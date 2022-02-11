static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
#ifdef F_2
if ( V_4 -> V_6 ) {
F_3 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
#endif
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
V_7 -> V_8 ( V_2 ) ;
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_2 , V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 ) {
F_9 ( V_4 -> V_6 ) ;
} else {
V_4 -> V_6 = F_10 ( V_2 , 32 ,
V_2 -> V_9 . V_10 ,
V_2 -> V_9 . V_11 ) ;
if ( F_11 ( V_4 -> V_6 ) )
V_4 -> V_6 = NULL ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
V_2 -> V_9 . V_12 = 0 ;
V_2 -> V_9 . V_13 = 0 ;
V_2 -> V_9 . V_14 = 2048 ;
V_2 -> V_9 . V_15 = 2048 ;
V_2 -> V_9 . V_16 = & V_17 ;
}
static int F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_18 ;
V_4 = F_14 ( V_2 -> V_2 , sizeof( * V_4 ) , V_19 ) ;
if ( ! V_4 )
return - V_20 ;
V_2 -> V_5 = V_4 ;
F_15 ( V_2 -> V_2 , V_2 ) ;
F_16 ( V_2 ) ;
F_12 ( V_2 ) ;
V_18 = V_7 -> V_21 ( V_2 ) ;
if ( V_18 )
goto V_22;
V_18 = F_17 ( V_2 -> V_2 , V_2 ) ;
if ( V_18 ) {
F_18 ( L_1 ) ;
goto V_23;
}
V_18 = F_19 ( V_2 , V_2 -> V_9 . V_10 ) ;
if ( V_18 ) {
F_18 ( L_2 ) ;
goto V_24;
}
V_2 -> V_25 = true ;
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
( void ) F_22 ( V_2 ) ;
return 0 ;
V_24:
F_23 ( V_2 -> V_2 , V_2 ) ;
V_23:
V_7 -> V_8 ( V_2 ) ;
V_22:
F_6 ( V_2 ) ;
F_7 ( V_2 -> V_2 , V_4 ) ;
V_2 -> V_5 = NULL ;
return V_18 ;
}
static int F_24 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_28 * args )
{
return F_25 ( V_27 , V_2 , args ) ;
}
static int F_26 ( struct V_29 * V_2 , void * V_30 )
{
return V_2 -> V_31 == V_30 ;
}
static int F_27 ( struct V_29 * V_2 )
{
struct V_32 * V_33 = & V_34 ;
struct V_1 * V_35 ;
int V_18 ;
V_35 = F_28 ( V_33 , V_2 ) ;
if ( F_11 ( V_35 ) )
return F_29 ( V_35 ) ;
V_35 -> V_36 = F_30 ( V_2 ) ;
V_18 = F_13 ( V_35 ) ;
if ( V_18 )
goto V_37;
V_18 = F_31 ( V_35 , 0 ) ;
if ( V_18 )
goto V_38;
F_32 ( L_3 ,
V_33 -> V_39 , V_33 -> V_40 , V_33 -> V_41 , V_33 -> V_42 ,
V_33 -> V_43 , V_35 -> V_44 -> V_45 ) ;
return 0 ;
V_38:
F_1 ( V_35 ) ;
V_37:
F_33 ( V_35 ) ;
return V_18 ;
}
static void F_34 ( struct V_29 * V_2 )
{
struct V_1 * V_35 = F_35 ( V_2 ) ;
F_36 ( V_35 ) ;
F_1 ( V_35 ) ;
F_33 ( V_35 ) ;
}
static struct V_46 * F_37 ( struct V_46 * V_47 )
{
struct V_46 * V_48 , * V_49 ;
V_48 = F_38 ( V_47 , NULL ) ;
if ( ! V_48 ) {
F_18 ( L_4 ) ;
return F_39 ( - V_50 ) ;
}
F_40 ( V_48 ) ;
V_49 = F_41 ( V_48 ) ;
if ( ! V_49 ) {
F_18 ( L_5 ) ;
return F_39 ( - V_50 ) ;
}
F_40 ( V_49 ) ;
if ( ! F_42 ( V_49 ) ) {
F_18 ( L_6 ) ;
return F_39 ( - V_50 ) ;
}
return V_49 ;
}
static int F_43 ( struct V_51 * V_52 )
{
struct V_29 * V_2 = & V_52 -> V_2 ;
struct V_46 * V_47 = V_2 -> V_31 ;
struct V_53 * V_54 = NULL ;
struct V_46 * V_49 ;
V_7 = (struct V_55 * ) F_44 ( V_2 ) ;
if ( ! V_7 ) {
F_18 ( L_7 ) ;
return - V_56 ;
}
V_49 = F_37 ( V_47 ) ;
if ( F_11 ( V_49 ) )
return F_29 ( V_49 ) ;
F_45 ( V_2 , & V_54 , F_26 , V_49 ) ;
return F_46 ( V_2 , & V_57 , V_54 ) ;
return 0 ;
}
static int F_47 ( struct V_51 * V_52 )
{
F_48 ( & V_52 -> V_2 , & V_57 ) ;
V_7 = NULL ;
return 0 ;
}
