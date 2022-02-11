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
return F_8 ( V_6 , V_7 + 1 , V_8 , V_9 , V_11 ) ;
case V_14 :
V_7 ++ ;
if ( ! F_7 ( V_7 , V_8 , 1 ) ) {
return FALSE ;
}
if ( V_12 && V_6 [ V_7 ] == 0xff ) {
V_7 += 4 ;
}
return F_8 ( V_6 , V_7 + 3 , V_8 , V_9 , V_11 ) ;
case V_15 :
case V_16 :
return F_9 ( V_6 , V_7 + 1 , V_8 , V_9 , V_11 ) ;
case V_17 :
F_10 ( V_9 , V_18 ) ;
break;
default:
return FALSE ;
}
return TRUE ;
}
static T_5
F_11 ( const T_6 * V_6 , int V_7 V_1 , int V_8 , T_7 * V_9 , const union V_10 * V_11 )
{
return F_6 ( V_6 , 4 , V_8 , V_9 , V_11 , FALSE ) ;
}
static T_5
F_12 ( const T_6 * V_6 , int V_7 V_1 , int V_8 , T_7 * V_9 , const union V_10 * V_11 )
{
return F_6 ( V_6 , 2 , V_8 , V_9 , V_11 , TRUE ) ;
}
static void
F_13 ( T_8 * V_19 , T_9 * V_20 , T_10 * V_21 ,
T_5 V_22 , T_5 V_12 )
{
int V_7 = 0 ;
V_3 V_23 , V_24 , V_25 , V_26 ;
T_8 * V_27 ;
T_11 * V_28 ;
T_10 * V_29 ;
F_14 ( V_20 -> V_30 , V_31 , L_3 ) ;
F_14 ( V_20 -> V_30 , V_32 , L_3 ) ;
V_24 = F_15 ( V_19 , 0 ) ;
V_23 = F_15 ( V_19 , 1 ) ;
F_16 ( & V_20 -> V_33 , V_34 , 1 , V_19 , 0 ) ;
F_17 ( & V_20 -> V_24 , & V_20 -> V_33 ) ;
F_16 ( & V_20 -> V_35 , V_34 , 1 , V_19 , 1 ) ;
F_17 ( & V_20 -> V_23 , & V_20 -> V_35 ) ;
V_28 = F_18 ( V_21 , V_36 , V_19 , 0 , - 1 , V_37 ) ;
V_29 = F_19 ( V_28 , V_38 ) ;
F_20 ( V_29 , V_39 , V_19 , V_7 , 1 , V_24 ) ;
V_7 ++ ;
F_20 ( V_29 , V_40 , V_19 , V_7 , 1 , V_23 ) ;
V_7 ++ ;
if ( V_22 ) {
F_18 ( V_29 , V_41 , V_19 , V_7 , 2 , V_37 ) ;
V_7 += 2 ;
}
V_25 = F_15 ( V_19 , V_7 ) ;
F_20 ( V_29 , V_42 , V_19 , V_7 , 1 , V_25 ) ;
V_7 ++ ;
switch ( V_25 ) {
case V_13 :
case V_15 :
case V_43 :
case V_44 :
break;
default:
V_26 = F_15 ( V_19 , V_7 ) ;
if ( V_12 && V_26 == 0xff ) {
F_20 ( V_29 , V_45 , V_19 , V_7 , 1 ,
V_26 ) ;
V_7 ++ ;
F_18 ( V_29 , V_46 , V_19 , V_7 , 2 , V_47 ) ;
V_7 += 2 ;
F_18 ( V_29 , V_42 , V_19 , V_7 , 1 , V_47 ) ;
V_7 ++ ;
V_26 = F_15 ( V_19 , V_7 ) ;
}
F_20 ( V_29 , V_48 , V_19 , V_7 , 1 ,
V_26 ) ;
V_7 ++ ;
F_18 ( V_29 , V_49 , V_19 , V_7 , 2 , V_47 ) ;
V_7 += 2 ;
break;
}
F_21 ( V_28 , V_7 ) ;
V_27 = F_22 ( V_19 , V_7 ) ;
if ( ! F_23 ( V_50 , V_25 ,
V_27 , V_20 , V_21 ) )
{
F_24 ( V_20 -> V_30 , V_31 , L_4 , V_25 ) ;
F_25 ( V_27 , V_20 , V_21 ) ;
}
}
static int
F_26 ( T_8 * V_19 , T_9 * V_20 , T_10 * V_21 , void * V_4 V_1 )
{
F_13 ( V_19 , V_20 , V_21 , FALSE , TRUE ) ;
return F_27 ( V_19 ) ;
}
static int
F_28 ( T_8 * V_19 , T_9 * V_20 , T_10 * V_21 , void * V_4 V_1 )
{
F_13 ( V_19 , V_20 , V_21 , TRUE , FALSE ) ;
return F_27 ( V_19 ) ;
}
void
F_29 ( void )
{
static T_12 V_51 [] = {
{ & V_39 ,
{ L_5 , L_1 ,
V_52 , V_53 , NULL , 0 ,
L_6 , V_54 }
} ,
{ & V_40 ,
{ L_7 , L_2 ,
V_52 , V_53 , NULL , 0 ,
L_8 , V_54 }
} ,
{ & V_41 ,
{ L_9 , L_10 ,
V_55 , V_56 , NULL , 0 ,
NULL , V_54 }
} ,
{ & V_42 ,
{ L_11 , L_12 ,
V_52 , V_53 , F_30 ( V_57 ) , 0 ,
L_13 , V_54 }
} ,
{ & V_48 ,
{ L_14 , L_15 ,
V_52 , V_58 , NULL , 0 ,
NULL , V_54 }
} ,
{ & V_45 ,
{ L_16 , L_17 ,
V_52 , V_53 , NULL , 0 ,
NULL , V_54 }
} ,
{ & V_49 ,
{ L_18 , L_19 ,
V_59 , V_58 , NULL , 0 ,
L_20 , V_54 }
} ,
{ & V_46 ,
{ L_21 , L_22 ,
V_59 , V_53 , NULL , 0 ,
NULL , V_54 }
} ,
} ;
static T_13 * V_60 [] = {
& V_38 ,
} ;
V_36 = F_31 ( L_3 , L_3 , L_23 ) ;
F_32 ( V_36 , V_51 , F_33 ( V_51 ) ) ;
F_34 ( V_60 , F_33 ( V_60 ) ) ;
V_50 = F_35 ( L_24 , L_25 ,
V_36 , V_52 , V_53 , V_61 ) ;
V_34 = F_36 ( L_26 , L_27 , F_2 , F_1 , F_4 , F_5 , NULL , NULL ) ;
}
void
F_37 ( void )
{
T_14 V_62 , V_63 ;
V_62 = F_38 ( F_26 , V_36 ) ;
F_39 ( L_28 , V_64 , V_62 ) ;
V_63 = F_38 ( F_28 , V_36 ) ;
F_39 ( L_28 , V_65 , V_63 ) ;
V_18 = F_40 ( L_29 ) ;
F_41 ( L_28 , V_65 , F_11 , V_36 ) ;
F_41 ( L_28 , V_64 , F_12 , V_36 ) ;
}
