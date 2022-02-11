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
struct V_49 * V_50 ;
if ( V_70 -> V_71 . V_72 & V_73 ) {
if ( ! V_45 || V_45 > V_22 -> time )
V_45 = V_22 -> time ;
if ( V_74 < V_22 -> time )
V_74 = V_22 -> time ;
}
V_50 = ( void * ) V_22 -> V_75 ;
if ( ( V_70 -> V_71 . V_72 & V_76 ) && V_22 -> V_77 > 0 ) {
char * V_78 ;
#ifdef F_17
struct V_79 * V_80 ;
V_80 = ( void * ) V_50 ;
#endif
V_78 = F_18 ( V_50 -> type ) ;
if ( ! V_78 )
return 0 ;
if ( V_22 -> V_18 > V_81 )
V_81 = V_22 -> V_18 ;
if ( strcmp ( V_78 , L_1 ) == 0 ) {
struct V_82 * V_83 = ( void * ) V_50 ;
if ( V_83 -> V_34 == ( V_84 ) V_85 )
F_12 ( V_83 -> V_86 , V_22 -> time ) ;
else
F_11 ( V_83 -> V_86 , V_22 -> time ,
V_83 -> V_34 ) ;
}
else if ( strcmp ( V_78 , L_2 ) == 0 ) {
struct V_82 * V_83 = ( void * ) V_50 ;
F_13 ( V_83 -> V_86 , V_22 -> time , V_83 -> V_34 ) ;
}
else if ( strcmp ( V_78 , L_3 ) == 0 )
F_14 ( V_22 -> V_18 , V_22 -> time , V_22 -> V_2 , V_50 ) ;
else if ( strcmp ( V_78 , L_4 ) == 0 )
F_15 ( V_22 -> V_18 , V_22 -> time , V_50 ) ;
#ifdef F_17
if ( V_87 ) {
if ( strcmp ( V_78 , L_5 ) == 0 )
F_11 ( V_80 -> V_86 , V_22 -> time ,
V_80 -> V_88 ) ;
else if ( strcmp ( V_78 , L_6 ) == 0 )
F_12 ( V_22 -> V_18 , V_22 -> time ) ;
else if ( strcmp ( V_78 ,
L_7 ) == 0 )
F_13 ( V_80 -> V_86 , V_22 -> time ,
V_80 -> V_88 ) ;
}
#endif
}
return 0 ;
}
static void F_19 ( void )
{
T_1 V_18 ;
struct V_37 * V_38 ;
for ( V_18 = 0 ; V_18 <= V_81 ; V_18 ++ ) {
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
static void F_20 ( void )
{
struct V_1 * V_89 , * V_7 , * V_3 , * V_90 ;
V_89 = NULL ;
while ( V_4 ) {
V_7 = V_4 ;
V_4 = V_7 -> V_5 ;
V_7 -> V_5 = NULL ;
if ( V_89 == NULL ) {
V_89 = V_7 ;
V_7 -> V_5 = NULL ;
continue;
}
V_90 = NULL ;
V_3 = V_89 ;
while ( V_3 ) {
if ( V_3 -> V_12 > V_7 -> V_12 ||
( V_3 -> V_12 == V_7 -> V_12 && V_3 -> V_2 > V_7 -> V_2 ) ) {
if ( V_90 ) {
V_7 -> V_5 = V_90 -> V_5 ;
V_90 -> V_5 = V_7 ;
V_3 = NULL ;
continue;
} else {
V_7 -> V_5 = V_89 ;
V_89 = V_7 ;
V_3 = NULL ;
continue;
}
}
V_90 = V_3 ;
V_3 = V_3 -> V_5 ;
if ( ! V_3 )
V_90 -> V_5 = V_7 ;
}
}
V_4 = V_89 ;
}
static void F_21 ( void )
{
struct V_37 * V_38 ;
V_38 = V_40 ;
while ( V_38 ) {
if ( V_38 -> type == V_39 )
F_22 ( V_38 -> V_18 , V_38 -> V_15 , V_38 -> V_17 , V_38 -> V_34 ) ;
V_38 = V_38 -> V_5 ;
}
V_38 = V_40 ;
while ( V_38 ) {
if ( V_38 -> type == V_44 ) {
if ( ! V_38 -> V_34 )
V_38 -> V_34 = V_47 ;
F_23 ( V_38 -> V_18 , V_38 -> V_15 , V_38 -> V_17 , V_38 -> V_34 ) ;
}
V_38 = V_38 -> V_5 ;
}
}
static void F_24 ( void )
{
struct V_53 * V_54 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_54 = V_60 ;
while ( V_54 ) {
int V_91 = 0 , V_92 = 0 ;
char * V_93 = NULL , * V_94 = NULL ;
V_7 = V_4 ;
while ( V_7 ) {
if ( V_7 -> V_2 == V_54 -> V_55 || V_7 -> V_2 == V_54 -> V_59 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_9 -> V_95 && V_9 -> V_15 <= V_54 -> time && V_9 -> V_17 >= V_54 -> time ) {
if ( V_7 -> V_2 == V_54 -> V_55 && ! V_91 ) {
V_91 = V_9 -> V_95 ;
V_93 = F_4 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_54 -> V_59 && ! V_92 ) {
V_92 = V_9 -> V_95 ;
V_94 = F_4 ( V_9 -> V_6 ) ;
}
}
V_9 = V_9 -> V_5 ;
}
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_7 -> V_2 == V_54 -> V_55 && ! V_91 ) {
V_91 = V_9 -> V_95 ;
V_93 = F_4 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_54 -> V_59 && ! V_92 ) {
V_92 = V_9 -> V_95 ;
V_94 = F_4 ( V_9 -> V_6 ) ;
}
V_9 = V_9 -> V_5 ;
}
}
V_7 = V_7 -> V_5 ;
}
if ( ! V_93 ) {
V_93 = malloc ( 40 ) ;
sprintf ( V_93 , L_8 , V_54 -> V_55 ) ;
}
if ( ! V_94 ) {
V_94 = malloc ( 40 ) ;
sprintf ( V_94 , L_8 , V_54 -> V_59 ) ;
}
if ( V_54 -> V_55 == - 1 )
F_25 ( V_54 -> time , V_92 ) ;
else if ( V_91 && V_92 && abs ( V_91 - V_92 ) == 1 )
F_26 ( V_54 -> time , V_91 , V_92 ) ;
else
F_27 ( V_54 -> time , V_91 , V_93 , V_92 , V_94 ) ;
V_54 = V_54 -> V_5 ;
free ( V_93 ) ;
free ( V_94 ) ;
}
}
static void F_28 ( void )
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
F_29 ( V_22 -> V_18 , V_22 -> V_15 , V_22 -> V_17 , L_9 , V_9 -> V_6 ) ;
V_22 = V_22 -> V_5 ;
}
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
}
static void F_30 ( void )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
int V_95 = 0 ;
V_95 = 2 * V_81 + 2 ;
V_7 = V_4 ;
while ( V_7 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( ! V_9 -> V_96 ) {
V_9 -> V_95 = 0 ;
V_9 = V_9 -> V_5 ;
continue;
}
F_31 ( V_95 , V_9 -> V_15 , V_9 -> V_17 , L_10 ) ;
V_22 = V_9 -> V_23 ;
while ( V_22 ) {
if ( V_22 -> type == V_24 )
F_32 ( V_95 , V_22 -> V_18 , V_22 -> V_15 , V_22 -> V_17 ) ;
if ( V_22 -> type == V_63 )
F_31 ( V_95 , V_22 -> V_15 , V_22 -> V_17 , L_11 ) ;
if ( V_22 -> type == V_62 )
F_33 ( V_95 , V_22 -> V_15 , V_22 -> V_17 ) ;
V_22 = V_22 -> V_5 ;
}
if ( V_9 -> V_6 ) {
char V_6 [ 256 ] ;
if ( V_9 -> V_25 > 5000000000 )
sprintf ( V_6 , L_12 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000000.0 ) ;
else
sprintf ( V_6 , L_13 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000.0 ) ;
F_34 ( V_95 , V_9 -> V_15 , V_6 ) ;
}
V_9 -> V_95 = V_95 ;
V_95 ++ ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
}
static void F_35 ( const char * string )
{
int V_2 = F_36 ( string , NULL , 10 ) ;
struct V_97 * V_98 = malloc ( sizeof( * V_98 ) ) ;
if ( ! V_98 )
return;
V_98 -> V_99 = F_4 ( string ) ;
V_98 -> V_2 = V_2 ;
V_98 -> V_5 = V_97 ;
V_97 = V_98 ;
}
static int F_37 ( struct V_1 * V_7 , struct V_8 * V_9 )
{
struct V_97 * V_98 ;
if ( ! V_97 )
return 1 ;
V_98 = V_97 ;
while ( V_98 ) {
if ( V_98 -> V_2 && V_7 -> V_2 == V_98 -> V_2 )
return 1 ;
if ( strcmp ( V_98 -> V_99 , V_9 -> V_6 ) == 0 )
return 1 ;
V_98 = V_98 -> V_5 ;
}
return 0 ;
}
static int F_38 ( void )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_100 = 0 ;
V_7 = V_4 ;
while ( V_7 ) {
V_7 -> V_96 = 0 ;
if ( V_7 -> V_15 == 1 )
V_7 -> V_15 = V_45 ;
if ( V_7 -> V_17 == 0 )
V_7 -> V_17 = V_74 ;
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
V_9 -> V_96 = 0 ;
if ( V_9 -> V_15 == 1 )
V_9 -> V_15 = V_45 ;
if ( F_37 ( V_7 , V_9 ) ) {
V_9 -> V_96 = 1 ;
V_7 -> V_96 = 1 ;
V_100 ++ ;
}
if ( V_9 -> V_17 == 0 )
V_9 -> V_17 = V_74 ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
return V_100 ;
}
static int F_39 ( T_1 V_101 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_100 = 0 ;
if ( V_97 )
return F_38 () ;
V_7 = V_4 ;
while ( V_7 ) {
V_7 -> V_96 = 0 ;
if ( V_7 -> V_15 == 1 )
V_7 -> V_15 = V_45 ;
if ( V_7 -> V_17 == 0 )
V_7 -> V_17 = V_74 ;
if ( V_7 -> V_25 >= V_101 && ! V_102 )
V_7 -> V_96 = 1 ;
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
V_9 -> V_96 = 0 ;
if ( V_9 -> V_15 == 1 )
V_9 -> V_15 = V_45 ;
if ( V_9 -> V_25 >= V_101 && ! V_102 ) {
V_9 -> V_96 = 1 ;
V_100 ++ ;
}
if ( V_9 -> V_17 == 0 )
V_9 -> V_17 = V_74 ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
return V_100 ;
}
static void F_40 ( const char * V_103 )
{
T_1 V_104 ;
int V_100 ;
V_81 ++ ;
V_100 = F_39 ( V_105 ) ;
if ( V_100 < 15 )
V_100 = F_39 ( V_105 / 10 ) ;
F_41 ( V_103 , V_81 , V_100 , V_45 , V_74 ) ;
F_42 () ;
F_43 () ;
for ( V_104 = 0 ; V_104 < V_81 ; V_104 ++ )
F_44 ( V_104 , V_46 , V_48 ) ;
F_28 () ;
F_30 () ;
F_21 () ;
F_24 () ;
F_45 () ;
}
static int F_46 ( const char * V_106 , const char * V_107 )
{
struct V_26 V_108 = {
. V_6 = F_8 ,
. V_33 = F_9 ,
. exit = F_10 ,
. V_22 = F_16 ,
. V_109 = true ,
} ;
struct V_110 * V_111 = F_47 ( V_106 , V_112 ,
0 , false , & V_108 ) ;
int V_113 = - V_114 ;
if ( V_111 == NULL )
return - V_115 ;
if ( ! F_48 ( V_111 , L_14 ) )
goto V_116;
V_113 = F_49 ( V_111 , & V_108 ) ;
if ( V_113 )
goto V_116;
F_19 () ;
F_20 () ;
F_40 ( V_107 ) ;
F_50 ( L_15 ,
( V_74 - V_45 ) / 1000000000.0 , V_107 ) ;
V_116:
F_51 ( V_111 ) ;
return V_113 ;
}
static int F_52 ( int V_117 , const char * * V_118 )
{
#ifdef F_17
const char * const V_119 [] = {
L_16 , L_17 , L_18 , L_19 , L_20 , L_21 ,
L_22 , L_5 ,
L_22 , L_6 ,
L_22 , L_7 ,
L_22 , L_3 ,
L_22 , L_4 ,
} ;
#endif
const char * const V_120 [] = {
L_16 , L_17 , L_18 , L_19 , L_20 , L_21 ,
L_22 , L_2 ,
L_22 , L_1 ,
L_22 , L_3 ,
L_22 , L_4 ,
} ;
unsigned int V_121 , V_104 , V_122 ;
const char * * V_123 ;
const char * const * V_124 = V_120 ;
unsigned int V_125 = F_53 ( V_120 ) ;
#ifdef F_17
if ( ! F_54 ( L_1 ) &&
F_54 ( L_5 ) ) {
V_87 = 1 ;
V_124 = V_119 ;
V_125 = F_53 ( V_119 ) ;
}
#endif
V_121 = V_125 + V_117 - 1 ;
V_123 = calloc ( V_121 + 1 , sizeof( char * ) ) ;
if ( V_123 == NULL )
return - V_115 ;
for ( V_104 = 0 ; V_104 < V_125 ; V_104 ++ )
V_123 [ V_104 ] = F_4 ( V_124 [ V_104 ] ) ;
for ( V_122 = 1 ; V_122 < ( unsigned int ) V_117 ; V_122 ++ , V_104 ++ )
V_123 [ V_104 ] = V_118 [ V_122 ] ;
return F_55 ( V_104 , V_123 , NULL ) ;
}
static int
F_56 ( const struct V_126 * T_3 V_27 , const char * V_127 ,
int V_27 V_128 )
{
if ( V_127 )
F_35 ( V_127 ) ;
return 0 ;
}
int F_57 ( int V_117 , const char * * V_118 ,
const char * T_4 V_27 )
{
const char * V_106 ;
const char * V_107 = L_23 ;
const struct V_126 V_129 [] = {
F_58 ( 'i' , L_24 , & V_106 , L_25 , L_26 ) ,
F_58 ( 'o' , L_27 , & V_107 , L_25 , L_28 ) ,
F_59 ( 'w' , L_29 , & V_130 , L_30 ) ,
F_60 ( 'P' , L_31 , & V_102 , L_32 ) ,
F_61 ( 'p' , L_10 , NULL , L_10 ,
L_33 ,
F_56 ) ,
F_58 ( 0 , L_34 , & V_131 . V_132 , L_35 ,
L_36 ) ,
F_62 ()
} ;
const char * const V_133 [] = {
L_37 ,
NULL
} ;
V_117 = F_63 ( V_117 , V_118 , V_129 , V_133 ,
V_134 ) ;
F_64 () ;
if ( V_117 && ! strncmp ( V_118 [ 0 ] , L_38 , 3 ) )
return F_52 ( V_117 , V_118 ) ;
else if ( V_117 )
F_65 ( V_133 , V_129 ) ;
F_66 () ;
return F_46 ( V_106 , V_107 ) ;
}
