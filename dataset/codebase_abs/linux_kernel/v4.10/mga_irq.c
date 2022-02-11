T_1 F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
const T_2 * const V_4 =
( T_2 * ) V_2 -> V_5 ;
if ( V_3 != 0 )
return 0 ;
return F_2 ( & V_4 -> V_6 ) ;
}
T_3 F_3 ( int V_7 , void * V_8 )
{
struct V_1 * V_2 = (struct V_1 * ) V_8 ;
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
int V_9 ;
int V_10 = 0 ;
V_9 = F_4 ( V_11 ) ;
if ( V_9 & V_12 ) {
F_5 ( V_13 , V_14 ) ;
F_6 ( & V_4 -> V_6 ) ;
F_7 ( V_2 , 0 ) ;
V_10 = 1 ;
}
if ( V_9 & V_15 ) {
const T_1 V_16 = F_4 ( V_17 ) ;
const T_1 V_18 = F_4 ( V_19 ) ;
F_5 ( V_13 , V_20 ) ;
if ( ( V_16 & ~ 0x03 ) != ( V_18 & ~ 0x03 ) )
F_5 ( V_19 , V_18 ) ;
F_6 ( & V_4 -> V_21 ) ;
F_8 ( & V_4 -> V_22 ) ;
V_10 = 1 ;
}
if ( V_10 )
return V_23 ;
return V_24 ;
}
int F_9 ( struct V_1 * V_2 , unsigned int V_3 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
if ( V_3 != 0 ) {
F_10 ( L_1 ,
V_3 ) ;
return 0 ;
}
F_5 ( V_25 , V_26 | V_15 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 , unsigned int V_3 )
{
if ( V_3 != 0 ) {
F_10 ( L_2 ,
V_3 ) ;
}
}
int F_12 ( struct V_1 * V_2 , unsigned int * V_27 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
unsigned int V_28 ;
int V_29 = 0 ;
F_13 ( V_29 , V_4 -> V_22 , 3 * V_30 ,
( ( ( V_28 = F_2 ( & V_4 -> V_21 ) )
- * V_27 ) <= ( 1 << 23 ) ) ) ;
* V_27 = V_28 ;
return V_29 ;
}
void F_14 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
F_5 ( V_25 , 0 ) ;
F_5 ( V_13 , ~ 0 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
F_16 ( & V_4 -> V_22 ) ;
F_5 ( V_25 , V_15 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
if ( ! V_4 )
return;
F_5 ( V_25 , 0 ) ;
V_2 -> V_31 = false ;
}
