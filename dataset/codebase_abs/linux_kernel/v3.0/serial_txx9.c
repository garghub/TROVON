static inline unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
switch ( V_2 -> V_4 . V_5 ) {
default:
return F_2 ( V_2 -> V_4 . V_6 + V_3 ) ;
case V_7 :
return F_3 ( V_2 -> V_4 . V_8 + V_3 ) ;
}
}
static inline void
F_4 ( struct V_1 * V_2 , int V_3 , int V_9 )
{
switch ( V_2 -> V_4 . V_5 ) {
default:
F_5 ( V_9 , V_2 -> V_4 . V_6 + V_3 ) ;
break;
case V_7 :
F_6 ( V_9 , V_2 -> V_4 . V_8 + V_3 ) ;
break;
}
}
static inline void
F_7 ( struct V_1 * V_2 , int V_3 , unsigned int V_9 )
{
F_4 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) & ~ V_9 ) ;
}
static inline void
F_8 ( struct V_1 * V_2 , int V_3 , unsigned int V_9 )
{
F_4 ( V_2 , V_3 , F_1 ( V_2 , V_3 ) | V_9 ) ;
}
static inline void
F_9 ( struct V_1 * V_2 , int V_10 )
{
V_10 >>= 1 ;
if ( V_10 < 256 )
F_4 ( V_2 , V_11 , V_10 | V_12 ) ;
else if ( V_10 < ( 256 << 2 ) )
F_4 ( V_2 , V_11 , ( V_10 >> 2 ) | V_13 ) ;
else if ( V_10 < ( 256 << 4 ) )
F_4 ( V_2 , V_11 , ( V_10 >> 4 ) | V_14 ) ;
else if ( V_10 < ( 256 << 6 ) )
F_4 ( V_2 , V_11 , ( V_10 >> 6 ) | V_15 ) ;
else
F_4 ( V_2 , V_11 , 0xff | V_15 ) ;
}
static struct V_1 * F_10 ( struct V_16 * V_4 )
{
return F_11 ( V_4 , struct V_1 , V_4 ) ;
}
static void F_12 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_7 ( V_2 , V_17 , V_18 ) ;
}
static void F_13 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_8 ( V_2 , V_17 , V_18 ) ;
}
static void F_14 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
V_2 -> V_4 . V_19 &= ~ V_20 ;
}
static void F_15 ( struct V_16 * V_4 )
{
}
static void F_16 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned int V_21 = 10000 ;
F_4 ( V_2 , V_22 , V_23 ) ;
F_17 () ;
F_18 ( 1 ) ;
while ( ( F_1 ( V_2 , V_22 ) & V_23 ) && -- V_21 )
F_18 ( 1 ) ;
F_8 ( V_2 , V_22 ,
V_24 | V_25 ) ;
F_4 ( V_2 , V_26 ,
V_27 | V_28 |
( ( V_2 -> V_4 . V_29 & V_30 ) ?
V_31 : V_32 ) ) ;
F_9 ( V_2 , F_19 ( V_4 , 9600 ) ) ;
F_4 ( V_2 , V_33 , V_34 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
}
static inline void
F_20 ( struct V_1 * V_2 , unsigned int * V_35 )
{
struct V_36 * V_37 = V_2 -> V_4 . V_38 -> V_4 . V_37 ;
unsigned char V_39 ;
unsigned int V_40 = * V_35 ;
int V_41 = 256 ;
char V_42 ;
unsigned int V_43 ;
do {
V_39 = F_1 ( V_2 , V_44 ) ;
V_42 = V_45 ;
V_2 -> V_4 . V_46 . V_47 ++ ;
V_43 =
V_2 -> V_4 . V_48 & ~ V_49 ;
if ( F_21 ( V_40 & ( V_50 | V_51 |
V_52 | V_53 ) ) ) {
if ( V_40 & V_50 ) {
V_40 &= ~ ( V_52 | V_51 ) ;
V_2 -> V_4 . V_46 . V_54 ++ ;
if ( F_22 ( & V_2 -> V_4 ) )
goto V_55;
} else if ( V_40 & V_51 )
V_2 -> V_4 . V_46 . V_56 ++ ;
else if ( V_40 & V_52 )
V_2 -> V_4 . V_46 . V_57 ++ ;
if ( V_40 & V_53 ) {
V_2 -> V_4 . V_46 . V_58 ++ ;
V_43 |=
V_49 ;
}
V_40 &= V_2 -> V_4 . V_19 ;
if ( V_40 & V_50 ) {
V_42 = V_59 ;
} else if ( V_40 & V_51 )
V_42 = V_60 ;
else if ( V_40 & V_52 )
V_42 = V_61 ;
}
if ( F_23 ( & V_2 -> V_4 , V_39 ) )
goto V_55;
F_24 ( & V_2 -> V_4 , V_40 , V_53 , V_39 , V_42 ) ;
V_55:
V_2 -> V_4 . V_48 = V_43 ;
V_40 = F_1 ( V_2 , V_62 ) ;
} while ( ! ( V_40 & V_63 ) && ( V_41 -- > 0 ) );
F_25 ( & V_2 -> V_4 . V_64 ) ;
F_26 ( V_37 ) ;
F_27 ( & V_2 -> V_4 . V_64 ) ;
* V_35 = V_40 ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
struct V_65 * V_66 = & V_2 -> V_4 . V_38 -> V_66 ;
int V_67 ;
if ( V_2 -> V_4 . V_68 ) {
F_4 ( V_2 , V_69 , V_2 -> V_4 . V_68 ) ;
V_2 -> V_4 . V_46 . V_70 ++ ;
V_2 -> V_4 . V_68 = 0 ;
return;
}
if ( F_29 ( V_66 ) || F_30 ( & V_2 -> V_4 ) ) {
F_12 ( & V_2 -> V_4 ) ;
return;
}
V_67 = V_71 ;
do {
F_4 ( V_2 , V_69 , V_66 -> V_72 [ V_66 -> V_73 ] ) ;
V_66 -> V_73 = ( V_66 -> V_73 + 1 ) & ( V_74 - 1 ) ;
V_2 -> V_4 . V_46 . V_70 ++ ;
if ( F_29 ( V_66 ) )
break;
} while ( -- V_67 > 0 );
if ( F_31 ( V_66 ) < V_75 )
F_32 ( & V_2 -> V_4 ) ;
if ( F_29 ( V_66 ) )
F_12 ( & V_2 -> V_4 ) ;
}
static T_1 F_33 ( int V_76 , void * V_77 )
{
int V_78 = 0 ;
struct V_1 * V_2 = V_77 ;
unsigned int V_35 ;
while ( 1 ) {
F_27 ( & V_2 -> V_4 . V_64 ) ;
V_35 = F_1 ( V_2 , V_62 ) ;
if ( ! ( F_1 ( V_2 , V_17 ) & V_18 ) )
V_35 &= ~ V_79 ;
if ( ! ( V_35 & ( V_79 | V_20 |
V_80 ) ) ) {
F_25 ( & V_2 -> V_4 . V_64 ) ;
break;
}
if ( V_35 & V_20 )
F_20 ( V_2 , & V_35 ) ;
if ( V_35 & V_79 )
F_28 ( V_2 ) ;
F_7 ( V_2 , V_62 ,
V_79 | V_20 |
V_80 ) ;
F_25 ( & V_2 -> V_4 . V_64 ) ;
if ( V_78 ++ > V_81 )
break;
}
return V_78 ? V_82 : V_83 ;
}
static unsigned int F_34 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
unsigned int V_84 ;
F_35 ( & V_2 -> V_4 . V_64 , V_29 ) ;
V_84 = ( F_1 ( V_2 , V_85 ) & V_86 ) ? V_87 : 0 ;
F_36 ( & V_2 -> V_4 . V_64 , V_29 ) ;
return V_84 ;
}
static unsigned int F_37 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned int V_84 ;
V_84 = V_88 | V_89 ;
V_84 |= ( F_1 ( V_2 , V_33 ) & V_90 ) ? 0 : V_91 ;
V_84 |= ( F_1 ( V_2 , V_85 ) & V_92 ) ? 0 : V_93 ;
return V_84 ;
}
static void F_38 ( struct V_16 * V_4 , unsigned int V_94 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_94 & V_91 )
F_7 ( V_2 , V_33 , V_90 ) ;
else
F_8 ( V_2 , V_33 , V_90 ) ;
}
static void F_39 ( struct V_16 * V_4 , int V_95 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
F_35 ( & V_2 -> V_4 . V_64 , V_29 ) ;
if ( V_95 == - 1 )
F_8 ( V_2 , V_33 , V_96 ) ;
else
F_7 ( V_2 , V_33 , V_96 ) ;
F_36 ( & V_2 -> V_4 . V_64 , V_29 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_21 = 10000 ;
while ( -- V_21 &&
! ( F_1 ( V_2 , V_85 ) & V_86 ) )
F_18 ( 1 ) ;
if ( V_2 -> V_4 . V_29 & V_97 ) {
V_21 = 1000000 ;
while ( -- V_21 &&
( F_1 ( V_2 , V_85 ) & V_92 ) )
F_18 ( 1 ) ;
}
}
static int F_41 ( struct V_16 * V_4 )
{
unsigned int V_98 ;
unsigned char V_99 ;
struct V_1 * V_2 = F_10 ( V_4 ) ;
V_98 = F_1 ( V_2 , V_17 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
while ( F_1 ( V_2 , V_62 ) & V_63 )
;
V_99 = F_1 ( V_2 , V_44 ) ;
F_7 ( V_2 , V_62 , V_20 ) ;
F_4 ( V_2 , V_17 , V_98 ) ;
return V_99 ;
}
static void F_42 ( struct V_16 * V_4 , unsigned char V_99 )
{
unsigned int V_98 ;
struct V_1 * V_2 = F_10 ( V_4 ) ;
V_98 = F_1 ( V_2 , V_17 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_69 , V_99 ) ;
if ( V_99 == 10 ) {
F_40 ( V_2 ) ;
F_4 ( V_2 , V_69 , 13 ) ;
}
F_40 ( V_2 ) ;
F_4 ( V_2 , V_17 , V_98 ) ;
}
static int F_43 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
int V_100 ;
F_8 ( V_2 , V_22 ,
V_101 | V_102 | V_103 ) ;
F_7 ( V_2 , V_22 ,
V_101 | V_102 | V_103 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
F_4 ( V_2 , V_62 , 0 ) ;
V_100 = F_44 ( V_2 -> V_4 . V_76 , F_33 ,
V_104 , L_1 , V_2 ) ;
if ( V_100 )
return V_100 ;
F_35 ( & V_2 -> V_4 . V_64 , V_29 ) ;
F_38 ( & V_2 -> V_4 , V_2 -> V_4 . V_94 ) ;
F_36 ( & V_2 -> V_4 . V_64 , V_29 ) ;
F_7 ( V_2 , V_33 , V_105 | V_106 ) ;
F_8 ( V_2 , V_17 , V_107 ) ;
return 0 ;
}
static void F_45 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
F_4 ( V_2 , V_17 , 0 ) ;
F_35 ( & V_2 -> V_4 . V_64 , V_29 ) ;
F_38 ( & V_2 -> V_4 , V_2 -> V_4 . V_94 ) ;
F_36 ( & V_2 -> V_4 . V_64 , V_29 ) ;
F_7 ( V_2 , V_33 , V_96 ) ;
#ifdef F_46
if ( V_2 -> V_4 . V_108 && V_2 -> V_4 . line == V_2 -> V_4 . V_108 -> V_109 ) {
F_47 ( V_2 -> V_4 . V_76 , V_2 ) ;
return;
}
#endif
F_8 ( V_2 , V_22 ,
V_101 | V_102 | V_103 ) ;
F_7 ( V_2 , V_22 ,
V_101 | V_102 | V_103 ) ;
F_8 ( V_2 , V_33 , V_105 | V_106 ) ;
F_47 ( V_2 -> V_4 . V_76 , V_2 ) ;
}
static void
F_48 ( struct V_16 * V_4 , struct V_110 * V_111 ,
struct V_110 * V_112 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned int V_113 , V_114 = 0 ;
unsigned long V_29 ;
unsigned int V_115 , V_10 ;
V_111 -> V_116 &= ~ ( V_117 | V_118 ) ;
V_111 -> V_116 |= V_119 ;
V_113 = F_1 ( V_2 , V_26 ) ;
V_113 &= ~ V_120 ;
switch ( V_111 -> V_116 & V_121 ) {
case V_122 :
V_113 |= V_123 ;
break;
default:
case V_124 :
case V_125 :
case V_126 :
V_113 |= V_27 ;
break;
}
V_113 &= ~ V_127 ;
if ( V_111 -> V_116 & V_128 )
V_113 |= V_129 ;
else
V_113 |= V_28 ;
V_113 &= ~ ( V_130 | V_131 ) ;
if ( V_111 -> V_116 & V_132 )
V_113 |= V_130 ;
if ( ! ( V_111 -> V_116 & V_133 ) )
V_113 |= V_131 ;
V_115 = F_49 ( V_4 , V_111 , V_112 , 0 , V_4 -> V_134 / 16 / 2 ) ;
V_10 = F_19 ( V_4 , V_115 ) ;
V_114 = V_24 | V_25 ;
F_35 ( & V_2 -> V_4 . V_64 , V_29 ) ;
F_50 ( V_4 , V_111 -> V_116 , V_115 ) ;
V_2 -> V_4 . V_19 = V_53 |
V_79 | V_20 ;
if ( V_111 -> V_135 & V_136 )
V_2 -> V_4 . V_19 |= V_52 | V_51 ;
if ( V_111 -> V_135 & ( V_137 | V_138 ) )
V_2 -> V_4 . V_19 |= V_50 ;
V_2 -> V_4 . V_48 = 0 ;
if ( V_111 -> V_135 & V_139 )
V_2 -> V_4 . V_48 |= V_51 | V_52 ;
if ( V_111 -> V_135 & V_140 ) {
V_2 -> V_4 . V_48 |= V_50 ;
if ( V_111 -> V_135 & V_139 )
V_2 -> V_4 . V_48 |= V_53 ;
}
if ( ( V_111 -> V_116 & V_141 ) == 0 )
V_2 -> V_4 . V_48 |= V_20 ;
if ( ( V_111 -> V_116 & V_142 ) &&
( V_2 -> V_4 . V_29 & V_143 ) ) {
F_8 ( V_2 , V_33 ,
V_144 | V_145 ) ;
} else {
F_7 ( V_2 , V_33 ,
V_144 | V_145 ) ;
}
F_4 ( V_2 , V_26 , V_113 ) ;
F_9 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_22 , V_114 ) ;
F_38 ( & V_2 -> V_4 , V_2 -> V_4 . V_94 ) ;
F_36 ( & V_2 -> V_4 . V_64 , V_29 ) ;
}
static void
F_51 ( struct V_16 * V_4 , unsigned int V_38 ,
unsigned int V_146 )
{
if ( V_38 == 0 && V_146 != - 1 )
F_16 ( V_4 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned int V_147 = V_148 ;
int V_84 = 0 ;
switch ( V_2 -> V_4 . V_5 ) {
default:
if ( ! V_2 -> V_4 . V_149 )
break;
if ( ! F_53 ( V_2 -> V_4 . V_149 , V_147 , L_1 ) ) {
V_84 = - V_150 ;
break;
}
if ( V_2 -> V_4 . V_29 & V_151 ) {
V_2 -> V_4 . V_6 = F_54 ( V_2 -> V_4 . V_149 , V_147 ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_55 ( V_2 -> V_4 . V_149 , V_147 ) ;
V_84 = - V_152 ;
}
}
break;
case V_7 :
if ( ! F_56 ( V_2 -> V_4 . V_8 , V_147 , L_1 ) )
V_84 = - V_150 ;
break;
}
return V_84 ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned int V_147 = V_148 ;
switch ( V_2 -> V_4 . V_5 ) {
default:
if ( ! V_2 -> V_4 . V_149 )
break;
if ( V_2 -> V_4 . V_29 & V_151 ) {
F_58 ( V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_6 = NULL ;
}
F_55 ( V_2 -> V_4 . V_149 , V_147 ) ;
break;
case V_7 :
F_59 ( V_2 -> V_4 . V_8 , V_147 ) ;
break;
}
}
static void F_60 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_57 ( V_2 ) ;
}
static int F_61 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
return F_52 ( V_2 ) ;
}
static void F_62 ( struct V_16 * V_4 , int V_153 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
int V_84 ;
V_84 = F_52 ( V_2 ) ;
if ( V_84 < 0 )
return;
V_4 -> type = V_154 ;
V_2 -> V_4 . V_155 = V_71 ;
#ifdef F_46
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_108 -> V_109 )
return;
#endif
F_16 ( V_4 ) ;
}
static const char *
F_63 ( struct V_16 * V_4 )
{
return L_2 ;
}
static void T_2 F_64 ( struct V_156 * V_157 ,
struct V_158 * V_159 )
{
int V_160 ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
struct V_1 * V_2 = & V_162 [ V_160 ] ;
V_2 -> V_4 . line = V_160 ;
V_2 -> V_4 . V_163 = & V_164 ;
V_2 -> V_4 . V_159 = V_159 ;
if ( V_2 -> V_4 . V_8 || V_2 -> V_4 . V_149 )
F_65 ( V_157 , & V_2 -> V_4 ) ;
}
}
static void F_66 ( struct V_16 * V_4 , int V_39 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_69 , V_39 ) ;
}
static void
F_67 ( struct V_165 * V_166 , const char * V_167 , unsigned int V_67 )
{
struct V_1 * V_2 = & V_162 [ V_166 -> V_109 ] ;
unsigned int V_98 , V_168 ;
V_98 = F_1 ( V_2 , V_17 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
V_168 = F_1 ( V_2 , V_33 ) ;
if ( ! ( V_2 -> V_4 . V_29 & V_97 ) && ( V_168 & V_145 ) )
F_4 ( V_2 , V_33 , V_168 & ~ V_145 ) ;
F_68 ( & V_2 -> V_4 , V_167 , V_67 , F_66 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_33 , V_168 ) ;
F_4 ( V_2 , V_17 , V_98 ) ;
}
static int T_2 F_69 ( struct V_165 * V_166 , char * V_169 )
{
struct V_16 * V_4 ;
struct V_1 * V_2 ;
int V_115 = 9600 ;
int V_170 = 8 ;
int V_56 = 'n' ;
int V_171 = 'n' ;
if ( V_166 -> V_109 >= V_161 )
V_166 -> V_109 = 0 ;
V_2 = & V_162 [ V_166 -> V_109 ] ;
V_4 = & V_2 -> V_4 ;
if ( ! V_4 -> V_163 )
return - V_172 ;
F_16 ( & V_2 -> V_4 ) ;
if ( V_169 )
F_70 ( V_169 , & V_115 , & V_56 , & V_170 , & V_171 ) ;
return F_71 ( V_4 , V_166 , V_115 , V_56 , V_170 , V_171 ) ;
}
static int T_2 F_72 ( void )
{
F_73 ( & V_173 ) ;
return 0 ;
}
int T_2 F_74 ( struct V_16 * V_4 )
{
if ( V_4 -> line >= F_75 ( V_162 ) )
return - V_172 ;
V_162 [ V_4 -> line ] . V_4 = * V_4 ;
V_162 [ V_4 -> line ] . V_4 . V_163 = & V_164 ;
V_162 [ V_4 -> line ] . V_4 . V_29 |=
V_174 | V_175 ;
return 0 ;
}
static int T_3 F_76 ( struct V_16 * V_4 )
{
int V_160 ;
struct V_1 * V_176 ;
int V_84 = - V_177 ;
F_77 ( & V_178 ) ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
V_176 = & V_162 [ V_160 ] ;
if ( F_78 ( & V_176 -> V_4 , V_4 ) ) {
F_79 ( & V_179 , & V_176 -> V_4 ) ;
break;
}
}
if ( V_160 == V_161 ) {
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
V_176 = & V_162 [ V_160 ] ;
if ( ! ( V_176 -> V_4 . V_8 || V_176 -> V_4 . V_149 ) )
break;
}
}
if ( V_160 < V_161 ) {
V_176 -> V_4 . V_8 = V_4 -> V_8 ;
V_176 -> V_4 . V_6 = V_4 -> V_6 ;
V_176 -> V_4 . V_76 = V_4 -> V_76 ;
V_176 -> V_4 . V_134 = V_4 -> V_134 ;
V_176 -> V_4 . V_5 = V_4 -> V_5 ;
V_176 -> V_4 . V_29 = V_4 -> V_29
| V_174 | V_175 ;
V_176 -> V_4 . V_149 = V_4 -> V_149 ;
if ( V_4 -> V_159 )
V_176 -> V_4 . V_159 = V_4 -> V_159 ;
V_84 = F_65 ( & V_179 , & V_176 -> V_4 ) ;
if ( V_84 == 0 )
V_84 = V_176 -> V_4 . line ;
}
F_80 ( & V_178 ) ;
return V_84 ;
}
static void T_4 F_81 ( int line )
{
struct V_1 * V_176 = & V_162 [ line ] ;
F_77 ( & V_178 ) ;
F_79 ( & V_179 , & V_176 -> V_4 ) ;
V_176 -> V_4 . V_29 = 0 ;
V_176 -> V_4 . type = V_180 ;
V_176 -> V_4 . V_8 = 0 ;
V_176 -> V_4 . V_149 = 0 ;
V_176 -> V_4 . V_6 = NULL ;
V_176 -> V_4 . V_159 = NULL ;
F_80 ( & V_178 ) ;
}
static int T_3 F_82 ( struct V_181 * V_159 )
{
struct V_16 * V_182 = V_159 -> V_159 . V_183 ;
struct V_16 V_4 ;
int V_84 , V_160 ;
memset ( & V_4 , 0 , sizeof( struct V_16 ) ) ;
for ( V_160 = 0 ; V_182 && V_182 -> V_134 != 0 ; V_182 ++ , V_160 ++ ) {
V_4 . V_8 = V_182 -> V_8 ;
V_4 . V_6 = V_182 -> V_6 ;
V_4 . V_76 = V_182 -> V_76 ;
V_4 . V_134 = V_182 -> V_134 ;
V_4 . V_5 = V_182 -> V_5 ;
V_4 . V_29 = V_182 -> V_29 ;
V_4 . V_149 = V_182 -> V_149 ;
V_4 . V_159 = & V_159 -> V_159 ;
V_84 = F_76 ( & V_4 ) ;
if ( V_84 < 0 ) {
F_83 ( & V_159 -> V_159 , L_3
L_4 , V_160 ,
V_182 -> V_8 , ( unsigned long long ) V_182 -> V_149 ,
V_182 -> V_76 , V_84 ) ;
}
}
return 0 ;
}
static int T_4 F_84 ( struct V_181 * V_159 )
{
int V_160 ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
struct V_1 * V_2 = & V_162 [ V_160 ] ;
if ( V_2 -> V_4 . V_159 == & V_159 -> V_159 )
F_81 ( V_160 ) ;
}
return 0 ;
}
static int F_85 ( struct V_181 * V_159 , T_5 V_38 )
{
int V_160 ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
struct V_1 * V_2 = & V_162 [ V_160 ] ;
if ( V_2 -> V_4 . type != V_180 && V_2 -> V_4 . V_159 == & V_159 -> V_159 )
F_86 ( & V_179 , & V_2 -> V_4 ) ;
}
return 0 ;
}
static int F_87 ( struct V_181 * V_159 )
{
int V_160 ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
struct V_1 * V_2 = & V_162 [ V_160 ] ;
if ( V_2 -> V_4 . type != V_180 && V_2 -> V_4 . V_159 == & V_159 -> V_159 )
F_88 ( & V_179 , & V_2 -> V_4 ) ;
}
return 0 ;
}
static int T_3
F_89 ( struct V_184 * V_159 , const struct V_185 * V_186 )
{
struct V_16 V_4 ;
int line ;
int V_187 ;
V_187 = F_90 ( V_159 ) ;
if ( V_187 )
return V_187 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_163 = & V_164 ;
V_4 . V_29 |= V_143 ;
V_4 . V_134 = 66670000 ;
V_4 . V_76 = V_159 -> V_76 ;
V_4 . V_5 = V_7 ;
V_4 . V_8 = F_91 ( V_159 , 1 ) ;
V_4 . V_159 = & V_159 -> V_159 ;
line = F_76 ( & V_4 ) ;
if ( line < 0 ) {
F_92 ( V_188 L_5 , F_93 ( V_159 ) , line ) ;
F_94 ( V_159 ) ;
return line ;
}
F_95 ( V_159 , & V_162 [ line ] ) ;
return 0 ;
}
static void T_4 F_96 ( struct V_184 * V_159 )
{
struct V_1 * V_2 = F_97 ( V_159 ) ;
F_95 ( V_159 , NULL ) ;
if ( V_2 ) {
F_81 ( V_2 -> V_4 . line ) ;
F_94 ( V_159 ) ;
}
}
static int F_98 ( struct V_184 * V_159 , T_5 V_38 )
{
struct V_1 * V_2 = F_97 ( V_159 ) ;
if ( V_2 )
F_86 ( & V_179 , & V_2 -> V_4 ) ;
F_99 ( V_159 ) ;
F_100 ( V_159 , F_101 ( V_159 , V_38 ) ) ;
return 0 ;
}
static int F_102 ( struct V_184 * V_159 )
{
struct V_1 * V_2 = F_97 ( V_159 ) ;
F_100 ( V_159 , V_189 ) ;
F_103 ( V_159 ) ;
if ( V_2 )
F_88 ( & V_179 , & V_2 -> V_4 ) ;
return 0 ;
}
static int T_2 F_104 ( void )
{
int V_84 ;
F_92 ( V_190 L_6 , V_191 , V_192 ) ;
V_84 = F_105 ( & V_179 ) ;
if ( V_84 )
goto V_193;
V_194 = F_106 ( L_1 , - 1 ) ;
if ( ! V_194 ) {
V_84 = - V_152 ;
goto V_195;
}
V_84 = F_107 ( V_194 ) ;
if ( V_84 )
goto V_196;
F_64 ( & V_179 ,
& V_194 -> V_159 ) ;
V_84 = F_108 ( & V_197 ) ;
if ( V_84 )
goto V_198;
#ifdef F_109
V_84 = F_110 ( & V_199 ) ;
#endif
if ( V_84 == 0 )
goto V_193;
V_198:
F_111 ( V_194 ) ;
V_196:
F_112 ( V_194 ) ;
V_195:
F_113 ( & V_179 ) ;
V_193:
return V_84 ;
}
static void T_6 F_114 ( void )
{
int V_160 ;
#ifdef F_109
F_115 ( & V_199 ) ;
#endif
F_116 ( & V_197 ) ;
F_117 ( V_194 ) ;
for ( V_160 = 0 ; V_160 < V_161 ; V_160 ++ ) {
struct V_1 * V_2 = & V_162 [ V_160 ] ;
if ( V_2 -> V_4 . V_8 || V_2 -> V_4 . V_149 )
F_79 ( & V_179 , & V_2 -> V_4 ) ;
}
F_113 ( & V_179 ) ;
}
