static inline T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 - V_2 -> V_4 + 1 ;
}
static int F_2 ( unsigned long * V_5 , unsigned long V_6 )
{
unsigned long V_7 , V_8 ;
V_8 = * V_5 ;
do {
V_7 = V_8 ;
if ( V_7 & V_6 )
return - V_9 ;
F_3 () ;
} while ( ( V_8 = F_4 ( V_5 , V_7 , V_7 | V_6 ) ) != V_7 );
return 0 ;
}
static int F_5 ( unsigned long * V_5 , unsigned long V_10 )
{
unsigned long V_7 , V_8 ;
V_8 = * V_5 ;
do {
V_7 = V_8 ;
if ( ( V_7 & V_10 ) != V_10 )
return - V_9 ;
F_3 () ;
} while ( ( V_8 = F_4 ( V_5 , V_7 , V_7 & ~ V_10 ) ) != V_7 );
return 0 ;
}
static int F_6 ( unsigned long * V_11 , int V_12 , int V_13 )
{
unsigned long * V_14 = V_11 + F_7 ( V_12 ) ;
const int V_15 = V_12 + V_13 ;
int V_16 = V_17 - ( V_12 % V_17 ) ;
unsigned long V_6 = F_8 ( V_12 ) ;
while ( V_13 - V_16 >= 0 ) {
if ( F_2 ( V_14 , V_6 ) )
return V_13 ;
V_13 -= V_16 ;
V_16 = V_17 ;
V_6 = ~ 0UL ;
V_14 ++ ;
}
if ( V_13 ) {
V_6 &= F_9 ( V_15 ) ;
if ( F_2 ( V_14 , V_6 ) )
return V_13 ;
}
return 0 ;
}
static int F_10 ( unsigned long * V_11 , int V_12 , int V_13 )
{
unsigned long * V_14 = V_11 + F_7 ( V_12 ) ;
const int V_15 = V_12 + V_13 ;
int V_18 = V_17 - ( V_12 % V_17 ) ;
unsigned long V_10 = F_8 ( V_12 ) ;
while ( V_13 - V_18 >= 0 ) {
if ( F_5 ( V_14 , V_10 ) )
return V_13 ;
V_13 -= V_18 ;
V_18 = V_17 ;
V_10 = ~ 0UL ;
V_14 ++ ;
}
if ( V_13 ) {
V_10 &= F_9 ( V_15 ) ;
if ( F_5 ( V_14 , V_10 ) )
return V_13 ;
}
return 0 ;
}
struct V_19 * F_11 ( int V_20 , int V_21 )
{
struct V_19 * V_22 ;
V_22 = F_12 ( sizeof( struct V_19 ) , V_23 , V_21 ) ;
if ( V_22 != NULL ) {
F_13 ( & V_22 -> V_24 ) ;
F_14 ( & V_22 -> V_25 ) ;
V_22 -> V_20 = V_20 ;
V_22 -> V_26 = V_27 ;
V_22 -> V_28 = NULL ;
}
return V_22 ;
}
int F_15 ( struct V_19 * V_22 , unsigned long V_29 , T_2 V_30 ,
T_1 V_15 , int V_21 )
{
struct V_1 * V_2 ;
int V_31 = V_15 >> V_22 -> V_20 ;
int V_32 = sizeof( struct V_1 ) +
F_16 ( V_31 ) * sizeof( long ) ;
V_2 = F_17 ( V_32 , V_23 , V_21 ) ;
if ( F_18 ( V_2 == NULL ) )
return - V_33 ;
V_2 -> V_34 = V_30 ;
V_2 -> V_4 = V_29 ;
V_2 -> V_3 = V_29 + V_15 - 1 ;
F_19 ( & V_2 -> V_35 , V_15 ) ;
F_20 ( & V_22 -> V_24 ) ;
F_21 ( & V_2 -> V_36 , & V_22 -> V_25 ) ;
F_22 ( & V_22 -> V_24 ) ;
return 0 ;
}
T_2 F_23 ( struct V_19 * V_22 , unsigned long V_5 )
{
struct V_1 * V_2 ;
T_2 V_37 = - 1 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk) {
if ( V_5 >= V_2 -> V_4 && V_5 <= V_2 -> V_3 ) {
V_37 = V_2 -> V_34 + ( V_5 - V_2 -> V_4 ) ;
break;
}
}
F_26 () ;
return V_37 ;
}
void F_27 ( struct V_19 * V_22 )
{
struct V_38 * V_39 , * V_40 ;
struct V_1 * V_2 ;
int V_41 = V_22 -> V_20 ;
int V_42 , V_43 ;
F_28 (_chunk, _next_chunk, &pool->chunks) {
V_2 = F_29 ( V_39 , struct V_1 , V_36 ) ;
F_30 ( & V_2 -> V_36 ) ;
V_43 = F_1 ( V_2 ) >> V_41 ;
V_42 = F_31 ( V_2 -> V_44 , V_43 , 0 ) ;
F_32 ( V_42 < V_43 ) ;
F_33 ( V_2 ) ;
}
F_33 ( V_22 ) ;
return;
}
unsigned long F_34 ( struct V_19 * V_22 , T_1 V_15 )
{
struct V_1 * V_2 ;
unsigned long V_5 = 0 ;
int V_41 = V_22 -> V_20 ;
int V_31 , V_45 = 0 , V_43 , V_46 ;
#ifndef F_35
F_32 ( F_36 () ) ;
#endif
if ( V_15 == 0 )
return 0 ;
V_31 = ( V_15 + ( 1UL << V_41 ) - 1 ) >> V_41 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk) {
if ( V_15 > F_37 ( & V_2 -> V_35 ) )
continue;
V_43 = F_1 ( V_2 ) >> V_41 ;
V_47:
V_45 = V_22 -> V_26 ( V_2 -> V_44 , V_43 , V_45 , V_31 ,
V_22 -> V_28 ) ;
if ( V_45 >= V_43 )
continue;
V_46 = F_6 ( V_2 -> V_44 , V_45 , V_31 ) ;
if ( V_46 ) {
V_46 = F_10 ( V_2 -> V_44 , V_45 ,
V_31 - V_46 ) ;
F_32 ( V_46 ) ;
goto V_47;
}
V_5 = V_2 -> V_4 + ( ( unsigned long ) V_45 << V_41 ) ;
V_15 = V_31 << V_41 ;
F_38 ( V_15 , & V_2 -> V_35 ) ;
break;
}
F_26 () ;
return V_5 ;
}
void * F_39 ( struct V_19 * V_22 , T_1 V_15 , T_3 * V_48 )
{
unsigned long V_49 ;
if ( ! V_22 )
return NULL ;
V_49 = F_34 ( V_22 , V_15 ) ;
if ( ! V_49 )
return NULL ;
* V_48 = F_23 ( V_22 , V_49 ) ;
return ( void * ) V_49 ;
}
void F_40 ( struct V_19 * V_22 , unsigned long V_5 , T_1 V_15 )
{
struct V_1 * V_2 ;
int V_41 = V_22 -> V_20 ;
int V_45 , V_31 , V_46 ;
#ifndef F_35
F_32 ( F_36 () ) ;
#endif
V_31 = ( V_15 + ( 1UL << V_41 ) - 1 ) >> V_41 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk) {
if ( V_5 >= V_2 -> V_4 && V_5 <= V_2 -> V_3 ) {
F_32 ( V_5 + V_15 - 1 > V_2 -> V_3 ) ;
V_45 = ( V_5 - V_2 -> V_4 ) >> V_41 ;
V_46 = F_10 ( V_2 -> V_44 , V_45 , V_31 ) ;
F_32 ( V_46 ) ;
V_15 = V_31 << V_41 ;
F_41 ( V_15 , & V_2 -> V_35 ) ;
F_26 () ;
return;
}
}
F_26 () ;
F_42 () ;
}
void F_43 ( struct V_19 * V_22 ,
void (* F_44)( struct V_19 * V_22 , struct V_1 * V_2 , void * V_28 ) ,
void * V_28 )
{
struct V_1 * V_2 ;
F_24 () ;
F_25 (chunk, &(pool)->chunks, next_chunk)
F_44 ( V_22 , V_2 , V_28 ) ;
F_26 () ;
}
T_1 F_45 ( struct V_19 * V_22 )
{
struct V_1 * V_2 ;
T_1 V_35 = 0 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk)
V_35 += F_37 ( & V_2 -> V_35 ) ;
F_26 () ;
return V_35 ;
}
T_1 F_46 ( struct V_19 * V_22 )
{
struct V_1 * V_2 ;
T_1 V_15 = 0 ;
F_24 () ;
F_25 (chunk, &pool->chunks, next_chunk)
V_15 += F_1 ( V_2 ) ;
F_26 () ;
return V_15 ;
}
void F_47 ( struct V_19 * V_22 , T_4 V_26 , void * V_28 )
{
F_24 () ;
V_22 -> V_26 = V_26 ;
if ( ! V_22 -> V_26 )
V_22 -> V_26 = V_27 ;
V_22 -> V_28 = V_28 ;
F_26 () ;
}
unsigned long V_27 ( unsigned long * V_11 , unsigned long V_15 ,
unsigned long V_12 , unsigned int V_13 , void * V_28 )
{
return F_48 ( V_11 , V_15 , V_12 , V_13 , 0 ) ;
}
unsigned long F_49 ( unsigned long * V_11 , unsigned long V_15 ,
unsigned long V_12 , unsigned int V_13 , void * V_28 )
{
unsigned long V_45 = V_15 ;
unsigned long V_50 = V_15 + 1 ;
unsigned long V_51 ;
V_51 = F_48 ( V_11 , V_15 , V_12 , V_13 , 0 ) ;
while ( V_51 < V_15 ) {
int V_52 = F_31 ( V_11 , V_15 , V_51 + V_13 ) ;
if ( ( V_52 - V_51 ) < V_50 ) {
V_50 = V_52 - V_51 ;
V_45 = V_51 ;
if ( V_50 == V_13 )
return V_45 ;
}
V_51 = F_48 ( V_11 , V_15 ,
V_52 + 1 , V_13 , 0 ) ;
}
return V_45 ;
}
static void F_50 ( struct V_53 * V_54 , void * V_55 )
{
F_27 ( * (struct V_19 * * ) V_55 ) ;
}
struct V_19 * F_51 ( struct V_53 * V_54 , int V_20 ,
int V_21 )
{
struct V_19 * * V_56 , * V_22 ;
V_56 = F_52 ( F_50 , sizeof( * V_56 ) , V_23 ) ;
V_22 = F_11 ( V_20 , V_21 ) ;
if ( V_22 ) {
* V_56 = V_22 ;
F_53 ( V_54 , V_56 ) ;
} else {
F_54 ( V_56 ) ;
}
return V_22 ;
}
struct V_19 * F_55 ( struct V_53 * V_54 )
{
struct V_19 * * V_14 = F_56 ( V_54 , F_50 , NULL ,
NULL ) ;
if ( ! V_14 )
return NULL ;
return * V_14 ;
}
struct V_19 * F_57 ( struct V_57 * V_58 ,
const char * V_59 , int V_51 )
{
struct V_60 * V_61 ;
struct V_57 * V_62 ;
V_62 = F_58 ( V_58 , V_59 , V_51 ) ;
if ( ! V_62 )
return NULL ;
V_61 = F_59 ( V_62 ) ;
if ( ! V_61 )
return NULL ;
return F_55 ( & V_61 -> V_54 ) ;
}
