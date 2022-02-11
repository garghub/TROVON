int F_1 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
const unsigned char * V_5 , int V_6 )
{
int V_7 , V_8 = V_2 - 1 ;
unsigned char * V_9 , * V_10 ;
unsigned char * V_11 , V_12 [ V_13 ] ;
if ( V_4 > V_8 - 2 * V_13 - 1 )
{
F_2 ( V_14 ,
V_15 ) ;
return 0 ;
}
if ( V_8 < 2 * V_13 + 1 )
{
F_2 ( V_14 , V_16 ) ;
return 0 ;
}
V_11 = F_3 ( V_8 - V_13 ) ;
if ( V_11 == NULL )
{
F_2 ( V_14 , V_17 ) ;
return 0 ;
}
V_1 [ 0 ] = 0 ;
V_10 = V_1 + 1 ;
V_9 = V_1 + V_13 + 1 ;
F_4 ( ( void * ) V_5 , V_6 , V_9 , NULL , F_5 () , NULL ) ;
memset ( V_9 + V_13 , 0 ,
V_8 - V_4 - 2 * V_13 - 1 ) ;
V_9 [ V_8 - V_4 - V_13 - 1 ] = 0x01 ;
memcpy ( V_9 + V_8 - V_4 - V_13 , V_3 , ( unsigned int ) V_4 ) ;
if ( F_6 ( V_10 , V_13 ) <= 0 )
return 0 ;
#ifdef F_7
memcpy ( V_10 ,
L_1 ,
20 ) ;
#endif
F_8 ( V_11 , V_8 - V_13 , V_10 , V_13 ) ;
for ( V_7 = 0 ; V_7 < V_8 - V_13 ; V_7 ++ )
V_9 [ V_7 ] ^= V_11 [ V_7 ] ;
F_8 ( V_12 , V_13 , V_9 , V_8 - V_13 ) ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ )
V_10 [ V_7 ] ^= V_12 [ V_7 ] ;
F_9 ( V_11 ) ;
return 1 ;
}
int F_10 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_18 ,
const unsigned char * V_5 , int V_6 )
{
int V_7 , V_19 , V_20 = - 1 ;
const unsigned char * V_21 ;
int V_22 ;
unsigned char * V_9 = NULL , V_10 [ V_13 ] , V_23 [ V_13 ] ;
int V_24 = 0 ;
if ( -- V_18 < 2 * V_13 + 1 )
goto V_25;
V_22 = V_18 - V_4 ;
if ( V_22 < 0 )
{
V_24 = 1 ;
V_22 = 0 ;
}
V_21 = V_3 - V_22 + V_13 ;
V_19 = V_18 - V_13 ;
V_9 = F_3 ( V_19 ) ;
if ( V_9 == NULL )
{
F_2 ( V_14 , V_17 ) ;
return - 1 ;
}
F_8 ( V_10 , V_13 , V_21 , V_19 ) ;
for ( V_7 = V_22 ; V_7 < V_13 ; V_7 ++ )
V_10 [ V_7 ] ^= V_3 [ V_7 - V_22 ] ;
F_8 ( V_9 , V_19 , V_10 , V_13 ) ;
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ )
V_9 [ V_7 ] ^= V_21 [ V_7 ] ;
F_4 ( ( void * ) V_5 , V_6 , V_23 , NULL , F_5 () , NULL ) ;
if ( memcmp ( V_9 , V_23 , V_13 ) != 0 || V_24 )
goto V_25;
else
{
for ( V_7 = V_13 ; V_7 < V_19 ; V_7 ++ )
if ( V_9 [ V_7 ] != 0x00 )
break;
if ( V_9 [ V_7 ] != 0x01 || V_7 ++ >= V_19 )
goto V_25;
else
{
V_20 = V_19 - V_7 ;
if ( V_2 < V_20 )
{
F_2 ( V_26 , V_27 ) ;
V_20 = - 1 ;
}
else
memcpy ( V_1 , V_9 + V_7 , V_20 ) ;
}
}
F_9 ( V_9 ) ;
return V_20 ;
V_25:
F_2 ( V_26 , V_28 ) ;
if ( V_9 != NULL ) F_9 ( V_9 ) ;
return - 1 ;
}
int F_8 ( unsigned char * V_29 , long V_30 ,
const unsigned char * V_10 , long V_31 )
{
long V_7 , V_32 = 0 ;
unsigned char V_33 [ 4 ] ;
T_1 V_34 ;
unsigned char V_35 [ V_13 ] ;
F_11 ( & V_34 ) ;
for ( V_7 = 0 ; V_32 < V_30 ; V_7 ++ )
{
V_33 [ 0 ] = ( unsigned char ) ( ( V_7 >> 24 ) & 255 ) ;
V_33 [ 1 ] = ( unsigned char ) ( ( V_7 >> 16 ) & 255 ) ;
V_33 [ 2 ] = ( unsigned char ) ( ( V_7 >> 8 ) ) & 255 ;
V_33 [ 3 ] = ( unsigned char ) ( V_7 & 255 ) ;
F_12 ( & V_34 , F_5 () , NULL ) ;
F_13 ( & V_34 , V_10 , V_31 ) ;
F_13 ( & V_34 , V_33 , 4 ) ;
if ( V_32 + V_13 <= V_30 )
{
F_14 ( & V_34 , V_29 + V_32 , NULL ) ;
V_32 += V_13 ;
}
else
{
F_14 ( & V_34 , V_35 , NULL ) ;
memcpy ( V_29 + V_32 , V_35 , V_30 - V_32 ) ;
V_32 = V_30 ;
}
}
F_15 ( & V_34 ) ;
return 0 ;
}
