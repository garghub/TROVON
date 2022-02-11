static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_1 )
{
int V_4 ;
V_4 = F_4 ( V_1 -> V_5 ) ;
if ( V_4 < 0 ) {
F_5 ( V_1 -> V_6 , L_1 ) ;
return V_4 ;
}
V_4 = F_4 ( V_1 -> V_7 ) ;
if ( V_4 ) {
F_5 ( V_1 -> V_6 , L_2 ) ;
goto V_8;
}
V_4 = F_4 ( V_1 -> V_9 ) ;
if ( V_4 ) {
F_5 ( V_1 -> V_6 , L_3 ) ;
goto V_10;
}
return 0 ;
V_10:
F_6 ( V_1 -> V_7 ) ;
V_8:
F_6 ( V_1 -> V_5 ) ;
return V_4 ;
}
static void F_7 ( struct V_1 * V_1 )
{
int V_4 ;
V_4 = F_6 ( V_1 -> V_9 ) ;
if ( V_4 < 0 )
F_5 ( V_1 -> V_6 , L_4 ) ;
V_4 = F_6 ( V_1 -> V_7 ) ;
if ( V_4 < 0 )
F_5 ( V_1 -> V_6 , L_5 ) ;
V_4 = F_6 ( V_1 -> V_5 ) ;
if ( V_4 < 0 )
F_5 ( V_1 -> V_6 , L_6 ) ;
}
static int F_8 ( struct V_1 * V_1 , T_1 V_11 , T_2 V_12 )
{
T_2 V_13 [ 3 ] ;
int V_4 ;
V_13 [ 0 ] = V_11 >> 8 ;
V_13 [ 1 ] = V_11 & 0xff ;
V_13 [ 2 ] = V_12 ;
V_4 = F_9 ( V_1 -> V_14 , V_13 , 3 ) ;
if ( V_4 < 0 )
F_5 ( V_1 -> V_6 , L_7 ,
V_15 , V_4 , V_11 , V_12 ) ;
return V_4 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_11 , T_2 * V_12 )
{
T_2 V_13 [ 2 ] ;
int V_4 ;
V_13 [ 0 ] = V_11 >> 8 ;
V_13 [ 1 ] = V_11 & 0xff ;
V_4 = F_9 ( V_1 -> V_14 , V_13 , 2 ) ;
if ( V_4 < 0 ) {
F_5 ( V_1 -> V_6 , L_8 ,
V_15 , V_4 , V_11 ) ;
return V_4 ;
}
V_4 = F_11 ( V_1 -> V_14 , V_12 , 1 ) ;
if ( V_4 < 0 ) {
F_5 ( V_1 -> V_6 , L_9 ,
V_15 , V_4 , V_11 ) ;
return V_4 ;
}
return 0 ;
}
static int F_12 ( struct V_1 * V_1 , T_3 V_16 )
{
T_2 V_12 = V_1 -> V_17 ;
int V_4 ;
if ( V_16 == V_18 )
V_12 &= ~ V_19 ;
else
V_12 |= V_19 ;
V_4 = F_8 ( V_1 , V_20 , V_12 ) ;
if ( ! V_4 )
V_1 -> V_17 = V_12 ;
return V_4 ;
}
static int F_13 ( struct V_1 * V_1 , T_3 V_21 )
{
T_2 V_12 = V_1 -> V_17 ;
int V_4 ;
if ( V_21 )
V_12 &= ~ V_22 ;
else
V_12 |= V_22 ;
V_4 = F_8 ( V_1 , V_20 , V_12 ) ;
if ( ! V_4 )
V_1 -> V_17 = V_12 ;
return V_4 ;
}
static int F_14 ( struct V_1 * V_1 ,
const struct V_23 * V_24 ,
unsigned int V_25 )
{
unsigned int V_26 ;
int V_4 ;
for ( V_26 = 0 ; V_26 < V_25 ; ++ V_26 , ++ V_24 ) {
V_4 = F_8 ( V_1 , V_24 -> V_11 , V_24 -> V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_1 )
{
int V_4 ;
V_4 = F_3 ( V_1 ) ;
if ( V_4 < 0 ) {
return V_4 ;
}
V_4 = F_16 ( V_1 -> V_27 ) ;
if ( V_4 < 0 ) {
F_5 ( V_1 -> V_6 , L_10 ) ;
F_7 ( V_1 ) ;
return V_4 ;
}
F_17 ( 5000 , 15000 ) ;
F_18 ( V_1 -> V_28 , 1 ) ;
F_17 ( 1000 , 2000 ) ;
F_18 ( V_1 -> V_29 , 0 ) ;
F_19 ( 20 ) ;
return 0 ;
}
static void F_20 ( struct V_1 * V_1 )
{
F_18 ( V_1 -> V_29 , 1 ) ;
F_18 ( V_1 -> V_28 , 0 ) ;
F_21 ( V_1 -> V_27 ) ;
F_7 ( V_1 ) ;
}
static int F_22 ( struct V_2 * V_3 , int V_30 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
int V_4 = 0 ;
F_23 ( & V_1 -> V_31 ) ;
if ( V_1 -> V_32 == ! V_30 ) {
if ( V_30 ) {
V_4 = F_15 ( V_1 ) ;
if ( V_4 < 0 )
goto exit;
V_4 = F_14 ( V_1 ,
V_33 ,
F_24 ( V_33 ) ) ;
if ( V_4 < 0 ) {
F_5 ( V_1 -> V_6 ,
L_11 ) ;
F_20 ( V_1 ) ;
goto exit;
}
V_4 = F_8 ( V_1 , V_34 ,
V_35 ) ;
if ( V_4 < 0 ) {
F_20 ( V_1 ) ;
goto exit;
}
} else {
F_20 ( V_1 ) ;
}
}
V_1 -> V_32 += V_30 ? 1 : - 1 ;
F_25 ( V_1 -> V_32 < 0 ) ;
exit:
F_26 ( & V_1 -> V_31 ) ;
return V_4 ;
}
static int F_27 ( struct V_1 * V_1 , T_4 V_36 )
{
T_3 V_23 = ( V_36 * 0x10 ) + 0x40 ;
int V_4 ;
V_4 = F_8 ( V_1 , V_37 , V_23 ) ;
if ( V_4 < 0 )
return V_4 ;
return F_8 ( V_1 , V_38 , V_23 ) ;
}
static int F_28 ( struct V_1 * V_1 , T_4 V_36 )
{
T_2 V_12 = V_1 -> V_39 ;
int V_4 ;
if ( V_36 == 0 )
V_12 &= ~ ( V_40 ) ;
else
V_12 |= ( V_40 ) ;
V_4 = F_8 ( V_1 , V_41 , V_12 ) ;
if ( ! V_4 )
V_1 -> V_39 = V_12 ;
return V_4 ;
}
static int F_29 ( struct V_1 * V_1 , T_4 V_36 )
{
T_2 V_12 = V_1 -> V_42 ;
int V_4 ;
if ( V_36 == 0 )
V_12 |= ( V_43 | V_44 ) ;
else
V_12 &= ~ ( V_43 | V_44 ) ;
V_4 = F_8 ( V_1 , V_45 , V_12 ) ;
if ( ! V_4 )
V_1 -> V_42 = V_12 ;
return V_4 ;
}
static int F_30 ( struct V_1 * V_1 , T_4 V_36 )
{
T_2 V_12 = 0 ;
if ( V_36 ) {
V_12 = F_31 ( V_36 - 1 ) ;
V_12 |= V_46 ;
}
return F_8 ( V_1 , V_47 , V_12 ) ;
}
static int F_32 ( struct V_1 * V_1 , T_4 V_48 )
{
T_2 V_12 = 0 ;
if ( ! V_48 )
V_12 = V_49 ;
return F_8 ( V_1 , V_50 , V_12 ) ;
}
static int F_33 ( struct V_51 * V_52 )
{
struct V_1 * V_1 = F_2 ( V_52 -> V_53 ,
struct V_1 , V_54 ) ;
int V_4 ;
F_23 ( & V_1 -> V_31 ) ;
if ( ! V_1 -> V_32 ) {
F_26 ( & V_1 -> V_31 ) ;
return 0 ;
}
switch ( V_52 -> V_55 ) {
case V_56 :
V_4 = F_27 ( V_1 , V_52 -> V_12 ) ;
break;
case V_57 :
V_4 = F_32 ( V_1 , V_52 -> V_12 ) ;
break;
case V_58 :
V_4 = F_13 ( V_1 , V_52 -> V_12 ) ;
break;
case V_59 :
V_4 = F_12 ( V_1 , V_52 -> V_12 ) ;
break;
case V_60 :
V_4 = F_30 ( V_1 , V_52 -> V_12 ) ;
break;
case V_61 :
V_4 = F_28 ( V_1 , V_52 -> V_12 ) ;
break;
case V_62 :
V_4 = F_29 ( V_1 , V_52 -> V_12 ) ;
break;
default:
V_4 = - V_63 ;
break;
}
F_26 ( & V_1 -> V_31 ) ;
return V_4 ;
}
static int F_34 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_66 * V_67 )
{
if ( V_67 -> V_68 > 0 )
return - V_63 ;
V_67 -> V_67 = V_69 ;
return 0 ;
}
static int F_35 ( struct V_2 * V_70 ,
struct V_64 * V_65 ,
struct V_71 * V_72 )
{
if ( V_72 -> V_67 != V_69 )
return - V_63 ;
if ( V_72 -> V_68 >= F_24 ( V_73 ) )
return - V_63 ;
V_72 -> V_74 = V_73 [ V_72 -> V_68 ] . V_75 ;
V_72 -> V_76 = V_73 [ V_72 -> V_68 ] . V_75 ;
V_72 -> V_77 = V_73 [ V_72 -> V_68 ] . V_78 ;
V_72 -> V_79 = V_73 [ V_72 -> V_68 ] . V_78 ;
return 0 ;
}
static struct V_80 *
F_36 ( struct V_1 * V_1 ,
struct V_64 * V_65 ,
unsigned int V_81 ,
enum V_82 V_83 )
{
switch ( V_83 ) {
case V_84 :
return F_37 ( & V_1 -> V_3 , V_65 , V_81 ) ;
case V_85 :
return & V_1 -> V_86 ;
default:
return NULL ;
}
}
static int F_38 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_87 * V_88 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
V_88 -> V_88 = * F_36 ( V_1 , V_65 , V_88 -> V_81 ,
V_88 -> V_83 ) ;
return 0 ;
}
static struct V_89 *
F_39 ( struct V_1 * V_1 , struct V_64 * V_65 ,
unsigned int V_81 , enum V_82 V_83 )
{
switch ( V_83 ) {
case V_84 :
return F_40 ( & V_1 -> V_3 , V_65 , V_81 ) ;
case V_85 :
return & V_1 -> V_90 ;
default:
return NULL ;
}
}
static const struct V_91 *
F_41 ( unsigned int V_75 , unsigned int V_78 )
{
int V_26 ;
for ( V_26 = F_24 ( V_73 ) - 1 ; V_26 >= 0 ; V_26 -- ) {
if ( V_73 [ V_26 ] . V_75 <= V_75 &&
V_73 [ V_26 ] . V_78 <= V_78 )
break;
}
if ( V_26 < 0 )
V_26 = 0 ;
return & V_73 [ V_26 ] ;
}
static int F_42 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_87 * V_88 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_80 * V_92 ;
struct V_89 * V_93 ;
const struct V_91 * V_94 ;
V_93 = F_39 ( V_1 , V_65 , V_88 -> V_81 ,
V_88 -> V_83 ) ;
V_94 = F_41 ( V_88 -> V_88 . V_75 ,
V_88 -> V_88 . V_78 ) ;
V_93 -> V_75 = V_94 -> V_75 ;
V_93 -> V_78 = V_94 -> V_78 ;
if ( V_88 -> V_83 == V_85 )
V_1 -> V_95 = V_94 ;
V_92 = F_36 ( V_1 , V_65 , V_88 -> V_81 ,
V_88 -> V_83 ) ;
V_92 -> V_75 = V_93 -> V_75 ;
V_92 -> V_78 = V_93 -> V_78 ;
V_92 -> V_67 = V_69 ;
V_92 -> V_96 = V_97 ;
V_92 -> V_98 = V_99 ;
V_88 -> V_88 = * V_92 ;
return 0 ;
}
static int F_43 ( struct V_2 * V_70 ,
struct V_64 * V_65 )
{
struct V_87 V_86 = { 0 } ;
V_86 . V_83 = V_65 ? V_84 : V_85 ;
V_86 . V_88 . V_75 = 1920 ;
V_86 . V_88 . V_78 = 1080 ;
F_42 ( V_70 , V_65 , & V_86 ) ;
return 0 ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_100 * V_101 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
if ( V_101 -> V_102 != V_103 )
return - V_63 ;
V_101 -> V_104 = * F_39 ( V_1 , V_65 , V_101 -> V_81 ,
V_101 -> V_83 ) ;
return 0 ;
}
static int F_45 ( struct V_2 * V_70 , int V_21 )
{
struct V_1 * V_1 = F_1 ( V_70 ) ;
int V_4 ;
if ( V_21 ) {
V_4 = F_14 ( V_1 ,
V_1 -> V_95 -> V_105 ,
V_1 -> V_95 -> V_106 ) ;
if ( V_4 < 0 ) {
F_5 ( V_1 -> V_6 , L_12 ,
V_1 -> V_95 -> V_75 ,
V_1 -> V_95 -> V_78 ) ;
return V_4 ;
}
V_4 = F_46 ( & V_1 -> V_54 ) ;
if ( V_4 < 0 ) {
F_5 ( V_1 -> V_6 , L_13 ) ;
return V_4 ;
}
V_4 = F_8 ( V_1 , V_34 ,
V_107 ) ;
if ( V_4 < 0 )
return V_4 ;
} else {
V_4 = F_8 ( V_1 , V_34 ,
V_35 ) ;
if ( V_4 < 0 )
return V_4 ;
}
return 0 ;
}
static int F_47 ( struct V_14 * V_108 ,
const struct V_109 * V_55 )
{
struct V_110 * V_6 = & V_108 -> V_6 ;
struct V_111 * V_112 ;
struct V_1 * V_1 ;
T_2 V_113 , V_114 ;
T_3 V_115 ;
int V_4 ;
V_1 = F_48 ( V_6 , sizeof( struct V_1 ) , V_116 ) ;
if ( ! V_1 )
return - V_117 ;
V_1 -> V_14 = V_108 ;
V_1 -> V_6 = V_6 ;
V_112 = F_49 ( V_6 -> V_118 , NULL ) ;
if ( ! V_112 ) {
F_5 ( V_6 , L_14 ) ;
return - V_63 ;
}
V_4 = F_50 ( F_51 ( V_112 ) ,
& V_1 -> V_119 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_15 ) ;
return V_4 ;
}
F_52 ( V_112 ) ;
if ( V_1 -> V_119 . V_120 != V_121 ) {
F_5 ( V_6 , L_16 ) ;
return - V_63 ;
}
V_1 -> V_27 = F_53 ( V_6 , L_17 ) ;
if ( F_54 ( V_1 -> V_27 ) ) {
F_5 ( V_6 , L_18 ) ;
return F_55 ( V_1 -> V_27 ) ;
}
V_4 = F_56 ( V_6 -> V_118 , L_19 , & V_115 ) ;
if ( V_4 ) {
F_5 ( V_6 , L_20 ) ;
return V_4 ;
}
if ( V_115 != 23880000 ) {
F_5 ( V_6 , L_21 ,
V_115 ) ;
return - V_63 ;
}
V_4 = F_57 ( V_1 -> V_27 , V_115 ) ;
if ( V_4 ) {
F_5 ( V_6 , L_22 ) ;
return V_4 ;
}
V_1 -> V_5 = F_58 ( V_6 , L_23 ) ;
if ( F_54 ( V_1 -> V_5 ) ) {
F_5 ( V_6 , L_24 ) ;
return F_55 ( V_1 -> V_5 ) ;
}
V_4 = F_59 ( V_1 -> V_5 ,
V_122 ,
V_122 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_25 ) ;
return V_4 ;
}
V_1 -> V_9 = F_58 ( V_6 , L_26 ) ;
if ( F_54 ( V_1 -> V_9 ) ) {
F_5 ( V_6 , L_27 ) ;
return F_55 ( V_1 -> V_9 ) ;
}
V_4 = F_59 ( V_1 -> V_9 ,
V_123 ,
V_123 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_28 ) ;
return V_4 ;
}
V_1 -> V_7 = F_58 ( V_6 , L_29 ) ;
if ( F_54 ( V_1 -> V_7 ) ) {
F_5 ( V_6 , L_30 ) ;
return F_55 ( V_1 -> V_7 ) ;
}
V_4 = F_59 ( V_1 -> V_7 ,
V_124 ,
V_124 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_31 ) ;
return V_4 ;
}
V_1 -> V_28 = F_60 ( V_6 , L_32 , V_125 ) ;
if ( F_54 ( V_1 -> V_28 ) ) {
F_5 ( V_6 , L_33 ) ;
return F_55 ( V_1 -> V_28 ) ;
}
V_1 -> V_29 = F_60 ( V_6 , L_34 , V_125 ) ;
if ( F_54 ( V_1 -> V_29 ) ) {
F_5 ( V_6 , L_35 ) ;
return F_55 ( V_1 -> V_29 ) ;
}
F_61 ( & V_1 -> V_31 ) ;
F_62 ( & V_1 -> V_54 , 7 ) ;
F_63 ( & V_1 -> V_54 , & V_126 ,
V_56 , - 4 , 4 , 1 , 0 ) ;
F_63 ( & V_1 -> V_54 , & V_126 ,
V_61 , 0 , 1 , 1 , 0 ) ;
F_63 ( & V_1 -> V_54 , & V_126 ,
V_62 , 0 , 1 , 1 , 0 ) ;
F_63 ( & V_1 -> V_54 , & V_126 ,
V_58 , 0 , 1 , 1 , 1 ) ;
F_63 ( & V_1 -> V_54 , & V_126 ,
V_57 , 0 , 1 , 1 , 1 ) ;
F_64 ( & V_1 -> V_54 , & V_126 ,
V_59 , V_127 ,
0 , V_18 ) ;
F_65 ( & V_1 -> V_54 , & V_126 ,
V_60 ,
F_24 ( V_128 ) - 1 ,
0 , 0 , V_128 ) ;
V_1 -> V_3 . V_129 = & V_1 -> V_54 ;
if ( V_1 -> V_54 . error ) {
F_5 ( V_6 , L_36 ,
V_15 , V_1 -> V_54 . error ) ;
V_4 = V_1 -> V_54 . error ;
goto V_130;
}
F_66 ( & V_1 -> V_3 , V_108 , & V_131 ) ;
V_1 -> V_3 . V_132 |= V_133 ;
V_1 -> V_81 . V_132 = V_134 ;
V_1 -> V_3 . V_6 = & V_108 -> V_6 ;
V_4 = F_67 ( & V_1 -> V_3 . V_135 , 1 , & V_1 -> V_81 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_37 ) ;
goto V_130;
}
V_4 = F_22 ( & V_1 -> V_3 , true ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_38 ) ;
goto V_136;
}
V_4 = F_10 ( V_1 , V_137 , & V_113 ) ;
if ( V_4 < 0 || V_113 != V_138 ) {
F_5 ( V_6 , L_39 ) ;
V_4 = - V_139 ;
goto V_140;
}
V_4 = F_10 ( V_1 , V_141 , & V_114 ) ;
if ( V_4 < 0 || V_114 != V_142 ) {
F_5 ( V_6 , L_40 ) ;
V_4 = - V_139 ;
goto V_140;
}
F_68 ( V_6 , L_41 , V_108 -> V_143 ) ;
V_4 = F_10 ( V_1 , V_20 ,
& V_1 -> V_17 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_42 ) ;
V_4 = - V_139 ;
goto V_140;
}
V_4 = F_10 ( V_1 , V_45 ,
& V_1 -> V_42 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_43 ) ;
V_4 = - V_139 ;
goto V_140;
}
V_4 = F_10 ( V_1 , V_41 ,
& V_1 -> V_39 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_44 ) ;
V_4 = - V_139 ;
goto V_140;
}
F_22 ( & V_1 -> V_3 , false ) ;
V_4 = F_69 ( & V_1 -> V_3 ) ;
if ( V_4 < 0 ) {
F_5 ( V_6 , L_45 ) ;
goto V_136;
}
F_43 ( & V_1 -> V_3 , NULL ) ;
return 0 ;
V_140:
F_22 ( & V_1 -> V_3 , false ) ;
V_136:
F_70 ( & V_1 -> V_3 . V_135 ) ;
V_130:
F_71 ( & V_1 -> V_54 ) ;
F_72 ( & V_1 -> V_31 ) ;
return V_4 ;
}
static int F_73 ( struct V_14 * V_108 )
{
struct V_2 * V_3 = F_74 ( V_108 ) ;
struct V_1 * V_1 = F_1 ( V_3 ) ;
F_75 ( & V_1 -> V_3 ) ;
F_70 ( & V_1 -> V_3 . V_135 ) ;
F_71 ( & V_1 -> V_54 ) ;
F_72 ( & V_1 -> V_31 ) ;
return 0 ;
}
