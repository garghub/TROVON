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
F_3 ( L_24 , V_5 ) ;
F_28 ( V_113 == NULL ) ;
V_116 = F_23 ( sizeof( * V_116 ) , V_38 ) ;
if ( V_116 == NULL )
return NULL ;
V_116 -> args . V_117 = V_118 ;
if ( V_116 -> args . V_117 > V_114 -> V_70 )
V_116 -> args . V_117 = V_114 -> V_70 ;
V_116 -> args . V_119 = V_120 ;
V_116 -> args . V_114 = * V_114 ;
V_116 -> args . type = V_14 -> V_10 -> V_2 ;
V_116 -> args . V_36 = V_37 ;
V_116 -> args . V_113 = F_76 ( V_113 ) ;
V_116 -> V_121 = & V_48 ;
V_116 -> V_38 = V_38 ;
F_77 ( V_116 , V_38 ) ;
if ( ! V_48 ) {
F_38 ( F_78 ( V_114 -> V_75 ) , & V_34 -> V_57 ) ;
}
return V_48 ;
}
int
F_79 ( struct V_36 * V_37 )
{
struct V_33 * V_34 = NULL ;
struct V_88 * V_89 = F_30 ( V_37 ) ;
F_46 ( V_78 ) ;
struct V_122 * V_123 ;
T_4 V_102 ;
int V_25 = 0 , V_124 ;
F_3 ( L_26 , V_5 , V_37 -> V_93 ) ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = V_89 -> V_45 ;
if ( ! V_34 || F_80 ( V_34 ) ) {
F_7 ( & V_37 -> V_46 ) ;
F_3 ( L_27 , V_5 ) ;
goto V_4;
}
V_102 = V_89 -> V_45 -> V_98 ;
F_20 ( V_34 ) ;
V_124 = F_29 ( & V_34 -> V_55 ) ;
F_55 ( V_34 , & V_78 , NULL ) ;
if ( V_124 ) {
F_7 ( & V_37 -> V_46 ) ;
F_32 ( V_34 ) ;
F_3 ( L_28 , V_5 ) ;
goto V_4;
}
V_34 -> V_91 ++ ;
F_81 ( V_34 ) ;
F_7 ( & V_37 -> V_46 ) ;
F_47 ( & V_78 ) ;
F_40 ( F_41 ( V_125 , & V_89 -> V_126 ) ) ;
V_123 = F_23 ( sizeof( * V_123 ) , V_127 ) ;
if ( F_70 ( V_123 == NULL ) ) {
V_25 = - V_128 ;
F_38 ( V_129 , & V_34 -> V_57 ) ;
F_38 ( V_130 , & V_34 -> V_57 ) ;
F_82 ( V_34 ) ;
F_32 ( V_34 ) ;
goto V_4;
}
V_123 -> args . V_102 = V_102 ;
V_123 -> args . V_131 = F_22 ( V_37 ) -> V_10 -> V_2 ;
V_123 -> args . V_36 = V_37 ;
V_123 -> args . V_45 = V_34 ;
V_123 -> V_86 = F_22 ( V_37 ) -> V_12 ;
V_25 = F_83 ( V_123 ) ;
V_4:
F_3 ( L_29 , V_5 , V_25 ) ;
return V_25 ;
}
bool F_84 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
struct V_47 * V_48 , * V_27 ;
F_46 ( V_78 ) ;
bool V_132 = false ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_30 ( V_37 ) -> V_45 ;
if ( ! V_34 || ! F_54 ( V_133 , & V_34 -> V_57 ) ||
F_41 ( V_104 , & V_34 -> V_57 ) )
goto V_134;
F_57 (lseg, tmp, &lo->plh_segs, pls_list)
if ( F_41 ( V_135 , & V_48 -> V_53 ) ) {
F_53 ( V_48 , & V_78 ) ;
V_132 = true ;
}
if ( ! V_132 )
goto V_134;
V_34 -> V_91 ++ ;
F_20 ( V_34 ) ;
F_7 ( & V_37 -> V_46 ) ;
F_47 ( & V_78 ) ;
return true ;
V_134:
F_7 ( & V_37 -> V_46 ) ;
return false ;
}
void F_85 ( struct V_36 * V_37 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_30 ( V_37 ) -> V_45 ;
V_34 -> V_91 -- ;
F_31 ( V_34 ) ;
F_7 ( & V_37 -> V_46 ) ;
}
void F_86 ( struct V_36 * V_37 , T_1 V_136 )
{
struct V_33 * V_34 ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_30 ( V_37 ) -> V_45 ;
if ( ( int ) ( V_136 - V_34 -> V_101 ) > 0 )
V_34 -> V_101 = V_136 ;
F_7 ( & V_37 -> V_46 ) ;
}
bool F_87 ( struct V_36 * V_37 , T_1 * V_136 )
{
struct V_88 * V_89 = F_30 ( V_37 ) ;
struct V_47 * V_48 ;
bool V_132 = false ;
F_5 ( & V_37 -> V_46 ) ;
F_2 (lseg, &nfsi->layout->plh_segs, pls_list)
if ( F_41 ( V_135 , & V_48 -> V_53 ) ) {
V_132 = true ;
break;
}
if ( ! V_132 ) {
struct V_33 * V_34 = V_89 -> V_45 ;
T_1 V_137 = F_68 ( V_34 -> V_98 . V_99 ) ;
* V_136 = V_137 + F_45 ( & V_34 -> V_105 ) ;
}
F_7 ( & V_37 -> V_46 ) ;
return V_132 ;
}
static T_5
F_88 ( struct V_64 * V_65 ,
struct V_64 * V_66 )
{
T_5 V_138 ;
V_138 = V_65 -> V_68 - V_66 -> V_68 ;
if ( V_138 )
return V_138 ;
V_138 = V_66 -> V_70 - V_65 -> V_70 ;
if ( V_138 )
return V_138 ;
return ( int ) ( V_65 -> V_75 == V_139 ) - ( int ) ( V_66 -> V_75 == V_139 ) ;
}
static void
F_89 ( struct V_33 * V_34 ,
struct V_47 * V_48 )
{
struct V_47 * V_140 ;
F_3 ( L_30 , V_5 ) ;
F_90 ( & V_34 -> V_41 -> V_46 ) ;
F_2 (lp, &lo->plh_segs, pls_list) {
if ( F_88 ( & V_48 -> V_85 , & V_140 -> V_85 ) > 0 )
continue;
F_91 ( & V_48 -> V_49 , & V_140 -> V_49 ) ;
F_3 ( L_31
L_32
L_33 ,
V_5 , V_48 , V_48 -> V_85 . V_75 ,
V_48 -> V_85 . V_68 , V_48 -> V_85 . V_70 ,
V_140 , V_140 -> V_85 . V_75 , V_140 -> V_85 . V_68 ,
V_140 -> V_85 . V_70 ) ;
goto V_4;
}
F_91 ( & V_48 -> V_49 , & V_34 -> V_55 ) ;
F_3 ( L_31
L_34 ,
V_5 , V_48 , V_48 -> V_85 . V_75 ,
V_48 -> V_85 . V_68 , V_48 -> V_85 . V_70 ) ;
V_4:
F_20 ( V_34 ) ;
F_3 ( L_35 , V_5 ) ;
}
static struct V_33 *
F_92 ( struct V_36 * V_37 ,
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
F_35 ( & V_34 -> V_141 ) ;
V_34 -> V_41 = V_37 ;
V_34 -> V_42 = F_93 ( V_113 -> V_142 -> V_7 -> V_143 ) ;
return V_34 ;
}
static struct V_33 *
F_94 ( struct V_36 * V_37 ,
struct V_112 * V_113 ,
T_2 V_38 )
{
struct V_88 * V_89 = F_30 ( V_37 ) ;
struct V_33 * V_94 = NULL ;
F_3 ( L_36 , V_5 , V_37 , V_89 -> V_45 ) ;
F_90 ( & V_37 -> V_46 ) ;
if ( V_89 -> V_45 ) {
if ( F_41 ( V_56 , & V_89 -> V_45 -> V_57 ) )
return NULL ;
else
return V_89 -> V_45 ;
}
F_7 ( & V_37 -> V_46 ) ;
V_94 = F_92 ( V_37 , V_113 , V_38 ) ;
F_5 ( & V_37 -> V_46 ) ;
if ( F_95 ( V_89 -> V_45 == NULL ) )
V_89 -> V_45 = V_94 ;
else
F_24 ( V_94 ) ;
return V_89 -> V_45 ;
}
static int
F_96 ( struct V_64 * V_144 ,
struct V_64 * V_114 )
{
struct V_64 V_145 ;
if ( ( V_114 -> V_75 == V_146 &&
V_144 -> V_75 != V_146 ) ||
! F_51 ( V_144 , V_114 ) )
return 0 ;
V_145 = * V_114 ;
V_145 . V_70 = 1 ;
return F_50 ( V_144 , & V_145 ) ;
}
static struct V_47 *
F_97 ( struct V_33 * V_34 ,
struct V_64 * V_114 )
{
struct V_47 * V_48 , * V_147 = NULL ;
F_3 ( L_30 , V_5 ) ;
F_90 ( & V_34 -> V_41 -> V_46 ) ;
F_2 (lseg, &lo->plh_segs, pls_list) {
if ( F_41 ( V_52 , & V_48 -> V_53 ) &&
F_96 ( & V_48 -> V_85 , V_114 ) ) {
V_147 = F_98 ( V_48 ) ;
break;
}
if ( V_48 -> V_85 . V_68 > V_114 -> V_68 )
break;
}
F_3 ( L_37 ,
V_5 , V_147 , V_147 ? F_45 ( & V_147 -> V_51 ) : 0 ) ;
return V_147 ;
}
static bool F_99 ( struct V_112 * V_113 ,
struct V_36 * V_37 , int V_75 )
{
struct V_148 * V_149 = V_113 -> V_150 ;
struct V_88 * V_89 = F_30 ( V_37 ) ;
T_6 V_151 = F_100 ( V_37 ) ;
bool V_152 = false , V_153 = false , V_154 = false , V_155 = false , V_147 = false ;
if ( V_149 == NULL )
return V_147 ;
F_3 ( L_38 ,
V_5 , V_149 -> V_156 , V_149 -> V_157 , V_149 -> V_158 , V_149 -> V_159 , V_149 -> V_160 ) ;
switch ( V_75 ) {
case V_139 :
if ( V_149 -> V_156 & V_161 ) {
F_3 ( L_39 , V_5 , V_151 ) ;
V_153 = true ;
if ( V_151 < V_149 -> V_157 )
V_152 = true ;
}
if ( V_149 -> V_156 & V_162 ) {
F_3 ( L_40 , V_5 ,
V_89 -> V_84 ) ;
V_155 = true ;
if ( V_89 -> V_84 < V_149 -> V_159 )
V_154 = true ;
}
break;
case V_146 :
if ( V_149 -> V_156 & V_163 ) {
F_3 ( L_39 , V_5 , V_151 ) ;
V_153 = true ;
if ( V_151 < V_149 -> V_158 )
V_152 = true ;
}
if ( V_149 -> V_156 & V_164 ) {
F_3 ( L_41 , V_5 ,
V_89 -> V_83 ) ;
V_155 = true ;
if ( V_89 -> V_83 < V_149 -> V_160 )
V_154 = true ;
}
break;
}
if ( V_153 && V_155 ) {
if ( V_152 && V_154 )
V_147 = true ;
} else if ( V_152 || V_154 )
V_147 = true ;
F_3 ( L_42 , V_5 , V_152 , V_154 , V_147 ) ;
return V_147 ;
}
struct V_47 *
F_101 ( struct V_36 * V_37 ,
struct V_112 * V_113 ,
T_6 V_165 ,
T_3 V_166 ,
enum V_167 V_75 ,
T_2 V_38 )
{
struct V_64 V_168 = {
. V_75 = V_75 ,
. V_68 = V_165 ,
. V_70 = V_166 ,
} ;
unsigned V_169 ;
struct V_88 * V_89 = F_30 ( V_37 ) ;
struct V_8 * V_14 = F_22 ( V_37 ) ;
struct V_12 * V_86 = V_14 -> V_12 ;
struct V_33 * V_34 ;
struct V_47 * V_48 = NULL ;
bool V_170 = false ;
if ( ! F_102 ( F_22 ( V_37 ) ) )
return NULL ;
if ( F_99 ( V_113 , V_37 , V_75 ) )
return NULL ;
F_5 ( & V_37 -> V_46 ) ;
V_34 = F_94 ( V_37 , V_113 , V_38 ) ;
if ( V_34 == NULL ) {
F_3 ( L_43 , V_5 ) ;
goto V_171;
}
if ( F_41 ( V_104 , & V_34 -> V_57 ) ) {
F_3 ( L_44 , V_5 ) ;
goto V_171;
}
if ( F_41 ( F_78 ( V_75 ) , & V_89 -> V_45 -> V_57 ) )
goto V_171;
V_48 = F_97 ( V_34 , & V_168 ) ;
if ( V_48 )
goto V_171;
if ( F_71 ( V_34 , NULL , 0 ) )
goto V_171;
F_15 ( & V_34 -> V_105 ) ;
F_20 ( V_34 ) ;
if ( F_29 ( & V_34 -> V_55 ) )
V_170 = true ;
F_82 ( V_34 ) ;
F_7 ( & V_37 -> V_46 ) ;
if ( V_170 ) {
F_5 ( & V_86 -> V_87 ) ;
F_28 ( ! F_29 ( & V_34 -> V_44 ) ) ;
F_91 ( & V_34 -> V_44 , & V_14 -> V_92 ) ;
F_7 ( & V_86 -> V_87 ) ;
}
V_169 = V_168 . V_68 & ~ V_172 ;
if ( V_169 ) {
V_168 . V_68 -= V_169 ;
V_168 . V_70 += V_169 ;
}
if ( V_168 . V_70 != V_63 )
V_168 . V_70 = F_103 ( V_168 . V_70 ) ;
V_48 = F_75 ( V_34 , V_113 , & V_168 , V_38 ) ;
if ( ! V_48 && V_170 ) {
F_5 ( & V_86 -> V_87 ) ;
F_42 ( & V_34 -> V_44 ) ;
F_7 ( & V_86 -> V_87 ) ;
}
F_104 ( & V_34 -> V_105 ) ;
F_32 ( V_34 ) ;
V_4:
F_3 ( L_45 , V_5 ,
V_89 -> V_45 ? V_89 -> V_45 -> V_57 : - 1 , V_48 ) ;
return V_48 ;
V_171:
F_7 ( & V_37 -> V_46 ) ;
goto V_4;
}
int
F_105 ( struct V_115 * V_116 )
{
struct V_33 * V_34 = F_30 ( V_116 -> args . V_36 ) -> V_45 ;
struct V_173 * V_174 = & V_116 -> V_174 ;
struct V_47 * V_48 ;
struct V_36 * V_37 = V_34 -> V_41 ;
int V_25 = 0 ;
V_48 = F_22 ( V_37 ) -> V_10 -> V_28 ( V_34 , V_174 , V_116 -> V_38 ) ;
if ( ! V_48 || F_106 ( V_48 ) ) {
if ( ! V_48 )
V_25 = - V_128 ;
else
V_25 = F_107 ( V_48 ) ;
F_3 ( L_46 ,
V_5 , V_25 ) ;
goto V_4;
}
F_5 ( & V_37 -> V_46 ) ;
if ( F_41 ( V_104 , & V_34 -> V_57 ) ) {
F_3 ( L_47 , V_5 ) ;
goto V_175;
}
if ( F_71 ( V_34 , & V_174 -> V_102 , 1 ) ) {
F_3 ( L_48 , V_5 ) ;
goto V_175;
}
F_34 ( V_34 , V_48 ) ;
V_48 -> V_85 = V_174 -> V_114 ;
* V_116 -> V_121 = F_98 ( V_48 ) ;
F_89 ( V_34 , V_48 ) ;
if ( V_174 -> V_176 ) {
F_38 ( V_135 , & V_48 -> V_53 ) ;
F_38 ( V_133 , & V_34 -> V_57 ) ;
}
F_67 ( V_34 , & V_174 -> V_102 , false ) ;
F_7 ( & V_37 -> V_46 ) ;
V_4:
return V_25 ;
V_175:
F_7 ( & V_37 -> V_46 ) ;
V_48 -> V_54 = V_34 ;
F_22 ( V_37 ) -> V_10 -> V_29 ( V_48 ) ;
goto V_4;
}
void
F_108 ( struct V_177 * V_178 , struct V_179 * V_180 )
{
F_28 ( V_178 -> V_181 != NULL ) ;
if ( V_180 -> V_182 != V_180 -> V_183 ) {
F_109 ( V_178 ) ;
return;
}
V_178 -> V_181 = F_101 ( V_178 -> V_184 ,
V_180 -> V_185 ,
F_110 ( V_180 ) ,
V_180 -> V_186 ,
V_139 ,
V_127 ) ;
if ( V_178 -> V_181 == NULL )
F_109 ( V_178 ) ;
}
void
F_111 ( struct V_177 * V_178 , struct V_179 * V_180 )
{
F_28 ( V_178 -> V_181 != NULL ) ;
if ( V_180 -> V_182 != V_180 -> V_183 ) {
F_112 ( V_178 ) ;
return;
}
V_178 -> V_181 = F_101 ( V_178 -> V_184 ,
V_180 -> V_185 ,
F_110 ( V_180 ) ,
V_180 -> V_186 ,
V_146 ,
V_187 ) ;
if ( V_178 -> V_181 == NULL )
F_112 ( V_178 ) ;
}
void
F_113 ( struct V_177 * V_178 , struct V_36 * V_36 ,
const struct V_188 * V_189 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_114 ( V_178 , V_36 , V_189 ) ;
else
F_115 ( V_178 , V_36 , V_39 -> V_190 , V_189 , V_14 -> V_191 , 0 ) ;
}
void
F_116 ( struct V_177 * V_178 , struct V_36 * V_36 ,
int V_192 ,
const struct V_188 * V_189 )
{
struct V_8 * V_14 = F_22 ( V_36 ) ;
struct V_1 * V_39 = V_14 -> V_10 ;
if ( V_39 == NULL )
F_117 ( V_178 , V_36 , V_192 , V_189 ) ;
else
F_115 ( V_178 , V_36 , V_39 -> V_193 , V_189 , V_14 -> V_194 , V_192 ) ;
}
bool
F_118 ( struct V_177 * V_178 , struct V_179 * V_195 ,
struct V_179 * V_180 )
{
if ( V_178 -> V_181 == NULL )
return F_119 ( V_178 , V_195 , V_180 ) ;
return F_110 ( V_180 ) < F_48 ( V_178 -> V_181 -> V_85 . V_68 ,
V_178 -> V_181 -> V_85 . V_70 ) ;
}
int F_120 ( struct V_36 * V_36 ,
struct V_77 * V_196 ,
const struct V_188 * V_189 )
{
struct V_177 V_178 ;
F_46 ( V_197 ) ;
F_117 ( & V_178 , V_36 , V_198 , V_189 ) ;
while ( ! F_29 ( V_196 ) ) {
struct V_179 * V_180 = F_121 ( V_196 -> V_80 ) ;
F_122 ( V_180 ) ;
if ( ! F_123 ( & V_178 , V_180 ) )
F_124 ( V_180 , & V_197 ) ;
}
F_125 ( & V_178 ) ;
if ( ! F_29 ( & V_197 ) ) {
F_126 ( & V_197 , V_196 ) ;
return - V_199 ;
}
return 0 ;
}
static void F_127 ( struct V_200 * V_201 )
{
struct V_202 * V_203 = V_201 -> V_204 ;
F_3 ( L_49 , V_203 -> V_205 ) ;
if ( F_22 ( V_203 -> V_36 ) -> V_10 -> V_126 &
V_206 ) {
F_128 ( V_125 , & F_30 ( V_203 -> V_36 ) -> V_126 ) ;
F_129 ( V_203 -> V_36 ) ;
}
if ( ! F_56 ( V_207 , & V_203 -> V_126 ) )
V_201 -> V_208 . V_209 = F_120 ( V_203 -> V_36 ,
& V_203 -> V_210 ,
V_203 -> V_211 ) ;
}
void F_130 ( struct V_200 * V_201 )
{
struct V_202 * V_203 = V_201 -> V_204 ;
if ( ! V_203 -> V_205 ) {
F_131 ( V_201 ) ;
V_203 -> V_212 -> V_213 ( & V_201 -> V_208 , V_201 ) ;
} else
F_127 ( V_201 ) ;
V_203 -> V_212 -> V_214 ( V_201 ) ;
}
static void
F_132 ( struct V_177 * V_215 ,
struct V_200 * V_201 )
{
struct V_202 * V_203 = V_201 -> V_204 ;
if ( ! F_56 ( V_207 , & V_203 -> V_126 ) ) {
F_133 ( & V_203 -> V_210 , & V_215 -> V_216 ) ;
F_112 ( V_215 ) ;
V_215 -> V_217 = 1 ;
}
F_134 ( V_201 ) ;
}
static enum V_218
F_135 ( struct V_200 * V_219 ,
const struct V_220 * V_221 ,
struct V_47 * V_48 ,
int V_222 )
{
struct V_202 * V_203 = V_219 -> V_204 ;
struct V_36 * V_36 = V_203 -> V_36 ;
enum V_218 V_223 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
V_203 -> V_212 = V_221 ;
F_3 ( L_50 , V_5 ,
V_36 -> V_93 , V_219 -> args . V_166 , V_219 -> args . V_68 , V_222 ) ;
V_223 = V_9 -> V_10 -> V_224 ( V_219 , V_222 ) ;
if ( V_223 != V_225 )
F_136 ( V_36 , V_226 ) ;
F_3 ( L_51 , V_5 , V_223 ) ;
return V_223 ;
}
static void
F_137 ( struct V_177 * V_215 , struct V_77 * V_196 , int V_222 )
{
struct V_200 * V_201 ;
const struct V_220 * V_221 = V_215 -> V_227 ;
struct V_47 * V_48 = V_215 -> V_181 ;
V_215 -> V_181 = NULL ;
while ( ! F_29 ( V_196 ) ) {
enum V_218 V_223 ;
V_201 = F_58 ( V_196 , struct V_200 , V_228 ) ;
F_42 ( & V_201 -> V_228 ) ;
V_223 = F_135 ( V_201 , V_221 , V_48 , V_222 ) ;
if ( V_223 == V_225 )
F_132 ( V_215 , V_201 ) ;
}
F_44 ( V_48 ) ;
}
static void F_138 ( struct V_202 * V_203 )
{
F_44 ( V_203 -> V_48 ) ;
F_139 ( V_203 ) ;
}
int
F_140 ( struct V_177 * V_215 )
{
struct V_229 * V_230 ;
struct V_202 * V_203 ;
int V_147 ;
V_230 = F_141 () ;
if ( ! V_230 ) {
V_215 -> V_231 -> V_232 ( & V_215 -> V_216 ) ;
F_44 ( V_215 -> V_181 ) ;
V_215 -> V_181 = NULL ;
return - V_128 ;
}
V_203 = & V_230 -> V_204 ;
F_142 ( V_215 , V_203 , F_138 ) ;
V_203 -> V_48 = F_98 ( V_215 -> V_181 ) ;
F_15 ( & V_203 -> V_233 ) ;
V_147 = F_143 ( V_215 , V_203 ) ;
if ( V_147 != 0 ) {
F_44 ( V_215 -> V_181 ) ;
V_215 -> V_181 = NULL ;
} else
F_137 ( V_215 , & V_203 -> V_234 , V_215 -> V_235 ) ;
if ( F_9 ( & V_203 -> V_233 ) )
V_203 -> V_211 -> V_236 ( V_203 ) ;
return V_147 ;
}
int F_144 ( struct V_36 * V_36 ,
struct V_77 * V_196 ,
const struct V_188 * V_189 )
{
struct V_177 V_178 ;
F_46 ( V_197 ) ;
F_114 ( & V_178 , V_36 , V_189 ) ;
while ( ! F_29 ( V_196 ) ) {
struct V_179 * V_180 = F_121 ( V_196 -> V_80 ) ;
F_122 ( V_180 ) ;
if ( ! F_123 ( & V_178 , V_180 ) )
F_124 ( V_180 , & V_197 ) ;
}
F_125 ( & V_178 ) ;
if ( ! F_29 ( & V_197 ) ) {
F_126 ( & V_197 , V_196 ) ;
return - V_199 ;
}
return 0 ;
}
static void F_145 ( struct V_237 * V_201 )
{
struct V_202 * V_203 = V_201 -> V_204 ;
F_3 ( L_52 , V_203 -> V_205 ) ;
if ( F_22 ( V_203 -> V_36 ) -> V_10 -> V_126 &
V_206 ) {
F_128 ( V_125 , & F_30 ( V_203 -> V_36 ) -> V_126 ) ;
F_129 ( V_203 -> V_36 ) ;
}
if ( ! F_56 ( V_207 , & V_203 -> V_126 ) )
V_201 -> V_208 . V_209 = F_144 ( V_203 -> V_36 ,
& V_203 -> V_210 ,
V_203 -> V_211 ) ;
}
void F_146 ( struct V_237 * V_201 )
{
struct V_202 * V_203 = V_201 -> V_204 ;
if ( F_95 ( ! V_203 -> V_205 ) ) {
F_147 ( V_201 ) ;
V_203 -> V_212 -> V_213 ( & V_201 -> V_208 , V_201 ) ;
} else
F_145 ( V_201 ) ;
V_203 -> V_212 -> V_214 ( V_201 ) ;
}
static void
F_148 ( struct V_177 * V_215 ,
struct V_237 * V_201 )
{
struct V_202 * V_203 = V_201 -> V_204 ;
if ( ! F_56 ( V_207 , & V_203 -> V_126 ) ) {
F_133 ( & V_203 -> V_210 , & V_215 -> V_216 ) ;
F_109 ( V_215 ) ;
V_215 -> V_217 = 1 ;
}
F_149 ( V_201 ) ;
}
static enum V_218
F_150 ( struct V_237 * V_238 ,
const struct V_220 * V_221 ,
struct V_47 * V_48 )
{
struct V_202 * V_203 = V_238 -> V_204 ;
struct V_36 * V_36 = V_203 -> V_36 ;
struct V_8 * V_9 = F_22 ( V_36 ) ;
enum V_218 V_223 ;
V_203 -> V_212 = V_221 ;
F_3 ( L_53 ,
V_5 , V_36 -> V_93 , V_238 -> args . V_166 , V_238 -> args . V_68 ) ;
V_223 = V_9 -> V_10 -> V_239 ( V_238 ) ;
if ( V_223 != V_225 )
F_136 ( V_36 , V_240 ) ;
F_3 ( L_51 , V_5 , V_223 ) ;
return V_223 ;
}
static void
F_151 ( struct V_177 * V_215 , struct V_77 * V_196 )
{
struct V_237 * V_201 ;
const struct V_220 * V_221 = V_215 -> V_227 ;
struct V_47 * V_48 = V_215 -> V_181 ;
V_215 -> V_181 = NULL ;
while ( ! F_29 ( V_196 ) ) {
enum V_218 V_223 ;
V_201 = F_58 ( V_196 , struct V_237 , V_228 ) ;
F_42 ( & V_201 -> V_228 ) ;
V_223 = F_150 ( V_201 , V_221 , V_48 ) ;
if ( V_223 == V_225 )
F_148 ( V_215 , V_201 ) ;
}
F_44 ( V_48 ) ;
}
static void F_152 ( struct V_202 * V_203 )
{
F_44 ( V_203 -> V_48 ) ;
F_153 ( V_203 ) ;
}
int
F_154 ( struct V_177 * V_215 )
{
struct V_241 * V_242 ;
struct V_202 * V_203 ;
int V_147 ;
V_242 = F_155 () ;
if ( ! V_242 ) {
V_215 -> V_231 -> V_232 ( & V_215 -> V_216 ) ;
V_147 = - V_128 ;
F_44 ( V_215 -> V_181 ) ;
V_215 -> V_181 = NULL ;
return V_147 ;
}
V_203 = & V_242 -> V_204 ;
F_142 ( V_215 , V_203 , F_152 ) ;
V_203 -> V_48 = F_98 ( V_215 -> V_181 ) ;
F_15 ( & V_203 -> V_233 ) ;
V_147 = F_156 ( V_215 , V_203 ) ;
if ( V_147 != 0 ) {
F_44 ( V_215 -> V_181 ) ;
V_215 -> V_181 = NULL ;
} else
F_151 ( V_215 , & V_203 -> V_234 ) ;
if ( F_9 ( & V_203 -> V_233 ) )
V_203 -> V_211 -> V_236 ( V_203 ) ;
return V_147 ;
}
static void F_157 ( struct V_36 * V_36 , struct V_77 * V_243 )
{
struct V_47 * V_48 ;
F_2 (lseg, &NFS_I(inode)->layout->plh_segs, pls_list) {
if ( V_48 -> V_85 . V_75 == V_146 &&
F_41 ( V_244 , & V_48 -> V_53 ) )
F_17 ( & V_48 -> V_50 , V_243 ) ;
}
}
void F_158 ( struct V_47 * V_48 )
{
if ( V_48 -> V_85 . V_75 == V_146 ) {
F_3 ( L_54 , V_5 ) ;
F_38 ( F_78 ( V_146 ) , & V_48 -> V_54 -> V_57 ) ;
} else {
F_3 ( L_55 , V_5 ) ;
F_38 ( F_78 ( V_139 ) , & V_48 -> V_54 -> V_57 ) ;
}
}
void
F_131 ( struct V_200 * V_219 )
{
struct V_202 * V_203 = V_219 -> V_204 ;
struct V_36 * V_36 = V_203 -> V_36 ;
struct V_88 * V_89 = F_30 ( V_36 ) ;
T_6 V_245 = V_219 -> V_246 + V_219 -> V_174 . V_166 ;
bool V_247 = false ;
F_5 ( & V_36 -> V_46 ) ;
if ( ! F_56 ( V_125 , & V_89 -> V_126 ) ) {
V_247 = true ;
F_3 ( L_56 ,
V_5 , V_36 -> V_93 ) ;
}
if ( ! F_56 ( V_244 , & V_203 -> V_48 -> V_53 ) ) {
F_98 ( V_203 -> V_48 ) ;
}
if ( V_245 > V_89 -> V_45 -> V_248 )
V_89 -> V_45 -> V_248 = V_245 ;
F_7 ( & V_36 -> V_46 ) ;
F_3 ( L_57 ,
V_5 , V_203 -> V_48 , V_89 -> V_45 -> V_248 ) ;
if ( V_247 )
F_159 ( V_36 ) ;
}
void F_160 ( struct V_249 * V_201 )
{
struct V_8 * V_9 = F_22 ( V_201 -> args . V_36 ) ;
if ( V_9 -> V_10 -> V_250 )
V_9 -> V_10 -> V_250 ( V_201 ) ;
}
int
F_161 ( struct V_36 * V_36 , bool V_251 )
{
struct V_249 * V_201 ;
struct V_88 * V_89 = F_30 ( V_36 ) ;
T_6 V_245 ;
int V_25 = 0 ;
F_3 ( L_58 , V_5 , V_36 -> V_93 ) ;
if ( ! F_41 ( V_125 , & V_89 -> V_126 ) )
return 0 ;
V_201 = F_23 ( sizeof( * V_201 ) , V_187 ) ;
if ( ! V_201 ) {
V_25 = - V_128 ;
goto V_4;
}
if ( ! F_41 ( V_125 , & V_89 -> V_126 ) )
goto V_252;
if ( F_56 ( V_253 , & V_89 -> V_126 ) ) {
if ( ! V_251 ) {
V_25 = - V_109 ;
goto V_252;
}
V_25 = F_162 ( & V_89 -> V_126 , V_253 ,
V_254 , V_255 ) ;
if ( V_25 )
goto V_252;
}
F_35 ( & V_201 -> V_256 ) ;
F_5 ( & V_36 -> V_46 ) ;
if ( ! F_54 ( V_125 , & V_89 -> V_126 ) ) {
F_128 ( V_253 , & V_89 -> V_126 ) ;
F_7 ( & V_36 -> V_46 ) ;
F_163 ( & V_89 -> V_126 , V_253 ) ;
goto V_252;
}
F_157 ( V_36 , & V_201 -> V_256 ) ;
V_245 = V_89 -> V_45 -> V_248 ;
V_89 -> V_45 -> V_248 = 0 ;
F_69 ( & V_201 -> args . V_102 , & V_89 -> V_45 -> V_98 ) ;
F_7 ( & V_36 -> V_46 ) ;
V_201 -> args . V_36 = V_36 ;
V_201 -> V_257 = F_93 ( V_89 -> V_45 -> V_42 ) ;
F_164 ( & V_201 -> V_258 ) ;
V_201 -> args . V_259 = F_22 ( V_36 ) -> V_260 ;
V_201 -> V_174 . V_258 = & V_201 -> V_258 ;
V_201 -> args . V_261 = V_245 - 1 ;
V_201 -> V_174 . V_14 = F_22 ( V_36 ) ;
V_25 = F_165 ( V_201 , V_251 ) ;
V_4:
if ( V_25 )
F_159 ( V_36 ) ;
F_3 ( L_59 , V_5 , V_25 ) ;
return V_25 ;
V_252:
F_26 ( V_201 ) ;
goto V_4;
}
struct V_148 * F_166 ( void )
{
struct V_148 * V_262 ;
V_262 = F_23 ( sizeof( * V_262 ) , V_187 ) ;
if ( ! V_262 ) {
F_3 ( L_60 , V_5 ) ;
return NULL ;
}
return V_262 ;
}
