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
V_34 -> V_85 ++ ;
F_20 ( V_34 ) ;
F_53 ( V_86 , & V_34 -> V_61 ) ;
return true ;
}
static void F_57 ( struct V_71 * V_72 ,
struct V_33 * V_34 , struct V_36 * V_36 )
{
V_34 = V_72 -> V_78 ;
V_36 = V_34 -> V_41 ;
F_5 ( & V_36 -> V_52 ) ;
if ( F_55 ( V_34 , V_72 ) ) {
T_3 V_87 ;
enum V_88 V_54 ;
bool V_89 ;
V_87 = V_34 -> V_90 ;
V_54 = V_34 -> V_84 ;
V_89 = F_56 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_89 ) {
F_58 ( V_34 , V_87 , V_54 , false ) ;
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
static void F_62 ( struct V_91 * V_92 )
{
struct V_71 * V_72 ;
struct V_33 * V_34 ;
V_72 = F_63 ( V_92 , struct V_71 , V_93 ) ;
V_34 = V_72 -> V_78 ;
F_50 ( V_72 ) ;
F_29 ( V_34 ) ;
}
static void F_64 ( struct V_71 * V_72 )
{
F_65 ( & V_72 -> V_93 , F_62 ) ;
F_66 ( & V_72 -> V_93 ) ;
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
F_69 ( T_4 V_68 , T_4 V_94 )
{
T_4 V_69 ;
V_69 = V_68 + V_94 ;
return V_69 >= V_68 ? V_69 : V_66 ;
}
static bool
F_70 ( const struct V_62 * V_95 ,
const struct V_62 * V_96 )
{
T_4 V_97 = V_95 -> V_64 ;
T_4 V_98 = F_69 ( V_97 , V_95 -> V_65 ) ;
T_4 V_99 = V_96 -> V_64 ;
T_4 V_100 = F_69 ( V_99 , V_96 -> V_65 ) ;
return ( V_97 <= V_99 ) && ( V_98 >= V_100 ) ;
}
static bool
F_71 ( const struct V_62 * V_95 ,
const struct V_62 * V_96 )
{
T_4 V_97 = V_95 -> V_64 ;
T_4 V_98 = F_69 ( V_97 , V_95 -> V_65 ) ;
T_4 V_99 = V_96 -> V_64 ;
T_4 V_100 = F_69 ( V_99 , V_96 -> V_65 ) ;
return ( V_98 == V_66 || V_98 > V_99 ) &&
( V_100 == V_66 || V_100 > V_97 ) ;
}
static bool
F_72 ( const struct V_62 * V_101 ,
const struct V_62 * V_102 )
{
return ( V_102 -> V_54 == V_103 ||
V_101 -> V_54 == V_102 -> V_54 ) &&
F_71 ( V_101 , V_102 ) ;
}
static bool F_73 ( struct V_71 * V_72 ,
struct V_104 * V_105 )
{
if ( ! F_9 ( & V_72 -> V_75 ) )
return false ;
F_51 ( V_72 -> V_78 , V_72 ) ;
F_17 ( & V_72 -> V_73 , V_105 ) ;
return true ;
}
static int F_74 ( struct V_71 * V_72 ,
struct V_104 * V_105 )
{
int V_106 = 0 ;
if ( F_36 ( V_76 , & V_72 -> V_77 ) ) {
F_3 ( L_22 , V_5 , V_72 ,
F_60 ( & V_72 -> V_75 ) ) ;
if ( F_73 ( V_72 , V_105 ) )
V_106 = 1 ;
}
return V_106 ;
}
int
F_40 ( struct V_33 * V_34 ,
struct V_104 * V_105 ,
struct V_62 * V_102 )
{
struct V_71 * V_72 , * V_107 ;
int V_108 = 0 , V_109 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_75 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_102 ||
F_72 ( & V_72 -> V_110 , V_102 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_72 , V_72 -> V_110 . V_54 , V_72 -> V_110 . V_64 ,
V_72 -> V_110 . V_65 ) ;
V_108 ++ ;
V_109 += F_74 ( V_72 , V_105 ) ;
}
F_3 ( L_26 , V_5 , V_108 - V_109 ) ;
return V_108 - V_109 ;
}
void
F_41 ( struct V_104 * V_111 )
{
struct V_71 * V_72 , * V_27 ;
if ( F_24 ( V_111 ) )
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
F_39 ( V_105 ) ;
F_5 ( & V_48 -> V_112 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
V_34 -> V_85 ++ ;
F_40 ( V_34 , & V_105 , NULL ) ;
F_20 ( V_34 ) ;
F_35 ( V_34 , V_57 ) ;
F_35 ( V_34 , V_56 ) ;
F_77 ( V_34 ) ;
F_7 ( & V_48 -> V_112 . V_52 ) ;
F_41 ( & V_105 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_112 . V_52 ) ;
}
static bool
F_78 ( struct V_36 * V_36 ,
struct V_104 * V_113 )
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
struct V_104 * V_113 )
{
struct V_33 * V_34 , * V_107 ;
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
F_84 ( struct V_104 * V_113 ,
bool V_117 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
struct V_62 V_63 = {
. V_54 = V_103 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_39 ( V_118 ) ;
int V_114 = 0 ;
while ( ! F_24 ( V_113 ) ) {
V_34 = F_85 ( V_113 -> V_107 , struct V_33 ,
V_115 ) ;
F_3 ( L_27 , V_5 ,
V_34 -> V_41 -> V_119 ) ;
V_36 = V_34 -> V_41 ;
F_86 ( V_36 , false ) ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_115 ) ;
V_34 -> V_85 ++ ;
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
V_129 = F_94 ( V_34 -> V_90 . V_133 ) ;
V_130 = F_94 ( V_127 -> V_133 ) ;
if ( V_132 || F_92 ( V_130 , V_129 ) ) {
F_95 ( & V_34 -> V_90 , V_127 ) ;
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
const T_3 * V_87 )
{
T_1 V_133 = F_94 ( V_87 -> V_133 ) ;
return ! F_92 ( V_133 , V_34 -> V_135 ) ;
}
static bool
F_97 ( const struct V_33 * V_34 ,
struct V_62 * V_63 )
{
return F_43 ( V_83 , & V_34 -> V_61 ) &&
( V_34 -> V_84 == V_103 ||
V_34 -> V_84 == V_63 -> V_54 ) ;
}
static bool
F_98 ( const struct V_33 * V_34 ,
struct V_62 * V_63 , int V_136 )
{
return V_34 -> V_85 ||
F_43 ( V_79 , & V_34 -> V_61 ) ||
( F_24 ( & V_34 -> V_53 ) &&
( F_60 ( & V_34 -> V_134 ) > V_136 ) ) ||
F_97 ( V_34 , V_63 ) ;
}
int
F_99 ( T_3 * V_137 , struct V_33 * V_34 ,
struct V_62 * V_63 ,
struct V_138 * V_139 )
{
int V_25 = 0 ;
F_3 ( L_28 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_98 ( V_34 , V_63 , 1 ) ) {
V_25 = - V_116 ;
} else if ( ! F_100 ( V_139 ) ) {
V_25 = - V_140 ;
} else if ( F_24 ( & V_34 -> V_53 ) ||
F_43 ( V_141 , & V_34 -> V_61 ) ) {
int V_142 ;
do {
V_142 = F_101 ( & V_139 -> V_143 ) ;
F_95 ( V_137 , & V_139 -> V_87 ) ;
} while ( F_102 ( & V_139 -> V_143 , V_142 ) );
} else
F_95 ( V_137 , & V_34 -> V_90 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_29 , V_5 ) ;
return V_25 ;
}
static struct V_71 *
F_103 ( struct V_33 * V_34 ,
struct V_144 * V_145 ,
struct V_62 * V_63 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_146 * V_147 ;
struct V_71 * V_72 ;
F_3 ( L_28 , V_5 ) ;
V_147 = F_104 ( sizeof( * V_147 ) , V_38 ) ;
if ( V_147 == NULL )
return NULL ;
V_147 -> args . V_148 = V_149 ;
if ( V_147 -> args . V_148 > V_63 -> V_65 )
V_147 -> args . V_148 = V_63 -> V_65 ;
V_147 -> args . V_150 = V_151 ;
V_147 -> args . V_63 = * V_63 ;
V_147 -> args . type = V_14 -> V_10 -> V_2 ;
V_147 -> args . V_36 = V_37 ;
V_147 -> args . V_145 = F_105 ( V_145 ) ;
V_147 -> V_38 = V_38 ;
V_147 -> V_152 = V_34 -> V_45 ;
V_72 = F_106 ( V_147 , V_38 ) ;
if ( F_107 ( V_72 ) ) {
switch ( F_108 ( V_72 ) ) {
case - V_153 :
case - V_154 :
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
struct V_104 * V_67 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_71 * V_72 , * V_27 ;
if ( ! F_36 ( V_155 , & V_48 -> V_156 ) )
return;
F_75 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_36 ( V_157 , & V_72 -> V_77 ) )
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
F_58 ( struct V_33 * V_34 , T_3 V_87 ,
enum V_88 V_54 , bool V_158 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_159 * V_160 ;
int V_25 = 0 ;
V_160 = F_104 ( sizeof( * V_160 ) , V_161 ) ;
if ( F_114 ( V_160 == NULL ) ) {
V_25 = - V_153 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 -> V_85 -- ;
F_110 ( V_34 ) ;
F_54 ( & F_22 ( V_37 ) -> V_80 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_160 -> args . V_87 = V_87 ;
V_160 -> args . V_162 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_160 -> args . V_36 = V_37 ;
V_160 -> args . V_63 . V_54 = V_54 ;
V_160 -> args . V_63 . V_64 = 0 ;
V_160 -> args . V_63 . V_65 = V_66 ;
V_160 -> args . V_49 = V_34 ;
V_160 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_160 -> V_152 = V_34 -> V_45 ;
V_25 = F_115 ( V_160 , V_158 ) ;
V_4:
F_3 ( L_30 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_116 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_39 ( V_105 ) ;
T_3 V_87 ;
int V_25 = 0 , V_132 ;
bool V_89 ;
F_3 ( L_31 , V_5 , V_37 -> V_119 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_4;
}
V_87 = V_48 -> V_49 -> V_90 ;
F_20 ( V_34 ) ;
V_132 = F_24 ( & V_34 -> V_53 ) ;
F_109 ( V_37 , & V_105 ) ;
F_40 ( V_34 , & V_105 , NULL ) ;
if ( F_22 ( V_37 ) -> V_10 -> V_163 ) {
struct V_62 V_63 = {
. V_54 = V_103 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_22 ( V_37 ) -> V_10 -> V_163 ( V_34 , & V_63 ) ;
}
if ( V_132 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_33 , V_5 ) ;
goto V_164;
}
F_49 ( V_141 , & V_34 -> V_61 ) ;
V_89 = F_56 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_105 ) ;
if ( V_89 )
V_25 = F_58 ( V_34 , V_87 , V_103 , true ) ;
V_164:
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
V_34 -> V_85 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_118 ( V_36 -> V_165 ) ;
V_114 = F_86 ( V_36 , true ) ;
if ( V_114 == 0 )
V_114 = F_116 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_85 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_114 ;
}
bool F_119 ( struct V_36 * V_37 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_144 * V_145 ;
struct V_138 * V_166 ;
struct V_33 * V_34 ;
struct V_71 * V_72 , * V_27 ;
T_3 V_87 ;
F_39 ( V_105 ) ;
bool V_167 = false , V_168 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 || ! F_36 ( V_169 , & V_34 -> V_61 ) ||
F_43 ( V_79 , & V_34 -> V_61 ) )
goto V_170;
if ( F_120 ( V_37 , V_171 ) )
goto V_170;
F_2 (ctx, &nfsi->open_files, list) {
V_166 = V_145 -> V_166 ;
if ( V_166 != NULL && V_166 -> V_166 != 0 )
goto V_170;
}
F_77 ( V_34 ) ;
F_75 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_43 ( V_172 , & V_72 -> V_77 ) ) {
F_74 ( V_72 , & V_105 ) ;
V_167 = true ;
}
if ( ! V_167 )
goto V_170;
V_34 -> V_85 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_105 ) ;
F_86 ( V_37 , true ) ;
return true ;
V_170:
if ( V_34 ) {
V_87 = V_34 -> V_90 ;
if ( F_36 ( V_86 ,
& V_34 -> V_61 ) )
V_168 = F_56 ( V_34 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
if ( V_168 ) {
F_86 ( V_37 , true ) ;
F_58 ( V_34 , V_87 , V_103 , true ) ;
}
return false ;
}
void F_121 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
V_34 -> V_85 -- ;
if ( F_9 ( & V_34 -> V_35 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_23 ( V_34 ) ;
} else
F_7 ( & V_37 -> V_52 ) ;
}
void F_122 ( struct V_36 * V_37 , T_1 V_173 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_92 ( V_173 , V_34 -> V_135 ) )
V_34 -> V_135 = V_173 ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_123 ( struct V_36 * V_37 , T_1 * V_173 , struct V_174 * V_175 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
struct V_71 * V_72 ;
T_3 V_87 ;
T_1 V_176 ;
bool V_168 = false ;
F_5 ( & V_37 -> V_52 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_43 ( V_172 , & V_72 -> V_77 ) )
continue;
if ( F_43 ( V_76 , & V_72 -> V_77 ) )
continue;
F_124 ( & F_22 ( V_37 ) -> V_80 , V_175 , NULL ) ;
F_7 ( & V_37 -> V_52 ) ;
return true ;
}
V_34 = V_48 -> V_49 ;
V_176 = F_94 ( V_34 -> V_90 . V_133 ) ;
* V_173 = V_176 + F_60 ( & V_34 -> V_134 ) ;
V_87 = V_34 -> V_90 ;
if ( F_36 ( V_86 ,
& V_34 -> V_61 ) )
V_168 = F_56 ( V_34 ) ;
if ( F_43 ( V_83 , & V_34 -> V_61 ) )
F_124 ( & F_22 ( V_37 ) -> V_80 , V_175 , NULL ) ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_168 ) {
F_58 ( V_34 , V_87 , V_103 , false ) ;
return true ;
}
return false ;
}
static T_5
F_125 ( const struct V_62 * V_95 ,
const struct V_62 * V_96 )
{
T_5 V_177 ;
V_177 = V_95 -> V_64 - V_96 -> V_64 ;
if ( V_177 )
return V_177 ;
V_177 = V_96 -> V_65 - V_95 -> V_65 ;
if ( V_177 )
return V_177 ;
return ( int ) ( V_95 -> V_54 == V_178 ) - ( int ) ( V_96 -> V_54 == V_178 ) ;
}
static void
F_126 ( struct V_33 * V_34 ,
struct V_71 * V_72 )
{
struct V_71 * V_179 ;
F_3 ( L_34 , V_5 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_125 ( & V_72 -> V_110 , & V_179 -> V_110 ) > 0 )
continue;
F_127 ( & V_72 -> V_73 , & V_179 -> V_73 ) ;
F_3 ( L_35
L_36
L_37 ,
V_5 , V_72 , V_72 -> V_110 . V_54 ,
V_72 -> V_110 . V_64 , V_72 -> V_110 . V_65 ,
V_179 , V_179 -> V_110 . V_54 , V_179 -> V_110 . V_64 ,
V_179 -> V_110 . V_65 ) ;
goto V_4;
}
F_127 ( & V_72 -> V_73 , & V_34 -> V_53 ) ;
F_3 ( L_35
L_38 ,
V_5 , V_72 , V_72 -> V_110 . V_54 ,
V_72 -> V_110 . V_64 , V_72 -> V_110 . V_65 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_39 , V_5 ) ;
}
static struct V_33 *
F_128 ( struct V_36 * V_37 ,
struct V_144 * V_145 ,
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
V_34 -> V_45 = F_129 ( V_145 -> V_152 ) ;
return V_34 ;
}
static struct V_33 *
F_130 ( struct V_36 * V_37 ,
struct V_144 * V_145 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_127 = NULL ;
F_3 ( L_40 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_180;
F_7 ( & V_37 -> V_52 ) ;
V_127 = F_128 ( V_37 , V_145 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_131 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_127 ;
return V_127 ;
} else if ( V_127 != NULL )
F_23 ( V_127 ) ;
V_180:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_132 ( const struct V_62 * V_181 ,
const struct V_62 * V_63 )
{
struct V_62 V_182 ;
if ( ( V_63 -> V_54 == V_55 &&
V_181 -> V_54 != V_55 ) ||
! F_71 ( V_181 , V_63 ) )
return 0 ;
V_182 = * V_63 ;
V_182 . V_65 = 1 ;
return F_70 ( V_181 , & V_182 ) ;
}
static struct V_71 *
F_133 ( struct V_33 * V_34 ,
struct V_62 * V_63 )
{
struct V_71 * V_72 , * V_114 = NULL ;
F_3 ( L_34 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_43 ( V_76 , & V_72 -> V_77 ) &&
! F_43 ( V_82 , & V_72 -> V_77 ) &&
F_132 ( & V_72 -> V_110 , V_63 ) ) {
V_114 = F_134 ( V_72 ) ;
break;
}
if ( V_72 -> V_110 . V_64 > V_63 -> V_64 )
break;
}
F_3 ( L_41 ,
V_5 , V_114 , V_114 ? F_60 ( & V_114 -> V_75 ) : 0 ) ;
return V_114 ;
}
static bool F_135 ( struct V_144 * V_145 ,
struct V_36 * V_37 , int V_54 )
{
struct V_183 * V_184 = V_145 -> V_185 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_6 V_186 = F_136 ( V_37 ) ;
bool V_187 = false , V_188 = false , V_189 = false , V_190 = false , V_114 = false ;
if ( V_184 == NULL )
return V_114 ;
F_3 ( L_42 ,
V_5 , V_184 -> V_191 , V_184 -> V_192 , V_184 -> V_193 , V_184 -> V_194 , V_184 -> V_195 ) ;
switch ( V_54 ) {
case V_178 :
if ( V_184 -> V_191 & V_196 ) {
F_3 ( L_43 , V_5 , V_186 ) ;
V_188 = true ;
if ( V_186 < V_184 -> V_192 )
V_187 = true ;
}
if ( V_184 -> V_191 & V_197 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_51 ) ;
V_190 = true ;
if ( V_48 -> V_51 < V_184 -> V_194 )
V_189 = true ;
}
break;
case V_55 :
if ( V_184 -> V_191 & V_198 ) {
F_3 ( L_43 , V_5 , V_186 ) ;
V_188 = true ;
if ( V_186 < V_184 -> V_193 )
V_187 = true ;
}
if ( V_184 -> V_191 & V_199 ) {
F_3 ( L_45 , V_5 ,
V_48 -> V_50 ) ;
V_190 = true ;
if ( V_48 -> V_50 < V_184 -> V_195 )
V_189 = true ;
}
break;
}
if ( V_188 && V_190 ) {
if ( V_187 && V_189 )
V_114 = true ;
} else if ( V_187 || V_189 )
V_114 = true ;
F_3 ( L_46 , V_5 , V_187 , V_189 , V_114 ) ;
return V_114 ;
}
static int F_137 ( struct V_200 * V_201 )
{
if ( ! F_43 ( V_202 , V_201 -> V_156 ) )
return 1 ;
return F_138 ( V_201 ) ;
}
static bool F_139 ( struct V_33 * V_34 )
{
F_86 ( V_34 -> V_41 , false ) ;
return ! F_140 ( & V_34 -> V_61 , V_83 ,
F_137 ,
V_203 ) ;
}
static void F_141 ( struct V_33 * V_34 )
{
unsigned long * V_204 = & V_34 -> V_61 ;
F_111 ( V_205 , V_204 ) ;
F_112 () ;
F_113 ( V_204 , V_205 ) ;
}
struct V_71 *
F_142 ( struct V_36 * V_37 ,
struct V_144 * V_145 ,
T_6 V_206 ,
T_4 V_207 ,
enum V_88 V_54 ,
T_2 V_38 )
{
struct V_62 V_208 = {
. V_54 = V_54 ,
. V_64 = V_206 ,
. V_65 = V_207 ,
} ;
unsigned V_209 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_71 * V_72 = NULL ;
bool V_210 ;
if ( ! F_143 ( F_22 ( V_37 ) ) )
goto V_4;
if ( F_135 ( V_145 , V_37 , V_54 ) )
goto V_4;
V_211:
V_210 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_130 ( V_37 , V_145 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
goto V_4;
}
if ( F_43 ( V_79 , & V_34 -> V_61 ) ) {
F_3 ( L_47 , V_5 ) ;
goto V_212;
}
if ( F_42 ( V_34 , V_54 ) &&
! F_144 ( V_34 ) )
goto V_212;
V_210 = F_24 ( & V_34 -> V_53 ) ;
if ( V_210 ) {
if ( F_34 ( V_205 ,
& V_34 -> V_61 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_145 ( & V_34 -> V_61 , V_205 ,
V_203 ) ;
F_29 ( V_34 ) ;
goto V_211;
}
} else {
V_72 = F_133 ( V_34 , & V_208 ) ;
if ( V_72 )
goto V_212;
}
if ( ! V_72 && F_144 ( V_34 ) &&
F_43 ( V_83 , & V_34 -> V_61 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_48 , V_5 ) ;
if ( F_139 ( V_34 ) ) {
if ( V_210 )
F_141 ( V_34 ) ;
F_29 ( V_34 ) ;
F_3 ( L_49 , V_5 ) ;
goto V_211;
}
goto V_164;
}
if ( F_98 ( V_34 , & V_208 , 0 ) )
goto V_212;
F_15 ( & V_34 -> V_134 ) ;
F_7 ( & V_37 -> V_52 ) ;
if ( F_24 ( & V_34 -> V_42 ) ) {
F_5 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_34 -> V_42 ) )
F_127 ( & V_34 -> V_42 , & V_14 -> V_213 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_209 = V_208 . V_64 & ~ V_214 ;
if ( V_209 ) {
V_208 . V_64 -= V_209 ;
V_208 . V_65 += V_209 ;
}
if ( V_208 . V_65 != V_66 )
V_208 . V_65 = F_146 ( V_208 . V_65 ) ;
V_72 = F_103 ( V_34 , V_145 , & V_208 , V_38 ) ;
F_77 ( V_34 ) ;
F_37 ( & V_34 -> V_134 ) ;
V_164:
if ( V_210 )
F_141 ( V_34 ) ;
F_29 ( V_34 ) ;
V_4:
F_3 ( L_50
L_51 ,
V_5 , V_37 -> V_215 -> V_216 ,
( unsigned long long ) F_147 ( V_37 ) ,
V_72 == NULL ? L_52 : L_53 ,
V_54 == V_55 ? L_54 : L_55 ,
( unsigned long long ) V_206 ,
( unsigned long long ) V_207 ) ;
return V_72 ;
V_212:
F_7 ( & V_37 -> V_52 ) ;
goto V_164;
}
struct V_71 *
F_148 ( struct V_146 * V_147 )
{
struct V_33 * V_34 = F_28 ( V_147 -> args . V_36 ) -> V_49 ;
struct V_217 * V_218 = & V_147 -> V_218 ;
struct V_71 * V_72 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_39 ( V_111 ) ;
int V_25 = 0 ;
V_72 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_218 , V_147 -> V_38 ) ;
if ( ! V_72 || F_107 ( V_72 ) ) {
if ( ! V_72 )
V_25 = - V_153 ;
else
V_25 = F_108 ( V_72 ) ;
F_3 ( L_56 ,
V_5 , V_25 ) ;
goto V_4;
}
F_45 ( V_34 , V_72 ) ;
V_72 -> V_110 = V_218 -> V_63 ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_43 ( V_79 , & V_34 -> V_61 ) ) {
F_3 ( L_57 , V_5 ) ;
goto V_219;
}
if ( F_98 ( V_34 , & V_147 -> args . V_63 , 1 ) ) {
F_3 ( L_58 , V_5 ) ;
goto V_219;
}
if ( F_149 ( & V_34 -> V_90 , & V_218 -> V_87 ) ) {
if ( F_96 ( V_34 , & V_218 -> V_87 ) ) {
F_3 ( L_59 , V_5 ) ;
goto V_219;
}
F_93 ( V_34 , & V_218 -> V_87 , false ) ;
} else {
F_40 ( V_34 , & V_111 , NULL ) ;
F_95 ( & V_34 -> V_90 , & V_218 -> V_87 ) ;
V_34 -> V_135 = F_94 ( V_218 -> V_87 . V_133 ) ;
}
F_53 ( V_141 , & V_34 -> V_61 ) ;
F_134 ( V_72 ) ;
F_126 ( V_34 , V_72 ) ;
if ( V_218 -> V_220 ) {
F_49 ( V_172 , & V_72 -> V_77 ) ;
F_49 ( V_169 , & V_34 -> V_61 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
F_41 ( & V_111 ) ;
return V_72 ;
V_4:
return F_150 ( V_25 ) ;
V_219:
F_7 ( & V_37 -> V_52 ) ;
V_72 -> V_78 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_72 ) ;
goto V_4;
}
static void
F_151 ( struct V_33 * V_34 ,
struct V_104 * V_105 ,
struct V_62 * V_163 )
{
struct V_71 * V_72 , * V_107 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return;
F_75 (lseg, next, &lo->plh_segs, pls_list)
if ( F_72 ( & V_72 -> V_110 , V_163 ) ) {
F_3 ( L_60
L_25 , V_5 ,
V_72 , V_72 -> V_110 . V_54 ,
V_72 -> V_110 . V_64 ,
V_72 -> V_110 . V_65 ) ;
F_49 ( V_82 , & V_72 -> V_77 ) ;
F_74 ( V_72 , V_105 ) ;
}
}
void F_152 ( struct V_36 * V_36 ,
struct V_71 * V_72 )
{
struct V_33 * V_34 = F_28 ( V_36 ) -> V_49 ;
int V_54 = F_32 ( V_72 -> V_110 . V_54 ) ;
struct V_62 V_63 = {
. V_54 = V_72 -> V_110 . V_54 ,
. V_64 = 0 ,
. V_65 = V_66 ,
} ;
F_39 ( V_111 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_33 ( V_34 , V_54 ) ;
if ( V_34 -> V_84 == 0 )
V_34 -> V_84 = V_63 . V_54 ;
else if ( V_34 -> V_84 != V_63 . V_54 )
V_34 -> V_84 = V_103 ;
F_151 ( V_34 , & V_111 , & V_63 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_41 ( & V_111 ) ;
}
void
F_153 ( struct V_221 * V_222 , struct V_223 * V_224 )
{
T_4 V_225 = V_224 -> V_226 ;
if ( V_222 -> V_227 == NULL ) {
if ( V_222 -> V_228 == NULL )
V_225 = F_136 ( V_222 -> V_229 ) - F_154 ( V_224 ) ;
else
V_225 = F_155 ( V_222 -> V_228 ) ;
V_222 -> V_227 = F_142 ( V_222 -> V_229 ,
V_224 -> V_230 ,
F_154 ( V_224 ) ,
V_225 ,
V_178 ,
V_231 ) ;
}
if ( V_222 -> V_227 == NULL )
F_156 ( V_222 ) ;
}
void
F_157 ( struct V_221 * V_222 ,
struct V_223 * V_224 , T_4 V_232 )
{
if ( V_222 -> V_227 == NULL )
V_222 -> V_227 = F_142 ( V_222 -> V_229 ,
V_224 -> V_230 ,
F_154 ( V_224 ) ,
V_232 ,
V_55 ,
V_161 ) ;
if ( V_222 -> V_227 == NULL )
F_158 ( V_222 ) ;
}
void
F_159 ( struct V_221 * V_233 )
{
if ( V_233 -> V_227 ) {
F_59 ( V_233 -> V_227 ) ;
V_233 -> V_227 = NULL ;
}
}
T_7
F_160 ( struct V_221 * V_222 ,
struct V_223 * V_234 , struct V_223 * V_224 )
{
unsigned int V_187 ;
T_4 V_235 , V_236 , V_237 ;
V_187 = F_161 ( V_222 , V_234 , V_224 ) ;
if ( ! V_187 )
return 0 ;
if ( V_222 -> V_227 ) {
V_235 = F_69 ( V_222 -> V_227 -> V_110 . V_64 ,
V_222 -> V_227 -> V_110 . V_65 ) ;
V_236 = F_154 ( V_224 ) ;
F_162 ( V_236 >= V_235 ) ;
if ( V_236 >= V_235 ) {
if ( V_222 -> V_238 -> V_239 )
V_222 -> V_238 -> V_239 ( V_222 ) ;
if ( V_222 -> V_238 -> V_240 )
V_222 -> V_238 -> V_240 ( V_222 , V_224 ) ;
return 0 ;
}
V_237 = V_235 - V_236 ;
if ( V_237 < V_187 )
V_187 = ( unsigned int ) V_237 ;
}
return V_187 ;
}
int F_163 ( struct V_241 * V_242 )
{
struct V_221 V_222 ;
F_164 ( & V_222 , V_242 -> V_36 , V_243 , true ,
V_242 -> V_244 ) ;
F_49 ( V_245 , & V_242 -> args . V_246 -> V_156 ) ;
return F_165 ( & V_222 , V_242 ) ;
}
static void F_166 ( struct V_241 * V_242 )
{
F_3 ( L_61 , V_242 -> V_247 ) ;
if ( F_22 ( V_242 -> V_36 ) -> V_10 -> V_156 &
V_248 ) {
F_167 ( V_242 -> V_36 ) ;
}
if ( ! F_34 ( V_249 , & V_242 -> V_156 ) )
V_242 -> V_175 . V_250 = F_163 ( V_242 ) ;
}
void F_168 ( struct V_241 * V_242 )
{
F_169 ( V_242 , V_242 -> V_247 ) ;
if ( ! V_242 -> V_247 ) {
F_170 ( V_242 -> V_36 , V_242 -> V_72 ,
V_242 -> V_251 + V_242 -> V_218 . V_207 ) ;
V_242 -> V_252 -> V_253 ( & V_242 -> V_175 , V_242 ) ;
} else
F_166 ( V_242 ) ;
V_242 -> V_252 -> V_254 ( V_242 ) ;
}
static void
F_171 ( struct V_221 * V_233 ,
struct V_241 * V_242 )
{
struct V_255 * V_256 = F_172 ( V_233 ) ;
if ( ! F_34 ( V_249 , & V_242 -> V_156 ) ) {
F_173 ( & V_242 -> V_257 , & V_256 -> V_258 ) ;
F_158 ( V_233 ) ;
V_256 -> V_259 = 1 ;
}
F_174 ( V_242 ) ;
V_242 -> V_260 ( V_242 ) ;
}
static enum V_261
F_175 ( struct V_241 * V_242 ,
const struct V_262 * V_263 ,
struct V_71 * V_72 ,
int V_264 )
{
struct V_36 * V_36 = V_242 -> V_36 ;
enum V_261 V_265 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_242 -> V_252 = V_263 ;
F_3 ( L_62 , V_5 ,
V_36 -> V_119 , V_242 -> args . V_207 , V_242 -> args . V_64 , V_264 ) ;
V_265 = V_9 -> V_10 -> V_266 ( V_242 , V_264 ) ;
if ( V_265 != V_267 )
F_176 ( V_36 , V_268 ) ;
F_3 ( L_63 , V_5 , V_265 ) ;
return V_265 ;
}
static void
F_177 ( struct V_221 * V_233 ,
struct V_241 * V_242 , int V_264 )
{
const struct V_262 * V_263 = V_233 -> V_269 ;
struct V_71 * V_72 = V_233 -> V_227 ;
enum V_261 V_265 ;
V_265 = F_175 ( V_242 , V_263 , V_72 , V_264 ) ;
if ( V_265 == V_267 )
F_171 ( V_233 , V_242 ) ;
}
static void F_178 ( struct V_241 * V_242 )
{
F_59 ( V_242 -> V_72 ) ;
F_179 ( V_242 ) ;
}
int
F_180 ( struct V_221 * V_233 )
{
struct V_255 * V_256 = F_172 ( V_233 ) ;
struct V_241 * V_242 ;
int V_114 ;
V_242 = F_181 ( V_233 -> V_270 ) ;
if ( ! V_242 ) {
V_233 -> V_271 -> V_272 ( & V_256 -> V_258 ) ;
return - V_153 ;
}
F_182 ( V_233 , V_242 , F_178 ) ;
V_242 -> V_72 = F_134 ( V_233 -> V_227 ) ;
V_114 = F_183 ( V_233 , V_242 ) ;
if ( ! V_114 )
F_177 ( V_233 , V_242 , V_233 -> V_273 ) ;
return V_114 ;
}
int F_184 ( struct V_241 * V_242 )
{
struct V_221 V_222 ;
F_185 ( & V_222 , V_242 -> V_36 , true , V_242 -> V_244 ) ;
return F_165 ( & V_222 , V_242 ) ;
}
static void F_186 ( struct V_241 * V_242 )
{
F_3 ( L_64 , V_242 -> V_247 ) ;
if ( F_22 ( V_242 -> V_36 ) -> V_10 -> V_156 &
V_248 ) {
F_167 ( V_242 -> V_36 ) ;
}
if ( ! F_34 ( V_249 , & V_242 -> V_156 ) )
V_242 -> V_175 . V_250 = F_184 ( V_242 ) ;
}
void F_187 ( struct V_241 * V_242 )
{
F_188 ( V_242 , V_242 -> V_247 ) ;
if ( F_131 ( ! V_242 -> V_247 ) ) {
F_189 ( V_242 ) ;
V_242 -> V_252 -> V_253 ( & V_242 -> V_175 , V_242 ) ;
} else
F_186 ( V_242 ) ;
V_242 -> V_252 -> V_254 ( V_242 ) ;
}
static void
F_190 ( struct V_221 * V_233 ,
struct V_241 * V_242 )
{
struct V_255 * V_256 = F_172 ( V_233 ) ;
if ( ! F_34 ( V_249 , & V_242 -> V_156 ) ) {
F_173 ( & V_242 -> V_257 , & V_256 -> V_258 ) ;
F_156 ( V_233 ) ;
V_256 -> V_259 = 1 ;
}
F_174 ( V_242 ) ;
V_242 -> V_260 ( V_242 ) ;
}
static enum V_261
F_191 ( struct V_241 * V_242 ,
const struct V_262 * V_263 ,
struct V_71 * V_72 )
{
struct V_36 * V_36 = V_242 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_261 V_265 ;
V_242 -> V_252 = V_263 ;
F_3 ( L_65 ,
V_5 , V_36 -> V_119 , V_242 -> args . V_207 , V_242 -> args . V_64 ) ;
V_265 = V_9 -> V_10 -> V_274 ( V_242 ) ;
if ( V_265 != V_267 )
F_176 ( V_36 , V_275 ) ;
F_3 ( L_63 , V_5 , V_265 ) ;
return V_265 ;
}
int F_192 ( struct V_241 * V_242 )
{
struct V_221 V_222 ;
F_185 ( & V_222 , V_242 -> V_36 , false , V_242 -> V_244 ) ;
return F_165 ( & V_222 , V_242 ) ;
}
static void
F_193 ( struct V_221 * V_233 , struct V_241 * V_242 )
{
const struct V_262 * V_263 = V_233 -> V_269 ;
struct V_71 * V_72 = V_233 -> V_227 ;
enum V_261 V_265 ;
int V_276 = 0 ;
V_265 = F_191 ( V_242 , V_263 , V_72 ) ;
if ( V_265 == V_277 )
V_276 = F_192 ( V_242 ) ;
if ( V_265 == V_267 || V_276 )
F_190 ( V_233 , V_242 ) ;
}
static void F_194 ( struct V_241 * V_242 )
{
F_59 ( V_242 -> V_72 ) ;
F_179 ( V_242 ) ;
}
int
F_195 ( struct V_221 * V_233 )
{
struct V_255 * V_256 = F_172 ( V_233 ) ;
struct V_241 * V_242 ;
int V_114 ;
V_242 = F_181 ( V_233 -> V_270 ) ;
if ( ! V_242 ) {
V_233 -> V_271 -> V_272 ( & V_256 -> V_258 ) ;
return - V_153 ;
}
F_182 ( V_233 , V_242 , F_194 ) ;
V_242 -> V_72 = F_134 ( V_233 -> V_227 ) ;
V_114 = F_183 ( V_233 , V_242 ) ;
if ( ! V_114 )
F_193 ( V_233 , V_242 ) ;
return V_114 ;
}
static void F_196 ( struct V_36 * V_36 )
{
unsigned long * V_204 = & F_28 ( V_36 ) -> V_156 ;
F_111 ( V_278 , V_204 ) ;
F_112 () ;
F_113 ( V_204 , V_278 ) ;
}
static void F_197 ( struct V_36 * V_36 , struct V_104 * V_279 )
{
struct V_71 * V_72 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_72 -> V_110 . V_54 == V_55 &&
F_36 ( V_157 , & V_72 -> V_77 ) )
F_17 ( & V_72 -> V_74 , V_279 ) ;
}
}
static void F_198 ( struct V_36 * V_36 , struct V_104 * V_279 )
{
struct V_71 * V_72 , * V_27 ;
F_75 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_72 -> V_74 ) ;
F_59 ( V_72 ) ;
}
F_196 ( V_36 ) ;
}
void F_199 ( struct V_71 * V_72 )
{
F_38 ( V_72 -> V_78 , V_72 -> V_110 . V_54 ) ;
}
void
F_170 ( struct V_36 * V_36 , struct V_71 * V_72 ,
T_6 V_280 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
bool V_281 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_34 ( V_155 , & V_48 -> V_156 ) ) {
V_48 -> V_49 -> V_282 = V_280 ;
V_281 = true ;
F_3 ( L_66 ,
V_5 , V_36 -> V_119 ) ;
} else if ( V_280 > V_48 -> V_49 -> V_282 )
V_48 -> V_49 -> V_282 = V_280 ;
if ( ! F_34 ( V_157 , & V_72 -> V_77 ) ) {
F_134 ( V_72 ) ;
}
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_67 ,
V_5 , V_72 , V_48 -> V_49 -> V_282 ) ;
if ( V_281 )
F_200 ( V_36 ) ;
}
void F_201 ( struct V_283 * V_284 )
{
struct V_8 * V_9 = F_22 ( V_284 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_285 )
V_9 -> V_10 -> V_285 ( V_284 ) ;
F_198 ( V_284 -> args . V_36 , & V_284 -> V_118 ) ;
}
int
F_86 ( struct V_36 * V_36 , bool V_158 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_283 * V_284 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_280 ;
int V_25 ;
if ( ! F_202 ( V_36 ) )
return 0 ;
F_3 ( L_68 , V_5 , V_36 -> V_119 ) ;
V_25 = - V_116 ;
if ( F_34 ( V_278 , & V_48 -> V_156 ) ) {
if ( ! V_158 )
goto V_4;
V_25 = F_203 ( & V_48 -> V_156 ,
V_278 ,
F_138 ,
V_286 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_153 ;
V_284 = F_104 ( sizeof( * V_284 ) , V_161 ) ;
if ( ! V_284 )
goto V_287;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_36 ( V_155 , & V_48 -> V_156 ) )
goto V_212;
F_46 ( & V_284 -> V_118 ) ;
F_197 ( V_36 , & V_284 -> V_118 ) ;
V_280 = V_48 -> V_49 -> V_282 ;
F_95 ( & V_284 -> args . V_87 , & V_48 -> V_49 -> V_90 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_284 -> args . V_36 = V_36 ;
V_284 -> V_152 = F_129 ( V_48 -> V_49 -> V_45 ) ;
F_204 ( & V_284 -> V_288 ) ;
V_284 -> args . V_289 = F_22 ( V_36 ) -> V_290 ;
V_284 -> V_218 . V_288 = & V_284 -> V_288 ;
V_284 -> args . V_291 = V_280 - 1 ;
V_284 -> V_218 . V_14 = F_22 ( V_36 ) ;
if ( V_39 -> V_292 ) {
V_25 = V_39 -> V_292 ( & V_284 -> args ) ;
if ( V_25 ) {
F_26 ( V_284 -> V_152 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_49 ( V_155 , & V_48 -> V_156 ) ;
if ( V_280 > V_48 -> V_49 -> V_282 )
V_48 -> V_49 -> V_282 = V_280 ;
goto V_212;
}
}
V_25 = F_205 ( V_284 , V_158 ) ;
V_4:
if ( V_25 )
F_200 ( V_36 ) ;
F_3 ( L_69 , V_5 , V_25 ) ;
return V_25 ;
V_212:
F_7 ( & V_36 -> V_52 ) ;
F_206 ( V_284 ) ;
V_287:
F_196 ( V_36 ) ;
goto V_4;
}
int
F_207 ( struct V_36 * V_36 , bool V_293 )
{
return F_86 ( V_36 , true ) ;
}
struct V_183 * F_208 ( void )
{
struct V_183 * V_294 ;
V_294 = F_104 ( sizeof( * V_294 ) , V_161 ) ;
if ( ! V_294 ) {
F_3 ( L_70 , V_5 ) ;
return NULL ;
}
return V_294 ;
}
int
F_209 ( struct V_36 * V_36 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_295 * V_284 ;
struct V_33 * V_242 ;
int V_25 = 0 ;
if ( ! F_143 ( V_14 ) || ! V_39 -> V_296 )
goto V_4;
if ( ! F_210 ( V_36 , V_297 ) )
goto V_4;
if ( F_34 ( V_298 , & V_48 -> V_156 ) )
goto V_4;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_28 ( V_36 ) -> V_49 ) {
F_7 ( & V_36 -> V_52 ) ;
goto V_4;
}
V_242 = F_28 ( V_36 ) -> V_49 ;
F_20 ( V_242 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_284 = F_104 ( sizeof( * V_284 ) , V_231 ) ;
if ( ! V_284 ) {
V_25 = - V_153 ;
goto V_299;
}
V_284 -> args . V_300 = F_211 ( V_36 ) ;
V_284 -> args . V_36 = V_36 ;
F_95 ( & V_284 -> args . V_87 , & V_242 -> V_90 ) ;
V_25 = V_39 -> V_296 ( & V_284 -> args ) ;
if ( V_25 )
goto V_301;
V_25 = F_212 ( F_22 ( V_36 ) , V_284 ) ;
V_4:
F_3 ( L_71 , V_5 , V_25 ) ;
return V_25 ;
V_301:
F_206 ( V_284 ) ;
V_299:
F_29 ( V_242 ) ;
F_213 () ;
F_53 ( V_298 , & V_48 -> V_156 ) ;
F_112 () ;
goto V_4;
}
