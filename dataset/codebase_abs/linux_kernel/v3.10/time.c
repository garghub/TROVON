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
V_22 . V_31 = F_13 ( 0 ) ;
F_14 ( & V_22 , V_26 ,
0xf , 0xffffffff ) ;
}
static void T_2 F_15 ( void )
{
unsigned int V_5 ;
unsigned int V_26 ;
struct V_4 * V_4 = F_7 ( NULL , L_2 ) ;
F_8 ( F_9 ( V_4 ) ) ;
F_3 ( 0x00 , V_32 ) ;
F_10 ( V_4 ) ;
V_26 = F_11 ( V_4 ) / ( V_13 + 1 ) ;
F_3 ( 0xffffffff , V_33 ) ;
V_5 = F_2 ( V_32 ) ;
V_5 |= ( V_11 | V_10 | V_13 ) ;
F_3 ( V_5 , V_32 ) ;
F_16 ( V_34 , L_3 , V_26 , 200 ,
V_35 , V_36 ) ;
}
void T_2 F_17 ( void )
{
F_15 () ;
F_6 () ;
}
