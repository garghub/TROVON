int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
if( V_1 -> V_3 ) F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_6 ) ;
F_4 () ;
if ( V_1 -> V_3 ) F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_6 ) ;
F_6 () ;
}
T_1 * F_7 ( void )
{
T_1 * V_7 = NULL ;
T_2 V_8 ;
F_8 ( V_7 , T_1 ) ;
V_7 -> V_3 = 0 ;
V_7 -> V_5 = NULL ;
return ( V_7 ) ;
F_9 ( V_9 ) ;
}
T_1 * F_10 ( T_1 * * V_1 ,
unsigned char * * V_2 , long V_10 )
{
F_11 ( V_1 , T_1 * , F_7 ) ;
F_12 () ;
F_13 () ;
if( ( V_11 & ( ~ V_12 ) ) ==
( V_13 | V_14 ) ) {
F_14 ( V_7 -> V_3 , V_15 ) ;
}
F_15 ( V_7 -> V_5 , V_16 , V_17 ) ;
F_16 ( V_1 , V_18 , V_19 ) ;
}
void V_18 ( T_1 * V_1 )
{
if ( V_1 == NULL ) return;
F_17 ( V_1 -> V_5 ) ;
Free ( ( char * ) V_1 ) ;
}
static T_3 * F_18 ( T_4 * V_20 ,
T_1 * V_21 , T_3 * V_22 )
{
F_19 ( L_1 , V_21 -> V_3 , & V_22 ) ;
F_20 ( L_2 , V_21 -> V_5 , & V_22 ) ;
return V_22 ;
}
static T_1 * F_21 ( T_4 * V_20 ,
T_5 * V_23 , T_3 * V_24 )
{
T_1 * V_21 = NULL ;
T_6 * V_25 ;
int V_26 ;
if( ! ( V_21 = F_7 () ) ) {
F_22 ( V_27 , V_28 ) ;
return NULL ;
}
for( V_26 = 0 ; V_26 < F_23 ( V_24 ) ; V_26 ++ ) {
V_25 = ( T_6 * ) F_24 ( V_24 , V_26 ) ;
if( ! strcmp ( V_25 -> V_29 , L_1 ) ) {
if( ! F_25 ( V_25 , & V_21 -> V_3 ) ) goto V_30;
} else if( ! strcmp ( V_25 -> V_29 , L_2 ) ) {
if( ! F_26 ( V_25 , & V_21 -> V_5 ) ) goto V_30;
} else {
F_22 ( V_27 , V_31 ) ;
F_27 ( V_25 ) ;
goto V_30;
}
}
return V_21 ;
V_30:
V_18 ( V_21 ) ;
return NULL ;
}
