static int F_1 ( T_1 * V_1 )
{
T_2 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) ) ;
if ( V_2 == NULL )
return 0 ;
V_1 -> V_3 = V_2 ;
return 1 ;
}
static void F_3 ( T_1 * V_1 )
{
T_2 * V_2 = V_1 -> V_3 ;
F_4 ( V_2 -> V_4 , V_2 -> V_5 ) ;
F_4 ( V_2 -> V_6 , V_2 -> V_7 ) ;
F_5 ( V_2 -> V_8 , V_2 -> V_9 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( T_1 * V_1 , int type , int V_10 , void * V_11 )
{
T_2 * V_2 = V_1 -> V_3 ;
switch ( type ) {
case V_12 :
if ( V_11 == NULL )
return 0 ;
V_2 -> V_13 = V_11 ;
return 1 ;
case V_14 :
if ( V_10 == 0 || V_11 == NULL )
return 1 ;
if ( V_10 < 0 )
return 0 ;
if ( V_2 -> V_4 != NULL )
F_4 ( V_2 -> V_4 , V_2 -> V_5 ) ;
V_2 -> V_4 = F_8 ( V_11 , V_10 ) ;
if ( V_2 -> V_4 == NULL )
return 0 ;
V_2 -> V_5 = V_10 ;
return 1 ;
case V_15 :
if ( V_10 < 0 )
return 0 ;
if ( V_2 -> V_6 != NULL )
F_4 ( V_2 -> V_6 , V_2 -> V_7 ) ;
V_2 -> V_6 = F_8 ( V_11 , V_10 ) ;
if ( V_2 -> V_6 == NULL )
return 0 ;
V_2 -> V_7 = V_10 ;
return 1 ;
case V_16 :
if ( V_10 == 0 || V_11 == NULL )
return 1 ;
if ( V_10 < 0 || V_10 > ( int ) ( V_17 - V_2 -> V_9 ) )
return 0 ;
memcpy ( V_2 -> V_8 + V_2 -> V_9 , V_11 , V_10 ) ;
V_2 -> V_9 += V_10 ;
return 1 ;
default:
return - 2 ;
}
}
static int F_9 ( T_1 * V_1 , const char * type ,
const char * V_18 )
{
if ( strcmp ( type , L_1 ) == 0 )
return F_10 ( V_1 , F_11 ( V_18 ) ) ;
if ( strcmp ( type , L_2 ) == 0 )
return F_12 ( V_1 , V_14 , V_18 ) ;
if ( strcmp ( type , L_3 ) == 0 )
return F_13 ( V_1 , V_14 , V_18 ) ;
if ( strcmp ( type , L_4 ) == 0 )
return F_12 ( V_1 , V_15 , V_18 ) ;
if ( strcmp ( type , L_5 ) == 0 )
return F_13 ( V_1 , V_15 , V_18 ) ;
if ( strcmp ( type , L_6 ) == 0 )
return F_12 ( V_1 , V_16 , V_18 ) ;
if ( strcmp ( type , L_7 ) == 0 )
return F_13 ( V_1 , V_16 , V_18 ) ;
return - 2 ;
}
static int F_14 ( T_1 * V_1 , unsigned char * V_6 ,
T_3 * V_19 )
{
T_2 * V_2 = V_1 -> V_3 ;
if ( V_2 -> V_13 == NULL || V_2 -> V_6 == NULL )
return 0 ;
if ( F_15 ( V_2 -> V_13 , V_2 -> V_4 , V_2 -> V_5 , V_2 -> V_6 , V_2 -> V_7 ,
V_2 -> V_8 , V_2 -> V_9 , V_6 , * V_19 ) == NULL )
{
return 0 ;
}
return 1 ;
}
static unsigned char * F_15 ( const T_4 * V_20 ,
const unsigned char * V_4 , T_3 V_5 ,
const unsigned char * V_6 , T_3 V_7 ,
const unsigned char * V_8 , T_3 V_9 ,
unsigned char * V_21 , T_3 V_22 )
{
unsigned char V_23 [ V_24 ] ;
T_3 V_25 ;
if ( ! F_16 ( V_20 , V_4 , V_5 , V_6 , V_7 , V_23 , & V_25 ) )
return NULL ;
return F_17 ( V_20 , V_23 , V_25 , V_8 , V_9 , V_21 , V_22 ) ;
}
static unsigned char * F_16 ( const T_4 * V_20 ,
const unsigned char * V_4 , T_3 V_5 ,
const unsigned char * V_6 , T_3 V_7 ,
unsigned char * V_23 , T_3 * V_25 )
{
unsigned int V_26 ;
if ( ! F_18 ( V_20 , V_4 , V_5 , V_6 , V_7 , V_23 , & V_26 ) )
return NULL ;
* V_25 = V_26 ;
return V_23 ;
}
static unsigned char * F_17 ( const T_4 * V_20 ,
const unsigned char * V_23 , T_3 V_25 ,
const unsigned char * V_8 , T_3 V_9 ,
unsigned char * V_21 , T_3 V_22 )
{
T_5 * V_27 ;
unsigned int V_28 ;
unsigned char V_29 [ V_24 ] ;
T_3 V_30 = 0 , V_31 = F_19 ( V_20 ) ;
T_3 V_32 = V_22 / V_31 ;
if ( V_22 % V_31 )
V_32 ++ ;
if ( V_32 > 255 )
return NULL ;
if ( ( V_27 = F_20 () ) == NULL )
return NULL ;
if ( ! F_21 ( V_27 , V_23 , V_25 , V_20 , NULL ) )
goto V_33;
for ( V_28 = 1 ; V_28 <= V_32 ; V_28 ++ ) {
T_3 V_34 ;
const unsigned char V_35 = V_28 ;
if ( V_28 > 1 ) {
if ( ! F_21 ( V_27 , NULL , 0 , NULL , NULL ) )
goto V_33;
if ( ! F_22 ( V_27 , V_29 , V_31 ) )
goto V_33;
}
if ( ! F_22 ( V_27 , V_8 , V_9 ) )
goto V_33;
if ( ! F_22 ( V_27 , & V_35 , 1 ) )
goto V_33;
if ( ! F_23 ( V_27 , V_29 , NULL ) )
goto V_33;
V_34 = ( V_30 + V_31 > V_22 ) ?
V_22 - V_30 :
V_31 ;
memcpy ( V_21 + V_30 , V_29 , V_34 ) ;
V_30 += V_34 ;
}
F_24 ( V_27 ) ;
return V_21 ;
V_33:
F_24 ( V_27 ) ;
return NULL ;
}
