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
if ( ( F_12 ( V_12 ) ) -> V_21 )
return V_22 ;
else
return V_23 ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_24 * V_25 , bool V_26 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_28 * V_29 ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
if ( V_3 -> V_7 == V_31 )
V_29 = V_25 -> V_32 ;
else
V_29 = V_25 -> V_33 ;
if ( V_29 -> V_34 && V_26 )
V_30 -> V_35 ++ ;
else if ( V_29 -> V_34 && ! V_26 )
V_30 -> V_35 -- ;
}
int F_16 ( struct V_36 * V_27 , struct V_37 * V_38 )
{
struct V_6 * V_12 = F_14 ( V_27 ) ;
struct V_10 * V_11 = F_12 ( V_12 ) ;
unsigned int V_16 ;
struct V_8 * V_9 ;
struct V_1 * V_7 ;
int V_39 ;
V_9 = F_17 ( V_11 , V_38 -> V_7 ,
V_38 -> V_40 + 1 ) ;
if ( ! V_9 )
return - V_41 ;
V_7 = F_18 ( V_9 ) ;
F_19 ( V_12 , V_7 , true ) ;
V_16 = F_20 ( V_38 -> V_42 ,
V_38 -> V_43 , V_38 -> V_44 , 32 , 0 ) ;
F_21 ( V_27 , L_1 ,
V_16 , V_38 -> V_42 , V_38 -> V_43 , V_38 -> V_44 ) ;
F_22 ( V_8 ( V_7 ) ) ;
V_39 = F_23 ( V_8 ( V_7 ) , V_16 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_24 ( V_8 ( V_7 ) ) ;
if ( V_39 < 0 )
return V_39 ;
V_8 ( V_7 ) -> V_45 = 1 ;
return 0 ;
}
int F_25 ( struct V_36 * V_27 , struct V_37 * V_38 )
{
struct V_6 * V_12 = F_14 ( V_27 ) ;
struct V_10 * V_11 = F_12 ( V_12 ) ;
unsigned int V_16 ;
struct V_8 * V_9 ;
struct V_1 * V_7 ;
struct V_46 * V_47 ;
V_9 = F_17 ( V_11 , V_38 -> V_7 ,
V_38 -> V_48 + 1 ) ;
if ( ! V_9 )
return - V_41 ;
V_7 = F_18 ( V_9 ) ;
F_19 ( V_12 , V_7 , true ) ;
V_16 = F_20 ( V_38 -> V_42 ,
V_38 -> V_43 , V_38 -> V_44 , 24 , 0 ) ;
F_21 ( V_27 , L_1 ,
V_16 , V_38 -> V_42 , V_38 -> V_43 , V_38 -> V_44 ) ;
F_26 ( V_7 ) ;
F_27 ( V_7 , V_16 ) ;
F_28 (link, &ebus->hlink_list, list) {
if ( V_47 -> V_49 == V_38 -> V_50 )
F_29 ( V_47 ,
V_9 -> V_51 ) ;
}
V_7 -> V_52 = 1 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_7 ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_53 * V_54 ;
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_55 * V_56 ;
F_21 ( V_25 -> V_27 , L_2 , V_57 , V_25 -> V_58 ) ;
V_7 = F_32 ( V_12 , V_3 ,
F_11 ( V_12 ) ) ;
if ( V_7 == NULL )
return - V_59 ;
F_8 ( V_12 , V_4 ) ;
if ( V_3 -> V_7 == V_60 ) {
V_4 -> V_61 . V_62 &= ~ V_63 ;
V_4 -> V_61 . V_62 &= ~ V_64 ;
}
V_4 -> V_5 = V_7 ;
V_54 = F_33 ( sizeof( * V_54 ) , V_65 ) ;
if ( ! V_54 )
return - V_66 ;
V_54 -> V_51 = V_8 ( V_7 ) -> V_51 ;
F_34 ( V_25 , V_3 , V_54 ) ;
F_21 ( V_25 -> V_27 , L_3 ,
V_54 -> V_51 ) ;
F_13 ( V_3 , V_25 , true ) ;
F_35 ( V_3 ) ;
V_56 = F_36 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_56 )
return - V_41 ;
F_37 ( V_30 , V_56 -> V_67 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_68 * V_69 = V_30 -> V_68 ;
struct V_55 * V_56 ;
if ( V_25 -> V_32 -> V_70 || V_25 -> V_33 -> V_70 )
return 0 ;
V_56 = F_39 ( V_25 , V_3 -> V_7 ) ;
if ( V_56 == NULL )
return - V_41 ;
return F_40 ( V_69 , V_56 ) ;
}
static int F_41 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_55 * V_56 ;
F_21 ( V_25 -> V_27 , L_2 , V_57 , V_25 -> V_58 ) ;
V_56 = F_36 ( V_25 , V_3 -> V_7 ) ;
if ( V_56 && ( V_3 -> V_4 -> V_71 -> V_72 ==
V_73 ) )
F_42 ( V_30 -> V_68 , V_56 -> V_74 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 ,
struct V_75 * V_38 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_37 V_76 = { 0 } ;
struct V_55 * V_77 ;
int V_78 , V_79 ;
F_21 ( V_25 -> V_27 , L_2 , V_57 , V_25 -> V_58 ) ;
V_78 = F_4 ( V_12 , V_3 ,
F_44 ( V_38 ) ) ;
if ( V_78 < 0 )
return V_78 ;
F_21 ( V_25 -> V_27 , L_4 ,
V_4 -> V_80 , V_4 -> V_81 , V_4 -> V_44 ) ;
V_79 = V_8 ( V_7 ) -> V_51 - 1 ;
F_21 ( V_25 -> V_27 , L_5 , V_79 ) ;
V_76 . V_82 = F_45 ( F_46 ( V_38 ) ) ;
V_76 . V_43 = F_47 ( V_38 ) ;
V_76 . V_42 = F_48 ( V_38 ) ;
V_76 . V_40 = V_79 ;
V_76 . V_7 = V_3 -> V_7 ;
V_76 . V_44 = F_46 ( V_38 ) ;
V_77 = F_36 ( V_25 , V_76 . V_7 ) ;
if ( V_77 )
F_49 ( V_25 -> V_27 , V_77 , & V_76 ) ;
return 0 ;
}
static void F_50 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_53 * V_54 = NULL ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
struct V_55 * V_56 ;
F_21 ( V_25 -> V_27 , L_2 , V_57 , V_25 -> V_58 ) ;
F_51 ( V_7 , F_11 ( V_12 ) ) ;
V_54 = F_52 ( V_25 , V_3 ) ;
F_34 ( V_25 , V_3 , NULL ) ;
F_13 ( V_3 , V_25 , false ) ;
if ( ! strncmp ( V_25 -> V_58 , L_6 , 13 ) &&
V_30 -> V_68 -> V_83 ) {
V_30 -> V_68 -> V_84 ( V_25 -> V_27 , true ) ;
V_30 -> V_68 -> V_83 = false ;
}
V_56 = F_36 ( V_25 , V_3 -> V_7 ) ;
F_53 ( V_30 , V_56 -> V_67 ) ;
F_54 ( V_54 ) ;
}
static int F_55 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_21 ( V_25 -> V_27 , L_2 , V_57 , V_25 -> V_58 ) ;
F_56 ( V_8 ( V_7 ) ) ;
V_8 ( V_7 ) -> V_45 = 0 ;
return F_6 ( F_12 ( V_12 ) , V_3 ) ;
}
static int F_57 ( struct V_2 * V_3 ,
struct V_75 * V_38 ,
struct V_24 * V_25 )
{
struct V_37 V_76 = { 0 } ;
V_76 . V_82 = F_45 ( F_46 ( V_38 ) ) ;
V_76 . V_43 = F_47 ( V_38 ) ;
V_76 . V_42 = F_48 ( V_38 ) ;
V_76 . V_7 = V_3 -> V_7 ;
return F_58 ( V_25 , & V_76 ) ;
}
static int F_59 ( struct V_2 * V_3 ,
int V_85 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_12 ( V_12 ) ;
struct V_1 * V_7 ;
int V_86 ;
unsigned long V_87 ;
struct V_8 * V_88 ;
V_7 = F_1 ( V_3 ) ;
V_88 = V_8 ( V_7 ) ;
if ( ! V_88 -> V_45 )
return - V_89 ;
switch ( V_85 ) {
case V_90 :
case V_91 :
case V_92 :
V_86 = 1 ;
break;
case V_93 :
case V_94 :
case V_95 :
V_86 = 0 ;
break;
default:
return - V_41 ;
}
F_60 ( & V_11 -> V_96 , V_87 ) ;
if ( V_86 ) {
F_61 ( V_8 ( V_7 ) , true ) ;
F_62 ( V_88 , 0 ) ;
} else {
F_63 ( V_8 ( V_7 ) ) ;
}
F_64 ( & V_11 -> V_96 , V_87 ) ;
return 0 ;
}
static int F_65 ( struct V_2 * V_3 , int V_85 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_68 * V_69 = V_30 -> V_68 ;
struct V_55 * V_56 ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_28 * V_29 ;
int V_78 ;
V_56 = F_36 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_56 )
return - V_97 ;
if ( V_3 -> V_7 == V_31 )
V_29 = V_25 -> V_32 ;
else
V_29 = V_25 -> V_33 ;
switch ( V_85 ) {
case V_92 :
if ( ! V_29 -> V_34 ) {
F_66 ( V_12 , true ,
V_8 ( V_7 ) -> V_49 ) ;
F_67 ( V_12 , V_7 ,
V_7 -> V_98 ) ;
F_68 ( V_7 , V_7 -> V_98 ) ;
}
case V_90 :
case V_91 :
V_78 = F_59 ( V_3 , V_85 ) ;
if ( V_78 < 0 )
return V_78 ;
return F_69 ( V_69 , V_56 -> V_74 ) ;
break;
case V_93 :
case V_94 :
case V_95 :
V_78 = F_70 ( V_69 , V_56 -> V_74 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_59 ( V_3 , V_85 ) ;
if ( ( V_85 == V_94 ) && ! V_29 -> V_34 ) {
V_7 -> V_99 = F_71 ( V_12 -> V_11 . V_100 +
V_101 +
( V_102 *
V_8 ( V_7 ) -> V_49 ) ) ;
V_7 -> V_98 = F_72 (
V_8 ( V_7 ) ) ;
F_19 ( V_12 , V_7 , false ) ;
}
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_73 ( struct V_2 * V_3 ,
struct V_75 * V_38 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_103 ;
struct V_104 * V_105 = F_74 ( V_3 ) ;
struct V_24 * V_106 = V_105 -> V_106 ;
struct V_37 V_76 = { 0 } ;
struct V_46 * V_47 ;
int V_51 ;
V_103 = F_32 ( V_12 , V_3 ,
V_107 ) ;
if ( ! V_103 )
return - V_59 ;
F_34 ( V_25 , V_3 , ( void * ) V_103 ) ;
V_47 = F_75 ( V_12 , V_105 -> V_108 -> V_109 . V_58 ) ;
if ( ! V_47 )
return - V_41 ;
V_51 = V_8 ( V_103 ) -> V_51 ;
F_76 ( V_106 , V_51 , 0 , 0 , 0 ) ;
V_76 . V_82 = F_45 ( F_46 ( V_38 ) ) ;
V_76 . V_43 = F_47 ( V_38 ) ;
V_76 . V_42 = F_48 ( V_38 ) ;
V_76 . V_7 = V_3 -> V_7 ;
V_76 . V_48 = V_51 - 1 ;
V_76 . V_50 = V_47 -> V_49 ;
V_76 . V_44 = F_46 ( V_38 ) ;
return F_58 ( V_25 , & V_76 ) ;
}
static int F_77 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_55 * V_56 = NULL ;
V_56 = F_39 ( V_25 , V_3 -> V_7 ) ;
if ( V_56 && ! V_56 -> V_74 -> V_110 &&
( V_3 -> V_4 -> V_71 -> V_72 == V_73 ) )
F_42 ( V_30 -> V_68 , V_56 -> V_74 ) ;
return 0 ;
}
static int F_78 ( struct V_2 * V_3 ,
int V_85 , struct V_24 * V_25 )
{
struct V_1 * V_103 =
F_52 ( V_25 , V_3 ) ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_21 ( V_25 -> V_27 , L_7 , V_57 , V_85 ) ;
switch ( V_85 ) {
case V_92 :
case V_90 :
case V_91 :
F_79 ( V_103 ) ;
break;
case V_93 :
case V_94 :
case V_95 :
F_80 ( V_103 ) ;
if ( V_85 == V_94 )
F_19 ( V_12 , V_7 , false ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_81 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_104 * V_105 = F_74 ( V_3 ) ;
struct V_1 * V_103 =
F_52 ( V_25 , V_3 ) ;
struct V_46 * V_47 ;
F_21 ( V_25 -> V_27 , L_2 , V_57 , V_25 -> V_58 ) ;
V_103 -> V_52 = 0 ;
V_47 = F_75 ( V_12 , V_105 -> V_108 -> V_109 . V_58 ) ;
if ( ! V_47 )
return - V_41 ;
F_82 ( V_47 , V_8 ( V_103 ) -> V_51 ) ;
F_51 ( V_103 , V_107 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 )
{
struct V_17 * V_4 ;
struct V_104 * V_105 = V_3 -> V_5 ;
struct V_111 * V_112 = V_105 -> V_112 ;
F_21 ( V_105 -> V_113 -> V_27 , L_8 , V_57 ,
V_112 -> V_114 ) ;
V_4 = V_3 -> V_4 ;
F_84 ( V_3 , & V_115 ) ;
return 0 ;
}
static int F_85 ( struct V_2 * V_3 ,
int V_85 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_12 ( V_12 ) ;
struct V_1 * V_7 ;
struct V_2 * V_116 ;
bool V_86 ;
int V_117 = 0 ;
unsigned long V_87 ;
struct V_8 * V_88 ;
V_7 = F_1 ( V_3 ) ;
V_88 = V_8 ( V_7 ) ;
F_21 ( V_11 -> V_27 , L_7 , V_57 , V_85 ) ;
if ( ! V_88 -> V_45 )
return - V_89 ;
switch ( V_85 ) {
case V_90 :
case V_91 :
case V_92 :
V_86 = true ;
break;
case V_93 :
case V_94 :
case V_95 :
V_86 = false ;
break;
default:
return - V_41 ;
}
F_86 (s, substream) {
if ( V_116 -> V_118 -> V_119 != V_3 -> V_118 -> V_119 )
continue;
V_7 = F_1 ( V_116 ) ;
V_117 |= 1 << V_8 ( V_7 ) -> V_49 ;
F_87 ( V_116 , V_3 ) ;
}
F_60 ( & V_11 -> V_96 , V_87 ) ;
F_88 ( V_88 , true , V_117 , V_120 ) ;
F_86 (s, substream) {
if ( V_116 -> V_118 -> V_119 != V_3 -> V_118 -> V_119 )
continue;
V_7 = F_1 ( V_116 ) ;
if ( V_86 )
F_61 ( V_8 ( V_7 ) , true ) ;
else
F_63 ( V_8 ( V_7 ) ) ;
}
F_64 ( & V_11 -> V_96 , V_87 ) ;
F_89 ( V_88 , V_86 , V_117 ) ;
F_60 ( & V_11 -> V_96 , V_87 ) ;
F_88 ( V_88 , false , V_117 , V_120 ) ;
if ( V_86 )
F_62 ( V_88 , V_117 ) ;
F_64 ( & V_11 -> V_96 , V_87 ) ;
return 0 ;
}
static int F_90 ( struct V_2 * V_3 ,
int V_85 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
if ( ! ( F_12 ( V_12 ) ) -> V_21 )
return F_85 ( V_3 , V_85 ) ;
return 0 ;
}
static T_2 F_91
( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
unsigned int V_121 ;
if ( V_3 -> V_7 == V_31 )
V_121 = F_71 ( V_12 -> V_11 . V_100 + V_101 +
( V_102 *
V_8 ( V_9 ) -> V_49 ) ) ;
else
V_121 = F_92 ( V_8 ( V_9 ) ) ;
if ( V_121 >= V_8 ( V_9 ) -> V_14 )
V_121 = 0 ;
return F_93 ( V_3 -> V_4 , V_121 ) ;
}
static T_3 F_94 ( struct V_2 * V_3 ,
T_3 V_122 )
{
struct V_104 * V_105 = F_74 ( V_3 ) ;
struct V_24 * V_106 = V_105 -> V_106 ;
T_3 V_123 , V_124 ;
if ( ! V_106 -> V_125 -> V_126 -> V_127 )
return V_122 ;
V_123 = V_106 -> V_125 -> V_126 -> V_127 ( V_3 , V_106 ) ;
V_124 = F_95 ( V_123 * 1000000000LL ,
V_3 -> V_4 -> V_80 ) ;
if ( V_3 -> V_7 == V_60 )
return V_122 + V_124 ;
return ( V_122 > V_124 ) ? V_122 - V_124 : 0 ;
}
static int F_96 ( struct V_2 * V_3 ,
struct V_128 * V_129 , struct V_128 * V_130 ,
struct V_131 * V_132 ,
struct V_133 * V_134 )
{
struct V_1 * V_135 = F_1 ( V_3 ) ;
struct V_8 * V_88 = V_8 ( V_135 ) ;
T_3 V_122 ;
if ( ( V_3 -> V_4 -> V_61 . V_62 & V_64 ) &&
( V_132 -> V_136 == V_137 ) ) {
F_97 ( V_3 -> V_4 , V_129 ) ;
V_122 = F_98 ( & V_88 -> V_138 ) ;
V_122 = F_95 ( V_122 , 3 ) ;
if ( V_132 -> V_139 )
V_122 = F_94 ( V_3 , V_122 ) ;
* V_130 = F_99 ( V_122 ) ;
V_134 -> V_140 = V_137 ;
V_134 -> V_141 = 1 ;
V_134 -> V_142 = 42 ;
} else {
V_134 -> V_140 = V_143 ;
}
return 0 ;
}
static void F_100 ( struct V_144 * V_118 )
{
F_101 ( V_118 ) ;
}
static int F_102 ( struct V_104 * V_105 )
{
struct V_24 * V_25 = V_105 -> V_113 ;
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_144 * V_118 = V_105 -> V_118 ;
unsigned int V_13 ;
int V_145 = 0 ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
if ( V_25 -> V_125 -> V_146 . V_147 ||
V_25 -> V_125 -> V_148 . V_147 ) {
V_13 = V_149 * 1024 ;
if ( V_13 > V_150 )
V_13 = V_150 ;
V_145 = F_103 ( V_118 ,
V_151 ,
F_104 ( V_30 -> V_152 ) ,
V_13 , V_150 ) ;
if ( V_145 ) {
F_105 ( V_25 -> V_27 , L_9 ) ;
return V_145 ;
}
}
return V_145 ;
}
static int F_106 ( struct V_30 * V_30 )
{
struct V_153 * V_154 ;
struct V_155 * V_156 ;
struct V_28 * V_29 ;
struct V_55 * V_56 ;
int V_78 ;
F_28 (p, &skl->ppl_list, node) {
F_28 (m, &p->pipe->w_list, node) {
V_29 = V_156 -> V_29 ;
V_56 = V_29 -> V_157 ;
V_78 = F_107 ( V_30 -> V_68 , V_56 ) ;
if ( V_78 < 0 ) {
F_105 ( V_30 -> V_68 -> V_27 ,
L_10 , V_78 ) ;
goto V_39;
}
}
}
V_39:
return V_78 ;
}
static int F_108 ( struct V_158 * V_159 )
{
struct V_6 * V_12 = F_14 ( V_159 -> V_27 ) ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
const struct V_160 * V_126 ;
int V_78 ;
F_109 ( V_159 -> V_27 ) ;
if ( ( F_12 ( V_12 ) ) -> V_21 ) {
V_78 = F_110 ( V_159 , V_12 ) ;
if ( V_78 < 0 ) {
F_105 ( V_159 -> V_27 , L_11 ) ;
return V_78 ;
}
V_30 -> V_159 = V_159 ;
V_126 = F_111 ( V_30 -> V_152 -> V_36 ) ;
if ( ! V_126 )
return - V_97 ;
if ( V_30 -> V_68 -> V_161 == false ) {
F_105 ( V_159 -> V_27 , L_12 ) ;
return - V_97 ;
}
V_78 = V_126 -> V_162 ( V_159 -> V_27 , V_30 -> V_68 ) ;
if ( V_78 < 0 ) {
F_105 ( V_159 -> V_27 , L_13 , V_78 ) ;
return V_78 ;
}
F_106 ( V_30 ) ;
V_30 -> V_68 -> V_163 = V_164 ;
}
F_112 ( V_159 -> V_27 ) ;
F_113 ( V_159 -> V_27 ) ;
return 0 ;
}
int F_114 ( struct V_36 * V_27 )
{
int V_78 ;
struct V_6 * V_12 = F_14 ( V_27 ) ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
F_115 ( & V_30 -> V_165 ) ;
V_78 = F_116 ( V_27 , & V_166 ) ;
if ( V_78 ) {
F_105 ( V_27 , L_14 , V_78 ) ;
return V_78 ;
}
V_78 = F_117 ( V_27 , & V_167 ,
V_168 ,
F_118 ( V_168 ) ) ;
if ( V_78 ) {
F_105 ( V_27 , L_15 , V_78 ) ;
F_119 ( V_27 ) ;
}
return V_78 ;
}
int F_120 ( struct V_36 * V_27 )
{
F_121 ( V_27 ) ;
F_119 ( V_27 ) ;
return 0 ;
}
