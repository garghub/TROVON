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
#ifdef F_2
V_4 -> V_7 [ V_18 ] == V_19 &&
#else
V_4 -> V_7 [ V_18 ] == V_20 &&
#endif
( V_4 -> V_21 == V_22 ||
V_4 -> V_21 == V_23 ) &&
V_4 -> V_24 == V_25 ) )
return 0 ;
V_5 = ( T_2 * ) ( ( unsigned long ) V_4 +
( unsigned long ) V_4 -> V_26 ) ;
for ( V_6 = 0 ; V_6 < ( unsigned int ) V_4 -> V_27 ; V_6 ++ , V_5 ++ )
if ( V_5 -> V_28 == V_29 )
break;
if ( V_6 >= ( unsigned int ) V_4 -> V_27 )
return 0 ;
V_3 -> V_30 = ( unsigned long ) V_5 -> V_31 ;
V_3 -> V_32 = ( unsigned long ) V_5 -> V_33 ;
V_3 -> V_34 = ( unsigned long ) V_5 -> V_35 ;
return 1 ;
}
int F_3 ( void * V_1 , struct V_2 * V_3 )
{
T_3 * V_36 = V_1 ;
T_4 * V_37 ;
unsigned int V_6 ;
if ( ! ( V_36 -> V_7 [ V_8 ] == V_9 &&
V_36 -> V_7 [ V_10 ] == V_11 &&
V_36 -> V_7 [ V_12 ] == V_13 &&
V_36 -> V_7 [ V_14 ] == V_15 &&
V_36 -> V_7 [ V_16 ] == V_38 &&
V_36 -> V_7 [ V_18 ] == V_20 &&
( V_36 -> V_21 == V_22 ||
V_36 -> V_21 == V_23 ) &&
V_36 -> V_24 == V_39 ) )
return 0 ;
V_37 = ( T_4 * ) ( ( unsigned long ) V_36 + V_36 -> V_26 ) ;
for ( V_6 = 0 ; V_6 < V_36 -> V_27 ; V_6 ++ , V_37 ++ )
if ( V_37 -> V_28 == V_29 )
break;
if ( V_6 >= V_36 -> V_27 )
return 0 ;
V_3 -> V_30 = V_37 -> V_31 ;
V_3 -> V_32 = V_37 -> V_33 ;
V_3 -> V_34 = V_37 -> V_35 ;
return 1 ;
}
