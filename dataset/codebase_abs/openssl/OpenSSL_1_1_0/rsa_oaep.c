int F_1 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
const unsigned char * V_5 , int V_6 )
{
return F_2 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , NULL , NULL ) ;
}
int F_2 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
const unsigned char * V_5 , int V_6 ,
const T_1 * V_7 , const T_1 * V_8 )
{
int V_9 , V_10 = V_2 - 1 ;
unsigned char * V_11 , * V_12 ;
unsigned char * V_13 , V_14 [ V_15 ] ;
int V_16 ;
if ( V_7 == NULL )
V_7 = F_3 () ;
if ( V_8 == NULL )
V_8 = V_7 ;
V_16 = F_4 ( V_7 ) ;
if ( V_4 > V_10 - 2 * V_16 - 1 ) {
F_5 ( V_17 ,
V_18 ) ;
return 0 ;
}
if ( V_10 < 2 * V_16 + 1 ) {
F_5 ( V_17 ,
V_19 ) ;
return 0 ;
}
V_1 [ 0 ] = 0 ;
V_12 = V_1 + 1 ;
V_11 = V_1 + V_16 + 1 ;
if ( ! F_6 ( ( void * ) V_5 , V_6 , V_11 , NULL , V_7 , NULL ) )
return 0 ;
memset ( V_11 + V_16 , 0 , V_10 - V_4 - 2 * V_16 - 1 ) ;
V_11 [ V_10 - V_4 - V_16 - 1 ] = 0x01 ;
memcpy ( V_11 + V_10 - V_4 - V_16 , V_3 , ( unsigned int ) V_4 ) ;
if ( F_7 ( V_12 , V_16 ) <= 0 )
return 0 ;
#ifdef F_8
memcpy ( V_12 ,
L_1 ,
20 ) ;
#endif
V_13 = F_9 ( V_10 - V_16 ) ;
if ( V_13 == NULL ) {
F_5 ( V_17 , V_20 ) ;
return 0 ;
}
if ( F_10 ( V_13 , V_10 - V_16 , V_12 , V_16 , V_8 ) < 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_10 - V_16 ; V_9 ++ )
V_11 [ V_9 ] ^= V_13 [ V_9 ] ;
if ( F_10 ( V_14 , V_16 , V_11 , V_10 - V_16 , V_8 ) < 0 )
return 0 ;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
V_12 [ V_9 ] ^= V_14 [ V_9 ] ;
F_11 ( V_13 ) ;
return 1 ;
}
int F_12 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 , int V_21 ,
const unsigned char * V_5 , int V_6 )
{
return F_13 ( V_1 , V_2 , V_3 , V_4 , V_21 ,
V_5 , V_6 , NULL , NULL ) ;
}
int F_13 ( unsigned char * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
int V_21 , const unsigned char * V_5 ,
int V_6 , const T_1 * V_7 ,
const T_1 * V_8 )
{
int V_9 , V_22 , V_23 = - 1 , V_24 = 0 , V_25 ;
unsigned int V_26 , V_27 ;
const unsigned char * V_28 , * V_29 ;
unsigned char * V_11 = NULL , * V_30 = NULL , V_12 [ V_15 ] ,
V_31 [ V_15 ] ;
int V_16 ;
if ( V_7 == NULL )
V_7 = F_3 () ;
if ( V_8 == NULL )
V_8 = V_7 ;
V_16 = F_4 ( V_7 ) ;
if ( V_2 <= 0 || V_4 <= 0 )
return - 1 ;
if ( V_21 < V_4 || V_21 < 2 * V_16 + 2 )
goto V_32;
V_22 = V_21 - V_16 - 1 ;
V_11 = F_9 ( V_22 ) ;
V_30 = F_9 ( V_21 ) ;
if ( V_11 == NULL || V_30 == NULL ) {
F_5 ( V_33 , V_20 ) ;
goto V_34;
}
memset ( V_30 , 0 , V_21 ) ;
memcpy ( V_30 + V_21 - V_4 , V_3 , V_4 ) ;
V_26 = F_14 ( V_30 [ 0 ] ) ;
V_28 = V_30 + 1 ;
V_29 = V_30 + 1 + V_16 ;
if ( F_10 ( V_12 , V_16 , V_29 , V_22 , V_8 ) )
goto V_34;
for ( V_9 = 0 ; V_9 < V_16 ; V_9 ++ )
V_12 [ V_9 ] ^= V_28 [ V_9 ] ;
if ( F_10 ( V_11 , V_22 , V_12 , V_16 , V_8 ) )
goto V_34;
for ( V_9 = 0 ; V_9 < V_22 ; V_9 ++ )
V_11 [ V_9 ] ^= V_29 [ V_9 ] ;
if ( ! F_6 ( ( void * ) V_5 , V_6 , V_31 , NULL , V_7 , NULL ) )
goto V_34;
V_26 &= F_14 ( F_15 ( V_11 , V_31 , V_16 ) ) ;
V_27 = 0 ;
for ( V_9 = V_16 ; V_9 < V_22 ; V_9 ++ ) {
unsigned int V_35 = F_16 ( V_11 [ V_9 ] , 1 ) ;
unsigned int V_36 = F_14 ( V_11 [ V_9 ] ) ;
V_24 = F_17 ( ~ V_27 & V_35 ,
V_9 , V_24 ) ;
V_27 |= V_35 ;
V_26 &= ( V_27 | V_36 ) ;
}
V_26 &= V_27 ;
if ( ! V_26 )
goto V_32;
V_25 = V_24 + 1 ;
V_23 = V_22 - V_25 ;
if ( V_2 < V_23 ) {
F_5 ( V_33 , V_37 ) ;
V_23 = - 1 ;
} else {
memcpy ( V_1 , V_11 + V_25 , V_23 ) ;
goto V_34;
}
V_32:
F_5 ( V_33 ,
V_38 ) ;
V_34:
F_11 ( V_11 ) ;
F_11 ( V_30 ) ;
return V_23 ;
}
int F_10 ( unsigned char * V_39 , long V_40 ,
const unsigned char * V_12 , long V_41 , const T_1 * V_42 )
{
long V_9 , V_43 = 0 ;
unsigned char V_44 [ 4 ] ;
T_2 * V_45 = F_18 () ;
unsigned char V_7 [ V_15 ] ;
int V_16 ;
int V_46 = - 1 ;
if ( V_45 == NULL )
goto V_47;
V_16 = F_4 ( V_42 ) ;
if ( V_16 < 0 )
goto V_47;
for ( V_9 = 0 ; V_43 < V_40 ; V_9 ++ ) {
V_44 [ 0 ] = ( unsigned char ) ( ( V_9 >> 24 ) & 255 ) ;
V_44 [ 1 ] = ( unsigned char ) ( ( V_9 >> 16 ) & 255 ) ;
V_44 [ 2 ] = ( unsigned char ) ( ( V_9 >> 8 ) ) & 255 ;
V_44 [ 3 ] = ( unsigned char ) ( V_9 & 255 ) ;
if ( ! F_19 ( V_45 , V_42 , NULL )
|| ! F_20 ( V_45 , V_12 , V_41 )
|| ! F_20 ( V_45 , V_44 , 4 ) )
goto V_47;
if ( V_43 + V_16 <= V_40 ) {
if ( ! F_21 ( V_45 , V_39 + V_43 , NULL ) )
goto V_47;
V_43 += V_16 ;
} else {
if ( ! F_21 ( V_45 , V_7 , NULL ) )
goto V_47;
memcpy ( V_39 + V_43 , V_7 , V_40 - V_43 ) ;
V_43 = V_40 ;
}
}
V_46 = 0 ;
V_47:
F_22 ( V_45 ) ;
return V_46 ;
}
