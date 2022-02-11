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
F_5 ( V_22 -> V_34 , F_6 ( V_24 -> V_20 -> V_35 -> V_36 ) ,
sizeof( V_22 -> V_34 ) ) ;
V_22 -> V_37 = 0 ;
V_22 -> V_38 = 0 ;
V_22 -> V_39 = 0 ;
}
static T_1 F_7 ( struct V_19 * V_20 )
{
return ( (struct V_1 * ) F_4 ( V_20 ) ) -> V_40 ;
}
static void F_8 ( struct V_19 * V_20 , T_1 V_41 )
{
( (struct V_1 * ) F_4 ( V_20 ) ) -> V_40 = V_41 ;
}
static void F_9 ( struct V_19 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_4 ( V_42 ) ;
int V_4 = 0 ;
T_2 V_45 = 0 ;
T_2 V_46 ;
if ( ( V_2 -> V_47 < 1 ) || ( V_2 -> V_47 > 2 ) ) {
F_10 ( V_2 , L_4 ) ;
return;
}
V_46 = ( V_2 -> V_47 == 1 ) ? V_48 :
V_49 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_50 & V_46 ) ) {
V_44 -> V_51 = 0 ;
V_44 -> V_52 = 0 ;
return;
}
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_45 , V_2 -> V_47 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_4 ) ;
return;
}
if ( V_45 & V_53 )
V_44 -> V_51 = V_54 ;
else
V_44 -> V_51 = 0 ;
if ( V_45 & V_55 )
V_44 -> V_52 = V_54 ;
else
V_44 -> V_52 = 0 ;
}
static int F_12 ( struct V_19 * V_42 ,
struct V_43 * V_44 )
{
struct V_1 * V_2 = F_4 ( V_42 ) ;
T_2 V_45 = 0 ;
int V_4 = 0 ;
T_2 V_46 ;
if ( ( V_2 -> V_47 < 1 ) || ( V_2 -> V_47 > 2 ) )
return - V_56 ;
V_46 = ( V_2 -> V_47 == 1 ) ? V_48 :
V_49 ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_50 & V_46 ) )
return - V_56 ;
if ( V_44 -> V_51 & ~ V_54 )
return - V_57 ;
V_4 = F_11 ( V_2 -> V_24 -> V_20 , & V_45 , V_2 -> V_47 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_5 ) ;
return V_4 ;
}
if ( V_44 -> V_52 & V_54 ) {
V_45 |= V_58 | V_55 |
V_53 ;
} else {
V_45 &= ~ ( V_55 | V_53 ) ;
V_45 |= V_58 ;
}
V_4 = F_13 ( V_2 -> V_24 -> V_20 , V_45 , V_2 -> V_47 ) ;
if ( V_4 )
F_10 ( V_2 , L_6 ) ;
return V_4 ;
}
static int F_14 ( struct V_19 * V_20 , int V_59 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_60 = F_15 ( V_2 -> V_61 ) ;
switch ( V_59 ) {
case V_62 :
return ( V_2 -> V_61 ? V_60 : V_63 ) +
( V_2 -> V_5 * 2 ) +
#ifdef F_16
( V_2 -> V_13 * 5 ) ;
#else
( V_2 -> V_13 * 2 ) ;
#endif
case V_64 :
return V_65 - ! ( V_2 -> V_24 -> V_20 -> V_32 . V_50
& V_66 ) * 2 ;
case V_67 :
return F_17 ( V_68 ) ;
default:
return - V_56 ;
}
}
static void F_18 ( struct V_19 * V_20 ,
struct V_69 * V_70 , T_3 * V_71 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_72 = 0 ;
int V_3 , V_73 = 0 ;
F_19 ( & V_2 -> V_74 ) ;
if ( ! ( V_2 -> V_61 ) ) {
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
V_71 [ V_72 ++ ] =
( ( unsigned long * ) & V_2 -> V_70 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_76 ; V_3 ++ )
V_71 [ V_72 ++ ] =
( ( unsigned long * ) & V_2 -> V_77 ) [ V_3 ] ;
for ( V_3 = 0 ; V_3 < V_78 ; V_3 ++ )
V_71 [ V_72 ++ ] =
( ( unsigned long * ) & V_2 -> V_79 ) [ V_3 ] ;
} else {
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ ) {
if ( ( V_2 -> V_61 >> V_73 ) & 1 )
V_71 [ V_72 ++ ] =
( ( unsigned long * ) & V_2 -> V_70 ) [ V_3 ] ;
V_73 ++ ;
}
for ( V_3 = 0 ; V_3 < V_76 ; V_3 ++ ) {
if ( ( V_2 -> V_61 >> V_73 ) & 1 )
V_71 [ V_72 ++ ] =
( ( unsigned long * ) & V_2 -> V_77 ) [ V_3 ] ;
V_73 ++ ;
}
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
V_71 [ V_72 ++ ] = V_2 -> V_80 [ V_3 ] -> V_81 ;
V_71 [ V_72 ++ ] = V_2 -> V_80 [ V_3 ] -> V_82 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
V_71 [ V_72 ++ ] = V_2 -> V_83 [ V_3 ] -> V_81 ;
V_71 [ V_72 ++ ] = V_2 -> V_83 [ V_3 ] -> V_82 ;
#ifdef F_16
V_71 [ V_72 ++ ] = V_2 -> V_83 [ V_3 ] -> V_84 ;
V_71 [ V_72 ++ ] = V_2 -> V_83 [ V_3 ] -> V_85 ;
V_71 [ V_72 ++ ] = V_2 -> V_83 [ V_3 ] -> V_86 ;
#endif
}
F_20 ( & V_2 -> V_74 ) ;
}
static void F_21 ( struct V_19 * V_20 ,
struct V_87 * V_88 , T_2 * V_89 )
{
F_22 ( V_20 , & V_88 -> V_50 , V_89 ) ;
}
static void F_23 ( struct V_19 * V_20 ,
T_4 V_90 , T_5 * V_71 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_72 = 0 ;
int V_3 ;
switch ( V_90 ) {
case V_64 :
for ( V_3 = 0 ; V_3 < V_65 - 2 ; V_3 ++ )
strcpy ( V_71 + V_3 * V_91 , V_92 [ V_3 ] ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_50 & V_66 )
for (; V_3 < V_65 ; V_3 ++ )
strcpy ( V_71 + V_3 * V_91 , V_92 [ V_3 ] ) ;
break;
case V_62 :
if ( ! V_2 -> V_61 ) {
for ( V_3 = 0 ; V_3 < V_75 ; V_3 ++ )
strcpy ( V_71 + ( V_72 ++ ) * V_91 ,
V_93 [ V_3 ] ) ;
for ( V_3 = 0 ; V_3 < V_76 ; V_3 ++ )
strcpy ( V_71 + ( V_72 ++ ) * V_91 ,
V_93 [ V_3 +
V_75 ] ) ;
for ( V_3 = 0 ; V_3 < V_78 ; V_3 ++ )
strcpy ( V_71 + ( V_72 ++ ) * V_91 ,
V_93 [ V_3 +
V_75 +
V_76 ] ) ;
} else
for ( V_3 = 0 ; V_3 < V_75 + V_76 ; V_3 ++ ) {
if ( ( V_2 -> V_61 >> V_3 ) & 1 ) {
strcpy ( V_71 +
( V_72 ++ ) * V_91 ,
V_93 [ V_3 ] ) ;
}
if ( ! ( V_2 -> V_61 >> V_3 ) )
break;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ ) {
sprintf ( V_71 + ( V_72 ++ ) * V_91 ,
L_7 , V_3 ) ;
sprintf ( V_71 + ( V_72 ++ ) * V_91 ,
L_8 , V_3 ) ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
sprintf ( V_71 + ( V_72 ++ ) * V_91 ,
L_9 , V_3 ) ;
sprintf ( V_71 + ( V_72 ++ ) * V_91 ,
L_10 , V_3 ) ;
#ifdef F_16
sprintf ( V_71 + ( V_72 ++ ) * V_91 ,
L_11 , V_3 ) ;
sprintf ( V_71 + ( V_72 ++ ) * V_91 ,
L_12 , V_3 ) ;
sprintf ( V_71 + ( V_72 ++ ) * V_91 ,
L_13 , V_3 ) ;
#endif
}
break;
case V_67 :
for ( V_3 = 0 ; V_3 < F_17 ( V_68 ) ; V_3 ++ )
strcpy ( V_71 + V_3 * V_91 ,
V_68 [ V_3 ] ) ;
break;
}
}
static T_1 F_24 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_94 = V_95 ;
if ( ( V_24 -> V_20 -> V_32 . V_96 & V_97 ) &&
( V_2 -> V_98 . V_50 & V_99 ) )
V_94 = V_100 ;
return V_94 ;
}
static T_1 F_25 ( struct V_101 * V_102 )
{
T_1 V_103 = F_26 ( V_102 -> V_104 ) ;
if ( V_103 & ( F_27 ( V_105 )
| F_27 ( V_106 )
| F_27 ( V_107 ) ) ) {
return V_108 ;
}
if ( V_103 & ( F_27 ( V_109 )
| F_27 ( V_110 )
| F_27 ( V_111 )
| F_27 ( V_112 )
| F_27 ( V_113 )
| F_27 ( V_114 ) ) ) {
return V_115 ;
}
if ( V_103 & ( F_27 ( V_116 )
| F_27 ( V_117 )
| F_27 ( V_118 )
| F_27 ( V_119 )
| F_27 ( V_120 )
| F_27 ( V_121 ) ) ) {
return V_122 ;
}
return 0 ;
}
static T_1 F_28 ( struct V_101 * V_102 )
{
T_1 V_103 = F_26 ( V_102 -> V_123 ) ;
if ( ! V_103 )
V_103 = F_26 ( V_102 -> V_104 ) ;
if ( V_103 & ( F_27 ( V_105 )
| F_27 ( V_106 )
| F_27 ( V_107 ) ) ) {
return V_124 ;
}
if ( V_103 & ( F_27 ( V_110 )
| F_27 ( V_111 )
| F_27 ( V_113 )
| F_27 ( V_114 ) ) ) {
return V_125 ;
}
if ( V_103 & ( F_27 ( V_109 )
| F_27 ( V_126 )
| F_27 ( V_112 ) ) ) {
return V_127 ;
}
if ( V_103 & ( F_27 ( V_116 )
| F_27 ( V_117 )
| F_27 ( V_118 )
| F_27 ( V_119 )
| F_27 ( V_120 )
| F_27 ( V_121 ) ) ) {
return V_128 ;
}
return V_129 ;
}
static T_1 F_29 ( T_1 V_103 , enum V_130 V_131 )
{
int V_3 ;
T_1 V_132 = 0 ;
for ( V_3 = 0 ; V_3 < V_133 ; V_3 ++ ) {
if ( V_103 & F_27 ( V_3 ) )
V_132 |= V_134 [ V_3 ] [ V_131 ] ;
}
return V_132 ;
}
static T_1 F_30 ( T_1 V_132 , enum V_130 V_131 )
{
int V_3 ;
T_1 V_135 = 0 ;
for ( V_3 = 0 ; V_3 < V_133 ; V_3 ++ ) {
if ( V_134 [ V_3 ] [ V_131 ] & V_132 )
V_135 |= 1 << V_3 ;
}
return V_135 ;
}
static T_1 F_31 ( T_1 V_136 )
{
int V_3 ;
T_1 V_135 = 0 ;
for ( V_3 = 0 ; V_3 < V_133 ; V_3 ++ ) {
if ( V_134 [ V_3 ] [ V_137 ] == V_136 )
V_135 |= 1 << V_3 ;
}
return V_135 ;
}
static int F_32 ( struct V_19 * V_20 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_101 V_102 ;
T_1 V_103 ;
int V_140 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_141 = V_2 -> V_47 ;
V_102 . V_142 = V_143 ;
V_140 = F_33 ( V_2 -> V_24 -> V_20 ,
V_144 , & V_102 ) ;
if ( V_140 ) {
F_34 ( V_2 , L_14 ,
V_140 ) ;
return V_140 ;
}
F_35 ( V_145 , V_2 , L_15 ,
V_102 . V_142 ) ;
F_35 ( V_145 , V_2 , L_16 ,
F_26 ( V_102 . V_104 ) ) ;
F_35 ( V_145 , V_2 , L_17 ,
F_26 ( V_102 . V_146 ) ) ;
F_35 ( V_145 , V_2 , L_18 ,
F_26 ( V_102 . V_123 ) ) ;
F_35 ( V_145 , V_2 , L_19 ,
F_26 ( V_102 . V_147 ) ) ;
V_139 -> V_51 = 0 ;
V_139 -> V_148 = 0 ;
V_139 -> V_51 |= F_25 ( & V_102 ) ;
V_103 = F_26 ( V_102 . V_104 ) ;
V_139 -> V_51 |= F_29 ( V_103 , V_149 ) ;
V_103 = F_26 ( V_102 . V_146 ) ;
V_139 -> V_148 |= F_29 ( V_103 , V_150 ) ;
V_139 -> V_51 |= V_151 | V_152 ;
V_139 -> V_148 |= ( V_2 -> V_153 -> V_154 ) ? V_155 : 0 ;
V_139 -> V_148 |= ( V_2 -> V_153 -> V_154 ^ V_2 -> V_153 -> V_156 ) ?
V_157 : 0 ;
V_139 -> V_47 = F_28 ( & V_102 ) ;
V_139 -> V_158 = ( V_108 & V_139 -> V_51 ) ?
V_159 : V_160 ;
if ( F_24 ( V_20 ) ) {
V_139 -> V_51 |= V_161 ;
V_139 -> V_148 |= V_162 ;
}
V_139 -> V_94 = ( V_2 -> V_98 . V_50 & V_163 ) ?
V_100 : V_95 ;
V_103 = F_26 ( V_102 . V_147 ) ;
V_139 -> V_164 = F_29 ( V_103 , V_150 ) ;
V_139 -> V_164 |= ( V_2 -> V_98 . V_50 & V_163 ) ?
V_162 : 0 ;
V_139 -> V_165 = 0 ;
V_139 -> V_166 = 0 ;
V_139 -> V_167 = 0 ;
V_139 -> V_168 = 0 ;
V_139 -> V_169 = V_170 ;
V_139 -> V_171 = V_172 ;
return V_140 ;
}
static void F_36 ( struct V_19 * V_20 ,
struct V_138 * V_139 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_173 ;
V_139 -> V_94 = V_95 ;
V_139 -> V_51 = V_174 ;
V_139 -> V_148 = V_175 ;
V_173 = V_2 -> V_98 . V_158 ;
if ( V_173 > 0 && V_173 <= 0xC ) {
V_139 -> V_47 = V_125 ;
V_139 -> V_158 = V_159 ;
V_139 -> V_51 |= V_115 ;
V_139 -> V_148 |= V_176 ;
} else if ( V_173 == 0x80 || V_173 == 0 ) {
V_139 -> V_47 = V_124 ;
V_139 -> V_158 = V_160 ;
V_139 -> V_51 |= V_108 ;
V_139 -> V_148 |= V_177 ;
} else {
V_139 -> V_47 = - 1 ;
V_139 -> V_158 = - 1 ;
}
}
static int F_37 ( struct V_19 * V_20 , struct V_138 * V_139 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_140 = - V_57 ;
if ( F_38 ( V_2 -> V_24 , V_2 -> V_47 ) )
return - V_178 ;
F_35 ( V_145 , V_2 , L_20 ,
V_2 -> V_98 . V_50 & V_163 ,
V_2 -> V_98 . V_50 & V_99 ) ;
if ( V_2 -> V_24 -> V_20 -> V_32 . V_96 & V_179 )
V_140 = F_32 ( V_20 , V_139 ) ;
if ( V_140 )
F_36 ( V_20 , V_139 ) ;
if ( F_39 ( V_20 ) ) {
F_40 ( V_139 , V_2 -> V_98 . V_180 ) ;
V_139 -> V_181 = V_182 ;
} else {
F_40 ( V_139 , V_183 ) ;
V_139 -> V_181 = V_184 ;
}
return 0 ;
}
static T_6 F_41 ( struct V_1 * V_2 , T_1 V_136 ,
T_6 V_185 )
{
T_6 V_186 = 0 ;
if ( ! V_136 ) {
V_186 = V_185 ;
F_42 ( V_2 , L_21 ,
F_26 ( V_185 ) ) ;
} else {
T_1 V_187 = F_31 ( V_136 ) ;
V_186 = F_43 ( V_187 ) & V_185 ;
F_42 ( V_2 , L_22 , V_136 ) ;
}
return V_186 ;
}
static int F_44 ( struct V_19 * V_20 , struct V_138 * V_139 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_101 V_102 ;
T_6 V_186 ;
int V_140 ;
T_1 V_188 = F_30 ( V_139 -> V_148 , V_150 ) ;
int V_136 = F_45 ( V_139 ) ;
F_35 ( V_145 , V_2 , L_23 ,
V_136 , V_139 -> V_148 , V_139 -> V_94 , V_139 -> V_181 ) ;
if ( ! ( V_2 -> V_24 -> V_20 -> V_32 . V_96 & V_179 ) ||
( V_139 -> V_181 == V_189 ) )
return - V_57 ;
memset ( & V_102 , 0 , sizeof( V_102 ) ) ;
V_102 . V_141 = V_2 -> V_47 ;
V_102 . V_142 = V_143 ;
V_140 = F_33 ( V_2 -> V_24 -> V_20 ,
V_144 , & V_102 ) ;
if ( V_140 ) {
F_34 ( V_2 , L_24 ,
V_140 ) ;
return 0 ;
}
V_186 = V_139 -> V_94 == V_100 ?
F_43 ( V_188 ) :
F_41 ( V_2 , V_136 ,
V_102 . V_104 ) ;
V_186 &= V_102 . V_104 ;
if ( ! V_186 ) {
F_34 ( V_2 , L_25 ) ;
return - V_57 ;
}
if ( V_186 == V_102 . V_146 )
return 0 ;
F_35 ( V_145 , V_2 , L_26 ,
F_26 ( V_186 ) ) ;
V_102 . V_146 = V_186 ;
V_140 = F_33 ( V_2 -> V_24 -> V_20 , V_190 ,
& V_102 ) ;
if ( V_140 ) {
F_34 ( V_2 , L_27 ,
F_26 ( V_102 . V_146 ) , V_140 ) ;
return V_140 ;
}
F_46 ( & V_2 -> V_24 -> V_191 ) ;
if ( V_2 -> V_11 ) {
F_34 ( V_2 , L_28 ) ;
F_47 ( V_20 , 1 ) ;
if ( F_48 ( V_20 ) )
F_10 ( V_2 , L_29 , V_2 -> V_47 ) ;
}
F_49 ( & V_2 -> V_24 -> V_191 ) ;
return 0 ;
}
static int F_50 ( struct V_19 * V_20 ,
struct V_192 * V_193 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_193 -> V_194 = V_2 -> V_10 ;
V_193 -> V_195 = V_2 -> V_8 ;
V_193 -> V_196 = V_2 -> V_197 ;
V_193 -> V_198 = V_2 -> V_16 ;
V_193 -> V_199 = V_2 -> V_15 ;
V_193 -> V_200 = V_2 -> V_200 ;
V_193 -> V_201 = V_2 -> V_202 ;
V_193 -> V_203 = V_2 -> V_203 ;
V_193 -> V_204 = V_2 -> V_205 ;
V_193 -> V_206 = V_2 -> V_207 ;
V_193 -> V_208 = V_2 -> V_12 ;
return 0 ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_192 * V_193 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( ! V_193 -> V_196 )
return - V_57 ;
V_2 -> V_15 = ( V_193 -> V_199 ==
V_18 ) ?
V_209 :
V_193 -> V_199 ;
V_2 -> V_16 = ( V_193 -> V_198 ==
V_18 ) ?
V_210 :
V_193 -> V_198 ;
if ( V_193 -> V_194 != V_2 -> V_10 ||
V_193 -> V_195 != V_2 -> V_8 ) {
V_2 -> V_10 = V_193 -> V_194 ;
V_2 -> V_8 = V_193 -> V_195 ;
}
V_2 -> V_200 = V_193 -> V_200 ;
V_2 -> V_202 = V_193 -> V_201 ;
V_2 -> V_203 = V_193 -> V_203 ;
V_2 -> V_205 = V_193 -> V_204 ;
V_2 -> V_207 = V_193 -> V_206 ;
V_2 -> V_12 = V_193 -> V_208 ;
V_2 -> V_197 = V_193 -> V_196 ;
return F_1 ( V_2 ) ;
}
static int F_52 ( struct V_19 * V_20 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 ;
if ( V_212 -> V_94 )
return - V_57 ;
V_2 -> V_153 -> V_154 = V_212 -> V_154 != 0 ;
V_2 -> V_153 -> V_156 = V_212 -> V_156 != 0 ;
V_4 = F_53 ( V_24 -> V_20 , V_2 -> V_47 ,
V_2 -> V_213 + V_214 ,
V_2 -> V_153 -> V_154 ,
V_2 -> V_153 -> V_215 ,
V_2 -> V_153 -> V_156 ,
V_2 -> V_153 -> V_216 ) ;
if ( V_4 )
F_10 ( V_2 , L_30 ) ;
return V_4 ;
}
static void F_54 ( struct V_19 * V_20 ,
struct V_211 * V_212 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_212 -> V_154 = V_2 -> V_153 -> V_154 ;
V_212 -> V_156 = V_2 -> V_153 -> V_156 ;
}
static int F_55 ( struct V_19 * V_20 ,
struct V_217 * V_218 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
T_1 V_219 , V_220 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_218 -> V_221 || V_218 -> V_222 )
return - V_57 ;
V_219 = F_56 ( V_218 -> V_223 ) ;
V_219 = F_57 ( T_1 , V_219 , V_224 ) ;
V_219 = F_58 ( T_1 , V_219 , V_225 ) ;
V_220 = F_56 ( V_218 -> V_226 ) ;
V_220 = F_57 ( T_1 , V_220 , V_227 ) ;
V_220 = F_58 ( T_1 , V_220 , V_228 ) ;
if ( V_219 == ( V_2 -> V_11 ? V_2 -> V_83 [ 0 ] -> V_229 :
V_2 -> V_83 [ 0 ] -> V_230 ) &&
V_220 == V_2 -> V_80 [ 0 ] -> V_230 )
return 0 ;
F_46 ( & V_24 -> V_191 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_47 ( V_20 , 1 ) ;
}
F_59 ( V_2 ) ;
V_2 -> V_153 -> V_231 = V_220 ;
V_2 -> V_153 -> V_232 = V_219 ;
V_4 = F_60 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_31 ) ;
goto V_233;
}
if ( V_11 ) {
V_4 = F_48 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_233:
F_49 ( & V_24 -> V_191 ) ;
return V_4 ;
}
static void F_61 ( struct V_19 * V_20 ,
struct V_217 * V_218 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_218 , 0 , sizeof( * V_218 ) ) ;
V_218 -> V_234 = V_225 ;
V_218 -> V_235 = V_228 ;
V_218 -> V_223 = V_2 -> V_11 ?
V_2 -> V_83 [ 0 ] -> V_229 : V_2 -> V_83 [ 0 ] -> V_230 ;
V_218 -> V_226 = V_2 -> V_80 [ 0 ] -> V_230 ;
}
static T_1 F_62 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_13 ;
}
static T_1 F_63 ( struct V_19 * V_42 )
{
return V_236 ;
}
static int F_64 ( struct V_19 * V_20 , T_7 V_237 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( ( V_237 == V_238 &&
! ( V_2 -> V_24 -> V_20 -> V_32 . V_96 & V_239 ) ) ||
( V_237 == V_240 &&
! ( V_2 -> V_24 -> V_20 -> V_32 . V_96 & V_241 ) ) )
return - V_57 ;
V_2 -> V_242 = V_237 ;
if ( V_237 == V_238 && ! ( V_20 -> V_243 & V_244 ) )
F_34 ( V_2 ,
L_33 ) ;
if ( V_237 == V_240 && ( V_20 -> V_243 & V_244 ) )
F_34 ( V_2 ,
L_34 ) ;
return 0 ;
}
static int F_65 ( struct V_19 * V_20 , T_1 * V_245 , T_7 * V_246 ,
T_7 * V_237 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_247 * V_248 = & V_2 -> V_248 ;
int V_249 ;
T_8 V_250 = V_2 -> V_13 ;
int V_4 = 0 ;
V_249 = V_2 -> V_153 -> V_249 ? : V_2 -> V_13 ;
V_249 = 1 << F_66 ( V_249 ) ;
while ( V_250 -- ) {
if ( ! V_245 )
break;
V_245 [ V_250 ] = V_248 -> V_251 [ V_250 % V_249 ] . V_252 -
V_248 -> V_253 ;
}
if ( V_246 )
memcpy ( V_246 , V_2 -> V_254 , V_236 ) ;
if ( V_237 )
* V_237 = V_2 -> V_242 ;
return V_4 ;
}
static int F_67 ( struct V_19 * V_20 , const T_1 * V_245 ,
const T_7 * V_246 , const T_7 V_237 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
int V_3 ;
int V_249 = 0 ;
for ( V_3 = 0 ; V_3 < V_2 -> V_13 ; V_3 ++ ) {
if ( ! V_245 )
continue;
if ( V_3 > 0 && ! V_245 [ V_3 ] && ! V_249 )
V_249 = V_3 ;
if ( V_245 [ V_3 ] != ( V_3 % ( V_249 ? : V_2 -> V_13 ) ) )
return - V_57 ;
}
if ( ! V_249 )
V_249 = V_2 -> V_13 ;
if ( ! F_68 ( V_249 ) )
return - V_57 ;
if ( V_237 != V_255 ) {
V_4 = F_64 ( V_20 , V_237 ) ;
if ( V_4 )
return V_4 ;
}
F_46 ( & V_24 -> V_191 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_47 ( V_20 , 1 ) ;
}
if ( V_245 )
V_2 -> V_153 -> V_249 = V_249 ;
if ( V_246 )
memcpy ( V_2 -> V_254 , V_246 , V_236 ) ;
if ( V_11 ) {
V_4 = F_48 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
F_49 ( & V_24 -> V_191 ) ;
return V_4 ;
}
static int F_69 ( struct V_19 * V_20 ,
struct V_256 * V_139 )
{
struct V_257 * V_258 ;
struct V_259 * V_260 ;
struct V_261 * V_262 ;
if ( V_139 -> V_263 . V_264 >= V_265 )
return - V_57 ;
if ( V_139 -> V_263 . V_266 & V_267 ) {
if ( ! F_70 ( V_139 -> V_263 . V_268 . V_269 ) )
return - V_57 ;
}
switch ( V_139 -> V_263 . V_266 & ~ ( V_270 | V_267 ) ) {
case V_271 :
case V_272 :
if ( V_139 -> V_263 . V_273 . V_274 . V_275 )
return - V_57 ;
V_260 = & V_139 -> V_263 . V_273 . V_274 ;
if ( ! F_71 ( V_260 -> V_276 ) ||
! F_71 ( V_260 -> V_277 ) ||
! F_71 ( V_260 -> V_278 ) ||
! F_71 ( V_260 -> V_279 ) )
return - V_57 ;
break;
case V_280 :
V_258 = & V_139 -> V_263 . V_273 . V_281 ;
if ( V_258 -> V_282 || V_258 -> V_275 || V_258 -> V_283 ||
V_139 -> V_263 . V_284 . V_281 . V_285 != V_286 ||
( ! V_258 -> V_276 && ! V_258 -> V_277 ) ||
! F_71 ( V_258 -> V_276 ) ||
! F_71 ( V_258 -> V_277 ) )
return - V_57 ;
break;
case V_287 :
V_262 = & V_139 -> V_263 . V_273 . V_288 ;
if ( ! F_72 ( V_262 -> V_289 ) )
return - V_57 ;
if ( ! F_70 ( V_262 -> V_269 ) )
return - V_57 ;
if ( ! F_71 ( V_262 -> V_290 ) )
return - V_57 ;
break;
default:
return - V_57 ;
}
if ( ( V_139 -> V_263 . V_266 & V_270 ) ) {
if ( V_139 -> V_263 . V_268 . V_291 ||
! ( ( V_139 -> V_263 . V_268 . V_292 & F_73 ( V_293 ) ) ==
0 ||
( V_139 -> V_263 . V_268 . V_292 & F_73 ( V_293 ) ) ==
F_73 ( V_293 ) ) )
return - V_57 ;
if ( V_139 -> V_263 . V_268 . V_292 ) {
if ( F_74 ( V_139 -> V_263 . V_294 . V_292 ) >= V_295 )
return - V_57 ;
}
}
return 0 ;
}
static int F_75 ( struct V_256 * V_139 ,
struct V_296 * V_297 ,
struct V_298 * V_299 ,
unsigned char * V_300 )
{
int V_4 = 0 ;
T_9 V_301 = F_76 ( V_302 << 16 ) ;
V_299 -> V_303 = V_304 ;
memcpy ( V_299 -> V_305 . V_306 , & V_301 , V_307 ) ;
memcpy ( V_299 -> V_305 . V_308 , V_300 , V_307 ) ;
if ( ( V_139 -> V_263 . V_266 & V_270 ) &&
( V_139 -> V_263 . V_268 . V_292 & F_73 ( V_293 ) ) ) {
V_299 -> V_305 . V_309 = V_139 -> V_263 . V_294 . V_292 ;
V_299 -> V_305 . V_310 = F_73 ( V_293 ) ;
}
F_77 ( & V_299 -> V_311 , V_297 ) ;
return V_4 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_256 * V_139 ,
struct V_296 * V_297 ,
struct V_298 * V_299 ,
T_6 V_312 )
{
#ifdef F_79
unsigned char V_300 [ V_307 ] ;
if ( ! F_80 ( V_312 ) ) {
if ( V_139 -> V_263 . V_266 & V_267 )
memcpy ( & V_300 , V_139 -> V_263 . V_294 . V_269 , V_307 ) ;
else
memcpy ( & V_300 , V_2 -> V_20 -> V_313 , V_307 ) ;
} else {
F_81 ( V_312 , V_300 ) ;
}
return F_75 ( V_139 , V_297 , V_299 , & V_300 [ 0 ] ) ;
#else
return - V_57 ;
#endif
}
static int F_82 ( struct V_1 * V_2 ,
struct V_256 * V_139 ,
struct V_296 * V_314 )
{
int V_4 ;
struct V_298 * V_299 = NULL ;
struct V_298 * V_315 = NULL ;
struct V_257 * V_258 = & V_139 -> V_263 . V_273 . V_281 ;
V_315 = F_83 ( sizeof( * V_315 ) , V_316 ) ;
V_299 = F_83 ( sizeof( * V_299 ) , V_316 ) ;
if ( ! V_299 || ! V_315 ) {
V_4 = - V_178 ;
goto V_317;
}
V_4 = F_78 ( V_2 , V_139 , V_314 , V_299 ,
V_139 -> V_263 . V_284 .
V_281 . V_277 ) ;
if ( V_4 )
goto V_317;
V_315 -> V_303 = V_318 ;
V_315 -> V_319 . V_320 = V_139 -> V_263 . V_284 . V_281 . V_276 ;
if ( V_258 -> V_276 )
V_315 -> V_319 . V_321 = V_322 ;
V_315 -> V_319 . V_323 = V_139 -> V_263 . V_284 . V_281 . V_277 ;
if ( V_258 -> V_277 )
V_315 -> V_319 . V_324 = V_322 ;
F_77 ( & V_315 -> V_311 , V_314 ) ;
return 0 ;
V_317:
F_84 ( V_299 ) ;
F_84 ( V_315 ) ;
return V_4 ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_256 * V_139 ,
struct V_296 * V_314 , int V_283 )
{
int V_4 ;
struct V_298 * V_299 = NULL ;
struct V_298 * V_315 = NULL ;
struct V_298 * V_325 = NULL ;
struct V_259 * V_260 = & V_139 -> V_263 . V_273 . V_274 ;
V_299 = F_83 ( sizeof( * V_299 ) , V_316 ) ;
V_315 = F_83 ( sizeof( * V_315 ) , V_316 ) ;
V_325 = F_83 ( sizeof( * V_325 ) , V_316 ) ;
if ( ! V_299 || ! V_315 || ! V_325 ) {
V_4 = - V_178 ;
goto V_317;
}
V_315 -> V_303 = V_318 ;
if ( V_283 == V_271 ) {
V_4 = F_78 ( V_2 , V_139 , V_314 ,
V_299 ,
V_139 -> V_263 . V_284 .
V_274 . V_277 ) ;
if ( V_4 )
goto V_317;
V_325 -> V_303 = V_326 ;
V_315 -> V_319 . V_320 = V_139 -> V_263 . V_284 . V_274 . V_276 ;
V_315 -> V_319 . V_323 = V_139 -> V_263 . V_284 . V_274 . V_277 ;
V_325 -> V_327 . V_328 = V_139 -> V_263 . V_284 . V_274 . V_278 ;
V_325 -> V_327 . V_329 = V_139 -> V_263 . V_284 . V_274 . V_279 ;
} else {
V_4 = F_78 ( V_2 , V_139 , V_314 ,
V_299 ,
V_139 -> V_263 . V_284 .
V_330 . V_277 ) ;
if ( V_4 )
goto V_317;
V_325 -> V_303 = V_331 ;
V_315 -> V_319 . V_320 = V_139 -> V_263 . V_284 . V_330 . V_276 ;
V_315 -> V_319 . V_323 = V_139 -> V_263 . V_284 . V_330 . V_277 ;
V_325 -> V_327 . V_328 = V_139 -> V_263 . V_284 . V_330 . V_278 ;
V_325 -> V_327 . V_329 = V_139 -> V_263 . V_284 . V_330 . V_279 ;
}
if ( V_260 -> V_276 )
V_315 -> V_319 . V_321 = V_322 ;
if ( V_260 -> V_277 )
V_315 -> V_319 . V_324 = V_322 ;
if ( V_260 -> V_278 )
V_325 -> V_327 . V_332 = V_333 ;
if ( V_260 -> V_279 )
V_325 -> V_327 . V_334 = V_333 ;
F_77 ( & V_315 -> V_311 , V_314 ) ;
F_77 ( & V_325 -> V_311 , V_314 ) ;
return 0 ;
V_317:
F_84 ( V_299 ) ;
F_84 ( V_315 ) ;
F_84 ( V_325 ) ;
return V_4 ;
}
static int F_86 ( struct V_19 * V_20 ,
struct V_256 * V_139 ,
struct V_296 * V_297 )
{
int V_4 ;
struct V_261 * V_335 ;
struct V_298 * V_299 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
V_4 = F_69 ( V_20 , V_139 ) ;
if ( V_4 )
return V_4 ;
switch ( V_139 -> V_263 . V_266 & ~ ( V_270 | V_267 ) ) {
case V_287 :
V_299 = F_83 ( sizeof( * V_299 ) , V_316 ) ;
if ( ! V_299 )
return - V_178 ;
V_335 = & V_139 -> V_263 . V_284 . V_288 ;
F_75 ( V_139 , V_297 , V_299 ,
& V_335 -> V_269 [ 0 ] ) ;
V_299 -> V_305 . V_336 = V_335 -> V_290 ;
if ( V_335 -> V_290 )
V_299 -> V_305 . V_337 = 1 ;
break;
case V_280 :
V_4 = F_82 ( V_2 , V_139 , V_297 ) ;
break;
case V_271 :
V_4 = F_85 ( V_2 , V_139 , V_297 , V_271 ) ;
break;
case V_272 :
V_4 = F_85 ( V_2 , V_139 , V_297 , V_272 ) ;
break;
}
return V_4 ;
}
static int F_87 ( struct V_19 * V_20 ,
struct V_256 * V_139 )
{
int V_4 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_338 * V_339 ;
struct V_298 * V_340 , * V_341 ;
T_1 V_252 ;
T_2 V_342 ;
struct V_343 V_344 = {
. V_345 = V_346 ,
. V_347 = 0 ,
. V_348 = 1 ,
. V_349 = V_350 ,
} ;
V_344 . V_47 = V_2 -> V_47 ;
V_344 . V_351 = V_352 | V_139 -> V_263 . V_264 ;
F_88 ( & V_344 . V_311 ) ;
if ( V_139 -> V_263 . V_353 == V_354 )
V_252 = V_2 -> V_355 . V_252 ;
else if ( V_139 -> V_263 . V_353 & V_356 ) {
V_252 = V_139 -> V_263 . V_353 & ( V_356 - 1 ) ;
} else {
if ( V_139 -> V_263 . V_353 >= V_2 -> V_13 ) {
F_34 ( V_2 , L_35 ,
V_139 -> V_263 . V_353 ) ;
return - V_57 ;
}
V_252 = V_2 -> V_248 . V_251 [ V_139 -> V_263 . V_353 ] . V_252 ;
if ( ! V_252 ) {
F_34 ( V_2 , L_36 ,
V_139 -> V_263 . V_353 ) ;
return - V_57 ;
}
}
V_344 . V_252 = V_252 ;
V_4 = F_86 ( V_20 , V_139 , & V_344 . V_311 ) ;
if ( V_4 )
goto V_357;
V_339 = & V_2 -> V_358 [ V_139 -> V_263 . V_264 ] ;
if ( V_339 -> V_303 ) {
V_4 = F_89 ( V_2 -> V_24 -> V_20 , V_339 -> V_303 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_37 ,
V_139 -> V_263 . V_264 , V_339 -> V_303 ) ;
goto V_357;
}
V_339 -> V_303 = 0 ;
memset ( & V_339 -> V_359 , 0 ,
sizeof( struct V_360 ) ) ;
F_90 ( & V_339 -> V_311 ) ;
}
V_4 = F_91 ( V_2 -> V_24 -> V_20 , & V_344 , & V_342 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_38 ,
V_139 -> V_263 . V_264 ) ;
goto V_357;
}
V_339 -> V_303 = V_342 ;
memcpy ( & V_339 -> V_359 , & V_139 -> V_263 ,
sizeof( struct V_360 ) ) ;
F_77 ( & V_339 -> V_311 , & V_2 -> V_361 ) ;
V_357:
F_92 (spec, tmp_spec, &rule.list, list) {
F_90 ( & V_340 -> V_311 ) ;
F_84 ( V_340 ) ;
}
return V_4 ;
}
static int F_93 ( struct V_19 * V_20 ,
struct V_256 * V_139 )
{
int V_4 = 0 ;
struct V_338 * V_344 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_139 -> V_263 . V_264 >= V_265 )
return - V_57 ;
V_344 = & V_2 -> V_358 [ V_139 -> V_263 . V_264 ] ;
if ( ! V_344 -> V_303 ) {
V_4 = - V_362 ;
goto V_233;
}
V_4 = F_89 ( V_2 -> V_24 -> V_20 , V_344 -> V_303 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_39 ,
V_139 -> V_263 . V_264 , V_344 -> V_303 ) ;
goto V_233;
}
V_344 -> V_303 = 0 ;
memset ( & V_344 -> V_359 , 0 , sizeof( struct V_360 ) ) ;
F_90 ( & V_344 -> V_311 ) ;
V_233:
return V_4 ;
}
static int F_94 ( struct V_19 * V_20 , struct V_256 * V_139 ,
int V_363 )
{
int V_4 = 0 ;
struct V_338 * V_344 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
if ( V_363 < 0 || V_363 >= V_265 )
return - V_57 ;
V_344 = & V_2 -> V_358 [ V_363 ] ;
if ( V_344 -> V_303 )
memcpy ( & V_139 -> V_263 , & V_344 -> V_359 ,
sizeof( struct V_360 ) ) ;
else
V_4 = - V_362 ;
return V_4 ;
}
static int F_95 ( struct V_1 * V_2 )
{
int V_3 , V_364 = 0 ;
for ( V_3 = 0 ; V_3 < V_265 ; V_3 ++ ) {
if ( V_2 -> V_358 [ V_3 ] . V_303 )
V_364 ++ ;
}
return V_364 ;
}
static int F_96 ( struct V_19 * V_20 , struct V_256 * V_139 ,
T_1 * V_365 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_4 = 0 ;
int V_3 = 0 , V_351 = 0 ;
if ( ( V_139 -> V_139 == V_366 ||
V_139 -> V_139 == V_367 ||
V_139 -> V_139 == V_368 ) &&
( V_24 -> V_20 -> V_32 . V_369 !=
V_370 || ! V_2 -> V_11 ) )
return - V_57 ;
switch ( V_139 -> V_139 ) {
case V_371 :
V_139 -> V_71 = V_2 -> V_13 ;
break;
case V_366 :
V_139 -> V_372 = F_95 ( V_2 ) ;
break;
case V_367 :
V_4 = F_94 ( V_20 , V_139 , V_139 -> V_263 . V_264 ) ;
break;
case V_368 :
while ( ( ! V_4 || V_4 == - V_362 ) && V_351 < V_139 -> V_372 ) {
V_4 = F_94 ( V_20 , V_139 , V_3 ) ;
if ( ! V_4 )
V_365 [ V_351 ++ ] = V_3 ;
V_3 ++ ;
}
V_4 = 0 ;
break;
default:
V_4 = - V_56 ;
break;
}
return V_4 ;
}
static int F_97 ( struct V_19 * V_20 , struct V_256 * V_139 )
{
int V_4 = 0 ;
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
if ( V_24 -> V_20 -> V_32 . V_369 !=
V_370 || ! V_2 -> V_11 )
return - V_57 ;
switch ( V_139 -> V_139 ) {
case V_373 :
V_4 = F_87 ( V_20 , V_139 ) ;
break;
case V_374 :
V_4 = F_93 ( V_20 , V_139 ) ;
break;
default:
F_34 ( V_2 , L_40 , V_139 -> V_139 ) ;
return - V_57 ;
}
return V_4 ;
}
static void F_98 ( struct V_19 * V_20 ,
struct V_375 * V_376 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
memset ( V_376 , 0 , sizeof( * V_376 ) ) ;
V_376 -> V_377 = V_378 ;
V_376 -> V_379 = V_380 ;
V_376 -> V_381 = V_2 -> V_13 ;
V_376 -> V_382 = V_2 -> V_5 / V_383 ;
}
static int F_99 ( struct V_19 * V_20 ,
struct V_375 * V_376 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_11 = 0 ;
int V_4 = 0 ;
if ( V_376 -> V_384 || V_376 -> V_385 ||
V_376 -> V_382 > V_380 ||
V_376 -> V_381 > V_378 ||
! V_376 -> V_382 || ! V_376 -> V_381 )
return - V_57 ;
F_46 ( & V_24 -> V_191 ) ;
if ( V_2 -> V_11 ) {
V_11 = 1 ;
F_47 ( V_20 , 1 ) ;
}
F_59 ( V_2 ) ;
V_2 -> V_386 = V_376 -> V_382 ;
V_2 -> V_5 = V_376 -> V_382 * V_383 ;
V_2 -> V_13 = V_376 -> V_381 ;
V_4 = F_60 ( V_2 ) ;
if ( V_4 ) {
F_10 ( V_2 , L_31 ) ;
goto V_233;
}
F_100 ( V_20 , V_2 -> V_5 ) ;
F_101 ( V_20 , V_2 -> V_13 ) ;
if ( V_20 -> V_387 )
F_102 ( V_20 , V_383 ) ;
F_34 ( V_2 , L_41 , V_2 -> V_5 ) ;
F_34 ( V_2 , L_42 , V_2 -> V_13 ) ;
if ( V_11 ) {
V_4 = F_48 ( V_20 ) ;
if ( V_4 )
F_10 ( V_2 , L_32 ) ;
}
V_4 = F_1 ( V_2 ) ;
V_233:
F_49 ( & V_24 -> V_191 ) ;
return V_4 ;
}
static int F_103 ( struct V_19 * V_20 ,
struct V_388 * V_389 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_140 ;
V_140 = F_104 ( V_20 , V_389 ) ;
if ( V_140 )
return V_140 ;
if ( V_24 -> V_20 -> V_32 . V_96 & V_390 ) {
V_389 -> V_391 |=
V_392 |
V_393 |
V_394 ;
V_389 -> V_395 =
( 1 << V_396 ) |
( 1 << V_397 ) ;
V_389 -> V_398 =
( 1 << V_399 ) |
( 1 << V_400 ) ;
if ( V_24 -> V_401 )
V_389 -> V_402 = F_105 ( V_24 -> V_401 ) ;
}
return V_140 ;
}
static int F_106 ( struct V_19 * V_20 , T_1 V_50 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
bool V_403 = ! ! ( V_50 & V_404 ) ;
bool V_405 = ! ! ( V_2 -> V_406 & V_404 ) ;
int V_3 ;
if ( V_403 == V_405 )
return 0 ;
if ( V_403 ) {
bool V_407 = true ;
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_407 &= V_2 -> V_80 [ V_3 ] -> V_408 ;
if ( ! V_407 ) {
F_10 ( V_2 , L_43 ) ;
return - V_57 ;
}
V_2 -> V_406 |= V_404 ;
} else {
V_2 -> V_406 &= ~ V_404 ;
}
for ( V_3 = 0 ; V_3 < V_2 -> V_5 ; V_3 ++ )
V_2 -> V_80 [ V_3 ] -> V_409 = V_403 ;
F_42 ( V_2 , L_44 ,
V_403 ? L_45 : L_46 ) ;
return 0 ;
}
static T_1 F_107 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
return V_2 -> V_406 ;
}
static int F_108 ( struct V_19 * V_20 ,
const struct V_410 * V_411 ,
void * V_71 )
{
const struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_140 = 0 ;
switch ( V_411 -> V_303 ) {
case V_412 :
* ( T_1 * ) V_71 = V_2 -> V_153 -> V_413 ;
break;
default:
V_140 = - V_57 ;
break;
}
return V_140 ;
}
static int F_109 ( struct V_19 * V_20 ,
const struct V_410 * V_411 ,
const void * V_71 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
int V_41 , V_140 = 0 ;
switch ( V_411 -> V_303 ) {
case V_412 :
V_41 = * ( T_1 * ) V_71 ;
if ( V_41 < V_414 || V_41 > V_415 )
V_140 = - V_57 ;
else
V_2 -> V_153 -> V_413 = V_41 ;
break;
default:
V_140 = - V_57 ;
break;
}
return V_140 ;
}
static int F_110 ( struct V_19 * V_20 ,
struct V_416 * V_417 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_140 ;
T_7 V_71 [ 4 ] ;
V_140 = F_111 ( V_24 -> V_20 , V_2 -> V_47 ,
0 , 2 , V_71 ) ;
if ( V_140 < 2 )
return - V_418 ;
switch ( V_71 [ 0 ] ) {
case V_419 :
V_417 -> type = V_420 ;
V_417 -> V_421 = V_422 ;
break;
case V_423 :
if ( V_71 [ 1 ] >= 0x3 ) {
V_417 -> type = V_424 ;
V_417 -> V_421 = V_425 ;
} else {
V_417 -> type = V_420 ;
V_417 -> V_421 = V_422 ;
}
break;
case V_426 :
V_417 -> type = V_424 ;
V_417 -> V_421 = V_425 ;
break;
case V_427 :
V_417 -> type = V_428 ;
V_417 -> V_421 = V_429 ;
break;
default:
return - V_430 ;
}
return 0 ;
}
static int F_112 ( struct V_19 * V_20 ,
struct V_431 * V_432 ,
T_7 * V_71 )
{
struct V_1 * V_2 = F_4 ( V_20 ) ;
struct V_23 * V_24 = V_2 -> V_24 ;
int V_433 = V_432 -> V_433 ;
int V_3 = 0 , V_140 ;
if ( V_432 -> V_434 == 0 )
return - V_57 ;
memset ( V_71 , 0 , V_432 -> V_434 ) ;
while ( V_3 < V_432 -> V_434 ) {
F_35 ( V_145 , V_2 ,
L_47 ,
V_3 , V_433 , V_432 -> V_434 - V_3 ) ;
V_140 = F_111 ( V_24 -> V_20 , V_2 -> V_47 ,
V_433 , V_432 -> V_434 - V_3 , V_71 + V_3 ) ;
if ( ! V_140 )
return 0 ;
if ( V_140 < 0 ) {
F_10 ( V_2 ,
L_48 ,
V_3 , V_433 , V_432 -> V_434 - V_3 , V_140 ) ;
return 0 ;
}
V_3 += V_140 ;
V_433 += V_140 ;
}
return 0 ;
}
