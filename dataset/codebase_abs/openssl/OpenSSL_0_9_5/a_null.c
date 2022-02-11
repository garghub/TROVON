int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
if( ! V_1 ) return 0 ;
if ( V_2 ) F_2 ( V_2 , 0 , 0 , V_3 , V_4 ) ;
return 2 ;
}
T_1 * F_3 ( T_1 * * V_1 , unsigned char * * V_2 , long V_5 )
{
T_1 * V_6 = NULL ;
unsigned char * V_7 ;
long V_8 ;
int V_9 , V_10 , V_11 ;
int V_12 = 0 ;
V_7 = * V_2 ;
V_9 = F_4 ( & V_7 , & V_8 , & V_10 , & V_11 , V_5 ) ;
if ( V_9 & 0x80 )
{
V_12 = V_13 ;
goto V_14;
}
if ( V_10 != V_3 )
{
V_12 = V_15 ;
goto V_14;
}
if ( V_8 != 0 )
{
V_12 = V_16 ;
goto V_14;
}
V_6 = ( T_1 * ) 1 ;
if ( V_1 != NULL ) ( * V_1 ) = V_6 ;
* V_2 = V_7 ;
return ( V_6 ) ;
V_14:
F_5 ( V_17 , V_12 ) ;
return ( V_6 ) ;
}
T_1 * F_6 ( void )
{
return ( T_1 * ) 1 ;
}
void F_7 ( T_1 * V_1 )
{
return;
}
