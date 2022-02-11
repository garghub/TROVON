static void F_1 ( void )
{
int V_1 = 1000000 ;
while ( -- V_1 > 0 ) {
if ( ! ( F_2 ( V_2 + V_3 ) & V_4 ) )
break;
F_3 ( 1 ) ;
}
if ( V_1 <= 0 )
F_4 (KERN_INFO PFX L_1 ) ;
}
static void F_5 ( void )
{
int V_1 = 1000000 ;
while ( -- V_1 > 0 ) {
if ( F_2 ( V_2 + V_3 ) & V_5 )
break;
F_3 ( 1 ) ;
}
if ( V_1 <= 0 )
F_4 (KERN_INFO PFX L_2 ) ;
}
static int F_6 ( unsigned char V_6 )
{
F_5 () ;
F_7 ( V_6 + 1 , V_2 + V_7 ) ;
F_5 () ;
F_7 ( V_8 , V_2 + V_3 ) ;
F_1 () ;
if ( ! ( F_2 ( V_2 + V_3 ) & V_9 ) ) {
return F_2 ( V_2 + V_7 ) ;
} else {
F_7 ( V_10 , V_2 + V_3 ) ;
return 0 ;
}
}
static void F_8 ( unsigned char V_6 )
{
F_5 () ;
F_7 ( V_6 , V_2 + V_7 ) ;
F_7 ( V_8 , V_2 + V_3 ) ;
}
static unsigned char F_9 ( void )
{
F_1 () ;
F_7 ( V_11 , V_2 + V_3 ) ;
return F_2 ( V_2 + V_7 ) ;
}
static void F_10 ( unsigned char V_12 )
{
F_1 () ;
F_7 ( V_12 , V_2 + V_7 ) ;
}
static void F_11 ( void )
{
F_1 () ;
F_7 ( V_10 , V_2 + V_3 ) ;
}
static unsigned char F_12 ( unsigned char V_6 , unsigned char V_12 )
{
F_8 ( V_6 ) ;
F_10 ( V_12 ) ;
F_11 () ;
F_6 ( V_6 ) ;
F_9 () ;
F_11 () ;
return F_2 ( V_2 + V_7 ) ;
}
static unsigned char F_13 ( unsigned char V_6 )
{
unsigned char V_13 ;
F_6 ( V_6 ) ;
V_13 = F_9 () ;
F_11 () ;
return V_13 ;
}
static int F_14 ( unsigned char V_14 , int V_15 ,
int V_16 , char * V_17 , char * V_18 )
{
int V_19 = 0 ;
switch ( V_15 ) {
case V_20 :
V_19 = 1 ;
V_18 [ 0 ] = V_14 ;
break;
case V_21 :
V_19 = 1 ;
V_18 [ 0 ] = V_17 [ V_14 ] ;
break;
case V_22 :
sprintf ( V_18 , L_3 , ( V_17 [ V_14 ] * 10 ) / ( V_16 ) ) ;
V_19 = strlen ( V_18 ) ;
V_18 [ V_19 - 1 ] = V_18 [ V_19 - 2 ] ;
V_18 [ V_19 - 2 ] = '.' ;
break;
default:
break;
} ;
return V_19 ;
}
static int F_15 ( int V_23 , struct V_24 * V_25 ,
char V_26 , unsigned char * V_18 )
{
unsigned char V_14 ;
int V_27 ;
char * V_17 , V_28 = - 1 ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( V_25 -> V_26 [ V_27 ] == V_26 ) {
if ( ++ V_28 == V_23 ) {
break;
}
}
}
if ( V_28 != V_23 )
return 0 ;
V_14 = F_12 ( ( unsigned char ) V_25 -> V_6 ,
( unsigned char ) V_25 -> V_30 [ V_27 ] . V_31 ) ;
V_17 = V_25 -> V_32 + V_25 -> V_33 [ V_27 ] . V_34 ;
return F_14 ( V_14 , V_25 -> V_33 [ V_27 ] . type ,
V_25 -> V_33 [ V_27 ] . V_16 ,
V_17 , V_18 ) ;
}
static int F_16 ( struct V_24 * V_25 ,
char V_26 , unsigned char * V_18 )
{
unsigned char V_14 ;
int V_27 ;
char * V_17 = NULL ;
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( V_25 -> V_26 [ V_27 ] == V_26 )
break;
}
if ( V_27 >= V_29 )
return 0 ;
V_14 = F_12 ( ( unsigned char ) V_25 -> V_6 ,
( unsigned char ) V_25 -> V_30 [ V_27 ] . V_31 ) ;
V_17 = V_25 -> V_32 + V_25 -> V_33 [ V_27 ] . V_34 ;
return F_14 ( V_14 , V_25 -> V_33 [ V_27 ] . type ,
V_25 -> V_33 [ V_27 ] . V_16 ,
V_17 , V_18 ) ;
}
static int F_17 ( struct V_24 * V_25 ,
unsigned char V_14 ,
char * V_18 )
{
unsigned char V_35 , V_36 = 0 ;
int V_27 , V_28 = 0 ;
V_35 = V_14 & V_25 -> V_37 ;
if ( V_35 == V_25 -> V_37 ) {
V_36 = V_38 ;
} else if ( V_35 == 0 ) {
V_36 = V_39 ;
} else {
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( V_25 -> V_37 & V_40 [ V_27 ] ) {
if ( ! ( V_40 [ V_27 ] & V_35 ) )
V_36 |= V_40 [ V_28 ] ;
V_28 ++ ;
}
}
}
V_18 [ 0 ] = V_36 ;
return 1 ;
}
static int F_18 ( struct V_24 * V_25 ,
unsigned char V_14 ,
char * V_18 )
{
V_18 [ 0 ] = ( V_14 & V_41 ) ;
return 1 ;
}
static unsigned char F_19 ( struct V_24 * V_25 ,
unsigned char V_14 ,
char * V_18 )
{
unsigned char V_35 , V_36 = 0 ;
int V_27 , V_28 = 0 ;
V_35 = V_14 & V_25 -> V_42 ;
if ( V_35 == V_25 -> V_42 ) {
V_36 = V_43 ;
} else if ( V_35 == 0 ) {
V_36 = V_44 ;
} else {
for ( V_27 = 0 ; V_27 < V_29 ; V_27 ++ ) {
if ( V_25 -> V_42 & V_40 [ V_27 ] ) {
V_28 ++ ;
if ( ! ( V_40 [ V_27 ] & V_35 ) )
break;
}
}
if ( V_28 == 1 )
V_36 = V_45 ;
else
V_36 = V_46 ;
}
V_18 [ 0 ] = V_36 ;
return 1 ;
}
static T_1
F_20 ( struct V_47 * V_47 , char T_2 * V_48 , T_3 V_49 , T_4 * V_50 )
{
struct V_24 * V_25 ;
unsigned char V_14 [ 10 ] ;
int V_36 = 0 ;
switch ( ( int ) ( long ) V_47 -> V_51 ) {
case V_52 :
if ( V_53 == 0 )
return 0 ;
V_14 [ 0 ] = ( unsigned char ) ( V_53 ) ;
V_36 = 1 ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_55 :
if ( V_56 == 0 )
return 0 ;
V_14 [ 0 ] = ( unsigned char ) ( V_56 ) ;
V_36 = 1 ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_57 :
if ( ! ( V_25 = F_22 ( V_58 ) ) )
return 0 ;
V_36 = F_16 ( V_25 , V_58 , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_59 :
if ( ! ( V_25 = F_22 ( V_60 ) ) )
return 0 ;
V_36 = F_15 ( V_61 , V_25 , V_60 , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_62 :
if ( ! ( V_25 = F_22 ( V_63 ) ) )
return 0 ;
V_36 = F_15 ( V_61 , V_25 , V_63 , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_64 :
if ( ! ( V_25 = F_22 ( V_65 ) ) )
return 0 ;
V_36 = F_16 ( V_25 , V_65 , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_66 :
if ( ! ( V_25 = F_22 ( V_67 ) ) )
return 0 ;
V_36 = F_16 ( V_25 , V_67 , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_68 :
if ( ! ( V_25 = F_22 ( V_69 ) ) )
return 0 ;
V_14 [ 0 ] = F_13 ( V_25 -> V_6 ) ;
V_36 = F_17 ( V_25 , V_14 [ 0 ] , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_70 :
if ( ! ( V_25 = F_22 ( V_71 ) ) )
return 0 ;
V_14 [ 0 ] = F_13 ( V_25 -> V_6 ) ;
V_36 = F_18 ( V_25 , V_14 [ 0 ] , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
case V_72 :
if ( ! ( V_25 = F_22 ( V_73 ) ) )
if ( ! ( V_25 = F_22 ( V_71 ) ) )
return 0 ;
V_14 [ 0 ] = F_13 ( V_25 -> V_6 ) ;
V_36 = F_19 ( V_25 , V_14 [ 0 ] , V_14 ) ;
if ( F_21 ( V_48 , V_14 , V_36 ) )
V_36 = - V_54 ;
break;
default:
break;
} ;
return V_36 ;
}
static long
F_23 ( struct V_47 * V_47 , unsigned int V_74 , unsigned long V_75 )
{
char T_2 * V_76 ;
switch ( V_74 ) {
case V_52 :
case V_55 :
case V_57 :
case V_68 :
case V_72 :
case V_66 :
case V_64 :
case V_70 :
V_47 -> V_51 = ( void * ) ( long ) V_74 ;
break;
case V_59 :
case V_62 :
V_76 = ( char T_2 * ) V_75 ;
if ( V_76 == NULL ) {
V_61 = 0 ;
} else {
F_24 ( V_61 , V_76 ) ;
}
V_47 -> V_51 = ( void * ) ( long ) V_74 ;
break;
default:
return - V_77 ;
} ;
return 0 ;
}
static int
F_25 ( struct V_78 * V_78 , struct V_47 * V_47 )
{
V_47 -> V_51 = NULL ;
return 0 ;
}
static int
F_26 ( struct V_78 * V_78 , struct V_47 * V_47 )
{
return 0 ;
}
static void F_27 ( struct V_24 * V_25 ,
const char * V_79 ,
int V_31 )
{
if ( ! ( strcmp ( V_79 , L_4 ) ) ||
! ( strcmp ( V_79 , L_5 ) ) ||
! ( strcmp ( V_79 , L_6 ) ) ||
! ( strcmp ( V_79 , L_7 ) ) ||
! ( strcmp ( V_79 , L_8 ) ) )
V_25 -> V_26 [ V_31 ] = V_60 ;
if ( ! ( strcmp ( V_79 , L_9 ) ) ||
! ( strcmp ( V_79 , L_10 ) ) ||
! ( strcmp ( V_79 , L_11 ) ) ||
! ( strcmp ( V_79 , L_12 ) ) )
V_25 -> V_26 [ V_31 ] = V_63 ;
if ( ! ( strcmp ( V_79 , L_13 ) ) )
V_25 -> V_26 [ V_31 ] = V_58 ;
if ( ! ( strcmp ( V_79 , L_14 ) ) )
V_25 -> V_26 [ V_31 ] = V_65 ;
if ( ! ( strcmp ( V_79 , L_15 ) ) )
V_25 -> V_26 [ V_31 ] = V_67 ;
}
static void F_28 ( struct V_24 * V_25 , struct V_80 * V_81 )
{
int V_27 = 0 , V_19 ;
const char * V_82 ;
const unsigned int * V_83 ;
V_82 = F_29 ( V_81 , L_16 , & V_19 ) ;
while ( V_19 > 0 ) {
int V_84 = strlen ( V_82 ) + 1 ;
F_27 ( V_25 , V_82 , V_27 ++ ) ;
V_19 -= V_84 ;
V_82 += V_84 ;
}
V_83 = F_29 ( V_81 , L_17 , NULL ) ;
if ( V_83 )
V_53 = * V_83 ;
V_83 = F_29 ( V_81 , L_18 , NULL ) ;
if ( V_83 )
V_56 = * V_83 ;
}
static void F_30 ( struct V_24 * V_25 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_85 ; V_27 ++ )
V_25 -> V_37 |= V_40 [ ( V_25 -> V_30 [ V_27 ] ) . V_31 ] ;
V_25 -> V_26 [ 0 ] = V_69 ;
}
static void F_31 ( struct V_24 * V_25 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_85 ; V_27 ++ ) {
if ( V_86 == V_25 -> V_30 [ V_27 ] . type ) {
V_25 -> V_42 |= V_40 [ V_27 ] ;
}
}
V_25 -> V_26 [ 0 ] = V_71 ;
}
static void F_32 ( struct V_24 * V_25 )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_25 -> V_85 ; V_27 ++ )
V_25 -> V_42 |= V_40 [ ( V_25 -> V_30 [ V_27 ] ) . V_31 ] ;
V_25 -> V_26 [ 0 ] = V_73 ;
}
static void F_33 ( struct V_80 * V_81 ,
struct V_24 * V_25 )
{
int V_19 , V_27 , V_87 = 0 ;
const void * V_83 ;
V_83 = F_29 ( V_81 , L_19 , & V_19 ) ;
memcpy ( & V_25 -> V_6 , V_83 , V_19 ) ;
V_83 = F_29 ( V_81 , L_20 , & V_19 ) ;
if ( V_83 && V_19 > 0 ) {
memcpy ( V_25 -> V_33 , V_83 , V_19 ) ;
V_25 -> V_88 = V_19 / sizeof( struct V_89 ) ;
for ( V_27 = 0 ; V_27 < V_25 -> V_88 ; V_27 ++ ) {
if ( ( V_25 -> V_33 [ V_27 ] . V_90 + V_25 -> V_33 [ V_27 ] . V_34 ) > V_87 ) {
V_87 = V_25 -> V_33 [ V_27 ] . V_90 + V_25 -> V_33 [ V_27 ] . V_34 ;
}
}
V_25 -> V_32 = F_34 ( V_87 , V_91 ) ;
if ( V_25 -> V_32 == NULL ) {
F_4 (KERN_ERR PFX L_21 ) ;
return;
}
V_83 = F_29 ( V_81 , L_22 , & V_19 ) ;
if ( ! V_83 || V_19 <= 0 ) {
F_4 (KERN_ERR PFX L_23 ) ;
return;
}
memcpy ( V_25 -> V_32 , V_83 , V_19 ) ;
}
if ( V_92 == V_25 -> V_6 ) {
struct V_80 * V_93 ;
int V_19 ;
V_93 = F_35 ( L_24 ) ;
if ( ! strcmp ( V_93 -> V_94 , L_25 ) ) {
for ( V_19 = 0 ; V_19 < V_29 ; ++ V_19 ) {
V_25 -> V_26 [ V_19 ] = V_95 ;
}
return;
}
}
V_83 = F_29 ( V_81 , L_26 , & V_19 ) ;
memcpy ( V_25 -> V_30 , V_83 , V_19 ) ;
V_25 -> V_85 = V_19 / sizeof( struct V_96 ) ;
for ( V_27 = 0 ; V_27 < V_25 -> V_85 ; V_27 ++ ) {
switch ( V_25 -> V_30 [ V_27 ] . type ) {
case V_97 :
F_28 ( V_25 , V_81 ) ;
break;
case V_98 :
F_31 ( V_25 ) ;
V_27 = V_25 -> V_85 ;
break;
case V_99 :
F_30 ( V_25 ) ;
V_27 = V_25 -> V_85 ;
break;
case V_86 :
if ( V_25 -> V_100 == V_101 ) {
F_28 ( V_25 , V_81 ) ;
} else {
F_32 ( V_25 ) ;
}
V_27 = V_25 -> V_85 ;
break;
default:
break;
} ;
}
}
static struct V_24 * F_22 ( unsigned char V_26 )
{
int V_27 , V_28 ;
for ( V_27 = 0 ; V_27 < V_102 * 2 ; V_27 ++ ) {
for ( V_28 = 0 ; V_28 < V_29 ; V_28 ++ ) {
if ( V_103 [ V_27 ] . V_26 [ V_28 ] == V_26 ) {
return (struct V_24 * ) ( & ( V_103 [ V_27 ] ) ) ;
}
}
}
return NULL ;
}
static void F_36 ( void )
{
static int V_104 = 0 ;
int V_36 ;
if ( V_104 != 0 )
return;
V_104 = 1 ;
F_4 ( V_105 L_27 ) ;
V_36 = F_37 ( true ) ;
if ( V_36 < 0 ) {
F_4 ( V_105 L_28 ) ;
V_104 = 0 ;
}
}
static int F_38 ( void * V_106 )
{
int V_107 ;
int V_108 ;
char V_109 [ 10 ] ;
struct V_24 * V_110 ;
if ( NULL == ( V_110 = F_22 ( V_60 ) ) ) {
F_4 (KERN_ERR PFX
L_29 ) ;
return - V_111 ;
}
V_107 = 5000 ;
F_4 (KERN_INFO PFX L_30 , current->comm) ;
for (; ; ) {
F_39 ( V_107 ) ;
if ( F_40 () )
break;
for ( V_108 = 0 ; V_108 < V_102 ; ++ V_108 ) {
if ( 0 < F_15 ( V_108 , V_110 ,
V_60 ,
V_109 ) ) {
if ( V_109 [ 0 ] >= V_56 ) {
F_4 ( V_105
L_31\
L_32 ,
V_112 -> V_113 , V_108 ,
V_109 [ 0 ] , V_56 ) ;
F_36 () ;
}
}
}
}
F_4 (KERN_INFO PFX L_33 , current->comm) ;
return 0 ;
}
static int T_5 F_41 ( struct V_114 * V_115 )
{
struct V_80 * V_81 ;
int V_116 , V_117 ;
if ( V_2 )
return - V_77 ;
V_2 = F_42 ( & V_115 -> V_118 [ 0 ] , 0 , 0x2 , V_119 ) ;
if ( ! V_2 )
return - V_120 ;
V_116 = 0 ;
V_81 = V_115 -> V_121 . V_122 -> V_123 ;
while ( V_81 ) {
if ( ! strcmp ( V_81 -> V_94 , L_34 ) ) {
V_103 [ V_116 ] . V_100 = V_124 ;
F_33 ( V_81 , & ( V_103 [ V_116 ++ ] ) ) ;
} else if ( ! strcmp ( V_81 -> V_94 , L_35 ) ) {
V_103 [ V_116 ] . V_100 = V_101 ;
F_33 ( V_81 , & ( V_103 [ V_116 ++ ] ) ) ;
}
V_81 = V_81 -> V_125 ;
}
F_7 ( V_126 , V_2 + V_3 ) ;
F_7 ( V_127 , V_2 + V_7 ) ;
F_7 ( V_126 | V_128 , V_2 + V_3 ) ;
F_7 ( V_129 | V_130 , V_2 + V_7 ) ;
F_7 ( V_126 | V_11 | V_131 , V_2 + V_3 ) ;
F_3 ( 200 ) ;
V_117 = F_43 ( & V_132 ) ;
if ( V_117 ) {
F_4 (KERN_ERR PFX L_36 ,
envctrl_dev.minor) ;
goto V_133;
}
F_4 (KERN_INFO PFX L_37 ) ;
for ( -- V_116 ; V_116 >= 0 ; -- V_116 ) {
F_4 ( L_38 ,
( V_101 == V_103 [ V_116 ] . V_100 ) ? L_35 :
( ( V_124 == V_103 [ V_116 ] . V_100 ) ? L_34 : L_39 ) ,
V_103 [ V_116 ] . V_6 , ( 0 == V_116 ) ? L_40 : L_41 ) ;
}
V_134 = F_44 ( F_38 , NULL , L_42 ) ;
if ( F_45 ( V_134 ) ) {
V_117 = F_46 ( V_134 ) ;
goto V_135;
}
return 0 ;
V_135:
F_47 ( & V_132 ) ;
V_133:
F_48 ( & V_115 -> V_118 [ 0 ] , V_2 , 0x2 ) ;
for ( V_116 = 0 ; V_116 < V_102 * 2 ; V_116 ++ )
F_49 ( V_103 [ V_116 ] . V_32 ) ;
return V_117 ;
}
static int T_6 F_50 ( struct V_114 * V_115 )
{
int V_116 ;
F_51 ( V_134 ) ;
F_48 ( & V_115 -> V_118 [ 0 ] , V_2 , 0x2 ) ;
F_47 ( & V_132 ) ;
for ( V_116 = 0 ; V_116 < V_102 * 2 ; V_116 ++ )
F_49 ( V_103 [ V_116 ] . V_32 ) ;
return 0 ;
}
