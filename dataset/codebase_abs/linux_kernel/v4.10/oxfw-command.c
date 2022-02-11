int F_1 ( struct V_1 * V_2 , enum V_3 V_4 ,
unsigned int V_5 , T_1 * V_6 , unsigned int V_7 )
{
T_1 * V_8 ;
int V_9 ;
V_8 = F_2 ( V_7 + 10 , V_10 ) ;
if ( V_8 == NULL )
return - V_11 ;
V_8 [ 0 ] = 0x00 ;
V_8 [ 1 ] = 0xff ;
V_8 [ 2 ] = 0xbf ;
V_8 [ 3 ] = 0xc0 ;
V_8 [ 4 ] = V_4 ;
V_8 [ 5 ] = 0x00 ;
V_8 [ 6 ] = 0x00 ;
V_8 [ 7 ] = 0xff & V_5 ;
V_8 [ 8 ] = 0xff ;
V_8 [ 9 ] = 0xff ;
memcpy ( V_8 + 10 , V_6 , V_7 ) ;
V_9 = F_3 ( V_2 , V_8 , V_7 + 10 , V_8 , V_7 + 10 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 7 ) | F_4 ( 8 ) ) ;
if ( ( V_9 > 0 ) && ( V_9 < V_7 + 10 ) )
V_9 = - V_12 ;
else if ( V_8 [ 0 ] == 0x08 )
V_9 = - V_13 ;
else if ( V_8 [ 0 ] == 0x0a )
V_9 = - V_14 ;
else
V_9 = 0 ;
F_5 ( V_8 ) ;
return V_9 ;
}
int F_6 ( struct V_1 * V_2 ,
enum V_3 V_4 , unsigned int V_5 ,
T_1 * V_8 , unsigned int * V_7 , unsigned int V_15 )
{
unsigned int V_16 ;
int V_9 ;
if ( V_15 == 0xff )
V_16 = 0xc0 ;
else
V_16 = 0xc1 ;
V_8 [ 0 ] = 0x01 ;
V_8 [ 1 ] = 0xff ;
V_8 [ 2 ] = 0xbf ;
V_8 [ 3 ] = V_16 ;
V_8 [ 4 ] = V_4 ;
V_8 [ 5 ] = 0x00 ;
V_8 [ 6 ] = 0x00 ;
V_8 [ 7 ] = 0xff & V_5 ;
V_8 [ 8 ] = 0xff ;
V_8 [ 9 ] = 0xff ;
V_8 [ 10 ] = 0xff & V_15 ;
V_8 [ 11 ] = 0xff ;
V_9 = F_3 ( V_2 , V_8 , 12 , V_8 , * V_7 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 7 ) ) ;
if ( ( V_9 > 0 ) && ( V_9 < 10 ) )
V_9 = - V_12 ;
else if ( V_8 [ 0 ] == 0x08 )
V_9 = - V_13 ;
else if ( V_8 [ 0 ] == 0x0a )
V_9 = - V_14 ;
else if ( V_8 [ 0 ] == 0x0b )
V_9 = - V_17 ;
else if ( ( V_16 == 0xc1 ) && ( V_8 [ 10 ] != V_15 ) )
V_9 = - V_12 ;
if ( V_9 < 0 )
goto V_18;
if ( V_16 == 0xc0 ) {
memmove ( V_8 , V_8 + 10 , V_9 - 10 ) ;
* V_7 = V_9 - 10 ;
} else {
memmove ( V_8 , V_8 + 11 , V_9 - 11 ) ;
* V_7 = V_9 - 11 ;
}
V_9 = 0 ;
V_18:
return V_9 ;
}
int F_7 ( struct V_1 * V_2 , unsigned int V_19 ,
enum V_3 V_4 ,
unsigned short V_5 )
{
unsigned int V_20 ;
T_1 * V_8 ;
int V_9 ;
for ( V_20 = 0 ; V_20 < V_21 ; V_20 ++ ) {
if ( V_22 [ V_20 ] == V_19 )
break;
}
if ( V_20 == V_21 )
return - V_14 ;
V_8 = F_8 ( 8 , V_10 ) ;
if ( V_8 == NULL )
return - V_11 ;
V_8 [ 0 ] = 0x02 ;
V_8 [ 1 ] = 0xff ;
if ( V_4 == V_23 )
V_8 [ 2 ] = 0x19 ;
else
V_8 [ 2 ] = 0x18 ;
V_8 [ 3 ] = 0xff & V_5 ;
V_8 [ 4 ] = 0x90 ;
V_8 [ 5 ] = 0x07 & V_20 ;
V_8 [ 6 ] = 0xff ;
V_8 [ 7 ] = 0xff ;
V_9 = F_3 ( V_2 , V_8 , 8 , V_8 , 8 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) ) ;
if ( ( V_9 > 0 ) && ( V_9 < 8 ) )
V_9 = - V_12 ;
else if ( V_8 [ 0 ] == 0x08 )
V_9 = - V_13 ;
if ( V_9 < 0 )
goto V_18;
V_9 = 0 ;
V_18:
F_5 ( V_8 ) ;
return V_9 ;
}
