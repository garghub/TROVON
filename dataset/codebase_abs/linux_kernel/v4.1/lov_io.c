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
V_17 -> V_30 . V_31 . V_34 = V_25 -> V_30 . V_31 . V_34 ;
if ( F_9 ( V_17 ) ) {
T_1 V_35 = V_25 -> V_30 . V_31 . V_32 . V_36 ;
V_35 = F_10 ( V_22 , V_35 , V_18 ) ;
V_17 -> V_30 . V_31 . V_32 . V_36 = V_35 ;
}
break;
}
case V_37 : {
struct V_38 * V_39 = V_25 -> V_40 ;
T_1 V_41 = F_11 ( V_39 , V_25 -> V_30 . V_42 . V_43 ) ;
V_17 -> V_30 . V_42 = V_25 -> V_30 . V_42 ;
V_41 = F_10 ( V_22 , V_41 , V_18 ) ;
V_17 -> V_30 . V_42 . V_43 = F_12 ( V_39 , V_41 ) ;
break;
}
case V_44 : {
V_17 -> V_30 . V_45 . V_46 = V_19 ;
V_17 -> V_30 . V_45 . V_47 = V_20 ;
V_17 -> V_30 . V_45 . V_48 = V_25 -> V_30 . V_45 . V_48 ;
V_17 -> V_30 . V_45 . V_49 = V_25 -> V_30 . V_45 . V_49 ;
V_17 -> V_30 . V_45 . V_50 = V_25 -> V_30 . V_45 . V_50 ;
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
struct V_38 * V_65 ;
struct V_16 * V_17 = V_7 -> V_26 . V_27 ;
int V_18 = V_2 -> V_12 ;
int V_66 ;
F_18 ( V_2 -> V_8 == NULL ) ;
F_18 ( V_2 -> V_10 == NULL ) ;
F_18 ( V_2 -> V_12 < V_7 -> V_67 ) ;
if ( F_19 ( F_20 ( V_60 ) -> V_68 [ V_18 ] == NULL ) )
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
if ( F_6 ( V_2 -> V_10 ) )
V_66 = F_25 ( V_2 -> V_10 ) ;
if ( V_66 == 0 ) {
if ( V_7 -> V_11 == 0 ) {
V_2 -> V_8 = & V_7 -> V_76 ;
V_7 -> V_13 = V_18 ;
} else {
F_26 ( V_2 -> V_8 ) ;
if ( V_2 -> V_8 == NULL )
V_66 = - V_77 ;
}
}
}
if ( V_66 == 0 ) {
V_65 = F_27 ( F_20 ( V_60 ) -> V_68 [ V_18 ] ) ;
V_8 = V_2 -> V_8 ;
V_8 -> V_40 = V_65 ;
V_8 -> V_78 = 0 ;
V_8 -> V_79 = V_17 ;
V_8 -> V_80 = V_17 -> V_80 ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_81 = V_17 -> V_81 ;
V_8 -> V_82 = V_17 -> V_82 ;
F_1 ( V_2 ) ;
V_66 = F_28 ( V_2 -> V_10 , V_8 ,
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
struct V_1 * F_29 ( const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_18 )
{
int V_83 ;
struct V_1 * V_2 = & V_7 -> V_84 [ V_18 ] ;
F_18 ( V_18 < V_7 -> V_67 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_12 = V_18 ;
V_83 = F_15 ( V_5 , V_7 , V_2 ) ;
} else
V_83 = 0 ;
if ( V_83 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_30 ( V_83 ) ;
return V_2 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_32 ( const struct V_85 * V_86 )
{
struct V_87 * V_88 ;
V_88 = F_33 (
F_34 ( V_86 -> V_89 -> V_90 -> V_63 . V_91 ,
& V_92 ) ) ;
F_18 ( V_88 != NULL ) ;
return V_88 -> V_93 ;
}
struct V_1 * F_35 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_94 * V_95 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_85 * V_86 = V_95 -> V_96 ;
int V_18 ;
F_18 ( V_7 -> V_26 . V_27 != NULL ) ;
F_18 ( F_36 ( V_95 -> V_97 ) == V_7 -> V_23 ) ;
F_18 ( V_22 != NULL ) ;
F_18 ( V_7 -> V_98 > 0 ) ;
V_18 = F_32 ( V_86 ) ;
return F_29 ( V_5 , V_7 , V_18 ) ;
}
static int F_37 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
int V_66 ;
F_18 ( V_7 -> V_23 != NULL ) ;
F_38 ( V_7 -> V_84 ,
V_22 -> V_99 * sizeof( V_7 -> V_84 [ 0 ] ) ) ;
if ( V_7 -> V_84 != NULL ) {
V_7 -> V_98 = V_7 -> V_67 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_11 = 0 ;
V_66 = 0 ;
} else
V_66 = - V_77 ;
return V_66 ;
}
static void F_39 ( struct V_6 * V_7 ,
struct V_59 * V_39 , struct V_16 * V_17 )
{
V_17 -> V_78 = 0 ;
V_7 -> V_23 = V_39 ;
F_18 ( V_39 -> V_24 != NULL ) ;
V_7 -> V_67 = V_39 -> V_24 -> V_99 ;
switch ( V_17 -> V_28 ) {
case V_51 :
case V_52 :
V_7 -> V_100 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_101 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
V_7 -> V_102 = V_7 -> V_101 ;
if ( F_14 ( V_17 ) ) {
F_18 ( V_17 -> V_28 == V_52 ) ;
V_7 -> V_100 = 0 ;
V_7 -> V_101 = V_103 ;
}
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_7 -> V_100 = V_17 -> V_30 . V_31 . V_32 . V_36 ;
else
V_7 -> V_100 = 0 ;
V_7 -> V_101 = V_103 ;
break;
case V_37 : {
T_2 V_104 = V_17 -> V_30 . V_42 . V_43 ;
V_7 -> V_100 = F_11 ( V_17 -> V_40 , V_104 ) ;
V_7 -> V_101 = F_11 ( V_17 -> V_40 , V_104 + 1 ) ;
break;
}
case V_44 : {
V_7 -> V_100 = V_17 -> V_30 . V_45 . V_46 ;
V_7 -> V_101 = V_17 -> V_30 . V_45 . V_47 ;
break;
}
case V_105 :
V_7 -> V_100 = 0 ;
V_7 -> V_101 = V_103 ;
break;
default:
F_40 () ;
}
}
static void F_41 ( const struct V_4 * V_5 , const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
struct V_59 * V_60 = F_36 ( V_107 -> V_108 ) ;
int V_109 ;
if ( V_7 -> V_84 != NULL ) {
for ( V_109 = 0 ; V_109 < V_7 -> V_98 ; V_109 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_84 [ V_109 ] ) ;
F_43 ( V_7 -> V_84 ,
V_7 -> V_98 * sizeof( V_7 -> V_84 [ 0 ] ) ) ;
V_7 -> V_98 = 0 ;
}
F_18 ( F_44 ( & V_60 -> V_110 ) > 0 ) ;
if ( F_45 ( & V_60 -> V_110 ) )
F_46 ( & V_60 -> V_111 ) ;
}
static T_3 F_47 ( T_3 V_112 , int V_113 )
{
if ( V_112 != V_103 )
V_112 += V_113 ;
return V_112 ;
}
static int F_48 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_1 * V_2 ;
T_3 V_114 ;
T_3 V_19 ;
T_3 V_20 ;
int V_18 ;
int V_83 = 0 ;
V_114 = F_47 ( V_7 -> V_101 , - 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_67 ; V_18 ++ ) {
if ( ! F_49 ( V_22 , V_18 , V_7 -> V_100 ,
V_114 , & V_19 , & V_20 ) )
continue;
if ( F_19 ( F_20 ( V_7 -> V_23 ) -> V_68 [ V_18 ] == NULL ) ) {
if ( V_107 -> V_27 -> V_28 == V_51 ||
V_107 -> V_27 -> V_28 == V_52 ||
V_107 -> V_27 -> V_28 == V_37 )
return - V_69 ;
continue;
}
V_20 = F_47 ( V_20 , 1 ) ;
V_2 = F_29 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
F_8 ( V_2 -> V_8 , V_7 , V_18 ,
V_19 , V_20 ) ;
V_83 = F_50 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_31 ( V_2 ) ;
F_51 ( V_115 , L_1 ,
V_18 , V_19 , V_20 ) ;
} else
V_83 = F_25 ( V_2 ) ;
if ( ! V_83 )
F_52 ( & V_2 -> V_116 , & V_7 -> V_117 ) ;
else
break;
}
return V_83 ;
}
static int F_53 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
struct V_16 * V_17 = V_107 -> V_27 ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
T_4 V_19 = V_17 -> V_30 . V_56 . V_57 ;
T_1 V_118 ;
unsigned long V_119 = V_22 -> V_120 ;
F_18 ( V_17 -> V_28 == V_51 || V_17 -> V_28 == V_52 ) ;
if ( V_7 -> V_98 != 1 && ! F_14 ( V_17 ) ) {
F_54 ( V_19 , V_119 ) ;
V_118 = ( V_19 + 1 ) * V_119 ;
if ( V_118 <= V_19 * V_119 )
V_118 = ~ 0ull ;
V_17 -> V_121 = V_118 < V_7 -> V_102 ;
V_17 -> V_30 . V_56 . V_58 = F_55 ( T_1 , V_7 -> V_102 ,
V_118 ) - V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_100 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_101 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
F_51 ( V_115 , L_2 ,
( T_4 ) V_19 , V_7 -> V_100 , V_7 -> V_101 ,
( T_4 ) V_7 -> V_102 ) ;
}
return F_48 ( V_5 , V_107 ) ;
}
static int F_56 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_57)( const struct V_4 * , struct V_16 * ) )
{
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_83 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_83 = F_57 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
if ( V_83 )
break;
if ( V_25 -> V_78 == 0 )
V_25 -> V_78 = V_2 -> V_8 -> V_78 ;
}
return V_83 ;
}
static int F_59 ( const struct V_4 * V_5 , const struct V_106 * V_107 )
{
return F_56 ( V_5 , F_42 ( V_5 , V_107 ) , V_122 ) ;
}
static int F_60 ( const struct V_4 * V_5 , const struct V_106 * V_107 )
{
return F_56 ( V_5 , F_42 ( V_5 , V_107 ) , V_123 ) ;
}
static int F_61 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( V_17 -> V_124 == V_125 )
F_62 ( V_5 , V_17 ) ;
else
V_17 -> V_124 = V_126 ;
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
static void F_67 ( const struct V_4 * V_5 , const struct V_106 * V_107 )
{
int V_83 ;
V_83 = F_56 ( V_5 , F_42 ( V_5 , V_107 ) , F_61 ) ;
F_18 ( V_83 == 0 ) ;
}
static void F_68 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
int V_83 ;
V_83 = F_56 ( V_5 , V_7 , F_63 ) ;
F_18 ( V_83 == 0 ) ;
while ( ! F_69 ( & V_7 -> V_117 ) )
F_70 ( V_7 -> V_117 . V_118 ) ;
}
static void F_71 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 )
{
int V_83 ;
V_83 = F_56 ( V_5 , F_42 ( V_5 , V_107 ) , F_65 ) ;
F_18 ( V_83 == 0 ) ;
}
static struct V_127 * F_72 ( struct V_61 * V_62 ,
struct V_127 * V_128 ,
int V_129 , int V_130 )
{
return V_130 ? & V_128 [ V_129 ] : & V_62 -> V_72 [ V_129 ] -> V_131 ;
}
static int F_73 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 ,
enum V_132 V_133 , struct V_134 * V_135 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
struct V_59 * V_39 = V_7 -> V_23 ;
struct V_61 * V_62 = F_16 ( F_17 ( V_39 ) -> V_63 . V_64 ) ;
struct V_127 * V_128 = & V_135 -> V_136 ;
struct V_134 * V_137 = & F_74 ( V_5 ) -> V_138 ;
struct V_127 * V_139 = NULL ;
struct V_85 * V_86 ;
struct V_85 * V_140 ;
int V_18 ;
#define F_75 ( V_18 ) lov_io_submit_qin(ld, stripes_qin, stripe, alloc)
int V_83 = 0 ;
int V_130 =
! ( V_141 -> V_142 & V_143 ) ;
if ( V_7 -> V_11 == 1 ) {
int V_129 = V_7 -> V_13 ;
struct V_1 * V_2 ;
F_18 ( V_129 < V_7 -> V_98 ) ;
V_2 = F_29 ( V_5 , V_7 , V_129 ) ;
F_18 ( ! F_6 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_76 ) ;
V_83 = F_76 ( V_2 -> V_10 , V_2 -> V_8 ,
V_133 , V_135 ) ;
F_31 ( V_2 ) ;
return V_83 ;
}
F_18 ( V_7 -> V_84 != NULL ) ;
if ( V_130 ) {
F_38 ( V_139 ,
sizeof( * V_139 ) * V_7 -> V_98 ) ;
if ( V_139 == NULL )
return - V_77 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_98 ; V_18 ++ )
F_77 ( & V_139 [ V_18 ] ) ;
} else {
F_78 ( & V_62 -> V_71 ) ;
V_7 -> V_70 = 1 ;
}
F_79 ( V_137 ) ;
F_80 (page, tmp, qin) {
V_18 = F_32 ( V_86 ) ;
F_81 ( F_75 ( V_18 ) , V_128 , V_86 ) ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_98 ; V_18 ++ ) {
struct V_1 * V_2 ;
struct V_127 * V_144 = F_75 ( V_18 ) ;
if ( F_69 ( & V_144 -> V_145 ) )
continue;
F_82 ( V_144 , & V_137 -> V_136 ) ;
V_2 = F_29 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
V_83 = F_76 ( V_2 -> V_10 , V_2 -> V_8 ,
V_133 , V_137 ) ;
F_31 ( V_2 ) ;
} else
V_83 = F_25 ( V_2 ) ;
F_82 ( & V_137 -> V_136 , & V_135 -> V_136 ) ;
F_82 ( & V_137 -> V_146 , & V_135 -> V_146 ) ;
if ( V_83 != 0 )
break;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_98 ; V_18 ++ ) {
struct V_127 * V_144 = F_75 ( V_18 ) ;
if ( F_69 ( & V_144 -> V_145 ) )
continue;
F_82 ( V_144 , V_128 ) ;
}
if ( V_130 ) {
F_43 ( V_139 ,
sizeof( * V_139 ) * V_7 -> V_98 ) ;
} else {
int V_109 ;
for ( V_109 = 0 ; V_109 < V_7 -> V_98 ; V_109 ++ ) {
struct V_16 * V_147 = V_7 -> V_84 [ V_109 ] . V_8 ;
if ( V_147 && V_147 == & V_62 -> V_72 [ V_109 ] -> V_73 )
F_3 ( V_5 , V_7 , & V_7 -> V_84 [ V_109 ] ) ;
}
V_7 -> V_70 = 0 ;
F_83 ( & V_62 -> V_71 ) ;
}
return V_83 ;
#undef F_75
}
static int F_84 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 ,
const struct V_94 * V_95 ,
unsigned V_148 , unsigned V_149 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
struct V_85 * V_150 = F_85 ( V_95 ) ;
struct V_1 * V_2 ;
int V_66 ;
V_2 = F_35 ( V_5 , V_7 , V_95 ) ;
if ( ! F_6 ( V_2 ) ) {
V_66 = F_86 ( V_2 -> V_10 , V_2 -> V_8 ,
V_150 , V_148 , V_149 ) ;
F_31 ( V_2 ) ;
} else
V_66 = F_25 ( V_2 ) ;
return V_66 ;
}
static int F_87 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 ,
const struct V_94 * V_95 ,
unsigned V_148 , unsigned V_149 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
struct V_85 * V_150 = F_85 ( V_95 ) ;
struct V_1 * V_2 ;
int V_66 ;
V_2 = F_35 ( V_5 , V_7 , V_95 ) ;
if ( ! F_6 ( V_2 ) ) {
V_66 = F_88 ( V_2 -> V_10 , V_2 -> V_8 ,
V_150 , V_148 , V_149 ) ;
F_31 ( V_2 ) ;
} else
V_66 = F_25 ( V_2 ) ;
return V_66 ;
}
static int F_89 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 )
{
struct V_151 * V_152 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_152 = & V_107 -> V_27 -> V_30 . V_42 ;
V_7 = F_42 ( V_5 , V_107 ) ;
V_2 = F_29 ( V_5 , V_7 , F_32 ( V_152 -> V_153 ) ) ;
V_2 -> V_8 -> V_30 . V_42 . V_154 = V_152 -> V_154 ;
F_31 ( V_2 ) ;
return F_60 ( V_5 , V_107 ) ;
}
static void F_90 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_107 ) ;
struct V_1 * V_2 ;
unsigned int * V_155 = & V_107 -> V_27 -> V_30 . V_45 . V_156 ;
* V_155 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
struct V_16 * V_157 = V_2 -> V_8 ;
F_1 ( V_2 ) ;
F_61 ( V_2 -> V_10 , V_157 ) ;
F_2 ( V_2 ) ;
if ( V_157 -> V_78 == 0 )
* V_155 += V_157 -> V_30 . V_45 . V_156 ;
}
}
static void F_91 ( const struct V_4 * V_5 ,
const struct V_106 * V_107 )
{
struct V_59 * V_60 = F_36 ( V_107 -> V_108 ) ;
if ( F_45 ( & V_60 -> V_110 ) )
F_46 ( & V_60 -> V_111 ) ;
}
static void F_92 ( const struct V_4 * V_5 ,
struct V_106 * V_107 )
{
F_40 () ;
}
int F_93 ( const struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_94 ( V_5 ) ;
struct V_59 * V_60 = F_36 ( V_39 ) ;
F_95 ( & V_7 -> V_117 ) ;
F_39 ( V_7 , V_60 , V_17 ) ;
if ( V_17 -> V_78 == 0 ) {
V_17 -> V_78 = F_37 ( V_5 , V_7 , V_17 ) ;
if ( V_17 -> V_78 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_39 , & V_158 ) ;
F_97 ( & V_60 -> V_110 ) ;
}
}
return V_17 -> V_78 ;
}
int F_98 ( const struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_59 * V_60 = F_36 ( V_39 ) ;
struct V_6 * V_7 = F_94 ( V_5 ) ;
int V_66 ;
V_7 -> V_23 = V_60 ;
switch ( V_17 -> V_28 ) {
default:
F_40 () ;
case V_105 :
case V_51 :
V_66 = 0 ;
break;
case V_44 :
case V_29 :
V_66 = 1 ;
break;
case V_52 :
V_66 = - V_159 ;
break;
case V_37 :
V_66 = - V_160 ;
F_99 ( L_3 V_161 L_4 ,
F_100 ( F_101 ( & V_39 -> V_63 ) ) ) ;
break;
}
if ( V_66 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_39 , & V_162 ) ;
F_97 ( & V_60 -> V_110 ) ;
}
V_17 -> V_78 = V_66 < 0 ? V_66 : 0 ;
return V_66 != 0 ;
}
int F_102 ( const struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_59 * V_60 = F_36 ( V_39 ) ;
struct V_6 * V_7 = F_94 ( V_5 ) ;
int V_66 ;
F_18 ( V_60 -> V_24 != NULL ) ;
V_7 -> V_23 = V_60 ;
switch ( V_17 -> V_28 ) {
default:
F_103 ( 0 , L_5 , V_17 -> V_28 ) ;
case V_105 :
case V_44 :
V_66 = 1 ;
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_17 -> V_163 = 1 ;
V_66 = - V_164 ;
break;
case V_51 :
case V_52 :
case V_37 :
V_17 -> V_163 = 1 ;
V_66 = - V_164 ;
break;
}
if ( V_66 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_39 , & V_162 ) ;
F_97 ( & V_60 -> V_110 ) ;
}
V_17 -> V_78 = V_66 < 0 ? V_66 : 0 ;
return V_66 != 0 ;
}
