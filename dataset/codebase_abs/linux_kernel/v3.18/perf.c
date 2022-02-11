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
} else if ( ! F_2 ( V_6 , V_21 ) ) {
F_15 ( V_6 + strlen ( V_21 ) ) ;
fprintf ( V_15 , L_18 , V_22 ) ;
if ( V_11 )
* V_11 = 1 ;
} else if ( ! strcmp ( V_6 , L_19 ) ) {
unsigned int V_23 ;
for ( V_23 = 0 ; V_23 < F_16 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
printf ( L_20 , V_26 -> V_6 ) ;
}
exit ( 0 ) ;
} else if ( ! strcmp ( V_6 , L_21 ) ) {
if ( * V_10 < 2 ) {
fprintf ( V_15 , L_22 ) ;
F_14 ( V_16 ) ;
}
if ( F_17 ( ( * V_9 ) [ 1 ] ) )
F_14 ( V_16 ) ;
( * V_9 ) ++ ;
( * V_10 ) -- ;
} else {
fprintf ( V_15 , L_23 , V_6 ) ;
F_14 ( V_16 ) ;
}
( * V_9 ) ++ ;
( * V_10 ) -- ;
V_12 ++ ;
}
return V_12 ;
}
static int F_18 ( int * V_27 , const char * * * V_9 )
{
int V_11 = 0 , V_28 = 0 , V_29 = V_30 ;
int V_31 , V_32 ;
const char * * V_33 ;
const char * V_34 ;
char * V_35 ;
V_34 = ( * V_9 ) [ 0 ] ;
V_35 = F_19 ( V_34 ) ;
if ( V_35 ) {
if ( V_35 [ 0 ] == '!' ) {
if ( * V_27 > 1 ) {
struct V_36 V_37 ;
F_20 ( & V_37 , V_38 ) ;
F_21 ( & V_37 , V_35 ) ;
F_22 ( & V_37 , ( * V_9 ) + 1 , V_38 ) ;
free ( V_35 ) ;
V_35 = V_37 . V_37 ;
}
V_28 = system ( V_35 + 1 ) ;
if ( V_28 >= 0 && F_23 ( V_28 ) &&
F_24 ( V_28 ) != 127 )
exit ( F_24 ( V_28 ) ) ;
F_25 ( L_24 ,
V_35 + 1 , V_34 ) ;
}
V_31 = F_26 ( V_35 , & V_33 ) ;
if ( V_31 < 0 )
F_25 ( L_25 , V_34 ) ;
V_32 = F_10 ( & V_33 , & V_31 , & V_11 ) ;
if ( V_11 )
F_25 ( L_26
L_27 ,
V_34 ) ;
memmove ( V_33 - V_32 , V_33 ,
V_31 * sizeof( char * ) ) ;
V_33 -= V_32 ;
if ( V_31 < 1 )
F_25 ( L_28 , V_34 ) ;
if ( ! strcmp ( V_34 , V_33 [ 0 ] ) )
F_25 ( L_29 , V_34 ) ;
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
static int F_27 ( struct V_25 * V_26 , int V_10 , const char * * V_9 )
{
int V_39 ;
struct V_40 V_41 ;
const char * V_42 ;
char V_43 [ V_44 ] ;
V_42 = NULL ;
if ( V_26 -> V_45 & V_46 )
V_42 = NULL ;
if ( V_47 == - 1 )
V_47 = F_7 ( V_26 -> V_6 ) ;
if ( V_8 == - 1 && V_26 -> V_45 & V_46 )
V_8 = F_4 ( V_26 -> V_6 ) ;
if ( V_8 == - 1 && V_26 -> V_45 & V_48 )
V_8 = 1 ;
F_8 () ;
V_39 = V_26 -> V_49 ( V_10 , V_9 , V_42 ) ;
F_28 ( V_39 ) ;
if ( V_39 )
return V_39 & 0xff ;
if ( F_29 ( fileno ( stdout ) , & V_41 ) )
return 0 ;
if ( F_30 ( V_41 . V_50 ) || F_31 ( V_41 . V_50 ) )
return 0 ;
V_39 = 1 ;
if ( fflush ( stdout ) ) {
fprintf ( V_15 , L_30 ,
F_32 ( V_30 , V_43 , sizeof( V_43 ) ) ) ;
goto V_51;
}
if ( ferror ( stdout ) ) {
fprintf ( V_15 , L_31 ) ;
goto V_51;
}
if ( fclose ( stdout ) ) {
fprintf ( V_15 , L_32 ,
F_32 ( V_30 , V_43 , sizeof( V_43 ) ) ) ;
goto V_51;
}
V_39 = 0 ;
V_51:
return V_39 ;
}
static void F_33 ( int V_10 , const char * * V_9 )
{
const char * V_6 = V_9 [ 0 ] ;
unsigned int V_23 ;
static const char V_52 [] = V_53 ;
if ( sizeof( V_52 ) > 1 ) {
V_23 = strlen ( V_9 [ 0 ] ) - strlen ( V_52 ) ;
if ( V_23 > 0 && ! strcmp ( V_9 [ 0 ] + V_23 , V_52 ) ) {
char * V_54 = F_34 ( V_9 [ 0 ] ) ;
V_9 [ 0 ] = V_6 = V_54 ;
V_54 [ V_23 ] = '\0' ;
}
}
if ( V_10 > 1 && ! strcmp ( V_9 [ 1 ] , L_6 ) ) {
V_9 [ 1 ] = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 = L_33 ;
}
for ( V_23 = 0 ; V_23 < F_16 ( V_24 ) ; V_23 ++ ) {
struct V_25 * V_26 = V_24 + V_23 ;
if ( strcmp ( V_26 -> V_6 , V_6 ) )
continue;
exit ( F_27 ( V_26 , V_10 , V_9 ) ) ;
}
}
static void F_35 ( const char * * V_9 )
{
struct V_36 V_6 = V_55 ;
const char * V_56 ;
int V_39 ;
F_36 ( & V_6 , L_34 , V_9 [ 0 ] ) ;
V_56 = V_9 [ 0 ] ;
V_9 [ 0 ] = V_6 . V_37 ;
V_39 = F_37 ( V_9 , 0 ) ;
if ( V_39 != - V_57 ) {
if ( F_38 ( V_39 ) )
F_25 ( L_35 , V_9 [ 0 ] ) ;
exit ( - V_39 ) ;
}
V_30 = V_58 ;
V_9 [ 0 ] = V_56 ;
F_39 ( & V_6 ) ;
}
static int F_40 ( int * V_27 , const char * * * V_9 )
{
int V_59 = 0 ;
while ( 1 ) {
F_33 ( * V_27 , * V_9 ) ;
F_35 ( * V_9 ) ;
if ( V_59 || ! F_18 ( V_27 , V_9 ) )
break;
V_59 = 1 ;
}
return V_59 ;
}
static void F_41 ( void )
{
T_1 V_60 ;
F_42 ( & V_60 ) ;
F_43 ( & V_60 , V_61 ) ;
F_44 ( V_62 , & V_60 , NULL ) ;
}
void F_45 ( void )
{
T_1 V_60 ;
F_42 ( & V_60 ) ;
F_43 ( & V_60 , V_61 ) ;
F_44 ( V_63 , & V_60 , NULL ) ;
}
int main ( int V_10 , const char * * V_9 )
{
const char * V_6 ;
char V_43 [ V_44 ] ;
V_64 = F_46 ( V_65 ) ;
V_66 = F_46 ( V_67 ) ;
V_6 = F_47 ( V_9 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_36 ;
F_48 ( NULL ) ;
if ( ! F_2 ( V_6 , L_37 ) ) {
V_6 += 5 ;
V_9 [ 0 ] = V_6 ;
F_33 ( V_10 , V_9 ) ;
fprintf ( V_15 , L_38 , V_6 ) ;
goto V_51;
}
if ( ! F_2 ( V_6 , L_39 ) ) {
#ifdef F_49
F_50 () ;
F_51 () ;
V_9 [ 0 ] = L_39 ;
return F_52 ( V_10 , V_9 , NULL ) ;
#else
fprintf ( V_15 ,
L_40 ) ;
goto V_51;
#endif
}
V_9 ++ ;
V_10 -- ;
F_10 ( & V_9 , & V_10 , NULL ) ;
F_8 () ;
F_50 () ;
if ( V_10 > 0 ) {
if ( ! F_2 ( V_9 [ 0 ] , L_41 ) )
V_9 [ 0 ] += 2 ;
} else {
printf ( L_42 , V_16 ) ;
F_53 () ;
printf ( L_43 , V_68 ) ;
goto V_51;
}
V_6 = V_9 [ 0 ] ;
F_54 () ;
F_51 () ;
F_41 () ;
while ( 1 ) {
static int V_69 ;
int V_70 = F_40 ( & V_10 , & V_9 ) ;
if ( V_30 != V_58 )
break;
if ( V_70 ) {
fprintf ( V_15 , L_44
L_45 ,
V_6 , V_9 [ 0 ] ) ;
goto V_51;
}
if ( ! V_69 ) {
V_6 = V_9 [ 0 ] = F_55 ( V_6 ) ;
V_69 = 1 ;
} else
break;
}
fprintf ( V_15 , L_46 ,
V_6 , F_32 ( V_30 , V_43 , sizeof( V_43 ) ) ) ;
V_51:
return 1 ;
}
