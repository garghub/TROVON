static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( L_1 , V_7 ) ;
F_5 ( V_4 -> V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_7 ( V_2 -> V_10 ) ;
struct V_11 * V_6 ;
struct V_3 * V_4 ;
int V_12 ;
F_4 ( L_1 , V_7 ) ;
V_4 = F_8 ( V_2 -> V_10 , sizeof( * V_4 ) , V_13 ) ;
if ( ! V_4 )
return - V_14 ;
V_2 -> V_5 = ( void * ) V_4 ;
F_9 ( V_2 ) ;
V_2 -> V_15 . V_16 = 0 ;
V_2 -> V_15 . V_17 = 0 ;
V_2 -> V_15 . V_18 = V_19 ;
V_2 -> V_15 . V_20 = V_21 ;
V_2 -> V_15 . V_22 = & V_23 ;
V_12 = F_10 ( V_2 ) ;
if ( V_12 )
goto V_24;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
if ( V_2 -> V_15 . V_25 ) {
V_4 = V_2 -> V_5 ;
V_6 = F_13 ( V_2 , 16 ,
V_2 -> V_15 . V_25 ) ;
if ( F_14 ( V_6 ) ) {
F_4 ( L_2 ) ;
V_6 = NULL ;
}
V_4 -> V_6 = V_6 ;
}
F_15 ( V_9 , V_2 ) ;
return 0 ;
V_24:
F_16 ( V_2 ) ;
return V_12 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( L_1 , V_7 ) ;
if ( V_4 -> V_6 ) {
F_18 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_19 ( V_2 ) ;
F_20 ( V_2 ) ;
F_16 ( V_2 ) ;
}
static int F_21 ( struct V_8 * V_9 )
{
struct V_26 * V_10 = & V_9 -> V_10 ;
struct V_1 * V_2 ;
int V_12 ;
F_4 ( L_1 , V_7 ) ;
F_22 ( V_10 , F_23 ( 32 ) ) ;
V_2 = F_24 ( & V_27 , V_10 ) ;
if ( F_14 ( V_2 ) )
return F_25 ( V_2 ) ;
V_12 = F_6 ( V_2 ) ;
if ( V_12 )
goto V_28;
V_12 = F_26 ( V_2 , 0 ) ;
if ( V_12 )
goto V_28;
return 0 ;
V_28:
F_27 ( V_2 ) ;
return V_12 ;
}
static int F_28 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_29 ( V_9 ) ;
F_4 ( L_1 , V_7 ) ;
F_30 ( V_2 ) ;
F_17 ( V_2 ) ;
F_27 ( V_2 ) ;
return 0 ;
}
