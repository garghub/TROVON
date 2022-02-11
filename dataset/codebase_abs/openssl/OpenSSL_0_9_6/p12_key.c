int F_1 ( const char * V_1 , int V_2 , unsigned char * V_3 ,
int V_4 , int V_5 , int V_6 , int V_7 , unsigned char * V_8 ,
const T_1 * V_9 )
{
int V_10 ;
unsigned char * V_11 ;
int V_12 ;
if( ! V_1 ) {
V_11 = NULL ;
V_12 = 0 ;
} else if ( ! F_2 ( V_1 , & V_11 , & V_12 ) ) {
F_3 ( V_13 , V_14 ) ;
return 0 ;
}
V_10 = F_4 ( V_11 , V_12 , V_3 , V_4 ,
V_5 , V_6 , V_7 , V_8 , V_9 ) ;
if( V_11 ) {
memset ( V_11 , 0 , V_12 ) ;
F_5 ( V_11 ) ;
}
return V_10 ;
}
int F_4 ( unsigned char * V_1 , int V_2 , unsigned char * V_3 ,
int V_4 , int V_5 , int V_6 , int V_7 , unsigned char * V_8 ,
const T_1 * V_9 )
{
unsigned char * V_15 , * V_16 , * V_17 , * V_18 , * V_19 ;
int V_20 , V_21 , V_22 ;
int V_23 , V_24 , V_25 , V_26 ;
T_2 * V_27 , * V_28 ;
T_3 V_29 ;
#ifdef F_6
unsigned char * V_30 = V_8 ;
int V_31 = V_7 ;
#endif
#if 0
if (!pass) {
PKCS12err(PKCS12_F_PKCS12_KEY_GEN_UNI,ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
#endif
#ifdef F_6
fprintf ( V_32 , L_1 ) ;
fprintf ( V_32 , L_2 , V_5 , V_6 ) ;
fprintf ( V_32 , L_3 , V_2 ) ;
F_7 ( V_1 , V_2 ) ;
fprintf ( V_32 , L_4 , V_4 ) ;
F_7 ( V_3 , V_4 ) ;
#endif
V_26 = F_8 ( V_9 ) ;
V_25 = F_9 ( V_9 ) ;
V_16 = F_10 ( V_26 ) ;
V_19 = F_10 ( V_25 ) ;
V_15 = F_10 ( V_26 + 1 ) ;
V_20 = V_26 * ( ( V_4 + V_26 - 1 ) / V_26 ) ;
if( V_2 ) V_21 = V_26 * ( ( V_2 + V_26 - 1 ) / V_26 ) ;
else V_21 = 0 ;
V_22 = V_20 + V_21 ;
V_17 = F_10 ( V_22 ) ;
V_27 = F_11 () ;
V_28 = F_11 () ;
if ( ! V_16 || ! V_19 || ! V_15 || ! V_17 || ! V_27 || ! V_28 ) {
F_3 ( V_33 , V_14 ) ;
return 0 ;
}
for ( V_23 = 0 ; V_23 < V_26 ; V_23 ++ ) V_16 [ V_23 ] = V_5 ;
V_18 = V_17 ;
for ( V_23 = 0 ; V_23 < V_20 ; V_23 ++ ) * V_18 ++ = V_3 [ V_23 % V_4 ] ;
for ( V_23 = 0 ; V_23 < V_21 ; V_23 ++ ) * V_18 ++ = V_1 [ V_23 % V_2 ] ;
for (; ; ) {
F_12 ( & V_29 , V_9 ) ;
F_13 ( & V_29 , V_16 , V_26 ) ;
F_13 ( & V_29 , V_17 , V_22 ) ;
F_14 ( & V_29 , V_19 , NULL ) ;
for ( V_24 = 1 ; V_24 < V_6 ; V_24 ++ ) {
F_12 ( & V_29 , V_9 ) ;
F_13 ( & V_29 , V_19 , V_25 ) ;
F_14 ( & V_29 , V_19 , NULL ) ;
}
memcpy ( V_8 , V_19 , F_15 ( V_7 , V_25 ) ) ;
if ( V_25 >= V_7 ) {
F_5 ( V_19 ) ;
F_5 ( V_15 ) ;
F_5 ( V_16 ) ;
F_5 ( V_17 ) ;
F_16 ( V_27 ) ;
F_16 ( V_28 ) ;
#ifdef F_6
fprintf ( V_32 , L_5 , V_31 ) ;
F_7 ( V_30 , V_31 ) ;
#endif
return 1 ;
}
V_7 -= V_25 ;
V_8 += V_25 ;
for ( V_24 = 0 ; V_24 < V_26 ; V_24 ++ ) V_15 [ V_24 ] = V_19 [ V_24 % V_25 ] ;
F_17 ( V_15 , V_26 , V_28 ) ;
F_18 ( V_28 , 1 ) ;
for ( V_24 = 0 ; V_24 < V_22 ; V_24 += V_26 ) {
F_17 ( V_17 + V_24 , V_26 , V_27 ) ;
F_19 ( V_27 , V_27 , V_28 ) ;
F_20 ( V_27 , V_15 ) ;
if ( F_21 ( V_27 ) > V_26 ) {
F_20 ( V_27 , V_15 ) ;
memcpy ( V_17 + V_24 , V_15 + 1 , V_26 ) ;
} else F_20 ( V_27 , V_17 + V_24 ) ;
}
}
}
void F_7 ( unsigned char * V_18 , int V_34 )
{
for (; V_34 -- ; V_18 ++ ) fprintf ( V_32 , L_6 , * V_18 ) ;
fprintf ( V_32 , L_7 ) ;
}
