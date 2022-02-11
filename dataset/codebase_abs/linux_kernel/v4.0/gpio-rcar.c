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
static T_2 F_17 ( int V_36 , void * V_37 )
{
struct V_1 * V_2 = V_37 ;
T_1 V_38 ;
unsigned int V_39 , V_40 = 0 ;
while ( ( V_38 = F_1 ( V_2 , V_41 ) &
F_1 ( V_2 , V_12 ) ) ) {
V_39 = F_18 ( V_38 ) ;
F_3 ( V_2 , V_26 , F_6 ( V_39 ) ) ;
F_19 ( F_20 ( V_2 -> V_10 . V_42 ,
V_39 ) ) ;
V_40 ++ ;
}
return V_40 ? V_43 : V_44 ;
}
static inline struct V_1 * F_21 ( struct V_10 * V_45 )
{
return F_9 ( V_45 , struct V_1 , V_10 ) ;
}
static void F_22 ( struct V_10 * V_45 ,
unsigned int V_46 ,
bool V_47 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
unsigned long V_18 ;
F_13 ( & V_2 -> V_19 , V_18 ) ;
F_5 ( V_2 , V_20 , V_46 , false ) ;
F_5 ( V_2 , V_25 , V_46 , false ) ;
F_5 ( V_2 , V_48 , V_46 , V_47 ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_23 ( struct V_10 * V_45 , unsigned V_39 )
{
return F_24 ( V_45 -> V_4 + V_39 ) ;
}
static void F_25 ( struct V_10 * V_45 , unsigned V_39 )
{
F_26 ( V_45 -> V_4 + V_39 ) ;
F_22 ( V_45 , V_39 , false ) ;
}
static int F_27 ( struct V_10 * V_45 , unsigned V_39 )
{
F_22 ( V_45 , V_39 , false ) ;
return 0 ;
}
static int F_28 ( struct V_10 * V_45 , unsigned V_39 )
{
T_1 V_6 = F_6 ( V_39 ) ;
if ( F_1 ( F_21 ( V_45 ) , V_48 ) & V_6 )
return ! ! ( F_1 ( F_21 ( V_45 ) , V_49 ) & V_6 ) ;
else
return ! ! ( F_1 ( F_21 ( V_45 ) , V_50 ) & V_6 ) ;
}
static void F_29 ( struct V_10 * V_45 , unsigned V_39 , int V_5 )
{
struct V_1 * V_2 = F_21 ( V_45 ) ;
unsigned long V_18 ;
F_13 ( & V_2 -> V_19 , V_18 ) ;
F_5 ( V_2 , V_49 , V_39 , V_5 ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_30 ( struct V_10 * V_45 , unsigned V_39 ,
int V_5 )
{
F_29 ( V_45 , V_39 , V_5 ) ;
F_22 ( V_45 , V_39 , true ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_51 * V_52 = F_32 ( & V_2 -> V_27 -> V_28 ) ;
struct V_53 * V_54 = V_2 -> V_27 -> V_28 . V_55 ;
struct V_56 args ;
int V_57 ;
if ( V_52 ) {
V_2 -> V_22 = * V_52 ;
} else if ( F_33 ( V_58 ) && V_54 ) {
const struct V_59 * V_60 ;
const struct V_61 * V_62 ;
V_60 = F_34 ( V_63 , V_54 ) ;
if ( ! V_60 )
return - V_35 ;
V_62 = V_60 -> V_64 ;
V_57 = F_35 ( V_54 , L_2 , 3 , 0 ,
& args ) ;
V_2 -> V_22 . V_65 = V_57 == 0 ? args . args [ 2 ]
: V_66 ;
V_2 -> V_22 . V_67 = - 1 ;
V_2 -> V_22 . V_23 = V_62 -> V_23 ;
}
if ( V_2 -> V_22 . V_65 == 0 ||
V_2 -> V_22 . V_65 > V_66 ) {
F_36 ( & V_2 -> V_27 -> V_28 ,
L_3 ,
V_2 -> V_22 . V_65 , V_66 ) ;
V_2 -> V_22 . V_65 = V_66 ;
}
return 0 ;
}
static int F_37 ( struct V_68 * V_27 )
{
struct V_1 * V_2 ;
struct V_69 * V_70 , * V_36 ;
struct V_10 * V_10 ;
struct V_71 * V_71 ;
struct V_72 * V_28 = & V_27 -> V_28 ;
const char * V_73 = F_38 ( V_28 ) ;
int V_57 ;
V_2 = F_39 ( V_28 , sizeof( * V_2 ) , V_74 ) ;
if ( ! V_2 )
return - V_75 ;
V_2 -> V_27 = V_27 ;
F_40 ( & V_2 -> V_19 ) ;
V_57 = F_31 ( V_2 ) ;
if ( V_57 < 0 )
return V_57 ;
F_41 ( V_27 , V_2 ) ;
F_42 ( V_28 ) ;
F_43 ( V_28 ) ;
V_70 = F_44 ( V_27 , V_76 , 0 ) ;
V_36 = F_44 ( V_27 , V_77 , 0 ) ;
if ( ! V_70 || ! V_36 ) {
F_45 ( V_28 , L_4 ) ;
V_57 = - V_35 ;
goto V_78;
}
V_2 -> V_4 = F_46 ( V_28 , V_70 -> V_79 , F_47 ( V_70 ) ) ;
if ( ! V_2 -> V_4 ) {
F_45 ( V_28 , L_5 ) ;
V_57 = - V_80 ;
goto V_78;
}
V_10 = & V_2 -> V_10 ;
V_10 -> V_81 = F_23 ;
V_10 -> free = F_25 ;
V_10 -> V_82 = F_27 ;
V_10 -> V_83 = F_28 ;
V_10 -> V_84 = F_30 ;
V_10 -> V_85 = F_29 ;
V_10 -> V_86 = V_73 ;
V_10 -> V_28 = V_28 ;
V_10 -> V_87 = V_88 ;
V_10 -> V_4 = V_2 -> V_22 . V_67 ;
V_10 -> V_89 = V_2 -> V_22 . V_65 ;
V_71 = & V_2 -> V_71 ;
V_71 -> V_73 = V_73 ;
V_71 -> V_90 = F_7 ;
V_71 -> V_91 = F_11 ;
V_71 -> V_92 = F_15 ;
V_71 -> V_18 = V_93 | V_94
| V_95 ;
V_57 = F_48 ( V_10 ) ;
if ( V_57 ) {
F_45 ( V_28 , L_6 ) ;
goto V_78;
}
V_57 = F_49 ( & V_2 -> V_10 , V_71 , V_2 -> V_22 . V_96 ,
V_97 , V_98 ) ;
if ( V_57 ) {
F_45 ( V_28 , L_7 ) ;
goto V_99;
}
if ( F_50 ( V_28 , V_36 -> V_79 , F_17 ,
V_100 , V_73 , V_2 ) ) {
F_45 ( V_28 , L_8 ) ;
V_57 = - V_101 ;
goto V_99;
}
F_51 ( V_28 , L_9 , V_2 -> V_22 . V_65 ) ;
if ( V_2 -> V_22 . V_96 ) {
V_57 = F_20 ( V_2 -> V_10 . V_42 , 0 ) ;
if ( V_2 -> V_22 . V_96 != V_57 )
F_36 ( V_28 , L_10 ,
V_2 -> V_22 . V_96 , V_57 ) ;
}
if ( V_2 -> V_22 . V_102 ) {
V_57 = F_52 ( V_10 , V_2 -> V_22 . V_102 , 0 ,
V_10 -> V_4 , V_10 -> V_89 ) ;
if ( V_57 < 0 )
F_36 ( V_28 , L_11 ) ;
}
return 0 ;
V_99:
F_53 ( & V_2 -> V_10 ) ;
V_78:
F_54 ( V_28 ) ;
F_55 ( V_28 ) ;
return V_57 ;
}
static int F_56 ( struct V_68 * V_27 )
{
struct V_1 * V_2 = F_57 ( V_27 ) ;
F_53 ( & V_2 -> V_10 ) ;
F_54 ( & V_27 -> V_28 ) ;
F_55 ( & V_27 -> V_28 ) ;
return 0 ;
}
