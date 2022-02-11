void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
int F_5 ( void )
{
return F_6 ( & V_1 ) ;
}
static inline unsigned int F_7 ( unsigned int V_2 )
{
return V_2 & V_3 ;
}
static inline struct V_4 * F_8 ( unsigned int V_2 )
{
return & V_5 [ F_7 ( V_2 ) ] ;
}
static struct V_6 * F_9 ( unsigned int V_2 )
{
struct V_6 * V_7 ;
F_10 (f, genl_family_chain(id), family_list)
if ( V_7 -> V_2 == V_2 )
return V_7 ;
return NULL ;
}
static struct V_6 * F_11 ( char * V_8 )
{
struct V_6 * V_7 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_10 (f, genl_family_chain(i), family_list)
if ( strcmp ( V_7 -> V_8 , V_8 ) == 0 )
return V_7 ;
return NULL ;
}
static struct V_11 * F_12 ( T_1 V_12 , struct V_6 * V_13 )
{
struct V_11 * V_14 ;
F_10 (ops, &family->ops_list, ops_list)
if ( V_14 -> V_12 == V_12 )
return V_14 ;
return NULL ;
}
static T_2 F_13 ( void )
{
static T_2 V_15 = V_16 ;
int V_9 ;
for ( V_9 = 0 ; V_9 <= V_17 - V_16 ; V_9 ++ ) {
if ( ! F_9 ( V_15 ) )
return V_15 ;
if ( ++ V_15 > V_17 )
V_15 = V_16 ;
}
return 0 ;
}
int F_14 ( struct V_6 * V_13 ,
struct V_18 * V_19 )
{
int V_2 ;
unsigned long * V_20 ;
int V_21 = 0 ;
F_15 ( V_19 -> V_8 [ 0 ] == '\0' ) ;
F_15 ( memchr ( V_19 -> V_8 , '\0' , V_22 ) == NULL ) ;
F_1 () ;
if ( V_19 == & V_23 )
V_2 = V_24 ;
else
V_2 = F_16 ( V_25 ,
V_26 * V_27 ) ;
if ( V_2 >= V_26 * V_27 ) {
T_3 V_28 = ( V_26 + 1 ) * sizeof( unsigned long ) ;
if ( V_25 == & V_29 ) {
V_20 = F_17 ( V_28 , V_30 ) ;
if ( ! V_20 ) {
V_21 = - V_31 ;
goto V_32;
}
V_25 = V_20 ;
* V_25 = V_29 ;
} else {
V_20 = F_18 ( V_25 , V_28 , V_30 ) ;
if ( ! V_20 ) {
V_21 = - V_31 ;
goto V_32;
}
V_25 = V_20 ;
V_25 [ V_26 ] = 0 ;
}
V_26 ++ ;
}
if ( V_13 -> V_33 ) {
struct V_34 * V_34 ;
F_19 () ;
F_20 () ;
F_21 (net) {
V_21 = F_22 ( V_34 -> V_35 ,
V_26 * V_27 ) ;
if ( V_21 ) {
F_23 () ;
F_24 () ;
goto V_32;
}
}
F_23 () ;
F_24 () ;
} else {
V_21 = F_25 ( V_36 . V_35 ,
V_26 * V_27 ) ;
if ( V_21 )
goto V_32;
}
V_19 -> V_2 = V_2 ;
F_26 ( V_2 , V_25 ) ;
F_27 ( & V_19 -> V_37 , & V_13 -> V_38 ) ;
V_19 -> V_13 = V_13 ;
F_28 ( V_39 , V_19 ) ;
V_32:
F_3 () ;
return V_21 ;
}
static void F_29 ( struct V_6 * V_13 ,
struct V_18 * V_19 )
{
struct V_34 * V_34 ;
F_15 ( V_19 -> V_13 != V_13 ) ;
F_19 () ;
F_20 () ;
F_21 (net)
F_30 ( V_34 -> V_35 , V_19 -> V_2 ) ;
F_23 () ;
F_24 () ;
F_31 ( V_19 -> V_2 , V_25 ) ;
F_32 ( & V_19 -> V_37 ) ;
F_28 ( V_40 , V_19 ) ;
V_19 -> V_2 = 0 ;
V_19 -> V_13 = NULL ;
}
void F_33 ( struct V_6 * V_13 ,
struct V_18 * V_19 )
{
F_1 () ;
F_29 ( V_13 , V_19 ) ;
F_3 () ;
}
static void F_34 ( struct V_6 * V_13 )
{
struct V_18 * V_19 , * V_41 ;
F_35 (grp, tmp, &family->mcast_groups, list)
F_29 ( V_13 , V_19 ) ;
}
int F_36 ( struct V_6 * V_13 , struct V_11 * V_14 )
{
int V_21 = - V_42 ;
if ( V_14 -> V_43 == NULL && V_14 -> V_44 == NULL )
goto V_45;
if ( F_12 ( V_14 -> V_12 , V_13 ) ) {
V_21 = - V_46 ;
goto V_45;
}
if ( V_14 -> V_43 )
V_14 -> V_47 |= V_48 ;
if ( V_14 -> V_44 )
V_14 -> V_47 |= V_49 ;
if ( V_14 -> V_50 )
V_14 -> V_47 |= V_51 ;
F_1 () ;
F_27 ( & V_14 -> V_52 , & V_13 -> V_52 ) ;
F_3 () ;
F_28 ( V_53 , V_14 ) ;
V_21 = 0 ;
V_45:
return V_21 ;
}
int F_37 ( struct V_6 * V_13 , struct V_11 * V_14 )
{
struct V_11 * V_54 ;
F_1 () ;
F_10 (rc, &family->ops_list, ops_list) {
if ( V_54 == V_14 ) {
F_32 ( & V_14 -> V_52 ) ;
F_3 () ;
F_28 ( V_55 , V_14 ) ;
return 0 ;
}
}
F_3 () ;
return - V_56 ;
}
int F_38 ( struct V_6 * V_13 )
{
int V_21 = - V_42 ;
if ( V_13 -> V_2 && V_13 -> V_2 < V_16 )
goto V_45;
if ( V_13 -> V_2 > V_17 )
goto V_45;
F_39 ( & V_13 -> V_52 ) ;
F_39 ( & V_13 -> V_38 ) ;
F_1 () ;
if ( F_11 ( V_13 -> V_8 ) ) {
V_21 = - V_46 ;
goto V_57;
}
if ( V_13 -> V_2 == V_58 ) {
T_2 V_59 = F_13 () ;
if ( ! V_59 ) {
V_21 = - V_31 ;
goto V_57;
}
V_13 -> V_2 = V_59 ;
} else if ( F_9 ( V_13 -> V_2 ) ) {
V_21 = - V_46 ;
goto V_57;
}
if ( V_13 -> V_60 ) {
V_13 -> V_61 = F_40 ( ( V_13 -> V_60 + 1 ) *
sizeof( struct V_62 * ) , V_30 ) ;
if ( V_13 -> V_61 == NULL ) {
V_21 = - V_31 ;
goto V_57;
}
} else
V_13 -> V_61 = NULL ;
F_27 ( & V_13 -> V_63 , F_8 ( V_13 -> V_2 ) ) ;
F_3 () ;
F_28 ( V_64 , V_13 ) ;
return 0 ;
V_57:
F_3 () ;
V_45:
return V_21 ;
}
int F_41 ( struct V_6 * V_13 ,
struct V_11 * V_14 , T_3 V_65 )
{
int V_21 , V_9 ;
V_21 = F_38 ( V_13 ) ;
if ( V_21 )
return V_21 ;
for ( V_9 = 0 ; V_9 < V_65 ; ++ V_9 , ++ V_14 ) {
V_21 = F_36 ( V_13 , V_14 ) ;
if ( V_21 )
goto V_66;
}
return 0 ;
V_66:
F_42 ( V_13 ) ;
return V_21 ;
}
int F_42 ( struct V_6 * V_13 )
{
struct V_6 * V_54 ;
F_1 () ;
F_34 ( V_13 ) ;
F_10 (rc, genl_family_chain(family->id), family_list) {
if ( V_13 -> V_2 != V_54 -> V_2 || strcmp ( V_54 -> V_8 , V_13 -> V_8 ) )
continue;
F_32 ( & V_54 -> V_63 ) ;
F_39 ( & V_13 -> V_52 ) ;
F_3 () ;
F_43 ( V_13 -> V_61 ) ;
F_28 ( V_67 , V_13 ) ;
return 0 ;
}
F_3 () ;
return - V_56 ;
}
void * F_44 ( struct V_68 * V_69 , T_4 V_70 , T_4 V_71 ,
struct V_6 * V_13 , int V_47 , T_1 V_12 )
{
struct V_72 * V_73 ;
struct V_74 * V_75 ;
V_73 = F_45 ( V_69 , V_70 , V_71 , V_13 -> V_2 , V_76 +
V_13 -> V_77 , V_47 ) ;
if ( V_73 == NULL )
return NULL ;
V_75 = F_46 ( V_73 ) ;
V_75 -> V_12 = V_12 ;
V_75 -> V_78 = V_13 -> V_78 ;
V_75 -> V_79 = 0 ;
return ( char * ) V_75 + V_76 ;
}
static int F_47 ( struct V_68 * V_69 , struct V_72 * V_73 )
{
struct V_11 * V_14 ;
struct V_6 * V_13 ;
struct V_34 * V_34 = F_48 ( V_69 -> V_80 ) ;
struct V_81 V_82 ;
struct V_74 * V_75 = F_46 ( V_73 ) ;
int V_83 , V_21 ;
V_13 = F_9 ( V_73 -> V_84 ) ;
if ( V_13 == NULL )
return - V_56 ;
if ( ! V_13 -> V_33 && ! F_49 ( V_34 , & V_36 ) )
return - V_56 ;
V_83 = V_76 + V_13 -> V_77 ;
if ( V_73 -> V_85 < F_50 ( V_83 ) )
return - V_42 ;
V_14 = F_12 ( V_75 -> V_12 , V_13 ) ;
if ( V_14 == NULL )
return - V_86 ;
if ( ( V_14 -> V_47 & V_87 ) &&
! F_51 ( V_88 ) )
return - V_89 ;
if ( V_73 -> V_90 & V_91 ) {
if ( V_14 -> V_43 == NULL )
return - V_86 ;
F_3 () ;
{
struct V_92 V_93 = {
. V_94 = V_14 -> V_43 ,
. V_95 = V_14 -> V_95 ,
} ;
V_21 = F_52 ( V_34 -> V_35 , V_69 , V_73 , & V_93 ) ;
}
F_1 () ;
return V_21 ;
}
if ( V_14 -> V_44 == NULL )
return - V_86 ;
if ( V_13 -> V_61 ) {
V_21 = F_53 ( V_73 , V_83 , V_13 -> V_61 , V_13 -> V_60 ,
V_14 -> V_50 ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_82 . V_96 = V_73 -> V_97 ;
V_82 . V_98 = F_54 ( V_69 ) . V_70 ;
V_82 . V_99 = V_73 ;
V_82 . V_100 = F_46 ( V_73 ) ;
V_82 . V_101 = F_46 ( V_73 ) + V_76 ;
V_82 . V_102 = V_13 -> V_61 ;
F_55 ( & V_82 , V_34 ) ;
memset ( & V_82 . V_103 , 0 , sizeof( V_82 . V_103 ) ) ;
if ( V_13 -> V_104 ) {
V_21 = V_13 -> V_104 ( V_14 , V_69 , & V_82 ) ;
if ( V_21 )
return V_21 ;
}
V_21 = V_14 -> V_44 ( V_69 , & V_82 ) ;
if ( V_13 -> V_105 )
V_13 -> V_105 ( V_14 , V_69 , & V_82 ) ;
return V_21 ;
}
static void F_56 ( struct V_68 * V_69 )
{
F_1 () ;
F_57 ( V_69 , & F_47 ) ;
F_3 () ;
}
static int F_58 ( struct V_6 * V_13 , T_4 V_70 , T_4 V_71 ,
T_4 V_47 , struct V_68 * V_69 , T_1 V_12 )
{
void * V_75 ;
V_75 = F_44 ( V_69 , V_70 , V_71 , & V_106 , V_47 , V_12 ) ;
if ( V_75 == NULL )
return - 1 ;
if ( F_59 ( V_69 , V_107 , V_13 -> V_8 ) ||
F_60 ( V_69 , V_108 , V_13 -> V_2 ) ||
F_61 ( V_69 , V_109 , V_13 -> V_78 ) ||
F_61 ( V_69 , V_110 , V_13 -> V_77 ) ||
F_61 ( V_69 , V_111 , V_13 -> V_60 ) )
goto V_112;
if ( ! F_62 ( & V_13 -> V_52 ) ) {
struct V_62 * V_113 ;
struct V_11 * V_14 ;
int V_114 = 1 ;
V_113 = F_63 ( V_69 , V_115 ) ;
if ( V_113 == NULL )
goto V_112;
F_10 (ops, &family->ops_list, ops_list) {
struct V_62 * V_116 ;
V_116 = F_63 ( V_69 , V_114 ++ ) ;
if ( V_116 == NULL )
goto V_112;
if ( F_61 ( V_69 , V_117 , V_14 -> V_12 ) ||
F_61 ( V_69 , V_118 , V_14 -> V_47 ) )
goto V_112;
F_64 ( V_69 , V_116 ) ;
}
F_64 ( V_69 , V_113 ) ;
}
if ( ! F_62 ( & V_13 -> V_38 ) ) {
struct V_18 * V_19 ;
struct V_62 * V_119 ;
int V_114 = 1 ;
V_119 = F_63 ( V_69 , V_120 ) ;
if ( V_119 == NULL )
goto V_112;
F_10 (grp, &family->mcast_groups, list) {
struct V_62 * V_116 ;
V_116 = F_63 ( V_69 , V_114 ++ ) ;
if ( V_116 == NULL )
goto V_112;
if ( F_61 ( V_69 , V_121 , V_19 -> V_2 ) ||
F_59 ( V_69 , V_122 ,
V_19 -> V_8 ) )
goto V_112;
F_64 ( V_69 , V_116 ) ;
}
F_64 ( V_69 , V_119 ) ;
}
return F_65 ( V_69 , V_75 ) ;
V_112:
F_66 ( V_69 , V_75 ) ;
return - V_123 ;
}
static int F_67 ( struct V_18 * V_19 , T_4 V_70 ,
T_4 V_71 , T_4 V_47 , struct V_68 * V_69 ,
T_1 V_12 )
{
void * V_75 ;
struct V_62 * V_119 ;
struct V_62 * V_116 ;
V_75 = F_44 ( V_69 , V_70 , V_71 , & V_106 , V_47 , V_12 ) ;
if ( V_75 == NULL )
return - 1 ;
if ( F_59 ( V_69 , V_107 , V_19 -> V_13 -> V_8 ) ||
F_60 ( V_69 , V_108 , V_19 -> V_13 -> V_2 ) )
goto V_112;
V_119 = F_63 ( V_69 , V_120 ) ;
if ( V_119 == NULL )
goto V_112;
V_116 = F_63 ( V_69 , 1 ) ;
if ( V_116 == NULL )
goto V_112;
if ( F_61 ( V_69 , V_121 , V_19 -> V_2 ) ||
F_59 ( V_69 , V_122 ,
V_19 -> V_8 ) )
goto V_112;
F_64 ( V_69 , V_116 ) ;
F_64 ( V_69 , V_119 ) ;
return F_65 ( V_69 , V_75 ) ;
V_112:
F_66 ( V_69 , V_75 ) ;
return - V_123 ;
}
static int F_68 ( struct V_68 * V_69 , struct V_124 * V_125 )
{
int V_9 , V_126 = 0 ;
struct V_6 * V_127 ;
struct V_34 * V_34 = F_48 ( V_69 -> V_80 ) ;
int V_128 = V_125 -> args [ 0 ] ;
int V_129 = V_125 -> args [ 1 ] ;
for ( V_9 = V_128 ; V_9 < V_10 ; V_9 ++ ) {
V_126 = 0 ;
F_10 (rt, genl_family_chain(i), family_list) {
if ( ! V_127 -> V_33 && ! F_49 ( V_34 , & V_36 ) )
continue;
if ( ++ V_126 < V_129 )
continue;
if ( F_58 ( V_127 , F_54 ( V_125 -> V_69 ) . V_70 ,
V_125 -> V_73 -> V_97 , V_130 ,
V_69 , V_64 ) < 0 )
goto V_45;
}
V_129 = 0 ;
}
V_45:
V_125 -> args [ 0 ] = V_9 ;
V_125 -> args [ 1 ] = V_126 ;
return V_69 -> V_131 ;
}
static struct V_68 * F_69 ( struct V_6 * V_13 ,
T_4 V_70 , int V_71 , T_1 V_12 )
{
struct V_68 * V_69 ;
int V_21 ;
V_69 = F_70 ( V_132 , V_30 ) ;
if ( V_69 == NULL )
return F_71 ( - V_133 ) ;
V_21 = F_58 ( V_13 , V_70 , V_71 , 0 , V_69 , V_12 ) ;
if ( V_21 < 0 ) {
F_72 ( V_69 ) ;
return F_71 ( V_21 ) ;
}
return V_69 ;
}
static struct V_68 * F_73 ( struct V_18 * V_19 ,
T_4 V_70 , int V_71 , T_1 V_12 )
{
struct V_68 * V_69 ;
int V_21 ;
V_69 = F_70 ( V_132 , V_30 ) ;
if ( V_69 == NULL )
return F_71 ( - V_133 ) ;
V_21 = F_67 ( V_19 , V_70 , V_71 , 0 , V_69 , V_12 ) ;
if ( V_21 < 0 ) {
F_72 ( V_69 ) ;
return F_71 ( V_21 ) ;
}
return V_69 ;
}
static int F_74 ( struct V_68 * V_69 , struct V_81 * V_82 )
{
struct V_68 * V_134 ;
struct V_6 * V_135 = NULL ;
int V_21 = - V_42 ;
if ( V_82 -> V_102 [ V_108 ] ) {
T_2 V_2 = F_75 ( V_82 -> V_102 [ V_108 ] ) ;
V_135 = F_9 ( V_2 ) ;
V_21 = - V_56 ;
}
if ( V_82 -> V_102 [ V_107 ] ) {
char * V_8 ;
V_8 = F_76 ( V_82 -> V_102 [ V_107 ] ) ;
V_135 = F_11 ( V_8 ) ;
#ifdef F_77
if ( V_135 == NULL ) {
F_3 () ;
F_78 ( L_1 ,
V_136 , V_137 , V_8 ) ;
F_1 () ;
V_135 = F_11 ( V_8 ) ;
}
#endif
V_21 = - V_56 ;
}
if ( V_135 == NULL )
return V_21 ;
if ( ! V_135 -> V_33 && ! F_49 ( F_79 ( V_82 ) , & V_36 ) ) {
return - V_56 ;
}
V_134 = F_69 ( V_135 , V_82 -> V_98 , V_82 -> V_96 ,
V_64 ) ;
if ( F_80 ( V_134 ) )
return F_81 ( V_134 ) ;
return F_82 ( V_134 , V_82 ) ;
}
static int F_28 ( int V_138 , void * V_139 )
{
struct V_68 * V_134 ;
struct V_6 * V_13 ;
struct V_18 * V_19 ;
if ( ! V_36 . V_35 )
return 0 ;
switch ( V_138 ) {
case V_64 :
case V_67 :
V_13 = V_139 ;
V_134 = F_69 ( V_13 , 0 , 0 , V_138 ) ;
break;
case V_39 :
case V_40 :
V_19 = V_139 ;
V_13 = V_19 -> V_13 ;
V_134 = F_73 ( V_139 , 0 , 0 , V_138 ) ;
break;
default:
return - V_42 ;
}
if ( F_80 ( V_134 ) )
return F_81 ( V_134 ) ;
if ( ! V_13 -> V_33 ) {
F_83 ( & V_36 , V_134 , 0 ,
V_24 , V_30 ) ;
} else {
F_20 () ;
F_84 ( V_134 , 0 , V_24 , V_140 ) ;
F_23 () ;
}
return 0 ;
}
static int T_5 F_85 ( struct V_34 * V_34 )
{
struct V_141 V_142 = {
. V_143 = F_56 ,
. V_144 = & V_1 ,
. V_47 = V_145 ,
} ;
V_34 -> V_35 = F_86 ( V_34 , V_137 , & V_142 ) ;
if ( ! V_34 -> V_35 && F_49 ( V_34 , & V_36 ) )
F_87 ( L_2 ) ;
if ( ! V_34 -> V_35 )
return - V_31 ;
return 0 ;
}
static void T_6 F_88 ( struct V_34 * V_34 )
{
F_89 ( V_34 -> V_35 ) ;
V_34 -> V_35 = NULL ;
}
static int T_7 F_90 ( void )
{
int V_9 , V_21 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_39 ( & V_5 [ V_9 ] ) ;
V_21 = F_41 ( & V_106 , & V_146 , 1 ) ;
if ( V_21 < 0 )
goto V_147;
V_21 = F_91 ( & V_148 ) ;
if ( V_21 )
goto V_147;
V_21 = F_14 ( & V_106 , & V_23 ) ;
if ( V_21 < 0 )
goto V_147;
return 0 ;
V_147:
F_87 ( L_3 , V_21 ) ;
}
static int F_92 ( struct V_68 * V_69 , T_4 V_70 , unsigned long V_149 ,
T_8 V_47 )
{
struct V_68 * V_41 ;
struct V_34 * V_34 , * V_150 = NULL ;
int V_21 ;
F_21 (net) {
if ( V_150 ) {
V_41 = F_93 ( V_69 , V_47 ) ;
if ( ! V_41 ) {
V_21 = - V_31 ;
goto error;
}
V_21 = F_94 ( V_150 -> V_35 , V_41 ,
V_70 , V_149 , V_47 ) ;
if ( V_21 )
goto error;
}
V_150 = V_34 ;
}
return F_94 ( V_150 -> V_35 , V_69 , V_70 , V_149 , V_47 ) ;
error:
F_95 ( V_69 ) ;
return V_21 ;
}
int F_84 ( struct V_68 * V_69 , T_4 V_70 , unsigned int V_149 ,
T_8 V_47 )
{
return F_92 ( V_69 , V_70 , V_149 , V_47 ) ;
}
void F_96 ( struct V_68 * V_69 , struct V_34 * V_34 , T_4 V_70 , T_4 V_149 ,
struct V_72 * V_73 , T_8 V_47 )
{
struct V_151 * V_80 = V_34 -> V_35 ;
int V_152 = 0 ;
if ( V_73 )
V_152 = F_97 ( V_73 ) ;
F_98 ( V_80 , V_69 , V_70 , V_149 , V_152 , V_47 ) ;
}
