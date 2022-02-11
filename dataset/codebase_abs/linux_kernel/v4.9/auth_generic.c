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
static int
F_10 ( struct V_3 * V_4 , unsigned int V_27 )
{
return F_11 ( F_12 ( & V_28 , V_4 -> V_11 ) |
( ( V_29 ) F_13 ( & V_28 , V_4 -> V_9 ) <<
( sizeof( V_30 ) * 8 ) ) , V_27 ) ;
}
static struct V_1 *
F_14 ( struct V_21 * V_22 , struct V_3 * V_4 , int V_5 )
{
return F_4 ( & V_2 , V_4 , V_5 , V_31 ) ;
}
static struct V_1 *
F_15 ( struct V_21 * V_22 , struct V_3 * V_4 , int V_5 , T_1 V_6 )
{
struct V_25 * V_32 ;
V_32 = F_16 ( sizeof( * V_32 ) , V_6 ) ;
if ( V_32 == NULL )
return F_17 ( - V_33 ) ;
F_18 ( & V_32 -> V_26 , V_4 , & V_2 , & V_34 ) ;
V_32 -> V_26 . V_35 = 1UL << V_36 ;
V_32 -> V_4 . V_9 = V_4 -> V_9 ;
V_32 -> V_4 . V_11 = V_4 -> V_11 ;
V_32 -> V_4 . V_37 = V_4 -> V_37 ;
V_32 -> V_4 . V_38 = 0 ;
if ( V_32 -> V_4 . V_37 != NULL )
F_19 ( V_32 -> V_4 . V_37 ) ;
V_32 -> V_4 . V_14 = V_4 -> V_14 ;
V_32 -> V_4 . V_13 = V_4 -> V_13 ;
F_7 ( L_2 ,
V_32 -> V_4 . V_14 ? L_3 : L_4 ,
V_32 ,
F_13 ( & V_28 , V_4 -> V_9 ) ,
F_12 ( & V_28 , V_4 -> V_11 ) ) ;
return & V_32 -> V_26 ;
}
static void
F_20 ( struct V_1 * V_19 )
{
struct V_25 * V_32 = F_9 ( V_19 , struct V_25 , V_26 ) ;
F_7 ( L_5 , V_32 ) ;
if ( V_32 -> V_4 . V_37 != NULL )
F_21 ( V_32 -> V_4 . V_37 ) ;
F_22 ( V_32 ) ;
}
static void
F_23 ( struct V_39 * V_40 )
{
struct V_1 * V_19 = F_9 ( V_40 , struct V_1 , V_41 ) ;
F_20 ( V_19 ) ;
}
static void
F_24 ( struct V_1 * V_19 )
{
F_25 ( & V_19 -> V_41 , F_23 ) ;
}
static int
F_26 ( struct V_3 * V_4 , struct V_25 * V_32 , int V_5 )
{
if ( ! V_32 -> V_4 . V_14 ||
V_32 -> V_4 . V_13 != V_4 -> V_13 ||
! F_27 ( V_32 -> V_4 . V_9 , V_4 -> V_9 ) ||
! F_28 ( V_32 -> V_4 . V_11 , V_4 -> V_11 ) )
return 0 ;
return 1 ;
}
static int
F_29 ( struct V_3 * V_4 , struct V_1 * V_19 , int V_5 )
{
struct V_25 * V_32 = F_9 ( V_19 , struct V_25 , V_26 ) ;
int V_42 ;
if ( V_4 -> V_14 )
return F_26 ( V_4 , V_32 , V_5 ) ;
if ( ! F_27 ( V_32 -> V_4 . V_9 , V_4 -> V_9 ) ||
! F_28 ( V_32 -> V_4 . V_11 , V_4 -> V_11 ) ||
V_32 -> V_4 . V_14 != 0 )
goto V_43;
if ( V_32 -> V_4 . V_37 == V_4 -> V_37 )
goto V_44;
if ( V_32 -> V_4 . V_37 -> V_45 != V_4 -> V_37 -> V_45 )
goto V_43;
for ( V_42 = 0 ; V_42 < V_32 -> V_4 . V_37 -> V_45 ; V_42 ++ ) {
if ( ! F_28 ( V_32 -> V_4 . V_37 -> V_11 [ V_42 ] ,
V_4 -> V_37 -> V_11 [ V_42 ] ) )
goto V_43;
}
V_44:
return 1 ;
V_43:
return 0 ;
}
int T_2 F_30 ( void )
{
return F_31 ( & V_2 ) ;
}
void F_32 ( void )
{
F_33 ( & V_2 ) ;
}
static int
F_34 ( struct V_21 * V_22 , struct V_1 * V_19 )
{
struct V_3 * V_4 = & F_9 ( V_19 , struct V_25 ,
V_26 ) -> V_4 ;
struct V_1 * V_46 ;
int V_47 = 0 ;
if ( V_22 -> V_48 & V_49 )
return 0 ;
if ( F_35 ( V_50 , & V_4 -> V_38 ) )
return 0 ;
V_46 = V_22 -> V_15 -> V_16 ( V_22 , V_4 , 0 ) ;
if ( F_36 ( V_46 ) )
return - V_51 ;
V_47 = V_46 -> V_52 -> V_53 ( V_46 ) ;
if ( V_47 != 0 ) {
F_37 ( V_54 , & V_4 -> V_38 ) ;
V_47 = 0 ;
} else {
if ( F_38 ( V_54 ,
& V_4 -> V_38 ) )
F_7 ( L_6 ,
F_13 ( & V_28 , V_46 -> V_55 ) ) ;
F_37 ( V_50 , & V_4 -> V_38 ) ;
}
F_39 ( V_46 ) ;
return V_47 ;
}
static bool F_40 ( struct V_1 * V_19 )
{
struct V_3 * V_4 = & F_9 ( V_19 , struct V_25 ,
V_26 ) -> V_4 ;
bool V_47 ;
F_41 ( V_19 ) ;
V_47 = F_35 ( V_54 , & V_4 -> V_38 ) ;
F_39 ( V_19 ) ;
return V_47 ;
}
