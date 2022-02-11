T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
const T_2 * const V_4 =
( T_2 * ) V_2 -> V_5 ;
if ( V_3 != 0 )
return 0 ;
return F_2 ( & V_4 -> V_6 ) ;
}
T_3 F_3 ( T_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_7 ;
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
int V_8 ;
int V_9 = 0 ;
V_8 = F_4 ( V_10 ) ;
if ( V_8 & V_11 ) {
F_5 ( V_12 , V_13 ) ;
F_6 ( & V_4 -> V_6 ) ;
F_7 ( V_2 , 0 ) ;
V_9 = 1 ;
}
if ( V_8 & V_14 ) {
const T_1 V_15 = F_4 ( V_16 ) ;
const T_1 V_17 = F_4 ( V_18 ) ;
F_5 ( V_12 , V_19 ) ;
if ( ( V_15 & ~ 0x03 ) != ( V_17 & ~ 0x03 ) )
F_5 ( V_18 , V_17 ) ;
F_6 ( & V_4 -> V_20 ) ;
F_8 ( & V_4 -> V_21 ) ;
V_9 = 1 ;
}
if ( V_9 )
return V_22 ;
return V_23 ;
}
int F_9 ( struct V_1 * V_2 , int V_3 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
if ( V_3 != 0 ) {
F_10 ( L_1 ,
V_3 ) ;
return 0 ;
}
F_5 ( V_24 , V_25 | V_14 ) ;
return 0 ;
}
void F_11 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 != 0 ) {
F_10 ( L_2 ,
V_3 ) ;
}
}
int F_12 ( struct V_1 * V_2 , unsigned int * V_26 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
unsigned int V_27 ;
int V_28 = 0 ;
F_13 ( V_28 , V_4 -> V_21 , 3 * V_29 ,
( ( ( V_27 = F_2 ( & V_4 -> V_20 ) )
- * V_26 ) <= ( 1 << 23 ) ) ) ;
* V_26 = V_27 ;
return V_28 ;
}
void F_14 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
F_5 ( V_24 , 0 ) ;
F_5 ( V_12 , ~ 0 ) ;
}
int F_15 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
F_16 ( & V_4 -> V_21 ) ;
F_5 ( V_24 , V_14 ) ;
return 0 ;
}
void F_17 ( struct V_1 * V_2 )
{
T_2 * V_4 = ( T_2 * ) V_2 -> V_5 ;
if ( ! V_4 )
return;
F_5 ( V_24 , 0 ) ;
V_2 -> V_30 = false ;
}
