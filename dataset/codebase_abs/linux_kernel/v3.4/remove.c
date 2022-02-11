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
V_2 -> V_12 . V_13 = V_2 -> V_12 . V_14 = NULL ;
F_13 ( & V_11 ) ;
F_1 ( V_2 ) ;
F_14 ( V_2 ) ;
}
void F_15 ( struct V_15 * V_15 )
{
F_16 ( V_15 ) ;
F_11 ( & V_11 ) ;
F_12 ( & V_15 -> V_16 ) ;
F_13 ( & V_11 ) ;
if ( ! V_15 -> V_8 )
return;
F_17 ( V_15 ) ;
F_8 ( & V_15 -> V_2 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 ) {
struct V_15 * V_18 = V_2 -> V_17 ;
F_19 ( V_2 ) ;
F_15 ( V_18 ) ;
V_2 -> V_17 = NULL ;
}
F_10 ( V_2 ) ;
}
void F_20 ( struct V_1 * V_2 )
{
F_21 ( V_2 ) ;
F_18 ( V_2 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_21 ;
if ( V_2 -> V_17 )
F_22 (l, n, &dev->subordinate->devices)
F_18 ( F_23 ( V_20 ) ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
struct V_19 * V_20 , * V_21 ;
if ( V_2 -> V_17 )
F_22 (l, n, &dev->subordinate->devices)
F_21 ( F_23 ( V_20 ) ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_24 ( V_2 ) ;
F_19 ( V_2 ) ;
}
static void F_26 ( struct V_15 * V_9 )
{
struct V_19 * V_20 , * V_21 ;
F_27 (l, n, &bus->devices) {
struct V_1 * V_2 = F_23 ( V_20 ) ;
F_21 ( V_2 ) ;
}
}
void F_21 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 )
F_26 ( V_2 -> V_17 ) ;
F_5 ( V_2 ) ;
}
