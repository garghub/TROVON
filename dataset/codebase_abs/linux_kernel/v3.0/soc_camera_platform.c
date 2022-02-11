static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static struct V_6 * F_4 ( struct V_7 * V_8 )
{
struct V_2 * V_3 =
F_5 ( F_6 ( V_8 ) ) ;
return V_3 -> V_9 . V_10 ;
}
static int F_7 ( struct V_4 * V_11 , int V_12 )
{
struct V_6 * V_13 = F_8 ( V_11 ) ;
return V_13 -> V_14 ( V_13 , V_12 ) ;
}
static int F_9 ( struct V_7 * V_8 ,
unsigned long V_15 )
{
return 0 ;
}
static unsigned long
F_10 ( struct V_7 * V_8 )
{
struct V_6 * V_13 = F_4 ( V_8 ) ;
return V_13 -> V_16 ;
}
static int F_11 ( struct V_4 * V_11 ,
struct V_17 * V_18 )
{
struct V_6 * V_13 = F_8 ( V_11 ) ;
V_18 -> V_19 = V_13 -> V_20 . V_19 ;
V_18 -> V_21 = V_13 -> V_20 . V_21 ;
V_18 -> V_22 = V_13 -> V_20 . V_22 ;
V_18 -> V_23 = V_13 -> V_20 . V_23 ;
V_18 -> V_24 = V_13 -> V_20 . V_24 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_11 , unsigned int V_25 ,
enum V_26 * V_22 )
{
struct V_6 * V_13 = F_8 ( V_11 ) ;
if ( V_25 )
return - V_27 ;
* V_22 = V_13 -> V_20 . V_22 ;
return 0 ;
}
static int F_13 ( struct V_4 * V_11 ,
struct V_28 * V_29 )
{
struct V_6 * V_13 = F_8 ( V_11 ) ;
V_29 -> V_30 . V_31 = 0 ;
V_29 -> V_30 . V_32 = 0 ;
V_29 -> V_30 . V_19 = V_13 -> V_20 . V_19 ;
V_29 -> V_30 . V_21 = V_13 -> V_20 . V_21 ;
V_29 -> type = V_33 ;
return 0 ;
}
static int F_14 ( struct V_4 * V_11 ,
struct V_34 * V_29 )
{
struct V_6 * V_13 = F_8 ( V_11 ) ;
V_29 -> V_35 . V_31 = 0 ;
V_29 -> V_35 . V_32 = 0 ;
V_29 -> V_35 . V_19 = V_13 -> V_20 . V_19 ;
V_29 -> V_35 . V_21 = V_13 -> V_20 . V_21 ;
V_29 -> V_36 = V_29 -> V_35 ;
V_29 -> type = V_33 ;
V_29 -> V_37 . V_38 = 1 ;
V_29 -> V_37 . V_39 = 1 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_40 * V_41 ;
struct V_1 * V_42 ;
struct V_6 * V_13 = V_3 -> V_9 . V_10 ;
struct V_7 * V_8 ;
int V_43 ;
if ( ! V_13 )
return - V_27 ;
if ( ! V_13 -> V_9 ) {
F_16 ( & V_3 -> V_9 ,
L_1 ) ;
return - V_27 ;
}
V_42 = F_17 ( sizeof( * V_42 ) , V_44 ) ;
if ( ! V_42 )
return - V_45 ;
V_8 = F_18 ( V_13 -> V_9 ) ;
F_19 ( V_3 , & V_42 -> V_5 ) ;
F_20 ( & V_8 -> V_9 , & V_3 -> V_9 ) ;
V_8 -> V_46 = & V_47 ;
V_41 = F_21 ( V_8 -> V_9 . V_48 ) ;
F_22 ( & V_42 -> V_5 , & V_49 ) ;
F_23 ( & V_42 -> V_5 , V_13 ) ;
strncpy ( V_42 -> V_5 . V_50 , F_24 ( & V_3 -> V_9 ) , V_51 ) ;
V_43 = F_25 ( & V_41 -> V_52 , & V_42 -> V_5 ) ;
if ( V_43 )
goto V_53;
return V_43 ;
V_53:
V_8 -> V_46 = NULL ;
F_19 ( V_3 , NULL ) ;
F_26 ( V_42 ) ;
return V_43 ;
}
static int F_27 ( struct V_2 * V_3 )
{
struct V_1 * V_42 = F_1 ( V_3 ) ;
struct V_6 * V_13 = V_3 -> V_9 . V_10 ;
struct V_7 * V_8 = F_18 ( V_13 -> V_9 ) ;
F_28 ( & V_42 -> V_5 ) ;
V_8 -> V_46 = NULL ;
F_19 ( V_3 , NULL ) ;
F_26 ( V_42 ) ;
return 0 ;
}
static int T_1 F_29 ( void )
{
return F_30 ( & V_54 ) ;
}
static void T_2 F_31 ( void )
{
F_32 ( & V_54 ) ;
}
