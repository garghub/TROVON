static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( (struct V_3 * ) F_3 ( V_2 ) ,
V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , const T_1 * V_5 ,
unsigned int V_6 )
{
return F_5 ( (struct V_3 * ) F_3 ( V_2 ) ,
V_5 , V_6 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_7 )
{
return F_7 ( (struct V_3 * ) F_3 ( V_2 ) ,
V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 , void * V_7 )
{
struct V_3 * V_8 = F_3 ( V_2 ) ;
memcpy ( V_7 , V_8 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , const void * V_9 )
{
struct V_3 * V_8 = F_3 ( V_2 ) ;
memcpy ( V_8 , V_9 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
return F_11 ( (struct V_10 * ) F_3 ( V_2 ) ,
V_11 ) ;
}
static int F_12 ( struct V_1 * V_2 , const T_1 * V_5 ,
unsigned int V_6 )
{
return F_13 ( (struct V_10 * ) F_3 ( V_2 ) ,
V_5 , V_6 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_7 )
{
return F_15 ( (struct V_10 * ) F_3 ( V_2 ) ,
V_7 ) ;
}
static int F_16 ( struct V_1 * V_2 , void * V_7 )
{
struct V_10 * V_8 = F_3 ( V_2 ) ;
memcpy ( V_7 , V_8 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , const void * V_9 )
{
struct V_10 * V_8 = F_3 ( V_2 ) ;
memcpy ( V_8 , V_9 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
return F_19 ( (struct V_12 * ) F_3 ( V_2 ) ,
V_13 ) ;
}
static int F_20 ( struct V_1 * V_2 , const T_1 * V_5 ,
unsigned int V_6 )
{
return F_21 ( (struct V_12 * ) F_3 ( V_2 ) ,
V_5 , V_6 ) ;
}
static int F_22 ( struct V_1 * V_2 , T_1 * V_7 )
{
return F_23 ( (struct V_12 * ) F_3 ( V_2 ) ,
V_7 ) ;
}
static int F_24 ( struct V_1 * V_2 , void * V_7 )
{
struct V_12 * V_8 = F_3 ( V_2 ) ;
memcpy ( V_7 , V_8 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int F_25 ( struct V_1 * V_2 , const void * V_9 )
{
struct V_12 * V_8 = F_3 ( V_2 ) ;
memcpy ( V_8 , V_9 , sizeof( * V_8 ) ) ;
return 0 ;
}
static int T_2 F_26 ( void )
{
if ( F_27 ( & V_14 ) )
goto V_7;
if ( F_27 ( & V_15 ) )
goto V_16;
if ( F_27 ( & V_17 ) )
goto V_18;
return 0 ;
V_18:
F_28 ( & V_15 ) ;
V_16:
F_28 ( & V_14 ) ;
V_7:
return - 1 ;
}
static void T_3 F_29 ( void )
{
F_28 ( & V_14 ) ;
F_28 ( & V_15 ) ;
F_28 ( & V_17 ) ;
}
