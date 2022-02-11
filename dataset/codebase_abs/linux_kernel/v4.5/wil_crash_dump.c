static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , T_1 * V_4 )
{
int V_5 ;
const struct V_6 * V_7 ;
T_1 V_8 , V_9 , V_10 ;
if ( ! V_3 )
return - V_11 ;
F_2 ( F_3 ( V_12 ) == 0 ) ;
V_7 = & V_12 [ 0 ] ;
V_8 = V_7 -> V_13 ;
V_9 = V_7 -> V_13 + ( V_7 -> V_14 - V_7 -> V_15 ) ;
for ( V_5 = 1 ; V_5 < F_3 ( V_12 ) ; V_5 ++ ) {
V_7 = & V_12 [ V_5 ] ;
if ( V_7 -> V_13 < V_8 )
V_8 = V_7 -> V_13 ;
V_10 = V_7 -> V_13 + ( V_7 -> V_14 - V_7 -> V_15 ) ;
if ( V_10 > V_9 )
V_9 = V_10 ;
}
* V_3 = V_9 - V_8 ;
if ( V_4 )
* V_4 = V_8 ;
return 0 ;
}
int F_4 ( struct V_1 * V_2 , void * V_16 , T_1 V_17 )
{
int V_5 ;
const struct V_6 * V_7 ;
void * V_18 ;
T_1 V_8 , V_19 , V_20 , V_21 ;
if ( F_1 ( V_2 , & V_19 , & V_8 ) ) {
F_5 ( V_2 , L_1 , V_22 ) ;
return - V_11 ;
}
if ( V_19 > V_17 ) {
F_5 ( V_2 , L_2 ,
V_22 , V_19 , V_17 ) ;
return - V_11 ;
}
for ( V_5 = 0 ; V_5 < F_3 ( V_12 ) ; V_5 ++ ) {
V_7 = & V_12 [ V_5 ] ;
V_18 = ( void * V_23 ) V_2 -> V_24 + F_6 ( V_7 -> V_13 ) ;
V_21 = V_7 -> V_14 - V_7 -> V_15 ;
V_20 = V_7 -> V_13 - V_8 ;
F_7 ( V_2 , L_3 ,
V_22 , V_12 [ V_5 ] . V_25 , V_21 , V_20 ) ;
F_8 ( ( void * V_23 ) ( V_16 + V_20 ) ,
( const void V_26 * V_23 ) V_18 , V_21 ) ;
}
return 0 ;
}
void F_9 ( struct V_1 * V_2 )
{
void * V_27 ;
T_1 V_28 ;
if ( F_1 ( V_2 , & V_28 , NULL ) ) {
F_5 ( V_2 , L_4 , V_22 ) ;
return;
}
V_27 = F_10 ( V_28 ) ;
if ( ! V_27 )
return;
if ( F_4 ( V_2 , V_27 , V_28 ) ) {
F_11 ( V_27 ) ;
return;
}
F_12 ( F_13 ( V_2 ) , V_27 , V_28 , V_29 ) ;
F_14 ( V_2 , L_5 , V_22 ,
V_28 ) ;
}
