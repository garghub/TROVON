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
V_17 -> V_30 . V_31 . V_33 = V_25 -> V_30 . V_31 . V_33 ;
if ( F_9 ( V_17 ) ) {
T_1 V_34 = V_25 -> V_30 . V_31 . V_32 . V_35 ;
V_34 = F_10 ( V_22 , V_34 , V_18 ) ;
V_17 -> V_30 . V_31 . V_32 . V_35 = V_34 ;
}
break;
}
case V_36 : {
struct V_37 * V_38 = V_25 -> V_39 ;
T_1 V_40 = F_11 ( V_38 , V_25 -> V_30 . V_41 . V_42 ) ;
V_17 -> V_30 . V_41 = V_25 -> V_30 . V_41 ;
V_40 = F_10 ( V_22 , V_40 , V_18 ) ;
V_17 -> V_30 . V_41 . V_42 = F_12 ( V_38 , V_40 ) ;
break;
}
case V_43 : {
V_17 -> V_30 . V_44 . V_45 = V_19 ;
V_17 -> V_30 . V_44 . V_46 = V_20 ;
V_17 -> V_30 . V_44 . V_47 = V_25 -> V_30 . V_44 . V_47 ;
V_17 -> V_30 . V_44 . V_48 = V_25 -> V_30 . V_44 . V_48 ;
break;
}
case V_49 :
case V_50 : {
V_17 -> V_30 . V_51 . V_52 = F_13 ( V_25 ) ;
if ( F_14 ( V_25 ) ) {
V_17 -> V_30 . V_51 . V_53 = 1 ;
} else {
V_17 -> V_30 . V_54 . V_55 = V_19 ;
V_17 -> V_30 . V_54 . V_56 = V_20 - V_19 ;
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
struct V_57 * V_58 = V_7 -> V_23 ;
struct V_59 * V_60 = F_16 ( F_17 ( V_58 ) -> V_61 . V_62 ) ;
struct V_16 * V_8 ;
struct V_37 * V_63 ;
struct V_16 * V_17 = V_7 -> V_26 . V_27 ;
int V_18 = V_2 -> V_12 ;
int V_64 ;
F_18 ( ! V_2 -> V_8 ) ;
F_18 ( ! V_2 -> V_10 ) ;
F_18 ( V_2 -> V_12 < V_7 -> V_65 ) ;
if ( F_19 ( ! F_20 ( V_58 ) -> V_66 [ V_18 ] ) )
return - V_67 ;
V_64 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_14 = 0 ;
if ( V_7 -> V_68 ) {
F_18 ( F_21 ( & V_60 -> V_69 ) ) ;
V_2 -> V_8 = & V_60 -> V_70 [ V_18 ] -> V_71 ;
V_2 -> V_10 = V_60 -> V_70 [ V_18 ] -> V_72 ;
V_2 -> V_14 = 1 ;
} else {
void * V_73 ;
V_73 = F_22 () ;
V_2 -> V_10 = F_23 ( & V_2 -> V_15 ) ;
F_24 ( V_73 ) ;
if ( F_25 ( V_2 -> V_10 ) )
V_64 = F_26 ( V_2 -> V_10 ) ;
if ( V_64 == 0 ) {
if ( V_7 -> V_11 == 0 ) {
V_2 -> V_8 = & V_7 -> V_74 ;
V_7 -> V_13 = V_18 ;
} else {
V_2 -> V_8 = F_27 ( sizeof( * V_2 -> V_8 ) ,
V_75 ) ;
if ( ! V_2 -> V_8 )
V_64 = - V_76 ;
}
}
}
if ( V_64 == 0 ) {
V_63 = F_28 ( F_20 ( V_58 ) -> V_66 [ V_18 ] ) ;
V_8 = V_2 -> V_8 ;
V_8 -> V_39 = V_63 ;
V_8 -> V_77 = 0 ;
V_8 -> V_78 = V_17 ;
V_8 -> V_79 = V_17 -> V_79 ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_80 = V_17 -> V_80 ;
V_8 -> V_81 = V_17 -> V_81 ;
F_1 ( V_2 ) ;
V_64 = F_29 ( V_2 -> V_10 , V_8 ,
V_17 -> V_28 , V_63 ) ;
F_2 ( V_2 ) ;
if ( V_64 >= 0 ) {
V_7 -> V_11 ++ ;
V_2 -> V_9 = 1 ;
V_64 = 0 ;
}
}
if ( V_64 != 0 )
F_3 ( V_5 , V_7 , V_2 ) ;
return V_64 ;
}
struct V_1 * F_30 ( const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_18 )
{
int V_82 ;
struct V_1 * V_2 = & V_7 -> V_83 [ V_18 ] ;
F_18 ( V_18 < V_7 -> V_65 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_12 = V_18 ;
V_82 = F_15 ( V_5 , V_7 , V_2 ) ;
} else {
V_82 = 0 ;
}
if ( V_82 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_31 ( V_82 ) ;
return V_2 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
int F_33 ( const struct V_84 * V_85 )
{
struct V_86 * V_87 ;
const struct V_88 * V_89 ;
V_89 = F_34 ( V_85 , & V_90 ) ;
F_18 ( V_89 -> V_91 ) ;
V_87 = F_35 ( V_89 -> V_91 ) ;
return V_87 -> V_92 ;
}
struct V_1 * F_36 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_88 * V_89 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_84 * V_85 = V_89 -> V_93 ;
int V_18 ;
F_18 ( V_7 -> V_26 . V_27 ) ;
F_18 ( F_37 ( V_89 -> V_91 ) == V_7 -> V_23 ) ;
F_18 ( V_22 ) ;
F_18 ( V_7 -> V_94 > 0 ) ;
V_18 = F_33 ( V_85 ) ;
return F_30 ( V_5 , V_7 , V_18 ) ;
}
static int F_38 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 ;
int V_64 ;
F_18 ( V_7 -> V_23 ) ;
V_22 = V_7 -> V_23 -> V_24 ;
V_7 -> V_83 =
F_39 ( V_22 -> V_95 *
sizeof( V_7 -> V_83 [ 0 ] ) ,
V_75 ) ;
if ( V_7 -> V_83 ) {
V_7 -> V_94 = V_7 -> V_65 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_11 = 0 ;
V_64 = 0 ;
} else {
V_64 = - V_76 ;
}
return V_64 ;
}
static void F_40 ( struct V_6 * V_7 ,
struct V_57 * V_38 , struct V_16 * V_17 )
{
V_17 -> V_77 = 0 ;
V_7 -> V_23 = V_38 ;
V_7 -> V_65 = V_38 -> V_24 -> V_95 ;
switch ( V_17 -> V_28 ) {
case V_49 :
case V_50 :
V_7 -> V_96 = V_17 -> V_30 . V_54 . V_55 ;
V_7 -> V_97 = V_17 -> V_30 . V_54 . V_55 + V_17 -> V_30 . V_54 . V_56 ;
V_7 -> V_98 = V_7 -> V_97 ;
if ( F_14 ( V_17 ) ) {
F_18 ( V_17 -> V_28 == V_50 ) ;
V_7 -> V_96 = 0 ;
V_7 -> V_97 = V_99 ;
}
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_7 -> V_96 = V_17 -> V_30 . V_31 . V_32 . V_35 ;
else
V_7 -> V_96 = 0 ;
V_7 -> V_97 = V_99 ;
break;
case V_36 : {
T_2 V_100 = V_17 -> V_30 . V_41 . V_42 ;
V_7 -> V_96 = F_11 ( V_17 -> V_39 , V_100 ) ;
V_7 -> V_97 = F_11 ( V_17 -> V_39 , V_100 + 1 ) ;
break;
}
case V_43 : {
V_7 -> V_96 = V_17 -> V_30 . V_44 . V_45 ;
V_7 -> V_97 = V_17 -> V_30 . V_44 . V_46 ;
break;
}
case V_101 :
V_7 -> V_96 = 0 ;
V_7 -> V_97 = V_99 ;
break;
default:
F_41 () ;
}
}
static void F_42 ( const struct V_4 * V_5 , const struct V_102 * V_103 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_103 ) ;
struct V_57 * V_58 = F_37 ( V_103 -> V_104 ) ;
int V_105 ;
if ( V_7 -> V_83 ) {
for ( V_105 = 0 ; V_105 < V_7 -> V_94 ; V_105 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_83 [ V_105 ] ) ;
F_44 ( V_7 -> V_83 ) ;
V_7 -> V_94 = 0 ;
}
F_18 ( F_45 ( & V_58 -> V_106 ) > 0 ) ;
if ( F_46 ( & V_58 -> V_106 ) )
F_47 ( & V_58 -> V_107 ) ;
}
static T_3 F_48 ( T_3 V_108 , int V_109 )
{
if ( V_108 != V_99 )
V_108 += V_109 ;
return V_108 ;
}
static int F_49 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_103 ) ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_1 * V_2 ;
T_3 V_110 ;
T_3 V_19 ;
T_3 V_20 ;
int V_18 ;
int V_82 = 0 ;
V_110 = F_48 ( V_7 -> V_97 , - 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_65 ; V_18 ++ ) {
if ( ! F_50 ( V_22 , V_18 , V_7 -> V_96 ,
V_110 , & V_19 , & V_20 ) )
continue;
if ( F_19 ( ! F_20 ( V_7 -> V_23 ) -> V_66 [ V_18 ] ) ) {
if ( V_103 -> V_27 -> V_28 == V_49 ||
V_103 -> V_27 -> V_28 == V_50 ||
V_103 -> V_27 -> V_28 == V_36 )
return - V_67 ;
continue;
}
V_20 = F_48 ( V_20 , 1 ) ;
V_2 = F_30 ( V_5 , V_7 , V_18 ) ;
if ( ! F_25 ( V_2 ) ) {
F_8 ( V_2 -> V_8 , V_7 , V_18 ,
V_19 , V_20 ) ;
V_82 = F_51 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_32 ( V_2 ) ;
F_52 ( V_111 , L_1 ,
V_18 , V_19 , V_20 ) ;
} else {
V_82 = F_26 ( V_2 ) ;
}
if ( ! V_82 )
F_53 ( & V_2 -> V_112 , & V_7 -> V_113 ) ;
else
break;
}
return V_82 ;
}
static int F_54 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_103 ) ;
struct V_16 * V_17 = V_103 -> V_27 ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
T_4 V_19 = V_17 -> V_30 . V_54 . V_55 ;
T_1 V_114 ;
unsigned long V_115 = V_22 -> V_116 ;
F_18 ( V_17 -> V_28 == V_49 || V_17 -> V_28 == V_50 ) ;
if ( V_7 -> V_94 != 1 && ! F_14 ( V_17 ) ) {
F_55 ( V_19 , V_115 ) ;
V_114 = ( V_19 + 1 ) * V_115 ;
if ( V_114 <= V_19 * V_115 )
V_114 = ~ 0ull ;
V_17 -> V_117 = V_114 < V_7 -> V_98 ;
V_17 -> V_30 . V_54 . V_56 = F_56 ( T_1 , V_7 -> V_98 ,
V_114 ) - V_17 -> V_30 . V_54 . V_55 ;
V_7 -> V_96 = V_17 -> V_30 . V_54 . V_55 ;
V_7 -> V_97 = V_17 -> V_30 . V_54 . V_55 + V_17 -> V_30 . V_54 . V_56 ;
F_52 ( V_111 , L_2 ,
( T_4 ) V_19 , V_7 -> V_96 , V_7 -> V_97 ,
( T_4 ) V_7 -> V_98 ) ;
}
return F_49 ( V_5 , V_103 ) ;
}
static int F_57 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_58)( const struct V_4 * , struct V_16 * ) )
{
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_82 = 0 ;
F_59 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_82 = F_58 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
if ( V_82 )
break;
if ( V_25 -> V_77 == 0 )
V_25 -> V_77 = V_2 -> V_8 -> V_77 ;
}
return V_82 ;
}
static int F_60 ( const struct V_4 * V_5 , const struct V_102 * V_103 )
{
return F_57 ( V_5 , F_43 ( V_5 , V_103 ) , V_118 ) ;
}
static int F_61 ( const struct V_4 * V_5 , const struct V_102 * V_103 )
{
return F_57 ( V_5 , F_43 ( V_5 , V_103 ) , V_119 ) ;
}
static int F_62 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( V_17 -> V_120 == V_121 )
F_63 ( V_5 , V_17 ) ;
else
V_17 -> V_120 = V_122 ;
return 0 ;
}
static int F_64 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_65 ( V_5 , V_17 ) ;
return 0 ;
}
static int F_66 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_67 ( V_5 , V_17 ) ;
return 0 ;
}
static void F_68 ( const struct V_4 * V_5 , const struct V_102 * V_103 )
{
int V_82 ;
V_82 = F_57 ( V_5 , F_43 ( V_5 , V_103 ) , F_62 ) ;
F_18 ( V_82 == 0 ) ;
}
static void F_69 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_103 ) ;
int V_82 ;
V_82 = F_57 ( V_5 , V_7 , F_64 ) ;
F_18 ( V_82 == 0 ) ;
while ( ! F_70 ( & V_7 -> V_113 ) )
F_71 ( V_7 -> V_113 . V_114 ) ;
}
static void F_72 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
int V_82 ;
V_82 = F_57 ( V_5 , F_43 ( V_5 , V_103 ) , F_66 ) ;
F_18 ( V_82 == 0 ) ;
}
static int F_73 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 ,
enum V_123 V_124 , struct V_125 * V_126 )
{
struct V_127 * V_128 = & V_126 -> V_129 ;
struct V_6 * V_7 = F_43 ( V_5 , V_103 ) ;
struct V_1 * V_2 ;
struct V_127 * V_130 = & F_74 ( V_5 ) -> V_131 ;
struct V_84 * V_85 ;
int V_18 ;
int V_82 = 0 ;
if ( V_7 -> V_11 == 1 ) {
int V_132 = V_7 -> V_13 ;
F_18 ( V_132 < V_7 -> V_94 ) ;
V_2 = F_30 ( V_5 , V_7 , V_132 ) ;
F_18 ( ! F_25 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_74 ) ;
V_82 = F_75 ( V_2 -> V_10 , V_2 -> V_8 ,
V_124 , V_126 ) ;
F_32 ( V_2 ) ;
return V_82 ;
}
F_18 ( V_7 -> V_83 ) ;
F_76 ( V_130 ) ;
while ( V_128 -> V_133 > 0 ) {
struct V_125 * V_134 = & F_74 ( V_5 ) -> V_135 ;
F_77 ( V_134 ) ;
V_85 = F_78 ( V_128 ) ;
F_79 ( & V_134 -> V_129 , V_128 , V_85 ) ;
V_18 = F_33 ( V_85 ) ;
while ( V_128 -> V_133 > 0 ) {
V_85 = F_78 ( V_128 ) ;
if ( V_18 != F_33 ( V_85 ) )
break;
F_79 ( & V_134 -> V_129 , V_128 , V_85 ) ;
}
V_2 = F_30 ( V_5 , V_7 , V_18 ) ;
if ( ! F_25 ( V_2 ) ) {
V_82 = F_75 ( V_2 -> V_10 , V_2 -> V_8 ,
V_124 , V_134 ) ;
F_32 ( V_2 ) ;
} else {
V_82 = F_26 ( V_2 ) ;
}
F_80 ( & V_134 -> V_129 , V_130 ) ;
F_80 ( & V_134 -> V_136 , & V_126 -> V_136 ) ;
F_81 ( V_5 , V_134 ) ;
if ( V_82 != 0 )
break;
}
F_80 ( V_130 , V_128 ) ;
F_82 ( V_5 , V_130 ) ;
return V_82 ;
}
static int F_83 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 ,
struct V_127 * V_126 , int V_137 , int V_138 ,
T_5 V_139 )
{
struct V_127 * V_130 = & F_74 ( V_5 ) -> V_131 ;
struct V_6 * V_7 = F_43 ( V_5 , V_103 ) ;
struct V_1 * V_2 ;
struct V_84 * V_85 ;
int V_82 = 0 ;
if ( V_7 -> V_11 == 1 ) {
int V_132 = V_7 -> V_13 ;
F_18 ( V_132 < V_7 -> V_94 ) ;
V_2 = F_30 ( V_5 , V_7 , V_132 ) ;
F_18 ( ! F_25 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_74 ) ;
V_82 = F_84 ( V_2 -> V_10 , V_2 -> V_8 , V_126 ,
V_137 , V_138 , V_139 ) ;
F_32 ( V_2 ) ;
return V_82 ;
}
F_18 ( V_7 -> V_83 ) ;
F_76 ( V_130 ) ;
while ( V_126 -> V_133 > 0 ) {
int V_140 = V_138 ;
int V_18 ;
F_18 ( V_130 -> V_133 == 0 ) ;
V_85 = F_78 ( V_126 ) ;
F_79 ( V_130 , V_126 , V_85 ) ;
V_18 = F_33 ( V_85 ) ;
while ( V_126 -> V_133 > 0 ) {
V_85 = F_78 ( V_126 ) ;
if ( V_18 != F_33 ( V_85 ) )
break;
F_79 ( V_130 , V_126 , V_85 ) ;
}
if ( V_126 -> V_133 > 0 )
V_140 = V_141 ;
V_2 = F_30 ( V_5 , V_7 , V_18 ) ;
if ( ! F_25 ( V_2 ) ) {
V_82 = F_84 ( V_2 -> V_10 , V_2 -> V_8 ,
V_130 , V_137 , V_140 , V_139 ) ;
F_32 ( V_2 ) ;
} else {
V_82 = F_26 ( V_2 ) ;
break;
}
if ( V_130 -> V_133 > 0 )
break;
V_137 = 0 ;
}
F_18 ( F_85 ( V_82 == 0 , V_130 -> V_133 == 0 ) ) ;
while ( V_130 -> V_133 > 0 ) {
V_85 = F_86 ( V_130 ) ;
F_87 ( V_126 , V_130 , V_85 ) ;
}
return V_82 ;
}
static int F_88 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
struct V_142 * V_143 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_143 = & V_103 -> V_27 -> V_30 . V_41 ;
V_7 = F_43 ( V_5 , V_103 ) ;
V_2 = F_30 ( V_5 , V_7 , F_33 ( V_143 -> V_144 ) ) ;
if ( F_25 ( V_2 ) )
return F_26 ( V_2 ) ;
V_2 -> V_8 -> V_30 . V_41 . V_145 = V_143 -> V_145 ;
F_32 ( V_2 ) ;
return F_61 ( V_5 , V_103 ) ;
}
static void F_89 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_103 ) ;
struct V_1 * V_2 ;
unsigned int * V_146 = & V_103 -> V_27 -> V_30 . V_44 . V_147 ;
* V_146 = 0 ;
F_59 (sub, &lio->lis_active, sub_linkage) {
struct V_16 * V_148 = V_2 -> V_8 ;
F_1 ( V_2 ) ;
F_62 ( V_2 -> V_10 , V_148 ) ;
F_2 ( V_2 ) ;
if ( V_148 -> V_77 == 0 )
* V_146 += V_148 -> V_30 . V_44 . V_147 ;
}
}
static void F_90 ( const struct V_4 * V_5 ,
const struct V_102 * V_103 )
{
struct V_57 * V_58 = F_37 ( V_103 -> V_104 ) ;
if ( F_46 ( & V_58 -> V_106 ) )
F_47 ( & V_58 -> V_107 ) ;
}
static void F_91 ( const struct V_4 * V_5 ,
struct V_102 * V_103 )
{
F_41 () ;
}
int F_92 ( const struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_93 ( V_5 ) ;
struct V_57 * V_58 = F_37 ( V_38 ) ;
F_94 ( & V_7 -> V_113 ) ;
F_40 ( V_7 , V_58 , V_17 ) ;
if ( V_17 -> V_77 == 0 ) {
V_17 -> V_77 = F_38 ( V_5 , V_7 , V_17 ) ;
if ( V_17 -> V_77 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_38 , & V_149 ) ;
F_96 ( & V_58 -> V_106 ) ;
}
}
return V_17 -> V_77 ;
}
int F_97 ( const struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_16 * V_17 )
{
struct V_57 * V_58 = F_37 ( V_38 ) ;
struct V_6 * V_7 = F_93 ( V_5 ) ;
int V_64 ;
V_7 -> V_23 = V_58 ;
switch ( V_17 -> V_28 ) {
default:
F_41 () ;
case V_101 :
case V_49 :
V_64 = 0 ;
break;
case V_43 :
case V_29 :
V_64 = 1 ;
break;
case V_50 :
V_64 = - V_150 ;
break;
case V_36 :
V_64 = - V_151 ;
F_98 ( L_3 V_152 L_4 ,
F_99 ( F_100 ( & V_38 -> V_61 ) ) ) ;
break;
}
if ( V_64 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_38 , & V_153 ) ;
F_96 ( & V_58 -> V_106 ) ;
}
V_17 -> V_77 = V_64 < 0 ? V_64 : 0 ;
return V_64 ;
}
int F_101 ( const struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_16 * V_17 )
{
struct V_57 * V_58 = F_37 ( V_38 ) ;
struct V_6 * V_7 = F_93 ( V_5 ) ;
int V_64 ;
F_18 ( V_58 -> V_24 ) ;
V_7 -> V_23 = V_58 ;
switch ( V_17 -> V_28 ) {
default:
F_102 ( 0 , L_5 , V_17 -> V_28 ) ;
case V_101 :
case V_43 :
V_64 = 1 ;
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_17 -> V_154 = 1 ;
V_64 = - V_155 ;
break;
case V_49 :
case V_50 :
case V_36 :
V_17 -> V_154 = 1 ;
V_64 = - V_155 ;
break;
}
if ( V_64 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_38 , & V_153 ) ;
F_96 ( & V_58 -> V_106 ) ;
}
V_17 -> V_77 = V_64 < 0 ? V_64 : 0 ;
return V_64 ;
}
