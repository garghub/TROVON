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
F_9 ( V_9 , L_4 , 1 ) ;
break;
case 1 :
break;
default:
break;
}
}
static int F_10 ( const char * * * V_10 , int * V_11 , int * V_12 )
{
int V_13 = 0 ;
while ( * V_11 > 0 ) {
const char * V_6 = ( * V_10 ) [ 0 ] ;
if ( V_6 [ 0 ] != '-' )
break;
if ( ! strcmp ( V_6 , L_5 ) || ! strcmp ( V_6 , L_6 ) )
break;
if ( ! strcmp ( V_6 , L_7 ) ) {
( * V_10 ) [ 0 ] = L_5 ;
break;
}
if ( ! strcmp ( V_6 , L_8 ) ) {
( * V_10 ) [ 0 ] = L_6 ;
break;
}
if ( ! F_2 ( V_6 , V_14 ) ) {
V_6 += strlen ( V_14 ) ;
if ( * V_6 == '=' )
F_11 ( V_6 + 1 ) ;
else {
puts ( F_12 () ) ;
exit ( 0 ) ;
}
} else if ( ! strcmp ( V_6 , L_9 ) ) {
puts ( F_13 ( V_15 ) ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_10 ) || ! strcmp ( V_6 , L_11 ) ) {
V_8 = 1 ;
} else if ( ! strcmp ( V_6 , L_12 ) ) {
V_8 = 0 ;
if ( V_12 )
* V_12 = 1 ;
} else if ( ! strcmp ( V_6 , L_13 ) ) {
if ( * V_11 < 2 ) {
fprintf ( V_16 , L_14 ) ;
F_14 ( V_17 ) ;
}
F_15 ( ( * V_10 ) [ 1 ] ) ;
if ( V_12 )
* V_12 = 1 ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
} else if ( ! strcmp ( V_6 , L_15 ) ) {
if ( * V_11 < 2 ) {
fprintf ( V_16 , L_16 ) ;
F_14 ( V_17 ) ;
}
F_16 ( ( * V_10 ) [ 1 ] ) ;
if ( V_12 )
* V_12 = 1 ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
} else if ( ! F_2 ( V_6 , V_18 ) ) {
F_15 ( V_6 + strlen ( V_18 ) ) ;
fprintf ( V_16 , L_17 , V_19 ) ;
if ( V_12 )
* V_12 = 1 ;
} else if ( ! strcmp ( V_6 , L_18 ) ) {
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < F_17 ( V_21 ) ; V_20 ++ ) {
struct V_22 * V_23 = V_21 + V_20 ;
printf ( L_19 , V_23 -> V_6 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_20 ) ) {
unsigned int V_20 ;
for ( V_20 = 0 ; V_20 < F_17 ( V_24 ) - 1 ; V_20 ++ ) {
struct V_25 * V_23 = V_24 + V_20 ;
printf ( L_21 , V_23 -> V_26 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_22 ) ) {
if ( * V_11 < 2 ) {
fprintf ( V_16 , L_23 ) ;
F_14 ( V_17 ) ;
}
if ( F_18 ( ( * V_10 ) [ 1 ] ) )
F_14 ( V_17 ) ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
} else {
fprintf ( V_16 , L_24 , V_6 ) ;
F_14 ( V_17 ) ;
}
( * V_10 ) ++ ;
( * V_11 ) -- ;
V_13 ++ ;
}
return V_13 ;
}
static int F_19 ( int * V_27 , const char * * * V_10 )
{
int V_12 = 0 , V_28 = 0 , V_29 = V_30 ;
int V_31 , V_32 ;
const char * * V_33 ;
const char * V_34 ;
char * V_35 ;
V_34 = ( * V_10 ) [ 0 ] ;
V_35 = F_20 ( V_34 ) ;
if ( V_35 ) {
if ( V_35 [ 0 ] == '!' ) {
if ( * V_27 > 1 ) {
struct V_36 V_37 ;
if ( F_21 ( & V_37 , V_38 ) < 0 ||
F_22 ( & V_37 , V_35 ) < 0 ||
F_23 ( & V_37 , ( * V_10 ) + 1 ,
V_38 ) < 0 )
F_24 ( L_25 ) ;
free ( V_35 ) ;
V_35 = V_37 . V_37 ;
}
V_28 = system ( V_35 + 1 ) ;
if ( V_28 >= 0 && F_25 ( V_28 ) &&
F_26 ( V_28 ) != 127 )
exit ( F_26 ( V_28 ) ) ;
F_24 ( L_26 ,
V_35 + 1 , V_34 ) ;
}
V_31 = F_27 ( V_35 , & V_33 ) ;
if ( V_31 < 0 )
F_24 ( L_27 , V_34 ) ;
V_32 = F_10 ( & V_33 , & V_31 , & V_12 ) ;
if ( V_12 )
F_24 ( L_28
L_29 ,
V_34 ) ;
memmove ( V_33 - V_32 , V_33 ,
V_31 * sizeof( char * ) ) ;
V_33 -= V_32 ;
if ( V_31 < 1 )
F_24 ( L_30 , V_34 ) ;
if ( ! strcmp ( V_34 , V_33 [ 0 ] ) )
F_24 ( L_31 , V_34 ) ;
V_33 = realloc ( V_33 , sizeof( char * ) *
( V_31 + * V_27 + 1 ) ) ;
memcpy ( V_33 + V_31 , * V_10 + 1 , sizeof( char * ) * * V_27 ) ;
V_33 [ V_31 + * V_27 ] = NULL ;
* V_10 = V_33 ;
* V_27 += V_31 - 1 ;
V_28 = 1 ;
}
V_30 = V_29 ;
return V_28 ;
}
static int F_28 ( struct V_22 * V_23 , int V_11 , const char * * V_10 )
{
int V_39 ;
struct V_40 V_41 ;
const char * V_42 ;
char V_43 [ V_44 ] ;
V_42 = NULL ;
if ( V_23 -> V_25 & V_45 )
V_42 = NULL ;
if ( V_46 == - 1 )
V_46 = F_7 ( V_23 -> V_6 ) ;
if ( V_8 == - 1 && V_23 -> V_25 & V_45 )
V_8 = F_4 ( V_23 -> V_6 ) ;
if ( V_8 == - 1 && V_23 -> V_25 & V_47 )
V_8 = 1 ;
F_8 () ;
F_29 ( & V_48 , V_11 , V_10 ) ;
V_39 = V_23 -> V_49 ( V_11 , V_10 , V_42 ) ;
F_30 () ;
F_31 ( V_39 ) ;
F_32 ( & V_48 ) ;
F_33 () ;
if ( V_39 )
return V_39 & 0xff ;
if ( F_34 ( fileno ( stdout ) , & V_41 ) )
return 0 ;
if ( F_35 ( V_41 . V_50 ) || F_36 ( V_41 . V_50 ) )
return 0 ;
V_39 = 1 ;
if ( fflush ( stdout ) ) {
fprintf ( V_16 , L_32 ,
F_37 ( V_30 , V_43 , sizeof( V_43 ) ) ) ;
goto V_51;
}
if ( ferror ( stdout ) ) {
fprintf ( V_16 , L_33 ) ;
goto V_51;
}
if ( fclose ( stdout ) ) {
fprintf ( V_16 , L_34 ,
F_37 ( V_30 , V_43 , sizeof( V_43 ) ) ) ;
goto V_51;
}
V_39 = 0 ;
V_51:
return V_39 ;
}
static void F_38 ( int V_11 , const char * * V_10 )
{
const char * V_6 = V_10 [ 0 ] ;
unsigned int V_20 ;
static const char V_52 [] = V_53 ;
if ( sizeof( V_52 ) > 1 ) {
V_20 = strlen ( V_10 [ 0 ] ) - strlen ( V_52 ) ;
if ( V_20 > 0 && ! strcmp ( V_10 [ 0 ] + V_20 , V_52 ) ) {
char * V_54 = F_39 ( V_10 [ 0 ] ) ;
V_10 [ 0 ] = V_6 = V_54 ;
V_54 [ V_20 ] = '\0' ;
}
}
if ( V_11 > 1 && ! strcmp ( V_10 [ 1 ] , L_5 ) ) {
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_6 = L_35 ;
}
for ( V_20 = 0 ; V_20 < F_17 ( V_21 ) ; V_20 ++ ) {
struct V_22 * V_23 = V_21 + V_20 ;
if ( strcmp ( V_23 -> V_6 , V_6 ) )
continue;
exit ( F_28 ( V_23 , V_11 , V_10 ) ) ;
}
}
static void F_40 ( const char * * V_10 )
{
char * V_6 ;
const char * V_55 ;
int V_39 ;
if ( F_41 ( & V_6 , L_36 , V_10 [ 0 ] ) < 0 )
goto V_56;
V_55 = V_10 [ 0 ] ;
V_10 [ 0 ] = V_6 ;
V_39 = F_42 ( V_10 , 0 ) ;
if ( V_39 != - V_57 ) {
if ( F_43 ( V_39 ) ) {
V_56:
F_24 ( L_37 , V_10 [ 0 ] ) ;
}
exit ( - V_39 ) ;
}
V_30 = V_58 ;
V_10 [ 0 ] = V_55 ;
F_44 ( & V_6 ) ;
}
static int F_45 ( int * V_27 , const char * * * V_10 )
{
int V_59 = 0 ;
while ( 1 ) {
F_38 ( * V_27 , * V_10 ) ;
F_40 ( * V_10 ) ;
if ( V_59 || ! F_19 ( V_27 , V_10 ) )
break;
V_59 = 1 ;
}
return V_59 ;
}
static void F_46 ( void )
{
T_1 V_60 ;
F_47 ( & V_60 ) ;
F_48 ( & V_60 , V_61 ) ;
F_49 ( V_62 , & V_60 , NULL ) ;
}
void F_50 ( void )
{
T_1 V_60 ;
F_47 ( & V_60 ) ;
F_48 ( & V_60 , V_61 ) ;
F_49 ( V_63 , & V_60 , NULL ) ;
}
static void F_51 ( int * V_64 )
{
if ( F_52 ( L_38 , V_64 ) )
F_53 ( L_39 ) ;
}
int main ( int V_11 , const char * * V_10 )
{
const char * V_6 ;
char V_43 [ V_44 ] ;
int V_2 ;
F_54 ( L_40 , V_65 , V_66 , V_67 ) ;
F_55 ( V_9 ) ;
V_68 = F_56 ( V_69 ) ;
F_51 ( & V_70 ) ;
if ( F_57 ( L_41 , & V_2 ) == 0 )
V_71 = V_2 ;
if ( F_57 ( L_42 , & V_2 ) == 0 )
V_72 = V_2 ;
V_6 = F_58 ( V_10 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_43 ;
F_59 ( time ( NULL ) ) ;
F_60 () ;
F_5 ( V_73 , NULL ) ;
F_16 ( NULL ) ;
F_61 () ;
if ( ! F_2 ( V_6 , L_44 ) ) {
V_6 += 5 ;
V_10 [ 0 ] = V_6 ;
F_38 ( V_11 , V_10 ) ;
fprintf ( V_16 , L_45 , V_6 ) ;
goto V_51;
}
if ( ! F_2 ( V_6 , L_46 ) ) {
#ifdef F_62
F_63 () ;
V_10 [ 0 ] = L_46 ;
return F_64 ( V_11 , V_10 , NULL ) ;
#else
fprintf ( V_16 ,
L_47 ) ;
goto V_51;
#endif
}
V_10 ++ ;
V_11 -- ;
F_10 ( & V_10 , & V_11 , NULL ) ;
F_8 () ;
if ( V_11 > 0 ) {
if ( ! F_2 ( V_10 [ 0 ] , L_48 ) )
V_10 [ 0 ] += 2 ;
} else {
printf ( L_49 , V_17 ) ;
F_65 () ;
printf ( L_50 , V_74 ) ;
goto V_51;
}
V_6 = V_10 [ 0 ] ;
F_66 () ;
F_63 () ;
F_46 () ;
F_67 () ;
while ( 1 ) {
static int V_75 ;
int V_76 = F_45 ( & V_11 , & V_10 ) ;
if ( V_30 != V_58 )
break;
if ( V_76 ) {
fprintf ( V_16 , L_51
L_52 ,
V_6 , V_10 [ 0 ] ) ;
goto V_51;
}
if ( ! V_75 ) {
V_6 = V_10 [ 0 ] = F_68 ( V_6 ) ;
V_75 = 1 ;
} else
break;
}
fprintf ( V_16 , L_53 ,
V_6 , F_37 ( V_30 , V_43 , sizeof( V_43 ) ) ) ;
V_51:
return 1 ;
}
