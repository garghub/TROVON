static void
F_1 ( void )
{
if ( ! V_1 )
F_2 ( V_2 , V_3 . V_4 ) ;
else
free ( V_2 ) ;
F_3 ( V_5 ) ;
}
static T_1
F_4 ( int const V_6 , T_1 const V_7 , int const V_8 )
{
T_1 const V_9 = F_5 ( V_6 , V_7 , V_8 ) ;
if ( V_9 == ( T_1 ) - 1 ) {
perror ( L_1 ) ;
F_6 () ;
}
return V_9 ;
}
static T_2
F_7 ( int const V_6 , void * const V_10 , T_2 const V_11 )
{
T_2 const V_12 = F_8 ( V_6 , V_10 , V_11 ) ;
if ( V_12 != V_11 ) {
perror ( L_2 ) ;
F_6 () ;
}
return V_12 ;
}
static T_2
F_9 ( int const V_6 , void const * const V_10 , T_2 const V_11 )
{
T_2 const V_12 = F_10 ( V_6 , V_10 , V_11 ) ;
if ( V_12 != V_11 ) {
perror ( L_3 ) ;
F_6 () ;
}
return V_12 ;
}
static void *
F_11 ( T_2 V_13 )
{
void * const V_14 = malloc ( V_13 ) ;
if ( V_14 == 0 ) {
fprintf ( V_15 , L_4 , V_13 ) ;
F_6 () ;
}
return V_14 ;
}
static int F_12 ( void * V_16 , T_2 const V_7 )
{
T_3 * V_17 ;
unsigned char * V_18 ;
V_17 = V_16 + V_7 ;
if ( * V_17 != 0 )
return - 1 ;
V_18 = V_16 + V_7 - 1 ;
if ( * V_18 != 0xe8 )
return - 1 ;
F_4 ( V_5 , V_7 - 1 , V_19 ) ;
F_9 ( V_5 , V_20 , 5 ) ;
return 0 ;
}
static void * F_13 ( char const * V_21 )
{
void * V_14 ;
V_5 = F_14 ( V_21 , V_22 ) ;
if ( V_5 < 0 || F_15 ( V_5 , & V_3 ) < 0 ) {
perror ( V_21 ) ;
F_6 () ;
}
if ( ! F_16 ( V_3 . V_23 ) ) {
fprintf ( V_15 , L_5 , V_21 ) ;
F_6 () ;
}
V_14 = F_17 ( 0 , V_3 . V_4 , V_24 | V_25 , V_26 ,
V_5 , 0 ) ;
V_1 = 0 ;
if ( V_14 == V_27 ) {
V_1 = 1 ;
V_14 = F_11 ( V_3 . V_4 ) ;
F_7 ( V_5 , V_14 , V_3 . V_4 ) ;
}
return V_14 ;
}
static T_4 F_18 ( T_4 const V_28 )
{
return ( ( 0xff & ( V_28 >> ( 0 * 8 ) ) ) << ( 7 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 1 * 8 ) ) ) << ( 6 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 2 * 8 ) ) ) << ( 5 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 3 * 8 ) ) ) << ( 4 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 4 * 8 ) ) ) << ( 3 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 5 * 8 ) ) ) << ( 2 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 6 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 7 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_3 F_19 ( T_3 const V_28 )
{
return ( ( 0xff & ( V_28 >> ( 0 * 8 ) ) ) << ( 3 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 1 * 8 ) ) ) << ( 2 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 2 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 3 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_3 F_20 ( T_5 const V_28 )
{
return ( ( 0xff & ( V_28 >> ( 0 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_28 >> ( 1 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_4 F_21 ( T_4 const V_28 )
{
return V_28 ;
}
static T_3 F_22 ( T_3 const V_28 )
{
return V_28 ;
}
static T_3 F_23 ( T_5 const V_28 )
{
return V_28 ;
}
static int
F_24 ( char const * const V_29 )
{
return strcmp ( L_6 , V_29 ) == 0 ||
strcmp ( L_7 , V_29 ) == 0 ||
strcmp ( L_8 , V_29 ) == 0 ||
strcmp ( L_9 , V_29 ) == 0 ||
strcmp ( L_10 , V_29 ) == 0 ||
strcmp ( L_11 , V_29 ) == 0 ||
strcmp ( L_12 , V_29 ) == 0 ;
}
static T_4 F_25 ( T_6 const * V_30 )
{
return V_9 (((union mips_r_info){ .r_info = rp->r_info }).r_mips.r_sym) ;
}
static void F_26 ( T_6 * const V_30 , unsigned V_31 , unsigned type )
{
V_30 -> V_32 = ( (union V_33 ) {
. V_34 = { . V_35 = V_9 ( V_31 ) , . V_36 = type }
} ) . V_32 ;
}
static void
F_27 ( char const * const V_21 )
{
T_7 * const V_37 = F_13 ( V_21 ) ;
unsigned int V_38 = 0 ;
V_2 = V_37 ;
V_9 = F_22 ;
V_39 = F_23 ;
V_40 = F_21 ;
switch ( V_37 -> V_41 [ V_42 ] ) {
static unsigned int const V_43 = 1 ;
default:
fprintf ( V_15 , L_13 ,
V_37 -> V_41 [ V_42 ] , V_21 ) ;
F_6 () ;
break;
case V_44 :
if ( * ( unsigned char const * ) & V_43 != 1 ) {
V_9 = F_19 ;
V_39 = F_20 ;
V_40 = F_18 ;
}
break;
case V_45 :
if ( * ( unsigned char const * ) & V_43 != 0 ) {
V_9 = F_19 ;
V_39 = F_20 ;
V_40 = F_18 ;
}
break;
}
if ( memcmp ( V_46 , V_37 -> V_41 , V_47 ) != 0
|| V_39 ( V_37 -> V_48 ) != V_49
|| V_37 -> V_41 [ V_50 ] != V_51 ) {
fprintf ( V_15 , L_14 , V_21 ) ;
F_6 () ;
}
V_52 = 0 ;
switch ( V_39 ( V_37 -> V_53 ) ) {
default:
fprintf ( V_15 , L_15 ,
V_39 ( V_37 -> V_53 ) , V_21 ) ;
F_6 () ;
break;
case V_54 :
V_38 = V_55 ;
V_56 = F_12 ;
V_20 = V_57 ;
V_58 = - 1 ;
break;
case V_59 : V_38 = V_60 ;
V_61 = L_16 ;
break;
case V_62 :
V_38 = V_63 ; V_52 = '_' ; break;
case V_64 : V_38 = V_65 ; V_52 = '_' ; break;
case V_66 : V_38 = V_67 ;
V_61 = L_17 ;
V_68 = V_69 ;
V_70 = V_71 ;
break;
case V_72 : V_52 = '_' ; break;
case V_73 : V_38 = V_74 ; V_52 = '_' ; break;
case V_75 : V_38 = V_76 ; V_52 = '_' ; break;
case V_77 : V_52 = '_' ; break;
case V_78 : V_38 = V_79 ; break;
case V_80 : V_38 = V_81 ; V_52 = '_' ; break;
case V_82 :
V_56 = F_12 ;
V_20 = V_83 ;
V_38 = V_84 ;
V_85 = - 1 ;
break;
}
switch ( V_37 -> V_41 [ V_86 ] ) {
default:
fprintf ( V_15 , L_18 ,
V_37 -> V_41 [ V_86 ] , V_21 ) ;
F_6 () ;
break;
case V_87 :
if ( V_39 ( V_37 -> V_88 ) != sizeof( T_7 )
|| V_39 ( V_37 -> V_89 ) != sizeof( V_90 ) ) {
fprintf ( V_15 ,
L_19 , V_21 ) ;
F_6 () ;
}
if ( V_39 ( V_37 -> V_53 ) == V_77 ) {
V_38 = V_91 ;
V_58 = - 4 ;
}
if ( V_39 ( V_37 -> V_53 ) == V_72 ) {
V_38 = V_92 ;
V_70 = V_71 ;
}
F_28 ( V_37 , V_21 , V_38 ) ;
break;
case V_93 : {
T_8 * const V_94 = ( T_8 * ) V_37 ;
if ( V_39 ( V_94 -> V_88 ) != sizeof( T_8 )
|| V_39 ( V_94 -> V_89 ) != sizeof( V_95 ) ) {
fprintf ( V_15 ,
L_19 , V_21 ) ;
F_6 () ;
}
if ( V_39 ( V_94 -> V_53 ) == V_77 ) {
V_38 = V_96 ;
V_85 = - 8 ;
}
if ( V_39 ( V_94 -> V_53 ) == V_72 ) {
V_38 = V_97 ;
V_98 = F_25 ;
V_99 = F_26 ;
V_100 = V_101 ;
}
F_29 ( V_94 , V_21 , V_38 ) ;
break;
}
}
F_1 () ;
}
int
main ( int V_102 , char * V_103 [] )
{
const char V_104 [] = L_20 ;
int V_105 = sizeof( V_104 ) - 1 ;
int V_106 = 0 ;
int V_107 ;
int V_108 ;
while ( ( V_107 = F_30 ( V_102 , V_103 , L_21 ) ) >= 0 ) {
switch ( V_107 ) {
case 'w' :
V_109 = 1 ;
break;
default:
fprintf ( V_15 , L_22 ) ;
return 0 ;
}
}
if ( ( V_102 - V_110 ) < 1 ) {
fprintf ( V_15 , L_22 ) ;
return 0 ;
}
for ( V_108 = V_110 ; V_108 < V_102 ; V_108 ++ ) {
char * V_111 = V_103 [ V_108 ] ;
int const V_112 = setjmp ( V_113 ) ;
int V_114 ;
V_114 = strlen ( V_111 ) ;
if ( V_114 >= V_105 &&
strcmp ( V_111 + ( V_114 - V_105 ) , V_104 ) == 0 )
continue;
switch ( V_112 ) {
default:
fprintf ( V_15 , L_23 , V_111 ) ;
exit ( 1 ) ;
break;
case V_115 :
V_5 = - 1 ;
V_2 = NULL ;
V_1 = 1 ;
F_27 ( V_111 ) ;
break;
case V_116 :
++ V_106 ;
break;
case V_117 :
break;
}
}
return ! ! V_106 ;
}
