static int F_1 ( struct V_1 * V_2 , bool V_3 ,
int * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
T_1 V_8 ;
int V_9 ;
if ( V_3 )
V_7 = V_10 ;
else
V_7 = V_11 ;
V_9 = F_3 ( V_6 -> V_12 , V_7 , & V_8 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_13 , L_1 ) ;
return V_9 ;
}
* V_4 = V_8 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_8 ;
int V_9 ;
V_9 = F_3 ( V_6 -> V_12 , V_15 , & V_8 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_13 , L_2 ) ;
return V_9 ;
}
V_8 = ( V_8 & V_16 ) >> V_17 ;
* V_14 = F_6 ( T_1 , V_8 , V_18 ) ;
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , T_1 * V_14 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_9 ;
if ( F_8 ( V_19 , & V_6 -> V_20 ) ) {
* V_14 = F_9 ( & V_6 -> V_14 ) ;
} else {
V_9 = F_5 ( V_2 , V_14 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static inline T_1 F_10 ( unsigned V_21 , unsigned V_14 )
{
return V_22 + 5 * V_21 + V_14 ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_21 ,
unsigned V_14 , T_1 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
int V_9 ;
if ( V_21 > V_23 )
return - V_24 ;
if ( V_14 > V_18 )
return - V_24 ;
V_7 = F_10 ( V_21 , V_14 ) ;
V_9 = F_3 ( V_6 -> V_12 , V_7 , V_8 ) ;
if ( V_9 )
F_4 ( & V_2 -> V_13 , L_3 ) ;
return V_9 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_21 ,
unsigned V_14 , T_1 V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
int V_9 ;
if ( V_21 > V_23 )
return - V_24 ;
if ( V_14 > V_18 )
return - V_24 ;
V_7 = F_10 ( V_21 , V_14 ) ;
V_9 = F_13 ( V_6 -> V_12 , V_7 , V_8 ) ;
if ( V_9 )
F_4 ( & V_2 -> V_13 , L_4 ) ;
return V_9 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_21 ,
int * V_8 )
{
T_1 V_14 ;
T_1 V_25 ;
int V_9 ;
V_9 = F_7 ( V_2 , & V_14 ) ;
if ( V_9 )
return V_9 ;
V_9 = F_11 ( V_2 , V_21 , V_14 , & V_25 ) ;
if ( V_9 )
return V_9 ;
* V_8 = V_25 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_26 const * V_27 ,
int * V_8 , int * V_28 , long V_29 )
{
int V_9 ;
switch ( V_29 ) {
case 0 :
switch ( V_27 -> type ) {
case V_30 :
V_9 = F_1 ( V_2 , false , V_8 ) ;
break;
case V_31 :
V_9 = F_14 ( V_2 , V_27 -> V_21 ,
V_8 ) ;
break;
default:
return - V_24 ;
}
break;
case V_32 :
V_9 = F_1 ( V_2 , true , V_8 ) ;
break;
default:
return - V_24 ;
}
if ( V_9 )
return V_9 ;
return V_33 ;
}
static T_2 F_16 ( int V_34 , void * V_35 )
{
struct V_1 * V_2 = V_35 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_14 ;
int V_9 ;
V_9 = F_5 ( V_2 , & V_14 ) ;
if ( V_9 )
goto V_36;
F_17 ( & V_6 -> V_14 , V_14 ) ;
F_18 ( V_2 ,
F_19 ( V_30 ,
0 ,
V_37 ,
V_38 ) ,
F_20 () ) ;
V_36:
return V_39 ;
}
static int F_21 ( struct V_1 * V_2 , int V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_29 = V_41 ;
T_1 V_8 ;
int V_9 ;
if ( V_40 )
V_8 = V_29 ;
else
V_8 = 0 ;
V_9 = F_22 ( V_6 -> V_12 , V_15 , V_8 , V_29 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_13 , L_5 ,
V_40 ) ;
return V_9 ;
}
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int * V_40 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_29 = V_41 ;
T_1 V_8 ;
int V_9 ;
V_9 = F_3 ( V_6 -> V_12 , V_15 , & V_8 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_13 , L_6 ) ;
return V_9 ;
}
* V_40 = ! ! ( V_8 & V_29 ) ;
return 0 ;
}
static inline T_1 F_24 ( unsigned V_42 , bool V_43 )
{
T_1 V_44 = ! V_43 ;
return V_45 + 2 * V_42 + V_44 ;
}
static int F_25 ( struct V_1 * V_2 , unsigned V_42 ,
bool V_43 , T_1 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_7 ;
int V_9 ;
if ( V_42 > V_46 )
return - V_24 ;
V_7 = F_24 ( V_42 , V_43 ) ;
V_9 = F_3 ( V_6 -> V_12 , V_7 , V_8 ) ;
if ( V_9 )
F_4 ( & V_2 -> V_13 , L_7 ) ;
return V_9 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned V_42 ,
bool V_43 , T_1 V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_28 ;
T_1 V_7 , V_47 ;
int V_9 ;
if ( V_42 > V_46 )
return - V_24 ;
V_7 = F_24 ( V_42 , V_43 ) ;
V_47 = F_24 ( V_42 , ! V_43 ) ;
F_27 ( & V_6 -> V_48 ) ;
V_9 = F_3 ( V_6 -> V_12 , V_47 , & V_28 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_13 , L_7 ) ;
goto V_36;
}
if ( ( V_43 && ( V_8 < V_28 ) ) || ( ! V_43 && ( V_8 > V_28 ) ) ) {
V_9 = - V_24 ;
goto V_36;
}
V_9 = F_13 ( V_6 -> V_12 , V_7 , V_8 ) ;
if ( V_9 ) {
F_4 ( & V_2 -> V_13 , L_8 ) ;
goto V_36;
}
V_36:
F_28 ( & V_6 -> V_48 ) ;
return V_9 ;
}
static int F_29 ( struct V_1 * V_2 , unsigned V_42 ,
T_1 * V_8 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
T_1 V_49 ;
T_1 V_43 ;
int V_9 ;
if ( V_42 > V_46 )
return - V_24 ;
F_27 ( & V_6 -> V_48 ) ;
V_9 = F_25 ( V_2 , V_42 , false , & V_49 ) ;
if ( V_9 )
goto V_36;
V_9 = F_25 ( V_2 , V_42 , true , & V_43 ) ;
if ( V_9 )
goto V_36;
* V_8 = V_43 - V_49 ;
V_36:
F_28 ( & V_6 -> V_48 ) ;
return V_9 ;
}
static T_3 F_30 ( struct V_50 * V_13 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_1 * V_2 = F_31 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_40 ;
int V_9 ;
if ( V_6 -> V_34 ) {
V_9 = F_23 ( V_2 , & V_40 ) ;
if ( V_9 )
return V_9 ;
} else {
V_40 = 0 ;
}
return F_32 ( V_53 , V_54 , L_9 , V_40 ) ;
}
static T_3 F_33 ( struct V_50 * V_13 ,
struct V_51 * V_52 ,
const char * V_53 , T_4 V_55 )
{
struct V_1 * V_2 = F_31 ( V_13 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_40 ;
bool V_56 ;
T_1 V_14 ;
int V_9 ;
if ( ! V_6 -> V_34 )
return - V_57 ;
if ( F_34 ( V_53 , 0 , & V_40 ) )
return - V_24 ;
V_56 = F_8 ( V_19 , & V_6 -> V_20 ) ;
if ( V_40 && ! V_56 ) {
V_9 = F_7 ( V_2 , & V_14 ) ;
if ( V_9 )
return V_9 ;
F_17 ( & V_6 -> V_14 , V_14 ) ;
F_35 ( V_19 , & V_6 -> V_20 ) ;
}
V_9 = F_21 ( V_2 , V_40 ) ;
if ( V_9 ) {
if ( ! V_56 )
F_36 ( V_19 , & V_6 -> V_20 ) ;
return V_9 ;
}
if ( ! V_40 )
F_36 ( V_19 , & V_6 -> V_20 ) ;
return V_55 ;
}
static T_3 F_37 ( struct V_50 * V_13 ,
struct V_51 * V_52 , char * V_53 )
{
struct V_1 * V_2 = F_31 ( V_13 ) ;
T_1 V_14 ;
int V_9 ;
V_9 = F_7 ( V_2 , & V_14 ) ;
if ( V_9 )
return V_9 ;
return F_32 ( V_53 , V_54 , L_9 , V_14 ) ;
}
static inline struct V_58 *
F_38 ( struct V_51 * V_52 )
{
return F_39 ( V_52 , struct V_58 , V_59 ) ;
}
static T_3 F_40 ( struct V_50 * V_13 ,
struct V_51 * V_52 ,
char * V_53 )
{
struct V_1 * V_2 = F_31 ( V_13 ) ;
struct V_58 * V_60 = F_38 ( V_52 ) ;
T_1 V_8 ;
int V_9 ;
switch ( V_60 -> type ) {
case V_61 :
V_9 = F_29 ( V_2 , V_60 -> V_62 ,
& V_8 ) ;
break;
case V_63 :
V_9 = F_11 ( V_2 , V_60 -> V_62 ,
V_60 -> V_28 , & V_8 ) ;
break;
case V_64 :
V_9 = F_25 ( V_2 , V_60 -> V_62 ,
false , & V_8 ) ;
break;
case V_65 :
V_9 = F_25 ( V_2 , V_60 -> V_62 ,
true , & V_8 ) ;
break;
default:
V_9 = - V_66 ;
}
if ( V_9 )
return V_9 ;
return F_32 ( V_53 , V_54 , L_9 , V_8 ) ;
}
static T_3 F_41 ( struct V_50 * V_13 ,
struct V_51 * V_52 ,
const char * V_53 , T_4 V_55 )
{
struct V_1 * V_2 = F_31 ( V_13 ) ;
struct V_58 * V_60 = F_38 ( V_52 ) ;
T_1 V_8 ;
int V_9 ;
if ( F_42 ( V_53 , 0 , & V_8 ) )
return - V_24 ;
switch ( V_60 -> type ) {
case V_63 :
V_9 = F_12 ( V_2 , V_60 -> V_62 ,
V_60 -> V_28 , V_8 ) ;
break;
case V_64 :
V_9 = F_26 ( V_2 , V_60 -> V_62 ,
false , V_8 ) ;
break;
case V_65 :
V_9 = F_26 ( V_2 , V_60 -> V_62 ,
true , V_8 ) ;
break;
default:
V_9 = - V_66 ;
}
if ( V_9 )
return V_9 ;
return V_55 ;
}
static int F_43 ( struct V_5 * V_6 , bool V_67 )
{
T_1 V_29 = V_68 ;
T_1 V_8 ;
int V_9 ;
if ( V_67 )
V_8 = V_29 ;
else
V_8 = 0 ;
V_9 = F_22 ( V_6 -> V_12 , V_69 , V_8 , V_29 ) ;
if ( V_9 ) {
F_4 ( & V_6 -> V_70 -> V_13 , L_10 ,
V_67 ) ;
return V_9 ;
}
return 0 ;
}
static int F_44 ( struct V_5 * V_6 , T_1 V_8 )
{
int V_9 ;
if ( V_8 < V_71 || V_8 > V_72 )
return - V_24 ;
V_9 = F_13 ( V_6 -> V_12 , V_73 , V_8 ) ;
if ( V_9 ) {
F_4 ( & V_6 -> V_70 -> V_13 , L_11 ) ;
return V_9 ;
}
return 0 ;
}
static int F_45 ( struct V_5 * V_6 ,
struct V_74 * V_75 )
{
int V_9 ;
V_9 = F_43 ( V_6 , V_75 -> V_67 ) ;
if ( V_9 )
return V_9 ;
if ( ! V_75 -> V_67 ) {
V_9 = F_44 ( V_6 , V_75 -> V_76 ) ;
if ( V_9 )
return V_9 ;
}
return 0 ;
}
static int F_46 ( struct V_5 * V_6 , void * V_13 )
{
T_1 V_29 = V_41 ;
int V_9 ;
V_9 = F_22 ( V_6 -> V_12 , V_15 , 0 , V_29 ) ;
if ( V_9 ) {
F_4 ( & V_6 -> V_70 -> V_13 , L_12 ) ;
return V_9 ;
}
V_9 = F_47 ( V_6 -> V_34 , NULL , F_16 ,
V_77 | V_78 ,
F_48 ( & V_6 -> V_70 -> V_13 ) , V_13 ) ;
if ( V_9 ) {
F_4 ( & V_6 -> V_70 -> V_13 , L_13 ,
V_6 -> V_34 ) ;
return V_9 ;
}
return 0 ;
}
static int F_49 ( struct V_5 * V_6 )
{
T_1 V_29 = V_79 ;
int V_9 ;
V_9 = F_22 ( V_6 -> V_12 , V_69 , V_29 , V_29 ) ;
if ( V_9 )
F_4 ( & V_6 -> V_70 -> V_13 , L_14 ) ;
return V_9 ;
}
static int F_50 ( struct V_5 * V_6 )
{
T_1 V_29 = V_79 ;
int V_9 ;
V_9 = F_22 ( V_6 -> V_12 , V_69 , 0 , V_29 ) ;
if ( V_9 )
F_4 ( & V_6 -> V_70 -> V_13 , L_15 ) ;
return V_9 ;
}
static int F_51 ( struct V_80 * V_70 )
{
struct V_12 * V_12 ;
struct V_74 * V_75 ;
struct V_5 * V_6 ;
struct V_1 * V_2 ;
int V_9 ;
V_12 = F_52 ( V_70 -> V_13 . V_81 ) ;
if ( ! V_12 )
return - V_24 ;
V_75 = V_70 -> V_13 . V_82 ;
if ( ! V_75 ) {
F_4 ( & V_70 -> V_13 , L_16 ) ;
return - V_24 ;
}
V_2 = F_53 ( & V_70 -> V_13 , sizeof( * V_6 ) ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_84 = & V_85 ;
V_2 -> V_86 = V_87 ;
V_2 -> V_88 = F_54 ( V_87 ) ;
V_2 -> V_89 = F_48 ( & V_70 -> V_13 ) ;
V_2 -> V_13 . V_81 = V_70 -> V_13 . V_81 ;
V_2 -> V_90 = V_91 ;
V_6 = F_2 ( V_2 ) ;
V_6 -> V_12 = V_12 ;
V_6 -> V_70 = V_70 ;
V_6 -> V_34 = V_12 -> V_34 ;
F_17 ( & V_6 -> V_14 , 0 ) ;
F_55 ( & V_6 -> V_48 ) ;
F_56 ( V_70 , V_2 ) ;
if ( V_6 -> V_34 ) {
V_9 = F_46 ( V_6 , V_2 ) ;
if ( V_9 )
return V_9 ;
}
V_9 = F_45 ( V_6 , V_75 ) ;
if ( V_9 )
goto V_92;
V_9 = F_49 ( V_6 ) ;
if ( V_9 )
goto V_92;
V_9 = F_57 ( V_2 ) ;
if ( V_9 ) {
F_4 ( & V_70 -> V_13 , L_17 ) ;
goto V_93;
}
return 0 ;
V_93:
F_50 ( V_6 ) ;
V_92:
if ( V_6 -> V_34 )
F_58 ( V_6 -> V_34 , V_2 ) ;
return V_9 ;
}
static int F_59 ( struct V_80 * V_70 )
{
struct V_1 * V_2 = F_60 ( V_70 ) ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
F_21 ( V_2 , false ) ;
F_61 ( V_2 ) ;
F_50 ( V_6 ) ;
if ( V_6 -> V_34 )
F_58 ( V_6 -> V_34 , V_2 ) ;
return 0 ;
}
