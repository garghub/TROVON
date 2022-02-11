static int F_1 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 , V_5 ;
V_3 = F_2 ( V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 &= V_8 ;
V_5 >>= V_9 ;
switch ( V_5 ) {
case V_10 :
case V_11 :
* V_2 = V_12 ;
break;
case V_13 :
if ( V_4 & V_14 )
* V_2 = V_15 ;
else
* V_2 = V_12 ;
break;
case V_16 :
default:
if ( ! ( V_4 & V_17 ) )
* V_2 = V_18 ;
else
* V_2 = V_19 ;
break;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 , V_5 ;
V_3 = F_2 ( V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 &= V_8 ;
V_5 >>= V_9 ;
switch ( V_5 ) {
case V_10 :
* V_2 = V_20 ;
break;
case V_11 :
* V_2 = V_21 ;
break;
case V_13 :
* V_2 = V_22 ;
break;
case V_16 :
default:
if ( ! ( V_4 & V_17 ) )
* V_2 = V_22 ;
else
* V_2 = V_23 ;
break;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 , V_5 , V_24 ;
V_3 = F_2 ( V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_25 , & V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 &= V_8 ;
V_5 >>= V_9 ;
switch ( V_5 ) {
case V_16 :
if ( V_24 & V_26 ) {
* V_2 = V_27 ;
} else if ( V_4 & V_17 ) {
if ( ! ( V_4 & V_28 ) )
* V_2 = V_29 ;
else if ( V_4 & V_30 )
* V_2 = V_31 ;
else
* V_2 = V_32 ;
} else {
* V_2 = V_33 ;
}
break;
case V_10 :
case V_11 :
case V_13 :
default:
* V_2 = V_33 ;
break;
}
return 0 ;
}
static int F_5 ( struct V_34 * V_35 ,
struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 , V_5 , V_24 ;
int V_36 = F_6 ( V_35 -> V_37 ) ;
V_3 = F_2 ( V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_25 , & V_24 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_5 &= V_8 ;
V_5 >>= V_9 ;
switch ( V_5 ) {
case V_10 :
* V_2 = V_38 ;
break;
case V_11 :
if ( V_36 )
* V_2 = V_39 ;
else
* V_2 = V_38 ;
break;
case V_13 :
if ( V_4 & V_14 )
* V_2 = V_40 ;
else
* V_2 = V_41 ;
break;
case V_16 :
default:
if ( V_24 & V_26 ) {
* V_2 = V_42 ;
} else {
* V_2 = V_41 ;
if ( ! ( V_4 & V_17 ) ) {
if ( ! V_36 )
* V_2 = V_43 ;
}
}
break;
}
return 0 ;
}
static int F_7 ( struct V_34 * V_35 ,
struct V_1 * V_1 , int * V_2 )
{
int V_3 ;
unsigned int V_4 , V_5 ;
unsigned int V_44 ;
int V_45 = F_6 ( V_35 -> V_46 ) ;
V_3 = F_2 ( V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
V_44 = ( V_5 & V_47 ) >> 1 ;
V_5 &= V_8 ;
V_5 >>= V_9 ;
switch ( V_5 ) {
case V_10 :
if ( V_44 ) {
if ( V_45 )
* V_2 = V_48 ;
else
* V_2 = V_49 ;
} else {
* V_2 = V_50 ;
}
break;
case V_11 :
if ( V_44 ) {
if ( V_45 )
* V_2 = V_51 ;
else
* V_2 = V_52 ;
} else {
if ( V_45 )
* V_2 = V_53 ;
else
* V_2 = V_54 ;
}
break;
case V_13 :
case V_16 :
default:
* V_2 = 0 ;
break;
}
return 0 ;
}
static int F_8 ( struct V_55 * V_56 ,
enum V_57 V_58 ,
union V_59 * V_2 )
{
struct V_34 * V_35 = F_9 ( V_56 ) ;
struct V_1 * V_1 = V_35 -> V_1 ;
int V_3 = 0 ;
switch ( V_58 ) {
case V_60 :
V_3 = F_1 ( V_1 , & V_2 -> V_61 ) ;
break;
case V_62 :
V_3 = F_3 ( V_1 , & V_2 -> V_61 ) ;
break;
case V_63 :
V_2 -> V_61 = V_64 ;
break;
case V_65 :
V_3 = F_4 ( V_1 , & V_2 -> V_61 ) ;
break;
case V_66 :
V_3 = F_5 ( V_35 ,
V_1 , & V_2 -> V_61 ) ;
break;
case V_67 :
V_3 = F_7 ( V_35 ,
V_1 , & V_2 -> V_61 ) ;
break;
case V_68 :
V_2 -> V_69 = V_70 ;
break;
case V_71 :
V_2 -> V_69 = V_72 ;
break;
default:
return - V_73 ;
}
return V_3 ;
}
static int F_10 ( struct V_34 * V_35 )
{
struct V_1 * V_1 = V_35 -> V_1 ;
unsigned char V_74 ;
int V_3 ;
V_74 = V_75 | V_76 |
V_77 | V_78 |
V_79 | V_80 |
V_81 | V_82 ;
V_3 = F_11 ( V_1 , V_83 , V_74 ) ;
if ( V_3 )
return V_3 ;
V_74 = V_84 | V_85 |
V_86 | V_87 ;
V_3 = F_11 ( V_1 , V_6 , V_74 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static unsigned int F_12 ( struct V_34 * V_35 ,
unsigned int * type )
{
unsigned int V_4 , V_5 ;
int V_3 ;
V_3 = F_2 ( V_35 -> V_1 , V_6 , & V_4 ) ;
if ( V_3 < 0 )
return V_3 ;
V_3 = F_2 ( V_35 -> V_1 , V_7 , & V_5 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( V_4 & V_17 ) {
if ( V_5 & V_47 )
* type = V_88 ;
else
* type = V_89 ;
} else {
* type = V_90 ;
}
return 0 ;
}
static void F_13 ( struct V_91 * V_92 )
{
struct V_34 * V_35 =
F_14 ( V_92 , struct V_34 , V_92 ) ;
F_12 ( V_35 , & V_35 -> V_93 . type ) ;
F_15 ( V_35 -> V_56 ) ;
}
static T_1 F_16 ( int V_94 , void * V_95 )
{
struct V_34 * V_35 = V_95 ;
if ( V_35 -> V_96 )
F_17 ( & V_35 -> V_92 ) ;
return V_97 ;
}
static int F_18 ( struct V_98 * V_99 ,
struct V_34 * V_35 )
{
struct V_100 * V_101 = V_99 -> V_102 ;
struct V_1 * V_1 = V_35 -> V_1 ;
T_2 V_103 ;
T_2 V_104 ;
T_2 V_105 ;
int V_106 , V_3 ;
unsigned int V_107 ;
unsigned int V_108 = 0 ;
if ( ! V_101 ) {
F_19 ( V_99 , L_1 ) ;
return - V_73 ;
}
V_3 = F_2 ( V_1 , V_25 , & V_107 ) ;
if ( V_3 )
return V_3 ;
if ( V_107 & V_26 ) {
V_108 |= V_26 ;
F_20 ( V_99 , L_2 ) ;
}
V_35 -> V_37 = F_21 ( V_99 , L_3 ,
V_109 ) ;
if ( F_22 ( V_35 -> V_37 ) ) {
V_106 = F_23 ( V_35 -> V_37 ) ;
F_19 ( V_99 , L_4 , V_106 ) ;
return V_106 ;
}
V_3 = F_24 ( V_99 , F_25 ( V_35 -> V_37 ) ,
F_16 ,
( V_110 | V_111 ) ,
L_5 , V_35 ) ;
if ( V_3 )
F_20 ( V_99 , L_6 ) ;
V_35 -> V_46 = F_21 ( V_99 ,
L_7 ,
V_109 ) ;
if ( F_22 ( V_35 -> V_46 ) ) {
V_106 = F_23 ( V_35 -> V_46 ) ;
F_19 ( V_99 , L_8 , V_106 ) ;
return V_106 ;
}
if ( F_26 ( V_101 ,
L_9 ,
& V_105 ) )
V_105 = V_112 ;
if ( F_26 ( V_101 ,
L_10 ,
& V_104 ) )
V_104 = V_113 ;
if ( F_26 ( V_101 , L_11 ,
& V_103 ) )
V_103 = V_114 ;
switch ( V_105 ) {
case 8000 :
V_108 |= V_115 ;
break;
case 7500 :
V_108 |= V_116 ;
break;
case 7000 :
V_108 |= V_117 ;
break;
case 6600 :
default:
V_108 |= V_118 ;
break;
}
switch ( V_104 ) {
case 60 :
V_108 |= V_119 ;
break;
case 80 :
V_108 |= V_120 ;
break;
case 0 :
V_108 |= V_121 ;
break;
case 40 :
default:
V_108 |= V_122 ;
break;
}
switch ( V_103 ) {
case 4 :
V_108 |= V_123 ;
break;
case 5 :
V_108 |= V_124 ;
break;
case 0 :
V_108 |= V_125 ;
break;
case 3 :
default:
V_108 |= V_126 ;
break;
}
return F_11 ( V_1 , V_25 , V_108 ) ;
}
static int F_27 ( struct V_127 * V_128 )
{
struct V_34 * V_35 ;
struct V_129 V_130 = {} ;
int V_94 , V_3 ;
V_35 = F_28 ( & V_128 -> V_99 , sizeof( * V_35 ) , V_131 ) ;
if ( ! V_35 )
return - V_132 ;
V_35 -> V_1 = F_29 ( V_128 -> V_99 . V_133 , NULL ) ;
if ( ! V_35 -> V_1 ) {
F_19 ( & V_128 -> V_99 , L_12 ) ;
return - V_73 ;
}
V_3 = F_18 ( & V_128 -> V_99 , V_35 ) ;
if ( V_3 )
return V_3 ;
V_94 = F_30 ( V_128 -> V_99 . V_102 , 0 ) ;
if ( V_94 == - V_134 ) {
F_19 ( & V_128 -> V_99 , L_13 ) ;
return - V_134 ;
}
V_3 = F_24 ( & V_128 -> V_99 , V_94 , F_16 ,
V_110 , L_14 ,
V_35 ) ;
if ( V_3 ) {
F_19 ( & V_128 -> V_99 , L_15 ) ;
return V_3 ;
}
V_35 -> V_93 . V_135 = L_16 ;
V_35 -> V_93 . V_136 = F_8 ;
V_35 -> V_93 . V_137 = V_138 ;
V_35 -> V_93 . V_139 = F_31 ( V_138 ) ;
V_3 = F_12 ( V_35 , & V_35 -> V_93 . type ) ;
if ( V_3 )
return - V_73 ;
V_130 . V_102 = V_128 -> V_99 . V_102 ;
V_130 . V_140 = V_35 ;
V_35 -> V_56 = F_32 ( & V_128 -> V_99 ,
& V_35 -> V_93 ,
& V_130 ) ;
if ( F_22 ( V_35 -> V_56 ) ) {
F_19 ( & V_128 -> V_99 , L_17 ) ;
return F_23 ( V_35 -> V_56 ) ;
}
F_33 ( V_128 , V_35 ) ;
F_34 ( & V_35 -> V_92 , F_13 ) ;
V_3 = F_10 ( V_35 ) ;
if ( V_3 )
return - V_141 ;
V_35 -> V_96 = true ;
return 0 ;
}
static int F_35 ( struct V_127 * V_128 )
{
struct V_34 * V_35 = F_36 ( V_128 ) ;
V_35 -> V_96 = false ;
F_37 ( & V_35 -> V_92 ) ;
return 0 ;
}
