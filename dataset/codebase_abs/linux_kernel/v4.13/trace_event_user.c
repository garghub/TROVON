static void F_1 ( T_1 V_1 )
{
struct V_2 * V_3 ;
if ( ! V_1 )
return;
V_3 = F_2 ( V_1 ) ;
printf ( L_1 , V_3 -> V_4 ) ;
if ( ! strcmp ( V_3 -> V_4 , L_2 ) )
V_5 = true ;
else if ( ! strcmp ( V_3 -> V_4 , L_3 ) )
V_6 = true ;
}
static void F_3 ( T_1 V_1 )
{
if ( ! V_1 )
return;
printf ( L_4 , V_1 ) ;
}
static void F_4 ( struct V_7 * V_8 , T_1 V_9 )
{
T_1 V_10 [ V_11 ] = {} ;
static bool V_12 ;
int V_13 ;
printf ( L_5 , V_9 , V_8 -> V_14 ) ;
if ( F_5 ( V_15 [ 1 ] , & V_8 -> V_16 , V_10 ) != 0 ) {
printf ( L_6 ) ;
} else {
for ( V_13 = V_11 - 1 ; V_13 >= 0 ; V_13 -- )
F_1 ( V_10 [ V_13 ] ) ;
}
printf ( L_7 ) ;
if ( F_5 ( V_15 [ 1 ] , & V_8 -> V_17 , V_10 ) != 0 ) {
printf ( L_6 ) ;
} else {
for ( V_13 = V_11 - 1 ; V_13 >= 0 ; V_13 -- )
F_3 ( V_10 [ V_13 ] ) ;
}
if ( V_9 < 6 )
printf ( L_8 ) ;
else
printf ( L_9 ) ;
if ( V_8 -> V_16 == - V_18 && ! V_12 ) {
printf ( L_10 ) ;
V_12 = true ;
} else if ( ( int ) V_8 -> V_16 < 0 && ( int ) V_8 -> V_17 < 0 ) {
printf ( L_11 , V_8 -> V_16 , V_8 -> V_17 ) ;
}
}
static void F_6 ( int V_19 )
{
F_7 ( 0 , V_20 ) ;
exit ( 0 ) ;
}
static void F_8 ( void )
{
struct V_7 V_8 = {} , V_21 ;
T_1 V_22 ;
T_2 V_23 = 0 , V_24 ;
int V_25 = V_15 [ 0 ] , V_26 = V_15 [ 1 ] ;
V_5 = V_6 = false ;
while ( F_9 ( V_25 , & V_8 , & V_21 ) == 0 ) {
F_5 ( V_25 , & V_21 , & V_22 ) ;
F_4 ( & V_21 , V_22 ) ;
F_10 ( V_25 , & V_21 ) ;
V_8 = V_21 ;
}
printf ( L_9 ) ;
if ( ! V_5 || ! V_6 ) {
printf ( L_12 ) ;
F_6 ( 0 ) ;
}
while ( F_9 ( V_26 , & V_23 , & V_24 ) == 0 ) {
F_10 ( V_26 , & V_24 ) ;
V_23 = V_24 ;
}
}
static void F_11 ( struct V_27 * V_28 )
{
int V_29 = F_12 ( V_30 ) ;
int * V_31 = malloc ( V_29 * sizeof( int ) ) ;
int V_13 , error = 0 ;
for ( V_13 = 0 ; V_13 < V_29 ; V_13 ++ ) {
V_31 [ V_13 ] = F_13 ( V_28 , - 1 , V_13 , - 1 , 0 ) ;
if ( V_31 [ V_13 ] < 0 ) {
printf ( L_13 ) ;
error = 1 ;
goto V_32;
}
assert ( F_14 ( V_31 [ V_13 ] , V_33 , V_34 [ 0 ] ) == 0 ) ;
assert ( F_14 ( V_31 [ V_13 ] , V_35 ) == 0 ) ;
}
system ( L_14 ) ;
F_8 () ;
V_32:
for ( V_13 -- ; V_13 >= 0 ; V_13 -- ) {
F_14 ( V_31 [ V_13 ] , V_36 ) ;
F_15 ( V_31 [ V_13 ] ) ;
}
free ( V_31 ) ;
if ( error )
F_6 ( 0 ) ;
}
static void F_16 ( struct V_27 * V_28 )
{
int V_31 ;
V_31 = F_13 ( V_28 , 0 , - 1 , - 1 , 0 ) ;
if ( V_31 < 0 ) {
printf ( L_13 ) ;
F_6 ( 0 ) ;
}
assert ( F_14 ( V_31 , V_33 , V_34 [ 0 ] ) == 0 ) ;
assert ( F_14 ( V_31 , V_35 ) == 0 ) ;
system ( L_14 ) ;
F_8 () ;
F_14 ( V_31 , V_36 ) ;
F_15 ( V_31 ) ;
}
static void F_17 ( void )
{
struct V_27 V_37 = {
. V_38 = V_39 ,
. V_40 = 1 ,
. type = V_41 ,
. V_42 = V_43 ,
. V_44 = 1 ,
} ;
struct V_27 V_45 = {
. V_38 = V_39 ,
. V_40 = 1 ,
. type = V_46 ,
. V_42 = V_47 ,
. V_44 = 1 ,
} ;
struct V_27 V_48 = {
. V_38 = V_39 ,
. V_40 = 1 ,
. type = V_49 ,
. V_42 =
V_50 |
( V_51 << 8 ) |
( V_52 << 16 ) ,
. V_44 = 1 ,
} ;
struct V_27 V_53 = {
. V_38 = V_39 ,
. V_40 = 1 ,
. type = V_49 ,
. V_42 =
V_54 |
( V_51 << 8 ) |
( V_55 << 16 ) ,
. V_44 = 1 ,
} ;
struct V_27 V_56 = {
. V_38 = V_39 ,
. V_40 = 1 ,
. type = V_57 ,
. V_42 = 0xc0 ,
. V_44 = 1 ,
} ;
printf ( L_15 ) ;
F_11 ( & V_37 ) ;
F_16 ( & V_37 ) ;
printf ( L_16 ) ;
F_11 ( & V_45 ) ;
F_16 ( & V_45 ) ;
printf ( L_17 ) ;
F_11 ( & V_48 ) ;
F_16 ( & V_48 ) ;
printf ( L_18 ) ;
F_11 ( & V_53 ) ;
F_16 ( & V_53 ) ;
printf ( L_19 ) ;
F_11 ( & V_56 ) ;
F_16 ( & V_56 ) ;
printf ( L_20 ) ;
}
int main ( int V_58 , char * * V_59 )
{
struct V_60 V_61 = { V_62 , V_62 } ;
char V_63 [ 256 ] ;
snprintf ( V_63 , sizeof( V_63 ) , L_21 , V_59 [ 0 ] ) ;
F_18 ( V_64 , & V_61 ) ;
signal ( V_65 , F_6 ) ;
signal ( V_66 , F_6 ) ;
if ( F_19 () ) {
printf ( L_22 ) ;
return 1 ;
}
if ( F_20 ( V_63 ) ) {
printf ( L_23 , V_67 ) ;
return 2 ;
}
if ( F_21 () == 0 ) {
F_22 () ;
return 0 ;
}
F_17 () ;
F_6 ( 0 ) ;
return 0 ;
}
