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
V_7 -> V_8 ( F_6 ( V_2 -> V_2 ) ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 -> V_2 , V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 ) {
F_10 ( V_4 -> V_6 ) ;
} else {
V_4 -> V_6 = F_11 ( V_2 , 32 ,
V_2 -> V_9 . V_10 ) ;
if ( F_12 ( V_4 -> V_6 ) )
V_4 -> V_6 = NULL ;
}
}
static void F_13 ( struct V_1 * V_2 )
{
V_2 -> V_9 . V_11 = 0 ;
V_2 -> V_9 . V_12 = 0 ;
V_2 -> V_9 . V_13 = 2048 ;
V_2 -> V_9 . V_14 = 2048 ;
V_2 -> V_9 . V_15 = & V_16 ;
}
static int F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_17 ;
V_4 = F_15 ( V_2 -> V_2 , sizeof( * V_4 ) , V_18 ) ;
if ( ! V_4 )
return - V_19 ;
V_2 -> V_5 = V_4 ;
F_16 ( V_2 -> V_2 , V_2 ) ;
F_17 ( V_2 ) ;
F_13 ( V_2 ) ;
V_17 = V_7 -> V_20 ( F_6 ( V_2 -> V_2 ) ) ;
if ( V_17 )
goto V_21;
V_17 = F_18 ( V_2 -> V_2 , V_2 ) ;
if ( V_17 ) {
F_19 ( L_1 ) ;
goto V_22;
}
V_17 = F_20 ( V_2 , V_2 -> V_9 . V_23 ) ;
if ( V_17 ) {
F_19 ( L_2 ) ;
goto V_24;
}
V_2 -> V_25 = true ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
( void ) F_23 ( V_2 ) ;
return 0 ;
V_24:
F_24 ( V_2 -> V_2 , V_2 ) ;
V_22:
V_7 -> V_8 ( F_6 ( V_2 -> V_2 ) ) ;
V_21:
F_7 ( V_2 ) ;
F_8 ( V_2 -> V_2 , V_4 ) ;
V_2 -> V_5 = NULL ;
return V_17 ;
}
static int F_25 ( struct V_26 * V_27 ,
struct V_1 * V_2 ,
struct V_28 * args )
{
return F_26 ( V_27 , V_2 , args ) ;
}
static int F_27 ( struct V_29 * V_2 , void * V_30 )
{
return V_2 -> V_31 == V_30 ;
}
static int F_28 ( struct V_29 * V_2 )
{
struct V_32 * V_33 = & V_34 ;
struct V_1 * V_35 ;
int V_17 ;
V_35 = F_29 ( V_33 , V_2 ) ;
if ( F_12 ( V_35 ) )
return F_30 ( V_35 ) ;
V_17 = F_14 ( V_35 ) ;
if ( V_17 )
goto V_36;
V_17 = F_31 ( V_35 , 0 ) ;
if ( V_17 )
goto V_37;
return 0 ;
V_37:
F_1 ( V_35 ) ;
V_36:
F_32 ( V_35 ) ;
return V_17 ;
}
static void F_33 ( struct V_29 * V_2 )
{
struct V_1 * V_35 = F_34 ( V_2 ) ;
F_35 ( V_35 ) ;
F_1 ( V_35 ) ;
F_32 ( V_35 ) ;
}
static int F_36 ( struct V_38 * V_39 )
{
struct V_29 * V_2 = & V_39 -> V_2 ;
struct V_40 * V_41 = V_2 -> V_31 ;
struct V_42 * V_43 = NULL ;
struct V_40 * V_44 ;
V_7 = (struct V_45 * ) F_37 ( V_2 ) ;
if ( ! V_7 ) {
F_19 ( L_3 ) ;
return - V_46 ;
}
V_44 = F_38 ( V_41 , 0 , 0 ) ;
if ( F_12 ( V_44 ) )
return F_30 ( V_44 ) ;
F_39 ( V_2 , & V_43 , F_27 , V_44 ) ;
F_40 ( V_44 ) ;
return F_41 ( V_2 , & V_47 , V_43 ) ;
return 0 ;
}
static int F_42 ( struct V_38 * V_39 )
{
F_43 ( & V_39 -> V_2 , & V_47 ) ;
V_7 = NULL ;
return 0 ;
}
