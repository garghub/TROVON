static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 , * V_4 ;
if ( ! V_5 )
return NULL ;
V_3 = NULL ;
F_2 ( & V_6 . V_7 ) ;
F_3 (v, &vpecontrol.vpe_list, list) {
if ( V_4 -> V_2 == V_2 ) {
V_3 = V_4 ;
break;
}
}
F_4 ( & V_6 . V_7 ) ;
return V_3 ;
}
static struct V_8 * F_5 ( int V_9 )
{
struct V_8 * V_3 , * V_10 ;
V_3 = NULL ;
F_2 ( & V_6 . V_11 ) ;
F_3 (t, &vpecontrol.tc_list, list) {
if ( V_10 -> V_9 == V_9 ) {
V_3 = V_10 ;
break;
}
}
F_4 ( & V_6 . V_11 ) ;
return V_3 ;
}
static struct V_1 * F_6 ( int V_2 )
{
struct V_1 * V_4 ;
if ( ( V_4 = F_7 ( sizeof( struct V_1 ) , V_12 ) ) == NULL )
return NULL ;
F_8 ( & V_4 -> V_8 ) ;
F_2 ( & V_6 . V_7 ) ;
F_9 ( & V_4 -> V_13 , & V_6 . V_14 ) ;
F_4 ( & V_6 . V_7 ) ;
F_8 ( & V_4 -> V_15 ) ;
V_4 -> V_2 = V_2 ;
return V_4 ;
}
static struct V_8 * F_10 ( int V_9 )
{
struct V_8 * V_8 ;
if ( ( V_8 = F_7 ( sizeof( struct V_8 ) , V_12 ) ) == NULL )
goto V_16;
F_8 ( & V_8 -> V_8 ) ;
V_8 -> V_9 = V_9 ;
F_2 ( & V_6 . V_11 ) ;
F_9 ( & V_8 -> V_13 , & V_6 . V_17 ) ;
F_4 ( & V_6 . V_11 ) ;
V_16:
return V_8 ;
}
static void F_11 ( struct V_1 * V_4 )
{
F_12 ( & V_4 -> V_13 ) ;
if ( V_4 -> V_18 )
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
}
static void T_1 F_15 ( void )
{
unsigned long V_19 ;
V_19 = F_16 () ;
F_17 ( L_1 , V_19 ,
( V_19 & V_20 ) >> V_21 ) ;
V_19 = F_18 () ;
F_17 ( L_2 , V_19 ,
( V_19 & V_22 ) >> V_23 ,
( V_19 & V_24 ) >> V_25 ,
( V_19 & V_26 ) ) ;
V_19 = F_19 () ;
F_17 ( L_3 , V_19 ,
( V_19 & V_27 ) >> V_28 ,
V_19 & V_29 , ( V_19 & V_30 ) >> V_31 ) ;
}
static void * F_20 ( unsigned long V_32 )
{
void * V_33 ;
#ifdef F_21
V_33 = F_22 ( V_34 ) ;
memset ( V_33 , 0 , V_32 ) ;
#else
V_33 = F_7 ( V_32 , V_12 ) ;
#endif
return V_33 ;
}
static void F_13 ( void * V_35 )
{
#ifndef F_21
F_14 ( V_35 ) ;
#endif
}
static long F_23 ( unsigned long * V_36 , T_2 * V_37 )
{
long V_38 ;
V_38 = F_24 ( * V_36 , V_37 -> V_39 ? : 1 ) ;
* V_36 = V_38 + V_37 -> V_40 ;
return V_38 ;
}
static void F_25 ( struct V_41 * V_42 , const T_3 * V_43 ,
T_2 * V_44 , const char * V_45 )
{
static unsigned long const V_46 [] [ 2 ] = {
{ V_47 | V_48 , V_49 } ,
{ V_48 , V_50 | V_49 } ,
{ V_50 | V_48 , V_49 } ,
{ V_49 | V_48 , 0 }
} ;
unsigned int V_51 , V_52 ;
for ( V_52 = 0 ; V_52 < V_43 -> V_53 ; V_52 ++ )
V_44 [ V_52 ] . V_54 = ~ 0UL ;
for ( V_51 = 0 ; V_51 < F_26 ( V_46 ) ; ++ V_51 ) {
for ( V_52 = 0 ; V_52 < V_43 -> V_53 ; ++ V_52 ) {
T_2 * V_55 = & V_44 [ V_52 ] ;
if ( ( V_55 -> V_56 & V_46 [ V_51 ] [ 0 ] ) != V_46 [ V_51 ] [ 0 ]
|| ( V_55 -> V_56 & V_46 [ V_51 ] [ 1 ] )
|| V_55 -> V_54 != ~ 0UL )
continue;
V_55 -> V_54 =
F_23 ( ( unsigned long * ) & V_42 -> V_57 , V_55 ) ;
}
if ( V_51 == 0 )
V_42 -> V_58 = V_42 -> V_57 ;
}
}
static int F_27 ( struct V_41 * V_59 , T_4 * V_60 ,
T_5 V_4 )
{
return 0 ;
}
static int F_28 ( struct V_41 * V_59 , T_4 * V_60 ,
T_5 V_4 )
{
int V_61 ;
if( ! ( * V_60 & 0xffff ) ) {
V_61 = ( int ) V_4 - V_62 ;
}
else {
V_61 = ( int ) ( short ) ( ( int ) V_4 + V_63 +
( int ) ( short ) ( * V_60 & 0xffff ) - V_62 ) ;
}
if( ( V_61 > 32768 ) || ( V_61 < - 32768 ) ) {
F_17 ( V_64 L_4
L_5 ,
V_61 ) ;
return - V_65 ;
}
* V_60 = ( * V_60 & 0xffff0000 ) | ( V_61 & 0xffff ) ;
return 0 ;
}
static int F_29 ( struct V_41 * V_59 , T_4 * V_60 ,
T_5 V_4 )
{
int V_61 ;
V_61 = ( ( ( unsigned int ) V_4 - ( unsigned int ) V_60 ) ) ;
V_61 >>= 2 ;
V_61 -= 1 ;
if( ( V_61 > 32768 ) || ( V_61 < - 32768 ) ) {
F_17 ( V_64 L_6
L_7 , V_61 ) ;
return - V_65 ;
}
* V_60 = ( * V_60 & 0xffff0000 ) | ( V_61 & 0xffff ) ;
return 0 ;
}
static int F_30 ( struct V_41 * V_59 , T_4 * V_60 ,
T_5 V_4 )
{
* V_60 += V_4 ;
return 0 ;
}
static int F_31 ( struct V_41 * V_59 , T_4 * V_60 ,
T_5 V_4 )
{
if ( V_4 % 4 ) {
F_17 ( V_64 L_8
L_9 ) ;
return - V_65 ;
}
* V_60 = ( * V_60 & ~ 0x03ffffff ) |
( ( * V_60 + ( V_4 >> 2 ) ) & 0x03ffffff ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_59 , T_4 * V_60 ,
T_5 V_4 )
{
struct V_66 * V_67 ;
V_67 = F_33 ( sizeof *V_67 , V_12 ) ;
if ( ! V_67 )
return - V_68 ;
V_67 -> V_33 = V_60 ;
V_67 -> V_69 = V_4 ;
V_67 -> V_70 = V_71 ;
V_71 = V_67 ;
return 0 ;
}
static int F_34 ( struct V_41 * V_59 , T_4 * V_60 ,
T_5 V_4 )
{
unsigned long V_72 = * V_60 ;
T_5 V_19 , V_73 ;
struct V_66 * V_74 , * V_70 ;
V_73 = ( ( V_72 & 0xffff ) ^ 0x8000 ) - 0x8000 ;
if ( V_71 != NULL ) {
V_74 = V_71 ;
while ( V_74 != NULL ) {
unsigned long V_75 ;
if ( V_4 != V_74 -> V_69 ) {
F_17 ( V_64 L_6
L_10
L_11 ) ;
goto V_76;
}
V_75 = * V_74 -> V_33 ;
V_19 = ( ( V_75 & 0xffff ) << 16 ) + V_73 ;
V_19 += V_4 ;
V_19 = ( ( V_19 >> 16 ) + ( ( V_19 & 0x8000 ) != 0 ) ) & 0xffff ;
V_75 = ( V_75 & ~ 0xffff ) | V_19 ;
* V_74 -> V_33 = V_75 ;
V_70 = V_74 -> V_70 ;
F_14 ( V_74 ) ;
V_74 = V_70 ;
}
V_71 = NULL ;
}
V_19 = V_4 + V_73 ;
V_72 = ( V_72 & ~ 0xffff ) | ( V_19 & 0xffff ) ;
* V_60 = V_72 ;
return 0 ;
V_76:
while ( V_74 != NULL ) {
V_70 = V_74 -> V_70 ;
F_14 ( V_74 ) ;
V_74 = V_70 ;
}
V_71 = NULL ;
return - V_65 ;
}
static int F_35 ( T_6 * V_44 ,
const char * V_77 ,
unsigned int V_78 ,
unsigned int V_79 ,
struct V_41 * V_59 )
{
T_7 * V_61 = ( void * ) V_44 [ V_79 ] . V_80 ;
T_8 * V_81 ;
T_4 * V_60 ;
unsigned int V_52 ;
T_5 V_4 ;
int V_3 ;
for ( V_52 = 0 ; V_52 < V_44 [ V_79 ] . V_40 / sizeof( * V_61 ) ; V_52 ++ ) {
T_9 V_82 = V_61 [ V_52 ] . V_82 ;
V_60 = ( void * ) V_44 [ V_44 [ V_79 ] . V_83 ] . V_80
+ V_61 [ V_52 ] . V_84 ;
V_81 = ( T_8 * ) V_44 [ V_78 ] . V_80
+ F_36 ( V_82 ) ;
if ( ! V_81 -> V_85 ) {
F_17 ( V_64 L_12 ,
V_59 -> V_86 , V_77 + V_81 -> V_87 ) ;
}
V_4 = V_81 -> V_85 ;
V_3 = V_88 [ F_37 ( V_82 ) ] ( V_59 , V_60 , V_4 ) ;
if( V_3 ) {
char * V_89 = V_90 [ F_37 ( V_82 ) ] ;
F_17 ( V_91 L_13
L_14 ,
V_61 [ V_52 ] . V_84 , V_89 ? V_89 : L_15 ,
V_77 + V_81 -> V_87 ) ;
return V_3 ;
}
}
return 0 ;
}
static inline void F_38 ( unsigned int V_92 , unsigned int V_61 )
{
V_62 = V_92 + V_61 ;
V_63 = V_62 - ( V_92 & 0xffff0000 ) ;
}
static void F_39 ( T_2 * V_44 ,
unsigned int V_78 ,
const char * V_77 ,
const char * V_45 ,
unsigned int V_93 , struct V_41 * V_42 )
{
T_10 * V_81 = ( void * ) V_44 [ V_78 ] . V_80 ;
unsigned long V_92 , V_94 = 0 ;
unsigned int V_52 , V_67 = V_44 [ V_78 ] . V_40 / sizeof( T_10 ) ;
int V_36 ;
for ( V_52 = 0 ; V_52 < V_93 ; V_52 ++ ) {
if ( strncmp ( V_45 + V_44 [ V_52 ] . V_95 , L_16 , 4 ) == 0 ) {
V_94 = V_44 [ V_52 ] . V_80 ;
break;
}
}
for ( V_52 = 1 ; V_52 < V_67 ; V_52 ++ ) {
switch ( V_81 [ V_52 ] . V_96 ) {
case V_97 :
V_36 = V_81 [ V_52 ] . V_85 ;
V_81 [ V_52 ] . V_85 = V_94 ;
V_94 += V_36 ;
break;
case V_98 :
break;
case V_99 :
break;
case V_100 :
F_17 ( V_64 L_17
L_18 , V_77 + V_81 [ V_52 ] . V_87 ,
V_81 [ V_52 ] . V_96 ) ;
break;
default:
V_92 = V_44 [ V_81 [ V_52 ] . V_96 ] . V_80 ;
if ( strncmp ( V_77 + V_81 [ V_52 ] . V_87 , L_19 , 3 ) == 0 ) {
F_38 ( V_92 , V_81 [ V_52 ] . V_85 ) ;
}
V_81 [ V_52 ] . V_85 += V_92 ;
break;
}
}
}
static void F_40 ( T_2 * V_44 , unsigned int V_78 ,
const char * V_77 , struct V_41 * V_42 )
{
T_10 * V_81 = ( void * ) V_44 [ V_78 ] . V_80 ;
unsigned int V_52 , V_67 = V_44 [ V_78 ] . V_40 / sizeof( T_10 ) ;
F_17 ( V_64 L_20 , V_67 ) ;
for ( V_52 = 1 ; V_52 < V_67 ; V_52 ++ ) {
F_17 ( V_64 L_21 , V_52 ,
V_77 + V_81 [ V_52 ] . V_87 , V_81 [ V_52 ] . V_85 ) ;
}
}
static int F_41 ( struct V_1 * V_4 )
{
unsigned long V_101 , V_19 , V_102 ;
struct V_103 * V_67 ;
unsigned int V_104 ;
struct V_8 * V_10 ;
F_42 ( V_101 ) ;
V_19 = F_43 () ;
if ( ! ( V_19 & V_105 ) ) {
F_17 ( V_91
L_22 ) ;
F_44 ( V_101 ) ;
return - 1 ;
}
V_102 = F_45 () ;
V_104 = F_46 () ;
if ( ! F_47 ( & V_4 -> V_8 ) ) {
if ( ( V_10 = F_48 ( V_4 -> V_8 . V_70 , struct V_8 , V_8 ) ) == NULL ) {
F_49 ( V_104 ) ;
F_50 ( V_102 ) ;
F_44 ( V_101 ) ;
F_17 ( V_91
L_23 ,
V_10 -> V_9 ) ;
return - V_65 ;
}
} else {
F_49 ( V_104 ) ;
F_50 ( V_102 ) ;
F_44 ( V_101 ) ;
F_17 ( V_91
L_24 ,
V_4 -> V_2 ) ;
return - V_65 ;
}
F_51 ( V_24 ) ;
F_52 ( V_10 -> V_9 ) ;
if ( ( F_53 () & V_106 ) || ! ( F_54 () & V_107 ) ) {
F_49 ( V_104 ) ;
F_50 ( V_102 ) ;
F_44 ( V_101 ) ;
F_17 ( V_91 L_25 ,
V_10 -> V_9 ) ;
return - V_65 ;
}
F_55 ( ( unsigned long ) V_4 -> V_108 ) ;
F_56 ( ( unsigned long ) 0 ) ;
V_19 = F_53 () ;
V_19 = ( V_19 & ~ ( V_109 | V_110 ) ) | V_106 ;
F_57 ( V_19 ) ;
F_58 ( F_54 () & ~ V_107 ) ;
F_59 ( 6 , V_4 -> V_111 ) ;
F_59 ( 7 , V_112 ) ;
F_60 ( ( F_61 () & ~ V_113 ) | 1 ) ;
F_62 ( F_63 () & ~ ( V_114 ) ) ;
F_64 () ;
F_62 ( ( F_63 () & ~ ( V_115 ) )
| ( V_10 -> V_9 << V_116 ) ) ;
F_64 () ;
F_62 ( F_63 () | V_114 ) ;
F_65 ( 0 ) ;
F_66 ( 0 ) ;
F_67 ( V_24 ) ;
#ifdef F_68
F_49 ( V_104 ) ;
#else
F_49 ( V_117 ) ;
#endif
F_50 ( V_102 ) ;
F_44 ( V_101 ) ;
F_3 (n, &v->notify, list)
V_67 -> V_118 ( V_2 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_4 , T_2 * V_44 ,
unsigned int V_78 , const char * V_77 ,
struct V_41 * V_42 )
{
T_10 * V_81 = ( void * ) V_44 [ V_78 ] . V_80 ;
unsigned int V_52 , V_67 = V_44 [ V_78 ] . V_40 / sizeof( T_10 ) ;
for ( V_52 = 1 ; V_52 < V_67 ; V_52 ++ ) {
if ( strcmp ( V_77 + V_81 [ V_52 ] . V_87 , L_26 ) == 0 ) {
V_4 -> V_108 = V_81 [ V_52 ] . V_85 ;
}
if ( strcmp ( V_77 + V_81 [ V_52 ] . V_87 , L_27 ) == 0 ) {
V_4 -> V_119 = ( void * ) V_81 [ V_52 ] . V_85 ;
}
}
if ( ( V_4 -> V_108 == 0 ) || ( V_4 -> V_119 == NULL ) )
return - 1 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_4 )
{
T_3 * V_43 ;
T_2 * V_44 ;
long V_120 = 0 ;
char * V_45 , * V_77 = NULL ;
unsigned int V_32 , V_52 , V_78 = 0 , V_121 = 0 , V_122 = 0 ;
struct V_41 V_42 ;
memset ( & V_42 , 0 , sizeof( struct V_41 ) ) ;
strcpy ( V_42 . V_86 , L_28 ) ;
V_43 = ( T_3 * ) V_4 -> V_123 ;
V_32 = V_4 -> V_124 ;
if ( memcmp ( V_43 -> V_125 , V_126 , V_127 ) != 0
|| ( V_43 -> V_128 != V_129 && V_43 -> V_128 != V_130 )
|| ! F_71 ( V_43 )
|| V_43 -> V_131 != sizeof( * V_44 ) ) {
F_17 ( V_91
L_29 ) ;
return - V_65 ;
}
if ( V_43 -> V_128 == V_129 )
V_122 = 1 ;
if ( V_32 < V_43 -> V_132 + V_43 -> V_53 * sizeof( T_2 ) ) {
F_17 ( V_133 L_30 ,
V_32 ) ;
return - V_65 ;
}
V_44 = ( void * ) V_43 + V_43 -> V_132 ;
V_45 = ( void * ) V_43 + V_44 [ V_43 -> V_134 ] . V_135 ;
V_44 [ 0 ] . V_80 = 0 ;
V_78 = V_121 = 0 ;
if ( V_122 ) {
for ( V_52 = 1 ; V_52 < V_43 -> V_53 ; V_52 ++ ) {
if ( V_44 [ V_52 ] . V_136 != V_137
&& V_32 < V_44 [ V_52 ] . V_135 + V_44 [ V_52 ] . V_40 ) {
F_17 ( V_133 L_31 ,
V_32 ) ;
return - V_65 ;
}
V_44 [ V_52 ] . V_80 = ( V_138 ) V_43 + V_44 [ V_52 ] . V_135 ;
if ( V_44 [ V_52 ] . V_136 == V_139 ) {
V_78 = V_52 ;
V_121 = V_44 [ V_52 ] . V_140 ;
V_77 = ( char * ) V_43 + V_44 [ V_121 ] . V_135 ;
}
}
F_25 ( & V_42 , V_43 , V_44 , V_45 ) ;
}
V_4 -> V_18 = F_20 ( V_42 . V_57 ) ;
if ( ! V_4 -> V_18 )
return - V_68 ;
F_72 ( L_32 , V_4 -> V_18 ) ;
if ( V_122 ) {
for ( V_52 = 0 ; V_52 < V_43 -> V_53 ; V_52 ++ ) {
void * V_141 ;
if ( ! ( V_44 [ V_52 ] . V_56 & V_48 ) )
continue;
V_141 = V_4 -> V_18 + V_44 [ V_52 ] . V_54 ;
if ( V_44 [ V_52 ] . V_136 != V_137 )
memcpy ( V_141 , ( void * ) V_44 [ V_52 ] . V_80 ,
V_44 [ V_52 ] . V_40 ) ;
V_44 [ V_52 ] . V_80 = ( unsigned long ) V_141 ;
F_17 ( V_64 L_33 ,
V_45 + V_44 [ V_52 ] . V_95 , V_44 [ V_52 ] . V_80 ) ;
}
F_39 ( V_44 , V_78 , V_77 , V_45 ,
V_43 -> V_53 , & V_42 ) ;
for ( V_52 = 1 ; V_52 < V_43 -> V_53 ; V_52 ++ ) {
const char * V_77 = ( char * ) V_44 [ V_121 ] . V_80 ;
unsigned int V_142 = V_44 [ V_52 ] . V_83 ;
if ( V_142 >= V_43 -> V_53 )
continue;
if ( ! ( V_44 [ V_142 ] . V_56 & V_48 ) )
continue;
if ( V_44 [ V_52 ] . V_136 == V_143 )
V_120 = F_35 ( V_44 , V_77 , V_78 , V_52 ,
& V_42 ) ;
else if ( V_44 [ V_52 ] . V_136 == V_144 )
V_120 = F_73 ( V_44 , V_77 , V_78 , V_52 ,
& V_42 ) ;
if ( V_120 < 0 )
return V_120 ;
}
} else {
struct V_145 * V_146 = (struct V_145 * ) ( ( char * ) V_43 + V_43 -> V_147 ) ;
for ( V_52 = 0 ; V_52 < V_43 -> V_148 ; V_52 ++ ) {
if ( V_146 -> V_149 == V_150 ) {
memcpy ( ( void * ) V_146 -> V_151 ,
( char * ) V_43 + V_146 -> V_152 ,
V_146 -> V_153 ) ;
memset ( ( void * ) V_146 -> V_151 + V_146 -> V_153 ,
0 , V_146 -> V_154 - V_146 -> V_153 ) ;
}
V_146 ++ ;
}
for ( V_52 = 0 ; V_52 < V_43 -> V_53 ; V_52 ++ ) {
if ( V_44 [ V_52 ] . V_136 == V_139 ) {
V_78 = V_52 ;
V_121 = V_44 [ V_52 ] . V_140 ;
V_77 = ( char * ) V_43 + V_44 [ V_121 ] . V_135 ;
V_44 [ V_52 ] . V_80 = ( V_138 ) V_43 + V_44 [ V_52 ] . V_135 ;
}
}
}
F_74 ( ( unsigned long ) V_4 -> V_18 ,
( unsigned long ) V_4 -> V_18 + V_4 -> V_32 ) ;
if ( ( F_69 ( V_4 , V_44 , V_78 , V_77 , & V_42 ) ) < 0 ) {
if ( V_4 -> V_108 == 0 ) {
F_17 ( V_91 L_34
L_35 ) ;
return - V_65 ;
}
if ( V_4 -> V_119 == NULL )
F_17 ( V_91 L_6
L_36
L_37 ) ;
}
F_17 ( L_38 ) ;
return 0 ;
}
static void F_75 ( struct V_8 * V_8 )
{
unsigned long V_101 ;
unsigned int V_155 , V_156 ;
int V_157 ;
F_42 ( V_101 ) ;
V_155 = F_45 () ;
V_156 = F_46 () ;
F_51 ( V_24 ) ;
F_52 ( V_8 -> V_9 ) ;
V_157 = F_53 () ;
V_157 &= ~ ( V_106 | V_109 ) ;
V_157 |= V_110 ;
F_57 ( V_157 ) ;
F_58 ( V_107 ) ;
F_76 () ;
F_67 ( V_24 ) ;
F_49 ( V_156 ) ;
F_50 ( V_155 ) ;
F_44 ( V_101 ) ;
}
static int F_77 ( char * V_158 , int V_36 )
{
T_11 V_159 ;
int V_38 ;
V_159 = F_78 () ;
F_79 ( V_160 ) ;
V_38 = F_80 ( V_158 , V_36 ) ;
F_79 ( V_159 ) ;
return V_38 ;
}
static int F_81 ( struct V_161 * V_161 , struct V_162 * V_163 )
{
enum V_164 V_165 ;
struct V_103 * V_166 ;
struct V_1 * V_4 ;
int V_38 ;
if ( V_2 != F_82 ( V_161 ) ) {
F_83 ( L_39 ) ;
return - V_167 ;
}
if ( ( V_4 = F_1 ( V_168 ) ) == NULL ) {
F_83 ( L_40 ) ;
return - V_167 ;
}
V_165 = F_84 ( & V_4 -> V_165 , V_169 ) ;
if ( V_165 != V_170 ) {
F_17 ( V_64 L_41 ) ;
F_3 (not, &v->notify, list) {
V_166 -> V_171 ( V_168 ) ;
}
F_13 ( V_4 -> V_18 ) ;
F_75 ( F_5 ( V_168 ) ) ;
}
V_4 -> V_123 = F_85 ( V_172 ) ;
if ( ! V_4 -> V_123 ) {
F_83 ( L_42 ) ;
return - V_68 ;
}
V_4 -> V_124 = V_172 ;
V_4 -> V_18 = NULL ;
V_4 -> V_32 = 0 ;
V_4 -> V_173 = V_163 -> V_174 -> V_175 ;
V_4 -> V_176 = V_163 -> V_174 -> V_177 ;
#ifdef F_86
if ( ! V_178 ) {
F_87 ( & V_179 ) ;
V_178 ++ ;
}
#endif
V_4 -> V_180 [ 0 ] = 0 ;
V_38 = F_77 ( V_4 -> V_180 , V_181 ) ;
if ( V_38 < 0 )
F_17 ( V_91 L_43 , V_38 ) ;
V_4 -> V_119 = NULL ;
V_4 -> V_108 = 0 ;
return 0 ;
}
static int F_88 ( struct V_161 * V_161 , struct V_162 * V_163 )
{
struct V_1 * V_4 ;
T_3 * V_43 ;
int V_38 = 0 ;
V_4 = F_1 ( V_168 ) ;
if ( V_4 == NULL )
return - V_167 ;
V_43 = ( T_3 * ) V_4 -> V_123 ;
if ( memcmp ( V_43 -> V_125 , V_126 , V_127 ) == 0 ) {
if ( F_70 ( V_4 ) >= 0 ) {
F_41 ( V_4 ) ;
} else {
F_17 ( V_91 L_44 ) ;
V_38 = - V_65 ;
}
} else {
F_17 ( V_91 L_45 ) ;
V_38 = - V_65 ;
}
if ( V_38 < 0 )
V_4 -> V_119 = NULL ;
F_89 ( V_4 -> V_123 ) ;
V_4 -> V_124 = 0 ;
return V_38 ;
}
static T_12 F_90 ( struct V_162 * V_162 , const char T_13 * V_182 ,
V_138 V_183 , T_14 * V_184 )
{
V_138 V_38 = V_183 ;
struct V_1 * V_4 ;
if ( F_82 ( V_162 -> V_185 . V_186 -> V_187 ) != V_2 )
return - V_167 ;
V_4 = F_1 ( V_168 ) ;
if ( V_4 == NULL )
return - V_167 ;
if ( ( V_183 + V_4 -> V_32 ) > V_4 -> V_124 ) {
F_17 ( V_91
L_46 ) ;
return - V_68 ;
}
V_183 -= F_91 ( V_4 -> V_123 + V_4 -> V_32 , V_182 , V_183 ) ;
if ( ! V_183 )
return - V_188 ;
V_4 -> V_32 += V_183 ;
return V_38 ;
}
T_15 F_92 ( void )
{
int V_52 ;
struct V_1 * V_4 ;
for ( V_52 = 1 ; V_52 < V_189 ; V_52 ++ ) {
if ( ( V_4 = F_1 ( V_52 ) ) != NULL ) {
V_4 -> V_165 = V_169 ;
return V_4 ;
}
}
return NULL ;
}
int F_93 ( T_15 V_1 , unsigned long V_118 )
{
struct V_1 * V_4 = V_1 ;
V_4 -> V_108 = V_118 ;
return F_41 ( V_4 ) ;
}
int F_94 ( T_15 V_1 )
{
struct V_1 * V_4 = V_1 ;
struct V_8 * V_10 ;
unsigned int V_190 ;
V_190 = F_46 () ;
if ( ( V_10 = F_48 ( V_4 -> V_8 . V_70 , struct V_8 , V_8 ) ) != NULL ) {
F_52 ( V_10 -> V_9 ) ;
F_62 ( F_63 () & ~ V_114 ) ;
}
F_49 ( V_190 ) ;
return 0 ;
}
int F_95 ( T_15 V_1 )
{
struct V_1 * V_4 = V_1 ;
struct V_8 * V_10 ;
unsigned int V_190 ;
if ( ( V_10 = F_48 ( V_4 -> V_8 . V_70 , struct V_8 , V_8 ) ) == NULL ) {
return - V_65 ;
}
V_190 = F_46 () ;
F_51 ( V_24 ) ;
F_52 ( V_10 -> V_9 ) ;
F_62 ( F_63 () & ~ V_114 ) ;
F_58 ( V_107 ) ;
F_76 () ;
F_57 ( F_53 () & ~ V_106 ) ;
V_4 -> V_165 = V_170 ;
F_67 ( V_24 ) ;
F_49 ( V_190 ) ;
return 0 ;
}
void * F_96 ( int V_9 )
{
struct V_1 * V_4 ;
if ( ( V_4 = F_1 ( V_9 ) ) == NULL )
return NULL ;
return V_4 -> V_119 ;
}
int F_97 ( int V_9 )
{
struct V_1 * V_4 ;
if ( ( V_4 = F_1 ( V_9 ) ) == NULL )
return - 1 ;
return V_4 -> V_173 ;
}
int F_98 ( int V_9 )
{
struct V_1 * V_4 ;
if ( ( V_4 = F_1 ( V_9 ) ) == NULL )
return - 1 ;
return V_4 -> V_176 ;
}
int F_99 ( int V_9 , struct V_103 * V_15 )
{
struct V_1 * V_4 ;
if ( ( V_4 = F_1 ( V_9 ) ) == NULL )
return - 1 ;
F_100 ( & V_15 -> V_13 , & V_4 -> V_15 ) ;
return 0 ;
}
char * F_101 ( int V_9 )
{
struct V_1 * V_4 ;
if ( ( V_4 = F_1 ( V_9 ) ) == NULL )
return NULL ;
return V_4 -> V_180 ;
}
static void F_102 ( int V_191 )
{
F_75 ( F_5 ( V_191 ) ) ;
}
static T_12 F_103 ( struct V_192 * V_193 , struct V_194 * V_195 ,
const char * V_196 , V_138 V_32 )
{
struct V_1 * V_1 = F_1 ( V_168 ) ;
struct V_103 * V_166 ;
F_3 (not, &vpe->notify, list) {
V_166 -> V_171 ( V_168 ) ;
}
F_13 ( V_1 -> V_18 ) ;
F_75 ( F_5 ( V_168 ) ) ;
F_94 ( V_1 ) ;
F_95 ( V_1 ) ;
return V_32 ;
}
static T_12 F_104 ( struct V_192 * V_197 , struct V_194 * V_195 ,
char * V_196 )
{
struct V_1 * V_1 = F_1 ( V_168 ) ;
return sprintf ( V_196 , L_47 , V_1 -> V_111 ) ;
}
static T_12 F_105 ( struct V_192 * V_193 , struct V_194 * V_195 ,
const char * V_196 , V_138 V_32 )
{
struct V_1 * V_1 = F_1 ( V_168 ) ;
unsigned long V_198 ;
char * V_199 ;
V_198 = F_106 ( V_196 , & V_199 , 0 ) ;
if ( V_199 == V_196 )
goto V_200;
if ( V_198 == 0 || V_198 > ( V_201 - V_168 ) )
goto V_200;
V_1 -> V_111 = V_198 ;
return V_32 ;
V_200:
return - V_202 ;
}
static void F_107 ( struct V_192 * V_197 )
{
F_14 ( V_197 ) ;
}
static int T_16 F_108 ( void )
{
unsigned int V_155 , V_156 ;
unsigned long V_101 , V_19 ;
struct V_1 * V_4 = NULL ;
struct V_8 * V_10 ;
int V_8 , V_120 ;
if ( ! V_5 ) {
F_17 ( L_48 ) ;
return - V_167 ;
}
if ( V_203 == 0 ) {
F_17 ( V_91 L_49
L_50
L_51 ) ;
return - V_167 ;
}
if ( V_168 == 0 ) {
F_17 ( V_91 L_52
L_53
L_51 ) ;
return - V_167 ;
}
V_204 = F_109 ( 0 , V_205 , & V_206 ) ;
if ( V_204 < 0 ) {
F_17 ( L_54 ) ;
return V_204 ;
}
V_120 = F_110 ( & V_207 ) ;
if ( V_120 ) {
F_17 ( V_133 L_55 ) ;
goto V_208;
}
F_111 ( & V_209 ) ;
V_209 . V_210 = & V_207 ,
V_209 . V_211 = NULL ,
F_112 ( & V_209 , L_56 ) ;
V_209 . V_212 = F_113 ( V_204 , V_2 ) ;
V_120 = F_114 ( & V_209 ) ;
if ( V_120 ) {
F_17 ( V_133 L_57 ) ;
goto V_213;
}
F_42 ( V_101 ) ;
V_155 = F_45 () ;
V_156 = F_46 () ;
F_51 ( V_24 ) ;
V_19 = F_19 () ;
V_201 = ( V_19 & V_29 ) + 1 ;
V_214 = ( ( V_19 & V_27 ) >> V_28 ) + 1 ;
for ( V_8 = V_168 ; V_8 < V_201 ; V_8 ++ ) {
F_67 ( V_24 ) ;
F_49 ( V_156 ) ;
F_50 ( V_155 ) ;
F_44 ( V_101 ) ;
V_10 = F_10 ( V_8 ) ;
if ( ! V_10 ) {
V_120 = - V_68 ;
goto V_16;
}
F_42 ( V_101 ) ;
V_155 = F_45 () ;
V_156 = F_46 () ;
F_51 ( V_24 ) ;
if ( V_8 < V_201 ) {
F_52 ( V_8 ) ;
if ( ( V_4 = F_6 ( V_8 ) ) == NULL ) {
F_17 ( V_91 L_58 ) ;
goto V_215;
}
V_4 -> V_111 = V_201 - V_168 ;
F_100 ( & V_10 -> V_8 , & V_4 -> V_8 ) ;
if ( V_8 >= V_168 ) {
unsigned long V_157 = F_63 () ;
V_157 &= ~ V_114 ;
V_157 |= V_105 ;
F_62 ( V_157 ) ;
}
F_115 ( F_116 () & ~ V_216 ) ;
if ( V_8 >= V_203 ) {
F_117 ( F_118 () ) ;
}
}
V_10 -> V_217 = V_4 ;
if ( V_8 >= V_168 ) {
unsigned long V_157 ;
F_52 ( V_8 ) ;
if ( ( ( V_157 = F_61 () ) & V_113 ) ) {
F_60 ( V_157 & ~ V_113 ) ;
V_10 -> V_217 = F_1 ( 0 ) ;
}
F_58 ( V_107 ) ;
F_76 () ;
V_157 = F_53 () ;
V_157 &= ~ ( V_106 | V_109 ) ;
V_157 |= V_110 ;
F_57 ( V_157 ) ;
}
}
V_215:
F_67 ( V_24 ) ;
F_49 ( V_156 ) ;
F_50 ( V_155 ) ;
F_44 ( V_101 ) ;
#ifdef F_86
V_179 . F_102 = F_102 ;
#endif
return 0 ;
V_213:
F_119 ( & V_207 ) ;
V_208:
F_120 ( V_204 , V_205 ) ;
V_16:
return V_120 ;
}
static void T_17 F_121 ( void )
{
struct V_1 * V_4 , * V_67 ;
F_122 ( & V_209 ) ;
F_120 ( V_204 , V_205 ) ;
F_123 (v, n, &vpecontrol.vpe_list, list) {
if ( V_4 -> V_165 != V_170 )
F_11 ( V_4 ) ;
}
}
