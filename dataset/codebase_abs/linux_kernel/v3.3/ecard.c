static inline unsigned short F_1 ( unsigned char * V_1 )
{
return V_1 [ 0 ] | V_1 [ 1 ] << 8 ;
}
static inline signed long F_2 ( unsigned char * V_1 )
{
return V_1 [ 0 ] | V_1 [ 1 ] << 8 | V_1 [ 2 ] << 16 | ( ( V_1 [ 2 ] & 0x80 ) ? 0xff000000 : 0 ) ;
}
static inline T_1 * F_3 ( unsigned int V_2 )
{
return V_2 < V_3 ? V_4 [ V_2 ] : NULL ;
}
static void F_4 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_9 * V_10 ;
V_10 = V_8 -> V_11 == 8
? & V_8 -> V_9 [ V_12 ]
: V_8 -> V_13
? & V_8 -> V_9 [ V_14 ]
: & V_8 -> V_9 [ V_15 ] ;
F_5 ( V_10 -> V_16 , V_8 -> V_17 ) ;
}
static void F_6 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
unsigned char * V_18 = V_6 -> V_19 ;
unsigned int V_20 = V_6 -> V_21 ;
unsigned int V_22 = V_6 -> V_23 ;
if ( V_8 -> V_11 == 8 ) {
void T_2 * V_24 = ( void T_2 * )
V_8 -> V_9 [ V_12 ] . V_16 ;
static unsigned int V_25 ;
unsigned int V_26 ;
V_26 = ( V_22 >> 12 ) * 4 ;
if ( V_26 > 256 * 4 )
return;
V_22 &= 4095 ;
if ( V_22 == 0 || V_25 > V_22 ) {
F_7 ( 0 , V_24 ) ;
V_25 = 0 ;
}
while ( V_25 < V_22 ) {
F_8 ( V_24 + V_26 ) ;
V_25 += 1 ;
}
while ( V_20 -- ) {
* V_18 ++ = F_8 ( V_24 + V_26 ) ;
V_25 += 1 ;
}
} else {
unsigned long V_24 = ( V_8 -> V_13
? & V_8 -> V_9 [ V_14 ]
: & V_8 -> V_9 [ V_15 ] ) -> V_16 ;
void T_2 * V_27 = ( void T_2 * ) V_24 ;
if ( ! V_6 -> V_28 || ! V_8 -> V_17 ) {
V_22 *= 4 ;
while ( V_20 -- ) {
* V_18 ++ = F_8 ( V_27 + V_22 ) ;
V_22 += 4 ;
}
} else {
while( V_20 -- ) {
* ( unsigned long * ) 0x108 = 0 ;
* V_18 ++ = F_9 ( V_22 ++ , V_24 ,
V_8 -> V_17 ) ;
}
}
}
}
static void F_10 ( struct V_29 * V_30 )
{
struct V_31 V_32 ;
T_3 * V_33 , * V_34 ;
V_33 = F_11 ( V_30 , ( unsigned long ) V_35 ) ;
V_34 = F_11 ( V_30 , V_36 ) ;
memcpy ( V_34 , V_33 , sizeof( T_3 ) * ( V_37 / V_38 ) ) ;
V_33 = F_11 ( V_30 , ( unsigned long ) V_39 ) ;
V_34 = F_11 ( V_30 , V_40 ) ;
memcpy ( V_34 , V_33 , sizeof( T_3 ) * ( V_41 / V_38 ) ) ;
V_32 . V_42 = V_43 ;
V_32 . V_44 = V_30 ;
F_12 ( & V_32 , V_36 , V_36 + V_37 ) ;
F_12 ( & V_32 , V_40 , V_40 + V_41 ) ;
}
static int F_13 ( void )
{
struct V_29 * V_30 = F_14 () ;
struct V_29 * V_45 = V_46 -> V_45 ;
if ( ! V_30 )
return - V_47 ;
V_46 -> V_30 = V_30 ;
V_46 -> V_45 = V_30 ;
F_15 ( V_45 , V_30 ) ;
F_16 ( V_45 ) ;
F_10 ( V_30 ) ;
return 0 ;
}
static int
F_17 ( void * V_48 )
{
if ( F_13 () )
F_18 ( L_1 ) ;
while ( 1 ) {
struct V_5 * V_6 ;
F_19 ( V_49 , V_50 != NULL ) ;
V_6 = F_20 ( & V_50 , NULL ) ;
if ( V_6 != NULL ) {
V_6 -> V_51 ( V_6 ) ;
F_21 ( V_6 -> F_21 ) ;
}
}
}
static void F_22 ( struct V_5 * V_6 )
{
F_23 ( V_52 ) ;
V_6 -> F_21 = & V_52 ;
F_24 ( & V_53 ) ;
V_50 = V_6 ;
F_25 ( & V_49 ) ;
F_26 ( & V_52 ) ;
F_27 ( & V_53 ) ;
}
static void
F_28 ( void * V_54 , T_1 * V_8 , int V_22 , int V_20 , int V_55 )
{
struct V_5 V_6 ;
V_6 . V_51 = F_6 ;
V_6 . V_8 = V_8 ;
V_6 . V_23 = V_22 ;
V_6 . V_21 = V_20 ;
V_6 . V_28 = V_55 ;
V_6 . V_19 = V_54 ;
F_22 ( & V_6 ) ;
}
int F_29 ( struct V_56 * V_57 , T_1 * V_8 , int V_58 , int V_59 )
{
struct V_60 V_61 ;
int V_25 = 16 ;
int V_55 = 0 ;
if ( ! V_8 -> V_62 . V_57 )
return 0 ;
while( 1 ) {
F_28 ( & V_61 , V_8 , V_25 , 8 , V_55 ) ;
V_25 += 8 ;
if ( F_30 ( & V_61 ) == 0 ) {
if ( ! V_55 && V_8 -> V_17 ) {
V_55 = 1 ;
V_25 = 0 ;
continue;
}
return 0 ;
}
if ( F_30 ( & V_61 ) == 0xf0 ) {
V_25 = F_31 ( & V_61 ) ;
continue;
}
if ( F_30 ( & V_61 ) == 0x80 ) {
if ( ! V_8 -> V_17 ) {
V_8 -> V_17 = F_32 ( F_33 ( & V_61 ) ,
V_63 ) ;
if ( V_8 -> V_17 )
F_28 ( V_8 -> V_17 , V_8 ,
( int ) F_31 ( & V_61 ) ,
F_33 ( & V_61 ) , V_55 ) ;
else
return 0 ;
}
continue;
}
if ( F_30 ( & V_61 ) == V_58 && V_59 -- == 0 )
break;
}
if ( F_30 ( & V_61 ) & 0x80 ) {
switch ( F_30 ( & V_61 ) & 0x70 ) {
case 0x70 :
F_28 ( ( unsigned char * ) V_61 . V_64 . string , V_8 ,
( int ) F_31 ( & V_61 ) , F_33 ( & V_61 ) ,
V_55 ) ;
break;
case 0x00 :
break;
}
}
V_57 -> V_65 = F_31 ( & V_61 ) ;
memcpy ( V_57 -> V_64 . string , V_61 . V_64 . string , 256 ) ;
return 1 ;
}
static void F_34 ( T_1 * V_8 , int V_66 )
{
#ifdef F_35
if ( V_66 < 4 && V_67 ) {
V_67 |= 1 << V_66 ;
F_36 ( V_67 , V_68 ) ;
}
#endif
}
static void F_37 ( T_1 * V_8 , int V_66 )
{
#ifdef F_35
if ( V_66 < 4 && V_67 ) {
V_67 &= ~ ( 1 << V_66 ) ;
F_36 ( V_67 , V_68 ) ;
}
#endif
}
static int F_38 ( T_1 * V_8 )
{
return ! V_8 -> V_69 || F_8 ( V_8 -> V_70 ) & V_8 -> V_69 ;
}
static void F_39 ( T_1 * V_8 , int V_71 )
{
F_18 ( L_2 ) ;
}
static void F_40 ( T_1 * V_8 , int V_71 )
{
F_18 ( L_3 ) ;
}
static int F_41 ( T_1 * V_8 )
{
return ! V_8 -> V_72 || F_8 ( V_8 -> V_73 ) & V_8 -> V_72 ;
}
static void F_42 ( struct V_74 * V_64 )
{
T_1 * V_8 = F_3 ( V_64 -> V_75 - 32 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_76 )
V_8 -> V_76 = & V_77 ;
if ( V_8 -> V_78 && V_8 -> V_76 -> V_79 )
V_8 -> V_76 -> V_79 ( V_8 , V_64 -> V_75 ) ;
else
F_43 ( V_80 L_4
L_5 , V_64 -> V_75 ) ;
}
}
static void F_44 ( struct V_74 * V_64 )
{
T_1 * V_8 = F_3 ( V_64 -> V_75 - 32 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_76 )
V_8 -> V_76 = & V_77 ;
if ( V_8 -> V_76 && V_8 -> V_76 -> V_81 )
V_8 -> V_76 -> V_81 ( V_8 , V_64 -> V_75 ) ;
}
}
void F_45 ( unsigned int V_71 )
{
T_1 * V_8 = F_3 ( V_71 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_76 )
V_8 -> V_76 = & V_77 ;
if ( V_8 -> V_78 && V_8 -> V_76 -> V_82 )
V_8 -> V_76 -> V_82 ( V_8 , V_71 ) ;
else
F_43 ( V_80 L_4
L_6 , V_71 ) ;
}
}
void F_46 ( unsigned int V_71 )
{
T_1 * V_8 = F_3 ( V_71 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_76 )
V_8 -> V_76 = & V_77 ;
if ( V_8 -> V_76 -> V_83 )
V_8 -> V_76 -> V_83 ( V_8 , V_71 ) ;
}
}
static void F_47 ( void )
{
T_1 * V_8 ;
F_43 ( L_7 ) ;
for ( V_8 = V_84 ; V_8 ; V_8 = V_8 -> V_85 ) {
if ( V_8 -> V_11 == 8 )
continue;
F_43 ( L_8 ,
V_8 -> V_11 , V_8 -> V_78 ? L_9 : L_10 ) ;
if ( V_8 -> V_76 && V_8 -> V_76 -> V_86 &&
V_8 -> V_76 != & V_77 )
F_43 ( L_11 ,
V_8 -> V_76 -> V_86 ( V_8 ) ? L_9 : L_10 ) ;
else
F_43 ( L_12 ,
V_8 -> V_70 , V_8 -> V_69 , F_8 ( V_8 -> V_70 ) ) ;
}
}
static void F_48 ( struct V_87 * V_88 )
{
static unsigned long V_89 ;
static int V_90 ;
if ( V_89 == V_91 ) {
V_90 += 1 ;
if ( V_90 > 1000000 ) {
F_43 ( V_80 L_13
L_14 ) ;
V_88 -> V_74 . V_92 -> V_93 ( & V_88 -> V_74 ) ;
F_47 () ;
}
} else
V_90 = 0 ;
if ( ! V_89 || F_49 ( V_91 , V_89 + 5 * V_94 ) ) {
V_89 = V_91 ;
F_43 ( V_95 L_15 ) ;
F_47 () ;
}
}
static void
F_50 ( unsigned int V_75 , struct V_87 * V_88 )
{
T_1 * V_8 ;
int V_96 = 0 ;
V_88 -> V_74 . V_92 -> V_93 ( & V_88 -> V_74 ) ;
for ( V_8 = V_84 ; V_8 ; V_8 = V_8 -> V_85 ) {
int V_97 ;
if ( ! V_8 -> V_78 || V_8 -> V_75 == V_98 || V_8 -> V_11 == 8 )
continue;
if ( V_8 -> V_76 && V_8 -> V_76 -> V_86 )
V_97 = V_8 -> V_76 -> V_86 ( V_8 ) ;
else
V_97 = V_77 . V_86 ( V_8 ) ;
if ( V_97 ) {
F_51 ( V_8 -> V_75 ) ;
V_96 ++ ;
}
}
V_88 -> V_74 . V_92 -> V_99 ( & V_88 -> V_74 ) ;
if ( V_96 == 0 )
F_48 ( V_88 ) ;
}
static void
F_52 ( unsigned int V_75 , struct V_87 * V_88 )
{
const unsigned int V_100 = 15 ;
unsigned int V_101 ;
V_101 = F_53 ( V_102 ) & V_100 ;
if ( V_101 ) {
unsigned int V_2 = V_103 [ V_101 ] ;
T_1 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_78 ) {
F_51 ( V_8 -> V_75 ) ;
} else {
F_43 ( V_95 L_16
L_17 , V_2 ) ;
V_67 &= ~ ( 1 << V_2 ) ;
F_36 ( V_67 , V_68 ) ;
}
} else
F_43 ( V_95 L_18 ) ;
}
static int T_4 F_54 ( void )
{
T_1 * V_8 ;
int V_104 ;
F_36 ( 0x00 , V_68 ) ;
F_36 ( 0xff , V_102 ) ;
V_104 = ( F_53 ( V_102 ) & 15 ) == 0 ;
F_36 ( 0xff , V_68 ) ;
if ( V_104 ) {
F_43 ( V_105 L_19
L_20 ) ;
V_67 = 0x80000000 ;
for ( V_8 = V_84 ; V_8 ; V_8 = V_8 -> V_85 )
V_67 |= 1 << V_8 -> V_11 ;
F_36 ( V_67 , V_68 ) ;
}
return V_104 ;
}
static void T_2 * F_55 ( T_1 * V_8 , T_5 type , T_6 V_106 )
{
void T_2 * V_23 = NULL ;
int V_2 = V_8 -> V_11 ;
if ( V_8 -> V_11 == 8 )
return V_107 ;
V_108 &= ~ ( 1 << V_2 ) ;
switch ( type ) {
case V_109 :
if ( V_2 < 4 )
V_23 = V_110 + ( V_2 << 14 ) ;
break;
case V_111 :
if ( V_2 < 4 )
V_23 = V_112 + ( V_2 << 14 ) ;
else
V_23 = V_113 + ( ( V_2 - 4 ) << 14 ) ;
if ( V_23 )
V_23 += V_106 << 19 ;
break;
case V_114 :
V_23 = V_115 + ( V_2 << 24 ) ;
if ( V_106 == V_116 )
V_108 |= 1 << V_2 ;
break;
default:
break;
}
#ifdef F_56
F_57 ( V_108 , F_56 ) ;
#endif
return V_23 ;
}
static int F_58 ( struct V_117 * V_118 , T_1 * V_8 )
{
F_59 ( V_118 , L_21 , V_8 -> V_11 , V_8 -> V_13 ? L_22 : L_23 ) ;
if ( V_8 -> V_62 . V_58 == 0 ) {
struct V_56 V_119 ;
F_59 ( V_118 , L_24 ,
V_8 -> V_62 . V_120 , V_8 -> V_62 . V_121 ) ;
if ( ! V_8 -> V_122 && V_8 -> V_62 . V_57 &&
F_29 ( & V_119 , V_8 , 0xf5 , 0 ) ) {
V_8 -> V_122 = F_32 ( strlen ( V_119 . V_64 . string ) + 1 , V_63 ) ;
if ( V_8 -> V_122 )
strcpy ( ( char * ) V_8 -> V_122 , V_119 . V_64 . string ) ;
}
F_59 ( V_118 , L_25 , V_8 -> V_122 ? V_8 -> V_122 : L_26 ) ;
} else
F_59 ( V_118 , L_27 , V_8 -> V_62 . V_58 ) ;
return 0 ;
}
static int F_60 ( struct V_117 * V_118 , void * V_1 )
{
T_1 * V_8 = V_84 ;
while ( V_8 ) {
F_58 ( V_118 , V_8 ) ;
V_8 = V_8 -> V_85 ;
}
return 0 ;
}
static int F_61 ( struct V_123 * V_123 , struct V_124 * V_124 )
{
return F_62 ( V_124 , F_60 , NULL ) ;
}
static void F_63 ( void )
{
V_125 = F_64 ( L_28 , NULL ) ;
F_65 ( L_29 , 0 , V_125 , & V_126 ) ;
}
static void T_4 F_66 ( struct V_7 * V_8 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ )
if ( V_8 -> V_9 [ V_127 ] . V_129 )
F_67 ( & V_8 -> V_9 [ V_127 ] ) ;
F_68 ( V_8 ) ;
}
static struct V_7 * T_4 F_69 ( int type , int V_2 )
{
struct V_7 * V_8 ;
unsigned long V_24 ;
int V_127 ;
V_8 = F_70 ( sizeof( T_1 ) , V_63 ) ;
if ( ! V_8 ) {
V_8 = F_71 ( - V_47 ) ;
goto V_130;
}
V_8 -> V_11 = V_2 ;
V_8 -> V_13 = type == V_114 ;
V_8 -> V_75 = V_98 ;
V_8 -> V_131 = V_98 ;
V_8 -> V_132 = V_133 ;
V_8 -> V_76 = & V_77 ;
F_72 ( & V_8 -> V_134 , L_30 , V_2 ) ;
V_8 -> V_134 . V_135 = NULL ;
V_8 -> V_134 . V_136 = & V_137 ;
V_8 -> V_134 . V_138 = & V_8 -> V_138 ;
V_8 -> V_138 = ( V_139 ) 0xffffffff ;
V_8 -> V_134 . V_140 = V_8 -> V_138 ;
if ( V_2 < 4 ) {
F_73 ( V_8 , V_12 ,
V_141 + ( V_2 << 14 ) ,
V_142 ) ;
V_24 = V_143 + ( V_2 << 14 ) ;
} else
V_24 = V_144 + ( ( V_2 - 4 ) << 14 ) ;
#ifdef F_74
if ( V_2 < 8 ) {
F_73 ( V_8 , V_14 ,
V_145 + ( V_2 << 24 ) ,
V_146 ) ;
}
if ( V_2 == 8 ) {
F_73 ( V_8 , V_12 , V_147 , V_148 ) ;
} else
#endif
for ( V_127 = 0 ; V_127 <= V_15 - V_149 ; V_127 ++ )
F_73 ( V_8 , V_127 + V_149 ,
V_24 + ( V_127 << 19 ) , V_150 ) ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
if ( V_8 -> V_9 [ V_127 ] . V_129 &&
F_75 ( & V_151 , & V_8 -> V_9 [ V_127 ] ) ) {
F_76 ( & V_8 -> V_134 , L_31 ) ;
V_8 -> V_9 [ V_127 ] . V_152 -= V_8 -> V_9 [ V_127 ] . V_16 ;
V_8 -> V_9 [ V_127 ] . V_16 = 0 ;
V_8 -> V_9 [ V_127 ] . V_129 = 0 ;
}
}
V_130:
return V_8 ;
}
static T_7 F_77 ( struct V_153 * V_134 , struct V_154 * V_155 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_75 ) ;
}
static T_7 F_79 ( struct V_153 * V_134 , struct V_154 * V_155 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_132 ) ;
}
static T_7 F_80 ( struct V_153 * V_134 , struct V_154 * V_155 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
char * V_156 = V_18 ;
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ )
V_156 += sprintf ( V_156 , L_33 ,
V_8 -> V_9 [ V_127 ] . V_16 ,
V_8 -> V_9 [ V_127 ] . V_152 ,
V_8 -> V_9 [ V_127 ] . V_129 ) ;
return V_156 - V_18 ;
}
static T_7 F_81 ( struct V_153 * V_134 , struct V_154 * V_155 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_62 . V_120 ) ;
}
static T_7 F_82 ( struct V_153 * V_134 , struct V_154 * V_155 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_62 . V_121 ) ;
}
static T_7 F_83 ( struct V_153 * V_134 , struct V_154 * V_155 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
return sprintf ( V_18 , L_25 , V_8 -> V_13 ? L_22 : L_34 ) ;
}
int F_84 ( struct V_7 * V_8 )
{
int V_127 , V_157 = 0 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ ) {
if ( F_85 ( V_8 , V_127 ) &&
! F_86 ( F_87 ( V_8 , V_127 ) ,
F_88 ( V_8 , V_127 ) ,
V_8 -> V_134 . V_158 -> V_159 ) ) {
V_157 = - V_160 ;
break;
}
}
if ( V_157 ) {
while ( V_127 -- )
if ( F_85 ( V_8 , V_127 ) )
F_89 ( F_87 ( V_8 , V_127 ) ,
F_88 ( V_8 , V_127 ) ) ;
}
return V_157 ;
}
void F_90 ( struct V_7 * V_8 )
{
int V_127 ;
for ( V_127 = 0 ; V_127 < V_128 ; V_127 ++ )
if ( F_85 ( V_8 , V_127 ) )
F_89 ( F_87 ( V_8 , V_127 ) ,
F_88 ( V_8 , V_127 ) ) ;
}
void F_91 ( struct V_7 * V_8 , const struct V_161 * V_76 , void * V_74 )
{
V_8 -> V_74 = V_74 ;
F_92 () ;
V_8 -> V_76 = V_76 ;
}
void T_2 * F_93 ( struct V_7 * V_8 , unsigned int V_10 ,
unsigned long V_162 , unsigned long V_163 )
{
unsigned long V_16 = F_87 ( V_8 , V_10 ) ;
unsigned long V_152 = F_85 ( V_8 , V_10 ) ;
if ( V_162 > ( V_152 - V_16 ) )
return NULL ;
V_16 += V_162 ;
if ( V_163 && V_152 - V_16 > V_163 )
V_152 = V_16 + V_163 ;
return F_94 ( & V_8 -> V_134 , V_16 , V_152 - V_16 ) ;
}
static int T_4
F_95 ( int V_2 , T_5 type )
{
T_1 * * V_164 ;
T_1 * V_8 ;
struct V_165 V_62 ;
void T_2 * V_54 ;
int V_127 , V_166 ;
V_8 = F_69 ( type , V_2 ) ;
if ( F_96 ( V_8 ) ) {
V_166 = F_97 ( V_8 ) ;
goto V_130;
}
V_166 = - V_167 ;
if ( ( V_54 = F_55 ( V_8 , type , V_168 ) ) == NULL )
goto V_169;
V_62 . V_170 = 1 ;
F_28 ( & V_62 , V_8 , 0 , 16 , 0 ) ;
if ( V_62 . V_170 )
goto V_169;
V_8 -> V_62 . V_58 = V_62 . V_171 ;
V_8 -> V_62 . V_57 = V_62 . V_172 ;
V_8 -> V_62 . V_173 = V_62 . V_174 ;
V_8 -> V_62 . V_175 = V_62 . V_176 ;
V_8 -> V_62 . V_120 = F_1 ( V_62 . V_177 ) ;
V_8 -> V_62 . V_121 = F_1 ( V_62 . V_178 ) ;
V_8 -> V_62 . V_179 = V_62 . V_180 ;
V_8 -> V_62 . V_69 = V_62 . V_181 ;
V_8 -> V_62 . V_182 = F_2 ( V_62 . V_183 ) ;
V_8 -> V_62 . V_72 = V_62 . V_184 ;
V_8 -> V_62 . V_185 = F_2 ( V_62 . V_186 ) ;
V_8 -> V_73 =
V_8 -> V_70 = V_54 ;
if ( V_8 -> V_62 . V_173 ) {
V_8 -> V_69 = V_8 -> V_62 . V_69 ;
V_8 -> V_70 += V_8 -> V_62 . V_182 ;
V_8 -> V_72 = V_8 -> V_62 . V_72 ;
V_8 -> V_73 += V_8 -> V_62 . V_185 ;
} else {
V_8 -> V_69 = 1 ;
V_8 -> V_72 = 4 ;
}
for ( V_127 = 0 ; V_127 < F_98 ( V_187 ) ; V_127 ++ )
if ( V_187 [ V_127 ] . V_120 == V_8 -> V_62 . V_120 &&
V_187 [ V_127 ] . V_121 == V_8 -> V_62 . V_121 ) {
V_8 -> V_122 = V_187 [ V_127 ] . type ;
break;
}
if ( V_2 < 8 ) {
V_8 -> V_75 = 32 + V_2 ;
F_99 ( V_8 -> V_75 , & V_188 ,
V_189 ) ;
F_100 ( V_8 -> V_75 , V_190 ) ;
}
if ( V_2 == 8 )
V_8 -> V_75 = 11 ;
#ifdef F_74
if ( V_2 < 2 )
V_8 -> V_132 = 2 + V_2 ;
#endif
for ( V_164 = & V_84 ; * V_164 ; V_164 = & ( * V_164 ) -> V_85 ) ;
* V_164 = V_8 ;
V_4 [ V_2 ] = V_8 ;
F_101 ( & V_8 -> V_134 ) ;
return 0 ;
V_169:
F_66 ( V_8 ) ;
V_130:
return V_166 ;
}
static int T_4 F_102 ( void )
{
struct V_191 * V_192 ;
int V_2 , V_193 ;
V_192 = F_103 ( F_17 , NULL , L_35 ) ;
if ( F_96 ( V_192 ) ) {
F_43 ( V_80 L_36 ,
F_97 ( V_192 ) ) ;
return F_97 ( V_192 ) ;
}
F_43 ( L_37 ) ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
if ( F_95 ( V_2 , V_114 ) == - V_167 )
F_95 ( V_2 , V_111 ) ;
}
F_95 ( 8 , V_111 ) ;
V_193 = F_54 () ;
F_104 ( V_194 ,
V_193 ? F_52 : F_50 ) ;
F_63 () ;
return 0 ;
}
static const struct V_195 *
F_105 ( const struct V_195 * V_196 , struct V_7 * V_8 )
{
int V_127 ;
for ( V_127 = 0 ; V_196 [ V_127 ] . V_120 != 65535 ; V_127 ++ )
if ( V_8 -> V_62 . V_120 == V_196 [ V_127 ] . V_120 &&
V_8 -> V_62 . V_121 == V_196 [ V_127 ] . V_121 )
return V_196 + V_127 ;
return NULL ;
}
static int F_106 ( struct V_153 * V_134 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
struct V_197 * V_198 = F_107 ( V_134 -> V_158 ) ;
const struct V_195 * V_58 ;
int V_199 ;
V_58 = F_105 ( V_198 -> V_200 , V_8 ) ;
V_8 -> V_78 = 1 ;
V_199 = V_198 -> V_201 ( V_8 , V_58 ) ;
if ( V_199 )
V_8 -> V_78 = 0 ;
return V_199 ;
}
static int F_108 ( struct V_153 * V_134 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
struct V_197 * V_198 = F_107 ( V_134 -> V_158 ) ;
V_198 -> remove ( V_8 ) ;
V_8 -> V_78 = 0 ;
V_8 -> V_76 = & V_77 ;
F_92 () ;
V_8 -> V_74 = NULL ;
return 0 ;
}
static void F_109 ( struct V_153 * V_134 )
{
struct V_7 * V_8 = F_78 ( V_134 ) ;
struct V_197 * V_198 = F_107 ( V_134 -> V_158 ) ;
struct V_5 V_6 ;
if ( V_134 -> V_158 ) {
if ( V_198 -> V_202 )
V_198 -> V_202 ( V_8 ) ;
V_8 -> V_78 = 0 ;
}
if ( V_8 -> V_17 ) {
V_6 . V_51 = F_4 ;
V_6 . V_8 = V_8 ;
F_22 ( & V_6 ) ;
}
}
int F_110 ( struct V_197 * V_198 )
{
V_198 -> V_198 . V_136 = & V_137 ;
return F_111 ( & V_198 -> V_198 ) ;
}
void F_112 ( struct V_197 * V_198 )
{
F_113 ( & V_198 -> V_198 ) ;
}
static int F_114 ( struct V_153 * V_203 , struct V_204 * V_205 )
{
struct V_7 * V_8 = F_78 ( V_203 ) ;
struct V_197 * V_198 = F_107 ( V_205 ) ;
int V_199 ;
if ( V_198 -> V_200 ) {
V_199 = F_105 ( V_198 -> V_200 , V_8 ) != NULL ;
} else {
V_199 = V_8 -> V_62 . V_58 == V_198 -> V_58 ;
}
return V_199 ;
}
static int F_115 ( void )
{
return F_116 ( & V_137 ) ;
}
