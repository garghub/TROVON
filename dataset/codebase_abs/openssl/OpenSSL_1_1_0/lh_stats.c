void F_1 ( const T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_2 ( F_3 () ) ;
if ( V_3 == NULL )
return;
F_4 ( V_3 , V_2 , V_4 ) ;
F_5 ( V_1 , V_3 ) ;
F_6 ( V_3 ) ;
}
void F_7 ( const T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_2 ( F_3 () ) ;
if ( V_3 == NULL )
return;
F_4 ( V_3 , V_2 , V_4 ) ;
F_8 ( V_1 , V_3 ) ;
F_6 ( V_3 ) ;
}
void F_9 ( const T_1 * V_1 , T_2 * V_2 )
{
T_3 * V_3 ;
V_3 = F_2 ( F_3 () ) ;
if ( V_3 == NULL )
return;
F_4 ( V_3 , V_2 , V_4 ) ;
F_10 ( V_1 , V_3 ) ;
F_6 ( V_3 ) ;
}
void F_5 ( const T_1 * V_1 , T_3 * V_5 )
{
F_11 ( V_5 , L_1 , V_1 -> V_6 ) ;
F_11 ( V_5 , L_2 , V_1 -> V_7 ) ;
F_11 ( V_5 , L_3 , V_1 -> V_8 ) ;
F_11 ( V_5 , L_4 , V_1 -> V_9 ) ;
F_11 ( V_5 , L_5 , V_1 -> V_10 ) ;
F_11 ( V_5 , L_6 , V_1 -> V_11 ) ;
F_11 ( V_5 , L_7 ,
V_1 -> V_12 ) ;
F_11 ( V_5 , L_8 , V_1 -> V_13 ) ;
F_11 ( V_5 , L_9 , V_1 -> V_14 ) ;
F_11 ( V_5 , L_10 , V_1 -> V_15 ) ;
F_11 ( V_5 , L_11 , V_1 -> V_16 ) ;
F_11 ( V_5 , L_12 , V_1 -> V_17 ) ;
F_11 ( V_5 , L_13 , V_1 -> V_18 ) ;
F_11 ( V_5 , L_14 , V_1 -> V_19 ) ;
F_11 ( V_5 , L_15 , V_1 -> V_20 ) ;
F_11 ( V_5 , L_16 , V_1 -> V_21 ) ;
}
void F_8 ( const T_1 * V_1 , T_3 * V_5 )
{
T_4 * V_22 ;
unsigned int V_23 , V_24 ;
for ( V_23 = 0 ; V_23 < V_1 -> V_7 ; V_23 ++ ) {
for ( V_22 = V_1 -> V_25 [ V_23 ] , V_24 = 0 ; V_22 != NULL ; V_22 = V_22 -> V_26 )
V_24 ++ ;
F_11 ( V_5 , L_17 , V_23 , V_24 ) ;
}
}
void F_10 ( const T_1 * V_1 , T_3 * V_5 )
{
T_4 * V_22 ;
unsigned long V_24 ;
unsigned int V_23 ;
unsigned long V_27 = 0 , V_28 = 0 ;
for ( V_23 = 0 ; V_23 < V_1 -> V_7 ; V_23 ++ ) {
for ( V_22 = V_1 -> V_25 [ V_23 ] , V_24 = 0 ; V_22 != NULL ; V_22 = V_22 -> V_26 )
V_24 ++ ;
if ( V_24 != 0 ) {
V_28 ++ ;
V_27 += V_24 ;
}
}
F_11 ( V_5 , L_18 , V_28 , V_1 -> V_7 ) ;
F_11 ( V_5 , L_19 , V_27 ) ;
if ( V_28 == 0 )
return;
F_11 ( V_5 , L_20 ,
( int ) ( V_27 / V_1 -> V_7 ) ,
( int ) ( ( V_27 % V_1 -> V_7 ) * 100 / V_1 -> V_7 ) ,
( int ) ( V_27 / V_28 ) , ( int ) ( ( V_27 % V_28 ) * 100 / V_28 ) ) ;
}
