static struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 = V_6 . V_4 ;
while ( V_5 ) {
V_3 = F_2 ( V_5 , struct V_1 , V_4 ) ;
if ( V_2 < V_3 -> V_2 )
V_5 = V_5 -> V_7 ;
else if ( V_2 > V_3 -> V_2 )
V_5 = V_5 -> V_8 ;
else
break;
}
if ( ! V_5 )
return NULL ;
return V_3 ;
}
struct V_1 * F_3 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
if ( ! F_4 ( V_2 ) )
return NULL ;
F_5 ( & V_9 ) ;
V_3 = F_1 ( V_2 ) ;
F_6 ( & V_9 ) ;
return V_3 ;
}
static void F_7 ( struct V_1 * V_3 )
{
F_8 ( V_3 -> V_10 ) ;
V_3 -> V_10 = NULL ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0UL ;
V_3 -> V_13 = V_14 ;
V_3 -> V_15 = V_14 ;
V_3 -> V_16 = V_14 ;
V_3 -> V_17 = V_14 ;
V_3 -> V_18 = V_14 ;
F_9 ( V_19 , V_3 ) ;
}
struct V_1 * F_10 ( struct V_2 * V_2 )
{
struct V_4 * * V_20 ;
struct V_4 * V_21 , * V_22 = NULL ;
struct V_1 * V_3 , * V_23 ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_11 ( V_19 , V_24 ) ;
if ( ! V_3 )
return NULL ;
F_12 ( & V_9 ) ;
V_20 = & V_6 . V_4 ;
while ( * V_20 ) {
V_22 = * V_20 ;
V_23 = F_2 ( V_22 , struct V_1 ,
V_4 ) ;
if ( V_2 < V_23 -> V_2 )
V_20 = & ( * V_20 ) -> V_7 ;
else
V_20 = & ( * V_20 ) -> V_8 ;
}
V_3 -> V_2 = V_2 ;
V_21 = & V_3 -> V_4 ;
V_2 -> V_25 |= V_26 ;
F_13 ( V_21 , V_22 , V_20 ) ;
F_14 ( V_21 , & V_6 ) ;
F_15 ( & V_9 ) ;
return V_3 ;
}
void F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
if ( ! F_4 ( V_2 ) )
return;
F_12 ( & V_9 ) ;
V_3 = F_1 ( V_2 ) ;
F_17 ( & V_3 -> V_4 , & V_6 ) ;
F_15 ( & V_9 ) ;
F_7 ( V_3 ) ;
}
static void F_18 ( void * V_27 )
{
struct V_1 * V_3 = V_27 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0UL ;
V_3 -> V_13 = V_14 ;
V_3 -> V_15 = V_14 ;
V_3 -> V_16 = V_14 ;
V_3 -> V_17 = V_14 ;
V_3 -> V_18 = V_14 ;
}
static int T_1 F_19 ( void )
{
V_19 =
F_20 ( L_1 , sizeof( struct V_1 ) ,
0 , V_28 , F_18 ) ;
V_29 = 1 ;
return 0 ;
}
