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
static const struct V_12 * F_16 ( T_1 V_13 , struct V_7 * V_14 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_14 -> V_15 ; V_10 ++ )
if ( V_14 -> V_16 [ V_10 ] . V_13 == V_13 )
return & V_14 -> V_16 [ V_10 ] ;
return NULL ;
}
static T_2 F_17 ( void )
{
static T_2 V_17 = V_18 ;
int V_10 ;
for ( V_10 = 0 ; V_10 <= V_19 - V_18 ; V_10 ++ ) {
if ( V_17 != V_20 &&
V_17 != V_21 &&
! F_13 ( V_17 ) )
return V_17 ;
if ( ++ V_17 > V_19 )
V_17 = V_18 ;
}
return 0 ;
}
static int F_18 ( int V_22 , int * V_23 )
{
unsigned long * V_24 ;
int V_25 = 0 ;
int V_10 ;
int V_3 ;
bool V_26 ;
do {
if ( V_25 == 0 )
V_3 = F_19 ( V_27 ,
V_28 *
V_29 ) ;
else
V_3 = F_20 ( V_27 ,
V_28 * V_29 ,
V_25 ) ;
V_26 = true ;
for ( V_10 = V_3 ;
V_10 < F_21 ( int , V_3 + V_22 ,
V_28 * V_29 ) ;
V_10 ++ ) {
if ( F_22 ( V_10 , V_27 ) ) {
V_25 = V_10 ;
V_26 = false ;
break;
}
}
if ( V_3 >= V_28 * V_29 ) {
unsigned long V_30 = V_28 +
F_23 ( V_22 ) ;
T_3 V_31 = V_30 * sizeof( unsigned long ) ;
if ( V_27 == & V_32 ) {
V_24 = F_24 ( V_31 , V_33 ) ;
if ( ! V_24 )
return - V_34 ;
V_27 = V_24 ;
* V_27 = V_32 ;
} else {
V_24 = F_25 ( V_27 , V_31 ,
V_33 ) ;
if ( ! V_24 )
return - V_34 ;
V_27 = V_24 ;
for ( V_10 = 0 ; V_10 < F_23 ( V_22 ) ; V_10 ++ )
V_27 [ V_28 + V_10 ] = 0 ;
}
V_28 = V_30 ;
}
} while ( ! V_26 );
for ( V_10 = V_3 ; V_10 < V_3 + V_22 ; V_10 ++ )
F_26 ( V_10 , V_27 ) ;
* V_23 = V_3 ;
return 0 ;
}
static int F_27 ( struct V_7 * V_14 )
{
int V_23 ;
int V_22 = V_14 -> V_35 ;
int V_36 = 0 , V_10 ;
bool V_37 = false ;
if ( ! V_22 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_22 ; V_10 ++ ) {
const struct V_38 * V_39 = & V_14 -> V_40 [ V_10 ] ;
if ( F_28 ( V_39 -> V_9 [ 0 ] == '\0' ) )
return - V_41 ;
if ( F_28 ( memchr ( V_39 -> V_9 , '\0' , V_42 ) == NULL ) )
return - V_41 ;
}
if ( V_14 == & V_43 ) {
V_23 = V_44 ;
F_29 ( V_22 != 1 ) ;
} else if ( strcmp ( V_14 -> V_9 , L_1 ) == 0 ) {
V_23 = 1 ;
F_29 ( V_22 != 1 ) ;
} else if ( V_14 -> V_3 == V_20 ) {
V_23 = V_20 ;
F_29 ( V_22 != 1 ) ;
} else if ( V_14 -> V_3 == V_21 ) {
V_23 = V_21 ;
F_29 ( V_22 != 1 ) ;
} else {
V_37 = true ;
V_36 = F_18 ( V_22 , & V_23 ) ;
if ( V_36 )
return V_36 ;
}
V_14 -> V_45 = V_23 ;
if ( ! V_46 . V_47 )
return 0 ;
if ( V_14 -> V_48 ) {
struct V_49 * V_49 ;
F_30 () ;
F_31 () ;
F_32 (net) {
V_36 = F_33 ( V_49 -> V_47 ,
V_28 * V_29 ) ;
if ( V_36 ) {
break;
}
}
F_34 () ;
F_35 () ;
} else {
V_36 = F_36 ( V_46 . V_47 ,
V_28 * V_29 ) ;
}
if ( V_37 && V_36 ) {
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ )
F_37 ( V_14 -> V_45 + V_10 , V_27 ) ;
}
return V_36 ;
}
static void F_38 ( struct V_7 * V_14 )
{
struct V_49 * V_49 ;
int V_10 ;
F_30 () ;
F_31 () ;
F_32 (net) {
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ )
F_39 (
V_49 -> V_47 , V_14 -> V_45 + V_10 ) ;
}
F_34 () ;
F_35 () ;
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ ) {
int V_50 = V_14 -> V_45 + V_10 ;
if ( V_50 != 1 )
F_37 ( V_50 , V_27 ) ;
F_40 ( V_51 , V_14 ,
& V_14 -> V_40 [ V_10 ] , V_50 ) ;
}
}
static int F_41 ( struct V_7 * V_14 )
{
const struct V_12 * V_16 = V_14 -> V_16 ;
unsigned int V_15 = V_14 -> V_15 ;
int V_10 , V_52 ;
if ( F_28 ( V_15 && ! V_16 ) )
return - V_41 ;
if ( ! V_15 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_15 ; V_10 ++ ) {
if ( V_16 [ V_10 ] . V_53 == NULL && V_16 [ V_10 ] . V_54 == NULL )
return - V_41 ;
for ( V_52 = V_10 + 1 ; V_52 < V_15 ; V_52 ++ )
if ( V_16 [ V_10 ] . V_13 == V_16 [ V_52 ] . V_13 )
return - V_41 ;
}
V_14 -> V_16 = V_16 ;
V_14 -> V_15 = V_15 ;
return 0 ;
}
int F_42 ( struct V_7 * V_14 )
{
int V_36 = - V_41 , V_10 ;
if ( V_14 -> V_3 && V_14 -> V_3 < V_18 )
goto V_55;
if ( V_14 -> V_3 > V_19 )
goto V_55;
V_36 = F_41 ( V_14 ) ;
if ( V_36 )
return V_36 ;
F_7 () ;
if ( F_15 ( V_14 -> V_9 ) ) {
V_36 = - V_56 ;
goto V_57;
}
if ( V_14 -> V_3 == V_58 ) {
T_2 V_59 = F_17 () ;
if ( ! V_59 ) {
V_36 = - V_34 ;
goto V_57;
}
V_14 -> V_3 = V_59 ;
} else if ( F_13 ( V_14 -> V_3 ) ) {
V_36 = - V_56 ;
goto V_57;
}
if ( V_14 -> V_60 && ! V_14 -> V_61 ) {
V_14 -> V_62 = F_43 ( ( V_14 -> V_60 + 1 ) *
sizeof( struct V_63 * ) , V_33 ) ;
if ( V_14 -> V_62 == NULL ) {
V_36 = - V_34 ;
goto V_57;
}
} else
V_14 -> V_62 = NULL ;
V_36 = F_27 ( V_14 ) ;
if ( V_36 )
goto V_57;
F_44 ( & V_14 -> V_64 , F_12 ( V_14 -> V_3 ) ) ;
F_9 () ;
F_40 ( V_65 , V_14 , NULL , 0 ) ;
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ )
F_40 ( V_66 , V_14 ,
& V_14 -> V_40 [ V_10 ] , V_14 -> V_45 + V_10 ) ;
return 0 ;
V_57:
F_9 () ;
V_55:
return V_36 ;
}
int F_45 ( struct V_7 * V_14 )
{
struct V_7 * V_67 ;
F_7 () ;
F_38 ( V_14 ) ;
F_14 (rc, genl_family_chain(family->id), family_list) {
if ( V_14 -> V_3 != V_67 -> V_3 || strcmp ( V_67 -> V_9 , V_14 -> V_9 ) )
continue;
F_46 ( & V_67 -> V_64 ) ;
V_14 -> V_15 = 0 ;
F_9 () ;
F_47 ( V_14 -> V_62 ) ;
F_40 ( V_68 , V_14 , NULL , 0 ) ;
return 0 ;
}
F_9 () ;
return - V_69 ;
}
struct V_70 * F_48 ( T_3 V_71 , struct V_72 * V_73 ,
T_4 V_74 )
{
T_3 V_75 = F_49 ( F_50 ( V_71 ) ) ;
return F_51 ( V_73 -> V_76 , V_75 , V_73 -> V_77 , V_74 ) ;
}
void * F_52 ( struct V_70 * V_78 , T_5 V_79 , T_5 V_80 ,
struct V_7 * V_14 , int V_74 , T_1 V_13 )
{
struct V_81 * V_82 ;
struct V_83 * V_84 ;
V_82 = F_53 ( V_78 , V_79 , V_80 , V_14 -> V_3 , V_85 +
V_14 -> V_86 , V_74 ) ;
if ( V_82 == NULL )
return NULL ;
V_84 = F_54 ( V_82 ) ;
V_84 -> V_13 = V_13 ;
V_84 -> V_87 = V_14 -> V_87 ;
V_84 -> V_88 = 0 ;
return ( char * ) V_84 + V_85 ;
}
static int F_55 ( struct V_70 * V_78 , struct V_89 * V_90 )
{
const struct V_12 * V_16 = V_90 -> V_91 ;
int V_67 ;
F_1 () ;
V_67 = V_16 -> V_53 ( V_78 , V_90 ) ;
F_3 () ;
return V_67 ;
}
static int F_56 ( struct V_89 * V_90 )
{
const struct V_12 * V_16 = V_90 -> V_91 ;
int V_67 = 0 ;
if ( V_16 -> V_92 ) {
F_1 () ;
V_67 = V_16 -> V_92 ( V_90 ) ;
F_3 () ;
}
return V_67 ;
}
static int F_57 ( struct V_7 * V_14 ,
struct V_70 * V_78 ,
struct V_81 * V_82 )
{
const struct V_12 * V_16 ;
struct V_49 * V_49 = F_58 ( V_78 -> V_93 ) ;
struct V_72 V_73 ;
struct V_83 * V_84 = F_54 ( V_82 ) ;
struct V_63 * * V_62 ;
int V_94 , V_36 ;
if ( ! V_14 -> V_48 && ! F_59 ( V_49 , & V_46 ) )
return - V_69 ;
V_94 = V_85 + V_14 -> V_86 ;
if ( V_82 -> V_95 < F_60 ( V_94 ) )
return - V_41 ;
V_16 = F_16 ( V_84 -> V_13 , V_14 ) ;
if ( V_16 == NULL )
return - V_96 ;
if ( ( V_16 -> V_74 & V_97 ) &&
! F_61 ( V_98 ) )
return - V_99 ;
if ( ( V_82 -> V_100 & V_101 ) == V_101 ) {
int V_67 ;
if ( V_16 -> V_53 == NULL )
return - V_96 ;
if ( ! V_14 -> V_61 ) {
struct V_102 V_103 = {
. V_104 = V_14 -> V_104 ,
. V_91 = ( void * ) V_16 ,
. V_105 = F_55 ,
. V_92 = F_56 ,
} ;
F_3 () ;
V_67 = F_62 ( V_49 -> V_47 , V_78 , V_82 , & V_103 ) ;
F_1 () ;
} else {
struct V_102 V_103 = {
. V_104 = V_14 -> V_104 ,
. V_105 = V_16 -> V_53 ,
. V_92 = V_16 -> V_92 ,
} ;
V_67 = F_62 ( V_49 -> V_47 , V_78 , V_82 , & V_103 ) ;
}
return V_67 ;
}
if ( V_16 -> V_54 == NULL )
return - V_96 ;
if ( V_14 -> V_60 && V_14 -> V_61 ) {
V_62 = F_43 ( ( V_14 -> V_60 + 1 ) *
sizeof( struct V_63 * ) , V_33 ) ;
if ( V_62 == NULL )
return - V_34 ;
} else
V_62 = V_14 -> V_62 ;
if ( V_62 ) {
V_36 = F_63 ( V_82 , V_94 , V_62 , V_14 -> V_60 ,
V_16 -> V_106 ) ;
if ( V_36 < 0 )
goto V_107;
}
V_73 . V_108 = V_82 -> V_109 ;
V_73 . V_77 = F_64 ( V_78 ) . V_79 ;
V_73 . V_110 = V_82 ;
V_73 . V_111 = F_54 ( V_82 ) ;
V_73 . V_112 = F_54 ( V_82 ) + V_85 ;
V_73 . V_113 = V_62 ;
V_73 . V_76 = V_78 -> V_93 ;
F_65 ( & V_73 , V_49 ) ;
memset ( & V_73 . V_114 , 0 , sizeof( V_73 . V_114 ) ) ;
if ( V_14 -> V_115 ) {
V_36 = V_14 -> V_115 ( V_16 , V_78 , & V_73 ) ;
if ( V_36 )
goto V_107;
}
V_36 = V_16 -> V_54 ( V_78 , & V_73 ) ;
if ( V_14 -> V_116 )
V_14 -> V_116 ( V_16 , V_78 , & V_73 ) ;
V_107:
if ( V_14 -> V_61 )
F_47 ( V_62 ) ;
return V_36 ;
}
static int F_66 ( struct V_70 * V_78 , struct V_81 * V_82 )
{
struct V_7 * V_14 ;
int V_36 ;
V_14 = F_13 ( V_82 -> V_117 ) ;
if ( V_14 == NULL )
return - V_69 ;
if ( ! V_14 -> V_61 )
F_1 () ;
V_36 = F_57 ( V_14 , V_78 , V_82 ) ;
if ( ! V_14 -> V_61 )
F_3 () ;
return V_36 ;
}
static void F_67 ( struct V_70 * V_78 )
{
F_68 ( & V_2 ) ;
F_69 ( V_78 , & F_66 ) ;
F_70 ( & V_2 ) ;
}
static int F_71 ( struct V_7 * V_14 , T_5 V_79 , T_5 V_80 ,
T_5 V_74 , struct V_70 * V_78 , T_1 V_13 )
{
void * V_84 ;
V_84 = F_52 ( V_78 , V_79 , V_80 , & V_43 , V_74 , V_13 ) ;
if ( V_84 == NULL )
return - 1 ;
if ( F_72 ( V_78 , V_118 , V_14 -> V_9 ) ||
F_73 ( V_78 , V_119 , V_14 -> V_3 ) ||
F_74 ( V_78 , V_120 , V_14 -> V_87 ) ||
F_74 ( V_78 , V_121 , V_14 -> V_86 ) ||
F_74 ( V_78 , V_122 , V_14 -> V_60 ) )
goto V_123;
if ( V_14 -> V_15 ) {
struct V_63 * V_124 ;
int V_10 ;
V_124 = F_75 ( V_78 , V_125 ) ;
if ( V_124 == NULL )
goto V_123;
for ( V_10 = 0 ; V_10 < V_14 -> V_15 ; V_10 ++ ) {
struct V_63 * V_126 ;
const struct V_12 * V_16 = & V_14 -> V_16 [ V_10 ] ;
T_5 V_127 = V_16 -> V_74 ;
if ( V_16 -> V_53 )
V_127 |= V_128 ;
if ( V_16 -> V_54 )
V_127 |= V_129 ;
if ( V_16 -> V_106 )
V_127 |= V_130 ;
V_126 = F_75 ( V_78 , V_10 + 1 ) ;
if ( V_126 == NULL )
goto V_123;
if ( F_74 ( V_78 , V_131 , V_16 -> V_13 ) ||
F_74 ( V_78 , V_132 , V_127 ) )
goto V_123;
F_76 ( V_78 , V_126 ) ;
}
F_76 ( V_78 , V_124 ) ;
}
if ( V_14 -> V_35 ) {
struct V_63 * V_133 ;
int V_10 ;
V_133 = F_75 ( V_78 , V_134 ) ;
if ( V_133 == NULL )
goto V_123;
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ ) {
struct V_63 * V_126 ;
const struct V_38 * V_39 ;
V_39 = & V_14 -> V_40 [ V_10 ] ;
V_126 = F_75 ( V_78 , V_10 + 1 ) ;
if ( V_126 == NULL )
goto V_123;
if ( F_74 ( V_78 , V_135 ,
V_14 -> V_45 + V_10 ) ||
F_72 ( V_78 , V_136 ,
V_39 -> V_9 ) )
goto V_123;
F_76 ( V_78 , V_126 ) ;
}
F_76 ( V_78 , V_133 ) ;
}
return F_77 ( V_78 , V_84 ) ;
V_123:
F_78 ( V_78 , V_84 ) ;
return - V_137 ;
}
static int F_79 ( struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 , T_5 V_79 , T_5 V_80 , T_5 V_74 ,
struct V_70 * V_78 , T_1 V_13 )
{
void * V_84 ;
struct V_63 * V_133 ;
struct V_63 * V_126 ;
V_84 = F_52 ( V_78 , V_79 , V_80 , & V_43 , V_74 , V_13 ) ;
if ( V_84 == NULL )
return - 1 ;
if ( F_72 ( V_78 , V_118 , V_14 -> V_9 ) ||
F_73 ( V_78 , V_119 , V_14 -> V_3 ) )
goto V_123;
V_133 = F_75 ( V_78 , V_134 ) ;
if ( V_133 == NULL )
goto V_123;
V_126 = F_75 ( V_78 , 1 ) ;
if ( V_126 == NULL )
goto V_123;
if ( F_74 ( V_78 , V_135 , V_50 ) ||
F_72 ( V_78 , V_136 ,
V_39 -> V_9 ) )
goto V_123;
F_76 ( V_78 , V_126 ) ;
F_76 ( V_78 , V_133 ) ;
return F_77 ( V_78 , V_84 ) ;
V_123:
F_78 ( V_78 , V_84 ) ;
return - V_137 ;
}
static int F_80 ( struct V_70 * V_78 , struct V_89 * V_90 )
{
int V_10 , V_138 = 0 ;
struct V_7 * V_139 ;
struct V_49 * V_49 = F_58 ( V_78 -> V_93 ) ;
int V_140 = V_90 -> args [ 0 ] ;
int V_141 = V_90 -> args [ 1 ] ;
for ( V_10 = V_140 ; V_10 < V_11 ; V_10 ++ ) {
V_138 = 0 ;
F_14 (rt, genl_family_chain(i), family_list) {
if ( ! V_139 -> V_48 && ! F_59 ( V_49 , & V_46 ) )
continue;
if ( ++ V_138 < V_141 )
continue;
if ( F_71 ( V_139 , F_64 ( V_90 -> V_78 ) . V_79 ,
V_90 -> V_82 -> V_109 , V_142 ,
V_78 , V_65 ) < 0 )
goto V_55;
}
V_141 = 0 ;
}
V_55:
V_90 -> args [ 0 ] = V_10 ;
V_90 -> args [ 1 ] = V_138 ;
return V_78 -> V_75 ;
}
static struct V_70 * F_81 ( struct V_7 * V_14 ,
T_5 V_79 , int V_80 , T_1 V_13 )
{
struct V_70 * V_78 ;
int V_36 ;
V_78 = F_82 ( V_143 , V_33 ) ;
if ( V_78 == NULL )
return F_83 ( - V_144 ) ;
V_36 = F_71 ( V_14 , V_79 , V_80 , 0 , V_78 , V_13 ) ;
if ( V_36 < 0 ) {
F_84 ( V_78 ) ;
return F_83 ( V_36 ) ;
}
return V_78 ;
}
static struct V_70 *
F_85 ( struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 , T_5 V_79 , int V_80 , T_1 V_13 )
{
struct V_70 * V_78 ;
int V_36 ;
V_78 = F_82 ( V_143 , V_33 ) ;
if ( V_78 == NULL )
return F_83 ( - V_144 ) ;
V_36 = F_79 ( V_14 , V_39 , V_50 , V_79 ,
V_80 , 0 , V_78 , V_13 ) ;
if ( V_36 < 0 ) {
F_84 ( V_78 ) ;
return F_83 ( V_36 ) ;
}
return V_78 ;
}
static int F_86 ( struct V_70 * V_78 , struct V_72 * V_73 )
{
struct V_70 * V_145 ;
struct V_7 * V_146 = NULL ;
int V_36 = - V_41 ;
if ( V_73 -> V_113 [ V_119 ] ) {
T_2 V_3 = F_87 ( V_73 -> V_113 [ V_119 ] ) ;
V_146 = F_13 ( V_3 ) ;
V_36 = - V_69 ;
}
if ( V_73 -> V_113 [ V_118 ] ) {
char * V_9 ;
V_9 = F_88 ( V_73 -> V_113 [ V_118 ] ) ;
V_146 = F_15 ( V_9 ) ;
#ifdef F_89
if ( V_146 == NULL ) {
F_3 () ;
F_70 ( & V_2 ) ;
F_90 ( L_2 ,
V_147 , V_148 , V_9 ) ;
F_68 ( & V_2 ) ;
F_1 () ;
V_146 = F_15 ( V_9 ) ;
}
#endif
V_36 = - V_69 ;
}
if ( V_146 == NULL )
return V_36 ;
if ( ! V_146 -> V_48 && ! F_59 ( F_91 ( V_73 ) , & V_46 ) ) {
return - V_69 ;
}
V_145 = F_81 ( V_146 , V_73 -> V_77 , V_73 -> V_108 ,
V_65 ) ;
if ( F_92 ( V_145 ) )
return F_93 ( V_145 ) ;
return F_94 ( V_145 , V_73 ) ;
}
static int F_40 ( int V_149 , struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 )
{
struct V_70 * V_145 ;
if ( ! V_46 . V_47 )
return 0 ;
switch ( V_149 ) {
case V_65 :
case V_68 :
F_28 ( V_39 ) ;
V_145 = F_81 ( V_14 , 0 , 0 , V_149 ) ;
break;
case V_66 :
case V_51 :
F_29 ( ! V_39 ) ;
V_145 = F_85 ( V_14 , V_39 , V_50 , 0 , 0 , V_149 ) ;
break;
default:
return - V_41 ;
}
if ( F_92 ( V_145 ) )
return F_93 ( V_145 ) ;
if ( ! V_14 -> V_48 ) {
F_95 ( & V_43 , & V_46 , V_145 , 0 ,
0 , V_33 ) ;
} else {
F_31 () ;
F_96 ( & V_43 , V_145 , 0 ,
0 , V_150 ) ;
F_34 () ;
}
return 0 ;
}
static int T_6 F_97 ( struct V_49 * V_49 )
{
struct V_151 V_152 = {
. V_153 = F_67 ,
. V_74 = V_154 ,
} ;
V_49 -> V_47 = F_98 ( V_49 , V_148 , & V_152 ) ;
if ( ! V_49 -> V_47 && F_59 ( V_49 , & V_46 ) )
F_99 ( L_3 ) ;
if ( ! V_49 -> V_47 )
return - V_34 ;
return 0 ;
}
static void T_7 F_100 ( struct V_49 * V_49 )
{
F_101 ( V_49 -> V_47 ) ;
V_49 -> V_47 = NULL ;
}
static int T_8 F_102 ( void )
{
int V_10 , V_36 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_103 ( & V_6 [ V_10 ] ) ;
V_36 = F_104 ( & V_43 , V_155 ,
V_156 ) ;
if ( V_36 < 0 )
goto V_157;
V_36 = F_105 ( & V_158 ) ;
if ( V_36 )
goto V_157;
return 0 ;
V_157:
F_99 ( L_4 , V_36 ) ;
}
static int F_106 ( struct V_70 * V_78 , T_5 V_79 , unsigned long V_159 ,
T_4 V_74 )
{
struct V_70 * V_160 ;
struct V_49 * V_49 , * V_161 = NULL ;
int V_36 ;
F_32 (net) {
if ( V_161 ) {
V_160 = F_107 ( V_78 , V_74 ) ;
if ( ! V_160 ) {
V_36 = - V_34 ;
goto error;
}
V_36 = F_108 ( V_161 -> V_47 , V_160 ,
V_79 , V_159 , V_74 ) ;
if ( V_36 )
goto error;
}
V_161 = V_49 ;
}
return F_108 ( V_161 -> V_47 , V_78 , V_79 , V_159 , V_74 ) ;
error:
F_109 ( V_78 ) ;
return V_36 ;
}
int F_96 ( struct V_7 * V_14 , struct V_70 * V_78 ,
T_5 V_79 , unsigned int V_159 , T_4 V_74 )
{
if ( F_110 ( V_159 >= V_14 -> V_35 ) )
return - V_41 ;
V_159 = V_14 -> V_45 + V_159 ;
return F_106 ( V_78 , V_79 , V_159 , V_74 ) ;
}
void F_111 ( struct V_7 * V_14 ,
struct V_70 * V_78 , struct V_49 * V_49 , T_5 V_79 , T_5 V_159 ,
struct V_81 * V_82 , T_4 V_74 )
{
struct V_162 * V_93 = V_49 -> V_47 ;
int V_163 = 0 ;
if ( V_82 )
V_163 = F_112 ( V_82 ) ;
if ( F_110 ( V_159 >= V_14 -> V_35 ) )
return;
V_159 = V_14 -> V_45 + V_159 ;
F_113 ( V_93 , V_78 , V_79 , V_159 , V_163 , V_74 ) ;
}
