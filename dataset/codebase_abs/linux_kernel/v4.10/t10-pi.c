static T_1 F_1 ( void * V_1 , unsigned int V_2 )
{
return F_2 ( F_3 ( V_1 , V_2 ) ) ;
}
static T_1 F_4 ( void * V_1 , unsigned int V_2 )
{
return ( V_3 T_1 ) F_5 ( V_1 , V_2 ) ;
}
static int F_6 ( struct V_4 * V_5 , T_2 * V_6 ,
unsigned int type )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 += V_5 -> V_9 ) {
struct V_10 * V_11 = V_5 -> V_12 ;
V_11 -> V_13 = V_6 ( V_5 -> V_14 , V_5 -> V_9 ) ;
V_11 -> V_15 = 0 ;
if ( type == 1 )
V_11 -> V_16 = F_7 ( F_8 ( V_5 -> V_17 ) ) ;
else
V_11 -> V_16 = 0 ;
V_5 -> V_14 += V_5 -> V_9 ;
V_5 -> V_12 += sizeof( struct V_10 ) ;
V_5 -> V_17 ++ ;
}
return 0 ;
}
static int F_9 ( struct V_4 * V_5 , T_2 * V_6 ,
unsigned int type )
{
unsigned int V_7 ;
for ( V_7 = 0 ; V_7 < V_5 -> V_8 ; V_7 += V_5 -> V_9 ) {
struct V_10 * V_11 = V_5 -> V_12 ;
T_1 V_18 ;
switch ( type ) {
case 1 :
case 2 :
if ( V_11 -> V_15 == V_19 )
goto V_20;
if ( F_10 ( V_11 -> V_16 ) !=
F_8 ( V_5 -> V_17 ) ) {
F_11 ( L_1 \
L_2 , V_5 -> V_21 ,
( unsigned long long )
V_5 -> V_17 , F_10 ( V_11 -> V_16 ) ) ;
return - V_22 ;
}
break;
case 3 :
if ( V_11 -> V_15 == V_19 &&
V_11 -> V_16 == V_23 )
goto V_20;
break;
}
V_18 = V_6 ( V_5 -> V_14 , V_5 -> V_9 ) ;
if ( V_11 -> V_13 != V_18 ) {
F_11 ( L_3 \
L_4 , V_5 -> V_21 ,
( unsigned long long ) V_5 -> V_17 ,
F_12 ( V_11 -> V_13 ) , F_12 ( V_18 ) ) ;
return - V_22 ;
}
V_20:
V_5 -> V_14 += V_5 -> V_9 ;
V_5 -> V_12 += sizeof( struct V_10 ) ;
V_5 -> V_17 ++ ;
}
return 0 ;
}
static int F_13 ( struct V_4 * V_5 )
{
return F_6 ( V_5 , F_1 , 1 ) ;
}
static int F_14 ( struct V_4 * V_5 )
{
return F_6 ( V_5 , F_4 , 1 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , F_1 , 1 ) ;
}
static int F_16 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , F_4 , 1 ) ;
}
static int F_17 ( struct V_4 * V_5 )
{
return F_6 ( V_5 , F_1 , 3 ) ;
}
static int F_18 ( struct V_4 * V_5 )
{
return F_6 ( V_5 , F_4 , 3 ) ;
}
static int F_19 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , F_1 , 3 ) ;
}
static int F_20 ( struct V_4 * V_5 )
{
return F_9 ( V_5 , F_4 , 3 ) ;
}
