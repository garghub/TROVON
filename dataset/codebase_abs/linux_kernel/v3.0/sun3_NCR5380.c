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
static void F_13 ( struct V_10 * V_11 )
{
unsigned long V_22 ;
#if ( V_23 & V_24 )
unsigned long V_25 = V_11 -> V_26 . V_27 ;
int V_28 = 1 ;
#endif
for ( V_22 = F_14 ( V_11 -> V_26 . V_29 + V_11 -> V_26 . V_27 - 1 ) + 1 ;
V_11 -> V_26 . V_30 &&
F_14 ( F_15 ( & ( V_11 -> V_26 . V_31 [ 1 ] ) ) ) == V_22 ; ) {
F_16 ( L_9 ,
F_15 ( & ( V_11 -> V_26 . V_31 [ 1 ] ) ) , V_22 ) ;
#if ( V_23 & V_24 )
++ V_28 ;
#endif
++ V_11 -> V_26 . V_31 ;
-- V_11 -> V_26 . V_30 ;
V_11 -> V_26 . V_27 += V_11 -> V_26 . V_31 -> V_32 ;
V_22 += V_11 -> V_26 . V_31 -> V_32 ;
}
#if ( V_23 & V_24 )
if ( V_25 != V_11 -> V_26 . V_27 )
F_16 ( L_10 ,
V_28 , V_11 -> V_26 . V_29 , V_11 -> V_26 . V_27 ) ;
#endif
}
static T_3 void F_17 ( struct V_10 * V_11 )
{
if ( F_18 ( V_11 ) ) {
V_11 -> V_26 . V_31 = F_19 ( V_11 ) ;
V_11 -> V_26 . V_30 = F_20 ( V_11 ) - 1 ;
V_11 -> V_26 . V_29 = ( char * ) F_15 ( V_11 -> V_26 . V_31 ) ;
V_11 -> V_26 . V_27 = V_11 -> V_26 . V_31 -> V_32 ;
} else {
V_11 -> V_26 . V_31 = NULL ;
V_11 -> V_26 . V_30 = 0 ;
V_11 -> V_26 . V_29 = NULL ;
V_11 -> V_26 . V_27 = 0 ;
}
}
static void F_21 ( struct V_33 * V_34 ) {
unsigned char V_35 , V_36 , V_37 , V_38 , V_39 , V_40 ;
unsigned long V_41 ;
F_22 ( V_41 ) ;
V_36 = F_23 ( V_42 ) ;
V_35 = F_23 ( V_43 ) ;
V_38 = F_23 ( V_44 ) ;
V_39 = F_23 ( V_45 ) ;
V_37 = F_23 ( V_46 ) ;
F_24 ( V_41 ) ;
F_10 ( L_11 , V_35 ) ;
for ( V_40 = 0 ; V_47 [ V_40 ] . V_48 ; ++ V_40 )
if ( V_35 & V_47 [ V_40 ] . V_48 )
F_10 ( L_12 , V_47 [ V_40 ] . V_49 ) ;
F_10 ( L_13 , V_37 ) ;
for ( V_40 = 0 ; V_50 [ V_40 ] . V_48 ; ++ V_40 )
if ( V_37 & V_50 [ V_40 ] . V_48 )
F_10 ( L_12 , V_50 [ V_40 ] . V_49 ) ;
F_10 ( L_14 , V_39 ) ;
for ( V_40 = 0 ; V_51 [ V_40 ] . V_48 ; ++ V_40 )
if ( V_39 & V_51 [ V_40 ] . V_48 )
F_10 ( L_12 , V_51 [ V_40 ] . V_49 ) ;
F_10 ( L_15 , V_38 ) ;
for ( V_40 = 0 ; V_52 [ V_40 ] . V_48 ; ++ V_40 )
if ( V_38 & V_52 [ V_40 ] . V_48 )
F_10 ( L_12 , V_52 [ V_40 ] . V_49 ) ;
F_10 ( L_16 ) ;
}
static void F_25 ( struct V_33 * V_34 )
{
unsigned char V_35 ;
int V_40 ;
V_35 = F_23 ( V_43 ) ;
if ( ! ( V_35 & V_53 ) )
F_10 ( V_54 L_17 , V_55 ) ;
else {
for ( V_40 = 0 ; ( V_56 [ V_40 ] . V_57 != V_58 ) &&
( V_56 [ V_40 ] . V_57 != ( V_35 & V_59 ) ) ; ++ V_40 ) ;
F_10 ( V_54 L_18 , V_55 , V_56 [ V_40 ] . V_49 ) ;
}
}
T_3 void F_21 ( struct V_33 * V_34 ) { }
T_3 void F_25 ( struct V_33 * V_34 ) { }
static T_3 void F_26 ( void )
{
if ( ! V_60 ) {
F_27 ( & V_61 ) ;
}
}
static inline void F_28 ( void )
{
static int V_62 = 0 ;
if ( ! V_62 ) {
F_29 ( L_19 ) ;
V_62 = 1 ;
}
}
static void T_1 F_30 ( struct V_33 * V_34 )
{
F_10 ( L_20
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
) ;
F_10 ( L_25 , V_63 ) ;
}
static void F_35 ( struct V_33 * V_34 )
{
char * V_64 ;
char * V_65 ;
int V_66 ;
F_36 ( V_67 ) ;
F_37 ( V_67 ) ;
V_64 = ( char * ) F_38 ( V_68 ) ;
if ( ! V_64 ) {
F_10 ( L_26 ) ;
return;
}
V_66 = F_39 ( V_34 , V_64 , & V_65 , 0 , V_69 , 0 ) ;
V_64 [ V_66 ] = 0 ;
F_10 ( L_27 , V_64 ) ;
F_40 ( ( unsigned long ) V_64 ) ;
}
static int F_39 ( struct V_33 * V_34 , char * V_31 ,
char * * V_65 , T_4 V_70 , int V_32 , int V_71 )
{
char * V_72 = V_31 ;
struct V_73 * V_15 ;
struct V_10 * V_29 ;
unsigned long V_41 ;
T_4 V_74 = 0 ;
#define F_41 () \
do { \
if (pos - buffer < offset - begin) { \
begin += pos - buffer; \
pos = buffer; \
} \
} while (0)
V_15 = (struct V_73 * ) V_34 -> V_15 ;
if ( V_71 ) {
return ( - V_75 ) ;
}
SPRINTF ( L_28 , V_63 ) ;
F_41 () ;
F_22 ( V_41 ) ;
SPRINTF ( L_29 , V_60 ? L_30 : L_31 ) ;
F_41 () ;
if ( ! V_15 -> V_76 )
SPRINTF ( L_32 , V_55 ) ;
else
V_72 = F_42 ( (struct V_10 * ) V_15 -> V_76 ,
V_72 , V_31 , V_32 ) ;
SPRINTF ( L_33 , V_55 ) ;
F_41 () ;
for ( V_29 = (struct V_10 * ) V_15 -> V_77 ; V_29 ; V_29 = F_43 ( V_29 ) )
{
V_72 = F_42 ( V_29 , V_72 , V_31 , V_32 ) ;
F_41 () ;
}
SPRINTF ( L_34 , V_55 ) ;
F_41 () ;
for ( V_29 = (struct V_10 * ) V_15 -> V_78 ; V_29 ;
V_29 = F_43 ( V_29 ) ) {
V_72 = F_42 ( V_29 , V_72 , V_31 , V_32 ) ;
F_41 () ;
}
F_24 ( V_41 ) ;
* V_65 = V_31 + ( V_70 - V_74 ) ;
if ( V_72 - V_31 < V_70 - V_74 )
return 0 ;
else if ( V_72 - V_31 - ( V_70 - V_74 ) < V_32 )
return V_72 - V_31 - ( V_70 - V_74 ) ;
return V_32 ;
}
static char * F_42 ( struct V_10 * V_11 , char * V_72 , char * V_31 ,
int V_32 )
{
int V_40 , V_79 ;
unsigned char * V_80 ;
SPRINTF ( L_35 ,
F_5 ( V_11 ) , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
SPRINTF ( L_36 ) ;
V_80 = V_11 -> V_81 ;
SPRINTF ( L_37 , V_80 [ 0 ] , V_80 [ 0 ] ) ;
for ( V_40 = 1 , V_79 = F_44 ( V_80 [ 0 ] ) ; V_40 < V_79 ; ++ V_40 )
SPRINTF ( L_38 , V_80 [ V_40 ] ) ;
SPRINTF ( L_16 ) ;
return V_72 ;
}
static int F_45 ( struct V_33 * V_34 , int V_41 )
{
int V_40 ;
F_3 ( V_34 ) ;
F_28 () ;
V_15 -> V_82 = 0 ;
V_15 -> V_83 = 1 << V_34 -> V_84 ;
V_15 -> V_85 = 0 ;
for ( V_40 = V_15 -> V_83 ; V_40 <= 0x80 ; V_40 <<= 1 )
if ( V_40 > V_15 -> V_83 )
V_15 -> V_85 |= V_40 ;
for ( V_40 = 0 ; V_40 < 8 ; ++ V_40 )
V_15 -> V_16 [ V_40 ] = 0 ;
#ifdef F_34
F_1 () ;
#endif
#if F_46 ( F_32 )
V_15 -> V_86 = 0 ;
#endif
V_15 -> V_87 = 0 ;
V_15 -> V_76 = NULL ;
V_15 -> V_77 = NULL ;
V_15 -> V_78 = NULL ;
V_15 -> V_41 = V_88 ;
if ( ! V_89 ) {
V_89 = V_34 -> V_90 ;
V_91 = V_34 ;
}
#ifndef F_31
if ( ( V_34 -> V_92 > 1 ) || ( V_34 -> V_93 > 1 ) )
F_10 ( L_39
L_40
L_41 , V_55 ) ;
#endif
F_47 ( V_45 , V_94 ) ;
F_47 ( V_44 , V_95 ) ;
F_47 ( V_96 , 0 ) ;
F_47 ( V_97 , 0 ) ;
return 0 ;
}
static int F_48 ( struct V_10 * V_11 ,
void (* V_62)( struct V_10 * ) )
{
F_3 ( V_11 -> V_13 -> V_14 ) ;
struct V_10 * V_98 ;
unsigned long V_41 ;
#if ( V_23 & V_99 )
switch ( V_11 -> V_81 [ 0 ] ) {
case V_100 :
case V_101 :
F_10 ( V_21 L_42 ,
F_5 ( V_11 ) ) ;
V_11 -> V_102 = ( V_103 << 16 ) ;
V_62 ( V_11 ) ;
return 0 ;
}
#endif
#ifdef F_49
# if 0
if (!hostdata->connected && !hostdata->issue_queue &&
!hostdata->disconnected_queue) {
hostdata->timebase = jiffies;
}
# endif
# ifdef F_50
if ( F_18 ( V_11 ) > F_50 )
# endif
switch ( V_11 -> V_81 [ 0 ] )
{
case V_104 :
case V_100 :
case V_101 :
V_15 -> V_105 [ V_11 -> V_13 -> V_17 ] -= ( V_106 - V_15 -> V_107 ) ;
V_15 -> V_108 [ V_11 -> V_13 -> V_17 ] += F_18 ( V_11 ) ;
V_15 -> V_109 ++ ;
break;
case V_110 :
case V_111 :
case V_112 :
V_15 -> V_113 [ V_11 -> V_13 -> V_17 ] -= ( V_106 - V_15 -> V_107 ) ;
V_15 -> V_114 [ V_11 -> V_13 -> V_17 ] += F_18 ( V_11 ) ;
V_15 -> V_115 ++ ;
break;
}
#endif
F_43 ( V_11 ) = NULL ;
V_11 -> V_116 = V_62 ;
V_11 -> V_102 = 0 ;
F_22 ( V_41 ) ;
if ( ! ( V_15 -> V_77 ) || ( V_11 -> V_81 [ 0 ] == V_117 ) ) {
F_51 ( V_11 , V_15 -> V_77 ) ;
F_43 ( V_11 ) = V_15 -> V_77 ;
V_15 -> V_77 = V_11 ;
} else {
for ( V_98 = (struct V_10 * ) V_15 -> V_77 ;
F_43 ( V_98 ) ; V_98 = F_43 ( V_98 ) )
;
F_51 ( V_11 , V_98 ) ;
F_43 ( V_98 ) = V_11 ;
}
F_24 ( V_41 ) ;
F_52 ( L_43 , F_5 ( V_11 ) ,
( V_11 -> V_81 [ 0 ] == V_117 ) ? L_44 : L_45 ) ;
if ( F_53 () || ( ( V_41 >> 8 ) & 7 ) >= 6 )
F_26 () ;
else
F_54 ( NULL ) ;
return 0 ;
}
void F_55 ( struct V_33 * V_34 )
{
F_3 ( V_34 ) ;
int V_118 ;
unsigned char * * V_36 ;
volatile int * V_119 ;
if ( ! V_15 -> V_76 ) {
F_10 ( V_120 L_46
L_47 , V_55 ) ;
return;
}
F_56 ( L_48 ,
V_55 , F_23 ( V_46 ) ,
F_23 ( V_43 ) ) ;
if( ( F_57 ( F_58 ( V_15 -> V_76 -> V_121 ) ) ) ) {
F_10 ( L_49 , V_55 ) ;
F_10 ( L_50 ) ;
F_10 ( L_51 ) ;
F_59 () ;
}
if( ( F_23 ( V_46 ) & ( V_122 |
V_123 ) ) ==
( V_122 | V_123 ) ) {
F_10 ( L_52 , V_55 , F_23 ( V_46 ) ) ;
F_10 ( L_53
L_54 , V_55 ) ;
F_10 ( L_55 ) ;
F_10 ( L_50 ) ;
F_10 ( L_51 ) ;
F_59 () ;
}
( void ) F_23 ( V_124 ) ;
F_47 ( V_44 , V_95 ) ;
F_47 ( V_45 , V_94 ) ;
V_118 = V_15 -> V_86 - F_60 ( V_34 ) ;
V_15 -> V_86 = 0 ;
V_36 = ( unsigned char * * ) & ( V_15 -> V_76 -> V_26 . V_29 ) ;
V_119 = & ( V_15 -> V_76 -> V_26 . V_27 ) ;
* V_36 += V_118 ;
* V_119 -= V_118 ;
}
static T_5 F_61 ( int V_125 , void * V_126 )
{
struct V_33 * V_34 = V_91 ;
int V_62 = 1 , V_127 = 0 ;
unsigned char V_37 ;
F_62 ( L_56 , V_55 ) ;
V_37 = F_23 ( V_46 ) ;
F_62 ( L_57 , V_55 , V_37 ) ;
if ( V_37 & V_128 ) {
F_36 ( V_129 ) ;
if ( ( F_23 ( V_43 ) & ( V_130 | V_131 ) ) == ( V_130 | V_131 ) ) {
V_62 = 0 ;
F_62 ( L_58 , V_55 ) ;
F_63 ( V_34 ) ;
( void ) F_23 ( V_124 ) ;
}
else if ( V_37 & V_132 ) {
F_62 ( L_59 , V_55 ) ;
( void ) F_23 ( V_124 ) ;
}
else if ( ( F_23 ( V_43 ) & V_133 ) == V_133 ) {
F_62 ( L_60 , V_55 ) ;
( void ) F_23 ( V_124 ) ;
}
else {
#if F_46 ( F_32 )
if ( ( F_23 ( V_44 ) & V_134 ) &&
( ( V_37 & V_135 ) ||
! ( V_37 & V_122 ) ) ) {
F_62 ( L_61 , V_55 ) ;
F_55 ( V_34 ) ;
V_62 = 0 ;
} else
#endif
{
if ( V_37 & V_122 )
F_62 ( L_62
L_63 ,
V_55 , V_37 , F_23 ( V_44 ) ,
F_23 ( V_43 ) ) ;
( void ) F_23 ( V_124 ) ;
#ifdef F_64
V_136 -> V_137 |= V_138 ;
#endif
}
}
V_127 = 1 ;
}
else {
F_10 ( V_21 L_64
L_65 , V_55 , V_37 ,
F_23 ( V_44 ) , F_23 ( V_43 ) ) ;
( void ) F_23 ( V_124 ) ;
#ifdef F_64
V_136 -> V_137 |= V_138 ;
#endif
}
if ( ! V_62 ) {
F_62 ( L_66 , V_55 ) ;
F_26 () ;
}
return F_65 ( V_127 ) ;
}
static void F_66 ( struct V_73 * V_15 ,
struct V_10 * V_11 )
{
# ifdef F_50
if ( F_18 ( V_11 ) > F_50 )
# endif
switch ( V_11 -> V_81 [ 0 ] )
{
case V_104 :
case V_100 :
case V_101 :
V_15 -> V_105 [ V_11 -> V_13 -> V_17 ] += ( V_106 - V_15 -> V_107 ) ;
V_15 -> V_109 -- ;
break;
case V_110 :
case V_111 :
case V_112 :
V_15 -> V_113 [ V_11 -> V_13 -> V_17 ] += ( V_106 - V_15 -> V_107 ) ;
V_15 -> V_115 -- ;
break;
}
}
static int F_67 ( struct V_33 * V_34 , struct V_10 * V_11 ,
int V_19 )
{
F_3 ( V_34 ) ;
unsigned char V_98 [ 3 ] , V_139 ;
unsigned char * V_36 ;
int V_66 ;
unsigned long V_140 ;
unsigned long V_41 ;
V_15 -> V_141 = 0 ;
F_36 ( V_142 ) ;
F_68 ( L_67 , V_55 ,
V_34 -> V_84 ) ;
F_22 ( V_41 ) ;
if ( V_15 -> V_76 ) {
F_24 ( V_41 ) ;
return - 1 ;
}
F_47 ( V_96 , 0 ) ;
F_47 ( V_143 , V_15 -> V_83 ) ;
F_47 ( V_44 , V_144 ) ;
F_24 ( V_41 ) ;
#if V_145
{
unsigned long V_140 = V_106 + 2 * V_145 ;
while ( ! ( F_23 ( V_45 ) & V_146 )
&& F_69 ( V_106 , V_140 ) && ! V_15 -> V_76 )
;
if ( F_70 ( V_106 , V_140 ) )
{
F_10 ( L_68 , __LINE__ ) ;
F_47 ( V_44 , V_95 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
return - 1 ;
}
}
#else
while ( ! ( F_23 ( V_45 ) & V_146 )
&& ! V_15 -> V_76 ) ;
#endif
F_68 ( L_69 , V_55 ) ;
if ( V_15 -> V_76 ) {
F_47 ( V_44 , V_95 ) ;
return - 1 ;
}
F_71 ( 3 ) ;
if ( ( F_23 ( V_45 ) & V_147 ) ||
( F_23 ( V_42 ) & V_15 -> V_85 ) ||
( F_23 ( V_45 ) & V_147 ) ||
V_15 -> V_76 ) {
F_47 ( V_44 , V_95 ) ;
F_68 ( L_70 ,
V_55 ) ;
return - 1 ;
}
F_47 ( V_45 , V_94 | V_148 |
V_149 ) ;
if ( ( F_23 ( V_45 ) & V_147 ) ||
V_15 -> V_76 ) {
F_47 ( V_44 , V_95 ) ;
F_47 ( V_45 , V_94 ) ;
F_68 ( L_71 ,
V_55 ) ;
return - 1 ;
}
#ifdef F_72
F_71 ( 15 ) ;
#else
F_71 ( 2 ) ;
#endif
if ( V_15 -> V_76 ) {
F_47 ( V_44 , V_95 ) ;
F_47 ( V_45 , V_94 ) ;
return - 1 ;
}
F_68 ( L_72 , V_55 ) ;
F_47 ( V_143 , ( V_15 -> V_83 | ( 1 << V_11 -> V_13 -> V_17 ) ) ) ;
F_47 ( V_45 , ( V_94 | V_149 |
V_150 | V_151 | V_148 ) ) ;
F_47 ( V_44 , V_95 ) ;
if ( V_15 -> V_76 ) {
F_47 ( V_45 , V_94 ) ;
return - 1 ;
}
F_47 ( V_97 , 0 ) ;
F_71 ( 1 ) ;
F_47 ( V_45 , ( V_94 | V_150 |
V_151 | V_148 ) ) ;
F_71 ( 1 ) ;
F_73 ( L_73 , V_55 , V_11 -> V_13 -> V_17 ) ;
V_140 = V_106 + 25 ;
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
while ( F_69 ( V_106 , V_140 ) && ! ( F_23 ( V_43 ) & V_152 ) ) ;
#endif
F_71 ( 1 ) ;
F_47 ( V_45 , V_94 | V_151 ) ;
if ( ! ( F_23 ( V_43 ) & V_152 ) ) {
F_47 ( V_45 , V_94 ) ;
if ( V_15 -> V_87 & ( 1 << V_11 -> V_13 -> V_17 ) ) {
F_10 ( V_153 L_74 , V_55 ) ;
if ( V_15 -> V_141 )
F_10 ( V_21 L_75 ) ;
F_36 ( V_67 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
return - 1 ;
}
V_11 -> V_102 = V_154 << 16 ;
#ifdef F_49
F_66 ( V_15 , V_11 ) ;
#endif
#ifdef F_34
F_9 ( V_11 ) ;
#endif
V_11 -> V_116 ( V_11 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
F_73 ( L_76 , V_55 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
return 0 ;
}
V_15 -> V_87 |= ( 1 << V_11 -> V_13 -> V_17 ) ;
while ( ! ( F_23 ( V_43 ) & V_53 ) ) ;
F_73 ( L_77 ,
V_55 , V_11 -> V_13 -> V_17 ) ;
V_98 [ 0 ] = F_74 ( 1 , V_11 -> V_13 -> V_2 ) ;
#ifdef F_34
if ( V_11 -> V_19 != V_20 ) {
V_98 [ 1 ] = V_15 -> V_155 = V_156 ;
V_98 [ 2 ] = V_11 -> V_19 ;
V_66 = 3 ;
} else
V_66 = 1 ;
#else
V_66 = 1 ;
V_11 -> V_19 = 0 ;
#endif
V_36 = V_98 ;
V_139 = V_157 ;
F_75 ( V_34 , & V_139 , & V_66 , & V_36 ) ;
F_73 ( L_78 , V_55 ) ;
V_15 -> V_76 = V_11 ;
#ifndef F_34
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] |= ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
#ifdef F_64
V_136 -> V_137 |= V_158 ;
#endif
F_17 ( V_11 ) ;
return 0 ;
}
static int F_75 ( struct V_33 * V_34 ,
unsigned char * V_139 , int * V_119 ,
unsigned char * * V_36 )
{
register unsigned char V_159 = * V_139 , V_98 ;
register int V_160 = * V_119 ;
register unsigned char * V_161 = * V_36 ;
F_47 ( V_96 , F_76 ( V_159 ) ) ;
do {
while ( ! ( ( V_98 = F_23 ( V_43 ) ) & V_53 ) ) ;
F_77 ( L_79 , V_55 ) ;
if ( ( V_98 & V_59 ) != V_159 ) {
F_78 ( L_80 , V_55 ) ;
F_37 ( V_162 ) ;
break;
}
if ( ! ( V_159 & V_131 ) )
F_47 ( V_143 , * V_161 ) ;
else
* V_161 = F_23 ( V_42 ) ;
++ V_161 ;
if ( ! ( V_159 & V_131 ) ) {
if ( ! ( ( V_159 & V_163 ) && V_160 > 1 ) ) {
F_47 ( V_45 , V_94 |
V_150 ) ;
F_36 ( V_162 ) ;
F_47 ( V_45 , V_94 |
V_150 | V_164 ) ;
} else {
F_47 ( V_45 , V_94 |
V_150 | V_151 ) ;
F_36 ( V_162 ) ;
F_47 ( V_45 , V_94 |
V_150 | V_151 | V_164 ) ;
}
} else {
F_36 ( V_162 ) ;
F_47 ( V_45 , V_94 | V_164 ) ;
}
while ( F_23 ( V_43 ) & V_53 ) ;
F_77 ( L_81 , V_55 ) ;
if ( ! ( V_159 == V_165 && V_160 == 1 ) ) {
if ( V_159 == V_157 && V_160 > 1 )
F_47 ( V_45 , V_94 | V_151 ) ;
else
F_47 ( V_45 , V_94 ) ;
}
} while ( -- V_160 );
F_78 ( L_82 , V_55 , V_160 ) ;
* V_119 = V_160 ;
* V_36 = V_161 ;
V_98 = F_23 ( V_43 ) ;
if ( ( V_98 & V_53 ) || ( V_159 == V_165 && V_160 == 0 ) )
* V_139 = V_98 & V_59 ;
else
* V_139 = V_58 ;
if ( ! V_160 || ( * V_139 == V_159 ) )
return 0 ;
else
return - 1 ;
}
static int F_79 ( struct V_33 * V_14 )
{
unsigned char V_98 , * V_166 , V_139 ;
int V_66 ;
F_47 ( V_45 , V_94 | V_151 ) ;
while ( ! ( ( V_98 = F_23 ( V_43 ) ) & V_53 ) ) ;
F_47 ( V_96 , F_76 ( V_98 ) ) ;
if ( ( V_98 & V_59 ) != V_157 ) {
F_47 ( V_45 , V_94 | V_151 |
V_164 ) ;
while ( F_23 ( V_43 ) & V_53 ) ;
F_47 ( V_45 , V_94 | V_151 ) ;
}
V_98 = ABORT ;
V_166 = & V_98 ;
V_66 = 1 ;
V_139 = V_157 ;
F_75 ( V_14 , & V_139 , & V_66 , & V_166 ) ;
return V_66 ? - 1 : 0 ;
}
static int F_80 ( struct V_33 * V_34 ,
unsigned char * V_139 , int * V_119 ,
unsigned char * * V_36 )
{
F_3 ( V_34 ) ;
register int V_160 = * V_119 ;
register unsigned char V_159 = * V_139 ;
unsigned long V_41 ;
if( ! V_167 ) {
F_10 ( L_83 , V_55 ) ;
F_59 () ;
}
V_15 -> V_86 = V_160 ;
F_56 ( L_84 ,
V_55 , ( V_159 & V_131 ) ? L_85 : L_86 ,
V_160 , ( V_159 & V_131 ) ? L_87 : L_88 , * V_36 ) ;
F_22 ( V_41 ) ;
F_81 ( V_160 , * V_36 ) ;
if ( V_159 & V_131 ) {
F_47 ( V_96 , 1 ) ;
F_23 ( V_124 ) ;
F_47 ( V_45 , 0 ) ;
F_47 ( V_44 , ( F_23 ( V_44 ) | V_134 | V_168 ) ) ;
F_47 ( V_169 , 0 ) ;
} else {
F_47 ( V_96 , 0 ) ;
F_23 ( V_124 ) ;
F_47 ( V_45 , V_150 ) ;
F_47 ( V_44 , ( F_23 ( V_44 ) | V_134 | V_168 ) ) ;
F_47 ( V_170 , 0 ) ;
}
#ifdef F_64
V_136 -> V_137 |= V_138 ;
#endif
F_24 ( V_41 ) ;
V_171 = 1 ;
return 0 ;
}
static void F_82 ( struct V_33 * V_34 )
{
F_3 ( V_34 ) ;
unsigned long V_41 ;
unsigned char V_172 = V_173 ;
int V_174 = 0 ;
int V_66 ;
#if F_46 ( F_32 )
int V_175 ;
#endif
unsigned char * V_36 ;
unsigned char V_139 , V_98 , V_176 [ 10 ] , V_177 = 0xff ;
struct V_10 * V_11 = (struct V_10 * ) V_15 -> V_76 ;
#ifdef F_64
V_136 -> V_137 |= V_158 ;
#endif
while ( 1 ) {
V_98 = F_23 ( V_43 ) ;
if ( V_98 & V_53 ) {
V_139 = ( V_98 & V_59 ) ;
if ( V_139 != V_177 ) {
V_177 = V_139 ;
F_37 ( V_178 ) ;
}
if( V_139 == V_179 ) {
void * V_161 ;
unsigned long V_119 ;
if ( ! V_11 -> V_26 . V_27 && V_11 -> V_26 . V_30 ) {
V_119 = V_11 -> V_26 . V_31 -> V_32 ;
V_161 = F_15 ( V_11 -> V_26 . V_31 ) ;
} else {
V_119 = V_11 -> V_26 . V_27 ;
V_161 = V_11 -> V_26 . V_29 ;
}
#ifdef F_32
if( ( V_119 > V_180 ) && ( V_167
!= V_11 ) )
{
if ( V_11 -> V_121 -> V_181 == V_182 ) {
F_83 ( V_161 , V_119 ,
F_58 ( V_11 -> V_121 ) ) ;
V_167 = V_11 ;
}
}
#endif
#ifdef F_64
V_136 -> V_137 |= V_158 ;
#endif
}
if ( V_174 && ( V_139 != V_157 ) ) {
F_47 ( V_96 , F_76 ( V_98 ) ) ;
F_47 ( V_45 , V_94 | V_151 |
V_164 ) ;
while ( F_23 ( V_43 ) & V_53 ) ;
F_47 ( V_45 , V_94 |
V_151 ) ;
V_174 = 0 ;
continue;
}
switch ( V_139 ) {
case V_183 :
#if ( V_23 & V_184 )
F_10 ( L_89
L_90 , V_55 ) ;
V_174 = 1 ;
F_79 ( V_34 ) ;
V_11 -> V_102 = V_103 << 16 ;
V_11 -> V_116 ( V_11 ) ;
return;
#endif
case V_185 :
if ( ! V_11 -> V_26 . V_27 && V_11 -> V_26 . V_30 ) {
++ V_11 -> V_26 . V_31 ;
-- V_11 -> V_26 . V_30 ;
V_11 -> V_26 . V_27 = V_11 -> V_26 . V_31 -> V_32 ;
V_11 -> V_26 . V_29 = F_15 ( V_11 -> V_26 . V_31 ) ;
F_84 ( L_91 ,
V_55 , V_11 -> V_26 . V_27 ,
V_11 -> V_26 . V_30 ) ;
}
#if F_46 ( F_32 )
if( ( V_175 =
F_85 ( V_34 , V_11 , V_139 ) ) > V_180 ) {
V_66 = V_175 ;
V_11 -> V_26 . V_139 = V_139 ;
if ( F_80 ( V_34 , & V_139 ,
& V_66 , ( unsigned char * * ) & V_11 -> V_26 . V_29 ) ) {
F_10 ( V_21 L_92
L_93 , V_55 ,
V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
V_11 -> V_13 -> V_186 = 1 ;
F_47 ( V_45 , V_94 |
V_151 ) ;
V_174 = 1 ;
F_79 ( V_34 ) ;
V_11 -> V_102 = V_103 << 16 ;
V_11 -> V_116 ( V_11 ) ;
} else {
#ifdef F_32
return;
#else
V_11 -> V_26 . V_27 -= V_175 - V_66 ;
#endif
}
} else
#endif
F_75 ( V_34 , & V_139 ,
( int * ) & V_11 -> V_26 . V_27 , ( unsigned char * * )
& V_11 -> V_26 . V_29 ) ;
#ifdef F_32
if( V_167 == V_11 )
V_167 = NULL ;
#endif
break;
case V_165 :
V_66 = 1 ;
V_36 = & V_98 ;
F_47 ( V_97 , 0 ) ;
F_75 ( V_34 , & V_139 , & V_66 , & V_36 ) ;
V_11 -> V_26 . V_187 = V_98 ;
switch ( V_98 ) {
#ifdef F_86
case V_188 :
case V_189 :
F_47 ( V_45 , V_94 ) ;
F_87 ( L_94
L_95 , V_55 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
if ( ! V_11 -> V_190 ) {
F_10 ( V_21 L_96
L_97 ,
V_55 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
V_174 = 1 ;
F_79 ( V_34 ) ;
return;
}
F_17 ( V_11 -> V_190 ) ;
V_11 -> V_190 -> V_19 = V_11 -> V_19 ;
V_11 -> V_102 = V_11 -> V_26 . V_191 | ( V_11 -> V_26 . V_187 << 8 ) ;
F_87 ( L_98
L_99 ,
V_55 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
#ifdef F_49
F_66 ( V_15 , V_11 ) ;
#endif
V_11 -> V_116 ( V_11 ) ;
V_11 = V_15 -> V_76 ;
break;
#endif
case ABORT :
case V_192 :
F_47 ( V_45 , V_94 ) ;
V_15 -> V_76 = NULL ;
F_52 ( L_100
L_101 , V_55 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
#ifdef F_34
F_9 ( V_11 ) ;
if ( F_88 ( V_11 -> V_26 . V_191 ) == V_193 ) {
T_2 * V_3 = & V_5 [ V_11 -> V_13 -> V_17 ] [ V_11 -> V_13 -> V_2 ] ;
F_4 ( L_102
L_103 ,
V_55 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ,
V_3 -> V_8 ) ;
if ( V_3 -> V_9 > V_3 -> V_8 )
V_3 -> V_8 = V_3 -> V_9 ;
}
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
F_47 ( V_97 , V_15 -> V_83 ) ;
if ( V_11 -> V_81 [ 0 ] != V_117 )
V_11 -> V_102 = V_11 -> V_26 . V_191 | ( V_11 -> V_26 . V_187 << 8 ) ;
else if ( F_88 ( V_11 -> V_26 . V_191 ) != V_194 )
V_11 -> V_102 = ( V_11 -> V_102 & 0x00ffff ) | ( V_103 << 16 ) ;
#ifdef F_31
if ( ( V_11 -> V_81 [ 0 ] == V_117 ) &&
V_15 -> V_195 . V_196 ) {
F_89 ( V_11 , & V_15 -> V_195 ) ;
V_15 -> V_195 . V_196 = 0 ;
}
if ( ( V_11 -> V_81 [ 0 ] != V_117 ) &&
( F_88 ( V_11 -> V_26 . V_191 ) == V_197 ) ) {
F_90 ( V_11 , & V_15 -> V_195 , NULL , 0 , ~ 0 ) ;
F_91 ( L_104 ,
V_55 ) ;
F_22 ( V_41 ) ;
F_51 ( V_11 , V_15 -> V_77 ) ;
F_43 ( V_11 ) = V_15 -> V_77 ;
V_15 -> V_77 = (struct V_10 * ) V_11 ;
F_24 ( V_41 ) ;
F_52 ( L_105
L_106 , F_5 ( V_11 ) ) ;
} else
#endif
{
#ifdef F_49
F_66 ( V_15 , V_11 ) ;
#endif
V_11 -> V_116 ( V_11 ) ;
}
F_47 ( V_97 , V_15 -> V_83 ) ;
F_47 ( V_96 , 0 ) ;
while ( ( F_23 ( V_43 ) & V_152 ) && ! V_15 -> V_76 )
F_92 () ;
return;
case V_198 :
F_47 ( V_45 , V_94 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
switch ( V_15 -> V_155 ) {
case V_199 :
case V_200 :
case V_156 :
V_11 -> V_13 -> V_18 = 0 ;
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] |= ( 1 << V_11 -> V_13 -> V_2 ) ;
V_11 -> V_19 = V_20 ;
F_4 ( L_107
L_108
L_109 ,
V_55 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
break;
}
break;
case V_201 :
F_47 ( V_45 , V_94 ) ;
F_22 ( V_41 ) ;
V_11 -> V_13 -> V_202 = 1 ;
F_51 ( V_11 , V_15 -> V_78 ) ;
F_43 ( V_11 ) = V_15 -> V_78 ;
V_15 -> V_76 = NULL ;
V_15 -> V_78 = V_11 ;
F_24 ( V_41 ) ;
F_52 ( L_110
L_111
L_112 , V_55 ,
V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
F_47 ( V_96 , 0 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
while ( ( F_23 ( V_43 ) & V_152 ) && ! V_15 -> V_76 )
F_92 () ;
#ifdef F_64
V_136 -> V_137 |= V_138 ;
#endif
return;
case V_203 :
case V_204 :
F_47 ( V_45 , V_94 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
break;
case V_205 :
V_176 [ 0 ] = V_205 ;
F_47 ( V_45 , V_94 ) ;
F_93 ( L_113 , V_55 ) ;
V_66 = 2 ;
V_36 = V_176 + 1 ;
V_139 = V_165 ;
F_75 ( V_34 , & V_139 , & V_66 , & V_36 ) ;
F_93 ( L_114 , V_55 ,
( int ) V_176 [ 1 ] , ( int ) V_176 [ 2 ] ) ;
if ( ! V_66 && V_176 [ 1 ] <=
( sizeof ( V_176 ) - 1 ) ) {
F_47 ( V_45 , V_94 ) ;
V_66 = V_176 [ 1 ] - 1 ;
V_36 = V_176 + 3 ;
V_139 = V_165 ;
F_75 ( V_34 , & V_139 , & V_66 , & V_36 ) ;
F_93 ( L_115 ,
V_55 , V_66 ) ;
switch ( V_176 [ 2 ] ) {
case V_206 :
case V_207 :
case V_208 :
case V_209 :
V_98 = 0 ;
}
} else if ( V_66 ) {
F_10 ( V_21 L_116
L_117 , V_55 ) ;
V_98 = 0 ;
} else {
F_10 ( V_21 L_118
L_119 ,
V_55 , V_176 [ 2 ] , V_176 [ 1 ] ) ;
V_98 = 0 ;
}
default:
if ( ! V_98 ) {
F_10 ( V_54 L_120 , V_55 ) ;
F_94 ( V_176 ) ;
F_10 ( L_16 ) ;
} else if ( V_98 != V_205 )
F_10 ( V_54 L_121
L_122 ,
V_55 , V_98 , V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
else
F_10 ( V_54 L_121
L_123
L_124 ,
V_55 , V_176 [ 1 ] , V_176 [ 0 ] ,
V_11 -> V_13 -> V_17 , V_11 -> V_13 -> V_2 ) ;
V_172 = V_198 ;
F_47 ( V_45 , V_94 |
V_151 ) ;
break;
}
break;
case V_157 :
V_66 = 1 ;
V_36 = & V_172 ;
V_15 -> V_155 = V_172 ;
F_75 ( V_34 , & V_139 , & V_66 , & V_36 ) ;
if ( V_172 == ABORT ) {
#ifdef F_34
F_9 ( V_11 ) ;
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
V_15 -> V_76 = NULL ;
V_11 -> V_102 = V_103 << 16 ;
#ifdef F_49
F_66 ( V_15 , V_11 ) ;
#endif
V_11 -> V_116 ( V_11 ) ;
F_47 ( V_97 , V_15 -> V_83 ) ;
return;
}
V_172 = V_173 ;
break;
case V_179 :
V_66 = V_11 -> V_196 ;
V_36 = V_11 -> V_81 ;
F_75 ( V_34 , & V_139 , & V_66 ,
& V_36 ) ;
break;
case V_210 :
V_66 = 1 ;
V_36 = & V_98 ;
F_75 ( V_34 , & V_139 , & V_66 , & V_36 ) ;
V_11 -> V_26 . V_191 = V_98 ;
break;
default:
F_10 ( L_125 , V_55 ) ;
F_36 ( V_67 ) ;
}
}
}
}
static void F_63 ( struct V_33 * V_34 )
{
F_3 ( V_34 ) ;
unsigned char V_211 ;
unsigned char V_2 ;
#ifdef F_34
unsigned char V_19 ;
#endif
unsigned char V_212 [ 3 ] ;
struct V_10 * V_98 = NULL , * V_213 ;
F_47 ( V_44 , V_95 ) ;
V_15 -> V_141 = 1 ;
V_211 = F_23 ( V_42 ) & ~ ( V_15 -> V_83 ) ;
F_95 ( L_126 , V_55 ) ;
F_47 ( V_45 , V_94 | V_149 ) ;
while ( F_23 ( V_43 ) & V_130 ) ;
F_47 ( V_45 , V_94 ) ;
while ( ! ( F_23 ( V_43 ) & V_53 ) ) ;
#if 1
F_47 ( V_96 , F_76 ( V_165 ) ) ;
V_212 [ 0 ] = F_23 ( V_42 ) ;
#endif
if ( ! ( V_212 [ 0 ] & 0x80 ) ) {
F_10 ( V_54 L_127 , V_55 ) ;
F_94 ( V_212 ) ;
F_79 ( V_34 ) ;
return;
}
V_2 = ( V_212 [ 0 ] & 0x07 ) ;
for ( V_98 = (struct V_10 * ) V_15 -> V_78 , V_213 = NULL ;
V_98 ; V_213 = V_98 , V_98 = F_43 ( V_98 ) ) {
if ( ( V_211 == ( 1 << V_98 -> V_13 -> V_17 ) ) && ( V_2 == V_98 -> V_13 -> V_2 )
#ifdef F_34
&& ( V_19 == V_98 -> V_19 )
#endif
) {
if ( V_213 ) {
REMOVE ( V_213 , F_43 ( V_213 ) , V_98 , F_43 ( V_98 ) ) ;
F_43 ( V_213 ) = F_43 ( V_98 ) ;
} else {
REMOVE ( - 1 , V_15 -> V_78 , V_98 , F_43 ( V_98 ) ) ;
V_15 -> V_78 = F_43 ( V_98 ) ;
}
F_43 ( V_98 ) = NULL ;
break;
}
}
if ( ! V_98 ) {
F_10 ( V_120 L_128
#ifdef F_34
L_129
#endif
L_130 ,
V_55 , V_211 , V_2
#ifdef F_34
, V_19
#endif
) ;
F_79 ( V_34 ) ;
return;
}
#if 1
{
void * V_161 ;
unsigned long V_119 ;
if ( ! V_98 -> V_26 . V_27 && V_98 -> V_26 . V_30 ) {
V_119 = V_98 -> V_26 . V_31 -> V_32 ;
V_161 = F_15 ( V_98 -> V_26 . V_31 ) ;
} else {
V_119 = V_98 -> V_26 . V_27 ;
V_161 = V_98 -> V_26 . V_29 ;
}
#ifdef F_32
if( ( V_119 > V_180 ) && ( V_167 != V_98 ) )
{
F_83 ( V_161 , V_119 , F_58 ( V_98 -> V_121 ) ) ;
V_167 = V_98 ;
}
#endif
}
#endif
F_47 ( V_45 , V_94 | V_164 ) ;
F_47 ( V_45 , V_94 ) ;
#ifdef F_34
V_19 = V_20 ;
if ( V_139 == V_165 && V_4 ) {
F_47 ( V_45 , V_94 ) ;
V_66 = 2 ;
V_36 = V_212 + 1 ;
if ( ! F_75 ( V_34 , & V_139 , & V_66 , & V_36 ) &&
V_212 [ 1 ] == V_156 )
V_19 = V_212 [ 2 ] ;
F_4 ( L_131
L_132 , V_55 , V_211 , V_2 , V_19 ) ;
}
#endif
V_15 -> V_76 = V_98 ;
F_95 ( L_133 ,
V_55 , V_98 -> V_1 , V_98 -> V_2 , V_98 -> V_19 ) ;
}
static int F_96 ( struct V_10 * V_11 )
{
struct V_33 * V_34 = V_11 -> V_13 -> V_14 ;
F_3 ( V_34 ) ;
struct V_10 * V_98 , * * V_213 ;
unsigned long V_41 ;
F_10 ( V_21 L_134 , V_55 ) ;
F_97 ( V_11 ) ;
F_35 ( V_34 ) ;
F_22 ( V_41 ) ;
F_98 ( L_135 , V_55 ,
F_23 ( V_46 ) ,
F_23 ( V_43 ) ) ;
#if 1
if ( V_15 -> V_76 == V_11 ) {
F_98 ( L_136 , V_55 ) ;
if ( F_79 ( V_34 ) == 0 ) {
V_15 -> V_82 = 1 ;
V_15 -> V_76 = NULL ;
V_11 -> V_102 = V_214 << 16 ;
#ifdef F_34
F_9 ( V_11 ) ;
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
F_24 ( V_41 ) ;
V_11 -> V_116 ( V_11 ) ;
return V_215 ;
} else {
F_10 ( L_137 , V_55 ) ;
return V_216 ;
}
}
#endif
for ( V_213 = (struct V_10 * * ) & ( V_15 -> V_77 ) ,
V_98 = (struct V_10 * ) V_15 -> V_77 ;
V_98 ; V_213 = F_99 ( V_98 ) , V_98 = F_43 ( V_98 ) )
if ( V_11 == V_98 ) {
REMOVE ( 5 , * V_213 , V_98 , F_43 ( V_98 ) ) ;
( * V_213 ) = F_43 ( V_98 ) ;
F_43 ( V_98 ) = NULL ;
V_98 -> V_102 = V_214 << 16 ;
F_24 ( V_41 ) ;
F_98 ( L_138 ,
V_55 ) ;
V_98 -> V_116 ( V_98 ) ;
return V_215 ;
}
if ( V_15 -> V_76 ) {
F_24 ( V_41 ) ;
F_98 ( L_139 , V_55 ) ;
return V_217 ;
}
for ( V_98 = (struct V_10 * ) V_15 -> V_78 ; V_98 ;
V_98 = F_43 ( V_98 ) )
if ( V_11 == V_98 ) {
F_24 ( V_41 ) ;
F_98 ( L_140 , V_55 ) ;
if ( F_67 ( V_34 , V_11 , ( int ) V_11 -> V_19 ) )
return V_218 ;
F_98 ( L_141 , V_55 ) ;
F_79 ( V_34 ) ;
F_22 ( V_41 ) ;
for ( V_213 = (struct V_10 * * ) & ( V_15 -> V_78 ) ,
V_98 = (struct V_10 * ) V_15 -> V_78 ;
V_98 ; V_213 = F_99 ( V_98 ) , V_98 = F_43 ( V_98 ) )
if ( V_11 == V_98 ) {
REMOVE ( 5 , * V_213 , V_98 , F_43 ( V_98 ) ) ;
* V_213 = F_43 ( V_98 ) ;
F_43 ( V_98 ) = NULL ;
V_98 -> V_102 = V_214 << 16 ;
#ifdef F_34
F_9 ( V_98 ) ;
#else
V_15 -> V_16 [ V_11 -> V_13 -> V_17 ] &= ~ ( 1 << V_11 -> V_13 -> V_2 ) ;
#endif
F_24 ( V_41 ) ;
V_98 -> V_116 ( V_98 ) ;
return V_215 ;
}
}
F_24 ( V_41 ) ;
F_10 ( V_219 L_142 , V_55 ) ;
return V_220 ;
}
static int F_100 ( struct V_10 * V_11 )
{
F_3 ( V_11 -> V_13 -> V_14 ) ;
int V_40 ;
unsigned long V_41 ;
#if 1
struct V_10 * V_76 , * V_78 ;
#endif
F_35 ( V_11 -> V_13 -> V_14 ) ;
F_47 ( V_96 ,
F_76 ( F_23 ( V_43 ) ) ) ;
F_47 ( V_45 , V_94 | V_221 ) ;
F_71 ( 40 ) ;
F_47 ( V_45 , V_94 ) ;
F_47 ( V_44 , V_95 ) ;
F_47 ( V_96 , 0 ) ;
F_47 ( V_97 , 0 ) ;
( void ) F_23 ( V_124 ) ;
#if 1
F_22 ( V_41 ) ;
V_76 = (struct V_10 * ) V_15 -> V_76 ;
V_15 -> V_76 = NULL ;
V_78 = (struct V_10 * ) V_15 -> V_78 ;
V_15 -> V_78 = NULL ;
#ifdef F_34
F_12 () ;
#endif
for( V_40 = 0 ; V_40 < 8 ; ++ V_40 )
V_15 -> V_16 [ V_40 ] = 0 ;
#ifdef F_32
V_15 -> V_86 = 0 ;
#endif
F_24 ( V_41 ) ;
if ( ( V_11 = V_76 ) ) {
F_98 ( L_143 , F_5 ( V_11 ) ) ;
V_11 -> V_102 = ( V_11 -> V_102 & 0xffff ) | ( V_222 << 16 ) ;
V_11 -> V_116 ( V_11 ) ;
}
for ( V_40 = 0 ; ( V_11 = V_78 ) ; ++ V_40 ) {
V_78 = F_43 ( V_11 ) ;
F_43 ( V_11 ) = NULL ;
V_11 -> V_102 = ( V_11 -> V_102 & 0xffff ) | ( V_222 << 16 ) ;
V_11 -> V_116 ( V_11 ) ;
}
if ( V_40 > 0 )
F_98 ( L_144 , V_40 ) ;
return V_223 | V_224 ;
#else
if ( V_15 -> V_77 )
F_98 ( L_145 , F_5 ( V_11 ) ) ;
if ( V_15 -> V_76 )
F_98 ( L_143 , F_5 ( V_11 ) ) ;
if ( V_15 -> V_78 )
F_98 ( L_146 , F_5 ( V_11 ) ) ;
F_22 ( V_41 ) ;
V_15 -> V_77 = NULL ;
V_15 -> V_76 = NULL ;
V_15 -> V_78 = NULL ;
#ifdef F_34
F_12 () ;
#endif
for( V_40 = 0 ; V_40 < 8 ; ++ V_40 )
V_15 -> V_16 [ V_40 ] = 0 ;
#ifdef F_32
V_15 -> V_86 = 0 ;
#endif
F_24 ( V_41 ) ;
return V_225 | V_224 ;
#endif
}
