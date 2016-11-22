/**
 * Copyright (C) 2016 Deepin Technology Co., Ltd.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 **/

#ifndef STYLE_H
#define STYLE_H

#include <QCommonStyle>

#include "common.h"
#include "paletteextended.h"
#include "sliderhelper.h"
#include "pushbuttonhelper.h"
#include "framehelper.h"
#include "lineedithelper.h"

namespace dstyle {

class Style : public QCommonStyle
{
    Q_OBJECT
public:
    explicit Style(StyleType type);
    ~Style();

    void polish(QPalette &p) Q_DECL_OVERRIDE;
    void polish(QWidget *w) Q_DECL_OVERRIDE;
    void unpolish(QWidget *w) Q_DECL_OVERRIDE;

    int pixelMetric(PixelMetric m, const QStyleOption *opt, const QWidget *widget) const Q_DECL_OVERRIDE;

    QRect subControlRect(ComplexControl cc, const QStyleOptionComplex *opt, SubControl sc, const QWidget *w) const Q_DECL_OVERRIDE;

    void drawControl(ControlElement element, const QStyleOption *opt, QPainter *p, const QWidget *w) const Q_DECL_OVERRIDE;
    void drawComplexControl(ComplexControl cc, const QStyleOptionComplex *opt, QPainter *p, const QWidget *w) const Q_DECL_OVERRIDE;
    void drawPrimitive(PrimitiveElement pe, const QStyleOption *opt, QPainter *p, const QWidget *w) const Q_DECL_OVERRIDE;

    // some function type alias.
//    using SubControlRectFunc = QRect(*)(const QStyleOptionComplex *opt, SubControl sc, const QWidget *w);
    using RenderFunc = bool(*)(const QStyleOptionComplex *, QPainter *, const QWidget *);
    using DrawPrimitiveFunc = bool(*)(const QStyleOption*, QPainter*, const QWidget* );
    using DrawControlFunc = bool (*)(const QStyleOption*, QPainter*, const QWidget* );

    // helper functions
    QRect sliderSubControlRect( const QStyleOptionComplex *opt, SubControl sc, const QWidget *w ) const;

private:
    StyleType m_type;
    PaletteExtended *m_palette;

    friend class SliderHelper;
    friend class PushButtonHelper;
    friend class LineEditHelper;
    friend class FrameHelper;
};


}

#endif // STYLE_H
