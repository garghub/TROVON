void
F_1 ( const T_1 * V_1 , int V_2 , int V_3 , T_2 * V_4 )
{
int V_5 ;
T_3 V_6 ;
if ( ! F_2 ( V_2 , V_3 , V_7 ) )
{
V_4 -> V_8 ++ ;
return;
}
V_5 = V_2 ;
V_6 = V_1 [ V_5 ] ;
V_5 += V_7 ;
switch ( V_6 & V_9 )
{
case V_10 : F_3 ( V_1 , V_5 , V_3 , V_4 ) ; break;
case V_11 : break;
case V_12 : break;
case V_13 : break;
case V_14 : break;
case V_15 : break;
case V_16 : break;
case V_17 : break;
default : break;
}
}
static void
F_4 ( T_4 * V_18 , T_5 * V_19 , T_6 * V_20 )
{
T_7 * V_21 ;
T_6 * V_22 ;
int V_2 ;
int V_6 ;
int V_23 ;
int V_24 ;
int V_25 ;
int V_26 ;
const char * V_27 ;
char * V_28 ;
T_4 * V_29 = NULL ;
V_28 = ( char * ) F_5 ( F_6 () , STRLEN ) ;
V_28 [ 0 ] = '\0' ;
F_7 ( V_19 -> V_30 , V_31 , L_1 ) ;
F_8 ( V_19 -> V_30 , V_32 ) ;
V_2 = 0 ;
V_6 = F_9 ( V_18 , V_2 ) & 0xff ;
V_23 = V_6 & V_9 ;
V_24 = ( V_6 & V_33 ) >> 4 ;
V_2 += V_7 ;
V_25 = 0 ;
V_26 = 0 ;
switch ( V_23 )
{
case V_11 : V_26 = 1 ; V_25 = F_9 ( V_18 , V_2 ) & 0xff ; break;
case V_12 : V_26 = 1 ; V_25 = F_9 ( V_18 , V_2 ) & 0xff ; break;
case V_13 : V_26 = 1 ; V_25 = F_9 ( V_18 , V_2 ) & 0xff ; break;
case V_14 : V_26 = 1 ; V_25 = F_9 ( V_18 , V_2 ) & 0xff ; break;
case V_15 : V_26 = 1 ; V_25 = F_9 ( V_18 , V_2 ) & 0xff ; break;
case V_16 : V_26 = 1 ; V_25 = F_9 ( V_18 , V_2 ) & 0xff ; break;
default : break;
}
V_27 = F_10 ( V_23 , V_34 , L_2 ) ;
F_11 ( V_28 , STRLEN , L_3 , V_27 , V_24 ) ;
if ( V_26 > 0 )
F_11 ( V_28 , STRLEN , L_4 , V_27 , V_25 , V_24 ) ;
V_2 += V_26 ;
F_12 ( V_19 -> V_30 , V_32 , V_28 ) ;
if ( V_20 )
{
V_2 = 0 ;
V_21 = F_13 ( V_20 , V_35 , V_18 , V_2 ,
V_7 + V_26 ,
L_5 ,
V_28
) ;
V_22 = F_14 ( V_21 , V_36 ) ;
F_15 ( V_22 , V_37 , V_18 , V_2 , V_7 ,
V_6 ) ;
F_15 ( V_22 , V_38 , V_18 , V_2 , V_7 ,
V_24 ) ;
V_2 += V_7 ;
switch ( V_23 )
{
case V_10 : break;
case V_11 :
F_15 ( V_22 , V_39 ,
V_18 , V_2 , V_26 , V_25 ) ;
V_2 += V_26 ;
break;
case V_12 :
F_15 ( V_22 , V_40 ,
V_18 , V_2 , V_26 , V_25 ) ;
V_2 += V_26 ;
break;
case V_13 :
F_15 ( V_22 , V_41 ,
V_18 , V_2 , V_26 , V_25 ) ;
V_2 += V_26 ;
break;
case V_14 :
F_15 ( V_22 , V_42 ,
V_18 , V_2 , V_26 , V_25 ) ;
V_2 += V_26 ;
break;
case V_15 :
F_15 ( V_22 , V_43 ,
V_18 , V_2 , V_26 , V_25 ) ;
V_2 += V_26 ;
break;
case V_16 :
F_15 ( V_22 , V_44 ,
V_18 , V_2 , V_26 , V_25 ) ;
V_2 += V_26 ;
break;
case V_17 : break;
default : break;
}
}
if ( V_23 == V_10 )
{
V_29 = F_16 ( V_18 , V_2 ) ;
F_17 ( V_45 , V_29 , V_19 , V_20 ) ;
}
}
void
F_18 ( void )
{
static T_8 V_46 [] = {
{ & V_37 ,
{ L_6 , L_7 ,
V_47 , V_48 , F_19 ( V_34 ) , V_9 ,
NULL , V_49 }
} ,
{ & V_38 ,
{ L_8 , L_9 ,
V_47 , V_48 , NULL , V_33 ,
NULL , V_49 }
} ,
{ & V_39 ,
{ L_10 , L_11 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_49 }
} ,
{ & V_40 ,
{ L_12 , L_13 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_49 }
} ,
{ & V_41 ,
{ L_14 , L_15 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_49 }
} ,
{ & V_42 ,
{ L_16 , L_17 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_49 }
} ,
{ & V_43 ,
{ L_18 , L_19 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_49 }
} ,
{ & V_44 ,
{ L_20 , L_21 ,
V_47 , V_48 , NULL , 0x0 ,
NULL , V_49 }
} ,
} ;
static T_9 * V_50 [] = {
& V_36 ,
} ;
V_35 = F_20 ( L_1 , L_1 , L_22 ) ;
V_51 = F_21 ( L_22 , F_4 , V_35 ) ;
F_22 ( V_35 , V_46 , F_23 ( V_46 ) ) ;
F_24 ( V_50 , F_23 ( V_50 ) ) ;
}
void
F_25 ( void )
{
F_26 ( L_23 , V_52 , V_51 ) ;
V_45 = F_27 ( L_24 ) ;
}
