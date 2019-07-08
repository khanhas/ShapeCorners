/*
 *   Copyright © 2015 Robert Metsäranta <therealestrob@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *   General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; see the file COPYING.  if not, write to
 *   the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *   Boston, MA 02110-1301, USA.
 */

#pragma once
#include <kwineffects.h>

namespace KWin { class GLTexture; }

class Q_DECL_EXPORT ShapeCornersEffect : public KWin::Effect
{
//    Q_OBJECT
public:
    ShapeCornersEffect();
    ~ShapeCornersEffect();

    static bool supported();
    static bool enabledByDefault();

    void genMasks();

    void readConfig();
    void reconfigure(ReconfigureFlags flags);
    bool isValid(KWin::EffectWindow *w);
    void paintWindow (KWin::EffectWindow* w, int mask, QRegion region, KWin::WindowPaintData& data);
    int requestedEffectChainPosition() const { return 100; }

private:
    enum { TopLeft = 0, TopRight, BottomRight, BottomLeft, NTex };
    KWin::GLTexture *m_tex[NTex];

    QList<int> m_size, m_rSize;
    QList<QSize> m_corner;

    QRegion m_updateRegion;
    KWin::GLShader *m_shader;
    enum CornerType
    {
        Normal = 0,
        Rounded,
        Chiseled
    };
    CornerType m_type = CornerType::Normal;
    
    bool squareAtEdge = false;

    QStringList whitelist;
    QStringList blacklist;

    bool filterShadow = false;
};
