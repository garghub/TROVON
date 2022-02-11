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
static int F_6 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
V_2 = F_7 ( V_9 ) ;
V_7 = V_2 -> V_7 ;
V_13 = V_7 -> V_14 ;
V_13 -> V_15 ( V_2 -> V_7 , V_10 ) ;
return 0 ;
}
static int F_8 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
V_2 = F_7 ( V_9 ) ;
V_7 = V_2 -> V_7 ;
V_13 = V_7 -> V_14 ;
if ( V_2 -> V_16 == V_17 )
V_13 -> V_18 ( V_2 -> V_7 , 1 , 1 ) ;
else
V_13 -> V_18 ( V_2 -> V_7 , 0 , 1 ) ;
return 0 ;
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 ;
struct V_11 * V_7 ;
struct V_12 * V_13 ;
V_2 = F_7 ( V_9 ) ;
V_7 = V_2 -> V_7 ;
V_13 = V_7 -> V_14 ;
V_13 -> V_18 ( V_2 -> V_7 , 0 , 0 ) ;
}
static int F_10 ( struct V_8 * V_9 , int V_19 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
struct V_11 * V_7 = V_2 -> V_7 ;
struct V_12 * V_13 = V_7 -> V_14 ;
V_13 -> V_20 ( V_7 , V_19 ) ;
return 0 ;
}
static int F_11 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 , V_21 , 0x24 , V_22 ) ;
F_1 ( V_2 , V_21 , 0x84 , V_22 ) ;
F_12 ( 100 ) ;
F_1 ( V_2 , V_21 , 0xa0 , V_23 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 )
{
char * V_24 ;
if ( V_2 -> V_25 & V_26 )
V_24 = L_3 ;
else
V_24 = L_4 ;
F_1 ( V_2 , V_27 , 0x1 , V_28 ) ;
F_1 ( V_2 , V_27 , 0x1 , V_29 ) ;
F_1 ( V_2 , V_27 , 0x10 , V_30 ) ;
V_2 -> V_31 = F_14 ( V_2 -> V_7 , V_24 ) ;
if ( F_15 ( V_2 -> V_31 ) )
return - V_32 ;
F_1 ( V_2 , V_21 , 0x4 , V_22 ) ;
F_1 ( V_2 , V_21 , 0x14 , V_33 ) ;
return 0 ;
}
static T_2 F_16 ( struct V_11 * V_7 ,
struct V_34 * V_35 , char * V_36 )
{
struct V_1 * V_2 = F_17 ( V_7 ) ;
unsigned long V_37 ;
int V_6 = - V_38 ;
F_18 ( & V_2 -> V_39 , V_37 ) ;
switch ( V_2 -> V_16 ) {
case V_40 :
V_6 = snprintf ( V_36 , V_41 , L_5 ) ;
break;
case V_17 :
V_6 = snprintf ( V_36 , V_41 , L_6 ) ;
break;
case V_42 :
V_6 = snprintf ( V_36 , V_41 , L_7 ) ;
break;
default:
V_6 = snprintf ( V_36 , V_41 , L_8 ) ;
}
F_19 ( & V_2 -> V_39 , V_37 ) ;
return V_6 ;
}
static T_3 F_20 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
int V_45 ;
T_1 V_46 , V_47 ;
V_47 = F_4 ( V_2 , V_27 , V_48 ) ;
V_46 = F_4 ( V_2 , V_49 ,
V_50 ) ;
if ( ! ( V_47 & V_51 ) ) {
if ( V_46 & V_52 ) {
F_21 ( V_2 -> V_31 ) ;
V_2 -> V_53 = 1 ;
V_45 = V_40 ;
V_2 -> V_54 . V_55 = false ;
V_2 -> V_54 . V_56 = V_57 ;
V_2 -> V_16 = V_45 ;
V_2 -> V_54 . V_58 = V_45 ;
F_22 ( & V_2 -> V_54 . V_59 ,
V_45 , V_2 -> V_54 . V_60 ) ;
} else {
V_45 = V_42 ;
V_2 -> V_16 = V_45 ;
V_2 -> V_54 . V_58 = V_45 ;
F_22 ( & V_2 -> V_54 . V_59 ,
V_45 , V_2 -> V_54 . V_60 ) ;
if ( V_2 -> V_53 ) {
F_23 ( V_2 -> V_31 ) ;
V_2 -> V_53 = 0 ;
}
}
}
F_24 ( & V_2 -> V_7 -> V_61 , NULL , L_9 ) ;
return V_62 ;
}
static T_3 F_25 ( int V_43 , void * V_44 )
{
struct V_1 * V_2 = V_44 ;
int V_45 = V_42 ;
T_1 V_47 ;
V_47 = F_4 ( V_2 , V_27 , V_48 ) ;
if ( V_47 & V_51 ) {
F_21 ( V_2 -> V_31 ) ;
V_2 -> V_53 = 1 ;
F_1 ( V_2 , V_21 , V_63 , 0x1 ) ;
F_1 ( V_2 , V_21 , V_64 ,
0x10 ) ;
V_45 = V_17 ;
V_2 -> V_54 . V_55 = true ;
V_2 -> V_54 . V_56 = V_65 ;
V_2 -> V_16 = V_45 ;
V_2 -> V_54 . V_58 = V_45 ;
F_22 ( & V_2 -> V_54 . V_59 , V_45 ,
V_2 -> V_54 . V_60 ) ;
} else {
F_1 ( V_2 , V_21 , V_63 ,
0x10 ) ;
F_1 ( V_2 , V_21 , V_64 ,
0x1 ) ;
}
F_1 ( V_2 , V_21 , V_66 , V_45 ) ;
return V_62 ;
}
static int F_26 ( struct V_8 * V_9 ,
struct V_67 * V_60 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return - V_32 ;
V_2 = F_7 ( V_9 ) ;
V_2 -> V_54 . V_60 = V_60 ;
if ( ! V_60 )
V_2 -> V_54 . V_56 = V_68 ;
return 0 ;
}
static int F_27 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
F_1 ( V_2 , V_21 , V_64 , 0x1 ) ;
F_28 ( 0x05 , V_69 ) ;
F_28 ( 0x05 , V_70 ) ;
F_28 ( V_71 ,
V_69 ) ;
F_28 ( V_71 ,
V_70 ) ;
F_20 ( V_2 -> V_72 , V_2 ) ;
F_25 ( V_2 -> V_73 , V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_8 * V_9 , bool V_74 )
{
struct V_1 * V_2 = F_7 ( V_9 ) ;
if ( V_74 )
F_1 ( V_2 , V_49 , 0x40 ,
V_75 ) ;
else
F_1 ( V_2 , V_49 , 0x00 ,
V_75 ) ;
return 0 ;
}
static int F_30 ( struct V_8 * V_9 , struct V_76 * V_77 )
{
struct V_1 * V_2 ;
if ( ! V_9 )
return - V_32 ;
V_2 = F_7 ( V_9 ) ;
V_2 -> V_54 . V_77 = V_77 ;
if ( ! V_77 )
V_2 -> V_54 . V_56 = V_68 ;
return 0 ;
}
static int T_4 F_31 ( struct V_78 * V_79 )
{
struct V_1 * V_2 ;
int V_45 , V_80 ;
struct V_12 * V_13 ;
struct V_11 * V_7 = & V_79 -> V_7 ;
V_13 = V_7 -> V_14 ;
V_2 = F_32 ( sizeof *V_2 , V_81 ) ;
if ( ! V_2 )
return - V_82 ;
V_2 -> V_7 = & V_79 -> V_7 ;
V_2 -> V_73 = F_33 ( V_79 , 0 ) ;
V_2 -> V_72 = F_33 ( V_79 , 1 ) ;
V_2 -> V_25 = V_13 -> V_25 ;
V_2 -> V_54 . V_7 = V_2 -> V_7 ;
V_2 -> V_54 . V_83 = L_10 ;
V_2 -> V_54 . V_84 = F_30 ;
V_2 -> V_54 . V_85 = F_26 ;
V_2 -> V_54 . V_86 = F_29 ;
V_2 -> V_54 . V_87 = F_8 ;
V_2 -> V_54 . V_88 = F_9 ;
V_2 -> V_54 . V_89 = F_10 ;
V_2 -> V_54 . V_90 = F_11 ;
F_34 ( & V_2 -> V_39 ) ;
V_80 = F_13 ( V_2 ) ;
if ( V_80 ) {
F_3 ( & V_79 -> V_7 , L_11 ) ;
F_35 ( V_2 ) ;
return V_80 ;
}
F_36 ( & V_2 -> V_54 ) ;
F_37 ( V_79 , V_2 ) ;
if ( F_38 ( & V_79 -> V_7 , & V_91 ) )
F_39 ( & V_79 -> V_7 , L_12 ) ;
F_40 ( & V_2 -> V_54 . V_59 ) ;
V_2 -> V_92 = true ;
V_45 = F_41 ( V_2 -> V_73 , NULL , F_25 ,
V_93 | V_94 ,
L_13 , V_2 ) ;
if ( V_45 < 0 ) {
F_3 ( & V_79 -> V_7 , L_14 ,
V_2 -> V_73 , V_45 ) ;
F_42 ( V_2 -> V_7 , & V_91 ) ;
F_35 ( V_2 ) ;
return V_45 ;
}
V_45 = F_41 ( V_2 -> V_72 , NULL , F_20 ,
V_93 | V_94 ,
L_13 , V_2 ) ;
if ( V_45 < 0 ) {
F_3 ( & V_79 -> V_7 , L_14 ,
V_2 -> V_72 , V_45 ) ;
F_43 ( V_2 -> V_73 , V_2 ) ;
F_42 ( V_2 -> V_7 , & V_91 ) ;
F_35 ( V_2 ) ;
return V_45 ;
}
V_2 -> V_53 = 0 ;
V_13 -> V_95 ( V_7 ) ;
F_10 ( & V_2 -> V_54 , 0 ) ;
F_27 ( & V_2 -> V_54 ) ;
F_44 ( & V_79 -> V_7 , L_15 ) ;
return 0 ;
}
static int T_5 F_45 ( struct V_78 * V_79 )
{
struct V_1 * V_2 = F_46 ( V_79 ) ;
struct V_12 * V_13 ;
struct V_11 * V_7 = & V_79 -> V_7 ;
V_13 = V_7 -> V_14 ;
F_47 ( V_96 ,
V_69 ) ;
F_47 ( V_96 ,
V_70 ) ;
F_43 ( V_2 -> V_73 , V_2 ) ;
F_43 ( V_2 -> V_72 , V_2 ) ;
F_48 ( V_2 -> V_31 ) ;
V_13 -> V_97 ( V_2 -> V_7 ) ;
F_42 ( V_2 -> V_7 , & V_91 ) ;
F_35 ( V_2 ) ;
return 0 ;
}
static int T_6 F_49 ( void )
{
return F_50 ( & V_98 ) ;
}
static void T_5 F_51 ( void )
{
F_52 ( & V_98 ) ;
}
