static struct V_1 * F_1 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
struct V_4 * V_5 = V_6 . V_4 ;
F_2 ( & V_7 ) ;
while ( V_5 ) {
V_3 = F_3 ( V_5 , struct V_1 , V_4 ) ;
if ( V_2 < V_3 -> V_2 )
V_5 = V_5 -> V_8 ;
else if ( V_2 > V_3 -> V_2 )
V_5 = V_5 -> V_9 ;
else
break;
}
if ( ! V_5 )
return NULL ;
return V_3 ;
}
struct V_1 * F_4 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
if ( ! F_5 ( V_2 ) )
return NULL ;
F_6 ( & V_7 ) ;
V_3 = F_1 ( V_2 ) ;
F_7 ( & V_7 ) ;
return V_3 ;
}
static void F_8 ( struct V_1 * V_3 )
{
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0UL ;
F_9 ( V_12 , V_3 ) ;
}
int F_10 ( struct V_2 * V_2 )
{
struct V_4 * * V_13 ;
struct V_4 * V_14 , * V_15 = NULL ;
struct V_1 * V_16 , * V_17 ;
int V_18 ;
V_16 = F_11 ( V_12 , V_19 ) ;
if ( ! V_16 )
return - V_20 ;
V_16 -> V_2 = V_2 ;
V_14 = & V_16 -> V_4 ;
F_12 ( & V_2 -> V_21 ) ;
F_6 ( & V_7 ) ;
V_13 = & V_6 . V_4 ;
while ( * V_13 ) {
V_15 = * V_13 ;
V_17 = F_3 ( V_15 , struct V_1 , V_4 ) ;
V_18 = - V_22 ;
if ( V_2 < V_17 -> V_2 )
V_13 = & ( * V_13 ) -> V_8 ;
else if ( V_2 > V_17 -> V_2 )
V_13 = & ( * V_13 ) -> V_9 ;
else
goto V_23;
}
V_2 -> V_24 |= V_25 ;
F_13 ( V_14 , V_15 , V_13 ) ;
F_14 ( V_14 , & V_6 ) ;
F_7 ( & V_7 ) ;
F_15 ( & V_2 -> V_21 ) ;
return 0 ;
V_23:
F_7 ( & V_7 ) ;
F_15 ( & V_2 -> V_21 ) ;
F_8 ( V_16 ) ;
return V_18 ;
}
void F_16 ( struct V_2 * V_2 )
{
struct V_1 * V_3 ;
if ( ! F_5 ( V_2 ) )
return;
F_6 ( & V_7 ) ;
V_3 = F_1 ( V_2 ) ;
F_17 ( & V_3 -> V_4 , & V_6 ) ;
F_7 ( & V_7 ) ;
F_8 ( V_3 ) ;
}
static void F_18 ( void * V_26 )
{
struct V_1 * V_3 = V_26 ;
memset ( V_3 , 0 , sizeof *V_3 ) ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0UL ;
F_19 ( & V_3 -> V_27 ) ;
}
static int T_1 F_20 ( void )
{
V_12 =
F_21 ( L_1 , sizeof( struct V_1 ) , 0 ,
V_28 , F_18 ) ;
V_29 = 1 ;
return 0 ;
}
