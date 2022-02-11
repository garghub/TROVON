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
V_32 . V_42 = V_30 ;
F_12 ( & V_32 , V_36 , V_36 + V_37 ) ;
F_12 ( & V_32 , V_40 , V_40 + V_41 ) ;
}
static int F_13 ( void )
{
struct V_29 * V_30 = F_14 () ;
struct V_29 * V_43 = V_44 -> V_43 ;
if ( ! V_30 )
return - V_45 ;
V_44 -> V_30 = V_30 ;
V_44 -> V_43 = V_30 ;
F_15 ( V_43 , V_30 ) ;
F_16 ( V_43 ) ;
F_10 ( V_30 ) ;
return 0 ;
}
static int
F_17 ( void * V_46 )
{
if ( F_13 () )
F_18 ( L_1 ) ;
while ( 1 ) {
struct V_5 * V_6 ;
F_19 ( V_47 , V_48 != NULL ) ;
V_6 = F_20 ( & V_48 , NULL ) ;
if ( V_6 != NULL ) {
V_6 -> V_49 ( V_6 ) ;
F_21 ( V_6 -> F_21 ) ;
}
}
}
static void F_22 ( struct V_5 * V_6 )
{
F_23 ( V_50 ) ;
V_6 -> F_21 = & V_50 ;
F_24 ( & V_51 ) ;
V_48 = V_6 ;
F_25 ( & V_47 ) ;
F_26 ( & V_50 ) ;
F_27 ( & V_51 ) ;
}
static void
F_28 ( void * V_52 , T_1 * V_8 , int V_22 , int V_20 , int V_53 )
{
struct V_5 V_6 ;
V_6 . V_49 = F_6 ;
V_6 . V_8 = V_8 ;
V_6 . V_23 = V_22 ;
V_6 . V_21 = V_20 ;
V_6 . V_28 = V_53 ;
V_6 . V_19 = V_52 ;
F_22 ( & V_6 ) ;
}
int F_29 ( struct V_54 * V_55 , T_1 * V_8 , int V_56 , int V_57 )
{
struct V_58 V_59 ;
int V_25 = 16 ;
int V_53 = 0 ;
if ( ! V_8 -> V_60 . V_55 )
return 0 ;
while( 1 ) {
F_28 ( & V_59 , V_8 , V_25 , 8 , V_53 ) ;
V_25 += 8 ;
if ( F_30 ( & V_59 ) == 0 ) {
if ( ! V_53 && V_8 -> V_17 ) {
V_53 = 1 ;
V_25 = 0 ;
continue;
}
return 0 ;
}
if ( F_30 ( & V_59 ) == 0xf0 ) {
V_25 = F_31 ( & V_59 ) ;
continue;
}
if ( F_30 ( & V_59 ) == 0x80 ) {
if ( ! V_8 -> V_17 ) {
V_8 -> V_17 = F_32 ( F_33 ( & V_59 ) ,
V_61 ) ;
if ( V_8 -> V_17 )
F_28 ( V_8 -> V_17 , V_8 ,
( int ) F_31 ( & V_59 ) ,
F_33 ( & V_59 ) , V_53 ) ;
else
return 0 ;
}
continue;
}
if ( F_30 ( & V_59 ) == V_56 && V_57 -- == 0 )
break;
}
if ( F_30 ( & V_59 ) & 0x80 ) {
switch ( F_30 ( & V_59 ) & 0x70 ) {
case 0x70 :
F_28 ( ( unsigned char * ) V_59 . V_62 . string , V_8 ,
( int ) F_31 ( & V_59 ) , F_33 ( & V_59 ) ,
V_53 ) ;
break;
case 0x00 :
break;
}
}
V_55 -> V_63 = F_31 ( & V_59 ) ;
memcpy ( V_55 -> V_62 . string , V_59 . V_62 . string , 256 ) ;
return 1 ;
}
static void F_34 ( T_1 * V_8 , int V_64 )
{
#ifdef F_35
if ( V_64 < 4 && V_65 ) {
V_65 |= 1 << V_64 ;
F_36 ( V_65 , V_66 ) ;
}
#endif
}
static void F_37 ( T_1 * V_8 , int V_64 )
{
#ifdef F_35
if ( V_64 < 4 && V_65 ) {
V_65 &= ~ ( 1 << V_64 ) ;
F_36 ( V_65 , V_66 ) ;
}
#endif
}
static int F_38 ( T_1 * V_8 )
{
return ! V_8 -> V_67 || F_8 ( V_8 -> V_68 ) & V_8 -> V_67 ;
}
static void F_39 ( T_1 * V_8 , int V_69 )
{
F_18 ( L_2 ) ;
}
static void F_40 ( T_1 * V_8 , int V_69 )
{
F_18 ( L_3 ) ;
}
static int F_41 ( T_1 * V_8 )
{
return ! V_8 -> V_70 || F_8 ( V_8 -> V_71 ) & V_8 -> V_70 ;
}
static void F_42 ( struct V_72 * V_62 )
{
T_1 * V_8 = F_3 ( V_62 -> V_73 - 32 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_74 )
V_8 -> V_74 = & V_75 ;
if ( V_8 -> V_76 && V_8 -> V_74 -> V_77 )
V_8 -> V_74 -> V_77 ( V_8 , V_62 -> V_73 ) ;
else
F_43 ( V_78 L_4
L_5 , V_62 -> V_73 ) ;
}
}
static void F_44 ( struct V_72 * V_62 )
{
T_1 * V_8 = F_3 ( V_62 -> V_73 - 32 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_74 )
V_8 -> V_74 = & V_75 ;
if ( V_8 -> V_74 && V_8 -> V_74 -> V_79 )
V_8 -> V_74 -> V_79 ( V_8 , V_62 -> V_73 ) ;
}
}
void F_45 ( unsigned int V_69 )
{
T_1 * V_8 = F_3 ( V_69 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_74 )
V_8 -> V_74 = & V_75 ;
if ( V_8 -> V_76 && V_8 -> V_74 -> V_80 )
V_8 -> V_74 -> V_80 ( V_8 , V_69 ) ;
else
F_43 ( V_78 L_4
L_6 , V_69 ) ;
}
}
void F_46 ( unsigned int V_69 )
{
T_1 * V_8 = F_3 ( V_69 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_74 )
V_8 -> V_74 = & V_75 ;
if ( V_8 -> V_74 -> V_81 )
V_8 -> V_74 -> V_81 ( V_8 , V_69 ) ;
}
}
static void F_47 ( void )
{
T_1 * V_8 ;
F_43 ( L_7 ) ;
for ( V_8 = V_82 ; V_8 ; V_8 = V_8 -> V_83 ) {
if ( V_8 -> V_11 == 8 )
continue;
F_43 ( L_8 ,
V_8 -> V_11 , V_8 -> V_76 ? L_9 : L_10 ) ;
if ( V_8 -> V_74 && V_8 -> V_74 -> V_84 &&
V_8 -> V_74 != & V_75 )
F_43 ( L_11 ,
V_8 -> V_74 -> V_84 ( V_8 ) ? L_9 : L_10 ) ;
else
F_43 ( L_12 ,
V_8 -> V_68 , V_8 -> V_67 , F_8 ( V_8 -> V_68 ) ) ;
}
}
static void F_48 ( struct V_85 * V_86 )
{
static unsigned long V_87 ;
static int V_88 ;
if ( V_87 == V_89 ) {
V_88 += 1 ;
if ( V_88 > 1000000 ) {
F_43 ( V_78 L_13
L_14 ) ;
V_86 -> V_72 . V_90 -> V_91 ( & V_86 -> V_72 ) ;
F_47 () ;
}
} else
V_88 = 0 ;
if ( ! V_87 || F_49 ( V_89 , V_87 + 5 * V_92 ) ) {
V_87 = V_89 ;
F_43 ( V_93 L_15 ) ;
F_47 () ;
}
}
static void
F_50 ( unsigned int V_73 , struct V_85 * V_86 )
{
T_1 * V_8 ;
int V_94 = 0 ;
V_86 -> V_72 . V_90 -> V_91 ( & V_86 -> V_72 ) ;
for ( V_8 = V_82 ; V_8 ; V_8 = V_8 -> V_83 ) {
int V_95 ;
if ( ! V_8 -> V_76 || V_8 -> V_73 == V_96 || V_8 -> V_11 == 8 )
continue;
if ( V_8 -> V_74 && V_8 -> V_74 -> V_84 )
V_95 = V_8 -> V_74 -> V_84 ( V_8 ) ;
else
V_95 = V_75 . V_84 ( V_8 ) ;
if ( V_95 ) {
F_51 ( V_8 -> V_73 ) ;
V_94 ++ ;
}
}
V_86 -> V_72 . V_90 -> V_97 ( & V_86 -> V_72 ) ;
if ( V_94 == 0 )
F_48 ( V_86 ) ;
}
static void
F_52 ( unsigned int V_73 , struct V_85 * V_86 )
{
const unsigned int V_98 = 15 ;
unsigned int V_99 ;
V_99 = F_53 ( V_100 ) & V_98 ;
if ( V_99 ) {
unsigned int V_2 = V_101 [ V_99 ] ;
T_1 * V_8 = F_3 ( V_2 ) ;
if ( V_8 -> V_76 ) {
F_51 ( V_8 -> V_73 ) ;
} else {
F_43 ( V_93 L_16
L_17 , V_2 ) ;
V_65 &= ~ ( 1 << V_2 ) ;
F_36 ( V_65 , V_66 ) ;
}
} else
F_43 ( V_93 L_18 ) ;
}
static int T_4 F_54 ( void )
{
T_1 * V_8 ;
int V_102 ;
F_36 ( 0x00 , V_66 ) ;
F_36 ( 0xff , V_100 ) ;
V_102 = ( F_53 ( V_100 ) & 15 ) == 0 ;
F_36 ( 0xff , V_66 ) ;
if ( V_102 ) {
F_43 ( V_103 L_19
L_20 ) ;
V_65 = 0x80000000 ;
for ( V_8 = V_82 ; V_8 ; V_8 = V_8 -> V_83 )
V_65 |= 1 << V_8 -> V_11 ;
F_36 ( V_65 , V_66 ) ;
}
return V_102 ;
}
static void T_2 * F_55 ( T_1 * V_8 , T_5 type , T_6 V_104 )
{
void T_2 * V_23 = NULL ;
int V_2 = V_8 -> V_11 ;
if ( V_8 -> V_11 == 8 )
return V_105 ;
V_106 &= ~ ( 1 << V_2 ) ;
switch ( type ) {
case V_107 :
if ( V_2 < 4 )
V_23 = V_108 + ( V_2 << 14 ) ;
break;
case V_109 :
if ( V_2 < 4 )
V_23 = V_110 + ( V_2 << 14 ) ;
else
V_23 = V_111 + ( ( V_2 - 4 ) << 14 ) ;
if ( V_23 )
V_23 += V_104 << 19 ;
break;
case V_112 :
V_23 = V_113 + ( V_2 << 24 ) ;
if ( V_104 == V_114 )
V_106 |= 1 << V_2 ;
break;
default:
break;
}
#ifdef F_56
F_57 ( V_106 , F_56 ) ;
#endif
return V_23 ;
}
static int F_58 ( struct V_115 * V_116 , T_1 * V_8 )
{
F_59 ( V_116 , L_21 , V_8 -> V_11 , V_8 -> V_13 ? L_22 : L_23 ) ;
if ( V_8 -> V_60 . V_56 == 0 ) {
struct V_54 V_117 ;
F_59 ( V_116 , L_24 ,
V_8 -> V_60 . V_118 , V_8 -> V_60 . V_119 ) ;
if ( ! V_8 -> V_120 && V_8 -> V_60 . V_55 &&
F_29 ( & V_117 , V_8 , 0xf5 , 0 ) ) {
V_8 -> V_120 = F_32 ( strlen ( V_117 . V_62 . string ) + 1 , V_61 ) ;
if ( V_8 -> V_120 )
strcpy ( ( char * ) V_8 -> V_120 , V_117 . V_62 . string ) ;
}
F_59 ( V_116 , L_25 , V_8 -> V_120 ? V_8 -> V_120 : L_26 ) ;
} else
F_59 ( V_116 , L_27 , V_8 -> V_60 . V_56 ) ;
return 0 ;
}
static int F_60 ( struct V_115 * V_116 , void * V_1 )
{
T_1 * V_8 = V_82 ;
while ( V_8 ) {
F_58 ( V_116 , V_8 ) ;
V_8 = V_8 -> V_83 ;
}
return 0 ;
}
static int F_61 ( struct V_121 * V_121 , struct V_122 * V_122 )
{
return F_62 ( V_122 , F_60 , NULL ) ;
}
static void F_63 ( void )
{
V_123 = F_64 ( L_28 , NULL ) ;
F_65 ( L_29 , 0 , V_123 , & V_124 ) ;
}
static void T_4 F_66 ( struct V_7 * V_8 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ )
if ( V_8 -> V_9 [ V_125 ] . V_127 )
F_67 ( & V_8 -> V_9 [ V_125 ] ) ;
F_68 ( V_8 ) ;
}
static struct V_7 * T_4 F_69 ( int type , int V_2 )
{
struct V_7 * V_8 ;
unsigned long V_24 ;
int V_125 ;
V_8 = F_70 ( sizeof( T_1 ) , V_61 ) ;
if ( ! V_8 ) {
V_8 = F_71 ( - V_45 ) ;
goto V_128;
}
V_8 -> V_11 = V_2 ;
V_8 -> V_13 = type == V_112 ;
V_8 -> V_73 = V_96 ;
V_8 -> V_129 = V_96 ;
V_8 -> V_130 = V_131 ;
V_8 -> V_74 = & V_75 ;
F_72 ( & V_8 -> V_132 , L_30 , V_2 ) ;
V_8 -> V_132 . V_133 = NULL ;
V_8 -> V_132 . V_134 = & V_135 ;
V_8 -> V_132 . V_136 = & V_8 -> V_136 ;
V_8 -> V_136 = ( V_137 ) 0xffffffff ;
V_8 -> V_132 . V_138 = V_8 -> V_136 ;
if ( V_2 < 4 ) {
F_73 ( V_8 , V_12 ,
V_139 + ( V_2 << 14 ) ,
V_140 ) ;
V_24 = V_141 + ( V_2 << 14 ) ;
} else
V_24 = V_142 + ( ( V_2 - 4 ) << 14 ) ;
#ifdef F_74
if ( V_2 < 8 ) {
F_73 ( V_8 , V_14 ,
V_143 + ( V_2 << 24 ) ,
V_144 ) ;
}
if ( V_2 == 8 ) {
F_73 ( V_8 , V_12 , V_145 , V_146 ) ;
} else
#endif
for ( V_125 = 0 ; V_125 <= V_15 - V_147 ; V_125 ++ )
F_73 ( V_8 , V_125 + V_147 ,
V_24 + ( V_125 << 19 ) , V_148 ) ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
if ( V_8 -> V_9 [ V_125 ] . V_127 &&
F_75 ( & V_149 , & V_8 -> V_9 [ V_125 ] ) ) {
F_76 ( & V_8 -> V_132 , L_31 ) ;
V_8 -> V_9 [ V_125 ] . V_150 -= V_8 -> V_9 [ V_125 ] . V_16 ;
V_8 -> V_9 [ V_125 ] . V_16 = 0 ;
V_8 -> V_9 [ V_125 ] . V_127 = 0 ;
}
}
V_128:
return V_8 ;
}
static T_7 F_77 ( struct V_151 * V_132 , struct V_152 * V_153 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_73 ) ;
}
static T_7 F_79 ( struct V_151 * V_132 , struct V_152 * V_153 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_130 ) ;
}
static T_7 F_80 ( struct V_151 * V_132 , struct V_152 * V_153 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
char * V_154 = V_18 ;
int V_125 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ )
V_154 += sprintf ( V_154 , L_33 ,
V_8 -> V_9 [ V_125 ] . V_16 ,
V_8 -> V_9 [ V_125 ] . V_150 ,
V_8 -> V_9 [ V_125 ] . V_127 ) ;
return V_154 - V_18 ;
}
static T_7 F_81 ( struct V_151 * V_132 , struct V_152 * V_153 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_60 . V_118 ) ;
}
static T_7 F_82 ( struct V_151 * V_132 , struct V_152 * V_153 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
return sprintf ( V_18 , L_32 , V_8 -> V_60 . V_119 ) ;
}
static T_7 F_83 ( struct V_151 * V_132 , struct V_152 * V_153 , char * V_18 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
return sprintf ( V_18 , L_25 , V_8 -> V_13 ? L_22 : L_34 ) ;
}
int F_84 ( struct V_7 * V_8 )
{
int V_125 , V_155 = 0 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ ) {
if ( F_85 ( V_8 , V_125 ) &&
! F_86 ( F_87 ( V_8 , V_125 ) ,
F_88 ( V_8 , V_125 ) ,
V_8 -> V_132 . V_156 -> V_157 ) ) {
V_155 = - V_158 ;
break;
}
}
if ( V_155 ) {
while ( V_125 -- )
if ( F_85 ( V_8 , V_125 ) )
F_89 ( F_87 ( V_8 , V_125 ) ,
F_88 ( V_8 , V_125 ) ) ;
}
return V_155 ;
}
void F_90 ( struct V_7 * V_8 )
{
int V_125 ;
for ( V_125 = 0 ; V_125 < V_126 ; V_125 ++ )
if ( F_85 ( V_8 , V_125 ) )
F_89 ( F_87 ( V_8 , V_125 ) ,
F_88 ( V_8 , V_125 ) ) ;
}
void F_91 ( struct V_7 * V_8 , const struct V_159 * V_74 , void * V_72 )
{
V_8 -> V_72 = V_72 ;
F_92 () ;
V_8 -> V_74 = V_74 ;
}
void T_2 * F_93 ( struct V_7 * V_8 , unsigned int V_10 ,
unsigned long V_160 , unsigned long V_161 )
{
unsigned long V_16 = F_87 ( V_8 , V_10 ) ;
unsigned long V_150 = F_85 ( V_8 , V_10 ) ;
if ( V_160 > ( V_150 - V_16 ) )
return NULL ;
V_16 += V_160 ;
if ( V_161 && V_150 - V_16 > V_161 )
V_150 = V_16 + V_161 ;
return F_94 ( & V_8 -> V_132 , V_16 , V_150 - V_16 ) ;
}
static int T_4
F_95 ( int V_2 , T_5 type )
{
T_1 * * V_162 ;
T_1 * V_8 ;
struct V_163 V_60 ;
void T_2 * V_52 ;
int V_125 , V_164 ;
V_8 = F_69 ( type , V_2 ) ;
if ( F_96 ( V_8 ) ) {
V_164 = F_97 ( V_8 ) ;
goto V_128;
}
V_164 = - V_165 ;
if ( ( V_52 = F_55 ( V_8 , type , V_166 ) ) == NULL )
goto V_167;
V_60 . V_168 = 1 ;
F_28 ( & V_60 , V_8 , 0 , 16 , 0 ) ;
if ( V_60 . V_168 )
goto V_167;
V_8 -> V_60 . V_56 = V_60 . V_169 ;
V_8 -> V_60 . V_55 = V_60 . V_170 ;
V_8 -> V_60 . V_171 = V_60 . V_172 ;
V_8 -> V_60 . V_173 = V_60 . V_174 ;
V_8 -> V_60 . V_118 = F_1 ( V_60 . V_175 ) ;
V_8 -> V_60 . V_119 = F_1 ( V_60 . V_176 ) ;
V_8 -> V_60 . V_177 = V_60 . V_178 ;
V_8 -> V_60 . V_67 = V_60 . V_179 ;
V_8 -> V_60 . V_180 = F_2 ( V_60 . V_181 ) ;
V_8 -> V_60 . V_70 = V_60 . V_182 ;
V_8 -> V_60 . V_183 = F_2 ( V_60 . V_184 ) ;
V_8 -> V_71 =
V_8 -> V_68 = V_52 ;
if ( V_8 -> V_60 . V_171 ) {
V_8 -> V_67 = V_8 -> V_60 . V_67 ;
V_8 -> V_68 += V_8 -> V_60 . V_180 ;
V_8 -> V_70 = V_8 -> V_60 . V_70 ;
V_8 -> V_71 += V_8 -> V_60 . V_183 ;
} else {
V_8 -> V_67 = 1 ;
V_8 -> V_70 = 4 ;
}
for ( V_125 = 0 ; V_125 < F_98 ( V_185 ) ; V_125 ++ )
if ( V_185 [ V_125 ] . V_118 == V_8 -> V_60 . V_118 &&
V_185 [ V_125 ] . V_119 == V_8 -> V_60 . V_119 ) {
V_8 -> V_120 = V_185 [ V_125 ] . type ;
break;
}
if ( V_2 < 8 ) {
V_8 -> V_73 = 32 + V_2 ;
F_99 ( V_8 -> V_73 , & V_186 ,
V_187 ) ;
F_100 ( V_8 -> V_73 , V_188 ) ;
}
if ( V_2 == 8 )
V_8 -> V_73 = 11 ;
#ifdef F_74
if ( V_2 < 2 )
V_8 -> V_130 = 2 + V_2 ;
#endif
for ( V_162 = & V_82 ; * V_162 ; V_162 = & ( * V_162 ) -> V_83 ) ;
* V_162 = V_8 ;
V_4 [ V_2 ] = V_8 ;
F_101 ( & V_8 -> V_132 ) ;
return 0 ;
V_167:
F_66 ( V_8 ) ;
V_128:
return V_164 ;
}
static int T_4 F_102 ( void )
{
struct V_189 * V_190 ;
int V_2 , V_191 ;
V_190 = F_103 ( F_17 , NULL , L_35 ) ;
if ( F_96 ( V_190 ) ) {
F_43 ( V_78 L_36 ,
F_97 ( V_190 ) ) ;
return F_97 ( V_190 ) ;
}
F_43 ( L_37 ) ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
if ( F_95 ( V_2 , V_112 ) == - V_165 )
F_95 ( V_2 , V_109 ) ;
}
F_95 ( 8 , V_109 ) ;
V_191 = F_54 () ;
F_104 ( V_192 ,
V_191 ? F_52 : F_50 ) ;
F_63 () ;
return 0 ;
}
static const struct V_193 *
F_105 ( const struct V_193 * V_194 , struct V_7 * V_8 )
{
int V_125 ;
for ( V_125 = 0 ; V_194 [ V_125 ] . V_118 != 65535 ; V_125 ++ )
if ( V_8 -> V_60 . V_118 == V_194 [ V_125 ] . V_118 &&
V_8 -> V_60 . V_119 == V_194 [ V_125 ] . V_119 )
return V_194 + V_125 ;
return NULL ;
}
static int F_106 ( struct V_151 * V_132 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
struct V_195 * V_196 = F_107 ( V_132 -> V_156 ) ;
const struct V_193 * V_56 ;
int V_197 ;
V_56 = F_105 ( V_196 -> V_198 , V_8 ) ;
V_8 -> V_76 = 1 ;
V_197 = V_196 -> V_199 ( V_8 , V_56 ) ;
if ( V_197 )
V_8 -> V_76 = 0 ;
return V_197 ;
}
static int F_108 ( struct V_151 * V_132 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
struct V_195 * V_196 = F_107 ( V_132 -> V_156 ) ;
V_196 -> remove ( V_8 ) ;
V_8 -> V_76 = 0 ;
V_8 -> V_74 = & V_75 ;
F_92 () ;
V_8 -> V_72 = NULL ;
return 0 ;
}
static void F_109 ( struct V_151 * V_132 )
{
struct V_7 * V_8 = F_78 ( V_132 ) ;
struct V_195 * V_196 = F_107 ( V_132 -> V_156 ) ;
struct V_5 V_6 ;
if ( V_132 -> V_156 ) {
if ( V_196 -> V_200 )
V_196 -> V_200 ( V_8 ) ;
V_8 -> V_76 = 0 ;
}
if ( V_8 -> V_17 ) {
V_6 . V_49 = F_4 ;
V_6 . V_8 = V_8 ;
F_22 ( & V_6 ) ;
}
}
int F_110 ( struct V_195 * V_196 )
{
V_196 -> V_196 . V_134 = & V_135 ;
return F_111 ( & V_196 -> V_196 ) ;
}
void F_112 ( struct V_195 * V_196 )
{
F_113 ( & V_196 -> V_196 ) ;
}
static int F_114 ( struct V_151 * V_201 , struct V_202 * V_203 )
{
struct V_7 * V_8 = F_78 ( V_201 ) ;
struct V_195 * V_196 = F_107 ( V_203 ) ;
int V_197 ;
if ( V_196 -> V_198 ) {
V_197 = F_105 ( V_196 -> V_198 , V_8 ) != NULL ;
} else {
V_197 = V_8 -> V_60 . V_56 == V_196 -> V_56 ;
}
return V_197 ;
}
static int F_115 ( void )
{
return F_116 ( & V_135 ) ;
}
