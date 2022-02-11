static int F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 ,
void T_1 * V_4 , int V_5 )
{
V_5 = ! ! V_5 ;
F_3 ( V_5 ) ;
F_4 ( V_5 << 14 , V_4 + V_6 ) ;
return 0 ;
}
static int F_5 ( int V_7 , int V_5 )
{
static int V_8 [ V_9 ] = { 0 , 0 , 0 } ;
int * V_10 = NULL ;
T_2 V_11 ;
switch ( V_7 ) {
case 3 :
case 4 :
V_10 = V_8 + V_12 ;
V_11 = ( 1 << 10 ) ;
break;
case 5 :
case 6 :
V_10 = V_8 + V_13 ;
V_11 = ( 1 << 6 ) ;
break;
case 7 :
case 8 :
V_10 = V_8 + V_14 ;
V_11 = ( 1 << 7 ) ;
break;
}
if ( ! V_10 )
return - V_15 ;
if ( V_5 ) {
if ( * V_10 == 0 ) {
T_2 V_16 = F_6 ( V_17 + V_18 ) ;
V_16 &= ~ V_11 ;
F_4 ( V_16 , V_17 + V_18 ) ;
}
( * V_10 ) ++ ;
} else {
if ( * V_10 == 0 )
return 0 ;
( * V_10 ) -- ;
if ( * V_10 == 0 ) {
T_2 V_16 = F_6 ( V_17 + V_18 ) ;
V_16 |= V_11 ;
F_4 ( V_16 , V_17 + V_18 ) ;
}
}
return 0 ;
}
static int F_7 ( int V_7 )
{
return F_5 ( V_7 , 1 ) ;
}
static int F_8 ( int V_7 )
{
return F_5 ( V_7 , 0 ) ;
}
static void T_3 F_9 ( void )
{
void T_1 * V_4 ;
struct V_19 * V_19 ;
int V_20 ;
F_10 () ;
F_11 ( 1 ) ;
F_12 () ;
F_13 ( & V_21 , L_1 , - 1 ,
V_22 ,
F_14 ( V_22 ) ,
& V_23 ,
sizeof( V_23 ) ) ;
F_15 ( & V_24 ) ;
if ( ! F_16 ( V_25 ) )
F_15 ( & V_26 ) ;
F_17 ( & V_21 , L_2 , 0 ,
& V_27 ,
sizeof( V_27 ) ) ;
F_17 ( & V_21 , L_2 , 1 ,
& V_28 ,
sizeof( V_28 ) ) ;
F_18 ( 0 , V_29 ,
F_14 ( V_29 ) ) ;
F_19 ( V_30 ,
F_14 ( V_30 ) ) ;
F_20 ( V_31 ,
F_14 ( V_31 ) ) ;
F_21 () ;
F_13 (
& V_21 , L_3 , - 1 ,
V_32 , F_14 ( V_32 ) ,
& V_33 , sizeof( struct V_34 ) ) ;
F_13 (
& V_21 , L_4 , - 1 ,
V_35 ,
F_14 ( V_35 ) ,
& V_36 ,
sizeof( struct V_37 ) ) ;
V_17 = F_22 ( V_38 , V_39 ) ;
if ( V_17 ) {
T_4 V_16 = F_6 ( V_17 + V_40 ) ;
V_16 &= ~ ( 1 << 4 ) ;
F_4 ( V_16 , V_17 + V_40 ) ;
F_23 ( 0 , V_41 ,
F_14 ( V_41 ) ) ;
F_13 (
& V_21 , L_5 , - 1 ,
V_42 , F_14 ( V_42 ) ,
& V_43 , sizeof( V_43 ) ) ;
}
V_4 = F_22 ( V_44 , 0x200 ) ;
if ( V_4 ) {
F_24 ( F_25 ( V_4 + V_45 ) | ( 3 << 26 ) , V_4 + V_45 ) ;
F_26 ( V_4 ) ;
F_13 (
& V_21 , L_6 , 0 ,
V_46 , F_14 ( V_46 ) ,
& V_47 , sizeof( struct V_48 ) ) ;
}
V_19 = F_27 ( NULL , L_7 ) ;
F_28 ( V_19 , 24576000 ) ;
F_29 ( V_19 ) ;
F_5 ( 5 , 1 ) ;
F_30 (
L_8 , 0 , NULL , 0 ) ;
F_30 (
L_8 , 1 , NULL , 0 ) ;
F_13 (
& V_21 , L_9 , - 1 ,
V_49 , F_14 ( V_49 ) ,
& V_50 , sizeof( V_50 ) ) ;
for ( V_20 = 0 ; V_20 < F_14 ( V_51 ) ; V_20 ++ ) {
struct V_52 V_53 = {
. V_54 = & V_21 ,
. V_55 = L_10 ,
. V_7 = V_20 ,
. V_56 = & V_51 [ V_20 ] ,
. V_57 = sizeof( struct V_58 ) ,
. V_59 = F_31 ( 32 ) ,
} ;
F_15 ( & V_53 ) ;
}
}
static void T_3 F_32 ( void )
{
F_33 () ;
F_34 () ;
}
