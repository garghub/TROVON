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
static void * F_13 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = & V_2 -> V_6 -> V_5 ;
V_2 -> V_19 = F_14 ( V_5 -> V_27 ) ;
if ( V_2 -> V_19 < 0 ) {
F_2 ( V_5 , L_4 ) ;
return F_15 ( - V_13 ) ;
}
if ( F_16 ( V_5 -> V_27 , L_5 , & V_2 -> V_21 ) < 0 ) {
F_2 ( V_5 , L_6 ) ;
return F_15 ( - V_13 ) ;
}
if ( V_2 -> V_21 < 0 || V_2 -> V_21 > 3 ) {
F_2 ( V_5 , L_7 ) ;
return F_15 ( - V_13 ) ;
}
V_2 -> V_28 = F_17 ( V_5 , L_8 ) ;
if ( F_18 ( V_2 -> V_28 ) ) {
F_2 ( V_5 , L_9 ) ;
return V_2 -> V_28 ;
}
F_19 ( V_2 -> V_28 , 266000000 ) ;
V_2 -> V_23 = F_20 ( V_5 -> V_27 ,
L_10 ) ;
if ( F_18 ( V_2 -> V_23 ) ) {
F_2 ( V_5 , L_11 ) ;
return V_2 -> V_23 ;
}
V_2 -> V_29 = F_20 ( V_5 -> V_27 ,
L_12 ) ;
if ( F_18 ( V_2 -> V_29 ) ) {
F_2 ( V_5 , L_13 ) ;
return V_2 -> V_29 ;
}
return NULL ;
}
static void * F_21 ( struct V_30 * V_6 )
{
struct V_4 * V_5 = & V_6 -> V_5 ;
struct V_1 * V_2 ;
int V_18 ;
void * V_31 ;
V_2 = F_22 ( V_5 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return F_15 ( - V_33 ) ;
V_2 -> V_6 = V_6 ;
V_31 = F_13 ( V_2 ) ;
if ( V_31 ) {
F_2 ( V_5 , L_14 ) ;
return V_31 ;
}
F_11 ( V_2 -> V_29 , V_34 ,
V_35 ) ;
V_18 = 12 << V_36 |
12 << V_37 ;
V_18 |= V_38 ;
switch ( V_2 -> V_19 ) {
case V_20 :
V_18 |= V_39 ;
break;
case V_22 :
V_18 &= ~ V_39 ;
break;
default:
F_2 ( & V_6 -> V_5 , L_3 ,
F_9 ( V_2 -> V_19 ) ) ;
return NULL ;
}
F_11 ( V_2 -> V_23 , F_23 ( V_2 -> V_21 ) , V_18 ) ;
F_10 ( V_2 -> V_23 , V_40 , & V_18 ) ;
V_18 &= ~ ( 1 << F_24 ( V_2 -> V_21 ) ) ;
switch ( V_2 -> V_19 ) {
case V_20 :
V_18 |= F_25 ( V_2 -> V_21 ) <<
F_24 ( V_2 -> V_21 ) ;
break;
case V_22 :
V_18 |= F_26 ( V_2 -> V_21 ) <<
F_24 ( V_2 -> V_21 ) ;
break;
default:
F_2 ( & V_6 -> V_5 , L_3 ,
F_9 ( V_2 -> V_19 ) ) ;
return NULL ;
}
F_11 ( V_2 -> V_23 , V_40 , V_18 ) ;
F_10 ( V_2 -> V_23 , V_24 , & V_18 ) ;
V_18 |= F_27 ( V_2 -> V_21 ) ;
F_11 ( V_2 -> V_23 , V_24 , V_18 ) ;
if ( V_2 -> V_19 == V_22 ) {
F_11 ( V_2 -> V_29 , F_28 ( V_2 -> V_21 ) ,
V_41 |
V_42 |
V_43 |
V_44 |
V_45 |
0x4 << V_46 |
0x3 << V_47 |
0x1 << V_48 |
0x2 << V_49 |
0xC << V_50 ) ;
}
return V_2 ;
}
static void F_29 ( void * V_51 , unsigned int V_3 )
{
struct V_1 * V_2 = V_51 ;
F_4 ( V_2 , V_3 ) ;
}
