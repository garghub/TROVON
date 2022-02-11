static int F_1 ( unsigned long * V_1 , unsigned long V_2 )
{
unsigned long V_3 , V_4 ;
V_4 = * V_1 ;
do {
V_3 = V_4 ;
if ( V_3 & V_2 )
return - V_5 ;
F_2 () ;
} while ( ( V_4 = F_3 ( V_1 , V_3 , V_3 | V_2 ) ) != V_3 );
return 0 ;
}
static int F_4 ( unsigned long * V_1 , unsigned long V_6 )
{
unsigned long V_3 , V_4 ;
V_4 = * V_1 ;
do {
V_3 = V_4 ;
if ( ( V_3 & V_6 ) != V_6 )
return - V_5 ;
F_2 () ;
} while ( ( V_4 = F_3 ( V_1 , V_3 , V_3 & ~ V_6 ) ) != V_3 );
return 0 ;
}
static int F_5 ( unsigned long * V_7 , int V_8 , int V_9 )
{
unsigned long * V_10 = V_7 + F_6 ( V_8 ) ;
const int V_11 = V_8 + V_9 ;
int V_12 = V_13 - ( V_8 % V_13 ) ;
unsigned long V_2 = F_7 ( V_8 ) ;
while ( V_9 - V_12 >= 0 ) {
if ( F_1 ( V_10 , V_2 ) )
return V_9 ;
V_9 -= V_12 ;
V_12 = V_13 ;
V_2 = ~ 0UL ;
V_10 ++ ;
}
if ( V_9 ) {
V_2 &= F_8 ( V_11 ) ;
if ( F_1 ( V_10 , V_2 ) )
return V_9 ;
}
return 0 ;
}
static int F_9 ( unsigned long * V_7 , int V_8 , int V_9 )
{
unsigned long * V_10 = V_7 + F_6 ( V_8 ) ;
const int V_11 = V_8 + V_9 ;
int V_14 = V_13 - ( V_8 % V_13 ) ;
unsigned long V_6 = F_7 ( V_8 ) ;
while ( V_9 - V_14 >= 0 ) {
if ( F_4 ( V_10 , V_6 ) )
return V_9 ;
V_9 -= V_14 ;
V_14 = V_13 ;
V_6 = ~ 0UL ;
V_10 ++ ;
}
if ( V_9 ) {
V_6 &= F_8 ( V_11 ) ;
if ( F_4 ( V_10 , V_6 ) )
return V_9 ;
}
return 0 ;
}
struct V_15 * F_10 ( int V_16 , int V_17 )
{
struct V_15 * V_18 ;
V_18 = F_11 ( sizeof( struct V_15 ) , V_19 , V_17 ) ;
if ( V_18 != NULL ) {
F_12 ( & V_18 -> V_20 ) ;
F_13 ( & V_18 -> V_21 ) ;
V_18 -> V_16 = V_16 ;
V_18 -> V_22 = V_23 ;
V_18 -> V_24 = NULL ;
}
return V_18 ;
}
int F_14 ( struct V_15 * V_18 , unsigned long V_25 , T_1 V_26 ,
T_2 V_11 , int V_17 )
{
struct V_27 * V_28 ;
int V_29 = V_11 >> V_18 -> V_16 ;
int V_30 = sizeof( struct V_27 ) +
F_15 ( V_29 ) * sizeof( long ) ;
V_28 = F_11 ( V_30 , V_19 | V_31 , V_17 ) ;
if ( F_16 ( V_28 == NULL ) )
return - V_32 ;
V_28 -> V_33 = V_26 ;
V_28 -> V_34 = V_25 ;
V_28 -> V_35 = V_25 + V_11 ;
F_17 ( & V_28 -> V_36 , V_11 ) ;
F_18 ( & V_18 -> V_20 ) ;
F_19 ( & V_28 -> V_37 , & V_18 -> V_21 ) ;
F_20 ( & V_18 -> V_20 ) ;
return 0 ;
}
T_1 F_21 ( struct V_15 * V_18 , unsigned long V_1 )
{
struct V_27 * V_28 ;
T_1 V_38 = - 1 ;
F_22 () ;
F_23 (chunk, &pool->chunks, next_chunk) {
if ( V_1 >= V_28 -> V_34 && V_1 < V_28 -> V_35 ) {
V_38 = V_28 -> V_33 + ( V_1 - V_28 -> V_34 ) ;
break;
}
}
F_24 () ;
return V_38 ;
}
void F_25 ( struct V_15 * V_18 )
{
struct V_39 * V_40 , * V_41 ;
struct V_27 * V_28 ;
int V_42 = V_18 -> V_16 ;
int V_43 , V_44 ;
F_26 (_chunk, _next_chunk, &pool->chunks) {
V_28 = F_27 ( V_40 , struct V_27 , V_37 ) ;
F_28 ( & V_28 -> V_37 ) ;
V_44 = ( V_28 -> V_35 - V_28 -> V_34 ) >> V_42 ;
V_43 = F_29 ( V_28 -> V_45 , V_44 , 0 ) ;
F_30 ( V_43 < V_44 ) ;
F_31 ( V_28 ) ;
}
F_31 ( V_18 ) ;
return;
}
unsigned long F_32 ( struct V_15 * V_18 , T_2 V_11 )
{
struct V_27 * V_28 ;
unsigned long V_1 = 0 ;
int V_42 = V_18 -> V_16 ;
int V_29 , V_46 = 0 , V_44 , V_47 ;
#ifndef F_33
F_30 ( F_34 () ) ;
#endif
if ( V_11 == 0 )
return 0 ;
V_29 = ( V_11 + ( 1UL << V_42 ) - 1 ) >> V_42 ;
F_22 () ;
F_23 (chunk, &pool->chunks, next_chunk) {
if ( V_11 > F_35 ( & V_28 -> V_36 ) )
continue;
V_44 = ( V_28 -> V_35 - V_28 -> V_34 ) >> V_42 ;
V_48:
V_46 = V_18 -> V_22 ( V_28 -> V_45 , V_44 , V_46 , V_29 ,
V_18 -> V_24 ) ;
if ( V_46 >= V_44 )
continue;
V_47 = F_5 ( V_28 -> V_45 , V_46 , V_29 ) ;
if ( V_47 ) {
V_47 = F_9 ( V_28 -> V_45 , V_46 ,
V_29 - V_47 ) ;
F_30 ( V_47 ) ;
goto V_48;
}
V_1 = V_28 -> V_34 + ( ( unsigned long ) V_46 << V_42 ) ;
V_11 = V_29 << V_42 ;
F_36 ( V_11 , & V_28 -> V_36 ) ;
break;
}
F_24 () ;
return V_1 ;
}
void F_37 ( struct V_15 * V_18 , unsigned long V_1 , T_2 V_11 )
{
struct V_27 * V_28 ;
int V_42 = V_18 -> V_16 ;
int V_46 , V_29 , V_47 ;
#ifndef F_33
F_30 ( F_34 () ) ;
#endif
V_29 = ( V_11 + ( 1UL << V_42 ) - 1 ) >> V_42 ;
F_22 () ;
F_23 (chunk, &pool->chunks, next_chunk) {
if ( V_1 >= V_28 -> V_34 && V_1 < V_28 -> V_35 ) {
F_30 ( V_1 + V_11 > V_28 -> V_35 ) ;
V_46 = ( V_1 - V_28 -> V_34 ) >> V_42 ;
V_47 = F_9 ( V_28 -> V_45 , V_46 , V_29 ) ;
F_30 ( V_47 ) ;
V_11 = V_29 << V_42 ;
F_38 ( V_11 , & V_28 -> V_36 ) ;
F_24 () ;
return;
}
}
F_24 () ;
F_39 () ;
}
void F_40 ( struct V_15 * V_18 ,
void (* F_41)( struct V_15 * V_18 , struct V_27 * V_28 , void * V_24 ) ,
void * V_24 )
{
struct V_27 * V_28 ;
F_22 () ;
F_23 (chunk, &(pool)->chunks, next_chunk)
F_41 ( V_18 , V_28 , V_24 ) ;
F_24 () ;
}
T_2 F_42 ( struct V_15 * V_18 )
{
struct V_27 * V_28 ;
T_2 V_36 = 0 ;
F_22 () ;
F_23 (chunk, &pool->chunks, next_chunk)
V_36 += F_35 ( & V_28 -> V_36 ) ;
F_24 () ;
return V_36 ;
}
T_2 F_43 ( struct V_15 * V_18 )
{
struct V_27 * V_28 ;
T_2 V_11 = 0 ;
F_22 () ;
F_23 (chunk, &pool->chunks, next_chunk)
V_11 += V_28 -> V_35 - V_28 -> V_34 ;
F_24 () ;
return V_11 ;
}
void F_44 ( struct V_15 * V_18 , T_3 V_22 , void * V_24 )
{
F_22 () ;
V_18 -> V_22 = V_22 ;
if ( ! V_18 -> V_22 )
V_18 -> V_22 = V_23 ;
V_18 -> V_24 = V_24 ;
F_24 () ;
}
unsigned long V_23 ( unsigned long * V_7 , unsigned long V_11 ,
unsigned long V_8 , unsigned int V_9 , void * V_24 )
{
return F_45 ( V_7 , V_11 , V_8 , V_9 , 0 ) ;
}
unsigned long F_46 ( unsigned long * V_7 , unsigned long V_11 ,
unsigned long V_8 , unsigned int V_9 , void * V_24 )
{
unsigned long V_46 = V_11 ;
unsigned long V_49 = V_11 + 1 ;
unsigned long V_50 ;
V_50 = F_45 ( V_7 , V_11 , V_8 , V_9 , 0 ) ;
while ( V_50 < V_11 ) {
int V_51 = F_29 ( V_7 , V_11 , V_50 + V_9 ) ;
if ( ( V_51 - V_50 ) < V_49 ) {
V_49 = V_51 - V_50 ;
V_46 = V_50 ;
if ( V_49 == V_9 )
return V_46 ;
}
V_50 = F_45 ( V_7 , V_11 ,
V_51 + 1 , V_9 , 0 ) ;
}
return V_46 ;
}
static void F_47 ( struct V_52 * V_53 , void * V_54 )
{
F_25 ( * (struct V_15 * * ) V_54 ) ;
}
struct V_15 * F_48 ( struct V_52 * V_53 , int V_16 ,
int V_17 )
{
struct V_15 * * V_55 , * V_18 ;
V_55 = F_49 ( F_47 , sizeof( * V_55 ) , V_19 ) ;
V_18 = F_10 ( V_16 , V_17 ) ;
if ( V_18 ) {
* V_55 = V_18 ;
F_50 ( V_53 , V_55 ) ;
} else {
F_51 ( V_55 ) ;
}
return V_18 ;
}
struct V_15 * F_52 ( struct V_52 * V_53 )
{
struct V_15 * * V_10 = F_53 ( V_53 , F_47 , NULL ,
NULL ) ;
if ( ! V_10 )
return NULL ;
return * V_10 ;
}
struct V_15 * F_54 ( struct V_56 * V_57 ,
const char * V_58 , int V_50 )
{
struct V_59 * V_60 ;
struct V_56 * V_61 ;
V_61 = F_55 ( V_57 , V_58 , V_50 ) ;
if ( ! V_61 )
return NULL ;
V_60 = F_56 ( V_61 ) ;
if ( ! V_60 )
return NULL ;
return F_52 ( & V_60 -> V_53 ) ;
}
