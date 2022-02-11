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
if ( V_8 -> V_9 )
F_8 ( V_8 -> V_9 -> V_10 ) ;
V_8 -> V_9 = NULL ;
}
void
F_9 ( struct V_7 * V_11 , T_1 V_2 )
{
struct V_1 * V_12 = NULL ;
if ( V_2 == 0 )
goto V_13;
if ( ! ( V_11 -> V_14 -> V_15 &
( V_16 | V_17 ) ) ) {
F_10 ( V_18 L_2 , V_5 ,
V_2 , V_11 -> V_14 -> V_15 ) ;
goto V_13;
}
V_12 = F_4 ( V_2 ) ;
if ( ! V_12 ) {
F_11 ( L_3 , V_19 , V_2 ) ;
V_12 = F_4 ( V_2 ) ;
if ( ! V_12 ) {
F_3 ( L_4 ,
V_5 , V_2 ) ;
goto V_13;
}
}
if ( ! F_12 ( V_12 -> V_10 ) ) {
F_3 ( L_5 , V_5 ) ;
goto V_13;
}
V_11 -> V_9 = V_12 ;
F_3 ( L_6 , V_5 , V_2 ) ;
return;
V_13:
F_3 ( L_7 , V_5 ) ;
V_11 -> V_9 = NULL ;
}
int
F_13 ( struct V_1 * V_12 )
{
int V_20 = - V_21 ;
struct V_1 * V_22 ;
if ( V_12 -> V_2 == 0 ) {
F_10 ( V_18 L_8 , V_5 ) ;
return V_20 ;
}
if ( ! V_12 -> V_23 || ! V_12 -> V_24 ) {
F_10 ( V_18 L_9
L_10 , V_5 ) ;
return V_20 ;
}
F_5 ( & V_6 ) ;
V_22 = F_1 ( V_12 -> V_2 ) ;
if ( ! V_22 ) {
F_14 ( & V_12 -> V_25 , & V_26 ) ;
V_20 = 0 ;
F_3 ( L_11 , V_5 , V_12 -> V_2 ,
V_12 -> V_27 ) ;
} else {
F_10 ( V_18 L_12 ,
V_5 , V_12 -> V_2 ) ;
}
F_6 ( & V_6 ) ;
return V_20 ;
}
void
F_15 ( struct V_1 * V_12 )
{
F_3 ( L_13 , V_5 , V_12 -> V_2 ) ;
F_5 ( & V_6 ) ;
F_16 ( & V_12 -> V_25 ) ;
F_6 ( & V_6 ) ;
}
void
F_17 ( struct V_28 * V_29 )
{
F_18 ( & V_29 -> V_30 ) ;
}
static struct V_28 *
F_19 ( struct V_31 * V_32 , T_2 V_33 )
{
struct V_1 * V_34 = F_20 ( V_32 ) -> V_9 ;
return V_34 -> V_35 ? V_34 -> V_35 ( V_32 , V_33 ) :
F_21 ( sizeof( struct V_28 ) , V_33 ) ;
}
static void
F_22 ( struct V_28 * V_29 )
{
struct V_1 * V_34 = F_20 ( V_29 -> V_36 ) -> V_9 ;
return V_34 -> V_35 ? V_34 -> V_37 ( V_29 ) : F_23 ( V_29 ) ;
}
static void
F_24 ( struct V_28 * V_29 )
{
F_3 ( L_14 , V_5 , V_29 ) ;
F_25 ( ! F_26 ( & V_29 -> V_38 ) ) ;
F_27 ( V_29 -> V_36 ) -> V_39 = NULL ;
F_22 ( V_29 ) ;
}
static void
F_28 ( struct V_28 * V_29 )
{
if ( F_29 ( & V_29 -> V_30 ) )
F_24 ( V_29 ) ;
}
void
F_30 ( struct V_28 * V_29 )
{
struct V_31 * V_31 = V_29 -> V_36 ;
if ( F_31 ( & V_29 -> V_30 , & V_31 -> V_40 ) ) {
F_24 ( V_29 ) ;
F_6 ( & V_31 -> V_40 ) ;
}
}
static void
F_32 ( struct V_28 * V_29 , struct V_41 * V_42 )
{
F_33 ( & V_42 -> V_43 ) ;
F_34 ( & V_42 -> V_44 , 1 ) ;
F_35 () ;
F_36 ( V_45 , & V_42 -> V_46 ) ;
V_42 -> V_47 = V_29 ;
}
static void V_24 ( struct V_41 * V_42 )
{
struct V_31 * V_32 = V_42 -> V_47 -> V_36 ;
F_20 ( V_32 ) -> V_9 -> V_24 ( V_42 ) ;
F_30 ( F_27 ( V_32 ) -> V_39 ) ;
}
static void
F_37 ( struct V_41 * V_42 )
{
struct V_31 * V_31 = V_42 -> V_47 -> V_36 ;
F_38 ( F_39 ( V_45 , & V_42 -> V_46 ) ) ;
F_40 ( & V_42 -> V_43 ) ;
if ( F_26 ( & V_42 -> V_47 -> V_48 ) ) {
F_36 ( V_49 , & V_42 -> V_47 -> V_50 ) ;
F_28 ( V_42 -> V_47 ) ;
}
F_41 ( & F_20 ( V_31 ) -> V_51 ) ;
}
void
F_42 ( struct V_41 * V_42 )
{
struct V_31 * V_31 ;
if ( ! V_42 )
return;
F_3 ( L_15 , V_5 , V_42 ,
F_43 ( & V_42 -> V_44 ) ,
F_39 ( V_45 , & V_42 -> V_46 ) ) ;
V_31 = V_42 -> V_47 -> V_36 ;
if ( F_31 ( & V_42 -> V_44 , & V_31 -> V_40 ) ) {
F_44 ( V_52 ) ;
F_37 ( V_42 ) ;
F_14 ( & V_42 -> V_43 , & V_52 ) ;
F_6 ( & V_31 -> V_40 ) ;
F_45 ( & V_52 ) ;
}
}
static inline T_3
F_46 ( T_3 V_53 , T_3 V_54 )
{
T_3 V_55 ;
V_55 = V_53 + V_54 ;
return V_55 >= V_53 ? V_55 : V_56 ;
}
static inline T_3
F_47 ( T_3 V_53 , T_3 V_54 )
{
T_3 V_55 ;
F_25 ( ! V_54 ) ;
V_55 = V_53 + V_54 ;
return V_55 > V_53 ? V_55 - 1 : V_56 ;
}
static inline int
F_48 ( struct V_57 * V_58 ,
struct V_57 * V_59 )
{
T_3 V_60 = V_58 -> V_61 ;
T_3 V_62 = F_46 ( V_60 , V_58 -> V_63 ) ;
T_3 V_64 = V_59 -> V_61 ;
T_3 V_65 = F_46 ( V_64 , V_59 -> V_63 ) ;
return ( V_60 <= V_64 ) && ( V_62 >= V_65 ) ;
}
static inline int
F_49 ( struct V_57 * V_58 ,
struct V_57 * V_59 )
{
T_3 V_60 = V_58 -> V_61 ;
T_3 V_62 = F_46 ( V_60 , V_58 -> V_63 ) ;
T_3 V_64 = V_59 -> V_61 ;
T_3 V_65 = F_46 ( V_64 , V_59 -> V_63 ) ;
return ( V_62 == V_56 || V_62 > V_64 ) &&
( V_65 == V_56 || V_65 > V_60 ) ;
}
static bool
F_50 ( struct V_57 * V_66 ,
struct V_57 * V_67 )
{
return ( V_67 -> V_68 == V_69 ||
V_66 -> V_68 == V_67 -> V_68 ) &&
F_49 ( V_66 , V_67 ) ;
}
static int F_51 ( struct V_41 * V_42 ,
struct V_70 * V_71 )
{
int V_72 = 0 ;
if ( F_52 ( V_45 , & V_42 -> V_46 ) ) {
F_3 ( L_16 , V_5 , V_42 ,
F_43 ( & V_42 -> V_44 ) ) ;
if ( F_29 ( & V_42 -> V_44 ) ) {
F_37 ( V_42 ) ;
F_14 ( & V_42 -> V_43 , V_71 ) ;
V_72 = 1 ;
}
}
return V_72 ;
}
int
F_53 ( struct V_28 * V_29 ,
struct V_70 * V_71 ,
struct V_57 * V_67 )
{
struct V_41 * V_42 , * V_73 ;
int V_74 = 0 , V_75 = 0 ;
F_3 ( L_17 , V_5 , V_29 ) ;
if ( F_26 ( & V_29 -> V_48 ) ) {
if ( ! F_54 ( V_49 , & V_29 -> V_50 ) )
F_28 ( V_29 ) ;
return 0 ;
}
F_55 (lseg, next, &lo->plh_segs, pls_list)
if ( ! V_67 ||
F_50 ( & V_42 -> V_76 , V_67 ) ) {
F_3 ( L_18
L_19 , V_5 ,
V_42 , V_42 -> V_76 . V_68 , V_42 -> V_76 . V_61 ,
V_42 -> V_76 . V_63 ) ;
V_74 ++ ;
V_75 += F_51 ( V_42 , V_71 ) ;
}
F_3 ( L_20 , V_5 , V_74 - V_75 ) ;
return V_74 - V_75 ;
}
void
F_45 ( struct V_70 * V_52 )
{
struct V_41 * V_42 , * V_22 ;
struct V_28 * V_29 ;
if ( F_26 ( V_52 ) )
return;
V_29 = F_56 ( V_52 , struct V_41 ,
V_43 ) -> V_47 ;
if ( F_39 ( V_49 , & V_29 -> V_50 ) ) {
struct V_14 * V_77 ;
V_77 = F_20 ( V_29 -> V_36 ) -> V_14 ;
F_5 ( & V_77 -> V_78 ) ;
F_40 ( & V_29 -> V_38 ) ;
F_6 ( & V_77 -> V_78 ) ;
}
F_55 (lseg, tmp, free_me, pls_list) {
F_16 ( & V_42 -> V_43 ) ;
V_24 ( V_42 ) ;
}
}
void
F_57 ( struct V_79 * V_80 )
{
struct V_28 * V_29 ;
F_44 ( V_71 ) ;
F_5 ( & V_80 -> V_81 . V_40 ) ;
V_29 = V_80 -> V_39 ;
if ( V_29 ) {
V_29 -> V_82 ++ ;
F_53 ( V_29 , & V_71 , NULL ) ;
}
F_6 ( & V_80 -> V_81 . V_40 ) ;
F_45 ( & V_71 ) ;
}
void
F_58 ( struct V_14 * V_77 )
{
struct V_28 * V_29 ;
F_44 ( V_71 ) ;
F_5 ( & V_77 -> V_78 ) ;
F_59 ( & V_77 -> V_83 , & V_71 ) ;
F_6 ( & V_77 -> V_78 ) ;
while ( ! F_26 ( & V_71 ) ) {
V_29 = F_60 ( V_71 . V_73 , struct V_28 ,
V_38 ) ;
F_3 ( L_21 , V_5 ,
V_29 -> V_36 -> V_84 ) ;
F_40 ( & V_29 -> V_38 ) ;
F_57 ( F_27 ( V_29 -> V_36 ) ) ;
}
}
void
F_61 ( struct V_28 * V_29 , const T_4 * V_85 ,
bool V_86 )
{
T_1 V_87 , V_88 ;
V_87 = F_62 ( V_29 -> V_89 . V_90 . V_91 ) ;
V_88 = F_62 ( V_85 -> V_90 . V_91 ) ;
if ( ( int ) ( V_88 - V_87 ) > 0 ) {
memcpy ( & V_29 -> V_89 , & V_85 -> V_90 , sizeof( V_85 -> V_90 ) ) ;
if ( V_86 ) {
T_1 V_92 = F_62 ( V_85 -> V_90 . V_91 ) ;
if ( ( int ) ( V_92 - V_29 -> V_93 ) )
V_29 -> V_93 = V_92 ;
} else {
if ( F_63 ( ( V_88 - V_29 -> V_93 ) > ( 3 << 29 ) ) )
V_29 -> V_93 = V_88 - ( 1 << 30 ) ;
}
}
}
static bool
F_64 ( struct V_28 * V_29 , T_4 * V_90 ,
int V_94 )
{
if ( ( V_90 ) &&
( int ) ( V_29 -> V_93 - F_62 ( V_90 -> V_90 . V_91 ) ) >= 0 )
return true ;
return V_29 -> V_82 ||
F_39 ( V_49 , & V_29 -> V_50 ) ||
F_39 ( V_95 , & V_29 -> V_50 ) ||
( F_26 ( & V_29 -> V_48 ) &&
( F_43 ( & V_29 -> V_96 ) > V_94 ) ) ;
}
int
F_65 ( T_4 * V_97 , struct V_28 * V_29 ,
struct V_98 * V_99 )
{
int V_20 = 0 ;
F_3 ( L_22 , V_5 ) ;
F_5 ( & V_29 -> V_36 -> V_40 ) ;
if ( F_64 ( V_29 , NULL , 1 ) ) {
V_20 = - V_100 ;
} else if ( F_26 ( & V_29 -> V_48 ) ) {
int V_101 ;
do {
V_101 = F_66 ( & V_99 -> V_102 ) ;
memcpy ( V_97 -> V_103 , V_99 -> V_90 . V_103 ,
sizeof( V_99 -> V_90 . V_103 ) ) ;
} while ( F_67 ( & V_99 -> V_102 , V_101 ) );
} else
memcpy ( V_97 -> V_103 , V_29 -> V_89 . V_103 , sizeof( V_29 -> V_89 . V_103 ) ) ;
F_6 ( & V_29 -> V_36 -> V_40 ) ;
F_3 ( L_23 , V_5 ) ;
return V_20 ;
}
static struct V_41 *
F_68 ( struct V_28 * V_29 ,
struct V_104 * V_105 ,
struct V_57 * V_106 ,
T_2 V_33 )
{
struct V_31 * V_32 = V_29 -> V_36 ;
struct V_7 * V_11 = F_20 ( V_32 ) ;
struct V_107 * V_108 ;
struct V_41 * V_42 = NULL ;
struct V_109 * * V_110 = NULL ;
int V_111 ;
T_1 V_112 , V_113 ;
F_3 ( L_22 , V_5 ) ;
F_25 ( V_105 == NULL ) ;
V_108 = F_21 ( sizeof( * V_108 ) , V_33 ) ;
if ( V_108 == NULL )
return NULL ;
V_112 = V_11 -> V_14 -> V_114 -> V_115 . V_112 ;
V_113 = V_112 >> V_116 ;
V_110 = F_21 ( V_113 * sizeof( struct V_109 * ) , V_33 ) ;
if ( ! V_110 )
goto V_117;
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ ) {
V_110 [ V_111 ] = F_69 ( V_33 ) ;
if ( ! V_110 [ V_111 ] )
goto V_117;
}
V_108 -> args . V_118 = V_119 ;
if ( V_108 -> args . V_118 > V_106 -> V_63 )
V_108 -> args . V_118 = V_106 -> V_63 ;
V_108 -> args . V_120 = V_121 ;
V_108 -> args . V_106 = * V_106 ;
V_108 -> args . type = V_11 -> V_9 -> V_2 ;
V_108 -> args . V_31 = V_32 ;
V_108 -> args . V_105 = F_70 ( V_105 ) ;
V_108 -> args . V_39 . V_110 = V_110 ;
V_108 -> args . V_39 . V_122 = V_113 * V_123 ;
V_108 -> V_124 = & V_42 ;
V_108 -> V_33 = V_33 ;
F_71 ( V_108 ) ;
if ( ! V_42 ) {
F_36 ( F_72 ( V_106 -> V_68 ) , & V_29 -> V_50 ) ;
}
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ )
F_73 ( V_110 [ V_111 ] ) ;
F_23 ( V_110 ) ;
return V_42 ;
V_117:
if ( V_110 ) {
for ( V_111 = 0 ; V_111 < V_113 ; V_111 ++ ) {
if ( ! V_110 [ V_111 ] )
break;
F_73 ( V_110 [ V_111 ] ) ;
}
F_23 ( V_110 ) ;
}
F_23 ( V_108 ) ;
return NULL ;
}
int
F_74 ( struct V_31 * V_32 )
{
struct V_28 * V_29 = NULL ;
struct V_79 * V_80 = F_27 ( V_32 ) ;
F_44 ( V_71 ) ;
struct V_125 * V_126 ;
T_4 V_90 ;
int V_20 = 0 ;
F_3 ( L_22 , V_5 ) ;
F_5 ( & V_32 -> V_40 ) ;
V_29 = V_80 -> V_39 ;
if ( ! V_29 ) {
F_6 ( & V_32 -> V_40 ) ;
F_3 ( L_24 , V_5 ) ;
return V_20 ;
}
V_90 = V_80 -> V_39 -> V_89 ;
F_17 ( V_29 ) ;
F_53 ( V_29 , & V_71 , NULL ) ;
V_29 -> V_82 ++ ;
F_6 ( & V_32 -> V_40 ) ;
F_45 ( & V_71 ) ;
F_38 ( F_39 ( V_127 , & V_80 -> V_128 ) ) ;
V_126 = F_21 ( sizeof( * V_126 ) , V_129 ) ;
if ( F_63 ( V_126 == NULL ) ) {
V_20 = - V_130 ;
F_36 ( V_131 , & V_29 -> V_50 ) ;
F_36 ( V_132 , & V_29 -> V_50 ) ;
F_30 ( V_29 ) ;
goto V_4;
}
V_126 -> args . V_90 = V_90 ;
V_126 -> args . V_133 = F_20 ( V_32 ) -> V_9 -> V_2 ;
V_126 -> args . V_31 = V_32 ;
V_126 -> V_77 = F_20 ( V_32 ) -> V_14 ;
V_20 = F_75 ( V_126 ) ;
V_4:
F_3 ( L_25 , V_5 , V_20 ) ;
return V_20 ;
}
bool F_76 ( struct V_31 * V_32 )
{
struct V_28 * V_29 ;
struct V_41 * V_42 , * V_22 ;
F_44 ( V_71 ) ;
bool V_134 = false ;
F_5 ( & V_32 -> V_40 ) ;
V_29 = F_27 ( V_32 ) -> V_39 ;
if ( ! V_29 || ! F_52 ( V_135 , & V_29 -> V_50 ) ||
F_39 ( V_95 , & V_29 -> V_50 ) )
goto V_136;
F_55 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_39 ( V_137 , & V_42 -> V_46 ) ) {
F_51 ( V_42 , & V_71 ) ;
V_134 = true ;
}
if ( ! V_134 )
goto V_136;
V_29 -> V_82 ++ ;
F_17 ( V_29 ) ;
F_6 ( & V_32 -> V_40 ) ;
F_45 ( & V_71 ) ;
return true ;
V_136:
F_6 ( & V_32 -> V_40 ) ;
return false ;
}
void F_77 ( struct V_31 * V_32 )
{
struct V_28 * V_29 ;
F_5 ( & V_32 -> V_40 ) ;
V_29 = F_27 ( V_32 ) -> V_39 ;
V_29 -> V_82 -- ;
F_28 ( V_29 ) ;
F_6 ( & V_32 -> V_40 ) ;
}
void F_78 ( struct V_31 * V_32 , T_1 V_138 )
{
struct V_28 * V_29 ;
F_5 ( & V_32 -> V_40 ) ;
V_29 = F_27 ( V_32 ) -> V_39 ;
if ( ( int ) ( V_138 - V_29 -> V_93 ) > 0 )
V_29 -> V_93 = V_138 ;
F_6 ( & V_32 -> V_40 ) ;
}
bool F_79 ( struct V_31 * V_32 , T_1 * V_138 )
{
struct V_79 * V_80 = F_27 ( V_32 ) ;
struct V_41 * V_42 ;
bool V_134 = false ;
F_5 ( & V_32 -> V_40 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_39 ( V_137 , & V_42 -> V_46 ) ) {
V_134 = true ;
break;
}
if ( ! V_134 ) {
struct V_28 * V_29 = V_80 -> V_39 ;
T_1 V_139 = F_62 ( V_29 -> V_89 . V_90 . V_91 ) ;
* V_138 = V_139 + F_43 ( & V_29 -> V_96 ) ;
}
F_6 ( & V_32 -> V_40 ) ;
return V_134 ;
}
static T_5
F_80 ( struct V_57 * V_58 ,
struct V_57 * V_59 )
{
T_5 V_140 ;
V_140 = V_58 -> V_61 - V_59 -> V_61 ;
if ( V_140 )
return V_140 ;
V_140 = V_59 -> V_63 - V_58 -> V_63 ;
if ( V_140 )
return V_140 ;
return ( int ) ( V_58 -> V_68 == V_141 ) - ( int ) ( V_59 -> V_68 == V_141 ) ;
}
static void
F_81 ( struct V_28 * V_29 ,
struct V_41 * V_42 )
{
struct V_41 * V_142 ;
F_3 ( L_26 , V_5 ) ;
F_82 ( & V_29 -> V_36 -> V_40 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_80 ( & V_42 -> V_76 , & V_142 -> V_76 ) > 0 )
continue;
F_83 ( & V_42 -> V_43 , & V_142 -> V_43 ) ;
F_3 ( L_27
L_28
L_29 ,
V_5 , V_42 , V_42 -> V_76 . V_68 ,
V_42 -> V_76 . V_61 , V_42 -> V_76 . V_63 ,
V_142 , V_142 -> V_76 . V_68 , V_142 -> V_76 . V_61 ,
V_142 -> V_76 . V_63 ) ;
goto V_4;
}
F_83 ( & V_42 -> V_43 , & V_29 -> V_48 ) ;
F_3 ( L_27
L_30 ,
V_5 , V_42 , V_42 -> V_76 . V_68 ,
V_42 -> V_76 . V_61 , V_42 -> V_76 . V_63 ) ;
V_4:
F_17 ( V_29 ) ;
F_3 ( L_31 , V_5 ) ;
}
static struct V_28 *
F_84 ( struct V_31 * V_32 , T_2 V_33 )
{
struct V_28 * V_29 ;
V_29 = F_19 ( V_32 , V_33 ) ;
if ( ! V_29 )
return NULL ;
F_34 ( & V_29 -> V_30 , 1 ) ;
F_33 ( & V_29 -> V_38 ) ;
F_33 ( & V_29 -> V_48 ) ;
F_33 ( & V_29 -> V_143 ) ;
V_29 -> V_36 = V_32 ;
return V_29 ;
}
static struct V_28 *
F_85 ( struct V_31 * V_32 , T_2 V_33 )
{
struct V_79 * V_80 = F_27 ( V_32 ) ;
struct V_28 * V_85 = NULL ;
F_3 ( L_32 , V_5 , V_32 , V_80 -> V_39 ) ;
F_82 ( & V_32 -> V_40 ) ;
if ( V_80 -> V_39 ) {
if ( F_39 ( V_49 , & V_80 -> V_39 -> V_50 ) )
return NULL ;
else
return V_80 -> V_39 ;
}
F_6 ( & V_32 -> V_40 ) ;
V_85 = F_84 ( V_32 , V_33 ) ;
F_5 ( & V_32 -> V_40 ) ;
if ( F_86 ( V_80 -> V_39 == NULL ) )
V_80 -> V_39 = V_85 ;
else
F_22 ( V_85 ) ;
return V_80 -> V_39 ;
}
static int
F_87 ( struct V_57 * V_144 ,
struct V_57 * V_106 )
{
struct V_57 V_145 ;
if ( ( V_106 -> V_68 == V_146 &&
V_144 -> V_68 != V_146 ) ||
! F_49 ( V_144 , V_106 ) )
return 0 ;
V_145 = * V_106 ;
V_145 . V_63 = 1 ;
return F_48 ( V_144 , & V_145 ) ;
}
static struct V_41 *
F_88 ( struct V_28 * V_29 ,
struct V_57 * V_106 )
{
struct V_41 * V_42 , * V_147 = NULL ;
F_3 ( L_26 , V_5 ) ;
F_82 ( & V_29 -> V_36 -> V_40 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_39 ( V_45 , & V_42 -> V_46 ) &&
F_87 ( & V_42 -> V_76 , V_106 ) ) {
V_147 = F_89 ( V_42 ) ;
break;
}
if ( V_42 -> V_76 . V_61 > V_106 -> V_61 )
break;
}
F_3 ( L_33 ,
V_5 , V_147 , V_147 ? F_43 ( & V_147 -> V_44 ) : 0 ) ;
return V_147 ;
}
struct V_41 *
F_90 ( struct V_31 * V_32 ,
struct V_104 * V_105 ,
T_6 V_148 ,
T_3 V_149 ,
enum V_150 V_68 ,
T_2 V_33 )
{
struct V_57 V_151 = {
. V_68 = V_68 ,
. V_61 = V_148 ,
. V_63 = V_149 ,
} ;
unsigned V_152 ;
struct V_79 * V_80 = F_27 ( V_32 ) ;
struct V_14 * V_77 = F_20 ( V_32 ) -> V_14 ;
struct V_28 * V_29 ;
struct V_41 * V_42 = NULL ;
bool V_153 = false ;
if ( ! F_91 ( F_20 ( V_32 ) ) )
return NULL ;
F_5 ( & V_32 -> V_40 ) ;
V_29 = F_85 ( V_32 , V_33 ) ;
if ( V_29 == NULL ) {
F_3 ( L_34 , V_5 ) ;
goto V_154;
}
if ( F_39 ( V_155 , & V_77 -> V_156 ) ||
F_39 ( V_95 , & V_29 -> V_50 ) ) {
F_3 ( L_35 , V_5 ) ;
goto V_154;
}
if ( F_39 ( F_72 ( V_68 ) , & V_80 -> V_39 -> V_50 ) )
goto V_154;
V_42 = F_88 ( V_29 , & V_151 ) ;
if ( V_42 )
goto V_154;
if ( F_64 ( V_29 , NULL , 0 ) )
goto V_154;
F_18 ( & V_29 -> V_96 ) ;
F_17 ( V_29 ) ;
if ( F_26 ( & V_29 -> V_48 ) )
V_153 = true ;
F_6 ( & V_32 -> V_40 ) ;
if ( V_153 ) {
F_5 ( & V_77 -> V_78 ) ;
F_25 ( ! F_26 ( & V_29 -> V_38 ) ) ;
F_83 ( & V_29 -> V_38 , & V_77 -> V_83 ) ;
F_6 ( & V_77 -> V_78 ) ;
}
V_152 = V_151 . V_61 & ~ V_157 ;
if ( V_152 ) {
V_151 . V_61 -= V_152 ;
V_151 . V_63 += V_152 ;
}
V_151 . V_63 = F_92 ( V_151 . V_63 ) ;
V_42 = F_68 ( V_29 , V_105 , & V_151 , V_33 ) ;
if ( ! V_42 && V_153 ) {
F_5 ( & V_77 -> V_78 ) ;
F_40 ( & V_29 -> V_38 ) ;
F_6 ( & V_77 -> V_78 ) ;
}
F_93 ( & V_29 -> V_96 ) ;
F_30 ( V_29 ) ;
V_4:
F_3 ( L_36 , V_5 ,
V_80 -> V_39 ? V_80 -> V_39 -> V_50 : - 1 , V_42 ) ;
return V_42 ;
V_154:
F_6 ( & V_32 -> V_40 ) ;
goto V_4;
}
int
F_94 ( struct V_107 * V_108 )
{
struct V_28 * V_29 = F_27 ( V_108 -> args . V_31 ) -> V_39 ;
struct V_158 * V_159 = & V_108 -> V_159 ;
struct V_41 * V_42 ;
struct V_31 * V_32 = V_29 -> V_36 ;
struct V_14 * V_77 = F_20 ( V_32 ) -> V_14 ;
int V_20 = 0 ;
V_42 = F_20 ( V_32 ) -> V_9 -> V_23 ( V_29 , V_159 , V_108 -> V_33 ) ;
if ( ! V_42 || F_95 ( V_42 ) ) {
if ( ! V_42 )
V_20 = - V_130 ;
else
V_20 = F_96 ( V_42 ) ;
F_3 ( L_37 ,
V_5 , V_20 ) ;
goto V_4;
}
F_5 ( & V_32 -> V_40 ) ;
if ( F_39 ( V_155 , & V_77 -> V_156 ) ||
F_39 ( V_95 , & V_29 -> V_50 ) ) {
F_3 ( L_38 , V_5 ) ;
goto V_160;
}
if ( F_64 ( V_29 , & V_159 -> V_90 , 1 ) ) {
F_3 ( L_39 , V_5 ) ;
goto V_160;
}
F_32 ( V_29 , V_42 ) ;
V_42 -> V_76 = V_159 -> V_106 ;
* V_108 -> V_124 = F_89 ( V_42 ) ;
F_81 ( V_29 , V_42 ) ;
if ( V_159 -> V_161 ) {
F_36 ( V_137 , & V_42 -> V_46 ) ;
F_36 ( V_135 , & V_29 -> V_50 ) ;
}
F_61 ( V_29 , & V_159 -> V_90 , false ) ;
F_6 ( & V_32 -> V_40 ) ;
V_4:
return V_20 ;
V_160:
F_6 ( & V_32 -> V_40 ) ;
V_42 -> V_47 = V_29 ;
F_20 ( V_32 ) -> V_9 -> V_24 ( V_42 ) ;
goto V_4;
}
bool
F_97 ( struct V_162 * V_163 , struct V_164 * V_165 ,
struct V_164 * V_166 )
{
enum V_150 V_167 ;
T_2 V_33 ;
if ( V_163 -> V_168 == 0 ) {
V_167 = V_141 ;
V_33 = V_129 ;
} else {
V_167 = V_146 ;
V_33 = V_169 ;
}
if ( V_163 -> V_170 == NULL ) {
if ( V_163 -> V_171 != V_165 -> V_172 )
return true ;
V_163 -> V_170 = F_90 ( V_163 -> V_173 ,
V_165 -> V_174 ,
F_98 ( V_165 ) ,
V_163 -> V_171 ,
V_167 ,
V_33 ) ;
if ( V_163 -> V_170 == NULL )
return true ;
}
return F_98 ( V_166 ) < F_46 ( V_163 -> V_170 -> V_76 . V_61 ,
V_163 -> V_170 -> V_76 . V_63 ) ;
}
int
F_99 ( struct V_175 * V_103 )
{
int V_20 ;
if ( ! V_103 -> V_176 ) {
F_100 ( V_103 ) ;
V_103 -> V_177 -> V_178 ( & V_103 -> V_179 , V_103 ) ;
V_103 -> V_177 -> V_180 ( V_103 ) ;
return 0 ;
}
F_3 ( L_40 , V_5 ,
V_103 -> V_176 ) ;
V_20 = F_101 ( V_103 , F_102 ( V_103 -> V_31 ) ,
V_103 -> V_177 , V_181 ) ;
return V_20 ? : - V_100 ;
}
enum V_182
F_103 ( struct V_175 * V_183 ,
const struct V_184 * V_185 , int V_186 )
{
struct V_31 * V_31 = V_183 -> V_31 ;
enum V_182 V_187 ;
struct V_7 * V_8 = F_20 ( V_31 ) ;
V_183 -> V_177 = V_185 ;
F_3 ( L_41 , V_5 ,
V_31 -> V_84 , V_183 -> args . V_149 , V_183 -> args . V_61 , V_186 ) ;
V_187 = V_8 -> V_9 -> V_188 ( V_183 , V_186 ) ;
if ( V_187 == V_189 ) {
F_42 ( V_183 -> V_42 ) ;
V_183 -> V_42 = NULL ;
} else
F_104 ( V_31 , V_190 ) ;
F_3 ( L_42 , V_5 , V_187 ) ;
return V_187 ;
}
int
F_105 ( struct V_191 * V_103 )
{
int V_20 ;
if ( ! V_103 -> V_176 ) {
F_106 ( V_103 ) ;
V_103 -> V_177 -> V_178 ( & V_103 -> V_179 , V_103 ) ;
V_103 -> V_177 -> V_180 ( V_103 ) ;
return 0 ;
}
F_3 ( L_40 , V_5 ,
V_103 -> V_176 ) ;
V_20 = F_107 ( V_103 , F_102 ( V_103 -> V_31 ) ,
V_103 -> V_177 ) ;
return V_20 ? : - V_100 ;
}
enum V_182
F_108 ( struct V_191 * V_192 ,
const struct V_184 * V_185 )
{
struct V_31 * V_31 = V_192 -> V_31 ;
struct V_7 * V_8 = F_20 ( V_31 ) ;
enum V_182 V_187 ;
V_192 -> V_177 = V_185 ;
F_3 ( L_43 ,
V_5 , V_31 -> V_84 , V_192 -> args . V_149 , V_192 -> args . V_61 ) ;
V_187 = V_8 -> V_9 -> V_193 ( V_192 ) ;
if ( V_187 == V_189 ) {
F_42 ( V_192 -> V_42 ) ;
V_192 -> V_42 = NULL ;
} else {
F_104 ( V_31 , V_194 ) ;
}
F_3 ( L_42 , V_5 , V_187 ) ;
return V_187 ;
}
static struct V_41 * F_109 ( struct V_31 * V_31 )
{
struct V_41 * V_42 , * V_72 = NULL ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list)
if ( V_42 -> V_76 . V_68 == V_146 )
V_72 = V_42 ;
return V_72 ;
}
void
F_100 ( struct V_175 * V_183 )
{
struct V_79 * V_80 = F_27 ( V_183 -> V_31 ) ;
T_6 V_195 = V_183 -> V_196 + V_183 -> V_159 . V_149 ;
bool V_197 = false ;
F_5 ( & V_80 -> V_81 . V_40 ) ;
if ( ! F_54 ( V_127 , & V_80 -> V_128 ) ) {
F_89 ( V_183 -> V_42 ) ;
V_183 -> V_42 -> V_198 =
F_110 ( V_183 -> args . V_199 -> V_200 -> V_10 -> V_201 ) ;
V_197 = true ;
F_3 ( L_44 ,
V_5 , V_183 -> V_31 -> V_84 ) ;
}
if ( V_195 > V_183 -> V_42 -> V_202 )
V_183 -> V_42 -> V_202 = V_195 ;
F_6 ( & V_80 -> V_81 . V_40 ) ;
if ( V_197 )
F_111 ( V_183 -> V_31 ) ;
}
int
F_112 ( struct V_31 * V_31 , bool V_203 )
{
struct V_204 * V_103 ;
struct V_79 * V_80 = F_27 ( V_31 ) ;
struct V_41 * V_42 ;
struct V_205 * V_206 ;
T_6 V_195 ;
int V_20 = 0 ;
F_3 ( L_45 , V_5 , V_31 -> V_84 ) ;
if ( ! F_39 ( V_127 , & V_80 -> V_128 ) )
return 0 ;
V_103 = F_21 ( sizeof( * V_103 ) , V_169 ) ;
if ( ! V_103 ) {
F_111 ( V_31 ) ;
V_20 = - V_130 ;
goto V_4;
}
F_5 ( & V_31 -> V_40 ) ;
if ( ! F_52 ( V_127 , & V_80 -> V_128 ) ) {
F_6 ( & V_31 -> V_40 ) ;
F_23 ( V_103 ) ;
goto V_4;
}
V_42 = F_109 ( V_31 ) ;
V_195 = V_42 -> V_202 ;
V_206 = V_42 -> V_198 ;
V_42 -> V_202 = 0 ;
V_42 -> V_198 = NULL ;
memcpy ( & V_103 -> args . V_90 . V_103 , V_80 -> V_39 -> V_89 . V_103 ,
sizeof( V_80 -> V_39 -> V_89 . V_103 ) ) ;
F_6 ( & V_31 -> V_40 ) ;
V_103 -> args . V_31 = V_31 ;
V_103 -> V_42 = V_42 ;
V_103 -> V_206 = V_206 ;
F_113 ( & V_103 -> V_207 ) ;
V_103 -> args . V_208 = F_20 ( V_31 ) -> V_209 ;
V_103 -> V_159 . V_207 = & V_103 -> V_207 ;
V_103 -> args . V_210 = V_195 - 1 ;
V_103 -> V_159 . V_11 = F_20 ( V_31 ) ;
V_20 = F_114 ( V_103 , V_203 ) ;
V_4:
F_3 ( L_46 , V_5 , V_20 ) ;
return V_20 ;
}
