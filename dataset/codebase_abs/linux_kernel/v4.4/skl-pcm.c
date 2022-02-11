static inline
struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 -> V_5 ;
}
static struct V_6 * F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_8 * V_9 = V_8 ( V_7 ) ;
struct V_10 * V_11 = V_9 -> V_11 ;
return F_3 ( V_11 ) ;
}
static int F_4 ( struct V_6 * V_12 ,
struct V_2 * V_3 ,
T_1 V_13 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
V_8 ( V_7 ) -> V_14 = 0 ;
V_8 ( V_7 ) -> V_15 = 0 ;
V_8 ( V_7 ) -> V_16 = 0 ;
return F_5 ( V_3 , V_13 ) ;
}
static int F_6 ( struct V_10 * V_11 ,
struct V_2 * V_3 )
{
return F_7 ( V_3 ) ;
}
static void F_8 ( struct V_6 * V_12 ,
struct V_17 * V_4 )
{
F_9 ( V_4 , V_18 ) ;
F_10 ( V_4 , V_19 ,
20 , 178000000 ) ;
}
static enum V_20 F_11 ( struct V_6 * V_12 )
{
if ( V_12 -> V_21 )
return V_22 ;
else
return V_23 ;
}
static int F_12 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_7 ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_27 * V_28 ;
int V_29 ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
V_29 = F_15 ( V_25 -> V_26 ) ;
if ( V_29 < 0 )
return V_29 ;
V_7 = F_16 ( V_12 , V_3 ,
F_11 ( V_12 ) ) ;
if ( V_7 == NULL )
return - V_32 ;
F_8 ( V_12 , V_4 ) ;
if ( V_3 -> V_7 == V_33 ) {
V_4 -> V_34 . V_35 &= ~ V_36 ;
V_4 -> V_34 . V_35 &= ~ V_37 ;
}
V_4 -> V_5 = V_7 ;
V_28 = F_17 ( sizeof( * V_28 ) , V_38 ) ;
if ( ! V_28 )
return - V_39 ;
V_28 -> V_40 = V_8 ( V_7 ) -> V_40 ;
F_18 ( V_25 , V_3 , V_28 ) ;
F_14 ( V_25 -> V_26 , L_2 ,
V_28 -> V_40 ) ;
F_19 ( V_3 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_27 * V_28 ;
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
int V_16 = 0 ;
if ( V_12 -> V_21 ) {
struct V_17 * V_4 = V_3 -> V_4 ;
V_16 = F_22 ( V_4 -> V_43 ,
V_4 -> V_44 ,
V_4 -> V_45 ,
32 , 0 ) ;
} else {
struct V_24 * V_46 = V_42 -> V_46 ;
V_28 = F_23 ( V_46 , V_3 ) ;
if ( V_28 )
V_16 = V_28 -> V_45 ;
}
return V_16 ;
}
static int F_24 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_16 ;
int V_47 ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
if ( V_8 ( V_7 ) -> V_48 ) {
F_14 ( V_25 -> V_26 , L_3 ) ;
return 0 ;
}
V_16 = F_20 ( V_3 , V_25 ) ;
F_14 ( V_25 -> V_26 , L_4 ,
V_8 ( V_7 ) -> V_40 , V_16 ) ;
F_25 ( V_8 ( V_7 ) ) ;
V_47 = F_26 ( V_8 ( V_7 ) , V_16 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_27 ( V_8 ( V_7 ) ) ;
if ( V_47 < 0 )
return V_47 ;
V_8 ( V_7 ) -> V_48 = 1 ;
return V_47 ;
}
static int F_28 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_51 V_52 = { 0 } ;
struct V_53 * V_54 ;
int V_29 , V_55 ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
V_29 = F_4 ( V_12 , V_3 ,
F_29 ( V_50 ) ) ;
if ( V_29 < 0 )
return V_29 ;
F_14 ( V_25 -> V_26 , L_5 ,
V_4 -> V_43 , V_4 -> V_44 , V_4 -> V_45 ) ;
V_55 = V_8 ( V_7 ) -> V_40 - 1 ;
F_14 ( V_25 -> V_26 , L_6 , V_55 ) ;
V_52 . V_56 = F_30 ( F_31 ( V_50 ) ) ;
V_52 . V_57 = F_32 ( V_50 ) ;
V_52 . V_58 = F_33 ( V_50 ) ;
V_52 . V_59 = V_55 ;
V_52 . V_7 = V_3 -> V_7 ;
V_54 = F_34 ( V_25 , V_52 . V_7 ) ;
if ( V_54 )
F_35 ( V_25 -> V_26 , V_54 , & V_52 ) ;
return 0 ;
}
static void F_36 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_27 * V_28 = NULL ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
F_37 ( V_7 , F_11 ( V_12 ) ) ;
V_28 = F_23 ( V_25 , V_3 ) ;
F_18 ( V_25 , V_3 , NULL ) ;
F_38 ( V_25 -> V_26 ) ;
F_39 ( V_25 -> V_26 ) ;
F_40 ( V_28 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
F_42 ( V_8 ( V_7 ) ) ;
V_8 ( V_7 ) -> V_48 = 0 ;
return F_6 ( F_43 ( V_12 ) , V_3 ) ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_24 * V_25 )
{
struct V_51 V_52 = { 0 } ;
V_52 . V_56 = F_30 ( F_31 ( V_50 ) ) ;
V_52 . V_57 = F_32 ( V_50 ) ;
V_52 . V_58 = F_33 ( V_50 ) ;
V_52 . V_7 = V_3 -> V_7 ;
F_45 ( V_25 , & V_52 ) ;
return 0 ;
}
static int F_46 ( struct V_2 * V_3 , int V_60 ,
struct V_24 * V_25 )
{
struct V_61 * V_61 = F_47 ( V_25 -> V_26 ) ;
struct V_62 * V_63 = V_61 -> V_62 ;
struct V_53 * V_64 ;
V_64 = F_34 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_64 )
return - V_65 ;
switch ( V_60 ) {
case V_66 :
case V_67 :
return F_48 ( V_63 , V_64 -> V_68 ) ;
case V_69 :
case V_70 :
return F_49 ( V_63 , V_64 -> V_68 ) ;
default:
return 0 ;
}
}
static int F_50 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_71 ;
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_27 * V_28 ;
struct V_24 * V_46 = V_42 -> V_46 ;
struct V_51 V_52 = { 0 } ;
V_71 = F_16 ( V_12 , V_3 ,
V_72 ) ;
if ( ! V_71 )
return - V_32 ;
F_18 ( V_25 , V_3 , ( void * ) V_71 ) ;
V_28 = (struct V_27 * )
F_23 ( V_46 , V_3 ) ;
if ( V_28 )
V_28 -> V_40 = V_8 ( V_71 ) -> V_40 ;
F_18 ( V_46 , V_3 , ( void * ) V_28 ) ;
V_52 . V_56 = F_30 ( F_31 ( V_50 ) ) ;
V_52 . V_57 = F_32 ( V_50 ) ;
V_52 . V_58 = F_33 ( V_50 ) ;
V_52 . V_7 = V_3 -> V_7 ;
V_52 . V_73 = V_8 ( V_71 ) -> V_40 - 1 ;
F_45 ( V_25 , & V_52 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_71 =
F_23 ( V_25 , V_3 ) ;
unsigned int V_16 = 0 ;
struct V_27 * V_28 ;
struct V_24 * V_46 = V_42 -> V_46 ;
struct V_74 * V_75 ;
if ( V_71 -> V_76 ) {
F_14 ( V_25 -> V_26 , L_3 ) ;
return 0 ;
}
V_28 = (struct V_27 * )
F_23 ( V_46 , V_3 ) ;
if ( V_28 )
V_16 = V_28 -> V_45 ;
F_14 ( V_25 -> V_26 , L_7 ,
V_8 ( V_71 ) -> V_40 , V_16 , V_46 -> V_31 ) ;
F_52 ( V_71 ) ;
F_53 ( V_71 , V_16 ) ;
V_75 = F_54 ( V_12 , V_42 -> V_77 -> V_78 . V_31 ) ;
if ( ! V_75 )
return - V_79 ;
F_55 ( V_75 , V_8 ( V_71 ) -> V_40 ) ;
V_71 -> V_76 = 1 ;
return 0 ;
}
static int F_56 ( struct V_2 * V_3 ,
int V_60 , struct V_24 * V_25 )
{
struct V_1 * V_71 =
F_23 ( V_25 , V_3 ) ;
F_14 ( V_25 -> V_26 , L_8 , V_30 , V_60 ) ;
switch ( V_60 ) {
case V_80 :
case V_66 :
case V_67 :
F_57 ( V_71 ) ;
break;
case V_69 :
case V_70 :
case V_81 :
F_58 ( V_71 ) ;
break;
default:
return - V_79 ;
}
return 0 ;
}
static int F_59 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_1 * V_71 =
F_23 ( V_25 , V_3 ) ;
struct V_74 * V_75 ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
V_71 -> V_76 = 0 ;
V_75 = F_54 ( V_12 , V_42 -> V_77 -> V_78 . V_31 ) ;
if ( ! V_75 )
return - V_79 ;
F_60 ( V_75 , V_8 ( V_71 ) -> V_40 ) ;
F_37 ( V_71 , V_72 ) ;
return 0 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
return F_15 ( V_25 -> V_26 ) ;
}
static void F_62 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
F_38 ( V_25 -> V_26 ) ;
F_39 ( V_25 -> V_26 ) ;
}
static int F_63 ( struct V_2 * V_3 )
{
struct V_17 * V_4 ;
struct V_41 * V_42 = V_3 -> V_5 ;
struct V_82 * V_83 = V_42 -> V_83 ;
F_14 ( V_42 -> V_84 -> V_26 , L_9 , V_30 ,
V_83 -> V_85 ) ;
V_4 = V_3 -> V_4 ;
F_64 ( V_3 , & V_86 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 ,
int V_60 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_43 ( V_12 ) ;
struct V_1 * V_7 ;
struct V_2 * V_87 ;
bool V_88 ;
int V_89 = 0 ;
unsigned long V_90 ;
struct V_8 * V_91 ;
V_7 = F_1 ( V_3 ) ;
V_91 = V_8 ( V_7 ) ;
F_14 ( V_11 -> V_26 , L_8 , V_30 , V_60 ) ;
if ( ! V_91 -> V_48 )
return - V_92 ;
switch ( V_60 ) {
case V_80 :
case V_66 :
case V_67 :
V_88 = true ;
break;
case V_69 :
case V_70 :
case V_81 :
V_88 = false ;
break;
default:
return - V_79 ;
}
F_66 (s, substream) {
if ( V_87 -> V_93 -> V_94 != V_3 -> V_93 -> V_94 )
continue;
V_7 = F_1 ( V_87 ) ;
V_89 |= 1 << V_8 ( V_7 ) -> V_95 ;
F_67 ( V_87 , V_3 ) ;
}
F_68 ( & V_11 -> V_96 , V_90 ) ;
F_69 ( V_91 , true , V_89 , V_97 ) ;
F_66 (s, substream) {
if ( V_87 -> V_93 -> V_94 != V_3 -> V_93 -> V_94 )
continue;
V_7 = F_1 ( V_87 ) ;
if ( V_88 )
F_70 ( V_8 ( V_7 ) , true ) ;
else
F_71 ( V_8 ( V_7 ) ) ;
}
F_72 ( & V_11 -> V_96 , V_90 ) ;
F_73 ( V_91 , V_88 , V_89 ) ;
F_68 ( & V_11 -> V_96 , V_90 ) ;
F_69 ( V_91 , false , V_89 , V_97 ) ;
if ( V_88 )
F_74 ( V_91 , V_89 ) ;
F_72 ( & V_11 -> V_96 , V_90 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
int V_60 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_43 ( V_12 ) ;
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_24 * V_84 = V_42 -> V_84 ;
struct V_1 * V_7 ;
int V_88 ;
unsigned long V_90 ;
struct V_8 * V_91 ;
F_14 ( V_11 -> V_26 , L_10 , V_30 , V_60 , V_84 -> V_31 ) ;
V_7 = F_1 ( V_3 ) ;
V_91 = V_8 ( V_7 ) ;
if ( ! V_91 -> V_48 )
return - V_92 ;
switch ( V_60 ) {
case V_80 :
case V_66 :
case V_67 :
V_88 = 1 ;
break;
case V_69 :
case V_70 :
case V_81 :
V_88 = 0 ;
break;
default:
return - V_79 ;
}
F_68 ( & V_11 -> V_96 , V_90 ) ;
if ( V_88 )
F_70 ( V_8 ( V_7 ) , true ) ;
else
F_71 ( V_8 ( V_7 ) ) ;
if ( V_88 )
F_74 ( V_91 , 0 ) ;
F_72 ( & V_11 -> V_96 , V_90 ) ;
return 0 ;
}
static int F_76 ( struct V_2 * V_3 ,
int V_60 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
if ( V_12 -> V_21 )
return F_75 ( V_3 , V_60 ) ;
else
return F_65 ( V_3 , V_60 ) ;
}
static int F_77 ( struct V_6 * V_12 ,
struct V_1 * V_98 ,
unsigned int V_99 )
{
struct V_10 * V_11 = F_43 ( V_12 ) ;
struct V_8 * V_9 = V_8 ( V_98 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
int V_7 = V_3 -> V_7 ;
unsigned int V_100 = F_78 ( V_9 ) ;
int V_101 ;
if ( V_7 == V_102 )
V_101 = V_99 - V_100 ;
else
V_101 = V_100 - V_99 ;
if ( V_101 < 0 ) {
if ( V_101 >= V_9 -> V_103 )
V_101 = 0 ;
else
V_101 += V_9 -> V_14 ;
}
if ( V_101 >= V_9 -> V_15 ) {
F_79 ( V_11 -> V_26 ,
L_11 ,
V_101 , V_9 -> V_15 ) ;
V_101 = 0 ;
}
return F_80 ( V_3 -> V_4 , V_101 ) ;
}
static unsigned int F_81 ( struct V_1 * V_9 ,
int V_104 )
{
struct V_8 * V_91 = V_8 ( V_9 ) ;
struct V_2 * V_3 = V_91 -> V_3 ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
unsigned int V_99 ;
int V_101 ;
V_99 = F_82 ( V_8 ( V_9 ) ) ;
if ( V_99 >= V_8 ( V_9 ) -> V_14 )
V_99 = 0 ;
if ( V_3 -> V_4 ) {
V_101 = F_77 ( V_12 , V_9 , V_99 )
+ V_104 ;
V_3 -> V_4 -> V_101 += V_101 ;
}
return V_99 ;
}
static T_2 F_83
( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_80 ( V_3 -> V_4 ,
F_81 ( V_9 , 0 ) ) ;
}
static T_3 F_84 ( struct V_2 * V_3 ,
T_3 V_105 )
{
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_24 * V_46 = V_42 -> V_46 ;
T_3 V_106 , V_107 ;
if ( ! V_46 -> V_108 -> V_109 -> V_101 )
return V_105 ;
V_106 = V_46 -> V_108 -> V_109 -> V_101 ( V_3 , V_46 ) ;
V_107 = F_85 ( V_106 * 1000000000LL ,
V_3 -> V_4 -> V_43 ) ;
if ( V_3 -> V_7 == V_33 )
return V_105 + V_107 ;
return ( V_105 > V_107 ) ? V_105 - V_107 : 0 ;
}
static int F_86 ( struct V_2 * V_3 ,
struct V_110 * V_111 , struct V_110 * V_112 ,
struct V_113 * V_114 ,
struct V_115 * V_116 )
{
struct V_1 * V_98 = F_1 ( V_3 ) ;
struct V_8 * V_91 = V_8 ( V_98 ) ;
T_3 V_105 ;
if ( ( V_3 -> V_4 -> V_34 . V_35 & V_37 ) &&
( V_114 -> V_117 == V_118 ) ) {
F_87 ( V_3 -> V_4 , V_111 ) ;
V_105 = F_88 ( & V_91 -> V_119 ) ;
V_105 = F_85 ( V_105 , 3 ) ;
if ( V_114 -> V_120 )
V_105 = F_84 ( V_3 , V_105 ) ;
* V_112 = F_89 ( V_105 ) ;
V_116 -> V_121 = V_118 ;
V_116 -> V_122 = 1 ;
V_116 -> V_123 = 42 ;
} else {
V_116 -> V_121 = V_124 ;
}
return 0 ;
}
static void F_90 ( struct V_125 * V_93 )
{
F_91 ( V_93 ) ;
}
static int F_92 ( struct V_41 * V_42 )
{
struct V_24 * V_25 = V_42 -> V_84 ;
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_125 * V_93 = V_42 -> V_93 ;
unsigned int V_13 ;
int V_126 = 0 ;
struct V_61 * V_61 = F_93 ( V_12 ) ;
if ( V_25 -> V_108 -> V_127 . V_128 ||
V_25 -> V_108 -> V_129 . V_128 ) {
V_13 = V_130 * 1024 ;
if ( V_13 > V_131 )
V_13 = V_131 ;
V_126 = F_94 ( V_93 ,
V_132 ,
F_95 ( V_61 -> V_133 ) ,
V_13 , V_131 ) ;
if ( V_126 ) {
F_96 ( V_25 -> V_26 , L_12 ) ;
return V_126 ;
}
}
return V_126 ;
}
static int F_97 ( struct V_134 * V_135 )
{
struct V_6 * V_12 = F_13 ( V_135 -> V_26 ) ;
if ( V_12 -> V_21 )
return F_98 ( V_135 , V_12 ) ;
return 0 ;
}
int F_99 ( struct V_136 * V_26 )
{
int V_29 ;
struct V_6 * V_12 = F_13 ( V_26 ) ;
struct V_61 * V_61 = F_93 ( V_12 ) ;
F_100 ( & V_61 -> V_137 ) ;
F_100 ( & V_61 -> V_138 ) ;
V_29 = F_101 ( V_26 , & V_139 ) ;
if ( V_29 ) {
F_96 ( V_26 , L_13 , V_29 ) ;
return V_29 ;
}
V_29 = F_102 ( V_26 , & V_140 ,
V_141 ,
F_103 ( V_141 ) ) ;
if ( V_29 ) {
F_96 ( V_26 , L_14 , V_29 ) ;
F_104 ( V_26 ) ;
}
return V_29 ;
}
int F_105 ( struct V_136 * V_26 )
{
F_106 ( V_26 ) ;
F_104 ( V_26 ) ;
return 0 ;
}
