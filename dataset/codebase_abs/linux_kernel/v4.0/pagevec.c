struct V_1 * * F_1 ( const void T_1 * V_2 ,
int V_3 , bool V_4 )
{
struct V_1 * * V_5 ;
int V_6 = 0 ;
int V_7 = 0 ;
V_5 = F_2 ( sizeof( * V_5 ) * V_3 , V_8 ) ;
if ( ! V_5 )
return F_3 ( - V_9 ) ;
while ( V_6 < V_3 ) {
V_7 = F_4 ( V_10 , V_10 -> V_11 ,
( unsigned long ) V_2 + ( ( unsigned long ) V_6 * V_12 ) ,
V_3 - V_6 , V_4 , 0 , V_5 + V_6 ) ;
if ( V_7 < 0 )
break;
F_5 ( V_7 == 0 ) ;
V_6 += V_7 ;
}
if ( V_7 < 0 )
goto V_13;
return V_5 ;
V_13:
F_6 ( V_5 , V_6 , false ) ;
return F_3 ( V_7 ) ;
}
void F_6 ( struct V_1 * * V_5 , int V_3 , bool V_14 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_3 ; V_15 ++ ) {
if ( V_14 )
F_7 ( V_5 [ V_15 ] ) ;
F_8 ( V_5 [ V_15 ] ) ;
}
if ( F_9 ( V_5 ) )
F_10 ( V_5 ) ;
else
F_11 ( V_5 ) ;
}
void F_12 ( struct V_1 * * V_5 , int V_3 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_3 ; V_15 ++ )
F_13 ( V_5 [ V_15 ] , 0 ) ;
F_11 ( V_5 ) ;
}
struct V_1 * * F_14 ( int V_3 , T_2 V_16 )
{
struct V_1 * * V_5 ;
int V_15 ;
V_5 = F_2 ( sizeof( * V_5 ) * V_3 , V_16 ) ;
if ( ! V_5 )
return F_3 ( - V_9 ) ;
for ( V_15 = 0 ; V_15 < V_3 ; V_15 ++ ) {
V_5 [ V_15 ] = F_15 ( V_16 ) ;
if ( V_5 [ V_15 ] == NULL ) {
F_12 ( V_5 , V_15 ) ;
return F_3 ( - V_9 ) ;
}
}
return V_5 ;
}
int F_16 ( struct V_1 * * V_5 ,
const void T_1 * V_2 ,
T_3 V_17 , T_4 V_18 )
{
int V_15 = 0 ;
int V_19 = V_17 & ~ V_20 ;
int V_21 = V_18 ;
int V_22 , V_23 ;
while ( V_21 > 0 ) {
V_22 = F_17 ( int , V_24 - V_19 , V_21 ) ;
V_23 = F_18 ( F_19 ( V_5 [ V_15 ] ) + V_19 , V_2 , V_22 ) ;
if ( V_23 == V_22 )
return - V_25 ;
V_2 += V_22 - V_23 ;
V_21 -= V_22 - V_23 ;
V_19 += V_22 - V_23 ;
if ( V_19 == V_24 ) {
V_19 = 0 ;
V_15 ++ ;
}
}
return V_18 ;
}
void F_20 ( struct V_1 * * V_5 ,
const void * V_2 ,
T_3 V_17 , T_4 V_18 )
{
int V_15 = 0 ;
T_4 V_19 = V_17 & ~ V_20 ;
T_4 V_21 = V_18 ;
while ( V_21 > 0 ) {
T_4 V_22 = F_17 ( T_4 , V_24 - V_19 , V_21 ) ;
memcpy ( F_19 ( V_5 [ V_15 ] ) + V_19 , V_2 , V_22 ) ;
V_2 += V_22 ;
V_21 -= V_22 ;
V_19 += V_22 ;
if ( V_19 == V_24 ) {
V_19 = 0 ;
V_15 ++ ;
}
}
}
void F_21 ( struct V_1 * * V_5 ,
void * V_2 ,
T_3 V_17 , T_4 V_18 )
{
int V_15 = 0 ;
T_4 V_19 = V_17 & ~ V_20 ;
T_4 V_21 = V_18 ;
while ( V_21 > 0 ) {
T_4 V_22 = F_17 ( T_4 , V_24 - V_19 , V_21 ) ;
memcpy ( V_2 , F_19 ( V_5 [ V_15 ] ) + V_19 , V_22 ) ;
V_2 += V_22 ;
V_21 -= V_22 ;
V_19 += V_22 ;
if ( V_19 == V_24 ) {
V_19 = 0 ;
V_15 ++ ;
}
}
}
void F_22 ( int V_17 , int V_18 , struct V_1 * * V_5 )
{
int V_15 = V_17 >> V_26 ;
V_17 &= ~ V_20 ;
F_23 ( L_1 , V_17 , V_18 ) ;
if ( V_17 ) {
int V_27 = F_24 ( ( int ) V_24 , V_17 + V_18 ) ;
F_23 ( L_2 , V_15 , V_5 [ V_15 ] ,
( int ) V_17 ) ;
F_25 ( V_5 [ V_15 ] , V_17 , V_27 ) ;
V_18 -= ( V_27 - V_17 ) ;
V_15 ++ ;
}
while ( V_18 >= V_24 ) {
F_23 ( L_3 , V_15 , V_5 [ V_15 ] , V_18 ) ;
F_25 ( V_5 [ V_15 ] , 0 , V_24 ) ;
V_18 -= V_24 ;
V_15 ++ ;
}
if ( V_18 ) {
F_23 ( L_4 , V_15 , V_5 [ V_15 ] , ( int ) V_18 ) ;
F_25 ( V_5 [ V_15 ] , 0 , V_18 ) ;
}
}
