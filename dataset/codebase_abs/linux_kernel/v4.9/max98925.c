static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
struct V_6 * V_7 = F_2 ( V_4 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
switch ( V_5 ) {
case V_10 :
F_4 ( V_9 -> V_11 ,
V_12 ,
V_13 |
V_14 | V_15 ,
V_13 |
V_14 | V_15 ) ;
break;
case V_16 :
F_4 ( V_9 -> V_11 ,
V_12 , V_13 |
V_14 | V_15 , 0 ) ;
break;
default:
return 0 ;
}
return 0 ;
}
static bool F_5 ( struct V_17 * V_18 , unsigned int V_19 )
{
switch ( V_19 ) {
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
case V_30 :
case V_31 :
return true ;
default:
return false ;
}
}
static bool F_6 ( struct V_17 * V_18 , unsigned int V_19 )
{
switch ( V_19 ) {
case V_32 :
case V_33 :
case V_34 :
case V_35 :
return false ;
default:
return true ;
}
}
static inline int F_7 ( struct V_6 * V_7 ,
int V_36 , int clock , int * V_37 , int * V_38 , int * V_39 )
{
int V_40 = - V_41 ;
int V_42 ;
for ( V_42 = 0 ; V_42 < F_8 ( V_43 ) ; V_42 ++ ) {
if ( V_43 [ V_42 ] . V_36 >= V_36 ) {
* V_37 = V_43 [ V_42 ] . V_44 ;
* V_38 = V_43 [ V_42 ] . V_45 [ clock ] [ 0 ] ;
* V_39 = V_43 [ V_42 ] . V_45 [ clock ] [ 1 ] ;
V_40 = 0 ;
break;
}
}
return V_40 ;
}
static void F_9 ( struct V_8 * V_9 )
{
F_4 ( V_9 -> V_11 ,
V_46 ,
V_47 , V_47 ) ;
F_4 ( V_9 -> V_11 ,
V_46 ,
V_48 ,
V_9 -> V_49 << V_50 ) ;
F_4 ( V_9 -> V_11 ,
V_51 ,
V_52 , V_52 ) ;
F_4 ( V_9 -> V_11 ,
V_51 ,
V_53 ,
V_9 -> V_54 << V_55 ) ;
}
static int F_10 ( struct V_56 * V_57 ,
unsigned int V_58 )
{
struct V_6 * V_7 = V_57 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
unsigned int V_59 = 0 ;
F_11 ( V_7 -> V_18 , L_1 , V_60 , V_58 ) ;
switch ( V_58 & V_61 ) {
case V_62 :
F_4 ( V_9 -> V_11 ,
V_63 ,
V_64 , 0 ) ;
F_9 ( V_9 ) ;
break;
case V_65 :
F_4 ( V_9 -> V_11 ,
V_63 ,
V_64 , V_64 ) ;
break;
case V_66 :
case V_67 :
default:
F_12 ( V_7 -> V_18 , L_2 ) ;
return - V_41 ;
}
switch ( V_58 & V_68 ) {
case V_69 :
break;
case V_70 :
V_59 = V_71 ;
break;
case V_72 :
V_59 = V_73 ;
break;
case V_74 :
V_59 = V_73 | V_71 ;
break;
default:
F_12 ( V_7 -> V_18 , L_3 ) ;
return - V_41 ;
}
F_4 ( V_9 -> V_11 , V_75 ,
V_73 | V_71 , V_59 ) ;
return 0 ;
}
static int F_13 ( struct V_8 * V_9 ,
struct V_76 * V_77 )
{
unsigned int V_78 = 0 , clock , V_79 , V_38 , V_39 ;
struct V_6 * V_7 = V_9 -> V_7 ;
int V_36 = F_14 ( V_77 ) ;
int V_80 = F_15 ( V_77 ) * V_9 -> V_81 ;
switch ( V_80 ) {
case 32 :
F_4 ( V_9 -> V_11 ,
V_63 ,
V_82 , V_83 ) ;
break;
case 48 :
F_4 ( V_9 -> V_11 ,
V_63 ,
V_82 , V_84 ) ;
break;
case 64 :
F_4 ( V_9 -> V_11 ,
V_63 ,
V_82 , V_85 ) ;
break;
default:
return - V_41 ;
}
switch ( V_9 -> V_86 ) {
case 6000000 :
clock = 0 ;
V_79 = V_87 ;
break;
case 11289600 :
clock = 1 ;
V_79 = V_88 ;
break;
case 12000000 :
clock = 0 ;
V_79 = V_88 ;
break;
case 12288000 :
clock = 2 ;
V_79 = V_88 ;
break;
default:
F_16 ( V_9 -> V_7 -> V_18 , L_4 ,
V_9 -> V_86 ) ;
return - V_41 ;
}
if ( F_7 ( V_7 , V_36 , clock , & V_78 , & V_38 , & V_39 ) )
return - V_41 ;
F_4 ( V_9 -> V_11 ,
V_63 ,
V_89 , V_78 << V_90 ) ;
F_17 ( V_9 -> V_11 ,
V_91 , V_39 >> 8 ) ;
F_17 ( V_9 -> V_11 ,
V_92 , V_39 & 0xFF ) ;
F_17 ( V_9 -> V_11 ,
V_93 , V_38 >> 8 ) ;
F_17 ( V_9 -> V_11 ,
V_94 , V_38 & 0xFF ) ;
F_4 ( V_9 -> V_11 , V_95 ,
V_96 , V_79 << V_97 ) ;
return 0 ;
}
static int F_18 ( struct V_98 * V_99 ,
struct V_76 * V_77 ,
struct V_56 * V_100 )
{
struct V_6 * V_7 = V_100 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
switch ( F_19 ( V_77 ) ) {
case 16 :
F_4 ( V_9 -> V_11 ,
V_75 ,
V_101 , V_102 ) ;
V_9 -> V_81 = 16 ;
break;
case 24 :
F_4 ( V_9 -> V_11 ,
V_75 ,
V_101 , V_103 ) ;
V_9 -> V_81 = 24 ;
break;
case 32 :
F_4 ( V_9 -> V_11 ,
V_75 ,
V_101 , V_104 ) ;
V_9 -> V_81 = 32 ;
break;
default:
F_20 ( L_5 ,
V_60 , F_21 ( V_77 ) ) ;
return - V_41 ;
}
F_11 ( V_7 -> V_18 , L_6 ,
V_60 , F_21 ( V_77 ) ) ;
return F_13 ( V_9 , V_77 ) ;
}
static int F_22 ( struct V_56 * V_100 ,
int V_105 , unsigned int V_106 , int V_107 )
{
struct V_6 * V_7 = V_100 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
switch ( V_105 ) {
case 0 :
F_4 ( V_9 -> V_11 ,
V_95 ,
V_108 , 0 ) ;
break;
case 1 :
F_4 ( V_9 -> V_11 ,
V_95 ,
V_108 ,
V_108 ) ;
break;
default:
return - V_41 ;
}
V_9 -> V_86 = V_106 ;
return 0 ;
}
static int F_23 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = F_3 ( V_7 ) ;
V_9 -> V_7 = V_7 ;
F_17 ( V_9 -> V_11 , V_109 , 0x00 ) ;
F_17 ( V_9 -> V_11 ,
V_75 , V_110 ) ;
F_17 ( V_9 -> V_11 , V_111 , 0xC8 ) ;
F_17 ( V_9 -> V_11 , V_112 , 0xFF ) ;
F_17 ( V_9 -> V_11 , V_113 , 0xFF ) ;
F_17 ( V_9 -> V_11 , V_114 , 0xFF ) ;
F_17 ( V_9 -> V_11 , V_115 , 0xF0 ) ;
F_17 ( V_9 -> V_11 , V_116 , 0xD8 ) ;
F_17 ( V_9 -> V_11 , V_117 , 0xF8 ) ;
F_17 ( V_9 -> V_11 , V_118 , 0xF0 ) ;
F_17 ( V_9 -> V_11 , V_119 , 0xF8 ) ;
return 0 ;
}
static int F_24 ( struct V_120 * V_121 ,
const struct V_122 * V_123 )
{
int V_40 , V_19 ;
T_1 V_37 ;
struct V_8 * V_9 ;
V_9 = F_25 ( & V_121 -> V_18 ,
sizeof( * V_9 ) , V_124 ) ;
if ( ! V_9 )
return - V_125 ;
F_26 ( V_121 , V_9 ) ;
V_9 -> V_11 = F_27 ( V_121 , & V_126 ) ;
if ( F_28 ( V_9 -> V_11 ) ) {
V_40 = F_29 ( V_9 -> V_11 ) ;
F_12 ( & V_121 -> V_18 ,
L_7 , V_40 ) ;
goto V_127;
}
if ( ! F_30 ( V_121 -> V_18 . V_128 , L_8 , & V_37 ) ) {
if ( V_37 > V_129 ) {
F_12 ( & V_121 -> V_18 , L_9 ) ;
return - V_41 ;
}
V_9 -> V_49 = V_37 ;
}
if ( ! F_30 ( V_121 -> V_18 . V_128 , L_10 , & V_37 ) ) {
if ( V_37 > V_130 ) {
F_12 ( & V_121 -> V_18 , L_11 ) ;
return - V_41 ;
}
V_9 -> V_54 = V_37 ;
}
V_40 = F_31 ( V_9 -> V_11 ,
V_31 , & V_19 ) ;
if ( ( V_40 < 0 ) ||
( ( V_19 != V_131 ) &&
( V_19 != V_132 ) ) ) {
F_12 ( & V_121 -> V_18 ,
L_12 ,
V_40 , V_19 ) ;
goto V_127;
}
F_16 ( & V_121 -> V_18 , L_13 , V_19 ) ;
V_40 = F_32 ( & V_121 -> V_18 , & V_133 ,
V_134 , F_8 ( V_134 ) ) ;
if ( V_40 < 0 )
F_12 ( & V_121 -> V_18 ,
L_14 , V_40 ) ;
V_127:
return V_40 ;
}
static int F_33 ( struct V_120 * V_135 )
{
F_34 ( & V_135 -> V_18 ) ;
return 0 ;
}
