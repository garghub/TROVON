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
}
return V_18 ;
}
int F_14 ( struct V_15 * V_18 , unsigned long V_22 , T_1 V_23 ,
T_2 V_11 , int V_17 )
{
struct V_24 * V_25 ;
int V_26 = V_11 >> V_18 -> V_16 ;
int V_27 = sizeof( struct V_24 ) +
( V_26 + V_28 - 1 ) / V_28 ;
V_25 = F_11 ( V_27 , V_19 | V_29 , V_17 ) ;
if ( F_15 ( V_25 == NULL ) )
return - V_30 ;
V_25 -> V_31 = V_23 ;
V_25 -> V_32 = V_22 ;
V_25 -> V_33 = V_22 + V_11 ;
F_16 ( & V_25 -> V_34 , V_11 ) ;
F_17 ( & V_18 -> V_20 ) ;
F_18 ( & V_25 -> V_35 , & V_18 -> V_21 ) ;
F_19 ( & V_18 -> V_20 ) ;
return 0 ;
}
T_1 F_20 ( struct V_15 * V_18 , unsigned long V_1 )
{
struct V_24 * V_25 ;
T_1 V_36 = - 1 ;
F_21 () ;
F_22 (chunk, &pool->chunks, next_chunk) {
if ( V_1 >= V_25 -> V_32 && V_1 < V_25 -> V_33 ) {
V_36 = V_25 -> V_31 + ( V_1 - V_25 -> V_32 ) ;
break;
}
}
F_23 () ;
return V_36 ;
}
void F_24 ( struct V_15 * V_18 )
{
struct V_37 * V_38 , * V_39 ;
struct V_24 * V_25 ;
int V_40 = V_18 -> V_16 ;
int V_41 , V_42 ;
F_25 (_chunk, _next_chunk, &pool->chunks) {
V_25 = F_26 ( V_38 , struct V_24 , V_35 ) ;
F_27 ( & V_25 -> V_35 ) ;
V_42 = ( V_25 -> V_33 - V_25 -> V_32 ) >> V_40 ;
V_41 = F_28 ( V_25 -> V_43 , V_42 , 0 ) ;
F_29 ( V_41 < V_42 ) ;
F_30 ( V_25 ) ;
}
F_30 ( V_18 ) ;
return;
}
unsigned long F_31 ( struct V_15 * V_18 , T_2 V_11 )
{
struct V_24 * V_25 ;
unsigned long V_1 = 0 ;
int V_40 = V_18 -> V_16 ;
int V_26 , V_44 = 0 , V_42 , V_45 ;
#ifndef F_32
F_29 ( F_33 () ) ;
#endif
if ( V_11 == 0 )
return 0 ;
V_26 = ( V_11 + ( 1UL << V_40 ) - 1 ) >> V_40 ;
F_21 () ;
F_22 (chunk, &pool->chunks, next_chunk) {
if ( V_11 > F_34 ( & V_25 -> V_34 ) )
continue;
V_42 = ( V_25 -> V_33 - V_25 -> V_32 ) >> V_40 ;
V_46:
V_44 = F_35 ( V_25 -> V_43 , V_42 ,
V_44 , V_26 , 0 ) ;
if ( V_44 >= V_42 )
continue;
V_45 = F_5 ( V_25 -> V_43 , V_44 , V_26 ) ;
if ( V_45 ) {
V_45 = F_9 ( V_25 -> V_43 , V_44 ,
V_26 - V_45 ) ;
F_29 ( V_45 ) ;
goto V_46;
}
V_1 = V_25 -> V_32 + ( ( unsigned long ) V_44 << V_40 ) ;
V_11 = V_26 << V_40 ;
F_36 ( V_11 , & V_25 -> V_34 ) ;
break;
}
F_23 () ;
return V_1 ;
}
void F_37 ( struct V_15 * V_18 , unsigned long V_1 , T_2 V_11 )
{
struct V_24 * V_25 ;
int V_40 = V_18 -> V_16 ;
int V_44 , V_26 , V_45 ;
#ifndef F_32
F_29 ( F_33 () ) ;
#endif
V_26 = ( V_11 + ( 1UL << V_40 ) - 1 ) >> V_40 ;
F_21 () ;
F_22 (chunk, &pool->chunks, next_chunk) {
if ( V_1 >= V_25 -> V_32 && V_1 < V_25 -> V_33 ) {
F_29 ( V_1 + V_11 > V_25 -> V_33 ) ;
V_44 = ( V_1 - V_25 -> V_32 ) >> V_40 ;
V_45 = F_9 ( V_25 -> V_43 , V_44 , V_26 ) ;
F_29 ( V_45 ) ;
V_11 = V_26 << V_40 ;
F_38 ( V_11 , & V_25 -> V_34 ) ;
F_23 () ;
return;
}
}
F_23 () ;
F_39 () ;
}
void F_40 ( struct V_15 * V_18 ,
void (* F_41)( struct V_15 * V_18 , struct V_24 * V_25 , void * V_47 ) ,
void * V_47 )
{
struct V_24 * V_25 ;
F_21 () ;
F_22 (chunk, &(pool)->chunks, next_chunk)
F_41 ( V_18 , V_25 , V_47 ) ;
F_23 () ;
}
T_2 F_42 ( struct V_15 * V_18 )
{
struct V_24 * V_25 ;
T_2 V_34 = 0 ;
F_21 () ;
F_22 (chunk, &pool->chunks, next_chunk)
V_34 += F_34 ( & V_25 -> V_34 ) ;
F_23 () ;
return V_34 ;
}
T_2 F_43 ( struct V_15 * V_18 )
{
struct V_24 * V_25 ;
T_2 V_11 = 0 ;
F_21 () ;
F_22 (chunk, &pool->chunks, next_chunk)
V_11 += V_25 -> V_33 - V_25 -> V_32 ;
F_23 () ;
return V_11 ;
}
