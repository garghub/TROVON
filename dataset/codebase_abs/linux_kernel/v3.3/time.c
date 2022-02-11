static void F_1 ( enum V_1 V_2 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
V_5 = F_2 ( V_6 ) ;
V_5 &= ~ ( 0x03 << 27 ) ;
switch ( V_2 ) {
case V_7 :
F_3 ( V_8 , V_9 ) ;
V_5 |= ( V_10 | V_11 | V_12 | V_13 ) ;
break;
case V_14 :
V_5 |= ( V_15 | V_11 | V_12 | V_13 ) ;
break;
case V_16 :
case V_17 :
case V_18 :
break;
}
F_3 ( V_5 , V_6 ) ;
}
static int F_4 ( unsigned long V_19 ,
struct V_3 * V_4 )
{
unsigned int V_5 ;
F_3 ( V_19 , V_9 ) ;
V_5 = F_2 ( V_6 ) ;
V_5 |= ( V_11 | V_12 | V_13 ) ;
F_3 ( V_5 , V_6 ) ;
return 0 ;
}
static T_1 F_5 ( int V_20 , void * V_21 )
{
struct V_3 * V_19 = & V_22 ;
F_3 ( 0x01 , V_23 ) ;
V_19 -> V_24 ( V_19 ) ;
return V_25 ;
}
static void T_2 F_6 ( void )
{
unsigned int V_26 ;
struct V_4 * V_4 = F_7 ( NULL , L_1 ) ;
F_8 ( F_9 ( V_4 ) ) ;
F_3 ( 0x00 , V_6 ) ;
F_10 ( V_4 ) ;
V_26 = F_11 ( V_4 ) / ( V_13 + 1 ) ;
V_8 = ( V_26 / V_27 ) ;
F_3 ( V_28 , V_23 ) ;
F_12 ( V_29 , & V_30 ) ;
V_22 . V_31 = F_13 ( V_26 , V_32 ,
V_22 . V_33 ) ;
V_22 . V_34 = F_14 ( 0xffffffff ,
& V_22 ) ;
V_22 . V_35 = F_14 ( 0xf ,
& V_22 ) ;
V_22 . V_36 = F_15 ( 0 ) ;
F_16 ( & V_22 ) ;
}
static void T_2 F_17 ( void )
{
unsigned int V_5 ;
unsigned int V_26 ;
struct V_4 * V_4 = F_7 ( NULL , L_2 ) ;
F_8 ( F_9 ( V_4 ) ) ;
F_3 ( 0x00 , V_37 ) ;
F_10 ( V_4 ) ;
V_26 = F_11 ( V_4 ) / ( V_13 + 1 ) ;
F_3 ( 0xffffffff , V_38 ) ;
V_5 = F_2 ( V_37 ) ;
V_5 |= ( V_11 | V_10 | V_13 ) ;
F_3 ( V_5 , V_37 ) ;
F_18 ( V_39 , L_3 , V_26 , 200 ,
V_40 , V_41 ) ;
}
static void T_2 F_19 ( void )
{
F_17 () ;
F_6 () ;
}
