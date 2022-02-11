void F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_8 ; ++ V_7 )
F_2 ( & V_2 -> V_9 [ V_7 ] ) ;
F_3 ( & V_2 -> V_10 ) ;
F_4 ( V_2 , V_4 , V_6 ) ;
F_5 ( & V_2 -> V_11 , 64 ) ;
V_2 -> V_12 . V_13 = - 1 ;
V_2 -> V_14 = V_15 ;
}
struct V_1 * F_6 ( void )
{
struct V_1 * V_2 = F_7 ( sizeof( * V_2 ) ) ;
if ( V_2 != NULL )
F_1 ( V_2 , NULL , NULL ) ;
return V_2 ;
}
struct V_1 * F_8 ( void )
{
struct V_1 * V_2 = F_6 () ;
if ( V_2 && F_9 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
struct V_1 * F_11 ( void )
{
struct V_1 * V_2 = F_6 () ;
if ( V_2 && F_12 ( V_2 ) ) {
F_10 ( V_2 ) ;
V_2 = NULL ;
}
return V_2 ;
}
void F_13 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
V_2 -> V_18 = V_17 -> V_18 ;
V_2 -> V_19 = V_17 -> V_19 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_17 ( V_20 ) ;
F_13 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_16 * V_21 , * V_22 ;
F_19 (evlist, n, pos) {
F_20 ( & V_21 -> V_23 ) ;
V_21 -> V_2 = NULL ;
F_21 ( V_21 ) ;
}
V_2 -> V_24 = 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_25 ) ;
F_23 ( & V_2 -> V_26 ) ;
F_24 ( & V_2 -> V_11 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return;
F_25 ( V_2 ) ;
F_26 ( V_2 ) ;
F_27 ( V_2 -> V_4 ) ;
F_28 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
F_18 ( V_2 ) ;
F_22 ( V_2 ) ;
free ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 ,
struct V_16 * V_20 )
{
if ( ! V_20 -> V_27 || V_2 -> V_28 ) {
F_27 ( V_20 -> V_4 ) ;
V_20 -> V_4 = F_30 ( V_2 -> V_4 ) ;
} else if ( V_20 -> V_4 != V_20 -> V_27 ) {
F_27 ( V_20 -> V_4 ) ;
V_20 -> V_4 = F_30 ( V_20 -> V_27 ) ;
}
F_28 ( V_20 -> V_6 ) ;
V_20 -> V_6 = F_31 ( V_2 -> V_6 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_29 ( V_2 , V_20 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_16 * V_29 )
{
V_29 -> V_2 = V_2 ;
F_34 ( & V_29 -> V_23 , & V_2 -> V_10 ) ;
V_29 -> V_30 = V_2 -> V_24 ;
V_29 -> V_31 = ! V_29 -> V_30 ;
if ( ! V_2 -> V_24 ++ )
F_13 ( V_2 ) ;
F_29 ( V_2 , V_29 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_16 * V_20 )
{
V_20 -> V_2 = NULL ;
F_20 ( & V_20 -> V_23 ) ;
V_2 -> V_24 -= 1 ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
struct V_16 * V_20 , * V_34 ;
F_37 (list, temp, evsel) {
F_20 ( & V_20 -> V_23 ) ;
F_33 ( V_2 , V_20 ) ;
}
}
void F_38 ( struct V_32 * V_33 )
{
struct V_16 * V_20 , * V_35 ;
V_35 = F_39 ( V_33 -> V_36 , struct V_16 , V_23 ) ;
V_20 = F_39 ( V_33 -> V_37 , struct V_16 , V_23 ) ;
V_35 -> V_38 = V_20 -> V_30 - V_35 -> V_30 + 1 ;
F_40 (list, evsel) {
V_20 -> V_35 = V_35 ;
}
}
void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_24 ) {
V_2 -> V_39 = V_2 -> V_24 > 1 ? 1 : 0 ;
F_38 ( & V_2 -> V_10 ) ;
}
}
void F_42 ( struct V_40 * V_41 )
{
V_41 -> V_42 = 3 ;
while ( V_41 -> V_42 != 0 ) {
int V_43 = F_43 ( V_41 , 0 , - 1 , - 1 , 0 ) ;
if ( V_43 != - 1 ) {
F_44 ( V_43 ) ;
break;
}
-- V_41 -> V_42 ;
}
}
int F_45 ( struct V_1 * V_2 , bool V_44 )
{
struct V_16 * V_20 = F_46 ( V_44 ) ;
if ( V_20 == NULL )
return - V_45 ;
F_33 ( V_2 , V_20 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_40 V_41 = {
. type = V_46 ,
. V_47 = V_48 ,
. V_49 = sizeof( V_41 ) ,
} ;
struct V_16 * V_20 = F_47 ( & V_41 ) ;
if ( V_20 == NULL )
return - V_45 ;
F_33 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_40 * V_50 , T_1 V_51 )
{
struct V_16 * V_20 , * V_22 ;
F_49 ( V_52 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ ) {
V_20 = F_50 ( V_50 + V_7 , V_2 -> V_24 + V_7 ) ;
if ( V_20 == NULL )
goto V_53;
F_34 ( & V_20 -> V_23 , & V_52 ) ;
}
F_36 ( V_2 , & V_52 ) ;
return 0 ;
V_53:
F_37 (&head, n, evsel)
F_21 ( V_20 ) ;
return - 1 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_40 * V_50 , T_1 V_51 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ )
F_52 ( V_50 + V_7 ) ;
return F_48 ( V_2 , V_50 , V_51 ) ;
}
struct V_16 *
F_53 ( struct V_1 * V_2 , int V_54 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_41 . type == V_55 &&
( int ) V_20 -> V_41 . V_47 == V_54 )
return V_20 ;
}
return NULL ;
}
struct V_16 *
F_54 ( struct V_1 * V_2 ,
const char * V_56 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( ( V_20 -> V_41 . type == V_55 ) &&
( strcmp ( V_20 -> V_56 , V_56 ) == 0 ) )
return V_20 ;
}
return NULL ;
}
int F_55 ( struct V_1 * V_2 ,
const char * V_57 , const char * V_56 , void * V_58 )
{
struct V_16 * V_20 = F_56 ( V_57 , V_56 ) ;
if ( F_57 ( V_20 ) )
return - 1 ;
V_20 -> V_58 = V_58 ;
F_33 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_16 * V_20 )
{
if ( V_20 -> V_59 )
return 1 ;
else
return F_59 ( V_2 -> V_6 ) ;
}
void F_60 ( struct V_1 * V_2 )
{
struct V_16 * V_21 ;
F_16 (evlist, pos) {
if ( ! F_61 ( V_21 ) || ! V_21 -> V_43 )
continue;
F_62 ( V_21 ) ;
}
V_2 -> V_60 = false ;
}
void F_63 ( struct V_1 * V_2 )
{
struct V_16 * V_21 ;
F_16 (evlist, pos) {
if ( ! F_61 ( V_21 ) || ! V_21 -> V_43 )
continue;
F_64 ( V_21 ) ;
}
V_2 -> V_60 = true ;
}
void F_65 ( struct V_1 * V_2 )
{
( V_2 -> V_60 ? F_60 : F_63 ) ( V_2 ) ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_16 * V_20 , int V_61 )
{
int V_62 ;
int V_63 = F_58 ( V_2 , V_20 ) ;
if ( ! V_20 -> V_43 )
return - V_64 ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
int V_65 = F_67 ( F_68 ( V_20 , V_61 , V_62 ) , V_66 , 0 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_69 ( struct V_1 * V_2 ,
struct V_16 * V_20 ,
int V_62 )
{
int V_61 ;
int V_67 = F_70 ( V_2 -> V_4 ) ;
if ( ! V_20 -> V_43 )
return - V_64 ;
for ( V_61 = 0 ; V_61 < V_67 ; V_61 ++ ) {
int V_65 = F_67 ( F_68 ( V_20 , V_61 , V_62 ) , V_66 , 0 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_16 * V_20 , int V_30 )
{
bool V_68 = ! F_72 ( V_2 -> V_4 ) ;
if ( V_68 )
return F_66 ( V_2 , V_20 , V_30 ) ;
else
return F_69 ( V_2 , V_20 , V_30 ) ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_67 = F_70 ( V_2 -> V_4 ) ;
int V_63 = F_59 ( V_2 -> V_6 ) ;
int V_69 = 0 ;
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_59 )
V_69 += V_67 ;
else
V_69 += V_67 * V_63 ;
}
if ( F_74 ( & V_2 -> V_11 ) < V_69 &&
F_75 ( & V_2 -> V_11 , V_69 ) < 0 )
return - V_45 ;
return 0 ;
}
static int F_76 ( struct V_1 * V_2 , int V_43 ,
struct V_70 * V_71 , short V_72 )
{
int V_21 = F_77 ( & V_2 -> V_11 , V_43 , V_72 | V_73 | V_74 ) ;
if ( V_21 >= 0 ) {
V_2 -> V_11 . V_75 [ V_21 ] . V_76 = V_71 ;
F_78 ( V_43 , V_77 , V_78 ) ;
}
return V_21 ;
}
int F_79 ( struct V_1 * V_2 , int V_43 )
{
return F_76 ( V_2 , V_43 , NULL , V_79 ) ;
}
static void F_80 ( struct V_80 * V_81 , int V_43 ,
void * T_2 V_82 )
{
struct V_70 * V_71 = V_81 -> V_75 [ V_43 ] . V_76 ;
if ( V_71 )
F_81 ( V_71 ) ;
}
int F_82 ( struct V_1 * V_2 , short V_83 )
{
return F_83 ( & V_2 -> V_11 , V_83 ,
F_80 , NULL ) ;
}
int F_84 ( struct V_1 * V_2 , int V_84 )
{
return F_85 ( & V_2 -> V_11 , V_84 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_16 * V_20 ,
int V_61 , int V_62 , T_3 V_54 )
{
int V_85 ;
struct V_86 * V_87 = F_87 ( V_20 , V_61 , V_62 ) ;
V_87 -> V_54 = V_54 ;
V_87 -> V_20 = V_20 ;
V_85 = F_88 ( V_87 -> V_54 , V_88 ) ;
F_89 ( & V_87 -> V_23 , & V_2 -> V_9 [ V_85 ] ) ;
}
void F_90 ( struct V_1 * V_2 , struct V_16 * V_20 ,
int V_61 , int V_62 , T_3 V_54 )
{
F_86 ( V_2 , V_20 , V_61 , V_62 , V_54 ) ;
V_20 -> V_54 [ V_20 -> V_89 ++ ] = V_54 ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_16 * V_20 ,
int V_61 , int V_62 , int V_43 )
{
T_3 V_90 [ 4 ] = { 0 , } ;
int V_91 = 1 ;
T_3 V_54 ;
int V_92 ;
V_92 = F_67 ( V_43 , V_93 , & V_54 ) ;
if ( ! V_92 )
goto V_94;
if ( V_95 != V_96 )
return - 1 ;
if ( F_92 ( V_2 ) & V_97 )
return - 1 ;
if ( ! ( V_20 -> V_41 . V_98 & V_99 ) ||
F_93 ( V_43 , & V_90 , sizeof( V_90 ) ) == - 1 )
return - 1 ;
if ( V_20 -> V_41 . V_98 & V_100 )
++ V_91 ;
if ( V_20 -> V_41 . V_98 & V_101 )
++ V_91 ;
V_54 = V_90 [ V_91 ] ;
V_94:
F_90 ( V_2 , V_20 , V_61 , V_62 , V_54 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_16 * V_20 , int V_30 , int V_61 ,
int V_62 )
{
struct V_86 * V_87 = F_87 ( V_20 , V_61 , V_62 ) ;
V_87 -> V_30 = V_30 ;
if ( V_2 -> V_4 && V_61 >= 0 )
V_87 -> V_61 = V_2 -> V_4 -> V_71 [ V_61 ] ;
else
V_87 -> V_61 = - 1 ;
if ( ! V_20 -> V_59 && V_2 -> V_6 && V_62 >= 0 )
V_87 -> V_102 = F_95 ( V_2 -> V_6 , V_62 ) ;
else
V_87 -> V_102 = - 1 ;
}
struct V_86 * F_96 ( struct V_1 * V_2 , T_3 V_54 )
{
struct V_103 * V_52 ;
struct V_86 * V_87 ;
int V_85 ;
V_85 = F_88 ( V_54 , V_88 ) ;
V_52 = & V_2 -> V_9 [ V_85 ] ;
F_97 (sid, head, node)
if ( V_87 -> V_54 == V_54 )
return V_87 ;
return NULL ;
}
struct V_16 * F_98 ( struct V_1 * V_2 , T_3 V_54 )
{
struct V_86 * V_87 ;
if ( V_2 -> V_24 == 1 || ! V_54 )
return F_14 ( V_2 ) ;
V_87 = F_96 ( V_2 , V_54 ) ;
if ( V_87 )
return V_87 -> V_20 ;
if ( ! F_99 ( V_2 ) )
return F_14 ( V_2 ) ;
return NULL ;
}
struct V_16 * F_100 ( struct V_1 * V_2 ,
T_3 V_54 )
{
struct V_86 * V_87 ;
if ( ! V_54 )
return NULL ;
V_87 = F_96 ( V_2 , V_54 ) ;
if ( V_87 )
return V_87 -> V_20 ;
return NULL ;
}
static int F_101 ( struct V_1 * V_2 ,
union V_104 * V_105 , T_3 * V_54 )
{
const T_3 * V_106 = V_105 -> V_107 . V_106 ;
T_4 V_22 ;
V_22 = ( V_105 -> V_108 . V_49 - sizeof( V_105 -> V_108 ) ) >> 3 ;
if ( V_105 -> V_108 . type == V_109 ) {
if ( V_2 -> V_18 >= V_22 )
return - 1 ;
* V_54 = V_106 [ V_2 -> V_18 ] ;
} else {
if ( V_2 -> V_19 > V_22 )
return - 1 ;
V_22 -= V_2 -> V_19 ;
* V_54 = V_106 [ V_22 ] ;
}
return 0 ;
}
struct V_16 * F_102 ( struct V_1 * V_2 ,
union V_104 * V_105 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
struct V_103 * V_52 ;
struct V_86 * V_87 ;
int V_85 ;
T_3 V_54 ;
if ( V_2 -> V_24 == 1 )
return V_17 ;
if ( ! V_17 -> V_41 . V_110 &&
V_105 -> V_108 . type != V_109 )
return V_17 ;
if ( F_101 ( V_2 , V_105 , & V_54 ) )
return NULL ;
if ( ! V_54 )
return V_17 ;
V_85 = F_88 ( V_54 , V_88 ) ;
V_52 = & V_2 -> V_9 [ V_85 ] ;
F_97 (sid, head, node) {
if ( V_87 -> V_54 == V_54 )
return V_87 -> V_20 ;
}
return NULL ;
}
static int F_103 ( struct V_1 * V_2 , bool V_111 )
{
int V_7 ;
if ( ! V_2 -> V_26 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_112 ; V_7 ++ ) {
int V_43 = V_2 -> V_26 [ V_7 ] . V_43 ;
int V_65 ;
if ( V_43 < 0 )
continue;
V_65 = F_67 ( V_43 , V_113 , V_111 ? 1 : 0 ) ;
if ( V_65 )
return V_65 ;
}
return 0 ;
}
static int F_104 ( struct V_1 * V_2 )
{
return F_103 ( V_2 , true ) ;
}
static int F_105 ( struct V_1 * V_2 )
{
return F_103 ( V_2 , false ) ;
}
static union V_104 *
F_106 ( struct V_70 * V_114 , bool V_115 , T_3 V_116 ,
T_3 V_117 , T_3 * V_37 )
{
unsigned char * V_118 = V_114 -> V_119 + V_120 ;
union V_104 * V_105 = NULL ;
int V_121 = V_117 - V_116 ;
if ( V_115 ) {
if ( V_121 > V_114 -> V_122 / 2 || V_121 < 0 ) {
fprintf ( V_123 , L_1 ) ;
V_116 = V_117 ;
V_121 = 0 ;
}
}
if ( V_121 >= ( int ) sizeof( V_105 -> V_108 ) ) {
T_1 V_49 ;
V_105 = (union V_104 * ) & V_118 [ V_116 & V_114 -> V_122 ] ;
V_49 = V_105 -> V_108 . V_49 ;
if ( V_49 < sizeof( V_105 -> V_108 ) || V_121 < ( int ) V_49 ) {
V_105 = NULL ;
goto V_124;
}
if ( ( V_116 & V_114 -> V_122 ) + V_49 != ( ( V_116 + V_49 ) & V_114 -> V_122 ) ) {
unsigned int V_125 = V_116 ;
unsigned int V_126 = F_107 ( sizeof( * V_105 ) , V_49 ) , V_127 ;
void * V_128 = V_114 -> V_129 ;
do {
V_127 = F_107 ( V_114 -> V_122 + 1 - ( V_125 & V_114 -> V_122 ) , V_126 ) ;
memcpy ( V_128 , & V_118 [ V_125 & V_114 -> V_122 ] , V_127 ) ;
V_125 += V_127 ;
V_128 += V_127 ;
V_126 -= V_127 ;
} while ( V_126 );
V_105 = (union V_104 * ) V_114 -> V_129 ;
}
V_116 += V_49 ;
}
V_124:
if ( V_37 )
* V_37 = V_116 ;
return V_105 ;
}
union V_104 * F_108 ( struct V_70 * V_114 , bool V_115 )
{
T_3 V_52 ;
T_3 V_130 = V_114 -> V_37 ;
if ( ! F_109 ( & V_114 -> V_131 ) )
return NULL ;
V_52 = F_110 ( V_114 ) ;
return F_106 ( V_114 , V_115 , V_130 , V_52 , & V_114 -> V_37 ) ;
}
union V_104 *
F_111 ( struct V_70 * V_114 )
{
T_3 V_52 , V_117 ;
T_3 V_116 = V_114 -> V_37 ;
if ( ! F_109 ( & V_114 -> V_131 ) )
return NULL ;
V_52 = F_110 ( V_114 ) ;
if ( ! V_52 )
return NULL ;
if ( - V_52 < ( T_3 ) ( V_114 -> V_122 + 1 ) )
V_117 = 0 ;
else
V_117 = V_52 + V_114 -> V_122 + 1 ;
return F_106 ( V_114 , false , V_116 , V_117 , & V_114 -> V_37 ) ;
}
union V_104 * F_112 ( struct V_1 * V_2 , int V_30 )
{
struct V_70 * V_114 = & V_2 -> V_25 [ V_30 ] ;
return F_108 ( V_114 , V_2 -> V_132 ) ;
}
union V_104 * F_113 ( struct V_1 * V_2 , int V_30 )
{
struct V_70 * V_114 = & V_2 -> V_25 [ V_30 ] ;
return F_111 ( V_114 ) ;
}
union V_104 * F_114 ( struct V_1 * V_2 , int V_30 )
{
return F_112 ( V_2 , V_30 ) ;
}
void F_115 ( struct V_70 * V_114 )
{
T_3 V_52 ;
if ( ! F_109 ( & V_114 -> V_131 ) )
return;
V_52 = F_110 ( V_114 ) ;
V_114 -> V_37 = V_52 ;
}
void F_116 ( struct V_1 * V_2 , int V_30 )
{
F_115 ( & V_2 -> V_25 [ V_30 ] ) ;
}
static bool F_117 ( struct V_70 * V_114 )
{
return F_110 ( V_114 ) == V_114 -> V_37 && ! V_114 -> V_133 . V_119 ;
}
static void F_118 ( struct V_70 * V_71 )
{
F_119 ( & V_71 -> V_131 ) ;
}
static void F_81 ( struct V_70 * V_114 )
{
F_120 ( V_114 -> V_119 && F_109 ( & V_114 -> V_131 ) == 0 ) ;
if ( F_121 ( & V_114 -> V_131 ) )
F_122 ( V_114 ) ;
}
void F_123 ( struct V_70 * V_114 , bool V_132 )
{
if ( ! V_132 ) {
T_3 V_130 = V_114 -> V_37 ;
F_124 ( V_114 , V_130 ) ;
}
if ( F_109 ( & V_114 -> V_131 ) == 1 && F_117 ( V_114 ) )
F_81 ( V_114 ) ;
}
void F_125 ( struct V_1 * V_2 , int V_30 )
{
F_123 ( & V_2 -> V_25 [ V_30 ] , V_2 -> V_132 ) ;
}
int __weak F_126 ( struct V_133 * T_5 V_82 ,
struct V_134 * T_6 V_82 ,
void * T_7 V_82 ,
int V_43 V_82 )
{
return 0 ;
}
void __weak F_127 ( struct V_133 * T_5 V_82 )
{
}
void __weak F_128 (
struct V_134 * T_6 V_82 ,
T_8 T_9 V_82 ,
unsigned int T_10 V_82 ,
bool T_11 V_82 )
{
}
void __weak F_129 (
struct V_134 * T_6 V_82 ,
struct V_1 * V_2 V_82 ,
int V_30 V_82 ,
bool T_12 V_82 )
{
}
static void F_122 ( struct V_70 * V_71 )
{
if ( V_71 -> V_119 != NULL ) {
F_130 ( V_71 -> V_119 , F_131 ( V_71 ) ) ;
V_71 -> V_119 = NULL ;
V_71 -> V_43 = - 1 ;
F_132 ( & V_71 -> V_131 , 0 ) ;
}
F_127 ( & V_71 -> V_133 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_25 )
for ( V_7 = 0 ; V_7 < V_2 -> V_112 ; V_7 ++ )
F_122 ( & V_2 -> V_25 [ V_7 ] ) ;
if ( V_2 -> V_26 )
for ( V_7 = 0 ; V_7 < V_2 -> V_112 ; V_7 ++ )
F_122 ( & V_2 -> V_26 [ V_7 ] ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_133 ( V_2 ) ;
F_23 ( & V_2 -> V_25 ) ;
F_23 ( & V_2 -> V_26 ) ;
}
static struct V_70 * F_134 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_70 * V_71 ;
V_2 -> V_112 = F_70 ( V_2 -> V_4 ) ;
if ( F_72 ( V_2 -> V_4 ) )
V_2 -> V_112 = F_59 ( V_2 -> V_6 ) ;
V_71 = F_7 ( V_2 -> V_112 * sizeof( struct V_70 ) ) ;
if ( ! V_71 )
return NULL ;
for ( V_7 = 0 ; V_7 < V_2 -> V_112 ; V_7 ++ ) {
V_71 [ V_7 ] . V_43 = - 1 ;
F_132 ( & V_71 [ V_7 ] . V_131 , 0 ) ;
}
return V_71 ;
}
static int F_135 ( struct V_70 * V_71 ,
struct V_135 * T_6 , int V_43 )
{
F_132 ( & V_71 -> V_131 , 2 ) ;
V_71 -> V_37 = 0 ;
V_71 -> V_122 = T_6 -> V_122 ;
V_71 -> V_119 = V_25 ( NULL , F_131 ( V_71 ) , T_6 -> V_136 ,
V_137 , V_43 , 0 ) ;
if ( V_71 -> V_119 == V_138 ) {
F_136 ( L_2 ,
V_95 ) ;
V_71 -> V_119 = NULL ;
return - 1 ;
}
V_71 -> V_43 = V_43 ;
if ( F_126 ( & V_71 -> V_133 ,
& T_6 -> V_139 , V_71 -> V_119 , V_43 ) )
return - 1 ;
return 0 ;
}
static bool
F_137 ( struct V_1 * V_2 V_82 ,
struct V_16 * V_20 )
{
if ( V_20 -> V_41 . V_140 )
return false ;
return true ;
}
static int F_138 ( struct V_1 * V_2 , int V_30 ,
struct V_135 * T_6 , int V_141 ,
int V_62 , int * V_142 , int * V_143 )
{
struct V_16 * V_20 ;
int V_72 ;
int V_144 = F_139 ( V_2 -> V_4 , V_141 ) ;
F_16 (evlist, evsel) {
struct V_70 * V_145 = V_2 -> V_25 ;
int * V_146 = V_142 ;
int V_43 ;
int V_61 ;
if ( V_20 -> V_41 . V_140 ) {
V_146 = V_143 ;
V_145 = V_2 -> V_26 ;
if ( ! V_145 ) {
V_145 = F_134 ( V_2 ) ;
if ( ! V_145 )
return - 1 ;
V_2 -> V_26 = V_145 ;
if ( V_2 -> V_14 == V_15 )
F_140 ( V_2 , V_147 ) ;
}
}
if ( V_20 -> V_59 && V_62 )
continue;
V_61 = F_141 ( V_20 -> V_4 , V_144 ) ;
if ( V_61 == - 1 )
continue;
V_43 = F_68 ( V_20 , V_61 , V_62 ) ;
if ( * V_146 == - 1 ) {
* V_146 = V_43 ;
if ( F_135 ( & V_145 [ V_30 ] , T_6 , * V_146 ) < 0 )
return - 1 ;
} else {
if ( F_67 ( V_43 , V_148 , * V_146 ) != 0 )
return - 1 ;
F_118 ( & V_145 [ V_30 ] ) ;
}
V_72 = F_137 ( V_2 , V_20 ) ? V_79 : 0 ;
if ( ! V_20 -> V_59 &&
F_76 ( V_2 , V_43 , & V_145 [ V_30 ] , V_72 ) < 0 ) {
F_81 ( & V_145 [ V_30 ] ) ;
return - 1 ;
}
if ( V_20 -> V_41 . V_98 & V_99 ) {
if ( F_91 ( V_2 , V_20 , V_61 , V_62 ,
V_43 ) < 0 )
return - 1 ;
F_94 ( V_2 , V_20 , V_30 , V_61 ,
V_62 ) ;
}
}
return 0 ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_135 * T_6 )
{
int V_61 , V_62 ;
int V_67 = F_70 ( V_2 -> V_4 ) ;
int V_63 = F_59 ( V_2 -> V_6 ) ;
F_136 ( L_3 ) ;
for ( V_61 = 0 ; V_61 < V_67 ; V_61 ++ ) {
int V_146 = - 1 ;
int V_149 = - 1 ;
F_129 ( & T_6 -> V_139 , V_2 , V_61 ,
true ) ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
if ( F_138 ( V_2 , V_61 , T_6 , V_61 ,
V_62 , & V_146 , & V_149 ) )
goto V_150;
}
}
return 0 ;
V_150:
F_133 ( V_2 ) ;
return - 1 ;
}
static int F_143 ( struct V_1 * V_2 ,
struct V_135 * T_6 )
{
int V_62 ;
int V_63 = F_59 ( V_2 -> V_6 ) ;
F_136 ( L_4 ) ;
for ( V_62 = 0 ; V_62 < V_63 ; V_62 ++ ) {
int V_146 = - 1 ;
int V_149 = - 1 ;
F_129 ( & T_6 -> V_139 , V_2 , V_62 ,
false ) ;
if ( F_138 ( V_2 , V_62 , T_6 , 0 , V_62 ,
& V_146 , & V_149 ) )
goto V_150;
}
return 0 ;
V_150:
F_133 ( V_2 ) ;
return - 1 ;
}
unsigned long F_144 ( void )
{
unsigned long V_151 ;
int V_152 ;
if ( F_145 ( L_5 , & V_152 ) < 0 ) {
V_152 = 512 ;
} else {
V_152 -= ( V_120 / 1024 ) ;
}
V_151 = ( V_152 * 1024 ) / V_120 ;
if ( ! F_146 ( V_151 ) )
V_151 = F_147 ( V_151 ) ;
return V_151 ;
}
T_1 F_148 ( unsigned long V_151 )
{
if ( V_151 == V_153 )
V_151 = F_144 () ;
else if ( ! F_146 ( V_151 ) )
return 0 ;
return ( V_151 + 1 ) * V_120 ;
}
static long F_149 ( const char * V_154 , unsigned long F_107 ,
unsigned long V_152 )
{
unsigned long V_151 , V_155 ;
static struct V_156 V_157 [] = {
{ . V_158 = 'B' , . V_159 = 1 } ,
{ . V_158 = 'K' , . V_159 = 1 << 10 } ,
{ . V_158 = 'M' , . V_159 = 1 << 20 } ,
{ . V_158 = 'G' , . V_159 = 1 << 30 } ,
{ . V_158 = 0 } ,
} ;
if ( V_154 == NULL )
return - V_64 ;
V_155 = F_150 ( V_154 , V_157 ) ;
if ( V_155 != ( unsigned long ) - 1 ) {
V_151 = F_151 ( V_155 , V_120 ) / V_120 ;
} else {
char * V_160 ;
V_151 = strtoul ( V_154 , & V_160 , 10 ) ;
if ( * V_160 != '\0' )
return - V_64 ;
}
if ( V_151 == 0 && F_107 == 0 ) {
} else if ( ! F_146 ( V_151 ) ) {
char V_161 [ 100 ] ;
V_151 = F_152 ( V_151 ) ;
if ( ! V_151 )
return - V_64 ;
F_153 ( V_161 , sizeof( V_161 ) , V_151 * V_120 ) ;
F_154 ( L_6 ,
V_161 , V_151 ) ;
}
if ( V_151 > V_152 )
return - V_64 ;
return V_151 ;
}
int F_155 ( unsigned int * V_162 , const char * V_154 )
{
unsigned long V_152 = V_153 ;
long V_151 ;
if ( V_152 > V_163 / V_120 )
V_152 = V_163 / V_120 ;
V_151 = F_149 ( V_154 , 1 , V_152 ) ;
if ( V_151 < 0 ) {
F_156 ( L_7 ) ;
return - 1 ;
}
* V_162 = V_151 ;
return 0 ;
}
int F_157 ( const struct V_164 * V_165 , const char * V_154 ,
int T_13 V_82 )
{
return F_155 ( V_165 -> V_111 , V_154 ) ;
}
int F_158 ( struct V_1 * V_2 , unsigned int V_151 ,
bool V_132 , unsigned int T_10 ,
bool T_11 )
{
struct V_16 * V_20 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_135 T_6 = {
. V_136 = V_166 | ( V_132 ? 0 : V_167 ) ,
} ;
if ( ! V_2 -> V_25 )
V_2 -> V_25 = F_134 ( V_2 ) ;
if ( ! V_2 -> V_25 )
return - V_45 ;
if ( V_2 -> V_11 . V_10 == NULL && F_73 ( V_2 ) < 0 )
return - V_45 ;
V_2 -> V_132 = V_132 ;
V_2 -> V_168 = F_148 ( V_151 ) ;
F_159 ( L_8 , V_2 -> V_168 ) ;
T_6 . V_122 = V_2 -> V_168 - V_120 - 1 ;
F_128 ( & T_6 . V_139 , V_2 -> V_168 ,
T_10 , T_11 ) ;
F_16 (evlist, evsel) {
if ( ( V_20 -> V_41 . V_98 & V_99 ) &&
V_20 -> V_169 == NULL &&
F_160 ( V_20 , F_70 ( V_4 ) , V_6 -> V_170 ) < 0 )
return - V_45 ;
}
if ( F_72 ( V_4 ) )
return F_143 ( V_2 , & T_6 ) ;
return F_142 ( V_2 , & T_6 ) ;
}
int F_161 ( struct V_1 * V_2 , unsigned int V_151 ,
bool V_132 )
{
return F_158 ( V_2 , V_151 , V_132 , 0 , false ) ;
}
int F_162 ( struct V_1 * V_2 , struct V_171 * V_171 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_163 ( V_171 -> V_13 , V_171 -> V_102 , V_171 -> V_172 ) ;
if ( ! V_6 )
return - 1 ;
if ( F_164 ( V_171 ) )
V_4 = F_165 () ;
else
V_4 = F_166 ( V_171 -> V_173 ) ;
if ( ! V_4 )
goto V_174;
V_2 -> V_28 = ! ! V_171 -> V_173 ;
F_4 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_174:
F_28 ( V_6 ) ;
return - 1 ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 != V_2 -> V_4 ) {
F_27 ( V_2 -> V_4 ) ;
V_2 -> V_4 = F_30 ( V_4 ) ;
}
if ( V_6 != V_2 -> V_6 ) {
F_28 ( V_2 -> V_6 ) ;
V_2 -> V_6 = F_31 ( V_6 ) ;
}
F_32 ( V_2 ) ;
}
void F_167 ( struct V_1 * V_2 ,
enum V_175 V_176 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_168 ( V_20 , V_176 ) ;
}
void F_169 ( struct V_1 * V_2 ,
enum V_175 V_176 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_170 ( V_20 , V_176 ) ;
}
int F_171 ( struct V_1 * V_2 , struct V_16 * * V_177 )
{
struct V_16 * V_20 ;
int V_65 = 0 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_178 == NULL )
continue;
V_65 = F_172 ( V_20 , V_20 -> V_178 ) ;
if ( V_65 ) {
* V_177 = V_20 ;
break;
}
}
return V_65 ;
}
int F_173 ( struct V_1 * V_2 , const char * V_178 )
{
struct V_16 * V_20 ;
int V_65 = 0 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_41 . type != V_55 )
continue;
V_65 = F_174 ( V_20 , V_178 ) ;
if ( V_65 )
break;
}
return V_65 ;
}
int F_175 ( struct V_1 * V_2 , T_1 V_179 , T_14 * V_180 )
{
char * V_178 ;
int V_92 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_179 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_176 ( & V_178 , L_9 , V_180 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_181 ;
if ( F_176 ( & V_181 , L_10 , V_178 , V_180 [ V_7 ] ) < 0 )
goto V_182;
free ( V_178 ) ;
V_178 = V_181 ;
}
}
V_92 = F_173 ( V_2 , V_178 ) ;
V_182:
free ( V_178 ) ;
return V_92 ;
}
int F_177 ( struct V_1 * V_2 , T_14 V_13 )
{
return F_175 ( V_2 , 1 , & V_13 ) ;
}
bool F_178 ( struct V_1 * V_2 )
{
struct V_16 * V_21 ;
if ( V_2 -> V_24 == 1 )
return true ;
if ( V_2 -> V_18 < 0 || V_2 -> V_19 < 0 )
return false ;
F_16 (evlist, pos) {
if ( V_21 -> V_18 != V_2 -> V_18 ||
V_21 -> V_19 != V_2 -> V_19 )
return false ;
}
return true ;
}
T_3 F_179 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
if ( V_2 -> V_183 )
return V_2 -> V_183 ;
F_16 (evlist, evsel)
V_2 -> V_183 |= V_20 -> V_41 . V_184 ;
return V_2 -> V_183 ;
}
T_3 F_180 ( struct V_1 * V_2 )
{
V_2 -> V_183 = 0 ;
return F_179 ( V_2 ) ;
}
T_3 F_181 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
T_3 V_185 = 0 ;
F_16 (evlist, evsel)
V_185 |= V_20 -> V_41 . V_186 ;
return V_185 ;
}
bool F_182 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) , * V_21 = V_17 ;
T_3 V_98 = V_17 -> V_41 . V_98 ;
T_3 V_184 = V_17 -> V_41 . V_184 ;
F_16 (evlist, pos) {
if ( V_98 != V_21 -> V_41 . V_98 )
return false ;
}
if ( ( V_184 & V_187 ) &&
! ( V_98 & V_99 ) ) {
return false ;
}
return true ;
}
T_3 F_92 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
return V_17 -> V_41 . V_98 ;
}
T_15 F_183 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
struct V_188 * V_118 ;
T_3 V_184 ;
T_15 V_49 = 0 ;
if ( ! V_17 -> V_41 . V_110 )
goto V_189;
V_184 = V_17 -> V_41 . V_184 ;
if ( V_184 & V_190 )
V_49 += sizeof( V_118 -> V_102 ) * 2 ;
if ( V_184 & V_191 )
V_49 += sizeof( V_118 -> time ) ;
if ( V_184 & V_192 )
V_49 += sizeof( V_118 -> V_54 ) ;
if ( V_184 & V_193 )
V_49 += sizeof( V_118 -> V_194 ) ;
if ( V_184 & V_195 )
V_49 += sizeof( V_118 -> V_61 ) * 2 ;
if ( V_184 & V_196 )
V_49 += sizeof( V_118 -> V_54 ) ;
V_189:
return V_49 ;
}
bool F_184 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) , * V_21 = V_17 ;
F_185 (evlist, pos) {
if ( V_17 -> V_41 . V_110 != V_21 -> V_41 . V_110 )
return false ;
}
return true ;
}
bool F_99 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
return V_17 -> V_41 . V_110 ;
}
void F_186 ( struct V_1 * V_2 ,
struct V_16 * V_20 )
{
V_2 -> V_197 = V_20 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
F_187 (evlist, evsel)
F_188 ( V_20 ) ;
}
static int F_189 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_65 = - V_45 ;
V_4 = F_166 ( NULL ) ;
if ( ! V_4 )
goto V_189;
V_6 = F_190 () ;
if ( ! V_6 )
goto V_198;
F_4 ( V_2 , V_4 , V_6 ) ;
V_189:
return V_65 ;
V_198:
F_27 ( V_4 ) ;
goto V_189;
}
int F_191 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
int V_65 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_65 = F_189 ( V_2 ) ;
if ( V_65 < 0 )
goto V_199;
}
F_15 ( V_2 ) ;
F_16 (evlist, evsel) {
V_65 = F_192 ( V_20 , V_20 -> V_4 , V_20 -> V_6 ) ;
if ( V_65 < 0 )
goto V_199;
}
return 0 ;
V_199:
F_26 ( V_2 ) ;
V_95 = - V_65 ;
return V_65 ;
}
int F_193 ( struct V_1 * V_2 , struct V_171 * V_171 ,
const char * V_200 [] , bool V_201 ,
void (* F_194)( int V_202 , T_16 * V_203 , void * V_204 ) )
{
int V_205 [ 2 ] , V_206 [ 2 ] ;
char V_207 ;
if ( F_195 ( V_205 ) < 0 ) {
perror ( L_11 ) ;
return - 1 ;
}
if ( F_195 ( V_206 ) < 0 ) {
perror ( L_12 ) ;
goto V_208;
}
V_2 -> V_12 . V_13 = F_196 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_13 ) ;
goto V_209;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_92 ;
if ( V_201 )
F_197 ( 2 , 1 ) ;
signal ( V_210 , V_211 ) ;
F_44 ( V_205 [ 0 ] ) ;
F_44 ( V_206 [ 1 ] ) ;
F_78 ( V_206 [ 0 ] , V_212 , V_213 ) ;
F_44 ( V_205 [ 1 ] ) ;
V_92 = F_93 ( V_206 [ 0 ] , & V_207 , 1 ) ;
if ( V_92 != 1 ) {
if ( V_92 == - 1 )
perror ( L_14 ) ;
exit ( V_92 ) ;
}
F_198 ( V_200 [ 0 ] , ( char * * ) V_200 ) ;
if ( F_194 ) {
union V_214 V_155 ;
V_155 . V_215 = V_95 ;
if ( F_199 ( F_200 () , V_216 , V_155 ) )
perror ( V_200 [ 0 ] ) ;
} else
perror ( V_200 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_194 ) {
struct V_217 V_218 = {
. V_219 = V_220 ,
. V_221 = F_194 ,
} ;
V_217 ( V_216 , & V_218 , NULL ) ;
}
if ( F_201 ( V_171 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_123 , L_15 ,
V_222 , __LINE__ ) ;
goto V_209;
}
F_202 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_44 ( V_205 [ 1 ] ) ;
F_44 ( V_206 [ 0 ] ) ;
if ( F_93 ( V_205 [ 0 ] , & V_207 , 1 ) == - 1 ) {
perror ( L_14 ) ;
goto V_209;
}
F_78 ( V_206 [ 1 ] , V_212 , V_213 ) ;
V_2 -> V_12 . V_223 = V_206 [ 1 ] ;
F_44 ( V_205 [ 0 ] ) ;
return 0 ;
V_209:
F_44 ( V_206 [ 0 ] ) ;
F_44 ( V_206 [ 1 ] ) ;
V_208:
F_44 ( V_205 [ 0 ] ) ;
F_44 ( V_205 [ 1 ] ) ;
return - 1 ;
}
int F_203 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_223 > 0 ) {
char V_207 = 0 ;
int V_92 ;
V_92 = F_204 ( V_2 -> V_12 . V_223 , & V_207 , 1 ) ;
if ( V_92 < 0 )
perror ( L_16 ) ;
F_44 ( V_2 -> V_12 . V_223 ) ;
return V_92 ;
}
return 0 ;
}
int F_205 ( struct V_1 * V_2 , union V_104 * V_105 ,
struct V_188 * V_107 )
{
struct V_16 * V_20 = F_102 ( V_2 , V_105 ) ;
if ( ! V_20 )
return - V_224 ;
return F_206 ( V_20 , V_105 , V_107 ) ;
}
T_1 F_207 ( struct V_1 * V_2 , T_17 * V_225 )
{
struct V_16 * V_20 ;
T_1 V_226 = 0 ;
F_16 (evlist, evsel) {
V_226 += fprintf ( V_225 , L_17 , V_20 -> V_30 ? L_18 : L_19 ,
F_208 ( V_20 ) ) ;
}
return V_226 + fprintf ( V_225 , L_20 ) ;
}
int F_209 ( struct V_1 * V_2 ,
int V_65 , char * V_161 , T_1 V_49 )
{
int V_226 , V_111 ;
char V_227 [ V_228 ] , * V_229 = F_210 ( V_65 , V_227 , sizeof( V_227 ) ) ;
switch ( V_65 ) {
case V_230 :
case V_231 :
V_226 = F_211 ( V_161 , V_49 ,
L_21
L_22 , V_229 ) ;
V_111 = F_212 () ;
V_226 += F_211 ( V_161 + V_226 , V_49 - V_226 , L_23 ) ;
if ( V_111 >= 2 ) {
V_226 += F_211 ( V_161 + V_226 , V_49 - V_226 ,
L_24 ) ;
}
V_226 += F_211 ( V_161 + V_226 , V_49 - V_226 ,
L_25 ) ;
V_226 += F_211 ( V_161 + V_226 , V_49 - V_226 ,
L_26
L_27 , V_111 ) ;
break;
case V_64 : {
struct V_16 * V_17 = F_14 ( V_2 ) ;
int V_232 ;
if ( F_145 ( L_28 , & V_232 ) < 0 )
goto V_233;
if ( V_17 -> V_41 . V_234 < ( T_3 ) V_232 )
goto V_233;
V_226 = F_211 ( V_161 , V_49 ,
L_21
L_29
L_30 V_235 L_31 ,
V_229 , V_232 , V_17 -> V_41 . V_234 ) ;
break;
}
default:
V_233:
F_211 ( V_161 , V_49 , L_32 , V_229 ) ;
break;
}
return 0 ;
}
int F_213 ( struct V_1 * V_2 , int V_65 , char * V_161 , T_1 V_49 )
{
char V_227 [ V_228 ] , * V_229 = F_210 ( V_65 , V_227 , sizeof( V_227 ) ) ;
int V_236 = V_2 -> V_168 / 1024 , V_237 , V_226 = 0 ;
switch ( V_65 ) {
case V_231 :
F_145 ( L_5 , & V_237 ) ;
V_226 += F_211 ( V_161 + V_226 , V_49 - V_226 ,
L_21
L_33
L_34 ,
V_229 , V_237 , V_236 ) ;
if ( V_236 >= V_237 ) {
V_226 += F_211 ( V_161 + V_226 , V_49 - V_226 ,
L_35 ,
V_237 + V_236 ) ;
}
V_226 += F_211 ( V_161 + V_226 , V_49 - V_226 ,
L_36 ) ;
break;
default:
F_211 ( V_161 , V_49 , L_32 , V_229 ) ;
break;
}
return 0 ;
}
void F_214 ( struct V_1 * V_2 ,
struct V_16 * V_238 )
{
struct V_16 * V_20 , * V_22 ;
F_49 ( V_239 ) ;
if ( V_238 == F_14 ( V_2 ) )
return;
F_19 (evlist, n, evsel) {
if ( V_20 -> V_35 == V_238 -> V_35 )
F_215 ( & V_20 -> V_23 , & V_239 ) ;
}
F_216 ( & V_239 , & V_2 -> V_10 ) ;
}
void F_217 ( struct V_1 * V_2 ,
struct V_16 * V_240 )
{
struct V_16 * V_20 ;
if ( V_240 -> V_31 )
return;
F_16 (evlist, evsel) {
if ( V_20 != V_240 )
V_20 -> V_31 = false ;
}
V_240 -> V_31 = true ;
}
struct V_16 *
F_218 ( struct V_1 * V_2 ,
const char * V_154 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( ! V_20 -> V_56 )
continue;
if ( strcmp ( V_154 , V_20 -> V_56 ) == 0 )
return V_20 ;
}
return NULL ;
}
void F_140 ( struct V_1 * V_2 ,
enum V_14 V_241 )
{
enum V_14 V_242 = V_2 -> V_14 ;
enum T_18 {
V_243 ,
V_244 ,
V_245 ,
} T_18 = V_243 ;
if ( ! V_2 -> V_26 )
return;
switch ( V_242 ) {
case V_15 : {
if ( V_241 != V_147 )
goto V_246; ;
break;
}
case V_147 : {
if ( V_241 != V_247 )
goto V_246;
T_18 = V_244 ;
break;
}
case V_247 : {
if ( V_241 != V_248 )
goto V_246;
break;
}
case V_248 : {
if ( V_241 != V_147 )
goto V_246;
T_18 = V_245 ;
break;
}
default:
F_219 ( 1 , L_37 ) ;
}
V_2 -> V_14 = V_241 ;
switch ( T_18 ) {
case V_244 :
F_104 ( V_2 ) ;
break;
case V_245 :
F_105 ( V_2 ) ;
break;
case V_243 :
default:
break;
}
V_246:
return;
}
