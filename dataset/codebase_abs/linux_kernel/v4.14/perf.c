static int F_1 ( const char * V_1 , const char * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_3 ;
if ( F_2 ( V_1 , L_1 ) && ! strcmp ( V_1 + 6 , V_5 -> V_6 ) )
V_5 -> V_7 = F_3 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_4 ( const char * V_6 )
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
if ( F_2 ( V_1 , L_2 ) && ! strcmp ( V_1 + 4 , V_5 -> V_6 ) )
V_5 -> V_7 = F_3 ( V_1 , V_2 ) ;
if ( F_2 ( V_1 , L_3 ) && ! strcmp ( V_1 + 4 , V_5 -> V_6 ) )
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
if ( F_2 ( V_6 , V_15 ) ) {
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
} else if ( F_2 ( V_6 , V_19 ) ) {
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
static int F_19 ( struct V_23 * V_24 , int V_12 , const char * * V_11 )
{
int V_28 ;
struct V_29 V_30 ;
char V_31 [ V_32 ] ;
if ( V_33 == - 1 )
V_33 = F_7 ( V_24 -> V_6 ) ;
if ( V_9 == - 1 && V_24 -> V_26 & V_34 )
V_9 = F_4 ( V_24 -> V_6 ) ;
if ( V_9 == - 1 && V_24 -> V_26 & V_35 )
V_9 = 1 ;
F_8 () ;
F_20 ( & V_36 , V_12 , V_11 ) ;
V_28 = V_24 -> V_37 ( V_12 , V_11 ) ;
F_21 () ;
F_22 ( V_28 ) ;
F_23 ( & V_36 ) ;
F_24 () ;
if ( V_28 )
return V_28 & 0xff ;
if ( F_25 ( fileno ( stdout ) , & V_30 ) )
return 0 ;
if ( F_26 ( V_30 . V_38 ) || F_27 ( V_30 . V_38 ) )
return 0 ;
V_28 = 1 ;
if ( fflush ( stdout ) ) {
fprintf ( V_17 , L_25 ,
F_28 ( V_39 , V_31 , sizeof( V_31 ) ) ) ;
goto V_40;
}
if ( ferror ( stdout ) ) {
fprintf ( V_17 , L_26 ) ;
goto V_40;
}
if ( fclose ( stdout ) ) {
fprintf ( V_17 , L_27 ,
F_28 ( V_39 , V_31 , sizeof( V_31 ) ) ) ;
goto V_40;
}
V_28 = 0 ;
V_40:
return V_28 ;
}
static void F_29 ( int V_12 , const char * * V_11 )
{
const char * V_6 = V_11 [ 0 ] ;
unsigned int V_21 ;
if ( V_12 > 1 && ! strcmp ( V_11 [ 1 ] , L_5 ) ) {
V_11 [ 1 ] = V_11 [ 0 ] ;
V_11 [ 0 ] = V_6 = L_28 ;
}
for ( V_21 = 0 ; V_21 < F_17 ( V_22 ) ; V_21 ++ ) {
struct V_23 * V_24 = V_22 + V_21 ;
if ( strcmp ( V_24 -> V_6 , V_6 ) )
continue;
exit ( F_19 ( V_24 , V_12 , V_11 ) ) ;
}
}
static void F_30 ( const char * * V_11 )
{
char * V_6 ;
const char * V_41 ;
int V_28 ;
if ( F_31 ( & V_6 , L_29 , V_11 [ 0 ] ) < 0 )
goto V_42;
V_41 = V_11 [ 0 ] ;
V_11 [ 0 ] = V_6 ;
V_28 = F_32 ( V_11 , 0 ) ;
if ( V_28 != - V_43 ) {
if ( F_33 ( V_28 ) ) {
V_42:
F_34 ( L_30 , V_11 [ 0 ] ) ;
V_28 = - 128 ;
}
exit ( - V_28 ) ;
}
V_39 = V_44 ;
V_11 [ 0 ] = V_41 ;
F_35 ( & V_6 ) ;
}
static int F_36 ( int * V_45 , const char * * * V_11 )
{
F_29 ( * V_45 , * V_11 ) ;
F_30 ( * V_11 ) ;
return 0 ;
}
static void F_37 ( void )
{
T_1 V_46 ;
F_38 ( & V_46 ) ;
F_39 ( & V_46 , V_47 ) ;
F_40 ( V_48 , & V_46 , NULL ) ;
}
void F_41 ( void )
{
T_1 V_46 ;
F_38 ( & V_46 ) ;
F_39 ( & V_46 , V_47 ) ;
F_40 ( V_49 , & V_46 , NULL ) ;
}
static void F_42 ( int * V_50 )
{
if ( F_43 ( L_31 , V_50 ) )
F_44 ( L_32 ) ;
}
int main ( int V_12 , const char * * V_11 )
{
int V_8 ;
const char * V_6 ;
char V_31 [ V_32 ] ;
int V_2 ;
F_45 ( L_33 , V_51 , V_52 , V_53 ) ;
F_46 ( V_10 ) ;
V_54 = F_47 ( V_55 ) ;
F_42 ( & V_56 ) ;
if ( F_48 ( L_34 , & V_2 ) == 0 )
V_57 = V_2 ;
if ( F_48 ( L_35 , & V_2 ) == 0 )
V_58 = V_2 ;
V_6 = F_49 ( V_11 [ 0 ] ) ;
if ( ! V_6 )
V_6 = L_36 ;
F_50 ( time ( NULL ) ) ;
F_51 () ;
V_8 = F_5 ( V_59 , NULL ) ;
if ( V_8 )
return V_8 ;
F_16 ( NULL ) ;
F_52 () ;
if ( F_2 ( V_6 , L_37 ) ) {
V_6 += 5 ;
V_11 [ 0 ] = V_6 ;
F_29 ( V_12 , V_11 ) ;
V_6 -= 5 ;
V_11 [ 0 ] = V_6 ;
}
if ( F_2 ( V_6 , L_38 ) ) {
#ifdef F_53
F_54 () ;
V_11 [ 0 ] = L_38 ;
return F_55 ( V_12 , V_11 ) ;
#else
fprintf ( V_17 ,
L_39 ) ;
goto V_40;
#endif
}
V_11 ++ ;
V_12 -- ;
F_10 ( & V_11 , & V_12 , NULL ) ;
F_8 () ;
if ( V_12 > 0 ) {
if ( F_2 ( V_11 [ 0 ] , L_40 ) )
V_11 [ 0 ] += 2 ;
} else {
printf ( L_41 , V_18 ) ;
F_56 () ;
printf ( L_42 , V_60 ) ;
goto V_40;
}
V_6 = V_11 [ 0 ] ;
F_57 () ;
F_54 () ;
F_37 () ;
F_58 () ;
while ( 1 ) {
static int V_61 ;
F_36 ( & V_12 , & V_11 ) ;
if ( V_39 != V_44 )
break;
if ( ! V_61 ) {
V_6 = V_11 [ 0 ] = F_59 ( V_6 ) ;
V_61 = 1 ;
} else
break;
}
fprintf ( V_17 , L_43 ,
V_6 , F_28 ( V_39 , V_31 , sizeof( V_31 ) ) ) ;
V_40:
return 1 ;
}
