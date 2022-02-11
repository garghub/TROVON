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
static int F_10 ( const char * * * V_9 , int * V_10 , int * V_11 )
{
int V_12 = 0 ;
while ( * V_10 > 0 ) {
const char * V_6 = ( * V_9 ) [ 0 ] ;
if ( V_6 [ 0 ] != '-' )
break;
if ( ! strcmp ( V_6 , L_5 ) || ! strcmp ( V_6 , L_6 ) )
break;
if ( ! F_2 ( V_6 , V_13 ) ) {
V_6 += strlen ( V_13 ) ;
if ( * V_6 == '=' )
F_11 ( V_6 + 1 ) ;
else {
puts ( F_12 () ) ;
exit ( 0 ) ;
}
} else if ( ! strcmp ( V_6 , L_7 ) ) {
puts ( F_13 ( V_14 ) ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_8 ) || ! strcmp ( V_6 , L_9 ) ) {
V_8 = 1 ;
} else if ( ! strcmp ( V_6 , L_10 ) ) {
V_8 = 0 ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_11 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_12 ) ;
F_14 ( V_16 ) ;
}
F_9 ( V_17 , ( * V_9 ) [ 1 ] , 1 ) ;
if ( V_11 )
* V_11 = 1 ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
V_12 ++ ;
} else if ( ! F_2 ( V_6 , V_18 ) ) {
F_9 ( V_17 , V_6 + strlen ( V_18 ) , 1 ) ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_13 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_14 ) ;
F_14 ( V_16 ) ;
}
F_9 ( V_19 , ( * V_9 ) [ 1 ] , 1 ) ;
if ( V_11 )
* V_11 = 1 ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else if ( ! F_2 ( V_6 , V_20 ) ) {
F_9 ( V_19 , V_6 + strlen ( V_20 ) , 1 ) ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_15 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_16 ) ;
F_14 ( V_16 ) ;
}
F_15 ( ( * V_9 ) [ 1 ] ) ;
if ( V_11 )
* V_11 = 1 ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else if ( ! F_2 ( V_6 , V_21 ) ) {
F_15 ( V_6 + strlen ( V_21 ) ) ;
fprintf ( V_15 , L_17 , V_22 ) ;
if ( V_11 )
* V_11 = 1 ;
} else {
fprintf ( V_15 , L_18 , V_6 ) ;
F_14 ( V_16 ) ;
}
( * V_9 ) ++ ;
( * V_10 ) -- ;
V_12 ++ ;
}
return V_12 ;
}
static int F_16 ( int * V_23 , const char * * * V_9 )
{
int V_11 = 0 , V_24 = 0 , V_25 = V_26 ;
int V_27 , V_28 ;
const char * * V_29 ;
const char * V_30 ;
char * V_31 ;
V_30 = ( * V_9 ) [ 0 ] ;
V_31 = F_17 ( V_30 ) ;
if ( V_31 ) {
if ( V_31 [ 0 ] == '!' ) {
if ( * V_23 > 1 ) {
struct V_32 V_33 ;
F_18 ( & V_33 , V_34 ) ;
F_19 ( & V_33 , V_31 ) ;
F_20 ( & V_33 , ( * V_9 ) + 1 , V_34 ) ;
free ( V_31 ) ;
V_31 = V_33 . V_33 ;
}
V_24 = system ( V_31 + 1 ) ;
if ( V_24 >= 0 && F_21 ( V_24 ) &&
F_22 ( V_24 ) != 127 )
exit ( F_22 ( V_24 ) ) ;
F_23 ( L_19 ,
V_31 + 1 , V_30 ) ;
}
V_27 = F_24 ( V_31 , & V_29 ) ;
if ( V_27 < 0 )
F_23 ( L_20 , V_30 ) ;
V_28 = F_10 ( & V_29 , & V_27 , & V_11 ) ;
if ( V_11 )
F_23 ( L_21
L_22 ,
V_30 ) ;
memmove ( V_29 - V_28 , V_29 ,
V_27 * sizeof( char * ) ) ;
V_29 -= V_28 ;
if ( V_27 < 1 )
F_23 ( L_23 , V_30 ) ;
if ( ! strcmp ( V_30 , V_29 [ 0 ] ) )
F_23 ( L_24 , V_30 ) ;
V_29 = realloc ( V_29 , sizeof( char * ) *
( V_27 + * V_23 + 1 ) ) ;
memcpy ( V_29 + V_27 , * V_9 + 1 , sizeof( char * ) * * V_23 ) ;
V_29 [ V_27 + * V_23 ] = NULL ;
* V_9 = V_29 ;
* V_23 += V_27 - 1 ;
V_24 = 1 ;
}
V_26 = V_25 ;
return V_24 ;
}
static int F_25 ( struct V_35 * V_36 , int V_10 , const char * * V_9 )
{
int V_37 ;
struct V_38 V_39 ;
const char * V_40 ;
V_40 = NULL ;
if ( V_36 -> V_41 & V_42 )
V_40 = NULL ;
if ( V_43 == - 1 )
V_43 = F_7 ( V_36 -> V_6 ) ;
if ( V_8 == - 1 && V_36 -> V_41 & V_42 )
V_8 = F_4 ( V_36 -> V_6 ) ;
if ( V_8 == - 1 && V_36 -> V_41 & V_44 )
V_8 = 1 ;
F_8 () ;
V_37 = V_36 -> V_45 ( V_10 , V_9 , V_40 ) ;
F_26 ( V_37 ) ;
if ( V_37 )
return V_37 & 0xff ;
if ( F_27 ( fileno ( stdout ) , & V_39 ) )
return 0 ;
if ( F_28 ( V_39 . V_46 ) || F_29 ( V_39 . V_46 ) )
return 0 ;
if ( fflush ( stdout ) )
F_23 ( L_25 , strerror ( V_26 ) ) ;
if ( ferror ( stdout ) )
F_23 ( L_26 ) ;
if ( fclose ( stdout ) )
F_23 ( L_27 , strerror ( V_26 ) ) ;
return 0 ;
}
static void F_30 ( int V_10 , const char * * V_9 )
{
const char * V_6 = V_9 [ 0 ] ;
static struct V_35 V_47 [] = {
{ L_28 , V_48 , 0 } ,
{ L_29 , V_49 , 0 } ,
{ L_30 , V_50 , 0 } ,
{ L_31 , V_51 , 0 } ,
{ L_32 , V_52 , 0 } ,
{ L_33 , V_53 , 0 } ,
{ L_34 , V_54 , 0 } ,
{ L_35 , V_55 , 0 } ,
{ L_36 , V_56 , 0 } ,
{ L_37 , V_57 , 0 } ,
{ L_38 , V_58 , 0 } ,
{ L_39 , V_59 , 0 } ,
{ L_40 , V_60 , 0 } ,
{ L_41 , V_61 , 0 } ,
{ L_42 , V_62 , 0 } ,
{ L_43 , V_63 , 0 } ,
{ L_44 , V_64 , 0 } ,
{ L_45 , V_65 , 0 } ,
{ L_46 , V_66 , 0 } ,
{ L_47 , V_67 , 0 } ,
{ L_48 , V_68 , 0 } ,
{ L_49 , V_69 , 0 } ,
} ;
unsigned int V_70 ;
static const char V_71 [] = V_72 ;
if ( sizeof( V_71 ) > 1 ) {
V_70 = strlen ( V_9 [ 0 ] ) - strlen ( V_71 ) ;
if ( V_70 > 0 && ! strcmp ( V_9 [ 0 ] + V_70 , V_71 ) ) {
char * V_73 = F_31 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = V_6 = V_73 ;
V_73 [ V_70 ] = '\0' ;
}
}
if ( V_10 > 1 && ! strcmp ( V_9 [ 1 ] , L_5 ) ) {
V_9 [ 1 ] = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 = L_32 ;
}
for ( V_70 = 0 ; V_70 < F_32 ( V_47 ) ; V_70 ++ ) {
struct V_35 * V_36 = V_47 + V_70 ;
if ( strcmp ( V_36 -> V_6 , V_6 ) )
continue;
exit ( F_25 ( V_36 , V_10 , V_9 ) ) ;
}
}
static void F_33 ( const char * * V_9 )
{
struct V_32 V_6 = V_74 ;
const char * V_75 ;
int V_37 ;
F_34 ( & V_6 , L_50 , V_9 [ 0 ] ) ;
V_75 = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 . V_33 ;
V_37 = F_35 ( V_9 , 0 ) ;
if ( V_37 != - V_76 ) {
if ( F_36 ( V_37 ) )
F_23 ( L_51 , V_9 [ 0 ] ) ;
exit ( - V_37 ) ;
}
V_26 = V_77 ;
V_9 [ 0 ] = V_75 ;
F_37 ( & V_6 ) ;
}
static int F_38 ( int * V_23 , const char * * * V_9 )
{
int V_78 = 0 ;
while ( 1 ) {
F_30 ( * V_23 , * V_9 ) ;
F_33 ( * V_9 ) ;
if ( V_78 || ! F_16 ( V_23 , V_9 ) )
break;
V_78 = 1 ;
}
return V_78 ;
}
static void F_39 ( void )
{
T_1 V_79 ;
F_40 ( & V_79 ) ;
F_41 ( & V_79 , V_80 ) ;
F_42 ( V_81 , & V_79 , NULL ) ;
}
void F_43 ( void )
{
T_1 V_79 ;
F_40 ( & V_79 ) ;
F_41 ( & V_79 , V_80 ) ;
F_42 ( V_82 , & V_79 , NULL ) ;
}
int main ( int V_10 , const char * * V_9 )
{
const char * V_6 ;
V_6 = F_44 ( V_9 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_52 ;
F_45 ( NULL ) ;
if ( ! F_2 ( V_6 , L_53 ) ) {
V_6 += 5 ;
V_9 [ 0 ] = V_6 ;
F_30 ( V_10 , V_9 ) ;
F_23 ( L_54 , V_6 ) ;
}
V_9 ++ ;
V_10 -- ;
F_10 ( & V_9 , & V_10 , NULL ) ;
F_8 () ;
F_46 () ;
if ( V_10 > 0 ) {
if ( ! F_2 ( V_9 [ 0 ] , L_55 ) )
V_9 [ 0 ] += 2 ;
} else {
printf ( L_56 , V_16 ) ;
F_47 () ;
printf ( L_57 , V_83 ) ;
exit ( 1 ) ;
}
V_6 = V_9 [ 0 ] ;
F_48 () ;
F_39 () ;
while ( 1 ) {
static int V_84 ;
static int V_85 ;
V_85 = F_38 ( & V_10 , & V_9 ) ;
if ( V_26 != V_77 )
break;
if ( V_85 ) {
fprintf ( V_15 , L_58
L_59 ,
V_6 , V_9 [ 0 ] ) ;
exit ( 1 ) ;
}
if ( ! V_84 ) {
V_6 = V_9 [ 0 ] = F_49 ( V_6 ) ;
V_84 = 1 ;
} else
break;
}
fprintf ( V_15 , L_60 ,
V_6 , strerror ( V_26 ) ) ;
return 1 ;
}
