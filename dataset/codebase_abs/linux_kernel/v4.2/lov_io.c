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
V_2 -> V_8 = F_26 ( sizeof( * V_2 -> V_8 ) ,
V_77 ) ;
if ( V_2 -> V_8 == NULL )
V_66 = - V_78 ;
}
}
}
if ( V_66 == 0 ) {
V_65 = F_27 ( F_20 ( V_60 ) -> V_68 [ V_18 ] ) ;
V_8 = V_2 -> V_8 ;
V_8 -> V_40 = V_65 ;
V_8 -> V_79 = 0 ;
V_8 -> V_80 = V_17 ;
V_8 -> V_81 = V_17 -> V_81 ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_82 = V_17 -> V_82 ;
V_8 -> V_83 = V_17 -> V_83 ;
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
int V_84 ;
struct V_1 * V_2 = & V_7 -> V_85 [ V_18 ] ;
F_18 ( V_18 < V_7 -> V_67 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_12 = V_18 ;
V_84 = F_15 ( V_5 , V_7 , V_2 ) ;
} else
V_84 = 0 ;
if ( V_84 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_30 ( V_84 ) ;
return V_2 ;
}
void F_31 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_32 ( const struct V_86 * V_87 )
{
struct V_88 * V_89 ;
V_89 = F_33 (
F_34 ( V_87 -> V_90 -> V_91 -> V_63 . V_92 ,
& V_93 ) ) ;
F_18 ( V_89 != NULL ) ;
return V_89 -> V_94 ;
}
struct V_1 * F_35 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_95 * V_96 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_86 * V_87 = V_96 -> V_97 ;
int V_18 ;
F_18 ( V_7 -> V_26 . V_27 != NULL ) ;
F_18 ( F_36 ( V_96 -> V_98 ) == V_7 -> V_23 ) ;
F_18 ( V_22 != NULL ) ;
F_18 ( V_7 -> V_99 > 0 ) ;
V_18 = F_32 ( V_87 ) ;
return F_29 ( V_5 , V_7 , V_18 ) ;
}
static int F_37 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
int V_66 ;
F_18 ( V_7 -> V_23 != NULL ) ;
V_7 -> V_85 =
F_38 ( V_22 -> V_100 *
sizeof( V_7 -> V_85 [ 0 ] ) ,
V_77 ) ;
if ( V_7 -> V_85 != NULL ) {
V_7 -> V_99 = V_7 -> V_67 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_11 = 0 ;
V_66 = 0 ;
} else
V_66 = - V_78 ;
return V_66 ;
}
static void F_39 ( struct V_6 * V_7 ,
struct V_59 * V_39 , struct V_16 * V_17 )
{
V_17 -> V_79 = 0 ;
V_7 -> V_23 = V_39 ;
F_18 ( V_39 -> V_24 != NULL ) ;
V_7 -> V_67 = V_39 -> V_24 -> V_100 ;
switch ( V_17 -> V_28 ) {
case V_51 :
case V_52 :
V_7 -> V_101 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_102 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
V_7 -> V_103 = V_7 -> V_102 ;
if ( F_14 ( V_17 ) ) {
F_18 ( V_17 -> V_28 == V_52 ) ;
V_7 -> V_101 = 0 ;
V_7 -> V_102 = V_104 ;
}
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_7 -> V_101 = V_17 -> V_30 . V_31 . V_32 . V_36 ;
else
V_7 -> V_101 = 0 ;
V_7 -> V_102 = V_104 ;
break;
case V_37 : {
T_2 V_105 = V_17 -> V_30 . V_42 . V_43 ;
V_7 -> V_101 = F_11 ( V_17 -> V_40 , V_105 ) ;
V_7 -> V_102 = F_11 ( V_17 -> V_40 , V_105 + 1 ) ;
break;
}
case V_44 : {
V_7 -> V_101 = V_17 -> V_30 . V_45 . V_46 ;
V_7 -> V_102 = V_17 -> V_30 . V_45 . V_47 ;
break;
}
case V_106 :
V_7 -> V_101 = 0 ;
V_7 -> V_102 = V_104 ;
break;
default:
F_40 () ;
}
}
static void F_41 ( const struct V_4 * V_5 , const struct V_107 * V_108 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
struct V_59 * V_60 = F_36 ( V_108 -> V_109 ) ;
int V_110 ;
if ( V_7 -> V_85 != NULL ) {
for ( V_110 = 0 ; V_110 < V_7 -> V_99 ; V_110 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_85 [ V_110 ] ) ;
F_43 ( V_7 -> V_85 ) ;
V_7 -> V_99 = 0 ;
}
F_18 ( F_44 ( & V_60 -> V_111 ) > 0 ) ;
if ( F_45 ( & V_60 -> V_111 ) )
F_46 ( & V_60 -> V_112 ) ;
}
static T_3 F_47 ( T_3 V_113 , int V_114 )
{
if ( V_113 != V_104 )
V_113 += V_114 ;
return V_113 ;
}
static int F_48 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_1 * V_2 ;
T_3 V_115 ;
T_3 V_19 ;
T_3 V_20 ;
int V_18 ;
int V_84 = 0 ;
V_115 = F_47 ( V_7 -> V_102 , - 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_67 ; V_18 ++ ) {
if ( ! F_49 ( V_22 , V_18 , V_7 -> V_101 ,
V_115 , & V_19 , & V_20 ) )
continue;
if ( F_19 ( F_20 ( V_7 -> V_23 ) -> V_68 [ V_18 ] == NULL ) ) {
if ( V_108 -> V_27 -> V_28 == V_51 ||
V_108 -> V_27 -> V_28 == V_52 ||
V_108 -> V_27 -> V_28 == V_37 )
return - V_69 ;
continue;
}
V_20 = F_47 ( V_20 , 1 ) ;
V_2 = F_29 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
F_8 ( V_2 -> V_8 , V_7 , V_18 ,
V_19 , V_20 ) ;
V_84 = F_50 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_31 ( V_2 ) ;
F_51 ( V_116 , L_1 ,
V_18 , V_19 , V_20 ) ;
} else
V_84 = F_25 ( V_2 ) ;
if ( ! V_84 )
F_52 ( & V_2 -> V_117 , & V_7 -> V_118 ) ;
else
break;
}
return V_84 ;
}
static int F_53 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
struct V_16 * V_17 = V_108 -> V_27 ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
T_4 V_19 = V_17 -> V_30 . V_56 . V_57 ;
T_1 V_119 ;
unsigned long V_120 = V_22 -> V_121 ;
F_18 ( V_17 -> V_28 == V_51 || V_17 -> V_28 == V_52 ) ;
if ( V_7 -> V_99 != 1 && ! F_14 ( V_17 ) ) {
F_54 ( V_19 , V_120 ) ;
V_119 = ( V_19 + 1 ) * V_120 ;
if ( V_119 <= V_19 * V_120 )
V_119 = ~ 0ull ;
V_17 -> V_122 = V_119 < V_7 -> V_103 ;
V_17 -> V_30 . V_56 . V_58 = F_55 ( T_1 , V_7 -> V_103 ,
V_119 ) - V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_101 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_102 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
F_51 ( V_116 , L_2 ,
( T_4 ) V_19 , V_7 -> V_101 , V_7 -> V_102 ,
( T_4 ) V_7 -> V_103 ) ;
}
return F_48 ( V_5 , V_108 ) ;
}
static int F_56 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_57)( const struct V_4 * , struct V_16 * ) )
{
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_84 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_84 = F_57 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
if ( V_84 )
break;
if ( V_25 -> V_79 == 0 )
V_25 -> V_79 = V_2 -> V_8 -> V_79 ;
}
return V_84 ;
}
static int F_59 ( const struct V_4 * V_5 , const struct V_107 * V_108 )
{
return F_56 ( V_5 , F_42 ( V_5 , V_108 ) , V_123 ) ;
}
static int F_60 ( const struct V_4 * V_5 , const struct V_107 * V_108 )
{
return F_56 ( V_5 , F_42 ( V_5 , V_108 ) , V_124 ) ;
}
static int F_61 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( V_17 -> V_125 == V_126 )
F_62 ( V_5 , V_17 ) ;
else
V_17 -> V_125 = V_127 ;
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
static void F_67 ( const struct V_4 * V_5 , const struct V_107 * V_108 )
{
int V_84 ;
V_84 = F_56 ( V_5 , F_42 ( V_5 , V_108 ) , F_61 ) ;
F_18 ( V_84 == 0 ) ;
}
static void F_68 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
int V_84 ;
V_84 = F_56 ( V_5 , V_7 , F_63 ) ;
F_18 ( V_84 == 0 ) ;
while ( ! F_69 ( & V_7 -> V_118 ) )
F_70 ( V_7 -> V_118 . V_119 ) ;
}
static void F_71 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 )
{
int V_84 ;
V_84 = F_56 ( V_5 , F_42 ( V_5 , V_108 ) , F_65 ) ;
F_18 ( V_84 == 0 ) ;
}
static struct V_128 * F_72 ( struct V_61 * V_62 ,
struct V_128 * V_129 ,
int V_130 , int V_131 )
{
return V_131 ? & V_129 [ V_130 ] : & V_62 -> V_72 [ V_130 ] -> V_132 ;
}
static int F_73 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 ,
enum V_133 V_134 , struct V_135 * V_136 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
struct V_59 * V_39 = V_7 -> V_23 ;
struct V_61 * V_62 = F_16 ( F_17 ( V_39 ) -> V_63 . V_64 ) ;
struct V_128 * V_129 = & V_136 -> V_137 ;
struct V_135 * V_138 = & F_74 ( V_5 ) -> V_139 ;
struct V_128 * V_140 = NULL ;
struct V_86 * V_87 ;
struct V_86 * V_141 ;
int V_18 ;
#define F_75 ( V_18 ) lov_io_submit_qin(ld, stripes_qin, stripe, alloc)
int V_84 = 0 ;
int V_131 =
! ( V_142 -> V_143 & V_144 ) ;
if ( V_7 -> V_11 == 1 ) {
int V_130 = V_7 -> V_13 ;
struct V_1 * V_2 ;
F_18 ( V_130 < V_7 -> V_99 ) ;
V_2 = F_29 ( V_5 , V_7 , V_130 ) ;
F_18 ( ! F_6 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_76 ) ;
V_84 = F_76 ( V_2 -> V_10 , V_2 -> V_8 ,
V_134 , V_136 ) ;
F_31 ( V_2 ) ;
return V_84 ;
}
F_18 ( V_7 -> V_85 != NULL ) ;
if ( V_131 ) {
V_140 =
F_38 ( sizeof( * V_140 ) *
V_7 -> V_99 ,
V_77 ) ;
if ( V_140 == NULL )
return - V_78 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_99 ; V_18 ++ )
F_77 ( & V_140 [ V_18 ] ) ;
} else {
F_78 ( & V_62 -> V_71 ) ;
V_7 -> V_70 = 1 ;
}
F_79 ( V_138 ) ;
F_80 (page, tmp, qin) {
V_18 = F_32 ( V_87 ) ;
F_81 ( F_75 ( V_18 ) , V_129 , V_87 ) ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_99 ; V_18 ++ ) {
struct V_1 * V_2 ;
struct V_128 * V_145 = F_75 ( V_18 ) ;
if ( F_69 ( & V_145 -> V_146 ) )
continue;
F_82 ( V_145 , & V_138 -> V_137 ) ;
V_2 = F_29 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
V_84 = F_76 ( V_2 -> V_10 , V_2 -> V_8 ,
V_134 , V_138 ) ;
F_31 ( V_2 ) ;
} else
V_84 = F_25 ( V_2 ) ;
F_82 ( & V_138 -> V_137 , & V_136 -> V_137 ) ;
F_82 ( & V_138 -> V_147 , & V_136 -> V_147 ) ;
if ( V_84 != 0 )
break;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_99 ; V_18 ++ ) {
struct V_128 * V_145 = F_75 ( V_18 ) ;
if ( F_69 ( & V_145 -> V_146 ) )
continue;
F_82 ( V_145 , V_129 ) ;
}
if ( V_131 ) {
F_43 ( V_140 ) ;
} else {
int V_110 ;
for ( V_110 = 0 ; V_110 < V_7 -> V_99 ; V_110 ++ ) {
struct V_16 * V_148 = V_7 -> V_85 [ V_110 ] . V_8 ;
if ( V_148 && V_148 == & V_62 -> V_72 [ V_110 ] -> V_73 )
F_3 ( V_5 , V_7 , & V_7 -> V_85 [ V_110 ] ) ;
}
V_7 -> V_70 = 0 ;
F_83 ( & V_62 -> V_71 ) ;
}
return V_84 ;
#undef F_75
}
static int F_84 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 ,
const struct V_95 * V_96 ,
unsigned V_149 , unsigned V_150 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
struct V_86 * V_151 = F_85 ( V_96 ) ;
struct V_1 * V_2 ;
int V_66 ;
V_2 = F_35 ( V_5 , V_7 , V_96 ) ;
if ( ! F_6 ( V_2 ) ) {
V_66 = F_86 ( V_2 -> V_10 , V_2 -> V_8 ,
V_151 , V_149 , V_150 ) ;
F_31 ( V_2 ) ;
} else
V_66 = F_25 ( V_2 ) ;
return V_66 ;
}
static int F_87 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 ,
const struct V_95 * V_96 ,
unsigned V_149 , unsigned V_150 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
struct V_86 * V_151 = F_85 ( V_96 ) ;
struct V_1 * V_2 ;
int V_66 ;
V_2 = F_35 ( V_5 , V_7 , V_96 ) ;
if ( ! F_6 ( V_2 ) ) {
V_66 = F_88 ( V_2 -> V_10 , V_2 -> V_8 ,
V_151 , V_149 , V_150 ) ;
F_31 ( V_2 ) ;
} else
V_66 = F_25 ( V_2 ) ;
return V_66 ;
}
static int F_89 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 )
{
struct V_152 * V_153 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_153 = & V_108 -> V_27 -> V_30 . V_42 ;
V_7 = F_42 ( V_5 , V_108 ) ;
V_2 = F_29 ( V_5 , V_7 , F_32 ( V_153 -> V_154 ) ) ;
V_2 -> V_8 -> V_30 . V_42 . V_155 = V_153 -> V_155 ;
F_31 ( V_2 ) ;
return F_60 ( V_5 , V_108 ) ;
}
static void F_90 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 )
{
struct V_6 * V_7 = F_42 ( V_5 , V_108 ) ;
struct V_1 * V_2 ;
unsigned int * V_156 = & V_108 -> V_27 -> V_30 . V_45 . V_157 ;
* V_156 = 0 ;
F_58 (sub, &lio->lis_active, sub_linkage) {
struct V_16 * V_158 = V_2 -> V_8 ;
F_1 ( V_2 ) ;
F_61 ( V_2 -> V_10 , V_158 ) ;
F_2 ( V_2 ) ;
if ( V_158 -> V_79 == 0 )
* V_156 += V_158 -> V_30 . V_45 . V_157 ;
}
}
static void F_91 ( const struct V_4 * V_5 ,
const struct V_107 * V_108 )
{
struct V_59 * V_60 = F_36 ( V_108 -> V_109 ) ;
if ( F_45 ( & V_60 -> V_111 ) )
F_46 ( & V_60 -> V_112 ) ;
}
static void F_92 ( const struct V_4 * V_5 ,
struct V_107 * V_108 )
{
F_40 () ;
}
int F_93 ( const struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_94 ( V_5 ) ;
struct V_59 * V_60 = F_36 ( V_39 ) ;
F_95 ( & V_7 -> V_118 ) ;
F_39 ( V_7 , V_60 , V_17 ) ;
if ( V_17 -> V_79 == 0 ) {
V_17 -> V_79 = F_37 ( V_5 , V_7 , V_17 ) ;
if ( V_17 -> V_79 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_39 , & V_159 ) ;
F_97 ( & V_60 -> V_111 ) ;
}
}
return V_17 -> V_79 ;
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
case V_106 :
case V_51 :
V_66 = 0 ;
break;
case V_44 :
case V_29 :
V_66 = 1 ;
break;
case V_52 :
V_66 = - V_160 ;
break;
case V_37 :
V_66 = - V_161 ;
F_99 ( L_3 V_162 L_4 ,
F_100 ( F_101 ( & V_39 -> V_63 ) ) ) ;
break;
}
if ( V_66 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_39 , & V_163 ) ;
F_97 ( & V_60 -> V_111 ) ;
}
V_17 -> V_79 = V_66 < 0 ? V_66 : 0 ;
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
case V_106 :
case V_44 :
V_66 = 1 ;
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_17 -> V_164 = 1 ;
V_66 = - V_165 ;
break;
case V_51 :
case V_52 :
case V_37 :
V_17 -> V_164 = 1 ;
V_66 = - V_165 ;
break;
}
if ( V_66 == 0 ) {
F_96 ( V_17 , & V_7 -> V_26 , V_39 , & V_163 ) ;
F_97 ( & V_60 -> V_111 ) ;
}
V_17 -> V_79 = V_66 < 0 ? V_66 : 0 ;
return V_66 != 0 ;
}
