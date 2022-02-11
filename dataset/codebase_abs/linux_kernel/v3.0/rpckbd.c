static int F_1 ( struct V_1 * V_2 , unsigned char V_3 )
{
while ( ! ( F_2 ( V_4 ) & ( 1 << 7 ) ) )
F_3 () ;
F_4 ( V_3 , V_5 ) ;
return 0 ;
}
static T_1 F_5 ( int V_6 , void * V_7 )
{
struct V_1 * V_2 = V_7 ;
unsigned int V_8 ;
int V_9 = V_10 ;
while ( F_2 ( V_4 ) & ( 1 << 5 ) ) {
V_8 = F_2 ( V_11 ) ;
F_6 ( V_2 , V_8 , 0 ) ;
V_9 = V_12 ;
}
return V_9 ;
}
static T_1 F_7 ( int V_6 , void * V_7 )
{
return V_12 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_4 ( 0 , V_4 ) ;
F_4 ( 8 , V_4 ) ;
F_2 ( V_11 ) ;
if ( F_9 ( V_13 , F_5 , 0 , L_1 , V_2 ) != 0 ) {
F_10 ( V_14 L_2 ) ;
return - V_15 ;
}
if ( F_9 ( V_16 , F_7 , 0 , L_1 , V_2 ) != 0 ) {
F_10 ( V_14 L_3 ) ;
F_11 ( V_13 , V_2 ) ;
return - V_15 ;
}
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_13 , V_2 ) ;
F_11 ( V_16 , V_2 ) ;
}
static int T_2 F_13 ( struct V_17 * V_18 )
{
struct V_1 * V_1 ;
V_1 = F_14 ( sizeof( struct V_1 ) , V_19 ) ;
if ( ! V_1 )
return - V_20 ;
V_1 -> V_21 . type = V_22 ;
V_1 -> V_23 = F_1 ;
V_1 -> V_24 = F_8 ;
V_1 -> V_25 = F_12 ;
V_1 -> V_18 . V_26 = & V_18 -> V_18 ;
F_15 ( V_1 -> V_27 , L_4 , sizeof( V_1 -> V_27 ) ) ;
F_15 ( V_1 -> V_28 , L_5 , sizeof( V_1 -> V_28 ) ) ;
F_16 ( V_18 , V_1 ) ;
F_17 ( V_1 ) ;
return 0 ;
}
static int T_3 F_18 ( struct V_17 * V_18 )
{
struct V_1 * V_1 = F_19 ( V_18 ) ;
F_20 ( V_1 ) ;
return 0 ;
}
static int T_4 F_21 ( void )
{
return F_22 ( & V_29 ) ;
}
static void T_5 F_23 ( void )
{
F_24 ( & V_29 ) ;
}
