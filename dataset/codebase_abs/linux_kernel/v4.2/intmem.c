static void F_1 ( void )
{
static int V_1 = 0 ;
if ( ! V_1 ) {
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof *V_3 , V_4 ) ;
F_3 ( & V_5 ) ;
V_6 = F_4 ( V_7 + V_8 ,
V_9 - V_8 ) ;
V_1 = 1 ;
V_3 -> V_10 = V_9 - V_8 ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = V_13 ;
F_5 ( & V_3 -> V_14 , & V_5 ) ;
}
}
void * F_6 ( unsigned V_10 , unsigned V_15 )
{
struct V_2 * V_16 ;
struct V_2 * V_17 ;
void * V_18 = NULL ;
F_7 () ;
F_1 () ;
F_8 (allocation, tmp, &intmem_allocations, entry) {
int V_19 = V_16 -> V_11 % V_15 ;
V_19 = V_19 ? V_15 - V_19 : V_19 ;
if ( V_16 -> V_12 == V_13 &&
V_16 -> V_10 >= V_10 + V_19 ) {
if ( V_16 -> V_10 > V_10 + V_19 ) {
struct V_2 * V_3 ;
V_3 = F_2 ( sizeof *V_3 , V_20 ) ;
V_3 -> V_12 = V_13 ;
V_3 -> V_10 = V_16 -> V_10 - V_10 -
V_19 ;
V_3 -> V_11 = V_16 -> V_11 + V_10 +
V_19 ;
F_9 ( & V_3 -> V_14 , & V_16 -> V_14 ) ;
if ( V_19 ) {
struct V_2 * V_17 ;
V_17 = F_2 ( sizeof *V_17 , V_20 ) ;
V_17 -> V_11 = V_16 -> V_11 ;
V_17 -> V_10 = V_19 ;
V_17 -> V_12 = V_13 ;
V_16 -> V_11 += V_19 ;
F_5 ( & V_17 -> V_14 ,
& V_16 -> V_14 ) ;
}
}
V_16 -> V_12 = V_21 ;
V_16 -> V_10 = V_10 ;
V_18 = ( void * ) ( ( int ) V_6 + V_16 -> V_11 ) ;
}
}
F_10 () ;
return V_18 ;
}
void F_11 ( void * V_22 )
{
struct V_2 * V_16 ;
struct V_2 * V_17 ;
if ( V_22 == NULL )
return;
F_7 () ;
F_1 () ;
F_8 (allocation, tmp, &intmem_allocations, entry) {
if ( V_16 -> V_11 == ( int ) ( V_22 - V_6 ) ) {
struct V_2 * V_23 =
F_12 ( V_16 -> V_14 . V_23 ,
struct V_2 , V_14 ) ;
struct V_2 * V_24 =
F_12 ( V_16 -> V_14 . V_24 ,
struct V_2 , V_14 ) ;
V_16 -> V_12 = V_13 ;
if ( ( V_23 != & V_5 ) &&
( V_23 -> V_12 == V_13 ) ) {
V_23 -> V_10 += V_16 -> V_10 ;
F_13 ( & V_16 -> V_14 ) ;
F_14 ( V_16 ) ;
V_16 = V_23 ;
}
if ( ( V_24 != & V_5 ) &&
( V_24 -> V_12 == V_13 ) ) {
V_16 -> V_10 += V_24 -> V_10 ;
F_13 ( & V_24 -> V_14 ) ;
F_14 ( V_24 ) ;
}
F_10 () ;
return;
}
}
F_10 () ;
}
void * F_15 ( unsigned long V_22 )
{
return ( void * ) ( V_22 - ( V_7 + V_8 ) +
( unsigned long ) V_6 ) ;
}
unsigned long F_16 ( void * V_22 )
{
return ( unsigned long ) ( ( unsigned long ) V_22 -
( unsigned long ) V_6 + V_7 +
V_8 ) ;
}
