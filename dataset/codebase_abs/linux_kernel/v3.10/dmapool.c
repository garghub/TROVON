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
if ( V_2 ) {
int V_26 ;
F_3 ( & V_14 ) ;
if ( F_16 ( & V_2 -> V_27 ) )
V_26 = F_17 ( V_2 , & V_28 ) ;
else
V_26 = 0 ;
if ( ! V_26 )
F_18 ( & V_23 -> V_29 , & V_2 -> V_27 ) ;
else {
F_19 ( V_23 ) ;
V_23 = NULL ;
}
F_7 ( & V_14 ) ;
} else
F_14 ( & V_23 -> V_29 ) ;
return V_23 ;
}
static void F_20 ( struct V_11 * V_12 , struct V_9 * V_10 )
{
unsigned int V_30 = 0 ;
unsigned int V_31 = V_12 -> V_22 ;
do {
unsigned int V_8 = V_30 + V_12 -> V_7 ;
if ( F_21 ( ( V_8 + V_12 -> V_7 ) >= V_31 ) ) {
V_8 = V_31 ;
V_31 += V_12 -> V_22 ;
}
* ( int * ) ( V_10 -> V_32 + V_30 ) = V_8 ;
V_30 = V_8 ;
} while ( V_30 < V_12 -> V_20 );
}
static struct V_9 * F_22 ( struct V_11 * V_12 , T_3 V_33 )
{
struct V_9 * V_10 ;
V_10 = F_23 ( sizeof( * V_10 ) , V_33 ) ;
if ( ! V_10 )
return NULL ;
V_10 -> V_32 = F_24 ( V_12 -> V_2 , V_12 -> V_20 ,
& V_10 -> V_34 , V_33 ) ;
if ( V_10 -> V_32 ) {
#ifdef F_25
memset ( V_10 -> V_32 , V_35 , V_12 -> V_20 ) ;
#endif
F_20 ( V_12 , V_10 ) ;
V_10 -> V_18 = 0 ;
V_10 -> V_30 = 0 ;
} else {
F_19 ( V_10 ) ;
V_10 = NULL ;
}
return V_10 ;
}
static inline int F_26 ( struct V_9 * V_10 )
{
return V_10 -> V_18 != 0 ;
}
static void F_27 ( struct V_11 * V_12 , struct V_9 * V_10 )
{
T_4 V_34 = V_10 -> V_34 ;
#ifdef F_25
memset ( V_10 -> V_32 , V_35 , V_12 -> V_20 ) ;
#endif
F_28 ( V_12 -> V_2 , V_12 -> V_20 , V_10 -> V_32 , V_34 ) ;
F_29 ( & V_10 -> V_25 ) ;
F_19 ( V_10 ) ;
}
void F_30 ( struct V_11 * V_12 )
{
F_3 ( & V_14 ) ;
F_29 ( & V_12 -> V_29 ) ;
if ( V_12 -> V_2 && F_16 ( & V_12 -> V_2 -> V_27 ) )
F_31 ( V_12 -> V_2 , & V_28 ) ;
F_7 ( & V_14 ) ;
while ( ! F_16 ( & V_12 -> V_25 ) ) {
struct V_9 * V_10 ;
V_10 = F_32 ( V_12 -> V_25 . V_8 ,
struct V_9 , V_25 ) ;
if ( F_26 ( V_10 ) ) {
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_3 ,
V_12 -> V_19 , V_10 -> V_32 ) ;
else
F_34 ( V_36
L_3 ,
V_12 -> V_19 , V_10 -> V_32 ) ;
F_29 ( & V_10 -> V_25 ) ;
F_19 ( V_10 ) ;
} else
F_27 ( V_12 , V_10 ) ;
}
F_19 ( V_12 ) ;
}
void * F_35 ( struct V_11 * V_12 , T_3 V_33 ,
T_4 * V_37 )
{
unsigned long V_38 ;
struct V_9 * V_10 ;
T_2 V_30 ;
void * V_23 ;
F_36 ( V_33 & V_39 ) ;
F_37 ( & V_12 -> V_17 , V_38 ) ;
F_4 (page, &pool->page_list, page_list) {
if ( V_10 -> V_30 < V_12 -> V_20 )
goto V_40;
}
F_38 ( & V_12 -> V_17 , V_38 ) ;
V_10 = F_22 ( V_12 , V_33 ) ;
if ( ! V_10 )
return NULL ;
F_37 ( & V_12 -> V_17 , V_38 ) ;
F_18 ( & V_10 -> V_25 , & V_12 -> V_25 ) ;
V_40:
V_10 -> V_18 ++ ;
V_30 = V_10 -> V_30 ;
V_10 -> V_30 = * ( int * ) ( V_10 -> V_32 + V_30 ) ;
V_23 = V_30 + V_10 -> V_32 ;
* V_37 = V_30 + V_10 -> V_34 ;
#ifdef F_25
{
int V_41 ;
T_5 * V_42 = V_23 ;
for ( V_41 = sizeof( V_10 -> V_30 ) ; V_41 < V_12 -> V_7 ; V_41 ++ ) {
if ( V_42 [ V_41 ] == V_35 )
continue;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_4 ,
V_12 -> V_19 , V_23 ) ;
else
F_39 ( L_4 ,
V_12 -> V_19 , V_23 ) ;
F_40 ( V_36 , L_5 , V_43 , 16 , 1 ,
V_42 , V_12 -> V_7 , 1 ) ;
break;
}
}
memset ( V_23 , V_44 , V_12 -> V_7 ) ;
#endif
F_38 ( & V_12 -> V_17 , V_38 ) ;
return V_23 ;
}
static struct V_9 * F_41 ( struct V_11 * V_12 , T_4 V_34 )
{
struct V_9 * V_10 ;
F_4 (page, &pool->page_list, page_list) {
if ( V_34 < V_10 -> V_34 )
continue;
if ( V_34 < ( V_10 -> V_34 + V_12 -> V_20 ) )
return V_10 ;
}
return NULL ;
}
void F_42 ( struct V_11 * V_12 , void * V_32 , T_4 V_34 )
{
struct V_9 * V_10 ;
unsigned long V_38 ;
unsigned int V_30 ;
F_37 ( & V_12 -> V_17 , V_38 ) ;
V_10 = F_41 ( V_12 , V_34 ) ;
if ( ! V_10 ) {
F_38 ( & V_12 -> V_17 , V_38 ) ;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_6 ,
V_12 -> V_19 , V_32 , ( unsigned long ) V_34 ) ;
else
F_34 ( V_36 L_6 ,
V_12 -> V_19 , V_32 , ( unsigned long ) V_34 ) ;
return;
}
V_30 = V_32 - V_10 -> V_32 ;
#ifdef F_25
if ( ( V_34 - V_10 -> V_34 ) != V_30 ) {
F_38 ( & V_12 -> V_17 , V_38 ) ;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 ,
L_7 ,
V_12 -> V_19 , V_32 , ( unsigned long long ) V_34 ) ;
else
F_34 ( V_36
L_7 ,
V_12 -> V_19 , V_32 , ( unsigned long long ) V_34 ) ;
return;
}
{
unsigned int V_45 = V_10 -> V_30 ;
while ( V_45 < V_12 -> V_20 ) {
if ( V_45 != V_30 ) {
V_45 = * ( int * ) ( V_10 -> V_32 + V_45 ) ;
continue;
}
F_38 ( & V_12 -> V_17 , V_38 ) ;
if ( V_12 -> V_2 )
F_33 ( V_12 -> V_2 , L_8
L_9 , V_12 -> V_19 ,
( unsigned long long ) V_34 ) ;
else
F_34 ( V_36 L_8
L_9 , V_12 -> V_19 ,
( unsigned long long ) V_34 ) ;
return;
}
}
memset ( V_32 , V_35 , V_12 -> V_7 ) ;
#endif
V_10 -> V_18 -- ;
* ( int * ) V_32 = V_10 -> V_30 ;
V_10 -> V_30 = V_30 ;
F_38 ( & V_12 -> V_17 , V_38 ) ;
}
static void F_43 ( struct V_1 * V_2 , void * V_46 )
{
struct V_11 * V_12 = * (struct V_11 * * ) V_46 ;
F_30 ( V_12 ) ;
}
static int F_44 ( struct V_1 * V_2 , void * V_46 , void * V_47 )
{
return * (struct V_11 * * ) V_46 == V_47 ;
}
struct V_11 * F_45 ( const char * V_19 , struct V_1 * V_2 ,
T_2 V_7 , T_2 V_21 , T_2 V_20 )
{
struct V_11 * * V_48 , * V_12 ;
V_48 = F_46 ( F_43 , sizeof( * V_48 ) , V_24 ) ;
if ( ! V_48 )
return NULL ;
V_12 = * V_48 = F_8 ( V_19 , V_2 , V_7 , V_21 , V_20 ) ;
if ( V_12 )
F_47 ( V_2 , V_48 ) ;
else
F_48 ( V_48 ) ;
return V_12 ;
}
void F_49 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_2 ;
F_50 ( F_51 ( V_2 , F_43 , F_44 , V_12 ) ) ;
F_30 ( V_12 ) ;
}
