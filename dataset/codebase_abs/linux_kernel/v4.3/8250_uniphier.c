static unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
unsigned int V_4 = 0 ;
switch ( V_3 ) {
case V_5 :
V_4 = V_6 ;
case V_7 :
V_3 = V_8 ;
break;
default:
break;
}
V_3 <<= V_2 -> V_9 ;
return ( F_2 ( V_2 -> V_10 + V_3 ) >> V_4 ) & 0xff ;
}
static void F_3 ( struct V_1 * V_2 , int V_3 , int V_11 )
{
unsigned int V_4 = 0 ;
bool V_12 = false ;
switch ( V_3 ) {
case V_13 :
V_3 = V_14 ;
break;
case V_5 :
V_4 = V_6 ;
V_11 &= ~ ( V_15 << V_4 ) ;
case V_7 :
V_3 = V_8 ;
break;
default:
V_12 = true ;
break;
}
V_3 <<= V_2 -> V_9 ;
if ( V_12 ) {
F_4 ( V_11 , V_2 -> V_10 + V_3 ) ;
} else {
struct V_16 * V_17 = V_2 -> V_18 ;
unsigned long V_19 ;
T_1 V_20 ;
F_5 ( & V_17 -> V_21 , V_19 ) ;
V_20 = F_2 ( V_2 -> V_10 + V_3 ) ;
V_20 &= ~ ( 0xff << V_4 ) ;
V_20 |= V_11 << V_4 ;
F_4 ( V_20 , V_2 -> V_10 + V_3 ) ;
F_6 ( & V_17 -> V_21 , V_19 ) ;
}
}
static int F_7 ( struct V_22 * V_23 )
{
return F_2 ( V_23 -> V_24 . V_10 + V_25 ) ;
}
static void F_8 ( struct V_22 * V_23 , int V_11 )
{
F_4 ( V_11 , V_23 -> V_24 . V_10 + V_25 ) ;
}
static int F_9 ( struct V_26 * V_27 , struct V_1 * V_24 ,
struct V_16 * V_17 )
{
int V_28 ;
T_1 V_29 ;
struct V_30 * V_31 = V_27 -> V_32 ;
V_28 = F_10 ( V_31 , L_1 ) ;
if ( V_28 < 0 ) {
F_11 ( V_27 , L_2 ) ;
return V_28 ;
}
V_24 -> line = V_17 -> line = V_28 ;
V_17 -> V_33 = F_12 ( V_27 , NULL ) ;
if ( F_13 ( V_17 -> V_33 ) ) {
F_11 ( V_27 , L_3 ) ;
return F_14 ( V_17 -> V_33 ) ;
}
V_28 = F_15 ( V_17 -> V_33 ) ;
if ( V_28 < 0 )
return V_28 ;
V_24 -> V_34 = F_16 ( V_17 -> V_33 ) ;
if ( F_17 ( V_31 , L_4 , & V_29 ) == 0 )
V_24 -> V_35 = V_29 ;
else
V_24 -> V_35 = V_36 ;
return 0 ;
}
static int F_18 ( struct V_37 * V_38 )
{
struct V_26 * V_27 = & V_38 -> V_27 ;
struct V_22 V_23 ;
struct V_16 * V_17 ;
struct V_39 * V_40 ;
void T_2 * V_10 ;
int V_41 ;
int V_28 ;
V_40 = F_19 ( V_38 , V_42 , 0 ) ;
if ( ! V_40 ) {
F_11 ( V_27 , L_5 ) ;
return - V_43 ;
}
V_10 = F_20 ( V_27 , V_40 -> V_44 , F_21 ( V_40 ) ) ;
if ( ! V_10 )
return - V_45 ;
V_41 = F_22 ( V_38 , 0 ) ;
if ( V_41 < 0 ) {
F_11 ( V_27 , L_6 ) ;
return V_41 ;
}
V_17 = F_23 ( V_27 , sizeof( * V_17 ) , V_46 ) ;
if ( ! V_17 )
return - V_45 ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
V_28 = F_9 ( V_27 , & V_23 . V_24 , V_17 ) ;
if ( V_28 < 0 )
return V_28 ;
F_24 ( & V_17 -> V_21 ) ;
V_23 . V_24 . V_27 = V_27 ;
V_23 . V_24 . V_18 = V_17 ;
V_23 . V_24 . V_47 = V_40 -> V_44 ;
V_23 . V_24 . V_48 = F_21 ( V_40 ) ;
V_23 . V_24 . V_10 = V_10 ;
V_23 . V_24 . V_41 = V_41 ;
V_23 . V_24 . type = V_49 ;
V_23 . V_24 . V_50 = V_51 ;
V_23 . V_24 . V_9 = 2 ;
V_23 . V_24 . V_19 = V_52 | V_53 ;
V_23 . V_54 = V_55 ;
V_23 . V_24 . V_56 = F_1 ;
V_23 . V_24 . V_57 = F_3 ;
V_23 . V_58 = F_7 ;
V_23 . V_59 = F_8 ;
V_28 = F_25 ( & V_23 ) ;
if ( V_28 < 0 ) {
F_11 ( V_27 , L_7 ) ;
F_26 ( V_17 -> V_33 ) ;
return V_28 ;
}
F_27 ( V_38 , V_17 ) ;
return 0 ;
}
static int F_28 ( struct V_37 * V_38 )
{
struct V_16 * V_17 = F_29 ( V_38 ) ;
F_30 ( V_17 -> line ) ;
F_26 ( V_17 -> V_33 ) ;
return 0 ;
}
