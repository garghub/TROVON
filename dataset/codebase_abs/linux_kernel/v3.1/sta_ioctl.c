int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
struct V_6 * V_7 ;
F_2 (ha, dev)
memcpy ( & V_2 -> V_8 [ V_5 ++ ] , V_7 -> V_9 , V_10 ) ;
return V_5 ;
}
int F_3 ( struct V_11 * V_12 )
{
bool V_13 = false ;
int V_14 = V_12 -> V_15 . V_14 ;
F_4 ( V_12 -> V_4 , L_1 ) ;
F_5 ( & V_12 -> V_16 ) ;
F_6 ( V_12 -> V_17 , & V_12 -> V_18 ) ;
F_7 ( V_12 -> V_15 . V_19 ,
V_12 -> V_15 . V_20 ) ;
if ( ! V_12 -> V_15 . V_20 )
V_13 = true ;
if ( V_13 ) {
F_8 ( V_12 ) ;
F_4 ( V_12 -> V_4 , L_2 ) ;
}
V_12 -> V_15 . V_14 = 0 ;
return V_14 ;
}
int F_9 ( struct V_21 * V_22 ,
struct V_1 * V_23 )
{
int V_24 = 0 ;
T_1 V_25 ;
V_25 = V_22 -> V_26 ;
if ( V_23 -> V_27 == V_28 ) {
F_4 ( V_22 -> V_12 -> V_4 , L_3 ) ;
V_22 -> V_26 |= V_29 ;
V_22 -> V_26 &=
~ V_30 ;
} else {
V_22 -> V_26 &= ~ V_29 ;
if ( V_23 -> V_27 == V_31 ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_4 ) ;
V_22 -> V_26 |=
V_30 ;
} else {
V_22 -> V_26 &=
~ V_30 ;
if ( V_23 -> V_32 ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_5 ,
V_23 -> V_32 ) ;
if ( V_25 == V_22 -> V_26 ) {
V_24 = F_10 ( V_22 ,
V_33 ,
V_34 , 0 ,
V_23 ) ;
} else {
V_24 = F_10 ( V_22 ,
V_33 ,
V_34 , 0 ,
V_23 ) ;
}
}
}
}
F_4 ( V_22 -> V_12 -> V_4 ,
L_6 ,
V_25 , V_22 -> V_26 ) ;
if ( V_25 != V_22 -> V_26 ) {
V_24 = F_10 ( V_22 , V_35 ,
V_34 ,
0 , & V_22 -> V_26 ) ;
}
return V_24 ;
}
int F_11 ( struct V_21 * V_22 ,
struct V_36 * V_37 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_2 V_5 = - 1 ;
V_22 -> V_38 = false ;
if ( ! V_37 )
return - 1 ;
if ( V_22 -> V_39 == V_40 ) {
V_24 = F_12 ( V_22 , NULL ) ;
if ( V_24 )
return V_24 ;
if ( V_37 -> V_41 . V_42 )
V_5 = F_13 ( V_22 , & V_37 -> V_41 ,
NULL , V_40 ) ;
else
V_5 = F_14 ( V_22 ,
( V_43 * ) & V_37 -> V_44 ,
V_40 ) ;
if ( V_5 < 0 )
return - 1 ;
F_4 ( V_12 -> V_4 ,
L_7 ) ;
V_22 -> V_45 = 0 ;
V_24 = F_15 ( V_22 , & V_12 -> V_46 [ V_5 ] ) ;
if ( V_24 )
return V_24 ;
} else {
if ( V_37 -> V_41 . V_42 &&
( ! F_16
( & V_22 -> V_47 . V_48 . V_41 ,
& V_37 -> V_41 ) ) )
return 0 ;
F_4 ( V_12 -> V_4 , L_8 ) ;
V_24 = F_12 ( V_22 , NULL ) ;
if ( V_24 )
return V_24 ;
V_22 -> V_49 = false ;
if ( V_37 -> V_41 . V_42 )
V_5 = F_13 ( V_22 ,
& V_37 -> V_41 , NULL ,
V_50 ) ;
else
V_5 = F_14 ( V_22 ,
( V_43 * ) & V_37 -> V_44 ,
V_50 ) ;
if ( V_5 >= 0 ) {
F_4 ( V_12 -> V_4 , L_9
L_10 ) ;
V_24 = F_17 ( V_22 , & V_12 -> V_46 [ V_5 ] ) ;
if ( V_24 )
return V_24 ;
} else {
F_4 ( V_12 -> V_4 , L_11
L_12 ,
V_37 -> V_41 . V_41 ) ;
V_24 = F_18 ( V_22 , & V_37 -> V_41 ) ;
if ( V_24 )
return V_24 ;
}
}
return V_24 ;
}
int F_19 ( struct V_21 * V_22 , T_1 V_51 ,
int V_52 , struct V_53 * V_54 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
int V_14 = 0 ;
T_3 V_55 = 0 ;
if ( ! V_54 )
return - V_56 ;
switch ( V_51 ) {
case V_34 :
if ( V_12 -> V_57 ) {
F_4 ( V_12 -> V_4 , L_13
L_14 ) ;
V_14 = - 1 ;
break;
}
if ( V_54 -> V_58 ) {
if ( V_54 -> V_59 == V_60 ) {
if ( ! V_12 -> V_61 )
break;
V_55 = F_20 ( V_12 -> V_54
. V_59 ) ;
V_12 -> V_54 . V_59 =
F_21 ( V_54 -> V_59 ) ;
} else if ( V_54 -> V_59 ) {
V_12 -> V_54 . V_59 =
F_21 ( V_54 -> V_59 ) ;
V_12 -> V_54 . V_62 = ( V_43 ) V_54 -> V_62 ;
if ( V_54 -> V_63 )
V_12 -> V_54 . V_63 = ( V_43 ) V_54 -> V_63 ;
} else if ( V_12 -> V_54 . V_59 ==
F_21 (
V_60 ) ) {
V_14 = - 1 ;
break;
}
if ( V_52 == V_64 )
V_14 = F_22 ( V_22 ,
V_65 ,
V_34 , 0 ,
& V_12 -> V_54 ) ;
else
V_14 = F_10 ( V_22 ,
V_65 ,
V_34 , 0 ,
& V_12 -> V_54 ) ;
if ( V_54 -> V_59 == V_60 )
V_12 -> V_54 . V_59 =
F_21 ( V_55 ) ;
} else {
V_12 -> V_54 . V_59 =
F_21 ( V_54 -> V_59 ) ;
V_12 -> V_54 . V_62 = ( V_43 ) V_54 -> V_62 ;
V_12 -> V_54 . V_63 = ( V_43 ) V_54 -> V_63 ;
}
break;
case V_66 :
V_54 -> V_59 = F_20 ( V_12 -> V_54 . V_59 ) ;
V_54 -> V_62 = V_12 -> V_54 . V_62 ;
V_54 -> V_63 = V_12 -> V_54 . V_63 ;
break;
default:
V_14 = - 1 ;
break;
}
return V_14 ;
}
int F_23 ( struct V_21 * V_22 , int V_52 )
{
struct V_53 V_67 ;
V_67 . V_59 = V_60 ;
V_67 . V_58 = true ;
return F_19 ( V_22 , V_34 ,
V_52 , & V_67 ) ;
}
int F_24 ( struct V_11 * V_12 )
{
struct V_53 V_67 ;
if ( V_12 -> V_68 ) {
F_4 ( V_12 -> V_4 , L_15 ) ;
return true ;
}
V_12 -> V_69 = false ;
memset ( & V_67 , 0 , sizeof( struct V_70 ) ) ;
V_67 . V_58 = true ;
if ( F_19 ( F_25 ( V_12 ,
V_71 ) ,
V_34 , V_64 ,
& V_67 ) ) {
F_26 ( V_12 -> V_4 , L_16 ) ;
return false ;
}
F_7 ( V_12 -> V_72 ,
V_12 -> V_69 ) ;
return true ;
}
int F_27 ( struct V_21 * V_22 ,
struct V_73 * V_74 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_75 * V_76 ;
T_2 V_77 ;
if ( ! V_74 )
return - 1 ;
V_76 = & V_22 -> V_47 . V_48 ;
V_74 -> V_39 = V_22 -> V_39 ;
memcpy ( & V_74 -> V_41 , & V_76 -> V_41 ,
sizeof( struct V_78 ) ) ;
memcpy ( & V_74 -> V_44 , & V_76 -> V_79 , V_10 ) ;
V_74 -> V_80 = V_76 -> V_81 ;
V_74 -> V_82 = V_12 -> V_82 ;
V_74 -> V_83 = 0 ;
if ( V_22 -> V_84 ) {
V_77 =
F_13 ( V_22 , & V_76 -> V_41 ,
V_76 -> V_79 ,
V_22 -> V_39 ) ;
if ( V_77 >= 0 )
V_74 -> V_83 = V_77 ;
}
V_74 -> V_84 = V_22 -> V_84 ;
V_74 -> V_85 = V_22 -> V_86 ;
V_74 -> V_87 = V_22 -> V_88 ;
V_74 -> V_89 = V_22 -> V_89 ;
V_74 -> V_90 = V_22 -> V_90 ;
if ( V_22 -> V_91 . V_92 == V_93 )
V_74 -> V_92 = true ;
else
V_74 -> V_92 = false ;
V_74 -> V_61 = V_12 -> V_61 ;
V_74 -> V_94 = V_12 -> V_94 ;
return 0 ;
}
int F_28 ( struct V_21 * V_22 ,
struct V_95 * V_96 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
V_43 V_97 , V_98 ;
T_3 V_99 ;
V_97 = ( V_43 ) V_96 -> V_100 ;
V_98 = ( V_43 ) V_96 -> V_101 ;
V_99 = V_96 -> V_99 ;
if ( ( V_97 | V_12 -> V_102 ) & ~ V_12 -> V_102 )
return - 1 ;
V_12 -> V_100 = V_97 ;
if ( ( V_98 | V_12 -> V_102 ) & ~ V_12 -> V_102 )
return - 1 ;
if ( V_98 )
V_12 -> V_101 = V_98 ;
V_12 -> V_103 = ( V_43 ) V_96 -> V_104 ;
if ( ! V_99 ) {
if ( ! F_29
( V_22 , V_12 -> V_101 ,
V_22 -> V_99 ) ) {
V_96 -> V_99 = V_105 ;
if ( ( V_12 -> V_101 & V_106 )
|| ( V_12 -> V_101 & V_107 ) )
V_96 -> V_99 =
V_108 ;
}
} else {
if ( ! F_29
( V_22 , V_12 -> V_101 , ( T_1 ) V_99 ) )
return - 1 ;
V_22 -> V_99 = ( V_43 ) V_99 ;
}
if ( ( V_98 & V_109 ) || ( V_98 & V_107 ) )
V_12 -> V_110 = true ;
else
V_12 -> V_110 = false ;
return 0 ;
}
int F_30 ( struct V_21 * V_22 )
{
struct V_111 V_112 ;
V_112 . V_112 = V_113 ;
return F_22 ( V_22 , V_114 ,
V_115 , V_116 , & V_112 ) ;
}
int F_31 ( struct V_21 * V_22 ,
struct V_117 * V_118 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_117 * V_119 = NULL ;
if ( ! V_118 )
return - 1 ;
if ( ! V_118 -> V_81 && ! V_118 -> V_120 )
return - 1 ;
if ( V_12 -> V_101 & V_107 )
V_12 -> V_101 = V_121 | V_122 | V_109 ;
else if ( V_12 -> V_101 & V_106 )
V_12 -> V_101 = V_121 | V_122 ;
if ( V_118 -> V_81 ) {
if ( V_118 -> V_81 <= V_123 )
V_119 = F_29
( V_22 , 0 , ( T_1 ) V_118 -> V_81 ) ;
if ( ! V_119 ) {
V_119 = F_29
( V_22 , V_106 , ( T_1 ) V_118 -> V_81 ) ;
if ( V_119 ) {
if ( V_12 -> V_110 )
V_12 -> V_101 = V_106
| V_107 ;
else
V_12 -> V_101 = V_106 ;
}
}
} else {
if ( V_118 -> V_120 <= V_124 )
V_119 = F_32 (
V_22 , 0 , V_118 -> V_120 ) ;
if ( ! V_119 ) {
V_119 = F_32
( V_22 , V_106 , V_118 -> V_120 ) ;
if ( V_119 ) {
if ( V_12 -> V_110 )
V_12 -> V_101 = V_106
| V_107 ;
else
V_12 -> V_101 = V_106 ;
}
}
}
if ( ! V_119 || ! V_119 -> V_81 ) {
F_26 ( V_12 -> V_4 , L_17 ) ;
return - 1 ;
}
V_22 -> V_99 = ( V_43 ) V_119 -> V_81 ;
V_118 -> V_81 = V_119 -> V_81 ;
V_118 -> V_120 = V_119 -> V_120 ;
return 0 ;
}
static int F_33 ( struct V_21 * V_22 ,
T_1 V_51 , T_1 * V_81 )
{
if ( V_51 == V_66 ) {
if ( ! V_22 -> V_84 ) {
* V_81 = V_22 -> V_99 ;
return 0 ;
}
} else {
V_22 -> V_99 = ( V_43 ) * V_81 ;
}
return F_22 ( V_22 , V_125 ,
V_51 , 0 , V_81 ) ;
}
int F_34 ( struct V_21 * V_22 ,
struct V_36 * V_37 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_75 * V_76 ;
V_43 V_126 [ V_10 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
V_43 V_127 [ V_10 ] ;
int V_5 = 0 ;
if ( memcmp ( V_37 -> V_44 , V_126 , sizeof( V_126 ) ) ) {
V_5 = F_14 ( V_22 ,
( V_43 * ) V_37 -> V_44 ,
V_22 -> V_39 ) ;
if ( V_5 < 0 ) {
memcpy ( V_127 , V_37 -> V_44 , sizeof( V_127 ) ) ;
F_26 ( V_12 -> V_4 , L_18 , V_127 ) ;
return - 1 ;
}
V_76 = & V_12 -> V_46 [ V_5 ] ;
memcpy ( & V_37 -> V_41 , & V_76 -> V_41 ,
sizeof( struct V_78 ) ) ;
} else if ( V_37 -> V_41 . V_42 ) {
V_5 = F_13 ( V_22 , & V_37 -> V_41 , NULL ,
V_22 -> V_39 ) ;
if ( V_5 < 0 ) {
F_26 ( V_12 -> V_4 , L_19 ,
V_37 -> V_41 . V_41 ) ;
return - 1 ;
}
V_76 = & V_12 -> V_46 [ V_5 ] ;
memcpy ( V_37 -> V_44 , V_76 -> V_79 , V_10 ) ;
} else {
return F_35 ( V_22 , V_37 ) ;
}
return 0 ;
}
int
F_36 ( struct V_21 * V_22 , int V_81 )
{
int V_24 ;
struct V_73 V_128 ;
struct V_36 V_37 ;
T_1 V_129 = 0 ;
memset ( & V_128 , 0 , sizeof( V_128 ) ) ;
if ( F_27 ( V_22 , & V_128 ) )
return - 1 ;
V_24 = F_33 ( V_22 , V_66 ,
& V_129 ) ;
if ( V_129 == V_81 ) {
V_24 = 0 ;
goto V_130;
}
F_4 ( V_22 -> V_12 -> V_4 , L_20 ,
V_129 , V_81 ) ;
if ( ! V_128 . V_84 ) {
V_24 = 0 ;
goto V_130;
}
memset ( & V_37 , 0 , V_10 ) ;
V_24 = F_12 ( V_22 , V_37 . V_44 ) ;
V_24 = F_33 ( V_22 , V_34 ,
( T_1 * ) & V_81 ) ;
if ( F_37 ( V_22 , & V_128 . V_41 ) ) {
V_24 = - 1 ;
goto V_130;
}
memset ( & V_37 , 0 , sizeof( struct V_36 ) ) ;
memcpy ( & V_37 . V_41 , & V_128 . V_41 ,
sizeof( struct V_78 ) ) ;
V_24 = F_11 ( V_22 , & V_37 ) ;
V_130:
return V_24 ;
}
static int F_38 ( struct V_21 * V_22 ,
struct V_131 * V_132 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
V_132 -> V_133 = V_22 -> V_134 ;
if ( ! V_22 -> V_84 ) {
switch ( V_12 -> V_100 ) {
case V_122 :
V_132 -> V_135 = V_136 [ 0 ] & 0x7f ;
break;
case V_121 :
case V_121 | V_109 :
V_132 -> V_135 = V_137 [ 0 ] & 0x7f ;
break;
case V_122 | V_121 :
case V_106 | V_122 | V_121 :
case V_106 | V_122 :
case V_106 | V_122 | V_121 | V_107 | V_109 :
case V_122 | V_121 | V_109 :
V_132 -> V_135 = V_138 [ 0 ] & 0x7f ;
break;
case V_106 :
case V_106 | V_121 :
case V_106 | V_121 | V_107 | V_109 :
case V_106 | V_107 :
V_132 -> V_135 = V_139 [ 0 ] & 0x7f ;
break;
case V_109 :
V_132 -> V_135 = V_140 [ 0 ] & 0x7f ;
break;
default:
F_39 ( V_12 -> V_4 , L_21 ,
V_12 -> V_100 ) ;
break;
}
} else {
return F_22 ( V_22 ,
V_141 ,
V_66 , 0 , NULL ) ;
}
return 0 ;
}
static int F_40 ( struct V_21 * V_22 ,
struct V_131 * V_132 )
{
V_43 V_142 [ V_143 ] ;
V_43 * V_135 ;
int V_144 , V_24 ;
T_1 V_145 [ V_146 ] ;
T_3 V_5 ;
struct V_11 * V_12 = V_22 -> V_12 ;
if ( V_132 -> V_133 ) {
memset ( V_145 , 0 , sizeof( V_145 ) ) ;
V_145 [ 0 ] = 0x000F ;
V_145 [ 1 ] = 0x00FF ;
for ( V_5 = 0 ; V_5 < F_41 ( V_22 -> V_145 ) - 3 ; V_5 ++ )
V_145 [ V_5 + 2 ] = 0xFFFF ;
V_145 [ 9 ] = 0x3FFF ;
} else {
memset ( V_142 , 0 , sizeof( V_142 ) ) ;
F_42 ( V_22 , V_142 ) ;
V_135 = V_142 ;
for ( V_5 = 0 ; ( V_135 [ V_5 ] && V_5 < V_143 ) ; V_5 ++ ) {
F_4 ( V_12 -> V_4 , L_22 ,
V_135 [ V_5 ] , V_132 -> V_135 ) ;
if ( ( V_135 [ V_5 ] & 0x7f ) == ( V_132 -> V_135 & 0x7f ) )
break;
}
if ( ! V_135 [ V_5 ] || ( V_5 == V_143 ) ) {
F_26 ( V_12 -> V_4 , L_23
L_24 , V_132 -> V_135 ) ;
return - 1 ;
}
memset ( V_145 , 0 , sizeof( V_145 ) ) ;
V_144 = F_43 ( V_132 -> V_135 ) ;
if ( V_144 >= V_147 &&
V_144 <= V_148 ) {
V_145 [ 0 ] = 1 << V_144 ;
} else {
V_144 -= 1 ;
if ( V_144 >= V_149 &&
V_144 <= V_150 )
V_145 [ 1 ] = 1 << ( V_144 -
V_149 ) ;
}
}
V_24 = F_22 ( V_22 , V_151 ,
V_34 , 0 , V_145 ) ;
return V_24 ;
}
static int F_44 ( struct V_21 * V_22 ,
struct V_131 * V_132 )
{
int V_14 ;
if ( ! V_132 )
return - 1 ;
if ( V_132 -> V_51 == V_66 )
V_14 = F_38 ( V_22 , V_132 ) ;
else
V_14 = F_40 ( V_22 , V_132 ) ;
return V_14 ;
}
int F_45 ( struct V_21 * V_22 ,
struct V_131 * V_135 )
{
int V_24 ;
memset ( V_135 , 0 , sizeof( struct V_131 ) ) ;
V_135 -> V_51 = V_66 ;
V_24 = F_44 ( V_22 , V_135 ) ;
if ( ! V_24 ) {
if ( V_135 && V_135 -> V_133 )
V_135 -> V_135 = F_46 ( V_22 -> V_152 ,
V_22 -> V_153 ) ;
else if ( V_135 )
V_135 -> V_135 = V_22 -> V_154 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
int F_47 ( struct V_21 * V_22 ,
struct V_155 * V_156 )
{
int V_24 ;
struct V_157 * V_158 ;
struct V_159 * V_160 ;
struct V_161 * V_162 ;
V_43 * V_163 ;
T_1 V_164 = 0 ;
if ( ! V_156 -> V_165 ) {
V_164 = ( T_1 ) V_156 -> V_166 ;
if ( ( V_164 < V_22 -> V_88 ) ||
( V_164 > V_22 -> V_86 ) ) {
F_26 ( V_22 -> V_12 -> V_4 , L_25
L_26 ,
V_164 , V_22 -> V_88 ,
V_22 -> V_86 ) ;
return - 1 ;
}
}
V_163 = F_48 ( V_167 , V_168 ) ;
if ( ! V_163 ) {
F_26 ( V_22 -> V_12 -> V_4 , L_27 ,
V_169 ) ;
return - V_56 ;
}
V_158 = (struct V_157 * ) V_163 ;
V_158 -> V_51 = F_49 ( V_34 ) ;
if ( ! V_156 -> V_165 ) {
V_158 -> V_27 = F_21 ( 1 ) ;
V_160 = (struct V_159 * ) ( V_163 +
sizeof( struct V_157 ) ) ;
V_160 -> type = V_170 ;
V_160 -> V_171 = 4 * sizeof( struct V_161 ) ;
V_162 = (struct V_161 * ) ( V_163 +
sizeof( struct V_157 ) +
sizeof( struct V_159 ) ) ;
V_162 -> V_172 = 0x00 ;
V_162 -> V_173 = 0x03 ;
V_162 -> V_174 = V_175 ;
V_162 -> V_176 = 0 ;
V_162 -> V_177 = ( V_178 ) V_164 ;
V_162 -> V_179 = ( V_178 ) V_164 ;
V_162 ++ ;
V_162 -> V_172 = 0x00 ;
V_162 -> V_173 = 0x07 ;
V_162 -> V_174 = V_180 ;
V_162 -> V_176 = 0 ;
V_162 -> V_177 = ( V_178 ) V_164 ;
V_162 -> V_179 = ( V_178 ) V_164 ;
V_162 ++ ;
V_162 -> V_172 = 0x00 ;
V_162 -> V_173 = 0x20 ;
V_162 -> V_174 = V_181 ;
V_162 -> V_176 = 0 ;
V_162 -> V_177 = ( V_178 ) V_164 ;
V_162 -> V_179 = ( V_178 ) V_164 ;
V_162 -> V_182 = V_183 ;
V_162 ++ ;
V_162 -> V_172 = 0x00 ;
V_162 -> V_173 = 0x20 ;
V_162 -> V_174 = V_181 ;
V_162 -> V_176 = 0 ;
V_162 -> V_177 = ( V_178 ) V_164 ;
V_162 -> V_179 = ( V_178 ) V_164 ;
V_162 -> V_182 = V_184 ;
}
V_24 = F_22 ( V_22 , V_185 ,
V_34 , 0 , V_163 ) ;
F_50 ( V_163 ) ;
return V_24 ;
}
int F_51 ( struct V_21 * V_22 , T_3 * V_186 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_187 ;
if ( * V_186 )
V_12 -> V_186 = V_188 ;
else
V_12 -> V_186 = V_189 ;
V_187 = ( * V_186 ) ? V_190 : V_115 ;
V_24 = F_22 ( V_22 , V_114 ,
V_187 , V_191 , NULL ) ;
if ( ( ! V_24 ) && ( V_187 == V_115 ) )
V_24 = F_10 ( V_22 ,
V_114 , V_192 ,
0 , NULL ) ;
return V_24 ;
}
static int F_52 ( struct V_21 * V_22 ,
V_43 * V_193 , T_1 V_194 )
{
if ( V_194 ) {
if ( V_194 > sizeof( V_22 -> V_195 ) ) {
F_26 ( V_22 -> V_12 -> V_4 ,
L_28 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_195 , V_193 , V_194 ) ;
V_22 -> V_196 = ( V_43 ) V_194 ;
F_4 ( V_22 -> V_12 -> V_4 , L_29 ,
V_22 -> V_196 , V_22 -> V_195 [ 0 ] ) ;
if ( V_22 -> V_195 [ 0 ] == V_197 ) {
V_22 -> V_91 . V_198 = true ;
} else if ( V_22 -> V_195 [ 0 ] == V_199 ) {
V_22 -> V_91 . V_200 = true ;
} else {
V_22 -> V_91 . V_198 = false ;
V_22 -> V_91 . V_200 = false ;
}
} else {
memset ( V_22 -> V_195 , 0 , sizeof( V_22 -> V_195 ) ) ;
V_22 -> V_196 = 0 ;
F_4 ( V_22 -> V_12 -> V_4 , L_30 ,
V_22 -> V_196 , V_22 -> V_195 [ 0 ] ) ;
V_22 -> V_91 . V_198 = false ;
V_22 -> V_91 . V_200 = false ;
}
return 0 ;
}
static int F_53 ( struct V_21 * V_22 ,
V_43 * V_193 , T_1 V_194 )
{
if ( V_194 ) {
if ( V_194 > sizeof( V_22 -> V_201 ) ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_31 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_201 , V_193 , V_194 ) ;
V_22 -> V_202 = V_194 ;
F_4 ( V_22 -> V_12 -> V_4 , L_32 ,
V_22 -> V_202 , V_22 -> V_201 [ 0 ] ) ;
if ( V_22 -> V_201 [ 0 ] == V_203 )
V_22 -> V_91 . V_204 = true ;
} else {
memset ( V_22 -> V_201 , 0 , sizeof( V_22 -> V_201 ) ) ;
V_22 -> V_202 = V_194 ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_33 ,
V_22 -> V_202 , V_22 -> V_201 [ 0 ] ) ;
V_22 -> V_91 . V_204 = false ;
}
return 0 ;
}
static int F_54 ( struct V_21 * V_22 ,
struct V_205 * V_206 )
{
return F_22 ( V_22 , V_207 ,
V_34 , V_208 ,
V_206 ) ;
}
static int F_55 ( struct V_21 * V_22 ,
struct V_205 * V_206 )
{
int V_24 ;
struct V_209 * V_210 ;
int V_211 ;
if ( V_22 -> V_212 >= V_213 )
V_22 -> V_212 = 0 ;
V_210 = & V_22 -> V_210 [ V_22 -> V_212 ] ;
V_211 = V_206 -> V_214 ;
if ( V_206 -> V_215 ) {
V_22 -> V_91 . V_92 = V_216 ;
} else if ( ! V_206 -> V_217 ) {
V_210 = & V_22 -> V_210 [ V_211 ] ;
if ( ! V_210 -> V_218 ) {
F_26 ( V_22 -> V_12 -> V_4 ,
L_34 ) ;
return - 1 ;
}
V_22 -> V_212 = ( T_1 ) V_211 ;
V_22 -> V_91 . V_92 = V_93 ;
} else {
V_210 = & V_22 -> V_210 [ V_211 ] ;
memset ( V_210 , 0 , sizeof( struct V_209 ) ) ;
memcpy ( V_210 -> V_219 ,
V_206 -> V_219 ,
V_206 -> V_217 ) ;
V_210 -> V_214 = V_211 ;
V_210 -> V_218 = V_206 -> V_217 ;
V_22 -> V_91 . V_92 = V_93 ;
}
if ( V_210 -> V_218 ) {
V_24 = F_10 ( V_22 ,
V_207 ,
V_34 , 0 , NULL ) ;
if ( V_24 )
return V_24 ;
}
if ( V_22 -> V_91 . V_92 == V_93 )
V_22 -> V_26 |= V_220 ;
else
V_22 -> V_26 &= ~ V_220 ;
V_24 = F_22 ( V_22 , V_35 ,
V_34 , 0 ,
& V_22 -> V_26 ) ;
return V_24 ;
}
static int F_56 ( struct V_21 * V_22 ,
struct V_205 * V_206 )
{
int V_24 ;
V_43 V_221 = false ;
struct V_222 * V_223 ;
if ( V_206 -> V_217 > V_224 ) {
F_26 ( V_22 -> V_12 -> V_4 , L_35 ) ;
return - 1 ;
}
if ( V_22 -> V_39 == V_50 ) {
V_206 -> V_214 = V_225 ;
V_24 = F_10 ( V_22 ,
V_207 ,
V_34 , V_208 ,
V_206 ) ;
if ( V_24 )
return V_24 ;
V_223 = & V_22 -> V_226 ;
memset ( V_223 , 0 ,
sizeof( struct V_222 ) ) ;
memcpy ( V_223 -> V_227 . V_228 , V_206 -> V_219 ,
V_206 -> V_217 ) ;
memcpy ( & V_223 -> V_227 . V_217 , & V_206 -> V_217 ,
sizeof( V_223 -> V_227 . V_217 ) ) ;
V_223 -> V_227 . V_229
= F_49 ( V_230 ) ;
V_223 -> V_227 . V_231 = F_49 ( V_232 ) ;
V_206 -> V_214 = ~ V_225 ;
}
if ( ! V_206 -> V_214 )
V_206 -> V_214 = V_225 ;
if ( V_221 )
V_24 = F_22 ( V_22 ,
V_207 ,
V_34 , ! ( V_208 ) ,
V_206 ) ;
else
V_24 = F_22 ( V_22 ,
V_207 ,
V_34 , V_208 ,
V_206 ) ;
return V_24 ;
}
static int
F_57 ( struct V_21 * V_22 ,
struct V_205 * V_206 )
{
int V_14 ;
if ( V_206 -> V_233 )
V_14 = F_54 ( V_22 , V_206 ) ;
else if ( V_206 -> V_217 > V_234 )
V_14 = F_56 ( V_22 , V_206 ) ;
else
V_14 = F_55 ( V_22 , V_206 ) ;
return V_14 ;
}
int
F_58 ( struct V_11 * V_12 , char * V_235 ,
int V_236 )
{
union {
T_3 V_237 ;
V_43 V_238 [ 4 ] ;
} V_239 ;
char V_240 [ 32 ] ;
V_239 . V_237 = V_12 -> V_241 ;
sprintf ( V_240 , L_36 , V_239 . V_238 [ 2 ] , V_239 . V_238 [ 1 ] , V_239 . V_238 [ 0 ] , V_239 . V_238 [ 3 ] ) ;
snprintf ( V_235 , V_236 , V_242 , V_240 ) ;
F_4 ( V_12 -> V_4 , L_37 , V_235 ) ;
return 0 ;
}
int F_59 ( struct V_21 * V_22 ,
struct V_243 * signal )
{
int V_14 ;
signal -> V_244 = V_245 ;
if ( ! V_22 -> V_84 ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_38 ) ;
return - 1 ;
}
V_14 = F_22 ( V_22 , V_246 ,
V_66 , 0 , signal ) ;
if ( ! V_14 ) {
if ( signal -> V_244 & V_247 )
V_22 -> V_248 . V_249 . V_250 = signal -> V_251 ;
if ( signal -> V_244 & V_252 )
V_22 -> V_248 . V_249 . V_253 = signal -> V_254 ;
}
return V_14 ;
}
int F_60 ( struct V_21 * V_22 , const V_43 * V_228 ,
int V_217 , V_43 V_214 , int V_255 )
{
struct V_205 V_206 ;
memset ( & V_206 , 0 , sizeof( struct V_205 ) ) ;
V_206 . V_217 = V_217 ;
if ( ! V_255 ) {
V_206 . V_214 = V_214 ;
if ( V_217 )
memcpy ( V_206 . V_219 , V_228 , V_217 ) ;
} else {
V_206 . V_215 = true ;
}
return F_57 ( V_22 , & V_206 ) ;
}
int
F_61 ( struct V_21 * V_22 )
{
struct V_256 V_257 ;
memset ( & V_257 , 0 , sizeof( struct V_258 ) ) ;
if ( F_22 ( V_22 , V_259 ,
V_66 , 0 , & V_257 ) )
return - 1 ;
return 0 ;
}
int
F_62 ( struct V_21 * V_22 ,
struct V_260 * log )
{
int V_24 ;
V_24 = F_22 ( V_22 , V_261 ,
V_66 , 0 , log ) ;
if ( ! V_24 ) {
V_22 -> V_248 . V_262 . V_263 = log -> V_264 ;
V_22 -> V_248 . V_262 . V_265 = log -> V_266 ;
V_22 -> V_248 . V_262 . V_267 = log -> V_268 ;
}
return V_24 ;
}
static int F_63 ( struct V_21 * V_22 ,
struct V_269 * V_270 ,
T_1 V_51 )
{
T_1 V_271 ;
switch ( F_20 ( V_270 -> type ) ) {
case V_272 :
V_271 = V_273 ;
break;
case V_274 :
V_271 = V_275 ;
break;
case V_276 :
V_271 = V_277 ;
break;
case V_278 :
V_271 = V_279 ;
break;
case V_280 :
V_271 = V_281 ;
break;
default:
return - 1 ;
}
return F_22 ( V_22 , V_271 , V_51 , 0 , V_270 ) ;
}
int
F_64 ( struct V_21 * V_22 , T_3 V_282 ,
T_3 V_283 , T_3 V_284 )
{
struct V_269 V_270 ;
V_270 . type = F_21 ( V_282 ) ;
V_270 . V_285 = F_21 ( V_283 ) ;
V_270 . V_286 = F_21 ( V_284 ) ;
return F_63 ( V_22 , & V_270 , V_34 ) ;
}
int
F_65 ( struct V_21 * V_22 , T_3 V_282 ,
T_3 V_283 , T_3 * V_286 )
{
int V_24 ;
struct V_269 V_270 ;
V_270 . type = F_21 ( V_282 ) ;
V_270 . V_285 = F_21 ( V_283 ) ;
V_24 = F_63 ( V_22 , & V_270 , V_66 ) ;
if ( V_24 )
goto V_130;
* V_286 = F_20 ( V_270 . V_286 ) ;
V_130:
return V_24 ;
}
int
F_66 ( struct V_21 * V_22 , T_1 V_285 , T_1 V_287 ,
V_43 * V_286 )
{
int V_24 ;
struct V_288 V_289 ;
V_289 . V_285 = F_49 ( ( T_1 ) V_285 ) ;
V_289 . V_290 = F_49 ( ( T_1 ) V_287 ) ;
V_24 = F_22 ( V_22 , V_291 ,
V_66 , 0 , & V_289 ) ;
if ( ! V_24 )
memcpy ( V_286 , V_289 . V_286 , V_292 ) ;
return V_24 ;
}
static int
F_67 ( struct V_21 * V_22 , V_43 * V_193 ,
T_1 V_194 )
{
int V_24 = 0 ;
struct V_293 * V_294 ;
const V_43 V_295 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const V_43 V_296 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_194 ) {
V_22 -> V_297 = 0 ;
V_22 -> V_298 . V_299 = false ;
return 0 ;
} else if ( ! V_193 ) {
return - 1 ;
}
V_294 = (struct V_293 * ) V_193 ;
if ( ( ( V_294 -> V_300 == V_197 )
&& ( ! memcmp ( V_294 -> V_301 , V_295 , sizeof( V_295 ) ) ) )
|| ( V_294 -> V_300 == V_199 ) ) {
V_24 = F_52 ( V_22 , V_193 , V_194 ) ;
V_22 -> V_298 . V_299 = false ;
return V_24 ;
} else if ( V_294 -> V_300 == V_203 ) {
V_24 = F_53 ( V_22 , V_193 , V_194 ) ;
return V_24 ;
}
if ( V_194 < ( sizeof( V_22 -> V_302 ) - V_22 -> V_297 ) ) {
V_294 = (struct V_293 * ) V_193 ;
if ( ( V_294 -> V_300 == V_303 )
&& ( ! memcmp ( V_294 -> V_301 , V_296 ,
sizeof( V_296 ) ) ) ) {
V_22 -> V_298 . V_299 = true ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_39 ) ;
}
memcpy ( V_22 -> V_302 + V_22 -> V_297 , V_193 ,
V_194 ) ;
V_22 -> V_297 += V_194 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_68 ( struct V_21 * V_22 ,
struct V_304 * V_305 ,
T_1 V_51 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_305 -> type ) {
case V_306 :
if ( V_51 == V_66 ) {
V_305 -> V_307 = V_22 -> V_196 ;
memcpy ( V_305 -> V_308 , V_22 -> V_195 , V_305 -> V_307 ) ;
} else {
F_67 ( V_22 , V_305 -> V_308 ,
( T_1 ) V_305 -> V_307 ) ;
}
break;
case V_309 :
memset ( V_12 -> V_310 , 0 , sizeof( V_12 -> V_310 ) ) ;
if ( V_305 -> V_307 > V_311 ) {
V_12 -> V_312 = 0 ;
F_26 ( V_12 -> V_4 , L_40 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_310 , V_305 -> V_308 ,
V_305 -> V_307 ) ;
V_12 -> V_312 = V_305 -> V_307 ;
}
break;
default:
F_26 ( V_12 -> V_4 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
int
F_69 ( struct V_21 * V_22 , V_43 * V_313 , int V_194 )
{
struct V_304 V_305 ;
if ( V_194 > V_314 )
return - V_315 ;
V_305 . type = V_306 ;
V_305 . V_307 = V_194 ;
memcpy ( V_305 . V_308 , V_313 , V_194 ) ;
if ( F_68 ( V_22 , & V_305 , V_34 ) )
return - V_315 ;
return 0 ;
}
