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
static int F_6 ( struct V_3 * V_4 , int V_5 )
{
return 0 ;
}
static int F_7 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
if ( ! V_7 )
return - V_10 ;
if ( ! V_9 ) {
V_7 -> V_9 = NULL ;
return - V_10 ;
}
V_7 -> V_9 = V_9 ;
V_7 -> V_11 -> V_12 = V_13 ;
return 0 ;
}
static int F_8 ( struct V_6 * V_7 , struct V_14 * V_15 )
{
if ( ! V_7 )
return - V_10 ;
if ( ! V_15 ) {
V_7 -> V_15 = NULL ;
return - V_10 ;
}
V_7 -> V_15 = V_15 ;
return 0 ;
}
static int T_1 F_9 ( struct V_16 * V_17 )
{
struct V_18 * V_19 ;
int V_20 ;
V_19 = F_10 ( sizeof *V_19 , V_21 ) ;
if ( ! V_19 )
return - V_22 ;
V_19 -> V_11 . V_7 = F_10 ( sizeof * V_19 -> V_11 . V_7 , V_21 ) ;
if ( ! V_19 -> V_11 . V_7 ) {
F_11 ( V_19 ) ;
return - V_22 ;
}
V_19 -> V_23 = & V_17 -> V_23 ;
V_19 -> V_11 . V_23 = V_19 -> V_23 ;
V_19 -> V_11 . V_24 = L_3 ;
V_19 -> V_11 . V_25 = F_6 ;
V_19 -> V_11 . V_12 = V_26 ;
V_19 -> V_11 . V_7 -> V_11 = & V_19 -> V_11 ;
V_19 -> V_11 . V_7 -> V_27 = F_8 ;
V_19 -> V_11 . V_7 -> V_28 = F_7 ;
V_20 = F_12 ( & V_19 -> V_11 , V_29 ) ;
if ( V_20 ) {
F_13 ( & V_17 -> V_23 , L_4 ,
V_20 ) ;
goto exit;
}
F_14 ( V_17 , V_19 ) ;
F_15 ( & V_19 -> V_11 . V_30 ) ;
return 0 ;
exit:
F_11 ( V_19 -> V_11 . V_7 ) ;
F_11 ( V_19 ) ;
return V_20 ;
}
static int T_2 F_16 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = F_17 ( V_17 ) ;
F_18 ( & V_19 -> V_11 ) ;
F_14 ( V_17 , NULL ) ;
F_11 ( V_19 -> V_11 . V_7 ) ;
F_11 ( V_19 ) ;
return 0 ;
}
static int T_3 F_19 ( void )
{
return F_20 ( & V_31 ) ;
}
static void T_4 F_21 ( void )
{
F_22 ( & V_31 ) ;
}
