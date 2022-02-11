static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 ( 12000000 ) ;
F_5 ( V_2 , F_3 ( V_2 ) ) ;
F_6 ( V_3 , V_4 ) ;
}
static int T_1 F_7 ( char * V_5 )
{
if ( V_5 )
F_8 ( V_6 , V_5 , sizeof( V_6 ) ) ;
return 1 ;
}
static void T_1 F_9 (
struct V_7 * V_8 ,
const char * V_9 )
{
const char * V_10 = V_9 ;
V_8 -> V_11 = 0 ;
V_8 -> V_12 = 0 ;
V_8 -> V_13 = - 1 ;
while ( * V_10 ) {
char V_14 = * V_10 ++ ;
switch ( V_14 ) {
case '0' ... '9' :
if ( V_8 -> V_12 & V_15 ) {
F_10 ( V_16 L_1
L_2 , V_14 ) ;
} else {
int V_17 = V_14 - '0' ;
if ( V_17 >= F_3 ( V_18 ) )
F_10 ( V_16 L_3
L_4 , V_14 ) ;
else {
V_8 -> V_19 [ V_8 -> V_11 ++ ] =
& V_20 ;
V_8 -> V_13 = V_17 ;
}
}
V_8 -> V_12 |= V_15 ;
break;
case 'b' :
if ( V_8 -> V_12 & V_21 )
F_10 ( V_16 L_1
L_5 , V_14 ) ;
else {
V_8 -> V_19 [ V_8 -> V_11 ++ ] =
& V_22 ;
}
V_8 -> V_12 |= V_21 ;
break;
case 't' :
F_10 ( V_16 L_1
L_6 , V_14 ) ;
break;
case 'c' :
if ( V_8 -> V_12 & V_23 )
F_10 ( V_16 L_1
L_7 , V_14 ) ;
else
V_8 -> V_19 [ V_8 -> V_11 ++ ] =
& V_24 ;
V_8 -> V_12 |= V_23 ;
break;
}
}
}
static void T_1 F_11 ( void )
{
struct V_7 V_8 = { 0 } ;
int V_25 ;
F_10 ( V_16 L_8 ,
V_6 ) ;
F_9 ( & V_8 , V_6 ) ;
F_12 ( F_13 ( 0 ) , V_26 ) ;
F_14 ( F_15 ( F_16 ( 4 ) , V_27 , NULL ) ) ;
F_17 ( F_16 ( 4 ) ) ;
F_15 ( F_18 ( 1 ) , V_28 , NULL ) ;
F_19 ( F_18 ( 1 ) , V_29 ) ;
F_17 ( F_18 ( 1 ) ) ;
for ( V_25 = 0 ; V_25 < F_3 ( V_30 ) ; V_25 ++ ) {
F_19 ( V_30 [ V_25 ] . V_31 , V_29 ) ;
F_12 ( V_30 [ V_25 ] . V_31 , V_32 ) ;
}
if ( V_8 . V_13 != - 1 ) {
int V_17 ;
V_33 . V_34 =
& V_18 [ V_8 . V_13 ] ;
F_10 ( V_16 L_9 ) ;
for ( V_17 = 0 ; V_17 < F_3 ( V_18 ) ; V_17 ++ )
if ( V_17 == V_8 . V_13 )
F_10 ( L_10 , V_17 ,
V_18 [ V_17 ] . V_35 ,
V_18 [ V_17 ] . V_36 ) ;
else
F_10 ( L_11 , V_17 ,
V_18 [ V_17 ] . V_35 ,
V_18 [ V_17 ] . V_36 ) ;
F_10 ( L_12 ) ;
F_20 ( & V_33 ) ;
}
F_21 ( & V_37 ) ;
F_22 ( & V_38 ) ;
F_23 ( & V_39 ) ;
F_24 ( NULL ) ;
F_25 ( 0 , V_40 ,
F_3 ( V_40 ) ) ;
F_26 ( V_41 , F_3 ( V_41 ) ) ;
if ( V_8 . V_11 )
F_26 ( V_8 . V_19 , V_8 . V_11 ) ;
}
