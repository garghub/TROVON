int F_1 ( void * V_1 , struct V_2 * V_3 )
{
T_1 * V_4 = V_1 ;
T_2 * V_5 ;
unsigned int V_6 ;
if ( ! ( V_4 -> V_7 [ V_8 ] == V_9 &&
V_4 -> V_7 [ V_10 ] == V_11 &&
V_4 -> V_7 [ V_12 ] == V_13 &&
V_4 -> V_7 [ V_14 ] == V_15 &&
V_4 -> V_7 [ V_16 ] == V_17 &&
V_4 -> V_7 [ V_18 ] == V_19 &&
( V_4 -> V_20 == V_21 ||
V_4 -> V_20 == V_22 ) &&
V_4 -> V_23 == V_24 ) )
return 0 ;
V_5 = ( T_2 * ) ( ( unsigned long ) V_4 +
( unsigned long ) V_4 -> V_25 ) ;
for ( V_6 = 0 ; V_6 < ( unsigned int ) V_4 -> V_26 ; V_6 ++ , V_5 ++ )
if ( V_5 -> V_27 == V_28 )
break;
if ( V_6 >= ( unsigned int ) V_4 -> V_26 )
return 0 ;
V_3 -> V_29 = ( unsigned long ) V_5 -> V_30 ;
V_3 -> V_31 = ( unsigned long ) V_5 -> V_32 ;
V_3 -> V_33 = ( unsigned long ) V_5 -> V_34 ;
return 1 ;
}
int F_2 ( void * V_1 , struct V_2 * V_3 )
{
T_3 * V_35 = V_1 ;
T_4 * V_36 ;
unsigned int V_6 ;
if ( ! ( V_35 -> V_7 [ V_8 ] == V_9 &&
V_35 -> V_7 [ V_10 ] == V_11 &&
V_35 -> V_7 [ V_12 ] == V_13 &&
V_35 -> V_7 [ V_14 ] == V_15 &&
V_35 -> V_7 [ V_16 ] == V_37 &&
V_35 -> V_7 [ V_18 ] == V_19 &&
( V_35 -> V_20 == V_21 ||
V_35 -> V_20 == V_22 ) &&
V_35 -> V_23 == V_38 ) )
return 0 ;
V_36 = ( T_4 * ) ( ( unsigned long ) V_35 + V_35 -> V_25 ) ;
for ( V_6 = 0 ; V_6 < V_35 -> V_26 ; V_6 ++ , V_36 ++ )
if ( V_36 -> V_27 == V_28 )
break;
if ( V_6 >= V_35 -> V_26 )
return 0 ;
V_3 -> V_29 = V_36 -> V_30 ;
V_3 -> V_31 = V_36 -> V_32 ;
V_3 -> V_33 = V_36 -> V_34 ;
return 1 ;
}
