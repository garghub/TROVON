unsigned char * F_1 ( T_1 * V_1 , const char * V_2 ,
int V_3 , unsigned char * V_4 , int V_5 , unsigned char * * V_6 ,
int * V_7 , int V_8 )
{
unsigned char * V_9 ;
int V_10 , V_11 ;
T_2 V_12 ;
if( ! ( V_9 = Malloc ( V_5 + 8 ) ) ) {
F_2 ( V_13 , V_14 ) ;
return NULL ;
}
if ( ! F_3 ( V_1 , V_2 , V_3 , & V_12 , V_8 ) ) {
F_2 ( V_13 , V_15 ) ;
return NULL ;
}
F_4 ( & V_12 , V_9 , & V_11 , V_4 , V_5 ) ;
V_10 = V_11 ;
if( ! F_5 ( & V_12 , V_9 + V_11 , & V_11 ) ) {
Free ( V_9 ) ;
F_2 ( V_13 , V_16 ) ;
return NULL ;
}
V_10 += V_11 ;
if ( V_7 ) * V_7 = V_10 ;
if ( V_6 ) * V_6 = V_9 ;
return V_9 ;
}
char * F_6 ( T_1 * V_1 , char * (* F_7)() ,
void (* F_8)() , const char * V_2 , int V_3 ,
T_3 * V_17 , int V_18 )
{
unsigned char * V_9 , * V_19 ;
char * V_20 ;
int V_10 ;
if ( ! F_1 ( V_1 , V_2 , V_3 , V_17 -> V_6 , V_17 -> V_21 ,
& V_9 , & V_10 , 0 ) ) {
F_2 ( V_22 , V_23 ) ;
return NULL ;
}
V_19 = V_9 ;
#ifdef F_9
{
T_4 * V_24 ;
char V_25 [ 30 ] ;
static int V_26 = 1 ;
sprintf ( V_25 , L_1 , V_26 ++ ) ;
V_24 = fopen ( V_25 , L_2 ) ;
fwrite ( V_19 , 1 , V_10 , V_24 ) ;
fclose ( V_24 ) ;
}
#endif
if ( V_18 & 1 ) V_20 = ( char * ) F_10 ( NULL , & V_19 , V_10 , F_7 ,
F_8 , V_27 , V_28 ) ;
else V_20 = F_7 ( NULL , & V_19 , V_10 ) ;
if ( V_18 & 2 ) memset ( V_9 , 0 , V_10 ) ;
if( ! V_20 ) F_2 ( V_22 , V_29 ) ;
Free ( V_9 ) ;
return V_20 ;
}
T_3 * F_11 ( T_1 * V_1 , int (* F_12)() ,
const char * V_2 , int V_3 ,
char * V_30 , int V_18 )
{
T_3 * V_17 ;
unsigned char * V_4 , * V_19 ;
int V_5 ;
if ( ! ( V_17 = F_13 () ) ) {
F_2 ( V_31 , V_14 ) ;
return NULL ;
}
if ( V_18 ) V_5 = F_14 ( ( V_32 * ) V_30 , NULL , F_12 , V_27 ,
V_28 , V_33 ) ;
else V_5 = F_12 ( V_30 , NULL ) ;
if ( ! V_5 ) {
F_2 ( V_31 , V_34 ) ;
return NULL ;
}
if ( ! ( V_4 = Malloc ( V_5 ) ) ) {
F_2 ( V_31 , V_14 ) ;
return NULL ;
}
V_19 = V_4 ;
if ( V_18 ) F_14 ( ( V_32 * ) V_30 , & V_19 , F_12 , V_27 ,
V_28 , V_33 ) ;
else F_12 ( V_30 , & V_19 ) ;
if ( ! F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , & V_17 -> V_6 ,
& V_17 -> V_21 , 1 ) ) {
F_2 ( V_31 , V_35 ) ;
Free ( V_4 ) ;
return NULL ;
}
Free ( V_4 ) ;
return V_17 ;
}
