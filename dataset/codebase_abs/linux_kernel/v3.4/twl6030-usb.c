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
struct V_19 * V_20 = V_2 -> V_21 . V_20 ;
int V_46 ;
T_1 V_47 , V_48 ;
V_48 = F_4 ( V_2 , V_28 , V_49 ) ;
V_47 = F_4 ( V_2 , V_50 ,
V_51 ) ;
if ( ! ( V_48 & V_52 ) ) {
if ( V_47 & V_53 ) {
F_20 ( V_2 -> V_32 ) ;
V_2 -> V_54 = 1 ;
V_46 = V_41 ;
V_20 -> V_55 = false ;
V_2 -> V_21 . V_56 = V_57 ;
V_2 -> V_14 = V_46 ;
V_2 -> V_21 . V_58 = V_46 ;
F_21 ( & V_2 -> V_21 . V_59 ,
V_46 , V_20 -> V_60 ) ;
} else {
V_46 = V_43 ;
V_2 -> V_14 = V_46 ;
V_2 -> V_21 . V_58 = V_46 ;
F_21 ( & V_2 -> V_21 . V_59 ,
V_46 , V_20 -> V_60 ) ;
if ( V_2 -> V_54 ) {
F_22 ( V_2 -> V_32 ) ;
V_2 -> V_54 = 0 ;
}
}
}
F_23 ( & V_2 -> V_7 -> V_61 , NULL , L_9 ) ;
return V_62 ;
}
static T_3 F_24 ( int V_44 , void * V_45 )
{
struct V_1 * V_2 = V_45 ;
struct V_19 * V_20 = V_2 -> V_21 . V_20 ;
int V_46 = V_43 ;
T_1 V_48 ;
V_48 = F_4 ( V_2 , V_28 , V_49 ) ;
if ( V_48 & V_52 ) {
F_20 ( V_2 -> V_32 ) ;
V_2 -> V_54 = 1 ;
F_1 ( V_2 , V_22 , V_63 , 0x1 ) ;
F_1 ( V_2 , V_22 , V_64 ,
0x10 ) ;
V_46 = V_15 ;
V_20 -> V_55 = true ;
V_2 -> V_21 . V_56 = V_65 ;
V_2 -> V_14 = V_46 ;
V_2 -> V_21 . V_58 = V_46 ;
F_21 ( & V_2 -> V_21 . V_59 , V_46 ,
V_20 -> V_60 ) ;
} else {
F_1 ( V_2 , V_22 , V_63 ,
0x10 ) ;
F_1 ( V_2 , V_22 , V_64 ,
0x1 ) ;
}
F_1 ( V_2 , V_22 , V_66 , V_46 ) ;
return V_62 ;
}
static int F_25 ( struct V_19 * V_20 ,
struct V_67 * V_60 )
{
if ( ! V_20 )
return - V_33 ;
V_20 -> V_60 = V_60 ;
if ( ! V_60 )
V_20 -> V_21 -> V_56 = V_68 ;
return 0 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 , V_22 , V_64 , 0x1 ) ;
F_27 ( 0x05 , V_69 ) ;
F_27 ( 0x05 , V_70 ) ;
F_27 ( V_71 ,
V_69 ) ;
F_27 ( V_71 ,
V_70 ) ;
F_19 ( V_2 -> V_72 , V_2 ) ;
F_24 ( V_2 -> V_73 , V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_74 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 , struct V_1 ,
V_75 ) ;
if ( V_2 -> V_76 )
F_1 ( V_2 , V_50 , 0x40 ,
V_77 ) ;
else
F_1 ( V_2 , V_50 , 0x00 ,
V_77 ) ;
}
static int F_30 ( struct V_19 * V_20 , bool V_78 )
{
struct V_1 * V_2 = F_7 ( V_20 -> V_21 ) ;
V_2 -> V_76 = V_78 ;
F_31 ( & V_2 -> V_75 ) ;
return 0 ;
}
static int F_32 ( struct V_19 * V_20 , struct V_79 * V_80 )
{
if ( ! V_20 )
return - V_33 ;
V_20 -> V_80 = V_80 ;
if ( ! V_80 )
V_20 -> V_21 -> V_56 = V_68 ;
return 0 ;
}
static int T_4 F_33 ( struct V_81 * V_82 )
{
struct V_1 * V_2 ;
int V_46 , V_83 ;
struct V_11 * V_12 ;
struct V_19 * V_20 ;
struct V_10 * V_7 = & V_82 -> V_7 ;
V_12 = V_7 -> V_13 ;
V_2 = F_34 ( sizeof *V_2 , V_84 ) ;
if ( ! V_2 )
return - V_85 ;
V_20 = F_34 ( sizeof *V_20 , V_84 ) ;
if ( ! V_20 ) {
F_35 ( V_2 ) ;
return - V_85 ;
}
V_2 -> V_7 = & V_82 -> V_7 ;
V_2 -> V_73 = F_36 ( V_82 , 0 ) ;
V_2 -> V_72 = F_36 ( V_82 , 1 ) ;
V_2 -> V_26 = V_12 -> V_26 ;
V_2 -> V_21 . V_7 = V_2 -> V_7 ;
V_2 -> V_21 . V_86 = L_10 ;
V_2 -> V_21 . V_20 = V_20 ;
V_2 -> V_21 . V_87 = F_6 ;
V_2 -> V_21 . V_88 = F_8 ;
V_2 -> V_21 . V_89 = F_9 ;
V_20 -> V_21 = & V_2 -> V_21 ;
V_20 -> V_90 = F_32 ;
V_20 -> V_91 = F_25 ;
V_20 -> V_92 = F_30 ;
V_20 -> V_93 = F_10 ;
F_37 ( & V_2 -> V_40 ) ;
V_83 = F_12 ( V_2 ) ;
if ( V_83 ) {
F_3 ( & V_82 -> V_7 , L_11 ) ;
F_35 ( V_20 ) ;
F_35 ( V_2 ) ;
return V_83 ;
}
F_38 ( & V_2 -> V_21 ) ;
F_39 ( V_82 , V_2 ) ;
if ( F_40 ( & V_82 -> V_7 , & V_94 ) )
F_41 ( & V_82 -> V_7 , L_12 ) ;
F_42 ( & V_2 -> V_21 . V_59 ) ;
F_43 ( & V_2 -> V_75 , F_28 ) ;
V_2 -> V_95 = true ;
V_46 = F_44 ( V_2 -> V_73 , NULL , F_24 ,
V_96 | V_97 ,
L_13 , V_2 ) ;
if ( V_46 < 0 ) {
F_3 ( & V_82 -> V_7 , L_14 ,
V_2 -> V_73 , V_46 ) ;
F_45 ( V_2 -> V_7 , & V_94 ) ;
F_35 ( V_20 ) ;
F_35 ( V_2 ) ;
return V_46 ;
}
V_46 = F_44 ( V_2 -> V_72 , NULL , F_19 ,
V_96 | V_97 ,
L_13 , V_2 ) ;
if ( V_46 < 0 ) {
F_3 ( & V_82 -> V_7 , L_14 ,
V_2 -> V_72 , V_46 ) ;
F_46 ( V_2 -> V_73 , V_2 ) ;
F_45 ( V_2 -> V_7 , & V_94 ) ;
F_35 ( V_20 ) ;
F_35 ( V_2 ) ;
return V_46 ;
}
V_2 -> V_54 = 0 ;
V_12 -> V_98 ( V_7 ) ;
F_9 ( & V_2 -> V_21 , 0 ) ;
F_26 ( & V_2 -> V_21 ) ;
F_47 ( & V_82 -> V_7 , L_15 ) ;
return 0 ;
}
static int T_5 F_48 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_49 ( V_82 ) ;
struct V_11 * V_12 ;
struct V_10 * V_7 = & V_82 -> V_7 ;
V_12 = V_7 -> V_13 ;
F_50 ( V_99 ,
V_69 ) ;
F_50 ( V_99 ,
V_70 ) ;
F_46 ( V_2 -> V_73 , V_2 ) ;
F_46 ( V_2 -> V_72 , V_2 ) ;
F_51 ( V_2 -> V_32 ) ;
V_12 -> V_100 ( V_2 -> V_7 ) ;
F_45 ( V_2 -> V_7 , & V_94 ) ;
F_52 ( & V_2 -> V_75 ) ;
F_35 ( V_2 -> V_21 . V_20 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int T_6 F_53 ( void )
{
return F_54 ( & V_101 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_101 ) ;
}
