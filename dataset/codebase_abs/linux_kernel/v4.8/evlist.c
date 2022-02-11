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
int F_9 ( struct V_1 * V_2 )
{
struct V_16 * V_20 = F_45 () ;
if ( V_20 == NULL )
return - V_44 ;
F_33 ( V_2 , V_20 ) ;
return 0 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_40 V_41 = {
. type = V_45 ,
. V_46 = V_47 ,
. V_48 = sizeof( V_41 ) ,
} ;
struct V_16 * V_20 = F_46 ( & V_41 ) ;
if ( V_20 == NULL )
return - V_44 ;
F_33 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_40 * V_49 , T_1 V_50 )
{
struct V_16 * V_20 , * V_22 ;
F_48 ( V_51 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_50 ; V_7 ++ ) {
V_20 = F_49 ( V_49 + V_7 , V_2 -> V_24 + V_7 ) ;
if ( V_20 == NULL )
goto V_52;
F_34 ( & V_20 -> V_23 , & V_51 ) ;
}
F_36 ( V_2 , & V_51 ) ;
return 0 ;
V_52:
F_37 (&head, n, evsel)
F_21 ( V_20 ) ;
return - 1 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_40 * V_49 , T_1 V_50 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_50 ; V_7 ++ )
F_51 ( V_49 + V_7 ) ;
return F_47 ( V_2 , V_49 , V_50 ) ;
}
struct V_16 *
F_52 ( struct V_1 * V_2 , int V_53 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_41 . type == V_54 &&
( int ) V_20 -> V_41 . V_46 == V_53 )
return V_20 ;
}
return NULL ;
}
struct V_16 *
F_53 ( struct V_1 * V_2 ,
const char * V_55 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( ( V_20 -> V_41 . type == V_54 ) &&
( strcmp ( V_20 -> V_55 , V_55 ) == 0 ) )
return V_20 ;
}
return NULL ;
}
int F_54 ( struct V_1 * V_2 ,
const char * V_56 , const char * V_55 , void * V_57 )
{
struct V_16 * V_20 = F_55 ( V_56 , V_55 ) ;
if ( F_56 ( V_20 ) )
return - 1 ;
V_20 -> V_57 = V_57 ;
F_33 ( V_2 , V_20 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_16 * V_20 )
{
if ( V_20 -> V_58 )
return 1 ;
else
return F_58 ( V_2 -> V_6 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_16 * V_21 ;
F_16 (evlist, pos) {
if ( ! F_60 ( V_21 ) || ! V_21 -> V_43 )
continue;
F_61 ( V_21 ) ;
}
V_2 -> V_59 = false ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_16 * V_21 ;
F_16 (evlist, pos) {
if ( ! F_60 ( V_21 ) || ! V_21 -> V_43 )
continue;
F_63 ( V_21 ) ;
}
V_2 -> V_59 = true ;
}
void F_64 ( struct V_1 * V_2 )
{
( V_2 -> V_59 ? F_59 : F_62 ) ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_16 * V_20 , int V_60 )
{
int V_61 , V_62 ;
int V_63 = F_57 ( V_2 , V_20 ) ;
if ( ! V_20 -> V_43 )
return - V_64 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_62 = F_66 ( F_67 ( V_20 , V_60 , V_61 ) ,
V_65 , 0 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_16 * V_20 ,
int V_61 )
{
int V_60 , V_62 ;
int V_66 = F_69 ( V_2 -> V_4 ) ;
if ( ! V_20 -> V_43 )
return - V_64 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
V_62 = F_66 ( F_67 ( V_20 , V_60 , V_61 ) , V_65 , 0 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_16 * V_20 , int V_30 )
{
bool V_67 = ! F_71 ( V_2 -> V_4 ) ;
if ( V_67 )
return F_65 ( V_2 , V_20 , V_30 ) ;
else
return F_68 ( V_2 , V_20 , V_30 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_66 = F_69 ( V_2 -> V_4 ) ;
int V_63 = F_58 ( V_2 -> V_6 ) ;
int V_68 = 0 ;
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_58 )
V_68 += V_66 ;
else
V_68 += V_66 * V_63 ;
}
if ( F_73 ( & V_2 -> V_11 ) < V_68 &&
F_74 ( & V_2 -> V_11 , V_68 ) < 0 )
return - V_44 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , int V_43 ,
struct V_69 * V_70 , short V_71 )
{
int V_21 = F_76 ( & V_2 -> V_11 , V_43 , V_71 | V_72 | V_73 ) ;
if ( V_21 >= 0 ) {
V_2 -> V_11 . V_74 [ V_21 ] . V_75 = V_70 ;
F_77 ( V_43 , V_76 , V_77 ) ;
}
return V_21 ;
}
int F_78 ( struct V_1 * V_2 , int V_43 )
{
return F_75 ( V_2 , V_43 , NULL , V_78 ) ;
}
static void F_79 ( struct V_79 * V_80 , int V_43 ,
void * T_2 V_81 )
{
struct V_69 * V_70 = V_80 -> V_74 [ V_43 ] . V_75 ;
if ( V_70 )
F_80 ( V_70 ) ;
}
int F_81 ( struct V_1 * V_2 , short V_82 )
{
return F_82 ( & V_2 -> V_11 , V_82 ,
F_79 , NULL ) ;
}
int F_83 ( struct V_1 * V_2 , int V_83 )
{
return F_84 ( & V_2 -> V_11 , V_83 ) ;
}
static void F_85 ( struct V_1 * V_2 ,
struct V_16 * V_20 ,
int V_60 , int V_61 , T_3 V_53 )
{
int V_84 ;
struct V_85 * V_86 = F_86 ( V_20 , V_60 , V_61 ) ;
V_86 -> V_53 = V_53 ;
V_86 -> V_20 = V_20 ;
V_84 = F_87 ( V_86 -> V_53 , V_87 ) ;
F_88 ( & V_86 -> V_23 , & V_2 -> V_9 [ V_84 ] ) ;
}
void F_89 ( struct V_1 * V_2 , struct V_16 * V_20 ,
int V_60 , int V_61 , T_3 V_53 )
{
F_85 ( V_2 , V_20 , V_60 , V_61 , V_53 ) ;
V_20 -> V_53 [ V_20 -> V_88 ++ ] = V_53 ;
}
int F_90 ( struct V_1 * V_2 ,
struct V_16 * V_20 ,
int V_60 , int V_61 , int V_43 )
{
T_3 V_89 [ 4 ] = { 0 , } ;
int V_90 = 1 ;
T_3 V_53 ;
int V_91 ;
V_91 = F_66 ( V_43 , V_92 , & V_53 ) ;
if ( ! V_91 )
goto V_93;
if ( V_94 != V_95 )
return - 1 ;
if ( F_91 ( V_2 ) & V_96 )
return - 1 ;
if ( ! ( V_20 -> V_41 . V_97 & V_98 ) ||
F_92 ( V_43 , & V_89 , sizeof( V_89 ) ) == - 1 )
return - 1 ;
if ( V_20 -> V_41 . V_97 & V_99 )
++ V_90 ;
if ( V_20 -> V_41 . V_97 & V_100 )
++ V_90 ;
V_53 = V_89 [ V_90 ] ;
V_93:
F_89 ( V_2 , V_20 , V_60 , V_61 , V_53 ) ;
return 0 ;
}
static void F_93 ( struct V_1 * V_2 ,
struct V_16 * V_20 , int V_30 , int V_60 ,
int V_61 )
{
struct V_85 * V_86 = F_86 ( V_20 , V_60 , V_61 ) ;
V_86 -> V_30 = V_30 ;
if ( V_2 -> V_4 && V_60 >= 0 )
V_86 -> V_60 = V_2 -> V_4 -> V_70 [ V_60 ] ;
else
V_86 -> V_60 = - 1 ;
if ( ! V_20 -> V_58 && V_2 -> V_6 && V_61 >= 0 )
V_86 -> V_101 = F_94 ( V_2 -> V_6 , V_61 ) ;
else
V_86 -> V_101 = - 1 ;
}
struct V_85 * F_95 ( struct V_1 * V_2 , T_3 V_53 )
{
struct V_102 * V_51 ;
struct V_85 * V_86 ;
int V_84 ;
V_84 = F_87 ( V_53 , V_87 ) ;
V_51 = & V_2 -> V_9 [ V_84 ] ;
F_96 (sid, head, node)
if ( V_86 -> V_53 == V_53 )
return V_86 ;
return NULL ;
}
struct V_16 * F_97 ( struct V_1 * V_2 , T_3 V_53 )
{
struct V_85 * V_86 ;
if ( V_2 -> V_24 == 1 || ! V_53 )
return F_14 ( V_2 ) ;
V_86 = F_95 ( V_2 , V_53 ) ;
if ( V_86 )
return V_86 -> V_20 ;
if ( ! F_98 ( V_2 ) )
return F_14 ( V_2 ) ;
return NULL ;
}
struct V_16 * F_99 ( struct V_1 * V_2 ,
T_3 V_53 )
{
struct V_85 * V_86 ;
if ( ! V_53 )
return NULL ;
V_86 = F_95 ( V_2 , V_53 ) ;
if ( V_86 )
return V_86 -> V_20 ;
return NULL ;
}
static int F_100 ( struct V_1 * V_2 ,
union V_103 * V_104 , T_3 * V_53 )
{
const T_3 * V_105 = V_104 -> V_106 . V_105 ;
T_4 V_22 ;
V_22 = ( V_104 -> V_107 . V_48 - sizeof( V_104 -> V_107 ) ) >> 3 ;
if ( V_104 -> V_107 . type == V_108 ) {
if ( V_2 -> V_18 >= V_22 )
return - 1 ;
* V_53 = V_105 [ V_2 -> V_18 ] ;
} else {
if ( V_2 -> V_19 > V_22 )
return - 1 ;
V_22 -= V_2 -> V_19 ;
* V_53 = V_105 [ V_22 ] ;
}
return 0 ;
}
struct V_16 * F_101 ( struct V_1 * V_2 ,
union V_103 * V_104 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
struct V_102 * V_51 ;
struct V_85 * V_86 ;
int V_84 ;
T_3 V_53 ;
if ( V_2 -> V_24 == 1 )
return V_17 ;
if ( ! V_17 -> V_41 . V_109 &&
V_104 -> V_107 . type != V_108 )
return V_17 ;
if ( F_100 ( V_2 , V_104 , & V_53 ) )
return NULL ;
if ( ! V_53 )
return V_17 ;
V_84 = F_87 ( V_53 , V_87 ) ;
V_51 = & V_2 -> V_9 [ V_84 ] ;
F_96 (sid, head, node) {
if ( V_86 -> V_53 == V_53 )
return V_86 -> V_20 ;
}
return NULL ;
}
static int F_102 ( struct V_1 * V_2 , bool V_110 )
{
int V_7 ;
if ( ! V_2 -> V_26 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_111 ; V_7 ++ ) {
int V_43 = V_2 -> V_26 [ V_7 ] . V_43 ;
int V_62 ;
if ( V_43 < 0 )
continue;
V_62 = F_66 ( V_43 , V_112 , V_110 ? 1 : 0 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_103 ( struct V_1 * V_2 )
{
return F_102 ( V_2 , true ) ;
}
static int F_104 ( struct V_1 * V_2 )
{
return F_102 ( V_2 , false ) ;
}
static union V_103 *
F_105 ( struct V_69 * V_113 , bool V_114 , T_3 V_115 ,
T_3 V_116 , T_3 * V_37 )
{
unsigned char * V_117 = V_113 -> V_118 + V_119 ;
union V_103 * V_104 = NULL ;
int V_120 = V_116 - V_115 ;
if ( V_114 ) {
if ( V_120 > V_113 -> V_121 / 2 || V_120 < 0 ) {
fprintf ( V_122 , L_1 ) ;
V_115 = V_116 ;
V_120 = 0 ;
}
}
if ( V_120 >= ( int ) sizeof( V_104 -> V_107 ) ) {
T_1 V_48 ;
V_104 = (union V_103 * ) & V_117 [ V_115 & V_113 -> V_121 ] ;
V_48 = V_104 -> V_107 . V_48 ;
if ( V_48 < sizeof( V_104 -> V_107 ) || V_120 < ( int ) V_48 ) {
V_104 = NULL ;
goto V_123;
}
if ( ( V_115 & V_113 -> V_121 ) + V_48 != ( ( V_115 + V_48 ) & V_113 -> V_121 ) ) {
unsigned int V_124 = V_115 ;
unsigned int V_125 = F_106 ( sizeof( * V_104 ) , V_48 ) , V_126 ;
void * V_127 = V_113 -> V_128 ;
do {
V_126 = F_106 ( V_113 -> V_121 + 1 - ( V_124 & V_113 -> V_121 ) , V_125 ) ;
memcpy ( V_127 , & V_117 [ V_124 & V_113 -> V_121 ] , V_126 ) ;
V_124 += V_126 ;
V_127 += V_126 ;
V_125 -= V_126 ;
} while ( V_125 );
V_104 = (union V_103 * ) V_113 -> V_128 ;
}
V_115 += V_48 ;
}
V_123:
if ( V_37 )
* V_37 = V_115 ;
return V_104 ;
}
union V_103 * F_107 ( struct V_69 * V_113 , bool V_114 )
{
T_3 V_51 ;
T_3 V_129 = V_113 -> V_37 ;
if ( ! F_108 ( & V_113 -> V_130 ) )
return NULL ;
V_51 = F_109 ( V_113 ) ;
return F_105 ( V_113 , V_114 , V_129 , V_51 , & V_113 -> V_37 ) ;
}
union V_103 *
F_110 ( struct V_69 * V_113 )
{
T_3 V_51 , V_116 ;
T_3 V_115 = V_113 -> V_37 ;
if ( ! F_108 ( & V_113 -> V_130 ) )
return NULL ;
V_51 = F_109 ( V_113 ) ;
if ( ! V_51 )
return NULL ;
if ( - V_51 < ( T_3 ) ( V_113 -> V_121 + 1 ) )
V_116 = 0 ;
else
V_116 = V_51 + V_113 -> V_121 + 1 ;
return F_105 ( V_113 , false , V_115 , V_116 , & V_113 -> V_37 ) ;
}
union V_103 * F_111 ( struct V_1 * V_2 , int V_30 )
{
struct V_69 * V_113 = & V_2 -> V_25 [ V_30 ] ;
return F_107 ( V_113 , V_2 -> V_131 ) ;
}
union V_103 * F_112 ( struct V_1 * V_2 , int V_30 )
{
struct V_69 * V_113 = & V_2 -> V_25 [ V_30 ] ;
return F_110 ( V_113 ) ;
}
union V_103 * F_113 ( struct V_1 * V_2 , int V_30 )
{
return F_111 ( V_2 , V_30 ) ;
}
void F_114 ( struct V_69 * V_113 )
{
T_3 V_51 ;
if ( ! F_108 ( & V_113 -> V_130 ) )
return;
V_51 = F_109 ( V_113 ) ;
V_113 -> V_37 = V_51 ;
}
void F_115 ( struct V_1 * V_2 , int V_30 )
{
F_114 ( & V_2 -> V_25 [ V_30 ] ) ;
}
static bool F_116 ( struct V_69 * V_113 )
{
return F_109 ( V_113 ) == V_113 -> V_37 && ! V_113 -> V_132 . V_118 ;
}
static void F_117 ( struct V_69 * V_70 )
{
F_118 ( & V_70 -> V_130 ) ;
}
static void F_80 ( struct V_69 * V_113 )
{
F_119 ( V_113 -> V_118 && F_108 ( & V_113 -> V_130 ) == 0 ) ;
if ( F_120 ( & V_113 -> V_130 ) )
F_121 ( V_113 ) ;
}
void F_122 ( struct V_69 * V_113 , bool V_131 )
{
if ( ! V_131 ) {
T_3 V_129 = V_113 -> V_37 ;
F_123 ( V_113 , V_129 ) ;
}
if ( F_108 ( & V_113 -> V_130 ) == 1 && F_116 ( V_113 ) )
F_80 ( V_113 ) ;
}
void F_124 ( struct V_1 * V_2 , int V_30 )
{
F_122 ( & V_2 -> V_25 [ V_30 ] , V_2 -> V_131 ) ;
}
int __weak F_125 ( struct V_132 * T_5 V_81 ,
struct V_133 * T_6 V_81 ,
void * T_7 V_81 ,
int V_43 V_81 )
{
return 0 ;
}
void __weak F_126 ( struct V_132 * T_5 V_81 )
{
}
void __weak F_127 (
struct V_133 * T_6 V_81 ,
T_8 T_9 V_81 ,
unsigned int T_10 V_81 ,
bool T_11 V_81 )
{
}
void __weak F_128 (
struct V_133 * T_6 V_81 ,
struct V_1 * V_2 V_81 ,
int V_30 V_81 ,
bool T_12 V_81 )
{
}
static void F_121 ( struct V_69 * V_70 )
{
if ( V_70 -> V_118 != NULL ) {
F_129 ( V_70 -> V_118 , F_130 ( V_70 ) ) ;
V_70 -> V_118 = NULL ;
V_70 -> V_43 = - 1 ;
F_131 ( & V_70 -> V_130 , 0 ) ;
}
F_126 ( & V_70 -> V_132 ) ;
}
static void F_132 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_25 )
for ( V_7 = 0 ; V_7 < V_2 -> V_111 ; V_7 ++ )
F_121 ( & V_2 -> V_25 [ V_7 ] ) ;
if ( V_2 -> V_26 )
for ( V_7 = 0 ; V_7 < V_2 -> V_111 ; V_7 ++ )
F_121 ( & V_2 -> V_26 [ V_7 ] ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_132 ( V_2 ) ;
F_23 ( & V_2 -> V_25 ) ;
F_23 ( & V_2 -> V_26 ) ;
}
static struct V_69 * F_133 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_69 * V_70 ;
V_2 -> V_111 = F_69 ( V_2 -> V_4 ) ;
if ( F_71 ( V_2 -> V_4 ) )
V_2 -> V_111 = F_58 ( V_2 -> V_6 ) ;
V_70 = F_7 ( V_2 -> V_111 * sizeof( struct V_69 ) ) ;
if ( ! V_70 )
return NULL ;
for ( V_7 = 0 ; V_7 < V_2 -> V_111 ; V_7 ++ )
V_70 [ V_7 ] . V_43 = - 1 ;
return V_70 ;
}
static int F_134 ( struct V_69 * V_70 ,
struct V_134 * T_6 , int V_43 )
{
F_131 ( & V_70 -> V_130 , 2 ) ;
V_70 -> V_37 = 0 ;
V_70 -> V_121 = T_6 -> V_121 ;
V_70 -> V_118 = V_25 ( NULL , F_130 ( V_70 ) , T_6 -> V_135 ,
V_136 , V_43 , 0 ) ;
if ( V_70 -> V_118 == V_137 ) {
F_135 ( L_2 ,
V_94 ) ;
V_70 -> V_118 = NULL ;
return - 1 ;
}
V_70 -> V_43 = V_43 ;
if ( F_125 ( & V_70 -> V_132 ,
& T_6 -> V_138 , V_70 -> V_118 , V_43 ) )
return - 1 ;
return 0 ;
}
static bool
F_136 ( struct V_1 * V_2 V_81 ,
struct V_16 * V_20 )
{
if ( V_20 -> V_41 . V_139 )
return false ;
return true ;
}
static int F_137 ( struct V_1 * V_2 , int V_30 ,
struct V_134 * T_6 , int V_60 ,
int V_61 , int * V_140 , int * V_141 )
{
struct V_16 * V_20 ;
int V_71 ;
F_16 (evlist, evsel) {
struct V_69 * V_142 = V_2 -> V_25 ;
int * V_143 = V_140 ;
int V_43 ;
if ( V_20 -> V_41 . V_139 ) {
V_143 = V_141 ;
V_142 = V_2 -> V_26 ;
if ( ! V_142 ) {
V_142 = F_133 ( V_2 ) ;
if ( ! V_142 )
return - 1 ;
V_2 -> V_26 = V_142 ;
if ( V_2 -> V_14 == V_15 )
F_138 ( V_2 , V_144 ) ;
}
}
if ( V_20 -> V_58 && V_61 )
continue;
V_43 = F_67 ( V_20 , V_60 , V_61 ) ;
if ( * V_143 == - 1 ) {
* V_143 = V_43 ;
if ( F_134 ( & V_142 [ V_30 ] , T_6 , * V_143 ) < 0 )
return - 1 ;
} else {
if ( F_66 ( V_43 , V_145 , * V_143 ) != 0 )
return - 1 ;
F_117 ( & V_142 [ V_30 ] ) ;
}
V_71 = F_136 ( V_2 , V_20 ) ? V_78 : 0 ;
if ( ! V_20 -> V_58 &&
F_75 ( V_2 , V_43 , & V_142 [ V_30 ] , V_71 ) < 0 ) {
F_80 ( & V_142 [ V_30 ] ) ;
return - 1 ;
}
if ( V_20 -> V_41 . V_97 & V_98 ) {
if ( F_90 ( V_2 , V_20 , V_60 , V_61 ,
V_43 ) < 0 )
return - 1 ;
F_93 ( V_2 , V_20 , V_30 , V_60 ,
V_61 ) ;
}
}
return 0 ;
}
static int F_139 ( struct V_1 * V_2 ,
struct V_134 * T_6 )
{
int V_60 , V_61 ;
int V_66 = F_69 ( V_2 -> V_4 ) ;
int V_63 = F_58 ( V_2 -> V_6 ) ;
F_135 ( L_3 ) ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
int V_143 = - 1 ;
int V_146 = - 1 ;
F_128 ( & T_6 -> V_138 , V_2 , V_60 ,
true ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
if ( F_137 ( V_2 , V_60 , T_6 , V_60 ,
V_61 , & V_143 , & V_146 ) )
goto V_147;
}
}
return 0 ;
V_147:
F_132 ( V_2 ) ;
return - 1 ;
}
static int F_140 ( struct V_1 * V_2 ,
struct V_134 * T_6 )
{
int V_61 ;
int V_63 = F_58 ( V_2 -> V_6 ) ;
F_135 ( L_4 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
int V_143 = - 1 ;
int V_146 = - 1 ;
F_128 ( & T_6 -> V_138 , V_2 , V_61 ,
false ) ;
if ( F_137 ( V_2 , V_61 , T_6 , 0 , V_61 ,
& V_143 , & V_146 ) )
goto V_147;
}
return 0 ;
V_147:
F_132 ( V_2 ) ;
return - 1 ;
}
unsigned long F_141 ( void )
{
unsigned long V_148 ;
int V_149 ;
if ( F_142 ( L_5 , & V_149 ) < 0 ) {
V_149 = 512 ;
} else {
V_149 -= ( V_119 / 1024 ) ;
}
V_148 = ( V_149 * 1024 ) / V_119 ;
if ( ! F_143 ( V_148 ) )
V_148 = F_144 ( V_148 ) ;
return V_148 ;
}
static T_1 F_145 ( unsigned long V_148 )
{
if ( V_148 == V_150 )
V_148 = F_141 () ;
else if ( ! F_143 ( V_148 ) )
return 0 ;
return ( V_148 + 1 ) * V_119 ;
}
static long F_146 ( const char * V_151 , unsigned long F_106 ,
unsigned long V_149 )
{
unsigned long V_148 , V_152 ;
static struct V_153 V_154 [] = {
{ . V_155 = 'B' , . V_156 = 1 } ,
{ . V_155 = 'K' , . V_156 = 1 << 10 } ,
{ . V_155 = 'M' , . V_156 = 1 << 20 } ,
{ . V_155 = 'G' , . V_156 = 1 << 30 } ,
{ . V_155 = 0 } ,
} ;
if ( V_151 == NULL )
return - V_64 ;
V_152 = F_147 ( V_151 , V_154 ) ;
if ( V_152 != ( unsigned long ) - 1 ) {
V_148 = F_148 ( V_152 , V_119 ) / V_119 ;
} else {
char * V_157 ;
V_148 = strtoul ( V_151 , & V_157 , 10 ) ;
if ( * V_157 != '\0' )
return - V_64 ;
}
if ( V_148 == 0 && F_106 == 0 ) {
} else if ( ! F_143 ( V_148 ) ) {
V_148 = F_149 ( V_148 ) ;
if ( ! V_148 )
return - V_64 ;
F_150 ( L_6 ,
V_148 * V_119 , V_148 ) ;
}
if ( V_148 > V_149 )
return - V_64 ;
return V_148 ;
}
int F_151 ( unsigned int * V_158 , const char * V_151 )
{
unsigned long V_149 = V_150 ;
long V_148 ;
if ( V_149 > V_159 / V_119 )
V_149 = V_159 / V_119 ;
V_148 = F_146 ( V_151 , 1 , V_149 ) ;
if ( V_148 < 0 ) {
F_152 ( L_7 ) ;
return - 1 ;
}
* V_158 = V_148 ;
return 0 ;
}
int F_153 ( const struct V_160 * V_161 , const char * V_151 ,
int T_13 V_81 )
{
return F_151 ( V_161 -> V_110 , V_151 ) ;
}
int F_154 ( struct V_1 * V_2 , unsigned int V_148 ,
bool V_131 , unsigned int T_10 ,
bool T_11 )
{
struct V_16 * V_20 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_134 T_6 = {
. V_135 = V_162 | ( V_131 ? 0 : V_163 ) ,
} ;
if ( ! V_2 -> V_25 )
V_2 -> V_25 = F_133 ( V_2 ) ;
if ( ! V_2 -> V_25 )
return - V_44 ;
if ( V_2 -> V_11 . V_10 == NULL && F_72 ( V_2 ) < 0 )
return - V_44 ;
V_2 -> V_131 = V_131 ;
V_2 -> V_164 = F_145 ( V_148 ) ;
F_155 ( L_8 , V_2 -> V_164 ) ;
T_6 . V_121 = V_2 -> V_164 - V_119 - 1 ;
F_127 ( & T_6 . V_138 , V_2 -> V_164 ,
T_10 , T_11 ) ;
F_16 (evlist, evsel) {
if ( ( V_20 -> V_41 . V_97 & V_98 ) &&
V_20 -> V_165 == NULL &&
F_156 ( V_20 , F_69 ( V_4 ) , V_6 -> V_166 ) < 0 )
return - V_44 ;
}
if ( F_71 ( V_4 ) )
return F_140 ( V_2 , & T_6 ) ;
return F_139 ( V_2 , & T_6 ) ;
}
int F_157 ( struct V_1 * V_2 , unsigned int V_148 ,
bool V_131 )
{
return F_154 ( V_2 , V_148 , V_131 , 0 , false ) ;
}
int F_158 ( struct V_1 * V_2 , struct V_167 * V_167 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_159 ( V_167 -> V_13 , V_167 -> V_101 , V_167 -> V_168 ) ;
if ( ! V_6 )
return - 1 ;
if ( F_160 ( V_167 ) )
V_4 = F_161 () ;
else
V_4 = F_162 ( V_167 -> V_169 ) ;
if ( ! V_4 )
goto V_170;
V_2 -> V_28 = ! ! V_167 -> V_169 ;
F_4 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_170:
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
void F_163 ( struct V_1 * V_2 ,
enum V_171 V_172 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_164 ( V_20 , V_172 ) ;
}
void F_165 ( struct V_1 * V_2 ,
enum V_171 V_172 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_166 ( V_20 , V_172 ) ;
}
int F_167 ( struct V_1 * V_2 , struct V_16 * * V_173 )
{
struct V_16 * V_20 ;
int V_62 = 0 ;
const int V_174 = F_69 ( V_2 -> V_4 ) ,
V_175 = F_58 ( V_2 -> V_6 ) ;
F_16 (evlist, evsel) {
if ( V_20 -> V_176 == NULL )
continue;
V_62 = F_168 ( V_20 , V_174 , V_175 , V_20 -> V_176 ) ;
if ( V_62 ) {
* V_173 = V_20 ;
break;
}
}
return V_62 ;
}
int F_169 ( struct V_1 * V_2 , const char * V_176 )
{
struct V_16 * V_20 ;
int V_62 = 0 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_41 . type != V_54 )
continue;
V_62 = F_170 ( V_20 , V_176 ) ;
if ( V_62 )
break;
}
return V_62 ;
}
int F_171 ( struct V_1 * V_2 , T_1 V_177 , T_14 * V_178 )
{
char * V_176 ;
int V_91 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_177 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_172 ( & V_176 , L_9 , V_178 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_179 ;
if ( F_172 ( & V_179 , L_10 , V_176 , V_178 [ V_7 ] ) < 0 )
goto V_180;
free ( V_176 ) ;
V_176 = V_179 ;
}
}
V_91 = F_169 ( V_2 , V_176 ) ;
V_180:
free ( V_176 ) ;
return V_91 ;
}
int F_173 ( struct V_1 * V_2 , T_14 V_13 )
{
return F_171 ( V_2 , 1 , & V_13 ) ;
}
bool F_174 ( struct V_1 * V_2 )
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
T_3 F_175 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
if ( V_2 -> V_181 )
return V_2 -> V_181 ;
F_16 (evlist, evsel)
V_2 -> V_181 |= V_20 -> V_41 . V_182 ;
return V_2 -> V_181 ;
}
T_3 F_176 ( struct V_1 * V_2 )
{
V_2 -> V_181 = 0 ;
return F_175 ( V_2 ) ;
}
T_3 F_177 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
T_3 V_183 = 0 ;
F_16 (evlist, evsel)
V_183 |= V_20 -> V_41 . V_184 ;
return V_183 ;
}
bool F_178 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) , * V_21 = V_17 ;
T_3 V_97 = V_17 -> V_41 . V_97 ;
T_3 V_182 = V_17 -> V_41 . V_182 ;
F_16 (evlist, pos) {
if ( V_97 != V_21 -> V_41 . V_97 )
return false ;
}
if ( ( V_182 & V_185 ) &&
! ( V_97 & V_98 ) ) {
return false ;
}
return true ;
}
T_3 F_91 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
return V_17 -> V_41 . V_97 ;
}
T_15 F_179 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
struct V_186 * V_117 ;
T_3 V_182 ;
T_15 V_48 = 0 ;
if ( ! V_17 -> V_41 . V_109 )
goto V_187;
V_182 = V_17 -> V_41 . V_182 ;
if ( V_182 & V_188 )
V_48 += sizeof( V_117 -> V_101 ) * 2 ;
if ( V_182 & V_189 )
V_48 += sizeof( V_117 -> time ) ;
if ( V_182 & V_190 )
V_48 += sizeof( V_117 -> V_53 ) ;
if ( V_182 & V_191 )
V_48 += sizeof( V_117 -> V_192 ) ;
if ( V_182 & V_193 )
V_48 += sizeof( V_117 -> V_60 ) * 2 ;
if ( V_182 & V_194 )
V_48 += sizeof( V_117 -> V_53 ) ;
V_187:
return V_48 ;
}
bool F_180 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) , * V_21 = V_17 ;
F_181 (evlist, pos) {
if ( V_17 -> V_41 . V_109 != V_21 -> V_41 . V_109 )
return false ;
}
return true ;
}
bool F_98 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
return V_17 -> V_41 . V_109 ;
}
void F_182 ( struct V_1 * V_2 ,
struct V_16 * V_20 )
{
V_2 -> V_195 = V_20 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
int V_174 = F_69 ( V_2 -> V_4 ) ;
int V_175 = F_58 ( V_2 -> V_6 ) ;
int V_22 ;
F_183 (evlist, evsel) {
V_22 = V_20 -> V_4 ? V_20 -> V_4 -> V_166 : V_174 ;
F_184 ( V_20 , V_22 , V_175 ) ;
}
}
static int F_185 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_62 = - V_44 ;
V_4 = F_162 ( NULL ) ;
if ( ! V_4 )
goto V_187;
V_6 = F_186 () ;
if ( ! V_6 )
goto V_196;
F_4 ( V_2 , V_4 , V_6 ) ;
V_187:
return V_62 ;
V_196:
F_27 ( V_4 ) ;
goto V_187;
}
int F_187 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
int V_62 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_62 = F_185 ( V_2 ) ;
if ( V_62 < 0 )
goto V_197;
}
F_15 ( V_2 ) ;
F_16 (evlist, evsel) {
V_62 = F_188 ( V_20 , V_20 -> V_4 , V_20 -> V_6 ) ;
if ( V_62 < 0 )
goto V_197;
}
return 0 ;
V_197:
F_26 ( V_2 ) ;
V_94 = - V_62 ;
return V_62 ;
}
int F_189 ( struct V_1 * V_2 , struct V_167 * V_167 ,
const char * V_198 [] , bool V_199 ,
void (* F_190)( int V_200 , T_16 * V_201 , void * V_202 ) )
{
int V_203 [ 2 ] , V_204 [ 2 ] ;
char V_205 ;
if ( F_191 ( V_203 ) < 0 ) {
perror ( L_11 ) ;
return - 1 ;
}
if ( F_191 ( V_204 ) < 0 ) {
perror ( L_12 ) ;
goto V_206;
}
V_2 -> V_12 . V_13 = F_192 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_13 ) ;
goto V_207;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_91 ;
if ( V_199 )
F_193 ( 2 , 1 ) ;
signal ( V_208 , V_209 ) ;
F_44 ( V_203 [ 0 ] ) ;
F_44 ( V_204 [ 1 ] ) ;
F_77 ( V_204 [ 0 ] , V_210 , V_211 ) ;
F_44 ( V_203 [ 1 ] ) ;
V_91 = F_92 ( V_204 [ 0 ] , & V_205 , 1 ) ;
if ( V_91 != 1 ) {
if ( V_91 == - 1 )
perror ( L_14 ) ;
exit ( V_91 ) ;
}
F_194 ( V_198 [ 0 ] , ( char * * ) V_198 ) ;
if ( F_190 ) {
union V_212 V_152 ;
V_152 . V_213 = V_94 ;
if ( F_195 ( F_196 () , V_214 , V_152 ) )
perror ( V_198 [ 0 ] ) ;
} else
perror ( V_198 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_190 ) {
struct V_215 V_216 = {
. V_217 = V_218 ,
. V_219 = F_190 ,
} ;
V_215 ( V_214 , & V_216 , NULL ) ;
}
if ( F_197 ( V_167 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_122 , L_15 ,
V_220 , __LINE__ ) ;
goto V_207;
}
F_198 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_44 ( V_203 [ 1 ] ) ;
F_44 ( V_204 [ 0 ] ) ;
if ( F_92 ( V_203 [ 0 ] , & V_205 , 1 ) == - 1 ) {
perror ( L_14 ) ;
goto V_207;
}
F_77 ( V_204 [ 1 ] , V_210 , V_211 ) ;
V_2 -> V_12 . V_221 = V_204 [ 1 ] ;
F_44 ( V_203 [ 0 ] ) ;
return 0 ;
V_207:
F_44 ( V_204 [ 0 ] ) ;
F_44 ( V_204 [ 1 ] ) ;
V_206:
F_44 ( V_203 [ 0 ] ) ;
F_44 ( V_203 [ 1 ] ) ;
return - 1 ;
}
int F_199 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_221 > 0 ) {
char V_205 = 0 ;
int V_91 ;
V_91 = F_200 ( V_2 -> V_12 . V_221 , & V_205 , 1 ) ;
if ( V_91 < 0 )
perror ( L_16 ) ;
F_44 ( V_2 -> V_12 . V_221 ) ;
return V_91 ;
}
return 0 ;
}
int F_201 ( struct V_1 * V_2 , union V_103 * V_104 ,
struct V_186 * V_106 )
{
struct V_16 * V_20 = F_101 ( V_2 , V_104 ) ;
if ( ! V_20 )
return - V_222 ;
return F_202 ( V_20 , V_104 , V_106 ) ;
}
T_1 F_203 ( struct V_1 * V_2 , T_17 * V_223 )
{
struct V_16 * V_20 ;
T_1 V_224 = 0 ;
F_16 (evlist, evsel) {
V_224 += fprintf ( V_223 , L_17 , V_20 -> V_30 ? L_18 : L_19 ,
F_204 ( V_20 ) ) ;
}
return V_224 + fprintf ( V_223 , L_20 ) ;
}
int F_205 ( struct V_1 * V_2 ,
int V_62 , char * V_225 , T_1 V_48 )
{
int V_224 , V_110 ;
char V_226 [ V_227 ] , * V_228 = F_206 ( V_62 , V_226 , sizeof( V_226 ) ) ;
switch ( V_62 ) {
case V_229 :
case V_230 :
V_224 = F_207 ( V_225 , V_48 ,
L_21
L_22 , V_228 ) ;
V_110 = F_208 () ;
V_224 += F_207 ( V_225 + V_224 , V_48 - V_224 , L_23 ) ;
if ( V_110 >= 2 ) {
V_224 += F_207 ( V_225 + V_224 , V_48 - V_224 ,
L_24 ) ;
}
V_224 += F_207 ( V_225 + V_224 , V_48 - V_224 ,
L_25 ) ;
V_224 += F_207 ( V_225 + V_224 , V_48 - V_224 ,
L_26
L_27 , V_110 ) ;
break;
case V_64 : {
struct V_16 * V_17 = F_14 ( V_2 ) ;
int V_231 ;
if ( F_142 ( L_28 , & V_231 ) < 0 )
goto V_232;
if ( V_17 -> V_41 . V_233 < ( T_3 ) V_231 )
goto V_232;
V_224 = F_207 ( V_225 , V_48 ,
L_21
L_29
L_30 V_234 L_31 ,
V_228 , V_231 , V_17 -> V_41 . V_233 ) ;
break;
}
default:
V_232:
F_207 ( V_225 , V_48 , L_32 , V_228 ) ;
break;
}
return 0 ;
}
int F_209 ( struct V_1 * V_2 , int V_62 , char * V_225 , T_1 V_48 )
{
char V_226 [ V_227 ] , * V_228 = F_206 ( V_62 , V_226 , sizeof( V_226 ) ) ;
int V_235 = V_2 -> V_164 / 1024 , V_236 , V_224 = 0 ;
switch ( V_62 ) {
case V_230 :
F_142 ( L_5 , & V_236 ) ;
V_224 += F_207 ( V_225 + V_224 , V_48 - V_224 ,
L_21
L_33
L_34 ,
V_228 , V_236 , V_235 ) ;
if ( V_235 >= V_236 ) {
V_224 += F_207 ( V_225 + V_224 , V_48 - V_224 ,
L_35 ,
V_236 + V_235 ) ;
}
V_224 += F_207 ( V_225 + V_224 , V_48 - V_224 ,
L_36 ) ;
break;
default:
F_207 ( V_225 , V_48 , L_32 , V_228 ) ;
break;
}
return 0 ;
}
void F_210 ( struct V_1 * V_2 ,
struct V_16 * V_237 )
{
struct V_16 * V_20 , * V_22 ;
F_48 ( V_238 ) ;
if ( V_237 == F_14 ( V_2 ) )
return;
F_19 (evlist, n, evsel) {
if ( V_20 -> V_35 == V_237 -> V_35 )
F_211 ( & V_20 -> V_23 , & V_238 ) ;
}
F_212 ( & V_238 , & V_2 -> V_10 ) ;
}
void F_213 ( struct V_1 * V_2 ,
struct V_16 * V_239 )
{
struct V_16 * V_20 ;
if ( V_239 -> V_31 )
return;
F_16 (evlist, evsel) {
if ( V_20 != V_239 )
V_20 -> V_31 = false ;
}
V_239 -> V_31 = true ;
}
struct V_16 *
F_214 ( struct V_1 * V_2 ,
const char * V_151 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( ! V_20 -> V_55 )
continue;
if ( strcmp ( V_151 , V_20 -> V_55 ) == 0 )
return V_20 ;
}
return NULL ;
}
void F_138 ( struct V_1 * V_2 ,
enum V_14 V_240 )
{
enum V_14 V_241 = V_2 -> V_14 ;
enum T_18 {
V_242 ,
V_243 ,
V_244 ,
} T_18 = V_242 ;
if ( ! V_2 -> V_26 )
return;
switch ( V_241 ) {
case V_15 : {
if ( V_240 != V_144 )
goto V_245; ;
break;
}
case V_144 : {
if ( V_240 != V_246 )
goto V_245;
T_18 = V_243 ;
break;
}
case V_246 : {
if ( V_240 != V_247 )
goto V_245;
break;
}
case V_247 : {
if ( V_240 != V_144 )
goto V_245;
T_18 = V_244 ;
break;
}
default:
F_215 ( 1 , L_37 ) ;
}
V_2 -> V_14 = V_240 ;
switch ( T_18 ) {
case V_243 :
F_103 ( V_2 ) ;
break;
case V_244 :
F_104 ( V_2 ) ;
break;
case V_242 :
default:
break;
}
V_245:
return;
}
