static int T_1 F_1 ( void )
{
int V_1 = 0 , V_2 = 0 ;
unsigned long V_3 , V_4 , V_5 = 0 ;
T_2 * V_6 = ( T_2 * ) V_7 ;
V_3 = V_6 -> V_8 ;
V_4 = V_6 -> V_9 ;
V_10 = F_2 ( V_3 , V_4 ) ;
if ( ! V_10 ) {
F_3 ( V_11 L_1 , V_12 , V_3 ) ;
return - V_13 ;
}
for ( V_1 = 0 ; V_1 < V_14 ; V_1 ++ ) {
if( V_5 >= V_4 )
break;
F_3 ( V_15 L_2 , V_12 , V_1 ) ;
V_16 [ V_1 ] = F_4 ( sizeof( struct V_17 ) , V_18 ) ;
if( V_16 [ V_1 ] == NULL ) {
V_2 = - V_19 ;
goto V_20;
}
V_16 [ V_1 ] -> V_21 = F_5 ( 16 , V_18 ) ;
if ( ! V_16 [ V_1 ] -> V_21 ) {
V_2 = - V_19 ;
goto V_20;
}
sprintf ( V_16 [ V_1 ] -> V_21 , L_3 , V_1 ) ;
V_16 [ V_1 ] -> V_22 = V_4 ;
V_16 [ V_1 ] -> V_23 = 4 ;
F_6 ( V_16 [ V_1 ] ) ;
V_16 [ V_1 ] -> V_24 = V_10 ;
V_16 [ V_1 ] -> V_25 = V_3 ;
if ( V_1 && V_26 [ V_1 - 1 ] ) {
V_16 [ V_1 ] -> V_24 += V_26 [ V_1 - 1 ] -> V_22 ;
V_16 [ V_1 ] -> V_25 += V_26 [ V_1 - 1 ] -> V_22 ;
}
V_26 [ V_1 ] = F_7 ( L_4 , V_16 [ V_1 ] ) ;
if ( V_26 [ V_1 ] ) {
V_26 [ V_1 ] -> V_27 = V_28 ;
V_5 += V_26 [ V_1 ] -> V_22 ;
V_29 ++ ;
F_3 ( V_15 L_5 , V_12 , V_29 ,
V_26 [ V_1 ] -> V_21 , V_26 [ V_1 ] -> V_22 ) ;
}
}
if ( ! V_29 ) {
F_3 ( V_30 L_6 ) ;
V_2 = - V_31 ;
goto V_20;
}
V_32 [ 0 ] . V_33 = V_34 ;
V_32 [ 0 ] . type = L_7 ;
V_32 [ 0 ] . V_35 = F_8 ( V_34 ) ;
V_32 [ 1 ] . V_33 = V_36 ;
V_32 [ 1 ] . type = L_8 ;
V_32 [ 1 ] . V_35 = F_8 ( V_36 ) ;
for( V_1 = 0 ; V_1 < V_29 ; V_1 ++ ) {
if ( V_32 [ V_1 ] . V_35 == 0 )
F_3 ( V_30 L_9 , V_1 ) ;
else
F_3 ( V_30 L_10 ,
V_1 , V_32 [ V_1 ] . type ) ;
F_9 ( V_26 [ V_1 ] , V_32 [ V_1 ] . V_33 ,
V_32 [ V_1 ] . V_35 ) ;
}
return 0 ;
V_20:
for( V_1 = 0 ; V_1 < V_14 ; V_1 ++ ) {
if( V_16 [ V_1 ] != NULL ) {
F_10 ( V_16 [ V_1 ] -> V_21 ) ;
V_16 [ V_1 ] -> V_21 = NULL ;
F_10 ( V_16 [ V_1 ] ) ;
V_16 [ V_1 ] = NULL ;
}
}
error:
F_11 ( V_10 ) ;
return V_2 ;
}
static void T_3 F_12 ( void )
{
unsigned int V_1 = 0 ;
for( V_1 = 0 ; V_1 < V_29 ; V_1 ++ ) {
if ( V_26 [ V_1 ] ) {
F_13 ( V_26 [ V_1 ] ) ;
F_14 ( V_26 [ V_1 ] ) ;
}
F_10 ( V_16 [ V_1 ] -> V_21 ) ;
F_10 ( V_16 [ V_1 ] ) ;
}
if ( V_10 ) {
F_11 ( V_10 ) ;
V_10 = 0 ;
}
}
