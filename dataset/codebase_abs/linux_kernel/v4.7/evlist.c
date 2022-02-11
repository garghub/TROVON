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
V_2 -> V_14 = false ;
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
struct V_15 * V_16 = F_14 ( V_2 ) ;
V_2 -> V_17 = V_16 -> V_17 ;
V_2 -> V_18 = V_16 -> V_18 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel)
F_17 ( V_19 ) ;
F_13 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_15 * V_20 , * V_21 ;
F_19 (evlist, n, pos) {
F_20 ( & V_20 -> V_22 ) ;
V_20 -> V_2 = NULL ;
F_21 ( V_20 ) ;
}
V_2 -> V_23 = 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_24 ) ;
F_24 ( & V_2 -> V_11 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
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
struct V_15 * V_19 )
{
if ( ! V_19 -> V_25 || V_2 -> V_26 ) {
F_27 ( V_19 -> V_4 ) ;
V_19 -> V_4 = F_30 ( V_2 -> V_4 ) ;
} else if ( V_19 -> V_4 != V_19 -> V_25 ) {
F_27 ( V_19 -> V_4 ) ;
V_19 -> V_4 = F_30 ( V_19 -> V_25 ) ;
}
F_28 ( V_19 -> V_6 ) ;
V_19 -> V_6 = F_31 ( V_2 -> V_6 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel)
F_29 ( V_2 , V_19 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_15 * V_27 )
{
V_27 -> V_2 = V_2 ;
F_34 ( & V_27 -> V_22 , & V_2 -> V_10 ) ;
V_27 -> V_28 = V_2 -> V_23 ;
V_27 -> V_29 = ! V_27 -> V_28 ;
if ( ! V_2 -> V_23 ++ )
F_13 ( V_2 ) ;
F_29 ( V_2 , V_27 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_15 * V_19 )
{
V_19 -> V_2 = NULL ;
F_20 ( & V_19 -> V_22 ) ;
V_2 -> V_23 -= 1 ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
struct V_15 * V_19 , * V_32 ;
F_37 (list, temp, evsel) {
F_20 ( & V_19 -> V_22 ) ;
F_33 ( V_2 , V_19 ) ;
}
}
void F_38 ( struct V_30 * V_31 )
{
struct V_15 * V_19 , * V_33 ;
V_33 = F_39 ( V_31 -> V_34 , struct V_15 , V_22 ) ;
V_19 = F_39 ( V_31 -> V_35 , struct V_15 , V_22 ) ;
V_33 -> V_36 = V_19 -> V_28 - V_33 -> V_28 + 1 ;
F_40 (list, evsel) {
V_19 -> V_33 = V_33 ;
}
}
void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_23 ) {
V_2 -> V_37 = V_2 -> V_23 > 1 ? 1 : 0 ;
F_38 ( & V_2 -> V_10 ) ;
}
}
void F_42 ( struct V_38 * V_39 )
{
V_39 -> V_40 = 3 ;
while ( V_39 -> V_40 != 0 ) {
int V_41 = F_43 ( V_39 , 0 , - 1 , - 1 , 0 ) ;
if ( V_41 != - 1 ) {
F_44 ( V_41 ) ;
break;
}
-- V_39 -> V_40 ;
}
}
int F_9 ( struct V_1 * V_2 )
{
struct V_38 V_39 = {
. type = V_42 ,
. V_43 = V_44 ,
} ;
struct V_15 * V_19 ;
F_45 ( & V_39 ) ;
F_42 ( & V_39 ) ;
V_19 = F_46 ( & V_39 ) ;
if ( V_19 == NULL )
goto error;
if ( F_47 ( & V_19 -> V_45 , L_1 ,
V_39 . V_40 ? V_39 . V_40 + 1 : 0 , L_2 ) < 0 )
goto V_46;
F_33 ( V_2 , V_19 ) ;
return 0 ;
V_46:
F_21 ( V_19 ) ;
error:
return - V_47 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_38 V_39 = {
. type = V_48 ,
. V_43 = V_49 ,
. V_50 = sizeof( V_39 ) ,
} ;
struct V_15 * V_19 = F_46 ( & V_39 ) ;
if ( V_19 == NULL )
return - V_47 ;
F_33 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_38 * V_51 , T_1 V_52 )
{
struct V_15 * V_19 , * V_21 ;
F_49 ( V_53 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_52 ; V_7 ++ ) {
V_19 = F_50 ( V_51 + V_7 , V_2 -> V_23 + V_7 ) ;
if ( V_19 == NULL )
goto V_54;
F_34 ( & V_19 -> V_22 , & V_53 ) ;
}
F_36 ( V_2 , & V_53 ) ;
return 0 ;
V_54:
F_37 (&head, n, evsel)
F_21 ( V_19 ) ;
return - 1 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_38 * V_51 , T_1 V_52 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_52 ; V_7 ++ )
F_45 ( V_51 + V_7 ) ;
return F_48 ( V_2 , V_51 , V_52 ) ;
}
struct V_15 *
F_52 ( struct V_1 * V_2 , int V_55 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel) {
if ( V_19 -> V_39 . type == V_56 &&
( int ) V_19 -> V_39 . V_43 == V_55 )
return V_19 ;
}
return NULL ;
}
struct V_15 *
F_53 ( struct V_1 * V_2 ,
const char * V_45 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel) {
if ( ( V_19 -> V_39 . type == V_56 ) &&
( strcmp ( V_19 -> V_45 , V_45 ) == 0 ) )
return V_19 ;
}
return NULL ;
}
int F_54 ( struct V_1 * V_2 ,
const char * V_57 , const char * V_45 , void * V_58 )
{
struct V_15 * V_19 = F_55 ( V_57 , V_45 ) ;
if ( F_56 ( V_19 ) )
return - 1 ;
V_19 -> V_58 = V_58 ;
F_33 ( V_2 , V_19 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_15 * V_19 )
{
if ( V_19 -> V_59 )
return 1 ;
else
return F_58 ( V_2 -> V_6 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_15 * V_20 ;
F_16 (evlist, pos) {
if ( ! F_60 ( V_20 ) || ! V_20 -> V_41 )
continue;
F_61 ( V_20 ) ;
}
V_2 -> V_60 = false ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_15 * V_20 ;
F_16 (evlist, pos) {
if ( ! F_60 ( V_20 ) || ! V_20 -> V_41 )
continue;
F_63 ( V_20 ) ;
}
V_2 -> V_60 = true ;
}
void F_64 ( struct V_1 * V_2 )
{
( V_2 -> V_60 ? F_59 : F_62 ) ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_15 * V_19 , int V_61 )
{
int V_62 , V_63 ;
int V_64 = F_57 ( V_2 , V_19 ) ;
if ( ! V_19 -> V_41 )
return - V_65 ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ ) {
V_63 = F_66 ( F_67 ( V_19 , V_61 , V_62 ) ,
V_66 , 0 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_15 * V_19 ,
int V_62 )
{
int V_61 , V_63 ;
int V_67 = F_69 ( V_2 -> V_4 ) ;
if ( ! V_19 -> V_41 )
return - V_65 ;
for ( V_61 = 0 ; V_61 < V_67 ; V_61 ++ ) {
V_63 = F_66 ( F_67 ( V_19 , V_61 , V_62 ) , V_66 , 0 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_15 * V_19 , int V_28 )
{
bool V_68 = ! F_71 ( V_2 -> V_4 ) ;
if ( V_68 )
return F_65 ( V_2 , V_19 , V_28 ) ;
else
return F_68 ( V_2 , V_19 , V_28 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_67 = F_69 ( V_2 -> V_4 ) ;
int V_64 = F_58 ( V_2 -> V_6 ) ;
int V_69 = 0 ;
struct V_15 * V_19 ;
F_16 (evlist, evsel) {
if ( V_19 -> V_59 )
V_69 += V_67 ;
else
V_69 += V_67 * V_64 ;
}
if ( F_73 ( & V_2 -> V_11 ) < V_69 &&
F_74 ( & V_2 -> V_11 , V_69 ) < 0 )
return - V_47 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , int V_41 , int V_28 )
{
int V_20 = F_76 ( & V_2 -> V_11 , V_41 , V_70 | V_71 | V_72 ) ;
if ( V_20 >= 0 ) {
V_2 -> V_11 . V_73 [ V_20 ] . V_28 = V_28 ;
F_77 ( V_41 , V_74 , V_75 ) ;
}
return V_20 ;
}
int F_78 ( struct V_1 * V_2 , int V_41 )
{
return F_75 ( V_2 , V_41 , - 1 ) ;
}
static void F_79 ( struct V_76 * V_77 , int V_41 )
{
struct V_1 * V_2 = F_80 ( V_77 , struct V_1 , V_11 ) ;
F_81 ( V_2 , V_77 -> V_73 [ V_41 ] . V_28 ) ;
}
int F_82 ( struct V_1 * V_2 , short V_78 )
{
return F_83 ( & V_2 -> V_11 , V_78 ,
F_79 ) ;
}
int F_84 ( struct V_1 * V_2 , int V_79 )
{
return F_85 ( & V_2 -> V_11 , V_79 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_15 * V_19 ,
int V_61 , int V_62 , T_2 V_55 )
{
int V_80 ;
struct V_81 * V_82 = F_87 ( V_19 , V_61 , V_62 ) ;
V_82 -> V_55 = V_55 ;
V_82 -> V_19 = V_19 ;
V_80 = F_88 ( V_82 -> V_55 , V_83 ) ;
F_89 ( & V_82 -> V_22 , & V_2 -> V_9 [ V_80 ] ) ;
}
void F_90 ( struct V_1 * V_2 , struct V_15 * V_19 ,
int V_61 , int V_62 , T_2 V_55 )
{
F_86 ( V_2 , V_19 , V_61 , V_62 , V_55 ) ;
V_19 -> V_55 [ V_19 -> V_84 ++ ] = V_55 ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_15 * V_19 ,
int V_61 , int V_62 , int V_41 )
{
T_2 V_85 [ 4 ] = { 0 , } ;
int V_86 = 1 ;
T_2 V_55 ;
int V_87 ;
V_87 = F_66 ( V_41 , V_88 , & V_55 ) ;
if ( ! V_87 )
goto V_89;
if ( V_90 != V_91 )
return - 1 ;
if ( F_92 ( V_2 ) & V_92 )
return - 1 ;
if ( ! ( V_19 -> V_39 . V_93 & V_94 ) ||
F_93 ( V_41 , & V_85 , sizeof( V_85 ) ) == - 1 )
return - 1 ;
if ( V_19 -> V_39 . V_93 & V_95 )
++ V_86 ;
if ( V_19 -> V_39 . V_93 & V_96 )
++ V_86 ;
V_55 = V_85 [ V_86 ] ;
V_89:
F_90 ( V_2 , V_19 , V_61 , V_62 , V_55 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_15 * V_19 , int V_28 , int V_61 ,
int V_62 )
{
struct V_81 * V_82 = F_87 ( V_19 , V_61 , V_62 ) ;
V_82 -> V_28 = V_28 ;
if ( V_2 -> V_4 && V_61 >= 0 )
V_82 -> V_61 = V_2 -> V_4 -> V_97 [ V_61 ] ;
else
V_82 -> V_61 = - 1 ;
if ( ! V_19 -> V_59 && V_2 -> V_6 && V_62 >= 0 )
V_82 -> V_98 = F_95 ( V_2 -> V_6 , V_62 ) ;
else
V_82 -> V_98 = - 1 ;
}
struct V_81 * F_96 ( struct V_1 * V_2 , T_2 V_55 )
{
struct V_99 * V_53 ;
struct V_81 * V_82 ;
int V_80 ;
V_80 = F_88 ( V_55 , V_83 ) ;
V_53 = & V_2 -> V_9 [ V_80 ] ;
F_97 (sid, head, node)
if ( V_82 -> V_55 == V_55 )
return V_82 ;
return NULL ;
}
struct V_15 * F_98 ( struct V_1 * V_2 , T_2 V_55 )
{
struct V_81 * V_82 ;
if ( V_2 -> V_23 == 1 || ! V_55 )
return F_14 ( V_2 ) ;
V_82 = F_96 ( V_2 , V_55 ) ;
if ( V_82 )
return V_82 -> V_19 ;
if ( ! F_99 ( V_2 ) )
return F_14 ( V_2 ) ;
return NULL ;
}
struct V_15 * F_100 ( struct V_1 * V_2 ,
T_2 V_55 )
{
struct V_81 * V_82 ;
if ( ! V_55 )
return NULL ;
V_82 = F_96 ( V_2 , V_55 ) ;
if ( V_82 )
return V_82 -> V_19 ;
return NULL ;
}
static int F_101 ( struct V_1 * V_2 ,
union V_100 * V_101 , T_2 * V_55 )
{
const T_2 * V_102 = V_101 -> V_103 . V_102 ;
T_3 V_21 ;
V_21 = ( V_101 -> V_104 . V_50 - sizeof( V_101 -> V_104 ) ) >> 3 ;
if ( V_101 -> V_104 . type == V_105 ) {
if ( V_2 -> V_17 >= V_21 )
return - 1 ;
* V_55 = V_102 [ V_2 -> V_17 ] ;
} else {
if ( V_2 -> V_18 > V_21 )
return - 1 ;
V_21 -= V_2 -> V_18 ;
* V_55 = V_102 [ V_21 ] ;
}
return 0 ;
}
static struct V_15 * F_102 ( struct V_1 * V_2 ,
union V_100 * V_101 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
struct V_99 * V_53 ;
struct V_81 * V_82 ;
int V_80 ;
T_2 V_55 ;
if ( V_2 -> V_23 == 1 )
return V_16 ;
if ( ! V_16 -> V_39 . V_106 &&
V_101 -> V_104 . type != V_105 )
return V_16 ;
if ( F_101 ( V_2 , V_101 , & V_55 ) )
return NULL ;
if ( ! V_55 )
return V_16 ;
V_80 = F_88 ( V_55 , V_83 ) ;
V_53 = & V_2 -> V_9 [ V_80 ] ;
F_97 (sid, head, node) {
if ( V_82 -> V_55 == V_55 )
return V_82 -> V_19 ;
}
return NULL ;
}
static int F_103 ( struct V_1 * V_2 , bool V_107 )
{
int V_7 ;
for ( V_7 = 0 ; V_7 < V_2 -> V_108 ; V_7 ++ ) {
int V_41 = V_2 -> V_24 [ V_7 ] . V_41 ;
int V_63 ;
if ( V_41 < 0 )
continue;
V_63 = F_66 ( V_41 , V_109 , V_107 ? 1 : 0 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
int F_104 ( struct V_1 * V_2 )
{
return F_103 ( V_2 , true ) ;
}
int F_105 ( struct V_1 * V_2 )
{
return F_103 ( V_2 , false ) ;
}
static union V_100 *
F_106 ( struct V_110 * V_111 , bool V_112 , T_2 V_113 ,
T_2 V_114 , T_2 * V_35 )
{
unsigned char * V_115 = V_111 -> V_116 + V_117 ;
union V_100 * V_101 = NULL ;
int V_118 = V_114 - V_113 ;
if ( V_112 ) {
if ( V_118 > V_111 -> V_119 / 2 || V_118 < 0 ) {
fprintf ( V_120 , L_3 ) ;
V_113 = V_114 ;
V_118 = 0 ;
}
}
if ( V_118 >= ( int ) sizeof( V_101 -> V_104 ) ) {
T_1 V_50 ;
V_101 = (union V_100 * ) & V_115 [ V_113 & V_111 -> V_119 ] ;
V_50 = V_101 -> V_104 . V_50 ;
if ( V_50 < sizeof( V_101 -> V_104 ) || V_118 < ( int ) V_50 ) {
V_101 = NULL ;
goto V_121;
}
if ( ( V_113 & V_111 -> V_119 ) + V_50 != ( ( V_113 + V_50 ) & V_111 -> V_119 ) ) {
unsigned int V_122 = V_113 ;
unsigned int V_123 = F_107 ( sizeof( * V_101 ) , V_50 ) , V_124 ;
void * V_125 = V_111 -> V_126 ;
do {
V_124 = F_107 ( V_111 -> V_119 + 1 - ( V_122 & V_111 -> V_119 ) , V_123 ) ;
memcpy ( V_125 , & V_115 [ V_122 & V_111 -> V_119 ] , V_124 ) ;
V_122 += V_124 ;
V_125 += V_124 ;
V_123 -= V_124 ;
} while ( V_123 );
V_101 = (union V_100 * ) V_111 -> V_126 ;
}
V_113 += V_50 ;
}
V_121:
if ( V_35 )
* V_35 = V_113 ;
return V_101 ;
}
union V_100 * F_108 ( struct V_1 * V_2 , int V_28 )
{
struct V_110 * V_111 = & V_2 -> V_24 [ V_28 ] ;
T_2 V_53 ;
T_2 V_127 = V_111 -> V_35 ;
if ( ! F_109 ( & V_111 -> V_128 ) )
return NULL ;
V_53 = F_110 ( V_111 ) ;
return F_106 ( V_111 , V_2 -> V_129 , V_127 , V_53 , & V_111 -> V_35 ) ;
}
union V_100 *
F_111 ( struct V_1 * V_2 , int V_28 )
{
struct V_110 * V_111 = & V_2 -> V_24 [ V_28 ] ;
T_2 V_53 , V_114 ;
T_2 V_113 = V_111 -> V_35 ;
if ( ! F_109 ( & V_111 -> V_128 ) )
return NULL ;
V_53 = F_110 ( V_111 ) ;
if ( ! V_53 )
return NULL ;
if ( - V_53 < ( T_2 ) ( V_111 -> V_119 + 1 ) )
V_114 = 0 ;
else
V_114 = V_53 + V_111 -> V_119 + 1 ;
return F_106 ( V_111 , false , V_113 , V_114 , & V_111 -> V_35 ) ;
}
void F_112 ( struct V_1 * V_2 , int V_28 )
{
struct V_110 * V_111 = & V_2 -> V_24 [ V_28 ] ;
T_2 V_53 ;
if ( ! F_109 ( & V_111 -> V_128 ) )
return;
V_53 = F_110 ( V_111 ) ;
V_111 -> V_35 = V_53 ;
}
static bool F_113 ( struct V_110 * V_111 )
{
return F_110 ( V_111 ) == V_111 -> V_35 && ! V_111 -> V_130 . V_116 ;
}
static void F_114 ( struct V_1 * V_2 , int V_28 )
{
F_115 ( & V_2 -> V_24 [ V_28 ] . V_128 ) ;
}
static void F_81 ( struct V_1 * V_2 , int V_28 )
{
F_116 ( F_109 ( & V_2 -> V_24 [ V_28 ] . V_128 ) == 0 ) ;
if ( F_117 ( & V_2 -> V_24 [ V_28 ] . V_128 ) )
F_118 ( V_2 , V_28 ) ;
}
void F_119 ( struct V_1 * V_2 , int V_28 )
{
struct V_110 * V_111 = & V_2 -> V_24 [ V_28 ] ;
if ( ! V_2 -> V_129 ) {
T_2 V_127 = V_111 -> V_35 ;
F_120 ( V_111 , V_127 ) ;
}
if ( F_109 ( & V_111 -> V_128 ) == 1 && F_113 ( V_111 ) )
F_81 ( V_2 , V_28 ) ;
}
int __weak F_121 ( struct V_130 * T_4 V_131 ,
struct V_132 * T_5 V_131 ,
void * T_6 V_131 ,
int V_41 V_131 )
{
return 0 ;
}
void __weak F_122 ( struct V_130 * T_4 V_131 )
{
}
void __weak F_123 (
struct V_132 * T_5 V_131 ,
T_7 T_8 V_131 ,
unsigned int T_9 V_131 ,
bool T_10 V_131 )
{
}
void __weak F_124 (
struct V_132 * T_5 V_131 ,
struct V_1 * V_2 V_131 ,
int V_28 V_131 ,
bool T_11 V_131 )
{
}
static void F_118 ( struct V_1 * V_2 , int V_28 )
{
if ( V_2 -> V_24 [ V_28 ] . V_116 != NULL ) {
F_125 ( V_2 -> V_24 [ V_28 ] . V_116 , V_2 -> V_133 ) ;
V_2 -> V_24 [ V_28 ] . V_116 = NULL ;
V_2 -> V_24 [ V_28 ] . V_41 = - 1 ;
F_126 ( & V_2 -> V_24 [ V_28 ] . V_128 , 0 ) ;
}
F_122 ( & V_2 -> V_24 [ V_28 ] . V_130 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_24 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_108 ; V_7 ++ )
F_118 ( V_2 , V_7 ) ;
F_23 ( & V_2 -> V_24 ) ;
}
static int F_127 ( struct V_1 * V_2 )
{
int V_7 ;
V_2 -> V_108 = F_69 ( V_2 -> V_4 ) ;
if ( F_71 ( V_2 -> V_4 ) )
V_2 -> V_108 = F_58 ( V_2 -> V_6 ) ;
V_2 -> V_24 = F_7 ( V_2 -> V_108 * sizeof( struct V_110 ) ) ;
for ( V_7 = 0 ; V_7 < V_2 -> V_108 ; V_7 ++ )
V_2 -> V_24 [ V_7 ] . V_41 = - 1 ;
return V_2 -> V_24 != NULL ? 0 : - V_47 ;
}
static int F_128 ( struct V_1 * V_2 , int V_28 ,
struct V_134 * T_5 , int V_41 )
{
F_126 ( & V_2 -> V_24 [ V_28 ] . V_128 , 2 ) ;
V_2 -> V_24 [ V_28 ] . V_35 = 0 ;
V_2 -> V_24 [ V_28 ] . V_119 = T_5 -> V_119 ;
V_2 -> V_24 [ V_28 ] . V_116 = V_24 ( NULL , V_2 -> V_133 , T_5 -> V_135 ,
V_136 , V_41 , 0 ) ;
if ( V_2 -> V_24 [ V_28 ] . V_116 == V_137 ) {
F_129 ( L_4 ,
V_90 ) ;
V_2 -> V_24 [ V_28 ] . V_116 = NULL ;
return - 1 ;
}
V_2 -> V_24 [ V_28 ] . V_41 = V_41 ;
if ( F_121 ( & V_2 -> V_24 [ V_28 ] . V_130 ,
& T_5 -> V_138 , V_2 -> V_24 [ V_28 ] . V_116 , V_41 ) )
return - 1 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int V_28 ,
struct V_134 * T_5 , int V_61 ,
int V_62 , int * V_139 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel) {
int V_41 ;
if ( V_19 -> V_59 && V_62 )
continue;
V_41 = F_67 ( V_19 , V_61 , V_62 ) ;
if ( * V_139 == - 1 ) {
* V_139 = V_41 ;
if ( F_128 ( V_2 , V_28 , T_5 , * V_139 ) < 0 )
return - 1 ;
} else {
if ( F_66 ( V_41 , V_140 , * V_139 ) != 0 )
return - 1 ;
F_114 ( V_2 , V_28 ) ;
}
if ( ! V_19 -> V_59 &&
F_75 ( V_2 , V_41 , V_28 ) < 0 ) {
F_81 ( V_2 , V_28 ) ;
return - 1 ;
}
if ( V_19 -> V_39 . V_93 & V_94 ) {
if ( F_91 ( V_2 , V_19 , V_61 , V_62 ,
V_41 ) < 0 )
return - 1 ;
F_94 ( V_2 , V_19 , V_28 , V_61 ,
V_62 ) ;
}
}
return 0 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_134 * T_5 )
{
int V_61 , V_62 ;
int V_67 = F_69 ( V_2 -> V_4 ) ;
int V_64 = F_58 ( V_2 -> V_6 ) ;
F_129 ( L_5 ) ;
for ( V_61 = 0 ; V_61 < V_67 ; V_61 ++ ) {
int V_139 = - 1 ;
F_124 ( & T_5 -> V_138 , V_2 , V_61 ,
true ) ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ ) {
if ( F_130 ( V_2 , V_61 , T_5 , V_61 ,
V_62 , & V_139 ) )
goto V_141;
}
}
return 0 ;
V_141:
for ( V_61 = 0 ; V_61 < V_67 ; V_61 ++ )
F_118 ( V_2 , V_61 ) ;
return - 1 ;
}
static int F_132 ( struct V_1 * V_2 ,
struct V_134 * T_5 )
{
int V_62 ;
int V_64 = F_58 ( V_2 -> V_6 ) ;
F_129 ( L_6 ) ;
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ ) {
int V_139 = - 1 ;
F_124 ( & T_5 -> V_138 , V_2 , V_62 ,
false ) ;
if ( F_130 ( V_2 , V_62 , T_5 , 0 , V_62 ,
& V_139 ) )
goto V_141;
}
return 0 ;
V_141:
for ( V_62 = 0 ; V_62 < V_64 ; V_62 ++ )
F_118 ( V_2 , V_62 ) ;
return - 1 ;
}
unsigned long F_133 ( void )
{
unsigned long V_142 ;
int V_143 ;
if ( F_134 ( L_7 , & V_143 ) < 0 ) {
V_143 = 512 ;
} else {
V_143 -= ( V_117 / 1024 ) ;
}
V_142 = ( V_143 * 1024 ) / V_117 ;
if ( ! F_135 ( V_142 ) )
V_142 = F_136 ( V_142 ) ;
return V_142 ;
}
static T_1 F_137 ( unsigned long V_142 )
{
if ( V_142 == V_144 )
V_142 = F_133 () ;
else if ( ! F_135 ( V_142 ) )
return 0 ;
return ( V_142 + 1 ) * V_117 ;
}
static long F_138 ( const char * V_145 , unsigned long F_107 ,
unsigned long V_143 )
{
unsigned long V_142 , V_146 ;
static struct V_147 V_148 [] = {
{ . V_149 = 'B' , . V_150 = 1 } ,
{ . V_149 = 'K' , . V_150 = 1 << 10 } ,
{ . V_149 = 'M' , . V_150 = 1 << 20 } ,
{ . V_149 = 'G' , . V_150 = 1 << 30 } ,
{ . V_149 = 0 } ,
} ;
if ( V_145 == NULL )
return - V_65 ;
V_146 = F_139 ( V_145 , V_148 ) ;
if ( V_146 != ( unsigned long ) - 1 ) {
V_142 = F_140 ( V_146 , V_117 ) / V_117 ;
} else {
char * V_151 ;
V_142 = strtoul ( V_145 , & V_151 , 10 ) ;
if ( * V_151 != '\0' )
return - V_65 ;
}
if ( V_142 == 0 && F_107 == 0 ) {
} else if ( ! F_135 ( V_142 ) ) {
V_142 = F_141 ( V_142 ) ;
if ( ! V_142 )
return - V_65 ;
F_142 ( L_8 ,
V_142 * V_117 , V_142 ) ;
}
if ( V_142 > V_143 )
return - V_65 ;
return V_142 ;
}
int F_143 ( unsigned int * V_152 , const char * V_145 )
{
unsigned long V_143 = V_144 ;
long V_142 ;
if ( V_143 > V_153 / V_117 )
V_143 = V_153 / V_117 ;
V_142 = F_138 ( V_145 , 1 , V_143 ) ;
if ( V_142 < 0 ) {
F_144 ( L_9 ) ;
return - 1 ;
}
* V_152 = V_142 ;
return 0 ;
}
int F_145 ( const struct V_154 * V_155 , const char * V_145 ,
int T_12 V_131 )
{
return F_143 ( V_155 -> V_107 , V_145 ) ;
}
int F_146 ( struct V_1 * V_2 , unsigned int V_142 ,
bool V_129 , unsigned int T_9 ,
bool T_10 )
{
struct V_15 * V_19 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_134 T_5 = {
. V_135 = V_156 | ( V_129 ? 0 : V_157 ) ,
} ;
if ( V_2 -> V_24 == NULL && F_127 ( V_2 ) < 0 )
return - V_47 ;
if ( V_2 -> V_11 . V_10 == NULL && F_72 ( V_2 ) < 0 )
return - V_47 ;
V_2 -> V_129 = V_129 ;
V_2 -> V_133 = F_137 ( V_142 ) ;
F_147 ( L_10 , V_2 -> V_133 ) ;
T_5 . V_119 = V_2 -> V_133 - V_117 - 1 ;
F_123 ( & T_5 . V_138 , V_2 -> V_133 ,
T_9 , T_10 ) ;
F_16 (evlist, evsel) {
if ( ( V_19 -> V_39 . V_93 & V_94 ) &&
V_19 -> V_158 == NULL &&
F_148 ( V_19 , F_69 ( V_4 ) , V_6 -> V_159 ) < 0 )
return - V_47 ;
}
if ( F_71 ( V_4 ) )
return F_132 ( V_2 , & T_5 ) ;
return F_131 ( V_2 , & T_5 ) ;
}
int F_149 ( struct V_1 * V_2 , unsigned int V_142 ,
bool V_129 )
{
return F_146 ( V_2 , V_142 , V_129 , 0 , false ) ;
}
int F_150 ( struct V_1 * V_2 , struct V_160 * V_160 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_151 ( V_160 -> V_13 , V_160 -> V_98 , V_160 -> V_161 ) ;
if ( ! V_6 )
return - 1 ;
if ( F_152 ( V_160 ) )
V_4 = F_153 () ;
else
V_4 = F_154 ( V_160 -> V_162 ) ;
if ( ! V_4 )
goto V_163;
V_2 -> V_26 = ! ! V_160 -> V_162 ;
F_4 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_163:
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
void F_155 ( struct V_1 * V_2 ,
enum V_164 V_165 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel)
F_156 ( V_19 , V_165 ) ;
}
void F_157 ( struct V_1 * V_2 ,
enum V_164 V_165 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel)
F_158 ( V_19 , V_165 ) ;
}
int F_159 ( struct V_1 * V_2 , struct V_15 * * V_166 )
{
struct V_15 * V_19 ;
int V_63 = 0 ;
const int V_167 = F_69 ( V_2 -> V_4 ) ,
V_168 = F_58 ( V_2 -> V_6 ) ;
F_16 (evlist, evsel) {
if ( V_19 -> V_169 == NULL )
continue;
V_63 = F_160 ( V_19 , V_167 , V_168 , V_19 -> V_169 ) ;
if ( V_63 ) {
* V_166 = V_19 ;
break;
}
}
return V_63 ;
}
int F_161 ( struct V_1 * V_2 , const char * V_169 )
{
struct V_15 * V_19 ;
int V_63 = 0 ;
F_16 (evlist, evsel) {
if ( V_19 -> V_39 . type != V_56 )
continue;
V_63 = F_162 ( V_19 , V_169 ) ;
if ( V_63 )
break;
}
return V_63 ;
}
int F_163 ( struct V_1 * V_2 , T_1 V_170 , T_13 * V_171 )
{
char * V_169 ;
int V_87 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_170 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_47 ( & V_169 , L_11 , V_171 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_172 ;
if ( F_47 ( & V_172 , L_12 , V_169 , V_171 [ V_7 ] ) < 0 )
goto V_173;
free ( V_169 ) ;
V_169 = V_172 ;
}
}
V_87 = F_161 ( V_2 , V_169 ) ;
V_173:
free ( V_169 ) ;
return V_87 ;
}
int F_164 ( struct V_1 * V_2 , T_13 V_13 )
{
return F_163 ( V_2 , 1 , & V_13 ) ;
}
bool F_165 ( struct V_1 * V_2 )
{
struct V_15 * V_20 ;
if ( V_2 -> V_23 == 1 )
return true ;
if ( V_2 -> V_17 < 0 || V_2 -> V_18 < 0 )
return false ;
F_16 (evlist, pos) {
if ( V_20 -> V_17 != V_2 -> V_17 ||
V_20 -> V_18 != V_2 -> V_18 )
return false ;
}
return true ;
}
T_2 F_166 ( struct V_1 * V_2 )
{
struct V_15 * V_19 ;
if ( V_2 -> V_174 )
return V_2 -> V_174 ;
F_16 (evlist, evsel)
V_2 -> V_174 |= V_19 -> V_39 . V_175 ;
return V_2 -> V_174 ;
}
T_2 F_167 ( struct V_1 * V_2 )
{
V_2 -> V_174 = 0 ;
return F_166 ( V_2 ) ;
}
T_2 F_168 ( struct V_1 * V_2 )
{
struct V_15 * V_19 ;
T_2 V_176 = 0 ;
F_16 (evlist, evsel)
V_176 |= V_19 -> V_39 . V_177 ;
return V_176 ;
}
bool F_169 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) , * V_20 = V_16 ;
T_2 V_93 = V_16 -> V_39 . V_93 ;
T_2 V_175 = V_16 -> V_39 . V_175 ;
F_16 (evlist, pos) {
if ( V_93 != V_20 -> V_39 . V_93 )
return false ;
}
if ( ( V_175 & V_178 ) &&
! ( V_93 & V_94 ) ) {
return false ;
}
return true ;
}
T_2 F_92 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
return V_16 -> V_39 . V_93 ;
}
T_14 F_170 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
struct V_179 * V_115 ;
T_2 V_175 ;
T_14 V_50 = 0 ;
if ( ! V_16 -> V_39 . V_106 )
goto V_180;
V_175 = V_16 -> V_39 . V_175 ;
if ( V_175 & V_181 )
V_50 += sizeof( V_115 -> V_98 ) * 2 ;
if ( V_175 & V_182 )
V_50 += sizeof( V_115 -> time ) ;
if ( V_175 & V_183 )
V_50 += sizeof( V_115 -> V_55 ) ;
if ( V_175 & V_184 )
V_50 += sizeof( V_115 -> V_185 ) ;
if ( V_175 & V_186 )
V_50 += sizeof( V_115 -> V_61 ) * 2 ;
if ( V_175 & V_187 )
V_50 += sizeof( V_115 -> V_55 ) ;
V_180:
return V_50 ;
}
bool F_171 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) , * V_20 = V_16 ;
F_172 (evlist, pos) {
if ( V_16 -> V_39 . V_106 != V_20 -> V_39 . V_106 )
return false ;
}
return true ;
}
bool F_99 ( struct V_1 * V_2 )
{
struct V_15 * V_16 = F_14 ( V_2 ) ;
return V_16 -> V_39 . V_106 ;
}
void F_173 ( struct V_1 * V_2 ,
struct V_15 * V_19 )
{
V_2 -> V_188 = V_19 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_15 * V_19 ;
int V_167 = F_69 ( V_2 -> V_4 ) ;
int V_168 = F_58 ( V_2 -> V_6 ) ;
int V_21 ;
F_174 (evlist, evsel) {
V_21 = V_19 -> V_4 ? V_19 -> V_4 -> V_159 : V_167 ;
F_175 ( V_19 , V_21 , V_168 ) ;
}
}
static int F_176 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_63 = - V_47 ;
V_4 = F_154 ( NULL ) ;
if ( ! V_4 )
goto V_180;
V_6 = F_177 () ;
if ( ! V_6 )
goto V_189;
F_4 ( V_2 , V_4 , V_6 ) ;
V_180:
return V_63 ;
V_189:
F_27 ( V_4 ) ;
goto V_180;
}
int F_178 ( struct V_1 * V_2 )
{
struct V_15 * V_19 ;
int V_63 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_63 = F_176 ( V_2 ) ;
if ( V_63 < 0 )
goto V_190;
}
F_15 ( V_2 ) ;
F_16 (evlist, evsel) {
V_63 = F_179 ( V_19 , V_19 -> V_4 , V_19 -> V_6 ) ;
if ( V_63 < 0 )
goto V_190;
}
return 0 ;
V_190:
F_26 ( V_2 ) ;
V_90 = - V_63 ;
return V_63 ;
}
int F_180 ( struct V_1 * V_2 , struct V_160 * V_160 ,
const char * V_191 [] , bool V_192 ,
void (* F_181)( int V_193 , T_15 * V_194 , void * V_195 ) )
{
int V_196 [ 2 ] , V_197 [ 2 ] ;
char V_198 ;
if ( F_182 ( V_196 ) < 0 ) {
perror ( L_13 ) ;
return - 1 ;
}
if ( F_182 ( V_197 ) < 0 ) {
perror ( L_14 ) ;
goto V_199;
}
V_2 -> V_12 . V_13 = F_183 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_15 ) ;
goto V_200;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_87 ;
if ( V_192 )
F_184 ( 2 , 1 ) ;
signal ( V_201 , V_202 ) ;
F_44 ( V_196 [ 0 ] ) ;
F_44 ( V_197 [ 1 ] ) ;
F_77 ( V_197 [ 0 ] , V_203 , V_204 ) ;
F_44 ( V_196 [ 1 ] ) ;
V_87 = F_93 ( V_197 [ 0 ] , & V_198 , 1 ) ;
if ( V_87 != 1 ) {
if ( V_87 == - 1 )
perror ( L_16 ) ;
exit ( V_87 ) ;
}
F_185 ( V_191 [ 0 ] , ( char * * ) V_191 ) ;
if ( F_181 ) {
union V_205 V_146 ;
V_146 . V_206 = V_90 ;
if ( F_186 ( F_187 () , V_207 , V_146 ) )
perror ( V_191 [ 0 ] ) ;
} else
perror ( V_191 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_181 ) {
struct V_208 V_209 = {
. V_210 = V_211 ,
. V_212 = F_181 ,
} ;
V_208 ( V_207 , & V_209 , NULL ) ;
}
if ( F_188 ( V_160 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_120 , L_17 ,
V_213 , __LINE__ ) ;
goto V_200;
}
F_189 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_44 ( V_196 [ 1 ] ) ;
F_44 ( V_197 [ 0 ] ) ;
if ( F_93 ( V_196 [ 0 ] , & V_198 , 1 ) == - 1 ) {
perror ( L_16 ) ;
goto V_200;
}
F_77 ( V_197 [ 1 ] , V_203 , V_204 ) ;
V_2 -> V_12 . V_214 = V_197 [ 1 ] ;
F_44 ( V_196 [ 0 ] ) ;
return 0 ;
V_200:
F_44 ( V_197 [ 0 ] ) ;
F_44 ( V_197 [ 1 ] ) ;
V_199:
F_44 ( V_196 [ 0 ] ) ;
F_44 ( V_196 [ 1 ] ) ;
return - 1 ;
}
int F_190 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_214 > 0 ) {
char V_198 = 0 ;
int V_87 ;
V_87 = F_191 ( V_2 -> V_12 . V_214 , & V_198 , 1 ) ;
if ( V_87 < 0 )
perror ( L_18 ) ;
F_44 ( V_2 -> V_12 . V_214 ) ;
return V_87 ;
}
return 0 ;
}
int F_192 ( struct V_1 * V_2 , union V_100 * V_101 ,
struct V_179 * V_103 )
{
struct V_15 * V_19 = F_102 ( V_2 , V_101 ) ;
if ( ! V_19 )
return - V_215 ;
return F_193 ( V_19 , V_101 , V_103 ) ;
}
T_1 F_194 ( struct V_1 * V_2 , T_16 * V_216 )
{
struct V_15 * V_19 ;
T_1 V_217 = 0 ;
F_16 (evlist, evsel) {
V_217 += fprintf ( V_216 , L_19 , V_19 -> V_28 ? L_20 : L_21 ,
F_195 ( V_19 ) ) ;
}
return V_217 + fprintf ( V_216 , L_22 ) ;
}
int F_196 ( struct V_1 * V_2 ,
int V_63 , char * V_218 , T_1 V_50 )
{
int V_217 , V_107 ;
char V_219 [ V_220 ] , * V_221 = F_197 ( V_63 , V_219 , sizeof( V_219 ) ) ;
switch ( V_63 ) {
case V_222 :
case V_223 :
V_217 = F_198 ( V_218 , V_50 ,
L_23
L_24 , V_221 ) ;
V_107 = F_199 () ;
V_217 += F_198 ( V_218 + V_217 , V_50 - V_217 , L_25 ) ;
if ( V_107 >= 2 ) {
V_217 += F_198 ( V_218 + V_217 , V_50 - V_217 ,
L_26 ) ;
}
V_217 += F_198 ( V_218 + V_217 , V_50 - V_217 ,
L_27 ) ;
V_217 += F_198 ( V_218 + V_217 , V_50 - V_217 ,
L_28
L_29 , V_107 ) ;
break;
case V_65 : {
struct V_15 * V_16 = F_14 ( V_2 ) ;
int V_224 ;
if ( F_134 ( L_30 , & V_224 ) < 0 )
goto V_225;
if ( V_16 -> V_39 . V_226 < ( T_2 ) V_224 )
goto V_225;
V_217 = F_198 ( V_218 , V_50 ,
L_23
L_31
L_32 V_227 L_33 ,
V_221 , V_224 , V_16 -> V_39 . V_226 ) ;
break;
}
default:
V_225:
F_198 ( V_218 , V_50 , L_34 , V_221 ) ;
break;
}
return 0 ;
}
int F_200 ( struct V_1 * V_2 , int V_63 , char * V_218 , T_1 V_50 )
{
char V_219 [ V_220 ] , * V_221 = F_197 ( V_63 , V_219 , sizeof( V_219 ) ) ;
int V_228 = V_2 -> V_133 / 1024 , V_229 , V_217 = 0 ;
switch ( V_63 ) {
case V_223 :
F_134 ( L_7 , & V_229 ) ;
V_217 += F_198 ( V_218 + V_217 , V_50 - V_217 ,
L_23
L_35
L_36 ,
V_221 , V_229 , V_228 ) ;
if ( V_228 >= V_229 ) {
V_217 += F_198 ( V_218 + V_217 , V_50 - V_217 ,
L_37 ,
V_229 + V_228 ) ;
}
V_217 += F_198 ( V_218 + V_217 , V_50 - V_217 ,
L_38 ) ;
break;
default:
F_198 ( V_218 , V_50 , L_34 , V_221 ) ;
break;
}
return 0 ;
}
void F_201 ( struct V_1 * V_2 ,
struct V_15 * V_230 )
{
struct V_15 * V_19 , * V_21 ;
F_49 ( V_231 ) ;
if ( V_230 == F_14 ( V_2 ) )
return;
F_19 (evlist, n, evsel) {
if ( V_19 -> V_33 == V_230 -> V_33 )
F_202 ( & V_19 -> V_22 , & V_231 ) ;
}
F_203 ( & V_231 , & V_2 -> V_10 ) ;
}
void F_204 ( struct V_1 * V_2 ,
struct V_15 * V_232 )
{
struct V_15 * V_19 ;
if ( V_232 -> V_29 )
return;
F_16 (evlist, evsel) {
if ( V_19 != V_232 )
V_19 -> V_29 = false ;
}
V_232 -> V_29 = true ;
}
struct V_15 *
F_205 ( struct V_1 * V_2 ,
const char * V_145 )
{
struct V_15 * V_19 ;
F_16 (evlist, evsel) {
if ( ! V_19 -> V_45 )
continue;
if ( strcmp ( V_145 , V_19 -> V_45 ) == 0 )
return V_19 ;
}
return NULL ;
}
