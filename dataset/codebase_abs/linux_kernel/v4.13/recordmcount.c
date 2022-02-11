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
char * V_26 ;
int V_19 = 1 ;
int V_30 ;
T_2 V_31 = V_9 ;
V_26 = V_25 + V_9 ;
if ( memcmp ( V_26 , V_32 , 4 ) == 0 ) {
if ( memcmp ( V_26 - 4 , V_33 , 4 ) == 0 ) {
V_31 -= 4 ;
V_19 = 2 ;
}
V_29 = V_34 ;
V_30 = 4 ;
} else if ( memcmp ( V_26 - 2 , V_35 , 6 ) == 0 ) {
V_19 = 3 ;
V_30 = 2 ;
V_31 -= 2 ;
V_29 = V_36 ;
} else
return - 1 ;
F_3 ( V_28 , V_31 , V_11 ) ;
do {
F_7 ( V_28 , V_29 , V_30 ) ;
} while ( -- V_19 > 0 );
return 0 ;
}
static int F_11 ( void * V_25 , T_2 const V_9 )
{
T_3 * V_26 ;
V_26 = V_25 + V_9 ;
if ( * V_26 != 0x94000000 )
return - 1 ;
F_3 ( V_28 , V_9 , V_11 ) ;
F_7 ( V_28 , V_29 , 4 ) ;
return 0 ;
}
static void * F_12 ( char const * V_37 )
{
V_28 = F_13 ( V_37 , V_38 ) ;
if ( V_28 < 0 || F_14 ( V_28 , & V_3 ) < 0 ) {
perror ( V_37 ) ;
F_4 () ;
}
if ( ! F_15 ( V_3 . V_39 ) ) {
fprintf ( V_15 , L_5 , V_37 ) ;
F_4 () ;
}
V_2 = F_16 ( 0 , V_3 . V_4 , V_40 | V_41 , V_42 ,
V_28 , 0 ) ;
V_1 = 0 ;
if ( V_2 == V_43 ) {
V_1 = 1 ;
V_2 = F_8 ( V_3 . V_4 ) ;
F_5 ( V_28 , V_2 , V_3 . V_4 ) ;
}
F_17 ( V_28 ) ;
V_21 = V_2 + V_3 . V_4 ;
return V_2 ;
}
static void F_18 ( const char * V_37 )
{
char V_44 [ strlen ( V_37 ) + 4 ] ;
T_2 V_18 ;
if ( ! V_7 )
return;
sprintf ( V_44 , L_6 , V_37 ) ;
V_28 = F_13 ( V_44 , V_45 | V_46 | V_47 , V_3 . V_39 ) ;
if ( V_28 < 0 ) {
perror ( V_37 ) ;
F_4 () ;
}
V_18 = F_19 ( V_28 , V_2 , V_3 . V_4 ) ;
if ( V_18 != V_3 . V_4 ) {
perror ( L_3 ) ;
F_4 () ;
}
if ( V_6 ) {
V_18 = F_19 ( V_28 , V_5 , V_6 ) ;
if ( V_18 != V_6 ) {
perror ( L_3 ) ;
F_4 () ;
}
}
F_17 ( V_28 ) ;
if ( rename ( V_44 , V_37 ) < 0 ) {
perror ( V_37 ) ;
F_4 () ;
}
}
static T_4 F_20 ( T_4 const V_48 )
{
return ( ( 0xff & ( V_48 >> ( 0 * 8 ) ) ) << ( 7 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 1 * 8 ) ) ) << ( 6 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 2 * 8 ) ) ) << ( 5 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 3 * 8 ) ) ) << ( 4 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 4 * 8 ) ) ) << ( 3 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 5 * 8 ) ) ) << ( 2 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 6 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 7 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_3 F_21 ( T_3 const V_48 )
{
return ( ( 0xff & ( V_48 >> ( 0 * 8 ) ) ) << ( 3 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 1 * 8 ) ) ) << ( 2 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 2 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 3 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_3 F_22 ( T_5 const V_48 )
{
return ( ( 0xff & ( V_48 >> ( 0 * 8 ) ) ) << ( 1 * 8 ) )
| ( ( 0xff & ( V_48 >> ( 1 * 8 ) ) ) << ( 0 * 8 ) ) ;
}
static T_4 F_23 ( T_4 const V_48 )
{
return V_48 ;
}
static T_3 F_24 ( T_3 const V_48 )
{
return V_48 ;
}
static T_3 F_25 ( T_5 const V_48 )
{
return V_48 ;
}
static int
F_26 ( char const * const V_49 )
{
return strcmp ( L_7 , V_49 ) == 0 ||
strcmp ( L_8 , V_49 ) == 0 ||
strcmp ( L_9 , V_49 ) == 0 ||
strcmp ( L_10 , V_49 ) == 0 ||
strcmp ( L_11 , V_49 ) == 0 ||
strcmp ( L_12 , V_49 ) == 0 ||
strcmp ( L_13 , V_49 ) == 0 ||
strcmp ( L_14 , V_49 ) == 0 ||
strcmp ( L_15 , V_49 ) == 0 ||
strcmp ( L_16 , V_49 ) == 0 ;
}
static T_4 F_27 ( T_6 const * V_50 )
{
return F_28 (((union mips_r_info){ .r_info = rp->r_info }).r_mips.r_sym) ;
}
static void F_29 ( T_6 * const V_50 , unsigned V_51 , unsigned type )
{
V_50 -> V_52 = ( (union V_53 ) {
. V_54 = { . V_55 = F_28 ( V_51 ) , . V_56 = type }
} ) . V_52 ;
}
static void
F_30 ( char const * const V_37 )
{
T_7 * const V_57 = F_12 ( V_37 ) ;
unsigned int V_58 = 0 ;
F_28 = F_24 ;
V_59 = F_25 ;
V_60 = F_23 ;
switch ( V_57 -> V_61 [ V_62 ] ) {
static unsigned int const V_63 = 1 ;
default:
fprintf ( V_15 , L_17 ,
V_57 -> V_61 [ V_62 ] , V_37 ) ;
F_4 () ;
break;
case V_64 :
if ( * ( unsigned char const * ) & V_63 != 1 ) {
F_28 = F_21 ;
V_59 = F_22 ;
V_60 = F_20 ;
}
V_34 = V_65 ;
V_32 = V_66 ;
V_33 = V_67 ;
V_36 = V_68 ;
V_35 = V_69 ;
break;
case V_70 :
if ( * ( unsigned char const * ) & V_63 != 0 ) {
F_28 = F_21 ;
V_59 = F_22 ;
V_60 = F_20 ;
}
V_34 = V_71 ;
V_32 = V_72 ;
V_33 = V_73 ;
V_36 = V_74 ;
V_35 = V_75 ;
break;
}
if ( memcmp ( V_76 , V_57 -> V_61 , V_77 ) != 0
|| V_59 ( V_57 -> V_78 ) != V_79
|| V_57 -> V_61 [ V_80 ] != V_81 ) {
fprintf ( V_15 , L_18 , V_37 ) ;
F_4 () ;
}
V_82 = 0 ;
switch ( V_59 ( V_57 -> V_83 ) ) {
default:
fprintf ( V_15 , L_19 ,
V_59 ( V_57 -> V_83 ) , V_37 ) ;
F_4 () ;
break;
case V_84 :
V_58 = V_85 ;
V_86 = V_87 ;
V_88 = F_9 ;
V_29 = V_89 ;
V_90 = - 1 ;
break;
case V_91 : V_58 = V_92 ;
V_93 = L_20 ;
V_88 = F_10 ;
V_86 = V_94 ;
break;
case V_95 :
V_58 = V_96 ;
V_88 = F_11 ;
V_86 = V_97 ;
V_29 = V_98 ;
V_82 = '_' ;
break;
case V_99 : V_58 = V_100 ; V_82 = '_' ; break;
case V_101 : V_58 = V_102 ;
V_93 = L_21 ;
V_86 = V_103 ;
V_104 = V_105 ;
break;
case V_106 : V_82 = '_' ; break;
case V_107 : V_58 = V_108 ; V_82 = '_' ; break;
case V_109 : V_58 = V_110 ; V_82 = '_' ; break;
case V_111 : V_82 = '_' ; break;
case V_112 : V_58 = V_113 ; break;
case V_114 : V_58 = V_115 ; V_82 = '_' ; break;
case V_116 :
V_88 = F_9 ;
V_29 = V_117 ;
V_58 = V_118 ;
V_86 = V_119 ;
V_120 = - 1 ;
break;
}
switch ( V_57 -> V_61 [ V_121 ] ) {
default:
fprintf ( V_15 , L_22 ,
V_57 -> V_61 [ V_121 ] , V_37 ) ;
F_4 () ;
break;
case V_122 :
if ( V_59 ( V_57 -> V_123 ) != sizeof( T_7 )
|| V_59 ( V_57 -> V_124 ) != sizeof( V_125 ) ) {
fprintf ( V_15 ,
L_23 , V_37 ) ;
F_4 () ;
}
if ( V_59 ( V_57 -> V_83 ) == V_106 ) {
V_58 = V_126 ;
V_104 = V_105 ;
}
F_31 ( V_57 , V_37 , V_58 ) ;
break;
case V_127 : {
T_8 * const V_128 = ( T_8 * ) V_57 ;
if ( V_59 ( V_128 -> V_123 ) != sizeof( T_8 )
|| V_59 ( V_128 -> V_124 ) != sizeof( V_129 ) ) {
fprintf ( V_15 ,
L_23 , V_37 ) ;
F_4 () ;
}
if ( V_59 ( V_128 -> V_83 ) == V_111 ) {
V_58 = V_130 ;
V_120 = - 14 ;
}
if ( V_59 ( V_128 -> V_83 ) == V_106 ) {
V_58 = V_131 ;
V_132 = F_27 ;
V_133 = F_29 ;
V_134 = V_135 ;
}
F_32 ( V_128 , V_37 , V_58 ) ;
break;
}
}
F_18 ( V_37 ) ;
F_1 () ;
}
int
main ( int V_136 , char * V_137 [] )
{
const char V_138 [] = L_24 ;
int V_139 = sizeof( V_138 ) - 1 ;
int V_140 = 0 ;
int V_141 ;
int V_142 ;
while ( ( V_141 = F_33 ( V_136 , V_137 , L_25 ) ) >= 0 ) {
switch ( V_141 ) {
case 'w' :
V_143 = 1 ;
break;
default:
fprintf ( V_15 , L_26 ) ;
return 0 ;
}
}
if ( ( V_136 - V_144 ) < 1 ) {
fprintf ( V_15 , L_26 ) ;
return 0 ;
}
for ( V_142 = V_144 ; V_142 < V_136 ; V_142 ++ ) {
char * V_145 = V_137 [ V_142 ] ;
int const V_146 = setjmp ( V_147 ) ;
int V_148 ;
V_148 = strlen ( V_145 ) ;
if ( V_148 >= V_139 &&
strcmp ( V_145 + ( V_148 - V_139 ) , V_138 ) == 0 )
continue;
switch ( V_146 ) {
default:
fprintf ( V_15 , L_27 , V_145 ) ;
exit ( 1 ) ;
break;
case V_149 :
V_28 = - 1 ;
V_1 = 1 ;
V_2 = NULL ;
V_12 = NULL ;
V_7 = 0 ;
F_30 ( V_145 ) ;
break;
case V_150 :
fprintf ( V_15 , L_28 , V_145 ) ;
++ V_140 ;
break;
case V_151 :
break;
}
}
return ! ! V_140 ;
}
