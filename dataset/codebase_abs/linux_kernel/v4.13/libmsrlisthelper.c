static int F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
unsigned int V_4 )
{
T_1 * V_5 = V_3 ;
while ( V_5 < V_3 + V_4 ) {
struct V_6 V_7 = {
. V_8 = V_2 -> V_8 ,
. V_9 = 0 ,
} ;
int V_10 ;
V_7 . V_11 = * V_5 ++ ;
V_7 . V_12 = V_5 ;
V_5 += V_7 . V_11 ;
if ( V_5 > V_3 + V_4 )
return - V_13 ;
V_10 = F_2 ( V_2 -> V_14 , & V_7 , 1 ) ;
if ( V_10 < 0 ) {
F_3 ( & V_2 -> V_15 , L_1 , V_10 ) ;
return V_10 ;
}
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_1 * V_16 ,
unsigned int V_4 )
{
T_1 * V_17 = V_16 + V_4 ;
struct V_18 * V_19 =
(struct V_18 * ) V_16 ;
unsigned int V_20 = 0 ;
do {
if ( ( T_1 * ) V_19 + sizeof( * V_19 ) > V_17 )
return - V_13 ;
if ( ( T_1 * ) V_19 + V_19 -> V_21 +
V_19 -> V_22 > V_17 )
return - V_13 ;
V_20 ++ ;
if ( V_19 -> V_22 && ( V_19 -> V_9 & 1 ) ) {
int V_10 ;
F_5 ( & V_2 -> V_15 ,
L_2 ,
V_20 , V_19 -> V_22 ) ;
V_10 = F_1 ( V_2 ,
V_16 + V_19 -> V_21 ,
V_19 -> V_22 ) ;
if ( V_10 )
return V_10 ;
}
V_19 = (struct V_18 * ) ( V_16 +
V_19 -> V_23 ) ;
} while ( V_19 -> V_23 );
return 0 ;
}
int F_6 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
struct V_26 * V_19 ;
struct V_27 * V_28 ;
if ( ! V_25 ) {
F_7 ( & V_2 -> V_15 , L_3 ) ;
return - V_13 ;
}
if ( sizeof( * V_19 ) > V_25 -> V_4 )
return - V_13 ;
V_19 = (struct V_26 * ) V_25 -> V_29 ;
if ( memcmp ( & V_19 -> V_30 , L_4 , 4 ) )
return - V_13 ;
if ( V_19 -> V_4 != V_25 -> V_4 )
return - V_13 ;
if ( sizeof( * V_19 ) + sizeof( * V_28 ) > V_25 -> V_4 )
return - V_13 ;
V_28 = (struct V_27 * ) ( V_19 + 1 ) ;
if ( V_28 -> V_31 != V_32 )
return - V_13 ;
if ( ! V_28 -> V_4 )
return 0 ;
return F_4 ( V_2 , ( T_1 * ) ( V_28 + 1 ) , V_28 -> V_4 ) ;
}
int F_8 ( struct V_1 * V_2 , char * V_33 ,
const struct V_24 * * V_25 )
{
int V_10 = F_9 ( V_25 , V_33 , & V_2 -> V_15 ) ;
if ( V_10 ) {
F_3 ( & V_2 -> V_15 ,
L_5 ,
V_10 , V_33 ) ;
return V_10 ;
}
F_5 ( & V_2 -> V_15 , L_6 ,
( unsigned long ) ( * V_25 ) -> V_4 ) ;
return 0 ;
}
void F_10 ( struct V_1 * V_2 , const struct V_24 * V_25 )
{
F_11 ( V_25 ) ;
}
static int F_12 ( void )
{
return 0 ;
}
static void F_13 ( void )
{
}
