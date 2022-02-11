void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = F_3 () ;
F_4 ( & V_2 -> V_6 ) ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_9 ;
F_6 ( & V_2 -> V_6 ) ;
F_7 (marker, next, &queue->head, head) {
F_8 ( V_8 ) ;
}
F_9 ( & V_2 -> V_6 ) ;
}
int F_10 ( struct V_1 * V_2 ,
T_1 V_10 )
{
struct V_7 * V_8 = F_11 ( sizeof( * V_8 ) , V_11 ) ;
if ( F_12 ( ! V_8 ) )
return - V_12 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_13 = F_3 () ;
F_6 ( & V_2 -> V_6 ) ;
F_13 ( & V_8 -> V_3 , & V_2 -> V_3 ) ;
F_9 ( & V_2 -> V_6 ) ;
return 0 ;
}
int F_14 ( struct V_1 * V_2 ,
T_1 V_14 )
{
struct V_7 * V_8 , * V_9 ;
bool V_15 = false ;
T_2 V_16 ;
F_6 ( & V_2 -> V_6 ) ;
V_16 = F_3 () ;
if ( F_15 ( & V_2 -> V_3 ) ) {
V_2 -> V_4 = 0 ;
V_2 -> V_5 = V_16 ;
V_15 = true ;
goto V_17;
}
F_7 (marker, next, &queue->head, head) {
if ( V_14 - V_8 -> V_10 > ( 1 << 30 ) )
continue;
V_2 -> V_4 = V_16 - V_8 -> V_13 ;
V_2 -> V_5 = V_16 ;
V_15 = true ;
F_16 ( & V_8 -> V_3 ) ;
F_8 ( V_8 ) ;
}
V_17:
F_9 ( & V_2 -> V_6 ) ;
return ( V_15 ) ? 0 : - V_18 ;
}
static T_2 F_17 ( struct V_1 * V_2 )
{
T_2 V_16 ;
F_6 ( & V_2 -> V_6 ) ;
V_16 = F_3 () ;
V_2 -> V_4 += V_16 - V_2 -> V_5 ;
V_2 -> V_5 = V_16 ;
F_9 ( & V_2 -> V_6 ) ;
return V_2 -> V_4 ;
}
static bool F_18 ( struct V_1 * V_2 ,
T_1 V_19 )
{
T_2 V_20 = ( T_2 ) V_19 * V_21 ;
return F_17 ( V_2 ) <= V_20 ;
}
int F_19 ( struct V_22 * V_23 ,
struct V_1 * V_2 , T_1 V_19 )
{
struct V_7 * V_8 ;
T_1 V_10 ;
int V_24 ;
while ( ! F_18 ( V_2 , V_19 ) ) {
F_6 ( & V_2 -> V_6 ) ;
if ( F_15 ( & V_2 -> V_3 ) )
V_10 = F_20 ( & V_23 -> V_25 ) ;
else {
V_8 = F_21 ( & V_2 -> V_3 ,
struct V_7 , V_3 ) ;
V_10 = V_8 -> V_10 ;
}
F_9 ( & V_2 -> V_6 ) ;
V_24 = F_22 ( V_23 , false , V_10 , true ,
3 * V_26 ) ;
if ( F_12 ( V_24 != 0 ) )
return V_24 ;
( void ) F_14 ( V_2 , V_10 ) ;
}
return 0 ;
}
