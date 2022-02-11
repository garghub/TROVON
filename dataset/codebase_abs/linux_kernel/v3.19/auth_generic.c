struct V_1 * F_1 ( void )
{
return F_2 ( & V_2 , 0 ) ;
}
struct V_1 * F_3 ( void )
{
return F_2 ( & V_2 , V_3 ) ;
}
struct V_1 * F_4 ( const char * V_4 )
{
struct V_5 V_6 = {
. V_7 = V_8 ,
. V_9 = V_10 ,
. V_11 = V_4 ,
. V_12 = 1 ,
} ;
F_5 ( L_1 ,
V_4 ) ;
return V_2 . V_13 -> V_14 ( & V_2 , & V_6 , 0 ) ;
}
static struct V_1 * F_6 ( struct V_15 * V_16 ,
struct V_1 * V_17 , int V_18 )
{
struct V_19 * V_20 = V_16 -> V_21 -> V_22 ;
struct V_5 * V_6 = & F_7 ( V_17 , struct V_23 , V_24 ) -> V_6 ;
return V_20 -> V_13 -> V_14 ( V_20 , V_6 , V_18 ) ;
}
static struct V_1 *
F_8 ( struct V_19 * V_20 , struct V_5 * V_6 , int V_25 )
{
return F_9 ( & V_2 , V_6 , V_25 ) ;
}
static struct V_1 *
F_10 ( struct V_19 * V_20 , struct V_5 * V_6 , int V_25 )
{
struct V_23 * V_26 ;
V_26 = F_11 ( sizeof( * V_26 ) , V_27 ) ;
if ( V_26 == NULL )
return F_12 ( - V_28 ) ;
F_13 ( & V_26 -> V_24 , V_6 , & V_2 , & V_29 ) ;
V_26 -> V_24 . V_30 = 1UL << V_31 ;
V_26 -> V_6 . V_7 = V_6 -> V_7 ;
V_26 -> V_6 . V_9 = V_6 -> V_9 ;
V_26 -> V_6 . V_32 = V_6 -> V_32 ;
V_26 -> V_6 . V_33 = 0 ;
if ( V_26 -> V_6 . V_32 != NULL )
F_14 ( V_26 -> V_6 . V_32 ) ;
V_26 -> V_6 . V_12 = V_6 -> V_12 ;
V_26 -> V_6 . V_11 = V_6 -> V_11 ;
F_5 ( L_2 ,
V_26 -> V_6 . V_12 ? L_3 : L_4 ,
V_26 ,
F_15 ( & V_34 , V_6 -> V_7 ) ,
F_16 ( & V_34 , V_6 -> V_9 ) ) ;
return & V_26 -> V_24 ;
}
static void
F_17 ( struct V_1 * V_17 )
{
struct V_23 * V_26 = F_7 ( V_17 , struct V_23 , V_24 ) ;
F_5 ( L_5 , V_26 ) ;
if ( V_26 -> V_6 . V_32 != NULL )
F_18 ( V_26 -> V_6 . V_32 ) ;
F_19 ( V_26 ) ;
}
static void
F_20 ( struct V_35 * V_36 )
{
struct V_1 * V_17 = F_7 ( V_36 , struct V_1 , V_37 ) ;
F_17 ( V_17 ) ;
}
static void
F_21 ( struct V_1 * V_17 )
{
F_22 ( & V_17 -> V_37 , F_20 ) ;
}
static int
F_23 ( struct V_5 * V_6 , struct V_23 * V_26 , int V_25 )
{
if ( ! V_26 -> V_6 . V_12 ||
V_26 -> V_6 . V_11 != V_6 -> V_11 ||
! F_24 ( V_26 -> V_6 . V_7 , V_6 -> V_7 ) ||
! F_25 ( V_26 -> V_6 . V_9 , V_6 -> V_9 ) )
return 0 ;
return 1 ;
}
static int
F_26 ( struct V_5 * V_6 , struct V_1 * V_17 , int V_25 )
{
struct V_23 * V_26 = F_7 ( V_17 , struct V_23 , V_24 ) ;
int V_38 ;
if ( V_6 -> V_12 )
return F_23 ( V_6 , V_26 , V_25 ) ;
if ( ! F_24 ( V_26 -> V_6 . V_7 , V_6 -> V_7 ) ||
! F_25 ( V_26 -> V_6 . V_9 , V_6 -> V_9 ) ||
V_26 -> V_6 . V_12 != 0 )
goto V_39;
if ( V_26 -> V_6 . V_32 == V_6 -> V_32 )
goto V_40;
if ( V_26 -> V_6 . V_32 -> V_41 != V_6 -> V_32 -> V_41 )
goto V_39;
for ( V_38 = 0 ; V_38 < V_26 -> V_6 . V_32 -> V_41 ; V_38 ++ ) {
if ( ! F_25 ( F_27 ( V_26 -> V_6 . V_32 , V_38 ) ,
F_27 ( V_6 -> V_32 , V_38 ) ) )
goto V_39;
}
V_40:
return 1 ;
V_39:
return 0 ;
}
int T_1 F_28 ( void )
{
return F_29 ( & V_2 ) ;
}
void F_30 ( void )
{
F_31 ( & V_2 ) ;
}
static int
F_32 ( struct V_19 * V_20 , struct V_1 * V_17 )
{
struct V_5 * V_6 = & F_7 ( V_17 , struct V_23 ,
V_24 ) -> V_6 ;
struct V_1 * V_42 ;
int V_43 = 0 ;
if ( F_33 ( V_44 , & V_6 -> V_33 ) )
return 0 ;
if ( F_33 ( V_45 , & V_6 -> V_33 ) )
return 0 ;
V_42 = V_20 -> V_13 -> V_14 ( V_20 , V_6 , 0 ) ;
if ( F_34 ( V_42 ) )
return - V_46 ;
if ( ! V_42 -> V_47 -> V_48 ) {
F_35 ( V_44 , & V_6 -> V_33 ) ;
V_43 = 0 ;
goto V_49;
}
V_43 = V_42 -> V_47 -> V_48 ( V_42 ) ;
if ( V_43 != 0 ) {
F_35 ( V_50 , & V_6 -> V_33 ) ;
V_43 = 0 ;
} else {
if ( F_36 ( V_50 ,
& V_6 -> V_33 ) )
F_5 ( L_6 ,
F_15 ( & V_34 , V_42 -> V_51 ) ) ;
F_35 ( V_45 , & V_6 -> V_33 ) ;
}
V_49:
F_37 ( V_42 ) ;
return V_43 ;
}
static bool F_38 ( struct V_1 * V_17 )
{
struct V_5 * V_6 = & F_7 ( V_17 , struct V_23 ,
V_24 ) -> V_6 ;
bool V_43 ;
F_39 ( V_17 ) ;
V_43 = F_33 ( V_50 , & V_6 -> V_33 ) ;
F_37 ( V_17 ) ;
return V_43 ;
}
