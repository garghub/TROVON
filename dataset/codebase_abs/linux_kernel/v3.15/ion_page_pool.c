static void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = F_2 ( V_2 -> V_4 , V_2 -> V_5 ) ;
if ( ! V_3 )
return NULL ;
F_3 ( NULL , V_3 , V_6 << V_2 -> V_5 ,
V_7 ) ;
return V_3 ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_3 * V_3 )
{
F_5 ( V_3 , V_2 -> V_5 ) ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_8 * V_9 ;
V_9 = F_7 ( sizeof( struct V_8 ) , V_10 ) ;
if ( ! V_9 )
return - V_11 ;
F_8 ( & V_2 -> V_12 ) ;
V_9 -> V_3 = V_3 ;
if ( F_9 ( V_3 ) ) {
F_10 ( & V_9 -> V_13 , & V_2 -> V_14 ) ;
V_2 -> V_15 ++ ;
} else {
F_10 ( & V_9 -> V_13 , & V_2 -> V_16 ) ;
V_2 -> V_17 ++ ;
}
F_11 ( & V_2 -> V_12 ) ;
return 0 ;
}
static struct V_3 * F_12 ( struct V_1 * V_2 , bool V_18 )
{
struct V_8 * V_9 ;
struct V_3 * V_3 ;
if ( V_18 ) {
F_13 ( ! V_2 -> V_15 ) ;
V_9 = F_14 ( & V_2 -> V_14 ,
struct V_8 , V_13 ) ;
V_2 -> V_15 -- ;
} else {
F_13 ( ! V_2 -> V_17 ) ;
V_9 = F_14 ( & V_2 -> V_16 ,
struct V_8 , V_13 ) ;
V_2 -> V_17 -- ;
}
F_15 ( & V_9 -> V_13 ) ;
V_3 = V_9 -> V_3 ;
F_16 ( V_9 ) ;
return V_3 ;
}
void * F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = NULL ;
F_13 ( ! V_2 ) ;
F_8 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_15 )
V_3 = F_12 ( V_2 , true ) ;
else if ( V_2 -> V_17 )
V_3 = F_12 ( V_2 , false ) ;
F_11 ( & V_2 -> V_12 ) ;
if ( ! V_3 )
V_3 = F_1 ( V_2 ) ;
return V_3 ;
}
void F_18 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
int V_19 ;
V_19 = F_6 ( V_2 , V_3 ) ;
if ( V_19 )
F_4 ( V_2 , V_3 ) ;
}
static int F_19 ( struct V_1 * V_2 , bool V_18 )
{
int V_20 = 0 ;
V_20 += V_18 ? ( V_2 -> V_15 + V_2 -> V_17 ) *
( 1 << V_2 -> V_5 ) :
V_2 -> V_17 * ( 1 << V_2 -> V_5 ) ;
return V_20 ;
}
int F_20 ( struct V_1 * V_2 , T_1 V_4 ,
int V_21 )
{
int V_22 ;
bool V_18 ;
V_18 = ! ! ( V_4 & V_23 ) ;
if ( V_21 == 0 )
return F_19 ( V_2 , V_18 ) ;
for ( V_22 = 0 ; V_22 < V_21 ; V_22 ++ ) {
struct V_3 * V_3 ;
F_8 ( & V_2 -> V_12 ) ;
if ( V_2 -> V_17 ) {
V_3 = F_12 ( V_2 , false ) ;
} else if ( V_18 && V_2 -> V_15 ) {
V_3 = F_12 ( V_2 , true ) ;
} else {
F_11 ( & V_2 -> V_12 ) ;
break;
}
F_11 ( & V_2 -> V_12 ) ;
F_4 ( V_2 , V_3 ) ;
}
return V_22 ;
}
struct V_1 * F_21 ( T_1 V_4 , unsigned int V_5 )
{
struct V_1 * V_2 = F_7 ( sizeof( struct V_1 ) ,
V_10 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_15 = 0 ;
V_2 -> V_17 = 0 ;
F_22 ( & V_2 -> V_16 ) ;
F_22 ( & V_2 -> V_14 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_5 = V_5 ;
F_23 ( & V_2 -> V_12 ) ;
F_24 ( & V_2 -> V_13 , V_5 ) ;
return V_2 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_16 ( V_2 ) ;
}
static int T_2 F_26 ( void )
{
return 0 ;
}
static void T_3 F_27 ( void )
{
}
