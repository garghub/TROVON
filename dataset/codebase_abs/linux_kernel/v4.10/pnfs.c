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
V_44 -> V_67 = 0 ;
V_44 -> V_71 = 0 ;
F_39 ( V_69 , & V_44 -> V_70 ) ;
}
static void F_40 ( struct V_43 * V_44 )
{
F_41 ( V_72 , & V_44 -> V_70 ) ;
F_39 ( V_73 , & V_44 -> V_70 ) ;
F_42 () ;
F_43 ( & V_44 -> V_70 , V_72 ) ;
F_44 ( & F_24 ( V_44 -> V_51 ) -> V_74 ) ;
}
static void
F_45 ( struct V_75 * V_76 ,
struct V_77 * V_78 )
{
F_39 ( V_79 , & V_76 -> V_80 ) ;
F_39 ( V_81 , & V_76 -> V_80 ) ;
if ( F_46 ( V_82 , & V_76 -> V_80 ) )
F_47 ( V_76 , V_78 ) ;
if ( F_46 ( V_83 , & V_76 -> V_80 ) )
F_47 ( V_76 , V_78 ) ;
}
int
F_48 ( struct V_43 * V_44 ,
struct V_77 * V_84 )
{
struct V_85 V_86 = {
. V_65 = V_68 ,
. V_87 = 0 ,
. V_88 = V_89 ,
} ;
struct V_75 * V_76 , * V_90 ;
F_36 ( V_91 , & V_44 -> V_70 ) ;
F_38 ( V_44 ) ;
F_49 (lseg, next, &lo->plh_segs, pls_list)
F_45 ( V_76 , V_84 ) ;
F_50 ( V_44 , V_84 , & V_86 , 0 ) ;
if ( F_51 ( V_72 , & V_44 -> V_70 ) &&
! F_52 ( V_73 , & V_44 -> V_70 ) )
F_40 ( V_44 ) ;
return ! F_26 ( & V_44 -> V_63 ) ;
}
static int
F_53 ( T_1 V_65 )
{
return V_65 == V_92 ?
V_93 : V_94 ;
}
static void
F_54 ( struct V_43 * V_44 , int V_95 )
{
V_44 -> V_96 = V_97 ;
if ( ! F_52 ( V_95 , & V_44 -> V_70 ) )
F_17 ( & V_44 -> V_45 ) ;
}
static void
F_55 ( struct V_43 * V_44 , int V_95 )
{
if ( F_46 ( V_95 , & V_44 -> V_70 ) )
F_56 ( & V_44 -> V_45 ) ;
}
static void
F_57 ( struct V_43 * V_44 , T_1 V_65 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
struct V_85 V_86 = {
. V_65 = V_65 ,
. V_87 = 0 ,
. V_88 = V_89 ,
} ;
F_58 ( V_98 ) ;
F_5 ( & V_46 -> V_62 ) ;
F_54 ( V_44 , F_53 ( V_65 ) ) ;
F_59 ( V_44 , & V_98 , & V_86 , 0 ) ;
F_7 ( & V_46 -> V_62 ) ;
F_60 ( & V_98 ) ;
F_3 ( L_18 , V_5 ,
V_65 == V_92 ? L_19 : L_20 ) ;
}
static bool
F_61 ( struct V_43 * V_44 , T_1 V_65 )
{
unsigned long V_99 , V_100 ;
int V_95 = F_53 ( V_65 ) ;
if ( F_51 ( V_95 , & V_44 -> V_70 ) == 0 )
return false ;
V_100 = V_97 ;
V_99 = V_100 - V_101 ;
if ( ! F_62 ( V_44 -> V_96 , V_99 , V_100 ) ) {
F_55 ( V_44 , V_95 ) ;
return false ;
}
return true ;
}
static void
F_63 ( struct V_43 * V_44 , struct V_75 * V_76 ,
const struct V_85 * V_86 ,
const T_3 * V_102 )
{
F_64 ( & V_76 -> V_103 ) ;
F_64 ( & V_76 -> V_104 ) ;
F_65 ( & V_76 -> V_105 , 1 ) ;
F_36 ( V_82 , & V_76 -> V_80 ) ;
V_76 -> V_106 = V_44 ;
V_76 -> V_107 = * V_86 ;
V_76 -> V_108 = F_66 ( V_102 -> V_109 ) ;
}
static void F_67 ( struct V_75 * V_76 )
{
if ( V_76 != NULL ) {
struct V_46 * V_46 = V_76 -> V_106 -> V_51 ;
F_24 ( V_46 ) -> V_10 -> V_39 ( V_76 ) ;
}
}
static void
F_68 ( struct V_43 * V_44 ,
struct V_75 * V_76 )
{
F_69 ( F_51 ( V_82 , & V_76 -> V_80 ) ) ;
F_27 ( & V_76 -> V_103 ) ;
F_56 ( & V_44 -> V_45 ) ;
if ( F_51 ( V_81 , & V_76 -> V_80 ) )
return;
if ( F_26 ( & V_44 -> V_63 ) &&
! F_51 ( V_69 , & V_44 -> V_70 ) &&
! F_51 ( V_72 , & V_44 -> V_70 ) ) {
if ( F_70 ( & V_44 -> V_110 ) == 0 )
F_36 ( V_91 , & V_44 -> V_70 ) ;
F_39 ( V_111 , & V_44 -> V_70 ) ;
}
}
static bool
F_71 ( struct V_43 * V_44 ,
struct V_75 * V_76 )
{
if ( F_46 ( V_81 , & V_76 -> V_80 ) &&
F_72 ( V_44 ) ) {
F_35 ( V_44 , V_76 -> V_107 . V_65 , 0 ) ;
F_73 ( & V_76 -> V_103 , & V_44 -> V_112 ) ;
return true ;
}
return false ;
}
void
F_74 ( struct V_75 * V_76 )
{
struct V_43 * V_44 ;
struct V_46 * V_46 ;
if ( ! V_76 )
return;
F_3 ( L_21 , V_5 , V_76 ,
F_70 ( & V_76 -> V_105 ) ,
F_51 ( V_82 , & V_76 -> V_80 ) ) ;
V_44 = V_76 -> V_106 ;
V_46 = V_44 -> V_51 ;
if ( F_33 ( & V_76 -> V_105 , & V_46 -> V_62 ) ) {
if ( F_51 ( V_82 , & V_76 -> V_80 ) ) {
F_7 ( & V_46 -> V_62 ) ;
return;
}
F_22 ( V_44 ) ;
F_68 ( V_44 , V_76 ) ;
if ( F_71 ( V_44 , V_76 ) )
V_76 = NULL ;
F_7 ( & V_46 -> V_62 ) ;
F_67 ( V_76 ) ;
F_31 ( V_44 ) ;
}
}
static void F_75 ( struct V_113 * V_114 )
{
struct V_75 * V_76 ;
struct V_43 * V_44 ;
V_76 = F_76 ( V_114 , struct V_75 , V_115 ) ;
V_44 = V_76 -> V_106 ;
F_67 ( V_76 ) ;
F_31 ( V_44 ) ;
}
static void F_77 ( struct V_75 * V_76 )
{
F_78 ( & V_76 -> V_115 , F_75 ) ;
F_79 ( & V_76 -> V_115 ) ;
}
void
F_80 ( struct V_75 * V_76 )
{
if ( ! V_76 )
return;
F_81 ( & V_76 -> V_106 -> V_51 -> V_62 ) ;
F_3 ( L_21 , V_5 , V_76 ,
F_70 ( & V_76 -> V_105 ) ,
F_51 ( V_82 , & V_76 -> V_80 ) ) ;
if ( F_9 ( & V_76 -> V_105 ) ) {
struct V_43 * V_44 = V_76 -> V_106 ;
if ( F_51 ( V_82 , & V_76 -> V_80 ) )
return;
F_68 ( V_44 , V_76 ) ;
if ( ! F_71 ( V_44 , V_76 ) ) {
F_22 ( V_44 ) ;
F_77 ( V_76 ) ;
}
}
}
static bool
F_82 ( const struct V_85 * V_116 ,
const struct V_85 * V_117 )
{
T_4 V_118 = V_116 -> V_87 ;
T_4 V_119 = F_83 ( V_118 , V_116 -> V_88 ) ;
T_4 V_120 = V_117 -> V_87 ;
T_4 V_121 = F_83 ( V_120 , V_117 -> V_88 ) ;
return ( V_118 <= V_120 ) && ( V_119 >= V_121 ) ;
}
static bool F_47 ( struct V_75 * V_76 ,
struct V_77 * V_122 )
{
if ( ! F_9 ( & V_76 -> V_105 ) )
return false ;
F_68 ( V_76 -> V_106 , V_76 ) ;
F_19 ( & V_76 -> V_103 , V_122 ) ;
return true ;
}
static int F_84 ( struct V_75 * V_76 ,
struct V_77 * V_122 )
{
int V_123 = 0 ;
if ( F_46 ( V_82 , & V_76 -> V_80 ) ) {
F_3 ( L_22 , V_5 , V_76 ,
F_70 ( & V_76 -> V_105 ) ) ;
if ( F_47 ( V_76 , V_122 ) )
V_123 = 1 ;
}
return V_123 ;
}
static bool F_85 ( T_1 V_124 , T_1 V_125 )
{
return ( V_126 ) ( V_124 - V_125 ) > 0 ;
}
static bool
F_86 ( const struct V_85 * V_127 ,
const struct V_85 * V_128 )
{
return ( V_128 -> V_65 == V_68 ||
V_127 -> V_65 == V_128 -> V_65 ) &&
F_87 ( V_127 , V_128 ) ;
}
static bool
F_88 ( const struct V_75 * V_76 ,
const struct V_85 * V_128 ,
T_1 V_66 )
{
if ( V_66 != 0 && F_85 ( V_76 -> V_108 , V_66 ) )
return false ;
if ( V_128 == NULL )
return true ;
return F_86 ( & V_76 -> V_107 , V_128 ) ;
}
int
F_59 ( struct V_43 * V_44 ,
struct V_77 * V_122 ,
const struct V_85 * V_128 ,
T_1 V_66 )
{
struct V_75 * V_76 , * V_90 ;
int V_129 = 0 ;
F_3 ( L_23 , V_5 , V_44 ) ;
if ( F_26 ( & V_44 -> V_63 ) )
return 0 ;
F_49 (lseg, next, &lo->plh_segs, pls_list)
if ( F_88 ( V_76 , V_128 , V_66 ) ) {
F_3 ( L_24
L_25 , V_5 ,
V_76 , V_76 -> V_107 . V_65 , V_76 -> V_108 ,
V_76 -> V_107 . V_87 , V_76 -> V_107 . V_88 ) ;
if ( ! F_84 ( V_76 , V_122 ) )
V_129 ++ ;
}
F_3 ( L_26 , V_5 , V_129 ) ;
return V_129 ;
}
static void
F_50 ( struct V_43 * V_44 ,
struct V_77 * V_78 ,
const struct V_85 * V_86 ,
T_1 V_66 )
{
struct V_75 * V_76 , * V_90 ;
F_49 (lseg, next, &lo->plh_return_segs, pls_list) {
if ( F_88 ( V_76 , V_86 , V_66 ) )
F_73 ( & V_76 -> V_103 , V_78 ) ;
}
}
void
F_60 ( struct V_77 * V_78 )
{
struct V_75 * V_76 , * V_37 ;
if ( F_26 ( V_78 ) )
return;
F_49 (lseg, tmp, free_me, pls_list) {
F_21 ( & V_76 -> V_103 ) ;
F_67 ( V_76 ) ;
}
}
void
F_89 ( struct V_57 * V_58 )
{
struct V_43 * V_44 ;
F_58 ( V_122 ) ;
F_5 ( & V_58 -> V_130 . V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( V_44 ) {
F_22 ( V_44 ) ;
F_48 ( V_44 , & V_122 ) ;
F_55 ( V_44 , V_94 ) ;
F_55 ( V_44 , V_93 ) ;
F_7 ( & V_58 -> V_130 . V_62 ) ;
F_60 ( & V_122 ) ;
F_31 ( V_44 ) ;
} else
F_7 ( & V_58 -> V_130 . V_62 ) ;
}
static bool
F_90 ( struct V_46 * V_46 ,
struct V_77 * V_131 )
{
struct V_43 * V_44 ;
bool V_132 = false ;
F_5 ( & V_46 -> V_62 ) ;
V_44 = F_30 ( V_46 ) -> V_59 ;
if ( V_44 != NULL && F_26 ( & V_44 -> V_133 ) ) {
F_22 ( V_44 ) ;
F_19 ( & V_44 -> V_133 , V_131 ) ;
V_132 = true ;
}
F_7 ( & V_46 -> V_62 ) ;
return V_132 ;
}
static int
F_91 ( struct V_12 * V_53 ,
struct V_8 * V_20 ,
struct V_77 * V_131 )
{
struct V_43 * V_44 , * V_90 ;
struct V_46 * V_46 ;
F_49 (lo, next, &server->layouts, plh_layouts) {
if ( F_51 ( V_91 , & V_44 -> V_70 ) )
continue;
V_46 = F_92 ( V_44 -> V_51 ) ;
if ( V_46 == NULL )
continue;
F_27 ( & V_44 -> V_52 ) ;
if ( F_90 ( V_46 , V_131 ) )
continue;
F_93 () ;
F_7 ( & V_53 -> V_54 ) ;
F_94 ( V_46 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_95 () ;
return - V_134 ;
}
return 0 ;
}
static int
F_96 ( struct V_77 * V_131 ,
bool V_135 )
{
struct V_43 * V_44 ;
struct V_46 * V_46 ;
F_58 ( V_84 ) ;
int V_132 = 0 ;
while ( ! F_26 ( V_131 ) ) {
V_44 = F_97 ( V_131 -> V_90 , struct V_43 ,
V_133 ) ;
F_3 ( L_27 , V_5 ,
V_44 -> V_51 -> V_136 ) ;
V_46 = V_44 -> V_51 ;
F_98 ( V_46 , false ) ;
F_5 ( & V_46 -> V_62 ) ;
F_27 ( & V_44 -> V_133 ) ;
if ( F_48 ( V_44 , & V_84 ) ) {
if ( V_135 )
F_36 ( V_111 , & V_44 -> V_70 ) ;
V_132 = - V_134 ;
}
F_7 ( & V_46 -> V_62 ) ;
F_60 ( & V_84 ) ;
F_99 ( V_46 , 0 ) ;
F_31 ( V_44 ) ;
F_94 ( V_46 ) ;
}
return V_132 ;
}
int
F_100 ( struct V_12 * V_53 ,
struct V_137 * V_138 ,
bool V_139 )
{
struct V_8 * V_20 ;
F_58 ( V_131 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_95 () ;
V_140:
F_101 (server, &clp->cl_superblocks, client_link) {
if ( memcmp ( & V_20 -> V_138 , V_138 , sizeof( * V_138 ) ) != 0 )
continue;
if ( F_91 ( V_53 ,
V_20 ,
& V_131 ) != 0 )
goto V_140;
}
F_93 () ;
F_7 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_131 ) )
return 0 ;
return F_96 ( & V_131 , V_139 ) ;
}
int
F_102 ( struct V_12 * V_53 ,
bool V_139 )
{
struct V_8 * V_20 ;
F_58 ( V_131 ) ;
F_5 ( & V_53 -> V_54 ) ;
F_95 () ;
V_140:
F_101 (server, &clp->cl_superblocks, client_link) {
if ( F_91 ( V_53 ,
V_20 ,
& V_131 ) != 0 )
goto V_140;
}
F_93 () ;
F_7 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_131 ) )
return 0 ;
return F_96 ( & V_131 , V_139 ) ;
}
void
F_103 ( struct V_12 * V_53 )
{
F_104 ( V_53 ) ;
F_10 ( V_53 ) ;
F_102 ( V_53 , false ) ;
}
void
F_105 ( struct V_43 * V_44 , const T_3 * V_141 ,
bool V_142 )
{
T_1 V_143 , V_144 , V_145 = 0 ;
V_143 = F_66 ( V_44 -> V_146 . V_109 ) ;
V_144 = F_66 ( V_141 -> V_109 ) ;
if ( ! F_72 ( V_44 ) ) {
F_106 ( & V_44 -> V_146 , V_141 ) ;
V_44 -> V_147 = V_144 ;
F_38 ( V_44 ) ;
F_39 ( V_91 , & V_44 -> V_70 ) ;
return;
}
if ( F_85 ( V_144 , V_143 ) ) {
F_106 ( & V_44 -> V_146 , V_141 ) ;
V_145 = V_144 - F_70 ( & V_44 -> V_110 ) ;
}
if ( V_142 )
V_145 = F_66 ( V_141 -> V_109 ) ;
else if ( V_145 == 0 )
return;
if ( F_85 ( V_145 , V_44 -> V_147 ) )
V_44 -> V_147 = V_145 ;
}
static bool
F_107 ( const struct V_43 * V_44 ,
const T_3 * V_102 )
{
T_1 V_109 = F_66 ( V_102 -> V_109 ) ;
return ! F_85 ( V_109 , V_44 -> V_147 ) ;
}
static bool
F_108 ( const struct V_43 * V_44 )
{
return V_44 -> V_148 ||
F_51 ( V_111 , & V_44 -> V_70 ) ;
}
static struct V_75 *
F_109 ( struct V_43 * V_44 ,
struct V_149 * V_150 ,
T_3 * V_102 ,
const struct V_85 * V_86 ,
long * V_151 , T_2 V_48 )
{
struct V_46 * V_47 = V_44 -> V_51 ;
struct V_8 * V_20 = F_24 ( V_47 ) ;
struct V_152 * V_153 ;
T_5 V_154 ;
F_3 ( L_28 , V_5 ) ;
V_153 = F_110 ( sizeof( * V_153 ) , V_48 ) ;
if ( V_153 == NULL )
return F_111 ( - V_155 ) ;
V_154 = F_112 ( V_47 ) ;
V_153 -> args . V_156 = V_157 ;
if ( V_153 -> args . V_156 > V_86 -> V_88 )
V_153 -> args . V_156 = V_86 -> V_88 ;
if ( V_86 -> V_65 == V_158 ) {
if ( V_86 -> V_87 >= V_154 )
V_153 -> args . V_156 = 0 ;
else if ( V_154 - V_86 -> V_87 < V_153 -> args . V_156 )
V_153 -> args . V_156 = V_154 - V_86 -> V_87 ;
}
V_153 -> args . V_159 = V_160 ;
F_113 ( & V_153 -> args . V_86 , V_86 ) ;
V_153 -> args . type = V_20 -> V_10 -> V_2 ;
V_153 -> args . V_46 = V_47 ;
V_153 -> args . V_150 = F_114 ( V_150 ) ;
F_106 ( & V_153 -> args . V_102 , V_102 ) ;
V_153 -> V_48 = V_48 ;
V_153 -> V_161 = V_44 -> V_55 ;
return F_115 ( V_153 , V_151 , V_48 ) ;
}
static void F_116 ( struct V_46 * V_46 ,
struct V_77 * V_98 )
{
struct V_57 * V_58 = F_30 ( V_46 ) ;
struct V_75 * V_76 , * V_37 ;
if ( ! F_46 ( V_162 , & V_58 -> V_163 ) )
return;
F_49 (lseg, tmp, &nfsi->layout->plh_segs, pls_list) {
if ( ! F_46 ( V_83 , & V_76 -> V_80 ) )
continue;
F_47 ( V_76 , V_98 ) ;
}
}
void F_117 ( struct V_43 * V_44 ,
const T_3 * V_164 ,
const struct V_85 * V_86 ,
const T_3 * V_102 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
F_58 ( V_165 ) ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_72 ( V_44 ) || ! V_164 ||
! F_118 ( & V_44 -> V_146 , V_164 ) )
goto V_166;
if ( V_102 ) {
T_1 V_66 = F_66 ( V_164 -> V_109 ) ;
F_59 ( V_44 , & V_165 , V_86 , V_66 ) ;
F_50 ( V_44 , & V_165 , V_86 , V_66 ) ;
F_105 ( V_44 , V_102 , true ) ;
} else
F_48 ( V_44 , & V_165 ) ;
V_166:
F_40 ( V_44 ) ;
F_7 ( & V_46 -> V_62 ) ;
F_60 ( & V_165 ) ;
}
static bool
F_119 ( struct V_43 * V_44 ,
T_3 * V_102 ,
enum V_64 * V_65 )
{
if ( F_70 ( & V_44 -> V_110 ) != 0 )
return false ;
if ( F_52 ( V_73 , & V_44 -> V_70 ) )
return false ;
F_36 ( V_72 , & V_44 -> V_70 ) ;
F_22 ( V_44 ) ;
if ( F_51 ( V_69 , & V_44 -> V_70 ) ) {
if ( V_102 != NULL ) {
F_106 ( V_102 , & V_44 -> V_146 ) ;
if ( V_44 -> V_71 != 0 )
V_102 -> V_109 = F_120 ( V_44 -> V_71 ) ;
}
if ( V_65 != NULL )
* V_65 = V_44 -> V_67 ;
F_38 ( V_44 ) ;
return true ;
}
if ( V_102 != NULL )
F_106 ( V_102 , & V_44 -> V_146 ) ;
if ( V_65 != NULL )
* V_65 = V_68 ;
return true ;
}
static void
F_121 ( struct V_167 * args ,
struct V_43 * V_44 ,
const T_3 * V_102 ,
enum V_64 V_65 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
args -> V_168 = F_24 ( V_46 ) -> V_10 -> V_2 ;
args -> V_46 = V_46 ;
args -> V_86 . V_65 = V_65 ;
args -> V_86 . V_87 = 0 ;
args -> V_86 . V_88 = V_89 ;
args -> V_59 = V_44 ;
F_106 ( & args -> V_102 , V_102 ) ;
}
static int
F_122 ( struct V_43 * V_44 , const T_3 * V_102 ,
enum V_64 V_65 , bool V_169 )
{
struct V_46 * V_47 = V_44 -> V_51 ;
struct V_1 * V_49 = F_24 ( V_47 ) -> V_10 ;
struct V_170 * V_171 ;
int V_35 = 0 ;
V_171 = F_110 ( sizeof( * V_171 ) , V_172 ) ;
if ( F_123 ( V_171 == NULL ) ) {
V_35 = - V_155 ;
F_5 ( & V_47 -> V_62 ) ;
F_40 ( V_44 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_31 ( V_44 ) ;
goto V_4;
}
F_121 ( & V_171 -> args , V_44 , V_102 , V_65 ) ;
V_171 -> args . V_173 = & V_171 -> V_173 ;
V_171 -> V_53 = F_24 ( V_47 ) -> V_12 ;
V_171 -> V_161 = V_44 -> V_55 ;
if ( V_49 -> V_174 )
V_49 -> V_174 ( & V_171 -> args ) ;
V_35 = F_124 ( V_171 , V_169 ) ;
V_4:
F_3 ( L_29 , V_5 , V_35 ) ;
return V_35 ;
}
static bool
F_125 ( struct V_43 * V_44 )
{
struct V_75 * V_175 ;
if ( ! F_51 ( V_69 , & V_44 -> V_70 ) )
return false ;
F_2 (s, &lo->plh_segs, pls_list) {
if ( F_51 ( V_81 , & V_175 -> V_80 ) )
return false ;
}
return true ;
}
static void F_32 ( struct V_43 * V_44 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
if ( ! F_51 ( V_69 , & V_44 -> V_70 ) )
return;
F_5 ( & V_46 -> V_62 ) ;
if ( F_125 ( V_44 ) ) {
T_3 V_102 ;
enum V_64 V_65 ;
bool V_176 ;
V_176 = F_119 ( V_44 , & V_102 , & V_65 ) ;
F_7 ( & V_46 -> V_62 ) ;
if ( V_176 ) {
F_122 ( V_44 , & V_102 , V_65 , false ) ;
}
} else
F_7 ( & V_46 -> V_62 ) ;
}
int
F_126 ( struct V_46 * V_47 )
{
struct V_43 * V_44 = NULL ;
struct V_57 * V_58 = F_30 ( V_47 ) ;
F_58 ( V_122 ) ;
T_3 V_102 ;
int V_35 = 0 ;
bool V_176 ;
F_3 ( L_30 , V_5 , V_47 -> V_136 ) ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( ! V_44 ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_31 , V_5 ) ;
goto V_4;
}
F_22 ( V_44 ) ;
if ( F_51 ( V_73 , & V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
if ( F_127 ( & V_44 -> V_70 , V_72 ,
V_177 ) )
goto V_178;
F_5 ( & V_47 -> V_62 ) ;
}
F_116 ( V_47 , & V_122 ) ;
F_59 ( V_44 , & V_122 , NULL , 0 ) ;
if ( F_24 ( V_47 ) -> V_10 -> V_179 ) {
struct V_85 V_86 = {
. V_65 = V_68 ,
. V_87 = 0 ,
. V_88 = V_89 ,
} ;
F_24 ( V_47 ) -> V_10 -> V_179 ( V_44 , & V_86 ) ;
}
if ( ! F_51 ( V_69 , & V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_32 , V_5 ) ;
goto V_178;
}
V_176 = F_119 ( V_44 , & V_102 , NULL ) ;
F_7 ( & V_47 -> V_62 ) ;
if ( V_176 )
V_35 = F_122 ( V_44 , & V_102 , V_68 , true ) ;
V_178:
F_60 ( & V_122 ) ;
F_31 ( V_44 ) ;
V_4:
F_3 ( L_29 , V_5 , V_35 ) ;
return V_35 ;
}
int
F_128 ( struct V_46 * V_46 )
{
struct V_43 * V_44 ;
int V_132 ;
F_5 ( & V_46 -> V_62 ) ;
V_44 = F_30 ( V_46 ) -> V_59 ;
if ( V_44 == NULL ) {
F_7 ( & V_46 -> V_62 ) ;
return 0 ;
}
F_22 ( V_44 ) ;
V_44 -> V_148 ++ ;
F_7 ( & V_46 -> V_62 ) ;
F_129 ( V_46 -> V_180 ) ;
V_132 = F_98 ( V_46 , true ) ;
if ( V_132 == 0 )
V_132 = F_126 ( V_46 ) ;
F_5 ( & V_46 -> V_62 ) ;
V_44 -> V_148 -- ;
F_7 ( & V_46 -> V_62 ) ;
F_31 ( V_44 ) ;
return V_132 ;
}
bool F_130 ( struct V_46 * V_47 ,
struct V_167 * args ,
struct V_181 * V_182 ,
const struct V_183 * V_161 )
{
struct V_57 * V_58 = F_30 ( V_47 ) ;
struct V_149 * V_150 ;
struct V_184 * V_185 ;
struct V_43 * V_44 ;
struct V_75 * V_76 , * V_90 ;
T_3 V_102 ;
enum V_64 V_65 = 0 ;
bool V_186 = false , V_187 = false ;
bool V_188 = false ;
if ( ! F_131 ( V_47 ) )
return false ;
V_189:
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( ! V_44 || ! F_72 ( V_44 ) ||
F_51 ( V_111 , & V_44 -> V_70 ) )
goto V_190;
if ( F_51 ( V_73 , & V_44 -> V_70 ) ) {
F_22 ( V_44 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_127 ( & V_44 -> V_70 , V_72 ,
V_177 ) ;
F_31 ( V_44 ) ;
goto V_189;
}
if ( F_132 ( V_47 , V_191 ) ) {
if ( F_132 ( V_47 , V_192 ) )
goto V_190;
V_188 = true ;
}
F_2 (ctx, &nfsi->open_files, list) {
V_185 = V_150 -> V_185 ;
if ( V_185 == NULL )
continue;
if ( V_185 -> V_185 & V_192 )
goto V_190;
if ( V_185 -> V_185 & V_191 )
V_188 = true ;
}
F_49 (lseg, next, &lo->plh_segs, pls_list) {
if ( V_188 && V_76 -> V_107 . V_65 == V_158 )
continue;
if ( ! F_46 ( V_79 , & V_76 -> V_80 ) )
continue;
F_36 ( V_81 , & V_76 -> V_80 ) ;
if ( ! F_84 ( V_76 , & V_44 -> V_112 ) )
continue;
F_35 ( V_44 , V_76 -> V_107 . V_65 , 0 ) ;
}
if ( ! F_51 ( V_69 , & V_44 -> V_70 ) )
goto V_190;
V_186 = F_119 ( V_44 , & V_102 , & V_65 ) ;
if ( ! V_186 || V_161 != V_44 -> V_55 )
goto V_190;
V_187 = V_186 ;
F_121 ( args , V_44 , & V_102 , V_65 ) ;
V_182 -> V_193 = 0 ;
V_186 = false ;
V_190:
F_7 ( & V_47 -> V_62 ) ;
F_98 ( V_47 , true ) ;
if ( V_187 ) {
struct V_1 * V_49 = F_24 ( V_47 ) -> V_10 ;
if ( V_49 -> V_174 )
V_49 -> V_174 ( args ) ;
return true ;
}
if ( V_186 )
F_122 ( V_44 , & V_102 , V_65 , true ) ;
return false ;
}
void F_133 ( struct V_167 * args ,
struct V_181 * V_182 ,
int V_132 )
{
struct V_43 * V_44 = args -> V_59 ;
const T_3 * V_164 = NULL ;
const T_3 * V_194 = NULL ;
struct V_195 * V_173 = args -> V_173 ;
if ( V_132 == 0 ) {
V_164 = & args -> V_102 ;
if ( V_182 -> V_193 )
V_194 = & V_182 -> V_102 ;
}
F_117 ( V_44 , V_164 , & args -> V_86 ,
V_194 ) ;
if ( V_173 && V_173 -> V_196 && V_173 -> V_196 -> free )
V_173 -> V_196 -> free ( V_173 ) ;
F_31 ( V_44 ) ;
F_134 ( args -> V_46 , 0 ) ;
}
bool F_135 ( struct V_46 * V_47 , struct V_197 * V_198 )
{
struct V_57 * V_58 = F_30 ( V_47 ) ;
struct V_43 * V_44 ;
bool V_199 = false ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = V_58 -> V_59 ;
if ( V_44 && F_51 ( V_72 , & V_44 -> V_70 ) ) {
F_136 ( & F_24 ( V_47 ) -> V_74 , V_198 , NULL ) ;
V_199 = true ;
}
F_7 ( & V_47 -> V_62 ) ;
return V_199 ;
}
static T_6
F_137 ( const struct V_85 * V_116 ,
const struct V_85 * V_117 )
{
T_6 V_200 ;
V_200 = V_116 -> V_87 - V_117 -> V_87 ;
if ( V_200 )
return V_200 ;
V_200 = V_117 -> V_88 - V_116 -> V_88 ;
if ( V_200 )
return V_200 ;
return ( int ) ( V_116 -> V_65 == V_158 ) - ( int ) ( V_117 -> V_65 == V_158 ) ;
}
static bool
F_138 ( const struct V_85 * V_116 ,
const struct V_85 * V_117 )
{
return F_137 ( V_116 , V_117 ) > 0 ;
}
static bool
F_139 ( struct V_75 * V_76 ,
struct V_75 * V_201 )
{
return false ;
}
void
F_140 ( struct V_43 * V_44 ,
struct V_75 * V_76 ,
bool (* F_141)( const struct V_85 * ,
const struct V_85 * ) ,
bool (* F_142)( struct V_75 * ,
struct V_75 * ) ,
struct V_77 * V_78 )
{
struct V_75 * V_202 , * V_37 ;
F_3 ( L_33 , V_5 ) ;
F_49 (lp, tmp, &lo->plh_segs, pls_list) {
if ( F_51 ( V_82 , & V_202 -> V_80 ) == 0 )
continue;
if ( F_142 ( V_76 , V_202 ) ) {
F_84 ( V_202 , V_78 ) ;
continue;
}
if ( F_141 ( & V_76 -> V_107 , & V_202 -> V_107 ) )
continue;
F_143 ( & V_76 -> V_103 , & V_202 -> V_103 ) ;
F_3 ( L_34
L_35
L_36 ,
V_5 , V_76 , V_76 -> V_107 . V_65 ,
V_76 -> V_107 . V_87 , V_76 -> V_107 . V_88 ,
V_202 , V_202 -> V_107 . V_65 , V_202 -> V_107 . V_87 ,
V_202 -> V_107 . V_88 ) ;
goto V_4;
}
F_143 ( & V_76 -> V_103 , & V_44 -> V_63 ) ;
F_3 ( L_34
L_37 ,
V_5 , V_76 , V_76 -> V_107 . V_65 ,
V_76 -> V_107 . V_87 , V_76 -> V_107 . V_88 ) ;
V_4:
F_22 ( V_44 ) ;
F_3 ( L_38 , V_5 ) ;
}
static void
F_144 ( struct V_43 * V_44 ,
struct V_75 * V_76 ,
struct V_77 * V_78 )
{
struct V_46 * V_46 = V_44 -> V_51 ;
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
if ( V_49 -> V_203 != NULL )
V_49 -> V_203 ( V_44 , V_76 , V_78 ) ;
else
F_140 ( V_44 , V_76 ,
F_138 ,
F_139 ,
V_78 ) ;
}
static struct V_43 *
F_145 ( struct V_46 * V_47 ,
struct V_149 * V_150 ,
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
F_64 ( & V_44 -> V_133 ) ;
V_44 -> V_51 = V_47 ;
V_44 -> V_55 = F_146 ( V_150 -> V_161 ) ;
V_44 -> V_70 |= 1 << V_91 ;
return V_44 ;
}
static struct V_43 *
F_147 ( struct V_46 * V_47 ,
struct V_149 * V_150 ,
T_2 V_48 )
__releases( &ino->i_lock
static bool
F_148 ( const struct V_85 * V_204 ,
const struct V_85 * V_86 ,
bool V_205 )
{
struct V_85 V_206 ;
if ( ( V_86 -> V_65 == V_92 &&
V_204 -> V_65 != V_92 ) ||
( V_86 -> V_65 != V_204 -> V_65 &&
V_205 == true ) ||
! F_87 ( V_204 , V_86 ) )
return 0 ;
V_206 = * V_86 ;
V_206 . V_88 = 1 ;
return F_82 ( V_204 , & V_206 ) ;
}
static struct V_75 *
F_149 ( struct V_43 * V_44 ,
struct V_85 * V_86 ,
bool V_205 )
{
struct V_75 * V_76 , * V_132 = NULL ;
F_3 ( L_33 , V_5 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_51 ( V_82 , & V_76 -> V_80 ) &&
! F_51 ( V_81 , & V_76 -> V_80 ) &&
F_148 ( & V_76 -> V_107 , V_86 ,
V_205 ) ) {
V_132 = F_150 ( V_76 ) ;
break;
}
}
F_3 ( L_39 ,
V_5 , V_132 , V_132 ? F_70 ( & V_132 -> V_105 ) : 0 ) ;
return V_132 ;
}
static bool F_151 ( struct V_149 * V_150 ,
struct V_46 * V_47 , int V_65 )
{
struct V_207 * V_208 = V_150 -> V_209 ;
struct V_57 * V_58 = F_30 ( V_47 ) ;
T_5 V_210 = F_112 ( V_47 ) ;
bool V_211 = false , V_212 = false , V_213 = false , V_214 = false , V_132 = false ;
if ( V_208 == NULL )
return V_132 ;
F_3 ( L_40 ,
V_5 , V_208 -> V_215 , V_208 -> V_216 , V_208 -> V_217 , V_208 -> V_218 , V_208 -> V_219 ) ;
switch ( V_65 ) {
case V_158 :
if ( V_208 -> V_215 & V_220 ) {
F_3 ( L_41 , V_5 , V_210 ) ;
V_212 = true ;
if ( V_210 < V_208 -> V_216 )
V_211 = true ;
}
if ( V_208 -> V_215 & V_221 ) {
F_3 ( L_42 , V_5 ,
V_58 -> V_61 ) ;
V_214 = true ;
if ( V_58 -> V_61 < V_208 -> V_218 )
V_213 = true ;
}
break;
case V_92 :
if ( V_208 -> V_215 & V_222 ) {
F_3 ( L_41 , V_5 , V_210 ) ;
V_212 = true ;
if ( V_210 < V_208 -> V_217 )
V_211 = true ;
}
if ( V_208 -> V_215 & V_223 ) {
F_3 ( L_43 , V_5 ,
V_58 -> V_60 ) ;
V_214 = true ;
if ( V_58 -> V_60 < V_208 -> V_219 )
V_213 = true ;
}
break;
}
if ( V_212 && V_214 ) {
if ( V_211 && V_213 )
V_132 = true ;
} else if ( V_211 || V_213 )
V_132 = true ;
F_3 ( L_44 , V_5 , V_211 , V_213 , V_132 ) ;
return V_132 ;
}
static bool F_152 ( struct V_43 * V_44 )
{
F_98 ( V_44 -> V_51 , false ) ;
return ! F_153 ( & V_44 -> V_70 , V_72 ,
V_224 ,
V_177 ) ;
}
static void F_154 ( struct V_43 * V_44 )
{
unsigned long * V_225 = & V_44 -> V_70 ;
F_41 ( V_226 , V_225 ) ;
F_42 () ;
F_43 ( V_225 , V_226 ) ;
}
struct V_75 *
F_155 ( struct V_46 * V_47 ,
struct V_149 * V_150 ,
T_5 V_227 ,
T_4 V_228 ,
enum V_64 V_65 ,
bool V_205 ,
T_2 V_48 )
{
struct V_85 V_229 = {
. V_65 = V_65 ,
. V_87 = V_227 ,
. V_88 = V_228 ,
} ;
unsigned V_230 , V_66 ;
struct V_8 * V_20 = F_24 ( V_47 ) ;
struct V_12 * V_53 = V_20 -> V_12 ;
struct V_43 * V_44 = NULL ;
struct V_75 * V_76 = NULL ;
T_3 V_102 ;
long V_151 = 0 ;
unsigned long V_231 = V_97 + ( V_53 -> V_232 << 1 ) ;
bool V_233 ;
if ( ! F_156 ( F_24 ( V_47 ) ) ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_234 ) ;
goto V_4;
}
if ( V_65 == V_158 && F_112 ( V_47 ) == 0 ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_235 ) ;
goto V_4;
}
if ( F_151 ( V_150 , V_47 , V_65 ) ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_236 ) ;
goto V_4;
}
V_237:
F_158 ( V_53 ) ;
V_233 = false ;
F_5 ( & V_47 -> V_62 ) ;
V_44 = F_147 ( V_47 , V_150 , V_48 ) ;
if ( V_44 == NULL ) {
F_7 ( & V_47 -> V_62 ) ;
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_238 ) ;
goto V_4;
}
if ( F_51 ( V_111 , & V_44 -> V_70 ) ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_239 ) ;
F_3 ( L_45 , V_5 ) ;
goto V_166;
}
if ( F_61 ( V_44 , V_65 ) ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_240 ) ;
goto V_166;
}
V_76 = F_149 ( V_44 , & V_229 , V_205 ) ;
if ( V_76 ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_241 ) ;
goto V_166;
}
if ( ! F_159 ( V_150 -> V_185 ) ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_242 ) ;
goto V_166;
}
if ( F_51 ( V_91 , & V_44 -> V_70 ) ) {
if ( F_52 ( V_226 ,
& V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_127 ( & V_44 -> V_70 , V_226 ,
V_177 ) ;
F_31 ( V_44 ) ;
F_3 ( L_46 , V_5 ) ;
goto V_237;
}
V_233 = true ;
do {
V_66 = F_160 ( & V_150 -> V_185 -> V_243 ) ;
F_106 ( & V_102 , & V_150 -> V_185 -> V_102 ) ;
} while ( F_161 ( & V_150 -> V_185 -> V_243 , V_66 ) );
} else {
F_106 ( & V_102 , & V_44 -> V_146 ) ;
}
if ( F_51 ( V_72 , & V_44 -> V_70 ) ) {
F_7 ( & V_47 -> V_62 ) ;
F_3 ( L_47 , V_5 ) ;
if ( F_152 ( V_44 ) ) {
if ( V_233 )
F_154 ( V_44 ) ;
F_31 ( V_44 ) ;
F_3 ( L_46 , V_5 ) ;
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 ,
V_76 , V_244 ) ;
goto V_237;
}
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_245 ) ;
goto V_178;
}
if ( F_108 ( V_44 ) ) {
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_246 ) ;
goto V_166;
}
F_17 ( & V_44 -> V_110 ) ;
F_7 ( & V_47 -> V_62 ) ;
if ( F_26 ( & V_44 -> V_52 ) ) {
F_5 ( & V_53 -> V_54 ) ;
if ( F_26 ( & V_44 -> V_52 ) )
F_143 ( & V_44 -> V_52 , & V_20 -> V_247 ) ;
F_7 ( & V_53 -> V_54 ) ;
}
V_230 = V_229 . V_87 & ~ V_248 ;
if ( V_230 ) {
V_229 . V_87 -= V_230 ;
V_229 . V_88 += V_230 ;
}
if ( V_229 . V_88 != V_89 )
V_229 . V_88 = F_162 ( V_229 . V_88 ) ;
V_76 = F_109 ( V_44 , V_150 , & V_102 , & V_229 , & V_151 , V_48 ) ;
F_157 ( V_47 , V_227 , V_228 , V_65 , V_44 , V_76 ,
V_249 ) ;
F_56 ( & V_44 -> V_110 ) ;
if ( F_163 ( V_76 ) ) {
switch( F_164 ( V_76 ) ) {
case - V_250 :
if ( F_165 ( V_97 , V_231 ) )
V_76 = NULL ;
break;
case - V_251 :
if ( V_233 ) {
V_76 = NULL ;
break;
}
if ( F_165 ( V_97 , V_231 ) )
F_89 ( F_30 ( V_47 ) ) ;
case - V_134 :
break;
default:
if ( ! F_166 ( F_164 ( V_76 ) ) ) {
F_55 ( V_44 , F_53 ( V_65 ) ) ;
V_76 = NULL ;
}
goto V_178;
}
if ( V_76 ) {
if ( V_233 )
F_154 ( V_44 ) ;
F_157 ( V_47 , V_227 , V_228 ,
V_65 , V_44 , V_76 , V_244 ) ;
F_31 ( V_44 ) ;
goto V_237;
}
} else {
F_55 ( V_44 , F_53 ( V_65 ) ) ;
}
V_178:
if ( V_233 )
F_154 ( V_44 ) ;
F_31 ( V_44 ) ;
V_4:
F_3 ( L_48
L_49 ,
V_5 , V_47 -> V_252 -> V_253 ,
( unsigned long long ) F_167 ( V_47 ) ,
F_168 ( V_76 ) ? L_50 : L_51 ,
V_65 == V_92 ? L_52 : L_53 ,
( unsigned long long ) V_227 ,
( unsigned long long ) V_228 ) ;
return V_76 ;
V_166:
F_7 ( & V_47 -> V_62 ) ;
goto V_178;
}
static bool
F_169 ( struct V_85 * V_86 )
{
switch ( V_86 -> V_65 ) {
case V_158 :
case V_92 :
break;
default:
return false ;
}
if ( V_86 -> V_87 == V_89 )
return false ;
if ( V_86 -> V_88 == 0 )
return false ;
if ( V_86 -> V_88 != V_89 &&
V_86 -> V_88 > V_89 - V_86 -> V_87 )
return false ;
return true ;
}
struct V_75 *
F_170 ( struct V_152 * V_153 )
{
struct V_43 * V_44 = F_30 ( V_153 -> args . V_46 ) -> V_59 ;
struct V_254 * V_182 = & V_153 -> V_182 ;
struct V_75 * V_76 ;
struct V_46 * V_47 = V_44 -> V_51 ;
F_58 ( V_78 ) ;
if ( ! F_169 ( & V_182 -> V_86 ) )
return F_111 ( - V_36 ) ;
V_76 = F_24 ( V_47 ) -> V_10 -> V_38 ( V_44 , V_182 , V_153 -> V_48 ) ;
if ( F_168 ( V_76 ) ) {
if ( ! V_76 )
V_76 = F_111 ( - V_155 ) ;
F_3 ( L_54 ,
V_5 , F_164 ( V_76 ) ) ;
return V_76 ;
}
F_63 ( V_44 , V_76 , & V_182 -> V_86 , & V_182 -> V_102 ) ;
F_5 ( & V_47 -> V_62 ) ;
if ( F_108 ( V_44 ) ) {
F_3 ( L_55 , V_5 ) ;
goto V_255;
}
if ( ! F_72 ( V_44 ) ) {
F_105 ( V_44 , & V_182 -> V_102 , true ) ;
} else if ( F_118 ( & V_44 -> V_146 , & V_182 -> V_102 ) ) {
if ( F_107 ( V_44 , & V_182 -> V_102 ) ) {
F_3 ( L_56 , V_5 ) ;
goto V_255;
}
F_105 ( V_44 , & V_182 -> V_102 , false ) ;
} else {
F_48 ( V_44 , & V_78 ) ;
goto V_255;
}
F_150 ( V_76 ) ;
F_144 ( V_44 , V_76 , & V_78 ) ;
if ( V_182 -> V_256 )
F_36 ( V_79 , & V_76 -> V_80 ) ;
F_7 ( & V_47 -> V_62 ) ;
F_60 ( & V_78 ) ;
return V_76 ;
V_255:
F_7 ( & V_47 -> V_62 ) ;
V_76 -> V_106 = V_44 ;
F_24 ( V_47 ) -> V_10 -> V_39 ( V_76 ) ;
return F_111 ( - V_134 ) ;
}
int
F_171 ( struct V_43 * V_44 ,
struct V_77 * V_122 ,
const struct V_85 * V_179 ,
T_1 V_66 )
{
struct V_75 * V_76 , * V_90 ;
int V_129 = 0 ;
F_3 ( L_23 , V_5 , V_44 ) ;
if ( F_26 ( & V_44 -> V_63 ) )
return 0 ;
F_81 ( & V_44 -> V_51 -> V_62 ) ;
F_49 (lseg, next, &lo->plh_segs, pls_list)
if ( F_88 ( V_76 , V_179 , V_66 ) ) {
F_3 ( L_57
L_25 , V_5 ,
V_76 , V_76 -> V_107 . V_65 ,
V_76 -> V_107 . V_87 ,
V_76 -> V_107 . V_88 ) ;
if ( F_84 ( V_76 , V_122 ) )
continue;
V_129 ++ ;
F_36 ( V_81 , & V_76 -> V_80 ) ;
}
if ( V_129 )
F_35 ( V_44 , V_179 -> V_65 , V_66 ) ;
return V_129 ;
}
void F_172 ( struct V_46 * V_46 ,
struct V_75 * V_76 )
{
struct V_43 * V_44 = F_30 ( V_46 ) -> V_59 ;
struct V_85 V_86 = {
. V_65 = V_76 -> V_107 . V_65 ,
. V_87 = 0 ,
. V_88 = V_89 ,
} ;
bool V_257 = false ;
F_5 ( & V_46 -> V_62 ) ;
F_35 ( V_44 , V_86 . V_65 , 0 ) ;
F_36 ( V_72 , & V_44 -> V_70 ) ;
if ( ! F_171 ( V_44 , & V_44 -> V_112 , & V_86 , 0 ) ) {
T_3 V_102 ;
enum V_64 V_65 ;
V_257 = F_119 ( V_44 , & V_102 , & V_65 ) ;
F_7 ( & V_46 -> V_62 ) ;
if ( V_257 )
F_122 ( V_44 , & V_102 , V_65 , false ) ;
} else {
F_7 ( & V_46 -> V_62 ) ;
F_99 ( V_46 , 0 ) ;
}
}
void
F_173 ( struct V_258 * V_259 , struct V_260 * V_261 )
{
T_4 V_262 = V_261 -> V_263 ;
if ( V_259 -> V_264 == NULL ) {
if ( V_259 -> V_265 == NULL )
V_262 = F_112 ( V_259 -> V_266 ) - F_174 ( V_261 ) ;
else
V_262 = F_175 ( V_259 -> V_265 ) ;
V_259 -> V_264 = F_155 ( V_259 -> V_266 ,
V_261 -> V_267 ,
F_174 ( V_261 ) ,
V_262 ,
V_158 ,
false ,
V_268 ) ;
if ( F_163 ( V_259 -> V_264 ) ) {
V_259 -> V_269 = F_164 ( V_259 -> V_264 ) ;
V_259 -> V_264 = NULL ;
return;
}
}
if ( V_259 -> V_264 == NULL )
F_176 ( V_259 ) ;
}
void
F_177 ( struct V_258 * V_259 ,
struct V_260 * V_261 , T_4 V_270 )
{
if ( V_259 -> V_264 == NULL ) {
V_259 -> V_264 = F_155 ( V_259 -> V_266 ,
V_261 -> V_267 ,
F_174 ( V_261 ) ,
V_270 ,
V_92 ,
false ,
V_172 ) ;
if ( F_163 ( V_259 -> V_264 ) ) {
V_259 -> V_269 = F_164 ( V_259 -> V_264 ) ;
V_259 -> V_264 = NULL ;
return;
}
}
if ( V_259 -> V_264 == NULL )
F_178 ( V_259 ) ;
}
void
F_179 ( struct V_258 * V_271 )
{
if ( V_271 -> V_264 ) {
F_74 ( V_271 -> V_264 ) ;
V_271 -> V_264 = NULL ;
}
}
T_7
F_180 ( struct V_258 * V_259 ,
struct V_260 * V_272 , struct V_260 * V_261 )
{
unsigned int V_211 ;
T_4 V_273 , V_274 , V_275 ;
V_211 = F_181 ( V_259 , V_272 , V_261 ) ;
if ( ! V_211 )
return 0 ;
if ( V_259 -> V_264 ) {
V_273 = F_83 ( V_259 -> V_264 -> V_107 . V_87 ,
V_259 -> V_264 -> V_107 . V_88 ) ;
V_274 = F_174 ( V_261 ) ;
F_37 ( V_274 >= V_273 ) ;
if ( V_274 >= V_273 ) {
if ( V_259 -> V_276 -> V_277 )
V_259 -> V_276 -> V_277 ( V_259 ) ;
if ( V_259 -> V_276 -> V_278 )
V_259 -> V_276 -> V_278 ( V_259 , V_261 ) ;
return 0 ;
}
V_275 = V_273 - V_274 ;
if ( V_275 < V_211 )
V_211 = ( unsigned int ) V_275 ;
}
return V_211 ;
}
int F_182 ( struct V_279 * V_280 )
{
struct V_258 V_259 ;
F_183 ( & V_259 , V_280 -> V_46 , V_281 , true ,
V_280 -> V_282 ) ;
F_36 ( V_283 , & V_280 -> args . V_284 -> V_163 ) ;
return F_184 ( & V_259 , V_280 ) ;
}
static void F_185 ( struct V_279 * V_280 )
{
F_3 ( L_58 , V_280 -> V_285 ) ;
if ( F_24 ( V_280 -> V_46 ) -> V_10 -> V_163 &
V_286 ) {
F_186 ( V_280 -> V_46 ) ;
}
if ( ! F_52 ( V_287 , & V_280 -> V_163 ) )
V_280 -> V_198 . V_288 = F_182 ( V_280 ) ;
}
void F_187 ( struct V_279 * V_280 )
{
if ( F_188 ( ! V_280 -> V_285 ) ) {
F_189 ( V_280 -> V_46 , V_280 -> V_76 ,
V_280 -> V_289 + V_280 -> V_182 . V_228 ) ;
V_280 -> V_290 -> V_291 ( & V_280 -> V_198 , V_280 ) ;
}
F_190 ( V_280 , V_280 -> V_285 ) ;
if ( F_123 ( V_280 -> V_285 ) )
F_185 ( V_280 ) ;
V_280 -> V_290 -> V_292 ( V_280 ) ;
}
static void
F_191 ( struct V_258 * V_271 ,
struct V_279 * V_280 )
{
struct V_293 * V_294 = F_192 ( V_271 ) ;
if ( ! F_52 ( V_287 , & V_280 -> V_163 ) ) {
F_193 ( & V_280 -> V_295 , & V_294 -> V_296 ) ;
F_178 ( V_271 ) ;
V_294 -> V_297 = 1 ;
}
F_194 ( V_280 ) ;
V_280 -> V_298 ( V_280 ) ;
}
static enum V_299
F_195 ( struct V_279 * V_280 ,
const struct V_300 * V_301 ,
struct V_75 * V_76 ,
int V_302 )
{
struct V_46 * V_46 = V_280 -> V_46 ;
enum V_299 V_303 ;
struct V_8 * V_9 = F_24 ( V_46 ) ;
V_280 -> V_290 = V_301 ;
F_3 ( L_59 , V_5 ,
V_46 -> V_136 , V_280 -> args . V_228 , V_280 -> args . V_87 , V_302 ) ;
V_303 = V_9 -> V_10 -> V_304 ( V_280 , V_302 ) ;
if ( V_303 != V_305 )
F_196 ( V_46 , V_306 ) ;
F_3 ( L_60 , V_5 , V_303 ) ;
return V_303 ;
}
static void
F_197 ( struct V_258 * V_271 ,
struct V_279 * V_280 , int V_302 )
{
const struct V_300 * V_301 = V_271 -> V_307 ;
struct V_75 * V_76 = V_271 -> V_264 ;
enum V_299 V_303 ;
V_303 = F_195 ( V_280 , V_301 , V_76 , V_302 ) ;
if ( V_303 == V_305 )
F_191 ( V_271 , V_280 ) ;
}
static void F_198 ( struct V_279 * V_280 )
{
F_74 ( V_280 -> V_76 ) ;
F_199 ( V_280 ) ;
}
int
F_200 ( struct V_258 * V_271 )
{
struct V_279 * V_280 ;
int V_132 ;
V_280 = F_201 ( V_271 -> V_308 ) ;
if ( ! V_280 ) {
V_271 -> V_269 = - V_155 ;
return V_271 -> V_269 ;
}
F_202 ( V_271 , V_280 , F_198 ) ;
V_280 -> V_76 = F_150 ( V_271 -> V_264 ) ;
V_132 = F_203 ( V_271 , V_280 ) ;
if ( ! V_132 )
F_197 ( V_271 , V_280 , V_271 -> V_309 ) ;
return V_132 ;
}
int F_204 ( struct V_279 * V_280 )
{
struct V_258 V_259 ;
F_205 ( & V_259 , V_280 -> V_46 , true , V_280 -> V_282 ) ;
return F_184 ( & V_259 , V_280 ) ;
}
static void F_206 ( struct V_279 * V_280 )
{
F_3 ( L_61 , V_280 -> V_285 ) ;
if ( F_24 ( V_280 -> V_46 ) -> V_10 -> V_163 &
V_286 ) {
F_186 ( V_280 -> V_46 ) ;
}
if ( ! F_52 ( V_287 , & V_280 -> V_163 ) )
V_280 -> V_198 . V_288 = F_204 ( V_280 ) ;
}
void F_207 ( struct V_279 * V_280 )
{
if ( F_188 ( ! V_280 -> V_285 ) )
V_280 -> V_290 -> V_291 ( & V_280 -> V_198 , V_280 ) ;
F_208 ( V_280 , V_280 -> V_285 ) ;
if ( F_123 ( V_280 -> V_285 ) )
F_206 ( V_280 ) ;
V_280 -> V_290 -> V_292 ( V_280 ) ;
}
static void
F_209 ( struct V_258 * V_271 ,
struct V_279 * V_280 )
{
struct V_293 * V_294 = F_192 ( V_271 ) ;
if ( ! F_52 ( V_287 , & V_280 -> V_163 ) ) {
F_193 ( & V_280 -> V_295 , & V_294 -> V_296 ) ;
F_176 ( V_271 ) ;
V_294 -> V_297 = 1 ;
}
F_194 ( V_280 ) ;
V_280 -> V_298 ( V_280 ) ;
}
static enum V_299
F_210 ( struct V_279 * V_280 ,
const struct V_300 * V_301 ,
struct V_75 * V_76 )
{
struct V_46 * V_46 = V_280 -> V_46 ;
struct V_8 * V_9 = F_24 ( V_46 ) ;
enum V_299 V_303 ;
V_280 -> V_290 = V_301 ;
F_3 ( L_62 ,
V_5 , V_46 -> V_136 , V_280 -> args . V_228 , V_280 -> args . V_87 ) ;
V_303 = V_9 -> V_10 -> V_310 ( V_280 ) ;
if ( V_303 != V_305 )
F_196 ( V_46 , V_311 ) ;
F_3 ( L_60 , V_5 , V_303 ) ;
return V_303 ;
}
void F_211 ( struct V_279 * V_280 )
{
struct V_258 V_259 ;
if ( ! F_52 ( V_287 , & V_280 -> V_163 ) ) {
F_74 ( V_280 -> V_76 ) ;
V_280 -> V_76 = NULL ;
F_205 ( & V_259 , V_280 -> V_46 , false ,
V_280 -> V_282 ) ;
V_280 -> V_198 . V_288 = F_184 ( & V_259 , V_280 ) ;
}
}
static void
F_212 ( struct V_258 * V_271 , struct V_279 * V_280 )
{
const struct V_300 * V_301 = V_271 -> V_307 ;
struct V_75 * V_76 = V_271 -> V_264 ;
enum V_299 V_303 ;
V_303 = F_210 ( V_280 , V_301 , V_76 ) ;
if ( V_303 == V_312 )
F_211 ( V_280 ) ;
if ( V_303 == V_305 || V_280 -> V_198 . V_288 )
F_209 ( V_271 , V_280 ) ;
}
static void F_213 ( struct V_279 * V_280 )
{
F_74 ( V_280 -> V_76 ) ;
F_199 ( V_280 ) ;
}
int
F_214 ( struct V_258 * V_271 )
{
struct V_279 * V_280 ;
int V_132 ;
V_280 = F_201 ( V_271 -> V_308 ) ;
if ( ! V_280 ) {
V_271 -> V_269 = - V_155 ;
return V_271 -> V_269 ;
}
F_202 ( V_271 , V_280 , F_213 ) ;
V_280 -> V_76 = F_150 ( V_271 -> V_264 ) ;
V_132 = F_203 ( V_271 , V_280 ) ;
if ( ! V_132 )
F_212 ( V_271 , V_280 ) ;
return V_132 ;
}
static void F_215 ( struct V_46 * V_46 )
{
unsigned long * V_225 = & F_30 ( V_46 ) -> V_163 ;
F_41 ( V_313 , V_225 ) ;
F_42 () ;
F_43 ( V_225 , V_313 ) ;
}
static void F_216 ( struct V_46 * V_46 , struct V_77 * V_314 )
{
struct V_75 * V_76 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_76 -> V_107 . V_65 == V_92 &&
F_46 ( V_83 , & V_76 -> V_80 ) )
F_19 ( & V_76 -> V_104 , V_314 ) ;
}
}
static void F_217 ( struct V_46 * V_46 , struct V_77 * V_314 )
{
struct V_75 * V_76 , * V_37 ;
F_49 (lseg, tmp, listp, pls_lc_list) {
F_27 ( & V_76 -> V_104 ) ;
F_74 ( V_76 ) ;
}
F_215 ( V_46 ) ;
}
void F_218 ( struct V_75 * V_76 )
{
F_57 ( V_76 -> V_106 , V_76 -> V_107 . V_65 ) ;
}
void
F_189 ( struct V_46 * V_46 , struct V_75 * V_76 ,
T_5 V_315 )
{
struct V_57 * V_58 = F_30 ( V_46 ) ;
bool V_316 = false ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_52 ( V_162 , & V_58 -> V_163 ) ) {
V_58 -> V_59 -> V_317 = V_315 ;
V_316 = true ;
F_3 ( L_63 ,
V_5 , V_46 -> V_136 ) ;
} else if ( V_315 > V_58 -> V_59 -> V_317 )
V_58 -> V_59 -> V_317 = V_315 ;
if ( ! F_52 ( V_83 , & V_76 -> V_80 ) ) {
F_150 ( V_76 ) ;
}
F_7 ( & V_46 -> V_62 ) ;
F_3 ( L_64 ,
V_5 , V_76 , V_58 -> V_59 -> V_317 ) ;
if ( V_316 )
F_219 ( V_46 ) ;
}
void F_220 ( struct V_318 * V_319 )
{
struct V_8 * V_9 = F_24 ( V_319 -> args . V_46 ) ;
if ( V_9 -> V_10 -> V_320 )
V_9 -> V_10 -> V_320 ( V_319 ) ;
F_217 ( V_319 -> args . V_46 , & V_319 -> V_84 ) ;
}
int
F_98 ( struct V_46 * V_46 , bool V_169 )
{
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
struct V_318 * V_319 ;
struct V_57 * V_58 = F_30 ( V_46 ) ;
T_5 V_315 ;
int V_35 ;
if ( ! F_221 ( V_46 ) )
return 0 ;
F_3 ( L_65 , V_5 , V_46 -> V_136 ) ;
V_35 = - V_134 ;
if ( F_52 ( V_313 , & V_58 -> V_163 ) ) {
if ( ! V_169 )
goto V_4;
V_35 = F_222 ( & V_58 -> V_163 ,
V_313 ,
V_224 ,
V_321 ) ;
if ( V_35 )
goto V_4;
}
V_35 = - V_155 ;
V_319 = F_110 ( sizeof( * V_319 ) , V_172 ) ;
if ( ! V_319 )
goto V_322;
V_35 = 0 ;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_46 ( V_162 , & V_58 -> V_163 ) )
goto V_166;
F_64 ( & V_319 -> V_84 ) ;
F_216 ( V_46 , & V_319 -> V_84 ) ;
V_315 = V_58 -> V_59 -> V_317 ;
F_106 ( & V_319 -> args . V_102 , & V_58 -> V_59 -> V_146 ) ;
F_7 ( & V_46 -> V_62 ) ;
V_319 -> args . V_46 = V_46 ;
V_319 -> V_161 = F_146 ( V_58 -> V_59 -> V_55 ) ;
F_223 ( & V_319 -> V_323 ) ;
V_319 -> args . V_324 = F_24 ( V_46 ) -> V_325 ;
V_319 -> V_182 . V_323 = & V_319 -> V_323 ;
if ( V_315 != 0 )
V_319 -> args . V_326 = V_315 - 1 ;
else
V_319 -> args . V_326 = V_327 ;
V_319 -> V_182 . V_20 = F_24 ( V_46 ) ;
if ( V_49 -> V_328 ) {
V_35 = V_49 -> V_328 ( & V_319 -> args ) ;
if ( V_35 ) {
F_28 ( V_319 -> V_161 ) ;
F_5 ( & V_46 -> V_62 ) ;
F_36 ( V_162 , & V_58 -> V_163 ) ;
if ( V_315 > V_58 -> V_59 -> V_317 )
V_58 -> V_59 -> V_317 = V_315 ;
goto V_166;
}
}
V_35 = F_224 ( V_319 , V_169 ) ;
V_4:
if ( V_35 )
F_219 ( V_46 ) ;
F_3 ( L_66 , V_5 , V_35 ) ;
return V_35 ;
V_166:
F_7 ( & V_46 -> V_62 ) ;
F_225 ( V_319 ) ;
V_322:
F_215 ( V_46 ) ;
goto V_4;
}
int
F_226 ( struct V_46 * V_46 , bool V_329 )
{
return F_98 ( V_46 , true ) ;
}
struct V_207 * F_227 ( void )
{
struct V_207 * V_330 ;
V_330 = F_110 ( sizeof( * V_330 ) , V_172 ) ;
if ( ! V_330 ) {
F_3 ( L_67 , V_5 ) ;
return NULL ;
}
return V_330 ;
}
int
F_228 ( struct V_46 * V_46 , T_2 V_48 )
{
struct V_1 * V_49 = F_24 ( V_46 ) -> V_10 ;
struct V_8 * V_20 = F_24 ( V_46 ) ;
struct V_57 * V_58 = F_30 ( V_46 ) ;
struct V_331 * V_319 ;
struct V_43 * V_280 ;
int V_35 = 0 ;
if ( ! F_156 ( V_20 ) || ! V_49 -> V_332 )
goto V_4;
if ( ! F_229 ( V_46 , V_333 ) )
goto V_4;
if ( F_52 ( V_334 , & V_58 -> V_163 ) )
goto V_4;
F_5 ( & V_46 -> V_62 ) ;
if ( ! F_30 ( V_46 ) -> V_59 ) {
F_7 ( & V_46 -> V_62 ) ;
goto V_335;
}
V_280 = F_30 ( V_46 ) -> V_59 ;
F_22 ( V_280 ) ;
F_7 ( & V_46 -> V_62 ) ;
V_319 = F_110 ( sizeof( * V_319 ) , V_48 ) ;
if ( ! V_319 ) {
V_35 = - V_155 ;
goto V_336;
}
V_319 -> args . V_337 = F_230 ( V_46 ) ;
V_319 -> args . V_46 = V_46 ;
V_35 = V_49 -> V_332 ( & V_319 -> args ) ;
if ( V_35 )
goto V_338;
V_35 = F_231 ( F_24 ( V_46 ) , V_319 ) ;
V_4:
F_3 ( L_68 , V_5 , V_35 ) ;
return V_35 ;
V_338:
F_225 ( V_319 ) ;
V_336:
F_31 ( V_280 ) ;
V_335:
F_232 () ;
F_39 ( V_334 , & V_58 -> V_163 ) ;
F_42 () ;
goto V_4;
}
