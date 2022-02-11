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
static void F_12 ( struct V_2 * V_3 ,
struct V_24 * V_25 , bool V_26 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_28 * V_29 ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
if ( V_3 -> V_7 == V_31 )
V_29 = V_25 -> V_32 ;
else
V_29 = V_25 -> V_33 ;
if ( V_29 -> V_34 && V_26 )
V_30 -> V_35 ++ ;
else if ( V_29 -> V_34 && ! V_26 )
V_30 -> V_35 -- ;
}
static int F_15 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_7 ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_36 * V_37 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_7 = F_17 ( V_12 , V_3 ,
F_11 ( V_12 ) ) ;
if ( V_7 == NULL )
return - V_40 ;
F_8 ( V_12 , V_4 ) ;
if ( V_3 -> V_7 == V_41 ) {
V_4 -> V_42 . V_43 &= ~ V_44 ;
V_4 -> V_42 . V_43 &= ~ V_45 ;
}
V_4 -> V_5 = V_7 ;
V_37 = F_18 ( sizeof( * V_37 ) , V_46 ) ;
if ( ! V_37 )
return - V_47 ;
V_37 -> V_48 = V_8 ( V_7 ) -> V_48 ;
F_19 ( V_25 , V_3 , V_37 ) ;
F_16 ( V_25 -> V_27 , L_2 ,
V_37 -> V_48 ) ;
F_12 ( V_3 , V_25 , true ) ;
F_20 ( V_3 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
int V_16 = 0 ;
if ( V_12 -> V_21 ) {
struct V_17 * V_4 = V_3 -> V_4 ;
V_16 = F_23 ( V_4 -> V_51 ,
V_4 -> V_52 ,
V_4 -> V_53 ,
32 , 0 ) ;
} else {
struct V_24 * V_54 = V_50 -> V_54 ;
V_37 = F_24 ( V_54 , V_3 ) ;
if ( V_37 )
V_16 = V_37 -> V_53 ;
}
return V_16 ;
}
static int F_25 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_16 ;
int V_55 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_16 = F_21 ( V_3 , V_25 ) ;
F_16 ( V_25 -> V_27 , L_3 ,
V_8 ( V_7 ) -> V_48 , V_16 ) ;
F_26 ( V_8 ( V_7 ) ) ;
V_55 = F_27 ( V_8 ( V_7 ) , V_16 ) ;
if ( V_55 < 0 )
return V_55 ;
V_55 = F_28 ( V_8 ( V_7 ) ) ;
if ( V_55 < 0 )
return V_55 ;
V_8 ( V_7 ) -> V_56 = 1 ;
return V_55 ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_57 * V_58 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_59 V_60 = { 0 } ;
struct V_61 * V_62 ;
int V_63 , V_64 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_63 = F_4 ( V_12 , V_3 ,
F_30 ( V_58 ) ) ;
if ( V_63 < 0 )
return V_63 ;
F_16 ( V_25 -> V_27 , L_4 ,
V_4 -> V_51 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_64 = V_8 ( V_7 ) -> V_48 - 1 ;
F_16 ( V_25 -> V_27 , L_5 , V_64 ) ;
V_60 . V_65 = F_31 ( F_32 ( V_58 ) ) ;
V_60 . V_66 = F_33 ( V_58 ) ;
V_60 . V_67 = F_34 ( V_58 ) ;
V_60 . V_68 = V_64 ;
V_60 . V_7 = V_3 -> V_7 ;
V_62 = F_35 ( V_25 , V_60 . V_7 ) ;
if ( V_62 )
F_36 ( V_25 -> V_27 , V_62 , & V_60 ) ;
return 0 ;
}
static void F_37 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_36 * V_37 = NULL ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
F_38 ( V_7 , F_11 ( V_12 ) ) ;
V_37 = F_24 ( V_25 , V_3 ) ;
F_19 ( V_25 , V_3 , NULL ) ;
F_12 ( V_3 , V_25 , false ) ;
if ( ! strncmp ( V_25 -> V_39 , L_6 , 13 ) &&
V_30 -> V_69 -> V_70 ) {
V_30 -> V_69 -> V_71 ( V_25 -> V_27 , true ) ;
V_30 -> V_69 -> V_70 = false ;
}
F_39 ( V_37 ) ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
F_41 ( V_8 ( V_7 ) ) ;
V_8 ( V_7 ) -> V_56 = 0 ;
return F_6 ( F_42 ( V_12 ) , V_3 ) ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_57 * V_58 ,
struct V_24 * V_25 )
{
struct V_59 V_60 = { 0 } ;
V_60 . V_65 = F_31 ( F_32 ( V_58 ) ) ;
V_60 . V_66 = F_33 ( V_58 ) ;
V_60 . V_67 = F_34 ( V_58 ) ;
V_60 . V_7 = V_3 -> V_7 ;
return F_44 ( V_25 , & V_60 ) ;
}
static int F_45 ( struct V_2 * V_3 ,
int V_72 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_42 ( V_12 ) ;
struct V_1 * V_7 ;
int V_73 ;
unsigned long V_74 ;
struct V_8 * V_75 ;
V_7 = F_1 ( V_3 ) ;
V_75 = V_8 ( V_7 ) ;
if ( ! V_75 -> V_56 )
return - V_76 ;
switch ( V_72 ) {
case V_77 :
case V_78 :
case V_79 :
V_73 = 1 ;
break;
case V_80 :
case V_81 :
case V_82 :
V_73 = 0 ;
break;
default:
return - V_83 ;
}
F_46 ( & V_11 -> V_84 , V_74 ) ;
if ( V_73 ) {
F_47 ( V_8 ( V_7 ) , true ) ;
F_48 ( V_75 , 0 ) ;
} else {
F_49 ( V_8 ( V_7 ) ) ;
}
F_50 ( & V_11 -> V_84 , V_74 ) ;
return 0 ;
}
static int F_51 ( struct V_2 * V_3 , int V_72 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_52 ( V_25 -> V_27 ) ;
struct V_69 * V_85 = V_30 -> V_69 ;
struct V_61 * V_86 ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_63 ;
V_86 = F_35 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_86 )
return - V_87 ;
switch ( V_72 ) {
case V_79 :
F_25 ( V_3 , V_25 ) ;
F_53 ( V_12 , true ,
V_8 ( V_7 ) -> V_88 ) ;
F_54 ( V_12 , V_7 , V_7 -> V_89 ) ;
F_55 ( V_7 , V_7 -> V_90 ) ;
case V_77 :
case V_78 :
F_56 ( V_12 , V_7 , true ) ;
V_63 = F_45 ( V_3 , V_72 ) ;
if ( V_63 < 0 )
return V_63 ;
return F_57 ( V_85 , V_86 -> V_91 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
V_63 = F_58 ( V_85 , V_86 -> V_91 ) ;
if ( V_63 < 0 )
return V_63 ;
V_63 = F_45 ( V_3 , V_72 ) ;
if ( V_72 == V_81 ) {
V_7 -> V_89 = F_59 ( V_12 -> V_11 . V_92 +
V_93 +
( V_94 *
V_8 ( V_7 ) -> V_88 ) ) ;
V_7 -> V_90 = F_60 (
V_8 ( V_7 ) ) ;
F_56 ( V_12 , V_7 , false ) ;
}
break;
default:
return - V_83 ;
}
return 0 ;
}
static int F_61 ( struct V_2 * V_3 ,
struct V_57 * V_58 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_95 ;
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_36 * V_37 ;
struct V_24 * V_54 = V_50 -> V_54 ;
struct V_59 V_60 = { 0 } ;
V_95 = F_17 ( V_12 , V_3 ,
V_96 ) ;
if ( ! V_95 )
return - V_40 ;
F_19 ( V_25 , V_3 , ( void * ) V_95 ) ;
V_37 = (struct V_36 * )
F_24 ( V_54 , V_3 ) ;
if ( V_37 )
V_37 -> V_48 = V_8 ( V_95 ) -> V_48 ;
F_19 ( V_54 , V_3 , ( void * ) V_37 ) ;
V_60 . V_65 = F_31 ( F_32 ( V_58 ) ) ;
V_60 . V_66 = F_33 ( V_58 ) ;
V_60 . V_67 = F_34 ( V_58 ) ;
V_60 . V_7 = V_3 -> V_7 ;
V_60 . V_97 = V_8 ( V_95 ) -> V_48 - 1 ;
return F_44 ( V_25 , & V_60 ) ;
}
static int F_62 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_95 =
F_24 ( V_25 , V_3 ) ;
unsigned int V_16 = 0 ;
struct V_36 * V_37 ;
struct V_24 * V_54 = V_50 -> V_54 ;
struct V_98 * V_99 ;
V_37 = (struct V_36 * )
F_24 ( V_54 , V_3 ) ;
if ( V_37 )
V_16 = V_37 -> V_53 ;
F_16 ( V_25 -> V_27 , L_7 ,
V_8 ( V_95 ) -> V_48 , V_16 , V_54 -> V_39 ) ;
V_99 = F_63 ( V_12 , V_50 -> V_100 -> V_101 . V_39 ) ;
if ( ! V_99 )
return - V_83 ;
F_64 ( V_99 ) ;
F_65 ( V_95 ) ;
F_66 ( V_95 , V_16 ) ;
F_67 ( V_99 , V_8 ( V_95 ) -> V_48 ) ;
V_95 -> V_102 = 1 ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
int V_72 , struct V_24 * V_25 )
{
struct V_1 * V_95 =
F_24 ( V_25 , V_3 ) ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_16 ( V_25 -> V_27 , L_8 , V_38 , V_72 ) ;
switch ( V_72 ) {
case V_79 :
F_62 ( V_3 , V_25 ) ;
case V_77 :
case V_78 :
F_56 ( V_12 , V_7 , true ) ;
F_69 ( V_95 ) ;
break;
case V_80 :
case V_81 :
case V_82 :
F_70 ( V_95 ) ;
if ( V_72 == V_81 )
F_56 ( V_12 , V_7 , false ) ;
break;
default:
return - V_83 ;
}
return 0 ;
}
static int F_71 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_1 * V_95 =
F_24 ( V_25 , V_3 ) ;
struct V_98 * V_99 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_95 -> V_102 = 0 ;
V_99 = F_63 ( V_12 , V_50 -> V_100 -> V_101 . V_39 ) ;
if ( ! V_99 )
return - V_83 ;
F_72 ( V_99 , V_8 ( V_95 ) -> V_48 ) ;
F_38 ( V_95 , V_96 ) ;
return 0 ;
}
static int F_73 ( struct V_2 * V_3 )
{
struct V_17 * V_4 ;
struct V_49 * V_50 = V_3 -> V_5 ;
struct V_103 * V_104 = V_50 -> V_104 ;
F_16 ( V_50 -> V_105 -> V_27 , L_9 , V_38 ,
V_104 -> V_106 ) ;
V_4 = V_3 -> V_4 ;
F_74 ( V_3 , & V_107 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 ,
int V_72 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_42 ( V_12 ) ;
struct V_1 * V_7 ;
struct V_2 * V_108 ;
bool V_73 ;
int V_109 = 0 ;
unsigned long V_74 ;
struct V_8 * V_75 ;
V_7 = F_1 ( V_3 ) ;
V_75 = V_8 ( V_7 ) ;
F_16 ( V_11 -> V_27 , L_8 , V_38 , V_72 ) ;
if ( ! V_75 -> V_56 )
return - V_76 ;
switch ( V_72 ) {
case V_77 :
case V_78 :
case V_79 :
V_73 = true ;
break;
case V_80 :
case V_81 :
case V_82 :
V_73 = false ;
break;
default:
return - V_83 ;
}
F_76 (s, substream) {
if ( V_108 -> V_110 -> V_111 != V_3 -> V_110 -> V_111 )
continue;
V_7 = F_1 ( V_108 ) ;
V_109 |= 1 << V_8 ( V_7 ) -> V_88 ;
F_77 ( V_108 , V_3 ) ;
}
F_46 ( & V_11 -> V_84 , V_74 ) ;
F_78 ( V_75 , true , V_109 , V_112 ) ;
F_76 (s, substream) {
if ( V_108 -> V_110 -> V_111 != V_3 -> V_110 -> V_111 )
continue;
V_7 = F_1 ( V_108 ) ;
if ( V_73 )
F_47 ( V_8 ( V_7 ) , true ) ;
else
F_49 ( V_8 ( V_7 ) ) ;
}
F_50 ( & V_11 -> V_84 , V_74 ) ;
F_79 ( V_75 , V_73 , V_109 ) ;
F_46 ( & V_11 -> V_84 , V_74 ) ;
F_78 ( V_75 , false , V_109 , V_112 ) ;
if ( V_73 )
F_48 ( V_75 , V_109 ) ;
F_50 ( & V_11 -> V_84 , V_74 ) ;
return 0 ;
}
static int F_80 ( struct V_2 * V_3 ,
int V_72 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
if ( ! V_12 -> V_21 )
return F_75 ( V_3 , V_72 ) ;
return 0 ;
}
static int F_81 ( struct V_6 * V_12 ,
struct V_1 * V_113 ,
unsigned int V_114 )
{
struct V_10 * V_11 = F_42 ( V_12 ) ;
struct V_8 * V_9 = V_8 ( V_113 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
int V_7 = V_3 -> V_7 ;
unsigned int V_115 = F_60 ( V_9 ) ;
int V_116 ;
if ( V_7 == V_31 )
V_116 = V_114 - V_115 ;
else
V_116 = V_115 - V_114 ;
if ( V_116 < 0 ) {
if ( V_116 >= V_9 -> V_117 )
V_116 = 0 ;
else
V_116 += V_9 -> V_14 ;
}
V_116 = ( V_9 -> V_14 == V_116 ) ? 0 : V_116 ;
if ( V_116 >= V_9 -> V_15 ) {
F_82 ( V_11 -> V_27 ,
L_10 ,
V_116 , V_9 -> V_15 ) ;
V_116 = 0 ;
}
return F_83 ( V_3 -> V_4 , V_116 ) ;
}
static unsigned int F_84 ( struct V_1 * V_9 ,
int V_118 )
{
struct V_8 * V_75 = V_8 ( V_9 ) ;
struct V_2 * V_3 = V_75 -> V_3 ;
struct V_6 * V_12 ;
unsigned int V_114 ;
int V_116 ;
V_114 = F_85 ( V_8 ( V_9 ) ) ;
if ( V_114 >= V_8 ( V_9 ) -> V_14 )
V_114 = 0 ;
if ( V_3 -> V_4 ) {
V_12 = F_2 ( V_3 ) ;
V_116 = F_81 ( V_12 , V_9 , V_114 )
+ V_118 ;
V_3 -> V_4 -> V_116 += V_116 ;
}
return V_114 ;
}
static T_2 F_86
( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_83 ( V_3 -> V_4 ,
F_84 ( V_9 , 0 ) ) ;
}
static T_3 F_87 ( struct V_2 * V_3 ,
T_3 V_119 )
{
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_24 * V_54 = V_50 -> V_54 ;
T_3 V_120 , V_121 ;
if ( ! V_54 -> V_122 -> V_123 -> V_116 )
return V_119 ;
V_120 = V_54 -> V_122 -> V_123 -> V_116 ( V_3 , V_54 ) ;
V_121 = F_88 ( V_120 * 1000000000LL ,
V_3 -> V_4 -> V_51 ) ;
if ( V_3 -> V_7 == V_41 )
return V_119 + V_121 ;
return ( V_119 > V_121 ) ? V_119 - V_121 : 0 ;
}
static int F_89 ( struct V_2 * V_3 ,
struct V_124 * V_125 , struct V_124 * V_126 ,
struct V_127 * V_128 ,
struct V_129 * V_130 )
{
struct V_1 * V_113 = F_1 ( V_3 ) ;
struct V_8 * V_75 = V_8 ( V_113 ) ;
T_3 V_119 ;
if ( ( V_3 -> V_4 -> V_42 . V_43 & V_45 ) &&
( V_128 -> V_131 == V_132 ) ) {
F_90 ( V_3 -> V_4 , V_125 ) ;
V_119 = F_91 ( & V_75 -> V_133 ) ;
V_119 = F_88 ( V_119 , 3 ) ;
if ( V_128 -> V_134 )
V_119 = F_87 ( V_3 , V_119 ) ;
* V_126 = F_92 ( V_119 ) ;
V_130 -> V_135 = V_132 ;
V_130 -> V_136 = 1 ;
V_130 -> V_137 = 42 ;
} else {
V_130 -> V_135 = V_138 ;
}
return 0 ;
}
static void F_93 ( struct V_139 * V_110 )
{
F_94 ( V_110 ) ;
}
static int F_95 ( struct V_49 * V_50 )
{
struct V_24 * V_25 = V_50 -> V_105 ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_139 * V_110 = V_50 -> V_110 ;
unsigned int V_13 ;
int V_140 = 0 ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
if ( V_25 -> V_122 -> V_141 . V_142 ||
V_25 -> V_122 -> V_143 . V_142 ) {
V_13 = V_144 * 1024 ;
if ( V_13 > V_145 )
V_13 = V_145 ;
V_140 = F_96 ( V_110 ,
V_146 ,
F_97 ( V_30 -> V_147 ) ,
V_13 , V_145 ) ;
if ( V_140 ) {
F_98 ( V_25 -> V_27 , L_11 ) ;
return V_140 ;
}
}
return V_140 ;
}
static int F_99 ( struct V_148 * V_149 )
{
struct V_6 * V_12 = F_13 ( V_149 -> V_27 ) ;
if ( V_12 -> V_21 )
return F_100 ( V_149 , V_12 ) ;
return 0 ;
}
int F_101 ( struct V_150 * V_27 )
{
int V_63 ;
struct V_6 * V_12 = F_13 ( V_27 ) ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
F_102 ( & V_30 -> V_151 ) ;
V_63 = F_103 ( V_27 , & V_152 ) ;
if ( V_63 ) {
F_98 ( V_27 , L_12 , V_63 ) ;
return V_63 ;
}
V_63 = F_104 ( V_27 , & V_153 ,
V_154 ,
F_105 ( V_154 ) ) ;
if ( V_63 ) {
F_98 ( V_27 , L_13 , V_63 ) ;
F_106 ( V_27 ) ;
}
return V_63 ;
}
int F_107 ( struct V_150 * V_27 )
{
F_108 ( V_27 ) ;
F_106 ( V_27 ) ;
return 0 ;
}
