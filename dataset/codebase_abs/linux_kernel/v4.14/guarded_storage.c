void F_1 ( void )
{
F_2 ( V_1 -> V_2 . V_3 ) ;
F_2 ( V_1 -> V_2 . V_4 ) ;
V_1 -> V_2 . V_3 = V_1 -> V_2 . V_4 = NULL ;
}
static int F_3 ( void )
{
struct V_3 * V_3 ;
if ( ! V_1 -> V_2 . V_3 ) {
V_3 = F_4 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 )
return - V_6 ;
V_3 -> V_7 = 25 ;
F_5 () ;
F_6 ( 2 , 4 ) ;
F_7 ( V_3 ) ;
V_1 -> V_2 . V_3 = V_3 ;
F_8 () ;
}
return 0 ;
}
static int F_9 ( void )
{
if ( V_1 -> V_2 . V_3 ) {
F_5 () ;
F_2 ( V_1 -> V_2 . V_3 ) ;
V_1 -> V_2 . V_3 = NULL ;
F_10 ( 2 , 4 ) ;
F_8 () ;
}
return 0 ;
}
static int F_11 ( struct V_3 T_1 * V_8 )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_2 . V_4 ;
if ( ! V_3 ) {
V_3 = F_4 ( sizeof( * V_3 ) , V_5 ) ;
if ( ! V_3 )
return - V_6 ;
V_1 -> V_2 . V_4 = V_3 ;
}
if ( F_12 ( V_3 , V_8 , sizeof( * V_3 ) ) )
return - V_9 ;
return 0 ;
}
static int F_13 ( void )
{
struct V_3 * V_3 ;
V_3 = V_1 -> V_2 . V_4 ;
V_1 -> V_2 . V_4 = NULL ;
F_2 ( V_3 ) ;
return 0 ;
}
void F_14 ( struct V_10 * V_11 )
{
struct V_3 * V_3 ;
F_5 () ;
F_15 ( V_12 ) ;
V_3 = V_1 -> V_2 . V_4 ;
if ( V_3 ) {
F_2 ( V_1 -> V_2 . V_3 ) ;
V_1 -> V_2 . V_4 = NULL ;
F_6 ( 2 , 4 ) ;
F_7 ( V_3 ) ;
V_1 -> V_2 . V_3 = V_3 ;
}
F_8 () ;
}
static int F_16 ( void )
{
struct V_13 * V_14 ;
F_17 ( & V_15 ) ;
F_18 (current, sibling) {
if ( ! V_14 -> V_2 . V_4 )
continue;
if ( F_19 ( V_14 , V_12 ) )
F_20 ( V_14 ) ;
}
F_21 ( & V_15 ) ;
return 0 ;
}
