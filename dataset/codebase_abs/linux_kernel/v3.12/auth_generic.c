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
V_25 -> V_5 . V_32 = 0 ;
if ( V_25 -> V_5 . V_31 != NULL )
F_13 ( V_25 -> V_5 . V_31 ) ;
V_25 -> V_5 . V_11 = V_5 -> V_11 ;
V_25 -> V_5 . V_10 = V_5 -> V_10 ;
F_4 ( L_2 ,
V_25 -> V_5 . V_11 ? L_3 : L_4 ,
V_25 ,
F_14 ( & V_33 , V_5 -> V_6 ) ,
F_15 ( & V_33 , V_5 -> V_8 ) ) ;
return & V_25 -> V_23 ;
}
static void
F_16 ( struct V_1 * V_16 )
{
struct V_22 * V_25 = F_6 ( V_16 , struct V_22 , V_23 ) ;
F_4 ( L_5 , V_25 ) ;
if ( V_25 -> V_5 . V_31 != NULL )
F_17 ( V_25 -> V_5 . V_31 ) ;
F_18 ( V_25 ) ;
}
static void
F_19 ( struct V_34 * V_35 )
{
struct V_1 * V_16 = F_6 ( V_35 , struct V_1 , V_36 ) ;
F_16 ( V_16 ) ;
}
static void
F_20 ( struct V_1 * V_16 )
{
F_21 ( & V_16 -> V_36 , F_19 ) ;
}
static int
F_22 ( struct V_4 * V_5 , struct V_22 * V_25 , int V_24 )
{
if ( ! V_25 -> V_5 . V_11 ||
V_25 -> V_5 . V_10 != V_5 -> V_10 ||
! F_23 ( V_25 -> V_5 . V_6 , V_5 -> V_6 ) ||
! F_24 ( V_25 -> V_5 . V_8 , V_5 -> V_8 ) )
return 0 ;
return 1 ;
}
static int
F_25 ( struct V_4 * V_5 , struct V_1 * V_16 , int V_24 )
{
struct V_22 * V_25 = F_6 ( V_16 , struct V_22 , V_23 ) ;
int V_37 ;
if ( V_5 -> V_11 )
return F_22 ( V_5 , V_25 , V_24 ) ;
if ( ! F_23 ( V_25 -> V_5 . V_6 , V_5 -> V_6 ) ||
! F_24 ( V_25 -> V_5 . V_8 , V_5 -> V_8 ) ||
V_25 -> V_5 . V_11 != 0 )
goto V_38;
if ( V_25 -> V_5 . V_31 == V_5 -> V_31 )
goto V_39;
if ( V_25 -> V_5 . V_31 -> V_40 != V_5 -> V_31 -> V_40 )
goto V_38;
for ( V_37 = 0 ; V_37 < V_25 -> V_5 . V_31 -> V_40 ; V_37 ++ ) {
if ( ! F_24 ( F_26 ( V_25 -> V_5 . V_31 , V_37 ) ,
F_26 ( V_5 -> V_31 , V_37 ) ) )
goto V_38;
}
V_39:
return 1 ;
V_38:
return 0 ;
}
int T_1 F_27 ( void )
{
return F_28 ( & V_2 ) ;
}
void F_29 ( void )
{
F_30 ( & V_2 ) ;
}
static int
F_31 ( struct V_18 * V_19 , struct V_1 * V_16 )
{
struct V_4 * V_5 = & F_6 ( V_16 , struct V_22 ,
V_23 ) -> V_5 ;
struct V_1 * V_41 ;
int V_42 = 0 ;
if ( F_32 ( V_43 , & V_5 -> V_32 ) )
return 0 ;
if ( F_32 ( V_44 , & V_5 -> V_32 ) )
return 0 ;
V_41 = V_19 -> V_12 -> V_13 ( V_19 , V_5 , 0 ) ;
if ( F_33 ( V_41 ) )
return - V_45 ;
if ( ! V_41 -> V_46 -> V_47 ) {
F_34 ( V_43 , & V_5 -> V_32 ) ;
V_42 = 0 ;
goto V_48;
}
V_42 = V_41 -> V_46 -> V_47 ( V_41 ) ;
if ( V_42 != 0 ) {
F_34 ( V_49 , & V_5 -> V_32 ) ;
V_42 = 0 ;
} else {
if ( F_35 ( V_49 ,
& V_5 -> V_32 ) )
F_4 ( L_6 ,
F_14 ( & V_33 , V_41 -> V_50 ) ) ;
F_34 ( V_44 , & V_5 -> V_32 ) ;
}
V_48:
F_36 ( V_41 ) ;
return V_42 ;
}
static bool F_37 ( struct V_1 * V_16 )
{
struct V_4 * V_5 = & F_6 ( V_16 , struct V_22 ,
V_23 ) -> V_5 ;
bool V_42 ;
F_38 ( V_16 ) ;
V_42 = F_32 ( V_49 , & V_5 -> V_32 ) ;
F_36 ( V_16 ) ;
return V_42 ;
}
