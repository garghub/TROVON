static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
unsigned long V_3 = V_1 -> V_4 + ( V_2 -> V_5 ? 0x02 : 0x00 ) ;
T_3 V_6 , V_7 = F_2 ( V_3 ) ;
const T_4 V_8 = V_2 -> V_9 ;
switch ( V_8 ) {
case V_10 : V_6 = 0x00c0 ; break;
case V_11 : V_6 = 0x00b0 ; break;
case V_12 : V_6 = 0x00a0 ; break;
case V_13 : V_6 = 0x0090 ; break;
case V_14 : V_6 = 0x0080 ; break;
case V_15 : V_6 = 0x0070 ; break;
case V_16 : V_6 = 0x0060 ; break;
case V_17 : V_6 = 0x0050 ; break;
case V_18 : V_6 = 0x0400 ; break;
case V_19 : V_6 = 0x0300 ; break;
case V_20 : V_6 = 0x0200 ; break;
case V_21 : V_6 = 0x0100 ; break;
case V_22 :
default: V_6 = 0x0000 ; break;
}
V_7 &= ( V_8 < V_17 ) ? 0xf8ff : 0xff0f ;
V_7 |= V_6 ;
F_3 ( V_7 , V_3 ) ;
}
static void F_4 ( T_1 * V_1 , T_2 * V_2 )
{
V_2 -> V_9 = V_2 -> V_23 ;
F_1 ( V_1 , V_2 ) ;
}
static int F_5 ( T_2 * V_2 )
{
T_1 * V_1 = V_2 -> V_1 ;
T_5 * V_24 = F_6 ( V_1 ) ;
T_4 V_25 = F_7 ( V_1 -> V_26 + V_27 ) ;
V_1 -> V_24 = V_24 ;
if ( ( V_25 & 5 ) == 1 ) {
unsigned long V_28 = V_1 -> V_4 ;
unsigned long V_29 = V_28 + ( V_2 -> V_5 ? 0x06 : 0x04 ) ;
T_4 V_30 = F_7 ( V_1 -> V_26 + V_31 ) ;
F_8 ( V_32 L_1
L_2 , V_2 -> V_33 ) ;
F_9 ( V_30 & ~ 0x01 , V_1 -> V_26 + V_31 ) ;
F_3 ( 0 , V_28 + 0x0a ) ;
F_3 ( 0 , V_29 ) ;
F_9 ( 0x00 , V_1 -> V_26 + V_31 ) ;
F_9 ( 0x01 , V_1 -> V_26 + V_31 ) ;
return V_34 ;
}
if ( F_10 ( V_24 != NULL ) )
return V_24 ( V_2 ) ;
return - 1 ;
}
static void F_11 ( T_2 * V_2 )
{
T_1 * V_1 = V_2 -> V_1 ;
unsigned long V_28 = V_1 -> V_4 ;
unsigned long V_29 = V_28 + ( V_2 -> V_5 ? 0x06 : 0x04 ) ;
unsigned long V_35 = F_12 ( V_1 -> V_36 ) ;
F_3 ( V_35 , V_28 + 0x0a ) ;
F_3 ( V_37 / 2 , V_29 ) ;
F_13 ( V_1 , V_1 -> V_24 ) ;
V_1 -> V_24 = & F_5 ;
F_14 ( V_2 ) ;
}
static T_4 F_15 ( T_1 * V_1 )
{
struct V_38 * V_39 = F_16 ( V_1 -> V_39 ) ;
unsigned long V_28 = F_17 ( V_39 , 5 ) ;
T_3 V_40 = F_2 ( V_28 + 0x00 ) ;
return ( V_40 & 0x2000 ) ? V_41 : V_42 ;
}
static void T_6 F_18 ( T_1 * V_1 )
{
struct V_38 * V_39 = F_16 ( V_1 -> V_39 ) ;
unsigned long V_28 = F_17 ( V_39 , 5 ) ;
T_3 V_40 = F_2 ( V_28 + 0x00 ) ;
F_3 ( V_40 | 0x8000 , V_28 + 0x00 ) ;
F_3 ( V_40 | 0x4000 , V_28 + 0x00 ) ;
F_3 ( V_40 & ~ 0xc000 , V_28 + 0x00 ) ;
V_1 -> V_4 = V_28 ;
if ( ! V_1 -> V_26 )
return;
F_3 ( 0x0003 , V_28 + 0x0c ) ;
V_1 -> V_43 = 0xffff ;
}
static int T_6 F_19 ( struct V_38 * V_39 ,
const struct V_44 * V_45 )
{
int V_46 ;
V_46 = F_20 ( V_39 ) ;
if ( V_46 )
goto V_47;
V_46 = F_21 ( V_39 , 5 , V_48 ) ;
if ( V_46 ) {
F_8 (KERN_ERR DRV_NAME L_3 ) ;
goto V_49;
}
V_46 = F_22 ( V_39 , & V_50 , NULL ) ;
if ( V_46 )
goto V_51;
goto V_47;
V_51:
F_23 ( V_39 , 5 ) ;
V_49:
F_24 ( V_39 ) ;
V_47:
return V_46 ;
}
static void T_7 F_25 ( struct V_38 * V_39 )
{
F_26 ( V_39 ) ;
F_23 ( V_39 , 5 ) ;
F_24 ( V_39 ) ;
}
static int T_8 F_27 ( void )
{
return F_28 ( & V_52 ) ;
}
static void T_9 F_29 ( void )
{
F_30 ( & V_52 ) ;
}
