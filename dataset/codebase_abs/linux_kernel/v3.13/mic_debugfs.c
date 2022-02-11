static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_7 * V_8 = & V_5 -> V_8 ;
F_2 ( V_8 , 0 ) ;
F_3 ( 1000 ) ;
F_2 ( V_8 , 1 ) ;
F_3 ( 1000 ) ;
F_2 ( V_8 , 2 ) ;
F_3 ( 1000 ) ;
F_2 ( V_8 , 3 ) ;
F_3 ( 1000 ) ;
return 0 ;
}
static int F_4 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_5 ( V_10 , F_1 , V_9 -> V_11 ) ;
}
static int F_6 ( struct V_9 * V_9 , struct V_10 * V_10 )
{
return F_7 ( V_9 , V_10 ) ;
}
void T_1 F_8 ( struct V_4 * V_5 )
{
struct V_12 * V_13 ;
if ( ! V_14 )
return;
V_5 -> V_15 = F_9 ( V_5 -> V_16 , V_14 ) ;
if ( ! V_5 -> V_15 ) {
F_10 ( V_5 -> V_17 , L_1 , V_5 -> V_16 ) ;
return;
}
V_13 = F_11 ( L_2 , 0444 , V_5 -> V_15 ,
V_5 , & V_18 ) ;
if ( ! V_13 ) {
F_10 ( V_5 -> V_17 ,
L_3 , V_5 -> V_16 ) ;
return;
}
}
void F_12 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_15 )
return;
F_13 ( V_5 -> V_15 ) ;
}
void T_1 F_14 ( void )
{
V_14 = F_9 ( V_19 , NULL ) ;
if ( ! V_14 )
F_15 ( L_4 ) ;
}
void F_16 ( void )
{
F_17 ( V_14 ) ;
}
