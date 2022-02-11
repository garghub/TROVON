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
F_6 ( & V_6 ) ;
return V_3 ;
}
void
F_7 ( struct V_7 * V_8 )
{
if ( V_8 -> V_9 ) {
if ( V_8 -> V_9 -> V_10 )
V_8 -> V_9 -> V_10 ( V_8 ) ;
F_8 ( V_8 -> V_9 -> V_11 ) ;
}
V_8 -> V_9 = NULL ;
}
void
F_9 ( struct V_7 * V_12 , const struct V_13 * V_14 ,
T_1 V_2 )
{
struct V_1 * V_15 = NULL ;
if ( V_2 == 0 )
goto V_16;
if ( ! ( V_12 -> V_17 -> V_18 &
( V_19 | V_20 ) ) ) {
F_10 ( V_21 L_2 ,
V_5 , V_2 , V_12 -> V_17 -> V_18 ) ;
goto V_16;
}
V_15 = F_4 ( V_2 ) ;
if ( ! V_15 ) {
F_11 ( L_3 , V_22 , V_2 ) ;
V_15 = F_4 ( V_2 ) ;
if ( ! V_15 ) {
F_3 ( L_4 ,
V_5 , V_2 ) ;
goto V_16;
}
}
if ( ! F_12 ( V_15 -> V_11 ) ) {
F_3 ( L_5 , V_5 ) ;
goto V_16;
}
V_12 -> V_9 = V_15 ;
if ( V_15 -> V_23
&& V_15 -> V_23 ( V_12 , V_14 ) ) {
F_10 ( V_21 L_6
L_7 , V_5 , V_2 ) ;
F_8 ( V_15 -> V_11 ) ;
goto V_16;
}
F_3 ( L_8 , V_5 , V_2 ) ;
return;
V_16:
F_3 ( L_9 , V_5 ) ;
V_12 -> V_9 = NULL ;
}
int
F_13 ( struct V_1 * V_15 )
{
int V_24 = - V_25 ;
struct V_1 * V_26 ;
if ( V_15 -> V_2 == 0 ) {
F_10 ( V_21 L_10 , V_5 ) ;
return V_24 ;
}
if ( ! V_15 -> V_27 || ! V_15 -> V_28 ) {
F_10 ( V_21 L_11
L_12 , V_5 ) ;
return V_24 ;
}
F_5 ( & V_6 ) ;
V_26 = F_1 ( V_15 -> V_2 ) ;
if ( ! V_26 ) {
F_14 ( & V_15 -> V_29 , & V_30 ) ;
V_24 = 0 ;
F_3 ( L_13 , V_5 , V_15 -> V_2 ,
V_15 -> V_31 ) ;
} else {
F_10 ( V_21 L_14 ,
V_5 , V_15 -> V_2 ) ;
}
F_6 ( & V_6 ) ;
return V_24 ;
}
void
F_15 ( struct V_1 * V_15 )
{
F_3 ( L_15 , V_5 , V_15 -> V_2 ) ;
F_5 ( & V_6 ) ;
F_16 ( & V_15 -> V_29 ) ;
F_6 ( & V_6 ) ;
}
void
F_17 ( struct V_32 * V_33 )
{
F_18 ( & V_33 -> V_34 ) ;
}
static struct V_32 *
F_19 ( struct V_35 * V_36 , T_2 V_37 )
{
struct V_1 * V_38 = F_20 ( V_36 ) -> V_9 ;
return V_38 -> V_39 ? V_38 -> V_39 ( V_36 , V_37 ) :
F_21 ( sizeof( struct V_32 ) , V_37 ) ;
}
static void
F_22 ( struct V_32 * V_33 )
{
struct V_1 * V_38 = F_20 ( V_33 -> V_40 ) -> V_9 ;
F_23 ( V_33 -> V_41 ) ;
return V_38 -> V_39 ? V_38 -> V_42 ( V_33 ) : F_24 ( V_33 ) ;
}
static void
F_25 ( struct V_32 * V_33 )
{
F_3 ( L_16 , V_5 , V_33 ) ;
F_26 ( ! F_27 ( & V_33 -> V_43 ) ) ;
F_28 ( V_33 -> V_40 ) -> V_44 = NULL ;
F_22 ( V_33 ) ;
}
static void
F_29 ( struct V_32 * V_33 )
{
if ( F_30 ( & V_33 -> V_34 ) )
F_25 ( V_33 ) ;
}
void
F_31 ( struct V_32 * V_33 )
{
struct V_35 * V_35 = V_33 -> V_40 ;
if ( F_32 ( & V_33 -> V_34 , & V_35 -> V_45 ) ) {
F_25 ( V_33 ) ;
F_6 ( & V_35 -> V_45 ) ;
}
}
static void
F_33 ( struct V_32 * V_33 , struct V_46 * V_47 )
{
F_34 ( & V_47 -> V_48 ) ;
F_34 ( & V_47 -> V_49 ) ;
F_35 ( & V_47 -> V_50 , 1 ) ;
F_36 () ;
F_37 ( V_51 , & V_47 -> V_52 ) ;
V_47 -> V_53 = V_33 ;
}
static void V_28 ( struct V_46 * V_47 )
{
struct V_35 * V_36 = V_47 -> V_53 -> V_40 ;
F_20 ( V_36 ) -> V_9 -> V_28 ( V_47 ) ;
F_31 ( F_28 ( V_36 ) -> V_44 ) ;
}
static void
F_38 ( struct V_46 * V_47 )
{
struct V_35 * V_35 = V_47 -> V_53 -> V_40 ;
F_39 ( F_40 ( V_51 , & V_47 -> V_52 ) ) ;
F_41 ( & V_47 -> V_48 ) ;
if ( F_27 ( & V_47 -> V_53 -> V_54 ) ) {
F_37 ( V_55 , & V_47 -> V_53 -> V_56 ) ;
F_29 ( V_47 -> V_53 ) ;
}
F_42 ( & F_20 ( V_35 ) -> V_57 ) ;
}
void
F_43 ( struct V_46 * V_47 )
{
struct V_35 * V_35 ;
if ( ! V_47 )
return;
F_3 ( L_17 , V_5 , V_47 ,
F_44 ( & V_47 -> V_50 ) ,
F_40 ( V_51 , & V_47 -> V_52 ) ) ;
V_35 = V_47 -> V_53 -> V_40 ;
if ( F_32 ( & V_47 -> V_50 , & V_35 -> V_45 ) ) {
F_45 ( V_58 ) ;
F_38 ( V_47 ) ;
F_14 ( & V_47 -> V_48 , & V_58 ) ;
F_6 ( & V_35 -> V_45 ) ;
F_46 ( & V_58 ) ;
}
}
static inline T_3
F_47 ( T_3 V_59 , T_3 V_60 )
{
T_3 V_61 ;
V_61 = V_59 + V_60 ;
return V_61 >= V_59 ? V_61 : V_62 ;
}
static inline T_3
F_48 ( T_3 V_59 , T_3 V_60 )
{
T_3 V_61 ;
F_26 ( ! V_60 ) ;
V_61 = V_59 + V_60 ;
return V_61 > V_59 ? V_61 - 1 : V_62 ;
}
static inline int
F_49 ( struct V_63 * V_64 ,
struct V_63 * V_65 )
{
T_3 V_66 = V_64 -> V_67 ;
T_3 V_68 = F_47 ( V_66 , V_64 -> V_69 ) ;
T_3 V_70 = V_65 -> V_67 ;
T_3 V_71 = F_47 ( V_70 , V_65 -> V_69 ) ;
return ( V_66 <= V_70 ) && ( V_68 >= V_71 ) ;
}
static inline int
F_50 ( struct V_63 * V_64 ,
struct V_63 * V_65 )
{
T_3 V_66 = V_64 -> V_67 ;
T_3 V_68 = F_47 ( V_66 , V_64 -> V_69 ) ;
T_3 V_70 = V_65 -> V_67 ;
T_3 V_71 = F_47 ( V_70 , V_65 -> V_69 ) ;
return ( V_68 == V_62 || V_68 > V_70 ) &&
( V_71 == V_62 || V_71 > V_66 ) ;
}
static bool
F_51 ( struct V_63 * V_72 ,
struct V_63 * V_73 )
{
return ( V_73 -> V_74 == V_75 ||
V_72 -> V_74 == V_73 -> V_74 ) &&
F_50 ( V_72 , V_73 ) ;
}
static int F_52 ( struct V_46 * V_47 ,
struct V_76 * V_77 )
{
int V_78 = 0 ;
if ( F_53 ( V_51 , & V_47 -> V_52 ) ) {
F_3 ( L_18 , V_5 , V_47 ,
F_44 ( & V_47 -> V_50 ) ) ;
if ( F_30 ( & V_47 -> V_50 ) ) {
F_38 ( V_47 ) ;
F_14 ( & V_47 -> V_48 , V_77 ) ;
V_78 = 1 ;
}
}
return V_78 ;
}
int
F_54 ( struct V_32 * V_33 ,
struct V_76 * V_77 ,
struct V_63 * V_73 )
{
struct V_46 * V_47 , * V_79 ;
int V_80 = 0 , V_81 = 0 ;
F_3 ( L_19 , V_5 , V_33 ) ;
if ( F_27 ( & V_33 -> V_54 ) ) {
if ( ! F_55 ( V_55 , & V_33 -> V_56 ) )
F_29 ( V_33 ) ;
return 0 ;
}
F_56 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_73 ||
F_51 ( & V_47 -> V_82 , V_73 ) ) {
F_3 ( L_20
L_21 , V_5 ,
V_47 , V_47 -> V_82 . V_74 , V_47 -> V_82 . V_67 ,
V_47 -> V_82 . V_69 ) ;
V_80 ++ ;
V_81 += F_52 ( V_47 , V_77 ) ;
}
F_3 ( L_22 , V_5 , V_80 - V_81 ) ;
return V_80 - V_81 ;
}
void
F_46 ( struct V_76 * V_58 )
{
struct V_46 * V_47 , * V_26 ;
struct V_32 * V_33 ;
if ( F_27 ( V_58 ) )
return;
V_33 = F_57 ( V_58 , struct V_46 ,
V_48 ) -> V_53 ;
if ( F_40 ( V_55 , & V_33 -> V_56 ) ) {
struct V_17 * V_83 ;
V_83 = F_20 ( V_33 -> V_40 ) -> V_17 ;
F_5 ( & V_83 -> V_84 ) ;
F_41 ( & V_33 -> V_43 ) ;
F_6 ( & V_83 -> V_84 ) ;
}
F_56 (lseg, tmp, free_me, pls_list) {
F_16 ( & V_47 -> V_48 ) ;
V_28 ( V_47 ) ;
}
}
void
F_58 ( struct V_85 * V_86 )
{
struct V_32 * V_33 ;
F_45 ( V_77 ) ;
F_5 ( & V_86 -> V_87 . V_45 ) ;
V_33 = V_86 -> V_44 ;
if ( V_33 ) {
V_33 -> V_88 ++ ;
F_54 ( V_33 , & V_77 , NULL ) ;
}
F_6 ( & V_86 -> V_87 . V_45 ) ;
F_46 ( & V_77 ) ;
}
void
F_59 ( struct V_17 * V_83 )
{
struct V_7 * V_12 ;
struct V_32 * V_33 ;
F_45 ( V_77 ) ;
F_60 ( V_83 ) ;
F_61 ( V_83 ) ;
F_5 ( & V_83 -> V_84 ) ;
F_62 () ;
F_63 (server, &clp->cl_superblocks, client_link) {
if ( ! F_27 ( & V_12 -> V_89 ) )
F_64 ( & V_12 -> V_89 , & V_77 ) ;
}
F_65 () ;
F_6 ( & V_83 -> V_84 ) ;
while ( ! F_27 ( & V_77 ) ) {
V_33 = F_66 ( V_77 . V_79 , struct V_32 ,
V_43 ) ;
F_3 ( L_23 , V_5 ,
V_33 -> V_40 -> V_90 ) ;
F_41 ( & V_33 -> V_43 ) ;
F_58 ( F_28 ( V_33 -> V_40 ) ) ;
}
}
void
F_67 ( struct V_32 * V_33 , const T_4 * V_91 ,
bool V_92 )
{
T_1 V_93 , V_94 ;
V_93 = F_68 ( V_33 -> V_95 . V_96 ) ;
V_94 = F_68 ( V_91 -> V_96 ) ;
if ( ( int ) ( V_94 - V_93 ) > 0 ) {
F_69 ( & V_33 -> V_95 , V_91 ) ;
if ( V_92 ) {
T_1 V_97 = F_68 ( V_91 -> V_96 ) ;
if ( ( int ) ( V_97 - V_33 -> V_98 ) )
V_33 -> V_98 = V_97 ;
} else {
if ( F_70 ( ( V_94 - V_33 -> V_98 ) > ( 3 << 29 ) ) )
V_33 -> V_98 = V_94 - ( 1 << 30 ) ;
}
}
}
static bool
F_71 ( struct V_32 * V_33 , T_4 * V_99 ,
int V_100 )
{
if ( ( V_99 ) &&
( int ) ( V_33 -> V_98 - F_68 ( V_99 -> V_96 ) ) >= 0 )
return true ;
return V_33 -> V_88 ||
F_40 ( V_55 , & V_33 -> V_56 ) ||
F_40 ( V_101 , & V_33 -> V_56 ) ||
( F_27 ( & V_33 -> V_54 ) &&
( F_44 ( & V_33 -> V_102 ) > V_100 ) ) ;
}
int
F_72 ( T_4 * V_103 , struct V_32 * V_33 ,
struct V_104 * V_105 )
{
int V_24 = 0 ;
F_3 ( L_24 , V_5 ) ;
F_5 ( & V_33 -> V_40 -> V_45 ) ;
if ( F_71 ( V_33 , NULL , 1 ) ) {
V_24 = - V_106 ;
} else if ( F_27 ( & V_33 -> V_54 ) ) {
int V_107 ;
do {
V_107 = F_73 ( & V_105 -> V_108 ) ;
F_69 ( V_103 , & V_105 -> V_99 ) ;
} while ( F_74 ( & V_105 -> V_108 , V_107 ) );
} else
F_69 ( V_103 , & V_33 -> V_95 ) ;
F_6 ( & V_33 -> V_40 -> V_45 ) ;
F_3 ( L_25 , V_5 ) ;
return V_24 ;
}
static struct V_46 *
F_75 ( struct V_32 * V_33 ,
struct V_109 * V_110 ,
struct V_63 * V_111 ,
T_2 V_37 )
{
struct V_35 * V_36 = V_33 -> V_40 ;
struct V_7 * V_12 = F_20 ( V_36 ) ;
struct V_112 * V_113 ;
struct V_46 * V_47 = NULL ;
struct V_114 * * V_115 = NULL ;
int V_116 ;
T_1 V_117 , V_118 ;
F_3 ( L_24 , V_5 ) ;
F_26 ( V_110 == NULL ) ;
V_113 = F_21 ( sizeof( * V_113 ) , V_37 ) ;
if ( V_113 == NULL )
return NULL ;
V_117 = V_12 -> V_17 -> V_119 -> V_120 . V_117 ;
V_118 = F_76 ( 0 , V_117 ) ;
V_115 = F_77 ( V_118 , sizeof( struct V_114 * ) , V_37 ) ;
if ( ! V_115 )
goto V_121;
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ ) {
V_115 [ V_116 ] = F_78 ( V_37 ) ;
if ( ! V_115 [ V_116 ] )
goto V_121;
}
V_113 -> args . V_122 = V_123 ;
if ( V_113 -> args . V_122 > V_111 -> V_69 )
V_113 -> args . V_122 = V_111 -> V_69 ;
V_113 -> args . V_124 = V_125 ;
V_113 -> args . V_111 = * V_111 ;
V_113 -> args . type = V_12 -> V_9 -> V_2 ;
V_113 -> args . V_35 = V_36 ;
V_113 -> args . V_110 = F_79 ( V_110 ) ;
V_113 -> args . V_44 . V_115 = V_115 ;
V_113 -> args . V_44 . V_126 = V_118 * V_127 ;
V_113 -> V_128 = & V_47 ;
V_113 -> V_37 = V_37 ;
F_80 ( V_113 ) ;
if ( ! V_47 ) {
F_37 ( F_81 ( V_111 -> V_74 ) , & V_33 -> V_56 ) ;
}
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ )
F_82 ( V_115 [ V_116 ] ) ;
F_24 ( V_115 ) ;
return V_47 ;
V_121:
if ( V_115 ) {
for ( V_116 = 0 ; V_116 < V_118 ; V_116 ++ ) {
if ( ! V_115 [ V_116 ] )
break;
F_82 ( V_115 [ V_116 ] ) ;
}
F_24 ( V_115 ) ;
}
F_24 ( V_113 ) ;
return NULL ;
}
int
F_83 ( struct V_35 * V_36 )
{
struct V_32 * V_33 = NULL ;
struct V_85 * V_86 = F_28 ( V_36 ) ;
F_45 ( V_77 ) ;
struct V_129 * V_130 ;
T_4 V_99 ;
int V_24 = 0 ;
F_3 ( L_24 , V_5 ) ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = V_86 -> V_44 ;
if ( ! V_33 ) {
F_6 ( & V_36 -> V_45 ) ;
F_3 ( L_26 , V_5 ) ;
return V_24 ;
}
V_99 = V_86 -> V_44 -> V_95 ;
F_17 ( V_33 ) ;
F_54 ( V_33 , & V_77 , NULL ) ;
V_33 -> V_88 ++ ;
F_6 ( & V_36 -> V_45 ) ;
F_46 ( & V_77 ) ;
F_39 ( F_40 ( V_131 , & V_86 -> V_132 ) ) ;
V_130 = F_21 ( sizeof( * V_130 ) , V_133 ) ;
if ( F_70 ( V_130 == NULL ) ) {
V_24 = - V_134 ;
F_37 ( V_135 , & V_33 -> V_56 ) ;
F_37 ( V_136 , & V_33 -> V_56 ) ;
F_31 ( V_33 ) ;
goto V_4;
}
V_130 -> args . V_99 = V_99 ;
V_130 -> args . V_137 = F_20 ( V_36 ) -> V_9 -> V_2 ;
V_130 -> args . V_35 = V_36 ;
V_130 -> args . V_44 = V_33 ;
V_130 -> V_83 = F_20 ( V_36 ) -> V_17 ;
V_24 = F_84 ( V_130 ) ;
V_4:
F_3 ( L_27 , V_5 , V_24 ) ;
return V_24 ;
}
bool F_85 ( struct V_35 * V_36 )
{
struct V_32 * V_33 ;
struct V_46 * V_47 , * V_26 ;
F_45 ( V_77 ) ;
bool V_138 = false ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_28 ( V_36 ) -> V_44 ;
if ( ! V_33 || ! F_53 ( V_139 , & V_33 -> V_56 ) ||
F_40 ( V_101 , & V_33 -> V_56 ) )
goto V_140;
F_56 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_40 ( V_141 , & V_47 -> V_52 ) ) {
F_52 ( V_47 , & V_77 ) ;
V_138 = true ;
}
if ( ! V_138 )
goto V_140;
V_33 -> V_88 ++ ;
F_17 ( V_33 ) ;
F_6 ( & V_36 -> V_45 ) ;
F_46 ( & V_77 ) ;
return true ;
V_140:
F_6 ( & V_36 -> V_45 ) ;
return false ;
}
void F_86 ( struct V_35 * V_36 )
{
struct V_32 * V_33 ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_28 ( V_36 ) -> V_44 ;
V_33 -> V_88 -- ;
F_29 ( V_33 ) ;
F_6 ( & V_36 -> V_45 ) ;
}
void F_87 ( struct V_35 * V_36 , T_1 V_142 )
{
struct V_32 * V_33 ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_28 ( V_36 ) -> V_44 ;
if ( ( int ) ( V_142 - V_33 -> V_98 ) > 0 )
V_33 -> V_98 = V_142 ;
F_6 ( & V_36 -> V_45 ) ;
}
bool F_88 ( struct V_35 * V_36 , T_1 * V_142 )
{
struct V_85 * V_86 = F_28 ( V_36 ) ;
struct V_46 * V_47 ;
bool V_138 = false ;
F_5 ( & V_36 -> V_45 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_40 ( V_141 , & V_47 -> V_52 ) ) {
V_138 = true ;
break;
}
if ( ! V_138 ) {
struct V_32 * V_33 = V_86 -> V_44 ;
T_1 V_143 = F_68 ( V_33 -> V_95 . V_96 ) ;
* V_142 = V_143 + F_44 ( & V_33 -> V_102 ) ;
}
F_6 ( & V_36 -> V_45 ) ;
return V_138 ;
}
static T_5
F_89 ( struct V_63 * V_64 ,
struct V_63 * V_65 )
{
T_5 V_144 ;
V_144 = V_64 -> V_67 - V_65 -> V_67 ;
if ( V_144 )
return V_144 ;
V_144 = V_65 -> V_69 - V_64 -> V_69 ;
if ( V_144 )
return V_144 ;
return ( int ) ( V_64 -> V_74 == V_145 ) - ( int ) ( V_65 -> V_74 == V_145 ) ;
}
static void
F_90 ( struct V_32 * V_33 ,
struct V_46 * V_47 )
{
struct V_46 * V_146 ;
F_3 ( L_28 , V_5 ) ;
F_91 ( & V_33 -> V_40 -> V_45 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_89 ( & V_47 -> V_82 , & V_146 -> V_82 ) > 0 )
continue;
F_92 ( & V_47 -> V_48 , & V_146 -> V_48 ) ;
F_3 ( L_29
L_30
L_31 ,
V_5 , V_47 , V_47 -> V_82 . V_74 ,
V_47 -> V_82 . V_67 , V_47 -> V_82 . V_69 ,
V_146 , V_146 -> V_82 . V_74 , V_146 -> V_82 . V_67 ,
V_146 -> V_82 . V_69 ) ;
goto V_4;
}
F_92 ( & V_47 -> V_48 , & V_33 -> V_54 ) ;
F_3 ( L_29
L_32 ,
V_5 , V_47 , V_47 -> V_82 . V_74 ,
V_47 -> V_82 . V_67 , V_47 -> V_82 . V_69 ) ;
V_4:
F_17 ( V_33 ) ;
F_3 ( L_33 , V_5 ) ;
}
static struct V_32 *
F_93 ( struct V_35 * V_36 ,
struct V_109 * V_110 ,
T_2 V_37 )
{
struct V_32 * V_33 ;
V_33 = F_19 ( V_36 , V_37 ) ;
if ( ! V_33 )
return NULL ;
F_35 ( & V_33 -> V_34 , 1 ) ;
F_34 ( & V_33 -> V_43 ) ;
F_34 ( & V_33 -> V_54 ) ;
F_34 ( & V_33 -> V_147 ) ;
V_33 -> V_40 = V_36 ;
V_33 -> V_41 = F_94 ( V_110 -> V_148 -> V_11 -> V_149 ) ;
return V_33 ;
}
static struct V_32 *
F_95 ( struct V_35 * V_36 ,
struct V_109 * V_110 ,
T_2 V_37 )
{
struct V_85 * V_86 = F_28 ( V_36 ) ;
struct V_32 * V_91 = NULL ;
F_3 ( L_34 , V_5 , V_36 , V_86 -> V_44 ) ;
F_91 ( & V_36 -> V_45 ) ;
if ( V_86 -> V_44 ) {
if ( F_40 ( V_55 , & V_86 -> V_44 -> V_56 ) )
return NULL ;
else
return V_86 -> V_44 ;
}
F_6 ( & V_36 -> V_45 ) ;
V_91 = F_93 ( V_36 , V_110 , V_37 ) ;
F_5 ( & V_36 -> V_45 ) ;
if ( F_96 ( V_86 -> V_44 == NULL ) )
V_86 -> V_44 = V_91 ;
else
F_22 ( V_91 ) ;
return V_86 -> V_44 ;
}
static int
F_97 ( struct V_63 * V_150 ,
struct V_63 * V_111 )
{
struct V_63 V_151 ;
if ( ( V_111 -> V_74 == V_152 &&
V_150 -> V_74 != V_152 ) ||
! F_50 ( V_150 , V_111 ) )
return 0 ;
V_151 = * V_111 ;
V_151 . V_69 = 1 ;
return F_49 ( V_150 , & V_151 ) ;
}
static struct V_46 *
F_98 ( struct V_32 * V_33 ,
struct V_63 * V_111 )
{
struct V_46 * V_47 , * V_153 = NULL ;
F_3 ( L_28 , V_5 ) ;
F_91 ( & V_33 -> V_40 -> V_45 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_40 ( V_51 , & V_47 -> V_52 ) &&
F_97 ( & V_47 -> V_82 , V_111 ) ) {
V_153 = F_99 ( V_47 ) ;
break;
}
if ( V_47 -> V_82 . V_67 > V_111 -> V_67 )
break;
}
F_3 ( L_35 ,
V_5 , V_153 , V_153 ? F_44 ( & V_153 -> V_50 ) : 0 ) ;
return V_153 ;
}
struct V_46 *
F_100 ( struct V_35 * V_36 ,
struct V_109 * V_110 ,
T_6 V_154 ,
T_3 V_155 ,
enum V_156 V_74 ,
T_2 V_37 )
{
struct V_63 V_157 = {
. V_74 = V_74 ,
. V_67 = V_154 ,
. V_69 = V_155 ,
} ;
unsigned V_158 ;
struct V_85 * V_86 = F_28 ( V_36 ) ;
struct V_7 * V_12 = F_20 ( V_36 ) ;
struct V_17 * V_83 = V_12 -> V_17 ;
struct V_32 * V_33 ;
struct V_46 * V_47 = NULL ;
bool V_159 = false ;
if ( ! F_101 ( F_20 ( V_36 ) ) )
return NULL ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_95 ( V_36 , V_110 , V_37 ) ;
if ( V_33 == NULL ) {
F_3 ( L_36 , V_5 ) ;
goto V_160;
}
if ( F_40 ( V_101 , & V_33 -> V_56 ) ) {
F_3 ( L_37 , V_5 ) ;
goto V_160;
}
if ( F_40 ( F_81 ( V_74 ) , & V_86 -> V_44 -> V_56 ) )
goto V_160;
V_47 = F_98 ( V_33 , & V_157 ) ;
if ( V_47 )
goto V_160;
if ( F_71 ( V_33 , NULL , 0 ) )
goto V_160;
F_18 ( & V_33 -> V_102 ) ;
F_17 ( V_33 ) ;
if ( F_27 ( & V_33 -> V_54 ) )
V_159 = true ;
F_6 ( & V_36 -> V_45 ) ;
if ( V_159 ) {
F_5 ( & V_83 -> V_84 ) ;
F_26 ( ! F_27 ( & V_33 -> V_43 ) ) ;
F_92 ( & V_33 -> V_43 , & V_12 -> V_89 ) ;
F_6 ( & V_83 -> V_84 ) ;
}
V_158 = V_157 . V_67 & ~ V_161 ;
if ( V_158 ) {
V_157 . V_67 -= V_158 ;
V_157 . V_69 += V_158 ;
}
if ( V_157 . V_69 != V_62 )
V_157 . V_69 = F_102 ( V_157 . V_69 ) ;
V_47 = F_75 ( V_33 , V_110 , & V_157 , V_37 ) ;
if ( ! V_47 && V_159 ) {
F_5 ( & V_83 -> V_84 ) ;
F_41 ( & V_33 -> V_43 ) ;
F_6 ( & V_83 -> V_84 ) ;
}
F_103 ( & V_33 -> V_102 ) ;
F_31 ( V_33 ) ;
V_4:
F_3 ( L_38 , V_5 ,
V_86 -> V_44 ? V_86 -> V_44 -> V_56 : - 1 , V_47 ) ;
return V_47 ;
V_160:
F_6 ( & V_36 -> V_45 ) ;
goto V_4;
}
int
F_104 ( struct V_112 * V_113 )
{
struct V_32 * V_33 = F_28 ( V_113 -> args . V_35 ) -> V_44 ;
struct V_162 * V_163 = & V_113 -> V_163 ;
struct V_46 * V_47 ;
struct V_35 * V_36 = V_33 -> V_40 ;
int V_24 = 0 ;
V_47 = F_20 ( V_36 ) -> V_9 -> V_27 ( V_33 , V_163 , V_113 -> V_37 ) ;
if ( ! V_47 || F_105 ( V_47 ) ) {
if ( ! V_47 )
V_24 = - V_134 ;
else
V_24 = F_106 ( V_47 ) ;
F_3 ( L_39 ,
V_5 , V_24 ) ;
goto V_4;
}
F_5 ( & V_36 -> V_45 ) ;
if ( F_40 ( V_101 , & V_33 -> V_56 ) ) {
F_3 ( L_40 , V_5 ) ;
goto V_164;
}
if ( F_71 ( V_33 , & V_163 -> V_99 , 1 ) ) {
F_3 ( L_41 , V_5 ) ;
goto V_164;
}
F_33 ( V_33 , V_47 ) ;
V_47 -> V_82 = V_163 -> V_111 ;
* V_113 -> V_128 = F_99 ( V_47 ) ;
F_90 ( V_33 , V_47 ) ;
if ( V_163 -> V_165 ) {
F_37 ( V_141 , & V_47 -> V_52 ) ;
F_37 ( V_139 , & V_33 -> V_56 ) ;
}
F_67 ( V_33 , & V_163 -> V_99 , false ) ;
F_6 ( & V_36 -> V_45 ) ;
V_4:
return V_24 ;
V_164:
F_6 ( & V_36 -> V_45 ) ;
V_47 -> V_53 = V_33 ;
F_20 ( V_36 ) -> V_9 -> V_28 ( V_47 ) ;
goto V_4;
}
void
F_107 ( struct V_166 * V_167 , struct V_168 * V_169 )
{
F_26 ( V_167 -> V_170 != NULL ) ;
V_167 -> V_170 = F_100 ( V_167 -> V_171 ,
V_169 -> V_172 ,
F_108 ( V_169 ) ,
V_169 -> V_173 ,
V_145 ,
V_133 ) ;
if ( V_167 -> V_170 == NULL )
F_109 ( V_167 ) ;
}
void
F_110 ( struct V_166 * V_167 , struct V_168 * V_169 )
{
F_26 ( V_167 -> V_170 != NULL ) ;
V_167 -> V_170 = F_100 ( V_167 -> V_171 ,
V_169 -> V_172 ,
F_108 ( V_169 ) ,
V_169 -> V_173 ,
V_152 ,
V_174 ) ;
if ( V_167 -> V_170 == NULL )
F_111 ( V_167 ) ;
}
bool
F_112 ( struct V_166 * V_167 , struct V_35 * V_35 )
{
struct V_7 * V_12 = F_20 ( V_35 ) ;
struct V_1 * V_38 = V_12 -> V_9 ;
if ( V_38 == NULL )
return false ;
F_113 ( V_167 , V_35 , V_38 -> V_175 , V_12 -> V_176 , 0 ) ;
return true ;
}
bool
F_114 ( struct V_166 * V_167 , struct V_35 * V_35 , int V_177 )
{
struct V_7 * V_12 = F_20 ( V_35 ) ;
struct V_1 * V_38 = V_12 -> V_9 ;
if ( V_38 == NULL )
return false ;
F_113 ( V_167 , V_35 , V_38 -> V_178 , V_12 -> V_179 , V_177 ) ;
return true ;
}
bool
F_115 ( struct V_166 * V_167 , struct V_168 * V_180 ,
struct V_168 * V_169 )
{
if ( V_167 -> V_170 == NULL )
return F_116 ( V_167 , V_180 , V_169 ) ;
return F_108 ( V_169 ) < F_47 ( V_167 -> V_170 -> V_82 . V_67 ,
V_167 -> V_170 -> V_82 . V_69 ) ;
}
static int F_117 ( struct V_35 * V_35 , struct V_76 * V_181 )
{
struct V_166 V_167 ;
F_45 ( V_182 ) ;
F_118 ( & V_167 , V_35 , V_183 ) ;
while ( ! F_27 ( V_181 ) ) {
struct V_168 * V_169 = F_119 ( V_181 -> V_79 ) ;
F_120 ( V_169 ) ;
if ( ! F_121 ( & V_167 , V_169 ) )
F_122 ( V_169 , & V_182 ) ;
}
F_123 ( & V_167 ) ;
if ( ! F_27 ( & V_182 ) ) {
F_124 ( & V_182 , V_181 ) ;
return - V_184 ;
}
return 0 ;
}
void F_125 ( struct V_185 * V_186 )
{
if ( F_96 ( ! V_186 -> V_187 ) ) {
F_126 ( V_186 ) ;
V_186 -> V_188 -> V_189 ( & V_186 -> V_190 , V_186 ) ;
} else {
F_3 ( L_42 , V_186 -> V_187 ) ;
if ( F_20 ( V_186 -> V_35 ) -> V_9 -> V_132 &
V_191 ) {
F_127 ( V_131 ,
& F_28 ( V_186 -> V_35 ) -> V_132 ) ;
F_128 ( V_186 -> V_35 ) ;
}
V_186 -> V_190 . V_192 = F_117 ( V_186 -> V_35 , & V_186 -> V_115 ) ;
}
F_43 ( V_186 -> V_47 ) ;
V_186 -> V_188 -> V_193 ( V_186 ) ;
}
static void
F_129 ( struct V_166 * V_194 ,
struct V_185 * V_186 )
{
F_130 ( & V_186 -> V_115 , & V_194 -> V_195 ) ;
if ( V_186 -> V_169 && F_27 ( & V_186 -> V_169 -> V_196 ) )
F_122 ( V_186 -> V_169 , & V_194 -> V_195 ) ;
F_111 ( V_194 ) ;
V_194 -> V_197 = 1 ;
F_43 ( V_186 -> V_47 ) ;
F_131 ( V_186 ) ;
}
static enum V_198
F_132 ( struct V_185 * V_199 ,
const struct V_200 * V_201 ,
struct V_46 * V_47 ,
int V_202 )
{
struct V_35 * V_35 = V_199 -> V_35 ;
enum V_198 V_203 ;
struct V_7 * V_8 = F_20 ( V_35 ) ;
V_199 -> V_188 = V_201 ;
V_199 -> V_47 = F_99 ( V_47 ) ;
F_3 ( L_43 , V_5 ,
V_35 -> V_90 , V_199 -> args . V_155 , V_199 -> args . V_67 , V_202 ) ;
V_203 = V_8 -> V_9 -> V_204 ( V_199 , V_202 ) ;
if ( V_203 == V_205 ) {
F_43 ( V_199 -> V_47 ) ;
V_199 -> V_47 = NULL ;
} else
F_133 ( V_35 , V_206 ) ;
F_3 ( L_44 , V_5 , V_203 ) ;
return V_203 ;
}
static void
F_134 ( struct V_166 * V_194 , struct V_76 * V_181 , int V_202 )
{
struct V_185 * V_186 ;
const struct V_200 * V_201 = V_194 -> V_207 ;
struct V_46 * V_47 = V_194 -> V_170 ;
V_194 -> V_170 = NULL ;
while ( ! F_27 ( V_181 ) ) {
enum V_198 V_203 ;
V_186 = F_66 ( V_181 -> V_79 , struct V_185 , V_208 ) ;
F_41 ( & V_186 -> V_208 ) ;
V_203 = F_132 ( V_186 , V_201 , V_47 , V_202 ) ;
if ( V_203 == V_205 )
F_129 ( V_194 , V_186 ) ;
}
F_43 ( V_47 ) ;
}
int
F_135 ( struct V_166 * V_194 )
{
F_45 ( V_181 ) ;
int V_153 ;
V_153 = F_136 ( V_194 , & V_181 ) ;
if ( V_153 != 0 ) {
F_43 ( V_194 -> V_170 ) ;
V_194 -> V_170 = NULL ;
return V_153 ;
}
F_134 ( V_194 , & V_181 , V_194 -> V_209 ) ;
return 0 ;
}
static void F_137 ( struct V_210 * V_186 )
{
struct V_166 V_167 ;
F_43 ( V_186 -> V_47 ) ;
V_186 -> V_47 = NULL ;
F_3 ( L_42 , V_186 -> V_187 ) ;
if ( F_20 ( V_186 -> V_35 ) -> V_9 -> V_132 &
V_191 )
F_128 ( V_186 -> V_35 ) ;
F_138 ( & V_167 , V_186 -> V_35 ) ;
while ( ! F_27 ( & V_186 -> V_115 ) ) {
struct V_168 * V_169 = F_119 ( V_186 -> V_115 . V_79 ) ;
F_120 ( V_169 ) ;
F_121 ( & V_167 , V_169 ) ;
}
F_123 ( & V_167 ) ;
}
void F_139 ( struct V_210 * V_186 )
{
if ( F_96 ( ! V_186 -> V_187 ) ) {
F_140 ( V_186 ) ;
V_186 -> V_188 -> V_189 ( & V_186 -> V_190 , V_186 ) ;
} else
F_137 ( V_186 ) ;
F_43 ( V_186 -> V_47 ) ;
V_186 -> V_188 -> V_193 ( V_186 ) ;
}
static void
F_141 ( struct V_166 * V_194 ,
struct V_210 * V_186 )
{
F_130 ( & V_186 -> V_115 , & V_194 -> V_195 ) ;
if ( V_186 -> V_169 && F_27 ( & V_186 -> V_169 -> V_196 ) )
F_122 ( V_186 -> V_169 , & V_194 -> V_195 ) ;
F_109 ( V_194 ) ;
V_194 -> V_197 = 1 ;
F_142 ( V_186 ) ;
}
static enum V_198
F_143 ( struct V_210 * V_211 ,
const struct V_200 * V_201 ,
struct V_46 * V_47 )
{
struct V_35 * V_35 = V_211 -> V_35 ;
struct V_7 * V_8 = F_20 ( V_35 ) ;
enum V_198 V_203 ;
V_211 -> V_188 = V_201 ;
V_211 -> V_47 = F_99 ( V_47 ) ;
F_3 ( L_45 ,
V_5 , V_35 -> V_90 , V_211 -> args . V_155 , V_211 -> args . V_67 ) ;
V_203 = V_8 -> V_9 -> V_212 ( V_211 ) ;
if ( V_203 == V_205 ) {
F_43 ( V_211 -> V_47 ) ;
V_211 -> V_47 = NULL ;
} else {
F_133 ( V_35 , V_213 ) ;
}
F_3 ( L_44 , V_5 , V_203 ) ;
return V_203 ;
}
static void
F_144 ( struct V_166 * V_194 , struct V_76 * V_181 )
{
struct V_210 * V_186 ;
const struct V_200 * V_201 = V_194 -> V_207 ;
struct V_46 * V_47 = V_194 -> V_170 ;
V_194 -> V_170 = NULL ;
while ( ! F_27 ( V_181 ) ) {
enum V_198 V_203 ;
V_186 = F_66 ( V_181 -> V_79 , struct V_210 , V_208 ) ;
F_41 ( & V_186 -> V_208 ) ;
V_203 = F_143 ( V_186 , V_201 , V_47 ) ;
if ( V_203 == V_205 )
F_141 ( V_194 , V_186 ) ;
}
F_43 ( V_47 ) ;
}
int
F_145 ( struct V_166 * V_194 )
{
F_45 ( V_181 ) ;
int V_153 ;
V_153 = F_146 ( V_194 , & V_181 ) ;
if ( V_153 != 0 ) {
F_43 ( V_194 -> V_170 ) ;
V_194 -> V_170 = NULL ;
return V_153 ;
}
F_144 ( V_194 , & V_181 ) ;
return 0 ;
}
static void F_147 ( struct V_35 * V_35 , struct V_76 * V_214 )
{
struct V_46 * V_47 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_47 -> V_82 . V_74 == V_152 &&
F_40 ( V_215 , & V_47 -> V_52 ) )
F_14 ( & V_47 -> V_49 , V_214 ) ;
}
}
void F_148 ( struct V_46 * V_47 )
{
if ( V_47 -> V_82 . V_74 == V_152 ) {
F_3 ( L_46 , V_5 ) ;
F_37 ( F_81 ( V_152 ) , & V_47 -> V_53 -> V_56 ) ;
} else {
F_3 ( L_47 , V_5 ) ;
F_37 ( F_81 ( V_145 ) , & V_47 -> V_53 -> V_56 ) ;
}
}
void
F_126 ( struct V_185 * V_199 )
{
struct V_85 * V_86 = F_28 ( V_199 -> V_35 ) ;
T_6 V_216 = V_199 -> V_217 + V_199 -> V_163 . V_155 ;
bool V_218 = false ;
F_5 ( & V_86 -> V_87 . V_45 ) ;
if ( ! F_55 ( V_131 , & V_86 -> V_132 ) ) {
V_218 = true ;
F_3 ( L_48 ,
V_5 , V_199 -> V_35 -> V_90 ) ;
}
if ( ! F_55 ( V_215 , & V_199 -> V_47 -> V_52 ) ) {
F_99 ( V_199 -> V_47 ) ;
}
if ( V_216 > V_86 -> V_44 -> V_219 )
V_86 -> V_44 -> V_219 = V_216 ;
F_6 ( & V_86 -> V_87 . V_45 ) ;
F_3 ( L_49 ,
V_5 , V_199 -> V_47 , V_86 -> V_44 -> V_219 ) ;
if ( V_218 )
F_149 ( V_199 -> V_35 ) ;
}
void F_150 ( struct V_220 * V_186 )
{
struct V_7 * V_8 = F_20 ( V_186 -> args . V_35 ) ;
if ( V_8 -> V_9 -> V_221 )
V_8 -> V_9 -> V_221 ( V_186 ) ;
}
int
F_151 ( struct V_35 * V_35 , bool V_222 )
{
struct V_220 * V_186 ;
struct V_85 * V_86 = F_28 ( V_35 ) ;
T_6 V_216 ;
int V_24 = 0 ;
F_3 ( L_50 , V_5 , V_35 -> V_90 ) ;
if ( ! F_40 ( V_131 , & V_86 -> V_132 ) )
return 0 ;
V_186 = F_21 ( sizeof( * V_186 ) , V_174 ) ;
if ( ! V_186 ) {
V_24 = - V_134 ;
goto V_4;
}
if ( ! F_40 ( V_131 , & V_86 -> V_132 ) )
goto V_223;
if ( F_55 ( V_224 , & V_86 -> V_132 ) ) {
if ( ! V_222 ) {
V_24 = - V_106 ;
goto V_223;
}
V_24 = F_152 ( & V_86 -> V_132 , V_224 ,
V_225 , V_226 ) ;
if ( V_24 )
goto V_223;
}
F_34 ( & V_186 -> V_227 ) ;
F_5 ( & V_35 -> V_45 ) ;
if ( ! F_53 ( V_131 , & V_86 -> V_132 ) ) {
F_127 ( V_224 , & V_86 -> V_132 ) ;
F_6 ( & V_35 -> V_45 ) ;
F_153 ( & V_86 -> V_132 , V_224 ) ;
goto V_223;
}
F_147 ( V_35 , & V_186 -> V_227 ) ;
V_216 = V_86 -> V_44 -> V_219 ;
V_86 -> V_44 -> V_219 = 0 ;
F_69 ( & V_186 -> args . V_99 , & V_86 -> V_44 -> V_95 ) ;
F_6 ( & V_35 -> V_45 ) ;
V_186 -> args . V_35 = V_35 ;
V_186 -> V_228 = F_94 ( V_86 -> V_44 -> V_41 ) ;
F_154 ( & V_186 -> V_229 ) ;
V_186 -> args . V_230 = F_20 ( V_35 ) -> V_231 ;
V_186 -> V_163 . V_229 = & V_186 -> V_229 ;
V_186 -> args . V_232 = V_216 - 1 ;
V_186 -> V_163 . V_12 = F_20 ( V_35 ) ;
V_24 = F_155 ( V_186 , V_222 ) ;
V_4:
if ( V_24 )
F_149 ( V_35 ) ;
F_3 ( L_51 , V_5 , V_24 ) ;
return V_24 ;
V_223:
F_24 ( V_186 ) ;
goto V_4;
}
