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
static void
F_35 ( struct V_43 * V_44 , enum V_64 V_65 ,
T_1 V_66 )
{
if ( V_44 -> V_67 != 0 && V_44 -> V_67 != V_65 )
V_65 = V_68 ;
V_44 -> V_67 = V_65 ;
F_36 ( V_69 , & V_44 -> V_70 ) ;
if ( V_66 != 0 ) {
F_37 ( V_44 -> V_71 != 0 && V_44 -> V_71 != V_66 ) ;
V_44 -> V_71 = V_66 ;
}
}
static void
F_38 ( struct V_43 * V_44 )
{
struct V_72 * V_73 ;
V_44 -> V_67 = 0 ;
V_44 -> V_71 = 0 ;
F_39 ( V_69 , & V_44 -> V_70 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( ! F_40 ( V_74 , & V_73 -> V_75 ) )
continue;
F_35 ( V_44 , V_73 -> V_76 . V_65 , 0 ) ;
}
}
static void F_41 ( struct V_43 * V_44 )
{
F_42 ( V_77 , & V_44 -> V_70 ) ;
F_39 ( V_78 , & V_44 -> V_70 ) ;
F_43 () ;
F_44 ( & V_44 -> V_70 , V_77 ) ;
F_45 ( & F_24 ( V_44 -> V_51 ) -> V_79 ) ;
}
static void
F_46 ( struct V_72 * V_73 ,
struct V_80 * V_81 )
{
F_39 ( V_82 , & V_73 -> V_75 ) ;
F_39 ( V_74 , & V_73 -> V_75 ) ;
if ( F_47 ( V_83 , & V_73 -> V_75 ) )
F_48 ( V_73 , V_81 ) ;
if ( F_47 ( V_84 , & V_73 -> V_75 ) )
F_48 ( V_73 , V_81 ) ;
}
int
F_49 ( struct V_43 * V_44 ,
struct V_80 * V_85 )
{
struct V_86 V_87 = {
. V_65 = V_68 ,
. V_88 = 0 ,
. V_89 = V_90 ,
} ;
struct V_72 * V_73 , * V_91 ;
F_36 ( V_92 , & V_44 -> V_70 ) ;
F_50 (lseg, next, &lo->plh_segs, pls_list)
F_46 ( V_73 , V_85 ) ;
F_38 ( V_44 ) ;
F_51 ( V_44 , V_85 , & V_87 , 0 ) ;
if ( F_40 ( V_77 , & V_44 -> V_70 ) &&
! F_52 ( V_78 , & V_44 -> V_70 ) )
F_41 ( V_44 ) ;
return ! F_26 ( & V_44 -> V_63 ) ;
}
static int
F_53 ( T_1 V_65 )
{
return V_65 == V_93 ?
V_94 : V_95 ;
}
static void
F_54 ( struct V_43 * V_44 , int V_96 )
{
V_44 -> V_97 = V_98 ;
if ( ! F_52 ( V_96 , & V_44 -> V_70 ) )
F_17 ( & V_44 -> V_45 ) ;
}
static void
F_55 ( struct V_43 * V_44 , int V_96 )
{
if ( F_47 ( V_96 , & V_44 -> V_70 ) )
F_56 ( & V_44 -> V_45 ) ;
}
static void
F_57 ( struct V_43 * V_44 , T_1 V_65 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
struct V_86 V_87 = {
. V_65 = V_65 ,
. V_88 = 0 ,
. V_89 = V_90 ,
} ;
F_58 ( V_99 ) ;
F_5 ( & V_46 -> V_62 ) ;
F_54 ( V_44 , F_53 ( V_65 ) ) ;
F_59 ( V_44 , & V_99 , & V_87 , 0 ) ;
F_7 ( & V_46 -> V_62 ) ;
F_60 ( & V_99 ) ;
F_3 ( L_18 , V_5 ,
V_65 == V_93 ? L_19 : L_20 ) ;
}
static bool
F_61 ( struct V_43 * V_44 , T_1 V_65 )
{
unsigned long V_100 , V_101 ;
int V_96 = F_53 ( V_65 ) ;
if ( F_40 ( V_96 , & V_44 -> V_70 ) == 0 )
return false ;
V_101 = V_98 ;
V_100 = V_101 - V_102 ;
if ( ! F_62 ( V_44 -> V_97 , V_100 , V_101 ) ) {
F_55 ( V_44 , V_96 ) ;
return false ;
}
return true ;
}
static void
F_63 ( struct V_43 * V_44 , struct V_72 * V_73 ,
const struct V_86 * V_87 ,
const T_3 * V_103 )
{
F_64 ( & V_73 -> V_104 ) ;
F_64 ( & V_73 -> V_105 ) ;
F_65 ( & V_73 -> V_106 , 1 ) ;
F_36 ( V_83 , & V_73 -> V_75 ) ;
V_73 -> V_107 = V_44 ;
V_73 -> V_76 = * V_87 ;
V_73 -> V_108 = F_66 ( V_103 -> V_109 ) ;
}
static void F_67 ( struct V_72 * V_73 )
{
if ( V_73 != NULL ) {
struct V_46 * V_46 = V_73 -> V_107 -> V_51 ;
F_24 ( V_46 ) -> V_10 -> V_39 ( V_73 ) ;
}
}
static void
F_68 ( struct V_43 * V_44 ,
struct V_72 * V_73 )
{
F_69 ( F_40 ( V_83 , & V_73 -> V_75 ) ) ;
F_27 ( & V_73 -> V_104 ) ;
F_56 ( & V_44 -> V_45 ) ;
if ( F_40 ( V_74 , & V_73 -> V_75 ) )
return;
if ( F_26 ( & V_44 -> V_63 ) &&
! F_40 ( V_69 , & V_44 -> V_70 ) &&
! F_40 ( V_77 , & V_44 -> V_70 ) ) {
if ( F_70 ( & V_44 -> V_110 ) == 0 )
F_36 ( V_92 , & V_44 -> V_70 ) ;
F_39 ( V_111 , & V_44 -> V_70 ) ;
}
}
static bool
F_71 ( struct V_43 * V_44 ,
struct V_72 * V_73 )
{
if ( F_47 ( V_74 , & V_73 -> V_75 ) &&
F_72 ( V_44 ) ) {
F_35 ( V_44 , V_73 -> V_76 . V_65 , 0 ) ;
F_73 ( & V_73 -> V_104 , & V_44 -> V_112 ) ;
return true ;
}
return false ;
}
void
F_74 ( struct V_72 * V_73 )
{
struct V_43 * V_44 ;
struct V_46 * V_46 ;
if ( ! V_73 )
return;
F_3 ( L_21 , V_5 , V_73 ,
F_70 ( & V_73 -> V_106 ) ,
F_40 ( V_83 , & V_73 -> V_75 ) ) ;
V_44 = V_73 -> V_107 ;
V_46 = V_44 -> V_51 ;
if ( F_33 ( & V_73 -> V_106 , & V_46 -> V_62 ) ) {
if ( F_40 ( V_83 , & V_73 -> V_75 ) ) {
F_7 ( & V_46 -> V_62 ) ;
return;
}
F_22 ( V_44 ) ;
F_68 ( V_44 , V_73 ) ;
if ( F_71 ( V_44 , V_73 ) )
V_73 = NULL ;
F_7 ( & V_46 -> V_62 ) ;
F_67 ( V_73 ) ;
F_31 ( V_44 ) ;
}
}
static bool
F_75 ( const struct V_86 * V_113 ,
const struct V_86 * V_114 )
{
T_4 V_115 = V_113 -> V_88 ;
T_4 V_116 = F_76 ( V_115 , V_113 -> V_89 ) ;
T_4 V_117 = V_114 -> V_88 ;
T_4 V_118 = F_76 ( V_117 , V_114 -> V_89 ) ;
return ( V_115 <= V_117 ) && ( V_116 >= V_118 ) ;
}
static bool F_48 ( struct V_72 * V_73 ,
struct V_80 * V_119 )
{
if ( ! F_9 ( & V_73 -> V_106 ) )
return false ;
F_68 ( V_73 -> V_107 , V_73 ) ;
F_19 ( & V_73 -> V_104 , V_119 ) ;
return true ;
}
static int F_77 ( struct V_72 * V_73 ,
struct V_80 * V_119 )
{
int V_120 = 0 ;
if ( F_47 ( V_83 , & V_73 -> V_75 ) ) {
F_3 ( L_22 , V_5 , V_73 ,
F_70 ( & V_73 -> V_106 ) ) ;
if ( F_48 ( V_73 , V_119 ) )
V_120 = 1 ;
}
return V_120 ;
}
static bool F_78 ( T_1 V_121 , T_1 V_122 )
{
return ( V_123 ) ( V_121 - V_122 ) > 0 ;
}
static bool
F_79 ( const struct V_86 * V_124 ,
const struct V_86 * V_125 )
{
return ( V_125 -> V_65 == V_68 ||
V_124 -> V_65 == V_125 -> V_65 ) &&
F_80 ( V_124 , V_125 ) ;
}
static bool
F_81 ( const struct V_72 * V_73 ,
const struct V_86 * V_125 ,
T_1 V_66 )
{
if ( V_66 != 0 && F_78 ( V_73 -> V_108 , V_66 ) )
return false ;
if ( V_125 == NULL )
return true ;
return F_79 ( & V_73 -> V_76 , V_125 ) ;
}
int
F_59 ( struct V_43 * V_44 ,
struct V_80 * V_119 ,
const struct V_86 * V_125 ,
T_1 V_66 )
{
struct V_72 * V_73 , * V_91 ;
int V_126 = 0 ;
F_3 ( L_23 , V_5 , V_44 ) ;
if ( F_26 ( & V_44 -> V_63 ) )
return 0 ;
F_50 (lseg, next, &lo->plh_segs, pls_list)
if ( F_81 ( V_73 , V_125 , V_66 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_73 , V_73 -> V_76 . V_65 , V_73 -> V_108 ,
V_73 -> V_76 . V_88 , V_73 -> V_76 . V_89 ) ;
if ( ! F_77 ( V_73 , V_119 ) )
V_126 ++ ;
}
F_3 ( L_26 , V_5 , V_126 ) ;
return V_126 ;
}
static void
F_51 ( struct V_43 * V_44 ,
struct V_80 * V_81 ,
const struct V_86 * V_87 ,
T_1 V_66 )
{
struct V_72 * V_73 , * V_91 ;
F_50 (lseg, next, &lo->plh_return_segs, pls_list) {
if ( F_81 ( V_73 , V_87 , V_66 ) )
F_73 ( & V_73 -> V_104 , V_81 ) ;
}
}
void
F_60 ( struct V_80 * V_81 )
{
struct V_72 * V_73 , * V_37 ;
if ( F_26 ( V_81 ) )
return;
F_50 (lseg, tmp, free_me, pls_list) {
F_21 ( & V_73 -> V_104 ) ;
F_67 ( V_73 ) ;
}
}
void
F_82 ( struct V_57 * V_58 )
{
struct V_43 * V_44 ;
F_58 ( V_119 ) ;
F_5 ( & V_58 -> V_127 . V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( V_44 ) {
F_22 ( V_44 ) ;
F_49 ( V_44 , & V_119 ) ;
F_55 ( V_44 , V_95 ) ;
F_55 ( V_44 , V_94 ) ;
F_7 ( & V_58 -> V_127 . V_62 ) ;
F_60 ( & V_119 ) ;
F_83 ( & V_58 -> V_127 , 0 ) ;
F_31 ( V_44 ) ;
} else
F_7 ( & V_58 -> V_127 . V_62 ) ;
}
static bool
F_84 ( struct V_46 * V_46 ,
struct V_80 * V_128 )
{
struct V_43 * V_44 ;
bool V_129 = false ;
F_5 ( & V_46 -> V_62 ) ;
V_44 = F_30 ( V_46 ) -> V_59 ;
if ( V_44 != NULL && F_26 ( & V_44 -> V_130 ) ) {
F_22 ( V_44 ) ;
F_19 ( & V_44 -> V_130 , V_128 ) ;
V_129 = true ;
}
F_7 ( & V_46 -> V_62 ) ;
return V_129 ;
}
static int
F_85 ( struct V_12 * V_53 ,
struct V_8 * V_20 ,
struct V_80 * V_128 )
{
struct V_43 * V_44 , * V_91 ;
struct V_46 * V_46 ;
F_50 (lo, next, &server->layouts, plh_layouts) {
if ( F_40 ( V_92 , & V_44 -> V_70 ) )
continue;
V_46 = F_86 ( V_44 -> V_51 ) ;
if ( V_46 == NULL )
continue;
F_27 ( & V_44 -> V_52 ) ;
if ( F_84 ( V_46 , V_128 ) )
continue;
F_87 () ;
F_7 ( & V_53 -> V_54 ) ;
F_88 ( V_46 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_89 () ;
return - V_131 ;
}
return 0 ;
}
static int
F_90 ( struct V_80 * V_128 ,
bool V_132 )
{
struct V_43 * V_44 ;
struct V_46 * V_46 ;
F_58 ( V_85 ) ;
int V_129 = 0 ;
while ( ! F_26 ( V_128 ) ) {
V_44 = F_91 ( V_128 -> V_91 , struct V_43 ,
V_130 ) ;
F_3 ( L_27 , V_5 ,
V_44 -> V_51 -> V_133 ) ;
V_46 = V_44 -> V_51 ;
F_92 ( V_46 , false ) ;
F_5 ( & V_46 -> V_62 ) ;
F_27 ( & V_44 -> V_130 ) ;
if ( F_49 ( V_44 , & V_85 ) ) {
if ( V_132 )
F_36 ( V_111 , & V_44 -> V_70 ) ;
V_129 = - V_131 ;
}
F_7 ( & V_46 -> V_62 ) ;
F_60 ( & V_85 ) ;
F_83 ( V_46 , 0 ) ;
F_31 ( V_44 ) ;
F_88 ( V_46 ) ;
}
return V_129 ;
}
int
F_93 ( struct V_12 * V_53 ,
struct V_134 * V_135 ,
bool V_136 )
{
struct V_8 * V_20 ;
F_58 ( V_128 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_89 () ;
V_137:
F_94 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_20 -> V_135 , V_135 , sizeof( * V_135 ) ) != 0 )
continue;
if ( F_85 ( V_53 ,
V_20 ,
& V_128 ) != 0 )
goto V_137;
}
F_87 () ;
F_7 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_128 ) )
return 0 ;
return F_90 ( & V_128 , V_136 ) ;
}
int
F_95 ( struct V_12 * V_53 ,
bool V_136 )
{
struct V_8 * V_20 ;
F_58 ( V_128 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_89 () ;
V_137:
F_94 (server, &clp->cl_superblocks, client_link) {
if ( F_85 ( V_53 ,
V_20 ,
& V_128 ) != 0 )
goto V_137;
}
F_87 () ;
F_7 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_128 ) )
return 0 ;
return F_90 ( & V_128 , V_136 ) ;
}
void
F_96 ( struct V_12 * V_53 )
{
F_97 ( V_53 ) ;
F_10 ( V_53 ) ;
F_95 ( V_53 , false ) ;
}
void
F_98 ( struct V_43 * V_44 , const T_3 * V_138 ,
bool V_139 )
{
T_1 V_140 , V_141 , V_142 = 0 ;
V_140 = F_66 ( V_44 -> V_143 . V_109 ) ;
V_141 = F_66 ( V_138 -> V_109 ) ;
if ( ! F_72 ( V_44 ) ) {
F_99 ( & V_44 -> V_143 , V_138 ) ;
V_44 -> V_144 = V_141 ;
F_38 ( V_44 ) ;
F_39 ( V_92 , & V_44 -> V_70 ) ;
return;
}
if ( F_78 ( V_141 , V_140 ) ) {
F_99 ( & V_44 -> V_143 , V_138 ) ;
V_142 = V_141 - F_70 ( & V_44 -> V_110 ) ;
}
if ( V_139 )
V_142 = F_66 ( V_138 -> V_109 ) ;
else if ( V_142 == 0 )
return;
if ( F_78 ( V_142 , V_44 -> V_144 ) )
V_44 -> V_144 = V_142 ;
}
static bool
F_100 ( const struct V_43 * V_44 ,
const T_3 * V_103 )
{
T_1 V_109 = F_66 ( V_103 -> V_109 ) ;
return ! F_78 ( V_109 , V_44 -> V_144 ) ;
}
static bool
F_101 ( const struct V_43 * V_44 )
{
return V_44 -> V_145 ||
F_40 ( V_111 , & V_44 -> V_70 ) ;
}
static struct V_72 *
F_102 ( struct V_43 * V_44 ,
struct V_146 * V_147 ,
T_3 * V_103 ,
const struct V_86 * V_87 ,
long * V_148 , T_2 V_48 )
{
struct V_46 * V_47 = V_44 -> V_51 ;
struct V_8 * V_20 = F_24 ( V_47 ) ;
struct V_149 * V_150 ;
T_5 V_151 ;
F_3 ( L_28 , V_5 ) ;
V_150 = F_103 ( sizeof( * V_150 ) , V_48 ) ;
if ( V_150 == NULL )
return F_104 ( - V_152 ) ;
V_151 = F_105 ( V_47 ) ;
V_150 -> args . V_153 = V_154 ;
if ( V_150 -> args . V_153 > V_87 -> V_89 )
V_150 -> args . V_153 = V_87 -> V_89 ;
if ( V_87 -> V_65 == V_155 ) {
if ( V_87 -> V_88 >= V_151 )
V_150 -> args . V_153 = 0 ;
else if ( V_151 - V_87 -> V_88 < V_150 -> args . V_153 )
V_150 -> args . V_153 = V_151 - V_87 -> V_88 ;
}
V_150 -> args . V_156 = V_157 ;
F_106 ( & V_150 -> args . V_87 , V_87 ) ;
V_150 -> args . type = V_20 -> V_10 -> V_2 ;
V_150 -> args . V_46 = V_47 ;
V_150 -> args . V_147 = F_107 ( V_147 ) ;
F_99 ( & V_150 -> args . V_103 , V_103 ) ;
V_150 -> V_48 = V_48 ;
V_150 -> V_158 = V_44 -> V_55 ;
return F_108 ( V_150 , V_148 , V_48 ) ;
}
static void F_109 ( struct V_46 * V_46 ,
struct V_80 * V_99 )
{
struct V_57 * V_58 = F_30 ( V_46 ) ;
struct V_72 * V_73 , * V_37 ;
if ( ! F_47 ( V_159 , & V_58 -> V_160 ) )
return;
F_50 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_47 ( V_84 , & V_73 -> V_75 ) )
continue;
F_48 ( V_73 , V_99 ) ;
}
}
void F_110 ( struct V_43 * V_44 ,
const T_3 * V_161 ,
const struct V_86 * V_87 ,
const T_3 * V_103 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
F_58 ( V_162 ) ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_72 ( V_44 ) || ! V_161 ||
! F_111 ( & V_44 -> V_143 , V_161 ) )
goto V_163;
if ( V_103 ) {
T_1 V_66 = F_66 ( V_161 -> V_109 ) ;
F_59 ( V_44 , & V_162 , V_87 , V_66 ) ;
F_51 ( V_44 , & V_162 , V_87 , V_66 ) ;
F_98 ( V_44 , V_103 , true ) ;
} else
F_49 ( V_44 , & V_162 ) ;
V_163:
F_41 ( V_44 ) ;
F_7 ( & V_46 -> V_62 ) ;
F_60 ( & V_162 ) ;
}
static bool
F_112 ( struct V_43 * V_44 ,
T_3 * V_103 ,
enum V_64 * V_65 )
{
if ( F_70 ( & V_44 -> V_110 ) != 0 )
return false ;
if ( F_52 ( V_78 , & V_44 -> V_70 ) )
return false ;
F_36 ( V_77 , & V_44 -> V_70 ) ;
F_22 ( V_44 ) ;
if ( F_40 ( V_69 , & V_44 -> V_70 ) ) {
if ( V_103 != NULL ) {
F_99 ( V_103 , & V_44 -> V_143 ) ;
if ( V_44 -> V_71 != 0 )
V_103 -> V_109 = F_113 ( V_44 -> V_71 ) ;
}
if ( V_65 != NULL )
* V_65 = V_44 -> V_67 ;
F_38 ( V_44 ) ;
return true ;
}
if ( V_103 != NULL )
F_99 ( V_103 , & V_44 -> V_143 ) ;
if ( V_65 != NULL )
* V_65 = V_68 ;
return true ;
}
static void
F_114 ( struct V_164 * args ,
struct V_43 * V_44 ,
const T_3 * V_103 ,
enum V_64 V_65 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
args -> V_165 = F_24 ( V_46 ) -> V_10 -> V_2 ;
args -> V_46 = V_46 ;
args -> V_87 . V_65 = V_65 ;
args -> V_87 . V_88 = 0 ;
args -> V_87 . V_89 = V_90 ;
args -> V_59 = V_44 ;
F_99 ( & args -> V_103 , V_103 ) ;
}
static int
F_115 ( struct V_43 * V_44 , const T_3 * V_103 ,
enum V_64 V_65 , bool V_166 )
{
struct V_46 * V_47 = V_44 -> V_51 ;
struct V_1 * V_49 = F_24 ( V_47 ) -> V_10 ;
struct V_167 * V_168 ;
int V_35 = 0 ;
V_168 = F_103 ( sizeof( * V_168 ) , V_169 ) ;
if ( F_116 ( V_168 == NULL ) ) {
V_35 = - V_152 ;
F_5 ( & V_47 -> V_62 ) ;
F_41 ( V_44 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_31 ( V_44 ) ;
goto V_4;
}
F_114 ( & V_168 -> args , V_44 , V_103 , V_65 ) ;
V_168 -> args . V_170 = & V_168 -> V_170 ;
V_168 -> V_53 = F_24 ( V_47 ) -> V_12 ;
V_168 -> V_158 = V_44 -> V_55 ;
if ( V_49 -> V_171 )
V_49 -> V_171 ( & V_168 -> args ) ;
V_35 = F_117 ( V_168 , V_166 ) ;
V_4:
F_3 ( L_29 , V_5 , V_35 ) ;
return V_35 ;
}
static bool
F_118 ( struct V_43 * V_44 )
{
struct V_72 * V_172 ;
if ( ! F_40 ( V_69 , & V_44 -> V_70 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list) {
if ( F_40 ( V_74 , & V_172 -> V_75 ) )
return false ;
}
return true ;
}
static void F_32 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
if ( ! F_40 ( V_69 , & V_44 -> V_70 ) )
return;
F_5 ( & V_46 -> V_62 ) ;
if ( F_118 ( V_44 ) ) {
T_3 V_103 ;
enum V_64 V_65 ;
bool V_173 ;
V_173 = F_112 ( V_44 , & V_103 , & V_65 ) ;
F_7 ( & V_46 -> V_62 ) ;
if ( V_173 ) {
F_115 ( V_44 , & V_103 , V_65 , false ) ;
}
} else
F_7 ( & V_46 -> V_62 ) ;
}
int
F_119 ( struct V_46 * V_47 )
{
struct V_43 * V_44 = NULL ;
struct V_57 * V_58 = F_30 ( V_47 ) ;
F_58 ( V_119 ) ;
T_3 V_103 ;
int V_35 = 0 ;
bool V_173 ;
F_3 ( L_30 , V_5 , V_47 -> V_133 ) ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( ! V_44 ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
F_22 ( V_44 ) ;
if ( F_40 ( V_78 , & V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
if ( F_120 ( & V_44 -> V_70 , V_77 ,
V_174 ) )
goto V_175;
F_5 ( & V_47 -> V_62 ) ;
}
F_109 ( V_47 , & V_119 ) ;
F_59 ( V_44 , & V_119 , NULL , 0 ) ;
if ( F_24 ( V_47 ) -> V_10 -> V_176 ) {
struct V_86 V_87 = {
. V_65 = V_68 ,
. V_88 = 0 ,
. V_89 = V_90 ,
} ;
F_24 ( V_47 ) -> V_10 -> V_176 ( V_44 , & V_87 ) ;
}
if ( ! F_40 ( V_69 , & V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_175;
}
V_173 = F_112 ( V_44 , & V_103 , NULL ) ;
F_7 ( & V_47 -> V_62 ) ;
if ( V_173 )
V_35 = F_115 ( V_44 , & V_103 , V_68 , true ) ;
V_175:
F_60 ( & V_119 ) ;
F_31 ( V_44 ) ;
V_4:
F_3 ( L_29 , V_5 , V_35 ) ;
return V_35 ;
}
int
F_121 ( struct V_46 * V_46 )
{
struct V_43 * V_44 ;
int V_129 ;
F_5 ( & V_46 -> V_62 ) ;
V_44 = F_30 ( V_46 ) -> V_59 ;
if ( V_44 == NULL ) {
F_7 ( & V_46 -> V_62 ) ;
return 0 ;
}
F_22 ( V_44 ) ;
V_44 -> V_145 ++ ;
F_7 ( & V_46 -> V_62 ) ;
F_122 ( V_46 -> V_177 ) ;
V_129 = F_92 ( V_46 , true ) ;
if ( V_129 == 0 )
V_129 = F_119 ( V_46 ) ;
F_5 ( & V_46 -> V_62 ) ;
V_44 -> V_145 -- ;
F_7 ( & V_46 -> V_62 ) ;
F_31 ( V_44 ) ;
return V_129 ;
}
bool F_123 ( struct V_46 * V_47 ,
struct V_164 * args ,
struct V_178 * V_179 ,
const struct V_180 * V_158 )
{
struct V_57 * V_58 = F_30 ( V_47 ) ;
struct V_146 * V_147 ;
struct V_181 * V_182 ;
struct V_43 * V_44 ;
struct V_72 * V_73 , * V_91 ;
T_3 V_103 ;
enum V_64 V_65 = 0 ;
bool V_183 = false , V_184 = false ;
bool V_185 = false ;
if ( ! F_124 ( V_47 ) )
return false ;
V_186:
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( ! V_44 || ! F_72 ( V_44 ) ||
F_40 ( V_111 , & V_44 -> V_70 ) )
goto V_187;
if ( F_40 ( V_78 , & V_44 -> V_70 ) ) {
F_22 ( V_44 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_120 ( & V_44 -> V_70 , V_77 ,
V_174 ) ;
F_31 ( V_44 ) ;
goto V_186;
}
if ( F_125 ( V_47 , V_188 ) ) {
if ( F_125 ( V_47 , V_189 ) )
goto V_187;
V_185 = true ;
}
F_2 (ctx, &nfsi->open_files, list) {
V_182 = V_147 -> V_182 ;
if ( V_182 == NULL )
continue;
if ( V_182 -> V_182 & V_189 )
goto V_187;
if ( V_182 -> V_182 & V_188 )
V_185 = true ;
}
F_50 (lseg, next, &lo->plh_segs, pls_list) {
if ( V_185 && V_73 -> V_76 . V_65 == V_155 )
continue;
if ( ! F_47 ( V_82 , & V_73 -> V_75 ) )
continue;
F_36 ( V_74 , & V_73 -> V_75 ) ;
if ( ! F_77 ( V_73 , & V_44 -> V_112 ) )
continue;
F_35 ( V_44 , V_73 -> V_76 . V_65 , 0 ) ;
}
if ( ! F_40 ( V_69 , & V_44 -> V_70 ) )
goto V_187;
V_183 = F_112 ( V_44 , & V_103 , & V_65 ) ;
if ( ! V_183 || V_158 != V_44 -> V_55 )
goto V_187;
V_184 = V_183 ;
F_114 ( args , V_44 , & V_103 , V_65 ) ;
V_179 -> V_190 = 0 ;
V_183 = false ;
V_187:
F_7 ( & V_47 -> V_62 ) ;
F_92 ( V_47 , true ) ;
if ( V_184 ) {
struct V_1 * V_49 = F_24 ( V_47 ) -> V_10 ;
if ( V_49 -> V_171 )
V_49 -> V_171 ( args ) ;
return true ;
}
if ( V_183 )
F_115 ( V_44 , & V_103 , V_65 , true ) ;
return false ;
}
void F_126 ( struct V_164 * args ,
struct V_178 * V_179 ,
int V_129 )
{
struct V_43 * V_44 = args -> V_59 ;
const T_3 * V_161 = NULL ;
const T_3 * V_191 = NULL ;
struct V_192 * V_170 = args -> V_170 ;
if ( V_129 == 0 ) {
V_161 = & args -> V_103 ;
if ( V_179 -> V_190 )
V_191 = & V_179 -> V_103 ;
}
F_110 ( V_44 , V_161 , & args -> V_87 ,
V_191 ) ;
if ( V_170 && V_170 -> V_193 && V_170 -> V_193 -> free )
V_170 -> V_193 -> free ( V_170 ) ;
F_31 ( V_44 ) ;
F_127 ( args -> V_46 , 0 ) ;
}
bool F_128 ( struct V_46 * V_47 , struct V_194 * V_195 )
{
struct V_57 * V_58 = F_30 ( V_47 ) ;
struct V_43 * V_44 ;
bool V_196 = false ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( V_44 && F_40 ( V_77 , & V_44 -> V_70 ) ) {
F_129 ( & F_24 ( V_47 ) -> V_79 , V_195 , NULL ) ;
V_196 = true ;
}
F_7 ( & V_47 -> V_62 ) ;
return V_196 ;
}
static T_6
F_130 ( const struct V_86 * V_113 ,
const struct V_86 * V_114 )
{
T_6 V_197 ;
V_197 = V_113 -> V_88 - V_114 -> V_88 ;
if ( V_197 )
return V_197 ;
V_197 = V_114 -> V_89 - V_113 -> V_89 ;
if ( V_197 )
return V_197 ;
return ( int ) ( V_113 -> V_65 == V_155 ) - ( int ) ( V_114 -> V_65 == V_155 ) ;
}
static bool
F_131 ( const struct V_86 * V_113 ,
const struct V_86 * V_114 )
{
return F_130 ( V_113 , V_114 ) > 0 ;
}
static bool
F_132 ( struct V_72 * V_73 ,
struct V_72 * V_198 )
{
return false ;
}
void
F_133 ( struct V_43 * V_44 ,
struct V_72 * V_73 ,
bool (* F_134)( const struct V_86 * ,
const struct V_86 * ) ,
bool (* F_135)( struct V_72 * ,
struct V_72 * ) ,
struct V_80 * V_81 )
{
struct V_72 * V_199 , * V_37 ;
F_3 ( L_33 , V_5 ) ;
F_50 (lp, tmp, &lo->plh_segs, pls_list) {
if ( F_40 ( V_83 , & V_199 -> V_75 ) == 0 )
continue;
if ( F_135 ( V_73 , V_199 ) ) {
F_77 ( V_199 , V_81 ) ;
continue;
}
if ( F_134 ( & V_73 -> V_76 , & V_199 -> V_76 ) )
continue;
F_136 ( & V_73 -> V_104 , & V_199 -> V_104 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_73 , V_73 -> V_76 . V_65 ,
V_73 -> V_76 . V_88 , V_73 -> V_76 . V_89 ,
V_199 , V_199 -> V_76 . V_65 , V_199 -> V_76 . V_88 ,
V_199 -> V_76 . V_89 ) ;
goto V_4;
}
F_136 ( & V_73 -> V_104 , & V_44 -> V_63 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_73 , V_73 -> V_76 . V_65 ,
V_73 -> V_76 . V_88 , V_73 -> V_76 . V_89 ) ;
V_4:
F_22 ( V_44 ) ;
F_3 ( L_38 , V_5 ) ;
}
static void
F_137 ( struct V_43 * V_44 ,
struct V_72 * V_73 ,
struct V_80 * V_81 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
if ( V_49 -> V_200 != NULL )
V_49 -> V_200 ( V_44 , V_73 , V_81 ) ;
else
F_133 ( V_44 , V_73 ,
F_131 ,
F_132 ,
V_81 ) ;
}
static struct V_43 *
F_138 ( struct V_46 * V_47 ,
struct V_146 * V_147 ,
T_2 V_48 )
{
struct V_43 * V_44 ;
V_44 = F_23 ( V_47 , V_48 ) ;
if ( ! V_44 )
return NULL ;
F_65 ( & V_44 -> V_45 , 1 ) ;
F_64 ( & V_44 -> V_52 ) ;
F_64 ( & V_44 -> V_63 ) ;
F_64 ( & V_44 -> V_112 ) ;
F_64 ( & V_44 -> V_130 ) ;
V_44 -> V_51 = V_47 ;
V_44 -> V_55 = F_139 ( V_147 -> V_158 ) ;
V_44 -> V_70 |= 1 << V_92 ;
return V_44 ;
}
static struct V_43 *
F_140 ( struct V_46 * V_47 ,
struct V_146 * V_147 ,
T_2 V_48 )
__releases( &ino->i_lock
static bool
F_141 ( const struct V_86 * V_201 ,
const struct V_86 * V_87 ,
bool V_202 )
{
struct V_86 V_203 ;
if ( ( V_87 -> V_65 == V_93 &&
V_201 -> V_65 != V_93 ) ||
( V_87 -> V_65 != V_201 -> V_65 &&
V_202 == true ) ||
! F_80 ( V_201 , V_87 ) )
return 0 ;
V_203 = * V_87 ;
V_203 . V_89 = 1 ;
return F_75 ( V_201 , & V_203 ) ;
}
static struct V_72 *
F_142 ( struct V_43 * V_44 ,
struct V_86 * V_87 ,
bool V_202 )
{
struct V_72 * V_73 , * V_129 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_40 ( V_83 , & V_73 -> V_75 ) &&
! F_40 ( V_74 , & V_73 -> V_75 ) &&
F_141 ( & V_73 -> V_76 , V_87 ,
V_202 ) ) {
V_129 = F_143 ( V_73 ) ;
break;
}
}
F_3 ( L_39 ,
V_5 , V_129 , V_129 ? F_70 ( & V_129 -> V_106 ) : 0 ) ;
return V_129 ;
}
static bool F_144 ( struct V_146 * V_147 ,
struct V_46 * V_47 , int V_65 )
{
struct V_204 * V_205 = V_147 -> V_206 ;
struct V_57 * V_58 = F_30 ( V_47 ) ;
T_5 V_207 = F_105 ( V_47 ) ;
bool V_208 = false , V_209 = false , V_210 = false , V_211 = false , V_129 = false ;
if ( V_205 == NULL )
return V_129 ;
F_3 ( L_40 ,
V_5 , V_205 -> V_212 , V_205 -> V_213 , V_205 -> V_214 , V_205 -> V_215 , V_205 -> V_216 ) ;
switch ( V_65 ) {
case V_155 :
if ( V_205 -> V_212 & V_217 ) {
F_3 ( L_41 , V_5 , V_207 ) ;
V_209 = true ;
if ( V_207 < V_205 -> V_213 )
V_208 = true ;
}
if ( V_205 -> V_212 & V_218 ) {
F_3 ( L_42 , V_5 ,
V_58 -> V_61 ) ;
V_211 = true ;
if ( V_58 -> V_61 < V_205 -> V_215 )
V_210 = true ;
}
break;
case V_93 :
if ( V_205 -> V_212 & V_219 ) {
F_3 ( L_41 , V_5 , V_207 ) ;
V_209 = true ;
if ( V_207 < V_205 -> V_214 )
V_208 = true ;
}
if ( V_205 -> V_212 & V_220 ) {
F_3 ( L_43 , V_5 ,
V_58 -> V_60 ) ;
V_211 = true ;
if ( V_58 -> V_60 < V_205 -> V_216 )
V_210 = true ;
}
break;
}
if ( V_209 && V_211 ) {
if ( V_208 && V_210 )
V_129 = true ;
} else if ( V_208 || V_210 )
V_129 = true ;
F_3 ( L_44 , V_5 , V_208 , V_210 , V_129 ) ;
return V_129 ;
}
static bool F_145 ( struct V_43 * V_44 )
{
F_92 ( V_44 -> V_51 , false ) ;
return ! F_146 ( & V_44 -> V_70 , V_77 ,
V_221 ,
V_174 ) ;
}
static void F_147 ( struct V_43 * V_44 )
{
unsigned long * V_222 = & V_44 -> V_70 ;
F_42 ( V_223 , V_222 ) ;
F_43 () ;
F_44 ( V_222 , V_223 ) ;
}
struct V_72 *
F_148 ( struct V_46 * V_47 ,
struct V_146 * V_147 ,
T_5 V_224 ,
T_4 V_225 ,
enum V_64 V_65 ,
bool V_202 ,
T_2 V_48 )
{
struct V_86 V_226 = {
. V_65 = V_65 ,
. V_88 = V_224 ,
. V_89 = V_225 ,
} ;
unsigned V_227 ;
struct V_8 * V_20 = F_24 ( V_47 ) ;
struct V_12 * V_53 = V_20 -> V_12 ;
struct V_43 * V_44 = NULL ;
struct V_72 * V_73 = NULL ;
T_3 V_103 ;
long V_148 = 0 ;
unsigned long V_228 = V_98 + ( V_53 -> V_229 << 1 ) ;
bool V_230 ;
if ( ! F_149 ( F_24 ( V_47 ) ) ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_231 ) ;
goto V_4;
}
if ( V_65 == V_155 && F_105 ( V_47 ) == 0 ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_232 ) ;
goto V_4;
}
if ( F_144 ( V_147 , V_47 , V_65 ) ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_233 ) ;
goto V_4;
}
V_234:
F_151 ( V_53 ) ;
V_230 = false ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = F_140 ( V_47 , V_147 , V_48 ) ;
if ( V_44 == NULL ) {
F_7 ( & V_47 -> V_62 ) ;
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_235 ) ;
goto V_4;
}
if ( F_40 ( V_111 , & V_44 -> V_70 ) ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_236 ) ;
F_3 ( L_45 , V_5 ) ;
goto V_163;
}
if ( F_61 ( V_44 , V_65 ) ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_237 ) ;
goto V_163;
}
V_73 = F_142 ( V_44 , & V_226 , V_202 ) ;
if ( V_73 ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_238 ) ;
goto V_163;
}
if ( ! F_152 ( V_147 -> V_182 ) ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_239 ) ;
goto V_163;
}
if ( F_40 ( V_92 , & V_44 -> V_70 ) ) {
if ( F_52 ( V_223 ,
& V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_120 ( & V_44 -> V_70 , V_223 ,
V_174 ) ;
F_31 ( V_44 ) ;
F_3 ( L_46 , V_5 ) ;
goto V_234;
}
V_230 = true ;
if ( F_153 ( V_147 -> V_182 ,
V_65 == V_93 ? V_189 : V_188 ,
NULL , & V_103 , NULL ) != 0 ) {
F_150 ( V_47 , V_224 , V_225 ,
V_65 , V_44 , V_73 ,
V_239 ) ;
goto V_163;
}
} else {
F_99 ( & V_103 , & V_44 -> V_143 ) ;
}
if ( F_40 ( V_77 , & V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_47 , V_5 ) ;
if ( F_145 ( V_44 ) ) {
if ( V_230 )
F_147 ( V_44 ) ;
F_31 ( V_44 ) ;
F_3 ( L_46 , V_5 ) ;
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 ,
V_73 , V_240 ) ;
goto V_234;
}
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_241 ) ;
goto V_175;
}
if ( F_101 ( V_44 ) ) {
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_242 ) ;
goto V_163;
}
F_17 ( & V_44 -> V_110 ) ;
F_7 ( & V_47 -> V_62 ) ;
if ( F_26 ( & V_44 -> V_52 ) ) {
F_5 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_44 -> V_52 ) )
F_136 ( & V_44 -> V_52 , & V_20 -> V_243 ) ;
F_7 ( & V_53 -> V_54 ) ;
}
V_227 = V_226 . V_88 & ~ V_244 ;
if ( V_227 ) {
V_226 . V_88 -= V_227 ;
V_226 . V_89 += V_227 ;
}
if ( V_226 . V_89 != V_90 )
V_226 . V_89 = F_154 ( V_226 . V_89 ) ;
V_73 = F_102 ( V_44 , V_147 , & V_103 , & V_226 , & V_148 , V_48 ) ;
F_150 ( V_47 , V_224 , V_225 , V_65 , V_44 , V_73 ,
V_245 ) ;
F_56 ( & V_44 -> V_110 ) ;
if ( F_155 ( V_73 ) ) {
switch( F_156 ( V_73 ) ) {
case - V_246 :
if ( F_157 ( V_98 , V_228 ) )
V_73 = NULL ;
break;
case - V_247 :
if ( V_230 ) {
V_73 = NULL ;
break;
}
if ( F_157 ( V_98 , V_228 ) )
F_82 ( F_30 ( V_47 ) ) ;
case - V_131 :
break;
default:
if ( ! F_158 ( F_156 ( V_73 ) ) ) {
F_55 ( V_44 , F_53 ( V_65 ) ) ;
V_73 = NULL ;
}
goto V_175;
}
if ( V_73 ) {
if ( V_230 )
F_147 ( V_44 ) ;
F_150 ( V_47 , V_224 , V_225 ,
V_65 , V_44 , V_73 , V_240 ) ;
F_31 ( V_44 ) ;
goto V_234;
}
} else {
F_55 ( V_44 , F_53 ( V_65 ) ) ;
}
V_175:
if ( V_230 )
F_147 ( V_44 ) ;
F_31 ( V_44 ) ;
V_4:
F_3 ( L_48
L_49 ,
V_5 , V_47 -> V_248 -> V_249 ,
( unsigned long long ) F_159 ( V_47 ) ,
F_160 ( V_73 ) ? L_50 : L_51 ,
V_65 == V_93 ? L_52 : L_53 ,
( unsigned long long ) V_224 ,
( unsigned long long ) V_225 ) ;
return V_73 ;
V_163:
F_7 ( & V_47 -> V_62 ) ;
goto V_175;
}
static bool
F_161 ( struct V_86 * V_87 )
{
switch ( V_87 -> V_65 ) {
case V_155 :
case V_93 :
break;
default:
return false ;
}
if ( V_87 -> V_88 == V_90 )
return false ;
if ( V_87 -> V_89 == 0 )
return false ;
if ( V_87 -> V_89 != V_90 &&
V_87 -> V_89 > V_90 - V_87 -> V_88 )
return false ;
return true ;
}
struct V_72 *
F_162 ( struct V_149 * V_150 )
{
struct V_43 * V_44 = F_30 ( V_150 -> args . V_46 ) -> V_59 ;
struct V_250 * V_179 = & V_150 -> V_179 ;
struct V_72 * V_73 ;
struct V_46 * V_47 = V_44 -> V_51 ;
F_58 ( V_81 ) ;
if ( ! F_161 ( & V_179 -> V_87 ) )
return F_104 ( - V_36 ) ;
V_73 = F_24 ( V_47 ) -> V_10 -> V_38 ( V_44 , V_179 , V_150 -> V_48 ) ;
if ( F_160 ( V_73 ) ) {
if ( ! V_73 )
V_73 = F_104 ( - V_152 ) ;
F_3 ( L_54 ,
V_5 , F_156 ( V_73 ) ) ;
return V_73 ;
}
F_63 ( V_44 , V_73 , & V_179 -> V_87 , & V_179 -> V_103 ) ;
F_5 ( & V_47 -> V_62 ) ;
if ( F_101 ( V_44 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_251;
}
if ( ! F_72 ( V_44 ) ) {
F_98 ( V_44 , & V_179 -> V_103 , true ) ;
} else if ( F_111 ( & V_44 -> V_143 , & V_179 -> V_103 ) ) {
if ( F_100 ( V_44 , & V_179 -> V_103 ) ) {
F_3 ( L_56 , V_5 ) ;
goto V_251;
}
F_98 ( V_44 , & V_179 -> V_103 , false ) ;
} else {
F_49 ( V_44 , & V_81 ) ;
goto V_251;
}
F_143 ( V_73 ) ;
F_137 ( V_44 , V_73 , & V_81 ) ;
if ( V_179 -> V_252 )
F_36 ( V_82 , & V_73 -> V_75 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_60 ( & V_81 ) ;
return V_73 ;
V_251:
F_7 ( & V_47 -> V_62 ) ;
V_73 -> V_107 = V_44 ;
F_24 ( V_47 ) -> V_10 -> V_39 ( V_73 ) ;
if ( ! F_72 ( V_44 ) )
F_83 ( V_47 , 0 ) ;
return F_104 ( - V_131 ) ;
}
int
F_163 ( struct V_43 * V_44 ,
struct V_80 * V_119 ,
const struct V_86 * V_176 ,
T_1 V_66 )
{
struct V_72 * V_73 , * V_91 ;
int V_126 = 0 ;
F_3 ( L_23 , V_5 , V_44 ) ;
if ( F_26 ( & V_44 -> V_63 ) )
return 0 ;
F_164 ( & V_44 -> V_51 -> V_62 ) ;
F_50 (lseg, next, &lo->plh_segs, pls_list)
if ( F_81 ( V_73 , V_176 , V_66 ) ) {
F_3 ( L_57
L_25 , V_5 ,
V_73 , V_73 -> V_76 . V_65 ,
V_73 -> V_76 . V_88 ,
V_73 -> V_76 . V_89 ) ;
if ( F_77 ( V_73 , V_119 ) )
continue;
V_126 ++ ;
F_36 ( V_74 , & V_73 -> V_75 ) ;
}
if ( V_126 )
F_35 ( V_44 , V_176 -> V_65 , V_66 ) ;
return V_126 ;
}
void F_165 ( struct V_46 * V_46 ,
struct V_72 * V_73 )
{
struct V_43 * V_44 = F_30 ( V_46 ) -> V_59 ;
struct V_86 V_87 = {
. V_65 = V_73 -> V_76 . V_65 ,
. V_88 = 0 ,
. V_89 = V_90 ,
} ;
bool V_253 = false ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_72 ( V_44 ) ) {
F_7 ( & V_46 -> V_62 ) ;
return;
}
F_35 ( V_44 , V_87 . V_65 , 0 ) ;
if ( ! F_163 ( V_44 , & V_44 -> V_112 , & V_87 , 0 ) ) {
T_3 V_103 ;
enum V_64 V_65 ;
V_253 = F_112 ( V_44 , & V_103 , & V_65 ) ;
F_7 ( & V_46 -> V_62 ) ;
if ( V_253 )
F_115 ( V_44 , & V_103 , V_65 , false ) ;
} else {
F_7 ( & V_46 -> V_62 ) ;
F_83 ( V_46 , 0 ) ;
}
}
void
F_166 ( struct V_254 * V_255 )
{
if ( V_255 -> V_256 == NULL ||
F_40 ( V_83 , & V_255 -> V_256 -> V_75 ) )
return;
F_74 ( V_255 -> V_256 ) ;
V_255 -> V_256 = NULL ;
}
static void
F_167 ( struct V_254 * V_255 , struct V_257 * V_258 )
{
if ( V_255 -> V_256 && ! F_168 ( V_255 -> V_256 , V_258 ) ) {
F_74 ( V_255 -> V_256 ) ;
V_255 -> V_256 = NULL ;
}
}
void
F_169 ( struct V_254 * V_255 , struct V_257 * V_258 )
{
T_4 V_259 = V_258 -> V_260 ;
F_166 ( V_255 ) ;
F_167 ( V_255 , V_258 ) ;
if ( V_255 -> V_256 == NULL ) {
if ( V_255 -> V_261 == NULL )
V_259 = F_105 ( V_255 -> V_262 ) - F_170 ( V_258 ) ;
else
V_259 = F_171 ( V_255 -> V_261 ) ;
V_255 -> V_256 = F_148 ( V_255 -> V_262 ,
V_258 -> V_263 ,
F_170 ( V_258 ) ,
V_259 ,
V_155 ,
false ,
V_264 ) ;
if ( F_155 ( V_255 -> V_256 ) ) {
V_255 -> V_265 = F_156 ( V_255 -> V_256 ) ;
V_255 -> V_256 = NULL ;
return;
}
}
if ( V_255 -> V_256 == NULL )
F_172 ( V_255 ) ;
}
void
F_173 ( struct V_254 * V_255 ,
struct V_257 * V_258 , T_4 V_266 )
{
F_166 ( V_255 ) ;
F_167 ( V_255 , V_258 ) ;
if ( V_255 -> V_256 == NULL ) {
V_255 -> V_256 = F_148 ( V_255 -> V_262 ,
V_258 -> V_263 ,
F_170 ( V_258 ) ,
V_266 ,
V_93 ,
false ,
V_169 ) ;
if ( F_155 ( V_255 -> V_256 ) ) {
V_255 -> V_265 = F_156 ( V_255 -> V_256 ) ;
V_255 -> V_256 = NULL ;
return;
}
}
if ( V_255 -> V_256 == NULL )
F_174 ( V_255 ) ;
}
void
F_175 ( struct V_254 * V_267 )
{
if ( V_267 -> V_256 ) {
F_74 ( V_267 -> V_256 ) ;
V_267 -> V_256 = NULL ;
}
}
T_7
F_176 ( struct V_254 * V_255 ,
struct V_257 * V_268 , struct V_257 * V_258 )
{
unsigned int V_208 ;
T_4 V_269 , V_270 , V_271 ;
V_208 = F_177 ( V_255 , V_268 , V_258 ) ;
if ( ! V_208 )
return 0 ;
if ( V_255 -> V_256 ) {
V_269 = F_76 ( V_255 -> V_256 -> V_76 . V_88 ,
V_255 -> V_256 -> V_76 . V_89 ) ;
V_270 = F_170 ( V_258 ) ;
if ( V_270 >= V_269 )
return 0 ;
V_271 = V_269 - V_270 ;
if ( V_271 < V_208 )
V_208 = ( unsigned int ) V_271 ;
}
return V_208 ;
}
int F_178 ( struct V_272 * V_273 )
{
struct V_254 V_255 ;
F_179 ( & V_255 , V_273 -> V_46 , V_274 , true ,
V_273 -> V_275 ) ;
F_36 ( V_276 , & V_273 -> args . V_277 -> V_160 ) ;
return F_180 ( & V_255 , V_273 ) ;
}
static void F_181 ( struct V_272 * V_273 )
{
F_3 ( L_58 , V_273 -> V_278 ) ;
if ( F_24 ( V_273 -> V_46 ) -> V_10 -> V_160 &
V_279 ) {
F_182 ( V_273 -> V_46 ) ;
}
if ( ! F_52 ( V_280 , & V_273 -> V_160 ) )
V_273 -> V_195 . V_281 = F_178 ( V_273 ) ;
}
void F_183 ( struct V_272 * V_273 )
{
if ( F_184 ( ! V_273 -> V_278 ) ) {
F_185 ( V_273 -> V_46 , V_273 -> V_73 ,
V_273 -> V_282 + V_273 -> V_179 . V_225 ) ;
V_273 -> V_283 -> V_284 ( & V_273 -> V_195 , V_273 ) ;
}
F_186 ( V_273 , V_273 -> V_278 ) ;
if ( F_116 ( V_273 -> V_278 ) )
F_181 ( V_273 ) ;
V_273 -> V_283 -> V_285 ( V_273 ) ;
}
static void
F_187 ( struct V_254 * V_267 ,
struct V_272 * V_273 )
{
struct V_286 * V_287 = F_188 ( V_267 ) ;
if ( ! F_52 ( V_280 , & V_273 -> V_160 ) ) {
F_189 ( & V_273 -> V_288 , & V_287 -> V_289 ) ;
F_174 ( V_267 ) ;
V_287 -> V_290 = 1 ;
}
V_273 -> V_291 ( V_273 ) ;
}
static enum V_292
F_190 ( struct V_272 * V_273 ,
const struct V_293 * V_294 ,
struct V_72 * V_73 ,
int V_295 )
{
struct V_46 * V_46 = V_273 -> V_46 ;
enum V_292 V_296 ;
struct V_8 * V_9 = F_24 ( V_46 ) ;
V_273 -> V_283 = V_294 ;
F_3 ( L_59 , V_5 ,
V_46 -> V_133 , V_273 -> args . V_225 , V_273 -> args . V_88 , V_295 ) ;
V_296 = V_9 -> V_10 -> V_297 ( V_273 , V_295 ) ;
if ( V_296 != V_298 )
F_191 ( V_46 , V_299 ) ;
F_3 ( L_60 , V_5 , V_296 ) ;
return V_296 ;
}
static void
F_192 ( struct V_254 * V_267 ,
struct V_272 * V_273 , int V_295 )
{
const struct V_293 * V_294 = V_267 -> V_300 ;
struct V_72 * V_73 = V_267 -> V_256 ;
enum V_292 V_296 ;
V_296 = F_190 ( V_273 , V_294 , V_73 , V_295 ) ;
switch ( V_296 ) {
case V_298 :
F_187 ( V_267 , V_273 ) ;
case V_301 :
break;
case V_302 :
if ( ! F_52 ( V_280 , & V_273 -> V_160 ) ) {
struct V_286 * V_287 = F_188 ( V_267 ) ;
F_193 ( & V_273 -> V_288 , & V_287 -> V_289 ) ;
V_287 -> V_290 = 1 ;
}
V_273 -> V_283 -> V_285 ( V_273 ) ;
}
}
static void F_194 ( struct V_272 * V_273 )
{
F_74 ( V_273 -> V_73 ) ;
F_195 ( V_273 ) ;
}
int
F_196 ( struct V_254 * V_267 )
{
struct V_272 * V_273 ;
int V_129 ;
V_273 = F_197 ( V_267 -> V_303 ) ;
if ( ! V_273 ) {
V_267 -> V_265 = - V_152 ;
return V_267 -> V_265 ;
}
F_198 ( V_267 , V_273 , F_194 ) ;
V_273 -> V_73 = F_143 ( V_267 -> V_256 ) ;
V_129 = F_199 ( V_267 , V_273 ) ;
if ( ! V_129 )
F_192 ( V_267 , V_273 , V_267 -> V_304 ) ;
return V_129 ;
}
int F_200 ( struct V_272 * V_273 )
{
struct V_254 V_255 ;
F_201 ( & V_255 , V_273 -> V_46 , true , V_273 -> V_275 ) ;
return F_180 ( & V_255 , V_273 ) ;
}
static void F_202 ( struct V_272 * V_273 )
{
F_3 ( L_61 , V_273 -> V_278 ) ;
if ( F_24 ( V_273 -> V_46 ) -> V_10 -> V_160 &
V_279 ) {
F_182 ( V_273 -> V_46 ) ;
}
if ( ! F_52 ( V_280 , & V_273 -> V_160 ) )
V_273 -> V_195 . V_281 = F_200 ( V_273 ) ;
}
void F_203 ( struct V_272 * V_273 )
{
if ( F_184 ( ! V_273 -> V_278 ) )
V_273 -> V_283 -> V_284 ( & V_273 -> V_195 , V_273 ) ;
F_204 ( V_273 , V_273 -> V_278 ) ;
if ( F_116 ( V_273 -> V_278 ) )
F_202 ( V_273 ) ;
V_273 -> V_283 -> V_285 ( V_273 ) ;
}
static void
F_205 ( struct V_254 * V_267 ,
struct V_272 * V_273 )
{
struct V_286 * V_287 = F_188 ( V_267 ) ;
if ( ! F_52 ( V_280 , & V_273 -> V_160 ) ) {
F_189 ( & V_273 -> V_288 , & V_287 -> V_289 ) ;
F_172 ( V_267 ) ;
V_287 -> V_290 = 1 ;
}
V_273 -> V_291 ( V_273 ) ;
}
static enum V_292
F_206 ( struct V_272 * V_273 ,
const struct V_293 * V_294 ,
struct V_72 * V_73 )
{
struct V_46 * V_46 = V_273 -> V_46 ;
struct V_8 * V_9 = F_24 ( V_46 ) ;
enum V_292 V_296 ;
V_273 -> V_283 = V_294 ;
F_3 ( L_62 ,
V_5 , V_46 -> V_133 , V_273 -> args . V_225 , V_273 -> args . V_88 ) ;
V_296 = V_9 -> V_10 -> V_305 ( V_273 ) ;
if ( V_296 != V_298 )
F_191 ( V_46 , V_306 ) ;
F_3 ( L_60 , V_5 , V_296 ) ;
return V_296 ;
}
void F_207 ( struct V_272 * V_273 )
{
struct V_254 V_255 ;
if ( ! F_52 ( V_280 , & V_273 -> V_160 ) ) {
F_74 ( V_273 -> V_73 ) ;
V_273 -> V_73 = NULL ;
F_201 ( & V_255 , V_273 -> V_46 , false ,
V_273 -> V_275 ) ;
V_273 -> V_195 . V_281 = F_180 ( & V_255 , V_273 ) ;
}
}
static void
F_208 ( struct V_254 * V_267 , struct V_272 * V_273 )
{
const struct V_293 * V_294 = V_267 -> V_300 ;
struct V_72 * V_73 = V_267 -> V_256 ;
enum V_292 V_296 ;
V_296 = F_206 ( V_273 , V_294 , V_73 ) ;
switch ( V_296 ) {
case V_298 :
F_205 ( V_267 , V_273 ) ;
case V_301 :
break;
case V_302 :
if ( ! F_52 ( V_280 , & V_273 -> V_160 ) ) {
struct V_286 * V_287 = F_188 ( V_267 ) ;
F_193 ( & V_273 -> V_288 , & V_287 -> V_289 ) ;
V_287 -> V_290 = 1 ;
}
V_273 -> V_283 -> V_285 ( V_273 ) ;
}
}
static void F_209 ( struct V_272 * V_273 )
{
F_74 ( V_273 -> V_73 ) ;
F_195 ( V_273 ) ;
}
int
F_210 ( struct V_254 * V_267 )
{
struct V_272 * V_273 ;
int V_129 ;
V_273 = F_197 ( V_267 -> V_303 ) ;
if ( ! V_273 ) {
V_267 -> V_265 = - V_152 ;
return V_267 -> V_265 ;
}
F_198 ( V_267 , V_273 , F_209 ) ;
V_273 -> V_73 = F_143 ( V_267 -> V_256 ) ;
V_129 = F_199 ( V_267 , V_273 ) ;
if ( ! V_129 )
F_208 ( V_267 , V_273 ) ;
return V_129 ;
}
static void F_211 ( struct V_46 * V_46 )
{
unsigned long * V_222 = & F_30 ( V_46 ) -> V_160 ;
F_42 ( V_307 , V_222 ) ;
F_43 () ;
F_44 ( V_222 , V_307 ) ;
}
static void F_212 ( struct V_46 * V_46 , struct V_80 * V_308 )
{
struct V_72 * V_73 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_73 -> V_76 . V_65 == V_93 &&
F_47 ( V_84 , & V_73 -> V_75 ) )
F_19 ( & V_73 -> V_105 , V_308 ) ;
}
}
static void F_213 ( struct V_46 * V_46 , struct V_80 * V_308 )
{
struct V_72 * V_73 , * V_37 ;
F_50 (lseg, tmp, listp, pls_lc_list) {
F_27 ( & V_73 -> V_105 ) ;
F_74 ( V_73 ) ;
}
F_211 ( V_46 ) ;
}
void F_214 ( struct V_72 * V_73 )
{
F_57 ( V_73 -> V_107 , V_73 -> V_76 . V_65 ) ;
}
void
F_185 ( struct V_46 * V_46 , struct V_72 * V_73 ,
T_5 V_309 )
{
struct V_57 * V_58 = F_30 ( V_46 ) ;
bool V_310 = false ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_52 ( V_159 , & V_58 -> V_160 ) ) {
V_58 -> V_59 -> V_311 = V_309 ;
V_310 = true ;
F_3 ( L_63 ,
V_5 , V_46 -> V_133 ) ;
} else if ( V_309 > V_58 -> V_59 -> V_311 )
V_58 -> V_59 -> V_311 = V_309 ;
if ( ! F_52 ( V_84 , & V_73 -> V_75 ) ) {
F_143 ( V_73 ) ;
}
F_7 ( & V_46 -> V_62 ) ;
F_3 ( L_64 ,
V_5 , V_73 , V_58 -> V_59 -> V_311 ) ;
if ( V_310 )
F_215 ( V_46 ) ;
}
void F_216 ( struct V_312 * V_313 )
{
struct V_8 * V_9 = F_24 ( V_313 -> args . V_46 ) ;
if ( V_9 -> V_10 -> V_314 )
V_9 -> V_10 -> V_314 ( V_313 ) ;
F_213 ( V_313 -> args . V_46 , & V_313 -> V_85 ) ;
}
int
F_92 ( struct V_46 * V_46 , bool V_166 )
{
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
struct V_312 * V_313 ;
struct V_57 * V_58 = F_30 ( V_46 ) ;
T_5 V_309 ;
int V_35 ;
if ( ! F_217 ( V_46 ) )
return 0 ;
F_3 ( L_65 , V_5 , V_46 -> V_133 ) ;
V_35 = - V_131 ;
if ( F_52 ( V_307 , & V_58 -> V_160 ) ) {
if ( ! V_166 )
goto V_4;
V_35 = F_218 ( & V_58 -> V_160 ,
V_307 ,
V_221 ,
V_315 ) ;
if ( V_35 )
goto V_4;
}
V_35 = - V_152 ;
V_313 = F_103 ( sizeof( * V_313 ) , V_169 ) ;
if ( ! V_313 )
goto V_316;
V_35 = 0 ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_47 ( V_159 , & V_58 -> V_160 ) )
goto V_163;
F_64 ( & V_313 -> V_85 ) ;
F_212 ( V_46 , & V_313 -> V_85 ) ;
V_309 = V_58 -> V_59 -> V_311 ;
F_99 ( & V_313 -> args . V_103 , & V_58 -> V_59 -> V_143 ) ;
F_7 ( & V_46 -> V_62 ) ;
V_313 -> args . V_46 = V_46 ;
V_313 -> V_158 = F_139 ( V_58 -> V_59 -> V_55 ) ;
F_219 ( & V_313 -> V_317 ) ;
V_313 -> args . V_318 = F_24 ( V_46 ) -> V_319 ;
V_313 -> V_179 . V_317 = & V_313 -> V_317 ;
if ( V_309 != 0 )
V_313 -> args . V_320 = V_309 - 1 ;
else
V_313 -> args . V_320 = V_321 ;
V_313 -> V_179 . V_20 = F_24 ( V_46 ) ;
if ( V_49 -> V_322 ) {
V_35 = V_49 -> V_322 ( & V_313 -> args ) ;
if ( V_35 ) {
F_28 ( V_313 -> V_158 ) ;
F_5 ( & V_46 -> V_62 ) ;
F_36 ( V_159 , & V_58 -> V_160 ) ;
if ( V_309 > V_58 -> V_59 -> V_311 )
V_58 -> V_59 -> V_311 = V_309 ;
goto V_163;
}
}
V_35 = F_220 ( V_313 , V_166 ) ;
V_4:
if ( V_35 )
F_215 ( V_46 ) ;
F_3 ( L_66 , V_5 , V_35 ) ;
return V_35 ;
V_163:
F_7 ( & V_46 -> V_62 ) ;
F_221 ( V_313 ) ;
V_316:
F_211 ( V_46 ) ;
goto V_4;
}
int
F_222 ( struct V_46 * V_46 , bool V_323 )
{
return F_92 ( V_46 , true ) ;
}
struct V_204 * F_223 ( void )
{
struct V_204 * V_324 ;
V_324 = F_103 ( sizeof( * V_324 ) , V_169 ) ;
if ( ! V_324 ) {
F_3 ( L_67 , V_5 ) ;
return NULL ;
}
return V_324 ;
}
int
F_224 ( struct V_46 * V_46 , T_2 V_48 )
{
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
struct V_8 * V_20 = F_24 ( V_46 ) ;
struct V_57 * V_58 = F_30 ( V_46 ) ;
struct V_325 * V_313 ;
struct V_43 * V_273 ;
int V_35 = 0 ;
if ( ! F_149 ( V_20 ) || ! V_49 -> V_326 )
goto V_4;
if ( ! F_225 ( V_46 , V_327 ) )
goto V_4;
if ( F_52 ( V_328 , & V_58 -> V_160 ) )
goto V_4;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_30 ( V_46 ) -> V_59 ) {
F_7 ( & V_46 -> V_62 ) ;
goto V_329;
}
V_273 = F_30 ( V_46 ) -> V_59 ;
F_22 ( V_273 ) ;
F_7 ( & V_46 -> V_62 ) ;
V_313 = F_103 ( sizeof( * V_313 ) , V_48 ) ;
if ( ! V_313 ) {
V_35 = - V_152 ;
goto V_330;
}
V_313 -> args . V_331 = F_226 ( V_46 ) ;
V_313 -> args . V_46 = V_46 ;
V_35 = V_49 -> V_326 ( & V_313 -> args ) ;
if ( V_35 )
goto V_332;
V_35 = F_227 ( F_24 ( V_46 ) , V_313 ) ;
V_4:
F_3 ( L_68 , V_5 , V_35 ) ;
return V_35 ;
V_332:
F_221 ( V_313 ) ;
V_330:
F_31 ( V_273 ) ;
V_329:
F_228 () ;
F_39 ( V_328 , & V_58 -> V_160 ) ;
F_43 () ;
goto V_4;
}
