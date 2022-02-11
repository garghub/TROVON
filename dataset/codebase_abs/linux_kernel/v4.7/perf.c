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
F_9 ( V_18 , ( * V_10 ) [ 1 ] , 1 ) ;
if ( V_12 )
* V_12 = 1 ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
V_13 ++ ;
} else if ( ! F_2 ( V_6 , V_19 ) ) {
F_9 ( V_18 , V_6 + strlen ( V_19 ) , 1 ) ;
if ( V_12 )
* V_12 = 1 ;
} else if ( ! strcmp ( V_6 , L_15 ) ) {
if ( * V_11 < 2 ) {
fprintf ( V_16 , L_16 ) ;
F_14 ( V_17 ) ;
}
F_9 ( V_20 , ( * V_10 ) [ 1 ] , 1 ) ;
if ( V_12 )
* V_12 = 1 ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
} else if ( ! F_2 ( V_6 , V_21 ) ) {
F_9 ( V_20 , V_6 + strlen ( V_21 ) , 1 ) ;
if ( V_12 )
* V_12 = 1 ;
} else if ( ! strcmp ( V_6 , L_17 ) ) {
if ( * V_11 < 2 ) {
fprintf ( V_16 , L_18 ) ;
F_14 ( V_17 ) ;
}
F_15 ( ( * V_10 ) [ 1 ] ) ;
if ( V_12 )
* V_12 = 1 ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
} else if ( ! strcmp ( V_6 , L_19 ) ) {
if ( * V_11 < 2 ) {
fprintf ( V_16 , L_20 ) ;
F_14 ( V_17 ) ;
}
F_16 ( ( * V_10 ) [ 1 ] ) ;
if ( V_12 )
* V_12 = 1 ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
} else if ( ! F_2 ( V_6 , V_22 ) ) {
F_15 ( V_6 + strlen ( V_22 ) ) ;
fprintf ( V_16 , L_21 , V_23 ) ;
if ( V_12 )
* V_12 = 1 ;
} else if ( ! strcmp ( V_6 , L_22 ) ) {
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < F_17 ( V_25 ) ; V_24 ++ ) {
struct V_26 * V_27 = V_25 + V_24 ;
printf ( L_23 , V_27 -> V_6 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_24 ) ) {
unsigned int V_24 ;
for ( V_24 = 0 ; V_24 < F_17 ( V_28 ) - 1 ; V_24 ++ ) {
struct V_29 * V_27 = V_28 + V_24 ;
printf ( L_25 , V_27 -> V_30 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_26 ) ) {
if ( * V_11 < 2 ) {
fprintf ( V_16 , L_27 ) ;
F_14 ( V_17 ) ;
}
if ( F_18 ( ( * V_10 ) [ 1 ] ) )
F_14 ( V_17 ) ;
( * V_10 ) ++ ;
( * V_11 ) -- ;
} else {
fprintf ( V_16 , L_28 , V_6 ) ;
F_14 ( V_17 ) ;
}
( * V_10 ) ++ ;
( * V_11 ) -- ;
V_13 ++ ;
}
return V_13 ;
}
static int F_19 ( int * V_31 , const char * * * V_10 )
{
int V_12 = 0 , V_32 = 0 , V_33 = V_34 ;
int V_35 , V_36 ;
const char * * V_37 ;
const char * V_38 ;
char * V_39 ;
V_38 = ( * V_10 ) [ 0 ] ;
V_39 = F_20 ( V_38 ) ;
if ( V_39 ) {
if ( V_39 [ 0 ] == '!' ) {
if ( * V_31 > 1 ) {
struct V_40 V_41 ;
if ( F_21 ( & V_41 , V_42 ) < 0 ||
F_22 ( & V_41 , V_39 ) < 0 ||
F_23 ( & V_41 , ( * V_10 ) + 1 ,
V_42 ) < 0 )
F_24 ( L_29 ) ;
free ( V_39 ) ;
V_39 = V_41 . V_41 ;
}
V_32 = system ( V_39 + 1 ) ;
if ( V_32 >= 0 && F_25 ( V_32 ) &&
F_26 ( V_32 ) != 127 )
exit ( F_26 ( V_32 ) ) ;
F_24 ( L_30 ,
V_39 + 1 , V_38 ) ;
}
V_35 = F_27 ( V_39 , & V_37 ) ;
if ( V_35 < 0 )
F_24 ( L_31 , V_38 ) ;
V_36 = F_10 ( & V_37 , & V_35 , & V_12 ) ;
if ( V_12 )
F_24 ( L_32
L_33 ,
V_38 ) ;
memmove ( V_37 - V_36 , V_37 ,
V_35 * sizeof( char * ) ) ;
V_37 -= V_36 ;
if ( V_35 < 1 )
F_24 ( L_34 , V_38 ) ;
if ( ! strcmp ( V_38 , V_37 [ 0 ] ) )
F_24 ( L_35 , V_38 ) ;
V_37 = realloc ( V_37 , sizeof( char * ) *
( V_35 + * V_31 + 1 ) ) ;
memcpy ( V_37 + V_35 , * V_10 + 1 , sizeof( char * ) * * V_31 ) ;
V_37 [ V_35 + * V_31 ] = NULL ;
* V_10 = V_37 ;
* V_31 += V_35 - 1 ;
V_32 = 1 ;
}
V_34 = V_33 ;
return V_32 ;
}
static int F_28 ( struct V_26 * V_27 , int V_11 , const char * * V_10 )
{
int V_43 ;
struct V_44 V_45 ;
const char * V_46 ;
char V_47 [ V_48 ] ;
V_46 = NULL ;
if ( V_27 -> V_29 & V_49 )
V_46 = NULL ;
if ( V_50 == - 1 )
V_50 = F_7 ( V_27 -> V_6 ) ;
if ( V_8 == - 1 && V_27 -> V_29 & V_49 )
V_8 = F_4 ( V_27 -> V_6 ) ;
if ( V_8 == - 1 && V_27 -> V_29 & V_51 )
V_8 = 1 ;
F_8 () ;
F_29 ( & V_52 , V_11 , V_10 ) ;
V_43 = V_27 -> V_53 ( V_11 , V_10 , V_46 ) ;
F_30 ( V_43 ) ;
F_31 ( & V_52 ) ;
F_32 () ;
if ( V_43 )
return V_43 & 0xff ;
if ( F_33 ( fileno ( stdout ) , & V_45 ) )
return 0 ;
if ( F_34 ( V_45 . V_54 ) || F_35 ( V_45 . V_54 ) )
return 0 ;
V_43 = 1 ;
if ( fflush ( stdout ) ) {
fprintf ( V_16 , L_36 ,
F_36 ( V_34 , V_47 , sizeof( V_47 ) ) ) ;
goto V_55;
}
if ( ferror ( stdout ) ) {
fprintf ( V_16 , L_37 ) ;
goto V_55;
}
if ( fclose ( stdout ) ) {
fprintf ( V_16 , L_38 ,
F_36 ( V_34 , V_47 , sizeof( V_47 ) ) ) ;
goto V_55;
}
V_43 = 0 ;
V_55:
return V_43 ;
}
static void F_37 ( int V_11 , const char * * V_10 )
{
const char * V_6 = V_10 [ 0 ] ;
unsigned int V_24 ;
static const char V_56 [] = V_57 ;
if ( sizeof( V_56 ) > 1 ) {
V_24 = strlen ( V_10 [ 0 ] ) - strlen ( V_56 ) ;
if ( V_24 > 0 && ! strcmp ( V_10 [ 0 ] + V_24 , V_56 ) ) {
char * V_58 = F_38 ( V_10 [ 0 ] ) ;
V_10 [ 0 ] = V_6 = V_58 ;
V_58 [ V_24 ] = '\0' ;
}
}
if ( V_11 > 1 && ! strcmp ( V_10 [ 1 ] , L_5 ) ) {
V_10 [ 1 ] = V_10 [ 0 ] ;
V_10 [ 0 ] = V_6 = L_39 ;
}
for ( V_24 = 0 ; V_24 < F_17 ( V_25 ) ; V_24 ++ ) {
struct V_26 * V_27 = V_25 + V_24 ;
if ( strcmp ( V_27 -> V_6 , V_6 ) )
continue;
exit ( F_28 ( V_27 , V_11 , V_10 ) ) ;
}
}
static void F_39 ( const char * * V_10 )
{
char * V_6 ;
const char * V_59 ;
int V_43 ;
if ( F_40 ( & V_6 , L_40 , V_10 [ 0 ] ) < 0 )
goto V_60;
V_59 = V_10 [ 0 ] ;
V_10 [ 0 ] = V_6 ;
V_43 = F_41 ( V_10 , 0 ) ;
if ( V_43 != - V_61 ) {
if ( F_42 ( V_43 ) ) {
V_60:
F_24 ( L_41 , V_10 [ 0 ] ) ;
}
exit ( - V_43 ) ;
}
V_34 = V_62 ;
V_10 [ 0 ] = V_59 ;
F_43 ( & V_6 ) ;
}
static int F_44 ( int * V_31 , const char * * * V_10 )
{
int V_63 = 0 ;
while ( 1 ) {
F_37 ( * V_31 , * V_10 ) ;
F_39 ( * V_10 ) ;
if ( V_63 || ! F_19 ( V_31 , V_10 ) )
break;
V_63 = 1 ;
}
return V_63 ;
}
static void F_45 ( void )
{
T_1 V_64 ;
F_46 ( & V_64 ) ;
F_47 ( & V_64 , V_65 ) ;
F_48 ( V_66 , & V_64 , NULL ) ;
}
void F_49 ( void )
{
T_1 V_64 ;
F_46 ( & V_64 ) ;
F_47 ( & V_64 , V_65 ) ;
F_48 ( V_67 , & V_64 , NULL ) ;
}
int main ( int V_11 , const char * * V_10 )
{
const char * V_6 ;
char V_47 [ V_48 ] ;
int V_2 ;
F_50 ( L_42 , V_68 , V_69 , V_70 ) ;
F_51 ( V_9 ) ;
V_71 = F_52 ( V_72 ) ;
V_73 = F_52 ( V_74 ) ;
if ( F_53 ( L_43 , & V_2 ) == 0 )
V_75 = V_2 ;
if ( F_53 ( L_44 , & V_2 ) == 0 )
V_76 = V_2 ;
V_6 = F_54 ( V_10 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_45 ;
F_55 ( time ( NULL ) ) ;
F_5 ( V_77 , NULL ) ;
F_16 ( NULL ) ;
F_56 () ;
if ( ! F_2 ( V_6 , L_46 ) ) {
V_6 += 5 ;
V_10 [ 0 ] = V_6 ;
F_37 ( V_11 , V_10 ) ;
fprintf ( V_16 , L_47 , V_6 ) ;
goto V_55;
}
if ( ! F_2 ( V_6 , L_48 ) ) {
#ifdef F_57
F_58 () ;
V_10 [ 0 ] = L_48 ;
return F_59 ( V_11 , V_10 , NULL ) ;
#else
fprintf ( V_16 ,
L_49 ) ;
goto V_55;
#endif
}
V_10 ++ ;
V_11 -- ;
F_10 ( & V_10 , & V_11 , NULL ) ;
F_8 () ;
if ( V_11 > 0 ) {
if ( ! F_2 ( V_10 [ 0 ] , L_50 ) )
V_10 [ 0 ] += 2 ;
} else {
printf ( L_51 , V_17 ) ;
F_60 () ;
printf ( L_52 , V_78 ) ;
goto V_55;
}
V_6 = V_10 [ 0 ] ;
F_61 () ;
F_58 () ;
F_45 () ;
F_62 () ;
while ( 1 ) {
static int V_79 ;
int V_80 = F_44 ( & V_11 , & V_10 ) ;
if ( V_34 != V_62 )
break;
if ( V_80 ) {
fprintf ( V_16 , L_53
L_54 ,
V_6 , V_10 [ 0 ] ) ;
goto V_55;
}
if ( ! V_79 ) {
V_6 = V_10 [ 0 ] = F_63 ( V_6 ) ;
V_79 = 1 ;
} else
break;
}
fprintf ( V_16 , L_55 ,
V_6 , F_36 ( V_34 , V_47 , sizeof( V_47 ) ) ) ;
V_55:
return 1 ;
}
