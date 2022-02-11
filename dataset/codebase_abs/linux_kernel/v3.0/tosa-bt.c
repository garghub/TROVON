static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 0 ) ;
F_2 ( V_2 -> V_4 , 1 ) ;
F_2 ( V_2 -> V_3 , 1 ) ;
F_3 ( 20 ) ;
F_2 ( V_2 -> V_3 , 0 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 1 ) ;
F_3 ( 10 ) ;
F_2 ( V_2 -> V_4 , 0 ) ;
F_2 ( V_2 -> V_3 , 0 ) ;
}
static int F_5 ( void * V_2 , bool V_5 )
{
F_6 ( L_1 , V_5 ? L_2 : L_3 ) ;
if ( ! V_5 ) {
F_6 ( L_4 ) ;
F_1 ( V_2 ) ;
} else {
F_6 ( L_5 ) ;
F_4 ( V_2 ) ;
}
return 0 ;
}
static int F_7 ( struct V_6 * V_7 )
{
int V_8 ;
struct V_9 * V_10 ;
struct V_1 * V_2 = V_7 -> V_7 . V_11 ;
V_8 = F_8 ( V_2 -> V_3 , L_6 ) ;
if ( V_8 )
goto V_12;
V_8 = F_9 ( V_2 -> V_3 , 0 ) ;
if ( V_8 )
goto V_13;
V_8 = F_8 ( V_2 -> V_4 , L_7 ) ;
if ( V_8 )
goto V_14;
V_8 = F_9 ( V_2 -> V_4 , 0 ) ;
if ( V_8 )
goto V_15;
V_10 = F_10 ( L_8 , & V_7 -> V_7 , V_16 ,
& V_17 , V_2 ) ;
if ( ! V_10 ) {
V_8 = - V_18 ;
goto V_19;
}
V_8 = F_11 ( V_10 ) ;
if ( V_8 )
goto V_20;
F_12 ( V_7 , V_10 ) ;
return 0 ;
V_20:
F_13 ( V_10 ) ;
V_19:
F_4 ( V_2 ) ;
V_15:
F_14 ( V_2 -> V_4 ) ;
V_14:
V_13:
F_14 ( V_2 -> V_3 ) ;
V_12:
return V_8 ;
}
static int T_1 F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = V_7 -> V_7 . V_11 ;
struct V_9 * V_10 = F_16 ( V_7 ) ;
F_12 ( V_7 , NULL ) ;
if ( V_10 ) {
F_17 ( V_10 ) ;
F_13 ( V_10 ) ;
}
V_10 = NULL ;
F_4 ( V_2 ) ;
F_14 ( V_2 -> V_4 ) ;
F_14 ( V_2 -> V_3 ) ;
return 0 ;
}
static int T_2 F_18 ( void )
{
return F_19 ( & V_21 ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( & V_21 ) ;
}
