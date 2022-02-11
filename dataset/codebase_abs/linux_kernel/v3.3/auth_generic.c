struct V_1 * F_1 ( void )
{
return F_2 ( & V_2 , 0 ) ;
}
struct V_1 * F_3 ( const char * V_3 )
{
struct V_4 V_5 = {
. V_6 = V_7 ,
. V_8 = V_9 ,
. V_10 = V_3 ,
. V_11 = 1 ,
} ;
F_4 ( L_1 ,
V_3 ) ;
return V_2 . V_12 -> V_13 ( & V_2 , & V_5 , 0 ) ;
}
static struct V_1 * F_5 ( struct V_14 * V_15 ,
struct V_1 * V_16 , int V_17 )
{
struct V_18 * V_19 = V_15 -> V_20 -> V_21 ;
struct V_4 * V_5 = & F_6 ( V_16 , struct V_22 , V_23 ) -> V_5 ;
return V_19 -> V_12 -> V_13 ( V_19 , V_5 , V_17 ) ;
}
static struct V_1 *
F_7 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_24 )
{
return F_8 ( & V_2 , V_5 , V_24 ) ;
}
static struct V_1 *
F_9 ( struct V_18 * V_19 , struct V_4 * V_5 , int V_24 )
{
struct V_22 * V_25 ;
V_25 = F_10 ( sizeof( * V_25 ) , V_26 ) ;
if ( V_25 == NULL )
return F_11 ( - V_27 ) ;
F_12 ( & V_25 -> V_23 , V_5 , & V_2 , & V_28 ) ;
V_25 -> V_23 . V_29 = 1UL << V_30 ;
V_25 -> V_5 . V_6 = V_5 -> V_6 ;
V_25 -> V_5 . V_8 = V_5 -> V_8 ;
V_25 -> V_5 . V_31 = V_5 -> V_31 ;
if ( V_25 -> V_5 . V_31 != NULL )
F_13 ( V_25 -> V_5 . V_31 ) ;
V_25 -> V_5 . V_11 = V_5 -> V_11 ;
V_25 -> V_5 . V_10 = V_5 -> V_10 ;
F_4 ( L_2 ,
V_25 -> V_5 . V_11 ? L_3 : L_4 ,
V_25 , V_5 -> V_6 , V_5 -> V_8 ) ;
return & V_25 -> V_23 ;
}
static void
F_14 ( struct V_1 * V_16 )
{
struct V_22 * V_25 = F_6 ( V_16 , struct V_22 , V_23 ) ;
F_4 ( L_5 , V_25 ) ;
if ( V_25 -> V_5 . V_31 != NULL )
F_15 ( V_25 -> V_5 . V_31 ) ;
F_16 ( V_25 ) ;
}
static void
F_17 ( struct V_32 * V_33 )
{
struct V_1 * V_16 = F_6 ( V_33 , struct V_1 , V_34 ) ;
F_14 ( V_16 ) ;
}
static void
F_18 ( struct V_1 * V_16 )
{
F_19 ( & V_16 -> V_34 , F_17 ) ;
}
static int
F_20 ( struct V_4 * V_5 , struct V_22 * V_25 , int V_24 )
{
if ( ! V_25 -> V_5 . V_11 ||
V_25 -> V_5 . V_10 != V_5 -> V_10 ||
V_25 -> V_5 . V_6 != V_5 -> V_6 ||
V_25 -> V_5 . V_8 != V_5 -> V_8 )
return 0 ;
return 1 ;
}
static int
F_21 ( struct V_4 * V_5 , struct V_1 * V_16 , int V_24 )
{
struct V_22 * V_25 = F_6 ( V_16 , struct V_22 , V_23 ) ;
int V_35 ;
if ( V_5 -> V_11 )
return F_20 ( V_5 , V_25 , V_24 ) ;
if ( V_25 -> V_5 . V_6 != V_5 -> V_6 ||
V_25 -> V_5 . V_8 != V_5 -> V_8 ||
V_25 -> V_5 . V_11 != 0 )
goto V_36;
if ( V_25 -> V_5 . V_31 == V_5 -> V_31 )
goto V_37;
if ( V_25 -> V_5 . V_31 -> V_38 != V_5 -> V_31 -> V_38 )
goto V_36;
for ( V_35 = 0 ; V_35 < V_25 -> V_5 . V_31 -> V_38 ; V_35 ++ ) {
if ( F_22 ( V_25 -> V_5 . V_31 , V_35 ) !=
F_22 ( V_5 -> V_31 , V_35 ) )
goto V_36;
}
V_37:
return 1 ;
V_36:
return 0 ;
}
int T_1 F_23 ( void )
{
return F_24 ( & V_2 ) ;
}
void F_25 ( void )
{
F_26 ( & V_2 ) ;
}
