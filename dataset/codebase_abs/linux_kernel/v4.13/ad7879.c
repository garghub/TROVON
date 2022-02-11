static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
unsigned int V_4 ;
int error ;
error = F_2 ( V_2 -> V_5 , V_3 , & V_4 ) ;
if ( error ) {
F_3 ( V_2 -> V_6 , L_1 ,
V_3 , error ) ;
return error ;
}
return V_4 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
int error ;
error = F_5 ( V_2 -> V_5 , V_3 , V_4 ) ;
if ( error ) {
F_3 ( V_2 -> V_6 ,
L_2 ,
V_4 , V_3 , error ) ;
return error ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = V_2 -> V_8 ;
unsigned V_9 ;
T_2 V_10 , V_11 , V_12 , V_13 ;
V_10 = V_2 -> V_14 [ V_15 ] & V_16 ;
V_11 = V_2 -> V_14 [ V_17 ] & V_16 ;
V_12 = V_2 -> V_14 [ V_18 ] & V_16 ;
V_13 = V_2 -> V_14 [ V_19 ] & V_16 ;
if ( V_2 -> V_20 )
F_7 ( V_10 , V_11 ) ;
if ( F_8 ( V_10 && V_12 ) ) {
V_9 = ( V_13 - V_12 ) * V_10 * V_2 -> V_21 ;
V_9 /= V_12 ;
V_9 = ( V_9 + 2047 ) >> 12 ;
if ( V_9 > F_9 ( V_7 , V_22 ) )
return - V_23 ;
if ( F_10 ( & V_2 -> V_24 ) ) {
F_11 ( V_7 , V_25 , 1 ) ;
F_12 ( V_7 , V_26 , V_2 -> V_10 ) ;
F_12 ( V_7 , V_27 , V_2 -> V_11 ) ;
F_12 ( V_7 , V_22 , V_2 -> V_9 ) ;
F_13 ( V_7 ) ;
}
V_2 -> V_10 = V_10 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_9 = V_9 ;
return 0 ;
}
return - V_23 ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_7 * V_7 = V_2 -> V_8 ;
F_12 ( V_7 , V_22 , 0 ) ;
F_11 ( V_7 , V_25 , 0 ) ;
F_13 ( V_7 ) ;
}
static void F_15 ( unsigned long V_28 )
{
struct V_1 * V_2 = ( void * ) V_28 ;
F_14 ( V_2 ) ;
}
static T_3 F_16 ( int V_29 , void * V_28 )
{
struct V_1 * V_2 = V_28 ;
F_17 ( V_2 -> V_5 , V_30 ,
V_2 -> V_14 , V_31 ) ;
if ( ! F_6 ( V_2 ) )
F_18 ( & V_2 -> V_24 , V_32 + V_33 ) ;
return V_34 ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_4 ( V_2 , V_35 , V_2 -> V_36 ) ;
F_4 ( V_2 , V_37 , V_2 -> V_38 ) ;
F_4 ( V_2 , V_39 , V_2 -> V_40 ) ;
F_20 ( V_2 -> V_29 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_3 = ( V_2 -> V_36 & ~ F_22 ( - 1 ) ) |
F_22 ( V_41 ) ;
F_23 ( V_2 -> V_29 ) ;
if ( F_24 ( & V_2 -> V_24 ) )
F_14 ( V_2 ) ;
F_4 ( V_2 , V_35 , V_3 ) ;
}
static int F_25 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_26 ( V_8 ) ;
if ( ! V_2 -> V_42 && ! V_2 -> V_43 )
F_19 ( V_2 ) ;
return 0 ;
}
static void F_27 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_26 ( V_8 ) ;
if ( ! V_2 -> V_42 && ! V_2 -> V_43 )
F_21 ( V_2 ) ;
}
static int T_4 F_28 ( struct V_44 * V_6 )
{
struct V_1 * V_2 = F_29 ( V_6 ) ;
F_30 ( & V_2 -> V_8 -> V_45 ) ;
if ( ! V_2 -> V_43 && ! V_2 -> V_42 && V_2 -> V_8 -> V_46 )
F_21 ( V_2 ) ;
V_2 -> V_43 = true ;
F_31 ( & V_2 -> V_8 -> V_45 ) ;
return 0 ;
}
static int T_4 F_32 ( struct V_44 * V_6 )
{
struct V_1 * V_2 = F_29 ( V_6 ) ;
F_30 ( & V_2 -> V_8 -> V_45 ) ;
if ( V_2 -> V_43 && ! V_2 -> V_42 && V_2 -> V_8 -> V_46 )
F_19 ( V_2 ) ;
V_2 -> V_43 = false ;
F_31 ( & V_2 -> V_8 -> V_45 ) ;
return 0 ;
}
static void F_33 ( struct V_1 * V_2 , bool V_47 )
{
F_30 ( & V_2 -> V_8 -> V_45 ) ;
if ( ! V_2 -> V_43 && V_2 -> V_8 -> V_46 != 0 ) {
if ( V_47 ) {
if ( V_2 -> V_42 )
F_19 ( V_2 ) ;
} else {
if ( ! V_2 -> V_42 )
F_21 ( V_2 ) ;
}
}
V_2 -> V_42 = V_47 ;
F_31 ( & V_2 -> V_8 -> V_45 ) ;
}
static T_5 F_34 ( struct V_44 * V_6 ,
struct V_48 * V_49 , char * V_50 )
{
struct V_1 * V_2 = F_29 ( V_6 ) ;
return sprintf ( V_50 , L_3 , V_2 -> V_42 ) ;
}
static T_5 F_35 ( struct V_44 * V_6 ,
struct V_48 * V_49 ,
const char * V_50 , T_6 V_51 )
{
struct V_1 * V_2 = F_29 ( V_6 ) ;
unsigned int V_4 ;
int error ;
error = F_36 ( V_50 , 10 , & V_4 ) ;
if ( error )
return error ;
F_33 ( V_2 , V_4 ) ;
return V_51 ;
}
static int F_37 ( struct V_52 * V_53 ,
unsigned V_54 )
{
struct V_1 * V_2 = F_38 ( V_53 ) ;
int V_55 ;
F_30 ( & V_2 -> V_45 ) ;
V_2 -> V_36 |= V_56 | V_57 | V_58 ;
V_55 = F_4 ( V_2 , V_35 , V_2 -> V_36 ) ;
F_31 ( & V_2 -> V_45 ) ;
return V_55 ;
}
static int F_39 ( struct V_52 * V_53 ,
unsigned V_54 , int V_59 )
{
struct V_1 * V_2 = F_38 ( V_53 ) ;
int V_55 ;
F_30 ( & V_2 -> V_45 ) ;
V_2 -> V_36 &= ~ V_57 ;
V_2 -> V_36 |= V_56 | V_58 ;
if ( V_59 )
V_2 -> V_36 |= V_60 ;
else
V_2 -> V_36 &= ~ V_60 ;
V_55 = F_4 ( V_2 , V_35 , V_2 -> V_36 ) ;
F_31 ( & V_2 -> V_45 ) ;
return V_55 ;
}
static int F_40 ( struct V_52 * V_53 , unsigned V_54 )
{
struct V_1 * V_2 = F_38 ( V_53 ) ;
T_2 V_4 ;
F_30 ( & V_2 -> V_45 ) ;
V_4 = F_1 ( V_2 , V_35 ) ;
F_31 ( & V_2 -> V_45 ) ;
return ! ! ( V_4 & V_60 ) ;
}
static void F_41 ( struct V_52 * V_53 ,
unsigned V_54 , int V_61 )
{
struct V_1 * V_2 = F_38 ( V_53 ) ;
F_30 ( & V_2 -> V_45 ) ;
if ( V_61 )
V_2 -> V_36 |= V_60 ;
else
V_2 -> V_36 &= ~ V_60 ;
F_4 ( V_2 , V_35 , V_2 -> V_36 ) ;
F_31 ( & V_2 -> V_45 ) ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
bool V_64 ;
int V_65 ;
int V_66 = 0 ;
if ( V_63 ) {
V_64 = V_63 -> V_64 ;
V_65 = V_63 -> V_65 ;
} else {
V_64 = F_43 ( V_2 -> V_6 ,
L_4 ) ;
V_65 = - 1 ;
}
F_44 ( & V_2 -> V_45 ) ;
if ( V_64 ) {
V_2 -> V_67 . V_68 = F_37 ;
V_2 -> V_67 . V_69 = F_39 ;
V_2 -> V_67 . V_70 = F_40 ;
V_2 -> V_67 . V_71 = F_41 ;
V_2 -> V_67 . V_72 = 1 ;
V_2 -> V_67 . V_73 = V_65 ;
V_2 -> V_67 . V_74 = 1 ;
V_2 -> V_67 . V_75 = L_5 ;
V_2 -> V_67 . V_76 = V_77 ;
V_2 -> V_67 . V_78 = V_2 -> V_6 ;
V_66 = F_45 ( V_2 -> V_6 , & V_2 -> V_67 , V_2 ) ;
if ( V_66 )
F_3 ( V_2 -> V_6 , L_6 ,
V_2 -> V_67 . V_73 ) ;
}
return V_66 ;
}
static int F_42 ( struct V_1 * V_2 ,
const struct V_62 * V_63 )
{
return 0 ;
}
static int F_46 ( struct V_44 * V_6 , struct V_1 * V_2 )
{
int V_55 ;
T_7 V_79 ;
V_55 = F_47 ( V_6 , L_7 , & V_79 ) ;
if ( V_55 ) {
F_3 ( V_6 , L_8 ) ;
return V_55 ;
}
V_2 -> V_21 = ( T_2 ) V_79 ;
F_48 ( V_6 , L_9 ,
& V_2 -> V_80 ) ;
F_48 ( V_6 , L_10 ,
& V_2 -> V_81 ) ;
F_48 ( V_6 , L_11 , & V_2 -> V_82 ) ;
F_48 ( V_6 , L_12 , & V_2 -> V_83 ) ;
F_48 ( V_6 , L_13 ,
& V_2 -> V_84 ) ;
V_2 -> V_20 = F_43 ( V_6 , L_14 ) ;
return 0 ;
}
static void F_49 ( void * V_85 )
{
struct V_1 * V_2 = V_85 ;
F_50 ( & V_2 -> V_6 -> V_86 , & V_87 ) ;
}
int F_51 ( struct V_44 * V_6 , struct V_5 * V_5 ,
int V_29 , T_2 V_88 , T_1 V_89 )
{
struct V_62 * V_63 = F_52 ( V_6 ) ;
struct V_1 * V_2 ;
struct V_7 * V_7 ;
int V_55 ;
T_2 V_90 ;
if ( V_29 <= 0 ) {
F_3 ( V_6 , L_15 ) ;
return - V_23 ;
}
V_2 = F_53 ( V_6 , sizeof( * V_2 ) , V_91 ) ;
if ( ! V_2 )
return - V_92 ;
if ( V_63 ) {
V_2 -> V_20 = ! V_63 -> V_20 ;
V_2 -> V_21 = V_63 -> V_21 ? : 400 ;
V_2 -> V_80 = V_63 -> V_80 ;
V_2 -> V_81 = V_63 -> V_81 ;
V_2 -> V_83 = V_63 -> V_83 ;
V_2 -> V_84 = V_63 -> V_84 ;
V_2 -> V_82 = V_63 -> V_82 ;
} else {
V_55 = F_46 ( V_6 , V_2 ) ;
if ( V_55 )
return V_55 ;
}
V_7 = F_54 ( V_6 ) ;
if ( ! V_7 ) {
F_3 ( V_6 , L_16 ) ;
return - V_92 ;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_8 = V_7 ;
V_2 -> V_29 = V_29 ;
V_2 -> V_5 = V_5 ;
F_55 ( & V_2 -> V_24 , F_15 , ( unsigned long ) V_2 ) ;
snprintf ( V_2 -> V_93 , sizeof( V_2 -> V_93 ) , L_17 , F_56 ( V_6 ) ) ;
V_7 -> V_94 = L_18 ;
V_7 -> V_93 = V_2 -> V_93 ;
V_7 -> V_6 . V_78 = V_6 ;
V_7 -> V_95 . V_88 = V_88 ;
V_7 -> V_96 = F_25 ;
V_7 -> V_97 = F_27 ;
F_57 ( V_7 , V_2 ) ;
F_58 ( V_7 , V_98 , V_25 ) ;
if ( V_63 ) {
F_59 ( V_7 , V_26 ,
V_63 -> V_99 ? : 0 ,
V_63 -> V_100 ? : V_16 ,
0 , 0 ) ;
F_59 ( V_7 , V_27 ,
V_63 -> V_101 ? : 0 ,
V_63 -> V_102 ? : V_16 ,
0 , 0 ) ;
F_59 ( V_7 , V_22 ,
V_63 -> V_103 ,
V_63 -> V_104 ? : ~ 0 ,
0 , 0 ) ;
} else {
F_59 ( V_7 , V_26 , 0 , V_16 , 0 , 0 ) ;
F_59 ( V_7 , V_27 , 0 , V_16 , 0 , 0 ) ;
F_58 ( V_7 , V_105 , V_22 ) ;
F_60 ( V_7 , false , NULL ) ;
if ( ! F_9 ( V_7 , V_22 ) ) {
F_3 ( V_6 , L_19 ) ;
return - V_23 ;
}
}
V_55 = F_4 ( V_2 , V_35 , V_106 ) ;
if ( V_55 < 0 ) {
F_3 ( V_6 , L_20 , V_7 -> V_94 ) ;
return V_55 ;
}
V_90 = F_1 ( V_2 , V_107 ) ;
V_7 -> V_95 . V_108 = ( V_90 & 0xff ) ;
V_7 -> V_95 . V_109 = V_90 >> 8 ;
if ( V_7 -> V_95 . V_108 != V_89 ) {
F_3 ( V_6 , L_21 ,
V_7 -> V_94 , V_89 , V_90 ) ;
return - V_110 ;
}
V_2 -> V_38 = V_111 |
V_112 |
V_113 |
V_114 |
V_115 |
V_116 |
V_117 ;
V_2 -> V_36 = F_22 ( V_118 ) | V_119 |
F_61 ( V_2 -> V_83 ) |
F_62 ( V_2 -> V_82 ) |
F_63 ( V_2 -> V_80 ) ;
V_2 -> V_40 = V_120 | V_121 |
F_64 ( V_2 -> V_81 ) |
F_65 ( V_2 -> V_84 ) ;
V_55 = F_66 ( V_6 , V_2 -> V_29 , NULL , F_16 ,
V_122 | V_123 ,
F_56 ( V_6 ) , V_2 ) ;
if ( V_55 ) {
F_3 ( V_6 , L_22 , V_55 ) ;
return V_55 ;
}
F_21 ( V_2 ) ;
V_55 = F_67 ( & V_6 -> V_86 , & V_87 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_68 ( V_6 , F_49 , V_2 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_42 ( V_2 , V_63 ) ;
if ( V_55 )
return V_55 ;
V_55 = F_69 ( V_7 ) ;
if ( V_55 )
return V_55 ;
F_70 ( V_6 , V_2 ) ;
return 0 ;
}
