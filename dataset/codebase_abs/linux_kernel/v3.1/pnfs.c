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
F_10 ( V_21 L_2 , V_5 ,
V_2 , V_12 -> V_17 -> V_18 ) ;
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
F_10 ( V_21 L_6 ,
V_5 , V_2 ) ;
F_8 ( V_15 -> V_11 ) ;
goto V_16;
}
F_3 ( L_7 , V_5 , V_2 ) ;
return;
V_16:
F_3 ( L_8 , V_5 ) ;
V_12 -> V_9 = NULL ;
}
int
F_13 ( struct V_1 * V_15 )
{
int V_24 = - V_25 ;
struct V_1 * V_26 ;
if ( V_15 -> V_2 == 0 ) {
F_10 ( V_21 L_9 , V_5 ) ;
return V_24 ;
}
if ( ! V_15 -> V_27 || ! V_15 -> V_28 ) {
F_10 ( V_21 L_10
L_11 , V_5 ) ;
return V_24 ;
}
F_5 ( & V_6 ) ;
V_26 = F_1 ( V_15 -> V_2 ) ;
if ( ! V_26 ) {
F_14 ( & V_15 -> V_29 , & V_30 ) ;
V_24 = 0 ;
F_3 ( L_12 , V_5 , V_15 -> V_2 ,
V_15 -> V_31 ) ;
} else {
F_10 ( V_21 L_13 ,
V_5 , V_15 -> V_2 ) ;
}
F_6 ( & V_6 ) ;
return V_24 ;
}
void
F_15 ( struct V_1 * V_15 )
{
F_3 ( L_14 , V_5 , V_15 -> V_2 ) ;
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
F_3 ( L_15 , V_5 , V_33 ) ;
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
F_3 ( L_16 , V_5 , V_47 ,
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
F_3 ( L_17 , V_5 , V_47 ,
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
F_3 ( L_18 , V_5 , V_33 ) ;
if ( F_27 ( & V_33 -> V_54 ) ) {
if ( ! F_55 ( V_55 , & V_33 -> V_56 ) )
F_29 ( V_33 ) ;
return 0 ;
}
F_56 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_73 ||
F_51 ( & V_47 -> V_82 , V_73 ) ) {
F_3 ( L_19
L_20 , V_5 ,
V_47 , V_47 -> V_82 . V_74 , V_47 -> V_82 . V_67 ,
V_47 -> V_82 . V_69 ) ;
V_80 ++ ;
V_81 += F_52 ( V_47 , V_77 ) ;
}
F_3 ( L_21 , V_5 , V_80 - V_81 ) ;
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
F_3 ( L_22 , V_5 ,
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
V_93 = F_68 ( V_33 -> V_95 . V_96 . V_97 ) ;
V_94 = F_68 ( V_91 -> V_96 . V_97 ) ;
if ( ( int ) ( V_94 - V_93 ) > 0 ) {
memcpy ( & V_33 -> V_95 , & V_91 -> V_96 , sizeof( V_91 -> V_96 ) ) ;
if ( V_92 ) {
T_1 V_98 = F_68 ( V_91 -> V_96 . V_97 ) ;
if ( ( int ) ( V_98 - V_33 -> V_99 ) )
V_33 -> V_99 = V_98 ;
} else {
if ( F_69 ( ( V_94 - V_33 -> V_99 ) > ( 3 << 29 ) ) )
V_33 -> V_99 = V_94 - ( 1 << 30 ) ;
}
}
}
static bool
F_70 ( struct V_32 * V_33 , T_4 * V_96 ,
int V_100 )
{
if ( ( V_96 ) &&
( int ) ( V_33 -> V_99 - F_68 ( V_96 -> V_96 . V_97 ) ) >= 0 )
return true ;
return V_33 -> V_88 ||
F_40 ( V_55 , & V_33 -> V_56 ) ||
F_40 ( V_101 , & V_33 -> V_56 ) ||
( F_27 ( & V_33 -> V_54 ) &&
( F_44 ( & V_33 -> V_102 ) > V_100 ) ) ;
}
int
F_71 ( T_4 * V_103 , struct V_32 * V_33 ,
struct V_104 * V_105 )
{
int V_24 = 0 ;
F_3 ( L_23 , V_5 ) ;
F_5 ( & V_33 -> V_40 -> V_45 ) ;
if ( F_70 ( V_33 , NULL , 1 ) ) {
V_24 = - V_106 ;
} else if ( F_27 ( & V_33 -> V_54 ) ) {
int V_107 ;
do {
V_107 = F_72 ( & V_105 -> V_108 ) ;
memcpy ( V_103 -> V_109 , V_105 -> V_96 . V_109 ,
sizeof( V_105 -> V_96 . V_109 ) ) ;
} while ( F_73 ( & V_105 -> V_108 , V_107 ) );
} else
memcpy ( V_103 -> V_109 , V_33 -> V_95 . V_109 , sizeof( V_33 -> V_95 . V_109 ) ) ;
F_6 ( & V_33 -> V_40 -> V_45 ) ;
F_3 ( L_24 , V_5 ) ;
return V_24 ;
}
static struct V_46 *
F_74 ( struct V_32 * V_33 ,
struct V_110 * V_111 ,
struct V_63 * V_112 ,
T_2 V_37 )
{
struct V_35 * V_36 = V_33 -> V_40 ;
struct V_7 * V_12 = F_20 ( V_36 ) ;
struct V_113 * V_114 ;
struct V_46 * V_47 = NULL ;
struct V_115 * * V_116 = NULL ;
int V_117 ;
T_1 V_118 , V_119 ;
F_3 ( L_23 , V_5 ) ;
F_26 ( V_111 == NULL ) ;
V_114 = F_21 ( sizeof( * V_114 ) , V_37 ) ;
if ( V_114 == NULL )
return NULL ;
V_118 = V_12 -> V_17 -> V_120 -> V_121 . V_118 ;
V_119 = V_118 >> V_122 ;
V_116 = F_21 ( V_119 * sizeof( struct V_115 * ) , V_37 ) ;
if ( ! V_116 )
goto V_123;
for ( V_117 = 0 ; V_117 < V_119 ; V_117 ++ ) {
V_116 [ V_117 ] = F_75 ( V_37 ) ;
if ( ! V_116 [ V_117 ] )
goto V_123;
}
V_114 -> args . V_124 = V_125 ;
if ( V_114 -> args . V_124 > V_112 -> V_69 )
V_114 -> args . V_124 = V_112 -> V_69 ;
V_114 -> args . V_126 = V_127 ;
V_114 -> args . V_112 = * V_112 ;
V_114 -> args . type = V_12 -> V_9 -> V_2 ;
V_114 -> args . V_35 = V_36 ;
V_114 -> args . V_111 = F_76 ( V_111 ) ;
V_114 -> args . V_44 . V_116 = V_116 ;
V_114 -> args . V_44 . V_128 = V_119 * V_129 ;
V_114 -> V_130 = & V_47 ;
V_114 -> V_37 = V_37 ;
F_77 ( V_114 ) ;
if ( ! V_47 ) {
F_37 ( F_78 ( V_112 -> V_74 ) , & V_33 -> V_56 ) ;
}
for ( V_117 = 0 ; V_117 < V_119 ; V_117 ++ )
F_79 ( V_116 [ V_117 ] ) ;
F_24 ( V_116 ) ;
return V_47 ;
V_123:
if ( V_116 ) {
for ( V_117 = 0 ; V_117 < V_119 ; V_117 ++ ) {
if ( ! V_116 [ V_117 ] )
break;
F_79 ( V_116 [ V_117 ] ) ;
}
F_24 ( V_116 ) ;
}
F_24 ( V_114 ) ;
return NULL ;
}
int
F_80 ( struct V_35 * V_36 )
{
struct V_32 * V_33 = NULL ;
struct V_85 * V_86 = F_28 ( V_36 ) ;
F_45 ( V_77 ) ;
struct V_131 * V_132 ;
T_4 V_96 ;
int V_24 = 0 ;
F_3 ( L_23 , V_5 ) ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = V_86 -> V_44 ;
if ( ! V_33 ) {
F_6 ( & V_36 -> V_45 ) ;
F_3 ( L_25 , V_5 ) ;
return V_24 ;
}
V_96 = V_86 -> V_44 -> V_95 ;
F_17 ( V_33 ) ;
F_54 ( V_33 , & V_77 , NULL ) ;
V_33 -> V_88 ++ ;
F_6 ( & V_36 -> V_45 ) ;
F_46 ( & V_77 ) ;
F_39 ( F_40 ( V_133 , & V_86 -> V_134 ) ) ;
V_132 = F_21 ( sizeof( * V_132 ) , V_135 ) ;
if ( F_69 ( V_132 == NULL ) ) {
V_24 = - V_136 ;
F_37 ( V_137 , & V_33 -> V_56 ) ;
F_37 ( V_138 , & V_33 -> V_56 ) ;
F_31 ( V_33 ) ;
goto V_4;
}
V_132 -> args . V_96 = V_96 ;
V_132 -> args . V_139 = F_20 ( V_36 ) -> V_9 -> V_2 ;
V_132 -> args . V_35 = V_36 ;
V_132 -> args . V_44 = V_33 ;
V_132 -> V_83 = F_20 ( V_36 ) -> V_17 ;
V_24 = F_81 ( V_132 ) ;
V_4:
F_3 ( L_26 , V_5 , V_24 ) ;
return V_24 ;
}
bool F_82 ( struct V_35 * V_36 )
{
struct V_32 * V_33 ;
struct V_46 * V_47 , * V_26 ;
F_45 ( V_77 ) ;
bool V_140 = false ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_28 ( V_36 ) -> V_44 ;
if ( ! V_33 || ! F_53 ( V_141 , & V_33 -> V_56 ) ||
F_40 ( V_101 , & V_33 -> V_56 ) )
goto V_142;
F_56 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_40 ( V_143 , & V_47 -> V_52 ) ) {
F_52 ( V_47 , & V_77 ) ;
V_140 = true ;
}
if ( ! V_140 )
goto V_142;
V_33 -> V_88 ++ ;
F_17 ( V_33 ) ;
F_6 ( & V_36 -> V_45 ) ;
F_46 ( & V_77 ) ;
return true ;
V_142:
F_6 ( & V_36 -> V_45 ) ;
return false ;
}
void F_83 ( struct V_35 * V_36 )
{
struct V_32 * V_33 ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_28 ( V_36 ) -> V_44 ;
V_33 -> V_88 -- ;
F_29 ( V_33 ) ;
F_6 ( & V_36 -> V_45 ) ;
}
void F_84 ( struct V_35 * V_36 , T_1 V_144 )
{
struct V_32 * V_33 ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_28 ( V_36 ) -> V_44 ;
if ( ( int ) ( V_144 - V_33 -> V_99 ) > 0 )
V_33 -> V_99 = V_144 ;
F_6 ( & V_36 -> V_45 ) ;
}
bool F_85 ( struct V_35 * V_36 , T_1 * V_144 )
{
struct V_85 * V_86 = F_28 ( V_36 ) ;
struct V_46 * V_47 ;
bool V_140 = false ;
F_5 ( & V_36 -> V_45 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_40 ( V_143 , & V_47 -> V_52 ) ) {
V_140 = true ;
break;
}
if ( ! V_140 ) {
struct V_32 * V_33 = V_86 -> V_44 ;
T_1 V_145 = F_68 ( V_33 -> V_95 . V_96 . V_97 ) ;
* V_144 = V_145 + F_44 ( & V_33 -> V_102 ) ;
}
F_6 ( & V_36 -> V_45 ) ;
return V_140 ;
}
static T_5
F_86 ( struct V_63 * V_64 ,
struct V_63 * V_65 )
{
T_5 V_146 ;
V_146 = V_64 -> V_67 - V_65 -> V_67 ;
if ( V_146 )
return V_146 ;
V_146 = V_65 -> V_69 - V_64 -> V_69 ;
if ( V_146 )
return V_146 ;
return ( int ) ( V_64 -> V_74 == V_147 ) - ( int ) ( V_65 -> V_74 == V_147 ) ;
}
static void
F_87 ( struct V_32 * V_33 ,
struct V_46 * V_47 )
{
struct V_46 * V_148 ;
F_3 ( L_27 , V_5 ) ;
F_88 ( & V_33 -> V_40 -> V_45 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_86 ( & V_47 -> V_82 , & V_148 -> V_82 ) > 0 )
continue;
F_89 ( & V_47 -> V_48 , & V_148 -> V_48 ) ;
F_3 ( L_28
L_29
L_30 ,
V_5 , V_47 , V_47 -> V_82 . V_74 ,
V_47 -> V_82 . V_67 , V_47 -> V_82 . V_69 ,
V_148 , V_148 -> V_82 . V_74 , V_148 -> V_82 . V_67 ,
V_148 -> V_82 . V_69 ) ;
goto V_4;
}
F_89 ( & V_47 -> V_48 , & V_33 -> V_54 ) ;
F_3 ( L_28
L_31 ,
V_5 , V_47 , V_47 -> V_82 . V_74 ,
V_47 -> V_82 . V_67 , V_47 -> V_82 . V_69 ) ;
V_4:
F_17 ( V_33 ) ;
F_3 ( L_32 , V_5 ) ;
}
static struct V_32 *
F_90 ( struct V_35 * V_36 ,
struct V_110 * V_111 ,
T_2 V_37 )
{
struct V_32 * V_33 ;
V_33 = F_19 ( V_36 , V_37 ) ;
if ( ! V_33 )
return NULL ;
F_35 ( & V_33 -> V_34 , 1 ) ;
F_34 ( & V_33 -> V_43 ) ;
F_34 ( & V_33 -> V_54 ) ;
F_34 ( & V_33 -> V_149 ) ;
V_33 -> V_40 = V_36 ;
V_33 -> V_41 = F_91 ( V_111 -> V_150 -> V_11 -> V_151 ) ;
return V_33 ;
}
static struct V_32 *
F_92 ( struct V_35 * V_36 ,
struct V_110 * V_111 ,
T_2 V_37 )
{
struct V_85 * V_86 = F_28 ( V_36 ) ;
struct V_32 * V_91 = NULL ;
F_3 ( L_33 , V_5 , V_36 , V_86 -> V_44 ) ;
F_88 ( & V_36 -> V_45 ) ;
if ( V_86 -> V_44 ) {
if ( F_40 ( V_55 , & V_86 -> V_44 -> V_56 ) )
return NULL ;
else
return V_86 -> V_44 ;
}
F_6 ( & V_36 -> V_45 ) ;
V_91 = F_90 ( V_36 , V_111 , V_37 ) ;
F_5 ( & V_36 -> V_45 ) ;
if ( F_93 ( V_86 -> V_44 == NULL ) )
V_86 -> V_44 = V_91 ;
else
F_22 ( V_91 ) ;
return V_86 -> V_44 ;
}
static int
F_94 ( struct V_63 * V_152 ,
struct V_63 * V_112 )
{
struct V_63 V_153 ;
if ( ( V_112 -> V_74 == V_154 &&
V_152 -> V_74 != V_154 ) ||
! F_50 ( V_152 , V_112 ) )
return 0 ;
V_153 = * V_112 ;
V_153 . V_69 = 1 ;
return F_49 ( V_152 , & V_153 ) ;
}
static struct V_46 *
F_95 ( struct V_32 * V_33 ,
struct V_63 * V_112 )
{
struct V_46 * V_47 , * V_155 = NULL ;
F_3 ( L_27 , V_5 ) ;
F_88 ( & V_33 -> V_40 -> V_45 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_40 ( V_51 , & V_47 -> V_52 ) &&
F_94 ( & V_47 -> V_82 , V_112 ) ) {
V_155 = F_96 ( V_47 ) ;
break;
}
if ( V_47 -> V_82 . V_67 > V_112 -> V_67 )
break;
}
F_3 ( L_34 ,
V_5 , V_155 , V_155 ? F_44 ( & V_155 -> V_50 ) : 0 ) ;
return V_155 ;
}
struct V_46 *
F_97 ( struct V_35 * V_36 ,
struct V_110 * V_111 ,
T_6 V_156 ,
T_3 V_157 ,
enum V_158 V_74 ,
T_2 V_37 )
{
struct V_63 V_159 = {
. V_74 = V_74 ,
. V_67 = V_156 ,
. V_69 = V_157 ,
} ;
unsigned V_160 ;
struct V_85 * V_86 = F_28 ( V_36 ) ;
struct V_7 * V_12 = F_20 ( V_36 ) ;
struct V_17 * V_83 = V_12 -> V_17 ;
struct V_32 * V_33 ;
struct V_46 * V_47 = NULL ;
bool V_161 = false ;
if ( ! F_98 ( F_20 ( V_36 ) ) )
return NULL ;
F_5 ( & V_36 -> V_45 ) ;
V_33 = F_92 ( V_36 , V_111 , V_37 ) ;
if ( V_33 == NULL ) {
F_3 ( L_35 , V_5 ) ;
goto V_162;
}
if ( F_40 ( V_163 , & V_83 -> V_164 ) ||
F_40 ( V_101 , & V_33 -> V_56 ) ) {
F_3 ( L_36 , V_5 ) ;
goto V_162;
}
if ( F_40 ( F_78 ( V_74 ) , & V_86 -> V_44 -> V_56 ) )
goto V_162;
V_47 = F_95 ( V_33 , & V_159 ) ;
if ( V_47 )
goto V_162;
if ( F_70 ( V_33 , NULL , 0 ) )
goto V_162;
F_18 ( & V_33 -> V_102 ) ;
F_17 ( V_33 ) ;
if ( F_27 ( & V_33 -> V_54 ) )
V_161 = true ;
F_6 ( & V_36 -> V_45 ) ;
if ( V_161 ) {
F_5 ( & V_83 -> V_84 ) ;
F_26 ( ! F_27 ( & V_33 -> V_43 ) ) ;
F_89 ( & V_33 -> V_43 , & V_12 -> V_89 ) ;
F_6 ( & V_83 -> V_84 ) ;
}
V_160 = V_159 . V_67 & ~ V_165 ;
if ( V_160 ) {
V_159 . V_67 -= V_160 ;
V_159 . V_69 += V_160 ;
}
if ( V_159 . V_69 != V_62 )
V_159 . V_69 = F_99 ( V_159 . V_69 ) ;
V_47 = F_74 ( V_33 , V_111 , & V_159 , V_37 ) ;
if ( ! V_47 && V_161 ) {
F_5 ( & V_83 -> V_84 ) ;
F_41 ( & V_33 -> V_43 ) ;
F_6 ( & V_83 -> V_84 ) ;
}
F_100 ( & V_33 -> V_102 ) ;
F_31 ( V_33 ) ;
V_4:
F_3 ( L_37 , V_5 ,
V_86 -> V_44 ? V_86 -> V_44 -> V_56 : - 1 , V_47 ) ;
return V_47 ;
V_162:
F_6 ( & V_36 -> V_45 ) ;
goto V_4;
}
int
F_101 ( struct V_113 * V_114 )
{
struct V_32 * V_33 = F_28 ( V_114 -> args . V_35 ) -> V_44 ;
struct V_166 * V_167 = & V_114 -> V_167 ;
struct V_46 * V_47 ;
struct V_35 * V_36 = V_33 -> V_40 ;
struct V_17 * V_83 = F_20 ( V_36 ) -> V_17 ;
int V_24 = 0 ;
V_47 = F_20 ( V_36 ) -> V_9 -> V_27 ( V_33 , V_167 , V_114 -> V_37 ) ;
if ( ! V_47 || F_102 ( V_47 ) ) {
if ( ! V_47 )
V_24 = - V_136 ;
else
V_24 = F_103 ( V_47 ) ;
F_3 ( L_38 ,
V_5 , V_24 ) ;
goto V_4;
}
F_5 ( & V_36 -> V_45 ) ;
if ( F_40 ( V_163 , & V_83 -> V_164 ) ||
F_40 ( V_101 , & V_33 -> V_56 ) ) {
F_3 ( L_39 , V_5 ) ;
goto V_168;
}
if ( F_70 ( V_33 , & V_167 -> V_96 , 1 ) ) {
F_3 ( L_40 , V_5 ) ;
goto V_168;
}
F_33 ( V_33 , V_47 ) ;
V_47 -> V_82 = V_167 -> V_112 ;
* V_114 -> V_130 = F_96 ( V_47 ) ;
F_87 ( V_33 , V_47 ) ;
if ( V_167 -> V_169 ) {
F_37 ( V_143 , & V_47 -> V_52 ) ;
F_37 ( V_141 , & V_33 -> V_56 ) ;
}
F_67 ( V_33 , & V_167 -> V_96 , false ) ;
F_6 ( & V_36 -> V_45 ) ;
V_4:
return V_24 ;
V_168:
F_6 ( & V_36 -> V_45 ) ;
V_47 -> V_53 = V_33 ;
F_20 ( V_36 ) -> V_9 -> V_28 ( V_47 ) ;
goto V_4;
}
void
F_104 ( struct V_170 * V_171 , struct V_172 * V_173 )
{
F_26 ( V_171 -> V_174 != NULL ) ;
V_171 -> V_174 = F_97 ( V_171 -> V_175 ,
V_173 -> V_176 ,
F_105 ( V_173 ) ,
V_173 -> V_177 ,
V_147 ,
V_135 ) ;
if ( V_171 -> V_174 == NULL )
F_106 ( V_171 ) ;
}
void
F_107 ( struct V_170 * V_171 , struct V_172 * V_173 )
{
F_26 ( V_171 -> V_174 != NULL ) ;
V_171 -> V_174 = F_97 ( V_171 -> V_175 ,
V_173 -> V_176 ,
F_105 ( V_173 ) ,
V_173 -> V_177 ,
V_154 ,
V_178 ) ;
if ( V_171 -> V_174 == NULL )
F_108 ( V_171 ) ;
}
bool
F_109 ( struct V_170 * V_171 , struct V_35 * V_35 )
{
struct V_7 * V_12 = F_20 ( V_35 ) ;
struct V_1 * V_38 = V_12 -> V_9 ;
if ( V_38 == NULL )
return false ;
F_110 ( V_171 , V_35 , V_38 -> V_179 , V_12 -> V_180 , 0 ) ;
return true ;
}
bool
F_111 ( struct V_170 * V_171 , struct V_35 * V_35 , int V_181 )
{
struct V_7 * V_12 = F_20 ( V_35 ) ;
struct V_1 * V_38 = V_12 -> V_9 ;
if ( V_38 == NULL )
return false ;
F_110 ( V_171 , V_35 , V_38 -> V_182 , V_12 -> V_183 , V_181 ) ;
return true ;
}
bool
F_112 ( struct V_170 * V_171 , struct V_172 * V_184 ,
struct V_172 * V_173 )
{
if ( V_171 -> V_174 == NULL )
return F_113 ( V_171 , V_184 , V_173 ) ;
return F_105 ( V_173 ) < F_47 ( V_171 -> V_174 -> V_82 . V_67 ,
V_171 -> V_174 -> V_82 . V_69 ) ;
}
int
F_114 ( struct V_185 * V_109 )
{
int V_24 ;
if ( ! V_109 -> V_186 ) {
F_115 ( V_109 ) ;
V_109 -> V_187 -> V_188 ( & V_109 -> V_189 , V_109 ) ;
V_109 -> V_187 -> V_190 ( V_109 ) ;
return 0 ;
}
F_3 ( L_41 , V_5 ,
V_109 -> V_186 ) ;
V_24 = F_116 ( V_109 , F_117 ( V_109 -> V_35 ) ,
V_109 -> V_187 , V_191 ) ;
return V_24 ? : - V_106 ;
}
static void
F_118 ( struct V_170 * V_192 ,
struct V_185 * V_109 )
{
F_119 ( & V_109 -> V_116 , & V_192 -> V_193 ) ;
if ( V_109 -> V_173 && F_27 ( & V_109 -> V_173 -> V_194 ) )
F_120 ( V_109 -> V_173 , & V_192 -> V_193 ) ;
F_108 ( V_192 ) ;
V_192 -> V_195 = 1 ;
F_121 ( V_109 ) ;
}
static enum V_196
F_122 ( struct V_185 * V_197 ,
const struct V_198 * V_199 ,
struct V_46 * V_47 ,
int V_200 )
{
struct V_35 * V_35 = V_197 -> V_35 ;
enum V_196 V_201 ;
struct V_7 * V_8 = F_20 ( V_35 ) ;
V_197 -> V_187 = V_199 ;
V_197 -> V_47 = F_96 ( V_47 ) ;
F_3 ( L_42 , V_5 ,
V_35 -> V_90 , V_197 -> args . V_157 , V_197 -> args . V_67 , V_200 ) ;
V_201 = V_8 -> V_9 -> V_202 ( V_197 , V_200 ) ;
if ( V_201 == V_203 ) {
F_43 ( V_197 -> V_47 ) ;
V_197 -> V_47 = NULL ;
} else
F_123 ( V_35 , V_204 ) ;
F_3 ( L_43 , V_5 , V_201 ) ;
return V_201 ;
}
static void
F_124 ( struct V_170 * V_192 , struct V_76 * V_205 , int V_200 )
{
struct V_185 * V_109 ;
const struct V_198 * V_199 = V_192 -> V_206 ;
struct V_46 * V_47 = V_192 -> V_174 ;
V_192 -> V_174 = NULL ;
while ( ! F_27 ( V_205 ) ) {
enum V_196 V_201 ;
V_109 = F_66 ( V_205 -> V_79 , struct V_185 , V_207 ) ;
F_41 ( & V_109 -> V_207 ) ;
V_201 = F_122 ( V_109 , V_199 , V_47 , V_200 ) ;
if ( V_201 == V_203 )
F_118 ( V_192 , V_109 ) ;
}
F_43 ( V_47 ) ;
}
int
F_125 ( struct V_170 * V_192 )
{
F_45 ( V_205 ) ;
int V_155 ;
V_155 = F_126 ( V_192 , & V_205 ) ;
if ( V_155 != 0 ) {
F_43 ( V_192 -> V_174 ) ;
V_192 -> V_174 = NULL ;
return V_155 ;
}
F_124 ( V_192 , & V_205 , V_192 -> V_208 ) ;
return 0 ;
}
int
F_127 ( struct V_209 * V_109 )
{
int V_24 ;
if ( ! V_109 -> V_186 ) {
F_128 ( V_109 ) ;
V_109 -> V_187 -> V_188 ( & V_109 -> V_189 , V_109 ) ;
V_109 -> V_187 -> V_190 ( V_109 ) ;
return 0 ;
}
F_3 ( L_41 , V_5 ,
V_109 -> V_186 ) ;
V_24 = F_129 ( V_109 , F_117 ( V_109 -> V_35 ) ,
V_109 -> V_187 ) ;
return V_24 ? : - V_106 ;
}
static void
F_130 ( struct V_170 * V_192 ,
struct V_209 * V_109 )
{
F_119 ( & V_109 -> V_116 , & V_192 -> V_193 ) ;
if ( V_109 -> V_173 && F_27 ( & V_109 -> V_173 -> V_194 ) )
F_120 ( V_109 -> V_173 , & V_192 -> V_193 ) ;
F_106 ( V_192 ) ;
V_192 -> V_195 = 1 ;
F_131 ( V_109 ) ;
}
static enum V_196
F_132 ( struct V_209 * V_210 ,
const struct V_198 * V_199 ,
struct V_46 * V_47 )
{
struct V_35 * V_35 = V_210 -> V_35 ;
struct V_7 * V_8 = F_20 ( V_35 ) ;
enum V_196 V_201 ;
V_210 -> V_187 = V_199 ;
V_210 -> V_47 = F_96 ( V_47 ) ;
F_3 ( L_44 ,
V_5 , V_35 -> V_90 , V_210 -> args . V_157 , V_210 -> args . V_67 ) ;
V_201 = V_8 -> V_9 -> V_211 ( V_210 ) ;
if ( V_201 == V_203 ) {
F_43 ( V_210 -> V_47 ) ;
V_210 -> V_47 = NULL ;
} else {
F_123 ( V_35 , V_212 ) ;
}
F_3 ( L_43 , V_5 , V_201 ) ;
return V_201 ;
}
static void
F_133 ( struct V_170 * V_192 , struct V_76 * V_205 )
{
struct V_209 * V_109 ;
const struct V_198 * V_199 = V_192 -> V_206 ;
struct V_46 * V_47 = V_192 -> V_174 ;
V_192 -> V_174 = NULL ;
while ( ! F_27 ( V_205 ) ) {
enum V_196 V_201 ;
V_109 = F_66 ( V_205 -> V_79 , struct V_209 , V_207 ) ;
F_41 ( & V_109 -> V_207 ) ;
V_201 = F_132 ( V_109 , V_199 , V_47 ) ;
if ( V_201 == V_203 )
F_130 ( V_192 , V_109 ) ;
}
F_43 ( V_47 ) ;
}
int
F_134 ( struct V_170 * V_192 )
{
F_45 ( V_205 ) ;
int V_155 ;
V_155 = F_135 ( V_192 , & V_205 ) ;
if ( V_155 != 0 ) {
F_43 ( V_192 -> V_174 ) ;
V_192 -> V_174 = NULL ;
return V_155 ;
}
F_133 ( V_192 , & V_205 ) ;
return 0 ;
}
static void F_136 ( struct V_35 * V_35 , struct V_76 * V_213 )
{
struct V_46 * V_47 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_47 -> V_82 . V_74 == V_154 &&
F_40 ( V_214 , & V_47 -> V_52 ) )
F_14 ( & V_47 -> V_49 , V_213 ) ;
}
}
void
F_115 ( struct V_185 * V_197 )
{
struct V_85 * V_86 = F_28 ( V_197 -> V_35 ) ;
T_6 V_215 = V_197 -> V_216 + V_197 -> V_167 . V_157 ;
bool V_217 = false ;
F_5 ( & V_86 -> V_87 . V_45 ) ;
if ( ! F_55 ( V_133 , & V_86 -> V_134 ) ) {
V_217 = true ;
F_3 ( L_45 ,
V_5 , V_197 -> V_35 -> V_90 ) ;
}
if ( ! F_55 ( V_214 , & V_197 -> V_47 -> V_52 ) ) {
F_96 ( V_197 -> V_47 ) ;
}
if ( V_215 > V_86 -> V_44 -> V_218 )
V_86 -> V_44 -> V_218 = V_215 ;
F_6 ( & V_86 -> V_87 . V_45 ) ;
F_3 ( L_46 ,
V_5 , V_197 -> V_47 , V_86 -> V_44 -> V_218 ) ;
if ( V_217 )
F_137 ( V_197 -> V_35 ) ;
}
void F_138 ( struct V_219 * V_109 )
{
struct V_7 * V_8 = F_20 ( V_109 -> args . V_35 ) ;
if ( V_8 -> V_9 -> V_220 )
V_8 -> V_9 -> V_220 ( V_109 ) ;
}
int
F_139 ( struct V_35 * V_35 , bool V_221 )
{
struct V_219 * V_109 ;
struct V_85 * V_86 = F_28 ( V_35 ) ;
T_6 V_215 ;
int V_24 = 0 ;
F_3 ( L_47 , V_5 , V_35 -> V_90 ) ;
if ( ! F_40 ( V_133 , & V_86 -> V_134 ) )
return 0 ;
V_109 = F_21 ( sizeof( * V_109 ) , V_178 ) ;
if ( ! V_109 ) {
F_137 ( V_35 ) ;
V_24 = - V_136 ;
goto V_4;
}
F_34 ( & V_109 -> V_222 ) ;
F_5 ( & V_35 -> V_45 ) ;
if ( ! F_53 ( V_133 , & V_86 -> V_134 ) ) {
F_6 ( & V_35 -> V_45 ) ;
F_24 ( V_109 ) ;
goto V_4;
}
F_136 ( V_35 , & V_109 -> V_222 ) ;
V_215 = V_86 -> V_44 -> V_218 ;
V_86 -> V_44 -> V_218 = 0 ;
memcpy ( & V_109 -> args . V_96 . V_109 , V_86 -> V_44 -> V_95 . V_109 ,
sizeof( V_86 -> V_44 -> V_95 . V_109 ) ) ;
F_6 ( & V_35 -> V_45 ) ;
V_109 -> args . V_35 = V_35 ;
V_109 -> V_223 = F_91 ( V_86 -> V_44 -> V_41 ) ;
F_140 ( & V_109 -> V_224 ) ;
V_109 -> args . V_225 = F_20 ( V_35 ) -> V_226 ;
V_109 -> V_167 . V_224 = & V_109 -> V_224 ;
V_109 -> args . V_227 = V_215 - 1 ;
V_109 -> V_167 . V_12 = F_20 ( V_35 ) ;
V_24 = F_141 ( V_109 , V_221 ) ;
V_4:
F_3 ( L_48 , V_5 , V_24 ) ;
return V_24 ;
}
