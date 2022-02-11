static struct V_1 * F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 )
V_2 = V_2 -> V_3 ;
return V_2 ;
}
struct V_4 * F_2 ( struct V_1 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
return F_3 ( V_5 -> V_6 ) ;
}
struct V_7 * F_4 ( struct V_8 * V_9 )
{
struct V_1 * V_5 = F_1 ( V_9 -> V_2 ) ;
struct V_7 * V_6 = V_5 -> V_6 ;
F_5 ( & V_6 -> V_10 ) ;
return V_6 ;
}
void F_6 ( struct V_7 * V_9 )
{
F_7 ( & V_9 -> V_10 ) ;
}
void F_8 ( struct V_4 * V_6 ,
void (* F_9)( struct V_4 * ) ,
void * V_11 )
{
V_6 -> F_9 = F_9 ;
V_6 -> V_11 = V_11 ;
}
void F_10 ( struct V_1 * V_2 , struct V_12 * V_13 ,
struct V_14 * V_15 )
{
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
T_1 V_18 = 0 ;
F_11 (window, &bridge->windows) {
if ( F_12 ( V_17 -> V_15 , V_15 ) ) {
V_18 = V_17 -> V_18 ;
break;
}
}
V_13 -> V_19 = V_15 -> V_19 - V_18 ;
V_13 -> V_20 = V_15 -> V_20 - V_18 ;
}
static bool F_13 ( struct V_12 * V_21 ,
struct V_12 * V_22 )
{
return V_21 -> V_19 <= V_22 -> V_19 && V_21 -> V_20 >= V_22 -> V_20 ;
}
void F_14 ( struct V_1 * V_2 , struct V_14 * V_15 ,
struct V_12 * V_13 )
{
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
T_1 V_18 = 0 ;
F_11 (window, &bridge->windows) {
struct V_12 V_23 ;
if ( F_15 ( V_15 ) != F_15 ( V_17 -> V_15 ) )
continue;
V_23 . V_19 = V_17 -> V_15 -> V_19 - V_17 -> V_18 ;
V_23 . V_20 = V_17 -> V_15 -> V_20 - V_17 -> V_18 ;
if ( F_13 ( & V_23 , V_13 ) ) {
V_18 = V_17 -> V_18 ;
break;
}
}
V_15 -> V_19 = V_13 -> V_19 + V_18 ;
V_15 -> V_20 = V_13 -> V_20 + V_18 ;
}
