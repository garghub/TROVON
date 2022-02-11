void F_1 ( void )
{
F_2 ( & V_1 ) ;
}
void F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static void F_5 ( struct V_2 * V_3 , T_1 V_4 )
{
T_1 V_5 = V_3 -> V_6 ;
T_1 V_7 = 0 ;
T_1 V_8 ;
T_2 V_9 ;
V_3 -> V_6 = V_4 ;
V_8 = V_4 - V_5 ;
if ( V_8 >= V_10 ) {
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_6 = V_4 ;
return;
}
V_9 = V_8 - V_3 -> V_11 ;
V_3 -> V_12 ++ ;
if ( F_6 ( V_3 -> V_12 > 1 ) )
V_7 = V_3 -> V_7 >> V_13 ;
if ( ( V_3 -> V_12 >= 30 ) && ( ( V_9 * V_9 ) > ( 9 * V_7 ) ) ) {
if ( V_3 -> V_14 ++ >= 3 ) {
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_6 = V_4 ;
return;
}
} else {
V_3 -> V_14 = 0 ;
}
V_3 -> V_15 = 1 ;
V_3 -> V_11 = V_3 -> V_11 + ( V_9 >> V_13 ) ;
V_3 -> V_7 = V_3 -> V_7 + ( V_9 * ( V_8 - V_3 -> V_11 ) ) ;
V_3 -> V_16 = V_4 + V_3 -> V_11 ;
}
T_1 F_7 ( T_1 V_17 )
{
struct V_18 * V_19 = F_8 ( & V_18 ) ;
struct V_2 * V_3 ;
struct V_2 T_3 * V_20 ;
T_1 V_4 , V_16 = V_21 ;
int V_22 , V_23 = 0 ;
F_9 ( ! F_10 () ) ;
for ( V_22 = V_19 -> V_24 & V_25 ,
V_19 -> V_24 = F_11 ( V_26 , V_19 -> V_24 ) ;
V_19 -> V_24 > 0 ; V_19 -> V_24 -- , V_22 = ( V_22 + 1 ) & V_25 ) {
V_23 = F_12 ( V_19 -> V_27 [ V_22 ] , & V_4 ) ;
V_20 = F_13 ( & V_28 , V_23 ) ;
if ( V_20 ) {
V_3 = F_8 ( V_20 ) ;
F_5 ( V_3 , V_4 ) ;
}
}
F_14 (&irqt_stats, s, i) {
V_3 = F_8 ( V_20 ) ;
if ( ! V_3 -> V_15 )
continue;
if ( V_3 -> V_16 <= V_17 ) {
V_23 = V_22 ;
V_16 = V_17 ;
V_3 -> V_15 = 0 ;
break;
}
if ( V_3 -> V_16 < V_16 ) {
V_23 = V_22 ;
V_16 = V_3 -> V_16 ;
}
}
return V_16 ;
}
void F_15 ( int V_23 )
{
struct V_2 T_3 * V_20 ;
V_20 = F_13 ( & V_28 , V_23 ) ;
if ( V_20 ) {
F_16 ( V_20 ) ;
F_17 ( & V_28 , V_23 ) ;
}
}
int F_18 ( int V_23 )
{
struct V_2 T_3 * V_20 ;
int V_29 ;
V_20 = F_13 ( & V_28 , V_23 ) ;
if ( V_20 )
return 0 ;
V_20 = F_19 ( * V_20 ) ;
if ( ! V_20 )
return - V_30 ;
F_20 ( V_31 ) ;
V_29 = F_21 ( & V_28 , V_20 , V_23 , V_23 + 1 , V_32 ) ;
F_22 () ;
if ( V_29 < 0 ) {
F_16 ( V_20 ) ;
return V_29 ;
}
return 0 ;
}
