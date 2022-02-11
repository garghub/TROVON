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
V_2 = F_24 ( V_35 , V_37 ) ;
if ( F_25 ( ! V_2 ) )
return F_26 ( - V_38 ) ;
F_27 ( V_39 , L_1 ,
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
F_27 ( V_39 , L_2 ,
V_2 -> V_11 . V_33 , V_2 -> V_11 . V_32 , V_2 ,
V_2 -> V_40 ) ;
F_36 ( F_2 ( & V_2 -> V_45 ) ) ;
F_36 ( F_2 ( & V_2 -> V_20 ) ) ;
F_36 ( F_1 ( V_2 ) ) ;
F_37 ( V_9 , V_2 ) ;
F_39 ( V_2 -> V_56 ) ;
F_40 ( V_2 ) ;
F_44 ( & V_9 -> V_24 ) ;
}
}
static inline void
F_45 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_21 * V_34 = F_30 ( V_9 -> V_43 ) ;
F_36 ( ! F_1 ( V_2 ) ) ;
F_36 ( ! F_2 ( & V_2 -> V_45 ) ) ;
F_10 ( V_9 , V_2 ) ;
F_7 ( & V_34 -> V_44 ) ;
V_2 -> V_4 = V_57 ;
F_11 ( & V_2 -> V_45 ) ;
if ( F_46 ( ! F_2 ( & V_2 -> V_20 ) ) )
F_11 ( & V_2 -> V_20 ) ;
F_9 ( & V_34 -> V_44 ) ;
F_42 ( V_9 , V_2 ) ;
}
static void
F_47 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_1 * V_58 , * V_19 ;
if ( V_2 )
F_45 ( V_9 , V_2 ) ;
F_48 (pos, next, &sai->sai_entries, se_link) {
if ( ! F_22 ( V_9 , V_58 -> V_40 ) )
break;
F_45 ( V_9 , V_58 ) ;
}
}
static void
F_49 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_59 )
{
struct V_1 * V_60 ;
struct V_61 * V_58 = & V_9 -> V_62 ;
if ( ! F_2 ( & V_2 -> V_20 ) )
F_11 ( & V_2 -> V_20 ) ;
F_50 (se, &sai->sai_entries_stated, se_list) {
if ( V_60 -> V_40 < V_2 -> V_40 ) {
V_58 = & V_60 -> V_20 ;
break;
}
}
F_51 ( & V_2 -> V_20 , V_58 ) ;
V_2 -> V_4 = V_59 ;
}
static int
F_52 ( struct V_8 * V_9 ,
struct V_1 * V_2 , T_2 V_59 )
{
struct V_21 * V_34 = F_30 ( V_9 -> V_43 ) ;
int V_63 = 1 ;
F_37 ( V_9 , V_2 ) ;
F_7 ( & V_34 -> V_44 ) ;
if ( F_46 ( V_2 -> V_4 != V_57 ) ) {
F_49 ( V_9 , V_2 , V_59 ) ;
V_63 = 0 ;
}
F_9 ( & V_34 -> V_44 ) ;
return V_63 ;
}
static void F_53 ( struct V_8 * V_9 ,
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
F_54 ( V_15 ) ;
F_7 ( & V_65 -> V_67 ) ;
if ( F_20 ( V_9 ) )
V_66 = 1 ;
F_8 ( & V_64 -> V_23 , & V_9 -> V_22 ) ;
F_9 ( & V_65 -> V_67 ) ;
} else {
F_9 ( & V_64 -> V_67 ) ;
}
if ( V_66 > 0 )
F_55 ( & V_9 -> V_69 . V_70 ) ;
}
static struct V_8 * F_56 ( void )
{
struct V_8 * V_9 ;
int V_10 ;
V_9 = F_24 ( sizeof( * V_9 ) , V_37 ) ;
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
F_57 ( & V_9 -> V_75 ) ;
F_57 ( & V_9 -> V_76 . V_70 ) ;
F_57 ( & V_9 -> V_69 . V_70 ) ;
F_31 ( & V_9 -> V_46 ) ;
F_31 ( & V_9 -> V_18 ) ;
F_31 ( & V_9 -> V_62 ) ;
F_31 ( & V_9 -> V_22 ) ;
for ( V_10 = 0 ; V_10 < V_77 ; V_10 ++ ) {
F_31 ( & V_9 -> V_14 [ V_10 ] ) ;
F_58 ( & V_9 -> V_13 [ V_10 ] ) ;
}
F_28 ( & V_9 -> V_24 , 0 ) ;
return V_9 ;
}
static inline struct V_8 *
F_59 ( struct V_8 * V_9 )
{
F_32 ( & V_9 -> V_71 ) ;
return V_9 ;
}
static void F_60 ( struct V_8 * V_9 )
{
struct V_15 * V_15 = V_9 -> V_43 ;
struct V_21 * V_34 = F_30 ( V_15 ) ;
if ( F_61 ( & V_9 -> V_71 , & V_34 -> V_44 ) ) {
struct V_1 * V_2 , * V_19 ;
if ( F_25 ( F_18 ( & V_9 -> V_71 ) > 0 ) ) {
F_9 ( & V_34 -> V_44 ) ;
return;
}
F_36 ( V_34 -> V_78 == NULL ) ;
F_36 ( F_62 ( & V_9 -> V_76 ) ) ;
F_36 ( F_62 ( & V_9 -> V_69 ) ) ;
V_34 -> V_79 = NULL ;
V_34 -> V_80 = 0 ;
F_9 ( & V_34 -> V_44 ) ;
if ( V_9 -> V_81 > V_9 -> V_82 )
F_27 ( V_39 , L_3 V_83
L_4 ,
F_63 ( & V_34 -> V_84 ) ,
V_9 -> V_81 , V_9 -> V_82 ) ;
F_48 (entry, next,
&sai->sai_entries, se_link)
F_45 ( V_9 , V_2 ) ;
F_36 ( F_2 ( & V_9 -> V_46 ) ) ;
F_36 ( F_19 ( V_9 ) ) ;
F_36 ( F_2 ( & V_9 -> V_62 ) ) ;
F_36 ( F_18 ( & V_9 -> V_24 ) == 0 ) ;
F_36 ( F_20 ( V_9 ) ) ;
F_39 ( V_15 ) ;
F_40 ( V_9 ) ;
}
}
static void F_64 ( struct V_15 * V_15 , struct V_8 * V_9 )
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
V_85 = F_65 ( & V_34 -> V_86 ) ;
if ( V_85 == 0 ) {
V_34 -> V_68 = 0 ;
F_39 ( V_15 ) ;
return;
}
if ( V_34 -> V_87 != 0 &&
F_66 ( F_67 ( - 1 ) , V_34 -> V_87 ) ) {
F_68 ( & V_34 -> V_86 ) ;
V_34 -> V_68 = 0 ;
F_39 ( V_15 ) ;
return;
}
F_27 ( V_39 , L_5
V_83 L_6 , F_63 ( & V_34 -> V_84 ) , V_29 ) ;
F_69 ( V_15 ) ;
V_34 -> V_68 = 0 ;
V_34 -> V_87 = F_70 () ;
F_68 ( & V_34 -> V_86 ) ;
F_27 ( V_39 , L_7
V_83 L_8 ,
F_63 ( & V_34 -> V_84 ) , V_29 , V_85 ) ;
F_39 ( V_15 ) ;
}
static void F_71 ( struct V_8 * V_9 )
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
V_92 = F_72 ( & V_52 -> V_94 , & V_95 ) ;
if ( V_92 == NULL ) {
V_85 = - V_96 ;
goto V_97;
}
V_64 = V_2 -> V_56 ;
if ( V_64 == NULL ) {
F_36 ( F_73 ( & V_49 -> V_98 . V_99 ) ) ;
if ( V_92 -> V_100 & V_101 ) {
V_85 = - V_102 ;
goto V_97;
}
} else {
if ( F_25 ( ! F_74 ( & V_49 -> V_98 . V_99 , & V_92 -> V_103 ) ) ) {
V_2 -> V_56 = NULL ;
F_39 ( V_64 ) ;
V_64 = NULL ;
}
}
V_90 -> V_104 . V_105 . V_106 = V_2 -> V_93 ;
V_85 = F_75 ( F_76 ( V_88 ) , V_90 , F_77 ( V_88 ) , NULL ) ;
if ( V_85 != 1 ) {
V_85 = - V_102 ;
goto V_97;
}
V_85 = F_78 ( & V_64 , V_52 , V_88 -> V_107 , V_90 ) ;
if ( V_85 )
goto V_97;
F_27 ( V_108 , L_9 ,
V_64 , V_64 -> V_109 , V_64 -> V_110 ) ;
F_79 ( F_80 ( V_88 ) -> V_111 , V_64 , V_90 , NULL ) ;
V_2 -> V_56 = V_64 ;
if ( F_12 ( V_9 , V_64 ) )
F_53 ( V_9 , V_64 , V_2 -> V_40 ) ;
V_97:
V_85 = F_52 ( V_9 , V_2 ,
V_85 < 0 ? V_112 : V_113 ) ;
if ( V_85 == 0 && V_2 -> V_40 == V_9 -> V_114 )
F_55 ( & V_9 -> V_75 ) ;
F_42 ( V_9 , V_2 ) ;
}
static int F_81 ( struct V_51 * V_52 ,
struct V_48 * V_49 , int V_85 )
{
struct V_89 * V_90 = & V_49 -> V_54 ;
struct V_15 * V_88 = V_49 -> V_55 ;
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_8 * V_9 = NULL ;
struct V_1 * V_2 ;
T_1 V_115 = 0 ;
int V_116 ;
if ( F_82 ( V_90 , V_117 ) )
V_85 = - V_118 ;
if ( V_85 == 0 ) {
V_115 = V_90 -> V_104 . V_105 . V_106 ;
F_83 ( V_90 ) ;
}
F_7 ( & V_34 -> V_44 ) ;
if ( F_25 ( V_34 -> V_79 == NULL ||
V_34 -> V_79 -> V_73 != V_49 -> V_119 ) ) {
F_9 ( & V_34 -> V_44 ) ;
V_85 = - V_120 ;
goto V_97;
} else {
V_9 = F_59 ( V_34 -> V_79 ) ;
if ( F_25 ( ! F_84 ( & V_9 -> V_76 ) ) ) {
V_9 -> V_82 ++ ;
F_9 ( & V_34 -> V_44 ) ;
V_85 = - V_121 ;
goto V_97;
}
V_2 = F_35 ( V_9 , V_49 -> V_122 ) ;
if ( V_2 == NULL ) {
V_9 -> V_82 ++ ;
F_9 ( & V_34 -> V_44 ) ;
V_85 = - V_123 ;
goto V_97;
}
if ( V_85 != 0 ) {
F_49 ( V_9 , V_2 , V_112 ) ;
V_116 = ( V_2 -> V_40 == V_9 -> V_114 ) ;
} else {
V_2 -> V_50 = V_49 ;
V_2 -> V_53 = F_85 ( V_52 ) ;
V_2 -> V_93 = V_115 ;
V_116 = F_19 ( V_9 ) ;
F_8 ( & V_2 -> V_20 ,
& V_9 -> V_18 ) ;
}
V_9 -> V_82 ++ ;
F_9 ( & V_34 -> V_44 ) ;
F_42 ( V_9 , V_2 ) ;
if ( V_116 )
F_55 ( & V_9 -> V_76 . V_70 ) ;
}
V_97:
if ( V_85 != 0 ) {
F_38 ( V_90 ) ;
F_39 ( V_88 ) ;
F_40 ( V_49 ) ;
}
if ( V_9 != NULL )
F_60 ( V_9 ) ;
return V_85 ;
}
static void F_86 ( struct V_48 * V_49 ,
struct V_124 * V_125 )
{
F_36 ( V_49 && V_125 ) ;
F_39 ( V_49 -> V_55 ) ;
F_87 ( V_49 -> V_98 . V_126 ) ;
F_87 ( V_49 -> V_98 . V_127 ) ;
F_40 ( V_49 ) ;
F_40 ( V_125 ) ;
}
static int F_88 ( struct V_15 * V_88 , struct V_15 * V_64 ,
struct V_1 * V_2 , struct V_48 * * V_128 ,
struct V_124 * * V_129 ,
struct V_130 * * V_131 )
{
struct V_47 * V_47 = & V_2 -> V_11 ;
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_48 * V_49 ;
struct V_124 * V_125 ;
struct V_132 * V_133 ;
V_125 = F_24 ( sizeof( * V_125 ) , V_37 ) ;
if ( ! V_125 )
return - V_38 ;
V_49 = F_24 ( sizeof( * V_49 ) , V_37 ) ;
if ( ! V_49 ) {
F_40 ( V_125 ) ;
return - V_38 ;
}
V_133 = F_89 ( & V_49 -> V_98 , V_88 , V_64 , V_47 -> V_32 ,
V_47 -> V_33 , 0 , V_134 , NULL ) ;
if ( F_90 ( V_133 ) ) {
F_40 ( V_125 ) ;
F_40 ( V_49 ) ;
return F_91 ( V_133 ) ;
}
V_49 -> V_54 . V_135 = V_136 ;
V_49 -> V_55 = F_54 ( V_88 ) ;
V_49 -> V_137 = F_81 ;
V_49 -> V_119 = V_34 -> V_79 -> V_73 ;
V_49 -> V_122 = V_2 -> V_40 ;
V_125 -> V_138 = V_139 ;
V_125 -> V_140 = F_92 ( & V_49 -> V_54 ) ;
V_125 -> V_141 = V_142 ;
V_125 -> V_143 = V_144 ;
V_125 -> V_145 = NULL ;
V_125 -> V_146 = NULL ;
* V_128 = V_49 ;
* V_129 = V_125 ;
V_131 [ 0 ] = V_133 -> V_126 ;
V_131 [ 1 ] = V_133 -> V_127 ;
return 0 ;
}
static int F_93 ( struct V_15 * V_88 , struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_124 * V_125 ;
struct V_130 * V_147 [ 2 ] ;
int V_85 ;
V_85 = F_88 ( V_88 , NULL , V_2 , & V_49 , & V_125 , V_147 ) ;
if ( V_85 )
return V_85 ;
V_85 = F_94 ( F_76 ( V_88 ) , V_49 , V_125 ) ;
if ( ! V_85 ) {
F_87 ( V_147 [ 0 ] ) ;
F_87 ( V_147 [ 1 ] ) ;
} else {
F_86 ( V_49 , V_125 ) ;
}
return V_85 ;
}
static int F_95 ( struct V_15 * V_88 , struct V_1 * V_2 ,
struct V_148 * V_148 )
{
struct V_15 * V_15 = F_96 ( V_148 ) ;
struct V_89 V_90 = { . V_135 = V_136 ,
. V_104 . V_105 . V_106 = 0 } ;
struct V_48 * V_49 ;
struct V_124 * V_125 ;
struct V_130 * V_147 [ 2 ] ;
int V_85 ;
if ( F_25 ( V_15 == NULL ) )
return 1 ;
if ( F_97 ( V_148 ) )
return 1 ;
V_2 -> V_56 = F_54 ( V_15 ) ;
V_85 = F_75 ( F_76 ( V_88 ) , & V_90 , F_77 ( V_15 ) ,
NULL ) ;
if ( V_85 == 1 ) {
V_2 -> V_93 = V_90 . V_104 . V_105 . V_106 ;
F_38 ( & V_90 ) ;
return 1 ;
}
V_85 = F_88 ( V_88 , V_15 , V_2 , & V_49 , & V_125 , V_147 ) ;
if ( V_85 ) {
V_2 -> V_56 = NULL ;
F_39 ( V_15 ) ;
return V_85 ;
}
V_85 = F_94 ( F_76 ( V_88 ) , V_49 , V_125 ) ;
if ( ! V_85 ) {
F_87 ( V_147 [ 0 ] ) ;
F_87 ( V_147 [ 1 ] ) ;
} else {
V_2 -> V_56 = NULL ;
F_39 ( V_15 ) ;
F_86 ( V_49 , V_125 ) ;
}
return V_85 ;
}
static void F_98 ( struct V_148 * V_65 , const char * V_149 ,
int V_150 )
{
struct V_15 * V_88 = F_96 ( V_65 ) ;
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_8 * V_9 = V_34 -> V_79 ;
struct V_148 * V_148 = NULL ;
struct V_1 * V_2 ;
int V_85 ;
int V_151 ;
V_2 = F_23 ( V_9 , V_9 -> V_31 , V_149 ,
V_150 ) ;
if ( F_90 ( V_2 ) )
return;
V_148 = F_99 ( V_65 , & V_2 -> V_11 ) ;
if ( ! V_148 ) {
V_85 = F_93 ( V_88 , V_2 ) ;
} else {
V_85 = F_95 ( V_88 , V_2 , V_148 ) ;
if ( V_85 == 1 && F_12 ( V_9 , F_96 ( V_148 ) ) )
F_53 ( V_9 , F_96 ( V_148 ) , V_2 -> V_40 ) ;
}
if ( V_148 != NULL )
F_100 ( V_148 ) ;
if ( V_85 ) {
V_151 = F_52 ( V_9 , V_2 ,
V_85 < 0 ? V_112 : V_113 ) ;
if ( V_151 == 0 && V_2 -> V_40 == V_9 -> V_114 )
F_55 ( & V_9 -> V_75 ) ;
} else {
V_9 -> V_81 ++ ;
}
V_9 -> V_31 ++ ;
F_42 ( V_9 , V_2 ) ;
}
static int F_101 ( void * V_152 )
{
struct V_148 * V_65 = (struct V_148 * ) V_152 ;
struct V_15 * V_88 = F_96 ( V_65 ) ;
struct V_21 * V_153 = F_30 ( V_88 ) ;
struct V_21 * V_154 ;
struct V_155 * V_156 = F_80 ( V_88 ) ;
struct V_8 * V_9 = F_59 ( V_153 -> V_79 ) ;
struct V_157 * V_158 = & V_9 -> V_69 ;
struct V_159 V_160 = { 0 } ;
V_158 -> V_161 = F_102 () ;
F_27 ( V_39 , L_10 ,
V_9 , V_65 ) ;
F_32 ( & V_156 -> V_162 ) ;
F_7 ( & V_153 -> V_67 ) ;
V_9 -> V_17 = 1 ;
if ( F_103 ( V_158 ) )
F_104 ( V_158 , V_163 ) ;
F_9 ( & V_153 -> V_67 ) ;
F_55 ( & V_158 -> V_70 ) ;
while ( 1 ) {
F_105 ( V_158 -> V_70 ,
! F_20 ( V_9 ) ||
! F_84 ( V_158 ) ,
& V_160 ) ;
if ( ! F_84 ( V_158 ) )
break;
F_7 ( & V_153 -> V_67 ) ;
if ( ! F_20 ( V_9 ) ) {
V_154 = F_16 ( V_9 ) ;
F_11 ( & V_154 -> V_23 ) ;
F_9 ( & V_153 -> V_67 ) ;
F_64 ( & V_154 -> V_164 , V_9 ) ;
} else {
F_9 ( & V_153 -> V_67 ) ;
}
}
F_7 ( & V_153 -> V_67 ) ;
V_9 -> V_17 = 0 ;
while ( ! F_20 ( V_9 ) ) {
V_154 = F_16 ( V_9 ) ;
F_11 ( & V_154 -> V_23 ) ;
F_9 ( & V_153 -> V_67 ) ;
V_154 -> V_68 = 0 ;
F_39 ( & V_154 -> V_164 ) ;
F_7 ( & V_153 -> V_67 ) ;
}
F_104 ( V_158 , V_165 ) ;
F_9 ( & V_153 -> V_67 ) ;
F_55 ( & V_158 -> V_70 ) ;
F_60 ( V_9 ) ;
F_27 ( V_39 , L_11 ,
V_9 , V_65 ) ;
return 0 ;
}
static void F_106 ( struct V_148 * V_65 , struct V_8 * V_9 )
{
struct V_157 * V_158 = & V_9 -> V_69 ;
struct V_159 V_160 = { 0 } ;
struct V_21 * V_153 ;
struct V_166 * V_167 ;
F_27 ( V_39 , L_12 ,
V_9 , V_65 ) ;
V_153 = F_30 ( F_96 ( V_65 ) ) ;
V_167 = F_107 ( F_101 , V_65 ,
L_13 , V_153 -> V_80 ) ;
if ( F_90 ( V_167 ) ) {
F_108 ( L_14 , F_91 ( V_167 ) ) ;
F_104 ( V_158 , V_165 ) ;
return;
}
F_105 ( V_158 -> V_70 ,
F_84 ( V_158 ) || F_62 ( V_158 ) ,
& V_160 ) ;
}
static int F_109 ( void * V_152 )
{
struct V_148 * V_65 = (struct V_148 * ) V_152 ;
struct V_15 * V_88 = F_96 ( V_65 ) ;
struct V_21 * V_153 = F_30 ( V_88 ) ;
struct V_21 * V_154 ;
struct V_155 * V_156 = F_80 ( V_88 ) ;
struct V_8 * V_9 = F_59 ( V_153 -> V_79 ) ;
struct V_157 * V_158 = & V_9 -> V_76 ;
struct V_157 * V_168 = & V_9 -> V_69 ;
struct V_169 * V_169 ;
T_1 V_58 = 0 ;
int V_170 = 0 ;
int V_85 = 0 ;
struct V_171 V_172 ;
struct V_159 V_160 = { 0 } ;
V_158 -> V_161 = F_102 () ;
F_27 ( V_39 , L_15 ,
V_9 , V_65 ) ;
if ( V_156 -> V_173 & V_174 )
F_106 ( V_65 , V_9 ) ;
F_32 ( & V_156 -> V_175 ) ;
F_7 ( & V_153 -> V_44 ) ;
if ( F_103 ( V_158 ) )
F_104 ( V_158 , V_163 ) ;
F_9 ( & V_153 -> V_44 ) ;
F_55 ( & V_158 -> V_70 ) ;
F_110 ( & V_172 ) ;
V_169 = F_111 ( V_88 , V_58 , & V_172 ) ;
while ( 1 ) {
struct V_176 * V_177 ;
struct V_178 * V_179 ;
if ( F_90 ( V_169 ) ) {
V_85 = F_91 ( V_169 ) ;
F_27 ( V_39 , L_16 V_83 L_17 ,
F_63 ( F_77 ( V_88 ) ) , V_58 , V_9 -> V_31 ,
V_85 , V_153 -> V_80 ) ;
goto V_97;
}
V_177 = F_112 ( V_169 ) ;
for ( V_179 = F_113 ( V_177 ) ; V_179 != NULL ;
V_179 = F_114 ( V_179 ) ) {
T_1 V_12 ;
int V_180 ;
char * V_32 ;
V_12 = F_115 ( V_179 -> V_181 ) ;
if ( F_25 ( V_12 < V_58 ) )
continue;
V_180 = F_116 ( V_179 -> V_182 ) ;
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
F_105 ( V_158 -> V_70 ,
! F_17 ( V_9 ) ||
! F_19 ( V_9 ) ||
! F_20 ( V_9 ) ||
! F_84 ( V_158 ) ,
& V_160 ) ;
V_187:
while ( ! F_19 ( V_9 ) )
F_71 ( V_9 ) ;
if ( F_25 ( ! F_84 ( V_158 ) ) ) {
F_117 ( V_169 , 0 ) ;
V_85 = 0 ;
goto V_97;
}
if ( F_17 ( V_9 ) ) {
F_7 ( & V_153 -> V_67 ) ;
while ( ! F_20 ( V_9 ) ) {
V_154 = F_16 ( V_9 ) ;
F_11 ( & V_154 -> V_23 ) ;
F_9 ( & V_153 -> V_67 ) ;
F_64 ( & V_154 -> V_164 ,
V_9 ) ;
if ( ! F_19 ( V_9 ) )
goto V_187;
if ( F_25 (
! F_84 ( V_158 ) ) ) {
F_117 ( V_169 , 0 ) ;
V_85 = 0 ;
goto V_97;
}
if ( ! F_17 ( V_9 ) )
goto V_188;
F_7 ( & V_153 -> V_67 ) ;
}
F_9 ( & V_153 -> V_67 ) ;
goto V_186;
}
V_188:
F_98 ( V_65 , V_32 , V_180 ) ;
}
V_58 = F_115 ( V_177 -> V_189 ) ;
if ( V_58 == V_190 ) {
F_117 ( V_169 , 0 ) ;
while ( 1 ) {
F_105 ( V_158 -> V_70 ,
! F_19 ( V_9 ) ||
V_9 -> V_81 == V_9 -> V_82 ||
! F_84 ( V_158 ) ,
& V_160 ) ;
while ( ! F_19 ( V_9 ) )
F_71 ( V_9 ) ;
if ( F_25 ( ! F_84 ( V_158 ) ) ) {
V_85 = 0 ;
goto V_97;
}
if ( V_9 -> V_81 == V_9 -> V_82 &&
F_19 ( V_9 ) )
break;
}
F_7 ( & V_153 -> V_67 ) ;
while ( ! F_20 ( V_9 ) &&
F_84 ( V_158 ) ) {
V_154 = F_16 ( V_9 ) ;
F_11 ( & V_154 -> V_23 ) ;
F_9 ( & V_153 -> V_67 ) ;
F_64 ( & V_154 -> V_164 , V_9 ) ;
F_7 ( & V_153 -> V_67 ) ;
}
F_9 ( & V_153 -> V_67 ) ;
V_85 = 0 ;
goto V_97;
} else if ( 1 ) {
F_117 ( V_169 , F_118 ( V_177 -> V_191 ) &
V_192 ) ;
V_169 = F_111 ( V_88 , V_58 , & V_172 ) ;
} else {
F_36 ( F_118 ( V_177 -> V_191 ) & V_192 ) ;
F_117 ( V_169 , 1 ) ;
}
}
V_97:
if ( V_9 -> V_17 ) {
F_7 ( & V_153 -> V_67 ) ;
F_104 ( V_168 , V_193 ) ;
F_9 ( & V_153 -> V_67 ) ;
F_55 ( & V_168 -> V_70 ) ;
F_27 ( V_39 , L_18 ,
V_9 , ( unsigned int ) V_168 -> V_161 ) ;
F_105 ( V_168 -> V_70 ,
F_62 ( V_168 ) ,
& V_160 ) ;
} else {
F_104 ( & V_9 -> V_69 , V_165 ) ;
}
F_119 ( & V_172 ) ;
F_7 ( & V_153 -> V_44 ) ;
if ( ! F_19 ( V_9 ) ) {
F_104 ( V_158 , V_193 ) ;
F_9 ( & V_153 -> V_44 ) ;
while ( ! F_19 ( V_9 ) )
F_71 ( V_9 ) ;
F_7 ( & V_153 -> V_44 ) ;
}
F_104 ( V_158 , V_165 ) ;
F_9 ( & V_153 -> V_44 ) ;
F_55 ( & V_9 -> V_75 ) ;
F_55 ( & V_158 -> V_70 ) ;
F_60 ( V_9 ) ;
F_100 ( V_65 ) ;
F_27 ( V_39 , L_19 ,
V_9 , V_65 ) ;
return V_85 ;
}
void F_120 ( struct V_15 * V_88 , void * V_194 )
{
struct V_21 * V_34 = F_30 ( V_88 ) ;
if ( F_25 ( V_194 == NULL ) )
return;
F_7 ( & V_34 -> V_44 ) ;
if ( V_34 -> V_78 != V_194 || V_34 -> V_80 == 0 ) {
F_9 ( & V_34 -> V_44 ) ;
return;
}
V_34 -> V_78 = NULL ;
if ( V_34 -> V_79 ) {
struct V_159 V_160 = { 0 } ;
struct V_157 * V_158 = & V_34 -> V_79 -> V_76 ;
if ( ! F_62 ( V_158 ) ) {
F_104 ( V_158 , V_193 ) ;
F_9 ( & V_34 -> V_44 ) ;
F_55 ( & V_158 -> V_70 ) ;
F_27 ( V_39 , L_20 ,
V_34 -> V_79 , ( unsigned int ) V_158 -> V_161 ) ;
F_105 ( V_158 -> V_70 ,
F_62 ( V_158 ) ,
& V_160 ) ;
} else {
F_9 ( & V_34 -> V_44 ) ;
}
F_60 ( V_34 -> V_79 ) ;
} else {
V_34 -> V_80 = 0 ;
F_9 ( & V_34 -> V_44 ) ;
}
}
static int F_121 ( struct V_15 * V_88 , struct V_148 * V_148 )
{
struct V_171 V_172 ;
struct V_47 * V_195 = & V_148 -> V_196 ;
struct V_169 * V_169 ;
T_1 V_58 = 0 ;
int V_197 ;
int V_85 = V_198 ;
F_110 ( & V_172 ) ;
V_169 = F_111 ( V_88 , V_58 , & V_172 ) ;
while ( 1 ) {
struct V_176 * V_177 ;
struct V_178 * V_179 ;
if ( F_90 ( V_169 ) ) {
struct V_21 * V_34 = F_30 ( V_88 ) ;
V_85 = F_91 ( V_169 ) ;
F_108 ( L_16 V_83 L_21 ,
F_63 ( F_77 ( V_88 ) ) , V_58 ,
V_85 , V_34 -> V_80 ) ;
break;
}
V_177 = F_112 ( V_169 ) ;
for ( V_179 = F_113 ( V_177 ) ; V_179 != NULL ;
V_179 = F_114 ( V_179 ) ) {
T_1 V_12 ;
int V_180 ;
char * V_32 ;
V_12 = F_115 ( V_179 -> V_181 ) ;
if ( F_25 ( V_12 < V_58 ) )
continue;
V_180 = F_116 ( V_179 -> V_182 ) ;
if ( F_25 ( V_180 == 0 ) )
continue;
V_32 = V_179 -> V_183 ;
if ( V_32 [ 0 ] == '.' ) {
if ( V_180 == 1 )
continue;
else if ( V_32 [ 1 ] == '.' && V_180 == 2 )
continue;
else
V_197 = 1 ;
} else {
V_197 = 0 ;
}
if ( V_197 && V_195 -> V_32 [ 0 ] != '.' ) {
F_27 ( V_39 , L_22 ,
V_195 -> V_33 , V_195 -> V_32 ,
V_180 , V_32 ) ;
continue;
}
if ( V_195 -> V_33 != V_180 ||
memcmp ( V_195 -> V_32 , V_32 , V_180 ) != 0 )
V_85 = V_198 ;
else if ( ! V_197 )
V_85 = V_199 ;
else
V_85 = V_200 ;
F_117 ( V_169 , 0 ) ;
goto V_97;
}
V_58 = F_115 ( V_177 -> V_189 ) ;
if ( V_58 == V_190 ) {
F_117 ( V_169 , 0 ) ;
break;
} else if ( 1 ) {
F_117 ( V_169 , F_118 ( V_177 -> V_191 ) &
V_192 ) ;
V_169 = F_111 ( V_88 , V_58 , & V_172 ) ;
} else {
F_36 ( F_118 ( V_177 -> V_191 ) & V_192 ) ;
F_117 ( V_169 , 1 ) ;
}
}
V_97:
F_119 ( & V_172 ) ;
return V_85 ;
}
static void
F_122 ( struct V_8 * V_9 , struct V_1 * V_2 )
{
struct V_157 * V_158 = & V_9 -> V_76 ;
struct V_155 * V_156 = F_80 ( V_9 -> V_43 ) ;
int V_201 ;
if ( V_2 != NULL && V_2 -> V_4 == V_113 )
V_201 = 1 ;
else
V_201 = 0 ;
F_47 ( V_9 , V_2 ) ;
if ( V_201 ) {
V_9 -> V_26 ++ ;
V_9 -> V_28 = 0 ;
V_9 -> V_25 = F_123 ( 2 * V_9 -> V_25 , V_156 -> V_202 ) ;
} else {
struct V_21 * V_34 = F_30 ( V_9 -> V_43 ) ;
V_9 -> V_27 ++ ;
V_9 -> V_28 ++ ;
if ( F_21 ( V_9 ) && F_84 ( V_158 ) ) {
F_32 ( & V_156 -> V_203 ) ;
F_27 ( V_39 , L_23 V_83 L_24 ,
F_63 ( & V_34 -> V_84 ) , V_9 -> V_26 ,
V_9 -> V_27 , V_9 -> V_81 ,
V_9 -> V_82 ) ;
F_7 ( & V_34 -> V_44 ) ;
if ( ! F_62 ( V_158 ) )
F_104 ( V_158 , V_193 ) ;
F_9 ( & V_34 -> V_44 ) ;
}
}
if ( ! F_62 ( V_158 ) )
F_55 ( & V_158 -> V_70 ) ;
}
int F_124 ( struct V_15 * V_88 , struct V_148 * * V_204 ,
int V_205 )
{
struct V_21 * V_34 = F_30 ( V_88 ) ;
struct V_8 * V_9 = V_34 -> V_79 ;
struct V_148 * V_65 ;
struct V_1 * V_2 ;
struct V_157 * V_158 ;
struct V_159 V_160 = { 0 } ;
int V_85 = 0 ;
struct V_21 * V_153 ;
F_36 ( V_34 -> V_80 == F_102 () ) ;
if ( V_9 ) {
V_158 = & V_9 -> V_76 ;
if ( F_25 ( F_62 ( V_158 ) &&
F_2 ( & V_9 -> V_62 ) ) ) {
F_120 ( V_88 , V_34 -> V_78 ) ;
return - V_102 ;
}
if ( ( * V_204 ) -> V_196 . V_32 [ 0 ] == '.' ) {
if ( V_9 -> V_184 ||
V_9 -> V_206 >= V_9 -> V_185 ) {
} else {
if ( ! V_9 -> V_184 )
V_9 -> V_184 = 1 ;
V_9 -> V_206 ++ ;
return - V_102 ;
}
}
V_2 = F_33 ( V_9 , & ( * V_204 ) -> V_196 ) ;
if ( V_2 == NULL || V_205 ) {
F_122 ( V_9 , V_2 ) ;
return V_2 ? 1 : - V_102 ;
}
if ( ! F_3 ( V_2 ) ) {
V_9 -> V_114 = V_2 -> V_40 ;
V_160 = F_125 ( F_126 ( 30 ) , NULL ,
V_207 , NULL ) ;
V_85 = F_105 ( V_9 -> V_75 ,
F_3 ( V_2 ) ||
F_62 ( V_158 ) ,
& V_160 ) ;
if ( V_85 < 0 ) {
F_122 ( V_9 , V_2 ) ;
return - V_102 ;
}
}
if ( V_2 -> V_4 == V_113 &&
V_2 -> V_56 != NULL ) {
struct V_15 * V_15 = V_2 -> V_56 ;
struct V_89 V_90 = { . V_135 = V_136 ,
. V_104 . V_105 . V_106 =
V_2 -> V_93 } ;
T_1 V_208 ;
V_85 = F_75 ( F_76 ( V_88 ) , & V_90 ,
F_77 ( V_15 ) , & V_208 ) ;
if ( V_85 == 1 ) {
if ( F_96 ( * V_204 ) == NULL ) {
struct V_148 * V_209 ;
V_209 = F_127 ( V_15 ,
* V_204 ) ;
if ( F_90 ( V_209 ) ) {
F_122 ( V_9 , V_2 ) ;
return F_91 ( V_209 ) ;
}
* V_204 = V_209 ;
} else if ( F_96 ( * V_204 ) != V_15 ) {
F_27 ( V_39 ,
L_25 ,
* V_204 ,
F_96 ( * V_204 ) -> V_109 ,
F_96 ( * V_204 ) -> V_110 ,
V_15 -> V_109 ,
V_15 -> V_110 ) ;
F_122 ( V_9 , V_2 ) ;
return - V_120 ;
} else {
F_39 ( V_15 ) ;
}
V_2 -> V_56 = NULL ;
if ( ( V_208 & V_210 ) &&
F_128 ( * V_204 ) )
F_129 ( * V_204 ) ;
F_38 ( & V_90 ) ;
}
}
F_122 ( V_9 , V_2 ) ;
return V_85 ;
}
V_85 = F_121 ( V_88 , * V_204 ) ;
if ( V_85 == V_198 ) {
V_85 = - V_102 ;
goto V_97;
}
V_9 = F_56 () ;
if ( V_9 == NULL ) {
V_85 = - V_38 ;
goto V_97;
}
V_9 -> V_184 = ( V_85 == V_200 ) ;
V_9 -> V_43 = F_54 ( V_88 ) ;
if ( F_25 ( V_9 -> V_43 == NULL ) ) {
F_130 ( L_26 V_83 L_27 ,
F_63 ( & V_34 -> V_84 ) ) ;
V_85 = - V_120 ;
goto V_97;
}
V_65 = F_131 ( ( * V_204 ) -> V_211 ) ;
if ( F_25 ( V_9 -> V_43 != F_96 ( V_65 ) ) ) {
struct V_21 * V_212 = F_30 ( F_96 ( V_65 ) ) ;
F_130 ( L_28 V_83 L_29 V_83 L_27 ,
* V_204 ,
F_63 ( & V_34 -> V_84 ) , F_63 ( & V_212 -> V_84 ) ) ;
F_100 ( V_65 ) ;
F_39 ( V_9 -> V_43 ) ;
V_85 = - V_102 ;
goto V_97;
}
F_27 ( V_39 , L_30 ,
V_9 , V_65 ) ;
F_59 ( V_9 ) ;
V_34 -> V_79 = V_9 ;
V_153 = F_30 ( F_96 ( V_65 ) ) ;
V_85 = F_91 ( F_107 ( F_109 , V_65 ,
L_31 , V_153 -> V_80 ) ) ;
V_158 = & V_9 -> V_76 ;
if ( F_132 ( V_85 ) ) {
F_108 ( L_32 , V_85 ) ;
F_100 ( V_65 ) ;
V_34 -> V_78 = NULL ;
F_104 ( V_158 , V_165 ) ;
F_104 ( & V_9 -> V_69 , V_165 ) ;
F_60 ( V_9 ) ;
F_60 ( V_9 ) ;
F_36 ( V_34 -> V_79 == NULL ) ;
return - V_102 ;
}
F_105 ( V_158 -> V_70 ,
F_84 ( V_158 ) || F_62 ( V_158 ) ,
& V_160 ) ;
F_60 ( V_9 ) ;
return - V_102 ;
V_97:
F_40 ( V_9 ) ;
F_7 ( & V_34 -> V_44 ) ;
V_34 -> V_78 = NULL ;
V_34 -> V_80 = 0 ;
F_9 ( & V_34 -> V_44 ) ;
return V_85 ;
}
