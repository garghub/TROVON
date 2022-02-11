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
static T_3 F_14 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = F_7 ( V_2 ) ;
return F_15 ( V_21 -> V_50 ) ;
}
static struct V_7 * F_16 ( struct V_51 * V_9 )
{
struct V_7 * V_8 ;
struct V_52 * V_53 = V_9 -> V_54 ;
T_3 V_55 ;
T_3 V_12 ;
enum V_56 V_57 ;
V_8 = F_17 ( V_9 , sizeof( * V_8 ) , V_58 ) ;
if ( ! V_8 )
return NULL ;
if ( F_18 ( V_53 , L_5 , NULL ) )
V_8 -> V_59 |= V_60 ;
F_19 ( V_53 , L_6 , & V_55 ) ;
if ( V_55 == 8 )
V_8 -> V_59 |= V_61 ;
F_19 ( V_53 , L_7 , & V_12 ) ;
if ( V_12 > 0 )
V_8 -> V_12 = V_12 ;
V_8 -> V_62 = F_20 ( V_53 , L_8 , 0 , & V_57 ) ;
if ( V_57 != V_63 )
V_8 -> V_64 |= V_65 ;
return V_8 ;
}
static inline struct V_7 * F_16 ( struct V_51 * V_9 )
{
return NULL ;
}
static int F_21 ( struct V_4 * V_5 )
{
struct V_20 * V_21 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
struct V_51 * V_9 = & V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = NULL ;
const struct V_66 * V_67 ;
int V_68 ;
struct V_50 * V_50 ;
V_23 = F_22 ( sizeof( struct V_22 ) , V_58 ) ;
if ( ! V_23 )
return - V_69 ;
V_2 = F_23 ( V_5 , NULL ) ;
if ( F_24 ( V_2 ) ) {
F_25 ( V_23 ) ;
return F_26 ( V_2 ) ;
}
V_21 = F_7 ( V_2 ) ;
V_21 -> V_24 = V_23 ;
V_50 = F_27 ( V_9 , NULL ) ;
if ( F_24 ( V_50 ) ) {
F_28 ( V_9 , L_9 ) ;
V_68 = F_26 ( V_50 ) ;
goto V_70;
}
V_21 -> V_50 = V_50 ;
F_29 ( V_50 ) ;
V_2 -> V_71 = V_72
| V_73
| V_74
| V_75 ;
V_2 -> V_6 -> V_76 |= V_77 ;
V_67 = F_30 ( F_31 ( V_78 ) , & V_5 -> V_9 ) ;
if ( V_67 )
V_8 = F_16 ( V_9 ) ;
if ( V_8 ) {
if ( V_8 -> V_59 & V_60 ) {
V_2 -> V_71 |= V_79 ;
V_2 -> V_6 -> V_76 |= V_80 ;
}
if ( V_8 -> V_59 & V_61 )
V_2 -> V_6 -> V_76 |= V_81 ;
if ( V_8 -> V_71 )
V_2 -> V_71 |= V_8 -> V_71 ;
if ( V_8 -> V_82 )
V_2 -> V_82 |= V_8 -> V_82 ;
if ( V_8 -> V_83 )
V_2 -> V_6 -> V_76 |= V_8 -> V_83 ;
if ( V_8 -> V_64 )
V_2 -> V_6 -> V_84 |= V_8 -> V_64 ;
if ( V_8 -> V_85 )
V_2 -> V_6 -> V_85 |= V_8 -> V_85 ;
if ( F_32 ( V_8 -> V_62 ) ) {
V_68 = F_33 ( V_2 -> V_6 , V_8 -> V_62 ) ;
if ( V_68 ) {
F_28 ( F_3 ( V_2 -> V_6 ) ,
L_10 ) ;
goto V_86;
}
}
}
V_2 -> V_87 = & V_88 ;
F_34 ( V_5 ) ;
V_68 = F_35 ( V_2 ) ;
if ( V_68 ) {
F_28 ( & V_5 -> V_9 , L_11 ) ;
goto V_89;
}
F_36 ( V_5 , V_2 ) ;
return 0 ;
V_89:
F_37 ( V_50 ) ;
F_38 ( V_50 ) ;
F_39 ( V_2 -> V_6 ) ;
V_86:
V_70:
F_40 ( V_5 ) ;
F_25 ( V_23 ) ;
return V_68 ;
}
static int F_41 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_42 ( V_5 ) ;
struct V_20 * V_21 = F_7 ( V_2 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
F_43 ( V_2 , 1 ) ;
F_37 ( V_21 -> V_50 ) ;
F_38 ( V_21 -> V_50 ) ;
if ( F_32 ( V_8 -> V_62 ) )
F_39 ( V_2 -> V_6 ) ;
F_40 ( V_5 ) ;
F_25 ( V_23 ) ;
F_36 ( V_5 , NULL ) ;
return 0 ;
}
