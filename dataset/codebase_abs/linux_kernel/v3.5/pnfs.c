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
return V_39 -> V_40 ? V_39 -> V_40 ( V_37 , V_38 ) :
F_23 ( sizeof( struct V_33 ) , V_38 ) ;
}
static void
F_24 ( struct V_33 * V_34 )
{
struct V_1 * V_39 = F_22 ( V_34 -> V_41 ) -> V_10 ;
F_25 ( V_34 -> V_42 ) ;
return V_39 -> V_40 ? V_39 -> V_43 ( V_34 ) : F_26 ( V_34 ) ;
}
static void
F_27 ( struct V_33 * V_34 )
{
F_3 ( L_16 , V_5 , V_34 ) ;
F_28 ( ! F_29 ( & V_34 -> V_44 ) ) ;
F_30 ( V_34 -> V_41 ) -> V_45 = NULL ;
F_24 ( V_34 ) ;
}
static void
F_31 ( struct V_33 * V_34 )
{
if ( F_9 ( & V_34 -> V_35 ) )
F_27 ( V_34 ) ;
}
void
F_32 ( struct V_33 * V_34 )
{
struct V_36 * V_36 = V_34 -> V_41 ;
if ( F_33 ( & V_34 -> V_35 , & V_36 -> V_46 ) ) {
F_27 ( V_34 ) ;
F_7 ( & V_36 -> V_46 ) ;
}
}
static void
F_34 ( struct V_33 * V_34 , struct V_47 * V_48 )
{
F_35 ( & V_48 -> V_49 ) ;
F_35 ( & V_48 -> V_50 ) ;
F_36 ( & V_48 -> V_51 , 1 ) ;
F_37 () ;
F_38 ( V_52 , & V_48 -> V_53 ) ;
V_48 -> V_54 = V_34 ;
}
static void V_29 ( struct V_47 * V_48 )
{
struct V_36 * V_37 = V_48 -> V_54 -> V_41 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_48 ) ;
F_32 ( F_30 ( V_37 ) -> V_45 ) ;
}
static void
F_39 ( struct V_47 * V_48 )
{
struct V_36 * V_36 = V_48 -> V_54 -> V_41 ;
F_40 ( F_41 ( V_52 , & V_48 -> V_53 ) ) ;
F_42 ( & V_48 -> V_49 ) ;
if ( F_29 ( & V_48 -> V_54 -> V_55 ) ) {
F_38 ( V_56 , & V_48 -> V_54 -> V_57 ) ;
F_31 ( V_48 -> V_54 ) ;
}
F_43 ( & F_22 ( V_36 ) -> V_58 ) ;
}
void
F_44 ( struct V_47 * V_48 )
{
struct V_36 * V_36 ;
if ( ! V_48 )
return;
F_3 ( L_17 , V_5 , V_48 ,
F_45 ( & V_48 -> V_51 ) ,
F_41 ( V_52 , & V_48 -> V_53 ) ) ;
V_36 = V_48 -> V_54 -> V_41 ;
if ( F_33 ( & V_48 -> V_51 , & V_36 -> V_46 ) ) {
F_46 ( V_59 ) ;
F_39 ( V_48 ) ;
F_17 ( & V_48 -> V_49 , & V_59 ) ;
F_7 ( & V_36 -> V_46 ) ;
F_47 ( & V_59 ) ;
}
}
static inline T_3
F_48 ( T_3 V_60 , T_3 V_61 )
{
T_3 V_62 ;
V_62 = V_60 + V_61 ;
return V_62 >= V_60 ? V_62 : V_63 ;
}
static inline T_3
F_49 ( T_3 V_60 , T_3 V_61 )
{
T_3 V_62 ;
F_28 ( ! V_61 ) ;
V_62 = V_60 + V_61 ;
return V_62 > V_60 ? V_62 - 1 : V_63 ;
}
static inline int
F_50 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
T_3 V_67 = V_65 -> V_68 ;
T_3 V_69 = F_48 ( V_67 , V_65 -> V_70 ) ;
T_3 V_71 = V_66 -> V_68 ;
T_3 V_72 = F_48 ( V_71 , V_66 -> V_70 ) ;
return ( V_67 <= V_71 ) && ( V_69 >= V_72 ) ;
}
static inline int
F_51 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
T_3 V_67 = V_65 -> V_68 ;
T_3 V_69 = F_48 ( V_67 , V_65 -> V_70 ) ;
T_3 V_71 = V_66 -> V_68 ;
T_3 V_72 = F_48 ( V_71 , V_66 -> V_70 ) ;
return ( V_69 == V_63 || V_69 > V_71 ) &&
( V_72 == V_63 || V_72 > V_67 ) ;
}
static bool
F_52 ( struct V_64 * V_73 ,
struct V_64 * V_74 )
{
return ( V_74 -> V_75 == V_76 ||
V_73 -> V_75 == V_74 -> V_75 ) &&
F_51 ( V_73 , V_74 ) ;
}
static int F_53 ( struct V_47 * V_48 ,
struct V_77 * V_78 )
{
int V_79 = 0 ;
if ( F_54 ( V_52 , & V_48 -> V_53 ) ) {
F_3 ( L_18 , V_5 , V_48 ,
F_45 ( & V_48 -> V_51 ) ) ;
if ( F_9 ( & V_48 -> V_51 ) ) {
F_39 ( V_48 ) ;
F_17 ( & V_48 -> V_49 , V_78 ) ;
V_79 = 1 ;
}
}
return V_79 ;
}
int
F_55 ( struct V_33 * V_34 ,
struct V_77 * V_78 ,
struct V_64 * V_74 )
{
struct V_47 * V_48 , * V_80 ;
int V_81 = 0 , V_82 = 0 ;
F_3 ( L_19 , V_5 , V_34 ) ;
if ( F_29 ( & V_34 -> V_55 ) ) {
F_30 ( V_34 -> V_41 ) -> V_83 = 0 ;
F_30 ( V_34 -> V_41 ) -> V_84 = 0 ;
if ( ! F_56 ( V_56 , & V_34 -> V_57 ) )
F_31 ( V_34 ) ;
return 0 ;
}
F_57 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_74 ||
F_52 ( & V_48 -> V_85 , V_74 ) ) {
F_3 ( L_20
L_21 , V_5 ,
V_48 , V_48 -> V_85 . V_75 , V_48 -> V_85 . V_68 ,
V_48 -> V_85 . V_70 ) ;
V_81 ++ ;
V_82 += F_53 ( V_48 , V_78 ) ;
}
F_3 ( L_22 , V_5 , V_81 - V_82 ) ;
return V_81 - V_82 ;
}
void
F_47 ( struct V_77 * V_59 )
{
struct V_47 * V_48 , * V_27 ;
struct V_33 * V_34 ;
if ( F_29 ( V_59 ) )
return;
V_34 = F_58 ( V_59 , struct V_47 ,
V_49 ) -> V_54 ;
if ( F_41 ( V_56 , & V_34 -> V_57 ) ) {
struct V_12 * V_86 ;
V_86 = F_22 ( V_34 -> V_41 ) -> V_12 ;
F_5 ( & V_86 -> V_87 ) ;
F_42 ( & V_34 -> V_44 ) ;
F_7 ( & V_86 -> V_87 ) ;
}
F_57 (lseg, tmp, free_me, pls_list) {
F_19 ( & V_48 -> V_49 ) ;
V_29 ( V_48 ) ;
}
}
void
F_59 ( struct V_88 * V_89 )
{
struct V_33 * V_34 ;
F_46 ( V_78 ) ;
F_5 ( & V_89 -> V_90 . V_46 ) ;
V_34 = V_89 -> V_45 ;
if ( V_34 ) {
V_34 -> V_91 ++ ;
F_55 ( V_34 , & V_78 , NULL ) ;
}
F_7 ( & V_89 -> V_90 . V_46 ) ;
F_47 ( & V_78 ) ;
}
void
F_60 ( struct V_12 * V_86 )
{
struct V_8 * V_14 ;
struct V_33 * V_34 ;
F_46 ( V_78 ) ;
F_61 ( V_86 ) ;
F_10 ( V_86 ) ;
F_5 ( & V_86 -> V_87 ) ;
F_62 () ;
F_63 (server, &clp->cl_superblocks, client_link) {
if ( ! F_29 ( & V_14 -> V_92 ) )
F_64 ( & V_14 -> V_92 , & V_78 ) ;
}
F_65 () ;
F_7 ( & V_86 -> V_87 ) ;
while ( ! F_29 ( & V_78 ) ) {
V_34 = F_66 ( V_78 . V_80 , struct V_33 ,
V_44 ) ;
F_3 ( L_23 , V_5 ,
V_34 -> V_41 -> V_93 ) ;
F_42 ( & V_34 -> V_44 ) ;
F_59 ( F_30 ( V_34 -> V_41 ) ) ;
}
}
void
F_67 ( struct V_33 * V_34 , const T_4 * V_94 ,
bool V_95 )
{
T_1 V_96 , V_97 ;
V_96 = F_68 ( V_34 -> V_98 . V_99 ) ;
V_97 = F_68 ( V_94 -> V_99 ) ;
if ( ( int ) ( V_97 - V_96 ) > 0 ) {
F_69 ( & V_34 -> V_98 , V_94 ) ;
if ( V_95 ) {
T_1 V_100 = F_68 ( V_94 -> V_99 ) ;
if ( ( int ) ( V_100 - V_34 -> V_101 ) )
V_34 -> V_101 = V_100 ;
} else {
if ( F_70 ( ( V_97 - V_34 -> V_101 ) > ( 3 << 29 ) ) )
V_34 -> V_101 = V_97 - ( 1 << 30 ) ;
}
}
}
static bool
F_71 ( struct V_33 * V_34 , T_4 * V_102 ,
int V_103 )
{
if ( ( V_102 ) &&
( int ) ( V_34 -> V_101 - F_68 ( V_102 -> V_99 ) ) >= 0 )
return true ;
return V_34 -> V_91 ||
F_41 ( V_56 , & V_34 -> V_57 ) ||
F_41 ( V_104 , & V_34 -> V_57 ) ||
( F_29 ( & V_34 -> V_55 ) &&
( F_45 ( & V_34 -> V_105 ) > V_103 ) ) ;
}
int
F_72 ( T_4 * V_106 , struct V_33 * V_34 ,
struct V_107 * V_108 )
{
int V_25 = 0 ;
F_3 ( L_24 , V_5 ) ;
F_5 ( & V_34 -> V_41 -> V_46 ) ;
if ( F_71 ( V_34 , NULL , 1 ) ) {
V_25 = - V_109 ;
} else if ( F_29 ( & V_34 -> V_55 ) ) {
int V_110 ;
do {
V_110 = F_73 ( & V_108 -> V_111 ) ;
F_69 ( V_106 , & V_108 -> V_102 ) ;
} while ( F_74 ( & V_108 -> V_111 , V_110 ) );
} else
F_69 ( V_106 , & V_34 -> V_98 ) ;
F_7 ( & V_34 -> V_41 -> V_46 ) ;
F_3 ( L_25 , V_5 ) ;
return V_25 ;
}
static struct V_47 *
F_75 ( struct V_33 * V_34 ,
struct V_112 * V_113 ,
struct V_64 * V_114 ,
T_2 V_38 )
{
struct V_36 * V_37 = V_34 -> V_41 ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_115 * V_116 ;
struct V_47 * V_48 = NULL ;
struct V_117 * * V_118 = NULL ;
int V_119 ;
T_1 V_120 , V_121 ;
F_3 ( L_24 , V_5 ) ;
F_28 ( V_113 == NULL ) ;
V_116 = F_23 ( sizeof( * V_116 ) , V_38 ) ;
if ( V_116 == NULL )
return NULL ;
V_120 = V_14 -> V_12 -> V_122 -> V_123 . V_120 ;
V_121 = F_76 ( 0 , V_120 ) ;
V_118 = F_77 ( V_121 , sizeof( struct V_117 * ) , V_38 ) ;
if ( ! V_118 )
goto V_124;
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
V_118 [ V_119 ] = F_78 ( V_38 ) ;
if ( ! V_118 [ V_119 ] )
goto V_124;
}
V_116 -> args . V_125 = V_126 ;
if ( V_116 -> args . V_125 > V_114 -> V_70 )
V_116 -> args . V_125 = V_114 -> V_70 ;
V_116 -> args . V_127 = V_128 ;
V_116 -> args . V_114 = * V_114 ;
V_116 -> args . type = V_14 -> V_10 -> V_2 ;
V_116 -> args . V_36 = V_37 ;
V_116 -> args . V_113 = F_79 ( V_113 ) ;
V_116 -> args . V_45 . V_118 = V_118 ;
V_116 -> args . V_45 . V_129 = V_121 * V_130 ;
V_116 -> V_131 = & V_48 ;
V_116 -> V_38 = V_38 ;
F_80 ( V_116 ) ;
if ( ! V_48 ) {
F_38 ( F_81 ( V_114 -> V_75 ) , & V_34 -> V_57 ) ;
}
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ )
F_82 ( V_118 [ V_119 ] ) ;
F_26 ( V_118 ) ;
return V_48 ;
V_124:
if ( V_118 ) {
for ( V_119 = 0 ; V_119 < V_121 ; V_119 ++ ) {
if ( ! V_118 [ V_119 ] )
break;
F_82 ( V_118 [ V_119 ] ) ;
}
F_26 ( V_118 ) ;
}
F_26 ( V_116 ) ;
return NULL ;
}
int
F_83 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_88 * V_89 = F_30 ( V_37 ) ;
F_46 ( V_78 ) ;
struct V_132 * V_133 ;
T_4 V_102 ;
int V_25 = 0 ;
F_3 ( L_24 , V_5 ) ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = V_89 -> V_45 ;
if ( ! V_34 ) {
F_7 ( & V_37 -> V_46 ) ;
F_3 ( L_26 , V_5 ) ;
return V_25 ;
}
V_102 = V_89 -> V_45 -> V_98 ;
F_20 ( V_34 ) ;
F_55 ( V_34 , & V_78 , NULL ) ;
V_34 -> V_91 ++ ;
F_7 ( & V_37 -> V_46 ) ;
F_47 ( & V_78 ) ;
F_40 ( F_41 ( V_134 , & V_89 -> V_135 ) ) ;
V_133 = F_23 ( sizeof( * V_133 ) , V_136 ) ;
if ( F_70 ( V_133 == NULL ) ) {
V_25 = - V_137 ;
F_38 ( V_138 , & V_34 -> V_57 ) ;
F_38 ( V_139 , & V_34 -> V_57 ) ;
F_32 ( V_34 ) ;
goto V_4;
}
V_133 -> args . V_102 = V_102 ;
V_133 -> args . V_140 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_133 -> args . V_36 = V_37 ;
V_133 -> args . V_45 = V_34 ;
V_133 -> V_86 = F_22 ( V_37 ) -> V_12 ;
V_25 = F_84 ( V_133 ) ;
V_4:
F_3 ( L_27 , V_5 , V_25 ) ;
return V_25 ;
}
bool F_85 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
struct V_47 * V_48 , * V_27 ;
F_46 ( V_78 ) ;
bool V_141 = false ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_30 ( V_37 ) -> V_45 ;
if ( ! V_34 || ! F_54 ( V_142 , & V_34 -> V_57 ) ||
F_41 ( V_104 , & V_34 -> V_57 ) )
goto V_143;
F_57 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_41 ( V_144 , & V_48 -> V_53 ) ) {
F_53 ( V_48 , & V_78 ) ;
V_141 = true ;
}
if ( ! V_141 )
goto V_143;
V_34 -> V_91 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_46 ) ;
F_47 ( & V_78 ) ;
return true ;
V_143:
F_7 ( & V_37 -> V_46 ) ;
return false ;
}
void F_86 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_30 ( V_37 ) -> V_45 ;
V_34 -> V_91 -- ;
F_31 ( V_34 ) ;
F_7 ( & V_37 -> V_46 ) ;
}
void F_87 ( struct V_36 * V_37 , T_1 V_145 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_30 ( V_37 ) -> V_45 ;
if ( ( int ) ( V_145 - V_34 -> V_101 ) > 0 )
V_34 -> V_101 = V_145 ;
F_7 ( & V_37 -> V_46 ) ;
}
bool F_88 ( struct V_36 * V_37 , T_1 * V_145 )
{
struct V_88 * V_89 = F_30 ( V_37 ) ;
struct V_47 * V_48 ;
bool V_141 = false ;
F_5 ( & V_37 -> V_46 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_41 ( V_144 , & V_48 -> V_53 ) ) {
V_141 = true ;
break;
}
if ( ! V_141 ) {
struct V_33 * V_34 = V_89 -> V_45 ;
T_1 V_146 = F_68 ( V_34 -> V_98 . V_99 ) ;
* V_145 = V_146 + F_45 ( & V_34 -> V_105 ) ;
}
F_7 ( & V_37 -> V_46 ) ;
return V_141 ;
}
static T_5
F_89 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
T_5 V_147 ;
V_147 = V_65 -> V_68 - V_66 -> V_68 ;
if ( V_147 )
return V_147 ;
V_147 = V_66 -> V_70 - V_65 -> V_70 ;
if ( V_147 )
return V_147 ;
return ( int ) ( V_65 -> V_75 == V_148 ) - ( int ) ( V_66 -> V_75 == V_148 ) ;
}
static void
F_90 ( struct V_33 * V_34 ,
struct V_47 * V_48 )
{
struct V_47 * V_149 ;
F_3 ( L_28 , V_5 ) ;
F_91 ( & V_34 -> V_41 -> V_46 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_89 ( & V_48 -> V_85 , & V_149 -> V_85 ) > 0 )
continue;
F_92 ( & V_48 -> V_49 , & V_149 -> V_49 ) ;
F_3 ( L_29
L_30
L_31 ,
V_5 , V_48 , V_48 -> V_85 . V_75 ,
V_48 -> V_85 . V_68 , V_48 -> V_85 . V_70 ,
V_149 , V_149 -> V_85 . V_75 , V_149 -> V_85 . V_68 ,
V_149 -> V_85 . V_70 ) ;
goto V_4;
}
F_92 ( & V_48 -> V_49 , & V_34 -> V_55 ) ;
F_3 ( L_29
L_32 ,
V_5 , V_48 , V_48 -> V_85 . V_75 ,
V_48 -> V_85 . V_68 , V_48 -> V_85 . V_70 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_33 , V_5 ) ;
}
static struct V_33 *
F_93 ( struct V_36 * V_37 ,
struct V_112 * V_113 ,
T_2 V_38 )
{
struct V_33 * V_34 ;
V_34 = F_21 ( V_37 , V_38 ) ;
if ( ! V_34 )
return NULL ;
F_36 ( & V_34 -> V_35 , 1 ) ;
F_35 ( & V_34 -> V_44 ) ;
F_35 ( & V_34 -> V_55 ) ;
F_35 ( & V_34 -> V_150 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_42 = F_94 ( V_113 -> V_151 -> V_7 -> V_152 ) ;
return V_34 ;
}
static struct V_33 *
F_95 ( struct V_36 * V_37 ,
struct V_112 * V_113 ,
T_2 V_38 )
{
struct V_88 * V_89 = F_30 ( V_37 ) ;
struct V_33 * V_94 = NULL ;
F_3 ( L_34 , V_5 , V_37 , V_89 -> V_45 ) ;
F_91 ( & V_37 -> V_46 ) ;
if ( V_89 -> V_45 ) {
if ( F_41 ( V_56 , & V_89 -> V_45 -> V_57 ) )
return NULL ;
else
return V_89 -> V_45 ;
}
F_7 ( & V_37 -> V_46 ) ;
V_94 = F_93 ( V_37 , V_113 , V_38 ) ;
F_5 ( & V_37 -> V_46 ) ;
if ( F_96 ( V_89 -> V_45 == NULL ) )
V_89 -> V_45 = V_94 ;
else
F_24 ( V_94 ) ;
return V_89 -> V_45 ;
}
static int
F_97 ( struct V_64 * V_153 ,
struct V_64 * V_114 )
{
struct V_64 V_154 ;
if ( ( V_114 -> V_75 == V_155 &&
V_153 -> V_75 != V_155 ) ||
! F_51 ( V_153 , V_114 ) )
return 0 ;
V_154 = * V_114 ;
V_154 . V_70 = 1 ;
return F_50 ( V_153 , & V_154 ) ;
}
static struct V_47 *
F_98 ( struct V_33 * V_34 ,
struct V_64 * V_114 )
{
struct V_47 * V_48 , * V_156 = NULL ;
F_3 ( L_28 , V_5 ) ;
F_91 ( & V_34 -> V_41 -> V_46 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_41 ( V_52 , & V_48 -> V_53 ) &&
F_97 ( & V_48 -> V_85 , V_114 ) ) {
V_156 = F_99 ( V_48 ) ;
break;
}
if ( V_48 -> V_85 . V_68 > V_114 -> V_68 )
break;
}
F_3 ( L_35 ,
V_5 , V_156 , V_156 ? F_45 ( & V_156 -> V_51 ) : 0 ) ;
return V_156 ;
}
static bool F_100 ( struct V_112 * V_113 ,
struct V_36 * V_37 , int V_75 )
{
struct V_157 * V_158 = V_113 -> V_159 ;
struct V_88 * V_89 = F_30 ( V_37 ) ;
T_6 V_160 = F_101 ( V_37 ) ;
bool V_161 = false , V_162 = false , V_163 = false , V_164 = false , V_156 = false ;
if ( V_158 == NULL )
return V_156 ;
F_3 ( L_36 ,
V_5 , V_158 -> V_165 , V_158 -> V_166 , V_158 -> V_167 , V_158 -> V_168 , V_158 -> V_169 ) ;
switch ( V_75 ) {
case V_148 :
if ( V_158 -> V_165 & V_170 ) {
F_3 ( L_37 , V_5 , V_160 ) ;
V_162 = true ;
if ( V_160 < V_158 -> V_166 )
V_161 = true ;
}
if ( V_158 -> V_165 & V_171 ) {
F_3 ( L_38 , V_5 ,
V_89 -> V_84 ) ;
V_164 = true ;
if ( V_89 -> V_84 < V_158 -> V_168 )
V_163 = true ;
}
break;
case V_155 :
if ( V_158 -> V_165 & V_172 ) {
F_3 ( L_37 , V_5 , V_160 ) ;
V_162 = true ;
if ( V_160 < V_158 -> V_167 )
V_161 = true ;
}
if ( V_158 -> V_165 & V_173 ) {
F_3 ( L_39 , V_5 ,
V_89 -> V_83 ) ;
V_164 = true ;
if ( V_89 -> V_83 < V_158 -> V_169 )
V_163 = true ;
}
break;
}
if ( V_162 && V_164 ) {
if ( V_161 && V_163 )
V_156 = true ;
} else if ( V_161 || V_163 )
V_156 = true ;
F_3 ( L_40 , V_5 , V_161 , V_163 , V_156 ) ;
return V_156 ;
}
struct V_47 *
F_102 ( struct V_36 * V_37 ,
struct V_112 * V_113 ,
T_6 V_174 ,
T_3 V_175 ,
enum V_176 V_75 ,
T_2 V_38 )
{
struct V_64 V_177 = {
. V_75 = V_75 ,
. V_68 = V_174 ,
. V_70 = V_175 ,
} ;
unsigned V_178 ;
struct V_88 * V_89 = F_30 ( V_37 ) ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_86 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_47 * V_48 = NULL ;
bool V_179 = false ;
if ( ! F_103 ( F_22 ( V_37 ) ) )
return NULL ;
if ( F_100 ( V_113 , V_37 , V_75 ) )
return NULL ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_95 ( V_37 , V_113 , V_38 ) ;
if ( V_34 == NULL ) {
F_3 ( L_41 , V_5 ) ;
goto V_180;
}
if ( F_41 ( V_104 , & V_34 -> V_57 ) ) {
F_3 ( L_42 , V_5 ) ;
goto V_180;
}
if ( F_41 ( F_81 ( V_75 ) , & V_89 -> V_45 -> V_57 ) )
goto V_180;
V_48 = F_98 ( V_34 , & V_177 ) ;
if ( V_48 )
goto V_180;
if ( F_71 ( V_34 , NULL , 0 ) )
goto V_180;
F_15 ( & V_34 -> V_105 ) ;
F_20 ( V_34 ) ;
if ( F_29 ( & V_34 -> V_55 ) )
V_179 = true ;
F_7 ( & V_37 -> V_46 ) ;
if ( V_179 ) {
F_5 ( & V_86 -> V_87 ) ;
F_28 ( ! F_29 ( & V_34 -> V_44 ) ) ;
F_92 ( & V_34 -> V_44 , & V_14 -> V_92 ) ;
F_7 ( & V_86 -> V_87 ) ;
}
V_178 = V_177 . V_68 & ~ V_181 ;
if ( V_178 ) {
V_177 . V_68 -= V_178 ;
V_177 . V_70 += V_178 ;
}
if ( V_177 . V_70 != V_63 )
V_177 . V_70 = F_104 ( V_177 . V_70 ) ;
V_48 = F_75 ( V_34 , V_113 , & V_177 , V_38 ) ;
if ( ! V_48 && V_179 ) {
F_5 ( & V_86 -> V_87 ) ;
F_42 ( & V_34 -> V_44 ) ;
F_7 ( & V_86 -> V_87 ) ;
}
F_105 ( & V_34 -> V_105 ) ;
F_32 ( V_34 ) ;
V_4:
F_3 ( L_43 , V_5 ,
V_89 -> V_45 ? V_89 -> V_45 -> V_57 : - 1 , V_48 ) ;
return V_48 ;
V_180:
F_7 ( & V_37 -> V_46 ) ;
goto V_4;
}
int
F_106 ( struct V_115 * V_116 )
{
struct V_33 * V_34 = F_30 ( V_116 -> args . V_36 ) -> V_45 ;
struct V_182 * V_183 = & V_116 -> V_183 ;
struct V_47 * V_48 ;
struct V_36 * V_37 = V_34 -> V_41 ;
int V_25 = 0 ;
V_48 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_183 , V_116 -> V_38 ) ;
if ( ! V_48 || F_107 ( V_48 ) ) {
if ( ! V_48 )
V_25 = - V_137 ;
else
V_25 = F_108 ( V_48 ) ;
F_3 ( L_44 ,
V_5 , V_25 ) ;
goto V_4;
}
F_5 ( & V_37 -> V_46 ) ;
if ( F_41 ( V_104 , & V_34 -> V_57 ) ) {
F_3 ( L_45 , V_5 ) ;
goto V_184;
}
if ( F_71 ( V_34 , & V_183 -> V_102 , 1 ) ) {
F_3 ( L_46 , V_5 ) ;
goto V_184;
}
F_34 ( V_34 , V_48 ) ;
V_48 -> V_85 = V_183 -> V_114 ;
* V_116 -> V_131 = F_99 ( V_48 ) ;
F_90 ( V_34 , V_48 ) ;
if ( V_183 -> V_185 ) {
F_38 ( V_144 , & V_48 -> V_53 ) ;
F_38 ( V_142 , & V_34 -> V_57 ) ;
}
F_67 ( V_34 , & V_183 -> V_102 , false ) ;
F_7 ( & V_37 -> V_46 ) ;
V_4:
return V_25 ;
V_184:
F_7 ( & V_37 -> V_46 ) ;
V_48 -> V_54 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_48 ) ;
goto V_4;
}
void
F_109 ( struct V_186 * V_187 , struct V_188 * V_189 )
{
F_28 ( V_187 -> V_190 != NULL ) ;
if ( V_189 -> V_191 != V_189 -> V_192 ) {
F_110 ( V_187 ) ;
return;
}
V_187 -> V_190 = F_102 ( V_187 -> V_193 ,
V_189 -> V_194 ,
F_111 ( V_189 ) ,
V_189 -> V_195 ,
V_148 ,
V_136 ) ;
if ( V_187 -> V_190 == NULL )
F_110 ( V_187 ) ;
}
void
F_112 ( struct V_186 * V_187 , struct V_188 * V_189 )
{
F_28 ( V_187 -> V_190 != NULL ) ;
if ( V_189 -> V_191 != V_189 -> V_192 ) {
F_113 ( V_187 ) ;
return;
}
V_187 -> V_190 = F_102 ( V_187 -> V_193 ,
V_189 -> V_194 ,
F_111 ( V_189 ) ,
V_189 -> V_195 ,
V_155 ,
V_196 ) ;
if ( V_187 -> V_190 == NULL )
F_113 ( V_187 ) ;
}
bool
F_114 ( struct V_186 * V_187 , struct V_36 * V_36 ,
const struct V_197 * V_198 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
return false ;
F_115 ( V_187 , V_36 , V_39 -> V_199 , V_198 ,
V_14 -> V_200 , 0 ) ;
return true ;
}
bool
F_116 ( struct V_186 * V_187 , struct V_36 * V_36 ,
int V_201 ,
const struct V_197 * V_198 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
return false ;
F_115 ( V_187 , V_36 , V_39 -> V_202 , V_198 ,
V_14 -> V_203 , V_201 ) ;
return true ;
}
bool
F_117 ( struct V_186 * V_187 , struct V_188 * V_204 ,
struct V_188 * V_189 )
{
if ( V_187 -> V_190 == NULL )
return F_118 ( V_187 , V_204 , V_189 ) ;
return F_111 ( V_189 ) < F_48 ( V_187 -> V_190 -> V_85 . V_68 ,
V_187 -> V_190 -> V_85 . V_70 ) ;
}
int F_119 ( struct V_36 * V_36 ,
struct V_77 * V_205 ,
const struct V_197 * V_198 )
{
struct V_186 V_187 ;
F_46 ( V_206 ) ;
F_120 ( & V_187 , V_36 , V_207 , V_198 ) ;
while ( ! F_29 ( V_205 ) ) {
struct V_188 * V_189 = F_121 ( V_205 -> V_80 ) ;
F_122 ( V_189 ) ;
if ( ! F_123 ( & V_187 , V_189 ) )
F_124 ( V_189 , & V_206 ) ;
}
F_125 ( & V_187 ) ;
if ( ! F_29 ( & V_206 ) ) {
F_126 ( & V_206 , V_205 ) ;
return - V_208 ;
}
return 0 ;
}
static void F_127 ( struct V_209 * V_210 )
{
struct V_211 * V_212 = V_210 -> V_213 ;
F_3 ( L_47 , V_212 -> V_214 ) ;
if ( F_22 ( V_212 -> V_36 ) -> V_10 -> V_135 &
V_215 ) {
F_128 ( V_134 , & F_30 ( V_212 -> V_36 ) -> V_135 ) ;
F_129 ( V_212 -> V_36 ) ;
}
if ( ! F_56 ( V_216 , & V_212 -> V_135 ) )
V_210 -> V_217 . V_218 = F_119 ( V_212 -> V_36 ,
& V_212 -> V_118 ,
V_212 -> V_219 ) ;
}
void F_130 ( struct V_209 * V_210 )
{
struct V_211 * V_212 = V_210 -> V_213 ;
if ( ! V_212 -> V_214 ) {
F_131 ( V_210 ) ;
V_212 -> V_220 -> V_221 ( & V_210 -> V_217 , V_210 ) ;
} else
F_127 ( V_210 ) ;
V_212 -> V_220 -> V_222 ( V_210 ) ;
}
static void
F_132 ( struct V_186 * V_223 ,
struct V_209 * V_210 )
{
struct V_211 * V_212 = V_210 -> V_213 ;
if ( ! F_56 ( V_216 , & V_212 -> V_135 ) ) {
F_133 ( & V_212 -> V_118 , & V_223 -> V_224 ) ;
F_113 ( V_223 ) ;
V_223 -> V_225 = 1 ;
}
F_134 ( V_210 ) ;
}
static enum V_226
F_135 ( struct V_209 * V_227 ,
const struct V_228 * V_229 ,
struct V_47 * V_48 ,
int V_230 )
{
struct V_211 * V_212 = V_227 -> V_213 ;
struct V_36 * V_36 = V_212 -> V_36 ;
enum V_226 V_231 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_212 -> V_220 = V_229 ;
F_3 ( L_48 , V_5 ,
V_36 -> V_93 , V_227 -> args . V_175 , V_227 -> args . V_68 , V_230 ) ;
V_231 = V_9 -> V_10 -> V_232 ( V_227 , V_230 ) ;
if ( V_231 != V_233 )
F_136 ( V_36 , V_234 ) ;
F_3 ( L_49 , V_5 , V_231 ) ;
return V_231 ;
}
static void
F_137 ( struct V_186 * V_223 , struct V_77 * V_205 , int V_230 )
{
struct V_209 * V_210 ;
const struct V_228 * V_229 = V_223 -> V_235 ;
struct V_47 * V_48 = V_223 -> V_190 ;
V_223 -> V_190 = NULL ;
while ( ! F_29 ( V_205 ) ) {
enum V_226 V_231 ;
V_210 = F_58 ( V_205 , struct V_209 , V_236 ) ;
F_42 ( & V_210 -> V_236 ) ;
V_231 = F_135 ( V_210 , V_229 , V_48 , V_230 ) ;
if ( V_231 == V_233 )
F_132 ( V_223 , V_210 ) ;
}
F_44 ( V_48 ) ;
}
static void F_138 ( struct V_211 * V_212 )
{
F_44 ( V_212 -> V_48 ) ;
F_139 ( V_212 ) ;
}
int
F_140 ( struct V_186 * V_223 )
{
struct V_237 * V_238 ;
struct V_211 * V_212 ;
int V_156 ;
V_238 = F_141 () ;
if ( ! V_238 ) {
V_223 -> V_239 -> V_240 ( & V_223 -> V_224 ) ;
F_44 ( V_223 -> V_190 ) ;
V_223 -> V_190 = NULL ;
return - V_137 ;
}
V_212 = & V_238 -> V_213 ;
F_142 ( V_223 , V_212 , F_138 ) ;
V_212 -> V_48 = F_99 ( V_223 -> V_190 ) ;
F_15 ( & V_212 -> V_241 ) ;
V_156 = F_143 ( V_223 , V_212 ) ;
if ( V_156 != 0 ) {
F_44 ( V_223 -> V_190 ) ;
V_223 -> V_190 = NULL ;
} else
F_137 ( V_223 , & V_212 -> V_242 , V_223 -> V_243 ) ;
if ( F_9 ( & V_212 -> V_241 ) )
V_212 -> V_219 -> V_244 ( V_212 ) ;
return V_156 ;
}
int F_144 ( struct V_36 * V_36 ,
struct V_77 * V_205 ,
const struct V_197 * V_198 )
{
struct V_186 V_187 ;
F_46 ( V_206 ) ;
F_145 ( & V_187 , V_36 , V_198 ) ;
while ( ! F_29 ( V_205 ) ) {
struct V_188 * V_189 = F_121 ( V_205 -> V_80 ) ;
F_122 ( V_189 ) ;
if ( ! F_123 ( & V_187 , V_189 ) )
F_124 ( V_189 , & V_206 ) ;
}
F_125 ( & V_187 ) ;
if ( ! F_29 ( & V_206 ) ) {
F_126 ( & V_206 , V_205 ) ;
return - V_208 ;
}
return 0 ;
}
static void F_146 ( struct V_245 * V_210 )
{
struct V_211 * V_212 = V_210 -> V_213 ;
F_3 ( L_50 , V_212 -> V_214 ) ;
if ( F_22 ( V_212 -> V_36 ) -> V_10 -> V_135 &
V_215 ) {
F_128 ( V_134 , & F_30 ( V_212 -> V_36 ) -> V_135 ) ;
F_129 ( V_212 -> V_36 ) ;
}
if ( ! F_56 ( V_216 , & V_212 -> V_135 ) )
V_210 -> V_217 . V_218 = F_144 ( V_212 -> V_36 ,
& V_212 -> V_118 ,
V_212 -> V_219 ) ;
}
void F_147 ( struct V_245 * V_210 )
{
struct V_211 * V_212 = V_210 -> V_213 ;
if ( F_96 ( ! V_212 -> V_214 ) ) {
F_148 ( V_210 ) ;
V_212 -> V_220 -> V_221 ( & V_210 -> V_217 , V_210 ) ;
} else
F_146 ( V_210 ) ;
V_212 -> V_220 -> V_222 ( V_210 ) ;
}
static void
F_149 ( struct V_186 * V_223 ,
struct V_245 * V_210 )
{
struct V_211 * V_212 = V_210 -> V_213 ;
if ( ! F_56 ( V_216 , & V_212 -> V_135 ) ) {
F_133 ( & V_212 -> V_118 , & V_223 -> V_224 ) ;
F_110 ( V_223 ) ;
V_223 -> V_225 = 1 ;
}
F_150 ( V_210 ) ;
}
static enum V_226
F_151 ( struct V_245 * V_246 ,
const struct V_228 * V_229 ,
struct V_47 * V_48 )
{
struct V_211 * V_212 = V_246 -> V_213 ;
struct V_36 * V_36 = V_212 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_226 V_231 ;
V_212 -> V_220 = V_229 ;
F_3 ( L_51 ,
V_5 , V_36 -> V_93 , V_246 -> args . V_175 , V_246 -> args . V_68 ) ;
V_231 = V_9 -> V_10 -> V_247 ( V_246 ) ;
if ( V_231 != V_233 )
F_136 ( V_36 , V_248 ) ;
F_3 ( L_49 , V_5 , V_231 ) ;
return V_231 ;
}
static void
F_152 ( struct V_186 * V_223 , struct V_77 * V_205 )
{
struct V_245 * V_210 ;
const struct V_228 * V_229 = V_223 -> V_235 ;
struct V_47 * V_48 = V_223 -> V_190 ;
V_223 -> V_190 = NULL ;
while ( ! F_29 ( V_205 ) ) {
enum V_226 V_231 ;
V_210 = F_58 ( V_205 , struct V_245 , V_236 ) ;
F_42 ( & V_210 -> V_236 ) ;
V_231 = F_151 ( V_210 , V_229 , V_48 ) ;
if ( V_231 == V_233 )
F_149 ( V_223 , V_210 ) ;
}
F_44 ( V_48 ) ;
}
static void F_153 ( struct V_211 * V_212 )
{
F_44 ( V_212 -> V_48 ) ;
F_154 ( V_212 ) ;
}
int
F_155 ( struct V_186 * V_223 )
{
struct V_249 * V_250 ;
struct V_211 * V_212 ;
int V_156 ;
V_250 = F_156 () ;
if ( ! V_250 ) {
V_223 -> V_239 -> V_240 ( & V_223 -> V_224 ) ;
V_156 = - V_137 ;
F_44 ( V_223 -> V_190 ) ;
V_223 -> V_190 = NULL ;
return V_156 ;
}
V_212 = & V_250 -> V_213 ;
F_142 ( V_223 , V_212 , F_153 ) ;
V_212 -> V_48 = F_99 ( V_223 -> V_190 ) ;
F_15 ( & V_212 -> V_241 ) ;
V_156 = F_157 ( V_223 , V_212 ) ;
if ( V_156 != 0 ) {
F_44 ( V_223 -> V_190 ) ;
V_223 -> V_190 = NULL ;
} else
F_152 ( V_223 , & V_212 -> V_242 ) ;
if ( F_9 ( & V_212 -> V_241 ) )
V_212 -> V_219 -> V_244 ( V_212 ) ;
return V_156 ;
}
static void F_158 ( struct V_36 * V_36 , struct V_77 * V_251 )
{
struct V_47 * V_48 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_48 -> V_85 . V_75 == V_155 &&
F_41 ( V_252 , & V_48 -> V_53 ) )
F_17 ( & V_48 -> V_50 , V_251 ) ;
}
}
void F_159 ( struct V_47 * V_48 )
{
if ( V_48 -> V_85 . V_75 == V_155 ) {
F_3 ( L_52 , V_5 ) ;
F_38 ( F_81 ( V_155 ) , & V_48 -> V_54 -> V_57 ) ;
} else {
F_3 ( L_53 , V_5 ) ;
F_38 ( F_81 ( V_148 ) , & V_48 -> V_54 -> V_57 ) ;
}
}
void
F_131 ( struct V_209 * V_227 )
{
struct V_211 * V_212 = V_227 -> V_213 ;
struct V_36 * V_36 = V_212 -> V_36 ;
struct V_88 * V_89 = F_30 ( V_36 ) ;
T_6 V_253 = V_227 -> V_254 + V_227 -> V_183 . V_175 ;
bool V_255 = false ;
F_5 ( & V_36 -> V_46 ) ;
if ( ! F_56 ( V_134 , & V_89 -> V_135 ) ) {
V_255 = true ;
F_3 ( L_54 ,
V_5 , V_36 -> V_93 ) ;
}
if ( ! F_56 ( V_252 , & V_212 -> V_48 -> V_53 ) ) {
F_99 ( V_212 -> V_48 ) ;
}
if ( V_253 > V_89 -> V_45 -> V_256 )
V_89 -> V_45 -> V_256 = V_253 ;
F_7 ( & V_36 -> V_46 ) ;
F_3 ( L_55 ,
V_5 , V_212 -> V_48 , V_89 -> V_45 -> V_256 ) ;
if ( V_255 )
F_160 ( V_36 ) ;
}
void F_161 ( struct V_257 * V_210 )
{
struct V_8 * V_9 = F_22 ( V_210 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_258 )
V_9 -> V_10 -> V_258 ( V_210 ) ;
}
int
F_162 ( struct V_36 * V_36 , bool V_259 )
{
struct V_257 * V_210 ;
struct V_88 * V_89 = F_30 ( V_36 ) ;
T_6 V_253 ;
int V_25 = 0 ;
F_3 ( L_56 , V_5 , V_36 -> V_93 ) ;
if ( ! F_41 ( V_134 , & V_89 -> V_135 ) )
return 0 ;
V_210 = F_23 ( sizeof( * V_210 ) , V_196 ) ;
if ( ! V_210 ) {
V_25 = - V_137 ;
goto V_4;
}
if ( ! F_41 ( V_134 , & V_89 -> V_135 ) )
goto V_260;
if ( F_56 ( V_261 , & V_89 -> V_135 ) ) {
if ( ! V_259 ) {
V_25 = - V_109 ;
goto V_260;
}
V_25 = F_163 ( & V_89 -> V_135 , V_261 ,
V_262 , V_263 ) ;
if ( V_25 )
goto V_260;
}
F_35 ( & V_210 -> V_264 ) ;
F_5 ( & V_36 -> V_46 ) ;
if ( ! F_54 ( V_134 , & V_89 -> V_135 ) ) {
F_128 ( V_261 , & V_89 -> V_135 ) ;
F_7 ( & V_36 -> V_46 ) ;
F_164 ( & V_89 -> V_135 , V_261 ) ;
goto V_260;
}
F_158 ( V_36 , & V_210 -> V_264 ) ;
V_253 = V_89 -> V_45 -> V_256 ;
V_89 -> V_45 -> V_256 = 0 ;
F_69 ( & V_210 -> args . V_102 , & V_89 -> V_45 -> V_98 ) ;
F_7 ( & V_36 -> V_46 ) ;
V_210 -> args . V_36 = V_36 ;
V_210 -> V_265 = F_94 ( V_89 -> V_45 -> V_42 ) ;
F_165 ( & V_210 -> V_266 ) ;
V_210 -> args . V_267 = F_22 ( V_36 ) -> V_268 ;
V_210 -> V_183 . V_266 = & V_210 -> V_266 ;
V_210 -> args . V_269 = V_253 - 1 ;
V_210 -> V_183 . V_14 = F_22 ( V_36 ) ;
V_25 = F_166 ( V_210 , V_259 ) ;
V_4:
if ( V_25 )
F_160 ( V_36 ) ;
F_3 ( L_57 , V_5 , V_25 ) ;
return V_25 ;
V_260:
F_26 ( V_210 ) ;
goto V_4;
}
struct V_157 * F_167 ( void )
{
struct V_157 * V_270 ;
V_270 = F_23 ( sizeof( * V_270 ) , V_196 ) ;
if ( ! V_270 ) {
F_3 ( L_58 , V_5 ) ;
return NULL ;
}
return V_270 ;
}
