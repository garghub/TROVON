static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( F_3 ( V_2 -> V_6 ) ) ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
if ( V_3 == V_11 ) {
if ( V_8 && 0 != V_8 -> V_12 ) {
T_2 V_13 ;
V_13 = F_4 ( V_2 -> V_14 + V_15 ) ;
V_13 |= ( V_8 -> V_12 & V_16 )
<< V_17 ;
V_13 |= V_18 ;
F_5 ( V_13 , V_2 -> V_14 + V_15 ) ;
}
}
}
static void F_6 ( struct V_1 * V_2 , T_1 V_19 )
{
struct V_20 * V_21 = F_7 ( V_2 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
T_2 V_13 ;
int V_25 ;
if ( V_23 -> V_19 == V_26
&& V_19 == V_27 ) {
F_8 ( F_3 ( V_2 -> V_6 ) ,
L_1
L_2 ,
V_28 ,
V_23 -> V_19 ,
V_19 ) ;
V_13 = F_4 ( V_2 -> V_14 + V_29 ) ;
V_13 |= V_30 ;
F_5 ( V_13 , V_2 -> V_14 + V_29 ) ;
V_13 = F_4 ( V_2 -> V_14 + V_31 ) ;
V_13 |= V_32 ;
F_5 ( V_13 , V_2 -> V_14 + V_31 ) ;
F_9 ( 740 ) ;
V_25 = 0 ;
while ( V_25 ++ < V_33 ) {
if ( ( F_4 ( V_2 -> V_14 + V_29 )
& V_34 ) == 0 )
break;
F_9 ( 10 ) ;
}
if ( V_25 == V_33 )
F_10 ( F_3 ( V_2 -> V_6 ) , L_3 ) ;
V_13 = F_4 ( V_2 -> V_14 + V_29 ) ;
V_13 |= V_34 ;
F_5 ( V_13 , V_2 -> V_14 + V_29 ) ;
}
V_23 -> V_19 = V_19 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned int V_35 )
{
T_2 V_36 ;
V_36 = F_12 ( V_2 , V_37 ) ;
V_36 &= ~ V_38 ;
switch ( V_35 ) {
case V_39 :
V_36 |= V_40 ;
break;
case V_41 :
V_36 |= V_42 ;
break;
case V_43 :
V_36 |= V_44 | V_45 ;
break;
case V_46 :
V_36 |= V_47 | V_45 ;
break;
case V_48 :
V_36 |= V_49 | V_45 ;
break;
}
F_13 ( V_2 , V_36 , V_37 ) ;
F_8 ( F_3 ( V_2 -> V_6 ) ,
L_4 ,
V_28 , V_35 , V_36 ) ;
return 0 ;
}
static int T_3 F_14 ( struct V_4 * V_5 )
{
struct V_20 * V_21 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
struct V_50 * V_9 = & V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = NULL ;
int V_51 ;
struct V_52 * V_52 ;
V_23 = F_15 ( sizeof( struct V_22 ) , V_53 ) ;
if ( ! V_23 )
return - V_54 ;
V_2 = F_16 ( V_5 , NULL ) ;
if ( F_17 ( V_2 ) ) {
F_18 ( V_23 ) ;
return F_19 ( V_2 ) ;
}
V_21 = F_7 ( V_2 ) ;
V_21 -> V_24 = V_23 ;
V_52 = F_20 ( V_9 , L_5 ) ;
if ( F_17 ( V_52 ) ) {
F_21 ( V_9 , L_6 ) ;
V_51 = F_19 ( V_52 ) ;
goto V_55;
}
V_21 -> V_52 = V_52 ;
F_22 ( V_52 ) ;
V_2 -> V_56 = V_57
| V_58
| V_59 ;
V_2 -> V_6 -> V_60 |= V_61 ;
if ( V_8 ) {
if ( V_8 -> V_62 & V_63 ) {
V_2 -> V_56 |= V_64 ;
V_2 -> V_6 -> V_60 |= V_65 ;
}
if ( V_8 -> V_62 & V_66 )
V_2 -> V_6 -> V_60 |= V_67 ;
if ( V_8 -> V_56 )
V_2 -> V_56 |= V_8 -> V_56 ;
if ( V_8 -> V_68 )
V_2 -> V_6 -> V_60 |= V_8 -> V_68 ;
if ( V_8 -> V_69 )
V_2 -> V_6 -> V_69 |= V_8 -> V_69 ;
}
V_2 -> V_70 = & V_71 ;
V_51 = F_23 ( V_2 ) ;
if ( V_51 ) {
F_21 ( & V_5 -> V_9 , L_7 ) ;
goto V_72;
}
F_24 ( V_5 , V_2 ) ;
return 0 ;
V_72:
F_25 ( V_52 ) ;
F_26 ( V_52 ) ;
V_55:
F_27 ( V_5 ) ;
F_18 ( V_23 ) ;
return V_51 ;
}
static int T_4 F_28 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_29 ( V_5 ) ;
struct V_20 * V_21 = F_7 ( V_2 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
F_30 ( V_2 , 1 ) ;
F_25 ( V_21 -> V_52 ) ;
F_26 ( V_21 -> V_52 ) ;
F_27 ( V_5 ) ;
F_18 ( V_23 ) ;
F_24 ( V_5 , NULL ) ;
return 0 ;
}
