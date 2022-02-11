static void * F_1 ( struct V_1 * V_2 )
{
char * V_3 = V_2 -> V_4 ;
struct V_5 * V_6 = V_7 -> V_8 -> V_6 ;
V_3 = ( V_3 - ( char * ) & V_9 ) + ( char * ) V_6 ;
return V_3 ;
}
static int F_2 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_3 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_5 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int F_6 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_5 * V_15 = V_7 -> V_8 -> V_6 ;
int V_16 = F_4 ( V_2 , V_10 , V_11 , V_12 , V_13 ) ;
if ( V_16 < 0 )
return V_16 ;
if ( V_15 -> V_17 )
F_7 ( V_15 ) ;
return V_16 ;
}
static int F_8 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = F_1 ( V_2 ) ;
return F_9 ( & V_14 , V_10 , V_11 ,
V_12 , V_13 ) ;
}
static int F_10 ( struct V_1 * V_2 , int V_10 ,
void T_1 * V_11 , T_2 * V_12 , T_3 * V_13 )
{
struct V_1 V_14 ;
int V_18 = 0 ;
memcpy ( & V_14 , V_2 , sizeof( V_14 ) ) ;
V_14 . V_4 = & V_18 ;
if ( V_10 )
F_11 ( L_1 ) ;
return F_5 ( & V_14 , V_10 , V_11 , V_12 , V_13 ) ;
}
static int T_4 F_12 ( void )
{
F_13 ( V_19 ) ;
return 0 ;
}
