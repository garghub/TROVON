static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 ) {
F_2 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_3 ( V_2 ) ;
V_7 -> V_8 ( F_4 ( V_2 -> V_2 ) ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_2 , V_4 ) ;
V_2 -> V_5 = NULL ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_8 ( V_4 -> V_6 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
V_2 -> V_9 . V_10 = 0 ;
V_2 -> V_9 . V_11 = 0 ;
V_2 -> V_9 . V_12 = 2048 ;
V_2 -> V_9 . V_13 = 2048 ;
V_2 -> V_9 . V_14 = & V_15 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
int V_16 ;
V_4 = F_11 ( V_2 -> V_2 , sizeof( * V_4 ) , V_17 ) ;
if ( ! V_4 )
return - V_18 ;
V_2 -> V_5 = V_4 ;
F_12 ( V_2 -> V_2 , V_2 ) ;
F_13 ( V_2 ) ;
F_9 ( V_2 ) ;
V_16 = V_7 -> V_19 ( F_4 ( V_2 -> V_2 ) ) ;
if ( V_16 )
goto V_20;
V_16 = F_14 ( V_2 -> V_2 , V_2 ) ;
if ( V_16 ) {
F_15 ( L_1 ) ;
goto V_21;
}
V_16 = F_16 ( V_2 , V_2 -> V_9 . V_22 ) ;
if ( V_16 ) {
F_15 ( L_2 ) ;
goto V_23;
}
V_2 -> V_24 = true ;
F_17 ( V_2 ) ;
F_18 ( V_2 ) ;
V_4 -> V_6 = F_19 ( V_2 , 32 ,
V_2 -> V_9 . V_25 ) ;
if ( F_20 ( V_4 -> V_6 ) ) {
F_15 ( L_3 ) ;
V_16 = F_21 ( V_4 -> V_6 ) ;
goto V_26;
}
return 0 ;
V_26:
F_3 ( V_2 ) ;
V_23:
F_22 ( V_2 -> V_2 , V_2 ) ;
V_21:
V_7 -> V_8 ( F_4 ( V_2 -> V_2 ) ) ;
V_20:
F_5 ( V_2 ) ;
F_6 ( V_2 -> V_2 , V_4 ) ;
V_2 -> V_5 = NULL ;
return V_16 ;
}
static int F_23 ( struct V_27 * V_28 ,
struct V_1 * V_2 ,
struct V_29 * args )
{
return F_24 ( V_28 , V_2 , args ) ;
}
static int F_25 ( struct V_30 * V_2 , void * V_31 )
{
return V_2 -> V_32 == V_31 ;
}
static int F_26 ( struct V_30 * V_2 )
{
struct V_33 * V_34 = & V_35 ;
struct V_1 * V_36 ;
int V_16 ;
V_36 = F_27 ( V_34 , V_2 ) ;
if ( F_20 ( V_36 ) )
return F_21 ( V_36 ) ;
V_16 = F_10 ( V_36 ) ;
if ( V_16 )
goto V_37;
V_16 = F_28 ( V_36 , 0 ) ;
if ( V_16 )
goto V_38;
return 0 ;
V_38:
F_1 ( V_36 ) ;
V_37:
F_29 ( V_36 ) ;
return V_16 ;
}
static void F_30 ( struct V_30 * V_2 )
{
struct V_1 * V_36 = F_31 ( V_2 ) ;
F_32 ( V_36 ) ;
F_1 ( V_36 ) ;
F_29 ( V_36 ) ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_30 * V_2 = & V_40 -> V_2 ;
struct V_41 * V_42 = V_2 -> V_32 ;
struct V_43 * V_44 = NULL ;
struct V_41 * V_45 ;
V_7 = (struct V_46 * ) F_34 ( V_2 ) ;
if ( ! V_7 ) {
F_15 ( L_4 ) ;
return - V_47 ;
}
V_45 = F_35 ( V_42 , 0 , 0 ) ;
if ( F_20 ( V_45 ) )
return F_21 ( V_45 ) ;
F_36 ( V_2 , & V_44 , F_25 , V_45 ) ;
F_37 ( V_45 ) ;
return F_38 ( V_2 , & V_48 , V_44 ) ;
return 0 ;
}
static int F_39 ( struct V_39 * V_40 )
{
F_40 ( & V_40 -> V_2 , & V_48 ) ;
V_7 = NULL ;
return 0 ;
}
