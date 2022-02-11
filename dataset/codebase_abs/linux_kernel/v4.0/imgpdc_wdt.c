static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_5 , V_4 -> V_6 + V_7 ) ;
F_3 ( V_8 , V_4 -> V_6 + V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_10 = F_5 ( V_4 -> V_6 + V_11 ) ;
V_10 &= ~ V_12 ;
F_3 ( V_10 , V_4 -> V_6 + V_11 ) ;
F_1 ( V_2 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned int V_13 )
{
unsigned int V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned long V_14 = F_7 ( V_4 -> V_15 ) ;
V_4 -> V_2 . V_16 = V_13 ;
V_10 = F_5 ( V_4 -> V_6 + V_11 ) & ~ V_17 ;
V_10 |= F_8 ( V_13 * V_14 ) - 1 ;
F_3 ( V_10 , V_4 -> V_6 + V_11 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_10 = F_5 ( V_4 -> V_6 + V_11 ) ;
V_10 |= V_12 ;
F_3 ( V_10 , V_4 -> V_6 + V_11 ) ;
return 0 ;
}
static int F_10 ( struct V_18 * V_19 )
{
int V_20 , V_10 ;
unsigned long V_14 ;
struct V_21 * V_22 ;
struct V_3 * V_23 ;
V_23 = F_11 ( & V_19 -> V_24 , sizeof( * V_23 ) , V_25 ) ;
if ( ! V_23 )
return - V_26 ;
V_22 = F_12 ( V_19 , V_27 , 0 ) ;
V_23 -> V_6 = F_13 ( & V_19 -> V_24 , V_22 ) ;
if ( F_14 ( V_23 -> V_6 ) )
return F_15 ( V_23 -> V_6 ) ;
V_23 -> V_28 = F_16 ( & V_19 -> V_24 , L_1 ) ;
if ( F_14 ( V_23 -> V_28 ) ) {
F_17 ( & V_19 -> V_24 , L_2 ) ;
return F_15 ( V_23 -> V_28 ) ;
}
V_23 -> V_15 = F_16 ( & V_19 -> V_24 , L_3 ) ;
if ( F_14 ( V_23 -> V_15 ) ) {
F_17 ( & V_19 -> V_24 , L_4 ) ;
return F_15 ( V_23 -> V_15 ) ;
}
V_20 = F_18 ( V_23 -> V_28 ) ;
if ( V_20 ) {
F_17 ( & V_19 -> V_24 , L_5 ) ;
return V_20 ;
}
V_20 = F_18 ( V_23 -> V_15 ) ;
if ( V_20 ) {
F_17 ( & V_19 -> V_24 , L_6 ) ;
goto V_29;
}
V_14 = F_7 ( V_23 -> V_15 ) ;
if ( V_14 == 0 ) {
F_17 ( & V_19 -> V_24 , L_7 ) ;
V_20 = - V_30 ;
goto V_31;
}
if ( F_8 ( V_14 ) > V_17 + 1 ) {
F_17 ( & V_19 -> V_24 , L_8 ) ;
V_20 = - V_30 ;
goto V_31;
}
if ( F_8 ( V_14 ) == 0 )
V_23 -> V_2 . V_32 = V_33 + 1 ;
else
V_23 -> V_2 . V_32 = V_33 ;
V_23 -> V_2 . V_34 = & V_35 ;
V_23 -> V_2 . V_36 = & V_37 ;
V_23 -> V_2 . V_38 = 1 << V_17 ;
V_23 -> V_2 . V_39 = & V_19 -> V_24 ;
F_19 ( & V_23 -> V_2 , V_23 ) ;
V_20 = F_20 ( & V_23 -> V_2 , V_40 , & V_19 -> V_24 ) ;
if ( V_20 < 0 ) {
V_23 -> V_2 . V_16 = V_23 -> V_2 . V_38 ;
F_21 ( & V_19 -> V_24 ,
L_9 ) ;
}
F_4 ( & V_23 -> V_2 ) ;
V_10 = F_5 ( V_23 -> V_6 + V_7 ) ;
V_10 = ( V_10 & V_41 ) >> V_42 ;
switch ( V_10 ) {
case V_43 :
case V_44 :
V_23 -> V_2 . V_45 |= V_46 ;
F_22 ( & V_19 -> V_24 ,
L_10 ) ;
break;
case V_47 :
F_22 ( & V_19 -> V_24 ,
L_11 ) ;
break;
case V_48 :
F_22 ( & V_19 -> V_24 ,
L_12 ) ;
break;
case V_49 :
F_22 ( & V_19 -> V_24 ,
L_13 ) ;
break;
default:
F_22 ( & V_19 -> V_24 ,
L_14 , V_10 ) ;
break;
}
F_23 ( & V_23 -> V_2 , V_50 ) ;
F_24 ( V_19 , V_23 ) ;
V_20 = F_25 ( & V_23 -> V_2 ) ;
if ( V_20 )
goto V_31;
return 0 ;
V_31:
F_26 ( V_23 -> V_15 ) ;
V_29:
F_26 ( V_23 -> V_28 ) ;
return V_20 ;
}
static void F_27 ( struct V_18 * V_19 )
{
struct V_3 * V_23 = F_28 ( V_19 ) ;
F_4 ( & V_23 -> V_2 ) ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_3 * V_23 = F_28 ( V_19 ) ;
F_4 ( & V_23 -> V_2 ) ;
F_30 ( & V_23 -> V_2 ) ;
F_26 ( V_23 -> V_15 ) ;
F_26 ( V_23 -> V_28 ) ;
return 0 ;
}
