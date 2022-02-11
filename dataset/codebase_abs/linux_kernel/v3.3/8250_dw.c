static void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_2 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_3 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_4 ( V_2 -> V_11 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_3 == V_8 )
V_6 -> V_9 = V_4 ;
V_3 <<= V_2 -> V_10 ;
F_6 ( V_4 , V_2 -> V_11 + V_3 ) ;
}
static unsigned int F_7 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_10 ;
return F_8 ( V_2 -> V_11 + V_3 ) ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_12 = V_2 -> V_13 ( V_2 , V_14 ) ;
if ( F_10 ( V_2 , V_12 ) ) {
return 1 ;
} else if ( ( V_12 & V_15 ) == V_15 ) {
( void ) V_2 -> V_13 ( V_2 , V_16 ) ;
V_2 -> V_17 ( V_2 , V_6 -> V_9 , V_8 ) ;
return 1 ;
}
return 0 ;
}
static int T_1 F_11 ( struct V_18 * V_19 )
{
struct V_1 V_20 = {} ;
struct V_21 * V_22 = F_12 ( V_19 , V_23 , 0 ) ;
struct V_21 * V_24 = F_12 ( V_19 , V_25 , 0 ) ;
struct V_26 * V_27 = V_19 -> V_28 . V_29 ;
T_2 V_30 ;
struct V_5 * V_31 ;
if ( ! V_22 || ! V_24 ) {
F_13 ( & V_19 -> V_28 , L_1 ) ;
return - V_32 ;
}
V_31 = F_14 ( & V_19 -> V_28 , sizeof( * V_31 ) , V_33 ) ;
if ( ! V_31 )
return - V_34 ;
V_20 . V_7 = V_31 ;
F_15 ( & V_20 . V_35 ) ;
V_20 . V_36 = V_22 -> V_37 ;
V_20 . V_24 = V_24 -> V_37 ;
V_20 . V_38 = F_9 ;
V_20 . type = V_39 ;
V_20 . V_40 = V_41 | V_42 | V_43 |
V_44 | V_45 ;
V_20 . V_28 = & V_19 -> V_28 ;
V_20 . V_46 = V_47 ;
V_20 . V_13 = F_3 ;
V_20 . V_17 = F_1 ;
if ( ! F_16 ( V_27 , L_2 , & V_30 ) ) {
switch ( V_30 ) {
case 1 :
break;
case 4 :
V_20 . V_46 = V_48 ;
V_20 . V_13 = F_7 ;
V_20 . V_17 = F_5 ;
break;
default:
F_13 ( & V_19 -> V_28 , L_3 ,
V_30 ) ;
return - V_32 ;
}
}
if ( ! F_16 ( V_27 , L_4 , & V_30 ) )
V_20 . V_10 = V_30 ;
if ( F_16 ( V_27 , L_5 , & V_30 ) ) {
F_13 ( & V_19 -> V_28 , L_6 ) ;
return - V_32 ;
}
V_20 . V_49 = V_30 ;
V_31 -> line = F_17 ( & V_20 ) ;
if ( V_31 -> line < 0 )
return V_31 -> line ;
F_18 ( V_19 , V_31 ) ;
return 0 ;
}
static int T_3 F_19 ( struct V_18 * V_19 )
{
struct V_5 * V_31 = F_20 ( V_19 ) ;
F_21 ( V_31 -> line ) ;
return 0 ;
}
