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
if ( V_2 -> V_8 != NULL ) {
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
if ( V_2 -> V_10 != NULL && ! F_6 ( V_2 -> V_10 ) ) {
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
F_18 ( V_2 -> V_8 == NULL ) ;
F_18 ( V_2 -> V_10 == NULL ) ;
F_18 ( V_2 -> V_12 < V_7 -> V_65 ) ;
if ( F_19 ( F_20 ( V_58 ) -> V_66 [ V_18 ] == NULL ) )
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
if ( F_6 ( V_2 -> V_10 ) )
V_64 = F_25 ( V_2 -> V_10 ) ;
if ( V_64 == 0 ) {
if ( V_7 -> V_11 == 0 ) {
V_2 -> V_8 = & V_7 -> V_74 ;
V_7 -> V_13 = V_18 ;
} else {
V_2 -> V_8 = F_26 ( sizeof( * V_2 -> V_8 ) ,
V_75 ) ;
if ( ! V_2 -> V_8 )
V_64 = - V_76 ;
}
}
}
if ( V_64 == 0 ) {
V_63 = F_27 ( F_20 ( V_58 ) -> V_66 [ V_18 ] ) ;
V_8 = V_2 -> V_8 ;
V_8 -> V_39 = V_63 ;
V_8 -> V_77 = 0 ;
V_8 -> V_78 = V_17 ;
V_8 -> V_79 = V_17 -> V_79 ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_80 = V_17 -> V_80 ;
V_8 -> V_81 = V_17 -> V_81 ;
F_1 ( V_2 ) ;
V_64 = F_28 ( V_2 -> V_10 , V_8 ,
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
struct V_1 * F_29 ( const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_18 )
{
int V_82 ;
struct V_1 * V_2 = & V_7 -> V_83 [ V_18 ] ;
F_18 ( V_18 < V_7 -> V_65 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_12 = V_18 ;
V_82 = F_15 ( V_5 , V_7 , V_2 ) ;
} else
V_82 = 0 ;
if ( V_82 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_30 ( V_82 ) ;
return V_2 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_32 ( const struct V_84 * V_85 )
{
struct V_86 * V_87 ;
V_87 = F_33 (
F_34 ( V_85 -> V_88 -> V_89 -> V_61 . V_90 ,
& V_91 ) ) ;
F_18 ( V_87 != NULL ) ;
return V_87 -> V_92 ;
}
struct V_1 * F_35 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_93 * V_94 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_84 * V_85 = V_94 -> V_95 ;
int V_18 ;
F_18 ( V_7 -> V_26 . V_27 != NULL ) ;
F_18 ( F_36 ( V_94 -> V_96 ) == V_7 -> V_23 ) ;
F_18 ( V_22 != NULL ) ;
F_18 ( V_7 -> V_97 > 0 ) ;
V_18 = F_32 ( V_85 ) ;
return F_29 ( V_5 , V_7 , V_18 ) ;
}
static int F_37 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
int V_64 ;
F_18 ( V_7 -> V_23 != NULL ) ;
V_7 -> V_83 =
F_38 ( V_22 -> V_98 *
sizeof( V_7 -> V_83 [ 0 ] ) ,
V_75 ) ;
if ( V_7 -> V_83 != NULL ) {
V_7 -> V_97 = V_7 -> V_65 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_11 = 0 ;
V_64 = 0 ;
} else
V_64 = - V_76 ;
return V_64 ;
}
static void F_39 ( struct V_6 * V_7 ,
struct V_57 * V_38 , struct V_16 * V_17 )
{
V_17 -> V_77 = 0 ;
V_7 -> V_23 = V_38 ;
F_18 ( V_38 -> V_24 != NULL ) ;
V_7 -> V_65 = V_38 -> V_24 -> V_98 ;
switch ( V_17 -> V_28 ) {
case V_49 :
case V_50 :
V_7 -> V_99 = V_17 -> V_30 . V_54 . V_55 ;
V_7 -> V_100 = V_17 -> V_30 . V_54 . V_55 + V_17 -> V_30 . V_54 . V_56 ;
V_7 -> V_101 = V_7 -> V_100 ;
if ( F_14 ( V_17 ) ) {
F_18 ( V_17 -> V_28 == V_50 ) ;
V_7 -> V_99 = 0 ;
V_7 -> V_100 = V_102 ;
}
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_7 -> V_99 = V_17 -> V_30 . V_31 . V_32 . V_35 ;
else
V_7 -> V_99 = 0 ;
V_7 -> V_100 = V_102 ;
break;
case V_36 : {
T_2 V_103 = V_17 -> V_30 . V_41 . V_42 ;
V_7 -> V_99 = F_11 ( V_17 -> V_39 , V_103 ) ;
V_7 -> V_100 = F_11 ( V_17 -> V_39 , V_103 + 1 ) ;
break;
}
case V_43 : {
V_7 -> V_99 = V_17 -> V_30 . V_44 . V_45 ;
V_7 -> V_100 = V_17 -> V_30 . V_44 . V_46 ;
break;
}
case V_104 :
V_7 -> V_99 = 0 ;
V_7 -> V_100 = V_102 ;
break;
default:
F_40 () ;
}
}
static void F_41 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
struct V_57 * V_58 = F_36 ( V_106 -> V_107 ) ;
int V_108 ;
if ( V_7 -> V_83 != NULL ) {
for ( V_108 = 0 ; V_108 < V_7 -> V_97 ; V_108 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_83 [ V_108 ] ) ;
F_43 ( V_7 -> V_83 ) ;
V_7 -> V_97 = 0 ;
}
F_18 ( F_44 ( & V_58 -> V_109 ) > 0 ) ;
if ( F_45 ( & V_58 -> V_109 ) )
F_46 ( & V_58 -> V_110 ) ;
}
static T_3 F_47 ( T_3 V_111 , int V_112 )
{
if ( V_111 != V_102 )
V_111 += V_112 ;
return V_111 ;
}
static int F_48 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_1 * V_2 ;
T_3 V_113 ;
T_3 V_19 ;
T_3 V_20 ;
int V_18 ;
int V_82 = 0 ;
V_113 = F_47 ( V_7 -> V_100 , - 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_65 ; V_18 ++ ) {
if ( ! F_49 ( V_22 , V_18 , V_7 -> V_99 ,
V_113 , & V_19 , & V_20 ) )
continue;
if ( F_19 ( F_20 ( V_7 -> V_23 ) -> V_66 [ V_18 ] == NULL ) ) {
if ( V_106 -> V_27 -> V_28 == V_49 ||
V_106 -> V_27 -> V_28 == V_50 ||
V_106 -> V_27 -> V_28 == V_36 )
return - V_67 ;
continue;
}
V_20 = F_47 ( V_20 , 1 ) ;
V_2 = F_29 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
F_8 ( V_2 -> V_8 , V_7 , V_18 ,
V_19 , V_20 ) ;
V_82 = F_50 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_31 ( V_2 ) ;
F_51 ( V_114 , L_1 ,
V_18 , V_19 , V_20 ) ;
} else
V_82 = F_25 ( V_2 ) ;
if ( ! V_82 )
F_52 ( & V_2 -> V_115 , & V_7 -> V_116 ) ;
else
break;
}
return V_82 ;
}
static int F_53 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
struct V_16 * V_17 = V_106 -> V_27 ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
T_4 V_19 = V_17 -> V_30 . V_54 . V_55 ;
T_1 V_117 ;
unsigned long V_118 = V_22 -> V_119 ;
F_18 ( V_17 -> V_28 == V_49 || V_17 -> V_28 == V_50 ) ;
if ( V_7 -> V_97 != 1 && ! F_14 ( V_17 ) ) {
F_54 ( V_19 , V_118 ) ;
V_117 = ( V_19 + 1 ) * V_118 ;
if ( V_117 <= V_19 * V_118 )
V_117 = ~ 0ull ;
V_17 -> V_120 = V_117 < V_7 -> V_101 ;
V_17 -> V_30 . V_54 . V_56 = F_55 ( T_1 , V_7 -> V_101 ,
V_117 ) - V_17 -> V_30 . V_54 . V_55 ;
V_7 -> V_99 = V_17 -> V_30 . V_54 . V_55 ;
V_7 -> V_100 = V_17 -> V_30 . V_54 . V_55 + V_17 -> V_30 . V_54 . V_56 ;
F_51 ( V_114 , L_2 ,
( T_4 ) V_19 , V_7 -> V_99 , V_7 -> V_100 ,
( T_4 ) V_7 -> V_101 ) ;
}
return F_48 ( V_5 , V_106 ) ;
}
static int F_56 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_57)( const struct V_4 * , struct V_16 * ) )
{
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_82 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_82 = F_57 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
if ( V_82 )
break;
if ( V_25 -> V_77 == 0 )
V_25 -> V_77 = V_2 -> V_8 -> V_77 ;
}
return V_82 ;
}
static int F_59 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
return F_56 ( V_5 , F_42 ( V_5 , V_106 ) , V_121 ) ;
}
static int F_60 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
return F_56 ( V_5 , F_42 ( V_5 , V_106 ) , V_122 ) ;
}
static int F_61 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( V_17 -> V_123 == V_124 )
F_62 ( V_5 , V_17 ) ;
else
V_17 -> V_123 = V_125 ;
return 0 ;
}
static int F_63 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_64 ( V_5 , V_17 ) ;
return 0 ;
}
static int F_65 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_66 ( V_5 , V_17 ) ;
return 0 ;
}
static void F_67 ( const struct V_4 * V_5 , const struct V_105 * V_106 )
{
int V_82 ;
V_82 = F_56 ( V_5 , F_42 ( V_5 , V_106 ) , F_61 ) ;
F_18 ( V_82 == 0 ) ;
}
static void F_68 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
int V_82 ;
V_82 = F_56 ( V_5 , V_7 , F_63 ) ;
F_18 ( V_82 == 0 ) ;
while ( ! F_69 ( & V_7 -> V_116 ) )
F_70 ( V_7 -> V_116 . V_117 ) ;
}
static void F_71 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
int V_82 ;
V_82 = F_56 ( V_5 , F_42 ( V_5 , V_106 ) , F_65 ) ;
F_18 ( V_82 == 0 ) ;
}
static struct V_126 * F_72 ( struct V_59 * V_60 ,
struct V_126 * V_127 ,
int V_128 , int V_129 )
{
return V_129 ? & V_127 [ V_128 ] : & V_60 -> V_70 [ V_128 ] -> V_130 ;
}
static int F_73 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 ,
enum V_131 V_132 , struct V_133 * V_134 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
struct V_57 * V_38 = V_7 -> V_23 ;
struct V_59 * V_60 = F_16 ( F_17 ( V_38 ) -> V_61 . V_62 ) ;
struct V_126 * V_127 = & V_134 -> V_135 ;
struct V_133 * V_136 = & F_74 ( V_5 ) -> V_137 ;
struct V_126 * V_138 = NULL ;
struct V_84 * V_85 ;
struct V_84 * V_139 ;
int V_18 ;
#define F_75 ( V_18 ) lov_io_submit_qin(ld, stripes_qin, stripe, alloc)
int V_82 = 0 ;
int V_129 =
! ( V_140 -> V_141 & V_142 ) ;
if ( V_7 -> V_11 == 1 ) {
int V_128 = V_7 -> V_13 ;
struct V_1 * V_2 ;
F_18 ( V_128 < V_7 -> V_97 ) ;
V_2 = F_29 ( V_5 , V_7 , V_128 ) ;
F_18 ( ! F_6 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_74 ) ;
V_82 = F_76 ( V_2 -> V_10 , V_2 -> V_8 ,
V_132 , V_134 ) ;
F_31 ( V_2 ) ;
return V_82 ;
}
F_18 ( V_7 -> V_83 != NULL ) ;
if ( V_129 ) {
V_138 =
F_38 ( sizeof( * V_138 ) *
V_7 -> V_97 ,
V_75 ) ;
if ( V_138 == NULL )
return - V_76 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_97 ; V_18 ++ )
F_77 ( & V_138 [ V_18 ] ) ;
} else {
F_78 ( & V_60 -> V_69 ) ;
V_7 -> V_68 = 1 ;
}
F_79 ( V_136 ) ;
F_80 (page, tmp, qin) {
V_18 = F_32 ( V_85 ) ;
F_81 ( F_75 ( V_18 ) , V_127 , V_85 ) ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_97 ; V_18 ++ ) {
struct V_1 * V_2 ;
struct V_126 * V_143 = F_75 ( V_18 ) ;
if ( F_69 ( & V_143 -> V_144 ) )
continue;
F_82 ( V_143 , & V_136 -> V_135 ) ;
V_2 = F_29 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
V_82 = F_76 ( V_2 -> V_10 , V_2 -> V_8 ,
V_132 , V_136 ) ;
F_31 ( V_2 ) ;
} else
V_82 = F_25 ( V_2 ) ;
F_82 ( & V_136 -> V_135 , & V_134 -> V_135 ) ;
F_82 ( & V_136 -> V_145 , & V_134 -> V_145 ) ;
if ( V_82 != 0 )
break;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_97 ; V_18 ++ ) {
struct V_126 * V_143 = F_75 ( V_18 ) ;
if ( F_69 ( & V_143 -> V_144 ) )
continue;
F_82 ( V_143 , V_127 ) ;
}
if ( V_129 ) {
F_43 ( V_138 ) ;
} else {
int V_108 ;
for ( V_108 = 0 ; V_108 < V_7 -> V_97 ; V_108 ++ ) {
struct V_16 * V_146 = V_7 -> V_83 [ V_108 ] . V_8 ;
if ( V_146 && V_146 == & V_60 -> V_70 [ V_108 ] -> V_71 )
F_3 ( V_5 , V_7 , & V_7 -> V_83 [ V_108 ] ) ;
}
V_7 -> V_68 = 0 ;
F_83 ( & V_60 -> V_69 ) ;
}
return V_82 ;
#undef F_75
}
static int F_84 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 ,
const struct V_93 * V_94 ,
unsigned V_147 , unsigned V_148 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
struct V_84 * V_149 = F_85 ( V_94 ) ;
struct V_1 * V_2 ;
int V_64 ;
V_2 = F_35 ( V_5 , V_7 , V_94 ) ;
if ( ! F_6 ( V_2 ) ) {
V_64 = F_86 ( V_2 -> V_10 , V_2 -> V_8 ,
V_149 , V_147 , V_148 ) ;
F_31 ( V_2 ) ;
} else
V_64 = F_25 ( V_2 ) ;
return V_64 ;
}
static int F_87 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 ,
const struct V_93 * V_94 ,
unsigned V_147 , unsigned V_148 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
struct V_84 * V_149 = F_85 ( V_94 ) ;
struct V_1 * V_2 ;
int V_64 ;
V_2 = F_35 ( V_5 , V_7 , V_94 ) ;
if ( ! F_6 ( V_2 ) ) {
V_64 = F_88 ( V_2 -> V_10 , V_2 -> V_8 ,
V_149 , V_147 , V_148 ) ;
F_31 ( V_2 ) ;
} else
V_64 = F_25 ( V_2 ) ;
return V_64 ;
}
static int F_89 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_150 * V_151 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_151 = & V_106 -> V_27 -> V_30 . V_41 ;
V_7 = F_42 ( V_5 , V_106 ) ;
V_2 = F_29 ( V_5 , V_7 , F_32 ( V_151 -> V_152 ) ) ;
if ( F_6 ( V_2 ) )
return F_25 ( V_2 ) ;
V_2 -> V_8 -> V_30 . V_41 . V_153 = V_151 -> V_153 ;
F_31 ( V_2 ) ;
return F_60 ( V_5 , V_106 ) ;
}
static void F_90 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_106 ) ;
struct V_1 * V_2 ;
unsigned int * V_154 = & V_106 -> V_27 -> V_30 . V_44 . V_155 ;
* V_154 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
struct V_16 * V_156 = V_2 -> V_8 ;
F_1 ( V_2 ) ;
F_61 ( V_2 -> V_10 , V_156 ) ;
F_2 ( V_2 ) ;
if ( V_156 -> V_77 == 0 )
* V_154 += V_156 -> V_30 . V_44 . V_155 ;
}
}
static void F_91 ( const struct V_4 * V_5 ,
const struct V_105 * V_106 )
{
struct V_57 * V_58 = F_36 ( V_106 -> V_107 ) ;
if ( F_45 ( & V_58 -> V_109 ) )
F_46 ( & V_58 -> V_110 ) ;
}
static void F_92 ( const struct V_4 * V_5 ,
struct V_105 * V_106 )
{
F_40 () ;
}
int F_93 ( const struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_94 ( V_5 ) ;
struct V_57 * V_58 = F_36 ( V_38 ) ;
F_95 ( & V_7 -> V_116 ) ;
F_39 ( V_7 , V_58 , V_17 ) ;
if ( V_17 -> V_77 == 0 ) {
V_17 -> V_77 = F_37 ( V_5 , V_7 , V_17 ) ;
if ( V_17 -> V_77 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_38 , & V_157 ) ;
F_97 ( & V_58 -> V_109 ) ;
}
}
return V_17 -> V_77 ;
}
int F_98 ( const struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_16 * V_17 )
{
struct V_57 * V_58 = F_36 ( V_38 ) ;
struct V_6 * V_7 = F_94 ( V_5 ) ;
int V_64 ;
V_7 -> V_23 = V_58 ;
switch ( V_17 -> V_28 ) {
default:
F_40 () ;
case V_104 :
case V_49 :
V_64 = 0 ;
break;
case V_43 :
case V_29 :
V_64 = 1 ;
break;
case V_50 :
V_64 = - V_158 ;
break;
case V_36 :
V_64 = - V_159 ;
F_99 ( L_3 V_160 L_4 ,
F_100 ( F_101 ( & V_38 -> V_61 ) ) ) ;
break;
}
if ( V_64 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_38 , & V_161 ) ;
F_97 ( & V_58 -> V_109 ) ;
}
V_17 -> V_77 = V_64 < 0 ? V_64 : 0 ;
return V_64 != 0 ;
}
int F_102 ( const struct V_4 * V_5 , struct V_37 * V_38 ,
struct V_16 * V_17 )
{
struct V_57 * V_58 = F_36 ( V_38 ) ;
struct V_6 * V_7 = F_94 ( V_5 ) ;
int V_64 ;
F_18 ( V_58 -> V_24 != NULL ) ;
V_7 -> V_23 = V_58 ;
switch ( V_17 -> V_28 ) {
default:
F_103 ( 0 , L_5 , V_17 -> V_28 ) ;
case V_104 :
case V_43 :
V_64 = 1 ;
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_17 -> V_162 = 1 ;
V_64 = - V_163 ;
break;
case V_49 :
case V_50 :
case V_36 :
V_17 -> V_162 = 1 ;
V_64 = - V_163 ;
break;
}
if ( V_64 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_38 , & V_161 ) ;
F_97 ( & V_58 -> V_109 ) ;
}
V_17 -> V_77 = V_64 < 0 ? V_64 : 0 ;
return V_64 != 0 ;
}
