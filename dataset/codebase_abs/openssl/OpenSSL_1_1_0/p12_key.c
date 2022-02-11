int F_1 ( const char * V_1 , int V_2 , unsigned char * V_3 ,
int V_4 , int V_5 , int V_6 , int V_7 ,
unsigned char * V_8 , const T_1 * V_9 )
{
int V_10 ;
unsigned char * V_11 ;
int V_12 ;
if ( ! V_1 ) {
V_11 = NULL ;
V_12 = 0 ;
} else if ( ! F_2 ( V_1 , V_2 , & V_11 , & V_12 ) ) {
F_3 ( V_13 , V_14 ) ;
return 0 ;
}
V_10 = F_4 ( V_11 , V_12 , V_3 , V_4 ,
V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_10 <= 0 )
return 0 ;
F_5 ( V_11 , V_12 ) ;
return V_10 ;
}
int F_6 ( const char * V_1 , int V_2 , unsigned char * V_3 ,
int V_4 , int V_5 , int V_6 , int V_7 ,
unsigned char * V_8 , const T_1 * V_9 )
{
int V_10 ;
unsigned char * V_11 ;
int V_12 ;
if ( ! V_1 ) {
V_11 = NULL ;
V_12 = 0 ;
} else if ( ! F_7 ( V_1 , V_2 , & V_11 , & V_12 ) ) {
F_3 ( V_15 , V_14 ) ;
return 0 ;
}
V_10 = F_4 ( V_11 , V_12 , V_3 , V_4 ,
V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if ( V_10 <= 0 )
return 0 ;
F_5 ( V_11 , V_12 ) ;
return V_10 ;
}
int F_4 ( unsigned char * V_1 , int V_2 , unsigned char * V_3 ,
int V_4 , int V_5 , int V_6 , int V_7 ,
unsigned char * V_8 , const T_1 * V_9 )
{
unsigned char * V_16 = NULL , * V_17 = NULL , * V_18 = NULL , * V_19 = NULL , * V_20 = NULL ;
int V_21 , V_22 , V_23 , V_24 ;
int V_25 , V_26 , V_27 , V_28 ;
int V_10 = 0 ;
T_2 * V_29 = NULL , * V_30 = NULL ;
T_3 * V_31 = NULL ;
#ifdef F_8
unsigned char * V_32 = V_8 ;
int V_33 = V_7 ;
#endif
V_31 = F_9 () ;
if ( V_31 == NULL )
goto V_34;
#ifdef F_8
fprintf ( V_35 , L_1 ) ;
fprintf ( V_35 , L_2 , V_5 , V_6 ) ;
fprintf ( V_35 , L_3 , V_2 ) ;
F_10 ( V_1 , V_2 ) ;
fprintf ( V_35 , L_4 , V_4 ) ;
F_10 ( V_3 , V_4 ) ;
#endif
V_28 = F_11 ( V_9 ) ;
V_27 = F_12 ( V_9 ) ;
if ( V_27 < 0 || V_28 <= 0 )
goto V_34;
V_17 = F_13 ( V_28 ) ;
V_20 = F_13 ( V_27 ) ;
V_16 = F_13 ( V_28 + 1 ) ;
V_21 = V_28 * ( ( V_4 + V_28 - 1 ) / V_28 ) ;
if ( V_2 )
V_22 = V_28 * ( ( V_2 + V_28 - 1 ) / V_28 ) ;
else
V_22 = 0 ;
V_23 = V_21 + V_22 ;
V_18 = F_13 ( V_23 ) ;
V_29 = F_14 () ;
V_30 = F_14 () ;
if ( V_17 == NULL || V_20 == NULL || V_16 == NULL || V_18 == NULL || V_29 == NULL
|| V_30 == NULL )
goto V_34;
for ( V_25 = 0 ; V_25 < V_28 ; V_25 ++ )
V_17 [ V_25 ] = V_5 ;
V_19 = V_18 ;
for ( V_25 = 0 ; V_25 < V_21 ; V_25 ++ )
* V_19 ++ = V_3 [ V_25 % V_4 ] ;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 ++ )
* V_19 ++ = V_1 [ V_25 % V_2 ] ;
for (; ; ) {
if ( ! F_15 ( V_31 , V_9 , NULL )
|| ! F_16 ( V_31 , V_17 , V_28 )
|| ! F_16 ( V_31 , V_18 , V_23 )
|| ! F_17 ( V_31 , V_20 , NULL ) )
goto V_34;
for ( V_26 = 1 ; V_26 < V_6 ; V_26 ++ ) {
if ( ! F_15 ( V_31 , V_9 , NULL )
|| ! F_16 ( V_31 , V_20 , V_27 )
|| ! F_17 ( V_31 , V_20 , NULL ) )
goto V_34;
}
memcpy ( V_8 , V_20 , F_18 ( V_7 , V_27 ) ) ;
if ( V_27 >= V_7 ) {
#ifdef F_8
fprintf ( V_35 , L_5 , V_33 ) ;
F_10 ( V_32 , V_33 ) ;
#endif
V_10 = 1 ;
goto V_36;
}
V_7 -= V_27 ;
V_8 += V_27 ;
for ( V_26 = 0 ; V_26 < V_28 ; V_26 ++ )
V_16 [ V_26 ] = V_20 [ V_26 % V_27 ] ;
if ( ! F_19 ( V_16 , V_28 , V_30 ) )
goto V_34;
if ( ! F_20 ( V_30 , 1 ) )
goto V_34;
for ( V_26 = 0 ; V_26 < V_23 ; V_26 += V_28 ) {
if ( ! F_19 ( V_18 + V_26 , V_28 , V_29 ) )
goto V_34;
if ( ! F_21 ( V_29 , V_29 , V_30 ) )
goto V_34;
if ( ! F_22 ( V_29 , V_16 ) )
goto V_34;
V_24 = F_23 ( V_29 ) ;
if ( V_24 > V_28 ) {
if ( ! F_22 ( V_29 , V_16 ) )
goto V_34;
memcpy ( V_18 + V_26 , V_16 + 1 , V_28 ) ;
#ifndef F_24
} else if ( V_24 < V_28 ) {
memset ( V_18 + V_26 , 0 , V_28 - V_24 ) ;
if ( ! F_22 ( V_29 , V_18 + V_26 + V_28 - V_24 ) )
goto V_34;
#endif
} else if ( ! F_22 ( V_29 , V_18 + V_26 ) )
goto V_34;
}
}
V_34:
F_3 ( V_37 , V_14 ) ;
V_36:
F_25 ( V_20 ) ;
F_25 ( V_16 ) ;
F_25 ( V_17 ) ;
F_25 ( V_18 ) ;
F_26 ( V_29 ) ;
F_26 ( V_30 ) ;
F_27 ( V_31 ) ;
return V_10 ;
}
void F_10 ( unsigned char * V_19 , int V_38 )
{
for (; V_38 -- ; V_19 ++ )
fprintf ( V_35 , L_6 , * V_19 ) ;
fprintf ( V_35 , L_7 ) ;
}
