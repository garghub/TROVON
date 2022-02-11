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
int
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
F_48 ( struct V_33 * V_34 , struct V_75 * V_76 ,
const struct V_56 * V_57 ,
const T_3 * V_77 )
{
F_49 ( & V_76 -> V_78 ) ;
F_49 ( & V_76 -> V_79 ) ;
F_50 ( & V_76 -> V_80 , 1 ) ;
F_34 ( V_81 , & V_76 -> V_82 ) ;
V_76 -> V_83 = V_34 ;
V_76 -> V_84 = * V_57 ;
V_76 -> V_85 = F_51 ( V_77 -> V_86 ) ;
}
static void F_52 ( struct V_75 * V_76 )
{
struct V_36 * V_37 = V_76 -> V_83 -> V_41 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_76 ) ;
}
static void
F_53 ( struct V_33 * V_34 ,
struct V_75 * V_76 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
F_54 ( F_46 ( V_81 , & V_76 -> V_82 ) ) ;
F_25 ( & V_76 -> V_78 ) ;
F_41 ( & V_34 -> V_35 ) ;
if ( F_24 ( & V_34 -> V_53 ) ) {
if ( F_55 ( & V_34 -> V_87 ) == 0 )
F_34 ( V_63 , & V_34 -> V_64 ) ;
F_56 ( V_88 , & V_34 -> V_64 ) ;
}
F_57 ( & F_22 ( V_36 ) -> V_89 ) ;
}
void
F_58 ( struct V_75 * V_76 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
if ( ! V_76 )
return;
F_3 ( L_21 , V_5 , V_76 ,
F_55 ( & V_76 -> V_80 ) ,
F_46 ( V_81 , & V_76 -> V_82 ) ) ;
V_34 = V_76 -> V_83 ;
V_36 = V_34 -> V_41 ;
if ( F_31 ( & V_76 -> V_80 , & V_36 -> V_52 ) ) {
if ( F_46 ( V_81 , & V_76 -> V_82 ) ) {
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
static void F_59 ( struct V_90 * V_91 )
{
struct V_75 * V_76 ;
struct V_33 * V_34 ;
V_76 = F_60 ( V_91 , struct V_75 , V_92 ) ;
V_34 = V_76 -> V_83 ;
F_52 ( V_76 ) ;
F_29 ( V_34 ) ;
}
static void F_61 ( struct V_75 * V_76 )
{
F_62 ( & V_76 -> V_92 , F_59 ) ;
F_63 ( & V_76 -> V_92 ) ;
}
void
F_64 ( struct V_75 * V_76 )
{
if ( ! V_76 )
return;
F_65 ( & V_76 -> V_83 -> V_41 -> V_52 ) ;
F_3 ( L_21 , V_5 , V_76 ,
F_55 ( & V_76 -> V_80 ) ,
F_46 ( V_81 , & V_76 -> V_82 ) ) ;
if ( F_9 ( & V_76 -> V_80 ) ) {
struct V_33 * V_34 = V_76 -> V_83 ;
if ( F_46 ( V_81 , & V_76 -> V_82 ) )
return;
F_20 ( V_34 ) ;
F_53 ( V_34 , V_76 ) ;
F_61 ( V_76 ) ;
}
}
static T_4
F_66 ( T_4 V_72 , T_4 V_93 )
{
T_4 V_73 ;
V_73 = V_72 + V_93 ;
return V_73 >= V_72 ? V_73 : V_62 ;
}
static bool
F_67 ( const struct V_56 * V_94 ,
const struct V_56 * V_95 )
{
T_4 V_96 = V_94 -> V_60 ;
T_4 V_97 = F_66 ( V_96 , V_94 -> V_61 ) ;
T_4 V_98 = V_95 -> V_60 ;
T_4 V_99 = F_66 ( V_98 , V_95 -> V_61 ) ;
return ( V_96 <= V_98 ) && ( V_97 >= V_99 ) ;
}
static bool
F_68 ( const struct V_56 * V_94 ,
const struct V_56 * V_95 )
{
T_4 V_96 = V_94 -> V_60 ;
T_4 V_97 = F_66 ( V_96 , V_94 -> V_61 ) ;
T_4 V_98 = V_95 -> V_60 ;
T_4 V_99 = F_66 ( V_98 , V_95 -> V_61 ) ;
return ( V_97 == V_62 || V_97 > V_98 ) &&
( V_99 == V_62 || V_99 > V_96 ) ;
}
static bool F_69 ( struct V_75 * V_76 ,
struct V_54 * V_100 )
{
if ( ! F_9 ( & V_76 -> V_80 ) )
return false ;
F_53 ( V_76 -> V_83 , V_76 ) ;
F_17 ( & V_76 -> V_78 , V_100 ) ;
return true ;
}
static int F_70 ( struct V_75 * V_76 ,
struct V_54 * V_100 )
{
int V_101 = 0 ;
if ( F_40 ( V_81 , & V_76 -> V_82 ) ) {
F_3 ( L_22 , V_5 , V_76 ,
F_55 ( & V_76 -> V_80 ) ) ;
if ( F_69 ( V_76 , V_100 ) )
V_101 = 1 ;
}
return V_101 ;
}
static bool F_71 ( T_1 V_102 , T_1 V_103 )
{
return ( V_104 ) ( V_102 - V_103 ) > 0 ;
}
static bool
F_72 ( const struct V_56 * V_105 ,
const struct V_56 * V_106 )
{
return ( V_106 -> V_58 == V_59 ||
V_105 -> V_58 == V_106 -> V_58 ) &&
F_68 ( V_105 , V_106 ) ;
}
static bool
F_73 ( const struct V_75 * V_76 ,
const struct V_56 * V_106 ,
T_1 V_107 )
{
if ( V_107 != 0 && F_71 ( V_76 -> V_85 , V_107 ) )
return false ;
if ( V_106 == NULL )
return true ;
return F_72 ( & V_76 -> V_84 , V_106 ) ;
}
int
F_35 ( struct V_33 * V_34 ,
struct V_54 * V_100 ,
const struct V_56 * V_106 ,
T_1 V_107 )
{
struct V_75 * V_76 , * V_108 ;
int V_109 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_74 (lseg, next, &lo->plh_segs, pls_list)
if ( F_73 ( V_76 , V_106 , V_107 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_76 , V_76 -> V_84 . V_58 , V_76 -> V_85 ,
V_76 -> V_84 . V_60 , V_76 -> V_84 . V_61 ) ;
if ( ! F_70 ( V_76 , V_100 ) )
V_109 ++ ;
}
F_3 ( L_26 , V_5 , V_109 ) ;
return V_109 ;
}
void
F_44 ( struct V_54 * V_110 )
{
struct V_75 * V_76 , * V_27 ;
if ( F_24 ( V_110 ) )
return;
F_74 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_76 -> V_78 ) ;
F_52 ( V_76 ) ;
}
}
void
F_75 ( struct V_47 * V_48 )
{
struct V_33 * V_34 ;
F_43 ( V_100 ) ;
F_5 ( & V_48 -> V_111 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
F_20 ( V_34 ) ;
F_33 ( V_34 , & V_100 ) ;
F_39 ( V_34 , V_67 ) ;
F_39 ( V_34 , V_66 ) ;
F_7 ( & V_48 -> V_111 . V_52 ) ;
F_44 ( & V_100 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_111 . V_52 ) ;
}
static bool
F_76 ( struct V_36 * V_36 ,
struct V_54 * V_112 )
{
struct V_33 * V_34 ;
bool V_113 = false ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 != NULL && F_24 ( & V_34 -> V_114 ) ) {
F_20 ( V_34 ) ;
F_17 ( & V_34 -> V_114 , V_112 ) ;
V_113 = true ;
}
F_7 ( & V_36 -> V_52 ) ;
return V_113 ;
}
static int
F_77 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_54 * V_112 )
{
struct V_33 * V_34 , * V_108 ;
struct V_36 * V_36 ;
F_74 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_78 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_76 ( V_36 , V_112 ) )
continue;
F_79 () ;
F_7 ( & V_43 -> V_44 ) ;
F_80 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_81 () ;
return - V_115 ;
}
return 0 ;
}
static int
F_82 ( struct V_54 * V_112 ,
bool V_116 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
F_43 ( V_55 ) ;
int V_113 = 0 ;
while ( ! F_24 ( V_112 ) ) {
V_34 = F_83 ( V_112 -> V_108 , struct V_33 ,
V_114 ) ;
F_3 ( L_27 , V_5 ,
V_34 -> V_41 -> V_117 ) ;
V_36 = V_34 -> V_41 ;
F_84 ( V_36 , false ) ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_114 ) ;
if ( F_33 ( V_34 , & V_55 ) ) {
if ( V_116 )
F_34 ( V_88 , & V_34 -> V_64 ) ;
V_113 = - V_115 ;
}
F_7 ( & V_36 -> V_52 ) ;
F_44 ( & V_55 ) ;
F_85 ( V_36 , 0 ) ;
F_29 ( V_34 ) ;
F_80 ( V_36 ) ;
}
return V_113 ;
}
int
F_86 ( struct V_12 * V_43 ,
struct V_118 * V_119 ,
bool V_120 )
{
struct V_8 * V_14 ;
F_43 ( V_112 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_81 () ;
V_121:
F_87 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_119 , V_119 , sizeof( * V_119 ) ) != 0 )
continue;
if ( F_77 ( V_43 ,
V_14 ,
& V_112 ) != 0 )
goto V_121;
}
F_79 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_112 ) )
return 0 ;
return F_82 ( & V_112 , V_120 ) ;
}
int
F_88 ( struct V_12 * V_43 ,
bool V_120 )
{
struct V_8 * V_14 ;
F_43 ( V_112 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_81 () ;
V_121:
F_87 (server, &clp->cl_superblocks, client_link) {
if ( F_77 ( V_43 ,
V_14 ,
& V_112 ) != 0 )
goto V_121;
}
F_79 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_112 ) )
return 0 ;
return F_82 ( & V_112 , V_120 ) ;
}
void
F_89 ( struct V_12 * V_43 )
{
F_90 ( V_43 ) ;
F_10 ( V_43 ) ;
F_88 ( V_43 , false ) ;
}
static void
F_91 ( struct V_33 * V_34 )
{
V_34 -> V_122 = 0 ;
V_34 -> V_123 = 0 ;
F_56 ( V_124 , & V_34 -> V_64 ) ;
}
void
F_92 ( struct V_33 * V_34 , const T_3 * V_125 ,
bool V_126 )
{
T_1 V_127 , V_128 , V_129 = 0 ;
V_127 = F_51 ( V_34 -> V_130 . V_86 ) ;
V_128 = F_51 ( V_125 -> V_86 ) ;
if ( ! F_93 ( V_34 ) ) {
F_94 ( & V_34 -> V_130 , V_125 ) ;
V_34 -> V_131 = V_128 ;
F_91 ( V_34 ) ;
F_56 ( V_63 , & V_34 -> V_64 ) ;
return;
}
if ( F_71 ( V_128 , V_127 ) ) {
F_94 ( & V_34 -> V_130 , V_125 ) ;
V_129 = V_128 - F_55 ( & V_34 -> V_87 ) ;
}
if ( V_126 )
V_129 = F_51 ( V_125 -> V_86 ) ;
else if ( V_129 == 0 )
return;
if ( F_71 ( V_129 , V_34 -> V_131 ) )
V_34 -> V_131 = V_129 ;
}
static bool
F_95 ( const struct V_33 * V_34 ,
const T_3 * V_77 )
{
T_1 V_86 = F_51 ( V_77 -> V_86 ) ;
return ! F_71 ( V_86 , V_34 -> V_131 ) ;
}
static bool
F_96 ( const struct V_33 * V_34 )
{
return V_34 -> V_132 ||
F_46 ( V_88 , & V_34 -> V_64 ) ;
}
static struct V_75 *
F_97 ( struct V_33 * V_34 ,
struct V_133 * V_134 ,
T_3 * V_77 ,
const struct V_56 * V_57 ,
long * V_135 , T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_136 * V_137 ;
T_5 V_138 ;
F_3 ( L_28 , V_5 ) ;
V_137 = F_98 ( sizeof( * V_137 ) , V_38 ) ;
if ( V_137 == NULL )
return F_99 ( - V_139 ) ;
V_138 = F_100 ( V_37 ) ;
V_137 -> args . V_140 = V_141 ;
if ( V_137 -> args . V_140 > V_57 -> V_61 )
V_137 -> args . V_140 = V_57 -> V_61 ;
if ( V_57 -> V_58 == V_142 ) {
if ( V_57 -> V_60 >= V_138 )
V_137 -> args . V_140 = 0 ;
else if ( V_138 - V_57 -> V_60 < V_137 -> args . V_140 )
V_137 -> args . V_140 = V_138 - V_57 -> V_60 ;
}
V_137 -> args . V_143 = V_144 ;
F_101 ( & V_137 -> args . V_57 , V_57 ) ;
V_137 -> args . type = V_14 -> V_10 -> V_2 ;
V_137 -> args . V_36 = V_37 ;
V_137 -> args . V_134 = F_102 ( V_134 ) ;
F_94 ( & V_137 -> args . V_77 , V_77 ) ;
V_137 -> V_38 = V_38 ;
V_137 -> V_145 = V_34 -> V_45 ;
return F_103 ( V_137 , V_135 , V_38 ) ;
}
static void F_104 ( struct V_36 * V_36 ,
struct V_54 * V_71 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_75 * V_76 , * V_27 ;
if ( ! F_40 ( V_146 , & V_48 -> V_147 ) )
return;
F_74 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_40 ( V_148 , & V_76 -> V_82 ) )
continue;
F_69 ( V_76 , V_71 ) ;
}
}
void F_105 ( struct V_33 * V_34 )
{
F_106 ( V_149 , & V_34 -> V_64 ) ;
F_107 () ;
F_108 ( & V_34 -> V_64 , V_149 ) ;
F_57 ( & F_22 ( V_34 -> V_41 ) -> V_89 ) ;
}
static bool
F_109 ( struct V_33 * V_34 ,
T_3 * V_77 ,
enum V_150 * V_58 )
{
if ( F_55 ( & V_34 -> V_87 ) != 0 )
return false ;
if ( F_38 ( V_149 , & V_34 -> V_64 ) )
return false ;
F_20 ( V_34 ) ;
if ( F_46 ( V_124 , & V_34 -> V_64 ) ) {
if ( V_77 != NULL ) {
F_94 ( V_77 , & V_34 -> V_130 ) ;
if ( V_34 -> V_123 != 0 )
V_77 -> V_86 = F_110 ( V_34 -> V_123 ) ;
}
if ( V_58 != NULL )
* V_58 = V_34 -> V_122 ;
F_91 ( V_34 ) ;
return true ;
}
if ( V_77 != NULL )
F_94 ( V_77 , & V_34 -> V_130 ) ;
if ( V_58 != NULL )
* V_58 = V_59 ;
return true ;
}
static int
F_111 ( struct V_33 * V_34 , const T_3 * V_77 ,
enum V_150 V_58 , bool V_151 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_152 * V_153 ;
int V_25 = 0 ;
V_153 = F_98 ( sizeof( * V_153 ) , V_154 ) ;
if ( F_112 ( V_153 == NULL ) ) {
V_25 = - V_139 ;
F_5 ( & V_37 -> V_52 ) ;
F_105 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
F_94 ( & V_153 -> args . V_77 , V_77 ) ;
V_153 -> args . V_155 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_153 -> args . V_36 = V_37 ;
V_153 -> args . V_57 . V_58 = V_58 ;
V_153 -> args . V_57 . V_60 = 0 ;
V_153 -> args . V_57 . V_61 = V_62 ;
V_153 -> args . V_49 = V_34 ;
V_153 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_153 -> V_145 = V_34 -> V_45 ;
V_25 = F_113 ( V_153 , V_151 ) ;
V_4:
F_3 ( L_29 , V_5 , V_25 ) ;
return V_25 ;
}
static bool
F_114 ( struct V_33 * V_34 )
{
struct V_75 * V_156 ;
if ( ! F_46 ( V_124 , & V_34 -> V_64 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list) {
if ( F_46 ( V_157 , & V_156 -> V_82 ) )
return false ;
}
return true ;
}
static void F_30 ( struct V_33 * V_34 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
if ( ! F_46 ( V_124 , & V_34 -> V_64 ) )
return;
F_5 ( & V_36 -> V_52 ) ;
if ( F_114 ( V_34 ) ) {
T_3 V_77 ;
enum V_150 V_58 ;
bool V_158 ;
V_158 = F_109 ( V_34 , & V_77 , & V_58 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_158 ) {
F_111 ( V_34 , & V_77 , V_58 , false ) ;
}
} else
F_7 ( & V_36 -> V_52 ) ;
}
int
F_115 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_43 ( V_100 ) ;
T_3 V_77 ;
int V_25 = 0 , V_159 ;
bool V_158 ;
F_3 ( L_30 , V_5 , V_37 -> V_117 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
F_20 ( V_34 ) ;
V_159 = F_24 ( & V_34 -> V_53 ) ;
F_104 ( V_37 , & V_100 ) ;
F_35 ( V_34 , & V_100 , NULL , 0 ) ;
if ( F_22 ( V_37 ) -> V_10 -> V_160 ) {
struct V_56 V_57 = {
. V_58 = V_59 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_22 ( V_37 ) -> V_10 -> V_160 ( V_34 , & V_57 ) ;
}
if ( V_159 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_161;
}
V_158 = F_109 ( V_34 , & V_77 , NULL ) ;
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_100 ) ;
if ( V_158 )
V_25 = F_111 ( V_34 , & V_77 , V_59 , true ) ;
V_161:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_29 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_116 ( struct V_36 * V_36 )
{
struct V_33 * V_34 ;
int V_113 ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 == NULL ) {
F_7 ( & V_36 -> V_52 ) ;
return 0 ;
}
F_20 ( V_34 ) ;
V_34 -> V_132 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_117 ( V_36 -> V_162 ) ;
V_113 = F_84 ( V_36 , true ) ;
if ( V_113 == 0 )
V_113 = F_115 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_132 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_113 ;
}
bool F_118 ( struct V_36 * V_37 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_133 * V_134 ;
struct V_163 * V_164 ;
struct V_33 * V_34 ;
struct V_75 * V_76 , * V_27 ;
T_3 V_77 ;
F_43 ( V_100 ) ;
bool V_165 = false , V_166 = false , V_167 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 || F_46 ( V_88 , & V_34 -> V_64 ) )
goto V_168;
if ( F_119 ( V_37 , V_169 ) )
goto V_168;
F_2 (ctx, &nfsi->open_files, list) {
V_164 = V_134 -> V_164 ;
if ( V_164 != NULL && V_164 -> V_164 != 0 )
goto V_168;
}
if ( F_46 ( V_124 , & V_34 -> V_64 ) )
V_166 = F_109 ( V_34 ,
& V_77 , NULL ) ;
F_74 (lseg, tmp, &lo->plh_segs, pls_list)
if ( V_166 || F_46 ( V_170 , & V_76 -> V_82 ) ) {
F_70 ( V_76 , & V_100 ) ;
V_165 = true ;
}
if ( V_165 && ! V_166 ) {
F_20 ( V_34 ) ;
V_167 = true ;
}
V_168:
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_100 ) ;
F_84 ( V_37 , true ) ;
if ( V_166 )
F_111 ( V_34 , & V_77 , V_59 , true ) ;
return V_167 ;
}
void F_120 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
F_105 ( V_34 ) ;
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
if ( F_71 ( V_171 , V_34 -> V_131 ) )
V_34 -> V_131 = V_171 ;
F_7 ( & V_37 -> V_52 ) ;
F_122 ( V_37 , 0 ) ;
}
void F_123 ( struct V_36 * V_37 , T_1 * V_171 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
T_1 V_172 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
V_172 = F_51 ( V_34 -> V_130 . V_86 ) ;
* V_171 = V_172 + F_55 ( & V_34 -> V_87 ) ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_124 ( struct V_36 * V_37 , struct V_173 * V_174 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
bool V_175 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 && F_46 ( V_149 , & V_34 -> V_64 ) )
V_175 = true ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_175 )
F_125 ( & F_22 ( V_37 ) -> V_89 , V_174 , NULL ) ;
return V_175 ;
}
static T_6
F_126 ( const struct V_56 * V_94 ,
const struct V_56 * V_95 )
{
T_6 V_176 ;
V_176 = V_94 -> V_60 - V_95 -> V_60 ;
if ( V_176 )
return V_176 ;
V_176 = V_95 -> V_61 - V_94 -> V_61 ;
if ( V_176 )
return V_176 ;
return ( int ) ( V_94 -> V_58 == V_142 ) - ( int ) ( V_95 -> V_58 == V_142 ) ;
}
static bool
F_127 ( const struct V_56 * V_94 ,
const struct V_56 * V_95 )
{
return F_126 ( V_94 , V_95 ) > 0 ;
}
static bool
F_128 ( struct V_75 * V_76 ,
struct V_75 * V_177 )
{
return false ;
}
void
F_129 ( struct V_33 * V_34 ,
struct V_75 * V_76 ,
bool (* F_130)( const struct V_56 * ,
const struct V_56 * ) ,
bool (* F_131)( struct V_75 * ,
struct V_75 * ) ,
struct V_54 * V_110 )
{
struct V_75 * V_178 , * V_27 ;
F_3 ( L_33 , V_5 ) ;
F_74 (lp, tmp, &lo->plh_segs, pls_list) {
if ( F_46 ( V_81 , & V_178 -> V_82 ) == 0 )
continue;
if ( F_131 ( V_76 , V_178 ) ) {
F_70 ( V_178 , V_110 ) ;
continue;
}
if ( F_130 ( & V_76 -> V_84 , & V_178 -> V_84 ) )
continue;
F_132 ( & V_76 -> V_78 , & V_178 -> V_78 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_76 , V_76 -> V_84 . V_58 ,
V_76 -> V_84 . V_60 , V_76 -> V_84 . V_61 ,
V_178 , V_178 -> V_84 . V_58 , V_178 -> V_84 . V_60 ,
V_178 -> V_84 . V_61 ) ;
goto V_4;
}
F_132 ( & V_76 -> V_78 , & V_34 -> V_53 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_76 , V_76 -> V_84 . V_58 ,
V_76 -> V_84 . V_60 , V_76 -> V_84 . V_61 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_38 , V_5 ) ;
}
static void
F_133 ( struct V_33 * V_34 ,
struct V_75 * V_76 ,
struct V_54 * V_110 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
if ( V_39 -> V_179 != NULL )
V_39 -> V_179 ( V_34 , V_76 , V_110 ) ;
else
F_129 ( V_34 , V_76 ,
F_127 ,
F_128 ,
V_110 ) ;
}
static struct V_33 *
F_134 ( struct V_36 * V_37 ,
struct V_133 * V_134 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_50 ( & V_34 -> V_35 , 1 ) ;
F_49 ( & V_34 -> V_42 ) ;
F_49 ( & V_34 -> V_53 ) ;
F_49 ( & V_34 -> V_114 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_135 ( V_134 -> V_145 ) ;
V_34 -> V_64 |= 1 << V_63 ;
return V_34 ;
}
static struct V_33 *
F_136 ( struct V_36 * V_37 ,
struct V_133 * V_134 ,
T_2 V_38 )
__releases( &ino->i_lock
static bool
F_137 ( const struct V_56 * V_180 ,
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
F_138 ( struct V_33 * V_34 ,
struct V_56 * V_57 ,
bool V_181 )
{
struct V_75 * V_76 , * V_113 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_46 ( V_81 , & V_76 -> V_82 ) &&
! F_46 ( V_157 , & V_76 -> V_82 ) &&
F_137 ( & V_76 -> V_84 , V_57 ,
V_181 ) ) {
V_113 = F_139 ( V_76 ) ;
break;
}
}
F_3 ( L_39 ,
V_5 , V_113 , V_113 ? F_55 ( & V_113 -> V_80 ) : 0 ) ;
return V_113 ;
}
static bool F_140 ( struct V_133 * V_134 ,
struct V_36 * V_37 , int V_58 )
{
struct V_183 * V_184 = V_134 -> V_185 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_5 V_186 = F_100 ( V_37 ) ;
bool V_187 = false , V_188 = false , V_189 = false , V_190 = false , V_113 = false ;
if ( V_184 == NULL )
return V_113 ;
F_3 ( L_40 ,
V_5 , V_184 -> V_191 , V_184 -> V_192 , V_184 -> V_193 , V_184 -> V_194 , V_184 -> V_195 ) ;
switch ( V_58 ) {
case V_142 :
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
V_113 = true ;
} else if ( V_187 || V_189 )
V_113 = true ;
F_3 ( L_44 , V_5 , V_187 , V_189 , V_113 ) ;
return V_113 ;
}
static bool F_141 ( struct V_33 * V_34 )
{
F_84 ( V_34 -> V_41 , false ) ;
return ! F_142 ( & V_34 -> V_64 , V_149 ,
V_200 ,
V_201 ) ;
}
static void F_143 ( struct V_33 * V_34 )
{
unsigned long * V_202 = & V_34 -> V_64 ;
F_106 ( V_203 , V_202 ) ;
F_107 () ;
F_108 ( V_202 , V_203 ) ;
}
struct V_75 *
F_144 ( struct V_36 * V_37 ,
struct V_133 * V_134 ,
T_5 V_204 ,
T_4 V_205 ,
enum V_150 V_58 ,
bool V_181 ,
T_2 V_38 )
{
struct V_56 V_206 = {
. V_58 = V_58 ,
. V_60 = V_204 ,
. V_61 = V_205 ,
} ;
unsigned V_207 , V_107 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 = NULL ;
struct V_75 * V_76 = NULL ;
T_3 V_77 ;
long V_135 = 0 ;
unsigned long V_208 = V_70 + ( V_43 -> V_209 << 1 ) ;
bool V_210 ;
if ( ! F_145 ( F_22 ( V_37 ) ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_211 ) ;
goto V_4;
}
if ( V_58 == V_142 && F_100 ( V_37 ) == 0 ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_212 ) ;
goto V_4;
}
if ( F_140 ( V_134 , V_37 , V_58 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_213 ) ;
goto V_4;
}
V_214:
F_147 ( V_43 ) ;
V_210 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_136 ( V_37 , V_134 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_215 ) ;
goto V_4;
}
if ( F_46 ( V_88 , & V_34 -> V_64 ) ) {
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
V_76 = F_138 ( V_34 , & V_206 , V_181 ) ;
if ( V_76 ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_219 ) ;
goto V_217;
}
if ( ! F_148 ( V_134 -> V_164 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_220 ) ;
goto V_217;
}
if ( F_46 ( V_63 , & V_34 -> V_64 ) ) {
if ( F_38 ( V_203 ,
& V_34 -> V_64 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_149 ( & V_34 -> V_64 , V_203 ,
V_201 ) ;
F_29 ( V_34 ) ;
F_3 ( L_46 , V_5 ) ;
goto V_214;
}
V_210 = true ;
do {
V_107 = F_150 ( & V_134 -> V_164 -> V_221 ) ;
F_94 ( & V_77 , & V_134 -> V_164 -> V_77 ) ;
} while ( F_151 ( & V_134 -> V_164 -> V_221 , V_107 ) );
} else {
F_94 ( & V_77 , & V_34 -> V_130 ) ;
}
if ( F_46 ( V_149 , & V_34 -> V_64 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_47 , V_5 ) ;
if ( F_141 ( V_34 ) ) {
if ( V_210 )
F_143 ( V_34 ) ;
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
if ( F_96 ( V_34 ) ) {
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_224 ) ;
goto V_217;
}
F_15 ( & V_34 -> V_87 ) ;
F_7 ( & V_37 -> V_52 ) ;
if ( F_24 ( & V_34 -> V_42 ) ) {
F_5 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_34 -> V_42 ) )
F_132 ( & V_34 -> V_42 , & V_14 -> V_225 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_207 = V_206 . V_60 & ~ V_226 ;
if ( V_207 ) {
V_206 . V_60 -= V_207 ;
V_206 . V_61 += V_207 ;
}
if ( V_206 . V_61 != V_62 )
V_206 . V_61 = F_152 ( V_206 . V_61 ) ;
V_76 = F_97 ( V_34 , V_134 , & V_77 , & V_206 , & V_135 , V_38 ) ;
F_146 ( V_37 , V_204 , V_205 , V_58 , V_34 , V_76 ,
V_227 ) ;
F_41 ( & V_34 -> V_87 ) ;
if ( F_153 ( V_76 ) ) {
switch( F_154 ( V_76 ) ) {
case - V_228 :
if ( F_155 ( V_70 , V_208 ) )
V_76 = NULL ;
break;
case - V_229 :
if ( V_210 ) {
V_76 = NULL ;
break;
}
if ( F_155 ( V_70 , V_208 ) )
F_75 ( F_28 ( V_37 ) ) ;
case - V_115 :
break;
default:
if ( ! F_156 ( F_154 ( V_76 ) ) ) {
F_39 ( V_34 , F_36 ( V_58 ) ) ;
V_76 = NULL ;
}
goto V_161;
}
if ( V_76 ) {
if ( V_210 )
F_143 ( V_34 ) ;
F_146 ( V_37 , V_204 , V_205 ,
V_58 , V_34 , V_76 , V_222 ) ;
F_29 ( V_34 ) ;
goto V_214;
}
} else {
F_39 ( V_34 , F_36 ( V_58 ) ) ;
}
V_161:
if ( V_210 )
F_143 ( V_34 ) ;
F_29 ( V_34 ) ;
V_4:
F_3 ( L_48
L_49 ,
V_5 , V_37 -> V_230 -> V_231 ,
( unsigned long long ) F_157 ( V_37 ) ,
F_158 ( V_76 ) ? L_50 : L_51 ,
V_58 == V_65 ? L_52 : L_53 ,
( unsigned long long ) V_204 ,
( unsigned long long ) V_205 ) ;
return V_76 ;
V_217:
F_7 ( & V_37 -> V_52 ) ;
goto V_161;
}
static bool
F_159 ( struct V_56 * V_57 )
{
switch ( V_57 -> V_58 ) {
case V_142 :
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
F_160 ( struct V_136 * V_137 )
{
struct V_33 * V_34 = F_28 ( V_137 -> args . V_36 ) -> V_49 ;
struct V_232 * V_233 = & V_137 -> V_233 ;
struct V_75 * V_76 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_43 ( V_110 ) ;
if ( ! F_159 ( & V_233 -> V_57 ) )
return F_99 ( - V_26 ) ;
V_76 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_233 , V_137 -> V_38 ) ;
if ( F_158 ( V_76 ) ) {
if ( ! V_76 )
V_76 = F_99 ( - V_139 ) ;
F_3 ( L_54 ,
V_5 , F_154 ( V_76 ) ) ;
return V_76 ;
}
F_48 ( V_34 , V_76 , & V_233 -> V_57 , & V_233 -> V_77 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_96 ( V_34 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_234;
}
if ( F_161 ( & V_34 -> V_130 , & V_233 -> V_77 ) ) {
if ( F_95 ( V_34 , & V_233 -> V_77 ) ) {
F_3 ( L_56 , V_5 ) ;
goto V_234;
}
F_92 ( V_34 , & V_233 -> V_77 , false ) ;
} else {
F_33 ( V_34 , & V_110 ) ;
F_92 ( V_34 , & V_233 -> V_77 , true ) ;
}
F_139 ( V_76 ) ;
F_133 ( V_34 , V_76 , & V_110 ) ;
if ( V_233 -> V_235 )
F_34 ( V_170 , & V_76 -> V_82 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_110 ) ;
return V_76 ;
V_234:
F_7 ( & V_37 -> V_52 ) ;
V_76 -> V_83 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_76 ) ;
return F_99 ( - V_115 ) ;
}
static void
F_162 ( struct V_33 * V_34 , enum V_150 V_58 ,
T_1 V_107 )
{
if ( V_34 -> V_122 != 0 && V_34 -> V_122 != V_58 )
V_58 = V_59 ;
V_34 -> V_122 = V_58 ;
F_34 ( V_124 , & V_34 -> V_64 ) ;
if ( V_107 != 0 ) {
F_163 ( V_34 -> V_123 != 0 && V_34 -> V_123 != V_107 ) ;
V_34 -> V_123 = V_107 ;
}
}
int
F_164 ( struct V_33 * V_34 ,
struct V_54 * V_100 ,
const struct V_56 * V_160 ,
T_1 V_107 )
{
struct V_75 * V_76 , * V_108 ;
int V_109 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_65 ( & V_34 -> V_41 -> V_52 ) ;
F_74 (lseg, next, &lo->plh_segs, pls_list)
if ( F_73 ( V_76 , V_160 , V_107 ) ) {
F_3 ( L_57
L_25 , V_5 ,
V_76 , V_76 -> V_84 . V_58 ,
V_76 -> V_84 . V_60 ,
V_76 -> V_84 . V_61 ) ;
if ( F_70 ( V_76 , V_100 ) )
continue;
V_109 ++ ;
F_34 ( V_157 , & V_76 -> V_82 ) ;
}
if ( V_109 )
F_162 ( V_34 , V_160 -> V_58 , V_107 ) ;
return V_109 ;
}
void F_165 ( struct V_36 * V_36 ,
struct V_75 * V_76 )
{
struct V_33 * V_34 = F_28 ( V_36 ) -> V_49 ;
struct V_56 V_57 = {
. V_58 = V_76 -> V_84 . V_58 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_43 ( V_110 ) ;
bool V_236 = false ;
F_5 ( & V_36 -> V_52 ) ;
F_162 ( V_34 , V_57 . V_58 , 0 ) ;
if ( ! F_164 ( V_34 , & V_110 , & V_57 , 0 ) ) {
T_3 V_77 ;
enum V_150 V_58 ;
V_236 = F_109 ( V_34 , & V_77 , & V_58 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_236 )
F_111 ( V_34 , & V_77 , V_58 , false ) ;
} else {
F_7 ( & V_36 -> V_52 ) ;
F_85 ( V_36 , 0 ) ;
}
F_44 ( & V_110 ) ;
}
void
F_166 ( struct V_237 * V_238 , struct V_239 * V_240 )
{
T_4 V_241 = V_240 -> V_242 ;
if ( V_238 -> V_243 == NULL ) {
if ( V_238 -> V_244 == NULL )
V_241 = F_100 ( V_238 -> V_245 ) - F_167 ( V_240 ) ;
else
V_241 = F_168 ( V_238 -> V_244 ) ;
V_238 -> V_243 = F_144 ( V_238 -> V_245 ,
V_240 -> V_246 ,
F_167 ( V_240 ) ,
V_241 ,
V_142 ,
false ,
V_247 ) ;
if ( F_153 ( V_238 -> V_243 ) ) {
V_238 -> V_248 = F_154 ( V_238 -> V_243 ) ;
V_238 -> V_243 = NULL ;
return;
}
}
if ( V_238 -> V_243 == NULL )
F_169 ( V_238 ) ;
}
void
F_170 ( struct V_237 * V_238 ,
struct V_239 * V_240 , T_4 V_249 )
{
if ( V_238 -> V_243 == NULL ) {
V_238 -> V_243 = F_144 ( V_238 -> V_245 ,
V_240 -> V_246 ,
F_167 ( V_240 ) ,
V_249 ,
V_65 ,
false ,
V_154 ) ;
if ( F_153 ( V_238 -> V_243 ) ) {
V_238 -> V_248 = F_154 ( V_238 -> V_243 ) ;
V_238 -> V_243 = NULL ;
return;
}
}
if ( V_238 -> V_243 == NULL )
F_171 ( V_238 ) ;
}
void
F_172 ( struct V_237 * V_250 )
{
if ( V_250 -> V_243 ) {
F_58 ( V_250 -> V_243 ) ;
V_250 -> V_243 = NULL ;
}
}
T_7
F_173 ( struct V_237 * V_238 ,
struct V_239 * V_251 , struct V_239 * V_240 )
{
unsigned int V_187 ;
T_4 V_252 , V_253 , V_254 ;
V_187 = F_174 ( V_238 , V_251 , V_240 ) ;
if ( ! V_187 )
return 0 ;
if ( V_238 -> V_243 ) {
V_252 = F_66 ( V_238 -> V_243 -> V_84 . V_60 ,
V_238 -> V_243 -> V_84 . V_61 ) ;
V_253 = F_167 ( V_240 ) ;
F_163 ( V_253 >= V_252 ) ;
if ( V_253 >= V_252 ) {
if ( V_238 -> V_255 -> V_256 )
V_238 -> V_255 -> V_256 ( V_238 ) ;
if ( V_238 -> V_255 -> V_257 )
V_238 -> V_255 -> V_257 ( V_238 , V_240 ) ;
return 0 ;
}
V_254 = V_252 - V_253 ;
if ( V_254 < V_187 )
V_187 = ( unsigned int ) V_254 ;
}
return V_187 ;
}
int F_175 ( struct V_258 * V_259 )
{
struct V_237 V_238 ;
F_176 ( & V_238 , V_259 -> V_36 , V_260 , true ,
V_259 -> V_261 ) ;
F_34 ( V_262 , & V_259 -> args . V_263 -> V_147 ) ;
return F_177 ( & V_238 , V_259 ) ;
}
static void F_178 ( struct V_258 * V_259 )
{
F_3 ( L_58 , V_259 -> V_264 ) ;
if ( F_22 ( V_259 -> V_36 ) -> V_10 -> V_147 &
V_265 ) {
F_179 ( V_259 -> V_36 ) ;
}
if ( ! F_38 ( V_266 , & V_259 -> V_147 ) )
V_259 -> V_174 . V_267 = F_175 ( V_259 ) ;
}
void F_180 ( struct V_258 * V_259 )
{
if ( F_181 ( ! V_259 -> V_264 ) ) {
F_182 ( V_259 -> V_36 , V_259 -> V_76 ,
V_259 -> V_268 + V_259 -> V_233 . V_205 ) ;
V_259 -> V_269 -> V_270 ( & V_259 -> V_174 , V_259 ) ;
}
F_183 ( V_259 , V_259 -> V_264 ) ;
if ( F_112 ( V_259 -> V_264 ) )
F_178 ( V_259 ) ;
V_259 -> V_269 -> V_271 ( V_259 ) ;
}
static void
F_184 ( struct V_237 * V_250 ,
struct V_258 * V_259 )
{
struct V_272 * V_273 = F_185 ( V_250 ) ;
if ( ! F_38 ( V_266 , & V_259 -> V_147 ) ) {
F_186 ( & V_259 -> V_274 , & V_273 -> V_275 ) ;
F_171 ( V_250 ) ;
V_273 -> V_276 = 1 ;
}
F_187 ( V_259 ) ;
V_259 -> V_277 ( V_259 ) ;
}
static enum V_278
F_188 ( struct V_258 * V_259 ,
const struct V_279 * V_280 ,
struct V_75 * V_76 ,
int V_281 )
{
struct V_36 * V_36 = V_259 -> V_36 ;
enum V_278 V_282 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_259 -> V_269 = V_280 ;
F_3 ( L_59 , V_5 ,
V_36 -> V_117 , V_259 -> args . V_205 , V_259 -> args . V_60 , V_281 ) ;
V_282 = V_9 -> V_10 -> V_283 ( V_259 , V_281 ) ;
if ( V_282 != V_284 )
F_189 ( V_36 , V_285 ) ;
F_3 ( L_60 , V_5 , V_282 ) ;
return V_282 ;
}
static void
F_190 ( struct V_237 * V_250 ,
struct V_258 * V_259 , int V_281 )
{
const struct V_279 * V_280 = V_250 -> V_286 ;
struct V_75 * V_76 = V_250 -> V_243 ;
enum V_278 V_282 ;
V_282 = F_188 ( V_259 , V_280 , V_76 , V_281 ) ;
if ( V_282 == V_284 )
F_184 ( V_250 , V_259 ) ;
}
static void F_191 ( struct V_258 * V_259 )
{
F_58 ( V_259 -> V_76 ) ;
F_192 ( V_259 ) ;
}
int
F_193 ( struct V_237 * V_250 )
{
struct V_258 * V_259 ;
int V_113 ;
V_259 = F_194 ( V_250 -> V_287 ) ;
if ( ! V_259 ) {
V_250 -> V_248 = - V_139 ;
return V_250 -> V_248 ;
}
F_195 ( V_250 , V_259 , F_191 ) ;
V_259 -> V_76 = F_139 ( V_250 -> V_243 ) ;
V_113 = F_196 ( V_250 , V_259 ) ;
if ( ! V_113 )
F_190 ( V_250 , V_259 , V_250 -> V_288 ) ;
return V_113 ;
}
int F_197 ( struct V_258 * V_259 )
{
struct V_237 V_238 ;
F_198 ( & V_238 , V_259 -> V_36 , true , V_259 -> V_261 ) ;
return F_177 ( & V_238 , V_259 ) ;
}
static void F_199 ( struct V_258 * V_259 )
{
F_3 ( L_61 , V_259 -> V_264 ) ;
if ( F_22 ( V_259 -> V_36 ) -> V_10 -> V_147 &
V_265 ) {
F_179 ( V_259 -> V_36 ) ;
}
if ( ! F_38 ( V_266 , & V_259 -> V_147 ) )
V_259 -> V_174 . V_267 = F_197 ( V_259 ) ;
}
void F_200 ( struct V_258 * V_259 )
{
if ( F_181 ( ! V_259 -> V_264 ) ) {
F_201 ( V_259 ) ;
V_259 -> V_269 -> V_270 ( & V_259 -> V_174 , V_259 ) ;
}
F_202 ( V_259 , V_259 -> V_264 ) ;
if ( F_112 ( V_259 -> V_264 ) )
F_199 ( V_259 ) ;
V_259 -> V_269 -> V_271 ( V_259 ) ;
}
static void
F_203 ( struct V_237 * V_250 ,
struct V_258 * V_259 )
{
struct V_272 * V_273 = F_185 ( V_250 ) ;
if ( ! F_38 ( V_266 , & V_259 -> V_147 ) ) {
F_186 ( & V_259 -> V_274 , & V_273 -> V_275 ) ;
F_169 ( V_250 ) ;
V_273 -> V_276 = 1 ;
}
F_187 ( V_259 ) ;
V_259 -> V_277 ( V_259 ) ;
}
static enum V_278
F_204 ( struct V_258 * V_259 ,
const struct V_279 * V_280 ,
struct V_75 * V_76 )
{
struct V_36 * V_36 = V_259 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_278 V_282 ;
V_259 -> V_269 = V_280 ;
F_3 ( L_62 ,
V_5 , V_36 -> V_117 , V_259 -> args . V_205 , V_259 -> args . V_60 ) ;
V_282 = V_9 -> V_10 -> V_289 ( V_259 ) ;
if ( V_282 != V_284 )
F_189 ( V_36 , V_290 ) ;
F_3 ( L_60 , V_5 , V_282 ) ;
return V_282 ;
}
void F_205 ( struct V_258 * V_259 )
{
struct V_237 V_238 ;
if ( ! F_38 ( V_266 , & V_259 -> V_147 ) ) {
F_198 ( & V_238 , V_259 -> V_36 , false ,
V_259 -> V_261 ) ;
V_259 -> V_174 . V_267 = F_177 ( & V_238 , V_259 ) ;
}
}
static void
F_206 ( struct V_237 * V_250 , struct V_258 * V_259 )
{
const struct V_279 * V_280 = V_250 -> V_286 ;
struct V_75 * V_76 = V_250 -> V_243 ;
enum V_278 V_282 ;
V_282 = F_204 ( V_259 , V_280 , V_76 ) ;
if ( V_282 == V_291 )
F_205 ( V_259 ) ;
if ( V_282 == V_284 || V_259 -> V_174 . V_267 )
F_203 ( V_250 , V_259 ) ;
}
static void F_207 ( struct V_258 * V_259 )
{
F_58 ( V_259 -> V_76 ) ;
F_192 ( V_259 ) ;
}
int
F_208 ( struct V_237 * V_250 )
{
struct V_258 * V_259 ;
int V_113 ;
V_259 = F_194 ( V_250 -> V_287 ) ;
if ( ! V_259 ) {
V_250 -> V_248 = - V_139 ;
return V_250 -> V_248 ;
}
F_195 ( V_250 , V_259 , F_207 ) ;
V_259 -> V_76 = F_139 ( V_250 -> V_243 ) ;
V_113 = F_196 ( V_250 , V_259 ) ;
if ( ! V_113 )
F_206 ( V_250 , V_259 ) ;
return V_113 ;
}
static void F_209 ( struct V_36 * V_36 )
{
unsigned long * V_202 = & F_28 ( V_36 ) -> V_147 ;
F_106 ( V_292 , V_202 ) ;
F_107 () ;
F_108 ( V_202 , V_292 ) ;
}
static void F_210 ( struct V_36 * V_36 , struct V_54 * V_293 )
{
struct V_75 * V_76 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_76 -> V_84 . V_58 == V_65 &&
F_40 ( V_148 , & V_76 -> V_82 ) )
F_17 ( & V_76 -> V_79 , V_293 ) ;
}
}
static void F_211 ( struct V_36 * V_36 , struct V_54 * V_293 )
{
struct V_75 * V_76 , * V_27 ;
F_74 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_76 -> V_79 ) ;
F_58 ( V_76 ) ;
}
F_209 ( V_36 ) ;
}
void F_212 ( struct V_75 * V_76 )
{
F_42 ( V_76 -> V_83 , V_76 -> V_84 . V_58 ) ;
}
void
F_182 ( struct V_36 * V_36 , struct V_75 * V_76 ,
T_5 V_294 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
bool V_295 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_38 ( V_146 , & V_48 -> V_147 ) ) {
V_48 -> V_49 -> V_296 = V_294 ;
V_295 = true ;
F_3 ( L_63 ,
V_5 , V_36 -> V_117 ) ;
} else if ( V_294 > V_48 -> V_49 -> V_296 )
V_48 -> V_49 -> V_296 = V_294 ;
if ( ! F_38 ( V_148 , & V_76 -> V_82 ) ) {
F_139 ( V_76 ) ;
}
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_64 ,
V_5 , V_76 , V_48 -> V_49 -> V_296 ) ;
if ( V_295 )
F_213 ( V_36 ) ;
}
void F_214 ( struct V_297 * V_298 )
{
struct V_8 * V_9 = F_22 ( V_298 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_299 )
V_9 -> V_10 -> V_299 ( V_298 ) ;
F_211 ( V_298 -> args . V_36 , & V_298 -> V_55 ) ;
}
int
F_84 ( struct V_36 * V_36 , bool V_151 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_297 * V_298 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_5 V_294 ;
int V_25 ;
if ( ! F_215 ( V_36 ) )
return 0 ;
F_3 ( L_65 , V_5 , V_36 -> V_117 ) ;
V_25 = - V_115 ;
if ( F_38 ( V_292 , & V_48 -> V_147 ) ) {
if ( ! V_151 )
goto V_4;
V_25 = F_216 ( & V_48 -> V_147 ,
V_292 ,
V_200 ,
V_300 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_139 ;
V_298 = F_98 ( sizeof( * V_298 ) , V_154 ) ;
if ( ! V_298 )
goto V_301;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_40 ( V_146 , & V_48 -> V_147 ) )
goto V_217;
F_49 ( & V_298 -> V_55 ) ;
F_210 ( V_36 , & V_298 -> V_55 ) ;
V_294 = V_48 -> V_49 -> V_296 ;
F_94 ( & V_298 -> args . V_77 , & V_48 -> V_49 -> V_130 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_298 -> args . V_36 = V_36 ;
V_298 -> V_145 = F_135 ( V_48 -> V_49 -> V_45 ) ;
F_217 ( & V_298 -> V_302 ) ;
V_298 -> args . V_303 = F_22 ( V_36 ) -> V_304 ;
V_298 -> V_233 . V_302 = & V_298 -> V_302 ;
if ( V_294 != 0 )
V_298 -> args . V_305 = V_294 - 1 ;
else
V_298 -> args . V_305 = V_306 ;
V_298 -> V_233 . V_14 = F_22 ( V_36 ) ;
if ( V_39 -> V_307 ) {
V_25 = V_39 -> V_307 ( & V_298 -> args ) ;
if ( V_25 ) {
F_26 ( V_298 -> V_145 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_34 ( V_146 , & V_48 -> V_147 ) ;
if ( V_294 > V_48 -> V_49 -> V_296 )
V_48 -> V_49 -> V_296 = V_294 ;
goto V_217;
}
}
V_25 = F_218 ( V_298 , V_151 ) ;
V_4:
if ( V_25 )
F_213 ( V_36 ) ;
F_3 ( L_66 , V_5 , V_25 ) ;
return V_25 ;
V_217:
F_7 ( & V_36 -> V_52 ) ;
F_219 ( V_298 ) ;
V_301:
F_209 ( V_36 ) ;
goto V_4;
}
int
F_220 ( struct V_36 * V_36 , bool V_308 )
{
return F_84 ( V_36 , true ) ;
}
struct V_183 * F_221 ( void )
{
struct V_183 * V_309 ;
V_309 = F_98 ( sizeof( * V_309 ) , V_154 ) ;
if ( ! V_309 ) {
F_3 ( L_67 , V_5 ) ;
return NULL ;
}
return V_309 ;
}
int
F_222 ( struct V_36 * V_36 , T_2 V_38 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_310 * V_298 ;
struct V_33 * V_259 ;
int V_25 = 0 ;
if ( ! F_145 ( V_14 ) || ! V_39 -> V_311 )
goto V_4;
if ( ! F_223 ( V_36 , V_312 ) )
goto V_4;
if ( F_38 ( V_313 , & V_48 -> V_147 ) )
goto V_4;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_28 ( V_36 ) -> V_49 ) {
F_7 ( & V_36 -> V_52 ) ;
goto V_314;
}
V_259 = F_28 ( V_36 ) -> V_49 ;
F_20 ( V_259 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_298 = F_98 ( sizeof( * V_298 ) , V_38 ) ;
if ( ! V_298 ) {
V_25 = - V_139 ;
goto V_315;
}
V_298 -> args . V_316 = F_224 ( V_36 ) ;
V_298 -> args . V_36 = V_36 ;
V_25 = V_39 -> V_311 ( & V_298 -> args ) ;
if ( V_25 )
goto V_317;
V_25 = F_225 ( F_22 ( V_36 ) , V_298 ) ;
V_4:
F_3 ( L_68 , V_5 , V_25 ) ;
return V_25 ;
V_317:
F_219 ( V_298 ) ;
V_315:
F_29 ( V_259 ) ;
V_314:
F_226 () ;
F_56 ( V_313 , & V_48 -> V_147 ) ;
F_107 () ;
goto V_4;
}
