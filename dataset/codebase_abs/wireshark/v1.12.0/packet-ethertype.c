static void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
F_2 ( V_2 , V_3 , L_1 ,
F_3 ( F_4 ( V_1 -> V_4 , V_1 , V_5 , 0 ) ) ) ;
}
static T_3 F_5 ( T_1 * V_1 )
{
return F_4 ( V_1 -> V_4 , V_1 , V_5 , 0 ) ;
}
void
F_6 ( T_4 V_6 , const T_5 * V_7 , int V_8 , int V_9 ,
T_6 * V_10 )
{
switch ( V_6 ) {
case V_11 :
V_10 -> V_12 ++ ;
break;
case V_13 :
F_7 ( V_7 , V_8 , V_9 , V_10 ) ;
break;
case V_14 :
F_8 ( V_7 , V_8 , V_9 , V_10 ) ;
break;
case V_15 :
F_9 ( V_10 ) ;
break;
case V_16 :
F_10 ( V_7 , V_8 , V_9 , V_10 ) ;
break;
case V_17 :
case V_18 :
F_11 ( V_7 , V_8 , V_9 , V_10 ) ;
break;
case V_19 :
case V_20 :
F_12 ( V_10 ) ;
break;
case V_21 :
F_13 ( V_7 , V_8 , V_9 , V_10 ) ;
break;
default:
V_10 -> V_22 ++ ;
break;
}
}
static int
F_14 ( T_7 * V_23 , T_1 * V_1 , T_8 * V_24 , void * V_25 )
{
const char * V_26 ;
T_7 * volatile V_27 ;
T_9 V_28 ;
T_10 V_29 , V_30 ;
volatile T_11 V_31 = FALSE ;
const char * volatile V_32 ;
void * V_33 ;
T_12 * V_34 ;
if ( V_25 == NULL )
return 0 ;
V_34 = ( T_12 * ) V_25 ;
F_15 ( V_34 -> V_35 , V_34 -> V_36 , V_23 ,
V_34 -> V_37 - 2 , 2 , V_34 -> V_6 ) ;
V_29 = F_16 ( V_23 , V_34 -> V_37 ) ;
V_30 = F_17 ( V_23 ,
V_34 -> V_37 ) ;
V_28 = V_30 ;
if ( V_34 -> V_38 > 0 ) {
if ( V_29 >= 0 && V_30 >= 0 ) {
if ( V_30 >= V_34 -> V_38 )
V_30 -= V_34 -> V_38 ;
if ( V_29 > V_30 )
V_29 = V_30 ;
}
}
V_27 = F_18 ( V_23 , V_34 -> V_37 , V_29 ,
V_30 ) ;
F_19 ( V_1 -> V_4 , V_1 , V_5 , 0 , F_20 ( ( T_9 ) V_34 -> V_6 ) ) ;
V_32 = V_1 -> V_39 ;
V_33 = V_1 -> V_40 ;
F_21 {
V_31 = F_22 ( V_41 ,
V_34 -> V_6 , V_27 , V_1 , V_24 ) ;
}
F_23 {
F_24 ( V_27 , V_1 , V_24 , V_42 , V_43 ) ;
V_1 -> V_40 = V_33 ;
V_31 = TRUE ;
V_1 -> V_39 = V_32 ;
}
V_44 ;
if ( ! V_31 ) {
F_25 ( V_45 , V_27 , V_1 , V_24 ) ;
F_26 ( V_1 -> V_46 , V_47 , L_2 , V_34 -> V_6 ) ;
V_26 = F_27 ( V_34 -> V_6 , V_48 ) ;
if ( V_26 ) {
F_28 ( V_1 -> V_46 , V_49 , V_26 ) ;
}
}
F_29 ( V_1 , V_24 , V_34 -> V_35 , V_34 -> V_50 , V_23 , V_27 , V_34 -> V_37 ,
V_28 , V_34 -> V_38 ) ;
return F_30 ( V_23 ) ;
}
static void
F_29 ( T_1 * V_1 , T_8 * V_24 , T_8 * V_35 , int V_50 ,
T_7 * V_23 , T_7 * V_27 , int V_51 ,
T_9 V_28 , T_10 V_38 )
{
T_9 V_52 ;
T_7 * V_53 ;
V_52 = F_31 ( V_27 ) ;
if ( V_52 < V_28 ) {
if ( F_32 ( V_23 , V_51 + V_52 ) ) {
V_53 = F_33 ( V_23 ,
V_51 + V_52 ) ;
} else {
V_53 = NULL ;
}
} else
V_53 = NULL ;
F_34 ( V_1 , V_24 , V_35 , V_50 , V_23 , V_53 , V_38 ) ;
}
void
F_35 ( void )
{
static T_13 V_54 [ 1 ] = { F_5 } ;
static T_14 V_55 = { F_1 , 1 , V_54 } ;
static T_15 V_56 = { L_3 , L_4 , L_3 , 1 , 0 , & V_55 , NULL , NULL ,
V_57 , V_58 , V_59 , NULL } ;
V_5 = F_36 ( L_5 , L_5 , L_3 ) ;
F_37 ( L_3 , F_14 , V_5 ) ;
V_41 = F_38 ( L_3 ,
L_5 , V_60 , V_61 ) ;
F_39 ( & V_56 ) ;
}
void
F_40 ( void )
{
V_45 = F_41 ( L_6 ) ;
}
