static struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 = V_4 ;
while ( V_3 ) {
if ( V_3 -> V_2 == V_2 )
return V_3 ;
V_3 = V_3 -> V_5 ;
}
V_3 = malloc ( sizeof( struct V_1 ) ) ;
assert ( V_3 != NULL ) ;
memset ( V_3 , 0 , sizeof( struct V_1 ) ) ;
V_3 -> V_2 = V_2 ;
V_3 -> V_5 = V_4 ;
V_4 = V_3 ;
return V_3 ;
}
static void F_2 ( int V_2 , char * V_6 )
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
V_9 -> V_6 = F_3 ( V_6 ) ;
V_7 -> V_11 = V_9 ;
return;
}
V_9 = V_9 -> V_5 ;
}
V_9 = malloc ( sizeof( struct V_8 ) ) ;
assert ( V_9 != NULL ) ;
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_9 -> V_6 = F_3 ( V_6 ) ;
V_7 -> V_11 = V_9 ;
V_9 -> V_5 = V_7 -> V_10 ;
V_7 -> V_10 = V_9 ;
}
static void F_4 ( int V_2 , int V_12 , T_1 V_13 )
{
struct V_1 * V_7 , * V_14 ;
V_7 = F_1 ( V_2 ) ;
V_14 = F_1 ( V_12 ) ;
V_7 -> V_12 = V_12 ;
if ( V_14 -> V_11 && V_14 -> V_11 -> V_6 && ! V_7 -> V_11 )
F_2 ( V_2 , V_14 -> V_11 -> V_6 ) ;
V_7 -> V_15 = V_13 ;
if ( V_7 -> V_11 ) {
V_7 -> V_11 -> V_15 = V_13 ;
V_7 -> V_11 -> V_16 = V_13 ;
}
}
static void F_5 ( int V_2 , T_1 V_13 )
{
struct V_1 * V_7 ;
V_7 = F_1 ( V_2 ) ;
V_7 -> V_17 = V_13 ;
if ( V_7 -> V_11 )
V_7 -> V_11 -> V_17 = V_13 ;
}
static void
F_6 ( int V_2 , int type , unsigned int V_18 , T_1 V_19 , T_1 V_20 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
struct V_21 * V_22 ;
V_7 = F_1 ( V_2 ) ;
V_9 = V_7 -> V_11 ;
if ( ! V_9 ) {
V_9 = malloc ( sizeof( struct V_8 ) ) ;
assert ( V_9 != NULL ) ;
memset ( V_9 , 0 , sizeof( struct V_8 ) ) ;
V_7 -> V_11 = V_9 ;
V_9 -> V_5 = V_7 -> V_10 ;
V_7 -> V_10 = V_9 ;
}
V_22 = malloc ( sizeof( struct V_21 ) ) ;
assert ( V_22 != NULL ) ;
memset ( V_22 , 0 , sizeof( struct V_21 ) ) ;
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
static int F_7 ( struct V_26 * T_2 V_27 ,
union V_28 * V_29 ,
struct V_30 * V_22 V_27 ,
struct V_31 * V_31 V_27 )
{
F_2 ( V_29 -> V_6 . V_32 , V_29 -> V_6 . V_6 ) ;
return 0 ;
}
static int F_8 ( struct V_26 * T_2 V_27 ,
union V_28 * V_29 ,
struct V_30 * V_22 V_27 ,
struct V_31 * V_31 V_27 )
{
F_4 ( V_29 -> V_33 . V_2 , V_29 -> V_33 . V_12 , V_29 -> V_33 . time ) ;
return 0 ;
}
static int F_9 ( struct V_26 * T_2 V_27 ,
union V_28 * V_29 ,
struct V_30 * V_22 V_27 ,
struct V_31 * V_31 V_27 )
{
F_5 ( V_29 -> V_33 . V_2 , V_29 -> V_33 . time ) ;
return 0 ;
}
static void F_10 ( int V_18 , T_1 V_13 , int V_34 )
{
V_35 [ V_18 ] = V_13 ;
V_36 [ V_18 ] = V_34 ;
}
static void F_11 ( int V_18 , T_1 V_13 )
{
struct V_37 * V_38 ;
V_38 = malloc ( sizeof( struct V_37 ) ) ;
if ( ! V_38 )
return;
memset ( V_38 , 0 , sizeof( struct V_37 ) ) ;
V_38 -> V_34 = V_36 [ V_18 ] ;
V_38 -> V_15 = V_35 [ V_18 ] ;
V_38 -> V_17 = V_13 ;
V_38 -> V_18 = V_18 ;
V_38 -> type = V_39 ;
V_38 -> V_5 = V_40 ;
V_40 = V_38 ;
}
static void F_12 ( int V_18 , T_1 V_13 , T_1 V_41 )
{
struct V_37 * V_38 ;
V_38 = malloc ( sizeof( struct V_37 ) ) ;
if ( V_41 > 8000000 )
return;
if ( ! V_38 )
return;
memset ( V_38 , 0 , sizeof( struct V_37 ) ) ;
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
F_13 ( int V_18 , T_1 V_13 , int V_2 , struct V_49 * V_50 )
{
struct V_51 * V_52 ;
struct V_1 * V_7 ;
struct V_53 * V_54 = ( void * ) V_50 ;
V_52 = malloc ( sizeof( struct V_51 ) ) ;
if ( ! V_52 )
return;
memset ( V_52 , 0 , sizeof( struct V_51 ) ) ;
V_52 -> time = V_13 ;
V_52 -> V_55 = V_2 ;
if ( ( V_50 -> V_56 & V_57 ) || ( V_50 -> V_56 & V_58 ) )
V_52 -> V_55 = - 1 ;
V_52 -> V_59 = V_54 -> V_2 ;
V_52 -> V_5 = V_60 ;
V_60 = V_52 ;
V_7 = F_1 ( V_52 -> V_59 ) ;
if ( V_7 && V_7 -> V_11 && V_7 -> V_11 -> V_34 == V_61 ) {
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_34 = V_62 ;
}
if ( V_7 && V_7 -> V_11 && V_7 -> V_11 -> V_34 == V_63 ) {
F_6 ( V_7 -> V_2 , V_7 -> V_11 -> V_34 , V_18 , V_7 -> V_11 -> V_16 , V_13 ) ;
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_34 = V_62 ;
}
}
static void F_14 ( int V_18 , T_1 V_13 , struct V_49 * V_50 )
{
struct V_1 * V_7 = NULL , * V_64 ;
struct F_14 * V_65 = ( void * ) V_50 ;
V_64 = F_1 ( V_65 -> V_66 ) ;
V_7 = F_1 ( V_65 -> V_67 ) ;
if ( V_64 -> V_11 && V_64 -> V_11 -> V_34 != V_61 )
F_6 ( V_65 -> V_66 , V_24 , V_18 , V_64 -> V_11 -> V_16 , V_13 ) ;
if ( V_7 && V_7 -> V_11 ) {
if ( V_7 -> V_11 -> V_34 != V_61 )
F_6 ( V_65 -> V_67 , V_7 -> V_11 -> V_34 , V_18 , V_7 -> V_11 -> V_16 , V_13 ) ;
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
static int F_15 ( struct V_26 * T_2 V_27 ,
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
#ifdef F_16
struct V_79 * V_80 ;
V_80 = ( void * ) V_50 ;
#endif
V_78 = F_17 ( V_50 -> type ) ;
if ( ! V_78 )
return 0 ;
if ( V_22 -> V_18 > V_81 )
V_81 = V_22 -> V_18 ;
if ( strcmp ( V_78 , L_1 ) == 0 ) {
struct V_82 * V_83 = ( void * ) V_50 ;
if ( V_83 -> V_34 == ( V_84 ) V_85 )
F_11 ( V_83 -> V_86 , V_22 -> time ) ;
else
F_10 ( V_83 -> V_86 , V_22 -> time ,
V_83 -> V_34 ) ;
}
else if ( strcmp ( V_78 , L_2 ) == 0 ) {
struct V_82 * V_83 = ( void * ) V_50 ;
F_12 ( V_83 -> V_86 , V_22 -> time , V_83 -> V_34 ) ;
}
else if ( strcmp ( V_78 , L_3 ) == 0 )
F_13 ( V_22 -> V_18 , V_22 -> time , V_22 -> V_2 , V_50 ) ;
else if ( strcmp ( V_78 , L_4 ) == 0 )
F_14 ( V_22 -> V_18 , V_22 -> time , V_50 ) ;
#ifdef F_16
if ( V_87 ) {
if ( strcmp ( V_78 , L_5 ) == 0 )
F_10 ( V_80 -> V_86 , V_22 -> time ,
V_80 -> V_88 ) ;
else if ( strcmp ( V_78 , L_6 ) == 0 )
F_11 ( V_22 -> V_18 , V_22 -> time ) ;
else if ( strcmp ( V_78 ,
L_7 ) == 0 )
F_12 ( V_80 -> V_86 , V_22 -> time ,
V_80 -> V_88 ) ;
}
#endif
}
return 0 ;
}
static void F_18 ( void )
{
T_1 V_18 ;
struct V_37 * V_38 ;
for ( V_18 = 0 ; V_18 <= V_81 ; V_18 ++ ) {
V_38 = malloc ( sizeof( struct V_37 ) ) ;
if ( ! V_38 )
return;
memset ( V_38 , 0 , sizeof( struct V_37 ) ) ;
#if 0
pwr->state = cpus_cstate_state[cpu];
pwr->start_time = cpus_cstate_start_times[cpu];
pwr->end_time = last_time;
pwr->cpu = cpu;
pwr->type = CSTATE;
pwr->next = power_events;
power_events = pwr;
#endif
V_38 = malloc ( sizeof( struct V_37 ) ) ;
if ( ! V_38 )
return;
memset ( V_38 , 0 , sizeof( struct V_37 ) ) ;
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
static void F_19 ( void )
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
static void F_20 ( void )
{
struct V_37 * V_38 ;
V_38 = V_40 ;
while ( V_38 ) {
if ( V_38 -> type == V_39 )
F_21 ( V_38 -> V_18 , V_38 -> V_15 , V_38 -> V_17 , V_38 -> V_34 ) ;
V_38 = V_38 -> V_5 ;
}
V_38 = V_40 ;
while ( V_38 ) {
if ( V_38 -> type == V_44 ) {
if ( ! V_38 -> V_34 )
V_38 -> V_34 = V_47 ;
F_22 ( V_38 -> V_18 , V_38 -> V_15 , V_38 -> V_17 , V_38 -> V_34 ) ;
}
V_38 = V_38 -> V_5 ;
}
}
static void F_23 ( void )
{
struct V_51 * V_52 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_52 = V_60 ;
while ( V_52 ) {
int V_91 = 0 , V_92 = 0 ;
char * V_93 = NULL , * V_94 = NULL ;
V_7 = V_4 ;
while ( V_7 ) {
if ( V_7 -> V_2 == V_52 -> V_55 || V_7 -> V_2 == V_52 -> V_59 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_9 -> V_95 && V_9 -> V_15 <= V_52 -> time && V_9 -> V_17 >= V_52 -> time ) {
if ( V_7 -> V_2 == V_52 -> V_55 && ! V_91 ) {
V_91 = V_9 -> V_95 ;
V_93 = F_3 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_52 -> V_59 && ! V_92 ) {
V_92 = V_9 -> V_95 ;
V_94 = F_3 ( V_9 -> V_6 ) ;
}
}
V_9 = V_9 -> V_5 ;
}
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_7 -> V_2 == V_52 -> V_55 && ! V_91 ) {
V_91 = V_9 -> V_95 ;
V_93 = F_3 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_52 -> V_59 && ! V_92 ) {
V_92 = V_9 -> V_95 ;
V_94 = F_3 ( V_9 -> V_6 ) ;
}
V_9 = V_9 -> V_5 ;
}
}
V_7 = V_7 -> V_5 ;
}
if ( ! V_93 ) {
V_93 = malloc ( 40 ) ;
sprintf ( V_93 , L_8 , V_52 -> V_55 ) ;
}
if ( ! V_94 ) {
V_94 = malloc ( 40 ) ;
sprintf ( V_94 , L_8 , V_52 -> V_59 ) ;
}
if ( V_52 -> V_55 == - 1 )
F_24 ( V_52 -> time , V_92 ) ;
else if ( V_91 && V_92 && abs ( V_91 - V_92 ) == 1 )
F_25 ( V_52 -> time , V_91 , V_92 ) ;
else
F_26 ( V_52 -> time , V_91 , V_93 , V_92 , V_94 ) ;
V_52 = V_52 -> V_5 ;
free ( V_93 ) ;
free ( V_94 ) ;
}
}
static void F_27 ( void )
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
F_28 ( V_22 -> V_18 , V_22 -> V_15 , V_22 -> V_17 , L_9 , V_9 -> V_6 ) ;
V_22 = V_22 -> V_5 ;
}
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
}
static void F_29 ( void )
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
F_30 ( V_95 , V_9 -> V_15 , V_9 -> V_17 , L_10 ) ;
V_22 = V_9 -> V_23 ;
while ( V_22 ) {
if ( V_22 -> type == V_24 )
F_31 ( V_95 , V_22 -> V_18 , V_22 -> V_15 , V_22 -> V_17 ) ;
if ( V_22 -> type == V_63 )
F_30 ( V_95 , V_22 -> V_15 , V_22 -> V_17 , L_11 ) ;
if ( V_22 -> type == V_62 )
F_32 ( V_95 , V_22 -> V_15 , V_22 -> V_17 ) ;
V_22 = V_22 -> V_5 ;
}
if ( V_9 -> V_6 ) {
char V_6 [ 256 ] ;
if ( V_9 -> V_25 > 5000000000 )
sprintf ( V_6 , L_12 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000000.0 ) ;
else
sprintf ( V_6 , L_13 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000.0 ) ;
F_33 ( V_95 , V_9 -> V_15 , V_6 ) ;
}
V_9 -> V_95 = V_95 ;
V_95 ++ ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
}
static void F_34 ( const char * string )
{
struct V_97 * V_98 ;
int V_2 ;
V_2 = F_35 ( string , NULL , 10 ) ;
V_98 = malloc ( sizeof( struct V_97 ) ) ;
if ( ! V_98 )
return;
V_98 -> V_99 = F_3 ( string ) ;
V_98 -> V_2 = V_2 ;
V_98 -> V_5 = V_97 ;
V_97 = V_98 ;
}
static int F_36 ( struct V_1 * V_7 , struct V_8 * V_9 )
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
static int F_37 ( void )
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
if ( F_36 ( V_7 , V_9 ) ) {
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
static int F_38 ( T_1 V_101 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_100 = 0 ;
if ( V_97 )
return F_37 () ;
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
static void F_39 ( const char * V_103 )
{
T_1 V_104 ;
int V_100 ;
V_81 ++ ;
V_100 = F_38 ( V_105 ) ;
if ( V_100 < 15 )
V_100 = F_38 ( V_105 / 10 ) ;
F_40 ( V_103 , V_81 , V_100 , V_45 , V_74 ) ;
F_41 () ;
F_42 () ;
for ( V_104 = 0 ; V_104 < V_81 ; V_104 ++ )
F_43 ( V_104 , V_46 , V_48 ) ;
F_27 () ;
F_29 () ;
F_20 () ;
F_23 () ;
F_44 () ;
}
static int F_45 ( void )
{
struct V_106 * V_107 = F_46 ( V_108 , V_109 ,
0 , false , & V_110 ) ;
int V_111 = - V_112 ;
if ( V_107 == NULL )
return - V_113 ;
if ( ! F_47 ( V_107 , L_14 ) )
goto V_114;
V_111 = F_48 ( V_107 , & V_110 ) ;
if ( V_111 )
goto V_114;
F_18 () ;
F_19 () ;
F_39 ( V_115 ) ;
F_49 ( L_15 ,
( V_74 - V_45 ) / 1000000000.0 , V_115 ) ;
V_114:
F_50 ( V_107 ) ;
return V_111 ;
}
static int F_51 ( int V_116 , const char * * V_117 )
{
unsigned int V_118 , V_104 , V_119 ;
const char * * V_120 ;
const char * const * V_121 = V_122 ;
unsigned int V_123 = F_52 ( V_122 ) ;
#ifdef F_16
if ( ! F_53 ( L_1 ) &&
F_53 ( L_5 ) ) {
V_87 = 1 ;
V_121 = V_124 ;
V_123 = F_52 ( V_124 ) ;
}
#endif
V_118 = V_123 + V_116 - 1 ;
V_120 = calloc ( V_118 + 1 , sizeof( char * ) ) ;
if ( V_120 == NULL )
return - V_113 ;
for ( V_104 = 0 ; V_104 < V_123 ; V_104 ++ )
V_120 [ V_104 ] = F_3 ( V_121 [ V_104 ] ) ;
for ( V_119 = 1 ; V_119 < ( unsigned int ) V_116 ; V_119 ++ , V_104 ++ )
V_120 [ V_104 ] = V_117 [ V_119 ] ;
return F_54 ( V_104 , V_120 , NULL ) ;
}
static int
F_55 ( const struct V_125 * T_3 V_27 , const char * V_126 , int V_27 V_127 )
{
if ( V_126 )
F_34 ( V_126 ) ;
return 0 ;
}
int F_56 ( int V_116 , const char * * V_117 , const char * T_4 V_27 )
{
V_116 = F_57 ( V_116 , V_117 , V_128 , V_129 ,
V_130 ) ;
F_58 () ;
if ( V_116 && ! strncmp ( V_117 [ 0 ] , L_16 , 3 ) )
return F_51 ( V_116 , V_117 ) ;
else if ( V_116 )
F_59 ( V_129 , V_128 ) ;
F_60 () ;
return F_45 () ;
}
