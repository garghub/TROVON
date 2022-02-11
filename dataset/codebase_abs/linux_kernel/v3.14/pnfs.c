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
return ( V_114 ) V_112 - ( V_114 ) V_113 > 0 ;
}
void
F_78 ( struct V_33 * V_34 , const T_4 * V_115 ,
bool V_116 )
{
T_1 V_117 , V_118 , V_119 ;
int V_120 = F_24 ( & V_34 -> V_78 ) ;
V_117 = F_79 ( V_34 -> V_121 . V_122 ) ;
V_118 = F_79 ( V_115 -> V_122 ) ;
if ( V_120 || F_77 ( V_118 , V_117 ) ) {
F_80 ( & V_34 -> V_121 , V_115 ) ;
if ( V_116 ) {
V_119 = F_79 ( V_115 -> V_122 ) ;
} else {
V_119 = V_118 - F_55 ( & V_34 -> V_123 ) ;
}
if ( V_120 || F_77 ( V_119 , V_34 -> V_124 ) )
V_34 -> V_124 = V_119 ;
}
}
static bool
F_81 ( const struct V_33 * V_34 ,
const T_4 * V_125 )
{
T_1 V_122 = F_79 ( V_125 -> V_122 ) ;
return ! F_77 ( V_122 , V_34 -> V_124 ) ;
}
static bool
F_82 ( const struct V_33 * V_34 , int V_126 )
{
return V_34 -> V_100 ||
F_42 ( V_79 , & V_34 -> V_60 ) ||
( F_24 ( & V_34 -> V_78 ) &&
( F_55 ( & V_34 -> V_123 ) > V_126 ) ) ;
}
int
F_83 ( T_4 * V_127 , struct V_33 * V_34 ,
struct V_128 * V_129 )
{
int V_25 = 0 ;
F_3 ( L_27 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_52 ) ;
if ( F_82 ( V_34 , 1 ) ) {
V_25 = - V_104 ;
} else if ( ! F_84 ( V_129 ) ) {
V_25 = - V_130 ;
} else if ( F_24 ( & V_34 -> V_78 ) ) {
int V_131 ;
do {
V_131 = F_85 ( & V_129 -> V_132 ) ;
F_80 ( V_127 , & V_129 -> V_125 ) ;
} while ( F_86 ( & V_129 -> V_132 , V_131 ) );
} else
F_80 ( V_127 , & V_34 -> V_121 ) ;
F_7 ( & V_34 -> V_41 -> V_52 ) ;
F_3 ( L_28 , V_5 ) ;
return V_25 ;
}
static struct V_70 *
F_87 ( struct V_33 * V_34 ,
struct V_133 * V_134 ,
struct V_61 * V_62 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_135 * V_136 ;
struct V_70 * V_71 ;
F_3 ( L_27 , V_5 ) ;
V_136 = F_88 ( sizeof( * V_136 ) , V_38 ) ;
if ( V_136 == NULL )
return NULL ;
V_136 -> args . V_137 = V_138 ;
if ( V_136 -> args . V_137 > V_62 -> V_64 )
V_136 -> args . V_137 = V_62 -> V_64 ;
V_136 -> args . V_139 = V_140 ;
V_136 -> args . V_62 = * V_62 ;
V_136 -> args . type = V_14 -> V_10 -> V_2 ;
V_136 -> args . V_36 = V_37 ;
V_136 -> args . V_134 = F_89 ( V_134 ) ;
V_136 -> V_38 = V_38 ;
V_136 -> V_141 = V_34 -> V_45 ;
V_71 = F_90 ( V_136 , V_38 ) ;
if ( F_91 ( V_71 ) ) {
switch ( F_92 ( V_71 ) ) {
case - V_142 :
case - V_143 :
break;
default:
F_37 ( V_34 , V_62 -> V_53 ) ;
}
return NULL ;
}
return V_71 ;
}
static void F_93 ( struct V_36 * V_36 ,
struct V_91 * V_66 )
{
struct V_47 * V_48 = F_28 ( V_36 ) ;
struct V_70 * V_71 , * V_27 ;
if ( ! F_35 ( V_144 , & V_48 -> V_145 ) )
return;
F_62 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_35 ( V_146 , & V_71 -> V_76 ) )
continue;
F_60 ( V_71 , V_66 ) ;
}
}
int
F_94 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
F_38 ( V_92 ) ;
struct V_147 * V_148 ;
T_4 V_125 ;
int V_25 = 0 , V_120 ;
F_3 ( L_29 , V_5 , V_37 -> V_107 ) ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = V_48 -> V_49 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_52 ) ;
F_3 ( L_30 , V_5 ) ;
goto V_4;
}
V_125 = V_48 -> V_49 -> V_121 ;
F_20 ( V_34 ) ;
V_120 = F_24 ( & V_34 -> V_78 ) ;
F_93 ( V_37 , & V_92 ) ;
F_39 ( V_34 , & V_92 , NULL ) ;
if ( V_120 ) {
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
V_34 -> V_100 ++ ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_92 ) ;
V_148 = F_88 ( sizeof( * V_148 ) , V_149 ) ;
if ( F_95 ( V_148 == NULL ) ) {
V_25 = - V_142 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 -> V_100 -- ;
F_7 ( & V_37 -> V_52 ) ;
F_29 ( V_34 ) ;
goto V_4;
}
V_148 -> args . V_125 = V_125 ;
V_148 -> args . V_150 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_148 -> args . V_36 = V_37 ;
V_148 -> args . V_49 = V_34 ;
V_148 -> V_43 = F_22 ( V_37 ) -> V_12 ;
V_148 -> V_141 = V_34 -> V_45 ;
V_25 = F_96 ( V_148 ) ;
V_4:
F_3 ( L_32 , V_5 , V_25 ) ;
return V_25 ;
}
int
F_97 ( struct V_36 * V_36 )
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
F_98 ( V_36 -> V_151 ) ;
V_102 = F_99 ( V_36 , true ) ;
if ( V_102 == 0 )
V_102 = F_94 ( V_36 ) ;
F_5 ( & V_36 -> V_52 ) ;
V_34 -> V_100 -- ;
F_7 ( & V_36 -> V_52 ) ;
F_29 ( V_34 ) ;
return V_102 ;
}
bool F_100 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
struct V_70 * V_71 , * V_27 ;
F_38 ( V_92 ) ;
bool V_152 = false ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( ! V_34 || ! F_35 ( V_153 , & V_34 -> V_60 ) ||
F_42 ( V_79 , & V_34 -> V_60 ) )
goto V_154;
F_62 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_42 ( V_155 , & V_71 -> V_76 ) ) {
F_61 ( V_71 , & V_92 ) ;
V_152 = true ;
}
if ( ! V_152 )
goto V_154;
V_34 -> V_100 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_52 ) ;
F_40 ( & V_92 ) ;
return true ;
V_154:
F_7 ( & V_37 -> V_52 ) ;
return false ;
}
void F_101 ( struct V_36 * V_37 )
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
void F_102 ( struct V_36 * V_37 , T_1 V_156 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_28 ( V_37 ) -> V_49 ;
if ( F_77 ( V_156 , V_34 -> V_124 ) )
V_34 -> V_124 = V_156 ;
F_7 ( & V_37 -> V_52 ) ;
}
bool F_103 ( struct V_36 * V_37 , T_1 * V_156 , struct V_157 * V_158 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_34 ;
struct V_70 * V_71 ;
T_1 V_159 ;
bool V_152 = false ;
F_5 ( & V_37 -> V_52 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_42 ( V_155 , & V_71 -> V_76 ) ) {
F_104 ( & F_22 ( V_37 ) -> V_80 , V_158 , NULL ) ;
V_152 = true ;
goto V_4;
}
V_34 = V_48 -> V_49 ;
V_159 = F_79 ( V_34 -> V_121 . V_122 ) ;
* V_156 = V_159 + F_55 ( & V_34 -> V_123 ) ;
V_4:
F_7 ( & V_37 -> V_52 ) ;
return V_152 ;
}
static T_5
F_105 ( const struct V_61 * V_82 ,
const struct V_61 * V_83 )
{
T_5 V_160 ;
V_160 = V_82 -> V_63 - V_83 -> V_63 ;
if ( V_160 )
return V_160 ;
V_160 = V_83 -> V_64 - V_82 -> V_64 ;
if ( V_160 )
return V_160 ;
return ( int ) ( V_82 -> V_53 == V_161 ) - ( int ) ( V_83 -> V_53 == V_161 ) ;
}
static void
F_106 ( struct V_33 * V_34 ,
struct V_70 * V_71 )
{
struct V_70 * V_162 ;
F_3 ( L_33 , V_5 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_105 ( & V_71 -> V_97 , & V_162 -> V_97 ) > 0 )
continue;
F_107 ( & V_71 -> V_72 , & V_162 -> V_72 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_71 , V_71 -> V_97 . V_53 ,
V_71 -> V_97 . V_63 , V_71 -> V_97 . V_64 ,
V_162 , V_162 -> V_97 . V_53 , V_162 -> V_97 . V_63 ,
V_162 -> V_97 . V_64 ) ;
goto V_4;
}
F_107 ( & V_71 -> V_72 , & V_34 -> V_78 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_71 , V_71 -> V_97 . V_53 ,
V_71 -> V_97 . V_63 , V_71 -> V_97 . V_64 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_38 , V_5 ) ;
}
static struct V_33 *
F_108 ( struct V_36 * V_37 ,
struct V_133 * V_134 ,
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
V_34 -> V_45 = F_109 ( V_134 -> V_141 ) ;
return V_34 ;
}
static struct V_33 *
F_110 ( struct V_36 * V_37 ,
struct V_133 * V_134 ,
T_2 V_38 )
{
struct V_47 * V_48 = F_28 ( V_37 ) ;
struct V_33 * V_115 = NULL ;
F_3 ( L_39 , V_5 , V_37 , V_48 -> V_49 ) ;
if ( V_48 -> V_49 != NULL )
goto V_163;
F_7 ( & V_37 -> V_52 ) ;
V_115 = F_108 ( V_37 , V_134 , V_38 ) ;
F_5 ( & V_37 -> V_52 ) ;
if ( F_111 ( V_48 -> V_49 == NULL ) ) {
V_48 -> V_49 = V_115 ;
return V_115 ;
} else if ( V_115 != NULL )
F_23 ( V_115 ) ;
V_163:
F_20 ( V_48 -> V_49 ) ;
return V_48 -> V_49 ;
}
static bool
F_112 ( const struct V_61 * V_164 ,
const struct V_61 * V_62 )
{
struct V_61 V_165 ;
if ( ( V_62 -> V_53 == V_54 &&
V_164 -> V_53 != V_54 ) ||
! F_58 ( V_164 , V_62 ) )
return 0 ;
V_165 = * V_62 ;
V_165 . V_64 = 1 ;
return F_57 ( V_164 , & V_165 ) ;
}
static struct V_70 *
F_113 ( struct V_33 * V_34 ,
struct V_61 * V_62 )
{
struct V_70 * V_71 , * V_102 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_42 ( V_75 , & V_71 -> V_76 ) &&
F_112 ( & V_71 -> V_97 , V_62 ) ) {
V_102 = F_114 ( V_71 ) ;
break;
}
if ( V_71 -> V_97 . V_63 > V_62 -> V_63 )
break;
}
F_3 ( L_40 ,
V_5 , V_102 , V_102 ? F_55 ( & V_102 -> V_74 ) : 0 ) ;
return V_102 ;
}
static bool F_115 ( struct V_133 * V_134 ,
struct V_36 * V_37 , int V_53 )
{
struct V_166 * V_167 = V_134 -> V_168 ;
struct V_47 * V_48 = F_28 ( V_37 ) ;
T_6 V_169 = F_116 ( V_37 ) ;
bool V_170 = false , V_171 = false , V_172 = false , V_173 = false , V_102 = false ;
if ( V_167 == NULL )
return V_102 ;
F_3 ( L_41 ,
V_5 , V_167 -> V_174 , V_167 -> V_175 , V_167 -> V_176 , V_167 -> V_177 , V_167 -> V_178 ) ;
switch ( V_53 ) {
case V_161 :
if ( V_167 -> V_174 & V_179 ) {
F_3 ( L_42 , V_5 , V_169 ) ;
V_171 = true ;
if ( V_169 < V_167 -> V_175 )
V_170 = true ;
}
if ( V_167 -> V_174 & V_180 ) {
F_3 ( L_43 , V_5 ,
V_48 -> V_51 ) ;
V_173 = true ;
if ( V_48 -> V_51 < V_167 -> V_177 )
V_172 = true ;
}
break;
case V_54 :
if ( V_167 -> V_174 & V_181 ) {
F_3 ( L_42 , V_5 , V_169 ) ;
V_171 = true ;
if ( V_169 < V_167 -> V_176 )
V_170 = true ;
}
if ( V_167 -> V_174 & V_182 ) {
F_3 ( L_44 , V_5 ,
V_48 -> V_50 ) ;
V_173 = true ;
if ( V_48 -> V_50 < V_167 -> V_178 )
V_172 = true ;
}
break;
}
if ( V_171 && V_173 ) {
if ( V_170 && V_172 )
V_102 = true ;
} else if ( V_170 || V_172 )
V_102 = true ;
F_3 ( L_45 , V_5 , V_170 , V_172 , V_102 ) ;
return V_102 ;
}
struct V_70 *
F_117 ( struct V_36 * V_37 ,
struct V_133 * V_134 ,
T_6 V_183 ,
T_3 V_184 ,
enum V_185 V_53 ,
T_2 V_38 )
{
struct V_61 V_186 = {
. V_53 = V_53 ,
. V_63 = V_183 ,
. V_64 = V_184 ,
} ;
unsigned V_187 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_43 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_70 * V_71 = NULL ;
bool V_188 ;
if ( ! F_118 ( F_22 ( V_37 ) ) )
goto V_4;
if ( F_115 ( V_134 , V_37 , V_53 ) )
goto V_4;
F_5 ( & V_37 -> V_52 ) ;
V_34 = F_110 ( V_37 , V_134 , V_38 ) ;
if ( V_34 == NULL ) {
F_7 ( & V_37 -> V_52 ) ;
goto V_4;
}
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_46 , V_5 ) ;
goto V_189;
}
if ( F_41 ( V_34 , V_53 ) )
goto V_189;
V_71 = F_113 ( V_34 , & V_186 ) ;
if ( V_71 )
goto V_189;
if ( F_82 ( V_34 , 0 ) )
goto V_189;
F_15 ( & V_34 -> V_123 ) ;
V_188 = F_24 ( & V_34 -> V_42 ) ? true : false ;
F_7 ( & V_37 -> V_52 ) ;
if ( V_188 ) {
F_5 ( & V_43 -> V_44 ) ;
F_107 ( & V_34 -> V_42 , & V_14 -> V_190 ) ;
F_7 ( & V_43 -> V_44 ) ;
}
V_187 = V_186 . V_63 & ~ V_191 ;
if ( V_187 ) {
V_186 . V_63 -= V_187 ;
V_186 . V_64 += V_187 ;
}
if ( V_186 . V_64 != V_65 )
V_186 . V_64 = F_119 ( V_186 . V_64 ) ;
V_71 = F_87 ( V_34 , V_134 , & V_186 , V_38 ) ;
F_36 ( & V_34 -> V_123 ) ;
V_192:
F_29 ( V_34 ) ;
V_4:
F_3 ( L_47
L_48 ,
V_5 , V_37 -> V_193 -> V_194 ,
( unsigned long long ) F_120 ( V_37 ) ,
V_71 == NULL ? L_49 : L_50 ,
V_53 == V_54 ? L_51 : L_52 ,
( unsigned long long ) V_183 ,
( unsigned long long ) V_184 ) ;
return V_71 ;
V_189:
F_7 ( & V_37 -> V_52 ) ;
goto V_192;
}
struct V_70 *
F_121 ( struct V_135 * V_136 )
{
struct V_33 * V_34 = F_28 ( V_136 -> args . V_36 ) -> V_49 ;
struct V_195 * V_196 = & V_136 -> V_196 ;
struct V_70 * V_71 ;
struct V_36 * V_37 = V_34 -> V_41 ;
int V_25 = 0 ;
V_71 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_196 , V_136 -> V_38 ) ;
if ( ! V_71 || F_91 ( V_71 ) ) {
if ( ! V_71 )
V_25 = - V_142 ;
else
V_25 = F_92 ( V_71 ) ;
F_3 ( L_53 ,
V_5 , V_25 ) ;
goto V_4;
}
F_5 ( & V_37 -> V_52 ) ;
if ( F_42 ( V_79 , & V_34 -> V_60 ) ) {
F_3 ( L_54 , V_5 ) ;
goto V_197;
}
if ( F_82 ( V_34 , 1 ) ||
F_81 ( V_34 , & V_196 -> V_125 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_197;
}
F_78 ( V_34 , & V_196 -> V_125 , false ) ;
F_44 ( V_34 , V_71 ) ;
V_71 -> V_97 = V_196 -> V_62 ;
F_114 ( V_71 ) ;
F_106 ( V_34 , V_71 ) ;
if ( V_196 -> V_198 ) {
F_48 ( V_155 , & V_71 -> V_76 ) ;
F_48 ( V_153 , & V_34 -> V_60 ) ;
}
F_7 ( & V_37 -> V_52 ) ;
return V_71 ;
V_4:
return F_122 ( V_25 ) ;
V_197:
F_7 ( & V_37 -> V_52 ) ;
V_71 -> V_77 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_71 ) ;
goto V_4;
}
void
F_123 ( struct V_199 * V_200 , struct V_201 * V_202 )
{
T_3 V_203 = V_202 -> V_204 ;
F_124 ( V_200 -> V_205 != NULL ) ;
if ( V_202 -> V_206 != V_202 -> V_207 ) {
F_125 ( V_200 ) ;
return;
}
if ( V_200 -> V_208 == NULL )
V_203 = F_116 ( V_200 -> V_209 ) - F_126 ( V_202 ) ;
else
V_203 = F_127 ( V_200 -> V_208 ) ;
V_200 -> V_205 = F_117 ( V_200 -> V_209 ,
V_202 -> V_210 ,
F_126 ( V_202 ) ,
V_203 ,
V_161 ,
V_149 ) ;
if ( V_200 -> V_205 == NULL )
F_125 ( V_200 ) ;
}
void
F_128 ( struct V_199 * V_200 ,
struct V_201 * V_202 , T_3 V_211 )
{
F_124 ( V_200 -> V_205 != NULL ) ;
if ( V_202 -> V_206 != V_202 -> V_207 ) {
F_129 ( V_200 ) ;
return;
}
V_200 -> V_205 = F_117 ( V_200 -> V_209 ,
V_202 -> V_210 ,
F_126 ( V_202 ) ,
V_211 ,
V_54 ,
V_212 ) ;
if ( V_200 -> V_205 == NULL )
F_129 ( V_200 ) ;
}
void
F_130 ( struct V_199 * V_200 , struct V_36 * V_36 ,
const struct V_213 * V_214 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_131 ( V_200 , V_36 , V_214 ) ;
else
F_132 ( V_200 , V_36 , V_39 -> V_215 , V_214 , V_14 -> V_216 , 0 ) ;
}
void
F_133 ( struct V_199 * V_200 , struct V_36 * V_36 ,
int V_217 ,
const struct V_213 * V_214 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_134 ( V_200 , V_36 , V_217 , V_214 ) ;
else
F_132 ( V_200 , V_36 , V_39 -> V_218 , V_214 , V_14 -> V_219 , V_217 ) ;
}
bool
F_135 ( struct V_199 * V_200 , struct V_201 * V_220 ,
struct V_201 * V_202 )
{
if ( V_200 -> V_205 == NULL )
return F_136 ( V_200 , V_220 , V_202 ) ;
return F_126 ( V_202 ) < F_56 ( V_200 -> V_205 -> V_97 . V_63 ,
V_200 -> V_205 -> V_97 . V_64 ) ;
}
int F_137 ( struct V_36 * V_36 ,
struct V_91 * V_66 ,
const struct V_213 * V_214 ,
struct V_221 * V_222 )
{
struct V_199 V_200 ;
F_38 ( V_223 ) ;
F_134 ( & V_200 , V_36 , V_224 , V_214 ) ;
V_200 . V_208 = V_222 ;
while ( ! F_24 ( V_66 ) ) {
struct V_201 * V_202 = F_138 ( V_66 -> V_94 ) ;
F_139 ( V_202 ) ;
if ( ! F_140 ( & V_200 , V_202 ) )
F_141 ( V_202 , & V_223 ) ;
}
F_142 ( & V_200 ) ;
if ( ! F_24 ( & V_223 ) ) {
F_143 ( & V_223 , V_66 ) ;
return - V_225 ;
}
return 0 ;
}
static void F_144 ( struct V_226 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_230 ;
F_3 ( L_56 , V_229 -> V_231 ) ;
if ( F_22 ( V_229 -> V_36 ) -> V_10 -> V_145 &
V_232 ) {
F_145 ( V_229 -> V_36 ) ;
}
if ( ! F_33 ( V_233 , & V_229 -> V_145 ) )
V_227 -> V_158 . V_234 = F_137 ( V_229 -> V_36 ,
& V_229 -> V_235 ,
V_229 -> V_236 ,
V_229 -> V_222 ) ;
}
void F_146 ( struct V_226 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_230 ;
F_147 ( V_227 , V_229 -> V_231 ) ;
if ( ! V_229 -> V_231 ) {
F_148 ( V_227 ) ;
V_229 -> V_237 -> V_238 ( & V_227 -> V_158 , V_227 ) ;
} else
F_144 ( V_227 ) ;
V_229 -> V_237 -> V_239 ( V_227 ) ;
}
static void
F_149 ( struct V_199 * V_240 ,
struct V_226 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_230 ;
if ( ! F_33 ( V_233 , & V_229 -> V_145 ) ) {
F_150 ( & V_229 -> V_235 , & V_240 -> V_241 ) ;
F_129 ( V_240 ) ;
V_240 -> V_242 = 1 ;
}
F_151 ( V_227 ) ;
}
static enum V_243
F_152 ( struct V_226 * V_244 ,
const struct V_245 * V_246 ,
struct V_70 * V_71 ,
int V_247 )
{
struct V_228 * V_229 = V_244 -> V_230 ;
struct V_36 * V_36 = V_229 -> V_36 ;
enum V_243 V_248 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_229 -> V_237 = V_246 ;
F_3 ( L_57 , V_5 ,
V_36 -> V_107 , V_244 -> args . V_184 , V_244 -> args . V_63 , V_247 ) ;
V_248 = V_9 -> V_10 -> V_249 ( V_244 , V_247 ) ;
if ( V_248 != V_250 )
F_153 ( V_36 , V_251 ) ;
F_3 ( L_58 , V_5 , V_248 ) ;
return V_248 ;
}
static void
F_154 ( struct V_199 * V_240 , struct V_91 * V_66 , int V_247 )
{
struct V_226 * V_227 ;
const struct V_245 * V_246 = V_240 -> V_252 ;
struct V_70 * V_71 = V_240 -> V_205 ;
V_240 -> V_205 = NULL ;
while ( ! F_24 ( V_66 ) ) {
enum V_243 V_248 ;
V_227 = F_155 ( V_66 , struct V_226 , V_253 ) ;
F_25 ( & V_227 -> V_253 ) ;
V_248 = F_152 ( V_227 , V_246 , V_71 , V_247 ) ;
if ( V_248 == V_250 )
F_149 ( V_240 , V_227 ) ;
}
F_54 ( V_71 ) ;
}
static void F_156 ( struct V_228 * V_229 )
{
F_54 ( V_229 -> V_71 ) ;
F_157 ( V_229 ) ;
}
int
F_158 ( struct V_199 * V_240 )
{
struct V_254 * V_255 ;
struct V_228 * V_229 ;
int V_102 ;
V_255 = F_159 () ;
if ( ! V_255 ) {
V_240 -> V_256 -> V_257 ( & V_240 -> V_241 ) ;
F_54 ( V_240 -> V_205 ) ;
V_240 -> V_205 = NULL ;
return - V_142 ;
}
V_229 = & V_255 -> V_230 ;
F_160 ( V_240 , V_229 , F_156 ) ;
V_229 -> V_71 = F_114 ( V_240 -> V_205 ) ;
F_15 ( & V_229 -> V_258 ) ;
V_102 = F_161 ( V_240 , V_229 ) ;
if ( V_102 != 0 ) {
F_54 ( V_240 -> V_205 ) ;
V_240 -> V_205 = NULL ;
} else
F_154 ( V_240 , & V_229 -> V_259 , V_240 -> V_260 ) ;
if ( F_9 ( & V_229 -> V_258 ) )
V_229 -> V_236 -> V_261 ( V_229 ) ;
return V_102 ;
}
int F_162 ( struct V_36 * V_36 ,
struct V_91 * V_66 ,
const struct V_213 * V_214 ,
struct V_221 * V_222 )
{
struct V_199 V_200 ;
F_38 ( V_223 ) ;
F_131 ( & V_200 , V_36 , V_214 ) ;
V_200 . V_208 = V_222 ;
while ( ! F_24 ( V_66 ) ) {
struct V_201 * V_202 = F_138 ( V_66 -> V_94 ) ;
F_139 ( V_202 ) ;
if ( ! F_140 ( & V_200 , V_202 ) )
F_141 ( V_202 , & V_223 ) ;
}
F_142 ( & V_200 ) ;
if ( ! F_24 ( & V_223 ) ) {
F_143 ( & V_223 , V_66 ) ;
return - V_225 ;
}
return 0 ;
}
static void F_163 ( struct V_262 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_230 ;
F_3 ( L_59 , V_229 -> V_231 ) ;
if ( F_22 ( V_229 -> V_36 ) -> V_10 -> V_145 &
V_232 ) {
F_145 ( V_229 -> V_36 ) ;
}
if ( ! F_33 ( V_233 , & V_229 -> V_145 ) )
V_227 -> V_158 . V_234 = F_162 ( V_229 -> V_36 ,
& V_229 -> V_235 ,
V_229 -> V_236 ,
V_229 -> V_222 ) ;
}
void F_164 ( struct V_262 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_230 ;
F_165 ( V_227 , V_229 -> V_231 ) ;
if ( F_111 ( ! V_229 -> V_231 ) ) {
F_166 ( V_227 ) ;
V_229 -> V_237 -> V_238 ( & V_227 -> V_158 , V_227 ) ;
} else
F_163 ( V_227 ) ;
V_229 -> V_237 -> V_239 ( V_227 ) ;
}
static void
F_167 ( struct V_199 * V_240 ,
struct V_262 * V_227 )
{
struct V_228 * V_229 = V_227 -> V_230 ;
if ( ! F_33 ( V_233 , & V_229 -> V_145 ) ) {
F_150 ( & V_229 -> V_235 , & V_240 -> V_241 ) ;
F_125 ( V_240 ) ;
V_240 -> V_242 = 1 ;
}
F_168 ( V_227 ) ;
}
static enum V_243
F_169 ( struct V_262 * V_263 ,
const struct V_245 * V_246 ,
struct V_70 * V_71 )
{
struct V_228 * V_229 = V_263 -> V_230 ;
struct V_36 * V_36 = V_229 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_243 V_248 ;
V_229 -> V_237 = V_246 ;
F_3 ( L_60 ,
V_5 , V_36 -> V_107 , V_263 -> args . V_184 , V_263 -> args . V_63 ) ;
V_248 = V_9 -> V_10 -> V_264 ( V_263 ) ;
if ( V_248 != V_250 )
F_153 ( V_36 , V_265 ) ;
F_3 ( L_58 , V_5 , V_248 ) ;
return V_248 ;
}
static void
F_170 ( struct V_199 * V_240 , struct V_91 * V_66 )
{
struct V_262 * V_227 ;
const struct V_245 * V_246 = V_240 -> V_252 ;
struct V_70 * V_71 = V_240 -> V_205 ;
V_240 -> V_205 = NULL ;
while ( ! F_24 ( V_66 ) ) {
enum V_243 V_248 ;
V_227 = F_155 ( V_66 , struct V_262 , V_253 ) ;
F_25 ( & V_227 -> V_253 ) ;
V_248 = F_169 ( V_227 , V_246 , V_71 ) ;
if ( V_248 == V_250 )
F_167 ( V_240 , V_227 ) ;
}
F_54 ( V_71 ) ;
}
static void F_171 ( struct V_228 * V_229 )
{
F_54 ( V_229 -> V_71 ) ;
F_172 ( V_229 ) ;
}
int
F_173 ( struct V_199 * V_240 )
{
struct V_266 * V_267 ;
struct V_228 * V_229 ;
int V_102 ;
V_267 = F_174 () ;
if ( ! V_267 ) {
V_240 -> V_256 -> V_257 ( & V_240 -> V_241 ) ;
V_102 = - V_142 ;
F_54 ( V_240 -> V_205 ) ;
V_240 -> V_205 = NULL ;
return V_102 ;
}
V_229 = & V_267 -> V_230 ;
F_160 ( V_240 , V_229 , F_171 ) ;
V_229 -> V_71 = F_114 ( V_240 -> V_205 ) ;
F_15 ( & V_229 -> V_258 ) ;
V_102 = F_175 ( V_240 , V_229 ) ;
if ( V_102 != 0 ) {
F_54 ( V_240 -> V_205 ) ;
V_240 -> V_205 = NULL ;
} else
F_170 ( V_240 , & V_229 -> V_259 ) ;
if ( F_9 ( & V_229 -> V_258 ) )
V_229 -> V_236 -> V_261 ( V_229 ) ;
return V_102 ;
}
static void F_176 ( struct V_36 * V_36 )
{
unsigned long * V_268 = & F_28 ( V_36 ) -> V_145 ;
F_177 ( V_269 , V_268 ) ;
F_178 () ;
F_179 ( V_268 , V_269 ) ;
}
static void F_180 ( struct V_36 * V_36 , struct V_91 * V_270 )
{
struct V_70 * V_71 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_71 -> V_97 . V_53 == V_54 &&
F_35 ( V_146 , & V_71 -> V_76 ) )
F_17 ( & V_71 -> V_73 , V_270 ) ;
}
}
static void F_181 ( struct V_36 * V_36 , struct V_91 * V_270 )
{
struct V_70 * V_71 , * V_27 ;
F_62 (lseg, tmp, listp, pls_lc_list) {
F_25 ( & V_71 -> V_73 ) ;
F_54 ( V_71 ) ;
}
F_176 ( V_36 ) ;
}
void F_182 ( struct V_70 * V_71 )
{
F_37 ( V_71 -> V_77 , V_71 -> V_97 . V_53 ) ;
}
void
F_148 ( struct V_226 * V_244 )
{
struct V_228 * V_229 = V_244 -> V_230 ;
struct V_36 * V_36 = V_229 -> V_36 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_271 = V_244 -> V_272 + V_244 -> V_196 . V_184 ;
bool V_273 = false ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_33 ( V_144 , & V_48 -> V_145 ) ) {
V_273 = true ;
F_3 ( L_61 ,
V_5 , V_36 -> V_107 ) ;
}
if ( ! F_33 ( V_146 , & V_229 -> V_71 -> V_76 ) ) {
F_114 ( V_229 -> V_71 ) ;
}
if ( V_271 > V_48 -> V_49 -> V_274 )
V_48 -> V_49 -> V_274 = V_271 ;
F_7 ( & V_36 -> V_52 ) ;
F_3 ( L_62 ,
V_5 , V_229 -> V_71 , V_48 -> V_49 -> V_274 ) ;
if ( V_273 )
F_183 ( V_36 ) ;
}
void F_184 ( struct V_275 * V_227 )
{
struct V_8 * V_9 = F_22 ( V_227 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_276 )
V_9 -> V_10 -> V_276 ( V_227 ) ;
F_181 ( V_227 -> args . V_36 , & V_227 -> V_106 ) ;
}
int
F_99 ( struct V_36 * V_36 , bool V_277 )
{
struct V_275 * V_227 ;
struct V_47 * V_48 = F_28 ( V_36 ) ;
T_6 V_271 ;
int V_25 ;
if ( ! F_185 ( V_36 ) )
return 0 ;
F_3 ( L_63 , V_5 , V_36 -> V_107 ) ;
V_25 = - V_104 ;
if ( F_33 ( V_269 , & V_48 -> V_145 ) ) {
if ( ! V_277 )
goto V_4;
V_25 = F_186 ( & V_48 -> V_145 ,
V_269 ,
V_278 ,
V_279 ) ;
if ( V_25 )
goto V_4;
}
V_25 = - V_142 ;
V_227 = F_88 ( sizeof( * V_227 ) , V_212 ) ;
if ( ! V_227 )
goto V_280;
V_25 = 0 ;
F_5 ( & V_36 -> V_52 ) ;
if ( ! F_35 ( V_144 , & V_48 -> V_145 ) )
goto V_189;
F_45 ( & V_227 -> V_106 ) ;
F_180 ( V_36 , & V_227 -> V_106 ) ;
V_271 = V_48 -> V_49 -> V_274 ;
V_48 -> V_49 -> V_274 = 0 ;
F_80 ( & V_227 -> args . V_125 , & V_48 -> V_49 -> V_121 ) ;
F_7 ( & V_36 -> V_52 ) ;
V_227 -> args . V_36 = V_36 ;
V_227 -> V_141 = F_109 ( V_48 -> V_49 -> V_45 ) ;
F_187 ( & V_227 -> V_281 ) ;
V_227 -> args . V_282 = F_22 ( V_36 ) -> V_283 ;
V_227 -> V_196 . V_281 = & V_227 -> V_281 ;
V_227 -> args . V_284 = V_271 - 1 ;
V_227 -> V_196 . V_14 = F_22 ( V_36 ) ;
V_25 = F_188 ( V_227 , V_277 ) ;
V_4:
if ( V_25 )
F_183 ( V_36 ) ;
F_3 ( L_64 , V_5 , V_25 ) ;
return V_25 ;
V_189:
F_7 ( & V_36 -> V_52 ) ;
F_189 ( V_227 ) ;
V_280:
F_176 ( V_36 ) ;
goto V_4;
}
struct V_166 * F_190 ( void )
{
struct V_166 * V_285 ;
V_285 = F_88 ( sizeof( * V_285 ) , V_212 ) ;
if ( ! V_285 ) {
F_3 ( L_65 , V_5 ) ;
return NULL ;
}
return V_285 ;
}
