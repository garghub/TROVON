static void T_1 F_1 ( void )
{
int V_1 , V_2 ;
T_2 * V_3 ;
if ( ! V_4 )
return;
for( V_1 = 0 ; V_1 < 8 ; ++ V_1 ) {
for( V_2 = 0 ; V_2 < 8 ; ++ V_2 ) {
V_3 = & V_5 [ V_1 ] [ V_2 ] ;
memset ( & V_3 -> V_6 , 0 , V_7 / 8 ) ;
V_3 -> V_8 = 0 ;
V_3 -> V_9 = V_7 ;
}
}
}
static int F_2 ( struct V_10 * V_11 , int V_12 )
{
F_3 ( V_11 -> V_13 -> V_14 ) ;
if ( V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] & ( 1 << V_11 -> V_13 -> V_2 ) )
return ( 1 ) ;
if ( ! V_12 ||
! V_4 || ! V_11 -> V_13 -> V_18 )
return ( 0 ) ;
if ( V_5 [ V_11 -> V_13 -> V_17 ] [ V_11 -> V_13 -> V_2 ] . V_8 >=
V_5 [ V_11 -> V_13 -> V_17 ] [ V_11 -> V_13 -> V_2 ] . V_9 ) {
F_4 ( L_1 ,
F_5 ( V_11 ) , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
return ( 1 ) ;
}
return ( 0 ) ;
}
static void F_6 ( struct V_10 * V_11 , int V_12 )
{
F_3 ( V_11 -> V_13 -> V_14 ) ;
if ( ! V_12 ||
! V_4 || ! V_11 -> V_13 -> V_18 ) {
V_11 -> V_19 = V_20 ;
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] |= ( 1 << V_11 -> V_13 -> V_2 ) ;
F_4 ( L_2
L_3 , F_5 ( V_11 ) , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
}
else {
T_2 * V_3 = & V_5 [ V_11 -> V_13 -> V_17 ] [ V_11 -> V_13 -> V_2 ] ;
V_11 -> V_19 = F_7 ( & V_3 -> V_6 , V_7 ) ;
F_8 ( V_11 -> V_19 , & V_3 -> V_6 ) ;
V_3 -> V_8 ++ ;
F_4 ( L_4
L_5 ,
F_5 ( V_11 ) , V_11 -> V_19 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ,
V_3 -> V_8 ) ;
}
}
static void F_9 ( struct V_10 * V_11 )
{
F_3 ( V_11 -> V_13 -> V_14 ) ;
if ( V_11 -> V_19 == V_20 ) {
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
F_4 ( L_6 ,
F_5 ( V_11 ) , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
}
else if ( V_11 -> V_19 >= V_7 ) {
F_10 ( V_21 L_7 ,
F_5 ( V_11 ) , V_11 -> V_19 ) ;
}
else {
T_2 * V_3 = & V_5 [ V_11 -> V_13 -> V_17 ] [ V_11 -> V_13 -> V_2 ] ;
F_11 ( V_11 -> V_19 , & V_3 -> V_6 ) ;
V_3 -> V_8 -- ;
F_4 ( L_8 ,
F_5 ( V_11 ) , V_11 -> V_19 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
}
}
static void F_12 ( void )
{
int V_1 , V_2 ;
T_2 * V_3 ;
if ( ! V_4 )
return;
for( V_1 = 0 ; V_1 < 8 ; ++ V_1 ) {
for( V_2 = 0 ; V_2 < 8 ; ++ V_2 ) {
V_3 = & V_5 [ V_1 ] [ V_2 ] ;
memset ( & V_3 -> V_6 , 0 , V_7 / 8 ) ;
V_3 -> V_8 = 0 ;
}
}
}
static T_3 void F_13 ( struct V_10 * V_11 )
{
if ( F_14 ( V_11 ) ) {
V_11 -> V_22 . V_23 = F_15 ( V_11 ) ;
V_11 -> V_22 . V_24 = F_16 ( V_11 ) - 1 ;
V_11 -> V_22 . V_25 = ( char * ) F_17 ( V_11 -> V_22 . V_23 ) ;
V_11 -> V_22 . V_26 = V_11 -> V_22 . V_23 -> V_27 ;
} else {
V_11 -> V_22 . V_23 = NULL ;
V_11 -> V_22 . V_24 = 0 ;
V_11 -> V_22 . V_25 = NULL ;
V_11 -> V_22 . V_26 = 0 ;
}
}
static void F_18 ( struct V_28 * V_29 ) {
unsigned char V_30 , V_31 , V_32 , V_33 , V_34 , V_35 ;
unsigned long V_36 ;
F_19 ( V_36 ) ;
V_31 = F_20 ( V_37 ) ;
V_30 = F_20 ( V_38 ) ;
V_33 = F_20 ( V_39 ) ;
V_34 = F_20 ( V_40 ) ;
V_32 = F_20 ( V_41 ) ;
F_21 ( V_36 ) ;
F_10 ( L_9 , V_30 ) ;
for ( V_35 = 0 ; V_42 [ V_35 ] . V_43 ; ++ V_35 )
if ( V_30 & V_42 [ V_35 ] . V_43 )
F_10 ( L_10 , V_42 [ V_35 ] . V_44 ) ;
F_10 ( L_11 , V_32 ) ;
for ( V_35 = 0 ; V_45 [ V_35 ] . V_43 ; ++ V_35 )
if ( V_32 & V_45 [ V_35 ] . V_43 )
F_10 ( L_10 , V_45 [ V_35 ] . V_44 ) ;
F_10 ( L_12 , V_34 ) ;
for ( V_35 = 0 ; V_46 [ V_35 ] . V_43 ; ++ V_35 )
if ( V_34 & V_46 [ V_35 ] . V_43 )
F_10 ( L_10 , V_46 [ V_35 ] . V_44 ) ;
F_10 ( L_13 , V_33 ) ;
for ( V_35 = 0 ; V_47 [ V_35 ] . V_43 ; ++ V_35 )
if ( V_33 & V_47 [ V_35 ] . V_43 )
F_10 ( L_10 , V_47 [ V_35 ] . V_44 ) ;
F_10 ( L_14 ) ;
}
static void F_22 ( struct V_28 * V_29 )
{
unsigned char V_30 ;
int V_35 ;
V_30 = F_20 ( V_38 ) ;
if ( ! ( V_30 & V_48 ) )
F_10 ( V_49 L_15 , V_50 ) ;
else {
for ( V_35 = 0 ; ( V_51 [ V_35 ] . V_52 != V_53 ) &&
( V_51 [ V_35 ] . V_52 != ( V_30 & V_54 ) ) ; ++ V_35 ) ;
F_10 ( V_49 L_16 , V_50 , V_51 [ V_35 ] . V_44 ) ;
}
}
T_3 void F_18 ( struct V_28 * V_29 ) { }
T_3 void F_22 ( struct V_28 * V_29 ) { }
static T_3 void F_23 ( void )
{
if ( ! V_55 ) {
F_24 ( & V_56 ) ;
}
}
static inline void F_25 ( void )
{
static int V_57 = 0 ;
if ( ! V_57 ) {
F_26 ( L_17 ) ;
V_57 = 1 ;
}
}
static void T_1 F_27 ( struct V_28 * V_29 )
{
F_10 ( L_18
#ifdef F_28
L_19
#endif
#ifdef F_29
L_20
#endif
#ifdef F_30
L_21
#endif
#ifdef F_31
L_22
#endif
) ;
F_10 ( L_23 , V_58 ) ;
}
static void F_32 ( struct V_28 * V_29 )
{
char * V_59 ;
char * V_60 ;
int V_61 ;
F_33 ( V_62 ) ;
F_34 ( V_62 ) ;
V_59 = ( char * ) F_35 ( V_63 ) ;
if ( ! V_59 ) {
F_10 ( L_24 ) ;
return;
}
V_61 = F_36 ( V_29 , V_59 , & V_60 , 0 , V_64 , 0 ) ;
V_59 [ V_61 ] = 0 ;
F_10 ( L_25 , V_59 ) ;
F_37 ( ( unsigned long ) V_59 ) ;
}
static int F_36 ( struct V_28 * V_29 , char * V_23 ,
char * * V_60 , T_4 V_65 , int V_27 , int V_66 )
{
char * V_67 = V_23 ;
struct V_68 * V_15 ;
struct V_10 * V_25 ;
unsigned long V_36 ;
T_4 V_69 = 0 ;
#define F_38 () \
do { \
if (pos - buffer < offset - begin) { \
begin += pos - buffer; \
pos = buffer; \
} \
} while (0)
V_15 = (struct V_68 * ) V_29 -> V_15 ;
if ( V_66 ) {
return ( - V_70 ) ;
}
SPRINTF ( L_26 , V_58 ) ;
F_38 () ;
F_19 ( V_36 ) ;
SPRINTF ( L_27 , V_55 ? L_28 : L_29 ) ;
F_38 () ;
if ( ! V_15 -> V_71 )
SPRINTF ( L_30 , V_50 ) ;
else
V_67 = F_39 ( (struct V_10 * ) V_15 -> V_71 ,
V_67 , V_23 , V_27 ) ;
SPRINTF ( L_31 , V_50 ) ;
F_38 () ;
for ( V_25 = (struct V_10 * ) V_15 -> V_72 ; V_25 ; V_25 = F_40 ( V_25 ) )
{
V_67 = F_39 ( V_25 , V_67 , V_23 , V_27 ) ;
F_38 () ;
}
SPRINTF ( L_32 , V_50 ) ;
F_38 () ;
for ( V_25 = (struct V_10 * ) V_15 -> V_73 ; V_25 ;
V_25 = F_40 ( V_25 ) ) {
V_67 = F_39 ( V_25 , V_67 , V_23 , V_27 ) ;
F_38 () ;
}
F_21 ( V_36 ) ;
* V_60 = V_23 + ( V_65 - V_69 ) ;
if ( V_67 - V_23 < V_65 - V_69 )
return 0 ;
else if ( V_67 - V_23 - ( V_65 - V_69 ) < V_27 )
return V_67 - V_23 - ( V_65 - V_69 ) ;
return V_27 ;
}
static char * F_39 ( struct V_10 * V_11 , char * V_67 , char * V_23 ,
int V_27 )
{
int V_35 , V_74 ;
unsigned char * V_75 ;
SPRINTF ( L_33 ,
F_5 ( V_11 ) , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
SPRINTF ( L_34 ) ;
V_75 = V_11 -> V_76 ;
SPRINTF ( L_35 , V_75 [ 0 ] , V_75 [ 0 ] ) ;
for ( V_35 = 1 , V_74 = F_41 ( V_75 [ 0 ] ) ; V_35 < V_74 ; ++ V_35 )
SPRINTF ( L_36 , V_75 [ V_35 ] ) ;
SPRINTF ( L_14 ) ;
return V_67 ;
}
static int T_1 F_42 ( struct V_28 * V_29 , int V_36 )
{
int V_35 ;
F_3 ( V_29 ) ;
F_25 () ;
V_15 -> V_77 = 0 ;
V_15 -> V_78 = 1 << V_29 -> V_79 ;
V_15 -> V_80 = 0 ;
for ( V_35 = V_15 -> V_78 ; V_35 <= 0x80 ; V_35 <<= 1 )
if ( V_35 > V_15 -> V_78 )
V_15 -> V_80 |= V_35 ;
for ( V_35 = 0 ; V_35 < 8 ; ++ V_35 )
V_15 -> V_16 [ V_35 ] = 0 ;
#ifdef F_31
F_1 () ;
#endif
#if F_43 ( F_29 )
V_15 -> V_81 = 0 ;
#endif
V_15 -> V_82 = 0 ;
V_15 -> V_71 = NULL ;
V_15 -> V_72 = NULL ;
V_15 -> V_73 = NULL ;
V_15 -> V_36 = V_83 ;
if ( ! V_84 ) {
V_84 = V_29 -> V_85 ;
V_86 = V_29 ;
}
#ifndef F_28
if ( ( V_29 -> V_87 > 1 ) || ( V_29 -> V_88 > 1 ) )
F_10 ( L_37
L_38
L_39 , V_50 ) ;
#endif
F_44 ( V_40 , V_89 ) ;
F_44 ( V_39 , V_90 ) ;
F_44 ( V_91 , 0 ) ;
F_44 ( V_92 , 0 ) ;
return 0 ;
}
static void F_45 ( struct V_28 * V_29 )
{
}
static int F_46 ( struct V_10 * V_11 ,
void (* V_57)( struct V_10 * ) )
{
F_3 ( V_11 -> V_13 -> V_14 ) ;
struct V_10 * V_93 ;
unsigned long V_36 ;
#if ( V_94 & V_95 )
switch ( V_11 -> V_76 [ 0 ] ) {
case V_96 :
case V_97 :
F_10 ( V_21 L_40 ,
F_5 ( V_11 ) ) ;
V_11 -> V_98 = ( V_99 << 16 ) ;
V_57 ( V_11 ) ;
return 0 ;
}
#endif
#ifdef F_47
# if 0
if (!hostdata->connected && !hostdata->issue_queue &&
!hostdata->disconnected_queue) {
hostdata->timebase = jiffies;
}
# endif
# ifdef F_48
if ( F_14 ( V_11 ) > F_48 )
# endif
switch ( V_11 -> V_76 [ 0 ] )
{
case V_100 :
case V_96 :
case V_97 :
V_15 -> V_101 [ V_11 -> V_13 -> V_17 ] -= ( V_102 - V_15 -> V_103 ) ;
V_15 -> V_104 [ V_11 -> V_13 -> V_17 ] += F_14 ( V_11 ) ;
V_15 -> V_105 ++ ;
break;
case V_106 :
case V_107 :
case V_108 :
V_15 -> V_109 [ V_11 -> V_13 -> V_17 ] -= ( V_102 - V_15 -> V_103 ) ;
V_15 -> V_110 [ V_11 -> V_13 -> V_17 ] += F_14 ( V_11 ) ;
V_15 -> V_111 ++ ;
break;
}
#endif
F_49 ( V_11 , NULL ) ;
V_11 -> V_112 = V_57 ;
V_11 -> V_98 = 0 ;
F_19 ( V_36 ) ;
if ( ! ( V_15 -> V_72 ) || ( V_11 -> V_76 [ 0 ] == V_113 ) ) {
F_50 ( V_11 , V_15 -> V_72 ) ;
F_49 ( V_11 , V_15 -> V_72 ) ;
V_15 -> V_72 = V_11 ;
} else {
for ( V_93 = (struct V_10 * ) V_15 -> V_72 ;
F_40 ( V_93 ) ; V_93 = F_40 ( V_93 ) )
;
F_50 ( V_11 , V_93 ) ;
F_49 ( V_93 , V_11 ) ;
}
F_21 ( V_36 ) ;
F_51 ( L_41 , F_5 ( V_11 ) ,
( V_11 -> V_76 [ 0 ] == V_113 ) ? L_42 : L_43 ) ;
if ( F_52 () || ( ( V_36 >> 8 ) & 7 ) >= 6 )
F_23 () ;
else
F_53 ( NULL ) ;
return 0 ;
}
void F_54 ( struct V_28 * V_29 )
{
F_3 ( V_29 ) ;
int V_114 ;
unsigned char * * V_31 ;
volatile int * V_115 ;
if ( ! V_15 -> V_71 ) {
F_10 ( V_116 L_44
L_45 , V_50 ) ;
return;
}
F_55 ( L_46 ,
V_50 , F_20 ( V_41 ) ,
F_20 ( V_38 ) ) ;
if( ( F_56 ( F_57 ( V_15 -> V_71 -> V_117 ) ) ) ) {
F_10 ( L_47 , V_50 ) ;
F_10 ( L_48 ) ;
F_10 ( L_49 ) ;
F_58 () ;
}
if( ( F_20 ( V_41 ) & ( V_118 |
V_119 ) ) ==
( V_118 | V_119 ) ) {
F_10 ( L_50 , V_50 , F_20 ( V_41 ) ) ;
F_10 ( L_51
L_52 , V_50 ) ;
F_10 ( L_53 ) ;
F_10 ( L_48 ) ;
F_10 ( L_49 ) ;
F_58 () ;
}
( void ) F_20 ( V_120 ) ;
F_44 ( V_39 , V_90 ) ;
F_44 ( V_40 , V_89 ) ;
V_114 = V_15 -> V_81 - F_59 ( V_29 ) ;
V_15 -> V_81 = 0 ;
V_31 = ( unsigned char * * ) & ( V_15 -> V_71 -> V_22 . V_25 ) ;
V_115 = & ( V_15 -> V_71 -> V_22 . V_26 ) ;
* V_31 += V_114 ;
* V_115 -= V_114 ;
}
static T_5 F_60 ( int V_121 , void * V_122 )
{
struct V_28 * V_29 = V_86 ;
int V_57 = 1 , V_123 = 0 ;
unsigned char V_32 ;
F_61 ( L_54 , V_50 ) ;
V_32 = F_20 ( V_41 ) ;
F_61 ( L_55 , V_50 , V_32 ) ;
if ( V_32 & V_124 ) {
F_33 ( V_125 ) ;
if ( ( F_20 ( V_38 ) & ( V_126 | V_127 ) ) == ( V_126 | V_127 ) ) {
V_57 = 0 ;
F_61 ( L_56 , V_50 ) ;
F_62 ( V_29 ) ;
( void ) F_20 ( V_120 ) ;
}
else if ( V_32 & V_128 ) {
F_61 ( L_57 , V_50 ) ;
( void ) F_20 ( V_120 ) ;
}
else if ( ( F_20 ( V_38 ) & V_129 ) == V_129 ) {
F_61 ( L_58 , V_50 ) ;
( void ) F_20 ( V_120 ) ;
}
else {
#if F_43 ( F_29 )
if ( ( F_20 ( V_39 ) & V_130 ) &&
( ( V_32 & V_131 ) ||
! ( V_32 & V_118 ) ) ) {
F_61 ( L_59 , V_50 ) ;
F_54 ( V_29 ) ;
V_57 = 0 ;
} else
#endif
{
if ( V_32 & V_118 )
F_61 ( L_60
L_61 ,
V_50 , V_32 , F_20 ( V_39 ) ,
F_20 ( V_38 ) ) ;
( void ) F_20 ( V_120 ) ;
#ifdef F_63
V_132 -> V_133 |= V_134 ;
#endif
}
}
V_123 = 1 ;
}
else {
F_10 ( V_21 L_62
L_63 , V_50 , V_32 ,
F_20 ( V_39 ) , F_20 ( V_38 ) ) ;
( void ) F_20 ( V_120 ) ;
#ifdef F_63
V_132 -> V_133 |= V_134 ;
#endif
}
if ( ! V_57 ) {
F_61 ( L_64 , V_50 ) ;
F_23 () ;
}
return F_64 ( V_123 ) ;
}
static void F_65 ( struct V_68 * V_15 ,
struct V_10 * V_11 )
{
# ifdef F_48
if ( F_14 ( V_11 ) > F_48 )
# endif
switch ( V_11 -> V_76 [ 0 ] )
{
case V_100 :
case V_96 :
case V_97 :
V_15 -> V_101 [ V_11 -> V_13 -> V_17 ] += ( V_102 - V_15 -> V_103 ) ;
V_15 -> V_105 -- ;
break;
case V_106 :
case V_107 :
case V_108 :
V_15 -> V_109 [ V_11 -> V_13 -> V_17 ] += ( V_102 - V_15 -> V_103 ) ;
V_15 -> V_111 -- ;
break;
}
}
static int F_66 ( struct V_28 * V_29 , struct V_10 * V_11 ,
int V_19 )
{
F_3 ( V_29 ) ;
unsigned char V_93 [ 3 ] , V_135 ;
unsigned char * V_31 ;
int V_61 ;
unsigned long V_136 ;
unsigned long V_36 ;
V_15 -> V_137 = 0 ;
F_33 ( V_138 ) ;
F_67 ( L_65 , V_50 ,
V_29 -> V_79 ) ;
F_19 ( V_36 ) ;
if ( V_15 -> V_71 ) {
F_21 ( V_36 ) ;
return - 1 ;
}
F_44 ( V_91 , 0 ) ;
F_44 ( V_139 , V_15 -> V_78 ) ;
F_44 ( V_39 , V_140 ) ;
F_21 ( V_36 ) ;
#ifdef F_68
{
unsigned long V_136 = V_102 + 2 * F_68 ;
while ( ! ( F_20 ( V_40 ) & V_141 )
&& F_69 ( V_102 , V_136 ) && ! V_15 -> V_71 )
;
if ( F_70 ( V_102 , V_136 ) )
{
F_10 ( L_66 , __LINE__ ) ;
F_44 ( V_39 , V_90 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
return - 1 ;
}
}
#else
while ( ! ( F_20 ( V_40 ) & V_141 )
&& ! V_15 -> V_71 ) ;
#endif
F_67 ( L_67 , V_50 ) ;
if ( V_15 -> V_71 ) {
F_44 ( V_39 , V_90 ) ;
return - 1 ;
}
F_71 ( 3 ) ;
if ( ( F_20 ( V_40 ) & V_142 ) ||
( F_20 ( V_37 ) & V_15 -> V_80 ) ||
( F_20 ( V_40 ) & V_142 ) ||
V_15 -> V_71 ) {
F_44 ( V_39 , V_90 ) ;
F_67 ( L_68 ,
V_50 ) ;
return - 1 ;
}
F_44 ( V_40 , V_89 | V_143 |
V_144 ) ;
if ( ( F_20 ( V_40 ) & V_142 ) ||
V_15 -> V_71 ) {
F_44 ( V_39 , V_90 ) ;
F_44 ( V_40 , V_89 ) ;
F_67 ( L_69 ,
V_50 ) ;
return - 1 ;
}
#ifdef F_72
F_71 ( 15 ) ;
#else
F_71 ( 2 ) ;
#endif
if ( V_15 -> V_71 ) {
F_44 ( V_39 , V_90 ) ;
F_44 ( V_40 , V_89 ) ;
return - 1 ;
}
F_67 ( L_70 , V_50 ) ;
F_44 ( V_139 , ( V_15 -> V_78 | ( 1 << V_11 -> V_13 -> V_17 ) ) ) ;
F_44 ( V_40 , ( V_89 | V_144 |
V_145 | V_146 | V_143 ) ) ;
F_44 ( V_39 , V_90 ) ;
if ( V_15 -> V_71 ) {
F_44 ( V_40 , V_89 ) ;
return - 1 ;
}
F_44 ( V_92 , 0 ) ;
F_71 ( 1 ) ;
F_44 ( V_40 , ( V_89 | V_145 |
V_146 | V_143 ) ) ;
F_71 ( 1 ) ;
F_73 ( L_71 , V_50 , V_11 -> V_13 -> V_17 ) ;
V_136 = V_102 + 25 ;
#if 0
while (time_before(jiffies, timeout) && !(NCR5380_read(STATUS_REG) &
(SR_BSY | SR_IO)));
if ((NCR5380_read(STATUS_REG) & (SR_SEL | SR_IO)) ==
(SR_SEL | SR_IO)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_reselect(instance);
printk (KERN_ERR "scsi%d: reselection after won arbitration?\n",
HOSTNO);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return -1;
}
#else
while ( F_69 ( V_102 , V_136 ) && ! ( F_20 ( V_38 ) & V_147 ) ) ;
#endif
F_71 ( 1 ) ;
F_44 ( V_40 , V_89 | V_146 ) ;
if ( ! ( F_20 ( V_38 ) & V_147 ) ) {
F_44 ( V_40 , V_89 ) ;
if ( V_15 -> V_82 & ( 1 << V_11 -> V_13 -> V_17 ) ) {
F_10 ( V_148 L_72 , V_50 ) ;
if ( V_15 -> V_137 )
F_10 ( V_21 L_73 ) ;
F_33 ( V_62 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
return - 1 ;
}
V_11 -> V_98 = V_149 << 16 ;
#ifdef F_47
F_65 ( V_15 , V_11 ) ;
#endif
#ifdef F_31
F_9 ( V_11 ) ;
#endif
V_11 -> V_112 ( V_11 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
F_73 ( L_74 , V_50 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
return 0 ;
}
V_15 -> V_82 |= ( 1 << V_11 -> V_13 -> V_17 ) ;
while ( ! ( F_20 ( V_38 ) & V_48 ) ) ;
F_73 ( L_75 ,
V_50 , V_11 -> V_13 -> V_17 ) ;
V_93 [ 0 ] = F_74 ( 1 , V_11 -> V_13 -> V_2 ) ;
#ifdef F_31
if ( V_11 -> V_19 != V_20 ) {
V_93 [ 1 ] = V_15 -> V_150 = V_151 ;
V_93 [ 2 ] = V_11 -> V_19 ;
V_61 = 3 ;
} else
V_61 = 1 ;
#else
V_61 = 1 ;
V_11 -> V_19 = 0 ;
#endif
V_31 = V_93 ;
V_135 = V_152 ;
F_75 ( V_29 , & V_135 , & V_61 , & V_31 ) ;
F_73 ( L_76 , V_50 ) ;
V_15 -> V_71 = V_11 ;
#ifndef F_31
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] |= ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
#ifdef F_63
V_132 -> V_133 |= V_153 ;
#endif
F_13 ( V_11 ) ;
return 0 ;
}
static int F_75 ( struct V_28 * V_29 ,
unsigned char * V_135 , int * V_115 ,
unsigned char * * V_31 )
{
register unsigned char V_154 = * V_135 , V_93 ;
register int V_155 = * V_115 ;
register unsigned char * V_156 = * V_31 ;
F_44 ( V_91 , F_76 ( V_154 ) ) ;
do {
while ( ! ( ( V_93 = F_20 ( V_38 ) ) & V_48 ) ) ;
F_77 ( L_77 , V_50 ) ;
if ( ( V_93 & V_54 ) != V_154 ) {
F_78 ( L_78 , V_50 ) ;
F_34 ( V_157 ) ;
break;
}
if ( ! ( V_154 & V_127 ) )
F_44 ( V_139 , * V_156 ) ;
else
* V_156 = F_20 ( V_37 ) ;
++ V_156 ;
if ( ! ( V_154 & V_127 ) ) {
if ( ! ( ( V_154 & V_158 ) && V_155 > 1 ) ) {
F_44 ( V_40 , V_89 |
V_145 ) ;
F_33 ( V_157 ) ;
F_44 ( V_40 , V_89 |
V_145 | V_159 ) ;
} else {
F_44 ( V_40 , V_89 |
V_145 | V_146 ) ;
F_33 ( V_157 ) ;
F_44 ( V_40 , V_89 |
V_145 | V_146 | V_159 ) ;
}
} else {
F_33 ( V_157 ) ;
F_44 ( V_40 , V_89 | V_159 ) ;
}
while ( F_20 ( V_38 ) & V_48 ) ;
F_77 ( L_79 , V_50 ) ;
if ( ! ( V_154 == V_160 && V_155 == 1 ) ) {
if ( V_154 == V_152 && V_155 > 1 )
F_44 ( V_40 , V_89 | V_146 ) ;
else
F_44 ( V_40 , V_89 ) ;
}
} while ( -- V_155 );
F_78 ( L_80 , V_50 , V_155 ) ;
* V_115 = V_155 ;
* V_31 = V_156 ;
V_93 = F_20 ( V_38 ) ;
if ( ( V_93 & V_48 ) || ( V_154 == V_160 && V_155 == 0 ) )
* V_135 = V_93 & V_54 ;
else
* V_135 = V_53 ;
if ( ! V_155 || ( * V_135 == V_154 ) )
return 0 ;
else
return - 1 ;
}
static int F_79 ( struct V_28 * V_14 )
{
unsigned char V_93 , * V_161 , V_135 ;
int V_61 ;
F_44 ( V_40 , V_89 | V_146 ) ;
while ( ! ( ( V_93 = F_20 ( V_38 ) ) & V_48 ) ) ;
F_44 ( V_91 , F_76 ( V_93 ) ) ;
if ( ( V_93 & V_54 ) != V_152 ) {
F_44 ( V_40 , V_89 | V_146 |
V_159 ) ;
while ( F_20 ( V_38 ) & V_48 ) ;
F_44 ( V_40 , V_89 | V_146 ) ;
}
V_93 = ABORT ;
V_161 = & V_93 ;
V_61 = 1 ;
V_135 = V_152 ;
F_75 ( V_14 , & V_135 , & V_61 , & V_161 ) ;
return V_61 ? - 1 : 0 ;
}
static int F_80 ( struct V_28 * V_29 ,
unsigned char * V_135 , int * V_115 ,
unsigned char * * V_31 )
{
F_3 ( V_29 ) ;
register int V_155 = * V_115 ;
register unsigned char V_154 = * V_135 ;
unsigned long V_36 ;
if( ! V_162 ) {
F_10 ( L_81 , V_50 ) ;
F_58 () ;
}
V_15 -> V_81 = V_155 ;
F_55 ( L_82 ,
V_50 , ( V_154 & V_127 ) ? L_83 : L_84 ,
V_155 , ( V_154 & V_127 ) ? L_85 : L_86 , * V_31 ) ;
F_19 ( V_36 ) ;
F_81 ( V_155 , * V_31 ) ;
if ( V_154 & V_127 ) {
F_44 ( V_91 , 1 ) ;
F_20 ( V_120 ) ;
F_44 ( V_40 , 0 ) ;
F_44 ( V_39 , ( F_20 ( V_39 ) | V_130 | V_163 ) ) ;
F_44 ( V_164 , 0 ) ;
} else {
F_44 ( V_91 , 0 ) ;
F_20 ( V_120 ) ;
F_44 ( V_40 , V_145 ) ;
F_44 ( V_39 , ( F_20 ( V_39 ) | V_130 | V_163 ) ) ;
F_44 ( V_165 , 0 ) ;
}
#ifdef F_63
V_132 -> V_133 |= V_134 ;
#endif
F_21 ( V_36 ) ;
V_166 = 1 ;
return 0 ;
}
static void F_82 ( struct V_28 * V_29 )
{
F_3 ( V_29 ) ;
unsigned long V_36 ;
unsigned char V_167 = V_168 ;
int V_169 = 0 ;
int V_61 ;
#if F_43 ( F_29 )
int V_170 ;
#endif
unsigned char * V_31 ;
unsigned char V_135 , V_93 , V_171 [ 10 ] , V_172 = 0xff ;
struct V_10 * V_11 = (struct V_10 * ) V_15 -> V_71 ;
#ifdef F_63
V_132 -> V_133 |= V_153 ;
#endif
while ( 1 ) {
V_93 = F_20 ( V_38 ) ;
if ( V_93 & V_48 ) {
V_135 = ( V_93 & V_54 ) ;
if ( V_135 != V_172 ) {
V_172 = V_135 ;
F_34 ( V_173 ) ;
}
if( V_135 == V_174 ) {
void * V_156 ;
unsigned long V_115 ;
if ( ! V_11 -> V_22 . V_26 && V_11 -> V_22 . V_24 ) {
V_115 = V_11 -> V_22 . V_23 -> V_27 ;
V_156 = F_17 ( V_11 -> V_22 . V_23 ) ;
} else {
V_115 = V_11 -> V_22 . V_26 ;
V_156 = V_11 -> V_22 . V_25 ;
}
#ifdef F_29
if( ( V_115 > V_175 ) && ( V_162
!= V_11 ) )
{
if ( V_11 -> V_117 -> V_176 == V_177 ) {
F_83 ( V_156 , V_115 ,
F_57 ( V_11 -> V_117 ) ) ;
V_162 = V_11 ;
}
}
#endif
#ifdef F_63
V_132 -> V_133 |= V_153 ;
#endif
}
if ( V_169 && ( V_135 != V_152 ) ) {
F_44 ( V_91 , F_76 ( V_93 ) ) ;
F_44 ( V_40 , V_89 | V_146 |
V_159 ) ;
while ( F_20 ( V_38 ) & V_48 ) ;
F_44 ( V_40 , V_89 |
V_146 ) ;
V_169 = 0 ;
continue;
}
switch ( V_135 ) {
case V_178 :
#if ( V_94 & V_179 )
F_10 ( L_87
L_88 , V_50 ) ;
V_169 = 1 ;
F_79 ( V_29 ) ;
V_11 -> V_98 = V_99 << 16 ;
V_11 -> V_112 ( V_11 ) ;
return;
#endif
case V_180 :
if ( ! V_11 -> V_22 . V_26 && V_11 -> V_22 . V_24 ) {
++ V_11 -> V_22 . V_23 ;
-- V_11 -> V_22 . V_24 ;
V_11 -> V_22 . V_26 = V_11 -> V_22 . V_23 -> V_27 ;
V_11 -> V_22 . V_25 = F_17 ( V_11 -> V_22 . V_23 ) ;
F_84 ( L_89 ,
V_50 , V_11 -> V_22 . V_26 ,
V_11 -> V_22 . V_24 ) ;
}
#if F_43 ( F_29 )
if( ( V_170 =
F_85 ( V_29 , V_11 , V_135 ) ) > V_175 ) {
V_61 = V_170 ;
V_11 -> V_22 . V_135 = V_135 ;
if ( F_80 ( V_29 , & V_135 ,
& V_61 , ( unsigned char * * ) & V_11 -> V_22 . V_25 ) ) {
F_10 ( V_21 L_90
L_91 , V_50 ,
V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
V_11 -> V_13 -> V_181 = 1 ;
F_44 ( V_40 , V_89 |
V_146 ) ;
V_169 = 1 ;
F_79 ( V_29 ) ;
V_11 -> V_98 = V_99 << 16 ;
V_11 -> V_112 ( V_11 ) ;
} else {
#ifdef F_29
return;
#else
V_11 -> V_22 . V_26 -= V_170 - V_61 ;
#endif
}
} else
#endif
F_75 ( V_29 , & V_135 ,
( int * ) & V_11 -> V_22 . V_26 , ( unsigned char * * )
& V_11 -> V_22 . V_25 ) ;
#ifdef F_29
if( V_162 == V_11 )
V_162 = NULL ;
#endif
break;
case V_160 :
V_61 = 1 ;
V_31 = & V_93 ;
F_44 ( V_92 , 0 ) ;
F_75 ( V_29 , & V_135 , & V_61 , & V_31 ) ;
V_11 -> V_22 . V_182 = V_93 ;
switch ( V_93 ) {
#ifdef F_86
case V_183 :
case V_184 :
F_44 ( V_40 , V_89 ) ;
F_87 ( L_92
L_93 , V_50 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
if ( ! V_11 -> V_185 ) {
F_10 ( V_21 L_94
L_95 ,
V_50 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
V_169 = 1 ;
F_79 ( V_29 ) ;
return;
}
F_13 ( V_11 -> V_185 ) ;
V_11 -> V_185 -> V_19 = V_11 -> V_19 ;
V_11 -> V_98 = V_11 -> V_22 . V_186 | ( V_11 -> V_22 . V_182 << 8 ) ;
F_87 ( L_96
L_97 ,
V_50 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
#ifdef F_47
F_65 ( V_15 , V_11 ) ;
#endif
V_11 -> V_112 ( V_11 ) ;
V_11 = V_15 -> V_71 ;
break;
#endif
case ABORT :
case V_187 :
F_44 ( V_40 , V_89 ) ;
V_15 -> V_71 = NULL ;
F_51 ( L_98
L_99 , V_50 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
#ifdef F_31
F_9 ( V_11 ) ;
if ( F_88 ( V_11 -> V_22 . V_186 ) == V_188 ) {
T_2 * V_3 = & V_5 [ V_11 -> V_13 -> V_17 ] [ V_11 -> V_13 -> V_2 ] ;
F_4 ( L_100
L_101 ,
V_50 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ,
V_3 -> V_8 ) ;
if ( V_3 -> V_9 > V_3 -> V_8 )
V_3 -> V_8 = V_3 -> V_9 ;
}
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
F_44 ( V_92 , V_15 -> V_78 ) ;
if ( V_11 -> V_76 [ 0 ] != V_113 )
V_11 -> V_98 = V_11 -> V_22 . V_186 | ( V_11 -> V_22 . V_182 << 8 ) ;
else if ( F_88 ( V_11 -> V_22 . V_186 ) != V_189 )
V_11 -> V_98 = ( V_11 -> V_98 & 0x00ffff ) | ( V_99 << 16 ) ;
#ifdef F_28
if ( ( V_11 -> V_76 [ 0 ] == V_113 ) &&
V_15 -> V_190 . V_191 ) {
F_89 ( V_11 , & V_15 -> V_190 ) ;
V_15 -> V_190 . V_191 = 0 ;
}
if ( ( V_11 -> V_76 [ 0 ] != V_113 ) &&
( F_88 ( V_11 -> V_22 . V_186 ) == V_192 ) ) {
F_90 ( V_11 , & V_15 -> V_190 , NULL , 0 , ~ 0 ) ;
F_91 ( L_102 ,
V_50 ) ;
F_19 ( V_36 ) ;
F_50 ( V_11 , V_15 -> V_72 ) ;
F_49 ( V_11 , V_15 -> V_72 ) ;
V_15 -> V_72 = (struct V_10 * ) V_11 ;
F_21 ( V_36 ) ;
F_51 ( L_103
L_104 , F_5 ( V_11 ) ) ;
} else
#endif
{
#ifdef F_47
F_65 ( V_15 , V_11 ) ;
#endif
V_11 -> V_112 ( V_11 ) ;
}
F_44 ( V_92 , V_15 -> V_78 ) ;
F_44 ( V_91 , 0 ) ;
while ( ( F_20 ( V_38 ) & V_147 ) && ! V_15 -> V_71 )
F_92 () ;
return;
case V_193 :
F_44 ( V_40 , V_89 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
switch ( V_15 -> V_150 ) {
case V_194 :
case V_195 :
case V_151 :
V_11 -> V_13 -> V_18 = 0 ;
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] |= ( 1 << V_11 -> V_13 -> V_2 ) ;
V_11 -> V_19 = V_20 ;
F_4 ( L_105
L_106
L_107 ,
V_50 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
break;
}
break;
case V_196 :
F_44 ( V_40 , V_89 ) ;
F_19 ( V_36 ) ;
V_11 -> V_13 -> V_197 = 1 ;
F_50 ( V_11 , V_15 -> V_73 ) ;
F_49 ( V_11 , V_15 -> V_73 ) ;
V_15 -> V_71 = NULL ;
V_15 -> V_73 = V_11 ;
F_21 ( V_36 ) ;
F_51 ( L_108
L_109
L_110 , V_50 ,
V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
F_44 ( V_91 , 0 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
while ( ( F_20 ( V_38 ) & V_147 ) && ! V_15 -> V_71 )
F_92 () ;
#ifdef F_63
V_132 -> V_133 |= V_134 ;
#endif
return;
case V_198 :
case V_199 :
F_44 ( V_40 , V_89 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
break;
case V_200 :
V_171 [ 0 ] = V_200 ;
F_44 ( V_40 , V_89 ) ;
F_93 ( L_111 , V_50 ) ;
V_61 = 2 ;
V_31 = V_171 + 1 ;
V_135 = V_160 ;
F_75 ( V_29 , & V_135 , & V_61 , & V_31 ) ;
F_93 ( L_112 , V_50 ,
( int ) V_171 [ 1 ] , ( int ) V_171 [ 2 ] ) ;
if ( ! V_61 && V_171 [ 1 ] <=
( sizeof ( V_171 ) - 1 ) ) {
F_44 ( V_40 , V_89 ) ;
V_61 = V_171 [ 1 ] - 1 ;
V_31 = V_171 + 3 ;
V_135 = V_160 ;
F_75 ( V_29 , & V_135 , & V_61 , & V_31 ) ;
F_93 ( L_113 ,
V_50 , V_61 ) ;
switch ( V_171 [ 2 ] ) {
case V_201 :
case V_202 :
case V_203 :
case V_204 :
V_93 = 0 ;
}
} else if ( V_61 ) {
F_10 ( V_21 L_114
L_115 , V_50 ) ;
V_93 = 0 ;
} else {
F_10 ( V_21 L_116
L_117 ,
V_50 , V_171 [ 2 ] , V_171 [ 1 ] ) ;
V_93 = 0 ;
}
default:
if ( ! V_93 ) {
F_10 ( V_49 L_118 , V_50 ) ;
F_94 ( V_171 ) ;
F_10 ( L_14 ) ;
} else if ( V_93 != V_200 )
F_10 ( V_49 L_119
L_120 ,
V_50 , V_93 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
else
F_10 ( V_49 L_119
L_121
L_122 ,
V_50 , V_171 [ 1 ] , V_171 [ 0 ] ,
V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
V_167 = V_193 ;
F_44 ( V_40 , V_89 |
V_146 ) ;
break;
}
break;
case V_152 :
V_61 = 1 ;
V_31 = & V_167 ;
V_15 -> V_150 = V_167 ;
F_75 ( V_29 , & V_135 , & V_61 , & V_31 ) ;
if ( V_167 == ABORT ) {
#ifdef F_31
F_9 ( V_11 ) ;
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
V_15 -> V_71 = NULL ;
V_11 -> V_98 = V_99 << 16 ;
#ifdef F_47
F_65 ( V_15 , V_11 ) ;
#endif
V_11 -> V_112 ( V_11 ) ;
F_44 ( V_92 , V_15 -> V_78 ) ;
return;
}
V_167 = V_168 ;
break;
case V_174 :
V_61 = V_11 -> V_191 ;
V_31 = V_11 -> V_76 ;
F_75 ( V_29 , & V_135 , & V_61 ,
& V_31 ) ;
break;
case V_205 :
V_61 = 1 ;
V_31 = & V_93 ;
F_75 ( V_29 , & V_135 , & V_61 , & V_31 ) ;
V_11 -> V_22 . V_186 = V_93 ;
break;
default:
F_10 ( L_123 , V_50 ) ;
F_33 ( V_62 ) ;
}
}
}
}
static void F_62 ( struct V_28 * V_29 )
{
F_3 ( V_29 ) ;
unsigned char V_206 ;
unsigned char V_2 ;
#ifdef F_31
unsigned char V_19 ;
#endif
unsigned char V_207 [ 3 ] ;
struct V_10 * V_93 = NULL , * V_208 ;
F_44 ( V_39 , V_90 ) ;
V_15 -> V_137 = 1 ;
V_206 = F_20 ( V_37 ) & ~ ( V_15 -> V_78 ) ;
F_95 ( L_124 , V_50 ) ;
F_44 ( V_40 , V_89 | V_144 ) ;
while ( F_20 ( V_38 ) & V_126 ) ;
F_44 ( V_40 , V_89 ) ;
while ( ! ( F_20 ( V_38 ) & V_48 ) ) ;
#if 1
F_44 ( V_91 , F_76 ( V_160 ) ) ;
V_207 [ 0 ] = F_20 ( V_37 ) ;
#endif
if ( ! ( V_207 [ 0 ] & 0x80 ) ) {
F_10 ( V_49 L_125 , V_50 ) ;
F_94 ( V_207 ) ;
F_79 ( V_29 ) ;
return;
}
V_2 = ( V_207 [ 0 ] & 0x07 ) ;
for ( V_93 = (struct V_10 * ) V_15 -> V_73 , V_208 = NULL ;
V_93 ; V_208 = V_93 , V_93 = F_40 ( V_93 ) ) {
if ( ( V_206 == ( 1 << V_93 -> V_13 -> V_17 ) ) && ( V_2 == V_93 -> V_13 -> V_2 )
#ifdef F_31
&& ( V_19 == V_93 -> V_19 )
#endif
) {
if ( V_208 ) {
REMOVE ( V_208 , F_40 ( V_208 ) , V_93 , F_40 ( V_93 ) ) ;
F_49 ( V_208 , F_40 ( V_93 ) ) ;
} else {
REMOVE ( - 1 , V_15 -> V_73 , V_93 , F_40 ( V_93 ) ) ;
V_15 -> V_73 = F_40 ( V_93 ) ;
}
F_49 ( V_93 , NULL ) ;
break;
}
}
if ( ! V_93 ) {
F_10 ( V_116 L_126
#ifdef F_31
L_127
#endif
L_128 ,
V_50 , V_206 , V_2
#ifdef F_31
, V_19
#endif
) ;
F_79 ( V_29 ) ;
return;
}
#if 1
{
void * V_156 ;
unsigned long V_115 ;
if ( ! V_93 -> V_22 . V_26 && V_93 -> V_22 . V_24 ) {
V_115 = V_93 -> V_22 . V_23 -> V_27 ;
V_156 = F_17 ( V_93 -> V_22 . V_23 ) ;
} else {
V_115 = V_93 -> V_22 . V_26 ;
V_156 = V_93 -> V_22 . V_25 ;
}
#ifdef F_29
if( ( V_115 > V_175 ) && ( V_162 != V_93 ) )
{
F_83 ( V_156 , V_115 , F_57 ( V_93 -> V_117 ) ) ;
V_162 = V_93 ;
}
#endif
}
#endif
F_44 ( V_40 , V_89 | V_159 ) ;
F_44 ( V_40 , V_89 ) ;
#ifdef F_31
V_19 = V_20 ;
if ( V_135 == V_160 && V_4 ) {
F_44 ( V_40 , V_89 ) ;
V_61 = 2 ;
V_31 = V_207 + 1 ;
if ( ! F_75 ( V_29 , & V_135 , & V_61 , & V_31 ) &&
V_207 [ 1 ] == V_151 )
V_19 = V_207 [ 2 ] ;
F_4 ( L_129
L_130 , V_50 , V_206 , V_2 , V_19 ) ;
}
#endif
V_15 -> V_71 = V_93 ;
F_95 ( L_131 ,
V_50 , V_93 -> V_1 , V_93 -> V_2 , V_93 -> V_19 ) ;
}
static int F_96 ( struct V_10 * V_11 )
{
struct V_28 * V_29 = V_11 -> V_13 -> V_14 ;
F_3 ( V_29 ) ;
struct V_10 * V_93 , * * V_208 ;
unsigned long V_36 ;
F_10 ( V_21 L_132 , V_50 ) ;
F_97 ( V_11 ) ;
F_32 ( V_29 ) ;
F_19 ( V_36 ) ;
F_98 ( L_133 , V_50 ,
F_20 ( V_41 ) ,
F_20 ( V_38 ) ) ;
#if 1
if ( V_15 -> V_71 == V_11 ) {
F_98 ( L_134 , V_50 ) ;
if ( F_79 ( V_29 ) == 0 ) {
V_15 -> V_77 = 1 ;
V_15 -> V_71 = NULL ;
V_11 -> V_98 = V_209 << 16 ;
#ifdef F_31
F_9 ( V_11 ) ;
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
F_21 ( V_36 ) ;
V_11 -> V_112 ( V_11 ) ;
return V_210 ;
} else {
F_10 ( L_135 , V_50 ) ;
return V_211 ;
}
}
#endif
for ( V_208 = (struct V_10 * * ) & ( V_15 -> V_72 ) ,
V_93 = (struct V_10 * ) V_15 -> V_72 ;
V_93 ; V_208 = F_99 ( V_93 ) , V_93 = F_40 ( V_93 ) )
if ( V_11 == V_93 ) {
REMOVE ( 5 , * V_208 , V_93 , F_40 ( V_93 ) ) ;
( * V_208 ) = F_40 ( V_93 ) ;
F_49 ( V_93 , NULL ) ;
V_93 -> V_98 = V_209 << 16 ;
F_21 ( V_36 ) ;
F_98 ( L_136 ,
V_50 ) ;
V_93 -> V_112 ( V_93 ) ;
return V_210 ;
}
if ( V_15 -> V_71 ) {
F_21 ( V_36 ) ;
F_98 ( L_137 , V_50 ) ;
return V_212 ;
}
for ( V_93 = (struct V_10 * ) V_15 -> V_73 ; V_93 ;
V_93 = F_40 ( V_93 ) )
if ( V_11 == V_93 ) {
F_21 ( V_36 ) ;
F_98 ( L_138 , V_50 ) ;
if ( F_66 ( V_29 , V_11 , ( int ) V_11 -> V_19 ) )
return V_213 ;
F_98 ( L_139 , V_50 ) ;
F_79 ( V_29 ) ;
F_19 ( V_36 ) ;
for ( V_208 = (struct V_10 * * ) & ( V_15 -> V_73 ) ,
V_93 = (struct V_10 * ) V_15 -> V_73 ;
V_93 ; V_208 = F_99 ( V_93 ) , V_93 = F_40 ( V_93 ) )
if ( V_11 == V_93 ) {
REMOVE ( 5 , * V_208 , V_93 , F_40 ( V_93 ) ) ;
* V_208 = F_40 ( V_93 ) ;
F_49 ( V_93 , NULL ) ;
V_93 -> V_98 = V_209 << 16 ;
#ifdef F_31
F_9 ( V_93 ) ;
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
F_21 ( V_36 ) ;
V_93 -> V_112 ( V_93 ) ;
return V_210 ;
}
}
F_21 ( V_36 ) ;
F_10 ( V_214 L_140 , V_50 ) ;
return V_215 ;
}
static int F_100 ( struct V_10 * V_11 )
{
F_3 ( V_11 -> V_13 -> V_14 ) ;
int V_35 ;
unsigned long V_36 ;
#if 1
struct V_10 * V_71 , * V_73 ;
#endif
F_32 ( V_11 -> V_13 -> V_14 ) ;
F_44 ( V_91 ,
F_76 ( F_20 ( V_38 ) ) ) ;
F_44 ( V_40 , V_89 | V_216 ) ;
F_71 ( 40 ) ;
F_44 ( V_40 , V_89 ) ;
F_44 ( V_39 , V_90 ) ;
F_44 ( V_91 , 0 ) ;
F_44 ( V_92 , 0 ) ;
( void ) F_20 ( V_120 ) ;
#if 1
F_19 ( V_36 ) ;
V_71 = (struct V_10 * ) V_15 -> V_71 ;
V_15 -> V_71 = NULL ;
V_73 = (struct V_10 * ) V_15 -> V_73 ;
V_15 -> V_73 = NULL ;
#ifdef F_31
F_12 () ;
#endif
for( V_35 = 0 ; V_35 < 8 ; ++ V_35 )
V_15 -> V_16 [ V_35 ] = 0 ;
#ifdef F_29
V_15 -> V_81 = 0 ;
#endif
F_21 ( V_36 ) ;
if ( ( V_11 = V_71 ) ) {
F_98 ( L_141 , F_5 ( V_11 ) ) ;
V_11 -> V_98 = ( V_11 -> V_98 & 0xffff ) | ( V_217 << 16 ) ;
V_11 -> V_112 ( V_11 ) ;
}
for ( V_35 = 0 ; ( V_11 = V_73 ) ; ++ V_35 ) {
V_73 = F_40 ( V_11 ) ;
F_49 ( V_11 , NULL ) ;
V_11 -> V_98 = ( V_11 -> V_98 & 0xffff ) | ( V_217 << 16 ) ;
V_11 -> V_112 ( V_11 ) ;
}
if ( V_35 > 0 )
F_98 ( L_142 , V_35 ) ;
return V_218 | V_219 ;
#else
if ( V_15 -> V_72 )
F_98 ( L_143 , F_5 ( V_11 ) ) ;
if ( V_15 -> V_71 )
F_98 ( L_141 , F_5 ( V_11 ) ) ;
if ( V_15 -> V_73 )
F_98 ( L_144 , F_5 ( V_11 ) ) ;
F_19 ( V_36 ) ;
V_15 -> V_72 = NULL ;
V_15 -> V_71 = NULL ;
V_15 -> V_73 = NULL ;
#ifdef F_31
F_12 () ;
#endif
for( V_35 = 0 ; V_35 < 8 ; ++ V_35 )
V_15 -> V_16 [ V_35 ] = 0 ;
#ifdef F_29
V_15 -> V_81 = 0 ;
#endif
F_21 ( V_36 ) ;
return V_220 | V_219 ;
#endif
}
