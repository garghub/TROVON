static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( ! F_2 ( V_1 , L_1 ) && ! strcmp ( V_1 + 6 , V_5 -> V_6 ) )
V_5 -> V_7 = F_3 ( V_1 , V_2 ) ;
return 0 ;
}
int F_4 ( const char * V_6 )
{
int V_8 ;
struct V_4 V_5 ;
V_5 . V_6 = V_6 ;
V_5 . V_7 = - 1 ;
V_8 = F_5 ( F_1 , & V_5 ) ;
return V_8 ? : V_5 . V_7 ;
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
int V_8 ;
struct V_4 V_5 ;
V_5 . V_6 = V_6 ;
V_5 . V_7 = - 1 ;
V_8 = F_5 ( F_6 , & V_5 ) ;
return V_8 ? : V_5 . V_7 ;
}
static void F_8 ( void )
{
switch ( V_9 ) {
case 0 :
F_9 ( V_10 , L_4 , 1 ) ;
break;
case 1 :
break;
default:
break;
}
}
static int F_10 ( const char * * * V_11 , int * V_12 , int * V_13 )
{
int V_14 = 0 ;
while ( * V_12 > 0 ) {
const char * V_6 = ( * V_11 ) [ 0 ] ;
if ( V_6 [ 0 ] != '-' )
break;
if ( ! strcmp ( V_6 , L_5 ) || ! strcmp ( V_6 , L_6 ) )
break;
if ( ! strcmp ( V_6 , L_7 ) ) {
( * V_11 ) [ 0 ] = L_5 ;
break;
}
if ( ! strcmp ( V_6 , L_8 ) ) {
( * V_11 ) [ 0 ] = L_6 ;
break;
}
if ( ! F_2 ( V_6 , V_15 ) ) {
V_6 += strlen ( V_15 ) ;
if ( * V_6 == '=' )
F_11 ( V_6 + 1 ) ;
else {
puts ( F_12 () ) ;
exit ( 0 ) ;
}
} else if ( ! strcmp ( V_6 , L_9 ) ) {
puts ( F_13 ( V_16 ) ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_10 ) || ! strcmp ( V_6 , L_11 ) ) {
V_9 = 1 ;
} else if ( ! strcmp ( V_6 , L_12 ) ) {
V_9 = 0 ;
if ( V_13 )
* V_13 = 1 ;
} else if ( ! strcmp ( V_6 , L_13 ) ) {
if ( * V_12 < 2 ) {
fprintf ( V_17 , L_14 ) ;
F_14 ( V_18 ) ;
}
F_15 ( ( * V_11 ) [ 1 ] ) ;
if ( V_13 )
* V_13 = 1 ;
( * V_11 ) ++ ;
( * V_12 ) -- ;
} else if ( ! strcmp ( V_6 , L_15 ) ) {
if ( * V_12 < 2 ) {
fprintf ( V_17 , L_16 ) ;
F_14 ( V_18 ) ;
}
F_16 ( ( * V_11 ) [ 1 ] ) ;
if ( V_13 )
* V_13 = 1 ;
( * V_11 ) ++ ;
( * V_12 ) -- ;
} else if ( ! F_2 ( V_6 , V_19 ) ) {
F_15 ( V_6 + strlen ( V_19 ) ) ;
fprintf ( V_17 , L_17 , V_20 ) ;
if ( V_13 )
* V_13 = 1 ;
} else if ( ! strcmp ( V_6 , L_18 ) ) {
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < F_17 ( V_22 ) ; V_21 ++ ) {
struct V_23 * V_24 = V_22 + V_21 ;
printf ( L_19 , V_24 -> V_6 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_20 ) ) {
unsigned int V_21 ;
for ( V_21 = 0 ; V_21 < F_17 ( V_25 ) - 1 ; V_21 ++ ) {
struct V_26 * V_24 = V_25 + V_21 ;
printf ( L_21 , V_24 -> V_27 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_22 ) ) {
if ( * V_12 < 2 ) {
fprintf ( V_17 , L_23 ) ;
F_14 ( V_18 ) ;
}
if ( F_18 ( ( * V_11 ) [ 1 ] ) )
F_14 ( V_18 ) ;
( * V_11 ) ++ ;
( * V_12 ) -- ;
} else {
fprintf ( V_17 , L_24 , V_6 ) ;
F_14 ( V_18 ) ;
}
( * V_11 ) ++ ;
( * V_12 ) -- ;
V_14 ++ ;
}
return V_14 ;
}
static int F_19 ( int * V_28 , const char * * * V_11 )
{
int V_13 = 0 , V_29 = 0 , V_30 = V_31 ;
int V_32 , V_33 ;
const char * * V_34 ;
const char * V_35 ;
char * V_36 ;
V_35 = ( * V_11 ) [ 0 ] ;
V_36 = F_20 ( V_35 ) ;
if ( V_36 ) {
if ( V_36 [ 0 ] == '!' ) {
if ( * V_28 > 1 ) {
struct V_37 V_38 ;
if ( F_21 ( & V_38 , V_39 ) < 0 ||
F_22 ( & V_38 , V_36 ) < 0 ||
F_23 ( & V_38 , ( * V_11 ) + 1 ,
V_39 ) < 0 )
F_24 ( L_25 ) ;
free ( V_36 ) ;
V_36 = V_38 . V_38 ;
}
V_29 = system ( V_36 + 1 ) ;
if ( V_29 >= 0 && F_25 ( V_29 ) &&
F_26 ( V_29 ) != 127 )
exit ( F_26 ( V_29 ) ) ;
F_24 ( L_26 ,
V_36 + 1 , V_35 ) ;
}
V_32 = F_27 ( V_36 , & V_34 ) ;
if ( V_32 < 0 )
F_24 ( L_27 , V_35 ) ;
V_33 = F_10 ( & V_34 , & V_32 , & V_13 ) ;
if ( V_13 )
F_24 ( L_28
L_29 ,
V_35 ) ;
memmove ( V_34 - V_33 , V_34 ,
V_32 * sizeof( char * ) ) ;
V_34 -= V_33 ;
if ( V_32 < 1 )
F_24 ( L_30 , V_35 ) ;
if ( ! strcmp ( V_35 , V_34 [ 0 ] ) )
F_24 ( L_31 , V_35 ) ;
V_34 = realloc ( V_34 , sizeof( char * ) *
( V_32 + * V_28 + 1 ) ) ;
memcpy ( V_34 + V_32 , * V_11 + 1 , sizeof( char * ) * * V_28 ) ;
V_34 [ V_32 + * V_28 ] = NULL ;
* V_11 = V_34 ;
* V_28 += V_32 - 1 ;
V_29 = 1 ;
}
V_31 = V_30 ;
return V_29 ;
}
static int F_28 ( struct V_23 * V_24 , int V_12 , const char * * V_11 )
{
int V_40 ;
struct V_41 V_42 ;
const char * V_43 ;
char V_44 [ V_45 ] ;
V_43 = NULL ;
if ( V_24 -> V_26 & V_46 )
V_43 = NULL ;
if ( V_47 == - 1 )
V_47 = F_7 ( V_24 -> V_6 ) ;
if ( V_9 == - 1 && V_24 -> V_26 & V_46 )
V_9 = F_4 ( V_24 -> V_6 ) ;
if ( V_9 == - 1 && V_24 -> V_26 & V_48 )
V_9 = 1 ;
F_8 () ;
F_29 ( & V_49 , V_12 , V_11 ) ;
V_40 = V_24 -> V_50 ( V_12 , V_11 , V_43 ) ;
F_30 () ;
F_31 ( V_40 ) ;
F_32 ( & V_49 ) ;
F_33 () ;
if ( V_40 )
return V_40 & 0xff ;
if ( F_34 ( fileno ( stdout ) , & V_42 ) )
return 0 ;
if ( F_35 ( V_42 . V_51 ) || F_36 ( V_42 . V_51 ) )
return 0 ;
V_40 = 1 ;
if ( fflush ( stdout ) ) {
fprintf ( V_17 , L_32 ,
F_37 ( V_31 , V_44 , sizeof( V_44 ) ) ) ;
goto V_52;
}
if ( ferror ( stdout ) ) {
fprintf ( V_17 , L_33 ) ;
goto V_52;
}
if ( fclose ( stdout ) ) {
fprintf ( V_17 , L_34 ,
F_37 ( V_31 , V_44 , sizeof( V_44 ) ) ) ;
goto V_52;
}
V_40 = 0 ;
V_52:
return V_40 ;
}
static void F_38 ( int V_12 , const char * * V_11 )
{
const char * V_6 = V_11 [ 0 ] ;
unsigned int V_21 ;
static const char V_53 [] = V_54 ;
if ( sizeof( V_53 ) > 1 ) {
V_21 = strlen ( V_11 [ 0 ] ) - strlen ( V_53 ) ;
if ( V_21 > 0 && ! strcmp ( V_11 [ 0 ] + V_21 , V_53 ) ) {
char * V_55 = F_39 ( V_11 [ 0 ] ) ;
V_11 [ 0 ] = V_6 = V_55 ;
V_55 [ V_21 ] = '\0' ;
}
}
if ( V_12 > 1 && ! strcmp ( V_11 [ 1 ] , L_5 ) ) {
V_11 [ 1 ] = V_11 [ 0 ] ;
V_11 [ 0 ] = V_6 = L_35 ;
}
for ( V_21 = 0 ; V_21 < F_17 ( V_22 ) ; V_21 ++ ) {
struct V_23 * V_24 = V_22 + V_21 ;
if ( strcmp ( V_24 -> V_6 , V_6 ) )
continue;
exit ( F_28 ( V_24 , V_12 , V_11 ) ) ;
}
}
static void F_40 ( const char * * V_11 )
{
char * V_6 ;
const char * V_56 ;
int V_40 ;
if ( F_41 ( & V_6 , L_36 , V_11 [ 0 ] ) < 0 )
goto V_57;
V_56 = V_11 [ 0 ] ;
V_11 [ 0 ] = V_6 ;
V_40 = F_42 ( V_11 , 0 ) ;
if ( V_40 != - V_58 ) {
if ( F_43 ( V_40 ) ) {
V_57:
F_24 ( L_37 , V_11 [ 0 ] ) ;
}
exit ( - V_40 ) ;
}
V_31 = V_59 ;
V_11 [ 0 ] = V_56 ;
F_44 ( & V_6 ) ;
}
static int F_45 ( int * V_28 , const char * * * V_11 )
{
int V_60 = 0 ;
while ( 1 ) {
F_38 ( * V_28 , * V_11 ) ;
F_40 ( * V_11 ) ;
if ( V_60 || ! F_19 ( V_28 , V_11 ) )
break;
V_60 = 1 ;
}
return V_60 ;
}
static void F_46 ( void )
{
T_1 V_61 ;
F_47 ( & V_61 ) ;
F_48 ( & V_61 , V_62 ) ;
F_49 ( V_63 , & V_61 , NULL ) ;
}
void F_50 ( void )
{
T_1 V_61 ;
F_47 ( & V_61 ) ;
F_48 ( & V_61 , V_62 ) ;
F_49 ( V_64 , & V_61 , NULL ) ;
}
static void F_51 ( int * V_65 )
{
if ( F_52 ( L_38 , V_65 ) )
F_53 ( L_39 ) ;
}
int main ( int V_12 , const char * * V_11 )
{
int V_8 ;
const char * V_6 ;
char V_44 [ V_45 ] ;
int V_2 ;
F_54 ( L_40 , V_66 , V_67 , V_68 ) ;
F_55 ( V_10 ) ;
V_69 = F_56 ( V_70 ) ;
F_51 ( & V_71 ) ;
if ( F_57 ( L_41 , & V_2 ) == 0 )
V_72 = V_2 ;
if ( F_57 ( L_42 , & V_2 ) == 0 )
V_73 = V_2 ;
V_6 = F_58 ( V_11 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_43 ;
F_59 ( time ( NULL ) ) ;
F_60 () ;
V_8 = F_5 ( V_74 , NULL ) ;
if ( V_8 )
return V_8 ;
F_16 ( NULL ) ;
F_61 () ;
if ( ! F_2 ( V_6 , L_44 ) ) {
V_6 += 5 ;
V_11 [ 0 ] = V_6 ;
F_38 ( V_12 , V_11 ) ;
fprintf ( V_17 , L_45 , V_6 ) ;
goto V_52;
}
if ( ! F_2 ( V_6 , L_46 ) ) {
#ifdef F_62
F_63 () ;
V_11 [ 0 ] = L_46 ;
return F_64 ( V_12 , V_11 , NULL ) ;
#else
fprintf ( V_17 ,
L_47 ) ;
goto V_52;
#endif
}
V_11 ++ ;
V_12 -- ;
F_10 ( & V_11 , & V_12 , NULL ) ;
F_8 () ;
if ( V_12 > 0 ) {
if ( ! F_2 ( V_11 [ 0 ] , L_48 ) )
V_11 [ 0 ] += 2 ;
} else {
printf ( L_49 , V_18 ) ;
F_65 () ;
printf ( L_50 , V_75 ) ;
goto V_52;
}
V_6 = V_11 [ 0 ] ;
F_66 () ;
F_63 () ;
F_46 () ;
F_67 () ;
while ( 1 ) {
static int V_76 ;
int V_77 = F_45 ( & V_12 , & V_11 ) ;
if ( V_31 != V_59 )
break;
if ( V_77 ) {
fprintf ( V_17 , L_51
L_52 ,
V_6 , V_11 [ 0 ] ) ;
goto V_52;
}
if ( ! V_76 ) {
V_6 = V_11 [ 0 ] = F_68 ( V_6 ) ;
V_76 = 1 ;
} else
break;
}
fprintf ( V_17 , L_53 ,
V_6 , F_37 ( V_31 , V_44 , sizeof( V_44 ) ) ) ;
V_52:
return 1 ;
}
