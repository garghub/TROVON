static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
F_2 ( * F_3 ( V_2 ) , F_4 ( V_2 , 0 ) ,
F_5 ( V_2 ) ) ;
V_2 -> V_6 . V_7 ++ ;
V_5 = F_6 ( V_2 ) ;
if ( V_5 < 0 ) {
F_7 ( V_2 ) ;
return 1 ;
}
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_7 ( V_2 ) ;
return 1 ;
}
static int F_9 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
F_7 ( V_2 ) ;
return 1 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( F_11 ( V_2 ) & V_8 ) {
F_12 ( * F_3 ( V_2 ) , true ) ;
V_2 -> V_6 . V_9 ++ ;
F_13 ( V_2 , F_14 ( V_2 ) ) ;
} else {
F_12 ( * F_3 ( V_2 ) , false ) ;
V_2 -> V_6 . V_10 ++ ;
F_15 ( V_2 ) ;
F_16 ( V_11 , V_2 ) ;
}
F_17 ( V_2 , F_18 ( V_2 ) ) ;
return 1 ;
}
static int F_19 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_12 = F_11 ( V_2 ) ;
int V_5 = 0 ;
V_4 -> V_13 = V_14 ;
V_4 -> V_15 . V_16 . V_12 = V_12 ;
switch ( F_20 ( V_12 ) ) {
case V_17 :
V_4 -> V_15 . V_16 . V_18 = V_2 -> V_16 . V_19 . V_20 ;
case V_21 :
case V_22 :
case V_23 :
case V_24 :
break;
default:
F_21 ( L_1 ,
V_25 , ( unsigned int ) V_12 ) ;
V_5 = - 1 ;
break;
}
return V_5 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
T_1 V_12 = F_11 ( V_2 ) ;
F_23 ( L_2 ,
V_12 , F_24 ( V_12 ) ) ;
F_7 ( V_2 ) ;
return 1 ;
}
static T_2 F_25 ( struct V_1 * V_2 )
{
T_1 V_12 = F_11 ( V_2 ) ;
T_3 V_26 = F_20 ( V_12 ) ;
return V_27 [ V_26 ] ;
}
int F_26 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_28 )
{
T_2 V_29 ;
if ( F_27 ( V_28 ) ) {
T_3 V_26 = F_20 ( F_11 ( V_2 ) ) ;
if ( V_26 == V_30 || V_26 == V_31 ||
V_26 == V_32 || V_26 == V_33 ) {
T_1 V_34 = F_18 ( V_2 ) ? 4 : 2 ;
* F_3 ( V_2 ) -= V_34 ;
}
F_28 ( V_2 ) ;
return 1 ;
}
V_28 = F_29 ( V_28 ) ;
switch ( V_28 ) {
case V_35 :
return 1 ;
case V_36 :
F_28 ( V_2 ) ;
return 1 ;
case V_37 :
if ( ! F_30 ( V_2 ) ) {
F_17 ( V_2 , F_18 ( V_2 ) ) ;
return 1 ;
}
V_29 = F_25 ( V_2 ) ;
return V_29 ( V_2 , V_4 ) ;
case V_38 :
V_4 -> V_13 = V_39 ;
return 0 ;
default:
F_23 ( L_3 ,
V_28 ) ;
V_4 -> V_13 = V_40 ;
return 0 ;
}
}
