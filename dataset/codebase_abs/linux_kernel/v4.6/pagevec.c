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
V_3 - V_6 , V_4 , 0 , V_5 + V_6 ) ;
if ( V_7 < 0 )
break;
F_5 ( V_7 == 0 ) ;
V_6 += V_7 ;
}
if ( V_7 < 0 )
goto V_11;
return V_5 ;
V_11:
F_6 ( V_5 , V_6 , false ) ;
return F_3 ( V_7 ) ;
}
void F_6 ( struct V_1 * * V_5 , int V_3 , bool V_12 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ ) {
if ( V_12 )
F_7 ( V_5 [ V_13 ] ) ;
F_8 ( V_5 [ V_13 ] ) ;
}
F_9 ( V_5 ) ;
}
void F_10 ( struct V_1 * * V_5 , int V_3 )
{
int V_13 ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ )
F_11 ( V_5 [ V_13 ] , 0 ) ;
F_12 ( V_5 ) ;
}
struct V_1 * * F_13 ( int V_3 , T_2 V_14 )
{
struct V_1 * * V_5 ;
int V_13 ;
V_5 = F_2 ( sizeof( * V_5 ) * V_3 , V_14 ) ;
if ( ! V_5 )
return F_3 ( - V_9 ) ;
for ( V_13 = 0 ; V_13 < V_3 ; V_13 ++ ) {
V_5 [ V_13 ] = F_14 ( V_14 ) ;
if ( V_5 [ V_13 ] == NULL ) {
F_10 ( V_5 , V_13 ) ;
return F_3 ( - V_9 ) ;
}
}
return V_5 ;
}
int F_15 ( struct V_1 * * V_5 ,
const void T_1 * V_2 ,
T_3 V_15 , T_4 V_16 )
{
int V_13 = 0 ;
int V_17 = V_15 & ~ V_18 ;
int V_19 = V_16 ;
int V_20 , V_21 ;
while ( V_19 > 0 ) {
V_20 = F_16 ( int , V_10 - V_17 , V_19 ) ;
V_21 = F_17 ( F_18 ( V_5 [ V_13 ] ) + V_17 , V_2 , V_20 ) ;
if ( V_21 == V_20 )
return - V_22 ;
V_2 += V_20 - V_21 ;
V_19 -= V_20 - V_21 ;
V_17 += V_20 - V_21 ;
if ( V_17 == V_10 ) {
V_17 = 0 ;
V_13 ++ ;
}
}
return V_16 ;
}
void F_19 ( struct V_1 * * V_5 ,
const void * V_2 ,
T_3 V_15 , T_4 V_16 )
{
int V_13 = 0 ;
T_4 V_17 = V_15 & ~ V_18 ;
T_4 V_19 = V_16 ;
while ( V_19 > 0 ) {
T_4 V_20 = F_16 ( T_4 , V_10 - V_17 , V_19 ) ;
memcpy ( F_18 ( V_5 [ V_13 ] ) + V_17 , V_2 , V_20 ) ;
V_2 += V_20 ;
V_19 -= V_20 ;
V_17 += V_20 ;
if ( V_17 == V_10 ) {
V_17 = 0 ;
V_13 ++ ;
}
}
}
void F_20 ( struct V_1 * * V_5 ,
void * V_2 ,
T_3 V_15 , T_4 V_16 )
{
int V_13 = 0 ;
T_4 V_17 = V_15 & ~ V_18 ;
T_4 V_19 = V_16 ;
while ( V_19 > 0 ) {
T_4 V_20 = F_16 ( T_4 , V_10 - V_17 , V_19 ) ;
memcpy ( V_2 , F_18 ( V_5 [ V_13 ] ) + V_17 , V_20 ) ;
V_2 += V_20 ;
V_19 -= V_20 ;
V_17 += V_20 ;
if ( V_17 == V_10 ) {
V_17 = 0 ;
V_13 ++ ;
}
}
}
void F_21 ( int V_15 , int V_16 , struct V_1 * * V_5 )
{
int V_13 = V_15 >> V_23 ;
V_15 &= ~ V_18 ;
F_22 ( L_1 , V_15 , V_16 ) ;
if ( V_15 ) {
int V_24 = F_23 ( ( int ) V_10 , V_15 + V_16 ) ;
F_22 ( L_2 , V_13 , V_5 [ V_13 ] ,
( int ) V_15 ) ;
F_24 ( V_5 [ V_13 ] , V_15 , V_24 ) ;
V_16 -= ( V_24 - V_15 ) ;
V_13 ++ ;
}
while ( V_16 >= V_10 ) {
F_22 ( L_3 , V_13 , V_5 [ V_13 ] , V_16 ) ;
F_24 ( V_5 [ V_13 ] , 0 , V_10 ) ;
V_16 -= V_10 ;
V_13 ++ ;
}
if ( V_16 ) {
F_22 ( L_4 , V_13 , V_5 [ V_13 ] , ( int ) V_16 ) ;
F_24 ( V_5 [ V_13 ] , 0 , V_16 ) ;
}
}
