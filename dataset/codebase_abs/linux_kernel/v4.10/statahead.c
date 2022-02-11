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
V_2 -> V_3 = V_4 ;
V_2 -> V_40 = V_34 ;
V_35 = ( char * ) V_2 + sizeof( struct V_1 ) ;
memcpy ( V_35 , V_30 , V_31 ) ;
V_35 [ V_31 ] = 0 ;
V_2 -> V_10 . V_11 = F_24 ( V_29 , V_30 , V_31 ) ;
V_2 -> V_10 . V_31 = V_31 ;
V_2 -> V_10 . V_30 = V_35 ;
V_33 = F_25 ( V_8 -> V_41 -> V_42 ) ;
F_5 ( & V_33 -> V_43 ) ;
F_26 ( & V_2 -> V_44 ) ;
F_4 ( V_8 , V_2 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_27 ( & V_8 -> V_18 ) ;
return V_2 ;
}
static void F_28 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
F_23 ( V_38 , L_2 ,
V_2 -> V_10 . V_31 , V_2 -> V_10 . V_30 , V_2 ,
V_2 -> V_39 ) ;
F_29 ( F_15 ( & V_2 -> V_44 ) ) ;
F_29 ( F_15 ( & V_2 -> V_13 ) ) ;
F_30 ( V_2 ) ;
F_31 ( & V_8 -> V_18 ) ;
}
static struct V_1 *
F_32 ( struct V_7 * V_8 , const struct V_45 * V_45 )
{
struct V_1 * V_2 ;
int V_9 = F_3 ( V_45 -> V_11 ) ;
F_33 (entry, &sai->sai_cache[i], se_hash) {
if ( V_2 -> V_10 . V_11 == V_45 -> V_11 &&
V_2 -> V_10 . V_31 == V_45 -> V_31 &&
memcmp ( V_2 -> V_10 . V_30 , V_45 -> V_30 , V_45 -> V_31 ) == 0 )
return V_2 ;
}
return NULL ;
}
static inline void
F_34 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_32 * V_33 = F_25 ( V_8 -> V_41 -> V_42 ) ;
F_29 ( ! F_15 ( & V_2 -> V_13 ) ) ;
F_29 ( ! F_15 ( & V_2 -> V_44 ) ) ;
F_29 ( F_1 ( V_2 ) ) ;
F_8 ( V_8 , V_2 ) ;
F_5 ( & V_33 -> V_43 ) ;
F_9 ( & V_2 -> V_44 ) ;
F_7 ( & V_33 -> V_43 ) ;
if ( V_2 -> V_46 )
F_35 ( V_2 -> V_46 ) ;
F_28 ( V_8 , V_2 ) ;
}
static void
F_36 ( struct V_7 * V_8 , struct V_1 * V_2 )
{
struct V_1 * V_47 , * V_48 ;
if ( V_2 && V_2 -> V_3 == V_49 ) {
struct V_50 * V_51 = F_37 ( V_8 -> V_41 -> V_42 ) ;
V_8 -> V_22 ++ ;
V_8 -> V_24 = 0 ;
V_8 -> V_19 = F_38 ( 2 * V_8 -> V_19 , V_51 -> V_52 ) ;
} else {
V_8 -> V_23 ++ ;
V_8 -> V_24 ++ ;
}
if ( V_2 )
F_34 ( V_8 , V_2 ) ;
F_39 (tmp, next, &sai->sai_entries, se_list) {
if ( ! F_18 ( V_8 , V_47 -> V_39 ) )
break;
F_34 ( V_8 , V_47 ) ;
}
F_40 ( & V_8 -> V_53 . V_54 ) ;
}
static bool
F_41 ( struct V_7 * V_8 , struct V_1 * V_2 , int V_55 )
{
struct V_56 * V_57 = & V_8 -> V_58 ;
T_1 V_25 = V_2 -> V_39 ;
struct V_1 * V_59 ;
F_29 ( ! F_1 ( V_2 ) ) ;
F_29 ( F_15 ( & V_2 -> V_44 ) ) ;
F_42 (se, &sai->sai_entries, se_list) {
if ( V_59 -> V_39 < V_2 -> V_39 ) {
V_57 = & V_59 -> V_44 ;
break;
}
}
F_43 ( & V_2 -> V_44 , V_57 ) ;
V_2 -> V_3 = V_55 < 0 ? V_60 : V_49 ;
return ( V_25 == V_8 -> V_61 ) ;
}
static void
F_44 ( struct V_7 * V_8 , struct V_1 * V_2 , int V_55 )
{
struct V_32 * V_33 = F_25 ( V_8 -> V_41 -> V_42 ) ;
struct V_62 * V_63 = V_2 -> V_64 ;
struct V_65 * V_66 = V_2 -> V_67 ;
bool V_68 ;
if ( V_63 ) {
V_2 -> V_64 = NULL ;
F_45 ( & V_63 -> V_69 ) ;
F_35 ( V_63 -> V_70 ) ;
F_30 ( V_63 ) ;
}
if ( V_66 ) {
V_2 -> V_67 = NULL ;
F_46 ( V_66 ) ;
}
F_5 ( & V_33 -> V_43 ) ;
V_68 = F_41 ( V_8 , V_2 , V_55 ) ;
F_7 ( & V_33 -> V_43 ) ;
if ( V_68 )
F_40 ( & V_8 -> V_71 ) ;
}
static void F_47 ( struct V_7 * V_8 ,
struct V_15 * V_15 , int V_25 )
{
struct V_32 * V_72 = F_25 ( V_15 ) ;
struct V_32 * V_29 = F_25 ( V_8 -> V_41 -> V_42 ) ;
int V_73 = 0 ;
F_5 ( & V_72 -> V_74 ) ;
if ( V_72 -> V_75 == 0 ) {
V_72 -> V_75 = V_25 ;
F_7 ( & V_72 -> V_74 ) ;
F_29 ( F_15 ( & V_72 -> V_76 ) ) ;
F_48 ( V_15 ) ;
F_5 ( & V_29 -> V_74 ) ;
if ( F_15 ( & V_8 -> V_21 ) )
V_73 = 1 ;
F_6 ( & V_72 -> V_76 , & V_8 -> V_21 ) ;
F_7 ( & V_29 -> V_74 ) ;
} else {
F_7 ( & V_72 -> V_74 ) ;
}
if ( V_73 > 0 )
F_40 ( & V_8 -> V_77 . V_54 ) ;
}
static struct V_7 * F_49 ( struct V_28 * V_28 )
{
struct V_32 * V_33 = F_25 ( V_28 -> V_42 ) ;
struct V_7 * V_8 ;
int V_9 ;
V_8 = F_20 ( sizeof( * V_8 ) , V_36 ) ;
if ( ! V_8 )
return NULL ;
V_8 -> V_41 = F_50 ( V_28 ) ;
F_51 ( & V_8 -> V_78 , 1 ) ;
V_8 -> V_19 = V_79 ;
V_8 -> V_27 = 1 ;
F_52 ( & V_8 -> V_71 ) ;
F_52 ( & V_8 -> V_53 . V_54 ) ;
F_52 ( & V_8 -> V_77 . V_54 ) ;
F_26 ( & V_8 -> V_20 ) ;
F_26 ( & V_8 -> V_58 ) ;
F_26 ( & V_8 -> V_21 ) ;
for ( V_9 = 0 ; V_9 < V_80 ; V_9 ++ ) {
F_26 ( & V_8 -> V_14 [ V_9 ] ) ;
F_53 ( & V_8 -> V_12 [ V_9 ] ) ;
}
F_51 ( & V_8 -> V_18 , 0 ) ;
F_5 ( & V_81 ) ;
V_33 -> V_82 = ++ V_83 ;
if ( F_21 ( ! V_83 ) )
V_33 -> V_82 = ++ V_83 ;
F_7 ( & V_81 ) ;
return V_8 ;
}
static inline void F_54 ( struct V_7 * V_8 )
{
F_29 ( V_8 -> V_41 ) ;
F_55 ( V_8 -> V_41 ) ;
F_30 ( V_8 ) ;
}
static inline struct V_7 * F_56 ( struct V_15 * V_84 )
{
struct V_32 * V_33 = F_25 ( V_84 ) ;
struct V_7 * V_8 = NULL ;
F_5 ( & V_33 -> V_43 ) ;
V_8 = V_33 -> V_85 ;
if ( V_8 )
F_27 ( & V_8 -> V_78 ) ;
F_7 ( & V_33 -> V_43 ) ;
return V_8 ;
}
static void F_57 ( struct V_7 * V_8 )
{
struct V_32 * V_33 = F_25 ( V_8 -> V_41 -> V_42 ) ;
if ( F_58 ( & V_8 -> V_78 , & V_33 -> V_43 ) ) {
struct V_50 * V_51 = F_37 ( V_8 -> V_41 -> V_42 ) ;
struct V_1 * V_2 , * V_48 ;
V_33 -> V_85 = NULL ;
F_7 ( & V_33 -> V_43 ) ;
F_29 ( F_59 ( & V_8 -> V_53 ) ) ;
F_29 ( F_59 ( & V_8 -> V_77 ) ) ;
F_29 ( V_8 -> V_86 == V_8 -> V_87 ) ;
F_29 ( ! F_14 ( V_8 ) ) ;
F_39 (entry, next, &sai->sai_entries,
se_list)
F_34 ( V_8 , V_2 ) ;
F_29 ( F_13 ( & V_8 -> V_18 ) == 0 ) ;
F_29 ( F_15 ( & V_8 -> V_21 ) ) ;
F_54 ( V_8 ) ;
F_31 ( & V_51 -> V_88 ) ;
}
}
static void F_60 ( struct V_15 * V_15 , struct V_7 * V_8 )
{
struct V_32 * V_33 = F_25 ( V_15 ) ;
T_1 V_25 = V_33 -> V_75 ;
int V_89 ;
F_29 ( F_15 ( & V_33 -> V_76 ) ) ;
if ( F_18 ( V_8 , V_25 + 1 ) ) {
V_33 -> V_75 = 0 ;
F_35 ( V_15 ) ;
return;
}
V_89 = F_61 ( & V_33 -> V_90 ) ;
if ( V_89 == 0 ) {
V_33 -> V_75 = 0 ;
F_35 ( V_15 ) ;
return;
}
if ( V_33 -> V_91 != 0 &&
F_62 ( F_63 ( - 1 ) , V_33 -> V_91 ) ) {
F_64 ( & V_33 -> V_90 ) ;
V_33 -> V_75 = 0 ;
F_35 ( V_15 ) ;
return;
}
F_23 ( V_38 , L_3
V_92 L_4 , F_65 ( & V_33 -> V_93 ) , V_25 ) ;
F_66 ( V_15 ) ;
V_33 -> V_75 = 0 ;
V_33 -> V_91 = F_67 () ;
F_64 ( & V_33 -> V_90 ) ;
F_23 ( V_38 , L_5
V_92 L_6 ,
F_65 ( & V_33 -> V_93 ) , V_25 , V_89 ) ;
F_35 ( V_15 ) ;
}
static void F_68 ( struct V_7 * V_8 ,
struct V_1 * V_2 )
{
struct V_15 * V_84 = V_8 -> V_41 -> V_42 ;
struct V_15 * V_72 ;
struct V_62 * V_63 ;
struct V_94 * V_95 ;
struct V_65 * V_66 ;
struct V_96 * V_97 ;
int V_89 = 0 ;
F_29 ( V_2 -> V_98 != 0 ) ;
V_63 = V_2 -> V_64 ;
V_95 = & V_63 -> V_69 ;
V_66 = V_2 -> V_67 ;
V_97 = F_69 ( & V_66 -> V_99 , & V_100 ) ;
if ( ! V_97 ) {
V_89 = - V_101 ;
goto V_102;
}
V_72 = V_2 -> V_46 ;
if ( ! V_72 ) {
F_29 ( F_70 ( & V_63 -> V_103 . V_104 ) ) ;
if ( V_97 -> V_105 & V_106 ) {
V_89 = - V_107 ;
goto V_102;
}
} else {
if ( F_21 ( ! F_71 ( & V_63 -> V_103 . V_104 , & V_97 -> V_108 ) ) ) {
V_2 -> V_46 = NULL ;
F_35 ( V_72 ) ;
V_72 = NULL ;
}
}
V_95 -> V_109 = V_2 -> V_98 ;
V_89 = F_72 ( F_73 ( V_84 ) , V_95 , F_74 ( V_84 ) , NULL ) ;
if ( V_89 != 1 ) {
V_89 = - V_107 ;
goto V_102;
}
V_89 = F_75 ( & V_72 , V_66 , V_84 -> V_110 , V_95 ) ;
if ( V_89 )
goto V_102;
F_23 ( V_38 , L_7 V_92 L_8 ,
F_76 ( V_72 -> V_110 , NULL , 0 ) ,
V_2 -> V_10 . V_31 , V_2 -> V_10 . V_30 ,
F_65 ( F_74 ( V_72 ) ) , V_72 ) ;
F_77 ( F_37 ( V_84 ) -> V_111 , V_72 , V_95 , NULL ) ;
V_2 -> V_46 = V_72 ;
if ( F_10 ( V_8 , V_72 ) )
F_47 ( V_8 , V_72 , V_2 -> V_39 ) ;
V_102:
F_44 ( V_8 , V_2 , V_89 ) ;
}
static void F_78 ( struct V_7 * V_8 )
{
struct V_32 * V_33 ;
V_33 = F_25 ( V_8 -> V_41 -> V_42 ) ;
while ( F_14 ( V_8 ) ) {
struct V_1 * V_2 ;
F_5 ( & V_33 -> V_43 ) ;
if ( F_21 ( ! F_14 ( V_8 ) ) ) {
F_7 ( & V_33 -> V_43 ) ;
break;
}
V_2 = F_79 ( V_8 -> V_20 . V_48 ,
struct V_1 , V_44 ) ;
F_9 ( & V_2 -> V_44 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_68 ( V_8 , V_2 ) ;
}
}
static int F_80 ( struct V_65 * V_66 ,
struct V_62 * V_63 , int V_89 )
{
struct V_94 * V_95 = & V_63 -> V_69 ;
struct V_15 * V_84 = V_63 -> V_70 ;
struct V_32 * V_33 = F_25 ( V_84 ) ;
struct V_7 * V_8 = V_33 -> V_85 ;
struct V_1 * V_2 = (struct V_1 * ) V_63 -> V_112 ;
T_2 * V_113 = NULL ;
T_1 V_114 = 0 ;
if ( F_81 ( V_95 , V_115 ) )
V_89 = - V_116 ;
F_29 ( V_8 ) ;
F_29 ( ! F_59 ( & V_8 -> V_53 ) ) ;
F_29 ( V_2 ) ;
F_23 ( V_38 , L_9 ,
V_2 -> V_10 . V_31 , V_2 -> V_10 . V_30 , V_89 ) ;
if ( V_89 ) {
F_45 ( V_95 ) ;
F_35 ( V_84 ) ;
F_30 ( V_63 ) ;
} else {
V_114 = V_95 -> V_109 ;
F_82 ( V_95 ) ;
}
F_5 ( & V_33 -> V_43 ) ;
if ( V_89 ) {
if ( F_41 ( V_8 , V_2 , V_89 ) )
V_113 = & V_8 -> V_71 ;
} else {
V_2 -> V_64 = V_63 ;
V_2 -> V_67 = F_83 ( V_66 ) ;
V_2 -> V_98 = V_114 ;
if ( ! F_14 ( V_8 ) )
V_113 = & V_8 -> V_53 . V_54 ;
F_6 ( & V_2 -> V_44 , & V_8 -> V_20 ) ;
}
V_8 -> V_87 ++ ;
if ( V_113 )
F_40 ( V_113 ) ;
F_7 ( & V_33 -> V_43 ) ;
return V_89 ;
}
static void F_84 ( struct V_62 * V_63 ,
struct V_117 * V_118 )
{
F_29 ( V_63 && V_118 ) ;
F_35 ( V_63 -> V_70 ) ;
F_30 ( V_63 ) ;
F_30 ( V_118 ) ;
}
static int F_85 ( struct V_15 * V_84 , struct V_15 * V_72 ,
struct V_1 * V_2 , struct V_62 * * V_119 ,
struct V_117 * * V_120 )
{
const struct V_45 * V_45 = & V_2 -> V_10 ;
struct V_62 * V_63 ;
struct V_117 * V_118 ;
struct V_121 * V_122 ;
V_118 = F_20 ( sizeof( * V_118 ) , V_36 ) ;
if ( ! V_118 )
return - V_37 ;
V_63 = F_20 ( sizeof( * V_63 ) , V_36 ) ;
if ( ! V_63 ) {
F_30 ( V_118 ) ;
return - V_37 ;
}
V_122 = F_86 ( & V_63 -> V_103 , V_84 , V_72 , V_45 -> V_30 ,
V_45 -> V_31 , 0 , V_123 , NULL ) ;
if ( F_87 ( V_122 ) ) {
F_30 ( V_118 ) ;
F_30 ( V_63 ) ;
return F_88 ( V_122 ) ;
}
V_63 -> V_69 . V_124 = V_125 ;
V_63 -> V_70 = F_48 ( V_84 ) ;
V_63 -> V_126 = F_80 ;
V_63 -> V_112 = V_2 ;
V_118 -> V_127 = V_128 ;
V_118 -> V_129 = F_89 ( & V_63 -> V_69 ) ;
V_118 -> V_130 = V_131 ;
V_118 -> V_132 = V_133 ;
V_118 -> V_134 = NULL ;
V_118 -> V_135 = NULL ;
* V_119 = V_63 ;
* V_120 = V_118 ;
return 0 ;
}
static int F_90 ( struct V_15 * V_84 , struct V_1 * V_2 )
{
struct V_62 * V_63 ;
struct V_117 * V_118 ;
int V_89 ;
V_89 = F_85 ( V_84 , NULL , V_2 , & V_63 , & V_118 ) ;
if ( V_89 )
return V_89 ;
V_89 = F_91 ( F_73 ( V_84 ) , V_63 , V_118 ) ;
if ( V_89 )
F_84 ( V_63 , V_118 ) ;
return V_89 ;
}
static int F_92 ( struct V_15 * V_84 , struct V_1 * V_2 ,
struct V_28 * V_28 )
{
struct V_15 * V_15 = V_42 ( V_28 ) ;
struct V_94 V_95 = { . V_124 = V_125 ,
. V_109 = 0 } ;
struct V_62 * V_63 ;
struct V_117 * V_118 ;
int V_89 ;
if ( F_21 ( ! V_15 ) )
return 1 ;
if ( F_93 ( V_28 ) )
return 1 ;
V_2 -> V_46 = F_48 ( V_15 ) ;
V_89 = F_72 ( F_73 ( V_84 ) , & V_95 , F_74 ( V_15 ) ,
NULL ) ;
if ( V_89 == 1 ) {
V_2 -> V_98 = V_95 . V_109 ;
F_45 ( & V_95 ) ;
return 1 ;
}
V_89 = F_85 ( V_84 , V_15 , V_2 , & V_63 , & V_118 ) ;
if ( V_89 ) {
V_2 -> V_46 = NULL ;
F_35 ( V_15 ) ;
return V_89 ;
}
V_89 = F_91 ( F_73 ( V_84 ) , V_63 , V_118 ) ;
if ( V_89 ) {
V_2 -> V_46 = NULL ;
F_35 ( V_15 ) ;
F_84 ( V_63 , V_118 ) ;
}
return V_89 ;
}
static void F_94 ( struct V_28 * V_29 , const char * V_30 , int V_31 )
{
struct V_15 * V_84 = V_42 ( V_29 ) ;
struct V_32 * V_33 = F_25 ( V_84 ) ;
struct V_7 * V_8 = V_33 -> V_85 ;
struct V_28 * V_28 = NULL ;
struct V_1 * V_2 ;
int V_89 ;
V_2 = F_19 ( V_29 , V_8 , V_8 -> V_27 , V_30 , V_31 ) ;
if ( F_87 ( V_2 ) )
return;
V_28 = F_95 ( V_29 , & V_2 -> V_10 ) ;
if ( ! V_28 ) {
V_89 = F_90 ( V_84 , V_2 ) ;
} else {
V_89 = F_92 ( V_84 , V_2 , V_28 ) ;
if ( V_89 == 1 && F_10 ( V_8 , V_42 ( V_28 ) ) )
F_47 ( V_8 , V_42 ( V_28 ) , V_2 -> V_39 ) ;
}
if ( V_28 )
F_55 ( V_28 ) ;
if ( V_89 )
F_44 ( V_8 , V_2 , V_89 ) ;
else
V_8 -> V_86 ++ ;
V_8 -> V_27 ++ ;
}
static int F_96 ( void * V_136 )
{
struct V_28 * V_29 = V_136 ;
struct V_15 * V_84 = V_42 ( V_29 ) ;
struct V_32 * V_137 = F_25 ( V_84 ) ;
struct V_32 * V_138 ;
struct V_50 * V_51 = F_37 ( V_84 ) ;
struct V_7 * V_8 ;
struct V_139 * V_140 ;
struct V_141 V_142 = { 0 } ;
V_8 = F_56 ( V_84 ) ;
V_140 = & V_8 -> V_77 ;
V_140 -> V_143 = F_97 () ;
F_23 ( V_38 , L_10 ,
V_8 , V_29 ) ;
F_27 ( & V_51 -> V_144 ) ;
F_5 ( & V_137 -> V_74 ) ;
V_8 -> V_17 = 1 ;
if ( F_98 ( V_140 ) )
F_99 ( V_140 , V_145 ) ;
F_7 ( & V_137 -> V_74 ) ;
F_40 ( & V_140 -> V_54 ) ;
while ( 1 ) {
F_100 ( V_140 -> V_54 ,
! F_15 ( & V_8 -> V_21 ) ||
! F_101 ( V_140 ) ,
& V_142 ) ;
if ( ! F_101 ( V_140 ) )
break;
F_5 ( & V_137 -> V_74 ) ;
if ( ! F_15 ( & V_8 -> V_21 ) ) {
V_138 = F_79 ( V_8 -> V_21 . V_48 ,
struct V_32 , V_76 ) ;
F_9 ( & V_138 -> V_76 ) ;
F_7 ( & V_137 -> V_74 ) ;
F_60 ( & V_138 -> V_146 , V_8 ) ;
} else {
F_7 ( & V_137 -> V_74 ) ;
}
}
F_5 ( & V_137 -> V_74 ) ;
V_8 -> V_17 = 0 ;
while ( ! F_15 ( & V_8 -> V_21 ) ) {
V_138 = F_79 ( V_8 -> V_21 . V_48 ,
struct V_32 , V_76 ) ;
F_9 ( & V_138 -> V_76 ) ;
F_7 ( & V_137 -> V_74 ) ;
V_138 -> V_75 = 0 ;
F_35 ( & V_138 -> V_146 ) ;
F_5 ( & V_137 -> V_74 ) ;
}
F_99 ( V_140 , V_147 ) ;
F_7 ( & V_137 -> V_74 ) ;
F_40 ( & V_140 -> V_54 ) ;
F_57 ( V_8 ) ;
F_23 ( V_38 , L_11 ,
V_8 , V_29 ) ;
return 0 ;
}
static void F_102 ( struct V_28 * V_29 , struct V_7 * V_8 )
{
struct V_139 * V_140 = & V_8 -> V_77 ;
struct V_141 V_142 = { 0 } ;
struct V_32 * V_137 ;
struct V_148 * V_149 ;
F_23 ( V_38 , L_12 ,
V_8 , V_29 ) ;
V_137 = F_25 ( V_42 ( V_29 ) ) ;
V_149 = F_103 ( F_96 , V_29 , L_13 ,
V_137 -> V_150 ) ;
if ( F_87 ( V_149 ) ) {
F_104 ( L_14 , F_88 ( V_149 ) ) ;
F_99 ( V_140 , V_147 ) ;
return;
}
F_100 ( V_140 -> V_54 ,
F_101 ( V_140 ) || F_59 ( V_140 ) ,
& V_142 ) ;
}
static int F_105 ( void * V_136 )
{
struct V_28 * V_29 = V_136 ;
struct V_15 * V_84 = V_42 ( V_29 ) ;
struct V_32 * V_33 = F_25 ( V_84 ) ;
struct V_50 * V_51 = F_37 ( V_84 ) ;
struct V_7 * V_8 ;
struct V_139 * V_151 ;
struct V_139 * V_152 ;
struct V_153 * V_153 = NULL ;
T_1 V_57 = 0 ;
int V_154 = 0 ;
int V_89 = 0 ;
struct V_121 * V_122 ;
struct V_141 V_142 = { 0 } ;
V_8 = F_56 ( V_84 ) ;
V_151 = & V_8 -> V_53 ;
V_152 = & V_8 -> V_77 ;
V_151 -> V_143 = F_97 () ;
F_23 ( V_38 , L_15 ,
V_8 , V_29 ) ;
V_122 = F_86 ( NULL , V_84 , V_84 , NULL , 0 , 0 ,
V_123 , V_84 ) ;
if ( F_87 ( V_122 ) ) {
V_89 = F_88 ( V_122 ) ;
goto V_102;
}
V_122 -> V_155 = F_37 ( V_84 ) -> V_156 ;
if ( V_51 -> V_157 & V_158 )
F_102 ( V_29 , V_8 ) ;
F_27 ( & V_51 -> V_159 ) ;
F_5 ( & V_33 -> V_43 ) ;
if ( F_98 ( V_151 ) )
F_99 ( V_151 , V_145 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_40 ( & V_151 -> V_54 ) ;
while ( V_57 != V_160 && F_101 ( V_151 ) ) {
struct V_161 * V_162 ;
struct V_163 * V_164 ;
V_8 -> V_165 = 1 ;
V_153 = F_106 ( V_84 , V_122 , V_57 ) ;
V_8 -> V_165 = 0 ;
if ( F_87 ( V_153 ) ) {
V_89 = F_88 ( V_153 ) ;
F_23 ( V_38 , L_16 V_92 L_17 ,
F_65 ( F_74 ( V_84 ) ) , V_57 , V_8 -> V_27 ,
V_33 -> V_150 , V_89 ) ;
break;
}
V_162 = F_107 ( V_153 ) ;
for ( V_164 = F_108 ( V_162 ) ;
V_164 && F_101 ( V_151 ) && ! F_17 ( V_8 ) ;
V_164 = F_109 ( V_164 ) ) {
T_1 V_11 ;
int V_166 ;
char * V_30 ;
V_11 = F_110 ( V_164 -> V_167 ) ;
if ( F_21 ( V_11 < V_57 ) )
continue;
V_166 = F_111 ( V_164 -> V_168 ) ;
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
do {
F_100 ( V_151 -> V_54 ,
! F_12 ( V_8 ) ||
F_14 ( V_8 ) ||
! F_15 ( & V_8 -> V_21 ) ||
! F_101 ( V_151 ) ,
& V_142 ) ;
F_78 ( V_8 ) ;
F_5 ( & V_33 -> V_74 ) ;
while ( F_12 ( V_8 ) &&
! F_16 ( V_8 ) ) {
struct V_32 * V_138 ;
V_138 = F_79 ( V_8 -> V_21 . V_48 ,
struct V_32 , V_76 ) ;
F_9 ( & V_138 -> V_76 ) ;
F_7 ( & V_33 -> V_74 ) ;
F_60 ( & V_138 -> V_146 ,
V_8 ) ;
F_5 ( & V_33 -> V_74 ) ;
}
F_7 ( & V_33 -> V_74 ) ;
} while ( F_12 ( V_8 ) &&
F_101 ( V_151 ) );
F_94 ( V_29 , V_30 , V_166 ) ;
}
V_57 = F_110 ( V_162 -> V_172 ) ;
F_112 ( V_84 , V_153 ,
F_113 ( V_162 -> V_173 ) & V_174 ) ;
if ( F_17 ( V_8 ) ) {
V_89 = - V_101 ;
F_27 ( & V_51 -> V_175 ) ;
F_23 ( V_38 , L_18 V_92 L_19 ,
F_65 ( & V_33 -> V_93 ) , V_8 -> V_22 ,
V_8 -> V_23 , V_8 -> V_86 ,
V_8 -> V_87 , F_97 () ) ;
break;
}
}
F_114 ( V_122 ) ;
if ( V_89 < 0 ) {
F_5 ( & V_33 -> V_43 ) ;
F_99 ( V_151 , V_176 ) ;
V_33 -> V_177 = 0 ;
F_7 ( & V_33 -> V_43 ) ;
}
while ( F_101 ( V_151 ) ) {
F_100 ( V_151 -> V_54 ,
F_14 ( V_8 ) ||
! F_16 ( V_8 ) ||
! F_101 ( V_151 ) ,
& V_142 ) ;
F_78 ( V_8 ) ;
}
V_102:
if ( V_8 -> V_17 ) {
F_5 ( & V_33 -> V_74 ) ;
F_99 ( V_152 , V_176 ) ;
F_7 ( & V_33 -> V_74 ) ;
F_40 ( & V_152 -> V_54 ) ;
F_23 ( V_38 , L_20 ,
V_8 , ( unsigned int ) V_152 -> V_143 ) ;
F_100 ( V_152 -> V_54 ,
F_59 ( V_152 ) ,
& V_142 ) ;
} else {
F_99 ( V_152 , V_147 ) ;
}
while ( V_8 -> V_86 != V_8 -> V_87 ) {
V_142 = F_115 ( F_116 ( V_178 >> 3 ) ,
NULL , NULL ) ;
F_100 ( V_151 -> V_54 ,
V_8 -> V_86 == V_8 -> V_87 , & V_142 ) ;
}
F_78 ( V_8 ) ;
F_5 ( & V_33 -> V_43 ) ;
F_99 ( V_151 , V_147 ) ;
F_7 ( & V_33 -> V_43 ) ;
F_23 ( V_38 , L_21 ,
V_8 , V_29 ) ;
F_40 ( & V_8 -> V_71 ) ;
F_40 ( & V_151 -> V_54 ) ;
F_57 ( V_8 ) ;
return V_89 ;
}
void F_117 ( struct V_15 * V_84 , void * V_179 )
{
struct V_32 * V_33 = F_25 ( V_84 ) ;
F_5 ( & V_33 -> V_43 ) ;
if ( ! V_33 -> V_180 && ! V_33 -> V_85 ) {
F_29 ( ! V_33 -> V_150 ) ;
V_33 -> V_180 = V_179 ;
V_33 -> V_150 = F_97 () ;
V_33 -> V_177 = 1 ;
}
F_7 ( & V_33 -> V_43 ) ;
}
void F_118 ( struct V_15 * V_84 , void * V_179 )
{
struct V_32 * V_33 = F_25 ( V_84 ) ;
struct V_7 * V_8 ;
F_29 ( V_33 -> V_180 == V_179 ) ;
F_29 ( V_33 -> V_150 ) ;
F_23 ( V_38 , L_22 V_92 L_23 ,
F_65 ( & V_33 -> V_93 ) ) ;
F_5 ( & V_33 -> V_43 ) ;
V_33 -> V_180 = NULL ;
V_33 -> V_150 = 0 ;
V_33 -> V_177 = 0 ;
V_8 = V_33 -> V_85 ;
if ( V_8 && F_101 ( & V_8 -> V_53 ) ) {
F_99 ( & V_8 -> V_53 , V_176 ) ;
F_40 ( & V_8 -> V_53 . V_54 ) ;
}
F_7 ( & V_33 -> V_43 ) ;
}
static int F_119 ( struct V_15 * V_84 , struct V_28 * V_28 )
{
const struct V_45 * V_181 = & V_28 -> V_182 ;
struct V_121 * V_122 ;
struct V_153 * V_153 ;
T_1 V_57 = 0 ;
int V_183 ;
int V_89 = V_184 ;
V_122 = F_86 ( NULL , V_84 , V_84 , NULL , 0 , 0 ,
V_123 , V_84 ) ;
if ( F_87 ( V_122 ) )
return F_88 ( V_122 ) ;
V_122 -> V_155 = F_37 ( V_84 ) -> V_156 ;
V_153 = F_106 ( V_84 , V_122 , V_57 ) ;
while ( 1 ) {
struct V_161 * V_162 ;
struct V_163 * V_164 ;
if ( F_87 ( V_153 ) ) {
struct V_32 * V_33 = F_25 ( V_84 ) ;
V_89 = F_88 ( V_153 ) ;
F_104 ( L_24 V_92 L_25 ,
F_76 ( V_84 -> V_110 , NULL , 0 ) ,
F_65 ( F_74 ( V_84 ) ) , V_57 ,
V_33 -> V_150 , V_89 ) ;
break;
}
V_162 = F_107 ( V_153 ) ;
for ( V_164 = F_108 ( V_162 ) ; V_164 ;
V_164 = F_109 ( V_164 ) ) {
T_1 V_11 ;
int V_166 ;
char * V_30 ;
V_11 = F_110 ( V_164 -> V_167 ) ;
if ( F_21 ( V_11 < V_57 ) )
continue;
V_166 = F_111 ( V_164 -> V_168 ) ;
if ( F_21 ( V_166 == 0 ) )
continue;
V_30 = V_164 -> V_169 ;
if ( V_30 [ 0 ] == '.' ) {
if ( V_166 == 1 )
continue;
else if ( V_30 [ 1 ] == '.' && V_166 == 2 )
continue;
else
V_183 = 1 ;
} else {
V_183 = 0 ;
}
if ( V_183 && V_181 -> V_30 [ 0 ] != '.' ) {
F_23 ( V_38 , L_26 ,
V_181 -> V_31 , V_181 -> V_30 ,
V_166 , V_30 ) ;
continue;
}
if ( V_181 -> V_31 != V_166 ||
memcmp ( V_181 -> V_30 , V_30 , V_166 ) != 0 )
V_89 = V_184 ;
else if ( ! V_183 )
V_89 = V_185 ;
else
V_89 = V_186 ;
F_112 ( V_84 , V_153 , false ) ;
goto V_102;
}
V_57 = F_110 ( V_162 -> V_172 ) ;
if ( V_57 == V_160 ) {
F_112 ( V_84 , V_153 , false ) ;
goto V_102;
} else {
F_112 ( V_84 , V_153 ,
F_113 ( V_162 -> V_173 ) &
V_174 ) ;
V_153 = F_106 ( V_84 , V_122 , V_57 ) ;
}
}
V_102:
F_114 ( V_122 ) ;
return V_89 ;
}
static int F_120 ( struct V_15 * V_84 ,
struct V_7 * V_8 ,
struct V_28 * * V_187 ,
bool V_188 )
{
struct V_32 * V_33 = F_25 ( V_84 ) ;
struct V_1 * V_2 = NULL ;
struct V_141 V_142 = { 0 } ;
struct V_189 * V_190 ;
int V_89 = 0 ;
if ( ( * V_187 ) -> V_182 . V_30 [ 0 ] == '.' ) {
if ( V_8 -> V_170 ||
V_8 -> V_191 >= V_8 -> V_171 ) {
} else {
if ( ! V_8 -> V_170 )
V_8 -> V_170 = 1 ;
V_8 -> V_191 ++ ;
return - V_107 ;
}
}
if ( V_188 ) {
V_89 = 1 ;
goto V_192;
}
V_2 = F_32 ( V_8 , & ( * V_187 ) -> V_182 ) ;
if ( ! V_2 ) {
V_89 = - V_107 ;
goto V_192;
}
if ( ! F_1 ( V_2 ) && V_8 -> V_165 )
F_78 ( V_8 ) ;
if ( ! F_1 ( V_2 ) ) {
F_5 ( & V_33 -> V_43 ) ;
V_8 -> V_61 = V_2 -> V_39 ;
F_7 ( & V_33 -> V_43 ) ;
V_142 = F_121 ( F_122 ( 30 ) , NULL ,
V_193 , NULL ) ;
V_89 = F_100 ( V_8 -> V_71 , F_1 ( V_2 ) , & V_142 ) ;
if ( V_89 < 0 ) {
V_2 = NULL ;
V_89 = - V_107 ;
goto V_192;
}
}
if ( V_2 -> V_3 == V_49 && V_2 -> V_46 ) {
struct V_15 * V_15 = V_2 -> V_46 ;
struct V_94 V_95 = { . V_124 = V_125 ,
. V_109 = V_2 -> V_98 } ;
T_1 V_194 ;
V_89 = F_72 ( F_73 ( V_84 ) , & V_95 ,
F_74 ( V_15 ) , & V_194 ) ;
if ( V_89 == 1 ) {
if ( ! ( * V_187 ) -> V_42 ) {
struct V_28 * V_195 ;
V_195 = F_123 ( V_15 , * V_187 ) ;
if ( F_87 ( V_195 ) ) {
F_45 ( & V_95 ) ;
V_89 = F_88 ( V_195 ) ;
goto V_192;
}
* V_187 = V_195 ;
V_2 -> V_46 = NULL ;
} else if ( ( * V_187 ) -> V_42 != V_15 ) {
F_23 ( V_38 ,
L_27 V_92 L_28 V_92 L_23 ,
F_76 ( ( * V_187 ) -> V_42 -> V_110 ,
NULL , 0 ) ,
* V_187 ,
F_65 ( F_74 ( ( * V_187 ) -> V_42 ) ) ,
F_65 ( F_74 ( V_15 ) ) ) ;
F_45 ( & V_95 ) ;
V_89 = - V_196 ;
goto V_192;
}
if ( ( V_194 & V_197 ) &&
F_124 ( * V_187 ) )
F_125 ( * V_187 ) ;
F_45 ( & V_95 ) ;
}
}
V_192:
V_190 = F_126 ( * V_187 ) ;
V_190 -> V_198 = V_33 -> V_82 ;
F_36 ( V_8 , V_2 ) ;
return V_89 ;
}
static int F_127 ( struct V_15 * V_84 , struct V_28 * V_28 )
{
struct V_32 * V_33 = F_25 ( V_84 ) ;
struct V_7 * V_8 = NULL ;
struct V_141 V_142 = { 0 } ;
struct V_139 * V_140 ;
struct V_148 * V_149 ;
struct V_28 * V_29 = V_28 -> V_199 ;
int V_89 ;
V_89 = F_119 ( V_84 , V_28 ) ;
if ( V_89 == V_184 ) {
V_89 = - V_101 ;
goto V_102;
}
V_8 = F_49 ( V_29 ) ;
if ( ! V_8 ) {
V_89 = - V_37 ;
goto V_102;
}
V_8 -> V_170 = ( V_89 == V_186 ) ;
F_5 ( & V_33 -> V_43 ) ;
if ( F_21 ( V_33 -> V_85 || V_33 -> V_180 ||
V_33 -> V_150 != V_200 -> V_201 ) ) {
F_7 ( & V_33 -> V_43 ) ;
V_89 = - V_202 ;
goto V_102;
}
V_33 -> V_85 = V_8 ;
F_7 ( & V_33 -> V_43 ) ;
F_27 ( & F_37 ( V_29 -> V_42 ) -> V_88 ) ;
F_23 ( V_38 , L_29 ,
F_97 () , V_29 ) ;
V_149 = F_103 ( F_105 , V_29 , L_30 ,
V_33 -> V_150 ) ;
V_140 = & V_8 -> V_53 ;
if ( F_87 ( V_149 ) ) {
V_89 = F_88 ( V_149 ) ;
F_104 ( L_31 , V_89 ) ;
goto V_102;
}
F_100 ( V_140 -> V_54 ,
F_101 ( V_140 ) || F_59 ( V_140 ) ,
& V_142 ) ;
F_57 ( V_8 ) ;
return - V_107 ;
V_102:
F_5 ( & V_33 -> V_43 ) ;
V_33 -> V_177 = 0 ;
V_33 -> V_85 = NULL ;
F_7 ( & V_33 -> V_43 ) ;
if ( V_8 )
F_54 ( V_8 ) ;
return V_89 ;
}
int F_128 ( struct V_15 * V_84 , struct V_28 * * V_187 , bool V_188 )
{
struct V_7 * V_8 ;
V_8 = F_56 ( V_84 ) ;
if ( V_8 ) {
int V_89 ;
V_89 = F_120 ( V_84 , V_8 , V_187 , V_188 ) ;
F_23 ( V_38 , L_32 ,
* V_187 , V_89 ) ;
F_57 ( V_8 ) ;
return V_89 ;
}
return F_127 ( V_84 , * V_187 ) ;
}
