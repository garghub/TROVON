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
void F_6 ( struct V_1 * V_2 , struct V_8 * V_9 ,
struct V_10 * V_11 )
{
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
T_1 V_14 = 0 ;
F_7 (window, &bridge->windows, list) {
if ( F_8 ( V_13 -> V_11 , V_11 ) ) {
V_14 = V_13 -> V_14 ;
break;
}
}
V_9 -> V_15 = V_11 -> V_15 - V_14 ;
V_9 -> V_16 = V_11 -> V_16 - V_14 ;
}
static bool F_9 ( struct V_8 * V_17 ,
struct V_8 * V_18 )
{
return V_17 -> V_15 <= V_18 -> V_15 && V_17 -> V_16 >= V_18 -> V_16 ;
}
void F_10 ( struct V_1 * V_2 , struct V_10 * V_11 ,
struct V_8 * V_9 )
{
struct V_4 * V_6 = F_2 ( V_2 ) ;
struct V_12 * V_13 ;
T_1 V_14 = 0 ;
F_7 (window, &bridge->windows, list) {
struct V_8 V_19 ;
if ( F_11 ( V_11 ) != F_11 ( V_13 -> V_11 ) )
continue;
V_19 . V_15 = V_13 -> V_11 -> V_15 - V_13 -> V_14 ;
V_19 . V_16 = V_13 -> V_11 -> V_16 - V_13 -> V_14 ;
if ( F_9 ( & V_19 , V_9 ) ) {
V_14 = V_13 -> V_14 ;
break;
}
}
V_11 -> V_15 = V_9 -> V_15 + V_14 ;
V_11 -> V_16 = V_9 -> V_16 + V_14 ;
}
