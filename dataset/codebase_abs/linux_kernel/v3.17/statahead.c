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
F_27 ( V_38 , L_1 ,
V_33 , V_32 , V_2 , V_29 ) ;
V_2 -> V_39 = V_29 ;
F_28 ( & V_2 -> V_40 , 2 ) ;
V_2 -> V_4 = V_5 ;
V_2 -> V_41 = V_35 ;
V_36 = ( char * ) V_2 + sizeof( struct V_1 ) ;
memcpy ( V_36 , V_32 , V_33 ) ;
V_36 [ V_33 ] = 0 ;
V_2 -> V_11 . V_12 = F_29 ( V_32 , V_33 ) ;
V_2 -> V_11 . V_33 = V_33 ;
V_2 -> V_11 . V_32 = V_36 ;
V_34 = F_30 ( V_9 -> V_42 ) ;
F_7 ( & V_34 -> V_43 ) ;
F_8 ( & V_2 -> V_44 , & V_9 -> V_45 ) ;
F_31 ( & V_2 -> V_20 ) ;
F_6 ( V_9 , V_2 ) ;
F_9 ( & V_34 -> V_43 ) ;
F_32 ( & V_9 -> V_24 ) ;
return V_2 ;
}
static struct V_1 *
F_33 ( struct V_8 * V_9 , const struct V_46 * V_46 )
{
struct V_1 * V_2 ;
int V_10 = F_5 ( V_46 -> V_12 ) ;
F_34 (entry, &sai->sai_cache[i], se_hash) {
if ( V_2 -> V_11 . V_12 == V_46 -> V_12 &&
V_2 -> V_11 . V_33 == V_46 -> V_33 &&
memcmp ( V_2 -> V_11 . V_32 , V_46 -> V_32 , V_46 -> V_33 ) == 0 )
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_35 ( struct V_8 * V_9 , T_1 V_29 )
{
struct V_1 * V_2 ;
F_34 (entry, &sai->sai_entries, se_link) {
if ( V_2 -> V_39 == V_29 ) {
F_36 ( F_18 ( & V_2 -> V_40 ) > 0 ) ;
F_32 ( & V_2 -> V_40 ) ;
return V_2 ;
}
if ( V_2 -> V_39 > V_29 )
break;
}
return NULL ;
}
static void F_37 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
struct V_47 * V_48 = V_2 -> V_49 ;
struct V_50 * V_51 = V_2 -> V_52 ;
if ( V_48 ) {
V_2 -> V_49 = NULL ;
F_38 ( & V_48 -> V_53 ) ;
F_39 ( V_48 -> V_54 ) ;
F_40 ( V_48 ) ;
}
if ( V_51 ) {
V_2 -> V_52 = NULL ;
F_41 ( V_51 ) ;
}
}
static void F_42 ( struct V_8 * V_9 ,
struct V_1 * V_2 )
{
if ( F_43 ( & V_2 -> V_40 ) ) {
F_27 ( V_38 , L_2 ,
V_2 -> V_11 . V_33 , V_2 -> V_11 . V_32 , V_2 ,
V_2 -> V_39 ) ;
F_36 ( F_2 ( & V_2 -> V_44 ) ) ;
F_36 ( F_2 ( & V_2 -> V_20 ) ) ;
F_36 ( F_1 ( V_2 ) ) ;
F_37 ( V_9 , V_2 ) ;
if ( V_2 -> V_55 )
F_39 ( V_2 -> V_55 ) ;
F_44 ( V_2 , V_2 -> V_41 ) ;
F_45 ( & V_9 -> V_24 ) ;
}
}
static inline void
F_46 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_21 * V_34 = F_30 ( V_9 -> V_42 ) ;
F_36 ( ! F_1 ( V_2 ) ) ;
F_36 ( ! F_2 ( & V_2 -> V_44 ) ) ;
F_10 ( V_9 , V_2 ) ;
F_7 ( & V_34 -> V_43 ) ;
V_2 -> V_4 = V_56 ;
F_11 ( & V_2 -> V_44 ) ;
if ( F_47 ( ! F_2 ( & V_2 -> V_20 ) ) )
F_11 ( & V_2 -> V_20 ) ;
F_9 ( & V_34 -> V_43 ) ;
F_42 ( V_9 , V_2 ) ;
}
static void
F_48 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_1 * V_57 , * V_19 ;
if ( V_2 )
F_46 ( V_9 , V_2 ) ;
F_49 (pos, next, &sai->sai_entries, se_link) {
if ( ! F_22 ( V_9 , V_57 -> V_39 ) )
break;
F_46 ( V_9 , V_57 ) ;
}
}
static void
F_50 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_58 )
{
struct V_1 * V_59 ;
struct V_60 * V_57 = & V_9 -> V_61 ;
if ( ! F_2 ( & V_2 -> V_20 ) )
F_11 ( & V_2 -> V_20 ) ;
F_51 (se, &sai->sai_entries_stated, se_list) {
if ( V_59 -> V_39 < V_2 -> V_39 ) {
V_57 = & V_59 -> V_20 ;
break;
}
}
F_52 ( & V_2 -> V_20 , V_57 ) ;
V_2 -> V_4 = V_58 ;
}
static int
F_53 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_58 )
{
struct V_21 * V_34 = F_30 ( V_9 -> V_42 ) ;
int V_62 = 1 ;
F_37 ( V_9 , V_2 ) ;
F_7 ( & V_34 -> V_43 ) ;
if ( F_47 ( V_2 -> V_4 != V_56 ) ) {
F_50 ( V_9 , V_2 , V_58 ) ;
V_62 = 0 ;
}
F_9 ( & V_34 -> V_43 ) ;
return V_62 ;
}
static void F_54 ( struct V_8 * V_9 ,
struct V_15 * V_15 , int V_29 )
{
struct V_21 * V_63 = F_30 ( V_15 ) ;
struct V_21 * V_64 = F_30 ( V_9 -> V_42 ) ;
int V_65 = 0 ;
F_7 ( & V_63 -> V_66 ) ;
if ( V_63 -> V_67 == 0 ) {
V_63 -> V_67 = V_29 ;
F_9 ( & V_63 -> V_66 ) ;
F_36 ( F_2 ( & V_63 -> V_23 ) ) ;
F_55 ( V_15 ) ;
F_7 ( & V_64 -> V_66 ) ;
if ( F_20 ( V_9 ) )
V_65 = 1 ;
F_8 ( & V_63 -> V_23 , & V_9 -> V_22 ) ;
F_9 ( & V_64 -> V_66 ) ;
} else {
F_9 ( & V_63 -> V_66 ) ;
}
if ( V_65 > 0 )
F_56 ( & V_9 -> V_68 . V_69 ) ;
}
static struct V_8 * F_57 ( void )
{
struct V_8 * V_9 ;
int V_10 ;
F_58 ( V_9 ) ;
if ( ! V_9 )
return NULL ;
F_28 ( & V_9 -> V_70 , 1 ) ;
F_7 ( & V_71 ) ;
V_9 -> V_72 = ++ V_72 ;
if ( F_25 ( V_72 == 0 ) )
V_9 -> V_72 = ++ V_72 ;
F_9 ( & V_71 ) ;
V_9 -> V_25 = V_73 ;
V_9 -> V_31 = 1 ;
F_59 ( & V_9 -> V_74 ) ;
F_59 ( & V_9 -> V_75 . V_69 ) ;
F_59 ( & V_9 -> V_68 . V_69 ) ;
F_31 ( & V_9 -> V_45 ) ;
F_31 ( & V_9 -> V_18 ) ;
F_31 ( & V_9 -> V_61 ) ;
F_31 ( & V_9 -> V_22 ) ;
for ( V_10 = 0 ; V_10 < V_76 ; V_10 ++ ) {
F_31 ( & V_9 -> V_14 [ V_10 ] ) ;
F_60 ( & V_9 -> V_13 [ V_10 ] ) ;
}
F_28 ( & V_9 -> V_24 , 0 ) ;
return V_9 ;
}
static inline struct V_8 *
F_61 ( struct V_8 * V_9 )
{
F_32 ( & V_9 -> V_70 ) ;
return V_9 ;
}
static void F_62 ( struct V_8 * V_9 )
{
struct V_15 * V_15 = V_9 -> V_42 ;
struct V_21 * V_34 = F_30 ( V_15 ) ;
if ( F_63 ( & V_9 -> V_70 , & V_34 -> V_43 ) ) {
struct V_1 * V_2 , * V_19 ;
if ( F_25 ( F_18 ( & V_9 -> V_70 ) > 0 ) ) {
F_9 ( & V_34 -> V_43 ) ;
return;
}
F_36 ( V_34 -> V_77 == NULL ) ;
F_36 ( F_64 ( & V_9 -> V_75 ) ) ;
F_36 ( F_64 ( & V_9 -> V_68 ) ) ;
V_34 -> V_78 = NULL ;
V_34 -> V_79 = 0 ;
F_9 ( & V_34 -> V_43 ) ;
if ( V_9 -> V_80 > V_9 -> V_81 )
F_27 ( V_38 , L_3 V_82
L_4 ,
F_65 ( & V_34 -> V_83 ) ,
V_9 -> V_80 , V_9 -> V_81 ) ;
F_49 (entry, next,
&sai->sai_entries, se_link)
F_46 ( V_9 , V_2 ) ;
F_36 ( F_2 ( & V_9 -> V_45 ) ) ;
F_36 ( F_19 ( V_9 ) ) ;
F_36 ( F_2 ( & V_9 -> V_61 ) ) ;
F_36 ( F_18 ( & V_9 -> V_24 ) == 0 ) ;
F_36 ( F_20 ( V_9 ) ) ;
F_39 ( V_15 ) ;
F_40 ( V_9 ) ;
}
}
static void F_66 ( struct V_15 * V_15 , struct V_8 * V_9 )
{
struct V_21 * V_34 = F_30 ( V_15 ) ;
T_1 V_29 = V_34 -> V_67 ;
int V_84 ;
F_36 ( F_2 ( & V_34 -> V_23 ) ) ;
if ( F_22 ( V_9 , V_29 + 1 ) ) {
V_34 -> V_67 = 0 ;
F_39 ( V_15 ) ;
return;
}
V_84 = F_67 ( & V_34 -> V_85 ) ;
if ( V_84 == 0 ) {
V_34 -> V_67 = 0 ;
F_39 ( V_15 ) ;
return;
}
if ( V_34 -> V_86 != 0 &&
F_68 ( F_69 ( - 1 ) , V_34 -> V_86 ) ) {
F_70 ( & V_34 -> V_85 ) ;
V_34 -> V_67 = 0 ;
F_39 ( V_15 ) ;
return;
}
F_27 ( V_38 , L_5
V_82 L_6 , F_65 ( & V_34 -> V_83 ) , V_29 ) ;
F_71 ( V_15 ) ;
V_34 -> V_67 = 0 ;
V_34 -> V_86 = F_72 () ;
F_70 ( & V_34 -> V_85 ) ;
F_27 ( V_38 , L_7
V_82 L_8 ,
F_65 ( & V_34 -> V_83 ) , V_29 , V_84 ) ;
F_39 ( V_15 ) ;
}
static void F_73 ( struct V_8 * V_9 )
{
struct V_15 * V_87 = V_9 -> V_42 ;
struct V_15 * V_63 ;
struct V_21 * V_34 = F_30 ( V_87 ) ;
struct V_1 * V_2 ;
struct V_47 * V_48 ;
struct V_88 * V_89 ;
struct V_50 * V_51 ;
struct V_90 * V_91 ;
int V_84 = 0 ;
F_7 ( & V_34 -> V_43 ) ;
if ( F_25 ( F_19 ( V_9 ) ) ) {
F_9 ( & V_34 -> V_43 ) ;
return;
}
V_2 = F_14 ( V_9 ) ;
F_32 ( & V_2 -> V_40 ) ;
F_11 ( & V_2 -> V_20 ) ;
F_9 ( & V_34 -> V_43 ) ;
F_36 ( V_2 -> V_92 != 0 ) ;
V_48 = V_2 -> V_49 ;
V_89 = & V_48 -> V_53 ;
V_51 = V_2 -> V_52 ;
V_91 = F_74 ( & V_51 -> V_93 , & V_94 ) ;
if ( V_91 == NULL )
GOTO ( V_95 , V_84 = - V_96 ) ;
V_63 = V_2 -> V_55 ;
if ( V_63 == NULL ) {
F_36 ( F_75 ( & V_48 -> V_97 . V_98 ) ) ;
if ( V_91 -> V_99 & V_100 )
GOTO ( V_95 , V_84 = - V_101 ) ;
} else {
if ( F_25 ( ! F_76 ( & V_48 -> V_97 . V_98 , & V_91 -> V_102 ) ) ) {
V_2 -> V_55 = NULL ;
F_39 ( V_63 ) ;
V_63 = NULL ;
}
}
V_89 -> V_103 . V_104 . V_105 = V_2 -> V_92 ;
V_84 = F_77 ( F_78 ( V_87 ) , V_89 , F_79 ( V_87 ) , NULL ) ;
if ( V_84 != 1 )
GOTO ( V_95 , V_84 = - V_101 ) ;
V_84 = F_80 ( & V_63 , V_51 , V_87 -> V_106 , V_89 ) ;
if ( V_84 )
GOTO ( V_95 , V_84 ) ;
F_27 ( V_107 , L_9 ,
V_63 , V_63 -> V_108 , V_63 -> V_109 ) ;
F_81 ( F_82 ( V_87 ) -> V_110 , V_63 , V_89 , NULL ) ;
V_2 -> V_55 = V_63 ;
if ( F_12 ( V_9 , V_63 ) )
F_54 ( V_9 , V_63 , V_2 -> V_39 ) ;
V_95:
V_84 = F_53 ( V_9 , V_2 ,
V_84 < 0 ? V_111 : V_112 ) ;
if ( V_84 == 0 && V_2 -> V_39 == V_9 -> V_113 )
F_56 ( & V_9 -> V_74 ) ;
F_42 ( V_9 , V_2 ) ;
}
static int F_83 ( struct V_50 * V_51 ,
struct V_47 * V_48 , int V_84 )
{
struct V_88 * V_89 = & V_48 -> V_53 ;
struct V_15 * V_87 = V_48 -> V_54 ;
struct V_21 * V_34 = F_30 ( V_87 ) ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 ;
int V_114 ;
if ( F_84 ( V_89 , V_115 ) )
V_84 = - V_116 ;
F_7 ( & V_34 -> V_43 ) ;
if ( F_25 ( V_34 -> V_78 == NULL ||
V_34 -> V_78 -> V_72 != V_48 -> V_117 ) ) {
F_9 ( & V_34 -> V_43 ) ;
GOTO ( V_95 , V_84 = - V_118 ) ;
} else {
V_9 = F_61 ( V_34 -> V_78 ) ;
if ( F_25 ( ! F_85 ( & V_9 -> V_75 ) ) ) {
V_9 -> V_81 ++ ;
F_9 ( & V_34 -> V_43 ) ;
GOTO ( V_95 , V_84 = - V_119 ) ;
}
V_2 = F_35 ( V_9 , V_48 -> V_120 ) ;
if ( V_2 == NULL ) {
V_9 -> V_81 ++ ;
F_9 ( & V_34 -> V_43 ) ;
GOTO ( V_95 , V_84 = - V_121 ) ;
}
if ( V_84 != 0 ) {
F_50 ( V_9 , V_2 , V_111 ) ;
V_114 = ( V_2 -> V_39 == V_9 -> V_113 ) ;
} else {
V_2 -> V_49 = V_48 ;
V_2 -> V_52 = F_86 ( V_51 ) ;
V_2 -> V_92 = V_89 -> V_103 . V_104 . V_105 ;
F_87 ( V_89 ) ;
V_114 = F_19 ( V_9 ) ;
F_8 ( & V_2 -> V_20 ,
& V_9 -> V_18 ) ;
}
V_9 -> V_81 ++ ;
F_9 ( & V_34 -> V_43 ) ;
F_42 ( V_9 , V_2 ) ;
if ( V_114 )
F_56 ( & V_9 -> V_75 . V_69 ) ;
}
V_95:
if ( V_84 != 0 ) {
F_38 ( V_89 ) ;
F_39 ( V_87 ) ;
F_40 ( V_48 ) ;
}
if ( V_9 != NULL )
F_62 ( V_9 ) ;
return V_84 ;
}
static void F_88 ( struct V_47 * V_48 ,
struct V_122 * V_123 )
{
F_36 ( V_48 && V_123 ) ;
F_39 ( V_48 -> V_54 ) ;
F_89 ( V_48 -> V_97 . V_124 ) ;
F_89 ( V_48 -> V_97 . V_125 ) ;
F_40 ( V_48 ) ;
F_40 ( V_123 ) ;
}
static int F_90 ( struct V_15 * V_87 , struct V_15 * V_63 ,
struct V_1 * V_2 , struct V_47 * * V_126 ,
struct V_122 * * V_127 ,
struct V_128 * * V_129 )
{
struct V_46 * V_46 = & V_2 -> V_11 ;
struct V_21 * V_34 = F_30 ( V_87 ) ;
struct V_47 * V_48 ;
struct V_122 * V_123 ;
struct V_130 * V_131 ;
F_58 ( V_123 ) ;
if ( V_123 == NULL )
return - V_37 ;
F_58 ( V_48 ) ;
if ( V_48 == NULL ) {
F_40 ( V_123 ) ;
return - V_37 ;
}
V_131 = F_91 ( & V_48 -> V_97 , V_87 , V_63 , V_46 -> V_32 ,
V_46 -> V_33 , 0 , V_132 , NULL ) ;
if ( F_92 ( V_131 ) ) {
F_40 ( V_123 ) ;
F_40 ( V_48 ) ;
return F_93 ( V_131 ) ;
}
V_48 -> V_53 . V_133 = V_134 ;
V_48 -> V_54 = F_55 ( V_87 ) ;
V_48 -> V_135 = F_83 ;
V_48 -> V_117 = V_34 -> V_78 -> V_72 ;
V_48 -> V_120 = V_2 -> V_39 ;
V_123 -> V_136 = V_137 ;
V_123 -> V_138 = F_94 ( & V_48 -> V_53 ) ;
V_123 -> V_139 = V_140 ;
V_123 -> V_141 = V_142 ;
V_123 -> V_143 = NULL ;
V_123 -> V_144 = NULL ;
* V_126 = V_48 ;
* V_127 = V_123 ;
V_129 [ 0 ] = V_131 -> V_124 ;
V_129 [ 1 ] = V_131 -> V_125 ;
return 0 ;
}
static int F_95 ( struct V_15 * V_87 , struct V_1 * V_2 )
{
struct V_47 * V_48 ;
struct V_122 * V_123 ;
struct V_128 * V_145 [ 2 ] ;
int V_84 ;
V_84 = F_90 ( V_87 , NULL , V_2 , & V_48 , & V_123 , V_145 ) ;
if ( V_84 )
return V_84 ;
V_84 = F_96 ( F_78 ( V_87 ) , V_48 , V_123 ) ;
if ( ! V_84 ) {
F_89 ( V_145 [ 0 ] ) ;
F_89 ( V_145 [ 1 ] ) ;
} else {
F_88 ( V_48 , V_123 ) ;
}
return V_84 ;
}
static int F_97 ( struct V_15 * V_87 , struct V_1 * V_2 ,
struct V_146 * V_146 )
{
struct V_15 * V_15 = V_146 -> V_147 ;
struct V_88 V_89 = { . V_133 = V_134 ,
. V_103 . V_104 . V_105 = 0 } ;
struct V_47 * V_48 ;
struct V_122 * V_123 ;
struct V_128 * V_145 [ 2 ] ;
int V_84 ;
if ( F_25 ( V_15 == NULL ) )
return 1 ;
if ( F_98 ( V_146 ) )
return 1 ;
V_2 -> V_55 = F_55 ( V_15 ) ;
V_84 = F_77 ( F_78 ( V_87 ) , & V_89 , F_79 ( V_15 ) , NULL ) ;
if ( V_84 == 1 ) {
V_2 -> V_92 = V_89 . V_103 . V_104 . V_105 ;
F_38 ( & V_89 ) ;
return 1 ;
}
V_84 = F_90 ( V_87 , V_15 , V_2 , & V_48 , & V_123 , V_145 ) ;
if ( V_84 ) {
V_2 -> V_55 = NULL ;
F_39 ( V_15 ) ;
return V_84 ;
}
V_84 = F_96 ( F_78 ( V_87 ) , V_48 , V_123 ) ;
if ( ! V_84 ) {
F_89 ( V_145 [ 0 ] ) ;
F_89 ( V_145 [ 1 ] ) ;
} else {
V_2 -> V_55 = NULL ;
F_39 ( V_15 ) ;
F_88 ( V_48 , V_123 ) ;
}
return V_84 ;
}
static void F_99 ( struct V_146 * V_64 , const char * V_148 ,
int V_149 )
{
struct V_15 * V_87 = V_64 -> V_147 ;
struct V_21 * V_34 = F_30 ( V_87 ) ;
struct V_8 * V_9 = V_34 -> V_78 ;
struct V_146 * V_146 = NULL ;
struct V_1 * V_2 ;
int V_84 ;
int V_150 ;
V_2 = F_23 ( V_9 , V_9 -> V_31 , V_148 ,
V_149 ) ;
if ( F_92 ( V_2 ) )
return;
V_146 = F_100 ( V_64 , & V_2 -> V_11 ) ;
if ( ! V_146 ) {
V_84 = F_95 ( V_87 , V_2 ) ;
} else {
V_84 = F_97 ( V_87 , V_2 , V_146 ) ;
if ( V_84 == 1 && F_12 ( V_9 , V_146 -> V_147 ) )
F_54 ( V_9 , V_146 -> V_147 , V_2 -> V_39 ) ;
}
if ( V_146 != NULL )
F_101 ( V_146 ) ;
if ( V_84 ) {
V_150 = F_53 ( V_9 , V_2 ,
V_84 < 0 ? V_111 : V_112 ) ;
if ( V_150 == 0 && V_2 -> V_39 == V_9 -> V_113 )
F_56 ( & V_9 -> V_74 ) ;
} else {
V_9 -> V_80 ++ ;
}
V_9 -> V_31 ++ ;
F_42 ( V_9 , V_2 ) ;
}
static int F_102 ( void * V_151 )
{
struct V_146 * V_64 = (struct V_146 * ) V_151 ;
struct V_15 * V_87 = V_64 -> V_147 ;
struct V_21 * V_152 = F_30 ( V_87 ) ;
struct V_21 * V_153 ;
struct V_154 * V_155 = F_82 ( V_87 ) ;
struct V_8 * V_9 = F_61 ( V_152 -> V_78 ) ;
struct V_156 * V_157 = & V_9 -> V_68 ;
struct V_158 V_159 = { 0 } ;
V_157 -> V_160 = F_103 () ;
F_27 ( V_38 , L_10 ,
V_9 , V_64 -> V_161 . V_33 , V_64 -> V_161 . V_32 ) ;
F_32 ( & V_155 -> V_162 ) ;
F_7 ( & V_152 -> V_66 ) ;
V_9 -> V_17 = 1 ;
if ( F_104 ( V_157 ) )
F_105 ( V_157 , V_163 ) ;
F_9 ( & V_152 -> V_66 ) ;
F_56 ( & V_157 -> V_69 ) ;
while ( 1 ) {
F_106 ( V_157 -> V_69 ,
! F_20 ( V_9 ) ||
! F_85 ( V_157 ) ,
& V_159 ) ;
if ( ! F_85 ( V_157 ) )
break;
F_7 ( & V_152 -> V_66 ) ;
if ( ! F_20 ( V_9 ) ) {
V_153 = F_16 ( V_9 ) ;
F_11 ( & V_153 -> V_23 ) ;
F_9 ( & V_152 -> V_66 ) ;
F_66 ( & V_153 -> V_164 , V_9 ) ;
} else {
F_9 ( & V_152 -> V_66 ) ;
}
}
F_7 ( & V_152 -> V_66 ) ;
V_9 -> V_17 = 0 ;
while ( ! F_20 ( V_9 ) ) {
V_153 = F_16 ( V_9 ) ;
F_11 ( & V_153 -> V_23 ) ;
F_9 ( & V_152 -> V_66 ) ;
V_153 -> V_67 = 0 ;
F_39 ( & V_153 -> V_164 ) ;
F_7 ( & V_152 -> V_66 ) ;
}
F_105 ( V_157 , V_165 ) ;
F_9 ( & V_152 -> V_66 ) ;
F_56 ( & V_157 -> V_69 ) ;
F_62 ( V_9 ) ;
F_27 ( V_38 , L_11 ,
V_9 , V_64 -> V_161 . V_33 , V_64 -> V_161 . V_32 ) ;
return 0 ;
}
static void F_107 ( struct V_146 * V_64 , struct V_8 * V_9 )
{
struct V_156 * V_157 = & V_9 -> V_68 ;
struct V_158 V_159 = { 0 } ;
struct V_21 * V_152 ;
struct V_166 * V_167 ;
F_27 ( V_38 , L_12 ,
V_9 , V_64 -> V_161 . V_33 , V_64 -> V_161 . V_32 ) ;
V_152 = F_30 ( V_64 -> V_147 ) ;
V_167 = F_108 ( F_102 , V_64 ,
L_13 , V_152 -> V_79 ) ;
if ( F_92 ( V_167 ) ) {
F_109 ( L_14 , F_93 ( V_167 ) ) ;
F_105 ( V_157 , V_165 ) ;
return;
}
F_106 ( V_157 -> V_69 ,
F_85 ( V_157 ) || F_64 ( V_157 ) ,
& V_159 ) ;
}
static int F_110 ( void * V_151 )
{
struct V_146 * V_64 = (struct V_146 * ) V_151 ;
struct V_15 * V_87 = V_64 -> V_147 ;
struct V_21 * V_152 = F_30 ( V_87 ) ;
struct V_21 * V_153 ;
struct V_154 * V_155 = F_82 ( V_87 ) ;
struct V_8 * V_9 = F_61 ( V_152 -> V_78 ) ;
struct V_156 * V_157 = & V_9 -> V_75 ;
struct V_156 * V_168 = & V_9 -> V_68 ;
struct V_169 * V_169 ;
T_1 V_57 = 0 ;
int V_170 = 0 ;
int V_84 = 0 ;
struct V_171 V_172 ;
struct V_158 V_159 = { 0 } ;
V_157 -> V_160 = F_103 () ;
F_27 ( V_38 , L_15 ,
V_9 , V_64 -> V_161 . V_33 , V_64 -> V_161 . V_32 ) ;
if ( V_155 -> V_173 & V_174 )
F_107 ( V_64 , V_9 ) ;
F_32 ( & V_155 -> V_175 ) ;
F_7 ( & V_152 -> V_43 ) ;
if ( F_104 ( V_157 ) )
F_105 ( V_157 , V_163 ) ;
F_9 ( & V_152 -> V_43 ) ;
F_56 ( & V_157 -> V_69 ) ;
F_111 ( & V_172 ) ;
V_169 = F_112 ( V_87 , V_57 , & V_172 ) ;
while ( 1 ) {
struct V_176 * V_177 ;
struct V_178 * V_179 ;
if ( F_92 ( V_169 ) ) {
V_84 = F_93 ( V_169 ) ;
F_27 ( V_38 , L_16 V_82 L_17 ,
F_65 ( F_79 ( V_87 ) ) , V_57 , V_9 -> V_31 ,
V_84 , V_152 -> V_79 ) ;
GOTO ( V_95 , V_84 ) ;
}
V_177 = F_113 ( V_169 ) ;
for ( V_179 = F_114 ( V_177 ) ; V_179 != NULL ;
V_179 = F_115 ( V_179 ) ) {
T_1 V_12 ;
int V_180 ;
char * V_32 ;
V_12 = F_116 ( V_179 -> V_181 ) ;
if ( F_25 ( V_12 < V_57 ) )
continue;
V_180 = F_117 ( V_179 -> V_182 ) ;
if ( F_25 ( V_180 == 0 ) )
continue;
V_32 = V_179 -> V_183 ;
if ( V_32 [ 0 ] == '.' ) {
if ( V_180 == 1 ) {
continue;
} else if ( V_32 [ 1 ] == '.' && V_180 == 2 ) {
continue;
} else if ( ! V_9 -> V_184 ) {
V_9 -> V_185 ++ ;
continue;
}
}
if ( F_25 ( ++ V_170 == 1 ) )
continue;
V_186:
F_106 ( V_157 -> V_69 ,
! F_17 ( V_9 ) ||
! F_19 ( V_9 ) ||
! F_20 ( V_9 ) ||
! F_85 ( V_157 ) ,
& V_159 ) ;
V_187:
while ( ! F_19 ( V_9 ) )
F_73 ( V_9 ) ;
if ( F_25 ( ! F_85 ( V_157 ) ) ) {
F_118 ( V_169 , 0 ) ;
GOTO ( V_95 , V_84 = 0 ) ;
}
if ( F_17 ( V_9 ) ) {
F_7 ( & V_152 -> V_66 ) ;
while ( ! F_20 ( V_9 ) ) {
V_153 = F_16 ( V_9 ) ;
F_11 ( & V_153 -> V_23 ) ;
F_9 ( & V_152 -> V_66 ) ;
F_66 ( & V_153 -> V_164 ,
V_9 ) ;
if ( ! F_19 ( V_9 ) )
goto V_187;
if ( F_25 (
! F_85 ( V_157 ) ) ) {
F_118 ( V_169 , 0 ) ;
GOTO ( V_95 , V_84 = 0 ) ;
}
if ( ! F_17 ( V_9 ) )
goto V_188;
F_7 ( & V_152 -> V_66 ) ;
}
F_9 ( & V_152 -> V_66 ) ;
goto V_186;
}
V_188:
F_99 ( V_64 , V_32 , V_180 ) ;
}
V_57 = F_116 ( V_177 -> V_189 ) ;
if ( V_57 == V_190 ) {
F_118 ( V_169 , 0 ) ;
while ( 1 ) {
F_106 ( V_157 -> V_69 ,
! F_19 ( V_9 ) ||
V_9 -> V_80 == V_9 -> V_81 ||
! F_85 ( V_157 ) ,
& V_159 ) ;
while ( ! F_19 ( V_9 ) )
F_73 ( V_9 ) ;
if ( F_25 ( ! F_85 ( V_157 ) ) )
GOTO ( V_95 , V_84 = 0 ) ;
if ( V_9 -> V_80 == V_9 -> V_81 &&
F_19 ( V_9 ) )
break;
}
F_7 ( & V_152 -> V_66 ) ;
while ( ! F_20 ( V_9 ) &&
F_85 ( V_157 ) ) {
V_153 = F_16 ( V_9 ) ;
F_11 ( & V_153 -> V_23 ) ;
F_9 ( & V_152 -> V_66 ) ;
F_66 ( & V_153 -> V_164 , V_9 ) ;
F_7 ( & V_152 -> V_66 ) ;
}
F_9 ( & V_152 -> V_66 ) ;
GOTO ( V_95 , V_84 = 0 ) ;
} else if ( 1 ) {
F_118 ( V_169 , F_119 ( V_177 -> V_191 ) &
V_192 ) ;
V_169 = F_112 ( V_87 , V_57 , & V_172 ) ;
} else {
F_36 ( F_119 ( V_177 -> V_191 ) & V_192 ) ;
F_118 ( V_169 , 1 ) ;
}
}
V_95:
if ( V_9 -> V_17 ) {
F_7 ( & V_152 -> V_66 ) ;
F_105 ( V_168 , V_193 ) ;
F_9 ( & V_152 -> V_66 ) ;
F_56 ( & V_168 -> V_69 ) ;
F_27 ( V_38 , L_18 ,
V_9 , ( unsigned int ) V_168 -> V_160 ) ;
F_106 ( V_168 -> V_69 ,
F_64 ( V_168 ) ,
& V_159 ) ;
} else {
F_105 ( & V_9 -> V_68 , V_165 ) ;
}
F_120 ( & V_172 ) ;
F_7 ( & V_152 -> V_43 ) ;
if ( ! F_19 ( V_9 ) ) {
F_105 ( V_157 , V_193 ) ;
F_9 ( & V_152 -> V_43 ) ;
while ( ! F_19 ( V_9 ) )
F_73 ( V_9 ) ;
F_7 ( & V_152 -> V_43 ) ;
}
F_105 ( V_157 , V_165 ) ;
F_9 ( & V_152 -> V_43 ) ;
F_56 ( & V_9 -> V_74 ) ;
F_56 ( & V_157 -> V_69 ) ;
F_62 ( V_9 ) ;
F_101 ( V_64 ) ;
F_27 ( V_38 , L_19 ,
V_9 , V_64 -> V_161 . V_33 , V_64 -> V_161 . V_32 ) ;
return V_84 ;
}
void F_121 ( struct V_15 * V_87 , void * V_194 )
{
struct V_21 * V_34 = F_30 ( V_87 ) ;
if ( F_25 ( V_194 == NULL ) )
return;
F_7 ( & V_34 -> V_43 ) ;
if ( V_34 -> V_77 != V_194 || V_34 -> V_79 == 0 ) {
F_9 ( & V_34 -> V_43 ) ;
return;
}
V_34 -> V_77 = NULL ;
if ( V_34 -> V_78 ) {
struct V_158 V_159 = { 0 } ;
struct V_156 * V_157 = & V_34 -> V_78 -> V_75 ;
if ( ! F_64 ( V_157 ) ) {
F_105 ( V_157 , V_193 ) ;
F_9 ( & V_34 -> V_43 ) ;
F_56 ( & V_157 -> V_69 ) ;
F_27 ( V_38 , L_20 ,
V_34 -> V_78 , ( unsigned int ) V_157 -> V_160 ) ;
F_106 ( V_157 -> V_69 ,
F_64 ( V_157 ) ,
& V_159 ) ;
} else {
F_9 ( & V_34 -> V_43 ) ;
}
F_62 ( V_34 -> V_78 ) ;
} else {
V_34 -> V_79 = 0 ;
F_9 ( & V_34 -> V_43 ) ;
}
}
static int F_122 ( struct V_15 * V_87 , struct V_146 * V_146 )
{
struct V_171 V_172 ;
struct V_46 * V_195 = & V_146 -> V_161 ;
struct V_169 * V_169 ;
T_1 V_57 = 0 ;
int V_196 ;
int V_84 = V_197 ;
F_111 ( & V_172 ) ;
V_169 = F_112 ( V_87 , V_57 , & V_172 ) ;
while ( 1 ) {
struct V_176 * V_177 ;
struct V_178 * V_179 ;
if ( F_92 ( V_169 ) ) {
struct V_21 * V_34 = F_30 ( V_87 ) ;
V_84 = F_93 ( V_169 ) ;
F_109 ( L_16 V_82 L_21 ,
F_65 ( F_79 ( V_87 ) ) , V_57 ,
V_84 , V_34 -> V_79 ) ;
break;
}
V_177 = F_113 ( V_169 ) ;
for ( V_179 = F_114 ( V_177 ) ; V_179 != NULL ;
V_179 = F_115 ( V_179 ) ) {
T_1 V_12 ;
int V_180 ;
char * V_32 ;
V_12 = F_116 ( V_179 -> V_181 ) ;
if ( F_25 ( V_12 < V_57 ) )
continue;
V_180 = F_117 ( V_179 -> V_182 ) ;
if ( F_25 ( V_180 == 0 ) )
continue;
V_32 = V_179 -> V_183 ;
if ( V_32 [ 0 ] == '.' ) {
if ( V_180 == 1 )
continue;
else if ( V_32 [ 1 ] == '.' && V_180 == 2 )
continue;
else
V_196 = 1 ;
} else {
V_196 = 0 ;
}
if ( V_196 && V_195 -> V_32 [ 0 ] != '.' ) {
F_27 ( V_38 , L_22 ,
V_195 -> V_33 , V_195 -> V_32 ,
V_180 , V_32 ) ;
continue;
}
if ( V_195 -> V_33 != V_180 ||
memcmp ( V_195 -> V_32 , V_32 , V_180 ) != 0 )
V_84 = V_197 ;
else if ( ! V_196 )
V_84 = V_198 ;
else
V_84 = V_199 ;
F_118 ( V_169 , 0 ) ;
GOTO ( V_95 , V_84 ) ;
}
V_57 = F_116 ( V_177 -> V_189 ) ;
if ( V_57 == V_190 ) {
F_118 ( V_169 , 0 ) ;
break;
} else if ( 1 ) {
F_118 ( V_169 , F_119 ( V_177 -> V_191 ) &
V_192 ) ;
V_169 = F_112 ( V_87 , V_57 , & V_172 ) ;
} else {
F_36 ( F_119 ( V_177 -> V_191 ) & V_192 ) ;
F_118 ( V_169 , 1 ) ;
}
}
V_95:
F_120 ( & V_172 ) ;
return V_84 ;
}
static void
F_123 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_156 * V_157 = & V_9 -> V_75 ;
struct V_154 * V_155 = F_82 ( V_9 -> V_42 ) ;
int V_200 ;
if ( V_2 != NULL && V_2 -> V_4 == V_112 )
V_200 = 1 ;
else
V_200 = 0 ;
F_48 ( V_9 , V_2 ) ;
if ( V_200 ) {
V_9 -> V_26 ++ ;
V_9 -> V_28 = 0 ;
V_9 -> V_25 = F_124 ( 2 * V_9 -> V_25 , V_155 -> V_201 ) ;
} else {
struct V_21 * V_34 = F_30 ( V_9 -> V_42 ) ;
V_9 -> V_27 ++ ;
V_9 -> V_28 ++ ;
if ( F_21 ( V_9 ) && F_85 ( V_157 ) ) {
F_32 ( & V_155 -> V_202 ) ;
F_27 ( V_38 , L_23 V_82 L_24
L_25
L_26
L_27 ,
F_65 ( & V_34 -> V_83 ) , V_9 -> V_26 ,
V_9 -> V_27 , V_9 -> V_80 ,
V_9 -> V_81 ) ;
F_7 ( & V_34 -> V_43 ) ;
if ( ! F_64 ( V_157 ) )
F_105 ( V_157 , V_193 ) ;
F_9 ( & V_34 -> V_43 ) ;
}
}
if ( ! F_64 ( V_157 ) )
F_56 ( & V_157 -> V_69 ) ;
}
int F_125 ( struct V_15 * V_87 , struct V_146 * * V_203 ,
int V_204 )
{
struct V_21 * V_34 = F_30 ( V_87 ) ;
struct V_8 * V_9 = V_34 -> V_78 ;
struct V_146 * V_64 ;
struct V_1 * V_2 ;
struct V_156 * V_157 ;
struct V_158 V_159 = { 0 } ;
int V_84 = 0 ;
struct V_21 * V_152 ;
F_36 ( V_34 -> V_79 == F_103 () ) ;
if ( V_9 ) {
V_157 = & V_9 -> V_75 ;
if ( F_25 ( F_64 ( V_157 ) &&
F_2 ( & V_9 -> V_61 ) ) ) {
F_121 ( V_87 , V_34 -> V_77 ) ;
return - V_101 ;
}
if ( ( * V_203 ) -> V_161 . V_32 [ 0 ] == '.' ) {
if ( V_9 -> V_184 ||
V_9 -> V_205 >= V_9 -> V_185 ) {
} else {
if ( ! V_9 -> V_184 )
V_9 -> V_184 = 1 ;
V_9 -> V_205 ++ ;
return - V_101 ;
}
}
V_2 = F_33 ( V_9 , & ( * V_203 ) -> V_161 ) ;
if ( V_2 == NULL || V_204 ) {
F_123 ( V_9 , V_2 ) ;
return V_2 ? 1 : - V_101 ;
}
if ( ! F_3 ( V_2 ) ) {
V_9 -> V_113 = V_2 -> V_39 ;
V_159 = F_126 ( F_127 ( 30 ) , NULL ,
V_206 , NULL ) ;
V_84 = F_106 ( V_9 -> V_74 ,
F_3 ( V_2 ) ||
F_64 ( V_157 ) ,
& V_159 ) ;
if ( V_84 < 0 ) {
F_123 ( V_9 , V_2 ) ;
return - V_101 ;
}
}
if ( V_2 -> V_4 == V_112 &&
V_2 -> V_55 != NULL ) {
struct V_15 * V_15 = V_2 -> V_55 ;
struct V_88 V_89 = { . V_133 = V_134 ,
. V_103 . V_104 . V_105 =
V_2 -> V_92 } ;
T_1 V_207 ;
V_84 = F_77 ( F_78 ( V_87 ) , & V_89 ,
F_79 ( V_15 ) , & V_207 ) ;
if ( V_84 == 1 ) {
if ( ( * V_203 ) -> V_147 == NULL ) {
struct V_146 * V_208 ;
V_208 = F_128 ( V_15 ,
* V_203 ) ;
if ( F_92 ( V_208 ) ) {
F_123 ( V_9 , V_2 ) ;
return F_93 ( V_208 ) ;
}
* V_203 = V_208 ;
} else if ( ( * V_203 ) -> V_147 != V_15 ) {
F_27 ( V_38 ,
L_28
L_29 ,
( * V_203 ) -> V_161 . V_33 ,
( * V_203 ) -> V_161 . V_32 ,
( * V_203 ) -> V_147 -> V_108 ,
( * V_203 ) -> V_147 -> V_109 ,
V_15 -> V_108 ,
V_15 -> V_109 ) ;
F_123 ( V_9 , V_2 ) ;
return - V_118 ;
} else {
F_39 ( V_15 ) ;
}
V_2 -> V_55 = NULL ;
if ( ( V_207 & V_209 ) &&
F_129 ( * V_203 ) )
F_130 ( * V_203 ) ;
F_38 ( & V_89 ) ;
}
}
F_123 ( V_9 , V_2 ) ;
return V_84 ;
}
V_84 = F_122 ( V_87 , * V_203 ) ;
if ( V_84 == V_197 )
GOTO ( V_95 , V_84 = - V_101 ) ;
V_9 = F_57 () ;
if ( V_9 == NULL )
GOTO ( V_95 , V_84 = - V_37 ) ;
V_9 -> V_184 = ( V_84 == V_199 ) ;
V_9 -> V_42 = F_55 ( V_87 ) ;
if ( F_25 ( V_9 -> V_42 == NULL ) ) {
F_131 ( L_30 V_82 L_31 ,
F_65 ( & V_34 -> V_83 ) ) ;
GOTO ( V_95 , V_84 = - V_118 ) ;
}
V_64 = F_132 ( ( * V_203 ) -> V_210 ) ;
if ( F_25 ( V_9 -> V_42 != V_64 -> V_147 ) ) {
struct V_21 * V_211 = F_30 ( V_64 -> V_147 ) ;
F_131 ( L_32
L_33 V_82 L_34 V_82 L_31 ,
( * V_203 ) -> V_161 . V_33 , ( * V_203 ) -> V_161 . V_32 ,
F_65 ( & V_34 -> V_83 ) , F_65 ( & V_211 -> V_83 ) ) ;
F_101 ( V_64 ) ;
F_39 ( V_9 -> V_42 ) ;
GOTO ( V_95 , V_84 = - V_101 ) ;
}
F_27 ( V_38 , L_35 ,
V_9 , V_64 -> V_161 . V_33 , V_64 -> V_161 . V_32 ) ;
F_61 ( V_9 ) ;
V_34 -> V_78 = V_9 ;
V_152 = F_30 ( V_64 -> V_147 ) ;
V_84 = F_93 ( F_108 ( F_110 , V_64 ,
L_36 , V_152 -> V_79 ) ) ;
V_157 = & V_9 -> V_75 ;
if ( F_133 ( V_84 ) ) {
F_109 ( L_37 , V_84 ) ;
F_101 ( V_64 ) ;
V_34 -> V_77 = NULL ;
F_105 ( V_157 , V_165 ) ;
F_105 ( & V_9 -> V_68 , V_165 ) ;
F_62 ( V_9 ) ;
F_62 ( V_9 ) ;
F_36 ( V_34 -> V_78 == NULL ) ;
return - V_101 ;
}
F_106 ( V_157 -> V_69 ,
F_85 ( V_157 ) || F_64 ( V_157 ) ,
& V_159 ) ;
F_62 ( V_9 ) ;
return - V_101 ;
V_95:
if ( V_9 != NULL )
F_40 ( V_9 ) ;
F_7 ( & V_34 -> V_43 ) ;
V_34 -> V_77 = NULL ;
V_34 -> V_79 = 0 ;
F_9 ( & V_34 -> V_43 ) ;
return V_84 ;
}
