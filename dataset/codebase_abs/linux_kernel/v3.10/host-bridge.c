static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_1 * V_4 ;
V_4 = V_3 -> V_4 ;
while ( V_4 -> V_5 )
V_4 = V_4 -> V_5 ;
return V_4 ;
}
static struct V_6 * F_2 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return F_3 ( V_4 -> V_7 ) ;
}
void F_4 ( struct V_6 * V_7 ,
void (* F_5)( struct V_6 * ) ,
void * V_8 )
{
V_7 -> F_5 = F_5 ;
V_7 -> V_8 = V_8 ;
}
static bool F_6 ( struct V_9 * V_10 , struct V_9 * V_11 )
{
return V_10 -> V_12 <= V_11 -> V_12 && V_10 -> V_13 >= V_11 -> V_13 ;
}
void F_7 ( struct V_2 * V_3 , struct V_14 * V_15 ,
struct V_9 * V_16 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_17 * V_18 ;
T_1 V_19 = 0 ;
F_8 (window, &bridge->windows, list) {
if ( F_9 ( V_16 ) != F_9 ( V_18 -> V_16 ) )
continue;
if ( F_6 ( V_18 -> V_16 , V_16 ) ) {
V_19 = V_18 -> V_19 ;
break;
}
}
V_15 -> V_12 = V_16 -> V_12 - V_19 ;
V_15 -> V_13 = V_16 -> V_13 - V_19 ;
}
static bool F_10 ( struct V_14 * V_20 ,
struct V_14 * V_21 )
{
return V_20 -> V_12 <= V_21 -> V_12 && V_20 -> V_13 >= V_21 -> V_13 ;
}
void F_11 ( struct V_2 * V_3 , struct V_9 * V_16 ,
struct V_14 * V_15 )
{
struct V_6 * V_7 = F_2 ( V_3 ) ;
struct V_17 * V_18 ;
T_1 V_19 = 0 ;
F_8 (window, &bridge->windows, list) {
struct V_14 V_22 ;
if ( F_9 ( V_16 ) != F_9 ( V_18 -> V_16 ) )
continue;
V_22 . V_12 = V_18 -> V_16 -> V_12 - V_18 -> V_19 ;
V_22 . V_13 = V_18 -> V_16 -> V_13 - V_18 -> V_19 ;
if ( F_10 ( & V_22 , V_15 ) ) {
V_19 = V_18 -> V_19 ;
break;
}
}
V_16 -> V_12 = V_15 -> V_12 + V_19 ;
V_16 -> V_13 = V_15 -> V_13 + V_19 ;
}
