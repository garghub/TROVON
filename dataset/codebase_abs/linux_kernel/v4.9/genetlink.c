void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
bool F_5 ( void )
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
if ( V_3 + V_22 > V_28 * V_29 ) {
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
static int F_41 ( const struct V_7 * V_14 )
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
goto V_64;
F_44 ( & V_14 -> V_65 , F_12 ( V_14 -> V_3 ) ) ;
F_9 () ;
F_40 ( V_66 , V_14 , NULL , 0 ) ;
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ )
F_40 ( V_67 , V_14 ,
& V_14 -> V_40 [ V_10 ] , V_14 -> V_45 + V_10 ) ;
return 0 ;
V_64:
F_45 ( V_14 -> V_62 ) ;
V_57:
F_9 () ;
V_55:
return V_36 ;
}
int F_46 ( struct V_7 * V_14 )
{
struct V_7 * V_68 ;
F_7 () ;
F_14 (rc, genl_family_chain(family->id), family_list) {
if ( V_14 -> V_3 != V_68 -> V_3 || strcmp ( V_68 -> V_9 , V_14 -> V_9 ) )
continue;
F_38 ( V_14 ) ;
F_47 ( & V_68 -> V_65 ) ;
V_14 -> V_15 = 0 ;
F_10 ( & V_2 ) ;
F_48 ( V_69 ,
F_49 ( & V_70 ) == 0 ) ;
F_3 () ;
F_45 ( V_14 -> V_62 ) ;
F_40 ( V_71 , V_14 , NULL , 0 ) ;
return 0 ;
}
F_9 () ;
return - V_72 ;
}
void * F_50 ( struct V_73 * V_74 , T_4 V_75 , T_4 V_76 ,
struct V_7 * V_14 , int V_77 , T_1 V_13 )
{
struct V_78 * V_79 ;
struct V_80 * V_81 ;
V_79 = F_51 ( V_74 , V_75 , V_76 , V_14 -> V_3 , V_82 +
V_14 -> V_83 , V_77 ) ;
if ( V_79 == NULL )
return NULL ;
V_81 = F_52 ( V_79 ) ;
V_81 -> V_13 = V_13 ;
V_81 -> V_84 = V_14 -> V_84 ;
V_81 -> V_85 = 0 ;
return ( char * ) V_81 + V_82 ;
}
static int F_53 ( struct V_86 * V_87 )
{
const struct V_12 * V_16 = V_87 -> V_88 ;
int V_68 = 0 ;
if ( V_16 -> V_25 ) {
F_1 () ;
V_68 = V_16 -> V_25 ( V_87 ) ;
F_3 () ;
}
return V_68 ;
}
static int F_54 ( struct V_73 * V_74 , struct V_86 * V_87 )
{
const struct V_12 * V_16 = V_87 -> V_88 ;
int V_68 ;
F_1 () ;
V_68 = V_16 -> V_53 ( V_74 , V_87 ) ;
F_3 () ;
return V_68 ;
}
static int F_55 ( struct V_86 * V_87 )
{
const struct V_12 * V_16 = V_87 -> V_88 ;
int V_68 = 0 ;
if ( V_16 -> V_89 ) {
F_1 () ;
V_68 = V_16 -> V_89 ( V_87 ) ;
F_3 () ;
}
return V_68 ;
}
static int F_56 ( struct V_7 * V_14 ,
struct V_73 * V_74 ,
struct V_78 * V_79 )
{
const struct V_12 * V_16 ;
struct V_49 * V_49 = F_57 ( V_74 -> V_90 ) ;
struct V_91 V_92 ;
struct V_80 * V_81 = F_52 ( V_79 ) ;
struct V_63 * * V_62 ;
int V_93 , V_36 ;
if ( ! V_14 -> V_48 && ! F_58 ( V_49 , & V_46 ) )
return - V_72 ;
V_93 = V_82 + V_14 -> V_83 ;
if ( V_79 -> V_94 < F_59 ( V_93 ) )
return - V_41 ;
V_16 = F_16 ( V_81 -> V_13 , V_14 ) ;
if ( V_16 == NULL )
return - V_95 ;
if ( ( V_16 -> V_77 & V_96 ) &&
! F_60 ( V_74 , V_97 ) )
return - V_98 ;
if ( ( V_16 -> V_77 & V_99 ) &&
! F_61 ( V_74 , V_49 -> V_100 , V_97 ) )
return - V_98 ;
if ( ( V_79 -> V_101 & V_102 ) == V_102 ) {
int V_68 ;
if ( V_16 -> V_53 == NULL )
return - V_95 ;
if ( ! V_14 -> V_61 ) {
struct V_103 V_104 = {
. V_105 = V_14 -> V_105 ,
. V_88 = ( void * ) V_16 ,
. V_25 = F_53 ,
. V_106 = F_54 ,
. V_89 = F_55 ,
} ;
F_3 () ;
V_68 = F_62 ( V_49 -> V_47 , V_74 , V_79 , & V_104 ) ;
F_1 () ;
} else {
struct V_103 V_104 = {
. V_105 = V_14 -> V_105 ,
. V_25 = V_16 -> V_25 ,
. V_106 = V_16 -> V_53 ,
. V_89 = V_16 -> V_89 ,
} ;
V_68 = F_62 ( V_49 -> V_47 , V_74 , V_79 , & V_104 ) ;
}
return V_68 ;
}
if ( V_16 -> V_54 == NULL )
return - V_95 ;
if ( V_14 -> V_60 && V_14 -> V_61 ) {
V_62 = F_43 ( ( V_14 -> V_60 + 1 ) *
sizeof( struct V_63 * ) , V_33 ) ;
if ( V_62 == NULL )
return - V_34 ;
} else
V_62 = V_14 -> V_62 ;
if ( V_62 ) {
V_36 = F_63 ( V_79 , V_93 , V_62 , V_14 -> V_60 ,
V_16 -> V_107 ) ;
if ( V_36 < 0 )
goto V_108;
}
V_92 . V_109 = V_79 -> V_110 ;
V_92 . V_111 = F_64 ( V_74 ) . V_75 ;
V_92 . V_112 = V_79 ;
V_92 . V_113 = F_52 ( V_79 ) ;
V_92 . V_114 = F_52 ( V_79 ) + V_82 ;
V_92 . V_115 = V_62 ;
F_65 ( & V_92 , V_49 ) ;
memset ( & V_92 . V_116 , 0 , sizeof( V_92 . V_116 ) ) ;
if ( V_14 -> V_117 ) {
V_36 = V_14 -> V_117 ( V_16 , V_74 , & V_92 ) ;
if ( V_36 )
goto V_108;
}
V_36 = V_16 -> V_54 ( V_74 , & V_92 ) ;
if ( V_14 -> V_118 )
V_14 -> V_118 ( V_16 , V_74 , & V_92 ) ;
V_108:
if ( V_14 -> V_61 )
F_45 ( V_62 ) ;
return V_36 ;
}
static int F_66 ( struct V_73 * V_74 , struct V_78 * V_79 )
{
struct V_7 * V_14 ;
int V_36 ;
V_14 = F_13 ( V_79 -> V_119 ) ;
if ( V_14 == NULL )
return - V_72 ;
if ( ! V_14 -> V_61 )
F_1 () ;
V_36 = F_56 ( V_14 , V_74 , V_79 ) ;
if ( ! V_14 -> V_61 )
F_3 () ;
return V_36 ;
}
static void F_67 ( struct V_73 * V_74 )
{
F_68 ( & V_2 ) ;
F_69 ( V_74 , & F_66 ) ;
F_70 ( & V_2 ) ;
}
static int F_71 ( struct V_7 * V_14 , T_4 V_75 , T_4 V_76 ,
T_4 V_77 , struct V_73 * V_74 , T_1 V_13 )
{
void * V_81 ;
V_81 = F_50 ( V_74 , V_75 , V_76 , & V_43 , V_77 , V_13 ) ;
if ( V_81 == NULL )
return - 1 ;
if ( F_72 ( V_74 , V_120 , V_14 -> V_9 ) ||
F_73 ( V_74 , V_121 , V_14 -> V_3 ) ||
F_74 ( V_74 , V_122 , V_14 -> V_84 ) ||
F_74 ( V_74 , V_123 , V_14 -> V_83 ) ||
F_74 ( V_74 , V_124 , V_14 -> V_60 ) )
goto V_125;
if ( V_14 -> V_15 ) {
struct V_63 * V_126 ;
int V_10 ;
V_126 = F_75 ( V_74 , V_127 ) ;
if ( V_126 == NULL )
goto V_125;
for ( V_10 = 0 ; V_10 < V_14 -> V_15 ; V_10 ++ ) {
struct V_63 * V_128 ;
const struct V_12 * V_16 = & V_14 -> V_16 [ V_10 ] ;
T_4 V_129 = V_16 -> V_77 ;
if ( V_16 -> V_53 )
V_129 |= V_130 ;
if ( V_16 -> V_54 )
V_129 |= V_131 ;
if ( V_16 -> V_107 )
V_129 |= V_132 ;
V_128 = F_75 ( V_74 , V_10 + 1 ) ;
if ( V_128 == NULL )
goto V_125;
if ( F_74 ( V_74 , V_133 , V_16 -> V_13 ) ||
F_74 ( V_74 , V_134 , V_129 ) )
goto V_125;
F_76 ( V_74 , V_128 ) ;
}
F_76 ( V_74 , V_126 ) ;
}
if ( V_14 -> V_35 ) {
struct V_63 * V_135 ;
int V_10 ;
V_135 = F_75 ( V_74 , V_136 ) ;
if ( V_135 == NULL )
goto V_125;
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ ) {
struct V_63 * V_128 ;
const struct V_38 * V_39 ;
V_39 = & V_14 -> V_40 [ V_10 ] ;
V_128 = F_75 ( V_74 , V_10 + 1 ) ;
if ( V_128 == NULL )
goto V_125;
if ( F_74 ( V_74 , V_137 ,
V_14 -> V_45 + V_10 ) ||
F_72 ( V_74 , V_138 ,
V_39 -> V_9 ) )
goto V_125;
F_76 ( V_74 , V_128 ) ;
}
F_76 ( V_74 , V_135 ) ;
}
F_77 ( V_74 , V_81 ) ;
return 0 ;
V_125:
F_78 ( V_74 , V_81 ) ;
return - V_139 ;
}
static int F_79 ( struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 , T_4 V_75 , T_4 V_76 , T_4 V_77 ,
struct V_73 * V_74 , T_1 V_13 )
{
void * V_81 ;
struct V_63 * V_135 ;
struct V_63 * V_128 ;
V_81 = F_50 ( V_74 , V_75 , V_76 , & V_43 , V_77 , V_13 ) ;
if ( V_81 == NULL )
return - 1 ;
if ( F_72 ( V_74 , V_120 , V_14 -> V_9 ) ||
F_73 ( V_74 , V_121 , V_14 -> V_3 ) )
goto V_125;
V_135 = F_75 ( V_74 , V_136 ) ;
if ( V_135 == NULL )
goto V_125;
V_128 = F_75 ( V_74 , 1 ) ;
if ( V_128 == NULL )
goto V_125;
if ( F_74 ( V_74 , V_137 , V_50 ) ||
F_72 ( V_74 , V_138 ,
V_39 -> V_9 ) )
goto V_125;
F_76 ( V_74 , V_128 ) ;
F_76 ( V_74 , V_135 ) ;
F_77 ( V_74 , V_81 ) ;
return 0 ;
V_125:
F_78 ( V_74 , V_81 ) ;
return - V_139 ;
}
static int F_80 ( struct V_73 * V_74 , struct V_86 * V_87 )
{
int V_10 , V_140 = 0 ;
struct V_7 * V_141 ;
struct V_49 * V_49 = F_57 ( V_74 -> V_90 ) ;
int V_142 = V_87 -> args [ 0 ] ;
int V_143 = V_87 -> args [ 1 ] ;
for ( V_10 = V_142 ; V_10 < V_11 ; V_10 ++ ) {
V_140 = 0 ;
F_14 (rt, genl_family_chain(i), family_list) {
if ( ! V_141 -> V_48 && ! F_58 ( V_49 , & V_46 ) )
continue;
if ( ++ V_140 < V_143 )
continue;
if ( F_71 ( V_141 , F_64 ( V_87 -> V_74 ) . V_75 ,
V_87 -> V_79 -> V_110 , V_144 ,
V_74 , V_66 ) < 0 )
goto V_55;
}
V_143 = 0 ;
}
V_55:
V_87 -> args [ 0 ] = V_10 ;
V_87 -> args [ 1 ] = V_140 ;
return V_74 -> V_145 ;
}
static struct V_73 * F_81 ( struct V_7 * V_14 ,
T_4 V_75 , int V_76 , T_1 V_13 )
{
struct V_73 * V_74 ;
int V_36 ;
V_74 = F_82 ( V_146 , V_33 ) ;
if ( V_74 == NULL )
return F_83 ( - V_147 ) ;
V_36 = F_71 ( V_14 , V_75 , V_76 , 0 , V_74 , V_13 ) ;
if ( V_36 < 0 ) {
F_84 ( V_74 ) ;
return F_83 ( V_36 ) ;
}
return V_74 ;
}
static struct V_73 *
F_85 ( struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 , T_4 V_75 , int V_76 , T_1 V_13 )
{
struct V_73 * V_74 ;
int V_36 ;
V_74 = F_82 ( V_146 , V_33 ) ;
if ( V_74 == NULL )
return F_83 ( - V_147 ) ;
V_36 = F_79 ( V_14 , V_39 , V_50 , V_75 ,
V_76 , 0 , V_74 , V_13 ) ;
if ( V_36 < 0 ) {
F_84 ( V_74 ) ;
return F_83 ( V_36 ) ;
}
return V_74 ;
}
static int F_86 ( struct V_73 * V_74 , struct V_91 * V_92 )
{
struct V_73 * V_148 ;
struct V_7 * V_149 = NULL ;
int V_36 = - V_41 ;
if ( V_92 -> V_115 [ V_121 ] ) {
T_2 V_3 = F_87 ( V_92 -> V_115 [ V_121 ] ) ;
V_149 = F_13 ( V_3 ) ;
V_36 = - V_72 ;
}
if ( V_92 -> V_115 [ V_120 ] ) {
char * V_9 ;
V_9 = F_88 ( V_92 -> V_115 [ V_120 ] ) ;
V_149 = F_15 ( V_9 ) ;
#ifdef F_89
if ( V_149 == NULL ) {
F_3 () ;
F_70 ( & V_2 ) ;
F_90 ( L_2 ,
V_150 , V_151 , V_9 ) ;
F_68 ( & V_2 ) ;
F_1 () ;
V_149 = F_15 ( V_9 ) ;
}
#endif
V_36 = - V_72 ;
}
if ( V_149 == NULL )
return V_36 ;
if ( ! V_149 -> V_48 && ! F_58 ( F_91 ( V_92 ) , & V_46 ) ) {
return - V_72 ;
}
V_148 = F_81 ( V_149 , V_92 -> V_111 , V_92 -> V_109 ,
V_66 ) ;
if ( F_92 ( V_148 ) )
return F_93 ( V_148 ) ;
return F_94 ( V_148 , V_92 ) ;
}
static int F_40 ( int V_152 , struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 )
{
struct V_73 * V_148 ;
if ( ! V_46 . V_47 )
return 0 ;
switch ( V_152 ) {
case V_66 :
case V_71 :
F_28 ( V_39 ) ;
V_148 = F_81 ( V_14 , 0 , 0 , V_152 ) ;
break;
case V_67 :
case V_51 :
F_29 ( ! V_39 ) ;
V_148 = F_85 ( V_14 , V_39 , V_50 , 0 , 0 , V_152 ) ;
break;
default:
return - V_41 ;
}
if ( F_92 ( V_148 ) )
return F_93 ( V_148 ) ;
if ( ! V_14 -> V_48 ) {
F_95 ( & V_43 , & V_46 , V_148 , 0 ,
0 , V_33 ) ;
} else {
F_31 () ;
F_96 ( & V_43 , V_148 , 0 ,
0 , V_153 ) ;
F_34 () ;
}
return 0 ;
}
static int F_97 ( struct V_49 * V_49 , int V_154 )
{
int V_10 , V_36 = - V_72 ;
F_68 ( & V_2 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_7 * V_8 ;
F_14 (f, genl_family_chain(i), family_list) {
if ( V_154 >= V_8 -> V_45 &&
V_154 < V_8 -> V_45 + V_8 -> V_35 ) {
int V_155 = V_154 - V_8 -> V_45 ;
if ( ! V_8 -> V_48 && V_49 != & V_46 )
V_36 = - V_72 ;
else if ( V_8 -> V_156 )
V_36 = V_8 -> V_156 ( V_49 , V_155 ) ;
else
V_36 = 0 ;
break;
}
}
}
F_70 ( & V_2 ) ;
return V_36 ;
}
static void F_98 ( struct V_49 * V_49 , int V_154 )
{
int V_10 ;
F_68 ( & V_2 ) ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
struct V_7 * V_8 ;
F_14 (f, genl_family_chain(i), family_list) {
if ( V_154 >= V_8 -> V_45 &&
V_154 < V_8 -> V_45 + V_8 -> V_35 ) {
int V_155 = V_154 - V_8 -> V_45 ;
if ( V_8 -> V_157 )
V_8 -> V_157 ( V_49 , V_155 ) ;
break;
}
}
}
F_70 ( & V_2 ) ;
}
static int T_5 F_99 ( struct V_49 * V_49 )
{
struct V_158 V_159 = {
. V_160 = F_67 ,
. V_77 = V_161 ,
. V_162 = F_97 ,
. V_163 = F_98 ,
} ;
V_49 -> V_47 = F_100 ( V_49 , V_151 , & V_159 ) ;
if ( ! V_49 -> V_47 && F_58 ( V_49 , & V_46 ) )
F_101 ( L_3 ) ;
if ( ! V_49 -> V_47 )
return - V_34 ;
return 0 ;
}
static void T_6 F_102 ( struct V_49 * V_49 )
{
F_103 ( V_49 -> V_47 ) ;
V_49 -> V_47 = NULL ;
}
static int T_7 F_104 ( void )
{
int V_10 , V_36 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_105 ( & V_6 [ V_10 ] ) ;
V_36 = F_106 ( & V_43 , V_164 ,
V_165 ) ;
if ( V_36 < 0 )
goto V_166;
V_36 = F_107 ( & V_167 ) ;
if ( V_36 )
goto V_166;
return 0 ;
V_166:
F_101 ( L_4 , V_36 ) ;
}
static int F_108 ( struct V_73 * V_74 , T_4 V_75 , unsigned long V_154 ,
T_8 V_77 )
{
struct V_73 * V_168 ;
struct V_49 * V_49 , * V_169 = NULL ;
int V_36 ;
F_32 (net) {
if ( V_169 ) {
V_168 = F_109 ( V_74 , V_77 ) ;
if ( ! V_168 ) {
V_36 = - V_34 ;
goto error;
}
V_36 = F_110 ( V_169 -> V_47 , V_168 ,
V_75 , V_154 , V_77 ) ;
if ( V_36 )
goto error;
}
V_169 = V_49 ;
}
return F_110 ( V_169 -> V_47 , V_74 , V_75 , V_154 , V_77 ) ;
error:
F_111 ( V_74 ) ;
return V_36 ;
}
int F_96 ( struct V_7 * V_14 , struct V_73 * V_74 ,
T_4 V_75 , unsigned int V_154 , T_8 V_77 )
{
if ( F_112 ( V_154 >= V_14 -> V_35 ) )
return - V_41 ;
V_154 = V_14 -> V_45 + V_154 ;
return F_108 ( V_74 , V_75 , V_154 , V_77 ) ;
}
void F_113 ( struct V_7 * V_14 , struct V_73 * V_74 ,
struct V_91 * V_92 , T_4 V_154 , T_8 V_77 )
{
struct V_49 * V_49 = F_91 ( V_92 ) ;
struct V_170 * V_90 = V_49 -> V_47 ;
int V_171 = 0 ;
if ( V_92 -> V_112 )
V_171 = F_114 ( V_92 -> V_112 ) ;
if ( F_112 ( V_154 >= V_14 -> V_35 ) )
return;
V_154 = V_14 -> V_45 + V_154 ;
F_115 ( V_90 , V_74 , V_92 -> V_111 , V_154 , V_171 , V_77 ) ;
}
