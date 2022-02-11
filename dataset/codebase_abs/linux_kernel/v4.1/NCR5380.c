static inline void F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 ) ) {
V_2 -> V_3 . V_4 = F_3 ( V_2 ) ;
V_2 -> V_3 . V_5 = F_4 ( V_2 ) - 1 ;
V_2 -> V_3 . V_6 = F_5 ( V_2 -> V_3 . V_4 ) ;
V_2 -> V_3 . V_7 = V_2 -> V_3 . V_4 -> V_8 ;
} else {
V_2 -> V_3 . V_4 = NULL ;
V_2 -> V_3 . V_5 = 0 ;
V_2 -> V_3 . V_6 = NULL ;
V_2 -> V_3 . V_7 = 0 ;
}
}
static int F_6 ( struct V_9 * V_10 , int V_11 , int V_12 , int V_13 , int V_14 )
{
F_7 () ;
int V_15 = 500 ;
unsigned long V_16 = V_17 + V_14 ;
int V_18 ;
F_8 ( V_10 ) ;
while( V_15 -- > 0 )
{
V_18 = F_9 ( V_11 ) ;
if( ( V_18 & V_12 ) == V_13 )
return 0 ;
F_10 () ;
}
while( F_11 ( V_17 , V_16 ) )
{
V_18 = F_9 ( V_11 ) ;
if( ( V_18 & V_12 ) == V_13 )
return 0 ;
if( ! F_12 () )
F_13 () ;
else
F_10 () ;
}
return - V_19 ;
}
static void F_14 ( struct V_9 * V_10 )
{
F_7 () ;
unsigned char V_20 , V_21 , V_22 , V_23 , V_24 , V_25 ;
F_8 ( V_10 ) ;
V_21 = F_9 ( V_26 ) ;
V_20 = F_9 ( V_27 ) ;
V_23 = F_9 ( V_28 ) ;
V_24 = F_9 ( V_29 ) ;
V_22 = F_9 ( V_30 ) ;
F_15 ( L_1 , V_20 ) ;
for ( V_25 = 0 ; V_31 [ V_25 ] . V_32 ; ++ V_25 )
if ( V_20 & V_31 [ V_25 ] . V_32 )
F_15 ( L_2 , V_31 [ V_25 ] . V_33 ) ;
F_15 ( L_3 , V_22 ) ;
for ( V_25 = 0 ; V_34 [ V_25 ] . V_32 ; ++ V_25 )
if ( V_22 & V_34 [ V_25 ] . V_32 )
F_15 ( L_2 , V_34 [ V_25 ] . V_33 ) ;
F_15 ( L_4 , V_24 ) ;
for ( V_25 = 0 ; V_35 [ V_25 ] . V_32 ; ++ V_25 )
if ( V_24 & V_35 [ V_25 ] . V_32 )
F_15 ( L_2 , V_35 [ V_25 ] . V_33 ) ;
F_15 ( L_5 , V_23 ) ;
for ( V_25 = 0 ; V_36 [ V_25 ] . V_32 ; ++ V_25 )
if ( V_23 & V_36 [ V_25 ] . V_32 )
F_15 ( L_2 , V_36 [ V_25 ] . V_33 ) ;
F_15 ( L_6 ) ;
}
static void F_16 ( struct V_9 * V_10 )
{
F_7 () ;
unsigned char V_20 ;
int V_25 ;
F_8 ( V_10 ) ;
V_20 = F_9 ( V_27 ) ;
if ( ! ( V_20 & V_37 ) )
F_15 ( L_7 , V_10 -> V_38 ) ;
else {
for ( V_25 = 0 ; ( V_39 [ V_25 ] . V_40 != V_41 ) && ( V_39 [ V_25 ] . V_40 != ( V_20 & V_42 ) ) ; ++ V_25 ) ;
F_15 ( L_8 , V_10 -> V_38 , V_39 [ V_25 ] . V_33 ) ;
}
}
static int F_17 ( unsigned char V_2 )
{
switch ( V_2 ) {
case V_43 :
case V_44 :
case V_45 :
case V_46 :
case V_47 :
case V_48 :
return V_49 ;
case V_50 :
case V_51 :
case V_52 :
case V_53 :
return V_54 ;
default:
return V_55 ;
}
}
static void F_18 ( struct V_56 * V_57 , unsigned long V_58 )
{
V_57 -> V_59 = V_17 + V_58 ;
F_19 ( & V_57 -> V_60 , V_58 ) ;
}
static T_1 T_2 F_20 ( int V_61 , void * V_62 )
{
V_63 = V_61 ;
return V_64 ;
}
static int T_2 T_3 F_21 ( struct V_9 * V_10 ,
int V_65 )
{
F_7 () ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
unsigned long V_58 ;
int V_66 , V_25 , V_32 ;
F_8 ( V_10 ) ;
for ( V_66 = 0 , V_25 = 1 , V_32 = 2 ; V_25 < 16 ; ++ V_25 , V_32 <<= 1 )
if ( ( V_32 & V_65 ) && ( F_22 ( V_25 , & F_20 , 0 , L_9 , NULL ) == 0 ) )
V_66 |= V_32 ;
V_58 = V_17 + F_23 ( 250 ) ;
V_63 = V_67 ;
F_24 ( V_68 , 0 ) ;
F_24 ( V_69 , V_57 -> V_70 ) ;
F_24 ( V_71 , V_57 -> V_70 ) ;
F_24 ( V_29 , V_72 | V_73 | V_74 ) ;
while ( V_63 == V_67 && F_11 ( V_17 , V_58 ) )
F_25 ( 1 ) ;
F_24 ( V_69 , 0 ) ;
F_24 ( V_29 , V_72 ) ;
for ( V_25 = 1 , V_32 = 2 ; V_25 < 16 ; ++ V_25 , V_32 <<= 1 )
if ( V_66 & V_32 )
F_26 ( V_25 , NULL ) ;
return V_63 ;
}
static const char * F_27 ( struct V_9 * V_10 )
{
struct V_56 * V_57 = F_28 ( V_10 ) ;
return V_57 -> V_75 ;
}
static void F_29 ( struct V_9 * V_10 )
{
struct V_56 * V_57 = F_28 ( V_10 ) ;
snprintf ( V_57 -> V_75 , sizeof( V_57 -> V_75 ) ,
L_10
L_11
L_12
L_13
L_14
#if F_30 ( V_76 ) && F_30 ( V_77 )
L_15
#endif
L_16 ,
V_10 -> V_78 -> V_33 , V_10 -> V_79 , V_10 -> V_80 ,
V_10 -> V_81 , V_10 -> V_61 ,
V_10 -> V_82 , V_10 -> V_83 ,
V_10 -> V_84 , V_10 -> V_85 ,
V_57 -> V_86 & V_87 ? L_17 : L_18 ,
V_57 -> V_86 & V_88 ? L_19 : L_18 ,
V_57 -> V_86 & V_89 ? L_20 : L_18 ,
#if F_30 ( V_76 ) && F_30 ( V_77 )
V_76 , V_77 ,
#endif
#ifdef F_31
L_21
#endif
#ifdef F_32
L_22
#endif
#ifdef F_33
L_23
#endif
#ifdef F_34
L_24
#endif
#ifdef F_35
L_25
#endif
#ifdef F_36
L_26
#endif
#ifdef F_37
L_27
#endif
#ifdef F_38
L_17
#endif
L_18 ) ;
}
static void F_39 ( struct V_9 * V_10 )
{
F_40 ( V_90 , V_10 ) ;
F_41 ( V_90 , V_10 ) ;
}
static int T_3 F_42 ( struct V_9 * V_10 ,
char * V_4 , int V_8 )
{
struct V_56 * V_57 = F_28 ( V_10 ) ;
V_57 -> V_91 = 0 ;
V_57 -> V_92 = 0 ;
return 0 ;
}
static int T_3 F_43 ( struct V_93 * V_94 ,
struct V_9 * V_10 )
{
struct V_56 * V_57 ;
struct V_1 * V_6 ;
V_57 = (struct V_56 * ) V_10 -> V_57 ;
#ifdef F_36
F_44 ( V_94 , L_28 ,
V_57 -> V_92 , V_57 -> V_91 ) ;
#endif
F_45 ( V_10 -> V_95 ) ;
if ( ! V_57 -> V_96 )
F_44 ( V_94 , L_29 , V_10 -> V_38 ) ;
else
F_46 ( (struct V_1 * ) V_57 -> V_96 , V_94 ) ;
F_44 ( V_94 , L_30 , V_10 -> V_38 ) ;
for ( V_6 = (struct V_1 * ) V_57 -> V_97 ; V_6 ; V_6 = (struct V_1 * ) V_6 -> V_98 )
F_46 ( V_6 , V_94 ) ;
F_44 ( V_94 , L_31 , V_10 -> V_38 ) ;
for ( V_6 = (struct V_1 * ) V_57 -> V_99 ; V_6 ; V_6 = (struct V_1 * ) V_6 -> V_98 )
F_46 ( V_6 , V_94 ) ;
F_47 ( V_10 -> V_95 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_2 , struct V_93 * V_94 )
{
F_44 ( V_94 , L_32 , V_2 -> V_100 -> V_101 -> V_38 , V_2 -> V_100 -> V_102 , V_2 -> V_100 -> V_103 ) ;
F_48 ( V_94 , L_33 ) ;
F_49 ( V_2 -> V_104 , V_94 ) ;
}
static void F_49 ( unsigned char * V_105 , struct V_93 * V_94 )
{
int V_25 , V_106 ;
F_50 ( V_105 [ 0 ] , V_94 ) ;
for ( V_25 = 1 , V_106 = F_51 ( V_105 [ 0 ] ) ; V_25 < V_106 ; ++ V_25 )
F_44 ( V_94 , L_34 , V_105 [ V_25 ] ) ;
F_52 ( V_94 , '\n' ) ;
}
static void F_50 ( int V_107 , struct V_93 * V_94 )
{
F_44 ( V_94 , L_35 , V_107 , V_107 ) ;
}
static int F_53 ( struct V_9 * V_10 , int V_86 )
{
F_7 () ;
int V_25 , V_108 ;
unsigned long V_58 ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
if( F_12 () )
F_15 ( V_109 L_36 ) ;
#ifdef F_38
if ( V_86 & V_87 )
V_10 -> V_110 += V_111 ;
#endif
F_8 ( V_10 ) ;
V_57 -> V_112 = 0 ;
V_57 -> V_70 = 1 << V_10 -> V_85 ;
for ( V_25 = V_57 -> V_70 ; V_25 <= 0x80 ; V_25 <<= 1 )
if ( V_25 > V_57 -> V_70 )
V_57 -> V_113 |= V_25 ;
for ( V_25 = 0 ; V_25 < 8 ; ++ V_25 )
V_57 -> V_114 [ V_25 ] = 0 ;
#ifdef F_33
V_57 -> V_115 = 0 ;
#endif
V_57 -> V_116 = 0 ;
V_57 -> V_96 = NULL ;
V_57 -> V_97 = NULL ;
V_57 -> V_99 = NULL ;
F_54 ( & V_57 -> V_60 , V_117 ) ;
if ( V_86 & V_87 )
V_57 -> V_86 = V_118 | V_86 ;
else
V_57 -> V_86 = V_119 | V_86 ;
V_57 -> V_101 = V_10 ;
V_57 -> V_59 = 0 ;
F_29 ( V_10 ) ;
F_24 ( V_29 , V_72 ) ;
F_24 ( V_28 , V_120 ) ;
F_24 ( V_68 , 0 ) ;
F_24 ( V_69 , 0 ) ;
#ifdef F_38
if ( V_57 -> V_86 & V_87 ) {
F_24 ( V_121 , V_122 ) ;
}
#endif
for ( V_108 = 1 ; ( F_9 ( V_27 ) & V_123 ) && V_108 <= 6 ; ++ V_108 ) {
switch ( V_108 ) {
case 1 :
case 3 :
case 5 :
F_15 ( V_124 L_37 , V_10 -> V_38 ) ;
V_58 = V_17 + 5 * V_125 ;
F_6 ( V_10 , V_27 , V_123 , 0 , 5 * V_125 ) ;
break;
case 2 :
F_15 ( V_126 L_38 , V_10 -> V_38 ) ;
F_55 ( V_10 ) ;
break;
case 4 :
F_15 ( V_126 L_39 , V_10 -> V_38 ) ;
F_56 ( V_10 ) ;
break;
case 6 :
F_15 ( V_109 L_40 , V_10 -> V_38 ) ;
return - V_127 ;
}
}
return 0 ;
}
static void F_57 ( struct V_9 * V_10 )
{
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
F_58 ( & V_57 -> V_60 ) ;
}
static int F_59 ( struct V_1 * V_2 , void (* F_60) ( struct V_1 * ) )
{
struct V_9 * V_10 = V_2 -> V_100 -> V_101 ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
struct V_1 * V_128 ;
#if ( V_129 & V_130 )
switch ( V_2 -> V_104 [ 0 ] ) {
case V_44 :
case V_47 :
F_15 ( L_41 , V_10 -> V_38 ) ;
V_2 -> V_131 = ( V_132 << 16 ) ;
F_60 ( V_2 ) ;
return 0 ;
}
#endif
V_2 -> V_98 = NULL ;
V_2 -> V_133 = F_60 ;
V_2 -> V_131 = 0 ;
if ( ! ( V_57 -> V_97 ) || ( V_2 -> V_104 [ 0 ] == V_134 ) ) {
F_61 ( V_2 , V_57 -> V_97 ) ;
V_2 -> V_98 = ( unsigned char * ) V_57 -> V_97 ;
V_57 -> V_97 = V_2 ;
} else {
for ( V_128 = (struct V_1 * ) V_57 -> V_97 ; V_128 -> V_98 ; V_128 = (struct V_1 * ) V_128 -> V_98 ) ;
F_61 ( V_2 , V_128 ) ;
V_128 -> V_98 = ( unsigned char * ) V_2 ;
}
F_62 ( V_135 , L_42 , V_10 -> V_38 , ( V_2 -> V_104 [ 0 ] == V_134 ) ? L_43 : L_44 ) ;
F_19 ( & V_57 -> V_60 , 0 ) ;
return 0 ;
}
T_1 F_63 ( int V_136 , void * V_62 )
{
F_7 () ;
struct V_9 * V_10 = V_62 ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
int F_60 ;
unsigned char V_22 ;
unsigned long V_86 ;
F_62 ( V_137 , L_45 ,
V_10 -> V_61 ) ;
do {
F_60 = 1 ;
F_64 ( V_10 -> V_95 , V_86 ) ;
F_8 ( V_10 ) ;
V_22 = F_9 ( V_30 ) ;
if ( V_22 & V_138 ) {
F_40 ( V_137 , V_10 ) ;
if ( ( F_9 ( V_27 ) & ( V_139 | V_140 ) ) == ( V_139 | V_140 ) ) {
F_60 = 0 ;
F_62 ( V_137 , L_46 , V_10 -> V_38 ) ;
F_65 ( V_10 ) ;
( void ) F_9 ( V_141 ) ;
} else if ( V_22 & V_142 ) {
F_62 ( V_137 , L_47 , V_10 -> V_38 ) ;
( void ) F_9 ( V_141 ) ;
} else if ( ( F_9 ( V_27 ) & V_143 ) == V_143 ) {
F_62 ( V_137 , L_48 , V_10 -> V_38 ) ;
( void ) F_9 ( V_141 ) ;
} else {
#if F_30 ( F_33 )
if ( ( F_9 ( V_28 ) & V_144 ) && ( ( V_22 & V_145 ) || ! ( V_22 & V_146 ) ) ) {
int V_147 ;
if ( ! V_57 -> V_96 )
F_66 ( L_49 , V_10 -> V_148 ) ;
V_147 = ( V_57 -> V_115 - F_67 ( V_10 ) ) ;
V_57 -> V_96 -> V_3 . V_7 -= V_147 ;
V_57 -> V_96 -> V_3 . V_6 += V_147 ;
V_57 -> V_115 = 0 ;
( void ) F_9 ( V_141 ) ;
F_6 ( V_57 , V_30 , V_149 , 0 , 2 * V_125 ) ;
F_24 ( V_28 , V_120 ) ;
F_24 ( V_29 , V_72 ) ;
}
#else
F_62 ( V_137 , L_50 , V_22 , F_9 ( V_28 ) , F_9 ( V_27 ) ) ;
( void ) F_9 ( V_141 ) ;
#endif
}
}
F_68 ( V_10 -> V_95 , V_86 ) ;
if( ! F_60 )
F_19 ( & V_57 -> V_60 , 0 ) ;
} while ( ! F_60 );
return V_64 ;
}
static int F_69 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
F_7 () ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
unsigned char V_128 [ 3 ] , V_150 ;
unsigned char * V_21 ;
int V_151 ;
unsigned long V_58 ;
unsigned char V_40 ;
int V_152 ;
F_8 ( V_10 ) ;
if ( V_57 -> V_153 )
goto V_154;
V_57 -> V_155 = 0 ;
F_40 ( V_156 , V_10 ) ;
F_62 ( V_156 , L_51 , V_10 -> V_38 , V_10 -> V_85 ) ;
F_24 ( V_68 , 0 ) ;
F_24 ( V_71 , V_57 -> V_70 ) ;
F_24 ( V_28 , V_157 ) ;
F_47 ( V_10 -> V_95 ) ;
V_152 = F_6 ( V_10 , V_29 , V_158 , V_158 , 5 * V_125 ) ;
F_45 ( V_10 -> V_95 ) ;
if ( V_152 < 0 ) {
F_15 ( V_159 L_52 , __LINE__ ) ;
F_24 ( V_28 , V_120 ) ;
F_24 ( V_69 , V_57 -> V_70 ) ;
goto V_160;
}
F_62 ( V_156 , L_53 , V_10 -> V_38 ) ;
F_70 ( 3 ) ;
if ( ( F_9 ( V_29 ) & V_161 ) || ( F_9 ( V_26 ) & V_57 -> V_113 ) || ( F_9 ( V_29 ) & V_161 ) ) {
F_24 ( V_28 , V_120 ) ;
F_62 ( V_156 , L_54 , V_10 -> V_38 ) ;
goto V_160;
}
F_24 ( V_29 , V_72 | V_74 ) ;
if ( ! ( V_57 -> V_86 & V_88 ) &&
( F_9 ( V_29 ) & V_161 ) ) {
F_24 ( V_28 , V_120 ) ;
F_24 ( V_29 , V_72 ) ;
F_62 ( V_156 , L_55 , V_10 -> V_38 ) ;
goto V_160;
}
F_70 ( 2 ) ;
F_62 ( V_156 , L_56 , V_10 -> V_38 ) ;
F_24 ( V_71 , ( V_57 -> V_70 | ( 1 << F_71 ( V_2 ) ) ) ) ;
F_24 ( V_29 , ( V_72 | V_162 | V_73 | V_163 | V_74 ) ) ;
F_24 ( V_28 , V_120 ) ;
F_24 ( V_69 , 0 ) ;
F_70 ( 1 ) ;
F_24 ( V_29 , ( V_72 | V_73 | V_163 | V_74 ) ) ;
F_70 ( 1 ) ;
F_62 ( V_164 , L_57 , V_10 -> V_38 , F_71 ( V_2 ) ) ;
V_58 = V_17 + F_23 ( 250 ) ;
V_57 -> V_165 = 0 ;
V_57 -> V_153 = V_2 ;
V_154:
V_40 = F_9 ( V_27 ) & ( V_123 | V_140 ) ;
if ( ! V_40 && ( V_57 -> V_165 < V_125 / 4 ) ) {
V_57 -> V_165 ++ ;
F_18 ( V_57 , 1 ) ;
return 0 ;
}
V_57 -> V_153 = NULL ;
if ( ( F_9 ( V_27 ) & ( V_139 | V_140 ) ) == ( V_139 | V_140 ) ) {
F_24 ( V_29 , V_72 ) ;
F_65 ( V_10 ) ;
F_15 ( L_58 , V_10 -> V_38 ) ;
F_24 ( V_69 , V_57 -> V_70 ) ;
return - 1 ;
}
F_70 ( 1 ) ;
F_24 ( V_29 , V_72 | V_163 ) ;
if ( ! ( F_9 ( V_27 ) & V_123 ) ) {
F_24 ( V_29 , V_72 ) ;
if ( V_57 -> V_116 & ( 1 << F_71 ( V_2 ) ) ) {
F_15 ( V_159 L_59 , V_10 -> V_38 ) ;
if ( V_57 -> V_155 )
F_15 ( V_159 L_60 ) ;
F_40 ( V_164 , V_10 ) ;
F_24 ( V_69 , V_57 -> V_70 ) ;
return - 1 ;
}
V_2 -> V_131 = V_166 << 16 ;
V_2 -> V_133 ( V_2 ) ;
F_24 ( V_69 , V_57 -> V_70 ) ;
F_62 ( V_164 , L_61 , V_10 -> V_38 ) ;
F_24 ( V_69 , V_57 -> V_70 ) ;
return 0 ;
}
V_57 -> V_116 |= ( 1 << F_71 ( V_2 ) ) ;
F_47 ( V_10 -> V_95 ) ;
V_152 = F_6 ( V_10 , V_27 , V_37 , V_37 , V_125 ) ;
F_45 ( V_10 -> V_95 ) ;
if( V_152 ) {
F_15 ( V_109 L_62 , V_10 -> V_38 , __LINE__ ) ;
F_24 ( V_69 , V_57 -> V_70 ) ;
goto V_160;
}
F_62 ( V_164 , L_63 , V_10 -> V_38 , V_2 -> V_100 -> V_102 ) ;
V_128 [ 0 ] = F_72 ( ( ( V_10 -> V_61 == V_67 ) ? 0 : 1 ) , V_2 -> V_100 -> V_103 ) ;
V_151 = 1 ;
V_2 -> V_167 = 0 ;
V_21 = V_128 ;
V_150 = V_168 ;
F_73 ( V_10 , & V_150 , & V_151 , & V_21 ) ;
F_62 ( V_164 , L_64 , V_10 -> V_38 ) ;
V_57 -> V_96 = V_2 ;
V_57 -> V_114 [ V_2 -> V_100 -> V_102 ] |= ( 1 << ( V_2 -> V_100 -> V_103 & 0xFF ) ) ;
F_1 ( V_2 ) ;
return 0 ;
V_160:
return - 1 ;
}
static int F_73 ( struct V_9 * V_10 , unsigned char * V_150 , int * V_169 , unsigned char * * V_21 ) {
F_7 () ;
unsigned char V_170 = * V_150 , V_128 ;
int V_171 = * V_169 ;
unsigned char * V_172 = * V_21 ;
int V_173 = 0 ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
F_8 ( V_10 ) ;
if ( ! ( V_170 & V_140 ) )
F_62 ( V_174 , L_65 , V_10 -> V_38 , V_171 ) ;
else
F_62 ( V_174 , L_66 , V_10 -> V_38 , V_171 ) ;
F_24 ( V_68 , F_74 ( V_170 ) ) ;
if ( ( V_170 == V_175 ) || ( V_170 == V_176 ) ) {
V_173 = 1 ;
}
do {
while ( ! ( ( V_128 = F_9 ( V_27 ) ) & V_37 ) && ! V_173 ) ;
if ( ! ( V_128 & V_37 ) ) {
F_18 ( V_57 , V_177 ) ;
break;
}
F_62 ( V_178 , L_67 , V_10 -> V_38 ) ;
if ( ( V_128 & V_42 ) != V_170 ) {
F_62 ( V_178 , L_68 , V_10 -> V_38 ) ;
F_41 ( V_178 , V_10 ) ;
break;
}
if ( ! ( V_170 & V_140 ) )
F_24 ( V_71 , * V_172 ) ;
else
* V_172 = F_9 ( V_26 ) ;
++ V_172 ;
if ( ! ( V_170 & V_140 ) ) {
if ( ! ( ( V_170 & V_179 ) && V_171 > 1 ) ) {
F_24 ( V_29 , V_72 | V_73 ) ;
F_40 ( V_174 , V_10 ) ;
F_24 ( V_29 , V_72 | V_73 | V_180 ) ;
} else {
F_24 ( V_29 , V_72 | V_73 | V_163 ) ;
F_40 ( V_174 , V_10 ) ;
F_24 ( V_29 , V_72 | V_73 | V_163 | V_180 ) ;
}
} else {
F_40 ( V_174 , V_10 ) ;
F_24 ( V_29 , V_72 | V_180 ) ;
}
F_6 ( V_10 , V_27 , V_37 , 0 , 5 * V_125 ) ;
F_62 ( V_178 , L_69 , V_10 -> V_38 ) ;
if ( ! ( V_170 == V_181 && V_171 == 1 ) ) {
if ( V_170 == V_168 && V_171 > 1 )
F_24 ( V_29 , V_72 | V_163 ) ;
else
F_24 ( V_29 , V_72 ) ;
}
} while ( -- V_171 );
F_62 ( V_174 , L_70 , V_10 -> V_38 , V_171 ) ;
* V_169 = V_171 ;
* V_21 = V_172 ;
V_128 = F_9 ( V_27 ) ;
if ( V_128 & V_37 )
* V_150 = V_128 & V_42 ;
else
* V_150 = V_41 ;
if ( ! V_171 || ( * V_150 == V_170 ) )
return 0 ;
else
return - 1 ;
}
static void F_56 ( struct V_9 * V_101 ) {
F_7 () ;
F_8 ( V_101 ) ;
F_24 ( V_68 , F_74 ( F_9 ( V_27 ) & V_42 ) ) ;
F_24 ( V_29 , V_72 | V_182 ) ;
F_70 ( 25 ) ;
F_24 ( V_29 , V_72 ) ;
}
static int F_55 ( struct V_9 * V_101 ) {
F_7 () ;
unsigned char * V_183 , V_150 , V_128 ;
int V_151 ;
int V_184 ;
F_8 ( V_101 ) ;
F_24 ( V_29 , V_72 | V_163 ) ;
V_184 = F_6 ( V_101 , V_27 , V_37 , V_37 , 60 * V_125 ) ;
if( V_184 < 0 )
return - 1 ;
V_128 = ( unsigned char ) V_184 ;
F_24 ( V_68 , F_74 ( V_128 ) ) ;
if ( ( V_128 & V_42 ) != V_168 ) {
F_24 ( V_29 , V_72 | V_163 | V_180 ) ;
V_184 = F_6 ( V_101 , V_27 , V_37 , 0 , 3 * V_125 ) ;
F_24 ( V_29 , V_72 | V_163 ) ;
if( V_184 == - 1 )
return - 1 ;
}
V_128 = ABORT ;
V_183 = & V_128 ;
V_151 = 1 ;
V_150 = V_168 ;
F_73 ( V_101 , & V_150 , & V_151 , & V_183 ) ;
return V_151 ? - 1 : 0 ;
}
static int F_75 ( struct V_9 * V_10 , unsigned char * V_150 , int * V_169 , unsigned char * * V_21 ) {
F_7 () ;
register int V_171 = * V_169 ;
register unsigned char V_170 = * V_150 ;
register unsigned char * V_172 = * V_21 ;
unsigned char V_128 ;
int V_185 ;
#if F_30 ( F_34 )
int V_186 , V_187 ;
unsigned char V_188 = 0 , V_189 = 0 , V_190 ;
#endif
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
F_8 ( V_10 ) ;
if ( ( V_128 = ( F_9 ( V_27 ) & V_42 ) ) != V_170 ) {
* V_150 = V_128 ;
return - 1 ;
}
#if F_30 ( F_33 ) || F_30 ( F_34 )
#ifdef F_76
if ( V_170 & V_140 ) {
V_171 -= 2 ;
}
#endif
F_62 ( V_191 , L_71 , V_10 -> V_38 , V_10 -> V_192 , ( V_170 & V_140 ) ? L_72 : L_73 , V_171 , ( V_170 & V_140 ) ? L_74 : L_75 , ( unsigned ) V_172 ) ;
V_57 -> V_193 = ( V_170 & V_140 ) ? F_77 ( V_10 , V_172 , V_171 ) : F_78 ( V_10 , V_172 , V_171 ) ;
#endif
F_24 ( V_68 , F_74 ( V_170 ) ) ;
#ifdef F_33
F_24 ( V_28 , V_120 | V_194 | V_195 | V_196 ) ;
#elif F_30 ( F_34 )
F_24 ( V_28 , V_120 | V_194 ) ;
#else
#if F_30 ( F_36 ) && F_30 ( F_37 )
F_47 ( V_10 -> V_95 ) ;
#endif
if ( V_57 -> V_86 & V_87 )
F_24 ( V_28 , V_120 | V_194 |
V_197 | V_198 |
V_195 | V_196 ) ;
else
F_24 ( V_28 , V_120 | V_194 ) ;
#endif
F_62 ( V_191 , L_76 , V_10 -> V_38 , F_9 ( V_28 ) ) ;
if ( V_170 & V_140 ) {
F_79 ( 1 ) ;
F_24 ( V_199 , 0 ) ;
} else {
F_79 ( 1 ) ;
F_24 ( V_29 , V_72 | V_73 ) ;
F_79 ( 1 ) ;
F_24 ( V_200 , 0 ) ;
F_79 ( 1 ) ;
}
#if F_30 ( F_34 )
do {
V_128 = F_9 ( V_30 ) ;
} while ( ( V_128 & V_146 ) && ! ( V_128 & ( V_201 | V_145 ) ) );
if ( V_170 & V_140 ) {
#ifdef F_76
F_70 ( 10 ) ;
if ( ( ( F_9 ( V_30 ) & ( V_146 | V_149 ) ) == ( V_146 | V_149 ) ) ) {
V_188 = F_9 ( V_202 ) ;
V_189 = 1 ;
}
#endif
} else {
int V_203 = 100 ;
while ( ( ( V_128 = F_9 ( V_30 ) ) & V_149 ) || ( F_9 ( V_27 ) & V_37 ) ) {
if ( ! ( V_128 & V_146 ) )
break;
if ( -- V_203 < 0 )
break;
}
}
F_62 ( V_191 , L_77 , V_10 -> V_38 , V_128 , F_9 ( V_27 ) ) ;
F_24 ( V_28 , V_120 ) ;
F_24 ( V_29 , V_72 ) ;
V_190 = F_67 ( V_10 ) ;
V_171 -= V_190 ;
* V_169 -= V_171 ;
* V_21 += V_171 ;
* V_150 = F_9 ( V_27 ) & V_42 ;
#ifdef F_76
if ( * V_150 == V_170 && ( V_170 & V_140 ) && V_190 == 0 ) {
if ( V_189 ) {
F_62 ( V_191 , L_78 ) ;
* * V_21 = V_188 ;
* V_21 += 1 ;
* V_169 -= 1 ;
V_186 = V_187 = 1 ;
} else {
F_15 ( L_79 ) ;
V_186 = V_187 = 2 ;
}
F_62 ( V_191 , L_80 , V_186 , * V_21 ) ;
F_73 ( V_10 , V_150 , & V_186 , V_21 ) ;
* V_169 -= V_187 - V_186 ;
}
#endif
F_62 ( V_191 , L_81 , * V_21 , * V_169 , * ( * V_21 + * V_169 - 1 ) , * ( * V_21 + * V_169 ) ) ;
return 0 ;
#elif F_30 ( F_33 )
return 0 ;
#else
if ( V_170 & V_140 ) {
#ifdef F_80
V_185 = F_81 ( V_10 , V_172 , V_171 ) ;
#else
int V_204 = 1 ;
if ( V_57 -> V_86 & V_87 ) {
V_204 = 0 ;
}
if ( ! ( V_185 = F_81 ( V_10 , V_172 , V_171 - V_204 ) ) ) {
if ( ! ( V_57 -> V_86 & V_87 ) ) {
while ( ! ( F_9 ( V_30 ) & V_205 ) ) ;
while ( F_9 ( V_27 ) & V_37 ) ;
V_172 [ V_171 - 1 ] = F_9 ( V_206 ) ;
}
}
#endif
} else {
#ifdef F_80
V_185 = F_82 ( V_10 , V_172 , V_171 ) ;
#else
int V_58 ;
F_62 ( V_207 , L_82 , V_171 ) ;
if ( ! ( V_185 = F_82 ( V_10 , V_172 , V_171 ) ) ) {
if ( ! ( V_57 -> V_86 & V_118 ) ) {
V_58 = 20000 ;
while ( ! ( F_9 ( V_30 ) & V_205 ) && ( F_9 ( V_30 ) & V_146 ) ) ;
if ( ! V_58 )
F_62 ( V_208 , L_83 , V_10 -> V_38 ) ;
if ( V_57 -> V_86 & V_119 ) {
V_57 -> V_86 &= ~ V_119 ;
if ( F_9 ( V_68 ) & V_209 ) {
V_57 -> V_86 |= V_118 ;
F_62 ( V_208 , L_84 , V_10 -> V_38 ) ;
}
}
} else {
F_62 ( V_207 , L_85 ) ;
while ( ! ( F_9 ( V_68 ) & V_209 ) ) ;
F_62 ( V_207 , L_86 ) ;
}
}
#endif
}
F_24 ( V_28 , V_120 ) ;
F_24 ( V_29 , V_72 ) ;
if ( ( ! ( V_170 & V_140 ) ) && ( V_57 -> V_86 & V_87 ) ) {
F_62 ( V_207 , L_87 ) ;
if ( F_9 ( V_30 ) & V_138 ) {
F_62 ( V_207 , L_88 ) ;
F_9 ( V_141 ) ;
} else {
F_15 ( L_89 ) ;
}
}
* V_21 = V_172 + V_171 ;
* V_169 = 0 ;
* V_150 = F_9 ( V_27 ) & V_42 ;
#if F_30 ( F_36 ) && F_30 ( F_37 )
F_45 ( V_10 -> V_95 ) ;
#endif
return V_185 ;
#endif
}
static void F_65 ( struct V_9 * V_10 ) {
F_7 () ;
struct V_56 * V_57 = (struct V_56 * )
V_10 -> V_57 ;
unsigned char V_210 ;
unsigned char V_103 , V_150 ;
int V_151 ;
unsigned char V_211 [ 3 ] ;
unsigned char * V_21 ;
struct V_1 * V_128 = NULL , * V_212 ;
int abort = 0 ;
F_8 ( V_10 ) ;
F_24 ( V_28 , V_120 ) ;
V_57 -> V_155 = 1 ;
V_210 = F_9 ( V_26 ) & ~ ( V_57 -> V_70 ) ;
F_62 ( V_164 , L_90 , V_10 -> V_38 ) ;
F_24 ( V_29 , V_72 | V_162 ) ;
if( F_6 ( V_10 , V_27 , V_139 , 0 , 2 * V_125 ) < 0 )
abort = 1 ;
F_24 ( V_29 , V_72 ) ;
if( F_6 ( V_10 , V_27 , V_37 , V_37 , 2 * V_125 ) )
abort = 1 ;
V_151 = 1 ;
V_21 = V_211 ;
V_150 = V_181 ;
F_73 ( V_10 , & V_150 , & V_151 , & V_21 ) ;
if ( ! ( V_211 [ 0 ] & 0x80 ) ) {
F_15 ( V_109 L_91 , V_10 -> V_38 ) ;
F_83 ( V_211 ) ;
abort = 1 ;
} else {
F_24 ( V_29 , V_72 ) ;
V_103 = ( V_211 [ 0 ] & 0x07 ) ;
for ( V_128 = (struct V_1 * ) V_57 -> V_99 , V_212 = NULL ; V_128 ; V_212 = V_128 , V_128 = (struct V_1 * ) V_128 -> V_98 )
if ( ( V_210 == ( 1 << V_128 -> V_100 -> V_102 ) ) && ( V_103 == ( V_213 ) V_128 -> V_100 -> V_103 )
) {
if ( V_212 ) {
REMOVE ( V_212 , V_212 -> V_98 , V_128 , V_128 -> V_98 ) ;
V_212 -> V_98 = V_128 -> V_98 ;
} else {
REMOVE ( - 1 , V_57 -> V_99 , V_128 , V_128 -> V_98 ) ;
V_57 -> V_99 = (struct V_1 * ) V_128 -> V_98 ;
}
V_128 -> V_98 = NULL ;
break;
}
if ( ! V_128 ) {
F_15 ( V_109 L_92 , V_10 -> V_38 , V_210 , V_103 ) ;
abort = 1 ;
}
}
if ( abort ) {
F_55 ( V_10 ) ;
} else {
V_57 -> V_96 = V_128 ;
F_62 ( V_214 , L_93 , V_10 -> V_38 , V_128 -> V_100 -> V_102 , V_128 -> V_100 -> V_103 , V_128 -> V_167 ) ;
}
}
static void F_84 ( T_4 * V_10 ) {
F_7 () ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
int V_147 ;
F_8 ( V_10 ) ;
F_6 ( V_10 , V_30 , V_149 , 0 , 5 * V_125 ) ;
F_24 ( V_28 , V_120 ) ;
F_24 ( V_29 , V_72 ) ;
if ( ! ( V_57 -> V_96 -> V_3 . V_150 & V_215 ) ) {
V_147 = V_10 -> V_115 - F_67 () ;
V_57 -> V_96 -> V_3 . V_7 -= V_147 ;
V_57 -> V_96 -> V_3 . V_6 += V_147 ;
}
}
static int F_85 ( struct V_1 * V_2 )
{
F_7 () ;
struct V_9 * V_10 = V_2 -> V_100 -> V_101 ;
struct V_56 * V_57 = (struct V_56 * ) V_10 -> V_57 ;
struct V_1 * V_128 , * * V_212 ;
F_86 ( V_126 , V_2 , L_94 ) ;
F_39 ( V_10 ) ;
F_8 ( V_10 ) ;
F_62 ( V_216 , L_95 , V_10 -> V_38 ) ;
F_62 ( V_216 , L_96 , F_9 ( V_30 ) , F_9 ( V_27 ) ) ;
#if 0
if (hostdata->connected == cmd) {
dprintk(NDEBUG_ABORT, "scsi%d : aborting connected command\n", instance->host_no);
hostdata->aborted = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_ASSERT_ATN);
return SUCCESS;
}
#endif
F_62 ( V_216 , L_97 , V_10 -> V_38 ) ;
for ( V_212 = (struct V_1 * * ) & ( V_57 -> V_97 ) , V_128 = (struct V_1 * ) V_57 -> V_97 ; V_128 ; V_212 = (struct V_1 * * ) & ( V_128 -> V_98 ) , V_128 = (struct V_1 * ) V_128 -> V_98 )
if ( V_2 == V_128 ) {
REMOVE ( 5 , * V_212 , V_128 , V_128 -> V_98 ) ;
( * V_212 ) = (struct V_1 * ) V_128 -> V_98 ;
V_128 -> V_98 = NULL ;
V_128 -> V_131 = V_217 << 16 ;
F_62 ( V_216 , L_98 , V_10 -> V_38 ) ;
V_128 -> V_133 ( V_128 ) ;
return V_218 ;
}
#if ( V_129 & V_216 )
else if ( V_212 == V_128 )
F_15 ( V_109 L_99 , V_10 -> V_38 ) ;
#endif
if ( V_57 -> V_96 ) {
F_62 ( V_216 , L_100 , V_10 -> V_38 ) ;
return V_219 ;
}
for ( V_128 = (struct V_1 * ) V_57 -> V_99 ; V_128 ; V_128 = (struct V_1 * ) V_128 -> V_98 )
if ( V_2 == V_128 ) {
F_62 ( V_216 , L_101 , V_10 -> V_38 ) ;
if ( F_69 ( V_10 , V_2 ) )
return V_219 ;
F_62 ( V_216 , L_102 , V_10 -> V_38 ) ;
F_55 ( V_10 ) ;
for ( V_212 = (struct V_1 * * ) & ( V_57 -> V_99 ) , V_128 = (struct V_1 * ) V_57 -> V_99 ; V_128 ; V_212 = (struct V_1 * * ) & ( V_128 -> V_98 ) , V_128 = (struct V_1 * ) V_128 -> V_98 )
if ( V_2 == V_128 ) {
REMOVE ( 5 , * V_212 , V_128 , V_128 -> V_98 ) ;
* V_212 = (struct V_1 * ) V_128 -> V_98 ;
V_128 -> V_98 = NULL ;
V_128 -> V_131 = V_217 << 16 ;
V_128 -> V_133 ( V_128 ) ;
return V_218 ;
}
}
F_15 ( V_126 L_103
L_104 , V_10 -> V_38 ) ;
return V_219 ;
}
static int F_87 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_100 -> V_101 ;
F_7 () ;
F_8 ( V_10 ) ;
F_39 ( V_10 ) ;
F_45 ( V_10 -> V_95 ) ;
F_56 ( V_10 ) ;
F_47 ( V_10 -> V_95 ) ;
return V_218 ;
}
