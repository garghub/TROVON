static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_5 * V_6 = V_2 -> V_5 + V_3 ;
if ( V_6 -> V_7 )
F_2 ( V_6 ) ;
}
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 , false ) ;
if ( V_2 -> V_8 ) {
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( & V_2 -> V_2 ) ;
V_2 -> V_8 = 0 ;
}
if ( V_2 -> V_9 -> V_10 )
F_8 ( V_2 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_2 . V_11 . V_7 )
return;
F_10 ( & V_2 -> V_2 ) ;
F_11 ( & V_12 ) ;
F_12 ( & V_2 -> V_13 ) ;
F_13 ( & V_12 ) ;
F_1 ( V_2 ) ;
F_14 ( & V_2 -> V_2 ) ;
}
void F_15 ( struct V_14 * V_9 )
{
F_16 ( V_9 ) ;
F_11 ( & V_12 ) ;
F_12 ( & V_9 -> V_15 ) ;
F_17 ( V_9 ) ;
F_13 ( & V_12 ) ;
F_18 ( V_9 ) ;
if ( V_9 -> V_16 -> V_17 )
V_9 -> V_16 -> V_17 ( V_9 ) ;
F_19 ( V_9 ) ;
F_20 ( & V_9 -> V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
struct V_14 * V_9 = V_2 -> V_18 ;
struct V_1 * V_19 , * V_20 ;
if ( V_9 ) {
F_22 (child, tmp,
&bus->devices, bus_list)
F_21 ( V_19 ) ;
}
F_3 ( V_2 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
struct V_14 * V_9 = V_2 -> V_18 ;
struct V_1 * V_19 , * V_20 ;
if ( V_9 ) {
F_24 (child, tmp,
&bus->devices, bus_list)
F_23 ( V_19 ) ;
F_15 ( V_9 ) ;
V_2 -> V_18 = NULL ;
}
F_9 ( V_2 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_23 ( V_2 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 () ;
F_25 ( V_2 ) ;
F_28 () ;
}
void F_29 ( struct V_14 * V_9 )
{
struct V_1 * V_19 , * V_20 ;
struct V_21 * V_22 ;
if ( ! F_30 ( V_9 ) )
return;
V_22 = F_31 ( V_9 -> V_23 ) ;
F_22 (child, tmp,
&bus->devices, bus_list)
F_21 ( V_19 ) ;
F_7 ( & V_22 -> V_2 ) ;
}
void F_32 ( struct V_14 * V_9 )
{
struct V_1 * V_19 , * V_20 ;
struct V_21 * V_22 ;
if ( ! F_30 ( V_9 ) )
return;
V_22 = F_31 ( V_9 -> V_23 ) ;
F_24 (child, tmp,
&bus->devices, bus_list)
F_23 ( V_19 ) ;
F_15 ( V_9 ) ;
V_22 -> V_9 = NULL ;
F_20 ( & V_22 -> V_2 ) ;
}
