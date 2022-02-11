int F_1 ( struct V_1 * V_2 , T_1 V_3 , int V_4 )
{
struct V_5 * V_5 = V_2 -> V_6 -> V_7 ;
struct V_8 * V_9 = V_5 -> V_10 -> V_11 ;
int V_12 = ( F_2 ( V_5 ) - 1 ) >> V_13 ;
int V_14 = ( 1 << ( V_9 -> V_15 - V_13 ) ) - 1 ;
int V_16 = V_2 -> V_17 & ~ V_14 ;
int V_18 = V_16 | V_14 ;
int V_19 , V_20 , V_21 , V_22 , V_23 , V_24 = - V_25 ;
struct V_1 * * V_1 ;
struct V_26 * V_27 ;
void * V_28 ;
if ( V_18 > V_12 )
V_18 = V_12 ;
V_21 = V_18 - V_16 + 1 ;
V_1 = F_3 ( sizeof( void * ) * V_21 , V_29 ) ;
if ( V_1 == NULL )
return V_24 ;
V_27 = F_4 ( V_1 , V_21 , 0 ) ;
if ( V_27 == NULL )
goto V_30;
for ( V_22 = 0 , V_19 = 0 , V_20 = V_16 ; V_19 < V_21 ; V_19 ++ , V_20 ++ ) {
V_1 [ V_19 ] = ( V_20 == V_2 -> V_17 ) ? V_2 :
F_5 ( V_2 -> V_6 , V_20 ) ;
if ( V_1 [ V_19 ] == NULL ) {
V_22 ++ ;
continue;
}
if ( F_6 ( V_1 [ V_19 ] ) ) {
F_7 ( V_1 [ V_19 ] ) ;
F_8 ( V_1 [ V_19 ] ) ;
V_1 [ V_19 ] = NULL ;
V_22 ++ ;
}
}
if ( V_22 ) {
V_24 = F_9 ( V_2 , V_3 , V_4 , V_21 ,
V_1 ) ;
if ( V_24 < 0 )
goto V_31;
goto V_30;
}
V_24 = F_10 ( V_5 -> V_10 , V_3 , V_4 , NULL , V_27 ) ;
if ( V_24 < 0 )
goto V_31;
V_23 = V_24 % V_32 ;
if ( V_23 ) {
V_28 = F_11 ( V_1 [ V_21 - 1 ] ) ;
memset ( V_28 + V_23 , 0 , V_32 - V_23 ) ;
F_12 ( V_28 ) ;
}
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
F_13 ( V_1 [ V_19 ] ) ;
F_14 ( V_1 [ V_19 ] ) ;
F_7 ( V_1 [ V_19 ] ) ;
if ( V_1 [ V_19 ] != V_2 )
F_8 ( V_1 [ V_19 ] ) ;
}
F_15 ( V_27 ) ;
F_15 ( V_1 ) ;
return 0 ;
V_31:
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ ) {
if ( V_1 [ V_19 ] == NULL || V_1 [ V_19 ] == V_2 )
continue;
F_13 ( V_1 [ V_19 ] ) ;
F_16 ( V_1 [ V_19 ] ) ;
F_7 ( V_1 [ V_19 ] ) ;
F_8 ( V_1 [ V_19 ] ) ;
}
V_30:
F_15 ( V_27 ) ;
F_15 ( V_1 ) ;
return V_24 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 , int V_4 ,
int V_21 , struct V_1 * * V_1 )
{
struct V_5 * V_19 = V_2 -> V_6 -> V_7 ;
struct V_33 * V_34 = F_17 ( V_19 -> V_10 ,
V_3 , V_4 ) ;
int V_23 = V_34 -> V_35 , V_24 = V_34 -> error , V_20 , V_36 = 0 ;
void * V_28 ;
if ( V_24 ) {
ERROR ( L_1 , V_3 ,
V_4 ) ;
goto V_30;
}
for ( V_20 = 0 ; V_20 < V_21 && V_23 > 0 ; V_20 ++ ,
V_23 -= V_32 , V_36 += V_32 ) {
int V_37 = F_18 ( int , V_23 , V_32 ) ;
if ( V_1 [ V_20 ] == NULL )
continue;
V_28 = F_11 ( V_1 [ V_20 ] ) ;
F_19 ( V_28 , V_34 , V_36 , V_37 ) ;
memset ( V_28 + V_37 , 0 , V_32 - V_37 ) ;
F_12 ( V_28 ) ;
F_13 ( V_1 [ V_20 ] ) ;
F_14 ( V_1 [ V_20 ] ) ;
F_7 ( V_1 [ V_20 ] ) ;
if ( V_1 [ V_20 ] != V_2 )
F_8 ( V_1 [ V_20 ] ) ;
}
V_30:
F_20 ( V_34 ) ;
return V_24 ;
}
