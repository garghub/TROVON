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
return F_35 ( V_34 , V_55 , & V_57 ) ;
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
F_35 ( V_34 , & V_71 , & V_57 ) ;
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
if ( F_24 ( & V_34 -> V_53 ) )
F_55 ( V_83 , & V_34 -> V_64 ) ;
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
int
F_35 ( struct V_33 * V_34 ,
struct V_54 * V_97 ,
const struct V_56 * V_96 )
{
struct V_75 * V_76 , * V_99 ;
int V_100 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_72 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_96 ||
F_69 ( & V_76 -> V_101 , V_96 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_76 , V_76 -> V_101 . V_58 , V_76 -> V_101 . V_60 ,
V_76 -> V_101 . V_61 ) ;
if ( ! F_71 ( V_76 , V_97 ) )
V_100 ++ ;
}
F_3 ( L_26 , V_5 , V_100 ) ;
return V_100 ;
}
void
F_44 ( struct V_54 * V_102 )
{
struct V_75 * V_76 , * V_27 ;
if ( F_24 ( V_102 ) )
return;
F_72 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_76 -> V_77 ) ;
F_52 ( V_76 ) ;
}
}
void
F_73 ( struct V_47 * V_48 )
{
struct V_33 * V_34 ;
F_43 ( V_97 ) ;
F_5 ( & V_48 -> V_103 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
F_20 ( V_34 ) ;
F_33 ( V_34 , & V_97 ) ;
F_39 ( V_34 , V_67 ) ;
F_39 ( V_34 , V_66 ) ;
F_7 ( & V_48 -> V_103 . V_52 ) ;
F_44 ( & V_97 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_103 . V_52 ) ;
}
static bool
F_74 ( struct V_36 * V_36 ,
struct V_54 * V_104 )
{
struct V_33 * V_34 ;
bool V_105 = false ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 != NULL && F_24 ( & V_34 -> V_106 ) ) {
F_20 ( V_34 ) ;
F_17 ( & V_34 -> V_106 , V_104 ) ;
V_105 = true ;
}
F_7 ( & V_36 -> V_52 ) ;
return V_105 ;
}
static int
F_75 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_54 * V_104 )
{
struct V_33 * V_34 , * V_99 ;
struct V_36 * V_36 ;
F_72 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_76 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_74 ( V_36 , V_104 ) )
continue;
F_77 () ;
F_7 ( & V_43 -> V_44 ) ;
F_78 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_79 () ;
return - V_107 ;
}
return 0 ;
}
static int
F_80 ( struct V_54 * V_104 ,
bool V_108 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
F_43 ( V_55 ) ;
int V_105 = 0 ;
while ( ! F_24 ( V_104 ) ) {
V_34 = F_81 ( V_104 -> V_99 , struct V_33 ,
V_106 ) ;
F_3 ( L_27 , V_5 ,
V_34 -> V_41 -> V_109 ) ;
V_36 = V_34 -> V_41 ;
F_82 ( V_36 , false ) ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_106 ) ;
if ( F_33 ( V_34 , & V_55 ) ) {
if ( V_108 )
F_34 ( V_83 , & V_34 -> V_64 ) ;
V_105 = - V_107 ;
}
F_7 ( & V_36 -> V_52 ) ;
F_44 ( & V_55 ) ;
F_83 ( V_36 , 0 ) ;
F_29 ( V_34 ) ;
F_78 ( V_36 ) ;
}
return V_105 ;
}
int
F_84 ( struct V_12 * V_43 ,
struct V_110 * V_111 ,
bool V_112 )
{
struct V_8 * V_14 ;
F_43 ( V_104 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_79 () ;
V_113:
F_85 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_111 , V_111 , sizeof( * V_111 ) ) != 0 )
continue;
if ( F_75 ( V_43 ,
V_14 ,
& V_104 ) != 0 )
goto V_113;
}
F_77 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_104 ) )
return 0 ;
return F_80 ( & V_104 , V_112 ) ;
}
int
F_86 ( struct V_12 * V_43 ,
bool V_112 )
{
struct V_8 * V_14 ;
F_43 ( V_104 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_79 () ;
V_113:
F_85 (server, &clp->cl_superblocks, client_link) {
if ( F_75 ( V_43 ,
V_14 ,
& V_104 ) != 0 )
goto V_113;
}
F_77 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_104 ) )
return 0 ;
return F_80 ( & V_104 , V_112 ) ;
}
void
F_87 ( struct V_12 * V_43 )
{
F_88 ( V_43 ) ;
F_10 ( V_43 ) ;
F_86 ( V_43 , false ) ;
}
static bool F_89 ( T_1 V_114 , T_1 V_115 )
{
return ( V_116 ) ( V_114 - V_115 ) > 0 ;
}
void
F_90 ( struct V_33 * V_34 , const T_4 * V_117 ,
bool V_118 )
{
T_1 V_119 , V_120 , V_121 ;
int V_122 = F_24 ( & V_34 -> V_53 ) ;
V_119 = F_91 ( V_34 -> V_123 . V_124 ) ;
V_120 = F_91 ( V_117 -> V_124 ) ;
if ( V_122 || F_89 ( V_120 , V_119 ) ) {
F_92 ( & V_34 -> V_123 , V_117 ) ;
if ( V_118 ) {
V_121 = F_91 ( V_117 -> V_124 ) ;
} else {
V_121 = V_120 - F_58 ( & V_34 -> V_125 ) ;
}
if ( V_122 || F_89 ( V_121 , V_34 -> V_126 ) )
V_34 -> V_126 = V_121 ;
}
}
static bool
F_93 ( const struct V_33 * V_34 ,
const T_4 * V_127 )
{
T_1 V_124 = F_91 ( V_127 -> V_124 ) ;
return ! F_89 ( V_124 , V_34 -> V_126 ) ;
}
static bool
F_94 ( const struct V_33 * V_34 )
{
return V_34 -> V_128 ||
F_46 ( V_83 , & V_34 -> V_64 ) ;
}
int
F_95 ( T_4 * V_129 , struct V_33 * V_34 ,
const struct V_56 * V_57 ,
struct V_130 * V_131 )
{
int V_25 = 0 ;
F_3 ( L_28 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_94 ( V_34 ) ) {
V_25 = - V_107 ;
} else if ( ! F_96 ( V_131 ) ) {
V_25 = - V_132 ;
} else if ( F_24 ( & V_34 -> V_53 ) ||
F_46 ( V_63 , & V_34 -> V_64 ) ) {
int V_133 ;
do {
V_133 = F_97 ( & V_131 -> V_134 ) ;
F_92 ( V_129 , & V_131 -> V_127 ) ;
} while ( F_98 ( & V_131 -> V_134 , V_133 ) );
} else
F_92 ( V_129 , & V_34 -> V_123 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_29 , V_5 ) ;
return V_25 ;
}
static struct V_75 *
F_99 ( struct V_33 * V_34 ,
struct V_135 * V_136 ,
const struct V_56 * V_57 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_137 * V_138 ;
struct V_75 * V_76 ;
T_5 V_139 ;
F_3 ( L_28 , V_5 ) ;
do {
V_138 = F_100 ( sizeof( * V_138 ) , V_38 ) ;
if ( V_138 == NULL )
return NULL ;
V_139 = F_101 ( V_37 ) ;
V_138 -> args . V_140 = V_141 ;
if ( V_138 -> args . V_140 > V_57 -> V_61 )
V_138 -> args . V_140 = V_57 -> V_61 ;
if ( V_57 -> V_58 == V_142 ) {
if ( V_57 -> V_60 >= V_139 )
V_138 -> args . V_140 = 0 ;
else if ( V_139 - V_57 -> V_60 < V_138 -> args . V_140 )
V_138 -> args . V_140 = V_139 - V_57 -> V_60 ;
}
V_138 -> args . V_143 = V_144 ;
F_102 ( & V_138 -> args . V_57 , V_57 ) ;
V_138 -> args . type = V_14 -> V_10 -> V_2 ;
V_138 -> args . V_36 = V_37 ;
V_138 -> args . V_136 = F_103 ( V_136 ) ;
V_138 -> V_38 = V_38 ;
V_138 -> V_145 = V_34 -> V_45 ;
V_76 = F_104 ( V_138 , V_38 ) ;
} while ( V_76 == F_105 ( - V_107 ) );
if ( F_106 ( V_76 ) && ! F_107 ( F_108 ( V_76 ) ) )
V_76 = NULL ;
else
F_39 ( V_34 ,
F_36 ( V_57 -> V_58 ) ) ;
return V_76 ;
}
static void F_109 ( struct V_36 * V_36 ,
struct V_54 * V_71 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_75 * V_76 , * V_27 ;
if ( ! F_40 ( V_146 , & V_48 -> V_147 ) )
return;
F_72 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_40 ( V_148 , & V_76 -> V_81 ) )
continue;
F_70 ( V_76 , V_71 ) ;
}
}
void F_110 ( struct V_33 * V_34 )
{
F_111 ( V_149 , & V_34 -> V_64 ) ;
F_112 () ;
F_113 ( & V_34 -> V_64 , V_149 ) ;
F_56 ( & F_22 ( V_34 -> V_41 ) -> V_84 ) ;
}
static bool
F_114 ( struct V_33 * V_34 )
{
if ( F_38 ( V_149 , & V_34 -> V_64 ) )
return false ;
V_34 -> V_150 = 0 ;
F_20 ( V_34 ) ;
F_55 ( V_151 , & V_34 -> V_64 ) ;
return true ;
}
static int
F_115 ( struct V_33 * V_34 , const T_4 * V_127 ,
enum V_152 V_58 , bool V_153 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_154 * V_155 ;
int V_25 = 0 ;
V_155 = F_100 ( sizeof( * V_155 ) , V_156 ) ;
if ( F_116 ( V_155 == NULL ) ) {
V_25 = - V_157 ;
F_5 ( & V_37 -> V_52 ) ;
F_110 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
F_92 ( & V_155 -> args . V_127 , V_127 ) ;
V_155 -> args . V_158 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_155 -> args . V_36 = V_37 ;
V_155 -> args . V_57 . V_58 = V_58 ;
V_155 -> args . V_57 . V_60 = 0 ;
V_155 -> args . V_57 . V_61 = V_62 ;
V_155 -> args . V_49 = V_34 ;
V_155 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_155 -> V_145 = V_34 -> V_45 ;
V_25 = F_117 ( V_155 , V_153 ) ;
V_4:
F_3 ( L_30 , V_5 , V_25 ) ;
return V_25 ;
}
static bool
F_118 ( struct V_33 * V_34 )
{
struct V_75 * V_159 ;
if ( ! F_46 ( V_151 , & V_34 -> V_64 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list) {
if ( F_46 ( V_160 , & V_159 -> V_81 ) )
return false ;
}
return true ;
}
static void F_30 ( struct V_33 * V_34 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
if ( ! F_46 ( V_151 , & V_34 -> V_64 ) )
return;
F_5 ( & V_36 -> V_52 ) ;
if ( F_118 ( V_34 ) ) {
T_4 V_127 ;
enum V_152 V_58 ;
bool V_161 ;
F_92 ( & V_127 , & V_34 -> V_123 ) ;
V_58 = V_34 -> V_150 ;
V_161 = F_114 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_161 ) {
F_115 ( V_34 , & V_127 , V_58 , false ) ;
}
} else
F_7 ( & V_36 -> V_52 ) ;
}
int
F_119 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_43 ( V_97 ) ;
T_4 V_127 ;
int V_25 = 0 , V_122 ;
bool V_161 ;
F_3 ( L_31 , V_5 , V_37 -> V_109 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_4;
}
F_92 ( & V_127 , & V_48 -> V_49 -> V_123 ) ;
F_20 ( V_34 ) ;
V_122 = F_24 ( & V_34 -> V_53 ) ;
F_109 ( V_37 , & V_97 ) ;
F_35 ( V_34 , & V_97 , NULL ) ;
if ( F_22 ( V_37 ) -> V_10 -> V_162 ) {
struct V_56 V_57 = {
. V_58 = V_59 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_22 ( V_37 ) -> V_10 -> V_162 ( V_34 , & V_57 ) ;
}
if ( V_122 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_33 , V_5 ) ;
goto V_163;
}
F_34 ( V_63 , & V_34 -> V_64 ) ;
V_161 = F_114 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_97 ) ;
if ( V_161 )
V_25 = F_115 ( V_34 , & V_127 , V_59 , true ) ;
V_163:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_30 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_120 ( struct V_36 * V_36 )
{
struct V_33 * V_34 ;
int V_105 ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 == NULL ) {
F_7 ( & V_36 -> V_52 ) ;
return 0 ;
}
F_20 ( V_34 ) ;
V_34 -> V_128 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_121 ( V_36 -> V_164 ) ;
V_105 = F_82 ( V_36 , true ) ;
if ( V_105 == 0 )
V_105 = F_119 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_128 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_105 ;
}
bool F_122 ( struct V_36 * V_37 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_135 * V_136 ;
struct V_130 * V_165 ;
struct V_33 * V_34 ;
struct V_75 * V_76 , * V_27 ;
T_4 V_127 ;
F_43 ( V_97 ) ;
bool V_166 = false , V_167 = false , V_168 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 || F_46 ( V_83 , & V_34 -> V_64 ) )
goto V_169;
if ( F_123 ( V_37 , V_170 ) )
goto V_169;
F_2 (ctx, &nfsi->open_files, list) {
V_165 = V_136 -> V_165 ;
if ( V_165 != NULL && V_165 -> V_165 != 0 )
goto V_169;
}
F_92 ( & V_127 , & V_34 -> V_123 ) ;
if ( F_40 ( V_151 ,
& V_34 -> V_64 ) )
V_167 = F_114 ( V_34 ) ;
F_72 (lseg, tmp, &lo->plh_segs, pls_list)
if ( V_167 || F_46 ( V_171 , & V_76 -> V_81 ) ) {
F_71 ( V_76 , & V_97 ) ;
V_166 = true ;
}
if ( V_166 && ! V_167 ) {
F_20 ( V_34 ) ;
V_168 = true ;
}
V_169:
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_97 ) ;
F_82 ( V_37 , true ) ;
if ( V_167 )
F_115 ( V_34 , & V_127 , V_59 , true ) ;
return V_168 ;
}
void F_124 ( struct V_36 * V_37 )
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
void F_125 ( struct V_36 * V_37 , T_1 V_172 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
F_126 ( V_34 ) ;
if ( F_89 ( V_172 , V_34 -> V_126 ) )
V_34 -> V_126 = V_172 ;
F_7 ( & V_37 -> V_52 ) ;
F_127 ( V_37 , 0 ) ;
}
void F_128 ( struct V_36 * V_37 , T_1 * V_172 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
T_1 V_173 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
V_173 = F_91 ( V_34 -> V_123 . V_124 ) ;
* V_172 = V_173 + F_58 ( & V_34 -> V_125 ) ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_129 ( struct V_36 * V_37 , struct V_174 * V_175 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
bool V_176 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 && F_46 ( V_149 , & V_34 -> V_64 ) )
V_176 = true ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_176 )
F_130 ( & F_22 ( V_37 ) -> V_84 , V_175 , NULL ) ;
return V_176 ;
}
static T_6
F_131 ( const struct V_56 * V_89 ,
const struct V_56 * V_90 )
{
T_6 V_177 ;
V_177 = V_89 -> V_60 - V_90 -> V_60 ;
if ( V_177 )
return V_177 ;
V_177 = V_90 -> V_61 - V_89 -> V_61 ;
if ( V_177 )
return V_177 ;
return ( int ) ( V_89 -> V_58 == V_142 ) - ( int ) ( V_90 -> V_58 == V_142 ) ;
}
static bool
F_132 ( const struct V_56 * V_89 ,
const struct V_56 * V_90 )
{
return F_131 ( V_89 , V_90 ) > 0 ;
}
static bool
F_133 ( struct V_75 * V_76 ,
struct V_75 * V_178 )
{
return false ;
}
void
F_134 ( struct V_33 * V_34 ,
struct V_75 * V_76 ,
bool (* F_135)( const struct V_56 * ,
const struct V_56 * ) ,
bool (* F_136)( struct V_75 * ,
struct V_75 * ) ,
struct V_54 * V_102 )
{
struct V_75 * V_179 , * V_27 ;
F_3 ( L_34 , V_5 ) ;
F_72 (lp, tmp, &lo->plh_segs, pls_list) {
if ( F_46 ( V_80 , & V_179 -> V_81 ) == 0 )
continue;
if ( F_136 ( V_76 , V_179 ) ) {
F_71 ( V_179 , V_102 ) ;
continue;
}
if ( F_135 ( & V_76 -> V_101 , & V_179 -> V_101 ) )
continue;
F_137 ( & V_76 -> V_77 , & V_179 -> V_77 ) ;
F_3 ( L_35
L_36
L_37 ,
V_5 , V_76 , V_76 -> V_101 . V_58 ,
V_76 -> V_101 . V_60 , V_76 -> V_101 . V_61 ,
V_179 , V_179 -> V_101 . V_58 , V_179 -> V_101 . V_60 ,
V_179 -> V_101 . V_61 ) ;
goto V_4;
}
F_137 ( & V_76 -> V_77 , & V_34 -> V_53 ) ;
F_3 ( L_35
L_38 ,
V_5 , V_76 , V_76 -> V_101 . V_58 ,
V_76 -> V_101 . V_60 , V_76 -> V_101 . V_61 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_39 , V_5 ) ;
}
static void
F_138 ( struct V_33 * V_34 ,
struct V_75 * V_76 ,
struct V_54 * V_102 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
if ( V_39 -> V_180 != NULL )
V_39 -> V_180 ( V_34 , V_76 , V_102 ) ;
else
F_134 ( V_34 , V_76 ,
F_132 ,
F_133 ,
V_102 ) ;
}
static struct V_33 *
F_139 ( struct V_36 * V_37 ,
struct V_135 * V_136 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_50 ( & V_34 -> V_35 , 1 ) ;
F_49 ( & V_34 -> V_42 ) ;
F_49 ( & V_34 -> V_53 ) ;
F_49 ( & V_34 -> V_106 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_140 ( V_136 -> V_145 ) ;
return V_34 ;
}
static struct V_33 *
F_141 ( struct V_36 * V_37 ,
struct V_135 * V_136 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_117 = NULL ;
F_3 ( L_40 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_181;
F_7 ( & V_37 -> V_52 ) ;
V_117 = F_139 ( V_37 , V_136 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_142 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_117 ;
return V_117 ;
} else if ( V_117 != NULL )
F_23 ( V_117 ) ;
V_181:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_143 ( const struct V_56 * V_182 ,
const struct V_56 * V_57 )
{
struct V_56 V_183 ;
if ( ( V_57 -> V_58 == V_65 &&
V_182 -> V_58 != V_65 ) ||
! F_68 ( V_182 , V_57 ) )
return 0 ;
V_183 = * V_57 ;
V_183 . V_61 = 1 ;
return F_67 ( V_182 , & V_183 ) ;
}
static struct V_75 *
F_144 ( struct V_33 * V_34 ,
struct V_56 * V_57 )
{
struct V_75 * V_76 , * V_105 = NULL ;
F_3 ( L_34 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_46 ( V_80 , & V_76 -> V_81 ) &&
! F_46 ( V_160 , & V_76 -> V_81 ) &&
F_143 ( & V_76 -> V_101 , V_57 ) ) {
V_105 = F_145 ( V_76 ) ;
break;
}
}
F_3 ( L_41 ,
V_5 , V_105 , V_105 ? F_58 ( & V_105 -> V_79 ) : 0 ) ;
return V_105 ;
}
static bool F_146 ( struct V_135 * V_136 ,
struct V_36 * V_37 , int V_58 )
{
struct V_184 * V_185 = V_136 -> V_186 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_5 V_187 = F_101 ( V_37 ) ;
bool V_188 = false , V_189 = false , V_190 = false , V_191 = false , V_105 = false ;
if ( V_185 == NULL )
return V_105 ;
F_3 ( L_42 ,
V_5 , V_185 -> V_192 , V_185 -> V_193 , V_185 -> V_194 , V_185 -> V_195 , V_185 -> V_196 ) ;
switch ( V_58 ) {
case V_142 :
if ( V_185 -> V_192 & V_197 ) {
F_3 ( L_43 , V_5 , V_187 ) ;
V_189 = true ;
if ( V_187 < V_185 -> V_193 )
V_188 = true ;
}
if ( V_185 -> V_192 & V_198 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_51 ) ;
V_191 = true ;
if ( V_48 -> V_51 < V_185 -> V_195 )
V_190 = true ;
}
break;
case V_65 :
if ( V_185 -> V_192 & V_199 ) {
F_3 ( L_43 , V_5 , V_187 ) ;
V_189 = true ;
if ( V_187 < V_185 -> V_194 )
V_188 = true ;
}
if ( V_185 -> V_192 & V_200 ) {
F_3 ( L_45 , V_5 ,
V_48 -> V_50 ) ;
V_191 = true ;
if ( V_48 -> V_50 < V_185 -> V_196 )
V_190 = true ;
}
break;
}
if ( V_189 && V_191 ) {
if ( V_188 && V_190 )
V_105 = true ;
} else if ( V_188 || V_190 )
V_105 = true ;
F_3 ( L_46 , V_5 , V_188 , V_190 , V_105 ) ;
return V_105 ;
}
static bool F_147 ( struct V_33 * V_34 )
{
F_82 ( V_34 -> V_41 , false ) ;
return ! F_148 ( & V_34 -> V_64 , V_149 ,
V_201 ,
V_202 ) ;
}
static void F_149 ( struct V_33 * V_34 )
{
unsigned long * V_203 = & V_34 -> V_64 ;
F_111 ( V_204 , V_203 ) ;
F_112 () ;
F_113 ( V_203 , V_204 ) ;
}
struct V_75 *
F_150 ( struct V_36 * V_37 ,
struct V_135 * V_136 ,
T_5 V_205 ,
T_3 V_206 ,
enum V_152 V_58 ,
T_2 V_38 )
{
struct V_56 V_207 = {
. V_58 = V_58 ,
. V_60 = V_205 ,
. V_61 = V_206 ,
} ;
unsigned V_208 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_75 * V_76 = NULL ;
bool V_209 ;
if ( ! F_151 ( F_22 ( V_37 ) ) ) {
F_152 ( V_37 , V_205 , V_206 , V_58 , NULL ,
V_210 ) ;
goto V_4;
}
if ( V_58 == V_142 && F_101 ( V_37 ) == 0 ) {
F_152 ( V_37 , V_205 , V_206 , V_58 , NULL ,
V_211 ) ;
goto V_4;
}
if ( F_146 ( V_136 , V_37 , V_58 ) ) {
F_152 ( V_37 , V_205 , V_206 , V_58 , NULL ,
V_212 ) ;
goto V_4;
}
V_213:
V_209 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_141 ( V_37 , V_136 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
F_152 ( V_37 , V_205 , V_206 , V_58 , NULL ,
V_214 ) ;
goto V_4;
}
if ( F_46 ( V_83 , & V_34 -> V_64 ) ) {
F_152 ( V_37 , V_205 , V_206 , V_58 , V_34 ,
V_215 ) ;
F_3 ( L_47 , V_5 ) ;
goto V_216;
}
if ( F_45 ( V_34 , V_58 ) ) {
F_152 ( V_37 , V_205 , V_206 , V_58 , V_34 ,
V_217 ) ;
goto V_216;
}
V_209 = F_24 ( & V_34 -> V_53 ) ;
if ( V_209 ) {
if ( F_38 ( V_204 ,
& V_34 -> V_64 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_153 ( & V_34 -> V_64 , V_204 ,
V_202 ) ;
F_29 ( V_34 ) ;
goto V_213;
}
} else {
V_76 = F_144 ( V_34 , & V_207 ) ;
if ( V_76 ) {
F_152 ( V_37 , V_205 , V_206 , V_58 , V_34 ,
V_218 ) ;
goto V_216;
}
}
if ( F_46 ( V_149 , & V_34 -> V_64 ) ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_48 , V_5 ) ;
if ( F_147 ( V_34 ) ) {
if ( V_209 )
F_149 ( V_34 ) ;
F_29 ( V_34 ) ;
F_3 ( L_49 , V_5 ) ;
goto V_213;
}
F_152 ( V_37 , V_205 , V_206 , V_58 , V_34 ,
V_219 ) ;
goto V_163;
}
if ( F_94 ( V_34 ) ) {
F_152 ( V_37 , V_205 , V_206 , V_58 , V_34 ,
V_220 ) ;
goto V_216;
}
F_15 ( & V_34 -> V_125 ) ;
F_7 ( & V_37 -> V_52 ) ;
if ( F_24 ( & V_34 -> V_42 ) ) {
F_5 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_34 -> V_42 ) )
F_137 ( & V_34 -> V_42 , & V_14 -> V_221 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_208 = V_207 . V_60 & ~ V_222 ;
if ( V_208 ) {
V_207 . V_60 -= V_208 ;
V_207 . V_61 += V_208 ;
}
if ( V_207 . V_61 != V_62 )
V_207 . V_61 = F_154 ( V_207 . V_61 ) ;
V_76 = F_99 ( V_34 , V_136 , & V_207 , V_38 ) ;
F_41 ( & V_34 -> V_125 ) ;
F_152 ( V_37 , V_205 , V_206 , V_58 , V_34 ,
V_223 ) ;
V_163:
if ( V_209 )
F_149 ( V_34 ) ;
F_29 ( V_34 ) ;
V_4:
F_3 ( L_50
L_51 ,
V_5 , V_37 -> V_224 -> V_225 ,
( unsigned long long ) F_155 ( V_37 ) ,
F_156 ( V_76 ) ? L_52 : L_53 ,
V_58 == V_65 ? L_54 : L_55 ,
( unsigned long long ) V_205 ,
( unsigned long long ) V_206 ) ;
return V_76 ;
V_216:
F_7 ( & V_37 -> V_52 ) ;
goto V_163;
}
static bool
F_157 ( struct V_56 * V_57 )
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
F_158 ( struct V_137 * V_138 )
{
struct V_33 * V_34 = F_28 ( V_138 -> args . V_36 ) -> V_49 ;
struct V_226 * V_227 = & V_138 -> V_227 ;
struct V_75 * V_76 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_43 ( V_102 ) ;
int V_25 = - V_26 ;
if ( ! F_157 ( & V_227 -> V_57 ) )
goto V_4;
V_76 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_227 , V_138 -> V_38 ) ;
if ( ! V_76 || F_106 ( V_76 ) ) {
if ( ! V_76 )
V_25 = - V_157 ;
else
V_25 = F_108 ( V_76 ) ;
F_3 ( L_56 ,
V_5 , V_25 ) ;
goto V_4;
}
F_48 ( V_34 , V_76 ) ;
V_76 -> V_101 = V_227 -> V_57 ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_94 ( V_34 ) ) {
F_3 ( L_57 , V_5 ) ;
goto V_228;
}
if ( F_159 ( & V_34 -> V_123 , & V_227 -> V_127 ) ) {
if ( F_93 ( V_34 , & V_227 -> V_127 ) ) {
F_3 ( L_58 , V_5 ) ;
V_25 = - V_107 ;
goto V_228;
}
F_90 ( V_34 , & V_227 -> V_127 , false ) ;
} else {
F_35 ( V_34 , & V_102 , NULL ) ;
F_92 ( & V_34 -> V_123 , & V_227 -> V_127 ) ;
V_34 -> V_126 = F_91 ( V_227 -> V_127 . V_124 ) ;
}
F_55 ( V_63 , & V_34 -> V_64 ) ;
F_145 ( V_76 ) ;
F_138 ( V_34 , V_76 , & V_102 ) ;
if ( V_227 -> V_229 )
F_34 ( V_171 , & V_76 -> V_81 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_44 ( & V_102 ) ;
return V_76 ;
V_4:
return F_105 ( V_25 ) ;
V_228:
F_7 ( & V_37 -> V_52 ) ;
V_76 -> V_82 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_76 ) ;
goto V_4;
}
static void
F_160 ( struct V_33 * V_34 , enum V_152 V_58 )
{
if ( V_34 -> V_150 == V_58 )
return;
if ( V_34 -> V_150 != 0 )
V_58 = V_59 ;
V_34 -> V_150 = V_58 ;
F_34 ( V_151 , & V_34 -> V_64 ) ;
}
int
F_161 ( struct V_33 * V_34 ,
struct V_54 * V_97 ,
const struct V_56 * V_162 )
{
struct V_75 * V_76 , * V_99 ;
int V_100 = 0 ;
F_3 ( L_23 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_53 ) )
return 0 ;
F_65 ( & V_34 -> V_41 -> V_52 ) ;
F_72 (lseg, next, &lo->plh_segs, pls_list)
if ( F_69 ( & V_76 -> V_101 , V_162 ) ) {
F_3 ( L_59
L_25 , V_5 ,
V_76 , V_76 -> V_101 . V_58 ,
V_76 -> V_101 . V_60 ,
V_76 -> V_101 . V_61 ) ;
if ( F_71 ( V_76 , V_97 ) )
continue;
V_100 ++ ;
F_34 ( V_160 , & V_76 -> V_81 ) ;
F_160 ( V_34 , V_162 -> V_58 ) ;
}
return V_100 ;
}
void F_162 ( struct V_36 * V_36 ,
struct V_75 * V_76 )
{
struct V_33 * V_34 = F_28 ( V_36 ) -> V_49 ;
struct V_56 V_57 = {
. V_58 = V_76 -> V_101 . V_58 ,
. V_60 = 0 ,
. V_61 = V_62 ,
} ;
F_43 ( V_102 ) ;
bool V_230 = false ;
F_5 ( & V_36 -> V_52 ) ;
F_160 ( V_34 , V_57 . V_58 ) ;
if ( ! F_161 ( V_34 , & V_102 , & V_57 ) ) {
T_4 V_127 ;
enum V_152 V_58 = V_34 -> V_150 ;
F_92 ( & V_127 , & V_34 -> V_123 ) ;
V_230 = F_114 ( V_34 ) ;
F_7 ( & V_36 -> V_52 ) ;
if ( V_230 )
F_115 ( V_34 , & V_127 , V_58 , false ) ;
} else {
F_7 ( & V_36 -> V_52 ) ;
F_83 ( V_36 , 0 ) ;
}
F_44 ( & V_102 ) ;
}
void
F_163 ( struct V_231 * V_232 , struct V_233 * V_234 )
{
T_3 V_235 = V_234 -> V_236 ;
if ( V_232 -> V_237 == NULL ) {
if ( V_232 -> V_238 == NULL )
V_235 = F_101 ( V_232 -> V_239 ) - F_164 ( V_234 ) ;
else
V_235 = F_165 ( V_232 -> V_238 ) ;
V_232 -> V_237 = F_150 ( V_232 -> V_239 ,
V_234 -> V_240 ,
F_164 ( V_234 ) ,
V_235 ,
V_142 ,
V_241 ) ;
if ( F_106 ( V_232 -> V_237 ) ) {
V_232 -> V_242 = F_108 ( V_232 -> V_237 ) ;
V_232 -> V_237 = NULL ;
return;
}
}
if ( V_232 -> V_237 == NULL )
F_166 ( V_232 ) ;
}
void
F_167 ( struct V_231 * V_232 ,
struct V_233 * V_234 , T_3 V_243 )
{
if ( V_232 -> V_237 == NULL ) {
V_232 -> V_237 = F_150 ( V_232 -> V_239 ,
V_234 -> V_240 ,
F_164 ( V_234 ) ,
V_243 ,
V_65 ,
V_156 ) ;
if ( F_106 ( V_232 -> V_237 ) ) {
V_232 -> V_242 = F_108 ( V_232 -> V_237 ) ;
V_232 -> V_237 = NULL ;
return;
}
}
if ( V_232 -> V_237 == NULL )
F_168 ( V_232 ) ;
}
void
F_169 ( struct V_231 * V_244 )
{
if ( V_244 -> V_237 ) {
F_57 ( V_244 -> V_237 ) ;
V_244 -> V_237 = NULL ;
}
}
T_7
F_170 ( struct V_231 * V_232 ,
struct V_233 * V_245 , struct V_233 * V_234 )
{
unsigned int V_188 ;
T_3 V_246 , V_247 , V_248 ;
V_188 = F_171 ( V_232 , V_245 , V_234 ) ;
if ( ! V_188 )
return 0 ;
if ( V_232 -> V_237 ) {
V_246 = F_66 ( V_232 -> V_237 -> V_101 . V_60 ,
V_232 -> V_237 -> V_101 . V_61 ) ;
V_247 = F_164 ( V_234 ) ;
F_172 ( V_247 >= V_246 ) ;
if ( V_247 >= V_246 ) {
if ( V_232 -> V_249 -> V_250 )
V_232 -> V_249 -> V_250 ( V_232 ) ;
if ( V_232 -> V_249 -> V_251 )
V_232 -> V_249 -> V_251 ( V_232 , V_234 ) ;
return 0 ;
}
V_248 = V_246 - V_247 ;
if ( V_248 < V_188 )
V_188 = ( unsigned int ) V_248 ;
}
return V_188 ;
}
int F_173 ( struct V_252 * V_253 )
{
struct V_231 V_232 ;
F_174 ( & V_232 , V_253 -> V_36 , V_254 , true ,
V_253 -> V_255 ) ;
F_34 ( V_256 , & V_253 -> args . V_257 -> V_147 ) ;
return F_175 ( & V_232 , V_253 ) ;
}
static void F_176 ( struct V_252 * V_253 )
{
F_3 ( L_60 , V_253 -> V_258 ) ;
if ( F_22 ( V_253 -> V_36 ) -> V_10 -> V_147 &
V_259 ) {
F_177 ( V_253 -> V_36 ) ;
}
if ( ! F_38 ( V_260 , & V_253 -> V_147 ) )
V_253 -> V_175 . V_261 = F_173 ( V_253 ) ;
}
void F_178 ( struct V_252 * V_253 )
{
if ( F_142 ( ! V_253 -> V_258 ) ) {
F_179 ( V_253 -> V_36 , V_253 -> V_76 ,
V_253 -> V_262 + V_253 -> V_227 . V_206 ) ;
V_253 -> V_263 -> V_264 ( & V_253 -> V_175 , V_253 ) ;
}
F_180 ( V_253 , V_253 -> V_258 ) ;
if ( F_116 ( V_253 -> V_258 ) )
F_176 ( V_253 ) ;
V_253 -> V_263 -> V_265 ( V_253 ) ;
}
static void
F_181 ( struct V_231 * V_244 ,
struct V_252 * V_253 )
{
struct V_266 * V_267 = F_182 ( V_244 ) ;
if ( ! F_38 ( V_260 , & V_253 -> V_147 ) ) {
F_183 ( & V_253 -> V_268 , & V_267 -> V_269 ) ;
F_168 ( V_244 ) ;
V_267 -> V_270 = 1 ;
}
F_184 ( V_253 ) ;
V_253 -> V_271 ( V_253 ) ;
}
static enum V_272
F_185 ( struct V_252 * V_253 ,
const struct V_273 * V_274 ,
struct V_75 * V_76 ,
int V_275 )
{
struct V_36 * V_36 = V_253 -> V_36 ;
enum V_272 V_276 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_253 -> V_263 = V_274 ;
F_3 ( L_61 , V_5 ,
V_36 -> V_109 , V_253 -> args . V_206 , V_253 -> args . V_60 , V_275 ) ;
V_276 = V_9 -> V_10 -> V_277 ( V_253 , V_275 ) ;
if ( V_276 != V_278 )
F_186 ( V_36 , V_279 ) ;
F_3 ( L_62 , V_5 , V_276 ) ;
return V_276 ;
}
static void
F_187 ( struct V_231 * V_244 ,
struct V_252 * V_253 , int V_275 )
{
const struct V_273 * V_274 = V_244 -> V_280 ;
struct V_75 * V_76 = V_244 -> V_237 ;
enum V_272 V_276 ;
V_276 = F_185 ( V_253 , V_274 , V_76 , V_275 ) ;
if ( V_276 == V_278 )
F_181 ( V_244 , V_253 ) ;
}
static void F_188 ( struct V_252 * V_253 )
{
F_57 ( V_253 -> V_76 ) ;
F_189 ( V_253 ) ;
}
int
F_190 ( struct V_231 * V_244 )
{
struct V_252 * V_253 ;
int V_105 ;
V_253 = F_191 ( V_244 -> V_281 ) ;
if ( ! V_253 ) {
V_244 -> V_242 = - V_157 ;
return V_244 -> V_242 ;
}
F_192 ( V_244 , V_253 , F_188 ) ;
V_253 -> V_76 = F_145 ( V_244 -> V_237 ) ;
V_105 = F_193 ( V_244 , V_253 ) ;
if ( ! V_105 )
F_187 ( V_244 , V_253 , V_244 -> V_282 ) ;
return V_105 ;
}
int F_194 ( struct V_252 * V_253 )
{
struct V_231 V_232 ;
F_195 ( & V_232 , V_253 -> V_36 , true , V_253 -> V_255 ) ;
return F_175 ( & V_232 , V_253 ) ;
}
static void F_196 ( struct V_252 * V_253 )
{
F_3 ( L_63 , V_253 -> V_258 ) ;
if ( F_22 ( V_253 -> V_36 ) -> V_10 -> V_147 &
V_259 ) {
F_177 ( V_253 -> V_36 ) ;
}
if ( ! F_38 ( V_260 , & V_253 -> V_147 ) )
V_253 -> V_175 . V_261 = F_194 ( V_253 ) ;
}
void F_197 ( struct V_252 * V_253 )
{
if ( F_142 ( ! V_253 -> V_258 ) ) {
F_198 ( V_253 ) ;
V_253 -> V_263 -> V_264 ( & V_253 -> V_175 , V_253 ) ;
}
F_199 ( V_253 , V_253 -> V_258 ) ;
if ( F_116 ( V_253 -> V_258 ) )
F_196 ( V_253 ) ;
V_253 -> V_263 -> V_265 ( V_253 ) ;
}
static void
F_200 ( struct V_231 * V_244 ,
struct V_252 * V_253 )
{
struct V_266 * V_267 = F_182 ( V_244 ) ;
if ( ! F_38 ( V_260 , & V_253 -> V_147 ) ) {
F_183 ( & V_253 -> V_268 , & V_267 -> V_269 ) ;
F_166 ( V_244 ) ;
V_267 -> V_270 = 1 ;
}
F_184 ( V_253 ) ;
V_253 -> V_271 ( V_253 ) ;
}
static enum V_272
F_201 ( struct V_252 * V_253 ,
const struct V_273 * V_274 ,
struct V_75 * V_76 )
{
struct V_36 * V_36 = V_253 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_272 V_276 ;
V_253 -> V_263 = V_274 ;
F_3 ( L_64 ,
V_5 , V_36 -> V_109 , V_253 -> args . V_206 , V_253 -> args . V_60 ) ;
V_276 = V_9 -> V_10 -> V_283 ( V_253 ) ;
if ( V_276 != V_278 )
F_186 ( V_36 , V_284 ) ;
F_3 ( L_62 , V_5 , V_276 ) ;
return V_276 ;
}
int F_202 ( struct V_252 * V_253 )
{
struct V_231 V_232 ;
F_195 ( & V_232 , V_253 -> V_36 , false , V_253 -> V_255 ) ;
return F_175 ( & V_232 , V_253 ) ;
}
static void
F_203 ( struct V_231 * V_244 , struct V_252 * V_253 )
{
const struct V_273 * V_274 = V_244 -> V_280 ;
struct V_75 * V_76 = V_244 -> V_237 ;
enum V_272 V_276 ;
int V_285 = 0 ;
V_276 = F_201 ( V_253 , V_274 , V_76 ) ;
if ( V_276 == V_286 )
V_285 = F_202 ( V_253 ) ;
if ( V_276 == V_278 || V_285 )
F_200 ( V_244 , V_253 ) ;
}
static void F_204 ( struct V_252 * V_253 )
{
F_57 ( V_253 -> V_76 ) ;
F_189 ( V_253 ) ;
}
int
F_205 ( struct V_231 * V_244 )
{
struct V_252 * V_253 ;
int V_105 ;
V_253 = F_191 ( V_244 -> V_281 ) ;
if ( ! V_253 ) {
V_244 -> V_242 = - V_157 ;
return V_244 -> V_242 ;
}
F_192 ( V_244 , V_253 , F_204 ) ;
V_253 -> V_76 = F_145 ( V_244 -> V_237 ) ;
V_105 = F_193 ( V_244 , V_253 ) ;
if ( ! V_105 )
F_203 ( V_244 , V_253 ) ;
return V_105 ;
}
static void F_206 ( struct V_36 * V_36 )
{
unsigned long * V_203 = & F_28 ( V_36 ) -> V_147 ;
F_111 ( V_287 , V_203 ) ;
F_112 () ;
F_113 ( V_203 , V_287 ) ;
}
static void F_207 ( struct V_36 * V_36 , struct V_54 * V_288 )
{
struct V_75 * V_76 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_76 -> V_101 . V_58 == V_65 &&
F_40 ( V_148 , & V_76 -> V_81 ) )
F_17 ( & V_76 -> V_78 , V_288 ) ;
}
}
static void F_208 ( struct V_36 * V_36 , struct V_54 * V_288 )
{
struct V_75 * V_76 , * V_27 ;
F_72 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_76 -> V_78 ) ;
F_57 ( V_76 ) ;
}
F_206 ( V_36 ) ;
}
void F_209 ( struct V_75 * V_76 )
{
F_42 ( V_76 -> V_82 , V_76 -> V_101 . V_58 ) ;
}
void
F_179 ( struct V_36 * V_36 , struct V_75 * V_76 ,
T_5 V_289 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
bool V_290 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_38 ( V_146 , & V_48 -> V_147 ) ) {
V_48 -> V_49 -> V_291 = V_289 ;
V_290 = true ;
F_3 ( L_65 ,
V_5 , V_36 -> V_109 ) ;
} else if ( V_289 > V_48 -> V_49 -> V_291 )
V_48 -> V_49 -> V_291 = V_289 ;
if ( ! F_38 ( V_148 , & V_76 -> V_81 ) ) {
F_145 ( V_76 ) ;
}
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_66 ,
V_5 , V_76 , V_48 -> V_49 -> V_291 ) ;
if ( V_290 )
F_210 ( V_36 ) ;
}
void F_211 ( struct V_292 * V_293 )
{
struct V_8 * V_9 = F_22 ( V_293 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_294 )
V_9 -> V_10 -> V_294 ( V_293 ) ;
F_208 ( V_293 -> args . V_36 , & V_293 -> V_55 ) ;
}
int
F_82 ( struct V_36 * V_36 , bool V_153 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_292 * V_293 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_5 V_289 ;
int V_25 ;
if ( ! F_212 ( V_36 ) )
return 0 ;
F_3 ( L_67 , V_5 , V_36 -> V_109 ) ;
V_25 = - V_107 ;
if ( F_38 ( V_287 , & V_48 -> V_147 ) ) {
if ( ! V_153 )
goto V_4;
V_25 = F_213 ( & V_48 -> V_147 ,
V_287 ,
V_201 ,
V_295 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_157 ;
V_293 = F_100 ( sizeof( * V_293 ) , V_156 ) ;
if ( ! V_293 )
goto V_296;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_40 ( V_146 , & V_48 -> V_147 ) )
goto V_216;
F_49 ( & V_293 -> V_55 ) ;
F_207 ( V_36 , & V_293 -> V_55 ) ;
V_289 = V_48 -> V_49 -> V_291 ;
F_92 ( & V_293 -> args . V_127 , & V_48 -> V_49 -> V_123 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_293 -> args . V_36 = V_36 ;
V_293 -> V_145 = F_140 ( V_48 -> V_49 -> V_45 ) ;
F_214 ( & V_293 -> V_297 ) ;
V_293 -> args . V_298 = F_22 ( V_36 ) -> V_299 ;
V_293 -> V_227 . V_297 = & V_293 -> V_297 ;
V_293 -> args . V_300 = V_289 - 1 ;
V_293 -> V_227 . V_14 = F_22 ( V_36 ) ;
if ( V_39 -> V_301 ) {
V_25 = V_39 -> V_301 ( & V_293 -> args ) ;
if ( V_25 ) {
F_26 ( V_293 -> V_145 ) ;
F_5 ( & V_36 -> V_52 ) ;
F_34 ( V_146 , & V_48 -> V_147 ) ;
if ( V_289 > V_48 -> V_49 -> V_291 )
V_48 -> V_49 -> V_291 = V_289 ;
goto V_216;
}
}
V_25 = F_215 ( V_293 , V_153 ) ;
V_4:
if ( V_25 )
F_210 ( V_36 ) ;
F_3 ( L_68 , V_5 , V_25 ) ;
return V_25 ;
V_216:
F_7 ( & V_36 -> V_52 ) ;
F_216 ( V_293 ) ;
V_296:
F_206 ( V_36 ) ;
goto V_4;
}
int
F_217 ( struct V_36 * V_36 , bool V_302 )
{
return F_82 ( V_36 , true ) ;
}
struct V_184 * F_218 ( void )
{
struct V_184 * V_303 ;
V_303 = F_100 ( sizeof( * V_303 ) , V_156 ) ;
if ( ! V_303 ) {
F_3 ( L_69 , V_5 ) ;
return NULL ;
}
return V_303 ;
}
int
F_219 ( struct V_36 * V_36 , T_2 V_38 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_304 * V_293 ;
struct V_33 * V_253 ;
int V_25 = 0 ;
if ( ! F_151 ( V_14 ) || ! V_39 -> V_305 )
goto V_4;
if ( ! F_220 ( V_36 , V_306 ) )
goto V_4;
if ( F_38 ( V_307 , & V_48 -> V_147 ) )
goto V_4;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_28 ( V_36 ) -> V_49 ) {
F_7 ( & V_36 -> V_52 ) ;
goto V_4;
}
V_253 = F_28 ( V_36 ) -> V_49 ;
F_20 ( V_253 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_293 = F_100 ( sizeof( * V_293 ) , V_38 ) ;
if ( ! V_293 ) {
V_25 = - V_157 ;
goto V_308;
}
V_293 -> args . V_309 = F_221 ( V_36 ) ;
V_293 -> args . V_36 = V_36 ;
F_92 ( & V_293 -> args . V_127 , & V_253 -> V_123 ) ;
V_25 = V_39 -> V_305 ( & V_293 -> args ) ;
if ( V_25 )
goto V_310;
V_25 = F_222 ( F_22 ( V_36 ) , V_293 ) ;
V_4:
F_3 ( L_70 , V_5 , V_25 ) ;
return V_25 ;
V_310:
F_216 ( V_293 ) ;
V_308:
F_29 ( V_253 ) ;
F_223 () ;
F_55 ( V_307 , & V_48 -> V_147 ) ;
F_112 () ;
goto V_4;
}
