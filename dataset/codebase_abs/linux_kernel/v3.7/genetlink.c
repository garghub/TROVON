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
F_1 () ;
if ( V_19 == & V_22 )
V_2 = V_23 ;
else
V_2 = F_16 ( V_24 ,
V_25 * V_26 ) ;
if ( V_2 >= V_25 * V_26 ) {
T_3 V_27 = ( V_25 + 1 ) * sizeof( unsigned long ) ;
if ( V_24 == & V_28 ) {
V_20 = F_17 ( V_27 , V_29 ) ;
if ( ! V_20 ) {
V_21 = - V_30 ;
goto V_31;
}
V_24 = V_20 ;
* V_24 = V_28 ;
} else {
V_20 = F_18 ( V_24 , V_27 , V_29 ) ;
if ( ! V_20 ) {
V_21 = - V_30 ;
goto V_31;
}
V_24 = V_20 ;
V_24 [ V_25 ] = 0 ;
}
V_25 ++ ;
}
if ( V_13 -> V_32 ) {
struct V_33 * V_33 ;
F_19 () ;
F_20 () ;
F_21 (net) {
V_21 = F_22 ( V_33 -> V_34 ,
V_25 * V_26 ) ;
if ( V_21 ) {
F_23 () ;
F_24 () ;
goto V_31;
}
}
F_23 () ;
F_24 () ;
} else {
V_21 = F_25 ( V_35 . V_34 ,
V_25 * V_26 ) ;
if ( V_21 )
goto V_31;
}
V_19 -> V_2 = V_2 ;
F_26 ( V_2 , V_24 ) ;
F_27 ( & V_19 -> V_36 , & V_13 -> V_37 ) ;
V_19 -> V_13 = V_13 ;
F_28 ( V_38 , V_19 ) ;
V_31:
F_3 () ;
return V_21 ;
}
static void F_29 ( struct V_6 * V_13 ,
struct V_18 * V_19 )
{
struct V_33 * V_33 ;
F_15 ( V_19 -> V_13 != V_13 ) ;
F_19 () ;
F_20 () ;
F_21 (net)
F_30 ( V_33 -> V_34 , V_19 -> V_2 ) ;
F_23 () ;
F_24 () ;
F_31 ( V_19 -> V_2 , V_24 ) ;
F_32 ( & V_19 -> V_36 ) ;
F_28 ( V_39 , V_19 ) ;
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
struct V_18 * V_19 , * V_40 ;
F_35 (grp, tmp, &family->mcast_groups, list)
F_29 ( V_13 , V_19 ) ;
}
int F_36 ( struct V_6 * V_13 , struct V_11 * V_14 )
{
int V_21 = - V_41 ;
if ( V_14 -> V_42 == NULL && V_14 -> V_43 == NULL )
goto V_44;
if ( F_12 ( V_14 -> V_12 , V_13 ) ) {
V_21 = - V_45 ;
goto V_44;
}
if ( V_14 -> V_42 )
V_14 -> V_46 |= V_47 ;
if ( V_14 -> V_43 )
V_14 -> V_46 |= V_48 ;
if ( V_14 -> V_49 )
V_14 -> V_46 |= V_50 ;
F_1 () ;
F_27 ( & V_14 -> V_51 , & V_13 -> V_51 ) ;
F_3 () ;
F_28 ( V_52 , V_14 ) ;
V_21 = 0 ;
V_44:
return V_21 ;
}
int F_37 ( struct V_6 * V_13 , struct V_11 * V_14 )
{
struct V_11 * V_53 ;
F_1 () ;
F_10 (rc, &family->ops_list, ops_list) {
if ( V_53 == V_14 ) {
F_32 ( & V_14 -> V_51 ) ;
F_3 () ;
F_28 ( V_54 , V_14 ) ;
return 0 ;
}
}
F_3 () ;
return - V_55 ;
}
int F_38 ( struct V_6 * V_13 )
{
int V_21 = - V_41 ;
if ( V_13 -> V_2 && V_13 -> V_2 < V_16 )
goto V_44;
if ( V_13 -> V_2 > V_17 )
goto V_44;
F_39 ( & V_13 -> V_51 ) ;
F_39 ( & V_13 -> V_37 ) ;
F_1 () ;
if ( F_11 ( V_13 -> V_8 ) ) {
V_21 = - V_45 ;
goto V_56;
}
if ( V_13 -> V_2 == V_57 ) {
T_2 V_58 = F_13 () ;
if ( ! V_58 ) {
V_21 = - V_30 ;
goto V_56;
}
V_13 -> V_2 = V_58 ;
} else if ( F_9 ( V_13 -> V_2 ) ) {
V_21 = - V_45 ;
goto V_56;
}
if ( V_13 -> V_59 ) {
V_13 -> V_60 = F_40 ( ( V_13 -> V_59 + 1 ) *
sizeof( struct V_61 * ) , V_29 ) ;
if ( V_13 -> V_60 == NULL ) {
V_21 = - V_30 ;
goto V_56;
}
} else
V_13 -> V_60 = NULL ;
F_27 ( & V_13 -> V_62 , F_8 ( V_13 -> V_2 ) ) ;
F_3 () ;
F_28 ( V_63 , V_13 ) ;
return 0 ;
V_56:
F_3 () ;
V_44:
return V_21 ;
}
int F_41 ( struct V_6 * V_13 ,
struct V_11 * V_14 , T_3 V_64 )
{
int V_21 , V_9 ;
V_21 = F_38 ( V_13 ) ;
if ( V_21 )
return V_21 ;
for ( V_9 = 0 ; V_9 < V_64 ; ++ V_9 , ++ V_14 ) {
V_21 = F_36 ( V_13 , V_14 ) ;
if ( V_21 )
goto V_65;
}
return 0 ;
V_65:
F_42 ( V_13 ) ;
return V_21 ;
}
int F_42 ( struct V_6 * V_13 )
{
struct V_6 * V_53 ;
F_1 () ;
F_34 ( V_13 ) ;
F_10 (rc, genl_family_chain(family->id), family_list) {
if ( V_13 -> V_2 != V_53 -> V_2 || strcmp ( V_53 -> V_8 , V_13 -> V_8 ) )
continue;
F_32 ( & V_53 -> V_62 ) ;
F_39 ( & V_13 -> V_51 ) ;
F_3 () ;
F_43 ( V_13 -> V_60 ) ;
F_28 ( V_66 , V_13 ) ;
return 0 ;
}
F_3 () ;
return - V_55 ;
}
void * F_44 ( struct V_67 * V_68 , T_4 V_69 , T_4 V_70 ,
struct V_6 * V_13 , int V_46 , T_1 V_12 )
{
struct V_71 * V_72 ;
struct V_73 * V_74 ;
V_72 = F_45 ( V_68 , V_69 , V_70 , V_13 -> V_2 , V_75 +
V_13 -> V_76 , V_46 ) ;
if ( V_72 == NULL )
return NULL ;
V_74 = F_46 ( V_72 ) ;
V_74 -> V_12 = V_12 ;
V_74 -> V_77 = V_13 -> V_77 ;
V_74 -> V_78 = 0 ;
return ( char * ) V_74 + V_75 ;
}
static int F_47 ( struct V_67 * V_68 , struct V_71 * V_72 )
{
struct V_11 * V_14 ;
struct V_6 * V_13 ;
struct V_33 * V_33 = F_48 ( V_68 -> V_79 ) ;
struct V_80 V_81 ;
struct V_73 * V_74 = F_46 ( V_72 ) ;
int V_82 , V_21 ;
V_13 = F_9 ( V_72 -> V_83 ) ;
if ( V_13 == NULL )
return - V_55 ;
if ( ! V_13 -> V_32 && ! F_49 ( V_33 , & V_35 ) )
return - V_55 ;
V_82 = V_75 + V_13 -> V_76 ;
if ( V_72 -> V_84 < F_50 ( V_82 ) )
return - V_41 ;
V_14 = F_12 ( V_74 -> V_12 , V_13 ) ;
if ( V_14 == NULL )
return - V_85 ;
if ( ( V_14 -> V_46 & V_86 ) &&
! F_51 ( V_87 ) )
return - V_88 ;
if ( V_72 -> V_89 & V_90 ) {
if ( V_14 -> V_42 == NULL )
return - V_85 ;
F_3 () ;
{
struct V_91 V_92 = {
. V_93 = V_14 -> V_42 ,
. V_94 = V_14 -> V_94 ,
} ;
V_21 = F_52 ( V_33 -> V_34 , V_68 , V_72 , & V_92 ) ;
}
F_1 () ;
return V_21 ;
}
if ( V_14 -> V_43 == NULL )
return - V_85 ;
if ( V_13 -> V_60 ) {
V_21 = F_53 ( V_72 , V_82 , V_13 -> V_60 , V_13 -> V_59 ,
V_14 -> V_49 ) ;
if ( V_21 < 0 )
return V_21 ;
}
V_81 . V_95 = V_72 -> V_96 ;
V_81 . V_97 = F_54 ( V_68 ) . V_69 ;
V_81 . V_98 = V_72 ;
V_81 . V_99 = F_46 ( V_72 ) ;
V_81 . V_100 = F_46 ( V_72 ) + V_75 ;
V_81 . V_101 = V_13 -> V_60 ;
F_55 ( & V_81 , V_33 ) ;
memset ( & V_81 . V_102 , 0 , sizeof( V_81 . V_102 ) ) ;
if ( V_13 -> V_103 ) {
V_21 = V_13 -> V_103 ( V_14 , V_68 , & V_81 ) ;
if ( V_21 )
return V_21 ;
}
V_21 = V_14 -> V_43 ( V_68 , & V_81 ) ;
if ( V_13 -> V_104 )
V_13 -> V_104 ( V_14 , V_68 , & V_81 ) ;
return V_21 ;
}
static void F_56 ( struct V_67 * V_68 )
{
F_1 () ;
F_57 ( V_68 , & F_47 ) ;
F_3 () ;
}
static int F_58 ( struct V_6 * V_13 , T_4 V_69 , T_4 V_70 ,
T_4 V_46 , struct V_67 * V_68 , T_1 V_12 )
{
void * V_74 ;
V_74 = F_44 ( V_68 , V_69 , V_70 , & V_105 , V_46 , V_12 ) ;
if ( V_74 == NULL )
return - 1 ;
if ( F_59 ( V_68 , V_106 , V_13 -> V_8 ) ||
F_60 ( V_68 , V_107 , V_13 -> V_2 ) ||
F_61 ( V_68 , V_108 , V_13 -> V_77 ) ||
F_61 ( V_68 , V_109 , V_13 -> V_76 ) ||
F_61 ( V_68 , V_110 , V_13 -> V_59 ) )
goto V_111;
if ( ! F_62 ( & V_13 -> V_51 ) ) {
struct V_61 * V_112 ;
struct V_11 * V_14 ;
int V_113 = 1 ;
V_112 = F_63 ( V_68 , V_114 ) ;
if ( V_112 == NULL )
goto V_111;
F_10 (ops, &family->ops_list, ops_list) {
struct V_61 * V_115 ;
V_115 = F_63 ( V_68 , V_113 ++ ) ;
if ( V_115 == NULL )
goto V_111;
if ( F_61 ( V_68 , V_116 , V_14 -> V_12 ) ||
F_61 ( V_68 , V_117 , V_14 -> V_46 ) )
goto V_111;
F_64 ( V_68 , V_115 ) ;
}
F_64 ( V_68 , V_112 ) ;
}
if ( ! F_62 ( & V_13 -> V_37 ) ) {
struct V_18 * V_19 ;
struct V_61 * V_118 ;
int V_113 = 1 ;
V_118 = F_63 ( V_68 , V_119 ) ;
if ( V_118 == NULL )
goto V_111;
F_10 (grp, &family->mcast_groups, list) {
struct V_61 * V_115 ;
V_115 = F_63 ( V_68 , V_113 ++ ) ;
if ( V_115 == NULL )
goto V_111;
if ( F_61 ( V_68 , V_120 , V_19 -> V_2 ) ||
F_59 ( V_68 , V_121 ,
V_19 -> V_8 ) )
goto V_111;
F_64 ( V_68 , V_115 ) ;
}
F_64 ( V_68 , V_118 ) ;
}
return F_65 ( V_68 , V_74 ) ;
V_111:
F_66 ( V_68 , V_74 ) ;
return - V_122 ;
}
static int F_67 ( struct V_18 * V_19 , T_4 V_69 ,
T_4 V_70 , T_4 V_46 , struct V_67 * V_68 ,
T_1 V_12 )
{
void * V_74 ;
struct V_61 * V_118 ;
struct V_61 * V_115 ;
V_74 = F_44 ( V_68 , V_69 , V_70 , & V_105 , V_46 , V_12 ) ;
if ( V_74 == NULL )
return - 1 ;
if ( F_59 ( V_68 , V_106 , V_19 -> V_13 -> V_8 ) ||
F_60 ( V_68 , V_107 , V_19 -> V_13 -> V_2 ) )
goto V_111;
V_118 = F_63 ( V_68 , V_119 ) ;
if ( V_118 == NULL )
goto V_111;
V_115 = F_63 ( V_68 , 1 ) ;
if ( V_115 == NULL )
goto V_111;
if ( F_61 ( V_68 , V_120 , V_19 -> V_2 ) ||
F_59 ( V_68 , V_121 ,
V_19 -> V_8 ) )
goto V_111;
F_64 ( V_68 , V_115 ) ;
F_64 ( V_68 , V_118 ) ;
return F_65 ( V_68 , V_74 ) ;
V_111:
F_66 ( V_68 , V_74 ) ;
return - V_122 ;
}
static int F_68 ( struct V_67 * V_68 , struct V_123 * V_124 )
{
int V_9 , V_125 = 0 ;
struct V_6 * V_126 ;
struct V_33 * V_33 = F_48 ( V_68 -> V_79 ) ;
int V_127 = V_124 -> args [ 0 ] ;
int V_128 = V_124 -> args [ 1 ] ;
for ( V_9 = V_127 ; V_9 < V_10 ; V_9 ++ ) {
V_125 = 0 ;
F_10 (rt, genl_family_chain(i), family_list) {
if ( ! V_126 -> V_32 && ! F_49 ( V_33 , & V_35 ) )
continue;
if ( ++ V_125 < V_128 )
continue;
if ( F_58 ( V_126 , F_54 ( V_124 -> V_68 ) . V_69 ,
V_124 -> V_72 -> V_96 , V_129 ,
V_68 , V_63 ) < 0 )
goto V_44;
}
V_128 = 0 ;
}
V_44:
V_124 -> args [ 0 ] = V_9 ;
V_124 -> args [ 1 ] = V_125 ;
return V_68 -> V_130 ;
}
static struct V_67 * F_69 ( struct V_6 * V_13 ,
T_4 V_69 , int V_70 , T_1 V_12 )
{
struct V_67 * V_68 ;
int V_21 ;
V_68 = F_70 ( V_131 , V_29 ) ;
if ( V_68 == NULL )
return F_71 ( - V_132 ) ;
V_21 = F_58 ( V_13 , V_69 , V_70 , 0 , V_68 , V_12 ) ;
if ( V_21 < 0 ) {
F_72 ( V_68 ) ;
return F_71 ( V_21 ) ;
}
return V_68 ;
}
static struct V_67 * F_73 ( struct V_18 * V_19 ,
T_4 V_69 , int V_70 , T_1 V_12 )
{
struct V_67 * V_68 ;
int V_21 ;
V_68 = F_70 ( V_131 , V_29 ) ;
if ( V_68 == NULL )
return F_71 ( - V_132 ) ;
V_21 = F_67 ( V_19 , V_69 , V_70 , 0 , V_68 , V_12 ) ;
if ( V_21 < 0 ) {
F_72 ( V_68 ) ;
return F_71 ( V_21 ) ;
}
return V_68 ;
}
static int F_74 ( struct V_67 * V_68 , struct V_80 * V_81 )
{
struct V_67 * V_133 ;
struct V_6 * V_134 = NULL ;
int V_21 = - V_41 ;
if ( V_81 -> V_101 [ V_107 ] ) {
T_2 V_2 = F_75 ( V_81 -> V_101 [ V_107 ] ) ;
V_134 = F_9 ( V_2 ) ;
V_21 = - V_55 ;
}
if ( V_81 -> V_101 [ V_106 ] ) {
char * V_8 ;
V_8 = F_76 ( V_81 -> V_101 [ V_106 ] ) ;
V_134 = F_11 ( V_8 ) ;
#ifdef F_77
if ( V_134 == NULL ) {
F_3 () ;
F_78 ( L_1 ,
V_135 , V_136 , V_8 ) ;
F_1 () ;
V_134 = F_11 ( V_8 ) ;
}
#endif
V_21 = - V_55 ;
}
if ( V_134 == NULL )
return V_21 ;
if ( ! V_134 -> V_32 && ! F_49 ( F_79 ( V_81 ) , & V_35 ) ) {
return - V_55 ;
}
V_133 = F_69 ( V_134 , V_81 -> V_97 , V_81 -> V_95 ,
V_63 ) ;
if ( F_80 ( V_133 ) )
return F_81 ( V_133 ) ;
return F_82 ( V_133 , V_81 ) ;
}
static int F_28 ( int V_137 , void * V_138 )
{
struct V_67 * V_133 ;
struct V_6 * V_13 ;
struct V_18 * V_19 ;
if ( ! V_35 . V_34 )
return 0 ;
switch ( V_137 ) {
case V_63 :
case V_66 :
V_13 = V_138 ;
V_133 = F_69 ( V_13 , 0 , 0 , V_137 ) ;
break;
case V_38 :
case V_39 :
V_19 = V_138 ;
V_13 = V_19 -> V_13 ;
V_133 = F_73 ( V_138 , 0 , 0 , V_137 ) ;
break;
default:
return - V_41 ;
}
if ( F_80 ( V_133 ) )
return F_81 ( V_133 ) ;
if ( ! V_13 -> V_32 ) {
F_83 ( & V_35 , V_133 , 0 ,
V_23 , V_29 ) ;
} else {
F_20 () ;
F_84 ( V_133 , 0 , V_23 , V_139 ) ;
F_23 () ;
}
return 0 ;
}
static int T_5 F_85 ( struct V_33 * V_33 )
{
struct V_140 V_141 = {
. V_142 = F_56 ,
. V_143 = & V_1 ,
. V_46 = V_144 ,
} ;
V_33 -> V_34 = F_86 ( V_33 , V_136 , & V_141 ) ;
if ( ! V_33 -> V_34 && F_49 ( V_33 , & V_35 ) )
F_87 ( L_2 ) ;
if ( ! V_33 -> V_34 )
return - V_30 ;
return 0 ;
}
static void T_6 F_88 ( struct V_33 * V_33 )
{
F_89 ( V_33 -> V_34 ) ;
V_33 -> V_34 = NULL ;
}
static int T_7 F_90 ( void )
{
int V_9 , V_21 ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ )
F_39 ( & V_5 [ V_9 ] ) ;
V_21 = F_41 ( & V_105 , & V_145 , 1 ) ;
if ( V_21 < 0 )
goto V_146;
V_21 = F_91 ( & V_147 ) ;
if ( V_21 )
goto V_146;
V_21 = F_14 ( & V_105 , & V_22 ) ;
if ( V_21 < 0 )
goto V_146;
return 0 ;
V_146:
F_87 ( L_3 , V_21 ) ;
}
static int F_92 ( struct V_67 * V_68 , T_4 V_69 , unsigned long V_148 ,
T_8 V_46 )
{
struct V_67 * V_40 ;
struct V_33 * V_33 , * V_149 = NULL ;
int V_21 ;
F_21 (net) {
if ( V_149 ) {
V_40 = F_93 ( V_68 , V_46 ) ;
if ( ! V_40 ) {
V_21 = - V_30 ;
goto error;
}
V_21 = F_94 ( V_149 -> V_34 , V_40 ,
V_69 , V_148 , V_46 ) ;
if ( V_21 )
goto error;
}
V_149 = V_33 ;
}
return F_94 ( V_149 -> V_34 , V_68 , V_69 , V_148 , V_46 ) ;
error:
F_95 ( V_68 ) ;
return V_21 ;
}
int F_84 ( struct V_67 * V_68 , T_4 V_69 , unsigned int V_148 ,
T_8 V_46 )
{
return F_92 ( V_68 , V_69 , V_148 , V_46 ) ;
}
void F_96 ( struct V_67 * V_68 , struct V_33 * V_33 , T_4 V_69 , T_4 V_148 ,
struct V_71 * V_72 , T_8 V_46 )
{
struct V_150 * V_79 = V_33 -> V_34 ;
int V_151 = 0 ;
if ( V_72 )
V_151 = F_97 ( V_72 ) ;
F_98 ( V_79 , V_68 , V_69 , V_148 , V_151 , V_46 ) ;
}
