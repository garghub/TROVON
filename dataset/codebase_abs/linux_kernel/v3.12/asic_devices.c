static T_1 int F_1 ( unsigned char V_1 [ 2 ] )
{
const char * V_2 ;
V_1 [ 0 ] = '\0' ;
V_1 [ 1 ] = '\0' ;
strncpy ( V_3 , V_4 , V_5 - 1 ) ;
V_2 = strstr ( V_3 , V_6 ) ;
if ( V_2 && ( V_2 != V_3 ) && ( * ( V_2 - 1 ) != ' ' ) )
V_2 = strstr ( V_2 , L_1 V_6 L_2 ) ;
if ( V_2 ) {
V_2 += strlen ( V_6 L_2 ) ;
if ( * V_2 == '\0' || * ( V_2 + 1 ) == '\0' ||
( * ( V_2 + 2 ) != '\0' && * ( V_2 + 2 ) != ' ' ) )
F_2 ( V_6 L_3
L_4 ) ;
else {
V_1 [ 0 ] = * V_2 ;
V_1 [ 1 ] = * ( V_2 + 1 ) ;
}
}
return 0 ;
}
static T_1 T_2 void F_3 ( void )
{
unsigned char V_1 [ 2 ] ;
unsigned short V_7 ;
if ( F_1 ( V_1 ) == 0 )
V_7 = F_4 ( V_1 [ 0 ] ,
V_1 [ 1 ] ) ;
else
V_7 = ( unsigned short ) F_4 (
V_8 [ 0 ] ,
V_8 [ 1 ] ) ;
F_5 ( L_5 , V_7 ) ;
switch ( V_7 ) {
case F_4 ( 'R' , '1' ) :
V_9 = V_10 ;
break;
case F_4 ( '4' , '4' ) :
V_9 = V_11 ;
break;
case F_4 ( '4' , '6' ) :
V_9 = V_12 ;
break;
case F_4 ( 'A' , '1' ) :
V_9 = V_13 ;
break;
case F_4 ( '8' , '5' ) :
V_9 = V_14 ;
break;
case F_4 ( 'R' , '2' ) :
V_9 = V_15 ;
break;
case F_4 ( '8' , '6' ) :
V_9 = V_16 ;
break;
case F_4 ( 'B' , '1' ) :
V_9 = V_17 ;
break;
case F_4 ( 'E' , '1' ) :
V_9 = V_18 ;
break;
case F_4 ( 'F' , '1' ) :
V_9 = V_19 ;
break;
case F_4 ( '8' , '7' ) :
V_9 = V_20 ;
break;
default:
V_9 = - 1 ;
}
}
unsigned int F_6 ( void )
{
return V_9 ;
}
enum V_21 F_7 ( void )
{
return V_22 ;
}
static void T_1 F_8 ( unsigned long V_23 ,
const struct V_24 * V_25 )
{
V_26 = V_23 ;
V_27 = * V_25 ;
F_9 ( & V_27 ) ;
V_28 = ( unsigned long ) F_10 ( V_23 , V_29 ) ;
}
void T_1 F_11 ( void )
{
F_3 () ;
switch ( V_9 ) {
case V_10 :
case V_18 :
case V_19 :
V_30 = V_31 ;
V_22 = V_32 ;
F_8 ( V_33 , & V_34 ) ;
if ( V_9 == V_18 ) {
V_35 = V_36 ;
F_5 ( L_6
L_7 ) ;
} else if ( V_9 == V_19 ) {
V_35 = V_37 ;
F_5 ( L_8
L_7 ) ;
} else {
V_35 = V_38 ;
F_5 ( L_9
L_10 ) ;
}
break;
case V_11 :
V_30 = V_31 | V_39 |
V_40 ;
V_22 = V_41 ;
F_8 ( V_42 , & V_43 ) ;
V_35 = V_44 ;
F_5 ( L_11 ) ;
break;
case V_12 :
{
unsigned int V_45 = 0 ;
V_30 = V_31 | V_40 ;
F_8 ( V_46 , & V_47 ) ;
V_45 = F_12 ( V_48 ) << 24 ;
V_45 |= F_12 ( V_49 ) << 16 ;
V_45 |= F_12 ( V_50 ) << 8 ;
V_45 |= F_12 ( V_51 ) ;
if ( ( V_45 == V_52 ) || ( V_45 == V_53 ) )
V_22 = V_54 ;
else
V_22 = V_55 ;
V_35 = V_56 ;
F_5 ( L_12
L_13 ,
( V_22 == V_54 ) ? L_14 : L_15 ,
V_45 ) ;
break;
}
case V_13 :
V_30 = V_31 | V_40 ;
V_22 = V_54 ;
F_8 ( V_46 , & V_47 ) ;
V_35 = V_57 ;
F_5 ( L_16 ) ;
break;
case V_14 :
case V_15 :
V_30 = V_58 | V_39 |
V_40 ;
V_22 = V_41 ;
F_8 ( V_42 , & V_43 ) ;
V_35 = V_59 ;
F_5 ( L_17 ) ;
break;
case V_16 :
case V_17 :
V_30 = V_58 | V_39 |
V_40 ;
V_22 = V_54 ;
F_8 ( V_46 , & V_47 ) ;
V_35 = V_60 ;
F_5 ( L_18
L_19 ) ;
break;
case V_20 :
V_30 = V_31 | V_39 ;
V_22 = V_61 ;
F_8 ( V_62 , & V_63 ) ;
V_35 = V_64 ;
F_5 ( L_20 ) ;
break;
default:
F_13 ( L_21 ) ;
break;
}
switch ( V_22 ) {
case V_41 :
V_65 = 0x30000000 ;
break;
case V_32 :
V_65 = 0x10000000 ;
break;
case V_55 :
case V_54 :
V_65 = 0x10000000 ;
break;
default:
V_65 = 0x00000000 ;
break;
}
}
void T_1 F_14 ( void )
{
int V_66 ;
int V_67 = 0 ;
F_15 () ;
for ( V_66 = 0 ; V_35 [ V_66 ] . V_68 != 0 ; V_66 ++ ) {
int V_69 = F_16 ( & V_35 [ V_66 ] ) ;
if ( ( V_35 [ V_66 ] . V_70 != 0 ) &&
( ( V_35 [ V_66 ] . V_68 & V_71 ) != 0 ) ) {
F_17 ( F_18 ( V_35 [ V_66 ] . V_70 ) ,
V_69 , 0 ) ;
V_67 += F_16 ( & V_35 [ V_66 ] ) ;
F_5 ( L_22 ,
V_35 [ V_66 ] . V_72 , V_35 [ V_66 ] . V_70 ,
F_16 ( & V_35 [ V_66 ] ) ) ;
}
}
for ( V_66 = 0 ; V_35 [ V_66 ] . V_68 != 0 ; V_66 ++ ) {
int V_69 = F_16 ( & V_35 [ V_66 ] ) ;
if ( ( V_35 [ V_66 ] . V_70 == 0 ) &&
( ( V_35 [ V_66 ] . V_68 & V_71 ) != 0 ) ) {
void * V_73 = F_19 ( V_69 ) ;
if ( V_73 == NULL )
F_2 ( L_23
L_24 , V_35 [ V_66 ] . V_72 ) ;
else {
V_35 [ V_66 ] . V_70 =
F_20 ( F_21 ( V_73 ) ) ;
V_35 [ V_66 ] . V_74 =
V_35 [ V_66 ] . V_70 + V_69 - 1 ;
V_67 += V_69 ;
F_5 ( L_25
L_26 ,
V_35 [ V_66 ] . V_72 ,
V_35 [ V_66 ] . V_70 , V_69 ) ;
}
}
}
F_5 ( L_27 , V_67 ) ;
for ( V_66 = 0 ; V_35 [ V_66 ] . V_68 != 0 ; V_66 ++ ) {
if ( ( V_35 [ V_66 ] . V_70 != 0 ) &&
( ( V_35 [ V_66 ] . V_68 & V_75 ) != 0 ) ) {
F_5 ( L_28 ,
V_35 [ V_66 ] . V_72 , V_35 [ V_66 ] . V_70 ) ;
}
}
}
static int T_1 F_22 ( char * V_2 )
{
V_76 = ( unsigned long ) F_23 ( V_2 , NULL , 0 ) ;
return 0 ;
}
static int T_1 F_24 ( char * V_2 )
{
#if 0
pmemlen = (unsigned long)simple_strtoul(p, NULL, 0);
#else
V_77 = 0x20000 ;
#endif
return 0 ;
}
static void T_1 F_15 ( void )
{
struct V_78 * V_78 ;
V_78 = F_25 ( L_29 ) ;
if ( V_78 && V_76 && V_77 ) {
V_78 -> V_70 = F_20 ( V_76 - 0x80000000 ) ;
V_78 -> V_74 = V_78 -> V_70 + V_77 - 1 ;
F_5 ( L_30 ,
V_78 -> V_70 , V_78 -> V_74 ) ;
}
}
struct V_78 * F_25 ( const char * V_72 )
{
int V_66 ;
for ( V_66 = 0 ; V_35 [ V_66 ] . V_68 != 0 ; V_66 ++ ) {
if ( strcmp ( V_35 [ V_66 ] . V_72 , V_72 ) == 0 )
return & V_35 [ V_66 ] ;
}
return NULL ;
}
void F_26 ( void * V_79 , int V_69 )
{
F_27 ( V_79 , V_79 + V_69 , - 1 , NULL ) ;
}
int F_28 ( void )
{
return ( V_30 & V_58 ) != 0 ;
}
int F_29 ( void )
{
return ( V_30 & V_31 ) != 0 ;
}
int F_30 ( void )
{
return ( V_30 & V_39 ) != 0 ;
}
int F_31 ( void )
{
return ( V_30 & V_40 ) != 0 ;
}
