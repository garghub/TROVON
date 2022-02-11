static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
unsigned short V_4 , char V_5 ,
T_2 V_6 , int V_7 , union V_8 * V_9 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
int V_13 = 0 ;
int error ;
while ( F_2 ( F_3 ( V_11 , V_14 ) ) & V_15 )
;
switch ( V_7 ) {
case V_16 :
F_4 ( ( F_5 ( V_3 ) |
( V_5 == V_17 ? V_18 : 0 ) |
V_19 ) , F_3 ( V_11 , V_20 ) ) ;
break;
case V_21 :
if ( V_5 == V_17 ) {
F_4 ( ( F_5 ( V_3 ) | V_22 ) ,
F_3 ( V_11 , V_20 ) ) ;
V_13 = 1 ;
} else {
F_4 ( F_6 ( V_6 ) , F_3 ( V_11 , V_23 ) ) ;
F_4 ( ( F_5 ( V_3 ) | V_24 ) ,
F_3 ( V_11 , V_20 ) ) ;
}
break;
case V_25 :
F_4 ( F_6 ( V_6 ) , F_3 ( V_11 , V_23 ) ) ;
if ( V_5 == V_17 ) {
F_4 ( ( F_5 ( V_3 ) | V_26 ) ,
F_3 ( V_11 , V_20 ) ) ;
V_13 = 1 ;
} else {
F_4 ( F_7 ( V_9 -> V_27 ) ,
F_3 ( V_11 , V_28 ) ) ;
F_4 ( ( F_5 ( V_3 ) | V_29 ) ,
F_3 ( V_11 , V_20 ) ) ;
}
break;
case V_30 :
F_4 ( F_6 ( V_6 ) , F_3 ( V_11 , V_23 ) ) ;
if ( V_5 == V_17 ) {
F_4 ( ( F_5 ( V_3 ) | V_31 ) ,
F_3 ( V_11 , V_20 ) ) ;
V_13 = 2 ;
} else {
F_4 ( F_7 ( V_9 -> V_32 & 0xff ) ,
F_3 ( V_11 , V_28 ) ) ;
F_4 ( F_8 ( V_9 -> V_32 >> 8 ) ,
F_3 ( V_11 , V_28 ) ) ;
F_4 ( ( F_5 ( V_3 ) | V_29 ) ,
F_3 ( V_11 , V_20 ) ) ;
}
break;
default:
return - V_33 ;
}
while ( F_2 ( F_3 ( V_11 , V_14 ) ) & V_15 )
;
error = F_2 ( F_3 ( V_11 , V_14 ) ) ;
if ( error & V_34 ) {
F_4 ( V_34 , F_3 ( V_11 , V_14 ) ) ;
return ( error & V_35 ) ? - V_36 : - V_37 ;
}
if ( V_13 == 1 )
V_9 -> V_27 = F_2 ( F_3 ( V_11 , V_28 ) ) & 0xff ;
if ( V_13 == 2 )
V_9 -> V_32 = F_2 ( F_3 ( V_11 , V_28 ) ) & 0xffff ;
return 0 ;
}
static T_3 F_9 ( struct V_1 * V_11 )
{
return ( V_38 | V_39 |
V_40 | V_41 ) ;
}
static int T_4 F_10 ( struct V_1 * V_2 , int V_42 )
{
struct V_10 * V_11 = V_2 -> V_12 ;
V_2 -> V_43 = & V_44 ;
F_4 ( V_42 , F_3 ( V_11 , V_45 ) ) ;
F_4 ( 0 , F_3 ( V_11 , V_46 ) ) ;
return F_11 ( V_2 ) ;
}
static int T_4 F_12 ( void )
{
F_13 ( L_1 ) ;
if ( F_10 ( & V_47 [ 0 ] , V_48 ) < 0 )
return - V_49 ;
if ( F_10 ( & V_47 [ 1 ] ,
V_50 ) < 0 ) {
F_14 ( & V_47 [ 0 ] ) ;
return - V_49 ;
}
return 0 ;
}
static void T_5 F_15 ( void )
{
F_14 ( & V_47 [ 0 ] ) ;
F_14 ( & V_47 [ 1 ] ) ;
}
