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
return ! F_15 ( & V_8 -> V_20 ) ;
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
F_19 ( struct V_28 * V_29 , struct V_7 * V_8 , T_1 V_25 ,
const char * V_30 , int V_31 , const struct V_32 * V_33 )
{
struct V_34 * V_35 ;
struct V_1 * V_2 ;
int V_36 ;
char * V_37 ;
V_36 = sizeof( struct V_1 ) + ( V_31 & ~ 3 ) + 4 ;
V_2 = F_20 ( V_36 , V_38 ) ;
if ( F_21 ( ! V_2 ) )
return F_22 ( - V_39 ) ;
F_23 ( V_40 , L_1 ,
V_31 , V_30 , V_2 , V_25 ) ;
V_2 -> V_41 = V_25 ;
V_2 -> V_3 = V_4 ;
V_2 -> V_42 = V_36 ;
V_37 = ( char * ) V_2 + sizeof( struct V_1 ) ;
memcpy ( V_37 , V_30 , V_31 ) ;
V_37 [ V_31 ] = 0 ;
V_2 -> V_10 . V_11 = F_24 ( V_29 , V_30 , V_31 ) ;
V_2 -> V_10 . V_31 = V_31 ;
V_2 -> V_10 . V_30 = V_37 ;
V_2 -> V_43 = * V_33 ;
V_35 = F_25 ( V_8 -> V_44 -> V_45 ) ;
F_5 ( & V_35 -> V_46 ) ;
F_26 ( & V_2 -> V_47 ) ;
F_4 ( V_8 , V_2 ) ;
F_7 ( & V_35 -> V_46 ) ;
F_27 ( & V_8 -> V_18 ) ;
return V_2 ;
}
static void F_28 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_23 ( V_40 , L_2 ,
V_2 -> V_10 . V_31 , V_2 -> V_10 . V_30 , V_2 ,
V_2 -> V_41 ) ;
F_29 ( F_15 ( & V_2 -> V_47 ) ) ;
F_29 ( F_15 ( & V_2 -> V_13 ) ) ;
F_30 ( V_2 ) ;
F_31 ( & V_8 -> V_18 ) ;
}
static struct V_1 *
F_32 ( struct V_7 * V_8 , const struct V_48 * V_48 )
{
struct V_1 * V_2 ;
int V_9 = F_3 ( V_48 -> V_11 ) ;
F_33 (entry, &sai->sai_cache[i], se_hash) {
if ( V_2 -> V_10 . V_11 == V_48 -> V_11 &&
V_2 -> V_10 . V_31 == V_48 -> V_31 &&
memcmp ( V_2 -> V_10 . V_30 , V_48 -> V_30 , V_48 -> V_31 ) == 0 )
return V_2 ;
}
return NULL ;
}
static inline void
F_34 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_34 * V_35 = F_25 ( V_8 -> V_44 -> V_45 ) ;
F_29 ( ! F_15 ( & V_2 -> V_13 ) ) ;
F_29 ( ! F_15 ( & V_2 -> V_47 ) ) ;
F_29 ( F_1 ( V_2 ) ) ;
F_8 ( V_8 , V_2 ) ;
F_5 ( & V_35 -> V_46 ) ;
F_9 ( & V_2 -> V_47 ) ;
F_7 ( & V_35 -> V_46 ) ;
if ( V_2 -> V_49 )
F_35 ( V_2 -> V_49 ) ;
F_28 ( V_8 , V_2 ) ;
}
static void
F_36 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_1 * V_50 , * V_51 ;
if ( V_2 && V_2 -> V_3 == V_52 ) {
struct V_53 * V_54 = F_37 ( V_8 -> V_44 -> V_45 ) ;
V_8 -> V_22 ++ ;
V_8 -> V_24 = 0 ;
V_8 -> V_19 = F_38 ( 2 * V_8 -> V_19 , V_54 -> V_55 ) ;
} else {
V_8 -> V_23 ++ ;
V_8 -> V_24 ++ ;
}
if ( V_2 )
F_34 ( V_8 , V_2 ) ;
F_39 (tmp, next, &sai->sai_entries, se_list) {
if ( ! F_18 ( V_8 , V_50 -> V_41 ) )
break;
F_34 ( V_8 , V_50 ) ;
}
F_40 ( & V_8 -> V_56 . V_57 ) ;
}
static bool
F_41 ( struct V_7 * V_8 , struct V_1 * V_2 , int V_58 )
{
struct V_59 * V_60 = & V_8 -> V_61 ;
T_1 V_25 = V_2 -> V_41 ;
struct V_1 * V_62 ;
F_29 ( ! F_1 ( V_2 ) ) ;
F_29 ( F_15 ( & V_2 -> V_47 ) ) ;
F_42 (se, &sai->sai_entries, se_list) {
if ( V_62 -> V_41 < V_2 -> V_41 ) {
V_60 = & V_62 -> V_47 ;
break;
}
}
F_43 ( & V_2 -> V_47 , V_60 ) ;
V_2 -> V_3 = V_58 < 0 ? V_63 : V_52 ;
return ( V_25 == V_8 -> V_64 ) ;
}
static void
F_44 ( struct V_7 * V_8 , struct V_1 * V_2 , int V_58 )
{
struct V_34 * V_35 = F_25 ( V_8 -> V_44 -> V_45 ) ;
struct V_65 * V_66 = V_2 -> V_67 ;
struct V_68 * V_69 = V_2 -> V_70 ;
bool V_71 ;
if ( V_66 ) {
V_2 -> V_67 = NULL ;
F_45 ( & V_66 -> V_72 ) ;
F_35 ( V_66 -> V_73 ) ;
F_30 ( V_66 ) ;
}
if ( V_69 ) {
V_2 -> V_70 = NULL ;
F_46 ( V_69 ) ;
}
F_5 ( & V_35 -> V_46 ) ;
V_71 = F_41 ( V_8 , V_2 , V_58 ) ;
F_7 ( & V_35 -> V_46 ) ;
if ( V_71 )
F_40 ( & V_8 -> V_74 ) ;
}
static void F_47 ( struct V_7 * V_8 ,
struct V_15 * V_15 , int V_25 )
{
struct V_34 * V_75 = F_25 ( V_15 ) ;
struct V_34 * V_29 = F_25 ( V_8 -> V_44 -> V_45 ) ;
int V_76 = 0 ;
F_5 ( & V_75 -> V_77 ) ;
if ( V_75 -> V_78 == 0 ) {
V_75 -> V_78 = V_25 ;
F_7 ( & V_75 -> V_77 ) ;
F_29 ( F_15 ( & V_75 -> V_79 ) ) ;
F_48 ( V_15 ) ;
F_5 ( & V_29 -> V_77 ) ;
if ( F_15 ( & V_8 -> V_21 ) )
V_76 = 1 ;
F_6 ( & V_75 -> V_79 , & V_8 -> V_21 ) ;
F_7 ( & V_29 -> V_77 ) ;
} else {
F_7 ( & V_75 -> V_77 ) ;
}
if ( V_76 > 0 )
F_40 ( & V_8 -> V_80 . V_57 ) ;
}
static struct V_7 * F_49 ( struct V_28 * V_28 )
{
struct V_34 * V_35 = F_25 ( V_28 -> V_45 ) ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_20 ( sizeof( * V_8 ) , V_38 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_44 = F_50 ( V_28 ) ;
F_51 ( & V_8 -> V_81 , 1 ) ;
V_8 -> V_19 = V_82 ;
V_8 -> V_27 = 1 ;
F_52 ( & V_8 -> V_74 ) ;
F_52 ( & V_8 -> V_56 . V_57 ) ;
F_52 ( & V_8 -> V_80 . V_57 ) ;
F_26 ( & V_8 -> V_20 ) ;
F_26 ( & V_8 -> V_61 ) ;
F_26 ( & V_8 -> V_21 ) ;
for ( V_9 = 0 ; V_9 < V_83 ; V_9 ++ ) {
F_26 ( & V_8 -> V_14 [ V_9 ] ) ;
F_53 ( & V_8 -> V_12 [ V_9 ] ) ;
}
F_51 ( & V_8 -> V_18 , 0 ) ;
F_5 ( & V_84 ) ;
V_35 -> V_85 = ++ V_86 ;
if ( F_21 ( ! V_86 ) )
V_35 -> V_85 = ++ V_86 ;
F_7 ( & V_84 ) ;
return V_8 ;
}
static inline void F_54 ( struct V_7 * V_8 )
{
F_29 ( V_8 -> V_44 ) ;
F_55 ( V_8 -> V_44 ) ;
F_30 ( V_8 ) ;
}
static inline struct V_7 * F_56 ( struct V_15 * V_87 )
{
struct V_34 * V_35 = F_25 ( V_87 ) ;
struct V_7 * V_8 = NULL ;
F_5 ( & V_35 -> V_46 ) ;
V_8 = V_35 -> V_88 ;
if ( V_8 )
F_27 ( & V_8 -> V_81 ) ;
F_7 ( & V_35 -> V_46 ) ;
return V_8 ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_34 * V_35 = F_25 ( V_8 -> V_44 -> V_45 ) ;
if ( F_58 ( & V_8 -> V_81 , & V_35 -> V_46 ) ) {
struct V_53 * V_54 = F_37 ( V_8 -> V_44 -> V_45 ) ;
struct V_1 * V_2 , * V_51 ;
V_35 -> V_88 = NULL ;
F_7 ( & V_35 -> V_46 ) ;
F_29 ( F_59 ( & V_8 -> V_56 ) ) ;
F_29 ( F_59 ( & V_8 -> V_80 ) ) ;
F_29 ( V_8 -> V_89 == V_8 -> V_90 ) ;
F_29 ( ! F_14 ( V_8 ) ) ;
F_39 (entry, next, &sai->sai_entries,
se_list)
F_34 ( V_8 , V_2 ) ;
F_29 ( F_13 ( & V_8 -> V_18 ) == 0 ) ;
F_29 ( F_15 ( & V_8 -> V_21 ) ) ;
F_54 ( V_8 ) ;
F_31 ( & V_54 -> V_91 ) ;
}
}
static void F_60 ( struct V_15 * V_15 , struct V_7 * V_8 )
{
struct V_34 * V_35 = F_25 ( V_15 ) ;
T_1 V_25 = V_35 -> V_78 ;
int V_92 ;
F_29 ( F_15 ( & V_35 -> V_79 ) ) ;
if ( F_18 ( V_8 , V_25 + 1 ) ) {
V_35 -> V_78 = 0 ;
F_35 ( V_15 ) ;
return;
}
V_92 = F_61 ( & V_35 -> V_93 ) ;
if ( V_92 == 0 ) {
V_35 -> V_78 = 0 ;
F_35 ( V_15 ) ;
return;
}
if ( V_35 -> V_94 != 0 &&
F_62 ( F_63 ( - 1 ) , V_35 -> V_94 ) ) {
F_64 ( & V_35 -> V_93 ) ;
V_35 -> V_78 = 0 ;
F_35 ( V_15 ) ;
return;
}
F_23 ( V_40 , L_3
V_95 L_4 , F_65 ( & V_35 -> V_96 ) , V_25 ) ;
F_66 ( V_15 ) ;
V_35 -> V_78 = 0 ;
V_35 -> V_94 = F_67 () ;
F_64 ( & V_35 -> V_93 ) ;
F_23 ( V_40 , L_5
V_95 L_6 ,
F_65 ( & V_35 -> V_96 ) , V_25 , V_92 ) ;
F_35 ( V_15 ) ;
}
static void F_68 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_15 * V_87 = V_8 -> V_44 -> V_45 ;
struct V_15 * V_75 ;
struct V_65 * V_66 ;
struct V_97 * V_98 ;
struct V_68 * V_69 ;
struct V_99 * V_100 ;
int V_92 = 0 ;
F_29 ( V_2 -> V_101 != 0 ) ;
V_66 = V_2 -> V_67 ;
V_98 = & V_66 -> V_72 ;
V_69 = V_2 -> V_70 ;
V_100 = F_69 ( & V_69 -> V_102 , & V_103 ) ;
if ( ! V_100 ) {
V_92 = - V_104 ;
goto V_105;
}
V_75 = V_2 -> V_49 ;
if ( V_75 ) {
if ( F_21 ( ! F_70 ( & V_66 -> V_106 . V_107 , & V_100 -> V_108 ) ) ) {
V_2 -> V_49 = NULL ;
F_35 ( V_75 ) ;
V_75 = NULL ;
}
}
V_98 -> V_109 = V_2 -> V_101 ;
V_92 = F_71 ( F_72 ( V_87 ) , V_98 , F_73 ( V_87 ) , NULL ) ;
if ( V_92 != 1 ) {
V_92 = - V_110 ;
goto V_105;
}
V_92 = F_74 ( & V_75 , V_69 , V_87 -> V_111 , V_98 ) ;
if ( V_92 )
goto V_105;
F_23 ( V_40 , L_7 V_95 L_8 ,
F_75 ( V_75 -> V_111 , NULL , 0 ) ,
V_2 -> V_10 . V_31 , V_2 -> V_10 . V_30 ,
F_65 ( F_73 ( V_75 ) ) , V_75 ) ;
F_76 ( F_37 ( V_87 ) -> V_112 , V_75 , V_98 , NULL ) ;
V_2 -> V_49 = V_75 ;
if ( F_10 ( V_8 , V_75 ) )
F_47 ( V_8 , V_75 , V_2 -> V_41 ) ;
V_105:
F_44 ( V_8 , V_2 , V_92 ) ;
}
static void F_77 ( struct V_7 * V_8 )
{
struct V_34 * V_35 ;
V_35 = F_25 ( V_8 -> V_44 -> V_45 ) ;
while ( F_14 ( V_8 ) ) {
struct V_1 * V_2 ;
F_5 ( & V_35 -> V_46 ) ;
if ( F_21 ( ! F_14 ( V_8 ) ) ) {
F_7 ( & V_35 -> V_46 ) ;
break;
}
V_2 = F_78 ( V_8 -> V_20 . V_51 ,
struct V_1 , V_47 ) ;
F_9 ( & V_2 -> V_47 ) ;
F_7 ( & V_35 -> V_46 ) ;
F_68 ( V_8 , V_2 ) ;
}
}
static int F_79 ( struct V_68 * V_69 ,
struct V_65 * V_66 , int V_92 )
{
struct V_97 * V_98 = & V_66 -> V_72 ;
struct V_15 * V_87 = V_66 -> V_73 ;
struct V_34 * V_35 = F_25 ( V_87 ) ;
struct V_7 * V_8 = V_35 -> V_88 ;
struct V_1 * V_2 = (struct V_1 * ) V_66 -> V_113 ;
T_2 * V_114 = NULL ;
T_1 V_115 = 0 ;
if ( F_80 ( V_98 , V_116 ) )
V_92 = - V_117 ;
F_29 ( V_8 ) ;
F_29 ( ! F_59 ( & V_8 -> V_56 ) ) ;
F_29 ( V_2 ) ;
F_23 ( V_40 , L_9 ,
V_2 -> V_10 . V_31 , V_2 -> V_10 . V_30 , V_92 ) ;
if ( V_92 ) {
F_45 ( V_98 ) ;
F_35 ( V_87 ) ;
F_30 ( V_66 ) ;
} else {
V_115 = V_98 -> V_109 ;
F_81 ( V_98 ) ;
}
F_5 ( & V_35 -> V_46 ) ;
if ( V_92 ) {
if ( F_41 ( V_8 , V_2 , V_92 ) )
V_114 = & V_8 -> V_74 ;
} else {
V_2 -> V_67 = V_66 ;
V_2 -> V_70 = F_82 ( V_69 ) ;
V_2 -> V_101 = V_115 ;
if ( ! F_14 ( V_8 ) )
V_114 = & V_8 -> V_56 . V_57 ;
F_6 ( & V_2 -> V_47 , & V_8 -> V_20 ) ;
}
V_8 -> V_90 ++ ;
if ( V_114 )
F_40 ( V_114 ) ;
F_7 ( & V_35 -> V_46 ) ;
return V_92 ;
}
static void F_83 ( struct V_65 * V_66 )
{
F_35 ( V_66 -> V_73 ) ;
F_30 ( V_66 ) ;
}
static struct V_65 *
F_84 ( struct V_15 * V_87 , struct V_15 * V_75 , struct V_1 * V_2 )
{
struct V_65 * V_66 ;
struct V_118 * V_119 ;
struct V_120 * V_121 ;
V_66 = F_20 ( sizeof( * V_66 ) , V_38 ) ;
if ( ! V_66 )
return F_22 ( - V_39 ) ;
V_121 = F_85 ( & V_66 -> V_106 , V_87 , V_75 , NULL , 0 , 0 ,
V_122 , NULL ) ;
if ( F_86 ( V_121 ) ) {
F_30 ( V_66 ) ;
return (struct V_65 * ) V_121 ;
}
if ( ! V_75 )
V_121 -> V_107 = V_2 -> V_43 ;
V_66 -> V_72 . V_123 = V_124 ;
V_66 -> V_73 = F_48 ( V_87 ) ;
V_66 -> V_125 = F_79 ;
V_66 -> V_113 = V_2 ;
V_119 = & V_66 -> V_126 ;
V_119 -> V_127 = V_128 ;
V_119 -> V_129 = F_87 ( & V_66 -> V_72 ) ;
V_119 -> V_130 = V_131 ;
V_119 -> V_132 = V_133 ;
V_119 -> V_134 = NULL ;
V_119 -> V_135 = NULL ;
return V_66 ;
}
static int F_88 ( struct V_15 * V_87 , struct V_1 * V_2 )
{
struct V_65 * V_66 ;
int V_92 ;
V_66 = F_84 ( V_87 , NULL , V_2 ) ;
if ( F_86 ( V_66 ) )
return F_89 ( V_66 ) ;
V_92 = F_90 ( F_72 ( V_87 ) , V_66 ) ;
if ( V_92 )
F_83 ( V_66 ) ;
return V_92 ;
}
static int F_91 ( struct V_15 * V_87 , struct V_1 * V_2 ,
struct V_28 * V_28 )
{
struct V_15 * V_15 = V_45 ( V_28 ) ;
struct V_97 V_98 = { . V_123 = V_124 ,
. V_109 = 0 } ;
struct V_65 * V_66 ;
int V_92 ;
if ( F_21 ( ! V_15 ) )
return 1 ;
if ( F_92 ( V_28 ) )
return 1 ;
V_2 -> V_49 = F_48 ( V_15 ) ;
V_92 = F_71 ( F_72 ( V_87 ) , & V_98 , F_73 ( V_15 ) ,
NULL ) ;
if ( V_92 == 1 ) {
V_2 -> V_101 = V_98 . V_109 ;
F_45 ( & V_98 ) ;
return 1 ;
}
V_66 = F_84 ( V_87 , V_15 , V_2 ) ;
if ( F_86 ( V_66 ) ) {
V_2 -> V_49 = NULL ;
F_35 ( V_15 ) ;
return F_89 ( V_66 ) ;
}
V_92 = F_90 ( F_72 ( V_87 ) , V_66 ) ;
if ( V_92 ) {
V_2 -> V_49 = NULL ;
F_35 ( V_15 ) ;
F_83 ( V_66 ) ;
}
return V_92 ;
}
static void F_93 ( struct V_28 * V_29 , const char * V_30 , int V_31 ,
const struct V_32 * V_33 )
{
struct V_15 * V_87 = V_45 ( V_29 ) ;
struct V_34 * V_35 = F_25 ( V_87 ) ;
struct V_7 * V_8 = V_35 -> V_88 ;
struct V_28 * V_28 = NULL ;
struct V_1 * V_2 ;
int V_92 ;
V_2 = F_19 ( V_29 , V_8 , V_8 -> V_27 , V_30 , V_31 , V_33 ) ;
if ( F_86 ( V_2 ) )
return;
V_28 = F_94 ( V_29 , & V_2 -> V_10 ) ;
if ( ! V_28 ) {
V_92 = F_88 ( V_87 , V_2 ) ;
} else {
V_92 = F_91 ( V_87 , V_2 , V_28 ) ;
if ( V_92 == 1 && F_10 ( V_8 , V_45 ( V_28 ) ) )
F_47 ( V_8 , V_45 ( V_28 ) , V_2 -> V_41 ) ;
}
if ( V_28 )
F_55 ( V_28 ) ;
if ( V_92 )
F_44 ( V_8 , V_2 , V_92 ) ;
else
V_8 -> V_89 ++ ;
V_8 -> V_27 ++ ;
}
static int F_95 ( void * V_136 )
{
struct V_28 * V_29 = V_136 ;
struct V_15 * V_87 = V_45 ( V_29 ) ;
struct V_34 * V_137 = F_25 ( V_87 ) ;
struct V_34 * V_138 ;
struct V_53 * V_54 = F_37 ( V_87 ) ;
struct V_7 * V_8 ;
struct V_139 * V_140 ;
struct V_141 V_142 = { 0 } ;
V_8 = F_56 ( V_87 ) ;
V_140 = & V_8 -> V_80 ;
V_140 -> V_143 = F_96 () ;
F_23 ( V_40 , L_10 ,
V_8 , V_29 ) ;
F_27 ( & V_54 -> V_144 ) ;
F_5 ( & V_137 -> V_77 ) ;
V_8 -> V_17 = 1 ;
if ( F_97 ( V_140 ) )
F_98 ( V_140 , V_145 ) ;
F_7 ( & V_137 -> V_77 ) ;
F_40 ( & V_140 -> V_57 ) ;
while ( 1 ) {
F_99 ( V_140 -> V_57 ,
! F_15 ( & V_8 -> V_21 ) ||
! F_100 ( V_140 ) ,
& V_142 ) ;
if ( ! F_100 ( V_140 ) )
break;
F_5 ( & V_137 -> V_77 ) ;
if ( ! F_15 ( & V_8 -> V_21 ) ) {
V_138 = F_78 ( V_8 -> V_21 . V_51 ,
struct V_34 , V_79 ) ;
F_9 ( & V_138 -> V_79 ) ;
F_7 ( & V_137 -> V_77 ) ;
F_60 ( & V_138 -> V_146 , V_8 ) ;
} else {
F_7 ( & V_137 -> V_77 ) ;
}
}
F_5 ( & V_137 -> V_77 ) ;
V_8 -> V_17 = 0 ;
while ( ! F_15 ( & V_8 -> V_21 ) ) {
V_138 = F_78 ( V_8 -> V_21 . V_51 ,
struct V_34 , V_79 ) ;
F_9 ( & V_138 -> V_79 ) ;
F_7 ( & V_137 -> V_77 ) ;
V_138 -> V_78 = 0 ;
F_35 ( & V_138 -> V_146 ) ;
F_5 ( & V_137 -> V_77 ) ;
}
F_98 ( V_140 , V_147 ) ;
F_7 ( & V_137 -> V_77 ) ;
F_40 ( & V_140 -> V_57 ) ;
F_57 ( V_8 ) ;
F_23 ( V_40 , L_11 ,
V_8 , V_29 ) ;
return 0 ;
}
static void F_101 ( struct V_28 * V_29 , struct V_7 * V_8 )
{
struct V_139 * V_140 = & V_8 -> V_80 ;
struct V_141 V_142 = { 0 } ;
struct V_34 * V_137 ;
struct V_148 * V_149 ;
F_23 ( V_40 , L_12 ,
V_8 , V_29 ) ;
V_137 = F_25 ( V_45 ( V_29 ) ) ;
V_149 = F_102 ( F_95 , V_29 , L_13 ,
V_137 -> V_150 ) ;
if ( F_86 ( V_149 ) ) {
F_103 ( L_14 , F_89 ( V_149 ) ) ;
F_98 ( V_140 , V_147 ) ;
return;
}
F_99 ( V_140 -> V_57 ,
F_100 ( V_140 ) || F_59 ( V_140 ) ,
& V_142 ) ;
}
static int F_104 ( void * V_136 )
{
struct V_28 * V_29 = V_136 ;
struct V_15 * V_87 = V_45 ( V_29 ) ;
struct V_34 * V_35 = F_25 ( V_87 ) ;
struct V_53 * V_54 = F_37 ( V_87 ) ;
struct V_7 * V_8 ;
struct V_139 * V_151 ;
struct V_139 * V_152 ;
struct V_153 * V_153 = NULL ;
T_1 V_60 = 0 ;
int V_154 = 0 ;
int V_92 = 0 ;
struct V_120 * V_121 ;
struct V_141 V_142 = { 0 } ;
V_8 = F_56 ( V_87 ) ;
V_151 = & V_8 -> V_56 ;
V_152 = & V_8 -> V_80 ;
V_151 -> V_143 = F_96 () ;
F_23 ( V_40 , L_15 ,
V_8 , V_29 ) ;
V_121 = F_85 ( NULL , V_87 , V_87 , NULL , 0 , 0 ,
V_122 , V_87 ) ;
if ( F_86 ( V_121 ) ) {
V_92 = F_89 ( V_121 ) ;
goto V_105;
}
V_121 -> V_155 = F_37 ( V_87 ) -> V_156 ;
if ( V_54 -> V_157 & V_158 )
F_101 ( V_29 , V_8 ) ;
F_27 ( & V_54 -> V_159 ) ;
F_5 ( & V_35 -> V_46 ) ;
if ( F_97 ( V_151 ) )
F_98 ( V_151 , V_145 ) ;
F_7 ( & V_35 -> V_46 ) ;
F_40 ( & V_151 -> V_57 ) ;
while ( V_60 != V_160 && F_100 ( V_151 ) ) {
struct V_161 * V_162 ;
struct V_163 * V_164 ;
V_8 -> V_165 = 1 ;
V_153 = F_105 ( V_87 , V_121 , V_60 ) ;
V_8 -> V_165 = 0 ;
if ( F_86 ( V_153 ) ) {
V_92 = F_89 ( V_153 ) ;
F_23 ( V_40 , L_16 V_95 L_17 ,
F_65 ( F_73 ( V_87 ) ) , V_60 , V_8 -> V_27 ,
V_35 -> V_150 , V_92 ) ;
break;
}
V_162 = F_106 ( V_153 ) ;
for ( V_164 = F_107 ( V_162 ) ;
V_164 && F_100 ( V_151 ) && ! F_17 ( V_8 ) ;
V_164 = F_108 ( V_164 ) ) {
struct V_32 V_33 ;
T_1 V_11 ;
int V_166 ;
char * V_30 ;
V_11 = F_109 ( V_164 -> V_167 ) ;
if ( F_21 ( V_11 < V_60 ) )
continue;
V_166 = F_110 ( V_164 -> V_168 ) ;
if ( F_21 ( V_166 == 0 ) )
continue;
V_30 = V_164 -> V_169 ;
if ( V_30 [ 0 ] == '.' ) {
if ( V_166 == 1 ) {
continue;
} else if ( V_30 [ 1 ] == '.' && V_166 == 2 ) {
continue;
} else if ( ! V_8 -> V_170 ) {
V_8 -> V_171 ++ ;
continue;
}
}
if ( F_21 ( ++ V_154 == 1 ) )
continue;
F_111 ( & V_33 , & V_164 -> V_172 ) ;
do {
F_99 ( V_151 -> V_57 ,
! F_12 ( V_8 ) ||
F_14 ( V_8 ) ||
! F_15 ( & V_8 -> V_21 ) ||
! F_100 ( V_151 ) ,
& V_142 ) ;
F_77 ( V_8 ) ;
F_5 ( & V_35 -> V_77 ) ;
while ( F_12 ( V_8 ) &&
! F_16 ( V_8 ) ) {
struct V_34 * V_138 ;
V_138 = F_78 ( V_8 -> V_21 . V_51 ,
struct V_34 , V_79 ) ;
F_9 ( & V_138 -> V_79 ) ;
F_7 ( & V_35 -> V_77 ) ;
F_60 ( & V_138 -> V_146 ,
V_8 ) ;
F_5 ( & V_35 -> V_77 ) ;
}
F_7 ( & V_35 -> V_77 ) ;
} while ( F_12 ( V_8 ) &&
F_100 ( V_151 ) );
F_93 ( V_29 , V_30 , V_166 , & V_33 ) ;
}
V_60 = F_109 ( V_162 -> V_173 ) ;
F_112 ( V_87 , V_153 ,
F_113 ( V_162 -> V_174 ) & V_175 ) ;
if ( F_17 ( V_8 ) ) {
V_92 = - V_104 ;
F_27 ( & V_54 -> V_176 ) ;
F_23 ( V_40 , L_18 V_95 L_19 ,
F_65 ( & V_35 -> V_96 ) , V_8 -> V_22 ,
V_8 -> V_23 , V_8 -> V_89 ,
V_8 -> V_90 , F_96 () ) ;
break;
}
}
F_114 ( V_121 ) ;
if ( V_92 < 0 ) {
F_5 ( & V_35 -> V_46 ) ;
F_98 ( V_151 , V_177 ) ;
V_35 -> V_178 = 0 ;
F_7 ( & V_35 -> V_46 ) ;
}
while ( F_100 ( V_151 ) ) {
F_99 ( V_151 -> V_57 ,
F_14 ( V_8 ) ||
! F_16 ( V_8 ) ||
! F_100 ( V_151 ) ,
& V_142 ) ;
F_77 ( V_8 ) ;
}
V_105:
if ( V_8 -> V_17 ) {
F_5 ( & V_35 -> V_77 ) ;
F_98 ( V_152 , V_177 ) ;
F_7 ( & V_35 -> V_77 ) ;
F_40 ( & V_152 -> V_57 ) ;
F_23 ( V_40 , L_20 ,
V_8 , ( unsigned int ) V_152 -> V_143 ) ;
F_99 ( V_152 -> V_57 ,
F_59 ( V_152 ) ,
& V_142 ) ;
} else {
F_98 ( V_152 , V_147 ) ;
}
while ( V_8 -> V_89 != V_8 -> V_90 ) {
V_142 = F_115 ( F_116 ( V_179 >> 3 ) ,
NULL , NULL ) ;
F_99 ( V_151 -> V_57 ,
V_8 -> V_89 == V_8 -> V_90 , & V_142 ) ;
}
F_77 ( V_8 ) ;
F_5 ( & V_35 -> V_46 ) ;
F_98 ( V_151 , V_147 ) ;
F_7 ( & V_35 -> V_46 ) ;
F_23 ( V_40 , L_21 ,
V_8 , V_29 ) ;
F_40 ( & V_8 -> V_74 ) ;
F_40 ( & V_151 -> V_57 ) ;
F_57 ( V_8 ) ;
return V_92 ;
}
void F_117 ( struct V_15 * V_87 , void * V_180 )
{
struct V_34 * V_35 = F_25 ( V_87 ) ;
F_5 ( & V_35 -> V_46 ) ;
if ( ! V_35 -> V_181 && ! V_35 -> V_88 ) {
F_29 ( ! V_35 -> V_150 ) ;
V_35 -> V_181 = V_180 ;
V_35 -> V_150 = F_96 () ;
V_35 -> V_178 = 1 ;
}
F_7 ( & V_35 -> V_46 ) ;
}
void F_118 ( struct V_15 * V_87 , void * V_180 )
{
struct V_34 * V_35 = F_25 ( V_87 ) ;
struct V_7 * V_8 ;
F_29 ( V_35 -> V_181 == V_180 ) ;
F_29 ( V_35 -> V_150 ) ;
F_23 ( V_40 , L_22 V_95 L_23 ,
F_65 ( & V_35 -> V_96 ) ) ;
F_5 ( & V_35 -> V_46 ) ;
V_35 -> V_181 = NULL ;
V_35 -> V_150 = 0 ;
V_35 -> V_178 = 0 ;
V_8 = V_35 -> V_88 ;
if ( V_8 && F_100 ( & V_8 -> V_56 ) ) {
F_98 ( & V_8 -> V_56 , V_177 ) ;
F_40 ( & V_8 -> V_56 . V_57 ) ;
}
F_7 ( & V_35 -> V_46 ) ;
}
static int F_119 ( struct V_15 * V_87 , struct V_28 * V_28 )
{
const struct V_48 * V_182 = & V_28 -> V_183 ;
struct V_120 * V_121 ;
struct V_153 * V_153 ;
T_1 V_60 = 0 ;
int V_184 ;
int V_92 = V_185 ;
V_121 = F_85 ( NULL , V_87 , V_87 , NULL , 0 , 0 ,
V_122 , V_87 ) ;
if ( F_86 ( V_121 ) )
return F_89 ( V_121 ) ;
V_121 -> V_155 = F_37 ( V_87 ) -> V_156 ;
V_153 = F_105 ( V_87 , V_121 , V_60 ) ;
while ( 1 ) {
struct V_161 * V_162 ;
struct V_163 * V_164 ;
if ( F_86 ( V_153 ) ) {
struct V_34 * V_35 = F_25 ( V_87 ) ;
V_92 = F_89 ( V_153 ) ;
F_103 ( L_24 V_95 L_25 ,
F_75 ( V_87 -> V_111 , NULL , 0 ) ,
F_65 ( F_73 ( V_87 ) ) , V_60 ,
V_35 -> V_150 , V_92 ) ;
break;
}
V_162 = F_106 ( V_153 ) ;
for ( V_164 = F_107 ( V_162 ) ; V_164 ;
V_164 = F_108 ( V_164 ) ) {
T_1 V_11 ;
int V_166 ;
char * V_30 ;
V_11 = F_109 ( V_164 -> V_167 ) ;
if ( F_21 ( V_11 < V_60 ) )
continue;
V_166 = F_110 ( V_164 -> V_168 ) ;
if ( F_21 ( V_166 == 0 ) )
continue;
V_30 = V_164 -> V_169 ;
if ( V_30 [ 0 ] == '.' ) {
if ( V_166 == 1 )
continue;
else if ( V_30 [ 1 ] == '.' && V_166 == 2 )
continue;
else
V_184 = 1 ;
} else {
V_184 = 0 ;
}
if ( V_184 && V_182 -> V_30 [ 0 ] != '.' ) {
F_23 ( V_40 , L_26 ,
V_182 -> V_31 , V_182 -> V_30 ,
V_166 , V_30 ) ;
continue;
}
if ( V_182 -> V_31 != V_166 ||
memcmp ( V_182 -> V_30 , V_30 , V_166 ) != 0 )
V_92 = V_185 ;
else if ( ! V_184 )
V_92 = V_186 ;
else
V_92 = V_187 ;
F_112 ( V_87 , V_153 , false ) ;
goto V_105;
}
V_60 = F_109 ( V_162 -> V_173 ) ;
if ( V_60 == V_160 ) {
F_112 ( V_87 , V_153 , false ) ;
goto V_105;
} else {
F_112 ( V_87 , V_153 ,
F_113 ( V_162 -> V_174 ) &
V_175 ) ;
V_153 = F_105 ( V_87 , V_121 , V_60 ) ;
}
}
V_105:
F_114 ( V_121 ) ;
return V_92 ;
}
static int F_120 ( struct V_15 * V_87 ,
struct V_7 * V_8 ,
struct V_28 * * V_188 ,
bool V_189 )
{
struct V_34 * V_35 = F_25 ( V_87 ) ;
struct V_1 * V_2 = NULL ;
struct V_141 V_142 = { 0 } ;
struct V_190 * V_191 ;
int V_92 = 0 ;
if ( ( * V_188 ) -> V_183 . V_30 [ 0 ] == '.' ) {
if ( V_8 -> V_170 ||
V_8 -> V_192 >= V_8 -> V_171 ) {
} else {
if ( ! V_8 -> V_170 )
V_8 -> V_170 = 1 ;
V_8 -> V_192 ++ ;
return - V_110 ;
}
}
if ( V_189 ) {
V_92 = 1 ;
goto V_193;
}
V_2 = F_32 ( V_8 , & ( * V_188 ) -> V_183 ) ;
if ( ! V_2 ) {
V_92 = - V_110 ;
goto V_193;
}
if ( ! F_1 ( V_2 ) && V_8 -> V_165 )
F_77 ( V_8 ) ;
if ( ! F_1 ( V_2 ) ) {
F_5 ( & V_35 -> V_46 ) ;
V_8 -> V_64 = V_2 -> V_41 ;
F_7 ( & V_35 -> V_46 ) ;
V_142 = F_121 ( F_122 ( 30 ) , NULL ,
V_194 , NULL ) ;
V_92 = F_99 ( V_8 -> V_74 , F_1 ( V_2 ) , & V_142 ) ;
if ( V_92 < 0 ) {
V_2 = NULL ;
V_92 = - V_110 ;
goto V_193;
}
}
if ( V_2 -> V_3 == V_52 && V_2 -> V_49 ) {
struct V_15 * V_15 = V_2 -> V_49 ;
struct V_97 V_98 = { . V_123 = V_124 ,
. V_109 = V_2 -> V_101 } ;
T_1 V_195 ;
V_92 = F_71 ( F_72 ( V_87 ) , & V_98 ,
F_73 ( V_15 ) , & V_195 ) ;
if ( V_92 == 1 ) {
if ( ! ( * V_188 ) -> V_45 ) {
struct V_28 * V_196 ;
V_196 = F_123 ( V_15 , * V_188 ) ;
if ( F_86 ( V_196 ) ) {
F_45 ( & V_98 ) ;
V_92 = F_89 ( V_196 ) ;
goto V_193;
}
* V_188 = V_196 ;
V_2 -> V_49 = NULL ;
} else if ( ( * V_188 ) -> V_45 != V_15 ) {
F_23 ( V_40 ,
L_27 V_95 L_28 V_95 L_23 ,
F_75 ( ( * V_188 ) -> V_45 -> V_111 ,
NULL , 0 ) ,
* V_188 ,
F_65 ( F_73 ( ( * V_188 ) -> V_45 ) ) ,
F_65 ( F_73 ( V_15 ) ) ) ;
F_45 ( & V_98 ) ;
V_92 = - V_197 ;
goto V_193;
}
if ( ( V_195 & V_198 ) &&
F_124 ( * V_188 ) )
F_125 ( * V_188 ) ;
F_45 ( & V_98 ) ;
}
}
V_193:
V_191 = F_126 ( * V_188 ) ;
V_191 -> V_199 = V_35 -> V_85 ;
F_36 ( V_8 , V_2 ) ;
return V_92 ;
}
static int F_127 ( struct V_15 * V_87 , struct V_28 * V_28 )
{
struct V_34 * V_35 = F_25 ( V_87 ) ;
struct V_7 * V_8 = NULL ;
struct V_141 V_142 = { 0 } ;
struct V_139 * V_140 ;
struct V_148 * V_149 ;
struct V_28 * V_29 = V_28 -> V_200 ;
int V_92 ;
V_92 = F_119 ( V_87 , V_28 ) ;
if ( V_92 == V_185 ) {
V_92 = - V_104 ;
goto V_105;
}
V_8 = F_49 ( V_29 ) ;
if ( ! V_8 ) {
V_92 = - V_39 ;
goto V_105;
}
V_8 -> V_170 = ( V_92 == V_187 ) ;
F_5 ( & V_35 -> V_46 ) ;
if ( F_21 ( V_35 -> V_88 || V_35 -> V_181 ||
V_35 -> V_150 != V_201 -> V_202 ) ) {
F_7 ( & V_35 -> V_46 ) ;
V_92 = - V_203 ;
goto V_105;
}
V_35 -> V_88 = V_8 ;
F_7 ( & V_35 -> V_46 ) ;
F_27 ( & F_37 ( V_29 -> V_45 ) -> V_91 ) ;
F_23 ( V_40 , L_29 ,
F_96 () , V_29 ) ;
V_149 = F_102 ( F_104 , V_29 , L_30 ,
V_35 -> V_150 ) ;
V_140 = & V_8 -> V_56 ;
if ( F_86 ( V_149 ) ) {
V_92 = F_89 ( V_149 ) ;
F_103 ( L_31 , V_92 ) ;
goto V_105;
}
F_99 ( V_140 -> V_57 ,
F_100 ( V_140 ) || F_59 ( V_140 ) ,
& V_142 ) ;
F_57 ( V_8 ) ;
return - V_110 ;
V_105:
F_5 ( & V_35 -> V_46 ) ;
V_35 -> V_178 = 0 ;
V_35 -> V_88 = NULL ;
F_7 ( & V_35 -> V_46 ) ;
if ( V_8 )
F_54 ( V_8 ) ;
return V_92 ;
}
int F_128 ( struct V_15 * V_87 , struct V_28 * * V_188 , bool V_189 )
{
struct V_7 * V_8 ;
V_8 = F_56 ( V_87 ) ;
if ( V_8 ) {
int V_92 ;
V_92 = F_120 ( V_87 , V_8 , V_188 , V_189 ) ;
F_23 ( V_40 , L_32 ,
* V_188 , V_92 ) ;
F_57 ( V_8 ) ;
return V_92 ;
}
return F_127 ( V_87 , * V_188 ) ;
}
