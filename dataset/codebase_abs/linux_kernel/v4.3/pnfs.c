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
if ( ! F_36 ( V_82 , & V_72 -> V_77 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list)
if ( V_81 != V_72 && F_43 ( V_82 , & V_81 -> V_77 ) )
return false ;
return true ;
}
static bool
F_56 ( struct V_33 * V_34 )
{
if ( F_34 ( V_83 , & V_34 -> V_61 ) )
return false ;
V_34 -> V_84 = 0 ;
F_20 ( V_34 ) ;
F_53 ( V_85 , & V_34 -> V_61 ) ;
return true ;
}
static void F_57 ( struct V_71 * V_72 ,
struct V_33 * V_34 , struct V_36 * V_36 )
{
V_34 = V_72 -> V_78 ;
V_36 = V_34 -> V_41 ;
F_5 ( & V_36 -> V_52 ) ;
if ( F_55 ( V_34 , V_72 ) ) {
T_3 V_86 ;
enum V_87 V_54 ;
bool V_88 ;
V_86 = V_34 -> V_89 ;
V_54 = V_34 -> V_84 ;
V_88 = F_56 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_88 ) {
F_58 ( V_34 , V_86 , V_54 , false ) ;
}
} else
F_7 ( & V_36 -> V_52 ) ;
}
void
F_59 ( struct V_71 * V_72 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
if ( ! V_72 )
return;
F_3 ( L_21 , V_5 , V_72 ,
F_60 ( & V_72 -> V_75 ) ,
F_43 ( V_76 , & V_72 -> V_77 ) ) ;
if ( F_61 ( & V_72 -> V_75 , - 1 , 1 ) )
return;
V_34 = V_72 -> V_78 ;
V_36 = V_34 -> V_41 ;
if ( F_43 ( V_82 , & V_72 -> V_77 ) )
F_57 ( V_72 , V_34 , V_36 ) ;
if ( F_30 ( & V_72 -> V_75 , & V_36 -> V_52 ) ) {
if ( F_43 ( V_76 , & V_72 -> V_77 ) ) {
F_7 ( & V_36 -> V_52 ) ;
return;
}
F_20 ( V_34 ) ;
F_51 ( V_34 , V_72 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_50 ( V_72 ) ;
F_29 ( V_34 ) ;
}
}
static void F_62 ( struct V_90 * V_91 )
{
struct V_71 * V_72 ;
struct V_33 * V_34 ;
V_72 = F_63 ( V_91 , struct V_71 , V_92 ) ;
V_34 = V_72 -> V_78 ;
F_50 ( V_72 ) ;
F_29 ( V_34 ) ;
}
static void F_64 ( struct V_71 * V_72 )
{
F_65 ( & V_72 -> V_92 , F_62 ) ;
F_66 ( & V_72 -> V_92 ) ;
}
void
F_67 ( struct V_71 * V_72 )
{
if ( ! V_72 )
return;
F_68 ( & V_72 -> V_78 -> V_41 -> V_52 ) ;
F_3 ( L_21 , V_5 , V_72 ,
F_60 ( & V_72 -> V_75 ) ,
F_43 ( V_76 , & V_72 -> V_77 ) ) ;
if ( F_9 ( & V_72 -> V_75 ) ) {
struct V_33 * V_34 = V_72 -> V_78 ;
if ( F_43 ( V_76 , & V_72 -> V_77 ) )
return;
F_20 ( V_34 ) ;
F_51 ( V_34 , V_72 ) ;
F_64 ( V_72 ) ;
}
}
static T_4
F_69 ( T_4 V_68 , T_4 V_93 )
{
T_4 V_69 ;
V_69 = V_68 + V_93 ;
return V_69 >= V_68 ? V_69 : V_66 ;
}
static bool
F_70 ( const struct V_62 * V_94 ,
const struct V_62 * V_95 )
{
T_4 V_96 = V_94 -> V_64 ;
T_4 V_97 = F_69 ( V_96 , V_94 -> V_65 ) ;
T_4 V_98 = V_95 -> V_64 ;
T_4 V_99 = F_69 ( V_98 , V_95 -> V_65 ) ;
return ( V_96 <= V_98 ) && ( V_97 >= V_99 ) ;
}
static bool
F_71 ( const struct V_62 * V_94 ,
const struct V_62 * V_95 )
{
T_4 V_96 = V_94 -> V_64 ;
T_4 V_97 = F_69 ( V_96 , V_94 -> V_65 ) ;
T_4 V_98 = V_95 -> V_64 ;
T_4 V_99 = F_69 ( V_98 , V_95 -> V_65 ) ;
return ( V_97 == V_66 || V_97 > V_98 ) &&
( V_99 == V_66 || V_99 > V_96 ) ;
}
static bool
F_72 ( const struct V_62 * V_100 ,
const struct V_62 * V_101 )
{
return ( V_101 -> V_54 == V_102 ||
V_100 -> V_54 == V_101 -> V_54 ) &&
F_71 ( V_100 , V_101 ) ;
}
static bool F_73 ( struct V_71 * V_72 ,
struct V_103 * V_104 )
{
if ( ! F_9 ( & V_72 -> V_75 ) )
return false ;
F_51 ( V_72 -> V_78 , V_72 ) ;
F_17 ( & V_72 -> V_73 , V_104 ) ;
return true ;
}
static int F_74 ( struct V_71 * V_72 ,
struct V_103 * V_104 )
{
int V_105 = 0 ;
if ( F_36 ( V_76 , & V_72 -> V_77 ) ) {
F_3 ( L_22 , V_5 , V_72 ,
F_60 ( & V_72 -> V_75 ) ) ;
if ( F_73 ( V_72 , V_104 ) )
V_105 = 1 ;
}
return V_105 ;
}
int
F_40 ( struct V_33 * V_34 ,
struct V_103 * V_104 ,
struct V_62 * V_101 )
{
struct V_71 * V_72 , * V_106 ;
int V_107 = 0 , V_108 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_75 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_101 ||
F_72 ( & V_72 -> V_109 , V_101 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_72 , V_72 -> V_109 . V_54 , V_72 -> V_109 . V_64 ,
V_72 -> V_109 . V_65 ) ;
V_107 ++ ;
V_108 += F_74 ( V_72 , V_104 ) ;
}
F_3 ( L_26 , V_5 , V_107 - V_108 ) ;
return V_107 - V_108 ;
}
void
F_41 ( struct V_103 * V_110 )
{
struct V_71 * V_72 , * V_27 ;
if ( F_24 ( V_110 ) )
return;
F_75 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_72 -> V_73 ) ;
F_50 ( V_72 ) ;
}
}
void
F_76 ( struct V_47 * V_48 )
{
struct V_33 * V_34 ;
F_39 ( V_104 ) ;
F_5 ( & V_48 -> V_111 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
V_34 -> V_112 ++ ;
F_40 ( V_34 , & V_104 , NULL ) ;
F_20 ( V_34 ) ;
F_35 ( V_34 , V_57 ) ;
F_35 ( V_34 , V_56 ) ;
F_77 ( V_34 ) ;
F_7 ( & V_48 -> V_111 . V_52 ) ;
F_41 ( & V_104 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_111 . V_52 ) ;
}
static bool
F_78 ( struct V_36 * V_36 ,
struct V_103 * V_113 )
{
struct V_33 * V_34 ;
bool V_114 = false ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 != NULL && F_24 ( & V_34 -> V_115 ) ) {
F_20 ( V_34 ) ;
F_17 ( & V_34 -> V_115 , V_113 ) ;
V_114 = true ;
}
F_7 ( & V_36 -> V_52 ) ;
return V_114 ;
}
static int
F_79 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_103 * V_113 )
{
struct V_33 * V_34 , * V_106 ;
struct V_36 * V_36 ;
F_75 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_80 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_78 ( V_36 , V_113 ) )
continue;
F_81 () ;
F_7 ( & V_43 -> V_44 ) ;
F_82 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_83 () ;
return - V_116 ;
}
return 0 ;
}
static int
F_84 ( struct V_103 * V_113 ,
bool V_117 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
struct V_62 V_63 = {
. V_54 = V_102 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_39 ( V_118 ) ;
int V_114 = 0 ;
while ( ! F_24 ( V_113 ) ) {
V_34 = F_85 ( V_113 -> V_106 , struct V_33 ,
V_115 ) ;
F_3 ( L_27 , V_5 ,
V_34 -> V_41 -> V_119 ) ;
V_36 = V_34 -> V_41 ;
F_86 ( V_36 , false ) ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_115 ) ;
V_34 -> V_112 ++ ;
if ( V_117 )
F_49 ( V_79 , & V_34 -> V_61 ) ;
if ( F_40 ( V_34 , & V_118 , & V_63 ) )
V_114 = - V_116 ;
F_7 ( & V_36 -> V_52 ) ;
F_41 ( & V_118 ) ;
F_29 ( V_34 ) ;
F_82 ( V_36 ) ;
}
return V_114 ;
}
int
F_87 ( struct V_12 * V_43 ,
struct V_120 * V_121 ,
bool V_122 )
{
struct V_8 * V_14 ;
F_39 ( V_113 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_83 () ;
V_123:
F_88 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_121 , V_121 , sizeof( * V_121 ) ) != 0 )
continue;
if ( F_79 ( V_43 ,
V_14 ,
& V_113 ) != 0 )
goto V_123;
}
F_81 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_113 ) )
return 0 ;
return F_84 ( & V_113 , V_122 ) ;
}
int
F_89 ( struct V_12 * V_43 ,
bool V_122 )
{
struct V_8 * V_14 ;
F_39 ( V_113 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_83 () ;
V_123:
F_88 (server, &clp->cl_superblocks, client_link) {
if ( F_79 ( V_43 ,
V_14 ,
& V_113 ) != 0 )
goto V_123;
}
F_81 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_113 ) )
return 0 ;
return F_84 ( & V_113 , V_122 ) ;
}
void
F_90 ( struct V_12 * V_43 )
{
F_91 ( V_43 ) ;
F_10 ( V_43 ) ;
F_89 ( V_43 , false ) ;
}
static bool F_92 ( T_1 V_124 , T_1 V_125 )
{
return ( V_126 ) ( V_124 - V_125 ) > 0 ;
}
void
F_93 ( struct V_33 * V_34 , const T_3 * V_127 ,
bool V_128 )
{
T_1 V_129 , V_130 , V_131 ;
int V_132 = F_24 ( & V_34 -> V_53 ) ;
V_129 = F_94 ( V_34 -> V_89 . V_133 ) ;
V_130 = F_94 ( V_127 -> V_133 ) ;
if ( V_132 || F_92 ( V_130 , V_129 ) ) {
F_95 ( & V_34 -> V_89 , V_127 ) ;
if ( V_128 ) {
V_131 = F_94 ( V_127 -> V_133 ) ;
} else {
V_131 = V_130 - F_60 ( & V_34 -> V_134 ) ;
}
if ( V_132 || F_92 ( V_131 , V_34 -> V_135 ) )
V_34 -> V_135 = V_131 ;
}
}
static bool
F_96 ( const struct V_33 * V_34 ,
const T_3 * V_86 )
{
T_1 V_133 = F_94 ( V_86 -> V_133 ) ;
return ! F_92 ( V_133 , V_34 -> V_135 ) ;
}
static bool
F_97 ( const struct V_33 * V_34 )
{
return V_34 -> V_112 ||
F_43 ( V_79 , & V_34 -> V_61 ) ;
}
int
F_98 ( T_3 * V_136 , struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_137 * V_138 )
{
int V_25 = 0 ;
F_3 ( L_28 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_97 ( V_34 ) ) {
V_25 = - V_116 ;
} else if ( ! F_99 ( V_138 ) ) {
V_25 = - V_139 ;
} else if ( F_24 ( & V_34 -> V_53 ) ||
F_43 ( V_140 , & V_34 -> V_61 ) ) {
int V_141 ;
do {
V_141 = F_100 ( & V_138 -> V_142 ) ;
F_95 ( V_136 , & V_138 -> V_86 ) ;
} while ( F_101 ( & V_138 -> V_142 , V_141 ) );
} else
F_95 ( V_136 , & V_34 -> V_89 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_29 , V_5 ) ;
return V_25 ;
}
static struct V_71 *
F_102 ( struct V_33 * V_34 ,
struct V_143 * V_144 ,
struct V_62 * V_63 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_145 * V_146 ;
struct V_71 * V_72 ;
T_5 V_147 ;
F_3 ( L_28 , V_5 ) ;
V_146 = F_103 ( sizeof( * V_146 ) , V_38 ) ;
if ( V_146 == NULL )
return NULL ;
V_147 = F_104 ( V_37 ) ;
V_146 -> args . V_148 = V_149 ;
if ( V_146 -> args . V_148 > V_63 -> V_65 )
V_146 -> args . V_148 = V_63 -> V_65 ;
if ( V_63 -> V_54 == V_150 ) {
if ( V_63 -> V_64 >= V_147 )
V_146 -> args . V_148 = 0 ;
else if ( V_147 - V_63 -> V_64 < V_146 -> args . V_148 )
V_146 -> args . V_148 = V_147 - V_63 -> V_64 ;
}
V_146 -> args . V_151 = V_152 ;
V_146 -> args . V_63 = * V_63 ;
V_146 -> args . type = V_14 -> V_10 -> V_2 ;
V_146 -> args . V_36 = V_37 ;
V_146 -> args . V_144 = F_105 ( V_144 ) ;
V_146 -> V_38 = V_38 ;
V_146 -> V_153 = V_34 -> V_45 ;
V_72 = F_106 ( V_146 , V_38 ) ;
if ( F_107 ( V_72 ) ) {
switch ( F_108 ( V_72 ) ) {
case - V_154 :
case - V_155 :
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
static void F_109 ( struct V_36 * V_36 ,
struct V_103 * V_67 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_71 * V_72 , * V_27 ;
if ( ! F_36 ( V_156 , & V_48 -> V_157 ) )
return;
F_75 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_36 ( V_158 , & V_72 -> V_77 ) )
continue;
F_73 ( V_72 , V_67 ) ;
}
}
void F_110 ( struct V_33 * V_34 )
{
F_111 ( V_83 , & V_34 -> V_61 ) ;
F_112 () ;
F_113 ( & V_34 -> V_61 , V_83 ) ;
F_54 ( & F_22 ( V_34 -> V_41 ) -> V_80 ) ;
}
static int
F_58 ( struct V_33 * V_34 , T_3 V_86 ,
enum V_87 V_54 , bool V_159 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_160 * V_161 ;
int V_25 = 0 ;
V_161 = F_103 ( sizeof( * V_161 ) , V_162 ) ;
if ( F_114 ( V_161 == NULL ) ) {
V_25 = - V_154 ;
F_5 ( & V_37 -> V_52 ) ;
F_110 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_161 -> args . V_86 = V_86 ;
V_161 -> args . V_163 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_161 -> args . V_36 = V_37 ;
V_161 -> args . V_63 . V_54 = V_54 ;
V_161 -> args . V_63 . V_64 = 0 ;
V_161 -> args . V_63 . V_65 = V_66 ;
V_161 -> args . V_49 = V_34 ;
V_161 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_161 -> V_153 = V_34 -> V_45 ;
V_25 = F_115 ( V_161 , V_159 ) ;
V_4:
F_3 ( L_30 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_116 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_39 ( V_104 ) ;
T_3 V_86 ;
int V_25 = 0 , V_132 ;
bool V_88 ;
F_3 ( L_31 , V_5 , V_37 -> V_119 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_4;
}
V_86 = V_48 -> V_49 -> V_89 ;
F_20 ( V_34 ) ;
V_132 = F_24 ( & V_34 -> V_53 ) ;
F_109 ( V_37 , & V_104 ) ;
F_40 ( V_34 , & V_104 , NULL ) ;
if ( F_22 ( V_37 ) -> V_10 -> V_164 ) {
struct V_62 V_63 = {
. V_54 = V_102 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_22 ( V_37 ) -> V_10 -> V_164 ( V_34 , & V_63 ) ;
}
if ( V_132 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_33 , V_5 ) ;
goto V_165;
}
F_49 ( V_140 , & V_34 -> V_61 ) ;
V_88 = F_56 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_104 ) ;
if ( V_88 )
V_25 = F_58 ( V_34 , V_86 , V_102 , true ) ;
V_165:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_30 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_117 ( struct V_36 * V_36 )
{
struct V_33 * V_34 ;
int V_114 ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 == NULL ) {
F_7 ( & V_36 -> V_52 ) ;
return 0 ;
}
F_20 ( V_34 ) ;
V_34 -> V_112 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_118 ( V_36 -> V_166 ) ;
V_114 = F_86 ( V_36 , true ) ;
if ( V_114 == 0 )
V_114 = F_116 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_112 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_114 ;
}
bool F_119 ( struct V_36 * V_37 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_143 * V_144 ;
struct V_137 * V_167 ;
struct V_33 * V_34 ;
struct V_71 * V_72 , * V_27 ;
T_3 V_86 ;
F_39 ( V_104 ) ;
bool V_168 = false , V_169 = false , V_170 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 || F_43 ( V_79 , & V_34 -> V_61 ) )
goto V_171;
if ( F_120 ( V_37 , V_172 ) )
goto V_171;
F_2 (ctx, &nfsi->open_files, list) {
V_167 = V_144 -> V_167 ;
if ( V_167 != NULL && V_167 -> V_167 != 0 )
goto V_171;
}
V_86 = V_34 -> V_89 ;
if ( F_36 ( V_85 ,
& V_34 -> V_61 ) )
V_169 = F_56 ( V_34 ) ;
F_77 ( V_34 ) ;
F_75 (lseg, tmp, &lo->plh_segs, pls_list)
if ( V_169 || F_43 ( V_173 , & V_72 -> V_77 ) ) {
F_74 ( V_72 , & V_104 ) ;
V_168 = true ;
}
if ( V_168 && ! V_169 ) {
F_20 ( V_34 ) ;
V_170 = true ;
}
V_171:
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_104 ) ;
F_86 ( V_37 , true ) ;
if ( V_169 )
F_58 ( V_34 , V_86 , V_102 , true ) ;
return V_170 ;
}
void F_121 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
F_110 ( V_34 ) ;
if ( F_9 ( & V_34 -> V_35 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_23 ( V_34 ) ;
} else
F_7 ( & V_37 -> V_52 ) ;
}
void F_122 ( struct V_36 * V_37 , T_1 V_174 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_92 ( V_174 , V_34 -> V_135 ) )
V_34 -> V_135 = V_174 ;
F_7 ( & V_37 -> V_52 ) ;
F_123 ( V_37 , 0 ) ;
}
void F_124 ( struct V_36 * V_37 , T_1 * V_174 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
T_1 V_175 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
V_175 = F_94 ( V_34 -> V_89 . V_133 ) ;
* V_174 = V_175 + F_60 ( & V_34 -> V_134 ) ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_125 ( struct V_36 * V_37 , struct V_176 * V_177 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
bool V_178 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 && F_43 ( V_83 , & V_34 -> V_61 ) )
V_178 = true ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_178 )
F_126 ( & F_22 ( V_37 ) -> V_80 , V_177 , NULL ) ;
return V_178 ;
}
static T_6
F_127 ( const struct V_62 * V_94 ,
const struct V_62 * V_95 )
{
T_6 V_179 ;
V_179 = V_94 -> V_64 - V_95 -> V_64 ;
if ( V_179 )
return V_179 ;
V_179 = V_95 -> V_65 - V_94 -> V_65 ;
if ( V_179 )
return V_179 ;
return ( int ) ( V_94 -> V_54 == V_150 ) - ( int ) ( V_95 -> V_54 == V_150 ) ;
}
static bool
F_128 ( const struct V_62 * V_94 ,
const struct V_62 * V_95 )
{
return F_127 ( V_94 , V_95 ) > 0 ;
}
static bool
F_129 ( struct V_71 * V_72 ,
struct V_71 * V_180 )
{
return false ;
}
void
F_130 ( struct V_33 * V_34 ,
struct V_71 * V_72 ,
bool (* F_131)( const struct V_62 * ,
const struct V_62 * ) ,
bool (* F_132)( struct V_71 * ,
struct V_71 * ) ,
struct V_103 * V_110 )
{
struct V_71 * V_181 , * V_27 ;
F_3 ( L_34 , V_5 ) ;
F_75 (lp, tmp, &lo->plh_segs, pls_list) {
if ( F_43 ( V_76 , & V_181 -> V_77 ) == 0 )
continue;
if ( F_132 ( V_72 , V_181 ) ) {
F_74 ( V_181 , V_110 ) ;
continue;
}
if ( F_131 ( & V_72 -> V_109 , & V_181 -> V_109 ) )
continue;
F_133 ( & V_72 -> V_73 , & V_181 -> V_73 ) ;
F_3 ( L_35
L_36
L_37 ,
V_5 , V_72 , V_72 -> V_109 . V_54 ,
V_72 -> V_109 . V_64 , V_72 -> V_109 . V_65 ,
V_181 , V_181 -> V_109 . V_54 , V_181 -> V_109 . V_64 ,
V_181 -> V_109 . V_65 ) ;
goto V_4;
}
F_133 ( & V_72 -> V_73 , & V_34 -> V_53 ) ;
F_3 ( L_35
L_38 ,
V_5 , V_72 , V_72 -> V_109 . V_54 ,
V_72 -> V_109 . V_64 , V_72 -> V_109 . V_65 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_39 , V_5 ) ;
}
static void
F_134 ( struct V_33 * V_34 ,
struct V_71 * V_72 ,
struct V_103 * V_110 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
if ( V_39 -> V_182 != NULL )
V_39 -> V_182 ( V_34 , V_72 , V_110 ) ;
else
F_130 ( V_34 , V_72 ,
F_128 ,
F_129 ,
V_110 ) ;
}
static struct V_33 *
F_135 ( struct V_36 * V_37 ,
struct V_143 * V_144 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_47 ( & V_34 -> V_35 , 1 ) ;
F_46 ( & V_34 -> V_42 ) ;
F_46 ( & V_34 -> V_53 ) ;
F_46 ( & V_34 -> V_115 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_136 ( V_144 -> V_153 ) ;
return V_34 ;
}
static struct V_33 *
F_137 ( struct V_36 * V_37 ,
struct V_143 * V_144 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_127 = NULL ;
F_3 ( L_40 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_183;
F_7 ( & V_37 -> V_52 ) ;
V_127 = F_135 ( V_37 , V_144 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_138 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_127 ;
return V_127 ;
} else if ( V_127 != NULL )
F_23 ( V_127 ) ;
V_183:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_139 ( const struct V_62 * V_184 ,
const struct V_62 * V_63 )
{
struct V_62 V_185 ;
if ( ( V_63 -> V_54 == V_55 &&
V_184 -> V_54 != V_55 ) ||
! F_71 ( V_184 , V_63 ) )
return 0 ;
V_185 = * V_63 ;
V_185 . V_65 = 1 ;
return F_70 ( V_184 , & V_185 ) ;
}
static struct V_71 *
F_140 ( struct V_33 * V_34 ,
struct V_62 * V_63 )
{
struct V_71 * V_72 , * V_114 = NULL ;
F_3 ( L_34 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_43 ( V_76 , & V_72 -> V_77 ) &&
! F_43 ( V_82 , & V_72 -> V_77 ) &&
F_139 ( & V_72 -> V_109 , V_63 ) ) {
V_114 = F_141 ( V_72 ) ;
break;
}
}
F_3 ( L_41 ,
V_5 , V_114 , V_114 ? F_60 ( & V_114 -> V_75 ) : 0 ) ;
return V_114 ;
}
static bool F_142 ( struct V_143 * V_144 ,
struct V_36 * V_37 , int V_54 )
{
struct V_186 * V_187 = V_144 -> V_188 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_5 V_189 = F_104 ( V_37 ) ;
bool V_190 = false , V_191 = false , V_192 = false , V_193 = false , V_114 = false ;
if ( V_187 == NULL )
return V_114 ;
F_3 ( L_42 ,
V_5 , V_187 -> V_194 , V_187 -> V_195 , V_187 -> V_196 , V_187 -> V_197 , V_187 -> V_198 ) ;
switch ( V_54 ) {
case V_150 :
if ( V_187 -> V_194 & V_199 ) {
F_3 ( L_43 , V_5 , V_189 ) ;
V_191 = true ;
if ( V_189 < V_187 -> V_195 )
V_190 = true ;
}
if ( V_187 -> V_194 & V_200 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_51 ) ;
V_193 = true ;
if ( V_48 -> V_51 < V_187 -> V_197 )
V_192 = true ;
}
break;
case V_55 :
if ( V_187 -> V_194 & V_201 ) {
F_3 ( L_43 , V_5 , V_189 ) ;
V_191 = true ;
if ( V_189 < V_187 -> V_196 )
V_190 = true ;
}
if ( V_187 -> V_194 & V_202 ) {
F_3 ( L_45 , V_5 ,
V_48 -> V_50 ) ;
V_193 = true ;
if ( V_48 -> V_50 < V_187 -> V_198 )
V_192 = true ;
}
break;
}
if ( V_191 && V_193 ) {
if ( V_190 && V_192 )
V_114 = true ;
} else if ( V_190 || V_192 )
V_114 = true ;
F_3 ( L_46 , V_5 , V_190 , V_192 , V_114 ) ;
return V_114 ;
}
static int F_143 ( struct V_203 * V_204 )
{
if ( ! F_43 ( V_205 , V_204 -> V_157 ) )
return 1 ;
return F_144 ( V_204 ) ;
}
static bool F_145 ( struct V_33 * V_34 )
{
if ( ! F_146 ( V_34 ) )
return false ;
F_86 ( V_34 -> V_41 , false ) ;
return ! F_147 ( & V_34 -> V_61 , V_83 ,
F_143 ,
V_206 ) ;
}
static void F_148 ( struct V_33 * V_34 )
{
unsigned long * V_207 = & V_34 -> V_61 ;
F_111 ( V_208 , V_207 ) ;
F_112 () ;
F_113 ( V_207 , V_208 ) ;
}
struct V_71 *
F_149 ( struct V_36 * V_37 ,
struct V_143 * V_144 ,
T_5 V_209 ,
T_4 V_210 ,
enum V_87 V_54 ,
T_2 V_38 )
{
struct V_62 V_211 = {
. V_54 = V_54 ,
. V_64 = V_209 ,
. V_65 = V_210 ,
} ;
unsigned V_212 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_71 * V_72 = NULL ;
bool V_213 ;
if ( ! F_150 ( F_22 ( V_37 ) ) )
goto V_4;
if ( V_54 == V_150 && F_104 ( V_37 ) == 0 )
goto V_4;
if ( F_142 ( V_144 , V_37 , V_54 ) )
goto V_4;
V_214:
V_213 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_137 ( V_37 , V_144 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
goto V_4;
}
if ( F_43 ( V_79 , & V_34 -> V_61 ) ) {
F_3 ( L_47 , V_5 ) ;
goto V_215;
}
if ( F_42 ( V_34 , V_54 ) &&
! F_146 ( V_34 ) )
goto V_215;
V_213 = F_24 ( & V_34 -> V_53 ) ;
if ( V_213 ) {
if ( F_34 ( V_208 ,
& V_34 -> V_61 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_151 ( & V_34 -> V_61 , V_208 ,
V_206 ) ;
F_29 ( V_34 ) ;
goto V_214;
}
} else {
V_72 = F_140 ( V_34 , & V_211 ) ;
if ( V_72 )
goto V_215;
}
if ( F_43 ( V_83 , & V_34 -> V_61 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_48 , V_5 ) ;
if ( F_145 ( V_34 ) ) {
if ( V_213 )
F_148 ( V_34 ) ;
F_29 ( V_34 ) ;
F_3 ( L_49 , V_5 ) ;
goto V_214;
}
goto V_165;
}
if ( F_97 ( V_34 ) )
goto V_215;
F_15 ( & V_34 -> V_134 ) ;
F_7 ( & V_37 -> V_52 ) ;
if ( F_24 ( & V_34 -> V_42 ) ) {
F_5 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_34 -> V_42 ) )
F_133 ( & V_34 -> V_42 , & V_14 -> V_216 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_212 = V_211 . V_64 & ~ V_217 ;
if ( V_212 ) {
V_211 . V_64 -= V_212 ;
V_211 . V_65 += V_212 ;
}
if ( V_211 . V_65 != V_66 )
V_211 . V_65 = F_152 ( V_211 . V_65 ) ;
V_72 = F_102 ( V_34 , V_144 , & V_211 , V_38 ) ;
F_77 ( V_34 ) ;
F_37 ( & V_34 -> V_134 ) ;
V_165:
if ( V_213 )
F_148 ( V_34 ) ;
F_29 ( V_34 ) ;
V_4:
F_3 ( L_50
L_51 ,
V_5 , V_37 -> V_218 -> V_219 ,
( unsigned long long ) F_153 ( V_37 ) ,
V_72 == NULL ? L_52 : L_53 ,
V_54 == V_55 ? L_54 : L_55 ,
( unsigned long long ) V_209 ,
( unsigned long long ) V_210 ) ;
return V_72 ;
V_215:
F_7 ( & V_37 -> V_52 ) ;
goto V_165;
}
static bool
F_154 ( struct V_62 * V_63 )
{
switch ( V_63 -> V_54 ) {
case V_150 :
case V_55 :
break;
default:
return false ;
}
if ( V_63 -> V_64 == V_66 )
return false ;
if ( V_63 -> V_65 == 0 )
return false ;
if ( V_63 -> V_65 != V_66 &&
V_63 -> V_65 > V_66 - V_63 -> V_64 )
return false ;
return true ;
}
struct V_71 *
F_155 ( struct V_145 * V_146 )
{
struct V_33 * V_34 = F_28 ( V_146 -> args . V_36 ) -> V_49 ;
struct V_220 * V_221 = & V_146 -> V_221 ;
struct V_71 * V_72 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_39 ( V_110 ) ;
int V_25 = - V_26 ;
if ( ! F_154 ( & V_221 -> V_63 ) )
goto V_4;
V_72 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_221 , V_146 -> V_38 ) ;
if ( ! V_72 || F_107 ( V_72 ) ) {
if ( ! V_72 )
V_25 = - V_154 ;
else
V_25 = F_108 ( V_72 ) ;
F_3 ( L_56 ,
V_5 , V_25 ) ;
goto V_4;
}
F_45 ( V_34 , V_72 ) ;
V_72 -> V_109 = V_221 -> V_63 ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_97 ( V_34 ) ) {
F_3 ( L_57 , V_5 ) ;
goto V_222;
}
if ( F_156 ( & V_34 -> V_89 , & V_221 -> V_86 ) ) {
if ( F_96 ( V_34 , & V_221 -> V_86 ) ) {
F_3 ( L_58 , V_5 ) ;
goto V_222;
}
F_93 ( V_34 , & V_221 -> V_86 , false ) ;
} else {
F_40 ( V_34 , & V_110 , NULL ) ;
F_95 ( & V_34 -> V_89 , & V_221 -> V_86 ) ;
V_34 -> V_135 = F_94 ( V_221 -> V_86 . V_133 ) ;
}
F_53 ( V_140 , & V_34 -> V_61 ) ;
F_141 ( V_72 ) ;
F_134 ( V_34 , V_72 , & V_110 ) ;
if ( V_221 -> V_223 )
F_49 ( V_173 , & V_72 -> V_77 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_110 ) ;
return V_72 ;
V_4:
return F_157 ( V_25 ) ;
V_222:
F_7 ( & V_37 -> V_52 ) ;
V_72 -> V_78 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_72 ) ;
goto V_4;
}
static void
F_158 ( struct V_33 * V_34 ,
struct V_103 * V_104 ,
struct V_62 * V_164 )
{
struct V_71 * V_72 , * V_106 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return;
F_75 (lseg, next, &lo->plh_segs, pls_list)
if ( F_72 ( & V_72 -> V_109 , V_164 ) ) {
F_3 ( L_59
L_25 , V_5 ,
V_72 , V_72 -> V_109 . V_54 ,
V_72 -> V_109 . V_64 ,
V_72 -> V_109 . V_65 ) ;
F_49 ( V_82 , & V_72 -> V_77 ) ;
F_74 ( V_72 , V_104 ) ;
F_49 ( V_85 ,
& V_34 -> V_61 ) ;
}
}
void F_159 ( struct V_36 * V_36 ,
struct V_71 * V_72 )
{
struct V_33 * V_34 = F_28 ( V_36 ) -> V_49 ;
int V_54 = F_32 ( V_72 -> V_109 . V_54 ) ;
struct V_62 V_63 = {
. V_54 = V_72 -> V_109 . V_54 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_39 ( V_110 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_33 ( V_34 , V_54 ) ;
if ( V_34 -> V_84 == 0 )
V_34 -> V_84 = V_63 . V_54 ;
else if ( V_34 -> V_84 != V_63 . V_54 )
V_34 -> V_84 = V_102 ;
F_158 ( V_34 , & V_110 , & V_63 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_41 ( & V_110 ) ;
}
void
F_160 ( struct V_224 * V_225 , struct V_226 * V_227 )
{
T_4 V_228 = V_227 -> V_229 ;
if ( V_225 -> V_230 == NULL ) {
if ( V_225 -> V_231 == NULL )
V_228 = F_104 ( V_225 -> V_232 ) - F_161 ( V_227 ) ;
else
V_228 = F_162 ( V_225 -> V_231 ) ;
V_225 -> V_230 = F_149 ( V_225 -> V_232 ,
V_227 -> V_233 ,
F_161 ( V_227 ) ,
V_228 ,
V_150 ,
V_234 ) ;
}
if ( V_225 -> V_230 == NULL )
F_163 ( V_225 ) ;
}
void
F_164 ( struct V_224 * V_225 ,
struct V_226 * V_227 , T_4 V_235 )
{
if ( V_225 -> V_230 == NULL )
V_225 -> V_230 = F_149 ( V_225 -> V_232 ,
V_227 -> V_233 ,
F_161 ( V_227 ) ,
V_235 ,
V_55 ,
V_162 ) ;
if ( V_225 -> V_230 == NULL )
F_165 ( V_225 ) ;
}
void
F_166 ( struct V_224 * V_236 )
{
if ( V_236 -> V_230 ) {
F_59 ( V_236 -> V_230 ) ;
V_236 -> V_230 = NULL ;
}
}
T_7
F_167 ( struct V_224 * V_225 ,
struct V_226 * V_237 , struct V_226 * V_227 )
{
unsigned int V_190 ;
T_4 V_238 , V_239 , V_240 ;
V_190 = F_168 ( V_225 , V_237 , V_227 ) ;
if ( ! V_190 )
return 0 ;
if ( V_225 -> V_230 ) {
V_238 = F_69 ( V_225 -> V_230 -> V_109 . V_64 ,
V_225 -> V_230 -> V_109 . V_65 ) ;
V_239 = F_161 ( V_227 ) ;
F_169 ( V_239 >= V_238 ) ;
if ( V_239 >= V_238 ) {
if ( V_225 -> V_241 -> V_242 )
V_225 -> V_241 -> V_242 ( V_225 ) ;
if ( V_225 -> V_241 -> V_243 )
V_225 -> V_241 -> V_243 ( V_225 , V_227 ) ;
return 0 ;
}
V_240 = V_238 - V_239 ;
if ( V_240 < V_190 )
V_190 = ( unsigned int ) V_240 ;
}
return V_190 ;
}
int F_170 ( struct V_244 * V_245 )
{
struct V_224 V_225 ;
F_171 ( & V_225 , V_245 -> V_36 , V_246 , true ,
V_245 -> V_247 ) ;
F_49 ( V_248 , & V_245 -> args . V_249 -> V_157 ) ;
return F_172 ( & V_225 , V_245 ) ;
}
static void F_173 ( struct V_244 * V_245 )
{
F_3 ( L_60 , V_245 -> V_250 ) ;
if ( F_22 ( V_245 -> V_36 ) -> V_10 -> V_157 &
V_251 ) {
F_174 ( V_245 -> V_36 ) ;
}
if ( ! F_34 ( V_252 , & V_245 -> V_157 ) )
V_245 -> V_177 . V_253 = F_170 ( V_245 ) ;
}
void F_175 ( struct V_244 * V_245 )
{
F_176 ( V_245 , V_245 -> V_250 ) ;
if ( ! V_245 -> V_250 ) {
F_177 ( V_245 -> V_36 , V_245 -> V_72 ,
V_245 -> V_254 + V_245 -> V_221 . V_210 ) ;
V_245 -> V_255 -> V_256 ( & V_245 -> V_177 , V_245 ) ;
} else
F_173 ( V_245 ) ;
V_245 -> V_255 -> V_257 ( V_245 ) ;
}
static void
F_178 ( struct V_224 * V_236 ,
struct V_244 * V_245 )
{
struct V_258 * V_259 = F_179 ( V_236 ) ;
if ( ! F_34 ( V_252 , & V_245 -> V_157 ) ) {
F_180 ( & V_245 -> V_260 , & V_259 -> V_261 ) ;
F_165 ( V_236 ) ;
V_259 -> V_262 = 1 ;
}
F_181 ( V_245 ) ;
V_245 -> V_263 ( V_245 ) ;
}
static enum V_264
F_182 ( struct V_244 * V_245 ,
const struct V_265 * V_266 ,
struct V_71 * V_72 ,
int V_267 )
{
struct V_36 * V_36 = V_245 -> V_36 ;
enum V_264 V_268 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_245 -> V_255 = V_266 ;
F_3 ( L_61 , V_5 ,
V_36 -> V_119 , V_245 -> args . V_210 , V_245 -> args . V_64 , V_267 ) ;
V_268 = V_9 -> V_10 -> V_269 ( V_245 , V_267 ) ;
if ( V_268 != V_270 )
F_183 ( V_36 , V_271 ) ;
F_3 ( L_62 , V_5 , V_268 ) ;
return V_268 ;
}
static void
F_184 ( struct V_224 * V_236 ,
struct V_244 * V_245 , int V_267 )
{
const struct V_265 * V_266 = V_236 -> V_272 ;
struct V_71 * V_72 = V_236 -> V_230 ;
enum V_264 V_268 ;
V_268 = F_182 ( V_245 , V_266 , V_72 , V_267 ) ;
if ( V_268 == V_270 )
F_178 ( V_236 , V_245 ) ;
}
static void F_185 ( struct V_244 * V_245 )
{
F_59 ( V_245 -> V_72 ) ;
F_186 ( V_245 ) ;
}
int
F_187 ( struct V_224 * V_236 )
{
struct V_258 * V_259 = F_179 ( V_236 ) ;
struct V_244 * V_245 ;
int V_114 ;
V_245 = F_188 ( V_236 -> V_273 ) ;
if ( ! V_245 ) {
V_236 -> V_274 -> V_275 ( & V_259 -> V_261 ) ;
return - V_154 ;
}
F_189 ( V_236 , V_245 , F_185 ) ;
V_245 -> V_72 = F_141 ( V_236 -> V_230 ) ;
V_114 = F_190 ( V_236 , V_245 ) ;
if ( ! V_114 )
F_184 ( V_236 , V_245 , V_236 -> V_276 ) ;
return V_114 ;
}
int F_191 ( struct V_244 * V_245 )
{
struct V_224 V_225 ;
F_192 ( & V_225 , V_245 -> V_36 , true , V_245 -> V_247 ) ;
return F_172 ( & V_225 , V_245 ) ;
}
static void F_193 ( struct V_244 * V_245 )
{
F_3 ( L_63 , V_245 -> V_250 ) ;
if ( F_22 ( V_245 -> V_36 ) -> V_10 -> V_157 &
V_251 ) {
F_174 ( V_245 -> V_36 ) ;
}
if ( ! F_34 ( V_252 , & V_245 -> V_157 ) )
V_245 -> V_177 . V_253 = F_191 ( V_245 ) ;
}
void F_194 ( struct V_244 * V_245 )
{
F_195 ( V_245 , V_245 -> V_250 ) ;
if ( F_138 ( ! V_245 -> V_250 ) ) {
F_196 ( V_245 ) ;
V_245 -> V_255 -> V_256 ( & V_245 -> V_177 , V_245 ) ;
} else
F_193 ( V_245 ) ;
V_245 -> V_255 -> V_257 ( V_245 ) ;
}
static void
F_197 ( struct V_224 * V_236 ,
struct V_244 * V_245 )
{
struct V_258 * V_259 = F_179 ( V_236 ) ;
if ( ! F_34 ( V_252 , & V_245 -> V_157 ) ) {
F_180 ( & V_245 -> V_260 , & V_259 -> V_261 ) ;
F_163 ( V_236 ) ;
V_259 -> V_262 = 1 ;
}
F_181 ( V_245 ) ;
V_245 -> V_263 ( V_245 ) ;
}
static enum V_264
F_198 ( struct V_244 * V_245 ,
const struct V_265 * V_266 ,
struct V_71 * V_72 )
{
struct V_36 * V_36 = V_245 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_264 V_268 ;
V_245 -> V_255 = V_266 ;
F_3 ( L_64 ,
V_5 , V_36 -> V_119 , V_245 -> args . V_210 , V_245 -> args . V_64 ) ;
V_268 = V_9 -> V_10 -> V_277 ( V_245 ) ;
if ( V_268 != V_270 )
F_183 ( V_36 , V_278 ) ;
F_3 ( L_62 , V_5 , V_268 ) ;
return V_268 ;
}
int F_199 ( struct V_244 * V_245 )
{
struct V_224 V_225 ;
F_192 ( & V_225 , V_245 -> V_36 , false , V_245 -> V_247 ) ;
return F_172 ( & V_225 , V_245 ) ;
}
static void
F_200 ( struct V_224 * V_236 , struct V_244 * V_245 )
{
const struct V_265 * V_266 = V_236 -> V_272 ;
struct V_71 * V_72 = V_236 -> V_230 ;
enum V_264 V_268 ;
int V_279 = 0 ;
V_268 = F_198 ( V_245 , V_266 , V_72 ) ;
if ( V_268 == V_280 )
V_279 = F_199 ( V_245 ) ;
if ( V_268 == V_270 || V_279 )
F_197 ( V_236 , V_245 ) ;
}
static void F_201 ( struct V_244 * V_245 )
{
F_59 ( V_245 -> V_72 ) ;
F_186 ( V_245 ) ;
}
int
F_202 ( struct V_224 * V_236 )
{
struct V_258 * V_259 = F_179 ( V_236 ) ;
struct V_244 * V_245 ;
int V_114 ;
V_245 = F_188 ( V_236 -> V_273 ) ;
if ( ! V_245 ) {
V_236 -> V_274 -> V_275 ( & V_259 -> V_261 ) ;
return - V_154 ;
}
F_189 ( V_236 , V_245 , F_201 ) ;
V_245 -> V_72 = F_141 ( V_236 -> V_230 ) ;
V_114 = F_190 ( V_236 , V_245 ) ;
if ( ! V_114 )
F_200 ( V_236 , V_245 ) ;
return V_114 ;
}
static void F_203 ( struct V_36 * V_36 )
{
unsigned long * V_207 = & F_28 ( V_36 ) -> V_157 ;
F_111 ( V_281 , V_207 ) ;
F_112 () ;
F_113 ( V_207 , V_281 ) ;
}
static void F_204 ( struct V_36 * V_36 , struct V_103 * V_282 )
{
struct V_71 * V_72 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_72 -> V_109 . V_54 == V_55 &&
F_36 ( V_158 , & V_72 -> V_77 ) )
F_17 ( & V_72 -> V_74 , V_282 ) ;
}
}
static void F_205 ( struct V_36 * V_36 , struct V_103 * V_282 )
{
struct V_71 * V_72 , * V_27 ;
F_75 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_72 -> V_74 ) ;
F_59 ( V_72 ) ;
}
F_203 ( V_36 ) ;
}
void F_206 ( struct V_71 * V_72 )
{
F_38 ( V_72 -> V_78 , V_72 -> V_109 . V_54 ) ;
}
void
F_177 ( struct V_36 * V_36 , struct V_71 * V_72 ,
T_5 V_283 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
bool V_284 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_34 ( V_156 , & V_48 -> V_157 ) ) {
V_48 -> V_49 -> V_285 = V_283 ;
V_284 = true ;
F_3 ( L_65 ,
V_5 , V_36 -> V_119 ) ;
} else if ( V_283 > V_48 -> V_49 -> V_285 )
V_48 -> V_49 -> V_285 = V_283 ;
if ( ! F_34 ( V_158 , & V_72 -> V_77 ) ) {
F_141 ( V_72 ) ;
}
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_66 ,
V_5 , V_72 , V_48 -> V_49 -> V_285 ) ;
if ( V_284 )
F_207 ( V_36 ) ;
}
void F_208 ( struct V_286 * V_287 )
{
struct V_8 * V_9 = F_22 ( V_287 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_288 )
V_9 -> V_10 -> V_288 ( V_287 ) ;
F_205 ( V_287 -> args . V_36 , & V_287 -> V_118 ) ;
}
int
F_86 ( struct V_36 * V_36 , bool V_159 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_286 * V_287 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_5 V_283 ;
int V_25 ;
if ( ! F_209 ( V_36 ) )
return 0 ;
F_3 ( L_67 , V_5 , V_36 -> V_119 ) ;
V_25 = - V_116 ;
if ( F_34 ( V_281 , & V_48 -> V_157 ) ) {
if ( ! V_159 )
goto V_4;
V_25 = F_210 ( & V_48 -> V_157 ,
V_281 ,
F_144 ,
V_289 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_154 ;
V_287 = F_103 ( sizeof( * V_287 ) , V_162 ) ;
if ( ! V_287 )
goto V_290;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_36 ( V_156 , & V_48 -> V_157 ) )
goto V_215;
F_46 ( & V_287 -> V_118 ) ;
F_204 ( V_36 , & V_287 -> V_118 ) ;
V_283 = V_48 -> V_49 -> V_285 ;
F_95 ( & V_287 -> args . V_86 , & V_48 -> V_49 -> V_89 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_287 -> args . V_36 = V_36 ;
V_287 -> V_153 = F_136 ( V_48 -> V_49 -> V_45 ) ;
F_211 ( & V_287 -> V_291 ) ;
V_287 -> args . V_292 = F_22 ( V_36 ) -> V_293 ;
V_287 -> V_221 . V_291 = & V_287 -> V_291 ;
V_287 -> args . V_294 = V_283 - 1 ;
V_287 -> V_221 . V_14 = F_22 ( V_36 ) ;
if ( V_39 -> V_295 ) {
V_25 = V_39 -> V_295 ( & V_287 -> args ) ;
if ( V_25 ) {
F_26 ( V_287 -> V_153 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_49 ( V_156 , & V_48 -> V_157 ) ;
if ( V_283 > V_48 -> V_49 -> V_285 )
V_48 -> V_49 -> V_285 = V_283 ;
goto V_215;
}
}
V_25 = F_212 ( V_287 , V_159 ) ;
V_4:
if ( V_25 )
F_207 ( V_36 ) ;
F_3 ( L_68 , V_5 , V_25 ) ;
return V_25 ;
V_215:
F_7 ( & V_36 -> V_52 ) ;
F_213 ( V_287 ) ;
V_290:
F_203 ( V_36 ) ;
goto V_4;
}
int
F_214 ( struct V_36 * V_36 , bool V_296 )
{
return F_86 ( V_36 , true ) ;
}
struct V_186 * F_215 ( void )
{
struct V_186 * V_297 ;
V_297 = F_103 ( sizeof( * V_297 ) , V_162 ) ;
if ( ! V_297 ) {
F_3 ( L_69 , V_5 ) ;
return NULL ;
}
return V_297 ;
}
int
F_216 ( struct V_36 * V_36 , T_2 V_38 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_298 * V_287 ;
struct V_33 * V_245 ;
int V_25 = 0 ;
if ( ! F_150 ( V_14 ) || ! V_39 -> V_299 )
goto V_4;
if ( ! F_217 ( V_36 , V_300 ) )
goto V_4;
if ( F_34 ( V_301 , & V_48 -> V_157 ) )
goto V_4;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_28 ( V_36 ) -> V_49 ) {
F_7 ( & V_36 -> V_52 ) ;
goto V_4;
}
V_245 = F_28 ( V_36 ) -> V_49 ;
F_20 ( V_245 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_287 = F_103 ( sizeof( * V_287 ) , V_38 ) ;
if ( ! V_287 ) {
V_25 = - V_154 ;
goto V_302;
}
V_287 -> args . V_303 = F_218 ( V_36 ) ;
V_287 -> args . V_36 = V_36 ;
F_95 ( & V_287 -> args . V_86 , & V_245 -> V_89 ) ;
V_25 = V_39 -> V_299 ( & V_287 -> args ) ;
if ( V_25 )
goto V_304;
V_25 = F_219 ( F_22 ( V_36 ) , V_287 ) ;
V_4:
F_3 ( L_70 , V_5 , V_25 ) ;
return V_25 ;
V_304:
F_213 ( V_287 ) ;
V_302:
F_29 ( V_245 ) ;
F_220 () ;
F_53 ( V_301 , & V_48 -> V_157 ) ;
F_112 () ;
goto V_4;
}
