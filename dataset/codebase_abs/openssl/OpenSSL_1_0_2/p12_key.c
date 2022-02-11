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
if ( V_11 ) {
F_5 ( V_11 , V_12 ) ;
F_6 ( V_11 ) ;
}
return V_10 ;
}
int F_4 ( unsigned char * V_1 , int V_2 , unsigned char * V_3 ,
int V_4 , int V_5 , int V_6 , int V_7 ,
unsigned char * V_8 , const T_1 * V_9 )
{
unsigned char * V_15 , * V_16 , * V_17 , * V_18 , * V_19 ;
int V_20 , V_21 , V_22 , V_23 ;
int V_24 , V_25 , V_26 , V_27 ;
int V_10 = 0 ;
T_2 * V_28 , * V_29 ;
T_3 V_30 ;
#ifdef F_7
unsigned char * V_31 = V_8 ;
int V_32 = V_7 ;
#endif
#if 0
if (!pass) {
PKCS12err(PKCS12_F_PKCS12_KEY_GEN_UNI, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
#endif
F_8 ( & V_30 ) ;
#ifdef F_7
fprintf ( V_33 , L_1 ) ;
fprintf ( V_33 , L_2 , V_5 , V_6 ) ;
fprintf ( V_33 , L_3 , V_2 ) ;
F_9 ( V_1 , V_2 ) ;
fprintf ( V_33 , L_4 , V_4 ) ;
F_9 ( V_3 , V_4 ) ;
#endif
V_27 = F_10 ( V_9 ) ;
V_26 = F_11 ( V_9 ) ;
if ( V_26 < 0 )
return 0 ;
V_16 = F_12 ( V_27 ) ;
V_19 = F_12 ( V_26 ) ;
V_15 = F_12 ( V_27 + 1 ) ;
V_20 = V_27 * ( ( V_4 + V_27 - 1 ) / V_27 ) ;
if ( V_2 )
V_21 = V_27 * ( ( V_2 + V_27 - 1 ) / V_27 ) ;
else
V_21 = 0 ;
V_22 = V_20 + V_21 ;
V_17 = F_12 ( V_22 ) ;
V_28 = F_13 () ;
V_29 = F_13 () ;
if ( ! V_16 || ! V_19 || ! V_15 || ! V_17 || ! V_28 || ! V_29 )
goto V_34;
for ( V_24 = 0 ; V_24 < V_27 ; V_24 ++ )
V_16 [ V_24 ] = V_5 ;
V_18 = V_17 ;
for ( V_24 = 0 ; V_24 < V_20 ; V_24 ++ )
* V_18 ++ = V_3 [ V_24 % V_4 ] ;
for ( V_24 = 0 ; V_24 < V_21 ; V_24 ++ )
* V_18 ++ = V_1 [ V_24 % V_2 ] ;
for (; ; ) {
if ( ! F_14 ( & V_30 , V_9 , NULL )
|| ! F_15 ( & V_30 , V_16 , V_27 )
|| ! F_15 ( & V_30 , V_17 , V_22 )
|| ! F_16 ( & V_30 , V_19 , NULL ) )
goto V_34;
for ( V_25 = 1 ; V_25 < V_6 ; V_25 ++ ) {
if ( ! F_14 ( & V_30 , V_9 , NULL )
|| ! F_15 ( & V_30 , V_19 , V_26 )
|| ! F_16 ( & V_30 , V_19 , NULL ) )
goto V_34;
}
memcpy ( V_8 , V_19 , F_17 ( V_7 , V_26 ) ) ;
if ( V_26 >= V_7 ) {
#ifdef F_7
fprintf ( V_33 , L_5 , V_32 ) ;
F_9 ( V_31 , V_32 ) ;
#endif
V_10 = 1 ;
goto V_35;
}
V_7 -= V_26 ;
V_8 += V_26 ;
for ( V_25 = 0 ; V_25 < V_27 ; V_25 ++ )
V_15 [ V_25 ] = V_19 [ V_25 % V_26 ] ;
if ( ! F_18 ( V_15 , V_27 , V_29 ) )
goto V_34;
if ( ! F_19 ( V_29 , 1 ) )
goto V_34;
for ( V_25 = 0 ; V_25 < V_22 ; V_25 += V_27 ) {
if ( ! F_18 ( V_17 + V_25 , V_27 , V_28 ) )
goto V_34;
if ( ! F_20 ( V_28 , V_28 , V_29 ) )
goto V_34;
if ( ! F_21 ( V_28 , V_15 ) )
goto V_34;
V_23 = F_22 ( V_28 ) ;
if ( V_23 > V_27 ) {
if ( ! F_21 ( V_28 , V_15 ) )
goto V_34;
memcpy ( V_17 + V_25 , V_15 + 1 , V_27 ) ;
#ifndef F_23
} else if ( V_23 < V_27 ) {
memset ( V_17 + V_25 , 0 , V_27 - V_23 ) ;
if ( ! F_21 ( V_28 , V_17 + V_25 + V_27 - V_23 ) )
goto V_34;
#endif
} else if ( ! F_21 ( V_28 , V_17 + V_25 ) )
goto V_34;
}
}
V_34:
F_3 ( V_36 , V_14 ) ;
V_35:
F_6 ( V_19 ) ;
F_6 ( V_15 ) ;
F_6 ( V_16 ) ;
F_6 ( V_17 ) ;
F_24 ( V_28 ) ;
F_24 ( V_29 ) ;
F_25 ( & V_30 ) ;
return V_10 ;
}
void F_9 ( unsigned char * V_18 , int V_37 )
{
for (; V_37 -- ; V_18 ++ )
fprintf ( V_33 , L_6 , * V_18 ) ;
fprintf ( V_33 , L_7 ) ;
}
