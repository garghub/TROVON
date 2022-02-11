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
case V_22 :
F_14 ( V_7 , V_8 , V_9 , V_10 ) ;
break;
default:
V_10 -> V_23 ++ ;
break;
}
}
static int
F_15 ( T_7 * V_24 , T_1 * V_1 , T_8 * V_25 , void * V_26 )
{
const char * V_27 ;
T_7 * volatile V_28 ;
T_9 V_29 ;
T_10 V_30 , V_31 ;
volatile int V_32 = 0 ;
const char * volatile V_33 ;
T_11 * V_34 ;
if ( V_26 == NULL )
return 0 ;
V_34 = ( T_11 * ) V_26 ;
F_16 ( V_34 -> V_35 , V_34 -> V_36 , V_24 ,
V_34 -> V_37 - 2 , 2 , V_34 -> V_6 ) ;
V_30 = F_17 ( V_24 , V_34 -> V_37 ) ;
V_31 = F_18 ( V_24 ,
V_34 -> V_37 ) ;
V_29 = V_31 ;
if ( V_34 -> V_38 > 0 ) {
if ( V_30 >= 0 && V_31 >= 0 ) {
if ( V_31 >= V_34 -> V_38 )
V_31 -= V_34 -> V_38 ;
if ( V_30 > V_31 )
V_30 = V_31 ;
}
}
V_28 = F_19 ( V_24 , V_34 -> V_37 , V_30 ,
V_31 ) ;
F_20 ( V_1 -> V_4 , V_1 , V_5 , 0 , F_21 ( ( T_9 ) V_34 -> V_6 ) ) ;
V_33 = V_1 -> V_39 ;
F_22 {
V_32 = F_23 ( V_40 ,
V_34 -> V_6 , V_28 , V_1 , V_25 ) ;
}
F_24 {
F_25 ( V_28 , V_1 , V_25 , V_41 , V_42 ) ;
V_32 = 1 ;
V_1 -> V_39 = V_33 ;
}
V_43 ;
if ( ! V_32 ) {
F_26 ( V_44 , V_28 , V_1 , V_25 ) ;
F_27 ( V_1 -> V_45 , V_46 , L_2 , V_34 -> V_6 ) ;
V_27 = F_28 ( V_34 -> V_6 , V_47 ) ;
if ( V_27 ) {
F_29 ( V_1 -> V_45 , V_48 , V_27 ) ;
}
}
F_30 ( V_1 , V_25 , V_34 -> V_35 , V_34 -> V_49 , V_24 , V_28 , V_34 -> V_37 ,
V_29 , V_34 -> V_38 ) ;
return F_31 ( V_24 ) ;
}
static void
F_30 ( T_1 * V_1 , T_8 * V_25 , T_8 * V_35 , int V_49 ,
T_7 * V_24 , T_7 * V_28 , int V_50 ,
T_9 V_29 , T_10 V_38 )
{
T_9 V_51 ;
T_7 * V_52 ;
V_51 = F_32 ( V_28 ) ;
if ( V_51 < V_29 ) {
if ( F_33 ( V_24 , V_50 + V_51 ) ) {
V_52 = F_34 ( V_24 ,
V_50 + V_51 ) ;
} else {
V_52 = NULL ;
}
} else
V_52 = NULL ;
F_35 ( V_1 , V_25 , V_35 , V_49 , V_24 , V_52 , V_38 ) ;
}
void
F_36 ( void )
{
static T_12 V_53 [ 1 ] = { F_5 } ;
static T_13 V_54 = { F_1 , 1 , V_53 } ;
static T_14 V_55 = { L_3 , L_4 , L_3 , 1 , 0 , & V_54 , NULL , NULL ,
V_56 , V_57 , V_58 , NULL } ;
V_5 = F_37 ( L_5 , L_5 , L_3 ) ;
F_38 ( L_3 , F_15 , V_5 ) ;
V_40 = F_39 ( L_3 ,
L_5 , V_59 , V_60 ) ;
F_40 ( & V_55 ) ;
}
void
F_41 ( void )
{
V_44 = F_42 ( L_6 ) ;
}
