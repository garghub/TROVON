static unsigned int F_1 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
struct V_8 * V_9 )
{
struct V_10 * V_10 = F_2 ( V_9 ) ;
return F_3 ( V_4 , V_2 -> V_11 , V_6 , V_7 , V_10 -> V_12 . V_13 ) ;
}
static unsigned int F_4 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_6 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static unsigned int F_7 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_8 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static unsigned int F_9 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_10 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static unsigned int F_11 ( const struct V_1 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_5 * V_7 ,
int (* F_5)( struct V_3 * ) )
{
return F_12 ( V_2 , V_4 , V_6 , V_7 , F_1 ) ;
}
static int T_1 F_13 ( struct V_10 * V_10 )
{
struct V_14 * V_15 ;
V_15 = F_14 ( & V_16 ) ;
if ( V_15 == NULL )
return - V_17 ;
V_10 -> V_12 . V_13 = F_15 ( V_10 , & V_16 , V_15 ) ;
F_16 ( V_15 ) ;
return F_17 ( V_10 -> V_12 . V_13 ) ;
}
static void T_2 F_18 ( struct V_10 * V_10 )
{
F_19 ( V_10 , V_10 -> V_12 . V_13 ) ;
}
static int T_3 F_20 ( void )
{
int V_18 ;
V_18 = F_21 ( & V_19 ) ;
if ( V_18 < 0 )
goto V_20;
V_18 = F_22 ( V_21 , F_23 ( V_21 ) ) ;
if ( V_18 < 0 )
goto V_22;
return 0 ;
V_22:
F_24 ( & V_19 ) ;
V_20:
return V_18 ;
}
static void T_4 F_25 ( void )
{
F_26 ( V_21 , F_23 ( V_21 ) ) ;
F_24 ( & V_19 ) ;
}
