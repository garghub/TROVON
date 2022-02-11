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
int F_30 ( struct V_21 * V_22 ,
struct V_111 * V_112 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_111 * V_113 = NULL ;
if ( ! V_112 )
return - 1 ;
if ( ! V_112 -> V_81 && ! V_112 -> V_114 )
return - 1 ;
if ( V_12 -> V_101 & V_107 )
V_12 -> V_101 = V_115 | V_116 | V_109 ;
else if ( V_12 -> V_101 & V_106 )
V_12 -> V_101 = V_115 | V_116 ;
if ( V_112 -> V_81 ) {
if ( V_112 -> V_81 <= V_117 )
V_113 = F_29
( V_22 , 0 , ( T_1 ) V_112 -> V_81 ) ;
if ( ! V_113 ) {
V_113 = F_29
( V_22 , V_106 , ( T_1 ) V_112 -> V_81 ) ;
if ( V_113 ) {
if ( V_12 -> V_110 )
V_12 -> V_101 = V_106
| V_107 ;
else
V_12 -> V_101 = V_106 ;
}
}
} else {
if ( V_112 -> V_114 <= V_118 )
V_113 = F_31 (
V_22 , 0 , V_112 -> V_114 ) ;
if ( ! V_113 ) {
V_113 = F_31
( V_22 , V_106 , V_112 -> V_114 ) ;
if ( V_113 ) {
if ( V_12 -> V_110 )
V_12 -> V_101 = V_106
| V_107 ;
else
V_12 -> V_101 = V_106 ;
}
}
}
if ( ! V_113 || ! V_113 -> V_81 ) {
F_26 ( V_12 -> V_4 , L_17 ) ;
return - 1 ;
}
V_22 -> V_99 = ( V_43 ) V_113 -> V_81 ;
V_112 -> V_81 = V_113 -> V_81 ;
V_112 -> V_114 = V_113 -> V_114 ;
return 0 ;
}
static int F_32 ( struct V_21 * V_22 ,
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
return F_22 ( V_22 , V_119 ,
V_51 , 0 , V_81 ) ;
}
int F_33 ( struct V_21 * V_22 ,
struct V_36 * V_37 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
struct V_75 * V_76 ;
V_43 V_120 [ V_10 ] = { 0 , 0 , 0 , 0 , 0 , 0 } ;
V_43 V_121 [ V_10 ] ;
int V_5 = 0 ;
if ( memcmp ( V_37 -> V_44 , V_120 , sizeof( V_120 ) ) ) {
V_5 = F_14 ( V_22 ,
( V_43 * ) V_37 -> V_44 ,
V_22 -> V_39 ) ;
if ( V_5 < 0 ) {
memcpy ( V_121 , V_37 -> V_44 , sizeof( V_121 ) ) ;
F_26 ( V_12 -> V_4 , L_18 , V_121 ) ;
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
return F_34 ( V_22 , V_37 ) ;
}
return 0 ;
}
int
F_35 ( struct V_21 * V_22 , int V_81 )
{
int V_24 ;
struct V_73 V_122 ;
struct V_36 V_37 ;
T_1 V_123 = 0 ;
memset ( & V_122 , 0 , sizeof( V_122 ) ) ;
if ( F_27 ( V_22 , & V_122 ) )
return - 1 ;
V_24 = F_32 ( V_22 , V_66 ,
& V_123 ) ;
if ( V_123 == V_81 ) {
V_24 = 0 ;
goto V_124;
}
F_4 ( V_22 -> V_12 -> V_4 , L_20 ,
V_123 , V_81 ) ;
if ( ! V_122 . V_84 ) {
V_24 = 0 ;
goto V_124;
}
memset ( & V_37 , 0 , V_10 ) ;
V_24 = F_12 ( V_22 , V_37 . V_44 ) ;
V_24 = F_32 ( V_22 , V_34 ,
( T_1 * ) & V_81 ) ;
if ( F_36 ( V_22 , & V_122 . V_41 ) ) {
V_24 = - 1 ;
goto V_124;
}
memset ( & V_37 , 0 , sizeof( struct V_36 ) ) ;
memcpy ( & V_37 . V_41 , & V_122 . V_41 ,
sizeof( struct V_78 ) ) ;
V_24 = F_11 ( V_22 , & V_37 ) ;
V_124:
return V_24 ;
}
static int F_37 ( struct V_21 * V_22 ,
struct V_125 * V_126 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
V_126 -> V_127 = V_22 -> V_128 ;
if ( ! V_22 -> V_84 ) {
switch ( V_12 -> V_100 ) {
case V_116 :
V_126 -> V_129 = V_130 [ 0 ] & 0x7f ;
break;
case V_115 :
case V_115 | V_109 :
V_126 -> V_129 = V_131 [ 0 ] & 0x7f ;
break;
case V_116 | V_115 :
case V_106 | V_116 | V_115 :
case V_106 | V_116 :
case V_106 | V_116 | V_115 | V_107 | V_109 :
case V_116 | V_115 | V_109 :
V_126 -> V_129 = V_132 [ 0 ] & 0x7f ;
break;
case V_106 :
case V_106 | V_115 :
case V_106 | V_115 | V_107 | V_109 :
case V_106 | V_107 :
V_126 -> V_129 = V_133 [ 0 ] & 0x7f ;
break;
case V_109 :
V_126 -> V_129 = V_134 [ 0 ] & 0x7f ;
break;
default:
F_38 ( V_12 -> V_4 , L_21 ,
V_12 -> V_100 ) ;
break;
}
} else {
return F_22 ( V_22 ,
V_135 ,
V_66 , 0 , NULL ) ;
}
return 0 ;
}
static int F_39 ( struct V_21 * V_22 ,
struct V_125 * V_126 )
{
V_43 V_136 [ V_137 ] ;
V_43 * V_129 ;
int V_138 , V_24 ;
T_1 V_139 [ V_140 ] ;
T_3 V_5 ;
struct V_11 * V_12 = V_22 -> V_12 ;
if ( V_126 -> V_127 ) {
memset ( V_139 , 0 , sizeof( V_139 ) ) ;
V_139 [ 0 ] = 0x000F ;
V_139 [ 1 ] = 0x00FF ;
for ( V_5 = 0 ; V_5 < F_40 ( V_22 -> V_139 ) - 3 ; V_5 ++ )
V_139 [ V_5 + 2 ] = 0xFFFF ;
V_139 [ 9 ] = 0x3FFF ;
} else {
memset ( V_136 , 0 , sizeof( V_136 ) ) ;
F_41 ( V_22 , V_136 ) ;
V_129 = V_136 ;
for ( V_5 = 0 ; ( V_129 [ V_5 ] && V_5 < V_137 ) ; V_5 ++ ) {
F_4 ( V_12 -> V_4 , L_22 ,
V_129 [ V_5 ] , V_126 -> V_129 ) ;
if ( ( V_129 [ V_5 ] & 0x7f ) == ( V_126 -> V_129 & 0x7f ) )
break;
}
if ( ! V_129 [ V_5 ] || ( V_5 == V_137 ) ) {
F_26 ( V_12 -> V_4 , L_23
L_24 , V_126 -> V_129 ) ;
return - 1 ;
}
memset ( V_139 , 0 , sizeof( V_139 ) ) ;
V_138 = F_42 ( V_126 -> V_129 ) ;
if ( V_138 >= V_141 &&
V_138 <= V_142 ) {
V_139 [ 0 ] = 1 << V_138 ;
} else {
V_138 -= 1 ;
if ( V_138 >= V_143 &&
V_138 <= V_144 )
V_139 [ 1 ] = 1 << ( V_138 -
V_143 ) ;
}
}
V_24 = F_22 ( V_22 , V_145 ,
V_34 , 0 , V_139 ) ;
return V_24 ;
}
static int F_43 ( struct V_21 * V_22 ,
struct V_125 * V_126 )
{
int V_14 ;
if ( ! V_126 )
return - 1 ;
if ( V_126 -> V_51 == V_66 )
V_14 = F_37 ( V_22 , V_126 ) ;
else
V_14 = F_39 ( V_22 , V_126 ) ;
return V_14 ;
}
int F_44 ( struct V_21 * V_22 ,
struct V_125 * V_129 )
{
int V_24 ;
memset ( V_129 , 0 , sizeof( struct V_125 ) ) ;
V_129 -> V_51 = V_66 ;
V_24 = F_43 ( V_22 , V_129 ) ;
if ( ! V_24 ) {
if ( V_129 && V_129 -> V_127 )
V_129 -> V_129 = F_45 ( V_22 -> V_146 ,
V_22 -> V_147 ) ;
else if ( V_129 )
V_129 -> V_129 = V_22 -> V_148 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
int F_46 ( struct V_21 * V_22 ,
struct V_149 * V_150 )
{
int V_24 ;
struct V_151 * V_152 ;
struct V_153 * V_154 ;
struct V_155 * V_156 ;
V_43 * V_157 ;
T_1 V_158 = 0 ;
if ( ! V_150 -> V_159 ) {
V_158 = ( T_1 ) V_150 -> V_160 ;
if ( ( V_158 < V_22 -> V_88 ) ||
( V_158 > V_22 -> V_86 ) ) {
F_26 ( V_22 -> V_12 -> V_4 , L_25
L_26 ,
V_158 , V_22 -> V_88 ,
V_22 -> V_86 ) ;
return - 1 ;
}
}
V_157 = F_47 ( V_161 , V_162 ) ;
if ( ! V_157 ) {
F_26 ( V_22 -> V_12 -> V_4 , L_27 ,
V_163 ) ;
return - V_56 ;
}
V_152 = (struct V_151 * ) V_157 ;
V_152 -> V_51 = F_48 ( V_34 ) ;
if ( ! V_150 -> V_159 ) {
V_152 -> V_27 = F_21 ( 1 ) ;
V_154 = (struct V_153 * ) ( V_157 +
sizeof( struct V_151 ) ) ;
V_154 -> type = V_164 ;
V_154 -> V_165 = 4 * sizeof( struct V_155 ) ;
V_156 = (struct V_155 * ) ( V_157 +
sizeof( struct V_151 ) +
sizeof( struct V_153 ) ) ;
V_156 -> V_166 = 0x00 ;
V_156 -> V_167 = 0x03 ;
V_156 -> V_168 = V_169 ;
V_156 -> V_170 = 0 ;
V_156 -> V_171 = ( V_172 ) V_158 ;
V_156 -> V_173 = ( V_172 ) V_158 ;
V_156 ++ ;
V_156 -> V_166 = 0x00 ;
V_156 -> V_167 = 0x07 ;
V_156 -> V_168 = V_174 ;
V_156 -> V_170 = 0 ;
V_156 -> V_171 = ( V_172 ) V_158 ;
V_156 -> V_173 = ( V_172 ) V_158 ;
V_156 ++ ;
V_156 -> V_166 = 0x00 ;
V_156 -> V_167 = 0x20 ;
V_156 -> V_168 = V_175 ;
V_156 -> V_170 = 0 ;
V_156 -> V_171 = ( V_172 ) V_158 ;
V_156 -> V_173 = ( V_172 ) V_158 ;
V_156 -> V_176 = V_177 ;
V_156 ++ ;
V_156 -> V_166 = 0x00 ;
V_156 -> V_167 = 0x20 ;
V_156 -> V_168 = V_175 ;
V_156 -> V_170 = 0 ;
V_156 -> V_171 = ( V_172 ) V_158 ;
V_156 -> V_173 = ( V_172 ) V_158 ;
V_156 -> V_176 = V_178 ;
}
V_24 = F_22 ( V_22 , V_179 ,
V_34 , 0 , V_157 ) ;
F_49 ( V_157 ) ;
return V_24 ;
}
int F_50 ( struct V_21 * V_22 , T_3 * V_180 )
{
int V_24 ;
struct V_11 * V_12 = V_22 -> V_12 ;
T_1 V_181 ;
if ( * V_180 )
V_12 -> V_180 = V_182 ;
else
V_12 -> V_180 = V_183 ;
V_181 = ( * V_180 ) ? V_184 : V_185 ;
V_24 = F_22 ( V_22 , V_186 ,
V_181 , V_187 , NULL ) ;
if ( ( ! V_24 ) && ( V_181 == V_185 ) )
V_24 = F_10 ( V_22 ,
V_186 , V_188 ,
0 , NULL ) ;
return V_24 ;
}
static int F_51 ( struct V_21 * V_22 ,
V_43 * V_189 , T_1 V_190 )
{
if ( V_190 ) {
if ( V_190 > sizeof( V_22 -> V_191 ) ) {
F_26 ( V_22 -> V_12 -> V_4 ,
L_28 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_191 , V_189 , V_190 ) ;
V_22 -> V_192 = ( V_43 ) V_190 ;
F_4 ( V_22 -> V_12 -> V_4 , L_29 ,
V_22 -> V_192 , V_22 -> V_191 [ 0 ] ) ;
if ( V_22 -> V_191 [ 0 ] == V_193 ) {
V_22 -> V_91 . V_194 = true ;
} else if ( V_22 -> V_191 [ 0 ] == V_195 ) {
V_22 -> V_91 . V_196 = true ;
} else {
V_22 -> V_91 . V_194 = false ;
V_22 -> V_91 . V_196 = false ;
}
} else {
memset ( V_22 -> V_191 , 0 , sizeof( V_22 -> V_191 ) ) ;
V_22 -> V_192 = 0 ;
F_4 ( V_22 -> V_12 -> V_4 , L_30 ,
V_22 -> V_192 , V_22 -> V_191 [ 0 ] ) ;
V_22 -> V_91 . V_194 = false ;
V_22 -> V_91 . V_196 = false ;
}
return 0 ;
}
static int F_52 ( struct V_21 * V_22 ,
V_43 * V_189 , T_1 V_190 )
{
if ( V_190 ) {
if ( V_190 > sizeof( V_22 -> V_197 ) ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_31 ) ;
return - 1 ;
}
memcpy ( V_22 -> V_197 , V_189 , V_190 ) ;
V_22 -> V_198 = V_190 ;
F_4 ( V_22 -> V_12 -> V_4 , L_32 ,
V_22 -> V_198 , V_22 -> V_197 [ 0 ] ) ;
if ( V_22 -> V_197 [ 0 ] == V_199 )
V_22 -> V_91 . V_200 = true ;
} else {
memset ( V_22 -> V_197 , 0 , sizeof( V_22 -> V_197 ) ) ;
V_22 -> V_198 = V_190 ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_33 ,
V_22 -> V_198 , V_22 -> V_197 [ 0 ] ) ;
V_22 -> V_91 . V_200 = false ;
}
return 0 ;
}
static int F_53 ( struct V_21 * V_22 ,
struct V_201 * V_202 )
{
return F_22 ( V_22 , V_203 ,
V_34 , V_204 ,
V_202 ) ;
}
static int F_54 ( struct V_21 * V_22 ,
struct V_201 * V_202 )
{
int V_24 ;
struct V_205 * V_206 ;
int V_207 ;
if ( V_22 -> V_208 >= V_209 )
V_22 -> V_208 = 0 ;
V_206 = & V_22 -> V_206 [ V_22 -> V_208 ] ;
V_207 = V_202 -> V_210 ;
if ( V_202 -> V_211 ) {
V_22 -> V_91 . V_92 = V_212 ;
} else if ( ! V_202 -> V_213 ) {
V_206 = & V_22 -> V_206 [ V_207 ] ;
if ( ! V_206 -> V_214 ) {
F_26 ( V_22 -> V_12 -> V_4 ,
L_34 ) ;
return - 1 ;
}
V_22 -> V_208 = ( T_1 ) V_207 ;
V_22 -> V_91 . V_92 = V_93 ;
} else {
V_206 = & V_22 -> V_206 [ V_207 ] ;
memset ( V_206 , 0 , sizeof( struct V_205 ) ) ;
memcpy ( V_206 -> V_215 ,
V_202 -> V_215 ,
V_202 -> V_213 ) ;
V_206 -> V_210 = V_207 ;
V_206 -> V_214 = V_202 -> V_213 ;
V_22 -> V_91 . V_92 = V_93 ;
}
if ( V_206 -> V_214 ) {
V_24 = F_10 ( V_22 ,
V_203 ,
V_34 , 0 , NULL ) ;
if ( V_24 )
return V_24 ;
}
if ( V_22 -> V_91 . V_92 == V_93 )
V_22 -> V_26 |= V_216 ;
else
V_22 -> V_26 &= ~ V_216 ;
V_24 = F_22 ( V_22 , V_35 ,
V_34 , 0 ,
& V_22 -> V_26 ) ;
return V_24 ;
}
static int F_55 ( struct V_21 * V_22 ,
struct V_201 * V_202 )
{
int V_24 ;
V_43 V_217 = false ;
struct V_218 * V_219 ;
if ( V_202 -> V_213 > V_220 ) {
F_26 ( V_22 -> V_12 -> V_4 , L_35 ) ;
return - 1 ;
}
if ( V_22 -> V_39 == V_50 ) {
V_202 -> V_210 = V_221 ;
V_24 = F_10 ( V_22 ,
V_203 ,
V_34 , V_204 ,
V_202 ) ;
if ( V_24 )
return V_24 ;
V_219 = & V_22 -> V_222 ;
memset ( V_219 , 0 ,
sizeof( struct V_218 ) ) ;
memcpy ( V_219 -> V_223 . V_224 , V_202 -> V_215 ,
V_202 -> V_213 ) ;
memcpy ( & V_219 -> V_223 . V_213 , & V_202 -> V_213 ,
sizeof( V_219 -> V_223 . V_213 ) ) ;
V_219 -> V_223 . V_225
= F_48 ( V_226 ) ;
V_219 -> V_223 . V_227 = F_48 ( V_228 ) ;
V_202 -> V_210 = ~ V_221 ;
}
if ( ! V_202 -> V_210 )
V_202 -> V_210 = V_221 ;
if ( V_217 )
V_24 = F_22 ( V_22 ,
V_203 ,
V_34 , ! ( V_204 ) ,
V_202 ) ;
else
V_24 = F_22 ( V_22 ,
V_203 ,
V_34 , V_204 ,
V_202 ) ;
return V_24 ;
}
static int
F_56 ( struct V_21 * V_22 ,
struct V_201 * V_202 )
{
int V_14 ;
if ( V_202 -> V_229 )
V_14 = F_53 ( V_22 , V_202 ) ;
else if ( V_202 -> V_213 > V_230 )
V_14 = F_55 ( V_22 , V_202 ) ;
else
V_14 = F_54 ( V_22 , V_202 ) ;
return V_14 ;
}
int
F_57 ( struct V_11 * V_12 , char * V_231 ,
int V_232 )
{
union {
T_3 V_233 ;
V_43 V_234 [ 4 ] ;
} V_235 ;
char V_236 [ 32 ] ;
V_235 . V_233 = V_12 -> V_237 ;
sprintf ( V_236 , L_36 , V_235 . V_234 [ 2 ] , V_235 . V_234 [ 1 ] , V_235 . V_234 [ 0 ] , V_235 . V_234 [ 3 ] ) ;
snprintf ( V_231 , V_232 , V_238 , V_236 ) ;
F_4 ( V_12 -> V_4 , L_37 , V_231 ) ;
return 0 ;
}
int F_58 ( struct V_21 * V_22 ,
struct V_239 * signal )
{
int V_14 ;
signal -> V_240 = V_241 ;
if ( ! V_22 -> V_84 ) {
F_4 ( V_22 -> V_12 -> V_4 ,
L_38 ) ;
return - 1 ;
}
V_14 = F_22 ( V_22 , V_242 ,
V_66 , 0 , signal ) ;
if ( ! V_14 ) {
if ( signal -> V_240 & V_243 )
V_22 -> V_244 . V_245 . V_246 = signal -> V_247 ;
if ( signal -> V_240 & V_248 )
V_22 -> V_244 . V_245 . V_249 = signal -> V_250 ;
}
return V_14 ;
}
int F_59 ( struct V_21 * V_22 , const V_43 * V_224 ,
int V_213 , V_43 V_210 , int V_251 )
{
struct V_201 V_202 ;
memset ( & V_202 , 0 , sizeof( struct V_201 ) ) ;
V_202 . V_213 = V_213 ;
if ( ! V_251 ) {
V_202 . V_210 = V_210 ;
if ( V_213 )
memcpy ( V_202 . V_215 , V_224 , V_213 ) ;
} else {
V_202 . V_211 = true ;
}
return F_56 ( V_22 , & V_202 ) ;
}
int
F_60 ( struct V_21 * V_22 )
{
struct V_252 V_253 ;
memset ( & V_253 , 0 , sizeof( struct V_254 ) ) ;
if ( F_22 ( V_22 , V_255 ,
V_66 , 0 , & V_253 ) )
return - 1 ;
return 0 ;
}
int
F_61 ( struct V_21 * V_22 ,
struct V_256 * log )
{
int V_24 ;
V_24 = F_22 ( V_22 , V_257 ,
V_66 , 0 , log ) ;
if ( ! V_24 ) {
V_22 -> V_244 . V_258 . V_259 = log -> V_260 ;
V_22 -> V_244 . V_258 . V_261 = log -> V_262 ;
V_22 -> V_244 . V_258 . V_263 = log -> V_264 ;
}
return V_24 ;
}
static int F_62 ( struct V_21 * V_22 ,
struct V_265 * V_266 ,
T_1 V_51 )
{
T_1 V_267 ;
switch ( F_20 ( V_266 -> type ) ) {
case V_268 :
V_267 = V_269 ;
break;
case V_270 :
V_267 = V_271 ;
break;
case V_272 :
V_267 = V_273 ;
break;
case V_274 :
V_267 = V_275 ;
break;
case V_276 :
V_267 = V_277 ;
break;
default:
return - 1 ;
}
return F_22 ( V_22 , V_267 , V_51 , 0 , V_266 ) ;
}
int
F_63 ( struct V_21 * V_22 , T_3 V_278 ,
T_3 V_279 , T_3 V_280 )
{
struct V_265 V_266 ;
V_266 . type = F_21 ( V_278 ) ;
V_266 . V_281 = F_21 ( V_279 ) ;
V_266 . V_282 = F_21 ( V_280 ) ;
return F_62 ( V_22 , & V_266 , V_34 ) ;
}
int
F_64 ( struct V_21 * V_22 , T_3 V_278 ,
T_3 V_279 , T_3 * V_282 )
{
int V_24 ;
struct V_265 V_266 ;
V_266 . type = F_21 ( V_278 ) ;
V_266 . V_281 = F_21 ( V_279 ) ;
V_24 = F_62 ( V_22 , & V_266 , V_66 ) ;
if ( V_24 )
goto V_124;
* V_282 = F_20 ( V_266 . V_282 ) ;
V_124:
return V_24 ;
}
int
F_65 ( struct V_21 * V_22 , T_1 V_281 , T_1 V_283 ,
V_43 * V_282 )
{
int V_24 ;
struct V_284 V_285 ;
V_285 . V_281 = F_48 ( ( T_1 ) V_281 ) ;
V_285 . V_286 = F_48 ( ( T_1 ) V_283 ) ;
V_24 = F_22 ( V_22 , V_287 ,
V_66 , 0 , & V_285 ) ;
if ( ! V_24 )
memcpy ( V_282 , V_285 . V_282 , V_288 ) ;
return V_24 ;
}
static int
F_66 ( struct V_21 * V_22 , V_43 * V_189 ,
T_1 V_190 )
{
int V_24 = 0 ;
struct V_289 * V_290 ;
const V_43 V_291 [] = { 0x00 , 0x50 , 0xf2 , 0x01 } ;
const V_43 V_292 [] = { 0x00 , 0x50 , 0xf2 , 0x04 } ;
if ( ! V_190 ) {
V_22 -> V_293 = 0 ;
V_22 -> V_294 . V_295 = false ;
return 0 ;
} else if ( ! V_189 ) {
return - 1 ;
}
V_290 = (struct V_289 * ) V_189 ;
if ( ( ( V_290 -> V_296 == V_193 )
&& ( ! memcmp ( V_290 -> V_297 , V_291 , sizeof( V_291 ) ) ) )
|| ( V_290 -> V_296 == V_195 ) ) {
V_24 = F_51 ( V_22 , V_189 , V_190 ) ;
V_22 -> V_294 . V_295 = false ;
return V_24 ;
} else if ( V_290 -> V_296 == V_199 ) {
V_24 = F_52 ( V_22 , V_189 , V_190 ) ;
return V_24 ;
}
if ( V_190 < ( sizeof( V_22 -> V_298 ) - V_22 -> V_293 ) ) {
V_290 = (struct V_289 * ) V_189 ;
if ( ( V_290 -> V_296 == V_299 )
&& ( ! memcmp ( V_290 -> V_297 , V_292 ,
sizeof( V_292 ) ) ) ) {
V_22 -> V_294 . V_295 = true ;
F_4 ( V_22 -> V_12 -> V_4 ,
L_39 ) ;
}
memcpy ( V_22 -> V_298 + V_22 -> V_293 , V_189 ,
V_190 ) ;
V_22 -> V_293 += V_190 ;
} else {
V_24 = - 1 ;
}
return V_24 ;
}
static int F_67 ( struct V_21 * V_22 ,
struct V_300 * V_301 ,
T_1 V_51 )
{
struct V_11 * V_12 = V_22 -> V_12 ;
switch ( V_301 -> type ) {
case V_302 :
if ( V_51 == V_66 ) {
V_301 -> V_303 = V_22 -> V_192 ;
memcpy ( V_301 -> V_304 , V_22 -> V_191 , V_301 -> V_303 ) ;
} else {
F_66 ( V_22 , V_301 -> V_304 ,
( T_1 ) V_301 -> V_303 ) ;
}
break;
case V_305 :
memset ( V_12 -> V_306 , 0 , sizeof( V_12 -> V_306 ) ) ;
if ( V_301 -> V_303 > V_307 ) {
V_12 -> V_308 = 0 ;
F_26 ( V_12 -> V_4 , L_40 ) ;
return - 1 ;
} else {
memcpy ( V_12 -> V_306 , V_301 -> V_304 ,
V_301 -> V_303 ) ;
V_12 -> V_308 = V_301 -> V_303 ;
}
break;
default:
F_26 ( V_12 -> V_4 , L_41 ) ;
return - 1 ;
}
return 0 ;
}
int
F_68 ( struct V_21 * V_22 , V_43 * V_309 , int V_190 )
{
struct V_300 V_301 ;
if ( V_190 > V_310 )
return - V_311 ;
V_301 . type = V_302 ;
V_301 . V_303 = V_190 ;
memcpy ( V_301 . V_304 , V_309 , V_190 ) ;
if ( F_67 ( V_22 , & V_301 , V_34 ) )
return - V_311 ;
return 0 ;
}
