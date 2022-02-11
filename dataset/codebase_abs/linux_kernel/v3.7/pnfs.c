static struct V_1 *
F_1 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_2 (local, &pnfs_modules_tbl, pnfs_tblid)
if ( V_3 -> V_2 == V_2 )
goto V_4;
V_3 = NULL ;
V_4:
F_3 ( L_1 , V_5 , V_2 , V_3 ) ;
return V_3 ;
}
static struct V_1 *
F_4 ( T_1 V_2 )
{
struct V_1 * V_3 ;
F_5 ( & V_6 ) ;
V_3 = F_1 ( V_2 ) ;
if ( V_3 != NULL && ! F_6 ( V_3 -> V_7 ) ) {
F_3 ( L_2 , V_5 ) ;
V_3 = NULL ;
}
F_7 ( & V_6 ) ;
return V_3 ;
}
void
F_8 ( struct V_8 * V_9 )
{
if ( V_9 -> V_10 ) {
if ( V_9 -> V_10 -> V_11 )
V_9 -> V_10 -> V_11 ( V_9 ) ;
if ( F_9 ( & V_9 -> V_12 -> V_13 ) )
F_10 ( V_9 -> V_12 ) ;
F_11 ( V_9 -> V_10 -> V_7 ) ;
}
V_9 -> V_10 = NULL ;
}
void
F_12 ( struct V_8 * V_14 , const struct V_15 * V_16 ,
T_1 V_2 )
{
struct V_1 * V_17 = NULL ;
if ( V_2 == 0 )
goto V_18;
if ( ! ( V_14 -> V_12 -> V_19 &
( V_20 | V_21 ) ) ) {
F_13 ( V_22 L_3 ,
V_5 , V_2 , V_14 -> V_12 -> V_19 ) ;
goto V_18;
}
V_17 = F_4 ( V_2 ) ;
if ( ! V_17 ) {
F_14 ( L_4 , V_23 , V_2 ) ;
V_17 = F_4 ( V_2 ) ;
if ( ! V_17 ) {
F_3 ( L_5 ,
V_5 , V_2 ) ;
goto V_18;
}
}
V_14 -> V_10 = V_17 ;
if ( V_17 -> V_24
&& V_17 -> V_24 ( V_14 , V_16 ) ) {
F_13 ( V_22 L_6
L_7 , V_5 , V_2 ) ;
F_11 ( V_17 -> V_7 ) ;
goto V_18;
}
F_15 ( & V_14 -> V_12 -> V_13 ) ;
F_3 ( L_8 , V_5 , V_2 ) ;
return;
V_18:
F_3 ( L_9 , V_5 ) ;
V_14 -> V_10 = NULL ;
}
int
F_16 ( struct V_1 * V_17 )
{
int V_25 = - V_26 ;
struct V_1 * V_27 ;
if ( V_17 -> V_2 == 0 ) {
F_13 ( V_22 L_10 , V_5 ) ;
return V_25 ;
}
if ( ! V_17 -> V_28 || ! V_17 -> V_29 ) {
F_13 ( V_22 L_11
L_12 , V_5 ) ;
return V_25 ;
}
F_5 ( & V_6 ) ;
V_27 = F_1 ( V_17 -> V_2 ) ;
if ( ! V_27 ) {
F_17 ( & V_17 -> V_30 , & V_31 ) ;
V_25 = 0 ;
F_3 ( L_13 , V_5 , V_17 -> V_2 ,
V_17 -> V_32 ) ;
} else {
F_13 ( V_22 L_14 ,
V_5 , V_17 -> V_2 ) ;
}
F_7 ( & V_6 ) ;
return V_25 ;
}
void
F_18 ( struct V_1 * V_17 )
{
F_3 ( L_15 , V_5 , V_17 -> V_2 ) ;
F_5 ( & V_6 ) ;
F_19 ( & V_17 -> V_30 ) ;
F_7 ( & V_6 ) ;
}
void
F_20 ( struct V_33 * V_34 )
{
F_15 ( & V_34 -> V_35 ) ;
}
static struct V_33 *
F_21 ( struct V_36 * V_37 , T_2 V_38 )
{
struct V_1 * V_39 = F_22 ( V_37 ) -> V_10 ;
return V_39 -> V_40 ( V_37 , V_38 ) ;
}
static void
F_23 ( struct V_33 * V_34 )
{
struct V_8 * V_14 = F_22 ( V_34 -> V_41 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( ! F_24 ( & V_34 -> V_42 ) ) {
struct V_12 * V_43 = V_14 -> V_12 ;
F_5 ( & V_43 -> V_44 ) ;
F_25 ( & V_34 -> V_42 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
F_26 ( V_34 -> V_45 ) ;
return V_39 -> V_46 ( V_34 ) ;
}
static void
F_27 ( struct V_33 * V_34 )
{
struct V_47 * V_48 = F_28 ( V_34 -> V_41 ) ;
F_3 ( L_16 , V_5 , V_34 ) ;
V_48 -> V_49 = NULL ;
V_48 -> V_50 = 0 ;
V_48 -> V_51 = 0 ;
}
void
F_29 ( struct V_33 * V_34 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
if ( F_30 ( & V_34 -> V_35 , & V_36 -> V_52 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_23 ( V_34 ) ;
}
}
static int
F_31 ( T_1 V_53 )
{
return V_53 == V_54 ?
V_55 : V_56 ;
}
static void
F_32 ( struct V_33 * V_34 , int V_57 )
{
V_34 -> V_58 = V_59 ;
if ( F_33 ( V_57 , & V_34 -> V_60 ) )
F_15 ( & V_34 -> V_35 ) ;
}
static void
F_34 ( struct V_33 * V_34 , int V_57 )
{
if ( F_35 ( V_57 , & V_34 -> V_60 ) )
F_36 ( & V_34 -> V_35 ) ;
}
static void
F_37 ( struct V_33 * V_34 , T_1 V_53 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
struct V_61 V_62 = {
. V_53 = V_53 ,
. V_63 = 0 ,
. V_64 = V_65 ,
} ;
F_38 ( V_66 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_32 ( V_34 , F_31 ( V_53 ) ) ;
F_39 ( V_34 , & V_66 , & V_62 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_40 ( & V_66 ) ;
F_3 ( L_17 , V_5 ,
V_53 == V_54 ? L_18 : L_19 ) ;
}
static bool
F_41 ( struct V_33 * V_34 , T_1 V_53 )
{
unsigned long V_67 , V_68 ;
int V_57 = F_31 ( V_53 ) ;
if ( F_42 ( V_57 , & V_34 -> V_60 ) == 0 )
return false ;
V_68 = V_59 ;
V_67 = V_68 - V_69 ;
if ( ! F_43 ( V_34 -> V_58 , V_67 , V_68 ) ) {
F_34 ( V_34 , V_57 ) ;
return false ;
}
return true ;
}
static void
F_44 ( struct V_33 * V_34 , struct V_70 * V_71 )
{
F_45 ( & V_71 -> V_72 ) ;
F_45 ( & V_71 -> V_73 ) ;
F_46 ( & V_71 -> V_74 , 1 ) ;
F_47 () ;
F_48 ( V_75 , & V_71 -> V_76 ) ;
V_71 -> V_77 = V_34 ;
}
static void F_49 ( struct V_70 * V_71 )
{
struct V_36 * V_37 = V_71 -> V_77 -> V_41 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_71 ) ;
}
static void
F_50 ( struct V_33 * V_34 ,
struct V_70 * V_71 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
F_51 ( F_42 ( V_75 , & V_71 -> V_76 ) ) ;
F_25 ( & V_71 -> V_72 ) ;
F_36 ( & V_34 -> V_35 ) ;
if ( F_24 ( & V_34 -> V_78 ) )
F_52 ( V_79 , & V_34 -> V_60 ) ;
F_53 ( & F_22 ( V_36 ) -> V_80 ) ;
}
void
F_54 ( struct V_70 * V_71 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
if ( ! V_71 )
return;
F_3 ( L_20 , V_5 , V_71 ,
F_55 ( & V_71 -> V_74 ) ,
F_42 ( V_75 , & V_71 -> V_76 ) ) ;
V_34 = V_71 -> V_77 ;
V_36 = V_34 -> V_41 ;
if ( F_30 ( & V_71 -> V_74 , & V_36 -> V_52 ) ) {
F_20 ( V_34 ) ;
F_50 ( V_34 , V_71 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_49 ( V_71 ) ;
F_29 ( V_34 ) ;
}
}
static inline T_3
F_56 ( T_3 V_67 , T_3 V_81 )
{
T_3 V_68 ;
V_68 = V_67 + V_81 ;
return V_68 >= V_67 ? V_68 : V_65 ;
}
static inline T_3
F_57 ( T_3 V_67 , T_3 V_81 )
{
T_3 V_68 ;
F_58 ( ! V_81 ) ;
V_68 = V_67 + V_81 ;
return V_68 > V_67 ? V_68 - 1 : V_65 ;
}
static inline int
F_59 ( struct V_61 * V_82 ,
struct V_61 * V_83 )
{
T_3 V_84 = V_82 -> V_63 ;
T_3 V_85 = F_56 ( V_84 , V_82 -> V_64 ) ;
T_3 V_86 = V_83 -> V_63 ;
T_3 V_87 = F_56 ( V_86 , V_83 -> V_64 ) ;
return ( V_84 <= V_86 ) && ( V_85 >= V_87 ) ;
}
static inline int
F_60 ( struct V_61 * V_82 ,
struct V_61 * V_83 )
{
T_3 V_84 = V_82 -> V_63 ;
T_3 V_85 = F_56 ( V_84 , V_82 -> V_64 ) ;
T_3 V_86 = V_83 -> V_63 ;
T_3 V_87 = F_56 ( V_86 , V_83 -> V_64 ) ;
return ( V_85 == V_65 || V_85 > V_86 ) &&
( V_87 == V_65 || V_87 > V_84 ) ;
}
static bool
F_61 ( struct V_61 * V_88 ,
struct V_61 * V_89 )
{
return ( V_89 -> V_53 == V_90 ||
V_88 -> V_53 == V_89 -> V_53 ) &&
F_60 ( V_88 , V_89 ) ;
}
static int F_62 ( struct V_70 * V_71 ,
struct V_91 * V_92 )
{
int V_93 = 0 ;
if ( F_35 ( V_75 , & V_71 -> V_76 ) ) {
F_3 ( L_21 , V_5 , V_71 ,
F_55 ( & V_71 -> V_74 ) ) ;
if ( F_9 ( & V_71 -> V_74 ) ) {
F_50 ( V_71 -> V_77 , V_71 ) ;
F_17 ( & V_71 -> V_72 , V_92 ) ;
V_93 = 1 ;
}
}
return V_93 ;
}
int
F_39 ( struct V_33 * V_34 ,
struct V_91 * V_92 ,
struct V_61 * V_89 )
{
struct V_70 * V_71 , * V_94 ;
int V_95 = 0 , V_96 = 0 ;
F_3 ( L_22 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_78 ) )
return 0 ;
F_63 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_89 ||
F_61 ( & V_71 -> V_97 , V_89 ) ) {
F_3 ( L_23
L_24 , V_5 ,
V_71 , V_71 -> V_97 . V_53 , V_71 -> V_97 . V_63 ,
V_71 -> V_97 . V_64 ) ;
V_95 ++ ;
V_96 += F_62 ( V_71 , V_92 ) ;
}
F_3 ( L_25 , V_5 , V_95 - V_96 ) ;
return V_95 - V_96 ;
}
void
F_40 ( struct V_91 * V_98 )
{
struct V_70 * V_71 , * V_27 ;
if ( F_24 ( V_98 ) )
return;
F_63 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_71 -> V_72 ) ;
F_49 ( V_71 ) ;
}
}
void
F_64 ( struct V_47 * V_48 )
{
struct V_33 * V_34 ;
F_38 ( V_92 ) ;
F_5 ( & V_48 -> V_99 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
V_34 -> V_100 ++ ;
F_39 ( V_34 , & V_92 , NULL ) ;
F_20 ( V_34 ) ;
F_34 ( V_34 , V_56 ) ;
F_34 ( V_34 , V_55 ) ;
F_7 ( & V_48 -> V_99 . V_52 ) ;
F_40 ( & V_92 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_99 . V_52 ) ;
}
void
F_65 ( struct V_12 * V_43 )
{
struct V_8 * V_14 ;
struct V_33 * V_34 ;
F_38 ( V_92 ) ;
F_66 ( V_43 ) ;
F_10 ( V_43 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_67 () ;
F_68 (server, &clp->cl_superblocks, client_link) {
if ( ! F_24 ( & V_14 -> V_101 ) )
F_69 ( & V_14 -> V_101 , & V_92 ) ;
}
F_70 () ;
F_7 ( & V_43 -> V_44 ) ;
while ( ! F_24 ( & V_92 ) ) {
V_34 = F_71 ( V_92 . V_94 , struct V_33 ,
V_42 ) ;
F_3 ( L_26 , V_5 ,
V_34 -> V_41 -> V_102 ) ;
F_25 ( & V_34 -> V_42 ) ;
F_64 ( F_28 ( V_34 -> V_41 ) ) ;
}
}
static bool F_72 ( T_1 V_103 , T_1 V_104 )
{
return ( V_105 ) V_103 - ( V_105 ) V_104 > 0 ;
}
void
F_73 ( struct V_33 * V_34 , const T_4 * V_106 ,
bool V_107 )
{
T_1 V_108 , V_109 , V_110 ;
int V_111 = F_24 ( & V_34 -> V_78 ) ;
V_108 = F_74 ( V_34 -> V_112 . V_113 ) ;
V_109 = F_74 ( V_106 -> V_113 ) ;
if ( V_111 || F_72 ( V_109 , V_108 ) ) {
F_75 ( & V_34 -> V_112 , V_106 ) ;
if ( V_107 ) {
V_110 = F_74 ( V_106 -> V_113 ) ;
} else {
V_110 = V_109 - F_55 ( & V_34 -> V_114 ) ;
}
if ( V_111 || F_72 ( V_110 , V_34 -> V_115 ) )
V_34 -> V_115 = V_110 ;
}
}
static bool
F_76 ( const struct V_33 * V_34 ,
const T_4 * V_116 )
{
T_1 V_113 = F_74 ( V_116 -> V_113 ) ;
return ! F_72 ( V_113 , V_34 -> V_115 ) ;
}
static bool
F_77 ( const struct V_33 * V_34 , int V_117 )
{
return V_34 -> V_100 ||
F_42 ( V_79 , & V_34 -> V_60 ) ||
( F_24 ( & V_34 -> V_78 ) &&
( F_55 ( & V_34 -> V_114 ) > V_117 ) ) ;
}
int
F_78 ( T_4 * V_118 , struct V_33 * V_34 ,
struct V_119 * V_120 )
{
int V_25 = 0 ;
F_3 ( L_27 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_77 ( V_34 , 1 ) ) {
V_25 = - V_121 ;
} else if ( F_24 ( & V_34 -> V_78 ) ) {
int V_122 ;
do {
V_122 = F_79 ( & V_120 -> V_123 ) ;
F_75 ( V_118 , & V_120 -> V_116 ) ;
} while ( F_80 ( & V_120 -> V_123 , V_122 ) );
} else
F_75 ( V_118 , & V_34 -> V_112 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_28 , V_5 ) ;
return V_25 ;
}
static struct V_70 *
F_81 ( struct V_33 * V_34 ,
struct V_124 * V_125 ,
struct V_61 * V_62 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_126 * V_127 ;
struct V_70 * V_71 ;
F_3 ( L_27 , V_5 ) ;
F_58 ( V_125 == NULL ) ;
V_127 = F_82 ( sizeof( * V_127 ) , V_38 ) ;
if ( V_127 == NULL )
return NULL ;
V_127 -> args . V_128 = V_129 ;
if ( V_127 -> args . V_128 > V_62 -> V_64 )
V_127 -> args . V_128 = V_62 -> V_64 ;
V_127 -> args . V_130 = V_131 ;
V_127 -> args . V_62 = * V_62 ;
V_127 -> args . type = V_14 -> V_10 -> V_2 ;
V_127 -> args . V_36 = V_37 ;
V_127 -> args . V_125 = F_83 ( V_125 ) ;
V_127 -> V_38 = V_38 ;
V_71 = F_84 ( V_127 , V_38 ) ;
if ( F_85 ( V_71 ) ) {
switch ( F_86 ( V_71 ) ) {
case - V_132 :
case - V_133 :
break;
default:
F_37 ( V_34 , V_62 -> V_53 ) ;
}
return NULL ;
}
return V_71 ;
}
int
F_87 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_38 ( V_92 ) ;
struct V_134 * V_135 ;
T_4 V_116 ;
int V_25 = 0 , V_111 ;
F_3 ( L_29 , V_5 , V_37 -> V_102 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_30 , V_5 ) ;
goto V_4;
}
V_116 = V_48 -> V_49 -> V_112 ;
F_20 ( V_34 ) ;
V_111 = F_24 ( & V_34 -> V_78 ) ;
F_39 ( V_34 , & V_92 , NULL ) ;
if ( V_111 ) {
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
V_34 -> V_100 ++ ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_92 ) ;
F_51 ( F_42 ( V_136 , & V_48 -> V_137 ) ) ;
V_135 = F_82 ( sizeof( * V_135 ) , V_138 ) ;
if ( F_88 ( V_135 == NULL ) ) {
V_25 = - V_132 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 -> V_100 -- ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_135 -> args . V_116 = V_116 ;
V_135 -> args . V_139 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_135 -> args . V_36 = V_37 ;
V_135 -> args . V_49 = V_34 ;
V_135 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_25 = F_89 ( V_135 ) ;
V_4:
F_3 ( L_32 , V_5 , V_25 ) ;
return V_25 ;
}
bool F_90 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
struct V_70 * V_71 , * V_27 ;
F_38 ( V_92 ) ;
bool V_140 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( ! V_34 || ! F_35 ( V_141 , & V_34 -> V_60 ) ||
F_42 ( V_79 , & V_34 -> V_60 ) )
goto V_142;
F_63 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_42 ( V_143 , & V_71 -> V_76 ) ) {
F_62 ( V_71 , & V_92 ) ;
V_140 = true ;
}
if ( ! V_140 )
goto V_142;
V_34 -> V_100 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_92 ) ;
return true ;
V_142:
F_7 ( & V_37 -> V_52 ) ;
return false ;
}
void F_91 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
V_34 -> V_100 -- ;
if ( F_9 ( & V_34 -> V_35 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_23 ( V_34 ) ;
} else
F_7 ( & V_37 -> V_52 ) ;
}
void F_92 ( struct V_36 * V_37 , T_1 V_144 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_72 ( V_144 , V_34 -> V_115 ) )
V_34 -> V_115 = V_144 ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_93 ( struct V_36 * V_37 , T_1 * V_144 , struct V_145 * V_146 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
struct V_70 * V_71 ;
T_1 V_147 ;
bool V_140 = false ;
F_5 ( & V_37 -> V_52 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_42 ( V_143 , & V_71 -> V_76 ) ) {
F_94 ( & F_22 ( V_37 ) -> V_80 , V_146 , NULL ) ;
V_140 = true ;
goto V_4;
}
V_34 = V_48 -> V_49 ;
V_147 = F_74 ( V_34 -> V_112 . V_113 ) ;
* V_144 = V_147 + F_55 ( & V_34 -> V_114 ) ;
V_4:
F_7 ( & V_37 -> V_52 ) ;
return V_140 ;
}
static T_5
F_95 ( struct V_61 * V_82 ,
struct V_61 * V_83 )
{
T_5 V_148 ;
V_148 = V_82 -> V_63 - V_83 -> V_63 ;
if ( V_148 )
return V_148 ;
V_148 = V_83 -> V_64 - V_82 -> V_64 ;
if ( V_148 )
return V_148 ;
return ( int ) ( V_82 -> V_53 == V_149 ) - ( int ) ( V_83 -> V_53 == V_149 ) ;
}
static void
F_96 ( struct V_33 * V_34 ,
struct V_70 * V_71 )
{
struct V_70 * V_150 ;
F_3 ( L_33 , V_5 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_95 ( & V_71 -> V_97 , & V_150 -> V_97 ) > 0 )
continue;
F_97 ( & V_71 -> V_72 , & V_150 -> V_72 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_71 , V_71 -> V_97 . V_53 ,
V_71 -> V_97 . V_63 , V_71 -> V_97 . V_64 ,
V_150 , V_150 -> V_97 . V_53 , V_150 -> V_97 . V_63 ,
V_150 -> V_97 . V_64 ) ;
goto V_4;
}
F_97 ( & V_71 -> V_72 , & V_34 -> V_78 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_71 , V_71 -> V_97 . V_53 ,
V_71 -> V_97 . V_63 , V_71 -> V_97 . V_64 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_38 , V_5 ) ;
}
static struct V_33 *
F_98 ( struct V_36 * V_37 ,
struct V_124 * V_125 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_46 ( & V_34 -> V_35 , 1 ) ;
F_45 ( & V_34 -> V_42 ) ;
F_45 ( & V_34 -> V_78 ) ;
F_45 ( & V_34 -> V_151 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_99 ( V_125 -> V_152 -> V_7 -> V_153 ) ;
return V_34 ;
}
static struct V_33 *
F_100 ( struct V_36 * V_37 ,
struct V_124 * V_125 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_106 = NULL ;
F_3 ( L_39 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_154;
F_7 ( & V_37 -> V_52 ) ;
V_106 = F_98 ( V_37 , V_125 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_101 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_106 ;
return V_106 ;
} else if ( V_106 != NULL )
F_23 ( V_106 ) ;
V_154:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static int
F_102 ( struct V_61 * V_155 ,
struct V_61 * V_62 )
{
struct V_61 V_156 ;
if ( ( V_62 -> V_53 == V_54 &&
V_155 -> V_53 != V_54 ) ||
! F_60 ( V_155 , V_62 ) )
return 0 ;
V_156 = * V_62 ;
V_156 . V_64 = 1 ;
return F_59 ( V_155 , & V_156 ) ;
}
static struct V_70 *
F_103 ( struct V_33 * V_34 ,
struct V_61 * V_62 )
{
struct V_70 * V_71 , * V_157 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_42 ( V_75 , & V_71 -> V_76 ) &&
F_102 ( & V_71 -> V_97 , V_62 ) ) {
V_157 = F_104 ( V_71 ) ;
break;
}
if ( V_71 -> V_97 . V_63 > V_62 -> V_63 )
break;
}
F_3 ( L_40 ,
V_5 , V_157 , V_157 ? F_55 ( & V_157 -> V_74 ) : 0 ) ;
return V_157 ;
}
static bool F_105 ( struct V_124 * V_125 ,
struct V_36 * V_37 , int V_53 )
{
struct V_158 * V_159 = V_125 -> V_160 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_6 V_161 = F_106 ( V_37 ) ;
bool V_162 = false , V_163 = false , V_164 = false , V_165 = false , V_157 = false ;
if ( V_159 == NULL )
return V_157 ;
F_3 ( L_41 ,
V_5 , V_159 -> V_166 , V_159 -> V_167 , V_159 -> V_168 , V_159 -> V_169 , V_159 -> V_170 ) ;
switch ( V_53 ) {
case V_149 :
if ( V_159 -> V_166 & V_171 ) {
F_3 ( L_42 , V_5 , V_161 ) ;
V_163 = true ;
if ( V_161 < V_159 -> V_167 )
V_162 = true ;
}
if ( V_159 -> V_166 & V_172 ) {
F_3 ( L_43 , V_5 ,
V_48 -> V_51 ) ;
V_165 = true ;
if ( V_48 -> V_51 < V_159 -> V_169 )
V_164 = true ;
}
break;
case V_54 :
if ( V_159 -> V_166 & V_173 ) {
F_3 ( L_42 , V_5 , V_161 ) ;
V_163 = true ;
if ( V_161 < V_159 -> V_168 )
V_162 = true ;
}
if ( V_159 -> V_166 & V_174 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_50 ) ;
V_165 = true ;
if ( V_48 -> V_50 < V_159 -> V_170 )
V_164 = true ;
}
break;
}
if ( V_163 && V_165 ) {
if ( V_162 && V_164 )
V_157 = true ;
} else if ( V_162 || V_164 )
V_157 = true ;
F_3 ( L_45 , V_5 , V_162 , V_164 , V_157 ) ;
return V_157 ;
}
struct V_70 *
F_107 ( struct V_36 * V_37 ,
struct V_124 * V_125 ,
T_6 V_175 ,
T_3 V_176 ,
enum V_177 V_53 ,
T_2 V_38 )
{
struct V_61 V_178 = {
. V_53 = V_53 ,
. V_63 = V_175 ,
. V_64 = V_176 ,
} ;
unsigned V_179 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_70 * V_71 = NULL ;
bool V_180 = false ;
if ( ! F_108 ( F_22 ( V_37 ) ) )
goto V_4;
if ( F_105 ( V_125 , V_37 , V_53 ) )
goto V_4;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_100 ( V_37 , V_125 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
goto V_4;
}
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_46 , V_5 ) ;
goto V_181;
}
if ( F_41 ( V_34 , V_53 ) )
goto V_181;
V_71 = F_103 ( V_34 , & V_178 ) ;
if ( V_71 )
goto V_181;
if ( F_77 ( V_34 , 0 ) )
goto V_181;
F_15 ( & V_34 -> V_114 ) ;
if ( F_24 ( & V_34 -> V_78 ) )
V_180 = true ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_180 ) {
F_5 ( & V_43 -> V_44 ) ;
F_58 ( ! F_24 ( & V_34 -> V_42 ) ) ;
F_97 ( & V_34 -> V_42 , & V_14 -> V_101 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_179 = V_178 . V_63 & ~ V_182 ;
if ( V_179 ) {
V_178 . V_63 -= V_179 ;
V_178 . V_64 += V_179 ;
}
if ( V_178 . V_64 != V_65 )
V_178 . V_64 = F_109 ( V_178 . V_64 ) ;
V_71 = F_81 ( V_34 , V_125 , & V_178 , V_38 ) ;
F_36 ( & V_34 -> V_114 ) ;
V_183:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_47
L_48 ,
V_5 , V_37 -> V_184 -> V_185 ,
( unsigned long long ) F_110 ( V_37 ) ,
V_71 == NULL ? L_49 : L_50 ,
V_53 == V_54 ? L_51 : L_52 ,
( unsigned long long ) V_175 ,
( unsigned long long ) V_176 ) ;
return V_71 ;
V_181:
F_7 ( & V_37 -> V_52 ) ;
goto V_183;
}
struct V_70 *
F_111 ( struct V_126 * V_127 )
{
struct V_33 * V_34 = F_28 ( V_127 -> args . V_36 ) -> V_49 ;
struct V_186 * V_187 = & V_127 -> V_187 ;
struct V_70 * V_71 ;
struct V_36 * V_37 = V_34 -> V_41 ;
int V_25 = 0 ;
V_71 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_187 , V_127 -> V_38 ) ;
if ( ! V_71 || F_85 ( V_71 ) ) {
if ( ! V_71 )
V_25 = - V_132 ;
else
V_25 = F_86 ( V_71 ) ;
F_3 ( L_53 ,
V_5 , V_25 ) ;
goto V_4;
}
F_5 ( & V_37 -> V_52 ) ;
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_54 , V_5 ) ;
goto V_188;
}
if ( F_77 ( V_34 , 1 ) ||
F_76 ( V_34 , & V_187 -> V_116 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_188;
}
F_73 ( V_34 , & V_187 -> V_116 , false ) ;
F_44 ( V_34 , V_71 ) ;
V_71 -> V_97 = V_187 -> V_62 ;
F_104 ( V_71 ) ;
F_96 ( V_34 , V_71 ) ;
if ( V_187 -> V_189 ) {
F_48 ( V_143 , & V_71 -> V_76 ) ;
F_48 ( V_141 , & V_34 -> V_60 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
return V_71 ;
V_4:
return F_112 ( V_25 ) ;
V_188:
F_7 ( & V_37 -> V_52 ) ;
V_71 -> V_77 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_71 ) ;
goto V_4;
}
void
F_113 ( struct V_190 * V_191 , struct V_192 * V_193 )
{
T_3 V_194 = V_193 -> V_195 ;
F_58 ( V_191 -> V_196 != NULL ) ;
if ( V_193 -> V_197 != V_193 -> V_198 ) {
F_114 ( V_191 ) ;
return;
}
if ( V_191 -> V_199 == NULL )
V_194 = F_106 ( V_191 -> V_200 ) - F_115 ( V_193 ) ;
else
V_194 = F_116 ( V_191 -> V_199 ) ;
V_191 -> V_196 = F_107 ( V_191 -> V_200 ,
V_193 -> V_201 ,
F_115 ( V_193 ) ,
V_194 ,
V_149 ,
V_138 ) ;
if ( V_191 -> V_196 == NULL )
F_114 ( V_191 ) ;
}
void
F_117 ( struct V_190 * V_191 ,
struct V_192 * V_193 , T_3 V_202 )
{
F_58 ( V_191 -> V_196 != NULL ) ;
if ( V_193 -> V_197 != V_193 -> V_198 ) {
F_118 ( V_191 ) ;
return;
}
V_191 -> V_196 = F_107 ( V_191 -> V_200 ,
V_193 -> V_201 ,
F_115 ( V_193 ) ,
V_202 ,
V_54 ,
V_203 ) ;
if ( V_191 -> V_196 == NULL )
F_118 ( V_191 ) ;
}
void
F_119 ( struct V_190 * V_191 , struct V_36 * V_36 ,
const struct V_204 * V_205 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_120 ( V_191 , V_36 , V_205 ) ;
else
F_121 ( V_191 , V_36 , V_39 -> V_206 , V_205 , V_14 -> V_207 , 0 ) ;
}
void
F_122 ( struct V_190 * V_191 , struct V_36 * V_36 ,
int V_208 ,
const struct V_204 * V_205 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_123 ( V_191 , V_36 , V_208 , V_205 ) ;
else
F_121 ( V_191 , V_36 , V_39 -> V_209 , V_205 , V_14 -> V_210 , V_208 ) ;
}
bool
F_124 ( struct V_190 * V_191 , struct V_192 * V_211 ,
struct V_192 * V_193 )
{
if ( V_191 -> V_196 == NULL )
return F_125 ( V_191 , V_211 , V_193 ) ;
return F_115 ( V_193 ) < F_56 ( V_191 -> V_196 -> V_97 . V_63 ,
V_191 -> V_196 -> V_97 . V_64 ) ;
}
int F_126 ( struct V_36 * V_36 ,
struct V_91 * V_66 ,
const struct V_204 * V_205 )
{
struct V_190 V_191 ;
F_38 ( V_212 ) ;
F_123 ( & V_191 , V_36 , V_213 , V_205 ) ;
while ( ! F_24 ( V_66 ) ) {
struct V_192 * V_193 = F_127 ( V_66 -> V_94 ) ;
F_128 ( V_193 ) ;
if ( ! F_129 ( & V_191 , V_193 ) )
F_130 ( V_193 , & V_212 ) ;
}
F_131 ( & V_191 ) ;
if ( ! F_24 ( & V_212 ) ) {
F_132 ( & V_212 , V_66 ) ;
return - V_214 ;
}
return 0 ;
}
static void F_133 ( struct V_215 * V_216 )
{
struct V_217 * V_218 = V_216 -> V_219 ;
F_3 ( L_56 , V_218 -> V_220 ) ;
if ( F_22 ( V_218 -> V_36 ) -> V_10 -> V_137 &
V_221 ) {
F_52 ( V_136 , & F_28 ( V_218 -> V_36 ) -> V_137 ) ;
F_134 ( V_218 -> V_36 ) ;
}
if ( ! F_33 ( V_222 , & V_218 -> V_137 ) )
V_216 -> V_146 . V_223 = F_126 ( V_218 -> V_36 ,
& V_218 -> V_224 ,
V_218 -> V_225 ) ;
}
void F_135 ( struct V_215 * V_216 )
{
struct V_217 * V_218 = V_216 -> V_219 ;
if ( ! V_218 -> V_220 ) {
F_136 ( V_216 ) ;
V_218 -> V_226 -> V_227 ( & V_216 -> V_146 , V_216 ) ;
} else
F_133 ( V_216 ) ;
V_218 -> V_226 -> V_228 ( V_216 ) ;
}
static void
F_137 ( struct V_190 * V_229 ,
struct V_215 * V_216 )
{
struct V_217 * V_218 = V_216 -> V_219 ;
if ( ! F_33 ( V_222 , & V_218 -> V_137 ) ) {
F_138 ( & V_218 -> V_224 , & V_229 -> V_230 ) ;
F_118 ( V_229 ) ;
V_229 -> V_231 = 1 ;
}
F_139 ( V_216 ) ;
}
static enum V_232
F_140 ( struct V_215 * V_233 ,
const struct V_234 * V_235 ,
struct V_70 * V_71 ,
int V_236 )
{
struct V_217 * V_218 = V_233 -> V_219 ;
struct V_36 * V_36 = V_218 -> V_36 ;
enum V_232 V_237 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_218 -> V_226 = V_235 ;
F_3 ( L_57 , V_5 ,
V_36 -> V_102 , V_233 -> args . V_176 , V_233 -> args . V_63 , V_236 ) ;
V_237 = V_9 -> V_10 -> V_238 ( V_233 , V_236 ) ;
if ( V_237 != V_239 )
F_141 ( V_36 , V_240 ) ;
F_3 ( L_58 , V_5 , V_237 ) ;
return V_237 ;
}
static void
F_142 ( struct V_190 * V_229 , struct V_91 * V_66 , int V_236 )
{
struct V_215 * V_216 ;
const struct V_234 * V_235 = V_229 -> V_241 ;
struct V_70 * V_71 = V_229 -> V_196 ;
V_229 -> V_196 = NULL ;
while ( ! F_24 ( V_66 ) ) {
enum V_232 V_237 ;
V_216 = F_143 ( V_66 , struct V_215 , V_242 ) ;
F_25 ( & V_216 -> V_242 ) ;
V_237 = F_140 ( V_216 , V_235 , V_71 , V_236 ) ;
if ( V_237 == V_239 )
F_137 ( V_229 , V_216 ) ;
}
F_54 ( V_71 ) ;
}
static void F_144 ( struct V_217 * V_218 )
{
F_54 ( V_218 -> V_71 ) ;
F_145 ( V_218 ) ;
}
int
F_146 ( struct V_190 * V_229 )
{
struct V_243 * V_244 ;
struct V_217 * V_218 ;
int V_157 ;
V_244 = F_147 () ;
if ( ! V_244 ) {
V_229 -> V_245 -> V_246 ( & V_229 -> V_230 ) ;
F_54 ( V_229 -> V_196 ) ;
V_229 -> V_196 = NULL ;
return - V_132 ;
}
V_218 = & V_244 -> V_219 ;
F_148 ( V_229 , V_218 , F_144 ) ;
V_218 -> V_71 = F_104 ( V_229 -> V_196 ) ;
F_15 ( & V_218 -> V_247 ) ;
V_157 = F_149 ( V_229 , V_218 ) ;
if ( V_157 != 0 ) {
F_54 ( V_229 -> V_196 ) ;
V_229 -> V_196 = NULL ;
} else
F_142 ( V_229 , & V_218 -> V_248 , V_229 -> V_249 ) ;
if ( F_9 ( & V_218 -> V_247 ) )
V_218 -> V_225 -> V_250 ( V_218 ) ;
return V_157 ;
}
int F_150 ( struct V_36 * V_36 ,
struct V_91 * V_66 ,
const struct V_204 * V_205 )
{
struct V_190 V_191 ;
F_38 ( V_212 ) ;
F_120 ( & V_191 , V_36 , V_205 ) ;
while ( ! F_24 ( V_66 ) ) {
struct V_192 * V_193 = F_127 ( V_66 -> V_94 ) ;
F_128 ( V_193 ) ;
if ( ! F_129 ( & V_191 , V_193 ) )
F_130 ( V_193 , & V_212 ) ;
}
F_131 ( & V_191 ) ;
if ( ! F_24 ( & V_212 ) ) {
F_132 ( & V_212 , V_66 ) ;
return - V_214 ;
}
return 0 ;
}
static void F_151 ( struct V_251 * V_216 )
{
struct V_217 * V_218 = V_216 -> V_219 ;
F_3 ( L_59 , V_218 -> V_220 ) ;
if ( F_22 ( V_218 -> V_36 ) -> V_10 -> V_137 &
V_221 ) {
F_52 ( V_136 , & F_28 ( V_218 -> V_36 ) -> V_137 ) ;
F_134 ( V_218 -> V_36 ) ;
}
if ( ! F_33 ( V_222 , & V_218 -> V_137 ) )
V_216 -> V_146 . V_223 = F_150 ( V_218 -> V_36 ,
& V_218 -> V_224 ,
V_218 -> V_225 ) ;
}
void F_152 ( struct V_251 * V_216 )
{
struct V_217 * V_218 = V_216 -> V_219 ;
if ( F_101 ( ! V_218 -> V_220 ) ) {
F_153 ( V_216 ) ;
V_218 -> V_226 -> V_227 ( & V_216 -> V_146 , V_216 ) ;
} else
F_151 ( V_216 ) ;
V_218 -> V_226 -> V_228 ( V_216 ) ;
}
static void
F_154 ( struct V_190 * V_229 ,
struct V_251 * V_216 )
{
struct V_217 * V_218 = V_216 -> V_219 ;
if ( ! F_33 ( V_222 , & V_218 -> V_137 ) ) {
F_138 ( & V_218 -> V_224 , & V_229 -> V_230 ) ;
F_114 ( V_229 ) ;
V_229 -> V_231 = 1 ;
}
F_155 ( V_216 ) ;
}
static enum V_232
F_156 ( struct V_251 * V_252 ,
const struct V_234 * V_235 ,
struct V_70 * V_71 )
{
struct V_217 * V_218 = V_252 -> V_219 ;
struct V_36 * V_36 = V_218 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_232 V_237 ;
V_218 -> V_226 = V_235 ;
F_3 ( L_60 ,
V_5 , V_36 -> V_102 , V_252 -> args . V_176 , V_252 -> args . V_63 ) ;
V_237 = V_9 -> V_10 -> V_253 ( V_252 ) ;
if ( V_237 != V_239 )
F_141 ( V_36 , V_254 ) ;
F_3 ( L_58 , V_5 , V_237 ) ;
return V_237 ;
}
static void
F_157 ( struct V_190 * V_229 , struct V_91 * V_66 )
{
struct V_251 * V_216 ;
const struct V_234 * V_235 = V_229 -> V_241 ;
struct V_70 * V_71 = V_229 -> V_196 ;
V_229 -> V_196 = NULL ;
while ( ! F_24 ( V_66 ) ) {
enum V_232 V_237 ;
V_216 = F_143 ( V_66 , struct V_251 , V_242 ) ;
F_25 ( & V_216 -> V_242 ) ;
V_237 = F_156 ( V_216 , V_235 , V_71 ) ;
if ( V_237 == V_239 )
F_154 ( V_229 , V_216 ) ;
}
F_54 ( V_71 ) ;
}
static void F_158 ( struct V_217 * V_218 )
{
F_54 ( V_218 -> V_71 ) ;
F_159 ( V_218 ) ;
}
int
F_160 ( struct V_190 * V_229 )
{
struct V_255 * V_256 ;
struct V_217 * V_218 ;
int V_157 ;
V_256 = F_161 () ;
if ( ! V_256 ) {
V_229 -> V_245 -> V_246 ( & V_229 -> V_230 ) ;
V_157 = - V_132 ;
F_54 ( V_229 -> V_196 ) ;
V_229 -> V_196 = NULL ;
return V_157 ;
}
V_218 = & V_256 -> V_219 ;
F_148 ( V_229 , V_218 , F_158 ) ;
V_218 -> V_71 = F_104 ( V_229 -> V_196 ) ;
F_15 ( & V_218 -> V_247 ) ;
V_157 = F_162 ( V_229 , V_218 ) ;
if ( V_157 != 0 ) {
F_54 ( V_229 -> V_196 ) ;
V_229 -> V_196 = NULL ;
} else
F_157 ( V_229 , & V_218 -> V_248 ) ;
if ( F_9 ( & V_218 -> V_247 ) )
V_218 -> V_225 -> V_250 ( V_218 ) ;
return V_157 ;
}
static void F_163 ( struct V_36 * V_36 , struct V_91 * V_257 )
{
struct V_70 * V_71 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_71 -> V_97 . V_53 == V_54 &&
F_42 ( V_258 , & V_71 -> V_76 ) )
F_17 ( & V_71 -> V_73 , V_257 ) ;
}
}
void F_164 ( struct V_70 * V_71 )
{
F_37 ( V_71 -> V_77 , V_71 -> V_97 . V_53 ) ;
}
void
F_136 ( struct V_215 * V_233 )
{
struct V_217 * V_218 = V_233 -> V_219 ;
struct V_36 * V_36 = V_218 -> V_36 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_259 = V_233 -> V_260 + V_233 -> V_187 . V_176 ;
bool V_261 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_33 ( V_136 , & V_48 -> V_137 ) ) {
V_261 = true ;
F_3 ( L_61 ,
V_5 , V_36 -> V_102 ) ;
}
if ( ! F_33 ( V_258 , & V_218 -> V_71 -> V_76 ) ) {
F_104 ( V_218 -> V_71 ) ;
}
if ( V_259 > V_48 -> V_49 -> V_262 )
V_48 -> V_49 -> V_262 = V_259 ;
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_62 ,
V_5 , V_218 -> V_71 , V_48 -> V_49 -> V_262 ) ;
if ( V_261 )
F_165 ( V_36 ) ;
}
void F_166 ( struct V_263 * V_216 )
{
struct V_8 * V_9 = F_22 ( V_216 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_264 )
V_9 -> V_10 -> V_264 ( V_216 ) ;
}
int
F_167 ( struct V_36 * V_36 , bool V_265 )
{
struct V_263 * V_216 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_259 ;
int V_25 = 0 ;
F_3 ( L_63 , V_5 , V_36 -> V_102 ) ;
if ( ! F_42 ( V_136 , & V_48 -> V_137 ) )
return 0 ;
V_216 = F_82 ( sizeof( * V_216 ) , V_203 ) ;
if ( ! V_216 ) {
V_25 = - V_132 ;
goto V_4;
}
if ( ! F_42 ( V_136 , & V_48 -> V_137 ) )
goto V_266;
if ( F_33 ( V_267 , & V_48 -> V_137 ) ) {
if ( ! V_265 ) {
V_25 = - V_121 ;
goto V_266;
}
V_25 = F_168 ( & V_48 -> V_137 , V_267 ,
V_268 , V_269 ) ;
if ( V_25 )
goto V_266;
}
F_45 ( & V_216 -> V_270 ) ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_35 ( V_136 , & V_48 -> V_137 ) ) {
F_52 ( V_267 , & V_48 -> V_137 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_169 ( & V_48 -> V_137 , V_267 ) ;
goto V_266;
}
F_163 ( V_36 , & V_216 -> V_270 ) ;
V_259 = V_48 -> V_49 -> V_262 ;
V_48 -> V_49 -> V_262 = 0 ;
F_75 ( & V_216 -> args . V_116 , & V_48 -> V_49 -> V_112 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_216 -> args . V_36 = V_36 ;
V_216 -> V_271 = F_99 ( V_48 -> V_49 -> V_45 ) ;
F_170 ( & V_216 -> V_272 ) ;
V_216 -> args . V_273 = F_22 ( V_36 ) -> V_274 ;
V_216 -> V_187 . V_272 = & V_216 -> V_272 ;
V_216 -> args . V_275 = V_259 - 1 ;
V_216 -> V_187 . V_14 = F_22 ( V_36 ) ;
V_25 = F_171 ( V_216 , V_265 ) ;
V_4:
if ( V_25 )
F_165 ( V_36 ) ;
F_3 ( L_64 , V_5 , V_25 ) ;
return V_25 ;
V_266:
F_172 ( V_216 ) ;
goto V_4;
}
struct V_158 * F_173 ( void )
{
struct V_158 * V_276 ;
V_276 = F_82 ( sizeof( * V_276 ) , V_203 ) ;
if ( ! V_276 ) {
F_3 ( L_65 , V_5 ) ;
return NULL ;
}
return V_276 ;
}
