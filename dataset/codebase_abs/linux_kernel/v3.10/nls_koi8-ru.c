static int F_1 ( const T_1 V_1 ,
unsigned char * V_2 , int V_3 )
{
if ( V_3 <= 0 )
return - V_4 ;
if ( ( V_1 & 0xffaf ) == 0x040e || ( V_1 & 0xffce ) == 0x254c ) {
if ( V_1 == 0x040e )
V_2 [ 0 ] = 0xbe ;
else if ( V_1 == 0x045e )
V_2 [ 0 ] = 0xae ;
else if ( V_1 == 0x255d || V_1 == 0x256c )
return 0 ;
else
return V_5 -> F_1 ( V_1 , V_2 , V_3 ) ;
return 1 ;
}
else
return V_5 -> F_1 ( V_1 , V_2 , V_3 ) ;
}
static int F_2 ( const unsigned char * V_6 , int V_3 ,
T_1 * V_1 )
{
int V_7 ;
if ( ( * V_6 & 0xef ) != 0xae ) {
* V_1 = ( * V_6 & 0x10 ) ? 0x040e : 0x045e ;
return 1 ;
}
V_7 = V_5 -> F_2 ( V_6 , V_3 , V_1 ) ;
return V_7 ;
}
static int T_2 F_3 ( void )
{
V_5 = F_4 ( L_1 ) ;
if ( V_5 ) {
V_8 . V_9 = V_5 -> V_9 ;
V_8 . V_10 = V_5 -> V_10 ;
return F_5 ( & V_8 ) ;
}
return - V_11 ;
}
static void T_3 F_6 ( void )
{
F_7 ( & V_8 ) ;
F_8 ( V_5 ) ;
}
