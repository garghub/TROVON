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
__releases( V_15 -> V_19 -> V_20 )
__acquires( V_15 -> V_19 -> V_20 )
{
struct V_21 * V_19 = NULL ;
unsigned char V_22 = V_15 -> V_22 ;
struct V_23 * V_24 , * V_25 ;
int V_26 ;
V_19 = (struct V_21 * ) V_15 -> V_19 ;
F_17 ( & V_17 -> V_27 ) ;
if ( V_17 -> V_17 . V_18 == - V_28 )
V_17 -> V_17 . V_18 = V_18 ;
else
V_18 = V_17 -> V_17 . V_18 ;
V_25 = V_17 -> V_29 ;
for ( V_26 = 0 ; V_26 < V_17 -> V_30 ; V_26 ++ ) {
V_24 = V_25 ;
if ( V_26 != V_17 -> V_30 - 1 ) {
V_25 = V_24 -> V_31 ;
}
F_18 ( V_19 -> V_32 , V_24 , V_24 -> V_33 ) ;
}
F_19 ( & V_15 -> V_19 -> V_34 , & V_17 -> V_17 , F_20 ( V_15 ) ) ;
if ( V_18 && ( V_18 != - V_35 ) )
F_21 ( L_1 ,
V_15 -> V_15 . V_36 , & V_17 -> V_17 , V_18 ,
V_17 -> V_17 . V_37 , V_17 -> V_17 . V_38 ) ;
V_15 -> V_22 = 1 ;
F_22 ( & V_15 -> V_19 -> V_20 ) ;
F_23 ( & V_15 -> V_15 , & V_17 -> V_17 ) ;
F_24 ( & V_15 -> V_19 -> V_20 ) ;
V_15 -> V_22 = V_22 ;
}
static void F_25 ( struct V_14 * V_15 , int V_18 )
{
V_15 -> V_22 = 1 ;
F_26 ( & V_15 -> V_15 ) ;
while ( ! F_27 ( & V_15 -> V_27 ) ) {
struct V_16 * V_17 = NULL ;
V_17 = F_28 ( V_15 -> V_27 . V_39 , struct V_16 , V_27 ) ;
F_16 ( V_15 , V_17 , V_18 ) ;
}
}
static int F_29 ( struct V_21 * V_19 )
{
unsigned int V_40 , V_41 , V_42 ;
unsigned int V_43 ;
unsigned int V_44 ;
unsigned long V_45 ;
#define F_30 1000
V_41 = F_31 ( & V_46 -> V_47 ) ;
V_41 &= ~ ( V_48 | V_49 ) ;
switch ( V_19 -> V_50 ) {
case V_51 :
if ( V_19 -> V_4 -> V_52 ) {
if ( V_19 -> V_4 -> V_53 ) {
V_44 = F_32 ( & V_54 -> V_55 ) ;
V_44 &= ~ V_56 ;
V_44 |= V_57 ;
F_33 ( V_44 , & V_54 -> V_55 ) ;
}
}
V_41 |= V_58 ;
break;
case V_59 :
V_41 |= V_60 ;
case V_61 :
if ( V_19 -> V_4 -> V_52 ) {
if ( V_19 -> V_4 -> V_53 ) {
V_44 = F_32 ( & V_54 -> V_55 ) ;
V_44 |= ( V_56 |
V_57 ) ;
F_33 ( V_44 , & V_54 -> V_55 ) ;
F_34 ( V_62 ) ;
}
}
V_41 |= V_63 ;
break;
case V_64 :
V_41 |= V_65 ;
break;
default:
return - V_66 ;
}
F_35 ( V_41 , & V_46 -> V_47 ) ;
V_40 = F_31 ( & V_46 -> V_67 ) ;
V_40 &= ~ V_68 ;
F_35 ( V_40 , & V_46 -> V_67 ) ;
V_40 = F_31 ( & V_46 -> V_67 ) ;
V_40 |= V_69 ;
F_35 ( V_40 , & V_46 -> V_67 ) ;
V_45 = V_70 + F_30 ;
while ( F_31 ( & V_46 -> V_67 ) & V_69 ) {
if ( F_36 ( V_70 , V_45 ) ) {
F_37 ( L_2 ) ;
return - V_71 ;
}
F_38 () ;
}
V_40 = F_31 ( & V_46 -> V_72 ) ;
V_40 &= ~ V_73 ;
V_40 |= V_74 ;
V_40 |= V_75 ;
if ( V_19 -> V_4 -> V_76 )
V_40 |= V_77 ;
F_35 ( V_40 , & V_46 -> V_72 ) ;
F_35 ( 0 , & V_46 -> V_78 ) ;
V_40 = V_19 -> V_79 ;
V_40 &= V_80 ;
F_35 ( V_40 , & V_46 -> V_81 ) ;
F_21 ( L_3 ,
V_19 -> V_82 , ( int ) V_40 ,
F_31 ( & V_46 -> V_81 ) ) ;
V_43 = ( 0x0000001F & F_31 ( & V_46 -> V_83 ) ) ;
for ( V_42 = 1 ; V_42 < V_43 ; V_42 ++ ) {
V_40 = F_31 ( & V_46 -> V_84 [ V_42 ] ) ;
V_40 &= ~ ( V_85 | V_86 ) ;
V_40 |= ( V_87 << V_88 )
| ( V_87 << V_89 ) ;
F_35 ( V_40 , & V_46 -> V_84 [ V_42 ] ) ;
}
#ifndef F_39
if ( V_19 -> V_4 -> V_52 ) {
V_44 = F_32 ( & V_54 -> V_55 ) ;
V_44 |= V_90 ;
F_33 ( V_44 , & V_54 -> V_55 ) ;
}
#endif
#if F_40 ( V_91 ) && ! F_40 ( V_92 )
if ( V_19 -> V_4 -> V_52 ) {
V_40 = V_93 ;
F_33 ( V_40 , & V_54 -> V_94 ) ;
V_40 |= 0x80000000 ;
F_33 ( V_40 , & V_54 -> V_95 ) ;
}
#endif
return 0 ;
}
static void F_41 ( struct V_21 * V_19 )
{
T_1 V_96 ;
V_96 = V_97 | V_98
| V_99 | V_100
| V_101 | V_102 ;
F_35 ( V_96 , & V_46 -> V_103 ) ;
V_19 -> V_22 = 0 ;
V_96 = F_31 ( & V_46 -> V_72 ) ;
V_96 |= V_74 ;
F_35 ( V_96 , & V_46 -> V_72 ) ;
V_96 = F_31 ( & V_46 -> V_67 ) ;
V_96 |= V_68 ;
F_35 ( V_96 , & V_46 -> V_67 ) ;
}
static void F_42 ( struct V_21 * V_19 )
{
unsigned int V_40 ;
F_43 ( L_4 , V_104 ) ;
if ( V_19 -> V_34 . V_105 ) {
if ( ! ( F_31 ( & V_46 -> V_106 ) & V_107 ) ) {
F_43 ( L_5 ) ;
return;
}
}
F_35 ( 0 , & V_46 -> V_103 ) ;
V_19 -> V_22 = 1 ;
V_40 = F_31 ( & V_46 -> V_67 ) ;
V_40 &= ~ V_68 ;
F_35 ( V_40 , & V_46 -> V_67 ) ;
}
static void F_44 ( unsigned char V_42 , unsigned char V_108 ,
unsigned char V_109 )
{
unsigned int V_110 = 0 ;
V_110 = F_31 ( & V_46 -> V_84 [ V_42 ] ) ;
if ( V_108 ) {
if ( V_42 )
V_110 |= V_111 ;
V_110 |= V_112 ;
V_110 &= ~ V_85 ;
V_110 |= ( ( unsigned int ) ( V_109 )
<< V_88 ) ;
} else {
if ( V_42 )
V_110 |= V_113 ;
V_110 |= V_114 ;
V_110 &= ~ V_86 ;
V_110 |= ( ( unsigned int ) ( V_109 )
<< V_89 ) ;
}
F_35 ( V_110 , & V_46 -> V_84 [ V_42 ] ) ;
}
static void
F_45 ( unsigned char V_42 , unsigned char V_108 , int V_115 )
{
T_1 V_110 = 0 ;
V_110 = F_31 ( & V_46 -> V_84 [ V_42 ] ) ;
if ( V_115 ) {
if ( V_108 )
V_110 |= V_116 ;
else
V_110 |= V_117 ;
} else {
if ( V_108 ) {
V_110 &= ~ V_116 ;
V_110 |= V_111 ;
} else {
V_110 &= ~ V_117 ;
V_110 |= V_113 ;
}
}
F_35 ( V_110 , & V_46 -> V_84 [ V_42 ] ) ;
}
static int F_46 ( unsigned char V_42 , unsigned char V_108 )
{
T_1 V_118 ;
V_118 = F_31 ( & V_46 -> V_84 [ V_42 ] ) ;
if ( V_108 )
return ( V_118 & V_116 ) ? 1 : 0 ;
else
return ( V_118 & V_117 ) ? 1 : 0 ;
}
static void F_47 ( struct V_21 * V_19 , unsigned char V_42 ,
unsigned char V_108 , unsigned char V_109 ,
unsigned int V_119 ,
unsigned int V_120 , unsigned char V_121 )
{
struct V_122 * V_123 = & V_19 -> V_82 [ 2 * V_42 + V_108 ] ;
unsigned int V_40 = 0 ;
switch ( V_109 ) {
case V_124 :
V_40 = ( V_119 << V_125 )
| V_126 ;
break;
case V_127 :
V_40 = ( V_119 << V_125 )
| ( V_121 << V_128 ) ;
break;
case V_129 :
case V_130 :
V_40 = V_119 << V_125 ;
break;
default:
F_21 ( L_6 , V_109 ) ;
return;
}
if ( V_120 )
V_40 |= V_131 ;
V_123 -> V_132 = F_10 ( V_40 ) ;
V_123 -> V_133 = 1 ;
V_123 -> V_134 = 0 ;
}
static void F_48 ( struct V_21 * V_19 )
{
F_47 ( V_19 , 0 , V_135 , V_124 ,
V_136 , 0 , 0 ) ;
F_47 ( V_19 , 0 , V_137 , V_124 ,
V_136 , 0 , 0 ) ;
F_44 ( 0 , V_135 , V_124 ) ;
F_44 ( 0 , V_137 , V_124 ) ;
return;
}
static int F_49 ( struct V_138 * V_139 ,
const struct V_140 * V_141 )
{
struct V_21 * V_19 = NULL ;
struct V_14 * V_15 = NULL ;
unsigned short V_142 = 0 ;
unsigned char V_121 = 0 , V_120 ;
int V_143 = - V_66 ;
unsigned long V_144 = 0 ;
V_15 = F_50 ( V_139 , struct V_14 , V_15 ) ;
if ( ! V_139 || ! V_141
|| ( V_141 -> V_145 != V_146 ) )
return - V_66 ;
V_19 = V_15 -> V_19 ;
if ( ! V_19 -> V_147 || ( V_19 -> V_34 . V_148 == V_149 ) )
return - V_35 ;
V_142 = F_51 ( V_141 ) ;
V_120 = 1 ;
switch ( V_141 -> V_150 & 0x03 ) {
case V_124 :
case V_129 :
case V_130 :
V_121 = 0 ;
break;
case V_127 :
V_121 = ( unsigned char ) ( 1 + ( ( V_142 >> 11 ) & 0x03 ) ) ;
V_142 = V_142 & 0x7ff ;
if ( V_121 > 3 )
goto V_151;
break;
default:
goto V_151;
}
F_52 ( & V_19 -> V_20 , V_144 ) ;
V_15 -> V_15 . V_152 = V_142 ;
V_15 -> V_15 . V_141 = V_141 ;
V_15 -> V_22 = 0 ;
F_47 ( V_19 , ( unsigned char ) F_53 ( V_15 ) ,
( unsigned char ) ( ( V_141 -> V_153 & V_154 )
? V_137 : V_135 ) ,
( unsigned char ) ( V_141 -> V_150
& V_155 ) ,
V_142 , V_120 , V_121 ) ;
F_44 ( ( unsigned char ) F_53 ( V_15 ) ,
( unsigned char ) ( ( V_141 -> V_153 & V_154 )
? V_137 : V_135 ) ,
( unsigned char ) ( V_141 -> V_150
& V_155 ) ) ;
F_54 ( & V_19 -> V_20 , V_144 ) ;
V_143 = 0 ;
F_21 ( L_7 , V_15 -> V_15 . V_36 ,
V_15 -> V_15 . V_141 -> V_153 & 0x0f ,
( V_141 -> V_153 & V_154 )
? L_8 : L_9 , V_142 ) ;
V_151:
return V_143 ;
}
static int F_55 ( struct V_138 * V_139 )
{
struct V_21 * V_19 = NULL ;
struct V_14 * V_15 = NULL ;
unsigned long V_144 = 0 ;
T_1 V_118 ;
int V_42 ;
V_15 = F_50 ( V_139 , struct V_14 , V_15 ) ;
if ( ! V_139 || ! V_15 -> V_15 . V_141 ) {
F_21 ( L_10 , V_139 ? V_15 -> V_15 . V_36 : NULL ) ;
return - V_66 ;
}
V_42 = F_53 ( V_15 ) ;
V_118 = F_31 ( & V_46 -> V_84 [ V_42 ] ) ;
if ( F_20 ( V_15 ) ) {
V_118 &= ~ ( V_112 | V_85 ) ;
V_118 |= V_87 << V_88 ;
} else {
V_118 &= ~ ( V_114 | V_85 ) ;
V_118 |= V_87 << V_89 ;
}
F_35 ( V_118 , & V_46 -> V_84 [ V_42 ] ) ;
V_19 = (struct V_21 * ) V_15 -> V_19 ;
F_52 ( & V_19 -> V_20 , V_144 ) ;
F_25 ( V_15 , - V_35 ) ;
V_15 -> V_15 . V_141 = NULL ;
V_15 -> V_22 = 1 ;
F_54 ( & V_19 -> V_20 , V_144 ) ;
F_21 ( L_11 , V_139 -> V_36 ) ;
return 0 ;
}
static struct V_156 *
F_56 ( struct V_138 * V_139 , T_3 V_157 )
{
struct V_16 * V_17 = NULL ;
V_17 = F_57 ( sizeof *V_17 , V_157 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_17 . V_158 = V_159 ;
F_58 ( & V_17 -> V_27 ) ;
return & V_17 -> V_17 ;
}
static void F_59 ( struct V_138 * V_139 , struct V_156 * V_160 )
{
struct V_16 * V_17 = NULL ;
V_17 = F_50 ( V_160 , struct V_16 , V_17 ) ;
if ( V_160 )
F_60 ( V_17 ) ;
}
static void F_61 ( struct V_14 * V_15 , struct V_23 * V_161 )
{
struct V_122 * V_162 = F_62 ( V_15 ) ;
V_162 -> V_133 = F_10 ( V_161 -> V_33
& V_163 ) ;
V_162 -> V_134 &= F_10 ( ~ ( V_164
| V_165 ) ) ;
F_63 () ;
F_35 ( F_20 ( V_15 ) ? ( 1 << ( F_53 ( V_15 ) + 16 ) )
: ( 1 << ( F_53 ( V_15 ) ) ) , & V_46 -> V_166 ) ;
}
static void F_64 ( struct V_14 * V_15 , struct V_16 * V_17 )
{
T_1 V_96 , V_167 , V_168 ;
V_167 = F_20 ( V_15 )
? ( 1 << ( F_53 ( V_15 ) + 16 ) )
: ( 1 << ( F_53 ( V_15 ) ) ) ;
if ( ! ( F_27 ( & V_15 -> V_27 ) ) && ! ( F_53 ( V_15 ) == 0 ) ) {
struct V_16 * V_169 ;
V_169 = F_28 ( V_15 -> V_27 . V_170 , struct V_16 , V_27 ) ;
V_169 -> V_171 -> V_172 =
F_10 ( V_17 -> V_29 -> V_33 & V_173 ) ;
F_63 () ;
if ( F_31 ( & V_46 -> V_166 ) & V_167 )
return;
do {
V_96 = F_31 ( & V_46 -> V_67 ) ;
F_35 ( V_96 | V_174 , & V_46 -> V_67 ) ;
V_168 = F_31 ( & V_46 -> V_175 ) & V_167 ;
} while ( ! ( F_31 ( & V_46 -> V_67 ) & V_174 ) );
V_96 = F_31 ( & V_46 -> V_67 ) ;
F_35 ( V_96 & ~ V_174 , & V_46 -> V_67 ) ;
if ( V_168 )
return;
}
F_61 ( V_15 , V_17 -> V_29 ) ;
}
static struct V_23 * F_65 ( struct V_16 * V_17 , unsigned * V_38 ,
T_4 * V_158 , int * V_176 , T_3 V_157 )
{
T_1 V_177 ;
struct V_23 * V_178 ;
* V_38 = F_66 ( V_17 -> V_17 . V_38 - V_17 -> V_17 . V_37 ,
( unsigned ) V_179 ) ;
V_178 = F_67 ( V_9 -> V_32 , V_157 , V_158 ) ;
if ( V_178 == NULL )
return V_178 ;
V_178 -> V_33 = * V_158 ;
V_177 = F_13 ( V_178 -> V_180 ) ;
V_177 &= ~ V_181 ;
V_178 -> V_180 = F_10 ( V_177 ) ;
V_177 = ( T_1 ) ( V_17 -> V_17 . V_158 + V_17 -> V_17 . V_37 ) ;
V_178 -> V_182 = F_10 ( V_177 ) ;
V_178 -> V_183 = F_10 ( V_177 + 0x1000 ) ;
V_178 -> V_184 = F_10 ( V_177 + 0x2000 ) ;
V_178 -> V_185 = F_10 ( V_177 + 0x3000 ) ;
V_178 -> V_186 = F_10 ( V_177 + 0x4000 ) ;
V_17 -> V_17 . V_37 += * V_38 ;
if ( V_17 -> V_17 . V_187 ) {
if ( * V_38 == 0 || ( * V_38 % V_17 -> V_15 -> V_15 . V_152 ) != 0 )
* V_176 = 1 ;
else
* V_176 = 0 ;
} else if ( V_17 -> V_17 . V_38 == V_17 -> V_17 . V_37 )
* V_176 = 1 ;
else
* V_176 = 0 ;
if ( ( * V_176 ) == 0 )
F_21 ( L_12 ) ;
V_177 = ( ( * V_38 << V_188 ) | V_189 ) ;
if ( * V_176 && ! V_17 -> V_17 . V_190 )
V_177 |= V_191 ;
V_178 -> V_180 = F_10 ( V_177 ) ;
F_68 () ;
F_21 ( L_13 , * V_38 , ( int ) * V_158 ) ;
return V_178 ;
}
static int F_69 ( struct V_16 * V_17 , T_3 V_157 )
{
unsigned V_192 ;
int V_176 ;
int V_193 = 1 ;
struct V_23 * V_194 = NULL , * V_178 ;
T_4 V_158 ;
do {
V_178 = F_65 ( V_17 , & V_192 , & V_158 , & V_176 , V_157 ) ;
if ( V_178 == NULL )
return - V_195 ;
if ( V_193 ) {
V_193 = 0 ;
V_17 -> V_29 = V_178 ;
} else {
V_194 -> V_172 = F_10 ( V_158 ) ;
V_194 -> V_31 = V_178 ;
}
V_194 = V_178 ;
V_17 -> V_30 ++ ;
} while ( ! V_176 );
V_178 -> V_172 = F_10 ( V_196 ) ;
V_17 -> V_171 = V_178 ;
return 0 ;
}
static int
F_70 ( struct V_138 * V_139 , struct V_156 * V_160 , T_3 V_157 )
{
struct V_14 * V_15 = F_50 ( V_139 , struct V_14 , V_15 ) ;
struct V_16 * V_17 = F_50 ( V_160 , struct V_16 , V_17 ) ;
struct V_21 * V_19 ;
unsigned long V_144 ;
int V_197 ;
if ( ! V_160 || ! V_17 -> V_17 . V_198 || ! V_17 -> V_17 . V_199
|| ! F_27 ( & V_17 -> V_27 ) ) {
F_21 ( L_14 , V_104 ) ;
return - V_66 ;
}
if ( F_71 ( ! V_139 || ! V_15 -> V_15 . V_141 ) ) {
F_21 ( L_15 , V_104 ) ;
return - V_66 ;
}
if ( F_72 ( V_15 -> V_15 . V_141 ) ) {
if ( V_17 -> V_17 . V_38 > V_15 -> V_15 . V_152 )
return - V_200 ;
}
V_19 = V_15 -> V_19 ;
if ( ! V_19 -> V_147 || V_19 -> V_34 . V_148 == V_149 )
return - V_35 ;
V_17 -> V_15 = V_15 ;
V_197 = F_73 ( & V_15 -> V_19 -> V_34 , & V_17 -> V_17 , F_20 ( V_15 ) ) ;
if ( V_197 )
return V_197 ;
V_17 -> V_17 . V_18 = - V_28 ;
V_17 -> V_17 . V_37 = 0 ;
V_17 -> V_30 = 0 ;
if ( ! F_69 ( V_17 , V_157 ) ) {
F_52 ( & V_19 -> V_20 , V_144 ) ;
F_64 ( V_15 , V_17 ) ;
} else {
return - V_195 ;
}
if ( V_17 != NULL )
F_74 ( & V_17 -> V_27 , & V_15 -> V_27 ) ;
F_54 ( & V_19 -> V_20 , V_144 ) ;
return 0 ;
}
static int F_75 ( struct V_138 * V_139 , struct V_156 * V_160 )
{
struct V_14 * V_15 = F_50 ( V_139 , struct V_14 , V_15 ) ;
struct V_16 * V_17 ;
unsigned long V_144 ;
int V_42 , V_22 , V_197 = 0 ;
T_1 V_118 ;
if ( ! V_139 || ! V_160 )
return - V_66 ;
F_52 ( & V_15 -> V_19 -> V_20 , V_144 ) ;
V_22 = V_15 -> V_22 ;
V_15 -> V_22 = 1 ;
V_42 = F_53 ( V_15 ) ;
V_118 = F_31 ( & V_46 -> V_84 [ V_42 ] ) ;
if ( F_20 ( V_15 ) )
V_118 &= ~ V_112 ;
else
V_118 &= ~ V_114 ;
F_35 ( V_118 , & V_46 -> V_84 [ V_42 ] ) ;
F_76 (req, &ep->queue, queue) {
if ( & V_17 -> V_17 == V_160 )
break;
}
if ( & V_17 -> V_17 != V_160 ) {
V_197 = - V_66 ;
goto V_201;
}
if ( V_15 -> V_27 . V_39 == & V_17 -> V_27 ) {
V_160 -> V_18 = - V_202 ;
F_26 ( V_139 ) ;
if ( V_17 -> V_27 . V_39 != & V_15 -> V_27 ) {
struct V_16 * V_203 ;
V_203 = F_28 ( V_17 -> V_27 . V_39 , struct V_16 ,
V_27 ) ;
F_61 ( V_15 , V_203 -> V_29 ) ;
}
} else {
struct V_16 * V_204 ;
V_204 = F_28 ( V_17 -> V_27 . V_170 , struct V_16 , V_27 ) ;
V_204 -> V_171 -> V_172 = V_17 -> V_171 -> V_172 ;
}
F_16 ( V_15 , V_17 , - V_202 ) ;
V_201: V_118 = F_31 ( & V_46 -> V_84 [ V_42 ] ) ;
if ( F_20 ( V_15 ) )
V_118 |= V_112 ;
else
V_118 |= V_114 ;
F_35 ( V_118 , & V_46 -> V_84 [ V_42 ] ) ;
V_15 -> V_22 = V_22 ;
F_54 ( & V_15 -> V_19 -> V_20 , V_144 ) ;
return V_197 ;
}
static int F_77 ( struct V_138 * V_139 , int V_115 )
{
struct V_14 * V_15 = NULL ;
unsigned long V_144 = 0 ;
int V_18 = - V_205 ;
unsigned char V_206 = 0 , V_42 = 0 ;
struct V_21 * V_19 = NULL ;
V_15 = F_50 ( V_139 , struct V_14 , V_15 ) ;
V_19 = V_15 -> V_19 ;
if ( ! V_139 || ! V_15 -> V_15 . V_141 ) {
V_18 = - V_66 ;
goto V_201;
}
if ( F_72 ( V_15 -> V_15 . V_141 ) ) {
V_18 = - V_205 ;
goto V_201;
}
if ( V_115 && F_20 ( V_15 ) && ! F_27 ( & V_15 -> V_27 ) ) {
V_18 = - V_207 ;
goto V_201;
}
V_18 = 0 ;
V_206 = F_20 ( V_15 ) ? V_137 : V_135 ;
V_42 = ( unsigned char ) ( F_53 ( V_15 ) ) ;
F_52 ( & V_15 -> V_19 -> V_20 , V_144 ) ;
F_45 ( V_42 , V_206 , V_115 ) ;
F_54 ( & V_15 -> V_19 -> V_20 , V_144 ) ;
if ( F_53 ( V_15 ) == 0 ) {
V_19 -> V_208 = V_209 ;
V_19 -> V_210 = 0 ;
}
V_201:
F_21 ( L_16 , V_15 -> V_15 . V_36 ,
V_115 ? L_17 : L_18 , V_18 ) ;
return V_18 ;
}
static int F_78 ( struct V_138 * V_139 )
{
struct V_14 * V_15 ;
struct V_21 * V_19 ;
int V_211 = 0 ;
T_1 V_167 ;
struct V_122 * V_162 ;
V_15 = F_50 ( V_139 , struct V_14 , V_15 ) ;
if ( ! V_139 || ( ! V_15 -> V_15 . V_141 && F_53 ( V_15 ) != 0 ) )
return - V_212 ;
V_19 = (struct V_21 * ) V_15 -> V_19 ;
if ( ! V_19 -> V_147 || V_19 -> V_34 . V_148 == V_149 )
return - V_35 ;
V_162 = F_62 ( V_15 ) ;
V_167 = ( F_20 ( V_15 ) ) ? ( 1 << ( F_53 ( V_15 ) + 16 ) ) :
( 1 << ( F_53 ( V_15 ) ) ) ;
if ( F_31 ( & V_46 -> V_175 ) & V_167 )
V_211 = ( V_162 -> V_134 & V_213 )
>> V_188 ;
F_43 ( L_19 , V_104 , V_211 ) ;
return V_211 ;
}
static void F_26 ( struct V_138 * V_139 )
{
struct V_14 * V_15 ;
int V_42 , V_206 ;
T_1 V_214 ;
unsigned long V_45 ;
#define F_79 1000
if ( ! V_139 ) {
return;
} else {
V_15 = F_50 ( V_139 , struct V_14 , V_15 ) ;
if ( ! V_15 -> V_15 . V_141 )
return;
}
V_42 = F_53 ( V_15 ) ;
V_206 = F_20 ( V_15 ) ? V_137 : V_135 ;
if ( V_42 == 0 )
V_214 = ( 1 << 16 ) | 1 ;
else if ( V_206 == V_137 )
V_214 = 1 << ( 16 + V_42 ) ;
else
V_214 = 1 << V_42 ;
V_45 = V_70 + F_79 ;
do {
F_35 ( V_214 , & V_46 -> V_215 ) ;
while ( F_31 ( & V_46 -> V_215 ) ) {
if ( F_36 ( V_70 , V_45 ) ) {
F_37 ( L_20 ) ;
return;
}
F_38 () ;
}
} while ( F_31 ( & V_46 -> V_175 ) & V_214 );
}
static int F_80 ( struct V_216 * V_34 )
{
return ( int ) ( F_31 ( & V_46 -> V_217 ) & V_218 ) ;
}
static int F_81 ( struct V_216 * V_34 )
{
struct V_21 * V_19 = F_50 ( V_34 , struct V_21 , V_34 ) ;
T_1 V_219 ;
if ( ! V_19 -> V_220 )
return - V_221 ;
V_219 = F_31 ( & V_46 -> V_47 ) ;
if ( ! ( V_219 & V_222 ) )
return 0 ;
V_219 |= V_223 ;
F_35 ( V_219 , & V_46 -> V_47 ) ;
return 0 ;
}
static int F_82 ( struct V_21 * V_19 )
{
return V_19 -> V_147 && V_19 -> V_224 && V_19 -> V_225 ;
}
static int F_83 ( struct V_216 * V_34 , int V_226 )
{
struct V_21 * V_19 ;
unsigned long V_144 ;
V_19 = F_50 ( V_34 , struct V_21 , V_34 ) ;
F_52 ( & V_19 -> V_20 , V_144 ) ;
F_21 ( L_21 , V_226 ? L_22 : L_23 ) ;
V_19 -> V_225 = ( V_226 != 0 ) ;
if ( F_82 ( V_19 ) )
F_35 ( ( F_31 ( & V_46 -> V_67 ) | V_68 ) ,
& V_46 -> V_67 ) ;
else
F_35 ( ( F_31 ( & V_46 -> V_67 ) & ~ V_68 ) ,
& V_46 -> V_67 ) ;
F_54 ( & V_19 -> V_20 , V_144 ) ;
return 0 ;
}
static int F_84 ( struct V_216 * V_34 , unsigned V_227 )
{
struct V_21 * V_19 ;
V_19 = F_50 ( V_34 , struct V_21 , V_34 ) ;
if ( ! F_85 ( V_19 -> V_228 ) )
return F_86 ( V_19 -> V_228 , V_227 ) ;
return - V_221 ;
}
static int F_87 ( struct V_216 * V_34 , int V_229 )
{
struct V_21 * V_19 ;
V_19 = F_50 ( V_34 , struct V_21 , V_34 ) ;
if ( ! V_19 -> V_225 )
return - V_205 ;
V_19 -> V_224 = ( V_229 != 0 ) ;
if ( F_82 ( V_19 ) )
F_35 ( ( F_31 ( & V_46 -> V_67 ) | V_68 ) ,
& V_46 -> V_67 ) ;
else
F_35 ( ( F_31 ( & V_46 -> V_67 ) & ~ V_68 ) ,
& V_46 -> V_67 ) ;
return 0 ;
}
static void F_88 ( struct V_21 * V_19 )
{
T_1 V_40 ;
V_40 = F_31 ( & V_46 -> V_84 [ 0 ] ) ;
V_40 |= V_116 | V_117 ;
F_35 ( V_40 , & V_46 -> V_84 [ 0 ] ) ;
V_19 -> V_208 = V_209 ;
V_19 -> V_210 = 0 ;
}
static int F_89 ( struct V_21 * V_19 , int V_230 )
{
struct V_16 * V_17 = V_19 -> V_231 ;
struct V_14 * V_15 ;
int V_197 ;
if ( V_230 == V_232 )
V_19 -> V_210 = V_154 ;
else
V_19 -> V_210 = V_233 ;
V_15 = & V_19 -> V_234 [ 0 ] ;
if ( V_19 -> V_208 != V_235 )
V_19 -> V_208 = V_236 ;
V_17 -> V_15 = V_15 ;
V_17 -> V_17 . V_38 = 0 ;
V_17 -> V_17 . V_18 = - V_28 ;
V_17 -> V_17 . V_37 = 0 ;
V_17 -> V_17 . V_198 = NULL ;
V_17 -> V_30 = 0 ;
V_197 = F_73 ( & V_15 -> V_19 -> V_34 , & V_17 -> V_17 , F_20 ( V_15 ) ) ;
if ( V_197 )
return V_197 ;
if ( F_69 ( V_17 , V_237 ) == 0 )
F_64 ( V_15 , V_17 ) ;
else
return - V_195 ;
F_74 ( & V_17 -> V_27 , & V_15 -> V_27 ) ;
return 0 ;
}
static void F_90 ( struct V_21 * V_19 , T_5 V_238 )
{
struct V_14 * V_15 = F_91 ( V_19 , V_238 ) ;
if ( V_15 -> V_36 )
F_25 ( V_15 , - V_35 ) ;
}
static void F_92 ( struct V_21 * V_19 , T_6 V_115 , T_6 V_239 , T_6 V_38 )
{
V_19 -> V_240 = ( T_5 ) V_115 ;
V_19 -> V_241 = V_242 ;
if ( F_89 ( V_19 , V_232 ) )
F_88 ( V_19 ) ;
}
static void F_93 ( struct V_21 * V_19 , T_5 V_243 , T_6 V_115 ,
T_6 V_239 , T_6 V_38 )
{
T_6 V_40 = 0 ;
struct V_16 * V_17 ;
struct V_14 * V_15 ;
int V_197 ;
V_15 = & V_19 -> V_234 [ 0 ] ;
if ( ( V_243 & V_244 ) == V_245 ) {
V_40 = V_19 -> V_34 . V_246 ;
V_40 |= V_19 -> V_220 << V_247 ;
} else if ( ( V_243 & V_244 ) == V_248 ) {
V_40 = 0 ;
} else if ( ( V_243 & V_244 ) == V_249 ) {
struct V_14 * V_250 ;
V_250 = F_91 ( V_19 , F_94 ( V_239 ) ) ;
if ( ! V_250 -> V_15 . V_141 )
goto V_251;
V_40 = F_46 ( F_53 ( V_250 ) , F_20 ( V_250 ) )
<< V_252 ;
}
V_19 -> V_210 = V_154 ;
V_17 = V_19 -> V_231 ;
* ( ( T_6 * ) V_17 -> V_17 . V_199 ) = F_95 ( V_40 ) ;
V_17 -> V_15 = V_15 ;
V_17 -> V_17 . V_38 = 2 ;
V_17 -> V_17 . V_18 = - V_28 ;
V_17 -> V_17 . V_37 = 0 ;
V_17 -> V_17 . V_198 = NULL ;
V_17 -> V_30 = 0 ;
V_197 = F_73 ( & V_15 -> V_19 -> V_34 , & V_17 -> V_17 , F_20 ( V_15 ) ) ;
if ( V_197 )
goto V_251;
if ( ( F_69 ( V_17 , V_237 ) == 0 ) )
F_64 ( V_15 , V_17 ) ;
else
goto V_251;
F_74 ( & V_17 -> V_27 , & V_15 -> V_27 ) ;
V_19 -> V_208 = V_235 ;
if ( F_89 ( V_19 , V_253 ) )
F_88 ( V_19 ) ;
return;
V_251:
F_88 ( V_19 ) ;
}
static void F_96 ( struct V_21 * V_19 ,
struct V_254 * V_255 )
__releases( V_19 -> V_20 )
__acquires( V_19 -> V_20 )
{
T_6 V_256 = F_97 ( V_255 -> V_256 ) ;
T_6 V_257 = F_97 ( V_255 -> V_257 ) ;
T_6 V_258 = F_97 ( V_255 -> V_258 ) ;
F_90 ( V_19 , 0 ) ;
switch ( V_255 -> V_259 ) {
case V_260 :
if ( ( V_255 -> V_261 & ( V_154 | V_262 ) )
!= ( V_154 | V_263 ) )
break;
F_93 ( V_19 , V_255 -> V_261 , V_256 , V_257 , V_258 ) ;
return;
case V_264 :
if ( V_255 -> V_261 != ( V_233 | V_263
| V_245 ) )
break;
F_92 ( V_19 , V_256 , V_257 , V_258 ) ;
return;
case V_265 :
case V_266 :
{
int V_267 = - V_205 ;
T_6 V_268 = 0 ;
if ( ( V_255 -> V_261 & ( V_244 | V_262 ) )
== ( V_249 | V_263 ) ) {
int V_238 = F_94 ( V_257 ) ;
struct V_14 * V_15 ;
if ( V_256 != 0 || V_258 != 0 || V_238 >= V_19 -> V_269 )
break;
V_15 = F_91 ( V_19 , V_238 ) ;
F_22 ( & V_19 -> V_20 ) ;
V_267 = F_77 ( & V_15 -> V_15 ,
( V_255 -> V_259 == V_266 )
? 1 : 0 ) ;
F_24 ( & V_19 -> V_20 ) ;
} else if ( ( V_255 -> V_261 & ( V_244
| V_262 ) ) == ( V_245
| V_263 ) ) {
if ( V_256 == V_270 )
V_268 = V_257 >> 8 ;
else if ( F_98 ( & V_19 -> V_34 ) ) {
if ( V_255 -> V_259 ==
V_271 )
V_19 -> V_34 . V_272 = 1 ;
else if ( V_255 -> V_259 ==
V_273 )
V_19 -> V_34 . V_274 = 1 ;
else if ( V_255 -> V_259 ==
V_275 )
V_19 -> V_34 . V_276 = 1 ;
}
V_267 = 0 ;
} else
break;
if ( V_267 == 0 ) {
if ( F_89 ( V_19 , V_232 ) )
F_88 ( V_19 ) ;
}
if ( V_268 ) {
T_1 V_40 ;
F_34 ( 10 ) ;
V_40 = F_31 ( & V_46 -> V_47 ) | ( V_268 << 16 ) ;
F_35 ( V_40 , & V_46 -> V_47 ) ;
F_99 ( V_277 L_24 , V_268 ) ;
}
return;
}
default:
break;
}
if ( V_258 ) {
V_19 -> V_210 = ( V_255 -> V_261 & V_154 )
? V_154 : V_233 ;
F_22 ( & V_19 -> V_20 ) ;
if ( V_19 -> V_147 -> V_255 ( & V_19 -> V_34 ,
& V_19 -> V_278 ) < 0 )
F_88 ( V_19 ) ;
F_24 ( & V_19 -> V_20 ) ;
V_19 -> V_208 = ( V_255 -> V_261 & V_154 )
? V_235 : V_279 ;
if ( V_19 -> V_208 == V_235 )
if ( F_89 ( V_19 , V_253 ) )
F_88 ( V_19 ) ;
} else {
V_19 -> V_210 = V_154 ;
F_22 ( & V_19 -> V_20 ) ;
if ( V_19 -> V_147 -> V_255 ( & V_19 -> V_34 ,
& V_19 -> V_278 ) < 0 )
F_88 ( V_19 ) ;
F_24 ( & V_19 -> V_20 ) ;
V_19 -> V_208 = V_236 ;
}
}
static void F_100 ( struct V_21 * V_19 , struct V_14 * V_280 ,
struct V_16 * V_17 )
{
if ( V_19 -> V_241 == V_242 ) {
T_1 V_281 = ( T_1 ) V_19 -> V_240 ;
F_35 ( V_281 << V_282 ,
& V_46 -> V_283 ) ;
}
F_16 ( V_280 , V_17 , 0 ) ;
switch ( V_19 -> V_208 ) {
case V_235 :
V_19 -> V_208 = V_236 ;
break;
case V_279 :
if ( F_89 ( V_19 , V_232 ) )
F_88 ( V_19 ) ;
break;
case V_236 :
V_19 -> V_208 = V_209 ;
break;
case V_209 :
F_37 ( L_25 ) ;
break;
default:
F_88 ( V_19 ) ;
break;
}
}
static void F_101 ( struct V_21 * V_19 , T_5 V_42 , T_5 * V_284 )
{
T_1 V_96 ;
struct V_122 * V_162 ;
struct V_3 * V_4 = V_19 -> V_4 ;
V_162 = & V_19 -> V_82 [ V_42 * 2 + V_253 ] ;
V_96 = F_31 ( & V_46 -> V_285 ) ;
F_35 ( V_96 | ( 1 << V_42 ) , & V_46 -> V_285 ) ;
do {
V_96 = F_31 ( & V_46 -> V_67 ) ;
F_35 ( V_96 | V_286 , & V_46 -> V_67 ) ;
if ( V_4 -> V_287 ) {
T_1 * V_1 = ( T_1 * ) V_284 ;
T_1 * V_288 = ( T_1 * ) V_162 -> V_289 ;
* V_1 ++ = F_15 ( * V_288 ++ ) ;
* V_1 = F_15 ( * V_288 ) ;
} else {
memcpy ( V_284 , ( T_5 * ) V_162 -> V_289 , 8 ) ;
}
} while ( ! ( F_31 ( & V_46 -> V_67 ) & V_286 ) );
V_96 = F_31 ( & V_46 -> V_67 ) ;
F_35 ( V_96 & ~ V_286 , & V_46 -> V_67 ) ;
}
static int F_102 ( struct V_21 * V_19 , int V_238 ,
struct V_16 * V_290 )
{
struct V_23 * V_24 ;
int V_291 , V_37 , V_292 , V_26 , V_40 ;
int V_18 = 0 ;
int V_293 = 0 ;
struct V_122 * V_294 = & V_19 -> V_82 [ V_238 ] ;
int V_230 = V_238 % 2 ;
V_24 = V_290 -> V_29 ;
V_291 = 0 ;
V_37 = V_290 -> V_17 . V_38 ;
for ( V_26 = 0 ; V_26 < V_290 -> V_30 ; V_26 ++ ) {
V_292 = ( F_13 ( V_24 -> V_180 )
& V_213 )
>> V_188 ;
V_37 -= V_292 ;
V_293 = F_13 ( V_24 -> V_180 ) ;
if ( V_293 & V_295 ) {
if ( V_293 & V_296 ) {
F_37 ( L_26 , V_293 , V_238 ) ;
V_40 = F_13 ( V_294 -> V_134 ) ;
V_40 &= ~ V_293 ;
V_294 -> V_134 = F_10 ( V_40 ) ;
V_18 = - V_297 ;
break;
}
if ( V_293 & V_298 ) {
F_21 ( L_27 ) ;
V_18 = - V_299 ;
break;
} else if ( V_293 & V_300 ) {
F_21 ( L_28 ) ;
V_18 = - V_301 ;
break;
} else
F_37 ( L_29 ,
V_293 ) ;
} else if ( F_13 ( V_24 -> V_180 )
& V_189 ) {
F_21 ( L_30 ) ;
V_18 = V_302 ;
return V_18 ;
} else if ( V_292 ) {
if ( V_230 ) {
F_21 ( L_31 ) ;
V_18 = - V_299 ;
break;
} else {
V_291 ++ ;
break;
}
} else {
V_291 ++ ;
F_21 ( L_32 ) ;
}
if ( V_26 != V_290 -> V_30 - 1 )
V_24 = (struct V_23 * ) V_24 -> V_31 ;
}
if ( V_18 )
return V_18 ;
V_290 -> V_17 . V_37 = V_37 ;
return 0 ;
}
static void F_103 ( struct V_21 * V_19 )
{
T_1 V_303 ;
int V_304 , V_42 , V_230 , V_305 , V_18 ;
struct V_14 * V_306 ;
struct V_16 * V_290 , * V_307 ;
V_303 = F_31 ( & V_46 -> V_308 ) ;
F_35 ( V_303 , & V_46 -> V_308 ) ;
if ( ! V_303 )
return;
for ( V_304 = 0 ; V_304 < V_19 -> V_269 ; V_304 ++ ) {
V_42 = V_304 >> 1 ;
V_230 = V_304 % 2 ;
V_305 = 1 << ( V_42 + 16 * V_230 ) ;
if ( ! ( V_303 & V_305 ) )
continue;
V_306 = F_91 ( V_19 , V_304 ) ;
if ( V_306 -> V_36 == NULL ) {
F_104 ( L_33 ) ;
continue;
}
F_105 (curr_req, temp_req, &curr_ep->queue,
queue) {
V_18 = F_102 ( V_19 , V_304 , V_290 ) ;
F_21 ( L_34 ,
V_18 , V_42 ) ;
if ( V_18 == V_302 )
break;
V_290 -> V_17 . V_18 = V_18 ;
if ( V_42 == 0 ) {
F_100 ( V_19 , V_306 , V_290 ) ;
break;
} else
F_16 ( V_306 , V_290 , V_18 ) ;
}
}
}
static inline enum V_309 F_106 ( T_1 V_310 )
{
switch ( V_310 & V_311 ) {
case V_312 :
return V_313 ;
case V_314 :
return V_315 ;
case V_316 :
return V_317 ;
default:
return V_149 ;
}
}
static void F_107 ( struct V_21 * V_19 )
{
if ( V_19 -> V_318 )
V_19 -> V_318 = 0 ;
if ( ! ( F_31 ( & V_46 -> V_47 ) & V_319 ) )
V_19 -> V_34 . V_148 =
F_106 ( F_31 ( & V_46 -> V_47 ) ) ;
if ( ! V_19 -> V_320 )
V_19 -> V_241 = V_321 ;
}
static void F_108 ( struct V_21 * V_19 )
{
V_19 -> V_320 = V_19 -> V_241 ;
V_19 -> V_241 = V_322 ;
if ( V_19 -> V_147 -> V_323 )
V_19 -> V_147 -> V_323 ( & V_19 -> V_34 ) ;
}
static void F_109 ( struct V_21 * V_19 )
{
V_19 -> V_241 = V_19 -> V_320 ;
V_19 -> V_320 = 0 ;
if ( V_19 -> V_147 -> V_324 )
V_19 -> V_147 -> V_324 ( & V_19 -> V_34 ) ;
}
static int F_110 ( struct V_21 * V_19 , bool V_318 )
{
T_5 V_238 ;
for ( V_238 = 0 ; V_238 < V_19 -> V_325 ; V_238 ++ )
F_90 ( V_19 , V_238 ) ;
F_22 ( & V_19 -> V_20 ) ;
if ( V_318 )
F_111 ( & V_19 -> V_34 , V_19 -> V_147 ) ;
else
V_19 -> V_147 -> V_326 ( & V_19 -> V_34 ) ;
F_24 ( & V_19 -> V_20 ) ;
return 0 ;
}
static void F_112 ( struct V_21 * V_19 )
{
T_1 V_96 ;
unsigned long V_45 ;
V_96 = F_31 ( & V_46 -> V_283 ) ;
F_35 ( V_96 & ~ V_327 , & V_46 -> V_283 ) ;
V_19 -> V_240 = 0 ;
V_19 -> V_320 = 0 ;
V_19 -> V_210 = 0 ;
V_19 -> V_208 = V_209 ;
V_19 -> V_220 = 0 ;
V_19 -> V_34 . V_272 = 0 ;
V_19 -> V_34 . V_274 = 0 ;
V_19 -> V_34 . V_276 = 0 ;
V_96 = F_31 ( & V_46 -> V_285 ) ;
F_35 ( V_96 , & V_46 -> V_285 ) ;
V_96 = F_31 ( & V_46 -> V_308 ) ;
F_35 ( V_96 , & V_46 -> V_308 ) ;
V_45 = V_70 + 100 ;
while ( F_31 ( & V_46 -> V_166 ) ) {
if ( F_36 ( V_70 , V_45 ) ) {
F_37 ( L_35 ) ;
break;
}
F_38 () ;
}
F_35 ( 0xffffffff , & V_46 -> V_215 ) ;
if ( F_31 ( & V_46 -> V_47 ) & V_319 ) {
F_21 ( L_36 ) ;
V_19 -> V_318 = 1 ;
F_110 ( V_19 , true ) ;
V_19 -> V_241 = V_321 ;
} else {
F_21 ( L_37 ) ;
F_29 ( V_19 ) ;
F_110 ( V_19 , false ) ;
F_48 ( V_19 ) ;
F_41 ( V_19 ) ;
V_19 -> V_241 = V_328 ;
}
}
static T_7 F_113 ( int V_329 , void * V_330 )
{
struct V_21 * V_19 = V_330 ;
T_1 V_331 ;
T_7 V_18 = V_332 ;
unsigned long V_144 ;
if ( V_19 -> V_22 )
return V_332 ;
F_52 ( & V_19 -> V_20 , V_144 ) ;
V_331 = F_31 ( & V_46 -> V_78 ) & F_31 ( & V_46 -> V_103 ) ;
F_35 ( V_331 , & V_46 -> V_78 ) ;
if ( V_19 -> V_241 == V_322 )
if ( ( F_31 ( & V_46 -> V_47 ) & V_222 ) == 0 )
F_109 ( V_19 ) ;
if ( V_331 & V_333 ) {
F_21 ( L_38 ) ;
if ( F_31 ( & V_46 -> V_285 ) & V_334 ) {
F_101 ( V_19 , 0 ,
( T_5 * ) ( & V_19 -> V_278 ) ) ;
F_96 ( V_19 , & V_19 -> V_278 ) ;
V_18 = V_335 ;
}
if ( F_31 ( & V_46 -> V_308 ) ) {
F_103 ( V_19 ) ;
V_18 = V_335 ;
}
}
if ( V_331 & V_336 ) {
V_18 = V_335 ;
}
if ( V_331 & V_337 ) {
F_107 ( V_19 ) ;
V_18 = V_335 ;
}
if ( V_331 & V_338 ) {
F_21 ( L_39 ) ;
F_112 ( V_19 ) ;
V_18 = V_335 ;
}
if ( V_331 & V_339 ) {
F_108 ( V_19 ) ;
V_18 = V_335 ;
}
if ( V_331 & ( V_340 | V_341 ) ) {
F_21 ( L_40 , V_331 ) ;
}
F_54 ( & V_19 -> V_20 , V_144 ) ;
return V_18 ;
}
static int F_114 ( struct V_216 * V_342 ,
struct V_343 * V_147 )
{
int V_143 = 0 ;
unsigned long V_144 = 0 ;
F_52 ( & V_9 -> V_20 , V_144 ) ;
V_147 -> V_147 . V_344 = NULL ;
V_9 -> V_147 = V_147 ;
F_54 ( & V_9 -> V_20 , V_144 ) ;
V_342 -> V_246 = 1 ;
if ( ! F_85 ( V_9 -> V_228 ) ) {
V_9 -> V_22 = 1 ;
F_99 ( V_277 L_41 ) ;
if ( ! F_85 ( V_9 -> V_228 ) ) {
V_143 = F_115 (
V_9 -> V_228 -> V_345 ,
& V_9 -> V_34 ) ;
if ( V_143 < 0 ) {
F_37 ( L_42 ) ;
V_9 -> V_147 = NULL ;
return V_143 ;
}
}
} else {
F_41 ( V_9 ) ;
V_9 -> V_241 = V_328 ;
V_9 -> V_208 = V_209 ;
V_9 -> V_210 = 0 ;
}
return V_143 ;
}
static int F_116 ( struct V_216 * V_342 )
{
struct V_14 * V_346 ;
unsigned long V_144 ;
if ( ! F_85 ( V_9 -> V_228 ) )
F_115 ( V_9 -> V_228 -> V_345 , NULL ) ;
F_42 ( V_9 ) ;
V_9 -> V_241 = V_328 ;
V_9 -> V_208 = V_209 ;
V_9 -> V_210 = 0 ;
F_52 ( & V_9 -> V_20 , V_144 ) ;
V_9 -> V_34 . V_148 = V_149 ;
F_25 ( & V_9 -> V_234 [ 0 ] , - V_35 ) ;
F_76 (loop_ep, &udc_controller->gadget.ep_list,
ep.ep_list)
F_25 ( V_346 , - V_35 ) ;
F_54 ( & V_9 -> V_20 , V_144 ) ;
V_9 -> V_147 = NULL ;
return 0 ;
}
static int F_117 ( struct V_347 * V_348 , void * V_2 )
{
unsigned long V_144 ;
int V_304 ;
T_1 V_349 ;
struct V_14 * V_15 = NULL ;
struct V_16 * V_17 ;
struct V_21 * V_19 = V_9 ;
F_52 ( & V_19 -> V_20 , V_144 ) ;
F_118 ( V_348 ,
V_350 L_43
L_44
L_45 ,
V_351 , V_352 ,
V_19 -> V_147 ? V_19 -> V_147 -> V_147 . V_36 : L_46 ) ;
V_349 = F_31 ( & V_46 -> V_67 ) ;
F_118 ( V_348 ,
L_47
L_48
L_49 ,
( V_349 & V_286 ) ? 1 : 0 ,
( V_349 & V_68 ) ? L_50 : L_51 ) ;
V_349 = F_31 ( & V_46 -> V_78 ) ;
F_118 ( V_348 ,
L_52
L_53
L_54 ,
( V_349 & V_339 ) ? 1 : 0 ,
( V_349 & V_338 ) ? 1 : 0 ,
( V_349 & V_341 ) ? L_55 : L_56 ,
( V_349 & V_340 ) ? L_57 : L_58 ) ;
V_349 = F_31 ( & V_46 -> V_103 ) ;
F_118 ( V_348 ,
L_59
L_60
L_61
L_62
L_63
L_64 ,
( V_349 & V_101 ) ? 1 : 0 ,
( V_349 & V_353 ) ? 1 : 0 ,
( V_349 & V_100 ) ? 1 : 0 ,
( V_349 & V_102 ) ? 1 : 0 ,
( V_349 & V_99 ) ? 1 : 0 ,
( V_349 & V_98 ) ? 1 : 0 ,
( V_349 & V_97 ) ? 1 : 0 ) ;
V_349 = F_31 ( & V_46 -> V_217 ) ;
F_118 ( V_348 ,
L_65 ,
( V_349 & V_218 ) ) ;
V_349 = F_31 ( & V_46 -> V_283 ) ;
F_118 ( V_348 ,
L_66 ,
( V_349 & V_327 ) ) ;
V_349 = F_31 ( & V_46 -> V_81 ) ;
F_118 ( V_348 ,
L_67
L_68 ,
( V_349 & V_80 ) ) ;
V_349 = F_31 ( & V_46 -> V_47 ) ;
F_118 (m,
L_69
L_70
L_71
L_72
L_73
L_74
L_75
L_76 , ( {
const char *s;
switch (tmp_reg & PORTSCX_PTS_FSLS) {
case PORTSCX_PTS_UTMI:
s = L_77; break;
case PORTSCX_PTS_ULPI:
s = L_78; break;
case PORTSCX_PTS_FSLS:
s = L_79; break;
default:
s = L_80; break;
}
s;} ),
usb_speed_string(portscx_device_speed(tmp_reg)),
(tmp_reg & PORTSCX_PHY_LOW_POWER_SPD) ?
L_81 : L_82 ,
(tmp_reg & PORTSCX_PORT_RESET) ? L_83 :
L_84 ,
(tmp_reg & PORTSCX_PORT_SUSPEND) ? L_85 : L_86 ,
(tmp_reg & PORTSCX_OVER_CURRENT_CHG) ? L_87 :
L_88 ,
(tmp_reg & PORTSCX_PORT_EN_DIS_CHANGE) ? L_89 :
L_90 ,
(tmp_reg & PORTSCX_PORT_ENABLE) ? L_91 :
L_92 ,
(tmp_reg & PORTSCX_CURRENT_CONNECT_STATUS) ?
L_93 : L_94 ) ;
V_349 = F_31 ( & V_46 -> V_72 ) ;
F_118 (m,
L_95 , ( {
const char *s;
switch (tmp_reg & USB_MODE_CTRL_MODE_HOST) {
case USB_MODE_CTRL_MODE_IDLE:
s = L_96; break;
case USB_MODE_CTRL_MODE_DEVICE:
s = L_97; break;
case USB_MODE_CTRL_MODE_HOST:
s = L_98; break;
default:
s = L_80; break;
}
s;
} )) ;
V_349 = F_31 ( & V_46 -> V_285 ) ;
F_118 ( V_348 ,
L_99 ,
( V_349 & V_354 ) ) ;
for ( V_304 = 0 ; V_304 < V_19 -> V_269 / 2 ; V_304 ++ ) {
V_349 = F_31 ( & V_46 -> V_84 [ V_304 ] ) ;
F_118 ( V_348 , L_100 , V_304 , V_349 ) ;
}
V_349 = F_31 ( & V_46 -> V_166 ) ;
F_118 ( V_348 , L_101 , V_349 ) ;
#ifndef F_39
if ( V_19 -> V_4 -> V_52 ) {
V_349 = V_54 -> V_94 ;
F_118 ( V_348 , L_102 , V_349 ) ;
V_349 = V_54 -> V_55 ;
F_118 ( V_348 , L_103 , V_349 ) ;
}
#endif
V_15 = & V_19 -> V_234 [ 0 ] ;
F_118 ( V_348 , L_104 ,
V_15 -> V_15 . V_36 , F_119 ( V_15 ) , F_53 ( V_15 ) ) ;
if ( F_27 ( & V_15 -> V_27 ) ) {
F_120 ( V_348 , L_105 ) ;
} else {
F_76 (req, &ep->queue, queue) {
F_118 ( V_348 ,
L_106 ,
& V_17 -> V_17 , V_17 -> V_17 . V_37 ,
V_17 -> V_17 . V_38 , V_17 -> V_17 . V_199 ) ;
}
}
F_76 (ep, &udc->gadget.ep_list, ep.ep_list) {
if ( V_15 -> V_15 . V_141 ) {
F_118 ( V_348 ,
L_107
L_108 ,
V_15 -> V_15 . V_36 , F_119 ( V_15 ) ,
F_53 ( V_15 ) ) ;
if ( F_27 ( & V_15 -> V_27 ) ) {
F_120 ( V_348 , L_105 ) ;
} else {
F_76 (req, &ep->queue, queue) {
F_118 ( V_348 ,
L_109
L_110 ,
& V_17 -> V_17 , V_17 -> V_17 . V_37 ,
V_17 -> V_17 . V_38 , V_17 -> V_17 . V_199 ) ;
}
}
}
}
F_54 ( & V_19 -> V_20 , V_144 ) ;
return 0 ;
}
static int F_121 ( struct V_355 * V_355 , struct V_356 * V_356 )
{
return F_122 ( V_356 , F_117 , NULL ) ;
}
static void F_123 ( struct V_357 * V_358 )
{
V_198 ( V_9 -> F_16 ) ;
F_124 ( V_358 -> V_359 , V_9 -> V_360 ,
V_9 -> V_82 , V_9 -> V_79 ) ;
F_60 ( V_9 ) ;
}
static int F_125 ( struct V_21 * V_19 ,
struct V_361 * V_362 )
{
struct V_3 * V_4 ;
T_8 V_211 ;
V_4 = F_126 ( & V_362 -> V_358 ) ;
V_19 -> V_50 = V_4 -> V_50 ;
V_19 -> V_234 = F_57 ( sizeof( struct V_14 ) * V_19 -> V_269 , V_363 ) ;
if ( ! V_19 -> V_234 )
return - 1 ;
V_211 = V_19 -> V_269 * sizeof( struct V_122 ) ;
if ( V_211 < V_364 )
V_211 = V_364 ;
else if ( ( V_211 % V_364 ) != 0 ) {
V_211 += V_364 + 1 ;
V_211 &= ~ ( V_364 - 1 ) ;
}
V_19 -> V_82 = F_127 ( & V_362 -> V_358 , V_211 ,
& V_19 -> V_79 , V_363 ) ;
if ( ! V_19 -> V_82 ) {
F_37 ( L_111 ) ;
F_60 ( V_19 -> V_234 ) ;
return - 1 ;
}
V_19 -> V_360 = V_211 ;
V_19 -> V_231 = F_50 ( F_56 ( NULL , V_363 ) ,
struct V_16 , V_17 ) ;
V_19 -> V_231 -> V_17 . V_199 = F_128 ( 8 , V_363 ) ;
V_19 -> V_320 = V_365 ;
V_19 -> V_241 = V_366 ;
V_19 -> V_210 = 0 ;
V_19 -> V_220 = 0 ;
return 0 ;
}
static int F_129 ( struct V_21 * V_19 , unsigned char V_239 ,
char * V_36 , int V_367 )
{
struct V_14 * V_15 = & V_19 -> V_234 [ V_239 ] ;
V_15 -> V_19 = V_19 ;
strcpy ( V_15 -> V_36 , V_36 ) ;
V_15 -> V_15 . V_36 = V_15 -> V_36 ;
V_15 -> V_15 . V_368 = & V_369 ;
V_15 -> V_22 = 0 ;
F_130 ( & V_15 -> V_15 , ( unsigned short ) ~ 0 ) ;
F_58 ( & V_15 -> V_27 ) ;
if ( V_367 )
F_74 ( & V_15 -> V_15 . V_370 , & V_19 -> V_34 . V_370 ) ;
V_15 -> V_34 = & V_19 -> V_34 ;
V_15 -> V_162 = & V_19 -> V_82 [ V_239 ] ;
return 0 ;
}
static int F_131 ( struct V_361 * V_362 )
{
struct V_3 * V_4 ;
struct V_371 * V_372 ;
int V_197 = - V_212 ;
unsigned int V_304 ;
T_1 V_83 ;
V_9 = F_57 ( sizeof( struct V_21 ) , V_363 ) ;
if ( V_9 == NULL )
return - V_195 ;
V_4 = F_126 ( & V_362 -> V_358 ) ;
V_9 -> V_4 = V_4 ;
F_132 ( & V_9 -> V_20 ) ;
V_9 -> V_22 = 1 ;
#ifdef F_133
if ( V_4 -> V_373 == V_374 ) {
V_9 -> V_228 = F_134 ( V_375 ) ;
if ( F_85 ( V_9 -> V_228 ) ) {
F_37 ( L_112 ) ;
V_197 = - V_212 ;
goto V_376;
}
}
#endif
V_372 = F_135 ( V_362 , V_377 , 0 ) ;
if ( ! V_372 ) {
V_197 = - V_378 ;
goto V_376;
}
if ( V_4 -> V_373 == V_379 ) {
if ( ! F_136 ( V_372 -> V_380 , F_137 ( V_372 ) ,
V_351 ) ) {
F_37 ( L_113 , V_362 -> V_36 ) ;
V_197 = - V_381 ;
goto V_376;
}
}
V_46 = F_138 ( V_372 -> V_380 , F_137 ( V_372 ) ) ;
if ( ! V_46 ) {
V_197 = - V_195 ;
goto V_382;
}
V_4 -> V_383 = ( void T_2 * ) V_46 ;
if ( V_4 -> V_384 && V_4 -> V_384 ( V_362 ) ) {
V_197 = - V_212 ;
goto V_385;
}
F_9 ( V_4 ) ;
#ifndef F_39
if ( V_4 -> V_52 )
V_54 = ( void * ) V_46 + V_386 ;
#endif
V_197 = F_139 ( V_362 ) ;
if ( V_197 < 0 )
goto V_385;
V_83 = F_31 ( & V_46 -> V_83 ) ;
if ( ! ( V_83 & V_387 ) ) {
F_37 ( L_114 ) ;
V_197 = - V_212 ;
goto V_388;
}
V_9 -> V_269 = ( V_83 & V_389 ) * 2 ;
V_9 -> V_329 = F_140 ( V_362 , 0 ) ;
if ( ! V_9 -> V_329 ) {
V_197 = - V_212 ;
goto V_388;
}
V_197 = F_141 ( V_9 -> V_329 , F_113 , V_390 ,
V_351 , V_9 ) ;
if ( V_197 != 0 ) {
F_37 ( L_115 ,
V_9 -> V_329 , V_197 ) ;
goto V_388;
}
if ( F_125 ( V_9 , V_362 ) ) {
F_37 ( L_116 ) ;
V_197 = - V_195 ;
goto V_391;
}
if ( F_85 ( V_9 -> V_228 ) ) {
F_29 ( V_9 ) ;
}
V_197 = F_142 ( V_362 ) ;
if ( V_197 )
goto V_391;
V_9 -> V_34 . V_368 = & V_392 ;
V_9 -> V_34 . V_393 = V_313 ;
V_9 -> V_34 . V_280 = & V_9 -> V_234 [ 0 ] . V_15 ;
F_58 ( & V_9 -> V_34 . V_370 ) ;
V_9 -> V_34 . V_148 = V_149 ;
V_9 -> V_34 . V_36 = V_351 ;
F_143 ( & V_9 -> V_34 . V_358 , L_117 ) ;
V_9 -> V_34 . V_358 . V_394 = V_362 -> V_358 . V_394 ;
if ( ! F_85 ( V_9 -> V_228 ) )
V_9 -> V_34 . V_105 = 1 ;
F_48 ( V_9 ) ;
F_129 ( V_9 , 0 , L_118 , 0 ) ;
V_9 -> V_234 [ 0 ] . V_15 . V_141 = & V_395 ;
F_130 ( & V_9 -> V_234 [ 0 ] . V_15 ,
V_136 ) ;
for ( V_304 = 1 ; V_304 < ( int ) ( V_9 -> V_269 / 2 ) ; V_304 ++ ) {
char V_36 [ 14 ] ;
sprintf ( V_36 , L_119 , V_304 ) ;
F_129 ( V_9 , V_304 * 2 , V_36 , 1 ) ;
sprintf ( V_36 , L_120 , V_304 ) ;
F_129 ( V_9 , V_304 * 2 + 1 , V_36 , 1 ) ;
}
V_9 -> V_32 = F_144 ( L_121 , & V_362 -> V_358 ,
sizeof( struct V_23 ) ,
V_396 , V_397 ) ;
if ( V_9 -> V_32 == NULL ) {
V_197 = - V_195 ;
goto V_391;
}
V_197 = F_145 ( & V_362 -> V_358 , & V_9 -> V_34 ,
F_123 ) ;
if ( V_197 )
goto V_398;
F_146 () ;
return 0 ;
V_398:
F_147 ( V_9 -> V_32 ) ;
V_391:
F_148 ( V_9 -> V_329 , V_9 ) ;
V_388:
if ( V_4 -> exit )
V_4 -> exit ( V_362 ) ;
F_149 () ;
V_385:
F_150 ( V_46 ) ;
V_382:
if ( V_4 -> V_373 == V_379 )
F_151 ( V_372 -> V_380 , F_137 ( V_372 ) ) ;
V_376:
F_60 ( V_9 ) ;
V_9 = NULL ;
return V_197 ;
}
static int T_9 F_152 ( struct V_361 * V_362 )
{
struct V_371 * V_372 = F_135 ( V_362 , V_377 , 0 ) ;
struct V_3 * V_4 = F_126 ( & V_362 -> V_358 ) ;
F_153 ( F_16 ) ;
if ( ! V_9 )
return - V_212 ;
V_9 -> F_16 = & F_16 ;
F_154 ( & V_9 -> V_34 ) ;
F_149 () ;
F_155 () ;
F_60 ( V_9 -> V_231 -> V_17 . V_199 ) ;
F_60 ( V_9 -> V_231 ) ;
F_60 ( V_9 -> V_234 ) ;
F_147 ( V_9 -> V_32 ) ;
F_148 ( V_9 -> V_329 , V_9 ) ;
F_150 ( V_46 ) ;
if ( V_4 -> V_373 == V_379 )
F_151 ( V_372 -> V_380 , F_137 ( V_372 ) ) ;
F_156 ( & F_16 ) ;
if ( V_4 -> exit )
V_4 -> exit ( V_362 ) ;
return 0 ;
}
static int F_157 ( struct V_361 * V_362 , T_10 V_399 )
{
F_42 ( V_9 ) ;
return 0 ;
}
static int F_158 ( struct V_361 * V_362 )
{
if ( V_9 -> V_22 ) {
F_29 ( V_9 ) ;
F_41 ( V_9 ) ;
}
V_9 -> V_241 = V_328 ;
V_9 -> V_208 = V_209 ;
V_9 -> V_210 = 0 ;
return 0 ;
}
static int F_159 ( struct V_357 * V_358 , T_10 V_399 )
{
struct V_21 * V_19 = V_9 ;
T_1 V_400 , V_67 ;
V_400 = F_31 ( & V_46 -> V_72 ) & V_73 ;
F_43 ( L_122 , V_104 , V_400 , V_19 -> V_22 ) ;
if ( V_19 -> V_22 ) {
F_43 ( L_123 ) ;
V_19 -> V_401 = 1 ;
return 0 ;
}
if ( V_400 != V_74 ) {
F_43 ( L_124 ) ;
return 0 ;
}
V_67 = F_31 ( & V_46 -> V_67 ) & ~ V_68 ;
F_35 ( V_67 , & V_46 -> V_67 ) ;
V_19 -> V_22 = 1 ;
F_160 ( L_125 ) ;
return 0 ;
}
static int F_161 ( struct V_357 * V_358 )
{
F_43 ( L_126 , V_104 ,
V_9 -> V_22 , V_9 -> V_401 ) ;
if ( V_9 -> V_401 ) {
V_9 -> V_401 = 0 ;
F_43 ( L_127 ) ;
return 0 ;
}
F_160 ( L_128 ) ;
return F_158 ( NULL ) ;
}
