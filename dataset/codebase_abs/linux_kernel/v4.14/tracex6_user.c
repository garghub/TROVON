static void F_1 ( int V_1 , struct V_2 * V_3 )
{
int V_4 , error = 0 ;
T_1 V_5 ;
T_2 V_6 ;
F_2 ( & V_5 ) ;
F_3 ( V_1 , & V_5 ) ;
assert ( F_4 ( 0 , sizeof( V_5 ) , & V_5 ) == 0 ) ;
V_4 = F_5 ( V_3 , - 1 , V_1 , - 1 , 0 ) ;
if ( V_4 < 0 ) {
fprintf ( V_7 , L_1 , V_1 ) ;
error = 1 ;
goto V_8;
}
assert ( F_6 ( V_9 [ 0 ] , & V_1 , & V_4 , V_10 ) == 0 ) ;
assert ( F_7 ( V_4 , V_11 , 0 ) == 0 ) ;
F_8 ( V_9 [ 1 ] , & V_1 , NULL ) ;
if ( F_9 ( V_9 [ 1 ] , & V_1 , & V_6 ) ) {
fprintf ( V_7 , L_2 , V_1 ) ;
error = 1 ;
goto V_8;
}
fprintf ( V_7 , L_3 , V_1 , V_6 ) ;
V_8:
assert ( F_10 ( V_9 [ 0 ] , & V_1 ) == 0 || error ) ;
assert ( F_7 ( V_4 , V_12 , 0 ) == 0 || error ) ;
assert ( F_11 ( V_4 ) == 0 || error ) ;
assert ( F_10 ( V_9 [ 1 ] , & V_1 ) == 0 || error ) ;
exit ( error ) ;
}
static void F_12 ( struct V_2 * V_3 ,
const char * V_13 )
{
int V_14 , V_15 , V_16 = F_13 ( V_17 ) ;
T_3 V_18 [ V_16 ] ;
int V_19 = 0 ;
printf ( L_4 , V_13 ) ;
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
V_18 [ V_14 ] = F_14 () ;
assert ( V_18 [ V_14 ] >= 0 ) ;
if ( V_18 [ V_14 ] == 0 ) {
F_1 ( V_14 , V_3 ) ;
exit ( 1 ) ;
}
}
for ( V_14 = 0 ; V_14 < V_16 ; V_14 ++ ) {
assert ( F_15 ( V_18 [ V_14 ] , & V_15 , 0 ) == V_18 [ V_14 ] ) ;
V_19 |= V_15 ;
}
if ( V_19 )
printf ( L_5 , V_13 ) ;
}
static void F_16 ( void )
{
struct V_2 V_20 = {
. V_21 = 0 ,
. V_22 = V_23 ,
. V_24 = 0 ,
. type = V_25 ,
. V_26 = 0 ,
. V_27 = 0 ,
. V_28 = V_29 ,
} ;
struct V_2 V_30 = {
. V_21 = 0 ,
. V_22 = V_23 ,
. V_24 = 0 ,
. type = V_31 ,
. V_26 = 0 ,
. V_27 = 0 ,
. V_28 = V_32 ,
} ;
struct V_2 V_33 = {
. V_21 = 0 ,
. V_22 = V_23 ,
. V_24 = 0 ,
. type = V_34 ,
. V_26 = 0 ,
. V_27 = 0 ,
. V_28 = 0xc0 ,
} ;
struct V_2 V_35 = {
. V_21 = 0 ,
. V_22 = V_23 ,
. V_24 = 0 ,
. type = V_36 ,
. V_26 = 0 ,
. V_27 = 0 ,
. V_28 =
V_37 |
( V_38 << 8 ) |
( V_39 << 16 ) ,
} ;
struct V_2 V_40 = {
. V_21 = 0 ,
. V_22 = V_23 ,
. V_24 = 0 ,
. type = V_36 ,
. V_26 = 0 ,
. V_27 = 0 ,
. V_28 =
V_41 |
( V_38 << 8 ) |
( V_42 << 16 ) ,
} ;
struct V_2 V_43 = {
. V_21 = 0 ,
. V_22 = 0 ,
. V_24 = 0 ,
. type = 7 ,
. V_26 = 0 ,
. V_27 = 0 ,
. V_28 = 0 ,
} ;
F_12 ( & V_20 , L_6 ) ;
F_12 ( & V_30 , L_7 ) ;
F_12 ( & V_33 , L_8 ) ;
F_12 ( & V_35 , L_9 ) ;
F_12 ( & V_40 , L_10 ) ;
F_12 ( & V_43 , L_11 ) ;
}
int main ( int V_44 , char * * V_45 )
{
struct V_46 V_47 = { V_48 , V_48 } ;
char V_49 [ 256 ] ;
snprintf ( V_49 , sizeof( V_49 ) , L_12 , V_45 [ 0 ] ) ;
F_17 ( V_50 , & V_47 ) ;
if ( F_18 ( V_49 ) ) {
printf ( L_13 , V_51 ) ;
return 1 ;
}
F_16 () ;
return 0 ;
}
