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
static const struct V_3 * F_11 ( unsigned int V_4 )
{
return F_12 ( & V_5 , V_4 ) ;
}
static const struct V_3 * F_13 ( char * V_6 )
{
const struct V_3 * V_7 ;
unsigned int V_4 ;
F_14 (&genl_fam_idr, family, id)
if ( strcmp ( V_7 -> V_6 , V_6 ) == 0 )
return V_7 ;
return NULL ;
}
static const struct V_8 * F_15 ( T_1 V_9 ,
const struct V_3 * V_7 )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 ; V_10 ++ )
if ( V_7 -> V_12 [ V_10 ] . V_9 == V_9 )
return & V_7 -> V_12 [ V_10 ] ;
return NULL ;
}
static int F_16 ( int V_13 , int * V_14 )
{
unsigned long * V_15 ;
int V_16 = 0 ;
int V_10 ;
int V_4 ;
bool V_17 ;
do {
if ( V_16 == 0 )
V_4 = F_17 ( V_18 ,
V_19 *
V_20 ) ;
else
V_4 = F_18 ( V_18 ,
V_19 * V_20 ,
V_16 ) ;
V_17 = true ;
for ( V_10 = V_4 ;
V_10 < F_19 ( int , V_4 + V_13 ,
V_19 * V_20 ) ;
V_10 ++ ) {
if ( F_20 ( V_10 , V_18 ) ) {
V_16 = V_10 ;
V_17 = false ;
break;
}
}
if ( V_4 + V_13 > V_19 * V_20 ) {
unsigned long V_21 = V_19 +
F_21 ( V_13 ) ;
T_2 V_22 = V_21 * sizeof( unsigned long ) ;
if ( V_18 == & V_23 ) {
V_15 = F_22 ( V_22 , V_24 ) ;
if ( ! V_15 )
return - V_25 ;
V_18 = V_15 ;
* V_18 = V_23 ;
} else {
V_15 = F_23 ( V_18 , V_22 ,
V_24 ) ;
if ( ! V_15 )
return - V_25 ;
V_18 = V_15 ;
for ( V_10 = 0 ; V_10 < F_21 ( V_13 ) ; V_10 ++ )
V_18 [ V_19 + V_10 ] = 0 ;
}
V_19 = V_21 ;
}
} while ( ! V_17 );
for ( V_10 = V_4 ; V_10 < V_4 + V_13 ; V_10 ++ )
F_24 ( V_10 , V_18 ) ;
* V_14 = V_4 ;
return 0 ;
}
static int F_25 ( struct V_3 * V_7 )
{
int V_14 ;
int V_13 = V_7 -> V_26 ;
int V_27 = 0 , V_10 ;
bool V_28 = false ;
if ( ! V_13 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_13 ; V_10 ++ ) {
const struct V_29 * V_30 = & V_7 -> V_31 [ V_10 ] ;
if ( F_26 ( V_30 -> V_6 [ 0 ] == '\0' ) )
return - V_32 ;
if ( F_26 ( memchr ( V_30 -> V_6 , '\0' , V_33 ) == NULL ) )
return - V_32 ;
}
if ( V_7 == & V_34 ) {
V_14 = V_35 ;
F_27 ( V_13 != 1 ) ;
} else if ( strcmp ( V_7 -> V_6 , L_1 ) == 0 ) {
V_14 = 1 ;
F_27 ( V_13 != 1 ) ;
} else if ( V_7 -> V_4 == V_36 ) {
V_14 = V_36 ;
F_27 ( V_13 != 1 ) ;
} else if ( V_7 -> V_4 == V_37 ) {
V_14 = V_37 ;
F_27 ( V_13 != 1 ) ;
} else {
V_28 = true ;
V_27 = F_16 ( V_13 , & V_14 ) ;
if ( V_27 )
return V_27 ;
}
V_7 -> V_38 = V_14 ;
if ( ! V_39 . V_40 )
return 0 ;
if ( V_7 -> V_41 ) {
struct V_42 * V_42 ;
F_28 () ;
F_29 () ;
F_30 (net) {
V_27 = F_31 ( V_42 -> V_40 ,
V_19 * V_20 ) ;
if ( V_27 ) {
break;
}
}
F_32 () ;
F_33 () ;
} else {
V_27 = F_34 ( V_39 . V_40 ,
V_19 * V_20 ) ;
}
if ( V_28 && V_27 ) {
for ( V_10 = 0 ; V_10 < V_7 -> V_26 ; V_10 ++ )
F_35 ( V_7 -> V_38 + V_10 , V_18 ) ;
}
return V_27 ;
}
static void F_36 ( const struct V_3 * V_7 )
{
struct V_42 * V_42 ;
int V_10 ;
F_28 () ;
F_29 () ;
F_30 (net) {
for ( V_10 = 0 ; V_10 < V_7 -> V_26 ; V_10 ++ )
F_37 (
V_42 -> V_40 , V_7 -> V_38 + V_10 ) ;
}
F_32 () ;
F_33 () ;
for ( V_10 = 0 ; V_10 < V_7 -> V_26 ; V_10 ++ ) {
int V_43 = V_7 -> V_38 + V_10 ;
if ( V_43 != 1 )
F_35 ( V_43 , V_18 ) ;
F_38 ( V_44 , V_7 ,
& V_7 -> V_31 [ V_10 ] , V_43 ) ;
}
}
static int F_39 ( const struct V_3 * V_7 )
{
const struct V_8 * V_12 = V_7 -> V_12 ;
unsigned int V_11 = V_7 -> V_11 ;
int V_10 , V_45 ;
if ( F_26 ( V_11 && ! V_12 ) )
return - V_32 ;
if ( ! V_11 )
return 0 ;
for ( V_10 = 0 ; V_10 < V_11 ; V_10 ++ ) {
if ( V_12 [ V_10 ] . V_46 == NULL && V_12 [ V_10 ] . V_47 == NULL )
return - V_32 ;
for ( V_45 = V_10 + 1 ; V_45 < V_11 ; V_45 ++ )
if ( V_12 [ V_10 ] . V_9 == V_12 [ V_45 ] . V_9 )
return - V_32 ;
}
return 0 ;
}
int F_40 ( struct V_3 * V_7 )
{
int V_27 , V_10 ;
int V_16 = V_48 , V_49 = V_50 ;
V_27 = F_39 ( V_7 ) ;
if ( V_27 )
return V_27 ;
F_7 () ;
if ( F_13 ( V_7 -> V_6 ) ) {
V_27 = - V_51 ;
goto V_52;
}
if ( V_7 == & V_34 ) {
V_16 = V_49 = V_35 ;
} else if ( strcmp ( V_7 -> V_6 , L_2 ) == 0 ) {
V_16 = V_49 = V_37 ;
} else if ( strcmp ( V_7 -> V_6 , L_3 ) == 0 ) {
V_16 = V_49 = V_36 ;
}
if ( V_7 -> V_53 && ! V_7 -> V_54 ) {
V_7 -> V_55 = F_41 ( ( V_7 -> V_53 + 1 ) *
sizeof( struct V_56 * ) , V_24 ) ;
if ( V_7 -> V_55 == NULL ) {
V_27 = - V_25 ;
goto V_52;
}
} else
V_7 -> V_55 = NULL ;
V_7 -> V_4 = F_42 ( & V_5 , V_7 ,
V_16 , V_49 + 1 , V_24 ) ;
if ( V_7 -> V_4 < 0 ) {
V_27 = V_7 -> V_4 ;
goto V_52;
}
V_27 = F_25 ( V_7 ) ;
if ( V_27 )
goto V_57;
F_9 () ;
F_38 ( V_58 , V_7 , NULL , 0 ) ;
for ( V_10 = 0 ; V_10 < V_7 -> V_26 ; V_10 ++ )
F_38 ( V_59 , V_7 ,
& V_7 -> V_31 [ V_10 ] , V_7 -> V_38 + V_10 ) ;
return 0 ;
V_57:
F_43 ( & V_5 , V_7 -> V_4 ) ;
F_44 ( V_7 -> V_55 ) ;
V_52:
F_9 () ;
return V_27 ;
}
int F_45 ( const struct V_3 * V_7 )
{
F_7 () ;
if ( ! F_11 ( V_7 -> V_4 ) ) {
F_9 () ;
return - V_60 ;
}
F_36 ( V_7 ) ;
F_43 ( & V_5 , V_7 -> V_4 ) ;
F_10 ( & V_2 ) ;
F_46 ( V_61 ,
F_47 ( & V_62 ) == 0 ) ;
F_3 () ;
F_44 ( V_7 -> V_55 ) ;
F_38 ( V_63 , V_7 , NULL , 0 ) ;
return 0 ;
}
void * F_48 ( struct V_64 * V_65 , T_3 V_66 , T_3 V_67 ,
const struct V_3 * V_7 , int V_68 , T_1 V_9 )
{
struct V_69 * V_70 ;
struct V_71 * V_72 ;
V_70 = F_49 ( V_65 , V_66 , V_67 , V_7 -> V_4 , V_73 +
V_7 -> V_74 , V_68 ) ;
if ( V_70 == NULL )
return NULL ;
V_72 = F_50 ( V_70 ) ;
V_72 -> V_9 = V_9 ;
V_72 -> V_75 = V_7 -> V_75 ;
V_72 -> V_76 = 0 ;
return ( char * ) V_72 + V_73 ;
}
static int F_51 ( struct V_77 * V_78 )
{
const struct V_8 * V_12 = V_78 -> V_79 ;
int V_80 = 0 ;
if ( V_12 -> V_16 ) {
F_1 () ;
V_80 = V_12 -> V_16 ( V_78 ) ;
F_3 () ;
}
return V_80 ;
}
static int F_52 ( struct V_64 * V_65 , struct V_77 * V_78 )
{
const struct V_8 * V_12 = V_78 -> V_79 ;
int V_80 ;
F_1 () ;
V_80 = V_12 -> V_46 ( V_65 , V_78 ) ;
F_3 () ;
return V_80 ;
}
static int F_53 ( struct V_77 * V_78 )
{
const struct V_8 * V_12 = V_78 -> V_79 ;
int V_80 = 0 ;
if ( V_12 -> V_81 ) {
F_1 () ;
V_80 = V_12 -> V_81 ( V_78 ) ;
F_3 () ;
}
return V_80 ;
}
static int F_54 ( const struct V_3 * V_7 ,
struct V_64 * V_65 ,
struct V_69 * V_70 )
{
const struct V_8 * V_12 ;
struct V_42 * V_42 = F_55 ( V_65 -> V_82 ) ;
struct V_83 V_84 ;
struct V_71 * V_72 = F_50 ( V_70 ) ;
struct V_56 * * V_55 ;
int V_85 , V_27 ;
if ( ! V_7 -> V_41 && ! F_56 ( V_42 , & V_39 ) )
return - V_60 ;
V_85 = V_73 + V_7 -> V_74 ;
if ( V_70 -> V_86 < F_57 ( V_85 ) )
return - V_32 ;
V_12 = F_15 ( V_72 -> V_9 , V_7 ) ;
if ( V_12 == NULL )
return - V_87 ;
if ( ( V_12 -> V_68 & V_88 ) &&
! F_58 ( V_65 , V_89 ) )
return - V_90 ;
if ( ( V_12 -> V_68 & V_91 ) &&
! F_59 ( V_65 , V_42 -> V_92 , V_89 ) )
return - V_90 ;
if ( ( V_70 -> V_93 & V_94 ) == V_94 ) {
int V_80 ;
if ( V_12 -> V_46 == NULL )
return - V_87 ;
if ( ! V_7 -> V_54 ) {
struct V_95 V_96 = {
. V_97 = V_7 -> V_97 ,
. V_79 = ( void * ) V_12 ,
. V_16 = F_51 ,
. V_98 = F_52 ,
. V_81 = F_53 ,
} ;
F_3 () ;
V_80 = F_60 ( V_42 -> V_40 , V_65 , V_70 , & V_96 ) ;
F_1 () ;
} else {
struct V_95 V_96 = {
. V_97 = V_7 -> V_97 ,
. V_16 = V_12 -> V_16 ,
. V_98 = V_12 -> V_46 ,
. V_81 = V_12 -> V_81 ,
} ;
V_80 = F_60 ( V_42 -> V_40 , V_65 , V_70 , & V_96 ) ;
}
return V_80 ;
}
if ( V_12 -> V_47 == NULL )
return - V_87 ;
if ( V_7 -> V_53 && V_7 -> V_54 ) {
V_55 = F_41 ( ( V_7 -> V_53 + 1 ) *
sizeof( struct V_56 * ) , V_24 ) ;
if ( V_55 == NULL )
return - V_25 ;
} else
V_55 = V_7 -> V_55 ;
if ( V_55 ) {
V_27 = F_61 ( V_70 , V_85 , V_55 , V_7 -> V_53 ,
V_12 -> V_99 ) ;
if ( V_27 < 0 )
goto V_100;
}
V_84 . V_101 = V_70 -> V_102 ;
V_84 . V_103 = F_62 ( V_65 ) . V_66 ;
V_84 . V_104 = V_70 ;
V_84 . V_105 = F_50 ( V_70 ) ;
V_84 . V_106 = F_50 ( V_70 ) + V_73 ;
V_84 . V_107 = V_55 ;
F_63 ( & V_84 , V_42 ) ;
memset ( & V_84 . V_108 , 0 , sizeof( V_84 . V_108 ) ) ;
if ( V_7 -> V_109 ) {
V_27 = V_7 -> V_109 ( V_12 , V_65 , & V_84 ) ;
if ( V_27 )
goto V_100;
}
V_27 = V_12 -> V_47 ( V_65 , & V_84 ) ;
if ( V_7 -> V_110 )
V_7 -> V_110 ( V_12 , V_65 , & V_84 ) ;
V_100:
if ( V_7 -> V_54 )
F_44 ( V_55 ) ;
return V_27 ;
}
static int F_64 ( struct V_64 * V_65 , struct V_69 * V_70 )
{
const struct V_3 * V_7 ;
int V_27 ;
V_7 = F_11 ( V_70 -> V_111 ) ;
if ( V_7 == NULL )
return - V_60 ;
if ( ! V_7 -> V_54 )
F_1 () ;
V_27 = F_54 ( V_7 , V_65 , V_70 ) ;
if ( ! V_7 -> V_54 )
F_3 () ;
return V_27 ;
}
static void F_65 ( struct V_64 * V_65 )
{
F_66 ( & V_2 ) ;
F_67 ( V_65 , & F_64 ) ;
F_68 ( & V_2 ) ;
}
static int F_69 ( const struct V_3 * V_7 , T_3 V_66 , T_3 V_67 ,
T_3 V_68 , struct V_64 * V_65 , T_1 V_9 )
{
void * V_72 ;
V_72 = F_48 ( V_65 , V_66 , V_67 , & V_34 , V_68 , V_9 ) ;
if ( V_72 == NULL )
return - 1 ;
if ( F_70 ( V_65 , V_112 , V_7 -> V_6 ) ||
F_71 ( V_65 , V_113 , V_7 -> V_4 ) ||
F_72 ( V_65 , V_114 , V_7 -> V_75 ) ||
F_72 ( V_65 , V_115 , V_7 -> V_74 ) ||
F_72 ( V_65 , V_116 , V_7 -> V_53 ) )
goto V_117;
if ( V_7 -> V_11 ) {
struct V_56 * V_118 ;
int V_10 ;
V_118 = F_73 ( V_65 , V_119 ) ;
if ( V_118 == NULL )
goto V_117;
for ( V_10 = 0 ; V_10 < V_7 -> V_11 ; V_10 ++ ) {
struct V_56 * V_120 ;
const struct V_8 * V_12 = & V_7 -> V_12 [ V_10 ] ;
T_3 V_121 = V_12 -> V_68 ;
if ( V_12 -> V_46 )
V_121 |= V_122 ;
if ( V_12 -> V_47 )
V_121 |= V_123 ;
if ( V_12 -> V_99 )
V_121 |= V_124 ;
V_120 = F_73 ( V_65 , V_10 + 1 ) ;
if ( V_120 == NULL )
goto V_117;
if ( F_72 ( V_65 , V_125 , V_12 -> V_9 ) ||
F_72 ( V_65 , V_126 , V_121 ) )
goto V_117;
F_74 ( V_65 , V_120 ) ;
}
F_74 ( V_65 , V_118 ) ;
}
if ( V_7 -> V_26 ) {
struct V_56 * V_127 ;
int V_10 ;
V_127 = F_73 ( V_65 , V_128 ) ;
if ( V_127 == NULL )
goto V_117;
for ( V_10 = 0 ; V_10 < V_7 -> V_26 ; V_10 ++ ) {
struct V_56 * V_120 ;
const struct V_29 * V_30 ;
V_30 = & V_7 -> V_31 [ V_10 ] ;
V_120 = F_73 ( V_65 , V_10 + 1 ) ;
if ( V_120 == NULL )
goto V_117;
if ( F_72 ( V_65 , V_129 ,
V_7 -> V_38 + V_10 ) ||
F_70 ( V_65 , V_130 ,
V_30 -> V_6 ) )
goto V_117;
F_74 ( V_65 , V_120 ) ;
}
F_74 ( V_65 , V_127 ) ;
}
F_75 ( V_65 , V_72 ) ;
return 0 ;
V_117:
F_76 ( V_65 , V_72 ) ;
return - V_131 ;
}
static int F_77 ( const struct V_3 * V_7 ,
const struct V_29 * V_30 ,
int V_43 , T_3 V_66 , T_3 V_67 , T_3 V_68 ,
struct V_64 * V_65 , T_1 V_9 )
{
void * V_72 ;
struct V_56 * V_127 ;
struct V_56 * V_120 ;
V_72 = F_48 ( V_65 , V_66 , V_67 , & V_34 , V_68 , V_9 ) ;
if ( V_72 == NULL )
return - 1 ;
if ( F_70 ( V_65 , V_112 , V_7 -> V_6 ) ||
F_71 ( V_65 , V_113 , V_7 -> V_4 ) )
goto V_117;
V_127 = F_73 ( V_65 , V_128 ) ;
if ( V_127 == NULL )
goto V_117;
V_120 = F_73 ( V_65 , 1 ) ;
if ( V_120 == NULL )
goto V_117;
if ( F_72 ( V_65 , V_129 , V_43 ) ||
F_70 ( V_65 , V_130 ,
V_30 -> V_6 ) )
goto V_117;
F_74 ( V_65 , V_120 ) ;
F_74 ( V_65 , V_127 ) ;
F_75 ( V_65 , V_72 ) ;
return 0 ;
V_117:
F_76 ( V_65 , V_72 ) ;
return - V_131 ;
}
static int F_78 ( struct V_64 * V_65 , struct V_77 * V_78 )
{
int V_132 = 0 ;
struct V_3 * V_133 ;
struct V_42 * V_42 = F_55 ( V_65 -> V_82 ) ;
int V_134 = V_78 -> args [ 0 ] ;
unsigned int V_4 ;
F_14 (&genl_fam_idr, rt, id) {
if ( ! V_133 -> V_41 && ! F_56 ( V_42 , & V_39 ) )
continue;
if ( V_132 ++ < V_134 )
continue;
if ( F_69 ( V_133 , F_62 ( V_78 -> V_65 ) . V_66 ,
V_78 -> V_70 -> V_102 , V_135 ,
V_65 , V_58 ) < 0 ) {
V_132 -- ;
break;
}
}
V_78 -> args [ 0 ] = V_132 ;
return V_65 -> V_136 ;
}
static struct V_64 * F_79 ( const struct V_3 * V_7 ,
T_3 V_66 , int V_67 , T_1 V_9 )
{
struct V_64 * V_65 ;
int V_27 ;
V_65 = F_80 ( V_137 , V_24 ) ;
if ( V_65 == NULL )
return F_81 ( - V_138 ) ;
V_27 = F_69 ( V_7 , V_66 , V_67 , 0 , V_65 , V_9 ) ;
if ( V_27 < 0 ) {
F_82 ( V_65 ) ;
return F_81 ( V_27 ) ;
}
return V_65 ;
}
static struct V_64 *
F_83 ( const struct V_3 * V_7 ,
const struct V_29 * V_30 ,
int V_43 , T_3 V_66 , int V_67 , T_1 V_9 )
{
struct V_64 * V_65 ;
int V_27 ;
V_65 = F_80 ( V_137 , V_24 ) ;
if ( V_65 == NULL )
return F_81 ( - V_138 ) ;
V_27 = F_77 ( V_7 , V_30 , V_43 , V_66 ,
V_67 , 0 , V_65 , V_9 ) ;
if ( V_27 < 0 ) {
F_82 ( V_65 ) ;
return F_81 ( V_27 ) ;
}
return V_65 ;
}
static int F_84 ( struct V_64 * V_65 , struct V_83 * V_84 )
{
struct V_64 * V_139 ;
const struct V_3 * V_140 = NULL ;
int V_27 = - V_32 ;
if ( V_84 -> V_107 [ V_113 ] ) {
T_4 V_4 = F_85 ( V_84 -> V_107 [ V_113 ] ) ;
V_140 = F_11 ( V_4 ) ;
V_27 = - V_60 ;
}
if ( V_84 -> V_107 [ V_112 ] ) {
char * V_6 ;
V_6 = F_86 ( V_84 -> V_107 [ V_112 ] ) ;
V_140 = F_13 ( V_6 ) ;
#ifdef F_87
if ( V_140 == NULL ) {
F_3 () ;
F_68 ( & V_2 ) ;
F_88 ( L_4 ,
V_141 , V_142 , V_6 ) ;
F_66 ( & V_2 ) ;
F_1 () ;
V_140 = F_13 ( V_6 ) ;
}
#endif
V_27 = - V_60 ;
}
if ( V_140 == NULL )
return V_27 ;
if ( ! V_140 -> V_41 && ! F_56 ( F_89 ( V_84 ) , & V_39 ) ) {
return - V_60 ;
}
V_139 = F_79 ( V_140 , V_84 -> V_103 , V_84 -> V_101 ,
V_58 ) ;
if ( F_90 ( V_139 ) )
return F_91 ( V_139 ) ;
return F_92 ( V_139 , V_84 ) ;
}
static int F_38 ( int V_143 , const struct V_3 * V_7 ,
const struct V_29 * V_30 ,
int V_43 )
{
struct V_64 * V_139 ;
if ( ! V_39 . V_40 )
return 0 ;
switch ( V_143 ) {
case V_58 :
case V_63 :
F_26 ( V_30 ) ;
V_139 = F_79 ( V_7 , 0 , 0 , V_143 ) ;
break;
case V_59 :
case V_44 :
F_27 ( ! V_30 ) ;
V_139 = F_83 ( V_7 , V_30 , V_43 , 0 , 0 , V_143 ) ;
break;
default:
return - V_32 ;
}
if ( F_90 ( V_139 ) )
return F_91 ( V_139 ) ;
if ( ! V_7 -> V_41 ) {
F_93 ( & V_34 , & V_39 , V_139 , 0 ,
0 , V_24 ) ;
} else {
F_29 () ;
F_94 ( & V_34 , V_139 , 0 ,
0 , V_144 ) ;
F_32 () ;
}
return 0 ;
}
static int F_95 ( struct V_42 * V_42 , int V_145 )
{
struct V_3 * V_146 ;
int V_27 = - V_60 ;
unsigned int V_4 ;
F_66 ( & V_2 ) ;
F_14 (&genl_fam_idr, f, id) {
if ( V_145 >= V_146 -> V_38 &&
V_145 < V_146 -> V_38 + V_146 -> V_26 ) {
int V_147 = V_145 - V_146 -> V_38 ;
if ( ! V_146 -> V_41 && V_42 != & V_39 )
V_27 = - V_60 ;
else if ( V_146 -> V_148 )
V_27 = V_146 -> V_148 ( V_42 , V_147 ) ;
else
V_27 = 0 ;
break;
}
}
F_68 ( & V_2 ) ;
return V_27 ;
}
static void F_96 ( struct V_42 * V_42 , int V_145 )
{
struct V_3 * V_146 ;
unsigned int V_4 ;
F_66 ( & V_2 ) ;
F_14 (&genl_fam_idr, f, id) {
if ( V_145 >= V_146 -> V_38 &&
V_145 < V_146 -> V_38 + V_146 -> V_26 ) {
int V_147 = V_145 - V_146 -> V_38 ;
if ( V_146 -> V_149 )
V_146 -> V_149 ( V_42 , V_147 ) ;
break;
}
}
F_68 ( & V_2 ) ;
}
static int T_5 F_97 ( struct V_42 * V_42 )
{
struct V_150 V_151 = {
. V_152 = F_65 ,
. V_68 = V_153 ,
. V_154 = F_95 ,
. V_155 = F_96 ,
} ;
V_42 -> V_40 = F_98 ( V_42 , V_142 , & V_151 ) ;
if ( ! V_42 -> V_40 && F_56 ( V_42 , & V_39 ) )
F_99 ( L_5 ) ;
if ( ! V_42 -> V_40 )
return - V_25 ;
return 0 ;
}
static void T_6 F_100 ( struct V_42 * V_42 )
{
F_101 ( V_42 -> V_40 ) ;
V_42 -> V_40 = NULL ;
}
static int T_7 F_102 ( void )
{
int V_27 ;
V_27 = F_40 ( & V_34 ) ;
if ( V_27 < 0 )
goto V_156;
V_27 = F_103 ( & V_157 ) ;
if ( V_27 )
goto V_156;
return 0 ;
V_156:
F_99 ( L_6 , V_27 ) ;
}
struct V_56 * * F_104 ( const struct V_3 * V_7 )
{
if ( ! F_26 ( V_7 -> V_54 ) )
F_105 ( & V_1 ) ;
return V_7 -> V_55 ;
}
static int F_106 ( struct V_64 * V_65 , T_3 V_66 , unsigned long V_145 ,
T_8 V_68 )
{
struct V_64 * V_158 ;
struct V_42 * V_42 , * V_159 = NULL ;
int V_27 ;
F_30 (net) {
if ( V_159 ) {
V_158 = F_107 ( V_65 , V_68 ) ;
if ( ! V_158 ) {
V_27 = - V_25 ;
goto error;
}
V_27 = F_108 ( V_159 -> V_40 , V_158 ,
V_66 , V_145 , V_68 ) ;
if ( V_27 )
goto error;
}
V_159 = V_42 ;
}
return F_108 ( V_159 -> V_40 , V_65 , V_66 , V_145 , V_68 ) ;
error:
F_109 ( V_65 ) ;
return V_27 ;
}
int F_94 ( const struct V_3 * V_7 ,
struct V_64 * V_65 , T_3 V_66 ,
unsigned int V_145 , T_8 V_68 )
{
if ( F_110 ( V_145 >= V_7 -> V_26 ) )
return - V_32 ;
V_145 = V_7 -> V_38 + V_145 ;
return F_106 ( V_65 , V_66 , V_145 , V_68 ) ;
}
void F_111 ( const struct V_3 * V_7 , struct V_64 * V_65 ,
struct V_83 * V_84 , T_3 V_145 , T_8 V_68 )
{
struct V_42 * V_42 = F_89 ( V_84 ) ;
struct V_160 * V_82 = V_42 -> V_40 ;
int V_161 = 0 ;
if ( V_84 -> V_104 )
V_161 = F_112 ( V_84 -> V_104 ) ;
if ( F_110 ( V_145 >= V_7 -> V_26 ) )
return;
V_145 = V_7 -> V_38 + V_145 ;
F_113 ( V_82 , V_65 , V_84 -> V_103 , V_145 , V_161 , V_68 ) ;
}
