static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
unsigned V_6 ;
unsigned V_7 ;
char * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_8 = V_5 ;
V_7 = V_13 ;
V_6 = F_2 ( V_8 , V_7 , L_1 ) ;
V_7 -= V_6 ;
V_8 += V_6 ;
F_3 ( & V_14 ) ;
F_4 (pool, &dev->dma_pools, pools) {
unsigned V_15 = 0 ;
unsigned V_16 = 0 ;
F_5 ( & V_12 -> V_17 ) ;
F_4 (page, &pool->page_list, page_list) {
V_15 ++ ;
V_16 += V_10 -> V_18 ;
}
F_6 ( & V_12 -> V_17 ) ;
V_6 = F_2 ( V_8 , V_7 , L_2 ,
V_12 -> V_19 , V_16 ,
V_15 * ( V_12 -> V_20 / V_12 -> V_7 ) ,
V_12 -> V_7 , V_15 ) ;
V_7 -= V_6 ;
V_8 += V_6 ;
}
F_7 ( & V_14 ) ;
return V_13 - V_7 ;
}
struct V_11 * F_8 ( const char * V_19 , struct V_1 * V_2 ,
T_2 V_7 , T_2 V_21 , T_2 V_22 )
{
struct V_11 * V_23 ;
T_2 V_20 ;
bool V_24 = false ;
if ( V_21 == 0 )
V_21 = 1 ;
else if ( V_21 & ( V_21 - 1 ) )
return NULL ;
if ( V_7 == 0 )
return NULL ;
else if ( V_7 < 4 )
V_7 = 4 ;
if ( ( V_7 % V_21 ) != 0 )
V_7 = F_9 ( V_7 , V_21 ) ;
V_20 = F_10 ( T_2 , V_7 , V_13 ) ;
if ( ! V_22 )
V_22 = V_20 ;
else if ( ( V_22 < V_7 ) || ( V_22 & ( V_22 - 1 ) ) )
return NULL ;
V_23 = F_11 ( sizeof( * V_23 ) , V_25 , F_12 ( V_2 ) ) ;
if ( ! V_23 )
return V_23 ;
F_13 ( V_23 -> V_19 , V_19 , sizeof( V_23 -> V_19 ) ) ;
V_23 -> V_2 = V_2 ;
F_14 ( & V_23 -> V_26 ) ;
F_15 ( & V_23 -> V_17 ) ;
V_23 -> V_7 = V_7 ;
V_23 -> V_22 = V_22 ;
V_23 -> V_20 = V_20 ;
F_14 ( & V_23 -> V_27 ) ;
F_3 ( & V_28 ) ;
F_3 ( & V_14 ) ;
if ( F_16 ( & V_2 -> V_29 ) )
V_24 = true ;
F_17 ( & V_23 -> V_27 , & V_2 -> V_29 ) ;
F_7 ( & V_14 ) ;
if ( V_24 ) {
int V_30 ;
V_30 = F_18 ( V_2 , & V_31 ) ;
if ( V_30 ) {
F_3 ( & V_14 ) ;
F_19 ( & V_23 -> V_27 ) ;
F_7 ( & V_14 ) ;
F_7 ( & V_28 ) ;
F_20 ( V_23 ) ;
return NULL ;
}
}
F_7 ( & V_28 ) ;
return V_23 ;
}
static void F_21 ( struct V_11 * V_12 , struct V_9 * V_10 )
{
unsigned int V_32 = 0 ;
unsigned int V_33 = V_12 -> V_22 ;
do {
unsigned int V_8 = V_32 + V_12 -> V_7 ;
if ( F_22 ( ( V_8 + V_12 -> V_7 ) >= V_33 ) ) {
V_8 = V_33 ;
V_33 += V_12 -> V_22 ;
}
* ( int * ) ( V_10 -> V_34 + V_32 ) = V_8 ;
V_32 = V_8 ;
} while ( V_32 < V_12 -> V_20 );
}
static struct V_9 * F_23 ( struct V_11 * V_12 , T_3 V_35 )
{
struct V_9 * V_10 ;
V_10 = F_24 ( sizeof( * V_10 ) , V_35 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_34 = F_25 ( V_12 -> V_2 , V_12 -> V_20 ,
& V_10 -> V_36 , V_35 ) ;
if ( V_10 -> V_34 ) {
#ifdef F_26
memset ( V_10 -> V_34 , V_37 , V_12 -> V_20 ) ;
#endif
F_21 ( V_12 , V_10 ) ;
V_10 -> V_18 = 0 ;
V_10 -> V_32 = 0 ;
} else {
F_20 ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
static inline bool F_27 ( struct V_9 * V_10 )
{
return V_10 -> V_18 != 0 ;
}
static void F_28 ( struct V_11 * V_12 , struct V_9 * V_10 )
{
T_4 V_36 = V_10 -> V_36 ;
#ifdef F_26
memset ( V_10 -> V_34 , V_37 , V_12 -> V_20 ) ;
#endif
F_29 ( V_12 -> V_2 , V_12 -> V_20 , V_10 -> V_34 , V_36 ) ;
F_19 ( & V_10 -> V_26 ) ;
F_20 ( V_10 ) ;
}
void F_30 ( struct V_11 * V_12 )
{
bool V_24 = false ;
if ( F_22 ( ! V_12 ) )
return;
F_3 ( & V_28 ) ;
F_3 ( & V_14 ) ;
F_19 ( & V_12 -> V_27 ) ;
if ( V_12 -> V_2 && F_16 ( & V_12 -> V_2 -> V_29 ) )
V_24 = true ;
F_7 ( & V_14 ) ;
if ( V_24 )
F_31 ( V_12 -> V_2 , & V_31 ) ;
F_7 ( & V_28 ) ;
while ( ! F_16 ( & V_12 -> V_26 ) ) {
struct V_9 * V_10 ;
V_10 = F_32 ( V_12 -> V_26 . V_8 ,
struct V_9 , V_26 ) ;
if ( F_27 ( V_10 ) ) {
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_3 ,
V_12 -> V_19 , V_10 -> V_34 ) ;
else
F_34 ( V_38
L_3 ,
V_12 -> V_19 , V_10 -> V_34 ) ;
F_19 ( & V_10 -> V_26 ) ;
F_20 ( V_10 ) ;
} else
F_28 ( V_12 , V_10 ) ;
}
F_20 ( V_12 ) ;
}
void * F_35 ( struct V_11 * V_12 , T_3 V_35 ,
T_4 * V_39 )
{
unsigned long V_40 ;
struct V_9 * V_10 ;
T_2 V_32 ;
void * V_23 ;
F_36 ( V_35 & V_41 ) ;
F_37 ( & V_12 -> V_17 , V_40 ) ;
F_4 (page, &pool->page_list, page_list) {
if ( V_10 -> V_32 < V_12 -> V_20 )
goto V_42;
}
F_38 ( & V_12 -> V_17 , V_40 ) ;
V_10 = F_23 ( V_12 , V_35 & ( ~ V_43 ) ) ;
if ( ! V_10 )
return NULL ;
F_37 ( & V_12 -> V_17 , V_40 ) ;
F_17 ( & V_10 -> V_26 , & V_12 -> V_26 ) ;
V_42:
V_10 -> V_18 ++ ;
V_32 = V_10 -> V_32 ;
V_10 -> V_32 = * ( int * ) ( V_10 -> V_34 + V_32 ) ;
V_23 = V_32 + V_10 -> V_34 ;
* V_39 = V_32 + V_10 -> V_36 ;
#ifdef F_26
{
int V_44 ;
T_5 * V_45 = V_23 ;
for ( V_44 = sizeof( V_10 -> V_32 ) ; V_44 < V_12 -> V_7 ; V_44 ++ ) {
if ( V_45 [ V_44 ] == V_37 )
continue;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_4 ,
V_12 -> V_19 , V_23 ) ;
else
F_39 ( L_4 ,
V_12 -> V_19 , V_23 ) ;
F_40 ( V_38 , L_5 , V_46 , 16 , 1 ,
V_45 , V_12 -> V_7 , 1 ) ;
break;
}
}
if ( ! ( V_35 & V_43 ) )
memset ( V_23 , V_47 , V_12 -> V_7 ) ;
#endif
F_38 ( & V_12 -> V_17 , V_40 ) ;
if ( V_35 & V_43 )
memset ( V_23 , 0 , V_12 -> V_7 ) ;
return V_23 ;
}
static struct V_9 * F_41 ( struct V_11 * V_12 , T_4 V_36 )
{
struct V_9 * V_10 ;
F_4 (page, &pool->page_list, page_list) {
if ( V_36 < V_10 -> V_36 )
continue;
if ( ( V_36 - V_10 -> V_36 ) < V_12 -> V_20 )
return V_10 ;
}
return NULL ;
}
void F_42 ( struct V_11 * V_12 , void * V_34 , T_4 V_36 )
{
struct V_9 * V_10 ;
unsigned long V_40 ;
unsigned int V_32 ;
F_37 ( & V_12 -> V_17 , V_40 ) ;
V_10 = F_41 ( V_12 , V_36 ) ;
if ( ! V_10 ) {
F_38 ( & V_12 -> V_17 , V_40 ) ;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_6 ,
V_12 -> V_19 , V_34 , ( unsigned long ) V_36 ) ;
else
F_34 ( V_38 L_6 ,
V_12 -> V_19 , V_34 , ( unsigned long ) V_36 ) ;
return;
}
V_32 = V_34 - V_10 -> V_34 ;
#ifdef F_26
if ( ( V_36 - V_10 -> V_36 ) != V_32 ) {
F_38 ( & V_12 -> V_17 , V_40 ) ;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_7 ,
V_12 -> V_19 , V_34 , ( unsigned long long ) V_36 ) ;
else
F_34 ( V_38
L_7 ,
V_12 -> V_19 , V_34 , ( unsigned long long ) V_36 ) ;
return;
}
{
unsigned int V_48 = V_10 -> V_32 ;
while ( V_48 < V_12 -> V_20 ) {
if ( V_48 != V_32 ) {
V_48 = * ( int * ) ( V_10 -> V_34 + V_48 ) ;
continue;
}
F_38 ( & V_12 -> V_17 , V_40 ) ;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 , L_8
L_9 , V_12 -> V_19 ,
( unsigned long long ) V_36 ) ;
else
F_34 ( V_38 L_8
L_9 , V_12 -> V_19 ,
( unsigned long long ) V_36 ) ;
return;
}
}
memset ( V_34 , V_37 , V_12 -> V_7 ) ;
#endif
V_10 -> V_18 -- ;
* ( int * ) V_34 = V_10 -> V_32 ;
V_10 -> V_32 = V_32 ;
F_38 ( & V_12 -> V_17 , V_40 ) ;
}
static void F_43 ( struct V_1 * V_2 , void * V_49 )
{
struct V_11 * V_12 = * (struct V_11 * * ) V_49 ;
F_30 ( V_12 ) ;
}
static int F_44 ( struct V_1 * V_2 , void * V_49 , void * V_50 )
{
return * (struct V_11 * * ) V_49 == V_50 ;
}
struct V_11 * F_45 ( const char * V_19 , struct V_1 * V_2 ,
T_2 V_7 , T_2 V_21 , T_2 V_20 )
{
struct V_11 * * V_51 , * V_12 ;
V_51 = F_46 ( F_43 , sizeof( * V_51 ) , V_25 ) ;
if ( ! V_51 )
return NULL ;
V_12 = * V_51 = F_8 ( V_19 , V_2 , V_7 , V_21 , V_20 ) ;
if ( V_12 )
F_47 ( V_2 , V_51 ) ;
else
F_48 ( V_51 ) ;
return V_12 ;
}
void F_49 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_50 ( F_51 ( V_2 , F_43 , F_44 , V_12 ) ) ;
}
