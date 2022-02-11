static void F_1 ( T_1 V_1 , int V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
V_6 = ( ( V_3 << V_7 ) |
( ( V_2 & V_8 ) << V_9 ) |
( V_1 << V_10 ) |
V_11 |
V_5 |
V_4 ) ;
F_2 ( V_6 , V_12 ) ;
F_2 ( V_6 | V_13 , V_12 ) ;
F_2 ( V_6 | V_13 | V_14 ,
V_12 ) ;
}
static void F_3 ( T_1 V_15 , T_1 V_16 )
{
T_1 V_17 ;
V_17 = F_4 ( V_18 ) ;
V_17 |= V_15 ;
V_17 &= ~ V_16 ;
F_2 ( V_17 , V_18 ) ;
}
static void F_5 ( void )
{
T_1 V_19 ;
enum V_20 V_20 ;
unsigned long V_21 ;
F_6 ( & V_22 , V_21 ) ;
V_23 ++ ;
if ( V_23 != 1 ) {
F_7 ( & V_22 , V_21 ) ;
return;
}
V_20 = F_8 () ;
switch ( V_20 ) {
case V_24 :
F_1 ( 0x0000 , - 15 , 0x02 , 0 , 0 ) ;
V_19 = V_25 |
V_26 ;
break;
case V_27 :
case V_28 :
F_3 ( 0 , V_29 ) ;
F_1 ( 0x8000 , - 14 , 0x03 , V_30 ,
V_31 ) ;
V_19 = V_25 |
V_26 ;
break;
case V_32 :
F_1 ( 0x0000 , - 15 , 0x02 , V_30 ,
V_31 ) ;
switch ( F_9 () ) {
case V_33 :
break;
case V_34 :
F_3 ( V_35 |
V_36 |
V_37 |
V_38 , 0 ) ;
break;
default:
F_3 ( V_35 |
V_36 , 0 ) ;
break;
}
V_19 = V_39 |
V_25 |
V_26 ;
break;
case V_40 :
F_1 ( 0x8000 , - 14 , 0x03 , V_30 ,
V_31 ) ;
V_19 = V_39 |
V_25 |
V_26 ;
break;
default:
F_10 ( L_1 , V_20 ) ;
V_19 = 0 ;
break;
}
F_2 ( 0 , V_41 ) ;
F_2 ( V_19 , V_42 ) ;
F_2 ( V_43 , V_44 ) ;
F_2 ( V_45 , V_46 ) ;
F_2 ( V_47 , V_48 ) ;
F_7 ( & V_22 , V_21 ) ;
}
static void F_11 ( void )
{
unsigned long V_21 ;
F_6 ( & V_22 , V_21 ) ;
V_23 -- ;
if ( V_23 == 0 )
F_2 ( V_49 , V_41 ) ;
F_7 ( & V_22 , V_21 ) ;
}
void F_12 ()
{
F_5 () ;
}
void F_13 ()
{
F_5 () ;
}
void F_14 ()
{
F_11 () ;
}
void F_15 ()
{
F_11 () ;
}
int T_2 F_16 ( struct V_50 * * V_51 ,
struct V_50 * * V_52 )
{
* V_51 = & V_53 ;
V_54 [ 0 ] . V_55 = F_17 ( V_56 ) ;
V_54 [ 0 ] . V_57 += V_54 [ 0 ] . V_55 ;
* V_52 = & V_58 ;
V_59 [ 0 ] . V_55 = F_17 ( V_60 ) ;
V_59 [ 0 ] . V_57 += V_59 [ 0 ] . V_55 ;
return 0 ;
}
