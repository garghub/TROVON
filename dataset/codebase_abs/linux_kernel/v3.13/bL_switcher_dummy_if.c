static T_1 F_1 ( struct V_1 * V_1 , const char T_2 * V_2 ,
T_3 V_3 , T_4 * V_4 )
{
unsigned char V_5 [ 3 ] ;
unsigned int V_6 , V_7 ;
int V_8 ;
F_2 ( L_1 , V_9 ) ;
if ( V_3 < 3 )
return - V_10 ;
if ( F_3 ( V_5 , V_2 , 3 ) )
return - V_11 ;
if ( V_5 [ 0 ] < '0' || V_5 [ 0 ] > '9' ||
V_5 [ 1 ] != ',' ||
V_5 [ 2 ] < '0' || V_5 [ 2 ] > '1' )
return - V_10 ;
V_6 = V_5 [ 0 ] - '0' ;
V_7 = V_5 [ 2 ] - '0' ;
V_8 = F_4 ( V_6 , V_7 ) ;
return V_8 ? : V_3 ;
}
static int T_5 F_5 ( void )
{
return F_6 ( & V_12 ) ;
}
static void T_6 F_7 ( void )
{
F_8 ( & V_12 ) ;
}
