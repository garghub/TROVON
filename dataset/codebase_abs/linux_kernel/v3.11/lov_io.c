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
V_8 ;
if ( V_2 -> V_9 != NULL ) {
if ( V_2 -> V_10 ) {
F_1 ( V_2 ) ;
F_4 ( V_2 -> V_11 , V_2 -> V_9 ) ;
F_2 ( V_2 ) ;
V_2 -> V_10 = 0 ;
V_7 -> V_12 -- ;
}
if ( V_2 -> V_13 == V_7 -> V_14 )
V_7 -> V_14 = - 1 ;
else if ( ! V_2 -> V_15 )
F_5 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
}
if ( V_2 -> V_11 != NULL && ! F_6 ( V_2 -> V_11 ) ) {
if ( ! V_2 -> V_15 )
F_7 ( V_2 -> V_11 , & V_2 -> V_16 ) ;
V_2 -> V_11 = NULL ;
}
EXIT ;
}
static void F_8 ( struct V_17 * V_18 , struct V_6 * V_7 ,
int V_19 , T_1 V_20 , T_1 V_21 )
{
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
struct V_17 * V_26 = V_7 -> V_27 . V_28 ;
switch( V_18 -> V_29 ) {
case V_30 : {
V_18 -> V_31 . V_32 . V_33 = V_26 -> V_31 . V_32 . V_33 ;
V_18 -> V_31 . V_32 . V_34 = V_26 -> V_31 . V_32 . V_34 ;
V_18 -> V_31 . V_32 . V_35 = V_26 -> V_31 . V_32 . V_35 ;
if ( F_9 ( V_18 ) ) {
T_1 V_36 = V_26 -> V_31 . V_32 . V_33 . V_37 ;
V_36 = F_10 ( V_23 , V_36 , V_19 ) ;
V_18 -> V_31 . V_32 . V_33 . V_37 = V_36 ;
}
break;
}
case V_38 : {
struct V_39 * V_40 = V_26 -> V_41 ;
T_1 V_42 = F_11 ( V_40 , V_26 -> V_31 . V_43 . V_44 ) ;
V_18 -> V_31 . V_43 = V_26 -> V_31 . V_43 ;
V_42 = F_10 ( V_23 , V_42 , V_19 ) ;
V_18 -> V_31 . V_43 . V_44 = F_12 ( V_40 , V_42 ) ;
break;
}
case V_45 : {
V_18 -> V_31 . V_46 . V_47 = V_20 ;
V_18 -> V_31 . V_46 . V_48 = V_21 ;
V_18 -> V_31 . V_46 . V_49 = V_26 -> V_31 . V_46 . V_49 ;
V_18 -> V_31 . V_46 . V_50 = V_26 -> V_31 . V_46 . V_50 ;
V_18 -> V_31 . V_46 . V_51 = V_26 -> V_31 . V_46 . V_51 ;
break;
}
case V_52 :
case V_53 : {
V_18 -> V_31 . V_54 . V_55 = F_13 ( V_26 ) ;
if ( F_14 ( V_26 ) ) {
V_18 -> V_31 . V_54 . V_56 = 1 ;
} else {
V_18 -> V_31 . V_57 . V_58 = V_20 ;
V_18 -> V_31 . V_57 . V_59 = V_21 - V_20 ;
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
struct V_60 * V_61 = V_7 -> V_24 ;
struct V_62 * V_63 = F_16 ( F_17 ( V_61 ) -> V_64 . V_65 ) ;
struct V_17 * V_9 ;
struct V_39 * V_66 ;
struct V_17 * V_18 = V_7 -> V_27 . V_28 ;
int V_19 = V_2 -> V_13 ;
int V_67 ;
F_18 ( V_2 -> V_9 == NULL ) ;
F_18 ( V_2 -> V_11 == NULL ) ;
F_18 ( V_2 -> V_13 < V_7 -> V_68 ) ;
V_8 ;
V_67 = 0 ;
V_2 -> V_10 = 0 ;
V_2 -> V_15 = 0 ;
if ( V_7 -> V_69 ) {
F_18 ( F_19 ( & V_63 -> V_70 ) ) ;
V_2 -> V_9 = & V_63 -> V_71 [ V_19 ] -> V_72 ;
V_2 -> V_11 = V_63 -> V_71 [ V_19 ] -> V_73 ;
V_2 -> V_15 = 1 ;
} else {
void * V_74 ;
V_74 = F_20 () ;
V_2 -> V_11 = F_21 ( & V_2 -> V_16 ) ;
F_22 ( V_74 ) ;
if ( F_6 ( V_2 -> V_11 ) )
V_67 = F_23 ( V_2 -> V_11 ) ;
if ( V_67 == 0 ) {
if ( V_7 -> V_12 == 0 ) {
V_2 -> V_9 = & V_7 -> V_75 ;
V_7 -> V_14 = V_19 ;
} else {
F_24 ( V_2 -> V_9 ) ;
if ( V_2 -> V_9 == NULL )
V_67 = - V_76 ;
}
}
}
if ( V_67 == 0 ) {
V_66 = F_25 ( F_26 ( V_61 ) -> V_77 [ V_19 ] ) ;
V_9 = V_2 -> V_9 ;
V_9 -> V_41 = V_66 ;
V_9 -> V_78 = 0 ;
V_9 -> V_79 = V_18 ;
V_9 -> V_80 = V_18 -> V_80 ;
V_9 -> V_29 = V_18 -> V_29 ;
V_9 -> V_81 = V_18 -> V_81 ;
F_1 ( V_2 ) ;
V_67 = F_27 ( V_2 -> V_11 , V_9 ,
V_18 -> V_29 , V_66 ) ;
F_2 ( V_2 ) ;
if ( V_67 >= 0 ) {
V_7 -> V_12 ++ ;
V_2 -> V_10 = 1 ;
V_67 = 0 ;
}
}
if ( V_67 != 0 )
F_3 ( V_5 , V_7 , V_2 ) ;
RETURN ( V_67 ) ;
}
struct V_1 * F_28 ( const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_19 )
{
int V_82 ;
struct V_1 * V_2 = & V_7 -> V_83 [ V_19 ] ;
F_18 ( V_19 < V_7 -> V_68 ) ;
V_8 ;
if ( ! V_2 -> V_10 ) {
V_2 -> V_13 = V_19 ;
V_82 = F_15 ( V_5 , V_7 , V_2 ) ;
} else
V_82 = 0 ;
if ( V_82 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_29 ( V_82 ) ;
RETURN ( V_2 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_31 ( const struct V_84 * V_85 )
{
struct V_86 * V_87 ;
V_8 ;
V_87 = F_32 (
F_33 ( V_85 -> V_88 -> V_89 -> V_64 . V_90 ,
& V_91 ) ) ;
F_18 ( V_87 != NULL ) ;
RETURN ( V_87 -> V_92 ) ;
}
struct V_1 * F_34 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_93 * V_94 )
{
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
struct V_84 * V_85 = V_94 -> V_95 ;
int V_19 ;
F_18 ( V_7 -> V_27 . V_28 != NULL ) ;
F_18 ( F_35 ( V_94 -> V_96 ) == V_7 -> V_24 ) ;
F_18 ( V_23 != NULL ) ;
F_18 ( V_7 -> V_97 > 0 ) ;
V_8 ;
V_19 = F_31 ( V_85 ) ;
RETURN ( F_28 ( V_5 , V_7 , V_19 ) ) ;
}
static int F_36 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_17 * V_18 )
{
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
int V_67 ;
F_18 ( V_7 -> V_24 != NULL ) ;
V_8 ;
F_37 ( V_7 -> V_83 ,
V_23 -> V_98 * sizeof V_7 -> V_83 [ 0 ] ) ;
if ( V_7 -> V_83 != NULL ) {
V_7 -> V_97 = V_7 -> V_68 ;
V_7 -> V_14 = - 1 ;
V_7 -> V_12 = 0 ;
V_67 = 0 ;
} else
V_67 = - V_76 ;
RETURN ( V_67 ) ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_60 * V_40 , struct V_17 * V_18 )
{
V_8 ;
V_18 -> V_78 = 0 ;
V_7 -> V_24 = V_40 ;
F_18 ( V_40 -> V_25 != NULL ) ;
V_7 -> V_68 = V_40 -> V_25 -> V_98 ;
switch ( V_18 -> V_29 ) {
case V_52 :
case V_53 :
V_7 -> V_99 = V_18 -> V_31 . V_57 . V_58 ;
V_7 -> V_100 = V_18 -> V_31 . V_57 . V_58 + V_18 -> V_31 . V_57 . V_59 ;
V_7 -> V_101 = V_7 -> V_100 ;
if ( F_14 ( V_18 ) ) {
F_18 ( V_18 -> V_29 == V_53 ) ;
V_7 -> V_99 = 0 ;
V_7 -> V_100 = V_102 ;
}
break;
case V_30 :
if ( F_9 ( V_18 ) )
V_7 -> V_99 = V_18 -> V_31 . V_32 . V_33 . V_37 ;
else
V_7 -> V_99 = 0 ;
V_7 -> V_100 = V_102 ;
break;
case V_38 : {
T_2 V_103 = V_18 -> V_31 . V_43 . V_44 ;
V_7 -> V_99 = F_11 ( V_18 -> V_41 , V_103 ) ;
V_7 -> V_100 = F_11 ( V_18 -> V_41 , V_103 + 1 ) ;
break;
}
case V_45 : {
V_7 -> V_99 = V_18 -> V_31 . V_46 . V_47 ;
V_7 -> V_100 = V_18 -> V_31 . V_46 . V_48 ;
break;
}
case V_104 :
V_7 -> V_99 = 0 ;
V_7 -> V_100 = V_102 ;
break;
default:
F_39 () ;
}
EXIT ;
}
static void F_40 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
struct V_60 * V_61 = F_35 ( V_106 -> V_107 ) ;
int V_108 ;
V_8 ;
if ( V_7 -> V_83 != NULL ) {
for ( V_108 = 0 ; V_108 < V_7 -> V_97 ; V_108 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_83 [ V_108 ] ) ;
F_42 ( V_7 -> V_83 ,
V_7 -> V_97 * sizeof V_7 -> V_83 [ 0 ] ) ;
V_7 -> V_97 = 0 ;
}
F_18 ( F_43 ( & V_61 -> V_109 ) > 0 ) ;
if ( F_44 ( & V_61 -> V_109 ) )
F_45 ( & V_61 -> V_110 ) ;
EXIT ;
}
static T_3 F_46 ( T_3 V_111 , int V_112 )
{
if ( V_111 != V_102 )
V_111 += V_112 ;
return V_111 ;
}
static int F_47 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
struct V_1 * V_2 ;
T_3 V_113 ;
T_3 V_20 ;
T_3 V_21 ;
int V_19 ;
int V_82 = 0 ;
V_8 ;
V_113 = F_46 ( V_7 -> V_100 , - 1 ) ;
for ( V_19 = 0 ; V_19 < V_7 -> V_68 ; V_19 ++ ) {
if ( ! F_48 ( V_23 , V_19 , V_7 -> V_99 ,
V_113 , & V_20 , & V_21 ) )
continue;
V_21 = F_46 ( V_21 , + 1 ) ;
V_2 = F_28 ( V_5 , V_7 , V_19 ) ;
if ( ! F_6 ( V_2 ) ) {
F_8 ( V_2 -> V_9 , V_7 , V_19 ,
V_20 , V_21 ) ;
V_82 = F_49 ( V_2 -> V_11 , V_2 -> V_9 ) ;
F_30 ( V_2 ) ;
F_50 ( V_114 , L_1 V_115 L_2 V_115 L_3 ,
V_19 , V_20 , V_21 ) ;
} else
V_82 = F_23 ( V_2 ) ;
if ( ! V_82 )
F_51 ( & V_2 -> V_116 , & V_7 -> V_117 ) ;
else
break;
}
RETURN ( V_82 ) ;
}
static int F_52 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
struct V_17 * V_18 = V_106 -> V_28 ;
struct V_22 * V_23 = V_7 -> V_24 -> V_25 ;
T_1 V_20 = V_18 -> V_31 . V_57 . V_58 ;
T_1 V_118 ;
unsigned long V_119 = V_23 -> V_120 ;
F_18 ( V_18 -> V_29 == V_52 || V_18 -> V_29 == V_53 ) ;
V_8 ;
if ( V_7 -> V_97 != 1 && ! F_14 ( V_18 ) ) {
F_53 ( V_20 , V_119 ) ;
V_118 = ( V_20 + 1 ) * V_119 ;
if ( V_118 <= V_20 * V_119 )
V_118 = ~ 0ull ;
V_18 -> V_121 = V_118 < V_7 -> V_101 ;
V_18 -> V_31 . V_57 . V_59 = F_54 ( T_1 , V_7 -> V_101 ,
V_118 ) - V_18 -> V_31 . V_57 . V_58 ;
V_7 -> V_99 = V_18 -> V_31 . V_57 . V_58 ;
V_7 -> V_100 = V_18 -> V_31 . V_57 . V_58 + V_18 -> V_31 . V_57 . V_59 ;
F_50 ( V_114 , L_4 V_115 L_5 V_115 L_2 V_115 L_6
V_115 L_7 , ( V_122 ) V_20 , V_7 -> V_99 , V_7 -> V_100 ,
( V_122 ) V_7 -> V_101 ) ;
}
RETURN ( F_47 ( V_5 , V_106 ) ) ;
}
static int F_55 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_56)( const struct V_4 * , struct V_17 * ) )
{
struct V_17 * V_26 = V_7 -> V_27 . V_28 ;
struct V_1 * V_2 ;
int V_82 = 0 ;
V_8 ;
F_57 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_82 = F_56 ( V_2 -> V_11 , V_2 -> V_9 ) ;
F_2 ( V_2 ) ;
if ( V_82 )
break;
if ( V_26 -> V_78 == 0 )
V_26 -> V_78 = V_2 -> V_9 -> V_78 ;
}
RETURN ( V_82 ) ;
}
static int F_58 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
V_8 ;
RETURN ( F_55 ( V_5 , F_41 ( V_5 , V_106 ) , V_123 ) ) ;
}
static int F_59 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
V_8 ;
RETURN ( F_55 ( V_5 , F_41 ( V_5 , V_106 ) , V_124 ) ) ;
}
static int F_60 ( const struct V_4 * V_5 , struct V_17 * V_18 )
{
V_8 ;
if ( V_18 -> V_125 == V_126 )
F_61 ( V_5 , V_18 ) ;
else
V_18 -> V_125 = V_127 ;
RETURN ( 0 ) ;
}
static int F_62 ( const struct V_4 * V_5 , struct V_17 * V_18 )
{
F_63 ( V_5 , V_18 ) ;
RETURN ( 0 ) ;
}
static int F_64 ( const struct V_4 * V_5 , struct V_17 * V_18 )
{
F_65 ( V_5 , V_18 ) ;
RETURN ( 0 ) ;
}
static void F_66 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
int V_82 ;
V_82 = F_55 ( V_5 , F_41 ( V_5 , V_106 ) , F_60 ) ;
F_18 ( V_82 == 0 ) ;
}
static void F_67 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
int V_82 ;
V_8 ;
V_82 = F_55 ( V_5 , V_7 , F_62 ) ;
F_18 ( V_82 == 0 ) ;
while ( ! F_68 ( & V_7 -> V_117 ) )
F_69 ( V_7 -> V_117 . V_118 ) ;
EXIT ;
}
static void F_70 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
int V_82 ;
V_8 ;
V_82 = F_55 ( V_5 , F_41 ( V_5 , V_106 ) , F_64 ) ;
F_18 ( V_82 == 0 ) ;
EXIT ;
}
static struct V_128 * F_71 ( struct V_62 * V_63 ,
struct V_128 * V_129 ,
int V_130 , int V_131 )
{
return V_131 ? & V_129 [ V_130 ] : & V_63 -> V_71 [ V_130 ] -> V_132 ;
}
static int F_72 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 ,
enum V_133 V_134 , struct V_135 * V_136 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
struct V_60 * V_40 = V_7 -> V_24 ;
struct V_62 * V_63 = F_16 ( F_17 ( V_40 ) -> V_64 . V_65 ) ;
struct V_128 * V_129 = & V_136 -> V_137 ;
struct V_135 * V_138 = & F_73 ( V_5 ) -> V_139 ;
struct V_128 * V_140 = NULL ;
struct V_84 * V_85 ;
struct V_84 * V_141 ;
int V_19 ;
#define F_74 ( V_19 ) lov_io_submit_qin(ld, stripes_qin, stripe, alloc)
int V_82 = 0 ;
int V_131 =
! ( V_142 -> V_143 & V_144 ) ;
V_8 ;
if ( V_7 -> V_12 == 1 ) {
int V_130 = V_7 -> V_14 ;
struct V_1 * V_2 ;
F_18 ( V_130 < V_7 -> V_97 ) ;
V_2 = F_28 ( V_5 , V_7 , V_130 ) ;
F_18 ( ! F_6 ( V_2 ) ) ;
F_18 ( V_2 -> V_9 == & V_7 -> V_75 ) ;
V_82 = F_75 ( V_2 -> V_11 , V_2 -> V_9 ,
V_134 , V_136 ) ;
F_30 ( V_2 ) ;
RETURN ( V_82 ) ;
}
F_18 ( V_7 -> V_83 != NULL ) ;
if ( V_131 ) {
F_37 ( V_140 ,
sizeof( * V_140 ) * V_7 -> V_97 ) ;
if ( V_140 == NULL )
RETURN ( - V_76 ) ;
for ( V_19 = 0 ; V_19 < V_7 -> V_97 ; V_19 ++ )
F_76 ( & V_140 [ V_19 ] ) ;
} else {
F_77 ( & V_63 -> V_70 ) ;
V_7 -> V_69 = 1 ;
}
F_78 ( V_138 ) ;
F_79 (page, tmp, qin) {
V_19 = F_31 ( V_85 ) ;
F_80 ( F_74 ( V_19 ) , V_129 , V_85 ) ;
}
for ( V_19 = 0 ; V_19 < V_7 -> V_97 ; V_19 ++ ) {
struct V_1 * V_2 ;
struct V_128 * V_145 = F_74 ( V_19 ) ;
if ( F_68 ( & V_145 -> V_146 ) )
continue;
F_81 ( V_145 , & V_138 -> V_137 ) ;
V_2 = F_28 ( V_5 , V_7 , V_19 ) ;
if ( ! F_6 ( V_2 ) ) {
V_82 = F_75 ( V_2 -> V_11 , V_2 -> V_9 ,
V_134 , V_138 ) ;
F_30 ( V_2 ) ;
} else
V_82 = F_23 ( V_2 ) ;
F_81 ( & V_138 -> V_137 , & V_136 -> V_137 ) ;
F_81 ( & V_138 -> V_147 , & V_136 -> V_147 ) ;
if ( V_82 != 0 )
break;
}
for ( V_19 = 0 ; V_19 < V_7 -> V_97 ; V_19 ++ ) {
struct V_128 * V_145 = F_74 ( V_19 ) ;
if ( F_68 ( & V_145 -> V_146 ) )
continue;
F_81 ( V_145 , V_129 ) ;
}
if ( V_131 ) {
F_42 ( V_140 ,
sizeof( * V_140 ) * V_7 -> V_97 ) ;
} else {
int V_108 ;
for ( V_108 = 0 ; V_108 < V_7 -> V_97 ; V_108 ++ ) {
struct V_17 * V_148 = V_7 -> V_83 [ V_108 ] . V_9 ;
if ( V_148 && V_148 == & V_63 -> V_71 [ V_108 ] -> V_72 )
F_3 ( V_5 , V_7 , & V_7 -> V_83 [ V_108 ] ) ;
}
V_7 -> V_69 = 0 ;
F_82 ( & V_63 -> V_70 ) ;
}
RETURN ( V_82 ) ;
#undef F_74
}
static int F_83 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 ,
const struct V_93 * V_94 ,
unsigned V_149 , unsigned V_150 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
struct V_84 * V_151 = F_84 ( V_94 ) ;
struct V_1 * V_2 ;
int V_67 ;
V_8 ;
V_2 = F_34 ( V_5 , V_7 , V_94 ) ;
if ( ! F_6 ( V_2 ) ) {
V_67 = F_85 ( V_2 -> V_11 , V_2 -> V_9 ,
V_151 , V_149 , V_150 ) ;
F_30 ( V_2 ) ;
} else
V_67 = F_23 ( V_2 ) ;
RETURN ( V_67 ) ;
}
static int F_86 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 ,
const struct V_93 * V_94 ,
unsigned V_149 , unsigned V_150 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
struct V_84 * V_151 = F_84 ( V_94 ) ;
struct V_1 * V_2 ;
int V_67 ;
V_8 ;
V_2 = F_34 ( V_5 , V_7 , V_94 ) ;
if ( ! F_6 ( V_2 ) ) {
V_67 = F_87 ( V_2 -> V_11 , V_2 -> V_9 ,
V_151 , V_149 , V_150 ) ;
F_30 ( V_2 ) ;
} else
V_67 = F_23 ( V_2 ) ;
RETURN ( V_67 ) ;
}
static int F_88 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_152 * V_153 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_8 ;
V_153 = & V_106 -> V_28 -> V_31 . V_43 ;
V_7 = F_41 ( V_5 , V_106 ) ;
V_2 = F_28 ( V_5 , V_7 , F_31 ( V_153 -> V_154 ) ) ;
V_2 -> V_9 -> V_31 . V_43 . V_155 = V_153 -> V_155 ;
F_30 ( V_2 ) ;
RETURN ( F_59 ( V_5 , V_106 ) ) ;
}
static void F_89 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_106 ) ;
struct V_1 * V_2 ;
unsigned int * V_156 = & V_106 -> V_28 -> V_31 . V_46 . V_157 ;
V_8 ;
* V_156 = 0 ;
F_57 (sub, &lio->lis_active, sub_linkage) {
struct V_17 * V_158 = V_2 -> V_9 ;
F_1 ( V_2 ) ;
F_60 ( V_2 -> V_11 , V_158 ) ;
F_2 ( V_2 ) ;
if ( V_158 -> V_78 == 0 )
* V_156 += V_158 -> V_31 . V_46 . V_157 ;
}
V_159 ;
}
static void F_90 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_60 * V_61 = F_35 ( V_106 -> V_107 ) ;
V_8 ;
if ( F_44 ( & V_61 -> V_109 ) )
F_45 ( & V_61 -> V_110 ) ;
EXIT ;
}
static void F_91 ( const struct V_4 * V_5 ,
struct V_105 * V_106 )
{
F_39 () ;
}
int F_92 ( const struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_17 * V_18 )
{
struct V_6 * V_7 = F_93 ( V_5 ) ;
struct V_60 * V_61 = F_35 ( V_40 ) ;
V_8 ;
F_94 ( & V_7 -> V_117 ) ;
F_38 ( V_7 , V_61 , V_18 ) ;
if ( V_18 -> V_78 == 0 ) {
V_18 -> V_78 = F_36 ( V_5 , V_7 , V_18 ) ;
if ( V_18 -> V_78 == 0 ) {
F_95 ( V_18 , & V_7 -> V_27 , V_40 , & V_160 ) ;
F_96 ( & V_61 -> V_109 ) ;
}
}
RETURN ( V_18 -> V_78 ) ;
}
int F_97 ( const struct V_4 * V_5 , struct V_39 * V_40 ,
struct V_17 * V_18 )
{
struct V_60 * V_61 = F_35 ( V_40 ) ;
struct V_6 * V_7 = F_93 ( V_5 ) ;
int V_67 ;
V_8 ;
V_7 -> V_24 = V_61 ;
switch ( V_18 -> V_29 ) {
default:
F_39 () ;
case V_104 :
case V_52 :
V_67 = 0 ;
break;
case V_45 :
case V_30 :
V_67 = + 1 ;
break;
case V_53 :
V_67 = - V_161 ;
break;
case V_38 :
V_67 = - V_162 ;
F_98 ( L_8 V_163 L_7 ,
F_99 ( F_100 ( & V_40 -> V_64 ) ) ) ;
break;
}
if ( V_67 == 0 ) {
F_95 ( V_18 , & V_7 -> V_27 , V_40 , & V_164 ) ;
F_96 ( & V_61 -> V_109 ) ;
}
V_18 -> V_78 = V_67 < 0 ? V_67 : 0 ;
RETURN ( V_67 != 0 ) ;
}
