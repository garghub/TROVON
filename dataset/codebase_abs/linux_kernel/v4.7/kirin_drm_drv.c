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
if ( ! V_35 )
return - V_20 ;
V_35 -> V_36 = F_29 ( V_2 ) ;
V_18 = F_13 ( V_35 ) ;
if ( V_18 )
goto V_37;
V_18 = F_30 ( V_35 , 0 ) ;
if ( V_18 )
goto V_38;
V_18 = F_31 ( V_35 ) ;
if ( V_18 )
goto V_39;
F_32 ( L_3 ,
V_33 -> V_40 , V_33 -> V_41 , V_33 -> V_42 , V_33 -> V_43 ,
V_33 -> V_44 , V_35 -> V_45 -> V_46 ) ;
return 0 ;
V_39:
F_33 ( V_35 ) ;
V_38:
F_1 ( V_35 ) ;
V_37:
F_34 ( V_35 ) ;
return V_18 ;
}
static void F_35 ( struct V_29 * V_2 )
{
struct V_1 * V_35 = F_36 ( V_2 ) ;
F_37 ( V_35 ) ;
F_33 ( V_35 ) ;
F_1 ( V_35 ) ;
F_34 ( V_35 ) ;
}
static struct V_47 * F_38 ( struct V_47 * V_48 )
{
struct V_47 * V_49 , * V_50 ;
V_49 = F_39 ( V_48 , NULL ) ;
if ( ! V_49 ) {
F_18 ( L_4 ) ;
return F_40 ( - V_51 ) ;
}
F_41 ( V_49 ) ;
V_50 = F_42 ( V_49 ) ;
if ( ! V_50 ) {
F_18 ( L_5 ) ;
return F_40 ( - V_51 ) ;
}
F_41 ( V_50 ) ;
if ( ! F_43 ( V_50 ) ) {
F_18 ( L_6 ) ;
return F_40 ( - V_51 ) ;
}
return V_50 ;
}
static int F_44 ( struct V_52 * V_53 )
{
struct V_29 * V_2 = & V_53 -> V_2 ;
struct V_47 * V_48 = V_2 -> V_31 ;
struct V_54 * V_55 = NULL ;
struct V_47 * V_50 ;
V_7 = (struct V_56 * ) F_45 ( V_2 ) ;
if ( ! V_7 ) {
F_18 ( L_7 ) ;
return - V_57 ;
}
V_50 = F_38 ( V_48 ) ;
if ( F_11 ( V_50 ) )
return F_46 ( V_50 ) ;
F_47 ( V_2 , & V_55 , F_26 , V_50 ) ;
return F_48 ( V_2 , & V_58 , V_55 ) ;
return 0 ;
}
static int F_49 ( struct V_52 * V_53 )
{
F_50 ( & V_53 -> V_2 , & V_58 ) ;
V_7 = NULL ;
return 0 ;
}
