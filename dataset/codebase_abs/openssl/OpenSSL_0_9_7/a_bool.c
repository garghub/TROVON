int F_1 ( int V_1 , unsigned char * * V_2 )
{
int V_3 ;
unsigned char * V_4 ;
V_3 = F_2 ( 0 , 1 , V_5 ) ;
if ( V_2 == NULL ) return ( V_3 ) ;
V_4 = * V_2 ;
F_3 ( & V_4 , 0 , 1 , V_5 , V_6 ) ;
* ( V_4 ++ ) = ( unsigned char ) V_1 ;
* V_2 = V_4 ;
return ( V_3 ) ;
}
int F_4 ( int * V_1 , unsigned char * * V_2 , long V_7 )
{
int V_8 = - 1 ;
unsigned char * V_4 ;
long V_9 ;
int V_10 , V_11 , V_12 ;
int V_13 = 0 ;
V_4 = * V_2 ;
V_10 = F_5 ( & V_4 , & V_9 , & V_11 , & V_12 , V_7 ) ;
if ( V_10 & 0x80 )
{
V_13 = V_14 ;
goto V_15;
}
if ( V_11 != V_5 )
{
V_13 = V_16 ;
goto V_15;
}
if ( V_9 != 1 )
{
V_13 = V_17 ;
goto V_15;
}
V_8 = ( int ) * ( V_4 ++ ) ;
if ( V_1 != NULL ) ( * V_1 ) = V_8 ;
* V_2 = V_4 ;
return ( V_8 ) ;
V_15:
F_6 ( V_18 , V_13 ) ;
return ( V_8 ) ;
}
