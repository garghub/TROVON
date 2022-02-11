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
if ( ! F_2 ( V_6 , V_13 ) ) {
V_6 += strlen ( V_13 ) ;
if ( * V_6 == '=' )
F_11 ( V_6 + 1 ) ;
else {
puts ( F_12 () ) ;
exit ( 0 ) ;
}
} else if ( ! strcmp ( V_6 , L_8 ) ) {
puts ( F_13 ( V_14 ) ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_9 ) || ! strcmp ( V_6 , L_10 ) ) {
V_8 = 1 ;
} else if ( ! strcmp ( V_6 , L_11 ) ) {
V_8 = 0 ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_12 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_13 ) ;
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
} else if ( ! strcmp ( V_6 , L_14 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_15 ) ;
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
} else if ( ! strcmp ( V_6 , L_16 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_17 ) ;
F_14 ( V_16 ) ;
}
F_15 ( ( * V_9 ) [ 1 ] ) ;
if ( V_11 )
* V_11 = 1 ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else if ( ! strcmp ( V_6 , L_18 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_19 ) ;
F_14 ( V_16 ) ;
}
F_16 ( ( * V_9 ) [ 1 ] ) ;
if ( V_11 )
* V_11 = 1 ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else if ( ! F_2 ( V_6 , V_21 ) ) {
F_15 ( V_6 + strlen ( V_21 ) ) ;
fprintf ( V_15 , L_20 , V_22 ) ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_21 ) ) {
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_17 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
printf ( L_22 , V_26 -> V_6 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_23 ) ) {
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_17 ( V_27 ) - 1 ; V_23 ++ ) {
struct V_28 * V_26 = V_27 + V_23 ;
printf ( L_24 , V_26 -> V_29 ) ;
}
putchar ( '\n' ) ;
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_25 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_26 ) ;
F_14 ( V_16 ) ;
}
if ( F_18 ( ( * V_9 ) [ 1 ] ) )
F_14 ( V_16 ) ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else {
fprintf ( V_15 , L_27 , V_6 ) ;
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
F_26 ( L_28 ,
V_38 + 1 , V_37 ) ;
}
V_34 = F_27 ( V_38 , & V_36 ) ;
if ( V_34 < 0 )
F_26 ( L_29 , V_37 ) ;
V_35 = F_10 ( & V_36 , & V_34 , & V_11 ) ;
if ( V_11 )
F_26 ( L_30
L_31 ,
V_37 ) ;
memmove ( V_36 - V_35 , V_36 ,
V_34 * sizeof( char * ) ) ;
V_36 -= V_35 ;
if ( V_34 < 1 )
F_26 ( L_32 , V_37 ) ;
if ( ! strcmp ( V_37 , V_36 [ 0 ] ) )
F_26 ( L_33 , V_37 ) ;
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
if ( V_42 )
return V_42 & 0xff ;
if ( F_30 ( fileno ( stdout ) , & V_44 ) )
return 0 ;
if ( F_31 ( V_44 . V_52 ) || F_32 ( V_44 . V_52 ) )
return 0 ;
V_42 = 1 ;
if ( fflush ( stdout ) ) {
fprintf ( V_15 , L_34 ,
F_33 ( V_33 , V_46 , sizeof( V_46 ) ) ) ;
goto V_53;
}
if ( ferror ( stdout ) ) {
fprintf ( V_15 , L_35 ) ;
goto V_53;
}
if ( fclose ( stdout ) ) {
fprintf ( V_15 , L_36 ,
F_33 ( V_33 , V_46 , sizeof( V_46 ) ) ) ;
goto V_53;
}
V_42 = 0 ;
V_53:
return V_42 ;
}
static void F_34 ( int V_10 , const char * * V_9 )
{
const char * V_6 = V_9 [ 0 ] ;
unsigned int V_23 ;
static const char V_54 [] = V_55 ;
if ( sizeof( V_54 ) > 1 ) {
V_23 = strlen ( V_9 [ 0 ] ) - strlen ( V_54 ) ;
if ( V_23 > 0 && ! strcmp ( V_9 [ 0 ] + V_23 , V_54 ) ) {
char * V_56 = F_35 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = V_6 = V_56 ;
V_56 [ V_23 ] = '\0' ;
}
}
if ( V_10 > 1 && ! strcmp ( V_9 [ 1 ] , L_6 ) ) {
V_9 [ 1 ] = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 = L_37 ;
}
for ( V_23 = 0 ; V_23 < F_17 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
if ( strcmp ( V_26 -> V_6 , V_6 ) )
continue;
exit ( F_28 ( V_26 , V_10 , V_9 ) ) ;
}
}
static void F_36 ( const char * * V_9 )
{
struct V_39 V_6 = V_57 ;
const char * V_58 ;
int V_42 ;
F_37 ( & V_6 , L_38 , V_9 [ 0 ] ) ;
V_58 = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 . V_40 ;
V_42 = F_38 ( V_9 , 0 ) ;
if ( V_42 != - V_59 ) {
if ( F_39 ( V_42 ) )
F_26 ( L_39 , V_9 [ 0 ] ) ;
exit ( - V_42 ) ;
}
V_33 = V_60 ;
V_9 [ 0 ] = V_58 ;
F_40 ( & V_6 ) ;
}
static int F_41 ( int * V_30 , const char * * * V_9 )
{
int V_61 = 0 ;
while ( 1 ) {
F_34 ( * V_30 , * V_9 ) ;
F_36 ( * V_9 ) ;
if ( V_61 || ! F_19 ( V_30 , V_9 ) )
break;
V_61 = 1 ;
}
return V_61 ;
}
static void F_42 ( void )
{
T_1 V_62 ;
F_43 ( & V_62 ) ;
F_44 ( & V_62 , V_63 ) ;
F_45 ( V_64 , & V_62 , NULL ) ;
}
void F_46 ( void )
{
T_1 V_62 ;
F_43 ( & V_62 ) ;
F_44 ( & V_62 , V_63 ) ;
F_45 ( V_65 , & V_62 , NULL ) ;
}
int main ( int V_10 , const char * * V_9 )
{
const char * V_6 ;
char V_46 [ V_47 ] ;
V_66 = F_47 ( V_67 ) ;
V_68 = F_47 ( V_69 ) ;
V_6 = F_48 ( V_9 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_40 ;
F_49 ( NULL ) ;
if ( ! F_2 ( V_6 , L_41 ) ) {
V_6 += 5 ;
V_9 [ 0 ] = V_6 ;
F_34 ( V_10 , V_9 ) ;
fprintf ( V_15 , L_42 , V_6 ) ;
goto V_53;
}
if ( ! F_2 ( V_6 , L_43 ) ) {
#ifdef F_50
F_16 ( NULL ) ;
F_51 () ;
V_9 [ 0 ] = L_43 ;
return F_52 ( V_10 , V_9 , NULL ) ;
#else
fprintf ( V_15 ,
L_44 ) ;
goto V_53;
#endif
}
V_9 ++ ;
V_10 -- ;
F_10 ( & V_9 , & V_10 , NULL ) ;
F_8 () ;
F_16 ( NULL ) ;
if ( V_10 > 0 ) {
if ( ! F_2 ( V_9 [ 0 ] , L_45 ) )
V_9 [ 0 ] += 2 ;
} else {
printf ( L_46 , V_16 ) ;
F_53 () ;
printf ( L_47 , V_70 ) ;
goto V_53;
}
V_6 = V_9 [ 0 ] ;
F_54 () ;
F_51 () ;
F_42 () ;
while ( 1 ) {
static int V_71 ;
int V_72 = F_41 ( & V_10 , & V_9 ) ;
if ( V_33 != V_60 )
break;
if ( V_72 ) {
fprintf ( V_15 , L_48
L_49 ,
V_6 , V_9 [ 0 ] ) ;
goto V_53;
}
if ( ! V_71 ) {
V_6 = V_9 [ 0 ] = F_55 ( V_6 ) ;
V_71 = 1 ;
} else
break;
}
fprintf ( V_15 , L_50 ,
V_6 , F_33 ( V_33 , V_46 , sizeof( V_46 ) ) ) ;
V_53:
return 1 ;
}
