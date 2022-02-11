static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = F_2 ( V_6 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
if ( ! V_4 )
return;
F_4 ( V_6 ,
F_2 ( V_6 ) ,
V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = F_2 ( V_7 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
if ( ! V_4 )
return;
F_6 ( V_7 ,
F_2 ( V_7 ) , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = F_2 ( V_8 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
if ( ! V_4 )
return;
F_6 ( V_8 ,
F_2 ( V_8 ) , V_4 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = F_2 ( V_9 ) +
F_2 ( V_10 ) +
F_2 ( V_11 ) +
F_2 ( V_12 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
if ( ! V_4 )
return;
F_6 ( V_9 ,
F_2 ( V_9 ) , V_4 ) ;
F_4 ( V_10 ,
F_2 ( V_10 ) ,
V_4 ) ;
F_9 ( V_11 ,
F_2 ( V_11 ) , V_4 ) ;
F_10 ( V_12 ,
F_2 ( V_12 ) ,
V_4 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_5 = F_2 ( V_13 ) +
F_2 ( V_14 ) +
F_2 ( V_15 ) +
F_2 ( V_16 ) +
F_2 ( V_17 ) +
F_2 ( V_18 ) ;
V_4 = F_3 ( V_2 , V_5 ) ;
if ( ! V_4 )
return;
F_12 ( V_13 ,
F_2 ( V_13 ) ,
V_4 ) ;
F_4 ( V_14 ,
F_2 ( V_14 ) ,
V_4 ) ;
F_6 ( V_15 ,
F_2 ( V_15 ) ,
V_4 ) ;
F_9 ( V_16 ,
F_2 ( V_16 ) ,
V_4 ) ;
F_13 ( V_17 ,
F_2 ( V_17 ) ,
V_4 ) ;
F_10 ( V_18 ,
F_2 ( V_18 ) ,
V_4 ) ;
}
static int F_14 ( struct V_19 * V_20 )
{
struct V_21 * V_22 = & V_20 -> V_22 ;
struct V_1 * V_2 = V_20 -> V_22 . V_23 ;
void (* F_15)( struct V_1 * V_2 );
F_15 = F_16 ( V_22 ) ;
if ( ! F_15 )
return - V_24 ;
F_15 ( V_2 ) ;
return 0 ;
}
static int T_1 F_17 ( void )
{
return F_18 ( & V_25 ) ;
}
