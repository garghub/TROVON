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
if ( V_21 == 0 ) {
V_21 = 1 ;
} else if ( V_21 & ( V_21 - 1 ) ) {
return NULL ;
}
if ( V_7 == 0 ) {
return NULL ;
} else if ( V_7 < 4 ) {
V_7 = 4 ;
}
if ( ( V_7 % V_21 ) != 0 )
V_7 = F_9 ( V_7 , V_21 ) ;
V_20 = F_10 ( T_2 , V_7 , V_13 ) ;
if ( ! V_22 ) {
V_22 = V_20 ;
} else if ( ( V_22 < V_7 ) || ( V_22 & ( V_22 - 1 ) ) ) {
return NULL ;
}
V_23 = F_11 ( sizeof( * V_23 ) , V_24 , F_12 ( V_2 ) ) ;
if ( ! V_23 )
return V_23 ;
F_13 ( V_23 -> V_19 , V_19 , sizeof( V_23 -> V_19 ) ) ;
V_23 -> V_2 = V_2 ;
F_14 ( & V_23 -> V_25 ) ;
F_15 ( & V_23 -> V_17 ) ;
V_23 -> V_7 = V_7 ;
V_23 -> V_22 = V_22 ;
V_23 -> V_20 = V_20 ;
F_16 ( & V_23 -> V_26 ) ;
if ( V_2 ) {
int V_27 ;
F_3 ( & V_14 ) ;
if ( F_17 ( & V_2 -> V_28 ) )
V_27 = F_18 ( V_2 , & V_29 ) ;
else
V_27 = 0 ;
if ( ! V_27 )
F_19 ( & V_23 -> V_30 , & V_2 -> V_28 ) ;
else {
F_20 ( V_23 ) ;
V_23 = NULL ;
}
F_7 ( & V_14 ) ;
} else
F_14 ( & V_23 -> V_30 ) ;
return V_23 ;
}
static void F_21 ( struct V_11 * V_12 , struct V_9 * V_10 )
{
unsigned int V_31 = 0 ;
unsigned int V_32 = V_12 -> V_22 ;
do {
unsigned int V_8 = V_31 + V_12 -> V_7 ;
if ( F_22 ( ( V_8 + V_12 -> V_7 ) >= V_32 ) ) {
V_8 = V_32 ;
V_32 += V_12 -> V_22 ;
}
* ( int * ) ( V_10 -> V_33 + V_31 ) = V_8 ;
V_31 = V_8 ;
} while ( V_31 < V_12 -> V_20 );
}
static struct V_9 * F_23 ( struct V_11 * V_12 , T_3 V_34 )
{
struct V_9 * V_10 ;
V_10 = F_24 ( sizeof( * V_10 ) , V_34 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_33 = F_25 ( V_12 -> V_2 , V_12 -> V_20 ,
& V_10 -> V_35 , V_34 ) ;
if ( V_10 -> V_33 ) {
#ifdef F_26
memset ( V_10 -> V_33 , V_36 , V_12 -> V_20 ) ;
#endif
F_21 ( V_12 , V_10 ) ;
F_19 ( & V_10 -> V_25 , & V_12 -> V_25 ) ;
V_10 -> V_18 = 0 ;
V_10 -> V_31 = 0 ;
} else {
F_20 ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
static inline int F_27 ( struct V_9 * V_10 )
{
return V_10 -> V_18 != 0 ;
}
static void F_28 ( struct V_11 * V_12 , struct V_9 * V_10 )
{
T_4 V_35 = V_10 -> V_35 ;
#ifdef F_26
memset ( V_10 -> V_33 , V_36 , V_12 -> V_20 ) ;
#endif
F_29 ( V_12 -> V_2 , V_12 -> V_20 , V_10 -> V_33 , V_35 ) ;
F_30 ( & V_10 -> V_25 ) ;
F_20 ( V_10 ) ;
}
void F_31 ( struct V_11 * V_12 )
{
F_3 ( & V_14 ) ;
F_30 ( & V_12 -> V_30 ) ;
if ( V_12 -> V_2 && F_17 ( & V_12 -> V_2 -> V_28 ) )
F_32 ( V_12 -> V_2 , & V_29 ) ;
F_7 ( & V_14 ) ;
while ( ! F_17 ( & V_12 -> V_25 ) ) {
struct V_9 * V_10 ;
V_10 = F_33 ( V_12 -> V_25 . V_8 ,
struct V_9 , V_25 ) ;
if ( F_27 ( V_10 ) ) {
if ( V_12 -> V_2 )
F_34 ( V_12 -> V_2 ,
L_3 ,
V_12 -> V_19 , V_10 -> V_33 ) ;
else
F_35 ( V_37
L_3 ,
V_12 -> V_19 , V_10 -> V_33 ) ;
F_30 ( & V_10 -> V_25 ) ;
F_20 ( V_10 ) ;
} else
F_28 ( V_12 , V_10 ) ;
}
F_20 ( V_12 ) ;
}
void * F_36 ( struct V_11 * V_12 , T_3 V_34 ,
T_4 * V_38 )
{
unsigned long V_39 ;
struct V_9 * V_10 ;
T_2 V_31 ;
void * V_23 ;
F_37 ( V_34 & V_40 ) ;
F_38 ( & V_12 -> V_17 , V_39 ) ;
V_41:
F_4 (page, &pool->page_list, page_list) {
if ( V_10 -> V_31 < V_12 -> V_20 )
goto V_42;
}
V_10 = F_23 ( V_12 , V_43 ) ;
if ( ! V_10 ) {
if ( V_34 & V_40 ) {
F_39 ( V_44 , V_45 ) ;
F_40 ( V_46 ) ;
F_41 ( & V_12 -> V_26 , & V_44 ) ;
F_42 ( & V_12 -> V_17 , V_39 ) ;
F_43 ( V_47 ) ;
F_38 ( & V_12 -> V_17 , V_39 ) ;
F_44 ( & V_12 -> V_26 , & V_44 ) ;
goto V_41;
}
V_23 = NULL ;
goto V_48;
}
V_42:
V_10 -> V_18 ++ ;
V_31 = V_10 -> V_31 ;
V_10 -> V_31 = * ( int * ) ( V_10 -> V_33 + V_31 ) ;
V_23 = V_31 + V_10 -> V_33 ;
* V_38 = V_31 + V_10 -> V_35 ;
#ifdef F_26
memset ( V_23 , V_49 , V_12 -> V_7 ) ;
#endif
V_48:
F_42 ( & V_12 -> V_17 , V_39 ) ;
return V_23 ;
}
static struct V_9 * F_45 ( struct V_11 * V_12 , T_4 V_35 )
{
struct V_9 * V_10 ;
F_4 (page, &pool->page_list, page_list) {
if ( V_35 < V_10 -> V_35 )
continue;
if ( V_35 < ( V_10 -> V_35 + V_12 -> V_20 ) )
return V_10 ;
}
return NULL ;
}
void F_46 ( struct V_11 * V_12 , void * V_33 , T_4 V_35 )
{
struct V_9 * V_10 ;
unsigned long V_39 ;
unsigned int V_31 ;
F_38 ( & V_12 -> V_17 , V_39 ) ;
V_10 = F_45 ( V_12 , V_35 ) ;
if ( ! V_10 ) {
F_42 ( & V_12 -> V_17 , V_39 ) ;
if ( V_12 -> V_2 )
F_34 ( V_12 -> V_2 ,
L_4 ,
V_12 -> V_19 , V_33 , ( unsigned long ) V_35 ) ;
else
F_35 ( V_37 L_4 ,
V_12 -> V_19 , V_33 , ( unsigned long ) V_35 ) ;
return;
}
V_31 = V_33 - V_10 -> V_33 ;
#ifdef F_26
if ( ( V_35 - V_10 -> V_35 ) != V_31 ) {
F_42 ( & V_12 -> V_17 , V_39 ) ;
if ( V_12 -> V_2 )
F_34 ( V_12 -> V_2 ,
L_5 ,
V_12 -> V_19 , V_33 , ( unsigned long long ) V_35 ) ;
else
F_35 ( V_37
L_5 ,
V_12 -> V_19 , V_33 , ( unsigned long long ) V_35 ) ;
return;
}
{
unsigned int V_50 = V_10 -> V_31 ;
while ( V_50 < V_12 -> V_20 ) {
if ( V_50 != V_31 ) {
V_50 = * ( int * ) ( V_10 -> V_33 + V_50 ) ;
continue;
}
F_42 ( & V_12 -> V_17 , V_39 ) ;
if ( V_12 -> V_2 )
F_34 ( V_12 -> V_2 , L_6
L_7 , V_12 -> V_19 ,
( unsigned long long ) V_35 ) ;
else
F_35 ( V_37 L_6
L_7 , V_12 -> V_19 ,
( unsigned long long ) V_35 ) ;
return;
}
}
memset ( V_33 , V_36 , V_12 -> V_7 ) ;
#endif
V_10 -> V_18 -- ;
* ( int * ) V_33 = V_10 -> V_31 ;
V_10 -> V_31 = V_31 ;
if ( F_47 ( & V_12 -> V_26 ) )
F_48 ( & V_12 -> V_26 ) ;
F_42 ( & V_12 -> V_17 , V_39 ) ;
}
static void F_49 ( struct V_1 * V_2 , void * V_51 )
{
struct V_11 * V_12 = * (struct V_11 * * ) V_51 ;
F_31 ( V_12 ) ;
}
static int F_50 ( struct V_1 * V_2 , void * V_51 , void * V_52 )
{
return * (struct V_11 * * ) V_51 == V_52 ;
}
struct V_11 * F_51 ( const char * V_19 , struct V_1 * V_2 ,
T_2 V_7 , T_2 V_21 , T_2 V_20 )
{
struct V_11 * * V_53 , * V_12 ;
V_53 = F_52 ( F_49 , sizeof( * V_53 ) , V_24 ) ;
if ( ! V_53 )
return NULL ;
V_12 = * V_53 = F_8 ( V_19 , V_2 , V_7 , V_21 , V_20 ) ;
if ( V_12 )
F_53 ( V_2 , V_53 ) ;
else
F_54 ( V_53 ) ;
return V_12 ;
}
void F_55 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_31 ( V_12 ) ;
F_56 ( F_57 ( V_2 , F_49 , F_50 , V_12 ) ) ;
}
