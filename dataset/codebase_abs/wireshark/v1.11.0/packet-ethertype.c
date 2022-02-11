void
F_1 ( T_1 V_1 , const T_2 * V_2 , int V_3 , int V_4 ,
T_3 * V_5 )
{
switch ( V_1 ) {
case V_6 :
V_5 -> V_7 ++ ;
break;
case V_8 :
F_2 ( V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_9 :
F_3 ( V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_10 :
F_4 ( V_5 ) ;
break;
case V_11 :
F_5 ( V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_12 :
case V_13 :
F_6 ( V_2 , V_3 , V_4 , V_5 ) ;
break;
case V_14 :
case V_15 :
F_7 ( V_5 ) ;
break;
case V_16 :
F_8 ( V_2 , V_3 , V_4 , V_5 ) ;
break;
default:
V_5 -> V_17 ++ ;
break;
}
}
void
F_9 ( T_1 V_1 , T_4 * V_18 , int V_19 ,
T_5 * V_20 , T_6 * V_21 , T_6 * V_22 ,
int V_23 , int V_24 , int V_25 )
{
const char * V_26 ;
T_4 * volatile V_27 ;
T_7 V_28 ;
T_8 V_29 , V_30 ;
volatile T_9 V_31 = FALSE ;
const char * volatile V_32 ;
void * V_33 ;
if ( V_21 ) {
F_10 ( V_22 , V_23 , V_18 ,
V_19 - 2 , 2 , V_1 ) ;
}
V_29 = F_11 ( V_18 , V_19 ) ;
V_30 = F_12 ( V_18 ,
V_19 ) ;
V_28 = V_30 ;
if ( V_25 > 0 ) {
if ( V_29 >= 0 && V_30 >= 0 ) {
if ( V_30 >= V_25 )
V_30 -= V_25 ;
if ( V_29 > V_30 )
V_29 = V_30 ;
}
}
V_27 = F_13 ( V_18 , V_19 , V_29 ,
V_30 ) ;
V_20 -> F_9 = V_1 ;
V_32 = V_20 -> V_34 ;
V_33 = V_20 -> V_35 ;
F_14 {
V_31 = F_15 ( V_36 ,
V_1 , V_27 , V_20 , V_21 ) ;
}
F_16 {
F_17 ( V_27 , V_20 , V_21 , V_37 , V_38 ) ;
V_20 -> V_35 = V_33 ;
V_31 = TRUE ;
V_20 -> V_34 = V_32 ;
}
V_39 ;
if ( ! V_31 ) {
F_18 ( V_40 , V_27 , V_20 , V_21 ) ;
F_19 ( V_20 -> V_41 , V_42 , L_1 , V_1 ) ;
V_26 = F_20 ( V_1 , V_43 ) ;
if ( V_26 ) {
F_21 ( V_20 -> V_41 , V_44 , V_26 ) ;
}
}
F_22 ( V_20 , V_21 , V_22 , V_24 , V_18 , V_27 , V_19 ,
V_28 , V_25 ) ;
}
static void
F_22 ( T_5 * V_20 , T_6 * V_21 , T_6 * V_22 , int V_24 ,
T_4 * V_18 , T_4 * V_27 , int V_19 ,
T_7 V_28 , T_8 V_25 )
{
T_7 V_45 ;
T_4 * V_46 ;
if ( V_22 == NULL )
return;
V_45 = F_23 ( V_27 ) ;
if ( V_45 < V_28 ) {
if ( F_24 ( V_18 , V_19 + V_45 ) ) {
V_46 = F_25 ( V_18 ,
V_19 + V_45 ) ;
} else {
V_46 = NULL ;
}
} else
V_46 = NULL ;
F_26 ( V_20 , V_21 , V_22 , V_24 , V_18 , V_46 , V_25 ) ;
}
void
F_27 ( void )
{
V_36 = F_28 ( L_2 ,
L_3 , V_47 , V_48 ) ;
}
void
F_29 ( void )
{
V_40 = F_30 ( L_4 ) ;
}
