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
V_38 -> V_43 , V_38 -> V_44 , V_38 -> V_45 , 0 ) ;
F_21 ( V_27 , L_1 ,
V_16 , V_38 -> V_42 , V_38 -> V_43 , V_38 -> V_44 ) ;
F_22 ( V_8 ( V_7 ) ) ;
V_39 = F_23 ( V_8 ( V_7 ) , V_16 ) ;
if ( V_39 < 0 )
return V_39 ;
V_39 = F_24 ( V_8 ( V_7 ) ) ;
if ( V_39 < 0 )
return V_39 ;
V_8 ( V_7 ) -> V_46 = 1 ;
return 0 ;
}
int F_25 ( struct V_36 * V_27 , struct V_37 * V_38 )
{
struct V_6 * V_12 = F_14 ( V_27 ) ;
struct V_10 * V_11 = F_12 ( V_12 ) ;
unsigned int V_16 ;
struct V_8 * V_9 ;
struct V_1 * V_7 ;
struct V_47 * V_48 ;
V_9 = F_17 ( V_11 , V_38 -> V_7 ,
V_38 -> V_49 + 1 ) ;
if ( ! V_9 )
return - V_41 ;
V_7 = F_18 ( V_9 ) ;
F_19 ( V_12 , V_7 , true ) ;
V_16 = F_20 ( V_38 -> V_42 , V_38 -> V_43 ,
V_38 -> V_44 , V_38 -> V_50 , 0 ) ;
F_21 ( V_27 , L_1 ,
V_16 , V_38 -> V_42 , V_38 -> V_43 , V_38 -> V_44 ) ;
F_26 ( V_7 ) ;
F_27 ( V_7 , V_16 ) ;
F_28 (link, &ebus->hlink_list, list) {
if ( V_48 -> V_51 == V_38 -> V_52 )
F_29 ( V_48 ,
V_9 -> V_53 ) ;
}
V_7 -> V_54 = 1 ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_7 ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_55 * V_56 ;
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_57 * V_58 ;
F_21 ( V_25 -> V_27 , L_2 , V_59 , V_25 -> V_60 ) ;
V_7 = F_32 ( V_12 , V_3 ,
F_11 ( V_12 ) ) ;
if ( V_7 == NULL )
return - V_61 ;
F_8 ( V_12 , V_4 ) ;
if ( V_3 -> V_7 == V_62 ) {
V_4 -> V_63 . V_64 &= ~ V_65 ;
V_4 -> V_63 . V_64 &= ~ V_66 ;
}
V_4 -> V_5 = V_7 ;
V_56 = F_33 ( sizeof( * V_56 ) , V_67 ) ;
if ( ! V_56 )
return - V_68 ;
V_56 -> V_53 = V_8 ( V_7 ) -> V_53 ;
F_34 ( V_25 , V_3 , V_56 ) ;
F_21 ( V_25 -> V_27 , L_3 ,
V_56 -> V_53 ) ;
F_13 ( V_3 , V_25 , true ) ;
F_35 ( V_3 ) ;
V_58 = F_36 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_58 )
return - V_41 ;
F_37 ( V_30 , V_58 -> V_69 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_57 * V_58 ;
F_21 ( V_25 -> V_27 , L_2 , V_59 , V_25 -> V_60 ) ;
V_58 = F_36 ( V_25 , V_3 -> V_7 ) ;
if ( V_58 && ( V_3 -> V_4 -> V_70 -> V_71 ==
V_72 ) )
F_39 ( V_30 -> V_73 , V_58 -> V_74 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 ,
struct V_75 * V_38 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_17 * V_4 = V_3 -> V_4 ;
struct V_37 V_76 = { 0 } ;
struct V_57 * V_77 ;
int V_78 , V_79 ;
F_21 ( V_25 -> V_27 , L_2 , V_59 , V_25 -> V_60 ) ;
V_78 = F_4 ( V_12 , V_3 ,
F_41 ( V_38 ) ) ;
if ( V_78 < 0 )
return V_78 ;
F_21 ( V_25 -> V_27 , L_4 ,
V_4 -> V_80 , V_4 -> V_81 , V_4 -> V_44 ) ;
V_79 = V_8 ( V_7 ) -> V_53 - 1 ;
F_21 ( V_25 -> V_27 , L_5 , V_79 ) ;
V_76 . V_82 = F_42 ( F_43 ( V_38 ) ) ;
V_76 . V_43 = F_44 ( V_38 ) ;
V_76 . V_42 = F_45 ( V_38 ) ;
V_76 . V_40 = V_79 ;
V_76 . V_7 = V_3 -> V_7 ;
V_76 . V_44 = F_43 ( V_38 ) ;
if ( V_3 -> V_7 == V_31 )
V_76 . V_45 = V_25 -> V_83 -> V_84 . V_85 ;
else
V_76 . V_45 = V_25 -> V_83 -> V_86 . V_85 ;
V_77 = F_36 ( V_25 , V_76 . V_7 ) ;
if ( V_77 )
F_46 ( V_25 -> V_27 , V_77 , & V_76 ) ;
return 0 ;
}
static void F_47 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_55 * V_56 = NULL ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
struct V_57 * V_58 ;
F_21 ( V_25 -> V_27 , L_2 , V_59 , V_25 -> V_60 ) ;
F_48 ( V_7 , F_11 ( V_12 ) ) ;
V_56 = F_49 ( V_25 , V_3 ) ;
F_34 ( V_25 , V_3 , NULL ) ;
F_13 ( V_3 , V_25 , false ) ;
if ( ! strncmp ( V_25 -> V_60 , L_6 , 13 ) &&
V_30 -> V_73 -> V_87 ) {
V_30 -> V_73 -> V_88 ( V_25 -> V_27 , true ) ;
V_30 -> V_73 -> V_87 = false ;
}
V_58 = F_36 ( V_25 , V_3 -> V_7 ) ;
F_50 ( V_30 , V_58 -> V_69 ) ;
F_51 ( V_56 ) ;
}
static int F_52 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_21 ( V_25 -> V_27 , L_2 , V_59 , V_25 -> V_60 ) ;
F_53 ( V_8 ( V_7 ) ) ;
V_8 ( V_7 ) -> V_46 = 0 ;
return F_6 ( F_12 ( V_12 ) , V_3 ) ;
}
static int F_54 ( struct V_2 * V_3 ,
struct V_75 * V_38 ,
struct V_24 * V_25 )
{
struct V_37 V_76 = { 0 } ;
V_76 . V_82 = F_42 ( F_43 ( V_38 ) ) ;
V_76 . V_43 = F_44 ( V_38 ) ;
V_76 . V_42 = F_45 ( V_38 ) ;
V_76 . V_7 = V_3 -> V_7 ;
return F_55 ( V_25 , & V_76 ) ;
}
static int F_56 ( struct V_2 * V_3 ,
int V_89 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_12 ( V_12 ) ;
struct V_1 * V_7 ;
int V_90 ;
unsigned long V_91 ;
struct V_8 * V_92 ;
V_7 = F_1 ( V_3 ) ;
V_92 = V_8 ( V_7 ) ;
if ( ! V_92 -> V_46 )
return - V_93 ;
switch ( V_89 ) {
case V_94 :
case V_95 :
case V_96 :
V_90 = 1 ;
break;
case V_97 :
case V_98 :
case V_99 :
V_90 = 0 ;
break;
default:
return - V_41 ;
}
F_57 ( & V_11 -> V_100 , V_91 ) ;
if ( V_90 ) {
F_58 ( V_8 ( V_7 ) , true ) ;
F_59 ( V_92 , 0 ) ;
} else {
F_60 ( V_8 ( V_7 ) ) ;
}
F_61 ( & V_11 -> V_100 , V_91 ) ;
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , int V_89 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_73 * V_101 = V_30 -> V_73 ;
struct V_57 * V_58 ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_28 * V_29 ;
int V_78 ;
V_58 = F_36 ( V_25 , V_3 -> V_7 ) ;
if ( ! V_58 )
return - V_102 ;
if ( V_3 -> V_7 == V_31 )
V_29 = V_25 -> V_32 ;
else
V_29 = V_25 -> V_33 ;
switch ( V_89 ) {
case V_96 :
if ( ! V_29 -> V_34 ) {
F_63 ( V_12 , true ,
V_8 ( V_7 ) -> V_51 ) ;
F_64 ( V_12 , V_7 ,
V_7 -> V_103 ) ;
F_65 ( V_7 , V_7 -> V_103 ) ;
}
case V_94 :
case V_95 :
V_78 = F_56 ( V_3 , V_89 ) ;
if ( V_78 < 0 )
return V_78 ;
return F_66 ( V_101 , V_58 -> V_74 ) ;
break;
case V_97 :
case V_98 :
case V_99 :
V_78 = F_67 ( V_101 , V_58 -> V_74 ) ;
if ( V_78 < 0 )
return V_78 ;
V_78 = F_56 ( V_3 , V_89 ) ;
if ( ( V_89 == V_98 ) && ! V_29 -> V_34 ) {
V_7 -> V_104 = F_68 ( V_12 -> V_11 . V_105 +
V_106 +
( V_107 *
V_8 ( V_7 ) -> V_51 ) ) ;
V_7 -> V_103 = F_69 (
V_8 ( V_7 ) ) ;
F_19 ( V_12 , V_7 , false ) ;
}
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_70 ( struct V_2 * V_3 ,
struct V_75 * V_38 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_1 * V_108 ;
struct V_109 * V_110 = F_71 ( V_3 ) ;
struct V_24 * V_111 = V_110 -> V_111 ;
struct V_37 V_76 = { 0 } ;
struct V_47 * V_48 ;
int V_53 ;
V_108 = F_32 ( V_12 , V_3 ,
V_112 ) ;
if ( ! V_108 )
return - V_61 ;
F_34 ( V_25 , V_3 , ( void * ) V_108 ) ;
V_48 = F_72 ( V_12 , V_110 -> V_113 -> V_114 . V_60 ) ;
if ( ! V_48 )
return - V_41 ;
V_53 = V_8 ( V_108 ) -> V_53 ;
F_73 ( V_111 , V_53 , 0 , 0 , 0 ) ;
V_76 . V_82 = F_42 ( F_43 ( V_38 ) ) ;
V_76 . V_43 = F_44 ( V_38 ) ;
V_76 . V_42 = F_45 ( V_38 ) ;
V_76 . V_7 = V_3 -> V_7 ;
V_76 . V_49 = V_53 - 1 ;
V_76 . V_52 = V_48 -> V_51 ;
V_76 . V_44 = F_43 ( V_38 ) ;
if ( V_3 -> V_7 == V_31 )
V_76 . V_50 = V_111 -> V_83 -> V_84 . V_85 ;
else
V_76 . V_50 = V_111 -> V_83 -> V_86 . V_85 ;
return F_55 ( V_25 , & V_76 ) ;
}
static int F_74 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_30 * V_30 = F_31 ( V_25 -> V_27 ) ;
struct V_57 * V_58 = NULL ;
V_58 = F_75 ( V_25 , V_3 -> V_7 ) ;
if ( V_58 && ! V_58 -> V_74 -> V_115 &&
( V_3 -> V_4 -> V_70 -> V_71 == V_72 ) )
F_39 ( V_30 -> V_73 , V_58 -> V_74 ) ;
return 0 ;
}
static int F_76 ( struct V_2 * V_3 ,
int V_89 , struct V_24 * V_25 )
{
struct V_1 * V_108 =
F_49 ( V_25 , V_3 ) ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
F_21 ( V_25 -> V_27 , L_7 , V_59 , V_89 ) ;
switch ( V_89 ) {
case V_96 :
case V_94 :
case V_95 :
F_77 ( V_108 ) ;
break;
case V_97 :
case V_98 :
case V_99 :
F_78 ( V_108 ) ;
if ( V_89 == V_98 )
F_19 ( V_12 , V_7 , false ) ;
break;
default:
return - V_41 ;
}
return 0 ;
}
static int F_79 ( struct V_2 * V_3 ,
struct V_24 * V_25 )
{
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_109 * V_110 = F_71 ( V_3 ) ;
struct V_1 * V_108 =
F_49 ( V_25 , V_3 ) ;
struct V_47 * V_48 ;
F_21 ( V_25 -> V_27 , L_2 , V_59 , V_25 -> V_60 ) ;
V_108 -> V_54 = 0 ;
V_48 = F_72 ( V_12 , V_110 -> V_113 -> V_114 . V_60 ) ;
if ( ! V_48 )
return - V_41 ;
F_80 ( V_48 , V_8 ( V_108 ) -> V_53 ) ;
F_48 ( V_108 , V_112 ) ;
return 0 ;
}
static int F_81 ( struct V_2 * V_3 )
{
struct V_109 * V_110 = V_3 -> V_5 ;
struct V_116 * V_117 = V_110 -> V_117 ;
F_21 ( V_110 -> V_118 -> V_27 , L_8 , V_59 ,
V_117 -> V_119 ) ;
F_82 ( V_3 , & V_120 ) ;
return 0 ;
}
static int F_83 ( struct V_2 * V_3 ,
int V_89 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
struct V_10 * V_11 = F_12 ( V_12 ) ;
struct V_1 * V_7 ;
struct V_2 * V_121 ;
bool V_90 ;
int V_122 = 0 ;
unsigned long V_91 ;
struct V_8 * V_92 ;
V_7 = F_1 ( V_3 ) ;
V_92 = V_8 ( V_7 ) ;
F_21 ( V_11 -> V_27 , L_7 , V_59 , V_89 ) ;
if ( ! V_92 -> V_46 )
return - V_93 ;
switch ( V_89 ) {
case V_94 :
case V_95 :
case V_96 :
V_90 = true ;
break;
case V_97 :
case V_98 :
case V_99 :
V_90 = false ;
break;
default:
return - V_41 ;
}
F_84 (s, substream) {
if ( V_121 -> V_123 -> V_124 != V_3 -> V_123 -> V_124 )
continue;
V_7 = F_1 ( V_121 ) ;
V_122 |= 1 << V_8 ( V_7 ) -> V_51 ;
F_85 ( V_121 , V_3 ) ;
}
F_57 ( & V_11 -> V_100 , V_91 ) ;
F_86 ( V_92 , true , V_122 , V_125 ) ;
F_84 (s, substream) {
if ( V_121 -> V_123 -> V_124 != V_3 -> V_123 -> V_124 )
continue;
V_7 = F_1 ( V_121 ) ;
if ( V_90 )
F_58 ( V_8 ( V_7 ) , true ) ;
else
F_60 ( V_8 ( V_7 ) ) ;
}
F_61 ( & V_11 -> V_100 , V_91 ) ;
F_87 ( V_92 , V_90 , V_122 ) ;
F_57 ( & V_11 -> V_100 , V_91 ) ;
F_86 ( V_92 , false , V_122 , V_125 ) ;
if ( V_90 )
F_59 ( V_92 , V_122 ) ;
F_61 ( & V_11 -> V_100 , V_91 ) ;
return 0 ;
}
static int F_88 ( struct V_2 * V_3 ,
int V_89 )
{
struct V_6 * V_12 = F_2 ( V_3 ) ;
if ( ! ( F_12 ( V_12 ) ) -> V_21 )
return F_83 ( V_3 , V_89 ) ;
return 0 ;
}
static T_2 F_89
( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
struct V_6 * V_12 = F_2 ( V_3 ) ;
unsigned int V_126 ;
if ( V_3 -> V_7 == V_31 ) {
V_126 = F_68 ( V_12 -> V_11 . V_105 + V_106 +
( V_107 *
V_8 ( V_9 ) -> V_51 ) ) ;
} else {
F_90 ( 20 ) ;
F_68 ( V_12 -> V_11 . V_105 +
V_106 +
( V_107 *
V_8 ( V_9 ) -> V_51 ) ) ;
V_126 = F_91 ( V_8 ( V_9 ) ) ;
}
if ( V_126 >= V_8 ( V_9 ) -> V_14 )
V_126 = 0 ;
return F_92 ( V_3 -> V_4 , V_126 ) ;
}
static T_3 F_93 ( struct V_2 * V_3 ,
T_3 V_127 )
{
struct V_109 * V_110 = F_71 ( V_3 ) ;
struct V_24 * V_111 = V_110 -> V_111 ;
T_3 V_128 , V_129 ;
if ( ! V_111 -> V_83 -> V_130 -> V_131 )
return V_127 ;
V_128 = V_111 -> V_83 -> V_130 -> V_131 ( V_3 , V_111 ) ;
V_129 = F_94 ( V_128 * 1000000000LL ,
V_3 -> V_4 -> V_80 ) ;
if ( V_3 -> V_7 == V_62 )
return V_127 + V_129 ;
return ( V_127 > V_129 ) ? V_127 - V_129 : 0 ;
}
static int F_95 ( struct V_2 * V_3 ,
struct V_132 * V_133 , struct V_132 * V_134 ,
struct V_135 * V_136 ,
struct V_137 * V_138 )
{
struct V_1 * V_139 = F_1 ( V_3 ) ;
struct V_8 * V_92 = V_8 ( V_139 ) ;
T_3 V_127 ;
if ( ( V_3 -> V_4 -> V_63 . V_64 & V_66 ) &&
( V_136 -> V_140 == V_141 ) ) {
F_96 ( V_3 -> V_4 , V_133 ) ;
V_127 = F_97 ( & V_92 -> V_142 ) ;
V_127 = F_94 ( V_127 , 3 ) ;
if ( V_136 -> V_143 )
V_127 = F_93 ( V_3 , V_127 ) ;
* V_134 = F_98 ( V_127 ) ;
V_138 -> V_144 = V_141 ;
V_138 -> V_145 = 1 ;
V_138 -> V_146 = 42 ;
} else {
V_138 -> V_144 = V_147 ;
}
return 0 ;
}
static void F_99 ( struct V_148 * V_123 )
{
F_100 ( V_123 ) ;
}
static int F_101 ( struct V_109 * V_110 )
{
struct V_24 * V_25 = V_110 -> V_118 ;
struct V_6 * V_12 = F_14 ( V_25 -> V_27 ) ;
struct V_148 * V_123 = V_110 -> V_123 ;
unsigned int V_13 ;
int V_149 = 0 ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
if ( V_25 -> V_83 -> V_84 . V_150 ||
V_25 -> V_83 -> V_86 . V_150 ) {
V_13 = V_151 * 1024 ;
if ( V_13 > V_152 )
V_13 = V_152 ;
V_149 = F_102 ( V_123 ,
V_153 ,
F_103 ( V_30 -> V_154 ) ,
V_13 , V_152 ) ;
if ( V_149 ) {
F_104 ( V_25 -> V_27 , L_9 ) ;
return V_149 ;
}
}
return V_149 ;
}
static int F_105 ( struct V_30 * V_30 , struct V_57 * V_58 )
{
struct V_73 * V_101 = V_30 -> V_73 ;
struct V_155 * V_156 ;
T_4 * V_157 ;
V_157 = ( T_4 * ) V_58 -> V_158 ;
if ( F_106 ( & V_101 -> V_159 ) ) {
F_104 ( V_101 -> V_27 , L_10 ) ;
return - V_102 ;
}
F_28 (module, &ctx->uuid_list, list) {
if ( F_107 ( * V_157 , V_156 -> V_160 ) == 0 ) {
V_58 -> V_161 . V_162 = V_156 -> V_161 ;
V_58 -> V_163 = V_156 -> V_163 ;
return 0 ;
}
}
return - V_102 ;
}
static int F_108 ( struct V_30 * V_30 )
{
struct V_164 * V_165 ;
struct V_166 * V_167 ;
struct V_28 * V_29 ;
struct V_57 * V_58 ;
int V_78 = 0 ;
F_28 (p, &skl->ppl_list, node) {
F_28 (m, &p->pipe->w_list, node) {
V_29 = V_167 -> V_29 ;
V_58 = V_29 -> V_168 ;
V_78 = F_105 ( V_30 , V_58 ) ;
if ( V_78 < 0 ) {
F_104 ( V_30 -> V_73 -> V_27 ,
L_11 ) ;
return V_78 ;
}
}
}
return V_78 ;
}
static int F_109 ( struct V_169 * V_170 )
{
struct V_6 * V_12 = F_14 ( V_170 -> V_27 ) ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
const struct V_171 * V_130 ;
int V_78 ;
F_110 ( V_170 -> V_27 ) ;
if ( ( F_12 ( V_12 ) ) -> V_21 ) {
V_78 = F_111 ( V_170 , V_12 ) ;
if ( V_78 < 0 ) {
F_104 ( V_170 -> V_27 , L_12 ) ;
return V_78 ;
}
V_30 -> V_170 = V_170 ;
V_130 = F_112 ( V_30 -> V_154 -> V_36 ) ;
if ( ! V_130 )
return - V_102 ;
if ( V_30 -> V_73 -> V_172 == false ) {
F_104 ( V_170 -> V_27 , L_13 ) ;
return - V_102 ;
}
V_78 = V_130 -> V_173 ( V_170 -> V_27 , V_30 -> V_73 ) ;
if ( V_78 < 0 ) {
F_104 ( V_170 -> V_27 , L_14 , V_78 ) ;
return V_78 ;
}
F_108 ( V_30 ) ;
V_30 -> V_73 -> V_174 = V_175 ;
F_113 ( V_30 -> V_73 , false ) ;
}
F_114 ( V_170 -> V_27 ) ;
F_115 ( V_170 -> V_27 ) ;
return 0 ;
}
int F_116 ( struct V_36 * V_27 )
{
int V_78 ;
struct V_6 * V_12 = F_14 ( V_27 ) ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
F_117 ( & V_30 -> V_176 ) ;
F_117 ( & V_30 -> V_177 ) ;
V_78 = F_118 ( V_27 , & V_178 ) ;
if ( V_78 ) {
F_104 ( V_27 , L_15 , V_78 ) ;
return V_78 ;
}
V_78 = F_119 ( V_27 , & V_179 ,
V_180 ,
F_120 ( V_180 ) ) ;
if ( V_78 ) {
F_104 ( V_27 , L_16 , V_78 ) ;
F_121 ( V_27 ) ;
}
return V_78 ;
}
int F_122 ( struct V_36 * V_27 )
{
struct V_6 * V_12 = F_14 ( V_27 ) ;
struct V_30 * V_30 = F_15 ( V_12 ) ;
struct V_181 * V_182 , * V_183 ;
if ( ! F_106 ( & V_30 -> V_177 ) ) {
F_123 (modules, tmp, &skl->bind_list, node) {
F_124 ( & V_182 -> V_184 ) ;
F_51 ( V_182 ) ;
}
}
F_125 ( V_27 ) ;
F_121 ( V_27 ) ;
return 0 ;
}
