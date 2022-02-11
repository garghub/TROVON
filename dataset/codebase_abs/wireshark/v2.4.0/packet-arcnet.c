static int F_1 ( const T_1 * T_2 V_1 )
{
return 5 ;
}
static int F_2 ( const T_1 * T_2 , T_3 * V_2 , int T_4 V_1 )
{
* V_2 ++ = '0' ;
* V_2 ++ = 'x' ;
V_2 = F_3 ( V_2 , ( const V_3 * ) T_2 -> V_4 , 1 ) ;
* V_2 = '\0' ;
return F_1 ( T_2 ) ;
}
static const char * F_4 ( const T_1 * T_2 V_1 , T_5 V_5 )
{
if ( V_5 )
return L_1 ;
return L_2 ;
}
static int F_5 ( void )
{
return 1 ;
}
static T_5
F_6 ( const T_6 * V_6 , int V_7 , int V_8 , T_7 * V_9 , const union V_10 * V_11 , T_5 V_12 )
{
if ( ! F_7 ( V_7 , V_8 , 1 ) ) {
return FALSE ;
}
switch ( V_6 [ V_7 ] ) {
case V_13 :
return F_8 ( V_14 , V_6 , V_7 + 1 , V_8 , V_9 , V_11 ) ;
case V_15 :
V_7 ++ ;
if ( ! F_7 ( V_7 , V_8 , 1 ) ) {
return FALSE ;
}
if ( V_12 && V_6 [ V_7 ] == 0xff ) {
V_7 += 4 ;
}
return F_8 ( V_14 , V_6 , V_7 + 3 , V_8 , V_9 , V_11 ) ;
case V_16 :
case V_17 :
return F_8 ( V_18 , V_6 , V_7 + 1 , V_8 , V_9 , V_11 ) ;
case V_19 :
F_9 ( V_9 , V_20 ) ;
break;
default:
return FALSE ;
}
return TRUE ;
}
static T_5
F_10 ( const T_6 * V_6 , int V_7 V_1 , int V_8 , T_7 * V_9 , const union V_10 * V_11 )
{
return F_6 ( V_6 , 4 , V_8 , V_9 , V_11 , FALSE ) ;
}
static T_5
F_11 ( const T_6 * V_6 , int V_7 V_1 , int V_8 , T_7 * V_9 , const union V_10 * V_11 )
{
return F_6 ( V_6 , 2 , V_8 , V_9 , V_11 , TRUE ) ;
}
static void
F_12 ( T_8 * V_21 , T_9 * V_22 , T_10 * V_23 ,
T_5 V_24 , T_5 V_12 )
{
int V_7 = 0 ;
V_3 V_25 , V_26 , V_27 , V_28 ;
T_8 * V_29 ;
T_11 * V_30 ;
T_10 * V_31 ;
F_13 ( V_22 -> V_32 , V_33 , L_3 ) ;
F_13 ( V_22 -> V_32 , V_34 , L_3 ) ;
V_26 = F_14 ( V_21 , 0 ) ;
V_25 = F_14 ( V_21 , 1 ) ;
F_15 ( & V_22 -> V_35 , V_36 , 1 , V_21 , 0 ) ;
F_16 ( & V_22 -> V_26 , & V_22 -> V_35 ) ;
F_15 ( & V_22 -> V_37 , V_36 , 1 , V_21 , 1 ) ;
F_16 ( & V_22 -> V_25 , & V_22 -> V_37 ) ;
V_30 = F_17 ( V_23 , V_38 , V_21 , 0 , - 1 , V_39 ) ;
V_31 = F_18 ( V_30 , V_40 ) ;
F_19 ( V_31 , V_41 , V_21 , V_7 , 1 , V_26 ) ;
V_7 ++ ;
F_19 ( V_31 , V_42 , V_21 , V_7 , 1 , V_25 ) ;
V_7 ++ ;
if ( V_24 ) {
F_17 ( V_31 , V_43 , V_21 , V_7 , 2 , V_39 ) ;
V_7 += 2 ;
}
V_27 = F_14 ( V_21 , V_7 ) ;
F_19 ( V_31 , V_44 , V_21 , V_7 , 1 , V_27 ) ;
V_7 ++ ;
switch ( V_27 ) {
case V_13 :
case V_16 :
case V_45 :
case V_46 :
break;
default:
V_28 = F_14 ( V_21 , V_7 ) ;
if ( V_12 && V_28 == 0xff ) {
F_19 ( V_31 , V_47 , V_21 , V_7 , 1 ,
V_28 ) ;
V_7 ++ ;
F_17 ( V_31 , V_48 , V_21 , V_7 , 2 , V_49 ) ;
V_7 += 2 ;
F_17 ( V_31 , V_44 , V_21 , V_7 , 1 , V_49 ) ;
V_7 ++ ;
V_28 = F_14 ( V_21 , V_7 ) ;
}
F_19 ( V_31 , V_50 , V_21 , V_7 , 1 ,
V_28 ) ;
V_7 ++ ;
F_17 ( V_31 , V_51 , V_21 , V_7 , 2 , V_49 ) ;
V_7 += 2 ;
break;
}
F_20 ( V_30 , V_7 ) ;
V_29 = F_21 ( V_21 , V_7 ) ;
if ( ! F_22 ( V_52 , V_27 ,
V_29 , V_22 , V_23 ) )
{
F_23 ( V_22 -> V_32 , V_33 , L_4 , V_27 ) ;
F_24 ( V_29 , V_22 , V_23 ) ;
}
}
static int
F_25 ( T_8 * V_21 , T_9 * V_22 , T_10 * V_23 , void * V_4 V_1 )
{
F_12 ( V_21 , V_22 , V_23 , FALSE , TRUE ) ;
return F_26 ( V_21 ) ;
}
static int
F_27 ( T_8 * V_21 , T_9 * V_22 , T_10 * V_23 , void * V_4 V_1 )
{
F_12 ( V_21 , V_22 , V_23 , TRUE , FALSE ) ;
return F_26 ( V_21 ) ;
}
void
F_28 ( void )
{
static T_12 V_53 [] = {
{ & V_41 ,
{ L_5 , L_1 ,
V_54 , V_55 , NULL , 0 ,
L_6 , V_56 }
} ,
{ & V_42 ,
{ L_7 , L_2 ,
V_54 , V_55 , NULL , 0 ,
L_8 , V_56 }
} ,
{ & V_43 ,
{ L_9 , L_10 ,
V_57 , V_58 , NULL , 0 ,
NULL , V_56 }
} ,
{ & V_44 ,
{ L_11 , L_12 ,
V_54 , V_55 , F_29 ( V_59 ) , 0 ,
L_13 , V_56 }
} ,
{ & V_50 ,
{ L_14 , L_15 ,
V_54 , V_60 , NULL , 0 ,
NULL , V_56 }
} ,
{ & V_47 ,
{ L_16 , L_17 ,
V_54 , V_55 , NULL , 0 ,
NULL , V_56 }
} ,
{ & V_51 ,
{ L_18 , L_19 ,
V_61 , V_60 , NULL , 0 ,
L_20 , V_56 }
} ,
{ & V_48 ,
{ L_21 , L_22 ,
V_61 , V_55 , NULL , 0 ,
NULL , V_56 }
} ,
} ;
static T_13 * V_62 [] = {
& V_40 ,
} ;
V_38 = F_30 ( L_3 , L_3 , L_23 ) ;
F_31 ( V_38 , V_53 , F_32 ( V_53 ) ) ;
F_33 ( V_62 , F_32 ( V_62 ) ) ;
V_52 = F_34 ( L_24 , L_25 ,
V_38 , V_54 , V_55 ) ;
V_36 = F_35 ( L_26 , L_27 , F_2 , F_1 , NULL , F_4 , F_5 , NULL , NULL ) ;
}
void
F_36 ( void )
{
T_14 V_63 , V_64 ;
T_15 V_65 ;
V_63 = F_37 ( F_25 , V_38 ) ;
F_38 ( L_28 , V_66 , V_63 ) ;
V_64 = F_37 ( F_27 , V_38 ) ;
F_38 ( L_28 , V_67 , V_64 ) ;
V_20 = F_39 ( L_29 ) ;
V_65 = F_40 ( F_10 , V_38 ) ;
F_41 ( L_28 , V_67 , V_65 ) ;
V_65 = F_40 ( F_11 , V_38 ) ;
F_41 ( L_28 , V_66 , V_65 ) ;
V_14 = F_42 ( L_30 ) ;
V_18 = F_42 ( L_31 ) ;
}
