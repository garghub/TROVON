static bool F_1 ( T_1 V_1 , T_1 V_2 , int V_3 )
{
T_1 V_4 , V_5 ;
V_4 = V_1 & ~ ( V_3 - 1 ) ;
V_5 = V_2 & ~ ( V_3 - 1 ) ;
return ( V_4 != V_5 ) ? true : false ;
}
void F_2 ( struct V_6 * V_7 , struct V_8 * V_9 ,
T_1 V_10 , T_1 V_11 )
{
if ( V_9 -> type == V_12 || V_10 == 0 )
return;
V_7 -> V_13 [ V_9 -> type ] ++ ;
if ( V_9 -> type == V_14 ) {
if ( V_11 > V_10 )
V_7 -> V_15 ++ ;
else
V_7 -> V_16 ++ ;
}
if ( F_1 ( V_10 , V_11 , V_17 ) )
V_7 -> V_18 ++ ;
else if ( F_1 ( V_10 , V_11 , V_19 ) )
V_7 -> V_20 ++ ;
}
const char * F_3 ( int type )
{
const char * V_21 [ V_22 ] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6 ,
L_7 ,
L_8 ,
L_9 ,
L_10 ,
L_11
} ;
if ( type >= 0 && type < V_22 )
return V_21 [ type ] ;
return NULL ;
}
void F_4 ( T_2 * V_23 , struct V_6 * V_7 )
{
T_1 V_24 = 0 ;
int V_25 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ )
V_24 += V_7 -> V_13 [ V_25 ] ;
if ( V_24 == 0 )
return;
fprintf ( V_23 , L_12 ) ;
fprintf ( V_23 , L_13 ) ;
fprintf ( V_23 , L_12 ) ;
if ( V_7 -> V_15 > 0 ) {
fprintf ( V_23 , L_14 ,
L_15 ,
100.0 * ( double ) V_7 -> V_15 / ( double ) V_24 ) ;
}
if ( V_7 -> V_16 > 0 ) {
fprintf ( V_23 , L_14 ,
L_16 ,
100.0 * ( double ) V_7 -> V_16 / ( double ) V_24 ) ;
}
if ( V_7 -> V_20 > 0 ) {
fprintf ( V_23 , L_14 ,
L_17 ,
100.0 * ( double ) V_7 -> V_20 / ( double ) V_24 ) ;
}
if ( V_7 -> V_18 > 0 ) {
fprintf ( V_23 , L_14 ,
L_18 ,
100.0 * ( double ) V_7 -> V_18 / ( double ) V_24 ) ;
}
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( V_7 -> V_13 [ V_25 ] > 0 )
fprintf ( V_23 , L_14 ,
F_3 ( V_25 ) ,
100.0 *
( double ) V_7 -> V_13 [ V_25 ] / ( double ) V_24 ) ;
}
}
static int F_5 ( int V_26 , const char * V_27 , char * V_28 , int V_3 )
{
return F_6 ( V_28 , V_3 , L_19 , ( V_26 ) ? L_20 : L_21 , V_27 ) ;
}
int F_7 ( struct V_6 * V_7 , char * V_28 , int V_3 )
{
int V_25 , V_29 = 0 , V_30 = 0 ;
T_1 V_24 = 0 ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ )
V_24 += V_7 -> V_13 [ V_25 ] ;
if ( V_24 == 0 )
return 0 ;
if ( V_7 -> V_15 > 0 )
V_30 += F_5 ( V_29 ++ , L_15 , V_28 + V_30 , V_3 - V_30 ) ;
if ( V_7 -> V_16 > 0 )
V_30 += F_5 ( V_29 ++ , L_16 , V_28 + V_30 , V_3 - V_30 ) ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ ) {
if ( V_25 == V_14 )
continue;
if ( V_7 -> V_13 [ V_25 ] > 0 )
V_30 += F_5 ( V_29 ++ , F_3 ( V_25 ) , V_28 + V_30 , V_3 - V_30 ) ;
}
if ( V_7 -> V_20 > 0 )
V_30 += F_5 ( V_29 ++ , L_17 , V_28 + V_30 , V_3 - V_30 ) ;
if ( V_7 -> V_18 > 0 )
V_30 += F_5 ( V_29 ++ , L_18 , V_28 + V_30 , V_3 - V_30 ) ;
return V_30 ;
}
