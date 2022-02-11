void F_1 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_3 ) ;
V_2 -> V_4 = F_3 ( 0 ) ;
F_4 ( & V_2 -> V_5 ) ;
F_5 ( & V_2 -> V_6 ) ;
}
void F_6 ( struct V_1 * V_2 )
{
struct V_7 * V_8 , * V_9 ;
F_7 ( & V_2 -> V_6 ) ;
F_8 (marker, next, &queue->head, head) {
F_9 ( V_8 ) ;
}
F_10 ( & V_2 -> V_6 ) ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_10 )
{
struct V_7 * V_8 = F_12 ( sizeof( * V_8 ) , V_11 ) ;
if ( F_13 ( ! V_8 ) )
return - V_12 ;
V_8 -> V_10 = V_10 ;
F_4 ( & V_8 -> V_13 ) ;
F_7 ( & V_2 -> V_6 ) ;
F_14 ( & V_8 -> V_3 , & V_2 -> V_3 ) ;
F_10 ( & V_2 -> V_6 ) ;
return 0 ;
}
int F_15 ( struct V_1 * V_2 ,
T_1 V_14 )
{
struct V_7 * V_8 , * V_9 ;
struct V_15 V_16 ;
bool V_17 = false ;
F_7 ( & V_2 -> V_6 ) ;
F_4 ( & V_16 ) ;
if ( F_16 ( & V_2 -> V_3 ) ) {
V_2 -> V_4 = F_3 ( 0 ) ;
V_2 -> V_5 = V_16 ;
V_17 = true ;
goto V_18;
}
F_8 (marker, next, &queue->head, head) {
if ( V_14 - V_8 -> V_10 > ( 1 << 30 ) )
continue;
V_2 -> V_4 = F_17 ( V_16 , V_8 -> V_13 ) ;
V_2 -> V_5 = V_16 ;
V_17 = true ;
F_18 ( & V_8 -> V_3 ) ;
F_9 ( V_8 ) ;
}
V_18:
F_10 ( & V_2 -> V_6 ) ;
return ( V_17 ) ? 0 : - V_19 ;
}
static struct V_15 F_19 ( struct V_15 V_20 ,
struct V_15 V_21 )
{
V_20 . V_22 += V_21 . V_22 ;
V_20 . V_23 += V_21 . V_23 ;
if ( V_20 . V_23 >= 1000000000L ) {
V_20 . V_22 += 1 ;
V_20 . V_23 -= 1000000000L ;
}
return V_20 ;
}
static struct V_15 F_20 ( struct V_1 * V_2 )
{
struct V_15 V_16 ;
F_7 ( & V_2 -> V_6 ) ;
F_4 ( & V_16 ) ;
V_2 -> V_4 = F_19 ( V_2 -> V_4 ,
F_17 ( V_16 , V_2 -> V_5 ) ) ;
V_2 -> V_5 = V_16 ;
F_10 ( & V_2 -> V_6 ) ;
return V_2 -> V_4 ;
}
static bool F_21 ( struct V_1 * V_2 ,
T_1 V_24 )
{
struct V_15 V_4 , V_25 ;
V_25 = F_3 ( ( V_26 ) V_24 * 1000 ) ;
V_4 = F_20 ( V_2 ) ;
return ( F_22 ( & V_4 , & V_25 ) < 1 ) ;
}
int F_23 ( struct V_27 * V_28 ,
struct V_1 * V_2 , T_1 V_24 )
{
struct V_7 * V_8 ;
T_1 V_10 ;
int V_29 ;
while ( ! F_21 ( V_2 , V_24 ) ) {
F_7 ( & V_2 -> V_6 ) ;
if ( F_16 ( & V_2 -> V_3 ) )
V_10 = F_24 ( & V_28 -> V_30 ) ;
else {
V_8 = F_25 ( & V_2 -> V_3 ,
struct V_7 , V_3 ) ;
V_10 = V_8 -> V_10 ;
}
F_10 ( & V_2 -> V_6 ) ;
V_29 = F_26 ( V_28 , false , V_10 , true ,
3 * V_31 ) ;
if ( F_13 ( V_29 != 0 ) )
return V_29 ;
( void ) F_15 ( V_2 , V_10 ) ;
}
return 0 ;
}
