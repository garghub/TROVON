void F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 )
return;
V_2 -> V_5 = 1024 * 1024 ;
V_2 -> V_6 = 1024 * 1024 ;
V_2 -> V_4 = F_2 ( V_2 -> V_7 ,
V_2 -> V_5 ,
& V_3 , V_8 ) ;
if ( V_2 -> V_4 )
V_2 -> V_9 = V_3 ;
V_2 -> V_10 = V_2 -> V_5 /
V_11 ;
V_2 -> V_12 = F_3 ( V_2 -> V_10 ,
sizeof( V_13 ) ,
V_8 ) ;
F_4 ( & V_2 -> V_14 ) ;
V_2 -> V_15 = F_2 ( V_2 -> V_7 ,
V_2 -> V_6 ,
& V_3 , V_8 ) ;
if ( V_2 -> V_15 )
V_2 -> V_16 = V_3 ;
}
void F_5 ( struct V_1 * V_2 )
{
T_1 V_3 ;
if ( V_2 -> V_4 ) {
V_3 = V_2 -> V_9 ;
F_6 ( V_2 -> V_7 , V_2 -> V_5 ,
V_2 -> V_4 , V_3 ) ;
}
if ( V_2 -> V_15 ) {
V_3 = V_2 -> V_16 ;
F_6 ( V_2 -> V_7 , V_2 -> V_6 ,
V_2 -> V_15 , V_3 ) ;
}
F_7 ( V_2 -> V_12 ) ;
V_2 -> V_4 = NULL ;
V_2 -> V_15 = NULL ;
V_2 -> V_12 = NULL ;
}
void * F_8 ( struct V_1 * V_2 ,
T_2 V_17 )
{
unsigned long V_18 ;
int V_19 , V_20 , free ;
int V_21 = ( V_17 / V_11 )
+ 1 * ( V_17 % V_11 != 0 ) ;
F_9 ( & V_2 -> V_14 , V_18 ) ;
for ( V_19 = 0 ; V_19 <= ( V_2 -> V_10 - V_21 ) ; V_19 ++ ) {
free = 1 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
if ( V_2 -> V_12 [ V_19 + V_20 ] ) {
free = 0 ;
V_19 += V_20 ;
break;
}
if ( free ) {
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ )
V_2 -> V_12 [ V_19 + V_20 ] = 1 ;
F_10 ( & V_2 -> V_14 , V_18 ) ;
return ( V_19 * V_11 ) +
( unsigned char * ) V_2 -> V_4 ;
}
}
F_10 ( & V_2 -> V_14 , V_18 ) ;
F_11 ( V_2 -> V_7 , L_1 ) ;
return NULL ;
}
void F_12 ( struct V_1 * V_2 ,
void * V_22 ,
V_13 V_17 )
{
unsigned long V_18 ;
int V_23 = ( V_17 / V_11 )
+ 1 * ( V_17 % V_11 != 0 ) ;
int V_19 , V_20 ;
if ( ( V_22 - V_2 -> V_4 ) % V_11 ) {
F_11 ( V_2 -> V_7 , L_2 ) ;
return;
}
V_19 = ( V_22 - V_2 -> V_4 ) / V_11 ;
F_9 ( & V_2 -> V_14 , V_18 ) ;
for ( V_20 = 0 ; V_20 < V_23 ; V_20 ++ ) {
if ( ( V_19 + V_20 ) >= V_2 -> V_10 ||
! V_2 -> V_12 [ V_19 + V_20 ] ) {
F_10 ( & V_2 -> V_14 , V_18 ) ;
F_11 ( V_2 -> V_7 , L_2 ) ;
return;
}
V_2 -> V_12 [ V_19 + V_20 ] = 0 ;
}
F_10 ( & V_2 -> V_14 , V_18 ) ;
}
