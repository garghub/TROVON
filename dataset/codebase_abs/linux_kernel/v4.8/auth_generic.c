struct V_1 * F_1 ( void )
{
return F_2 ( & V_2 , 0 ) ;
}
struct V_1 *
F_3 ( struct V_3 * V_4 , int V_5 , T_1 V_6 )
{
return F_4 ( & V_2 , V_4 , V_5 , V_6 ) ;
}
struct V_1 * F_5 ( void )
{
return F_2 ( & V_2 , V_7 ) ;
}
struct V_1 * F_6 ( const char * V_8 )
{
struct V_3 V_4 = {
. V_9 = V_10 ,
. V_11 = V_12 ,
. V_13 = V_8 ,
. V_14 = 1 ,
} ;
F_7 ( L_1 ,
V_8 ) ;
return V_2 . V_15 -> V_16 ( & V_2 , & V_4 , 0 ) ;
}
static struct V_1 * F_8 ( struct V_17 * V_18 ,
struct V_1 * V_19 , int V_20 )
{
struct V_21 * V_22 = V_18 -> V_23 -> V_24 ;
struct V_3 * V_4 = & F_9 ( V_19 , struct V_25 , V_26 ) -> V_4 ;
return V_22 -> V_15 -> V_16 ( V_22 , V_4 , V_20 ) ;
}
static struct V_1 *
F_10 ( struct V_21 * V_22 , struct V_3 * V_4 , int V_5 )
{
return F_4 ( & V_2 , V_4 , V_5 , V_27 ) ;
}
static struct V_1 *
F_11 ( struct V_21 * V_22 , struct V_3 * V_4 , int V_5 , T_1 V_6 )
{
struct V_25 * V_28 ;
V_28 = F_12 ( sizeof( * V_28 ) , V_6 ) ;
if ( V_28 == NULL )
return F_13 ( - V_29 ) ;
F_14 ( & V_28 -> V_26 , V_4 , & V_2 , & V_30 ) ;
V_28 -> V_26 . V_31 = 1UL << V_32 ;
V_28 -> V_4 . V_9 = V_4 -> V_9 ;
V_28 -> V_4 . V_11 = V_4 -> V_11 ;
V_28 -> V_4 . V_33 = V_4 -> V_33 ;
V_28 -> V_4 . V_34 = 0 ;
if ( V_28 -> V_4 . V_33 != NULL )
F_15 ( V_28 -> V_4 . V_33 ) ;
V_28 -> V_4 . V_14 = V_4 -> V_14 ;
V_28 -> V_4 . V_13 = V_4 -> V_13 ;
F_7 ( L_2 ,
V_28 -> V_4 . V_14 ? L_3 : L_4 ,
V_28 ,
F_16 ( & V_35 , V_4 -> V_9 ) ,
F_17 ( & V_35 , V_4 -> V_11 ) ) ;
return & V_28 -> V_26 ;
}
static void
F_18 ( struct V_1 * V_19 )
{
struct V_25 * V_28 = F_9 ( V_19 , struct V_25 , V_26 ) ;
F_7 ( L_5 , V_28 ) ;
if ( V_28 -> V_4 . V_33 != NULL )
F_19 ( V_28 -> V_4 . V_33 ) ;
F_20 ( V_28 ) ;
}
static void
F_21 ( struct V_36 * V_37 )
{
struct V_1 * V_19 = F_9 ( V_37 , struct V_1 , V_38 ) ;
F_18 ( V_19 ) ;
}
static void
F_22 ( struct V_1 * V_19 )
{
F_23 ( & V_19 -> V_38 , F_21 ) ;
}
static int
F_24 ( struct V_3 * V_4 , struct V_25 * V_28 , int V_5 )
{
if ( ! V_28 -> V_4 . V_14 ||
V_28 -> V_4 . V_13 != V_4 -> V_13 ||
! F_25 ( V_28 -> V_4 . V_9 , V_4 -> V_9 ) ||
! F_26 ( V_28 -> V_4 . V_11 , V_4 -> V_11 ) )
return 0 ;
return 1 ;
}
static int
F_27 ( struct V_3 * V_4 , struct V_1 * V_19 , int V_5 )
{
struct V_25 * V_28 = F_9 ( V_19 , struct V_25 , V_26 ) ;
int V_39 ;
if ( V_4 -> V_14 )
return F_24 ( V_4 , V_28 , V_5 ) ;
if ( ! F_25 ( V_28 -> V_4 . V_9 , V_4 -> V_9 ) ||
! F_26 ( V_28 -> V_4 . V_11 , V_4 -> V_11 ) ||
V_28 -> V_4 . V_14 != 0 )
goto V_40;
if ( V_28 -> V_4 . V_33 == V_4 -> V_33 )
goto V_41;
if ( V_28 -> V_4 . V_33 -> V_42 != V_4 -> V_33 -> V_42 )
goto V_40;
for ( V_39 = 0 ; V_39 < V_28 -> V_4 . V_33 -> V_42 ; V_39 ++ ) {
if ( ! F_26 ( F_28 ( V_28 -> V_4 . V_33 , V_39 ) ,
F_28 ( V_4 -> V_33 , V_39 ) ) )
goto V_40;
}
V_41:
return 1 ;
V_40:
return 0 ;
}
int T_2 F_29 ( void )
{
return F_30 ( & V_2 ) ;
}
void F_31 ( void )
{
F_32 ( & V_2 ) ;
}
static int
F_33 ( struct V_21 * V_22 , struct V_1 * V_19 )
{
struct V_3 * V_4 = & F_9 ( V_19 , struct V_25 ,
V_26 ) -> V_4 ;
struct V_1 * V_43 ;
int V_44 = 0 ;
if ( V_22 -> V_45 & V_46 )
return 0 ;
if ( F_34 ( V_47 , & V_4 -> V_34 ) )
return 0 ;
V_43 = V_22 -> V_15 -> V_16 ( V_22 , V_4 , 0 ) ;
if ( F_35 ( V_43 ) )
return - V_48 ;
V_44 = V_43 -> V_49 -> V_50 ( V_43 ) ;
if ( V_44 != 0 ) {
F_36 ( V_51 , & V_4 -> V_34 ) ;
V_44 = 0 ;
} else {
if ( F_37 ( V_51 ,
& V_4 -> V_34 ) )
F_7 ( L_6 ,
F_16 ( & V_35 , V_43 -> V_52 ) ) ;
F_36 ( V_47 , & V_4 -> V_34 ) ;
}
F_38 ( V_43 ) ;
return V_44 ;
}
static bool F_39 ( struct V_1 * V_19 )
{
struct V_3 * V_4 = & F_9 ( V_19 , struct V_25 ,
V_26 ) -> V_4 ;
bool V_44 ;
F_40 ( V_19 ) ;
V_44 = F_34 ( V_51 , & V_4 -> V_34 ) ;
F_38 ( V_19 ) ;
return V_44 ;
}
