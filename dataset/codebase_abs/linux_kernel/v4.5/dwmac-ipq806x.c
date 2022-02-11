static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 -> V_5 ;
int div ;
switch ( V_3 ) {
case V_7 :
div = V_8 ;
break;
case V_9 :
div = V_10 ;
break;
case V_11 :
div = V_12 ;
break;
default:
F_2 ( V_5 , L_1 , V_3 ) ;
return - V_13 ;
}
return div ;
}
static int F_3 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = & V_2 -> V_6 -> V_5 ;
int div ;
switch ( V_3 ) {
case V_7 :
div = V_14 ;
break;
case V_9 :
div = V_15 ;
break;
case V_11 :
div = V_16 ;
break;
default:
F_2 ( V_5 , L_2 , V_3 ) ;
return - V_13 ;
}
return div ;
}
static int F_4 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_1 V_17 , V_18 ;
int div ;
switch ( V_2 -> V_19 ) {
case V_20 :
div = F_3 ( V_2 , V_3 ) ;
V_17 = F_5 ( V_2 -> V_21 ) |
F_6 ( V_2 -> V_21 ) ;
break;
case V_22 :
div = F_1 ( V_2 , V_3 ) ;
V_17 = F_7 ( V_2 -> V_21 ) |
F_8 ( V_2 -> V_21 ) ;
break;
default:
F_2 ( & V_2 -> V_6 -> V_5 , L_3 ,
F_9 ( V_2 -> V_19 ) ) ;
return - V_13 ;
}
F_10 ( V_2 -> V_23 , V_24 , & V_18 ) ;
V_18 &= ~ V_17 ;
F_11 ( V_2 -> V_23 , V_24 , V_18 ) ;
F_10 ( V_2 -> V_23 , V_25 , & V_18 ) ;
V_18 &= ~ ( V_26
<< F_12 ( V_2 -> V_21 ) ) ;
V_18 |= div << F_12 ( V_2 -> V_21 ) ;
F_11 ( V_2 -> V_23 , V_25 , V_18 ) ;
F_10 ( V_2 -> V_23 , V_24 , & V_18 ) ;
V_18 |= V_17 ;
F_11 ( V_2 -> V_23 , V_24 , V_18 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 -> V_5 ;
V_2 -> V_19 = F_14 ( V_5 -> V_27 ) ;
if ( V_2 -> V_19 < 0 ) {
F_2 ( V_5 , L_4 ) ;
return - V_13 ;
}
if ( F_15 ( V_5 -> V_27 , L_5 , & V_2 -> V_21 ) < 0 ) {
F_2 ( V_5 , L_6 ) ;
return - V_13 ;
}
if ( V_2 -> V_21 < 0 || V_2 -> V_21 > 3 ) {
F_2 ( V_5 , L_7 ) ;
return - V_13 ;
}
V_2 -> V_28 = F_16 ( V_5 , L_8 ) ;
if ( F_17 ( V_2 -> V_28 ) ) {
F_2 ( V_5 , L_9 ) ;
return F_18 ( V_2 -> V_28 ) ;
}
F_19 ( V_2 -> V_28 , 266000000 ) ;
V_2 -> V_23 = F_20 ( V_5 -> V_27 ,
L_10 ) ;
if ( F_17 ( V_2 -> V_23 ) ) {
F_2 ( V_5 , L_11 ) ;
return F_18 ( V_2 -> V_23 ) ;
}
V_2 -> V_29 = F_20 ( V_5 -> V_27 ,
L_12 ) ;
if ( F_17 ( V_2 -> V_29 ) )
F_2 ( V_5 , L_13 ) ;
return F_21 ( V_2 -> V_29 ) ;
}
static void F_22 ( void * V_30 , unsigned int V_3 )
{
struct V_1 * V_2 = V_30 ;
F_4 ( V_2 , V_3 ) ;
}
static int F_23 ( struct V_31 * V_6 )
{
struct V_32 * V_33 ;
struct V_34 V_35 ;
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_1 * V_2 ;
int V_18 ;
int V_36 ;
V_18 = F_24 ( V_6 , & V_35 ) ;
if ( V_18 )
return V_18 ;
V_33 = F_25 ( V_6 , & V_35 . V_37 ) ;
if ( F_17 ( V_33 ) )
return F_18 ( V_33 ) ;
V_2 = F_26 ( V_5 , sizeof( * V_2 ) , V_38 ) ;
if ( ! V_2 )
return - V_39 ;
V_2 -> V_6 = V_6 ;
V_36 = F_13 ( V_2 ) ;
if ( V_36 ) {
F_2 ( V_5 , L_14 ) ;
return V_36 ;
}
F_11 ( V_2 -> V_29 , V_40 ,
V_41 ) ;
V_18 = 12 << V_42 |
12 << V_43 ;
V_18 |= V_44 ;
switch ( V_2 -> V_19 ) {
case V_20 :
V_18 |= V_45 ;
break;
case V_22 :
V_18 &= ~ V_45 ;
break;
default:
F_2 ( & V_6 -> V_5 , L_3 ,
F_9 ( V_2 -> V_19 ) ) ;
return - V_13 ;
}
F_11 ( V_2 -> V_23 , F_27 ( V_2 -> V_21 ) , V_18 ) ;
F_10 ( V_2 -> V_23 , V_46 , & V_18 ) ;
V_18 &= ~ ( 1 << F_28 ( V_2 -> V_21 ) ) ;
switch ( V_2 -> V_19 ) {
case V_20 :
V_18 |= F_29 ( V_2 -> V_21 ) <<
F_28 ( V_2 -> V_21 ) ;
break;
case V_22 :
V_18 |= F_30 ( V_2 -> V_21 ) <<
F_28 ( V_2 -> V_21 ) ;
break;
default:
F_2 ( & V_6 -> V_5 , L_3 ,
F_9 ( V_2 -> V_19 ) ) ;
return - V_13 ;
}
F_11 ( V_2 -> V_23 , V_46 , V_18 ) ;
F_10 ( V_2 -> V_23 , V_24 , & V_18 ) ;
V_18 |= F_31 ( V_2 -> V_21 ) ;
F_11 ( V_2 -> V_23 , V_24 , V_18 ) ;
if ( V_2 -> V_19 == V_22 ) {
F_11 ( V_2 -> V_29 , F_32 ( V_2 -> V_21 ) ,
V_47 |
V_48 |
V_49 |
V_50 |
V_51 |
0x4ul << V_52 |
0x3ul << V_53 |
0x1ul << V_54 |
0x2ul << V_55 |
0xCul << V_56 ) ;
}
V_33 -> V_57 = true ;
V_33 -> V_58 = V_2 ;
V_33 -> V_59 = F_22 ;
return F_33 ( & V_6 -> V_5 , V_33 , & V_35 ) ;
}
