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
V_7 = F_4 (
( unsigned long ) V_2 + ( ( unsigned long ) V_6 * V_10 ) ,
V_3 - V_6 , V_5 + V_6 , V_4 ? V_11 : 0 ) ;
if ( V_7 < 0 )
break;
F_5 ( V_7 == 0 ) ;
V_6 += V_7 ;
}
if ( V_7 < 0 )
goto V_12;
return V_5 ;
V_12:
F_6 ( V_5 , V_6 , false ) ;
return F_3 ( V_7 ) ;
}
void F_6 ( struct V_1 * * V_5 , int V_3 , bool V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_3 ; V_14 ++ ) {
if ( V_13 )
F_7 ( V_5 [ V_14 ] ) ;
F_8 ( V_5 [ V_14 ] ) ;
}
F_9 ( V_5 ) ;
}
void F_10 ( struct V_1 * * V_5 , int V_3 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < V_3 ; V_14 ++ )
F_11 ( V_5 [ V_14 ] , 0 ) ;
F_12 ( V_5 ) ;
}
struct V_1 * * F_13 ( int V_3 , T_2 V_15 )
{
struct V_1 * * V_5 ;
int V_14 ;
V_5 = F_2 ( sizeof( * V_5 ) * V_3 , V_15 ) ;
if ( ! V_5 )
return F_3 ( - V_9 ) ;
for ( V_14 = 0 ; V_14 < V_3 ; V_14 ++ ) {
V_5 [ V_14 ] = F_14 ( V_15 ) ;
if ( V_5 [ V_14 ] == NULL ) {
F_10 ( V_5 , V_14 ) ;
return F_3 ( - V_9 ) ;
}
}
return V_5 ;
}
int F_15 ( struct V_1 * * V_5 ,
const void T_1 * V_2 ,
T_3 V_16 , T_4 V_17 )
{
int V_14 = 0 ;
int V_18 = V_16 & ~ V_19 ;
int V_20 = V_17 ;
int V_21 , V_22 ;
while ( V_20 > 0 ) {
V_21 = F_16 ( int , V_10 - V_18 , V_20 ) ;
V_22 = F_17 ( F_18 ( V_5 [ V_14 ] ) + V_18 , V_2 , V_21 ) ;
if ( V_22 == V_21 )
return - V_23 ;
V_2 += V_21 - V_22 ;
V_20 -= V_21 - V_22 ;
V_18 += V_21 - V_22 ;
if ( V_18 == V_10 ) {
V_18 = 0 ;
V_14 ++ ;
}
}
return V_17 ;
}
void F_19 ( struct V_1 * * V_5 ,
const void * V_2 ,
T_3 V_16 , T_4 V_17 )
{
int V_14 = 0 ;
T_4 V_18 = V_16 & ~ V_19 ;
T_4 V_20 = V_17 ;
while ( V_20 > 0 ) {
T_4 V_21 = F_16 ( T_4 , V_10 - V_18 , V_20 ) ;
memcpy ( F_18 ( V_5 [ V_14 ] ) + V_18 , V_2 , V_21 ) ;
V_2 += V_21 ;
V_20 -= V_21 ;
V_18 += V_21 ;
if ( V_18 == V_10 ) {
V_18 = 0 ;
V_14 ++ ;
}
}
}
void F_20 ( struct V_1 * * V_5 ,
void * V_2 ,
T_3 V_16 , T_4 V_17 )
{
int V_14 = 0 ;
T_4 V_18 = V_16 & ~ V_19 ;
T_4 V_20 = V_17 ;
while ( V_20 > 0 ) {
T_4 V_21 = F_16 ( T_4 , V_10 - V_18 , V_20 ) ;
memcpy ( V_2 , F_18 ( V_5 [ V_14 ] ) + V_18 , V_21 ) ;
V_2 += V_21 ;
V_20 -= V_21 ;
V_18 += V_21 ;
if ( V_18 == V_10 ) {
V_18 = 0 ;
V_14 ++ ;
}
}
}
void F_21 ( int V_16 , int V_17 , struct V_1 * * V_5 )
{
int V_14 = V_16 >> V_24 ;
V_16 &= ~ V_19 ;
F_22 ( L_1 , V_16 , V_17 ) ;
if ( V_16 ) {
int V_25 = F_23 ( ( int ) V_10 , V_16 + V_17 ) ;
F_22 ( L_2 , V_14 , V_5 [ V_14 ] ,
( int ) V_16 ) ;
F_24 ( V_5 [ V_14 ] , V_16 , V_25 ) ;
V_17 -= ( V_25 - V_16 ) ;
V_14 ++ ;
}
while ( V_17 >= V_10 ) {
F_22 ( L_3 , V_14 , V_5 [ V_14 ] , V_17 ) ;
F_24 ( V_5 [ V_14 ] , 0 , V_10 ) ;
V_17 -= V_10 ;
V_14 ++ ;
}
if ( V_17 ) {
F_22 ( L_4 , V_14 , V_5 [ V_14 ] , ( int ) V_17 ) ;
F_24 ( V_5 [ V_14 ] , 0 , V_17 ) ;
}
}
