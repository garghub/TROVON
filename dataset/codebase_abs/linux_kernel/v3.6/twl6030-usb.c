static inline int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 , T_1 V_5 )
{
int V_6 = 0 ;
V_6 = F_2 ( V_3 , V_4 , V_5 ) ;
if ( V_6 < 0 )
F_3 ( V_2 -> V_7 ,
L_1 , V_5 , V_6 ) ;
return V_6 ;
}
static inline T_1 F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
T_1 V_4 , V_6 = 0 ;
V_6 = F_5 ( V_3 , & V_4 , V_5 ) ;
if ( V_6 >= 0 )
V_6 = V_4 ;
else
F_3 ( V_2 -> V_7 ,
L_2 ,
V_3 , V_5 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_7 ;
struct V_11 * V_12 ;
V_2 = F_7 ( V_9 ) ;
V_7 = V_2 -> V_7 ;
V_12 = V_7 -> V_13 ;
if ( V_2 -> V_14 == V_15 )
V_12 -> V_16 ( V_2 -> V_7 , 1 , 1 ) ;
else
V_12 -> V_16 ( V_2 -> V_7 , 0 , 1 ) ;
return 0 ;
}
static void F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_10 * V_7 ;
struct V_11 * V_12 ;
V_2 = F_7 ( V_9 ) ;
V_7 = V_2 -> V_7 ;
V_12 = V_7 -> V_13 ;
V_12 -> V_16 ( V_2 -> V_7 , 0 , 0 ) ;
}
static int F_9 ( struct V_8 * V_9 , int V_17 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_10 * V_7 = V_2 -> V_7 ;
struct V_11 * V_12 = V_7 -> V_13 ;
V_12 -> V_18 ( V_7 , V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_19 * V_20 )
{
struct V_1 * V_2 = F_7 ( V_20 -> V_21 ) ;
F_1 ( V_2 , V_22 , 0x24 , V_23 ) ;
F_1 ( V_2 , V_22 , 0x84 , V_23 ) ;
F_11 ( 100 ) ;
F_1 ( V_2 , V_22 , 0xa0 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
char * V_25 ;
if ( V_2 -> V_26 & V_27 )
V_25 = L_3 ;
else
V_25 = L_4 ;
F_1 ( V_2 , V_28 , 0x1 , V_29 ) ;
F_1 ( V_2 , V_28 , 0x1 , V_30 ) ;
F_1 ( V_2 , V_28 , 0x10 , V_31 ) ;
V_2 -> V_32 = F_13 ( V_2 -> V_7 , V_25 ) ;
if ( F_14 ( V_2 -> V_32 ) )
return - V_33 ;
F_1 ( V_2 , V_22 , 0x4 , V_23 ) ;
F_1 ( V_2 , V_22 , 0x14 , V_34 ) ;
return 0 ;
}
static T_2 F_15 ( struct V_10 * V_7 ,
struct V_35 * V_36 , char * V_37 )
{
struct V_1 * V_2 = F_16 ( V_7 ) ;
unsigned long V_38 ;
int V_6 = - V_39 ;
F_17 ( & V_2 -> V_40 , V_38 ) ;
switch ( V_2 -> V_14 ) {
case V_41 :
V_6 = snprintf ( V_37 , V_42 , L_5 ) ;
break;
case V_15 :
V_6 = snprintf ( V_37 , V_42 , L_6 ) ;
break;
case V_43 :
V_6 = snprintf ( V_37 , V_42 , L_7 ) ;
break;
default:
V_6 = snprintf ( V_37 , V_42 , L_8 ) ;
}
F_18 ( & V_2 -> V_40 , V_38 ) ;
return V_6 ;
}
static T_3 F_19 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
enum V_46 V_47 = V_48 ;
T_1 V_49 , V_50 ;
V_50 = F_4 ( V_2 , V_28 , V_51 ) ;
V_49 = F_4 ( V_2 , V_52 ,
V_53 ) ;
if ( ! ( V_50 & V_54 ) ) {
if ( V_49 & V_55 ) {
F_20 ( V_2 -> V_32 ) ;
V_2 -> V_56 = 1 ;
V_47 = V_41 ;
V_2 -> V_14 = V_47 ;
F_21 ( V_47 ) ;
} else {
if ( V_2 -> V_14 != V_48 ) {
V_47 = V_43 ;
V_2 -> V_14 = V_47 ;
F_21 ( V_47 ) ;
if ( V_2 -> V_56 ) {
F_22 ( V_2 -> V_32 ) ;
V_2 -> V_56 = 0 ;
}
}
}
}
F_23 ( & V_2 -> V_7 -> V_57 , NULL , L_9 ) ;
return V_58 ;
}
static T_3 F_24 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
enum V_46 V_47 = V_48 ;
T_1 V_50 ;
V_50 = F_4 ( V_2 , V_28 , V_51 ) ;
if ( V_50 & V_54 ) {
F_20 ( V_2 -> V_32 ) ;
V_2 -> V_56 = 1 ;
F_1 ( V_2 , V_22 , 0x1 , V_59 ) ;
F_1 ( V_2 , V_22 , 0x10 , V_60 ) ;
V_47 = V_15 ;
V_2 -> V_14 = V_47 ;
F_21 ( V_47 ) ;
} else {
F_1 ( V_2 , V_22 , 0x10 , V_59 ) ;
F_1 ( V_2 , V_22 , 0x1 , V_60 ) ;
}
F_1 ( V_2 , V_22 , V_47 , V_61 ) ;
return V_58 ;
}
static int F_25 ( struct V_19 * V_20 ,
struct V_62 * V_63 )
{
if ( ! V_20 )
return - V_33 ;
V_20 -> V_63 = V_63 ;
if ( ! V_63 )
V_20 -> V_21 -> V_64 = V_65 ;
return 0 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 , V_22 , 0x1 , V_60 ) ;
F_27 ( 0x05 , V_66 ) ;
F_27 ( 0x05 , V_67 ) ;
F_27 ( V_68 ,
V_66 ) ;
F_27 ( V_68 ,
V_67 ) ;
F_19 ( V_2 -> V_69 , V_2 ) ;
F_24 ( V_2 -> V_70 , V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_71 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 , struct V_1 ,
V_72 ) ;
if ( V_2 -> V_73 )
F_1 ( V_2 , V_52 , 0x40 ,
V_74 ) ;
else
F_1 ( V_2 , V_52 , 0x00 ,
V_74 ) ;
}
static int F_30 ( struct V_19 * V_20 , bool V_75 )
{
struct V_1 * V_2 = F_7 ( V_20 -> V_21 ) ;
V_2 -> V_73 = V_75 ;
F_31 ( & V_2 -> V_72 ) ;
return 0 ;
}
static int F_32 ( struct V_19 * V_20 , struct V_76 * V_77 )
{
if ( ! V_20 )
return - V_33 ;
V_20 -> V_77 = V_77 ;
if ( ! V_77 )
V_20 -> V_21 -> V_64 = V_65 ;
return 0 ;
}
static int T_4 F_33 ( struct V_78 * V_79 )
{
struct V_1 * V_2 ;
int V_47 , V_80 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
struct V_10 * V_7 = & V_79 -> V_7 ;
V_12 = V_7 -> V_13 ;
V_2 = F_34 ( V_7 , sizeof *V_2 , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
V_20 = F_34 ( V_7 , sizeof *V_20 , V_81 ) ;
if ( ! V_20 )
return - V_82 ;
V_2 -> V_7 = & V_79 -> V_7 ;
V_2 -> V_70 = F_35 ( V_79 , 0 ) ;
V_2 -> V_69 = F_35 ( V_79 , 1 ) ;
V_2 -> V_26 = V_12 -> V_26 ;
V_2 -> V_14 = V_48 ;
V_2 -> V_21 . V_7 = V_2 -> V_7 ;
V_2 -> V_21 . V_83 = L_10 ;
V_2 -> V_21 . V_20 = V_20 ;
V_2 -> V_21 . V_84 = F_6 ;
V_2 -> V_21 . V_85 = F_8 ;
V_2 -> V_21 . V_86 = F_9 ;
V_20 -> V_21 = & V_2 -> V_21 ;
V_20 -> V_87 = F_32 ;
V_20 -> V_88 = F_25 ;
V_20 -> V_89 = F_30 ;
V_20 -> V_90 = F_10 ;
F_36 ( & V_2 -> V_40 ) ;
V_80 = F_12 ( V_2 ) ;
if ( V_80 ) {
F_3 ( & V_79 -> V_7 , L_11 ) ;
return V_80 ;
}
F_37 ( & V_2 -> V_21 , V_91 ) ;
F_38 ( V_79 , V_2 ) ;
if ( F_39 ( & V_79 -> V_7 , & V_92 ) )
F_40 ( & V_79 -> V_7 , L_12 ) ;
F_41 ( & V_2 -> V_72 , F_28 ) ;
V_2 -> V_93 = true ;
V_47 = F_42 ( V_2 -> V_70 , NULL , F_24 ,
V_94 | V_95 | V_96 ,
L_13 , V_2 ) ;
if ( V_47 < 0 ) {
F_3 ( & V_79 -> V_7 , L_14 ,
V_2 -> V_70 , V_47 ) ;
F_43 ( V_2 -> V_7 , & V_92 ) ;
return V_47 ;
}
V_47 = F_42 ( V_2 -> V_69 , NULL , F_19 ,
V_94 | V_95 | V_96 ,
L_13 , V_2 ) ;
if ( V_47 < 0 ) {
F_3 ( & V_79 -> V_7 , L_14 ,
V_2 -> V_69 , V_47 ) ;
F_44 ( V_2 -> V_70 , V_2 ) ;
F_43 ( V_2 -> V_7 , & V_92 ) ;
return V_47 ;
}
V_2 -> V_56 = 0 ;
V_12 -> V_97 ( V_7 ) ;
F_9 ( & V_2 -> V_21 , 0 ) ;
F_26 ( & V_2 -> V_21 ) ;
F_45 ( & V_79 -> V_7 , L_15 ) ;
return 0 ;
}
static int T_5 F_46 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_47 ( V_79 ) ;
struct V_11 * V_12 ;
struct V_10 * V_7 = & V_79 -> V_7 ;
V_12 = V_7 -> V_13 ;
F_48 ( V_98 ,
V_66 ) ;
F_48 ( V_98 ,
V_67 ) ;
F_44 ( V_2 -> V_70 , V_2 ) ;
F_44 ( V_2 -> V_69 , V_2 ) ;
F_49 ( V_2 -> V_32 ) ;
V_12 -> V_99 ( V_2 -> V_7 ) ;
F_43 ( V_2 -> V_7 , & V_92 ) ;
F_50 ( & V_2 -> V_72 ) ;
return 0 ;
}
static int T_6 F_51 ( void )
{
return F_52 ( & V_100 ) ;
}
static void T_5 F_53 ( void )
{
F_54 ( & V_100 ) ;
}
