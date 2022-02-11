struct V_1 * * F_1 ( const char T_1 * V_2 ,
int V_3 , bool V_4 )
{
struct V_1 * * V_5 ;
int V_6 = 0 ;
int V_7 = 0 ;
V_5 = F_2 ( sizeof( * V_5 ) * V_3 , V_8 ) ;
if ( ! V_5 )
return F_3 ( - V_9 ) ;
F_4 ( & V_10 -> V_11 -> V_12 ) ;
while ( V_6 < V_3 ) {
V_7 = F_5 ( V_10 , V_10 -> V_11 ,
( unsigned long ) V_2 + ( ( unsigned long ) V_6 * V_13 ) ,
V_3 - V_6 , V_4 , 0 , V_5 + V_6 , NULL ) ;
if ( V_7 < 0 )
break;
F_6 ( V_7 == 0 ) ;
V_6 += V_7 ;
}
F_7 ( & V_10 -> V_11 -> V_12 ) ;
if ( V_7 < 0 )
goto V_14;
return V_5 ;
V_14:
F_8 ( V_5 , V_6 , false ) ;
return F_3 ( V_7 ) ;
}
void F_8 ( struct V_1 * * V_5 , int V_3 , bool V_15 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 ; V_16 ++ ) {
if ( V_15 )
F_9 ( V_5 [ V_16 ] ) ;
F_10 ( V_5 [ V_16 ] ) ;
}
F_11 ( V_5 ) ;
}
void F_12 ( struct V_1 * * V_5 , int V_3 )
{
int V_16 ;
for ( V_16 = 0 ; V_16 < V_3 ; V_16 ++ )
F_13 ( V_5 [ V_16 ] , 0 ) ;
F_11 ( V_5 ) ;
}
struct V_1 * * F_14 ( int V_3 , T_2 V_17 )
{
struct V_1 * * V_5 ;
int V_16 ;
V_5 = F_2 ( sizeof( * V_5 ) * V_3 , V_17 ) ;
if ( ! V_5 )
return F_3 ( - V_9 ) ;
for ( V_16 = 0 ; V_16 < V_3 ; V_16 ++ ) {
V_5 [ V_16 ] = F_15 ( V_17 ) ;
if ( V_5 [ V_16 ] == NULL ) {
F_12 ( V_5 , V_16 ) ;
return F_3 ( - V_9 ) ;
}
}
return V_5 ;
}
int F_16 ( struct V_1 * * V_5 ,
const char T_1 * V_2 ,
T_3 V_18 , T_4 V_19 )
{
int V_16 = 0 ;
int V_20 = V_18 & ~ V_21 ;
int V_22 = V_19 ;
int V_23 , V_24 ;
while ( V_22 > 0 ) {
V_23 = F_17 ( int , V_25 - V_20 , V_22 ) ;
V_24 = F_18 ( F_19 ( V_5 [ V_16 ] ) + V_20 , V_2 , V_23 ) ;
if ( V_24 == V_23 )
return - V_26 ;
V_2 += V_23 - V_24 ;
V_22 -= V_23 - V_24 ;
V_20 += V_23 - V_24 ;
if ( V_20 == V_25 ) {
V_20 = 0 ;
V_16 ++ ;
}
}
return V_19 ;
}
int F_20 ( struct V_1 * * V_5 ,
const char * V_2 ,
T_3 V_18 , T_4 V_19 )
{
int V_16 = 0 ;
T_4 V_20 = V_18 & ~ V_21 ;
T_4 V_22 = V_19 ;
T_4 V_23 ;
while ( V_22 > 0 ) {
V_23 = F_17 ( T_4 , V_25 - V_20 , V_22 ) ;
memcpy ( F_19 ( V_5 [ V_16 ] ) + V_20 , V_2 , V_23 ) ;
V_2 += V_23 ;
V_22 -= V_23 ;
V_20 += V_23 ;
if ( V_20 == V_25 ) {
V_20 = 0 ;
V_16 ++ ;
}
}
return V_19 ;
}
int F_21 ( struct V_1 * * V_5 ,
char * V_2 ,
T_3 V_18 , T_4 V_19 )
{
int V_16 = 0 ;
T_4 V_20 = V_18 & ~ V_21 ;
T_4 V_22 = V_19 ;
T_4 V_23 ;
while ( V_22 > 0 ) {
V_23 = F_17 ( T_4 , V_25 - V_20 , V_22 ) ;
memcpy ( V_2 , F_19 ( V_5 [ V_16 ] ) + V_20 , V_23 ) ;
V_2 += V_23 ;
V_22 -= V_23 ;
V_20 += V_23 ;
if ( V_20 == V_25 ) {
V_20 = 0 ;
V_16 ++ ;
}
}
return V_19 ;
}
int F_22 ( struct V_1 * * V_5 ,
char T_1 * V_2 ,
T_3 V_18 , T_4 V_19 )
{
int V_16 = 0 ;
int V_20 = V_18 & ~ V_21 ;
int V_22 = V_19 ;
int V_23 , V_24 ;
while ( V_22 > 0 ) {
V_23 = F_17 ( int , V_22 , V_25 - V_20 ) ;
V_24 = F_23 ( V_2 , F_19 ( V_5 [ V_16 ] ) + V_20 , V_23 ) ;
if ( V_24 == V_23 )
return - V_26 ;
V_2 += V_23 - V_24 ;
V_22 -= V_23 - V_24 ;
if ( V_20 ) {
V_20 += V_23 - V_24 ;
if ( V_20 == V_25 )
V_20 = 0 ;
}
V_16 ++ ;
}
return V_19 ;
}
void F_24 ( int V_18 , int V_19 , struct V_1 * * V_5 )
{
int V_16 = V_18 >> V_27 ;
V_18 &= ~ V_21 ;
F_25 ( L_1 , V_18 , V_19 ) ;
if ( V_18 ) {
int V_28 = F_26 ( ( int ) V_25 , V_18 + V_19 ) ;
F_25 ( L_2 , V_16 , V_5 [ V_16 ] ,
( int ) V_18 ) ;
F_27 ( V_5 [ V_16 ] , V_18 , V_28 ) ;
V_19 -= ( V_28 - V_18 ) ;
V_16 ++ ;
}
while ( V_19 >= V_25 ) {
F_25 ( L_3 , V_16 , V_5 [ V_16 ] , V_19 ) ;
F_27 ( V_5 [ V_16 ] , 0 , V_25 ) ;
V_19 -= V_25 ;
V_16 ++ ;
}
if ( V_19 ) {
F_25 ( L_4 , V_16 , V_5 [ V_16 ] , ( int ) V_19 ) ;
F_27 ( V_5 [ V_16 ] , 0 , V_19 ) ;
}
}
