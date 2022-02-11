static struct V_1 * F_1 ( struct V_2 * V_3 , int V_4 )
{
struct V_1 * V_5 = V_3 -> V_6 ;
while ( V_5 ) {
if ( V_5 -> V_4 == V_4 )
return V_5 ;
V_5 = V_5 -> V_7 ;
}
V_5 = F_2 ( sizeof( * V_5 ) ) ;
assert ( V_5 != NULL ) ;
V_5 -> V_4 = V_4 ;
V_5 -> V_7 = V_3 -> V_6 ;
V_3 -> V_6 = V_5 ;
return V_5 ;
}
static void F_3 ( struct V_2 * V_3 , int V_4 , char * V_8 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
V_9 = F_1 ( V_3 , V_4 ) ;
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( V_11 -> V_8 && strcmp ( V_11 -> V_8 , V_8 ) == 0 ) {
V_9 -> V_13 = V_11 ;
return;
}
if ( ! V_11 -> V_8 ) {
V_11 -> V_8 = F_4 ( V_8 ) ;
V_9 -> V_13 = V_11 ;
return;
}
V_11 = V_11 -> V_7 ;
}
V_11 = F_2 ( sizeof( * V_11 ) ) ;
assert ( V_11 != NULL ) ;
V_11 -> V_8 = F_4 ( V_8 ) ;
V_9 -> V_13 = V_11 ;
V_11 -> V_7 = V_9 -> V_12 ;
V_9 -> V_12 = V_11 ;
}
static void F_5 ( struct V_2 * V_3 , int V_4 , int V_14 , T_1 V_15 )
{
struct V_1 * V_9 , * V_16 ;
V_9 = F_1 ( V_3 , V_4 ) ;
V_16 = F_1 ( V_3 , V_14 ) ;
V_9 -> V_14 = V_14 ;
if ( V_16 -> V_13 && V_16 -> V_13 -> V_8 && ! V_9 -> V_13 )
F_3 ( V_3 , V_4 , V_16 -> V_13 -> V_8 ) ;
V_9 -> V_17 = V_15 ;
if ( V_9 -> V_13 && ! V_9 -> V_13 -> V_17 ) {
V_9 -> V_13 -> V_17 = V_15 ;
V_9 -> V_13 -> V_18 = V_15 ;
}
}
static void F_6 ( struct V_2 * V_3 , int V_4 , T_1 V_15 )
{
struct V_1 * V_9 ;
V_9 = F_1 ( V_3 , V_4 ) ;
V_9 -> V_19 = V_15 ;
if ( V_9 -> V_13 )
V_9 -> V_13 -> V_19 = V_15 ;
}
static void F_7 ( struct V_2 * V_3 , int V_4 , int type ,
unsigned int V_20 , T_1 V_21 , T_1 V_22 ,
const char * V_23 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
struct V_24 * V_25 ;
V_9 = F_1 ( V_3 , V_4 ) ;
V_11 = V_9 -> V_13 ;
if ( ! V_11 ) {
V_11 = F_2 ( sizeof( * V_11 ) ) ;
assert ( V_11 != NULL ) ;
V_9 -> V_13 = V_11 ;
V_11 -> V_7 = V_9 -> V_12 ;
V_9 -> V_12 = V_11 ;
}
V_25 = F_2 ( sizeof( * V_25 ) ) ;
assert ( V_25 != NULL ) ;
V_25 -> V_17 = V_21 ;
V_25 -> V_19 = V_22 ;
V_25 -> type = type ;
V_25 -> V_7 = V_11 -> V_26 ;
V_25 -> V_20 = V_20 ;
V_25 -> V_23 = V_23 ;
V_11 -> V_26 = V_25 ;
if ( V_25 -> type == V_27 && V_22 > V_21 && V_21 > 0 ) {
V_11 -> V_28 += ( V_22 - V_21 ) ;
V_9 -> V_28 += ( V_22 - V_21 ) ;
}
if ( V_11 -> V_17 == 0 || V_11 -> V_17 > V_21 )
V_11 -> V_17 = V_21 ;
if ( V_9 -> V_17 == 0 || V_9 -> V_17 > V_21 )
V_9 -> V_17 = V_21 ;
}
static int F_8 ( struct V_29 * V_30 ,
union V_31 * V_32 ,
struct V_33 * V_25 V_34 ,
struct V_35 * V_35 V_34 )
{
struct V_2 * V_3 = F_9 ( V_30 , struct V_2 , V_30 ) ;
F_3 ( V_3 , V_32 -> V_8 . V_36 , V_32 -> V_8 . V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_29 * V_30 ,
union V_31 * V_32 ,
struct V_33 * V_25 V_34 ,
struct V_35 * V_35 V_34 )
{
struct V_2 * V_3 = F_9 ( V_30 , struct V_2 , V_30 ) ;
F_5 ( V_3 , V_32 -> V_37 . V_4 , V_32 -> V_37 . V_14 , V_32 -> V_37 . time ) ;
return 0 ;
}
static int F_11 ( struct V_29 * V_30 ,
union V_31 * V_32 ,
struct V_33 * V_25 V_34 ,
struct V_35 * V_35 V_34 )
{
struct V_2 * V_3 = F_9 ( V_30 , struct V_2 , V_30 ) ;
F_6 ( V_3 , V_32 -> V_37 . V_4 , V_32 -> V_37 . time ) ;
return 0 ;
}
static void F_12 ( int V_20 , T_1 V_15 , int V_38 )
{
V_39 [ V_20 ] = V_15 ;
V_40 [ V_20 ] = V_38 ;
}
static void F_13 ( struct V_2 * V_3 , int V_20 , T_1 V_15 )
{
struct V_41 * V_42 = F_2 ( sizeof( * V_42 ) ) ;
if ( ! V_42 )
return;
V_42 -> V_38 = V_40 [ V_20 ] ;
V_42 -> V_17 = V_39 [ V_20 ] ;
V_42 -> V_19 = V_15 ;
V_42 -> V_20 = V_20 ;
V_42 -> type = V_43 ;
V_42 -> V_7 = V_3 -> V_44 ;
V_3 -> V_44 = V_42 ;
}
static void F_14 ( struct V_2 * V_3 , int V_20 , T_1 V_15 , T_1 V_45 )
{
struct V_41 * V_42 ;
if ( V_45 > 8000000 )
return;
V_42 = F_2 ( sizeof( * V_42 ) ) ;
if ( ! V_42 )
return;
V_42 -> V_38 = V_46 [ V_20 ] ;
V_42 -> V_17 = V_47 [ V_20 ] ;
V_42 -> V_19 = V_15 ;
V_42 -> V_20 = V_20 ;
V_42 -> type = V_48 ;
V_42 -> V_7 = V_3 -> V_44 ;
if ( ! V_42 -> V_17 )
V_42 -> V_17 = V_3 -> V_49 ;
V_3 -> V_44 = V_42 ;
V_46 [ V_20 ] = V_45 ;
V_47 [ V_20 ] = V_15 ;
if ( ( T_1 ) V_45 > V_3 -> V_50 )
V_3 -> V_50 = V_45 ;
if ( V_45 < V_3 -> V_51 || V_3 -> V_51 == 0 )
V_3 -> V_51 = V_45 ;
if ( V_45 == V_3 -> V_50 - 1000 )
V_3 -> V_52 = V_3 -> V_50 ;
}
static void F_15 ( struct V_2 * V_3 , int V_20 , T_1 V_15 ,
int V_53 , int V_54 , T_2 V_55 , const char * V_23 )
{
struct V_1 * V_9 ;
struct V_56 * V_57 = F_2 ( sizeof( * V_57 ) ) ;
if ( ! V_57 )
return;
V_57 -> time = V_15 ;
V_57 -> V_53 = V_53 ;
V_57 -> V_23 = V_23 ;
if ( ( V_55 & V_58 ) || ( V_55 & V_59 ) )
V_57 -> V_53 = - 1 ;
V_57 -> V_54 = V_54 ;
V_57 -> V_7 = V_3 -> V_60 ;
V_3 -> V_60 = V_57 ;
V_9 = F_1 ( V_3 , V_57 -> V_54 ) ;
if ( V_9 && V_9 -> V_13 && V_9 -> V_13 -> V_38 == V_61 ) {
V_9 -> V_13 -> V_18 = V_15 ;
V_9 -> V_13 -> V_38 = V_62 ;
}
if ( V_9 && V_9 -> V_13 && V_9 -> V_13 -> V_38 == V_63 ) {
F_7 ( V_3 , V_9 -> V_4 , V_9 -> V_13 -> V_38 , V_20 ,
V_9 -> V_13 -> V_18 , V_15 , NULL ) ;
V_9 -> V_13 -> V_18 = V_15 ;
V_9 -> V_13 -> V_38 = V_62 ;
}
}
static void F_16 ( struct V_2 * V_3 , int V_20 , T_1 V_15 ,
int V_64 , int V_65 , T_1 V_66 ,
const char * V_23 )
{
struct V_1 * V_9 = NULL , * V_67 ;
V_67 = F_1 ( V_3 , V_64 ) ;
V_9 = F_1 ( V_3 , V_65 ) ;
if ( V_67 -> V_13 && V_67 -> V_13 -> V_38 != V_61 )
F_7 ( V_3 , V_64 , V_27 , V_20 ,
V_67 -> V_13 -> V_18 , V_15 ,
V_23 ) ;
if ( V_9 && V_9 -> V_13 ) {
if ( V_9 -> V_13 -> V_38 != V_61 )
F_7 ( V_3 , V_65 , V_9 -> V_13 -> V_38 , V_20 ,
V_9 -> V_13 -> V_18 , V_15 ,
V_23 ) ;
V_9 -> V_13 -> V_18 = V_15 ;
V_9 -> V_13 -> V_38 = V_27 ;
}
if ( V_67 -> V_13 ) {
V_67 -> V_13 -> V_38 = V_61 ;
V_67 -> V_13 -> V_18 = V_15 ;
if ( V_66 & 2 )
V_67 -> V_13 -> V_38 = V_63 ;
if ( V_66 == 0 )
V_67 -> V_13 -> V_38 = V_62 ;
}
}
static const char * F_17 ( union V_31 * V_32 ,
struct V_33 * V_25 ,
struct V_35 * V_35 )
{
struct V_68 V_69 ;
unsigned int V_70 ;
char * V_9 = NULL ;
T_3 V_71 ;
T_2 V_72 = V_73 ;
struct V_68 V_74 ;
struct V_75 * V_76 = V_25 -> V_77 ;
T_4 * V_78 = F_18 ( & V_9 , & V_71 ) ;
if ( ! V_78 ) {
perror ( L_1 ) ;
return NULL ;
}
if ( ! V_76 )
goto exit;
if ( F_19 ( V_35 , & V_69 , V_25 ) < 0 ) {
fprintf ( V_79 , L_2 ,
V_32 -> V_80 . type ) ;
goto exit;
}
for ( V_70 = 0 ; V_70 < V_76 -> V_81 ; V_70 ++ ) {
T_1 V_82 ;
if ( V_83 . V_84 == V_85 )
V_82 = V_76 -> V_86 [ V_70 ] ;
else
V_82 = V_76 -> V_86 [ V_76 -> V_81 - V_70 - 1 ] ;
if ( V_82 >= V_87 ) {
switch ( V_82 ) {
case V_88 :
V_72 = V_89 ;
break;
case V_90 :
V_72 = V_91 ;
break;
case V_92 :
V_72 = V_73 ;
break;
default:
F_20 ( L_3
L_4 V_93 L_5 , ( V_94 ) V_82 ) ;
F_21 ( & V_9 ) ;
goto V_95;
}
continue;
}
V_74 . V_96 = 0 ;
F_22 ( V_69 . V_97 , V_72 ,
V_98 , V_82 , & V_74 ) ;
if ( V_74 . V_99 )
fprintf ( V_78 , L_6 V_100 L_7 , V_82 ,
V_74 . V_99 -> V_101 ) ;
else
fprintf ( V_78 , L_6 V_100 L_5 , V_82 ) ;
}
V_95:
F_23 ( & V_69 ) ;
exit:
fclose ( V_78 ) ;
return V_9 ;
}
static int F_24 ( struct V_29 * V_30 ,
union V_31 * V_32 ,
struct V_33 * V_25 ,
struct V_102 * V_103 ,
struct V_35 * V_35 )
{
struct V_2 * V_3 = F_9 ( V_30 , struct V_2 , V_30 ) ;
if ( V_103 -> V_104 . V_105 & V_106 ) {
if ( ! V_3 -> V_49 || V_3 -> V_49 > V_25 -> time )
V_3 -> V_49 = V_25 -> time ;
if ( V_3 -> V_107 < V_25 -> time )
V_3 -> V_107 = V_25 -> time ;
}
if ( V_103 -> V_108 != NULL ) {
T_5 V_78 = V_103 -> V_108 ;
return V_78 ( V_3 , V_103 , V_25 ,
F_17 ( V_32 , V_25 , V_35 ) ) ;
}
return 0 ;
}
static int
F_25 ( struct V_2 * V_3 V_34 ,
struct V_102 * V_103 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_6 V_38 = F_26 ( V_103 , V_25 , L_8 ) ;
T_6 V_109 = F_26 ( V_103 , V_25 , L_9 ) ;
if ( V_38 == ( T_6 ) V_110 )
F_13 ( V_3 , V_109 , V_25 -> time ) ;
else
F_12 ( V_109 , V_25 -> time , V_38 ) ;
return 0 ;
}
static int
F_27 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_6 V_38 = F_26 ( V_103 , V_25 , L_8 ) ;
T_6 V_109 = F_26 ( V_103 , V_25 , L_9 ) ;
F_14 ( V_3 , V_109 , V_25 -> time , V_38 ) ;
return 0 ;
}
static int
F_28 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 ,
const char * V_23 )
{
T_2 V_55 = F_26 ( V_103 , V_25 , L_10 ) ;
int V_53 = F_26 ( V_103 , V_25 , L_11 ) ;
int V_54 = F_26 ( V_103 , V_25 , L_12 ) ;
F_15 ( V_3 , V_25 -> V_20 , V_25 -> time , V_53 , V_54 , V_55 , V_23 ) ;
return 0 ;
}
static int
F_29 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 ,
const char * V_23 )
{
int V_64 = F_26 ( V_103 , V_25 , L_13 ) ;
int V_65 = F_26 ( V_103 , V_25 , L_14 ) ;
T_1 V_66 = F_26 ( V_103 , V_25 , L_15 ) ;
F_16 ( V_3 , V_25 -> V_20 , V_25 -> time , V_64 , V_65 ,
V_66 , V_23 ) ;
return 0 ;
}
static int
F_30 ( struct V_2 * V_3 V_34 ,
struct V_102 * V_103 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_1 V_109 = F_26 ( V_103 , V_25 , L_9 ) ;
T_1 V_111 = F_26 ( V_103 , V_25 , L_16 ) ;
F_12 ( V_109 , V_25 -> time , V_111 ) ;
return 0 ;
}
static int
F_31 ( struct V_2 * V_3 ,
struct V_102 * V_103 V_34 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
F_13 ( V_3 , V_25 -> V_20 , V_25 -> time ) ;
return 0 ;
}
static int
F_32 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_1 V_109 = F_26 ( V_103 , V_25 , L_9 ) ;
T_1 V_111 = F_26 ( V_103 , V_25 , L_16 ) ;
F_14 ( V_3 , V_109 , V_25 -> time , V_111 ) ;
return 0 ;
}
static void F_33 ( struct V_2 * V_3 )
{
T_1 V_20 ;
struct V_41 * V_42 ;
for ( V_20 = 0 ; V_20 <= V_3 -> V_112 ; V_20 ++ ) {
#if 0
pwr = zalloc(sizeof(*pwr));
if (!pwr)
return;
pwr->state = cpus_cstate_state[cpu];
pwr->start_time = cpus_cstate_start_times[cpu];
pwr->end_time = tchart->last_time;
pwr->cpu = cpu;
pwr->type = CSTATE;
pwr->next = tchart->power_events;
tchart->power_events = pwr;
#endif
V_42 = F_2 ( sizeof( * V_42 ) ) ;
if ( ! V_42 )
return;
V_42 -> V_38 = V_46 [ V_20 ] ;
V_42 -> V_17 = V_47 [ V_20 ] ;
V_42 -> V_19 = V_3 -> V_107 ;
V_42 -> V_20 = V_20 ;
V_42 -> type = V_48 ;
V_42 -> V_7 = V_3 -> V_44 ;
if ( ! V_42 -> V_17 )
V_42 -> V_17 = V_3 -> V_49 ;
if ( ! V_42 -> V_38 )
V_42 -> V_38 = V_3 -> V_51 ;
V_3 -> V_44 = V_42 ;
}
}
static int F_34 ( struct V_2 * V_3 , int V_4 , int type ,
T_1 V_21 , int V_113 )
{
struct V_1 * V_9 = F_1 ( V_3 , V_4 ) ;
struct V_10 * V_11 = V_9 -> V_13 ;
struct V_114 * V_25 ;
struct V_114 * V_115 ;
if ( ! V_11 ) {
V_11 = F_2 ( sizeof( * V_11 ) ) ;
if ( ! V_11 )
return - V_116 ;
V_9 -> V_13 = V_11 ;
V_11 -> V_7 = V_9 -> V_12 ;
V_9 -> V_12 = V_11 ;
}
V_115 = V_11 -> V_117 ;
if ( V_115 && V_115 -> V_17 && ! V_115 -> V_19 ) {
F_35 ( L_17
L_18 ) ;
V_11 -> V_117 = V_115 -> V_7 ;
free ( V_115 ) ;
return 0 ;
}
V_25 = F_2 ( sizeof( * V_25 ) ) ;
if ( ! V_25 )
return - V_116 ;
V_25 -> V_17 = V_21 ;
V_25 -> type = type ;
V_25 -> V_113 = V_113 ;
V_25 -> V_7 = V_11 -> V_117 ;
V_11 -> V_117 = V_25 ;
if ( V_11 -> V_17 == 0 || V_11 -> V_17 > V_21 )
V_11 -> V_17 = V_21 ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , int V_4 , int type ,
T_1 V_22 , long V_118 )
{
struct V_1 * V_9 = F_1 ( V_3 , V_4 ) ;
struct V_10 * V_11 = V_9 -> V_13 ;
struct V_114 * V_25 , * V_115 ;
if ( ! V_11 ) {
F_35 ( L_19 ) ;
return - 1 ;
}
V_25 = V_11 -> V_117 ;
if ( ! V_25 )
return 0 ;
if ( V_25 -> V_19 ) {
F_35 ( L_20
L_21 ) ;
return 0 ;
}
if ( V_25 -> type != type ) {
F_35 ( L_22 ) ;
return 0 ;
}
V_25 -> V_19 = V_22 ;
V_115 = V_25 -> V_7 ;
if ( V_25 -> V_19 - V_25 -> V_17 < V_3 -> V_119 )
V_25 -> V_19 = V_25 -> V_17 + V_3 -> V_119 ;
if ( V_115 && V_25 -> V_17 < V_115 -> V_19 ) {
if ( V_115 -> V_120 )
V_25 -> V_17 = V_115 -> V_19 ;
else
V_115 -> V_19 = V_25 -> V_17 ;
}
if ( V_118 < 0 ) {
V_25 -> V_120 = V_118 ;
} else if ( type == V_121 || type == V_122 ||
type == V_123 || type == V_124 ) {
if ( ( T_1 ) V_118 > V_11 -> V_125 )
V_11 -> V_125 = V_118 ;
V_11 -> V_126 += V_118 ;
V_9 -> V_126 += V_118 ;
V_25 -> V_127 = V_118 ;
}
if ( V_115 &&
V_115 -> type == V_25 -> type &&
V_115 -> V_120 == V_25 -> V_120 &&
V_115 -> V_113 == V_25 -> V_113 &&
V_115 -> V_19 + V_3 -> V_128 >= V_25 -> V_17 ) {
V_25 -> V_127 += V_115 -> V_127 ;
V_25 -> V_129 += V_115 -> V_129 + 1 ;
V_25 -> V_17 = V_115 -> V_17 ;
V_25 -> V_7 = V_115 -> V_7 ;
free ( V_115 ) ;
if ( ! V_25 -> V_120 && V_25 -> V_127 > V_11 -> V_125 )
V_11 -> V_125 = V_25 -> V_127 ;
}
V_3 -> V_130 ++ ;
return 0 ;
}
static int
F_37 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_113 = F_26 ( V_103 , V_25 , L_23 ) ;
return F_34 ( V_3 , V_25 -> V_36 , V_121 ,
V_25 -> time , V_113 ) ;
}
static int
F_38 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_118 = F_26 ( V_103 , V_25 , L_24 ) ;
return F_36 ( V_3 , V_25 -> V_36 , V_121 ,
V_25 -> time , V_118 ) ;
}
static int
F_39 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_113 = F_26 ( V_103 , V_25 , L_23 ) ;
return F_34 ( V_3 , V_25 -> V_36 , V_122 ,
V_25 -> time , V_113 ) ;
}
static int
F_40 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_118 = F_26 ( V_103 , V_25 , L_24 ) ;
return F_36 ( V_3 , V_25 -> V_36 , V_122 ,
V_25 -> time , V_118 ) ;
}
static int
F_41 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_113 = F_26 ( V_103 , V_25 , L_23 ) ;
return F_34 ( V_3 , V_25 -> V_36 , V_131 ,
V_25 -> time , V_113 ) ;
}
static int
F_42 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_118 = F_26 ( V_103 , V_25 , L_24 ) ;
return F_36 ( V_3 , V_25 -> V_36 , V_131 ,
V_25 -> time , V_118 ) ;
}
static int
F_43 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_113 = F_26 ( V_103 , V_25 , L_23 ) ;
return F_34 ( V_3 , V_25 -> V_36 , V_123 ,
V_25 -> time , V_113 ) ;
}
static int
F_44 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_118 = F_26 ( V_103 , V_25 , L_24 ) ;
return F_36 ( V_3 , V_25 -> V_36 , V_123 ,
V_25 -> time , V_118 ) ;
}
static int
F_45 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_113 = F_26 ( V_103 , V_25 , L_23 ) ;
return F_34 ( V_3 , V_25 -> V_36 , V_124 ,
V_25 -> time , V_113 ) ;
}
static int
F_46 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_118 = F_26 ( V_103 , V_25 , L_24 ) ;
return F_36 ( V_3 , V_25 -> V_36 , V_124 ,
V_25 -> time , V_118 ) ;
}
static int
F_47 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_113 = F_26 ( V_103 , V_25 , L_23 ) ;
return F_34 ( V_3 , V_25 -> V_36 , V_132 ,
V_25 -> time , V_113 ) ;
}
static int
F_48 ( struct V_2 * V_3 ,
struct V_102 * V_103 ,
struct V_33 * V_25 )
{
long V_118 = F_26 ( V_103 , V_25 , L_24 ) ;
return F_36 ( V_3 , V_25 -> V_36 , V_132 ,
V_25 -> time , V_118 ) ;
}
static void F_49 ( struct V_2 * V_3 )
{
struct V_1 * V_133 , * V_9 , * V_5 , * V_115 ;
V_133 = NULL ;
while ( V_3 -> V_6 ) {
V_9 = V_3 -> V_6 ;
V_3 -> V_6 = V_9 -> V_7 ;
V_9 -> V_7 = NULL ;
if ( V_133 == NULL ) {
V_133 = V_9 ;
V_9 -> V_7 = NULL ;
continue;
}
V_115 = NULL ;
V_5 = V_133 ;
while ( V_5 ) {
if ( V_5 -> V_14 > V_9 -> V_14 ||
( V_5 -> V_14 == V_9 -> V_14 && V_5 -> V_4 > V_9 -> V_4 ) ) {
if ( V_115 ) {
V_9 -> V_7 = V_115 -> V_7 ;
V_115 -> V_7 = V_9 ;
V_5 = NULL ;
continue;
} else {
V_9 -> V_7 = V_133 ;
V_133 = V_9 ;
V_5 = NULL ;
continue;
}
}
V_115 = V_5 ;
V_5 = V_5 -> V_7 ;
if ( ! V_5 )
V_115 -> V_7 = V_9 ;
}
}
V_3 -> V_6 = V_133 ;
}
static void F_50 ( struct V_2 * V_3 )
{
struct V_41 * V_42 ;
V_42 = V_3 -> V_44 ;
while ( V_42 ) {
if ( V_42 -> type == V_43 )
F_51 ( V_42 -> V_20 , V_42 -> V_17 , V_42 -> V_19 , V_42 -> V_38 ) ;
V_42 = V_42 -> V_7 ;
}
V_42 = V_3 -> V_44 ;
while ( V_42 ) {
if ( V_42 -> type == V_48 ) {
if ( ! V_42 -> V_38 )
V_42 -> V_38 = V_3 -> V_51 ;
F_52 ( V_42 -> V_20 , V_42 -> V_17 , V_42 -> V_19 , V_42 -> V_38 ) ;
}
V_42 = V_42 -> V_7 ;
}
}
static void F_53 ( struct V_2 * V_3 )
{
struct V_56 * V_57 ;
struct V_1 * V_9 ;
struct V_10 * V_11 ;
V_57 = V_3 -> V_60 ;
while ( V_57 ) {
int V_134 = 0 , V_135 = 0 ;
char * V_136 = NULL , * V_137 = NULL ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
if ( V_9 -> V_4 == V_57 -> V_53 || V_9 -> V_4 == V_57 -> V_54 ) {
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( V_11 -> V_138 && V_11 -> V_17 <= V_57 -> time && V_11 -> V_19 >= V_57 -> time ) {
if ( V_9 -> V_4 == V_57 -> V_53 && ! V_134 ) {
V_134 = V_11 -> V_138 ;
V_136 = F_4 ( V_11 -> V_8 ) ;
}
if ( V_9 -> V_4 == V_57 -> V_54 && ! V_135 ) {
V_135 = V_11 -> V_138 ;
V_137 = F_4 ( V_11 -> V_8 ) ;
}
}
V_11 = V_11 -> V_7 ;
}
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( V_9 -> V_4 == V_57 -> V_53 && ! V_134 ) {
V_134 = V_11 -> V_138 ;
V_136 = F_4 ( V_11 -> V_8 ) ;
}
if ( V_9 -> V_4 == V_57 -> V_54 && ! V_135 ) {
V_135 = V_11 -> V_138 ;
V_137 = F_4 ( V_11 -> V_8 ) ;
}
V_11 = V_11 -> V_7 ;
}
}
V_9 = V_9 -> V_7 ;
}
if ( ! V_136 ) {
V_136 = malloc ( 40 ) ;
sprintf ( V_136 , L_25 , V_57 -> V_53 ) ;
}
if ( ! V_137 ) {
V_137 = malloc ( 40 ) ;
sprintf ( V_137 , L_25 , V_57 -> V_54 ) ;
}
if ( V_57 -> V_53 == - 1 )
F_54 ( V_57 -> time , V_135 , V_57 -> V_23 ) ;
else if ( V_134 && V_135 && abs ( V_134 - V_135 ) == 1 )
F_55 ( V_57 -> time , V_134 , V_135 , V_57 -> V_23 ) ;
else
F_56 ( V_57 -> time , V_134 , V_136 , V_135 ,
V_137 , V_57 -> V_23 ) ;
V_57 = V_57 -> V_7 ;
free ( V_136 ) ;
free ( V_137 ) ;
}
}
static void F_57 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
struct V_24 * V_25 ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
V_25 = V_11 -> V_26 ;
while ( V_25 ) {
if ( V_25 -> type == V_27 ) {
F_58 ( V_25 -> V_20 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_9 -> V_4 ,
V_11 -> V_8 ,
V_25 -> V_23 ) ;
}
V_25 = V_25 -> V_7 ;
}
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
}
static void F_59 ( struct V_2 * V_3 )
{
const char * V_139 ;
double V_127 ;
char V_8 [ 256 ] ;
struct V_1 * V_9 ;
struct V_10 * V_11 ;
struct V_114 * V_25 ;
int V_138 = 1 ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( ! V_11 -> V_140 ) {
V_11 -> V_138 = 0 ;
V_11 = V_11 -> V_7 ;
continue;
}
F_60 ( V_138 , V_11 -> V_17 , V_11 -> V_19 , L_26 ) ;
V_25 = V_11 -> V_117 ;
for ( V_25 = V_11 -> V_117 ; V_25 ; V_25 = V_25 -> V_7 ) {
double V_141 = ( double ) V_25 -> V_127 / V_11 -> V_125 ;
if ( V_3 -> V_142 &&
V_25 -> V_120 == - V_143 )
continue;
if ( V_25 -> V_120 )
V_141 = 1 ;
if ( V_25 -> type == V_131 )
F_61 ( V_138 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
1 ,
V_25 -> V_120 ? L_27 : L_28 ,
V_25 -> V_113 ,
V_25 -> V_120 ,
V_25 -> V_129 ) ;
else if ( V_25 -> type == V_132 )
F_61 ( V_138 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
1 ,
V_25 -> V_120 ? L_27 : L_29 ,
V_25 -> V_113 ,
V_25 -> V_120 ,
V_25 -> V_129 ) ;
else if ( V_25 -> type == V_121 )
F_62 ( V_138 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_141 ,
V_25 -> V_120 ? L_27 : L_30 ,
V_25 -> V_113 ,
V_25 -> V_120 ,
V_25 -> V_129 ) ;
else if ( V_25 -> type == V_122 )
F_63 ( V_138 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_141 ,
V_25 -> V_120 ? L_27 : L_30 ,
V_25 -> V_113 ,
V_25 -> V_120 ,
V_25 -> V_129 ) ;
else if ( V_25 -> type == V_124 )
F_62 ( V_138 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_141 ,
V_25 -> V_120 ? L_27 : L_31 ,
V_25 -> V_113 ,
V_25 -> V_120 ,
V_25 -> V_129 ) ;
else if ( V_25 -> type == V_123 )
F_63 ( V_138 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_141 ,
V_25 -> V_120 ? L_27 : L_31 ,
V_25 -> V_113 ,
V_25 -> V_120 ,
V_25 -> V_129 ) ;
}
V_139 = L_32 ;
V_127 = V_11 -> V_126 ;
if ( V_127 > 1024 ) {
V_127 = V_127 / 1024 ;
V_139 = L_33 ;
}
if ( V_127 > 1024 ) {
V_127 = V_127 / 1024 ;
V_139 = L_34 ;
}
if ( V_127 > 1024 ) {
V_127 = V_127 / 1024 ;
V_139 = L_35 ;
}
sprintf ( V_8 , L_36 , V_11 -> V_8 ? : L_32 , V_9 -> V_4 , V_127 , V_139 ) ;
F_64 ( V_138 , V_11 -> V_17 , V_8 ) ;
V_11 -> V_138 = V_138 ;
V_138 ++ ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
}
static void F_65 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
struct V_24 * V_25 ;
int V_138 = 0 ;
V_138 = 2 * V_3 -> V_112 + 2 ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( ! V_11 -> V_140 ) {
V_11 -> V_138 = 0 ;
V_11 = V_11 -> V_7 ;
continue;
}
F_60 ( V_138 , V_11 -> V_17 , V_11 -> V_19 , L_37 ) ;
V_25 = V_11 -> V_26 ;
while ( V_25 ) {
if ( V_25 -> type == V_27 )
F_66 ( V_138 , V_25 -> V_20 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_25 -> V_23 ) ;
if ( V_25 -> type == V_63 )
F_67 ( V_138 , V_25 -> V_20 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_25 -> V_23 ) ;
if ( V_25 -> type == V_62 )
F_68 ( V_138 , V_25 -> V_20 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_25 -> V_23 ) ;
V_25 = V_25 -> V_7 ;
}
if ( V_11 -> V_8 ) {
char V_8 [ 256 ] ;
if ( V_11 -> V_28 > 5000000000 )
sprintf ( V_8 , L_38 , V_11 -> V_8 , V_9 -> V_4 , V_11 -> V_28 / ( double ) V_144 ) ;
else
sprintf ( V_8 , L_39 , V_11 -> V_8 , V_9 -> V_4 , V_11 -> V_28 / ( double ) V_145 ) ;
F_64 ( V_138 , V_11 -> V_17 , V_8 ) ;
}
V_11 -> V_138 = V_138 ;
V_138 ++ ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
}
static void F_69 ( const char * string )
{
int V_4 = F_70 ( string , NULL , 10 ) ;
struct V_146 * V_147 = malloc ( sizeof( * V_147 ) ) ;
if ( ! V_147 )
return;
V_147 -> V_101 = F_4 ( string ) ;
V_147 -> V_4 = V_4 ;
V_147 -> V_7 = V_146 ;
V_146 = V_147 ;
}
static int F_71 ( struct V_1 * V_9 , struct V_10 * V_11 )
{
struct V_146 * V_147 ;
if ( ! V_146 )
return 1 ;
V_147 = V_146 ;
while ( V_147 ) {
if ( V_147 -> V_4 && V_9 -> V_4 == V_147 -> V_4 )
return 1 ;
if ( strcmp ( V_147 -> V_101 , V_11 -> V_8 ) == 0 )
return 1 ;
V_147 = V_147 -> V_7 ;
}
return 0 ;
}
static int F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
int V_148 = 0 ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_9 -> V_140 = 0 ;
if ( V_9 -> V_17 == 1 )
V_9 -> V_17 = V_3 -> V_49 ;
if ( V_9 -> V_19 == 0 )
V_9 -> V_19 = V_3 -> V_107 ;
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
V_11 -> V_140 = 0 ;
if ( V_11 -> V_17 == 1 )
V_11 -> V_17 = V_3 -> V_49 ;
if ( F_71 ( V_9 , V_11 ) ) {
V_11 -> V_140 = 1 ;
V_9 -> V_140 = 1 ;
V_148 ++ ;
}
if ( V_11 -> V_19 == 0 )
V_11 -> V_19 = V_3 -> V_107 ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
return V_148 ;
}
static int F_73 ( struct V_2 * V_3 , T_1 V_149 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
int V_148 = 0 ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_9 -> V_140 = 0 ;
if ( V_9 -> V_17 == 1 )
V_9 -> V_17 = V_3 -> V_49 ;
if ( V_9 -> V_19 == 0 )
V_9 -> V_19 = V_3 -> V_107 ;
if ( V_9 -> V_28 >= V_149 )
V_9 -> V_140 = 1 ;
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
V_11 -> V_140 = 0 ;
if ( V_11 -> V_17 == 1 )
V_11 -> V_17 = V_3 -> V_49 ;
if ( V_11 -> V_28 >= V_149 ) {
V_11 -> V_140 = 1 ;
V_148 ++ ;
}
if ( V_11 -> V_19 == 0 )
V_11 -> V_19 = V_3 -> V_107 ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
return V_148 ;
}
static int F_74 ( struct V_2 * V_2 , T_1 V_149 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
int V_148 = 0 ;
V_9 = V_2 -> V_6 ;
while ( V_9 ) {
if ( V_9 -> V_19 == 0 )
V_9 -> V_19 = V_2 -> V_107 ;
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
V_11 -> V_140 = 0 ;
if ( V_11 -> V_126 >= V_149 ) {
V_11 -> V_140 = 1 ;
V_148 ++ ;
}
if ( V_11 -> V_19 == 0 )
V_11 -> V_19 = V_2 -> V_107 ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
return V_148 ;
}
static void F_75 ( struct V_2 * V_3 , const char * V_150 )
{
T_1 V_70 ;
int V_148 ;
int V_151 = V_3 -> V_130 ? V_152 : V_153 ;
if ( V_3 -> V_154 )
V_3 -> V_155 = 0 ;
do {
if ( V_146 )
V_148 = F_72 ( V_3 ) ;
else if ( V_3 -> V_130 )
V_148 = F_74 ( V_3 , V_151 ) ;
else
V_148 = F_73 ( V_3 , V_151 ) ;
V_151 /= 10 ;
} while ( ! V_146 && V_151 && V_148 < V_3 -> V_155 );
if ( ! V_3 -> V_155 )
V_148 = 0 ;
if ( V_3 -> V_130 ) {
F_76 ( V_150 , 0 , V_148 , V_3 -> V_49 , V_3 -> V_107 ) ;
F_77 ( 0.5 ) ;
F_78 () ;
F_59 ( V_3 ) ;
} else {
F_76 ( V_150 , V_3 -> V_112 , V_148 , V_3 -> V_49 , V_3 -> V_107 ) ;
F_77 ( 0 ) ;
F_79 () ;
for ( V_70 = 0 ; V_70 < V_3 -> V_112 ; V_70 ++ )
F_80 ( V_70 , V_3 -> V_50 , V_3 -> V_52 ) ;
F_57 ( V_3 ) ;
if ( V_3 -> V_155 )
F_65 ( V_3 ) ;
if ( ! V_3 -> V_156 )
F_50 ( V_3 ) ;
if ( V_3 -> V_155 )
F_53 ( V_3 ) ;
}
F_81 () ;
}
static int F_82 ( struct V_157 * T_7 V_34 ,
struct V_158 * V_159 ,
int V_160 ,
int V_113 V_34 ,
void * V_161 )
{
struct V_2 * V_3 = V_161 ;
switch ( V_160 ) {
case V_162 :
V_3 -> V_112 = V_159 -> V_163 . V_164 ;
break;
case V_165 :
if ( ! V_3 -> V_166 )
break;
if ( F_83 ( V_159 -> V_163 . V_167 ,
V_159 -> V_163 . V_168 ,
V_159 -> V_163 . V_169 ,
V_159 -> V_163 . V_170 ) )
fprintf ( V_79 , L_40 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_84 ( struct V_2 * V_3 , const char * V_171 )
{
const struct V_172 V_173 [] = {
{ L_41 , F_25 } ,
{ L_42 , F_27 } ,
{ L_43 , F_28 } ,
{ L_44 , F_29 } ,
#ifdef F_85
{ L_45 , F_30 } ,
{ L_46 , F_31 } ,
{ L_47 , F_32 } ,
#endif
{ L_48 , F_37 } ,
{ L_49 , F_37 } ,
{ L_50 , F_37 } ,
{ L_51 , F_37 } ,
{ L_52 , F_39 } ,
{ L_53 , F_39 } ,
{ L_54 , F_39 } ,
{ L_55 , F_39 } ,
{ L_56 , F_41 } ,
{ L_57 , F_41 } ,
{ L_58 , F_41 } ,
{ L_59 , F_41 } ,
{ L_60 , F_45 } ,
{ L_61 , F_45 } ,
{ L_62 , F_45 } ,
{ L_63 , F_43 } ,
{ L_64 , F_43 } ,
{ L_65 , F_43 } ,
{ L_66 , F_47 } ,
{ L_67 , F_47 } ,
{ L_68 , F_47 } ,
{ L_69 , F_47 } ,
{ L_70 , F_47 } ,
{ L_71 , F_47 } ,
{ L_72 , F_38 } ,
{ L_73 , F_38 } ,
{ L_74 , F_38 } ,
{ L_75 , F_38 } ,
{ L_76 , F_40 } ,
{ L_77 , F_40 } ,
{ L_78 , F_40 } ,
{ L_79 , F_40 } ,
{ L_80 , F_42 } ,
{ L_81 , F_42 } ,
{ L_82 , F_42 } ,
{ L_83 , F_42 } ,
{ L_84 , F_46 } ,
{ L_85 , F_46 } ,
{ L_86 , F_46 } ,
{ L_87 , F_44 } ,
{ L_88 , F_44 } ,
{ L_89 , F_44 } ,
{ L_90 , F_48 } ,
{ L_91 , F_48 } ,
{ L_92 , F_48 } ,
{ L_93 , F_48 } ,
{ L_94 , F_48 } ,
{ L_95 , F_48 } ,
} ;
struct V_174 V_175 = {
. V_176 = V_177 ,
. V_178 = V_179 ,
. V_180 = V_3 -> V_180 ,
} ;
struct V_181 * V_182 = F_86 ( & V_175 , false ,
& V_3 -> V_30 ) ;
int V_118 = - V_183 ;
if ( V_182 == NULL )
return - 1 ;
F_87 ( & V_182 -> V_80 . V_163 ) ;
( void ) F_88 ( & V_182 -> V_80 ,
F_89 ( V_182 -> V_175 ) ,
V_3 ,
F_82 ) ;
if ( ! F_90 ( V_182 , L_96 ) )
goto V_184;
if ( F_91 ( V_182 ,
V_173 ) ) {
F_92 ( L_97 ) ;
goto V_184;
}
V_118 = F_93 ( V_182 ) ;
if ( V_118 )
goto V_184;
F_33 ( V_3 ) ;
F_49 ( V_3 ) ;
F_75 ( V_3 , V_171 ) ;
F_94 ( L_98 ,
( V_3 -> V_107 - V_3 -> V_49 ) / ( double ) V_144 , V_171 ) ;
V_184:
F_95 ( V_182 ) ;
return V_118 ;
}
static int F_96 ( int V_185 , const char * * V_186 )
{
unsigned int V_187 , V_70 ;
const char * * V_188 ;
const char * * V_9 ;
char * V_189 = NULL ;
const char * const V_190 [] = {
L_99 , L_100 , L_101 , L_102 , L_103 ,
} ;
unsigned int V_191 = F_97 ( V_190 ) ;
const char * const V_192 [] = {
L_48 ,
L_49 ,
L_50 ,
L_51 ,
L_52 ,
L_53 ,
L_54 ,
L_55 ,
L_56 ,
L_57 ,
L_58 ,
L_59 ,
L_72 ,
L_73 ,
L_74 ,
L_75 ,
L_76 ,
L_77 ,
L_78 ,
L_79 ,
L_80 ,
L_81 ,
L_82 ,
L_83 ,
} ;
unsigned int V_193 = F_97 ( V_192 ) ;
const char * const V_194 [] = {
L_60 ,
L_61 ,
L_62 ,
L_63 ,
L_64 ,
L_65 ,
L_84 ,
L_85 ,
L_86 ,
L_87 ,
L_88 ,
L_89 ,
} ;
unsigned int V_195 = F_97 ( V_194 ) ;
const char * const V_196 [] = {
L_66 ,
L_67 ,
L_68 ,
L_69 ,
L_70 ,
L_71 ,
L_90 ,
L_91 ,
L_92 ,
L_93 ,
L_94 ,
L_95 ,
} ;
unsigned int V_197 = F_97 ( V_196 ) ;
V_187 = V_191 +
V_193 * 4 +
V_195 * 4 +
V_197 * 4 +
V_185 ;
V_188 = calloc ( V_187 + 1 , sizeof( char * ) ) ;
if ( V_188 == NULL )
return - V_116 ;
if ( F_98 ( & V_189 , L_104 , F_99 () ) < 0 )
return - V_116 ;
V_9 = V_188 ;
for ( V_70 = 0 ; V_70 < V_191 ; V_70 ++ )
* V_9 ++ = F_4 ( V_190 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_193 ; V_70 ++ ) {
if ( ! F_100 ( V_192 [ V_70 ] ) ) {
V_187 -= 4 ;
continue;
}
* V_9 ++ = L_105 ;
* V_9 ++ = F_4 ( V_192 [ V_70 ] ) ;
* V_9 ++ = L_106 ;
* V_9 ++ = V_189 ;
}
for ( V_70 = 0 ; V_70 < V_195 ; V_70 ++ ) {
if ( ! F_100 ( V_194 [ V_70 ] ) ) {
V_187 -= 4 ;
continue;
}
* V_9 ++ = L_105 ;
* V_9 ++ = F_4 ( V_194 [ V_70 ] ) ;
* V_9 ++ = L_106 ;
* V_9 ++ = V_189 ;
}
for ( V_70 = 0 ; V_70 < V_197 ; V_70 ++ ) {
if ( ! F_100 ( V_196 [ V_70 ] ) ) {
V_187 -= 4 ;
continue;
}
* V_9 ++ = L_105 ;
* V_9 ++ = F_4 ( V_196 [ V_70 ] ) ;
* V_9 ++ = L_106 ;
* V_9 ++ = V_189 ;
}
for ( V_70 = 0 ; V_70 < ( unsigned int ) V_185 ; V_70 ++ )
* V_9 ++ = V_186 [ V_70 ] ;
return F_101 ( V_187 , V_188 , NULL ) ;
}
static int F_102 ( struct V_2 * V_3 , int V_185 , const char * * V_186 )
{
unsigned int V_187 , V_70 , V_198 ;
const char * * V_188 ;
const char * * V_9 ;
unsigned int V_199 ;
const char * const V_190 [] = {
L_99 , L_100 , L_101 , L_102 , L_103 ,
} ;
unsigned int V_191 = F_97 ( V_190 ) ;
const char * const V_200 [] = {
L_107 ,
} ;
unsigned int V_201 = F_97 ( V_200 ) ;
const char * const V_202 [] = {
L_105 , L_42 ,
L_105 , L_41 ,
} ;
unsigned int V_203 = F_97 ( V_202 ) ;
const char * const V_204 [] = {
#ifdef F_85
L_105 , L_45 ,
L_105 , L_46 ,
L_105 , L_47 ,
#endif
} ;
unsigned int V_205 = F_97 ( V_204 ) ;
const char * const V_206 [] = {
L_105 , L_43 ,
L_105 , L_44 ,
} ;
unsigned int V_207 = F_97 ( V_206 ) ;
#ifdef F_85
if ( ! F_100 ( L_41 ) &&
F_100 ( L_45 ) ) {
V_208 = 1 ;
V_203 = 0 ;
} else {
V_205 = 0 ;
}
#endif
if ( V_3 -> V_154 )
V_207 = 0 ;
if ( V_3 -> V_156 ) {
V_203 = 0 ;
V_205 = 0 ;
}
if ( ! V_3 -> V_209 )
V_201 = 0 ;
V_199 = V_191 + V_207 +
V_203 + V_205 + V_201 ;
V_187 = V_199 + V_185 ;
V_188 = calloc ( V_187 + 1 , sizeof( char * ) ) ;
if ( V_188 == NULL )
return - V_116 ;
V_9 = V_188 ;
for ( V_70 = 0 ; V_70 < V_191 ; V_70 ++ )
* V_9 ++ = F_4 ( V_190 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_201 ; V_70 ++ )
* V_9 ++ = F_4 ( V_200 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_207 ; V_70 ++ )
* V_9 ++ = F_4 ( V_206 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_203 ; V_70 ++ )
* V_9 ++ = F_4 ( V_202 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_205 ; V_70 ++ )
* V_9 ++ = F_4 ( V_204 [ V_70 ] ) ;
for ( V_198 = 0 ; V_198 < ( unsigned int ) V_185 ; V_198 ++ )
* V_9 ++ = V_186 [ V_198 ] ;
return F_101 ( V_187 , V_188 , NULL ) ;
}
static int
F_103 ( const struct V_210 * T_8 V_34 , const char * V_211 ,
int V_34 V_212 )
{
if ( V_211 )
F_69 ( V_211 ) ;
return 0 ;
}
static int
F_104 ( const struct V_210 * T_8 V_34 , const char * V_211 ,
int V_34 V_212 )
{
unsigned long V_213 = strtoul ( V_211 , NULL , 0 ) ;
if ( V_214 || V_215 )
return - 1 ;
if ( V_213 )
V_214 = V_213 ;
else
V_215 = F_4 ( V_211 ) ;
return 0 ;
}
static int
F_105 ( const struct V_210 * T_8 , const char * V_211 , int V_34 V_212 )
{
char V_216 = 'n' ;
T_1 * V_111 = T_8 -> V_111 ;
if ( sscanf ( V_211 , L_4 V_217 L_108 , V_111 , & V_216 ) > 0 ) {
switch ( V_216 ) {
case 'm' :
* V_111 *= V_145 ;
break;
case 'u' :
* V_111 *= V_218 ;
break;
case 'n' :
break;
default:
return - 1 ;
}
}
return 0 ;
}
int F_106 ( int V_185 , const char * * V_186 ,
const char * T_9 V_34 )
{
struct V_2 V_3 = {
. V_30 = {
. V_8 = F_8 ,
. V_37 = F_10 ,
. exit = F_11 ,
. V_25 = F_24 ,
. V_219 = true ,
} ,
. V_155 = 15 ,
. V_119 = V_145 ,
. V_128 = 1000 ,
} ;
const char * V_171 = L_109 ;
const struct V_210 V_220 [] = {
F_107 ( 'i' , L_110 , & V_177 , L_111 , L_112 ) ,
F_107 ( 'o' , L_113 , & V_171 , L_111 , L_114 ) ,
F_108 ( 'w' , L_115 , & V_221 , L_116 ) ,
F_109 ( 0 , L_117 , NULL , L_118 ,
L_119 ,
F_104 ) ,
F_110 ( 'P' , L_120 , & V_3 . V_154 , L_121 ) ,
F_110 ( 'T' , L_122 , & V_3 . V_156 ,
L_123 ) ,
F_109 ( 'p' , L_37 , NULL , L_37 ,
L_124 ,
F_103 ) ,
F_109 ( 0 , L_125 , NULL , L_126 ,
L_127 ,
V_222 ) ,
F_108 ( 'n' , L_128 , & V_3 . V_155 ,
L_129 ) ,
F_110 ( 't' , L_130 , & V_3 . V_166 ,
L_131 ) ,
F_110 ( 0 , L_132 , & V_3 . V_142 ,
L_133 ) ,
F_109 ( 0 , L_134 , & V_3 . V_119 , L_135 ,
L_136 ,
F_105 ) ,
F_109 ( 0 , L_137 , & V_3 . V_128 , L_135 ,
L_138 ,
F_105 ) ,
F_110 ( 'f' , L_139 , & V_3 . V_180 , L_140 ) ,
F_111 ()
} ;
const char * const V_223 [] = { L_99 , NULL } ;
const char * V_224 [] = {
L_141 ,
NULL
} ;
const struct V_210 V_225 [] = {
F_110 ( 'P' , L_120 , & V_3 . V_154 , L_121 ) ,
F_110 ( 'T' , L_122 , & V_3 . V_156 ,
L_123 ) ,
F_110 ( 'I' , L_142 , & V_3 . V_226 ,
L_143 ) ,
F_110 ( 'g' , L_144 , & V_3 . V_209 , L_145 ) ,
F_111 ()
} ;
const char * const V_227 [] = {
L_146 ,
NULL
} ;
V_185 = F_112 ( V_185 , V_186 , V_220 , V_223 ,
V_224 , V_228 ) ;
if ( V_3 . V_154 && V_3 . V_156 ) {
F_92 ( L_147 ) ;
return - 1 ;
}
if ( V_185 && ! strncmp ( V_186 [ 0 ] , L_148 , 3 ) ) {
V_185 = F_113 ( V_185 , V_186 , V_225 ,
V_227 ,
V_228 ) ;
if ( V_3 . V_154 && V_3 . V_156 ) {
F_92 ( L_147 ) ;
return - 1 ;
}
if ( V_3 . V_226 )
return F_96 ( V_185 , V_186 ) ;
else
return F_102 ( & V_3 , V_185 , V_186 ) ;
} else if ( V_185 )
F_114 ( V_224 , V_220 ) ;
F_115 () ;
return F_84 ( & V_3 , V_171 ) ;
}
