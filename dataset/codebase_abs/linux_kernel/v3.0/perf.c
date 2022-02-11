static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! F_2 ( V_1 , L_1 ) && ! strcmp ( V_1 + 6 , V_5 -> V_6 ) )
V_5 -> V_7 = F_3 ( V_1 , V_2 ) ;
return 0 ;
}
int F_4 ( const char * V_6 )
{
struct V_4 V_5 ;
V_5 . V_6 = V_6 ;
V_5 . V_7 = - 1 ;
F_5 ( F_1 , & V_5 ) ;
return V_5 . V_7 ;
}
static int F_6 ( const char * V_1 , const char * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! F_2 ( V_1 , L_2 ) && ! strcmp ( V_1 + 4 , V_5 -> V_6 ) )
V_5 -> V_7 = F_3 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_7 ( const char * V_6 )
{
struct V_4 V_5 ;
V_5 . V_6 = V_6 ;
V_5 . V_7 = - 1 ;
F_5 ( F_6 , & V_5 ) ;
return V_5 . V_7 ;
}
static void F_8 ( void )
{
switch ( V_8 ) {
case 0 :
F_9 ( L_3 , L_4 , 1 ) ;
break;
case 1 :
break;
default:
break;
}
}
static void F_10 ( void )
{
char * V_9 ;
V_9 = getenv ( V_10 ) ;
snprintf ( V_11 , V_12 , L_5 , V_9 ? : V_13 ,
L_6 ) ;
}
static int F_11 ( const char * * * V_14 , int * V_15 , int * V_16 )
{
int V_17 = 0 ;
while ( * V_15 > 0 ) {
const char * V_6 = ( * V_14 ) [ 0 ] ;
if ( V_6 [ 0 ] != '-' )
break;
if ( ! strcmp ( V_6 , L_7 ) || ! strcmp ( V_6 , L_8 ) )
break;
if ( ! F_2 ( V_6 , V_18 ) ) {
V_6 += strlen ( V_18 ) ;
if ( * V_6 == '=' )
F_12 ( V_6 + 1 ) ;
else {
puts ( F_13 () ) ;
exit ( 0 ) ;
}
} else if ( ! strcmp ( V_6 , L_9 ) ) {
puts ( F_14 ( V_19 ) ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_10 ) || ! strcmp ( V_6 , L_11 ) ) {
V_8 = 1 ;
} else if ( ! strcmp ( V_6 , L_12 ) ) {
V_8 = 0 ;
if ( V_16 )
* V_16 = 1 ;
} else if ( ! strcmp ( V_6 , L_13 ) ) {
if ( * V_15 < 2 ) {
fprintf ( V_20 , L_14 ) ;
F_15 ( V_21 ) ;
}
F_9 ( V_22 , ( * V_14 ) [ 1 ] , 1 ) ;
if ( V_16 )
* V_16 = 1 ;
( * V_14 ) ++ ;
( * V_15 ) -- ;
V_17 ++ ;
} else if ( ! F_2 ( V_6 , V_23 ) ) {
F_9 ( V_22 , V_6 + strlen ( V_23 ) , 1 ) ;
if ( V_16 )
* V_16 = 1 ;
} else if ( ! strcmp ( V_6 , L_15 ) ) {
if ( * V_15 < 2 ) {
fprintf ( V_20 , L_16 ) ;
F_15 ( V_21 ) ;
}
F_9 ( V_24 , ( * V_14 ) [ 1 ] , 1 ) ;
if ( V_16 )
* V_16 = 1 ;
( * V_14 ) ++ ;
( * V_15 ) -- ;
} else if ( ! F_2 ( V_6 , V_25 ) ) {
F_9 ( V_24 , V_6 + strlen ( V_25 ) , 1 ) ;
if ( V_16 )
* V_16 = 1 ;
} else if ( ! strcmp ( V_6 , L_17 ) ) {
if ( * V_15 < 2 ) {
fprintf ( V_20 , L_18 ) ;
F_15 ( V_21 ) ;
}
strncpy ( V_13 , ( * V_14 ) [ 1 ] , V_12 ) ;
V_13 [ V_12 - 1 ] = '\0' ;
if ( V_16 )
* V_16 = 1 ;
( * V_14 ) ++ ;
( * V_15 ) -- ;
} else if ( ! F_2 ( V_6 , V_26 ) ) {
strncpy ( V_13 , V_6 + strlen ( V_26 ) , V_12 ) ;
V_13 [ V_12 - 1 ] = '\0' ;
if ( V_16 )
* V_16 = 1 ;
} else {
fprintf ( V_20 , L_19 , V_6 ) ;
F_15 ( V_21 ) ;
}
( * V_14 ) ++ ;
( * V_15 ) -- ;
V_17 ++ ;
}
return V_17 ;
}
static int F_16 ( int * V_27 , const char * * * V_14 )
{
int V_16 = 0 , V_28 = 0 , V_29 = V_30 ;
int V_31 , V_32 ;
const char * * V_33 ;
const char * V_34 ;
char * V_35 ;
V_34 = ( * V_14 ) [ 0 ] ;
V_35 = F_17 ( V_34 ) ;
if ( V_35 ) {
if ( V_35 [ 0 ] == '!' ) {
if ( * V_27 > 1 ) {
struct V_36 V_37 ;
F_18 ( & V_37 , V_38 ) ;
F_19 ( & V_37 , V_35 ) ;
F_20 ( & V_37 , ( * V_14 ) + 1 , V_38 ) ;
free ( V_35 ) ;
V_35 = V_37 . V_37 ;
}
V_28 = system ( V_35 + 1 ) ;
if ( V_28 >= 0 && F_21 ( V_28 ) &&
F_22 ( V_28 ) != 127 )
exit ( F_22 ( V_28 ) ) ;
F_23 ( L_20 ,
V_35 + 1 , V_34 ) ;
}
V_31 = F_24 ( V_35 , & V_33 ) ;
if ( V_31 < 0 )
F_23 ( L_21 , V_34 ) ;
V_32 = F_11 ( & V_33 , & V_31 , & V_16 ) ;
if ( V_16 )
F_23 ( L_22
L_23 ,
V_34 ) ;
memmove ( V_33 - V_32 , V_33 ,
V_31 * sizeof( char * ) ) ;
V_33 -= V_32 ;
if ( V_31 < 1 )
F_23 ( L_24 , V_34 ) ;
if ( ! strcmp ( V_34 , V_33 [ 0 ] ) )
F_23 ( L_25 , V_34 ) ;
V_33 = realloc ( V_33 , sizeof( char * ) *
( V_31 + * V_27 + 1 ) ) ;
memcpy ( V_33 + V_31 , * V_14 + 1 , sizeof( char * ) * * V_27 ) ;
V_33 [ V_31 + * V_27 ] = NULL ;
* V_14 = V_33 ;
* V_27 += V_31 - 1 ;
V_28 = 1 ;
}
V_30 = V_29 ;
return V_28 ;
}
static int F_25 ( struct V_39 * V_40 , int V_15 , const char * * V_14 )
{
int V_41 ;
struct V_42 V_43 ;
const char * V_44 ;
V_44 = NULL ;
if ( V_40 -> V_45 & V_46 )
V_44 = NULL ;
if ( V_47 == - 1 )
V_47 = F_7 ( V_40 -> V_6 ) ;
if ( V_8 == - 1 && V_40 -> V_45 & V_46 )
V_8 = F_4 ( V_40 -> V_6 ) ;
if ( V_8 == - 1 && V_40 -> V_45 & V_48 )
V_8 = 1 ;
F_8 () ;
F_10 () ;
V_41 = V_40 -> V_49 ( V_15 , V_14 , V_44 ) ;
F_26 ( V_41 ) ;
if ( V_41 )
return V_41 & 0xff ;
if ( F_27 ( fileno ( stdout ) , & V_43 ) )
return 0 ;
if ( F_28 ( V_43 . V_50 ) || F_29 ( V_43 . V_50 ) )
return 0 ;
if ( fflush ( stdout ) )
F_23 ( L_26 , strerror ( V_30 ) ) ;
if ( ferror ( stdout ) )
F_23 ( L_27 ) ;
if ( fclose ( stdout ) )
F_23 ( L_28 , strerror ( V_30 ) ) ;
return 0 ;
}
static void F_30 ( int V_15 , const char * * V_14 )
{
const char * V_6 = V_14 [ 0 ] ;
static struct V_39 V_51 [] = {
{ L_29 , V_52 , 0 } ,
{ L_30 , V_53 , 0 } ,
{ L_31 , V_54 , 0 } ,
{ L_32 , V_55 , 0 } ,
{ L_33 , V_56 , 0 } ,
{ L_34 , V_57 , 0 } ,
{ L_35 , V_58 , 0 } ,
{ L_36 , V_59 , 0 } ,
{ L_37 , V_60 , 0 } ,
{ L_38 , V_61 , 0 } ,
{ L_39 , V_62 , 0 } ,
{ L_40 , V_63 , 0 } ,
{ L_41 , V_64 , 0 } ,
{ L_42 , V_65 , 0 } ,
{ L_43 , V_66 , 0 } ,
{ L_44 , V_67 , 0 } ,
{ L_45 , V_68 , 0 } ,
{ L_46 , V_69 , 0 } ,
{ L_47 , V_70 , 0 } ,
{ L_48 , V_71 , 0 } ,
{ L_49 , V_72 , 0 } ,
{ L_50 , V_73 , 0 } ,
} ;
unsigned int V_74 ;
static const char V_75 [] = V_76 ;
if ( sizeof( V_75 ) > 1 ) {
V_74 = strlen ( V_14 [ 0 ] ) - strlen ( V_75 ) ;
if ( V_74 > 0 && ! strcmp ( V_14 [ 0 ] + V_74 , V_75 ) ) {
char * V_77 = F_31 ( V_14 [ 0 ] ) ;
V_14 [ 0 ] = V_6 = V_77 ;
V_77 [ V_74 ] = '\0' ;
}
}
if ( V_15 > 1 && ! strcmp ( V_14 [ 1 ] , L_7 ) ) {
V_14 [ 1 ] = V_14 [ 0 ] ;
V_14 [ 0 ] = V_6 = L_33 ;
}
for ( V_74 = 0 ; V_74 < F_32 ( V_51 ) ; V_74 ++ ) {
struct V_39 * V_40 = V_51 + V_74 ;
if ( strcmp ( V_40 -> V_6 , V_6 ) )
continue;
exit ( F_25 ( V_40 , V_15 , V_14 ) ) ;
}
}
static void F_33 ( const char * * V_14 )
{
struct V_36 V_6 = V_78 ;
const char * V_79 ;
int V_41 ;
F_34 ( & V_6 , L_51 , V_14 [ 0 ] ) ;
V_79 = V_14 [ 0 ] ;
V_14 [ 0 ] = V_6 . V_37 ;
V_41 = F_35 ( V_14 , 0 ) ;
if ( V_41 != - V_80 ) {
if ( F_36 ( V_41 ) )
F_23 ( L_52 , V_14 [ 0 ] ) ;
exit ( - V_41 ) ;
}
V_30 = V_81 ;
V_14 [ 0 ] = V_79 ;
F_37 ( & V_6 ) ;
}
static int F_38 ( int * V_27 , const char * * * V_14 )
{
int V_82 = 0 ;
while ( 1 ) {
F_30 ( * V_27 , * V_14 ) ;
F_33 ( * V_14 ) ;
if ( V_82 || ! F_16 ( V_27 , V_14 ) )
break;
V_82 = 1 ;
}
return V_82 ;
}
static void F_39 ( void )
{
const char * V_9 = F_40 ( NULL ) ;
if ( V_9 )
strncpy ( V_13 , V_9 , sizeof( V_13 ) ) ;
else
V_13 [ 0 ] = '\0' ;
}
int main ( int V_15 , const char * * V_14 )
{
const char * V_6 ;
V_6 = F_41 ( V_14 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_53 ;
F_39 () ;
if ( ! F_2 ( V_6 , L_54 ) ) {
V_6 += 5 ;
V_14 [ 0 ] = V_6 ;
F_30 ( V_15 , V_14 ) ;
F_23 ( L_55 , V_6 ) ;
}
V_14 ++ ;
V_15 -- ;
F_11 ( & V_14 , & V_15 , NULL ) ;
F_8 () ;
F_10 () ;
F_42 () ;
if ( V_15 > 0 ) {
if ( ! F_2 ( V_14 [ 0 ] , L_56 ) )
V_14 [ 0 ] += 2 ;
} else {
printf ( L_57 , V_21 ) ;
F_43 () ;
printf ( L_58 , V_83 ) ;
exit ( 1 ) ;
}
V_6 = V_14 [ 0 ] ;
F_44 () ;
while ( 1 ) {
static int V_84 ;
static int V_85 ;
V_85 = F_38 ( & V_15 , & V_14 ) ;
if ( V_30 != V_81 )
break;
if ( V_85 ) {
fprintf ( V_20 , L_59
L_60 ,
V_6 , V_14 [ 0 ] ) ;
exit ( 1 ) ;
}
if ( ! V_84 ) {
V_6 = V_14 [ 0 ] = F_45 ( V_6 ) ;
V_84 = 1 ;
} else
break;
}
fprintf ( V_20 , L_61 ,
V_6 , strerror ( V_30 ) ) ;
return 1 ;
}
