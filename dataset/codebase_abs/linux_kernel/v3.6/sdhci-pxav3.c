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
static struct V_7 * F_14 ( struct V_50 * V_9 )
{
struct V_7 * V_8 ;
struct V_51 * V_52 = V_9 -> V_53 ;
T_3 V_54 ;
T_3 V_12 ;
V_8 = F_15 ( V_9 , sizeof( * V_8 ) , V_55 ) ;
if ( ! V_8 )
return NULL ;
if ( F_16 ( V_52 , L_5 , NULL ) )
V_8 -> V_56 |= V_57 ;
F_17 ( V_52 , L_6 , & V_54 ) ;
if ( V_54 == 8 )
V_8 -> V_56 |= V_58 ;
F_17 ( V_52 , L_7 , & V_12 ) ;
if ( V_12 > 0 )
V_8 -> V_12 = V_12 ;
return V_8 ;
}
static inline struct V_7 * F_14 ( struct V_50 * V_9 )
{
return NULL ;
}
static int T_4 F_18 ( struct V_4 * V_5 )
{
struct V_20 * V_21 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
struct V_50 * V_9 = & V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = NULL ;
const struct V_59 * V_60 ;
int V_61 ;
struct V_62 * V_62 ;
V_23 = F_19 ( sizeof( struct V_22 ) , V_55 ) ;
if ( ! V_23 )
return - V_63 ;
V_2 = F_20 ( V_5 , NULL ) ;
if ( F_21 ( V_2 ) ) {
F_22 ( V_23 ) ;
return F_23 ( V_2 ) ;
}
V_21 = F_7 ( V_2 ) ;
V_21 -> V_24 = V_23 ;
V_62 = F_24 ( V_9 , L_8 ) ;
if ( F_21 ( V_62 ) ) {
F_25 ( V_9 , L_9 ) ;
V_61 = F_23 ( V_62 ) ;
goto V_64;
}
V_21 -> V_62 = V_62 ;
F_26 ( V_62 ) ;
V_2 -> V_65 = V_66
| V_67
| V_68 ;
V_2 -> V_6 -> V_69 |= V_70 ;
V_60 = F_27 ( F_28 ( V_71 ) , & V_5 -> V_9 ) ;
if ( V_60 )
V_8 = F_14 ( V_9 ) ;
if ( V_8 ) {
if ( V_8 -> V_56 & V_57 ) {
V_2 -> V_65 |= V_72 ;
V_2 -> V_6 -> V_69 |= V_73 ;
}
if ( V_8 -> V_56 & V_58 )
V_2 -> V_6 -> V_69 |= V_74 ;
if ( V_8 -> V_65 )
V_2 -> V_65 |= V_8 -> V_65 ;
if ( V_8 -> V_75 )
V_2 -> V_6 -> V_69 |= V_8 -> V_75 ;
if ( V_8 -> V_76 )
V_2 -> V_6 -> V_76 |= V_8 -> V_76 ;
}
V_2 -> V_77 = & V_78 ;
V_61 = F_29 ( V_2 ) ;
if ( V_61 ) {
F_25 ( & V_5 -> V_9 , L_10 ) ;
goto V_79;
}
F_30 ( V_5 , V_2 ) ;
return 0 ;
V_79:
F_31 ( V_62 ) ;
F_32 ( V_62 ) ;
V_64:
F_33 ( V_5 ) ;
F_22 ( V_23 ) ;
return V_61 ;
}
static int T_5 F_34 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_35 ( V_5 ) ;
struct V_20 * V_21 = F_7 ( V_2 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
F_36 ( V_2 , 1 ) ;
F_31 ( V_21 -> V_62 ) ;
F_32 ( V_21 -> V_62 ) ;
F_33 ( V_5 ) ;
F_22 ( V_23 ) ;
F_30 ( V_5 , NULL ) ;
return 0 ;
}
