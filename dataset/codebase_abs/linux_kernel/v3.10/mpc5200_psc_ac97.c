static unsigned short F_1 ( struct V_1 * V_2 , unsigned short V_3 )
{
int V_4 ;
unsigned int V_5 ;
F_2 ( & V_6 -> V_7 ) ;
V_4 = F_3 ( ! ( F_4 ( & V_6 -> V_8 -> V_9 . V_4 ) &
V_10 ) , 100 , 0 ) ;
if ( V_4 == 0 ) {
F_5 ( L_1 ) ;
F_6 ( & V_6 -> V_7 ) ;
return - V_11 ;
}
F_7 ( & V_6 -> V_8 -> V_12 ) ;
F_8 ( & V_6 -> V_8 -> V_13 , ( 1 << 31 ) | ( ( V_3 & 0x7f ) << 24 ) ) ;
V_4 = F_3 ( ( F_4 ( & V_6 -> V_8 -> V_9 . V_4 ) &
V_14 ) , 100 , 0 ) ;
if ( V_4 == 0 ) {
F_5 ( L_2 ,
F_4 ( & V_6 -> V_8 -> V_9 . V_4 ) ) ;
F_6 ( & V_6 -> V_7 ) ;
return - V_11 ;
}
V_5 = F_7 ( & V_6 -> V_8 -> V_12 ) ;
if ( ( ( V_5 >> 24 ) & 0x7f ) != V_3 ) {
F_5 ( L_3 ) ;
F_6 ( & V_6 -> V_7 ) ;
return - V_11 ;
}
V_5 = ( V_5 >> 8 ) & 0xffff ;
F_6 ( & V_6 -> V_7 ) ;
return ( unsigned short ) V_5 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned short V_3 , unsigned short V_5 )
{
int V_4 ;
F_2 ( & V_6 -> V_7 ) ;
V_4 = F_3 ( ! ( F_4 ( & V_6 -> V_8 -> V_9 . V_4 ) &
V_10 ) , 100 , 0 ) ;
if ( V_4 == 0 ) {
F_5 ( L_4 ) ;
goto V_15;
}
F_8 ( & V_6 -> V_8 -> V_13 ,
( ( V_3 & 0x7f ) << 24 ) | ( V_5 << 8 ) ) ;
V_15:
F_6 ( & V_6 -> V_7 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_16 T_1 * V_17 = V_6 -> V_8 ;
F_2 ( & V_6 -> V_7 ) ;
F_8 ( & V_17 -> V_18 , V_6 -> V_18 | V_19 ) ;
F_11 ( 3 ) ;
F_8 ( & V_17 -> V_18 , V_6 -> V_18 ) ;
F_6 ( & V_6 -> V_7 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_16 T_1 * V_17 = V_6 -> V_8 ;
F_2 ( & V_6 -> V_7 ) ;
F_13 ( V_6 -> V_20 , L_5 ) ;
F_14 ( V_6 -> V_21 ) ;
F_8 ( & V_17 -> V_18 , V_6 -> V_18 | V_22 ) ;
F_15 ( & V_17 -> V_23 , V_24 | V_25 ) ;
F_6 ( & V_6 -> V_7 ) ;
F_16 ( 1 ) ;
F_10 ( V_2 ) ;
}
static int F_17 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_6 * V_6 = F_18 ( V_31 ) ;
struct V_32 * V_33 = F_19 ( V_27 , V_6 ) ;
F_13 ( V_6 -> V_20 , L_6
L_7
L_8 ,
V_34 , V_27 , F_20 ( V_29 ) ,
F_21 ( V_29 ) , F_22 ( V_29 ) ,
F_23 ( V_29 ) , F_24 ( V_29 ) ,
F_25 ( V_29 ) , F_26 ( V_29 ) ,
F_27 ( V_29 ) ) ;
V_33 -> V_35 = ( F_25 ( V_29 ) == 1 ) ? 0x100 : 0x300 ;
if ( V_27 -> V_36 -> V_37 != V_38 )
V_33 -> V_35 <<= 16 ;
return 0 ;
}
static int F_28 ( struct V_26 * V_27 ,
struct V_28 * V_29 ,
struct V_30 * V_31 )
{
struct V_6 * V_6 = F_18 ( V_31 ) ;
F_13 ( V_6 -> V_20 , L_9 , V_34 , V_27 ) ;
if ( F_25 ( V_29 ) == 1 )
F_8 ( & V_6 -> V_8 -> V_39 , 0x01000000 ) ;
else
F_8 ( & V_6 -> V_8 -> V_39 , 0x03000000 ) ;
return 0 ;
}
static int F_29 ( struct V_26 * V_27 , int V_40 ,
struct V_30 * V_41 )
{
struct V_6 * V_6 = F_18 ( V_41 ) ;
struct V_32 * V_33 = F_19 ( V_27 , V_6 ) ;
switch ( V_40 ) {
case V_42 :
F_13 ( V_6 -> V_20 , L_10 ,
V_27 -> V_36 -> V_37 ) ;
V_6 -> V_43 |= V_33 -> V_35 ;
F_8 ( & V_6 -> V_8 -> V_39 , V_6 -> V_43 ) ;
break;
case V_44 :
F_13 ( V_6 -> V_20 , L_11 ,
V_27 -> V_36 -> V_37 ) ;
V_6 -> V_43 &= ~ ( V_33 -> V_35 ) ;
F_8 ( & V_6 -> V_8 -> V_39 , V_6 -> V_43 ) ;
break;
}
return 0 ;
}
static int F_30 ( struct V_30 * V_31 )
{
struct V_6 * V_6 = F_18 ( V_31 ) ;
struct V_16 T_1 * V_17 = V_6 -> V_8 ;
F_15 ( & V_17 -> V_23 , V_24 | V_25 ) ;
return 0 ;
}
static int F_31 ( struct V_45 * V_46 )
{
int V_47 ;
struct V_1 V_2 ;
struct V_16 T_1 * V_17 ;
V_47 = F_32 ( V_46 ) ;
if ( V_47 != 0 )
return V_47 ;
V_47 = F_33 ( & V_46 -> V_20 , & V_48 ,
V_49 , F_34 ( V_49 ) ) ;
if ( V_47 != 0 ) {
F_35 ( & V_46 -> V_20 , L_12 ) ;
return V_47 ;
}
V_6 = F_36 ( & V_46 -> V_20 ) ;
V_17 = V_6 -> V_8 ;
V_2 . V_50 = V_6 ;
V_6 -> V_51 = 0 ;
F_37 ( & V_6 -> V_8 -> V_52 . V_51 , V_6 -> V_51 ) ;
V_6 -> V_18 = V_53 | V_54 ;
F_8 ( & V_17 -> V_18 , V_6 -> V_18 ) ;
F_8 ( & V_17 -> V_39 , 0x00000000 ) ;
return 0 ;
}
static int F_38 ( struct V_45 * V_46 )
{
F_39 ( V_46 ) ;
F_40 ( & V_46 -> V_20 ) ;
return 0 ;
}
