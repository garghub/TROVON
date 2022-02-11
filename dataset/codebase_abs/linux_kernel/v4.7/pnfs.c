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
F_30 ( V_34 ) ;
if ( F_31 ( & V_34 -> V_35 , & V_36 -> V_52 ) ) {
if ( ! F_24 ( & V_34 -> V_53 ) )
F_32 ( 1 , L_17 ) ;
F_27 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_23 ( V_34 ) ;
}
}
static int
F_33 ( struct V_33 * V_34 ,
struct V_54 * V_55 )
{
struct V_56 V_57 = {
. V_58 = V_59 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_34 ( V_63 , & V_34 -> V_64 ) ;
return F_35 ( V_34 , V_55 , & V_57 , 0 ) ;
}
static int
F_36 ( T_1 V_58 )
{
return V_58 == V_65 ?
V_66 : V_67 ;
}
static void
F_37 ( struct V_33 * V_34 , int V_68 )
{
V_34 -> V_69 = V_70 ;
if ( ! F_38 ( V_68 , & V_34 -> V_64 ) )
F_15 ( & V_34 -> V_35 ) ;
}
static void
F_39 ( struct V_33 * V_34 , int V_68 )
{
if ( F_40 ( V_68 , & V_34 -> V_64 ) )
F_41 ( & V_34 -> V_35 ) ;
}
static void
F_42 ( struct V_33 * V_34 , T_1 V_58 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
struct V_56 V_57 = {
. V_58 = V_58 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_43 ( V_71 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_37 ( V_34 , F_36 ( V_58 ) ) ;
F_35 ( V_34 , & V_71 , & V_57 , 0 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_44 ( & V_71 ) ;
F_3 ( L_18 , V_5 ,
V_58 == V_65 ? L_19 : L_20 ) ;
}
static bool
F_45 ( struct V_33 * V_34 , T_1 V_58 )
{
unsigned long V_72 , V_73 ;
int V_68 = F_36 ( V_58 ) ;
if ( F_46 ( V_68 , & V_34 -> V_64 ) == 0 )
return false ;
V_73 = V_70 ;
V_72 = V_73 - V_74 ;
if ( ! F_47 ( V_34 -> V_69 , V_72 , V_73 ) ) {
F_39 ( V_34 , V_68 ) ;
return false ;
}
return true ;
}
static void
F_48 ( struct V_33 * V_34 , struct V_75 * V_76 )
{
F_49 ( & V_76 -> V_77 ) ;
F_49 ( & V_76 -> V_78 ) ;
F_50 ( & V_76 -> V_79 , 1 ) ;
F_51 () ;
F_34 ( V_80 , & V_76 -> V_81 ) ;
V_76 -> V_82 = V_34 ;
}
static void F_52 ( struct V_75 * V_76 )
{
struct V_36 * V_37 = V_76 -> V_82 -> V_41 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_76 ) ;
}
static void
F_53 ( struct V_33 * V_34 ,
struct V_75 * V_76 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
F_54 ( F_46 ( V_80 , & V_76 -> V_81 ) ) ;
F_25 ( & V_76 -> V_77 ) ;
F_41 ( & V_34 -> V_35 ) ;
if ( F_24 ( & V_34 -> V_53 ) ) {
F_34 ( V_63 , & V_34 -> V_64 ) ;
F_55 ( V_83 , & V_34 -> V_64 ) ;
}
F_56 ( & F_22 ( V_36 ) -> V_84 ) ;
}
void
F_57 ( struct V_75 * V_76 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
if ( ! V_76 )
return;
F_3 ( L_21 , V_5 , V_76 ,
F_58 ( & V_76 -> V_79 ) ,
F_46 ( V_80 , & V_76 -> V_81 ) ) ;
V_34 = V_76 -> V_82 ;
V_36 = V_34 -> V_41 ;
if ( F_31 ( & V_76 -> V_79 , & V_36 -> V_52 ) ) {
if ( F_46 ( V_80 , & V_76 -> V_81 ) ) {
F_7 ( & V_36 -> V_52 ) ;
return;
}
F_20 ( V_34 ) ;
F_53 ( V_34 , V_76 ) ;
F_7 ( & V_36 -> V_52 ) ;
F_52 ( V_76 ) ;
F_29 ( V_34 ) ;
}
}
static void F_59 ( struct V_85 * V_86 )
{
struct V_75 * V_76 ;
struct V_33 * V_34 ;
V_76 = F_60 ( V_86 , struct V_75 , V_87 ) ;
V_34 = V_76 -> V_82 ;
F_52 ( V_76 ) ;
F_29 ( V_34 ) ;
}
static void F_61 ( struct V_75 * V_76 )
{
F_62 ( & V_76 -> V_87 , F_59 ) ;
F_63 ( & V_76 -> V_87 ) ;
}
void
F_64 ( struct V_75 * V_76 )
{
if ( ! V_76 )
return;
F_65 ( & V_76 -> V_82 -> V_41 -> V_52 ) ;
F_3 ( L_21 , V_5 , V_76 ,
F_58 ( & V_76 -> V_79 ) ,
F_46 ( V_80 , & V_76 -> V_81 ) ) ;
if ( F_9 ( & V_76 -> V_79 ) ) {
struct V_33 * V_34 = V_76 -> V_82 ;
if ( F_46 ( V_80 , & V_76 -> V_81 ) )
return;
F_20 ( V_34 ) ;
F_53 ( V_34 , V_76 ) ;
F_61 ( V_76 ) ;
}
}
static T_3
F_66 ( T_3 V_72 , T_3 V_88 )
{
T_3 V_73 ;
V_73 = V_72 + V_88 ;
return V_73 >= V_72 ? V_73 : V_62 ;
}
static bool
F_67 ( const struct V_56 * V_89 ,
const struct V_56 * V_90 )
{
T_3 V_91 = V_89 -> V_60 ;
T_3 V_92 = F_66 ( V_91 , V_89 -> V_61 ) ;
T_3 V_93 = V_90 -> V_60 ;
T_3 V_94 = F_66 ( V_93 , V_90 -> V_61 ) ;
return ( V_91 <= V_93 ) && ( V_92 >= V_94 ) ;
}
static bool
F_68 ( const struct V_56 * V_89 ,
const struct V_56 * V_90 )
{
T_3 V_91 = V_89 -> V_60 ;
T_3 V_92 = F_66 ( V_91 , V_89 -> V_61 ) ;
T_3 V_93 = V_90 -> V_60 ;
T_3 V_94 = F_66 ( V_93 , V_90 -> V_61 ) ;
return ( V_92 == V_62 || V_92 > V_93 ) &&
( V_94 == V_62 || V_94 > V_91 ) ;
}
static bool
F_69 ( const struct V_56 * V_95 ,
const struct V_56 * V_96 )
{
return ( V_96 -> V_58 == V_59 ||
V_95 -> V_58 == V_96 -> V_58 ) &&
F_68 ( V_95 , V_96 ) ;
}
static bool F_70 ( struct V_75 * V_76 ,
struct V_54 * V_97 )
{
if ( ! F_9 ( & V_76 -> V_79 ) )
return false ;
F_53 ( V_76 -> V_82 , V_76 ) ;
F_17 ( & V_76 -> V_77 , V_97 ) ;
return true ;
}
static int F_71 ( struct V_75 * V_76 ,
struct V_54 * V_97 )
{
int V_98 = 0 ;
if ( F_40 ( V_80 , & V_76 -> V_81 ) ) {
F_3 ( L_22 , V_5 , V_76 ,
F_58 ( & V_76 -> V_79 ) ) ;
if ( F_70 ( V_76 , V_97 ) )
V_98 = 1 ;
}
return V_98 ;
}
static bool F_72 ( T_1 V_99 , T_1 V_100 )
{
return ( V_101 ) ( V_99 - V_100 ) > 0 ;
}
int
F_35 ( struct V_33 * V_34 ,
struct V_54 * V_97 ,
const struct V_56 * V_96 ,
T_1 V_102 )
{
struct V_75 * V_76 , * V_103 ;
int V_104 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_73 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_96 ||
F_69 ( & V_76 -> V_105 , V_96 ) ) {
if ( V_102 && F_72 ( V_76 -> V_106 , V_102 ) )
continue;
F_3 ( L_24
L_25 , V_5 ,
V_76 , V_76 -> V_105 . V_58 , V_76 -> V_106 ,
V_76 -> V_105 . V_60 , V_76 -> V_105 . V_61 ) ;
if ( ! F_71 ( V_76 , V_97 ) )
V_104 ++ ;
}
F_3 ( L_26 , V_5 , V_104 ) ;
return V_104 ;
}
void
F_44 ( struct V_54 * V_107 )
{
struct V_75 * V_76 , * V_27 ;
if ( F_24 ( V_107 ) )
return;
F_73 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_76 -> V_77 ) ;
F_52 ( V_76 ) ;
}
}
void
F_74 ( struct V_47 * V_48 )
{
struct V_33 * V_34 ;
F_43 ( V_97 ) ;
F_5 ( & V_48 -> V_108 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
F_20 ( V_34 ) ;
F_33 ( V_34 , & V_97 ) ;
F_39 ( V_34 , V_67 ) ;
F_39 ( V_34 , V_66 ) ;
F_7 ( & V_48 -> V_108 . V_52 ) ;
F_44 ( & V_97 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_108 . V_52 ) ;
}
static bool
F_75 ( struct V_36 * V_36 ,
struct V_54 * V_109 )
{
struct V_33 * V_34 ;
bool V_110 = false ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 != NULL && F_24 ( & V_34 -> V_111 ) ) {
F_20 ( V_34 ) ;
F_17 ( & V_34 -> V_111 , V_109 ) ;
V_110 = true ;
}
F_7 ( & V_36 -> V_52 ) ;
return V_110 ;
}
static int
F_76 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_54 * V_109 )
{
struct V_33 * V_34 , * V_103 ;
struct V_36 * V_36 ;
F_73 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_77 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_75 ( V_36 , V_109 ) )
continue;
F_78 () ;
F_7 ( & V_43 -> V_44 ) ;
F_79 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_80 () ;
return - V_112 ;
}
return 0 ;
}
static int
F_81 ( struct V_54 * V_109 ,
bool V_113 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
F_43 ( V_55 ) ;
int V_110 = 0 ;
while ( ! F_24 ( V_109 ) ) {
V_34 = F_82 ( V_109 -> V_103 , struct V_33 ,
V_111 ) ;
F_3 ( L_27 , V_5 ,
V_34 -> V_41 -> V_114 ) ;
V_36 = V_34 -> V_41 ;
F_83 ( V_36 , false ) ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_111 ) ;
if ( F_33 ( V_34 , & V_55 ) ) {
if ( V_113 )
F_34 ( V_83 , & V_34 -> V_64 ) ;
V_110 = - V_112 ;
}
F_7 ( & V_36 -> V_52 ) ;
F_44 ( & V_55 ) ;
F_84 ( V_36 , 0 ) ;
F_29 ( V_34 ) ;
F_79 ( V_36 ) ;
}
return V_110 ;
}
int
F_85 ( struct V_12 * V_43 ,
struct V_115 * V_116 ,
bool V_117 )
{
struct V_8 * V_14 ;
F_43 ( V_109 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_80 () ;
V_118:
F_86 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_116 , V_116 , sizeof( * V_116 ) ) != 0 )
continue;
if ( F_76 ( V_43 ,
V_14 ,
& V_109 ) != 0 )
goto V_118;
}
F_78 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_109 ) )
return 0 ;
return F_81 ( & V_109 , V_117 ) ;
}
int
F_87 ( struct V_12 * V_43 ,
bool V_117 )
{
struct V_8 * V_14 ;
F_43 ( V_109 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_80 () ;
V_118:
F_86 (server, &clp->cl_superblocks, client_link) {
if ( F_76 ( V_43 ,
V_14 ,
& V_109 ) != 0 )
goto V_118;
}
F_78 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_109 ) )
return 0 ;
return F_81 ( & V_109 , V_117 ) ;
}
void
F_88 ( struct V_12 * V_43 )
{
F_89 ( V_43 ) ;
F_10 ( V_43 ) ;
F_87 ( V_43 , false ) ;
}
void
F_90 ( struct V_33 * V_34 , const T_4 * V_119 ,
bool V_120 )
{
T_1 V_121 , V_122 , V_123 ;
int V_124 = F_24 ( & V_34 -> V_53 ) ;
V_121 = F_91 ( V_34 -> V_125 . V_126 ) ;
V_122 = F_91 ( V_119 -> V_126 ) ;
if ( V_124 || F_72 ( V_122 , V_121 ) ) {
F_92 ( & V_34 -> V_125 , V_119 ) ;
if ( V_120 ) {
V_123 = F_91 ( V_119 -> V_126 ) ;
} else {
V_123 = V_122 - F_58 ( & V_34 -> V_127 ) ;
}
if ( V_124 || F_72 ( V_123 , V_34 -> V_128 ) )
V_34 -> V_128 = V_123 ;
}
}
static bool
F_93 ( const struct V_33 * V_34 ,
const T_4 * V_129 )
{
T_1 V_126 = F_91 ( V_129 -> V_126 ) ;
return ! F_72 ( V_126 , V_34 -> V_128 ) ;
}
static bool
F_94 ( const struct V_33 * V_34 )
{
return V_34 -> V_130 ||
F_46 ( V_83 , & V_34 -> V_64 ) ;
}
static struct V_75 *
F_95 ( struct V_33 * V_34 ,
struct V_131 * V_132 ,
T_4 * V_129 ,
const struct V_56 * V_57 ,
long * V_133 , T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_134 * V_135 ;
T_5 V_136 ;
F_3 ( L_28 , V_5 ) ;
V_135 = F_96 ( sizeof( * V_135 ) , V_38 ) ;
if ( V_135 == NULL )
return F_97 ( - V_137 ) ;
V_136 = F_98 ( V_37 ) ;
V_135 -> args . V_138 = V_139 ;
if ( V_135 -> args . V_138 > V_57 -> V_61 )
V_135 -> args . V_138 = V_57 -> V_61 ;
if ( V_57 -> V_58 == V_140 ) {
if ( V_57 -> V_60 >= V_136 )
V_135 -> args . V_138 = 0 ;
else if ( V_136 - V_57 -> V_60 < V_135 -> args . V_138 )
V_135 -> args . V_138 = V_136 - V_57 -> V_60 ;
}
V_135 -> args . V_141 = V_142 ;
F_99 ( & V_135 -> args . V_57 , V_57 ) ;
V_135 -> args . type = V_14 -> V_10 -> V_2 ;
V_135 -> args . V_36 = V_37 ;
V_135 -> args . V_132 = F_100 ( V_132 ) ;
F_92 ( & V_135 -> args . V_129 , V_129 ) ;
V_135 -> V_38 = V_38 ;
V_135 -> V_143 = V_34 -> V_45 ;
return F_101 ( V_135 , V_133 , V_38 ) ;
}
static void F_102 ( struct V_36 * V_36 ,
struct V_54 * V_71 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_75 * V_76 , * V_27 ;
if ( ! F_40 ( V_144 , & V_48 -> V_145 ) )
return;
F_73 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_40 ( V_146 , & V_76 -> V_81 ) )
continue;
F_70 ( V_76 , V_71 ) ;
}
}
void F_103 ( struct V_33 * V_34 )
{
F_104 ( V_147 , & V_34 -> V_64 ) ;
F_105 () ;
F_106 ( & V_34 -> V_64 , V_147 ) ;
F_56 ( & F_22 ( V_34 -> V_41 ) -> V_84 ) ;
}
static bool
F_107 ( struct V_33 * V_34 )
{
if ( F_38 ( V_147 , & V_34 -> V_64 ) )
return false ;
V_34 -> V_148 = 0 ;
V_34 -> V_149 = 0 ;
F_20 ( V_34 ) ;
F_55 ( V_150 , & V_34 -> V_64 ) ;
return true ;
}
static int
F_108 ( struct V_33 * V_34 , const T_4 * V_129 ,
enum V_151 V_58 , bool V_152 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_153 * V_154 ;
int V_25 = 0 ;
V_154 = F_96 ( sizeof( * V_154 ) , V_155 ) ;
if ( F_109 ( V_154 == NULL ) ) {
V_25 = - V_137 ;
F_5 ( & V_37 -> V_52 ) ;
F_103 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
F_92 ( & V_154 -> args . V_129 , V_129 ) ;
V_154 -> args . V_156 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_154 -> args . V_36 = V_37 ;
V_154 -> args . V_57 . V_58 = V_58 ;
V_154 -> args . V_57 . V_60 = 0 ;
V_154 -> args . V_57 . V_61 = V_62 ;
V_154 -> args . V_49 = V_34 ;
V_154 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_154 -> V_143 = V_34 -> V_45 ;
V_25 = F_110 ( V_154 , V_152 ) ;
V_4:
F_3 ( L_29 , V_5 , V_25 ) ;
return V_25 ;
}
static bool
F_111 ( struct V_33 * V_34 )
{
struct V_75 * V_157 ;
if ( ! F_46 ( V_150 , & V_34 -> V_64 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list) {
if ( F_46 ( V_158 , & V_157 -> V_81 ) )
return false ;
}
return true ;
}
static void F_30 ( struct V_33 * V_34 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
if ( ! F_46 ( V_150 , & V_34 -> V_64 ) )
return;
F_5 ( & V_36 -> V_52 ) ;
if ( F_111 ( V_34 ) ) {
T_4 V_129 ;
enum V_151 V_58 ;
bool V_159 ;
F_92 ( & V_129 , & V_34 -> V_125 ) ;
V_129 . V_126 = F_112 ( V_34 -> V_149 ) ;
V_58 = V_34 -> V_148 ;
V_159 = F_107 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_159 ) {
F_108 ( V_34 , & V_129 , V_58 , false ) ;
}
} else
F_7 ( & V_36 -> V_52 ) ;
}
int
F_113 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_43 ( V_97 ) ;
T_4 V_129 ;
int V_25 = 0 , V_124 ;
bool V_159 ;
F_3 ( L_30 , V_5 , V_37 -> V_114 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
F_92 ( & V_129 , & V_48 -> V_49 -> V_125 ) ;
F_20 ( V_34 ) ;
V_124 = F_24 ( & V_34 -> V_53 ) ;
F_102 ( V_37 , & V_97 ) ;
F_35 ( V_34 , & V_97 , NULL , 0 ) ;
if ( F_22 ( V_37 ) -> V_10 -> V_160 ) {
struct V_56 V_57 = {
. V_58 = V_59 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_22 ( V_37 ) -> V_10 -> V_160 ( V_34 , & V_57 ) ;
}
if ( V_124 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_161;
}
F_34 ( V_63 , & V_34 -> V_64 ) ;
V_159 = F_107 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_97 ) ;
if ( V_159 )
V_25 = F_108 ( V_34 , & V_129 , V_59 , true ) ;
V_161:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_29 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_114 ( struct V_36 * V_36 )
{
struct V_33 * V_34 ;
int V_110 ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 == NULL ) {
F_7 ( & V_36 -> V_52 ) ;
return 0 ;
}
F_20 ( V_34 ) ;
V_34 -> V_130 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_115 ( V_36 -> V_162 ) ;
V_110 = F_83 ( V_36 , true ) ;
if ( V_110 == 0 )
V_110 = F_113 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_130 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_110 ;
}
bool F_116 ( struct V_36 * V_37 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_131 * V_132 ;
struct V_163 * V_164 ;
struct V_33 * V_34 ;
struct V_75 * V_76 , * V_27 ;
T_4 V_129 ;
F_43 ( V_97 ) ;
bool V_165 = false , V_166 = false , V_167 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 || F_46 ( V_83 , & V_34 -> V_64 ) )
goto V_168;
if ( F_117 ( V_37 , V_169 ) )
goto V_168;
F_2 (ctx, &nfsi->open_files, list) {
V_164 = V_132 -> V_164 ;
if ( V_164 != NULL && V_164 -> V_164 != 0 )
goto V_168;
}
F_92 ( & V_129 , & V_34 -> V_125 ) ;
if ( F_40 ( V_150 ,
& V_34 -> V_64 ) )
V_166 = F_107 ( V_34 ) ;
F_73 (lseg, tmp, &lo->plh_segs, pls_list)
if ( V_166 || F_46 ( V_170 , & V_76 -> V_81 ) ) {
F_71 ( V_76 , & V_97 ) ;
V_165 = true ;
}
if ( V_165 && ! V_166 ) {
F_20 ( V_34 ) ;
V_167 = true ;
}
V_168:
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_97 ) ;
F_83 ( V_37 , true ) ;
if ( V_166 )
F_108 ( V_34 , & V_129 , V_59 , true ) ;
return V_167 ;
}
void F_118 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
F_103 ( V_34 ) ;
if ( F_9 ( & V_34 -> V_35 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_23 ( V_34 ) ;
} else
F_7 ( & V_37 -> V_52 ) ;
}
void F_119 ( struct V_36 * V_37 , T_1 V_171 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
F_120 ( V_34 ) ;
if ( F_72 ( V_171 , V_34 -> V_128 ) )
V_34 -> V_128 = V_171 ;
F_7 ( & V_37 -> V_52 ) ;
F_121 ( V_37 , 0 ) ;
}
void F_122 ( struct V_36 * V_37 , T_1 * V_171 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
T_1 V_172 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
V_172 = F_91 ( V_34 -> V_125 . V_126 ) ;
* V_171 = V_172 + F_58 ( & V_34 -> V_127 ) ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_123 ( struct V_36 * V_37 , struct V_173 * V_174 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
bool V_175 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 && F_46 ( V_147 , & V_34 -> V_64 ) )
V_175 = true ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_175 )
F_124 ( & F_22 ( V_37 ) -> V_84 , V_174 , NULL ) ;
return V_175 ;
}
static T_6
F_125 ( const struct V_56 * V_89 ,
const struct V_56 * V_90 )
{
T_6 V_176 ;
V_176 = V_89 -> V_60 - V_90 -> V_60 ;
if ( V_176 )
return V_176 ;
V_176 = V_90 -> V_61 - V_89 -> V_61 ;
if ( V_176 )
return V_176 ;
return ( int ) ( V_89 -> V_58 == V_140 ) - ( int ) ( V_90 -> V_58 == V_140 ) ;
}
static bool
F_126 ( const struct V_56 * V_89 ,
const struct V_56 * V_90 )
{
return F_125 ( V_89 , V_90 ) > 0 ;
}
static bool
F_127 ( struct V_75 * V_76 ,
struct V_75 * V_177 )
{
return false ;
}
void
F_128 ( struct V_33 * V_34 ,
struct V_75 * V_76 ,
bool (* F_129)( const struct V_56 * ,
const struct V_56 * ) ,
bool (* F_130)( struct V_75 * ,
struct V_75 * ) ,
struct V_54 * V_107 )
{
struct V_75 * V_178 , * V_27 ;
F_3 ( L_33 , V_5 ) ;
F_73 (lp, tmp, &lo->plh_segs, pls_list) {
if ( F_46 ( V_80 , & V_178 -> V_81 ) == 0 )
continue;
if ( F_130 ( V_76 , V_178 ) ) {
F_71 ( V_178 , V_107 ) ;
continue;
}
if ( F_129 ( & V_76 -> V_105 , & V_178 -> V_105 ) )
continue;
F_131 ( & V_76 -> V_77 , & V_178 -> V_77 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_76 , V_76 -> V_105 . V_58 ,
V_76 -> V_105 . V_60 , V_76 -> V_105 . V_61 ,
V_178 , V_178 -> V_105 . V_58 , V_178 -> V_105 . V_60 ,
V_178 -> V_105 . V_61 ) ;
goto V_4;
}
F_131 ( & V_76 -> V_77 , & V_34 -> V_53 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_76 , V_76 -> V_105 . V_58 ,
V_76 -> V_105 . V_60 , V_76 -> V_105 . V_61 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_38 , V_5 ) ;
}
static void
F_132 ( struct V_33 * V_34 ,
struct V_75 * V_76 ,
struct V_54 * V_107 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
if ( V_39 -> V_179 != NULL )
V_39 -> V_179 ( V_34 , V_76 , V_107 ) ;
else
F_128 ( V_34 , V_76 ,
F_126 ,
F_127 ,
V_107 ) ;
}
static struct V_33 *
F_133 ( struct V_36 * V_37 ,
struct V_131 * V_132 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_50 ( & V_34 -> V_35 , 1 ) ;
F_49 ( & V_34 -> V_42 ) ;
F_49 ( & V_34 -> V_53 ) ;
F_49 ( & V_34 -> V_111 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_134 ( V_132 -> V_143 ) ;
V_34 -> V_64 |= 1 << V_63 ;
return V_34 ;
}
static struct V_33 *
F_135 ( struct V_36 * V_37 ,
struct V_131 * V_132 ,
T_2 V_38 )
__releases( &ino->i_lock
static bool
F_136 ( const struct V_56 * V_180 ,
const struct V_56 * V_57 ,
bool V_181 )
{
struct V_56 V_182 ;
if ( ( V_57 -> V_58 == V_65 &&
V_180 -> V_58 != V_65 ) ||
( V_57 -> V_58 != V_180 -> V_58 &&
V_181 == true ) ||
! F_68 ( V_180 , V_57 ) )
return 0 ;
V_182 = * V_57 ;
V_182 . V_61 = 1 ;
return F_67 ( V_180 , & V_182 ) ;
}
static struct V_75 *
F_137 ( struct V_33 * V_34 ,
struct V_56 * V_57 ,
bool V_181 )
{
struct V_75 * V_76 , * V_110 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_46 ( V_80 , & V_76 -> V_81 ) &&
! F_46 ( V_158 , & V_76 -> V_81 ) &&
F_136 ( & V_76 -> V_105 , V_57 ,
V_181 ) ) {
V_110 = F_138 ( V_76 ) ;
break;
}
}
F_3 ( L_39 ,
V_5 , V_110 , V_110 ? F_58 ( & V_110 -> V_79 ) : 0 ) ;
return V_110 ;
}
static bool F_139 ( struct V_131 * V_132 ,
struct V_36 * V_37 , int V_58 )
{
struct V_183 * V_184 = V_132 -> V_185 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_5 V_186 = F_98 ( V_37 ) ;
bool V_187 = false , V_188 = false , V_189 = false , V_190 = false , V_110 = false ;
if ( V_184 == NULL )
return V_110 ;
F_3 ( L_40 ,
V_5 , V_184 -> V_191 , V_184 -> V_192 , V_184 -> V_193 , V_184 -> V_194 , V_184 -> V_195 ) ;
switch ( V_58 ) {
case V_140 :
if ( V_184 -> V_191 & V_196 ) {
F_3 ( L_41 , V_5 , V_186 ) ;
V_188 = true ;
if ( V_186 < V_184 -> V_192 )
V_187 = true ;
}
if ( V_184 -> V_191 & V_197 ) {
F_3 ( L_42 , V_5 ,
V_48 -> V_51 ) ;
V_190 = true ;
if ( V_48 -> V_51 < V_184 -> V_194 )
V_189 = true ;
}
break;
case V_65 :
if ( V_184 -> V_191 & V_198 ) {
F_3 ( L_41 , V_5 , V_186 ) ;
V_188 = true ;
if ( V_186 < V_184 -> V_193 )
V_187 = true ;
}
if ( V_184 -> V_191 & V_199 ) {
F_3 ( L_43 , V_5 ,
V_48 -> V_50 ) ;
V_190 = true ;
if ( V_48 -> V_50 < V_184 -> V_195 )
V_189 = true ;
}
break;
}
if ( V_188 && V_190 ) {
if ( V_187 && V_189 )
V_110 = true ;
} else if ( V_187 || V_189 )
V_110 = true ;
F_3 ( L_44 , V_5 , V_187 , V_189 , V_110 ) ;
return V_110 ;
}
static bool F_140 ( struct V_33 * V_34 )
{
F_83 ( V_34 -> V_41 , false ) ;
return ! F_141 ( & V_34 -> V_64 , V_147 ,
V_200 ,
V_201 ) ;
}
static void F_142 ( struct V_33 * V_34 )
{
unsigned long * V_202 = & V_34 -> V_64 ;
F_104 ( V_203 , V_202 ) ;
F_105 () ;
F_106 ( V_202 , V_203 ) ;
}
struct V_75 *
F_143 ( struct V_36 * V_37 ,
struct V_131 * V_132 ,
T_5 V_204 ,
T_3 V_205 ,
enum V_151 V_58 ,
bool V_181 ,
T_2 V_38 )
{
struct V_56 V_206 = {
. V_58 = V_58 ,
. V_60 = V_204 ,
. V_61 = V_205 ,
} ;
unsigned V_207 , V_102 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 = NULL ;
struct V_75 * V_76 = NULL ;
T_4 V_129 ;
long V_133 = 0 ;
unsigned long V_208 = V_70 + F_144 ( V_14 -> V_209 ) ;
bool V_210 ;
if ( ! F_145 ( F_22 ( V_37 ) ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_211 ) ;
goto V_4;
}
if ( V_58 == V_140 && F_98 ( V_37 ) == 0 ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_212 ) ;
goto V_4;
}
if ( F_139 ( V_132 , V_37 , V_58 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_213 ) ;
goto V_4;
}
V_214:
V_210 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_135 ( V_37 , V_132 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_215 ) ;
goto V_4;
}
if ( F_46 ( V_83 , & V_34 -> V_64 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_216 ) ;
F_3 ( L_45 , V_5 ) ;
goto V_217;
}
if ( F_45 ( V_34 , V_58 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_218 ) ;
goto V_217;
}
V_76 = F_137 ( V_34 , & V_206 , V_181 ) ;
if ( V_76 ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_219 ) ;
goto V_217;
}
if ( ! F_147 ( V_132 -> V_164 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_220 ) ;
goto V_217;
}
if ( F_46 ( V_63 , & V_34 -> V_64 ) ) {
if ( F_38 ( V_203 ,
& V_34 -> V_64 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_148 ( & V_34 -> V_64 , V_203 ,
V_201 ) ;
F_29 ( V_34 ) ;
F_3 ( L_46 , V_5 ) ;
goto V_214;
}
V_210 = true ;
do {
V_102 = F_149 ( & V_132 -> V_164 -> V_221 ) ;
F_92 ( & V_129 , & V_132 -> V_164 -> V_129 ) ;
} while ( F_150 ( & V_132 -> V_164 -> V_221 , V_102 ) );
} else {
F_92 ( & V_129 , & V_34 -> V_125 ) ;
}
if ( F_46 ( V_147 , & V_34 -> V_64 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_47 , V_5 ) ;
if ( F_140 ( V_34 ) ) {
if ( V_210 )
F_142 ( V_34 ) ;
F_29 ( V_34 ) ;
F_3 ( L_46 , V_5 ) ;
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 ,
V_76 , V_222 ) ;
goto V_214;
}
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_223 ) ;
goto V_161;
}
if ( F_94 ( V_34 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_224 ) ;
goto V_217;
}
F_15 ( & V_34 -> V_127 ) ;
F_7 ( & V_37 -> V_52 ) ;
if ( F_24 ( & V_34 -> V_42 ) ) {
F_5 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_34 -> V_42 ) )
F_131 ( & V_34 -> V_42 , & V_14 -> V_225 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_207 = V_206 . V_60 & ~ V_226 ;
if ( V_207 ) {
V_206 . V_60 -= V_207 ;
V_206 . V_61 += V_207 ;
}
if ( V_206 . V_61 != V_62 )
V_206 . V_61 = F_151 ( V_206 . V_61 ) ;
V_76 = F_95 ( V_34 , V_132 , & V_129 , & V_206 , & V_133 , V_38 ) ;
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_227 ) ;
if ( F_152 ( V_76 ) ) {
switch( F_153 ( V_76 ) ) {
case - V_228 :
if ( F_154 ( V_70 , V_208 ) )
V_76 = NULL ;
case - V_112 :
F_29 ( V_34 ) ;
if ( V_210 )
F_142 ( V_34 ) ;
if ( V_76 ) {
F_146 ( V_37 , V_204 , V_205 ,
V_58 , V_34 , V_76 , V_222 ) ;
goto V_214;
}
default:
if ( ! F_155 ( F_153 ( V_76 ) ) ) {
F_39 ( V_34 , F_36 ( V_58 ) ) ;
V_76 = NULL ;
}
}
} else {
F_39 ( V_34 , F_36 ( V_58 ) ) ;
}
F_41 ( & V_34 -> V_127 ) ;
V_161:
if ( V_210 )
F_142 ( V_34 ) ;
F_29 ( V_34 ) ;
V_4:
F_3 ( L_48
L_49 ,
V_5 , V_37 -> V_229 -> V_230 ,
( unsigned long long ) F_156 ( V_37 ) ,
F_157 ( V_76 ) ? L_50 : L_51 ,
V_58 == V_65 ? L_52 : L_53 ,
( unsigned long long ) V_204 ,
( unsigned long long ) V_205 ) ;
return V_76 ;
V_217:
F_7 ( & V_37 -> V_52 ) ;
goto V_161;
}
static bool
F_158 ( struct V_56 * V_57 )
{
switch ( V_57 -> V_58 ) {
case V_140 :
case V_65 :
break;
default:
return false ;
}
if ( V_57 -> V_60 == V_62 )
return false ;
if ( V_57 -> V_61 == 0 )
return false ;
if ( V_57 -> V_61 != V_62 &&
V_57 -> V_61 > V_62 - V_57 -> V_60 )
return false ;
return true ;
}
struct V_75 *
F_159 ( struct V_134 * V_135 )
{
struct V_33 * V_34 = F_28 ( V_135 -> args . V_36 ) -> V_49 ;
struct V_231 * V_232 = & V_135 -> V_232 ;
struct V_75 * V_76 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_43 ( V_107 ) ;
if ( ! F_158 ( & V_232 -> V_57 ) )
return F_97 ( - V_26 ) ;
V_76 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_232 , V_135 -> V_38 ) ;
if ( F_157 ( V_76 ) ) {
if ( ! V_76 )
V_76 = F_97 ( - V_137 ) ;
F_3 ( L_54 ,
V_5 , F_153 ( V_76 ) ) ;
return V_76 ;
}
F_48 ( V_34 , V_76 ) ;
V_76 -> V_105 = V_232 -> V_57 ;
V_76 -> V_106 = F_91 ( V_232 -> V_129 . V_126 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_94 ( V_34 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_233;
}
if ( F_160 ( & V_34 -> V_125 , & V_232 -> V_129 ) ) {
if ( F_93 ( V_34 , & V_232 -> V_129 ) ) {
F_3 ( L_56 , V_5 ) ;
goto V_233;
}
F_90 ( V_34 , & V_232 -> V_129 , false ) ;
} else {
F_35 ( V_34 , & V_107 , NULL , 0 ) ;
F_92 ( & V_34 -> V_125 , & V_232 -> V_129 ) ;
V_34 -> V_128 = F_91 ( V_232 -> V_129 . V_126 ) ;
}
F_55 ( V_63 , & V_34 -> V_64 ) ;
F_138 ( V_76 ) ;
F_132 ( V_34 , V_76 , & V_107 ) ;
if ( V_232 -> V_234 )
F_34 ( V_170 , & V_76 -> V_81 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_107 ) ;
return V_76 ;
V_233:
F_7 ( & V_37 -> V_52 ) ;
V_76 -> V_82 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_76 ) ;
return F_97 ( - V_112 ) ;
}
static void
F_161 ( struct V_33 * V_34 , enum V_151 V_58 ,
T_1 V_102 )
{
if ( V_34 -> V_148 == V_58 )
return;
if ( V_34 -> V_148 != 0 )
V_58 = V_59 ;
V_34 -> V_148 = V_58 ;
F_34 ( V_150 , & V_34 -> V_64 ) ;
if ( ! V_34 -> V_149 || F_72 ( V_102 , V_34 -> V_149 ) )
V_34 -> V_149 = V_102 ;
}
int
F_162 ( struct V_33 * V_34 ,
struct V_54 * V_97 ,
const struct V_56 * V_160 ,
T_1 V_102 )
{
struct V_75 * V_76 , * V_103 ;
int V_104 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_65 ( & V_34 -> V_41 -> V_52 ) ;
F_73 (lseg, next, &lo->plh_segs, pls_list)
if ( F_69 ( & V_76 -> V_105 , V_160 ) ) {
F_3 ( L_57
L_25 , V_5 ,
V_76 , V_76 -> V_105 . V_58 ,
V_76 -> V_105 . V_60 ,
V_76 -> V_105 . V_61 ) ;
if ( F_71 ( V_76 , V_97 ) )
continue;
V_104 ++ ;
F_34 ( V_158 , & V_76 -> V_81 ) ;
}
if ( V_104 )
F_161 ( V_34 , V_160 -> V_58 , V_102 ) ;
return V_104 ;
}
void F_163 ( struct V_36 * V_36 ,
struct V_75 * V_76 )
{
struct V_33 * V_34 = F_28 ( V_36 ) -> V_49 ;
struct V_56 V_57 = {
. V_58 = V_76 -> V_105 . V_58 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_43 ( V_107 ) ;
bool V_235 = false ;
F_5 ( & V_36 -> V_52 ) ;
F_161 ( V_34 , V_57 . V_58 , V_76 -> V_106 ) ;
if ( ! F_162 ( V_34 , & V_107 ,
& V_57 , V_76 -> V_106 ) ) {
T_4 V_129 ;
enum V_151 V_58 = V_34 -> V_148 ;
F_92 ( & V_129 , & V_34 -> V_125 ) ;
V_235 = F_107 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_235 )
F_108 ( V_34 , & V_129 , V_58 , false ) ;
} else {
F_7 ( & V_36 -> V_52 ) ;
F_84 ( V_36 , 0 ) ;
}
F_44 ( & V_107 ) ;
}
void
F_164 ( struct V_236 * V_237 , struct V_238 * V_239 )
{
T_3 V_240 = V_239 -> V_241 ;
if ( V_237 -> V_242 == NULL ) {
if ( V_237 -> V_243 == NULL )
V_240 = F_98 ( V_237 -> V_244 ) - F_165 ( V_239 ) ;
else
V_240 = F_166 ( V_237 -> V_243 ) ;
V_237 -> V_242 = F_143 ( V_237 -> V_244 ,
V_239 -> V_245 ,
F_165 ( V_239 ) ,
V_240 ,
V_140 ,
false ,
V_246 ) ;
if ( F_152 ( V_237 -> V_242 ) ) {
V_237 -> V_247 = F_153 ( V_237 -> V_242 ) ;
V_237 -> V_242 = NULL ;
return;
}
}
if ( V_237 -> V_242 == NULL )
F_167 ( V_237 ) ;
}
void
F_168 ( struct V_236 * V_237 ,
struct V_238 * V_239 , T_3 V_248 )
{
if ( V_237 -> V_242 == NULL ) {
V_237 -> V_242 = F_143 ( V_237 -> V_244 ,
V_239 -> V_245 ,
F_165 ( V_239 ) ,
V_248 ,
V_65 ,
false ,
V_155 ) ;
if ( F_152 ( V_237 -> V_242 ) ) {
V_237 -> V_247 = F_153 ( V_237 -> V_242 ) ;
V_237 -> V_242 = NULL ;
return;
}
}
if ( V_237 -> V_242 == NULL )
F_169 ( V_237 ) ;
}
void
F_170 ( struct V_236 * V_249 )
{
if ( V_249 -> V_242 ) {
F_57 ( V_249 -> V_242 ) ;
V_249 -> V_242 = NULL ;
}
}
T_7
F_171 ( struct V_236 * V_237 ,
struct V_238 * V_250 , struct V_238 * V_239 )
{
unsigned int V_187 ;
T_3 V_251 , V_252 , V_253 ;
V_187 = F_172 ( V_237 , V_250 , V_239 ) ;
if ( ! V_187 )
return 0 ;
if ( V_237 -> V_242 ) {
V_251 = F_66 ( V_237 -> V_242 -> V_105 . V_60 ,
V_237 -> V_242 -> V_105 . V_61 ) ;
V_252 = F_165 ( V_239 ) ;
F_173 ( V_252 >= V_251 ) ;
if ( V_252 >= V_251 ) {
if ( V_237 -> V_254 -> V_255 )
V_237 -> V_254 -> V_255 ( V_237 ) ;
if ( V_237 -> V_254 -> V_256 )
V_237 -> V_254 -> V_256 ( V_237 , V_239 ) ;
return 0 ;
}
V_253 = V_251 - V_252 ;
if ( V_253 < V_187 )
V_187 = ( unsigned int ) V_253 ;
}
return V_187 ;
}
int F_174 ( struct V_257 * V_258 )
{
struct V_236 V_237 ;
F_175 ( & V_237 , V_258 -> V_36 , V_259 , true ,
V_258 -> V_260 ) ;
F_34 ( V_261 , & V_258 -> args . V_262 -> V_145 ) ;
return F_176 ( & V_237 , V_258 ) ;
}
static void F_177 ( struct V_257 * V_258 )
{
F_3 ( L_58 , V_258 -> V_263 ) ;
if ( F_22 ( V_258 -> V_36 ) -> V_10 -> V_145 &
V_264 ) {
F_178 ( V_258 -> V_36 ) ;
}
if ( ! F_38 ( V_265 , & V_258 -> V_145 ) )
V_258 -> V_174 . V_266 = F_174 ( V_258 ) ;
}
void F_179 ( struct V_257 * V_258 )
{
if ( F_180 ( ! V_258 -> V_263 ) ) {
F_181 ( V_258 -> V_36 , V_258 -> V_76 ,
V_258 -> V_267 + V_258 -> V_232 . V_205 ) ;
V_258 -> V_268 -> V_269 ( & V_258 -> V_174 , V_258 ) ;
}
F_182 ( V_258 , V_258 -> V_263 ) ;
if ( F_109 ( V_258 -> V_263 ) )
F_177 ( V_258 ) ;
V_258 -> V_268 -> V_270 ( V_258 ) ;
}
static void
F_183 ( struct V_236 * V_249 ,
struct V_257 * V_258 )
{
struct V_271 * V_272 = F_184 ( V_249 ) ;
if ( ! F_38 ( V_265 , & V_258 -> V_145 ) ) {
F_185 ( & V_258 -> V_273 , & V_272 -> V_274 ) ;
F_169 ( V_249 ) ;
V_272 -> V_275 = 1 ;
}
F_186 ( V_258 ) ;
V_258 -> V_276 ( V_258 ) ;
}
static enum V_277
F_187 ( struct V_257 * V_258 ,
const struct V_278 * V_279 ,
struct V_75 * V_76 ,
int V_280 )
{
struct V_36 * V_36 = V_258 -> V_36 ;
enum V_277 V_281 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_258 -> V_268 = V_279 ;
F_3 ( L_59 , V_5 ,
V_36 -> V_114 , V_258 -> args . V_205 , V_258 -> args . V_60 , V_280 ) ;
V_281 = V_9 -> V_10 -> V_282 ( V_258 , V_280 ) ;
if ( V_281 != V_283 )
F_188 ( V_36 , V_284 ) ;
F_3 ( L_60 , V_5 , V_281 ) ;
return V_281 ;
}
static void
F_189 ( struct V_236 * V_249 ,
struct V_257 * V_258 , int V_280 )
{
const struct V_278 * V_279 = V_249 -> V_285 ;
struct V_75 * V_76 = V_249 -> V_242 ;
enum V_277 V_281 ;
V_281 = F_187 ( V_258 , V_279 , V_76 , V_280 ) ;
if ( V_281 == V_283 )
F_183 ( V_249 , V_258 ) ;
}
static void F_190 ( struct V_257 * V_258 )
{
F_57 ( V_258 -> V_76 ) ;
F_191 ( V_258 ) ;
}
int
F_192 ( struct V_236 * V_249 )
{
struct V_257 * V_258 ;
int V_110 ;
V_258 = F_193 ( V_249 -> V_286 ) ;
if ( ! V_258 ) {
V_249 -> V_247 = - V_137 ;
return V_249 -> V_247 ;
}
F_194 ( V_249 , V_258 , F_190 ) ;
V_258 -> V_76 = F_138 ( V_249 -> V_242 ) ;
V_110 = F_195 ( V_249 , V_258 ) ;
if ( ! V_110 )
F_189 ( V_249 , V_258 , V_249 -> V_287 ) ;
return V_110 ;
}
int F_196 ( struct V_257 * V_258 )
{
struct V_236 V_237 ;
F_197 ( & V_237 , V_258 -> V_36 , true , V_258 -> V_260 ) ;
return F_176 ( & V_237 , V_258 ) ;
}
static void F_198 ( struct V_257 * V_258 )
{
F_3 ( L_61 , V_258 -> V_263 ) ;
if ( F_22 ( V_258 -> V_36 ) -> V_10 -> V_145 &
V_264 ) {
F_178 ( V_258 -> V_36 ) ;
}
if ( ! F_38 ( V_265 , & V_258 -> V_145 ) )
V_258 -> V_174 . V_266 = F_196 ( V_258 ) ;
}
void F_199 ( struct V_257 * V_258 )
{
if ( F_180 ( ! V_258 -> V_263 ) ) {
F_200 ( V_258 ) ;
V_258 -> V_268 -> V_269 ( & V_258 -> V_174 , V_258 ) ;
}
F_201 ( V_258 , V_258 -> V_263 ) ;
if ( F_109 ( V_258 -> V_263 ) )
F_198 ( V_258 ) ;
V_258 -> V_268 -> V_270 ( V_258 ) ;
}
static void
F_202 ( struct V_236 * V_249 ,
struct V_257 * V_258 )
{
struct V_271 * V_272 = F_184 ( V_249 ) ;
if ( ! F_38 ( V_265 , & V_258 -> V_145 ) ) {
F_185 ( & V_258 -> V_273 , & V_272 -> V_274 ) ;
F_167 ( V_249 ) ;
V_272 -> V_275 = 1 ;
}
F_186 ( V_258 ) ;
V_258 -> V_276 ( V_258 ) ;
}
static enum V_277
F_203 ( struct V_257 * V_258 ,
const struct V_278 * V_279 ,
struct V_75 * V_76 )
{
struct V_36 * V_36 = V_258 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_277 V_281 ;
V_258 -> V_268 = V_279 ;
F_3 ( L_62 ,
V_5 , V_36 -> V_114 , V_258 -> args . V_205 , V_258 -> args . V_60 ) ;
V_281 = V_9 -> V_10 -> V_288 ( V_258 ) ;
if ( V_281 != V_283 )
F_188 ( V_36 , V_289 ) ;
F_3 ( L_60 , V_5 , V_281 ) ;
return V_281 ;
}
void F_204 ( struct V_257 * V_258 )
{
struct V_236 V_237 ;
if ( ! F_38 ( V_265 , & V_258 -> V_145 ) ) {
F_197 ( & V_237 , V_258 -> V_36 , false ,
V_258 -> V_260 ) ;
V_258 -> V_174 . V_266 = F_176 ( & V_237 , V_258 ) ;
}
}
static void
F_205 ( struct V_236 * V_249 , struct V_257 * V_258 )
{
const struct V_278 * V_279 = V_249 -> V_285 ;
struct V_75 * V_76 = V_249 -> V_242 ;
enum V_277 V_281 ;
V_281 = F_203 ( V_258 , V_279 , V_76 ) ;
if ( V_281 == V_290 )
F_204 ( V_258 ) ;
if ( V_281 == V_283 || V_258 -> V_174 . V_266 )
F_202 ( V_249 , V_258 ) ;
}
static void F_206 ( struct V_257 * V_258 )
{
F_57 ( V_258 -> V_76 ) ;
F_191 ( V_258 ) ;
}
int
F_207 ( struct V_236 * V_249 )
{
struct V_257 * V_258 ;
int V_110 ;
V_258 = F_193 ( V_249 -> V_286 ) ;
if ( ! V_258 ) {
V_249 -> V_247 = - V_137 ;
return V_249 -> V_247 ;
}
F_194 ( V_249 , V_258 , F_206 ) ;
V_258 -> V_76 = F_138 ( V_249 -> V_242 ) ;
V_110 = F_195 ( V_249 , V_258 ) ;
if ( ! V_110 )
F_205 ( V_249 , V_258 ) ;
return V_110 ;
}
static void F_208 ( struct V_36 * V_36 )
{
unsigned long * V_202 = & F_28 ( V_36 ) -> V_145 ;
F_104 ( V_291 , V_202 ) ;
F_105 () ;
F_106 ( V_202 , V_291 ) ;
}
static void F_209 ( struct V_36 * V_36 , struct V_54 * V_292 )
{
struct V_75 * V_76 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_76 -> V_105 . V_58 == V_65 &&
F_40 ( V_146 , & V_76 -> V_81 ) )
F_17 ( & V_76 -> V_78 , V_292 ) ;
}
}
static void F_210 ( struct V_36 * V_36 , struct V_54 * V_292 )
{
struct V_75 * V_76 , * V_27 ;
F_73 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_76 -> V_78 ) ;
F_57 ( V_76 ) ;
}
F_208 ( V_36 ) ;
}
void F_211 ( struct V_75 * V_76 )
{
F_42 ( V_76 -> V_82 , V_76 -> V_105 . V_58 ) ;
}
void
F_181 ( struct V_36 * V_36 , struct V_75 * V_76 ,
T_5 V_293 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
bool V_294 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_38 ( V_144 , & V_48 -> V_145 ) ) {
V_48 -> V_49 -> V_295 = V_293 ;
V_294 = true ;
F_3 ( L_63 ,
V_5 , V_36 -> V_114 ) ;
} else if ( V_293 > V_48 -> V_49 -> V_295 )
V_48 -> V_49 -> V_295 = V_293 ;
if ( ! F_38 ( V_146 , & V_76 -> V_81 ) ) {
F_138 ( V_76 ) ;
}
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_64 ,
V_5 , V_76 , V_48 -> V_49 -> V_295 ) ;
if ( V_294 )
F_212 ( V_36 ) ;
}
void F_213 ( struct V_296 * V_297 )
{
struct V_8 * V_9 = F_22 ( V_297 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_298 )
V_9 -> V_10 -> V_298 ( V_297 ) ;
F_210 ( V_297 -> args . V_36 , & V_297 -> V_55 ) ;
}
int
F_83 ( struct V_36 * V_36 , bool V_152 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_296 * V_297 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_5 V_293 ;
int V_25 ;
if ( ! F_214 ( V_36 ) )
return 0 ;
F_3 ( L_65 , V_5 , V_36 -> V_114 ) ;
V_25 = - V_112 ;
if ( F_38 ( V_291 , & V_48 -> V_145 ) ) {
if ( ! V_152 )
goto V_4;
V_25 = F_215 ( & V_48 -> V_145 ,
V_291 ,
V_200 ,
V_299 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_137 ;
V_297 = F_96 ( sizeof( * V_297 ) , V_155 ) ;
if ( ! V_297 )
goto V_300;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_40 ( V_144 , & V_48 -> V_145 ) )
goto V_217;
F_49 ( & V_297 -> V_55 ) ;
F_209 ( V_36 , & V_297 -> V_55 ) ;
V_293 = V_48 -> V_49 -> V_295 ;
F_92 ( & V_297 -> args . V_129 , & V_48 -> V_49 -> V_125 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_297 -> args . V_36 = V_36 ;
V_297 -> V_143 = F_134 ( V_48 -> V_49 -> V_45 ) ;
F_216 ( & V_297 -> V_301 ) ;
V_297 -> args . V_302 = F_22 ( V_36 ) -> V_303 ;
V_297 -> V_232 . V_301 = & V_297 -> V_301 ;
V_297 -> args . V_304 = V_293 - 1 ;
V_297 -> V_232 . V_14 = F_22 ( V_36 ) ;
if ( V_39 -> V_305 ) {
V_25 = V_39 -> V_305 ( & V_297 -> args ) ;
if ( V_25 ) {
F_26 ( V_297 -> V_143 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_34 ( V_144 , & V_48 -> V_145 ) ;
if ( V_293 > V_48 -> V_49 -> V_295 )
V_48 -> V_49 -> V_295 = V_293 ;
goto V_217;
}
}
V_25 = F_217 ( V_297 , V_152 ) ;
V_4:
if ( V_25 )
F_212 ( V_36 ) ;
F_3 ( L_66 , V_5 , V_25 ) ;
return V_25 ;
V_217:
F_7 ( & V_36 -> V_52 ) ;
F_218 ( V_297 ) ;
V_300:
F_208 ( V_36 ) ;
goto V_4;
}
int
F_219 ( struct V_36 * V_36 , bool V_306 )
{
return F_83 ( V_36 , true ) ;
}
struct V_183 * F_220 ( void )
{
struct V_183 * V_307 ;
V_307 = F_96 ( sizeof( * V_307 ) , V_155 ) ;
if ( ! V_307 ) {
F_3 ( L_67 , V_5 ) ;
return NULL ;
}
return V_307 ;
}
int
F_221 ( struct V_36 * V_36 , T_2 V_38 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_308 * V_297 ;
struct V_33 * V_258 ;
int V_25 = 0 ;
if ( ! F_145 ( V_14 ) || ! V_39 -> V_309 )
goto V_4;
if ( ! F_222 ( V_36 , V_310 ) )
goto V_4;
if ( F_38 ( V_311 , & V_48 -> V_145 ) )
goto V_4;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_28 ( V_36 ) -> V_49 ) {
F_7 ( & V_36 -> V_52 ) ;
goto V_312;
}
V_258 = F_28 ( V_36 ) -> V_49 ;
F_20 ( V_258 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_297 = F_96 ( sizeof( * V_297 ) , V_38 ) ;
if ( ! V_297 ) {
V_25 = - V_137 ;
goto V_313;
}
V_297 -> args . V_314 = F_223 ( V_36 ) ;
V_297 -> args . V_36 = V_36 ;
F_92 ( & V_297 -> args . V_129 , & V_258 -> V_125 ) ;
V_25 = V_39 -> V_309 ( & V_297 -> args ) ;
if ( V_25 )
goto V_315;
V_25 = F_224 ( F_22 ( V_36 ) , V_297 ) ;
V_4:
F_3 ( L_68 , V_5 , V_25 ) ;
return V_25 ;
V_315:
F_218 ( V_297 ) ;
V_313:
F_29 ( V_258 ) ;
V_312:
F_225 () ;
F_55 ( V_311 , & V_48 -> V_145 ) ;
F_105 () ;
goto V_4;
}
