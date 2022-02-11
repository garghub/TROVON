struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 , * V_4 ;
if ( ! V_5 )
return NULL ;
V_3 = NULL ;
F_2 ( & V_6 . V_7 ) ;
F_3 (v, &vpecontrol.vpe_list, list) {
if ( V_4 -> V_2 == V_8 ) {
V_3 = V_4 ;
break;
}
}
F_4 ( & V_6 . V_7 ) ;
return V_3 ;
}
struct V_9 * F_5 ( int V_10 )
{
struct V_9 * V_3 , * V_11 ;
V_3 = NULL ;
F_2 ( & V_6 . V_12 ) ;
F_3 (t, &vpecontrol.tc_list, list) {
if ( V_11 -> V_10 == V_10 ) {
V_3 = V_11 ;
break;
}
}
F_4 ( & V_6 . V_12 ) ;
return V_3 ;
}
struct V_1 * F_6 ( int V_2 )
{
struct V_1 * V_4 ;
V_4 = F_7 ( sizeof( struct V_1 ) , V_13 ) ;
if ( V_4 == NULL )
goto V_14;
F_8 ( & V_4 -> V_9 ) ;
F_2 ( & V_6 . V_7 ) ;
F_9 ( & V_4 -> V_15 , & V_6 . V_16 ) ;
F_4 ( & V_6 . V_7 ) ;
F_8 ( & V_4 -> V_17 ) ;
V_4 -> V_2 = V_8 ;
V_14:
return V_4 ;
}
struct V_9 * F_10 ( int V_10 )
{
struct V_9 * V_9 ;
V_9 = F_7 ( sizeof( struct V_9 ) , V_13 ) ;
if ( V_9 == NULL )
goto V_14;
F_8 ( & V_9 -> V_9 ) ;
V_9 -> V_10 = V_10 ;
F_2 ( & V_6 . V_12 ) ;
F_9 ( & V_9 -> V_15 , & V_6 . V_18 ) ;
F_4 ( & V_6 . V_12 ) ;
V_14:
return V_9 ;
}
void F_11 ( struct V_1 * V_4 )
{
F_12 ( & V_4 -> V_15 ) ;
if ( V_4 -> V_19 )
F_13 ( V_4 ) ;
F_14 ( V_4 ) ;
}
void * F_15 ( unsigned long V_20 )
{
void * V_21 ;
#ifdef F_16
V_21 = F_17 ( V_22 ) ;
memset ( V_21 , 0 , V_20 ) ;
#else
V_21 = F_7 ( V_20 , V_13 ) ;
#endif
return V_21 ;
}
void F_13 ( void * V_23 )
{
#ifndef F_16
F_14 ( V_23 ) ;
#endif
}
static long F_18 ( unsigned long * V_24 , T_1 * V_25 )
{
long V_26 ;
V_26 = F_19 ( * V_24 , V_25 -> V_27 ? : 1 ) ;
* V_24 = V_26 + V_25 -> V_28 ;
return V_26 ;
}
static void F_20 ( struct V_29 * V_30 , const T_2 * V_31 ,
T_1 * V_32 , const char * V_33 )
{
static unsigned long const V_34 [] [ 2 ] = {
{ V_35 | V_36 , V_37 } ,
{ V_36 , V_38 | V_37 } ,
{ V_38 | V_36 , V_37 } ,
{ V_37 | V_36 , 0 }
} ;
unsigned int V_39 , V_40 ;
for ( V_40 = 0 ; V_40 < V_31 -> V_41 ; V_40 ++ )
V_32 [ V_40 ] . V_42 = ~ 0UL ;
for ( V_39 = 0 ; V_39 < F_21 ( V_34 ) ; ++ V_39 ) {
for ( V_40 = 0 ; V_40 < V_31 -> V_41 ; ++ V_40 ) {
T_1 * V_43 = & V_32 [ V_40 ] ;
if ( ( V_43 -> V_44 & V_34 [ V_39 ] [ 0 ] ) != V_34 [ V_39 ] [ 0 ]
|| ( V_43 -> V_44 & V_34 [ V_39 ] [ 1 ] )
|| V_43 -> V_42 != ~ 0UL )
continue;
V_43 -> V_42 =
F_18 ( ( unsigned long * ) & V_30 -> V_45 , V_43 ) ;
}
if ( V_39 == 0 )
V_30 -> V_46 = V_30 -> V_45 ;
}
}
static int F_22 ( struct V_29 * V_47 , T_3 * V_48 ,
T_4 V_4 )
{
return 0 ;
}
static int F_23 ( struct V_29 * V_47 , T_3 * V_48 ,
T_4 V_4 )
{
int V_49 ;
if ( ! ( * V_48 & 0xffff ) ) {
V_49 = ( int ) V_4 - V_50 ;
} else {
V_49 = ( int ) ( short ) ( ( int ) V_4 + V_51 +
( int ) ( short ) ( * V_48 & 0xffff ) - V_50 ) ;
}
if ( ( V_49 > 32768 ) || ( V_49 < - 32768 ) ) {
F_24 ( L_1 ,
V_49 ) ;
return - V_52 ;
}
* V_48 = ( * V_48 & 0xffff0000 ) | ( V_49 & 0xffff ) ;
return 0 ;
}
static int F_25 ( struct V_29 * V_47 , T_3 * V_48 ,
T_4 V_4 )
{
int V_49 ;
V_49 = ( ( ( unsigned int ) V_4 - ( unsigned int ) V_48 ) ) ;
V_49 >>= 2 ;
V_49 -= 1 ;
if ( ( V_49 > 32768 ) || ( V_49 < - 32768 ) ) {
F_24 ( L_2 ,
V_49 ) ;
return - V_52 ;
}
* V_48 = ( * V_48 & 0xffff0000 ) | ( V_49 & 0xffff ) ;
return 0 ;
}
static int F_26 ( struct V_29 * V_47 , T_3 * V_48 ,
T_4 V_4 )
{
* V_48 += V_4 ;
return 0 ;
}
static int F_27 ( struct V_29 * V_47 , T_3 * V_48 ,
T_4 V_4 )
{
if ( V_4 % 4 ) {
F_24 ( L_3 ) ;
return - V_52 ;
}
* V_48 = ( * V_48 & ~ 0x03ffffff ) |
( ( * V_48 + ( V_4 >> 2 ) ) & 0x03ffffff ) ;
return 0 ;
}
static int F_28 ( struct V_29 * V_47 , T_3 * V_48 ,
T_4 V_4 )
{
struct V_53 * V_54 ;
V_54 = F_29 ( sizeof( * V_54 ) , V_13 ) ;
if ( ! V_54 )
return - V_55 ;
V_54 -> V_21 = V_48 ;
V_54 -> V_56 = V_4 ;
V_54 -> V_57 = V_58 ;
V_58 = V_54 ;
return 0 ;
}
static int F_30 ( struct V_29 * V_47 , T_3 * V_48 ,
T_4 V_4 )
{
unsigned long V_59 = * V_48 ;
T_4 V_60 , V_61 ;
struct V_53 * V_62 , * V_57 ;
V_61 = ( ( V_59 & 0xffff ) ^ 0x8000 ) - 0x8000 ;
if ( V_58 != NULL ) {
V_62 = V_58 ;
while ( V_62 != NULL ) {
unsigned long V_63 ;
if ( V_4 != V_62 -> V_56 ) {
F_24 ( L_4 ) ;
goto V_64;
}
V_63 = * V_62 -> V_21 ;
V_60 = ( ( V_63 & 0xffff ) << 16 ) + V_61 ;
V_60 += V_4 ;
V_60 = ( ( V_60 >> 16 ) + ( ( V_60 & 0x8000 ) != 0 ) ) & 0xffff ;
V_63 = ( V_63 & ~ 0xffff ) | V_60 ;
* V_62 -> V_21 = V_63 ;
V_57 = V_62 -> V_57 ;
F_14 ( V_62 ) ;
V_62 = V_57 ;
}
V_58 = NULL ;
}
V_60 = V_4 + V_61 ;
V_59 = ( V_59 & ~ 0xffff ) | ( V_60 & 0xffff ) ;
* V_48 = V_59 ;
return 0 ;
V_64:
while ( V_62 != NULL ) {
V_57 = V_62 -> V_57 ;
F_14 ( V_62 ) ;
V_62 = V_57 ;
}
V_58 = NULL ;
return - V_52 ;
}
static int F_31 ( T_5 * V_32 ,
const char * V_65 ,
unsigned int V_66 ,
unsigned int V_67 ,
struct V_29 * V_47 )
{
T_6 * V_49 = ( void * ) V_32 [ V_67 ] . V_68 ;
T_7 * V_69 ;
T_3 * V_48 ;
unsigned int V_40 ;
T_4 V_4 ;
int V_3 ;
for ( V_40 = 0 ; V_40 < V_32 [ V_67 ] . V_28 / sizeof( * V_49 ) ; V_40 ++ ) {
T_8 V_70 = V_49 [ V_40 ] . V_70 ;
V_48 = ( void * ) V_32 [ V_32 [ V_67 ] . V_71 ] . V_68
+ V_49 [ V_40 ] . V_72 ;
V_69 = ( T_7 * ) V_32 [ V_66 ] . V_68
+ F_32 ( V_70 ) ;
if ( ! V_69 -> V_73 ) {
F_24 ( L_5 ,
V_47 -> V_74 , V_65 + V_69 -> V_75 ) ;
}
V_4 = V_69 -> V_73 ;
V_3 = V_76 [ F_33 ( V_70 ) ] ( V_47 , V_48 , V_4 ) ;
if ( V_3 ) {
char * V_77 = V_78 [ F_33 ( V_70 ) ] ;
F_34 ( L_6 ,
V_49 [ V_40 ] . V_72 , V_77 ? V_77 : L_7 ,
V_65 + V_69 -> V_75 ) ;
return V_3 ;
}
}
return 0 ;
}
static inline void F_35 ( unsigned int V_79 , unsigned int V_49 )
{
V_50 = V_79 + V_49 ;
V_51 = V_50 - ( V_79 & 0xffff0000 ) ;
}
static void F_36 ( T_1 * V_32 ,
unsigned int V_66 ,
const char * V_65 ,
const char * V_33 ,
unsigned int V_80 , struct V_29 * V_30 )
{
T_9 * V_69 = ( void * ) V_32 [ V_66 ] . V_68 ;
unsigned long V_79 , V_81 = 0 ;
unsigned int V_40 , V_54 = V_32 [ V_66 ] . V_28 / sizeof( T_9 ) ;
int V_24 ;
for ( V_40 = 0 ; V_40 < V_80 ; V_40 ++ ) {
if ( strncmp ( V_33 + V_32 [ V_40 ] . V_82 , L_8 , 4 ) == 0 ) {
V_81 = V_32 [ V_40 ] . V_68 ;
break;
}
}
for ( V_40 = 1 ; V_40 < V_54 ; V_40 ++ ) {
switch ( V_69 [ V_40 ] . V_83 ) {
case V_84 :
V_24 = V_69 [ V_40 ] . V_73 ;
V_69 [ V_40 ] . V_73 = V_81 ;
V_81 += V_24 ;
break;
case V_85 :
break;
case V_86 :
break;
case V_87 :
F_24 ( L_9 ,
V_65 + V_69 [ V_40 ] . V_75 , V_69 [ V_40 ] . V_83 ) ;
break;
default:
V_79 = V_32 [ V_69 [ V_40 ] . V_83 ] . V_68 ;
if ( strncmp ( V_65 + V_69 [ V_40 ] . V_75 , L_10 , 3 ) == 0 )
F_35 ( V_79 , V_69 [ V_40 ] . V_73 ) ;
V_69 [ V_40 ] . V_73 += V_79 ;
break;
}
}
}
static void F_37 ( T_1 * V_32 , unsigned int V_66 ,
const char * V_65 , struct V_29 * V_30 )
{
T_9 * V_69 = ( void * ) V_32 [ V_66 ] . V_68 ;
unsigned int V_40 , V_54 = V_32 [ V_66 ] . V_28 / sizeof( T_9 ) ;
F_24 ( L_11 , V_54 ) ;
for ( V_40 = 1 ; V_40 < V_54 ; V_40 ++ ) {
F_24 ( L_12 , V_40 , V_65 + V_69 [ V_40 ] . V_75 ,
V_69 [ V_40 ] . V_73 ) ;
}
}
static int F_38 ( struct V_1 * V_4 , T_1 * V_32 ,
unsigned int V_66 , const char * V_65 ,
struct V_29 * V_30 )
{
T_9 * V_69 = ( void * ) V_32 [ V_66 ] . V_68 ;
unsigned int V_40 , V_54 = V_32 [ V_66 ] . V_28 / sizeof( T_9 ) ;
for ( V_40 = 1 ; V_40 < V_54 ; V_40 ++ ) {
if ( strcmp ( V_65 + V_69 [ V_40 ] . V_75 , L_13 ) == 0 )
V_4 -> V_88 = V_69 [ V_40 ] . V_73 ;
if ( strcmp ( V_65 + V_69 [ V_40 ] . V_75 , L_14 ) == 0 )
V_4 -> V_89 = ( void * ) V_69 [ V_40 ] . V_73 ;
}
if ( ( V_4 -> V_88 == 0 ) || ( V_4 -> V_89 == NULL ) )
return - 1 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_4 )
{
T_2 * V_31 ;
T_1 * V_32 ;
long V_90 = 0 ;
char * V_33 , * V_65 = NULL ;
unsigned int V_20 , V_40 , V_66 = 0 , V_91 = 0 , V_92 = 0 ;
struct V_29 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_29 ) ) ;
strcpy ( V_30 . V_74 , L_15 ) ;
V_31 = ( T_2 * ) V_4 -> V_93 ;
V_20 = V_4 -> V_94 ;
if ( memcmp ( V_31 -> V_95 , V_96 , V_97 ) != 0
|| ( V_31 -> V_98 != V_99 && V_31 -> V_98 != V_100 )
|| ! F_40 ( V_31 )
|| V_31 -> V_101 != sizeof( * V_32 ) ) {
F_34 ( L_16 ) ;
return - V_52 ;
}
if ( V_31 -> V_98 == V_99 )
V_92 = 1 ;
if ( V_20 < V_31 -> V_102 + V_31 -> V_41 * sizeof( T_1 ) ) {
F_41 ( L_17 , V_20 ) ;
return - V_52 ;
}
V_32 = ( void * ) V_31 + V_31 -> V_102 ;
V_33 = ( void * ) V_31 + V_32 [ V_31 -> V_103 ] . V_104 ;
V_32 [ 0 ] . V_68 = 0 ;
V_66 = V_91 = 0 ;
if ( V_92 ) {
for ( V_40 = 1 ; V_40 < V_31 -> V_41 ; V_40 ++ ) {
if ( ( V_32 [ V_40 ] . V_105 != V_106 ) &&
( V_20 < V_32 [ V_40 ] . V_104 + V_32 [ V_40 ] . V_28 ) ) {
F_41 ( L_18 ,
V_20 ) ;
return - V_52 ;
}
V_32 [ V_40 ] . V_68 = ( V_107 ) V_31 +
V_32 [ V_40 ] . V_104 ;
if ( V_32 [ V_40 ] . V_105 == V_108 ) {
V_66 = V_40 ;
V_91 = V_32 [ V_40 ] . V_109 ;
V_65 = ( char * ) V_31 +
V_32 [ V_91 ] . V_104 ;
}
}
F_20 ( & V_30 , V_31 , V_32 , V_33 ) ;
}
V_4 -> V_19 = F_15 ( V_30 . V_45 ) ;
if ( ! V_4 -> V_19 )
return - V_55 ;
F_42 ( L_19 , V_4 -> V_19 ) ;
if ( V_92 ) {
for ( V_40 = 0 ; V_40 < V_31 -> V_41 ; V_40 ++ ) {
void * V_110 ;
if ( ! ( V_32 [ V_40 ] . V_44 & V_36 ) )
continue;
V_110 = V_4 -> V_19 + V_32 [ V_40 ] . V_42 ;
if ( V_32 [ V_40 ] . V_105 != V_106 )
memcpy ( V_110 , ( void * ) V_32 [ V_40 ] . V_68 ,
V_32 [ V_40 ] . V_28 ) ;
V_32 [ V_40 ] . V_68 = ( unsigned long ) V_110 ;
F_24 ( L_20 ,
V_33 + V_32 [ V_40 ] . V_82 ,
V_32 [ V_40 ] . V_68 ) ;
}
F_36 ( V_32 , V_66 , V_65 , V_33 ,
V_31 -> V_41 , & V_30 ) ;
for ( V_40 = 1 ; V_40 < V_31 -> V_41 ; V_40 ++ ) {
const char * V_65 = ( char * ) V_32 [ V_91 ] . V_68 ;
unsigned int V_111 = V_32 [ V_40 ] . V_71 ;
if ( V_111 >= V_31 -> V_41 )
continue;
if ( ! ( V_32 [ V_111 ] . V_44 & V_36 ) )
continue;
if ( V_32 [ V_40 ] . V_105 == V_112 )
V_90 = F_31 ( V_32 , V_65 ,
V_66 , V_40 , & V_30 ) ;
else if ( V_32 [ V_40 ] . V_105 == V_113 )
V_90 = F_43 ( V_32 , V_65 ,
V_66 , V_40 , & V_30 ) ;
if ( V_90 < 0 )
return V_90 ;
}
} else {
struct V_114 * V_115 = (struct V_114 * )
( ( char * ) V_31 + V_31 -> V_116 ) ;
for ( V_40 = 0 ; V_40 < V_31 -> V_117 ; V_40 ++ ) {
if ( V_115 -> V_118 == V_119 ) {
memcpy ( ( void * ) V_115 -> V_120 ,
( char * ) V_31 + V_115 -> V_121 ,
V_115 -> V_122 ) ;
memset ( ( void * ) V_115 -> V_120 + V_115 -> V_122 ,
0 , V_115 -> V_123 - V_115 -> V_122 ) ;
}
V_115 ++ ;
}
for ( V_40 = 0 ; V_40 < V_31 -> V_41 ; V_40 ++ ) {
if ( V_32 [ V_40 ] . V_105 == V_108 ) {
V_66 = V_40 ;
V_91 = V_32 [ V_40 ] . V_109 ;
V_65 = ( char * ) V_31 +
V_32 [ V_91 ] . V_104 ;
V_32 [ V_40 ] . V_68 = ( V_107 ) V_31 +
V_32 [ V_40 ] . V_104 ;
}
}
}
F_44 ( ( unsigned long ) V_4 -> V_19 ,
( unsigned long ) V_4 -> V_19 + V_4 -> V_20 ) ;
if ( ( F_38 ( V_4 , V_32 , V_66 , V_65 , & V_30 ) ) < 0 ) {
if ( V_4 -> V_88 == 0 ) {
F_34 ( L_21 ) ;
return - V_52 ;
}
if ( V_4 -> V_89 == NULL )
F_34 ( L_22
L_23 ) ;
}
F_42 ( L_24 ) ;
return 0 ;
}
static int F_45 ( char * V_124 , int V_24 )
{
T_10 V_125 ;
int V_26 ;
V_125 = F_46 () ;
F_47 ( V_126 ) ;
V_26 = F_48 ( V_124 , V_24 ) ;
F_47 ( V_125 ) ;
return V_26 ;
}
static int F_49 ( struct V_127 * V_127 , struct V_128 * V_129 )
{
enum V_130 V_131 ;
struct V_132 * V_133 ;
struct V_1 * V_4 ;
int V_26 ;
if ( V_8 != F_50 ( V_127 ) ) {
F_34 ( L_25 ) ;
return - V_134 ;
}
V_4 = F_1 ( F_51 () ) ;
if ( V_4 == NULL ) {
F_34 ( L_26 ) ;
return - V_134 ;
}
V_131 = F_52 ( & V_4 -> V_131 , V_135 ) ;
if ( V_131 != V_136 ) {
F_24 ( L_27 ) ;
F_3 (notifier, &v->notify, list)
V_133 -> V_137 ( F_51 () ) ;
F_13 ( V_4 -> V_19 ) ;
F_53 ( F_5 ( F_51 () ) ) ;
}
V_4 -> V_93 = F_54 ( V_138 ) ;
if ( ! V_4 -> V_93 ) {
F_34 ( L_28 ) ;
return - V_55 ;
}
V_4 -> V_94 = V_138 ;
V_4 -> V_19 = NULL ;
V_4 -> V_20 = 0 ;
V_4 -> V_139 [ 0 ] = 0 ;
V_26 = F_45 ( V_4 -> V_139 , V_140 ) ;
if ( V_26 < 0 )
F_34 ( L_29 , V_26 ) ;
V_4 -> V_89 = NULL ;
V_4 -> V_88 = 0 ;
return 0 ;
}
static int F_55 ( struct V_127 * V_127 , struct V_128 * V_129 )
{
#if F_56 ( V_141 ) || F_56 ( V_142 )
struct V_1 * V_4 ;
T_2 * V_31 ;
int V_26 = 0 ;
V_4 = F_1 ( F_51 () ) ;
if ( V_4 == NULL )
return - V_134 ;
V_31 = ( T_2 * ) V_4 -> V_93 ;
if ( memcmp ( V_31 -> V_95 , V_96 , V_97 ) == 0 ) {
if ( F_39 ( V_4 ) >= 0 ) {
F_57 ( V_4 ) ;
} else {
F_34 ( L_30 ) ;
V_26 = - V_52 ;
}
} else {
F_34 ( L_31 ) ;
V_26 = - V_52 ;
}
if ( V_26 < 0 )
V_4 -> V_89 = NULL ;
F_58 ( V_4 -> V_93 ) ;
V_4 -> V_94 = 0 ;
return V_26 ;
#else
F_34 ( L_30 ) ;
return - V_52 ;
#endif
}
static T_11 F_59 ( struct V_128 * V_128 , const char T_12 * V_143 ,
V_107 V_144 , T_13 * V_145 )
{
V_107 V_26 = V_144 ;
struct V_1 * V_4 ;
if ( F_50 ( F_60 ( V_128 ) ) != V_8 )
return - V_134 ;
V_4 = F_1 ( F_51 () ) ;
if ( V_4 == NULL )
return - V_134 ;
if ( ( V_144 + V_4 -> V_20 ) > V_4 -> V_94 ) {
F_34 ( L_32 ) ;
return - V_55 ;
}
V_144 -= F_61 ( V_4 -> V_93 + V_4 -> V_20 , V_143 , V_144 ) ;
if ( ! V_144 )
return - V_146 ;
V_4 -> V_20 += V_144 ;
return V_26 ;
}
void * F_62 ( int V_10 )
{
struct V_1 * V_4 = F_1 ( V_10 ) ;
if ( V_4 == NULL )
return NULL ;
return V_4 -> V_89 ;
}
int F_63 ( int V_10 , struct V_132 * V_17 )
{
struct V_1 * V_4 = F_1 ( V_10 ) ;
if ( V_4 == NULL )
return - 1 ;
F_64 ( & V_17 -> V_15 , & V_4 -> V_17 ) ;
return 0 ;
}
char * F_65 ( int V_10 )
{
struct V_1 * V_4 = F_1 ( V_10 ) ;
if ( V_4 == NULL )
return NULL ;
return V_4 -> V_139 ;
}
