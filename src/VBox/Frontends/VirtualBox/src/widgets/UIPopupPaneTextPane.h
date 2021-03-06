/** @file
 * VBox Qt GUI - UIPopupPaneTextPane class declaration.
 */

/*
 * Copyright (C) 2013 Oracle Corporation
 *
 * This file is part of VirtualBox Open Source Edition (OSE), as
 * available from http://www.virtualbox.org. This file is free software;
 * you can redistribute it and/or modify it under the terms of the GNU
 * General Public License (GPL) as published by the Free Software
 * Foundation, in version 2 as it comes in the "COPYING" file of the
 * VirtualBox OSE distribution. VirtualBox OSE is distributed in the
 * hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
 */

#ifndef __UIPopupPaneTextPane_h__
#define __UIPopupPaneTextPane_h__

/* Qt includes: */
#include <QWidget>

/* Forward declarations: */
class QLabel;
class UIAnimation;

/* Popup-pane text-pane prototype class: */
class UIPopupPaneTextPane : public QWidget
{
    Q_OBJECT;
    Q_PROPERTY(QSize collapsedSizeHint READ collapsedSizeHint);
    Q_PROPERTY(QSize expandedSizeHint READ expandedSizeHint);
    Q_PROPERTY(QSize minimumSizeHint READ minimumSizeHint WRITE setMinimumSizeHint);

signals:

    /* Notifiers: Parent propagation stuff: */
    void sigFocusEnter();
    void sigFocusLeave();

    /* Notifier: Layout stuff: */
    void sigSizeHintChanged();

public:

    /* Constructor: */
    UIPopupPaneTextPane(QWidget *pParent, const QString &strText, bool fFocused);

    /* API: Text stuff: */
    void setText(const QString &strText);

    /* API: Layout stuff: */
    QSize minimumSizeHint() const;
    void setMinimumSizeHint(const QSize &minimumSizeHint);
    void layoutContent();

private slots:

    /* Handler: Layout stuff: */
    void sltHandleProposalForWidth(int iWidth);

    /* Handlers: Focus stuff: */
    void sltFocusEnter();
    void sltFocusLeave();

private:

    /* Helpers: Prepare stuff: */
    void prepare();
    void prepareContent();
    void prepareAnimation();

    /* Helper: Layout stuff: */
    void updateSizeHint();

    /* Property: Focus stuff: */
    QSize collapsedSizeHint() const { return m_collapsedSizeHint; }
    QSize expandedSizeHint() const { return m_expandedSizeHint; }

    /* Static helper: Font stuff: */
    static QFont tuneFont(QFont font);

    /* Variables: Layout stuff: */
    const int m_iLayoutMargin;
    const int m_iLayoutSpacing;
    QSize m_labelSizeHint;
    QSize m_collapsedSizeHint;
    QSize m_expandedSizeHint;
    QSize m_minimumSizeHint;

    /* Variables: Widget stuff: */
    QString m_strText;
    QLabel *m_pLabel;
    int m_iDesiredLabelWidth;

    /* Variables: Focus stuff: */
    bool m_fFocused;
    UIAnimation *m_pAnimation;
};

#endif /* __UIPopupPaneTextPane_h__ */
