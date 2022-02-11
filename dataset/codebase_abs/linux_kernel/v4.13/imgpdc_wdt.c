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
static int F_11 ( struct V_1 * V_2 ,
unsigned long V_18 , void * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( 0x1 , V_4 -> V_6 + V_20 ) ;
return 0 ;
}
static int F_12 ( struct V_21 * V_22 )
{
T_1 div ;
int V_23 , V_10 ;
unsigned long V_13 ;
struct V_24 * V_25 ;
struct V_3 * V_26 ;
V_26 = F_13 ( & V_22 -> V_27 , sizeof( * V_26 ) , V_28 ) ;
if ( ! V_26 )
return - V_29 ;
V_25 = F_14 ( V_22 , V_30 , 0 ) ;
V_26 -> V_6 = F_15 ( & V_22 -> V_27 , V_25 ) ;
if ( F_16 ( V_26 -> V_6 ) )
return F_17 ( V_26 -> V_6 ) ;
V_26 -> V_31 = F_18 ( & V_22 -> V_27 , L_1 ) ;
if ( F_16 ( V_26 -> V_31 ) ) {
F_19 ( & V_22 -> V_27 , L_2 ) ;
return F_17 ( V_26 -> V_31 ) ;
}
V_26 -> V_14 = F_18 ( & V_22 -> V_27 , L_3 ) ;
if ( F_16 ( V_26 -> V_14 ) ) {
F_19 ( & V_22 -> V_27 , L_4 ) ;
return F_17 ( V_26 -> V_14 ) ;
}
V_23 = F_20 ( V_26 -> V_31 ) ;
if ( V_23 ) {
F_19 ( & V_22 -> V_27 , L_5 ) ;
return V_23 ;
}
V_23 = F_20 ( V_26 -> V_14 ) ;
if ( V_23 ) {
F_19 ( & V_22 -> V_27 , L_6 ) ;
goto V_32;
}
V_13 = F_7 ( V_26 -> V_14 ) ;
if ( V_13 == 0 ) {
F_19 ( & V_22 -> V_27 , L_7 ) ;
V_23 = - V_33 ;
goto V_34;
}
if ( F_8 ( V_13 ) > V_15 + 1 ) {
F_19 ( & V_22 -> V_27 , L_8 ) ;
V_23 = - V_33 ;
goto V_34;
}
if ( F_8 ( V_13 ) == 0 )
V_26 -> V_2 . V_35 = V_36 + 1 ;
else
V_26 -> V_2 . V_35 = V_36 ;
V_26 -> V_2 . V_37 = & V_38 ;
V_26 -> V_2 . V_39 = & V_40 ;
div = 1ULL << ( V_15 + 1 ) ;
F_21 ( div , V_13 ) ;
V_26 -> V_2 . V_41 = div ;
V_26 -> V_2 . V_16 = V_42 ;
V_26 -> V_2 . V_43 = & V_22 -> V_27 ;
F_22 ( & V_26 -> V_2 , V_26 ) ;
F_23 ( & V_26 -> V_2 , V_44 , & V_22 -> V_27 ) ;
F_4 ( & V_26 -> V_2 ) ;
V_10 = F_5 ( V_26 -> V_6 + V_7 ) ;
V_10 = ( V_10 & V_45 ) >> V_46 ;
switch ( V_10 ) {
case V_47 :
case V_48 :
V_26 -> V_2 . V_49 |= V_50 ;
F_24 ( & V_22 -> V_27 ,
L_9 ) ;
break;
case V_51 :
F_24 ( & V_22 -> V_27 ,
L_10 ) ;
break;
case V_52 :
F_24 ( & V_22 -> V_27 ,
L_11 ) ;
break;
case V_53 :
F_24 ( & V_22 -> V_27 ,
L_12 ) ;
break;
default:
F_24 ( & V_22 -> V_27 ,
L_13 , V_10 ) ;
break;
}
F_25 ( & V_26 -> V_2 , V_54 ) ;
F_26 ( & V_26 -> V_2 , 128 ) ;
F_27 ( V_22 , V_26 ) ;
V_23 = F_28 ( & V_26 -> V_2 ) ;
if ( V_23 )
goto V_34;
return 0 ;
V_34:
F_29 ( V_26 -> V_14 ) ;
V_32:
F_29 ( V_26 -> V_31 ) ;
return V_23 ;
}
static void F_30 ( struct V_21 * V_22 )
{
struct V_3 * V_26 = F_31 ( V_22 ) ;
F_4 ( & V_26 -> V_2 ) ;
}
static int F_32 ( struct V_21 * V_22 )
{
struct V_3 * V_26 = F_31 ( V_22 ) ;
F_4 ( & V_26 -> V_2 ) ;
F_33 ( & V_26 -> V_2 ) ;
F_29 ( V_26 -> V_14 ) ;
F_29 ( V_26 -> V_31 ) ;
return 0 ;
}
