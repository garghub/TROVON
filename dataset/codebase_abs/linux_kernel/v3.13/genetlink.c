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
void * F_48 ( struct V_70 * V_71 , T_4 V_72 , T_4 V_73 ,
struct V_7 * V_14 , int V_74 , T_1 V_13 )
{
struct V_75 * V_76 ;
struct V_77 * V_78 ;
V_76 = F_49 ( V_71 , V_72 , V_73 , V_14 -> V_3 , V_79 +
V_14 -> V_80 , V_74 ) ;
if ( V_76 == NULL )
return NULL ;
V_78 = F_50 ( V_76 ) ;
V_78 -> V_13 = V_13 ;
V_78 -> V_81 = V_14 -> V_81 ;
V_78 -> V_82 = 0 ;
return ( char * ) V_78 + V_79 ;
}
static int F_51 ( struct V_70 * V_71 , struct V_83 * V_84 )
{
const struct V_12 * V_16 = V_84 -> V_85 ;
int V_67 ;
F_1 () ;
V_67 = V_16 -> V_53 ( V_71 , V_84 ) ;
F_3 () ;
return V_67 ;
}
static int F_52 ( struct V_83 * V_84 )
{
const struct V_12 * V_16 = V_84 -> V_85 ;
int V_67 = 0 ;
if ( V_16 -> V_86 ) {
F_1 () ;
V_67 = V_16 -> V_86 ( V_84 ) ;
F_3 () ;
}
return V_67 ;
}
static int F_53 ( struct V_7 * V_14 ,
struct V_70 * V_71 ,
struct V_75 * V_76 )
{
const struct V_12 * V_16 ;
struct V_49 * V_49 = F_54 ( V_71 -> V_87 ) ;
struct V_88 V_89 ;
struct V_77 * V_78 = F_50 ( V_76 ) ;
struct V_63 * * V_62 ;
int V_90 , V_36 ;
if ( ! V_14 -> V_48 && ! F_55 ( V_49 , & V_46 ) )
return - V_69 ;
V_90 = V_79 + V_14 -> V_80 ;
if ( V_76 -> V_91 < F_56 ( V_90 ) )
return - V_41 ;
V_16 = F_16 ( V_78 -> V_13 , V_14 ) ;
if ( V_16 == NULL )
return - V_92 ;
if ( ( V_16 -> V_74 & V_93 ) &&
! F_57 ( V_94 ) )
return - V_95 ;
if ( ( V_76 -> V_96 & V_97 ) == V_97 ) {
int V_67 ;
if ( V_16 -> V_53 == NULL )
return - V_92 ;
if ( ! V_14 -> V_61 ) {
struct V_98 V_99 = {
. V_100 = V_14 -> V_100 ,
. V_85 = ( void * ) V_16 ,
. V_101 = F_51 ,
. V_86 = F_52 ,
} ;
F_3 () ;
V_67 = F_58 ( V_49 -> V_47 , V_71 , V_76 , & V_99 ) ;
F_1 () ;
} else {
struct V_98 V_99 = {
. V_100 = V_14 -> V_100 ,
. V_101 = V_16 -> V_53 ,
. V_86 = V_16 -> V_86 ,
} ;
V_67 = F_58 ( V_49 -> V_47 , V_71 , V_76 , & V_99 ) ;
}
return V_67 ;
}
if ( V_16 -> V_54 == NULL )
return - V_92 ;
if ( V_14 -> V_60 && V_14 -> V_61 ) {
V_62 = F_43 ( ( V_14 -> V_60 + 1 ) *
sizeof( struct V_63 * ) , V_33 ) ;
if ( V_62 == NULL )
return - V_34 ;
} else
V_62 = V_14 -> V_62 ;
if ( V_62 ) {
V_36 = F_59 ( V_76 , V_90 , V_62 , V_14 -> V_60 ,
V_16 -> V_102 ) ;
if ( V_36 < 0 )
goto V_103;
}
V_89 . V_104 = V_76 -> V_105 ;
V_89 . V_106 = F_60 ( V_71 ) . V_72 ;
V_89 . V_107 = V_76 ;
V_89 . V_108 = F_50 ( V_76 ) ;
V_89 . V_109 = F_50 ( V_76 ) + V_79 ;
V_89 . V_110 = V_62 ;
F_61 ( & V_89 , V_49 ) ;
memset ( & V_89 . V_111 , 0 , sizeof( V_89 . V_111 ) ) ;
if ( V_14 -> V_112 ) {
V_36 = V_14 -> V_112 ( V_16 , V_71 , & V_89 ) ;
if ( V_36 )
goto V_103;
}
V_36 = V_16 -> V_54 ( V_71 , & V_89 ) ;
if ( V_14 -> V_113 )
V_14 -> V_113 ( V_16 , V_71 , & V_89 ) ;
V_103:
if ( V_14 -> V_61 )
F_47 ( V_62 ) ;
return V_36 ;
}
static int F_62 ( struct V_70 * V_71 , struct V_75 * V_76 )
{
struct V_7 * V_14 ;
int V_36 ;
V_14 = F_13 ( V_76 -> V_114 ) ;
if ( V_14 == NULL )
return - V_69 ;
if ( ! V_14 -> V_61 )
F_1 () ;
V_36 = F_53 ( V_14 , V_71 , V_76 ) ;
if ( ! V_14 -> V_61 )
F_3 () ;
return V_36 ;
}
static void F_63 ( struct V_70 * V_71 )
{
F_64 ( & V_2 ) ;
F_65 ( V_71 , & F_62 ) ;
F_66 ( & V_2 ) ;
}
static int F_67 ( struct V_7 * V_14 , T_4 V_72 , T_4 V_73 ,
T_4 V_74 , struct V_70 * V_71 , T_1 V_13 )
{
void * V_78 ;
V_78 = F_48 ( V_71 , V_72 , V_73 , & V_43 , V_74 , V_13 ) ;
if ( V_78 == NULL )
return - 1 ;
if ( F_68 ( V_71 , V_115 , V_14 -> V_9 ) ||
F_69 ( V_71 , V_116 , V_14 -> V_3 ) ||
F_70 ( V_71 , V_117 , V_14 -> V_81 ) ||
F_70 ( V_71 , V_118 , V_14 -> V_80 ) ||
F_70 ( V_71 , V_119 , V_14 -> V_60 ) )
goto V_120;
if ( V_14 -> V_15 ) {
struct V_63 * V_121 ;
int V_10 ;
V_121 = F_71 ( V_71 , V_122 ) ;
if ( V_121 == NULL )
goto V_120;
for ( V_10 = 0 ; V_10 < V_14 -> V_15 ; V_10 ++ ) {
struct V_63 * V_123 ;
const struct V_12 * V_16 = & V_14 -> V_16 [ V_10 ] ;
T_4 V_124 = V_16 -> V_74 ;
if ( V_16 -> V_53 )
V_124 |= V_125 ;
if ( V_16 -> V_54 )
V_124 |= V_126 ;
if ( V_16 -> V_102 )
V_124 |= V_127 ;
V_123 = F_71 ( V_71 , V_10 + 1 ) ;
if ( V_123 == NULL )
goto V_120;
if ( F_70 ( V_71 , V_128 , V_16 -> V_13 ) ||
F_70 ( V_71 , V_129 , V_124 ) )
goto V_120;
F_72 ( V_71 , V_123 ) ;
}
F_72 ( V_71 , V_121 ) ;
}
if ( V_14 -> V_35 ) {
struct V_63 * V_130 ;
int V_10 ;
V_130 = F_71 ( V_71 , V_131 ) ;
if ( V_130 == NULL )
goto V_120;
for ( V_10 = 0 ; V_10 < V_14 -> V_35 ; V_10 ++ ) {
struct V_63 * V_123 ;
const struct V_38 * V_39 ;
V_39 = & V_14 -> V_40 [ V_10 ] ;
V_123 = F_71 ( V_71 , V_10 + 1 ) ;
if ( V_123 == NULL )
goto V_120;
if ( F_70 ( V_71 , V_132 ,
V_14 -> V_45 + V_10 ) ||
F_68 ( V_71 , V_133 ,
V_39 -> V_9 ) )
goto V_120;
F_72 ( V_71 , V_123 ) ;
}
F_72 ( V_71 , V_130 ) ;
}
return F_73 ( V_71 , V_78 ) ;
V_120:
F_74 ( V_71 , V_78 ) ;
return - V_134 ;
}
static int F_75 ( struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 , T_4 V_72 , T_4 V_73 , T_4 V_74 ,
struct V_70 * V_71 , T_1 V_13 )
{
void * V_78 ;
struct V_63 * V_130 ;
struct V_63 * V_123 ;
V_78 = F_48 ( V_71 , V_72 , V_73 , & V_43 , V_74 , V_13 ) ;
if ( V_78 == NULL )
return - 1 ;
if ( F_68 ( V_71 , V_115 , V_14 -> V_9 ) ||
F_69 ( V_71 , V_116 , V_14 -> V_3 ) )
goto V_120;
V_130 = F_71 ( V_71 , V_131 ) ;
if ( V_130 == NULL )
goto V_120;
V_123 = F_71 ( V_71 , 1 ) ;
if ( V_123 == NULL )
goto V_120;
if ( F_70 ( V_71 , V_132 , V_50 ) ||
F_68 ( V_71 , V_133 ,
V_39 -> V_9 ) )
goto V_120;
F_72 ( V_71 , V_123 ) ;
F_72 ( V_71 , V_130 ) ;
return F_73 ( V_71 , V_78 ) ;
V_120:
F_74 ( V_71 , V_78 ) ;
return - V_134 ;
}
static int F_76 ( struct V_70 * V_71 , struct V_83 * V_84 )
{
int V_10 , V_135 = 0 ;
struct V_7 * V_136 ;
struct V_49 * V_49 = F_54 ( V_71 -> V_87 ) ;
int V_137 = V_84 -> args [ 0 ] ;
int V_138 = V_84 -> args [ 1 ] ;
for ( V_10 = V_137 ; V_10 < V_11 ; V_10 ++ ) {
V_135 = 0 ;
F_14 (rt, genl_family_chain(i), family_list) {
if ( ! V_136 -> V_48 && ! F_55 ( V_49 , & V_46 ) )
continue;
if ( ++ V_135 < V_138 )
continue;
if ( F_67 ( V_136 , F_60 ( V_84 -> V_71 ) . V_72 ,
V_84 -> V_76 -> V_105 , V_139 ,
V_71 , V_65 ) < 0 )
goto V_55;
}
V_138 = 0 ;
}
V_55:
V_84 -> args [ 0 ] = V_10 ;
V_84 -> args [ 1 ] = V_135 ;
return V_71 -> V_140 ;
}
static struct V_70 * F_77 ( struct V_7 * V_14 ,
T_4 V_72 , int V_73 , T_1 V_13 )
{
struct V_70 * V_71 ;
int V_36 ;
V_71 = F_78 ( V_141 , V_33 ) ;
if ( V_71 == NULL )
return F_79 ( - V_142 ) ;
V_36 = F_67 ( V_14 , V_72 , V_73 , 0 , V_71 , V_13 ) ;
if ( V_36 < 0 ) {
F_80 ( V_71 ) ;
return F_79 ( V_36 ) ;
}
return V_71 ;
}
static struct V_70 *
F_81 ( struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 , T_4 V_72 , int V_73 , T_1 V_13 )
{
struct V_70 * V_71 ;
int V_36 ;
V_71 = F_78 ( V_141 , V_33 ) ;
if ( V_71 == NULL )
return F_79 ( - V_142 ) ;
V_36 = F_75 ( V_14 , V_39 , V_50 , V_72 ,
V_73 , 0 , V_71 , V_13 ) ;
if ( V_36 < 0 ) {
F_80 ( V_71 ) ;
return F_79 ( V_36 ) ;
}
return V_71 ;
}
static int F_82 ( struct V_70 * V_71 , struct V_88 * V_89 )
{
struct V_70 * V_143 ;
struct V_7 * V_144 = NULL ;
int V_36 = - V_41 ;
if ( V_89 -> V_110 [ V_116 ] ) {
T_2 V_3 = F_83 ( V_89 -> V_110 [ V_116 ] ) ;
V_144 = F_13 ( V_3 ) ;
V_36 = - V_69 ;
}
if ( V_89 -> V_110 [ V_115 ] ) {
char * V_9 ;
V_9 = F_84 ( V_89 -> V_110 [ V_115 ] ) ;
V_144 = F_15 ( V_9 ) ;
#ifdef F_85
if ( V_144 == NULL ) {
F_3 () ;
F_66 ( & V_2 ) ;
F_86 ( L_2 ,
V_145 , V_146 , V_9 ) ;
F_64 ( & V_2 ) ;
F_1 () ;
V_144 = F_15 ( V_9 ) ;
}
#endif
V_36 = - V_69 ;
}
if ( V_144 == NULL )
return V_36 ;
if ( ! V_144 -> V_48 && ! F_55 ( F_87 ( V_89 ) , & V_46 ) ) {
return - V_69 ;
}
V_143 = F_77 ( V_144 , V_89 -> V_106 , V_89 -> V_104 ,
V_65 ) ;
if ( F_88 ( V_143 ) )
return F_89 ( V_143 ) ;
return F_90 ( V_143 , V_89 ) ;
}
static int F_40 ( int V_147 , struct V_7 * V_14 ,
const struct V_38 * V_39 ,
int V_50 )
{
struct V_70 * V_143 ;
if ( ! V_46 . V_47 )
return 0 ;
switch ( V_147 ) {
case V_65 :
case V_68 :
F_28 ( V_39 ) ;
V_143 = F_77 ( V_14 , 0 , 0 , V_147 ) ;
break;
case V_66 :
case V_51 :
F_29 ( ! V_39 ) ;
V_143 = F_81 ( V_14 , V_39 , V_50 , 0 , 0 , V_147 ) ;
break;
default:
return - V_41 ;
}
if ( F_88 ( V_143 ) )
return F_89 ( V_143 ) ;
if ( ! V_14 -> V_48 ) {
F_91 ( & V_43 , & V_46 , V_143 , 0 ,
0 , V_33 ) ;
} else {
F_31 () ;
F_92 ( & V_43 , V_143 , 0 ,
0 , V_148 ) ;
F_34 () ;
}
return 0 ;
}
static int T_5 F_93 ( struct V_49 * V_49 )
{
struct V_149 V_150 = {
. V_151 = F_63 ,
. V_74 = V_152 ,
} ;
V_49 -> V_47 = F_94 ( V_49 , V_146 , & V_150 ) ;
if ( ! V_49 -> V_47 && F_55 ( V_49 , & V_46 ) )
F_95 ( L_3 ) ;
if ( ! V_49 -> V_47 )
return - V_34 ;
return 0 ;
}
static void T_6 F_96 ( struct V_49 * V_49 )
{
F_97 ( V_49 -> V_47 ) ;
V_49 -> V_47 = NULL ;
}
static int T_7 F_98 ( void )
{
int V_10 , V_36 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ )
F_99 ( & V_6 [ V_10 ] ) ;
V_36 = F_100 ( & V_43 , V_153 ,
V_154 ) ;
if ( V_36 < 0 )
goto V_155;
V_36 = F_101 ( & V_156 ) ;
if ( V_36 )
goto V_155;
return 0 ;
V_155:
F_95 ( L_4 , V_36 ) ;
}
static int F_102 ( struct V_70 * V_71 , T_4 V_72 , unsigned long V_157 ,
T_8 V_74 )
{
struct V_70 * V_158 ;
struct V_49 * V_49 , * V_159 = NULL ;
int V_36 ;
F_32 (net) {
if ( V_159 ) {
V_158 = F_103 ( V_71 , V_74 ) ;
if ( ! V_158 ) {
V_36 = - V_34 ;
goto error;
}
V_36 = F_104 ( V_159 -> V_47 , V_158 ,
V_72 , V_157 , V_74 ) ;
if ( V_36 )
goto error;
}
V_159 = V_49 ;
}
return F_104 ( V_159 -> V_47 , V_71 , V_72 , V_157 , V_74 ) ;
error:
F_105 ( V_71 ) ;
return V_36 ;
}
int F_92 ( struct V_7 * V_14 , struct V_70 * V_71 ,
T_4 V_72 , unsigned int V_157 , T_8 V_74 )
{
if ( F_106 ( V_157 >= V_14 -> V_35 ) )
return - V_41 ;
V_157 = V_14 -> V_45 + V_157 ;
return F_102 ( V_71 , V_72 , V_157 , V_74 ) ;
}
void F_107 ( struct V_7 * V_14 ,
struct V_70 * V_71 , struct V_49 * V_49 , T_4 V_72 , T_4 V_157 ,
struct V_75 * V_76 , T_8 V_74 )
{
struct V_160 * V_87 = V_49 -> V_47 ;
int V_161 = 0 ;
if ( V_76 )
V_161 = F_108 ( V_76 ) ;
if ( F_106 ( V_157 >= V_14 -> V_35 ) )
return;
V_157 = V_14 -> V_45 + V_157 ;
F_109 ( V_87 , V_71 , V_72 , V_157 , V_161 , V_74 ) ;
}
