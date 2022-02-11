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
} else if ( ! strcmp ( V_6 , L_18 ) ) {
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_16 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
printf ( L_19 , V_26 -> V_6 ) ;
}
exit ( 0 ) ;
} else {
fprintf ( V_15 , L_20 , V_6 ) ;
F_14 ( V_16 ) ;
}
( * V_9 ) ++ ;
( * V_10 ) -- ;
V_12 ++ ;
}
return V_12 ;
}
static int F_17 ( int * V_27 , const char * * * V_9 )
{
int V_11 = 0 , V_28 = 0 , V_29 = V_30 ;
int V_31 , V_32 ;
const char * * V_33 ;
const char * V_34 ;
char * V_35 ;
V_34 = ( * V_9 ) [ 0 ] ;
V_35 = F_18 ( V_34 ) ;
if ( V_35 ) {
if ( V_35 [ 0 ] == '!' ) {
if ( * V_27 > 1 ) {
struct V_36 V_37 ;
F_19 ( & V_37 , V_38 ) ;
F_20 ( & V_37 , V_35 ) ;
F_21 ( & V_37 , ( * V_9 ) + 1 , V_38 ) ;
free ( V_35 ) ;
V_35 = V_37 . V_37 ;
}
V_28 = system ( V_35 + 1 ) ;
if ( V_28 >= 0 && F_22 ( V_28 ) &&
F_23 ( V_28 ) != 127 )
exit ( F_23 ( V_28 ) ) ;
F_24 ( L_21 ,
V_35 + 1 , V_34 ) ;
}
V_31 = F_25 ( V_35 , & V_33 ) ;
if ( V_31 < 0 )
F_24 ( L_22 , V_34 ) ;
V_32 = F_10 ( & V_33 , & V_31 , & V_11 ) ;
if ( V_11 )
F_24 ( L_23
L_24 ,
V_34 ) ;
memmove ( V_33 - V_32 , V_33 ,
V_31 * sizeof( char * ) ) ;
V_33 -= V_32 ;
if ( V_31 < 1 )
F_24 ( L_25 , V_34 ) ;
if ( ! strcmp ( V_34 , V_33 [ 0 ] ) )
F_24 ( L_26 , V_34 ) ;
V_33 = realloc ( V_33 , sizeof( char * ) *
( V_31 + * V_27 + 1 ) ) ;
memcpy ( V_33 + V_31 , * V_9 + 1 , sizeof( char * ) * * V_27 ) ;
V_33 [ V_31 + * V_27 ] = NULL ;
* V_9 = V_33 ;
* V_27 += V_31 - 1 ;
V_28 = 1 ;
}
V_30 = V_29 ;
return V_28 ;
}
static int F_26 ( struct V_25 * V_26 , int V_10 , const char * * V_9 )
{
int V_39 ;
struct V_40 V_41 ;
const char * V_42 ;
V_42 = NULL ;
if ( V_26 -> V_43 & V_44 )
V_42 = NULL ;
if ( V_45 == - 1 )
V_45 = F_7 ( V_26 -> V_6 ) ;
if ( V_8 == - 1 && V_26 -> V_43 & V_44 )
V_8 = F_4 ( V_26 -> V_6 ) ;
if ( V_8 == - 1 && V_26 -> V_43 & V_46 )
V_8 = 1 ;
F_8 () ;
V_39 = V_26 -> V_47 ( V_10 , V_9 , V_42 ) ;
F_27 ( V_39 ) ;
if ( V_39 )
return V_39 & 0xff ;
if ( F_28 ( fileno ( stdout ) , & V_41 ) )
return 0 ;
if ( F_29 ( V_41 . V_48 ) || F_30 ( V_41 . V_48 ) )
return 0 ;
if ( fflush ( stdout ) )
F_24 ( L_27 , strerror ( V_30 ) ) ;
if ( ferror ( stdout ) )
F_24 ( L_28 ) ;
if ( fclose ( stdout ) )
F_24 ( L_29 , strerror ( V_30 ) ) ;
return 0 ;
}
static void F_31 ( int V_10 , const char * * V_9 )
{
const char * V_6 = V_9 [ 0 ] ;
unsigned int V_23 ;
static const char V_49 [] = V_50 ;
if ( sizeof( V_49 ) > 1 ) {
V_23 = strlen ( V_9 [ 0 ] ) - strlen ( V_49 ) ;
if ( V_23 > 0 && ! strcmp ( V_9 [ 0 ] + V_23 , V_49 ) ) {
char * V_51 = F_32 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = V_6 = V_51 ;
V_51 [ V_23 ] = '\0' ;
}
}
if ( V_10 > 1 && ! strcmp ( V_9 [ 1 ] , L_5 ) ) {
V_9 [ 1 ] = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 = L_30 ;
}
for ( V_23 = 0 ; V_23 < F_16 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
if ( strcmp ( V_26 -> V_6 , V_6 ) )
continue;
exit ( F_26 ( V_26 , V_10 , V_9 ) ) ;
}
}
static void F_33 ( const char * * V_9 )
{
struct V_36 V_6 = V_52 ;
const char * V_53 ;
int V_39 ;
F_34 ( & V_6 , L_31 , V_9 [ 0 ] ) ;
V_53 = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 . V_37 ;
V_39 = F_35 ( V_9 , 0 ) ;
if ( V_39 != - V_54 ) {
if ( F_36 ( V_39 ) )
F_24 ( L_32 , V_9 [ 0 ] ) ;
exit ( - V_39 ) ;
}
V_30 = V_55 ;
V_9 [ 0 ] = V_53 ;
F_37 ( & V_6 ) ;
}
static int F_38 ( int * V_27 , const char * * * V_9 )
{
int V_56 = 0 ;
while ( 1 ) {
F_31 ( * V_27 , * V_9 ) ;
F_33 ( * V_9 ) ;
if ( V_56 || ! F_17 ( V_27 , V_9 ) )
break;
V_56 = 1 ;
}
return V_56 ;
}
static void F_39 ( void )
{
T_1 V_57 ;
F_40 ( & V_57 ) ;
F_41 ( & V_57 , V_58 ) ;
F_42 ( V_59 , & V_57 , NULL ) ;
}
void F_43 ( void )
{
T_1 V_57 ;
F_40 ( & V_57 ) ;
F_41 ( & V_57 , V_58 ) ;
F_42 ( V_60 , & V_57 , NULL ) ;
}
int main ( int V_10 , const char * * V_9 )
{
const char * V_6 ;
V_6 = F_44 ( V_9 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_33 ;
F_45 ( NULL ) ;
if ( ! F_2 ( V_6 , L_34 ) ) {
V_6 += 5 ;
V_9 [ 0 ] = V_6 ;
F_31 ( V_10 , V_9 ) ;
F_24 ( L_35 , V_6 ) ;
}
V_9 ++ ;
V_10 -- ;
F_10 ( & V_9 , & V_10 , NULL ) ;
F_8 () ;
F_46 () ;
if ( V_10 > 0 ) {
if ( ! F_2 ( V_9 [ 0 ] , L_36 ) )
V_9 [ 0 ] += 2 ;
} else {
printf ( L_37 , V_16 ) ;
F_47 () ;
printf ( L_38 , V_61 ) ;
exit ( 1 ) ;
}
V_6 = V_9 [ 0 ] ;
F_48 () ;
F_39 () ;
while ( 1 ) {
static int V_62 ;
static int V_63 ;
V_63 = F_38 ( & V_10 , & V_9 ) ;
if ( V_30 != V_55 )
break;
if ( V_63 ) {
fprintf ( V_15 , L_39
L_40 ,
V_6 , V_9 [ 0 ] ) ;
exit ( 1 ) ;
}
if ( ! V_62 ) {
V_6 = V_9 [ 0 ] = F_49 ( V_6 ) ;
V_62 = 1 ;
} else
break;
}
fprintf ( V_15 , L_41 ,
V_6 , strerror ( V_30 ) ) ;
return 1 ;
}
