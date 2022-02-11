static int F_1 ( T_1 V_1 , unsigned char * V_2 , int V_3 )
{
int V_4 ;
if ( V_3 <= 0 )
return - V_5 ;
V_4 = F_2 ( V_1 , V_2 , V_3 ) ;
if ( V_4 < 0 ) {
* V_2 = '?' ;
return - V_6 ;
}
return V_4 ;
}
static int F_3 ( const unsigned char * V_7 , int V_3 , T_1 * V_1 )
{
int V_4 ;
T_2 V_8 ;
V_4 = F_4 ( V_7 , V_3 , & V_8 ) ;
if ( V_4 < 0 || V_8 > V_9 ) {
* V_1 = 0x003f ;
return - V_6 ;
}
* V_1 = ( T_1 ) V_8 ;
return V_4 ;
}
static int T_3 F_5 ( void )
{
int V_10 ;
for ( V_10 = 0 ; V_10 < 256 ; V_10 ++ )
V_11 [ V_10 ] = V_10 ;
return F_6 ( & V_12 ) ;
}
static void T_4 F_7 ( void )
{
F_8 ( & V_12 ) ;
}
