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
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0UL ;
V_3 -> V_12 = V_13 ;
V_3 -> V_14 = V_13 ;
F_8 ( V_15 , V_3 ) ;
}
struct V_1 * F_9 ( struct V_2 * V_2 )
{
struct V_4 * * V_16 ;
struct V_4 * V_17 , * V_18 = NULL ;
struct V_1 * V_3 , * V_19 ;
V_3 = F_3 ( V_2 ) ;
if ( V_3 )
return V_3 ;
V_3 = F_10 ( V_15 , V_20 ) ;
if ( ! V_3 )
return NULL ;
F_11 ( & V_9 ) ;
V_16 = & V_6 . V_4 ;
while ( * V_16 ) {
V_18 = * V_16 ;
V_19 = F_2 ( V_18 , struct V_1 ,
V_4 ) ;
if ( V_2 < V_19 -> V_2 )
V_16 = & ( * V_16 ) -> V_7 ;
else
V_16 = & ( * V_16 ) -> V_8 ;
}
V_3 -> V_2 = V_2 ;
V_17 = & V_3 -> V_4 ;
V_2 -> V_21 |= V_22 ;
F_12 ( V_17 , V_18 , V_16 ) ;
F_13 ( V_17 , & V_6 ) ;
F_14 ( & V_9 ) ;
return V_3 ;
}
void F_15 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
if ( ! F_4 ( V_2 ) )
return;
F_11 ( & V_9 ) ;
V_3 = F_1 ( V_2 ) ;
F_16 ( & V_3 -> V_4 , & V_6 ) ;
F_14 ( & V_9 ) ;
F_7 ( V_3 ) ;
}
static void F_17 ( void * V_23 )
{
struct V_1 * V_3 = V_23 ;
memset ( V_3 , 0 , sizeof *V_3 ) ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0UL ;
V_3 -> V_12 = V_13 ;
V_3 -> V_14 = V_13 ;
}
static int T_1 F_18 ( void )
{
V_15 =
F_19 ( L_1 , sizeof( struct V_1 ) ,
0 , V_24 , F_17 ) ;
V_25 = 1 ;
return 0 ;
}
