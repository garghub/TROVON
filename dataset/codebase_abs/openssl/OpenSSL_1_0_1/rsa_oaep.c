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
V_1 [ 0 ] = 0 ;
V_10 = V_1 + 1 ;
V_9 = V_1 + V_13 + 1 ;
if ( ! F_3 ( ( void * ) V_5 , V_6 , V_9 , NULL , F_4 () , NULL ) )
return 0 ;
memset ( V_9 + V_13 , 0 ,
V_8 - V_4 - 2 * V_13 - 1 ) ;
V_9 [ V_8 - V_4 - V_13 - 1 ] = 0x01 ;
memcpy ( V_9 + V_8 - V_4 - V_13 , V_3 , ( unsigned int ) V_4 ) ;
if ( F_5 ( V_10 , V_13 ) <= 0 )
return 0 ;
#ifdef F_6
memcpy ( V_10 ,
L_1 ,
20 ) ;
#endif
V_11 = F_7 ( V_8 - V_13 ) ;
if ( V_11 == NULL )
{
F_2 ( V_14 , V_17 ) ;
return 0 ;
}
if ( F_8 ( V_11 , V_8 - V_13 , V_10 , V_13 ) < 0 )
return 0 ;
for ( V_7 = 0 ; V_7 < V_8 - V_13 ; V_7 ++ )
V_9 [ V_7 ] ^= V_11 [ V_7 ] ;
if ( F_8 ( V_12 , V_13 , V_9 , V_8 - V_13 ) < 0 )
return 0 ;
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
unsigned char * V_24 ;
int V_25 = 0 ;
if ( -- V_18 < 2 * V_13 + 1 )
goto V_26;
V_22 = V_18 - V_4 ;
if ( V_22 < 0 )
{
V_25 = 1 ;
V_22 = 0 ;
V_4 = V_18 ;
}
V_19 = V_18 - V_13 ;
V_9 = F_7 ( V_19 + V_18 ) ;
if ( V_9 == NULL )
{
F_2 ( V_27 , V_17 ) ;
return - 1 ;
}
V_24 = V_9 + V_19 ;
memset ( V_24 , 0 , V_22 ) ;
memcpy ( V_24 + V_22 , V_3 , V_4 ) ;
V_21 = V_24 + V_13 ;
if ( F_8 ( V_10 , V_13 , V_21 , V_19 ) )
return - 1 ;
for ( V_7 = 0 ; V_7 < V_13 ; V_7 ++ )
V_10 [ V_7 ] ^= V_24 [ V_7 ] ;
if ( F_8 ( V_9 , V_19 , V_10 , V_13 ) )
return - 1 ;
for ( V_7 = 0 ; V_7 < V_19 ; V_7 ++ )
V_9 [ V_7 ] ^= V_21 [ V_7 ] ;
if ( ! F_3 ( ( void * ) V_5 , V_6 , V_23 , NULL , F_4 () , NULL ) )
return - 1 ;
if ( memcmp ( V_9 , V_23 , V_13 ) != 0 || V_25 )
goto V_26;
else
{
for ( V_7 = V_13 ; V_7 < V_19 ; V_7 ++ )
if ( V_9 [ V_7 ] != 0x00 )
break;
if ( V_7 == V_19 || V_9 [ V_7 ] != 0x01 )
goto V_26;
else
{
V_20 = V_19 - ++ V_7 ;
if ( V_2 < V_20 )
{
F_2 ( V_27 , V_28 ) ;
V_20 = - 1 ;
}
else
memcpy ( V_1 , V_9 + V_7 , V_20 ) ;
}
}
F_9 ( V_9 ) ;
return V_20 ;
V_26:
F_2 ( V_27 , V_29 ) ;
if ( V_9 != NULL ) F_9 ( V_9 ) ;
return - 1 ;
}
int F_11 ( unsigned char * V_30 , long V_31 ,
const unsigned char * V_10 , long V_32 , const T_1 * V_33 )
{
long V_7 , V_34 = 0 ;
unsigned char V_35 [ 4 ] ;
T_2 V_36 ;
unsigned char V_37 [ V_38 ] ;
int V_39 ;
int V_40 = - 1 ;
F_12 ( & V_36 ) ;
V_39 = F_13 ( V_33 ) ;
if ( V_39 < 0 )
goto V_41;
for ( V_7 = 0 ; V_34 < V_31 ; V_7 ++ )
{
V_35 [ 0 ] = ( unsigned char ) ( ( V_7 >> 24 ) & 255 ) ;
V_35 [ 1 ] = ( unsigned char ) ( ( V_7 >> 16 ) & 255 ) ;
V_35 [ 2 ] = ( unsigned char ) ( ( V_7 >> 8 ) ) & 255 ;
V_35 [ 3 ] = ( unsigned char ) ( V_7 & 255 ) ;
if ( ! F_14 ( & V_36 , V_33 , NULL )
|| ! F_15 ( & V_36 , V_10 , V_32 )
|| ! F_15 ( & V_36 , V_35 , 4 ) )
goto V_41;
if ( V_34 + V_39 <= V_31 )
{
if ( ! F_16 ( & V_36 , V_30 + V_34 , NULL ) )
goto V_41;
V_34 += V_39 ;
}
else
{
if ( ! F_16 ( & V_36 , V_37 , NULL ) )
goto V_41;
memcpy ( V_30 + V_34 , V_37 , V_31 - V_34 ) ;
V_34 = V_31 ;
}
}
V_40 = 0 ;
V_41:
F_17 ( & V_36 ) ;
return V_40 ;
}
static int F_8 ( unsigned char * V_30 , long V_31 , const unsigned char * V_10 ,
long V_32 )
{
return F_11 ( V_30 , V_31 , V_10 , V_32 , F_4 () ) ;
}
