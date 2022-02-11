static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static inline struct V_6 *
F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return V_7 -> V_8 ;
}
static void F_5 ( struct V_1 * V_7 ,
unsigned int V_9 , bool V_10 )
{
struct V_4 * V_5 = & V_7 -> V_5 ;
struct V_6 * V_11 = V_7 -> V_8 ;
T_1 V_12 = V_5 -> V_13 ( V_5 , V_9 ) ;
T_1 V_14 ;
unsigned long V_15 ;
F_6 ( & V_5 -> V_16 , V_15 ) ;
V_14 = V_5 -> V_17 ( V_11 -> V_18 + F_7 ( V_7 -> V_19 ) ) ;
if ( V_10 )
V_14 |= V_12 ;
else
V_14 &= ~ V_12 ;
V_5 -> V_20 ( V_11 -> V_18 + F_7 ( V_7 -> V_19 ) , V_14 ) ;
F_8 ( & V_5 -> V_16 , V_15 ) ;
}
static void F_9 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = F_10 ( V_22 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_5 ( V_7 , V_22 -> V_23 , false ) ;
}
static void F_11 ( struct V_21 * V_22 )
{
struct V_2 * V_3 = F_10 ( V_22 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_5 ( V_7 , V_22 -> V_23 , true ) ;
}
static int F_12 ( struct V_21 * V_22 , unsigned int type )
{
struct V_2 * V_3 = F_10 ( V_22 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_11 = V_7 -> V_8 ;
T_1 V_12 = F_13 ( V_22 -> V_23 ) ;
T_1 V_24 , V_25 ;
T_1 V_26 , V_27 ;
T_1 V_28 , V_29 ;
unsigned long V_15 ;
switch ( type ) {
case V_30 :
V_28 = 0 ;
V_26 = 0 ;
V_24 = 0 ;
break;
case V_31 :
V_28 = V_12 ;
V_26 = 0 ;
V_24 = 0 ;
break;
case V_32 :
V_28 = 0 ;
V_26 = 0 ;
V_24 = 0 ;
break;
case V_33 :
V_28 = 0 ;
V_26 = V_12 ;
V_24 = 0 ;
break;
case V_34 :
V_28 = 0 ;
V_26 = 0 ;
V_24 = V_12 ;
break;
default:
return - V_35 ;
}
F_6 ( & V_7 -> V_5 . V_16 , V_15 ) ;
V_27 = V_7 -> V_5 . V_17 ( V_11 -> V_18 +
F_14 ( V_7 -> V_19 ) ) & ~ V_12 ;
V_25 = V_7 -> V_5 . V_17 ( V_11 -> V_18 +
F_15 ( V_7 -> V_19 ) ) & ~ V_12 ;
V_29 = V_7 -> V_5 . V_17 ( V_11 -> V_18 +
F_16 ( V_7 -> V_19 ) ) & ~ V_12 ;
V_7 -> V_5 . V_20 ( V_11 -> V_18 + F_14 ( V_7 -> V_19 ) ,
V_27 | V_26 ) ;
V_7 -> V_5 . V_20 ( V_11 -> V_18 + F_15 ( V_7 -> V_19 ) ,
V_25 | V_24 ) ;
V_7 -> V_5 . V_20 ( V_11 -> V_18 + F_16 ( V_7 -> V_19 ) ,
V_29 | V_28 ) ;
F_8 ( & V_7 -> V_5 . V_16 , V_15 ) ;
return 0 ;
}
static int F_17 ( struct V_6 * V_11 ,
unsigned int V_10 )
{
int V_36 = 0 ;
if ( V_10 )
V_36 = F_18 ( V_11 -> V_37 ) ;
else
V_36 = F_19 ( V_11 -> V_37 ) ;
if ( V_36 )
F_20 ( & V_11 -> V_38 -> V_39 , L_1 ,
V_10 ? L_2 : L_3 ) ;
return V_36 ;
}
static int F_21 ( struct V_21 * V_22 , unsigned int V_10 )
{
struct V_2 * V_3 = F_10 ( V_22 ) ;
struct V_6 * V_11 = F_4 ( V_3 ) ;
return F_17 ( V_11 , V_10 ) ;
}
static T_2 F_22 ( int V_40 , void * V_41 )
{
struct V_6 * V_11 = V_41 ;
if ( ! V_11 || V_40 != V_11 -> V_37 )
return V_42 ;
F_23 ( & V_11 -> V_38 -> V_39 , 0 ) ;
return V_43 ;
}
static void F_24 ( struct V_1 * V_7 )
{
struct V_6 * V_11 = V_7 -> V_8 ;
struct V_44 * V_44 = V_7 -> V_5 . V_3 . V_45 ;
void T_3 * V_18 = V_11 -> V_18 ;
unsigned long V_46 ;
unsigned long V_15 ;
F_6 ( & V_7 -> V_5 . V_16 , V_15 ) ;
while ( ( V_46 = V_7 -> V_5 . V_17 ( V_18 + F_25 ( V_7 -> V_19 ) ) &
V_7 -> V_5 . V_17 ( V_18 + F_7 ( V_7 -> V_19 ) ) ) ) {
int V_47 ;
F_26 (bit, &status, 32 ) {
T_1 V_48 = V_7 -> V_5 . V_17 ( V_18 +
F_25 ( V_7 -> V_19 ) ) ;
if ( V_47 >= V_7 -> V_49 )
F_27 ( & V_11 -> V_38 -> V_39 ,
L_4 ,
V_7 -> V_19 , V_47 ) ;
V_7 -> V_5 . V_20 ( V_18 + F_25 ( V_7 -> V_19 ) ,
V_48 | F_13 ( V_47 ) ) ;
F_28 ( F_29 ( V_44 , V_47 ) ) ;
}
}
F_8 ( & V_7 -> V_5 . V_16 , V_15 ) ;
}
static void F_30 ( struct V_50 * V_51 )
{
struct V_2 * V_3 = F_31 ( V_51 ) ;
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_52 * V_53 = F_32 ( V_51 ) ;
struct V_54 * V_55 ;
F_33 ( ! V_11 || ! V_53 ) ;
F_34 ( V_53 , V_51 ) ;
F_35 (pos, &priv->bank_list) {
struct V_1 * V_7 =
F_36 ( V_55 , struct V_1 , V_56 ) ;
F_24 ( V_7 ) ;
}
F_37 ( V_53 , V_51 ) ;
}
static int F_38 ( struct V_57 * V_58 ,
unsigned long V_59 , void * V_41 )
{
struct V_6 * V_11 =
F_3 ( V_58 , struct V_6 , V_60 ) ;
if ( V_59 == V_61 )
F_17 ( V_11 , 1 ) ;
return V_62 ;
}
static int F_39 ( struct V_63 * V_39 ,
struct V_64 * V_65 , struct V_66 * V_67 )
{
int V_68 = F_40 ( V_67 ) / V_69 ;
int V_70 =
F_41 ( V_65 , L_5 ) ;
if ( V_68 != V_70 ) {
F_20 ( V_39 , L_6 ,
V_68 , V_70 ) ;
return - V_35 ;
} else {
return 0 ;
}
}
static int F_42 ( struct V_71 * V_38 )
{
struct V_6 * V_11 = F_43 ( V_38 ) ;
struct V_54 * V_55 ;
struct V_1 * V_7 ;
int V_36 = 0 ;
if ( ! V_11 ) {
F_20 ( & V_38 -> V_39 , L_7 , V_72 ) ;
return - V_73 ;
}
F_35 (pos, &priv->bank_list) {
V_7 = F_36 ( V_55 , struct V_1 , V_56 ) ;
V_36 = F_44 ( & V_7 -> V_5 ) ;
if ( V_36 )
F_20 ( & V_38 -> V_39 , L_8 ) ;
}
if ( V_11 -> V_60 . V_74 ) {
V_36 = F_45 ( & V_11 -> V_60 ) ;
if ( V_36 )
F_20 ( & V_38 -> V_39 ,
L_9 ) ;
}
return V_36 ;
}
static int F_46 ( struct V_2 * V_3 ,
const struct V_75 * V_76 , T_1 * V_15 )
{
struct V_6 * V_11 = F_4 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_9 ;
if ( V_3 -> V_77 != 2 ) {
F_47 ( 1 ) ;
return - V_35 ;
}
if ( F_47 ( V_76 -> V_78 < V_3 -> V_77 ) )
return - V_35 ;
V_9 = V_76 -> args [ 0 ] - ( V_3 -> V_79 - V_11 -> V_80 ) ;
if ( V_9 >= V_3 -> V_81 || V_9 < 0 )
return - V_35 ;
if ( F_48 ( V_9 >= V_7 -> V_49 ) ) {
F_49 ( & V_11 -> V_38 -> V_39 ,
L_10 ,
V_76 -> args [ 0 ] ) ;
}
if ( V_15 )
* V_15 = V_76 -> args [ 1 ] ;
return V_9 ;
}
static int F_50 ( struct V_71 * V_38 ,
struct V_1 * V_7 )
{
struct V_6 * V_11 = V_7 -> V_8 ;
struct V_63 * V_39 = & V_38 -> V_39 ;
struct V_64 * V_65 = V_39 -> V_82 ;
V_7 -> V_52 . V_83 = F_51 ( V_39 ) ;
V_7 -> V_52 . V_84 = F_9 ;
V_7 -> V_52 . V_85 = F_11 ;
V_7 -> V_52 . V_86 = F_12 ;
V_7 -> V_52 . V_15 = V_87 ;
if ( F_52 ( V_88 ) && ! V_11 -> V_89 &&
F_53 ( V_65 , L_11 ) ) {
V_11 -> V_37 = F_54 ( V_38 , 1 ) ;
if ( V_11 -> V_37 < 0 ) {
F_27 ( V_39 ,
L_12 ) ;
} else {
int V_90 ;
F_55 ( V_39 , true ) ;
F_56 ( V_39 ) ;
V_90 = F_57 ( V_39 , V_11 -> V_37 ,
F_22 , 0 ,
L_13 , V_11 ) ;
if ( V_90 < 0 ) {
F_20 ( V_39 , L_14 ) ;
return V_90 ;
}
V_11 -> V_60 . V_74 =
F_38 ;
F_58 ( & V_11 -> V_60 ) ;
V_11 -> V_89 = true ;
}
}
if ( V_11 -> V_89 )
V_7 -> V_52 . V_91 = F_21 ;
F_59 ( & V_7 -> V_5 . V_3 , & V_7 -> V_52 , 0 ,
V_92 , V_93 ) ;
F_60 ( & V_7 -> V_5 . V_3 , & V_7 -> V_52 ,
V_11 -> V_94 , F_30 ) ;
return 0 ;
}
static int F_61 ( struct V_71 * V_38 )
{
struct V_63 * V_39 = & V_38 -> V_39 ;
struct V_64 * V_65 = V_39 -> V_82 ;
void T_3 * V_18 ;
struct V_6 * V_11 ;
struct V_66 * V_67 ;
struct V_95 * V_96 ;
const T_4 * V_97 ;
T_1 V_98 ;
int V_70 = 0 ;
int V_90 ;
static int V_80 ;
V_11 = F_62 ( V_39 , sizeof( * V_11 ) , V_99 ) ;
if ( ! V_11 )
return - V_100 ;
F_63 ( V_38 , V_11 ) ;
F_64 ( & V_11 -> V_101 ) ;
V_67 = F_65 ( V_38 , V_102 , 0 ) ;
V_18 = F_66 ( V_39 , V_67 ) ;
if ( F_67 ( V_18 ) )
return F_68 ( V_18 ) ;
V_11 -> V_80 = V_80 ;
V_11 -> V_18 = V_18 ;
V_11 -> V_38 = V_38 ;
if ( F_53 ( V_65 , L_15 ) ) {
V_11 -> V_94 = F_54 ( V_38 , 0 ) ;
if ( V_11 -> V_94 <= 0 ) {
F_20 ( V_39 , L_16 ) ;
return - V_103 ;
}
} else {
V_11 -> V_94 = - V_103 ;
}
if ( F_39 ( V_39 , V_65 , V_67 ) )
return - V_35 ;
F_69 (np, L_5 , prop, p,
bank_width) {
struct V_1 * V_7 ;
struct V_4 * V_5 ;
struct V_2 * V_3 ;
V_7 = F_62 ( V_39 , sizeof( * V_7 ) , V_99 ) ;
if ( ! V_7 ) {
V_90 = - V_100 ;
goto V_104;
}
V_7 -> V_8 = V_11 ;
V_7 -> V_19 = V_70 ;
if ( V_98 <= 0 || V_98 > V_105 ) {
F_20 ( V_39 , L_17 , V_98 ) ;
goto V_104;
} else {
V_7 -> V_49 = V_98 ;
}
V_5 = & V_7 -> V_5 ;
V_90 = F_70 ( V_5 , V_39 , 4 ,
V_18 + F_71 ( V_7 -> V_19 ) ,
NULL , NULL , NULL ,
V_18 + F_72 ( V_7 -> V_19 ) , 0 ) ;
if ( V_90 ) {
F_20 ( V_39 , L_18 ) ;
goto V_104;
}
V_3 = & V_5 -> V_3 ;
V_3 -> V_82 = V_65 ;
V_3 -> V_106 = V_107 ;
V_3 -> V_108 = V_65 -> V_109 ;
V_3 -> V_79 = V_80 ;
V_3 -> V_77 = 2 ;
V_3 -> V_110 = F_46 ;
V_3 -> V_81 = V_105 ;
V_7 -> V_5 . V_20 ( V_18 + F_7 ( V_7 -> V_19 ) , 0 ) ;
V_90 = F_73 ( V_3 ) ;
if ( V_90 ) {
F_20 ( V_39 , L_19 ,
V_7 -> V_19 ) ;
goto V_104;
}
V_80 += V_3 -> V_81 ;
if ( V_11 -> V_94 > 0 ) {
V_90 = F_50 ( V_38 , V_7 ) ;
if ( V_90 )
goto V_104;
}
F_74 ( V_39 , L_20 , V_7 -> V_19 ,
V_3 -> V_79 , V_3 -> V_81 , V_7 -> V_49 ) ;
F_75 ( & V_7 -> V_56 , & V_11 -> V_101 ) ;
V_70 ++ ;
}
F_76 ( V_39 , L_21 ,
V_70 , V_11 -> V_80 , V_80 - 1 ) ;
return 0 ;
V_104:
( void ) F_42 ( V_38 ) ;
return V_90 ;
}
