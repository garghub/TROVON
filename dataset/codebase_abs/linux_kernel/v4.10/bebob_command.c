int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int V_5 )
{
T_1 * V_6 ;
int V_7 ;
V_6 = F_2 ( 12 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_6 [ 0 ] = 0x00 ;
V_6 [ 1 ] = 0x08 | ( 0x07 & V_3 ) ;
V_6 [ 2 ] = 0xb8 ;
V_6 [ 3 ] = 0x80 ;
V_6 [ 4 ] = 0xff & V_4 ;
V_6 [ 5 ] = 0x10 ;
V_6 [ 6 ] = 0x02 ;
V_6 [ 7 ] = 0xff & V_5 ;
V_6 [ 8 ] = 0x01 ;
V_7 = F_3 ( V_2 , V_6 , 12 , V_6 , 12 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 7 ) | F_4 ( 8 ) ) ;
if ( V_7 > 0 && V_7 < 9 )
V_7 = - V_10 ;
else if ( V_6 [ 0 ] == 0x08 )
V_7 = - V_11 ;
else if ( V_6 [ 0 ] == 0x0a )
V_7 = - V_12 ;
else if ( V_7 > 0 )
V_7 = 0 ;
F_5 ( V_6 ) ;
return V_7 ;
}
int F_6 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 , unsigned int * V_5 )
{
T_1 * V_6 ;
int V_7 ;
V_6 = F_2 ( 12 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
V_6 [ 0 ] = 0x01 ;
V_6 [ 1 ] = 0x08 | ( 0x07 & V_3 ) ;
V_6 [ 2 ] = 0xb8 ;
V_6 [ 3 ] = 0x80 ;
V_6 [ 4 ] = 0xff & V_4 ;
V_6 [ 5 ] = 0x10 ;
V_6 [ 6 ] = 0x02 ;
V_6 [ 7 ] = 0xff ;
V_6 [ 8 ] = 0x01 ;
V_7 = F_3 ( V_2 , V_6 , 12 , V_6 , 12 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 8 ) ) ;
if ( V_7 > 0 && V_7 < 9 )
V_7 = - V_10 ;
else if ( V_6 [ 0 ] == 0x08 )
V_7 = - V_11 ;
else if ( V_6 [ 0 ] == 0x0a )
V_7 = - V_12 ;
else if ( V_6 [ 0 ] == 0x0b )
V_7 = - V_13 ;
if ( V_7 < 0 )
goto V_14;
* V_5 = V_6 [ 7 ] ;
V_7 = 0 ;
V_14:
F_5 ( V_6 ) ;
return V_7 ;
}
static inline void
F_7 ( T_1 * V_6 , T_1 * V_15 )
{
V_6 [ 1 ] = V_15 [ 0 ] ;
memcpy ( V_6 + 4 , V_15 + 1 , 5 ) ;
}
static inline void
F_8 ( T_1 * V_6 , T_1 * V_15 ,
unsigned int V_16 )
{
V_6 [ 0 ] = 0x01 ;
V_6 [ 2 ] = 0x02 ;
V_6 [ 3 ] = 0xc0 ;
F_7 ( V_6 , V_15 ) ;
V_6 [ 9 ] = V_16 ;
}
int F_9 ( struct V_1 * V_2 ,
T_1 V_15 [ V_17 ] ,
enum V_18 * type )
{
T_1 * V_6 ;
int V_7 ;
V_6 = F_2 ( 12 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
F_8 ( V_6 , V_15 , 0x00 ) ;
V_7 = F_3 ( V_2 , V_6 , 12 , V_6 , 12 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 7 ) | F_4 ( 9 ) ) ;
if ( ( V_7 >= 0 ) && ( V_7 < 8 ) )
V_7 = - V_10 ;
else if ( V_6 [ 0 ] == 0x08 )
V_7 = - V_11 ;
else if ( V_6 [ 0 ] == 0x0a )
V_7 = - V_12 ;
else if ( V_6 [ 0 ] == 0x0b )
V_7 = - V_13 ;
if ( V_7 < 0 )
goto V_14;
* type = V_6 [ 10 ] ;
V_7 = 0 ;
V_14:
F_5 ( V_6 ) ;
return V_7 ;
}
int F_10 ( struct V_1 * V_2 ,
T_1 V_15 [ V_17 ] ,
T_1 * V_6 , unsigned int V_19 )
{
int V_7 ;
F_8 ( V_6 , V_15 , 0x03 ) ;
V_7 = F_3 ( V_2 , V_6 , 12 , V_6 , 256 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) |
F_4 ( 5 ) | F_4 ( 6 ) | F_4 ( 7 ) | F_4 ( 9 ) ) ;
if ( ( V_7 >= 0 ) && ( V_7 < 8 ) )
V_7 = - V_10 ;
else if ( V_6 [ 0 ] == 0x08 )
V_7 = - V_11 ;
else if ( V_6 [ 0 ] == 0x0a )
V_7 = - V_12 ;
else if ( V_6 [ 0 ] == 0x0b )
V_7 = - V_13 ;
if ( V_7 < 0 )
goto V_14;
memmove ( V_6 , V_6 + 10 , V_7 - 10 ) ;
V_7 = 0 ;
V_14:
return V_7 ;
}
int F_11 ( struct V_1 * V_2 ,
T_1 V_15 [ V_17 ] ,
unsigned int V_20 , T_1 * type )
{
T_1 * V_6 ;
int V_7 ;
V_6 = F_2 ( 12 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
F_8 ( V_6 , V_15 , 0x07 ) ;
V_6 [ 10 ] = 0xff & ++ V_20 ;
V_7 = F_3 ( V_2 , V_6 , 12 , V_6 , 12 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 7 ) | F_4 ( 9 ) | F_4 ( 10 ) ) ;
if ( ( V_7 >= 0 ) && ( V_7 < 8 ) )
V_7 = - V_10 ;
else if ( V_6 [ 0 ] == 0x08 )
V_7 = - V_11 ;
else if ( V_6 [ 0 ] == 0x0a )
V_7 = - V_12 ;
else if ( V_6 [ 0 ] == 0x0b )
V_7 = - V_13 ;
if ( V_7 < 0 )
goto V_14;
* type = V_6 [ 11 ] ;
V_7 = 0 ;
V_14:
F_5 ( V_6 ) ;
return V_7 ;
}
int F_12 ( struct V_1 * V_2 ,
T_1 V_15 [ V_17 ] , T_1 V_21 [ 7 ] )
{
int V_7 ;
T_1 * V_6 ;
V_6 = F_2 ( 18 , V_8 ) ;
if ( V_6 == NULL )
return - V_9 ;
F_8 ( V_6 , V_15 , 0x05 ) ;
V_7 = F_3 ( V_2 , V_6 , 16 , V_6 , 16 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 7 ) ) ;
if ( ( V_7 >= 0 ) && ( V_7 < 8 ) )
V_7 = - V_10 ;
else if ( V_6 [ 0 ] == 0x08 )
V_7 = - V_11 ;
else if ( V_6 [ 0 ] == 0x0a )
V_7 = - V_12 ;
else if ( V_6 [ 0 ] == 0x0b )
V_7 = - V_13 ;
if ( V_7 < 0 )
goto V_14;
memcpy ( V_21 , V_6 + 10 , 5 ) ;
V_7 = 0 ;
V_14:
F_5 ( V_6 ) ;
return V_7 ;
}
int F_13 ( struct V_1 * V_2 ,
T_1 V_15 [ V_17 ] , T_1 * V_6 ,
unsigned int * V_19 , unsigned int V_22 )
{
int V_7 ;
if ( ( V_6 == NULL ) || ( * V_19 < 12 ) ) {
V_7 = - V_12 ;
goto V_14;
}
V_6 [ 0 ] = 0x01 ;
V_6 [ 2 ] = 0x2f ;
V_6 [ 3 ] = 0xc1 ;
F_7 ( V_6 , V_15 ) ;
V_6 [ 10 ] = 0xff & V_22 ;
V_7 = F_3 ( V_2 , V_6 , 12 , V_6 , * V_19 ,
F_4 ( 1 ) | F_4 ( 2 ) | F_4 ( 3 ) | F_4 ( 4 ) | F_4 ( 5 ) |
F_4 ( 6 ) | F_4 ( 7 ) | F_4 ( 10 ) ) ;
if ( ( V_7 >= 0 ) && ( V_7 < 12 ) )
V_7 = - V_10 ;
else if ( V_6 [ 0 ] == 0x08 )
V_7 = - V_11 ;
else if ( V_6 [ 0 ] == 0x0a )
V_7 = - V_12 ;
else if ( V_6 [ 0 ] == 0x0b )
V_7 = - V_13 ;
else if ( V_6 [ 10 ] != V_22 )
V_7 = - V_10 ;
if ( V_7 < 0 )
goto V_14;
memmove ( V_6 , V_6 + 11 , V_7 - 11 ) ;
* V_19 = V_7 - 11 ;
V_7 = 0 ;
V_14:
return V_7 ;
}
