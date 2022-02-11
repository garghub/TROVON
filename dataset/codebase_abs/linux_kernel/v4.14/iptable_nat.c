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
int V_13 ;
if ( V_8 -> V_9 . V_10 )
return 0 ;
V_12 = F_12 ( & V_14 ) ;
if ( V_12 == NULL )
return - V_15 ;
V_13 = F_13 ( V_8 , & V_14 , V_12 ,
V_16 , & V_8 -> V_9 . V_10 ) ;
F_14 ( V_12 ) ;
return V_13 ;
}
static void T_2 F_15 ( struct V_8 * V_8 )
{
if ( ! V_8 -> V_9 . V_10 )
return;
F_16 ( V_8 , V_8 -> V_9 . V_10 , V_16 ) ;
V_8 -> V_9 . V_10 = NULL ;
}
static int T_3 F_17 ( void )
{
int V_13 = F_18 ( & V_17 ) ;
if ( V_13 )
return V_13 ;
V_13 = F_11 ( & V_18 ) ;
if ( V_13 )
F_19 ( & V_17 ) ;
return V_13 ;
}
static void T_4 F_20 ( void )
{
F_19 ( & V_17 ) ;
}
