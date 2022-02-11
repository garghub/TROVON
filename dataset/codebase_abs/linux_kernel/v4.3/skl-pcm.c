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
if ( V_29 )
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
int V_29 , V_51 ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
V_29 = F_4 ( V_12 , V_3 ,
F_29 ( V_50 ) ) ;
if ( V_29 < 0 )
return V_29 ;
F_14 ( V_25 -> V_26 , L_5 ,
V_4 -> V_43 , V_4 -> V_44 , V_4 -> V_45 ) ;
V_51 = V_8 ( V_7 ) -> V_40 - 1 ;
F_14 ( V_25 -> V_26 , L_6 , V_51 ) ;
return 0 ;
}
static void F_30 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_27 * V_28 = NULL ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
F_31 ( V_7 , F_11 ( V_12 ) ) ;
V_28 = F_23 ( V_25 , V_3 ) ;
F_18 ( V_25 , V_3 , NULL ) ;
F_32 ( V_25 -> V_26 ) ;
F_33 ( V_25 -> V_26 ) ;
F_34 ( V_28 ) ;
}
static int F_35 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
F_36 ( V_8 ( V_7 ) ) ;
V_8 ( V_7 ) -> V_48 = 0 ;
return F_6 ( F_37 ( V_12 ) , V_3 ) ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_49 * V_50 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_52 ;
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_27 * V_28 ;
struct V_24 * V_46 = V_42 -> V_46 ;
int V_51 ;
F_39 ( L_7 , V_30 ) ;
V_52 = F_16 ( V_12 , V_3 ,
V_53 ) ;
if ( ! V_52 )
return - V_32 ;
F_18 ( V_25 , V_3 , ( void * ) V_52 ) ;
V_28 = (struct V_27 * )
F_23 ( V_46 , V_3 ) ;
if ( V_28 )
V_28 -> V_40 = V_8 ( V_52 ) -> V_40 ;
F_18 ( V_46 , V_3 , ( void * ) V_28 ) ;
V_51 = V_8 ( V_52 ) -> V_40 - 1 ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_1 * V_52 =
F_23 ( V_25 , V_3 ) ;
unsigned int V_16 = 0 ;
struct V_27 * V_28 ;
struct V_24 * V_46 = V_42 -> V_46 ;
struct V_49 * V_50 ;
struct V_54 * V_44 , * V_43 ;
struct V_55 * V_56 ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
if ( V_52 -> V_57 ) {
F_14 ( V_25 -> V_26 , L_3 ) ;
return 0 ;
}
V_50 = F_41 ( V_25 -> V_26 , sizeof( * V_50 ) , V_38 ) ;
if ( V_50 == NULL )
return - V_39 ;
V_44 = F_42 ( V_50 , V_58 ) ;
V_44 -> V_59 = V_44 -> V_60 = V_3 -> V_4 -> V_44 ;
V_43 = F_42 ( V_50 , V_61 ) ;
V_43 -> V_59 = V_43 -> V_60 = V_3 -> V_4 -> V_43 ;
F_43 ( & V_50 -> V_62 [ V_63 -
V_64 ] ,
V_3 -> V_4 -> V_45 ) ;
V_28 = (struct V_27 * )
F_23 ( V_46 , V_3 ) ;
if ( V_28 )
V_16 = V_28 -> V_45 ;
F_14 ( V_25 -> V_26 , L_8 ,
V_8 ( V_52 ) -> V_40 , V_16 , V_46 -> V_31 ) ;
F_44 ( V_52 ) ;
F_45 ( V_52 , V_16 ) ;
V_56 = F_46 ( V_12 , V_42 -> V_65 -> V_66 . V_31 ) ;
if ( ! V_56 )
return - V_67 ;
F_47 ( V_56 , V_8 ( V_52 ) -> V_40 ) ;
V_52 -> V_57 = 1 ;
return 0 ;
}
static int F_48 ( struct V_2 * V_3 ,
int V_68 , struct V_24 * V_25 )
{
struct V_1 * V_52 =
F_23 ( V_25 , V_3 ) ;
F_14 ( V_25 -> V_26 , L_9 , V_30 , V_68 ) ;
switch ( V_68 ) {
case V_69 :
case V_70 :
case V_71 :
F_49 ( V_52 ) ;
break;
case V_72 :
case V_73 :
case V_74 :
F_50 ( V_52 ) ;
break;
default:
return - V_67 ;
}
return 0 ;
}
static int F_51 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_1 * V_52 =
F_23 ( V_25 , V_3 ) ;
struct V_55 * V_56 ;
F_14 ( V_25 -> V_26 , L_1 , V_30 , V_25 -> V_31 ) ;
V_52 -> V_57 = 0 ;
V_56 = F_46 ( V_12 , V_42 -> V_65 -> V_66 . V_31 ) ;
if ( ! V_56 )
return - V_67 ;
F_52 ( V_56 , V_8 ( V_52 ) -> V_40 ) ;
F_31 ( V_52 , V_53 ) ;
return 0 ;
}
static int F_53 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
return F_15 ( V_25 -> V_26 ) ;
}
static void F_54 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
F_32 ( V_25 -> V_26 ) ;
F_33 ( V_25 -> V_26 ) ;
}
static int F_55 ( struct V_2 * V_3 )
{
struct V_17 * V_4 ;
struct V_41 * V_42 = V_3 -> V_5 ;
struct V_75 * V_76 = V_42 -> V_76 ;
F_14 ( V_42 -> V_77 -> V_26 , L_10 , V_30 ,
V_76 -> V_78 ) ;
V_4 = V_3 -> V_4 ;
F_56 ( V_3 , & V_79 ) ;
return 0 ;
}
static int F_57 ( struct V_2 * V_3 ,
int V_68 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_37 ( V_12 ) ;
struct V_1 * V_7 ;
struct V_2 * V_80 ;
bool V_81 ;
int V_82 = 0 ;
unsigned long V_83 ;
struct V_8 * V_84 ;
V_7 = F_1 ( V_3 ) ;
V_84 = V_8 ( V_7 ) ;
F_14 ( V_11 -> V_26 , L_9 , V_30 , V_68 ) ;
if ( ! V_84 -> V_48 )
return - V_85 ;
switch ( V_68 ) {
case V_69 :
case V_70 :
case V_71 :
V_81 = true ;
break;
case V_72 :
case V_73 :
case V_74 :
V_81 = false ;
break;
default:
return - V_67 ;
}
F_58 (s, substream) {
if ( V_80 -> V_86 -> V_87 != V_3 -> V_86 -> V_87 )
continue;
V_7 = F_1 ( V_80 ) ;
V_82 |= 1 << V_8 ( V_7 ) -> V_88 ;
F_59 ( V_80 , V_3 ) ;
}
F_60 ( & V_11 -> V_89 , V_83 ) ;
F_61 ( V_84 , true , V_82 , V_90 ) ;
F_58 (s, substream) {
if ( V_80 -> V_86 -> V_87 != V_3 -> V_86 -> V_87 )
continue;
V_7 = F_1 ( V_80 ) ;
if ( V_81 )
F_62 ( V_8 ( V_7 ) , true ) ;
else
F_63 ( V_8 ( V_7 ) ) ;
}
F_64 ( & V_11 -> V_89 , V_83 ) ;
F_65 ( V_84 , V_81 , V_82 ) ;
F_60 ( & V_11 -> V_89 , V_83 ) ;
F_61 ( V_84 , false , V_82 , V_90 ) ;
if ( V_81 )
F_66 ( V_84 , V_82 ) ;
F_64 ( & V_11 -> V_89 , V_83 ) ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 ,
int V_68 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_37 ( V_12 ) ;
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_24 * V_77 = V_42 -> V_77 ;
struct V_1 * V_7 ;
int V_81 ;
unsigned long V_83 ;
struct V_8 * V_84 ;
F_14 ( V_11 -> V_26 , L_11 , V_30 , V_68 , V_77 -> V_31 ) ;
V_7 = F_1 ( V_3 ) ;
V_84 = V_8 ( V_7 ) ;
if ( ! V_84 -> V_48 )
return - V_85 ;
switch ( V_68 ) {
case V_69 :
case V_70 :
case V_71 :
V_81 = 1 ;
break;
case V_72 :
case V_73 :
case V_74 :
V_81 = 0 ;
break;
default:
return - V_67 ;
}
F_60 ( & V_11 -> V_89 , V_83 ) ;
if ( V_81 )
F_62 ( V_8 ( V_7 ) , true ) ;
else
F_63 ( V_8 ( V_7 ) ) ;
if ( V_81 )
F_66 ( V_84 , 0 ) ;
F_64 ( & V_11 -> V_89 , V_83 ) ;
return 0 ;
}
static int F_68 ( struct V_2 * V_3 ,
int V_68 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
if ( V_12 -> V_21 )
return F_67 ( V_3 , V_68 ) ;
else
return F_57 ( V_3 , V_68 ) ;
}
static int F_69 ( struct V_6 * V_12 ,
struct V_1 * V_91 ,
unsigned int V_92 )
{
struct V_10 * V_11 = F_37 ( V_12 ) ;
struct V_8 * V_9 = V_8 ( V_91 ) ;
struct V_2 * V_3 = V_9 -> V_3 ;
int V_7 = V_3 -> V_7 ;
unsigned int V_93 = F_70 ( V_9 ) ;
int V_94 ;
if ( V_7 == V_95 )
V_94 = V_92 - V_93 ;
else
V_94 = V_93 - V_92 ;
if ( V_94 < 0 ) {
if ( V_94 >= V_9 -> V_96 )
V_94 = 0 ;
else
V_94 += V_9 -> V_14 ;
}
if ( V_94 >= V_9 -> V_15 ) {
F_71 ( V_11 -> V_26 ,
L_12 ,
V_94 , V_9 -> V_15 ) ;
V_94 = 0 ;
}
return F_72 ( V_3 -> V_4 , V_94 ) ;
}
static unsigned int F_73 ( struct V_1 * V_9 ,
int V_97 )
{
struct V_8 * V_84 = V_8 ( V_9 ) ;
struct V_2 * V_3 = V_84 -> V_3 ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
unsigned int V_92 ;
int V_94 ;
V_92 = F_74 ( V_8 ( V_9 ) ) ;
if ( V_92 >= V_8 ( V_9 ) -> V_14 )
V_92 = 0 ;
if ( V_3 -> V_4 ) {
V_94 = F_69 ( V_12 , V_9 , V_92 )
+ V_97 ;
V_3 -> V_4 -> V_94 += V_94 ;
}
return V_92 ;
}
static T_2 F_75
( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
return F_72 ( V_3 -> V_4 ,
F_73 ( V_9 , 0 ) ) ;
}
static T_3 F_76 ( struct V_2 * V_3 ,
T_3 V_98 )
{
struct V_41 * V_42 = F_21 ( V_3 ) ;
struct V_24 * V_46 = V_42 -> V_46 ;
T_3 V_99 , V_100 ;
if ( ! V_46 -> V_101 -> V_102 -> V_94 )
return V_98 ;
V_99 = V_46 -> V_101 -> V_102 -> V_94 ( V_3 , V_46 ) ;
V_100 = F_77 ( V_99 * 1000000000LL ,
V_3 -> V_4 -> V_43 ) ;
if ( V_3 -> V_7 == V_33 )
return V_98 + V_100 ;
return ( V_98 > V_100 ) ? V_98 - V_100 : 0 ;
}
static int F_78 ( struct V_2 * V_3 ,
struct V_103 * V_104 , struct V_103 * V_105 ,
struct V_106 * V_107 ,
struct V_108 * V_109 )
{
struct V_1 * V_91 = F_1 ( V_3 ) ;
struct V_8 * V_84 = V_8 ( V_91 ) ;
T_3 V_98 ;
if ( ( V_3 -> V_4 -> V_34 . V_35 & V_37 ) &&
( V_107 -> V_110 == V_111 ) ) {
F_79 ( V_3 -> V_4 , V_104 ) ;
V_98 = F_80 ( & V_84 -> V_112 ) ;
V_98 = F_77 ( V_98 , 3 ) ;
if ( V_107 -> V_113 )
V_98 = F_76 ( V_3 , V_98 ) ;
* V_105 = F_81 ( V_98 ) ;
V_109 -> V_114 = V_111 ;
V_109 -> V_115 = 1 ;
V_109 -> V_116 = 42 ;
} else {
V_109 -> V_114 = V_117 ;
}
return 0 ;
}
static void F_82 ( struct V_118 * V_86 )
{
F_83 ( V_86 ) ;
}
static int F_84 ( struct V_41 * V_42 )
{
struct V_24 * V_25 = V_42 -> V_77 ;
struct V_6 * V_12 = F_13 ( V_25 -> V_26 ) ;
struct V_118 * V_86 = V_42 -> V_86 ;
unsigned int V_13 ;
int V_119 = 0 ;
struct V_120 * V_120 = F_85 ( V_12 ) ;
if ( V_25 -> V_101 -> V_121 . V_122 ||
V_25 -> V_101 -> V_123 . V_122 ) {
V_13 = V_124 * 1024 ;
if ( V_13 > V_125 )
V_13 = V_125 ;
V_119 = F_86 ( V_86 ,
V_126 ,
F_87 ( V_120 -> V_127 ) ,
V_13 , V_125 ) ;
if ( V_119 ) {
F_88 ( V_25 -> V_26 , L_13 ) ;
return V_119 ;
}
}
return V_119 ;
}
int F_89 ( struct V_128 * V_26 )
{
int V_29 ;
V_29 = F_90 ( V_26 , & V_129 ) ;
if ( V_29 ) {
F_88 ( V_26 , L_14 , V_29 ) ;
return V_29 ;
}
V_29 = F_91 ( V_26 , & V_130 ,
V_131 ,
F_92 ( V_131 ) ) ;
if ( V_29 ) {
F_88 ( V_26 , L_15 , V_29 ) ;
F_93 ( V_26 ) ;
}
return V_29 ;
}
int F_94 ( struct V_128 * V_26 )
{
F_95 ( V_26 ) ;
F_93 ( V_26 ) ;
return 0 ;
}
