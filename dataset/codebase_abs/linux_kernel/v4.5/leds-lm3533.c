static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_4 )
{
return V_4 -> V_5 + 2 ;
}
static inline T_1 F_4 ( struct V_1 * V_4 , T_1 V_6 )
{
return V_6 + V_4 -> V_5 ;
}
static inline T_1 F_5 ( struct V_1 * V_4 )
{
return V_4 -> V_5 ;
}
static inline T_1 F_6 ( struct V_1 * V_4 ,
T_1 V_6 )
{
return V_6 + F_5 ( V_4 ) * V_7 ;
}
static int F_7 ( struct V_1 * V_4 , int V_8 )
{
T_1 V_9 ;
T_1 V_10 ;
int V_11 ;
int V_12 ;
int V_13 = 0 ;
F_8 ( V_4 -> V_3 . V_14 , L_1 , V_15 , V_8 ) ;
F_9 ( & V_4 -> V_16 ) ;
V_12 = F_10 ( V_17 , & V_4 -> V_18 ) ;
if ( ( V_8 && V_12 ) || ( ! V_8 && ! V_12 ) )
goto V_19;
V_11 = F_5 ( V_4 ) ;
V_9 = 1 << ( 2 * V_11 ) ;
if ( V_8 )
V_10 = V_9 ;
else
V_10 = 0 ;
V_13 = F_11 ( V_4 -> V_20 , V_21 , V_10 , V_9 ) ;
if ( V_13 ) {
F_12 ( V_4 -> V_3 . V_14 , L_2 ,
V_11 , V_8 ) ;
goto V_19;
}
F_13 ( V_17 , & V_4 -> V_18 ) ;
V_19:
F_14 ( & V_4 -> V_16 ) ;
return V_13 ;
}
static int F_15 ( struct V_2 * V_3 ,
enum V_22 V_23 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_8 ( V_4 -> V_3 . V_14 , L_1 , V_15 , V_23 ) ;
if ( V_23 == 0 )
F_7 ( V_4 , 0 ) ;
return F_16 ( & V_4 -> V_24 , V_23 ) ;
}
static enum V_22 F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_10 ;
int V_13 ;
V_13 = F_18 ( & V_4 -> V_24 , & V_10 ) ;
if ( V_13 )
return V_13 ;
F_8 ( V_4 -> V_3 . V_14 , L_3 , V_15 , V_10 ) ;
return V_10 ;
}
static T_1 F_19 ( unsigned * V_25 , unsigned V_26 , unsigned V_27 ,
T_1 V_28 , T_1 V_29 )
{
unsigned V_10 ;
V_10 = ( * V_25 + V_27 / 2 - V_26 ) / V_27 + V_28 ;
* V_25 = V_27 * ( V_10 - V_28 ) + V_26 ;
return ( T_1 ) V_10 ;
}
static T_1 F_20 ( unsigned * V_30 )
{
unsigned V_25 ;
T_1 V_10 ;
V_25 = * V_30 * 1000 ;
if ( V_25 >= ( V_31 + V_32 ) / 2 ) {
V_25 = F_21 ( V_25 , V_32 , V_33 ) ;
V_10 = F_19 ( & V_25 , V_32 ,
V_34 ,
V_35 ,
V_36 ) ;
} else if ( V_25 >= ( V_37 + V_38 ) / 2 ) {
V_25 = F_21 ( V_25 , V_38 , V_31 ) ;
V_10 = F_19 ( & V_25 , V_38 ,
V_39 ,
V_40 ,
V_41 ) ;
} else {
V_25 = F_21 ( V_25 , V_42 , V_37 ) ;
V_10 = F_19 ( & V_25 , V_42 ,
V_43 ,
V_44 ,
V_45 ) ;
}
* V_30 = ( V_25 + 500 ) / 1000 ;
return V_10 ;
}
static T_1 F_22 ( struct V_1 * V_4 , T_1 V_6 ,
unsigned long * V_30 )
{
unsigned V_25 ;
T_1 V_10 ;
T_1 V_46 ;
int V_13 ;
V_25 = ( unsigned ) * V_30 ;
if ( V_6 != V_47 )
V_25 = F_23 ( V_25 , V_31 / 1000 ) ;
V_10 = F_20 ( & V_25 ) ;
F_8 ( V_4 -> V_3 . V_14 , L_4 , V_15 ,
* V_30 , V_25 , V_10 ) ;
V_46 = F_6 ( V_4 , V_6 ) ;
V_13 = F_24 ( V_4 -> V_20 , V_46 , V_10 ) ;
if ( V_13 )
F_12 ( V_4 -> V_3 . V_14 , L_5 , V_46 ) ;
* V_30 = V_25 ;
return V_13 ;
}
static int F_25 ( struct V_1 * V_4 , unsigned long * V_25 )
{
return F_22 ( V_4 , V_48 , V_25 ) ;
}
static int F_26 ( struct V_1 * V_4 , unsigned long * V_25 )
{
return F_22 ( V_4 , V_47 , V_25 ) ;
}
static int F_27 ( struct V_2 * V_3 ,
unsigned long * V_49 ,
unsigned long * V_50 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
F_8 ( V_4 -> V_3 . V_14 , L_6 , V_15 ,
* V_49 , * V_50 ) ;
if ( * V_49 > V_51 ||
* V_50 > V_52 )
return - V_53 ;
if ( * V_49 == 0 && * V_50 == 0 ) {
* V_49 = 500 ;
* V_50 = 500 ;
}
V_13 = F_25 ( V_4 , V_49 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_26 ( V_4 , V_50 ) ;
if ( V_13 )
return V_13 ;
return F_7 ( V_4 , 1 ) ;
}
static T_2 F_28 ( struct V_54 * V_14 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
return F_30 ( V_57 , V_59 , L_7 , V_4 -> V_5 ) ;
}
static T_2 F_31 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
char * V_57 , T_1 V_6 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
T_2 V_13 ;
T_1 V_46 ;
T_1 V_10 ;
V_46 = F_6 ( V_4 , V_6 ) ;
V_13 = F_32 ( V_4 -> V_20 , V_46 , & V_10 ) ;
if ( V_13 )
return V_13 ;
return F_30 ( V_57 , V_59 , L_8 , V_10 ) ;
}
static T_2 F_33 ( struct V_54 * V_14 ,
struct V_55 * V_56 , char * V_57 )
{
return F_31 ( V_14 , V_56 , V_57 ,
V_60 ) ;
}
static T_2 F_34 ( struct V_54 * V_14 ,
struct V_55 * V_56 , char * V_57 )
{
return F_31 ( V_14 , V_56 , V_57 ,
V_61 ) ;
}
static T_2 F_35 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
const char * V_57 , T_3 V_62 , T_1 V_6 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
T_1 V_10 ;
T_1 V_46 ;
int V_13 ;
if ( F_36 ( V_57 , 0 , & V_10 ) || V_10 > V_63 )
return - V_53 ;
V_46 = F_6 ( V_4 , V_6 ) ;
V_13 = F_24 ( V_4 -> V_20 , V_46 , V_10 ) ;
if ( V_13 )
return V_13 ;
return V_62 ;
}
static T_2 F_37 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
const char * V_57 , T_3 V_62 )
{
return F_35 ( V_14 , V_56 , V_57 , V_62 ,
V_60 ) ;
}
static T_2 F_38 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
const char * V_57 , T_3 V_62 )
{
return F_35 ( V_14 , V_56 , V_57 , V_62 ,
V_61 ) ;
}
static T_2 F_39 ( struct V_54 * V_14 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
unsigned V_64 ;
T_1 V_46 ;
T_1 V_10 ;
int V_13 ;
V_46 = F_4 ( V_4 , V_65 ) ;
V_13 = F_32 ( V_4 -> V_20 , V_46 , & V_10 ) ;
if ( V_13 )
return V_13 ;
V_64 = ( V_10 & V_66 ) + 1 ;
return F_30 ( V_57 , V_59 , L_9 , V_64 ) ;
}
static T_2 F_40 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
const char * V_57 , T_3 V_62 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
unsigned V_64 ;
T_1 V_46 ;
T_1 V_10 ;
T_1 V_9 ;
int V_13 ;
if ( F_41 ( V_57 , 0 , & V_64 ) )
return - V_53 ;
if ( V_64 < V_67 ||
V_64 > V_68 )
return - V_53 ;
V_46 = F_4 ( V_4 , V_65 ) ;
V_9 = V_66 ;
V_10 = V_64 - 1 ;
V_13 = F_11 ( V_4 -> V_20 , V_46 , V_10 , V_9 ) ;
if ( V_13 )
return V_13 ;
return V_62 ;
}
static T_2 F_42 ( struct V_54 * V_14 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
bool V_8 ;
T_1 V_46 ;
T_1 V_10 ;
int V_13 ;
V_46 = F_4 ( V_4 , V_65 ) ;
V_13 = F_32 ( V_4 -> V_20 , V_46 , & V_10 ) ;
if ( V_13 )
return V_13 ;
V_8 = V_10 & V_69 ;
return F_30 ( V_57 , V_59 , L_7 , V_8 ) ;
}
static T_2 F_43 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
const char * V_57 , T_3 V_62 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
unsigned V_8 ;
T_1 V_46 ;
T_1 V_9 ;
T_1 V_10 ;
int V_13 ;
if ( F_41 ( V_57 , 0 , & V_8 ) )
return - V_53 ;
V_46 = F_4 ( V_4 , V_65 ) ;
V_9 = V_69 ;
if ( V_8 )
V_10 = V_9 ;
else
V_10 = 0 ;
V_13 = F_11 ( V_4 -> V_20 , V_46 , V_10 , V_9 ) ;
if ( V_13 )
return V_13 ;
return V_62 ;
}
static T_2 F_44 ( struct V_54 * V_14 ,
struct V_55 * V_56 , char * V_57 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
T_1 V_46 ;
T_1 V_10 ;
int V_70 ;
int V_13 ;
V_46 = F_4 ( V_4 , V_65 ) ;
V_13 = F_32 ( V_4 -> V_20 , V_46 , & V_10 ) ;
if ( V_13 )
return V_13 ;
if ( V_10 & V_71 )
V_70 = 1 ;
else
V_70 = 0 ;
return F_30 ( V_57 , V_59 , L_8 , V_70 ) ;
}
static T_2 F_45 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
const char * V_57 , T_3 V_62 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
unsigned long V_70 ;
T_1 V_46 ;
T_1 V_9 ;
T_1 V_10 ;
int V_13 ;
if ( F_46 ( V_57 , 0 , & V_70 ) )
return - V_53 ;
V_46 = F_4 ( V_4 , V_65 ) ;
V_9 = V_71 ;
if ( V_70 )
V_10 = V_9 ;
else
V_10 = 0 ;
V_13 = F_11 ( V_4 -> V_20 , V_46 , V_10 , V_9 ) ;
if ( V_13 )
return V_13 ;
return V_62 ;
}
static T_2 F_47 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
char * V_57 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
T_1 V_10 ;
int V_13 ;
V_13 = F_48 ( & V_4 -> V_24 , & V_10 ) ;
if ( V_13 )
return V_13 ;
return F_30 ( V_57 , V_59 , L_9 , V_10 ) ;
}
static T_2 F_49 ( struct V_54 * V_14 ,
struct V_55 * V_56 ,
const char * V_57 , T_3 V_62 )
{
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
T_1 V_10 ;
int V_13 ;
if ( F_36 ( V_57 , 0 , & V_10 ) )
return - V_53 ;
V_13 = F_50 ( & V_4 -> V_24 , V_10 ) ;
if ( V_13 )
return V_13 ;
return V_62 ;
}
static T_4 F_51 ( struct V_72 * V_73 ,
struct V_74 * V_56 , int V_75 )
{
struct V_54 * V_14 = F_2 ( V_73 , struct V_54 , V_73 ) ;
struct V_2 * V_58 = F_29 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_58 ) ;
T_4 V_76 = V_56 -> V_76 ;
if ( V_56 == & V_77 . V_56 ||
V_56 == & V_78 . V_56 ) {
if ( ! V_4 -> V_20 -> V_79 )
V_76 = 0 ;
}
return V_76 ;
}
static int F_52 ( struct V_1 * V_4 ,
struct V_80 * V_81 )
{
int V_13 ;
V_13 = F_53 ( & V_4 -> V_24 , V_81 -> V_82 ) ;
if ( V_13 )
return V_13 ;
return F_50 ( & V_4 -> V_24 , V_81 -> V_83 ) ;
}
static int F_54 ( struct V_84 * V_85 )
{
struct V_20 * V_20 ;
struct V_80 * V_81 ;
struct V_1 * V_4 ;
int V_13 ;
F_8 ( & V_85 -> V_14 , L_10 , V_15 ) ;
V_20 = F_29 ( V_85 -> V_14 . V_86 ) ;
if ( ! V_20 )
return - V_53 ;
V_81 = F_55 ( & V_85 -> V_14 ) ;
if ( ! V_81 ) {
F_12 ( & V_85 -> V_14 , L_11 ) ;
return - V_53 ;
}
if ( V_85 -> V_5 < 0 || V_85 -> V_5 >= V_87 ) {
F_12 ( & V_85 -> V_14 , L_12 , V_85 -> V_5 ) ;
return - V_53 ;
}
V_4 = F_56 ( & V_85 -> V_14 , sizeof( * V_4 ) , V_88 ) ;
if ( ! V_4 )
return - V_89 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_3 . V_90 = V_81 -> V_90 ;
V_4 -> V_3 . V_91 = V_81 -> V_91 ;
V_4 -> V_3 . V_92 = F_15 ;
V_4 -> V_3 . V_93 = F_17 ;
V_4 -> V_3 . V_94 = F_27 ;
V_4 -> V_3 . V_95 = V_96 ;
V_4 -> V_3 . V_97 = V_98 ,
V_4 -> V_5 = V_85 -> V_5 ;
F_57 ( & V_4 -> V_16 ) ;
V_4 -> V_24 . V_20 = V_20 ;
V_4 -> V_24 . V_5 = F_3 ( V_4 ) ;
V_4 -> V_24 . V_14 = V_20 -> V_14 ;
F_58 ( V_85 , V_4 ) ;
V_13 = F_59 ( V_85 -> V_14 . V_86 , & V_4 -> V_3 ) ;
if ( V_13 ) {
F_12 ( & V_85 -> V_14 , L_13 , V_85 -> V_5 ) ;
return V_13 ;
}
V_4 -> V_24 . V_14 = V_4 -> V_3 . V_14 ;
V_13 = F_52 ( V_4 , V_81 ) ;
if ( V_13 )
goto V_99;
V_13 = F_60 ( & V_4 -> V_24 ) ;
if ( V_13 )
goto V_99;
return 0 ;
V_99:
F_61 ( & V_4 -> V_3 ) ;
return V_13 ;
}
static int F_62 ( struct V_84 * V_85 )
{
struct V_1 * V_4 = F_63 ( V_85 ) ;
F_8 ( & V_85 -> V_14 , L_10 , V_15 ) ;
F_64 ( & V_4 -> V_24 ) ;
F_61 ( & V_4 -> V_3 ) ;
return 0 ;
}
static void F_65 ( struct V_84 * V_85 )
{
struct V_1 * V_4 = F_63 ( V_85 ) ;
F_8 ( & V_85 -> V_14 , L_10 , V_15 ) ;
F_64 ( & V_4 -> V_24 ) ;
F_15 ( & V_4 -> V_3 , V_96 ) ;
}
