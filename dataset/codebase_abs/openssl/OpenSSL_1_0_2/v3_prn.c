int F_1 ( T_1 * V_1 , T_2 * V_2 , unsigned long V_3 ,
int V_4 )
{
void * V_5 = NULL ;
char * V_6 = NULL ;
const unsigned char * V_7 ;
const T_3 * V_8 ;
F_2 ( V_9 ) * V_10 = NULL ;
int V_11 = 1 ;
if ( ! ( V_8 = F_3 ( V_2 ) ) )
return F_4 ( V_1 , V_2 , V_3 , V_4 , 0 ) ;
V_7 = V_2 -> V_6 -> V_12 ;
if ( V_8 -> V_13 )
V_5 =
F_5 ( NULL , & V_7 , V_2 -> V_6 -> V_14 ,
F_6 ( V_8 -> V_13 ) ) ;
else
V_5 = V_8 -> V_15 ( NULL , & V_7 , V_2 -> V_6 -> V_14 ) ;
if ( ! V_5 )
return F_4 ( V_1 , V_2 , V_3 , V_4 , 1 ) ;
if ( V_8 -> V_16 ) {
if ( ! ( V_6 = V_8 -> V_16 ( V_8 , V_5 ) ) ) {
V_11 = 0 ;
goto V_17;
}
#ifndef F_7
F_8 ( V_1 , L_1 , V_4 , L_2 , V_6 ) ;
#else
{
int V_18 ;
char * V_19 ;
V_18 = strlen ( V_6 ) + 1 ;
V_19 = F_9 ( V_18 ) ;
if ( V_19 ) {
F_10 ( V_19 , V_6 , V_18 ) ;
F_8 ( V_1 , L_1 , V_4 , L_2 , V_19 ) ;
F_11 ( V_19 ) ;
}
}
#endif
} else if ( V_8 -> V_20 ) {
if ( ! ( V_10 = V_8 -> V_20 ( V_8 , V_5 , NULL ) ) ) {
V_11 = 0 ;
goto V_17;
}
F_12 ( V_1 , V_10 , V_4 ,
V_8 -> V_21 & V_22 ) ;
} else if ( V_8 -> V_23 ) {
if ( ! V_8 -> V_23 ( V_8 , V_5 , V_1 , V_4 ) )
V_11 = 0 ;
} else
V_11 = 0 ;
V_17:
F_13 ( V_10 , V_24 ) ;
if ( V_6 )
F_11 ( V_6 ) ;
if ( V_8 -> V_13 )
F_14 ( V_5 , F_6 ( V_8 -> V_13 ) ) ;
else
V_8 -> V_25 ( V_5 ) ;
return V_11 ;
}
static int F_4 ( T_1 * V_1 , T_2 * V_2 ,
unsigned long V_3 , int V_4 , int V_26 )
{
switch ( V_3 & V_27 ) {
case V_28 :
return 0 ;
case V_29 :
if ( V_26 )
F_8 ( V_1 , L_3 , V_4 , L_2 ) ;
else
F_8 ( V_1 , L_4 , V_4 , L_2 ) ;
return 1 ;
case V_30 :
return F_15 ( V_1 ,
V_2 -> V_6 -> V_12 , V_2 -> V_6 -> V_14 , V_4 ,
- 1 ) ;
case V_31 :
return F_16 ( V_1 , ( char * ) V_2 -> V_6 -> V_12 ,
V_2 -> V_6 -> V_14 , V_4 ) ;
default:
return 1 ;
}
}
int F_17 ( T_4 * V_32 , T_2 * V_2 , int V_3 , int V_4 )
{
T_1 * V_33 ;
int V_34 ;
if ( ! ( V_33 = F_18 ( V_32 , V_35 ) ) )
return 0 ;
V_34 = F_1 ( V_33 , V_2 , V_3 , V_4 ) ;
F_19 ( V_33 ) ;
return V_34 ;
}
