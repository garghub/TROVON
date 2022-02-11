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
static int F_10 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 , V_19 , 0x24 , V_20 ) ;
F_1 ( V_2 , V_19 , 0x84 , V_20 ) ;
F_11 ( 100 ) ;
F_1 ( V_2 , V_19 , 0xa0 , V_21 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
char * V_22 ;
if ( V_2 -> V_23 & V_24 )
V_22 = L_3 ;
else
V_22 = L_4 ;
F_1 ( V_2 , V_25 , 0x1 , V_26 ) ;
F_1 ( V_2 , V_25 , 0x1 , V_27 ) ;
F_1 ( V_2 , V_25 , 0x10 , V_28 ) ;
V_2 -> V_29 = F_13 ( V_2 -> V_7 , V_22 ) ;
if ( F_14 ( V_2 -> V_29 ) )
return - V_30 ;
F_1 ( V_2 , V_19 , 0x4 , V_20 ) ;
F_1 ( V_2 , V_19 , 0x14 , V_31 ) ;
return 0 ;
}
static T_2 F_15 ( struct V_10 * V_7 ,
struct V_32 * V_33 , char * V_34 )
{
struct V_1 * V_2 = F_16 ( V_7 ) ;
unsigned long V_35 ;
int V_6 = - V_36 ;
F_17 ( & V_2 -> V_37 , V_35 ) ;
switch ( V_2 -> V_14 ) {
case V_38 :
V_6 = snprintf ( V_34 , V_39 , L_5 ) ;
break;
case V_15 :
V_6 = snprintf ( V_34 , V_39 , L_6 ) ;
break;
case V_40 :
V_6 = snprintf ( V_34 , V_39 , L_7 ) ;
break;
default:
V_6 = snprintf ( V_34 , V_39 , L_8 ) ;
}
F_18 ( & V_2 -> V_37 , V_35 ) ;
return V_6 ;
}
static T_3 F_19 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
int V_43 ;
T_1 V_44 , V_45 ;
V_45 = F_4 ( V_2 , V_25 , V_46 ) ;
V_44 = F_4 ( V_2 , V_47 ,
V_48 ) ;
if ( ! ( V_45 & V_49 ) ) {
if ( V_44 & V_50 ) {
F_20 ( V_2 -> V_29 ) ;
V_2 -> V_51 = 1 ;
V_43 = V_38 ;
V_2 -> V_52 . V_53 = false ;
V_2 -> V_52 . V_54 = V_55 ;
V_2 -> V_14 = V_43 ;
V_2 -> V_52 . V_56 = V_43 ;
F_21 ( & V_2 -> V_52 . V_57 ,
V_43 , V_2 -> V_52 . V_58 ) ;
} else {
V_43 = V_40 ;
V_2 -> V_14 = V_43 ;
V_2 -> V_52 . V_56 = V_43 ;
F_21 ( & V_2 -> V_52 . V_57 ,
V_43 , V_2 -> V_52 . V_58 ) ;
if ( V_2 -> V_51 ) {
F_22 ( V_2 -> V_29 ) ;
V_2 -> V_51 = 0 ;
}
}
}
F_23 ( & V_2 -> V_7 -> V_59 , NULL , L_9 ) ;
return V_60 ;
}
static T_3 F_24 ( int V_41 , void * V_42 )
{
struct V_1 * V_2 = V_42 ;
int V_43 = V_40 ;
T_1 V_45 ;
V_45 = F_4 ( V_2 , V_25 , V_46 ) ;
if ( V_45 & V_49 ) {
F_20 ( V_2 -> V_29 ) ;
V_2 -> V_51 = 1 ;
F_1 ( V_2 , V_19 , V_61 , 0x1 ) ;
F_1 ( V_2 , V_19 , V_62 ,
0x10 ) ;
V_43 = V_15 ;
V_2 -> V_52 . V_53 = true ;
V_2 -> V_52 . V_54 = V_63 ;
V_2 -> V_14 = V_43 ;
V_2 -> V_52 . V_56 = V_43 ;
F_21 ( & V_2 -> V_52 . V_57 , V_43 ,
V_2 -> V_52 . V_58 ) ;
} else {
F_1 ( V_2 , V_19 , V_61 ,
0x10 ) ;
F_1 ( V_2 , V_19 , V_62 ,
0x1 ) ;
}
F_1 ( V_2 , V_19 , V_64 , V_43 ) ;
return V_60 ;
}
static int F_25 ( struct V_8 * V_9 ,
struct V_65 * V_58 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return - V_30 ;
V_2 = F_7 ( V_9 ) ;
V_2 -> V_52 . V_58 = V_58 ;
if ( ! V_58 )
V_2 -> V_52 . V_54 = V_66 ;
return 0 ;
}
static int F_26 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 , V_19 , V_62 , 0x1 ) ;
F_27 ( 0x05 , V_67 ) ;
F_27 ( 0x05 , V_68 ) ;
F_27 ( V_69 ,
V_67 ) ;
F_27 ( V_69 ,
V_68 ) ;
F_19 ( V_2 -> V_70 , V_2 ) ;
F_24 ( V_2 -> V_71 , V_2 ) ;
return 0 ;
}
static void F_28 ( struct V_72 * V_4 )
{
struct V_1 * V_2 = F_29 ( V_4 , struct V_1 ,
V_73 ) ;
if ( V_2 -> V_74 )
F_1 ( V_2 , V_47 , 0x40 ,
V_75 ) ;
else
F_1 ( V_2 , V_47 , 0x00 ,
V_75 ) ;
}
static int F_30 ( struct V_8 * V_9 , bool V_76 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
V_2 -> V_74 = V_76 ;
F_31 ( & V_2 -> V_73 ) ;
return 0 ;
}
static int F_32 ( struct V_8 * V_9 , struct V_77 * V_78 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return - V_30 ;
V_2 = F_7 ( V_9 ) ;
V_2 -> V_52 . V_78 = V_78 ;
if ( ! V_78 )
V_2 -> V_52 . V_54 = V_66 ;
return 0 ;
}
static int T_4 F_33 ( struct V_79 * V_80 )
{
struct V_1 * V_2 ;
int V_43 , V_81 ;
struct V_11 * V_12 ;
struct V_10 * V_7 = & V_80 -> V_7 ;
V_12 = V_7 -> V_13 ;
V_2 = F_34 ( sizeof *V_2 , V_82 ) ;
if ( ! V_2 )
return - V_83 ;
V_2 -> V_7 = & V_80 -> V_7 ;
V_2 -> V_71 = F_35 ( V_80 , 0 ) ;
V_2 -> V_70 = F_35 ( V_80 , 1 ) ;
V_2 -> V_23 = V_12 -> V_23 ;
V_2 -> V_52 . V_7 = V_2 -> V_7 ;
V_2 -> V_52 . V_84 = L_10 ;
V_2 -> V_52 . V_85 = F_32 ;
V_2 -> V_52 . V_86 = F_25 ;
V_2 -> V_52 . V_87 = F_30 ;
V_2 -> V_52 . V_88 = F_6 ;
V_2 -> V_52 . V_89 = F_8 ;
V_2 -> V_52 . V_90 = F_9 ;
V_2 -> V_52 . V_91 = F_10 ;
F_36 ( & V_2 -> V_37 ) ;
V_81 = F_12 ( V_2 ) ;
if ( V_81 ) {
F_3 ( & V_80 -> V_7 , L_11 ) ;
F_37 ( V_2 ) ;
return V_81 ;
}
F_38 ( & V_2 -> V_52 ) ;
F_39 ( V_80 , V_2 ) ;
if ( F_40 ( & V_80 -> V_7 , & V_92 ) )
F_41 ( & V_80 -> V_7 , L_12 ) ;
F_42 ( & V_2 -> V_52 . V_57 ) ;
F_43 ( & V_2 -> V_73 , F_28 ) ;
V_2 -> V_93 = true ;
V_43 = F_44 ( V_2 -> V_71 , NULL , F_24 ,
V_94 | V_95 ,
L_13 , V_2 ) ;
if ( V_43 < 0 ) {
F_3 ( & V_80 -> V_7 , L_14 ,
V_2 -> V_71 , V_43 ) ;
F_45 ( V_2 -> V_7 , & V_92 ) ;
F_37 ( V_2 ) ;
return V_43 ;
}
V_43 = F_44 ( V_2 -> V_70 , NULL , F_19 ,
V_94 | V_95 ,
L_13 , V_2 ) ;
if ( V_43 < 0 ) {
F_3 ( & V_80 -> V_7 , L_14 ,
V_2 -> V_70 , V_43 ) ;
F_46 ( V_2 -> V_71 , V_2 ) ;
F_45 ( V_2 -> V_7 , & V_92 ) ;
F_37 ( V_2 ) ;
return V_43 ;
}
V_2 -> V_51 = 0 ;
V_12 -> V_96 ( V_7 ) ;
F_9 ( & V_2 -> V_52 , 0 ) ;
F_26 ( & V_2 -> V_52 ) ;
F_47 ( & V_80 -> V_7 , L_15 ) ;
return 0 ;
}
static int T_5 F_48 ( struct V_79 * V_80 )
{
struct V_1 * V_2 = F_49 ( V_80 ) ;
struct V_11 * V_12 ;
struct V_10 * V_7 = & V_80 -> V_7 ;
V_12 = V_7 -> V_13 ;
F_50 ( V_97 ,
V_67 ) ;
F_50 ( V_97 ,
V_68 ) ;
F_46 ( V_2 -> V_71 , V_2 ) ;
F_46 ( V_2 -> V_70 , V_2 ) ;
F_51 ( V_2 -> V_29 ) ;
V_12 -> V_98 ( V_2 -> V_7 ) ;
F_45 ( V_2 -> V_7 , & V_92 ) ;
F_52 ( & V_2 -> V_73 ) ;
F_37 ( V_2 ) ;
return 0 ;
}
static int T_6 F_53 ( void )
{
return F_54 ( & V_99 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_99 ) ;
}
