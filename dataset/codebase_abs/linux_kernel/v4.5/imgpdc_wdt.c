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
static void F_6 ( struct V_3 * V_4 )
{
unsigned long V_13 = F_7 ( V_4 -> V_14 ) ;
unsigned int V_10 ;
V_10 = F_5 ( V_4 -> V_6 + V_11 ) & ~ V_15 ;
V_10 |= F_8 ( V_4 -> V_2 . V_16 * V_13 ) - 1 ;
F_3 ( V_10 , V_4 -> V_6 + V_11 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_17 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_2 . V_16 = V_17 ;
F_6 ( V_4 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
unsigned int V_10 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_6 ( V_4 ) ;
V_10 = F_5 ( V_4 -> V_6 + V_11 ) ;
V_10 |= V_12 ;
F_3 ( V_10 , V_4 -> V_6 + V_11 ) ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x1 , V_4 -> V_6 + V_18 ) ;
return 0 ;
}
static int F_12 ( struct V_19 * V_20 )
{
T_1 div ;
int V_21 , V_10 ;
unsigned long V_13 ;
struct V_22 * V_23 ;
struct V_3 * V_24 ;
V_24 = F_13 ( & V_20 -> V_25 , sizeof( * V_24 ) , V_26 ) ;
if ( ! V_24 )
return - V_27 ;
V_23 = F_14 ( V_20 , V_28 , 0 ) ;
V_24 -> V_6 = F_15 ( & V_20 -> V_25 , V_23 ) ;
if ( F_16 ( V_24 -> V_6 ) )
return F_17 ( V_24 -> V_6 ) ;
V_24 -> V_29 = F_18 ( & V_20 -> V_25 , L_1 ) ;
if ( F_16 ( V_24 -> V_29 ) ) {
F_19 ( & V_20 -> V_25 , L_2 ) ;
return F_17 ( V_24 -> V_29 ) ;
}
V_24 -> V_14 = F_18 ( & V_20 -> V_25 , L_3 ) ;
if ( F_16 ( V_24 -> V_14 ) ) {
F_19 ( & V_20 -> V_25 , L_4 ) ;
return F_17 ( V_24 -> V_14 ) ;
}
V_21 = F_20 ( V_24 -> V_29 ) ;
if ( V_21 ) {
F_19 ( & V_20 -> V_25 , L_5 ) ;
return V_21 ;
}
V_21 = F_20 ( V_24 -> V_14 ) ;
if ( V_21 ) {
F_19 ( & V_20 -> V_25 , L_6 ) ;
goto V_30;
}
V_13 = F_7 ( V_24 -> V_14 ) ;
if ( V_13 == 0 ) {
F_19 ( & V_20 -> V_25 , L_7 ) ;
V_21 = - V_31 ;
goto V_32;
}
if ( F_8 ( V_13 ) > V_15 + 1 ) {
F_19 ( & V_20 -> V_25 , L_8 ) ;
V_21 = - V_31 ;
goto V_32;
}
if ( F_8 ( V_13 ) == 0 )
V_24 -> V_2 . V_33 = V_34 + 1 ;
else
V_24 -> V_2 . V_33 = V_34 ;
V_24 -> V_2 . V_35 = & V_36 ;
V_24 -> V_2 . V_37 = & V_38 ;
div = 1ULL << ( V_15 + 1 ) ;
F_21 ( div , V_13 ) ;
V_24 -> V_2 . V_39 = div ;
V_24 -> V_2 . V_16 = V_40 ;
V_24 -> V_2 . V_41 = & V_20 -> V_25 ;
F_22 ( & V_24 -> V_2 , V_24 ) ;
F_23 ( & V_24 -> V_2 , V_42 , & V_20 -> V_25 ) ;
F_4 ( & V_24 -> V_2 ) ;
V_10 = F_5 ( V_24 -> V_6 + V_7 ) ;
V_10 = ( V_10 & V_43 ) >> V_44 ;
switch ( V_10 ) {
case V_45 :
case V_46 :
V_24 -> V_2 . V_47 |= V_48 ;
F_24 ( & V_20 -> V_25 ,
L_9 ) ;
break;
case V_49 :
F_24 ( & V_20 -> V_25 ,
L_10 ) ;
break;
case V_50 :
F_24 ( & V_20 -> V_25 ,
L_11 ) ;
break;
case V_51 :
F_24 ( & V_20 -> V_25 ,
L_12 ) ;
break;
default:
F_24 ( & V_20 -> V_25 ,
L_13 , V_10 ) ;
break;
}
F_25 ( & V_24 -> V_2 , V_52 ) ;
F_26 ( & V_24 -> V_2 , 128 ) ;
F_27 ( V_20 , V_24 ) ;
V_21 = F_28 ( & V_24 -> V_2 ) ;
if ( V_21 )
goto V_32;
return 0 ;
V_32:
F_29 ( V_24 -> V_14 ) ;
V_30:
F_29 ( V_24 -> V_29 ) ;
return V_21 ;
}
static void F_30 ( struct V_19 * V_20 )
{
struct V_3 * V_24 = F_31 ( V_20 ) ;
F_4 ( & V_24 -> V_2 ) ;
}
static int F_32 ( struct V_19 * V_20 )
{
struct V_3 * V_24 = F_31 ( V_20 ) ;
F_4 ( & V_24 -> V_2 ) ;
F_33 ( & V_24 -> V_2 ) ;
F_29 ( V_24 -> V_14 ) ;
F_29 ( V_24 -> V_29 ) ;
return 0 ;
}
