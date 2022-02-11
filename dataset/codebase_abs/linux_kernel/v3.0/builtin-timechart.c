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
static int F_7 ( union V_26 * V_27 ,
struct V_28 * V_22 V_29 ,
struct V_30 * T_2 V_29 )
{
F_2 ( V_27 -> V_6 . V_31 , V_27 -> V_6 . V_6 ) ;
return 0 ;
}
static int F_8 ( union V_26 * V_27 ,
struct V_28 * V_22 V_29 ,
struct V_30 * T_2 V_29 )
{
F_4 ( V_27 -> V_32 . V_2 , V_27 -> V_32 . V_12 , V_27 -> V_32 . time ) ;
return 0 ;
}
static int F_9 ( union V_26 * V_27 ,
struct V_28 * V_22 V_29 ,
struct V_30 * T_2 V_29 )
{
F_5 ( V_27 -> V_32 . V_2 , V_27 -> V_32 . time ) ;
return 0 ;
}
static void F_10 ( int V_18 , T_1 V_13 , int V_33 )
{
V_34 [ V_18 ] = V_13 ;
V_35 [ V_18 ] = V_33 ;
}
static void F_11 ( int V_18 , T_1 V_13 )
{
struct V_36 * V_37 ;
V_37 = malloc ( sizeof( struct V_36 ) ) ;
if ( ! V_37 )
return;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 -> V_33 = V_35 [ V_18 ] ;
V_37 -> V_15 = V_34 [ V_18 ] ;
V_37 -> V_17 = V_13 ;
V_37 -> V_18 = V_18 ;
V_37 -> type = V_38 ;
V_37 -> V_5 = V_39 ;
V_39 = V_37 ;
}
static void F_12 ( int V_18 , T_1 V_13 , T_1 V_40 )
{
struct V_36 * V_37 ;
V_37 = malloc ( sizeof( struct V_36 ) ) ;
if ( V_40 > 8000000 )
return;
if ( ! V_37 )
return;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 -> V_33 = V_41 [ V_18 ] ;
V_37 -> V_15 = V_42 [ V_18 ] ;
V_37 -> V_17 = V_13 ;
V_37 -> V_18 = V_18 ;
V_37 -> type = V_43 ;
V_37 -> V_5 = V_39 ;
if ( ! V_37 -> V_15 )
V_37 -> V_15 = V_44 ;
V_39 = V_37 ;
V_41 [ V_18 ] = V_40 ;
V_42 [ V_18 ] = V_13 ;
if ( ( T_1 ) V_40 > V_45 )
V_45 = V_40 ;
if ( V_40 < V_46 || V_46 == 0 )
V_46 = V_40 ;
if ( V_40 == V_45 - 1000 )
V_47 = V_45 ;
}
static void
F_13 ( int V_18 , T_1 V_13 , int V_2 , struct V_48 * V_49 )
{
struct V_50 * V_51 ;
struct V_1 * V_7 ;
struct V_52 * V_53 = ( void * ) V_49 ;
V_51 = malloc ( sizeof( struct V_50 ) ) ;
if ( ! V_51 )
return;
memset ( V_51 , 0 , sizeof( struct V_50 ) ) ;
V_51 -> time = V_13 ;
V_51 -> V_54 = V_2 ;
if ( ( V_49 -> V_55 & V_56 ) || ( V_49 -> V_55 & V_57 ) )
V_51 -> V_54 = - 1 ;
V_51 -> V_58 = V_53 -> V_2 ;
V_51 -> V_5 = V_59 ;
V_59 = V_51 ;
V_7 = F_1 ( V_51 -> V_58 ) ;
if ( V_7 && V_7 -> V_11 && V_7 -> V_11 -> V_33 == V_60 ) {
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_33 = V_61 ;
}
if ( V_7 && V_7 -> V_11 && V_7 -> V_11 -> V_33 == V_62 ) {
F_6 ( V_7 -> V_2 , V_7 -> V_11 -> V_33 , V_18 , V_7 -> V_11 -> V_16 , V_13 ) ;
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_33 = V_61 ;
}
}
static void F_14 ( int V_18 , T_1 V_13 , struct V_48 * V_49 )
{
struct V_1 * V_7 = NULL , * V_63 ;
struct F_14 * V_64 = ( void * ) V_49 ;
V_63 = F_1 ( V_64 -> V_65 ) ;
V_7 = F_1 ( V_64 -> V_66 ) ;
if ( V_63 -> V_11 && V_63 -> V_11 -> V_33 != V_60 )
F_6 ( V_64 -> V_65 , V_24 , V_18 , V_63 -> V_11 -> V_16 , V_13 ) ;
if ( V_7 && V_7 -> V_11 ) {
if ( V_7 -> V_11 -> V_33 != V_60 )
F_6 ( V_64 -> V_66 , V_7 -> V_11 -> V_33 , V_18 , V_7 -> V_11 -> V_16 , V_13 ) ;
V_7 -> V_11 -> V_16 = V_13 ;
V_7 -> V_11 -> V_33 = V_24 ;
}
if ( V_63 -> V_11 ) {
V_63 -> V_11 -> V_33 = V_60 ;
V_63 -> V_11 -> V_16 = V_13 ;
if ( V_64 -> V_67 & 2 )
V_63 -> V_11 -> V_33 = V_62 ;
if ( V_64 -> V_67 == 0 )
V_63 -> V_11 -> V_33 = V_61 ;
}
}
static int F_15 ( union V_26 * V_27 V_29 ,
struct V_28 * V_22 ,
struct V_68 * T_3 V_29 ,
struct V_30 * T_2 )
{
struct V_48 * V_49 ;
if ( T_2 -> V_69 & V_70 ) {
if ( ! V_44 || V_44 > V_22 -> time )
V_44 = V_22 -> time ;
if ( V_71 < V_22 -> time )
V_71 = V_22 -> time ;
}
V_49 = ( void * ) V_22 -> V_72 ;
if ( T_2 -> V_69 & V_73 && V_22 -> V_74 > 0 ) {
char * V_75 ;
#ifdef F_16
struct V_76 * V_77 ;
V_77 = ( void * ) V_49 ;
#endif
V_75 = F_17 ( V_49 -> type ) ;
if ( ! V_75 )
return 0 ;
if ( V_22 -> V_18 > V_78 )
V_78 = V_22 -> V_18 ;
if ( strcmp ( V_75 , L_1 ) == 0 ) {
struct V_79 * V_80 = ( void * ) V_49 ;
if ( V_80 -> V_33 == ( V_81 ) V_82 )
F_11 ( V_80 -> V_83 , V_22 -> time ) ;
else
F_10 ( V_80 -> V_83 , V_22 -> time ,
V_80 -> V_33 ) ;
}
else if ( strcmp ( V_75 , L_2 ) == 0 ) {
struct V_79 * V_80 = ( void * ) V_49 ;
F_12 ( V_80 -> V_83 , V_22 -> time , V_80 -> V_33 ) ;
}
else if ( strcmp ( V_75 , L_3 ) == 0 )
F_13 ( V_22 -> V_18 , V_22 -> time , V_22 -> V_2 , V_49 ) ;
else if ( strcmp ( V_75 , L_4 ) == 0 )
F_14 ( V_22 -> V_18 , V_22 -> time , V_49 ) ;
#ifdef F_16
if ( V_84 ) {
if ( strcmp ( V_75 , L_5 ) == 0 )
F_10 ( V_77 -> V_83 , V_22 -> time ,
V_77 -> V_85 ) ;
else if ( strcmp ( V_75 , L_6 ) == 0 )
F_11 ( V_22 -> V_18 , V_22 -> time ) ;
else if ( strcmp ( V_75 ,
L_7 ) == 0 )
F_12 ( V_77 -> V_83 , V_22 -> time ,
V_77 -> V_85 ) ;
}
#endif
}
return 0 ;
}
static void F_18 ( void )
{
T_1 V_18 ;
struct V_36 * V_37 ;
for ( V_18 = 0 ; V_18 <= V_78 ; V_18 ++ ) {
V_37 = malloc ( sizeof( struct V_36 ) ) ;
if ( ! V_37 )
return;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
#if 0
pwr->state = cpus_cstate_state[cpu];
pwr->start_time = cpus_cstate_start_times[cpu];
pwr->end_time = last_time;
pwr->cpu = cpu;
pwr->type = CSTATE;
pwr->next = power_events;
power_events = pwr;
#endif
V_37 = malloc ( sizeof( struct V_36 ) ) ;
if ( ! V_37 )
return;
memset ( V_37 , 0 , sizeof( struct V_36 ) ) ;
V_37 -> V_33 = V_41 [ V_18 ] ;
V_37 -> V_15 = V_42 [ V_18 ] ;
V_37 -> V_17 = V_71 ;
V_37 -> V_18 = V_18 ;
V_37 -> type = V_43 ;
V_37 -> V_5 = V_39 ;
if ( ! V_37 -> V_15 )
V_37 -> V_15 = V_44 ;
if ( ! V_37 -> V_33 )
V_37 -> V_33 = V_46 ;
V_39 = V_37 ;
}
}
static void F_19 ( void )
{
struct V_1 * V_86 , * V_7 , * V_3 , * V_87 ;
V_86 = NULL ;
while ( V_4 ) {
V_7 = V_4 ;
V_4 = V_7 -> V_5 ;
V_7 -> V_5 = NULL ;
if ( V_86 == NULL ) {
V_86 = V_7 ;
V_7 -> V_5 = NULL ;
continue;
}
V_87 = NULL ;
V_3 = V_86 ;
while ( V_3 ) {
if ( V_3 -> V_12 > V_7 -> V_12 ||
( V_3 -> V_12 == V_7 -> V_12 && V_3 -> V_2 > V_7 -> V_2 ) ) {
if ( V_87 ) {
V_7 -> V_5 = V_87 -> V_5 ;
V_87 -> V_5 = V_7 ;
V_3 = NULL ;
continue;
} else {
V_7 -> V_5 = V_86 ;
V_86 = V_7 ;
V_3 = NULL ;
continue;
}
}
V_87 = V_3 ;
V_3 = V_3 -> V_5 ;
if ( ! V_3 )
V_87 -> V_5 = V_7 ;
}
}
V_4 = V_86 ;
}
static void F_20 ( void )
{
struct V_36 * V_37 ;
V_37 = V_39 ;
while ( V_37 ) {
if ( V_37 -> type == V_38 )
F_21 ( V_37 -> V_18 , V_37 -> V_15 , V_37 -> V_17 , V_37 -> V_33 ) ;
V_37 = V_37 -> V_5 ;
}
V_37 = V_39 ;
while ( V_37 ) {
if ( V_37 -> type == V_43 ) {
if ( ! V_37 -> V_33 )
V_37 -> V_33 = V_46 ;
F_22 ( V_37 -> V_18 , V_37 -> V_15 , V_37 -> V_17 , V_37 -> V_33 ) ;
}
V_37 = V_37 -> V_5 ;
}
}
static void F_23 ( void )
{
struct V_50 * V_51 ;
struct V_1 * V_7 ;
struct V_8 * V_9 ;
V_51 = V_59 ;
while ( V_51 ) {
int V_88 = 0 , V_89 = 0 ;
char * V_90 = NULL , * V_91 = NULL ;
V_7 = V_4 ;
while ( V_7 ) {
if ( V_7 -> V_2 == V_51 -> V_54 || V_7 -> V_2 == V_51 -> V_58 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_9 -> V_92 && V_9 -> V_15 <= V_51 -> time && V_9 -> V_17 >= V_51 -> time ) {
if ( V_7 -> V_2 == V_51 -> V_54 && ! V_88 ) {
V_88 = V_9 -> V_92 ;
V_90 = F_3 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_51 -> V_58 && ! V_89 ) {
V_89 = V_9 -> V_92 ;
V_91 = F_3 ( V_9 -> V_6 ) ;
}
}
V_9 = V_9 -> V_5 ;
}
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( V_7 -> V_2 == V_51 -> V_54 && ! V_88 ) {
V_88 = V_9 -> V_92 ;
V_90 = F_3 ( V_9 -> V_6 ) ;
}
if ( V_7 -> V_2 == V_51 -> V_58 && ! V_89 ) {
V_89 = V_9 -> V_92 ;
V_91 = F_3 ( V_9 -> V_6 ) ;
}
V_9 = V_9 -> V_5 ;
}
}
V_7 = V_7 -> V_5 ;
}
if ( ! V_90 ) {
V_90 = malloc ( 40 ) ;
sprintf ( V_90 , L_8 , V_51 -> V_54 ) ;
}
if ( ! V_91 ) {
V_91 = malloc ( 40 ) ;
sprintf ( V_91 , L_8 , V_51 -> V_58 ) ;
}
if ( V_51 -> V_54 == - 1 )
F_24 ( V_51 -> time , V_89 ) ;
else if ( V_88 && V_89 && abs ( V_88 - V_89 ) == 1 )
F_25 ( V_51 -> time , V_88 , V_89 ) ;
else
F_26 ( V_51 -> time , V_88 , V_90 , V_89 , V_91 ) ;
V_51 = V_51 -> V_5 ;
free ( V_90 ) ;
free ( V_91 ) ;
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
int V_92 = 0 ;
V_92 = 2 * V_78 + 2 ;
V_7 = V_4 ;
while ( V_7 ) {
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
if ( ! V_9 -> V_93 ) {
V_9 -> V_92 = 0 ;
V_9 = V_9 -> V_5 ;
continue;
}
F_30 ( V_92 , V_9 -> V_15 , V_9 -> V_17 , L_10 ) ;
V_22 = V_9 -> V_23 ;
while ( V_22 ) {
if ( V_22 -> type == V_24 )
F_31 ( V_92 , V_22 -> V_18 , V_22 -> V_15 , V_22 -> V_17 ) ;
if ( V_22 -> type == V_62 )
F_30 ( V_92 , V_22 -> V_15 , V_22 -> V_17 , L_11 ) ;
if ( V_22 -> type == V_61 )
F_32 ( V_92 , V_22 -> V_15 , V_22 -> V_17 ) ;
V_22 = V_22 -> V_5 ;
}
if ( V_9 -> V_6 ) {
char V_6 [ 256 ] ;
if ( V_9 -> V_25 > 5000000000 )
sprintf ( V_6 , L_12 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000000.0 ) ;
else
sprintf ( V_6 , L_13 , V_9 -> V_6 , V_7 -> V_2 , V_9 -> V_25 / 1000000.0 ) ;
F_33 ( V_92 , V_9 -> V_15 , V_6 ) ;
}
V_9 -> V_92 = V_92 ;
V_92 ++ ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
}
static void F_34 ( const char * string )
{
struct V_94 * V_95 ;
int V_2 ;
V_2 = F_35 ( string , NULL , 10 ) ;
V_95 = malloc ( sizeof( struct V_94 ) ) ;
if ( ! V_95 )
return;
V_95 -> V_96 = F_3 ( string ) ;
V_95 -> V_2 = V_2 ;
V_95 -> V_5 = V_94 ;
V_94 = V_95 ;
}
static int F_36 ( struct V_1 * V_7 , struct V_8 * V_9 )
{
struct V_94 * V_95 ;
if ( ! V_94 )
return 1 ;
V_95 = V_94 ;
while ( V_95 ) {
if ( V_95 -> V_2 && V_7 -> V_2 == V_95 -> V_2 )
return 1 ;
if ( strcmp ( V_95 -> V_96 , V_9 -> V_6 ) == 0 )
return 1 ;
V_95 = V_95 -> V_5 ;
}
return 0 ;
}
static int F_37 ( void )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_97 = 0 ;
V_7 = V_4 ;
while ( V_7 ) {
V_7 -> V_93 = 0 ;
if ( V_7 -> V_15 == 1 )
V_7 -> V_15 = V_44 ;
if ( V_7 -> V_17 == 0 )
V_7 -> V_17 = V_71 ;
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
V_9 -> V_93 = 0 ;
if ( V_9 -> V_15 == 1 )
V_9 -> V_15 = V_44 ;
if ( F_36 ( V_7 , V_9 ) ) {
V_9 -> V_93 = 1 ;
V_7 -> V_93 = 1 ;
V_97 ++ ;
}
if ( V_9 -> V_17 == 0 )
V_9 -> V_17 = V_71 ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
return V_97 ;
}
static int F_38 ( T_1 V_98 )
{
struct V_1 * V_7 ;
struct V_8 * V_9 ;
int V_97 = 0 ;
if ( V_94 )
return F_37 () ;
V_7 = V_4 ;
while ( V_7 ) {
V_7 -> V_93 = 0 ;
if ( V_7 -> V_15 == 1 )
V_7 -> V_15 = V_44 ;
if ( V_7 -> V_17 == 0 )
V_7 -> V_17 = V_71 ;
if ( V_7 -> V_25 >= V_98 && ! V_99 )
V_7 -> V_93 = 1 ;
V_9 = V_7 -> V_10 ;
while ( V_9 ) {
V_9 -> V_93 = 0 ;
if ( V_9 -> V_15 == 1 )
V_9 -> V_15 = V_44 ;
if ( V_9 -> V_25 >= V_98 && ! V_99 ) {
V_9 -> V_93 = 1 ;
V_97 ++ ;
}
if ( V_9 -> V_17 == 0 )
V_9 -> V_17 = V_71 ;
V_9 = V_9 -> V_5 ;
}
V_7 = V_7 -> V_5 ;
}
return V_97 ;
}
static void F_39 ( const char * V_100 )
{
T_1 V_101 ;
int V_97 ;
V_78 ++ ;
V_97 = F_38 ( V_102 ) ;
if ( V_97 < 15 )
V_97 = F_38 ( V_102 / 10 ) ;
F_40 ( V_100 , V_78 , V_97 , V_44 , V_71 ) ;
F_41 () ;
F_42 () ;
for ( V_101 = 0 ; V_101 < V_78 ; V_101 ++ )
F_43 ( V_101 , V_45 , V_47 ) ;
F_27 () ;
F_29 () ;
F_20 () ;
F_23 () ;
F_44 () ;
}
static int F_45 ( void )
{
struct V_30 * T_2 = F_46 ( V_103 , V_104 ,
0 , false , & V_105 ) ;
int V_106 = - V_107 ;
if ( T_2 == NULL )
return - V_108 ;
if ( ! F_47 ( T_2 , L_14 ) )
goto V_109;
V_106 = F_48 ( T_2 , & V_105 ) ;
if ( V_106 )
goto V_109;
F_18 () ;
F_19 () ;
F_39 ( V_110 ) ;
F_49 ( L_15 ,
( V_71 - V_44 ) / 1000000000.0 , V_110 ) ;
V_109:
F_50 ( T_2 ) ;
return V_106 ;
}
static int F_51 ( int V_111 , const char * * V_112 )
{
unsigned int V_113 , V_101 , V_114 ;
const char * * V_115 ;
const char * const * V_116 = V_117 ;
unsigned int V_118 = F_52 ( V_117 ) ;
#ifdef F_16
if ( ! F_53 ( L_1 ) &&
F_53 ( L_5 ) ) {
V_84 = 1 ;
V_116 = V_119 ;
V_118 = F_52 ( V_119 ) ;
}
#endif
V_113 = V_118 + V_111 - 1 ;
V_115 = calloc ( V_113 + 1 , sizeof( char * ) ) ;
if ( V_115 == NULL )
return - V_108 ;
for ( V_101 = 0 ; V_101 < V_118 ; V_101 ++ )
V_115 [ V_101 ] = F_3 ( V_116 [ V_101 ] ) ;
for ( V_114 = 1 ; V_114 < ( unsigned int ) V_111 ; V_114 ++ , V_101 ++ )
V_115 [ V_101 ] = V_112 [ V_114 ] ;
return F_54 ( V_101 , V_115 , NULL ) ;
}
static int
F_55 ( const struct V_120 * T_4 V_29 , const char * V_121 , int V_29 V_122 )
{
if ( V_121 )
F_34 ( V_121 ) ;
return 0 ;
}
int F_56 ( int V_111 , const char * * V_112 , const char * T_5 V_29 )
{
V_111 = F_57 ( V_111 , V_112 , V_123 , V_124 ,
V_125 ) ;
F_58 () ;
if ( V_111 && ! strncmp ( V_112 [ 0 ] , L_16 , 3 ) )
return F_51 ( V_111 , V_112 ) ;
else if ( V_111 )
F_59 ( V_124 , V_123 ) ;
F_60 () ;
return F_45 () ;
}
