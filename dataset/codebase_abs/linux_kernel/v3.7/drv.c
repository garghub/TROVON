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
if ( F_6 ( V_8 , V_8 -> V_14 ) )
goto V_15;
return 0 ;
V_15:
F_7 ( V_10 -> V_12 ) ;
V_13:
F_8 ( V_8 ) ;
F_3 ( V_2 , NULL ) ;
return - V_16 ;
}
static void T_1 F_9 ( struct V_1 * V_2 )
{
struct V_8 * V_17 = F_10 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_17 ) ;
F_7 ( V_10 -> V_12 ) ;
F_8 ( V_17 ) ;
F_3 ( V_2 , NULL ) ;
}
static int F_11 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
struct V_8 * V_8 = F_10 ( V_2 ) ;
return F_13 ( V_8 ) ;
}
static int F_14 ( struct V_18 * V_18 )
{
struct V_1 * V_2 = F_12 ( V_18 ) ;
struct V_8 * V_8 = F_10 ( V_2 ) ;
F_15 ( V_2 , V_19 , 0x00 ) ;
return F_16 ( V_8 ) ;
}
int T_2 F_17 ( void )
{
int V_20 ;
V_20 = F_18 ( & V_21 ) ;
if ( V_20 )
F_19 ( L_1 ) ;
return V_20 ;
}
void F_20 ( void )
{
F_21 ( & V_21 ) ;
}
