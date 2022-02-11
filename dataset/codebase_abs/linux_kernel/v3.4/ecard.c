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
}
static void F_35 ( T_1 * V_8 , int V_66 )
{
}
static int F_36 ( T_1 * V_8 )
{
return ! V_8 -> V_67 || F_8 ( V_8 -> V_68 ) & V_8 -> V_67 ;
}
static void F_37 ( T_1 * V_8 , int V_69 )
{
F_18 ( L_2 ) ;
}
static void F_38 ( T_1 * V_8 , int V_69 )
{
F_18 ( L_3 ) ;
}
static int F_39 ( T_1 * V_8 )
{
return ! V_8 -> V_70 || F_8 ( V_8 -> V_71 ) & V_8 -> V_70 ;
}
static void F_40 ( struct V_72 * V_64 )
{
T_1 * V_8 = F_41 ( V_64 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_73 )
V_8 -> V_73 = & V_74 ;
if ( V_8 -> V_75 && V_8 -> V_73 -> V_76 )
V_8 -> V_73 -> V_76 ( V_8 , V_64 -> V_77 ) ;
else
F_42 ( V_78 L_4
L_5 , V_64 -> V_77 ) ;
}
}
static void F_43 ( struct V_72 * V_64 )
{
T_1 * V_8 = F_41 ( V_64 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_73 )
V_8 -> V_73 = & V_74 ;
if ( V_8 -> V_73 && V_8 -> V_73 -> V_79 )
V_8 -> V_73 -> V_79 ( V_8 , V_64 -> V_77 ) ;
}
}
void F_44 ( unsigned int V_69 )
{
T_1 * V_8 = F_3 ( V_69 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_73 )
V_8 -> V_73 = & V_74 ;
if ( V_8 -> V_75 && V_8 -> V_73 -> V_80 )
V_8 -> V_73 -> V_80 ( V_8 , V_69 ) ;
else
F_42 ( V_78 L_4
L_6 , V_69 ) ;
}
}
void F_45 ( unsigned int V_69 )
{
T_1 * V_8 = F_3 ( V_69 ) ;
if ( V_8 ) {
if ( ! V_8 -> V_73 )
V_8 -> V_73 = & V_74 ;
if ( V_8 -> V_73 -> V_81 )
V_8 -> V_73 -> V_81 ( V_8 , V_69 ) ;
}
}
static void F_46 ( void )
{
T_1 * V_8 ;
F_42 ( L_7 ) ;
for ( V_8 = V_82 ; V_8 ; V_8 = V_8 -> V_83 ) {
if ( V_8 -> V_11 == 8 )
continue;
F_42 ( L_8 ,
V_8 -> V_11 , V_8 -> V_75 ? L_9 : L_10 ) ;
if ( V_8 -> V_73 && V_8 -> V_73 -> V_84 &&
V_8 -> V_73 != & V_74 )
F_42 ( L_11 ,
V_8 -> V_73 -> V_84 ( V_8 ) ? L_9 : L_10 ) ;
else
F_42 ( L_12 ,
V_8 -> V_68 , V_8 -> V_67 , F_8 ( V_8 -> V_68 ) ) ;
}
}
static void F_47 ( struct V_85 * V_86 )
{
static unsigned long V_87 ;
static int V_88 ;
if ( V_87 == V_89 ) {
V_88 += 1 ;
if ( V_88 > 1000000 ) {
F_42 ( V_78 L_13
L_14 ) ;
V_86 -> V_72 . V_90 -> V_91 ( & V_86 -> V_72 ) ;
F_46 () ;
}
} else
V_88 = 0 ;
if ( ! V_87 || F_48 ( V_89 , V_87 + 5 * V_92 ) ) {
V_87 = V_89 ;
F_42 ( V_93 L_15 ) ;
F_46 () ;
}
}
static void
F_49 ( unsigned int V_77 , struct V_85 * V_86 )
{
T_1 * V_8 ;
int V_94 = 0 ;
V_86 -> V_72 . V_90 -> V_91 ( & V_86 -> V_72 ) ;
for ( V_8 = V_82 ; V_8 ; V_8 = V_8 -> V_83 ) {
int V_95 ;
if ( ! V_8 -> V_75 || ! V_8 -> V_77 || V_8 -> V_11 == 8 )
continue;
if ( V_8 -> V_73 && V_8 -> V_73 -> V_84 )
V_95 = V_8 -> V_73 -> V_84 ( V_8 ) ;
else
V_95 = V_74 . V_84 ( V_8 ) ;
if ( V_95 ) {
F_50 ( V_8 -> V_77 ) ;
V_94 ++ ;
}
}
V_86 -> V_72 . V_90 -> V_96 ( & V_86 -> V_72 ) ;
if ( V_94 == 0 )
F_47 ( V_86 ) ;
}
static void T_2 * F_51 ( T_1 * V_8 , T_4 type , T_5 V_97 )
{
void T_2 * V_23 = NULL ;
int V_2 = V_8 -> V_11 ;
if ( V_8 -> V_11 == 8 )
return V_98 ;
V_99 &= ~ ( 1 << V_2 ) ;
switch ( type ) {
case V_100 :
if ( V_2 < 4 )
V_23 = V_101 + ( V_2 << 14 ) ;
break;
case V_102 :
if ( V_2 < 4 )
V_23 = V_103 + ( V_2 << 14 ) ;
else
V_23 = V_104 + ( ( V_2 - 4 ) << 14 ) ;
if ( V_23 )
V_23 += V_97 << 19 ;
break;
case V_105 :
V_23 = V_106 + ( V_2 << 24 ) ;
if ( V_97 == V_107 )
V_99 |= 1 << V_2 ;
break;
default:
break;
}
#ifdef F_52
F_53 ( V_99 , F_52 ) ;
#endif
return V_23 ;
}
static int F_54 ( struct V_108 * V_109 , T_1 * V_8 )
{
F_55 ( V_109 , L_16 , V_8 -> V_11 , V_8 -> V_13 ? L_17 : L_18 ) ;
if ( V_8 -> V_62 . V_58 == 0 ) {
struct V_56 V_110 ;
F_55 ( V_109 , L_19 ,
V_8 -> V_62 . V_111 , V_8 -> V_62 . V_112 ) ;
if ( ! V_8 -> V_113 && V_8 -> V_62 . V_57 &&
F_29 ( & V_110 , V_8 , 0xf5 , 0 ) ) {
V_8 -> V_113 = F_32 ( strlen ( V_110 . V_64 . string ) + 1 , V_63 ) ;
if ( V_8 -> V_113 )
strcpy ( ( char * ) V_8 -> V_113 , V_110 . V_64 . string ) ;
}
F_55 ( V_109 , L_20 , V_8 -> V_113 ? V_8 -> V_113 : L_21 ) ;
} else
F_55 ( V_109 , L_22 , V_8 -> V_62 . V_58 ) ;
return 0 ;
}
static int F_56 ( struct V_108 * V_109 , void * V_1 )
{
T_1 * V_8 = V_82 ;
while ( V_8 ) {
F_54 ( V_109 , V_8 ) ;
V_8 = V_8 -> V_83 ;
}
return 0 ;
}
static int F_57 ( struct V_114 * V_114 , struct V_115 * V_115 )
{
return F_58 ( V_115 , F_56 , NULL ) ;
}
static void F_59 ( void )
{
V_116 = F_60 ( L_23 , NULL ) ;
F_61 ( L_24 , 0 , V_116 , & V_117 ) ;
}
static void T_6 F_62 ( struct V_7 * V_8 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
if ( V_8 -> V_9 [ V_118 ] . V_120 )
F_63 ( & V_8 -> V_9 [ V_118 ] ) ;
F_64 ( V_8 ) ;
}
static struct V_7 * T_6 F_65 ( int type , int V_2 )
{
struct V_7 * V_8 ;
unsigned long V_24 ;
int V_118 ;
V_8 = F_66 ( sizeof( T_1 ) , V_63 ) ;
if ( ! V_8 ) {
V_8 = F_67 ( - V_47 ) ;
goto V_121;
}
V_8 -> V_11 = V_2 ;
V_8 -> V_13 = type == V_105 ;
V_8 -> V_77 = 0 ;
V_8 -> V_122 = 0 ;
V_8 -> V_123 = V_124 ;
V_8 -> V_73 = & V_74 ;
F_68 ( & V_8 -> V_125 , L_25 , V_2 ) ;
V_8 -> V_125 . V_126 = NULL ;
V_8 -> V_125 . V_127 = & V_128 ;
V_8 -> V_125 . V_129 = & V_8 -> V_129 ;
V_8 -> V_129 = ( V_130 ) 0xffffffff ;
V_8 -> V_125 . V_131 = V_8 -> V_129 ;
if ( V_2 < 4 ) {
F_69 ( V_8 , V_12 ,
V_132 + ( V_2 << 14 ) ,
V_133 ) ;
V_24 = V_134 + ( V_2 << 14 ) ;
} else
V_24 = V_135 + ( ( V_2 - 4 ) << 14 ) ;
#ifdef F_70
if ( V_2 < 8 ) {
F_69 ( V_8 , V_14 ,
V_136 + ( V_2 << 24 ) ,
V_137 ) ;
}
if ( V_2 == 8 ) {
F_69 ( V_8 , V_12 , V_138 , V_139 ) ;
} else
#endif
for ( V_118 = 0 ; V_118 <= V_15 - V_140 ; V_118 ++ )
F_69 ( V_8 , V_118 + V_140 ,
V_24 + ( V_118 << 19 ) , V_141 ) ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
if ( V_8 -> V_9 [ V_118 ] . V_120 &&
F_71 ( & V_142 , & V_8 -> V_9 [ V_118 ] ) ) {
F_72 ( & V_8 -> V_125 , L_26 ) ;
V_8 -> V_9 [ V_118 ] . V_143 -= V_8 -> V_9 [ V_118 ] . V_16 ;
V_8 -> V_9 [ V_118 ] . V_16 = 0 ;
V_8 -> V_9 [ V_118 ] . V_120 = 0 ;
}
}
V_121:
return V_8 ;
}
static T_7 F_73 ( struct V_144 * V_125 , struct V_145 * V_146 , char * V_18 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
return sprintf ( V_18 , L_27 , V_8 -> V_77 ) ;
}
static T_7 F_75 ( struct V_144 * V_125 , struct V_145 * V_146 , char * V_18 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
return sprintf ( V_18 , L_27 , V_8 -> V_123 ) ;
}
static T_7 F_76 ( struct V_144 * V_125 , struct V_145 * V_146 , char * V_18 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
char * V_147 = V_18 ;
int V_118 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
V_147 += sprintf ( V_147 , L_28 ,
V_8 -> V_9 [ V_118 ] . V_16 ,
V_8 -> V_9 [ V_118 ] . V_143 ,
V_8 -> V_9 [ V_118 ] . V_120 ) ;
return V_147 - V_18 ;
}
static T_7 F_77 ( struct V_144 * V_125 , struct V_145 * V_146 , char * V_18 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
return sprintf ( V_18 , L_27 , V_8 -> V_62 . V_111 ) ;
}
static T_7 F_78 ( struct V_144 * V_125 , struct V_145 * V_146 , char * V_18 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
return sprintf ( V_18 , L_27 , V_8 -> V_62 . V_112 ) ;
}
static T_7 F_79 ( struct V_144 * V_125 , struct V_145 * V_146 , char * V_18 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
return sprintf ( V_18 , L_20 , V_8 -> V_13 ? L_17 : L_29 ) ;
}
int F_80 ( struct V_7 * V_8 )
{
int V_118 , V_148 = 0 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ ) {
if ( F_81 ( V_8 , V_118 ) &&
! F_82 ( F_83 ( V_8 , V_118 ) ,
F_84 ( V_8 , V_118 ) ,
V_8 -> V_125 . V_149 -> V_150 ) ) {
V_148 = - V_151 ;
break;
}
}
if ( V_148 ) {
while ( V_118 -- )
if ( F_81 ( V_8 , V_118 ) )
F_85 ( F_83 ( V_8 , V_118 ) ,
F_84 ( V_8 , V_118 ) ) ;
}
return V_148 ;
}
void F_86 ( struct V_7 * V_8 )
{
int V_118 ;
for ( V_118 = 0 ; V_118 < V_119 ; V_118 ++ )
if ( F_81 ( V_8 , V_118 ) )
F_85 ( F_83 ( V_8 , V_118 ) ,
F_84 ( V_8 , V_118 ) ) ;
}
void F_87 ( struct V_7 * V_8 , const struct V_152 * V_73 , void * V_72 )
{
V_8 -> V_72 = V_72 ;
F_88 () ;
V_8 -> V_73 = V_73 ;
}
void T_2 * F_89 ( struct V_7 * V_8 , unsigned int V_10 ,
unsigned long V_153 , unsigned long V_154 )
{
unsigned long V_16 = F_83 ( V_8 , V_10 ) ;
unsigned long V_143 = F_81 ( V_8 , V_10 ) ;
if ( V_153 > ( V_143 - V_16 ) )
return NULL ;
V_16 += V_153 ;
if ( V_154 && V_143 - V_16 > V_154 )
V_143 = V_16 + V_154 ;
return F_90 ( & V_8 -> V_125 , V_16 , V_143 - V_16 ) ;
}
static int T_6 F_91 ( int V_2 , unsigned V_77 , T_4 type )
{
T_1 * * V_155 ;
T_1 * V_8 ;
struct V_156 V_62 ;
void T_2 * V_54 ;
int V_118 , V_157 ;
V_8 = F_65 ( type , V_2 ) ;
if ( F_92 ( V_8 ) ) {
V_157 = F_93 ( V_8 ) ;
goto V_121;
}
V_157 = - V_158 ;
if ( ( V_54 = F_51 ( V_8 , type , V_159 ) ) == NULL )
goto V_160;
V_62 . V_161 = 1 ;
F_28 ( & V_62 , V_8 , 0 , 16 , 0 ) ;
if ( V_62 . V_161 )
goto V_160;
V_8 -> V_62 . V_58 = V_62 . V_162 ;
V_8 -> V_62 . V_57 = V_62 . V_163 ;
V_8 -> V_62 . V_164 = V_62 . V_165 ;
V_8 -> V_62 . V_166 = V_62 . V_167 ;
V_8 -> V_62 . V_111 = F_1 ( V_62 . V_168 ) ;
V_8 -> V_62 . V_112 = F_1 ( V_62 . V_169 ) ;
V_8 -> V_62 . V_170 = V_62 . V_171 ;
V_8 -> V_62 . V_67 = V_62 . V_172 ;
V_8 -> V_62 . V_173 = F_2 ( V_62 . V_174 ) ;
V_8 -> V_62 . V_70 = V_62 . V_175 ;
V_8 -> V_62 . V_176 = F_2 ( V_62 . V_177 ) ;
V_8 -> V_71 =
V_8 -> V_68 = V_54 ;
if ( V_8 -> V_62 . V_164 ) {
V_8 -> V_67 = V_8 -> V_62 . V_67 ;
V_8 -> V_68 += V_8 -> V_62 . V_173 ;
V_8 -> V_70 = V_8 -> V_62 . V_70 ;
V_8 -> V_71 += V_8 -> V_62 . V_176 ;
} else {
V_8 -> V_67 = 1 ;
V_8 -> V_70 = 4 ;
}
for ( V_118 = 0 ; V_118 < F_94 ( V_178 ) ; V_118 ++ )
if ( V_178 [ V_118 ] . V_111 == V_8 -> V_62 . V_111 &&
V_178 [ V_118 ] . V_112 == V_8 -> V_62 . V_112 ) {
V_8 -> V_113 = V_178 [ V_118 ] . type ;
break;
}
V_8 -> V_77 = V_77 ;
if ( V_2 < 8 ) {
F_95 ( V_8 -> V_77 , & V_179 ,
V_180 ) ;
F_96 ( V_8 -> V_77 , V_8 ) ;
F_97 ( V_8 -> V_77 , V_181 ) ;
}
#ifdef F_70
if ( V_2 < 2 )
V_8 -> V_123 = 2 + V_2 ;
#endif
for ( V_155 = & V_82 ; * V_155 ; V_155 = & ( * V_155 ) -> V_83 ) ;
* V_155 = V_8 ;
V_4 [ V_2 ] = V_8 ;
F_98 ( & V_8 -> V_125 ) ;
return 0 ;
V_160:
F_62 ( V_8 ) ;
V_121:
return V_157 ;
}
static int T_6 F_99 ( void )
{
struct V_182 * V_183 ;
int V_2 , V_184 ;
V_184 = F_100 ( - 1 , 0 , 8 , - 1 ) ;
if ( V_184 < 0 )
return V_184 ;
V_183 = F_101 ( F_17 , NULL , L_30 ) ;
if ( F_92 ( V_183 ) ) {
F_42 ( V_78 L_31 ,
F_93 ( V_183 ) ) ;
F_102 ( V_184 , 8 ) ;
return F_93 ( V_183 ) ;
}
F_42 ( L_32 ) ;
for ( V_2 = 0 ; V_2 < 8 ; V_2 ++ ) {
if ( F_91 ( V_2 , V_184 + V_2 , V_105 ) == - V_158 )
F_91 ( V_2 , V_184 + V_2 , V_102 ) ;
}
F_91 ( 8 , 11 , V_102 ) ;
F_103 ( V_185 , F_49 ) ;
F_59 () ;
return 0 ;
}
static const struct V_186 *
F_104 ( const struct V_186 * V_187 , struct V_7 * V_8 )
{
int V_118 ;
for ( V_118 = 0 ; V_187 [ V_118 ] . V_111 != 65535 ; V_118 ++ )
if ( V_8 -> V_62 . V_111 == V_187 [ V_118 ] . V_111 &&
V_8 -> V_62 . V_112 == V_187 [ V_118 ] . V_112 )
return V_187 + V_118 ;
return NULL ;
}
static int F_105 ( struct V_144 * V_125 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
struct V_188 * V_189 = F_106 ( V_125 -> V_149 ) ;
const struct V_186 * V_58 ;
int V_190 ;
V_58 = F_104 ( V_189 -> V_191 , V_8 ) ;
V_8 -> V_75 = 1 ;
V_190 = V_189 -> V_192 ( V_8 , V_58 ) ;
if ( V_190 )
V_8 -> V_75 = 0 ;
return V_190 ;
}
static int F_107 ( struct V_144 * V_125 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
struct V_188 * V_189 = F_106 ( V_125 -> V_149 ) ;
V_189 -> remove ( V_8 ) ;
V_8 -> V_75 = 0 ;
V_8 -> V_73 = & V_74 ;
F_88 () ;
V_8 -> V_72 = NULL ;
return 0 ;
}
static void F_108 ( struct V_144 * V_125 )
{
struct V_7 * V_8 = F_74 ( V_125 ) ;
struct V_188 * V_189 = F_106 ( V_125 -> V_149 ) ;
struct V_5 V_6 ;
if ( V_125 -> V_149 ) {
if ( V_189 -> V_193 )
V_189 -> V_193 ( V_8 ) ;
V_8 -> V_75 = 0 ;
}
if ( V_8 -> V_17 ) {
V_6 . V_51 = F_4 ;
V_6 . V_8 = V_8 ;
F_22 ( & V_6 ) ;
}
}
int F_109 ( struct V_188 * V_189 )
{
V_189 -> V_189 . V_127 = & V_128 ;
return F_110 ( & V_189 -> V_189 ) ;
}
void F_111 ( struct V_188 * V_189 )
{
F_112 ( & V_189 -> V_189 ) ;
}
static int F_113 ( struct V_144 * V_194 , struct V_195 * V_196 )
{
struct V_7 * V_8 = F_74 ( V_194 ) ;
struct V_188 * V_189 = F_106 ( V_196 ) ;
int V_190 ;
if ( V_189 -> V_191 ) {
V_190 = F_104 ( V_189 -> V_191 , V_8 ) != NULL ;
} else {
V_190 = V_8 -> V_62 . V_58 == V_189 -> V_58 ;
}
return V_190 ;
}
static int F_114 ( void )
{
return F_115 ( & V_128 ) ;
}
