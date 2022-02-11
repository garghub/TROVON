void
F_1 ( void )
{
V_1 = F_2 ( L_1 , L_2 , L_3 ) ;
V_2 = F_2 ( L_4 ,
L_5 , L_6 ) ;
V_3 = F_2 (
L_7 ,
L_8 , L_9 ) ;
F_3 ( V_1 ) ;
F_3 ( V_2 ) ;
F_3 ( V_3 ) ;
}
void
F_4 ( T_1 * V_4 , T_2 * V_5 , T_3 * V_6 ,
unsigned long V_7 , const char * V_8 )
{
static const char V_9 [] =
L_10 ;
T_4 * V_10 ;
if ( V_7 == V_11 && V_5 -> V_12 )
V_7 = V_13 ;
switch ( V_7 ) {
case V_14 :
F_5 ( V_5 -> V_15 , V_16 , L_11 ) ;
F_6 ( V_6 , V_1 , V_4 , 0 , 0 ,
L_12 , V_5 -> V_17 ) ;
break;
case V_18 :
F_5 ( V_5 -> V_15 , V_16 , L_13 ) ;
F_6 ( V_6 , V_1 , V_4 , 0 , 0 ,
L_14 , V_5 -> V_17 ) ;
break;
case V_13 :
F_7 ( V_5 -> V_15 , V_16 , L_15 , V_5 -> V_19 ) ;
F_6 ( V_6 , V_3 ,
V_4 , 0 , 0 , L_16 ,
V_5 -> V_19 , V_5 -> V_17 ) ;
break;
case V_11 :
F_8 ( V_4 , V_5 , V_6 ) ;
break;
case V_20 :
F_7 ( V_5 -> V_15 , V_16 ,
L_17 ,
V_5 -> V_17 ,
V_8 == NULL ?
V_9 : V_8 ) ;
V_10 = F_6 ( V_6 , V_2 , V_4 , 0 , 0 ,
L_17 ,
V_5 -> V_17 ,
V_8 == NULL ?
V_9 : V_8 ) ;
F_9 ( L_18 ,
V_5 -> V_17 , V_5 -> V_21 -> V_22 ,
V_8 == NULL ?
V_9 : V_8 ) ;
F_10 ( V_5 , V_10 , V_23 , V_24 ,
L_19 ,
V_8 == NULL ?
V_9 : V_8 ) ;
break;
case V_25 :
F_7 ( V_5 -> V_15 , V_16 ,
L_20 ,
V_5 -> V_17 ,
V_8 == NULL ?
V_9 : V_8 ) ;
V_10 = F_6 ( V_6 , V_2 , V_4 , 0 , 0 ,
L_20 ,
V_5 -> V_17 ,
V_8 == NULL ?
V_9 : V_8 ) ;
F_10 ( V_5 , V_10 , V_23 , V_24 ,
L_19 ,
V_8 == NULL ?
V_9 : V_8 ) ;
break;
default:
F_11 () ;
}
}
void
F_8 ( T_1 * V_4 , T_2 * V_5 , T_3 * V_6 )
{
T_4 * V_10 ;
F_5 ( V_5 -> V_15 , V_16 ,
L_21 ) ;
V_10 = F_6 ( V_6 , V_2 ,
V_4 , 0 , 0 , L_22 , V_5 -> V_17 ) ;
F_10 ( V_5 , V_10 , V_23 , V_24 , L_23 ) ;
}
