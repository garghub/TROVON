static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_6 ) ;
}
static int F_3 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_7 )
{
if ( V_4 )
F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_6 ) ;
F_4 ( V_2 ,
( V_5 * ) V_6 ) ;
return F_5 ( V_2 , V_7 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 * V_7 )
{
return F_3 ( V_2 , NULL , 0 , V_7 ) ;
}
static int F_7 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
if ( ! F_8 () )
return F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_6 ) ;
F_9 () ;
F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_8 ) ;
F_10 () ;
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_7 )
{
if ( ! F_8 () ) {
if ( V_4 )
F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_6 ) ;
F_4 ( V_2 ,
( V_5 * ) V_6 ) ;
} else {
F_9 () ;
if ( V_4 )
F_2 ( V_2 , V_3 , V_4 ,
( V_5 * ) V_8 ) ;
F_4 ( V_2 ,
( V_5 * ) V_8 ) ;
F_10 () ;
}
return F_5 ( V_2 , V_7 ) ;
}
static int F_12 ( struct V_1 * V_2 , T_1 * V_7 )
{
return F_11 ( V_2 , NULL , 0 , V_7 ) ;
}
static int T_2 F_13 ( void )
{
int V_9 = F_14 ( V_10 , F_15 ( V_10 ) ) ;
if ( V_9 )
return V_9 ;
if ( V_11 & V_12 ) {
V_9 = F_14 ( V_13 , F_15 ( V_13 ) ) ;
if ( V_9 )
F_16 ( V_10 , F_15 ( V_10 ) ) ;
}
return V_9 ;
}
static void T_3 F_17 ( void )
{
if ( V_11 & V_12 )
F_16 ( V_13 , F_15 ( V_13 ) ) ;
F_16 ( V_10 , F_15 ( V_10 ) ) ;
}
