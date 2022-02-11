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
int V_61 ;
int V_62 = F_57 ( V_2 , V_20 ) ;
if ( ! V_20 -> V_43 )
return - V_63 ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
int V_64 = F_66 ( F_67 ( V_20 , V_60 , V_61 ) , V_65 , 0 ) ;
if ( V_64 )
return V_64 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_16 * V_20 ,
int V_61 )
{
int V_60 ;
int V_66 = F_69 ( V_2 -> V_4 ) ;
if ( ! V_20 -> V_43 )
return - V_63 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
int V_64 = F_66 ( F_67 ( V_20 , V_60 , V_61 ) , V_65 , 0 ) ;
if ( V_64 )
return V_64 ;
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
int V_62 = F_58 ( V_2 -> V_6 ) ;
int V_68 = 0 ;
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_58 )
V_68 += V_66 ;
else
V_68 += V_66 * V_62 ;
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
int V_64 ;
if ( V_43 < 0 )
continue;
V_64 = F_66 ( V_43 , V_112 , V_110 ? 1 : 0 ) ;
if ( V_64 )
return V_64 ;
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
struct V_134 * T_6 , int V_140 ,
int V_61 , int * V_141 , int * V_142 )
{
struct V_16 * V_20 ;
int V_71 ;
int V_143 = F_138 ( V_2 -> V_4 , V_140 ) ;
F_16 (evlist, evsel) {
struct V_69 * V_144 = V_2 -> V_25 ;
int * V_145 = V_141 ;
int V_43 ;
int V_60 ;
if ( V_20 -> V_41 . V_139 ) {
V_145 = V_142 ;
V_144 = V_2 -> V_26 ;
if ( ! V_144 ) {
V_144 = F_133 ( V_2 ) ;
if ( ! V_144 )
return - 1 ;
V_2 -> V_26 = V_144 ;
if ( V_2 -> V_14 == V_15 )
F_139 ( V_2 , V_146 ) ;
}
}
if ( V_20 -> V_58 && V_61 )
continue;
V_60 = F_140 ( V_20 -> V_4 , V_143 ) ;
if ( V_60 == - 1 )
continue;
V_43 = F_67 ( V_20 , V_60 , V_61 ) ;
if ( * V_145 == - 1 ) {
* V_145 = V_43 ;
if ( F_134 ( & V_144 [ V_30 ] , T_6 , * V_145 ) < 0 )
return - 1 ;
} else {
if ( F_66 ( V_43 , V_147 , * V_145 ) != 0 )
return - 1 ;
F_117 ( & V_144 [ V_30 ] ) ;
}
V_71 = F_136 ( V_2 , V_20 ) ? V_78 : 0 ;
if ( ! V_20 -> V_58 &&
F_75 ( V_2 , V_43 , & V_144 [ V_30 ] , V_71 ) < 0 ) {
F_80 ( & V_144 [ V_30 ] ) ;
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
static int F_141 ( struct V_1 * V_2 ,
struct V_134 * T_6 )
{
int V_60 , V_61 ;
int V_66 = F_69 ( V_2 -> V_4 ) ;
int V_62 = F_58 ( V_2 -> V_6 ) ;
F_135 ( L_3 ) ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
int V_145 = - 1 ;
int V_148 = - 1 ;
F_128 ( & T_6 -> V_138 , V_2 , V_60 ,
true ) ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
if ( F_137 ( V_2 , V_60 , T_6 , V_60 ,
V_61 , & V_145 , & V_148 ) )
goto V_149;
}
}
return 0 ;
V_149:
F_132 ( V_2 ) ;
return - 1 ;
}
static int F_142 ( struct V_1 * V_2 ,
struct V_134 * T_6 )
{
int V_61 ;
int V_62 = F_58 ( V_2 -> V_6 ) ;
F_135 ( L_4 ) ;
for ( V_61 = 0 ; V_61 < V_62 ; V_61 ++ ) {
int V_145 = - 1 ;
int V_148 = - 1 ;
F_128 ( & T_6 -> V_138 , V_2 , V_61 ,
false ) ;
if ( F_137 ( V_2 , V_61 , T_6 , 0 , V_61 ,
& V_145 , & V_148 ) )
goto V_149;
}
return 0 ;
V_149:
F_132 ( V_2 ) ;
return - 1 ;
}
unsigned long F_143 ( void )
{
unsigned long V_150 ;
int V_151 ;
if ( F_144 ( L_5 , & V_151 ) < 0 ) {
V_151 = 512 ;
} else {
V_151 -= ( V_119 / 1024 ) ;
}
V_150 = ( V_151 * 1024 ) / V_119 ;
if ( ! F_145 ( V_150 ) )
V_150 = F_146 ( V_150 ) ;
return V_150 ;
}
static T_1 F_147 ( unsigned long V_150 )
{
if ( V_150 == V_152 )
V_150 = F_143 () ;
else if ( ! F_145 ( V_150 ) )
return 0 ;
return ( V_150 + 1 ) * V_119 ;
}
static long F_148 ( const char * V_153 , unsigned long F_106 ,
unsigned long V_151 )
{
unsigned long V_150 , V_154 ;
static struct V_155 V_156 [] = {
{ . V_157 = 'B' , . V_158 = 1 } ,
{ . V_157 = 'K' , . V_158 = 1 << 10 } ,
{ . V_157 = 'M' , . V_158 = 1 << 20 } ,
{ . V_157 = 'G' , . V_158 = 1 << 30 } ,
{ . V_157 = 0 } ,
} ;
if ( V_153 == NULL )
return - V_63 ;
V_154 = F_149 ( V_153 , V_156 ) ;
if ( V_154 != ( unsigned long ) - 1 ) {
V_150 = F_150 ( V_154 , V_119 ) / V_119 ;
} else {
char * V_159 ;
V_150 = strtoul ( V_153 , & V_159 , 10 ) ;
if ( * V_159 != '\0' )
return - V_63 ;
}
if ( V_150 == 0 && F_106 == 0 ) {
} else if ( ! F_145 ( V_150 ) ) {
V_150 = F_151 ( V_150 ) ;
if ( ! V_150 )
return - V_63 ;
F_152 ( L_6 ,
V_150 * V_119 , V_150 ) ;
}
if ( V_150 > V_151 )
return - V_63 ;
return V_150 ;
}
int F_153 ( unsigned int * V_160 , const char * V_153 )
{
unsigned long V_151 = V_152 ;
long V_150 ;
if ( V_151 > V_161 / V_119 )
V_151 = V_161 / V_119 ;
V_150 = F_148 ( V_153 , 1 , V_151 ) ;
if ( V_150 < 0 ) {
F_154 ( L_7 ) ;
return - 1 ;
}
* V_160 = V_150 ;
return 0 ;
}
int F_155 ( const struct V_162 * V_163 , const char * V_153 ,
int T_13 V_81 )
{
return F_153 ( V_163 -> V_110 , V_153 ) ;
}
int F_156 ( struct V_1 * V_2 , unsigned int V_150 ,
bool V_131 , unsigned int T_10 ,
bool T_11 )
{
struct V_16 * V_20 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_134 T_6 = {
. V_135 = V_164 | ( V_131 ? 0 : V_165 ) ,
} ;
if ( ! V_2 -> V_25 )
V_2 -> V_25 = F_133 ( V_2 ) ;
if ( ! V_2 -> V_25 )
return - V_44 ;
if ( V_2 -> V_11 . V_10 == NULL && F_72 ( V_2 ) < 0 )
return - V_44 ;
V_2 -> V_131 = V_131 ;
V_2 -> V_166 = F_147 ( V_150 ) ;
F_157 ( L_8 , V_2 -> V_166 ) ;
T_6 . V_121 = V_2 -> V_166 - V_119 - 1 ;
F_127 ( & T_6 . V_138 , V_2 -> V_166 ,
T_10 , T_11 ) ;
F_16 (evlist, evsel) {
if ( ( V_20 -> V_41 . V_97 & V_98 ) &&
V_20 -> V_167 == NULL &&
F_158 ( V_20 , F_69 ( V_4 ) , V_6 -> V_168 ) < 0 )
return - V_44 ;
}
if ( F_71 ( V_4 ) )
return F_142 ( V_2 , & T_6 ) ;
return F_141 ( V_2 , & T_6 ) ;
}
int F_159 ( struct V_1 * V_2 , unsigned int V_150 ,
bool V_131 )
{
return F_156 ( V_2 , V_150 , V_131 , 0 , false ) ;
}
int F_160 ( struct V_1 * V_2 , struct V_169 * V_169 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_161 ( V_169 -> V_13 , V_169 -> V_101 , V_169 -> V_170 ) ;
if ( ! V_6 )
return - 1 ;
if ( F_162 ( V_169 ) )
V_4 = F_163 () ;
else
V_4 = F_164 ( V_169 -> V_171 ) ;
if ( ! V_4 )
goto V_172;
V_2 -> V_28 = ! ! V_169 -> V_171 ;
F_4 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_172:
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
void F_165 ( struct V_1 * V_2 ,
enum V_173 V_174 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_166 ( V_20 , V_174 ) ;
}
void F_167 ( struct V_1 * V_2 ,
enum V_173 V_174 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel)
F_168 ( V_20 , V_174 ) ;
}
int F_169 ( struct V_1 * V_2 , struct V_16 * * V_175 )
{
struct V_16 * V_20 ;
int V_64 = 0 ;
const int V_176 = F_69 ( V_2 -> V_4 ) ,
V_177 = F_58 ( V_2 -> V_6 ) ;
F_16 (evlist, evsel) {
if ( V_20 -> V_178 == NULL )
continue;
V_64 = F_170 ( V_20 , V_176 , V_177 , V_20 -> V_178 ) ;
if ( V_64 ) {
* V_175 = V_20 ;
break;
}
}
return V_64 ;
}
int F_171 ( struct V_1 * V_2 , const char * V_178 )
{
struct V_16 * V_20 ;
int V_64 = 0 ;
F_16 (evlist, evsel) {
if ( V_20 -> V_41 . type != V_54 )
continue;
V_64 = F_172 ( V_20 , V_178 ) ;
if ( V_64 )
break;
}
return V_64 ;
}
int F_173 ( struct V_1 * V_2 , T_1 V_179 , T_14 * V_180 )
{
char * V_178 ;
int V_91 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_179 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_174 ( & V_178 , L_9 , V_180 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_181 ;
if ( F_174 ( & V_181 , L_10 , V_178 , V_180 [ V_7 ] ) < 0 )
goto V_182;
free ( V_178 ) ;
V_178 = V_181 ;
}
}
V_91 = F_171 ( V_2 , V_178 ) ;
V_182:
free ( V_178 ) ;
return V_91 ;
}
int F_175 ( struct V_1 * V_2 , T_14 V_13 )
{
return F_173 ( V_2 , 1 , & V_13 ) ;
}
bool F_176 ( struct V_1 * V_2 )
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
T_3 F_177 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
if ( V_2 -> V_183 )
return V_2 -> V_183 ;
F_16 (evlist, evsel)
V_2 -> V_183 |= V_20 -> V_41 . V_184 ;
return V_2 -> V_183 ;
}
T_3 F_178 ( struct V_1 * V_2 )
{
V_2 -> V_183 = 0 ;
return F_177 ( V_2 ) ;
}
T_3 F_179 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
T_3 V_185 = 0 ;
F_16 (evlist, evsel)
V_185 |= V_20 -> V_41 . V_186 ;
return V_185 ;
}
bool F_180 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) , * V_21 = V_17 ;
T_3 V_97 = V_17 -> V_41 . V_97 ;
T_3 V_184 = V_17 -> V_41 . V_184 ;
F_16 (evlist, pos) {
if ( V_97 != V_21 -> V_41 . V_97 )
return false ;
}
if ( ( V_184 & V_187 ) &&
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
T_15 F_181 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) ;
struct V_188 * V_117 ;
T_3 V_184 ;
T_15 V_48 = 0 ;
if ( ! V_17 -> V_41 . V_109 )
goto V_189;
V_184 = V_17 -> V_41 . V_184 ;
if ( V_184 & V_190 )
V_48 += sizeof( V_117 -> V_101 ) * 2 ;
if ( V_184 & V_191 )
V_48 += sizeof( V_117 -> time ) ;
if ( V_184 & V_192 )
V_48 += sizeof( V_117 -> V_53 ) ;
if ( V_184 & V_193 )
V_48 += sizeof( V_117 -> V_194 ) ;
if ( V_184 & V_195 )
V_48 += sizeof( V_117 -> V_60 ) * 2 ;
if ( V_184 & V_196 )
V_48 += sizeof( V_117 -> V_53 ) ;
V_189:
return V_48 ;
}
bool F_182 ( struct V_1 * V_2 )
{
struct V_16 * V_17 = F_14 ( V_2 ) , * V_21 = V_17 ;
F_183 (evlist, pos) {
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
void F_184 ( struct V_1 * V_2 ,
struct V_16 * V_20 )
{
V_2 -> V_197 = V_20 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
int V_176 = F_69 ( V_2 -> V_4 ) ;
int V_177 = F_58 ( V_2 -> V_6 ) ;
F_185 (evlist, evsel) {
int V_22 = V_20 -> V_4 ? V_20 -> V_4 -> V_168 : V_176 ;
F_186 ( V_20 , V_22 , V_177 ) ;
}
}
static int F_187 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_64 = - V_44 ;
V_4 = F_164 ( NULL ) ;
if ( ! V_4 )
goto V_189;
V_6 = F_188 () ;
if ( ! V_6 )
goto V_198;
F_4 ( V_2 , V_4 , V_6 ) ;
V_189:
return V_64 ;
V_198:
F_27 ( V_4 ) ;
goto V_189;
}
int F_189 ( struct V_1 * V_2 )
{
struct V_16 * V_20 ;
int V_64 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_64 = F_187 ( V_2 ) ;
if ( V_64 < 0 )
goto V_199;
}
F_15 ( V_2 ) ;
F_16 (evlist, evsel) {
V_64 = F_190 ( V_20 , V_20 -> V_4 , V_20 -> V_6 ) ;
if ( V_64 < 0 )
goto V_199;
}
return 0 ;
V_199:
F_26 ( V_2 ) ;
V_94 = - V_64 ;
return V_64 ;
}
int F_191 ( struct V_1 * V_2 , struct V_169 * V_169 ,
const char * V_200 [] , bool V_201 ,
void (* F_192)( int V_202 , T_16 * V_203 , void * V_204 ) )
{
int V_205 [ 2 ] , V_206 [ 2 ] ;
char V_207 ;
if ( F_193 ( V_205 ) < 0 ) {
perror ( L_11 ) ;
return - 1 ;
}
if ( F_193 ( V_206 ) < 0 ) {
perror ( L_12 ) ;
goto V_208;
}
V_2 -> V_12 . V_13 = F_194 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_13 ) ;
goto V_209;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_91 ;
if ( V_201 )
F_195 ( 2 , 1 ) ;
signal ( V_210 , V_211 ) ;
F_44 ( V_205 [ 0 ] ) ;
F_44 ( V_206 [ 1 ] ) ;
F_77 ( V_206 [ 0 ] , V_212 , V_213 ) ;
F_44 ( V_205 [ 1 ] ) ;
V_91 = F_92 ( V_206 [ 0 ] , & V_207 , 1 ) ;
if ( V_91 != 1 ) {
if ( V_91 == - 1 )
perror ( L_14 ) ;
exit ( V_91 ) ;
}
F_196 ( V_200 [ 0 ] , ( char * * ) V_200 ) ;
if ( F_192 ) {
union V_214 V_154 ;
V_154 . V_215 = V_94 ;
if ( F_197 ( F_198 () , V_216 , V_154 ) )
perror ( V_200 [ 0 ] ) ;
} else
perror ( V_200 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_192 ) {
struct V_217 V_218 = {
. V_219 = V_220 ,
. V_221 = F_192 ,
} ;
V_217 ( V_216 , & V_218 , NULL ) ;
}
if ( F_199 ( V_169 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_122 , L_15 ,
V_222 , __LINE__ ) ;
goto V_209;
}
F_200 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_44 ( V_205 [ 1 ] ) ;
F_44 ( V_206 [ 0 ] ) ;
if ( F_92 ( V_205 [ 0 ] , & V_207 , 1 ) == - 1 ) {
perror ( L_14 ) ;
goto V_209;
}
F_77 ( V_206 [ 1 ] , V_212 , V_213 ) ;
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
int F_201 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_223 > 0 ) {
char V_207 = 0 ;
int V_91 ;
V_91 = F_202 ( V_2 -> V_12 . V_223 , & V_207 , 1 ) ;
if ( V_91 < 0 )
perror ( L_16 ) ;
F_44 ( V_2 -> V_12 . V_223 ) ;
return V_91 ;
}
return 0 ;
}
int F_203 ( struct V_1 * V_2 , union V_103 * V_104 ,
struct V_188 * V_106 )
{
struct V_16 * V_20 = F_101 ( V_2 , V_104 ) ;
if ( ! V_20 )
return - V_224 ;
return F_204 ( V_20 , V_104 , V_106 ) ;
}
T_1 F_205 ( struct V_1 * V_2 , T_17 * V_225 )
{
struct V_16 * V_20 ;
T_1 V_226 = 0 ;
F_16 (evlist, evsel) {
V_226 += fprintf ( V_225 , L_17 , V_20 -> V_30 ? L_18 : L_19 ,
F_206 ( V_20 ) ) ;
}
return V_226 + fprintf ( V_225 , L_20 ) ;
}
int F_207 ( struct V_1 * V_2 ,
int V_64 , char * V_227 , T_1 V_48 )
{
int V_226 , V_110 ;
char V_228 [ V_229 ] , * V_230 = F_208 ( V_64 , V_228 , sizeof( V_228 ) ) ;
switch ( V_64 ) {
case V_231 :
case V_232 :
V_226 = F_209 ( V_227 , V_48 ,
L_21
L_22 , V_230 ) ;
V_110 = F_210 () ;
V_226 += F_209 ( V_227 + V_226 , V_48 - V_226 , L_23 ) ;
if ( V_110 >= 2 ) {
V_226 += F_209 ( V_227 + V_226 , V_48 - V_226 ,
L_24 ) ;
}
V_226 += F_209 ( V_227 + V_226 , V_48 - V_226 ,
L_25 ) ;
V_226 += F_209 ( V_227 + V_226 , V_48 - V_226 ,
L_26
L_27 , V_110 ) ;
break;
case V_63 : {
struct V_16 * V_17 = F_14 ( V_2 ) ;
int V_233 ;
if ( F_144 ( L_28 , & V_233 ) < 0 )
goto V_234;
if ( V_17 -> V_41 . V_235 < ( T_3 ) V_233 )
goto V_234;
V_226 = F_209 ( V_227 , V_48 ,
L_21
L_29
L_30 V_236 L_31 ,
V_230 , V_233 , V_17 -> V_41 . V_235 ) ;
break;
}
default:
V_234:
F_209 ( V_227 , V_48 , L_32 , V_230 ) ;
break;
}
return 0 ;
}
int F_211 ( struct V_1 * V_2 , int V_64 , char * V_227 , T_1 V_48 )
{
char V_228 [ V_229 ] , * V_230 = F_208 ( V_64 , V_228 , sizeof( V_228 ) ) ;
int V_237 = V_2 -> V_166 / 1024 , V_238 , V_226 = 0 ;
switch ( V_64 ) {
case V_232 :
F_144 ( L_5 , & V_238 ) ;
V_226 += F_209 ( V_227 + V_226 , V_48 - V_226 ,
L_21
L_33
L_34 ,
V_230 , V_238 , V_237 ) ;
if ( V_237 >= V_238 ) {
V_226 += F_209 ( V_227 + V_226 , V_48 - V_226 ,
L_35 ,
V_238 + V_237 ) ;
}
V_226 += F_209 ( V_227 + V_226 , V_48 - V_226 ,
L_36 ) ;
break;
default:
F_209 ( V_227 , V_48 , L_32 , V_230 ) ;
break;
}
return 0 ;
}
void F_212 ( struct V_1 * V_2 ,
struct V_16 * V_239 )
{
struct V_16 * V_20 , * V_22 ;
F_48 ( V_240 ) ;
if ( V_239 == F_14 ( V_2 ) )
return;
F_19 (evlist, n, evsel) {
if ( V_20 -> V_35 == V_239 -> V_35 )
F_213 ( & V_20 -> V_23 , & V_240 ) ;
}
F_214 ( & V_240 , & V_2 -> V_10 ) ;
}
void F_215 ( struct V_1 * V_2 ,
struct V_16 * V_241 )
{
struct V_16 * V_20 ;
if ( V_241 -> V_31 )
return;
F_16 (evlist, evsel) {
if ( V_20 != V_241 )
V_20 -> V_31 = false ;
}
V_241 -> V_31 = true ;
}
struct V_16 *
F_216 ( struct V_1 * V_2 ,
const char * V_153 )
{
struct V_16 * V_20 ;
F_16 (evlist, evsel) {
if ( ! V_20 -> V_55 )
continue;
if ( strcmp ( V_153 , V_20 -> V_55 ) == 0 )
return V_20 ;
}
return NULL ;
}
void F_139 ( struct V_1 * V_2 ,
enum V_14 V_242 )
{
enum V_14 V_243 = V_2 -> V_14 ;
enum T_18 {
V_244 ,
V_245 ,
V_246 ,
} T_18 = V_244 ;
if ( ! V_2 -> V_26 )
return;
switch ( V_243 ) {
case V_15 : {
if ( V_242 != V_146 )
goto V_247; ;
break;
}
case V_146 : {
if ( V_242 != V_248 )
goto V_247;
T_18 = V_245 ;
break;
}
case V_248 : {
if ( V_242 != V_249 )
goto V_247;
break;
}
case V_249 : {
if ( V_242 != V_146 )
goto V_247;
T_18 = V_246 ;
break;
}
default:
F_217 ( 1 , L_37 ) ;
}
V_2 -> V_14 = V_242 ;
switch ( T_18 ) {
case V_245 :
F_103 ( V_2 ) ;
break;
case V_246 :
F_104 ( V_2 ) ;
break;
case V_244 :
default:
break;
}
V_247:
return;
}
