static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 ) ;
F_3 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_5 * V_6 = V_2 -> V_5 + V_3 ;
if ( V_6 -> V_7 )
F_4 ( V_6 ) ;
}
}
static void F_5 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 ) {
F_6 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( & V_2 -> V_2 ) ;
V_2 -> V_8 = 0 ;
}
if ( V_2 -> V_9 -> V_10 )
F_9 ( V_2 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_11 ( & V_11 ) ;
F_12 ( & V_2 -> V_12 ) ;
F_13 ( & V_11 ) ;
F_1 ( V_2 ) ;
F_14 ( V_2 ) ;
}
void F_15 ( struct V_13 * V_9 )
{
F_16 ( V_9 ) ;
F_11 ( & V_11 ) ;
F_12 ( & V_9 -> V_14 ) ;
F_17 ( V_9 ) ;
F_13 ( & V_11 ) ;
if ( ! V_9 -> V_8 )
return;
F_18 ( V_9 ) ;
F_8 ( & V_9 -> V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_13 * V_9 = V_2 -> V_15 ;
struct V_1 * V_16 , * V_17 ;
if ( V_9 ) {
F_20 (child, tmp,
&bus->devices, bus_list)
F_19 ( V_16 ) ;
}
F_5 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_13 * V_9 = V_2 -> V_15 ;
struct V_1 * V_16 , * V_17 ;
if ( V_9 ) {
F_22 (child, tmp,
&bus->devices, bus_list)
F_21 ( V_16 ) ;
F_15 ( V_9 ) ;
V_2 -> V_15 = NULL ;
}
F_10 ( V_2 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_19 ( V_2 ) ;
F_21 ( V_2 ) ;
}
