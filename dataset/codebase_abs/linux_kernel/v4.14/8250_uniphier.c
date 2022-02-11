static int T_1 F_1 ( struct V_1 * V_2 ,
const char * V_3 )
{
if ( ! V_2 -> V_4 . V_5 )
return - V_6 ;
V_2 -> V_4 . V_7 = V_8 ;
V_2 -> V_4 . V_9 = V_10 ;
V_2 -> V_11 = 0 ;
return F_2 ( V_2 , V_3 ) ;
}
static unsigned int F_3 ( struct V_12 * V_13 , int V_14 )
{
unsigned int V_15 = 0 ;
switch ( V_14 ) {
case V_16 :
V_15 = 8 ;
V_14 = V_17 ;
break;
case V_18 :
V_15 = 8 ;
case V_19 :
V_14 = V_20 ;
break;
default:
V_14 <<= V_10 ;
break;
}
return ( F_4 ( V_13 -> V_5 + V_14 ) >> V_15 ) & 0xff ;
}
static void F_5 ( struct V_12 * V_13 , int V_14 , int V_21 )
{
unsigned int V_15 = 0 ;
bool V_22 = false ;
switch ( V_14 ) {
case V_16 :
V_15 = 8 ;
case V_23 :
V_14 = V_17 ;
break;
case V_18 :
V_15 = 8 ;
V_21 &= ~ V_24 ;
case V_19 :
V_14 = V_20 ;
break;
default:
V_14 <<= V_10 ;
V_22 = true ;
break;
}
if ( V_22 ) {
F_6 ( V_21 , V_13 -> V_5 + V_14 ) ;
} else {
struct V_25 * V_26 = V_13 -> V_27 ;
unsigned long V_28 ;
T_2 V_29 ;
F_7 ( & V_26 -> V_30 , V_28 ) ;
V_29 = F_4 ( V_13 -> V_5 + V_14 ) ;
V_29 &= ~ ( 0xff << V_15 ) ;
V_29 |= V_21 << V_15 ;
F_6 ( V_29 , V_13 -> V_5 + V_14 ) ;
F_8 ( & V_26 -> V_30 , V_28 ) ;
}
}
static int F_9 ( struct V_31 * V_32 )
{
return F_4 ( V_32 -> V_4 . V_5 + V_33 ) ;
}
static void F_10 ( struct V_31 * V_32 , int V_21 )
{
F_6 ( V_21 , V_32 -> V_4 . V_5 + V_33 ) ;
}
static int F_11 ( struct V_2 * V_34 , struct V_12 * V_4 ,
struct V_25 * V_26 )
{
int V_35 ;
T_2 V_36 ;
struct V_37 * V_38 = V_34 -> V_39 ;
V_35 = F_12 ( V_38 , L_1 ) ;
if ( V_35 < 0 ) {
F_13 ( V_34 , L_2 ) ;
return V_35 ;
}
V_4 -> line = V_35 ;
V_26 -> V_40 = F_14 ( V_34 , NULL ) ;
if ( F_15 ( V_26 -> V_40 ) ) {
F_13 ( V_34 , L_3 ) ;
return F_16 ( V_26 -> V_40 ) ;
}
V_35 = F_17 ( V_26 -> V_40 ) ;
if ( V_35 < 0 )
return V_35 ;
V_4 -> V_41 = F_18 ( V_26 -> V_40 ) ;
if ( F_19 ( V_38 , L_4 , & V_36 ) == 0 )
V_4 -> V_42 = V_36 ;
else
V_4 -> V_42 = V_43 ;
return 0 ;
}
static int F_20 ( struct V_44 * V_45 )
{
struct V_2 * V_34 = & V_45 -> V_34 ;
struct V_31 V_32 ;
struct V_25 * V_26 ;
struct V_46 * V_47 ;
void T_3 * V_5 ;
int V_48 ;
int V_35 ;
V_47 = F_21 ( V_45 , V_49 , 0 ) ;
if ( ! V_47 ) {
F_13 ( V_34 , L_5 ) ;
return - V_50 ;
}
V_5 = F_22 ( V_34 , V_47 -> V_51 , F_23 ( V_47 ) ) ;
if ( ! V_5 )
return - V_52 ;
V_48 = F_24 ( V_45 , 0 ) ;
if ( V_48 < 0 ) {
F_13 ( V_34 , L_6 ) ;
return V_48 ;
}
V_26 = F_25 ( V_34 , sizeof( * V_26 ) , V_53 ) ;
if ( ! V_26 )
return - V_52 ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_35 = F_11 ( V_34 , & V_32 . V_4 , V_26 ) ;
if ( V_35 < 0 )
return V_35 ;
F_26 ( & V_26 -> V_30 ) ;
V_32 . V_4 . V_34 = V_34 ;
V_32 . V_4 . V_27 = V_26 ;
V_32 . V_4 . V_54 = V_47 -> V_51 ;
V_32 . V_4 . V_55 = F_23 ( V_47 ) ;
V_32 . V_4 . V_5 = V_5 ;
V_32 . V_4 . V_48 = V_48 ;
V_32 . V_4 . type = V_56 ;
V_32 . V_4 . V_7 = V_8 ;
V_32 . V_4 . V_9 = V_10 ;
V_32 . V_4 . V_28 = V_57 | V_58 ;
V_32 . V_59 = V_60 ;
V_32 . V_4 . V_61 = F_3 ;
V_32 . V_4 . V_62 = F_5 ;
V_32 . V_63 = F_9 ;
V_32 . V_64 = F_10 ;
V_26 -> line = F_27 ( & V_32 ) ;
if ( V_26 -> line < 0 ) {
F_13 ( V_34 , L_7 ) ;
F_28 ( V_26 -> V_40 ) ;
return V_35 ;
}
F_29 ( V_45 , V_26 ) ;
return 0 ;
}
static int F_30 ( struct V_44 * V_45 )
{
struct V_25 * V_26 = F_31 ( V_45 ) ;
F_32 ( V_26 -> line ) ;
F_28 ( V_26 -> V_40 ) ;
return 0 ;
}
static int T_4 F_33 ( struct V_2 * V_34 )
{
struct V_25 * V_26 = F_34 ( V_34 ) ;
struct V_31 * V_32 = F_35 ( V_26 -> line ) ;
F_36 ( V_26 -> line ) ;
if ( ! F_37 ( & V_32 -> V_4 ) || V_65 )
F_28 ( V_26 -> V_40 ) ;
return 0 ;
}
static int T_4 F_38 ( struct V_2 * V_34 )
{
struct V_25 * V_26 = F_34 ( V_34 ) ;
struct V_31 * V_32 = F_35 ( V_26 -> line ) ;
int V_35 ;
if ( ! F_37 ( & V_32 -> V_4 ) || V_65 ) {
V_35 = F_17 ( V_26 -> V_40 ) ;
if ( V_35 )
return V_35 ;
}
F_39 ( V_26 -> line ) ;
return 0 ;
}
