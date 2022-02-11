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
void F_11 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
V_2 -> V_16 = V_15 -> V_16 ;
V_2 -> V_17 = V_15 -> V_17 ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel)
F_15 ( V_18 ) ;
F_11 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
struct V_14 * V_19 , * V_20 ;
F_17 (evlist, n, pos) {
F_18 ( & V_19 -> V_21 ) ;
V_19 -> V_2 = NULL ;
F_19 ( V_19 ) ;
}
V_2 -> V_22 = 0 ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( & V_2 -> V_23 ) ;
F_22 ( & V_2 -> V_11 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_23 ( V_2 ) ;
F_24 ( V_2 ) ;
F_25 ( V_2 -> V_4 ) ;
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_6 = NULL ;
F_16 ( V_2 ) ;
F_20 ( V_2 ) ;
free ( V_2 ) ;
}
static void F_27 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
if ( ! V_18 -> V_24 || V_2 -> V_25 ) {
F_25 ( V_18 -> V_4 ) ;
V_18 -> V_4 = F_28 ( V_2 -> V_4 ) ;
} else if ( V_18 -> V_4 != V_18 -> V_24 ) {
F_25 ( V_18 -> V_4 ) ;
V_18 -> V_4 = F_28 ( V_18 -> V_24 ) ;
}
F_26 ( V_18 -> V_6 ) ;
V_18 -> V_6 = F_29 ( V_2 -> V_6 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel)
F_27 ( V_2 , V_18 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_14 * V_26 )
{
V_26 -> V_2 = V_2 ;
F_32 ( & V_26 -> V_21 , & V_2 -> V_10 ) ;
V_26 -> V_27 = V_2 -> V_22 ;
V_26 -> V_28 = ! V_26 -> V_27 ;
if ( ! V_2 -> V_22 ++ )
F_11 ( V_2 ) ;
F_27 ( V_2 , V_26 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_14 * V_18 )
{
V_18 -> V_2 = NULL ;
F_18 ( & V_18 -> V_21 ) ;
V_2 -> V_22 -= 1 ;
}
void F_34 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_14 * V_18 , * V_31 ;
F_35 (list, temp, evsel) {
F_18 ( & V_18 -> V_21 ) ;
F_31 ( V_2 , V_18 ) ;
}
}
void F_36 ( struct V_29 * V_30 )
{
struct V_14 * V_18 , * V_32 ;
V_32 = F_37 ( V_30 -> V_33 , struct V_14 , V_21 ) ;
V_18 = F_37 ( V_30 -> V_34 , struct V_14 , V_21 ) ;
V_32 -> V_35 = V_18 -> V_27 - V_32 -> V_27 + 1 ;
F_38 (list, evsel) {
V_18 -> V_32 = V_32 ;
}
}
void F_39 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 ) {
V_2 -> V_36 = V_2 -> V_22 > 1 ? 1 : 0 ;
F_36 ( & V_2 -> V_10 ) ;
}
}
void F_40 ( struct V_37 * V_38 )
{
V_38 -> V_39 = 3 ;
while ( V_38 -> V_39 != 0 ) {
int V_40 = F_41 ( V_38 , 0 , - 1 , - 1 , 0 ) ;
if ( V_40 != - 1 ) {
F_42 ( V_40 ) ;
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
F_43 ( & V_38 ) ;
F_40 ( & V_38 ) ;
V_18 = F_44 ( & V_38 ) ;
if ( V_18 == NULL )
goto error;
if ( F_45 ( & V_18 -> V_44 , L_1 ,
V_38 . V_39 ? V_38 . V_39 + 1 : 0 , L_2 ) < 0 )
goto V_45;
F_31 ( V_2 , V_18 ) ;
return 0 ;
V_45:
F_19 ( V_18 ) ;
error:
return - V_46 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_37 * V_47 , T_1 V_48 )
{
struct V_14 * V_18 , * V_20 ;
F_47 ( V_49 ) ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ ) {
V_18 = F_48 ( V_47 + V_7 , V_2 -> V_22 + V_7 ) ;
if ( V_18 == NULL )
goto V_50;
F_32 ( & V_18 -> V_21 , & V_49 ) ;
}
F_34 ( V_2 , & V_49 ) ;
return 0 ;
V_50:
F_35 (&head, n, evsel)
F_19 ( V_18 ) ;
return - 1 ;
}
int F_49 ( struct V_1 * V_2 ,
struct V_37 * V_47 , T_1 V_48 )
{
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_48 ; V_7 ++ )
F_43 ( V_47 + V_7 ) ;
return F_46 ( V_2 , V_47 , V_48 ) ;
}
struct V_14 *
F_50 ( struct V_1 * V_2 , int V_51 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( V_18 -> V_38 . type == V_52 &&
( int ) V_18 -> V_38 . V_42 == V_51 )
return V_18 ;
}
return NULL ;
}
struct V_14 *
F_51 ( struct V_1 * V_2 ,
const char * V_44 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_38 . type == V_52 ) &&
( strcmp ( V_18 -> V_44 , V_44 ) == 0 ) )
return V_18 ;
}
return NULL ;
}
int F_52 ( struct V_1 * V_2 ,
const char * V_53 , const char * V_44 , void * V_54 )
{
struct V_14 * V_18 = F_53 ( V_53 , V_44 ) ;
if ( F_54 ( V_18 ) )
return - 1 ;
V_18 -> V_54 = V_54 ;
F_31 ( V_2 , V_18 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
if ( V_18 -> V_55 )
return 1 ;
else
return F_56 ( V_2 -> V_6 ) ;
}
void F_57 ( struct V_1 * V_2 )
{
int V_56 , V_57 ;
struct V_14 * V_19 ;
int V_58 = F_58 ( V_2 -> V_4 ) ;
int V_59 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
F_14 (evlist, pos) {
if ( ! F_59 ( V_19 ) || ! V_19 -> V_40 )
continue;
V_59 = F_55 ( V_2 , V_19 ) ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ )
F_60 ( F_61 ( V_19 , V_56 , V_57 ) ,
V_60 , 0 ) ;
}
}
V_2 -> V_61 = false ;
}
void F_62 ( struct V_1 * V_2 )
{
int V_56 , V_57 ;
struct V_14 * V_19 ;
int V_58 = F_58 ( V_2 -> V_4 ) ;
int V_59 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
F_14 (evlist, pos) {
if ( ! F_59 ( V_19 ) || ! V_19 -> V_40 )
continue;
V_59 = F_55 ( V_2 , V_19 ) ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ )
F_60 ( F_61 ( V_19 , V_56 , V_57 ) ,
V_62 , 0 ) ;
}
}
V_2 -> V_61 = true ;
}
void F_63 ( struct V_1 * V_2 )
{
( V_2 -> V_61 ? F_57 : F_62 ) ( V_2 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_56 , V_57 , V_63 ;
int V_58 = F_58 ( V_2 -> V_4 ) ;
int V_59 = F_55 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_40 )
return 0 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
V_63 = F_60 ( F_61 ( V_18 , V_56 , V_57 ) ,
V_60 , 0 ) ;
if ( V_63 )
return V_63 ;
}
}
return 0 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
int V_56 , V_57 , V_63 ;
int V_58 = F_58 ( V_2 -> V_4 ) ;
int V_59 = F_55 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_40 )
return - V_64 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
V_63 = F_60 ( F_61 ( V_18 , V_56 , V_57 ) ,
V_62 , 0 ) ;
if ( V_63 )
return V_63 ;
}
}
return 0 ;
}
static int F_66 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_56 )
{
int V_57 , V_63 ;
int V_59 = F_55 ( V_2 , V_18 ) ;
if ( ! V_18 -> V_40 )
return - V_64 ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
V_63 = F_60 ( F_61 ( V_18 , V_56 , V_57 ) ,
V_62 , 0 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_57 )
{
int V_56 , V_63 ;
int V_58 = F_58 ( V_2 -> V_4 ) ;
if ( ! V_18 -> V_40 )
return - V_64 ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
V_63 = F_60 ( F_61 ( V_18 , V_56 , V_57 ) , V_62 , 0 ) ;
if ( V_63 )
return V_63 ;
}
return 0 ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_27 )
{
bool V_65 = ! F_69 ( V_2 -> V_4 ) ;
if ( V_65 )
return F_66 ( V_2 , V_18 , V_27 ) ;
else
return F_67 ( V_2 , V_18 , V_27 ) ;
}
int F_70 ( struct V_1 * V_2 )
{
int V_58 = F_58 ( V_2 -> V_4 ) ;
int V_59 = F_56 ( V_2 -> V_6 ) ;
int V_66 = 0 ;
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
if ( V_18 -> V_55 )
V_66 += V_58 ;
else
V_66 += V_58 * V_59 ;
}
if ( F_71 ( & V_2 -> V_11 ) < V_66 &&
F_72 ( & V_2 -> V_11 , V_66 ) < 0 )
return - V_46 ;
return 0 ;
}
static int F_73 ( struct V_1 * V_2 , int V_40 , int V_27 )
{
int V_19 = F_74 ( & V_2 -> V_11 , V_40 , V_67 | V_68 | V_69 ) ;
if ( V_19 >= 0 ) {
V_2 -> V_11 . V_70 [ V_19 ] . V_27 = V_27 ;
F_75 ( V_40 , V_71 , V_72 ) ;
}
return V_19 ;
}
int F_76 ( struct V_1 * V_2 , int V_40 )
{
return F_73 ( V_2 , V_40 , - 1 ) ;
}
static void F_77 ( struct V_73 * V_74 , int V_40 )
{
struct V_1 * V_2 = F_78 ( V_74 , struct V_1 , V_11 ) ;
F_79 ( V_2 , V_74 -> V_70 [ V_40 ] . V_27 ) ;
}
int F_80 ( struct V_1 * V_2 , short V_75 )
{
return F_81 ( & V_2 -> V_11 , V_75 ,
F_77 ) ;
}
int F_82 ( struct V_1 * V_2 , int V_76 )
{
return F_83 ( & V_2 -> V_11 , V_76 ) ;
}
static void F_84 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_56 , int V_57 , T_2 V_51 )
{
int V_77 ;
struct V_78 * V_79 = F_85 ( V_18 , V_56 , V_57 ) ;
V_79 -> V_51 = V_51 ;
V_79 -> V_18 = V_18 ;
V_77 = F_86 ( V_79 -> V_51 , V_80 ) ;
F_87 ( & V_79 -> V_21 , & V_2 -> V_9 [ V_77 ] ) ;
}
void F_88 ( struct V_1 * V_2 , struct V_14 * V_18 ,
int V_56 , int V_57 , T_2 V_51 )
{
F_84 ( V_2 , V_18 , V_56 , V_57 , V_51 ) ;
V_18 -> V_51 [ V_18 -> V_81 ++ ] = V_51 ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_14 * V_18 ,
int V_56 , int V_57 , int V_40 )
{
T_2 V_82 [ 4 ] = { 0 , } ;
int V_83 = 1 ;
T_2 V_51 ;
int V_84 ;
V_84 = F_60 ( V_40 , V_85 , & V_51 ) ;
if ( ! V_84 )
goto V_86;
if ( V_87 != V_88 )
return - 1 ;
if ( F_90 ( V_2 ) & V_89 )
return - 1 ;
if ( ! ( V_18 -> V_38 . V_90 & V_91 ) ||
F_91 ( V_40 , & V_82 , sizeof( V_82 ) ) == - 1 )
return - 1 ;
if ( V_18 -> V_38 . V_90 & V_92 )
++ V_83 ;
if ( V_18 -> V_38 . V_90 & V_93 )
++ V_83 ;
V_51 = V_82 [ V_83 ] ;
V_86:
F_88 ( V_2 , V_18 , V_56 , V_57 , V_51 ) ;
return 0 ;
}
static void F_92 ( struct V_1 * V_2 ,
struct V_14 * V_18 , int V_27 , int V_56 ,
int V_57 )
{
struct V_78 * V_79 = F_85 ( V_18 , V_56 , V_57 ) ;
V_79 -> V_27 = V_27 ;
if ( V_2 -> V_4 && V_56 >= 0 )
V_79 -> V_56 = V_2 -> V_4 -> V_94 [ V_56 ] ;
else
V_79 -> V_56 = - 1 ;
if ( ! V_18 -> V_55 && V_2 -> V_6 && V_57 >= 0 )
V_79 -> V_95 = F_93 ( V_2 -> V_6 , V_57 ) ;
else
V_79 -> V_95 = - 1 ;
}
struct V_78 * F_94 ( struct V_1 * V_2 , T_2 V_51 )
{
struct V_96 * V_49 ;
struct V_78 * V_79 ;
int V_77 ;
V_77 = F_86 ( V_51 , V_80 ) ;
V_49 = & V_2 -> V_9 [ V_77 ] ;
F_95 (sid, head, node)
if ( V_79 -> V_51 == V_51 )
return V_79 ;
return NULL ;
}
struct V_14 * F_96 ( struct V_1 * V_2 , T_2 V_51 )
{
struct V_78 * V_79 ;
if ( V_2 -> V_22 == 1 || ! V_51 )
return F_12 ( V_2 ) ;
V_79 = F_94 ( V_2 , V_51 ) ;
if ( V_79 )
return V_79 -> V_18 ;
if ( ! F_97 ( V_2 ) )
return F_12 ( V_2 ) ;
return NULL ;
}
struct V_14 * F_98 ( struct V_1 * V_2 ,
T_2 V_51 )
{
struct V_78 * V_79 ;
if ( ! V_51 )
return NULL ;
V_79 = F_94 ( V_2 , V_51 ) ;
if ( V_79 )
return V_79 -> V_18 ;
return NULL ;
}
static int F_99 ( struct V_1 * V_2 ,
union V_97 * V_98 , T_2 * V_51 )
{
const T_2 * V_99 = V_98 -> V_100 . V_99 ;
T_3 V_20 ;
V_20 = ( V_98 -> V_101 . V_102 - sizeof( V_98 -> V_101 ) ) >> 3 ;
if ( V_98 -> V_101 . type == V_103 ) {
if ( V_2 -> V_16 >= V_20 )
return - 1 ;
* V_51 = V_99 [ V_2 -> V_16 ] ;
} else {
if ( V_2 -> V_17 > V_20 )
return - 1 ;
V_20 -= V_2 -> V_17 ;
* V_51 = V_99 [ V_20 ] ;
}
return 0 ;
}
static struct V_14 * F_100 ( struct V_1 * V_2 ,
union V_97 * V_98 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_96 * V_49 ;
struct V_78 * V_79 ;
int V_77 ;
T_2 V_51 ;
if ( V_2 -> V_22 == 1 )
return V_15 ;
if ( ! V_15 -> V_38 . V_104 &&
V_98 -> V_101 . type != V_103 )
return V_15 ;
if ( F_99 ( V_2 , V_98 , & V_51 ) )
return NULL ;
if ( ! V_51 )
return V_15 ;
V_77 = F_86 ( V_51 , V_80 ) ;
V_49 = & V_2 -> V_9 [ V_77 ] ;
F_95 (sid, head, node) {
if ( V_79 -> V_51 == V_51 )
return V_79 -> V_18 ;
}
return NULL ;
}
union V_97 * F_101 ( struct V_1 * V_2 , int V_27 )
{
struct V_105 * V_106 = & V_2 -> V_23 [ V_27 ] ;
T_2 V_49 ;
T_2 V_107 = V_106 -> V_34 ;
unsigned char * V_108 = V_106 -> V_109 + V_110 ;
union V_97 * V_98 = NULL ;
if ( ! F_102 ( & V_106 -> V_111 ) )
return NULL ;
V_49 = F_103 ( V_106 ) ;
if ( V_2 -> V_112 ) {
int V_113 = V_49 - V_107 ;
if ( V_113 > V_106 -> V_114 / 2 || V_113 < 0 ) {
fprintf ( V_115 , L_3 ) ;
V_107 = V_49 ;
}
}
if ( V_107 != V_49 ) {
T_1 V_102 ;
V_98 = (union V_97 * ) & V_108 [ V_107 & V_106 -> V_114 ] ;
V_102 = V_98 -> V_101 . V_102 ;
if ( ( V_107 & V_106 -> V_114 ) + V_102 != ( ( V_107 + V_102 ) & V_106 -> V_114 ) ) {
unsigned int V_116 = V_107 ;
unsigned int V_117 = F_104 ( sizeof( * V_98 ) , V_102 ) , V_118 ;
void * V_119 = V_106 -> V_120 ;
do {
V_118 = F_104 ( V_106 -> V_114 + 1 - ( V_116 & V_106 -> V_114 ) , V_117 ) ;
memcpy ( V_119 , & V_108 [ V_116 & V_106 -> V_114 ] , V_118 ) ;
V_116 += V_118 ;
V_119 += V_118 ;
V_117 -= V_118 ;
} while ( V_117 );
V_98 = (union V_97 * ) V_106 -> V_120 ;
}
V_107 += V_102 ;
}
V_106 -> V_34 = V_107 ;
return V_98 ;
}
static bool F_105 ( struct V_105 * V_106 )
{
return F_103 ( V_106 ) == V_106 -> V_34 && ! V_106 -> V_121 . V_109 ;
}
static void F_106 ( struct V_1 * V_2 , int V_27 )
{
F_107 ( & V_2 -> V_23 [ V_27 ] . V_111 ) ;
}
static void F_79 ( struct V_1 * V_2 , int V_27 )
{
F_108 ( F_102 ( & V_2 -> V_23 [ V_27 ] . V_111 ) == 0 ) ;
if ( F_109 ( & V_2 -> V_23 [ V_27 ] . V_111 ) )
F_110 ( V_2 , V_27 ) ;
}
void F_111 ( struct V_1 * V_2 , int V_27 )
{
struct V_105 * V_106 = & V_2 -> V_23 [ V_27 ] ;
if ( ! V_2 -> V_112 ) {
T_2 V_107 = V_106 -> V_34 ;
F_112 ( V_106 , V_107 ) ;
}
if ( F_102 ( & V_106 -> V_111 ) == 1 && F_105 ( V_106 ) )
F_79 ( V_2 , V_27 ) ;
}
int __weak F_113 ( struct V_121 * T_4 V_122 ,
struct V_123 * T_5 V_122 ,
void * T_6 V_122 ,
int V_40 V_122 )
{
return 0 ;
}
void __weak F_114 ( struct V_121 * T_4 V_122 )
{
}
void __weak F_115 (
struct V_123 * T_5 V_122 ,
T_7 T_8 V_122 ,
unsigned int T_9 V_122 ,
bool T_10 V_122 )
{
}
void __weak F_116 (
struct V_123 * T_5 V_122 ,
struct V_1 * V_2 V_122 ,
int V_27 V_122 ,
bool T_11 V_122 )
{
}
static void F_110 ( struct V_1 * V_2 , int V_27 )
{
if ( V_2 -> V_23 [ V_27 ] . V_109 != NULL ) {
F_117 ( V_2 -> V_23 [ V_27 ] . V_109 , V_2 -> V_124 ) ;
V_2 -> V_23 [ V_27 ] . V_109 = NULL ;
F_118 ( & V_2 -> V_23 [ V_27 ] . V_111 , 0 ) ;
}
F_114 ( & V_2 -> V_23 [ V_27 ] . V_121 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
int V_7 ;
if ( V_2 -> V_23 == NULL )
return;
for ( V_7 = 0 ; V_7 < V_2 -> V_125 ; V_7 ++ )
F_110 ( V_2 , V_7 ) ;
F_21 ( & V_2 -> V_23 ) ;
}
static int F_119 ( struct V_1 * V_2 )
{
V_2 -> V_125 = F_58 ( V_2 -> V_4 ) ;
if ( F_69 ( V_2 -> V_4 ) )
V_2 -> V_125 = F_56 ( V_2 -> V_6 ) ;
V_2 -> V_23 = F_7 ( V_2 -> V_125 * sizeof( struct V_105 ) ) ;
return V_2 -> V_23 != NULL ? 0 : - V_46 ;
}
static int F_120 ( struct V_1 * V_2 , int V_27 ,
struct V_126 * T_5 , int V_40 )
{
F_118 ( & V_2 -> V_23 [ V_27 ] . V_111 , 2 ) ;
V_2 -> V_23 [ V_27 ] . V_34 = 0 ;
V_2 -> V_23 [ V_27 ] . V_114 = T_5 -> V_114 ;
V_2 -> V_23 [ V_27 ] . V_109 = V_23 ( NULL , V_2 -> V_124 , T_5 -> V_127 ,
V_128 , V_40 , 0 ) ;
if ( V_2 -> V_23 [ V_27 ] . V_109 == V_129 ) {
F_121 ( L_4 ,
V_87 ) ;
V_2 -> V_23 [ V_27 ] . V_109 = NULL ;
return - 1 ;
}
if ( F_113 ( & V_2 -> V_23 [ V_27 ] . V_121 ,
& T_5 -> V_130 , V_2 -> V_23 [ V_27 ] . V_109 , V_40 ) )
return - 1 ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , int V_27 ,
struct V_126 * T_5 , int V_56 ,
int V_57 , int * V_131 )
{
struct V_14 * V_18 ;
F_14 (evlist, evsel) {
int V_40 ;
if ( V_18 -> V_55 && V_57 )
continue;
V_40 = F_61 ( V_18 , V_56 , V_57 ) ;
if ( * V_131 == - 1 ) {
* V_131 = V_40 ;
if ( F_120 ( V_2 , V_27 , T_5 , * V_131 ) < 0 )
return - 1 ;
} else {
if ( F_60 ( V_40 , V_132 , * V_131 ) != 0 )
return - 1 ;
F_106 ( V_2 , V_27 ) ;
}
if ( ! V_18 -> V_55 &&
F_73 ( V_2 , V_40 , V_27 ) < 0 ) {
F_79 ( V_2 , V_27 ) ;
return - 1 ;
}
if ( V_18 -> V_38 . V_90 & V_91 ) {
if ( F_89 ( V_2 , V_18 , V_56 , V_57 ,
V_40 ) < 0 )
return - 1 ;
F_92 ( V_2 , V_18 , V_27 , V_56 ,
V_57 ) ;
}
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 ,
struct V_126 * T_5 )
{
int V_56 , V_57 ;
int V_58 = F_58 ( V_2 -> V_4 ) ;
int V_59 = F_56 ( V_2 -> V_6 ) ;
F_121 ( L_5 ) ;
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ ) {
int V_131 = - 1 ;
F_116 ( & T_5 -> V_130 , V_2 , V_56 ,
true ) ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
if ( F_122 ( V_2 , V_56 , T_5 , V_56 ,
V_57 , & V_131 ) )
goto V_133;
}
}
return 0 ;
V_133:
for ( V_56 = 0 ; V_56 < V_58 ; V_56 ++ )
F_110 ( V_2 , V_56 ) ;
return - 1 ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_126 * T_5 )
{
int V_57 ;
int V_59 = F_56 ( V_2 -> V_6 ) ;
F_121 ( L_6 ) ;
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ ) {
int V_131 = - 1 ;
F_116 ( & T_5 -> V_130 , V_2 , V_57 ,
false ) ;
if ( F_122 ( V_2 , V_57 , T_5 , 0 , V_57 ,
& V_131 ) )
goto V_133;
}
return 0 ;
V_133:
for ( V_57 = 0 ; V_57 < V_59 ; V_57 ++ )
F_110 ( V_2 , V_57 ) ;
return - 1 ;
}
static T_1 F_125 ( unsigned long V_134 )
{
if ( V_134 == V_135 ) {
int V_136 ;
if ( F_126 ( L_7 , & V_136 ) < 0 ) {
V_136 = 512 ;
} else {
V_136 -= ( V_110 / 1024 ) ;
}
V_134 = ( V_136 * 1024 ) / V_110 ;
if ( ! F_127 ( V_134 ) )
V_134 = F_128 ( V_134 ) ;
} else if ( ! F_127 ( V_134 ) )
return 0 ;
return ( V_134 + 1 ) * V_110 ;
}
static long F_129 ( const char * V_137 , unsigned long F_104 ,
unsigned long V_136 )
{
unsigned long V_134 , V_138 ;
static struct V_139 V_140 [] = {
{ . V_141 = 'B' , . V_142 = 1 } ,
{ . V_141 = 'K' , . V_142 = 1 << 10 } ,
{ . V_141 = 'M' , . V_142 = 1 << 20 } ,
{ . V_141 = 'G' , . V_142 = 1 << 30 } ,
{ . V_141 = 0 } ,
} ;
if ( V_137 == NULL )
return - V_64 ;
V_138 = F_130 ( V_137 , V_140 ) ;
if ( V_138 != ( unsigned long ) - 1 ) {
V_134 = F_131 ( V_138 , V_110 ) / V_110 ;
} else {
char * V_143 ;
V_134 = strtoul ( V_137 , & V_143 , 10 ) ;
if ( * V_143 != '\0' )
return - V_64 ;
}
if ( V_134 == 0 && F_104 == 0 ) {
} else if ( ! F_127 ( V_134 ) ) {
V_134 = F_132 ( V_134 ) ;
if ( ! V_134 )
return - V_64 ;
F_133 ( L_8 ,
V_134 * V_110 , V_134 ) ;
}
if ( V_134 > V_136 )
return - V_64 ;
return V_134 ;
}
int F_134 ( unsigned int * V_144 , const char * V_137 )
{
unsigned long V_136 = V_135 ;
long V_134 ;
if ( V_136 > V_145 / V_110 )
V_136 = V_145 / V_110 ;
V_134 = F_129 ( V_137 , 1 , V_136 ) ;
if ( V_134 < 0 ) {
F_135 ( L_9 ) ;
return - 1 ;
}
* V_144 = V_134 ;
return 0 ;
}
int F_136 ( const struct V_146 * V_147 , const char * V_137 ,
int T_12 V_122 )
{
return F_134 ( V_147 -> V_148 , V_137 ) ;
}
int F_137 ( struct V_1 * V_2 , unsigned int V_134 ,
bool V_112 , unsigned int T_9 ,
bool T_10 )
{
struct V_14 * V_18 ;
const struct V_3 * V_4 = V_2 -> V_4 ;
const struct V_5 * V_6 = V_2 -> V_6 ;
struct V_126 T_5 = {
. V_127 = V_149 | ( V_112 ? 0 : V_150 ) ,
} ;
if ( V_2 -> V_23 == NULL && F_119 ( V_2 ) < 0 )
return - V_46 ;
if ( V_2 -> V_11 . V_10 == NULL && F_70 ( V_2 ) < 0 )
return - V_46 ;
V_2 -> V_112 = V_112 ;
V_2 -> V_124 = F_125 ( V_134 ) ;
F_138 ( L_10 , V_2 -> V_124 ) ;
T_5 . V_114 = V_2 -> V_124 - V_110 - 1 ;
F_115 ( & T_5 . V_130 , V_2 -> V_124 ,
T_9 , T_10 ) ;
F_14 (evlist, evsel) {
if ( ( V_18 -> V_38 . V_90 & V_91 ) &&
V_18 -> V_151 == NULL &&
F_139 ( V_18 , F_58 ( V_4 ) , V_6 -> V_152 ) < 0 )
return - V_46 ;
}
if ( F_69 ( V_4 ) )
return F_124 ( V_2 , & T_5 ) ;
return F_123 ( V_2 , & T_5 ) ;
}
int F_140 ( struct V_1 * V_2 , unsigned int V_134 ,
bool V_112 )
{
return F_137 ( V_2 , V_134 , V_112 , 0 , false ) ;
}
int F_141 ( struct V_1 * V_2 , struct V_153 * V_153 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
V_6 = F_142 ( V_153 -> V_13 , V_153 -> V_95 , V_153 -> V_154 ) ;
if ( ! V_6 )
return - 1 ;
if ( F_143 ( V_153 ) )
V_4 = F_144 () ;
else
V_4 = F_145 ( V_153 -> V_155 ) ;
if ( ! V_4 )
goto V_156;
V_2 -> V_25 = ! ! V_153 -> V_155 ;
F_4 ( V_2 , V_4 , V_6 ) ;
return 0 ;
V_156:
F_26 ( V_6 ) ;
return - 1 ;
}
void F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_4 != V_2 -> V_4 ) {
F_25 ( V_2 -> V_4 ) ;
V_2 -> V_4 = V_4 ;
}
if ( V_6 != V_2 -> V_6 ) {
F_26 ( V_2 -> V_6 ) ;
V_2 -> V_6 = V_6 ;
}
F_30 ( V_2 ) ;
}
int F_146 ( struct V_1 * V_2 , struct V_14 * * V_157 )
{
struct V_14 * V_18 ;
int V_63 = 0 ;
const int V_158 = F_58 ( V_2 -> V_4 ) ,
V_159 = F_56 ( V_2 -> V_6 ) ;
F_14 (evlist, evsel) {
if ( V_18 -> V_160 == NULL )
continue;
V_63 = F_147 ( V_18 , V_158 , V_159 , V_18 -> V_160 ) ;
if ( V_63 ) {
* V_157 = V_18 ;
break;
}
}
return V_63 ;
}
int F_148 ( struct V_1 * V_2 , const char * V_160 )
{
struct V_14 * V_18 ;
int V_63 = 0 ;
F_14 (evlist, evsel) {
V_63 = F_149 ( V_18 , V_160 ) ;
if ( V_63 )
break;
}
return V_63 ;
}
int F_150 ( struct V_1 * V_2 , T_1 V_161 , T_13 * V_162 )
{
char * V_160 ;
int V_84 = - 1 ;
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_161 ; ++ V_7 ) {
if ( V_7 == 0 ) {
if ( F_45 ( & V_160 , L_11 , V_162 [ V_7 ] ) < 0 )
return - 1 ;
} else {
char * V_163 ;
if ( F_45 ( & V_163 , L_12 , V_160 , V_162 [ V_7 ] ) < 0 )
goto V_164;
free ( V_160 ) ;
V_160 = V_163 ;
}
}
V_84 = F_148 ( V_2 , V_160 ) ;
V_164:
free ( V_160 ) ;
return V_84 ;
}
int F_151 ( struct V_1 * V_2 , T_13 V_13 )
{
return F_150 ( V_2 , 1 , & V_13 ) ;
}
bool F_152 ( struct V_1 * V_2 )
{
struct V_14 * V_19 ;
if ( V_2 -> V_22 == 1 )
return true ;
if ( V_2 -> V_16 < 0 || V_2 -> V_17 < 0 )
return false ;
F_14 (evlist, pos) {
if ( V_19 -> V_16 != V_2 -> V_16 ||
V_19 -> V_17 != V_2 -> V_17 )
return false ;
}
return true ;
}
T_2 F_153 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
if ( V_2 -> V_165 )
return V_2 -> V_165 ;
F_14 (evlist, evsel)
V_2 -> V_165 |= V_18 -> V_38 . V_166 ;
return V_2 -> V_165 ;
}
T_2 F_154 ( struct V_1 * V_2 )
{
V_2 -> V_165 = 0 ;
return F_153 ( V_2 ) ;
}
T_2 F_155 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
T_2 V_167 = 0 ;
F_14 (evlist, evsel)
V_167 |= V_18 -> V_38 . V_168 ;
return V_167 ;
}
bool F_156 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
T_2 V_90 = V_15 -> V_38 . V_90 ;
T_2 V_166 = V_15 -> V_38 . V_166 ;
F_14 (evlist, pos) {
if ( V_90 != V_19 -> V_38 . V_90 )
return false ;
}
if ( ( V_166 & V_169 ) &&
! ( V_90 & V_91 ) ) {
return false ;
}
return true ;
}
T_2 F_90 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_38 . V_90 ;
}
T_14 F_157 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
struct V_170 * V_108 ;
T_2 V_166 ;
T_14 V_102 = 0 ;
if ( ! V_15 -> V_38 . V_104 )
goto V_171;
V_166 = V_15 -> V_38 . V_166 ;
if ( V_166 & V_172 )
V_102 += sizeof( V_108 -> V_95 ) * 2 ;
if ( V_166 & V_173 )
V_102 += sizeof( V_108 -> time ) ;
if ( V_166 & V_174 )
V_102 += sizeof( V_108 -> V_51 ) ;
if ( V_166 & V_175 )
V_102 += sizeof( V_108 -> V_176 ) ;
if ( V_166 & V_177 )
V_102 += sizeof( V_108 -> V_56 ) * 2 ;
if ( V_166 & V_178 )
V_102 += sizeof( V_108 -> V_51 ) ;
V_171:
return V_102 ;
}
bool F_158 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) , * V_19 = V_15 ;
F_159 (evlist, pos) {
if ( V_15 -> V_38 . V_104 != V_19 -> V_38 . V_104 )
return false ;
}
return true ;
}
bool F_97 ( struct V_1 * V_2 )
{
struct V_14 * V_15 = F_12 ( V_2 ) ;
return V_15 -> V_38 . V_104 ;
}
void F_160 ( struct V_1 * V_2 ,
struct V_14 * V_18 )
{
V_2 -> V_179 = V_18 ;
}
void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_158 = F_58 ( V_2 -> V_4 ) ;
int V_159 = F_56 ( V_2 -> V_6 ) ;
int V_20 ;
F_161 (evlist, evsel) {
V_20 = V_18 -> V_4 ? V_18 -> V_4 -> V_152 : V_158 ;
F_162 ( V_18 , V_20 , V_159 ) ;
}
}
static int F_163 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_63 = - V_46 ;
V_4 = F_145 ( NULL ) ;
if ( ! V_4 )
goto V_171;
V_6 = F_164 () ;
if ( ! V_6 )
goto V_180;
F_4 ( V_2 , V_4 , V_6 ) ;
V_171:
return V_63 ;
V_180:
F_25 ( V_4 ) ;
goto V_171;
}
int F_165 ( struct V_1 * V_2 )
{
struct V_14 * V_18 ;
int V_63 ;
if ( V_2 -> V_6 == NULL && V_2 -> V_4 == NULL ) {
V_63 = F_163 ( V_2 ) ;
if ( V_63 < 0 )
goto V_181;
}
F_13 ( V_2 ) ;
F_14 (evlist, evsel) {
V_63 = F_166 ( V_18 , V_2 -> V_4 , V_2 -> V_6 ) ;
if ( V_63 < 0 )
goto V_181;
}
return 0 ;
V_181:
F_24 ( V_2 ) ;
V_87 = - V_63 ;
return V_63 ;
}
int F_167 ( struct V_1 * V_2 , struct V_153 * V_153 ,
const char * V_182 [] , bool V_183 ,
void (* F_168)( int V_184 , T_15 * V_185 , void * V_186 ) )
{
int V_187 [ 2 ] , V_188 [ 2 ] ;
char V_189 ;
if ( F_169 ( V_187 ) < 0 ) {
perror ( L_13 ) ;
return - 1 ;
}
if ( F_169 ( V_188 ) < 0 ) {
perror ( L_14 ) ;
goto V_190;
}
V_2 -> V_12 . V_13 = F_170 () ;
if ( V_2 -> V_12 . V_13 < 0 ) {
perror ( L_15 ) ;
goto V_191;
}
if ( ! V_2 -> V_12 . V_13 ) {
int V_84 ;
if ( V_183 )
F_171 ( 2 , 1 ) ;
signal ( V_192 , V_193 ) ;
F_42 ( V_187 [ 0 ] ) ;
F_42 ( V_188 [ 1 ] ) ;
F_75 ( V_188 [ 0 ] , V_194 , V_195 ) ;
F_42 ( V_187 [ 1 ] ) ;
V_84 = F_91 ( V_188 [ 0 ] , & V_189 , 1 ) ;
if ( V_84 != 1 ) {
if ( V_84 == - 1 )
perror ( L_16 ) ;
exit ( V_84 ) ;
}
F_172 ( V_182 [ 0 ] , ( char * * ) V_182 ) ;
if ( F_168 ) {
union V_196 V_138 ;
V_138 . V_197 = V_87 ;
if ( F_173 ( F_174 () , V_198 , V_138 ) )
perror ( V_182 [ 0 ] ) ;
} else
perror ( V_182 [ 0 ] ) ;
exit ( - 1 ) ;
}
if ( F_168 ) {
struct V_199 V_200 = {
. V_201 = V_202 ,
. V_203 = F_168 ,
} ;
V_199 ( V_198 , & V_200 , NULL ) ;
}
if ( F_175 ( V_153 ) ) {
if ( V_2 -> V_6 == NULL ) {
fprintf ( V_115 , L_17 ,
V_204 , __LINE__ ) ;
goto V_191;
}
F_176 ( V_2 -> V_6 , 0 , V_2 -> V_12 . V_13 ) ;
}
F_42 ( V_187 [ 1 ] ) ;
F_42 ( V_188 [ 0 ] ) ;
if ( F_91 ( V_187 [ 0 ] , & V_189 , 1 ) == - 1 ) {
perror ( L_16 ) ;
goto V_191;
}
F_75 ( V_188 [ 1 ] , V_194 , V_195 ) ;
V_2 -> V_12 . V_205 = V_188 [ 1 ] ;
F_42 ( V_187 [ 0 ] ) ;
return 0 ;
V_191:
F_42 ( V_188 [ 0 ] ) ;
F_42 ( V_188 [ 1 ] ) ;
V_190:
F_42 ( V_187 [ 0 ] ) ;
F_42 ( V_187 [ 1 ] ) ;
return - 1 ;
}
int F_177 ( struct V_1 * V_2 )
{
if ( V_2 -> V_12 . V_205 > 0 ) {
char V_189 = 0 ;
int V_84 ;
V_84 = F_178 ( V_2 -> V_12 . V_205 , & V_189 , 1 ) ;
if ( V_84 < 0 )
perror ( L_18 ) ;
F_42 ( V_2 -> V_12 . V_205 ) ;
return V_84 ;
}
return 0 ;
}
int F_179 ( struct V_1 * V_2 , union V_97 * V_98 ,
struct V_170 * V_100 )
{
struct V_14 * V_18 = F_100 ( V_2 , V_98 ) ;
if ( ! V_18 )
return - V_206 ;
return F_180 ( V_18 , V_98 , V_100 ) ;
}
T_1 F_181 ( struct V_1 * V_2 , T_16 * V_207 )
{
struct V_14 * V_18 ;
T_1 V_208 = 0 ;
F_14 (evlist, evsel) {
V_208 += fprintf ( V_207 , L_19 , V_18 -> V_27 ? L_20 : L_21 ,
F_182 ( V_18 ) ) ;
}
return V_208 + fprintf ( V_207 , L_22 ) ;
}
int F_183 ( struct V_1 * V_2 V_122 ,
int V_63 , char * V_209 , T_1 V_102 )
{
int V_208 , V_148 ;
char V_210 [ V_211 ] , * V_212 = F_184 ( V_63 , V_210 , sizeof( V_210 ) ) ;
switch ( V_63 ) {
case V_213 :
case V_214 :
V_208 = F_185 ( V_209 , V_102 ,
L_23
L_24 , V_212 ) ;
V_148 = F_186 () ;
V_208 += F_185 ( V_209 + V_208 , V_102 - V_208 , L_25 ) ;
if ( V_148 >= 2 ) {
V_208 += F_185 ( V_209 + V_208 , V_102 - V_208 ,
L_26 ) ;
}
V_208 += F_185 ( V_209 + V_208 , V_102 - V_208 ,
L_27 ) ;
V_208 += F_185 ( V_209 + V_208 , V_102 - V_208 ,
L_28
L_29 , V_148 ) ;
break;
default:
F_185 ( V_209 , V_102 , L_30 , V_212 ) ;
break;
}
return 0 ;
}
int F_187 ( struct V_1 * V_2 , int V_63 , char * V_209 , T_1 V_102 )
{
char V_210 [ V_211 ] , * V_212 = F_184 ( V_63 , V_210 , sizeof( V_210 ) ) ;
int V_215 = V_2 -> V_124 / 1024 , V_216 , V_208 = 0 ;
switch ( V_63 ) {
case V_214 :
F_126 ( L_7 , & V_216 ) ;
V_208 += F_185 ( V_209 + V_208 , V_102 - V_208 ,
L_23
L_31
L_32 ,
V_212 , V_216 , V_215 ) ;
if ( V_215 >= V_216 ) {
V_208 += F_185 ( V_209 + V_208 , V_102 - V_208 ,
L_33 ,
V_216 + V_215 ) ;
}
V_208 += F_185 ( V_209 + V_208 , V_102 - V_208 ,
L_34 ) ;
break;
default:
F_185 ( V_209 , V_102 , L_30 , V_212 ) ;
break;
}
return 0 ;
}
void F_188 ( struct V_1 * V_2 ,
struct V_14 * V_217 )
{
struct V_14 * V_18 , * V_20 ;
F_47 ( V_218 ) ;
if ( V_217 == F_12 ( V_2 ) )
return;
F_17 (evlist, n, evsel) {
if ( V_18 -> V_32 == V_217 -> V_32 )
F_189 ( & V_18 -> V_21 , & V_218 ) ;
}
F_190 ( & V_218 , & V_2 -> V_10 ) ;
}
void F_191 ( struct V_1 * V_2 ,
struct V_14 * V_219 )
{
struct V_14 * V_18 ;
if ( V_219 -> V_28 )
return;
F_14 (evlist, evsel) {
if ( V_18 != V_219 )
V_18 -> V_28 = false ;
}
V_219 -> V_28 = true ;
}
