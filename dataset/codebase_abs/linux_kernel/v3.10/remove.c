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
F_6 ( V_2 , false ) ;
if ( V_2 -> V_8 ) {
F_7 ( V_2 ) ;
F_8 ( V_2 ) ;
F_9 ( & V_2 -> V_2 ) ;
V_2 -> V_8 = 0 ;
}
if ( V_2 -> V_9 -> V_10 )
F_10 ( V_2 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_12 ( & V_11 ) ;
F_13 ( & V_2 -> V_12 ) ;
F_14 ( & V_11 ) ;
F_1 ( V_2 ) ;
F_15 ( & V_2 -> V_2 ) ;
}
void F_16 ( struct V_13 * V_9 )
{
F_17 ( V_9 ) ;
F_12 ( & V_11 ) ;
F_13 ( & V_9 -> V_14 ) ;
F_18 ( V_9 ) ;
F_14 ( & V_11 ) ;
F_19 ( V_9 ) ;
F_20 ( V_9 ) ;
F_21 ( & V_9 -> V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_13 * V_9 = V_2 -> V_15 ;
struct V_1 * V_16 , * V_17 ;
if ( V_9 ) {
F_23 (child, tmp,
&bus->devices, bus_list)
F_22 ( V_16 ) ;
}
F_5 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_13 * V_9 = V_2 -> V_15 ;
struct V_1 * V_16 , * V_17 ;
if ( V_9 ) {
F_25 (child, tmp,
&bus->devices, bus_list)
F_24 ( V_16 ) ;
F_16 ( V_9 ) ;
V_2 -> V_15 = NULL ;
}
F_11 ( V_2 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_24 ( V_2 ) ;
}
void F_27 ( struct V_13 * V_9 )
{
struct V_1 * V_16 , * V_17 ;
struct V_18 * V_19 ;
if ( ! F_28 ( V_9 ) )
return;
V_19 = F_29 ( V_9 -> V_20 ) ;
F_23 (child, tmp,
&bus->devices, bus_list)
F_22 ( V_16 ) ;
F_9 ( & V_19 -> V_2 ) ;
}
void F_30 ( struct V_13 * V_9 )
{
struct V_1 * V_16 , * V_17 ;
struct V_18 * V_19 ;
if ( ! F_28 ( V_9 ) )
return;
V_19 = F_29 ( V_9 -> V_20 ) ;
F_25 (child, tmp,
&bus->devices, bus_list)
F_24 ( V_16 ) ;
F_16 ( V_9 ) ;
V_19 -> V_9 = NULL ;
F_15 ( & V_19 -> V_2 ) ;
}
