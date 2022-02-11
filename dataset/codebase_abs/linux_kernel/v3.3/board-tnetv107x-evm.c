static int F_1 ( int V_1 , char * V_2 )
{
int V_3 ;
V_3 = F_2 ( V_1 , V_2 ) ;
if ( V_3 < 0 ) {
F_3 ( L_1 , V_2 ) ;
return - V_4 ;
}
F_4 ( V_1 ) ;
return V_1 ;
}
static int F_5 ( int V_5 )
{
static int V_1 ;
if ( ! V_1 )
V_1 = F_1 ( V_6 , L_2 ) ;
if ( V_1 < 0 )
return V_1 ;
return F_6 ( V_1 ) ? 0 : 1 ;
}
static int F_7 ( int V_5 )
{
static int V_1 ;
if ( ! V_1 )
V_1 = F_1 ( V_7 , L_3 ) ;
if ( V_1 < 0 )
return V_1 ;
return F_6 ( V_1 ) ? 1 : 0 ;
}
static void F_8 ( int V_8 )
{
static int V_1 ;
if ( ! V_1 ) {
int V_3 ;
V_3 = F_2 ( V_9 , L_4 ) ;
if ( V_3 < 0 ) {
F_9 ( L_5 ) ;
V_1 = - V_4 ;
return;
} else {
V_1 = V_9 ;
F_10 ( V_1 , 0 ) ;
}
}
if ( V_1 < 0 )
return;
return F_11 ( V_1 , V_8 ? 1 : 0 ) ;
}
static T_1 void F_12 ( void )
{
F_13 ( V_10 ) ;
F_13 ( V_11 ) ;
F_13 ( V_12 ) ;
F_14 ( & V_13 ) ;
F_15 ( V_14 , F_16 ( V_14 ) ) ;
}
static int T_1 F_17 ( void )
{
return F_18 ( L_6 , 0 , L_7 ) ;
}
