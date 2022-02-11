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
F_7 ( F_8 ( V_2 ) ) ;
return 0 ;
}
static int F_9 ( struct V_5 * V_12 )
{
struct V_1 * V_2 = F_6 ( V_12 ) ;
return F_10 ( F_8 ( V_2 ) ) ;
}
static T_1 F_11 ( struct V_13 * V_12 )
{
return V_12 -> V_14 -> V_15 ;
}
static int F_12 ( struct V_1 * V_2 ,
const struct V_16 * V_17 )
{
struct V_13 * V_12 ;
struct V_18 * V_19 ;
int V_20 ;
struct V_3 * V_14 ;
struct V_21 * V_22 ;
if ( V_17 -> V_23 >= F_13 ( V_24 ) ) {
F_14 ( & V_2 -> V_12 , L_1 , V_25 ,
V_17 -> V_23 ) ;
return - V_26 ;
}
V_14 = & V_24 [ V_17 -> V_23 ] ;
V_20 = F_15 ( V_2 ) ;
if ( V_20 ) {
F_14 ( & V_2 -> V_12 , L_2 ,
V_20 ) ;
return V_20 ;
}
V_20 = F_16 ( V_2 , 1 << 0 , F_17 ( V_2 ) ) ;
if ( V_20 ) {
F_14 ( & V_2 -> V_12 , L_3 ) ;
return V_20 ;
}
V_12 = F_18 ( & V_2 -> V_12 , sizeof( struct V_13 ) , V_27 ) ;
if ( ! V_12 )
return - V_28 ;
V_12 -> V_29 = NULL ;
V_12 -> V_14 = V_14 ;
V_12 -> V_30 = F_11 ;
V_12 -> V_31 = F_19 ( V_2 ) [ 0 ] ;
V_12 -> V_12 = & V_2 -> V_12 ;
V_12 -> V_32 = V_2 -> V_32 ;
V_12 -> V_33 |= V_14 -> V_33 ;
if ( V_14 -> V_34 ) {
V_20 = V_14 -> V_34 ( V_2 , V_14 ) ;
if ( V_20 )
return V_20 ;
}
V_12 -> V_35 = V_14 -> V_35 |
V_36 ;
V_12 -> V_37 = V_14 -> V_6 ;
if ( V_14 -> V_38 ) {
V_22 = V_14 -> V_38 ;
V_12 -> V_39 = V_22 -> V_39 ;
V_12 -> V_40 = V_22 -> V_40 ;
V_12 -> V_41 = V_22 -> V_41 ;
V_12 -> V_42 = V_22 -> V_42 ;
V_12 -> V_43 = V_22 -> V_44 ;
}
F_20 ( V_2 , V_12 ) ;
V_12 -> V_45 = V_14 -> V_45 ;
V_12 -> V_46 = V_14 -> V_46 ;
V_19 = & V_12 -> V_47 ;
V_19 -> V_48 = V_49 ;
V_19 -> V_50 = 0 ;
F_21 ( & V_19 -> V_12 , F_22 ( & V_2 -> V_12 ) ) ;
V_19 -> V_51 = V_14 -> V_9 ;
V_20 = F_23 ( V_12 ) ;
if ( V_20 )
return V_20 ;
F_24 ( & V_2 -> V_12 , 1000 ) ;
F_25 ( & V_2 -> V_12 ) ;
F_26 ( & V_2 -> V_12 ) ;
F_27 ( & V_2 -> V_12 ) ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_13 * V_12 = F_8 ( V_2 ) ;
F_7 ( V_12 ) ;
F_29 ( & V_2 -> V_12 ) ;
F_30 ( & V_2 -> V_12 ) ;
F_31 ( & V_12 -> V_47 ) ;
}
