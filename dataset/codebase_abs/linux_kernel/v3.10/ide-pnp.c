static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
unsigned long V_7 , V_8 ;
int V_9 ;
struct V_10 V_11 , * V_12 [] = { & V_11 } ;
F_2 (KERN_INFO DRV_NAME L_1 ) ;
if ( ! ( F_3 ( V_2 , 0 ) && F_3 ( V_2 , 1 ) && F_4 ( V_2 , 0 ) ) )
return - 1 ;
V_7 = F_5 ( V_2 , 0 ) ;
V_8 = F_5 ( V_2 , 1 ) ;
if ( ! F_6 ( V_7 , 8 , V_13 ) ) {
F_2 ( V_14 L_2 ,
V_13 , V_7 , V_7 + 7 ) ;
return - V_15 ;
}
if ( ! F_6 ( V_8 , 1 , V_13 ) ) {
F_2 ( V_14 L_3 ,
V_13 , V_8 ) ;
F_7 ( V_7 , 8 ) ;
return - V_15 ;
}
memset ( & V_11 , 0 , sizeof( V_11 ) ) ;
F_8 ( & V_11 , V_7 , V_8 ) ;
V_11 . V_16 = F_9 ( V_2 , 0 ) ;
V_9 = F_10 ( & V_17 , V_12 , 1 , & V_6 ) ;
if ( V_9 )
goto V_18;
F_11 ( V_2 , V_6 ) ;
return 0 ;
V_18:
F_7 ( V_8 , 1 ) ;
F_7 ( V_7 , 8 ) ;
return V_9 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_13 ( V_2 ) ;
F_14 ( V_6 ) ;
F_7 ( F_5 ( V_2 , 1 ) , 1 ) ;
F_7 ( F_5 ( V_2 , 0 ) , 8 ) ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_19 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_19 ) ;
}
