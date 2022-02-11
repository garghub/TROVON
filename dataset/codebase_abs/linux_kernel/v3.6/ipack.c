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
return V_6 ;
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
struct V_13 * F_8 ( struct V_1 * V_14 , int V_15 ,
struct V_16 * V_9 )
{
int V_17 ;
struct V_13 * V_18 ;
V_18 = F_9 ( sizeof( struct V_13 ) , V_19 ) ;
if ( ! V_18 )
return NULL ;
V_17 = F_10 ( & V_20 , 0 , 0 , V_19 ) ;
if ( V_17 < 0 ) {
F_3 ( V_18 ) ;
return NULL ;
}
V_18 -> V_17 = V_17 ;
V_18 -> V_14 = V_14 ;
V_18 -> V_15 = V_15 ;
V_18 -> V_9 = V_9 ;
return V_18 ;
}
int F_11 ( struct V_13 * V_18 )
{
F_12 ( & V_20 , V_18 -> V_17 ) ;
F_3 ( V_18 ) ;
return 0 ;
}
int F_13 ( struct V_7 * V_21 , struct V_22 * V_23 ,
char * V_24 )
{
V_21 -> V_5 . V_23 = V_23 ;
V_21 -> V_5 . V_24 = V_24 ;
V_21 -> V_5 . V_18 = & V_25 ;
return F_14 ( & V_21 -> V_5 ) ;
}
void F_15 ( struct V_7 * V_21 )
{
F_16 ( & V_21 -> V_5 ) ;
}
struct V_3 * F_17 ( struct V_13 * V_18 ,
int V_26 , int V_27 )
{
int V_6 ;
struct V_3 * V_2 ;
V_2 = F_9 ( sizeof( struct V_3 ) , V_19 ) ;
if ( ! V_2 )
return NULL ;
V_2 -> V_2 . V_18 = & V_25 ;
V_2 -> V_2 . V_28 = F_1 ;
V_2 -> V_2 . V_14 = V_18 -> V_14 ;
V_2 -> V_26 = V_26 ;
V_2 -> V_17 = V_18 -> V_17 ;
V_2 -> V_29 = V_27 ;
V_2 -> V_18 = V_18 ;
F_18 ( & V_2 -> V_2 ,
L_1 , V_2 -> V_17 , V_2 -> V_26 ) ;
V_6 = F_19 ( & V_2 -> V_2 ) ;
if ( V_6 < 0 ) {
F_3 ( V_2 ) ;
return NULL ;
}
return V_2 ;
}
void F_20 ( struct V_3 * V_2 )
{
F_21 ( & V_2 -> V_2 ) ;
}
static int T_1 F_22 ( void )
{
F_23 ( & V_20 ) ;
return F_24 ( & V_25 ) ;
}
static void T_2 F_25 ( void )
{
F_26 ( & V_25 ) ;
F_27 ( & V_20 ) ;
}
