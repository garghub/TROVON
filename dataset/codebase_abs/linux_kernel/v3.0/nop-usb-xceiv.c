void F_1 ( void )
{
if ( V_1 )
return;
V_1 = F_2 ( L_1 , - 1 , NULL , 0 ) ;
if ( ! V_1 ) {
F_3 ( V_2 L_2 ) ;
return;
}
}
void F_4 ( void )
{
F_5 ( V_1 ) ;
V_1 = NULL ;
}
static inline struct V_3 * F_6 ( struct V_4 * V_5 )
{
return F_7 ( V_5 , struct V_3 , V_6 ) ;
}
static int F_8 ( struct V_4 * V_5 , int V_7 )
{
return 0 ;
}
static int F_9 ( struct V_4 * V_5 ,
struct V_8 * V_9 )
{
struct V_3 * V_10 ;
if ( ! V_5 )
return - V_11 ;
V_10 = F_6 ( V_5 ) ;
if ( ! V_9 ) {
V_10 -> V_6 . V_9 = NULL ;
return - V_11 ;
}
V_10 -> V_6 . V_9 = V_9 ;
V_10 -> V_6 . V_12 = V_13 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_5 , struct V_14 * V_15 )
{
struct V_3 * V_10 ;
if ( ! V_5 )
return - V_11 ;
V_10 = F_6 ( V_5 ) ;
if ( ! V_15 ) {
V_10 -> V_6 . V_15 = NULL ;
return - V_11 ;
}
V_10 -> V_6 . V_15 = V_15 ;
return 0 ;
}
static int T_1 F_11 ( struct V_16 * V_17 )
{
struct V_3 * V_10 ;
int V_18 ;
V_10 = F_12 ( sizeof *V_10 , V_19 ) ;
if ( ! V_10 )
return - V_20 ;
V_10 -> V_21 = & V_17 -> V_21 ;
V_10 -> V_6 . V_21 = V_10 -> V_21 ;
V_10 -> V_6 . V_22 = L_3 ;
V_10 -> V_6 . V_12 = V_23 ;
V_10 -> V_6 . V_24 = F_10 ;
V_10 -> V_6 . V_25 = F_9 ;
V_10 -> V_6 . V_26 = F_8 ;
V_18 = F_13 ( & V_10 -> V_6 ) ;
if ( V_18 ) {
F_14 ( & V_17 -> V_21 , L_4 ,
V_18 ) ;
goto exit;
}
F_15 ( V_17 , V_10 ) ;
F_16 ( & V_10 -> V_6 . V_27 ) ;
return 0 ;
exit:
F_17 ( V_10 ) ;
return V_18 ;
}
static int T_2 F_18 ( struct V_16 * V_17 )
{
struct V_3 * V_10 = F_19 ( V_17 ) ;
F_13 ( NULL ) ;
F_15 ( V_17 , NULL ) ;
F_17 ( V_10 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_28 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_28 ) ;
}
