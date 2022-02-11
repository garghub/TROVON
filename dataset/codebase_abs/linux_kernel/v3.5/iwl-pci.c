static int F_1 ( struct V_1 * V_2 , const struct V_3 * V_4 )
{
const struct V_5 * V_6 = (struct V_5 * ) ( V_4 -> V_7 ) ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
V_8 = F_2 ( V_2 , V_4 , V_6 ) ;
if ( V_8 == NULL )
return - V_11 ;
F_3 ( V_2 , V_8 ) ;
V_10 = F_4 ( V_8 ) ;
V_10 -> V_12 = F_5 ( V_8 , V_6 ) ;
if ( ! V_10 -> V_12 )
goto V_13;
return 0 ;
V_13:
F_6 ( V_8 ) ;
F_3 ( V_2 , NULL ) ;
return - V_14 ;
}
static void T_1 F_7 ( struct V_1 * V_2 )
{
struct V_8 * V_15 = F_8 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_15 ) ;
F_9 ( V_10 -> V_12 ) ;
F_6 ( V_15 ) ;
F_3 ( V_2 , NULL ) ;
}
static int F_10 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_8 * V_8 = F_8 ( V_2 ) ;
return F_12 ( V_8 ) ;
}
static int F_13 ( struct V_16 * V_16 )
{
struct V_1 * V_2 = F_11 ( V_16 ) ;
struct V_8 * V_8 = F_8 ( V_2 ) ;
F_14 ( V_2 , V_17 , 0x00 ) ;
return F_15 ( V_8 ) ;
}
int T_2 F_16 ( void )
{
int V_18 ;
V_18 = F_17 ( & V_19 ) ;
if ( V_18 )
F_18 ( L_1 ) ;
return V_18 ;
}
void F_19 ( void )
{
F_20 ( & V_19 ) ;
}
