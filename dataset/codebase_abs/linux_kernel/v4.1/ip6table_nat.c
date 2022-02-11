static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_9 = F_2 ( V_8 ) ;
return F_3 ( V_4 , V_2 -> V_10 , V_6 , V_9 -> V_11 . V_12 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_5 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static unsigned int F_6 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_7 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static unsigned int F_8 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_9 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static unsigned int F_10 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 )
{
return F_11 ( V_2 , V_4 , V_6 , F_1 ) ;
}
static int T_1 F_12 ( struct V_9 * V_9 )
{
struct V_13 * V_14 ;
V_14 = F_13 ( & V_15 ) ;
if ( V_14 == NULL )
return - V_16 ;
V_9 -> V_11 . V_12 = F_14 ( V_9 , & V_15 , V_14 ) ;
F_15 ( V_14 ) ;
return F_16 ( V_9 -> V_11 . V_12 ) ;
}
static void T_2 F_17 ( struct V_9 * V_9 )
{
F_18 ( V_9 , V_9 -> V_11 . V_12 ) ;
}
static int T_3 F_19 ( void )
{
int V_17 ;
V_17 = F_20 ( & V_18 ) ;
if ( V_17 < 0 )
goto V_19;
V_17 = F_21 ( V_20 , F_22 ( V_20 ) ) ;
if ( V_17 < 0 )
goto V_21;
return 0 ;
V_21:
F_23 ( & V_18 ) ;
V_19:
return V_17 ;
}
static void T_4 F_24 ( void )
{
F_25 ( V_20 , F_22 ( V_20 ) ) ;
F_23 ( & V_18 ) ;
}
