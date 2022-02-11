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
static int F_11 ( struct V_18 * V_19 , unsigned long V_20 ,
void * V_21 )
{
struct V_3 * V_4 = F_12 ( V_19 , struct V_3 ,
V_22 ) ;
F_3 ( 0x1 , V_4 -> V_6 + V_23 ) ;
return V_24 ;
}
static int F_13 ( struct V_25 * V_26 )
{
T_1 div ;
int V_27 , V_10 ;
unsigned long V_13 ;
struct V_28 * V_29 ;
struct V_3 * V_30 ;
V_30 = F_14 ( & V_26 -> V_31 , sizeof( * V_30 ) , V_32 ) ;
if ( ! V_30 )
return - V_33 ;
V_29 = F_15 ( V_26 , V_34 , 0 ) ;
V_30 -> V_6 = F_16 ( & V_26 -> V_31 , V_29 ) ;
if ( F_17 ( V_30 -> V_6 ) )
return F_18 ( V_30 -> V_6 ) ;
V_30 -> V_35 = F_19 ( & V_26 -> V_31 , L_1 ) ;
if ( F_17 ( V_30 -> V_35 ) ) {
F_20 ( & V_26 -> V_31 , L_2 ) ;
return F_18 ( V_30 -> V_35 ) ;
}
V_30 -> V_14 = F_19 ( & V_26 -> V_31 , L_3 ) ;
if ( F_17 ( V_30 -> V_14 ) ) {
F_20 ( & V_26 -> V_31 , L_4 ) ;
return F_18 ( V_30 -> V_14 ) ;
}
V_27 = F_21 ( V_30 -> V_35 ) ;
if ( V_27 ) {
F_20 ( & V_26 -> V_31 , L_5 ) ;
return V_27 ;
}
V_27 = F_21 ( V_30 -> V_14 ) ;
if ( V_27 ) {
F_20 ( & V_26 -> V_31 , L_6 ) ;
goto V_36;
}
V_13 = F_7 ( V_30 -> V_14 ) ;
if ( V_13 == 0 ) {
F_20 ( & V_26 -> V_31 , L_7 ) ;
V_27 = - V_37 ;
goto V_38;
}
if ( F_8 ( V_13 ) > V_15 + 1 ) {
F_20 ( & V_26 -> V_31 , L_8 ) ;
V_27 = - V_37 ;
goto V_38;
}
if ( F_8 ( V_13 ) == 0 )
V_30 -> V_2 . V_39 = V_40 + 1 ;
else
V_30 -> V_2 . V_39 = V_40 ;
V_30 -> V_2 . V_41 = & V_42 ;
V_30 -> V_2 . V_43 = & V_44 ;
div = 1ULL << ( V_15 + 1 ) ;
F_22 ( div , V_13 ) ;
V_30 -> V_2 . V_45 = div ;
V_30 -> V_2 . V_16 = V_46 ;
V_30 -> V_2 . V_47 = & V_26 -> V_31 ;
F_23 ( & V_30 -> V_2 , V_30 ) ;
F_24 ( & V_30 -> V_2 , V_48 , & V_26 -> V_31 ) ;
F_4 ( & V_30 -> V_2 ) ;
V_10 = F_5 ( V_30 -> V_6 + V_7 ) ;
V_10 = ( V_10 & V_49 ) >> V_50 ;
switch ( V_10 ) {
case V_51 :
case V_52 :
V_30 -> V_2 . V_53 |= V_54 ;
F_25 ( & V_26 -> V_31 ,
L_9 ) ;
break;
case V_55 :
F_25 ( & V_26 -> V_31 ,
L_10 ) ;
break;
case V_56 :
F_25 ( & V_26 -> V_31 ,
L_11 ) ;
break;
case V_57 :
F_25 ( & V_26 -> V_31 ,
L_12 ) ;
break;
default:
F_25 ( & V_26 -> V_31 ,
L_13 , V_10 ) ;
break;
}
F_26 ( & V_30 -> V_2 , V_58 ) ;
F_27 ( V_26 , V_30 ) ;
V_27 = F_28 ( & V_30 -> V_2 ) ;
if ( V_27 )
goto V_38;
V_30 -> V_22 . V_59 = F_11 ;
V_30 -> V_22 . V_60 = 128 ;
V_27 = F_29 ( & V_30 -> V_22 ) ;
if ( V_27 )
F_30 ( & V_26 -> V_31 , L_14 ,
V_27 ) ;
return 0 ;
V_38:
F_31 ( V_30 -> V_14 ) ;
V_36:
F_31 ( V_30 -> V_35 ) ;
return V_27 ;
}
static void F_32 ( struct V_25 * V_26 )
{
struct V_3 * V_30 = F_33 ( V_26 ) ;
F_4 ( & V_30 -> V_2 ) ;
}
static int F_34 ( struct V_25 * V_26 )
{
struct V_3 * V_30 = F_33 ( V_26 ) ;
F_4 ( & V_30 -> V_2 ) ;
F_35 ( & V_30 -> V_2 ) ;
F_31 ( V_30 -> V_14 ) ;
F_31 ( V_30 -> V_35 ) ;
return 0 ;
}
