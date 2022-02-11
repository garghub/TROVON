static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_8 ) ;
if ( V_4 == NULL )
return - V_9 ;
V_2 -> V_4 = V_4 ;
V_6 = & V_4 -> V_10 . V_11 ;
F_3 ( & V_4 -> V_10 ) ;
V_7 = F_4 ( V_2 , V_6 , NULL , 0 ) ;
if ( V_7 < 0 )
goto error;
V_7 = F_5 ( V_2 , V_6 ) ;
if ( V_7 < 0 )
goto error;
V_2 -> V_12 = V_13 ;
return 0 ;
error:
F_6 ( V_2 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 ;
int V_7 ;
V_4 = F_2 ( sizeof( * V_4 ) , V_8 ) ;
if ( ! V_4 )
return - V_9 ;
V_2 -> V_4 = V_4 ;
V_6 = & V_4 -> V_10 . V_11 ;
F_3 ( & V_4 -> V_10 ) ;
V_4 -> V_10 . V_14 = ( 1ULL << 0x10 ) ;
V_7 = F_4 ( V_2 , V_6 , NULL , 0 ) ;
if ( V_7 < 0 )
goto error;
V_7 = F_5 ( V_2 , V_6 ) ;
if ( V_7 < 0 )
goto error;
if ( F_8 ( F_9 ( V_2 , 0x10 ) ) ==
V_15 ) {
static const struct V_16 V_17 =
F_10 ( L_1 ,
0x10 , 0 , V_18 ) ;
if ( ! F_11 ( & V_4 -> V_10 , NULL , & V_17 ) ) {
V_7 = - V_9 ;
goto error;
}
}
V_2 -> V_12 = V_13 ;
return 0 ;
error:
F_6 ( V_2 ) ;
return V_7 ;
}
static int T_1 F_12 ( void )
{
return F_13 ( & V_19 ) ;
}
static void T_2 F_14 ( void )
{
F_15 ( & V_19 ) ;
}
