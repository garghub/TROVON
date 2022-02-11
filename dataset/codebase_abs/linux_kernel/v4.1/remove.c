static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_5 * V_6 = V_2 -> V_5 + V_3 ;
if ( V_6 -> V_7 )
F_3 ( V_6 ) ;
}
}
static void F_4 ( struct V_1 * V_2 )
{
F_5 ( V_2 , false ) ;
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
if ( ! V_2 -> V_2 . V_11 . V_7 )
return;
F_11 ( & V_2 -> V_2 ) ;
F_12 ( & V_12 ) ;
F_13 ( & V_2 -> V_13 ) ;
F_14 ( & V_12 ) ;
F_1 ( V_2 ) ;
F_15 ( & V_2 -> V_2 ) ;
}
void F_16 ( struct V_14 * V_9 )
{
F_17 ( V_9 ) ;
F_12 ( & V_12 ) ;
F_13 ( & V_9 -> V_15 ) ;
F_18 ( V_9 ) ;
F_14 ( & V_12 ) ;
F_19 ( V_9 ) ;
F_20 ( V_9 ) ;
F_21 ( & V_9 -> V_2 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
struct V_14 * V_9 = V_2 -> V_16 ;
struct V_1 * V_17 , * V_18 ;
if ( V_9 ) {
F_23 (child, tmp,
&bus->devices, bus_list)
F_22 ( V_17 ) ;
}
F_4 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_14 * V_9 = V_2 -> V_16 ;
struct V_1 * V_17 , * V_18 ;
if ( V_9 ) {
F_25 (child, tmp,
&bus->devices, bus_list)
F_24 ( V_17 ) ;
F_16 ( V_9 ) ;
V_2 -> V_16 = NULL ;
}
F_10 ( V_2 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_22 ( V_2 ) ;
F_24 ( V_2 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 () ;
F_26 ( V_2 ) ;
F_29 () ;
}
void F_30 ( struct V_14 * V_9 )
{
struct V_1 * V_17 , * V_18 ;
struct V_19 * V_20 ;
if ( ! F_31 ( V_9 ) )
return;
V_20 = F_32 ( V_9 -> V_21 ) ;
F_23 (child, tmp,
&bus->devices, bus_list)
F_22 ( V_17 ) ;
F_8 ( & V_20 -> V_2 ) ;
}
void F_33 ( struct V_14 * V_9 )
{
struct V_1 * V_17 , * V_18 ;
struct V_19 * V_20 ;
if ( ! F_31 ( V_9 ) )
return;
V_20 = F_32 ( V_9 -> V_21 ) ;
F_25 (child, tmp,
&bus->devices, bus_list)
F_24 ( V_17 ) ;
F_16 ( V_9 ) ;
V_20 -> V_9 = NULL ;
F_21 ( & V_20 -> V_2 ) ;
}
