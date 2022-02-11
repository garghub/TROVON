static struct V_1 * F_1 ( struct V_1 * V_2 )
{
while ( V_2 -> V_3 )
V_2 = V_2 -> V_3 ;
return V_2 ;
}
static struct V_4 * F_2 ( struct V_1 * V_2 )
{
struct V_1 * V_5 = F_1 ( V_2 ) ;
return F_3 ( V_5 -> V_6 ) ;
}
void F_4 ( struct V_4 * V_6 ,
void (* F_5)( struct V_4 * ) ,
void * V_7 )
{
V_6 -> F_5 = F_5 ;
V_6 -> V_7 = V_7 ;
}
static bool F_6 ( struct V_8 * V_9 , struct V_8 * V_10 )
{
return V_9 -> V_11 <= V_10 -> V_11 && V_9 -> V_12 >= V_10 -> V_12 ;
}
void F_7 ( struct V_1 * V_2 , struct V_13 * V_14 ,
struct V_8 * V_15 )
{
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
T_1 V_18 = 0 ;
F_8 (window, &bridge->windows, list) {
if ( F_9 ( V_15 ) != F_9 ( V_17 -> V_15 ) )
continue;
if ( F_6 ( V_17 -> V_15 , V_15 ) ) {
V_18 = V_17 -> V_18 ;
break;
}
}
V_14 -> V_11 = V_15 -> V_11 - V_18 ;
V_14 -> V_12 = V_15 -> V_12 - V_18 ;
}
static bool F_10 ( struct V_13 * V_19 ,
struct V_13 * V_20 )
{
return V_19 -> V_11 <= V_20 -> V_11 && V_19 -> V_12 >= V_20 -> V_12 ;
}
void F_11 ( struct V_1 * V_2 , struct V_8 * V_15 ,
struct V_13 * V_14 )
{
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_16 * V_17 ;
T_1 V_18 = 0 ;
F_8 (window, &bridge->windows, list) {
struct V_13 V_21 ;
if ( F_9 ( V_15 ) != F_9 ( V_17 -> V_15 ) )
continue;
V_21 . V_11 = V_17 -> V_15 -> V_11 - V_17 -> V_18 ;
V_21 . V_12 = V_17 -> V_15 -> V_12 - V_17 -> V_18 ;
if ( F_10 ( & V_21 , V_14 ) ) {
V_18 = V_17 -> V_18 ;
break;
}
}
V_15 -> V_11 = V_14 -> V_11 + V_18 ;
V_15 -> V_12 = V_14 -> V_12 + V_18 ;
}
