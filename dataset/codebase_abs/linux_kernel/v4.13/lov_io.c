static inline void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 ++ ;
}
static inline void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 -- ;
}
static void F_3 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
if ( V_2 -> V_9 ) {
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
V_2 -> V_9 = 0 ;
V_7 -> V_11 -- ;
}
if ( V_2 -> V_12 == V_7 -> V_13 )
V_7 -> V_13 = - 1 ;
else if ( ! V_2 -> V_14 )
F_5 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
}
if ( ! F_6 ( V_2 -> V_10 ) ) {
if ( ! V_2 -> V_14 )
F_7 ( V_2 -> V_10 , & V_2 -> V_15 ) ;
V_2 -> V_10 = NULL ;
}
}
static void F_8 ( struct V_16 * V_17 , struct V_6 * V_7 ,
int V_18 , T_1 V_19 , T_1 V_20 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
switch ( V_17 -> V_28 ) {
case V_29 : {
V_17 -> V_30 . V_31 . V_32 = V_25 -> V_30 . V_31 . V_32 ;
V_17 -> V_30 . V_31 . V_33 =
V_25 -> V_30 . V_31 . V_33 ;
V_17 -> V_30 . V_31 . V_34 = V_25 -> V_30 . V_31 . V_34 ;
V_17 -> V_30 . V_31 . V_35 = V_18 ;
V_17 -> V_30 . V_31 . V_36 =
V_25 -> V_30 . V_31 . V_36 ;
if ( F_9 ( V_17 ) ) {
T_1 V_37 = V_25 -> V_30 . V_31 . V_32 . V_38 ;
V_37 = F_10 ( V_22 , V_37 , V_18 ) ;
V_17 -> V_30 . V_31 . V_32 . V_38 = V_37 ;
}
break;
}
case V_39 : {
V_17 -> V_30 . V_40 . V_41 = 0 ;
V_17 -> V_30 . V_40 . V_42 =
V_25 -> V_30 . V_40 . V_42 ;
break;
}
case V_43 : {
struct V_44 * V_45 = V_25 -> V_46 ;
T_1 V_47 = F_11 ( V_45 , V_25 -> V_30 . V_48 . V_49 ) ;
V_17 -> V_30 . V_48 = V_25 -> V_30 . V_48 ;
V_47 = F_10 ( V_22 , V_47 , V_18 ) ;
V_17 -> V_30 . V_48 . V_49 = F_12 ( V_45 , V_47 ) ;
break;
}
case V_50 : {
V_17 -> V_30 . V_51 . V_52 = V_19 ;
V_17 -> V_30 . V_51 . V_53 = V_20 ;
V_17 -> V_30 . V_51 . V_54 = V_25 -> V_30 . V_51 . V_54 ;
V_17 -> V_30 . V_51 . V_55 = V_25 -> V_30 . V_51 . V_55 ;
break;
}
case V_56 :
case V_57 : {
V_17 -> V_30 . V_58 . V_59 = F_13 ( V_25 ) ;
if ( F_14 ( V_25 ) ) {
V_17 -> V_30 . V_58 . V_60 = 1 ;
} else {
V_17 -> V_30 . V_61 . V_62 = V_19 ;
V_17 -> V_30 . V_61 . V_63 = V_20 - V_19 ;
}
break;
}
default:
break;
}
}
static int F_15 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_1 * V_2 )
{
struct V_64 * V_65 = V_7 -> V_23 ;
struct V_66 * V_67 = F_16 ( F_17 ( V_65 ) -> V_68 . V_69 ) ;
struct V_16 * V_8 ;
struct V_44 * V_70 ;
struct V_16 * V_17 = V_7 -> V_26 . V_27 ;
int V_18 = V_2 -> V_12 ;
int V_71 ;
F_18 ( ! V_2 -> V_8 ) ;
F_18 ( ! V_2 -> V_10 ) ;
F_18 ( V_2 -> V_12 < V_7 -> V_72 ) ;
if ( F_19 ( ! F_20 ( V_65 ) -> V_73 [ V_18 ] ) )
return - V_74 ;
V_71 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_14 = 0 ;
if ( V_7 -> V_75 ) {
F_18 ( F_21 ( & V_67 -> V_76 ) ) ;
V_2 -> V_8 = & V_67 -> V_77 [ V_18 ] -> V_78 ;
V_2 -> V_10 = V_67 -> V_77 [ V_18 ] -> V_79 ;
V_2 -> V_14 = 1 ;
} else {
V_2 -> V_10 = F_22 ( & V_2 -> V_15 ) ;
if ( F_23 ( V_2 -> V_10 ) )
V_71 = F_24 ( V_2 -> V_10 ) ;
if ( V_71 == 0 ) {
if ( V_7 -> V_11 == 0 ) {
V_2 -> V_8 = & V_7 -> V_80 ;
V_7 -> V_13 = V_18 ;
} else {
V_2 -> V_8 = F_25 ( sizeof( * V_2 -> V_8 ) ,
V_81 ) ;
if ( ! V_2 -> V_8 )
V_71 = - V_82 ;
}
}
}
if ( V_71 == 0 ) {
V_70 = F_26 ( F_20 ( V_65 ) -> V_73 [ V_18 ] ) ;
V_8 = V_2 -> V_8 ;
V_8 -> V_46 = V_70 ;
V_8 -> V_83 = 0 ;
V_8 -> V_84 = V_17 ;
V_8 -> V_85 = V_17 -> V_85 ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_86 = V_17 -> V_86 ;
V_8 -> V_87 = V_17 -> V_87 ;
F_1 ( V_2 ) ;
V_71 = F_27 ( V_2 -> V_10 , V_8 ,
V_17 -> V_28 , V_70 ) ;
F_2 ( V_2 ) ;
if ( V_71 >= 0 ) {
V_7 -> V_11 ++ ;
V_2 -> V_9 = 1 ;
V_71 = 0 ;
}
}
if ( V_71 != 0 )
F_3 ( V_5 , V_7 , V_2 ) ;
return V_71 ;
}
struct V_1 * F_28 ( const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_18 )
{
int V_88 ;
struct V_1 * V_2 = & V_7 -> V_89 [ V_18 ] ;
F_18 ( V_18 < V_7 -> V_72 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_12 = V_18 ;
V_88 = F_15 ( V_5 , V_7 , V_2 ) ;
} else {
V_88 = 0 ;
}
if ( V_88 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_29 ( V_88 ) ;
return V_2 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
int F_31 ( const struct V_90 * V_91 )
{
const struct V_92 * V_93 ;
V_93 = F_32 ( V_91 , & V_94 ) ;
F_18 ( V_93 -> V_95 ) ;
return F_33 ( V_93 ) -> V_96 ;
}
struct V_1 * F_34 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_92 * V_93 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_90 * V_91 = V_93 -> V_97 ;
int V_18 ;
F_18 ( V_7 -> V_26 . V_27 ) ;
F_18 ( F_35 ( V_93 -> V_95 ) == V_7 -> V_23 ) ;
F_18 ( V_22 ) ;
F_18 ( V_7 -> V_98 > 0 ) ;
V_18 = F_31 ( V_91 ) ;
return F_28 ( V_5 , V_7 , V_18 ) ;
}
static int F_36 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 ;
int V_71 ;
F_18 ( V_7 -> V_23 ) ;
V_22 = V_7 -> V_23 -> V_24 ;
V_7 -> V_89 =
F_37 ( V_22 -> V_99 *
sizeof( V_7 -> V_89 [ 0 ] ) ,
V_81 ) ;
if ( V_7 -> V_89 ) {
V_7 -> V_98 = V_7 -> V_72 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_11 = 0 ;
V_71 = 0 ;
} else {
V_71 = - V_82 ;
}
return V_71 ;
}
static int F_38 ( struct V_6 * V_7 , struct V_64 * V_45 ,
struct V_16 * V_17 )
{
V_17 -> V_83 = 0 ;
V_7 -> V_23 = V_45 ;
V_7 -> V_72 = V_45 -> V_24 -> V_99 ;
switch ( V_17 -> V_28 ) {
case V_56 :
case V_57 :
V_7 -> V_100 = V_17 -> V_30 . V_61 . V_62 ;
V_7 -> V_101 = V_17 -> V_30 . V_61 . V_62 + V_17 -> V_30 . V_61 . V_63 ;
V_7 -> V_102 = V_7 -> V_101 ;
if ( F_14 ( V_17 ) ) {
F_18 ( V_17 -> V_28 == V_57 ) ;
if ( F_19 ( V_45 -> V_24 -> V_103 &
V_104 ) )
return - V_74 ;
V_7 -> V_100 = 0 ;
V_7 -> V_101 = V_105 ;
}
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_7 -> V_100 = V_17 -> V_30 . V_31 . V_32 . V_38 ;
else
V_7 -> V_100 = 0 ;
V_7 -> V_101 = V_105 ;
break;
case V_39 :
V_7 -> V_100 = 0 ;
V_7 -> V_101 = V_105 ;
break;
case V_43 : {
T_2 V_106 = V_17 -> V_30 . V_48 . V_49 ;
V_7 -> V_100 = F_11 ( V_17 -> V_46 , V_106 ) ;
V_7 -> V_101 = F_11 ( V_17 -> V_46 , V_106 + 1 ) ;
break;
}
case V_50 : {
V_7 -> V_100 = V_17 -> V_30 . V_51 . V_52 ;
V_7 -> V_101 = V_17 -> V_30 . V_51 . V_53 ;
break;
}
case V_107 :
V_7 -> V_100 = 0 ;
V_7 -> V_101 = V_105 ;
break;
default:
F_39 () ;
}
return 0 ;
}
static void F_40 ( const struct V_4 * V_5 , const struct V_108 * V_109 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_64 * V_65 = F_35 ( V_109 -> V_110 ) ;
int V_111 ;
if ( V_7 -> V_89 ) {
for ( V_111 = 0 ; V_111 < V_7 -> V_98 ; V_111 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_89 [ V_111 ] ) ;
F_42 ( V_7 -> V_89 ) ;
V_7 -> V_98 = 0 ;
}
F_18 ( F_43 ( & V_65 -> V_112 ) > 0 ) ;
if ( F_44 ( & V_65 -> V_112 ) )
F_45 ( & V_65 -> V_113 ) ;
}
static T_3 F_46 ( T_3 V_114 , int V_115 )
{
if ( V_114 != V_105 )
V_114 += V_115 ;
return V_114 ;
}
static int F_47 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_1 * V_2 ;
T_3 V_116 ;
T_3 V_19 ;
T_3 V_20 ;
int V_18 ;
int V_88 = 0 ;
V_116 = F_46 ( V_7 -> V_101 , - 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_72 ; V_18 ++ ) {
if ( ! F_48 ( V_22 , V_18 , V_7 -> V_100 ,
V_116 , & V_19 , & V_20 ) )
continue;
if ( F_19 ( ! F_20 ( V_7 -> V_23 ) -> V_73 [ V_18 ] ) ) {
if ( V_109 -> V_27 -> V_28 == V_56 ||
V_109 -> V_27 -> V_28 == V_57 ||
V_109 -> V_27 -> V_28 == V_43 )
return - V_74 ;
continue;
}
V_20 = F_46 ( V_20 , 1 ) ;
V_2 = F_28 ( V_5 , V_7 , V_18 ) ;
if ( F_23 ( V_2 ) ) {
V_88 = F_24 ( V_2 ) ;
break;
}
F_8 ( V_2 -> V_8 , V_7 , V_18 , V_19 , V_20 ) ;
V_88 = F_49 ( V_2 -> V_10 , V_2 -> V_8 ) ;
if ( V_88 )
F_50 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_30 ( V_2 ) ;
if ( V_88 )
break;
F_51 ( V_117 , L_1 ,
V_18 , V_19 , V_20 ) ;
F_52 ( & V_2 -> V_118 , & V_7 -> V_119 ) ;
}
return V_88 ;
}
static int F_53 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_16 * V_17 = V_109 -> V_27 ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
T_4 V_19 = V_17 -> V_30 . V_61 . V_62 ;
T_1 V_120 ;
unsigned long V_121 = V_22 -> V_122 ;
F_18 ( V_17 -> V_28 == V_56 || V_17 -> V_28 == V_57 ) ;
if ( V_7 -> V_98 != 1 && ! F_14 ( V_17 ) ) {
F_54 ( V_19 , V_121 ) ;
V_120 = ( V_19 + 1 ) * V_121 ;
if ( V_120 <= V_19 * V_121 )
V_120 = ~ 0ull ;
V_17 -> V_123 = V_120 < V_7 -> V_102 ;
V_17 -> V_30 . V_61 . V_63 = F_55 ( T_1 , V_7 -> V_102 ,
V_120 ) - V_17 -> V_30 . V_61 . V_62 ;
V_7 -> V_100 = V_17 -> V_30 . V_61 . V_62 ;
V_7 -> V_101 = V_17 -> V_30 . V_61 . V_62 + V_17 -> V_30 . V_61 . V_63 ;
F_51 ( V_117 , L_2 ,
( T_4 ) V_19 , V_7 -> V_100 , V_7 -> V_101 ,
( T_4 ) V_7 -> V_102 ) ;
}
return F_47 ( V_5 , V_109 ) ;
}
static int F_56 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_57)( const struct V_4 * , struct V_16 * ) )
{
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_88 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_88 = F_57 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
if ( V_88 )
break;
if ( V_25 -> V_83 == 0 )
V_25 -> V_83 = V_2 -> V_8 -> V_83 ;
}
return V_88 ;
}
static int F_59 ( const struct V_4 * V_5 , const struct V_108 * V_109 )
{
return F_56 ( V_5 , F_41 ( V_5 , V_109 ) , V_124 ) ;
}
static int F_60 ( const struct V_4 * V_5 , const struct V_108 * V_109 )
{
return F_56 ( V_5 , F_41 ( V_5 , V_109 ) , V_125 ) ;
}
static int F_61 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( V_17 -> V_126 == V_127 )
F_62 ( V_5 , V_17 ) ;
else
V_17 -> V_126 = V_128 ;
return 0 ;
}
static void
F_63 ( const struct V_4 * V_5 , const struct V_108 * V_109 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
F_61 ( V_5 , V_2 -> V_8 ) ;
V_25 -> V_30 . V_40 . V_41 +=
V_2 -> V_8 -> V_30 . V_40 . V_41 ;
if ( ! V_25 -> V_83 )
V_25 -> V_83 = V_2 -> V_8 -> V_83 ;
}
}
static int F_64 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_50 ( V_5 , V_17 ) ;
return 0 ;
}
static int F_65 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_66 ( V_5 , V_17 ) ;
return 0 ;
}
static void F_67 ( const struct V_4 * V_5 , const struct V_108 * V_109 )
{
int V_88 ;
V_88 = F_56 ( V_5 , F_41 ( V_5 , V_109 ) , F_61 ) ;
F_18 ( V_88 == 0 ) ;
}
static void F_68 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
int V_88 ;
V_88 = F_56 ( V_5 , V_7 , F_64 ) ;
F_18 ( V_88 == 0 ) ;
while ( ! F_69 ( & V_7 -> V_119 ) )
F_70 ( V_7 -> V_119 . V_120 ) ;
}
static void F_71 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 )
{
int V_88 ;
V_88 = F_56 ( V_5 , F_41 ( V_5 , V_109 ) , F_65 ) ;
F_18 ( V_88 == 0 ) ;
}
static int F_72 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 ,
T_2 V_19 , struct V_129 * V_130 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_64 * V_131 = V_7 -> V_23 ;
struct V_44 * V_45 = F_17 ( V_131 ) ;
struct V_132 * V_133 = F_20 ( V_131 ) ;
unsigned int V_134 ;
struct V_1 * V_2 ;
T_2 V_135 ;
T_1 V_136 ;
int V_18 ;
int V_88 ;
V_18 = F_73 ( V_131 -> V_24 , F_11 ( V_45 , V_19 ) ) ;
if ( F_19 ( ! V_133 -> V_73 [ V_18 ] ) )
return - V_74 ;
V_2 = F_28 ( V_5 , V_7 , V_18 ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
F_74 ( V_131 -> V_24 , F_11 ( V_45 , V_19 ) , V_18 , & V_136 ) ;
V_88 = F_75 ( V_2 -> V_10 , V_2 -> V_8 ,
F_12 ( F_26 ( V_133 -> V_73 [ V_18 ] ) , V_136 ) ,
V_130 ) ;
F_30 ( V_2 ) ;
F_51 ( V_137 , V_138 L_3 ,
F_76 ( F_77 ( F_78 ( V_131 ) ) ) , V_130 -> V_139 , V_133 -> V_140 , V_88 ) ;
if ( V_88 )
return V_88 ;
if ( V_133 -> V_140 == 1 )
return 0 ;
V_135 = V_130 -> V_139 ;
if ( V_135 != V_141 )
V_135 = F_79 ( V_131 -> V_24 , V_135 , V_18 ) ;
V_134 = V_131 -> V_24 -> V_122 >> V_142 ;
F_51 ( V_137 , V_138 L_4 ,
F_76 ( F_77 ( F_78 ( V_131 ) ) ) , V_135 , V_134 ,
V_131 -> V_24 -> V_122 , V_18 , V_19 ) ;
V_130 -> V_139 = F_55 ( T_2 , V_135 , V_19 + V_134 - V_19 % V_134 - 1 ) ;
return 0 ;
}
static int F_80 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 ,
enum V_143 V_144 , struct V_145 * V_146 )
{
struct V_147 * V_148 = & V_146 -> V_149 ;
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_1 * V_2 ;
struct V_147 * V_150 = & F_81 ( V_5 ) -> V_151 ;
struct V_90 * V_91 ;
int V_18 ;
int V_88 = 0 ;
if ( V_7 -> V_11 == 1 ) {
int V_152 = V_7 -> V_13 ;
F_18 ( V_152 < V_7 -> V_98 ) ;
V_2 = F_28 ( V_5 , V_7 , V_152 ) ;
F_18 ( ! F_23 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_80 ) ;
V_88 = F_82 ( V_2 -> V_10 , V_2 -> V_8 ,
V_144 , V_146 ) ;
F_30 ( V_2 ) ;
return V_88 ;
}
F_18 ( V_7 -> V_89 ) ;
F_83 ( V_150 ) ;
while ( V_148 -> V_153 > 0 ) {
struct V_145 * V_154 = & F_81 ( V_5 ) -> V_155 ;
F_84 ( V_154 ) ;
V_91 = F_85 ( V_148 ) ;
F_86 ( & V_154 -> V_149 , V_148 , V_91 ) ;
V_18 = F_31 ( V_91 ) ;
while ( V_148 -> V_153 > 0 ) {
V_91 = F_85 ( V_148 ) ;
if ( V_18 != F_31 ( V_91 ) )
break;
F_86 ( & V_154 -> V_149 , V_148 , V_91 ) ;
}
V_2 = F_28 ( V_5 , V_7 , V_18 ) ;
if ( ! F_23 ( V_2 ) ) {
V_88 = F_82 ( V_2 -> V_10 , V_2 -> V_8 ,
V_144 , V_154 ) ;
F_30 ( V_2 ) ;
} else {
V_88 = F_24 ( V_2 ) ;
}
F_87 ( & V_154 -> V_149 , V_150 ) ;
F_87 ( & V_154 -> V_156 , & V_146 -> V_156 ) ;
F_88 ( V_5 , V_154 ) ;
if ( V_88 != 0 )
break;
}
F_87 ( V_150 , V_148 ) ;
F_89 ( V_5 , V_150 ) ;
return V_88 ;
}
static int F_90 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 ,
struct V_147 * V_146 , int V_157 , int V_158 ,
T_5 V_159 )
{
struct V_147 * V_150 = & F_81 ( V_5 ) -> V_151 ;
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_1 * V_2 ;
struct V_90 * V_91 ;
int V_88 = 0 ;
if ( V_7 -> V_11 == 1 ) {
int V_152 = V_7 -> V_13 ;
F_18 ( V_152 < V_7 -> V_98 ) ;
V_2 = F_28 ( V_5 , V_7 , V_152 ) ;
F_18 ( ! F_23 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_80 ) ;
V_88 = F_91 ( V_2 -> V_10 , V_2 -> V_8 , V_146 ,
V_157 , V_158 , V_159 ) ;
F_30 ( V_2 ) ;
return V_88 ;
}
F_18 ( V_7 -> V_89 ) ;
F_83 ( V_150 ) ;
while ( V_146 -> V_153 > 0 ) {
int V_160 = V_158 ;
int V_18 ;
F_18 ( V_150 -> V_153 == 0 ) ;
V_91 = F_85 ( V_146 ) ;
F_86 ( V_150 , V_146 , V_91 ) ;
V_18 = F_31 ( V_91 ) ;
while ( V_146 -> V_153 > 0 ) {
V_91 = F_85 ( V_146 ) ;
if ( V_18 != F_31 ( V_91 ) )
break;
F_86 ( V_150 , V_146 , V_91 ) ;
}
if ( V_146 -> V_153 > 0 )
V_160 = V_161 ;
V_2 = F_28 ( V_5 , V_7 , V_18 ) ;
if ( ! F_23 ( V_2 ) ) {
V_88 = F_91 ( V_2 -> V_10 , V_2 -> V_8 ,
V_150 , V_157 , V_160 , V_159 ) ;
F_30 ( V_2 ) ;
} else {
V_88 = F_24 ( V_2 ) ;
break;
}
if ( V_150 -> V_153 > 0 )
break;
V_157 = 0 ;
}
F_18 ( F_92 ( V_88 == 0 , V_150 -> V_153 == 0 ) ) ;
while ( V_150 -> V_153 > 0 ) {
V_91 = F_93 ( V_150 ) ;
F_94 ( V_146 , V_150 , V_91 ) ;
}
return V_88 ;
}
static int F_95 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 )
{
struct V_162 * V_163 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_163 = & V_109 -> V_27 -> V_30 . V_48 ;
V_7 = F_41 ( V_5 , V_109 ) ;
V_2 = F_28 ( V_5 , V_7 , F_31 ( V_163 -> V_164 ) ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
V_2 -> V_8 -> V_30 . V_48 . V_165 = V_163 -> V_165 ;
F_30 ( V_2 ) ;
return F_60 ( V_5 , V_109 ) ;
}
static void F_96 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_109 ) ;
struct V_1 * V_2 ;
unsigned int * V_166 = & V_109 -> V_27 -> V_30 . V_51 . V_167 ;
* V_166 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
struct V_16 * V_168 = V_2 -> V_8 ;
F_1 ( V_2 ) ;
F_61 ( V_2 -> V_10 , V_168 ) ;
F_2 ( V_2 ) ;
if ( V_168 -> V_83 == 0 )
* V_166 += V_168 -> V_30 . V_51 . V_167 ;
}
}
static void F_97 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 )
{
struct V_64 * V_65 = F_35 ( V_109 -> V_110 ) ;
if ( F_44 ( & V_65 -> V_112 ) )
F_45 ( & V_65 -> V_113 ) ;
}
static int F_98 ( const struct V_4 * V_5 ,
const struct V_108 * V_109 ,
enum V_143 V_144 , struct V_145 * V_146 )
{
return - V_169 ;
}
static void F_99 ( const struct V_4 * V_5 ,
struct V_108 * V_109 )
{
F_39 () ;
}
int F_100 ( const struct V_4 * V_5 , struct V_44 * V_45 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_101 ( V_5 ) ;
struct V_64 * V_65 = F_35 ( V_45 ) ;
F_102 ( & V_7 -> V_119 ) ;
V_17 -> V_83 = F_38 ( V_7 , V_65 , V_17 ) ;
if ( V_17 -> V_83 == 0 ) {
V_17 -> V_83 = F_36 ( V_5 , V_7 , V_17 ) ;
if ( V_17 -> V_83 == 0 ) {
F_103 ( V_17 , & V_7 -> V_26 , V_45 , & V_170 ) ;
F_104 ( & V_65 -> V_112 ) ;
}
}
return V_17 -> V_83 ;
}
int F_105 ( const struct V_4 * V_5 , struct V_44 * V_45 ,
struct V_16 * V_17 )
{
struct V_64 * V_65 = F_35 ( V_45 ) ;
struct V_6 * V_7 = F_101 ( V_5 ) ;
int V_71 ;
V_7 -> V_23 = V_65 ;
switch ( V_17 -> V_28 ) {
default:
F_39 () ;
case V_107 :
case V_56 :
V_71 = 0 ;
break;
case V_50 :
case V_29 :
case V_39 :
V_71 = 1 ;
break;
case V_57 :
V_71 = - V_169 ;
break;
case V_43 :
V_71 = - V_171 ;
F_106 ( L_5 V_138 L_6 ,
F_76 ( F_77 ( & V_45 -> V_68 ) ) ) ;
break;
}
if ( V_71 == 0 ) {
F_103 ( V_17 , & V_7 -> V_26 , V_45 , & V_172 ) ;
F_104 ( & V_65 -> V_112 ) ;
}
V_17 -> V_83 = V_71 < 0 ? V_71 : 0 ;
return V_71 ;
}
int F_107 ( const struct V_4 * V_5 , struct V_44 * V_45 ,
struct V_16 * V_17 )
{
struct V_64 * V_65 = F_35 ( V_45 ) ;
struct V_6 * V_7 = F_101 ( V_5 ) ;
int V_71 ;
F_18 ( V_65 -> V_24 ) ;
V_7 -> V_23 = V_65 ;
switch ( V_17 -> V_28 ) {
default:
F_108 ( 0 , L_7 , V_17 -> V_28 ) ;
case V_107 :
case V_50 :
case V_39 :
V_71 = 1 ;
break;
case V_29 :
if ( F_9 ( V_17 ) ) {
V_17 -> V_173 = 1 ;
V_71 = - V_174 ;
} else {
V_71 = 1 ;
}
break;
case V_56 :
case V_57 :
case V_43 :
V_17 -> V_173 = 1 ;
V_71 = - V_174 ;
break;
}
if ( V_71 == 0 ) {
F_103 ( V_17 , & V_7 -> V_26 , V_45 , & V_172 ) ;
F_104 ( & V_65 -> V_112 ) ;
}
V_17 -> V_83 = V_71 < 0 ? V_71 : 0 ;
return V_71 ;
}
