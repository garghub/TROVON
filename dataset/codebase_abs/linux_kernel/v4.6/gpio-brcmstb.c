static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return V_5 -> V_6 ;
}
static void F_3 ( struct V_4 * V_5 ,
unsigned int V_7 , bool V_8 )
{
struct V_2 * V_3 = & V_5 -> V_3 ;
struct V_1 * V_9 = V_5 -> V_6 ;
T_1 V_10 = V_3 -> V_11 ( V_3 , V_7 ) ;
T_1 V_12 ;
unsigned long V_13 ;
F_4 ( & V_3 -> V_14 , V_13 ) ;
V_12 = V_3 -> V_15 ( V_9 -> V_16 + F_5 ( V_5 -> V_17 ) ) ;
if ( V_8 )
V_12 |= V_10 ;
else
V_12 &= ~ V_10 ;
V_3 -> V_18 ( V_9 -> V_16 + F_5 ( V_5 -> V_17 ) , V_12 ) ;
F_6 ( & V_3 -> V_14 , V_13 ) ;
}
static void F_7 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_8 ( V_20 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_3 ( V_5 , V_20 -> V_21 , false ) ;
}
static void F_9 ( struct V_19 * V_20 )
{
struct V_2 * V_3 = F_8 ( V_20 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
F_3 ( V_5 , V_20 -> V_21 , true ) ;
}
static int F_10 ( struct V_19 * V_20 , unsigned int type )
{
struct V_2 * V_3 = F_8 ( V_20 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
struct V_1 * V_9 = V_5 -> V_6 ;
T_1 V_10 = F_11 ( V_20 -> V_21 ) ;
T_1 V_22 , V_23 ;
T_1 V_24 , V_25 ;
T_1 V_26 , V_27 ;
unsigned long V_13 ;
switch ( type ) {
case V_28 :
V_26 = 0 ;
V_24 = 0 ;
V_22 = 0 ;
break;
case V_29 :
V_26 = V_10 ;
V_24 = 0 ;
V_22 = 0 ;
break;
case V_30 :
V_26 = 0 ;
V_24 = 0 ;
V_22 = 0 ;
break;
case V_31 :
V_26 = 0 ;
V_24 = V_10 ;
V_22 = 0 ;
break;
case V_32 :
V_26 = 0 ;
V_24 = 0 ;
V_22 = V_10 ;
break;
default:
return - V_33 ;
}
F_4 ( & V_5 -> V_3 . V_14 , V_13 ) ;
V_25 = V_5 -> V_3 . V_15 ( V_9 -> V_16 +
F_12 ( V_5 -> V_17 ) ) & ~ V_10 ;
V_23 = V_5 -> V_3 . V_15 ( V_9 -> V_16 +
F_13 ( V_5 -> V_17 ) ) & ~ V_10 ;
V_27 = V_5 -> V_3 . V_15 ( V_9 -> V_16 +
F_14 ( V_5 -> V_17 ) ) & ~ V_10 ;
V_5 -> V_3 . V_18 ( V_9 -> V_16 + F_12 ( V_5 -> V_17 ) ,
V_25 | V_24 ) ;
V_5 -> V_3 . V_18 ( V_9 -> V_16 + F_13 ( V_5 -> V_17 ) ,
V_23 | V_22 ) ;
V_5 -> V_3 . V_18 ( V_9 -> V_16 + F_14 ( V_5 -> V_17 ) ,
V_27 | V_26 ) ;
F_6 ( & V_5 -> V_3 . V_14 , V_13 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_9 ,
unsigned int V_8 )
{
int V_34 = 0 ;
if ( V_8 )
V_34 = F_16 ( V_9 -> V_35 ) ;
else
V_34 = F_17 ( V_9 -> V_35 ) ;
if ( V_34 )
F_18 ( & V_9 -> V_36 -> V_37 , L_1 ,
V_8 ? L_2 : L_3 ) ;
return V_34 ;
}
static int F_19 ( struct V_19 * V_20 , unsigned int V_8 )
{
struct V_2 * V_3 = F_8 ( V_20 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_15 ( V_9 , V_8 ) ;
}
static T_2 F_20 ( int V_38 , void * V_39 )
{
struct V_1 * V_9 = V_39 ;
if ( ! V_9 || V_38 != V_9 -> V_35 )
return V_40 ;
F_21 ( & V_9 -> V_36 -> V_37 , 0 ) ;
return V_41 ;
}
static void F_22 ( struct V_4 * V_5 )
{
struct V_1 * V_9 = V_5 -> V_6 ;
struct V_42 * V_42 = V_5 -> V_3 . V_43 ;
void T_3 * V_16 = V_9 -> V_16 ;
unsigned long V_44 ;
unsigned long V_13 ;
F_4 ( & V_5 -> V_3 . V_14 , V_13 ) ;
while ( ( V_44 = V_5 -> V_3 . V_15 ( V_16 + F_23 ( V_5 -> V_17 ) ) &
V_5 -> V_3 . V_15 ( V_16 + F_5 ( V_5 -> V_17 ) ) ) ) {
int V_45 ;
F_24 (bit, &status, 32 ) {
T_1 V_46 = V_5 -> V_3 . V_15 ( V_16 +
F_23 ( V_5 -> V_17 ) ) ;
if ( V_45 >= V_5 -> V_47 )
F_25 ( & V_9 -> V_36 -> V_37 ,
L_4 ,
V_5 -> V_17 , V_45 ) ;
V_5 -> V_3 . V_18 ( V_16 + F_23 ( V_5 -> V_17 ) ,
V_46 | F_11 ( V_45 ) ) ;
F_26 ( F_27 ( V_42 , V_45 ) ) ;
}
}
F_6 ( & V_5 -> V_3 . V_14 , V_13 ) ;
}
static void F_28 ( struct V_48 * V_49 )
{
struct V_2 * V_3 = F_29 ( V_49 ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_50 * V_51 = F_30 ( V_49 ) ;
struct V_4 * V_5 ;
F_31 ( ! V_9 || ! V_51 ) ;
F_32 ( V_51 , V_49 ) ;
F_33 (bank, &priv->bank_list, node)
F_22 ( V_5 ) ;
F_34 ( V_51 , V_49 ) ;
}
static int F_35 ( struct V_52 * V_53 ,
unsigned long V_54 , void * V_39 )
{
struct V_1 * V_9 =
F_36 ( V_53 , struct V_1 , V_55 ) ;
if ( V_54 == V_56 )
F_15 ( V_9 , 1 ) ;
return V_57 ;
}
static int F_37 ( struct V_58 * V_37 ,
struct V_59 * V_60 , struct V_61 * V_62 )
{
int V_63 = F_38 ( V_62 ) / V_64 ;
int V_65 =
F_39 ( V_60 , L_5 ) ;
if ( V_63 != V_65 ) {
F_18 ( V_37 , L_6 ,
V_63 , V_65 ) ;
return - V_33 ;
} else {
return 0 ;
}
}
static int F_40 ( struct V_66 * V_36 )
{
struct V_1 * V_9 = F_41 ( V_36 ) ;
struct V_4 * V_5 ;
int V_34 = 0 ;
if ( ! V_9 ) {
F_18 ( & V_36 -> V_37 , L_7 , V_67 ) ;
return - V_68 ;
}
F_33 (bank, &priv->bank_list, node)
F_42 ( & V_5 -> V_3 ) ;
if ( V_9 -> V_55 . V_69 ) {
V_34 = F_43 ( & V_9 -> V_55 ) ;
if ( V_34 )
F_18 ( & V_36 -> V_37 ,
L_8 ) ;
}
return V_34 ;
}
static int F_44 ( struct V_2 * V_3 ,
const struct V_70 * V_71 , T_1 * V_13 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_4 * V_5 = F_2 ( V_3 ) ;
int V_7 ;
if ( V_3 -> V_72 != 2 ) {
F_45 ( 1 ) ;
return - V_33 ;
}
if ( F_45 ( V_71 -> V_73 < V_3 -> V_72 ) )
return - V_33 ;
V_7 = V_71 -> args [ 0 ] - ( V_3 -> V_74 - V_9 -> V_75 ) ;
if ( V_7 >= V_3 -> V_76 || V_7 < 0 )
return - V_33 ;
if ( F_46 ( V_7 >= V_5 -> V_47 ) ) {
F_47 ( & V_9 -> V_36 -> V_37 ,
L_9 ,
V_71 -> args [ 0 ] ) ;
}
if ( V_13 )
* V_13 = V_71 -> args [ 1 ] ;
return V_7 ;
}
static int F_48 ( struct V_66 * V_36 ,
struct V_4 * V_5 )
{
struct V_1 * V_9 = V_5 -> V_6 ;
struct V_58 * V_37 = & V_36 -> V_37 ;
struct V_59 * V_60 = V_37 -> V_77 ;
V_5 -> V_50 . V_78 = F_49 ( V_37 ) ;
V_5 -> V_50 . V_79 = F_7 ;
V_5 -> V_50 . V_80 = F_9 ;
V_5 -> V_50 . V_81 = F_10 ;
V_5 -> V_50 . V_13 = V_82 ;
if ( F_50 ( V_83 ) && ! V_9 -> V_84 &&
F_51 ( V_60 , L_10 ) ) {
V_9 -> V_35 = F_52 ( V_36 , 1 ) ;
if ( V_9 -> V_35 < 0 ) {
F_25 ( V_37 ,
L_11 ) ;
} else {
int V_85 ;
F_53 ( V_37 , true ) ;
F_54 ( V_37 ) ;
V_85 = F_55 ( V_37 , V_9 -> V_35 ,
F_20 , 0 ,
L_12 , V_9 ) ;
if ( V_85 < 0 ) {
F_18 ( V_37 , L_13 ) ;
return V_85 ;
}
V_9 -> V_55 . V_69 =
F_35 ;
F_56 ( & V_9 -> V_55 ) ;
V_9 -> V_84 = true ;
}
}
if ( V_9 -> V_84 )
V_5 -> V_50 . V_86 = F_19 ;
F_57 ( & V_5 -> V_3 , & V_5 -> V_50 , 0 ,
V_87 , V_88 ) ;
F_58 ( & V_5 -> V_3 , & V_5 -> V_50 ,
V_9 -> V_89 , F_28 ) ;
return 0 ;
}
static int F_59 ( struct V_66 * V_36 )
{
struct V_58 * V_37 = & V_36 -> V_37 ;
struct V_59 * V_60 = V_37 -> V_77 ;
void T_3 * V_16 ;
struct V_1 * V_9 ;
struct V_61 * V_62 ;
struct V_90 * V_91 ;
const T_4 * V_92 ;
T_1 V_93 ;
int V_65 = 0 ;
int V_85 ;
static int V_75 ;
unsigned long V_13 = 0 ;
V_9 = F_60 ( V_37 , sizeof( * V_9 ) , V_94 ) ;
if ( ! V_9 )
return - V_95 ;
F_61 ( V_36 , V_9 ) ;
F_62 ( & V_9 -> V_96 ) ;
V_62 = F_63 ( V_36 , V_97 , 0 ) ;
V_16 = F_64 ( V_37 , V_62 ) ;
if ( F_65 ( V_16 ) )
return F_66 ( V_16 ) ;
V_9 -> V_75 = V_75 ;
V_9 -> V_16 = V_16 ;
V_9 -> V_36 = V_36 ;
if ( F_51 ( V_60 , L_14 ) ) {
V_9 -> V_89 = F_52 ( V_36 , 0 ) ;
if ( V_9 -> V_89 <= 0 ) {
F_18 ( V_37 , L_15 ) ;
return - V_98 ;
}
} else {
V_9 -> V_89 = - V_98 ;
}
if ( F_37 ( V_37 , V_60 , V_62 ) )
return - V_33 ;
#if F_67 ( V_99 ) && F_67 ( V_100 )
V_13 = V_101 ;
#endif
F_68 (np, L_5 , prop, p,
bank_width) {
struct V_4 * V_5 ;
struct V_2 * V_3 ;
V_5 = F_60 ( V_37 , sizeof( * V_5 ) , V_94 ) ;
if ( ! V_5 ) {
V_85 = - V_95 ;
goto V_102;
}
V_5 -> V_6 = V_9 ;
V_5 -> V_17 = V_65 ;
if ( V_93 <= 0 || V_93 > V_103 ) {
F_18 ( V_37 , L_16 , V_93 ) ;
goto V_102;
} else {
V_5 -> V_47 = V_93 ;
}
V_3 = & V_5 -> V_3 ;
V_85 = F_69 ( V_3 , V_37 , 4 ,
V_16 + F_70 ( V_5 -> V_17 ) ,
NULL , NULL , NULL ,
V_16 + F_71 ( V_5 -> V_17 ) , V_13 ) ;
if ( V_85 ) {
F_18 ( V_37 , L_17 ) ;
goto V_102;
}
V_3 -> V_77 = V_60 ;
V_3 -> V_104 = V_105 ;
V_3 -> V_106 = V_60 -> V_107 ;
V_3 -> V_74 = V_75 ;
V_3 -> V_72 = 2 ;
V_3 -> V_108 = F_44 ;
V_3 -> V_76 = V_103 ;
V_3 -> V_18 ( V_16 + F_5 ( V_5 -> V_17 ) , 0 ) ;
V_85 = F_72 ( V_3 , V_5 ) ;
if ( V_85 ) {
F_18 ( V_37 , L_18 ,
V_5 -> V_17 ) ;
goto V_102;
}
V_75 += V_3 -> V_76 ;
if ( V_9 -> V_89 > 0 ) {
V_85 = F_48 ( V_36 , V_5 ) ;
if ( V_85 )
goto V_102;
}
F_73 ( V_37 , L_19 , V_5 -> V_17 ,
V_3 -> V_74 , V_3 -> V_76 , V_5 -> V_47 ) ;
F_74 ( & V_5 -> V_109 , & V_9 -> V_96 ) ;
V_65 ++ ;
}
F_75 ( V_37 , L_20 ,
V_65 , V_9 -> V_75 , V_75 - 1 ) ;
return 0 ;
V_102:
( void ) F_40 ( V_36 ) ;
return V_85 ;
}
