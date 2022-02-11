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
static void F_15 ( struct V_22 * V_23 )
{
struct V_1 * V_4 = F_2 ( V_23 , struct V_1 , V_23 ) ;
F_8 ( V_4 -> V_3 . V_14 , L_3 , V_15 , V_4 -> V_24 ) ;
if ( V_4 -> V_24 == 0 )
F_7 ( V_4 , 0 ) ;
F_16 ( & V_4 -> V_25 , V_4 -> V_24 ) ;
}
static void F_17 ( struct V_2 * V_3 ,
enum V_26 V_27 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_8 ( V_4 -> V_3 . V_14 , L_1 , V_15 , V_27 ) ;
V_4 -> V_24 = V_27 ;
F_18 ( & V_4 -> V_23 ) ;
}
static enum V_26 F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
T_1 V_10 ;
int V_13 ;
V_13 = F_20 ( & V_4 -> V_25 , & V_10 ) ;
if ( V_13 )
return V_13 ;
F_8 ( V_4 -> V_3 . V_14 , L_3 , V_15 , V_10 ) ;
return V_10 ;
}
static T_1 F_21 ( unsigned * V_28 , unsigned V_29 , unsigned V_30 ,
T_1 V_31 , T_1 V_32 )
{
unsigned V_10 ;
V_10 = ( * V_28 + V_30 / 2 - V_29 ) / V_30 + V_31 ;
* V_28 = V_30 * ( V_10 - V_31 ) + V_29 ;
return ( T_1 ) V_10 ;
}
static T_1 F_22 ( unsigned * V_33 )
{
unsigned V_28 ;
T_1 V_10 ;
V_28 = * V_33 * 1000 ;
if ( V_28 >= ( V_34 + V_35 ) / 2 ) {
V_28 = F_23 ( V_28 , V_35 , V_36 ) ;
V_10 = F_21 ( & V_28 , V_35 ,
V_37 ,
V_38 ,
V_39 ) ;
} else if ( V_28 >= ( V_40 + V_41 ) / 2 ) {
V_28 = F_23 ( V_28 , V_41 , V_34 ) ;
V_10 = F_21 ( & V_28 , V_41 ,
V_42 ,
V_43 ,
V_44 ) ;
} else {
V_28 = F_23 ( V_28 , V_45 , V_40 ) ;
V_10 = F_21 ( & V_28 , V_45 ,
V_46 ,
V_47 ,
V_48 ) ;
}
* V_33 = ( V_28 + 500 ) / 1000 ;
return V_10 ;
}
static T_1 F_24 ( struct V_1 * V_4 , T_1 V_6 ,
unsigned long * V_33 )
{
unsigned V_28 ;
T_1 V_10 ;
T_1 V_49 ;
int V_13 ;
V_28 = ( unsigned ) * V_33 ;
if ( V_6 != V_50 )
V_28 = F_25 ( V_28 , V_34 / 1000 ) ;
V_10 = F_22 ( & V_28 ) ;
F_8 ( V_4 -> V_3 . V_14 , L_4 , V_15 ,
* V_33 , V_28 , V_10 ) ;
V_49 = F_6 ( V_4 , V_6 ) ;
V_13 = F_26 ( V_4 -> V_20 , V_49 , V_10 ) ;
if ( V_13 )
F_12 ( V_4 -> V_3 . V_14 , L_5 , V_49 ) ;
* V_33 = V_28 ;
return V_13 ;
}
static int F_27 ( struct V_1 * V_4 , unsigned long * V_28 )
{
return F_24 ( V_4 , V_51 , V_28 ) ;
}
static int F_28 ( struct V_1 * V_4 , unsigned long * V_28 )
{
return F_24 ( V_4 , V_50 , V_28 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
unsigned long * V_52 ,
unsigned long * V_53 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_13 ;
F_8 ( V_4 -> V_3 . V_14 , L_6 , V_15 ,
* V_52 , * V_53 ) ;
if ( * V_52 > V_54 ||
* V_53 > V_55 )
return - V_56 ;
if ( * V_52 == 0 && * V_53 == 0 ) {
* V_52 = 500 ;
* V_53 = 500 ;
}
V_13 = F_27 ( V_4 , V_52 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_28 ( V_4 , V_53 ) ;
if ( V_13 )
return V_13 ;
return F_7 ( V_4 , 1 ) ;
}
static T_2 F_30 ( struct V_57 * V_14 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
return F_32 ( V_60 , V_62 , L_7 , V_4 -> V_5 ) ;
}
static T_2 F_33 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
char * V_60 , T_1 V_6 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
T_2 V_13 ;
T_1 V_49 ;
T_1 V_10 ;
V_49 = F_6 ( V_4 , V_6 ) ;
V_13 = F_34 ( V_4 -> V_20 , V_49 , & V_10 ) ;
if ( V_13 )
return V_13 ;
return F_32 ( V_60 , V_62 , L_8 , V_10 ) ;
}
static T_2 F_35 ( struct V_57 * V_14 ,
struct V_58 * V_59 , char * V_60 )
{
return F_33 ( V_14 , V_59 , V_60 ,
V_63 ) ;
}
static T_2 F_36 ( struct V_57 * V_14 ,
struct V_58 * V_59 , char * V_60 )
{
return F_33 ( V_14 , V_59 , V_60 ,
V_64 ) ;
}
static T_2 F_37 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
const char * V_60 , T_3 V_65 , T_1 V_6 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
T_1 V_10 ;
T_1 V_49 ;
int V_13 ;
if ( F_38 ( V_60 , 0 , & V_10 ) || V_10 > V_66 )
return - V_56 ;
V_49 = F_6 ( V_4 , V_6 ) ;
V_13 = F_26 ( V_4 -> V_20 , V_49 , V_10 ) ;
if ( V_13 )
return V_13 ;
return V_65 ;
}
static T_2 F_39 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
const char * V_60 , T_3 V_65 )
{
return F_37 ( V_14 , V_59 , V_60 , V_65 ,
V_63 ) ;
}
static T_2 F_40 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
const char * V_60 , T_3 V_65 )
{
return F_37 ( V_14 , V_59 , V_60 , V_65 ,
V_64 ) ;
}
static T_2 F_41 ( struct V_57 * V_14 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
unsigned V_67 ;
T_1 V_49 ;
T_1 V_10 ;
int V_13 ;
V_49 = F_4 ( V_4 , V_68 ) ;
V_13 = F_34 ( V_4 -> V_20 , V_49 , & V_10 ) ;
if ( V_13 )
return V_13 ;
V_67 = ( V_10 & V_69 ) + 1 ;
return F_32 ( V_60 , V_62 , L_9 , V_67 ) ;
}
static T_2 F_42 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
const char * V_60 , T_3 V_65 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
unsigned V_67 ;
T_1 V_49 ;
T_1 V_10 ;
T_1 V_9 ;
int V_13 ;
if ( F_43 ( V_60 , 0 , & V_67 ) )
return - V_56 ;
if ( V_67 < V_70 ||
V_67 > V_71 )
return - V_56 ;
V_49 = F_4 ( V_4 , V_68 ) ;
V_9 = V_69 ;
V_10 = V_67 - 1 ;
V_13 = F_11 ( V_4 -> V_20 , V_49 , V_10 , V_9 ) ;
if ( V_13 )
return V_13 ;
return V_65 ;
}
static T_2 F_44 ( struct V_57 * V_14 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
bool V_8 ;
T_1 V_49 ;
T_1 V_10 ;
int V_13 ;
V_49 = F_4 ( V_4 , V_68 ) ;
V_13 = F_34 ( V_4 -> V_20 , V_49 , & V_10 ) ;
if ( V_13 )
return V_13 ;
V_8 = V_10 & V_72 ;
return F_32 ( V_60 , V_62 , L_7 , V_8 ) ;
}
static T_2 F_45 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
const char * V_60 , T_3 V_65 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
unsigned V_8 ;
T_1 V_49 ;
T_1 V_9 ;
T_1 V_10 ;
int V_13 ;
if ( F_43 ( V_60 , 0 , & V_8 ) )
return - V_56 ;
V_49 = F_4 ( V_4 , V_68 ) ;
V_9 = V_72 ;
if ( V_8 )
V_10 = V_9 ;
else
V_10 = 0 ;
V_13 = F_11 ( V_4 -> V_20 , V_49 , V_10 , V_9 ) ;
if ( V_13 )
return V_13 ;
return V_65 ;
}
static T_2 F_46 ( struct V_57 * V_14 ,
struct V_58 * V_59 , char * V_60 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
T_1 V_49 ;
T_1 V_10 ;
int V_73 ;
int V_13 ;
V_49 = F_4 ( V_4 , V_68 ) ;
V_13 = F_34 ( V_4 -> V_20 , V_49 , & V_10 ) ;
if ( V_13 )
return V_13 ;
if ( V_10 & V_74 )
V_73 = 1 ;
else
V_73 = 0 ;
return F_32 ( V_60 , V_62 , L_8 , V_73 ) ;
}
static T_2 F_47 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
const char * V_60 , T_3 V_65 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
unsigned long V_73 ;
T_1 V_49 ;
T_1 V_9 ;
T_1 V_10 ;
int V_13 ;
if ( F_48 ( V_60 , 0 , & V_73 ) )
return - V_56 ;
V_49 = F_4 ( V_4 , V_68 ) ;
V_9 = V_74 ;
if ( V_73 )
V_10 = V_9 ;
else
V_10 = 0 ;
V_13 = F_11 ( V_4 -> V_20 , V_49 , V_10 , V_9 ) ;
if ( V_13 )
return V_13 ;
return V_65 ;
}
static T_2 F_49 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
char * V_60 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
T_1 V_10 ;
int V_13 ;
V_13 = F_50 ( & V_4 -> V_25 , & V_10 ) ;
if ( V_13 )
return V_13 ;
return F_32 ( V_60 , V_62 , L_9 , V_10 ) ;
}
static T_2 F_51 ( struct V_57 * V_14 ,
struct V_58 * V_59 ,
const char * V_60 , T_3 V_65 )
{
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
T_1 V_10 ;
int V_13 ;
if ( F_38 ( V_60 , 0 , & V_10 ) )
return - V_56 ;
V_13 = F_52 ( & V_4 -> V_25 , V_10 ) ;
if ( V_13 )
return V_13 ;
return V_65 ;
}
static T_4 F_53 ( struct V_75 * V_76 ,
struct V_77 * V_59 , int V_78 )
{
struct V_57 * V_14 = F_2 ( V_76 , struct V_57 , V_76 ) ;
struct V_2 * V_61 = F_31 ( V_14 ) ;
struct V_1 * V_4 = F_1 ( V_61 ) ;
T_4 V_79 = V_59 -> V_79 ;
if ( V_59 == & V_80 . V_59 ||
V_59 == & V_81 . V_59 ) {
if ( ! V_4 -> V_20 -> V_82 )
V_79 = 0 ;
}
return V_79 ;
}
static int F_54 ( struct V_1 * V_4 ,
struct V_83 * V_84 )
{
int V_13 ;
V_13 = F_55 ( & V_4 -> V_25 , V_84 -> V_85 ) ;
if ( V_13 )
return V_13 ;
return F_52 ( & V_4 -> V_25 , V_84 -> V_86 ) ;
}
static int F_56 ( struct V_87 * V_88 )
{
struct V_20 * V_20 ;
struct V_83 * V_84 ;
struct V_1 * V_4 ;
int V_13 ;
F_8 ( & V_88 -> V_14 , L_10 , V_15 ) ;
V_20 = F_31 ( V_88 -> V_14 . V_89 ) ;
if ( ! V_20 )
return - V_56 ;
V_84 = F_57 ( & V_88 -> V_14 ) ;
if ( ! V_84 ) {
F_12 ( & V_88 -> V_14 , L_11 ) ;
return - V_56 ;
}
if ( V_88 -> V_5 < 0 || V_88 -> V_5 >= V_90 ) {
F_12 ( & V_88 -> V_14 , L_12 , V_88 -> V_5 ) ;
return - V_56 ;
}
V_4 = F_58 ( & V_88 -> V_14 , sizeof( * V_4 ) , V_91 ) ;
if ( ! V_4 )
return - V_92 ;
V_4 -> V_20 = V_20 ;
V_4 -> V_3 . V_93 = V_84 -> V_93 ;
V_4 -> V_3 . V_94 = V_84 -> V_94 ;
V_4 -> V_3 . V_95 = F_17 ;
V_4 -> V_3 . V_96 = F_19 ;
V_4 -> V_3 . V_97 = F_29 ;
V_4 -> V_3 . V_98 = V_99 ;
V_4 -> V_3 . V_100 = V_101 ,
V_4 -> V_5 = V_88 -> V_5 ;
F_59 ( & V_4 -> V_16 ) ;
F_60 ( & V_4 -> V_23 , F_15 ) ;
V_4 -> V_25 . V_20 = V_20 ;
V_4 -> V_25 . V_5 = F_3 ( V_4 ) ;
V_4 -> V_25 . V_14 = V_20 -> V_14 ;
F_61 ( V_88 , V_4 ) ;
V_13 = F_62 ( V_88 -> V_14 . V_89 , & V_4 -> V_3 ) ;
if ( V_13 ) {
F_12 ( & V_88 -> V_14 , L_13 , V_88 -> V_5 ) ;
return V_13 ;
}
V_4 -> V_25 . V_14 = V_4 -> V_3 . V_14 ;
V_13 = F_54 ( V_4 , V_84 ) ;
if ( V_13 )
goto V_102;
V_13 = F_63 ( & V_4 -> V_25 ) ;
if ( V_13 )
goto V_102;
return 0 ;
V_102:
F_64 ( & V_4 -> V_3 ) ;
F_65 ( & V_4 -> V_23 ) ;
return V_13 ;
}
static int F_66 ( struct V_87 * V_88 )
{
struct V_1 * V_4 = F_67 ( V_88 ) ;
F_8 ( & V_88 -> V_14 , L_10 , V_15 ) ;
F_68 ( & V_4 -> V_25 ) ;
F_64 ( & V_4 -> V_3 ) ;
F_65 ( & V_4 -> V_23 ) ;
return 0 ;
}
static void F_69 ( struct V_87 * V_88 )
{
struct V_1 * V_4 = F_67 ( V_88 ) ;
F_8 ( & V_88 -> V_14 , L_10 , V_15 ) ;
F_68 ( & V_4 -> V_25 ) ;
F_17 ( & V_4 -> V_3 , V_99 ) ;
F_65 ( & V_4 -> V_23 ) ;
}
