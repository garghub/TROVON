static int T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
if ( ! V_2 -> V_4 . V_5 )
return - V_6 ;
V_2 -> V_4 . V_7 = V_8 ;
V_2 -> V_4 . V_9 = 2 ;
V_2 -> V_10 = 0 ;
return F_2 ( V_2 , V_3 ) ;
}
static unsigned int F_3 ( struct V_11 * V_12 , int V_13 )
{
unsigned int V_14 = 0 ;
switch ( V_13 ) {
case V_15 :
V_14 = V_16 ;
case V_17 :
V_13 = V_18 ;
break;
default:
break;
}
V_13 <<= V_12 -> V_9 ;
return ( F_4 ( V_12 -> V_5 + V_13 ) >> V_14 ) & 0xff ;
}
static void F_5 ( struct V_11 * V_12 , int V_13 , int V_19 )
{
unsigned int V_14 = 0 ;
bool V_20 = false ;
switch ( V_13 ) {
case V_21 :
V_13 = V_22 ;
break;
case V_15 :
V_14 = V_16 ;
V_19 &= ~ ( V_23 << V_14 ) ;
case V_17 :
V_13 = V_18 ;
break;
default:
V_20 = true ;
break;
}
V_13 <<= V_12 -> V_9 ;
if ( V_20 ) {
F_6 ( V_19 , V_12 -> V_5 + V_13 ) ;
} else {
struct V_24 * V_25 = V_12 -> V_26 ;
unsigned long V_27 ;
T_2 V_28 ;
F_7 ( & V_25 -> V_29 , V_27 ) ;
V_28 = F_4 ( V_12 -> V_5 + V_13 ) ;
V_28 &= ~ ( 0xff << V_14 ) ;
V_28 |= V_19 << V_14 ;
F_6 ( V_28 , V_12 -> V_5 + V_13 ) ;
F_8 ( & V_25 -> V_29 , V_27 ) ;
}
}
static int F_9 ( struct V_30 * V_31 )
{
int V_13 = V_32 << V_31 -> V_4 . V_9 ;
return F_4 ( V_31 -> V_4 . V_5 + V_13 ) ;
}
static void F_10 ( struct V_30 * V_31 , int V_19 )
{
int V_13 = V_32 << V_31 -> V_4 . V_9 ;
F_6 ( V_19 , V_31 -> V_4 . V_5 + V_13 ) ;
}
static int F_11 ( struct V_2 * V_33 , struct V_11 * V_4 ,
struct V_24 * V_25 )
{
int V_34 ;
T_2 V_35 ;
struct V_36 * V_37 = V_33 -> V_38 ;
V_34 = F_12 ( V_37 , L_1 ) ;
if ( V_34 < 0 ) {
F_13 ( V_33 , L_2 ) ;
return V_34 ;
}
V_4 -> line = V_25 -> line = V_34 ;
V_25 -> V_39 = F_14 ( V_33 , NULL ) ;
if ( F_15 ( V_25 -> V_39 ) ) {
F_13 ( V_33 , L_3 ) ;
return F_16 ( V_25 -> V_39 ) ;
}
V_34 = F_17 ( V_25 -> V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
V_4 -> V_40 = F_18 ( V_25 -> V_39 ) ;
if ( F_19 ( V_37 , L_4 , & V_35 ) == 0 )
V_4 -> V_41 = V_35 ;
else
V_4 -> V_41 = V_42 ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 )
{
struct V_2 * V_33 = & V_44 -> V_33 ;
struct V_30 V_31 ;
struct V_24 * V_25 ;
struct V_45 * V_46 ;
void T_3 * V_5 ;
int V_47 ;
int V_34 ;
V_46 = F_21 ( V_44 , V_48 , 0 ) ;
if ( ! V_46 ) {
F_13 ( V_33 , L_5 ) ;
return - V_49 ;
}
V_5 = F_22 ( V_33 , V_46 -> V_50 , F_23 ( V_46 ) ) ;
if ( ! V_5 )
return - V_51 ;
V_47 = F_24 ( V_44 , 0 ) ;
if ( V_47 < 0 ) {
F_13 ( V_33 , L_6 ) ;
return V_47 ;
}
V_25 = F_25 ( V_33 , sizeof( * V_25 ) , V_52 ) ;
if ( ! V_25 )
return - V_51 ;
memset ( & V_31 , 0 , sizeof( V_31 ) ) ;
V_34 = F_11 ( V_33 , & V_31 . V_4 , V_25 ) ;
if ( V_34 < 0 )
return V_34 ;
F_26 ( & V_25 -> V_29 ) ;
V_31 . V_4 . V_33 = V_33 ;
V_31 . V_4 . V_26 = V_25 ;
V_31 . V_4 . V_53 = V_46 -> V_50 ;
V_31 . V_4 . V_54 = F_23 ( V_46 ) ;
V_31 . V_4 . V_5 = V_5 ;
V_31 . V_4 . V_47 = V_47 ;
V_31 . V_4 . type = V_55 ;
V_31 . V_4 . V_7 = V_8 ;
V_31 . V_4 . V_9 = 2 ;
V_31 . V_4 . V_27 = V_56 | V_57 ;
V_31 . V_58 = V_59 ;
V_31 . V_4 . V_60 = F_3 ;
V_31 . V_4 . V_61 = F_5 ;
V_31 . V_62 = F_9 ;
V_31 . V_63 = F_10 ;
V_34 = F_27 ( & V_31 ) ;
if ( V_34 < 0 ) {
F_13 ( V_33 , L_7 ) ;
F_28 ( V_25 -> V_39 ) ;
return V_34 ;
}
F_29 ( V_44 , V_25 ) ;
return 0 ;
}
static int F_30 ( struct V_43 * V_44 )
{
struct V_24 * V_25 = F_31 ( V_44 ) ;
F_32 ( V_25 -> line ) ;
F_28 ( V_25 -> V_39 ) ;
return 0 ;
}
