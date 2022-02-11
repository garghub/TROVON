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
if ( V_9 -> V_13 ) {
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
if ( F_19 ( V_32 , V_35 , & V_69 , V_25 ) < 0 ) {
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
goto exit;
}
continue;
}
V_74 . V_95 = false ;
F_22 ( V_69 . V_96 , V_35 , V_72 ,
V_97 , V_82 , & V_74 ) ;
if ( V_74 . V_98 )
fprintf ( V_78 , L_6 V_99 L_7 , V_82 ,
V_74 . V_98 -> V_100 ) ;
else
fprintf ( V_78 , L_6 V_99 L_5 , V_82 ) ;
}
exit:
fclose ( V_78 ) ;
return V_9 ;
}
static int F_23 ( struct V_29 * V_30 ,
union V_31 * V_32 ,
struct V_33 * V_25 ,
struct V_101 * V_102 ,
struct V_35 * V_35 )
{
struct V_2 * V_3 = F_9 ( V_30 , struct V_2 , V_30 ) ;
if ( V_102 -> V_103 . V_104 & V_105 ) {
if ( ! V_3 -> V_49 || V_3 -> V_49 > V_25 -> time )
V_3 -> V_49 = V_25 -> time ;
if ( V_3 -> V_106 < V_25 -> time )
V_3 -> V_106 = V_25 -> time ;
}
if ( V_102 -> V_107 != NULL ) {
T_5 V_78 = V_102 -> V_107 ;
return V_78 ( V_3 , V_102 , V_25 ,
F_17 ( V_32 , V_25 , V_35 ) ) ;
}
return 0 ;
}
static int
F_24 ( struct V_2 * V_3 V_34 ,
struct V_101 * V_102 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_6 V_38 = F_25 ( V_102 , V_25 , L_8 ) ;
T_6 V_108 = F_25 ( V_102 , V_25 , L_9 ) ;
if ( V_38 == ( T_6 ) V_109 )
F_13 ( V_3 , V_108 , V_25 -> time ) ;
else
F_12 ( V_108 , V_25 -> time , V_38 ) ;
return 0 ;
}
static int
F_26 ( struct V_2 * V_3 ,
struct V_101 * V_102 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_6 V_38 = F_25 ( V_102 , V_25 , L_8 ) ;
T_6 V_108 = F_25 ( V_102 , V_25 , L_9 ) ;
F_14 ( V_3 , V_108 , V_25 -> time , V_38 ) ;
return 0 ;
}
static int
F_27 ( struct V_2 * V_3 ,
struct V_101 * V_102 ,
struct V_33 * V_25 ,
const char * V_23 )
{
T_2 V_55 = F_25 ( V_102 , V_25 , L_10 ) ;
int V_53 = F_25 ( V_102 , V_25 , L_11 ) ;
int V_54 = F_25 ( V_102 , V_25 , L_12 ) ;
F_15 ( V_3 , V_25 -> V_20 , V_25 -> time , V_53 , V_54 , V_55 , V_23 ) ;
return 0 ;
}
static int
F_28 ( struct V_2 * V_3 ,
struct V_101 * V_102 ,
struct V_33 * V_25 ,
const char * V_23 )
{
int V_64 = F_25 ( V_102 , V_25 , L_13 ) ;
int V_65 = F_25 ( V_102 , V_25 , L_14 ) ;
T_1 V_66 = F_25 ( V_102 , V_25 , L_15 ) ;
F_16 ( V_3 , V_25 -> V_20 , V_25 -> time , V_64 , V_65 ,
V_66 , V_23 ) ;
return 0 ;
}
static int
F_29 ( struct V_2 * V_3 V_34 ,
struct V_101 * V_102 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_1 V_108 = F_25 ( V_102 , V_25 , L_9 ) ;
T_1 V_110 = F_25 ( V_102 , V_25 , L_16 ) ;
F_12 ( V_108 , V_25 -> time , V_110 ) ;
return 0 ;
}
static int
F_30 ( struct V_2 * V_3 ,
struct V_101 * V_102 V_34 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
F_13 ( V_3 , V_25 -> V_20 , V_25 -> time ) ;
return 0 ;
}
static int
F_31 ( struct V_2 * V_3 ,
struct V_101 * V_102 ,
struct V_33 * V_25 ,
const char * V_23 V_34 )
{
T_1 V_108 = F_25 ( V_102 , V_25 , L_9 ) ;
T_1 V_110 = F_25 ( V_102 , V_25 , L_16 ) ;
F_14 ( V_3 , V_108 , V_25 -> time , V_110 ) ;
return 0 ;
}
static void F_32 ( struct V_2 * V_3 )
{
T_1 V_20 ;
struct V_41 * V_42 ;
for ( V_20 = 0 ; V_20 <= V_3 -> V_111 ; V_20 ++ ) {
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
V_42 -> V_19 = V_3 -> V_106 ;
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
static void F_33 ( struct V_2 * V_3 )
{
struct V_1 * V_112 , * V_9 , * V_5 , * V_113 ;
V_112 = NULL ;
while ( V_3 -> V_6 ) {
V_9 = V_3 -> V_6 ;
V_3 -> V_6 = V_9 -> V_7 ;
V_9 -> V_7 = NULL ;
if ( V_112 == NULL ) {
V_112 = V_9 ;
V_9 -> V_7 = NULL ;
continue;
}
V_113 = NULL ;
V_5 = V_112 ;
while ( V_5 ) {
if ( V_5 -> V_14 > V_9 -> V_14 ||
( V_5 -> V_14 == V_9 -> V_14 && V_5 -> V_4 > V_9 -> V_4 ) ) {
if ( V_113 ) {
V_9 -> V_7 = V_113 -> V_7 ;
V_113 -> V_7 = V_9 ;
V_5 = NULL ;
continue;
} else {
V_9 -> V_7 = V_112 ;
V_112 = V_9 ;
V_5 = NULL ;
continue;
}
}
V_113 = V_5 ;
V_5 = V_5 -> V_7 ;
if ( ! V_5 )
V_113 -> V_7 = V_9 ;
}
}
V_3 -> V_6 = V_112 ;
}
static void F_34 ( struct V_2 * V_3 )
{
struct V_41 * V_42 ;
V_42 = V_3 -> V_44 ;
while ( V_42 ) {
if ( V_42 -> type == V_43 )
F_35 ( V_42 -> V_20 , V_42 -> V_17 , V_42 -> V_19 , V_42 -> V_38 ) ;
V_42 = V_42 -> V_7 ;
}
V_42 = V_3 -> V_44 ;
while ( V_42 ) {
if ( V_42 -> type == V_48 ) {
if ( ! V_42 -> V_38 )
V_42 -> V_38 = V_3 -> V_51 ;
F_36 ( V_42 -> V_20 , V_42 -> V_17 , V_42 -> V_19 , V_42 -> V_38 ) ;
}
V_42 = V_42 -> V_7 ;
}
}
static void F_37 ( struct V_2 * V_3 )
{
struct V_56 * V_57 ;
struct V_1 * V_9 ;
struct V_10 * V_11 ;
V_57 = V_3 -> V_60 ;
while ( V_57 ) {
int V_114 = 0 , V_115 = 0 ;
char * V_116 = NULL , * V_117 = NULL ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
if ( V_9 -> V_4 == V_57 -> V_53 || V_9 -> V_4 == V_57 -> V_54 ) {
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( V_11 -> V_118 && V_11 -> V_17 <= V_57 -> time && V_11 -> V_19 >= V_57 -> time ) {
if ( V_9 -> V_4 == V_57 -> V_53 && ! V_114 ) {
V_114 = V_11 -> V_118 ;
V_116 = F_4 ( V_11 -> V_8 ) ;
}
if ( V_9 -> V_4 == V_57 -> V_54 && ! V_115 ) {
V_115 = V_11 -> V_118 ;
V_117 = F_4 ( V_11 -> V_8 ) ;
}
}
V_11 = V_11 -> V_7 ;
}
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( V_9 -> V_4 == V_57 -> V_53 && ! V_114 ) {
V_114 = V_11 -> V_118 ;
V_116 = F_4 ( V_11 -> V_8 ) ;
}
if ( V_9 -> V_4 == V_57 -> V_54 && ! V_115 ) {
V_115 = V_11 -> V_118 ;
V_117 = F_4 ( V_11 -> V_8 ) ;
}
V_11 = V_11 -> V_7 ;
}
}
V_9 = V_9 -> V_7 ;
}
if ( ! V_116 ) {
V_116 = malloc ( 40 ) ;
sprintf ( V_116 , L_17 , V_57 -> V_53 ) ;
}
if ( ! V_117 ) {
V_117 = malloc ( 40 ) ;
sprintf ( V_117 , L_17 , V_57 -> V_54 ) ;
}
if ( V_57 -> V_53 == - 1 )
F_38 ( V_57 -> time , V_115 , V_57 -> V_23 ) ;
else if ( V_114 && V_115 && abs ( V_114 - V_115 ) == 1 )
F_39 ( V_57 -> time , V_114 , V_115 , V_57 -> V_23 ) ;
else
F_40 ( V_57 -> time , V_114 , V_116 , V_115 ,
V_117 , V_57 -> V_23 ) ;
V_57 = V_57 -> V_7 ;
free ( V_116 ) ;
free ( V_117 ) ;
}
}
static void F_41 ( struct V_2 * V_3 )
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
F_42 ( V_25 -> V_20 ,
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
static void F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
struct V_24 * V_25 ;
int V_118 = 0 ;
V_118 = 2 * V_3 -> V_111 + 2 ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
if ( ! V_11 -> V_119 ) {
V_11 -> V_118 = 0 ;
V_11 = V_11 -> V_7 ;
continue;
}
F_44 ( V_118 , V_11 -> V_17 , V_11 -> V_19 , L_18 ) ;
V_25 = V_11 -> V_26 ;
while ( V_25 ) {
if ( V_25 -> type == V_27 )
F_45 ( V_118 , V_25 -> V_20 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_25 -> V_23 ) ;
if ( V_25 -> type == V_63 )
F_46 ( V_118 , V_25 -> V_20 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_25 -> V_23 ) ;
if ( V_25 -> type == V_62 )
F_47 ( V_118 , V_25 -> V_20 ,
V_25 -> V_17 ,
V_25 -> V_19 ,
V_25 -> V_23 ) ;
V_25 = V_25 -> V_7 ;
}
if ( V_11 -> V_8 ) {
char V_8 [ 256 ] ;
if ( V_11 -> V_28 > 5000000000 )
sprintf ( V_8 , L_19 , V_11 -> V_8 , V_9 -> V_4 , V_11 -> V_28 / 1000000000.0 ) ;
else
sprintf ( V_8 , L_20 , V_11 -> V_8 , V_9 -> V_4 , V_11 -> V_28 / 1000000.0 ) ;
F_48 ( V_118 , V_11 -> V_17 , V_8 ) ;
}
V_11 -> V_118 = V_118 ;
V_118 ++ ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
}
static void F_49 ( const char * string )
{
int V_4 = F_50 ( string , NULL , 10 ) ;
struct V_120 * V_121 = malloc ( sizeof( * V_121 ) ) ;
if ( ! V_121 )
return;
V_121 -> V_100 = F_4 ( string ) ;
V_121 -> V_4 = V_4 ;
V_121 -> V_7 = V_120 ;
V_120 = V_121 ;
}
static int F_51 ( struct V_1 * V_9 , struct V_10 * V_11 )
{
struct V_120 * V_121 ;
if ( ! V_120 )
return 1 ;
V_121 = V_120 ;
while ( V_121 ) {
if ( V_121 -> V_4 && V_9 -> V_4 == V_121 -> V_4 )
return 1 ;
if ( strcmp ( V_121 -> V_100 , V_11 -> V_8 ) == 0 )
return 1 ;
V_121 = V_121 -> V_7 ;
}
return 0 ;
}
static int F_52 ( struct V_2 * V_3 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
int V_122 = 0 ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_9 -> V_119 = 0 ;
if ( V_9 -> V_17 == 1 )
V_9 -> V_17 = V_3 -> V_49 ;
if ( V_9 -> V_19 == 0 )
V_9 -> V_19 = V_3 -> V_106 ;
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
V_11 -> V_119 = 0 ;
if ( V_11 -> V_17 == 1 )
V_11 -> V_17 = V_3 -> V_49 ;
if ( F_51 ( V_9 , V_11 ) ) {
V_11 -> V_119 = 1 ;
V_9 -> V_119 = 1 ;
V_122 ++ ;
}
if ( V_11 -> V_19 == 0 )
V_11 -> V_19 = V_3 -> V_106 ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
return V_122 ;
}
static int F_53 ( struct V_2 * V_3 , T_1 V_123 )
{
struct V_1 * V_9 ;
struct V_10 * V_11 ;
int V_122 = 0 ;
if ( V_120 )
return F_52 ( V_3 ) ;
V_9 = V_3 -> V_6 ;
while ( V_9 ) {
V_9 -> V_119 = 0 ;
if ( V_9 -> V_17 == 1 )
V_9 -> V_17 = V_3 -> V_49 ;
if ( V_9 -> V_19 == 0 )
V_9 -> V_19 = V_3 -> V_106 ;
if ( V_9 -> V_28 >= V_123 )
V_9 -> V_119 = 1 ;
V_11 = V_9 -> V_12 ;
while ( V_11 ) {
V_11 -> V_119 = 0 ;
if ( V_11 -> V_17 == 1 )
V_11 -> V_17 = V_3 -> V_49 ;
if ( V_11 -> V_28 >= V_123 ) {
V_11 -> V_119 = 1 ;
V_122 ++ ;
}
if ( V_11 -> V_19 == 0 )
V_11 -> V_19 = V_3 -> V_106 ;
V_11 = V_11 -> V_7 ;
}
V_9 = V_9 -> V_7 ;
}
return V_122 ;
}
static void F_54 ( struct V_2 * V_3 , const char * V_124 )
{
T_1 V_70 ;
int V_122 ;
int V_125 = V_126 ;
if ( V_3 -> V_127 )
V_3 -> V_128 = 0 ;
do {
V_122 = F_53 ( V_3 , V_125 ) ;
V_125 /= 10 ;
} while ( ! V_120 && V_125 && V_122 < V_3 -> V_128 );
if ( ! V_3 -> V_128 )
V_122 = 0 ;
F_55 ( V_124 , V_3 -> V_111 , V_122 , V_3 -> V_49 , V_3 -> V_106 ) ;
F_56 () ;
F_57 () ;
for ( V_70 = 0 ; V_70 < V_3 -> V_111 ; V_70 ++ )
F_58 ( V_70 , V_3 -> V_50 , V_3 -> V_52 ) ;
F_41 ( V_3 ) ;
if ( V_3 -> V_128 )
F_43 ( V_3 ) ;
if ( ! V_3 -> V_129 )
F_34 ( V_3 ) ;
if ( V_3 -> V_128 )
F_37 ( V_3 ) ;
F_59 () ;
}
static int F_60 ( struct V_130 * T_7 V_34 ,
struct V_131 * V_132 ,
int V_133 ,
int T_8 V_34 ,
void * V_134 )
{
struct V_2 * V_3 = V_134 ;
switch ( V_133 ) {
case V_135 :
V_3 -> V_111 = V_132 -> V_136 . V_137 ;
break;
case V_138 :
if ( ! V_3 -> V_139 )
break;
if ( F_61 ( V_132 -> V_136 . V_140 ,
V_132 -> V_136 . V_141 ,
V_132 -> V_136 . V_142 ,
V_132 -> V_136 . V_143 ) )
fprintf ( V_79 , L_21 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_62 ( struct V_2 * V_3 , const char * V_144 )
{
const struct V_145 V_146 [] = {
{ L_22 , F_24 } ,
{ L_23 , F_26 } ,
{ L_24 , F_27 } ,
{ L_25 , F_28 } ,
#ifdef F_63
{ L_26 , F_29 } ,
{ L_27 , F_30 } ,
{ L_28 , F_31 } ,
#endif
} ;
struct V_147 V_148 = {
. V_149 = V_150 ,
. V_151 = V_152 ,
} ;
struct V_153 * V_154 = F_64 ( & V_148 , false ,
& V_3 -> V_30 ) ;
int V_155 = - V_156 ;
if ( V_154 == NULL )
return - V_157 ;
( void ) F_65 ( & V_154 -> V_80 ,
F_66 ( V_154 -> V_148 ) ,
V_3 ,
F_60 ) ;
if ( ! F_67 ( V_154 , L_29 ) )
goto V_158;
if ( F_68 ( V_154 ,
V_146 ) ) {
F_69 ( L_30 ) ;
goto V_158;
}
V_155 = F_70 ( V_154 , & V_3 -> V_30 ) ;
if ( V_155 )
goto V_158;
F_32 ( V_3 ) ;
F_33 ( V_3 ) ;
F_54 ( V_3 , V_144 ) ;
F_71 ( L_31 ,
( V_3 -> V_106 - V_3 -> V_49 ) / 1000000000.0 , V_144 ) ;
V_158:
F_72 ( V_154 ) ;
return V_155 ;
}
static int F_73 ( struct V_2 * V_3 , int V_159 , const char * * V_160 )
{
unsigned int V_161 , V_70 , V_162 ;
const char * * V_163 ;
const char * * V_9 ;
unsigned int V_164 ;
const char * const V_165 [] = {
L_32 , L_33 , L_34 , L_35 , L_36 ,
} ;
unsigned int V_166 = F_74 ( V_165 ) ;
const char * const V_167 [] = {
L_37 ,
} ;
unsigned int V_168 = F_74 ( V_167 ) ;
const char * const V_169 [] = {
L_38 , L_23 ,
L_38 , L_22 ,
} ;
unsigned int V_170 = F_74 ( V_169 ) ;
const char * const V_171 [] = {
#ifdef F_63
L_38 , L_26 ,
L_38 , L_27 ,
L_38 , L_28 ,
#endif
} ;
unsigned int V_172 = F_74 ( V_171 ) ;
const char * const V_173 [] = {
L_38 , L_24 ,
L_38 , L_25 ,
} ;
unsigned int V_174 = F_74 ( V_173 ) ;
#ifdef F_63
if ( ! F_75 ( L_22 ) &&
F_75 ( L_26 ) ) {
V_175 = 1 ;
V_170 = 0 ;
} else {
V_172 = 0 ;
}
#endif
if ( V_3 -> V_127 )
V_174 = 0 ;
if ( V_3 -> V_129 ) {
V_170 = 0 ;
V_172 = 0 ;
}
if ( ! V_3 -> V_176 )
V_168 = 0 ;
V_164 = V_166 + V_174 +
V_170 + V_172 + V_168 ;
V_161 = V_164 + V_159 ;
V_163 = calloc ( V_161 + 1 , sizeof( char * ) ) ;
if ( V_163 == NULL )
return - V_157 ;
V_9 = V_163 ;
for ( V_70 = 0 ; V_70 < V_166 ; V_70 ++ )
* V_9 ++ = F_4 ( V_165 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_168 ; V_70 ++ )
* V_9 ++ = F_4 ( V_167 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_174 ; V_70 ++ )
* V_9 ++ = F_4 ( V_173 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_170 ; V_70 ++ )
* V_9 ++ = F_4 ( V_169 [ V_70 ] ) ;
for ( V_70 = 0 ; V_70 < V_172 ; V_70 ++ )
* V_9 ++ = F_4 ( V_171 [ V_70 ] ) ;
for ( V_162 = 1 ; V_162 < ( unsigned int ) V_159 ; V_162 ++ )
* V_9 ++ = V_160 [ V_162 ] ;
return F_76 ( V_161 , V_163 , NULL ) ;
}
static int
F_77 ( const struct V_177 * T_9 V_34 , const char * V_178 ,
int V_34 V_179 )
{
if ( V_178 )
F_49 ( V_178 ) ;
return 0 ;
}
static int
F_78 ( const struct V_177 * T_9 V_34 , const char * V_178 ,
int V_34 V_179 )
{
unsigned long V_180 = strtoul ( V_178 , NULL , 0 ) ;
if ( V_181 || V_182 )
return - 1 ;
if ( V_180 )
V_181 = V_180 ;
else
V_182 = F_4 ( V_178 ) ;
return 0 ;
}
int F_79 ( int V_159 , const char * * V_160 ,
const char * T_10 V_34 )
{
struct V_2 V_3 = {
. V_30 = {
. V_8 = F_8 ,
. V_37 = F_10 ,
. exit = F_11 ,
. V_25 = F_23 ,
. V_183 = true ,
} ,
. V_128 = 15 ,
} ;
const char * V_144 = L_39 ;
const struct V_177 V_184 [] = {
F_80 ( 'i' , L_40 , & V_150 , L_41 , L_42 ) ,
F_80 ( 'o' , L_43 , & V_144 , L_41 , L_44 ) ,
F_81 ( 'w' , L_45 , & V_185 , L_46 ) ,
F_82 ( 0 , L_47 , NULL , L_48 ,
L_49 ,
F_78 ) ,
F_83 ( 'P' , L_50 , & V_3 . V_127 , L_51 ) ,
F_83 ( 'T' , L_52 , & V_3 . V_129 ,
L_53 ) ,
F_82 ( 'p' , L_18 , NULL , L_18 ,
L_54 ,
F_77 ) ,
F_80 ( 0 , L_55 , & V_186 . V_187 , L_56 ,
L_57 ) ,
F_81 ( 'n' , L_58 , & V_3 . V_128 ,
L_59 ) ,
F_83 ( 't' , L_60 , & V_3 . V_139 ,
L_61 ) ,
F_84 ()
} ;
const char * const V_188 [] = {
L_62 ,
NULL
} ;
const struct V_177 V_189 [] = {
F_83 ( 'P' , L_50 , & V_3 . V_127 , L_51 ) ,
F_83 ( 'T' , L_52 , & V_3 . V_129 ,
L_53 ) ,
F_83 ( 'g' , L_63 , & V_3 . V_176 , L_64 ) ,
F_84 ()
} ;
const char * const V_190 [] = {
L_65 ,
NULL
} ;
V_159 = F_85 ( V_159 , V_160 , V_184 , V_188 ,
V_191 ) ;
if ( V_3 . V_127 && V_3 . V_129 ) {
F_69 ( L_66 ) ;
return - 1 ;
}
F_86 () ;
if ( V_159 && ! strncmp ( V_160 [ 0 ] , L_67 , 3 ) ) {
V_159 = F_85 ( V_159 , V_160 , V_189 , V_190 ,
V_191 ) ;
if ( V_3 . V_127 && V_3 . V_129 ) {
F_69 ( L_66 ) ;
return - 1 ;
}
return F_73 ( & V_3 , V_159 , V_160 ) ;
} else if ( V_159 )
F_87 ( V_188 , V_184 ) ;
F_88 () ;
return F_62 ( & V_3 , V_144 ) ;
}
