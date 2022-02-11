int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const T_2 * V_3 , const unsigned char * V_4 , int V_5 )
{
int V_6 ;
int V_7 = 0 ;
int V_8 , V_9 , V_10 , V_11 ;
const unsigned char * V_12 ;
unsigned char * V_13 = NULL ;
T_3 V_14 ;
unsigned char V_15 [ V_16 ] ;
V_8 = F_2 ( V_3 ) ;
if ( V_5 == - 1 ) V_5 = V_8 ;
else if ( V_5 == - 2 ) V_5 = - 2 ;
else if ( V_5 < - 2 )
{
F_3 ( V_17 , V_18 ) ;
goto V_19;
}
V_10 = ( F_4 ( V_1 -> V_20 ) - 1 ) & 0x7 ;
V_11 = F_5 ( V_1 ) ;
if ( V_4 [ 0 ] & ( 0xFF << V_10 ) )
{
F_3 ( V_17 , V_21 ) ;
goto V_19;
}
if ( V_10 == 0 )
{
V_4 ++ ;
V_11 -- ;
}
if ( V_11 < ( V_8 + V_5 + 2 ) )
{
F_3 ( V_17 , V_22 ) ;
goto V_19;
}
if ( V_4 [ V_11 - 1 ] != 0xbc )
{
F_3 ( V_17 , V_23 ) ;
goto V_19;
}
V_9 = V_11 - V_8 - 1 ;
V_12 = V_4 + V_9 ;
V_13 = F_6 ( V_9 ) ;
if ( ! V_13 )
{
F_3 ( V_17 , V_24 ) ;
goto V_19;
}
F_7 ( V_13 , V_9 , V_12 , V_8 , V_3 ) ;
for ( V_6 = 0 ; V_6 < V_9 ; V_6 ++ )
V_13 [ V_6 ] ^= V_4 [ V_6 ] ;
if ( V_10 )
V_13 [ 0 ] &= 0xFF >> ( 8 - V_10 ) ;
for ( V_6 = 0 ; V_13 [ V_6 ] == 0 && V_6 < ( V_9 - 1 ) ; V_6 ++ ) ;
if ( V_13 [ V_6 ++ ] != 0x1 )
{
F_3 ( V_17 , V_25 ) ;
goto V_19;
}
if ( V_5 >= 0 && ( V_9 - V_6 ) != V_5 )
{
F_3 ( V_17 , V_18 ) ;
goto V_19;
}
F_8 ( & V_14 ) ;
F_9 ( & V_14 , V_3 , NULL ) ;
F_10 ( & V_14 , V_26 , sizeof V_26 ) ;
F_10 ( & V_14 , V_2 , V_8 ) ;
if ( V_9 - V_6 )
F_10 ( & V_14 , V_13 + V_6 , V_9 - V_6 ) ;
F_11 ( & V_14 , V_15 , NULL ) ;
F_12 ( & V_14 ) ;
if ( memcmp ( V_15 , V_12 , V_8 ) )
{
F_3 ( V_17 , V_27 ) ;
V_7 = 0 ;
}
else
V_7 = 1 ;
V_19:
if ( V_13 )
F_13 ( V_13 ) ;
return V_7 ;
}
int F_14 ( T_1 * V_1 , unsigned char * V_4 ,
const unsigned char * V_2 ,
const T_2 * V_3 , int V_5 )
{
int V_6 ;
int V_7 = 0 ;
int V_8 , V_9 , V_10 , V_11 ;
unsigned char * V_12 , * V_28 = NULL , * V_29 ;
T_3 V_14 ;
V_8 = F_2 ( V_3 ) ;
if ( V_5 == - 1 ) V_5 = V_8 ;
else if ( V_5 == - 2 ) V_5 = - 2 ;
else if ( V_5 < - 2 )
{
F_3 ( V_30 , V_18 ) ;
goto V_19;
}
V_10 = ( F_4 ( V_1 -> V_20 ) - 1 ) & 0x7 ;
V_11 = F_5 ( V_1 ) ;
if ( V_10 == 0 )
{
* V_4 ++ = 0 ;
V_11 -- ;
}
if ( V_5 == - 2 )
{
V_5 = V_11 - V_8 - 2 ;
}
else if ( V_11 < ( V_8 + V_5 + 2 ) )
{
F_3 ( V_30 ,
V_31 ) ;
goto V_19;
}
if ( V_5 > 0 )
{
V_28 = F_6 ( V_5 ) ;
if ( ! V_28 )
{
F_3 ( V_30 ,
V_24 ) ;
goto V_19;
}
if ( ! F_15 ( V_28 , V_5 ) )
goto V_19;
}
V_9 = V_11 - V_8 - 1 ;
V_12 = V_4 + V_9 ;
F_8 ( & V_14 ) ;
F_9 ( & V_14 , V_3 , NULL ) ;
F_10 ( & V_14 , V_26 , sizeof V_26 ) ;
F_10 ( & V_14 , V_2 , V_8 ) ;
if ( V_5 )
F_10 ( & V_14 , V_28 , V_5 ) ;
F_11 ( & V_14 , V_12 , NULL ) ;
F_12 ( & V_14 ) ;
F_7 ( V_4 , V_9 , V_12 , V_8 , V_3 ) ;
V_29 = V_4 ;
V_29 += V_11 - V_5 - V_8 - 2 ;
* V_29 ++ ^= 0x1 ;
if ( V_5 > 0 )
{
for ( V_6 = 0 ; V_6 < V_5 ; V_6 ++ )
* V_29 ++ ^= V_28 [ V_6 ] ;
}
if ( V_10 )
V_4 [ 0 ] &= 0xFF >> ( 8 - V_10 ) ;
V_4 [ V_11 - 1 ] = 0xbc ;
V_7 = 1 ;
V_19:
if ( V_28 )
F_13 ( V_28 ) ;
return V_7 ;
}
