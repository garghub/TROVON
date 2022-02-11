static unsigned int F_1 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 ,
struct V_6 * V_7 )
{
return F_2 ( V_3 , V_5 , V_5 -> V_8 -> V_9 . V_10 ) ;
}
static unsigned int F_3 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_4 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static unsigned int F_5 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_6 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static unsigned int F_7 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_8 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static unsigned int F_9 ( void * V_1 ,
struct V_2 * V_3 ,
const struct V_4 * V_5 )
{
return F_10 ( V_1 , V_3 , V_5 , F_1 ) ;
}
static int T_1 F_11 ( struct V_8 * V_8 )
{
struct V_11 * V_12 ;
V_12 = F_12 ( & V_13 ) ;
if ( V_12 == NULL )
return - V_14 ;
V_8 -> V_9 . V_10 = F_13 ( V_8 , & V_13 , V_12 ) ;
F_14 ( V_12 ) ;
return F_15 ( V_8 -> V_9 . V_10 ) ;
}
static void T_2 F_16 ( struct V_8 * V_8 )
{
F_17 ( V_8 , V_8 -> V_9 . V_10 ) ;
}
static int T_3 F_18 ( void )
{
int V_15 ;
V_15 = F_19 ( & V_16 ) ;
if ( V_15 < 0 )
goto V_17;
V_15 = F_20 ( V_18 , F_21 ( V_18 ) ) ;
if ( V_15 < 0 )
goto V_19;
return 0 ;
V_19:
F_22 ( & V_16 ) ;
V_17:
return V_15 ;
}
static void T_4 F_23 ( void )
{
F_24 ( V_18 , F_21 ( V_18 ) ) ;
F_22 ( & V_16 ) ;
}
