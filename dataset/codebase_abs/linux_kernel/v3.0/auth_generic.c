struct V_1 * F_1 ( void )
{
return F_2 ( & V_2 , 0 ) ;
}
struct V_1 * F_3 ( void )
{
struct V_3 V_4 = {
. V_5 = V_6 ,
. V_7 = V_8 ,
. V_9 = 1 ,
} ;
F_4 ( L_1 ) ;
return V_2 . V_10 -> V_11 ( & V_2 , & V_4 , 0 ) ;
}
static struct V_1 * F_5 ( struct V_12 * V_13 ,
struct V_1 * V_14 , int V_15 )
{
struct V_16 * V_17 = V_13 -> V_18 -> V_19 ;
struct V_3 * V_4 = & F_6 ( V_14 , struct V_20 , V_21 ) -> V_4 ;
return V_17 -> V_10 -> V_11 ( V_17 , V_4 , V_15 ) ;
}
static struct V_1 *
F_7 ( struct V_16 * V_17 , struct V_3 * V_4 , int V_22 )
{
return F_8 ( & V_2 , V_4 , V_22 ) ;
}
static struct V_1 *
F_9 ( struct V_16 * V_17 , struct V_3 * V_4 , int V_22 )
{
struct V_20 * V_23 ;
V_23 = F_10 ( sizeof( * V_23 ) , V_24 ) ;
if ( V_23 == NULL )
return F_11 ( - V_25 ) ;
F_12 ( & V_23 -> V_21 , V_4 , & V_2 , & V_26 ) ;
V_23 -> V_21 . V_27 = 1UL << V_28 ;
V_23 -> V_4 . V_5 = V_4 -> V_5 ;
V_23 -> V_4 . V_7 = V_4 -> V_7 ;
V_23 -> V_4 . V_29 = V_4 -> V_29 ;
if ( V_23 -> V_4 . V_29 != NULL )
F_13 ( V_23 -> V_4 . V_29 ) ;
V_23 -> V_4 . V_9 = V_4 -> V_9 ;
F_4 ( L_2 ,
V_23 -> V_4 . V_9 ? L_3 : L_4 ,
V_23 , V_4 -> V_5 , V_4 -> V_7 ) ;
return & V_23 -> V_21 ;
}
static void
F_14 ( struct V_1 * V_14 )
{
struct V_20 * V_23 = F_6 ( V_14 , struct V_20 , V_21 ) ;
F_4 ( L_5 , V_23 ) ;
if ( V_23 -> V_4 . V_29 != NULL )
F_15 ( V_23 -> V_4 . V_29 ) ;
F_16 ( V_23 ) ;
}
static void
F_17 ( struct V_30 * V_31 )
{
struct V_1 * V_14 = F_6 ( V_31 , struct V_1 , V_32 ) ;
F_14 ( V_14 ) ;
}
static void
F_18 ( struct V_1 * V_14 )
{
F_19 ( & V_14 -> V_32 , F_17 ) ;
}
static int
F_20 ( struct V_3 * V_4 , struct V_1 * V_14 , int V_22 )
{
struct V_20 * V_23 = F_6 ( V_14 , struct V_20 , V_21 ) ;
int V_33 ;
if ( V_23 -> V_4 . V_5 != V_4 -> V_5 ||
V_23 -> V_4 . V_7 != V_4 -> V_7 ||
V_23 -> V_4 . V_9 != V_4 -> V_9 )
goto V_34;
if ( V_23 -> V_4 . V_29 == V_4 -> V_29 )
goto V_35;
if ( V_23 -> V_4 . V_29 -> V_36 != V_4 -> V_29 -> V_36 )
goto V_34;
for ( V_33 = 0 ; V_33 < V_23 -> V_4 . V_29 -> V_36 ; V_33 ++ ) {
if ( F_21 ( V_23 -> V_4 . V_29 , V_33 ) !=
F_21 ( V_4 -> V_29 , V_33 ) )
goto V_34;
}
V_35:
return 1 ;
V_34:
return 0 ;
}
int T_1 F_22 ( void )
{
return F_23 ( & V_2 ) ;
}
void F_24 ( void )
{
F_25 ( & V_2 ) ;
}
