static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int div ;
div = F_3 ( V_5 -> V_6 ) >> V_5 -> V_7 ;
div &= F_4 ( V_5 ) ;
if ( ! ( V_5 -> V_8 & V_9 ) )
div ++ ;
return V_3 / div ;
}
static int F_5 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_12 , V_13 = 0 ;
unsigned long V_3 , V_14 = 0 , V_15 , V_16 ;
if ( ! V_10 )
V_10 = 1 ;
V_16 = ( 1 << V_5 -> V_17 ) ;
if ( V_5 -> V_8 & V_9 )
V_16 -- ;
if ( ! V_11 ) {
V_3 = F_6 ( F_7 ( V_2 -> V_18 ) ) ;
V_13 = F_8 ( V_3 , V_10 ) ;
V_13 = V_13 == 0 ? 1 : V_13 ;
V_13 = V_13 > V_16 ? V_16 : V_13 ;
return V_13 ;
}
V_16 = F_9 ( V_19 / V_10 , V_16 ) ;
for ( V_12 = 1 ; V_12 <= V_16 ; V_12 ++ ) {
V_3 = F_10 ( F_7 ( V_2 -> V_18 ) ,
F_11 ( V_10 , V_12 ) ) ;
V_15 = V_3 / V_12 ;
if ( V_15 <= V_10 && V_15 > V_14 ) {
V_13 = V_12 ;
V_14 = V_15 ;
* V_11 = V_3 ;
}
}
if ( ! V_13 ) {
V_13 = ( 1 << V_5 -> V_17 ) ;
if ( V_5 -> V_8 & V_9 )
V_13 -- ;
* V_11 = F_10 ( F_7 ( V_2 -> V_18 ) , 1 ) ;
}
return V_13 ;
}
static long F_12 ( struct V_1 * V_2 , unsigned long V_10 ,
unsigned long * V_20 )
{
int div ;
div = F_5 ( V_2 , V_10 , V_20 ) ;
if ( V_20 )
return * V_20 / div ;
else {
unsigned long V_21 ;
V_21 = F_6 ( F_7 ( V_2 -> V_18 ) ) ;
return V_21 / div ;
}
}
static int F_13 ( struct V_1 * V_2 , unsigned long V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int div ;
unsigned long V_8 = 0 ;
T_1 V_22 ;
div = F_6 ( F_7 ( V_2 -> V_18 ) ) / V_10 ;
if ( ! ( V_5 -> V_8 & V_9 ) )
div -- ;
if ( div > F_4 ( V_5 ) )
div = F_4 ( V_5 ) ;
if ( V_5 -> V_23 )
F_14 ( V_5 -> V_23 , V_8 ) ;
V_22 = F_3 ( V_5 -> V_6 ) ;
V_22 &= ~ ( F_4 ( V_5 ) << V_5 -> V_7 ) ;
V_22 |= div << V_5 -> V_7 ;
F_15 ( V_22 , V_5 -> V_6 ) ;
if ( V_5 -> V_23 )
F_16 ( V_5 -> V_23 , V_8 ) ;
return 0 ;
}
struct V_18 * F_17 ( struct V_24 * V_25 , const char * V_26 ,
const char * V_27 , unsigned long V_8 ,
void T_2 * V_6 , T_3 V_7 , T_3 V_17 ,
T_3 V_28 , T_4 * V_23 )
{
struct V_4 * div ;
struct V_18 * V_18 ;
div = F_18 ( sizeof( struct V_4 ) , V_29 ) ;
if ( ! div ) {
F_19 ( L_1 , V_30 ) ;
return NULL ;
}
div -> V_6 = V_6 ;
div -> V_7 = V_7 ;
div -> V_17 = V_17 ;
div -> V_8 = V_28 ;
div -> V_23 = V_23 ;
if ( V_27 ) {
div -> V_31 [ 0 ] = F_20 ( V_27 , V_29 ) ;
if ( ! div -> V_31 [ 0 ] )
goto V_32;
}
V_18 = F_21 ( V_25 , V_26 ,
& V_33 , & div -> V_2 ,
div -> V_31 ,
( V_27 ? 1 : 0 ) ,
V_8 ) ;
if ( V_18 )
return V_18 ;
V_32:
F_22 ( div -> V_31 [ 0 ] ) ;
F_22 ( div ) ;
return NULL ;
}
