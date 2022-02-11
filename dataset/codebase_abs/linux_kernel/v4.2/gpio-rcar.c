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
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 , struct V_1 ,
V_10 ) ;
F_3 ( V_2 , V_12 , ~ F_6 ( F_10 ( V_9 ) ) ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 , struct V_1 ,
V_10 ) ;
F_3 ( V_2 , V_13 , F_6 ( F_10 ( V_9 ) ) ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned int V_14 ,
bool V_15 ,
bool V_16 ,
bool V_17 )
{
unsigned long V_18 ;
F_13 ( & V_2 -> V_19 , V_18 ) ;
F_5 ( V_2 , V_20 , V_14 , ! V_15 ) ;
F_5 ( V_2 , V_21 , V_14 , ! V_16 ) ;
if ( V_2 -> V_22 . V_23 )
F_5 ( V_2 , V_24 , V_14 , V_17 ) ;
F_5 ( V_2 , V_25 , V_14 , true ) ;
if ( ! V_16 )
F_3 ( V_2 , V_26 , F_6 ( V_14 ) ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_15 ( struct V_8 * V_9 , unsigned int type )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 , struct V_1 ,
V_10 ) ;
unsigned int V_14 = F_10 ( V_9 ) ;
F_16 ( & V_2 -> V_27 -> V_28 , L_1 , V_14 , type ) ;
switch ( type & V_29 ) {
case V_30 :
F_12 ( V_2 , V_14 , true , true ,
false ) ;
break;
case V_31 :
F_12 ( V_2 , V_14 , false , true ,
false ) ;
break;
case V_32 :
F_12 ( V_2 , V_14 , true , false ,
false ) ;
break;
case V_33 :
F_12 ( V_2 , V_14 , false , false ,
false ) ;
break;
case V_34 :
if ( ! V_2 -> V_22 . V_23 )
return - V_35 ;
F_12 ( V_2 , V_14 , true , false ,
true ) ;
break;
default:
return - V_35 ;
}
return 0 ;
}
static int F_17 ( struct V_8 * V_9 , unsigned int V_36 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 , struct V_1 ,
V_10 ) ;
int error ;
if ( V_2 -> V_37 ) {
error = F_18 ( V_2 -> V_37 , V_36 ) ;
if ( error ) {
F_16 ( & V_2 -> V_27 -> V_28 ,
L_2 ,
V_2 -> V_37 ) ;
V_2 -> V_37 = 0 ;
}
}
if ( ! V_2 -> V_38 )
return 0 ;
if ( V_36 )
F_19 ( V_2 -> V_38 ) ;
else
F_20 ( V_2 -> V_38 ) ;
return 0 ;
}
static T_2 F_21 ( int V_39 , void * V_40 )
{
struct V_1 * V_2 = V_40 ;
T_1 V_41 ;
unsigned int V_42 , V_43 = 0 ;
while ( ( V_41 = F_1 ( V_2 , V_44 ) &
F_1 ( V_2 , V_12 ) ) ) {
V_42 = F_22 ( V_41 ) ;
F_3 ( V_2 , V_26 , F_6 ( V_42 ) ) ;
F_23 ( F_24 ( V_2 -> V_10 . V_45 ,
V_42 ) ) ;
V_43 ++ ;
}
return V_43 ? V_46 : V_47 ;
}
static inline struct V_1 * F_25 ( struct V_10 * V_48 )
{
return F_9 ( V_48 , struct V_1 , V_10 ) ;
}
static void F_26 ( struct V_10 * V_48 ,
unsigned int V_49 ,
bool V_50 )
{
struct V_1 * V_2 = F_25 ( V_48 ) ;
unsigned long V_18 ;
F_13 ( & V_2 -> V_19 , V_18 ) ;
F_5 ( V_2 , V_20 , V_49 , false ) ;
F_5 ( V_2 , V_25 , V_49 , false ) ;
F_5 ( V_2 , V_51 , V_49 , V_50 ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_27 ( struct V_10 * V_48 , unsigned V_42 )
{
return F_28 ( V_48 -> V_4 + V_42 ) ;
}
static void F_29 ( struct V_10 * V_48 , unsigned V_42 )
{
F_30 ( V_48 -> V_4 + V_42 ) ;
F_26 ( V_48 , V_42 , false ) ;
}
static int F_31 ( struct V_10 * V_48 , unsigned V_42 )
{
F_26 ( V_48 , V_42 , false ) ;
return 0 ;
}
static int F_32 ( struct V_10 * V_48 , unsigned V_42 )
{
T_1 V_6 = F_6 ( V_42 ) ;
if ( F_1 ( F_25 ( V_48 ) , V_51 ) & V_6 )
return ! ! ( F_1 ( F_25 ( V_48 ) , V_52 ) & V_6 ) ;
else
return ! ! ( F_1 ( F_25 ( V_48 ) , V_53 ) & V_6 ) ;
}
static void F_33 ( struct V_10 * V_48 , unsigned V_42 , int V_5 )
{
struct V_1 * V_2 = F_25 ( V_48 ) ;
unsigned long V_18 ;
F_13 ( & V_2 -> V_19 , V_18 ) ;
F_5 ( V_2 , V_52 , V_42 , V_5 ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_34 ( struct V_10 * V_48 , unsigned V_42 ,
int V_5 )
{
F_33 ( V_48 , V_42 , V_5 ) ;
F_26 ( V_48 , V_42 , true ) ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 )
{
struct V_54 * V_55 = F_36 ( & V_2 -> V_27 -> V_28 ) ;
struct V_56 * V_57 = V_2 -> V_27 -> V_28 . V_58 ;
struct V_59 args ;
int V_60 ;
if ( V_55 ) {
V_2 -> V_22 = * V_55 ;
} else if ( F_37 ( V_61 ) && V_57 ) {
const struct V_62 * V_63 ;
const struct V_64 * V_65 ;
V_63 = F_38 ( V_66 , V_57 ) ;
if ( ! V_63 )
return - V_35 ;
V_65 = V_63 -> V_67 ;
V_60 = F_39 ( V_57 , L_3 , 3 , 0 ,
& args ) ;
V_2 -> V_22 . V_68 = V_60 == 0 ? args . args [ 2 ]
: V_69 ;
V_2 -> V_22 . V_70 = - 1 ;
V_2 -> V_22 . V_23 = V_65 -> V_23 ;
}
if ( V_2 -> V_22 . V_68 == 0 ||
V_2 -> V_22 . V_68 > V_69 ) {
F_40 ( & V_2 -> V_27 -> V_28 ,
L_4 ,
V_2 -> V_22 . V_68 , V_69 ) ;
V_2 -> V_22 . V_68 = V_69 ;
}
return 0 ;
}
static int F_41 ( struct V_71 * V_27 )
{
struct V_1 * V_2 ;
struct V_72 * V_73 , * V_39 ;
struct V_10 * V_10 ;
struct V_74 * V_74 ;
struct V_75 * V_28 = & V_27 -> V_28 ;
const char * V_76 = F_42 ( V_28 ) ;
int V_60 ;
V_2 = F_43 ( V_28 , sizeof( * V_2 ) , V_77 ) ;
if ( ! V_2 )
return - V_78 ;
V_2 -> V_27 = V_27 ;
F_44 ( & V_2 -> V_19 ) ;
V_60 = F_35 ( V_2 ) ;
if ( V_60 < 0 )
return V_60 ;
F_45 ( V_27 , V_2 ) ;
V_2 -> V_38 = F_46 ( V_28 , NULL ) ;
if ( F_47 ( V_2 -> V_38 ) ) {
F_40 ( V_28 , L_5 ) ;
V_2 -> V_38 = NULL ;
}
F_48 ( V_28 ) ;
F_49 ( V_28 ) ;
V_73 = F_50 ( V_27 , V_79 , 0 ) ;
V_39 = F_50 ( V_27 , V_80 , 0 ) ;
if ( ! V_73 || ! V_39 ) {
F_51 ( V_28 , L_6 ) ;
V_60 = - V_35 ;
goto V_81;
}
V_2 -> V_4 = F_52 ( V_28 , V_73 -> V_82 , F_53 ( V_73 ) ) ;
if ( ! V_2 -> V_4 ) {
F_51 ( V_28 , L_7 ) ;
V_60 = - V_83 ;
goto V_81;
}
V_10 = & V_2 -> V_10 ;
V_10 -> V_84 = F_27 ;
V_10 -> free = F_29 ;
V_10 -> V_85 = F_31 ;
V_10 -> V_86 = F_32 ;
V_10 -> V_87 = F_34 ;
V_10 -> V_88 = F_33 ;
V_10 -> V_89 = V_76 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_90 = V_91 ;
V_10 -> V_4 = V_2 -> V_22 . V_70 ;
V_10 -> V_92 = V_2 -> V_22 . V_68 ;
V_74 = & V_2 -> V_74 ;
V_74 -> V_76 = V_76 ;
V_74 -> V_93 = F_7 ;
V_74 -> V_94 = F_11 ;
V_74 -> V_95 = F_15 ;
V_74 -> V_96 = F_17 ;
V_74 -> V_18 = V_97 | V_98 ;
V_60 = F_54 ( V_10 ) ;
if ( V_60 ) {
F_51 ( V_28 , L_8 ) ;
goto V_81;
}
V_60 = F_55 ( V_10 , V_74 , V_2 -> V_22 . V_99 ,
V_100 , V_101 ) ;
if ( V_60 ) {
F_51 ( V_28 , L_9 ) ;
goto V_102;
}
V_2 -> V_37 = V_39 -> V_82 ;
if ( F_56 ( V_28 , V_39 -> V_82 , F_21 ,
V_103 , V_76 , V_2 ) ) {
F_51 ( V_28 , L_10 ) ;
V_60 = - V_104 ;
goto V_102;
}
F_57 ( V_28 , L_11 , V_2 -> V_22 . V_68 ) ;
if ( V_2 -> V_22 . V_99 ) {
V_60 = F_24 ( V_10 -> V_45 , 0 ) ;
if ( V_2 -> V_22 . V_99 != V_60 )
F_40 ( V_28 , L_12 ,
V_2 -> V_22 . V_99 , V_60 ) ;
}
if ( V_2 -> V_22 . V_105 ) {
V_60 = F_58 ( V_10 , V_2 -> V_22 . V_105 , 0 ,
V_10 -> V_4 , V_10 -> V_92 ) ;
if ( V_60 < 0 )
F_40 ( V_28 , L_13 ) ;
}
return 0 ;
V_102:
F_59 ( V_10 ) ;
V_81:
F_60 ( V_28 ) ;
F_61 ( V_28 ) ;
return V_60 ;
}
static int F_62 ( struct V_71 * V_27 )
{
struct V_1 * V_2 = F_63 ( V_27 ) ;
F_59 ( & V_2 -> V_10 ) ;
F_60 ( & V_27 -> V_28 ) ;
F_61 ( & V_27 -> V_28 ) ;
return 0 ;
}
