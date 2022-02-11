unsigned char * F_1 ( T_1 * V_1 , const char * V_2 ,
int V_3 , unsigned char * V_4 , int V_5 , unsigned char * * V_6 ,
int * V_7 , int V_8 )
{
unsigned char * V_9 ;
int V_10 , V_11 ;
T_2 V_12 ;
if ( ! F_2 ( V_1 -> V_13 , V_2 , V_3 ,
V_1 -> V_14 , & V_12 , V_8 ) ) {
F_3 ( V_15 , V_16 ) ;
return NULL ;
}
if( ! ( V_9 = Malloc ( V_5 + F_4 ( & V_12 ) ) ) ) {
F_3 ( V_15 , V_17 ) ;
return NULL ;
}
F_5 ( & V_12 , V_9 , & V_11 , V_4 , V_5 ) ;
V_10 = V_11 ;
if( ! F_6 ( & V_12 , V_9 + V_11 , & V_11 ) ) {
Free ( V_9 ) ;
F_3 ( V_15 , V_18 ) ;
return NULL ;
}
V_10 += V_11 ;
if ( V_7 ) * V_7 = V_10 ;
if ( V_6 ) * V_6 = V_9 ;
return V_9 ;
}
char * F_7 ( T_1 * V_1 , char * (* F_8)() ,
void (* F_9)() , const char * V_2 , int V_3 ,
T_3 * V_19 , int V_20 )
{
unsigned char * V_9 , * V_21 ;
char * V_22 ;
int V_10 ;
if ( ! F_1 ( V_1 , V_2 , V_3 , V_19 -> V_6 , V_19 -> V_23 ,
& V_9 , & V_10 , 0 ) ) {
F_3 ( V_24 , V_25 ) ;
return NULL ;
}
V_21 = V_9 ;
#ifdef F_10
{
T_4 * V_26 ;
char V_27 [ 30 ] ;
static int V_28 = 1 ;
sprintf ( V_27 , L_1 , V_28 ++ ) ;
V_26 = fopen ( V_27 , L_2 ) ;
fwrite ( V_21 , 1 , V_10 , V_26 ) ;
fclose ( V_26 ) ;
}
#endif
if ( V_20 & 1 ) V_22 = ( char * ) F_11 ( NULL , & V_21 , V_10 , F_8 ,
F_9 , V_29 , V_30 ) ;
else V_22 = F_8 ( NULL , & V_21 , V_10 ) ;
if ( V_20 & 2 ) memset ( V_9 , 0 , V_10 ) ;
if( ! V_22 ) F_3 ( V_24 , V_31 ) ;
Free ( V_9 ) ;
return V_22 ;
}
T_3 * F_12 ( T_1 * V_1 , int (* F_13)() ,
const char * V_2 , int V_3 ,
char * V_32 , int V_20 )
{
T_3 * V_19 ;
unsigned char * V_4 , * V_21 ;
int V_5 ;
if ( ! ( V_19 = F_14 () ) ) {
F_3 ( V_33 , V_17 ) ;
return NULL ;
}
if ( V_20 ) V_5 = F_15 ( ( V_34 * ) V_32 , NULL , F_13 , V_29 ,
V_30 , V_35 ) ;
else V_5 = F_13 ( V_32 , NULL ) ;
if ( ! V_5 ) {
F_3 ( V_33 , V_36 ) ;
return NULL ;
}
if ( ! ( V_4 = Malloc ( V_5 ) ) ) {
F_3 ( V_33 , V_17 ) ;
return NULL ;
}
V_21 = V_4 ;
if ( V_20 ) F_15 ( ( V_34 * ) V_32 , & V_21 , F_13 , V_29 ,
V_30 , V_35 ) ;
else F_13 ( V_32 , & V_21 ) ;
if ( ! F_1 ( V_1 , V_2 , V_3 , V_4 , V_5 , & V_19 -> V_6 ,
& V_19 -> V_23 , 1 ) ) {
F_3 ( V_33 , V_37 ) ;
Free ( V_4 ) ;
return NULL ;
}
Free ( V_4 ) ;
return V_19 ;
}
