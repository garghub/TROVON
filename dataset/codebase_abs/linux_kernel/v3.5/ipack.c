static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_1 = F_2 ( V_2 ) ;
F_3 ( V_1 ) ;
}
static int F_4 ( struct V_1 * V_1 , struct V_4 * V_5 )
{
int V_6 ;
struct V_3 * V_2 = F_2 ( V_1 ) ;
struct V_7 * V_8 = F_5 ( V_5 ) ;
if ( ( ! V_8 -> V_9 ) || ( ! V_8 -> V_9 -> V_10 ) )
return - V_11 ;
V_6 = V_8 -> V_9 -> V_10 ( V_2 ) ;
if ( V_6 )
V_2 -> V_5 = V_8 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
if ( ! V_2 -> V_5 -> V_9 -> V_12 )
return - V_11 ;
return V_2 -> V_5 -> V_9 -> V_12 ( V_2 ) ;
}
static int F_7 ( struct V_1 * V_1 )
{
struct V_3 * V_2 = F_2 ( V_1 ) ;
if ( ! V_2 -> V_5 -> V_9 -> remove )
return - V_11 ;
V_2 -> V_5 -> V_9 -> remove ( V_2 ) ;
return 0 ;
}
static int F_8 ( void )
{
int V_13 ;
F_9 ( & V_14 ) ;
V_13 = F_10 ( V_15 . V_15 , V_16 , 1 ) ;
if ( V_13 >= V_16 ) {
F_11 ( L_1 ) ;
V_13 = - 1 ;
goto V_17;
}
F_12 ( V_13 , V_15 . V_15 ) ;
V_17:
F_13 ( & V_14 ) ;
return V_13 ;
}
struct V_18 * F_14 ( struct V_1 * V_19 , int V_20 ,
struct V_21 * V_9 )
{
int V_22 ;
struct V_18 * V_23 ;
V_23 = F_15 ( sizeof( struct V_18 ) , V_24 ) ;
if ( ! V_23 )
return NULL ;
V_22 = F_8 () ;
if ( V_22 < 0 ) {
F_3 ( V_23 ) ;
return NULL ;
}
V_23 -> V_22 = V_22 ;
V_23 -> V_19 = V_19 ;
V_23 -> V_20 = V_20 ;
V_23 -> V_9 = V_9 ;
return V_23 ;
}
int F_16 ( struct V_18 * V_23 )
{
F_9 ( & V_14 ) ;
F_17 ( V_23 -> V_22 , V_15 . V_15 ) ;
F_13 ( & V_14 ) ;
F_3 ( V_23 ) ;
return 0 ;
}
int F_18 ( struct V_7 * V_25 , struct V_26 * V_27 ,
char * V_28 )
{
V_25 -> V_5 . V_27 = V_27 ;
V_25 -> V_5 . V_28 = V_28 ;
V_25 -> V_5 . V_23 = & V_29 ;
return F_19 ( & V_25 -> V_5 ) ;
}
void F_20 ( struct V_7 * V_25 )
{
F_21 ( & V_25 -> V_5 ) ;
}
struct V_3 * F_22 ( struct V_18 * V_23 ,
int V_30 , int V_31 )
{
int V_6 ;
struct V_3 * V_2 ;
V_2 = F_15 ( sizeof( struct V_3 ) , V_24 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_2 . V_23 = & V_29 ;
V_2 -> V_2 . V_32 = F_1 ;
V_2 -> V_2 . V_19 = V_23 -> V_19 ;
V_2 -> V_30 = V_30 ;
V_2 -> V_22 = V_23 -> V_22 ;
V_2 -> V_33 = V_31 ;
V_2 -> V_23 = V_23 ;
F_23 ( & V_2 -> V_2 ,
L_2 , V_2 -> V_22 , V_2 -> V_30 ) ;
V_6 = F_24 ( & V_2 -> V_2 ) ;
if ( V_6 < 0 ) {
F_11 ( L_3 ) ;
V_2 -> V_5 -> V_9 -> remove ( V_2 ) ;
F_3 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_25 ( struct V_3 * V_2 )
{
F_26 ( & V_2 -> V_2 ) ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_29 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_29 ) ;
}
