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
static int
F_12 ( const void * V_14 , const void * V_15 )
{
T_1 V_16 = * ( ( T_1 * ) V_14 ) ;
T_1 V_17 = * ( ( T_1 * ) V_15 ) ;
int V_18 ;
for ( V_18 = 0 ; V_19 [ V_18 ] != 0 ; V_18 ++ ) {
if ( V_16 == V_19 [ V_18 ] )
return - 1 ;
if ( V_17 == V_19 [ V_18 ] )
return 1 ;
}
return 0 ;
}
void
F_13 ( struct V_8 * V_20 , const struct V_21 * V_22 ,
struct V_23 * V_24 )
{
struct V_1 * V_25 = NULL ;
T_1 V_2 ;
int V_18 ;
if ( V_24 -> V_26 == 0 )
goto V_27;
if ( ! ( V_20 -> V_12 -> V_28 &
( V_29 | V_30 ) ) ) {
F_14 ( V_31 L_3 ,
V_5 , V_20 -> V_12 -> V_28 ) ;
goto V_27;
}
F_15 ( V_24 -> V_32 , V_24 -> V_26 ,
sizeof( * V_24 -> V_32 ) , F_12 , NULL ) ;
for ( V_18 = 0 ; V_18 < V_24 -> V_26 ; V_18 ++ ) {
V_2 = V_24 -> V_32 [ V_18 ] ;
V_25 = F_4 ( V_2 ) ;
if ( ! V_25 ) {
F_16 ( L_4 , V_33 ,
V_2 ) ;
V_25 = F_4 ( V_2 ) ;
}
if ( V_25 )
break;
}
if ( ! V_25 ) {
F_3 ( L_5 , V_5 ) ;
goto V_27;
}
V_20 -> V_10 = V_25 ;
if ( V_25 -> V_34
&& V_25 -> V_34 ( V_20 , V_22 ) ) {
F_14 ( V_31 L_6
L_7 , V_5 , V_2 ) ;
F_11 ( V_25 -> V_7 ) ;
goto V_27;
}
F_17 ( & V_20 -> V_12 -> V_13 ) ;
F_3 ( L_8 , V_5 , V_2 ) ;
return;
V_27:
F_3 ( L_9 , V_5 ) ;
V_20 -> V_10 = NULL ;
}
int
F_18 ( struct V_1 * V_25 )
{
int V_35 = - V_36 ;
struct V_1 * V_37 ;
if ( V_25 -> V_2 == 0 ) {
F_14 ( V_31 L_10 , V_5 ) ;
return V_35 ;
}
if ( ! V_25 -> V_38 || ! V_25 -> V_39 ) {
F_14 ( V_31 L_11
L_12 , V_5 ) ;
return V_35 ;
}
F_5 ( & V_6 ) ;
V_37 = F_1 ( V_25 -> V_2 ) ;
if ( ! V_37 ) {
F_19 ( & V_25 -> V_40 , & V_41 ) ;
V_35 = 0 ;
F_3 ( L_13 , V_5 , V_25 -> V_2 ,
V_25 -> V_42 ) ;
} else {
F_14 ( V_31 L_14 ,
V_5 , V_25 -> V_2 ) ;
}
F_7 ( & V_6 ) ;
return V_35 ;
}
void
F_20 ( struct V_1 * V_25 )
{
F_3 ( L_15 , V_5 , V_25 -> V_2 ) ;
F_5 ( & V_6 ) ;
F_21 ( & V_25 -> V_40 ) ;
F_7 ( & V_6 ) ;
}
void
F_22 ( struct V_43 * V_44 )
{
F_17 ( & V_44 -> V_45 ) ;
}
static struct V_43 *
F_23 ( struct V_46 * V_47 , T_2 V_48 )
{
struct V_1 * V_49 = F_24 ( V_47 ) -> V_10 ;
return V_49 -> V_50 ( V_47 , V_48 ) ;
}
static void
F_25 ( struct V_43 * V_44 )
{
struct V_8 * V_20 = F_24 ( V_44 -> V_51 ) ;
struct V_1 * V_49 = V_20 -> V_10 ;
if ( ! F_26 ( & V_44 -> V_52 ) ) {
struct V_12 * V_53 = V_20 -> V_12 ;
F_5 ( & V_53 -> V_54 ) ;
F_27 ( & V_44 -> V_52 ) ;
F_7 ( & V_53 -> V_54 ) ;
}
F_28 ( V_44 -> V_55 ) ;
return V_49 -> V_56 ( V_44 ) ;
}
static void
F_29 ( struct V_43 * V_44 )
{
struct V_57 * V_58 = F_30 ( V_44 -> V_51 ) ;
F_3 ( L_16 , V_5 , V_44 ) ;
V_58 -> V_59 = NULL ;
V_58 -> V_60 = 0 ;
V_58 -> V_61 = 0 ;
}
void
F_31 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
F_32 ( V_44 ) ;
if ( F_33 ( & V_44 -> V_45 , & V_46 -> V_62 ) ) {
if ( ! F_26 ( & V_44 -> V_63 ) )
F_34 ( 1 , L_17 ) ;
F_29 ( V_44 ) ;
F_7 ( & V_46 -> V_62 ) ;
F_25 ( V_44 ) ;
}
}
int
F_35 ( struct V_43 * V_44 ,
struct V_64 * V_65 )
{
struct V_66 V_67 = {
. V_68 = V_69 ,
. V_70 = 0 ,
. V_71 = V_72 ,
} ;
F_36 ( V_73 , & V_44 -> V_74 ) ;
return F_37 ( V_44 , V_65 , & V_67 , 0 ) ;
}
static int
F_38 ( T_1 V_68 )
{
return V_68 == V_75 ?
V_76 : V_77 ;
}
static void
F_39 ( struct V_43 * V_44 , int V_78 )
{
V_44 -> V_79 = V_80 ;
if ( ! F_40 ( V_78 , & V_44 -> V_74 ) )
F_17 ( & V_44 -> V_45 ) ;
}
static void
F_41 ( struct V_43 * V_44 , int V_78 )
{
if ( F_42 ( V_78 , & V_44 -> V_74 ) )
F_43 ( & V_44 -> V_45 ) ;
}
static void
F_44 ( struct V_43 * V_44 , T_1 V_68 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
struct V_66 V_67 = {
. V_68 = V_68 ,
. V_70 = 0 ,
. V_71 = V_72 ,
} ;
F_45 ( V_81 ) ;
F_5 ( & V_46 -> V_62 ) ;
F_39 ( V_44 , F_38 ( V_68 ) ) ;
F_37 ( V_44 , & V_81 , & V_67 , 0 ) ;
F_7 ( & V_46 -> V_62 ) ;
F_46 ( & V_81 ) ;
F_3 ( L_18 , V_5 ,
V_68 == V_75 ? L_19 : L_20 ) ;
}
static bool
F_47 ( struct V_43 * V_44 , T_1 V_68 )
{
unsigned long V_82 , V_83 ;
int V_78 = F_38 ( V_68 ) ;
if ( F_48 ( V_78 , & V_44 -> V_74 ) == 0 )
return false ;
V_83 = V_80 ;
V_82 = V_83 - V_84 ;
if ( ! F_49 ( V_44 -> V_79 , V_82 , V_83 ) ) {
F_41 ( V_44 , V_78 ) ;
return false ;
}
return true ;
}
static void
F_50 ( struct V_43 * V_44 , struct V_85 * V_86 ,
const struct V_66 * V_67 ,
const T_3 * V_87 )
{
F_51 ( & V_86 -> V_88 ) ;
F_51 ( & V_86 -> V_89 ) ;
F_52 ( & V_86 -> V_90 , 1 ) ;
F_36 ( V_91 , & V_86 -> V_92 ) ;
V_86 -> V_93 = V_44 ;
V_86 -> V_94 = * V_67 ;
V_86 -> V_95 = F_53 ( V_87 -> V_96 ) ;
}
static void F_54 ( struct V_85 * V_86 )
{
struct V_46 * V_47 = V_86 -> V_93 -> V_51 ;
F_24 ( V_47 ) -> V_10 -> V_39 ( V_86 ) ;
}
static void
F_55 ( struct V_43 * V_44 ,
struct V_85 * V_86 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
F_56 ( F_48 ( V_91 , & V_86 -> V_92 ) ) ;
F_27 ( & V_86 -> V_88 ) ;
F_43 ( & V_44 -> V_45 ) ;
if ( F_26 ( & V_44 -> V_63 ) ) {
if ( F_57 ( & V_44 -> V_97 ) == 0 )
F_36 ( V_73 , & V_44 -> V_74 ) ;
F_58 ( V_98 , & V_44 -> V_74 ) ;
}
F_59 ( & F_24 ( V_46 ) -> V_99 ) ;
}
void
F_60 ( struct V_85 * V_86 )
{
struct V_43 * V_44 ;
struct V_46 * V_46 ;
if ( ! V_86 )
return;
F_3 ( L_21 , V_5 , V_86 ,
F_57 ( & V_86 -> V_90 ) ,
F_48 ( V_91 , & V_86 -> V_92 ) ) ;
V_44 = V_86 -> V_93 ;
V_46 = V_44 -> V_51 ;
if ( F_33 ( & V_86 -> V_90 , & V_46 -> V_62 ) ) {
if ( F_48 ( V_91 , & V_86 -> V_92 ) ) {
F_7 ( & V_46 -> V_62 ) ;
return;
}
F_22 ( V_44 ) ;
F_55 ( V_44 , V_86 ) ;
F_7 ( & V_46 -> V_62 ) ;
F_54 ( V_86 ) ;
F_31 ( V_44 ) ;
}
}
static void F_61 ( struct V_100 * V_101 )
{
struct V_85 * V_86 ;
struct V_43 * V_44 ;
V_86 = F_62 ( V_101 , struct V_85 , V_102 ) ;
V_44 = V_86 -> V_93 ;
F_54 ( V_86 ) ;
F_31 ( V_44 ) ;
}
static void F_63 ( struct V_85 * V_86 )
{
F_64 ( & V_86 -> V_102 , F_61 ) ;
F_65 ( & V_86 -> V_102 ) ;
}
void
F_66 ( struct V_85 * V_86 )
{
if ( ! V_86 )
return;
F_67 ( & V_86 -> V_93 -> V_51 -> V_62 ) ;
F_3 ( L_21 , V_5 , V_86 ,
F_57 ( & V_86 -> V_90 ) ,
F_48 ( V_91 , & V_86 -> V_92 ) ) ;
if ( F_9 ( & V_86 -> V_90 ) ) {
struct V_43 * V_44 = V_86 -> V_93 ;
if ( F_48 ( V_91 , & V_86 -> V_92 ) )
return;
F_22 ( V_44 ) ;
F_55 ( V_44 , V_86 ) ;
F_63 ( V_86 ) ;
}
}
static T_4
F_68 ( T_4 V_82 , T_4 V_103 )
{
T_4 V_83 ;
V_83 = V_82 + V_103 ;
return V_83 >= V_82 ? V_83 : V_72 ;
}
static bool
F_69 ( const struct V_66 * V_104 ,
const struct V_66 * V_105 )
{
T_4 V_106 = V_104 -> V_70 ;
T_4 V_107 = F_68 ( V_106 , V_104 -> V_71 ) ;
T_4 V_108 = V_105 -> V_70 ;
T_4 V_109 = F_68 ( V_108 , V_105 -> V_71 ) ;
return ( V_106 <= V_108 ) && ( V_107 >= V_109 ) ;
}
static bool
F_70 ( const struct V_66 * V_104 ,
const struct V_66 * V_105 )
{
T_4 V_106 = V_104 -> V_70 ;
T_4 V_107 = F_68 ( V_106 , V_104 -> V_71 ) ;
T_4 V_108 = V_105 -> V_70 ;
T_4 V_109 = F_68 ( V_108 , V_105 -> V_71 ) ;
return ( V_107 == V_72 || V_107 > V_108 ) &&
( V_109 == V_72 || V_109 > V_106 ) ;
}
static bool F_71 ( struct V_85 * V_86 ,
struct V_64 * V_110 )
{
if ( ! F_9 ( & V_86 -> V_90 ) )
return false ;
F_55 ( V_86 -> V_93 , V_86 ) ;
F_19 ( & V_86 -> V_88 , V_110 ) ;
return true ;
}
static int F_72 ( struct V_85 * V_86 ,
struct V_64 * V_110 )
{
int V_111 = 0 ;
if ( F_42 ( V_91 , & V_86 -> V_92 ) ) {
F_3 ( L_22 , V_5 , V_86 ,
F_57 ( & V_86 -> V_90 ) ) ;
if ( F_71 ( V_86 , V_110 ) )
V_111 = 1 ;
}
return V_111 ;
}
static bool F_73 ( T_1 V_112 , T_1 V_113 )
{
return ( V_114 ) ( V_112 - V_113 ) > 0 ;
}
static bool
F_74 ( const struct V_66 * V_115 ,
const struct V_66 * V_116 )
{
return ( V_116 -> V_68 == V_69 ||
V_115 -> V_68 == V_116 -> V_68 ) &&
F_70 ( V_115 , V_116 ) ;
}
static bool
F_75 ( const struct V_85 * V_86 ,
const struct V_66 * V_116 ,
T_1 V_117 )
{
if ( V_117 != 0 && F_73 ( V_86 -> V_95 , V_117 ) )
return false ;
if ( V_116 == NULL )
return true ;
return F_74 ( & V_86 -> V_94 , V_116 ) ;
}
int
F_37 ( struct V_43 * V_44 ,
struct V_64 * V_110 ,
const struct V_66 * V_116 ,
T_1 V_117 )
{
struct V_85 * V_86 , * V_118 ;
int V_119 = 0 ;
F_3 ( L_23 , V_5 , V_44 ) ;
if ( F_26 ( & V_44 -> V_63 ) )
return 0 ;
F_76 (lseg, next, &lo->plh_segs, pls_list)
if ( F_75 ( V_86 , V_116 , V_117 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_86 , V_86 -> V_94 . V_68 , V_86 -> V_95 ,
V_86 -> V_94 . V_70 , V_86 -> V_94 . V_71 ) ;
if ( ! F_72 ( V_86 , V_110 ) )
V_119 ++ ;
}
F_3 ( L_26 , V_5 , V_119 ) ;
return V_119 ;
}
void
F_46 ( struct V_64 * V_120 )
{
struct V_85 * V_86 , * V_37 ;
if ( F_26 ( V_120 ) )
return;
F_76 (lseg, tmp, free_me, pls_list) {
F_21 ( & V_86 -> V_88 ) ;
F_54 ( V_86 ) ;
}
}
void
F_77 ( struct V_57 * V_58 )
{
struct V_43 * V_44 ;
F_45 ( V_110 ) ;
F_5 ( & V_58 -> V_121 . V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( V_44 ) {
F_22 ( V_44 ) ;
F_35 ( V_44 , & V_110 ) ;
F_41 ( V_44 , V_77 ) ;
F_41 ( V_44 , V_76 ) ;
F_7 ( & V_58 -> V_121 . V_62 ) ;
F_46 ( & V_110 ) ;
F_31 ( V_44 ) ;
} else
F_7 ( & V_58 -> V_121 . V_62 ) ;
}
static bool
F_78 ( struct V_46 * V_46 ,
struct V_64 * V_122 )
{
struct V_43 * V_44 ;
bool V_123 = false ;
F_5 ( & V_46 -> V_62 ) ;
V_44 = F_30 ( V_46 ) -> V_59 ;
if ( V_44 != NULL && F_26 ( & V_44 -> V_124 ) ) {
F_22 ( V_44 ) ;
F_19 ( & V_44 -> V_124 , V_122 ) ;
V_123 = true ;
}
F_7 ( & V_46 -> V_62 ) ;
return V_123 ;
}
static int
F_79 ( struct V_12 * V_53 ,
struct V_8 * V_20 ,
struct V_64 * V_122 )
{
struct V_43 * V_44 , * V_118 ;
struct V_46 * V_46 ;
F_76 (lo, next, &server->layouts, plh_layouts) {
V_46 = F_80 ( V_44 -> V_51 ) ;
if ( V_46 == NULL )
continue;
F_27 ( & V_44 -> V_52 ) ;
if ( F_78 ( V_46 , V_122 ) )
continue;
F_81 () ;
F_7 ( & V_53 -> V_54 ) ;
F_82 ( V_46 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_83 () ;
return - V_125 ;
}
return 0 ;
}
static int
F_84 ( struct V_64 * V_122 ,
bool V_126 )
{
struct V_43 * V_44 ;
struct V_46 * V_46 ;
F_45 ( V_65 ) ;
int V_123 = 0 ;
while ( ! F_26 ( V_122 ) ) {
V_44 = F_85 ( V_122 -> V_118 , struct V_43 ,
V_124 ) ;
F_3 ( L_27 , V_5 ,
V_44 -> V_51 -> V_127 ) ;
V_46 = V_44 -> V_51 ;
F_86 ( V_46 , false ) ;
F_5 ( & V_46 -> V_62 ) ;
F_27 ( & V_44 -> V_124 ) ;
if ( F_35 ( V_44 , & V_65 ) ) {
if ( V_126 )
F_36 ( V_98 , & V_44 -> V_74 ) ;
V_123 = - V_125 ;
}
F_7 ( & V_46 -> V_62 ) ;
F_46 ( & V_65 ) ;
F_87 ( V_46 , 0 ) ;
F_31 ( V_44 ) ;
F_82 ( V_46 ) ;
}
return V_123 ;
}
int
F_88 ( struct V_12 * V_53 ,
struct V_128 * V_129 ,
bool V_130 )
{
struct V_8 * V_20 ;
F_45 ( V_122 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_83 () ;
V_131:
F_89 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_20 -> V_129 , V_129 , sizeof( * V_129 ) ) != 0 )
continue;
if ( F_79 ( V_53 ,
V_20 ,
& V_122 ) != 0 )
goto V_131;
}
F_81 () ;
F_7 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_122 ) )
return 0 ;
return F_84 ( & V_122 , V_130 ) ;
}
int
F_90 ( struct V_12 * V_53 ,
bool V_130 )
{
struct V_8 * V_20 ;
F_45 ( V_122 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_83 () ;
V_131:
F_89 (server, &clp->cl_superblocks, client_link) {
if ( F_79 ( V_53 ,
V_20 ,
& V_122 ) != 0 )
goto V_131;
}
F_81 () ;
F_7 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_122 ) )
return 0 ;
return F_84 ( & V_122 , V_130 ) ;
}
void
F_91 ( struct V_12 * V_53 )
{
F_92 ( V_53 ) ;
F_10 ( V_53 ) ;
F_90 ( V_53 , false ) ;
}
static void
F_93 ( struct V_43 * V_44 )
{
V_44 -> V_132 = 0 ;
V_44 -> V_133 = 0 ;
F_58 ( V_134 , & V_44 -> V_74 ) ;
}
void
F_94 ( struct V_43 * V_44 , const T_3 * V_135 ,
bool V_136 )
{
T_1 V_137 , V_138 , V_139 = 0 ;
V_137 = F_53 ( V_44 -> V_140 . V_96 ) ;
V_138 = F_53 ( V_135 -> V_96 ) ;
if ( ! F_95 ( V_44 ) ) {
F_96 ( & V_44 -> V_140 , V_135 ) ;
V_44 -> V_141 = V_138 ;
F_93 ( V_44 ) ;
F_58 ( V_73 , & V_44 -> V_74 ) ;
return;
}
if ( F_73 ( V_138 , V_137 ) ) {
F_96 ( & V_44 -> V_140 , V_135 ) ;
V_139 = V_138 - F_57 ( & V_44 -> V_97 ) ;
}
if ( V_136 )
V_139 = F_53 ( V_135 -> V_96 ) ;
else if ( V_139 == 0 )
return;
if ( F_73 ( V_139 , V_44 -> V_141 ) )
V_44 -> V_141 = V_139 ;
}
static bool
F_97 ( const struct V_43 * V_44 ,
const T_3 * V_87 )
{
T_1 V_96 = F_53 ( V_87 -> V_96 ) ;
return ! F_73 ( V_96 , V_44 -> V_141 ) ;
}
static bool
F_98 ( const struct V_43 * V_44 )
{
return V_44 -> V_142 ||
F_48 ( V_98 , & V_44 -> V_74 ) ;
}
static struct V_85 *
F_99 ( struct V_43 * V_44 ,
struct V_143 * V_144 ,
T_3 * V_87 ,
const struct V_66 * V_67 ,
long * V_145 , T_2 V_48 )
{
struct V_46 * V_47 = V_44 -> V_51 ;
struct V_8 * V_20 = F_24 ( V_47 ) ;
struct V_146 * V_147 ;
T_5 V_148 ;
F_3 ( L_28 , V_5 ) ;
V_147 = F_100 ( sizeof( * V_147 ) , V_48 ) ;
if ( V_147 == NULL )
return F_101 ( - V_149 ) ;
V_148 = F_102 ( V_47 ) ;
V_147 -> args . V_150 = V_151 ;
if ( V_147 -> args . V_150 > V_67 -> V_71 )
V_147 -> args . V_150 = V_67 -> V_71 ;
if ( V_67 -> V_68 == V_152 ) {
if ( V_67 -> V_70 >= V_148 )
V_147 -> args . V_150 = 0 ;
else if ( V_148 - V_67 -> V_70 < V_147 -> args . V_150 )
V_147 -> args . V_150 = V_148 - V_67 -> V_70 ;
}
V_147 -> args . V_153 = V_154 ;
F_103 ( & V_147 -> args . V_67 , V_67 ) ;
V_147 -> args . type = V_20 -> V_10 -> V_2 ;
V_147 -> args . V_46 = V_47 ;
V_147 -> args . V_144 = F_104 ( V_144 ) ;
F_96 ( & V_147 -> args . V_87 , V_87 ) ;
V_147 -> V_48 = V_48 ;
V_147 -> V_155 = V_44 -> V_55 ;
return F_105 ( V_147 , V_145 , V_48 ) ;
}
static void F_106 ( struct V_46 * V_46 ,
struct V_64 * V_81 )
{
struct V_57 * V_58 = F_30 ( V_46 ) ;
struct V_85 * V_86 , * V_37 ;
if ( ! F_42 ( V_156 , & V_58 -> V_157 ) )
return;
F_76 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_42 ( V_158 , & V_86 -> V_92 ) )
continue;
F_71 ( V_86 , V_81 ) ;
}
}
void F_107 ( struct V_43 * V_44 )
{
F_108 ( V_159 , & V_44 -> V_74 ) ;
F_109 () ;
F_110 ( & V_44 -> V_74 , V_159 ) ;
F_59 ( & F_24 ( V_44 -> V_51 ) -> V_99 ) ;
}
static bool
F_111 ( struct V_43 * V_44 ,
T_3 * V_87 ,
enum V_160 * V_68 )
{
if ( F_57 ( & V_44 -> V_97 ) != 0 )
return false ;
if ( F_40 ( V_159 , & V_44 -> V_74 ) )
return false ;
F_22 ( V_44 ) ;
if ( F_48 ( V_134 , & V_44 -> V_74 ) ) {
if ( V_87 != NULL ) {
F_96 ( V_87 , & V_44 -> V_140 ) ;
if ( V_44 -> V_133 != 0 )
V_87 -> V_96 = F_112 ( V_44 -> V_133 ) ;
}
if ( V_68 != NULL )
* V_68 = V_44 -> V_132 ;
F_93 ( V_44 ) ;
return true ;
}
if ( V_87 != NULL )
F_96 ( V_87 , & V_44 -> V_140 ) ;
if ( V_68 != NULL )
* V_68 = V_69 ;
return true ;
}
static int
F_113 ( struct V_43 * V_44 , const T_3 * V_87 ,
enum V_160 V_68 , bool V_161 )
{
struct V_46 * V_47 = V_44 -> V_51 ;
struct V_162 * V_163 ;
int V_35 = 0 ;
V_163 = F_100 ( sizeof( * V_163 ) , V_164 ) ;
if ( F_114 ( V_163 == NULL ) ) {
V_35 = - V_149 ;
F_5 ( & V_47 -> V_62 ) ;
F_107 ( V_44 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_31 ( V_44 ) ;
goto V_4;
}
F_96 ( & V_163 -> args . V_87 , V_87 ) ;
V_163 -> args . V_165 = F_24 ( V_47 ) -> V_10 -> V_2 ;
V_163 -> args . V_46 = V_47 ;
V_163 -> args . V_67 . V_68 = V_68 ;
V_163 -> args . V_67 . V_70 = 0 ;
V_163 -> args . V_67 . V_71 = V_72 ;
V_163 -> args . V_59 = V_44 ;
V_163 -> V_53 = F_24 ( V_47 ) -> V_12 ;
V_163 -> V_155 = V_44 -> V_55 ;
V_35 = F_115 ( V_163 , V_161 ) ;
V_4:
F_3 ( L_29 , V_5 , V_35 ) ;
return V_35 ;
}
static bool
F_116 ( struct V_43 * V_44 )
{
struct V_85 * V_166 ;
if ( ! F_48 ( V_134 , & V_44 -> V_74 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list) {
if ( F_48 ( V_167 , & V_166 -> V_92 ) )
return false ;
}
return true ;
}
static void F_32 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
if ( ! F_48 ( V_134 , & V_44 -> V_74 ) )
return;
F_5 ( & V_46 -> V_62 ) ;
if ( F_116 ( V_44 ) ) {
T_3 V_87 ;
enum V_160 V_68 ;
bool V_168 ;
V_168 = F_111 ( V_44 , & V_87 , & V_68 ) ;
F_7 ( & V_46 -> V_62 ) ;
if ( V_168 ) {
F_113 ( V_44 , & V_87 , V_68 , false ) ;
}
} else
F_7 ( & V_46 -> V_62 ) ;
}
int
F_117 ( struct V_46 * V_47 )
{
struct V_43 * V_44 = NULL ;
struct V_57 * V_58 = F_30 ( V_47 ) ;
F_45 ( V_110 ) ;
T_3 V_87 ;
int V_35 = 0 , V_169 ;
bool V_168 ;
F_3 ( L_30 , V_5 , V_47 -> V_127 ) ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( ! V_44 ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
F_22 ( V_44 ) ;
V_169 = F_26 ( & V_44 -> V_63 ) ;
F_106 ( V_47 , & V_110 ) ;
F_37 ( V_44 , & V_110 , NULL , 0 ) ;
if ( F_24 ( V_47 ) -> V_10 -> V_170 ) {
struct V_66 V_67 = {
. V_68 = V_69 ,
. V_70 = 0 ,
. V_71 = V_72 ,
} ;
F_24 ( V_47 ) -> V_10 -> V_170 ( V_44 , & V_67 ) ;
}
if ( V_169 ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_171;
}
V_168 = F_111 ( V_44 , & V_87 , NULL ) ;
F_7 ( & V_47 -> V_62 ) ;
F_46 ( & V_110 ) ;
if ( V_168 )
V_35 = F_113 ( V_44 , & V_87 , V_69 , true ) ;
V_171:
F_31 ( V_44 ) ;
V_4:
F_3 ( L_29 , V_5 , V_35 ) ;
return V_35 ;
}
int
F_118 ( struct V_46 * V_46 )
{
struct V_43 * V_44 ;
int V_123 ;
F_5 ( & V_46 -> V_62 ) ;
V_44 = F_30 ( V_46 ) -> V_59 ;
if ( V_44 == NULL ) {
F_7 ( & V_46 -> V_62 ) ;
return 0 ;
}
F_22 ( V_44 ) ;
V_44 -> V_142 ++ ;
F_7 ( & V_46 -> V_62 ) ;
F_119 ( V_46 -> V_172 ) ;
V_123 = F_86 ( V_46 , true ) ;
if ( V_123 == 0 )
V_123 = F_117 ( V_46 ) ;
F_5 ( & V_46 -> V_62 ) ;
V_44 -> V_142 -- ;
F_7 ( & V_46 -> V_62 ) ;
F_31 ( V_44 ) ;
return V_123 ;
}
bool F_120 ( struct V_46 * V_47 )
{
struct V_57 * V_58 = F_30 ( V_47 ) ;
struct V_143 * V_144 ;
struct V_173 * V_174 ;
struct V_43 * V_44 ;
struct V_85 * V_86 , * V_37 ;
T_3 V_87 ;
F_45 ( V_110 ) ;
bool V_175 = false , V_176 = false , V_177 = false ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( ! V_44 || F_48 ( V_98 , & V_44 -> V_74 ) )
goto V_178;
if ( F_121 ( V_47 , V_179 ) )
goto V_178;
F_2 (ctx, &nfsi->open_files, list) {
V_174 = V_144 -> V_174 ;
if ( V_174 != NULL && V_174 -> V_174 != 0 )
goto V_178;
}
if ( F_48 ( V_134 , & V_44 -> V_74 ) )
V_176 = F_111 ( V_44 ,
& V_87 , NULL ) ;
F_76 (lseg, tmp, &lo->plh_segs, pls_list)
if ( V_176 || F_48 ( V_180 , & V_86 -> V_92 ) ) {
F_72 ( V_86 , & V_110 ) ;
V_175 = true ;
}
if ( V_175 && ! V_176 ) {
F_22 ( V_44 ) ;
V_177 = true ;
}
V_178:
F_7 ( & V_47 -> V_62 ) ;
F_46 ( & V_110 ) ;
F_86 ( V_47 , true ) ;
if ( V_176 )
F_113 ( V_44 , & V_87 , V_69 , true ) ;
return V_177 ;
}
void F_122 ( struct V_46 * V_47 )
{
struct V_43 * V_44 ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = F_30 ( V_47 ) -> V_59 ;
F_107 ( V_44 ) ;
if ( F_9 ( & V_44 -> V_45 ) ) {
F_29 ( V_44 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_25 ( V_44 ) ;
} else
F_7 ( & V_47 -> V_62 ) ;
}
void F_123 ( struct V_46 * V_47 , T_1 V_181 )
{
struct V_43 * V_44 ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = F_30 ( V_47 ) -> V_59 ;
if ( F_73 ( V_181 , V_44 -> V_141 ) )
V_44 -> V_141 = V_181 ;
F_7 ( & V_47 -> V_62 ) ;
F_124 ( V_47 , 0 ) ;
}
void F_125 ( struct V_46 * V_47 , T_1 * V_181 )
{
struct V_57 * V_58 = F_30 ( V_47 ) ;
struct V_43 * V_44 ;
T_1 V_182 ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
V_182 = F_53 ( V_44 -> V_140 . V_96 ) ;
* V_181 = V_182 + F_57 ( & V_44 -> V_97 ) ;
F_7 ( & V_47 -> V_62 ) ;
}
bool F_126 ( struct V_46 * V_47 , struct V_183 * V_184 )
{
struct V_57 * V_58 = F_30 ( V_47 ) ;
struct V_43 * V_44 ;
bool V_185 = false ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( V_44 && F_48 ( V_159 , & V_44 -> V_74 ) )
V_185 = true ;
F_7 ( & V_47 -> V_62 ) ;
if ( V_185 )
F_127 ( & F_24 ( V_47 ) -> V_99 , V_184 , NULL ) ;
return V_185 ;
}
static T_6
F_128 ( const struct V_66 * V_104 ,
const struct V_66 * V_105 )
{
T_6 V_186 ;
V_186 = V_104 -> V_70 - V_105 -> V_70 ;
if ( V_186 )
return V_186 ;
V_186 = V_105 -> V_71 - V_104 -> V_71 ;
if ( V_186 )
return V_186 ;
return ( int ) ( V_104 -> V_68 == V_152 ) - ( int ) ( V_105 -> V_68 == V_152 ) ;
}
static bool
F_129 ( const struct V_66 * V_104 ,
const struct V_66 * V_105 )
{
return F_128 ( V_104 , V_105 ) > 0 ;
}
static bool
F_130 ( struct V_85 * V_86 ,
struct V_85 * V_187 )
{
return false ;
}
void
F_131 ( struct V_43 * V_44 ,
struct V_85 * V_86 ,
bool (* F_132)( const struct V_66 * ,
const struct V_66 * ) ,
bool (* F_133)( struct V_85 * ,
struct V_85 * ) ,
struct V_64 * V_120 )
{
struct V_85 * V_188 , * V_37 ;
F_3 ( L_33 , V_5 ) ;
F_76 (lp, tmp, &lo->plh_segs, pls_list) {
if ( F_48 ( V_91 , & V_188 -> V_92 ) == 0 )
continue;
if ( F_133 ( V_86 , V_188 ) ) {
F_72 ( V_188 , V_120 ) ;
continue;
}
if ( F_132 ( & V_86 -> V_94 , & V_188 -> V_94 ) )
continue;
F_134 ( & V_86 -> V_88 , & V_188 -> V_88 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_86 , V_86 -> V_94 . V_68 ,
V_86 -> V_94 . V_70 , V_86 -> V_94 . V_71 ,
V_188 , V_188 -> V_94 . V_68 , V_188 -> V_94 . V_70 ,
V_188 -> V_94 . V_71 ) ;
goto V_4;
}
F_134 ( & V_86 -> V_88 , & V_44 -> V_63 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_86 , V_86 -> V_94 . V_68 ,
V_86 -> V_94 . V_70 , V_86 -> V_94 . V_71 ) ;
V_4:
F_22 ( V_44 ) ;
F_3 ( L_38 , V_5 ) ;
}
static void
F_135 ( struct V_43 * V_44 ,
struct V_85 * V_86 ,
struct V_64 * V_120 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
if ( V_49 -> V_189 != NULL )
V_49 -> V_189 ( V_44 , V_86 , V_120 ) ;
else
F_131 ( V_44 , V_86 ,
F_129 ,
F_130 ,
V_120 ) ;
}
static struct V_43 *
F_136 ( struct V_46 * V_47 ,
struct V_143 * V_144 ,
T_2 V_48 )
{
struct V_43 * V_44 ;
V_44 = F_23 ( V_47 , V_48 ) ;
if ( ! V_44 )
return NULL ;
F_52 ( & V_44 -> V_45 , 1 ) ;
F_51 ( & V_44 -> V_52 ) ;
F_51 ( & V_44 -> V_63 ) ;
F_51 ( & V_44 -> V_124 ) ;
V_44 -> V_51 = V_47 ;
V_44 -> V_55 = F_137 ( V_144 -> V_155 ) ;
V_44 -> V_74 |= 1 << V_73 ;
return V_44 ;
}
static struct V_43 *
F_138 ( struct V_46 * V_47 ,
struct V_143 * V_144 ,
T_2 V_48 )
__releases( &ino->i_lock
static bool
F_139 ( const struct V_66 * V_190 ,
const struct V_66 * V_67 ,
bool V_191 )
{
struct V_66 V_192 ;
if ( ( V_67 -> V_68 == V_75 &&
V_190 -> V_68 != V_75 ) ||
( V_67 -> V_68 != V_190 -> V_68 &&
V_191 == true ) ||
! F_70 ( V_190 , V_67 ) )
return 0 ;
V_192 = * V_67 ;
V_192 . V_71 = 1 ;
return F_69 ( V_190 , & V_192 ) ;
}
static struct V_85 *
F_140 ( struct V_43 * V_44 ,
struct V_66 * V_67 ,
bool V_191 )
{
struct V_85 * V_86 , * V_123 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_48 ( V_91 , & V_86 -> V_92 ) &&
! F_48 ( V_167 , & V_86 -> V_92 ) &&
F_139 ( & V_86 -> V_94 , V_67 ,
V_191 ) ) {
V_123 = F_141 ( V_86 ) ;
break;
}
}
F_3 ( L_39 ,
V_5 , V_123 , V_123 ? F_57 ( & V_123 -> V_90 ) : 0 ) ;
return V_123 ;
}
static bool F_142 ( struct V_143 * V_144 ,
struct V_46 * V_47 , int V_68 )
{
struct V_193 * V_194 = V_144 -> V_195 ;
struct V_57 * V_58 = F_30 ( V_47 ) ;
T_5 V_196 = F_102 ( V_47 ) ;
bool V_197 = false , V_198 = false , V_199 = false , V_200 = false , V_123 = false ;
if ( V_194 == NULL )
return V_123 ;
F_3 ( L_40 ,
V_5 , V_194 -> V_201 , V_194 -> V_202 , V_194 -> V_203 , V_194 -> V_204 , V_194 -> V_205 ) ;
switch ( V_68 ) {
case V_152 :
if ( V_194 -> V_201 & V_206 ) {
F_3 ( L_41 , V_5 , V_196 ) ;
V_198 = true ;
if ( V_196 < V_194 -> V_202 )
V_197 = true ;
}
if ( V_194 -> V_201 & V_207 ) {
F_3 ( L_42 , V_5 ,
V_58 -> V_61 ) ;
V_200 = true ;
if ( V_58 -> V_61 < V_194 -> V_204 )
V_199 = true ;
}
break;
case V_75 :
if ( V_194 -> V_201 & V_208 ) {
F_3 ( L_41 , V_5 , V_196 ) ;
V_198 = true ;
if ( V_196 < V_194 -> V_203 )
V_197 = true ;
}
if ( V_194 -> V_201 & V_209 ) {
F_3 ( L_43 , V_5 ,
V_58 -> V_60 ) ;
V_200 = true ;
if ( V_58 -> V_60 < V_194 -> V_205 )
V_199 = true ;
}
break;
}
if ( V_198 && V_200 ) {
if ( V_197 && V_199 )
V_123 = true ;
} else if ( V_197 || V_199 )
V_123 = true ;
F_3 ( L_44 , V_5 , V_197 , V_199 , V_123 ) ;
return V_123 ;
}
static bool F_143 ( struct V_43 * V_44 )
{
F_86 ( V_44 -> V_51 , false ) ;
return ! F_144 ( & V_44 -> V_74 , V_159 ,
V_210 ,
V_211 ) ;
}
static void F_145 ( struct V_43 * V_44 )
{
unsigned long * V_212 = & V_44 -> V_74 ;
F_108 ( V_213 , V_212 ) ;
F_109 () ;
F_110 ( V_212 , V_213 ) ;
}
struct V_85 *
F_146 ( struct V_46 * V_47 ,
struct V_143 * V_144 ,
T_5 V_214 ,
T_4 V_215 ,
enum V_160 V_68 ,
bool V_191 ,
T_2 V_48 )
{
struct V_66 V_216 = {
. V_68 = V_68 ,
. V_70 = V_214 ,
. V_71 = V_215 ,
} ;
unsigned V_217 , V_117 ;
struct V_8 * V_20 = F_24 ( V_47 ) ;
struct V_12 * V_53 = V_20 -> V_12 ;
struct V_43 * V_44 = NULL ;
struct V_85 * V_86 = NULL ;
T_3 V_87 ;
long V_145 = 0 ;
unsigned long V_218 = V_80 + ( V_53 -> V_219 << 1 ) ;
bool V_220 ;
if ( ! F_147 ( F_24 ( V_47 ) ) ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_221 ) ;
goto V_4;
}
if ( V_68 == V_152 && F_102 ( V_47 ) == 0 ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_222 ) ;
goto V_4;
}
if ( F_142 ( V_144 , V_47 , V_68 ) ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_223 ) ;
goto V_4;
}
V_224:
F_149 ( V_53 ) ;
V_220 = false ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = F_138 ( V_47 , V_144 , V_48 ) ;
if ( V_44 == NULL ) {
F_7 ( & V_47 -> V_62 ) ;
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_225 ) ;
goto V_4;
}
if ( F_48 ( V_98 , & V_44 -> V_74 ) ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_226 ) ;
F_3 ( L_45 , V_5 ) ;
goto V_227;
}
if ( F_47 ( V_44 , V_68 ) ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_228 ) ;
goto V_227;
}
V_86 = F_140 ( V_44 , & V_216 , V_191 ) ;
if ( V_86 ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_229 ) ;
goto V_227;
}
if ( ! F_150 ( V_144 -> V_174 ) ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_230 ) ;
goto V_227;
}
if ( F_48 ( V_73 , & V_44 -> V_74 ) ) {
if ( F_40 ( V_213 ,
& V_44 -> V_74 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_151 ( & V_44 -> V_74 , V_213 ,
V_211 ) ;
F_31 ( V_44 ) ;
F_3 ( L_46 , V_5 ) ;
goto V_224;
}
V_220 = true ;
do {
V_117 = F_152 ( & V_144 -> V_174 -> V_231 ) ;
F_96 ( & V_87 , & V_144 -> V_174 -> V_87 ) ;
} while ( F_153 ( & V_144 -> V_174 -> V_231 , V_117 ) );
} else {
F_96 ( & V_87 , & V_44 -> V_140 ) ;
}
if ( F_48 ( V_159 , & V_44 -> V_74 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_47 , V_5 ) ;
if ( F_143 ( V_44 ) ) {
if ( V_220 )
F_145 ( V_44 ) ;
F_31 ( V_44 ) ;
F_3 ( L_46 , V_5 ) ;
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 ,
V_86 , V_232 ) ;
goto V_224;
}
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_233 ) ;
goto V_171;
}
if ( F_98 ( V_44 ) ) {
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_234 ) ;
goto V_227;
}
F_17 ( & V_44 -> V_97 ) ;
F_7 ( & V_47 -> V_62 ) ;
if ( F_26 ( & V_44 -> V_52 ) ) {
F_5 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_44 -> V_52 ) )
F_134 ( & V_44 -> V_52 , & V_20 -> V_235 ) ;
F_7 ( & V_53 -> V_54 ) ;
}
V_217 = V_216 . V_70 & ~ V_236 ;
if ( V_217 ) {
V_216 . V_70 -= V_217 ;
V_216 . V_71 += V_217 ;
}
if ( V_216 . V_71 != V_72 )
V_216 . V_71 = F_154 ( V_216 . V_71 ) ;
V_86 = F_99 ( V_44 , V_144 , & V_87 , & V_216 , & V_145 , V_48 ) ;
F_148 ( V_47 , V_214 , V_215 , V_68 , V_44 , V_86 ,
V_237 ) ;
F_43 ( & V_44 -> V_97 ) ;
if ( F_155 ( V_86 ) ) {
switch( F_156 ( V_86 ) ) {
case - V_238 :
if ( F_157 ( V_80 , V_218 ) )
V_86 = NULL ;
break;
case - V_239 :
if ( V_220 ) {
V_86 = NULL ;
break;
}
if ( F_157 ( V_80 , V_218 ) )
F_77 ( F_30 ( V_47 ) ) ;
case - V_125 :
break;
default:
if ( ! F_158 ( F_156 ( V_86 ) ) ) {
F_41 ( V_44 , F_38 ( V_68 ) ) ;
V_86 = NULL ;
}
goto V_171;
}
if ( V_86 ) {
if ( V_220 )
F_145 ( V_44 ) ;
F_148 ( V_47 , V_214 , V_215 ,
V_68 , V_44 , V_86 , V_232 ) ;
F_31 ( V_44 ) ;
goto V_224;
}
} else {
F_41 ( V_44 , F_38 ( V_68 ) ) ;
}
V_171:
if ( V_220 )
F_145 ( V_44 ) ;
F_31 ( V_44 ) ;
V_4:
F_3 ( L_48
L_49 ,
V_5 , V_47 -> V_240 -> V_241 ,
( unsigned long long ) F_159 ( V_47 ) ,
F_160 ( V_86 ) ? L_50 : L_51 ,
V_68 == V_75 ? L_52 : L_53 ,
( unsigned long long ) V_214 ,
( unsigned long long ) V_215 ) ;
return V_86 ;
V_227:
F_7 ( & V_47 -> V_62 ) ;
goto V_171;
}
static bool
F_161 ( struct V_66 * V_67 )
{
switch ( V_67 -> V_68 ) {
case V_152 :
case V_75 :
break;
default:
return false ;
}
if ( V_67 -> V_70 == V_72 )
return false ;
if ( V_67 -> V_71 == 0 )
return false ;
if ( V_67 -> V_71 != V_72 &&
V_67 -> V_71 > V_72 - V_67 -> V_70 )
return false ;
return true ;
}
struct V_85 *
F_162 ( struct V_146 * V_147 )
{
struct V_43 * V_44 = F_30 ( V_147 -> args . V_46 ) -> V_59 ;
struct V_242 * V_243 = & V_147 -> V_243 ;
struct V_85 * V_86 ;
struct V_46 * V_47 = V_44 -> V_51 ;
F_45 ( V_120 ) ;
if ( ! F_161 ( & V_243 -> V_67 ) )
return F_101 ( - V_36 ) ;
V_86 = F_24 ( V_47 ) -> V_10 -> V_38 ( V_44 , V_243 , V_147 -> V_48 ) ;
if ( F_160 ( V_86 ) ) {
if ( ! V_86 )
V_86 = F_101 ( - V_149 ) ;
F_3 ( L_54 ,
V_5 , F_156 ( V_86 ) ) ;
return V_86 ;
}
F_50 ( V_44 , V_86 , & V_243 -> V_67 , & V_243 -> V_87 ) ;
F_5 ( & V_47 -> V_62 ) ;
if ( F_98 ( V_44 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_244;
}
if ( F_163 ( & V_44 -> V_140 , & V_243 -> V_87 ) ) {
if ( F_97 ( V_44 , & V_243 -> V_87 ) ) {
F_3 ( L_56 , V_5 ) ;
goto V_244;
}
F_94 ( V_44 , & V_243 -> V_87 , false ) ;
} else {
F_35 ( V_44 , & V_120 ) ;
F_94 ( V_44 , & V_243 -> V_87 , true ) ;
}
F_141 ( V_86 ) ;
F_135 ( V_44 , V_86 , & V_120 ) ;
if ( V_243 -> V_245 )
F_36 ( V_180 , & V_86 -> V_92 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_46 ( & V_120 ) ;
return V_86 ;
V_244:
F_7 ( & V_47 -> V_62 ) ;
V_86 -> V_93 = V_44 ;
F_24 ( V_47 ) -> V_10 -> V_39 ( V_86 ) ;
return F_101 ( - V_125 ) ;
}
static void
F_164 ( struct V_43 * V_44 , enum V_160 V_68 ,
T_1 V_117 )
{
if ( V_44 -> V_132 != 0 && V_44 -> V_132 != V_68 )
V_68 = V_69 ;
V_44 -> V_132 = V_68 ;
F_36 ( V_134 , & V_44 -> V_74 ) ;
if ( V_117 != 0 ) {
F_165 ( V_44 -> V_133 != 0 && V_44 -> V_133 != V_117 ) ;
V_44 -> V_133 = V_117 ;
}
}
int
F_166 ( struct V_43 * V_44 ,
struct V_64 * V_110 ,
const struct V_66 * V_170 ,
T_1 V_117 )
{
struct V_85 * V_86 , * V_118 ;
int V_119 = 0 ;
F_3 ( L_23 , V_5 , V_44 ) ;
if ( F_26 ( & V_44 -> V_63 ) )
return 0 ;
F_67 ( & V_44 -> V_51 -> V_62 ) ;
F_76 (lseg, next, &lo->plh_segs, pls_list)
if ( F_75 ( V_86 , V_170 , V_117 ) ) {
F_3 ( L_57
L_25 , V_5 ,
V_86 , V_86 -> V_94 . V_68 ,
V_86 -> V_94 . V_70 ,
V_86 -> V_94 . V_71 ) ;
if ( F_72 ( V_86 , V_110 ) )
continue;
V_119 ++ ;
F_36 ( V_167 , & V_86 -> V_92 ) ;
}
if ( V_119 )
F_164 ( V_44 , V_170 -> V_68 , V_117 ) ;
return V_119 ;
}
void F_167 ( struct V_46 * V_46 ,
struct V_85 * V_86 )
{
struct V_43 * V_44 = F_30 ( V_46 ) -> V_59 ;
struct V_66 V_67 = {
. V_68 = V_86 -> V_94 . V_68 ,
. V_70 = 0 ,
. V_71 = V_72 ,
} ;
F_45 ( V_120 ) ;
bool V_246 = false ;
F_5 ( & V_46 -> V_62 ) ;
F_164 ( V_44 , V_67 . V_68 , 0 ) ;
if ( ! F_166 ( V_44 , & V_120 , & V_67 , 0 ) ) {
T_3 V_87 ;
enum V_160 V_68 ;
V_246 = F_111 ( V_44 , & V_87 , & V_68 ) ;
F_7 ( & V_46 -> V_62 ) ;
if ( V_246 )
F_113 ( V_44 , & V_87 , V_68 , false ) ;
} else {
F_7 ( & V_46 -> V_62 ) ;
F_87 ( V_46 , 0 ) ;
}
F_46 ( & V_120 ) ;
}
void
F_168 ( struct V_247 * V_248 , struct V_249 * V_250 )
{
T_4 V_251 = V_250 -> V_252 ;
if ( V_248 -> V_253 == NULL ) {
if ( V_248 -> V_254 == NULL )
V_251 = F_102 ( V_248 -> V_255 ) - F_169 ( V_250 ) ;
else
V_251 = F_170 ( V_248 -> V_254 ) ;
V_248 -> V_253 = F_146 ( V_248 -> V_255 ,
V_250 -> V_256 ,
F_169 ( V_250 ) ,
V_251 ,
V_152 ,
false ,
V_257 ) ;
if ( F_155 ( V_248 -> V_253 ) ) {
V_248 -> V_258 = F_156 ( V_248 -> V_253 ) ;
V_248 -> V_253 = NULL ;
return;
}
}
if ( V_248 -> V_253 == NULL )
F_171 ( V_248 ) ;
}
void
F_172 ( struct V_247 * V_248 ,
struct V_249 * V_250 , T_4 V_259 )
{
if ( V_248 -> V_253 == NULL ) {
V_248 -> V_253 = F_146 ( V_248 -> V_255 ,
V_250 -> V_256 ,
F_169 ( V_250 ) ,
V_259 ,
V_75 ,
false ,
V_164 ) ;
if ( F_155 ( V_248 -> V_253 ) ) {
V_248 -> V_258 = F_156 ( V_248 -> V_253 ) ;
V_248 -> V_253 = NULL ;
return;
}
}
if ( V_248 -> V_253 == NULL )
F_173 ( V_248 ) ;
}
void
F_174 ( struct V_247 * V_260 )
{
if ( V_260 -> V_253 ) {
F_60 ( V_260 -> V_253 ) ;
V_260 -> V_253 = NULL ;
}
}
T_7
F_175 ( struct V_247 * V_248 ,
struct V_249 * V_261 , struct V_249 * V_250 )
{
unsigned int V_197 ;
T_4 V_262 , V_263 , V_264 ;
V_197 = F_176 ( V_248 , V_261 , V_250 ) ;
if ( ! V_197 )
return 0 ;
if ( V_248 -> V_253 ) {
V_262 = F_68 ( V_248 -> V_253 -> V_94 . V_70 ,
V_248 -> V_253 -> V_94 . V_71 ) ;
V_263 = F_169 ( V_250 ) ;
F_165 ( V_263 >= V_262 ) ;
if ( V_263 >= V_262 ) {
if ( V_248 -> V_265 -> V_266 )
V_248 -> V_265 -> V_266 ( V_248 ) ;
if ( V_248 -> V_265 -> V_267 )
V_248 -> V_265 -> V_267 ( V_248 , V_250 ) ;
return 0 ;
}
V_264 = V_262 - V_263 ;
if ( V_264 < V_197 )
V_197 = ( unsigned int ) V_264 ;
}
return V_197 ;
}
int F_177 ( struct V_268 * V_269 )
{
struct V_247 V_248 ;
F_178 ( & V_248 , V_269 -> V_46 , V_270 , true ,
V_269 -> V_271 ) ;
F_36 ( V_272 , & V_269 -> args . V_273 -> V_157 ) ;
return F_179 ( & V_248 , V_269 ) ;
}
static void F_180 ( struct V_268 * V_269 )
{
F_3 ( L_58 , V_269 -> V_274 ) ;
if ( F_24 ( V_269 -> V_46 ) -> V_10 -> V_157 &
V_275 ) {
F_181 ( V_269 -> V_46 ) ;
}
if ( ! F_40 ( V_276 , & V_269 -> V_157 ) )
V_269 -> V_184 . V_277 = F_177 ( V_269 ) ;
}
void F_182 ( struct V_268 * V_269 )
{
if ( F_183 ( ! V_269 -> V_274 ) ) {
F_184 ( V_269 -> V_46 , V_269 -> V_86 ,
V_269 -> V_278 + V_269 -> V_243 . V_215 ) ;
V_269 -> V_279 -> V_280 ( & V_269 -> V_184 , V_269 ) ;
}
F_185 ( V_269 , V_269 -> V_274 ) ;
if ( F_114 ( V_269 -> V_274 ) )
F_180 ( V_269 ) ;
V_269 -> V_279 -> V_281 ( V_269 ) ;
}
static void
F_186 ( struct V_247 * V_260 ,
struct V_268 * V_269 )
{
struct V_282 * V_283 = F_187 ( V_260 ) ;
if ( ! F_40 ( V_276 , & V_269 -> V_157 ) ) {
F_188 ( & V_269 -> V_284 , & V_283 -> V_285 ) ;
F_173 ( V_260 ) ;
V_283 -> V_286 = 1 ;
}
F_189 ( V_269 ) ;
V_269 -> V_287 ( V_269 ) ;
}
static enum V_288
F_190 ( struct V_268 * V_269 ,
const struct V_289 * V_290 ,
struct V_85 * V_86 ,
int V_291 )
{
struct V_46 * V_46 = V_269 -> V_46 ;
enum V_288 V_292 ;
struct V_8 * V_9 = F_24 ( V_46 ) ;
V_269 -> V_279 = V_290 ;
F_3 ( L_59 , V_5 ,
V_46 -> V_127 , V_269 -> args . V_215 , V_269 -> args . V_70 , V_291 ) ;
V_292 = V_9 -> V_10 -> V_293 ( V_269 , V_291 ) ;
if ( V_292 != V_294 )
F_191 ( V_46 , V_295 ) ;
F_3 ( L_60 , V_5 , V_292 ) ;
return V_292 ;
}
static void
F_192 ( struct V_247 * V_260 ,
struct V_268 * V_269 , int V_291 )
{
const struct V_289 * V_290 = V_260 -> V_296 ;
struct V_85 * V_86 = V_260 -> V_253 ;
enum V_288 V_292 ;
V_292 = F_190 ( V_269 , V_290 , V_86 , V_291 ) ;
if ( V_292 == V_294 )
F_186 ( V_260 , V_269 ) ;
}
static void F_193 ( struct V_268 * V_269 )
{
F_60 ( V_269 -> V_86 ) ;
F_194 ( V_269 ) ;
}
int
F_195 ( struct V_247 * V_260 )
{
struct V_268 * V_269 ;
int V_123 ;
V_269 = F_196 ( V_260 -> V_297 ) ;
if ( ! V_269 ) {
V_260 -> V_258 = - V_149 ;
return V_260 -> V_258 ;
}
F_197 ( V_260 , V_269 , F_193 ) ;
V_269 -> V_86 = F_141 ( V_260 -> V_253 ) ;
V_123 = F_198 ( V_260 , V_269 ) ;
if ( ! V_123 )
F_192 ( V_260 , V_269 , V_260 -> V_298 ) ;
return V_123 ;
}
int F_199 ( struct V_268 * V_269 )
{
struct V_247 V_248 ;
F_200 ( & V_248 , V_269 -> V_46 , true , V_269 -> V_271 ) ;
return F_179 ( & V_248 , V_269 ) ;
}
static void F_201 ( struct V_268 * V_269 )
{
F_3 ( L_61 , V_269 -> V_274 ) ;
if ( F_24 ( V_269 -> V_46 ) -> V_10 -> V_157 &
V_275 ) {
F_181 ( V_269 -> V_46 ) ;
}
if ( ! F_40 ( V_276 , & V_269 -> V_157 ) )
V_269 -> V_184 . V_277 = F_199 ( V_269 ) ;
}
void F_202 ( struct V_268 * V_269 )
{
if ( F_183 ( ! V_269 -> V_274 ) )
V_269 -> V_279 -> V_280 ( & V_269 -> V_184 , V_269 ) ;
F_203 ( V_269 , V_269 -> V_274 ) ;
if ( F_114 ( V_269 -> V_274 ) )
F_201 ( V_269 ) ;
V_269 -> V_279 -> V_281 ( V_269 ) ;
}
static void
F_204 ( struct V_247 * V_260 ,
struct V_268 * V_269 )
{
struct V_282 * V_283 = F_187 ( V_260 ) ;
if ( ! F_40 ( V_276 , & V_269 -> V_157 ) ) {
F_188 ( & V_269 -> V_284 , & V_283 -> V_285 ) ;
F_171 ( V_260 ) ;
V_283 -> V_286 = 1 ;
}
F_189 ( V_269 ) ;
V_269 -> V_287 ( V_269 ) ;
}
static enum V_288
F_205 ( struct V_268 * V_269 ,
const struct V_289 * V_290 ,
struct V_85 * V_86 )
{
struct V_46 * V_46 = V_269 -> V_46 ;
struct V_8 * V_9 = F_24 ( V_46 ) ;
enum V_288 V_292 ;
V_269 -> V_279 = V_290 ;
F_3 ( L_62 ,
V_5 , V_46 -> V_127 , V_269 -> args . V_215 , V_269 -> args . V_70 ) ;
V_292 = V_9 -> V_10 -> V_299 ( V_269 ) ;
if ( V_292 != V_294 )
F_191 ( V_46 , V_300 ) ;
F_3 ( L_60 , V_5 , V_292 ) ;
return V_292 ;
}
void F_206 ( struct V_268 * V_269 )
{
struct V_247 V_248 ;
if ( ! F_40 ( V_276 , & V_269 -> V_157 ) ) {
F_200 ( & V_248 , V_269 -> V_46 , false ,
V_269 -> V_271 ) ;
V_269 -> V_184 . V_277 = F_179 ( & V_248 , V_269 ) ;
}
}
static void
F_207 ( struct V_247 * V_260 , struct V_268 * V_269 )
{
const struct V_289 * V_290 = V_260 -> V_296 ;
struct V_85 * V_86 = V_260 -> V_253 ;
enum V_288 V_292 ;
V_292 = F_205 ( V_269 , V_290 , V_86 ) ;
if ( V_292 == V_301 )
F_206 ( V_269 ) ;
if ( V_292 == V_294 || V_269 -> V_184 . V_277 )
F_204 ( V_260 , V_269 ) ;
}
static void F_208 ( struct V_268 * V_269 )
{
F_60 ( V_269 -> V_86 ) ;
F_194 ( V_269 ) ;
}
int
F_209 ( struct V_247 * V_260 )
{
struct V_268 * V_269 ;
int V_123 ;
V_269 = F_196 ( V_260 -> V_297 ) ;
if ( ! V_269 ) {
V_260 -> V_258 = - V_149 ;
return V_260 -> V_258 ;
}
F_197 ( V_260 , V_269 , F_208 ) ;
V_269 -> V_86 = F_141 ( V_260 -> V_253 ) ;
V_123 = F_198 ( V_260 , V_269 ) ;
if ( ! V_123 )
F_207 ( V_260 , V_269 ) ;
return V_123 ;
}
static void F_210 ( struct V_46 * V_46 )
{
unsigned long * V_212 = & F_30 ( V_46 ) -> V_157 ;
F_108 ( V_302 , V_212 ) ;
F_109 () ;
F_110 ( V_212 , V_302 ) ;
}
static void F_211 ( struct V_46 * V_46 , struct V_64 * V_303 )
{
struct V_85 * V_86 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_86 -> V_94 . V_68 == V_75 &&
F_42 ( V_158 , & V_86 -> V_92 ) )
F_19 ( & V_86 -> V_89 , V_303 ) ;
}
}
static void F_212 ( struct V_46 * V_46 , struct V_64 * V_303 )
{
struct V_85 * V_86 , * V_37 ;
F_76 (lseg, tmp, listp, pls_lc_list) {
F_27 ( & V_86 -> V_89 ) ;
F_60 ( V_86 ) ;
}
F_210 ( V_46 ) ;
}
void F_213 ( struct V_85 * V_86 )
{
F_44 ( V_86 -> V_93 , V_86 -> V_94 . V_68 ) ;
}
void
F_184 ( struct V_46 * V_46 , struct V_85 * V_86 ,
T_5 V_304 )
{
struct V_57 * V_58 = F_30 ( V_46 ) ;
bool V_305 = false ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_40 ( V_156 , & V_58 -> V_157 ) ) {
V_58 -> V_59 -> V_306 = V_304 ;
V_305 = true ;
F_3 ( L_63 ,
V_5 , V_46 -> V_127 ) ;
} else if ( V_304 > V_58 -> V_59 -> V_306 )
V_58 -> V_59 -> V_306 = V_304 ;
if ( ! F_40 ( V_158 , & V_86 -> V_92 ) ) {
F_141 ( V_86 ) ;
}
F_7 ( & V_46 -> V_62 ) ;
F_3 ( L_64 ,
V_5 , V_86 , V_58 -> V_59 -> V_306 ) ;
if ( V_305 )
F_214 ( V_46 ) ;
}
void F_215 ( struct V_307 * V_308 )
{
struct V_8 * V_9 = F_24 ( V_308 -> args . V_46 ) ;
if ( V_9 -> V_10 -> V_309 )
V_9 -> V_10 -> V_309 ( V_308 ) ;
F_212 ( V_308 -> args . V_46 , & V_308 -> V_65 ) ;
}
int
F_86 ( struct V_46 * V_46 , bool V_161 )
{
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
struct V_307 * V_308 ;
struct V_57 * V_58 = F_30 ( V_46 ) ;
T_5 V_304 ;
int V_35 ;
if ( ! F_216 ( V_46 ) )
return 0 ;
F_3 ( L_65 , V_5 , V_46 -> V_127 ) ;
V_35 = - V_125 ;
if ( F_40 ( V_302 , & V_58 -> V_157 ) ) {
if ( ! V_161 )
goto V_4;
V_35 = F_217 ( & V_58 -> V_157 ,
V_302 ,
V_210 ,
V_310 ) ;
if ( V_35 )
goto V_4;
}
V_35 = - V_149 ;
V_308 = F_100 ( sizeof( * V_308 ) , V_164 ) ;
if ( ! V_308 )
goto V_311;
V_35 = 0 ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_42 ( V_156 , & V_58 -> V_157 ) )
goto V_227;
F_51 ( & V_308 -> V_65 ) ;
F_211 ( V_46 , & V_308 -> V_65 ) ;
V_304 = V_58 -> V_59 -> V_306 ;
F_96 ( & V_308 -> args . V_87 , & V_58 -> V_59 -> V_140 ) ;
F_7 ( & V_46 -> V_62 ) ;
V_308 -> args . V_46 = V_46 ;
V_308 -> V_155 = F_137 ( V_58 -> V_59 -> V_55 ) ;
F_218 ( & V_308 -> V_312 ) ;
V_308 -> args . V_313 = F_24 ( V_46 ) -> V_314 ;
V_308 -> V_243 . V_312 = & V_308 -> V_312 ;
if ( V_304 != 0 )
V_308 -> args . V_315 = V_304 - 1 ;
else
V_308 -> args . V_315 = V_316 ;
V_308 -> V_243 . V_20 = F_24 ( V_46 ) ;
if ( V_49 -> V_317 ) {
V_35 = V_49 -> V_317 ( & V_308 -> args ) ;
if ( V_35 ) {
F_28 ( V_308 -> V_155 ) ;
F_5 ( & V_46 -> V_62 ) ;
F_36 ( V_156 , & V_58 -> V_157 ) ;
if ( V_304 > V_58 -> V_59 -> V_306 )
V_58 -> V_59 -> V_306 = V_304 ;
goto V_227;
}
}
V_35 = F_219 ( V_308 , V_161 ) ;
V_4:
if ( V_35 )
F_214 ( V_46 ) ;
F_3 ( L_66 , V_5 , V_35 ) ;
return V_35 ;
V_227:
F_7 ( & V_46 -> V_62 ) ;
F_220 ( V_308 ) ;
V_311:
F_210 ( V_46 ) ;
goto V_4;
}
int
F_221 ( struct V_46 * V_46 , bool V_318 )
{
return F_86 ( V_46 , true ) ;
}
struct V_193 * F_222 ( void )
{
struct V_193 * V_319 ;
V_319 = F_100 ( sizeof( * V_319 ) , V_164 ) ;
if ( ! V_319 ) {
F_3 ( L_67 , V_5 ) ;
return NULL ;
}
return V_319 ;
}
int
F_223 ( struct V_46 * V_46 , T_2 V_48 )
{
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
struct V_8 * V_20 = F_24 ( V_46 ) ;
struct V_57 * V_58 = F_30 ( V_46 ) ;
struct V_320 * V_308 ;
struct V_43 * V_269 ;
int V_35 = 0 ;
if ( ! F_147 ( V_20 ) || ! V_49 -> V_321 )
goto V_4;
if ( ! F_224 ( V_46 , V_322 ) )
goto V_4;
if ( F_40 ( V_323 , & V_58 -> V_157 ) )
goto V_4;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_30 ( V_46 ) -> V_59 ) {
F_7 ( & V_46 -> V_62 ) ;
goto V_324;
}
V_269 = F_30 ( V_46 ) -> V_59 ;
F_22 ( V_269 ) ;
F_7 ( & V_46 -> V_62 ) ;
V_308 = F_100 ( sizeof( * V_308 ) , V_48 ) ;
if ( ! V_308 ) {
V_35 = - V_149 ;
goto V_325;
}
V_308 -> args . V_326 = F_225 ( V_46 ) ;
V_308 -> args . V_46 = V_46 ;
V_35 = V_49 -> V_321 ( & V_308 -> args ) ;
if ( V_35 )
goto V_327;
V_35 = F_226 ( F_24 ( V_46 ) , V_308 ) ;
V_4:
F_3 ( L_68 , V_5 , V_35 ) ;
return V_35 ;
V_327:
F_220 ( V_308 ) ;
V_325:
F_31 ( V_269 ) ;
V_324:
F_227 () ;
F_58 ( V_323 , & V_58 -> V_157 ) ;
F_109 () ;
goto V_4;
}
