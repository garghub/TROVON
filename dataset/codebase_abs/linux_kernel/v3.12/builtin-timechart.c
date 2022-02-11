static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 = V_4 ;
while ( V_3 ) {
if ( V_3 -> V_2 == V_2 )
return V_3 ;
V_3 = V_3 -> V_5 ;
}
V_3 = F_2 ( sizeof( * V_3 ) ) ;
assert ( V_3 != NULL ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = V_4 ;
V_4 = V_3 ;
return V_3 ;
}
static void F_3 ( int V_2 , char * V_6 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_7 = F_1 ( V_2 ) ;
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_9 -> V_6 && strcmp ( V_9 -> V_6 , V_6 ) == 0 ) {
V_7 -> V_11 = V_9 ;
return;
}
if ( ! V_9 -> V_6 ) {
V_9 -> V_6 = F_4 ( V_6 ) ;
V_7 -> V_11 = V_9 ;
return;
}
V_9 = V_9 -> V_5 ;
}
V_9 = F_2 ( sizeof( * V_9 ) ) ;
assert ( V_9 != NULL ) ;
V_9 -> V_6 = F_4 ( V_6 ) ;
V_7 -> V_11 = V_9 ;
V_9 -> V_5 = V_7 -> V_10 ;
V_7 -> V_10 = V_9 ;
}
static void F_5 ( int V_2 , int V_12 , T_1 V_13 )
{
struct V_1 * V_7 , * V_14 ;
V_7 = F_1 ( V_2 ) ;
V_14 = F_1 ( V_12 ) ;
V_7 -> V_12 = V_12 ;
if ( V_14 -> V_11 && V_14 -> V_11 -> V_6 && ! V_7 -> V_11 )
F_3 ( V_2 , V_14 -> V_11 -> V_6 ) ;
V_7 -> V_15 = V_13 ;
if ( V_7 -> V_11 ) {
V_7 -> V_11 -> V_15 = V_13 ;
V_7 -> V_11 -> V_16 = V_13 ;
}
}
static void F_6 ( int V_2 , T_1 V_13 )
{
struct V_1 * V_7 ;
V_7 = F_1 ( V_2 ) ;
V_7 -> V_17 = V_13 ;
if ( V_7 -> V_11 )
V_7 -> V_11 -> V_17 = V_13 ;
}
static void
F_7 ( int V_2 , int type , unsigned int V_18 , T_1 V_19 , T_1 V_20 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_7 = F_1 ( V_2 ) ;
V_9 = V_7 -> V_11 ;
if ( ! V_9 ) {
V_9 = F_2 ( sizeof( * V_9 ) ) ;
assert ( V_9 != NULL ) ;
V_7 -> V_11 = V_9 ;
V_9 -> V_5 = V_7 -> V_10 ;
V_7 -> V_10 = V_9 ;
}
V_22 = F_2 ( sizeof( * V_22 ) ) ;
assert ( V_22 != NULL ) ;
V_22 -> V_15 = V_19 ;
V_22 -> V_17 = V_20 ;
V_22 -> type = type ;
V_22 -> V_5 = V_9 -> V_23 ;
V_22 -> V_18 = V_18 ;
V_9 -> V_23 = V_22 ;
if ( V_22 -> type == V_24 && V_20 > V_19 && V_19 > 0 ) {
V_9 -> V_25 += ( V_20 - V_19 ) ;
V_7 -> V_25 += ( V_20 - V_19 ) ;
}
if ( V_9 -> V_15 == 0 || V_9 -> V_15 > V_19 )
V_9 -> V_15 = V_19 ;
if ( V_7 -> V_15 == 0 || V_7 -> V_15 > V_19 )
V_7 -> V_15 = V_19 ;
}
static int F_8 ( struct V_26 * T_2 V_27 ,
union V_28 * V_29 ,
struct V_30 * V_22 V_27 ,
struct V_31 * V_31 V_27 )
{
F_3 ( V_29 -> V_6 . V_32 , V_29 -> V_6 . V_6 ) ;
return 0 ;
}
static int F_9 ( struct V_26 * T_2 V_27 ,
union V_28 * V_29 ,
struct V_30 * V_22 V_27 ,
struct V_31 * V_31 V_27 )
{
F_5 ( V_29 -> V_33 . V_2 , V_29 -> V_33 . V_12 , V_29 -> V_33 . time ) ;
return 0 ;
}
static int F_10 ( struct V_26 * T_2 V_27 ,
union V_28 * V_29 ,
struct V_30 * V_22 V_27 ,
struct V_31 * V_31 V_27 )
{
F_6 ( V_29 -> V_33 . V_2 , V_29 -> V_33 . time ) ;
return 0 ;
}
static void F_11 ( int V_18 , T_1 V_13 , int V_34 )
{
V_35 [ V_18 ] = V_13 ;
V_36 [ V_18 ] = V_34 ;
}
static void F_12 ( int V_18 , T_1 V_13 )
{
struct V_37 * V_38 = F_2 ( sizeof( * V_38 ) ) ;
if ( ! V_38 )
return;
V_38 -> V_34 = V_36 [ V_18 ] ;
V_38 -> V_15 = V_35 [ V_18 ] ;
V_38 -> V_17 = V_13 ;
V_38 -> V_18 = V_18 ;
V_38 -> type = V_39 ;
V_38 -> V_5 = V_40 ;
V_40 = V_38 ;
}
static void F_13 ( int V_18 , T_1 V_13 , T_1 V_41 )
{
struct V_37 * V_38 ;
if ( V_41 > 8000000 )
return;
V_38 = F_2 ( sizeof( * V_38 ) ) ;
if ( ! V_38 )
return;
V_38 -> V_34 = V_42 [ V_18 ] ;
V_38 -> V_15 = V_43 [ V_18 ] ;
V_38 -> V_17 = V_13 ;
V_38 -> V_18 = V_18 ;
V_38 -> type = V_44 ;
V_38 -> V_5 = V_40 ;
if ( ! V_38 -> V_15 )
V_38 -> V_15 = V_45 ;
V_40 = V_38 ;
V_42 [ V_18 ] = V_41 ;
V_43 [ V_18 ] = V_13 ;
if ( ( T_1 ) V_41 > V_46 )
V_46 = V_41 ;
if ( V_41 < V_47 || V_47 == 0 )
V_47 = V_41 ;
if ( V_41 == V_46 - 1000 )
V_48 = V_46 ;
}
static void
F_14 ( int V_18 , T_1 V_13 , int V_2 , struct V_49 * V_50 )
{
struct V_1 * V_7 ;
struct V_51 * V_52 = ( void * ) V_50 ;
struct V_53 * V_54 = F_2 ( sizeof( * V_54 ) ) ;
if ( ! V_54 )
return;
V_54 -> time = V_13 ;
V_54 -> V_55 = V_2 ;
if ( ( V_50 -> V_56 & V_57 ) || ( V_50 -> V_56 & V_58 ) )
V_54 -> V_55 = - 1 ;
V_54 -> V_59 = V_52 -> V_2 ;
V_54 -> V_5 = V_60 ;
V_60 = V_54 ;
V_7 = F_1 ( V_54 -> V_59 ) ;
if ( V_7 && V_7 -> V_11 && V_7 -> V_11 -> V_34 == V_61 ) {
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_34 = V_62 ;
}
if ( V_7 && V_7 -> V_11 && V_7 -> V_11 -> V_34 == V_63 ) {
F_7 ( V_7 -> V_2 , V_7 -> V_11 -> V_34 , V_18 , V_7 -> V_11 -> V_16 , V_13 ) ;
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_34 = V_62 ;
}
}
static void F_15 ( int V_18 , T_1 V_13 , struct V_49 * V_50 )
{
struct V_1 * V_7 = NULL , * V_64 ;
struct F_15 * V_65 = ( void * ) V_50 ;
V_64 = F_1 ( V_65 -> V_66 ) ;
V_7 = F_1 ( V_65 -> V_67 ) ;
if ( V_64 -> V_11 && V_64 -> V_11 -> V_34 != V_61 )
F_7 ( V_65 -> V_66 , V_24 , V_18 , V_64 -> V_11 -> V_16 , V_13 ) ;
if ( V_7 && V_7 -> V_11 ) {
if ( V_7 -> V_11 -> V_34 != V_61 )
F_7 ( V_65 -> V_67 , V_7 -> V_11 -> V_34 , V_18 , V_7 -> V_11 -> V_16 , V_13 ) ;
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_34 = V_24 ;
}
if ( V_64 -> V_11 ) {
V_64 -> V_11 -> V_34 = V_61 ;
V_64 -> V_11 -> V_16 = V_13 ;
if ( V_65 -> V_68 & 2 )
V_64 -> V_11 -> V_34 = V_63 ;
if ( V_65 -> V_68 == 0 )
V_64 -> V_11 -> V_34 = V_62 ;
}
}
static int F_16 ( struct V_26 * T_2 V_27 ,
union V_28 * V_29 V_27 ,
struct V_30 * V_22 ,
struct V_69 * V_70 ,
struct V_31 * V_31 V_27 )
{
if ( V_70 -> V_71 . V_72 & V_73 ) {
if ( ! V_45 || V_45 > V_22 -> time )
V_45 = V_22 -> time ;
if ( V_74 < V_22 -> time )
V_74 = V_22 -> time ;
}
if ( V_22 -> V_18 > V_75 )
V_75 = V_22 -> V_18 ;
if ( V_70 -> V_76 . V_77 != NULL ) {
T_3 V_78 = V_70 -> V_76 . V_77 ;
return V_78 ( V_70 , V_22 ) ;
}
return 0 ;
}
static int
F_17 ( struct V_69 * V_70 V_27 ,
struct V_30 * V_22 )
{
struct V_79 * V_80 = V_22 -> V_81 ;
if ( V_80 -> V_34 == ( V_82 ) V_83 )
F_12 ( V_80 -> V_84 , V_22 -> time ) ;
else
F_11 ( V_80 -> V_84 , V_22 -> time , V_80 -> V_34 ) ;
return 0 ;
}
static int
F_18 ( struct V_69 * V_70 V_27 ,
struct V_30 * V_22 )
{
struct V_79 * V_80 = V_22 -> V_81 ;
F_13 ( V_80 -> V_84 , V_22 -> time , V_80 -> V_34 ) ;
return 0 ;
}
static int
F_19 ( struct V_69 * V_70 V_27 ,
struct V_30 * V_22 )
{
struct V_49 * V_50 = V_22 -> V_81 ;
F_14 ( V_22 -> V_18 , V_22 -> time , V_22 -> V_2 , V_50 ) ;
return 0 ;
}
static int
F_20 ( struct V_69 * V_70 V_27 ,
struct V_30 * V_22 )
{
struct V_49 * V_50 = V_22 -> V_81 ;
F_15 ( V_22 -> V_18 , V_22 -> time , V_50 ) ;
return 0 ;
}
static int
F_21 ( struct V_69 * V_70 V_27 ,
struct V_30 * V_22 )
{
struct V_85 * V_86 = V_22 -> V_81 ;
F_11 ( V_86 -> V_84 , V_22 -> time , V_86 -> V_87 ) ;
return 0 ;
}
static int
F_22 ( struct V_69 * V_70 V_27 ,
struct V_30 * V_22 )
{
F_12 ( V_22 -> V_18 , V_22 -> time ) ;
return 0 ;
}
static int
F_23 ( struct V_69 * V_70 V_27 ,
struct V_30 * V_22 )
{
struct V_85 * V_86 = V_22 -> V_81 ;
F_13 ( V_86 -> V_84 , V_22 -> time , V_86 -> V_87 ) ;
return 0 ;
}
static void F_24 ( void )
{
T_1 V_18 ;
struct V_37 * V_38 ;
for ( V_18 = 0 ; V_18 <= V_75 ; V_18 ++ ) {
#if 0
pwr = zalloc(sizeof(*pwr));
if (!pwr)
return;
pwr->state = cpus_cstate_state[cpu];
pwr->start_time = cpus_cstate_start_times[cpu];
pwr->end_time = last_time;
pwr->cpu = cpu;
pwr->type = CSTATE;
pwr->next = power_events;
power_events = pwr;
#endif
V_38 = F_2 ( sizeof( * V_38 ) ) ;
if ( ! V_38 )
return;
V_38 -> V_34 = V_42 [ V_18 ] ;
V_38 -> V_15 = V_43 [ V_18 ] ;
V_38 -> V_17 = V_74 ;
V_38 -> V_18 = V_18 ;
V_38 -> type = V_44 ;
V_38 -> V_5 = V_40 ;
if ( ! V_38 -> V_15 )
V_38 -> V_15 = V_45 ;
if ( ! V_38 -> V_34 )
V_38 -> V_34 = V_47 ;
V_40 = V_38 ;
}
}
static void F_25 ( void )
{
struct V_1 * V_88 , * V_7 , * V_3 , * V_89 ;
V_88 = NULL ;
while ( V_4 ) {
V_7 = V_4 ;
V_4 = V_7 -> V_5 ;
V_7 -> V_5 = NULL ;
if ( V_88 == NULL ) {
V_88 = V_7 ;
V_7 -> V_5 = NULL ;
continue;
}
V_89 = NULL ;
V_3 = V_88 ;
while ( V_3 ) {
if ( V_3 -> V_12 > V_7 -> V_12 ||
( V_3 -> V_12 == V_7 -> V_12 && V_3 -> V_2 > V_7 -> V_2 ) ) {
if ( V_89 ) {
V_7 -> V_5 = V_89 -> V_5 ;
V_89 -> V_5 = V_7 ;
V_3 = NULL ;
continue;
} else {
V_7 -> V_5 = V_88 ;
V_88 = V_7 ;
V_3 = NULL ;
continue;
}
}
V_89 = V_3 ;
V_3 = V_3 -> V_5 ;
if ( ! V_3 )
V_89 -> V_5 = V_7 ;
}
}
V_4 = V_88 ;
}
static void F_26 ( void )
{
struct V_37 * V_38 ;
V_38 = V_40 ;
while ( V_38 ) {
if ( V_38 -> type == V_39 )
F_27 ( V_38 -> V_18 , V_38 -> V_15 , V_38 -> V_17 , V_38 -> V_34 ) ;
V_38 = V_38 -> V_5 ;
}
V_38 = V_40 ;
while ( V_38 ) {
if ( V_38 -> type == V_44 ) {
if ( ! V_38 -> V_34 )
V_38 -> V_34 = V_47 ;
F_28 ( V_38 -> V_18 , V_38 -> V_15 , V_38 -> V_17 , V_38 -> V_34 ) ;
}
V_38 = V_38 -> V_5 ;
}
}
static void F_29 ( void )
{
struct V_53 * V_54 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_54 = V_60 ;
while ( V_54 ) {
int V_90 = 0 , V_91 = 0 ;
char * V_92 = NULL , * V_93 = NULL ;
V_7 = V_4 ;
while ( V_7 ) {
if ( V_7 -> V_2 == V_54 -> V_55 || V_7 -> V_2 == V_54 -> V_59 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_9 -> V_94 && V_9 -> V_15 <= V_54 -> time && V_9 -> V_17 >= V_54 -> time ) {
if ( V_7 -> V_2 == V_54 -> V_55 && ! V_90 ) {
V_90 = V_9 -> V_94 ;
V_92 = F_4 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_54 -> V_59 && ! V_91 ) {
V_91 = V_9 -> V_94 ;
V_93 = F_4 ( V_9 -> V_6 ) ;
}
}
V_9 = V_9 -> V_5 ;
}
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_7 -> V_2 == V_54 -> V_55 && ! V_90 ) {
V_90 = V_9 -> V_94 ;
V_92 = F_4 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_54 -> V_59 && ! V_91 ) {
V_91 = V_9 -> V_94 ;
V_93 = F_4 ( V_9 -> V_6 ) ;
}
V_9 = V_9 -> V_5 ;
}
}
V_7 = V_7 -> V_5 ;
}
if ( ! V_92 ) {
V_92 = malloc ( 40 ) ;
sprintf ( V_92 , L_1 , V_54 -> V_55 ) ;
}
if ( ! V_93 ) {
V_93 = malloc ( 40 ) ;
sprintf ( V_93 , L_1 , V_54 -> V_59 ) ;
}
if ( V_54 -> V_55 == - 1 )
F_30 ( V_54 -> time , V_91 ) ;
else if ( V_90 && V_91 && abs ( V_90 - V_91 ) == 1 )
F_31 ( V_54 -> time , V_90 , V_91 ) ;
else
F_32 ( V_54 -> time , V_90 , V_92 , V_91 , V_93 ) ;
V_54 = V_54 -> V_5 ;
free ( V_92 ) ;
free ( V_93 ) ;
}
}
static void F_33 ( void )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_7 = V_4 ;
while ( V_7 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
V_22 = V_9 -> V_23 ;
while ( V_22 ) {
if ( V_22 -> type == V_24 )
F_34 ( V_22 -> V_18 , V_22 -> V_15 , V_22 -> V_17 , L_2 , V_9 -> V_6 ) ;
V_22 = V_22 -> V_5 ;
}
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
}
static void F_35 ( void )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
int V_94 = 0 ;
V_94 = 2 * V_75 + 2 ;
V_7 = V_4 ;
while ( V_7 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( ! V_9 -> V_95 ) {
V_9 -> V_94 = 0 ;
V_9 = V_9 -> V_5 ;
continue;
}
F_36 ( V_94 , V_9 -> V_15 , V_9 -> V_17 , L_3 ) ;
V_22 = V_9 -> V_23 ;
while ( V_22 ) {
if ( V_22 -> type == V_24 )
F_37 ( V_94 , V_22 -> V_18 , V_22 -> V_15 , V_22 -> V_17 ) ;
if ( V_22 -> type == V_63 )
F_36 ( V_94 , V_22 -> V_15 , V_22 -> V_17 , L_4 ) ;
if ( V_22 -> type == V_62 )
F_38 ( V_94 , V_22 -> V_15 , V_22 -> V_17 ) ;
V_22 = V_22 -> V_5 ;
}
if ( V_9 -> V_6 ) {
char V_6 [ 256 ] ;
if ( V_9 -> V_25 > 5000000000 )
sprintf ( V_6 , L_5 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000000.0 ) ;
else
sprintf ( V_6 , L_6 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000.0 ) ;
F_39 ( V_94 , V_9 -> V_15 , V_6 ) ;
}
V_9 -> V_94 = V_94 ;
V_94 ++ ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
}
static void F_40 ( const char * string )
{
int V_2 = F_41 ( string , NULL , 10 ) ;
struct V_96 * V_97 = malloc ( sizeof( * V_97 ) ) ;
if ( ! V_97 )
return;
V_97 -> V_98 = F_4 ( string ) ;
V_97 -> V_2 = V_2 ;
V_97 -> V_5 = V_96 ;
V_96 = V_97 ;
}
static int F_42 ( struct V_1 * V_7 , struct V_8 * V_9 )
{
struct V_96 * V_97 ;
if ( ! V_96 )
return 1 ;
V_97 = V_96 ;
while ( V_97 ) {
if ( V_97 -> V_2 && V_7 -> V_2 == V_97 -> V_2 )
return 1 ;
if ( strcmp ( V_97 -> V_98 , V_9 -> V_6 ) == 0 )
return 1 ;
V_97 = V_97 -> V_5 ;
}
return 0 ;
}
static int F_43 ( void )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_99 = 0 ;
V_7 = V_4 ;
while ( V_7 ) {
V_7 -> V_95 = 0 ;
if ( V_7 -> V_15 == 1 )
V_7 -> V_15 = V_45 ;
if ( V_7 -> V_17 == 0 )
V_7 -> V_17 = V_74 ;
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
V_9 -> V_95 = 0 ;
if ( V_9 -> V_15 == 1 )
V_9 -> V_15 = V_45 ;
if ( F_42 ( V_7 , V_9 ) ) {
V_9 -> V_95 = 1 ;
V_7 -> V_95 = 1 ;
V_99 ++ ;
}
if ( V_9 -> V_17 == 0 )
V_9 -> V_17 = V_74 ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
return V_99 ;
}
static int F_44 ( T_1 V_100 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_99 = 0 ;
if ( V_96 )
return F_43 () ;
V_7 = V_4 ;
while ( V_7 ) {
V_7 -> V_95 = 0 ;
if ( V_7 -> V_15 == 1 )
V_7 -> V_15 = V_45 ;
if ( V_7 -> V_17 == 0 )
V_7 -> V_17 = V_74 ;
if ( V_7 -> V_25 >= V_100 && ! V_101 )
V_7 -> V_95 = 1 ;
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
V_9 -> V_95 = 0 ;
if ( V_9 -> V_15 == 1 )
V_9 -> V_15 = V_45 ;
if ( V_9 -> V_25 >= V_100 && ! V_101 ) {
V_9 -> V_95 = 1 ;
V_99 ++ ;
}
if ( V_9 -> V_17 == 0 )
V_9 -> V_17 = V_74 ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
return V_99 ;
}
static void F_45 ( const char * V_102 )
{
T_1 V_103 ;
int V_99 ;
V_75 ++ ;
V_99 = F_44 ( V_104 ) ;
if ( V_99 < 15 )
V_99 = F_44 ( V_104 / 10 ) ;
F_46 ( V_102 , V_75 , V_99 , V_45 , V_74 ) ;
F_47 () ;
F_48 () ;
for ( V_103 = 0 ; V_103 < V_75 ; V_103 ++ )
F_49 ( V_103 , V_46 , V_48 ) ;
F_33 () ;
F_35 () ;
F_26 () ;
F_29 () ;
F_50 () ;
}
static int F_51 ( const char * V_105 )
{
struct V_26 V_106 = {
. V_6 = F_8 ,
. V_33 = F_9 ,
. exit = F_10 ,
. V_22 = F_16 ,
. V_107 = true ,
} ;
const struct V_108 V_109 [] = {
{ L_7 , F_17 } ,
{ L_8 , F_18 } ,
{ L_9 , F_19 } ,
{ L_10 , F_20 } ,
#ifdef F_52
{ L_11 , F_21 } ,
{ L_12 , F_22 } ,
{ L_13 , F_23 } ,
#endif
} ;
struct V_110 * V_111 = F_53 ( V_112 , V_113 ,
0 , false , & V_106 ) ;
int V_114 = - V_115 ;
if ( V_111 == NULL )
return - V_116 ;
if ( ! F_54 ( V_111 , L_14 ) )
goto V_117;
if ( F_55 ( V_111 ,
V_109 ) ) {
F_56 ( L_15 ) ;
goto V_117;
}
V_114 = F_57 ( V_111 , & V_106 ) ;
if ( V_114 )
goto V_117;
F_24 () ;
F_25 () ;
F_45 ( V_105 ) ;
F_58 ( L_16 ,
( V_74 - V_45 ) / 1000000000.0 , V_105 ) ;
V_117:
F_59 ( V_111 ) ;
return V_114 ;
}
static int F_60 ( int V_118 , const char * * V_119 )
{
#ifdef F_52
const char * const V_120 [] = {
L_17 , L_18 , L_19 , L_20 , L_21 ,
L_22 , L_11 ,
L_22 , L_12 ,
L_22 , L_13 ,
L_22 , L_9 ,
L_22 , L_10 ,
} ;
#endif
const char * const V_121 [] = {
L_17 , L_18 , L_19 , L_20 , L_21 ,
L_22 , L_8 ,
L_22 , L_7 ,
L_22 , L_9 ,
L_22 , L_10 ,
} ;
unsigned int V_122 , V_103 , V_123 ;
const char * * V_124 ;
const char * const * V_125 = V_121 ;
unsigned int V_126 = F_61 ( V_121 ) ;
#ifdef F_52
if ( ! F_62 ( L_7 ) &&
F_62 ( L_11 ) ) {
V_127 = 1 ;
V_125 = V_120 ;
V_126 = F_61 ( V_120 ) ;
}
#endif
V_122 = V_126 + V_118 - 1 ;
V_124 = calloc ( V_122 + 1 , sizeof( char * ) ) ;
if ( V_124 == NULL )
return - V_116 ;
for ( V_103 = 0 ; V_103 < V_126 ; V_103 ++ )
V_124 [ V_103 ] = F_4 ( V_125 [ V_103 ] ) ;
for ( V_123 = 1 ; V_123 < ( unsigned int ) V_118 ; V_123 ++ , V_103 ++ )
V_124 [ V_103 ] = V_119 [ V_123 ] ;
return F_63 ( V_103 , V_124 , NULL ) ;
}
static int
F_64 ( const struct V_128 * T_4 V_27 , const char * V_129 ,
int V_27 V_130 )
{
if ( V_129 )
F_40 ( V_129 ) ;
return 0 ;
}
int F_65 ( int V_118 , const char * * V_119 ,
const char * T_5 V_27 )
{
const char * V_105 = L_23 ;
const struct V_128 V_131 [] = {
F_66 ( 'i' , L_24 , & V_112 , L_25 , L_26 ) ,
F_66 ( 'o' , L_27 , & V_105 , L_25 , L_28 ) ,
F_67 ( 'w' , L_29 , & V_132 , L_30 ) ,
F_68 ( 'P' , L_31 , & V_101 , L_32 ) ,
F_69 ( 'p' , L_3 , NULL , L_3 ,
L_33 ,
F_64 ) ,
F_66 ( 0 , L_34 , & V_133 . V_134 , L_35 ,
L_36 ) ,
F_70 ()
} ;
const char * const V_135 [] = {
L_37 ,
NULL
} ;
V_118 = F_71 ( V_118 , V_119 , V_131 , V_135 ,
V_136 ) ;
F_72 () ;
if ( V_118 && ! strncmp ( V_119 [ 0 ] , L_38 , 3 ) )
return F_60 ( V_118 , V_119 ) ;
else if ( V_118 )
F_73 ( V_135 , V_131 ) ;
F_74 () ;
return F_51 ( V_105 ) ;
}
