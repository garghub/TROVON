int F_1 ( unsigned int V_1 , void (* F_2)( void ) )
{
void (* F_3)( void );
if ( V_1 > 0x3F )
return - V_2 ;
F_3 = V_3 [ V_1 ] ;
if ( F_3 != V_4 )
return - V_5 ;
V_3 [ V_1 ] = F_2 ;
return 0 ;
}
int F_4 ( unsigned int V_1 , void (* F_2)( void ) )
{
void (* F_3)( void );
if ( V_1 > 0x3F )
return - V_2 ;
F_3 = V_3 [ V_1 ] ;
if ( F_3 != F_2 )
return - V_5 ;
V_3 [ V_1 ] = V_4 ;
return 0 ;
}
