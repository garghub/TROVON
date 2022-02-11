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
switch( V_17 -> V_28 ) {
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
V_66 = 0 ;
V_2 -> V_9 = 0 ;
V_2 -> V_14 = 0 ;
if ( V_7 -> V_68 ) {
F_18 ( F_19 ( & V_62 -> V_69 ) ) ;
V_2 -> V_8 = & V_62 -> V_70 [ V_18 ] -> V_71 ;
V_2 -> V_10 = V_62 -> V_70 [ V_18 ] -> V_72 ;
V_2 -> V_14 = 1 ;
} else {
void * V_73 ;
V_73 = F_20 () ;
V_2 -> V_10 = F_21 ( & V_2 -> V_15 ) ;
F_22 ( V_73 ) ;
if ( F_6 ( V_2 -> V_10 ) )
V_66 = F_23 ( V_2 -> V_10 ) ;
if ( V_66 == 0 ) {
if ( V_7 -> V_11 == 0 ) {
V_2 -> V_8 = & V_7 -> V_74 ;
V_7 -> V_13 = V_18 ;
} else {
F_24 ( V_2 -> V_8 ) ;
if ( V_2 -> V_8 == NULL )
V_66 = - V_75 ;
}
}
}
if ( V_66 == 0 ) {
V_65 = F_25 ( F_26 ( V_60 ) -> V_76 [ V_18 ] ) ;
V_8 = V_2 -> V_8 ;
V_8 -> V_40 = V_65 ;
V_8 -> V_77 = 0 ;
V_8 -> V_78 = V_17 ;
V_8 -> V_79 = V_17 -> V_79 ;
V_8 -> V_28 = V_17 -> V_28 ;
V_8 -> V_80 = V_17 -> V_80 ;
F_1 ( V_2 ) ;
V_66 = F_27 ( V_2 -> V_10 , V_8 ,
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
struct V_1 * F_28 ( const struct V_4 * V_5 ,
struct V_6 * V_7 , int V_18 )
{
int V_81 ;
struct V_1 * V_2 = & V_7 -> V_82 [ V_18 ] ;
F_18 ( V_18 < V_7 -> V_67 ) ;
if ( ! V_2 -> V_9 ) {
V_2 -> V_12 = V_18 ;
V_81 = F_15 ( V_5 , V_7 , V_2 ) ;
} else
V_81 = 0 ;
if ( V_81 == 0 )
F_1 ( V_2 ) ;
else
V_2 = F_29 ( V_81 ) ;
return V_2 ;
}
void F_30 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
}
static int F_31 ( const struct V_83 * V_84 )
{
struct V_85 * V_86 ;
V_86 = F_32 (
F_33 ( V_84 -> V_87 -> V_88 -> V_63 . V_89 ,
& V_90 ) ) ;
F_18 ( V_86 != NULL ) ;
return V_86 -> V_91 ;
}
struct V_1 * F_34 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
const struct V_92 * V_93 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_83 * V_84 = V_93 -> V_94 ;
int V_18 ;
F_18 ( V_7 -> V_26 . V_27 != NULL ) ;
F_18 ( F_35 ( V_93 -> V_95 ) == V_7 -> V_23 ) ;
F_18 ( V_22 != NULL ) ;
F_18 ( V_7 -> V_96 > 0 ) ;
V_18 = F_31 ( V_84 ) ;
return F_28 ( V_5 , V_7 , V_18 ) ;
}
static int F_36 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
struct V_16 * V_17 )
{
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
int V_66 ;
F_18 ( V_7 -> V_23 != NULL ) ;
F_37 ( V_7 -> V_82 ,
V_22 -> V_97 * sizeof V_7 -> V_82 [ 0 ] ) ;
if ( V_7 -> V_82 != NULL ) {
V_7 -> V_96 = V_7 -> V_67 ;
V_7 -> V_13 = - 1 ;
V_7 -> V_11 = 0 ;
V_66 = 0 ;
} else
V_66 = - V_75 ;
return V_66 ;
}
static void F_38 ( struct V_6 * V_7 ,
struct V_59 * V_39 , struct V_16 * V_17 )
{
V_17 -> V_77 = 0 ;
V_7 -> V_23 = V_39 ;
F_18 ( V_39 -> V_24 != NULL ) ;
V_7 -> V_67 = V_39 -> V_24 -> V_97 ;
switch ( V_17 -> V_28 ) {
case V_51 :
case V_52 :
V_7 -> V_98 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_99 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
V_7 -> V_100 = V_7 -> V_99 ;
if ( F_14 ( V_17 ) ) {
F_18 ( V_17 -> V_28 == V_52 ) ;
V_7 -> V_98 = 0 ;
V_7 -> V_99 = V_101 ;
}
break;
case V_29 :
if ( F_9 ( V_17 ) )
V_7 -> V_98 = V_17 -> V_30 . V_31 . V_32 . V_36 ;
else
V_7 -> V_98 = 0 ;
V_7 -> V_99 = V_101 ;
break;
case V_37 : {
T_2 V_102 = V_17 -> V_30 . V_42 . V_43 ;
V_7 -> V_98 = F_11 ( V_17 -> V_40 , V_102 ) ;
V_7 -> V_99 = F_11 ( V_17 -> V_40 , V_102 + 1 ) ;
break;
}
case V_44 : {
V_7 -> V_98 = V_17 -> V_30 . V_45 . V_46 ;
V_7 -> V_99 = V_17 -> V_30 . V_45 . V_47 ;
break;
}
case V_103 :
V_7 -> V_98 = 0 ;
V_7 -> V_99 = V_101 ;
break;
default:
F_39 () ;
}
}
static void F_40 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
struct V_59 * V_60 = F_35 ( V_105 -> V_106 ) ;
int V_107 ;
if ( V_7 -> V_82 != NULL ) {
for ( V_107 = 0 ; V_107 < V_7 -> V_96 ; V_107 ++ )
F_3 ( V_5 , V_7 , & V_7 -> V_82 [ V_107 ] ) ;
F_42 ( V_7 -> V_82 ,
V_7 -> V_96 * sizeof V_7 -> V_82 [ 0 ] ) ;
V_7 -> V_96 = 0 ;
}
F_18 ( F_43 ( & V_60 -> V_108 ) > 0 ) ;
if ( F_44 ( & V_60 -> V_108 ) )
F_45 ( & V_60 -> V_109 ) ;
}
static T_3 F_46 ( T_3 V_110 , int V_111 )
{
if ( V_110 != V_101 )
V_110 += V_111 ;
return V_110 ;
}
static int F_47 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
struct V_1 * V_2 ;
T_3 V_112 ;
T_3 V_19 ;
T_3 V_20 ;
int V_18 ;
int V_81 = 0 ;
V_112 = F_46 ( V_7 -> V_99 , - 1 ) ;
for ( V_18 = 0 ; V_18 < V_7 -> V_67 ; V_18 ++ ) {
if ( ! F_48 ( V_22 , V_18 , V_7 -> V_98 ,
V_112 , & V_19 , & V_20 ) )
continue;
V_20 = F_46 ( V_20 , + 1 ) ;
V_2 = F_28 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
F_8 ( V_2 -> V_8 , V_7 , V_18 ,
V_19 , V_20 ) ;
V_81 = F_49 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_30 ( V_2 ) ;
F_50 ( V_113 , L_1 V_114 L_2 V_114 L_3 ,
V_18 , V_19 , V_20 ) ;
} else
V_81 = F_23 ( V_2 ) ;
if ( ! V_81 )
F_51 ( & V_2 -> V_115 , & V_7 -> V_116 ) ;
else
break;
}
return V_81 ;
}
static int F_52 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
struct V_16 * V_17 = V_105 -> V_27 ;
struct V_21 * V_22 = V_7 -> V_23 -> V_24 ;
T_4 V_19 = V_17 -> V_30 . V_56 . V_57 ;
T_1 V_117 ;
unsigned long V_118 = V_22 -> V_119 ;
F_18 ( V_17 -> V_28 == V_51 || V_17 -> V_28 == V_52 ) ;
if ( V_7 -> V_96 != 1 && ! F_14 ( V_17 ) ) {
F_53 ( V_19 , V_118 ) ;
V_117 = ( V_19 + 1 ) * V_118 ;
if ( V_117 <= V_19 * V_118 )
V_117 = ~ 0ull ;
V_17 -> V_120 = V_117 < V_7 -> V_100 ;
V_17 -> V_30 . V_56 . V_58 = F_54 ( T_1 , V_7 -> V_100 ,
V_117 ) - V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_98 = V_17 -> V_30 . V_56 . V_57 ;
V_7 -> V_99 = V_17 -> V_30 . V_56 . V_57 + V_17 -> V_30 . V_56 . V_58 ;
F_50 ( V_113 , L_4 V_114 L_5 V_114 L_2 V_114 L_6
V_114 L_7 , ( T_4 ) V_19 , V_7 -> V_98 , V_7 -> V_99 ,
( T_4 ) V_7 -> V_100 ) ;
}
return F_47 ( V_5 , V_105 ) ;
}
static int F_55 ( const struct V_4 * V_5 , struct V_6 * V_7 ,
int (* F_56)( const struct V_4 * , struct V_16 * ) )
{
struct V_16 * V_25 = V_7 -> V_26 . V_27 ;
struct V_1 * V_2 ;
int V_81 = 0 ;
F_57 (sub, &lio->lis_active, sub_linkage) {
F_1 ( V_2 ) ;
V_81 = F_56 ( V_2 -> V_10 , V_2 -> V_8 ) ;
F_2 ( V_2 ) ;
if ( V_81 )
break;
if ( V_25 -> V_77 == 0 )
V_25 -> V_77 = V_2 -> V_8 -> V_77 ;
}
return V_81 ;
}
static int F_58 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
return F_55 ( V_5 , F_41 ( V_5 , V_105 ) , V_121 ) ;
}
static int F_59 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
return F_55 ( V_5 , F_41 ( V_5 , V_105 ) , V_122 ) ;
}
static int F_60 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
if ( V_17 -> V_123 == V_124 )
F_61 ( V_5 , V_17 ) ;
else
V_17 -> V_123 = V_125 ;
return 0 ;
}
static int F_62 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_63 ( V_5 , V_17 ) ;
return 0 ;
}
static int F_64 ( const struct V_4 * V_5 , struct V_16 * V_17 )
{
F_65 ( V_5 , V_17 ) ;
return 0 ;
}
static void F_66 ( const struct V_4 * V_5 , const struct V_104 * V_105 )
{
int V_81 ;
V_81 = F_55 ( V_5 , F_41 ( V_5 , V_105 ) , F_60 ) ;
F_18 ( V_81 == 0 ) ;
}
static void F_67 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
int V_81 ;
V_81 = F_55 ( V_5 , V_7 , F_62 ) ;
F_18 ( V_81 == 0 ) ;
while ( ! F_68 ( & V_7 -> V_116 ) )
F_69 ( V_7 -> V_116 . V_117 ) ;
}
static void F_70 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
int V_81 ;
V_81 = F_55 ( V_5 , F_41 ( V_5 , V_105 ) , F_64 ) ;
F_18 ( V_81 == 0 ) ;
}
static struct V_126 * F_71 ( struct V_61 * V_62 ,
struct V_126 * V_127 ,
int V_128 , int V_129 )
{
return V_129 ? & V_127 [ V_128 ] : & V_62 -> V_70 [ V_128 ] -> V_130 ;
}
static int F_72 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 ,
enum V_131 V_132 , struct V_133 * V_134 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
struct V_59 * V_39 = V_7 -> V_23 ;
struct V_61 * V_62 = F_16 ( F_17 ( V_39 ) -> V_63 . V_64 ) ;
struct V_126 * V_127 = & V_134 -> V_135 ;
struct V_133 * V_136 = & F_73 ( V_5 ) -> V_137 ;
struct V_126 * V_138 = NULL ;
struct V_83 * V_84 ;
struct V_83 * V_139 ;
int V_18 ;
#define F_74 ( V_18 ) lov_io_submit_qin(ld, stripes_qin, stripe, alloc)
int V_81 = 0 ;
int V_129 =
! ( V_140 -> V_141 & V_142 ) ;
if ( V_7 -> V_11 == 1 ) {
int V_128 = V_7 -> V_13 ;
struct V_1 * V_2 ;
F_18 ( V_128 < V_7 -> V_96 ) ;
V_2 = F_28 ( V_5 , V_7 , V_128 ) ;
F_18 ( ! F_6 ( V_2 ) ) ;
F_18 ( V_2 -> V_8 == & V_7 -> V_74 ) ;
V_81 = F_75 ( V_2 -> V_10 , V_2 -> V_8 ,
V_132 , V_134 ) ;
F_30 ( V_2 ) ;
return V_81 ;
}
F_18 ( V_7 -> V_82 != NULL ) ;
if ( V_129 ) {
F_37 ( V_138 ,
sizeof( * V_138 ) * V_7 -> V_96 ) ;
if ( V_138 == NULL )
return - V_75 ;
for ( V_18 = 0 ; V_18 < V_7 -> V_96 ; V_18 ++ )
F_76 ( & V_138 [ V_18 ] ) ;
} else {
F_77 ( & V_62 -> V_69 ) ;
V_7 -> V_68 = 1 ;
}
F_78 ( V_136 ) ;
F_79 (page, tmp, qin) {
V_18 = F_31 ( V_84 ) ;
F_80 ( F_74 ( V_18 ) , V_127 , V_84 ) ;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_96 ; V_18 ++ ) {
struct V_1 * V_2 ;
struct V_126 * V_143 = F_74 ( V_18 ) ;
if ( F_68 ( & V_143 -> V_144 ) )
continue;
F_81 ( V_143 , & V_136 -> V_135 ) ;
V_2 = F_28 ( V_5 , V_7 , V_18 ) ;
if ( ! F_6 ( V_2 ) ) {
V_81 = F_75 ( V_2 -> V_10 , V_2 -> V_8 ,
V_132 , V_136 ) ;
F_30 ( V_2 ) ;
} else
V_81 = F_23 ( V_2 ) ;
F_81 ( & V_136 -> V_135 , & V_134 -> V_135 ) ;
F_81 ( & V_136 -> V_145 , & V_134 -> V_145 ) ;
if ( V_81 != 0 )
break;
}
for ( V_18 = 0 ; V_18 < V_7 -> V_96 ; V_18 ++ ) {
struct V_126 * V_143 = F_74 ( V_18 ) ;
if ( F_68 ( & V_143 -> V_144 ) )
continue;
F_81 ( V_143 , V_127 ) ;
}
if ( V_129 ) {
F_42 ( V_138 ,
sizeof( * V_138 ) * V_7 -> V_96 ) ;
} else {
int V_107 ;
for ( V_107 = 0 ; V_107 < V_7 -> V_96 ; V_107 ++ ) {
struct V_16 * V_146 = V_7 -> V_82 [ V_107 ] . V_8 ;
if ( V_146 && V_146 == & V_62 -> V_70 [ V_107 ] -> V_71 )
F_3 ( V_5 , V_7 , & V_7 -> V_82 [ V_107 ] ) ;
}
V_7 -> V_68 = 0 ;
F_82 ( & V_62 -> V_69 ) ;
}
return V_81 ;
#undef F_74
}
static int F_83 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 ,
const struct V_92 * V_93 ,
unsigned V_147 , unsigned V_148 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
struct V_83 * V_149 = F_84 ( V_93 ) ;
struct V_1 * V_2 ;
int V_66 ;
V_2 = F_34 ( V_5 , V_7 , V_93 ) ;
if ( ! F_6 ( V_2 ) ) {
V_66 = F_85 ( V_2 -> V_10 , V_2 -> V_8 ,
V_149 , V_147 , V_148 ) ;
F_30 ( V_2 ) ;
} else
V_66 = F_23 ( V_2 ) ;
return V_66 ;
}
static int F_86 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 ,
const struct V_92 * V_93 ,
unsigned V_147 , unsigned V_148 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
struct V_83 * V_149 = F_84 ( V_93 ) ;
struct V_1 * V_2 ;
int V_66 ;
V_2 = F_34 ( V_5 , V_7 , V_93 ) ;
if ( ! F_6 ( V_2 ) ) {
V_66 = F_87 ( V_2 -> V_10 , V_2 -> V_8 ,
V_149 , V_147 , V_148 ) ;
F_30 ( V_2 ) ;
} else
V_66 = F_23 ( V_2 ) ;
return V_66 ;
}
static int F_88 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_150 * V_151 ;
struct V_6 * V_7 ;
struct V_1 * V_2 ;
V_151 = & V_105 -> V_27 -> V_30 . V_42 ;
V_7 = F_41 ( V_5 , V_105 ) ;
V_2 = F_28 ( V_5 , V_7 , F_31 ( V_151 -> V_152 ) ) ;
V_2 -> V_8 -> V_30 . V_42 . V_153 = V_151 -> V_153 ;
F_30 ( V_2 ) ;
return F_59 ( V_5 , V_105 ) ;
}
static void F_89 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_6 * V_7 = F_41 ( V_5 , V_105 ) ;
struct V_1 * V_2 ;
unsigned int * V_154 = & V_105 -> V_27 -> V_30 . V_45 . V_155 ;
* V_154 = 0 ;
F_57 (sub, &lio->lis_active, sub_linkage) {
struct V_16 * V_156 = V_2 -> V_8 ;
F_1 ( V_2 ) ;
F_60 ( V_2 -> V_10 , V_156 ) ;
F_2 ( V_2 ) ;
if ( V_156 -> V_77 == 0 )
* V_154 += V_156 -> V_30 . V_45 . V_155 ;
}
}
static void F_90 ( const struct V_4 * V_5 ,
const struct V_104 * V_105 )
{
struct V_59 * V_60 = F_35 ( V_105 -> V_106 ) ;
if ( F_44 ( & V_60 -> V_108 ) )
F_45 ( & V_60 -> V_109 ) ;
}
static void F_91 ( const struct V_4 * V_5 ,
struct V_104 * V_105 )
{
F_39 () ;
}
int F_92 ( const struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_6 * V_7 = F_93 ( V_5 ) ;
struct V_59 * V_60 = F_35 ( V_39 ) ;
F_94 ( & V_7 -> V_116 ) ;
F_38 ( V_7 , V_60 , V_17 ) ;
if ( V_17 -> V_77 == 0 ) {
V_17 -> V_77 = F_36 ( V_5 , V_7 , V_17 ) ;
if ( V_17 -> V_77 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_39 , & V_157 ) ;
F_96 ( & V_60 -> V_108 ) ;
}
}
return V_17 -> V_77 ;
}
int F_97 ( const struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_59 * V_60 = F_35 ( V_39 ) ;
struct V_6 * V_7 = F_93 ( V_5 ) ;
int V_66 ;
V_7 -> V_23 = V_60 ;
switch ( V_17 -> V_28 ) {
default:
F_39 () ;
case V_103 :
case V_51 :
V_66 = 0 ;
break;
case V_44 :
case V_29 :
V_66 = + 1 ;
break;
case V_52 :
V_66 = - V_158 ;
break;
case V_37 :
V_66 = - V_159 ;
F_98 ( L_8 V_160 L_7 ,
F_99 ( F_100 ( & V_39 -> V_63 ) ) ) ;
break;
}
if ( V_66 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_39 , & V_161 ) ;
F_96 ( & V_60 -> V_108 ) ;
}
V_17 -> V_77 = V_66 < 0 ? V_66 : 0 ;
return V_66 != 0 ;
}
int F_101 ( const struct V_4 * V_5 , struct V_38 * V_39 ,
struct V_16 * V_17 )
{
struct V_59 * V_60 = F_35 ( V_39 ) ;
struct V_6 * V_7 = F_93 ( V_5 ) ;
int V_66 ;
F_18 ( V_60 -> V_24 != NULL ) ;
V_7 -> V_23 = V_60 ;
switch ( V_17 -> V_28 ) {
default:
F_102 ( 0 , L_9 , V_17 -> V_28 ) ;
case V_103 :
case V_44 :
V_66 = + 1 ;
break;
case V_29 :
case V_51 :
case V_52 :
case V_37 :
V_66 = - V_158 ;
break;
}
if ( V_66 == 0 ) {
F_95 ( V_17 , & V_7 -> V_26 , V_39 , & V_161 ) ;
F_96 ( & V_60 -> V_108 ) ;
}
V_17 -> V_77 = V_66 < 0 ? V_66 : 0 ;
return V_66 != 0 ;
}
