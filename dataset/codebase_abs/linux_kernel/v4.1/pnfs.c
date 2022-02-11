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
if ( ! F_24 ( & V_34 -> V_53 ) )
F_31 ( 1 , L_17 ) ;
F_27 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_23 ( V_34 ) ;
}
}
static int
F_32 ( T_1 V_54 )
{
return V_54 == V_55 ?
V_56 : V_57 ;
}
static void
F_33 ( struct V_33 * V_34 , int V_58 )
{
V_34 -> V_59 = V_60 ;
if ( ! F_34 ( V_58 , & V_34 -> V_61 ) )
F_15 ( & V_34 -> V_35 ) ;
}
static void
F_35 ( struct V_33 * V_34 , int V_58 )
{
if ( F_36 ( V_58 , & V_34 -> V_61 ) )
F_37 ( & V_34 -> V_35 ) ;
}
static void
F_38 ( struct V_33 * V_34 , T_1 V_54 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
struct V_62 V_63 = {
. V_54 = V_54 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_39 ( V_67 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_33 ( V_34 , F_32 ( V_54 ) ) ;
F_40 ( V_34 , & V_67 , & V_63 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_41 ( & V_67 ) ;
F_3 ( L_18 , V_5 ,
V_54 == V_55 ? L_19 : L_20 ) ;
}
static bool
F_42 ( struct V_33 * V_34 , T_1 V_54 )
{
unsigned long V_68 , V_69 ;
int V_58 = F_32 ( V_54 ) ;
if ( F_43 ( V_58 , & V_34 -> V_61 ) == 0 )
return false ;
V_69 = V_60 ;
V_68 = V_69 - V_70 ;
if ( ! F_44 ( V_34 -> V_59 , V_68 , V_69 ) ) {
F_35 ( V_34 , V_58 ) ;
return false ;
}
return true ;
}
static void
F_45 ( struct V_33 * V_34 , struct V_71 * V_72 )
{
F_46 ( & V_72 -> V_73 ) ;
F_46 ( & V_72 -> V_74 ) ;
F_47 ( & V_72 -> V_75 , 1 ) ;
F_48 () ;
F_49 ( V_76 , & V_72 -> V_77 ) ;
V_72 -> V_78 = V_34 ;
}
static void F_50 ( struct V_71 * V_72 )
{
struct V_36 * V_37 = V_72 -> V_78 -> V_41 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_72 ) ;
}
static void
F_51 ( struct V_33 * V_34 ,
struct V_71 * V_72 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
F_52 ( F_43 ( V_76 , & V_72 -> V_77 ) ) ;
F_25 ( & V_72 -> V_73 ) ;
F_37 ( & V_34 -> V_35 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
F_53 ( V_79 , & V_34 -> V_61 ) ;
F_54 ( & F_22 ( V_36 ) -> V_80 ) ;
}
static bool
F_55 ( struct V_33 * V_34 ,
struct V_71 * V_72 )
{
struct V_71 * V_81 ;
if ( ! F_43 ( V_82 , & V_72 -> V_77 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list)
if ( V_81 != V_72 && F_43 ( V_82 , & V_81 -> V_77 ) )
return false ;
return true ;
}
static void F_56 ( struct V_71 * V_72 ,
struct V_33 * V_34 , struct V_36 * V_36 )
{
V_34 = V_72 -> V_78 ;
V_36 = V_34 -> V_41 ;
F_5 ( & V_36 -> V_52 ) ;
if ( F_55 ( V_34 , V_72 ) ) {
T_3 V_83 ;
enum V_84 V_54 ;
V_83 = V_34 -> V_85 ;
V_54 = V_34 -> V_86 ;
V_34 -> V_87 ++ ;
V_34 -> V_86 = 0 ;
F_7 ( & V_36 -> V_52 ) ;
F_20 ( V_34 ) ;
F_57 ( V_34 , V_83 , V_54 , false ) ;
} else
F_7 ( & V_36 -> V_52 ) ;
}
void
F_58 ( struct V_71 * V_72 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
if ( ! V_72 )
return;
F_3 ( L_21 , V_5 , V_72 ,
F_59 ( & V_72 -> V_75 ) ,
F_43 ( V_76 , & V_72 -> V_77 ) ) ;
if ( F_60 ( & V_72 -> V_75 , - 1 , 1 ) )
return;
V_34 = V_72 -> V_78 ;
V_36 = V_34 -> V_41 ;
if ( F_43 ( V_82 , & V_72 -> V_77 ) )
F_56 ( V_72 , V_34 , V_36 ) ;
if ( F_30 ( & V_72 -> V_75 , & V_36 -> V_52 ) ) {
F_20 ( V_34 ) ;
F_51 ( V_34 , V_72 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_50 ( V_72 ) ;
F_29 ( V_34 ) ;
}
}
static void F_61 ( struct V_88 * V_89 )
{
struct V_71 * V_72 ;
struct V_33 * V_34 ;
V_72 = F_62 ( V_89 , struct V_71 , V_90 ) ;
V_34 = V_72 -> V_78 ;
F_50 ( V_72 ) ;
F_29 ( V_34 ) ;
}
static void F_63 ( struct V_71 * V_72 )
{
F_64 ( & V_72 -> V_90 , F_61 ) ;
F_65 ( & V_72 -> V_90 ) ;
}
void
F_66 ( struct V_71 * V_72 )
{
if ( ! V_72 )
return;
F_67 ( & V_72 -> V_78 -> V_41 -> V_52 ) ;
F_3 ( L_21 , V_5 , V_72 ,
F_59 ( & V_72 -> V_75 ) ,
F_43 ( V_76 , & V_72 -> V_77 ) ) ;
if ( F_9 ( & V_72 -> V_75 ) ) {
struct V_33 * V_34 = V_72 -> V_78 ;
F_20 ( V_34 ) ;
F_51 ( V_34 , V_72 ) ;
F_63 ( V_72 ) ;
}
}
static T_4
F_68 ( T_4 V_68 , T_4 V_91 )
{
T_4 V_69 ;
V_69 = V_68 + V_91 ;
return V_69 >= V_68 ? V_69 : V_66 ;
}
static bool
F_69 ( const struct V_62 * V_92 ,
const struct V_62 * V_93 )
{
T_4 V_94 = V_92 -> V_64 ;
T_4 V_95 = F_68 ( V_94 , V_92 -> V_65 ) ;
T_4 V_96 = V_93 -> V_64 ;
T_4 V_97 = F_68 ( V_96 , V_93 -> V_65 ) ;
return ( V_94 <= V_96 ) && ( V_95 >= V_97 ) ;
}
static bool
F_70 ( const struct V_62 * V_92 ,
const struct V_62 * V_93 )
{
T_4 V_94 = V_92 -> V_64 ;
T_4 V_95 = F_68 ( V_94 , V_92 -> V_65 ) ;
T_4 V_96 = V_93 -> V_64 ;
T_4 V_97 = F_68 ( V_96 , V_93 -> V_65 ) ;
return ( V_95 == V_66 || V_95 > V_96 ) &&
( V_97 == V_66 || V_97 > V_94 ) ;
}
static bool
F_71 ( const struct V_62 * V_98 ,
const struct V_62 * V_99 )
{
return ( V_99 -> V_54 == V_100 ||
V_98 -> V_54 == V_99 -> V_54 ) &&
F_70 ( V_98 , V_99 ) ;
}
static bool F_72 ( struct V_71 * V_72 ,
struct V_101 * V_102 )
{
if ( ! F_9 ( & V_72 -> V_75 ) )
return false ;
F_51 ( V_72 -> V_78 , V_72 ) ;
F_17 ( & V_72 -> V_73 , V_102 ) ;
return true ;
}
static int F_73 ( struct V_71 * V_72 ,
struct V_101 * V_102 )
{
int V_103 = 0 ;
if ( F_36 ( V_76 , & V_72 -> V_77 ) ) {
F_3 ( L_22 , V_5 , V_72 ,
F_59 ( & V_72 -> V_75 ) ) ;
if ( F_72 ( V_72 , V_102 ) )
V_103 = 1 ;
}
return V_103 ;
}
int
F_40 ( struct V_33 * V_34 ,
struct V_101 * V_102 ,
struct V_62 * V_99 )
{
struct V_71 * V_72 , * V_104 ;
int V_105 = 0 , V_106 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_74 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_99 ||
F_71 ( & V_72 -> V_107 , V_99 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_72 , V_72 -> V_107 . V_54 , V_72 -> V_107 . V_64 ,
V_72 -> V_107 . V_65 ) ;
V_105 ++ ;
V_106 += F_73 ( V_72 , V_102 ) ;
}
F_3 ( L_26 , V_5 , V_105 - V_106 ) ;
return V_105 - V_106 ;
}
void
F_41 ( struct V_101 * V_108 )
{
struct V_71 * V_72 , * V_27 ;
if ( F_24 ( V_108 ) )
return;
F_74 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_72 -> V_73 ) ;
F_50 ( V_72 ) ;
}
}
void
F_75 ( struct V_47 * V_48 )
{
struct V_33 * V_34 ;
F_39 ( V_102 ) ;
F_5 ( & V_48 -> V_109 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
V_34 -> V_87 ++ ;
F_40 ( V_34 , & V_102 , NULL ) ;
F_20 ( V_34 ) ;
F_35 ( V_34 , V_57 ) ;
F_35 ( V_34 , V_56 ) ;
F_76 ( V_34 ) ;
F_7 ( & V_48 -> V_109 . V_52 ) ;
F_41 ( & V_102 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_109 . V_52 ) ;
}
static bool
F_77 ( struct V_36 * V_36 ,
struct V_101 * V_110 )
{
struct V_33 * V_34 ;
bool V_111 = false ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 != NULL && F_24 ( & V_34 -> V_112 ) ) {
F_20 ( V_34 ) ;
F_17 ( & V_34 -> V_112 , V_110 ) ;
V_111 = true ;
}
F_7 ( & V_36 -> V_52 ) ;
return V_111 ;
}
static int
F_78 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_101 * V_110 )
{
struct V_33 * V_34 , * V_104 ;
struct V_36 * V_36 ;
F_74 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_79 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_77 ( V_36 , V_110 ) )
continue;
F_80 () ;
F_7 ( & V_43 -> V_44 ) ;
F_81 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_82 () ;
return - V_113 ;
}
return 0 ;
}
static int
F_83 ( struct V_101 * V_110 ,
bool V_114 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
struct V_62 V_63 = {
. V_54 = V_100 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_39 ( V_115 ) ;
int V_111 = 0 ;
while ( ! F_24 ( V_110 ) ) {
V_34 = F_84 ( V_110 -> V_104 , struct V_33 ,
V_112 ) ;
F_3 ( L_27 , V_5 ,
V_34 -> V_41 -> V_116 ) ;
V_36 = V_34 -> V_41 ;
F_85 ( V_36 , false ) ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_112 ) ;
V_34 -> V_87 ++ ;
if ( V_114 )
F_49 ( V_79 , & V_34 -> V_61 ) ;
if ( F_40 ( V_34 , & V_115 , & V_63 ) )
V_111 = - V_113 ;
F_7 ( & V_36 -> V_52 ) ;
F_41 ( & V_115 ) ;
F_29 ( V_34 ) ;
F_81 ( V_36 ) ;
}
return V_111 ;
}
int
F_86 ( struct V_12 * V_43 ,
struct V_117 * V_118 ,
bool V_119 )
{
struct V_8 * V_14 ;
F_39 ( V_110 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_82 () ;
V_120:
F_87 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_118 , V_118 , sizeof( * V_118 ) ) != 0 )
continue;
if ( F_78 ( V_43 ,
V_14 ,
& V_110 ) != 0 )
goto V_120;
}
F_80 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_110 ) )
return 0 ;
return F_83 ( & V_110 , V_119 ) ;
}
int
F_88 ( struct V_12 * V_43 ,
bool V_119 )
{
struct V_8 * V_14 ;
F_39 ( V_110 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_82 () ;
V_120:
F_87 (server, &clp->cl_superblocks, client_link) {
if ( F_78 ( V_43 ,
V_14 ,
& V_110 ) != 0 )
goto V_120;
}
F_80 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_110 ) )
return 0 ;
return F_83 ( & V_110 , V_119 ) ;
}
void
F_89 ( struct V_12 * V_43 )
{
F_90 ( V_43 ) ;
F_10 ( V_43 ) ;
F_88 ( V_43 , false ) ;
}
static bool F_91 ( T_1 V_121 , T_1 V_122 )
{
return ( V_123 ) ( V_121 - V_122 ) > 0 ;
}
void
F_92 ( struct V_33 * V_34 , const T_3 * V_124 ,
bool V_125 )
{
T_1 V_126 , V_127 , V_128 ;
int V_129 = F_24 ( & V_34 -> V_53 ) ;
V_126 = F_93 ( V_34 -> V_85 . V_130 ) ;
V_127 = F_93 ( V_124 -> V_130 ) ;
if ( V_129 || F_91 ( V_127 , V_126 ) ) {
F_94 ( & V_34 -> V_85 , V_124 ) ;
if ( V_125 ) {
V_128 = F_93 ( V_124 -> V_130 ) ;
} else {
V_128 = V_127 - F_59 ( & V_34 -> V_131 ) ;
}
if ( V_129 || F_91 ( V_128 , V_34 -> V_132 ) )
V_34 -> V_132 = V_128 ;
}
}
static bool
F_95 ( const struct V_33 * V_34 ,
const T_3 * V_83 )
{
T_1 V_130 = F_93 ( V_83 -> V_130 ) ;
return ! F_91 ( V_130 , V_34 -> V_132 ) ;
}
static bool
F_96 ( const struct V_33 * V_34 ,
struct V_62 * V_63 )
{
return F_43 ( V_133 , & V_34 -> V_61 ) &&
( V_34 -> V_86 == V_100 ||
V_34 -> V_86 == V_63 -> V_54 ) ;
}
static bool
F_97 ( const struct V_33 * V_34 ,
struct V_62 * V_63 , int V_134 )
{
return V_34 -> V_87 ||
F_43 ( V_79 , & V_34 -> V_61 ) ||
( F_24 ( & V_34 -> V_53 ) &&
( F_59 ( & V_34 -> V_131 ) > V_134 ) ) ||
F_96 ( V_34 , V_63 ) ;
}
int
F_98 ( T_3 * V_135 , struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_136 * V_137 )
{
int V_25 = 0 ;
F_3 ( L_28 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_97 ( V_34 , V_63 , 1 ) ) {
V_25 = - V_113 ;
} else if ( ! F_99 ( V_137 ) ) {
V_25 = - V_138 ;
} else if ( F_24 ( & V_34 -> V_53 ) ||
F_43 ( V_139 , & V_34 -> V_61 ) ) {
int V_140 ;
do {
V_140 = F_100 ( & V_137 -> V_141 ) ;
F_94 ( V_135 , & V_137 -> V_83 ) ;
} while ( F_101 ( & V_137 -> V_141 , V_140 ) );
} else
F_94 ( V_135 , & V_34 -> V_85 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_29 , V_5 ) ;
return V_25 ;
}
static struct V_71 *
F_102 ( struct V_33 * V_34 ,
struct V_142 * V_143 ,
struct V_62 * V_63 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_144 * V_145 ;
struct V_71 * V_72 ;
F_3 ( L_28 , V_5 ) ;
V_145 = F_103 ( sizeof( * V_145 ) , V_38 ) ;
if ( V_145 == NULL )
return NULL ;
V_145 -> args . V_146 = V_147 ;
if ( V_145 -> args . V_146 > V_63 -> V_65 )
V_145 -> args . V_146 = V_63 -> V_65 ;
V_145 -> args . V_148 = V_149 ;
V_145 -> args . V_63 = * V_63 ;
V_145 -> args . type = V_14 -> V_10 -> V_2 ;
V_145 -> args . V_36 = V_37 ;
V_145 -> args . V_143 = F_104 ( V_143 ) ;
V_145 -> V_38 = V_38 ;
V_145 -> V_150 = V_34 -> V_45 ;
V_72 = F_105 ( V_145 , V_38 ) ;
if ( F_106 ( V_72 ) ) {
switch ( F_107 ( V_72 ) ) {
case - V_151 :
case - V_152 :
break;
default:
F_38 ( V_34 , V_63 -> V_54 ) ;
}
return NULL ;
} else
F_35 ( V_34 ,
F_32 ( V_63 -> V_54 ) ) ;
return V_72 ;
}
static void F_108 ( struct V_36 * V_36 ,
struct V_101 * V_67 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_71 * V_72 , * V_27 ;
if ( ! F_36 ( V_153 , & V_48 -> V_154 ) )
return;
F_74 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_36 ( V_155 , & V_72 -> V_77 ) )
continue;
F_72 ( V_72 , V_67 ) ;
}
}
void F_109 ( struct V_33 * V_34 )
{
F_110 ( V_133 , & V_34 -> V_61 ) ;
F_111 () ;
F_112 ( & V_34 -> V_61 , V_133 ) ;
}
static int
F_57 ( struct V_33 * V_34 , T_3 V_83 ,
enum V_84 V_54 , bool V_156 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_157 * V_158 ;
int V_25 = 0 ;
V_158 = F_103 ( sizeof( * V_158 ) , V_159 ) ;
if ( F_113 ( V_158 == NULL ) ) {
V_25 = - V_151 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 -> V_87 -- ;
F_109 ( V_34 ) ;
F_54 ( & F_22 ( V_37 ) -> V_80 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_158 -> args . V_83 = V_83 ;
V_158 -> args . V_160 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_158 -> args . V_36 = V_37 ;
V_158 -> args . V_63 . V_54 = V_54 ;
V_158 -> args . V_63 . V_64 = 0 ;
V_158 -> args . V_63 . V_65 = V_66 ;
V_158 -> args . V_49 = V_34 ;
V_158 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_158 -> V_150 = V_34 -> V_45 ;
V_25 = F_114 ( V_158 , V_156 ) ;
V_4:
F_3 ( L_30 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_115 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_39 ( V_102 ) ;
T_3 V_83 ;
int V_25 = 0 , V_129 ;
F_3 ( L_31 , V_5 , V_37 -> V_116 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_4;
}
V_83 = V_48 -> V_49 -> V_85 ;
F_20 ( V_34 ) ;
V_129 = F_24 ( & V_34 -> V_53 ) ;
F_108 ( V_37 , & V_102 ) ;
F_40 ( V_34 , & V_102 , NULL ) ;
if ( F_22 ( V_37 ) -> V_10 -> V_161 ) {
struct V_62 V_63 = {
. V_54 = V_100 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_22 ( V_37 ) -> V_10 -> V_161 ( V_34 , & V_63 ) ;
}
if ( V_129 ) {
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
F_3 ( L_33 , V_5 ) ;
goto V_4;
}
F_49 ( V_139 , & V_34 -> V_61 ) ;
V_34 -> V_87 ++ ;
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_102 ) ;
V_25 = F_57 ( V_34 , V_83 , V_100 , true ) ;
V_4:
F_3 ( L_30 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_116 ( struct V_36 * V_36 )
{
struct V_33 * V_34 ;
int V_111 ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 == NULL ) {
F_7 ( & V_36 -> V_52 ) ;
return 0 ;
}
F_20 ( V_34 ) ;
V_34 -> V_87 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_117 ( V_36 -> V_162 ) ;
V_111 = F_85 ( V_36 , true ) ;
if ( V_111 == 0 )
V_111 = F_115 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_87 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_111 ;
}
bool F_118 ( struct V_36 * V_37 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_142 * V_143 ;
struct V_136 * V_163 ;
struct V_33 * V_34 ;
struct V_71 * V_72 , * V_27 ;
T_3 V_83 ;
F_39 ( V_102 ) ;
bool V_164 = false , V_165 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 || ! F_36 ( V_166 , & V_34 -> V_61 ) ||
F_43 ( V_79 , & V_34 -> V_61 ) )
goto V_167;
if ( F_119 ( V_37 , V_168 ) )
goto V_167;
F_2 (ctx, &nfsi->open_files, list) {
V_163 = V_143 -> V_163 ;
if ( V_163 != NULL && V_163 -> V_163 != 0 )
goto V_167;
}
F_76 ( V_34 ) ;
F_74 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_43 ( V_169 , & V_72 -> V_77 ) ) {
F_73 ( V_72 , & V_102 ) ;
V_164 = true ;
}
if ( ! V_164 )
goto V_167;
V_34 -> V_87 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_102 ) ;
F_85 ( V_37 , true ) ;
return true ;
V_167:
if ( V_34 ) {
V_83 = V_34 -> V_85 ;
V_165 =
F_36 ( V_170 ,
& V_34 -> V_61 ) ;
if ( V_165 ) {
V_34 -> V_87 ++ ;
F_20 ( V_34 ) ;
}
}
F_7 ( & V_37 -> V_52 ) ;
if ( V_165 ) {
F_85 ( V_37 , true ) ;
F_57 ( V_34 , V_83 , V_100 , true ) ;
}
return false ;
}
void F_120 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
V_34 -> V_87 -- ;
if ( F_9 ( & V_34 -> V_35 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_23 ( V_34 ) ;
} else
F_7 ( & V_37 -> V_52 ) ;
}
void F_121 ( struct V_36 * V_37 , T_1 V_171 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_91 ( V_171 , V_34 -> V_132 ) )
V_34 -> V_132 = V_171 ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_122 ( struct V_36 * V_37 , T_1 * V_171 , struct V_172 * V_173 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
struct V_71 * V_72 ;
T_3 V_83 ;
T_1 V_174 ;
bool V_164 = false , V_165 = false ;
F_5 ( & V_37 -> V_52 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_43 ( V_169 , & V_72 -> V_77 ) ) {
F_123 ( & F_22 ( V_37 ) -> V_80 , V_173 , NULL ) ;
V_164 = true ;
goto V_4;
}
V_34 = V_48 -> V_49 ;
V_174 = F_93 ( V_34 -> V_85 . V_130 ) ;
* V_171 = V_174 + F_59 ( & V_34 -> V_131 ) ;
V_4:
if ( ! V_164 ) {
V_83 = V_34 -> V_85 ;
V_165 =
F_36 ( V_170 ,
& V_34 -> V_61 ) ;
if ( V_165 ) {
V_34 -> V_87 ++ ;
F_20 ( V_34 ) ;
}
}
F_7 ( & V_37 -> V_52 ) ;
if ( V_165 ) {
F_123 ( & F_22 ( V_37 ) -> V_80 , V_173 , NULL ) ;
F_57 ( V_34 , V_83 , V_100 , false ) ;
}
return V_164 ;
}
static T_5
F_124 ( const struct V_62 * V_92 ,
const struct V_62 * V_93 )
{
T_5 V_175 ;
V_175 = V_92 -> V_64 - V_93 -> V_64 ;
if ( V_175 )
return V_175 ;
V_175 = V_93 -> V_65 - V_92 -> V_65 ;
if ( V_175 )
return V_175 ;
return ( int ) ( V_92 -> V_54 == V_176 ) - ( int ) ( V_93 -> V_54 == V_176 ) ;
}
static void
F_125 ( struct V_33 * V_34 ,
struct V_71 * V_72 )
{
struct V_71 * V_177 ;
F_3 ( L_34 , V_5 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_124 ( & V_72 -> V_107 , & V_177 -> V_107 ) > 0 )
continue;
F_126 ( & V_72 -> V_73 , & V_177 -> V_73 ) ;
F_3 ( L_35
L_36
L_37 ,
V_5 , V_72 , V_72 -> V_107 . V_54 ,
V_72 -> V_107 . V_64 , V_72 -> V_107 . V_65 ,
V_177 , V_177 -> V_107 . V_54 , V_177 -> V_107 . V_64 ,
V_177 -> V_107 . V_65 ) ;
goto V_4;
}
F_126 ( & V_72 -> V_73 , & V_34 -> V_53 ) ;
F_3 ( L_35
L_38 ,
V_5 , V_72 , V_72 -> V_107 . V_54 ,
V_72 -> V_107 . V_64 , V_72 -> V_107 . V_65 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_39 , V_5 ) ;
}
static struct V_33 *
F_127 ( struct V_36 * V_37 ,
struct V_142 * V_143 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_47 ( & V_34 -> V_35 , 1 ) ;
F_46 ( & V_34 -> V_42 ) ;
F_46 ( & V_34 -> V_53 ) ;
F_46 ( & V_34 -> V_112 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_128 ( V_143 -> V_150 ) ;
return V_34 ;
}
static struct V_33 *
F_129 ( struct V_36 * V_37 ,
struct V_142 * V_143 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_124 = NULL ;
F_3 ( L_40 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_178;
F_7 ( & V_37 -> V_52 ) ;
V_124 = F_127 ( V_37 , V_143 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_130 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_124 ;
return V_124 ;
} else if ( V_124 != NULL )
F_23 ( V_124 ) ;
V_178:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_131 ( const struct V_62 * V_179 ,
const struct V_62 * V_63 )
{
struct V_62 V_180 ;
if ( ( V_63 -> V_54 == V_55 &&
V_179 -> V_54 != V_55 ) ||
! F_70 ( V_179 , V_63 ) )
return 0 ;
V_180 = * V_63 ;
V_180 . V_65 = 1 ;
return F_69 ( V_179 , & V_180 ) ;
}
static struct V_71 *
F_132 ( struct V_33 * V_34 ,
struct V_62 * V_63 )
{
struct V_71 * V_72 , * V_111 = NULL ;
F_3 ( L_34 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_43 ( V_76 , & V_72 -> V_77 ) &&
! F_43 ( V_82 , & V_72 -> V_77 ) &&
F_131 ( & V_72 -> V_107 , V_63 ) ) {
V_111 = F_133 ( V_72 ) ;
break;
}
if ( V_72 -> V_107 . V_64 > V_63 -> V_64 )
break;
}
F_3 ( L_41 ,
V_5 , V_111 , V_111 ? F_59 ( & V_111 -> V_75 ) : 0 ) ;
return V_111 ;
}
static bool F_134 ( struct V_142 * V_143 ,
struct V_36 * V_37 , int V_54 )
{
struct V_181 * V_182 = V_143 -> V_183 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_6 V_184 = F_135 ( V_37 ) ;
bool V_185 = false , V_186 = false , V_187 = false , V_188 = false , V_111 = false ;
if ( V_182 == NULL )
return V_111 ;
F_3 ( L_42 ,
V_5 , V_182 -> V_189 , V_182 -> V_190 , V_182 -> V_191 , V_182 -> V_192 , V_182 -> V_193 ) ;
switch ( V_54 ) {
case V_176 :
if ( V_182 -> V_189 & V_194 ) {
F_3 ( L_43 , V_5 , V_184 ) ;
V_186 = true ;
if ( V_184 < V_182 -> V_190 )
V_185 = true ;
}
if ( V_182 -> V_189 & V_195 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_51 ) ;
V_188 = true ;
if ( V_48 -> V_51 < V_182 -> V_192 )
V_187 = true ;
}
break;
case V_55 :
if ( V_182 -> V_189 & V_196 ) {
F_3 ( L_43 , V_5 , V_184 ) ;
V_186 = true ;
if ( V_184 < V_182 -> V_191 )
V_185 = true ;
}
if ( V_182 -> V_189 & V_197 ) {
F_3 ( L_45 , V_5 ,
V_48 -> V_50 ) ;
V_188 = true ;
if ( V_48 -> V_50 < V_182 -> V_193 )
V_187 = true ;
}
break;
}
if ( V_186 && V_188 ) {
if ( V_185 && V_187 )
V_111 = true ;
} else if ( V_185 || V_187 )
V_111 = true ;
F_3 ( L_46 , V_5 , V_185 , V_187 , V_111 ) ;
return V_111 ;
}
static int F_136 ( struct V_198 * V_199 )
{
if ( ! F_43 ( V_200 , V_199 -> V_154 ) )
return 1 ;
return F_137 ( V_199 ) ;
}
static bool F_138 ( struct V_33 * V_34 )
{
F_85 ( V_34 -> V_41 , false ) ;
return ! F_139 ( & V_34 -> V_61 , V_133 ,
F_136 ,
V_201 ) ;
}
static void F_140 ( struct V_33 * V_34 )
{
unsigned long * V_202 = & V_34 -> V_61 ;
F_110 ( V_203 , V_202 ) ;
F_111 () ;
F_112 ( V_202 , V_203 ) ;
}
struct V_71 *
F_141 ( struct V_36 * V_37 ,
struct V_142 * V_143 ,
T_6 V_204 ,
T_4 V_205 ,
enum V_84 V_54 ,
T_2 V_38 )
{
struct V_62 V_206 = {
. V_54 = V_54 ,
. V_64 = V_204 ,
. V_65 = V_205 ,
} ;
unsigned V_207 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_71 * V_72 = NULL ;
bool V_208 ;
if ( ! F_142 ( F_22 ( V_37 ) ) )
goto V_4;
if ( F_134 ( V_143 , V_37 , V_54 ) )
goto V_4;
V_209:
V_208 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_129 ( V_37 , V_143 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
goto V_4;
}
if ( F_43 ( V_79 , & V_34 -> V_61 ) ) {
F_3 ( L_47 , V_5 ) ;
goto V_210;
}
if ( F_42 ( V_34 , V_54 ) &&
! F_143 ( V_34 ) )
goto V_210;
V_208 = F_24 ( & V_34 -> V_53 ) ;
if ( V_208 ) {
if ( F_34 ( V_203 ,
& V_34 -> V_61 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_144 ( & V_34 -> V_61 , V_203 ,
V_201 ) ;
F_29 ( V_34 ) ;
goto V_209;
}
} else {
V_72 = F_132 ( V_34 , & V_206 ) ;
if ( V_72 )
goto V_210;
}
if ( ! V_72 && F_143 ( V_34 ) &&
F_43 ( V_133 , & V_34 -> V_61 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_48 , V_5 ) ;
if ( F_138 ( V_34 ) ) {
if ( V_208 )
F_140 ( V_34 ) ;
F_29 ( V_34 ) ;
F_3 ( L_49 , V_5 ) ;
goto V_209;
}
goto V_211;
}
if ( F_97 ( V_34 , & V_206 , 0 ) )
goto V_210;
F_15 ( & V_34 -> V_131 ) ;
F_7 ( & V_37 -> V_52 ) ;
if ( F_24 ( & V_34 -> V_42 ) ) {
F_5 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_34 -> V_42 ) )
F_126 ( & V_34 -> V_42 , & V_14 -> V_212 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_207 = V_206 . V_64 & ~ V_213 ;
if ( V_207 ) {
V_206 . V_64 -= V_207 ;
V_206 . V_65 += V_207 ;
}
if ( V_206 . V_65 != V_66 )
V_206 . V_65 = F_145 ( V_206 . V_65 ) ;
V_72 = F_102 ( V_34 , V_143 , & V_206 , V_38 ) ;
F_76 ( V_34 ) ;
F_37 ( & V_34 -> V_131 ) ;
V_211:
if ( V_208 )
F_140 ( V_34 ) ;
F_29 ( V_34 ) ;
V_4:
F_3 ( L_50
L_51 ,
V_5 , V_37 -> V_214 -> V_215 ,
( unsigned long long ) F_146 ( V_37 ) ,
V_72 == NULL ? L_52 : L_53 ,
V_54 == V_55 ? L_54 : L_55 ,
( unsigned long long ) V_204 ,
( unsigned long long ) V_205 ) ;
return V_72 ;
V_210:
F_7 ( & V_37 -> V_52 ) ;
goto V_211;
}
struct V_71 *
F_147 ( struct V_144 * V_145 )
{
struct V_33 * V_34 = F_28 ( V_145 -> args . V_36 ) -> V_49 ;
struct V_216 * V_217 = & V_145 -> V_217 ;
struct V_71 * V_72 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_39 ( V_108 ) ;
int V_25 = 0 ;
V_72 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_217 , V_145 -> V_38 ) ;
if ( ! V_72 || F_106 ( V_72 ) ) {
if ( ! V_72 )
V_25 = - V_151 ;
else
V_25 = F_107 ( V_72 ) ;
F_3 ( L_56 ,
V_5 , V_25 ) ;
goto V_4;
}
F_45 ( V_34 , V_72 ) ;
V_72 -> V_107 = V_217 -> V_63 ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_43 ( V_79 , & V_34 -> V_61 ) ) {
F_3 ( L_57 , V_5 ) ;
goto V_218;
}
if ( F_97 ( V_34 , & V_145 -> args . V_63 , 1 ) ) {
F_3 ( L_58 , V_5 ) ;
goto V_218;
}
if ( F_148 ( & V_34 -> V_85 , & V_217 -> V_83 ) ) {
if ( F_95 ( V_34 , & V_217 -> V_83 ) ) {
F_3 ( L_59 , V_5 ) ;
goto V_218;
}
F_92 ( V_34 , & V_217 -> V_83 , false ) ;
} else {
F_40 ( V_34 , & V_108 , NULL ) ;
F_94 ( & V_34 -> V_85 , & V_217 -> V_83 ) ;
V_34 -> V_132 = F_93 ( V_217 -> V_83 . V_130 ) ;
}
F_53 ( V_139 , & V_34 -> V_61 ) ;
F_133 ( V_72 ) ;
F_125 ( V_34 , V_72 ) ;
if ( V_217 -> V_219 ) {
F_49 ( V_169 , & V_72 -> V_77 ) ;
F_49 ( V_166 , & V_34 -> V_61 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_108 ) ;
return V_72 ;
V_4:
return F_149 ( V_25 ) ;
V_218:
F_7 ( & V_37 -> V_52 ) ;
V_72 -> V_78 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_72 ) ;
goto V_4;
}
static void
F_150 ( struct V_33 * V_34 ,
struct V_101 * V_102 ,
struct V_62 * V_161 )
{
struct V_71 * V_72 , * V_104 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return;
F_74 (lseg, next, &lo->plh_segs, pls_list)
if ( F_71 ( & V_72 -> V_107 , V_161 ) ) {
F_3 ( L_60
L_25 , V_5 ,
V_72 , V_72 -> V_107 . V_54 ,
V_72 -> V_107 . V_64 ,
V_72 -> V_107 . V_65 ) ;
F_49 ( V_82 , & V_72 -> V_77 ) ;
F_73 ( V_72 , V_102 ) ;
}
}
void F_151 ( struct V_36 * V_36 ,
struct V_71 * V_72 )
{
struct V_33 * V_34 = F_28 ( V_36 ) -> V_49 ;
int V_54 = F_32 ( V_72 -> V_107 . V_54 ) ;
struct V_62 V_63 = {
. V_54 = V_72 -> V_107 . V_54 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_39 ( V_108 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_33 ( V_34 , V_54 ) ;
F_49 ( V_133 , & V_34 -> V_61 ) ;
if ( V_34 -> V_86 == 0 )
V_34 -> V_86 = V_63 . V_54 ;
else if ( V_34 -> V_86 != V_63 . V_54 )
V_34 -> V_86 = V_100 ;
F_150 ( V_34 , & V_108 , & V_63 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_41 ( & V_108 ) ;
}
void
F_152 ( struct V_220 * V_221 , struct V_222 * V_223 )
{
T_4 V_224 = V_223 -> V_225 ;
if ( V_221 -> V_226 == NULL ) {
if ( V_221 -> V_227 == NULL )
V_224 = F_135 ( V_221 -> V_228 ) - F_153 ( V_223 ) ;
else
V_224 = F_154 ( V_221 -> V_227 ) ;
V_221 -> V_226 = F_141 ( V_221 -> V_228 ,
V_223 -> V_229 ,
F_153 ( V_223 ) ,
V_224 ,
V_176 ,
V_230 ) ;
}
if ( V_221 -> V_226 == NULL )
F_155 ( V_221 ) ;
}
void
F_156 ( struct V_220 * V_221 ,
struct V_222 * V_223 , T_4 V_231 )
{
if ( V_221 -> V_226 == NULL )
V_221 -> V_226 = F_141 ( V_221 -> V_228 ,
V_223 -> V_229 ,
F_153 ( V_223 ) ,
V_231 ,
V_55 ,
V_159 ) ;
if ( V_221 -> V_226 == NULL )
F_157 ( V_221 ) ;
}
void
F_158 ( struct V_220 * V_232 )
{
if ( V_232 -> V_226 ) {
F_58 ( V_232 -> V_226 ) ;
V_232 -> V_226 = NULL ;
}
}
T_7
F_159 ( struct V_220 * V_221 ,
struct V_222 * V_233 , struct V_222 * V_223 )
{
unsigned int V_185 ;
T_4 V_234 , V_235 , V_236 ;
V_185 = F_160 ( V_221 , V_233 , V_223 ) ;
if ( ! V_185 )
return 0 ;
if ( V_221 -> V_226 ) {
V_234 = F_68 ( V_221 -> V_226 -> V_107 . V_64 ,
V_221 -> V_226 -> V_107 . V_65 ) ;
V_235 = F_153 ( V_223 ) ;
F_161 ( V_235 >= V_234 ) ;
if ( V_235 >= V_234 ) {
if ( V_221 -> V_237 -> V_238 )
V_221 -> V_237 -> V_238 ( V_221 ) ;
if ( V_221 -> V_237 -> V_239 )
V_221 -> V_237 -> V_239 ( V_221 , V_223 ) ;
return 0 ;
}
V_236 = V_234 - V_235 ;
if ( V_236 < V_185 )
V_185 = ( unsigned int ) V_236 ;
}
return V_185 ;
}
int F_162 ( struct V_240 * V_241 )
{
struct V_220 V_221 ;
F_163 ( & V_221 , V_241 -> V_36 , V_242 , true ,
V_241 -> V_243 ) ;
return F_164 ( & V_221 , V_241 ) ;
}
static void F_165 ( struct V_240 * V_241 )
{
F_3 ( L_61 , V_241 -> V_244 ) ;
if ( F_22 ( V_241 -> V_36 ) -> V_10 -> V_154 &
V_245 ) {
F_166 ( V_241 -> V_36 ) ;
}
if ( ! F_34 ( V_246 , & V_241 -> V_154 ) )
V_241 -> V_173 . V_247 = F_162 ( V_241 ) ;
}
void F_167 ( struct V_240 * V_241 )
{
F_168 ( V_241 , V_241 -> V_244 ) ;
if ( ! V_241 -> V_244 ) {
F_169 ( V_241 -> V_36 , V_241 -> V_72 ,
V_241 -> V_248 + V_241 -> V_217 . V_205 ) ;
V_241 -> V_249 -> V_250 ( & V_241 -> V_173 , V_241 ) ;
} else
F_165 ( V_241 ) ;
V_241 -> V_249 -> V_251 ( V_241 ) ;
}
static void
F_170 ( struct V_220 * V_232 ,
struct V_240 * V_241 )
{
struct V_252 * V_253 = F_171 ( V_232 ) ;
if ( ! F_34 ( V_246 , & V_241 -> V_154 ) ) {
F_172 ( & V_241 -> V_254 , & V_253 -> V_255 ) ;
F_157 ( V_232 ) ;
V_253 -> V_256 = 1 ;
}
F_173 ( V_241 ) ;
}
static enum V_257
F_174 ( struct V_240 * V_241 ,
const struct V_258 * V_259 ,
struct V_71 * V_72 ,
int V_260 )
{
struct V_36 * V_36 = V_241 -> V_36 ;
enum V_257 V_261 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_241 -> V_249 = V_259 ;
F_3 ( L_62 , V_5 ,
V_36 -> V_116 , V_241 -> args . V_205 , V_241 -> args . V_64 , V_260 ) ;
V_261 = V_9 -> V_10 -> V_262 ( V_241 , V_260 ) ;
if ( V_261 != V_263 )
F_175 ( V_36 , V_264 ) ;
F_3 ( L_63 , V_5 , V_261 ) ;
return V_261 ;
}
static void
F_176 ( struct V_220 * V_232 ,
struct V_240 * V_241 , int V_260 )
{
const struct V_258 * V_259 = V_232 -> V_265 ;
struct V_71 * V_72 = V_232 -> V_226 ;
enum V_257 V_261 ;
V_261 = F_174 ( V_241 , V_259 , V_72 , V_260 ) ;
if ( V_261 == V_263 )
F_170 ( V_232 , V_241 ) ;
}
static void F_177 ( struct V_240 * V_241 )
{
F_58 ( V_241 -> V_72 ) ;
F_178 ( V_241 ) ;
}
int
F_179 ( struct V_220 * V_232 )
{
struct V_252 * V_253 = F_171 ( V_232 ) ;
struct V_240 * V_241 ;
int V_111 ;
V_241 = F_180 ( V_232 -> V_266 ) ;
if ( ! V_241 ) {
V_232 -> V_267 -> V_268 ( & V_253 -> V_255 ) ;
return - V_151 ;
}
F_181 ( V_232 , V_241 , F_177 ) ;
V_241 -> V_72 = F_133 ( V_232 -> V_226 ) ;
V_111 = F_182 ( V_232 , V_241 ) ;
if ( ! V_111 )
F_176 ( V_232 , V_241 , V_232 -> V_269 ) ;
return V_111 ;
}
int F_183 ( struct V_240 * V_241 )
{
struct V_220 V_221 ;
F_184 ( & V_221 , V_241 -> V_36 , true , V_241 -> V_243 ) ;
return F_164 ( & V_221 , V_241 ) ;
}
static void F_185 ( struct V_240 * V_241 )
{
F_3 ( L_64 , V_241 -> V_244 ) ;
if ( F_22 ( V_241 -> V_36 ) -> V_10 -> V_154 &
V_245 ) {
F_166 ( V_241 -> V_36 ) ;
}
if ( ! F_34 ( V_246 , & V_241 -> V_154 ) )
V_241 -> V_173 . V_247 = F_183 ( V_241 ) ;
}
void F_186 ( struct V_240 * V_241 )
{
F_187 ( V_241 , V_241 -> V_244 ) ;
if ( F_130 ( ! V_241 -> V_244 ) ) {
F_188 ( V_241 ) ;
V_241 -> V_249 -> V_250 ( & V_241 -> V_173 , V_241 ) ;
} else
F_185 ( V_241 ) ;
V_241 -> V_249 -> V_251 ( V_241 ) ;
}
static void
F_189 ( struct V_220 * V_232 ,
struct V_240 * V_241 )
{
struct V_252 * V_253 = F_171 ( V_232 ) ;
if ( ! F_34 ( V_246 , & V_241 -> V_154 ) ) {
F_172 ( & V_241 -> V_254 , & V_253 -> V_255 ) ;
F_155 ( V_232 ) ;
V_253 -> V_256 = 1 ;
}
F_173 ( V_241 ) ;
}
static enum V_257
F_190 ( struct V_240 * V_241 ,
const struct V_258 * V_259 ,
struct V_71 * V_72 )
{
struct V_36 * V_36 = V_241 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_257 V_261 ;
V_241 -> V_249 = V_259 ;
F_3 ( L_65 ,
V_5 , V_36 -> V_116 , V_241 -> args . V_205 , V_241 -> args . V_64 ) ;
V_261 = V_9 -> V_10 -> V_270 ( V_241 ) ;
if ( V_261 != V_263 )
F_175 ( V_36 , V_271 ) ;
F_3 ( L_63 , V_5 , V_261 ) ;
return V_261 ;
}
int F_191 ( struct V_240 * V_241 )
{
struct V_220 V_221 ;
F_184 ( & V_221 , V_241 -> V_36 , false , V_241 -> V_243 ) ;
return F_164 ( & V_221 , V_241 ) ;
}
static void
F_192 ( struct V_220 * V_232 , struct V_240 * V_241 )
{
const struct V_258 * V_259 = V_232 -> V_265 ;
struct V_71 * V_72 = V_232 -> V_226 ;
enum V_257 V_261 ;
int V_272 = 0 ;
V_261 = F_190 ( V_241 , V_259 , V_72 ) ;
if ( V_261 == V_273 )
V_272 = F_191 ( V_241 ) ;
if ( V_261 == V_263 || V_272 )
F_189 ( V_232 , V_241 ) ;
}
static void F_193 ( struct V_240 * V_241 )
{
F_58 ( V_241 -> V_72 ) ;
F_178 ( V_241 ) ;
}
int
F_194 ( struct V_220 * V_232 )
{
struct V_252 * V_253 = F_171 ( V_232 ) ;
struct V_240 * V_241 ;
int V_111 ;
V_241 = F_180 ( V_232 -> V_266 ) ;
if ( ! V_241 ) {
V_232 -> V_267 -> V_268 ( & V_253 -> V_255 ) ;
return - V_151 ;
}
F_181 ( V_232 , V_241 , F_193 ) ;
V_241 -> V_72 = F_133 ( V_232 -> V_226 ) ;
V_111 = F_182 ( V_232 , V_241 ) ;
if ( ! V_111 )
F_192 ( V_232 , V_241 ) ;
return V_111 ;
}
static void F_195 ( struct V_36 * V_36 )
{
unsigned long * V_202 = & F_28 ( V_36 ) -> V_154 ;
F_110 ( V_274 , V_202 ) ;
F_111 () ;
F_112 ( V_202 , V_274 ) ;
}
static void F_196 ( struct V_36 * V_36 , struct V_101 * V_275 )
{
struct V_71 * V_72 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_72 -> V_107 . V_54 == V_55 &&
F_36 ( V_155 , & V_72 -> V_77 ) )
F_17 ( & V_72 -> V_74 , V_275 ) ;
}
}
static void F_197 ( struct V_36 * V_36 , struct V_101 * V_275 )
{
struct V_71 * V_72 , * V_27 ;
F_74 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_72 -> V_74 ) ;
F_58 ( V_72 ) ;
}
F_195 ( V_36 ) ;
}
void F_198 ( struct V_71 * V_72 )
{
F_38 ( V_72 -> V_78 , V_72 -> V_107 . V_54 ) ;
}
void
F_169 ( struct V_36 * V_36 , struct V_71 * V_72 ,
T_6 V_276 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
bool V_277 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_34 ( V_153 , & V_48 -> V_154 ) ) {
V_48 -> V_49 -> V_278 = V_276 ;
V_277 = true ;
F_3 ( L_66 ,
V_5 , V_36 -> V_116 ) ;
} else if ( V_276 > V_48 -> V_49 -> V_278 )
V_48 -> V_49 -> V_278 = V_276 ;
if ( ! F_34 ( V_155 , & V_72 -> V_77 ) ) {
F_133 ( V_72 ) ;
}
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_67 ,
V_5 , V_72 , V_48 -> V_49 -> V_278 ) ;
if ( V_277 )
F_199 ( V_36 ) ;
}
void F_200 ( struct V_279 * V_280 )
{
struct V_8 * V_9 = F_22 ( V_280 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_281 )
V_9 -> V_10 -> V_281 ( V_280 ) ;
F_197 ( V_280 -> args . V_36 , & V_280 -> V_115 ) ;
}
int
F_85 ( struct V_36 * V_36 , bool V_156 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_279 * V_280 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_276 ;
int V_25 ;
if ( ! F_201 ( V_36 ) )
return 0 ;
F_3 ( L_68 , V_5 , V_36 -> V_116 ) ;
V_25 = - V_113 ;
if ( F_34 ( V_274 , & V_48 -> V_154 ) ) {
if ( ! V_156 )
goto V_4;
V_25 = F_202 ( & V_48 -> V_154 ,
V_274 ,
F_137 ,
V_282 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_151 ;
V_280 = F_103 ( sizeof( * V_280 ) , V_159 ) ;
if ( ! V_280 )
goto V_283;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_36 ( V_153 , & V_48 -> V_154 ) )
goto V_210;
F_46 ( & V_280 -> V_115 ) ;
F_196 ( V_36 , & V_280 -> V_115 ) ;
V_276 = V_48 -> V_49 -> V_278 ;
F_94 ( & V_280 -> args . V_83 , & V_48 -> V_49 -> V_85 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_280 -> args . V_36 = V_36 ;
V_280 -> V_150 = F_128 ( V_48 -> V_49 -> V_45 ) ;
F_203 ( & V_280 -> V_284 ) ;
V_280 -> args . V_285 = F_22 ( V_36 ) -> V_286 ;
V_280 -> V_217 . V_284 = & V_280 -> V_284 ;
V_280 -> args . V_287 = V_276 - 1 ;
V_280 -> V_217 . V_14 = F_22 ( V_36 ) ;
if ( V_39 -> V_288 ) {
V_25 = V_39 -> V_288 ( & V_280 -> args ) ;
if ( V_25 ) {
F_5 ( & V_36 -> V_52 ) ;
F_49 ( V_153 , & V_48 -> V_154 ) ;
if ( V_276 > V_48 -> V_49 -> V_278 )
V_48 -> V_49 -> V_278 = V_276 ;
F_7 ( & V_36 -> V_52 ) ;
F_26 ( V_280 -> V_150 ) ;
goto V_283;
}
}
V_25 = F_204 ( V_280 , V_156 ) ;
V_4:
if ( V_25 )
F_199 ( V_36 ) ;
F_3 ( L_69 , V_5 , V_25 ) ;
return V_25 ;
V_210:
F_7 ( & V_36 -> V_52 ) ;
F_205 ( V_280 ) ;
V_283:
F_195 ( V_36 ) ;
goto V_4;
}
int
F_206 ( struct V_36 * V_36 , bool V_289 )
{
return F_85 ( V_36 , true ) ;
}
struct V_181 * F_207 ( void )
{
struct V_181 * V_290 ;
V_290 = F_103 ( sizeof( * V_290 ) , V_159 ) ;
if ( ! V_290 ) {
F_3 ( L_70 , V_5 ) ;
return NULL ;
}
return V_290 ;
}
