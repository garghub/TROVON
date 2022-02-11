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
if ( ! F_33 ( V_57 , & V_34 -> V_60 ) )
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
static void F_56 ( struct V_81 * V_82 )
{
struct V_70 * V_71 ;
V_71 = F_57 ( V_82 , struct V_70 , V_83 ) ;
F_54 ( V_71 ) ;
}
void
F_58 ( struct V_70 * V_71 )
{
F_59 ( & V_71 -> V_83 , F_56 ) ;
F_60 ( & V_71 -> V_83 ) ;
}
static T_3
F_61 ( T_3 V_67 , T_3 V_84 )
{
T_3 V_68 ;
V_68 = V_67 + V_84 ;
return V_68 >= V_67 ? V_68 : V_65 ;
}
static bool
F_62 ( const struct V_61 * V_85 ,
const struct V_61 * V_86 )
{
T_3 V_87 = V_85 -> V_63 ;
T_3 V_88 = F_61 ( V_87 , V_85 -> V_64 ) ;
T_3 V_89 = V_86 -> V_63 ;
T_3 V_90 = F_61 ( V_89 , V_86 -> V_64 ) ;
return ( V_87 <= V_89 ) && ( V_88 >= V_90 ) ;
}
static bool
F_63 ( const struct V_61 * V_85 ,
const struct V_61 * V_86 )
{
T_3 V_87 = V_85 -> V_63 ;
T_3 V_88 = F_61 ( V_87 , V_85 -> V_64 ) ;
T_3 V_89 = V_86 -> V_63 ;
T_3 V_90 = F_61 ( V_89 , V_86 -> V_64 ) ;
return ( V_88 == V_65 || V_88 > V_89 ) &&
( V_90 == V_65 || V_90 > V_87 ) ;
}
static bool
F_64 ( const struct V_61 * V_91 ,
const struct V_61 * V_92 )
{
return ( V_92 -> V_53 == V_93 ||
V_91 -> V_53 == V_92 -> V_53 ) &&
F_63 ( V_91 , V_92 ) ;
}
static bool F_65 ( struct V_70 * V_71 ,
struct V_94 * V_95 )
{
if ( ! F_9 ( & V_71 -> V_74 ) )
return false ;
F_50 ( V_71 -> V_77 , V_71 ) ;
F_17 ( & V_71 -> V_72 , V_95 ) ;
return true ;
}
static int F_66 ( struct V_70 * V_71 ,
struct V_94 * V_95 )
{
int V_96 = 0 ;
if ( F_35 ( V_75 , & V_71 -> V_76 ) ) {
F_3 ( L_21 , V_5 , V_71 ,
F_55 ( & V_71 -> V_74 ) ) ;
if ( F_65 ( V_71 , V_95 ) )
V_96 = 1 ;
}
return V_96 ;
}
int
F_39 ( struct V_33 * V_34 ,
struct V_94 * V_95 ,
struct V_61 * V_92 )
{
struct V_70 * V_71 , * V_97 ;
int V_98 = 0 , V_99 = 0 ;
F_3 ( L_22 , V_5 , V_34 ) ;
if ( F_24 ( & V_34 -> V_78 ) )
return 0 ;
F_67 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_92 ||
F_64 ( & V_71 -> V_100 , V_92 ) ) {
F_3 ( L_23
L_24 , V_5 ,
V_71 , V_71 -> V_100 . V_53 , V_71 -> V_100 . V_63 ,
V_71 -> V_100 . V_64 ) ;
V_98 ++ ;
V_99 += F_66 ( V_71 , V_95 ) ;
}
F_3 ( L_25 , V_5 , V_98 - V_99 ) ;
return V_98 - V_99 ;
}
void
F_40 ( struct V_94 * V_101 )
{
struct V_70 * V_71 , * V_27 ;
if ( F_24 ( V_101 ) )
return;
F_67 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_71 -> V_72 ) ;
F_49 ( V_71 ) ;
}
}
void
F_68 ( struct V_47 * V_48 )
{
struct V_33 * V_34 ;
F_38 ( V_95 ) ;
F_5 ( & V_48 -> V_102 . V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( V_34 ) {
V_34 -> V_103 ++ ;
F_39 ( V_34 , & V_95 , NULL ) ;
F_20 ( V_34 ) ;
F_34 ( V_34 , V_56 ) ;
F_34 ( V_34 , V_55 ) ;
F_7 ( & V_48 -> V_102 . V_52 ) ;
F_40 ( & V_95 ) ;
F_29 ( V_34 ) ;
} else
F_7 ( & V_48 -> V_102 . V_52 ) ;
}
static bool
F_69 ( struct V_36 * V_36 ,
struct V_94 * V_104 )
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
F_70 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_94 * V_104 )
{
struct V_33 * V_34 , * V_97 ;
struct V_36 * V_36 ;
F_67 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_71 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_69 ( V_36 , V_104 ) )
continue;
F_72 () ;
F_7 ( & V_43 -> V_44 ) ;
F_73 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_74 () ;
return - V_107 ;
}
return 0 ;
}
static int
F_75 ( struct V_94 * V_104 ,
bool V_108 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
struct V_61 V_62 = {
. V_53 = V_93 ,
. V_63 = 0 ,
. V_64 = V_65 ,
} ;
F_38 ( V_109 ) ;
int V_105 = 0 ;
while ( ! F_24 ( V_104 ) ) {
V_34 = F_76 ( V_104 -> V_97 , struct V_33 ,
V_106 ) ;
F_3 ( L_26 , V_5 ,
V_34 -> V_41 -> V_110 ) ;
V_36 = V_34 -> V_41 ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_106 ) ;
V_34 -> V_103 ++ ;
if ( V_108 )
F_48 ( V_79 , & V_34 -> V_60 ) ;
if ( F_39 ( V_34 , & V_109 , & V_62 ) )
V_105 = - V_107 ;
F_7 ( & V_36 -> V_52 ) ;
F_40 ( & V_109 ) ;
F_29 ( V_34 ) ;
F_73 ( V_36 ) ;
}
return V_105 ;
}
int
F_77 ( struct V_12 * V_43 ,
struct V_111 * V_112 ,
bool V_113 )
{
struct V_8 * V_14 ;
F_38 ( V_104 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_74 () ;
V_114:
F_78 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_112 , V_112 , sizeof( * V_112 ) ) != 0 )
continue;
if ( F_70 ( V_43 ,
V_14 ,
& V_104 ) != 0 )
goto V_114;
}
F_72 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_104 ) )
return 0 ;
return F_75 ( & V_104 , V_113 ) ;
}
int
F_79 ( struct V_12 * V_43 ,
bool V_113 )
{
struct V_8 * V_14 ;
F_38 ( V_104 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_74 () ;
V_114:
F_78 (server, &clp->cl_superblocks, client_link) {
if ( F_70 ( V_43 ,
V_14 ,
& V_104 ) != 0 )
goto V_114;
}
F_72 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_104 ) )
return 0 ;
return F_75 ( & V_104 , V_113 ) ;
}
void
F_80 ( struct V_12 * V_43 )
{
F_81 ( V_43 ) ;
F_10 ( V_43 ) ;
F_79 ( V_43 , false ) ;
}
static bool F_82 ( T_1 V_115 , T_1 V_116 )
{
return ( V_117 ) ( V_115 - V_116 ) > 0 ;
}
static void
F_83 ( struct V_33 * V_34 ,
const T_4 * V_118 ,
struct V_94 * V_119 )
{
if ( F_84 ( & V_34 -> V_120 , V_118 ) )
return;
F_39 ( V_34 , V_119 , NULL ) ;
}
void
F_85 ( struct V_33 * V_34 , const T_4 * V_118 ,
bool V_121 )
{
T_1 V_122 , V_123 , V_124 ;
int V_125 = F_24 ( & V_34 -> V_78 ) ;
V_122 = F_86 ( V_34 -> V_120 . V_126 ) ;
V_123 = F_86 ( V_118 -> V_126 ) ;
if ( V_125 || F_82 ( V_123 , V_122 ) ) {
F_87 ( & V_34 -> V_120 , V_118 ) ;
if ( V_121 ) {
V_124 = F_86 ( V_118 -> V_126 ) ;
} else {
V_124 = V_123 - F_55 ( & V_34 -> V_127 ) ;
}
if ( V_125 || F_82 ( V_124 , V_34 -> V_128 ) )
V_34 -> V_128 = V_124 ;
}
}
static bool
F_88 ( const struct V_33 * V_34 ,
const T_4 * V_129 )
{
T_1 V_126 = F_86 ( V_129 -> V_126 ) ;
return ! F_82 ( V_126 , V_34 -> V_128 ) ;
}
static bool
F_89 ( const struct V_33 * V_34 , int V_130 )
{
return V_34 -> V_103 ||
F_42 ( V_79 , & V_34 -> V_60 ) ||
( F_24 ( & V_34 -> V_78 ) &&
( F_55 ( & V_34 -> V_127 ) > V_130 ) ) ;
}
int
F_90 ( T_4 * V_131 , struct V_33 * V_34 ,
struct V_132 * V_133 )
{
int V_25 = 0 ;
F_3 ( L_27 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_89 ( V_34 , 1 ) ) {
V_25 = - V_107 ;
} else if ( ! F_91 ( V_133 ) ) {
V_25 = - V_134 ;
} else if ( F_24 ( & V_34 -> V_78 ) ) {
int V_135 ;
do {
V_135 = F_92 ( & V_133 -> V_136 ) ;
F_87 ( V_131 , & V_133 -> V_129 ) ;
} while ( F_93 ( & V_133 -> V_136 , V_135 ) );
} else
F_87 ( V_131 , & V_34 -> V_120 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_28 , V_5 ) ;
return V_25 ;
}
static struct V_70 *
F_94 ( struct V_33 * V_34 ,
struct V_137 * V_138 ,
struct V_61 * V_62 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_139 * V_140 ;
struct V_70 * V_71 ;
F_3 ( L_27 , V_5 ) ;
V_140 = F_95 ( sizeof( * V_140 ) , V_38 ) ;
if ( V_140 == NULL )
return NULL ;
V_140 -> args . V_141 = V_142 ;
if ( V_140 -> args . V_141 > V_62 -> V_64 )
V_140 -> args . V_141 = V_62 -> V_64 ;
V_140 -> args . V_143 = V_144 ;
V_140 -> args . V_62 = * V_62 ;
V_140 -> args . type = V_14 -> V_10 -> V_2 ;
V_140 -> args . V_36 = V_37 ;
V_140 -> args . V_138 = F_96 ( V_138 ) ;
V_140 -> V_38 = V_38 ;
V_140 -> V_145 = V_34 -> V_45 ;
V_71 = F_97 ( V_140 , V_38 ) ;
if ( F_98 ( V_71 ) ) {
switch ( F_99 ( V_71 ) ) {
case - V_146 :
case - V_147 :
break;
default:
F_37 ( V_34 , V_62 -> V_53 ) ;
}
return NULL ;
}
return V_71 ;
}
static void F_100 ( struct V_36 * V_36 ,
struct V_94 * V_66 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_70 * V_71 , * V_27 ;
if ( ! F_35 ( V_148 , & V_48 -> V_149 ) )
return;
F_67 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_35 ( V_150 , & V_71 -> V_76 ) )
continue;
F_65 ( V_71 , V_66 ) ;
}
}
int
F_101 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_38 ( V_95 ) ;
struct V_151 * V_152 ;
T_4 V_129 ;
int V_25 = 0 , V_125 ;
F_3 ( L_29 , V_5 , V_37 -> V_110 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_30 , V_5 ) ;
goto V_4;
}
V_129 = V_48 -> V_49 -> V_120 ;
F_20 ( V_34 ) ;
V_125 = F_24 ( & V_34 -> V_78 ) ;
F_100 ( V_37 , & V_95 ) ;
F_39 ( V_34 , & V_95 , NULL ) ;
if ( V_125 ) {
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
V_34 -> V_103 ++ ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_95 ) ;
V_152 = F_95 ( sizeof( * V_152 ) , V_153 ) ;
if ( F_102 ( V_152 == NULL ) ) {
V_25 = - V_146 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 -> V_103 -- ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_152 -> args . V_129 = V_129 ;
V_152 -> args . V_154 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_152 -> args . V_36 = V_37 ;
V_152 -> args . V_49 = V_34 ;
V_152 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_152 -> V_145 = V_34 -> V_45 ;
V_25 = F_103 ( V_152 ) ;
V_4:
F_3 ( L_32 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_104 ( struct V_36 * V_36 )
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
V_34 -> V_103 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_105 ( V_36 -> V_155 ) ;
V_105 = F_106 ( V_36 , true ) ;
if ( V_105 == 0 )
V_105 = F_101 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_103 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_105 ;
}
bool F_107 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
struct V_70 * V_71 , * V_27 ;
F_38 ( V_95 ) ;
bool V_156 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( ! V_34 || ! F_35 ( V_157 , & V_34 -> V_60 ) ||
F_42 ( V_79 , & V_34 -> V_60 ) )
goto V_158;
F_67 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_42 ( V_159 , & V_71 -> V_76 ) ) {
F_66 ( V_71 , & V_95 ) ;
V_156 = true ;
}
if ( ! V_156 )
goto V_158;
V_34 -> V_103 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_95 ) ;
return true ;
V_158:
F_7 ( & V_37 -> V_52 ) ;
return false ;
}
void F_108 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
V_34 -> V_103 -- ;
if ( F_9 ( & V_34 -> V_35 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_23 ( V_34 ) ;
} else
F_7 ( & V_37 -> V_52 ) ;
}
void F_109 ( struct V_36 * V_37 , T_1 V_160 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_82 ( V_160 , V_34 -> V_128 ) )
V_34 -> V_128 = V_160 ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_110 ( struct V_36 * V_37 , T_1 * V_160 , struct V_161 * V_162 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
struct V_70 * V_71 ;
T_1 V_163 ;
bool V_156 = false ;
F_5 ( & V_37 -> V_52 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_42 ( V_159 , & V_71 -> V_76 ) ) {
F_111 ( & F_22 ( V_37 ) -> V_80 , V_162 , NULL ) ;
V_156 = true ;
goto V_4;
}
V_34 = V_48 -> V_49 ;
V_163 = F_86 ( V_34 -> V_120 . V_126 ) ;
* V_160 = V_163 + F_55 ( & V_34 -> V_127 ) ;
V_4:
F_7 ( & V_37 -> V_52 ) ;
return V_156 ;
}
static T_5
F_112 ( const struct V_61 * V_85 ,
const struct V_61 * V_86 )
{
T_5 V_164 ;
V_164 = V_85 -> V_63 - V_86 -> V_63 ;
if ( V_164 )
return V_164 ;
V_164 = V_86 -> V_64 - V_85 -> V_64 ;
if ( V_164 )
return V_164 ;
return ( int ) ( V_85 -> V_53 == V_165 ) - ( int ) ( V_86 -> V_53 == V_165 ) ;
}
static void
F_113 ( struct V_33 * V_34 ,
struct V_70 * V_71 )
{
struct V_70 * V_166 ;
F_3 ( L_33 , V_5 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_112 ( & V_71 -> V_100 , & V_166 -> V_100 ) > 0 )
continue;
F_114 ( & V_71 -> V_72 , & V_166 -> V_72 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_71 , V_71 -> V_100 . V_53 ,
V_71 -> V_100 . V_63 , V_71 -> V_100 . V_64 ,
V_166 , V_166 -> V_100 . V_53 , V_166 -> V_100 . V_63 ,
V_166 -> V_100 . V_64 ) ;
goto V_4;
}
F_114 ( & V_71 -> V_72 , & V_34 -> V_78 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_71 , V_71 -> V_100 . V_53 ,
V_71 -> V_100 . V_63 , V_71 -> V_100 . V_64 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_38 , V_5 ) ;
}
static struct V_33 *
F_115 ( struct V_36 * V_37 ,
struct V_137 * V_138 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_46 ( & V_34 -> V_35 , 1 ) ;
F_45 ( & V_34 -> V_42 ) ;
F_45 ( & V_34 -> V_78 ) ;
F_45 ( & V_34 -> V_106 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_116 ( V_138 -> V_145 ) ;
return V_34 ;
}
static struct V_33 *
F_117 ( struct V_36 * V_37 ,
struct V_137 * V_138 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_118 = NULL ;
F_3 ( L_39 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_167;
F_7 ( & V_37 -> V_52 ) ;
V_118 = F_115 ( V_37 , V_138 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_118 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_118 ;
return V_118 ;
} else if ( V_118 != NULL )
F_23 ( V_118 ) ;
V_167:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_119 ( const struct V_61 * V_168 ,
const struct V_61 * V_62 )
{
struct V_61 V_169 ;
if ( ( V_62 -> V_53 == V_54 &&
V_168 -> V_53 != V_54 ) ||
! F_63 ( V_168 , V_62 ) )
return 0 ;
V_169 = * V_62 ;
V_169 . V_64 = 1 ;
return F_62 ( V_168 , & V_169 ) ;
}
static struct V_70 *
F_120 ( struct V_33 * V_34 ,
struct V_61 * V_62 )
{
struct V_70 * V_71 , * V_105 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_42 ( V_75 , & V_71 -> V_76 ) &&
F_119 ( & V_71 -> V_100 , V_62 ) ) {
V_105 = F_121 ( V_71 ) ;
break;
}
if ( V_71 -> V_100 . V_63 > V_62 -> V_63 )
break;
}
F_3 ( L_40 ,
V_5 , V_105 , V_105 ? F_55 ( & V_105 -> V_74 ) : 0 ) ;
return V_105 ;
}
static bool F_122 ( struct V_137 * V_138 ,
struct V_36 * V_37 , int V_53 )
{
struct V_170 * V_171 = V_138 -> V_172 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_6 V_173 = F_123 ( V_37 ) ;
bool V_174 = false , V_175 = false , V_176 = false , V_177 = false , V_105 = false ;
if ( V_171 == NULL )
return V_105 ;
F_3 ( L_41 ,
V_5 , V_171 -> V_178 , V_171 -> V_179 , V_171 -> V_180 , V_171 -> V_181 , V_171 -> V_182 ) ;
switch ( V_53 ) {
case V_165 :
if ( V_171 -> V_178 & V_183 ) {
F_3 ( L_42 , V_5 , V_173 ) ;
V_175 = true ;
if ( V_173 < V_171 -> V_179 )
V_174 = true ;
}
if ( V_171 -> V_178 & V_184 ) {
F_3 ( L_43 , V_5 ,
V_48 -> V_51 ) ;
V_177 = true ;
if ( V_48 -> V_51 < V_171 -> V_181 )
V_176 = true ;
}
break;
case V_54 :
if ( V_171 -> V_178 & V_185 ) {
F_3 ( L_42 , V_5 , V_173 ) ;
V_175 = true ;
if ( V_173 < V_171 -> V_180 )
V_174 = true ;
}
if ( V_171 -> V_178 & V_186 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_50 ) ;
V_177 = true ;
if ( V_48 -> V_50 < V_171 -> V_182 )
V_176 = true ;
}
break;
}
if ( V_175 && V_177 ) {
if ( V_174 && V_176 )
V_105 = true ;
} else if ( V_174 || V_176 )
V_105 = true ;
F_3 ( L_45 , V_5 , V_174 , V_176 , V_105 ) ;
return V_105 ;
}
struct V_70 *
F_124 ( struct V_36 * V_37 ,
struct V_137 * V_138 ,
T_6 V_187 ,
T_3 V_188 ,
enum V_189 V_53 ,
T_2 V_38 )
{
struct V_61 V_190 = {
. V_53 = V_53 ,
. V_63 = V_187 ,
. V_64 = V_188 ,
} ;
unsigned V_191 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_70 * V_71 = NULL ;
bool V_192 ;
if ( ! F_125 ( F_22 ( V_37 ) ) )
goto V_4;
if ( F_122 ( V_138 , V_37 , V_53 ) )
goto V_4;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_117 ( V_37 , V_138 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
goto V_4;
}
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_46 , V_5 ) ;
goto V_193;
}
if ( F_41 ( V_34 , V_53 ) )
goto V_193;
V_71 = F_120 ( V_34 , & V_190 ) ;
if ( V_71 )
goto V_193;
if ( F_89 ( V_34 , 0 ) )
goto V_193;
F_15 ( & V_34 -> V_127 ) ;
V_192 = F_24 ( & V_34 -> V_42 ) ? true : false ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_192 ) {
F_5 ( & V_43 -> V_44 ) ;
F_114 ( & V_34 -> V_42 , & V_14 -> V_194 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_191 = V_190 . V_63 & ~ V_195 ;
if ( V_191 ) {
V_190 . V_63 -= V_191 ;
V_190 . V_64 += V_191 ;
}
if ( V_190 . V_64 != V_65 )
V_190 . V_64 = F_126 ( V_190 . V_64 ) ;
V_71 = F_94 ( V_34 , V_138 , & V_190 , V_38 ) ;
F_36 ( & V_34 -> V_127 ) ;
V_196:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_47
L_48 ,
V_5 , V_37 -> V_197 -> V_198 ,
( unsigned long long ) F_127 ( V_37 ) ,
V_71 == NULL ? L_49 : L_50 ,
V_53 == V_54 ? L_51 : L_52 ,
( unsigned long long ) V_187 ,
( unsigned long long ) V_188 ) ;
return V_71 ;
V_193:
F_7 ( & V_37 -> V_52 ) ;
goto V_196;
}
struct V_70 *
F_128 ( struct V_139 * V_140 )
{
struct V_33 * V_34 = F_28 ( V_140 -> args . V_36 ) -> V_49 ;
struct V_199 * V_200 = & V_140 -> V_200 ;
struct V_70 * V_71 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_38 ( V_101 ) ;
int V_25 = 0 ;
V_71 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_200 , V_140 -> V_38 ) ;
if ( ! V_71 || F_98 ( V_71 ) ) {
if ( ! V_71 )
V_25 = - V_146 ;
else
V_25 = F_99 ( V_71 ) ;
F_3 ( L_53 ,
V_5 , V_25 ) ;
goto V_4;
}
F_5 ( & V_37 -> V_52 ) ;
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_54 , V_5 ) ;
goto V_201;
}
if ( F_89 ( V_34 , 1 ) ||
F_88 ( V_34 , & V_200 -> V_129 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_201;
}
F_83 ( V_34 , & V_200 -> V_129 , & V_101 ) ;
F_85 ( V_34 , & V_200 -> V_129 , false ) ;
F_44 ( V_34 , V_71 ) ;
V_71 -> V_100 = V_200 -> V_62 ;
F_121 ( V_71 ) ;
F_113 ( V_34 , V_71 ) ;
if ( V_200 -> V_202 ) {
F_48 ( V_159 , & V_71 -> V_76 ) ;
F_48 ( V_157 , & V_34 -> V_60 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_101 ) ;
return V_71 ;
V_4:
return F_129 ( V_25 ) ;
V_201:
F_7 ( & V_37 -> V_52 ) ;
V_71 -> V_77 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_71 ) ;
goto V_4;
}
void
F_130 ( struct V_203 * V_204 , struct V_205 * V_206 )
{
T_3 V_207 = V_206 -> V_208 ;
F_131 ( V_204 -> V_209 != NULL ) ;
if ( V_204 -> V_210 == NULL )
V_207 = F_123 ( V_204 -> V_211 ) - F_132 ( V_206 ) ;
else
V_207 = F_133 ( V_204 -> V_210 ) ;
V_204 -> V_209 = F_124 ( V_204 -> V_211 ,
V_206 -> V_212 ,
F_132 ( V_206 ) ,
V_207 ,
V_165 ,
V_153 ) ;
if ( V_204 -> V_209 == NULL )
F_134 ( V_204 ) ;
}
void
F_135 ( struct V_203 * V_204 ,
struct V_205 * V_206 , T_3 V_213 )
{
F_131 ( V_204 -> V_209 != NULL ) ;
V_204 -> V_209 = F_124 ( V_204 -> V_211 ,
V_206 -> V_212 ,
F_132 ( V_206 ) ,
V_213 ,
V_54 ,
V_214 ) ;
if ( V_204 -> V_209 == NULL )
F_136 ( V_204 ) ;
}
T_7
F_137 ( struct V_203 * V_204 , struct V_205 * V_215 ,
struct V_205 * V_206 )
{
unsigned int V_174 ;
T_3 V_216 , V_217 , V_218 ;
V_174 = F_138 ( V_204 , V_215 , V_206 ) ;
if ( ! V_174 )
return 0 ;
if ( V_204 -> V_209 ) {
V_216 = F_61 ( V_204 -> V_209 -> V_100 . V_63 ,
V_204 -> V_209 -> V_100 . V_64 ) ;
V_217 = F_132 ( V_206 ) ;
F_131 ( V_217 > V_216 ) ;
if ( V_217 >= V_216 )
return 0 ;
V_218 = V_216 - V_217 ;
if ( V_218 < V_174 )
V_174 = ( unsigned int ) V_218 ;
}
return V_174 ;
}
int F_139 ( struct V_219 * V_220 )
{
struct V_203 V_204 ;
F_140 ( & V_204 , V_220 -> V_36 , V_221 , true ,
V_220 -> V_222 ) ;
return F_141 ( & V_204 , V_220 ) ;
}
static void F_142 ( struct V_219 * V_220 )
{
F_3 ( L_56 , V_220 -> V_223 ) ;
if ( F_22 ( V_220 -> V_36 ) -> V_10 -> V_149 &
V_224 ) {
F_143 ( V_220 -> V_36 ) ;
}
if ( ! F_33 ( V_225 , & V_220 -> V_149 ) )
V_220 -> V_162 . V_226 = F_139 ( V_220 ) ;
}
void F_144 ( struct V_219 * V_220 )
{
F_145 ( V_220 , V_220 -> V_223 ) ;
if ( ! V_220 -> V_223 ) {
F_146 ( V_220 ) ;
V_220 -> V_227 -> V_228 ( & V_220 -> V_162 , V_220 ) ;
} else
F_142 ( V_220 ) ;
V_220 -> V_227 -> V_229 ( V_220 ) ;
}
static void
F_147 ( struct V_203 * V_230 ,
struct V_219 * V_220 )
{
if ( ! F_33 ( V_225 , & V_220 -> V_149 ) ) {
F_148 ( & V_220 -> V_231 , & V_230 -> V_232 ) ;
F_136 ( V_230 ) ;
V_230 -> V_233 = 1 ;
}
F_149 ( V_220 ) ;
}
static enum V_234
F_150 ( struct V_219 * V_220 ,
const struct V_235 * V_236 ,
struct V_70 * V_71 ,
int V_237 )
{
struct V_36 * V_36 = V_220 -> V_36 ;
enum V_234 V_238 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_220 -> V_227 = V_236 ;
F_3 ( L_57 , V_5 ,
V_36 -> V_110 , V_220 -> args . V_188 , V_220 -> args . V_63 , V_237 ) ;
V_238 = V_9 -> V_10 -> V_239 ( V_220 , V_237 ) ;
if ( V_238 != V_240 )
F_151 ( V_36 , V_241 ) ;
F_3 ( L_58 , V_5 , V_238 ) ;
return V_238 ;
}
static void
F_152 ( struct V_203 * V_230 ,
struct V_219 * V_220 , int V_237 )
{
const struct V_235 * V_236 = V_230 -> V_242 ;
struct V_70 * V_71 = V_230 -> V_209 ;
enum V_234 V_238 ;
V_230 -> V_209 = NULL ;
V_238 = F_150 ( V_220 , V_236 , V_71 , V_237 ) ;
if ( V_238 == V_240 )
F_147 ( V_230 , V_220 ) ;
F_54 ( V_71 ) ;
}
static void F_153 ( struct V_219 * V_220 )
{
F_54 ( V_220 -> V_71 ) ;
F_154 ( V_220 ) ;
}
int
F_155 ( struct V_203 * V_230 )
{
struct V_219 * V_220 ;
int V_105 ;
V_220 = F_156 ( V_230 -> V_243 ) ;
if ( ! V_220 ) {
V_230 -> V_244 -> V_245 ( & V_230 -> V_232 ) ;
F_54 ( V_230 -> V_209 ) ;
V_230 -> V_209 = NULL ;
return - V_146 ;
}
F_157 ( V_230 , V_220 , F_153 ) ;
V_220 -> V_71 = F_121 ( V_230 -> V_209 ) ;
V_105 = F_158 ( V_230 , V_220 ) ;
if ( V_105 != 0 ) {
F_54 ( V_230 -> V_209 ) ;
V_230 -> V_209 = NULL ;
} else
F_152 ( V_230 , V_220 , V_230 -> V_246 ) ;
return V_105 ;
}
int F_159 ( struct V_219 * V_220 )
{
struct V_203 V_204 ;
F_160 ( & V_204 , V_220 -> V_36 , true , V_220 -> V_222 ) ;
return F_141 ( & V_204 , V_220 ) ;
}
static void F_161 ( struct V_219 * V_220 )
{
F_3 ( L_59 , V_220 -> V_223 ) ;
if ( F_22 ( V_220 -> V_36 ) -> V_10 -> V_149 &
V_224 ) {
F_143 ( V_220 -> V_36 ) ;
}
if ( ! F_33 ( V_225 , & V_220 -> V_149 ) )
V_220 -> V_162 . V_226 = F_159 ( V_220 ) ;
}
void F_162 ( struct V_219 * V_220 )
{
F_163 ( V_220 , V_220 -> V_223 ) ;
if ( F_118 ( ! V_220 -> V_223 ) ) {
F_164 ( V_220 ) ;
V_220 -> V_227 -> V_228 ( & V_220 -> V_162 , V_220 ) ;
} else
F_161 ( V_220 ) ;
V_220 -> V_227 -> V_229 ( V_220 ) ;
}
static void
F_165 ( struct V_203 * V_230 ,
struct V_219 * V_220 )
{
if ( ! F_33 ( V_225 , & V_220 -> V_149 ) ) {
F_148 ( & V_220 -> V_231 , & V_230 -> V_232 ) ;
F_134 ( V_230 ) ;
V_230 -> V_233 = 1 ;
}
F_149 ( V_220 ) ;
}
static enum V_234
F_166 ( struct V_219 * V_220 ,
const struct V_235 * V_236 ,
struct V_70 * V_71 )
{
struct V_36 * V_36 = V_220 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_234 V_238 ;
V_220 -> V_227 = V_236 ;
F_3 ( L_60 ,
V_5 , V_36 -> V_110 , V_220 -> args . V_188 , V_220 -> args . V_63 ) ;
V_238 = V_9 -> V_10 -> V_247 ( V_220 ) ;
if ( V_238 != V_240 )
F_151 ( V_36 , V_248 ) ;
F_3 ( L_58 , V_5 , V_238 ) ;
return V_238 ;
}
static void
F_167 ( struct V_203 * V_230 , struct V_219 * V_220 )
{
const struct V_235 * V_236 = V_230 -> V_242 ;
struct V_70 * V_71 = V_230 -> V_209 ;
enum V_234 V_238 ;
V_230 -> V_209 = NULL ;
V_238 = F_166 ( V_220 , V_236 , V_71 ) ;
if ( V_238 == V_240 )
F_165 ( V_230 , V_220 ) ;
F_54 ( V_71 ) ;
}
static void F_168 ( struct V_219 * V_220 )
{
F_54 ( V_220 -> V_71 ) ;
F_154 ( V_220 ) ;
}
int
F_169 ( struct V_203 * V_230 )
{
struct V_219 * V_220 ;
int V_105 ;
V_220 = F_156 ( V_230 -> V_243 ) ;
if ( ! V_220 ) {
V_230 -> V_244 -> V_245 ( & V_230 -> V_232 ) ;
V_105 = - V_146 ;
F_54 ( V_230 -> V_209 ) ;
V_230 -> V_209 = NULL ;
return V_105 ;
}
F_157 ( V_230 , V_220 , F_168 ) ;
V_220 -> V_71 = F_121 ( V_230 -> V_209 ) ;
V_105 = F_158 ( V_230 , V_220 ) ;
if ( V_105 != 0 ) {
F_54 ( V_230 -> V_209 ) ;
V_230 -> V_209 = NULL ;
} else
F_167 ( V_230 , V_220 ) ;
return V_105 ;
}
static void F_170 ( struct V_36 * V_36 )
{
unsigned long * V_249 = & F_28 ( V_36 ) -> V_149 ;
F_171 ( V_250 , V_249 ) ;
F_172 () ;
F_173 ( V_249 , V_250 ) ;
}
static void F_174 ( struct V_36 * V_36 , struct V_94 * V_251 )
{
struct V_70 * V_71 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_71 -> V_100 . V_53 == V_54 &&
F_35 ( V_150 , & V_71 -> V_76 ) )
F_17 ( & V_71 -> V_73 , V_251 ) ;
}
}
static void F_175 ( struct V_36 * V_36 , struct V_94 * V_251 )
{
struct V_70 * V_71 , * V_27 ;
F_67 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_71 -> V_73 ) ;
F_54 ( V_71 ) ;
}
F_170 ( V_36 ) ;
}
void F_176 ( struct V_70 * V_71 )
{
F_37 ( V_71 -> V_77 , V_71 -> V_100 . V_53 ) ;
}
void
F_146 ( struct V_219 * V_220 )
{
struct V_36 * V_36 = V_220 -> V_36 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_252 = V_220 -> V_253 + V_220 -> V_200 . V_188 ;
bool V_254 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_33 ( V_148 , & V_48 -> V_149 ) ) {
V_254 = true ;
F_3 ( L_61 ,
V_5 , V_36 -> V_110 ) ;
}
if ( ! F_33 ( V_150 , & V_220 -> V_71 -> V_76 ) ) {
F_121 ( V_220 -> V_71 ) ;
}
if ( V_252 > V_48 -> V_49 -> V_255 )
V_48 -> V_49 -> V_255 = V_252 ;
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_62 ,
V_5 , V_220 -> V_71 , V_48 -> V_49 -> V_255 ) ;
if ( V_254 )
F_177 ( V_36 ) ;
}
void F_178 ( struct V_256 * V_257 )
{
struct V_8 * V_9 = F_22 ( V_257 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_258 )
V_9 -> V_10 -> V_258 ( V_257 ) ;
F_175 ( V_257 -> args . V_36 , & V_257 -> V_109 ) ;
}
int
F_106 ( struct V_36 * V_36 , bool V_259 )
{
struct V_256 * V_257 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_252 ;
int V_25 ;
if ( ! F_179 ( V_36 ) )
return 0 ;
F_3 ( L_63 , V_5 , V_36 -> V_110 ) ;
V_25 = - V_107 ;
if ( F_33 ( V_250 , & V_48 -> V_149 ) ) {
if ( ! V_259 )
goto V_4;
V_25 = F_180 ( & V_48 -> V_149 ,
V_250 ,
V_260 ,
V_261 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_146 ;
V_257 = F_95 ( sizeof( * V_257 ) , V_214 ) ;
if ( ! V_257 )
goto V_262;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_35 ( V_148 , & V_48 -> V_149 ) )
goto V_193;
F_45 ( & V_257 -> V_109 ) ;
F_174 ( V_36 , & V_257 -> V_109 ) ;
V_252 = V_48 -> V_49 -> V_255 ;
V_48 -> V_49 -> V_255 = 0 ;
F_87 ( & V_257 -> args . V_129 , & V_48 -> V_49 -> V_120 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_257 -> args . V_36 = V_36 ;
V_257 -> V_145 = F_116 ( V_48 -> V_49 -> V_45 ) ;
F_181 ( & V_257 -> V_263 ) ;
V_257 -> args . V_264 = F_22 ( V_36 ) -> V_265 ;
V_257 -> V_200 . V_263 = & V_257 -> V_263 ;
V_257 -> args . V_266 = V_252 - 1 ;
V_257 -> V_200 . V_14 = F_22 ( V_36 ) ;
V_25 = F_182 ( V_257 , V_259 ) ;
V_4:
if ( V_25 )
F_177 ( V_36 ) ;
F_3 ( L_64 , V_5 , V_25 ) ;
return V_25 ;
V_193:
F_7 ( & V_36 -> V_52 ) ;
F_183 ( V_257 ) ;
V_262:
F_170 ( V_36 ) ;
goto V_4;
}
struct V_170 * F_184 ( void )
{
struct V_170 * V_267 ;
V_267 = F_95 ( sizeof( * V_267 ) , V_214 ) ;
if ( ! V_267 ) {
F_3 ( L_65 , V_5 ) ;
return NULL ;
}
return V_267 ;
}
