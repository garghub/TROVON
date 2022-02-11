static void
F_1 ( void )
{
if ( ! V_1 )
F_2 ( V_2 , V_3 . V_4 ) ;
else
free ( V_2 ) ;
V_2 = NULL ;
free ( V_5 ) ;
V_5 = NULL ;
V_6 = 0 ;
V_7 = 0 ;
}
static T_1
F_3 ( int const V_8 , T_1 const V_9 , int const V_10 )
{
switch ( V_10 ) {
case V_11 :
V_12 = V_2 + V_9 ;
break;
case V_13 :
V_12 += V_9 ;
break;
case V_14 :
V_12 = V_2 + ( V_3 . V_4 - V_9 ) ;
break;
}
if ( V_12 < V_2 ) {
fprintf ( V_15 , L_1 ) ;
F_4 () ;
}
return V_12 - V_2 ;
}
static T_2
F_5 ( int const V_8 , void * const V_16 , T_2 const V_17 )
{
T_2 const V_18 = F_6 ( V_8 , V_16 , V_17 ) ;
if ( V_18 != V_17 ) {
perror ( L_2 ) ;
F_4 () ;
}
return V_18 ;
}
static T_2
F_7 ( int const V_8 , void const * const V_16 , T_2 const V_17 )
{
T_2 V_19 = V_17 ;
T_1 V_20 = 0 ;
V_7 = 1 ;
if ( V_12 + V_17 >= V_21 ) {
T_1 V_22 = ( V_12 + V_17 ) - V_21 ;
if ( V_22 > V_6 ) {
V_5 = realloc ( V_5 , V_22 ) ;
V_6 = V_22 ;
}
if ( ! V_5 ) {
perror ( L_3 ) ;
F_4 () ;
}
if ( V_12 < V_21 ) {
V_19 = V_21 - V_12 ;
} else {
V_19 = 0 ;
V_20 = V_22 - V_17 ;
}
}
if ( V_19 )
memcpy ( V_12 , V_16 , V_19 ) ;
if ( V_19 < V_17 )
memcpy ( V_5 + V_20 , V_16 + V_19 , V_17 - V_19 ) ;
V_12 += V_17 ;
return V_17 ;
}
static void *
F_8 ( T_2 V_23 )
{
void * const V_24 = malloc ( V_23 ) ;
if ( V_24 == 0 ) {
fprintf ( V_15 , L_4 , V_23 ) ;
F_4 () ;
}
return V_24 ;
}
static int F_9 ( void * V_25 , T_2 const V_9 )
{
T_3 * V_26 ;
unsigned char * V_27 ;
V_26 = V_25 + V_9 ;
if ( * V_26 != 0 )
return - 1 ;
V_27 = V_25 + V_9 - 1 ;
if ( * V_27 != 0xe8 )
return - 1 ;
F_3 ( V_28 , V_9 - 1 , V_11 ) ;
F_7 ( V_28 , V_29 , 5 ) ;
return 0 ;
}
static int F_10 ( void * V_25 , T_2 const V_9 )
{
T_3 * V_26 ;
V_26 = V_25 + V_9 ;
if ( * V_26 != 0x94000000 )
return - 1 ;
F_3 ( V_28 , V_9 , V_11 ) ;
F_7 ( V_28 , V_29 , 4 ) ;
return 0 ;
}
static void * F_11 ( char const * V_30 )
{
V_28 = F_12 ( V_30 , V_31 ) ;
if ( V_28 < 0 || F_13 ( V_28 , & V_3 ) < 0 ) {
perror ( V_30 ) ;
F_4 () ;
}
if ( ! F_14 ( V_3 . V_32 ) ) {
fprintf ( V_15 , L_5 , V_30 ) ;
F_4 () ;
}
V_2 = F_15 ( 0 , V_3 . V_4 , V_33 | V_34 , V_35 ,
V_28 , 0 ) ;
V_1 = 0 ;
if ( V_2 == V_36 ) {
V_1 = 1 ;
V_2 = F_8 ( V_3 . V_4 ) ;
F_5 ( V_28 , V_2 , V_3 . V_4 ) ;
}
F_16 ( V_28 ) ;
V_21 = V_2 + V_3 . V_4 ;
return V_2 ;
}
static void F_17 ( const char * V_30 )
{
char V_37 [ strlen ( V_30 ) + 4 ] ;
T_2 V_18 ;
if ( ! V_7 )
return;
sprintf ( V_37 , L_6 , V_30 ) ;
V_28 = F_12 ( V_37 , V_38 | V_39 | V_40 , V_3 . V_32 ) ;
if ( V_28 < 0 ) {
perror ( V_30 ) ;
F_4 () ;
}
V_18 = F_18 ( V_28 , V_2 , V_3 . V_4 ) ;
if ( V_18 != V_3 . V_4 ) {
perror ( L_3 ) ;
F_4 () ;
}
if ( V_6 ) {
V_18 = F_18 ( V_28 , V_5 , V_6 ) ;
if ( V_18 != V_6 ) {
perror ( L_3 ) ;
F_4 () ;
}
}
F_16 ( V_28 ) ;
if ( rename ( V_37 , V_30 ) < 0 ) {
perror ( V_30 ) ;
F_4 () ;
}
}
static T_4 F_19 ( T_4 const V_41 )
{
return ( ( 0xff & ( V_41 >> ( 0 * 8 ) ) ) << ( 7 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 1 * 8 ) ) ) << ( 6 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 2 * 8 ) ) ) << ( 5 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 3 * 8 ) ) ) << ( 4 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 4 * 8 ) ) ) << ( 3 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 5 * 8 ) ) ) << ( 2 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 6 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 7 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_3 F_20 ( T_3 const V_41 )
{
return ( ( 0xff & ( V_41 >> ( 0 * 8 ) ) ) << ( 3 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 1 * 8 ) ) ) << ( 2 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 2 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 3 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_3 F_21 ( T_5 const V_41 )
{
return ( ( 0xff & ( V_41 >> ( 0 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_41 >> ( 1 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_4 F_22 ( T_4 const V_41 )
{
return V_41 ;
}
static T_3 F_23 ( T_3 const V_41 )
{
return V_41 ;
}
static T_3 F_24 ( T_5 const V_41 )
{
return V_41 ;
}
static int
F_25 ( char const * const V_42 )
{
return strcmp ( L_7 , V_42 ) == 0 ||
strcmp ( L_8 , V_42 ) == 0 ||
strcmp ( L_9 , V_42 ) == 0 ||
strcmp ( L_10 , V_42 ) == 0 ||
strcmp ( L_11 , V_42 ) == 0 ||
strcmp ( L_12 , V_42 ) == 0 ||
strcmp ( L_13 , V_42 ) == 0 ||
strcmp ( L_14 , V_42 ) == 0 ;
}
static T_4 F_26 ( T_6 const * V_43 )
{
return F_27 (((union mips_r_info){ .r_info = rp->r_info }).r_mips.r_sym) ;
}
static void F_28 ( T_6 * const V_43 , unsigned V_44 , unsigned type )
{
V_43 -> V_45 = ( (union V_46 ) {
. V_47 = { . V_48 = F_27 ( V_44 ) , . V_49 = type }
} ) . V_45 ;
}
static void
F_29 ( char const * const V_30 )
{
T_7 * const V_50 = F_11 ( V_30 ) ;
unsigned int V_51 = 0 ;
F_27 = F_23 ;
V_52 = F_24 ;
V_53 = F_22 ;
switch ( V_50 -> V_54 [ V_55 ] ) {
static unsigned int const V_56 = 1 ;
default:
fprintf ( V_15 , L_15 ,
V_50 -> V_54 [ V_55 ] , V_30 ) ;
F_4 () ;
break;
case V_57 :
if ( * ( unsigned char const * ) & V_56 != 1 ) {
F_27 = F_20 ;
V_52 = F_21 ;
V_53 = F_19 ;
}
break;
case V_58 :
if ( * ( unsigned char const * ) & V_56 != 0 ) {
F_27 = F_20 ;
V_52 = F_21 ;
V_53 = F_19 ;
}
break;
}
if ( memcmp ( V_59 , V_50 -> V_54 , V_60 ) != 0
|| V_52 ( V_50 -> V_61 ) != V_62
|| V_50 -> V_54 [ V_63 ] != V_64 ) {
fprintf ( V_15 , L_16 , V_30 ) ;
F_4 () ;
}
V_65 = 0 ;
switch ( V_52 ( V_50 -> V_66 ) ) {
default:
fprintf ( V_15 , L_17 ,
V_52 ( V_50 -> V_66 ) , V_30 ) ;
F_4 () ;
break;
case V_67 :
V_51 = V_68 ;
V_69 = V_70 ;
V_71 = F_9 ;
V_29 = V_72 ;
V_73 = - 1 ;
break;
case V_74 : V_51 = V_75 ;
V_76 = L_18 ;
break;
case V_77 :
V_51 = V_78 ;
V_71 = F_10 ;
V_69 = V_79 ;
V_29 = V_80 ;
V_65 = '_' ;
break;
case V_81 : V_51 = V_82 ; V_65 = '_' ; break;
case V_83 : V_51 = V_84 ;
V_76 = L_19 ;
V_69 = V_85 ;
V_86 = V_87 ;
break;
case V_88 : V_65 = '_' ; break;
case V_89 : V_51 = V_90 ; V_65 = '_' ; break;
case V_91 : V_51 = V_92 ; V_65 = '_' ; break;
case V_93 : V_65 = '_' ; break;
case V_94 : V_51 = V_95 ; break;
case V_96 : V_51 = V_97 ; V_65 = '_' ; break;
case V_98 :
V_71 = F_9 ;
V_29 = V_99 ;
V_51 = V_100 ;
V_69 = V_101 ;
V_102 = - 1 ;
break;
}
switch ( V_50 -> V_54 [ V_103 ] ) {
default:
fprintf ( V_15 , L_20 ,
V_50 -> V_54 [ V_103 ] , V_30 ) ;
F_4 () ;
break;
case V_104 :
if ( V_52 ( V_50 -> V_105 ) != sizeof( T_7 )
|| V_52 ( V_50 -> V_106 ) != sizeof( V_107 ) ) {
fprintf ( V_15 ,
L_21 , V_30 ) ;
F_4 () ;
}
if ( V_52 ( V_50 -> V_66 ) == V_88 ) {
V_51 = V_108 ;
V_86 = V_87 ;
}
F_30 ( V_50 , V_30 , V_51 ) ;
break;
case V_109 : {
T_8 * const V_110 = ( T_8 * ) V_50 ;
if ( V_52 ( V_110 -> V_105 ) != sizeof( T_8 )
|| V_52 ( V_110 -> V_106 ) != sizeof( V_111 ) ) {
fprintf ( V_15 ,
L_21 , V_30 ) ;
F_4 () ;
}
if ( V_52 ( V_110 -> V_66 ) == V_93 ) {
V_51 = V_112 ;
V_102 = - 14 ;
}
if ( V_52 ( V_110 -> V_66 ) == V_88 ) {
V_51 = V_113 ;
V_114 = F_26 ;
V_115 = F_28 ;
V_116 = V_117 ;
}
F_31 ( V_110 , V_30 , V_51 ) ;
break;
}
}
F_17 ( V_30 ) ;
F_1 () ;
}
int
main ( int V_118 , char * V_119 [] )
{
const char V_120 [] = L_22 ;
int V_121 = sizeof( V_120 ) - 1 ;
int V_122 = 0 ;
int V_123 ;
int V_124 ;
while ( ( V_123 = F_32 ( V_118 , V_119 , L_23 ) ) >= 0 ) {
switch ( V_123 ) {
case 'w' :
V_125 = 1 ;
break;
default:
fprintf ( V_15 , L_24 ) ;
return 0 ;
}
}
if ( ( V_118 - V_126 ) < 1 ) {
fprintf ( V_15 , L_24 ) ;
return 0 ;
}
for ( V_124 = V_126 ; V_124 < V_118 ; V_124 ++ ) {
char * V_127 = V_119 [ V_124 ] ;
int const V_128 = setjmp ( V_129 ) ;
int V_130 ;
V_130 = strlen ( V_127 ) ;
if ( V_130 >= V_121 &&
strcmp ( V_127 + ( V_130 - V_121 ) , V_120 ) == 0 )
continue;
switch ( V_128 ) {
default:
fprintf ( V_15 , L_25 , V_127 ) ;
exit ( 1 ) ;
break;
case V_131 :
V_28 = - 1 ;
V_1 = 1 ;
V_2 = NULL ;
V_12 = NULL ;
V_7 = 0 ;
F_29 ( V_127 ) ;
break;
case V_132 :
fprintf ( V_15 , L_26 , V_127 ) ;
++ V_122 ;
break;
case V_133 :
break;
}
}
return ! ! V_122 ;
}
