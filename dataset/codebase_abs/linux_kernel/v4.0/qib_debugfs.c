static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_4 * V_5 ;
if ( * V_3 >= F_2 ( V_5 -> V_6 ) )
return NULL ;
return V_3 ;
}
static void * F_3 ( struct V_1 * V_2 , void * V_7 , T_1 * V_3 )
{
struct V_4 * V_5 ;
++ * V_3 ;
if ( * V_3 >= F_2 ( V_5 -> V_6 ) )
return NULL ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 , void * V_7 )
{
}
static int F_5 ( struct V_1 * V_2 , void * V_7 )
{
T_1 * V_8 = V_7 ;
T_1 V_9 = * V_8 , V_10 ;
T_2 V_11 = 0 , V_12 = 0 ;
struct V_13 * V_14 = (struct V_13 * ) V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_14 ) ;
for ( V_10 = 0 ; V_10 < V_17 -> V_18 ; V_10 ++ ) {
if ( ! V_17 -> V_19 [ V_10 ] )
continue;
V_11 += V_17 -> V_19 [ V_10 ] -> V_5 -> V_6 [ V_9 ] . V_11 ;
V_12 += V_17 -> V_19 [ V_10 ] -> V_5 -> V_6 [ V_9 ] . V_12 ;
}
if ( ! V_11 && ! V_12 )
return V_20 ;
F_7 ( V_2 , L_1 , V_9 ,
( unsigned long long ) V_11 ,
( unsigned long long ) V_12 ) ;
return 0 ;
}
static void * F_8 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_13 * V_14 = (struct V_13 * ) V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_14 ) ;
if ( ! * V_3 )
return V_21 ;
if ( * V_3 >= V_17 -> V_18 )
return NULL ;
return V_3 ;
}
static void * F_9 ( struct V_1 * V_2 , void * V_7 , T_1 * V_3 )
{
struct V_13 * V_14 = (struct V_13 * ) V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_14 ) ;
if ( V_7 == V_21 )
return V_3 ;
++ * V_3 ;
if ( * V_3 >= V_17 -> V_18 )
return NULL ;
return V_3 ;
}
static void F_10 ( struct V_1 * V_2 , void * V_7 )
{
}
static int F_11 ( struct V_1 * V_2 , void * V_7 )
{
T_1 * V_8 ;
T_1 V_9 , V_10 ;
T_2 V_11 = 0 ;
struct V_13 * V_14 = (struct V_13 * ) V_2 -> V_15 ;
struct V_16 * V_17 = F_6 ( V_14 ) ;
if ( V_7 == V_21 ) {
F_12 ( V_2 , L_2 ) ;
return 0 ;
}
V_8 = V_7 ;
V_9 = * V_8 ;
if ( ! V_17 -> V_19 [ V_9 ] )
return V_20 ;
for ( V_10 = 0 ; V_10 < F_2 ( V_17 -> V_19 [ V_9 ] -> V_5 -> V_6 ) ; V_10 ++ )
V_11 += V_17 -> V_19 [ V_9 ] -> V_5 -> V_6 [ V_10 ] . V_11 ;
if ( ! V_11 )
return V_20 ;
F_7 ( V_2 , L_3 , V_9 , V_11 ) ;
return 0 ;
}
static void * F_13 ( struct V_1 * V_2 , T_1 * V_3 )
{
struct V_22 * V_23 ;
T_1 V_24 = * V_3 ;
F_14 () ;
V_23 = F_15 ( V_2 -> V_15 ) ;
if ( ! V_23 )
return NULL ;
while ( V_24 -- ) {
if ( F_16 ( V_23 ) ) {
F_17 ( V_23 ) ;
return NULL ;
}
}
return V_23 ;
}
static void * F_18 ( struct V_1 * V_2 , void * V_25 ,
T_1 * V_3 )
{
struct V_22 * V_23 = V_25 ;
( * V_3 ) ++ ;
if ( F_16 ( V_23 ) ) {
F_17 ( V_23 ) ;
return NULL ;
}
return V_23 ;
}
static void F_19 ( struct V_1 * V_2 , void * V_25 )
{
F_20 () ;
}
static int F_21 ( struct V_1 * V_2 , void * V_25 )
{
struct V_22 * V_23 = V_25 ;
if ( ! V_23 )
return 0 ;
F_22 ( V_2 , V_23 ) ;
return 0 ;
}
void F_23 ( struct V_13 * V_14 )
{
char V_26 [ 10 ] ;
snprintf ( V_26 , sizeof( V_26 ) , L_4 , F_6 ( V_14 ) -> V_27 ) ;
V_14 -> V_28 = F_24 ( V_26 , V_29 ) ;
if ( ! V_14 -> V_28 ) {
F_25 ( L_5 , V_26 ) ;
return;
}
F_26 ( V_30 ) ;
F_26 ( V_31 ) ;
F_26 ( V_32 ) ;
}
void F_27 ( struct V_13 * V_14 )
{
if ( ! V_29 )
goto V_33;
F_28 ( V_14 -> V_28 ) ;
V_33:
V_14 -> V_28 = NULL ;
}
void F_29 ( void )
{
V_29 = F_24 ( V_34 , NULL ) ;
if ( ! V_29 )
F_25 ( L_6 ) ;
}
void F_30 ( void )
{
F_28 ( V_29 ) ;
V_29 = NULL ;
}
