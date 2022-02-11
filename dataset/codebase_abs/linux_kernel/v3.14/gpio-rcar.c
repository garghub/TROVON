static inline T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
return F_2 ( V_2 -> V_4 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
T_1 V_5 )
{
F_4 ( V_5 , V_2 -> V_4 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 ,
int V_6 , bool V_5 )
{
T_1 V_7 = F_1 ( V_2 , V_3 ) ;
if ( V_5 )
V_7 |= F_6 ( V_6 ) ;
else
V_7 &= ~ F_6 ( V_6 ) ;
F_3 ( V_2 , V_3 , V_7 ) ;
}
static void F_7 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_3 ( V_2 , V_10 , ~ F_6 ( F_9 ( V_9 ) ) ) ;
}
static void F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
F_3 ( V_2 , V_11 , F_6 ( F_9 ( V_9 ) ) ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_12 ,
bool V_13 ,
bool V_14 ,
bool V_15 )
{
unsigned long V_16 ;
F_12 ( & V_2 -> V_17 , V_16 ) ;
F_5 ( V_2 , V_18 , V_12 , ! V_13 ) ;
F_5 ( V_2 , V_19 , V_12 , ! V_14 ) ;
if ( V_2 -> V_20 . V_21 )
F_5 ( V_2 , V_22 , V_12 , V_15 ) ;
F_5 ( V_2 , V_23 , V_12 , true ) ;
if ( ! V_14 )
F_3 ( V_2 , V_24 , F_6 ( V_12 ) ) ;
F_13 ( & V_2 -> V_17 , V_16 ) ;
}
static int F_14 ( struct V_8 * V_9 , unsigned int type )
{
struct V_1 * V_2 = F_8 ( V_9 ) ;
unsigned int V_12 = F_9 ( V_9 ) ;
F_15 ( & V_2 -> V_25 -> V_26 , L_1 , V_12 , type ) ;
switch ( type & V_27 ) {
case V_28 :
F_11 ( V_2 , V_12 , true , true ,
false ) ;
break;
case V_29 :
F_11 ( V_2 , V_12 , false , true ,
false ) ;
break;
case V_30 :
F_11 ( V_2 , V_12 , true , false ,
false ) ;
break;
case V_31 :
F_11 ( V_2 , V_12 , false , false ,
false ) ;
break;
case V_32 :
if ( ! V_2 -> V_20 . V_21 )
return - V_33 ;
F_11 ( V_2 , V_12 , true , false ,
true ) ;
break;
default:
return - V_33 ;
}
return 0 ;
}
static T_2 F_16 ( int V_34 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
T_1 V_36 ;
unsigned int V_37 , V_38 = 0 ;
while ( ( V_36 = F_1 ( V_2 , V_39 ) &
F_1 ( V_2 , V_10 ) ) ) {
V_37 = F_17 ( V_36 ) ;
F_3 ( V_2 , V_24 , F_6 ( V_37 ) ) ;
F_18 ( F_19 ( V_2 -> V_40 , V_37 ) ) ;
V_38 ++ ;
}
return V_38 ? V_41 : V_42 ;
}
static inline struct V_1 * F_20 ( struct V_43 * V_44 )
{
return F_21 ( V_44 , struct V_1 , V_43 ) ;
}
static void F_22 ( struct V_43 * V_44 ,
unsigned int V_45 ,
bool V_46 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
unsigned long V_16 ;
F_12 ( & V_2 -> V_17 , V_16 ) ;
F_5 ( V_2 , V_18 , V_45 , false ) ;
F_5 ( V_2 , V_23 , V_45 , false ) ;
F_5 ( V_2 , V_47 , V_45 , V_46 ) ;
F_13 ( & V_2 -> V_17 , V_16 ) ;
}
static int F_23 ( struct V_43 * V_44 , unsigned V_37 )
{
return F_24 ( V_44 -> V_4 + V_37 ) ;
}
static void F_25 ( struct V_43 * V_44 , unsigned V_37 )
{
F_26 ( V_44 -> V_4 + V_37 ) ;
F_22 ( V_44 , V_37 , false ) ;
}
static int F_27 ( struct V_43 * V_44 , unsigned V_37 )
{
F_22 ( V_44 , V_37 , false ) ;
return 0 ;
}
static int F_28 ( struct V_43 * V_44 , unsigned V_37 )
{
T_1 V_6 = F_6 ( V_37 ) ;
if ( F_1 ( F_20 ( V_44 ) , V_47 ) & V_6 )
return ( int ) ( F_1 ( F_20 ( V_44 ) , V_48 ) & V_6 ) ;
else
return ( int ) ( F_1 ( F_20 ( V_44 ) , V_49 ) & V_6 ) ;
}
static void F_29 ( struct V_43 * V_44 , unsigned V_37 , int V_5 )
{
struct V_1 * V_2 = F_20 ( V_44 ) ;
unsigned long V_16 ;
F_12 ( & V_2 -> V_17 , V_16 ) ;
F_5 ( V_2 , V_48 , V_37 , V_5 ) ;
F_13 ( & V_2 -> V_17 , V_16 ) ;
}
static int F_30 ( struct V_43 * V_44 , unsigned V_37 ,
int V_5 )
{
F_29 ( V_44 , V_37 , V_5 ) ;
F_22 ( V_44 , V_37 , true ) ;
return 0 ;
}
static int F_31 ( struct V_43 * V_44 , unsigned V_37 )
{
return F_32 ( F_20 ( V_44 ) -> V_40 , V_37 ) ;
}
static int F_33 ( struct V_40 * V_50 , unsigned int V_34 ,
T_3 V_12 )
{
struct V_1 * V_2 = V_50 -> V_51 ;
F_15 ( & V_2 -> V_25 -> V_26 , L_2 , ( int ) V_12 , V_34 ) ;
F_34 ( V_34 , V_50 -> V_51 ) ;
F_35 ( V_34 , & V_2 -> V_52 , V_53 ) ;
F_36 ( V_34 , V_54 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
struct V_55 * V_56 = F_38 ( & V_2 -> V_25 -> V_26 ) ;
struct V_57 * V_58 = V_2 -> V_25 -> V_26 . V_59 ;
struct V_60 args ;
int V_61 ;
if ( V_56 ) {
V_2 -> V_20 = * V_56 ;
} else if ( F_39 ( V_62 ) && V_58 ) {
const struct V_63 * V_64 ;
const struct V_65 * V_66 ;
V_64 = F_40 ( V_67 , V_58 ) ;
if ( ! V_64 )
return - V_33 ;
V_66 = V_64 -> V_68 ;
V_61 = F_41 ( V_58 , L_3 , 3 , 0 ,
& args ) ;
V_2 -> V_20 . V_69 = V_61 == 0 ? args . args [ 2 ]
: V_70 ;
V_2 -> V_20 . V_71 = - 1 ;
V_2 -> V_20 . V_21 = V_66 -> V_21 ;
}
if ( V_2 -> V_20 . V_69 == 0 ||
V_2 -> V_20 . V_69 > V_70 ) {
F_42 ( & V_2 -> V_25 -> V_26 ,
L_4 ,
V_2 -> V_20 . V_69 , V_70 ) ;
V_2 -> V_20 . V_69 = V_70 ;
}
return 0 ;
}
static int F_43 ( struct V_72 * V_25 )
{
struct V_1 * V_2 ;
struct V_73 * V_74 , * V_34 ;
struct V_43 * V_43 ;
struct V_52 * V_52 ;
const char * V_75 = F_44 ( & V_25 -> V_26 ) ;
int V_61 ;
V_2 = F_45 ( & V_25 -> V_26 , sizeof( * V_2 ) , V_76 ) ;
if ( ! V_2 ) {
F_46 ( & V_25 -> V_26 , L_5 ) ;
V_61 = - V_77 ;
goto V_78;
}
V_2 -> V_25 = V_25 ;
F_47 ( & V_2 -> V_17 ) ;
V_61 = F_37 ( V_2 ) ;
if ( V_61 < 0 )
return V_61 ;
F_48 ( V_25 , V_2 ) ;
V_74 = F_49 ( V_25 , V_79 , 0 ) ;
V_34 = F_49 ( V_25 , V_80 , 0 ) ;
if ( ! V_74 || ! V_34 ) {
F_46 ( & V_25 -> V_26 , L_6 ) ;
V_61 = - V_33 ;
goto V_78;
}
V_2 -> V_4 = F_50 ( & V_25 -> V_26 , V_74 -> V_81 ,
F_51 ( V_74 ) ) ;
if ( ! V_2 -> V_4 ) {
F_46 ( & V_25 -> V_26 , L_7 ) ;
V_61 = - V_82 ;
goto V_78;
}
V_43 = & V_2 -> V_43 ;
V_43 -> V_83 = F_23 ;
V_43 -> free = F_25 ;
V_43 -> V_84 = F_27 ;
V_43 -> V_85 = F_28 ;
V_43 -> V_86 = F_30 ;
V_43 -> V_87 = F_29 ;
V_43 -> V_88 = F_31 ;
V_43 -> V_89 = V_75 ;
V_43 -> V_26 = & V_25 -> V_26 ;
V_43 -> V_90 = V_91 ;
V_43 -> V_4 = V_2 -> V_20 . V_71 ;
V_43 -> V_92 = V_2 -> V_20 . V_69 ;
V_52 = & V_2 -> V_52 ;
V_52 -> V_75 = V_75 ;
V_52 -> V_93 = F_7 ;
V_52 -> V_94 = F_10 ;
V_52 -> V_95 = F_14 ;
V_52 -> V_16 = V_96 | V_97
| V_98 ;
V_2 -> V_40 = F_52 ( V_25 -> V_26 . V_59 ,
V_2 -> V_20 . V_69 ,
V_2 -> V_20 . V_99 ,
& V_100 , V_2 ) ;
if ( ! V_2 -> V_40 ) {
V_61 = - V_82 ;
F_46 ( & V_25 -> V_26 , L_8 ) ;
goto V_78;
}
if ( F_53 ( & V_25 -> V_26 , V_34 -> V_81 ,
F_16 , V_101 , V_75 , V_2 ) ) {
F_46 ( & V_25 -> V_26 , L_9 ) ;
V_61 = - V_102 ;
goto V_103;
}
V_61 = F_54 ( V_43 ) ;
if ( V_61 ) {
F_46 ( & V_25 -> V_26 , L_10 ) ;
goto V_103;
}
F_55 ( & V_25 -> V_26 , L_11 , V_2 -> V_20 . V_69 ) ;
if ( V_2 -> V_20 . V_99 ) {
V_61 = F_19 ( V_2 -> V_40 , 0 ) ;
if ( V_2 -> V_20 . V_99 != V_61 )
F_42 ( & V_25 -> V_26 , L_12 ,
V_2 -> V_20 . V_99 , V_61 ) ;
}
if ( V_2 -> V_20 . V_104 ) {
V_61 = F_56 ( V_43 , V_2 -> V_20 . V_104 , 0 ,
V_43 -> V_4 , V_43 -> V_92 ) ;
if ( V_61 < 0 )
F_42 ( & V_25 -> V_26 , L_13 ) ;
}
return 0 ;
V_103:
F_57 ( V_2 -> V_40 ) ;
V_78:
return V_61 ;
}
static int F_58 ( struct V_72 * V_25 )
{
struct V_1 * V_2 = F_59 ( V_25 ) ;
int V_61 ;
V_61 = F_60 ( & V_2 -> V_43 ) ;
if ( V_61 )
return V_61 ;
F_57 ( V_2 -> V_40 ) ;
return 0 ;
}
