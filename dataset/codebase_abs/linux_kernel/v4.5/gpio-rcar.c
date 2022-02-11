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
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_3 ( V_2 , V_12 , ~ F_6 ( F_10 ( V_9 ) ) ) ;
}
static void F_11 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
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
if ( V_2 -> V_22 )
F_5 ( V_2 , V_23 , V_14 , V_17 ) ;
F_5 ( V_2 , V_24 , V_14 , true ) ;
if ( ! V_16 )
F_3 ( V_2 , V_25 , F_6 ( V_14 ) ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_15 ( struct V_8 * V_9 , unsigned int type )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
unsigned int V_14 = F_10 ( V_9 ) ;
F_16 ( & V_2 -> V_26 -> V_27 , L_1 , V_14 , type ) ;
switch ( type & V_28 ) {
case V_29 :
F_12 ( V_2 , V_14 , true , true ,
false ) ;
break;
case V_30 :
F_12 ( V_2 , V_14 , false , true ,
false ) ;
break;
case V_31 :
F_12 ( V_2 , V_14 , true , false ,
false ) ;
break;
case V_32 :
F_12 ( V_2 , V_14 , false , false ,
false ) ;
break;
case V_33 :
if ( ! V_2 -> V_22 )
return - V_34 ;
F_12 ( V_2 , V_14 , true , false ,
true ) ;
break;
default:
return - V_34 ;
}
return 0 ;
}
static int F_17 ( struct V_8 * V_9 , unsigned int V_35 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
int error ;
if ( V_2 -> V_36 ) {
error = F_18 ( V_2 -> V_36 , V_35 ) ;
if ( error ) {
F_16 ( & V_2 -> V_26 -> V_27 ,
L_2 ,
V_2 -> V_36 ) ;
V_2 -> V_36 = 0 ;
}
}
if ( ! V_2 -> V_37 )
return 0 ;
if ( V_35 )
F_19 ( V_2 -> V_37 ) ;
else
F_20 ( V_2 -> V_37 ) ;
return 0 ;
}
static void F_21 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_22 ( & V_2 -> V_26 -> V_27 ) ;
}
static void F_23 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_24 ( & V_2 -> V_26 -> V_27 ) ;
}
static int F_25 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
int error ;
error = F_22 ( & V_2 -> V_26 -> V_27 ) ;
if ( error < 0 )
return error ;
return 0 ;
}
static void F_26 ( struct V_8 * V_9 )
{
struct V_10 * V_11 = F_8 ( V_9 ) ;
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_24 ( & V_2 -> V_26 -> V_27 ) ;
}
static T_2 F_27 ( int V_38 , void * V_39 )
{
struct V_1 * V_2 = V_39 ;
T_1 V_40 ;
unsigned int V_41 , V_42 = 0 ;
while ( ( V_40 = F_1 ( V_2 , V_43 ) &
F_1 ( V_2 , V_12 ) ) ) {
V_41 = F_28 ( V_40 ) ;
F_3 ( V_2 , V_25 , F_6 ( V_41 ) ) ;
F_29 ( F_30 ( V_2 -> V_10 . V_44 ,
V_41 ) ) ;
V_42 ++ ;
}
return V_42 ? V_45 : V_46 ;
}
static void F_31 ( struct V_10 * V_47 ,
unsigned int V_48 ,
bool V_49 )
{
struct V_1 * V_2 = F_9 ( V_47 ) ;
unsigned long V_18 ;
F_13 ( & V_2 -> V_19 , V_18 ) ;
F_5 ( V_2 , V_20 , V_48 , false ) ;
F_5 ( V_2 , V_24 , V_48 , false ) ;
F_5 ( V_2 , V_50 , V_48 , V_49 ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_32 ( struct V_10 * V_47 , unsigned V_41 )
{
struct V_1 * V_2 = F_9 ( V_47 ) ;
int error ;
error = F_22 ( & V_2 -> V_26 -> V_27 ) ;
if ( error < 0 )
return error ;
error = F_33 ( V_47 -> V_4 + V_41 ) ;
if ( error )
F_24 ( & V_2 -> V_26 -> V_27 ) ;
return error ;
}
static void F_34 ( struct V_10 * V_47 , unsigned V_41 )
{
struct V_1 * V_2 = F_9 ( V_47 ) ;
F_35 ( V_47 -> V_4 + V_41 ) ;
F_31 ( V_47 , V_41 , false ) ;
F_24 ( & V_2 -> V_26 -> V_27 ) ;
}
static int F_36 ( struct V_10 * V_47 , unsigned V_41 )
{
F_31 ( V_47 , V_41 , false ) ;
return 0 ;
}
static int F_37 ( struct V_10 * V_47 , unsigned V_41 )
{
T_1 V_6 = F_6 ( V_41 ) ;
if ( F_1 ( F_9 ( V_47 ) , V_50 ) & V_6 )
return ! ! ( F_1 ( F_9 ( V_47 ) , V_51 ) & V_6 ) ;
else
return ! ! ( F_1 ( F_9 ( V_47 ) , V_52 ) & V_6 ) ;
}
static void F_38 ( struct V_10 * V_47 , unsigned V_41 , int V_5 )
{
struct V_1 * V_2 = F_9 ( V_47 ) ;
unsigned long V_18 ;
F_13 ( & V_2 -> V_19 , V_18 ) ;
F_5 ( V_2 , V_51 , V_41 , V_5 ) ;
F_14 ( & V_2 -> V_19 , V_18 ) ;
}
static int F_39 ( struct V_10 * V_47 , unsigned V_41 ,
int V_5 )
{
F_38 ( V_47 , V_41 , V_5 ) ;
F_31 ( V_47 , V_41 , true ) ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 , unsigned int * V_53 )
{
struct V_54 * V_55 = V_2 -> V_26 -> V_27 . V_56 ;
const struct V_57 * V_58 ;
const struct V_59 * V_60 ;
struct V_61 args ;
int V_62 ;
V_58 = F_41 ( V_63 , V_55 ) ;
if ( ! V_58 )
return - V_34 ;
V_60 = V_58 -> V_64 ;
V_62 = F_42 ( V_55 , L_3 , 3 , 0 , & args ) ;
* V_53 = V_62 == 0 ? args . args [ 2 ] : V_65 ;
V_2 -> V_22 = V_60 -> V_22 ;
V_2 -> V_66 = V_60 -> V_66 ;
if ( * V_53 == 0 || * V_53 > V_65 ) {
F_43 ( & V_2 -> V_26 -> V_27 ,
L_4 , * V_53 ,
V_65 ) ;
* V_53 = V_65 ;
}
return 0 ;
}
static int F_44 ( struct V_67 * V_26 )
{
struct V_1 * V_2 ;
struct V_68 * V_69 , * V_38 ;
struct V_10 * V_10 ;
struct V_70 * V_70 ;
struct V_71 * V_27 = & V_26 -> V_27 ;
const char * V_72 = F_45 ( V_27 ) ;
unsigned int V_53 ;
int V_62 ;
V_2 = F_46 ( V_27 , sizeof( * V_2 ) , V_73 ) ;
if ( ! V_2 )
return - V_74 ;
V_2 -> V_26 = V_26 ;
F_47 ( & V_2 -> V_19 ) ;
V_62 = F_40 ( V_2 , & V_53 ) ;
if ( V_62 < 0 )
return V_62 ;
F_48 ( V_26 , V_2 ) ;
V_2 -> V_37 = F_49 ( V_27 , NULL ) ;
if ( F_50 ( V_2 -> V_37 ) ) {
if ( V_2 -> V_66 ) {
F_51 ( V_27 , L_5 ) ;
V_62 = F_52 ( V_2 -> V_37 ) ;
goto V_75;
}
V_2 -> V_37 = NULL ;
}
F_53 ( V_27 ) ;
V_69 = F_54 ( V_26 , V_76 , 0 ) ;
V_38 = F_54 ( V_26 , V_77 , 0 ) ;
if ( ! V_69 || ! V_38 ) {
F_51 ( V_27 , L_6 ) ;
V_62 = - V_34 ;
goto V_75;
}
V_2 -> V_4 = F_55 ( V_27 , V_69 -> V_78 , F_56 ( V_69 ) ) ;
if ( ! V_2 -> V_4 ) {
F_51 ( V_27 , L_7 ) ;
V_62 = - V_79 ;
goto V_75;
}
V_10 = & V_2 -> V_10 ;
V_10 -> V_80 = F_32 ;
V_10 -> free = F_34 ;
V_10 -> V_81 = F_36 ;
V_10 -> V_82 = F_37 ;
V_10 -> V_83 = F_39 ;
V_10 -> V_84 = F_38 ;
V_10 -> V_85 = V_72 ;
V_10 -> V_86 = V_27 ;
V_10 -> V_87 = V_88 ;
V_10 -> V_4 = - 1 ;
V_10 -> V_89 = V_53 ;
V_70 = & V_2 -> V_70 ;
V_70 -> V_72 = V_72 ;
V_70 -> V_90 = F_7 ;
V_70 -> V_91 = F_11 ;
V_70 -> V_92 = F_15 ;
V_70 -> V_93 = F_17 ;
V_70 -> V_94 = F_21 ;
V_70 -> V_95 = F_23 ;
V_70 -> V_96 = F_25 ;
V_70 -> V_97 = F_26 ;
V_70 -> V_18 = V_98 | V_99 ;
V_62 = F_57 ( V_10 , V_2 ) ;
if ( V_62 ) {
F_51 ( V_27 , L_8 ) ;
goto V_75;
}
V_62 = F_58 ( V_10 , V_70 , 0 , V_100 ,
V_101 ) ;
if ( V_62 ) {
F_51 ( V_27 , L_9 ) ;
goto V_102;
}
V_2 -> V_36 = V_38 -> V_78 ;
if ( F_59 ( V_27 , V_38 -> V_78 , F_27 ,
V_103 , V_72 , V_2 ) ) {
F_51 ( V_27 , L_10 ) ;
V_62 = - V_104 ;
goto V_102;
}
F_60 ( V_27 , L_11 , V_53 ) ;
return 0 ;
V_102:
F_61 ( V_10 ) ;
V_75:
F_62 ( V_27 ) ;
return V_62 ;
}
static int F_63 ( struct V_67 * V_26 )
{
struct V_1 * V_2 = F_64 ( V_26 ) ;
F_61 ( & V_2 -> V_10 ) ;
F_62 ( & V_26 -> V_27 ) ;
return 0 ;
}
