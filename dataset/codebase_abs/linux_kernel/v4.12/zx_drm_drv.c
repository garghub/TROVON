static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_2 ( V_4 -> V_6 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
F_4 ( V_4 -> V_6 ) ;
}
static int F_5 ( struct V_7 * V_8 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_9 ;
V_4 = F_6 ( V_8 , sizeof( * V_4 ) , V_10 ) ;
if ( ! V_4 )
return - V_11 ;
V_2 = F_7 ( & V_12 , V_8 ) ;
if ( F_8 ( V_2 ) )
return F_9 ( V_2 ) ;
V_2 -> V_5 = V_4 ;
F_10 ( V_8 , V_2 ) ;
F_11 ( V_2 ) ;
V_2 -> V_13 . V_14 = 16 ;
V_2 -> V_13 . V_15 = 16 ;
V_2 -> V_13 . V_16 = 4096 ;
V_2 -> V_13 . V_17 = 4096 ;
V_2 -> V_13 . V_18 = & V_19 ;
V_9 = F_12 ( V_8 , V_2 ) ;
if ( V_9 ) {
F_13 ( V_8 , L_1 , V_9 ) ;
goto V_20;
}
V_9 = F_14 ( V_2 , V_2 -> V_13 . V_21 ) ;
if ( V_9 < 0 ) {
F_13 ( V_8 , L_2 , V_9 ) ;
goto V_22;
}
V_2 -> V_23 = true ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
V_4 -> V_6 = F_17 ( V_2 , 32 ,
V_2 -> V_13 . V_24 ) ;
if ( F_8 ( V_4 -> V_6 ) ) {
V_9 = F_9 ( V_4 -> V_6 ) ;
F_13 ( V_8 , L_3 , V_9 ) ;
V_4 -> V_6 = NULL ;
goto V_25;
}
V_9 = F_18 ( V_2 , 0 ) ;
if ( V_9 )
goto V_26;
return 0 ;
V_26:
if ( V_4 -> V_6 ) {
F_19 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
V_25:
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
V_22:
F_23 ( V_8 , V_2 ) ;
V_20:
F_10 ( V_8 , NULL ) ;
V_2 -> V_5 = NULL ;
F_24 ( V_2 ) ;
return V_9 ;
}
static void F_25 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_26 ( V_8 ) ;
struct V_3 * V_4 = V_2 -> V_5 ;
F_27 ( V_2 ) ;
if ( V_4 -> V_6 ) {
F_19 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
F_20 ( V_2 ) ;
F_21 ( V_2 ) ;
F_22 ( V_2 ) ;
F_23 ( V_8 , V_2 ) ;
F_10 ( V_8 , NULL ) ;
V_2 -> V_5 = NULL ;
F_24 ( V_2 ) ;
}
static int F_28 ( struct V_7 * V_8 , void * V_27 )
{
return V_8 -> V_28 == V_27 ;
}
static int F_29 ( struct V_29 * V_30 )
{
struct V_7 * V_8 = & V_30 -> V_8 ;
struct V_31 * V_32 = V_8 -> V_28 ;
struct V_31 * V_33 ;
struct V_34 * V_35 = NULL ;
int V_9 ;
V_9 = F_30 ( V_32 , NULL , NULL , V_8 ) ;
if ( V_9 )
return V_9 ;
F_31 (parent, child) {
F_32 ( V_8 , & V_35 , F_28 , V_33 ) ;
F_33 ( V_33 ) ;
}
return F_34 ( V_8 , & V_36 , V_35 ) ;
}
static int F_35 ( struct V_29 * V_30 )
{
F_36 ( & V_30 -> V_8 , & V_36 ) ;
return 0 ;
}
static int F_37 ( void )
{
return F_38 ( V_37 , F_39 ( V_37 ) ) ;
}
static void F_40 ( void )
{
F_41 ( V_37 , F_39 ( V_37 ) ) ;
}
