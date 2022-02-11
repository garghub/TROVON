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
V_3 -> V_12 = V_13 ;
F_9 ( V_14 , V_3 ) ;
}
int F_10 ( struct V_2 * V_2 )
{
struct V_4 * * V_15 ;
struct V_4 * V_16 , * V_17 = NULL ;
struct V_1 * V_18 , * V_19 ;
int V_20 ;
V_18 = F_11 ( V_14 , V_21 ) ;
if ( ! V_18 )
return - V_22 ;
V_18 -> V_2 = V_2 ;
V_16 = & V_18 -> V_4 ;
F_12 ( & V_2 -> V_23 ) ;
F_6 ( & V_7 ) ;
V_15 = & V_6 . V_4 ;
while ( * V_15 ) {
V_17 = * V_15 ;
V_19 = F_3 ( V_17 , struct V_1 ,
V_4 ) ;
V_20 = - V_24 ;
if ( V_2 < V_19 -> V_2 )
V_15 = & ( * V_15 ) -> V_8 ;
else if ( V_2 > V_19 -> V_2 )
V_15 = & ( * V_15 ) -> V_9 ;
else
goto V_25;
}
V_2 -> V_26 |= V_27 ;
F_13 ( V_16 , V_17 , V_15 ) ;
F_14 ( V_16 , & V_6 ) ;
F_7 ( & V_7 ) ;
F_15 ( & V_2 -> V_23 ) ;
return 0 ;
V_25:
F_7 ( & V_7 ) ;
F_15 ( & V_2 -> V_23 ) ;
F_8 ( V_18 ) ;
return V_20 ;
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
static void F_18 ( void * V_28 )
{
struct V_1 * V_3 = V_28 ;
memset ( V_3 , 0 , sizeof *V_3 ) ;
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0UL ;
F_19 ( & V_3 -> V_29 ) ;
V_3 -> V_12 = V_13 ;
}
static int T_1 F_20 ( void )
{
V_14 =
F_21 ( L_1 , sizeof( struct V_1 ) ,
0 , V_30 , F_18 ) ;
V_31 = 1 ;
return 0 ;
}
