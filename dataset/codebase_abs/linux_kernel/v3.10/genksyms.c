static unsigned long F_1 ( unsigned char V_1 , unsigned long V_2 )
{
return V_3 [ ( V_2 ^ V_1 ) & 0xff ] ^ ( V_2 >> 8 ) ;
}
static unsigned long F_2 ( const char * V_4 , unsigned long V_2 )
{
while ( * V_4 )
V_2 = F_1 ( * V_4 ++ , V_2 ) ;
return V_2 ;
}
static unsigned long F_3 ( const char * V_4 )
{
return F_2 ( V_4 , 0xffffffff ) ^ 0xffffffff ;
}
static enum V_5 F_4 ( enum V_5 V_6 )
{
switch ( V_6 ) {
case V_7 :
case V_8 :
case V_9 :
return V_8 ;
case V_10 :
case V_11 :
case V_12 :
return V_11 ;
}
return V_6 ;
}
struct V_13 * F_5 ( const char * V_14 , enum V_5 V_15 , int V_16 )
{
unsigned long V_17 = F_3 ( V_14 ) % V_18 ;
struct V_13 * V_19 ;
for ( V_19 = V_20 [ V_17 ] ; V_19 ; V_19 = V_19 -> V_21 )
if ( F_4 ( V_19 -> type ) == F_4 ( V_15 ) &&
strcmp ( V_14 , V_19 -> V_14 ) == 0 &&
V_19 -> V_22 )
break;
if ( V_16 && V_19 && V_19 -> type != V_15 )
return NULL ;
return V_19 ;
}
static int F_6 ( struct V_13 * V_19 )
{
struct V_23 * V_24 ;
return ( ( V_19 -> type == V_11 ||
V_19 -> type == V_12 ||
V_19 -> type == V_10 ) &&
( V_24 = V_19 -> V_24 ) && V_24 -> V_25 == V_8 &&
strcmp ( V_24 -> string , L_1 ) == 0 &&
( V_24 = V_24 -> V_26 ) && V_24 -> V_25 == V_8 &&
strcmp ( V_24 -> string , L_2 ) == 0 &&
( V_24 = V_24 -> V_26 ) && V_24 -> V_25 == V_8 &&
strcmp ( V_24 -> string , L_3 ) == 0 ) ;
}
static struct V_13 * F_7 ( const char * V_14 , enum V_5 type ,
struct V_23 * V_24 , int V_27 ,
int V_28 )
{
unsigned long V_17 ;
struct V_13 * V_19 ;
enum V_29 V_30 = V_31 ;
static int V_32 ;
static struct V_23 * V_33 ;
if ( type == V_7 ) {
if ( V_24 ) {
F_8 ( V_33 , NULL ) ;
V_33 = F_9 ( V_24 , NULL ) ;
V_32 = 1 ;
} else {
struct V_23 * V_34 ;
char V_35 [ 20 ] ;
snprintf ( V_35 , sizeof( V_35 ) , L_4 , V_32 ++ ) ;
if ( V_33 ) {
V_34 = F_9 ( V_33 , NULL ) ;
V_24 = F_10 ( F_11 ( L_5 ) ,
V_34 ,
F_11 ( L_6 ) ,
F_11 ( L_7 ) ,
F_11 ( V_35 ) , NULL ) ;
} else {
V_24 = F_11 ( V_35 ) ;
}
}
} else if ( type == V_10 ) {
F_8 ( V_33 , NULL ) ;
V_33 = NULL ;
V_32 = 0 ;
if ( ! V_14 )
return NULL ;
}
V_17 = F_3 ( V_14 ) % V_18 ;
for ( V_19 = V_20 [ V_17 ] ; V_19 ; V_19 = V_19 -> V_21 ) {
if ( F_4 ( V_19 -> type ) == F_4 ( type ) &&
strcmp ( V_14 , V_19 -> V_14 ) == 0 ) {
if ( V_28 )
;
else if ( V_19 -> type == type &&
F_12 ( V_19 -> V_24 , V_24 ) ) {
if ( ! V_19 -> V_22 && V_19 -> V_36 ) {
F_13 () ;
F_14 ( type , V_14 ) ;
fprintf ( V_37 , L_8
L_9 ) ;
}
V_19 -> V_22 = 1 ;
return V_19 ;
} else if ( ! V_19 -> V_22 ) {
if ( V_19 -> V_36 && V_38 ) {
F_13 () ;
fprintf ( V_37 , L_10 ) ;
F_14 ( type , V_14 ) ;
fprintf ( V_37 , L_11 ) ;
V_19 -> V_22 = 1 ;
return V_19 ;
} else {
V_30 = F_6 ( V_19 ) ?
V_39 : V_40 ;
}
} else {
F_15 ( L_12 , V_14 ) ;
return V_19 ;
}
break;
}
}
if ( V_19 ) {
struct V_13 * * V_41 ;
for ( V_41 = & V_20 [ V_17 ] ; * V_41 ; V_41 = & ( * V_41 ) -> V_21 ) {
if ( * V_41 == V_19 ) {
* V_41 = V_19 -> V_21 ;
break;
}
}
-- V_42 ;
}
V_19 = xmalloc ( sizeof( * V_19 ) ) ;
V_19 -> V_14 = V_14 ;
V_19 -> type = type ;
V_19 -> V_24 = V_24 ;
V_19 -> V_43 = NULL ;
V_19 -> V_44 = NULL ;
V_19 -> V_27 = V_27 ;
V_19 -> V_21 = V_20 [ V_17 ] ;
V_20 [ V_17 ] = V_19 ;
V_19 -> V_22 = ! V_28 ;
V_19 -> V_30 = V_30 ;
V_19 -> V_36 = 0 ;
if ( V_45 ) {
if ( V_46 [ type ] . V_14 )
fprintf ( V_47 , L_13 ,
V_46 [ type ] . V_14 , V_14 ) ;
else
fprintf ( V_47 , L_14 ,
type , V_14 ) ;
if ( V_27 )
fputs ( L_15 , V_47 ) ;
F_16 ( V_47 , V_24 ) ;
fputs ( L_16 , V_47 ) ;
}
++ V_42 ;
return V_19 ;
}
struct V_13 * F_17 ( const char * V_14 , enum V_5 type ,
struct V_23 * V_24 , int V_27 )
{
return F_7 ( V_14 , type , V_24 , V_27 , 0 ) ;
}
static struct V_13 * F_18 ( const char * V_14 , enum V_5 type ,
struct V_23 * V_24 , int V_27 )
{
return F_7 ( V_14 , type , V_24 , V_27 , 1 ) ;
}
void F_19 ( struct V_23 * V_48 )
{
free ( V_48 -> string ) ;
free ( V_48 ) ;
}
void F_8 ( struct V_23 * V_4 , struct V_23 * V_49 )
{
while ( V_4 != V_49 ) {
struct V_23 * V_26 = V_4 -> V_26 ;
F_19 ( V_4 ) ;
V_4 = V_26 ;
}
}
static struct V_23 * F_11 ( const char * string )
{
struct V_23 * V_50 ;
V_50 = xmalloc ( sizeof( * V_50 ) ) ;
V_50 -> string = F_20 ( string ) ;
V_50 -> V_25 = V_8 ;
V_50 -> V_26 = NULL ;
return V_50 ;
}
static struct V_23 * F_10 ( struct V_23 * V_51 , ... )
{
T_1 V_52 ;
struct V_23 * V_53 , * V_54 ;
if ( ! V_51 )
return NULL ;
for ( va_start ( V_52 , V_51 ) ; ( V_53 = va_arg ( V_52 , struct V_23 * ) ) ; ) {
for ( V_54 = V_53 ; V_54 -> V_26 ; V_54 = V_54 -> V_26 )
;
V_54 -> V_26 = V_51 ;
V_51 = V_53 ;
}
va_end ( V_52 ) ;
return V_51 ;
}
struct V_23 * F_21 ( struct V_23 * V_48 )
{
struct V_23 * V_50 ;
V_50 = xmalloc ( sizeof( * V_50 ) ) ;
V_50 -> string = F_20 ( V_48 -> string ) ;
V_50 -> V_25 = V_48 -> V_25 ;
return V_50 ;
}
struct V_23 * F_9 ( struct V_23 * V_51 ,
struct V_23 * V_55 )
{
struct V_23 * V_56 , * V_53 ;
if ( V_51 == V_55 )
return NULL ;
V_53 = V_56 = F_21 ( V_51 ) ;
for ( V_51 = V_51 -> V_26 ; V_51 != V_55 ; V_51 = V_51 -> V_26 ) {
V_53 -> V_26 = F_21 ( V_51 ) ;
V_53 = V_53 -> V_26 ;
}
V_53 -> V_26 = NULL ;
return V_56 ;
}
static int F_12 ( struct V_23 * V_57 , struct V_23 * V_58 )
{
while ( V_57 && V_58 ) {
if ( V_57 -> V_25 != V_58 -> V_25 || strcmp ( V_57 -> string , V_58 -> string ) )
return 0 ;
V_57 = V_57 -> V_26 ;
V_58 = V_58 -> V_26 ;
}
return ! V_57 && ! V_58 ;
}
static struct V_23 * F_22 ( T_2 * V_59 )
{
char V_60 [ 256 ] ;
struct V_23 V_48 = {
. string = V_60 ,
. V_25 = V_8 } ;
int V_1 ;
while ( ( V_1 = fgetc ( V_59 ) ) != V_61 ) {
if ( V_1 == ' ' ) {
if ( V_48 . string == V_60 )
continue;
break;
} else if ( V_1 == '\n' ) {
if ( V_48 . string == V_60 )
return NULL ;
ungetc ( V_1 , V_59 ) ;
break;
}
if ( V_48 . string >= V_60 + sizeof( V_60 ) - 1 ) {
fprintf ( V_37 , L_17 ) ;
exit ( 1 ) ;
}
* V_48 . string ++ = V_1 ;
}
if ( V_48 . string == V_60 )
return NULL ;
* V_48 . string = 0 ;
V_48 . string = V_60 ;
if ( V_48 . string [ 1 ] == '#' ) {
T_3 V_53 ;
for ( V_53 = 0 ; V_53 < F_23 ( V_46 ) ; V_53 ++ ) {
if ( V_48 . string [ 0 ] == V_46 [ V_53 ] . V_53 ) {
V_48 . V_25 = V_53 ;
V_48 . string += 2 ;
return F_21 ( & V_48 ) ;
}
}
fprintf ( V_37 , L_18 , V_48 . string [ 0 ] ) ;
exit ( 1 ) ;
}
return F_21 ( & V_48 ) ;
}
static void F_24 ( T_2 * V_59 )
{
while ( ! feof ( V_59 ) ) {
struct V_23 * V_24 = NULL ;
struct V_23 * V_19 , * V_62 ;
int V_27 = 0 , V_36 = 0 ;
struct V_13 * V_63 ;
V_19 = F_22 ( V_59 ) ;
if ( V_19 && V_19 -> V_25 == V_8 &&
! strcmp ( V_19 -> string , L_19 ) ) {
V_36 = 1 ;
F_19 ( V_19 ) ;
V_19 = F_22 ( V_59 ) ;
}
if ( ! V_19 )
continue;
V_62 = F_22 ( V_59 ) ;
if ( V_62 && V_62 -> V_25 == V_8 &&
! strcmp ( V_62 -> string , L_20 ) ) {
V_27 = 1 ;
F_19 ( V_62 ) ;
V_62 = F_22 ( V_59 ) ;
}
while ( V_62 ) {
V_62 -> V_26 = V_24 ;
V_24 = V_62 ;
V_62 = F_22 ( V_59 ) ;
}
V_63 = F_18 ( F_20 ( V_19 -> string ) , V_19 -> V_25 ,
V_24 , V_27 ) ;
V_63 -> V_36 = V_36 ;
F_19 ( V_19 ) ;
}
}
static void F_25 ( T_2 * V_59 , struct V_23 * V_64 )
{
if ( V_46 [ V_64 -> V_25 ] . V_53 ) {
putc ( V_46 [ V_64 -> V_25 ] . V_53 , V_59 ) ;
putc ( '#' , V_59 ) ;
}
fputs ( V_64 -> string , V_59 ) ;
}
static void F_16 ( T_2 * V_59 , struct V_23 * V_64 )
{
struct V_23 * * V_49 , * * V_58 ;
struct V_23 * V_65 , * * V_66 ;
int V_67 = 1 ;
if ( V_64 == NULL ) {
fputs ( L_21 , V_59 ) ;
return;
}
V_65 = V_64 ;
while ( ( V_65 = V_65 -> V_26 ) != NULL )
V_67 ++ ;
V_58 = F_26 ( V_67 * sizeof( * V_49 ) ) ;
V_49 = V_58 + V_67 ;
V_66 = V_49 - 1 ;
( * V_66 -- ) = V_64 ;
while ( ( V_64 = V_64 -> V_26 ) != NULL )
* ( V_66 -- ) = V_64 ;
while ( V_58 != V_49 ) {
F_25 ( V_59 , * V_58 ++ ) ;
putc ( ' ' , V_59 ) ;
}
}
static unsigned long F_27 ( struct V_13 * V_19 , unsigned long V_2 )
{
struct V_23 * V_64 = V_19 -> V_24 ;
struct V_23 * * V_49 , * * V_58 ;
struct V_23 * V_65 , * * V_66 ;
int V_67 = 1 ;
if ( ! V_64 )
return V_2 ;
V_65 = V_64 ;
while ( ( V_65 = V_65 -> V_26 ) != NULL )
V_67 ++ ;
V_58 = F_26 ( V_67 * sizeof( * V_49 ) ) ;
V_49 = V_58 + V_67 ;
V_66 = V_49 - 1 ;
* ( V_66 -- ) = V_64 ;
while ( ( V_64 = V_64 -> V_26 ) != NULL )
* ( V_66 -- ) = V_64 ;
while ( V_58 != V_49 ) {
struct V_23 * V_68 ;
struct V_13 * V_63 ;
V_68 = * ( V_58 ++ ) ;
switch ( V_68 -> V_25 ) {
case V_8 :
if ( V_69 )
fprintf ( V_47 , L_22 , V_68 -> string ) ;
V_2 = F_2 ( V_68 -> string , V_2 ) ;
V_2 = F_1 ( ' ' , V_2 ) ;
break;
case V_7 :
case V_9 :
V_63 = F_5 ( V_68 -> string , V_68 -> V_25 , 0 ) ;
if ( V_63 -> V_43 ) {
if ( V_69 )
fprintf ( V_47 , L_22 , V_68 -> string ) ;
V_2 = F_2 ( V_68 -> string , V_2 ) ;
V_2 = F_1 ( ' ' , V_2 ) ;
} else {
V_63 -> V_43 = V_43 ;
V_43 = V_63 ;
V_2 = F_27 ( V_63 , V_2 ) ;
}
break;
case V_11 :
case V_12 :
case V_10 :
V_63 = F_5 ( V_68 -> string , V_68 -> V_25 , 0 ) ;
if ( ! V_63 ) {
struct V_23 * V_53 ;
F_15 ( L_23 ,
V_46 [ V_68 -> V_25 ] . V_14 ,
V_68 -> string ) ;
V_53 = F_10 ( F_11
( V_46 [ V_68 -> V_25 ] . V_14 ) ,
F_11 ( V_68 -> string ) ,
F_11 ( L_3 ) ,
F_11 ( L_2 ) ,
F_11 ( L_1 ) , NULL ) ;
V_63 =
F_17 ( V_68 -> string , V_68 -> V_25 , V_53 , 0 ) ;
}
if ( V_63 -> V_43 ) {
if ( V_69 ) {
fprintf ( V_47 , L_24 ,
V_46 [ V_68 -> V_25 ] . V_14 ,
V_68 -> string ) ;
}
V_2 = F_2 ( V_46 [ V_68 -> V_25 ] . V_14 ,
V_2 ) ;
V_2 = F_1 ( ' ' , V_2 ) ;
V_2 = F_2 ( V_68 -> string , V_2 ) ;
V_2 = F_1 ( ' ' , V_2 ) ;
} else {
V_63 -> V_43 = V_43 ;
V_43 = V_63 ;
V_2 = F_27 ( V_63 , V_2 ) ;
}
break;
}
}
{
static struct V_13 * * V_55 = & V_70 ;
if ( ! V_19 -> V_44 ) {
* V_55 = V_19 ;
V_55 = & V_19 -> V_44 ;
V_19 -> V_44 = (struct V_13 * ) - 1L ;
}
}
return V_2 ;
}
void F_28 ( const char * V_14 )
{
struct V_13 * V_19 ;
V_19 = F_5 ( V_14 , V_8 , 0 ) ;
if ( ! V_19 )
F_15 ( L_25 , V_14 ) ;
else {
unsigned long V_2 ;
int V_71 = 0 ;
if ( V_69 )
fprintf ( V_47 , L_26 , V_14 ) ;
V_43 = (struct V_13 * ) - 1L ;
V_19 -> V_43 = V_43 ;
V_43 = V_19 ;
V_2 = F_27 ( V_19 , 0xffffffff ) ^ 0xffffffff ;
V_19 = V_43 ;
while ( V_19 != (struct V_13 * ) - 1L ) {
struct V_13 * V_53 = V_19 -> V_43 ;
if ( V_19 -> V_30 != V_31 ) {
if ( ! V_71 ) {
F_13 () ;
fprintf ( V_37 , L_27
L_28
L_29 , V_38 ? L_30 :
L_31 , V_14 ) ;
} else
fprintf ( V_37 , L_32 ) ;
F_14 ( V_19 -> type , V_19 -> V_14 ) ;
if ( V_19 -> V_30 == V_39 )
fprintf ( V_37 , L_33 ) ;
V_71 = 1 ;
if ( V_38 )
V_72 ++ ;
}
V_19 -> V_43 = 0 ;
V_19 = V_53 ;
}
if ( V_71 )
fprintf ( V_37 , L_34 ) ;
if ( V_69 )
fputs ( L_16 , V_47 ) ;
printf ( L_35 , V_73 , V_14 , V_2 ) ;
}
}
static void F_13 ( void )
{
fprintf ( V_37 , L_36 , V_74 ? : L_37 , V_75 ) ;
}
static void F_14 ( enum V_5 type , const char * V_14 )
{
if ( V_46 [ type ] . V_14 )
fprintf ( V_37 , L_38 , V_46 [ type ] . V_14 , V_14 ) ;
else
fprintf ( V_37 , L_39 , V_14 ) ;
}
void F_15 ( const char * V_76 , ... )
{
T_1 args ;
if ( V_77 ) {
F_13 () ;
va_start ( args , V_76 ) ;
vfprintf ( V_37 , V_76 , args ) ;
va_end ( args ) ;
putc ( '\n' , V_37 ) ;
V_72 ++ ;
}
}
static void F_29 ( void )
{
fputs ( L_40 L_41 L_34
#ifdef F_30
L_42
L_43
L_44
L_45
L_46
L_47
L_48
L_49
L_50
L_51
#else
L_52
L_53
L_54
L_55
L_56
L_57
L_58
L_59
L_60
L_61
#endif
, V_37 ) ;
}
int main ( int V_78 , char * * V_79 )
{
T_2 * V_80 = NULL , * V_81 = NULL ;
int V_82 ;
#ifdef F_30
struct V_83 V_84 [] = {
{ L_62 , 1 , 0 , 's' } ,
{ L_63 , 0 , 0 , 'd' } ,
{ L_64 , 0 , 0 , 'w' } ,
{ L_65 , 0 , 0 , 'q' } ,
{ L_66 , 0 , 0 , 'D' } ,
{ L_67 , 1 , 0 , 'r' } ,
{ L_68 , 1 , 0 , 'T' } ,
{ L_69 , 0 , 0 , 'p' } ,
{ L_70 , 0 , 0 , 'V' } ,
{ L_71 , 0 , 0 , 'h' } ,
{ 0 , 0 , 0 , 0 }
} ;
while ( ( V_82 = F_31 ( V_78 , V_79 , L_72 ,
& V_84 [ 0 ] , NULL ) ) != V_61 )
#else
while ( ( V_82 = F_32 ( V_78 , V_79 , L_72 ) ) != V_61 )
#endif
switch ( V_82 ) {
case 's' :
V_73 = V_85 ;
break;
case 'd' :
V_45 ++ ;
break;
case 'w' :
V_77 = 1 ;
break;
case 'q' :
V_77 = 0 ;
break;
case 'V' :
fputs ( L_73 , V_37 ) ;
break;
case 'D' :
V_69 = 1 ;
break;
case 'r' :
V_86 = 1 ;
V_81 = fopen ( V_85 , L_74 ) ;
if ( ! V_81 ) {
perror ( V_85 ) ;
return 1 ;
}
break;
case 'T' :
V_87 = 1 ;
V_80 = fopen ( V_85 , L_75 ) ;
if ( ! V_80 ) {
perror ( V_85 ) ;
return 1 ;
}
break;
case 'p' :
V_38 = 1 ;
break;
case 'h' :
F_29 () ;
return 0 ;
default:
F_29 () ;
return 1 ;
}
{
extern int V_88 ;
extern int V_89 ;
V_88 = ( V_45 > 1 ) ;
V_89 = ( V_45 > 2 ) ;
V_47 = V_37 ;
}
if ( V_86 ) {
F_24 ( V_81 ) ;
fclose ( V_81 ) ;
}
F_33 () ;
if ( V_87 && V_70 ) {
while ( V_70 != (struct V_13 * ) - 1L ) {
struct V_13 * V_19 = V_70 ;
if ( V_19 -> V_36 )
fputs ( L_76 , V_80 ) ;
if ( V_46 [ V_19 -> type ] . V_53 ) {
putc ( V_46 [ V_19 -> type ] . V_53 , V_80 ) ;
putc ( '#' , V_80 ) ;
}
fputs ( V_19 -> V_14 , V_80 ) ;
putc ( ' ' , V_80 ) ;
if ( V_19 -> V_27 )
fputs ( L_15 , V_80 ) ;
F_16 ( V_80 , V_19 -> V_24 ) ;
putc ( '\n' , V_80 ) ;
V_70 = V_19 -> V_44 ;
V_19 -> V_44 = NULL ;
}
}
if ( V_45 ) {
fprintf ( V_47 , L_77 ,
V_42 , V_18 ,
( double ) V_42 / ( double ) V_18 ) ;
}
return V_72 != 0 ;
}
