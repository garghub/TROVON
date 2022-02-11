static void T_1 F_1 ( void )
{
F_2 ( V_1 , F_3 ( V_1 ) ) ;
F_4 ( 12000000 ) ;
F_5 ( V_2 , F_3 ( V_2 ) ) ;
}
static int T_1 F_6 ( char * V_3 )
{
if ( V_3 )
F_7 ( V_4 , V_3 , sizeof( V_4 ) ) ;
return 1 ;
}
static void T_1 F_8 (
struct V_5 * V_6 ,
const char * V_7 )
{
const char * V_8 = V_7 ;
V_6 -> V_9 = 0 ;
V_6 -> V_10 = 0 ;
V_6 -> V_11 = - 1 ;
while ( * V_8 ) {
char V_12 = * V_8 ++ ;
switch ( V_12 ) {
case '0' ... '9' :
if ( V_6 -> V_10 & V_13 ) {
F_9 ( V_14 L_1
L_2 , V_12 ) ;
} else {
int V_15 = V_12 - '0' ;
if ( V_15 >= F_3 ( V_16 ) )
F_9 ( V_14 L_3
L_4 , V_12 ) ;
else {
V_6 -> V_17 [ V_6 -> V_9 ++ ] =
& V_18 ;
V_6 -> V_11 = V_15 ;
}
}
V_6 -> V_10 |= V_13 ;
break;
case 'b' :
if ( V_6 -> V_10 & V_19 )
F_9 ( V_14 L_1
L_5 , V_12 ) ;
else {
V_6 -> V_17 [ V_6 -> V_9 ++ ] =
& V_20 ;
}
V_6 -> V_10 |= V_19 ;
break;
case 't' :
F_9 ( V_14 L_1
L_6 , V_12 ) ;
break;
case 'c' :
if ( V_6 -> V_10 & V_21 )
F_9 ( V_14 L_1
L_7 , V_12 ) ;
else
V_6 -> V_17 [ V_6 -> V_9 ++ ] =
& V_22 ;
V_6 -> V_10 |= V_21 ;
break;
}
}
}
static void T_1 F_10 ( void )
{
struct V_5 V_6 = { 0 } ;
int V_23 ;
F_9 ( V_14 L_8 ,
V_4 ) ;
F_8 ( & V_6 , V_4 ) ;
F_11 ( F_12 ( 0 ) , V_24 ) ;
F_13 ( F_14 ( F_15 ( 4 ) , V_25 , NULL ) ) ;
F_16 ( F_15 ( 4 ) ) ;
F_14 ( F_17 ( 1 ) , V_26 , NULL ) ;
F_18 ( F_17 ( 1 ) , V_27 ) ;
F_16 ( F_17 ( 1 ) ) ;
for ( V_23 = 0 ; V_23 < F_3 ( V_28 ) ; V_23 ++ ) {
F_18 ( V_28 [ V_23 ] . V_29 , V_27 ) ;
F_11 ( V_28 [ V_23 ] . V_29 , V_30 ) ;
}
if ( V_6 . V_11 != - 1 ) {
int V_15 ;
V_31 . V_32 =
& V_16 [ V_6 . V_11 ] ;
F_9 ( V_14 L_9 ) ;
for ( V_15 = 0 ; V_15 < F_3 ( V_16 ) ; V_15 ++ )
if ( V_15 == V_6 . V_11 )
F_9 ( L_10 , V_15 ,
V_16 [ V_15 ] . V_33 ,
V_16 [ V_15 ] . V_34 ) ;
else
F_9 ( L_11 , V_15 ,
V_16 [ V_15 ] . V_33 ,
V_16 [ V_15 ] . V_34 ) ;
F_9 ( L_12 ) ;
F_19 ( & V_31 ) ;
}
F_20 ( & V_35 ) ;
F_21 ( & V_36 ) ;
F_22 ( & V_37 ) ;
F_23 ( NULL ) ;
F_24 ( 0 , V_38 ,
F_3 ( V_38 ) ) ;
F_25 ( V_39 , F_3 ( V_39 ) ) ;
if ( V_6 . V_9 )
F_25 ( V_6 . V_17 , V_6 . V_9 ) ;
}
