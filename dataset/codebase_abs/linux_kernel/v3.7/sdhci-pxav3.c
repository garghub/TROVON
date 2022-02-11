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
enum V_55 V_56 ;
V_8 = F_15 ( V_9 , sizeof( * V_8 ) , V_57 ) ;
if ( ! V_8 )
return NULL ;
if ( F_16 ( V_52 , L_5 , NULL ) )
V_8 -> V_58 |= V_59 ;
F_17 ( V_52 , L_6 , & V_54 ) ;
if ( V_54 == 8 )
V_8 -> V_58 |= V_60 ;
F_17 ( V_52 , L_7 , & V_12 ) ;
if ( V_12 > 0 )
V_8 -> V_12 = V_12 ;
V_8 -> V_61 = F_18 ( V_52 , L_8 , 0 , & V_56 ) ;
if ( V_56 != V_62 )
V_8 -> V_63 |= V_64 ;
return V_8 ;
}
static inline struct V_7 * F_14 ( struct V_50 * V_9 )
{
return NULL ;
}
static int T_4 F_19 ( struct V_4 * V_5 )
{
struct V_20 * V_21 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
struct V_50 * V_9 = & V_5 -> V_9 ;
struct V_1 * V_2 = NULL ;
struct V_22 * V_23 = NULL ;
const struct V_65 * V_66 ;
int V_67 ;
struct V_68 * V_68 ;
V_23 = F_20 ( sizeof( struct V_22 ) , V_57 ) ;
if ( ! V_23 )
return - V_69 ;
V_2 = F_21 ( V_5 , NULL ) ;
if ( F_22 ( V_2 ) ) {
F_23 ( V_23 ) ;
return F_24 ( V_2 ) ;
}
V_21 = F_7 ( V_2 ) ;
V_21 -> V_24 = V_23 ;
V_68 = F_25 ( V_9 , NULL ) ;
if ( F_22 ( V_68 ) ) {
F_26 ( V_9 , L_9 ) ;
V_67 = F_24 ( V_68 ) ;
goto V_70;
}
V_21 -> V_68 = V_68 ;
F_27 ( V_68 ) ;
V_2 -> V_71 = V_72
| V_73
| V_74 ;
V_2 -> V_6 -> V_75 |= V_76 ;
V_66 = F_28 ( F_29 ( V_77 ) , & V_5 -> V_9 ) ;
if ( V_66 )
V_8 = F_14 ( V_9 ) ;
if ( V_8 ) {
if ( V_8 -> V_58 & V_59 ) {
V_2 -> V_71 |= V_78 ;
V_2 -> V_6 -> V_75 |= V_79 ;
}
if ( V_8 -> V_58 & V_60 )
V_2 -> V_6 -> V_75 |= V_80 ;
if ( V_8 -> V_71 )
V_2 -> V_71 |= V_8 -> V_71 ;
if ( V_8 -> V_81 )
V_2 -> V_6 -> V_75 |= V_8 -> V_81 ;
if ( V_8 -> V_63 )
V_2 -> V_6 -> V_82 |= V_8 -> V_63 ;
if ( V_8 -> V_83 )
V_2 -> V_6 -> V_83 |= V_8 -> V_83 ;
if ( F_30 ( V_8 -> V_61 ) ) {
V_67 = F_31 ( V_2 -> V_6 , V_8 -> V_61 ) ;
if ( V_67 ) {
F_26 ( F_3 ( V_2 -> V_6 ) ,
L_10 ) ;
goto V_84;
}
}
}
V_2 -> V_85 = & V_86 ;
F_32 ( V_5 ) ;
V_67 = F_33 ( V_2 ) ;
if ( V_67 ) {
F_26 ( & V_5 -> V_9 , L_11 ) ;
goto V_87;
}
F_34 ( V_5 , V_2 ) ;
return 0 ;
V_87:
F_35 ( V_68 ) ;
F_36 ( V_68 ) ;
F_37 ( V_2 -> V_6 ) ;
V_84:
V_70:
F_38 ( V_5 ) ;
F_23 ( V_23 ) ;
return V_67 ;
}
static int T_5 F_39 ( struct V_4 * V_5 )
{
struct V_1 * V_2 = F_40 ( V_5 ) ;
struct V_20 * V_21 = F_7 ( V_2 ) ;
struct V_22 * V_23 = V_21 -> V_24 ;
struct V_7 * V_8 = V_5 -> V_9 . V_10 ;
F_41 ( V_2 , 1 ) ;
F_35 ( V_21 -> V_68 ) ;
F_36 ( V_21 -> V_68 ) ;
if ( F_30 ( V_8 -> V_61 ) )
F_37 ( V_2 -> V_6 ) ;
F_38 ( V_5 ) ;
F_23 ( V_23 ) ;
F_34 ( V_5 , NULL ) ;
return 0 ;
}
