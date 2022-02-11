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
F_5 ( V_2 -> V_6 , V_2 -> V_7 ) ;
F_6 ( V_2 ) ;
}
static int F_7 ( T_1 * V_1 , int type , int V_8 , void * V_9 )
{
T_2 * V_2 = V_1 -> V_3 ;
switch ( type ) {
case V_10 :
V_2 -> V_11 = V_9 ;
return 1 ;
case V_12 :
if ( V_8 < 0 )
return 0 ;
if ( V_2 -> V_4 != NULL )
F_4 ( V_2 -> V_4 , V_2 -> V_5 ) ;
F_5 ( V_2 -> V_6 , V_2 -> V_7 ) ;
V_2 -> V_7 = 0 ;
V_2 -> V_4 = F_8 ( V_9 , V_8 ) ;
if ( V_2 -> V_4 == NULL )
return 0 ;
V_2 -> V_5 = V_8 ;
return 1 ;
case V_13 :
if ( V_8 == 0 || V_9 == NULL )
return 1 ;
if ( V_8 < 0 || V_8 > ( int ) ( V_14 - V_2 -> V_7 ) )
return 0 ;
memcpy ( V_2 -> V_6 + V_2 -> V_7 , V_9 , V_8 ) ;
V_2 -> V_7 += V_8 ;
return 1 ;
default:
return - 2 ;
}
}
static int F_9 ( T_1 * V_1 ,
const char * type , const char * V_15 )
{
if ( V_15 == NULL ) {
F_10 ( V_16 , V_17 ) ;
return 0 ;
}
if ( strcmp ( type , L_1 ) == 0 ) {
T_2 * V_2 = V_1 -> V_3 ;
const T_3 * V_11 = F_11 ( V_15 ) ;
if ( V_11 == NULL ) {
F_10 ( V_16 , V_18 ) ;
return 0 ;
}
V_2 -> V_11 = V_11 ;
return 1 ;
}
if ( strcmp ( type , L_2 ) == 0 )
return F_12 ( V_1 , V_12 , V_15 ) ;
if ( strcmp ( type , L_3 ) == 0 )
return F_13 ( V_1 , V_12 , V_15 ) ;
if ( strcmp ( type , L_4 ) == 0 )
return F_12 ( V_1 , V_13 , V_15 ) ;
if ( strcmp ( type , L_5 ) == 0 )
return F_13 ( V_1 , V_13 , V_15 ) ;
return - 2 ;
}
static int F_14 ( T_1 * V_1 , unsigned char * V_19 ,
T_4 * V_20 )
{
T_2 * V_2 = V_1 -> V_3 ;
if ( V_2 -> V_11 == NULL || V_2 -> V_4 == NULL || V_2 -> V_7 == 0 ) {
F_10 ( V_21 , V_22 ) ;
return 0 ;
}
return F_15 ( V_2 -> V_11 , V_2 -> V_4 , V_2 -> V_5 ,
V_2 -> V_6 , V_2 -> V_7 ,
V_19 , * V_20 ) ;
}
static int F_16 ( const T_3 * V_11 ,
const unsigned char * V_4 , T_4 V_23 ,
const unsigned char * V_6 , T_4 V_24 ,
unsigned char * V_25 , T_4 V_26 )
{
int V_27 ;
T_5 * V_1 = NULL , * V_28 = NULL , * V_29 = NULL ;
T_6 * V_30 = NULL ;
unsigned char V_31 [ V_32 ] ;
T_4 V_33 ;
int V_34 = 0 ;
V_27 = F_17 ( V_11 ) ;
F_18 ( V_27 >= 0 ) ;
V_1 = F_19 () ;
V_28 = F_19 () ;
V_29 = F_19 () ;
if ( V_1 == NULL || V_28 == NULL || V_29 == NULL )
goto V_35;
F_20 ( V_29 , V_36 ) ;
V_30 = F_21 ( V_37 , NULL , V_4 , V_23 ) ;
if ( V_30 == NULL )
goto V_35;
if ( ! F_22 ( V_29 , NULL , V_11 , NULL , V_30 ) )
goto V_35;
if ( ! F_23 ( V_1 , V_29 ) )
goto V_35;
if ( V_6 != NULL && ! F_24 ( V_1 , V_6 , V_24 ) )
goto V_35;
if ( ! F_25 ( V_1 , V_31 , & V_33 ) )
goto V_35;
for (; ; ) {
if ( ! F_23 ( V_1 , V_29 ) )
goto V_35;
if ( ! F_24 ( V_1 , V_31 , V_33 ) )
goto V_35;
if ( V_26 > ( T_4 ) V_27 && ! F_23 ( V_28 , V_1 ) )
goto V_35;
if ( V_6 && ! F_24 ( V_1 , V_6 , V_24 ) )
goto V_35;
if ( V_26 > ( T_4 ) V_27 ) {
T_4 V_38 ;
if ( ! F_25 ( V_1 , V_25 , & V_38 ) )
goto V_35;
V_25 += V_38 ;
V_26 -= V_38 ;
if ( ! F_25 ( V_28 , V_31 , & V_33 ) )
goto V_35;
} else {
if ( ! F_25 ( V_1 , V_31 , & V_33 ) )
goto V_35;
memcpy ( V_25 , V_31 , V_26 ) ;
break;
}
}
V_34 = 1 ;
V_35:
F_26 ( V_30 ) ;
F_27 ( V_1 ) ;
F_27 ( V_28 ) ;
F_27 ( V_29 ) ;
F_5 ( V_31 , sizeof( V_31 ) ) ;
return V_34 ;
}
static int F_15 ( const T_3 * V_11 ,
const unsigned char * V_4 , T_4 V_39 ,
const unsigned char * V_6 , T_4 V_24 ,
unsigned char * V_25 , T_4 V_26 )
{
if ( F_28 ( V_11 ) == V_40 ) {
T_4 V_41 ;
unsigned char * V_42 ;
if ( ! F_16 ( F_29 () , V_4 , V_39 / 2 + ( V_39 & 1 ) ,
V_6 , V_24 , V_25 , V_26 ) )
return 0 ;
V_42 = F_30 ( V_26 ) ;
if ( V_42 == NULL )
return 0 ;
if ( ! F_16 ( F_31 () , V_4 + V_39 / 2 , V_39 / 2 + ( V_39 & 1 ) ,
V_6 , V_24 , V_42 , V_26 ) ) {
F_4 ( V_42 , V_26 ) ;
return 0 ;
}
for ( V_41 = 0 ; V_41 < V_26 ; V_41 ++ )
V_25 [ V_41 ] ^= V_42 [ V_41 ] ;
F_4 ( V_42 , V_26 ) ;
return 1 ;
}
if ( ! F_16 ( V_11 , V_4 , V_39 , V_6 , V_24 , V_25 , V_26 ) )
return 0 ;
return 1 ;
}
