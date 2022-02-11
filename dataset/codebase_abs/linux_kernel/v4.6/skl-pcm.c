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
if ( ( V_25 -> V_59 > 1 ) || ( V_25 -> V_60 > 1 ) )
return 0 ;
V_58 = F_27 ( V_25 , V_3 -> V_7 ) ;
if ( V_58 == NULL )
return - V_61 ;
return F_28 ( V_56 , V_58 ) ;
}
static int F_29 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned int V_16 ;
int V_62 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_16 = F_21 ( V_3 , V_25 ) ;
F_16 ( V_25 -> V_27 , L_3 ,
V_8 ( V_7 ) -> V_48 , V_16 ) ;
F_30 ( V_8 ( V_7 ) ) ;
V_62 = F_31 ( V_8 ( V_7 ) , V_16 ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_32 ( V_8 ( V_7 ) ) ;
if ( V_62 < 0 )
return V_62 ;
V_8 ( V_7 ) -> V_63 = 1 ;
return V_62 ;
}
static int F_33 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_66 V_67 = { 0 } ;
struct V_57 * V_68 ;
int V_69 , V_70 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_69 = F_4 ( V_12 , V_3 ,
F_34 ( V_65 ) ) ;
if ( V_69 < 0 )
return V_69 ;
F_16 ( V_25 -> V_27 , L_4 ,
V_4 -> V_51 , V_4 -> V_52 , V_4 -> V_53 ) ;
V_70 = V_8 ( V_7 ) -> V_48 - 1 ;
F_16 ( V_25 -> V_27 , L_5 , V_70 ) ;
V_67 . V_71 = F_35 ( F_36 ( V_65 ) ) ;
V_67 . V_72 = F_37 ( V_65 ) ;
V_67 . V_73 = F_38 ( V_65 ) ;
V_67 . V_74 = V_70 ;
V_67 . V_7 = V_3 -> V_7 ;
V_68 = F_39 ( V_25 , V_67 . V_7 ) ;
if ( V_68 )
F_40 ( V_25 -> V_27 , V_68 , & V_67 ) ;
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
V_30 -> V_55 -> V_75 ) {
V_30 -> V_55 -> V_76 ( V_25 -> V_27 , true ) ;
V_30 -> V_55 -> V_75 = false ;
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
V_8 ( V_7 ) -> V_63 = 0 ;
return F_6 ( F_46 ( V_12 ) , V_3 ) ;
}
static int F_47 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_24 * V_25 )
{
struct V_66 V_67 = { 0 } ;
V_67 . V_71 = F_35 ( F_36 ( V_65 ) ) ;
V_67 . V_72 = F_37 ( V_65 ) ;
V_67 . V_73 = F_38 ( V_65 ) ;
V_67 . V_7 = V_3 -> V_7 ;
return F_48 ( V_25 , & V_67 ) ;
}
static int F_49 ( struct V_2 * V_3 ,
int V_77 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_46 ( V_12 ) ;
struct V_1 * V_7 ;
int V_78 ;
unsigned long V_79 ;
struct V_8 * V_80 ;
V_7 = F_1 ( V_3 ) ;
V_80 = V_8 ( V_7 ) ;
if ( ! V_80 -> V_63 )
return - V_81 ;
switch ( V_77 ) {
case V_82 :
case V_83 :
case V_84 :
V_78 = 1 ;
break;
case V_85 :
case V_86 :
case V_87 :
V_78 = 0 ;
break;
default:
return - V_61 ;
}
F_50 ( & V_11 -> V_88 , V_79 ) ;
if ( V_78 ) {
F_51 ( V_8 ( V_7 ) , true ) ;
F_52 ( V_80 , 0 ) ;
} else {
F_53 ( V_8 ( V_7 ) ) ;
}
F_54 ( & V_11 -> V_88 , V_79 ) ;
return 0 ;
}
static int F_55 ( struct V_2 * V_3 , int V_77 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_26 ( V_25 -> V_27 ) ;
struct V_55 * V_56 = V_30 -> V_55 ;
struct V_57 * V_58 ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
int V_69 ;
V_58 = F_39 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_58 )
return - V_89 ;
switch ( V_77 ) {
case V_84 :
F_29 ( V_3 , V_25 ) ;
F_56 ( V_12 , true ,
V_8 ( V_7 ) -> V_90 ) ;
F_57 ( V_12 , V_7 , V_7 -> V_91 ) ;
F_58 ( V_7 , V_7 -> V_92 ) ;
case V_82 :
case V_83 :
F_59 ( V_12 , V_7 , true ) ;
V_69 = F_49 ( V_3 , V_77 ) ;
if ( V_69 < 0 )
return V_69 ;
return F_60 ( V_56 , V_58 -> V_93 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
V_69 = F_61 ( V_56 , V_58 -> V_93 ) ;
if ( V_69 < 0 )
return V_69 ;
V_69 = F_49 ( V_3 , V_77 ) ;
if ( V_77 == V_86 ) {
V_7 -> V_91 = F_62 ( V_12 -> V_11 . V_94 +
V_95 +
( V_96 *
V_8 ( V_7 ) -> V_90 ) ) ;
V_7 -> V_92 = F_63 (
V_8 ( V_7 ) ) ;
F_59 ( V_12 , V_7 , false ) ;
}
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_64 ( struct V_2 * V_3 ,
struct V_64 * V_65 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_97 ;
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_98 * V_37 ;
struct V_24 * V_54 = V_50 -> V_54 ;
struct V_66 V_67 = { 0 } ;
V_97 = F_17 ( V_12 , V_3 ,
V_99 ) ;
if ( ! V_97 )
return - V_40 ;
F_19 ( V_25 , V_3 , ( void * ) V_97 ) ;
V_37 = F_24 ( V_54 , V_3 ) ;
if ( V_37 )
V_37 -> V_48 = V_8 ( V_97 ) -> V_48 ;
V_67 . V_71 = F_35 ( F_36 ( V_65 ) ) ;
V_67 . V_72 = F_37 ( V_65 ) ;
V_67 . V_73 = F_38 ( V_65 ) ;
V_67 . V_7 = V_3 -> V_7 ;
V_67 . V_100 = V_8 ( V_97 ) -> V_48 - 1 ;
return F_48 ( V_25 , & V_67 ) ;
}
static int F_65 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_1 * V_97 =
F_24 ( V_25 , V_3 ) ;
unsigned int V_16 = 0 ;
struct V_36 * V_37 ;
struct V_24 * V_54 = V_50 -> V_54 ;
struct V_101 * V_102 ;
V_37 = (struct V_36 * )
F_24 ( V_54 , V_3 ) ;
if ( V_37 )
V_16 = V_37 -> V_53 ;
F_16 ( V_25 -> V_27 , L_7 ,
V_8 ( V_97 ) -> V_48 , V_16 , V_54 -> V_39 ) ;
V_102 = F_66 ( V_12 , V_50 -> V_103 -> V_104 . V_39 ) ;
if ( ! V_102 )
return - V_61 ;
F_67 ( V_102 ) ;
F_68 ( V_97 ) ;
F_69 ( V_97 , V_16 ) ;
F_70 ( V_102 , V_8 ( V_97 ) -> V_48 ) ;
V_97 -> V_105 = 1 ;
return 0 ;
}
static int F_71 ( struct V_2 * V_3 ,
int V_77 , struct V_24 * V_25 )
{
struct V_1 * V_97 =
F_24 ( V_25 , V_3 ) ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_16 ( V_25 -> V_27 , L_8 , V_38 , V_77 ) ;
switch ( V_77 ) {
case V_84 :
F_65 ( V_3 , V_25 ) ;
case V_82 :
case V_83 :
F_59 ( V_12 , V_7 , true ) ;
F_72 ( V_97 ) ;
break;
case V_85 :
case V_86 :
case V_87 :
F_73 ( V_97 ) ;
if ( V_77 == V_86 )
F_59 ( V_12 , V_7 , false ) ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_1 * V_97 =
F_24 ( V_25 , V_3 ) ;
struct V_101 * V_102 ;
F_16 ( V_25 -> V_27 , L_1 , V_38 , V_25 -> V_39 ) ;
V_97 -> V_105 = 0 ;
V_102 = F_66 ( V_12 , V_50 -> V_103 -> V_104 . V_39 ) ;
if ( ! V_102 )
return - V_61 ;
F_75 ( V_102 , V_8 ( V_97 ) -> V_48 ) ;
F_42 ( V_97 , V_99 ) ;
return 0 ;
}
static int F_76 ( struct V_2 * V_3 )
{
struct V_17 * V_4 ;
struct V_49 * V_50 = V_3 -> V_5 ;
struct V_106 * V_107 = V_50 -> V_107 ;
F_16 ( V_50 -> V_108 -> V_27 , L_9 , V_38 ,
V_107 -> V_109 ) ;
V_4 = V_3 -> V_4 ;
F_77 ( V_3 , & V_110 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 ,
int V_77 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_46 ( V_12 ) ;
struct V_1 * V_7 ;
struct V_2 * V_111 ;
bool V_78 ;
int V_112 = 0 ;
unsigned long V_79 ;
struct V_8 * V_80 ;
V_7 = F_1 ( V_3 ) ;
V_80 = V_8 ( V_7 ) ;
F_16 ( V_11 -> V_27 , L_8 , V_38 , V_77 ) ;
if ( ! V_80 -> V_63 )
return - V_81 ;
switch ( V_77 ) {
case V_82 :
case V_83 :
case V_84 :
V_78 = true ;
break;
case V_85 :
case V_86 :
case V_87 :
V_78 = false ;
break;
default:
return - V_61 ;
}
F_79 (s, substream) {
if ( V_111 -> V_113 -> V_114 != V_3 -> V_113 -> V_114 )
continue;
V_7 = F_1 ( V_111 ) ;
V_112 |= 1 << V_8 ( V_7 ) -> V_90 ;
F_80 ( V_111 , V_3 ) ;
}
F_50 ( & V_11 -> V_88 , V_79 ) ;
F_81 ( V_80 , true , V_112 , V_115 ) ;
F_79 (s, substream) {
if ( V_111 -> V_113 -> V_114 != V_3 -> V_113 -> V_114 )
continue;
V_7 = F_1 ( V_111 ) ;
if ( V_78 )
F_51 ( V_8 ( V_7 ) , true ) ;
else
F_53 ( V_8 ( V_7 ) ) ;
}
F_54 ( & V_11 -> V_88 , V_79 ) ;
F_82 ( V_80 , V_78 , V_112 ) ;
F_50 ( & V_11 -> V_88 , V_79 ) ;
F_81 ( V_80 , false , V_112 , V_115 ) ;
if ( V_78 )
F_52 ( V_80 , V_112 ) ;
F_54 ( & V_11 -> V_88 , V_79 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 ,
int V_77 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
if ( ! V_12 -> V_21 )
return F_78 ( V_3 , V_77 ) ;
return 0 ;
}
static int F_84 ( struct V_6 * V_12 ,
struct V_1 * V_116 ,
unsigned int V_117 )
{
struct V_10 * V_11 = F_46 ( V_12 ) ;
struct V_8 * V_9 = V_8 ( V_116 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
int V_7 = V_3 -> V_7 ;
unsigned int V_118 = F_63 ( V_9 ) ;
int V_119 ;
if ( V_7 == V_31 )
V_119 = V_117 - V_118 ;
else
V_119 = V_118 - V_117 ;
if ( V_119 < 0 ) {
if ( V_119 >= V_9 -> V_120 )
V_119 = 0 ;
else
V_119 += V_9 -> V_14 ;
}
if ( V_9 -> V_14 == V_119 )
V_119 = 0 ;
if ( V_119 >= V_9 -> V_15 ) {
F_85 ( V_11 -> V_27 ,
L_10 ,
V_119 , V_9 -> V_15 ) ;
V_119 = 0 ;
}
return F_86 ( V_3 -> V_4 , V_119 ) ;
}
static unsigned int F_87 ( struct V_1 * V_9 ,
int V_121 )
{
struct V_8 * V_80 = V_8 ( V_9 ) ;
struct V_2 * V_3 = V_80 -> V_3 ;
struct V_6 * V_12 ;
unsigned int V_117 ;
int V_119 ;
V_117 = F_88 ( V_8 ( V_9 ) ) ;
if ( V_117 >= V_8 ( V_9 ) -> V_14 )
V_117 = 0 ;
if ( V_3 -> V_4 ) {
V_12 = F_2 ( V_3 ) ;
V_119 = F_84 ( V_12 , V_9 , V_117 )
+ V_121 ;
V_3 -> V_4 -> V_119 += V_119 ;
}
return V_117 ;
}
static T_2 F_89
( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_86 ( V_3 -> V_4 ,
F_87 ( V_9 , 0 ) ) ;
}
static T_3 F_90 ( struct V_2 * V_3 ,
T_3 V_122 )
{
struct V_49 * V_50 = F_22 ( V_3 ) ;
struct V_24 * V_54 = V_50 -> V_54 ;
T_3 V_123 , V_124 ;
if ( ! V_54 -> V_125 -> V_126 -> V_119 )
return V_122 ;
V_123 = V_54 -> V_125 -> V_126 -> V_119 ( V_3 , V_54 ) ;
V_124 = F_91 ( V_123 * 1000000000LL ,
V_3 -> V_4 -> V_51 ) ;
if ( V_3 -> V_7 == V_41 )
return V_122 + V_124 ;
return ( V_122 > V_124 ) ? V_122 - V_124 : 0 ;
}
static int F_92 ( struct V_2 * V_3 ,
struct V_127 * V_128 , struct V_127 * V_129 ,
struct V_130 * V_131 ,
struct V_132 * V_133 )
{
struct V_1 * V_116 = F_1 ( V_3 ) ;
struct V_8 * V_80 = V_8 ( V_116 ) ;
T_3 V_122 ;
if ( ( V_3 -> V_4 -> V_42 . V_43 & V_45 ) &&
( V_131 -> V_134 == V_135 ) ) {
F_93 ( V_3 -> V_4 , V_128 ) ;
V_122 = F_94 ( & V_80 -> V_136 ) ;
V_122 = F_91 ( V_122 , 3 ) ;
if ( V_131 -> V_137 )
V_122 = F_90 ( V_3 , V_122 ) ;
* V_129 = F_95 ( V_122 ) ;
V_133 -> V_138 = V_135 ;
V_133 -> V_139 = 1 ;
V_133 -> V_140 = 42 ;
} else {
V_133 -> V_138 = V_141 ;
}
return 0 ;
}
static void F_96 ( struct V_142 * V_113 )
{
F_97 ( V_113 ) ;
}
static int F_98 ( struct V_49 * V_50 )
{
struct V_24 * V_25 = V_50 -> V_108 ;
struct V_6 * V_12 = F_13 ( V_25 -> V_27 ) ;
struct V_142 * V_113 = V_50 -> V_113 ;
unsigned int V_13 ;
int V_143 = 0 ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
if ( V_25 -> V_125 -> V_144 . V_145 ||
V_25 -> V_125 -> V_146 . V_145 ) {
V_13 = V_147 * 1024 ;
if ( V_13 > V_148 )
V_13 = V_148 ;
V_143 = F_99 ( V_113 ,
V_149 ,
F_100 ( V_30 -> V_150 ) ,
V_13 , V_148 ) ;
if ( V_143 ) {
F_101 ( V_25 -> V_27 , L_11 ) ;
return V_143 ;
}
}
return V_143 ;
}
static int F_102 ( struct V_151 * V_152 )
{
struct V_6 * V_12 = F_13 ( V_152 -> V_27 ) ;
if ( V_12 -> V_21 )
return F_103 ( V_152 , V_12 ) ;
return 0 ;
}
int F_104 ( struct V_153 * V_27 )
{
int V_69 ;
struct V_6 * V_12 = F_13 ( V_27 ) ;
struct V_30 * V_30 = F_14 ( V_12 ) ;
F_105 ( & V_30 -> V_154 ) ;
V_69 = F_106 ( V_27 , & V_155 ) ;
if ( V_69 ) {
F_101 ( V_27 , L_12 , V_69 ) ;
return V_69 ;
}
V_69 = F_107 ( V_27 , & V_156 ,
V_157 ,
F_108 ( V_157 ) ) ;
if ( V_69 ) {
F_101 ( V_27 , L_13 , V_69 ) ;
F_109 ( V_27 ) ;
}
return V_69 ;
}
int F_110 ( struct V_153 * V_27 )
{
F_111 ( V_27 ) ;
F_109 ( V_27 ) ;
return 0 ;
}
