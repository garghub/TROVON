void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 ) {
memset ( V_4 , 0 , sizeof( struct V_3 ) ) ;
F_2 ( V_4 ) ;
}
}
int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_6 ;
V_2 -> V_5 = F_4 (
sizeof( struct V_3 ) , V_7 ) ;
if ( ! V_2 -> V_5 ) {
F_5 ( L_1 ,
sizeof( struct V_3 ) ) ;
V_6 = - V_8 ;
goto V_9;
}
V_4 = V_2 -> V_5 ;
V_4 -> V_10 = 0 ;
return 0 ;
V_9:
F_1 ( V_2 ) ;
return V_6 ;
}
T_1 F_6 ( struct V_1 * V_2 , T_2 V_11 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_12 ;
if ( F_7 ( ( V_11 & 0x3 ) != 0 ) ) {
F_5 ( L_2 ,
V_11 ) ;
return V_13 ;
}
if ( F_7 ( V_11 > ( V_14 - V_4 -> V_10 ) ) ) {
F_5 ( L_3 ,
V_11 , V_4 -> V_10 ) ;
return V_13 ;
}
V_12 = V_4 -> V_10 ;
V_4 -> V_10 += V_11 ;
F_8 ( L_4 , V_11 , ( unsigned int ) V_12 ) ;
return V_12 ;
}
void F_9 (
const T_2 * V_15 , T_1 V_16 ,
unsigned int V_17 ,
struct V_18 * V_19 , unsigned int * V_20 )
{
T_2 V_21 ;
unsigned int V_22 = * V_20 ;
for ( V_21 = 0 ; V_21 < V_17 ; V_21 ++ , V_22 ++ ) {
F_10 ( & V_19 [ V_22 ] ) ;
F_11 ( & V_19 [ V_22 ] , V_15 [ V_21 ] , sizeof( T_2 ) ) ;
F_12 ( & V_19 [ V_22 ] , V_16 + ( V_21 * sizeof( T_2 ) ) , sizeof( T_2 ) ) ;
F_13 ( & V_19 [ V_22 ] , V_23 ) ;
}
* V_20 = V_22 ;
}
