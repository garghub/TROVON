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
struct V_1 * V_2 ;
int V_20 ;
F_10 () ;
F_11 ( 1 ) ;
F_12 () ;
F_13 ( & V_21 ) ;
F_13 ( & V_22 ) ;
if ( ! F_14 ( V_23 ) )
F_13 ( & V_24 ) ;
F_15 ( & V_25 , L_1 , 0 ,
& V_26 ,
sizeof( V_26 ) ) ;
F_15 ( & V_25 , L_1 , 1 ,
& V_27 ,
sizeof( V_27 ) ) ;
F_16 ( 0 , V_28 ,
F_17 ( V_28 ) ) ;
F_18 ( V_29 ,
F_17 ( V_29 ) ) ;
F_19 ( V_30 ,
F_17 ( V_30 ) ) ;
F_20 () ;
F_21 (
& V_25 , L_2 , - 1 ,
V_31 , F_17 ( V_31 ) ,
& V_32 , sizeof( struct V_33 ) ) ;
F_21 (
& V_25 , L_3 , - 1 ,
V_34 ,
F_17 ( V_34 ) ,
& V_35 ,
sizeof( struct V_36 ) ) ;
F_22 ( 0 , V_37 ,
F_17 ( V_37 ) ) ;
F_23 ( 1 , L_4 , V_38 ,
F_17 ( V_38 ) , 3300000 ) ;
V_17 = F_24 ( V_39 , V_40 ) ;
if ( V_17 ) {
T_4 V_16 = F_6 ( V_17 + V_41 ) ;
V_16 &= ~ ( 1 << 4 ) ;
F_4 ( V_16 , V_17 + V_41 ) ;
F_21 (
& V_25 , L_5 , - 1 ,
V_42 , F_17 ( V_42 ) ,
& V_43 , sizeof( V_43 ) ) ;
}
V_4 = F_24 ( V_44 , 0x200 ) ;
if ( V_4 ) {
F_25 ( F_26 ( V_4 + V_45 ) | ( 3 << 26 ) , V_4 + V_45 ) ;
F_27 ( V_4 ) ;
F_21 (
& V_25 , L_6 , 0 ,
V_46 , F_17 ( V_46 ) ,
& V_47 , sizeof( struct V_48 ) ) ;
}
F_5 ( 5 , 1 ) ;
F_28 (
L_7 , 0 , NULL , 0 ) ;
F_28 (
L_7 , 1 , NULL , 0 ) ;
V_2 = F_21 (
& V_25 , L_8 , - 1 ,
V_49 , F_17 ( V_49 ) ,
& V_50 , sizeof( V_50 ) ) ;
V_19 = F_29 ( & V_2 -> V_51 , L_9 ) ;
F_30 ( V_19 , 24576000 ) ;
F_31 ( V_19 ) ;
for ( V_20 = 0 ; V_20 < F_17 ( V_52 ) ; V_20 ++ ) {
struct V_53 V_54 = {
. V_55 = & V_25 ,
. V_56 = L_10 ,
. V_7 = V_20 ,
. V_57 = & V_52 [ V_20 ] ,
. V_58 = sizeof( struct V_59 ) ,
. V_60 = F_32 ( 32 ) ,
} ;
F_13 ( & V_54 ) ;
}
}
static void T_3 F_33 ( void )
{
F_34 () ;
F_35 () ;
}
