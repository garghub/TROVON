static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 )
{
T_2 V_5 ;
T_2 V_6 ;
T_2 V_7 = 0 ;
bool V_8 = false ;
V_5 = F_2 ( V_2 -> V_9 ) ;
switch ( V_3 ) {
case V_10 :
V_7 = V_11 ;
break;
case V_12 :
V_7 = V_13 ;
break;
case V_14 :
case V_15 :
case V_16 :
V_7 = V_13 ;
V_8 = true ;
break;
default:
F_3 ( V_2 -> V_17 ,
L_1 ,
F_4 ( V_3 ) ) ;
case V_18 :
V_7 = V_19 ;
break;
} ;
V_6 = V_20 << ( V_4 * 2 ) | F_5 ( V_4 + 6 ) ;
V_6 |= F_5 ( V_4 + 4 ) ;
V_7 <<= V_4 * 2 ;
if ( V_2 -> V_21 ) {
if ( V_4 == 0 )
V_7 |= V_22 ;
else
V_7 |= V_23 ;
}
if ( V_8 ) {
if ( V_4 == 0 )
V_7 |= V_24 ;
else
V_7 |= V_25 ;
}
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_6 ( V_5 , V_2 -> V_9 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_3 , int V_4 )
{
T_2 V_5 ;
T_2 V_6 ;
T_2 V_7 = 0 ;
V_5 = F_2 ( V_2 -> V_9 ) ;
switch ( V_3 ) {
case V_10 :
V_7 = V_11 ;
break;
case V_12 :
case V_14 :
case V_15 :
case V_16 :
V_7 = V_13 ;
break;
default:
F_3 ( V_2 -> V_17 ,
L_1 ,
F_4 ( V_3 ) ) ;
case V_18 :
V_7 = V_19 ;
break;
} ;
switch ( V_4 ) {
case 0 :
V_6 = V_20 ;
break;
case 1 :
V_6 = V_20 << 4 ;
V_7 <<= 4 ;
break;
default:
F_8 ( V_2 -> V_17 , L_2 ) ;
return;
}
if ( V_2 -> V_21 )
F_8 ( V_2 -> V_17 , L_3 ) ;
V_5 &= ~ V_6 ;
V_5 |= V_7 ;
F_6 ( V_5 , V_2 -> V_9 ) ;
}
static int F_9 ( struct V_26 * V_17 , void * V_27 )
{
struct V_28 * V_29 = (struct V_28 * ) V_27 ;
return V_17 -> V_30 == V_29 &&
V_17 -> V_31 == & V_32 . V_31 ;
}
void F_10 ( struct V_26 * V_17 , T_1 V_3 , int V_4 )
{
struct V_28 * V_29 ;
struct V_1 * V_2 ;
V_29 = F_11 ( V_17 -> V_30 , L_4 ) ;
if ( ! V_29 ) {
F_8 ( V_17 , L_5 ) ;
return;
}
V_17 = F_12 ( & V_33 , NULL , V_29 , F_9 ) ;
F_13 ( V_29 ) ;
V_2 = F_14 ( V_17 ) ;
V_2 -> F_10 ( V_2 , V_3 , V_4 ) ;
F_15 ( V_17 ) ;
}
static int F_16 ( struct V_34 * V_35 )
{
struct V_36 * V_37 ;
const struct V_38 * V_39 ;
struct V_1 * V_2 ;
V_39 = F_17 ( V_40 , V_35 -> V_17 . V_30 ) ;
if ( ! V_39 )
return - V_41 ;
V_2 = F_18 ( & V_35 -> V_17 , sizeof( * V_2 ) , V_42 ) ;
if ( ! V_2 ) {
F_8 ( & V_35 -> V_17 , L_6 ) ;
return - V_43 ;
}
V_2 -> V_17 = & V_35 -> V_17 ;
V_2 -> F_10 = V_39 -> V_27 ;
V_37 = F_19 ( V_35 , V_44 , L_7 ) ;
V_2 -> V_9 = F_20 ( & V_35 -> V_17 , V_37 ) ;
if ( F_21 ( V_2 -> V_9 ) )
return F_22 ( V_2 -> V_9 ) ;
if ( F_23 ( V_35 -> V_17 . V_30 , L_8 , NULL ) )
V_2 -> V_21 = true ;
F_24 ( & V_35 -> V_17 , V_2 ) ;
return 0 ;
}
