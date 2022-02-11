static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_2 -> V_6 [ V_3 ] -> V_7 = V_2 -> V_8 ;
V_2 -> V_6 [ V_3 ] -> V_9 = V_2 -> V_10 ;
if ( V_2 -> V_11 ) {
V_4 = F_2 ( V_2 , V_2 -> V_6 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
}
if ( V_2 -> V_12 )
return 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_2 -> V_14 [ V_3 ] -> V_7 = V_2 -> V_15 ;
V_2 -> V_14 [ V_3 ] -> V_9 = V_2 -> V_16 ;
V_2 -> V_17 [ V_3 ] = V_18 ;
if ( V_2 -> V_11 ) {
V_4 = F_2 ( V_2 , V_2 -> V_14 [ V_3 ] ) ;
if ( V_4 )
return V_4 ;
}
}
return V_4 ;
}
static void
F_3 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
F_5 ( V_22 -> V_25 , V_26 , sizeof( V_22 -> V_25 ) ) ;
F_5 ( V_22 -> V_27 , V_28 L_1 V_29 L_2 ,
sizeof( V_22 -> V_27 ) ) ;
snprintf ( V_22 -> V_30 , sizeof( V_22 -> V_30 ) ,
L_3 ,
( V_31 ) ( V_24 -> V_20 -> V_32 . V_33 >> 32 ) ,
( V_31 ) ( ( V_24 -> V_20 -> V_32 . V_33 >> 16 ) & 0xffff ) ,
( V_31 ) ( V_24 -> V_20 -> V_32 . V_33 & 0xffff ) ) ;
F_5 ( V_22 -> V_34 , F_6 ( V_24 -> V_20 -> V_35 ) ,
sizeof( V_22 -> V_34 ) ) ;
V_22 -> V_36 = 0 ;
V_22 -> V_37 = 0 ;
V_22 -> V_38 = 0 ;
}
static T_1 F_7 ( struct V_19 * V_20 )
{
return ( (struct V_1 * ) F_4 ( V_20 ) ) -> V_39 ;
}
static void F_8 ( struct V_19 * V_20 , T_1 V_40 )
{
( (struct V_1 * ) F_4 ( V_20 ) ) -> V_39 = V_40 ;
}
static void F_9 ( struct V_19 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
int V_4 = 0 ;
T_2 V_44 = 0 ;
T_2 V_45 ;
if ( ( V_2 -> V_46 < 1 ) || ( V_2 -> V_46 > 2 ) ) {
F_10 ( V_2 , L_4 ) ;
return;
}
V_45 = ( V_2 -> V_46 == 1 ) ? V_47 :
V_48 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_49 & V_45 ) ) {
V_43 -> V_50 = 0 ;
V_43 -> V_51 = 0 ;
return;
}
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_44 , V_2 -> V_46 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_4 ) ;
return;
}
if ( V_44 & V_52 )
V_43 -> V_50 = V_53 ;
else
V_43 -> V_50 = 0 ;
if ( V_44 & V_54 )
V_43 -> V_51 = V_53 ;
else
V_43 -> V_51 = 0 ;
}
static int F_12 ( struct V_19 * V_41 ,
struct V_42 * V_43 )
{
struct V_1 * V_2 = F_4 ( V_41 ) ;
T_2 V_44 = 0 ;
int V_4 = 0 ;
T_2 V_45 ;
if ( ( V_2 -> V_46 < 1 ) || ( V_2 -> V_46 > 2 ) )
return - V_55 ;
V_45 = ( V_2 -> V_46 == 1 ) ? V_47 :
V_48 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_49 & V_45 ) )
return - V_55 ;
if ( V_43 -> V_50 & ~ V_53 )
return - V_56 ;
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_44 , V_2 -> V_46 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_5 ) ;
return V_4 ;
}
if ( V_43 -> V_51 & V_53 ) {
V_44 |= V_57 | V_54 |
V_52 ;
} else {
V_44 &= ~ ( V_54 | V_52 ) ;
V_44 |= V_57 ;
}
V_4 = F_13 ( V_2 -> V_24 -> V_20 , V_44 , V_2 -> V_46 ) ;
if ( V_4 )
F_10 ( V_2 , L_6 ) ;
return V_4 ;
}
static int F_14 ( struct V_19 * V_20 , int V_58 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_59 = F_15 ( V_2 -> V_60 ) ;
switch ( V_58 ) {
case V_61 :
return ( V_2 -> V_60 ? V_59 : V_62 ) +
( V_2 -> V_5 * 2 ) +
#ifdef F_16
( V_2 -> V_13 * 5 ) ;
#else
( V_2 -> V_13 * 2 ) ;
#endif
case V_63 :
return V_64 - ! ( V_2 -> V_24 -> V_20 -> V_32 . V_49
& V_65 ) * 2 ;
case V_66 :
return F_17 ( V_67 ) ;
default:
return - V_55 ;
}
}
static void F_18 ( struct V_19 * V_20 ,
struct V_68 * V_69 , T_3 * V_70 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_71 = 0 ;
int V_3 , V_72 = 0 ;
F_19 ( & V_2 -> V_73 ) ;
if ( ! ( V_2 -> V_60 ) ) {
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_69 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_76 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_77 ; V_3 ++ )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_78 ) [ V_3 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_72 ) & 1 )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_69 ) [ V_3 ] ;
V_72 ++ ;
}
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_72 ) & 1 )
V_70 [ V_71 ++ ] =
( ( unsigned long * ) & V_2 -> V_76 ) [ V_3 ] ;
V_72 ++ ;
}
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_70 [ V_71 ++ ] = V_2 -> V_79 [ V_3 ] -> V_80 ;
V_70 [ V_71 ++ ] = V_2 -> V_79 [ V_3 ] -> V_81 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_80 ;
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_81 ;
#ifdef F_16
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_83 ;
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_84 ;
V_70 [ V_71 ++ ] = V_2 -> V_82 [ V_3 ] -> V_85 ;
#endif
}
F_20 ( & V_2 -> V_73 ) ;
}
static void F_21 ( struct V_19 * V_20 ,
struct V_86 * V_87 , T_2 * V_88 )
{
F_22 ( V_20 , & V_87 -> V_49 , V_88 ) ;
}
static void F_23 ( struct V_19 * V_20 ,
T_4 V_89 , T_5 * V_70 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_71 = 0 ;
int V_3 ;
switch ( V_89 ) {
case V_63 :
for ( V_3 = 0 ; V_3 < V_64 - 2 ; V_3 ++ )
strcpy ( V_70 + V_3 * V_90 , V_91 [ V_3 ] ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_49 & V_65 )
for (; V_3 < V_64 ; V_3 ++ )
strcpy ( V_70 + V_3 * V_90 , V_91 [ V_3 ] ) ;
break;
case V_61 :
if ( ! V_2 -> V_60 ) {
for ( V_3 = 0 ; V_3 < V_74 ; V_3 ++ )
strcpy ( V_70 + ( V_71 ++ ) * V_90 ,
V_92 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
strcpy ( V_70 + ( V_71 ++ ) * V_90 ,
V_92 [ V_3 +
V_74 ] ) ;
for ( V_3 = 0 ; V_3 < V_77 ; V_3 ++ )
strcpy ( V_70 + ( V_71 ++ ) * V_90 ,
V_92 [ V_3 +
V_74 +
V_75 ] ) ;
} else
for ( V_3 = 0 ; V_3 < V_74 + V_75 ; V_3 ++ ) {
if ( ( V_2 -> V_60 >> V_3 ) & 1 ) {
strcpy ( V_70 +
( V_71 ++ ) * V_90 ,
V_92 [ V_3 ] ) ;
}
if ( ! ( V_2 -> V_60 >> V_3 ) )
break;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_7 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_8 , V_3 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_9 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_10 , V_3 ) ;
#ifdef F_16
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_11 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_12 , V_3 ) ;
sprintf ( V_70 + ( V_71 ++ ) * V_90 ,
L_13 , V_3 ) ;
#endif
}
break;
case V_66 :
for ( V_3 = 0 ; V_3 < F_17 ( V_67 ) ; V_3 ++ )
strcpy ( V_70 + V_3 * V_90 ,
V_67 [ V_3 ] ) ;
break;
}
}
static T_1 F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_93 = V_94 ;
if ( ( V_24 -> V_20 -> V_32 . V_95 & V_96 ) &&
( V_2 -> V_97 . V_49 & V_98 ) )
V_93 = V_99 ;
return V_93 ;
}
static T_1 F_25 ( struct V_100 * V_101 )
{
T_1 V_102 = F_26 ( V_101 -> V_103 ) ;
if ( V_102 & ( F_27 ( V_104 )
| F_27 ( V_105 )
| F_27 ( V_106 ) ) ) {
return V_107 ;
}
if ( V_102 & ( F_27 ( V_108 )
| F_27 ( V_109 )
| F_27 ( V_110 )
| F_27 ( V_111 )
| F_27 ( V_112 )
| F_27 ( V_113 ) ) ) {
return V_114 ;
}
if ( V_102 & ( F_27 ( V_115 )
| F_27 ( V_116 )
| F_27 ( V_117 )
| F_27 ( V_118 )
| F_27 ( V_119 )
| F_27 ( V_120 ) ) ) {
return V_121 ;
}
return 0 ;
}
static T_1 F_28 ( struct V_100 * V_101 )
{
T_1 V_102 = F_26 ( V_101 -> V_122 ) ;
if ( ! V_102 )
V_102 = F_26 ( V_101 -> V_103 ) ;
if ( V_102 & ( F_27 ( V_104 )
| F_27 ( V_105 )
| F_27 ( V_106 ) ) ) {
return V_123 ;
}
if ( V_102 & ( F_27 ( V_109 )
| F_27 ( V_110 )
| F_27 ( V_112 )
| F_27 ( V_113 ) ) ) {
return V_124 ;
}
if ( V_102 & ( F_27 ( V_108 )
| F_27 ( V_125 )
| F_27 ( V_111 ) ) ) {
return V_126 ;
}
if ( V_102 & ( F_27 ( V_115 )
| F_27 ( V_116 )
| F_27 ( V_117 )
| F_27 ( V_118 )
| F_27 ( V_119 )
| F_27 ( V_120 ) ) ) {
return V_127 ;
}
return V_128 ;
}
static T_1 F_29 ( T_1 V_102 , enum V_129 V_130 )
{
int V_3 ;
T_1 V_131 = 0 ;
for ( V_3 = 0 ; V_3 < V_132 ; V_3 ++ ) {
if ( V_102 & F_27 ( V_3 ) )
V_131 |= V_133 [ V_3 ] [ V_130 ] ;
}
return V_131 ;
}
static T_1 F_30 ( T_1 V_131 , enum V_129 V_130 )
{
int V_3 ;
T_1 V_134 = 0 ;
for ( V_3 = 0 ; V_3 < V_132 ; V_3 ++ ) {
if ( V_133 [ V_3 ] [ V_130 ] & V_131 )
V_134 |= 1 << V_3 ;
}
return V_134 ;
}
static T_1 F_31 ( T_1 V_135 )
{
int V_3 ;
T_1 V_134 = 0 ;
for ( V_3 = 0 ; V_3 < V_132 ; V_3 ++ ) {
if ( V_133 [ V_3 ] [ V_136 ] == V_135 )
V_134 |= 1 << V_3 ;
}
return V_134 ;
}
static int F_32 ( struct V_19 * V_20 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_100 V_101 ;
T_1 V_102 ;
int V_139 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_140 = V_2 -> V_46 ;
V_101 . V_141 = V_142 ;
V_139 = F_33 ( V_2 -> V_24 -> V_20 ,
V_143 , & V_101 ) ;
if ( V_139 ) {
F_34 ( V_2 , L_14 ,
V_139 ) ;
return V_139 ;
}
F_35 ( V_144 , V_2 , L_15 ,
V_101 . V_141 ) ;
F_35 ( V_144 , V_2 , L_16 ,
F_26 ( V_101 . V_103 ) ) ;
F_35 ( V_144 , V_2 , L_17 ,
F_26 ( V_101 . V_145 ) ) ;
F_35 ( V_144 , V_2 , L_18 ,
F_26 ( V_101 . V_122 ) ) ;
F_35 ( V_144 , V_2 , L_19 ,
F_26 ( V_101 . V_146 ) ) ;
V_138 -> V_50 = 0 ;
V_138 -> V_147 = 0 ;
V_138 -> V_50 |= F_25 ( & V_101 ) ;
V_102 = F_26 ( V_101 . V_103 ) ;
V_138 -> V_50 |= F_29 ( V_102 , V_148 ) ;
V_102 = F_26 ( V_101 . V_145 ) ;
V_138 -> V_147 |= F_29 ( V_102 , V_149 ) ;
V_138 -> V_50 |= V_150 | V_151 ;
V_138 -> V_147 |= ( V_2 -> V_152 -> V_153 ) ? V_154 : 0 ;
V_138 -> V_147 |= ( V_2 -> V_152 -> V_153 ^ V_2 -> V_152 -> V_155 ) ?
V_156 : 0 ;
V_138 -> V_46 = F_28 ( & V_101 ) ;
V_138 -> V_157 = ( V_107 & V_138 -> V_50 ) ?
V_158 : V_159 ;
if ( F_24 ( V_20 ) ) {
V_138 -> V_50 |= V_160 ;
V_138 -> V_147 |= V_161 ;
}
V_138 -> V_93 = ( V_2 -> V_97 . V_49 & V_162 ) ?
V_99 : V_94 ;
V_102 = F_26 ( V_101 . V_146 ) ;
V_138 -> V_163 = F_29 ( V_102 , V_149 ) ;
V_138 -> V_163 |= ( V_2 -> V_97 . V_49 & V_162 ) ?
V_161 : 0 ;
V_138 -> V_164 = 0 ;
V_138 -> V_165 = 0 ;
V_138 -> V_166 = 0 ;
V_138 -> V_167 = 0 ;
V_138 -> V_168 = V_169 ;
V_138 -> V_170 = V_171 ;
return V_139 ;
}
static void F_36 ( struct V_19 * V_20 ,
struct V_137 * V_138 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_172 ;
V_138 -> V_93 = V_94 ;
V_138 -> V_50 = V_173 ;
V_138 -> V_147 = V_174 ;
V_172 = V_2 -> V_97 . V_157 ;
if ( V_172 > 0 && V_172 <= 0xC ) {
V_138 -> V_46 = V_124 ;
V_138 -> V_157 = V_158 ;
V_138 -> V_50 |= V_114 ;
V_138 -> V_147 |= V_175 ;
} else if ( V_172 == 0x80 || V_172 == 0 ) {
V_138 -> V_46 = V_123 ;
V_138 -> V_157 = V_159 ;
V_138 -> V_50 |= V_107 ;
V_138 -> V_147 |= V_176 ;
} else {
V_138 -> V_46 = - 1 ;
V_138 -> V_157 = - 1 ;
}
}
static int F_37 ( struct V_19 * V_20 , struct V_137 * V_138 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_139 = - V_56 ;
if ( F_38 ( V_2 -> V_24 , V_2 -> V_46 ) )
return - V_177 ;
F_35 ( V_144 , V_2 , L_20 ,
V_2 -> V_97 . V_49 & V_162 ,
V_2 -> V_97 . V_49 & V_98 ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_95 & V_178 )
V_139 = F_32 ( V_20 , V_138 ) ;
if ( V_139 )
F_36 ( V_20 , V_138 ) ;
if ( F_39 ( V_20 ) ) {
F_40 ( V_138 , V_2 -> V_97 . V_179 ) ;
V_138 -> V_180 = V_181 ;
} else {
F_40 ( V_138 , V_182 ) ;
V_138 -> V_180 = V_183 ;
}
return 0 ;
}
static T_6 F_41 ( struct V_1 * V_2 , T_1 V_135 ,
T_6 V_184 )
{
T_6 V_185 = 0 ;
if ( ! V_135 ) {
V_185 = V_184 ;
F_42 ( V_2 , L_21 ,
F_26 ( V_184 ) ) ;
} else {
T_1 V_186 = F_31 ( V_135 ) ;
V_185 = F_43 ( V_186 ) & V_184 ;
F_42 ( V_2 , L_22 , V_135 ) ;
}
return V_185 ;
}
static int F_44 ( struct V_19 * V_20 , struct V_137 * V_138 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_100 V_101 ;
T_6 V_185 ;
int V_139 ;
T_1 V_187 = F_30 ( V_138 -> V_147 , V_149 ) ;
int V_135 = F_45 ( V_138 ) ;
F_35 ( V_144 , V_2 , L_23 ,
V_135 , V_138 -> V_147 , V_138 -> V_93 , V_138 -> V_180 ) ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_95 & V_178 ) ||
( V_138 -> V_180 == V_188 ) )
return - V_56 ;
memset ( & V_101 , 0 , sizeof( V_101 ) ) ;
V_101 . V_140 = V_2 -> V_46 ;
V_101 . V_141 = V_142 ;
V_139 = F_33 ( V_2 -> V_24 -> V_20 ,
V_143 , & V_101 ) ;
if ( V_139 ) {
F_34 ( V_2 , L_24 ,
V_139 ) ;
return 0 ;
}
V_185 = F_43 ( V_187 ) ;
if ( V_135 >= 0 && V_135 != V_2 -> V_97 . V_179 )
V_185 = F_41 ( V_2 , V_135 ,
V_101 . V_103 ) ;
V_185 &= V_101 . V_103 ;
if ( V_185 == V_101 . V_145 )
return 0 ;
if ( ! V_185 ) {
F_34 ( V_2 , L_25 ) ;
return - V_56 ;
}
F_35 ( V_144 , V_2 , L_26 ,
F_26 ( V_185 ) ) ;
V_101 . V_145 = V_185 ;
V_139 = F_33 ( V_2 -> V_24 -> V_20 , V_189 ,
& V_101 ) ;
if ( V_139 ) {
F_34 ( V_2 , L_27 ,
F_26 ( V_101 . V_145 ) , V_139 ) ;
return V_139 ;
}
F_34 ( V_2 , L_28 ) ;
F_46 ( & V_2 -> V_24 -> V_190 ) ;
if ( V_2 -> V_11 ) {
F_47 ( V_20 , 1 ) ;
if ( F_48 ( V_20 ) )
F_10 ( V_2 , L_29 , V_2 -> V_46 ) ;
}
F_49 ( & V_2 -> V_24 -> V_190 ) ;
return 0 ;
}
static int F_50 ( struct V_19 * V_20 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_192 -> V_193 = V_2 -> V_10 ;
V_192 -> V_194 = V_2 -> V_8 ;
V_192 -> V_195 = V_2 -> V_196 ;
V_192 -> V_197 = V_2 -> V_16 ;
V_192 -> V_198 = V_2 -> V_15 ;
V_192 -> V_199 = V_2 -> V_199 ;
V_192 -> V_200 = V_2 -> V_201 ;
V_192 -> V_202 = V_2 -> V_202 ;
V_192 -> V_203 = V_2 -> V_204 ;
V_192 -> V_205 = V_2 -> V_206 ;
V_192 -> V_207 = V_2 -> V_12 ;
return 0 ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_191 * V_192 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( ! V_192 -> V_195 )
return - V_56 ;
V_2 -> V_15 = ( V_192 -> V_198 ==
V_18 ) ?
V_208 :
V_192 -> V_198 ;
V_2 -> V_16 = ( V_192 -> V_197 ==
V_18 ) ?
V_209 :
V_192 -> V_197 ;
if ( V_192 -> V_193 != V_2 -> V_10 ||
V_192 -> V_194 != V_2 -> V_8 ) {
V_2 -> V_10 = V_192 -> V_193 ;
V_2 -> V_8 = V_192 -> V_194 ;
}
V_2 -> V_199 = V_192 -> V_199 ;
V_2 -> V_201 = V_192 -> V_200 ;
V_2 -> V_202 = V_192 -> V_202 ;
V_2 -> V_204 = V_192 -> V_203 ;
V_2 -> V_206 = V_192 -> V_205 ;
V_2 -> V_12 = V_192 -> V_207 ;
V_2 -> V_196 = V_192 -> V_195 ;
return F_1 ( V_2 ) ;
}
static int F_52 ( struct V_19 * V_20 ,
struct V_210 * V_211 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 ;
if ( V_211 -> V_93 )
return - V_56 ;
V_2 -> V_152 -> V_153 = V_211 -> V_153 != 0 ;
V_2 -> V_152 -> V_155 = V_211 -> V_155 != 0 ;
V_4 = F_53 ( V_24 -> V_20 , V_2 -> V_46 ,
V_2 -> V_212 + V_213 ,
V_2 -> V_152 -> V_153 ,
V_2 -> V_152 -> V_214 ,
V_2 -> V_152 -> V_155 ,
V_2 -> V_152 -> V_215 ) ;
if ( V_4 )
F_10 ( V_2 , L_30 ) ;
return V_4 ;
}
static void F_54 ( struct V_19 * V_20 ,
struct V_210 * V_211 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_211 -> V_153 = V_2 -> V_152 -> V_153 ;
V_211 -> V_155 = V_2 -> V_152 -> V_155 ;
}
static int F_55 ( struct V_19 * V_20 ,
struct V_216 * V_217 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_218 , V_219 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_217 -> V_220 || V_217 -> V_221 )
return - V_56 ;
V_218 = F_56 ( V_217 -> V_222 ) ;
V_218 = F_57 ( T_1 , V_218 , V_223 ) ;
V_218 = F_58 ( T_1 , V_218 , V_224 ) ;
V_219 = F_56 ( V_217 -> V_225 ) ;
V_219 = F_57 ( T_1 , V_219 , V_226 ) ;
V_219 = F_58 ( T_1 , V_219 , V_227 ) ;
if ( V_218 == ( V_2 -> V_11 ? V_2 -> V_82 [ 0 ] -> V_228 :
V_2 -> V_82 [ 0 ] -> V_229 ) &&
V_219 == V_2 -> V_79 [ 0 ] -> V_229 )
return 0 ;
F_46 ( & V_24 -> V_190 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_47 ( V_20 , 1 ) ;
}
F_59 ( V_2 ) ;
V_2 -> V_152 -> V_230 = V_219 ;
V_2 -> V_152 -> V_231 = V_218 ;
V_4 = F_60 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_31 ) ;
goto V_232;
}
if ( V_11 ) {
V_4 = F_48 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_232:
F_49 ( & V_24 -> V_190 ) ;
return V_4 ;
}
static void F_61 ( struct V_19 * V_20 ,
struct V_216 * V_217 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_217 , 0 , sizeof( * V_217 ) ) ;
V_217 -> V_233 = V_224 ;
V_217 -> V_234 = V_227 ;
V_217 -> V_222 = V_2 -> V_11 ?
V_2 -> V_82 [ 0 ] -> V_228 : V_2 -> V_82 [ 0 ] -> V_229 ;
V_217 -> V_225 = V_2 -> V_79 [ 0 ] -> V_229 ;
}
static T_1 F_62 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_13 ;
}
static T_1 F_63 ( struct V_19 * V_41 )
{
return V_235 ;
}
static int F_64 ( struct V_19 * V_20 , T_7 V_236 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( ( V_236 == V_237 &&
! ( V_2 -> V_24 -> V_20 -> V_32 . V_95 & V_238 ) ) ||
( V_236 == V_239 &&
! ( V_2 -> V_24 -> V_20 -> V_32 . V_95 & V_240 ) ) )
return - V_56 ;
V_2 -> V_241 = V_236 ;
if ( V_236 == V_237 && ! ( V_20 -> V_242 & V_243 ) )
F_34 ( V_2 ,
L_33 ) ;
if ( V_236 == V_239 && ( V_20 -> V_242 & V_243 ) )
F_34 ( V_2 ,
L_34 ) ;
return 0 ;
}
static int F_65 ( struct V_19 * V_20 , T_1 * V_244 , T_7 * V_245 ,
T_7 * V_236 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_246 * V_247 = & V_2 -> V_247 ;
int V_248 ;
T_8 V_249 = V_2 -> V_13 ;
int V_4 = 0 ;
V_248 = V_2 -> V_152 -> V_248 ? : V_2 -> V_13 ;
V_248 = 1 << F_66 ( V_248 ) ;
while ( V_249 -- ) {
if ( ! V_244 )
break;
V_244 [ V_249 ] = V_247 -> V_250 [ V_249 % V_248 ] . V_251 -
V_247 -> V_252 ;
}
if ( V_245 )
memcpy ( V_245 , V_2 -> V_253 , V_235 ) ;
if ( V_236 )
* V_236 = V_2 -> V_241 ;
return V_4 ;
}
static int F_67 ( struct V_19 * V_20 , const T_1 * V_244 ,
const T_7 * V_245 , const T_7 V_236 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
int V_3 ;
int V_248 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
if ( ! V_244 )
continue;
if ( V_3 > 0 && ! V_244 [ V_3 ] && ! V_248 )
V_248 = V_3 ;
if ( V_244 [ V_3 ] != ( V_3 % ( V_248 ? : V_2 -> V_13 ) ) )
return - V_56 ;
}
if ( ! V_248 )
V_248 = V_2 -> V_13 ;
if ( ! F_68 ( V_248 ) )
return - V_56 ;
if ( V_236 != V_254 ) {
V_4 = F_64 ( V_20 , V_236 ) ;
if ( V_4 )
return V_4 ;
}
F_46 ( & V_24 -> V_190 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_47 ( V_20 , 1 ) ;
}
if ( V_244 )
V_2 -> V_152 -> V_248 = V_248 ;
if ( V_245 )
memcpy ( V_2 -> V_253 , V_245 , V_235 ) ;
if ( V_11 ) {
V_4 = F_48 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
F_49 ( & V_24 -> V_190 ) ;
return V_4 ;
}
static int F_69 ( struct V_19 * V_20 ,
struct V_255 * V_138 )
{
struct V_256 * V_257 ;
struct V_258 * V_259 ;
struct V_260 * V_261 ;
if ( V_138 -> V_262 . V_263 >= V_264 )
return - V_56 ;
if ( V_138 -> V_262 . V_265 & V_266 ) {
if ( ! F_70 ( V_138 -> V_262 . V_267 . V_268 ) )
return - V_56 ;
}
switch ( V_138 -> V_262 . V_265 & ~ ( V_269 | V_266 ) ) {
case V_270 :
case V_271 :
if ( V_138 -> V_262 . V_272 . V_273 . V_274 )
return - V_56 ;
V_259 = & V_138 -> V_262 . V_272 . V_273 ;
if ( ! F_71 ( V_259 -> V_275 ) ||
! F_71 ( V_259 -> V_276 ) ||
! F_71 ( V_259 -> V_277 ) ||
! F_71 ( V_259 -> V_278 ) )
return - V_56 ;
break;
case V_279 :
V_257 = & V_138 -> V_262 . V_272 . V_280 ;
if ( V_257 -> V_281 || V_257 -> V_274 || V_257 -> V_282 ||
V_138 -> V_262 . V_283 . V_280 . V_284 != V_285 ||
( ! V_257 -> V_275 && ! V_257 -> V_276 ) ||
! F_71 ( V_257 -> V_275 ) ||
! F_71 ( V_257 -> V_276 ) )
return - V_56 ;
break;
case V_286 :
V_261 = & V_138 -> V_262 . V_272 . V_287 ;
if ( ! F_72 ( V_261 -> V_288 ) )
return - V_56 ;
if ( ! F_70 ( V_261 -> V_268 ) )
return - V_56 ;
if ( ! F_71 ( V_261 -> V_289 ) )
return - V_56 ;
break;
default:
return - V_56 ;
}
if ( ( V_138 -> V_262 . V_265 & V_269 ) ) {
if ( V_138 -> V_262 . V_267 . V_290 ||
! ( ( V_138 -> V_262 . V_267 . V_291 & F_73 ( V_292 ) ) ==
0 ||
( V_138 -> V_262 . V_267 . V_291 & F_73 ( V_292 ) ) ==
F_73 ( V_292 ) ) )
return - V_56 ;
if ( V_138 -> V_262 . V_267 . V_291 ) {
if ( F_74 ( V_138 -> V_262 . V_293 . V_291 ) >= V_294 )
return - V_56 ;
}
}
return 0 ;
}
static int F_75 ( struct V_255 * V_138 ,
struct V_295 * V_296 ,
struct V_297 * V_298 ,
unsigned char * V_299 )
{
int V_4 = 0 ;
T_9 V_300 = F_76 ( V_301 << 16 ) ;
V_298 -> V_302 = V_303 ;
memcpy ( V_298 -> V_304 . V_305 , & V_300 , V_306 ) ;
memcpy ( V_298 -> V_304 . V_307 , V_299 , V_306 ) ;
if ( ( V_138 -> V_262 . V_265 & V_269 ) &&
( V_138 -> V_262 . V_267 . V_291 & F_73 ( V_292 ) ) ) {
V_298 -> V_304 . V_308 = V_138 -> V_262 . V_293 . V_291 ;
V_298 -> V_304 . V_309 = F_73 ( V_292 ) ;
}
F_77 ( & V_298 -> V_310 , V_296 ) ;
return V_4 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_255 * V_138 ,
struct V_295 * V_296 ,
struct V_297 * V_298 ,
T_6 V_311 )
{
#ifdef F_79
unsigned char V_299 [ V_306 ] ;
if ( ! F_80 ( V_311 ) ) {
if ( V_138 -> V_262 . V_265 & V_266 )
memcpy ( & V_299 , V_138 -> V_262 . V_293 . V_268 , V_306 ) ;
else
memcpy ( & V_299 , V_2 -> V_20 -> V_312 , V_306 ) ;
} else {
F_81 ( V_311 , V_299 ) ;
}
return F_75 ( V_138 , V_296 , V_298 , & V_299 [ 0 ] ) ;
#else
return - V_56 ;
#endif
}
static int F_82 ( struct V_1 * V_2 ,
struct V_255 * V_138 ,
struct V_295 * V_313 )
{
int V_4 ;
struct V_297 * V_298 = NULL ;
struct V_297 * V_314 = NULL ;
struct V_256 * V_257 = & V_138 -> V_262 . V_272 . V_280 ;
V_314 = F_83 ( sizeof( * V_314 ) , V_315 ) ;
V_298 = F_83 ( sizeof( * V_298 ) , V_315 ) ;
if ( ! V_298 || ! V_314 ) {
V_4 = - V_177 ;
goto V_316;
}
V_4 = F_78 ( V_2 , V_138 , V_313 , V_298 ,
V_138 -> V_262 . V_283 .
V_280 . V_276 ) ;
if ( V_4 )
goto V_316;
V_314 -> V_302 = V_317 ;
V_314 -> V_318 . V_319 = V_138 -> V_262 . V_283 . V_280 . V_275 ;
if ( V_257 -> V_275 )
V_314 -> V_318 . V_320 = V_321 ;
V_314 -> V_318 . V_322 = V_138 -> V_262 . V_283 . V_280 . V_276 ;
if ( V_257 -> V_276 )
V_314 -> V_318 . V_323 = V_321 ;
F_77 ( & V_314 -> V_310 , V_313 ) ;
return 0 ;
V_316:
F_84 ( V_298 ) ;
F_84 ( V_314 ) ;
return V_4 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_255 * V_138 ,
struct V_295 * V_313 , int V_282 )
{
int V_4 ;
struct V_297 * V_298 = NULL ;
struct V_297 * V_314 = NULL ;
struct V_297 * V_324 = NULL ;
struct V_258 * V_259 = & V_138 -> V_262 . V_272 . V_273 ;
V_298 = F_83 ( sizeof( * V_298 ) , V_315 ) ;
V_314 = F_83 ( sizeof( * V_314 ) , V_315 ) ;
V_324 = F_83 ( sizeof( * V_324 ) , V_315 ) ;
if ( ! V_298 || ! V_314 || ! V_324 ) {
V_4 = - V_177 ;
goto V_316;
}
V_314 -> V_302 = V_317 ;
if ( V_282 == V_270 ) {
V_4 = F_78 ( V_2 , V_138 , V_313 ,
V_298 ,
V_138 -> V_262 . V_283 .
V_273 . V_276 ) ;
if ( V_4 )
goto V_316;
V_324 -> V_302 = V_325 ;
V_314 -> V_318 . V_319 = V_138 -> V_262 . V_283 . V_273 . V_275 ;
V_314 -> V_318 . V_322 = V_138 -> V_262 . V_283 . V_273 . V_276 ;
V_324 -> V_326 . V_327 = V_138 -> V_262 . V_283 . V_273 . V_277 ;
V_324 -> V_326 . V_328 = V_138 -> V_262 . V_283 . V_273 . V_278 ;
} else {
V_4 = F_78 ( V_2 , V_138 , V_313 ,
V_298 ,
V_138 -> V_262 . V_283 .
V_329 . V_276 ) ;
if ( V_4 )
goto V_316;
V_324 -> V_302 = V_330 ;
V_314 -> V_318 . V_319 = V_138 -> V_262 . V_283 . V_329 . V_275 ;
V_314 -> V_318 . V_322 = V_138 -> V_262 . V_283 . V_329 . V_276 ;
V_324 -> V_326 . V_327 = V_138 -> V_262 . V_283 . V_329 . V_277 ;
V_324 -> V_326 . V_328 = V_138 -> V_262 . V_283 . V_329 . V_278 ;
}
if ( V_259 -> V_275 )
V_314 -> V_318 . V_320 = V_321 ;
if ( V_259 -> V_276 )
V_314 -> V_318 . V_323 = V_321 ;
if ( V_259 -> V_277 )
V_324 -> V_326 . V_331 = V_332 ;
if ( V_259 -> V_278 )
V_324 -> V_326 . V_333 = V_332 ;
F_77 ( & V_314 -> V_310 , V_313 ) ;
F_77 ( & V_324 -> V_310 , V_313 ) ;
return 0 ;
V_316:
F_84 ( V_298 ) ;
F_84 ( V_314 ) ;
F_84 ( V_324 ) ;
return V_4 ;
}
static int F_86 ( struct V_19 * V_20 ,
struct V_255 * V_138 ,
struct V_295 * V_296 )
{
int V_4 ;
struct V_260 * V_334 ;
struct V_297 * V_298 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_4 = F_69 ( V_20 , V_138 ) ;
if ( V_4 )
return V_4 ;
switch ( V_138 -> V_262 . V_265 & ~ ( V_269 | V_266 ) ) {
case V_286 :
V_298 = F_83 ( sizeof( * V_298 ) , V_315 ) ;
if ( ! V_298 )
return - V_177 ;
V_334 = & V_138 -> V_262 . V_283 . V_287 ;
F_75 ( V_138 , V_296 , V_298 ,
& V_334 -> V_268 [ 0 ] ) ;
V_298 -> V_304 . V_335 = V_334 -> V_289 ;
if ( V_334 -> V_289 )
V_298 -> V_304 . V_336 = 1 ;
break;
case V_279 :
V_4 = F_82 ( V_2 , V_138 , V_296 ) ;
break;
case V_270 :
V_4 = F_85 ( V_2 , V_138 , V_296 , V_270 ) ;
break;
case V_271 :
V_4 = F_85 ( V_2 , V_138 , V_296 , V_271 ) ;
break;
}
return V_4 ;
}
static int F_87 ( struct V_19 * V_20 ,
struct V_255 * V_138 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_337 * V_338 ;
struct V_297 * V_339 , * V_340 ;
T_1 V_251 ;
T_2 V_341 ;
struct V_342 V_343 = {
. V_344 = V_345 ,
. V_346 = 0 ,
. V_347 = 1 ,
. V_348 = V_349 ,
} ;
V_343 . V_46 = V_2 -> V_46 ;
V_343 . V_350 = V_351 | V_138 -> V_262 . V_263 ;
F_88 ( & V_343 . V_310 ) ;
if ( V_138 -> V_262 . V_352 == V_353 )
V_251 = V_2 -> V_354 . V_251 ;
else if ( V_138 -> V_262 . V_352 & V_355 ) {
V_251 = V_138 -> V_262 . V_352 & ( V_355 - 1 ) ;
} else {
if ( V_138 -> V_262 . V_352 >= V_2 -> V_13 ) {
F_34 ( V_2 , L_35 ,
V_138 -> V_262 . V_352 ) ;
return - V_56 ;
}
V_251 = V_2 -> V_247 . V_250 [ V_138 -> V_262 . V_352 ] . V_251 ;
if ( ! V_251 ) {
F_34 ( V_2 , L_36 ,
V_138 -> V_262 . V_352 ) ;
return - V_56 ;
}
}
V_343 . V_251 = V_251 ;
V_4 = F_86 ( V_20 , V_138 , & V_343 . V_310 ) ;
if ( V_4 )
goto V_356;
V_338 = & V_2 -> V_357 [ V_138 -> V_262 . V_263 ] ;
if ( V_338 -> V_302 ) {
V_4 = F_89 ( V_2 -> V_24 -> V_20 , V_338 -> V_302 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_37 ,
V_138 -> V_262 . V_263 , V_338 -> V_302 ) ;
goto V_356;
}
V_338 -> V_302 = 0 ;
memset ( & V_338 -> V_358 , 0 ,
sizeof( struct V_359 ) ) ;
F_90 ( & V_338 -> V_310 ) ;
}
V_4 = F_91 ( V_2 -> V_24 -> V_20 , & V_343 , & V_341 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_38 ,
V_138 -> V_262 . V_263 ) ;
goto V_356;
}
V_338 -> V_302 = V_341 ;
memcpy ( & V_338 -> V_358 , & V_138 -> V_262 ,
sizeof( struct V_359 ) ) ;
F_77 ( & V_338 -> V_310 , & V_2 -> V_360 ) ;
V_356:
F_92 (spec, tmp_spec, &rule.list, list) {
F_90 ( & V_339 -> V_310 ) ;
F_84 ( V_339 ) ;
}
return V_4 ;
}
static int F_93 ( struct V_19 * V_20 ,
struct V_255 * V_138 )
{
int V_4 = 0 ;
struct V_337 * V_343 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_138 -> V_262 . V_263 >= V_264 )
return - V_56 ;
V_343 = & V_2 -> V_357 [ V_138 -> V_262 . V_263 ] ;
if ( ! V_343 -> V_302 ) {
V_4 = - V_361 ;
goto V_232;
}
V_4 = F_89 ( V_2 -> V_24 -> V_20 , V_343 -> V_302 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_39 ,
V_138 -> V_262 . V_263 , V_343 -> V_302 ) ;
goto V_232;
}
V_343 -> V_302 = 0 ;
memset ( & V_343 -> V_358 , 0 , sizeof( struct V_359 ) ) ;
F_90 ( & V_343 -> V_310 ) ;
V_232:
return V_4 ;
}
static int F_94 ( struct V_19 * V_20 , struct V_255 * V_138 ,
int V_362 )
{
int V_4 = 0 ;
struct V_337 * V_343 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_362 < 0 || V_362 >= V_264 )
return - V_56 ;
V_343 = & V_2 -> V_357 [ V_362 ] ;
if ( V_343 -> V_302 )
memcpy ( & V_138 -> V_262 , & V_343 -> V_358 ,
sizeof( struct V_359 ) ) ;
else
V_4 = - V_361 ;
return V_4 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_3 , V_363 = 0 ;
for ( V_3 = 0 ; V_3 < V_264 ; V_3 ++ ) {
if ( V_2 -> V_357 [ V_3 ] . V_302 )
V_363 ++ ;
}
return V_363 ;
}
static int F_96 ( struct V_19 * V_20 , struct V_255 * V_138 ,
T_1 * V_364 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 = 0 ;
int V_3 = 0 , V_350 = 0 ;
if ( ( V_138 -> V_138 == V_365 ||
V_138 -> V_138 == V_366 ||
V_138 -> V_138 == V_367 ) &&
( V_24 -> V_20 -> V_32 . V_368 !=
V_369 || ! V_2 -> V_11 ) )
return - V_56 ;
switch ( V_138 -> V_138 ) {
case V_370 :
V_138 -> V_70 = V_2 -> V_13 ;
break;
case V_365 :
V_138 -> V_371 = F_95 ( V_2 ) ;
break;
case V_366 :
V_4 = F_94 ( V_20 , V_138 , V_138 -> V_262 . V_263 ) ;
break;
case V_367 :
while ( ( ! V_4 || V_4 == - V_361 ) && V_350 < V_138 -> V_371 ) {
V_4 = F_94 ( V_20 , V_138 , V_3 ) ;
if ( ! V_4 )
V_364 [ V_350 ++ ] = V_3 ;
V_3 ++ ;
}
V_4 = 0 ;
break;
default:
V_4 = - V_55 ;
break;
}
return V_4 ;
}
static int F_97 ( struct V_19 * V_20 , struct V_255 * V_138 )
{
int V_4 = 0 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_24 -> V_20 -> V_32 . V_368 !=
V_369 || ! V_2 -> V_11 )
return - V_56 ;
switch ( V_138 -> V_138 ) {
case V_372 :
V_4 = F_87 ( V_20 , V_138 ) ;
break;
case V_373 :
V_4 = F_93 ( V_20 , V_138 ) ;
break;
default:
F_34 ( V_2 , L_40 , V_138 -> V_138 ) ;
return - V_56 ;
}
return V_4 ;
}
static void F_98 ( struct V_19 * V_20 ,
struct V_374 * V_375 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_375 , 0 , sizeof( * V_375 ) ) ;
V_375 -> V_376 = V_377 ;
V_375 -> V_378 = V_379 ;
V_375 -> V_380 = V_2 -> V_13 ;
V_375 -> V_381 = V_2 -> V_5 / V_382 ;
}
static int F_99 ( struct V_19 * V_20 ,
struct V_374 * V_375 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_375 -> V_383 || V_375 -> V_384 ||
V_375 -> V_381 > V_379 ||
V_375 -> V_380 > V_377 ||
! V_375 -> V_381 || ! V_375 -> V_380 )
return - V_56 ;
F_46 ( & V_24 -> V_190 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_47 ( V_20 , 1 ) ;
}
F_59 ( V_2 ) ;
V_2 -> V_385 = V_375 -> V_381 ;
V_2 -> V_5 = V_375 -> V_381 * V_382 ;
V_2 -> V_13 = V_375 -> V_380 ;
V_4 = F_60 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_31 ) ;
goto V_232;
}
F_100 ( V_20 , V_2 -> V_5 ) ;
F_101 ( V_20 , V_2 -> V_13 ) ;
if ( V_20 -> V_386 )
F_102 ( V_20 , V_382 ) ;
F_34 ( V_2 , L_41 , V_2 -> V_5 ) ;
F_34 ( V_2 , L_42 , V_2 -> V_13 ) ;
if ( V_11 ) {
V_4 = F_48 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_232:
F_49 ( & V_24 -> V_190 ) ;
return V_4 ;
}
static int F_103 ( struct V_19 * V_20 ,
struct V_387 * V_388 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_139 ;
V_139 = F_104 ( V_20 , V_388 ) ;
if ( V_139 )
return V_139 ;
if ( V_24 -> V_20 -> V_32 . V_95 & V_389 ) {
V_388 -> V_390 |=
V_391 |
V_392 |
V_393 ;
V_388 -> V_394 =
( 1 << V_395 ) |
( 1 << V_396 ) ;
V_388 -> V_397 =
( 1 << V_398 ) |
( 1 << V_399 ) ;
if ( V_24 -> V_400 )
V_388 -> V_401 = F_105 ( V_24 -> V_400 ) ;
}
return V_139 ;
}
static int F_106 ( struct V_19 * V_20 , T_1 V_49 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
bool V_402 = ! ! ( V_49 & V_403 ) ;
bool V_404 = ! ! ( V_2 -> V_405 & V_403 ) ;
int V_3 ;
if ( V_402 == V_404 )
return 0 ;
if ( V_402 ) {
bool V_406 = true ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_406 &= V_2 -> V_79 [ V_3 ] -> V_407 ;
if ( ! V_406 ) {
F_10 ( V_2 , L_43 ) ;
return - V_56 ;
}
V_2 -> V_405 |= V_403 ;
} else {
V_2 -> V_405 &= ~ V_403 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_2 -> V_79 [ V_3 ] -> V_408 = V_402 ;
F_42 ( V_2 , L_44 ,
V_402 ? L_45 : L_46 ) ;
return 0 ;
}
static T_1 F_107 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_405 ;
}
static int F_108 ( struct V_19 * V_20 ,
const struct V_409 * V_410 ,
void * V_70 )
{
const struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_139 = 0 ;
switch ( V_410 -> V_302 ) {
case V_411 :
* ( T_1 * ) V_70 = V_2 -> V_152 -> V_412 ;
break;
default:
V_139 = - V_56 ;
break;
}
return V_139 ;
}
static int F_109 ( struct V_19 * V_20 ,
const struct V_409 * V_410 ,
const void * V_70 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_40 , V_139 = 0 ;
switch ( V_410 -> V_302 ) {
case V_411 :
V_40 = * ( T_1 * ) V_70 ;
if ( V_40 < V_413 || V_40 > V_414 )
V_139 = - V_56 ;
else
V_2 -> V_152 -> V_412 = V_40 ;
break;
default:
V_139 = - V_56 ;
break;
}
return V_139 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_415 * V_416 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_139 ;
T_7 V_70 [ 4 ] ;
V_139 = F_111 ( V_24 -> V_20 , V_2 -> V_46 ,
0 , 2 , V_70 ) ;
if ( V_139 < 2 )
return - V_417 ;
switch ( V_70 [ 0 ] ) {
case V_418 :
V_416 -> type = V_419 ;
V_416 -> V_420 = V_421 ;
break;
case V_422 :
if ( V_70 [ 1 ] >= 0x3 ) {
V_416 -> type = V_423 ;
V_416 -> V_420 = V_424 ;
} else {
V_416 -> type = V_419 ;
V_416 -> V_420 = V_421 ;
}
break;
case V_425 :
V_416 -> type = V_423 ;
V_416 -> V_420 = V_424 ;
break;
case V_426 :
V_416 -> type = V_427 ;
V_416 -> V_420 = V_428 ;
break;
default:
return - V_429 ;
}
return 0 ;
}
static int F_112 ( struct V_19 * V_20 ,
struct V_430 * V_431 ,
T_7 * V_70 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_432 = V_431 -> V_432 ;
int V_3 = 0 , V_139 ;
if ( V_431 -> V_433 == 0 )
return - V_56 ;
memset ( V_70 , 0 , V_431 -> V_433 ) ;
while ( V_3 < V_431 -> V_433 ) {
F_35 ( V_144 , V_2 ,
L_47 ,
V_3 , V_432 , V_431 -> V_433 - V_3 ) ;
V_139 = F_111 ( V_24 -> V_20 , V_2 -> V_46 ,
V_432 , V_431 -> V_433 - V_3 , V_70 + V_3 ) ;
if ( ! V_139 )
return 0 ;
if ( V_139 < 0 ) {
F_10 ( V_2 ,
L_48 ,
V_3 , V_432 , V_431 -> V_433 - V_3 , V_139 ) ;
return 0 ;
}
V_3 += V_139 ;
V_432 += V_139 ;
}
return 0 ;
}
