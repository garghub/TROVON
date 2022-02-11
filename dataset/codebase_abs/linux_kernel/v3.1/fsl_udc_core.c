static T_1 F_1 ( const unsigned T_2 * V_1 )
{
return F_2 ( V_1 ) ;
}
static T_1 F_3 ( const unsigned T_2 * V_1 )
{
return F_4 ( V_1 ) ;
}
static void F_5 ( T_1 V_2 , unsigned T_2 * V_1 )
{
F_6 ( V_1 , V_2 ) ;
}
static void F_7 ( T_1 V_2 , unsigned T_2 * V_1 )
{
F_8 ( V_1 , V_2 ) ;
}
static inline void F_9 ( struct V_3 * V_4 )
{
if ( V_4 -> V_5 ) {
V_6 = F_1 ;
V_7 = F_5 ;
} else {
V_6 = F_3 ;
V_7 = F_7 ;
}
}
static inline T_1 F_10 ( const T_1 V_8 )
{
return V_9 -> V_4 -> V_10
? ( V_11 T_1 ) F_11 ( V_8 )
: ( V_11 T_1 ) F_12 ( V_8 ) ;
}
static inline T_1 F_13 ( const T_1 V_8 )
{
return V_9 -> V_4 -> V_10
? F_14 ( ( V_11 V_12 ) V_8 )
: F_15 ( ( V_11 V_13 ) V_8 ) ;
}
static inline void F_9 ( struct V_3 * V_4 ) {}
static void F_16 ( struct V_14 * V_15 , struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 = NULL ;
unsigned char V_21 = V_15 -> V_21 ;
struct V_22 * V_23 , * V_24 ;
int V_25 ;
V_20 = (struct V_19 * ) V_15 -> V_20 ;
F_17 ( & V_17 -> V_26 ) ;
if ( V_17 -> V_17 . V_18 == - V_27 )
V_17 -> V_17 . V_18 = V_18 ;
else
V_18 = V_17 -> V_17 . V_18 ;
V_24 = V_17 -> V_28 ;
for ( V_25 = 0 ; V_25 < V_17 -> V_29 ; V_25 ++ ) {
V_23 = V_24 ;
if ( V_25 != V_17 -> V_29 - 1 ) {
V_24 = V_23 -> V_30 ;
}
F_18 ( V_20 -> V_31 , V_23 , V_23 -> V_32 ) ;
}
if ( V_17 -> V_33 ) {
F_19 ( V_15 -> V_20 -> V_34 . V_35 . V_36 ,
V_17 -> V_17 . V_37 , V_17 -> V_17 . V_38 ,
F_20 ( V_15 )
? V_39
: V_40 ) ;
V_17 -> V_17 . V_37 = V_41 ;
V_17 -> V_33 = 0 ;
} else
F_21 ( V_15 -> V_20 -> V_34 . V_35 . V_36 ,
V_17 -> V_17 . V_37 , V_17 -> V_17 . V_38 ,
F_20 ( V_15 )
? V_39
: V_40 ) ;
if ( V_18 && ( V_18 != - V_42 ) )
F_22 ( L_1 ,
V_15 -> V_15 . V_43 , & V_17 -> V_17 , V_18 ,
V_17 -> V_17 . V_44 , V_17 -> V_17 . V_38 ) ;
V_15 -> V_21 = 1 ;
F_23 ( & V_15 -> V_20 -> V_45 ) ;
if ( V_17 -> V_17 . V_46 )
V_17 -> V_17 . V_46 ( & V_15 -> V_15 , & V_17 -> V_17 ) ;
F_24 ( & V_15 -> V_20 -> V_45 ) ;
V_15 -> V_21 = V_21 ;
}
static void F_25 ( struct V_14 * V_15 , int V_18 )
{
V_15 -> V_21 = 1 ;
F_26 ( & V_15 -> V_15 ) ;
while ( ! F_27 ( & V_15 -> V_26 ) ) {
struct V_16 * V_17 = NULL ;
V_17 = F_28 ( V_15 -> V_26 . V_47 , struct V_16 , V_26 ) ;
F_16 ( V_15 , V_17 , V_18 ) ;
}
}
static int F_29 ( struct V_19 * V_20 )
{
unsigned int V_48 , V_49 , V_50 ;
unsigned int V_51 ;
#ifndef F_30
unsigned int V_52 ;
#endif
unsigned long V_53 ;
#define F_31 1000
V_49 = F_32 ( & V_54 -> V_55 ) ;
V_49 &= ~ ( V_56 | V_57 ) ;
switch ( V_20 -> V_58 ) {
case V_59 :
V_49 |= V_60 ;
break;
case V_61 :
V_49 |= V_62 ;
case V_63 :
V_49 |= V_64 ;
break;
case V_65 :
V_49 |= V_66 ;
break;
default:
return - V_67 ;
}
F_33 ( V_49 , & V_54 -> V_55 ) ;
V_48 = F_32 ( & V_54 -> V_68 ) ;
V_48 &= ~ V_69 ;
F_33 ( V_48 , & V_54 -> V_68 ) ;
V_48 = F_32 ( & V_54 -> V_68 ) ;
V_48 |= V_70 ;
F_33 ( V_48 , & V_54 -> V_68 ) ;
V_53 = V_71 + F_31 ;
while ( F_32 ( & V_54 -> V_68 ) & V_70 ) {
if ( F_34 ( V_71 , V_53 ) ) {
F_35 ( L_2 ) ;
return - V_72 ;
}
F_36 () ;
}
V_48 = F_32 ( & V_54 -> V_73 ) ;
V_48 &= ~ V_74 ;
V_48 |= V_75 ;
V_48 |= V_76 ;
if ( V_20 -> V_4 -> V_77 )
V_48 |= V_78 ;
F_33 ( V_48 , & V_54 -> V_73 ) ;
F_33 ( 0 , & V_54 -> V_79 ) ;
V_48 = V_20 -> V_80 ;
V_48 &= V_81 ;
F_33 ( V_48 , & V_54 -> V_82 ) ;
F_22 ( L_3 ,
V_20 -> V_83 , ( int ) V_48 ,
F_32 ( & V_54 -> V_82 ) ) ;
V_51 = ( 0x0000001F & F_32 ( & V_54 -> V_84 ) ) ;
for ( V_50 = 1 ; V_50 < V_51 ; V_50 ++ ) {
V_48 = F_32 ( & V_54 -> V_85 [ V_50 ] ) ;
V_48 &= ~ ( V_86 | V_87 ) ;
V_48 |= ( V_88 << V_89 )
| ( V_88 << V_90 ) ;
F_33 ( V_48 , & V_54 -> V_85 [ V_50 ] ) ;
}
#ifndef F_30
if ( V_20 -> V_4 -> V_91 ) {
V_52 = F_37 ( & V_92 -> V_93 ) ;
V_52 |= V_94 ;
F_38 ( V_52 , & V_92 -> V_93 ) ;
}
#endif
#if F_39 ( V_95 ) && ! F_39 ( V_96 )
if ( V_20 -> V_4 -> V_91 ) {
V_48 = V_97 ;
F_38 ( V_48 , & V_92 -> V_98 ) ;
V_48 |= 0x80000000 ;
F_38 ( V_48 , & V_92 -> V_99 ) ;
}
#endif
return 0 ;
}
static void F_40 ( struct V_19 * V_20 )
{
T_1 V_100 ;
V_100 = V_101 | V_102
| V_103 | V_104
| V_105 | V_106 ;
F_33 ( V_100 , & V_54 -> V_107 ) ;
V_20 -> V_21 = 0 ;
V_100 = F_32 ( & V_54 -> V_73 ) ;
V_100 |= V_75 ;
F_33 ( V_100 , & V_54 -> V_73 ) ;
V_100 = F_32 ( & V_54 -> V_68 ) ;
V_100 |= V_69 ;
F_33 ( V_100 , & V_54 -> V_68 ) ;
}
static void F_41 ( struct V_19 * V_20 )
{
unsigned int V_48 ;
F_42 ( L_4 , V_108 ) ;
if ( V_20 -> V_34 . V_109 ) {
if ( ! ( F_32 ( & V_54 -> V_110 ) & V_111 ) ) {
F_42 ( L_5 ) ;
return;
}
}
F_33 ( 0 , & V_54 -> V_107 ) ;
V_20 -> V_21 = 1 ;
V_48 = F_32 ( & V_54 -> V_68 ) ;
V_48 &= ~ V_69 ;
F_33 ( V_48 , & V_54 -> V_68 ) ;
}
static void F_43 ( unsigned char V_50 , unsigned char V_112 ,
unsigned char V_113 )
{
unsigned int V_114 = 0 ;
V_114 = F_32 ( & V_54 -> V_85 [ V_50 ] ) ;
if ( V_112 ) {
if ( V_50 )
V_114 |= V_115 ;
V_114 |= V_116 ;
V_114 &= ~ V_86 ;
V_114 |= ( ( unsigned int ) ( V_113 )
<< V_89 ) ;
} else {
if ( V_50 )
V_114 |= V_117 ;
V_114 |= V_118 ;
V_114 &= ~ V_87 ;
V_114 |= ( ( unsigned int ) ( V_113 )
<< V_90 ) ;
}
F_33 ( V_114 , & V_54 -> V_85 [ V_50 ] ) ;
}
static void
F_44 ( unsigned char V_50 , unsigned char V_112 , int V_119 )
{
T_1 V_114 = 0 ;
V_114 = F_32 ( & V_54 -> V_85 [ V_50 ] ) ;
if ( V_119 ) {
if ( V_112 )
V_114 |= V_120 ;
else
V_114 |= V_121 ;
} else {
if ( V_112 ) {
V_114 &= ~ V_120 ;
V_114 |= V_115 ;
} else {
V_114 &= ~ V_121 ;
V_114 |= V_117 ;
}
}
F_33 ( V_114 , & V_54 -> V_85 [ V_50 ] ) ;
}
static int F_45 ( unsigned char V_50 , unsigned char V_112 )
{
T_1 V_122 ;
V_122 = F_32 ( & V_54 -> V_85 [ V_50 ] ) ;
if ( V_112 )
return ( V_122 & V_120 ) ? 1 : 0 ;
else
return ( V_122 & V_121 ) ? 1 : 0 ;
}
static void F_46 ( struct V_19 * V_20 , unsigned char V_50 ,
unsigned char V_112 , unsigned char V_113 ,
unsigned int V_123 ,
unsigned int V_124 , unsigned char V_125 )
{
struct V_126 * V_127 = & V_20 -> V_83 [ 2 * V_50 + V_112 ] ;
unsigned int V_48 = 0 ;
switch ( V_113 ) {
case V_128 :
V_48 = ( V_123 << V_129 )
| V_130 ;
break;
case V_131 :
V_48 = ( V_123 << V_129 )
| ( V_125 << V_132 ) ;
break;
case V_133 :
case V_134 :
V_48 = V_123 << V_129 ;
break;
default:
F_22 ( L_6 , V_113 ) ;
return;
}
if ( V_124 )
V_48 |= V_135 ;
V_127 -> V_136 = F_10 ( V_48 ) ;
V_127 -> V_137 = 1 ;
V_127 -> V_138 = 0 ;
}
static void F_47 ( struct V_19 * V_20 )
{
F_46 ( V_20 , 0 , V_139 , V_128 ,
V_140 , 0 , 0 ) ;
F_46 ( V_20 , 0 , V_141 , V_128 ,
V_140 , 0 , 0 ) ;
F_43 ( 0 , V_139 , V_128 ) ;
F_43 ( 0 , V_141 , V_128 ) ;
return;
}
static int F_48 ( struct V_142 * V_143 ,
const struct V_144 * V_145 )
{
struct V_19 * V_20 = NULL ;
struct V_14 * V_15 = NULL ;
unsigned short V_146 = 0 ;
unsigned char V_125 = 0 , V_124 ;
int V_147 = - V_67 ;
unsigned long V_148 = 0 ;
V_15 = F_49 ( V_143 , struct V_14 , V_15 ) ;
if ( ! V_143 || ! V_145 || V_15 -> V_145
|| ( V_145 -> V_149 != V_150 ) )
return - V_67 ;
V_20 = V_15 -> V_20 ;
if ( ! V_20 -> V_151 || ( V_20 -> V_34 . V_152 == V_153 ) )
return - V_42 ;
V_146 = F_50 ( V_145 -> V_154 ) ;
V_124 = 1 ;
switch ( V_145 -> V_155 & 0x03 ) {
case V_128 :
case V_133 :
case V_134 :
V_125 = 0 ;
break;
case V_131 :
V_125 = ( unsigned char ) ( 1 + ( ( V_146 >> 11 ) & 0x03 ) ) ;
V_146 = V_146 & 0x7ff ;
if ( V_125 > 3 )
goto V_156;
break;
default:
goto V_156;
}
F_51 ( & V_20 -> V_45 , V_148 ) ;
V_15 -> V_15 . V_157 = V_146 ;
V_15 -> V_145 = V_145 ;
V_15 -> V_21 = 0 ;
F_46 ( V_20 , ( unsigned char ) F_52 ( V_15 ) ,
( unsigned char ) ( ( V_145 -> V_158 & V_159 )
? V_141 : V_139 ) ,
( unsigned char ) ( V_145 -> V_155
& V_160 ) ,
V_146 , V_124 , V_125 ) ;
F_43 ( ( unsigned char ) F_52 ( V_15 ) ,
( unsigned char ) ( ( V_145 -> V_158 & V_159 )
? V_141 : V_139 ) ,
( unsigned char ) ( V_145 -> V_155
& V_160 ) ) ;
F_53 ( & V_20 -> V_45 , V_148 ) ;
V_147 = 0 ;
F_22 ( L_7 , V_15 -> V_15 . V_43 ,
V_15 -> V_145 -> V_158 & 0x0f ,
( V_145 -> V_158 & V_159 )
? L_8 : L_9 , V_146 ) ;
V_156:
return V_147 ;
}
static int F_54 ( struct V_142 * V_143 )
{
struct V_19 * V_20 = NULL ;
struct V_14 * V_15 = NULL ;
unsigned long V_148 = 0 ;
T_1 V_122 ;
int V_50 ;
V_15 = F_49 ( V_143 , struct V_14 , V_15 ) ;
if ( ! V_143 || ! V_15 -> V_145 ) {
F_22 ( L_10 , V_143 ? V_15 -> V_15 . V_43 : NULL ) ;
return - V_67 ;
}
V_50 = F_52 ( V_15 ) ;
V_122 = F_32 ( & V_54 -> V_85 [ V_50 ] ) ;
if ( F_20 ( V_15 ) ) {
V_122 &= ~ ( V_116 | V_86 ) ;
V_122 |= V_88 << V_89 ;
} else {
V_122 &= ~ ( V_118 | V_86 ) ;
V_122 |= V_88 << V_90 ;
}
F_33 ( V_122 , & V_54 -> V_85 [ V_50 ] ) ;
V_20 = (struct V_19 * ) V_15 -> V_20 ;
F_51 ( & V_20 -> V_45 , V_148 ) ;
F_25 ( V_15 , - V_42 ) ;
V_15 -> V_145 = NULL ;
V_15 -> V_21 = 1 ;
F_53 ( & V_20 -> V_45 , V_148 ) ;
F_22 ( L_11 , V_143 -> V_43 ) ;
return 0 ;
}
static struct V_161 *
F_55 ( struct V_142 * V_143 , T_3 V_162 )
{
struct V_16 * V_17 = NULL ;
V_17 = F_56 ( sizeof *V_17 , V_162 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_17 . V_37 = V_41 ;
F_57 ( & V_17 -> V_26 ) ;
return & V_17 -> V_17 ;
}
static void F_58 ( struct V_142 * V_143 , struct V_161 * V_163 )
{
struct V_16 * V_17 = NULL ;
V_17 = F_49 ( V_163 , struct V_16 , V_17 ) ;
if ( V_163 )
F_59 ( V_17 ) ;
}
static void F_60 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
int V_164 = F_52 ( V_15 ) * 2 + F_20 ( V_15 ) ;
T_1 V_100 , V_165 , V_166 ;
struct V_126 * V_167 = & V_15 -> V_20 -> V_83 [ V_164 ] ;
V_165 = F_20 ( V_15 )
? ( 1 << ( F_52 ( V_15 ) + 16 ) )
: ( 1 << ( F_52 ( V_15 ) ) ) ;
if ( ! ( F_27 ( & V_15 -> V_26 ) ) ) {
struct V_16 * V_168 ;
V_168 = F_28 ( V_15 -> V_26 . V_169 , struct V_16 , V_26 ) ;
V_168 -> V_170 -> V_171 =
F_10 ( V_17 -> V_28 -> V_32 & V_172 ) ;
if ( F_32 ( & V_54 -> V_173 ) & V_165 )
goto V_174;
do {
V_100 = F_32 ( & V_54 -> V_68 ) ;
F_33 ( V_100 | V_175 , & V_54 -> V_68 ) ;
V_166 = F_32 ( & V_54 -> V_176 ) & V_165 ;
} while ( ! ( F_32 ( & V_54 -> V_68 ) & V_175 ) );
V_100 = F_32 ( & V_54 -> V_68 ) ;
F_33 ( V_100 & ~ V_175 , & V_54 -> V_68 ) ;
if ( V_166 )
goto V_174;
}
V_100 = V_17 -> V_28 -> V_32 & V_177 ;
V_167 -> V_137 = F_10 ( V_100 ) ;
V_100 = F_10 ( ~ ( V_178
| V_179 ) ) ;
V_167 -> V_138 &= V_100 ;
F_61 () ;
V_100 = F_20 ( V_15 )
? ( 1 << ( F_52 ( V_15 ) + 16 ) )
: ( 1 << ( F_52 ( V_15 ) ) ) ;
F_33 ( V_100 , & V_54 -> V_173 ) ;
V_174:
return;
}
static struct V_22 * F_62 ( struct V_16 * V_17 , unsigned * V_38 ,
T_4 * V_37 , int * V_180 )
{
T_1 V_181 ;
struct V_22 * V_182 ;
* V_38 = F_63 ( V_17 -> V_17 . V_38 - V_17 -> V_17 . V_44 ,
( unsigned ) V_183 ) ;
V_182 = F_64 ( V_9 -> V_31 , V_184 , V_37 ) ;
if ( V_182 == NULL )
return V_182 ;
V_182 -> V_32 = * V_37 ;
V_181 = F_13 ( V_182 -> V_185 ) ;
V_181 &= ~ V_186 ;
V_182 -> V_185 = F_10 ( V_181 ) ;
V_181 = ( T_1 ) ( V_17 -> V_17 . V_37 + V_17 -> V_17 . V_44 ) ;
V_182 -> V_187 = F_10 ( V_181 ) ;
V_182 -> V_188 = F_10 ( V_181 + 0x1000 ) ;
V_182 -> V_189 = F_10 ( V_181 + 0x2000 ) ;
V_182 -> V_190 = F_10 ( V_181 + 0x3000 ) ;
V_182 -> V_191 = F_10 ( V_181 + 0x4000 ) ;
V_17 -> V_17 . V_44 += * V_38 ;
if ( V_17 -> V_17 . V_192 ) {
if ( * V_38 == 0 || ( * V_38 % V_17 -> V_15 -> V_15 . V_157 ) != 0 )
* V_180 = 1 ;
else
* V_180 = 0 ;
} else if ( V_17 -> V_17 . V_38 == V_17 -> V_17 . V_44 )
* V_180 = 1 ;
else
* V_180 = 0 ;
if ( ( * V_180 ) == 0 )
F_22 ( L_12 ) ;
V_181 = ( ( * V_38 << V_193 ) | V_194 ) ;
if ( * V_180 && ! V_17 -> V_17 . V_195 )
V_181 |= V_196 ;
V_182 -> V_185 = F_10 ( V_181 ) ;
F_65 () ;
F_22 ( L_13 , * V_38 , ( int ) * V_37 ) ;
return V_182 ;
}
static int F_66 ( struct V_16 * V_17 )
{
unsigned V_197 ;
int V_180 ;
int V_198 = 1 ;
struct V_22 * V_199 = NULL , * V_182 ;
T_4 V_37 ;
do {
V_182 = F_62 ( V_17 , & V_197 , & V_37 , & V_180 ) ;
if ( V_182 == NULL )
return - V_200 ;
if ( V_198 ) {
V_198 = 0 ;
V_17 -> V_28 = V_182 ;
} else {
V_199 -> V_171 = F_10 ( V_37 ) ;
V_199 -> V_30 = V_182 ;
}
V_199 = V_182 ;
V_17 -> V_29 ++ ;
} while ( ! V_180 );
V_182 -> V_171 = F_10 ( V_201 ) ;
V_17 -> V_170 = V_182 ;
return 0 ;
}
static int
F_67 ( struct V_142 * V_143 , struct V_161 * V_163 , T_3 V_162 )
{
struct V_14 * V_15 = F_49 ( V_143 , struct V_14 , V_15 ) ;
struct V_16 * V_17 = F_49 ( V_163 , struct V_16 , V_17 ) ;
struct V_19 * V_20 ;
unsigned long V_148 ;
if ( ! V_163 || ! V_17 -> V_17 . V_46 || ! V_17 -> V_17 . V_202
|| ! F_27 ( & V_17 -> V_26 ) ) {
F_22 ( L_14 , V_108 ) ;
return - V_67 ;
}
if ( F_68 ( ! V_143 || ! V_15 -> V_145 ) ) {
F_22 ( L_15 , V_108 ) ;
return - V_67 ;
}
if ( V_15 -> V_145 -> V_155 == V_131 ) {
if ( V_17 -> V_17 . V_38 > V_15 -> V_15 . V_157 )
return - V_203 ;
}
V_20 = V_15 -> V_20 ;
if ( ! V_20 -> V_151 || V_20 -> V_34 . V_152 == V_153 )
return - V_42 ;
V_17 -> V_15 = V_15 ;
if ( V_17 -> V_17 . V_37 == V_41 ) {
V_17 -> V_17 . V_37 = F_69 ( V_15 -> V_20 -> V_34 . V_35 . V_36 ,
V_17 -> V_17 . V_202 ,
V_17 -> V_17 . V_38 , F_20 ( V_15 )
? V_39
: V_40 ) ;
V_17 -> V_33 = 1 ;
} else {
F_70 ( V_15 -> V_20 -> V_34 . V_35 . V_36 ,
V_17 -> V_17 . V_37 , V_17 -> V_17 . V_38 ,
F_20 ( V_15 )
? V_39
: V_40 ) ;
V_17 -> V_33 = 0 ;
}
V_17 -> V_17 . V_18 = - V_27 ;
V_17 -> V_17 . V_44 = 0 ;
V_17 -> V_29 = 0 ;
F_51 ( & V_20 -> V_45 , V_148 ) ;
if ( ! F_66 ( V_17 ) ) {
F_60 ( V_15 , V_17 ) ;
} else {
F_53 ( & V_20 -> V_45 , V_148 ) ;
return - V_200 ;
}
if ( ( F_52 ( V_15 ) == 0 ) )
V_20 -> V_204 = V_205 ;
if ( V_17 != NULL )
F_71 ( & V_17 -> V_26 , & V_15 -> V_26 ) ;
F_53 ( & V_20 -> V_45 , V_148 ) ;
return 0 ;
}
static int F_72 ( struct V_142 * V_143 , struct V_161 * V_163 )
{
struct V_14 * V_15 = F_49 ( V_143 , struct V_14 , V_15 ) ;
struct V_16 * V_17 ;
unsigned long V_148 ;
int V_50 , V_21 , V_206 = 0 ;
T_1 V_122 ;
if ( ! V_143 || ! V_163 )
return - V_67 ;
F_51 ( & V_15 -> V_20 -> V_45 , V_148 ) ;
V_21 = V_15 -> V_21 ;
V_15 -> V_21 = 1 ;
V_50 = F_52 ( V_15 ) ;
V_122 = F_32 ( & V_54 -> V_85 [ V_50 ] ) ;
if ( F_20 ( V_15 ) )
V_122 &= ~ V_116 ;
else
V_122 &= ~ V_118 ;
F_33 ( V_122 , & V_54 -> V_85 [ V_50 ] ) ;
F_73 (req, &ep->queue, queue) {
if ( & V_17 -> V_17 == V_163 )
break;
}
if ( & V_17 -> V_17 != V_163 ) {
V_206 = - V_67 ;
goto V_174;
}
if ( V_15 -> V_26 . V_47 == & V_17 -> V_26 ) {
V_163 -> V_18 = - V_207 ;
F_26 ( V_143 ) ;
if ( V_17 -> V_26 . V_47 != & V_15 -> V_26 ) {
struct V_126 * V_208 ;
struct V_16 * V_209 ;
V_208 = V_15 -> V_208 ;
V_209 = F_28 ( V_17 -> V_26 . V_47 , struct V_16 ,
V_26 ) ;
F_33 ( ( T_1 ) V_209 -> V_28 , & V_208 -> V_210 ) ;
}
} else {
struct V_16 * V_211 ;
V_211 = F_28 ( V_17 -> V_26 . V_169 , struct V_16 , V_26 ) ;
F_33 ( F_32 ( & V_17 -> V_170 -> V_171 ) ,
& V_211 -> V_170 -> V_171 ) ;
}
F_16 ( V_15 , V_17 , - V_207 ) ;
V_174: V_122 = F_32 ( & V_54 -> V_85 [ V_50 ] ) ;
if ( F_20 ( V_15 ) )
V_122 |= V_116 ;
else
V_122 |= V_118 ;
F_33 ( V_122 , & V_54 -> V_85 [ V_50 ] ) ;
V_15 -> V_21 = V_21 ;
F_53 ( & V_15 -> V_20 -> V_45 , V_148 ) ;
return V_206 ;
}
static int F_74 ( struct V_142 * V_143 , int V_119 )
{
struct V_14 * V_15 = NULL ;
unsigned long V_148 = 0 ;
int V_18 = - V_212 ;
unsigned char V_213 = 0 , V_50 = 0 ;
struct V_19 * V_20 = NULL ;
V_15 = F_49 ( V_143 , struct V_14 , V_15 ) ;
V_20 = V_15 -> V_20 ;
if ( ! V_143 || ! V_15 -> V_145 ) {
V_18 = - V_67 ;
goto V_174;
}
if ( V_15 -> V_145 -> V_155 == V_131 ) {
V_18 = - V_212 ;
goto V_174;
}
if ( V_119 && F_20 ( V_15 ) && ! F_27 ( & V_15 -> V_26 ) ) {
V_18 = - V_214 ;
goto V_174;
}
V_18 = 0 ;
V_213 = F_20 ( V_15 ) ? V_141 : V_139 ;
V_50 = ( unsigned char ) ( F_52 ( V_15 ) ) ;
F_51 ( & V_15 -> V_20 -> V_45 , V_148 ) ;
F_44 ( V_50 , V_213 , V_119 ) ;
F_53 ( & V_15 -> V_20 -> V_45 , V_148 ) ;
if ( F_52 ( V_15 ) == 0 ) {
V_20 -> V_204 = V_215 ;
V_20 -> V_216 = 0 ;
}
V_174:
F_22 ( L_16 , V_15 -> V_15 . V_43 ,
V_119 ? L_17 : L_18 , V_18 ) ;
return V_18 ;
}
static int F_75 ( struct V_142 * V_143 )
{
struct V_14 * V_15 ;
struct V_19 * V_20 ;
int V_217 = 0 ;
T_1 V_165 ;
struct V_126 * V_218 ;
V_15 = F_49 ( V_143 , struct V_14 , V_15 ) ;
if ( ! V_143 || ( ! V_15 -> V_145 && F_52 ( V_15 ) != 0 ) )
return - V_219 ;
V_20 = (struct V_19 * ) V_15 -> V_20 ;
if ( ! V_20 -> V_151 || V_20 -> V_34 . V_152 == V_153 )
return - V_42 ;
V_218 = & V_15 -> V_20 -> V_83 [ F_52 ( V_15 ) * 2 + F_20 ( V_15 ) ] ;
V_165 = ( F_20 ( V_15 ) ) ? ( 1 << ( F_52 ( V_15 ) + 16 ) ) :
( 1 << ( F_52 ( V_15 ) ) ) ;
if ( F_32 ( & V_54 -> V_176 ) & V_165 )
V_217 = ( V_218 -> V_138 & V_220 )
>> V_193 ;
F_42 ( L_19 , V_108 , V_217 ) ;
return V_217 ;
}
static void F_26 ( struct V_142 * V_143 )
{
struct V_14 * V_15 ;
int V_50 , V_213 ;
T_1 V_221 ;
unsigned long V_53 ;
#define F_76 1000
if ( ! V_143 ) {
return;
} else {
V_15 = F_49 ( V_143 , struct V_14 , V_15 ) ;
if ( ! V_15 -> V_145 )
return;
}
V_50 = F_52 ( V_15 ) ;
V_213 = F_20 ( V_15 ) ? V_141 : V_139 ;
if ( V_50 == 0 )
V_221 = ( 1 << 16 ) | 1 ;
else if ( V_213 == V_141 )
V_221 = 1 << ( 16 + V_50 ) ;
else
V_221 = 1 << V_50 ;
V_53 = V_71 + F_76 ;
do {
F_33 ( V_221 , & V_54 -> V_222 ) ;
while ( F_32 ( & V_54 -> V_222 ) ) {
if ( F_34 ( V_71 , V_53 ) ) {
F_35 ( L_20 ) ;
return;
}
F_36 () ;
}
} while ( F_32 ( & V_54 -> V_176 ) & V_221 );
}
static int F_77 ( struct V_223 * V_34 )
{
return ( int ) ( F_32 ( & V_54 -> V_224 ) & V_225 ) ;
}
static int F_78 ( struct V_223 * V_34 )
{
struct V_19 * V_20 = F_49 ( V_34 , struct V_19 , V_34 ) ;
T_1 V_226 ;
if ( ! V_20 -> V_227 )
return - V_228 ;
V_226 = F_32 ( & V_54 -> V_55 ) ;
if ( ! ( V_226 & V_229 ) )
return 0 ;
V_226 |= V_230 ;
F_33 ( V_226 , & V_54 -> V_55 ) ;
return 0 ;
}
static int F_79 ( struct V_19 * V_20 )
{
return V_20 -> V_151 && V_20 -> V_231 && V_20 -> V_232 ;
}
static int F_80 ( struct V_223 * V_34 , int V_233 )
{
struct V_19 * V_20 ;
unsigned long V_148 ;
V_20 = F_49 ( V_34 , struct V_19 , V_34 ) ;
F_51 ( & V_20 -> V_45 , V_148 ) ;
F_22 ( L_21 , V_233 ? L_22 : L_23 ) ;
V_20 -> V_232 = ( V_233 != 0 ) ;
if ( F_79 ( V_20 ) )
F_33 ( ( F_32 ( & V_54 -> V_68 ) | V_69 ) ,
& V_54 -> V_68 ) ;
else
F_33 ( ( F_32 ( & V_54 -> V_68 ) & ~ V_69 ) ,
& V_54 -> V_68 ) ;
F_53 ( & V_20 -> V_45 , V_148 ) ;
return 0 ;
}
static int F_81 ( struct V_223 * V_34 , unsigned V_234 )
{
struct V_19 * V_20 ;
V_20 = F_49 ( V_34 , struct V_19 , V_34 ) ;
if ( V_20 -> V_235 )
return F_82 ( V_20 -> V_235 , V_234 ) ;
return - V_228 ;
}
static int F_83 ( struct V_223 * V_34 , int V_236 )
{
struct V_19 * V_20 ;
V_20 = F_49 ( V_34 , struct V_19 , V_34 ) ;
V_20 -> V_231 = ( V_236 != 0 ) ;
if ( F_79 ( V_20 ) )
F_33 ( ( F_32 ( & V_54 -> V_68 ) | V_69 ) ,
& V_54 -> V_68 ) ;
else
F_33 ( ( F_32 ( & V_54 -> V_68 ) & ~ V_69 ) ,
& V_54 -> V_68 ) ;
return 0 ;
}
static void F_84 ( struct V_19 * V_20 )
{
T_1 V_48 ;
V_48 = F_32 ( & V_54 -> V_85 [ 0 ] ) ;
V_48 |= V_120 | V_121 ;
F_33 ( V_48 , & V_54 -> V_85 [ 0 ] ) ;
V_20 -> V_204 = V_215 ;
V_20 -> V_216 = 0 ;
}
static int F_85 ( struct V_19 * V_20 , int V_237 )
{
struct V_16 * V_17 = V_20 -> V_238 ;
struct V_14 * V_15 ;
if ( V_237 == V_239 )
V_20 -> V_216 = V_159 ;
else
V_20 -> V_216 = V_240 ;
V_15 = & V_20 -> V_241 [ 0 ] ;
V_20 -> V_204 = V_242 ;
V_17 -> V_15 = V_15 ;
V_17 -> V_17 . V_38 = 0 ;
V_17 -> V_17 . V_18 = - V_27 ;
V_17 -> V_17 . V_44 = 0 ;
V_17 -> V_17 . V_46 = NULL ;
V_17 -> V_29 = 0 ;
V_17 -> V_17 . V_37 = F_69 ( V_15 -> V_20 -> V_34 . V_35 . V_36 ,
V_17 -> V_17 . V_202 , V_17 -> V_17 . V_38 ,
F_20 ( V_15 ) ? V_39 : V_40 ) ;
V_17 -> V_33 = 1 ;
if ( F_66 ( V_17 ) == 0 )
F_60 ( V_15 , V_17 ) ;
else
return - V_200 ;
F_71 ( & V_17 -> V_26 , & V_15 -> V_26 ) ;
return 0 ;
}
static void F_86 ( struct V_19 * V_20 , T_5 V_243 )
{
struct V_14 * V_15 = F_87 ( V_20 , V_243 ) ;
if ( V_15 -> V_43 )
F_25 ( V_15 , - V_42 ) ;
}
static void F_88 ( struct V_19 * V_20 , T_6 V_119 , T_6 V_244 , T_6 V_38 )
{
V_20 -> V_245 = ( T_5 ) V_119 ;
V_20 -> V_246 = V_247 ;
if ( F_85 ( V_20 , V_239 ) )
F_84 ( V_20 ) ;
}
static void F_89 ( struct V_19 * V_20 , T_5 V_248 , T_6 V_119 ,
T_6 V_244 , T_6 V_38 )
{
T_6 V_48 = 0 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
V_15 = & V_20 -> V_241 [ 0 ] ;
if ( ( V_248 & V_249 ) == V_250 ) {
V_48 = 1 << V_251 ;
V_48 |= V_20 -> V_227 << V_252 ;
} else if ( ( V_248 & V_249 ) == V_253 ) {
V_48 = 0 ;
} else if ( ( V_248 & V_249 ) == V_254 ) {
struct V_14 * V_255 ;
V_255 = F_87 ( V_20 , F_90 ( V_244 ) ) ;
if ( ! V_255 -> V_145 )
goto V_256;
V_48 = F_45 ( F_52 ( V_255 ) , F_20 ( V_255 ) )
<< V_257 ;
}
V_20 -> V_216 = V_159 ;
V_17 = V_20 -> V_238 ;
* ( ( T_6 * ) V_17 -> V_17 . V_202 ) = F_91 ( V_48 ) ;
V_17 -> V_15 = V_15 ;
V_17 -> V_17 . V_38 = 2 ;
V_17 -> V_17 . V_18 = - V_27 ;
V_17 -> V_17 . V_44 = 0 ;
V_17 -> V_17 . V_46 = NULL ;
V_17 -> V_29 = 0 ;
V_17 -> V_17 . V_37 = F_69 ( V_15 -> V_20 -> V_34 . V_35 . V_36 ,
V_17 -> V_17 . V_202 , V_17 -> V_17 . V_38 ,
F_20 ( V_15 ) ? V_39 : V_40 ) ;
V_17 -> V_33 = 1 ;
if ( ( F_66 ( V_17 ) == 0 ) )
F_60 ( V_15 , V_17 ) ;
else
goto V_256;
F_71 ( & V_17 -> V_26 , & V_15 -> V_26 ) ;
V_20 -> V_204 = V_205 ;
return;
V_256:
F_84 ( V_20 ) ;
}
static void F_92 ( struct V_19 * V_20 ,
struct V_258 * V_259 )
{
T_6 V_260 = F_50 ( V_259 -> V_260 ) ;
T_6 V_261 = F_50 ( V_259 -> V_261 ) ;
T_6 V_262 = F_50 ( V_259 -> V_262 ) ;
F_86 ( V_20 , 0 ) ;
switch ( V_259 -> V_263 ) {
case V_264 :
if ( ( V_259 -> V_265 & ( V_159 | V_266 ) )
!= ( V_159 | V_267 ) )
break;
F_89 ( V_20 , V_259 -> V_265 , V_260 , V_261 , V_262 ) ;
return;
case V_268 :
if ( V_259 -> V_265 != ( V_240 | V_267
| V_250 ) )
break;
F_88 ( V_20 , V_260 , V_261 , V_262 ) ;
return;
case V_269 :
case V_270 :
{
int V_271 = - V_212 ;
T_6 V_272 = 0 ;
if ( ( V_259 -> V_265 & ( V_249 | V_266 ) )
== ( V_254 | V_267 ) ) {
int V_243 = F_90 ( V_261 ) ;
struct V_14 * V_15 ;
if ( V_260 != 0 || V_262 != 0 || V_243 > V_20 -> V_273 )
break;
V_15 = F_87 ( V_20 , V_243 ) ;
F_23 ( & V_20 -> V_45 ) ;
V_271 = F_74 ( & V_15 -> V_15 ,
( V_259 -> V_263 == V_270 )
? 1 : 0 ) ;
F_24 ( & V_20 -> V_45 ) ;
} else if ( ( V_259 -> V_265 & ( V_249
| V_266 ) ) == ( V_250
| V_267 ) ) {
if ( V_260 == V_274 )
V_272 = V_261 >> 8 ;
else if ( F_93 ( & V_20 -> V_34 ) ) {
if ( V_259 -> V_263 ==
V_275 )
V_20 -> V_34 . V_276 = 1 ;
else if ( V_259 -> V_263 ==
V_277 )
V_20 -> V_34 . V_278 = 1 ;
else if ( V_259 -> V_263 ==
V_279 )
V_20 -> V_34 . V_280 = 1 ;
}
V_271 = 0 ;
} else
break;
if ( V_271 == 0 ) {
if ( F_85 ( V_20 , V_239 ) )
F_84 ( V_20 ) ;
}
if ( V_272 ) {
T_1 V_48 ;
F_94 ( 10 ) ;
V_48 = F_32 ( & V_54 -> V_55 ) | ( V_272 << 16 ) ;
F_33 ( V_48 , & V_54 -> V_55 ) ;
F_95 ( V_281 L_24 , V_272 ) ;
}
return;
}
default:
break;
}
if ( V_262 ) {
V_20 -> V_216 = ( V_259 -> V_265 & V_159 )
? V_159 : V_240 ;
F_23 ( & V_20 -> V_45 ) ;
if ( V_20 -> V_151 -> V_259 ( & V_20 -> V_34 ,
& V_20 -> V_282 ) < 0 )
F_84 ( V_20 ) ;
F_24 ( & V_20 -> V_45 ) ;
V_20 -> V_204 = ( V_259 -> V_265 & V_159 )
? V_205 : V_283 ;
} else {
V_20 -> V_216 = V_159 ;
F_23 ( & V_20 -> V_45 ) ;
if ( V_20 -> V_151 -> V_259 ( & V_20 -> V_34 ,
& V_20 -> V_282 ) < 0 )
F_84 ( V_20 ) ;
F_24 ( & V_20 -> V_45 ) ;
V_20 -> V_204 = V_242 ;
}
}
static void F_96 ( struct V_19 * V_20 , struct V_14 * V_284 ,
struct V_16 * V_17 )
{
if ( V_20 -> V_246 == V_247 ) {
T_1 V_285 = ( T_1 ) V_20 -> V_245 ;
F_33 ( V_285 << V_286 ,
& V_54 -> V_287 ) ;
}
F_16 ( V_284 , V_17 , 0 ) ;
switch ( V_20 -> V_204 ) {
case V_205 :
if ( F_85 ( V_20 , V_288 ) )
F_84 ( V_20 ) ;
break;
case V_283 :
if ( F_85 ( V_20 , V_239 ) )
F_84 ( V_20 ) ;
break;
case V_242 :
V_20 -> V_204 = V_215 ;
break;
case V_215 :
F_35 ( L_25 ) ;
break;
default:
F_84 ( V_20 ) ;
break;
}
}
static void F_97 ( struct V_19 * V_20 , T_5 V_50 , T_5 * V_289 )
{
T_1 V_100 ;
struct V_126 * V_208 ;
struct V_3 * V_4 = V_20 -> V_4 ;
V_208 = & V_20 -> V_83 [ V_50 * 2 + V_288 ] ;
V_100 = F_32 ( & V_54 -> V_290 ) ;
F_33 ( V_100 | ( 1 << V_50 ) , & V_54 -> V_290 ) ;
do {
V_100 = F_32 ( & V_54 -> V_68 ) ;
F_33 ( V_100 | V_291 , & V_54 -> V_68 ) ;
if ( V_4 -> V_292 ) {
T_1 * V_1 = ( T_1 * ) V_289 ;
T_1 * V_293 = ( T_1 * ) V_208 -> V_294 ;
* V_1 ++ = F_15 ( * V_293 ++ ) ;
* V_1 = F_15 ( * V_293 ) ;
} else {
memcpy ( V_289 , ( T_5 * ) V_208 -> V_294 , 8 ) ;
}
} while ( ! ( F_32 ( & V_54 -> V_68 ) & V_291 ) );
V_100 = F_32 ( & V_54 -> V_68 ) ;
F_33 ( V_100 & ~ V_291 , & V_54 -> V_68 ) ;
}
static int F_98 ( struct V_19 * V_20 , int V_243 ,
struct V_16 * V_295 )
{
struct V_22 * V_23 ;
int V_296 , V_44 , V_297 , V_25 , V_48 ;
int V_18 = 0 ;
int V_298 = 0 ;
struct V_126 * V_299 = & V_20 -> V_83 [ V_243 ] ;
int V_237 = V_243 % 2 ;
V_23 = V_295 -> V_28 ;
V_296 = 0 ;
V_44 = V_295 -> V_17 . V_38 ;
for ( V_25 = 0 ; V_25 < V_295 -> V_29 ; V_25 ++ ) {
V_297 = ( F_13 ( V_23 -> V_185 )
& V_220 )
>> V_193 ;
V_44 -= V_297 ;
V_298 = F_13 ( V_23 -> V_185 ) ;
if ( V_298 & V_300 ) {
if ( V_298 & V_301 ) {
F_35 ( L_26 , V_298 , V_243 ) ;
V_48 = F_13 ( V_299 -> V_138 ) ;
V_48 &= ~ V_298 ;
V_299 -> V_138 = F_10 ( V_48 ) ;
V_18 = - V_302 ;
break;
}
if ( V_298 & V_303 ) {
F_22 ( L_27 ) ;
V_18 = - V_304 ;
break;
} else if ( V_298 & V_305 ) {
F_22 ( L_28 ) ;
V_18 = - V_306 ;
break;
} else
F_35 ( L_29 ,
V_298 ) ;
} else if ( F_13 ( V_23 -> V_185 )
& V_194 ) {
F_22 ( L_30 ) ;
V_18 = V_307 ;
return V_18 ;
} else if ( V_297 ) {
if ( V_237 ) {
F_22 ( L_31 ) ;
V_18 = - V_304 ;
break;
} else {
V_296 ++ ;
break;
}
} else {
V_296 ++ ;
F_22 ( L_32 ) ;
}
if ( V_25 != V_295 -> V_29 - 1 )
V_23 = (struct V_22 * ) V_23 -> V_30 ;
}
if ( V_18 )
return V_18 ;
V_295 -> V_17 . V_44 = V_44 ;
return 0 ;
}
static void F_99 ( struct V_19 * V_20 )
{
T_1 V_308 ;
int V_164 , V_50 , V_237 , V_309 , V_18 ;
struct V_14 * V_310 ;
struct V_16 * V_295 , * V_311 ;
V_308 = F_32 ( & V_54 -> V_312 ) ;
F_33 ( V_308 , & V_54 -> V_312 ) ;
if ( ! V_308 )
return;
for ( V_164 = 0 ; V_164 < V_20 -> V_273 * 2 ; V_164 ++ ) {
V_50 = V_164 >> 1 ;
V_237 = V_164 % 2 ;
V_309 = 1 << ( V_50 + 16 * V_237 ) ;
if ( ! ( V_308 & V_309 ) )
continue;
V_310 = F_87 ( V_20 , V_164 ) ;
if ( V_310 -> V_43 == NULL ) {
F_100 ( L_33 ) ;
continue;
}
F_101 (curr_req, temp_req, &curr_ep->queue,
queue) {
V_18 = F_98 ( V_20 , V_164 , V_295 ) ;
F_22 ( L_34 ,
V_18 , V_50 ) ;
if ( V_18 == V_307 )
break;
V_295 -> V_17 . V_18 = V_18 ;
if ( V_50 == 0 ) {
F_96 ( V_20 , V_310 , V_295 ) ;
break;
} else
F_16 ( V_310 , V_295 , V_18 ) ;
}
}
}
static void F_102 ( struct V_19 * V_20 )
{
T_1 V_152 ;
if ( V_20 -> V_313 )
V_20 -> V_313 = 0 ;
if ( ! ( F_32 ( & V_54 -> V_55 ) & V_314 ) ) {
V_152 = ( F_32 ( & V_54 -> V_55 )
& V_315 ) ;
switch ( V_152 ) {
case V_316 :
V_20 -> V_34 . V_152 = V_317 ;
break;
case V_318 :
V_20 -> V_34 . V_152 = V_319 ;
break;
case V_320 :
V_20 -> V_34 . V_152 = V_321 ;
break;
default:
V_20 -> V_34 . V_152 = V_153 ;
break;
}
}
if ( ! V_20 -> V_322 )
V_20 -> V_246 = V_323 ;
}
static void F_103 ( struct V_19 * V_20 )
{
V_20 -> V_322 = V_20 -> V_246 ;
V_20 -> V_246 = V_324 ;
if ( V_20 -> V_151 -> V_325 )
V_20 -> V_151 -> V_325 ( & V_20 -> V_34 ) ;
}
static void F_104 ( struct V_19 * V_20 )
{
V_20 -> V_246 = V_20 -> V_322 ;
V_20 -> V_322 = 0 ;
if ( V_20 -> V_151 -> V_326 )
V_20 -> V_151 -> V_326 ( & V_20 -> V_34 ) ;
}
static int F_105 ( struct V_19 * V_20 )
{
T_5 V_243 ;
for ( V_243 = 0 ; V_243 < V_20 -> V_327 ; V_243 ++ )
F_86 ( V_20 , V_243 ) ;
F_23 ( & V_20 -> V_45 ) ;
V_20 -> V_151 -> V_328 ( & V_20 -> V_34 ) ;
F_24 ( & V_20 -> V_45 ) ;
return 0 ;
}
static void F_106 ( struct V_19 * V_20 )
{
T_1 V_100 ;
unsigned long V_53 ;
V_100 = F_32 ( & V_54 -> V_287 ) ;
F_33 ( V_100 & ~ V_329 , & V_54 -> V_287 ) ;
V_20 -> V_245 = 0 ;
V_20 -> V_322 = 0 ;
V_20 -> V_216 = 0 ;
V_20 -> V_204 = V_215 ;
V_20 -> V_227 = 0 ;
V_20 -> V_34 . V_276 = 0 ;
V_20 -> V_34 . V_278 = 0 ;
V_20 -> V_34 . V_280 = 0 ;
V_100 = F_32 ( & V_54 -> V_290 ) ;
F_33 ( V_100 , & V_54 -> V_290 ) ;
V_100 = F_32 ( & V_54 -> V_312 ) ;
F_33 ( V_100 , & V_54 -> V_312 ) ;
V_53 = V_71 + 100 ;
while ( F_32 ( & V_54 -> V_173 ) ) {
if ( F_34 ( V_71 , V_53 ) ) {
F_35 ( L_35 ) ;
break;
}
F_36 () ;
}
F_33 ( 0xffffffff , & V_54 -> V_222 ) ;
if ( F_32 ( & V_54 -> V_55 ) & V_314 ) {
F_22 ( L_36 ) ;
V_20 -> V_313 = 1 ;
F_105 ( V_20 ) ;
V_20 -> V_246 = V_323 ;
} else {
F_22 ( L_37 ) ;
F_29 ( V_20 ) ;
F_105 ( V_20 ) ;
F_47 ( V_20 ) ;
F_40 ( V_20 ) ;
V_20 -> V_246 = V_330 ;
}
}
static T_7 F_107 ( int V_331 , void * V_332 )
{
struct V_19 * V_20 = V_332 ;
T_1 V_333 ;
T_7 V_18 = V_334 ;
unsigned long V_148 ;
if ( V_20 -> V_21 )
return V_334 ;
F_51 ( & V_20 -> V_45 , V_148 ) ;
V_333 = F_32 ( & V_54 -> V_79 ) & F_32 ( & V_54 -> V_107 ) ;
F_33 ( V_333 , & V_54 -> V_79 ) ;
if ( V_20 -> V_246 == V_324 )
if ( ( F_32 ( & V_54 -> V_55 ) & V_229 ) == 0 )
F_104 ( V_20 ) ;
if ( V_333 & V_335 ) {
F_22 ( L_38 ) ;
if ( F_32 ( & V_54 -> V_290 ) & V_336 ) {
F_97 ( V_20 , 0 ,
( T_5 * ) ( & V_20 -> V_282 ) ) ;
F_92 ( V_20 , & V_20 -> V_282 ) ;
V_18 = V_337 ;
}
if ( F_32 ( & V_54 -> V_312 ) ) {
F_99 ( V_20 ) ;
V_18 = V_337 ;
}
}
if ( V_333 & V_338 ) {
V_18 = V_337 ;
}
if ( V_333 & V_339 ) {
F_102 ( V_20 ) ;
V_18 = V_337 ;
}
if ( V_333 & V_340 ) {
F_22 ( L_39 ) ;
F_106 ( V_20 ) ;
V_18 = V_337 ;
}
if ( V_333 & V_341 ) {
F_103 ( V_20 ) ;
V_18 = V_337 ;
}
if ( V_333 & ( V_342 | V_343 ) ) {
F_22 ( L_40 , V_333 ) ;
}
F_53 ( & V_20 -> V_45 , V_148 ) ;
return V_18 ;
}
static int F_108 ( struct V_344 * V_151 ,
int (* F_109)( struct V_223 * ) )
{
int V_147 = - V_219 ;
unsigned long V_148 = 0 ;
if ( ! V_9 )
return - V_219 ;
if ( ! V_151 || ( V_151 -> V_152 != V_319
&& V_151 -> V_152 != V_317 )
|| ! F_109 || ! V_151 -> V_328 || ! V_151 -> V_259 )
return - V_67 ;
if ( V_9 -> V_151 )
return - V_345 ;
F_51 ( & V_9 -> V_45 , V_148 ) ;
V_151 -> V_151 . V_346 = NULL ;
V_9 -> V_151 = V_151 ;
V_9 -> V_34 . V_35 . V_151 = & V_151 -> V_151 ;
F_53 ( & V_9 -> V_45 , V_148 ) ;
V_147 = F_109 ( & V_9 -> V_34 ) ;
if ( V_147 ) {
F_22 ( L_41 , V_151 -> V_151 . V_43 , V_147 ) ;
V_9 -> V_34 . V_35 . V_151 = NULL ;
V_9 -> V_151 = NULL ;
goto V_174;
}
if ( V_9 -> V_235 ) {
V_9 -> V_21 = 1 ;
F_95 ( V_281 L_42 ) ;
if ( V_9 -> V_235 ) {
V_147 = F_110 ( V_9 -> V_235 ,
& V_9 -> V_34 ) ;
if ( V_147 < 0 ) {
F_35 ( L_43 ) ;
V_151 -> V_347 ( & V_9 -> V_34 ) ;
V_9 -> V_34 . V_35 . V_151 = 0 ;
V_9 -> V_151 = 0 ;
return V_147 ;
}
}
} else {
F_40 ( V_9 ) ;
V_9 -> V_246 = V_330 ;
V_9 -> V_204 = V_215 ;
V_9 -> V_216 = 0 ;
}
F_95 ( V_281 L_44 ,
V_9 -> V_34 . V_43 , V_151 -> V_151 . V_43 ) ;
V_174:
if ( V_147 )
F_95 ( V_348 L_45 ,
V_147 ) ;
return V_147 ;
}
static int F_111 ( struct V_344 * V_151 )
{
struct V_14 * V_349 ;
unsigned long V_148 ;
if ( ! V_9 )
return - V_219 ;
if ( ! V_151 || V_151 != V_9 -> V_151 || ! V_151 -> V_347 )
return - V_67 ;
if ( V_9 -> V_235 )
F_110 ( V_9 -> V_235 , NULL ) ;
F_41 ( V_9 ) ;
V_9 -> V_246 = V_330 ;
V_9 -> V_204 = V_215 ;
V_9 -> V_216 = 0 ;
F_51 ( & V_9 -> V_45 , V_148 ) ;
V_9 -> V_34 . V_152 = V_153 ;
F_25 ( & V_9 -> V_241 [ 0 ] , - V_42 ) ;
F_73 (loop_ep, &udc_controller->gadget.ep_list,
ep.ep_list)
F_25 ( V_349 , - V_42 ) ;
F_53 ( & V_9 -> V_45 , V_148 ) ;
V_151 -> V_328 ( & V_9 -> V_34 ) ;
V_151 -> V_347 ( & V_9 -> V_34 ) ;
V_9 -> V_34 . V_35 . V_151 = NULL ;
V_9 -> V_151 = NULL ;
F_95 ( V_348 L_46 ,
V_151 -> V_151 . V_43 ) ;
return 0 ;
}
static int F_112 ( char * V_350 , char * * V_351 , T_8 V_352 , int V_197 ,
int * V_353 , void * V_354 )
{
char * V_202 = V_350 ;
char * V_47 = V_202 ;
unsigned V_217 = V_197 ;
unsigned long V_148 ;
int V_355 , V_164 ;
T_1 V_356 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 ;
struct V_19 * V_20 = V_9 ;
if ( V_352 != 0 )
return 0 ;
F_51 ( & V_20 -> V_45 , V_148 ) ;
V_355 = F_113 ( V_47 , V_217 ,
V_357 L_47
L_48
L_49 ,
V_358 , V_359 ,
V_20 -> V_151 ? V_20 -> V_151 -> V_151 . V_43 : L_50 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_68 ) ;
V_355 = F_113 ( V_47 , V_217 ,
L_51
L_52
L_53 ,
( V_356 & V_291 ) ? 1 : 0 ,
( V_356 & V_69 ) ? L_54 : L_55 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_79 ) ;
V_355 = F_113 ( V_47 , V_217 ,
L_56
L_57
L_58 ,
( V_356 & V_341 ) ? 1 : 0 ,
( V_356 & V_340 ) ? 1 : 0 ,
( V_356 & V_343 ) ? L_59 : L_60 ,
( V_356 & V_342 ) ? L_61 : L_62 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_107 ) ;
V_355 = F_113 ( V_47 , V_217 ,
L_63
L_64
L_65
L_66
L_67
L_68 ,
( V_356 & V_105 ) ? 1 : 0 ,
( V_356 & V_360 ) ? 1 : 0 ,
( V_356 & V_104 ) ? 1 : 0 ,
( V_356 & V_106 ) ? 1 : 0 ,
( V_356 & V_103 ) ? 1 : 0 ,
( V_356 & V_102 ) ? 1 : 0 ,
( V_356 & V_101 ) ? 1 : 0 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_224 ) ;
V_355 = F_113 ( V_47 , V_217 ,
L_69 ,
( V_356 & V_225 ) ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_287 ) ;
V_355 = F_113 ( V_47 , V_217 ,
L_70 ,
( V_356 & V_329 ) ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_82 ) ;
V_355 = F_113 ( V_47 , V_217 ,
L_71
L_72 ,
( V_356 & V_81 ) ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_55 ) ;
V_355 = F_113 (next, size,
L_73
L_74
L_75
L_76
L_77
L_78
L_79
L_80 , ( {
char *s;
switch (tmp_reg & PORTSCX_PTS_FSLS) {
case PORTSCX_PTS_UTMI:
s = L_81; break;
case PORTSCX_PTS_ULPI:
s = L_82; break;
case PORTSCX_PTS_FSLS:
s = L_83; break;
default:
s = L_84; break;
}
s;} ), ( {
char *s;
switch (tmp_reg & PORTSCX_PORT_SPEED_UNDEF) {
case PORTSCX_PORT_SPEED_FULL:
s = L_85; break;
case PORTSCX_PORT_SPEED_LOW:
s = L_86; break;
case PORTSCX_PORT_SPEED_HIGH:
s = L_87; break;
default:
s = L_88; break;
}
s;
} ),
(tmp_reg & PORTSCX_PHY_LOW_POWER_SPD) ?
L_89 : L_90 ,
(tmp_reg & PORTSCX_PORT_RESET) ? L_91 :
L_92 ,
(tmp_reg & PORTSCX_PORT_SUSPEND) ? L_93 : L_94 ,
(tmp_reg & PORTSCX_OVER_CURRENT_CHG) ? L_95 :
L_96 ,
(tmp_reg & PORTSCX_PORT_EN_DIS_CHANGE) ? L_97 :
L_98 ,
(tmp_reg & PORTSCX_PORT_ENABLE) ? L_99 :
L_100 ,
(tmp_reg & PORTSCX_CURRENT_CONNECT_STATUS) ?
L_101 : L_102 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_73 ) ;
V_355 = F_113 (next, size,
L_103 , ( {
char *s;
switch (tmp_reg & USB_MODE_CTRL_MODE_HOST) {
case USB_MODE_CTRL_MODE_IDLE:
s = L_104; break;
case USB_MODE_CTRL_MODE_DEVICE:
s = L_105; break;
case USB_MODE_CTRL_MODE_HOST:
s = L_106; break;
default:
s = L_84; break;
}
s;
} )) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = F_32 ( & V_54 -> V_290 ) ;
V_355 = F_113 ( V_47 , V_217 ,
L_107 ,
( V_356 & V_361 ) ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
for ( V_164 = 0 ; V_164 < V_20 -> V_273 / 2 ; V_164 ++ ) {
V_356 = F_32 ( & V_54 -> V_85 [ V_164 ] ) ;
V_355 = F_113 ( V_47 , V_217 , L_108 ,
V_164 , V_356 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
}
V_356 = F_32 ( & V_54 -> V_173 ) ;
V_355 = F_113 ( V_47 , V_217 , L_109 , V_356 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
#ifndef F_30
if ( V_20 -> V_4 -> V_91 ) {
V_356 = V_92 -> V_98 ;
V_355 = F_113 ( V_47 , V_217 , L_110 , V_356 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
V_356 = V_92 -> V_93 ;
V_355 = F_113 ( V_47 , V_217 , L_111 ,
V_356 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
}
#endif
V_15 = & V_20 -> V_241 [ 0 ] ;
V_355 = F_113 ( V_47 , V_217 , L_112 ,
V_15 -> V_15 . V_43 , F_114 ( V_15 ) , F_52 ( V_15 ) ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
if ( F_27 ( & V_15 -> V_26 ) ) {
V_355 = F_113 ( V_47 , V_217 , L_113 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
} else {
F_73 (req, &ep->queue, queue) {
V_355 = F_113 ( V_47 , V_217 ,
L_114 ,
& V_17 -> V_17 , V_17 -> V_17 . V_44 ,
V_17 -> V_17 . V_38 , V_17 -> V_17 . V_202 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
}
}
F_73 (ep, &udc->gadget.ep_list, ep.ep_list) {
if ( V_15 -> V_145 ) {
V_355 = F_113 ( V_47 , V_217 ,
L_115
L_116 ,
V_15 -> V_15 . V_43 , F_114 ( V_15 ) ,
F_52 ( V_15 ) ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
if ( F_27 ( & V_15 -> V_26 ) ) {
V_355 = F_113 ( V_47 , V_217 ,
L_113 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
} else {
F_73 (req, &ep->queue, queue) {
V_355 = F_113 ( V_47 , V_217 ,
L_117
L_118 ,
& V_17 -> V_17 , V_17 -> V_17 . V_44 ,
V_17 -> V_17 . V_38 , V_17 -> V_17 . V_202 ) ;
V_217 -= V_355 ;
V_47 += V_355 ;
}
}
}
}
F_53 ( & V_20 -> V_45 , V_148 ) ;
* V_353 = 1 ;
return V_197 - V_217 ;
}
static void F_115 ( struct V_362 * V_35 )
{
V_46 ( V_9 -> F_16 ) ;
F_116 ( V_35 -> V_36 , V_9 -> V_363 ,
V_9 -> V_83 , V_9 -> V_80 ) ;
F_59 ( V_9 ) ;
}
static int T_9 F_117 ( struct V_19 * V_20 ,
struct V_364 * V_365 )
{
struct V_3 * V_4 ;
T_10 V_217 ;
V_4 = V_365 -> V_35 . V_366 ;
V_20 -> V_58 = V_4 -> V_58 ;
V_20 -> V_241 = F_56 ( sizeof( struct V_14 ) * V_20 -> V_273 , V_184 ) ;
if ( ! V_20 -> V_241 ) {
F_35 ( L_119 ) ;
return - 1 ;
}
V_217 = V_20 -> V_273 * sizeof( struct V_126 ) ;
if ( V_217 < V_367 )
V_217 = V_367 ;
else if ( ( V_217 % V_367 ) != 0 ) {
V_217 += V_367 + 1 ;
V_217 &= ~ ( V_367 - 1 ) ;
}
V_20 -> V_83 = F_118 ( & V_365 -> V_35 , V_217 ,
& V_20 -> V_80 , V_184 ) ;
if ( ! V_20 -> V_83 ) {
F_35 ( L_120 ) ;
F_59 ( V_20 -> V_241 ) ;
return - 1 ;
}
V_20 -> V_363 = V_217 ;
V_20 -> V_238 = F_49 ( F_55 ( NULL , V_184 ) ,
struct V_16 , V_17 ) ;
V_20 -> V_238 -> V_17 . V_202 = F_119 ( 8 , V_184 ) ;
V_20 -> V_322 = V_368 ;
V_20 -> V_246 = V_369 ;
V_20 -> V_216 = 0 ;
V_20 -> V_227 = 0 ;
return 0 ;
}
static int T_9 F_120 ( struct V_19 * V_20 , unsigned char V_244 ,
char * V_43 , int V_370 )
{
struct V_14 * V_15 = & V_20 -> V_241 [ V_244 ] ;
V_15 -> V_20 = V_20 ;
strcpy ( V_15 -> V_43 , V_43 ) ;
V_15 -> V_15 . V_43 = V_15 -> V_43 ;
V_15 -> V_15 . V_371 = & V_372 ;
V_15 -> V_21 = 0 ;
V_15 -> V_15 . V_157 = ( unsigned short ) ~ 0 ;
F_57 ( & V_15 -> V_26 ) ;
if ( V_370 )
F_71 ( & V_15 -> V_15 . V_373 , & V_20 -> V_34 . V_373 ) ;
V_15 -> V_34 = & V_20 -> V_34 ;
V_15 -> V_208 = & V_20 -> V_83 [ V_244 ] ;
return 0 ;
}
static int T_9 F_121 ( struct V_364 * V_365 )
{
struct V_3 * V_4 ;
struct V_374 * V_375 ;
int V_206 = - V_219 ;
unsigned int V_164 ;
T_1 V_84 ;
if ( strcmp ( V_365 -> V_43 , V_358 ) ) {
F_22 ( L_121 ) ;
return - V_219 ;
}
V_9 = F_56 ( sizeof( struct V_19 ) , V_184 ) ;
if ( V_9 == NULL ) {
F_35 ( L_122 ) ;
return - V_200 ;
}
V_4 = V_365 -> V_35 . V_366 ;
V_9 -> V_4 = V_4 ;
F_122 ( & V_9 -> V_45 ) ;
V_9 -> V_21 = 1 ;
#ifdef F_123
if ( V_4 -> V_376 == V_377 ) {
V_9 -> V_235 = F_124 () ;
if ( ! V_9 -> V_235 ) {
F_35 ( L_123 ) ;
V_206 = - V_219 ;
goto V_378;
}
}
#endif
V_375 = F_125 ( V_365 , V_379 , 0 ) ;
if ( ! V_375 ) {
V_206 = - V_380 ;
goto V_378;
}
if ( V_4 -> V_376 == V_381 ) {
if ( ! F_126 ( V_375 -> V_351 , F_127 ( V_375 ) ,
V_358 ) ) {
F_35 ( L_124 , V_365 -> V_43 ) ;
V_206 = - V_345 ;
goto V_378;
}
}
V_54 = F_128 ( V_375 -> V_351 , F_127 ( V_375 ) ) ;
if ( ! V_54 ) {
V_206 = - V_200 ;
goto V_382;
}
V_4 -> V_383 = ( void * ) V_54 ;
if ( V_4 -> V_384 && V_4 -> V_384 ( V_365 ) ) {
V_206 = - V_219 ;
goto V_385;
}
F_9 ( V_4 ) ;
#ifndef F_30
if ( V_4 -> V_91 )
V_92 = (struct V_386 * )
( ( T_1 ) V_54 + V_387 ) ;
#endif
V_206 = F_129 ( V_365 ) ;
if ( V_206 < 0 )
goto V_385;
V_84 = F_32 ( & V_54 -> V_84 ) ;
if ( ! ( V_84 & V_388 ) ) {
F_35 ( L_125 ) ;
V_206 = - V_219 ;
goto V_389;
}
V_9 -> V_273 = ( V_84 & V_390 ) * 2 ;
V_9 -> V_331 = F_130 ( V_365 , 0 ) ;
if ( ! V_9 -> V_331 ) {
V_206 = - V_219 ;
goto V_389;
}
V_206 = F_131 ( V_9 -> V_331 , F_107 , V_391 ,
V_358 , V_9 ) ;
if ( V_206 != 0 ) {
F_35 ( L_126 ,
V_9 -> V_331 , V_206 ) ;
goto V_389;
}
if ( F_117 ( V_9 , V_365 ) ) {
F_35 ( L_127 ) ;
V_206 = - V_200 ;
goto V_392;
}
if ( ! V_9 -> V_235 ) {
F_29 ( V_9 ) ;
}
F_132 ( V_365 ) ;
V_9 -> V_34 . V_371 = & V_393 ;
V_9 -> V_34 . V_394 = 1 ;
V_9 -> V_34 . V_284 = & V_9 -> V_241 [ 0 ] . V_15 ;
F_57 ( & V_9 -> V_34 . V_373 ) ;
V_9 -> V_34 . V_152 = V_153 ;
V_9 -> V_34 . V_43 = V_358 ;
F_133 ( & V_9 -> V_34 . V_35 , L_128 ) ;
V_9 -> V_34 . V_35 . V_395 = F_115 ;
V_9 -> V_34 . V_35 . V_36 = & V_365 -> V_35 ;
V_206 = F_134 ( & V_9 -> V_34 . V_35 ) ;
if ( V_206 < 0 )
goto V_392;
if ( V_9 -> V_235 )
V_9 -> V_34 . V_109 = 1 ;
F_47 ( V_9 ) ;
F_120 ( V_9 , 0 , L_129 , 0 ) ;
V_9 -> V_241 [ 0 ] . V_145 = & V_396 ;
V_9 -> V_241 [ 0 ] . V_15 . V_157 = V_140 ;
for ( V_164 = 1 ; V_164 < ( int ) ( V_9 -> V_273 / 2 ) ; V_164 ++ ) {
char V_43 [ 14 ] ;
sprintf ( V_43 , L_130 , V_164 ) ;
F_120 ( V_9 , V_164 * 2 , V_43 , 1 ) ;
sprintf ( V_43 , L_131 , V_164 ) ;
F_120 ( V_9 , V_164 * 2 + 1 , V_43 , 1 ) ;
}
V_9 -> V_31 = F_135 ( L_132 , & V_365 -> V_35 ,
sizeof( struct V_22 ) ,
V_397 , V_398 ) ;
if ( V_9 -> V_31 == NULL ) {
V_206 = - V_200 ;
goto V_399;
}
V_206 = F_136 ( & V_365 -> V_35 , & V_9 -> V_34 ) ;
if ( V_206 )
goto V_400;
F_137 () ;
return 0 ;
V_400:
F_138 ( V_9 -> V_31 ) ;
V_399:
F_139 ( & V_9 -> V_34 . V_35 ) ;
V_392:
F_140 ( V_9 -> V_331 , V_9 ) ;
V_389:
if ( V_4 -> exit )
V_4 -> exit ( V_365 ) ;
F_141 () ;
V_385:
F_142 ( V_54 ) ;
V_382:
if ( V_4 -> V_376 == V_381 )
F_143 ( V_375 -> V_351 , F_127 ( V_375 ) ) ;
V_378:
F_59 ( V_9 ) ;
V_9 = NULL ;
return V_206 ;
}
static int T_11 F_144 ( struct V_364 * V_365 )
{
struct V_374 * V_375 = F_125 ( V_365 , V_379 , 0 ) ;
struct V_3 * V_4 = V_365 -> V_35 . V_366 ;
F_145 ( F_16 ) ;
if ( ! V_9 )
return - V_219 ;
F_146 ( & V_9 -> V_34 ) ;
V_9 -> F_16 = & F_16 ;
F_141 () ;
F_147 () ;
F_59 ( V_9 -> V_238 -> V_17 . V_202 ) ;
F_59 ( V_9 -> V_238 ) ;
F_59 ( V_9 -> V_241 ) ;
F_138 ( V_9 -> V_31 ) ;
F_140 ( V_9 -> V_331 , V_9 ) ;
F_142 ( V_54 ) ;
if ( V_4 -> V_376 == V_381 )
F_143 ( V_375 -> V_351 , F_127 ( V_375 ) ) ;
F_139 ( & V_9 -> V_34 . V_35 ) ;
F_148 ( & F_16 ) ;
if ( V_4 -> exit )
V_4 -> exit ( V_365 ) ;
return 0 ;
}
static int F_149 ( struct V_364 * V_365 , T_12 V_401 )
{
F_41 ( V_9 ) ;
return 0 ;
}
static int F_150 ( struct V_364 * V_365 )
{
if ( V_9 -> V_21 ) {
F_29 ( V_9 ) ;
F_40 ( V_9 ) ;
}
V_9 -> V_246 = V_330 ;
V_9 -> V_204 = V_215 ;
V_9 -> V_216 = 0 ;
return 0 ;
}
static int F_151 ( struct V_362 * V_35 , T_12 V_401 )
{
struct V_19 * V_20 = V_9 ;
T_1 V_402 , V_68 ;
V_402 = F_32 ( & V_54 -> V_73 ) & V_74 ;
F_42 ( L_133 , V_108 , V_402 , V_20 -> V_21 ) ;
if ( V_20 -> V_21 ) {
F_42 ( L_134 ) ;
V_20 -> V_403 = 1 ;
return 0 ;
}
if ( V_402 != V_75 ) {
F_42 ( L_135 ) ;
return 0 ;
}
V_68 = F_32 ( & V_54 -> V_68 ) & ~ V_69 ;
F_33 ( V_68 , & V_54 -> V_68 ) ;
V_20 -> V_21 = 1 ;
F_152 ( L_136 ) ;
return 0 ;
}
static int F_153 ( struct V_362 * V_35 )
{
F_42 ( L_137 , V_108 ,
V_9 -> V_21 , V_9 -> V_403 ) ;
if ( V_9 -> V_403 ) {
V_9 -> V_403 = 0 ;
F_42 ( L_138 ) ;
return 0 ;
}
F_152 ( L_139 ) ;
return F_150 ( NULL ) ;
}
static int T_9 F_154 ( void )
{
F_95 ( V_281 L_140 , V_404 , V_359 ) ;
return F_155 ( & V_405 , F_121 ) ;
}
static void T_11 F_156 ( void )
{
F_157 ( & V_405 ) ;
F_95 ( V_348 L_141 , V_404 ) ;
}
