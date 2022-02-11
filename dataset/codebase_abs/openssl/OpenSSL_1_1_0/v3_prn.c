int F_1 ( T_1 * V_1 , T_2 * V_2 , unsigned long V_3 ,
int V_4 )
{
void * V_5 = NULL ;
char * V_6 = NULL ;
T_3 * V_7 ;
const unsigned char * V_8 ;
int V_9 ;
const T_4 * V_10 ;
F_2 ( V_11 ) * V_12 = NULL ;
int V_13 = 1 ;
V_7 = F_3 ( V_2 ) ;
V_8 = F_4 ( V_7 ) ;
V_9 = F_5 ( V_7 ) ;
if ( ( V_10 = F_6 ( V_2 ) ) == NULL )
return F_7 ( V_1 , V_8 , V_9 , V_3 , V_4 , 0 ) ;
if ( V_10 -> V_14 )
V_5 = F_8 ( NULL , & V_8 , V_9 , F_9 ( V_10 -> V_14 ) ) ;
else
V_5 = V_10 -> V_15 ( NULL , & V_8 , V_9 ) ;
if ( ! V_5 )
return F_7 ( V_1 , V_8 , V_9 , V_3 , V_4 , 1 ) ;
if ( V_10 -> V_16 ) {
if ( ( V_6 = V_10 -> V_16 ( V_10 , V_5 ) ) == NULL ) {
V_13 = 0 ;
goto V_17;
}
#ifndef F_10
F_11 ( V_1 , L_1 , V_4 , L_2 , V_6 ) ;
#else
{
int V_18 ;
char * V_19 ;
V_18 = strlen ( V_6 ) + 1 ;
V_19 = F_12 ( V_18 ) ;
if ( V_19 != NULL ) {
F_13 ( V_19 , V_6 , V_18 ) ;
F_11 ( V_1 , L_1 , V_4 , L_2 , V_19 ) ;
F_14 ( V_19 ) ;
}
}
#endif
} else if ( V_10 -> V_20 ) {
if ( ( V_12 = V_10 -> V_20 ( V_10 , V_5 , NULL ) ) == NULL ) {
V_13 = 0 ;
goto V_17;
}
F_15 ( V_1 , V_12 , V_4 ,
V_10 -> V_21 & V_22 ) ;
} else if ( V_10 -> V_23 ) {
if ( ! V_10 -> V_23 ( V_10 , V_5 , V_1 , V_4 ) )
V_13 = 0 ;
} else
V_13 = 0 ;
V_17:
F_16 ( V_12 , V_24 ) ;
F_14 ( V_6 ) ;
if ( V_10 -> V_14 )
F_17 ( V_5 , F_9 ( V_10 -> V_14 ) ) ;
else
V_10 -> V_25 ( V_5 ) ;
return V_13 ;
}
static int F_7 ( T_1 * V_1 , const unsigned char * V_2 , int V_9 ,
unsigned long V_3 , int V_4 , int V_26 )
{
switch ( V_3 & V_27 ) {
case V_28 :
return 0 ;
case V_29 :
if ( V_26 )
F_11 ( V_1 , L_3 , V_4 , L_2 ) ;
else
F_11 ( V_1 , L_4 , V_4 , L_2 ) ;
return 1 ;
case V_30 :
return F_18 ( V_1 , V_2 , V_9 , V_4 , - 1 ) ;
case V_31 :
return F_19 ( V_1 , ( const char * ) V_2 , V_9 , V_4 ) ;
default:
return 1 ;
}
}
int F_20 ( T_5 * V_32 , T_2 * V_2 , int V_3 , int V_4 )
{
T_1 * V_33 ;
int V_34 ;
if ( ( V_33 = F_21 ( V_32 , V_35 ) ) == NULL )
return 0 ;
V_34 = F_1 ( V_33 , V_2 , V_3 , V_4 ) ;
F_22 ( V_33 ) ;
return V_34 ;
}
