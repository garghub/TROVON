unsigned char * F_1 ( T_1 * V_1 , const char * V_2 ,
int V_3 , unsigned char * V_4 , int V_5 , unsigned char * * V_6 ,
int * V_7 , int V_8 )
{
unsigned char * V_9 ;
int V_10 , V_11 ;
T_2 V_12 ;
F_2 ( & V_12 ) ;
if ( ! F_3 ( V_1 -> V_13 , V_2 , V_3 ,
V_1 -> V_14 , & V_12 , V_8 ) ) {
F_4 ( V_15 , V_16 ) ;
return NULL ;
}
if( ! ( V_9 = F_5 ( V_5 + F_6 ( & V_12 ) ) ) ) {
F_4 ( V_15 , V_17 ) ;
goto V_18;
}
if ( ! F_7 ( & V_12 , V_9 , & V_11 , V_4 , V_5 ) )
{
F_8 ( V_9 ) ;
V_9 = NULL ;
F_4 ( V_15 , V_19 ) ;
goto V_18;
}
V_10 = V_11 ;
if( ! F_9 ( & V_12 , V_9 + V_11 , & V_11 ) ) {
F_8 ( V_9 ) ;
V_9 = NULL ;
F_4 ( V_15 , V_20 ) ;
goto V_18;
}
V_10 += V_11 ;
if ( V_7 ) * V_7 = V_10 ;
if ( V_6 ) * V_6 = V_9 ;
V_18:
F_10 ( & V_12 ) ;
return V_9 ;
}
void * F_11 ( T_1 * V_1 , const T_3 * V_21 ,
const char * V_2 , int V_3 , T_4 * V_22 , int V_23 )
{
unsigned char * V_9 ;
const unsigned char * V_24 ;
void * V_25 ;
int V_10 ;
if ( ! F_1 ( V_1 , V_2 , V_3 , V_22 -> V_6 , V_22 -> V_26 ,
& V_9 , & V_10 , 0 ) ) {
F_4 ( V_27 , V_28 ) ;
return NULL ;
}
V_24 = V_9 ;
#ifdef F_12
{
T_5 * V_29 ;
char V_30 [ 30 ] ;
static int V_31 = 1 ;
sprintf ( V_30 , L_1 , V_31 ++ ) ;
V_29 = fopen ( V_30 , L_2 ) ;
fwrite ( V_24 , 1 , V_10 , V_29 ) ;
fclose ( V_29 ) ;
}
#endif
V_25 = F_13 ( NULL , & V_24 , V_10 , V_21 ) ;
if ( V_23 ) F_14 ( V_9 , V_10 ) ;
if( ! V_25 ) F_4 ( V_27 , V_32 ) ;
F_8 ( V_9 ) ;
return V_25 ;
}
T_4 * F_15 ( T_1 * V_1 , const T_3 * V_21 ,
const char * V_2 , int V_3 ,
void * V_33 , int V_23 )
{
T_4 * V_22 ;
unsigned char * V_4 = NULL ;
int V_5 ;
if ( ! ( V_22 = F_16 () ) ) {
F_4 ( V_34 , V_17 ) ;
return NULL ;
}
V_5 = F_17 ( V_33 , & V_4 , V_21 ) ;
if ( ! V_4 ) {
F_4 ( V_34 , V_35 ) ;
return NULL ;
}
if ( ! F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , & V_22 -> V_6 ,
& V_22 -> V_26 , 1 ) ) {
F_4 ( V_34 , V_36 ) ;
F_8 ( V_4 ) ;
return NULL ;
}
if ( V_23 ) F_14 ( V_4 , V_5 ) ;
F_8 ( V_4 ) ;
return V_22 ;
}
