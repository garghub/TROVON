static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
const struct V_4 * V_5 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
const struct V_10 * V_11 ;
const int type = F_3 ( V_2 ) -> type ;
const int V_12 = F_3 ( V_2 ) -> V_12 ;
unsigned int V_13 = 0 ;
struct V_14 * V_15 ;
switch ( type ) {
default:
case V_16 :
return;
case V_17 :
switch ( V_12 ) {
case V_18 :
case V_19 :
return;
default:
break;
}
break;
case V_20 :
if ( V_12 != V_21 )
return;
V_13 = F_3 ( V_2 ) -> V_22 . V_23 [ 1 ] * 4 ;
break;
case V_24 :
break;
}
if ( V_5 -> V_25 == F_4 ( V_26 ) )
V_9 = F_5 ( V_6 , V_27 ) ;
else
V_9 = F_5 ( V_6 , V_28 ) ;
V_11 = ( const struct V_10 * ) ( F_3 ( V_2 ) + 1 ) ;
V_15 = F_6 ( V_9 , V_2 -> V_7 -> V_29 , V_5 -> V_30 ,
V_11 -> V_31 , V_11 -> V_32 , V_5 -> V_33 ) ;
if ( ! V_15 )
return;
#if F_7 ( V_34 )
if ( V_5 -> V_25 == F_4 ( V_35 ) &&
! F_8 ( V_2 , V_11 -> V_36 * 4 + V_5 -> V_37 ,
type , V_13 ) )
return;
#endif
if ( V_15 -> V_38 . V_11 . V_31 == 0 ||
F_9 ( V_15 -> V_38 . V_11 . V_31 ) )
return;
if ( V_15 -> V_38 . V_11 . V_39 == 0 && type == V_20 )
return;
if ( F_10 ( V_40 , V_15 -> V_41 + V_42 ) )
V_15 -> V_43 ++ ;
else
V_15 -> V_43 = 1 ;
V_15 -> V_41 = V_40 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 V_3 )
{
const struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_44 ;
const int type = F_3 ( V_2 ) -> type ;
const int V_12 = F_3 ( V_2 ) -> V_12 ;
struct V_4 V_5 ;
bool V_45 = false ;
if ( F_12 ( V_2 , & V_5 , & V_45 , F_4 ( V_46 ) ,
V_11 -> V_36 * 4 ) < 0 ) {
if ( ! V_45 )
return;
}
if ( type == V_17 && V_12 == V_47 ) {
F_13 ( V_2 , F_2 ( V_2 -> V_7 ) , V_3 ,
V_2 -> V_7 -> V_29 , 0 , V_48 , 0 ) ;
return;
}
if ( type == V_24 ) {
F_14 ( V_2 , F_2 ( V_2 -> V_7 ) , V_2 -> V_7 -> V_29 , 0 ,
V_48 , 0 ) ;
return;
}
F_1 ( V_2 , V_3 , & V_5 ) ;
}
static int F_15 ( struct V_1 * V_2 , struct V_4 * V_5 ,
int V_49 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_50 * V_51 = NULL ;
struct V_8 * V_9 ;
struct V_14 * V_52 ;
struct V_53 * V_54 ;
const struct V_10 * V_11 ;
T_2 V_55 ;
int V_56 ;
V_9 = F_5 ( V_6 , V_57 ) ;
V_56 = V_49 + sizeof( * V_54 ) ;
if ( F_16 ( ! F_17 ( V_2 , V_56 ) ) )
return - V_58 ;
V_11 = F_18 ( V_2 ) ;
V_54 = (struct V_53 * ) ( V_2 -> V_44 + V_49 ) ;
V_5 -> V_33 = F_19 ( F_20 ( V_54 -> V_59 ) & V_60 ) ;
V_55 = V_54 -> V_61 . V_55 ;
V_52 = F_6 ( V_9 , V_2 -> V_7 -> V_29 ,
V_5 -> V_30 | V_62 ,
V_11 -> V_32 , V_11 -> V_31 , V_5 -> V_33 ) ;
if ( V_52 ) {
if ( F_21 ( V_2 ,
V_49 + sizeof( * V_54 ) ,
F_4 ( V_26 ) ,
false , false ) < 0 )
goto V_63;
if ( V_52 -> V_64 ) {
struct V_65 * V_3 ;
struct V_66 * V_61 ;
T_3 V_67 ;
T_4 V_30 ;
V_5 -> V_30 |= V_62 ;
V_30 = V_5 -> V_30 ;
V_67 = F_22 ( V_5 -> V_33 ) ;
V_51 = F_23 ( V_2 , V_30 ,
V_67 , sizeof( * V_61 ) ) ;
if ( ! V_51 )
return V_68 ;
V_61 = F_24 ( & V_51 -> V_69 . V_70 ) ;
if ( ! V_61 )
return V_68 ;
V_61 -> V_55 = V_55 ;
V_3 = & V_51 -> V_69 . V_70 ;
V_3 -> V_33 . V_71 |= V_72 ;
V_3 -> V_73 = sizeof( * V_61 ) ;
} else {
V_52 -> V_55 = F_25 ( V_55 ) ;
}
F_26 ( V_2 ) ;
F_27 ( V_52 , V_2 , V_5 , V_51 , V_74 ) ;
return V_75 ;
}
V_63:
F_28 ( V_2 ) ;
return V_75 ;
}
static int F_29 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
struct V_8 * V_9 , int V_37 , bool V_76 )
{
struct V_50 * V_51 = NULL ;
const struct V_10 * V_11 ;
struct V_14 * V_52 ;
V_11 = F_18 ( V_2 ) ;
V_52 = F_6 ( V_9 , V_2 -> V_7 -> V_29 , V_5 -> V_30 ,
V_11 -> V_32 , V_11 -> V_31 , V_5 -> V_33 ) ;
if ( V_52 ) {
if ( F_21 ( V_2 , V_37 , V_5 -> V_25 ,
V_76 , false ) < 0 )
goto V_63;
if ( V_52 -> V_7 -> type != V_77 )
F_30 ( V_2 ) ;
else
F_26 ( V_2 ) ;
if ( V_52 -> V_64 ) {
T_4 V_30 ;
T_3 V_67 ;
V_30 = V_5 -> V_30 & ( V_78 | V_62 ) ;
V_67 = F_22 ( V_5 -> V_33 ) ;
V_51 = F_23 ( V_2 , V_30 , V_67 , 0 ) ;
if ( ! V_51 )
return V_68 ;
}
F_27 ( V_52 , V_2 , V_5 , V_51 , V_74 ) ;
return V_75 ;
}
return V_79 ;
V_63:
F_28 ( V_2 ) ;
return V_75 ;
}
static int F_31 ( struct V_1 * V_2 , const struct V_4 * V_5 ,
int V_37 )
{
struct V_6 * V_6 = F_2 ( V_2 -> V_7 ) ;
struct V_8 * V_9 ;
int V_80 ;
if ( V_5 -> V_25 == F_4 ( V_26 ) )
V_9 = F_5 ( V_6 , V_27 ) ;
else
V_9 = F_5 ( V_6 , V_28 ) ;
V_80 = F_29 ( V_2 , V_5 , V_9 , V_37 , false ) ;
if ( V_80 == V_79 && V_5 -> V_25 == F_4 ( V_26 ) ) {
V_9 = F_5 ( V_6 , V_28 ) ;
V_80 = F_29 ( V_2 , V_5 , V_9 , V_37 , true ) ;
}
return V_80 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_4 V_5 ;
bool V_45 = false ;
int V_37 ;
#ifdef F_33
if ( F_9 ( F_18 ( V_2 ) -> V_31 ) ) {
if ( F_34 ( F_35 ( V_2 ) ) )
goto V_63;
}
#endif
V_37 = F_12 ( V_2 , & V_5 , & V_45 , F_4 ( V_46 ) , 0 ) ;
if ( V_37 < 0 )
goto V_63;
if ( F_16 ( V_5 . V_25 == F_4 ( V_81 ) ) ) {
if ( F_15 ( V_2 , & V_5 , V_37 ) == V_75 )
return 0 ;
}
if ( F_31 ( V_2 , & V_5 , V_37 ) == V_75 )
return 0 ;
F_36 ( V_2 , V_17 , V_19 , 0 ) ;
V_63:
F_28 ( V_2 ) ;
return 0 ;
}
static void F_37 ( struct V_1 * V_2 , struct V_82 * V_7 ,
const struct V_10 * V_83 ,
T_4 V_25 )
{
struct V_14 * V_52 = F_38 ( V_7 ) ;
if ( V_52 -> V_38 . V_84 & V_85 )
V_52 -> V_86 ++ ;
F_39 ( V_2 , V_52 -> V_87 ,
V_52 -> V_38 . V_84 , V_25 , V_52 -> V_38 . V_88 ,
F_40 ( V_52 -> V_86 ) ) ;
F_41 ( V_2 , V_7 , V_83 , V_83 -> V_89 ) ;
}
static int F_42 ( struct V_1 * V_2 , bool V_90 )
{
return F_43 ( V_2 , V_90 ? V_91 : V_92 ) ;
}
static struct V_93 * F_44 ( struct V_1 * V_2 ,
struct V_82 * V_7 ,
struct V_94 * V_95 ,
const struct V_96 * V_33 )
{
struct V_6 * V_6 = F_2 ( V_7 ) ;
memset ( V_95 , 0 , sizeof( * V_95 ) ) ;
V_95 -> V_31 = V_33 -> V_69 . V_97 . V_98 ;
V_95 -> V_32 = V_33 -> V_69 . V_97 . V_99 ;
V_95 -> V_100 = F_45 ( V_33 -> V_101 ) ;
V_95 -> V_102 = V_2 -> V_103 ;
V_95 -> V_104 = V_48 ;
return F_46 ( V_6 , V_95 ) ;
}
static struct V_93 * F_47 ( struct V_1 * V_2 ,
struct V_82 * V_7 ,
struct V_94 * V_95 ,
int V_105 )
{
struct V_65 * V_70 ;
const struct V_96 * V_33 ;
struct V_93 * V_106 = NULL ;
int V_107 ;
bool V_108 ;
int V_109 ;
V_70 = F_48 ( V_2 ) ;
V_33 = & V_70 -> V_33 ;
V_108 = F_49 ( V_2 , V_70 ) ;
if ( V_108 )
V_106 = F_50 ( & V_70 -> V_110 , & V_95 -> V_32 ) ;
if ( ! V_106 ) {
V_106 = F_44 ( V_2 , V_7 , V_95 , V_33 ) ;
if ( F_51 ( V_106 ) )
goto V_111;
if ( V_108 )
F_52 ( & V_70 -> V_110 , & V_106 -> V_98 ,
V_95 -> V_32 ) ;
}
V_107 = F_53 ( V_106 -> V_98 . V_7 ) + V_106 -> V_98 . V_112
+ V_105 + sizeof( struct V_10 ) ;
if ( F_54 ( V_2 ) < V_107 || F_55 ( V_2 ) ) {
int V_113 = F_56 ( V_107 -
F_54 ( V_2 ) +
16 ) ;
V_109 = F_57 ( V_2 , F_58 ( int , V_113 , 0 ) ,
0 , V_114 ) ;
if ( F_16 ( V_109 ) )
goto V_115;
}
return V_106 ;
V_115:
F_59 ( V_106 ) ;
V_111:
F_28 ( V_2 ) ;
V_7 -> V_116 . V_117 ++ ;
return NULL ;
}
static void F_60 ( struct V_1 * V_2 , struct V_82 * V_7 ,
T_4 V_25 )
{
struct V_65 * V_70 ;
const struct V_96 * V_33 ;
struct V_93 * V_106 = NULL ;
struct V_94 V_95 ;
int V_105 ;
T_4 V_118 , V_30 ;
V_70 = F_48 ( V_2 ) ;
if ( F_16 ( ! V_70 || ! ( V_70 -> V_119 & V_120 ) ||
F_61 ( V_70 ) != V_121 ) )
goto V_111;
V_33 = & V_70 -> V_33 ;
V_105 = F_62 ( V_33 -> V_71 ) ;
V_106 = F_47 ( V_2 , V_7 , & V_95 , V_105 ) ;
if ( ! V_106 )
return;
if ( F_42 ( V_2 , ! ! ( V_70 -> V_33 . V_71 & V_78 ) ) )
goto V_115;
V_30 = V_70 -> V_33 . V_71 & ( V_78 | V_62 ) ;
F_39 ( V_2 , V_105 , V_30 , V_25 ,
F_63 ( V_70 -> V_33 . V_67 ) , 0 ) ;
V_118 = V_33 -> V_71 & V_122 ? F_4 ( V_123 ) : 0 ;
F_64 ( V_2 -> V_124 , V_106 , V_2 , V_95 . V_32 , V_33 -> V_69 . V_97 . V_98 , V_48 ,
V_33 -> V_101 , V_33 -> V_39 , V_118 , false ) ;
return;
V_115:
F_59 ( V_106 ) ;
V_111:
F_28 ( V_2 ) ;
V_7 -> V_116 . V_117 ++ ;
}
static void F_65 ( struct V_1 * V_2 , struct V_82 * V_7 ,
T_4 V_25 )
{
struct V_14 * V_52 = F_38 ( V_7 ) ;
struct V_65 * V_70 ;
const struct V_96 * V_33 ;
struct V_66 * V_61 ;
struct V_93 * V_106 = NULL ;
bool V_125 = false ;
struct V_94 V_95 ;
int V_105 ;
T_4 V_118 ;
V_70 = F_48 ( V_2 ) ;
if ( F_16 ( ! V_70 || ! ( V_70 -> V_119 & V_120 ) ||
F_61 ( V_70 ) != V_121 ) )
goto V_111;
V_33 = & V_70 -> V_33 ;
V_105 = 8 + sizeof( struct V_53 ) ;
V_106 = F_47 ( V_2 , V_7 , & V_95 , V_105 ) ;
if ( ! V_106 )
return;
if ( F_42 ( V_2 , false ) )
goto V_115;
if ( V_2 -> V_56 > V_7 -> V_126 ) {
F_66 ( V_2 , V_7 -> V_126 ) ;
V_125 = true ;
}
V_61 = F_24 ( V_70 ) ;
if ( ! V_61 )
goto V_115;
F_67 ( V_2 , F_63 ( V_33 -> V_67 ) ,
F_25 ( V_61 -> V_55 ) , V_125 ) ;
F_39 ( V_2 , 8 , V_85 ,
F_4 ( V_81 ) , 0 , F_40 ( V_52 -> V_86 ++ ) ) ;
V_118 = V_33 -> V_71 & V_122 ? F_4 ( V_123 ) : 0 ;
F_64 ( V_2 -> V_124 , V_106 , V_2 , V_95 . V_32 , V_33 -> V_69 . V_97 . V_98 , V_48 ,
V_33 -> V_101 , V_33 -> V_39 , V_118 , false ) ;
return;
V_115:
F_59 ( V_106 ) ;
V_111:
F_28 ( V_2 ) ;
V_7 -> V_116 . V_117 ++ ;
}
static int F_68 ( struct V_82 * V_7 , struct V_1 * V_2 )
{
struct V_65 * V_3 = F_48 ( V_2 ) ;
struct V_93 * V_106 ;
struct V_94 V_127 ;
if ( F_61 ( V_3 ) != V_121 )
return - V_128 ;
V_106 = F_44 ( V_2 , V_7 , & V_127 , & V_3 -> V_33 ) ;
if ( F_51 ( V_106 ) )
return F_69 ( V_106 ) ;
F_59 ( V_106 ) ;
V_3 -> V_33 . V_69 . V_97 . V_99 = V_127 . V_32 ;
return 0 ;
}
static T_5 F_70 ( struct V_1 * V_2 ,
struct V_82 * V_7 )
{
struct V_14 * V_52 = F_38 ( V_7 ) ;
const struct V_10 * V_83 ;
if ( V_52 -> V_64 ) {
F_60 ( V_2 , V_7 , V_2 -> V_89 ) ;
return V_129 ;
}
if ( V_7 -> V_130 ) {
if ( F_71 ( V_2 , V_7 -> V_131 -
( V_52 -> V_132 + sizeof( struct V_10 ) ) ) )
goto V_133;
V_83 = ( const struct V_10 * ) V_2 -> V_44 ;
F_72 ( V_2 , V_52 -> V_132 + sizeof( struct V_10 ) ) ;
F_26 ( V_2 ) ;
} else {
if ( F_71 ( V_2 , V_7 -> V_131 ) )
goto V_133;
V_83 = & V_52 -> V_38 . V_11 ;
}
if ( F_42 ( V_2 , ! ! ( V_52 -> V_38 . V_84 & V_78 ) ) )
goto V_133;
F_37 ( V_2 , V_7 , V_83 , V_2 -> V_89 ) ;
return V_129 ;
V_133:
F_28 ( V_2 ) ;
V_7 -> V_116 . V_117 ++ ;
return V_129 ;
}
static inline T_6 F_73 ( T_6 V_101 )
{
T_6 V_134 , cos ;
V_134 = V_101 >> 2 ;
cos = V_134 >> 3 ;
return cos ;
}
static void F_67 ( struct V_1 * V_2 ,
T_2 V_135 , T_1 V_55 , bool V_125 )
{
struct V_10 * V_10 = F_18 ( V_2 ) ;
struct V_136 * V_137 = F_74 ( V_2 ) ;
enum V_138 V_139 ;
struct V_53 * V_54 ;
struct V_140 {
T_4 V_141 ;
T_4 V_142 ;
} * V_143 ;
T_7 V_144 = 0 ;
V_139 = V_145 ;
if ( V_137 -> V_146 == F_4 ( V_147 ) ) {
V_143 = (struct V_140 * ) ( V_2 -> V_44 + 2 * V_148 ) ;
V_144 = F_20 ( V_143 -> V_142 ) ;
V_139 = V_149 ;
}
F_75 ( V_2 , sizeof( * V_54 ) ) ;
V_54 = (struct V_53 * ) V_2 -> V_44 ;
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
V_54 -> V_150 = F_4 ( ( V_144 & V_151 ) |
( V_152 << V_153 ) ) ;
V_54 -> V_59 = F_4 ( ( T_7 ) ( F_25 ( V_135 ) & V_60 ) |
( ( F_73 ( V_10 -> V_101 ) << V_154 ) & V_155 ) |
( V_139 << V_156 & V_157 ) |
( ( V_125 << V_158 ) & V_159 ) ) ;
V_54 -> V_61 . V_55 = F_40 ( V_55 & V_160 ) ;
}
static T_5 F_76 ( struct V_1 * V_2 ,
struct V_82 * V_7 )
{
struct V_14 * V_52 = F_38 ( V_7 ) ;
bool V_125 = false ;
if ( V_52 -> V_64 ) {
F_65 ( V_2 , V_7 , V_2 -> V_89 ) ;
return V_129 ;
}
if ( F_42 ( V_2 , false ) )
goto V_133;
if ( F_71 ( V_2 , V_7 -> V_131 ) )
goto V_133;
if ( V_2 -> V_56 - V_7 -> V_161 > V_7 -> V_126 ) {
F_66 ( V_2 , V_7 -> V_126 ) ;
V_125 = true ;
}
F_67 ( V_2 , V_52 -> V_38 . V_88 , V_52 -> V_55 , V_125 ) ;
V_52 -> V_38 . V_84 &= ~ V_62 ;
F_37 ( V_2 , V_7 , & V_52 -> V_38 . V_11 , F_4 ( V_81 ) ) ;
return V_129 ;
V_133:
F_28 ( V_2 ) ;
V_7 -> V_116 . V_117 ++ ;
return V_129 ;
}
static T_5 F_77 ( struct V_1 * V_2 ,
struct V_82 * V_7 )
{
struct V_14 * V_52 = F_38 ( V_7 ) ;
if ( V_52 -> V_64 ) {
F_60 ( V_2 , V_7 , F_4 ( V_26 ) ) ;
return V_129 ;
}
if ( F_42 ( V_2 , ! ! ( V_52 -> V_38 . V_84 & V_78 ) ) )
goto V_133;
if ( F_71 ( V_2 , V_7 -> V_131 ) )
goto V_133;
F_37 ( V_2 , V_7 , & V_52 -> V_38 . V_11 , F_4 ( V_26 ) ) ;
return V_129 ;
V_133:
F_28 ( V_2 ) ;
V_7 -> V_116 . V_117 ++ ;
return V_129 ;
}
static int F_78 ( struct V_82 * V_7 ,
struct V_162 * V_163 , int V_164 )
{
int V_109 ;
struct V_165 V_166 ;
if ( F_79 ( & V_166 , V_163 -> V_167 . V_168 , sizeof( V_166 ) ) )
return - V_169 ;
if ( V_164 == V_170 || V_164 == V_171 ) {
if ( V_166 . V_11 . V_172 != 4 || V_166 . V_11 . V_89 != V_48 ||
V_166 . V_11 . V_36 != 5 || ( V_166 . V_11 . V_173 & F_4 ( ~ V_123 ) ) ||
( ( V_166 . V_174 | V_166 . V_84 ) & ( V_175 | V_176 ) ) )
return - V_128 ;
}
V_166 . V_174 = F_80 ( V_166 . V_174 ) ;
V_166 . V_84 = F_80 ( V_166 . V_84 ) ;
V_109 = F_81 ( V_7 , & V_166 , V_164 ) ;
if ( V_109 )
return V_109 ;
V_166 . V_174 = F_82 ( V_166 . V_174 ) ;
V_166 . V_84 = F_82 ( V_166 . V_84 ) ;
if ( F_83 ( V_163 -> V_167 . V_168 , & V_166 , sizeof( V_166 ) ) )
return - V_169 ;
return 0 ;
}
static int F_84 ( struct V_1 * V_2 , struct V_82 * V_7 ,
unsigned short type ,
const void * V_31 , const void * V_32 , unsigned int V_56 )
{
struct V_14 * V_15 = F_38 ( V_7 ) ;
struct V_10 * V_11 ;
struct V_177 * V_178 ;
V_11 = F_75 ( V_2 , V_15 -> V_132 + sizeof( * V_11 ) ) ;
V_178 = (struct V_177 * ) ( V_11 + 1 ) ;
V_178 -> V_30 = F_82 ( V_15 -> V_38 . V_84 ) ;
V_178 -> V_89 = F_4 ( type ) ;
memcpy ( V_11 , & V_15 -> V_38 . V_11 , sizeof( struct V_10 ) ) ;
if ( V_32 )
memcpy ( & V_11 -> V_32 , V_32 , 4 ) ;
if ( V_31 )
memcpy ( & V_11 -> V_31 , V_31 , 4 ) ;
if ( V_11 -> V_31 )
return V_15 -> V_132 + sizeof( * V_11 ) ;
return - ( V_15 -> V_132 + sizeof( * V_11 ) ) ;
}
static int F_85 ( const struct V_1 * V_2 , unsigned char * V_179 )
{
const struct V_10 * V_11 = ( const struct V_10 * ) F_86 ( V_2 ) ;
memcpy ( V_179 , & V_11 -> V_32 , 4 ) ;
return 4 ;
}
static int F_87 ( struct V_82 * V_7 )
{
struct V_14 * V_15 = F_38 ( V_7 ) ;
if ( F_9 ( V_15 -> V_38 . V_11 . V_31 ) ) {
struct V_94 V_127 ;
struct V_93 * V_106 ;
V_106 = F_88 ( V_15 -> V_6 , & V_127 ,
V_15 -> V_38 . V_11 . V_31 ,
V_15 -> V_38 . V_11 . V_32 ,
V_15 -> V_38 . V_88 ,
F_45 ( V_15 -> V_38 . V_11 . V_101 ) ,
V_15 -> V_38 . V_180 ) ;
if ( F_51 ( V_106 ) )
return - V_181 ;
V_7 = V_106 -> V_98 . V_7 ;
F_59 ( V_106 ) ;
if ( ! F_89 ( V_7 ) )
return - V_181 ;
V_15 -> V_182 = V_7 -> V_29 ;
F_90 ( F_89 ( V_7 ) , V_15 -> V_38 . V_11 . V_31 ) ;
}
return 0 ;
}
static int F_91 ( struct V_82 * V_7 )
{
struct V_14 * V_15 = F_38 ( V_7 ) ;
if ( F_9 ( V_15 -> V_38 . V_11 . V_31 ) && V_15 -> V_182 ) {
struct V_183 * V_184 ;
V_184 = F_92 ( V_15 -> V_6 , V_15 -> V_182 ) ;
if ( V_184 )
F_93 ( V_184 , V_15 -> V_38 . V_11 . V_31 ) ;
}
return 0 ;
}
static void F_94 ( struct V_82 * V_7 )
{
V_7 -> V_185 = & V_186 ;
V_7 -> type = V_187 ;
F_95 ( V_7 , V_28 ) ;
}
static void F_96 ( struct V_82 * V_7 )
{
struct V_14 * V_52 ;
int V_188 ;
V_52 = F_38 ( V_7 ) ;
V_52 -> V_87 = F_62 ( V_52 -> V_38 . V_84 ) ;
V_52 -> V_38 . V_11 . V_89 = V_48 ;
V_52 -> V_132 = V_52 -> V_87 + V_52 -> V_189 ;
V_188 = V_52 -> V_132 + sizeof( struct V_10 ) ;
V_7 -> V_131 = V_190 + V_188 + 4 ;
V_7 -> V_126 = V_191 - V_188 - 4 ;
V_7 -> V_192 |= V_193 ;
V_7 -> V_194 |= V_193 ;
if ( ! ( V_52 -> V_38 . V_84 & V_85 ) ) {
if ( ! ( V_52 -> V_38 . V_84 & V_78 ) ||
( V_52 -> V_195 . type == V_196 ) ) {
V_7 -> V_192 |= V_197 ;
V_7 -> V_194 |= V_197 ;
}
V_7 -> V_192 |= V_198 ;
}
}
static int F_97 ( struct V_82 * V_7 )
{
struct V_14 * V_52 = F_38 ( V_7 ) ;
struct V_10 * V_11 = & V_52 -> V_38 . V_11 ;
F_96 ( V_7 ) ;
memcpy ( V_7 -> V_199 , & V_11 -> V_32 , 4 ) ;
memcpy ( V_7 -> V_200 , & V_11 -> V_31 , 4 ) ;
V_7 -> V_30 = V_201 ;
F_98 ( V_7 ) ;
V_7 -> V_202 = 4 ;
if ( V_11 -> V_31 && ! V_52 -> V_64 ) {
#ifdef F_33
if ( F_9 ( V_11 -> V_31 ) ) {
if ( ! V_11 -> V_32 )
return - V_128 ;
V_7 -> V_30 = V_203 ;
V_7 -> V_130 = & V_204 ;
}
#endif
} else if ( ! V_52 -> V_64 ) {
V_7 -> V_130 = & V_204 ;
}
return F_99 ( V_7 ) ;
}
static int T_8 F_100 ( struct V_6 * V_6 )
{
return F_101 ( V_6 , V_28 , & V_205 , NULL ) ;
}
static void T_9 F_102 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_28 ) ;
F_103 ( V_9 , & V_205 ) ;
}
static int F_104 ( struct V_206 * V_207 [] , struct V_206 * V_44 [] ,
struct V_208 * V_209 )
{
T_4 V_30 ;
if ( ! V_44 )
return 0 ;
V_30 = 0 ;
if ( V_44 [ V_210 ] )
V_30 |= F_105 ( V_44 [ V_210 ] ) ;
if ( V_44 [ V_211 ] )
V_30 |= F_105 ( V_44 [ V_211 ] ) ;
if ( V_30 & ( V_175 | V_176 ) )
return - V_128 ;
if ( V_44 [ V_212 ] &&
V_44 [ V_213 ] &&
F_106 ( V_44 [ V_213 ] ) != V_196 )
return - V_128 ;
return 0 ;
}
static int F_107 ( struct V_206 * V_207 [] , struct V_206 * V_44 [] ,
struct V_208 * V_209 )
{
T_2 V_31 ;
if ( V_207 [ V_214 ] ) {
if ( F_108 ( V_207 [ V_214 ] ) != V_148 )
return - V_128 ;
if ( ! F_109 ( F_110 ( V_207 [ V_214 ] ) ) )
return - V_181 ;
}
if ( ! V_44 )
goto V_215;
if ( V_44 [ V_216 ] ) {
memcpy ( & V_31 , F_110 ( V_44 [ V_216 ] ) , 4 ) ;
if ( ! V_31 )
return - V_128 ;
}
V_215:
return F_104 ( V_207 , V_44 , V_209 ) ;
}
static int F_111 ( struct V_206 * V_207 [] , struct V_206 * V_44 [] ,
struct V_208 * V_209 )
{
T_4 V_30 = 0 ;
int V_217 ;
if ( ! V_44 )
return 0 ;
V_217 = F_107 ( V_207 , V_44 , V_209 ) ;
if ( V_217 )
return V_217 ;
if ( V_44 [ V_211 ] )
V_30 |= F_105 ( V_44 [ V_211 ] ) ;
if ( V_44 [ V_210 ] )
V_30 |= F_105 ( V_44 [ V_210 ] ) ;
if ( ! V_44 [ V_212 ] &&
V_30 != ( V_218 | V_219 ) )
return - V_128 ;
if ( V_44 [ V_220 ] &&
( F_25 ( F_112 ( V_44 [ V_220 ] ) ) & ~ V_60 ) )
return - V_128 ;
if ( V_44 [ V_221 ] &&
( F_25 ( F_112 ( V_44 [ V_221 ] ) ) & ~ V_60 ) )
return - V_128 ;
return 0 ;
}
static int F_113 ( struct V_82 * V_7 ,
struct V_206 * V_44 [] ,
struct V_206 * V_207 [] ,
struct V_165 * V_38 ,
T_10 * V_222 )
{
struct V_14 * V_15 = F_38 ( V_7 ) ;
memset ( V_38 , 0 , sizeof( * V_38 ) ) ;
V_38 -> V_11 . V_89 = V_48 ;
if ( ! V_44 )
return 0 ;
if ( V_44 [ V_223 ] )
V_38 -> V_180 = F_114 ( V_44 [ V_223 ] ) ;
if ( V_44 [ V_210 ] )
V_38 -> V_174 = F_80 ( F_105 ( V_44 [ V_210 ] ) ) ;
if ( V_44 [ V_211 ] )
V_38 -> V_84 = F_80 ( F_105 ( V_44 [ V_211 ] ) ) ;
if ( V_44 [ V_220 ] )
V_38 -> V_224 = F_112 ( V_44 [ V_220 ] ) ;
if ( V_44 [ V_221 ] )
V_38 -> V_88 = F_112 ( V_44 [ V_221 ] ) ;
if ( V_44 [ V_225 ] )
V_38 -> V_11 . V_32 = F_115 ( V_44 [ V_225 ] ) ;
if ( V_44 [ V_216 ] )
V_38 -> V_11 . V_31 = F_115 ( V_44 [ V_216 ] ) ;
if ( V_44 [ V_226 ] )
V_38 -> V_11 . V_39 = F_116 ( V_44 [ V_226 ] ) ;
if ( V_44 [ V_227 ] )
V_38 -> V_11 . V_101 = F_116 ( V_44 [ V_227 ] ) ;
if ( ! V_44 [ V_228 ] || F_116 ( V_44 [ V_228 ] ) ) {
if ( V_15 -> V_229 )
return - V_128 ;
V_38 -> V_11 . V_173 = F_4 ( V_123 ) ;
}
if ( V_44 [ V_212 ] ) {
V_15 -> V_64 = true ;
if ( V_7 -> type == V_187 )
V_7 -> type = V_77 ;
}
if ( V_44 [ V_230 ] ) {
if ( F_116 ( V_44 [ V_230 ] )
&& ( V_38 -> V_11 . V_173 & F_4 ( V_123 ) ) )
return - V_128 ;
V_15 -> V_229 = ! ! F_116 ( V_44 [ V_230 ] ) ;
}
if ( V_44 [ V_231 ] )
* V_222 = F_114 ( V_44 [ V_231 ] ) ;
if ( V_44 [ V_232 ] ) {
V_15 -> V_55 = F_114 ( V_44 [ V_232 ] ) ;
if ( V_15 -> V_55 & ~ V_160 )
return - V_128 ;
}
return 0 ;
}
static bool F_117 ( struct V_206 * V_44 [] ,
struct V_233 * V_234 )
{
bool V_217 = false ;
memset ( V_234 , 0 , sizeof( * V_234 ) ) ;
if ( ! V_44 )
return V_217 ;
if ( V_44 [ V_213 ] ) {
V_217 = true ;
V_234 -> type = F_106 ( V_44 [ V_213 ] ) ;
}
if ( V_44 [ V_235 ] ) {
V_217 = true ;
V_234 -> V_30 = F_106 ( V_44 [ V_235 ] ) ;
}
if ( V_44 [ V_236 ] ) {
V_217 = true ;
V_234 -> V_237 = F_105 ( V_44 [ V_236 ] ) ;
}
if ( V_44 [ V_238 ] ) {
V_217 = true ;
V_234 -> V_239 = F_105 ( V_44 [ V_238 ] ) ;
}
return V_217 ;
}
static int F_118 ( struct V_82 * V_7 )
{
F_96 ( V_7 ) ;
V_7 -> V_240 |= V_241 ;
F_98 ( V_7 ) ;
return F_99 ( V_7 ) ;
}
static int F_119 ( struct V_82 * V_7 )
{
struct V_14 * V_52 = F_38 ( V_7 ) ;
int V_188 ;
V_52 -> V_87 = 8 ;
V_52 -> V_38 . V_11 . V_89 = V_48 ;
V_52 -> V_132 = V_52 -> V_87 + V_52 -> V_189 +
sizeof( struct V_53 ) ;
V_188 = V_52 -> V_132 + sizeof( struct V_10 ) ;
V_7 -> V_131 = V_190 + V_188 + 4 ;
V_7 -> V_126 = V_191 - V_188 - 4 ;
V_7 -> V_192 |= V_193 ;
V_7 -> V_194 |= V_193 ;
V_7 -> V_240 |= V_241 ;
F_98 ( V_7 ) ;
return F_99 ( V_7 ) ;
}
static void F_120 ( struct V_82 * V_7 )
{
F_121 ( V_7 ) ;
V_7 -> V_185 = & V_242 ;
V_7 -> V_240 &= ~ V_243 ;
V_7 -> V_240 |= V_241 ;
F_95 ( V_7 , V_27 ) ;
}
static int F_122 ( struct V_6 * V_244 , struct V_82 * V_7 ,
struct V_206 * V_207 [] , struct V_206 * V_44 [] ,
struct V_208 * V_209 )
{
struct V_165 V_166 ;
struct V_233 V_234 ;
T_10 V_222 = 0 ;
int V_109 ;
if ( F_117 ( V_44 , & V_234 ) ) {
struct V_14 * V_15 = F_38 ( V_7 ) ;
V_109 = F_123 ( V_15 , & V_234 ) ;
if ( V_109 < 0 )
return V_109 ;
}
V_109 = F_113 ( V_7 , V_44 , V_207 , & V_166 , & V_222 ) ;
if ( V_109 < 0 )
return V_109 ;
return F_124 ( V_7 , V_207 , & V_166 , V_222 ) ;
}
static int F_125 ( struct V_82 * V_7 , struct V_206 * V_207 [] ,
struct V_206 * V_44 [] ,
struct V_208 * V_209 )
{
struct V_14 * V_15 = F_38 ( V_7 ) ;
struct V_165 V_166 ;
struct V_233 V_234 ;
T_10 V_222 = V_15 -> V_222 ;
int V_109 ;
if ( F_117 ( V_44 , & V_234 ) ) {
V_109 = F_123 ( V_15 , & V_234 ) ;
if ( V_109 < 0 )
return V_109 ;
}
V_109 = F_113 ( V_7 , V_44 , V_207 , & V_166 , & V_222 ) ;
if ( V_109 < 0 )
return V_109 ;
return F_126 ( V_7 , V_207 , & V_166 , V_222 ) ;
}
static T_11 F_127 ( const struct V_82 * V_7 )
{
return
F_128 ( 4 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
F_128 ( 4 ) +
F_128 ( 4 ) +
F_128 ( 4 ) +
F_128 ( 4 ) +
F_128 ( 1 ) +
F_128 ( 1 ) +
F_128 ( 1 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
F_128 ( 2 ) +
F_128 ( 0 ) +
F_128 ( 1 ) +
F_128 ( 4 ) +
F_128 ( 4 ) +
0 ;
}
static int F_129 ( struct V_1 * V_2 , const struct V_82 * V_7 )
{
struct V_14 * V_15 = F_38 ( V_7 ) ;
struct V_165 * V_166 = & V_15 -> V_38 ;
if ( F_130 ( V_2 , V_223 , V_166 -> V_180 ) ||
F_131 ( V_2 , V_210 ,
F_82 ( V_166 -> V_174 ) ) ||
F_131 ( V_2 , V_211 ,
F_82 ( V_166 -> V_84 ) ) ||
F_132 ( V_2 , V_220 , V_166 -> V_224 ) ||
F_132 ( V_2 , V_221 , V_166 -> V_88 ) ||
F_133 ( V_2 , V_225 , V_166 -> V_11 . V_32 ) ||
F_133 ( V_2 , V_216 , V_166 -> V_11 . V_31 ) ||
F_134 ( V_2 , V_226 , V_166 -> V_11 . V_39 ) ||
F_134 ( V_2 , V_227 , V_166 -> V_11 . V_101 ) ||
F_134 ( V_2 , V_228 ,
! ! ( V_166 -> V_11 . V_173 & F_4 ( V_123 ) ) ) ||
F_130 ( V_2 , V_231 , V_15 -> V_222 ) )
goto V_245;
if ( F_135 ( V_2 , V_213 ,
V_15 -> V_195 . type ) ||
F_131 ( V_2 , V_236 ,
V_15 -> V_195 . V_237 ) ||
F_131 ( V_2 , V_238 ,
V_15 -> V_195 . V_239 ) ||
F_135 ( V_2 , V_235 ,
V_15 -> V_195 . V_30 ) )
goto V_245;
if ( F_134 ( V_2 , V_230 , V_15 -> V_229 ) )
goto V_245;
if ( V_15 -> V_64 ) {
if ( F_136 ( V_2 , V_212 ) )
goto V_245;
}
if ( V_15 -> V_55 )
if ( F_130 ( V_2 , V_232 , V_15 -> V_55 ) )
goto V_245;
return 0 ;
V_245:
return - V_246 ;
}
static void F_137 ( struct V_82 * V_7 )
{
F_121 ( V_7 ) ;
V_7 -> V_185 = & V_247 ;
V_7 -> V_240 &= ~ V_243 ;
V_7 -> V_240 |= V_241 ;
F_95 ( V_7 , V_57 ) ;
}
struct V_82 * F_138 ( struct V_6 * V_6 , const char * V_248 ,
T_6 V_249 )
{
struct V_206 * V_207 [ V_250 + 1 ] ;
struct V_82 * V_7 ;
F_139 ( V_251 ) ;
struct V_14 * V_15 ;
int V_109 ;
memset ( & V_207 , 0 , sizeof( V_207 ) ) ;
V_7 = F_140 ( V_6 , V_248 , V_249 ,
& V_252 , V_207 ) ;
if ( F_51 ( V_7 ) )
return V_7 ;
V_15 = F_38 ( V_7 ) ;
V_15 -> V_64 = true ;
V_109 = F_122 ( V_6 , V_7 , V_207 , NULL , NULL ) ;
if ( V_109 < 0 ) {
F_141 ( V_7 ) ;
return F_142 ( V_109 ) ;
}
V_109 = F_143 ( V_7 , V_253 , false ) ;
if ( V_109 )
goto V_215;
V_109 = F_144 ( V_7 , NULL ) ;
if ( V_109 < 0 )
goto V_215;
return V_7 ;
V_215:
F_145 ( V_7 , & V_251 ) ;
F_146 ( & V_251 ) ;
return F_142 ( V_109 ) ;
}
static int T_8 F_147 ( struct V_6 * V_6 )
{
return F_101 ( V_6 , V_27 , & V_252 , L_1 ) ;
}
static void T_9 F_148 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_27 ) ;
F_103 ( V_9 , & V_252 ) ;
}
static int T_8 F_149 ( struct V_6 * V_6 )
{
return F_101 ( V_6 , V_57 ,
& V_254 , L_2 ) ;
}
static void T_9 F_150 ( struct V_6 * V_6 )
{
struct V_8 * V_9 = F_5 ( V_6 , V_57 ) ;
F_103 ( V_9 , & V_254 ) ;
}
static int T_12 F_151 ( void )
{
int V_109 ;
F_152 ( L_3 ) ;
V_109 = F_153 ( & V_255 ) ;
if ( V_109 < 0 )
return V_109 ;
V_109 = F_153 ( & V_256 ) ;
if ( V_109 < 0 )
goto V_257;
V_109 = F_153 ( & V_258 ) ;
if ( V_109 < 0 )
goto V_259;
V_109 = F_154 ( & V_260 , V_261 ) ;
if ( V_109 < 0 ) {
F_152 ( L_4 , V_262 ) ;
goto V_263;
}
V_109 = F_155 ( & V_205 ) ;
if ( V_109 < 0 )
goto V_264;
V_109 = F_155 ( & V_252 ) ;
if ( V_109 < 0 )
goto V_265;
V_109 = F_155 ( & V_254 ) ;
if ( V_109 < 0 )
goto V_266;
return 0 ;
V_266:
F_156 ( & V_252 ) ;
V_265:
F_156 ( & V_205 ) ;
V_264:
F_157 ( & V_260 , V_261 ) ;
V_263:
F_158 ( & V_258 ) ;
V_259:
F_158 ( & V_256 ) ;
V_257:
F_158 ( & V_255 ) ;
return V_109 ;
}
static void T_13 F_159 ( void )
{
F_156 ( & V_252 ) ;
F_156 ( & V_205 ) ;
F_156 ( & V_254 ) ;
F_157 ( & V_260 , V_261 ) ;
F_158 ( & V_256 ) ;
F_158 ( & V_255 ) ;
F_158 ( & V_258 ) ;
}
