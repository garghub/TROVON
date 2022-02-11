static void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_6 , V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_7 , V_2 -> V_4 + V_5 ) ;
}
static int F_4 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
T_2 V_11 = V_10 * ( 1000000000 / V_12 ) ;
F_3 ( ( ( 0x00FF0000 & V_11 ) >> 16 ) , V_2 -> V_4 + V_13 ) ;
F_3 ( ( ( 0x0000FF00 & V_11 ) >> 8 ) , V_2 -> V_4 + V_14 ) ;
F_3 ( ( 0x000000FF & V_11 ) , V_2 -> V_4 + V_15 ) ;
V_9 -> V_10 = V_10 ;
return 0 ;
}
static unsigned int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
T_1 V_3 , V_16 , V_17 , V_18 ;
T_2 V_11 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
V_3 |= V_19 ;
F_3 ( V_3 , V_2 -> V_4 + V_5 ) ;
V_18 = F_2 ( V_2 -> V_4 + V_20 ) ;
V_17 = F_2 ( V_2 -> V_4 + V_21 ) ;
V_16 = F_2 ( V_2 -> V_4 + V_22 ) ;
V_11 = ( V_18 << 16 ) | ( V_17 << 8 ) | V_16 ;
return V_11 / ( 1000000000 / V_12 ) ;
}
static int F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
T_1 V_3 ;
V_3 = F_2 ( V_2 -> V_4 + V_5 ) ;
F_3 ( V_3 | V_7 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_3 ( V_6 | V_23 ,
V_2 -> V_4 + V_5 ) ;
F_4 ( V_9 , V_9 -> V_10 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_5 ( V_9 ) ;
F_3 ( V_6 , V_2 -> V_4 + V_5 ) ;
return 0 ;
}
static T_3 F_10 ( struct V_24 * V_25 , void * V_26 )
{
struct V_1 * V_2 = V_26 ;
T_4 V_27 ;
switch ( V_25 -> type ) {
case V_28 :
if ( V_2 -> V_4 != 0 ) {
F_11 ( V_2 -> V_29 , L_1 ) ;
return V_30 ;
}
V_2 -> V_4 = V_25 -> V_26 . V_31 . V_32 ;
V_27 = V_25 -> V_26 . V_31 . V_33 ;
if ( V_27 < V_34 ) {
F_11 ( V_2 -> V_29 , L_2 ) ;
return V_30 ;
}
if ( ! F_12 ( V_2 -> V_29 , V_2 -> V_4 , V_27 ,
V_35 ) ) {
F_11 ( V_2 -> V_29 , L_3 ) ;
return V_30 ;
}
return V_36 ;
case V_37 :
default:
return V_36 ;
}
}
static int F_13 ( struct V_38 * V_39 )
{
struct V_39 * V_29 = & V_39 -> V_29 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
T_3 V_40 ;
int V_41 ;
V_2 = F_14 ( V_29 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 )
return - V_43 ;
V_39 -> V_44 = V_2 ;
V_2 -> V_29 = V_29 ;
V_40 = F_15 ( V_39 -> V_45 , V_46 ,
F_10 , V_2 ) ;
if ( F_16 ( V_40 ) || V_2 -> V_4 == 0 ) {
F_11 ( V_29 , L_4 ) ;
return - V_47 ;
}
V_9 = & V_2 -> V_9 ;
V_9 -> V_48 = & V_49 ;
V_9 -> V_50 = & V_51 ;
V_9 -> V_52 = V_53 ;
V_9 -> V_54 = V_55 ;
V_9 -> V_10 = V_56 ;
V_9 -> V_57 = V_29 ;
F_17 ( V_9 , V_2 ) ;
F_18 ( V_9 , V_58 ) ;
V_41 = F_19 ( V_9 , V_10 , V_29 ) ;
if ( V_41 )
F_11 ( V_29 , L_5 ) ;
V_41 = F_20 ( V_9 ) ;
if ( V_41 ) {
F_11 ( V_29 , L_6 ) ;
return V_41 ;
}
F_3 ( V_6 | V_59 ,
V_2 -> V_4 + V_5 ) ;
F_21 ( V_29 , L_7 ,
V_2 -> V_4 , V_10 , V_58 ) ;
return 0 ;
}
static int F_22 ( struct V_38 * V_39 )
{
struct V_1 * V_2 = F_23 ( V_39 ) ;
F_9 ( & V_2 -> V_9 ) ;
F_24 ( & V_2 -> V_9 ) ;
return 0 ;
}
