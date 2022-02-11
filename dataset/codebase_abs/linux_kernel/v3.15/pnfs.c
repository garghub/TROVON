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
static T_3
F_56 ( T_3 V_67 , T_3 V_81 )
{
T_3 V_68 ;
V_68 = V_67 + V_81 ;
return V_68 >= V_67 ? V_68 : V_65 ;
}
static bool
F_57 ( const struct V_61 * V_82 ,
const struct V_61 * V_83 )
{
T_3 V_84 = V_82 -> V_63 ;
T_3 V_85 = F_56 ( V_84 , V_82 -> V_64 ) ;
T_3 V_86 = V_83 -> V_63 ;
T_3 V_87 = F_56 ( V_86 , V_83 -> V_64 ) ;
return ( V_84 <= V_86 ) && ( V_85 >= V_87 ) ;
}
static bool
F_58 ( const struct V_61 * V_82 ,
const struct V_61 * V_83 )
{
T_3 V_84 = V_82 -> V_63 ;
T_3 V_85 = F_56 ( V_84 , V_82 -> V_64 ) ;
T_3 V_86 = V_83 -> V_63 ;
T_3 V_87 = F_56 ( V_86 , V_83 -> V_64 ) ;
return ( V_85 == V_65 || V_85 > V_86 ) &&
( V_87 == V_65 || V_87 > V_84 ) ;
}
static bool
F_59 ( const struct V_61 * V_88 ,
const struct V_61 * V_89 )
{
return ( V_89 -> V_53 == V_90 ||
V_88 -> V_53 == V_89 -> V_53 ) &&
F_58 ( V_88 , V_89 ) ;
}
static bool F_60 ( struct V_70 * V_71 ,
struct V_91 * V_92 )
{
if ( ! F_9 ( & V_71 -> V_74 ) )
return false ;
F_50 ( V_71 -> V_77 , V_71 ) ;
F_17 ( & V_71 -> V_72 , V_92 ) ;
return true ;
}
static int F_61 ( struct V_70 * V_71 ,
struct V_91 * V_92 )
{
int V_93 = 0 ;
if ( F_35 ( V_75 , & V_71 -> V_76 ) ) {
F_3 ( L_21 , V_5 , V_71 ,
F_55 ( & V_71 -> V_74 ) ) ;
if ( F_60 ( V_71 , V_92 ) )
V_93 = 1 ;
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
F_62 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_89 ||
F_59 ( & V_71 -> V_97 , V_89 ) ) {
F_3 ( L_23
L_24 , V_5 ,
V_71 , V_71 -> V_97 . V_53 , V_71 -> V_97 . V_63 ,
V_71 -> V_97 . V_64 ) ;
V_95 ++ ;
V_96 += F_61 ( V_71 , V_92 ) ;
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
F_62 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_71 -> V_72 ) ;
F_49 ( V_71 ) ;
}
}
void
F_63 ( struct V_47 * V_48 )
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
static bool
F_64 ( struct V_36 * V_36 ,
struct V_91 * V_101 )
{
struct V_33 * V_34 ;
bool V_102 = false ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 != NULL && F_24 ( & V_34 -> V_103 ) ) {
F_20 ( V_34 ) ;
F_17 ( & V_34 -> V_103 , V_101 ) ;
V_102 = true ;
}
F_7 ( & V_36 -> V_52 ) ;
return V_102 ;
}
static int
F_65 ( struct V_12 * V_43 ,
struct V_8 * V_14 ,
struct V_91 * V_101 )
{
struct V_33 * V_34 , * V_94 ;
struct V_36 * V_36 ;
F_62 (lo, next, &server->layouts, plh_layouts) {
V_36 = F_66 ( V_34 -> V_41 ) ;
if ( V_36 == NULL )
continue;
F_25 ( & V_34 -> V_42 ) ;
if ( F_64 ( V_36 , V_101 ) )
continue;
F_67 () ;
F_7 ( & V_43 -> V_44 ) ;
F_68 ( V_36 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_69 () ;
return - V_104 ;
}
return 0 ;
}
static int
F_70 ( struct V_91 * V_101 ,
bool V_105 )
{
struct V_33 * V_34 ;
struct V_36 * V_36 ;
struct V_61 V_62 = {
. V_53 = V_90 ,
. V_63 = 0 ,
. V_64 = V_65 ,
} ;
F_38 ( V_106 ) ;
int V_102 = 0 ;
while ( ! F_24 ( V_101 ) ) {
V_34 = F_71 ( V_101 -> V_94 , struct V_33 ,
V_103 ) ;
F_3 ( L_26 , V_5 ,
V_34 -> V_41 -> V_107 ) ;
V_36 = V_34 -> V_41 ;
F_5 ( & V_36 -> V_52 ) ;
F_25 ( & V_34 -> V_103 ) ;
V_34 -> V_100 ++ ;
if ( V_105 )
F_48 ( V_79 , & V_34 -> V_60 ) ;
if ( F_39 ( V_34 , & V_106 , & V_62 ) )
V_102 = - V_104 ;
F_7 ( & V_36 -> V_52 ) ;
F_40 ( & V_106 ) ;
F_29 ( V_34 ) ;
F_68 ( V_36 ) ;
}
return V_102 ;
}
int
F_72 ( struct V_12 * V_43 ,
struct V_108 * V_109 ,
bool V_110 )
{
struct V_8 * V_14 ;
F_38 ( V_101 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_69 () ;
V_111:
F_73 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_14 -> V_109 , V_109 , sizeof( * V_109 ) ) != 0 )
continue;
if ( F_65 ( V_43 ,
V_14 ,
& V_101 ) != 0 )
goto V_111;
}
F_67 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_101 ) )
return 0 ;
return F_70 ( & V_101 , V_110 ) ;
}
int
F_74 ( struct V_12 * V_43 ,
bool V_110 )
{
struct V_8 * V_14 ;
F_38 ( V_101 ) ;
F_5 ( & V_43 -> V_44 ) ;
F_69 () ;
V_111:
F_73 (server, &clp->cl_superblocks, client_link) {
if ( F_65 ( V_43 ,
V_14 ,
& V_101 ) != 0 )
goto V_111;
}
F_67 () ;
F_7 ( & V_43 -> V_44 ) ;
if ( F_24 ( & V_101 ) )
return 0 ;
return F_70 ( & V_101 , V_110 ) ;
}
void
F_75 ( struct V_12 * V_43 )
{
F_76 ( V_43 ) ;
F_10 ( V_43 ) ;
F_74 ( V_43 , false ) ;
}
static bool F_77 ( T_1 V_112 , T_1 V_113 )
{
return ( V_114 ) ( V_112 - V_113 ) > 0 ;
}
static void
F_78 ( struct V_33 * V_34 ,
const T_4 * V_115 ,
struct V_91 * V_116 )
{
if ( F_79 ( & V_34 -> V_117 , V_115 ) )
return;
F_39 ( V_34 , V_116 , NULL ) ;
}
void
F_80 ( struct V_33 * V_34 , const T_4 * V_115 ,
bool V_118 )
{
T_1 V_119 , V_120 , V_121 ;
int V_122 = F_24 ( & V_34 -> V_78 ) ;
V_119 = F_81 ( V_34 -> V_117 . V_123 ) ;
V_120 = F_81 ( V_115 -> V_123 ) ;
if ( V_122 || F_77 ( V_120 , V_119 ) ) {
F_82 ( & V_34 -> V_117 , V_115 ) ;
if ( V_118 ) {
V_121 = F_81 ( V_115 -> V_123 ) ;
} else {
V_121 = V_120 - F_55 ( & V_34 -> V_124 ) ;
}
if ( V_122 || F_77 ( V_121 , V_34 -> V_125 ) )
V_34 -> V_125 = V_121 ;
}
}
static bool
F_83 ( const struct V_33 * V_34 ,
const T_4 * V_126 )
{
T_1 V_123 = F_81 ( V_126 -> V_123 ) ;
return ! F_77 ( V_123 , V_34 -> V_125 ) ;
}
static bool
F_84 ( const struct V_33 * V_34 , int V_127 )
{
return V_34 -> V_100 ||
F_42 ( V_79 , & V_34 -> V_60 ) ||
( F_24 ( & V_34 -> V_78 ) &&
( F_55 ( & V_34 -> V_124 ) > V_127 ) ) ;
}
int
F_85 ( T_4 * V_128 , struct V_33 * V_34 ,
struct V_129 * V_130 )
{
int V_25 = 0 ;
F_3 ( L_27 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_84 ( V_34 , 1 ) ) {
V_25 = - V_104 ;
} else if ( ! F_86 ( V_130 ) ) {
V_25 = - V_131 ;
} else if ( F_24 ( & V_34 -> V_78 ) ) {
int V_132 ;
do {
V_132 = F_87 ( & V_130 -> V_133 ) ;
F_82 ( V_128 , & V_130 -> V_126 ) ;
} while ( F_88 ( & V_130 -> V_133 , V_132 ) );
} else
F_82 ( V_128 , & V_34 -> V_117 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_28 , V_5 ) ;
return V_25 ;
}
static struct V_70 *
F_89 ( struct V_33 * V_34 ,
struct V_134 * V_135 ,
struct V_61 * V_62 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_136 * V_137 ;
struct V_70 * V_71 ;
F_3 ( L_27 , V_5 ) ;
V_137 = F_90 ( sizeof( * V_137 ) , V_38 ) ;
if ( V_137 == NULL )
return NULL ;
V_137 -> args . V_138 = V_139 ;
if ( V_137 -> args . V_138 > V_62 -> V_64 )
V_137 -> args . V_138 = V_62 -> V_64 ;
V_137 -> args . V_140 = V_141 ;
V_137 -> args . V_62 = * V_62 ;
V_137 -> args . type = V_14 -> V_10 -> V_2 ;
V_137 -> args . V_36 = V_37 ;
V_137 -> args . V_135 = F_91 ( V_135 ) ;
V_137 -> V_38 = V_38 ;
V_137 -> V_142 = V_34 -> V_45 ;
V_71 = F_92 ( V_137 , V_38 ) ;
if ( F_93 ( V_71 ) ) {
switch ( F_94 ( V_71 ) ) {
case - V_143 :
case - V_144 :
break;
default:
F_37 ( V_34 , V_62 -> V_53 ) ;
}
return NULL ;
}
return V_71 ;
}
static void F_95 ( struct V_36 * V_36 ,
struct V_91 * V_66 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_70 * V_71 , * V_27 ;
if ( ! F_35 ( V_145 , & V_48 -> V_146 ) )
return;
F_62 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_35 ( V_147 , & V_71 -> V_76 ) )
continue;
F_60 ( V_71 , V_66 ) ;
}
}
int
F_96 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_38 ( V_92 ) ;
struct V_148 * V_149 ;
T_4 V_126 ;
int V_25 = 0 , V_122 ;
F_3 ( L_29 , V_5 , V_37 -> V_107 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_30 , V_5 ) ;
goto V_4;
}
V_126 = V_48 -> V_49 -> V_117 ;
F_20 ( V_34 ) ;
V_122 = F_24 ( & V_34 -> V_78 ) ;
F_95 ( V_37 , & V_92 ) ;
F_39 ( V_34 , & V_92 , NULL ) ;
if ( V_122 ) {
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
V_34 -> V_100 ++ ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_92 ) ;
V_149 = F_90 ( sizeof( * V_149 ) , V_150 ) ;
if ( F_97 ( V_149 == NULL ) ) {
V_25 = - V_143 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 -> V_100 -- ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_149 -> args . V_126 = V_126 ;
V_149 -> args . V_151 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_149 -> args . V_36 = V_37 ;
V_149 -> args . V_49 = V_34 ;
V_149 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_149 -> V_142 = V_34 -> V_45 ;
V_25 = F_98 ( V_149 ) ;
V_4:
F_3 ( L_32 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_99 ( struct V_36 * V_36 )
{
struct V_33 * V_34 ;
int V_102 ;
F_5 ( & V_36 -> V_52 ) ;
V_34 = F_28 ( V_36 ) -> V_49 ;
if ( V_34 == NULL ) {
F_7 ( & V_36 -> V_52 ) ;
return 0 ;
}
F_20 ( V_34 ) ;
V_34 -> V_100 ++ ;
F_7 ( & V_36 -> V_52 ) ;
F_100 ( V_36 -> V_152 ) ;
V_102 = F_101 ( V_36 , true ) ;
if ( V_102 == 0 )
V_102 = F_96 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_100 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_102 ;
}
bool F_102 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
struct V_70 * V_71 , * V_27 ;
F_38 ( V_92 ) ;
bool V_153 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( ! V_34 || ! F_35 ( V_154 , & V_34 -> V_60 ) ||
F_42 ( V_79 , & V_34 -> V_60 ) )
goto V_155;
F_62 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_42 ( V_156 , & V_71 -> V_76 ) ) {
F_61 ( V_71 , & V_92 ) ;
V_153 = true ;
}
if ( ! V_153 )
goto V_155;
V_34 -> V_100 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_92 ) ;
return true ;
V_155:
F_7 ( & V_37 -> V_52 ) ;
return false ;
}
void F_103 ( struct V_36 * V_37 )
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
void F_104 ( struct V_36 * V_37 , T_1 V_157 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_77 ( V_157 , V_34 -> V_125 ) )
V_34 -> V_125 = V_157 ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_105 ( struct V_36 * V_37 , T_1 * V_157 , struct V_158 * V_159 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
struct V_70 * V_71 ;
T_1 V_160 ;
bool V_153 = false ;
F_5 ( & V_37 -> V_52 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_42 ( V_156 , & V_71 -> V_76 ) ) {
F_106 ( & F_22 ( V_37 ) -> V_80 , V_159 , NULL ) ;
V_153 = true ;
goto V_4;
}
V_34 = V_48 -> V_49 ;
V_160 = F_81 ( V_34 -> V_117 . V_123 ) ;
* V_157 = V_160 + F_55 ( & V_34 -> V_124 ) ;
V_4:
F_7 ( & V_37 -> V_52 ) ;
return V_153 ;
}
static T_5
F_107 ( const struct V_61 * V_82 ,
const struct V_61 * V_83 )
{
T_5 V_161 ;
V_161 = V_82 -> V_63 - V_83 -> V_63 ;
if ( V_161 )
return V_161 ;
V_161 = V_83 -> V_64 - V_82 -> V_64 ;
if ( V_161 )
return V_161 ;
return ( int ) ( V_82 -> V_53 == V_162 ) - ( int ) ( V_83 -> V_53 == V_162 ) ;
}
static void
F_108 ( struct V_33 * V_34 ,
struct V_70 * V_71 )
{
struct V_70 * V_163 ;
F_3 ( L_33 , V_5 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_107 ( & V_71 -> V_97 , & V_163 -> V_97 ) > 0 )
continue;
F_109 ( & V_71 -> V_72 , & V_163 -> V_72 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_71 , V_71 -> V_97 . V_53 ,
V_71 -> V_97 . V_63 , V_71 -> V_97 . V_64 ,
V_163 , V_163 -> V_97 . V_53 , V_163 -> V_97 . V_63 ,
V_163 -> V_97 . V_64 ) ;
goto V_4;
}
F_109 ( & V_71 -> V_72 , & V_34 -> V_78 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_71 , V_71 -> V_97 . V_53 ,
V_71 -> V_97 . V_63 , V_71 -> V_97 . V_64 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_38 , V_5 ) ;
}
static struct V_33 *
F_110 ( struct V_36 * V_37 ,
struct V_134 * V_135 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_46 ( & V_34 -> V_35 , 1 ) ;
F_45 ( & V_34 -> V_42 ) ;
F_45 ( & V_34 -> V_78 ) ;
F_45 ( & V_34 -> V_103 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_45 = F_111 ( V_135 -> V_142 ) ;
return V_34 ;
}
static struct V_33 *
F_112 ( struct V_36 * V_37 ,
struct V_134 * V_135 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_115 = NULL ;
F_3 ( L_39 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_164;
F_7 ( & V_37 -> V_52 ) ;
V_115 = F_110 ( V_37 , V_135 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_113 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_115 ;
return V_115 ;
} else if ( V_115 != NULL )
F_23 ( V_115 ) ;
V_164:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_114 ( const struct V_61 * V_165 ,
const struct V_61 * V_62 )
{
struct V_61 V_166 ;
if ( ( V_62 -> V_53 == V_54 &&
V_165 -> V_53 != V_54 ) ||
! F_58 ( V_165 , V_62 ) )
return 0 ;
V_166 = * V_62 ;
V_166 . V_64 = 1 ;
return F_57 ( V_165 , & V_166 ) ;
}
static struct V_70 *
F_115 ( struct V_33 * V_34 ,
struct V_61 * V_62 )
{
struct V_70 * V_71 , * V_102 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_42 ( V_75 , & V_71 -> V_76 ) &&
F_114 ( & V_71 -> V_97 , V_62 ) ) {
V_102 = F_116 ( V_71 ) ;
break;
}
if ( V_71 -> V_97 . V_63 > V_62 -> V_63 )
break;
}
F_3 ( L_40 ,
V_5 , V_102 , V_102 ? F_55 ( & V_102 -> V_74 ) : 0 ) ;
return V_102 ;
}
static bool F_117 ( struct V_134 * V_135 ,
struct V_36 * V_37 , int V_53 )
{
struct V_167 * V_168 = V_135 -> V_169 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_6 V_170 = F_118 ( V_37 ) ;
bool V_171 = false , V_172 = false , V_173 = false , V_174 = false , V_102 = false ;
if ( V_168 == NULL )
return V_102 ;
F_3 ( L_41 ,
V_5 , V_168 -> V_175 , V_168 -> V_176 , V_168 -> V_177 , V_168 -> V_178 , V_168 -> V_179 ) ;
switch ( V_53 ) {
case V_162 :
if ( V_168 -> V_175 & V_180 ) {
F_3 ( L_42 , V_5 , V_170 ) ;
V_172 = true ;
if ( V_170 < V_168 -> V_176 )
V_171 = true ;
}
if ( V_168 -> V_175 & V_181 ) {
F_3 ( L_43 , V_5 ,
V_48 -> V_51 ) ;
V_174 = true ;
if ( V_48 -> V_51 < V_168 -> V_178 )
V_173 = true ;
}
break;
case V_54 :
if ( V_168 -> V_175 & V_182 ) {
F_3 ( L_42 , V_5 , V_170 ) ;
V_172 = true ;
if ( V_170 < V_168 -> V_177 )
V_171 = true ;
}
if ( V_168 -> V_175 & V_183 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_50 ) ;
V_174 = true ;
if ( V_48 -> V_50 < V_168 -> V_179 )
V_173 = true ;
}
break;
}
if ( V_172 && V_174 ) {
if ( V_171 && V_173 )
V_102 = true ;
} else if ( V_171 || V_173 )
V_102 = true ;
F_3 ( L_45 , V_5 , V_171 , V_173 , V_102 ) ;
return V_102 ;
}
struct V_70 *
F_119 ( struct V_36 * V_37 ,
struct V_134 * V_135 ,
T_6 V_184 ,
T_3 V_185 ,
enum V_186 V_53 ,
T_2 V_38 )
{
struct V_61 V_187 = {
. V_53 = V_53 ,
. V_63 = V_184 ,
. V_64 = V_185 ,
} ;
unsigned V_188 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_70 * V_71 = NULL ;
bool V_189 ;
if ( ! F_120 ( F_22 ( V_37 ) ) )
goto V_4;
if ( F_117 ( V_135 , V_37 , V_53 ) )
goto V_4;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_112 ( V_37 , V_135 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
goto V_4;
}
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_46 , V_5 ) ;
goto V_190;
}
if ( F_41 ( V_34 , V_53 ) )
goto V_190;
V_71 = F_115 ( V_34 , & V_187 ) ;
if ( V_71 )
goto V_190;
if ( F_84 ( V_34 , 0 ) )
goto V_190;
F_15 ( & V_34 -> V_124 ) ;
V_189 = F_24 ( & V_34 -> V_42 ) ? true : false ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_189 ) {
F_5 ( & V_43 -> V_44 ) ;
F_109 ( & V_34 -> V_42 , & V_14 -> V_191 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_188 = V_187 . V_63 & ~ V_192 ;
if ( V_188 ) {
V_187 . V_63 -= V_188 ;
V_187 . V_64 += V_188 ;
}
if ( V_187 . V_64 != V_65 )
V_187 . V_64 = F_121 ( V_187 . V_64 ) ;
V_71 = F_89 ( V_34 , V_135 , & V_187 , V_38 ) ;
F_36 ( & V_34 -> V_124 ) ;
V_193:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_47
L_48 ,
V_5 , V_37 -> V_194 -> V_195 ,
( unsigned long long ) F_122 ( V_37 ) ,
V_71 == NULL ? L_49 : L_50 ,
V_53 == V_54 ? L_51 : L_52 ,
( unsigned long long ) V_184 ,
( unsigned long long ) V_185 ) ;
return V_71 ;
V_190:
F_7 ( & V_37 -> V_52 ) ;
goto V_193;
}
struct V_70 *
F_123 ( struct V_136 * V_137 )
{
struct V_33 * V_34 = F_28 ( V_137 -> args . V_36 ) -> V_49 ;
struct V_196 * V_197 = & V_137 -> V_197 ;
struct V_70 * V_71 ;
struct V_36 * V_37 = V_34 -> V_41 ;
F_38 ( V_98 ) ;
int V_25 = 0 ;
V_71 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_197 , V_137 -> V_38 ) ;
if ( ! V_71 || F_93 ( V_71 ) ) {
if ( ! V_71 )
V_25 = - V_143 ;
else
V_25 = F_94 ( V_71 ) ;
F_3 ( L_53 ,
V_5 , V_25 ) ;
goto V_4;
}
F_5 ( & V_37 -> V_52 ) ;
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_54 , V_5 ) ;
goto V_198;
}
if ( F_84 ( V_34 , 1 ) ||
F_83 ( V_34 , & V_197 -> V_126 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_198;
}
F_78 ( V_34 , & V_197 -> V_126 , & V_98 ) ;
F_80 ( V_34 , & V_197 -> V_126 , false ) ;
F_44 ( V_34 , V_71 ) ;
V_71 -> V_97 = V_197 -> V_62 ;
F_116 ( V_71 ) ;
F_108 ( V_34 , V_71 ) ;
if ( V_197 -> V_199 ) {
F_48 ( V_156 , & V_71 -> V_76 ) ;
F_48 ( V_154 , & V_34 -> V_60 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_98 ) ;
return V_71 ;
V_4:
return F_124 ( V_25 ) ;
V_198:
F_7 ( & V_37 -> V_52 ) ;
V_71 -> V_77 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_71 ) ;
goto V_4;
}
void
F_125 ( struct V_200 * V_201 , struct V_202 * V_203 )
{
T_3 V_204 = V_203 -> V_205 ;
F_126 ( V_201 -> V_206 != NULL ) ;
if ( V_203 -> V_207 != V_203 -> V_208 ) {
F_127 ( V_201 ) ;
return;
}
if ( V_201 -> V_209 == NULL )
V_204 = F_118 ( V_201 -> V_210 ) - F_128 ( V_203 ) ;
else
V_204 = F_129 ( V_201 -> V_209 ) ;
V_201 -> V_206 = F_119 ( V_201 -> V_210 ,
V_203 -> V_211 ,
F_128 ( V_203 ) ,
V_204 ,
V_162 ,
V_150 ) ;
if ( V_201 -> V_206 == NULL )
F_127 ( V_201 ) ;
}
void
F_130 ( struct V_200 * V_201 ,
struct V_202 * V_203 , T_3 V_212 )
{
F_126 ( V_201 -> V_206 != NULL ) ;
if ( V_203 -> V_207 != V_203 -> V_208 ) {
F_131 ( V_201 ) ;
return;
}
V_201 -> V_206 = F_119 ( V_201 -> V_210 ,
V_203 -> V_211 ,
F_128 ( V_203 ) ,
V_212 ,
V_54 ,
V_213 ) ;
if ( V_201 -> V_206 == NULL )
F_131 ( V_201 ) ;
}
void
F_132 ( struct V_200 * V_201 , struct V_36 * V_36 ,
const struct V_214 * V_215 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_133 ( V_201 , V_36 , V_215 ) ;
else
F_134 ( V_201 , V_36 , V_39 -> V_216 , V_215 , V_14 -> V_217 , 0 ) ;
}
void
F_135 ( struct V_200 * V_201 , struct V_36 * V_36 ,
int V_218 ,
const struct V_214 * V_215 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_136 ( V_201 , V_36 , V_218 , V_215 ) ;
else
F_134 ( V_201 , V_36 , V_39 -> V_219 , V_215 , V_14 -> V_220 , V_218 ) ;
}
bool
F_137 ( struct V_200 * V_201 , struct V_202 * V_221 ,
struct V_202 * V_203 )
{
if ( V_201 -> V_206 == NULL )
return F_138 ( V_201 , V_221 , V_203 ) ;
return F_128 ( V_203 ) < F_56 ( V_201 -> V_206 -> V_97 . V_63 ,
V_201 -> V_206 -> V_97 . V_64 ) ;
}
int F_139 ( struct V_36 * V_36 ,
struct V_91 * V_66 ,
const struct V_214 * V_215 ,
struct V_222 * V_223 )
{
struct V_200 V_201 ;
F_38 ( V_224 ) ;
F_136 ( & V_201 , V_36 , V_225 , V_215 ) ;
V_201 . V_209 = V_223 ;
while ( ! F_24 ( V_66 ) ) {
struct V_202 * V_203 = F_140 ( V_66 -> V_94 ) ;
F_141 ( V_203 ) ;
if ( ! F_142 ( & V_201 , V_203 ) )
F_143 ( V_203 , & V_224 ) ;
}
F_144 ( & V_201 ) ;
if ( ! F_24 ( & V_224 ) ) {
F_145 ( & V_224 , V_66 ) ;
return - V_226 ;
}
return 0 ;
}
static void F_146 ( struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_231 ;
F_3 ( L_56 , V_230 -> V_232 ) ;
if ( F_22 ( V_230 -> V_36 ) -> V_10 -> V_146 &
V_233 ) {
F_147 ( V_230 -> V_36 ) ;
}
if ( ! F_33 ( V_234 , & V_230 -> V_146 ) )
V_228 -> V_159 . V_235 = F_139 ( V_230 -> V_36 ,
& V_230 -> V_236 ,
V_230 -> V_237 ,
V_230 -> V_223 ) ;
}
void F_148 ( struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_231 ;
F_149 ( V_228 , V_230 -> V_232 ) ;
if ( ! V_230 -> V_232 ) {
F_150 ( V_228 ) ;
V_230 -> V_238 -> V_239 ( & V_228 -> V_159 , V_228 ) ;
} else
F_146 ( V_228 ) ;
V_230 -> V_238 -> V_240 ( V_228 ) ;
}
static void
F_151 ( struct V_200 * V_241 ,
struct V_227 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_231 ;
if ( ! F_33 ( V_234 , & V_230 -> V_146 ) ) {
F_152 ( & V_230 -> V_236 , & V_241 -> V_242 ) ;
F_131 ( V_241 ) ;
V_241 -> V_243 = 1 ;
}
F_153 ( V_228 ) ;
}
static enum V_244
F_154 ( struct V_227 * V_245 ,
const struct V_246 * V_247 ,
struct V_70 * V_71 ,
int V_248 )
{
struct V_229 * V_230 = V_245 -> V_231 ;
struct V_36 * V_36 = V_230 -> V_36 ;
enum V_244 V_249 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_230 -> V_238 = V_247 ;
F_3 ( L_57 , V_5 ,
V_36 -> V_107 , V_245 -> args . V_185 , V_245 -> args . V_63 , V_248 ) ;
V_249 = V_9 -> V_10 -> V_250 ( V_245 , V_248 ) ;
if ( V_249 != V_251 )
F_155 ( V_36 , V_252 ) ;
F_3 ( L_58 , V_5 , V_249 ) ;
return V_249 ;
}
static void
F_156 ( struct V_200 * V_241 , struct V_91 * V_66 , int V_248 )
{
struct V_227 * V_228 ;
const struct V_246 * V_247 = V_241 -> V_253 ;
struct V_70 * V_71 = V_241 -> V_206 ;
V_241 -> V_206 = NULL ;
while ( ! F_24 ( V_66 ) ) {
enum V_244 V_249 ;
V_228 = F_157 ( V_66 , struct V_227 , V_254 ) ;
F_25 ( & V_228 -> V_254 ) ;
V_249 = F_154 ( V_228 , V_247 , V_71 , V_248 ) ;
if ( V_249 == V_251 )
F_151 ( V_241 , V_228 ) ;
}
F_54 ( V_71 ) ;
}
static void F_158 ( struct V_229 * V_230 )
{
F_54 ( V_230 -> V_71 ) ;
F_159 ( V_230 ) ;
}
int
F_160 ( struct V_200 * V_241 )
{
struct V_255 * V_256 ;
struct V_229 * V_230 ;
int V_102 ;
V_256 = F_161 () ;
if ( ! V_256 ) {
V_241 -> V_257 -> V_258 ( & V_241 -> V_242 ) ;
F_54 ( V_241 -> V_206 ) ;
V_241 -> V_206 = NULL ;
return - V_143 ;
}
V_230 = & V_256 -> V_231 ;
F_162 ( V_241 , V_230 , F_158 ) ;
V_230 -> V_71 = F_116 ( V_241 -> V_206 ) ;
F_15 ( & V_230 -> V_259 ) ;
V_102 = F_163 ( V_241 , V_230 ) ;
if ( V_102 != 0 ) {
F_54 ( V_241 -> V_206 ) ;
V_241 -> V_206 = NULL ;
} else
F_156 ( V_241 , & V_230 -> V_260 , V_241 -> V_261 ) ;
if ( F_9 ( & V_230 -> V_259 ) )
V_230 -> V_237 -> V_262 ( V_230 ) ;
return V_102 ;
}
int F_164 ( struct V_36 * V_36 ,
struct V_91 * V_66 ,
const struct V_214 * V_215 ,
struct V_222 * V_223 )
{
struct V_200 V_201 ;
F_38 ( V_224 ) ;
F_133 ( & V_201 , V_36 , V_215 ) ;
V_201 . V_209 = V_223 ;
while ( ! F_24 ( V_66 ) ) {
struct V_202 * V_203 = F_140 ( V_66 -> V_94 ) ;
F_141 ( V_203 ) ;
if ( ! F_142 ( & V_201 , V_203 ) )
F_143 ( V_203 , & V_224 ) ;
}
F_144 ( & V_201 ) ;
if ( ! F_24 ( & V_224 ) ) {
F_145 ( & V_224 , V_66 ) ;
return - V_226 ;
}
return 0 ;
}
static void F_165 ( struct V_263 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_231 ;
F_3 ( L_59 , V_230 -> V_232 ) ;
if ( F_22 ( V_230 -> V_36 ) -> V_10 -> V_146 &
V_233 ) {
F_147 ( V_230 -> V_36 ) ;
}
if ( ! F_33 ( V_234 , & V_230 -> V_146 ) )
V_228 -> V_159 . V_235 = F_164 ( V_230 -> V_36 ,
& V_230 -> V_236 ,
V_230 -> V_237 ,
V_230 -> V_223 ) ;
}
void F_166 ( struct V_263 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_231 ;
F_167 ( V_228 , V_230 -> V_232 ) ;
if ( F_113 ( ! V_230 -> V_232 ) ) {
F_168 ( V_228 ) ;
V_230 -> V_238 -> V_239 ( & V_228 -> V_159 , V_228 ) ;
} else
F_165 ( V_228 ) ;
V_230 -> V_238 -> V_240 ( V_228 ) ;
}
static void
F_169 ( struct V_200 * V_241 ,
struct V_263 * V_228 )
{
struct V_229 * V_230 = V_228 -> V_231 ;
if ( ! F_33 ( V_234 , & V_230 -> V_146 ) ) {
F_152 ( & V_230 -> V_236 , & V_241 -> V_242 ) ;
F_127 ( V_241 ) ;
V_241 -> V_243 = 1 ;
}
F_170 ( V_228 ) ;
}
static enum V_244
F_171 ( struct V_263 * V_264 ,
const struct V_246 * V_247 ,
struct V_70 * V_71 )
{
struct V_229 * V_230 = V_264 -> V_231 ;
struct V_36 * V_36 = V_230 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_244 V_249 ;
V_230 -> V_238 = V_247 ;
F_3 ( L_60 ,
V_5 , V_36 -> V_107 , V_264 -> args . V_185 , V_264 -> args . V_63 ) ;
V_249 = V_9 -> V_10 -> V_265 ( V_264 ) ;
if ( V_249 != V_251 )
F_155 ( V_36 , V_266 ) ;
F_3 ( L_58 , V_5 , V_249 ) ;
return V_249 ;
}
static void
F_172 ( struct V_200 * V_241 , struct V_91 * V_66 )
{
struct V_263 * V_228 ;
const struct V_246 * V_247 = V_241 -> V_253 ;
struct V_70 * V_71 = V_241 -> V_206 ;
V_241 -> V_206 = NULL ;
while ( ! F_24 ( V_66 ) ) {
enum V_244 V_249 ;
V_228 = F_157 ( V_66 , struct V_263 , V_254 ) ;
F_25 ( & V_228 -> V_254 ) ;
V_249 = F_171 ( V_228 , V_247 , V_71 ) ;
if ( V_249 == V_251 )
F_169 ( V_241 , V_228 ) ;
}
F_54 ( V_71 ) ;
}
static void F_173 ( struct V_229 * V_230 )
{
F_54 ( V_230 -> V_71 ) ;
F_174 ( V_230 ) ;
}
int
F_175 ( struct V_200 * V_241 )
{
struct V_267 * V_268 ;
struct V_229 * V_230 ;
int V_102 ;
V_268 = F_176 () ;
if ( ! V_268 ) {
V_241 -> V_257 -> V_258 ( & V_241 -> V_242 ) ;
V_102 = - V_143 ;
F_54 ( V_241 -> V_206 ) ;
V_241 -> V_206 = NULL ;
return V_102 ;
}
V_230 = & V_268 -> V_231 ;
F_162 ( V_241 , V_230 , F_173 ) ;
V_230 -> V_71 = F_116 ( V_241 -> V_206 ) ;
F_15 ( & V_230 -> V_259 ) ;
V_102 = F_177 ( V_241 , V_230 ) ;
if ( V_102 != 0 ) {
F_54 ( V_241 -> V_206 ) ;
V_241 -> V_206 = NULL ;
} else
F_172 ( V_241 , & V_230 -> V_260 ) ;
if ( F_9 ( & V_230 -> V_259 ) )
V_230 -> V_237 -> V_262 ( V_230 ) ;
return V_102 ;
}
static void F_178 ( struct V_36 * V_36 )
{
unsigned long * V_269 = & F_28 ( V_36 ) -> V_146 ;
F_179 ( V_270 , V_269 ) ;
F_180 () ;
F_181 ( V_269 , V_270 ) ;
}
static void F_182 ( struct V_36 * V_36 , struct V_91 * V_271 )
{
struct V_70 * V_71 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_71 -> V_97 . V_53 == V_54 &&
F_35 ( V_147 , & V_71 -> V_76 ) )
F_17 ( & V_71 -> V_73 , V_271 ) ;
}
}
static void F_183 ( struct V_36 * V_36 , struct V_91 * V_271 )
{
struct V_70 * V_71 , * V_27 ;
F_62 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_71 -> V_73 ) ;
F_54 ( V_71 ) ;
}
F_178 ( V_36 ) ;
}
void F_184 ( struct V_70 * V_71 )
{
F_37 ( V_71 -> V_77 , V_71 -> V_97 . V_53 ) ;
}
void
F_150 ( struct V_227 * V_245 )
{
struct V_229 * V_230 = V_245 -> V_231 ;
struct V_36 * V_36 = V_230 -> V_36 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_272 = V_245 -> V_273 + V_245 -> V_197 . V_185 ;
bool V_274 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_33 ( V_145 , & V_48 -> V_146 ) ) {
V_274 = true ;
F_3 ( L_61 ,
V_5 , V_36 -> V_107 ) ;
}
if ( ! F_33 ( V_147 , & V_230 -> V_71 -> V_76 ) ) {
F_116 ( V_230 -> V_71 ) ;
}
if ( V_272 > V_48 -> V_49 -> V_275 )
V_48 -> V_49 -> V_275 = V_272 ;
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_62 ,
V_5 , V_230 -> V_71 , V_48 -> V_49 -> V_275 ) ;
if ( V_274 )
F_185 ( V_36 ) ;
}
void F_186 ( struct V_276 * V_228 )
{
struct V_8 * V_9 = F_22 ( V_228 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_277 )
V_9 -> V_10 -> V_277 ( V_228 ) ;
F_183 ( V_228 -> args . V_36 , & V_228 -> V_106 ) ;
}
int
F_101 ( struct V_36 * V_36 , bool V_278 )
{
struct V_276 * V_228 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_272 ;
int V_25 ;
if ( ! F_187 ( V_36 ) )
return 0 ;
F_3 ( L_63 , V_5 , V_36 -> V_107 ) ;
V_25 = - V_104 ;
if ( F_33 ( V_270 , & V_48 -> V_146 ) ) {
if ( ! V_278 )
goto V_4;
V_25 = F_188 ( & V_48 -> V_146 ,
V_270 ,
V_279 ,
V_280 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_143 ;
V_228 = F_90 ( sizeof( * V_228 ) , V_213 ) ;
if ( ! V_228 )
goto V_281;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_35 ( V_145 , & V_48 -> V_146 ) )
goto V_190;
F_45 ( & V_228 -> V_106 ) ;
F_182 ( V_36 , & V_228 -> V_106 ) ;
V_272 = V_48 -> V_49 -> V_275 ;
V_48 -> V_49 -> V_275 = 0 ;
F_82 ( & V_228 -> args . V_126 , & V_48 -> V_49 -> V_117 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_228 -> args . V_36 = V_36 ;
V_228 -> V_142 = F_111 ( V_48 -> V_49 -> V_45 ) ;
F_189 ( & V_228 -> V_282 ) ;
V_228 -> args . V_283 = F_22 ( V_36 ) -> V_284 ;
V_228 -> V_197 . V_282 = & V_228 -> V_282 ;
V_228 -> args . V_285 = V_272 - 1 ;
V_228 -> V_197 . V_14 = F_22 ( V_36 ) ;
V_25 = F_190 ( V_228 , V_278 ) ;
V_4:
if ( V_25 )
F_185 ( V_36 ) ;
F_3 ( L_64 , V_5 , V_25 ) ;
return V_25 ;
V_190:
F_7 ( & V_36 -> V_52 ) ;
F_191 ( V_228 ) ;
V_281:
F_178 ( V_36 ) ;
goto V_4;
}
struct V_167 * F_192 ( void )
{
struct V_167 * V_286 ;
V_286 = F_90 ( sizeof( * V_286 ) , V_213 ) ;
if ( ! V_286 ) {
F_3 ( L_65 , V_5 ) ;
return NULL ;
}
return V_286 ;
}
