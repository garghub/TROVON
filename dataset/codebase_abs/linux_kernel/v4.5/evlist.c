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
struct V_14 * V_15 = F_14 ( V_2 ) ;
V_2 -> V_16 = V_15 -> V_16 ;
V_2 -> V_17 = V_15 -> V_17 ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
F_16 (evlist, evsel)
F_17 ( V_18 ) ;
F_13 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_14 * V_19 , * V_20 ;
F_19 (evlist, n, pos) {
F_20 ( & V_19 -> V_21 ) ;
V_19 -> V_2 = NULL ;
F_21 ( V_19 ) ;
}
V_2 -> V_22 = 0 ;
}
void F_22 ( struct V_1 * V_2 )
{
F_23 ( & V_2 -> V_23 ) ;
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
struct V_14 * V_18 )
{
if ( ! V_18 -> V_24 || V_2 -> V_25 ) {
F_27 ( V_18 -> V_4 ) ;
V_18 -> V_4 = F_30 ( V_2 -> V_4 ) ;
} else if ( V_18 -> V_4 != V_18 -> V_24 ) {
F_27 ( V_18 -> V_4 ) ;
V_18 -> V_4 = F_30 ( V_18 -> V_24 ) ;
}
F_28 ( V_18 -> V_6 ) ;
V_18 -> V_6 = F_31 ( V_2 -> V_6 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
F_16 (evlist, evsel)
F_29 ( V_2 , V_18 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_14 * V_26 )
{
V_26 -> V_2 = V_2 ;
F_34 ( & V_26 -> V_21 , & V_2 -> V_10 ) ;
V_26 -> V_27 = V_2 -> V_22 ;
V_26 -> V_28 = ! V_26 -> V_27 ;
if ( ! V_2 -> V_22 ++ )
F_13 ( V_2 ) ;
F_29 ( V_2 , V_26 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_14 * V_18 )
{
V_18 -> V_2 = NULL ;
F_20 ( & V_18 -> V_21 ) ;
V_2 -> V_22 -= 1 ;
}
void F_36 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_14 * V_18 , * V_31 ;
F_37 (list, temp, evsel) {
F_20 ( & V_18 -> V_21 ) ;
F_33 ( V_2 , V_18 ) ;
}
}
void F_38 ( struct V_29 * V_30 )
{
struct V_14 * V_18 , * V_32 ;
V_32 = F_39 ( V_30 -> V_33 , struct V_14 , V_21 ) ;
V_18 = F_39 ( V_30 -> V_34 , struct V_14 , V_21 ) ;
V_32 -> V_35 = V_18 -> V_27 - V_32 -> V_27 + 1 ;
F_40 (list, evsel) {
V_18 -> V_32 = V_32 ;
}
}
void F_41 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
V_2 -> V_36 = V_2 -> V_22 > 1 ? 1 : 0 ;
F_38 ( & V_2 -> V_10 ) ;
}
}
void F_42 ( struct V_37 * V_38 )
{
V_38 -> V_39 = 3 ;
while ( V_38 -> V_39 != 0 ) {
int V_40 = F_43 ( V_38 , 0 , - 1 , - 1 , 0 ) ;
if ( V_40 != - 1 ) {
F_44 ( V_40 ) ;
break;
}
-- V_38 -> V_39 ;
}
}
int F_9 ( struct V_1 * V_2 )
{
struct V_37 V_38 = {
. type = V_41 ,
. V_42 = V_43 ,
} ;
struct V_14 * V_18 ;
F_45 ( & V_38 ) ;
F_42 ( & V_38 ) ;
V_18 = F_46 ( & V_38 ) ;
if ( V_18 == NULL )
goto error;
if ( F_47 ( & V_18 -> V_44 , L_1 ,
V_38 . V_39 ? V_38 . V_39 + 1 : 0 , L_2 ) < 0 )
goto V_45;
F_33 ( V_2 , V_18 ) ;
return 0 ;
V_45:
F_21 ( V_18 ) ;
error:
return - V_46 ;
}
int F_12 ( struct V_1 * V_2 )
{
struct V_37 V_38 = {
. type = V_47 ,
. V_42 = V_48 ,
. V_49 = sizeof( V_38 ) ,
} ;
struct V_14 * V_18 = F_46 ( & V_38 ) ;
if ( V_18 == NULL )
return - V_46 ;
F_33 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_37 * V_50 , T_1 V_51 )
{
struct V_14 * V_18 , * V_20 ;
F_49 ( V_52 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ ) {
V_18 = F_50 ( V_50 + V_7 , V_2 -> V_22 + V_7 ) ;
if ( V_18 == NULL )
goto V_53;
F_34 ( & V_18 -> V_21 , & V_52 ) ;
}
F_36 ( V_2 , & V_52 ) ;
return 0 ;
V_53:
F_37 (&head, n, evsel)
F_21 ( V_18 ) ;
return - 1 ;
}
int F_51 ( struct V_1 * V_2 ,
struct V_37 * V_50 , T_1 V_51 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_51 ; V_7 ++ )
F_45 ( V_50 + V_7 ) ;
return F_48 ( V_2 , V_50 , V_51 ) ;
}
struct V_14 *
F_52 ( struct V_1 * V_2 , int V_54 )
{
struct V_14 * V_18 ;
F_16 (evlist, evsel) {
if ( V_18 -> V_38 . type == V_55 &&
( int ) V_18 -> V_38 . V_42 == V_54 )
return V_18 ;
}
return NULL ;
}
struct V_14 *
F_53 ( struct V_1 * V_2 ,
const char * V_44 )
{
struct V_14 * V_18 ;
F_16 (evlist, evsel) {
if ( ( V_18 -> V_38 . type == V_55 ) &&
( strcmp ( V_18 -> V_44 , V_44 ) == 0 ) )
return V_18 ;
}
return NULL ;
}
int F_54 ( struct V_1 * V_2 ,
const char * V_56 , const char * V_44 , void * V_57 )
{
struct V_14 * V_18 = F_55 ( V_56 , V_44 ) ;
if ( F_56 ( V_18 ) )
return - 1 ;
V_18 -> V_57 = V_57 ;
F_33 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
if ( V_18 -> V_58 )
return 1 ;
else
return F_58 ( V_2 -> V_6 ) ;
}
void F_59 ( struct V_1 * V_2 )
{
struct V_14 * V_19 ;
F_16 (evlist, pos) {
if ( ! F_60 ( V_19 ) || ! V_19 -> V_40 )
continue;
F_61 ( V_19 ) ;
}
V_2 -> V_59 = false ;
}
void F_62 ( struct V_1 * V_2 )
{
struct V_14 * V_19 ;
F_16 (evlist, pos) {
if ( ! F_60 ( V_19 ) || ! V_19 -> V_40 )
continue;
F_63 ( V_19 ) ;
}
V_2 -> V_59 = true ;
}
void F_64 ( struct V_1 * V_2 )
{
( V_2 -> V_59 ? F_59 : F_62 ) ( V_2 ) ;
}
static int F_65 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_60 )
{
int V_61 , V_62 ;
int V_63 = F_57 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_40 )
return - V_64 ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
V_62 = F_66 ( F_67 ( V_18 , V_60 , V_61 ) ,
V_65 , 0 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_61 )
{
int V_60 , V_62 ;
int V_66 = F_69 ( V_2 -> V_4 ) ;
if ( ! V_18 -> V_40 )
return - V_64 ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
V_62 = F_66 ( F_67 ( V_18 , V_60 , V_61 ) , V_65 , 0 ) ;
if ( V_62 )
return V_62 ;
}
return 0 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_27 )
{
bool V_67 = ! F_71 ( V_2 -> V_4 ) ;
if ( V_67 )
return F_65 ( V_2 , V_18 , V_27 ) ;
else
return F_68 ( V_2 , V_18 , V_27 ) ;
}
int F_72 ( struct V_1 * V_2 )
{
int V_66 = F_69 ( V_2 -> V_4 ) ;
int V_63 = F_58 ( V_2 -> V_6 ) ;
int V_68 = 0 ;
struct V_14 * V_18 ;
F_16 (evlist, evsel) {
if ( V_18 -> V_58 )
V_68 += V_66 ;
else
V_68 += V_66 * V_63 ;
}
if ( F_73 ( & V_2 -> V_11 ) < V_68 &&
F_74 ( & V_2 -> V_11 , V_68 ) < 0 )
return - V_46 ;
return 0 ;
}
static int F_75 ( struct V_1 * V_2 , int V_40 , int V_27 )
{
int V_19 = F_76 ( & V_2 -> V_11 , V_40 , V_69 | V_70 | V_71 ) ;
if ( V_19 >= 0 ) {
V_2 -> V_11 . V_72 [ V_19 ] . V_27 = V_27 ;
F_77 ( V_40 , V_73 , V_74 ) ;
}
return V_19 ;
}
int F_78 ( struct V_1 * V_2 , int V_40 )
{
return F_75 ( V_2 , V_40 , - 1 ) ;
}
static void F_79 ( struct V_75 * V_76 , int V_40 )
{
struct V_1 * V_2 = F_80 ( V_76 , struct V_1 , V_11 ) ;
F_81 ( V_2 , V_76 -> V_72 [ V_40 ] . V_27 ) ;
}
int F_82 ( struct V_1 * V_2 , short V_77 )
{
return F_83 ( & V_2 -> V_11 , V_77 ,
F_79 ) ;
}
int F_84 ( struct V_1 * V_2 , int V_78 )
{
return F_85 ( & V_2 -> V_11 , V_78 ) ;
}
static void F_86 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_60 , int V_61 , T_2 V_54 )
{
int V_79 ;
struct V_80 * V_81 = F_87 ( V_18 , V_60 , V_61 ) ;
V_81 -> V_54 = V_54 ;
V_81 -> V_18 = V_18 ;
V_79 = F_88 ( V_81 -> V_54 , V_82 ) ;
F_89 ( & V_81 -> V_21 , & V_2 -> V_9 [ V_79 ] ) ;
}
void F_90 ( struct V_1 * V_2 , struct V_14 * V_18 ,
int V_60 , int V_61 , T_2 V_54 )
{
F_86 ( V_2 , V_18 , V_60 , V_61 , V_54 ) ;
V_18 -> V_54 [ V_18 -> V_83 ++ ] = V_54 ;
}
int F_91 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_60 , int V_61 , int V_40 )
{
T_2 V_84 [ 4 ] = { 0 , } ;
int V_85 = 1 ;
T_2 V_54 ;
int V_86 ;
V_86 = F_66 ( V_40 , V_87 , & V_54 ) ;
if ( ! V_86 )
goto V_88;
if ( V_89 != V_90 )
return - 1 ;
if ( F_92 ( V_2 ) & V_91 )
return - 1 ;
if ( ! ( V_18 -> V_38 . V_92 & V_93 ) ||
F_93 ( V_40 , & V_84 , sizeof( V_84 ) ) == - 1 )
return - 1 ;
if ( V_18 -> V_38 . V_92 & V_94 )
++ V_85 ;
if ( V_18 -> V_38 . V_92 & V_95 )
++ V_85 ;
V_54 = V_84 [ V_85 ] ;
V_88:
F_90 ( V_2 , V_18 , V_60 , V_61 , V_54 ) ;
return 0 ;
}
static void F_94 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_27 , int V_60 ,
int V_61 )
{
struct V_80 * V_81 = F_87 ( V_18 , V_60 , V_61 ) ;
V_81 -> V_27 = V_27 ;
if ( V_2 -> V_4 && V_60 >= 0 )
V_81 -> V_60 = V_2 -> V_4 -> V_96 [ V_60 ] ;
else
V_81 -> V_60 = - 1 ;
if ( ! V_18 -> V_58 && V_2 -> V_6 && V_61 >= 0 )
V_81 -> V_97 = F_95 ( V_2 -> V_6 , V_61 ) ;
else
V_81 -> V_97 = - 1 ;
}
struct V_80 * F_96 ( struct V_1 * V_2 , T_2 V_54 )
{
struct V_98 * V_52 ;
struct V_80 * V_81 ;
int V_79 ;
V_79 = F_88 ( V_54 , V_82 ) ;
V_52 = & V_2 -> V_9 [ V_79 ] ;
F_97 (sid, head, node)
if ( V_81 -> V_54 == V_54 )
return V_81 ;
return NULL ;
}
struct V_14 * F_98 ( struct V_1 * V_2 , T_2 V_54 )
{
struct V_80 * V_81 ;
if ( V_2 -> V_22 == 1 || ! V_54 )
return F_14 ( V_2 ) ;
V_81 = F_96 ( V_2 , V_54 ) ;
if ( V_81 )
return V_81 -> V_18 ;
if ( ! F_99 ( V_2 ) )
return F_14 ( V_2 ) ;
return NULL ;
}
struct V_14 * F_100 ( struct V_1 * V_2 ,
T_2 V_54 )
{
struct V_80 * V_81 ;
if ( ! V_54 )
return NULL ;
V_81 = F_96 ( V_2 , V_54 ) ;
if ( V_81 )
return V_81 -> V_18 ;
return NULL ;
}
static int F_101 ( struct V_1 * V_2 ,
union V_99 * V_100 , T_2 * V_54 )
{
const T_2 * V_101 = V_100 -> V_102 . V_101 ;
T_3 V_20 ;
V_20 = ( V_100 -> V_103 . V_49 - sizeof( V_100 -> V_103 ) ) >> 3 ;
if ( V_100 -> V_103 . type == V_104 ) {
if ( V_2 -> V_16 >= V_20 )
return - 1 ;
* V_54 = V_101 [ V_2 -> V_16 ] ;
} else {
if ( V_2 -> V_17 > V_20 )
return - 1 ;
V_20 -= V_2 -> V_17 ;
* V_54 = V_101 [ V_20 ] ;
}
return 0 ;
}
static struct V_14 * F_102 ( struct V_1 * V_2 ,
union V_99 * V_100 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
struct V_98 * V_52 ;
struct V_80 * V_81 ;
int V_79 ;
T_2 V_54 ;
if ( V_2 -> V_22 == 1 )
return V_15 ;
if ( ! V_15 -> V_38 . V_105 &&
V_100 -> V_103 . type != V_104 )
return V_15 ;
if ( F_101 ( V_2 , V_100 , & V_54 ) )
return NULL ;
if ( ! V_54 )
return V_15 ;
V_79 = F_88 ( V_54 , V_82 ) ;
V_52 = & V_2 -> V_9 [ V_79 ] ;
F_97 (sid, head, node) {
if ( V_81 -> V_54 == V_54 )
return V_81 -> V_18 ;
}
return NULL ;
}
union V_99 * F_103 ( struct V_1 * V_2 , int V_27 )
{
struct V_106 * V_107 = & V_2 -> V_23 [ V_27 ] ;
T_2 V_52 ;
T_2 V_108 = V_107 -> V_34 ;
unsigned char * V_109 = V_107 -> V_110 + V_111 ;
union V_99 * V_100 = NULL ;
if ( ! F_104 ( & V_107 -> V_112 ) )
return NULL ;
V_52 = F_105 ( V_107 ) ;
if ( V_2 -> V_113 ) {
int V_114 = V_52 - V_108 ;
if ( V_114 > V_107 -> V_115 / 2 || V_114 < 0 ) {
fprintf ( V_116 , L_3 ) ;
V_108 = V_52 ;
}
}
if ( V_108 != V_52 ) {
T_1 V_49 ;
V_100 = (union V_99 * ) & V_109 [ V_108 & V_107 -> V_115 ] ;
V_49 = V_100 -> V_103 . V_49 ;
if ( ( V_108 & V_107 -> V_115 ) + V_49 != ( ( V_108 + V_49 ) & V_107 -> V_115 ) ) {
unsigned int V_117 = V_108 ;
unsigned int V_118 = F_106 ( sizeof( * V_100 ) , V_49 ) , V_119 ;
void * V_120 = V_107 -> V_121 ;
do {
V_119 = F_106 ( V_107 -> V_115 + 1 - ( V_117 & V_107 -> V_115 ) , V_118 ) ;
memcpy ( V_120 , & V_109 [ V_117 & V_107 -> V_115 ] , V_119 ) ;
V_117 += V_119 ;
V_120 += V_119 ;
V_118 -= V_119 ;
} while ( V_118 );
V_100 = (union V_99 * ) V_107 -> V_121 ;
}
V_108 += V_49 ;
}
V_107 -> V_34 = V_108 ;
return V_100 ;
}
static bool F_107 ( struct V_106 * V_107 )
{
return F_105 ( V_107 ) == V_107 -> V_34 && ! V_107 -> V_122 . V_110 ;
}
static void F_108 ( struct V_1 * V_2 , int V_27 )
{
F_109 ( & V_2 -> V_23 [ V_27 ] . V_112 ) ;
}
static void F_81 ( struct V_1 * V_2 , int V_27 )
{
F_110 ( F_104 ( & V_2 -> V_23 [ V_27 ] . V_112 ) == 0 ) ;
if ( F_111 ( & V_2 -> V_23 [ V_27 ] . V_112 ) )
F_112 ( V_2 , V_27 ) ;
}
void F_113 ( struct V_1 * V_2 , int V_27 )
{
struct V_106 * V_107 = & V_2 -> V_23 [ V_27 ] ;
if ( ! V_2 -> V_113 ) {
T_2 V_108 = V_107 -> V_34 ;
F_114 ( V_107 , V_108 ) ;
}
if ( F_104 ( & V_107 -> V_112 ) == 1 && F_107 ( V_107 ) )
F_81 ( V_2 , V_27 ) ;
}
int __weak F_115 ( struct V_122 * T_4 V_123 ,
struct V_124 * T_5 V_123 ,
void * T_6 V_123 ,
int V_40 V_123 )
{
return 0 ;
}
void __weak F_116 ( struct V_122 * T_4 V_123 )
{
}
void __weak F_117 (
struct V_124 * T_5 V_123 ,
T_7 T_8 V_123 ,
unsigned int T_9 V_123 ,
bool T_10 V_123 )
{
}
void __weak F_118 (
struct V_124 * T_5 V_123 ,
struct V_1 * V_2 V_123 ,
int V_27 V_123 ,
bool T_11 V_123 )
{
}
static void F_112 ( struct V_1 * V_2 , int V_27 )
{
if ( V_2 -> V_23 [ V_27 ] . V_110 != NULL ) {
F_119 ( V_2 -> V_23 [ V_27 ] . V_110 , V_2 -> V_125 ) ;
V_2 -> V_23 [ V_27 ] . V_110 = NULL ;
F_120 ( & V_2 -> V_23 [ V_27 ] . V_112 , 0 ) ;
}
F_116 ( & V_2 -> V_23 [ V_27 ] . V_122 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_23 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_126 ; V_7 ++ )
F_112 ( V_2 , V_7 ) ;
F_23 ( & V_2 -> V_23 ) ;
}
static int F_121 ( struct V_1 * V_2 )
{
V_2 -> V_126 = F_69 ( V_2 -> V_4 ) ;
if ( F_71 ( V_2 -> V_4 ) )
V_2 -> V_126 = F_58 ( V_2 -> V_6 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_126 * sizeof( struct V_106 ) ) ;
return V_2 -> V_23 != NULL ? 0 : - V_46 ;
}
static int F_122 ( struct V_1 * V_2 , int V_27 ,
struct V_127 * T_5 , int V_40 )
{
F_120 ( & V_2 -> V_23 [ V_27 ] . V_112 , 2 ) ;
V_2 -> V_23 [ V_27 ] . V_34 = 0 ;
V_2 -> V_23 [ V_27 ] . V_115 = T_5 -> V_115 ;
V_2 -> V_23 [ V_27 ] . V_110 = V_23 ( NULL , V_2 -> V_125 , T_5 -> V_128 ,
V_129 , V_40 , 0 ) ;
if ( V_2 -> V_23 [ V_27 ] . V_110 == V_130 ) {
F_123 ( L_4 ,
V_89 ) ;
V_2 -> V_23 [ V_27 ] . V_110 = NULL ;
return - 1 ;
}
if ( F_115 ( & V_2 -> V_23 [ V_27 ] . V_122 ,
& T_5 -> V_131 , V_2 -> V_23 [ V_27 ] . V_110 , V_40 ) )
return - 1 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , int V_27 ,
struct V_127 * T_5 , int V_60 ,
int V_61 , int * V_132 )
{
struct V_14 * V_18 ;
F_16 (evlist, evsel) {
int V_40 ;
if ( V_18 -> V_58 && V_61 )
continue;
V_40 = F_67 ( V_18 , V_60 , V_61 ) ;
if ( * V_132 == - 1 ) {
* V_132 = V_40 ;
if ( F_122 ( V_2 , V_27 , T_5 , * V_132 ) < 0 )
return - 1 ;
} else {
if ( F_66 ( V_40 , V_133 , * V_132 ) != 0 )
return - 1 ;
F_108 ( V_2 , V_27 ) ;
}
if ( ! V_18 -> V_58 &&
F_75 ( V_2 , V_40 , V_27 ) < 0 ) {
F_81 ( V_2 , V_27 ) ;
return - 1 ;
}
if ( V_18 -> V_38 . V_92 & V_93 ) {
if ( F_91 ( V_2 , V_18 , V_60 , V_61 ,
V_40 ) < 0 )
return - 1 ;
F_94 ( V_2 , V_18 , V_27 , V_60 ,
V_61 ) ;
}
}
return 0 ;
}
static int F_125 ( struct V_1 * V_2 ,
struct V_127 * T_5 )
{
int V_60 , V_61 ;
int V_66 = F_69 ( V_2 -> V_4 ) ;
int V_63 = F_58 ( V_2 -> V_6 ) ;
F_123 ( L_5 ) ;
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ ) {
int V_132 = - 1 ;
F_118 ( & T_5 -> V_131 , V_2 , V_60 ,
true ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
if ( F_124 ( V_2 , V_60 , T_5 , V_60 ,
V_61 , & V_132 ) )
goto V_134;
}
}
return 0 ;
V_134:
for ( V_60 = 0 ; V_60 < V_66 ; V_60 ++ )
F_112 ( V_2 , V_60 ) ;
return - 1 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_127 * T_5 )
{
int V_61 ;
int V_63 = F_58 ( V_2 -> V_6 ) ;
F_123 ( L_6 ) ;
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ ) {
int V_132 = - 1 ;
F_118 ( & T_5 -> V_131 , V_2 , V_61 ,
false ) ;
if ( F_124 ( V_2 , V_61 , T_5 , 0 , V_61 ,
& V_132 ) )
goto V_134;
}
return 0 ;
V_134:
for ( V_61 = 0 ; V_61 < V_63 ; V_61 ++ )
F_112 ( V_2 , V_61 ) ;
return - 1 ;
}
static T_1 F_127 ( unsigned long V_135 )
{
if ( V_135 == V_136 ) {
int V_137 ;
if ( F_128 ( L_7 , & V_137 ) < 0 ) {
V_137 = 512 ;
} else {
V_137 -= ( V_111 / 1024 ) ;
}
V_135 = ( V_137 * 1024 ) / V_111 ;
if ( ! F_129 ( V_135 ) )
V_135 = F_130 ( V_135 ) ;
} else if ( ! F_129 ( V_135 ) )
return 0 ;
return ( V_135 + 1 ) * V_111 ;
}
static long F_131 ( const char * V_138 , unsigned long F_106 ,
unsigned long V_137 )
{
unsigned long V_135 , V_139 ;
static struct V_140 V_141 [] = {
{ . V_142 = 'B' , . V_143 = 1 } ,
{ . V_142 = 'K' , . V_143 = 1 << 10 } ,
{ . V_142 = 'M' , . V_143 = 1 << 20 } ,
{ . V_142 = 'G' , . V_143 = 1 << 30 } ,
{ . V_142 = 0 } ,
} ;
if ( V_138 == NULL )
return - V_64 ;
V_139 = F_132 ( V_138 , V_141 ) ;
if ( V_139 != ( unsigned long ) - 1 ) {
V_135 = F_133 ( V_139 , V_111 ) / V_111 ;
} else {
char * V_144 ;
V_135 = strtoul ( V_138 , & V_144 , 10 ) ;
if ( * V_144 != '\0' )
return - V_64 ;
}
if ( V_135 == 0 && F_106 == 0 ) {
} else if ( ! F_129 ( V_135 ) ) {
V_135 = F_134 ( V_135 ) ;
if ( ! V_135 )
return - V_64 ;
F_135 ( L_8 ,
V_135 * V_111 , V_135 ) ;
}
if ( V_135 > V_137 )
return - V_64 ;
return V_135 ;
}
int F_136 ( unsigned int * V_145 , const char * V_138 )
{
unsigned long V_137 = V_136 ;
long V_135 ;
if ( V_137 > V_146 / V_111 )
V_137 = V_146 / V_111 ;
V_135 = F_131 ( V_138 , 1 , V_137 ) ;
if ( V_135 < 0 ) {
F_137 ( L_9 ) ;
return - 1 ;
}
* V_145 = V_135 ;
return 0 ;
}
int F_138 ( const struct V_147 * V_148 , const char * V_138 ,
int T_12 V_123 )
{
return F_136 ( V_148 -> V_149 , V_138 ) ;
}
int F_139 ( struct V_1 * V_2 , unsigned int V_135 ,
bool V_113 , unsigned int T_9 ,
bool T_10 )
{
struct V_14 * V_18 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_127 T_5 = {
. V_128 = V_150 | ( V_113 ? 0 : V_151 ) ,
} ;
if ( V_2 -> V_23 == NULL && F_121 ( V_2 ) < 0 )
return - V_46 ;
if ( V_2 -> V_11 . V_10 == NULL && F_72 ( V_2 ) < 0 )
return - V_46 ;
V_2 -> V_113 = V_113 ;
V_2 -> V_125 = F_127 ( V_135 ) ;
F_140 ( L_10 , V_2 -> V_125 ) ;
T_5 . V_115 = V_2 -> V_125 - V_111 - 1 ;
F_117 ( & T_5 . V_131 , V_2 -> V_125 ,
T_9 , T_10 ) ;
F_16 (evlist, evsel) {
if ( ( V_18 -> V_38 . V_92 & V_93 ) &&
V_18 -> V_152 == NULL &&
F_141 ( V_18 , F_69 ( V_4 ) , V_6 -> V_153 ) < 0 )
return - V_46 ;
}
if ( F_71 ( V_4 ) )
return F_126 ( V_2 , & T_5 ) ;
return F_125 ( V_2 , & T_5 ) ;
}
int F_142 ( struct V_1 * V_2 , unsigned int V_135 ,
bool V_113 )
{
return F_139 ( V_2 , V_135 , V_113 , 0 , false ) ;
}
int F_143 ( struct V_1 * V_2 , struct V_154 * V_154 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_144 ( V_154 -> V_13 , V_154 -> V_97 , V_154 -> V_155 ) ;
if ( ! V_6 )
return - 1 ;
if ( F_145 ( V_154 ) )
V_4 = F_146 () ;
else
V_4 = F_147 ( V_154 -> V_156 ) ;
if ( ! V_4 )
goto V_157;
V_2 -> V_25 = ! ! V_154 -> V_156 ;
F_4 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_157:
F_28 ( V_6 ) ;
return - 1 ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 != V_2 -> V_4 ) {
F_27 ( V_2 -> V_4 ) ;
V_2 -> V_4 = V_4 ;
}
if ( V_6 != V_2 -> V_6 ) {
F_28 ( V_2 -> V_6 ) ;
V_2 -> V_6 = V_6 ;
}
F_32 ( V_2 ) ;
}
int F_148 ( struct V_1 * V_2 , struct V_14 * * V_158 )
{
struct V_14 * V_18 ;
int V_62 = 0 ;
const int V_159 = F_69 ( V_2 -> V_4 ) ,
V_160 = F_58 ( V_2 -> V_6 ) ;
F_16 (evlist, evsel) {
if ( V_18 -> V_161 == NULL )
continue;
V_62 = F_149 ( V_18 , V_159 , V_160 , V_18 -> V_161 ) ;
if ( V_62 ) {
* V_158 = V_18 ;
break;
}
}
return V_62 ;
}
int F_150 ( struct V_1 * V_2 , const char * V_161 )
{
struct V_14 * V_18 ;
int V_62 = 0 ;
F_16 (evlist, evsel) {
V_62 = F_151 ( V_18 , V_161 ) ;
if ( V_62 )
break;
}
return V_62 ;
}
int F_152 ( struct V_1 * V_2 , T_1 V_162 , T_13 * V_163 )
{
char * V_161 ;
int V_86 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_162 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_47 ( & V_161 , L_11 , V_163 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_164 ;
if ( F_47 ( & V_164 , L_12 , V_161 , V_163 [ V_7 ] ) < 0 )
goto V_165;
free ( V_161 ) ;
V_161 = V_164 ;
}
}
V_86 = F_150 ( V_2 , V_161 ) ;
V_165:
free ( V_161 ) ;
return V_86 ;
}
int F_153 ( struct V_1 * V_2 , T_13 V_13 )
{
return F_152 ( V_2 , 1 , & V_13 ) ;
}
bool F_154 ( struct V_1 * V_2 )
{
struct V_14 * V_19 ;
if ( V_2 -> V_22 == 1 )
return true ;
if ( V_2 -> V_16 < 0 || V_2 -> V_17 < 0 )
return false ;
F_16 (evlist, pos) {
if ( V_19 -> V_16 != V_2 -> V_16 ||
V_19 -> V_17 != V_2 -> V_17 )
return false ;
}
return true ;
}
T_2 F_155 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
if ( V_2 -> V_166 )
return V_2 -> V_166 ;
F_16 (evlist, evsel)
V_2 -> V_166 |= V_18 -> V_38 . V_167 ;
return V_2 -> V_166 ;
}
T_2 F_156 ( struct V_1 * V_2 )
{
V_2 -> V_166 = 0 ;
return F_155 ( V_2 ) ;
}
T_2 F_157 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
T_2 V_168 = 0 ;
F_16 (evlist, evsel)
V_168 |= V_18 -> V_38 . V_169 ;
return V_168 ;
}
bool F_158 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_14 ( V_2 ) , * V_19 = V_15 ;
T_2 V_92 = V_15 -> V_38 . V_92 ;
T_2 V_167 = V_15 -> V_38 . V_167 ;
F_16 (evlist, pos) {
if ( V_92 != V_19 -> V_38 . V_92 )
return false ;
}
if ( ( V_167 & V_170 ) &&
! ( V_92 & V_93 ) ) {
return false ;
}
return true ;
}
T_2 F_92 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
return V_15 -> V_38 . V_92 ;
}
T_14 F_159 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
struct V_171 * V_109 ;
T_2 V_167 ;
T_14 V_49 = 0 ;
if ( ! V_15 -> V_38 . V_105 )
goto V_172;
V_167 = V_15 -> V_38 . V_167 ;
if ( V_167 & V_173 )
V_49 += sizeof( V_109 -> V_97 ) * 2 ;
if ( V_167 & V_174 )
V_49 += sizeof( V_109 -> time ) ;
if ( V_167 & V_175 )
V_49 += sizeof( V_109 -> V_54 ) ;
if ( V_167 & V_176 )
V_49 += sizeof( V_109 -> V_177 ) ;
if ( V_167 & V_178 )
V_49 += sizeof( V_109 -> V_60 ) * 2 ;
if ( V_167 & V_179 )
V_49 += sizeof( V_109 -> V_54 ) ;
V_172:
return V_49 ;
}
bool F_160 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_14 ( V_2 ) , * V_19 = V_15 ;
F_161 (evlist, pos) {
if ( V_15 -> V_38 . V_105 != V_19 -> V_38 . V_105 )
return false ;
}
return true ;
}
bool F_99 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_14 ( V_2 ) ;
return V_15 -> V_38 . V_105 ;
}
void F_162 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
V_2 -> V_180 = V_18 ;
}
void F_26 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_159 = F_69 ( V_2 -> V_4 ) ;
int V_160 = F_58 ( V_2 -> V_6 ) ;
int V_20 ;
F_163 (evlist, evsel) {
V_20 = V_18 -> V_4 ? V_18 -> V_4 -> V_153 : V_159 ;
F_164 ( V_18 , V_20 , V_160 ) ;
}
}
static int F_165 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_62 = - V_46 ;
V_4 = F_147 ( NULL ) ;
if ( ! V_4 )
goto V_172;
V_6 = F_166 () ;
if ( ! V_6 )
goto V_181;
F_4 ( V_2 , V_4 , V_6 ) ;
V_172:
return V_62 ;
V_181:
F_27 ( V_4 ) ;
goto V_172;
}
int F_167 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_62 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_62 = F_165 ( V_2 ) ;
if ( V_62 < 0 )
goto V_182;
}
F_15 ( V_2 ) ;
F_16 (evlist, evsel) {
V_62 = F_168 ( V_18 , V_18 -> V_4 , V_18 -> V_6 ) ;
if ( V_62 < 0 )
goto V_182;
}
return 0 ;
V_182:
F_26 ( V_2 ) ;
V_89 = - V_62 ;
return V_62 ;
}
int F_169 ( struct V_1 * V_2 , struct V_154 * V_154 ,
const char * V_183 [] , bool V_184 ,
void (* F_170)( int V_185 , T_15 * V_186 , void * V_187 ) )
{
int V_188 [ 2 ] , V_189 [ 2 ] ;
char V_190 ;
if ( F_171 ( V_188 ) < 0 ) {
perror ( L_13 ) ;
return - 1 ;
}
if ( F_171 ( V_189 ) < 0 ) {
perror ( L_14 ) ;
goto V_191;
}
V_2 -> V_12 . V_13 = F_172 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_15 ) ;
goto V_192;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_86 ;
if ( V_184 )
F_173 ( 2 , 1 ) ;
signal ( V_193 , V_194 ) ;
F_44 ( V_188 [ 0 ] ) ;
F_44 ( V_189 [ 1 ] ) ;
F_77 ( V_189 [ 0 ] , V_195 , V_196 ) ;
F_44 ( V_188 [ 1 ] ) ;
V_86 = F_93 ( V_189 [ 0 ] , & V_190 , 1 ) ;
if ( V_86 != 1 ) {
if ( V_86 == - 1 )
perror ( L_16 ) ;
exit ( V_86 ) ;
}
F_174 ( V_183 [ 0 ] , ( char * * ) V_183 ) ;
if ( F_170 ) {
union V_197 V_139 ;
V_139 . V_198 = V_89 ;
if ( F_175 ( F_176 () , V_199 , V_139 ) )
perror ( V_183 [ 0 ] ) ;
} else
perror ( V_183 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_170 ) {
struct V_200 V_201 = {
. V_202 = V_203 ,
. V_204 = F_170 ,
} ;
V_200 ( V_199 , & V_201 , NULL ) ;
}
if ( F_177 ( V_154 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_116 , L_17 ,
V_205 , __LINE__ ) ;
goto V_192;
}
F_178 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_44 ( V_188 [ 1 ] ) ;
F_44 ( V_189 [ 0 ] ) ;
if ( F_93 ( V_188 [ 0 ] , & V_190 , 1 ) == - 1 ) {
perror ( L_16 ) ;
goto V_192;
}
F_77 ( V_189 [ 1 ] , V_195 , V_196 ) ;
V_2 -> V_12 . V_206 = V_189 [ 1 ] ;
F_44 ( V_188 [ 0 ] ) ;
return 0 ;
V_192:
F_44 ( V_189 [ 0 ] ) ;
F_44 ( V_189 [ 1 ] ) ;
V_191:
F_44 ( V_188 [ 0 ] ) ;
F_44 ( V_188 [ 1 ] ) ;
return - 1 ;
}
int F_179 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_206 > 0 ) {
char V_190 = 0 ;
int V_86 ;
V_86 = F_180 ( V_2 -> V_12 . V_206 , & V_190 , 1 ) ;
if ( V_86 < 0 )
perror ( L_18 ) ;
F_44 ( V_2 -> V_12 . V_206 ) ;
return V_86 ;
}
return 0 ;
}
int F_181 ( struct V_1 * V_2 , union V_99 * V_100 ,
struct V_171 * V_102 )
{
struct V_14 * V_18 = F_102 ( V_2 , V_100 ) ;
if ( ! V_18 )
return - V_207 ;
return F_182 ( V_18 , V_100 , V_102 ) ;
}
T_1 F_183 ( struct V_1 * V_2 , T_16 * V_208 )
{
struct V_14 * V_18 ;
T_1 V_209 = 0 ;
F_16 (evlist, evsel) {
V_209 += fprintf ( V_208 , L_19 , V_18 -> V_27 ? L_20 : L_21 ,
F_184 ( V_18 ) ) ;
}
return V_209 + fprintf ( V_208 , L_22 ) ;
}
int F_185 ( struct V_1 * V_2 V_123 ,
int V_62 , char * V_210 , T_1 V_49 )
{
int V_209 , V_149 ;
char V_211 [ V_212 ] , * V_213 = F_186 ( V_62 , V_211 , sizeof( V_211 ) ) ;
switch ( V_62 ) {
case V_214 :
case V_215 :
V_209 = F_187 ( V_210 , V_49 ,
L_23
L_24 , V_213 ) ;
V_149 = F_188 () ;
V_209 += F_187 ( V_210 + V_209 , V_49 - V_209 , L_25 ) ;
if ( V_149 >= 2 ) {
V_209 += F_187 ( V_210 + V_209 , V_49 - V_209 ,
L_26 ) ;
}
V_209 += F_187 ( V_210 + V_209 , V_49 - V_209 ,
L_27 ) ;
V_209 += F_187 ( V_210 + V_209 , V_49 - V_209 ,
L_28
L_29 , V_149 ) ;
break;
default:
F_187 ( V_210 , V_49 , L_30 , V_213 ) ;
break;
}
return 0 ;
}
int F_189 ( struct V_1 * V_2 , int V_62 , char * V_210 , T_1 V_49 )
{
char V_211 [ V_212 ] , * V_213 = F_186 ( V_62 , V_211 , sizeof( V_211 ) ) ;
int V_216 = V_2 -> V_125 / 1024 , V_217 , V_209 = 0 ;
switch ( V_62 ) {
case V_215 :
F_128 ( L_7 , & V_217 ) ;
V_209 += F_187 ( V_210 + V_209 , V_49 - V_209 ,
L_23
L_31
L_32 ,
V_213 , V_217 , V_216 ) ;
if ( V_216 >= V_217 ) {
V_209 += F_187 ( V_210 + V_209 , V_49 - V_209 ,
L_33 ,
V_217 + V_216 ) ;
}
V_209 += F_187 ( V_210 + V_209 , V_49 - V_209 ,
L_34 ) ;
break;
default:
F_187 ( V_210 , V_49 , L_30 , V_213 ) ;
break;
}
return 0 ;
}
void F_190 ( struct V_1 * V_2 ,
struct V_14 * V_218 )
{
struct V_14 * V_18 , * V_20 ;
F_49 ( V_219 ) ;
if ( V_218 == F_14 ( V_2 ) )
return;
F_19 (evlist, n, evsel) {
if ( V_18 -> V_32 == V_218 -> V_32 )
F_191 ( & V_18 -> V_21 , & V_219 ) ;
}
F_192 ( & V_219 , & V_2 -> V_10 ) ;
}
void F_193 ( struct V_1 * V_2 ,
struct V_14 * V_220 )
{
struct V_14 * V_18 ;
if ( V_220 -> V_28 )
return;
F_16 (evlist, evsel) {
if ( V_18 != V_220 )
V_18 -> V_28 = false ;
}
V_220 -> V_28 = true ;
}
