static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( V_2 -> V_5 ) {
case 0x0817 :
V_4 -> V_6 &= ~ V_7 ;
V_4 -> V_6 |= V_8 ;
case 0x0818 :
case 0x0819 :
V_4 -> V_9 = V_2 -> V_5 - 0x817 + 3 ;
return 0 ;
case 0x082C :
case 0x082D :
case 0x082E :
V_4 -> V_9 = V_2 -> V_5 - 0x82C + 0 ;
return 0 ;
}
return - V_10 ;
}
static int F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
switch ( F_3 ( V_2 -> V_11 ) ) {
case 8 :
V_4 -> V_9 = F_4 ( V_2 -> V_11 ) + 0 + 1 ;
return 0 ;
case 9 :
V_4 -> V_9 = F_4 ( V_2 -> V_11 ) + 4 + 1 ;
return 0 ;
}
return - V_10 ;
}
static int F_5 ( struct V_5 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_13 * V_14 = F_7 ( V_2 ) ;
V_14 -> V_15 ( V_14 ) ;
return 0 ;
}
static int F_8 ( struct V_5 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
struct V_13 * V_14 = F_7 ( V_2 ) ;
return V_14 -> V_16 ( V_14 ) ;
}
static T_1 F_9 ( struct V_13 * V_12 )
{
return V_12 -> V_17 -> V_18 ;
}
static int F_10 ( struct V_1 * V_2 ,
const struct V_19 * V_20 )
{
struct V_13 * V_12 ;
struct V_21 * V_22 ;
int V_23 ;
struct V_3 * V_17 ;
struct V_24 * V_25 ;
if ( V_20 -> V_26 >= F_11 ( V_27 ) ) {
F_12 ( & V_2 -> V_12 , L_1 , V_28 ,
V_20 -> V_26 ) ;
return - V_29 ;
}
V_17 = & V_27 [ V_20 -> V_26 ] ;
V_23 = F_13 ( V_2 ) ;
if ( V_23 ) {
F_12 ( & V_2 -> V_12 , L_2 ,
V_23 ) ;
return V_23 ;
}
V_23 = F_14 ( V_2 , 1 << 0 , F_15 ( V_2 ) ) ;
if ( V_23 ) {
F_12 ( & V_2 -> V_12 , L_3 ) ;
return V_23 ;
}
V_12 = F_16 ( & V_2 -> V_12 , sizeof( struct V_13 ) , V_30 ) ;
if ( ! V_12 )
return - V_31 ;
V_12 -> V_32 = NULL ;
V_12 -> V_17 = V_17 ;
V_12 -> V_33 = F_9 ;
V_12 -> V_34 = F_17 ( V_2 ) [ 0 ] ;
V_12 -> V_12 = & V_2 -> V_12 ;
V_12 -> V_35 = V_2 -> V_35 ;
V_12 -> V_36 |= V_17 -> V_36 ;
if ( V_17 -> V_37 ) {
V_23 = V_17 -> V_37 ( V_2 , V_17 ) ;
if ( V_23 )
return V_23 ;
}
V_12 -> V_38 = V_17 -> V_38 |
V_39 ;
V_12 -> V_40 = V_17 -> V_6 ;
if ( V_17 -> V_41 ) {
V_25 = V_17 -> V_41 ;
V_12 -> V_42 = V_25 -> V_42 ;
V_12 -> V_43 = V_25 -> V_43 ;
V_12 -> V_44 = V_25 -> V_44 ;
V_12 -> V_45 = V_25 -> V_45 ;
V_12 -> V_46 = V_25 -> V_47 ;
}
F_18 ( V_2 , V_12 ) ;
V_12 -> V_48 = V_17 -> V_48 ;
V_12 -> V_49 = V_17 -> V_49 ;
V_22 = & V_12 -> V_50 ;
V_22 -> V_51 = V_52 ;
V_22 -> V_53 = 0 ;
F_19 ( & V_22 -> V_12 , F_20 ( & V_2 -> V_12 ) ) ;
V_22 -> V_54 = V_17 -> V_9 ;
V_23 = F_21 ( V_12 ) ;
if ( V_23 )
return V_23 ;
F_22 ( & V_2 -> V_12 , 1000 ) ;
F_23 ( & V_2 -> V_12 ) ;
F_24 ( & V_2 -> V_12 ) ;
F_25 ( & V_2 -> V_12 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_13 * V_12 = F_7 ( V_2 ) ;
V_12 -> V_15 ( V_12 ) ;
F_27 ( & V_2 -> V_12 ) ;
F_28 ( & V_2 -> V_12 ) ;
F_29 ( & V_12 -> V_50 ) ;
}
