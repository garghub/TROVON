static inline int F_1 ( struct V_1 * V_2 )
{
return F_2 ( & V_2 -> V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 )
{
F_4 () ;
return ( V_2 -> V_4 != V_5 ) ;
}
static inline int F_5 ( int V_6 )
{
return V_6 & V_7 ;
}
static inline void
F_6 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_10 = F_5 ( V_2 -> V_11 . V_12 ) ;
F_7 ( & V_9 -> V_13 [ V_10 ] ) ;
F_8 ( & V_2 -> V_3 , & V_9 -> V_14 [ V_10 ] ) ;
F_9 ( & V_9 -> V_13 [ V_10 ] ) ;
}
static inline void
F_10 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
int V_10 = F_5 ( V_2 -> V_11 . V_12 ) ;
F_7 ( & V_9 -> V_13 [ V_10 ] ) ;
F_11 ( & V_2 -> V_3 ) ;
F_9 ( & V_9 -> V_13 [ V_10 ] ) ;
}
static inline int F_12 ( struct V_8 * V_9 ,
struct V_15 * V_15 )
{
return ( V_15 != NULL && F_13 ( V_15 -> V_16 ) && V_9 -> V_17 ) ;
}
static inline struct V_1 *
F_14 ( struct V_8 * V_9 )
{
return F_15 ( V_9 -> V_18 . V_19 ,
struct V_1 , V_20 ) ;
}
static inline struct V_21 *
F_16 ( struct V_8 * V_9 )
{
return F_15 ( V_9 -> V_22 . V_19 ,
struct V_21 , V_23 ) ;
}
static inline int F_17 ( struct V_8 * V_9 )
{
return F_18 ( & V_9 -> V_24 ) >= V_9 -> V_25 ;
}
static inline int F_19 ( struct V_8 * V_9 )
{
return F_2 ( & V_9 -> V_18 ) ;
}
static inline int F_20 ( struct V_8 * V_9 )
{
return F_2 ( & V_9 -> V_22 ) ;
}
static inline int F_21 ( struct V_8 * V_9 )
{
return ( ( V_9 -> V_26 > 7 && V_9 -> V_26 < 4 * V_9 -> V_27 ) ||
( V_9 -> V_28 > 8 ) ) ;
}
static inline int F_22 ( struct V_8 * V_9 , T_1 V_29 )
{
return ( ( T_1 ) V_9 -> V_25 + V_29 + V_30 <
V_9 -> V_31 ) ;
}
static struct V_1 *
F_23 ( struct V_8 * V_9 , T_1 V_29 ,
const char * V_32 , int V_33 )
{
struct V_21 * V_34 ;
struct V_1 * V_2 ;
int V_35 ;
char * V_36 ;
V_35 = sizeof( struct V_1 ) + ( V_33 & ~ 3 ) + 4 ;
F_24 ( V_2 , V_35 ) ;
if ( F_25 ( V_2 == NULL ) )
return F_26 ( - V_37 ) ;
F_27 ( V_38 , L_1 V_39 L_2 ,
V_33 , V_32 , V_2 , V_29 ) ;
V_2 -> V_40 = V_29 ;
F_28 ( & V_2 -> V_41 , 2 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_42 = V_35 ;
V_36 = ( char * ) V_2 + sizeof( struct V_1 ) ;
memcpy ( V_36 , V_32 , V_33 ) ;
V_36 [ V_33 ] = 0 ;
V_2 -> V_11 . V_12 = F_29 ( V_32 , V_33 ) ;
V_2 -> V_11 . V_33 = V_33 ;
V_2 -> V_11 . V_32 = V_36 ;
V_34 = F_30 ( V_9 -> V_43 ) ;
F_7 ( & V_34 -> V_44 ) ;
F_8 ( & V_2 -> V_45 , & V_9 -> V_46 ) ;
F_31 ( & V_2 -> V_20 ) ;
F_6 ( V_9 , V_2 ) ;
F_9 ( & V_34 -> V_44 ) ;
F_32 ( & V_9 -> V_24 ) ;
return V_2 ;
}
static struct V_1 *
F_33 ( struct V_8 * V_9 , const struct V_47 * V_47 )
{
struct V_1 * V_2 ;
int V_10 = F_5 ( V_47 -> V_12 ) ;
F_34 (entry, &sai->sai_cache[i], se_hash) {
if ( V_2 -> V_11 . V_12 == V_47 -> V_12 &&
V_2 -> V_11 . V_33 == V_47 -> V_33 &&
memcmp ( V_2 -> V_11 . V_32 , V_47 -> V_32 , V_47 -> V_33 ) == 0 )
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_35 ( struct V_8 * V_9 , T_1 V_29 )
{
struct V_1 * V_2 ;
F_34 (entry, &sai->sai_entries, se_link) {
if ( V_2 -> V_40 == V_29 ) {
F_36 ( F_18 ( & V_2 -> V_41 ) > 0 ) ;
F_32 ( & V_2 -> V_41 ) ;
return V_2 ;
}
if ( V_2 -> V_40 > V_29 )
break;
}
return NULL ;
}
static void F_37 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_50 ;
struct V_51 * V_52 = V_2 -> V_53 ;
if ( V_49 ) {
V_2 -> V_50 = NULL ;
F_38 ( & V_49 -> V_54 ) ;
F_39 ( V_49 -> V_55 ) ;
F_40 ( V_49 ) ;
}
if ( V_52 ) {
V_2 -> V_53 = NULL ;
F_41 ( V_52 ) ;
}
}
static void F_42 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( F_43 ( & V_2 -> V_41 ) ) {
F_27 ( V_38 , L_3 V_39 L_2 ,
V_2 -> V_11 . V_33 , V_2 -> V_11 . V_32 , V_2 ,
V_2 -> V_40 ) ;
F_36 ( F_2 ( & V_2 -> V_45 ) ) ;
F_36 ( F_2 ( & V_2 -> V_20 ) ) ;
F_36 ( F_1 ( V_2 ) ) ;
F_37 ( V_9 , V_2 ) ;
if ( V_2 -> V_56 )
F_39 ( V_2 -> V_56 ) ;
F_44 ( V_2 , V_2 -> V_42 ) ;
F_45 ( & V_9 -> V_24 ) ;
}
}
static inline void
F_46 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_21 * V_34 = F_30 ( V_9 -> V_43 ) ;
F_36 ( ! F_1 ( V_2 ) ) ;
F_36 ( ! F_2 ( & V_2 -> V_45 ) ) ;
F_10 ( V_9 , V_2 ) ;
F_7 ( & V_34 -> V_44 ) ;
V_2 -> V_4 = V_57 ;
F_11 ( & V_2 -> V_45 ) ;
if ( F_47 ( ! F_2 ( & V_2 -> V_20 ) ) )
F_11 ( & V_2 -> V_20 ) ;
F_9 ( & V_34 -> V_44 ) ;
F_42 ( V_9 , V_2 ) ;
}
static void
F_48 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_1 * V_58 , * V_19 ;
if ( V_2 )
F_46 ( V_9 , V_2 ) ;
F_49 (pos, next, &sai->sai_entries, se_link) {
if ( ! F_22 ( V_9 , V_58 -> V_40 ) )
break;
F_46 ( V_9 , V_58 ) ;
}
}
static void
F_50 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_59 )
{
struct V_1 * V_60 ;
struct V_61 * V_58 = & V_9 -> V_62 ;
if ( ! F_2 ( & V_2 -> V_20 ) )
F_11 ( & V_2 -> V_20 ) ;
F_51 (se, &sai->sai_entries_stated, se_list) {
if ( V_60 -> V_40 < V_2 -> V_40 ) {
V_58 = & V_60 -> V_20 ;
break;
}
}
F_52 ( & V_2 -> V_20 , V_58 ) ;
V_2 -> V_4 = V_59 ;
}
static int
F_53 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_59 )
{
struct V_21 * V_34 = F_30 ( V_9 -> V_43 ) ;
int V_63 = 1 ;
F_37 ( V_9 , V_2 ) ;
F_7 ( & V_34 -> V_44 ) ;
if ( F_47 ( V_2 -> V_4 != V_57 ) ) {
F_50 ( V_9 , V_2 , V_59 ) ;
V_63 = 0 ;
}
F_9 ( & V_34 -> V_44 ) ;
return V_63 ;
}
static void F_54 ( struct V_8 * V_9 ,
struct V_15 * V_15 , int V_29 )
{
struct V_21 * V_64 = F_30 ( V_15 ) ;
struct V_21 * V_65 = F_30 ( V_9 -> V_43 ) ;
int V_66 = 0 ;
F_7 ( & V_64 -> V_67 ) ;
if ( V_64 -> V_68 == 0 ) {
V_64 -> V_68 = V_29 ;
F_9 ( & V_64 -> V_67 ) ;
F_36 ( F_2 ( & V_64 -> V_23 ) ) ;
F_55 ( V_15 ) ;
F_7 ( & V_65 -> V_67 ) ;
if ( F_20 ( V_9 ) )
V_66 = 1 ;
F_8 ( & V_64 -> V_23 , & V_9 -> V_22 ) ;
F_9 ( & V_65 -> V_67 ) ;
} else {
F_9 ( & V_64 -> V_67 ) ;
}
if ( V_66 > 0 )
F_56 ( & V_9 -> V_69 . V_70 ) ;
}
static struct V_8 * F_57 ( void )
{
struct V_8 * V_9 ;
int V_10 ;
F_58 ( V_9 ) ;
if ( ! V_9 )
return NULL ;
F_28 ( & V_9 -> V_71 , 1 ) ;
F_7 ( & V_72 ) ;
V_9 -> V_73 = ++ V_73 ;
if ( F_25 ( V_73 == 0 ) )
V_9 -> V_73 = ++ V_73 ;
F_9 ( & V_72 ) ;
V_9 -> V_25 = V_74 ;
V_9 -> V_31 = 1 ;
F_59 ( & V_9 -> V_75 ) ;
F_59 ( & V_9 -> V_76 . V_70 ) ;
F_59 ( & V_9 -> V_69 . V_70 ) ;
F_31 ( & V_9 -> V_46 ) ;
F_31 ( & V_9 -> V_18 ) ;
F_31 ( & V_9 -> V_62 ) ;
F_31 ( & V_9 -> V_22 ) ;
for ( V_10 = 0 ; V_10 < V_77 ; V_10 ++ ) {
F_31 ( & V_9 -> V_14 [ V_10 ] ) ;
F_60 ( & V_9 -> V_13 [ V_10 ] ) ;
}
F_28 ( & V_9 -> V_24 , 0 ) ;
return V_9 ;
}
static inline struct V_8 *
F_61 ( struct V_8 * V_9 )
{
F_32 ( & V_9 -> V_71 ) ;
return V_9 ;
}
static void F_62 ( struct V_8 * V_9 )
{
struct V_15 * V_15 = V_9 -> V_43 ;
struct V_21 * V_34 = F_30 ( V_15 ) ;
if ( F_63 ( & V_9 -> V_71 , & V_34 -> V_44 ) ) {
struct V_1 * V_2 , * V_19 ;
if ( F_25 ( F_18 ( & V_9 -> V_71 ) > 0 ) ) {
F_9 ( & V_34 -> V_44 ) ;
return;
}
F_36 ( V_34 -> V_78 == NULL ) ;
F_36 ( F_64 ( & V_9 -> V_76 ) ) ;
F_36 ( F_64 ( & V_9 -> V_69 ) ) ;
V_34 -> V_79 = NULL ;
V_34 -> V_80 = 0 ;
F_9 ( & V_34 -> V_44 ) ;
if ( V_9 -> V_81 > V_9 -> V_82 )
F_27 ( V_38 , L_4 V_83 L_5
L_6 V_39 L_7 V_39 L_8 ,
F_65 ( & V_34 -> V_84 ) ,
V_9 -> V_81 , V_9 -> V_82 ) ;
F_49 (entry, next,
&sai->sai_entries, se_link)
F_46 ( V_9 , V_2 ) ;
F_36 ( F_2 ( & V_9 -> V_46 ) ) ;
F_36 ( F_19 ( V_9 ) ) ;
F_36 ( F_2 ( & V_9 -> V_62 ) ) ;
F_36 ( F_18 ( & V_9 -> V_24 ) == 0 ) ;
F_36 ( F_20 ( V_9 ) ) ;
F_39 ( V_15 ) ;
F_40 ( V_9 ) ;
}
}
static void F_66 ( struct V_15 * V_15 , struct V_8 * V_9 )
{
struct V_21 * V_34 = F_30 ( V_15 ) ;
T_1 V_29 = V_34 -> V_68 ;
int V_85 ;
F_36 ( F_2 ( & V_34 -> V_23 ) ) ;
if ( F_22 ( V_9 , V_29 + 1 ) ) {
V_34 -> V_68 = 0 ;
F_39 ( V_15 ) ;
return;
}
V_85 = F_67 ( & V_34 -> V_86 ) ;
if ( V_85 == 0 ) {
V_34 -> V_68 = 0 ;
F_39 ( V_15 ) ;
return;
}
if ( V_34 -> V_87 != 0 &&
F_68 ( F_69 ( - 1 ) , V_34 -> V_87 ) ) {
F_70 ( & V_34 -> V_86 ) ;
V_34 -> V_68 = 0 ;
F_39 ( V_15 ) ;
return;
}
F_27 ( V_38 , L_9
V_83 L_10 V_39 L_2 , F_65 ( & V_34 -> V_84 ) , V_29 ) ;
F_71 ( V_15 ) ;
V_34 -> V_68 = 0 ;
V_34 -> V_87 = F_72 () ;
F_70 ( & V_34 -> V_86 ) ;
F_27 ( V_38 , L_11
V_83 L_10 V_39 L_12 ,
F_65 ( & V_34 -> V_84 ) , V_29 , V_85 ) ;
F_39 ( V_15 ) ;
}
static void F_73 ( struct V_8 * V_9 )
{
struct V_15 * V_88 = V_9 -> V_43 ;
struct V_15 * V_64 ;
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
struct V_89 * V_90 ;
struct V_51 * V_52 ;
struct V_91 * V_92 ;
int V_85 = 0 ;
F_7 ( & V_34 -> V_44 ) ;
if ( F_25 ( F_19 ( V_9 ) ) ) {
F_9 ( & V_34 -> V_44 ) ;
return;
}
V_2 = F_14 ( V_9 ) ;
F_32 ( & V_2 -> V_41 ) ;
F_11 ( & V_2 -> V_20 ) ;
F_9 ( & V_34 -> V_44 ) ;
F_36 ( V_2 -> V_93 != 0 ) ;
V_49 = V_2 -> V_50 ;
V_90 = & V_49 -> V_54 ;
V_52 = V_2 -> V_53 ;
V_92 = F_74 ( & V_52 -> V_94 , & V_95 ) ;
if ( V_92 == NULL )
GOTO ( V_96 , V_85 = - V_97 ) ;
V_64 = V_2 -> V_56 ;
if ( V_64 == NULL ) {
F_36 ( F_75 ( & V_49 -> V_98 . V_99 ) ) ;
if ( V_92 -> V_100 & V_101 )
GOTO ( V_96 , V_85 = - V_102 ) ;
} else {
if ( F_25 ( ! F_76 ( & V_49 -> V_98 . V_99 , & V_92 -> V_103 ) ) ) {
V_2 -> V_56 = NULL ;
F_39 ( V_64 ) ;
V_64 = NULL ;
}
}
V_90 -> V_104 . V_105 . V_106 = V_2 -> V_93 ;
V_85 = F_77 ( F_78 ( V_88 ) , V_90 , F_79 ( V_88 ) , NULL ) ;
if ( V_85 != 1 )
GOTO ( V_96 , V_85 = - V_102 ) ;
V_85 = F_80 ( & V_64 , V_52 , V_88 -> V_107 , V_90 ) ;
if ( V_85 )
GOTO ( V_96 , V_85 ) ;
F_27 ( V_108 , L_13 ,
V_64 , V_64 -> V_109 , V_64 -> V_110 ) ;
F_81 ( F_82 ( V_88 ) -> V_111 , V_64 , V_90 , NULL ) ;
V_2 -> V_56 = V_64 ;
if ( F_12 ( V_9 , V_64 ) )
F_54 ( V_9 , V_64 , V_2 -> V_40 ) ;
V_96:
V_85 = F_53 ( V_9 , V_2 ,
V_85 < 0 ? V_112 : V_113 ) ;
if ( V_85 == 0 && V_2 -> V_40 == V_9 -> V_114 )
F_56 ( & V_9 -> V_75 ) ;
F_42 ( V_9 , V_2 ) ;
}
static int F_83 ( struct V_51 * V_52 ,
struct V_48 * V_49 , int V_85 )
{
struct V_89 * V_90 = & V_49 -> V_54 ;
struct V_15 * V_88 = V_49 -> V_55 ;
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 ;
int V_115 ;
if ( F_84 ( V_90 , V_116 ) )
V_85 = - V_117 ;
F_7 ( & V_34 -> V_44 ) ;
if ( F_25 ( V_34 -> V_79 == NULL ||
V_34 -> V_79 -> V_73 != V_49 -> V_118 ) ) {
F_9 ( & V_34 -> V_44 ) ;
GOTO ( V_96 , V_85 = - V_119 ) ;
} else {
V_9 = F_61 ( V_34 -> V_79 ) ;
if ( F_25 ( ! F_85 ( & V_9 -> V_76 ) ) ) {
V_9 -> V_82 ++ ;
F_9 ( & V_34 -> V_44 ) ;
GOTO ( V_96 , V_85 = - V_120 ) ;
}
V_2 = F_35 ( V_9 , V_49 -> V_121 ) ;
if ( V_2 == NULL ) {
V_9 -> V_82 ++ ;
F_9 ( & V_34 -> V_44 ) ;
GOTO ( V_96 , V_85 = - V_122 ) ;
}
if ( V_85 != 0 ) {
F_50 ( V_9 , V_2 , V_112 ) ;
V_115 = ( V_2 -> V_40 == V_9 -> V_114 ) ;
} else {
V_2 -> V_50 = V_49 ;
V_2 -> V_53 = F_86 ( V_52 ) ;
V_2 -> V_93 = V_90 -> V_104 . V_105 . V_106 ;
F_87 ( V_90 ) ;
V_115 = F_19 ( V_9 ) ;
F_8 ( & V_2 -> V_20 ,
& V_9 -> V_18 ) ;
}
V_9 -> V_82 ++ ;
F_9 ( & V_34 -> V_44 ) ;
F_42 ( V_9 , V_2 ) ;
if ( V_115 )
F_56 ( & V_9 -> V_76 . V_70 ) ;
}
V_96:
if ( V_85 != 0 ) {
F_38 ( V_90 ) ;
F_39 ( V_88 ) ;
F_40 ( V_49 ) ;
}
if ( V_9 != NULL )
F_62 ( V_9 ) ;
return V_85 ;
}
static void F_88 ( struct V_48 * V_49 ,
struct V_123 * V_124 )
{
F_36 ( V_49 && V_124 ) ;
F_39 ( V_49 -> V_55 ) ;
F_89 ( V_49 -> V_98 . V_125 ) ;
F_89 ( V_49 -> V_98 . V_126 ) ;
F_40 ( V_49 ) ;
F_40 ( V_124 ) ;
}
static int F_90 ( struct V_15 * V_88 , struct V_15 * V_64 ,
struct V_1 * V_2 , struct V_48 * * V_127 ,
struct V_123 * * V_128 ,
struct V_129 * * V_130 )
{
struct V_47 * V_47 = & V_2 -> V_11 ;
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_48 * V_49 ;
struct V_123 * V_124 ;
struct V_131 * V_132 ;
F_58 ( V_124 ) ;
if ( V_124 == NULL )
return - V_37 ;
F_58 ( V_49 ) ;
if ( V_49 == NULL ) {
F_40 ( V_124 ) ;
return - V_37 ;
}
V_132 = F_91 ( & V_49 -> V_98 , V_88 , V_64 , V_47 -> V_32 ,
V_47 -> V_33 , 0 , V_133 , NULL ) ;
if ( F_92 ( V_132 ) ) {
F_40 ( V_124 ) ;
F_40 ( V_49 ) ;
return F_93 ( V_132 ) ;
}
V_49 -> V_54 . V_134 = V_135 ;
V_49 -> V_55 = F_55 ( V_88 ) ;
V_49 -> V_136 = F_83 ;
V_49 -> V_118 = V_34 -> V_79 -> V_73 ;
V_49 -> V_121 = V_2 -> V_40 ;
V_124 -> V_137 = V_138 ;
V_124 -> V_139 = F_94 ( & V_49 -> V_54 ) ;
V_124 -> V_140 = V_141 ;
V_124 -> V_142 = V_143 ;
V_124 -> V_144 = NULL ;
V_124 -> V_145 = NULL ;
* V_127 = V_49 ;
* V_128 = V_124 ;
V_130 [ 0 ] = V_132 -> V_125 ;
V_130 [ 1 ] = V_132 -> V_126 ;
return 0 ;
}
static int F_95 ( struct V_15 * V_88 , struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_123 * V_124 ;
struct V_129 * V_146 [ 2 ] ;
int V_85 ;
V_85 = F_90 ( V_88 , NULL , V_2 , & V_49 , & V_124 , V_146 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_96 ( F_78 ( V_88 ) , V_49 , V_124 ) ;
if ( ! V_85 ) {
F_89 ( V_146 [ 0 ] ) ;
F_89 ( V_146 [ 1 ] ) ;
} else {
F_88 ( V_49 , V_124 ) ;
}
return V_85 ;
}
static int F_97 ( struct V_15 * V_88 , struct V_1 * V_2 ,
struct V_147 * V_147 )
{
struct V_15 * V_15 = V_147 -> V_148 ;
struct V_89 V_90 = { . V_134 = V_135 ,
. V_104 . V_105 . V_106 = 0 } ;
struct V_48 * V_49 ;
struct V_123 * V_124 ;
struct V_129 * V_146 [ 2 ] ;
int V_85 ;
if ( F_25 ( V_15 == NULL ) )
return 1 ;
if ( F_98 ( V_147 ) )
return 1 ;
if ( F_25 ( V_147 == V_147 -> V_149 -> V_150 ) )
return 1 ;
V_2 -> V_56 = F_55 ( V_15 ) ;
V_85 = F_77 ( F_78 ( V_88 ) , & V_90 , F_79 ( V_15 ) , NULL ) ;
if ( V_85 == 1 ) {
V_2 -> V_93 = V_90 . V_104 . V_105 . V_106 ;
F_38 ( & V_90 ) ;
return 1 ;
}
V_85 = F_90 ( V_88 , V_15 , V_2 , & V_49 , & V_124 , V_146 ) ;
if ( V_85 ) {
V_2 -> V_56 = NULL ;
F_39 ( V_15 ) ;
return V_85 ;
}
V_85 = F_96 ( F_78 ( V_88 ) , V_49 , V_124 ) ;
if ( ! V_85 ) {
F_89 ( V_146 [ 0 ] ) ;
F_89 ( V_146 [ 1 ] ) ;
} else {
V_2 -> V_56 = NULL ;
F_39 ( V_15 ) ;
F_88 ( V_49 , V_124 ) ;
}
return V_85 ;
}
static void F_99 ( struct V_147 * V_65 , const char * V_151 ,
int V_152 )
{
struct V_15 * V_88 = V_65 -> V_148 ;
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_8 * V_9 = V_34 -> V_79 ;
struct V_147 * V_147 = NULL ;
struct V_1 * V_2 ;
int V_85 ;
int V_153 ;
V_2 = F_23 ( V_9 , V_9 -> V_31 , V_151 ,
V_152 ) ;
if ( F_92 ( V_2 ) )
return;
V_147 = F_100 ( V_65 , & V_2 -> V_11 ) ;
if ( ! V_147 ) {
V_85 = F_95 ( V_88 , V_2 ) ;
} else {
V_85 = F_97 ( V_88 , V_2 , V_147 ) ;
if ( V_85 == 1 && F_12 ( V_9 , V_147 -> V_148 ) )
F_54 ( V_9 , V_147 -> V_148 , V_2 -> V_40 ) ;
}
if ( V_147 != NULL )
F_101 ( V_147 ) ;
if ( V_85 ) {
V_153 = F_53 ( V_9 , V_2 ,
V_85 < 0 ? V_112 : V_113 ) ;
if ( V_153 == 0 && V_2 -> V_40 == V_9 -> V_114 )
F_56 ( & V_9 -> V_75 ) ;
} else {
V_9 -> V_81 ++ ;
}
V_9 -> V_31 ++ ;
F_42 ( V_9 , V_2 ) ;
}
static int F_102 ( void * V_154 )
{
struct V_147 * V_65 = (struct V_147 * ) V_154 ;
struct V_15 * V_88 = V_65 -> V_148 ;
struct V_21 * V_155 = F_30 ( V_88 ) ;
struct V_21 * V_156 ;
struct V_157 * V_158 = F_82 ( V_88 ) ;
struct V_8 * V_9 = F_61 ( V_155 -> V_79 ) ;
struct V_159 * V_160 = & V_9 -> V_69 ;
struct V_161 V_162 = { 0 } ;
F_27 ( V_38 , L_14 ,
F_103 () , V_65 -> V_163 . V_33 , V_65 -> V_163 . V_32 ) ;
F_32 ( & V_158 -> V_164 ) ;
F_7 ( & V_155 -> V_67 ) ;
V_9 -> V_17 = 1 ;
F_104 ( V_160 , V_165 ) ;
F_9 ( & V_155 -> V_67 ) ;
F_56 ( & V_160 -> V_70 ) ;
while ( 1 ) {
F_105 ( V_160 -> V_70 ,
! F_20 ( V_9 ) ||
! F_85 ( V_160 ) ,
& V_162 ) ;
if ( ! F_85 ( V_160 ) )
break;
F_7 ( & V_155 -> V_67 ) ;
if ( ! F_20 ( V_9 ) ) {
V_156 = F_16 ( V_9 ) ;
F_11 ( & V_156 -> V_23 ) ;
F_9 ( & V_155 -> V_67 ) ;
F_66 ( & V_156 -> V_166 , V_9 ) ;
} else {
F_9 ( & V_155 -> V_67 ) ;
}
}
F_7 ( & V_155 -> V_67 ) ;
V_9 -> V_17 = 0 ;
while ( ! F_20 ( V_9 ) ) {
V_156 = F_16 ( V_9 ) ;
F_11 ( & V_156 -> V_23 ) ;
F_9 ( & V_155 -> V_67 ) ;
V_156 -> V_68 = 0 ;
F_39 ( & V_156 -> V_166 ) ;
F_7 ( & V_155 -> V_67 ) ;
}
F_104 ( V_160 , V_167 ) ;
F_9 ( & V_155 -> V_67 ) ;
F_56 ( & V_160 -> V_70 ) ;
F_62 ( V_9 ) ;
F_27 ( V_38 , L_15 ,
F_103 () , V_65 -> V_163 . V_33 , V_65 -> V_163 . V_32 ) ;
return 0 ;
}
static void F_106 ( struct V_147 * V_65 , struct V_8 * V_9 )
{
struct V_159 * V_160 = & V_9 -> V_69 ;
struct V_161 V_162 = { 0 } ;
struct V_21 * V_155 ;
struct V_168 * V_169 ;
F_27 ( V_38 , L_16 ,
F_103 () , V_65 -> V_163 . V_33 , V_65 -> V_163 . V_32 ) ;
V_155 = F_30 ( V_65 -> V_148 ) ;
V_169 = F_107 ( F_102 , V_65 ,
L_17 , V_155 -> V_80 ) ;
if ( F_92 ( V_169 ) ) {
F_108 ( L_18 , F_93 ( V_169 ) ) ;
F_104 ( V_160 , V_167 ) ;
return;
}
F_105 ( V_160 -> V_70 ,
F_85 ( V_160 ) || F_64 ( V_160 ) ,
& V_162 ) ;
}
static int F_109 ( void * V_154 )
{
struct V_147 * V_65 = (struct V_147 * ) V_154 ;
struct V_15 * V_88 = V_65 -> V_148 ;
struct V_21 * V_155 = F_30 ( V_88 ) ;
struct V_21 * V_156 ;
struct V_157 * V_158 = F_82 ( V_88 ) ;
struct V_8 * V_9 = F_61 ( V_155 -> V_79 ) ;
struct V_159 * V_160 = & V_9 -> V_76 ;
struct V_159 * V_170 = & V_9 -> V_69 ;
struct V_171 * V_171 ;
T_1 V_58 = 0 ;
int V_172 = 0 ;
int V_85 = 0 ;
struct V_173 V_174 ;
struct V_161 V_162 = { 0 } ;
F_27 ( V_38 , L_19 ,
F_103 () , V_65 -> V_163 . V_33 , V_65 -> V_163 . V_32 ) ;
if ( V_158 -> V_175 & V_176 )
F_106 ( V_65 , V_9 ) ;
F_32 ( & V_158 -> V_177 ) ;
F_7 ( & V_155 -> V_44 ) ;
F_104 ( V_160 , V_165 ) ;
F_9 ( & V_155 -> V_44 ) ;
F_56 ( & V_160 -> V_70 ) ;
F_110 ( & V_174 ) ;
V_171 = F_111 ( V_88 , V_58 , & V_174 ) ;
while ( 1 ) {
struct V_178 * V_179 ;
struct V_180 * V_181 ;
if ( F_92 ( V_171 ) ) {
V_85 = F_93 ( V_171 ) ;
F_27 ( V_38 , L_20 V_83 L_21 V_39
L_22 V_39 L_23 ,
F_65 ( F_79 ( V_88 ) ) , V_58 , V_9 -> V_31 ,
V_85 , V_155 -> V_80 ) ;
GOTO ( V_96 , V_85 ) ;
}
V_179 = F_112 ( V_171 ) ;
for ( V_181 = F_113 ( V_179 ) ; V_181 != NULL ;
V_181 = F_114 ( V_181 ) ) {
T_1 V_12 ;
int V_182 ;
char * V_32 ;
V_12 = F_115 ( V_181 -> V_183 ) ;
if ( F_25 ( V_12 < V_58 ) )
continue;
V_182 = F_116 ( V_181 -> V_184 ) ;
if ( F_25 ( V_182 == 0 ) )
continue;
V_32 = V_181 -> V_185 ;
if ( V_32 [ 0 ] == '.' ) {
if ( V_182 == 1 ) {
continue;
} else if ( V_32 [ 1 ] == '.' && V_182 == 2 ) {
continue;
} else if ( ! V_9 -> V_186 ) {
V_9 -> V_187 ++ ;
continue;
}
}
if ( F_25 ( ++ V_172 == 1 ) )
continue;
V_188:
F_105 ( V_160 -> V_70 ,
! F_17 ( V_9 ) ||
! F_19 ( V_9 ) ||
! F_20 ( V_9 ) ||
! F_85 ( V_160 ) ,
& V_162 ) ;
V_189:
while ( ! F_19 ( V_9 ) )
F_73 ( V_9 ) ;
if ( F_25 ( ! F_85 ( V_160 ) ) ) {
F_117 ( V_171 , 0 ) ;
GOTO ( V_96 , V_85 = 0 ) ;
}
if ( F_17 ( V_9 ) ) {
F_7 ( & V_155 -> V_67 ) ;
while ( ! F_20 ( V_9 ) ) {
V_156 = F_16 ( V_9 ) ;
F_11 ( & V_156 -> V_23 ) ;
F_9 ( & V_155 -> V_67 ) ;
F_66 ( & V_156 -> V_166 ,
V_9 ) ;
if ( ! F_19 ( V_9 ) )
goto V_189;
if ( F_25 (
! F_85 ( V_160 ) ) ) {
F_117 ( V_171 , 0 ) ;
GOTO ( V_96 , V_85 = 0 ) ;
}
if ( ! F_17 ( V_9 ) )
goto V_190;
F_7 ( & V_155 -> V_67 ) ;
}
F_9 ( & V_155 -> V_67 ) ;
goto V_188;
}
V_190:
F_99 ( V_65 , V_32 , V_182 ) ;
}
V_58 = F_115 ( V_179 -> V_191 ) ;
if ( V_58 == V_192 ) {
F_117 ( V_171 , 0 ) ;
while ( 1 ) {
F_105 ( V_160 -> V_70 ,
! F_19 ( V_9 ) ||
V_9 -> V_81 == V_9 -> V_82 ||
! F_85 ( V_160 ) ,
& V_162 ) ;
while ( ! F_19 ( V_9 ) )
F_73 ( V_9 ) ;
if ( F_25 ( ! F_85 ( V_160 ) ) )
GOTO ( V_96 , V_85 = 0 ) ;
if ( V_9 -> V_81 == V_9 -> V_82 &&
F_19 ( V_9 ) )
break;
}
F_7 ( & V_155 -> V_67 ) ;
while ( ! F_20 ( V_9 ) &&
F_85 ( V_160 ) ) {
V_156 = F_16 ( V_9 ) ;
F_11 ( & V_156 -> V_23 ) ;
F_9 ( & V_155 -> V_67 ) ;
F_66 ( & V_156 -> V_166 , V_9 ) ;
F_7 ( & V_155 -> V_67 ) ;
}
F_9 ( & V_155 -> V_67 ) ;
GOTO ( V_96 , V_85 = 0 ) ;
} else if ( 1 ) {
F_117 ( V_171 , F_118 ( V_179 -> V_193 ) &
V_194 ) ;
V_9 -> V_195 = 1 ;
V_171 = F_111 ( V_88 , V_58 , & V_174 ) ;
V_9 -> V_195 = 0 ;
} else {
F_36 ( F_118 ( V_179 -> V_193 ) & V_194 ) ;
F_117 ( V_171 , 1 ) ;
}
}
V_96:
if ( V_9 -> V_17 ) {
F_7 ( & V_155 -> V_67 ) ;
F_104 ( V_170 , V_196 ) ;
F_9 ( & V_155 -> V_67 ) ;
F_56 ( & V_170 -> V_70 ) ;
F_27 ( V_38 , L_24 ,
F_103 () ) ;
F_105 ( V_170 -> V_70 ,
F_64 ( V_170 ) ,
& V_162 ) ;
} else {
F_104 ( & V_9 -> V_69 , V_167 ) ;
}
F_119 ( & V_174 ) ;
F_7 ( & V_155 -> V_44 ) ;
if ( ! F_19 ( V_9 ) ) {
F_104 ( V_160 , V_196 ) ;
F_9 ( & V_155 -> V_44 ) ;
while ( ! F_19 ( V_9 ) )
F_73 ( V_9 ) ;
F_7 ( & V_155 -> V_44 ) ;
}
F_104 ( V_160 , V_167 ) ;
F_9 ( & V_155 -> V_44 ) ;
F_56 ( & V_9 -> V_75 ) ;
F_56 ( & V_160 -> V_70 ) ;
F_62 ( V_9 ) ;
F_101 ( V_65 ) ;
F_27 ( V_38 , L_25 ,
F_103 () , V_65 -> V_163 . V_33 , V_65 -> V_163 . V_32 ) ;
return V_85 ;
}
void F_120 ( struct V_15 * V_88 , void * V_197 )
{
struct V_21 * V_34 = F_30 ( V_88 ) ;
if ( F_25 ( V_197 == NULL ) )
return;
F_7 ( & V_34 -> V_44 ) ;
if ( V_34 -> V_78 != V_197 || V_34 -> V_80 == 0 ) {
F_9 ( & V_34 -> V_44 ) ;
return;
}
V_34 -> V_78 = NULL ;
if ( V_34 -> V_79 ) {
struct V_161 V_162 = { 0 } ;
struct V_159 * V_160 = & V_34 -> V_79 -> V_76 ;
if ( ! F_64 ( V_160 ) ) {
F_104 ( V_160 , V_196 ) ;
F_9 ( & V_34 -> V_44 ) ;
F_56 ( & V_160 -> V_70 ) ;
F_27 ( V_38 , L_26 ,
F_103 () ) ;
F_105 ( V_160 -> V_70 ,
F_64 ( V_160 ) ,
& V_162 ) ;
} else {
F_9 ( & V_34 -> V_44 ) ;
}
F_62 ( V_34 -> V_79 ) ;
} else {
V_34 -> V_80 = 0 ;
F_9 ( & V_34 -> V_44 ) ;
}
}
static int F_121 ( struct V_15 * V_88 , struct V_147 * V_147 )
{
struct V_173 V_174 ;
struct V_47 * V_198 = & V_147 -> V_163 ;
struct V_171 * V_171 ;
T_1 V_58 = 0 ;
int V_199 ;
int V_85 = V_200 ;
F_110 ( & V_174 ) ;
V_171 = F_111 ( V_88 , V_58 , & V_174 ) ;
while ( 1 ) {
struct V_178 * V_179 ;
struct V_180 * V_181 ;
if ( F_92 ( V_171 ) ) {
struct V_21 * V_34 = F_30 ( V_88 ) ;
V_85 = F_93 ( V_171 ) ;
F_108 ( L_20 V_83 L_21 V_39 L_27
L_28 ,
F_65 ( F_79 ( V_88 ) ) , V_58 ,
V_85 , V_34 -> V_80 ) ;
break;
}
V_179 = F_112 ( V_171 ) ;
for ( V_181 = F_113 ( V_179 ) ; V_181 != NULL ;
V_181 = F_114 ( V_181 ) ) {
T_1 V_12 ;
int V_182 ;
char * V_32 ;
V_12 = F_115 ( V_181 -> V_183 ) ;
if ( F_25 ( V_12 < V_58 ) )
continue;
V_182 = F_116 ( V_181 -> V_184 ) ;
if ( F_25 ( V_182 == 0 ) )
continue;
V_32 = V_181 -> V_185 ;
if ( V_32 [ 0 ] == '.' ) {
if ( V_182 == 1 )
continue;
else if ( V_32 [ 1 ] == '.' && V_182 == 2 )
continue;
else
V_199 = 1 ;
} else {
V_199 = 0 ;
}
if ( V_199 && V_198 -> V_32 [ 0 ] != '.' ) {
F_27 ( V_38 , L_29 ,
V_198 -> V_33 , V_198 -> V_32 ,
V_182 , V_32 ) ;
continue;
}
if ( V_198 -> V_33 != V_182 ||
memcmp ( V_198 -> V_32 , V_32 , V_182 ) != 0 )
V_85 = V_200 ;
else if ( ! V_199 )
V_85 = V_201 ;
else
V_85 = V_202 ;
F_117 ( V_171 , 0 ) ;
GOTO ( V_96 , V_85 ) ;
}
V_58 = F_115 ( V_179 -> V_191 ) ;
if ( V_58 == V_192 ) {
F_117 ( V_171 , 0 ) ;
break;
} else if ( 1 ) {
F_117 ( V_171 , F_118 ( V_179 -> V_193 ) &
V_194 ) ;
V_171 = F_111 ( V_88 , V_58 , & V_174 ) ;
} else {
F_36 ( F_118 ( V_179 -> V_193 ) & V_194 ) ;
F_117 ( V_171 , 1 ) ;
}
}
V_96:
F_119 ( & V_174 ) ;
return V_85 ;
}
static void
F_122 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_159 * V_160 = & V_9 -> V_76 ;
struct V_157 * V_158 = F_82 ( V_9 -> V_43 ) ;
int V_203 ;
if ( V_2 != NULL && V_2 -> V_4 == V_113 )
V_203 = 1 ;
else
V_203 = 0 ;
F_48 ( V_9 , V_2 ) ;
if ( V_203 ) {
V_9 -> V_26 ++ ;
V_9 -> V_28 = 0 ;
V_9 -> V_25 = F_123 ( 2 * V_9 -> V_25 , V_158 -> V_204 ) ;
} else {
struct V_21 * V_34 = F_30 ( V_9 -> V_43 ) ;
V_9 -> V_27 ++ ;
V_9 -> V_28 ++ ;
if ( F_21 ( V_9 ) && F_85 ( V_160 ) ) {
F_32 ( & V_158 -> V_205 ) ;
F_27 ( V_38 , L_30 V_83 L_31
L_32 V_39 L_22 V_39
L_33 V_39 L_22 V_39 L_34
L_35 ,
F_65 ( & V_34 -> V_84 ) , V_9 -> V_26 ,
V_9 -> V_27 , V_9 -> V_81 ,
V_9 -> V_82 , F_103 () ) ;
F_7 ( & V_34 -> V_44 ) ;
if ( ! F_64 ( V_160 ) )
F_104 ( V_160 , V_196 ) ;
F_9 ( & V_34 -> V_44 ) ;
}
}
if ( ! F_64 ( V_160 ) )
F_56 ( & V_160 -> V_70 ) ;
}
int F_124 ( struct V_15 * V_88 , struct V_147 * * V_206 ,
int V_207 )
{
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_8 * V_9 = V_34 -> V_79 ;
struct V_147 * V_65 ;
struct V_1 * V_2 ;
struct V_159 * V_160 ;
struct V_161 V_162 = { 0 } ;
int V_85 = 0 ;
struct V_21 * V_155 ;
F_36 ( V_34 -> V_80 == F_103 () ) ;
if ( V_9 ) {
V_160 = & V_9 -> V_76 ;
if ( F_25 ( F_64 ( V_160 ) &&
F_2 ( & V_9 -> V_62 ) ) ) {
F_120 ( V_88 , V_34 -> V_78 ) ;
return - V_102 ;
}
if ( ( * V_206 ) -> V_163 . V_32 [ 0 ] == '.' ) {
if ( V_9 -> V_186 ||
V_9 -> V_208 >= V_9 -> V_187 ) {
} else {
if ( ! V_9 -> V_186 )
V_9 -> V_186 = 1 ;
V_9 -> V_208 ++ ;
return - V_102 ;
}
}
V_2 = F_33 ( V_9 , & ( * V_206 ) -> V_163 ) ;
if ( V_2 == NULL || V_207 ) {
F_122 ( V_9 , V_2 ) ;
return V_2 ? 1 : - V_102 ;
}
while ( ! F_3 ( V_2 ) &&
V_9 -> V_195 &&
! F_19 ( V_9 ) )
F_73 ( V_9 ) ;
if ( ! F_3 ( V_2 ) ) {
V_9 -> V_114 = V_2 -> V_40 ;
V_162 = F_125 ( F_126 ( 30 ) , NULL ,
V_209 , NULL ) ;
V_85 = F_105 ( V_9 -> V_75 ,
F_3 ( V_2 ) ||
F_64 ( V_160 ) ,
& V_162 ) ;
if ( V_85 < 0 ) {
F_122 ( V_9 , V_2 ) ;
return - V_102 ;
}
}
if ( V_2 -> V_4 == V_113 &&
V_2 -> V_56 != NULL ) {
struct V_15 * V_15 = V_2 -> V_56 ;
struct V_89 V_90 = { . V_134 = V_135 ,
. V_104 . V_105 . V_106 =
V_2 -> V_93 } ;
T_1 V_210 ;
V_85 = F_77 ( F_78 ( V_88 ) , & V_90 ,
F_79 ( V_15 ) , & V_210 ) ;
if ( V_85 == 1 ) {
if ( ( * V_206 ) -> V_148 == NULL ) {
* V_206 = F_127 ( V_15 ,
* V_206 ) ;
} else if ( ( * V_206 ) -> V_148 != V_15 ) {
F_27 ( V_38 ,
L_36
L_37 ,
( * V_206 ) -> V_163 . V_33 ,
( * V_206 ) -> V_163 . V_32 ,
( * V_206 ) -> V_148 -> V_109 ,
( * V_206 ) -> V_148 -> V_110 ,
V_15 -> V_109 ,
V_15 -> V_110 ) ;
F_122 ( V_9 , V_2 ) ;
return - V_119 ;
} else {
F_39 ( V_15 ) ;
}
V_2 -> V_56 = NULL ;
if ( ( V_210 & V_211 ) &&
F_128 ( * V_206 ) )
F_129 ( * V_206 ) ;
F_38 ( & V_90 ) ;
}
}
F_122 ( V_9 , V_2 ) ;
return V_85 ;
}
V_85 = F_121 ( V_88 , * V_206 ) ;
if ( V_85 == V_200 )
GOTO ( V_96 , V_85 = - V_102 ) ;
V_9 = F_57 () ;
if ( V_9 == NULL )
GOTO ( V_96 , V_85 = - V_37 ) ;
V_9 -> V_186 = ( V_85 == V_202 ) ;
V_9 -> V_43 = F_55 ( V_88 ) ;
if ( F_25 ( V_9 -> V_43 == NULL ) ) {
F_130 ( L_38 V_83 L_2 ,
F_65 ( & V_34 -> V_84 ) ) ;
GOTO ( V_96 , V_85 = - V_119 ) ;
}
V_65 = F_131 ( ( * V_206 ) -> V_212 ) ;
if ( F_25 ( V_9 -> V_43 != V_65 -> V_148 ) ) {
struct V_21 * V_213 = F_30 ( V_65 -> V_148 ) ;
F_130 ( L_39
L_40 V_83 L_41 V_83 L_2 ,
( * V_206 ) -> V_163 . V_33 , ( * V_206 ) -> V_163 . V_32 ,
F_65 ( & V_34 -> V_84 ) , F_65 ( & V_213 -> V_84 ) ) ;
F_101 ( V_65 ) ;
F_39 ( V_9 -> V_43 ) ;
GOTO ( V_96 , V_85 = - V_102 ) ;
}
F_27 ( V_38 , L_42 ,
F_103 () , V_65 -> V_163 . V_33 , V_65 -> V_163 . V_32 ) ;
V_34 -> V_79 = V_9 ;
V_155 = F_30 ( V_65 -> V_148 ) ;
V_85 = F_93 ( F_107 ( F_109 , V_65 ,
L_43 , V_155 -> V_80 ) ) ;
V_160 = & V_9 -> V_76 ;
if ( F_132 ( V_85 ) ) {
F_108 ( L_44 , V_85 ) ;
F_101 ( V_65 ) ;
V_34 -> V_78 = NULL ;
F_104 ( V_160 , V_167 ) ;
F_104 ( & V_9 -> V_69 , V_167 ) ;
F_62 ( V_9 ) ;
F_36 ( V_34 -> V_79 == NULL ) ;
return - V_102 ;
}
F_105 ( V_160 -> V_70 ,
F_85 ( V_160 ) || F_64 ( V_160 ) ,
& V_162 ) ;
return - V_102 ;
V_96:
if ( V_9 != NULL )
F_40 ( V_9 ) ;
F_7 ( & V_34 -> V_44 ) ;
V_34 -> V_78 = NULL ;
V_34 -> V_80 = 0 ;
F_9 ( & V_34 -> V_44 ) ;
return V_85 ;
}
