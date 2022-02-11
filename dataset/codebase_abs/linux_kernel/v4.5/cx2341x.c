static const char * F_1 ( T_1 V_1 )
{
switch ( V_1 ) {
case V_2 :
return L_1 ;
case V_3 :
return L_2 ;
case V_4 :
return L_3 ;
case V_5 :
return L_4 ;
case V_6 :
return L_5 ;
case V_7 :
return L_6 ;
case V_8 :
return L_7 ;
case V_9 :
return L_8 ;
case V_10 :
return L_9 ;
case V_11 :
return L_10 ;
case V_12 :
return L_11 ;
case V_13 :
return L_12 ;
}
return NULL ;
}
static const char * * F_2 ( T_1 V_1 )
{
static const char * V_14 [] = {
L_13 ,
L_14 ,
NULL
} ;
static const char * V_15 [] = {
L_15 ,
L_16 ,
L_17 ,
L_18 ,
L_19 ,
NULL
} ;
static const char * V_16 [] = {
L_15 ,
L_16 ,
NULL
} ;
static const char * V_17 [] = {
L_13 ,
L_14 ,
NULL
} ;
static const char * V_18 [] = {
L_15 ,
L_20 ,
L_21 ,
L_22 ,
L_23 ,
NULL
} ;
switch ( V_1 ) {
case V_2 :
return V_14 ;
case V_4 :
return V_15 ;
case V_5 :
return V_16 ;
case V_6 :
return V_17 ;
case V_8 :
return V_18 ;
}
return NULL ;
}
static void F_3 ( T_1 V_1 , const char * * V_19 , enum V_20 * type ,
T_2 * V_21 , T_2 * V_22 , T_2 * V_23 , T_2 * V_24 , T_1 * V_25 )
{
* V_19 = F_1 ( V_1 ) ;
* V_25 = 0 ;
switch ( V_1 ) {
case V_2 :
case V_4 :
case V_5 :
case V_6 :
case V_8 :
* type = V_26 ;
* V_21 = 0 ;
* V_23 = 0 ;
break;
case V_13 :
* type = V_27 ;
* V_21 = 0 ;
* V_22 = * V_23 = 1 ;
break;
default:
* type = V_28 ;
break;
}
switch ( V_1 ) {
case V_2 :
case V_6 :
case V_8 :
* V_25 |= V_29 ;
break;
case V_3 :
case V_7 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
* V_25 |= V_30 ;
break;
case V_31 :
* V_25 |= V_32 ;
break;
}
}
static int F_4 ( const struct V_33 * V_34 ,
struct V_35 * V_36 )
{
switch ( V_36 -> V_1 ) {
case V_37 :
V_36 -> V_38 = V_34 -> V_39 ;
break;
case V_40 :
V_36 -> V_38 = V_34 -> V_41 ;
break;
case V_42 :
V_36 -> V_38 = V_34 -> V_43 ;
break;
case V_44 :
V_36 -> V_38 = V_34 -> V_45 ;
break;
case V_46 :
V_36 -> V_38 = V_34 -> V_47 ;
break;
case V_48 :
V_36 -> V_38 = V_34 -> V_49 ;
break;
case V_50 :
V_36 -> V_38 = V_34 -> V_51 ;
break;
case V_52 :
V_36 -> V_38 = V_34 -> V_53 ;
break;
case V_54 :
V_36 -> V_38 = V_34 -> V_55 ;
break;
case V_31 :
V_36 -> V_38 = V_34 -> V_56 ;
break;
case V_57 :
V_36 -> V_38 = V_34 -> V_58 ;
break;
case V_59 :
V_36 -> V_38 = V_34 -> V_60 ;
break;
case V_61 :
V_36 -> V_38 = V_34 -> V_62 ;
break;
case V_63 :
V_36 -> V_38 = V_34 -> V_64 ;
break;
case V_65 :
V_36 -> V_38 = V_34 -> V_66 ;
break;
case V_67 :
V_36 -> V_38 = V_34 -> V_68 ;
break;
case V_69 :
V_36 -> V_38 = V_34 -> V_70 ;
break;
case V_71 :
V_36 -> V_38 = V_34 -> V_72 ;
break;
case V_73 :
V_36 -> V_38 = V_34 -> V_74 ;
break;
case V_75 :
V_36 -> V_38 = V_34 -> V_76 ;
break;
case V_77 :
V_36 -> V_38 = V_34 -> V_78 ;
break;
case V_79 :
V_36 -> V_38 = V_34 -> V_80 ;
break;
case V_2 :
V_36 -> V_38 = V_34 -> V_81 ;
break;
case V_3 :
V_36 -> V_38 = V_34 -> V_82 ;
break;
case V_4 :
V_36 -> V_38 = V_34 -> V_83 ;
break;
case V_5 :
V_36 -> V_38 = V_34 -> V_84 ;
break;
case V_6 :
V_36 -> V_38 = V_34 -> V_85 ;
break;
case V_7 :
V_36 -> V_38 = V_34 -> V_86 ;
break;
case V_8 :
V_36 -> V_38 = V_34 -> V_87 ;
break;
case V_9 :
V_36 -> V_38 = V_34 -> V_88 ;
break;
case V_10 :
V_36 -> V_38 = V_34 -> V_89 ;
break;
case V_11 :
V_36 -> V_38 = V_34 -> V_90 ;
break;
case V_12 :
V_36 -> V_38 = V_34 -> V_91 ;
break;
case V_13 :
V_36 -> V_38 = V_34 -> V_92 ;
break;
default:
return - V_93 ;
}
return 0 ;
}
static int F_5 ( struct V_33 * V_34 , int V_94 ,
struct V_35 * V_36 )
{
switch ( V_36 -> V_1 ) {
case V_37 :
if ( V_94 )
return - V_95 ;
V_34 -> V_39 = V_36 -> V_38 ;
break;
case V_40 :
if ( V_94 )
return - V_95 ;
if ( V_34 -> V_96 & V_97 )
if ( V_36 -> V_38 != V_98 &&
V_36 -> V_38 != V_99 )
return - V_100 ;
V_34 -> V_41 = V_36 -> V_38 ;
break;
case V_42 :
if ( V_94 )
return - V_95 ;
V_34 -> V_43 = V_36 -> V_38 ;
break;
case V_44 :
if ( V_94 )
return - V_95 ;
if ( ! ( V_34 -> V_96 & V_97 ) )
return - V_93 ;
V_34 -> V_45 = V_36 -> V_38 ;
break;
case V_46 :
V_34 -> V_47 = V_36 -> V_38 ;
break;
case V_48 :
V_34 -> V_49 = V_36 -> V_38 ;
break;
case V_50 :
V_34 -> V_51 = V_36 -> V_38 ;
break;
case V_52 :
V_34 -> V_53 = V_36 -> V_38 ;
break;
case V_54 :
V_34 -> V_55 = V_36 -> V_38 ;
break;
case V_57 :
V_34 -> V_58 = V_36 -> V_38 ;
break;
case V_59 : {
int V_101 = V_36 -> V_38 + 1 ;
int V_102 = V_34 -> V_62 ;
V_34 -> V_60 = V_36 -> V_38 ;
V_34 -> V_62 = V_101 * ( ( V_102 + V_101 - 1 ) / V_101 ) ;
while ( V_34 -> V_62 > 34 )
V_34 -> V_62 -= V_101 ;
break;
}
case V_61 : {
int V_101 = V_34 -> V_60 + 1 ;
int V_102 = V_36 -> V_38 ;
V_34 -> V_62 = V_101 * ( ( V_102 + V_101 - 1 ) / V_101 ) ;
while ( V_34 -> V_62 > 34 )
V_34 -> V_62 -= V_101 ;
V_36 -> V_38 = V_34 -> V_62 ;
break;
}
case V_63 :
V_34 -> V_64 = V_36 -> V_38 ;
break;
case V_65 :
if ( V_94 )
return - V_95 ;
if ( V_34 -> V_56 == V_103 &&
V_36 -> V_38 != V_104 )
return - V_93 ;
V_34 -> V_66 = V_36 -> V_38 ;
break;
case V_67 :
if ( V_94 )
return - V_95 ;
V_34 -> V_68 = V_36 -> V_38 ;
break;
case V_69 :
if ( V_94 )
return - V_95 ;
V_34 -> V_70 = V_36 -> V_38 ;
break;
case V_71 :
V_34 -> V_72 = V_36 -> V_38 ;
break;
case V_73 :
V_34 -> V_74 = ( V_36 -> V_38 != 0 ) ;
break;
case V_75 :
V_34 -> V_76 = V_36 -> V_38 ;
break;
case V_77 :
if ( V_94 )
return - V_95 ;
V_34 -> V_78 = V_36 -> V_38 ;
V_34 -> V_56 =
( V_34 -> V_78 == V_105 ||
V_34 -> V_78 == V_106 ) ?
V_103 :
V_107 ;
if ( V_34 -> V_56 == V_103 )
V_34 -> V_66 =
V_104 ;
break;
case V_79 :
V_34 -> V_80 = V_36 -> V_38 ;
break;
case V_2 :
V_34 -> V_81 = V_36 -> V_38 ;
break;
case V_3 :
V_34 -> V_82 = V_36 -> V_38 ;
break;
case V_4 :
V_34 -> V_83 = V_36 -> V_38 ;
break;
case V_5 :
V_34 -> V_84 = V_36 -> V_38 ;
break;
case V_6 :
V_34 -> V_85 = V_36 -> V_38 ;
break;
case V_7 :
V_34 -> V_86 = V_36 -> V_38 ;
break;
case V_8 :
V_34 -> V_87 = V_36 -> V_38 ;
break;
case V_9 :
V_34 -> V_88 = V_36 -> V_38 ;
break;
case V_10 :
V_34 -> V_89 = V_36 -> V_38 ;
break;
case V_11 :
V_34 -> V_90 = V_36 -> V_38 ;
break;
case V_12 :
V_34 -> V_91 = V_36 -> V_38 ;
break;
case V_13 :
V_34 -> V_92 = V_36 -> V_38 ;
break;
default:
return - V_93 ;
}
return 0 ;
}
static int F_6 ( struct V_108 * V_109 ,
T_2 V_21 , T_2 V_22 , T_2 V_23 , T_2 V_24 )
{
const char * V_19 ;
switch ( V_109 -> V_1 ) {
case V_2 :
case V_3 :
case V_4 :
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
F_3 ( V_109 -> V_1 , & V_19 , & V_109 -> type ,
& V_21 , & V_22 , & V_23 , & V_24 , & V_109 -> V_25 ) ;
V_109 -> V_110 = V_21 ;
V_109 -> V_111 = V_22 ;
V_109 -> V_23 = V_23 ;
V_109 -> V_112 = V_24 ;
V_109 -> V_113 [ 0 ] = V_109 -> V_113 [ 1 ] = 0 ;
F_7 ( V_109 -> V_19 , V_19 , sizeof( V_109 -> V_19 ) ) ;
return 0 ;
default:
return F_8 ( V_109 , V_21 , V_22 , V_23 , V_24 ) ;
}
}
int F_9 ( const struct V_33 * V_34 ,
struct V_108 * V_109 )
{
int V_114 ;
switch ( V_109 -> V_1 ) {
case V_115 :
return F_8 ( V_109 , 0 , 0 , 0 , 0 ) ;
case V_77 :
return F_8 ( V_109 ,
V_116 ,
V_117 , 1 ,
V_116 ) ;
case V_79 :
if ( V_34 -> V_96 & V_118 )
return F_8 ( V_109 ,
V_119 ,
V_120 , 1 ,
V_119 ) ;
return F_6 ( V_109 ,
V_119 ,
V_119 , 1 ,
V_121 . V_80 ) ;
case V_37 :
return F_8 ( V_109 ,
V_122 ,
V_123 , 1 ,
V_124 ) ;
case V_40 :
if ( V_34 -> V_96 & V_97 ) {
return F_8 ( V_109 ,
V_98 ,
V_99 , 1 ,
V_121 . V_41 ) ;
}
return F_8 ( V_109 ,
V_98 ,
V_98 , 1 ,
V_121 . V_41 ) ;
case V_42 :
V_114 = F_8 ( V_109 ,
V_125 ,
V_126 , 1 ,
V_121 . V_43 ) ;
if ( V_114 )
return V_114 ;
if ( V_34 -> V_96 & V_97 &&
V_34 -> V_41 != V_98 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_46 :
return F_8 ( V_109 ,
V_128 ,
V_129 , 1 ,
V_128 ) ;
case V_48 :
V_114 = F_8 ( V_109 ,
V_130 ,
V_131 , 1 ,
V_130 ) ;
if ( V_114 == 0 &&
V_34 -> V_47 != V_132 )
V_109 -> V_25 |= V_127 ;
return V_114 ;
case V_50 :
return F_8 ( V_109 ,
V_133 ,
V_134 , 1 ,
V_133 ) ;
case V_52 :
return F_8 ( V_109 ,
V_135 ,
V_136 , 1 ,
V_135 ) ;
case V_54 :
return F_8 ( V_109 , 0 , 1 , 1 , 0 ) ;
case V_44 :
V_114 = F_8 ( V_109 ,
V_137 ,
V_138 , 1 ,
V_121 . V_45 ) ;
if ( V_114 )
return V_114 ;
if ( V_34 -> V_96 & V_97 ) {
if ( V_34 -> V_41 !=
V_99 )
V_109 -> V_25 |= V_127 ;
} else
V_109 -> V_25 |= V_139 ;
return 0 ;
case V_31 :
V_114 = F_8 ( V_109 ,
V_103 ,
V_107 , 1 ,
V_107 ) ;
if ( V_114 == 0 )
V_109 -> V_25 |= V_32 ;
return V_114 ;
case V_57 :
return F_8 ( V_109 ,
V_140 ,
V_141 , 1 ,
V_142 ) ;
case V_59 :
return F_8 ( V_109 , 0 , 33 , 1 , 2 ) ;
case V_61 :
return F_8 ( V_109 , 1 , 34 , 1 ,
V_34 -> V_143 ? 12 : 15 ) ;
case V_63 :
return F_8 ( V_109 , 0 , 1 , 1 , 1 ) ;
case V_65 :
V_114 = F_8 ( V_109 ,
V_144 ,
V_104 , 1 ,
V_144 ) ;
if ( V_114 == 0 &&
V_34 -> V_56 == V_103 )
V_109 -> V_25 |= V_127 ;
return V_114 ;
case V_67 :
return F_8 ( V_109 , 0 , 27000000 , 1 , 6000000 ) ;
case V_69 :
V_114 = F_8 ( V_109 , 0 , 27000000 , 1 , 8000000 ) ;
if ( V_114 == 0 &&
V_34 -> V_66 ==
V_104 )
V_109 -> V_25 |= V_127 ;
return V_114 ;
case V_71 :
return F_8 ( V_109 , 0 , 255 , 1 , 0 ) ;
case V_73 :
return F_8 ( V_109 , 0 , 1 , 1 , 0 ) ;
case V_75 :
return F_8 ( V_109 , 0 , 0xffffff , 1 , 0x008080 ) ;
case V_2 :
return F_6 ( V_109 ,
V_145 ,
V_146 , 1 ,
V_121 . V_81 ) ;
case V_3 :
F_6 ( V_109 , 0 , 15 , 1 ,
V_121 . V_82 ) ;
V_109 -> V_25 |= V_30 ;
if ( V_34 -> V_81 ==
V_146 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_4 :
F_6 ( V_109 ,
V_147 ,
V_148 ,
1 ,
V_121 . V_83 ) ;
if ( V_34 -> V_81 ==
V_146 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_5 :
F_6 ( V_109 ,
V_149 ,
V_150 ,
1 ,
V_121 . V_84 ) ;
if ( V_34 -> V_81 ==
V_146 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_6 :
return F_6 ( V_109 ,
V_151 ,
V_152 , 1 ,
V_121 . V_85 ) ;
case V_7 :
F_6 ( V_109 , 0 , 31 , 1 ,
V_121 . V_86 ) ;
V_109 -> V_25 |= V_30 ;
if ( V_34 -> V_85 ==
V_152 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_8 :
return F_6 ( V_109 ,
V_153 ,
V_154 , 1 ,
V_121 . V_87 ) ;
case V_9 :
F_6 ( V_109 , 0 , 255 , 1 ,
V_121 . V_88 ) ;
V_109 -> V_25 |= V_30 ;
if ( V_34 -> V_87 ==
V_153 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_10 :
F_6 ( V_109 , 0 , 255 , 1 ,
V_121 . V_89 ) ;
V_109 -> V_25 |= V_30 ;
if ( V_34 -> V_87 ==
V_153 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_11 :
F_6 ( V_109 , 0 , 255 , 1 ,
V_121 . V_90 ) ;
V_109 -> V_25 |= V_30 ;
if ( V_34 -> V_87 ==
V_153 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_12 :
F_6 ( V_109 , 0 , 255 , 1 ,
V_121 . V_91 ) ;
V_109 -> V_25 |= V_30 ;
if ( V_34 -> V_87 ==
V_153 )
V_109 -> V_25 |= V_127 ;
return 0 ;
case V_13 :
return F_6 ( V_109 , 0 , 1 , 1 ,
V_121 . V_92 ) ;
default:
return - V_93 ;
}
}
const char * const * F_10 ( const struct V_33 * V_155 , T_1 V_1 )
{
static const char * const V_156 [] = {
L_24 ,
L_25 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
NULL
} ;
static const char * V_157 [] = {
L_24 ,
L_30 ,
L_26 ,
L_27 ,
L_28 ,
L_29 ,
NULL
} ;
static const char * V_158 [] = {
L_25 ,
L_31 ,
L_25 ,
L_25 ,
L_32 ,
NULL
} ;
switch ( V_1 ) {
case V_77 :
return ( V_155 -> V_96 & V_159 ) ?
V_157 : V_156 ;
case V_40 :
return ( V_155 -> V_96 & V_97 ) ?
V_158 : F_11 ( V_1 ) ;
case V_160 :
case V_161 :
return NULL ;
case V_2 :
case V_4 :
case V_5 :
case V_6 :
case V_8 :
return F_2 ( V_1 ) ;
default:
return F_11 ( V_1 ) ;
}
}
static void F_12 ( struct V_33 * V_34 )
{
V_34 -> V_162 =
( V_34 -> V_39 << 0 ) |
( V_34 -> V_47 << 8 ) |
( V_34 -> V_49 << 10 ) |
( ( ( V_34 -> V_51 == V_134 )
? 3 : V_34 -> V_51 ) << 12 ) |
( V_34 -> V_53 << 14 ) ;
if ( ( V_34 -> V_96 & V_97 ) &&
V_34 -> V_41 == V_99 ) {
V_34 -> V_162 |=
( ( 3 - V_98 ) << 2 ) |
( V_34 -> V_45 << 4 ) |
( V_163 << 28 ) ;
} else {
V_34 -> V_162 |=
( ( 3 - V_34 -> V_41 ) << 2 ) |
( ( 1 + V_34 -> V_43 ) << 4 ) ;
}
}
static int F_13 ( struct V_35 * V_36 , struct V_108 * V_109 ,
const char * const * V_164 )
{
if ( V_109 -> V_25 & V_139 )
return - V_93 ;
if ( V_109 -> V_25 & V_165 )
return - V_95 ;
if ( V_109 -> type == V_166 )
return 0 ;
if ( V_109 -> type == V_167 ||
V_109 -> type == V_168 ||
V_109 -> type == V_169 )
return 0 ;
if ( V_36 -> V_38 < V_109 -> V_110 || V_36 -> V_38 > V_109 -> V_111 )
return - V_100 ;
if ( V_109 -> type == V_26 && V_164 != NULL ) {
if ( V_164 [ V_36 -> V_38 ] == NULL ||
V_164 [ V_36 -> V_38 ] [ 0 ] == '\0' )
return - V_93 ;
}
if ( V_109 -> type == V_170 &&
( V_36 -> V_38 & ~ V_109 -> V_111 ) )
return - V_100 ;
return 0 ;
}
int F_14 ( struct V_33 * V_34 , int V_94 ,
struct V_171 * V_172 , unsigned int V_173 )
{
int V_114 = 0 ;
int V_174 ;
if ( V_173 == V_175 ) {
for ( V_174 = 0 ; V_174 < V_172 -> V_176 ; V_174 ++ ) {
struct V_35 * V_36 = V_172 -> V_177 + V_174 ;
V_114 = F_4 ( V_34 , V_36 ) ;
if ( V_114 ) {
V_172 -> V_178 = V_174 ;
break;
}
}
return V_114 ;
}
for ( V_174 = 0 ; V_174 < V_172 -> V_176 ; V_174 ++ ) {
struct V_35 * V_36 = V_172 -> V_177 + V_174 ;
struct V_108 V_109 ;
const char * const * V_164 = NULL ;
V_109 . V_1 = V_36 -> V_1 ;
V_114 = F_9 ( V_34 , & V_109 ) ;
if ( V_114 )
break;
if ( V_109 . type == V_26 )
V_164 = F_10 ( V_34 , V_109 . V_1 ) ;
V_114 = F_13 ( V_36 , & V_109 , V_164 ) ;
if ( V_114 )
break;
V_114 = F_5 ( V_34 , V_94 , V_36 ) ;
if ( V_114 )
break;
}
if ( V_114 == 0 &&
V_34 -> V_66 == V_144 &&
V_34 -> V_70 < V_34 -> V_68 ) {
V_114 = - V_100 ;
V_172 -> V_178 = V_172 -> V_176 ;
}
if ( V_114 )
V_172 -> V_178 = V_174 ;
else
F_12 ( V_34 ) ;
return V_114 ;
}
void F_15 ( struct V_33 * V_155 )
{
* V_155 = V_121 ;
F_12 ( V_155 ) ;
}
static int F_16 ( void * V_179 , T_3 V_180 ,
T_1 V_173 , int args , ... )
{
T_1 V_181 [ V_182 ] ;
T_4 V_183 ;
int V_174 ;
va_start ( V_183 , args ) ;
for ( V_174 = 0 ; V_174 < args ; V_174 ++ )
V_181 [ V_174 ] = va_arg ( V_183 , int ) ;
va_end ( V_183 ) ;
return V_180 ( V_179 , V_173 , args , 0 , V_181 ) ;
}
int F_17 ( void * V_179 , T_3 V_180 ,
const struct V_33 * V_184 ,
const struct V_33 * V_185 )
{
static int V_186 [] = {
0 ,
1 ,
2 ,
14 ,
11 ,
12 ,
} ;
int V_114 = 0 ;
int V_187 = ( V_184 == NULL ) ;
T_5 V_188 = V_185 -> V_86 ;
F_16 ( V_179 , V_180 , V_189 , 2 , V_185 -> V_190 , 0 ) ;
if ( V_187 || F_18 ( V_143 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_191 , 1 ,
V_185 -> V_143 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_192 ) || F_18 ( V_193 ) || F_18 ( V_56 ) ) {
T_5 V_194 = V_185 -> V_192 ;
T_5 V_195 = V_185 -> V_193 ;
if ( V_185 -> V_56 == V_103 ) {
V_194 /= 2 ;
V_195 /= 2 ;
}
V_114 = F_16 ( V_179 , V_180 , V_196 , 2 ,
V_195 , V_194 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_78 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_197 , 1 ,
V_186 [ V_185 -> V_78 ] ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_58 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_198 , 1 ,
1 + V_185 -> V_58 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_60 ) || F_18 ( V_62 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_199 , 2 ,
V_185 -> V_62 , V_185 -> V_60 + 1 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_64 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_200 , 1 ,
V_185 -> V_64 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_162 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_201 ,
1 , V_185 -> V_162 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_55 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_202 , 1 ,
V_185 -> V_55 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_66 ) || F_18 ( V_68 ) ||
F_18 ( V_70 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_203 , 5 ,
V_185 -> V_66 , V_185 -> V_68 ,
V_185 -> V_70 / 400 , 0 , 0 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_81 ) ||
F_18 ( V_85 ) ||
F_18 ( V_87 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_204 ,
2 , V_185 -> V_81 |
( V_185 -> V_85 << 1 ) ,
V_185 -> V_87 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_89 ) ||
F_18 ( V_88 ) ||
F_18 ( V_91 ) ||
F_18 ( V_90 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_205 , 4 ,
V_185 -> V_89 ,
V_185 -> V_88 ,
V_185 -> V_91 ,
V_185 -> V_90 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_83 ) ||
F_18 ( V_84 ) ) {
V_114 = F_16 ( V_179 , V_180 ,
V_206 ,
2 , V_185 -> V_83 ,
V_185 -> V_84 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_82 ) ||
V_184 -> V_86 != V_188 ) {
V_114 = F_16 ( V_179 , V_180 , V_207 ,
2 , V_185 -> V_82 , V_188 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_72 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_208 ,
1 , V_185 -> V_72 ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_74 ) ||
( V_185 -> V_74 && F_18 ( V_76 ) ) ) {
V_114 = F_16 ( V_179 , V_180 , V_209 , 1 ,
V_185 -> V_74 | ( V_185 -> V_76 << 8 ) ) ;
if ( V_114 ) return V_114 ;
}
if ( V_187 || F_18 ( V_92 ) ) {
V_114 = F_16 ( V_179 , V_180 , V_210 , 2 ,
7 , V_185 -> V_92 ) ;
if ( V_114 ) return V_114 ;
}
return 0 ;
}
static const char * F_19 ( const struct V_33 * V_155 , T_1 V_1 )
{
const char * const * V_211 = F_10 ( V_155 , V_1 ) ;
struct V_35 V_36 ;
if ( V_211 == NULL )
goto V_212;
V_36 . V_1 = V_1 ;
if ( F_4 ( V_155 , & V_36 ) )
goto V_212;
while ( V_36 . V_38 -- && * V_211 ) V_211 ++ ;
if ( * V_211 == NULL )
goto V_212;
return * V_211 ;
V_212:
return L_33 ;
}
void F_20 ( const struct V_33 * V_155 , const char * V_213 )
{
int V_214 = V_155 -> V_56 == V_103 ;
F_21 ( V_215 L_34 ,
V_213 ,
F_19 ( V_155 , V_77 ) ) ;
if ( V_155 -> V_92 )
F_21 ( L_35 ) ;
F_21 ( L_36 ) ;
F_21 ( V_215 L_37 ,
V_213 ,
F_19 ( V_155 , V_79 ) ) ;
F_21 ( V_215 L_38 ,
V_213 ,
V_155 -> V_192 / ( V_214 ? 2 : 1 ) , V_155 -> V_193 / ( V_214 ? 2 : 1 ) ,
V_155 -> V_143 ? 25 : 30 ,
( V_155 -> V_74 ) ? L_39 : L_25 ) ;
F_21 ( V_215 L_40 ,
V_213 ,
F_19 ( V_155 , V_31 ) ,
F_19 ( V_155 , V_57 ) ,
F_19 ( V_155 , V_65 ) ,
V_155 -> V_68 ) ;
if ( V_155 -> V_66 == V_144 )
F_21 ( L_41 , V_155 -> V_70 ) ;
F_21 ( L_36 ) ;
F_21 ( V_215
L_42 ,
V_213 ,
V_155 -> V_62 , V_155 -> V_60 ,
V_155 -> V_64 ? L_25 : L_43 ) ;
if ( V_155 -> V_72 )
F_21 ( V_215 L_44 ,
V_213 , V_155 -> V_72 ) ;
F_21 ( V_215 L_45 ,
V_213 ,
F_19 ( V_155 , V_37 ) ,
F_19 ( V_155 , V_40 ) ,
F_19 ( V_155 ,
V_155 -> V_41 == V_99
? V_44
: V_42 ) ,
F_19 ( V_155 , V_46 ) ,
V_155 -> V_55 ? L_39 : L_25 ) ;
if ( V_155 -> V_47 == V_132 )
F_21 ( L_46 , F_19 ( V_155 ,
V_48 ) ) ;
F_21 ( L_47 ,
F_19 ( V_155 , V_50 ) ,
F_19 ( V_155 , V_52 ) ) ;
F_21 ( V_215 L_48 ,
V_213 ,
F_19 ( V_155 ,
V_2 ) ,
F_19 ( V_155 ,
V_4 ) ,
F_19 ( V_155 ,
V_5 ) ,
V_155 -> V_82 ) ;
F_21 ( V_215 L_49 ,
V_213 ,
F_19 ( V_155 ,
V_6 ) ,
V_155 -> V_86 ) ;
F_21 ( V_215
L_50 ,
V_213 ,
F_19 ( V_155 ,
V_8 ) ,
V_155 -> V_89 ,
V_155 -> V_88 ,
V_155 -> V_91 ,
V_155 -> V_90 ) ;
}
static inline struct V_216 * F_22 ( struct V_217 * V_36 )
{
return F_23 ( V_36 -> V_218 , struct V_216 , V_219 ) ;
}
static int F_24 ( struct V_216 * V_219 ,
T_1 V_173 , int args , ... )
{
T_1 V_181 [ V_182 ] ;
T_4 V_183 ;
int V_174 ;
va_start ( V_183 , args ) ;
for ( V_174 = 0 ; V_174 < args ; V_174 ++ )
V_181 [ V_174 ] = va_arg ( V_183 , int ) ;
va_end ( V_183 ) ;
return V_219 -> V_180 ( V_219 -> V_179 , V_173 , args , 0 , V_181 ) ;
}
static inline int F_25 ( struct V_217 * V_36 )
{
return V_36 && V_36 -> V_220 != V_36 -> V_221 . V_220 ;
}
static int F_26 ( struct V_217 * V_36 )
{
struct V_216 * V_219 = F_22 ( V_36 ) ;
T_2 V_220 = V_36 -> V_220 ;
switch ( V_36 -> V_1 ) {
case V_59 : {
int V_101 = V_220 + 1 ;
int V_102 = V_219 -> V_62 -> V_220 ;
V_102 = V_101 * ( ( V_102 + V_101 - 1 ) / V_101 ) ;
while ( V_102 > 34 )
V_102 -= V_101 ;
V_219 -> V_62 -> V_220 = V_102 ;
break;
}
case V_77 :
V_219 -> V_56 -> V_220 =
( V_219 -> V_78 -> V_220 == V_105 ||
V_219 -> V_78 -> V_220 == V_106 ) ?
V_103 :
V_107 ;
if ( V_219 -> V_56 -> V_220 == V_103 )
V_219 -> V_66 -> V_220 =
V_104 ;
if ( V_219 -> V_66 -> V_220 == V_144 &&
V_219 -> V_70 -> V_220 < V_219 -> V_68 -> V_220 )
V_219 -> V_70 -> V_220 = V_219 -> V_68 -> V_220 ;
break;
}
return 0 ;
}
static int F_27 ( struct V_217 * V_36 )
{
static const int V_186 [] = {
0 ,
1 ,
2 ,
14 ,
11 ,
12 ,
} ;
struct V_216 * V_219 = F_22 ( V_36 ) ;
T_2 V_220 = V_36 -> V_220 ;
T_1 V_222 ;
int V_114 ;
switch ( V_36 -> V_1 ) {
case V_79 :
if ( V_219 -> V_223 && V_219 -> V_223 -> V_224 )
return V_219 -> V_223 -> V_224 ( V_219 , V_220 ) ;
return 0 ;
case V_57 :
return F_24 ( V_219 ,
V_198 , 1 , V_220 + 1 ) ;
case V_63 :
return F_24 ( V_219 , V_200 , 1 , V_220 ) ;
case V_54 :
return F_24 ( V_219 , V_202 , 1 , V_220 ) ;
case V_71 :
return F_24 ( V_219 ,
V_208 , 1 , V_220 ) ;
case V_13 :
return F_24 ( V_219 , V_210 , 2 , 7 , V_220 ) ;
case V_37 :
V_222 = ( V_219 -> V_39 -> V_220 << 0 ) |
( V_219 -> V_47 -> V_220 << 8 ) |
( V_219 -> V_49 -> V_220 << 10 ) |
( V_219 -> V_53 -> V_220 << 14 ) ;
if ( V_219 -> V_51 -> V_220 == V_134 )
V_222 |= 3 << 12 ;
else
V_222 |= V_219 -> V_51 -> V_220 << 12 ;
if ( V_219 -> V_41 -> V_220 == V_99 ) {
V_222 |=
#if 1
( ( 3 - V_98 ) << 2 ) |
#endif
( V_219 -> V_45 -> V_220 << 4 ) |
( V_163 << 28 ) ;
} else {
V_222 |=
( ( 3 - V_219 -> V_41 -> V_220 ) << 2 ) |
( ( 1 + V_219 -> V_43 -> V_220 ) << 4 ) ;
}
V_114 = F_24 ( V_219 ,
V_201 , 1 , V_222 ) ;
if ( V_114 )
return V_114 ;
V_219 -> V_162 = V_222 ;
if ( V_219 -> V_45 ) {
int V_225 = V_219 -> V_41 -> V_220 ==
V_99 ;
F_28 ( V_219 -> V_45 , V_225 ) ;
F_28 ( V_219 -> V_43 , ! V_225 ) ;
}
F_28 ( V_219 -> V_49 ,
V_219 -> V_47 -> V_220 == V_132 ) ;
if ( F_25 ( V_219 -> V_39 ) &&
V_219 -> V_223 && V_219 -> V_223 -> V_226 )
return V_219 -> V_223 -> V_226 ( V_219 , V_219 -> V_39 -> V_220 ) ;
if ( F_25 ( V_219 -> V_47 ) &&
V_219 -> V_223 && V_219 -> V_223 -> V_227 )
return V_219 -> V_223 -> V_227 ( V_219 , V_219 -> V_47 -> V_220 ) ;
return 0 ;
case V_59 :
return F_24 ( V_219 , V_199 , 2 ,
V_219 -> V_62 -> V_220 ,
V_219 -> V_60 -> V_220 + 1 ) ;
case V_77 :
V_114 = F_24 ( V_219 ,
V_197 , 1 , V_186 [ V_220 ] ) ;
if ( V_114 )
return V_114 ;
V_114 = F_24 ( V_219 , V_203 , 5 ,
V_219 -> V_66 -> V_220 ,
V_219 -> V_68 -> V_220 ,
V_219 -> V_70 -> V_220 / 400 , 0 , 0 ) ;
if ( V_114 )
return V_114 ;
F_28 ( V_219 -> V_66 ,
V_219 -> V_56 -> V_220 != V_103 ) ;
F_28 ( V_219 -> V_70 ,
V_219 -> V_66 -> V_220 != V_104 ) ;
if ( F_25 ( V_219 -> V_56 ) &&
V_219 -> V_223 && V_219 -> V_223 -> V_228 )
return V_219 -> V_223 -> V_228 ( V_219 , V_219 -> V_56 -> V_220 ) ;
return 0 ;
case V_73 :
return F_24 ( V_219 , V_209 , 1 ,
V_219 -> V_74 -> V_220 |
( V_219 -> V_76 -> V_220 << 8 ) ) ;
case V_2 : {
int V_229 ;
V_114 = F_24 ( V_219 , V_204 , 2 ,
V_219 -> V_81 -> V_220 |
( V_219 -> V_85 -> V_220 << 1 ) ,
V_219 -> V_87 -> V_220 ) ;
if ( V_114 )
return V_114 ;
V_229 = V_219 -> V_81 -> V_220 !=
V_146 ;
F_28 ( V_219 -> V_82 , V_229 ) ;
F_28 ( V_219 -> V_83 , V_229 ) ;
F_28 ( V_219 -> V_84 , V_229 ) ;
V_229 = V_219 -> V_85 -> V_220 !=
V_152 ;
F_28 ( V_219 -> V_86 , V_229 ) ;
V_229 = V_219 -> V_87 -> V_220 !=
V_153 ;
F_28 ( V_219 -> V_89 , V_229 ) ;
F_28 ( V_219 -> V_88 , V_229 ) ;
F_28 ( V_219 -> V_91 , V_229 ) ;
F_28 ( V_219 -> V_90 , V_229 ) ;
return 0 ;
}
case V_4 :
return F_24 ( V_219 ,
V_206 , 2 ,
V_219 -> V_83 -> V_220 ,
V_219 -> V_84 -> V_220 ) ;
case V_3 :
return F_24 ( V_219 , V_207 , 2 ,
V_219 -> V_82 -> V_220 ,
V_219 -> V_86 -> V_220 ) ;
case V_9 :
return F_24 ( V_219 , V_205 , 4 ,
V_219 -> V_89 -> V_220 ,
V_219 -> V_88 -> V_220 ,
V_219 -> V_91 -> V_220 ,
V_219 -> V_90 -> V_220 ) ;
}
return - V_93 ;
}
static struct V_217 * F_29 ( struct V_230 * V_219 ,
T_1 V_1 , T_2 V_21 , T_2 V_22 , T_2 V_23 , T_2 V_24 )
{
struct V_231 V_232 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
F_3 ( V_1 , & V_232 . V_19 , & V_232 . type , & V_21 , & V_22 , & V_23 , & V_24 , & V_232 . V_25 ) ;
V_232 . V_223 = & V_233 ;
V_232 . V_1 = V_1 ;
V_232 . V_21 = V_21 ;
V_232 . V_22 = V_22 ;
V_232 . V_24 = V_24 ;
if ( V_232 . type == V_26 ) {
V_232 . V_23 = 0 ;
V_232 . V_234 = V_23 ;
V_232 . V_235 = F_2 ( V_1 ) ;
} else {
V_232 . V_23 = V_23 ;
V_232 . V_234 = 0 ;
}
return F_30 ( V_219 , & V_232 , NULL ) ;
}
static struct V_217 * F_31 ( struct V_230 * V_219 ,
T_1 V_1 , T_2 V_21 , T_2 V_22 , T_2 V_23 , T_2 V_24 )
{
return F_32 ( V_219 , & V_233 , V_1 , V_21 , V_22 , V_23 , V_24 ) ;
}
static struct V_217 * F_33 ( struct V_230 * V_219 ,
T_1 V_1 , T_2 V_22 , T_2 V_236 , T_2 V_24 )
{
return F_34 ( V_219 , & V_233 , V_1 , V_22 , V_236 , V_24 ) ;
}
int F_35 ( struct V_216 * V_237 ,
unsigned V_238 )
{
struct V_230 * V_219 = & V_237 -> V_219 ;
T_1 V_239 = V_237 -> V_96 ;
int V_240 = V_239 & V_118 ;
int V_241 = V_239 & V_97 ;
int V_242 = V_239 & V_159 ;
V_237 -> V_192 = 720 ;
V_237 -> V_193 = 480 ;
F_36 ( V_219 , V_238 ) ;
V_237 -> V_78 = F_33 ( V_219 ,
V_77 ,
V_117 , V_242 ? 0 : 2 ,
V_116 ) ;
V_237 -> V_80 = F_33 ( V_219 ,
V_79 ,
V_120 , V_240 ? 0 : 2 ,
V_119 ) ;
V_237 -> V_39 = F_33 ( V_219 ,
V_37 ,
V_123 , 0 ,
V_124 ) ;
V_237 -> V_41 = F_33 ( V_219 ,
V_40 ,
V_99 , V_241 ? ~ 0x12 : ~ 0x2 ,
V_98 ) ;
V_237 -> V_43 = F_33 ( V_219 ,
V_42 ,
V_126 , 0x1ff ,
V_243 ) ;
V_237 -> V_47 = F_33 ( V_219 ,
V_46 ,
V_129 , 0 ,
V_128 ) ;
V_237 -> V_49 = F_33 ( V_219 ,
V_48 ,
V_131 , 0 ,
V_130 ) ;
V_237 -> V_51 = F_33 ( V_219 ,
V_50 ,
V_134 , 0 ,
V_133 ) ;
V_237 -> V_53 = F_33 ( V_219 ,
V_52 ,
V_136 , 0 ,
V_135 ) ;
F_31 ( V_219 , V_54 , 0 , 1 , 1 , 0 ) ;
if ( V_241 )
V_237 -> V_45 = F_33 ( V_219 ,
V_44 ,
V_138 , 0x03 ,
V_244 ) ;
V_237 -> V_56 = F_33 ( V_219 ,
V_31 ,
V_107 , 0 ,
V_107 ) ;
F_33 ( V_219 ,
V_57 ,
V_141 , 0 ,
V_142 ) ;
V_237 -> V_60 = F_31 ( V_219 ,
V_59 , 0 , 33 , 1 , 2 ) ;
V_237 -> V_62 = F_31 ( V_219 ,
V_61 ,
1 , 34 , 1 , V_237 -> V_143 ? 12 : 15 ) ;
F_31 ( V_219 , V_63 , 0 , 1 , 1 , 1 ) ;
V_237 -> V_66 = F_33 ( V_219 ,
V_65 ,
V_104 , 0 ,
V_144 ) ;
V_237 -> V_68 = F_31 ( V_219 ,
V_67 ,
0 , 27000000 , 1 , 6000000 ) ;
V_237 -> V_70 = F_31 ( V_219 ,
V_69 ,
0 , 27000000 , 1 , 8000000 ) ;
F_31 ( V_219 ,
V_71 , 0 , 255 , 1 , 0 ) ;
V_237 -> V_74 = F_31 ( V_219 ,
V_73 , 0 , 1 , 1 , 0 ) ;
V_237 -> V_76 = F_31 ( V_219 ,
V_75 , 0 , 0xffffff , 1 , 0x008080 ) ;
V_237 -> V_81 = F_29 ( V_219 ,
V_2 ,
V_145 ,
V_146 , 0 ,
V_145 ) ;
V_237 -> V_82 = F_29 ( V_219 ,
V_3 ,
0 , 15 , 1 , 0 ) ;
V_237 -> V_83 = F_29 ( V_219 ,
V_4 ,
V_147 ,
V_148 ,
0 ,
V_245 ) ;
V_237 -> V_84 = F_29 ( V_219 ,
V_5 ,
V_149 ,
V_150 ,
0 ,
V_150 ) ;
V_237 -> V_85 = F_29 ( V_219 ,
V_6 ,
V_151 ,
V_152 ,
0 ,
V_151 ) ;
V_237 -> V_86 = F_29 ( V_219 ,
V_7 ,
0 , 31 , 1 , 8 ) ;
V_237 -> V_87 = F_29 ( V_219 ,
V_8 ,
V_153 ,
V_154 ,
0 ,
V_153 ) ;
V_237 -> V_89 = F_29 ( V_219 ,
V_10 ,
0 , 255 , 1 , 0 ) ;
V_237 -> V_88 = F_29 ( V_219 ,
V_9 ,
0 , 255 , 1 , 255 ) ;
V_237 -> V_91 = F_29 ( V_219 ,
V_12 ,
0 , 255 , 1 , 0 ) ;
V_237 -> V_90 = F_29 ( V_219 ,
V_11 ,
0 , 255 , 1 , 255 ) ;
F_29 ( V_219 , V_13 ,
0 , 1 , 1 , 0 ) ;
if ( V_219 -> error ) {
int V_114 = V_219 -> error ;
F_37 ( V_219 ) ;
return V_114 ;
}
F_38 ( 8 , & V_237 -> V_39 ) ;
F_38 ( 2 , & V_237 -> V_60 ) ;
F_38 ( 5 , & V_237 -> V_78 ) ;
F_38 ( 2 , & V_237 -> V_74 ) ;
F_38 ( 3 , & V_237 -> V_81 ) ;
F_38 ( 2 , & V_237 -> V_83 ) ;
F_38 ( 2 , & V_237 -> V_82 ) ;
F_38 ( 4 , & V_237 -> V_88 ) ;
return 0 ;
}
void F_39 ( struct V_216 * V_237 , int V_143 )
{
V_237 -> V_143 = V_143 ;
V_237 -> V_62 -> V_112 = V_237 -> V_143 ? 12 : 15 ;
}
int F_40 ( struct V_216 * V_237 )
{
int V_195 = V_237 -> V_193 ;
int V_194 = V_237 -> V_192 ;
int V_114 ;
V_114 = F_24 ( V_237 , V_189 , 2 , V_237 -> V_190 , 0 ) ;
if ( V_114 )
return V_114 ;
V_114 = F_24 ( V_237 , V_191 , 1 , V_237 -> V_143 ) ;
if ( V_114 )
return V_114 ;
if ( F_41 ( V_237 -> V_56 ) == V_103 ) {
V_194 /= 2 ;
V_195 /= 2 ;
}
V_114 = F_24 ( V_237 , V_196 , 2 , V_195 , V_194 ) ;
if ( V_114 )
return V_114 ;
return F_42 ( & V_237 -> V_219 ) ;
}
void F_43 ( struct V_216 * V_237 , int V_94 )
{
F_44 ( V_237 -> V_39 , V_94 ) ;
F_44 ( V_237 -> V_41 , V_94 ) ;
F_44 ( V_237 -> V_43 , V_94 ) ;
F_44 ( V_237 -> V_45 , V_94 ) ;
F_44 ( V_237 -> V_80 , V_94 ) ;
F_44 ( V_237 -> V_78 , V_94 ) ;
F_44 ( V_237 -> V_66 , V_94 ) ;
F_44 ( V_237 -> V_68 , V_94 ) ;
F_44 ( V_237 -> V_70 , V_94 ) ;
}
