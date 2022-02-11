static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_4 -> V_6 ;
struct V_7 * V_8 = V_4 -> V_8 ;
struct V_9 * V_10 ;
struct V_11 V_12 ;
if ( ! V_8 || ! V_6 )
return 0 ;
V_10 = F_2 ( V_4 -> V_13 ,
V_8 ) ;
if ( F_3 ( ! V_10 ) )
return - V_14 ;
if ( ! V_10 -> V_15 )
return 0 ;
if ( ! V_4 -> V_8 )
return - V_14 ;
V_12 . V_16 = 0 ;
V_12 . y1 = 0 ;
V_12 . V_17 = V_10 -> V_18 . V_19 ;
V_12 . V_20 = V_10 -> V_18 . V_21 ;
return F_4 ( V_4 , & V_12 ,
V_22 ,
V_22 ,
false , true ) ;
}
static int F_5 ( T_1 V_23 )
{
switch ( V_23 ) {
case V_24 :
case V_25 :
return V_26 ;
case V_27 :
return V_28 ;
case V_29 :
return V_30 ;
case V_31 :
return V_32 ;
case V_33 :
return V_34 ;
default:
F_6 ( 1 , L_1 , V_23 ) ;
return - V_14 ;
}
}
static inline void F_7 ( struct V_35 * V_36 )
{
void T_2 * V_37 = V_36 -> V_37 ;
F_8 ( V_37 + V_38 , V_39 , V_39 ) ;
}
static inline void F_9 ( struct V_35 * V_36 )
{
F_10 ( V_36 -> V_40 + V_41 , 1 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
struct V_35 * V_36 = F_12 ( V_2 ) ;
F_9 ( V_36 ) ;
F_7 ( V_36 ) ;
}
static void F_13 ( struct V_35 * V_36 , T_3 V_42 , T_3 V_43 ,
T_3 V_44 , T_3 V_45 )
{
void T_2 * V_40 = V_36 -> V_40 ;
F_10 ( V_40 + V_46 , F_14 ( V_43 - 1 ) | F_15 ( V_42 - 1 ) ) ;
F_10 ( V_40 + V_47 , F_14 ( V_45 - 1 ) | F_15 ( V_44 - 1 ) ) ;
F_9 ( V_36 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_48 )
{
struct V_35 * V_36 = F_12 ( V_2 ) ;
struct V_5 * V_6 = V_2 -> V_13 -> V_6 ;
struct V_49 * V_50 ;
void T_2 * V_37 = V_36 -> V_37 ;
void T_2 * V_51 = V_36 -> V_51 ;
void T_2 * V_52 = V_36 -> V_52 ;
T_3 V_53 , V_54 , V_42 , V_43 ;
T_3 V_55 , V_56 , V_44 , V_45 ;
unsigned int V_57 ;
T_1 V_23 ;
T_4 V_58 ;
T_3 V_59 ;
int V_60 ;
if ( ! V_6 )
return;
V_23 = V_6 -> V_61 ;
V_59 = V_6 -> V_62 [ 0 ] ;
V_53 = V_2 -> V_13 -> V_53 >> 16 ;
V_54 = V_2 -> V_13 -> V_54 >> 16 ;
V_42 = V_2 -> V_13 -> V_42 >> 16 ;
V_43 = V_2 -> V_13 -> V_43 >> 16 ;
V_55 = V_2 -> V_13 -> V_63 ;
V_56 = V_2 -> V_13 -> V_64 ;
V_44 = V_2 -> V_13 -> V_65 ;
V_45 = V_2 -> V_13 -> V_66 ;
V_57 = F_17 ( V_23 , 0 ) ;
V_50 = F_18 ( V_6 , 0 ) ;
V_58 = V_50 -> V_58 + V_6 -> V_67 [ 0 ] ;
V_58 += V_54 * V_59 + V_53 * V_57 / 8 ;
F_10 ( V_37 + V_68 , V_58 ) ;
F_10 ( V_37 + V_69 , F_19 ( V_42 ) | F_20 ( V_43 ) ) ;
F_10 ( V_37 + V_70 , F_21 ( V_55 ) | F_22 ( V_56 ) ) ;
F_10 ( V_37 + V_71 ,
F_21 ( V_55 + V_44 ) | F_22 ( V_56 + V_45 ) ) ;
F_10 ( V_37 + V_72 , V_59 & 0xffff ) ;
V_60 = F_5 ( V_23 ) ;
if ( V_60 >= 0 )
F_8 ( V_37 + V_73 , V_74 ,
V_60 << V_75 ) ;
F_8 ( V_37 + V_76 , V_77 ,
0xff << V_78 ) ;
if ( V_45 > 720 )
F_8 ( V_51 + V_79 , V_80 ,
V_81 << V_82 ) ;
else
F_8 ( V_51 + V_79 , V_80 ,
V_83 << V_82 ) ;
F_8 ( V_51 + V_79 , V_84 , V_84 ) ;
F_8 ( V_37 + V_85 , V_86 ,
V_86 ) ;
F_13 ( V_36 , V_42 , V_43 , V_44 , V_45 ) ;
F_8 ( V_52 + V_87 , V_88 , V_88 ) ;
F_7 ( V_36 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_25 ( V_2 ) ;
}
static void F_26 ( struct V_35 * V_36 )
{
void T_2 * V_52 = V_36 -> V_52 ;
F_10 ( V_52 + V_89 , 0x200 ) ;
F_10 ( V_52 + V_90 , 0x0 ) ;
F_10 ( V_52 + V_91 , 0x0 ) ;
F_10 ( V_52 + V_92 , 0x200 ) ;
F_10 ( V_52 + V_93 , ( 0x3ac << 16 ) | 0x40 ) ;
F_10 ( V_52 + V_94 , ( 0x3c0 << 16 ) | 0x40 ) ;
F_10 ( V_52 + V_95 , ( 0x3c0 << 16 ) | 0x40 ) ;
}
struct V_1 * F_27 ( struct V_96 * V_97 , struct V_98 * V_99 ,
struct V_100 * V_101 ,
enum V_102 type )
{
const struct V_103 * V_104 ;
struct V_35 * V_36 ;
struct V_1 * V_2 ;
const T_1 * V_105 ;
unsigned int V_106 ;
int V_107 ;
V_36 = F_28 ( V_99 , sizeof( * V_36 ) , V_108 ) ;
if ( ! V_36 )
return F_29 ( - V_109 ) ;
V_2 = & V_36 -> V_2 ;
V_36 -> V_37 = V_101 -> V_37 ;
V_36 -> V_52 = V_101 -> V_52 ;
V_36 -> V_51 = V_101 -> V_51 ;
V_36 -> V_40 = V_101 -> V_40 ;
F_26 ( V_36 ) ;
switch ( type ) {
case V_110 :
V_104 = & V_111 ;
V_105 = V_112 ;
V_106 = F_30 ( V_112 ) ;
break;
case V_113 :
break;
default:
return F_29 ( - V_114 ) ;
}
V_107 = F_31 ( V_97 , V_2 , V_115 ,
& V_116 , V_105 , V_106 ,
type , NULL ) ;
if ( V_107 ) {
F_32 ( V_99 , L_2 , V_107 ) ;
return F_29 ( V_107 ) ;
}
F_33 ( V_2 , V_104 ) ;
return V_2 ;
}
