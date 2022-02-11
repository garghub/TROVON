static int F_1 ( void * V_1 , void * V_2 )
{
struct V_3 * V_4 = V_1 ;
T_1 * V_5 ;
char V_6 [ V_7 ] ;
V_5 = F_2 ( V_4 -> V_8 , V_9 + V_10 ,
V_4 -> V_11 , 0 , V_6 ) ;
if ( V_5 == NULL ) {
F_3 ( V_12 L_1
L_2 , V_6 ) ;
return - V_13 ;
}
V_4 -> V_2 = V_2 ;
V_4 -> V_14 = V_5 ;
return 0 ;
}
static int F_4 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
T_2 V_15 ;
int V_16 ;
if ( V_4 -> V_14 == NULL )
return - V_17 ;
if ( V_4 -> V_18 != NULL ) {
V_16 = F_5 ( V_4 -> V_2 , & V_15 ) ;
if ( V_16 < 0 ) {
F_3 ( V_12 L_3 ) ;
return - V_19 ;
}
V_4 -> V_20 = F_6 ( sizeof( struct V_21 ) ,
V_22 ) ;
if ( V_4 -> V_20 == NULL ) {
F_3 ( V_12 L_4 ) ;
return - V_23 ;
}
V_16 = F_7 ( V_4 -> V_14 ,
(struct V_21 * ) V_4 -> V_20 ,
V_4 -> V_18 , V_4 -> V_24 , V_15 ) ;
if ( V_16 < 0 ) {
F_3 ( V_12 L_5
L_2 , F_8 ( V_4 -> V_14 ) ) ;
goto V_25;
}
V_16 = F_9 ( V_4 -> V_14 , V_4 -> V_20 ) ;
if ( V_16 < 0 ) {
F_3 ( V_12 L_6
L_7 , F_8 ( V_4 -> V_14 ) ) ;
goto V_25;
}
}
return F_10 ( V_4 -> V_14 ) ;
V_25:
F_11 ( V_4 -> V_20 ) ;
return - V_19 ;
}
static void F_12 ( void * V_1 )
{
struct V_3 * V_4 = V_1 ;
if ( V_4 -> V_20 != NULL )
F_13 ( V_4 -> V_20 ) ;
if ( V_4 -> V_14 != NULL )
F_14 ( V_4 -> V_14 ) ;
}
static void F_15 ( T_3 * V_1 , const struct V_26 * V_27 ,
const T_3 * V_28 )
{
int V_29 ;
struct V_30 * V_31 = (struct V_30 * ) V_1 ;
V_29 = V_31 -> V_29 < V_27 -> V_32 ? V_31 -> V_29 : V_27 -> V_32 ;
memcpy ( V_31 -> V_33 , V_28 , V_29 ) ;
V_31 -> V_29 = V_29 ;
}
int F_16 ( int V_34 , void * V_33 , int V_29 , struct V_3 * V_4 )
{
struct V_30 V_31 = ( (struct V_30 )
{ . V_33 = V_33 ,
. V_29 = V_29 } ) ;
int V_35 ;
V_35 = F_17 ( V_4 -> V_14 , 1 , F_15 , ( T_3 * ) & V_31 ) ;
if ( V_35 < 0 ) {
F_3 ( V_12 L_8 ,
F_8 ( V_4 -> V_14 ) ) ;
return - V_19 ;
}
else if ( V_35 == 0 )
return 0 ;
return V_31 . V_29 ;
}
