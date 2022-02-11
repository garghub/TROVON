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
struct V_30 * V_30 = F_26 ( V_25 -> V_27 ) ;
struct V_55 * V_56 = V_30 -> V_55 ;
struct V_57 * V_58 ;
if ( V_25 -> V_32 -> V_59 || V_25 -> V_33 -> V_59 )
return 0 ;
V_58 = F_27 ( V_25 , V_3 -> V_7 ) ;
if ( V_58 == NULL )
return - V_60 ;
return F_28 ( V_56 , V_58 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_16 ;
int V_61 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_16 = F_21 ( V_3 , V_25 ) ;
F_16 ( V_25 -> V_27 , L_3 ,
V_8 ( V_7 ) -> V_48 , V_16 ) ;
F_30 ( V_8 ( V_7 ) ) ;
V_61 = F_31 ( V_8 ( V_7 ) , V_16 ) ;
if ( V_61 < 0 )
return V_61 ;
V_61 = F_32 ( V_8 ( V_7 ) ) ;
if ( V_61 < 0 )
return V_61 ;
V_8 ( V_7 ) -> V_62 = 1 ;
return V_61 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_63 * V_64 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_65 V_66 = { 0 } ;
struct V_57 * V_67 ;
int V_68 , V_69 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_68 = F_4 ( V_12 , V_3 ,
F_34 ( V_64 ) ) ;
if ( V_68 < 0 )
return V_68 ;
F_16 ( V_25 -> V_27 , L_4 ,
V_4 -> V_51 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_69 = V_8 ( V_7 ) -> V_48 - 1 ;
F_16 ( V_25 -> V_27 , L_5 , V_69 ) ;
V_66 . V_70 = F_35 ( F_36 ( V_64 ) ) ;
V_66 . V_71 = F_37 ( V_64 ) ;
V_66 . V_72 = F_38 ( V_64 ) ;
V_66 . V_73 = V_69 ;
V_66 . V_7 = V_3 -> V_7 ;
V_67 = F_39 ( V_25 , V_66 . V_7 ) ;
if ( V_67 )
F_40 ( V_25 -> V_27 , V_67 , & V_66 ) ;
return 0 ;
}
static void F_41 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_36 * V_37 = NULL ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
F_42 ( V_7 , F_11 ( V_12 ) ) ;
V_37 = F_24 ( V_25 , V_3 ) ;
F_19 ( V_25 , V_3 , NULL ) ;
F_12 ( V_3 , V_25 , false ) ;
if ( ! strncmp ( V_25 -> V_39 , L_6 , 13 ) &&
V_30 -> V_55 -> V_74 ) {
V_30 -> V_55 -> V_75 ( V_25 -> V_27 , true ) ;
V_30 -> V_55 -> V_74 = false ;
}
F_43 ( V_37 ) ;
}
static int F_44 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
F_45 ( V_8 ( V_7 ) ) ;
V_8 ( V_7 ) -> V_62 = 0 ;
return F_6 ( F_46 ( V_12 ) , V_3 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_63 * V_64 ,
struct V_24 * V_25 )
{
struct V_65 V_66 = { 0 } ;
V_66 . V_70 = F_35 ( F_36 ( V_64 ) ) ;
V_66 . V_71 = F_37 ( V_64 ) ;
V_66 . V_72 = F_38 ( V_64 ) ;
V_66 . V_7 = V_3 -> V_7 ;
return F_48 ( V_25 , & V_66 ) ;
}
static int F_49 ( struct V_2 * V_3 ,
int V_76 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_46 ( V_12 ) ;
struct V_1 * V_7 ;
int V_77 ;
unsigned long V_78 ;
struct V_8 * V_79 ;
V_7 = F_1 ( V_3 ) ;
V_79 = V_8 ( V_7 ) ;
if ( ! V_79 -> V_62 )
return - V_80 ;
switch ( V_76 ) {
case V_81 :
case V_82 :
case V_83 :
V_77 = 1 ;
break;
case V_84 :
case V_85 :
case V_86 :
V_77 = 0 ;
break;
default:
return - V_60 ;
}
F_50 ( & V_11 -> V_87 , V_78 ) ;
if ( V_77 ) {
F_51 ( V_8 ( V_7 ) , true ) ;
F_52 ( V_79 , 0 ) ;
} else {
F_53 ( V_8 ( V_7 ) ) ;
}
F_54 ( & V_11 -> V_87 , V_78 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , int V_76 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_26 ( V_25 -> V_27 ) ;
struct V_55 * V_56 = V_30 -> V_55 ;
struct V_57 * V_58 ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_28 * V_29 ;
int V_68 ;
V_58 = F_39 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_58 )
return - V_88 ;
if ( V_3 -> V_7 == V_31 )
V_29 = V_25 -> V_32 ;
else
V_29 = V_25 -> V_33 ;
switch ( V_76 ) {
case V_83 :
if ( ! V_29 -> V_34 ) {
F_29 ( V_3 , V_25 ) ;
F_56 ( V_12 , true ,
V_8 ( V_7 ) -> V_89 ) ;
F_57 ( V_12 , V_7 ,
V_7 -> V_90 ) ;
F_58 ( V_7 , V_7 -> V_91 ) ;
}
case V_81 :
case V_82 :
F_59 ( V_12 , V_7 , true ) ;
V_68 = F_49 ( V_3 , V_76 ) ;
if ( V_68 < 0 )
return V_68 ;
return F_60 ( V_56 , V_58 -> V_92 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
V_68 = F_61 ( V_56 , V_58 -> V_92 ) ;
if ( V_68 < 0 )
return V_68 ;
V_68 = F_49 ( V_3 , V_76 ) ;
if ( ( V_76 == V_85 ) && ! V_29 -> V_34 ) {
V_7 -> V_90 = F_62 ( V_12 -> V_11 . V_93 +
V_94 +
( V_95 *
V_8 ( V_7 ) -> V_89 ) ) ;
V_7 -> V_91 = F_63 (
V_8 ( V_7 ) ) ;
F_59 ( V_12 , V_7 , false ) ;
}
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_63 * V_64 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_96 ;
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_97 * V_37 ;
struct V_24 * V_54 = V_50 -> V_54 ;
struct V_65 V_66 = { 0 } ;
V_96 = F_17 ( V_12 , V_3 ,
V_98 ) ;
if ( ! V_96 )
return - V_40 ;
F_19 ( V_25 , V_3 , ( void * ) V_96 ) ;
V_37 = F_24 ( V_54 , V_3 ) ;
if ( V_37 )
V_37 -> V_48 = V_8 ( V_96 ) -> V_48 ;
V_66 . V_70 = F_35 ( F_36 ( V_64 ) ) ;
V_66 . V_71 = F_37 ( V_64 ) ;
V_66 . V_72 = F_38 ( V_64 ) ;
V_66 . V_7 = V_3 -> V_7 ;
V_66 . V_99 = V_8 ( V_96 ) -> V_48 - 1 ;
return F_48 ( V_25 , & V_66 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_96 =
F_24 ( V_25 , V_3 ) ;
unsigned int V_16 = 0 ;
struct V_36 * V_37 ;
struct V_24 * V_54 = V_50 -> V_54 ;
struct V_100 * V_101 ;
V_37 = (struct V_36 * )
F_24 ( V_54 , V_3 ) ;
if ( V_37 )
V_16 = V_37 -> V_53 ;
F_16 ( V_25 -> V_27 , L_7 ,
V_8 ( V_96 ) -> V_48 , V_16 , V_54 -> V_39 ) ;
V_101 = F_66 ( V_12 , V_50 -> V_102 -> V_103 . V_39 ) ;
if ( ! V_101 )
return - V_60 ;
F_67 ( V_96 ) ;
F_68 ( V_96 , V_16 ) ;
F_69 ( V_101 , V_8 ( V_96 ) -> V_48 ) ;
V_96 -> V_104 = 1 ;
return 0 ;
}
static int F_70 ( struct V_2 * V_3 ,
int V_76 , struct V_24 * V_25 )
{
struct V_1 * V_96 =
F_24 ( V_25 , V_3 ) ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_16 ( V_25 -> V_27 , L_8 , V_38 , V_76 ) ;
switch ( V_76 ) {
case V_83 :
F_65 ( V_3 , V_25 ) ;
case V_81 :
case V_82 :
F_59 ( V_12 , V_7 , true ) ;
F_71 ( V_96 ) ;
break;
case V_84 :
case V_85 :
case V_86 :
F_72 ( V_96 ) ;
if ( V_76 == V_85 )
F_59 ( V_12 , V_7 , false ) ;
break;
default:
return - V_60 ;
}
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_1 * V_96 =
F_24 ( V_25 , V_3 ) ;
struct V_100 * V_101 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_96 -> V_104 = 0 ;
V_101 = F_66 ( V_12 , V_50 -> V_102 -> V_103 . V_39 ) ;
if ( ! V_101 )
return - V_60 ;
F_74 ( V_101 , V_8 ( V_96 ) -> V_48 ) ;
F_42 ( V_96 , V_98 ) ;
return 0 ;
}
static int F_75 ( struct V_2 * V_3 )
{
struct V_17 * V_4 ;
struct V_49 * V_50 = V_3 -> V_5 ;
struct V_105 * V_106 = V_50 -> V_106 ;
F_16 ( V_50 -> V_107 -> V_27 , L_9 , V_38 ,
V_106 -> V_108 ) ;
V_4 = V_3 -> V_4 ;
F_76 ( V_3 , & V_109 ) ;
return 0 ;
}
static int F_77 ( struct V_2 * V_3 ,
int V_76 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_46 ( V_12 ) ;
struct V_1 * V_7 ;
struct V_2 * V_110 ;
bool V_77 ;
int V_111 = 0 ;
unsigned long V_78 ;
struct V_8 * V_79 ;
V_7 = F_1 ( V_3 ) ;
V_79 = V_8 ( V_7 ) ;
F_16 ( V_11 -> V_27 , L_8 , V_38 , V_76 ) ;
if ( ! V_79 -> V_62 )
return - V_80 ;
switch ( V_76 ) {
case V_81 :
case V_82 :
case V_83 :
V_77 = true ;
break;
case V_84 :
case V_85 :
case V_86 :
V_77 = false ;
break;
default:
return - V_60 ;
}
F_78 (s, substream) {
if ( V_110 -> V_112 -> V_113 != V_3 -> V_112 -> V_113 )
continue;
V_7 = F_1 ( V_110 ) ;
V_111 |= 1 << V_8 ( V_7 ) -> V_89 ;
F_79 ( V_110 , V_3 ) ;
}
F_50 ( & V_11 -> V_87 , V_78 ) ;
F_80 ( V_79 , true , V_111 , V_114 ) ;
F_78 (s, substream) {
if ( V_110 -> V_112 -> V_113 != V_3 -> V_112 -> V_113 )
continue;
V_7 = F_1 ( V_110 ) ;
if ( V_77 )
F_51 ( V_8 ( V_7 ) , true ) ;
else
F_53 ( V_8 ( V_7 ) ) ;
}
F_54 ( & V_11 -> V_87 , V_78 ) ;
F_81 ( V_79 , V_77 , V_111 ) ;
F_50 ( & V_11 -> V_87 , V_78 ) ;
F_80 ( V_79 , false , V_111 , V_114 ) ;
if ( V_77 )
F_52 ( V_79 , V_111 ) ;
F_54 ( & V_11 -> V_87 , V_78 ) ;
return 0 ;
}
static int F_82 ( struct V_2 * V_3 ,
int V_76 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
if ( ! V_12 -> V_21 )
return F_77 ( V_3 , V_76 ) ;
return 0 ;
}
static int F_83 ( struct V_6 * V_12 ,
struct V_1 * V_115 ,
unsigned int V_116 )
{
struct V_10 * V_11 = F_46 ( V_12 ) ;
struct V_8 * V_9 = V_8 ( V_115 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
int V_7 = V_3 -> V_7 ;
unsigned int V_117 = F_63 ( V_9 ) ;
int V_118 ;
if ( V_7 == V_31 )
V_118 = V_116 - V_117 ;
else
V_118 = V_117 - V_116 ;
if ( V_118 < 0 ) {
if ( V_118 >= V_9 -> V_119 )
V_118 = 0 ;
else
V_118 += V_9 -> V_14 ;
}
if ( V_9 -> V_14 == V_118 )
V_118 = 0 ;
if ( V_118 >= V_9 -> V_15 ) {
F_84 ( V_11 -> V_27 ,
L_10 ,
V_118 , V_9 -> V_15 ) ;
V_118 = 0 ;
}
return F_85 ( V_3 -> V_4 , V_118 ) ;
}
static unsigned int F_86 ( struct V_1 * V_9 ,
int V_120 )
{
struct V_8 * V_79 = V_8 ( V_9 ) ;
struct V_2 * V_3 = V_79 -> V_3 ;
struct V_6 * V_12 ;
unsigned int V_116 ;
int V_118 ;
V_116 = F_87 ( V_8 ( V_9 ) ) ;
if ( V_116 >= V_8 ( V_9 ) -> V_14 )
V_116 = 0 ;
if ( V_3 -> V_4 ) {
V_12 = F_2 ( V_3 ) ;
V_118 = F_83 ( V_12 , V_9 , V_116 )
+ V_120 ;
V_3 -> V_4 -> V_118 += V_118 ;
}
return V_116 ;
}
static T_2 F_88
( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_85 ( V_3 -> V_4 ,
F_86 ( V_9 , 0 ) ) ;
}
static T_3 F_89 ( struct V_2 * V_3 ,
T_3 V_121 )
{
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_24 * V_54 = V_50 -> V_54 ;
T_3 V_122 , V_123 ;
if ( ! V_54 -> V_124 -> V_125 -> V_118 )
return V_121 ;
V_122 = V_54 -> V_124 -> V_125 -> V_118 ( V_3 , V_54 ) ;
V_123 = F_90 ( V_122 * 1000000000LL ,
V_3 -> V_4 -> V_51 ) ;
if ( V_3 -> V_7 == V_41 )
return V_121 + V_123 ;
return ( V_121 > V_123 ) ? V_121 - V_123 : 0 ;
}
static int F_91 ( struct V_2 * V_3 ,
struct V_126 * V_127 , struct V_126 * V_128 ,
struct V_129 * V_130 ,
struct V_131 * V_132 )
{
struct V_1 * V_115 = F_1 ( V_3 ) ;
struct V_8 * V_79 = V_8 ( V_115 ) ;
T_3 V_121 ;
if ( ( V_3 -> V_4 -> V_42 . V_43 & V_45 ) &&
( V_130 -> V_133 == V_134 ) ) {
F_92 ( V_3 -> V_4 , V_127 ) ;
V_121 = F_93 ( & V_79 -> V_135 ) ;
V_121 = F_90 ( V_121 , 3 ) ;
if ( V_130 -> V_136 )
V_121 = F_89 ( V_3 , V_121 ) ;
* V_128 = F_94 ( V_121 ) ;
V_132 -> V_137 = V_134 ;
V_132 -> V_138 = 1 ;
V_132 -> V_139 = 42 ;
} else {
V_132 -> V_137 = V_140 ;
}
return 0 ;
}
static void F_95 ( struct V_141 * V_112 )
{
F_96 ( V_112 ) ;
}
static int F_97 ( struct V_49 * V_50 )
{
struct V_24 * V_25 = V_50 -> V_107 ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_141 * V_112 = V_50 -> V_112 ;
unsigned int V_13 ;
int V_142 = 0 ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
if ( V_25 -> V_124 -> V_143 . V_144 ||
V_25 -> V_124 -> V_145 . V_144 ) {
V_13 = V_146 * 1024 ;
if ( V_13 > V_147 )
V_13 = V_147 ;
V_142 = F_98 ( V_112 ,
V_148 ,
F_99 ( V_30 -> V_149 ) ,
V_13 , V_147 ) ;
if ( V_142 ) {
F_100 ( V_25 -> V_27 , L_11 ) ;
return V_142 ;
}
}
return V_142 ;
}
static int F_101 ( struct V_150 * V_151 )
{
struct V_6 * V_12 = F_13 ( V_151 -> V_27 ) ;
if ( V_12 -> V_21 )
return F_102 ( V_151 , V_12 ) ;
return 0 ;
}
int F_103 ( struct V_152 * V_27 )
{
int V_68 ;
struct V_6 * V_12 = F_13 ( V_27 ) ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
F_104 ( & V_30 -> V_153 ) ;
V_68 = F_105 ( V_27 , & V_154 ) ;
if ( V_68 ) {
F_100 ( V_27 , L_12 , V_68 ) ;
return V_68 ;
}
V_68 = F_106 ( V_27 , & V_155 ,
V_156 ,
F_107 ( V_156 ) ) ;
if ( V_68 ) {
F_100 ( V_27 , L_13 , V_68 ) ;
F_108 ( V_27 ) ;
}
return V_68 ;
}
int F_109 ( struct V_152 * V_27 )
{
F_110 ( V_27 ) ;
F_108 ( V_27 ) ;
return 0 ;
}
