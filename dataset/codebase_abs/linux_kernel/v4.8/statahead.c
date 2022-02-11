static inline int F_1 ( struct V_1 * V_2 )
{
F_2 () ;
return ( V_2 -> V_3 != V_4 ) ;
}
static inline int F_3 ( int V_5 )
{
return V_5 & V_6 ;
}
static inline void
F_4 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_9 = F_3 ( V_2 -> V_10 . V_11 ) ;
F_5 ( & V_8 -> V_12 [ V_9 ] ) ;
F_6 ( & V_2 -> V_13 , & V_8 -> V_14 [ V_9 ] ) ;
F_7 ( & V_8 -> V_12 [ V_9 ] ) ;
}
static inline void
F_8 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
int V_9 = F_3 ( V_2 -> V_10 . V_11 ) ;
F_5 ( & V_8 -> V_12 [ V_9 ] ) ;
F_9 ( & V_2 -> V_13 ) ;
F_7 ( & V_8 -> V_12 [ V_9 ] ) ;
}
static inline int F_10 ( struct V_7 * V_8 ,
struct V_15 * V_15 )
{
return ( V_15 && F_11 ( V_15 -> V_16 ) && V_8 -> V_17 ) ;
}
static inline int F_12 ( struct V_7 * V_8 )
{
return F_13 ( & V_8 -> V_18 ) >= V_8 -> V_19 ;
}
static inline int F_14 ( struct V_7 * V_8 )
{
return F_15 ( & V_8 -> V_20 ) ;
}
static inline int F_16 ( struct V_7 * V_8 )
{
return F_15 ( & V_8 -> V_21 ) ;
}
static inline int F_17 ( struct V_7 * V_8 )
{
return ( ( V_8 -> V_22 > 7 && V_8 -> V_22 < 4 * V_8 -> V_23 ) ||
( V_8 -> V_24 > 8 ) ) ;
}
static inline int F_18 ( struct V_7 * V_8 , T_1 V_25 )
{
return ( ( T_1 ) V_8 -> V_19 + V_25 + V_26 <
V_8 -> V_27 ) ;
}
static struct V_1 *
F_19 ( struct V_28 * V_29 ,
struct V_7 * V_8 , T_1 V_25 ,
const char * V_30 , int V_31 )
{
struct V_32 * V_33 ;
struct V_1 * V_2 ;
int V_34 ;
char * V_35 ;
V_34 = sizeof( struct V_1 ) + ( V_31 & ~ 3 ) + 4 ;
V_2 = F_20 ( V_34 , V_36 ) ;
if ( F_21 ( ! V_2 ) )
return F_22 ( - V_37 ) ;
F_23 ( V_38 , L_1 ,
V_31 , V_30 , V_2 , V_25 ) ;
V_2 -> V_39 = V_25 ;
F_24 ( & V_2 -> V_40 , 2 ) ;
V_2 -> V_3 = V_4 ;
V_2 -> V_41 = V_34 ;
V_35 = ( char * ) V_2 + sizeof( struct V_1 ) ;
memcpy ( V_35 , V_30 , V_31 ) ;
V_35 [ V_31 ] = 0 ;
V_2 -> V_10 . V_11 = F_25 ( V_29 , V_30 , V_31 ) ;
V_2 -> V_10 . V_31 = V_31 ;
V_2 -> V_10 . V_30 = V_35 ;
V_33 = F_26 ( V_8 -> V_42 ) ;
F_5 ( & V_33 -> V_43 ) ;
F_6 ( & V_2 -> V_44 , & V_8 -> V_45 ) ;
F_27 ( & V_2 -> V_46 ) ;
F_4 ( V_8 , V_2 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_28 ( & V_8 -> V_18 ) ;
return V_2 ;
}
static struct V_1 *
F_29 ( struct V_7 * V_8 , const struct V_47 * V_47 )
{
struct V_1 * V_2 ;
int V_9 = F_3 ( V_47 -> V_11 ) ;
F_30 (entry, &sai->sai_cache[i], se_hash) {
if ( V_2 -> V_10 . V_11 == V_47 -> V_11 &&
V_2 -> V_10 . V_31 == V_47 -> V_31 &&
memcmp ( V_2 -> V_10 . V_30 , V_47 -> V_30 , V_47 -> V_31 ) == 0 )
return V_2 ;
}
return NULL ;
}
static struct V_1 *
F_31 ( struct V_7 * V_8 , T_1 V_25 )
{
struct V_1 * V_2 ;
F_30 (entry, &sai->sai_entries, se_link) {
if ( V_2 -> V_39 == V_25 ) {
F_32 ( F_13 ( & V_2 -> V_40 ) > 0 ) ;
F_28 ( & V_2 -> V_40 ) ;
return V_2 ;
}
if ( V_2 -> V_39 > V_25 )
break;
}
return NULL ;
}
static void F_33 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_48 * V_49 = V_2 -> V_50 ;
struct V_51 * V_52 = V_2 -> V_53 ;
if ( V_49 ) {
V_2 -> V_50 = NULL ;
F_34 ( & V_49 -> V_54 ) ;
F_35 ( V_49 -> V_55 ) ;
F_36 ( V_49 ) ;
}
if ( V_52 ) {
V_2 -> V_53 = NULL ;
F_37 ( V_52 ) ;
}
}
static void F_38 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
if ( F_39 ( & V_2 -> V_40 ) ) {
F_23 ( V_38 , L_2 ,
V_2 -> V_10 . V_31 , V_2 -> V_10 . V_30 , V_2 ,
V_2 -> V_39 ) ;
F_32 ( F_15 ( & V_2 -> V_44 ) ) ;
F_32 ( F_15 ( & V_2 -> V_46 ) ) ;
F_32 ( F_15 ( & V_2 -> V_13 ) ) ;
F_33 ( V_8 , V_2 ) ;
F_35 ( V_2 -> V_56 ) ;
F_36 ( V_2 ) ;
F_40 ( & V_8 -> V_18 ) ;
}
}
static inline void
F_41 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_32 * V_33 = F_26 ( V_8 -> V_42 ) ;
F_32 ( ! F_15 ( & V_2 -> V_13 ) ) ;
F_32 ( ! F_15 ( & V_2 -> V_44 ) ) ;
F_8 ( V_8 , V_2 ) ;
F_5 ( & V_33 -> V_43 ) ;
V_2 -> V_3 = V_57 ;
F_9 ( & V_2 -> V_44 ) ;
if ( F_42 ( ! F_15 ( & V_2 -> V_46 ) ) )
F_9 ( & V_2 -> V_46 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_38 ( V_8 , V_2 ) ;
}
static void
F_43 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_1 * V_58 , * V_59 ;
if ( V_2 )
F_41 ( V_8 , V_2 ) ;
F_44 (pos, next, &sai->sai_entries, se_link) {
if ( ! F_18 ( V_8 , V_58 -> V_39 ) )
break;
F_41 ( V_8 , V_58 ) ;
}
}
static void
F_45 ( struct V_7 * V_8 ,
struct V_1 * V_2 , enum V_3 V_60 )
{
struct V_1 * V_61 ;
struct V_62 * V_58 = & V_8 -> V_63 ;
if ( ! F_15 ( & V_2 -> V_46 ) )
F_9 ( & V_2 -> V_46 ) ;
F_46 (se, &sai->sai_entries_stated, se_list) {
if ( V_61 -> V_39 < V_2 -> V_39 ) {
V_58 = & V_61 -> V_46 ;
break;
}
}
F_47 ( & V_2 -> V_46 , V_58 ) ;
V_2 -> V_3 = V_60 ;
}
static int
F_48 ( struct V_7 * V_8 ,
struct V_1 * V_2 , enum V_3 V_60 )
{
struct V_32 * V_33 = F_26 ( V_8 -> V_42 ) ;
int V_64 = 1 ;
F_33 ( V_8 , V_2 ) ;
F_5 ( & V_33 -> V_43 ) ;
if ( F_42 ( V_2 -> V_3 != V_57 ) ) {
F_45 ( V_8 , V_2 , V_60 ) ;
V_64 = 0 ;
}
F_7 ( & V_33 -> V_43 ) ;
return V_64 ;
}
static void F_49 ( struct V_7 * V_8 ,
struct V_15 * V_15 , int V_25 )
{
struct V_32 * V_65 = F_26 ( V_15 ) ;
struct V_32 * V_29 = F_26 ( V_8 -> V_42 ) ;
int V_66 = 0 ;
F_5 ( & V_65 -> V_67 ) ;
if ( V_65 -> V_68 == 0 ) {
V_65 -> V_68 = V_25 ;
F_7 ( & V_65 -> V_67 ) ;
F_32 ( F_15 ( & V_65 -> V_69 ) ) ;
F_50 ( V_15 ) ;
F_5 ( & V_29 -> V_67 ) ;
if ( F_15 ( & V_8 -> V_21 ) )
V_66 = 1 ;
F_6 ( & V_65 -> V_69 , & V_8 -> V_21 ) ;
F_7 ( & V_29 -> V_67 ) ;
} else {
F_7 ( & V_65 -> V_67 ) ;
}
if ( V_66 > 0 )
F_51 ( & V_8 -> V_70 . V_71 ) ;
}
static struct V_7 * F_52 ( void )
{
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_20 ( sizeof( * V_8 ) , V_36 ) ;
if ( ! V_8 )
return NULL ;
F_24 ( & V_8 -> V_72 , 1 ) ;
F_5 ( & V_73 ) ;
V_8 -> V_74 = ++ V_74 ;
if ( F_21 ( V_74 == 0 ) )
V_8 -> V_74 = ++ V_74 ;
F_7 ( & V_73 ) ;
V_8 -> V_19 = V_75 ;
V_8 -> V_27 = 1 ;
F_53 ( & V_8 -> V_76 ) ;
F_53 ( & V_8 -> V_77 . V_71 ) ;
F_53 ( & V_8 -> V_70 . V_71 ) ;
F_27 ( & V_8 -> V_45 ) ;
F_27 ( & V_8 -> V_20 ) ;
F_27 ( & V_8 -> V_63 ) ;
F_27 ( & V_8 -> V_21 ) ;
for ( V_9 = 0 ; V_9 < V_78 ; V_9 ++ ) {
F_27 ( & V_8 -> V_14 [ V_9 ] ) ;
F_54 ( & V_8 -> V_12 [ V_9 ] ) ;
}
F_24 ( & V_8 -> V_18 , 0 ) ;
return V_8 ;
}
static inline struct V_7 *
F_55 ( struct V_7 * V_8 )
{
F_28 ( & V_8 -> V_72 ) ;
return V_8 ;
}
static void F_56 ( struct V_7 * V_8 )
{
struct V_15 * V_15 = V_8 -> V_42 ;
struct V_32 * V_33 = F_26 ( V_15 ) ;
if ( F_57 ( & V_8 -> V_72 , & V_33 -> V_43 ) ) {
struct V_1 * V_2 , * V_59 ;
if ( F_21 ( F_13 ( & V_8 -> V_72 ) > 0 ) ) {
F_7 ( & V_33 -> V_43 ) ;
return;
}
F_32 ( ! V_33 -> V_79 ) ;
F_32 ( F_58 ( & V_8 -> V_77 ) ) ;
F_32 ( F_58 ( & V_8 -> V_70 ) ) ;
V_33 -> V_80 = NULL ;
V_33 -> V_81 = 0 ;
F_7 ( & V_33 -> V_43 ) ;
if ( V_8 -> V_82 > V_8 -> V_83 )
F_23 ( V_38 , L_3 V_84
L_4 ,
F_59 ( & V_33 -> V_85 ) ,
V_8 -> V_82 , V_8 -> V_83 ) ;
F_44 (entry, next, &sai->sai_entries,
se_link)
F_41 ( V_8 , V_2 ) ;
F_32 ( F_15 ( & V_8 -> V_45 ) ) ;
F_32 ( F_15 ( & V_8 -> V_20 ) ) ;
F_32 ( F_15 ( & V_8 -> V_63 ) ) ;
F_32 ( F_13 ( & V_8 -> V_18 ) == 0 ) ;
F_32 ( F_15 ( & V_8 -> V_21 ) ) ;
F_35 ( V_15 ) ;
F_36 ( V_8 ) ;
}
}
static void F_60 ( struct V_15 * V_15 , struct V_7 * V_8 )
{
struct V_32 * V_33 = F_26 ( V_15 ) ;
T_1 V_25 = V_33 -> V_68 ;
int V_86 ;
F_32 ( F_15 ( & V_33 -> V_69 ) ) ;
if ( F_18 ( V_8 , V_25 + 1 ) ) {
V_33 -> V_68 = 0 ;
F_35 ( V_15 ) ;
return;
}
V_86 = F_61 ( & V_33 -> V_87 ) ;
if ( V_86 == 0 ) {
V_33 -> V_68 = 0 ;
F_35 ( V_15 ) ;
return;
}
if ( V_33 -> V_88 != 0 &&
F_62 ( F_63 ( - 1 ) , V_33 -> V_88 ) ) {
F_64 ( & V_33 -> V_87 ) ;
V_33 -> V_68 = 0 ;
F_35 ( V_15 ) ;
return;
}
F_23 ( V_38 , L_5
V_84 L_6 , F_59 ( & V_33 -> V_85 ) , V_25 ) ;
F_65 ( V_15 ) ;
V_33 -> V_68 = 0 ;
V_33 -> V_88 = F_66 () ;
F_64 ( & V_33 -> V_87 ) ;
F_23 ( V_38 , L_7
V_84 L_8 ,
F_59 ( & V_33 -> V_85 ) , V_25 , V_86 ) ;
F_35 ( V_15 ) ;
}
static void F_67 ( struct V_7 * V_8 )
{
struct V_15 * V_89 = V_8 -> V_42 ;
struct V_15 * V_65 ;
struct V_32 * V_33 = F_26 ( V_89 ) ;
struct V_1 * V_2 ;
struct V_48 * V_49 ;
struct V_90 * V_91 ;
struct V_51 * V_52 ;
struct V_92 * V_93 ;
int V_86 = 0 ;
F_5 ( & V_33 -> V_43 ) ;
if ( F_21 ( F_15 ( & V_8 -> V_20 ) ) ) {
F_7 ( & V_33 -> V_43 ) ;
return;
}
V_2 = F_68 ( V_8 -> V_20 . V_59 ,
struct V_1 , V_46 ) ;
F_28 ( & V_2 -> V_40 ) ;
F_9 ( & V_2 -> V_46 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_32 ( V_2 -> V_94 != 0 ) ;
V_49 = V_2 -> V_50 ;
V_91 = & V_49 -> V_54 ;
V_52 = V_2 -> V_53 ;
V_93 = F_69 ( & V_52 -> V_95 , & V_96 ) ;
if ( ! V_93 ) {
V_86 = - V_97 ;
goto V_98;
}
V_65 = V_2 -> V_56 ;
if ( ! V_65 ) {
F_32 ( F_70 ( & V_49 -> V_99 . V_100 ) ) ;
if ( V_93 -> V_101 & V_102 ) {
V_86 = - V_103 ;
goto V_98;
}
} else {
if ( F_21 ( ! F_71 ( & V_49 -> V_99 . V_100 , & V_93 -> V_104 ) ) ) {
V_2 -> V_56 = NULL ;
F_35 ( V_65 ) ;
V_65 = NULL ;
}
}
V_91 -> V_105 = V_2 -> V_94 ;
V_86 = F_72 ( F_73 ( V_89 ) , V_91 , F_74 ( V_89 ) , NULL ) ;
if ( V_86 != 1 ) {
V_86 = - V_103 ;
goto V_98;
}
V_86 = F_75 ( & V_65 , V_52 , V_89 -> V_106 , V_91 ) ;
if ( V_86 )
goto V_98;
F_23 ( V_107 , L_9 V_84 L_10 ,
F_76 ( V_65 -> V_106 , NULL , 0 ) ,
F_59 ( F_74 ( V_65 ) ) , V_65 ) ;
F_77 ( F_78 ( V_89 ) -> V_108 , V_65 , V_91 , NULL ) ;
V_2 -> V_56 = V_65 ;
if ( F_10 ( V_8 , V_65 ) )
F_49 ( V_8 , V_65 , V_2 -> V_39 ) ;
V_98:
V_86 = F_48 ( V_8 , V_2 ,
V_86 < 0 ? V_109 : V_110 ) ;
if ( V_86 == 0 && V_2 -> V_39 == V_8 -> V_111 )
F_51 ( & V_8 -> V_76 ) ;
F_38 ( V_8 , V_2 ) ;
}
static int F_79 ( struct V_51 * V_52 ,
struct V_48 * V_49 , int V_86 )
{
struct V_90 * V_91 = & V_49 -> V_54 ;
struct V_15 * V_89 = V_49 -> V_55 ;
struct V_32 * V_33 = F_26 ( V_89 ) ;
struct V_7 * V_8 = NULL ;
struct V_1 * V_2 ;
T_1 V_112 = 0 ;
int V_113 ;
if ( F_80 ( V_91 , V_114 ) )
V_86 = - V_115 ;
if ( V_86 == 0 ) {
V_112 = V_91 -> V_105 ;
F_81 ( V_91 ) ;
}
F_5 ( & V_33 -> V_43 ) ;
if ( F_21 ( ! V_33 -> V_80 ||
V_33 -> V_80 -> V_74 != V_49 -> V_116 ) ) {
F_7 ( & V_33 -> V_43 ) ;
V_86 = - V_117 ;
goto V_98;
} else {
V_8 = F_55 ( V_33 -> V_80 ) ;
if ( F_21 ( ! F_82 ( & V_8 -> V_77 ) ) ) {
V_8 -> V_83 ++ ;
F_7 ( & V_33 -> V_43 ) ;
V_86 = - V_118 ;
goto V_98;
}
V_2 = F_31 ( V_8 , V_49 -> V_119 ) ;
if ( ! V_2 ) {
V_8 -> V_83 ++ ;
F_7 ( & V_33 -> V_43 ) ;
V_86 = - V_120 ;
goto V_98;
}
if ( V_86 != 0 ) {
F_45 ( V_8 , V_2 , V_109 ) ;
V_113 = ( V_2 -> V_39 == V_8 -> V_111 ) ;
} else {
V_2 -> V_50 = V_49 ;
V_2 -> V_53 = F_83 ( V_52 ) ;
V_2 -> V_94 = V_112 ;
V_113 = F_15 ( & V_8 -> V_20 ) ;
F_6 ( & V_2 -> V_46 ,
& V_8 -> V_20 ) ;
}
V_8 -> V_83 ++ ;
F_7 ( & V_33 -> V_43 ) ;
F_38 ( V_8 , V_2 ) ;
if ( V_113 )
F_51 ( & V_8 -> V_77 . V_71 ) ;
}
V_98:
if ( V_86 != 0 ) {
F_34 ( V_91 ) ;
F_35 ( V_89 ) ;
F_36 ( V_49 ) ;
}
if ( V_8 )
F_56 ( V_8 ) ;
return V_86 ;
}
static void F_84 ( struct V_48 * V_49 ,
struct V_121 * V_122 )
{
F_32 ( V_49 && V_122 ) ;
F_35 ( V_49 -> V_55 ) ;
F_36 ( V_49 ) ;
F_36 ( V_122 ) ;
}
static int F_85 ( struct V_15 * V_89 , struct V_15 * V_65 ,
struct V_1 * V_2 , struct V_48 * * V_123 ,
struct V_121 * * V_124 )
{
const struct V_47 * V_47 = & V_2 -> V_10 ;
struct V_32 * V_33 = F_26 ( V_89 ) ;
struct V_48 * V_49 ;
struct V_121 * V_122 ;
struct V_125 * V_126 ;
V_122 = F_20 ( sizeof( * V_122 ) , V_36 ) ;
if ( ! V_122 )
return - V_37 ;
V_49 = F_20 ( sizeof( * V_49 ) , V_36 ) ;
if ( ! V_49 ) {
F_36 ( V_122 ) ;
return - V_37 ;
}
V_126 = F_86 ( & V_49 -> V_99 , V_89 , V_65 , V_47 -> V_30 ,
V_47 -> V_31 , 0 , V_127 , NULL ) ;
if ( F_87 ( V_126 ) ) {
F_36 ( V_122 ) ;
F_36 ( V_49 ) ;
return F_88 ( V_126 ) ;
}
V_49 -> V_54 . V_128 = V_129 ;
V_49 -> V_55 = F_50 ( V_89 ) ;
V_49 -> V_130 = F_79 ;
V_49 -> V_116 = V_33 -> V_80 -> V_74 ;
V_49 -> V_119 = V_2 -> V_39 ;
V_122 -> V_131 = V_132 ;
V_122 -> V_133 = F_89 ( & V_49 -> V_54 ) ;
V_122 -> V_134 = V_135 ;
V_122 -> V_136 = V_137 ;
V_122 -> V_138 = NULL ;
V_122 -> V_139 = NULL ;
* V_123 = V_49 ;
* V_124 = V_122 ;
return 0 ;
}
static int F_90 ( struct V_15 * V_89 , struct V_1 * V_2 )
{
struct V_48 * V_49 ;
struct V_121 * V_122 ;
int V_86 ;
V_86 = F_85 ( V_89 , NULL , V_2 , & V_49 , & V_122 ) ;
if ( V_86 )
return V_86 ;
V_86 = F_91 ( F_73 ( V_89 ) , V_49 , V_122 ) ;
if ( V_86 < 0 )
F_84 ( V_49 , V_122 ) ;
return V_86 ;
}
static int F_92 ( struct V_15 * V_89 , struct V_1 * V_2 ,
struct V_28 * V_28 )
{
struct V_15 * V_15 = F_93 ( V_28 ) ;
struct V_90 V_91 = { . V_128 = V_129 ,
. V_105 = 0 } ;
struct V_48 * V_49 ;
struct V_121 * V_122 ;
int V_86 ;
if ( F_21 ( ! V_15 ) )
return 1 ;
if ( F_94 ( V_28 ) )
return 1 ;
V_2 -> V_56 = F_50 ( V_15 ) ;
V_86 = F_72 ( F_73 ( V_89 ) , & V_91 , F_74 ( V_15 ) ,
NULL ) ;
if ( V_86 == 1 ) {
V_2 -> V_94 = V_91 . V_105 ;
F_34 ( & V_91 ) ;
return 1 ;
}
V_86 = F_85 ( V_89 , V_15 , V_2 , & V_49 , & V_122 ) ;
if ( V_86 ) {
V_2 -> V_56 = NULL ;
F_35 ( V_15 ) ;
return V_86 ;
}
V_86 = F_91 ( F_73 ( V_89 ) , V_49 , V_122 ) ;
if ( V_86 < 0 ) {
V_2 -> V_56 = NULL ;
F_35 ( V_15 ) ;
F_84 ( V_49 , V_122 ) ;
}
return V_86 ;
}
static void F_95 ( struct V_28 * V_29 , const char * V_140 ,
int V_141 )
{
struct V_15 * V_89 = F_93 ( V_29 ) ;
struct V_32 * V_33 = F_26 ( V_89 ) ;
struct V_7 * V_8 = V_33 -> V_80 ;
struct V_28 * V_28 = NULL ;
struct V_1 * V_2 ;
int V_86 ;
int V_142 ;
V_2 = F_19 ( V_29 , V_8 , V_8 -> V_27 , V_140 ,
V_141 ) ;
if ( F_87 ( V_2 ) )
return;
V_28 = F_96 ( V_29 , & V_2 -> V_10 ) ;
if ( ! V_28 ) {
V_86 = F_90 ( V_89 , V_2 ) ;
} else {
V_86 = F_92 ( V_89 , V_2 , V_28 ) ;
if ( V_86 == 1 && F_10 ( V_8 , F_93 ( V_28 ) ) )
F_49 ( V_8 , F_93 ( V_28 ) , V_2 -> V_39 ) ;
F_97 ( V_28 ) ;
}
if ( V_86 ) {
V_142 = F_48 ( V_8 , V_2 ,
V_86 < 0 ? V_109 : V_110 ) ;
if ( V_142 == 0 && V_2 -> V_39 == V_8 -> V_111 )
F_51 ( & V_8 -> V_76 ) ;
} else {
V_8 -> V_82 ++ ;
}
V_8 -> V_27 ++ ;
F_38 ( V_8 , V_2 ) ;
}
static int F_98 ( void * V_143 )
{
struct V_28 * V_29 = V_143 ;
struct V_15 * V_89 = F_93 ( V_29 ) ;
struct V_32 * V_144 = F_26 ( V_89 ) ;
struct V_32 * V_145 ;
struct V_146 * V_147 = F_78 ( V_89 ) ;
struct V_7 * V_8 = F_55 ( V_144 -> V_80 ) ;
struct V_148 * V_149 = & V_8 -> V_70 ;
struct V_150 V_151 = { 0 } ;
V_149 -> V_152 = F_99 () ;
F_23 ( V_38 , L_11 ,
V_8 , V_29 ) ;
F_28 ( & V_147 -> V_153 ) ;
F_5 ( & V_144 -> V_67 ) ;
V_8 -> V_17 = 1 ;
if ( F_100 ( V_149 ) )
F_101 ( V_149 , V_154 ) ;
F_7 ( & V_144 -> V_67 ) ;
F_51 ( & V_149 -> V_71 ) ;
while ( 1 ) {
F_102 ( V_149 -> V_71 ,
! F_15 ( & V_8 -> V_21 ) ||
! F_82 ( V_149 ) ,
& V_151 ) ;
if ( ! F_82 ( V_149 ) )
break;
F_5 ( & V_144 -> V_67 ) ;
if ( ! F_15 ( & V_8 -> V_21 ) ) {
V_145 = F_68 ( V_8 -> V_21 . V_59 ,
struct V_32 , V_69 ) ;
F_9 ( & V_145 -> V_69 ) ;
F_7 ( & V_144 -> V_67 ) ;
F_60 ( & V_145 -> V_155 , V_8 ) ;
} else {
F_7 ( & V_144 -> V_67 ) ;
}
}
F_5 ( & V_144 -> V_67 ) ;
V_8 -> V_17 = 0 ;
while ( ! F_15 ( & V_8 -> V_21 ) ) {
V_145 = F_68 ( V_8 -> V_21 . V_59 ,
struct V_32 , V_69 ) ;
F_9 ( & V_145 -> V_69 ) ;
F_7 ( & V_144 -> V_67 ) ;
V_145 -> V_68 = 0 ;
F_35 ( & V_145 -> V_155 ) ;
F_5 ( & V_144 -> V_67 ) ;
}
F_101 ( V_149 , V_156 ) ;
F_7 ( & V_144 -> V_67 ) ;
F_51 ( & V_149 -> V_71 ) ;
F_56 ( V_8 ) ;
F_23 ( V_38 , L_12 ,
V_8 , V_29 ) ;
return 0 ;
}
static void F_103 ( struct V_28 * V_29 , struct V_7 * V_8 )
{
struct V_148 * V_149 = & V_8 -> V_70 ;
struct V_150 V_151 = { 0 } ;
struct V_32 * V_144 ;
struct V_157 * V_158 ;
F_23 ( V_38 , L_13 ,
V_8 , V_29 ) ;
V_144 = F_26 ( F_93 ( V_29 ) ) ;
V_158 = F_104 ( F_98 , V_29 , L_14 ,
V_144 -> V_81 ) ;
if ( F_87 ( V_158 ) ) {
F_105 ( L_15 , F_88 ( V_158 ) ) ;
F_101 ( V_149 , V_156 ) ;
return;
}
F_102 ( V_149 -> V_71 ,
F_82 ( V_149 ) || F_58 ( V_149 ) ,
& V_151 ) ;
}
static int F_106 ( void * V_143 )
{
struct V_28 * V_29 = V_143 ;
struct V_15 * V_89 = F_93 ( V_29 ) ;
struct V_32 * V_144 = F_26 ( V_89 ) ;
struct V_32 * V_145 ;
struct V_146 * V_147 = F_78 ( V_89 ) ;
struct V_7 * V_8 = F_55 ( V_144 -> V_80 ) ;
struct V_148 * V_149 = & V_8 -> V_77 ;
struct V_148 * V_159 = & V_8 -> V_70 ;
struct V_160 * V_160 ;
T_1 V_58 = 0 ;
int V_161 = 0 ;
int V_86 = 0 ;
struct V_162 V_163 ;
struct V_150 V_151 = { 0 } ;
V_149 -> V_152 = F_99 () ;
F_23 ( V_38 , L_16 ,
V_8 , V_29 ) ;
if ( V_147 -> V_164 & V_165 )
F_103 ( V_29 , V_8 ) ;
F_28 ( & V_147 -> V_166 ) ;
F_5 ( & V_144 -> V_43 ) ;
if ( F_100 ( V_149 ) )
F_101 ( V_149 , V_154 ) ;
F_7 ( & V_144 -> V_43 ) ;
F_51 ( & V_149 -> V_71 ) ;
F_107 ( & V_163 ) ;
V_160 = F_108 ( V_89 , V_58 , & V_163 ) ;
while ( 1 ) {
struct V_167 * V_168 ;
struct V_169 * V_170 ;
if ( F_87 ( V_160 ) ) {
V_86 = F_88 ( V_160 ) ;
F_23 ( V_38 , L_17 V_84 L_18 ,
F_59 ( F_74 ( V_89 ) ) , V_58 , V_8 -> V_27 ,
V_86 , V_144 -> V_81 ) ;
goto V_98;
}
V_168 = F_109 ( V_160 ) ;
for ( V_170 = F_110 ( V_168 ) ; V_170 ;
V_170 = F_111 ( V_170 ) ) {
T_1 V_11 ;
int V_171 ;
char * V_30 ;
V_11 = F_112 ( V_170 -> V_172 ) ;
if ( F_21 ( V_11 < V_58 ) )
continue;
V_171 = F_113 ( V_170 -> V_173 ) ;
if ( F_21 ( V_171 == 0 ) )
continue;
V_30 = V_170 -> V_174 ;
if ( V_30 [ 0 ] == '.' ) {
if ( V_171 == 1 ) {
continue;
} else if ( V_30 [ 1 ] == '.' && V_171 == 2 ) {
continue;
} else if ( ! V_8 -> V_175 ) {
V_8 -> V_176 ++ ;
continue;
}
}
if ( F_21 ( ++ V_161 == 1 ) )
continue;
V_177:
F_102 ( V_149 -> V_71 ,
! F_12 ( V_8 ) ||
! F_15 ( & V_8 -> V_20 ) ||
! F_15 ( & V_8 -> V_21 ) ||
! F_82 ( V_149 ) ,
& V_151 ) ;
V_178:
while ( ! F_15 ( & V_8 -> V_20 ) )
F_67 ( V_8 ) ;
if ( F_21 ( ! F_82 ( V_149 ) ) ) {
F_114 ( V_160 , 0 ) ;
V_86 = 0 ;
goto V_98;
}
if ( F_12 ( V_8 ) ) {
F_5 ( & V_144 -> V_67 ) ;
while ( ! F_15 ( & V_8 -> V_21 ) ) {
V_145 = F_68 ( V_8 -> V_21 . V_59 ,
struct V_32 , V_69 ) ;
F_9 ( & V_145 -> V_69 ) ;
F_7 ( & V_144 -> V_67 ) ;
F_60 ( & V_145 -> V_155 ,
V_8 ) ;
if ( ! F_15 ( & V_8 -> V_20 ) )
goto V_178;
if ( F_21 (
! F_82 ( V_149 ) ) ) {
F_114 ( V_160 , 0 ) ;
V_86 = 0 ;
goto V_98;
}
if ( ! F_12 ( V_8 ) )
goto V_179;
F_5 ( & V_144 -> V_67 ) ;
}
F_7 ( & V_144 -> V_67 ) ;
goto V_177;
}
V_179:
F_95 ( V_29 , V_30 , V_171 ) ;
}
V_58 = F_112 ( V_168 -> V_180 ) ;
if ( V_58 == V_181 ) {
F_114 ( V_160 , 0 ) ;
while ( 1 ) {
F_102 ( V_149 -> V_71 ,
! F_15 ( & V_8 -> V_20 ) ||
V_8 -> V_82 == V_8 -> V_83 ||
! F_82 ( V_149 ) ,
& V_151 ) ;
while ( ! F_15 ( & V_8 -> V_20 ) )
F_67 ( V_8 ) ;
if ( F_21 ( ! F_82 ( V_149 ) ) ) {
V_86 = 0 ;
goto V_98;
}
if ( V_8 -> V_82 == V_8 -> V_83 &&
F_15 ( & V_8 -> V_20 ) )
break;
}
F_5 ( & V_144 -> V_67 ) ;
while ( ! F_15 ( & V_8 -> V_21 ) &&
F_82 ( V_149 ) ) {
V_145 = F_68 ( V_8 -> V_21 . V_59 ,
struct V_32 , V_69 ) ;
F_9 ( & V_145 -> V_69 ) ;
F_7 ( & V_144 -> V_67 ) ;
F_60 ( & V_145 -> V_155 , V_8 ) ;
F_5 ( & V_144 -> V_67 ) ;
}
F_7 ( & V_144 -> V_67 ) ;
V_86 = 0 ;
goto V_98;
} else if ( 1 ) {
F_114 ( V_160 , F_115 ( V_168 -> V_182 ) &
V_183 ) ;
V_160 = F_108 ( V_89 , V_58 , & V_163 ) ;
} else {
F_32 ( F_115 ( V_168 -> V_182 ) & V_183 ) ;
F_114 ( V_160 , 1 ) ;
}
}
V_98:
if ( V_8 -> V_17 ) {
F_5 ( & V_144 -> V_67 ) ;
F_101 ( V_159 , V_184 ) ;
F_7 ( & V_144 -> V_67 ) ;
F_51 ( & V_159 -> V_71 ) ;
F_23 ( V_38 , L_19 ,
V_8 , ( unsigned int ) V_159 -> V_152 ) ;
F_102 ( V_159 -> V_71 ,
F_58 ( V_159 ) ,
& V_151 ) ;
} else {
F_101 ( & V_8 -> V_70 , V_156 ) ;
}
F_116 ( & V_163 ) ;
F_5 ( & V_144 -> V_43 ) ;
if ( ! F_15 ( & V_8 -> V_20 ) ) {
F_101 ( V_149 , V_184 ) ;
F_7 ( & V_144 -> V_43 ) ;
while ( ! F_15 ( & V_8 -> V_20 ) )
F_67 ( V_8 ) ;
F_5 ( & V_144 -> V_43 ) ;
}
F_101 ( V_149 , V_156 ) ;
F_7 ( & V_144 -> V_43 ) ;
F_51 ( & V_8 -> V_76 ) ;
F_51 ( & V_149 -> V_71 ) ;
F_56 ( V_8 ) ;
F_97 ( V_29 ) ;
F_23 ( V_38 , L_20 ,
V_8 , V_29 ) ;
return V_86 ;
}
void F_117 ( struct V_15 * V_89 , void * V_185 )
{
struct V_32 * V_33 = F_26 ( V_89 ) ;
if ( F_21 ( ! V_185 ) )
return;
F_5 ( & V_33 -> V_43 ) ;
if ( V_33 -> V_79 != V_185 || V_33 -> V_81 == 0 ) {
F_7 ( & V_33 -> V_43 ) ;
return;
}
V_33 -> V_79 = NULL ;
if ( V_33 -> V_80 ) {
struct V_150 V_151 = { 0 } ;
struct V_148 * V_149 = & V_33 -> V_80 -> V_77 ;
if ( ! F_58 ( V_149 ) ) {
F_101 ( V_149 , V_184 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_51 ( & V_149 -> V_71 ) ;
F_23 ( V_38 , L_21 ,
V_33 -> V_80 , ( unsigned int ) V_149 -> V_152 ) ;
F_102 ( V_149 -> V_71 ,
F_58 ( V_149 ) ,
& V_151 ) ;
} else {
F_7 ( & V_33 -> V_43 ) ;
}
F_56 ( V_33 -> V_80 ) ;
} else {
V_33 -> V_81 = 0 ;
F_7 ( & V_33 -> V_43 ) ;
}
}
static int F_118 ( struct V_15 * V_89 , struct V_28 * V_28 )
{
struct V_162 V_163 ;
const struct V_47 * V_186 = & V_28 -> V_187 ;
struct V_160 * V_160 ;
T_1 V_58 = 0 ;
int V_188 ;
int V_86 = V_189 ;
F_107 ( & V_163 ) ;
V_160 = F_108 ( V_89 , V_58 , & V_163 ) ;
while ( 1 ) {
struct V_167 * V_168 ;
struct V_169 * V_170 ;
if ( F_87 ( V_160 ) ) {
struct V_32 * V_33 = F_26 ( V_89 ) ;
V_86 = F_88 ( V_160 ) ;
F_105 ( L_17 V_84 L_22 ,
F_59 ( F_74 ( V_89 ) ) , V_58 ,
V_86 , V_33 -> V_81 ) ;
break;
}
V_168 = F_109 ( V_160 ) ;
for ( V_170 = F_110 ( V_168 ) ; V_170 ;
V_170 = F_111 ( V_170 ) ) {
T_1 V_11 ;
int V_171 ;
char * V_30 ;
V_11 = F_112 ( V_170 -> V_172 ) ;
if ( F_21 ( V_11 < V_58 ) )
continue;
V_171 = F_113 ( V_170 -> V_173 ) ;
if ( F_21 ( V_171 == 0 ) )
continue;
V_30 = V_170 -> V_174 ;
if ( V_30 [ 0 ] == '.' ) {
if ( V_171 == 1 )
continue;
else if ( V_30 [ 1 ] == '.' && V_171 == 2 )
continue;
else
V_188 = 1 ;
} else {
V_188 = 0 ;
}
if ( V_188 && V_186 -> V_30 [ 0 ] != '.' ) {
F_23 ( V_38 , L_23 ,
V_186 -> V_31 , V_186 -> V_30 ,
V_171 , V_30 ) ;
continue;
}
if ( V_186 -> V_31 != V_171 ||
memcmp ( V_186 -> V_30 , V_30 , V_171 ) != 0 )
V_86 = V_189 ;
else if ( ! V_188 )
V_86 = V_190 ;
else
V_86 = V_191 ;
F_114 ( V_160 , 0 ) ;
goto V_98;
}
V_58 = F_112 ( V_168 -> V_180 ) ;
if ( V_58 == V_181 ) {
F_114 ( V_160 , 0 ) ;
break;
} else if ( 1 ) {
F_114 ( V_160 , F_115 ( V_168 -> V_182 ) &
V_183 ) ;
V_160 = F_108 ( V_89 , V_58 , & V_163 ) ;
} else {
F_32 ( F_115 ( V_168 -> V_182 ) & V_183 ) ;
F_114 ( V_160 , 1 ) ;
}
}
V_98:
F_116 ( & V_163 ) ;
return V_86 ;
}
static void
F_119 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_148 * V_149 = & V_8 -> V_77 ;
struct V_146 * V_147 = F_78 ( V_8 -> V_42 ) ;
int V_192 ;
if ( V_2 && V_2 -> V_3 == V_110 )
V_192 = 1 ;
else
V_192 = 0 ;
F_43 ( V_8 , V_2 ) ;
if ( V_192 ) {
V_8 -> V_22 ++ ;
V_8 -> V_24 = 0 ;
V_8 -> V_19 = F_120 ( 2 * V_8 -> V_19 , V_147 -> V_193 ) ;
} else {
struct V_32 * V_33 = F_26 ( V_8 -> V_42 ) ;
V_8 -> V_23 ++ ;
V_8 -> V_24 ++ ;
if ( F_17 ( V_8 ) && F_82 ( V_149 ) ) {
F_28 ( & V_147 -> V_194 ) ;
F_23 ( V_38 , L_24 V_84 L_25 ,
F_59 ( & V_33 -> V_85 ) , V_8 -> V_22 ,
V_8 -> V_23 , V_8 -> V_82 ,
V_8 -> V_83 ) ;
F_5 ( & V_33 -> V_43 ) ;
if ( ! F_58 ( V_149 ) )
F_101 ( V_149 , V_184 ) ;
F_7 ( & V_33 -> V_43 ) ;
}
}
if ( ! F_58 ( V_149 ) )
F_51 ( & V_149 -> V_71 ) ;
}
int F_121 ( struct V_15 * V_89 , struct V_28 * * V_195 ,
int V_196 )
{
struct V_32 * V_33 = F_26 ( V_89 ) ;
struct V_7 * V_8 = V_33 -> V_80 ;
struct V_28 * V_29 ;
struct V_1 * V_2 ;
struct V_148 * V_149 ;
struct V_150 V_151 = { 0 } ;
struct V_157 * V_158 ;
int V_86 = 0 ;
struct V_32 * V_144 ;
F_32 ( V_33 -> V_81 == F_99 () ) ;
if ( V_8 ) {
V_149 = & V_8 -> V_77 ;
if ( F_21 ( F_58 ( V_149 ) &&
F_15 ( & V_8 -> V_63 ) ) ) {
F_117 ( V_89 , V_33 -> V_79 ) ;
return - V_103 ;
}
if ( ( * V_195 ) -> V_187 . V_30 [ 0 ] == '.' ) {
if ( V_8 -> V_175 ||
V_8 -> V_197 >= V_8 -> V_176 ) {
} else {
if ( ! V_8 -> V_175 )
V_8 -> V_175 = 1 ;
V_8 -> V_197 ++ ;
return - V_103 ;
}
}
V_2 = F_29 ( V_8 , & ( * V_195 ) -> V_187 ) ;
if ( ! V_2 || V_196 ) {
F_119 ( V_8 , V_2 ) ;
return V_2 ? 1 : - V_103 ;
}
if ( ! F_1 ( V_2 ) ) {
V_8 -> V_111 = V_2 -> V_39 ;
V_151 = F_122 ( F_123 ( 30 ) , NULL ,
V_198 , NULL ) ;
V_86 = F_102 ( V_8 -> V_76 ,
F_1 ( V_2 ) ||
F_58 ( V_149 ) ,
& V_151 ) ;
if ( V_86 < 0 ) {
F_119 ( V_8 , V_2 ) ;
return - V_103 ;
}
}
if ( V_2 -> V_3 == V_110 && V_2 -> V_56 ) {
struct V_15 * V_15 = V_2 -> V_56 ;
struct V_90 V_91 = { . V_128 = V_129 ,
. V_105 =
V_2 -> V_94 } ;
T_1 V_199 ;
V_86 = F_72 ( F_73 ( V_89 ) , & V_91 ,
F_74 ( V_15 ) , & V_199 ) ;
if ( V_86 == 1 ) {
if ( ! F_93 ( * V_195 ) ) {
struct V_28 * V_200 ;
V_200 = F_124 ( V_15 ,
* V_195 ) ;
if ( F_87 ( V_200 ) ) {
F_119 ( V_8 , V_2 ) ;
return F_88 ( V_200 ) ;
}
* V_195 = V_200 ;
} else if ( F_93 ( * V_195 ) != V_15 ) {
F_23 ( V_38 , L_26 V_84 L_27 V_84 L_28 ,
F_76 ( F_93 ( * V_195 ) -> V_106 , NULL , 0 ) ,
* V_195 ,
F_59 ( F_74 ( F_93 ( * V_195 ) ) ) ,
F_59 ( F_74 ( V_15 ) ) ) ;
F_119 ( V_8 , V_2 ) ;
return - V_117 ;
} else {
F_35 ( V_15 ) ;
}
V_2 -> V_56 = NULL ;
if ( ( V_199 & V_201 ) &&
F_125 ( * V_195 ) )
F_126 ( * V_195 ) ;
F_34 ( & V_91 ) ;
}
}
F_119 ( V_8 , V_2 ) ;
return V_86 ;
}
V_86 = F_118 ( V_89 , * V_195 ) ;
if ( V_86 == V_189 ) {
V_86 = - V_103 ;
goto V_98;
}
V_8 = F_52 () ;
if ( ! V_8 ) {
V_86 = - V_37 ;
goto V_98;
}
V_8 -> V_175 = ( V_86 == V_191 ) ;
V_8 -> V_42 = F_50 ( V_89 ) ;
if ( F_21 ( ! V_8 -> V_42 ) ) {
F_127 ( L_29 V_84 L_28 ,
F_59 ( & V_33 -> V_85 ) ) ;
V_86 = - V_117 ;
goto V_98;
}
V_29 = F_128 ( ( * V_195 ) -> V_202 ) ;
if ( F_21 ( V_8 -> V_42 != F_93 ( V_29 ) ) ) {
struct V_32 * V_203 = F_26 ( F_93 ( V_29 ) ) ;
F_127 ( L_30 V_84 L_31 V_84 L_28 ,
* V_195 ,
F_59 ( & V_33 -> V_85 ) , F_59 ( & V_203 -> V_85 ) ) ;
F_97 ( V_29 ) ;
F_35 ( V_8 -> V_42 ) ;
V_86 = - V_103 ;
goto V_98;
}
F_23 ( V_38 , L_32 ,
V_8 , V_29 ) ;
F_55 ( V_8 ) ;
V_33 -> V_80 = V_8 ;
V_144 = F_26 ( F_93 ( V_29 ) ) ;
V_158 = F_104 ( F_106 , V_29 , L_33 ,
V_144 -> V_81 ) ;
V_149 = & V_8 -> V_77 ;
if ( F_87 ( V_158 ) ) {
V_86 = F_88 ( V_158 ) ;
F_105 ( L_34 , V_86 ) ;
F_97 ( V_29 ) ;
V_33 -> V_79 = NULL ;
F_101 ( V_149 , V_156 ) ;
F_101 ( & V_8 -> V_70 , V_156 ) ;
F_56 ( V_8 ) ;
F_56 ( V_8 ) ;
F_32 ( ! V_33 -> V_80 ) ;
return - V_103 ;
}
F_102 ( V_149 -> V_71 ,
F_82 ( V_149 ) || F_58 ( V_149 ) ,
& V_151 ) ;
F_56 ( V_8 ) ;
return - V_103 ;
V_98:
F_36 ( V_8 ) ;
F_5 ( & V_33 -> V_43 ) ;
V_33 -> V_79 = NULL ;
V_33 -> V_81 = 0 ;
F_7 ( & V_33 -> V_43 ) ;
return V_86 ;
}
