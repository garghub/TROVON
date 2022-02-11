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
struct V_33 * V_34 ;
V_71 = F_57 ( V_82 , struct V_70 , V_83 ) ;
V_34 = V_71 -> V_77 ;
F_49 ( V_71 ) ;
F_29 ( V_34 ) ;
}
static void F_58 ( struct V_70 * V_71 )
{
F_59 ( & V_71 -> V_83 , F_56 ) ;
F_60 ( & V_71 -> V_83 ) ;
}
void
F_61 ( struct V_70 * V_71 )
{
if ( ! V_71 )
return;
F_62 ( & V_71 -> V_77 -> V_41 -> V_52 ) ;
F_3 ( L_20 , V_5 , V_71 ,
F_55 ( & V_71 -> V_74 ) ,
F_42 ( V_75 , & V_71 -> V_76 ) ) ;
if ( F_9 ( & V_71 -> V_74 ) ) {
struct V_33 * V_34 = V_71 -> V_77 ;
F_20 ( V_34 ) ;
F_50 ( V_34 , V_71 ) ;
F_58 ( V_71 ) ;
}
}
static T_3
F_63 ( T_3 V_67 , T_3 V_84 )
{
T_3 V_68 ;
V_68 = V_67 + V_84 ;
return V_68 >= V_67 ? V_68 : V_65 ;
}
static bool
F_64 ( const struct V_61 * V_85 ,
const struct V_61 * V_86 )
{
T_3 V_87 = V_85 -> V_63 ;
T_3 V_88 = F_63 ( V_87 , V_85 -> V_64 ) ;
T_3 V_89 = V_86 -> V_63 ;
T_3 V_90 = F_63 ( V_89 , V_86 -> V_64 ) ;
return ( V_87 <= V_89 ) && ( V_88 >= V_90 ) ;
}
static bool
F_65 ( const struct V_61 * V_85 ,
const struct V_61 * V_86 )
{
T_3 V_87 = V_85 -> V_63 ;
T_3 V_88 = F_63 ( V_87 , V_85 -> V_64 ) ;
T_3 V_89 = V_86 -> V_63 ;
T_3 V_90 = F_63 ( V_89 , V_86 -> V_64 ) ;
return ( V_88 == V_65 || V_88 > V_89 ) &&
( V_90 == V_65 || V_90 > V_87 ) ;
}
static bool
F_66 ( const struct V_61 * V_91 ,
const struct V_61 * V_92 )
{
return ( V_92 -> V_53 == V_93 ||
V_91 -> V_53 == V_92 -> V_53 ) &&
F_65 ( V_91 , V_92 ) ;
}
static bool F_67 ( struct V_70 * V_71 ,
struct V_94 * V_95 )
{
if ( ! F_9 ( & V_71 -> V_74 ) )
return false ;
F_50 ( V_71 -> V_77 , V_71 ) ;
F_17 ( & V_71 -> V_72 , V_95 ) ;
return true ;
}
static int F_68 ( struct V_70 * V_71 ,
struct V_94 * V_95 )
{
int V_96 = 0 ;
if ( F_35 ( V_75 , & V_71 -> V_76 ) ) {
F_3 ( L_21 , V_5 , V_71 ,
F_55 ( & V_71 -> V_74 ) ) ;
if ( F_67 ( V_71 , V_95 ) )
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
F_69 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_92 ||
F_66 ( & V_71 -> V_100 , V_92 ) ) {
F_3 ( L_23
L_24 , V_5 ,
V_71 , V_71 -> V_100 . V_53 , V_71 -> V_100 . V_63 ,
V_71 -> V_100 . V_64 ) ;
V_98 ++ ;
V_99 += F_68 ( V_71 , V_95 ) ;
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
F_69 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_71 -> V_72 ) ;
F_49 ( V_71 ) ;
}
}
void
F_70 ( struct V_47 * V_48 )
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
F_71 ( struct V_36 * V_36 ,
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
F_72 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_94 * V_104 )
{
struct V_33 * V_34 , * V_97 ;
struct V_36 * V_36 ;
F_69 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_73 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_71 ( V_36 , V_104 ) )
continue;
F_74 () ;
F_7 ( & V_43 -> V_44 ) ;
F_75 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_76 () ;
return - V_107 ;
}
return 0 ;
}
static int
F_77 ( struct V_94 * V_104 ,
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
V_34 = F_78 ( V_104 -> V_97 , struct V_33 ,
V_106 ) ;
F_3 ( L_26 , V_5 ,
V_34 -> V_41 -> V_110 ) ;
V_36 = V_34 -> V_41 ;
F_79 ( V_36 , false ) ;
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
F_75 ( V_36 ) ;
}
return V_105 ;
}
int
F_80 ( struct V_12 * V_43 ,
struct V_111 * V_112 ,
bool V_113 )
{
struct V_8 * V_14 ;
F_38 ( V_104 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_76 () ;
V_114:
F_81 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_112 , V_112 , sizeof( * V_112 ) ) != 0 )
continue;
if ( F_72 ( V_43 ,
V_14 ,
& V_104 ) != 0 )
goto V_114;
}
F_74 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_104 ) )
return 0 ;
return F_77 ( & V_104 , V_113 ) ;
}
int
F_82 ( struct V_12 * V_43 ,
bool V_113 )
{
struct V_8 * V_14 ;
F_38 ( V_104 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_76 () ;
V_114:
F_81 (server, &clp->cl_superblocks, client_link) {
if ( F_72 ( V_43 ,
V_14 ,
& V_104 ) != 0 )
goto V_114;
}
F_74 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_104 ) )
return 0 ;
return F_77 ( & V_104 , V_113 ) ;
}
void
F_83 ( struct V_12 * V_43 )
{
F_84 ( V_43 ) ;
F_10 ( V_43 ) ;
F_82 ( V_43 , false ) ;
}
static bool F_85 ( T_1 V_115 , T_1 V_116 )
{
return ( V_117 ) ( V_115 - V_116 ) > 0 ;
}
void
F_86 ( struct V_33 * V_34 , const T_4 * V_118 ,
bool V_119 )
{
T_1 V_120 , V_121 , V_122 ;
int V_123 = F_24 ( & V_34 -> V_78 ) ;
V_120 = F_87 ( V_34 -> V_124 . V_125 ) ;
V_121 = F_87 ( V_118 -> V_125 ) ;
if ( V_123 || F_85 ( V_121 , V_120 ) ) {
F_88 ( & V_34 -> V_124 , V_118 ) ;
if ( V_119 ) {
V_122 = F_87 ( V_118 -> V_125 ) ;
} else {
V_122 = V_121 - F_55 ( & V_34 -> V_126 ) ;
}
if ( V_123 || F_85 ( V_122 , V_34 -> V_127 ) )
V_34 -> V_127 = V_122 ;
}
}
static bool
F_89 ( const struct V_33 * V_34 ,
const T_4 * V_128 )
{
T_1 V_125 = F_87 ( V_128 -> V_125 ) ;
return ! F_85 ( V_125 , V_34 -> V_127 ) ;
}
static bool
F_90 ( const struct V_33 * V_34 , int V_129 )
{
return V_34 -> V_103 ||
F_42 ( V_79 , & V_34 -> V_60 ) ||
( F_24 ( & V_34 -> V_78 ) &&
( F_55 ( & V_34 -> V_126 ) > V_129 ) ) ;
}
int
F_91 ( T_4 * V_130 , struct V_33 * V_34 ,
struct V_131 * V_132 )
{
int V_25 = 0 ;
F_3 ( L_27 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_90 ( V_34 , 1 ) ) {
V_25 = - V_107 ;
} else if ( ! F_92 ( V_132 ) ) {
V_25 = - V_133 ;
} else if ( F_24 ( & V_34 -> V_78 ) ||
F_42 ( V_134 , & V_34 -> V_60 ) ) {
int V_135 ;
do {
V_135 = F_93 ( & V_132 -> V_136 ) ;
F_88 ( V_130 , & V_132 -> V_128 ) ;
} while ( F_94 ( & V_132 -> V_136 , V_135 ) );
} else
F_88 ( V_130 , & V_34 -> V_124 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_28 , V_5 ) ;
return V_25 ;
}
static struct V_70 *
F_95 ( struct V_33 * V_34 ,
struct V_137 * V_138 ,
struct V_61 * V_62 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_139 * V_140 ;
struct V_70 * V_71 ;
F_3 ( L_27 , V_5 ) ;
V_140 = F_96 ( sizeof( * V_140 ) , V_38 ) ;
if ( V_140 == NULL )
return NULL ;
V_140 -> args . V_141 = V_142 ;
if ( V_140 -> args . V_141 > V_62 -> V_64 )
V_140 -> args . V_141 = V_62 -> V_64 ;
V_140 -> args . V_143 = V_144 ;
V_140 -> args . V_62 = * V_62 ;
V_140 -> args . type = V_14 -> V_10 -> V_2 ;
V_140 -> args . V_36 = V_37 ;
V_140 -> args . V_138 = F_97 ( V_138 ) ;
V_140 -> V_38 = V_38 ;
V_140 -> V_145 = V_34 -> V_45 ;
V_71 = F_98 ( V_140 , V_38 ) ;
if ( F_99 ( V_71 ) ) {
switch ( F_100 ( V_71 ) ) {
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
static void F_101 ( struct V_36 * V_36 ,
struct V_94 * V_66 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_70 * V_71 , * V_27 ;
if ( ! F_35 ( V_148 , & V_48 -> V_149 ) )
return;
F_69 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_35 ( V_150 , & V_71 -> V_76 ) )
continue;
F_67 ( V_71 , V_66 ) ;
}
}
int
F_102 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_38 ( V_95 ) ;
struct V_151 * V_152 ;
T_4 V_128 ;
int V_25 = 0 , V_123 ;
F_3 ( L_29 , V_5 , V_37 -> V_110 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_30 , V_5 ) ;
goto V_4;
}
V_128 = V_48 -> V_49 -> V_124 ;
F_20 ( V_34 ) ;
V_123 = F_24 ( & V_34 -> V_78 ) ;
F_101 ( V_37 , & V_95 ) ;
F_39 ( V_34 , & V_95 , NULL ) ;
if ( F_22 ( V_37 ) -> V_10 -> V_153 ) {
struct V_61 V_62 = {
. V_53 = V_93 ,
. V_63 = 0 ,
. V_64 = V_65 ,
} ;
F_22 ( V_37 ) -> V_10 -> V_153 ( V_34 , & V_62 ) ;
}
if ( V_123 ) {
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
F_48 ( V_134 , & V_34 -> V_60 ) ;
V_34 -> V_103 ++ ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_95 ) ;
V_152 = F_96 ( sizeof( * V_152 ) , V_154 ) ;
if ( F_103 ( V_152 == NULL ) ) {
V_25 = - V_146 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 -> V_103 -- ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_152 -> args . V_128 = V_128 ;
V_152 -> args . V_155 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_152 -> args . V_36 = V_37 ;
V_152 -> args . V_49 = V_34 ;
V_152 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_152 -> V_145 = V_34 -> V_45 ;
V_25 = F_104 ( V_152 ) ;
V_4:
F_3 ( L_32 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_105 ( struct V_36 * V_36 )
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
F_106 ( V_36 -> V_156 ) ;
V_105 = F_79 ( V_36 , true ) ;
if ( V_105 == 0 )
V_105 = F_102 ( V_36 ) ;
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
bool V_157 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( ! V_34 || ! F_35 ( V_158 , & V_34 -> V_60 ) ||
F_42 ( V_79 , & V_34 -> V_60 ) )
goto V_159;
F_69 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_42 ( V_160 , & V_71 -> V_76 ) ) {
F_68 ( V_71 , & V_95 ) ;
V_157 = true ;
}
if ( ! V_157 )
goto V_159;
V_34 -> V_103 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_95 ) ;
return true ;
V_159:
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
void F_109 ( struct V_36 * V_37 , T_1 V_161 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_85 ( V_161 , V_34 -> V_127 ) )
V_34 -> V_127 = V_161 ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_110 ( struct V_36 * V_37 , T_1 * V_161 , struct V_162 * V_163 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
struct V_70 * V_71 ;
T_1 V_164 ;
bool V_157 = false ;
F_5 ( & V_37 -> V_52 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_42 ( V_160 , & V_71 -> V_76 ) ) {
F_111 ( & F_22 ( V_37 ) -> V_80 , V_163 , NULL ) ;
V_157 = true ;
goto V_4;
}
V_34 = V_48 -> V_49 ;
V_164 = F_87 ( V_34 -> V_124 . V_125 ) ;
* V_161 = V_164 + F_55 ( & V_34 -> V_126 ) ;
V_4:
F_7 ( & V_37 -> V_52 ) ;
return V_157 ;
}
static T_5
F_112 ( const struct V_61 * V_85 ,
const struct V_61 * V_86 )
{
T_5 V_165 ;
V_165 = V_85 -> V_63 - V_86 -> V_63 ;
if ( V_165 )
return V_165 ;
V_165 = V_86 -> V_64 - V_85 -> V_64 ;
if ( V_165 )
return V_165 ;
return ( int ) ( V_85 -> V_53 == V_166 ) - ( int ) ( V_86 -> V_53 == V_166 ) ;
}
static void
F_113 ( struct V_33 * V_34 ,
struct V_70 * V_71 )
{
struct V_70 * V_167 ;
F_3 ( L_33 , V_5 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_112 ( & V_71 -> V_100 , & V_167 -> V_100 ) > 0 )
continue;
F_114 ( & V_71 -> V_72 , & V_167 -> V_72 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_71 , V_71 -> V_100 . V_53 ,
V_71 -> V_100 . V_63 , V_71 -> V_100 . V_64 ,
V_167 , V_167 -> V_100 . V_53 , V_167 -> V_100 . V_63 ,
V_167 -> V_100 . V_64 ) ;
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
goto V_168;
F_7 ( & V_37 -> V_52 ) ;
V_118 = F_115 ( V_37 , V_138 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_118 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_118 ;
return V_118 ;
} else if ( V_118 != NULL )
F_23 ( V_118 ) ;
V_168:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_119 ( const struct V_61 * V_169 ,
const struct V_61 * V_62 )
{
struct V_61 V_170 ;
if ( ( V_62 -> V_53 == V_54 &&
V_169 -> V_53 != V_54 ) ||
! F_65 ( V_169 , V_62 ) )
return 0 ;
V_170 = * V_62 ;
V_170 . V_64 = 1 ;
return F_64 ( V_169 , & V_170 ) ;
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
struct V_171 * V_172 = V_138 -> V_173 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_6 V_174 = F_123 ( V_37 ) ;
bool V_175 = false , V_176 = false , V_177 = false , V_178 = false , V_105 = false ;
if ( V_172 == NULL )
return V_105 ;
F_3 ( L_41 ,
V_5 , V_172 -> V_179 , V_172 -> V_180 , V_172 -> V_181 , V_172 -> V_182 , V_172 -> V_183 ) ;
switch ( V_53 ) {
case V_166 :
if ( V_172 -> V_179 & V_184 ) {
F_3 ( L_42 , V_5 , V_174 ) ;
V_176 = true ;
if ( V_174 < V_172 -> V_180 )
V_175 = true ;
}
if ( V_172 -> V_179 & V_185 ) {
F_3 ( L_43 , V_5 ,
V_48 -> V_51 ) ;
V_178 = true ;
if ( V_48 -> V_51 < V_172 -> V_182 )
V_177 = true ;
}
break;
case V_54 :
if ( V_172 -> V_179 & V_186 ) {
F_3 ( L_42 , V_5 , V_174 ) ;
V_176 = true ;
if ( V_174 < V_172 -> V_181 )
V_175 = true ;
}
if ( V_172 -> V_179 & V_187 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_50 ) ;
V_178 = true ;
if ( V_48 -> V_50 < V_172 -> V_183 )
V_177 = true ;
}
break;
}
if ( V_176 && V_178 ) {
if ( V_175 && V_177 )
V_105 = true ;
} else if ( V_175 || V_177 )
V_105 = true ;
F_3 ( L_45 , V_5 , V_175 , V_177 , V_105 ) ;
return V_105 ;
}
struct V_70 *
F_124 ( struct V_36 * V_37 ,
struct V_137 * V_138 ,
T_6 V_188 ,
T_3 V_189 ,
enum V_190 V_53 ,
T_2 V_38 )
{
struct V_61 V_191 = {
. V_53 = V_53 ,
. V_63 = V_188 ,
. V_64 = V_189 ,
} ;
unsigned V_192 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_70 * V_71 = NULL ;
bool V_193 ;
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
goto V_194;
}
if ( F_41 ( V_34 , V_53 ) )
goto V_194;
V_71 = F_120 ( V_34 , & V_191 ) ;
if ( V_71 )
goto V_194;
if ( F_90 ( V_34 , 0 ) )
goto V_194;
F_15 ( & V_34 -> V_126 ) ;
V_193 = F_24 ( & V_34 -> V_42 ) ? true : false ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_193 ) {
F_5 ( & V_43 -> V_44 ) ;
F_114 ( & V_34 -> V_42 , & V_14 -> V_195 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_192 = V_191 . V_63 & ~ V_196 ;
if ( V_192 ) {
V_191 . V_63 -= V_192 ;
V_191 . V_64 += V_192 ;
}
if ( V_191 . V_64 != V_65 )
V_191 . V_64 = F_126 ( V_191 . V_64 ) ;
V_71 = F_95 ( V_34 , V_138 , & V_191 , V_38 ) ;
F_36 ( & V_34 -> V_126 ) ;
V_197:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_47
L_48 ,
V_5 , V_37 -> V_198 -> V_199 ,
( unsigned long long ) F_127 ( V_37 ) ,
V_71 == NULL ? L_49 : L_50 ,
V_53 == V_54 ? L_51 : L_52 ,
( unsigned long long ) V_188 ,
( unsigned long long ) V_189 ) ;
return V_71 ;
V_194:
F_7 ( & V_37 -> V_52 ) ;
goto V_197;
}
struct V_70 *
F_128 ( struct V_139 * V_140 )
{
struct V_33 * V_34 = F_28 ( V_140 -> args . V_36 ) -> V_49 ;
struct V_200 * V_201 = & V_140 -> V_201 ;
struct V_70 * V_71 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_38 ( V_101 ) ;
int V_25 = 0 ;
V_71 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_201 , V_140 -> V_38 ) ;
if ( ! V_71 || F_99 ( V_71 ) ) {
if ( ! V_71 )
V_25 = - V_146 ;
else
V_25 = F_100 ( V_71 ) ;
F_3 ( L_53 ,
V_5 , V_25 ) ;
goto V_4;
}
F_44 ( V_34 , V_71 ) ;
V_71 -> V_100 = V_201 -> V_62 ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_54 , V_5 ) ;
goto V_202;
}
if ( F_90 ( V_34 , 1 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_202;
}
if ( F_129 ( & V_34 -> V_124 , & V_201 -> V_128 ) ) {
if ( F_89 ( V_34 , & V_201 -> V_128 ) ) {
F_3 ( L_56 , V_5 ) ;
goto V_202;
}
F_86 ( V_34 , & V_201 -> V_128 , false ) ;
} else {
F_39 ( V_34 , & V_101 , NULL ) ;
F_88 ( & V_34 -> V_124 , & V_201 -> V_128 ) ;
V_34 -> V_127 = F_87 ( V_201 -> V_128 . V_125 ) ;
}
F_52 ( V_134 , & V_34 -> V_60 ) ;
F_121 ( V_71 ) ;
F_113 ( V_34 , V_71 ) ;
if ( V_201 -> V_203 ) {
F_48 ( V_160 , & V_71 -> V_76 ) ;
F_48 ( V_158 , & V_34 -> V_60 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_101 ) ;
return V_71 ;
V_4:
return F_130 ( V_25 ) ;
V_202:
F_7 ( & V_37 -> V_52 ) ;
V_71 -> V_77 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_71 ) ;
goto V_4;
}
void
F_131 ( struct V_204 * V_205 , struct V_206 * V_207 )
{
T_3 V_208 = V_207 -> V_209 ;
F_132 ( V_205 -> V_210 != NULL ) ;
if ( V_205 -> V_211 == NULL )
V_208 = F_123 ( V_205 -> V_212 ) - F_133 ( V_207 ) ;
else
V_208 = F_134 ( V_205 -> V_211 ) ;
V_205 -> V_210 = F_124 ( V_205 -> V_212 ,
V_207 -> V_213 ,
F_133 ( V_207 ) ,
V_208 ,
V_166 ,
V_154 ) ;
if ( V_205 -> V_210 == NULL )
F_135 ( V_205 ) ;
}
void
F_136 ( struct V_204 * V_205 ,
struct V_206 * V_207 , T_3 V_214 )
{
F_132 ( V_205 -> V_210 != NULL ) ;
V_205 -> V_210 = F_124 ( V_205 -> V_212 ,
V_207 -> V_213 ,
F_133 ( V_207 ) ,
V_214 ,
V_54 ,
V_215 ) ;
if ( V_205 -> V_210 == NULL )
F_137 ( V_205 ) ;
}
T_7
F_138 ( struct V_204 * V_205 , struct V_206 * V_216 ,
struct V_206 * V_207 )
{
unsigned int V_175 ;
T_3 V_217 , V_218 , V_219 ;
V_175 = F_139 ( V_205 , V_216 , V_207 ) ;
if ( ! V_175 )
return 0 ;
if ( V_205 -> V_210 ) {
V_217 = F_63 ( V_205 -> V_210 -> V_100 . V_63 ,
V_205 -> V_210 -> V_100 . V_64 ) ;
V_218 = F_133 ( V_207 ) ;
F_132 ( V_218 > V_217 ) ;
if ( V_218 >= V_217 )
return 0 ;
V_219 = V_217 - V_218 ;
if ( V_219 < V_175 )
V_175 = ( unsigned int ) V_219 ;
}
return V_175 ;
}
int F_140 ( struct V_220 * V_221 )
{
struct V_204 V_205 ;
F_141 ( & V_205 , V_221 -> V_36 , V_222 , true ,
V_221 -> V_223 ) ;
return F_142 ( & V_205 , V_221 ) ;
}
static void F_143 ( struct V_220 * V_221 )
{
F_3 ( L_57 , V_221 -> V_224 ) ;
if ( F_22 ( V_221 -> V_36 ) -> V_10 -> V_149 &
V_225 ) {
F_144 ( V_221 -> V_36 ) ;
}
if ( ! F_33 ( V_226 , & V_221 -> V_149 ) )
V_221 -> V_163 . V_227 = F_140 ( V_221 ) ;
}
void F_145 ( struct V_220 * V_221 )
{
F_146 ( V_221 , V_221 -> V_224 ) ;
if ( ! V_221 -> V_224 ) {
F_147 ( V_221 ) ;
V_221 -> V_228 -> V_229 ( & V_221 -> V_163 , V_221 ) ;
} else
F_143 ( V_221 ) ;
V_221 -> V_228 -> V_230 ( V_221 ) ;
}
static void
F_148 ( struct V_204 * V_231 ,
struct V_220 * V_221 )
{
if ( ! F_33 ( V_226 , & V_221 -> V_149 ) ) {
F_149 ( & V_221 -> V_232 , & V_231 -> V_233 ) ;
F_137 ( V_231 ) ;
V_231 -> V_234 = 1 ;
}
F_150 ( V_221 ) ;
}
static enum V_235
F_151 ( struct V_220 * V_221 ,
const struct V_236 * V_237 ,
struct V_70 * V_71 ,
int V_238 )
{
struct V_36 * V_36 = V_221 -> V_36 ;
enum V_235 V_239 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_221 -> V_228 = V_237 ;
F_3 ( L_58 , V_5 ,
V_36 -> V_110 , V_221 -> args . V_189 , V_221 -> args . V_63 , V_238 ) ;
V_239 = V_9 -> V_10 -> V_240 ( V_221 , V_238 ) ;
if ( V_239 != V_241 )
F_152 ( V_36 , V_242 ) ;
F_3 ( L_59 , V_5 , V_239 ) ;
return V_239 ;
}
static void
F_153 ( struct V_204 * V_231 ,
struct V_220 * V_221 , int V_238 )
{
const struct V_236 * V_237 = V_231 -> V_243 ;
struct V_70 * V_71 = V_231 -> V_210 ;
enum V_235 V_239 ;
V_231 -> V_210 = NULL ;
V_239 = F_151 ( V_221 , V_237 , V_71 , V_238 ) ;
if ( V_239 == V_241 )
F_148 ( V_231 , V_221 ) ;
F_54 ( V_71 ) ;
}
static void F_154 ( struct V_220 * V_221 )
{
F_54 ( V_221 -> V_71 ) ;
F_155 ( V_221 ) ;
}
int
F_156 ( struct V_204 * V_231 )
{
struct V_220 * V_221 ;
int V_105 ;
V_221 = F_157 ( V_231 -> V_244 ) ;
if ( ! V_221 ) {
V_231 -> V_245 -> V_246 ( & V_231 -> V_233 ) ;
F_54 ( V_231 -> V_210 ) ;
V_231 -> V_210 = NULL ;
return - V_146 ;
}
F_158 ( V_231 , V_221 , F_154 ) ;
V_221 -> V_71 = F_121 ( V_231 -> V_210 ) ;
V_105 = F_159 ( V_231 , V_221 ) ;
if ( V_105 != 0 ) {
F_54 ( V_231 -> V_210 ) ;
V_231 -> V_210 = NULL ;
} else
F_153 ( V_231 , V_221 , V_231 -> V_247 ) ;
return V_105 ;
}
int F_160 ( struct V_220 * V_221 )
{
struct V_204 V_205 ;
F_161 ( & V_205 , V_221 -> V_36 , true , V_221 -> V_223 ) ;
return F_142 ( & V_205 , V_221 ) ;
}
static void F_162 ( struct V_220 * V_221 )
{
F_3 ( L_60 , V_221 -> V_224 ) ;
if ( F_22 ( V_221 -> V_36 ) -> V_10 -> V_149 &
V_225 ) {
F_144 ( V_221 -> V_36 ) ;
}
if ( ! F_33 ( V_226 , & V_221 -> V_149 ) )
V_221 -> V_163 . V_227 = F_160 ( V_221 ) ;
}
void F_163 ( struct V_220 * V_221 )
{
F_164 ( V_221 , V_221 -> V_224 ) ;
if ( F_118 ( ! V_221 -> V_224 ) ) {
F_165 ( V_221 ) ;
V_221 -> V_228 -> V_229 ( & V_221 -> V_163 , V_221 ) ;
} else
F_162 ( V_221 ) ;
V_221 -> V_228 -> V_230 ( V_221 ) ;
}
static void
F_166 ( struct V_204 * V_231 ,
struct V_220 * V_221 )
{
if ( ! F_33 ( V_226 , & V_221 -> V_149 ) ) {
F_149 ( & V_221 -> V_232 , & V_231 -> V_233 ) ;
F_135 ( V_231 ) ;
V_231 -> V_234 = 1 ;
}
F_150 ( V_221 ) ;
}
static enum V_235
F_167 ( struct V_220 * V_221 ,
const struct V_236 * V_237 ,
struct V_70 * V_71 )
{
struct V_36 * V_36 = V_221 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_235 V_239 ;
V_221 -> V_228 = V_237 ;
F_3 ( L_61 ,
V_5 , V_36 -> V_110 , V_221 -> args . V_189 , V_221 -> args . V_63 ) ;
V_239 = V_9 -> V_10 -> V_248 ( V_221 ) ;
if ( V_239 != V_241 )
F_152 ( V_36 , V_249 ) ;
F_3 ( L_59 , V_5 , V_239 ) ;
return V_239 ;
}
static void
F_168 ( struct V_204 * V_231 , struct V_220 * V_221 )
{
const struct V_236 * V_237 = V_231 -> V_243 ;
struct V_70 * V_71 = V_231 -> V_210 ;
enum V_235 V_239 ;
V_231 -> V_210 = NULL ;
V_239 = F_167 ( V_221 , V_237 , V_71 ) ;
if ( V_239 == V_241 )
F_166 ( V_231 , V_221 ) ;
F_54 ( V_71 ) ;
}
static void F_169 ( struct V_220 * V_221 )
{
F_54 ( V_221 -> V_71 ) ;
F_155 ( V_221 ) ;
}
int
F_170 ( struct V_204 * V_231 )
{
struct V_220 * V_221 ;
int V_105 ;
V_221 = F_157 ( V_231 -> V_244 ) ;
if ( ! V_221 ) {
V_231 -> V_245 -> V_246 ( & V_231 -> V_233 ) ;
V_105 = - V_146 ;
F_54 ( V_231 -> V_210 ) ;
V_231 -> V_210 = NULL ;
return V_105 ;
}
F_158 ( V_231 , V_221 , F_169 ) ;
V_221 -> V_71 = F_121 ( V_231 -> V_210 ) ;
V_105 = F_159 ( V_231 , V_221 ) ;
if ( V_105 != 0 ) {
F_54 ( V_231 -> V_210 ) ;
V_231 -> V_210 = NULL ;
} else
F_168 ( V_231 , V_221 ) ;
return V_105 ;
}
static void F_171 ( struct V_36 * V_36 )
{
unsigned long * V_250 = & F_28 ( V_36 ) -> V_149 ;
F_172 ( V_251 , V_250 ) ;
F_173 () ;
F_174 ( V_250 , V_251 ) ;
}
static void F_175 ( struct V_36 * V_36 , struct V_94 * V_252 )
{
struct V_70 * V_71 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_71 -> V_100 . V_53 == V_54 &&
F_35 ( V_150 , & V_71 -> V_76 ) )
F_17 ( & V_71 -> V_73 , V_252 ) ;
}
}
static void F_176 ( struct V_36 * V_36 , struct V_94 * V_252 )
{
struct V_70 * V_71 , * V_27 ;
F_69 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_71 -> V_73 ) ;
F_54 ( V_71 ) ;
}
F_171 ( V_36 ) ;
}
void F_177 ( struct V_70 * V_71 )
{
F_37 ( V_71 -> V_77 , V_71 -> V_100 . V_53 ) ;
}
void
F_147 ( struct V_220 * V_221 )
{
struct V_36 * V_36 = V_221 -> V_36 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_253 = V_221 -> V_254 + V_221 -> V_201 . V_189 ;
bool V_255 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_33 ( V_148 , & V_48 -> V_149 ) ) {
V_255 = true ;
F_3 ( L_62 ,
V_5 , V_36 -> V_110 ) ;
}
if ( ! F_33 ( V_150 , & V_221 -> V_71 -> V_76 ) ) {
F_121 ( V_221 -> V_71 ) ;
}
if ( V_253 > V_48 -> V_49 -> V_256 )
V_48 -> V_49 -> V_256 = V_253 ;
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_63 ,
V_5 , V_221 -> V_71 , V_48 -> V_49 -> V_256 ) ;
if ( V_255 )
F_178 ( V_36 ) ;
}
void F_179 ( struct V_257 * V_258 )
{
struct V_36 * V_36 = V_258 -> V_36 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
bool V_255 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_33 ( V_148 , & V_48 -> V_149 ) ) {
V_255 = true ;
F_3 ( L_62 ,
V_5 , V_36 -> V_110 ) ;
}
if ( ! F_33 ( V_150 , & V_258 -> V_71 -> V_76 ) ) {
F_121 ( V_258 -> V_71 ) ;
}
if ( V_258 -> V_259 > V_48 -> V_49 -> V_256 )
V_48 -> V_49 -> V_256 = V_258 -> V_259 ;
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_63 ,
V_5 , V_258 -> V_71 , V_48 -> V_49 -> V_256 ) ;
if ( V_255 )
F_178 ( V_36 ) ;
}
void F_180 ( struct V_260 * V_258 )
{
struct V_8 * V_9 = F_22 ( V_258 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_261 )
V_9 -> V_10 -> V_261 ( V_258 ) ;
F_176 ( V_258 -> args . V_36 , & V_258 -> V_109 ) ;
}
int
F_79 ( struct V_36 * V_36 , bool V_262 )
{
struct V_1 * V_39 = F_22 ( V_36 ) -> V_10 ;
struct V_260 * V_258 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_253 ;
int V_25 ;
if ( ! F_181 ( V_36 ) )
return 0 ;
F_3 ( L_64 , V_5 , V_36 -> V_110 ) ;
V_25 = - V_107 ;
if ( F_33 ( V_251 , & V_48 -> V_149 ) ) {
if ( ! V_262 )
goto V_4;
V_25 = F_182 ( & V_48 -> V_149 ,
V_251 ,
V_263 ,
V_264 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_146 ;
V_258 = F_96 ( sizeof( * V_258 ) , V_215 ) ;
if ( ! V_258 )
goto V_265;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_35 ( V_148 , & V_48 -> V_149 ) )
goto V_194;
F_45 ( & V_258 -> V_109 ) ;
F_175 ( V_36 , & V_258 -> V_109 ) ;
V_253 = V_48 -> V_49 -> V_256 ;
V_48 -> V_49 -> V_256 = 0 ;
F_88 ( & V_258 -> args . V_128 , & V_48 -> V_49 -> V_124 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_258 -> args . V_36 = V_36 ;
V_258 -> V_145 = F_116 ( V_48 -> V_49 -> V_45 ) ;
F_183 ( & V_258 -> V_266 ) ;
V_258 -> args . V_267 = F_22 ( V_36 ) -> V_268 ;
V_258 -> V_201 . V_266 = & V_258 -> V_266 ;
V_258 -> args . V_269 = V_253 - 1 ;
V_258 -> V_201 . V_14 = F_22 ( V_36 ) ;
if ( V_39 -> V_270 ) {
V_25 = V_39 -> V_270 ( & V_258 -> args ) ;
if ( V_25 ) {
F_5 ( & V_36 -> V_52 ) ;
if ( V_253 < V_48 -> V_49 -> V_256 )
V_48 -> V_49 -> V_256 = V_253 ;
F_7 ( & V_36 -> V_52 ) ;
F_26 ( V_258 -> V_145 ) ;
F_48 ( V_148 , & V_48 -> V_149 ) ;
goto V_265;
}
}
V_25 = F_184 ( V_258 , V_262 ) ;
V_4:
if ( V_25 )
F_178 ( V_36 ) ;
F_3 ( L_65 , V_5 , V_25 ) ;
return V_25 ;
V_194:
F_7 ( & V_36 -> V_52 ) ;
F_185 ( V_258 ) ;
V_265:
F_171 ( V_36 ) ;
goto V_4;
}
struct V_171 * F_186 ( void )
{
struct V_171 * V_271 ;
V_271 = F_96 ( sizeof( * V_271 ) , V_215 ) ;
if ( ! V_271 ) {
F_3 ( L_66 , V_5 ) ;
return NULL ;
}
return V_271 ;
}
