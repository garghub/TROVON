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
if ( ! F_2 ( V_1 , L_3 ) && ! strcmp ( V_1 + 4 , V_5 -> V_6 ) )
V_5 -> V_7 = F_3 ( V_1 , V_2 ) ? 2 : 0 ;
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
F_9 ( L_4 , L_5 , 1 ) ;
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
if ( ! strcmp ( V_6 , L_6 ) || ! strcmp ( V_6 , L_7 ) )
break;
if ( ! strcmp ( V_6 , L_8 ) ) {
( * V_9 ) [ 0 ] = L_6 ;
break;
}
if ( ! strcmp ( V_6 , L_9 ) ) {
( * V_9 ) [ 0 ] = L_7 ;
break;
}
if ( ! F_2 ( V_6 , V_13 ) ) {
V_6 += strlen ( V_13 ) ;
if ( * V_6 == '=' )
F_11 ( V_6 + 1 ) ;
else {
puts ( F_12 () ) ;
exit ( 0 ) ;
}
} else if ( ! strcmp ( V_6 , L_10 ) ) {
puts ( F_13 ( V_14 ) ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_11 ) || ! strcmp ( V_6 , L_12 ) ) {
V_8 = 1 ;
} else if ( ! strcmp ( V_6 , L_13 ) ) {
V_8 = 0 ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_14 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_15 ) ;
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
} else if ( ! strcmp ( V_6 , L_16 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_17 ) ;
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
} else if ( ! strcmp ( V_6 , L_18 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_19 ) ;
F_14 ( V_16 ) ;
}
F_15 ( ( * V_9 ) [ 1 ] ) ;
if ( V_11 )
* V_11 = 1 ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else if ( ! strcmp ( V_6 , L_20 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_21 ) ;
F_14 ( V_16 ) ;
}
F_16 ( ( * V_9 ) [ 1 ] ) ;
if ( V_11 )
* V_11 = 1 ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else if ( ! F_2 ( V_6 , V_21 ) ) {
F_15 ( V_6 + strlen ( V_21 ) ) ;
fprintf ( V_15 , L_22 , V_22 ) ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_23 ) ) {
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_17 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
printf ( L_24 , V_26 -> V_6 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_25 ) ) {
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_17 ( V_27 ) - 1 ; V_23 ++ ) {
struct V_28 * V_26 = V_27 + V_23 ;
printf ( L_26 , V_26 -> V_29 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_27 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_28 ) ;
F_14 ( V_16 ) ;
}
if ( F_18 ( ( * V_9 ) [ 1 ] ) )
F_14 ( V_16 ) ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else {
fprintf ( V_15 , L_29 , V_6 ) ;
F_14 ( V_16 ) ;
}
( * V_9 ) ++ ;
( * V_10 ) -- ;
V_12 ++ ;
}
return V_12 ;
}
static int F_19 ( int * V_30 , const char * * * V_9 )
{
int V_11 = 0 , V_31 = 0 , V_32 = V_33 ;
int V_34 , V_35 ;
const char * * V_36 ;
const char * V_37 ;
char * V_38 ;
V_37 = ( * V_9 ) [ 0 ] ;
V_38 = F_20 ( V_37 ) ;
if ( V_38 ) {
if ( V_38 [ 0 ] == '!' ) {
if ( * V_30 > 1 ) {
struct V_39 V_40 ;
F_21 ( & V_40 , V_41 ) ;
F_22 ( & V_40 , V_38 ) ;
F_23 ( & V_40 , ( * V_9 ) + 1 , V_41 ) ;
free ( V_38 ) ;
V_38 = V_40 . V_40 ;
}
V_31 = system ( V_38 + 1 ) ;
if ( V_31 >= 0 && F_24 ( V_31 ) &&
F_25 ( V_31 ) != 127 )
exit ( F_25 ( V_31 ) ) ;
F_26 ( L_30 ,
V_38 + 1 , V_37 ) ;
}
V_34 = F_27 ( V_38 , & V_36 ) ;
if ( V_34 < 0 )
F_26 ( L_31 , V_37 ) ;
V_35 = F_10 ( & V_36 , & V_34 , & V_11 ) ;
if ( V_11 )
F_26 ( L_32
L_33 ,
V_37 ) ;
memmove ( V_36 - V_35 , V_36 ,
V_34 * sizeof( char * ) ) ;
V_36 -= V_35 ;
if ( V_34 < 1 )
F_26 ( L_34 , V_37 ) ;
if ( ! strcmp ( V_37 , V_36 [ 0 ] ) )
F_26 ( L_35 , V_37 ) ;
V_36 = realloc ( V_36 , sizeof( char * ) *
( V_34 + * V_30 + 1 ) ) ;
memcpy ( V_36 + V_34 , * V_9 + 1 , sizeof( char * ) * * V_30 ) ;
V_36 [ V_34 + * V_30 ] = NULL ;
* V_9 = V_36 ;
* V_30 += V_34 - 1 ;
V_31 = 1 ;
}
V_33 = V_32 ;
return V_31 ;
}
static int F_28 ( struct V_25 * V_26 , int V_10 , const char * * V_9 )
{
int V_42 ;
struct V_43 V_44 ;
const char * V_45 ;
char V_46 [ V_47 ] ;
V_45 = NULL ;
if ( V_26 -> V_28 & V_48 )
V_45 = NULL ;
if ( V_49 == - 1 )
V_49 = F_7 ( V_26 -> V_6 ) ;
if ( V_8 == - 1 && V_26 -> V_28 & V_48 )
V_8 = F_4 ( V_26 -> V_6 ) ;
if ( V_8 == - 1 && V_26 -> V_28 & V_50 )
V_8 = 1 ;
F_8 () ;
V_42 = V_26 -> V_51 ( V_10 , V_9 , V_45 ) ;
F_29 ( V_42 ) ;
F_30 ( & V_52 ) ;
F_31 () ;
if ( V_42 )
return V_42 & 0xff ;
if ( F_32 ( fileno ( stdout ) , & V_44 ) )
return 0 ;
if ( F_33 ( V_44 . V_53 ) || F_34 ( V_44 . V_53 ) )
return 0 ;
V_42 = 1 ;
if ( fflush ( stdout ) ) {
fprintf ( V_15 , L_36 ,
F_35 ( V_33 , V_46 , sizeof( V_46 ) ) ) ;
goto V_54;
}
if ( ferror ( stdout ) ) {
fprintf ( V_15 , L_37 ) ;
goto V_54;
}
if ( fclose ( stdout ) ) {
fprintf ( V_15 , L_38 ,
F_35 ( V_33 , V_46 , sizeof( V_46 ) ) ) ;
goto V_54;
}
V_42 = 0 ;
V_54:
return V_42 ;
}
static void F_36 ( int V_10 , const char * * V_9 )
{
const char * V_6 = V_9 [ 0 ] ;
unsigned int V_23 ;
static const char V_55 [] = V_56 ;
if ( sizeof( V_55 ) > 1 ) {
V_23 = strlen ( V_9 [ 0 ] ) - strlen ( V_55 ) ;
if ( V_23 > 0 && ! strcmp ( V_9 [ 0 ] + V_23 , V_55 ) ) {
char * V_57 = F_37 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = V_6 = V_57 ;
V_57 [ V_23 ] = '\0' ;
}
}
if ( V_10 > 1 && ! strcmp ( V_9 [ 1 ] , L_6 ) ) {
V_9 [ 1 ] = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 = L_39 ;
}
for ( V_23 = 0 ; V_23 < F_17 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
if ( strcmp ( V_26 -> V_6 , V_6 ) )
continue;
exit ( F_28 ( V_26 , V_10 , V_9 ) ) ;
}
}
static void F_38 ( const char * * V_9 )
{
struct V_39 V_6 = V_58 ;
const char * V_59 ;
int V_42 ;
F_39 ( & V_6 , L_40 , V_9 [ 0 ] ) ;
V_59 = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 . V_40 ;
V_42 = F_40 ( V_9 , 0 ) ;
if ( V_42 != - V_60 ) {
if ( F_41 ( V_42 ) )
F_26 ( L_41 , V_9 [ 0 ] ) ;
exit ( - V_42 ) ;
}
V_33 = V_61 ;
V_9 [ 0 ] = V_59 ;
F_42 ( & V_6 ) ;
}
static int F_43 ( int * V_30 , const char * * * V_9 )
{
int V_62 = 0 ;
while ( 1 ) {
F_36 ( * V_30 , * V_9 ) ;
F_38 ( * V_9 ) ;
if ( V_62 || ! F_19 ( V_30 , V_9 ) )
break;
V_62 = 1 ;
}
return V_62 ;
}
static void F_44 ( void )
{
T_1 V_63 ;
F_45 ( & V_63 ) ;
F_46 ( & V_63 , V_64 ) ;
F_47 ( V_65 , & V_63 , NULL ) ;
}
void F_48 ( void )
{
T_1 V_63 ;
F_45 ( & V_63 ) ;
F_46 ( & V_63 , V_64 ) ;
F_47 ( V_66 , & V_63 , NULL ) ;
}
int main ( int V_10 , const char * * V_9 )
{
const char * V_6 ;
char V_46 [ V_47 ] ;
V_67 = F_49 ( V_68 ) ;
V_69 = F_49 ( V_70 ) ;
V_6 = F_50 ( V_9 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_42 ;
F_51 () ;
if ( ! F_2 ( V_6 , L_43 ) ) {
V_6 += 5 ;
V_9 [ 0 ] = V_6 ;
F_36 ( V_10 , V_9 ) ;
fprintf ( V_15 , L_44 , V_6 ) ;
goto V_54;
}
if ( ! F_2 ( V_6 , L_45 ) ) {
#ifdef F_52
F_16 ( NULL ) ;
F_53 () ;
V_9 [ 0 ] = L_45 ;
return F_54 ( V_10 , V_9 , NULL ) ;
#else
fprintf ( V_15 ,
L_46 ) ;
goto V_54;
#endif
}
V_9 ++ ;
V_10 -- ;
F_10 ( & V_9 , & V_10 , NULL ) ;
F_8 () ;
F_16 ( NULL ) ;
if ( V_10 > 0 ) {
if ( ! F_2 ( V_9 [ 0 ] , L_47 ) )
V_9 [ 0 ] += 2 ;
} else {
printf ( L_48 , V_16 ) ;
F_55 () ;
printf ( L_49 , V_71 ) ;
goto V_54;
}
V_6 = V_9 [ 0 ] ;
F_56 () ;
F_53 () ;
F_44 () ;
while ( 1 ) {
static int V_72 ;
int V_73 = F_43 ( & V_10 , & V_9 ) ;
if ( V_33 != V_61 )
break;
if ( V_73 ) {
fprintf ( V_15 , L_50
L_51 ,
V_6 , V_9 [ 0 ] ) ;
goto V_54;
}
if ( ! V_72 ) {
V_6 = V_9 [ 0 ] = F_57 ( V_6 ) ;
V_72 = 1 ;
} else
break;
}
fprintf ( V_15 , L_52 ,
V_6 , F_35 ( V_33 , V_46 , sizeof( V_46 ) ) ) ;
V_54:
return 1 ;
}
