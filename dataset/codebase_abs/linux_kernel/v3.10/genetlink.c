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
static void F_7 ( void )
{
F_8 ( & V_2 ) ;
F_1 () ;
}
static void F_9 ( void )
{
F_3 () ;
F_10 ( & V_2 ) ;
}
static inline unsigned int F_11 ( unsigned int V_3 )
{
return V_3 & V_4 ;
}
static inline struct V_5 * F_12 ( unsigned int V_3 )
{
return & V_6 [ F_11 ( V_3 ) ] ;
}
static struct V_7 * F_13 ( unsigned int V_3 )
{
struct V_7 * V_8 ;
F_14 (f, genl_family_chain(id), family_list)
if ( V_8 -> V_3 == V_3 )
return V_8 ;
return NULL ;
}
static struct V_7 * F_15 ( char * V_9 )
{
struct V_7 * V_8 ;
int V_10 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_14 (f, genl_family_chain(i), family_list)
if ( strcmp ( V_8 -> V_9 , V_9 ) == 0 )
return V_8 ;
return NULL ;
}
static struct V_12 * F_16 ( T_1 V_13 , struct V_7 * V_14 )
{
struct V_12 * V_15 ;
F_14 (ops, &family->ops_list, ops_list)
if ( V_15 -> V_13 == V_13 )
return V_15 ;
return NULL ;
}
static T_2 F_17 ( void )
{
static T_2 V_16 = V_17 ;
int V_10 ;
for ( V_10 = 0 ; V_10 <= V_18 - V_17 ; V_10 ++ ) {
if ( ! F_13 ( V_16 ) )
return V_16 ;
if ( ++ V_16 > V_18 )
V_16 = V_17 ;
}
return 0 ;
}
int F_18 ( struct V_7 * V_14 ,
struct V_19 * V_20 )
{
int V_3 ;
unsigned long * V_21 ;
int V_22 = 0 ;
F_19 ( V_20 -> V_9 [ 0 ] == '\0' ) ;
F_19 ( memchr ( V_20 -> V_9 , '\0' , V_23 ) == NULL ) ;
F_7 () ;
if ( V_20 == & V_24 )
V_3 = V_25 ;
else
V_3 = F_20 ( V_26 ,
V_27 * V_28 ) ;
if ( V_3 >= V_27 * V_28 ) {
T_3 V_29 = ( V_27 + 1 ) * sizeof( unsigned long ) ;
if ( V_26 == & V_30 ) {
V_21 = F_21 ( V_29 , V_31 ) ;
if ( ! V_21 ) {
V_22 = - V_32 ;
goto V_33;
}
V_26 = V_21 ;
* V_26 = V_30 ;
} else {
V_21 = F_22 ( V_26 , V_29 , V_31 ) ;
if ( ! V_21 ) {
V_22 = - V_32 ;
goto V_33;
}
V_26 = V_21 ;
V_26 [ V_27 ] = 0 ;
}
V_27 ++ ;
}
if ( V_14 -> V_34 ) {
struct V_35 * V_35 ;
F_23 () ;
F_24 () ;
F_25 (net) {
V_22 = F_26 ( V_35 -> V_36 ,
V_27 * V_28 ) ;
if ( V_22 ) {
F_27 () ;
F_28 () ;
goto V_33;
}
}
F_27 () ;
F_28 () ;
} else {
V_22 = F_29 ( V_37 . V_36 ,
V_27 * V_28 ) ;
if ( V_22 )
goto V_33;
}
V_20 -> V_3 = V_3 ;
F_30 ( V_3 , V_26 ) ;
F_31 ( & V_20 -> V_38 , & V_14 -> V_39 ) ;
V_20 -> V_14 = V_14 ;
F_32 ( V_40 , V_20 ) ;
V_33:
F_9 () ;
return V_22 ;
}
static void F_33 ( struct V_7 * V_14 ,
struct V_19 * V_20 )
{
struct V_35 * V_35 ;
F_19 ( V_20 -> V_14 != V_14 ) ;
F_23 () ;
F_24 () ;
F_25 (net)
F_34 ( V_35 -> V_36 , V_20 -> V_3 ) ;
F_27 () ;
F_28 () ;
F_35 ( V_20 -> V_3 , V_26 ) ;
F_36 ( & V_20 -> V_38 ) ;
F_32 ( V_41 , V_20 ) ;
V_20 -> V_3 = 0 ;
V_20 -> V_14 = NULL ;
}
void F_37 ( struct V_7 * V_14 ,
struct V_19 * V_20 )
{
F_7 () ;
F_33 ( V_14 , V_20 ) ;
F_9 () ;
}
static void F_38 ( struct V_7 * V_14 )
{
struct V_19 * V_20 , * V_42 ;
F_39 (grp, tmp, &family->mcast_groups, list)
F_33 ( V_14 , V_20 ) ;
}
int F_40 ( struct V_7 * V_14 , struct V_12 * V_15 )
{
int V_22 = - V_43 ;
if ( V_15 -> V_44 == NULL && V_15 -> V_45 == NULL )
goto V_46;
if ( F_16 ( V_15 -> V_13 , V_14 ) ) {
V_22 = - V_47 ;
goto V_46;
}
if ( V_15 -> V_44 )
V_15 -> V_48 |= V_49 ;
if ( V_15 -> V_45 )
V_15 -> V_48 |= V_50 ;
if ( V_15 -> V_51 )
V_15 -> V_48 |= V_52 ;
F_7 () ;
F_31 ( & V_15 -> V_53 , & V_14 -> V_53 ) ;
F_9 () ;
F_32 ( V_54 , V_15 ) ;
V_22 = 0 ;
V_46:
return V_22 ;
}
int F_41 ( struct V_7 * V_14 , struct V_12 * V_15 )
{
struct V_12 * V_55 ;
F_7 () ;
F_14 (rc, &family->ops_list, ops_list) {
if ( V_55 == V_15 ) {
F_36 ( & V_15 -> V_53 ) ;
F_9 () ;
F_32 ( V_56 , V_15 ) ;
return 0 ;
}
}
F_9 () ;
return - V_57 ;
}
int F_42 ( struct V_7 * V_14 )
{
int V_22 = - V_43 ;
if ( V_14 -> V_3 && V_14 -> V_3 < V_17 )
goto V_46;
if ( V_14 -> V_3 > V_18 )
goto V_46;
F_43 ( & V_14 -> V_53 ) ;
F_43 ( & V_14 -> V_39 ) ;
F_7 () ;
if ( F_15 ( V_14 -> V_9 ) ) {
V_22 = - V_47 ;
goto V_58;
}
if ( V_14 -> V_3 == V_59 ) {
T_2 V_60 = F_17 () ;
if ( ! V_60 ) {
V_22 = - V_32 ;
goto V_58;
}
V_14 -> V_3 = V_60 ;
} else if ( F_13 ( V_14 -> V_3 ) ) {
V_22 = - V_47 ;
goto V_58;
}
if ( V_14 -> V_61 && ! V_14 -> V_62 ) {
V_14 -> V_63 = F_44 ( ( V_14 -> V_61 + 1 ) *
sizeof( struct V_64 * ) , V_31 ) ;
if ( V_14 -> V_63 == NULL ) {
V_22 = - V_32 ;
goto V_58;
}
} else
V_14 -> V_63 = NULL ;
F_31 ( & V_14 -> V_65 , F_12 ( V_14 -> V_3 ) ) ;
F_9 () ;
F_32 ( V_66 , V_14 ) ;
return 0 ;
V_58:
F_9 () ;
V_46:
return V_22 ;
}
int F_45 ( struct V_7 * V_14 ,
struct V_12 * V_15 , T_3 V_67 )
{
int V_22 , V_10 ;
V_22 = F_42 ( V_14 ) ;
if ( V_22 )
return V_22 ;
for ( V_10 = 0 ; V_10 < V_67 ; ++ V_10 , ++ V_15 ) {
V_22 = F_40 ( V_14 , V_15 ) ;
if ( V_22 )
goto V_68;
}
return 0 ;
V_68:
F_46 ( V_14 ) ;
return V_22 ;
}
int F_46 ( struct V_7 * V_14 )
{
struct V_7 * V_55 ;
F_7 () ;
F_38 ( V_14 ) ;
F_14 (rc, genl_family_chain(family->id), family_list) {
if ( V_14 -> V_3 != V_55 -> V_3 || strcmp ( V_55 -> V_9 , V_14 -> V_9 ) )
continue;
F_36 ( & V_55 -> V_65 ) ;
F_43 ( & V_14 -> V_53 ) ;
F_9 () ;
F_47 ( V_14 -> V_63 ) ;
F_32 ( V_69 , V_14 ) ;
return 0 ;
}
F_9 () ;
return - V_57 ;
}
void * F_48 ( struct V_70 * V_71 , T_4 V_72 , T_4 V_73 ,
struct V_7 * V_14 , int V_48 , T_1 V_13 )
{
struct V_74 * V_75 ;
struct V_76 * V_77 ;
V_75 = F_49 ( V_71 , V_72 , V_73 , V_14 -> V_3 , V_78 +
V_14 -> V_79 , V_48 ) ;
if ( V_75 == NULL )
return NULL ;
V_77 = F_50 ( V_75 ) ;
V_77 -> V_13 = V_13 ;
V_77 -> V_80 = V_14 -> V_80 ;
V_77 -> V_81 = 0 ;
return ( char * ) V_77 + V_78 ;
}
static int F_51 ( struct V_7 * V_14 ,
struct V_70 * V_71 ,
struct V_74 * V_75 )
{
struct V_12 * V_15 ;
struct V_35 * V_35 = F_52 ( V_71 -> V_82 ) ;
struct V_83 V_84 ;
struct V_76 * V_77 = F_50 ( V_75 ) ;
struct V_64 * * V_63 ;
int V_85 , V_22 ;
if ( ! V_14 -> V_34 && ! F_53 ( V_35 , & V_37 ) )
return - V_57 ;
V_85 = V_78 + V_14 -> V_79 ;
if ( V_75 -> V_86 < F_54 ( V_85 ) )
return - V_43 ;
V_15 = F_16 ( V_77 -> V_13 , V_14 ) ;
if ( V_15 == NULL )
return - V_87 ;
if ( ( V_15 -> V_48 & V_88 ) &&
! F_55 ( V_89 ) )
return - V_90 ;
if ( V_75 -> V_91 & V_92 ) {
struct V_93 V_94 = {
. V_95 = V_15 -> V_44 ,
. V_96 = V_15 -> V_96 ,
} ;
if ( V_15 -> V_44 == NULL )
return - V_87 ;
return F_56 ( V_35 -> V_36 , V_71 , V_75 , & V_94 ) ;
}
if ( V_15 -> V_45 == NULL )
return - V_87 ;
if ( V_14 -> V_61 && V_14 -> V_62 ) {
V_63 = F_44 ( ( V_14 -> V_61 + 1 ) *
sizeof( struct V_64 * ) , V_31 ) ;
if ( V_63 == NULL )
return - V_32 ;
} else
V_63 = V_14 -> V_63 ;
if ( V_63 ) {
V_22 = F_57 ( V_75 , V_85 , V_63 , V_14 -> V_61 ,
V_15 -> V_51 ) ;
if ( V_22 < 0 )
goto V_33;
}
V_84 . V_97 = V_75 -> V_98 ;
V_84 . V_99 = F_58 ( V_71 ) . V_72 ;
V_84 . V_100 = V_75 ;
V_84 . V_101 = F_50 ( V_75 ) ;
V_84 . V_102 = F_50 ( V_75 ) + V_78 ;
V_84 . V_103 = V_63 ;
F_59 ( & V_84 , V_35 ) ;
memset ( & V_84 . V_104 , 0 , sizeof( V_84 . V_104 ) ) ;
if ( V_14 -> V_105 ) {
V_22 = V_14 -> V_105 ( V_15 , V_71 , & V_84 ) ;
if ( V_22 )
goto V_33;
}
V_22 = V_15 -> V_45 ( V_71 , & V_84 ) ;
if ( V_14 -> V_106 )
V_14 -> V_106 ( V_15 , V_71 , & V_84 ) ;
V_33:
if ( V_14 -> V_62 )
F_47 ( V_63 ) ;
return V_22 ;
}
static int F_60 ( struct V_70 * V_71 , struct V_74 * V_75 )
{
struct V_7 * V_14 ;
int V_22 ;
V_14 = F_13 ( V_75 -> V_107 ) ;
if ( V_14 == NULL )
return - V_57 ;
if ( ! V_14 -> V_62 )
F_1 () ;
V_22 = F_51 ( V_14 , V_71 , V_75 ) ;
if ( ! V_14 -> V_62 )
F_3 () ;
return V_22 ;
}
static void F_61 ( struct V_70 * V_71 )
{
F_62 ( & V_2 ) ;
F_63 ( V_71 , & F_60 ) ;
F_64 ( & V_2 ) ;
}
static int F_65 ( struct V_7 * V_14 , T_4 V_72 , T_4 V_73 ,
T_4 V_48 , struct V_70 * V_71 , T_1 V_13 )
{
void * V_77 ;
V_77 = F_48 ( V_71 , V_72 , V_73 , & V_108 , V_48 , V_13 ) ;
if ( V_77 == NULL )
return - 1 ;
if ( F_66 ( V_71 , V_109 , V_14 -> V_9 ) ||
F_67 ( V_71 , V_110 , V_14 -> V_3 ) ||
F_68 ( V_71 , V_111 , V_14 -> V_80 ) ||
F_68 ( V_71 , V_112 , V_14 -> V_79 ) ||
F_68 ( V_71 , V_113 , V_14 -> V_61 ) )
goto V_114;
if ( ! F_69 ( & V_14 -> V_53 ) ) {
struct V_64 * V_115 ;
struct V_12 * V_15 ;
int V_116 = 1 ;
V_115 = F_70 ( V_71 , V_117 ) ;
if ( V_115 == NULL )
goto V_114;
F_14 (ops, &family->ops_list, ops_list) {
struct V_64 * V_118 ;
V_118 = F_70 ( V_71 , V_116 ++ ) ;
if ( V_118 == NULL )
goto V_114;
if ( F_68 ( V_71 , V_119 , V_15 -> V_13 ) ||
F_68 ( V_71 , V_120 , V_15 -> V_48 ) )
goto V_114;
F_71 ( V_71 , V_118 ) ;
}
F_71 ( V_71 , V_115 ) ;
}
if ( ! F_69 ( & V_14 -> V_39 ) ) {
struct V_19 * V_20 ;
struct V_64 * V_121 ;
int V_116 = 1 ;
V_121 = F_70 ( V_71 , V_122 ) ;
if ( V_121 == NULL )
goto V_114;
F_14 (grp, &family->mcast_groups, list) {
struct V_64 * V_118 ;
V_118 = F_70 ( V_71 , V_116 ++ ) ;
if ( V_118 == NULL )
goto V_114;
if ( F_68 ( V_71 , V_123 , V_20 -> V_3 ) ||
F_66 ( V_71 , V_124 ,
V_20 -> V_9 ) )
goto V_114;
F_71 ( V_71 , V_118 ) ;
}
F_71 ( V_71 , V_121 ) ;
}
return F_72 ( V_71 , V_77 ) ;
V_114:
F_73 ( V_71 , V_77 ) ;
return - V_125 ;
}
static int F_74 ( struct V_19 * V_20 , T_4 V_72 ,
T_4 V_73 , T_4 V_48 , struct V_70 * V_71 ,
T_1 V_13 )
{
void * V_77 ;
struct V_64 * V_121 ;
struct V_64 * V_118 ;
V_77 = F_48 ( V_71 , V_72 , V_73 , & V_108 , V_48 , V_13 ) ;
if ( V_77 == NULL )
return - 1 ;
if ( F_66 ( V_71 , V_109 , V_20 -> V_14 -> V_9 ) ||
F_67 ( V_71 , V_110 , V_20 -> V_14 -> V_3 ) )
goto V_114;
V_121 = F_70 ( V_71 , V_122 ) ;
if ( V_121 == NULL )
goto V_114;
V_118 = F_70 ( V_71 , 1 ) ;
if ( V_118 == NULL )
goto V_114;
if ( F_68 ( V_71 , V_123 , V_20 -> V_3 ) ||
F_66 ( V_71 , V_124 ,
V_20 -> V_9 ) )
goto V_114;
F_71 ( V_71 , V_118 ) ;
F_71 ( V_71 , V_121 ) ;
return F_72 ( V_71 , V_77 ) ;
V_114:
F_73 ( V_71 , V_77 ) ;
return - V_125 ;
}
static int F_75 ( struct V_70 * V_71 , struct V_126 * V_127 )
{
int V_10 , V_128 = 0 ;
struct V_7 * V_129 ;
struct V_35 * V_35 = F_52 ( V_71 -> V_82 ) ;
int V_130 = V_127 -> args [ 0 ] ;
int V_131 = V_127 -> args [ 1 ] ;
for ( V_10 = V_130 ; V_10 < V_11 ; V_10 ++ ) {
V_128 = 0 ;
F_14 (rt, genl_family_chain(i), family_list) {
if ( ! V_129 -> V_34 && ! F_53 ( V_35 , & V_37 ) )
continue;
if ( ++ V_128 < V_131 )
continue;
if ( F_65 ( V_129 , F_58 ( V_127 -> V_71 ) . V_72 ,
V_127 -> V_75 -> V_98 , V_132 ,
V_71 , V_66 ) < 0 )
goto V_46;
}
V_131 = 0 ;
}
V_46:
V_127 -> args [ 0 ] = V_10 ;
V_127 -> args [ 1 ] = V_128 ;
return V_71 -> V_133 ;
}
static struct V_70 * F_76 ( struct V_7 * V_14 ,
T_4 V_72 , int V_73 , T_1 V_13 )
{
struct V_70 * V_71 ;
int V_22 ;
V_71 = F_77 ( V_134 , V_31 ) ;
if ( V_71 == NULL )
return F_78 ( - V_135 ) ;
V_22 = F_65 ( V_14 , V_72 , V_73 , 0 , V_71 , V_13 ) ;
if ( V_22 < 0 ) {
F_79 ( V_71 ) ;
return F_78 ( V_22 ) ;
}
return V_71 ;
}
static struct V_70 * F_80 ( struct V_19 * V_20 ,
T_4 V_72 , int V_73 , T_1 V_13 )
{
struct V_70 * V_71 ;
int V_22 ;
V_71 = F_77 ( V_134 , V_31 ) ;
if ( V_71 == NULL )
return F_78 ( - V_135 ) ;
V_22 = F_74 ( V_20 , V_72 , V_73 , 0 , V_71 , V_13 ) ;
if ( V_22 < 0 ) {
F_79 ( V_71 ) ;
return F_78 ( V_22 ) ;
}
return V_71 ;
}
static int F_81 ( struct V_70 * V_71 , struct V_83 * V_84 )
{
struct V_70 * V_136 ;
struct V_7 * V_137 = NULL ;
int V_22 = - V_43 ;
if ( V_84 -> V_103 [ V_110 ] ) {
T_2 V_3 = F_82 ( V_84 -> V_103 [ V_110 ] ) ;
V_137 = F_13 ( V_3 ) ;
V_22 = - V_57 ;
}
if ( V_84 -> V_103 [ V_109 ] ) {
char * V_9 ;
V_9 = F_83 ( V_84 -> V_103 [ V_109 ] ) ;
V_137 = F_15 ( V_9 ) ;
#ifdef F_84
if ( V_137 == NULL ) {
F_3 () ;
F_85 ( L_1 ,
V_138 , V_139 , V_9 ) ;
F_1 () ;
V_137 = F_15 ( V_9 ) ;
}
#endif
V_22 = - V_57 ;
}
if ( V_137 == NULL )
return V_22 ;
if ( ! V_137 -> V_34 && ! F_53 ( F_86 ( V_84 ) , & V_37 ) ) {
return - V_57 ;
}
V_136 = F_76 ( V_137 , V_84 -> V_99 , V_84 -> V_97 ,
V_66 ) ;
if ( F_87 ( V_136 ) )
return F_88 ( V_136 ) ;
return F_89 ( V_136 , V_84 ) ;
}
static int F_32 ( int V_140 , void * V_141 )
{
struct V_70 * V_136 ;
struct V_7 * V_14 ;
struct V_19 * V_20 ;
if ( ! V_37 . V_36 )
return 0 ;
switch ( V_140 ) {
case V_66 :
case V_69 :
V_14 = V_141 ;
V_136 = F_76 ( V_14 , 0 , 0 , V_140 ) ;
break;
case V_40 :
case V_41 :
V_20 = V_141 ;
V_14 = V_20 -> V_14 ;
V_136 = F_80 ( V_141 , 0 , 0 , V_140 ) ;
break;
default:
return - V_43 ;
}
if ( F_87 ( V_136 ) )
return F_88 ( V_136 ) ;
if ( ! V_14 -> V_34 ) {
F_90 ( & V_37 , V_136 , 0 ,
V_25 , V_31 ) ;
} else {
F_24 () ;
F_91 ( V_136 , 0 , V_25 , V_142 ) ;
F_27 () ;
}
return 0 ;
}
static int T_5 F_92 ( struct V_35 * V_35 )
{
struct V_143 V_144 = {
. V_145 = F_61 ,
. V_48 = V_146 ,
} ;
V_35 -> V_36 = F_93 ( V_35 , V_139 , & V_144 ) ;
if ( ! V_35 -> V_36 && F_53 ( V_35 , & V_37 ) )
F_94 ( L_2 ) ;
if ( ! V_35 -> V_36 )
return - V_32 ;
return 0 ;
}
static void T_6 F_95 ( struct V_35 * V_35 )
{
F_96 ( V_35 -> V_36 ) ;
V_35 -> V_36 = NULL ;
}
static int T_7 F_97 ( void )
{
int V_10 , V_22 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_43 ( & V_6 [ V_10 ] ) ;
V_22 = F_45 ( & V_108 , & V_147 , 1 ) ;
if ( V_22 < 0 )
goto V_148;
V_22 = F_98 ( & V_149 ) ;
if ( V_22 )
goto V_148;
V_22 = F_18 ( & V_108 , & V_24 ) ;
if ( V_22 < 0 )
goto V_148;
return 0 ;
V_148:
F_94 ( L_3 , V_22 ) ;
}
static int F_99 ( struct V_70 * V_71 , T_4 V_72 , unsigned long V_150 ,
T_8 V_48 )
{
struct V_70 * V_42 ;
struct V_35 * V_35 , * V_151 = NULL ;
int V_22 ;
F_25 (net) {
if ( V_151 ) {
V_42 = F_100 ( V_71 , V_48 ) ;
if ( ! V_42 ) {
V_22 = - V_32 ;
goto error;
}
V_22 = F_101 ( V_151 -> V_36 , V_42 ,
V_72 , V_150 , V_48 ) ;
if ( V_22 )
goto error;
}
V_151 = V_35 ;
}
return F_101 ( V_151 -> V_36 , V_71 , V_72 , V_150 , V_48 ) ;
error:
F_102 ( V_71 ) ;
return V_22 ;
}
int F_91 ( struct V_70 * V_71 , T_4 V_72 , unsigned int V_150 ,
T_8 V_48 )
{
return F_99 ( V_71 , V_72 , V_150 , V_48 ) ;
}
void F_103 ( struct V_70 * V_71 , struct V_35 * V_35 , T_4 V_72 , T_4 V_150 ,
struct V_74 * V_75 , T_8 V_48 )
{
struct V_152 * V_82 = V_35 -> V_36 ;
int V_153 = 0 ;
if ( V_75 )
V_153 = F_104 ( V_75 ) ;
F_105 ( V_82 , V_71 , V_72 , V_150 , V_153 , V_48 ) ;
}
