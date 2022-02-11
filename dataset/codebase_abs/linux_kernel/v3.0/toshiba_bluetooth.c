static int F_1 ( T_1 V_1 )
{
T_2 V_2 , V_3 ;
T_3 V_4 ;
V_2 = F_2 ( V_1 , L_1 , NULL , & V_4 ) ;
if ( F_3 ( V_2 ) )
return V_2 ;
if ( ! ( V_4 & 0x01 ) )
return 0 ;
F_4 ( L_2 ) ;
V_2 = F_5 ( V_1 , L_3 , NULL , NULL ) ;
V_3 = F_5 ( V_1 , L_4 , NULL , NULL ) ;
if ( ! F_3 ( V_2 ) || ! F_3 ( V_3 ) )
return 0 ;
F_6 ( L_5 ) ;
return - V_5 ;
}
static void F_7 ( struct V_6 * V_7 , T_4 V_8 )
{
F_1 ( V_7 -> V_1 ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
return F_1 ( V_7 -> V_1 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
T_2 V_9 ;
T_3 V_10 ;
int V_4 = - V_5 ;
V_9 = F_2 ( V_7 -> V_1 , L_6 , NULL ,
& V_10 ) ;
if ( ! F_3 ( V_9 ) && V_10 ) {
F_4 ( L_7
L_8 ) ;
V_4 = F_1 ( V_7 -> V_1 ) ;
}
return V_4 ;
}
static int T_5 F_10 ( void )
{
int V_4 ;
V_4 = F_11 ( & V_11 ) ;
if ( V_4 < 0 ) {
F_12 ( ( V_12 ,
L_9 ) ) ;
return V_4 ;
}
return 0 ;
}
static int F_13 ( struct V_6 * V_7 , int type )
{
return 0 ;
}
static void T_6 F_14 ( void )
{
F_15 ( & V_11 ) ;
}
