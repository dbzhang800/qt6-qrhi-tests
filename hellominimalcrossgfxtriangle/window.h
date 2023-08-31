// Copyright (C) 2020 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#ifndef WINDOW_H
#define WINDOW_H

#include <QWindow>

#include <QtGui/private/qrhinull_p.h>
#if QT_CONFIG(opengl)
#include <QtGui/private/qrhigles2_p.h>
#include <QOffscreenSurface>
#endif
#if QT_CONFIG(vulkan)
#include <QtGui/private/qrhivulkan_p.h>
#endif
#ifdef Q_OS_WIN
#include <QtGui/private/qrhid3d11_p.h>
#endif
#if defined(Q_OS_MACOS) || defined(Q_OS_IOS)
#include <QtGui/private/qrhimetal_p.h>
#endif

class Window : public QWindow
{
public:
    Window(QRhi::Implementation graphicsApi);

    void releaseSwapChain();

protected:
    virtual void customInit();
    virtual void customRender();

    // destruction order matters to a certain degree: the fallbackSurface must
    // outlive the rhi, the rhi must outlive all other resources.  The resources
    // need no special order when destroying.
#if QT_CONFIG(opengl)
    std::unique_ptr<QOffscreenSurface> m_fallbackSurface;
#endif
    std::unique_ptr<QRhi> m_rhi;
    std::unique_ptr<QRhiSwapChain> m_sc;
    std::unique_ptr<QRhiRenderBuffer> m_ds;
    std::unique_ptr<QRhiRenderPassDescriptor> m_rp;

    bool m_hasSwapChain = false;
    QMatrix4x4 m_proj;

private:
    void init();
    void resizeSwapChain();
    void render();

    void exposeEvent(QExposeEvent *) override;
    bool event(QEvent *) override;

    QRhi::Implementation m_graphicsApi;

    bool m_running = false;
    bool m_notExposed = false;
    bool m_newlyExposed = false;
};

#endif
