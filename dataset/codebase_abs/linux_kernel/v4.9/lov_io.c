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
V_17 -> V_30 . V_31 . V_34 = V_18 ;
V_17 -> V_30 . V_31 . V_35 =
V_25 -> V_30 . V_31 . V_35 ;
if ( F_9 ( V_17 ) ) {
T_1 V_36 = V_25 -> V_30 . V_31 . V_32 . V_37 ;
V_36 = F_10 ( V_22 , V_36 , V_18 ) ;
V_17 -> V_30 . V_31 . V_32 . V_37 = V_36 ;
}
break;
}
case V_38 : {
struct V_39 * V_40 = V_25 -> V_41 ;
T_1 V_42 = F_11 ( V_40 , V_25 -> V_30 . V_43 . V_44 ) ;
V_17 -> V_30 . V_43 = V_25 -> V_30 . V_43 ;
V_42 = F_10 ( V_22 , V_42 , V_18 ) ;
V_17 -> V_30 . V_43 . V_44 = F_12 ( V_40 , V_42 ) ;
break;
}
case V_45 : {
V_17 -> V_30 . V_46 . V_47 = V_19 ;
V_17 -> V_30 . V_46 . V_48 = V_20 ;
V_17 -> V_30 . V_46 . V_49 = V_25 -> V_30 . V_46 . V_49 ;
V_17 -> V_30 . V_46 . V_50 = V_25 -> V_30 . V_46 . V_50 ;
break;
}
case V_51 :
case V_52 : {
V_17 -> V_30 . V_53 . V_54 = F_13 ( V_25 ) ;
if ( F_14 ( V_25 ) ) {
V_17 -> V_30 . V_53 . V_55 = 1 ;
} else {
V_17 -> V_30 . V_56 . V_57 = V_19 ;
V_17 -> V_30 . V_56 . V_58 = V_20 - V_19 ;
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
struct V_59 * V_60 = V_7 -> V_23 ;
struct V_61 * V_62 = F_16 ( F_17 ( V_60 ) -> V_63 . V_64 ) ;
struct V_16 * V_8 ;
struct V_39 * V_65 ;
struct V_16 * V_17 = V_7 -> V_26 . V_27 ;
int V_18 = V_2 -> V_12 ;
int V_66 ;
F_18 ( ! V_2 -> V_8 ) ;
F_18 ( ! V_2 -> V_10 ) ;
F_18 ( V_2 -> V_12 < V_7 -> V_67 ) ;
if ( F_19 ( ! F_20 ( V_60 ) -> V_68 [ V_18 ] ) )
return - V_69 ;
V_66 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_14 = 0 ;
if ( V_7 -> V_70 ) {
F_18 ( F_21 ( & V_62 -> V_71 ) ) ;
V_2 -> V_8 = & V_62 -> V_72 [ V_18 ] -> V_73 ;
V_2 -> V_10 = V_62 -> V_72 [ V_18 ] -> V_74 ;
V_2 -> V_14 = 1 ;
} else {
void * V_75 ;
V_75 = F_22 () ;
V_2 -> V_10 = F_23 ( & V_2 -> V_15 ) ;
F_24 ( V_75 ) ;
if ( F_25 ( V_2 -> V_10 ) )
V_66 = F_26 ( V_2 -> V_10 ) ;
if ( V_66 == 0 ) {
if ( V_7 -> V_11 == 0 ) {
V_2 -> V_8 = & V_7 -> V_76 ;
V_7 -> V_13 = V_18 ;
} else {
V_2 -> V_8 = F_27 ( sizeof( * V_2 -> V_8 ) ,
V_77 ) ;
if ( ! V_2 -> V_8 )
V_66 = - V_78 ;
}
}
}
if ( V_66 == 0 ) {
V_65 = F_28 ( F_20 ( V_60 ) -> V_68 [ V_18 ] ) ;
V_8 = V_2 -> V_8 ;
V_8 -> V_41 = V_65 ;
V_8 -> V_79 = 0 ;
V_8 -> V_80 = V_17 ;
V_8 -> V_81 = V_17 -> V_81 ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_82 = V_17 -> V_82 ;
V_8 -> V_83 = V_17 -> V_83 ;
F_1 ( V_2 ) ;
V_66 = F_29 ( V_2 -> V_10 , V_8 ,
V_17 -> V_28 , V_65 ) ;
F_2 ( V_2 ) ;
if ( V_66 >= 0 ) {
V_7 -> V_11 ++ ;
V_2 -> V_9 = 1 ;
V_66 = 0 ;
}
}
if ( V_66 != 0 )
F_3 ( V_5 , V_7 , V_2 ) ;
return V_66 ;
}
struct V_1 * F_30 ( const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_18 )
{
int V_84 ;
struct V_1 * V_2 = & V_7 -> V_85 [ V_18 ] ;
F_18 ( V_18 < V_7 -> V_67 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_12 = V_18 ;
V_84 = F_15 ( V_5 , V_7 , V_2 ) ;
} else {
V_84 = 0 ;
}
if ( V_84 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_31 ( V_84 ) ;
return V_2 ;
}
void F_32 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
int F_33 ( const struct V_86 * V_87 )
{
const struct V_88 * V_89 ;
V_89 = F_34 ( V_87 , & V_90 ) ;
F_18 ( V_89 -> V_91 ) ;
return F_35 ( V_89 ) -> V_92 ;
}
struct V_1 * F_36 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_88 * V_89 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_86 * V_87 = V_89 -> V_93 ;
int V_18 ;
F_18 ( V_7 -> V_26 . V_27 ) ;
F_18 ( F_37 ( V_89 -> V_91 ) == V_7 -> V_23 ) ;
F_18 ( V_22 ) ;
F_18 ( V_7 -> V_94 > 0 ) ;
V_18 = F_33 ( V_87 ) ;
return F_30 ( V_5 , V_7 , V_18 ) ;
}
static int F_38 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 ;
int V_66 ;
F_18 ( V_7 -> V_23 ) ;
V_22 = V_7 -> V_23 -> V_24 ;
V_7 -> V_85 =
F_39 ( V_22 -> V_95 *
sizeof( V_7 -> V_85 [ 0 ] ) ,
V_77 ) ;
if ( V_7 -> V_85 ) {
V_7 -> V_94 = V_7 -> V_67 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_11 = 0 ;
V_66 = 0 ;
} else {
V_66 = - V_78 ;
}
return V_66 ;
}
static int F_40 ( struct V_6 * V_7 , struct V_59 * V_40 ,
struct V_16 * V_17 )
{
V_17 -> V_79 = 0 ;
V_7 -> V_23 = V_40 ;
V_7 -> V_67 = V_40 -> V_24 -> V_95 ;
switch ( V_17 -> V_28 ) {
case V_51 :
case V_52 :
V_7 -> V_96 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_97 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
V_7 -> V_98 = V_7 -> V_97 ;
if ( F_14 ( V_17 ) ) {
F_18 ( V_17 -> V_28 == V_52 ) ;
if ( F_19 ( V_40 -> V_24 -> V_99 &
V_100 ) )
return - V_69 ;
V_7 -> V_96 = 0 ;
V_7 -> V_97 = V_101 ;
}
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_7 -> V_96 = V_17 -> V_30 . V_31 . V_32 . V_37 ;
else
V_7 -> V_96 = 0 ;
V_7 -> V_97 = V_101 ;
break;
case V_38 : {
T_2 V_102 = V_17 -> V_30 . V_43 . V_44 ;
V_7 -> V_96 = F_11 ( V_17 -> V_41 , V_102 ) ;
V_7 -> V_97 = F_11 ( V_17 -> V_41 , V_102 + 1 ) ;
break;
}
case V_45 : {
V_7 -> V_96 = V_17 -> V_30 . V_46 . V_47 ;
V_7 -> V_97 = V_17 -> V_30 . V_46 . V_48 ;
break;
}
case V_103 :
V_7 -> V_96 = 0 ;
V_7 -> V_97 = V_101 ;
break;
default:
F_41 () ;
}
return 0 ;
}
static void F_42 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_105 ) ;
struct V_59 * V_60 = F_37 ( V_105 -> V_106 ) ;
int V_107 ;
if ( V_7 -> V_85 ) {
for ( V_107 = 0 ; V_107 < V_7 -> V_94 ; V_107 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_85 [ V_107 ] ) ;
F_44 ( V_7 -> V_85 ) ;
V_7 -> V_94 = 0 ;
}
F_18 ( F_45 ( & V_60 -> V_108 ) > 0 ) ;
if ( F_46 ( & V_60 -> V_108 ) )
F_47 ( & V_60 -> V_109 ) ;
}
static T_3 F_48 ( T_3 V_110 , int V_111 )
{
if ( V_110 != V_101 )
V_110 += V_111 ;
return V_110 ;
}
static int F_49 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_105 ) ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_1 * V_2 ;
T_3 V_112 ;
T_3 V_19 ;
T_3 V_20 ;
int V_18 ;
int V_84 = 0 ;
V_112 = F_48 ( V_7 -> V_97 , - 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_67 ; V_18 ++ ) {
if ( ! F_50 ( V_22 , V_18 , V_7 -> V_96 ,
V_112 , & V_19 , & V_20 ) )
continue;
if ( F_19 ( ! F_20 ( V_7 -> V_23 ) -> V_68 [ V_18 ] ) ) {
if ( V_105 -> V_27 -> V_28 == V_51 ||
V_105 -> V_27 -> V_28 == V_52 ||
V_105 -> V_27 -> V_28 == V_38 )
return - V_69 ;
continue;
}
V_20 = F_48 ( V_20 , 1 ) ;
V_2 = F_30 ( V_5 , V_7 , V_18 ) ;
if ( ! F_25 ( V_2 ) ) {
F_8 ( V_2 -> V_8 , V_7 , V_18 ,
V_19 , V_20 ) ;
V_84 = F_51 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_32 ( V_2 ) ;
F_52 ( V_113 , L_1 ,
V_18 , V_19 , V_20 ) ;
} else {
V_84 = F_26 ( V_2 ) ;
}
if ( ! V_84 )
F_53 ( & V_2 -> V_114 , & V_7 -> V_115 ) ;
else
break;
}
return V_84 ;
}
static int F_54 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_105 ) ;
struct V_16 * V_17 = V_105 -> V_27 ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
T_4 V_19 = V_17 -> V_30 . V_56 . V_57 ;
T_1 V_116 ;
unsigned long V_117 = V_22 -> V_118 ;
F_18 ( V_17 -> V_28 == V_51 || V_17 -> V_28 == V_52 ) ;
if ( V_7 -> V_94 != 1 && ! F_14 ( V_17 ) ) {
F_55 ( V_19 , V_117 ) ;
V_116 = ( V_19 + 1 ) * V_117 ;
if ( V_116 <= V_19 * V_117 )
V_116 = ~ 0ull ;
V_17 -> V_119 = V_116 < V_7 -> V_98 ;
V_17 -> V_30 . V_56 . V_58 = F_56 ( T_1 , V_7 -> V_98 ,
V_116 ) - V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_96 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_97 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
F_52 ( V_113 , L_2 ,
( T_4 ) V_19 , V_7 -> V_96 , V_7 -> V_97 ,
( T_4 ) V_7 -> V_98 ) ;
}
return F_49 ( V_5 , V_105 ) ;
}
static int F_57 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_58)( const struct V_4 * , struct V_16 * ) )
{
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_84 = 0 ;
F_59 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_84 = F_58 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
if ( V_84 )
break;
if ( V_25 -> V_79 == 0 )
V_25 -> V_79 = V_2 -> V_8 -> V_79 ;
}
return V_84 ;
}
static int F_60 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
return F_57 ( V_5 , F_43 ( V_5 , V_105 ) , V_120 ) ;
}
static int F_61 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
return F_57 ( V_5 , F_43 ( V_5 , V_105 ) , V_121 ) ;
}
static int F_62 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( V_17 -> V_122 == V_123 )
F_63 ( V_5 , V_17 ) ;
else
V_17 -> V_122 = V_124 ;
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
static void F_68 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
int V_84 ;
V_84 = F_57 ( V_5 , F_43 ( V_5 , V_105 ) , F_62 ) ;
F_18 ( V_84 == 0 ) ;
}
static void F_69 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_105 ) ;
int V_84 ;
V_84 = F_57 ( V_5 , V_7 , F_64 ) ;
F_18 ( V_84 == 0 ) ;
while ( ! F_70 ( & V_7 -> V_115 ) )
F_71 ( V_7 -> V_115 . V_116 ) ;
}
static void F_72 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
int V_84 ;
V_84 = F_57 ( V_5 , F_43 ( V_5 , V_105 ) , F_66 ) ;
F_18 ( V_84 == 0 ) ;
}
static int F_73 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 ,
enum V_125 V_126 , struct V_127 * V_128 )
{
struct V_129 * V_130 = & V_128 -> V_131 ;
struct V_6 * V_7 = F_43 ( V_5 , V_105 ) ;
struct V_1 * V_2 ;
struct V_129 * V_132 = & F_74 ( V_5 ) -> V_133 ;
struct V_86 * V_87 ;
int V_18 ;
int V_84 = 0 ;
if ( V_7 -> V_11 == 1 ) {
int V_134 = V_7 -> V_13 ;
F_18 ( V_134 < V_7 -> V_94 ) ;
V_2 = F_30 ( V_5 , V_7 , V_134 ) ;
F_18 ( ! F_25 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_76 ) ;
V_84 = F_75 ( V_2 -> V_10 , V_2 -> V_8 ,
V_126 , V_128 ) ;
F_32 ( V_2 ) ;
return V_84 ;
}
F_18 ( V_7 -> V_85 ) ;
F_76 ( V_132 ) ;
while ( V_130 -> V_135 > 0 ) {
struct V_127 * V_136 = & F_74 ( V_5 ) -> V_137 ;
F_77 ( V_136 ) ;
V_87 = F_78 ( V_130 ) ;
F_79 ( & V_136 -> V_131 , V_130 , V_87 ) ;
V_18 = F_33 ( V_87 ) ;
while ( V_130 -> V_135 > 0 ) {
V_87 = F_78 ( V_130 ) ;
if ( V_18 != F_33 ( V_87 ) )
break;
F_79 ( & V_136 -> V_131 , V_130 , V_87 ) ;
}
V_2 = F_30 ( V_5 , V_7 , V_18 ) ;
if ( ! F_25 ( V_2 ) ) {
V_84 = F_75 ( V_2 -> V_10 , V_2 -> V_8 ,
V_126 , V_136 ) ;
F_32 ( V_2 ) ;
} else {
V_84 = F_26 ( V_2 ) ;
}
F_80 ( & V_136 -> V_131 , V_132 ) ;
F_80 ( & V_136 -> V_138 , & V_128 -> V_138 ) ;
F_81 ( V_5 , V_136 ) ;
if ( V_84 != 0 )
break;
}
F_80 ( V_132 , V_130 ) ;
F_82 ( V_5 , V_132 ) ;
return V_84 ;
}
static int F_83 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 ,
struct V_129 * V_128 , int V_139 , int V_140 ,
T_5 V_141 )
{
struct V_129 * V_132 = & F_74 ( V_5 ) -> V_133 ;
struct V_6 * V_7 = F_43 ( V_5 , V_105 ) ;
struct V_1 * V_2 ;
struct V_86 * V_87 ;
int V_84 = 0 ;
if ( V_7 -> V_11 == 1 ) {
int V_134 = V_7 -> V_13 ;
F_18 ( V_134 < V_7 -> V_94 ) ;
V_2 = F_30 ( V_5 , V_7 , V_134 ) ;
F_18 ( ! F_25 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_76 ) ;
V_84 = F_84 ( V_2 -> V_10 , V_2 -> V_8 , V_128 ,
V_139 , V_140 , V_141 ) ;
F_32 ( V_2 ) ;
return V_84 ;
}
F_18 ( V_7 -> V_85 ) ;
F_76 ( V_132 ) ;
while ( V_128 -> V_135 > 0 ) {
int V_142 = V_140 ;
int V_18 ;
F_18 ( V_132 -> V_135 == 0 ) ;
V_87 = F_78 ( V_128 ) ;
F_79 ( V_132 , V_128 , V_87 ) ;
V_18 = F_33 ( V_87 ) ;
while ( V_128 -> V_135 > 0 ) {
V_87 = F_78 ( V_128 ) ;
if ( V_18 != F_33 ( V_87 ) )
break;
F_79 ( V_132 , V_128 , V_87 ) ;
}
if ( V_128 -> V_135 > 0 )
V_142 = V_143 ;
V_2 = F_30 ( V_5 , V_7 , V_18 ) ;
if ( ! F_25 ( V_2 ) ) {
V_84 = F_84 ( V_2 -> V_10 , V_2 -> V_8 ,
V_132 , V_139 , V_142 , V_141 ) ;
F_32 ( V_2 ) ;
} else {
V_84 = F_26 ( V_2 ) ;
break;
}
if ( V_132 -> V_135 > 0 )
break;
V_139 = 0 ;
}
F_18 ( F_85 ( V_84 == 0 , V_132 -> V_135 == 0 ) ) ;
while ( V_132 -> V_135 > 0 ) {
V_87 = F_86 ( V_132 ) ;
F_87 ( V_128 , V_132 , V_87 ) ;
}
return V_84 ;
}
static int F_88 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_144 * V_145 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_145 = & V_105 -> V_27 -> V_30 . V_43 ;
V_7 = F_43 ( V_5 , V_105 ) ;
V_2 = F_30 ( V_5 , V_7 , F_33 ( V_145 -> V_146 ) ) ;
if ( F_25 ( V_2 ) )
return F_26 ( V_2 ) ;
V_2 -> V_8 -> V_30 . V_43 . V_147 = V_145 -> V_147 ;
F_32 ( V_2 ) ;
return F_61 ( V_5 , V_105 ) ;
}
static void F_89 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_43 ( V_5 , V_105 ) ;
struct V_1 * V_2 ;
unsigned int * V_148 = & V_105 -> V_27 -> V_30 . V_46 . V_149 ;
* V_148 = 0 ;
F_59 (sub, &lio->lis_active, sub_linkage) {
struct V_16 * V_150 = V_2 -> V_8 ;
F_1 ( V_2 ) ;
F_62 ( V_2 -> V_10 , V_150 ) ;
F_2 ( V_2 ) ;
if ( V_150 -> V_79 == 0 )
* V_148 += V_150 -> V_30 . V_46 . V_149 ;
}
}
static void F_90 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_59 * V_60 = F_37 ( V_105 -> V_106 ) ;
if ( F_46 ( & V_60 -> V_108 ) )
F_47 ( & V_60 -> V_109 ) ;
}
static void F_91 ( const struct V_4 * V_5 ,
struct V_104 * V_105 )
{
F_41 () ;
}
int F_92 ( const struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_93 ( V_5 ) ;
struct V_59 * V_60 = F_37 ( V_40 ) ;
F_94 ( & V_7 -> V_115 ) ;
V_17 -> V_79 = F_40 ( V_7 , V_60 , V_17 ) ;
if ( V_17 -> V_79 == 0 ) {
V_17 -> V_79 = F_38 ( V_5 , V_7 , V_17 ) ;
if ( V_17 -> V_79 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_40 , & V_151 ) ;
F_96 ( & V_60 -> V_108 ) ;
}
}
return V_17 -> V_79 ;
}
int F_97 ( const struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_16 * V_17 )
{
struct V_59 * V_60 = F_37 ( V_40 ) ;
struct V_6 * V_7 = F_93 ( V_5 ) ;
int V_66 ;
V_7 -> V_23 = V_60 ;
switch ( V_17 -> V_28 ) {
default:
F_41 () ;
case V_103 :
case V_51 :
V_66 = 0 ;
break;
case V_45 :
case V_29 :
V_66 = 1 ;
break;
case V_52 :
V_66 = - V_152 ;
break;
case V_38 :
V_66 = - V_153 ;
F_98 ( L_3 V_154 L_4 ,
F_99 ( F_100 ( & V_40 -> V_63 ) ) ) ;
break;
}
if ( V_66 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_40 , & V_155 ) ;
F_96 ( & V_60 -> V_108 ) ;
}
V_17 -> V_79 = V_66 < 0 ? V_66 : 0 ;
return V_66 ;
}
int F_101 ( const struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_16 * V_17 )
{
struct V_59 * V_60 = F_37 ( V_40 ) ;
struct V_6 * V_7 = F_93 ( V_5 ) ;
int V_66 ;
F_18 ( V_60 -> V_24 ) ;
V_7 -> V_23 = V_60 ;
switch ( V_17 -> V_28 ) {
default:
F_102 ( 0 , L_5 , V_17 -> V_28 ) ;
case V_103 :
case V_45 :
V_66 = 1 ;
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_17 -> V_156 = 1 ;
V_66 = - V_157 ;
break;
case V_51 :
case V_52 :
case V_38 :
V_17 -> V_156 = 1 ;
V_66 = - V_157 ;
break;
}
if ( V_66 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_40 , & V_155 ) ;
F_96 ( & V_60 -> V_108 ) ;
}
V_17 -> V_79 = V_66 < 0 ? V_66 : 0 ;
return V_66 ;
}
