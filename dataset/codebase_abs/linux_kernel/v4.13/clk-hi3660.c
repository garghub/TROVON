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
int V_5 = F_2 ( V_13 ) +
F_2 ( V_14 ) +
F_2 ( V_15 ) +
F_2 ( V_16 ) +
F_2 ( V_17 ) +
F_2 ( V_18 ) ;
int V_19 ;
V_20 = F_3 ( V_2 , V_5 ) ;
if ( ! V_20 )
return;
for ( V_19 = 0 ; V_19 < V_5 ; V_19 ++ )
V_20 -> V_4 . V_21 [ V_19 ] = F_12 ( - V_22 ) ;
F_13 ( V_13 ,
F_2 ( V_13 ) ,
V_20 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_23 * * V_21 ;
int V_19 ;
if ( ! V_20 )
F_11 ( V_2 ) ;
if ( ! V_20 )
return;
F_4 ( V_14 ,
F_2 ( V_14 ) ,
V_20 ) ;
F_6 ( V_15 ,
F_2 ( V_15 ) ,
V_20 ) ;
F_9 ( V_16 ,
F_2 ( V_16 ) ,
V_20 ) ;
F_15 ( V_17 ,
F_2 ( V_17 ) ,
V_20 ) ;
F_10 ( V_18 ,
F_2 ( V_18 ) ,
V_20 ) ;
V_21 = V_20 -> V_4 . V_21 ;
for ( V_19 = 0 ; V_19 < V_20 -> V_4 . V_24 ; V_19 ++ ) {
if ( F_16 ( V_21 [ V_19 ] ) && F_17 ( V_21 [ V_19 ] ) != - V_22 )
F_18 ( L_1 ,
V_19 , F_17 ( V_21 [ V_19 ] ) ) ;
}
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_27 * V_28 = & V_26 -> V_28 ;
struct V_1 * V_2 = V_26 -> V_28 . V_29 ;
void (* F_20)( struct V_1 * V_2 );
F_20 = F_21 ( V_28 ) ;
if ( ! F_20 )
return - V_30 ;
F_20 ( V_2 ) ;
return 0 ;
}
static int T_1 F_22 ( void )
{
return F_23 ( & V_31 ) ;
}
