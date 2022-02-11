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
unsigned char V_36 ;
unsigned int V_37 = * V_35 ;
int V_38 = 256 ;
char V_39 ;
unsigned int V_40 ;
do {
V_36 = F_1 ( V_2 , V_41 ) ;
V_39 = V_42 ;
V_2 -> V_4 . V_43 . V_44 ++ ;
V_40 =
V_2 -> V_4 . V_45 & ~ V_46 ;
if ( F_21 ( V_37 & ( V_47 | V_48 |
V_49 | V_50 ) ) ) {
if ( V_37 & V_47 ) {
V_37 &= ~ ( V_49 | V_48 ) ;
V_2 -> V_4 . V_43 . V_51 ++ ;
if ( F_22 ( & V_2 -> V_4 ) )
goto V_52;
} else if ( V_37 & V_48 )
V_2 -> V_4 . V_43 . V_53 ++ ;
else if ( V_37 & V_49 )
V_2 -> V_4 . V_43 . V_54 ++ ;
if ( V_37 & V_50 ) {
V_2 -> V_4 . V_43 . V_55 ++ ;
V_40 |=
V_46 ;
}
V_37 &= V_2 -> V_4 . V_19 ;
if ( V_37 & V_47 ) {
V_39 = V_56 ;
} else if ( V_37 & V_48 )
V_39 = V_57 ;
else if ( V_37 & V_49 )
V_39 = V_58 ;
}
if ( F_23 ( & V_2 -> V_4 , V_36 ) )
goto V_52;
F_24 ( & V_2 -> V_4 , V_37 , V_50 , V_36 , V_39 ) ;
V_52:
V_2 -> V_4 . V_45 = V_40 ;
V_37 = F_1 ( V_2 , V_59 ) ;
} while ( ! ( V_37 & V_60 ) && ( V_38 -- > 0 ) );
F_25 ( & V_2 -> V_4 . V_61 ) ;
F_26 ( & V_2 -> V_4 . V_62 -> V_4 ) ;
F_27 ( & V_2 -> V_4 . V_61 ) ;
* V_35 = V_37 ;
}
static inline void F_28 ( struct V_1 * V_2 )
{
struct V_63 * V_64 = & V_2 -> V_4 . V_62 -> V_64 ;
int V_65 ;
if ( V_2 -> V_4 . V_66 ) {
F_4 ( V_2 , V_67 , V_2 -> V_4 . V_66 ) ;
V_2 -> V_4 . V_43 . V_68 ++ ;
V_2 -> V_4 . V_66 = 0 ;
return;
}
if ( F_29 ( V_64 ) || F_30 ( & V_2 -> V_4 ) ) {
F_12 ( & V_2 -> V_4 ) ;
return;
}
V_65 = V_69 ;
do {
F_4 ( V_2 , V_67 , V_64 -> V_70 [ V_64 -> V_71 ] ) ;
V_64 -> V_71 = ( V_64 -> V_71 + 1 ) & ( V_72 - 1 ) ;
V_2 -> V_4 . V_43 . V_68 ++ ;
if ( F_29 ( V_64 ) )
break;
} while ( -- V_65 > 0 );
if ( F_31 ( V_64 ) < V_73 )
F_32 ( & V_2 -> V_4 ) ;
if ( F_29 ( V_64 ) )
F_12 ( & V_2 -> V_4 ) ;
}
static T_1 F_33 ( int V_74 , void * V_75 )
{
int V_76 = 0 ;
struct V_1 * V_2 = V_75 ;
unsigned int V_35 ;
while ( 1 ) {
F_27 ( & V_2 -> V_4 . V_61 ) ;
V_35 = F_1 ( V_2 , V_59 ) ;
if ( ! ( F_1 ( V_2 , V_17 ) & V_18 ) )
V_35 &= ~ V_77 ;
if ( ! ( V_35 & ( V_77 | V_20 |
V_78 ) ) ) {
F_25 ( & V_2 -> V_4 . V_61 ) ;
break;
}
if ( V_35 & V_20 )
F_20 ( V_2 , & V_35 ) ;
if ( V_35 & V_77 )
F_28 ( V_2 ) ;
F_7 ( V_2 , V_59 ,
V_77 | V_20 |
V_78 ) ;
F_25 ( & V_2 -> V_4 . V_61 ) ;
if ( V_76 ++ > V_79 )
break;
}
return V_76 ? V_80 : V_81 ;
}
static unsigned int F_34 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
unsigned int V_82 ;
F_35 ( & V_2 -> V_4 . V_61 , V_29 ) ;
V_82 = ( F_1 ( V_2 , V_83 ) & V_84 ) ? V_85 : 0 ;
F_36 ( & V_2 -> V_4 . V_61 , V_29 ) ;
return V_82 ;
}
static unsigned int F_37 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned int V_82 ;
V_82 = V_86 | V_87 ;
V_82 |= ( F_1 ( V_2 , V_33 ) & V_88 ) ? 0 : V_89 ;
V_82 |= ( F_1 ( V_2 , V_83 ) & V_90 ) ? 0 : V_91 ;
return V_82 ;
}
static void F_38 ( struct V_16 * V_4 , unsigned int V_92 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
if ( V_92 & V_89 )
F_7 ( V_2 , V_33 , V_88 ) ;
else
F_8 ( V_2 , V_33 , V_88 ) ;
}
static void F_39 ( struct V_16 * V_4 , int V_93 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
F_35 ( & V_2 -> V_4 . V_61 , V_29 ) ;
if ( V_93 == - 1 )
F_8 ( V_2 , V_33 , V_94 ) ;
else
F_7 ( V_2 , V_33 , V_94 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_29 ) ;
}
static void F_40 ( struct V_1 * V_2 )
{
unsigned int V_21 = 10000 ;
while ( -- V_21 &&
! ( F_1 ( V_2 , V_83 ) & V_84 ) )
F_18 ( 1 ) ;
if ( V_2 -> V_4 . V_29 & V_95 ) {
V_21 = 1000000 ;
while ( -- V_21 &&
( F_1 ( V_2 , V_83 ) & V_90 ) )
F_18 ( 1 ) ;
}
}
static int F_41 ( struct V_16 * V_4 )
{
unsigned int V_96 ;
unsigned char V_97 ;
struct V_1 * V_2 = F_10 ( V_4 ) ;
V_96 = F_1 ( V_2 , V_17 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
while ( F_1 ( V_2 , V_59 ) & V_60 )
;
V_97 = F_1 ( V_2 , V_41 ) ;
F_7 ( V_2 , V_59 , V_20 ) ;
F_4 ( V_2 , V_17 , V_96 ) ;
return V_97 ;
}
static void F_42 ( struct V_16 * V_4 , unsigned char V_97 )
{
unsigned int V_96 ;
struct V_1 * V_2 = F_10 ( V_4 ) ;
V_96 = F_1 ( V_2 , V_17 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_67 , V_97 ) ;
if ( V_97 == 10 ) {
F_40 ( V_2 ) ;
F_4 ( V_2 , V_67 , 13 ) ;
}
F_40 ( V_2 ) ;
F_4 ( V_2 , V_17 , V_96 ) ;
}
static int F_43 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
int V_98 ;
F_8 ( V_2 , V_22 ,
V_99 | V_100 | V_101 ) ;
F_7 ( V_2 , V_22 ,
V_99 | V_100 | V_101 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
F_4 ( V_2 , V_59 , 0 ) ;
V_98 = F_44 ( V_2 -> V_4 . V_74 , F_33 ,
V_102 , L_1 , V_2 ) ;
if ( V_98 )
return V_98 ;
F_35 ( & V_2 -> V_4 . V_61 , V_29 ) ;
F_38 ( & V_2 -> V_4 , V_2 -> V_4 . V_92 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_29 ) ;
F_7 ( V_2 , V_33 , V_103 | V_104 ) ;
F_8 ( V_2 , V_17 , V_105 ) ;
return 0 ;
}
static void F_45 ( struct V_16 * V_4 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned long V_29 ;
F_4 ( V_2 , V_17 , 0 ) ;
F_35 ( & V_2 -> V_4 . V_61 , V_29 ) ;
F_38 ( & V_2 -> V_4 , V_2 -> V_4 . V_92 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_29 ) ;
F_7 ( V_2 , V_33 , V_94 ) ;
#ifdef F_46
if ( V_2 -> V_4 . V_106 && V_2 -> V_4 . line == V_2 -> V_4 . V_106 -> V_107 ) {
F_47 ( V_2 -> V_4 . V_74 , V_2 ) ;
return;
}
#endif
F_8 ( V_2 , V_22 ,
V_99 | V_100 | V_101 ) ;
F_7 ( V_2 , V_22 ,
V_99 | V_100 | V_101 ) ;
F_8 ( V_2 , V_33 , V_103 | V_104 ) ;
F_47 ( V_2 -> V_4 . V_74 , V_2 ) ;
}
static void
F_48 ( struct V_16 * V_4 , struct V_108 * V_109 ,
struct V_108 * V_110 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
unsigned int V_111 , V_112 = 0 ;
unsigned long V_29 ;
unsigned int V_113 , V_10 ;
V_109 -> V_114 &= ~ ( V_115 | V_116 ) ;
V_109 -> V_114 |= V_117 ;
V_111 = F_1 ( V_2 , V_26 ) ;
V_111 &= ~ V_118 ;
switch ( V_109 -> V_114 & V_119 ) {
case V_120 :
V_111 |= V_121 ;
break;
default:
case V_122 :
case V_123 :
case V_124 :
V_111 |= V_27 ;
break;
}
V_111 &= ~ V_125 ;
if ( V_109 -> V_114 & V_126 )
V_111 |= V_127 ;
else
V_111 |= V_28 ;
V_111 &= ~ ( V_128 | V_129 ) ;
if ( V_109 -> V_114 & V_130 )
V_111 |= V_128 ;
if ( ! ( V_109 -> V_114 & V_131 ) )
V_111 |= V_129 ;
V_113 = F_49 ( V_4 , V_109 , V_110 , 0 , V_4 -> V_132 / 16 / 2 ) ;
V_10 = F_19 ( V_4 , V_113 ) ;
V_112 = V_24 | V_25 ;
F_35 ( & V_2 -> V_4 . V_61 , V_29 ) ;
F_50 ( V_4 , V_109 -> V_114 , V_113 ) ;
V_2 -> V_4 . V_19 = V_50 |
V_77 | V_20 ;
if ( V_109 -> V_133 & V_134 )
V_2 -> V_4 . V_19 |= V_49 | V_48 ;
if ( V_109 -> V_133 & ( V_135 | V_136 ) )
V_2 -> V_4 . V_19 |= V_47 ;
V_2 -> V_4 . V_45 = 0 ;
if ( V_109 -> V_133 & V_137 )
V_2 -> V_4 . V_45 |= V_48 | V_49 ;
if ( V_109 -> V_133 & V_138 ) {
V_2 -> V_4 . V_45 |= V_47 ;
if ( V_109 -> V_133 & V_137 )
V_2 -> V_4 . V_45 |= V_50 ;
}
if ( ( V_109 -> V_114 & V_139 ) == 0 )
V_2 -> V_4 . V_45 |= V_20 ;
if ( ( V_109 -> V_114 & V_140 ) &&
( V_2 -> V_4 . V_29 & V_141 ) ) {
F_8 ( V_2 , V_33 ,
V_142 | V_143 ) ;
} else {
F_7 ( V_2 , V_33 ,
V_142 | V_143 ) ;
}
F_4 ( V_2 , V_26 , V_111 ) ;
F_9 ( V_2 , V_10 ) ;
F_4 ( V_2 , V_22 , V_112 ) ;
F_38 ( & V_2 -> V_4 , V_2 -> V_4 . V_92 ) ;
F_36 ( & V_2 -> V_4 . V_61 , V_29 ) ;
}
static void
F_51 ( struct V_16 * V_4 , unsigned int V_62 ,
unsigned int V_144 )
{
if ( V_62 == 0 && V_144 != - 1 )
F_16 ( V_4 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
unsigned int V_145 = V_146 ;
int V_82 = 0 ;
switch ( V_2 -> V_4 . V_5 ) {
default:
if ( ! V_2 -> V_4 . V_147 )
break;
if ( ! F_53 ( V_2 -> V_4 . V_147 , V_145 , L_1 ) ) {
V_82 = - V_148 ;
break;
}
if ( V_2 -> V_4 . V_29 & V_149 ) {
V_2 -> V_4 . V_6 = F_54 ( V_2 -> V_4 . V_147 , V_145 ) ;
if ( ! V_2 -> V_4 . V_6 ) {
F_55 ( V_2 -> V_4 . V_147 , V_145 ) ;
V_82 = - V_150 ;
}
}
break;
case V_7 :
if ( ! F_56 ( V_2 -> V_4 . V_8 , V_145 , L_1 ) )
V_82 = - V_148 ;
break;
}
return V_82 ;
}
static void F_57 ( struct V_1 * V_2 )
{
unsigned int V_145 = V_146 ;
switch ( V_2 -> V_4 . V_5 ) {
default:
if ( ! V_2 -> V_4 . V_147 )
break;
if ( V_2 -> V_4 . V_29 & V_149 ) {
F_58 ( V_2 -> V_4 . V_6 ) ;
V_2 -> V_4 . V_6 = NULL ;
}
F_55 ( V_2 -> V_4 . V_147 , V_145 ) ;
break;
case V_7 :
F_59 ( V_2 -> V_4 . V_8 , V_145 ) ;
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
static void F_62 ( struct V_16 * V_4 , int V_151 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
int V_82 ;
V_82 = F_52 ( V_2 ) ;
if ( V_82 < 0 )
return;
V_4 -> type = V_152 ;
V_2 -> V_4 . V_153 = V_69 ;
#ifdef F_46
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_106 -> V_107 )
return;
#endif
F_16 ( V_4 ) ;
}
static const char *
F_63 ( struct V_16 * V_4 )
{
return L_2 ;
}
static void T_2 F_64 ( struct V_154 * V_155 ,
struct V_156 * V_157 )
{
int V_158 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
struct V_1 * V_2 = & V_160 [ V_158 ] ;
V_2 -> V_4 . line = V_158 ;
V_2 -> V_4 . V_161 = & V_162 ;
V_2 -> V_4 . V_157 = V_157 ;
if ( V_2 -> V_4 . V_8 || V_2 -> V_4 . V_147 )
F_65 ( V_155 , & V_2 -> V_4 ) ;
}
}
static void F_66 ( struct V_16 * V_4 , int V_36 )
{
struct V_1 * V_2 = F_10 ( V_4 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_67 , V_36 ) ;
}
static void
F_67 ( struct V_163 * V_164 , const char * V_165 , unsigned int V_65 )
{
struct V_1 * V_2 = & V_160 [ V_164 -> V_107 ] ;
unsigned int V_96 , V_166 ;
V_96 = F_1 ( V_2 , V_17 ) ;
F_4 ( V_2 , V_17 , 0 ) ;
V_166 = F_1 ( V_2 , V_33 ) ;
if ( ! ( V_2 -> V_4 . V_29 & V_95 ) && ( V_166 & V_143 ) )
F_4 ( V_2 , V_33 , V_166 & ~ V_143 ) ;
F_68 ( & V_2 -> V_4 , V_165 , V_65 , F_66 ) ;
F_40 ( V_2 ) ;
F_4 ( V_2 , V_33 , V_166 ) ;
F_4 ( V_2 , V_17 , V_96 ) ;
}
static int T_2 F_69 ( struct V_163 * V_164 , char * V_167 )
{
struct V_16 * V_4 ;
struct V_1 * V_2 ;
int V_113 = 9600 ;
int V_168 = 8 ;
int V_53 = 'n' ;
int V_169 = 'n' ;
if ( V_164 -> V_107 >= V_159 )
V_164 -> V_107 = 0 ;
V_2 = & V_160 [ V_164 -> V_107 ] ;
V_4 = & V_2 -> V_4 ;
if ( ! V_4 -> V_161 )
return - V_170 ;
F_16 ( & V_2 -> V_4 ) ;
if ( V_167 )
F_70 ( V_167 , & V_113 , & V_53 , & V_168 , & V_169 ) ;
return F_71 ( V_4 , V_164 , V_113 , V_53 , V_168 , V_169 ) ;
}
static int T_2 F_72 ( void )
{
F_73 ( & V_171 ) ;
return 0 ;
}
int T_2 F_74 ( struct V_16 * V_4 )
{
if ( V_4 -> line >= F_75 ( V_160 ) )
return - V_170 ;
V_160 [ V_4 -> line ] . V_4 = * V_4 ;
V_160 [ V_4 -> line ] . V_4 . V_161 = & V_162 ;
V_160 [ V_4 -> line ] . V_4 . V_29 |=
V_172 | V_173 ;
return 0 ;
}
static int F_76 ( struct V_16 * V_4 )
{
int V_158 ;
struct V_1 * V_174 ;
int V_82 = - V_175 ;
F_77 ( & V_176 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
V_174 = & V_160 [ V_158 ] ;
if ( F_78 ( & V_174 -> V_4 , V_4 ) ) {
F_79 ( & V_177 , & V_174 -> V_4 ) ;
break;
}
}
if ( V_158 == V_159 ) {
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
V_174 = & V_160 [ V_158 ] ;
if ( ! ( V_174 -> V_4 . V_8 || V_174 -> V_4 . V_147 ) )
break;
}
}
if ( V_158 < V_159 ) {
V_174 -> V_4 . V_8 = V_4 -> V_8 ;
V_174 -> V_4 . V_6 = V_4 -> V_6 ;
V_174 -> V_4 . V_74 = V_4 -> V_74 ;
V_174 -> V_4 . V_132 = V_4 -> V_132 ;
V_174 -> V_4 . V_5 = V_4 -> V_5 ;
V_174 -> V_4 . V_29 = V_4 -> V_29
| V_172 | V_173 ;
V_174 -> V_4 . V_147 = V_4 -> V_147 ;
if ( V_4 -> V_157 )
V_174 -> V_4 . V_157 = V_4 -> V_157 ;
V_82 = F_65 ( & V_177 , & V_174 -> V_4 ) ;
if ( V_82 == 0 )
V_82 = V_174 -> V_4 . line ;
}
F_80 ( & V_176 ) ;
return V_82 ;
}
static void F_81 ( int line )
{
struct V_1 * V_174 = & V_160 [ line ] ;
F_77 ( & V_176 ) ;
F_79 ( & V_177 , & V_174 -> V_4 ) ;
V_174 -> V_4 . V_29 = 0 ;
V_174 -> V_4 . type = V_178 ;
V_174 -> V_4 . V_8 = 0 ;
V_174 -> V_4 . V_147 = 0 ;
V_174 -> V_4 . V_6 = NULL ;
V_174 -> V_4 . V_157 = NULL ;
F_80 ( & V_176 ) ;
}
static int F_82 ( struct V_179 * V_157 )
{
struct V_16 * V_180 = F_83 ( & V_157 -> V_157 ) ;
struct V_16 V_4 ;
int V_82 , V_158 ;
memset ( & V_4 , 0 , sizeof( struct V_16 ) ) ;
for ( V_158 = 0 ; V_180 && V_180 -> V_132 != 0 ; V_180 ++ , V_158 ++ ) {
V_4 . V_8 = V_180 -> V_8 ;
V_4 . V_6 = V_180 -> V_6 ;
V_4 . V_74 = V_180 -> V_74 ;
V_4 . V_132 = V_180 -> V_132 ;
V_4 . V_5 = V_180 -> V_5 ;
V_4 . V_29 = V_180 -> V_29 ;
V_4 . V_147 = V_180 -> V_147 ;
V_4 . V_157 = & V_157 -> V_157 ;
V_82 = F_76 ( & V_4 ) ;
if ( V_82 < 0 ) {
F_84 ( & V_157 -> V_157 , L_3
L_4 , V_158 ,
V_180 -> V_8 , ( unsigned long long ) V_180 -> V_147 ,
V_180 -> V_74 , V_82 ) ;
}
}
return 0 ;
}
static int F_85 ( struct V_179 * V_157 )
{
int V_158 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
struct V_1 * V_2 = & V_160 [ V_158 ] ;
if ( V_2 -> V_4 . V_157 == & V_157 -> V_157 )
F_81 ( V_158 ) ;
}
return 0 ;
}
static int F_86 ( struct V_179 * V_157 , T_3 V_62 )
{
int V_158 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
struct V_1 * V_2 = & V_160 [ V_158 ] ;
if ( V_2 -> V_4 . type != V_178 && V_2 -> V_4 . V_157 == & V_157 -> V_157 )
F_87 ( & V_177 , & V_2 -> V_4 ) ;
}
return 0 ;
}
static int F_88 ( struct V_179 * V_157 )
{
int V_158 ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
struct V_1 * V_2 = & V_160 [ V_158 ] ;
if ( V_2 -> V_4 . type != V_178 && V_2 -> V_4 . V_157 == & V_157 -> V_157 )
F_89 ( & V_177 , & V_2 -> V_4 ) ;
}
return 0 ;
}
static int
F_90 ( struct V_181 * V_157 , const struct V_182 * V_183 )
{
struct V_16 V_4 ;
int line ;
int V_184 ;
V_184 = F_91 ( V_157 ) ;
if ( V_184 )
return V_184 ;
memset ( & V_4 , 0 , sizeof( V_4 ) ) ;
V_4 . V_161 = & V_162 ;
V_4 . V_29 |= V_141 ;
V_4 . V_132 = 66670000 ;
V_4 . V_74 = V_157 -> V_74 ;
V_4 . V_5 = V_7 ;
V_4 . V_8 = F_92 ( V_157 , 1 ) ;
V_4 . V_157 = & V_157 -> V_157 ;
line = F_76 ( & V_4 ) ;
if ( line < 0 ) {
F_93 ( V_185 L_5 , F_94 ( V_157 ) , line ) ;
F_95 ( V_157 ) ;
return line ;
}
F_96 ( V_157 , & V_160 [ line ] ) ;
return 0 ;
}
static void F_97 ( struct V_181 * V_157 )
{
struct V_1 * V_2 = F_98 ( V_157 ) ;
if ( V_2 ) {
F_81 ( V_2 -> V_4 . line ) ;
F_95 ( V_157 ) ;
}
}
static int F_99 ( struct V_181 * V_157 , T_3 V_62 )
{
struct V_1 * V_2 = F_98 ( V_157 ) ;
if ( V_2 )
F_87 ( & V_177 , & V_2 -> V_4 ) ;
F_100 ( V_157 ) ;
F_101 ( V_157 , F_102 ( V_157 , V_62 ) ) ;
return 0 ;
}
static int F_103 ( struct V_181 * V_157 )
{
struct V_1 * V_2 = F_98 ( V_157 ) ;
F_101 ( V_157 , V_186 ) ;
F_104 ( V_157 ) ;
if ( V_2 )
F_89 ( & V_177 , & V_2 -> V_4 ) ;
return 0 ;
}
static int T_2 F_105 ( void )
{
int V_82 ;
F_93 ( V_187 L_6 , V_188 , V_189 ) ;
V_82 = F_106 ( & V_177 ) ;
if ( V_82 )
goto V_190;
V_191 = F_107 ( L_1 , - 1 ) ;
if ( ! V_191 ) {
V_82 = - V_150 ;
goto V_192;
}
V_82 = F_108 ( V_191 ) ;
if ( V_82 )
goto V_193;
F_64 ( & V_177 ,
& V_191 -> V_157 ) ;
V_82 = F_109 ( & V_194 ) ;
if ( V_82 )
goto V_195;
#ifdef F_110
V_82 = F_111 ( & V_196 ) ;
#endif
if ( V_82 == 0 )
goto V_190;
V_195:
F_112 ( V_191 ) ;
V_193:
F_113 ( V_191 ) ;
V_192:
F_114 ( & V_177 ) ;
V_190:
return V_82 ;
}
static void T_4 F_115 ( void )
{
int V_158 ;
#ifdef F_110
F_116 ( & V_196 ) ;
#endif
F_117 ( & V_194 ) ;
F_118 ( V_191 ) ;
for ( V_158 = 0 ; V_158 < V_159 ; V_158 ++ ) {
struct V_1 * V_2 = & V_160 [ V_158 ] ;
if ( V_2 -> V_4 . V_8 || V_2 -> V_4 . V_147 )
F_79 ( & V_177 , & V_2 -> V_4 ) ;
}
F_114 ( & V_177 ) ;
}
