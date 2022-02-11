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
case V_17 : V_5 += 2 ; F_3 ( V_1 , V_5 , V_3 , V_4 ) ; break;
case V_18 : break;
case V_19 : break;
default : break;
}
}
static void
F_4 ( T_4 * V_20 , T_5 * V_21 , T_6 * V_22 )
{
T_7 * V_23 ;
T_6 * V_24 ;
int V_2 ;
int V_6 ;
int V_25 ;
int V_26 ;
int V_27 ;
int V_28 ;
int V_29 ;
int V_30 ;
int V_31 ;
const char * V_32 ;
char * V_33 ;
T_4 * V_34 = NULL ;
V_33 = ( char * ) F_5 ( F_6 () , STRLEN ) ;
V_33 [ 0 ] = '\0' ;
F_7 ( V_21 -> V_35 , V_36 , L_1 ) ;
F_8 ( V_21 -> V_35 , V_37 ) ;
V_2 = 0 ;
V_6 = F_9 ( V_20 , V_2 ) & 0xff ;
V_25 = V_6 & V_9 ;
V_26 = ( V_6 & V_38 ) >> 4 ;
V_2 += V_7 ;
V_27 = 0 ;
V_28 = 0 ;
switch ( V_25 )
{
case V_11 : V_28 = 1 ; V_27 = F_9 ( V_20 , V_2 ) & 0xff ; break;
case V_12 : V_28 = 1 ; V_27 = F_9 ( V_20 , V_2 ) & 0xff ; break;
case V_13 : V_28 = 1 ; V_27 = F_9 ( V_20 , V_2 ) & 0xff ; break;
case V_14 : V_28 = 1 ; V_27 = F_9 ( V_20 , V_2 ) & 0xff ; break;
case V_15 : V_28 = 1 ; V_27 = F_9 ( V_20 , V_2 ) & 0xff ; break;
case V_16 :
V_28 = F_10 ( V_20 , V_2 ) ;
if ( V_28 < 0 )
V_28 = 0 ;
if ( ( V_28 > 0 ) && V_39 )
V_28 -- ;
break;
case V_17 : V_28 = 2 ; V_27 = F_9 ( V_20 , V_2 ) & 0xff ; break;
default : break;
}
V_32 = F_11 ( V_25 , V_40 , L_2 ) ;
F_12 ( V_33 , STRLEN , L_3 , V_32 , V_26 ) ;
if ( V_28 > 0 )
F_12 ( V_33 , STRLEN , L_4 , V_32 , V_27 , V_26 ) ;
V_2 += V_28 ;
F_13 ( V_21 -> V_35 , V_37 , V_33 ) ;
if ( V_22 )
{
V_2 = 0 ;
V_23 = F_14 ( V_22 , V_41 , V_20 , V_2 ,
F_10 ( V_20 , V_2 ) ,
L_5 ,
V_33
) ;
V_24 = F_15 ( V_23 , V_42 ) ;
F_16 ( V_24 , V_43 , V_20 , V_2 , V_7 ,
V_6 ) ;
F_16 ( V_24 , V_44 , V_20 , V_2 , V_7 ,
V_26 ) ;
V_2 += V_7 ;
switch ( V_25 )
{
case V_10 : break;
case V_11 :
F_16 ( V_24 , V_45 ,
V_20 , V_2 , V_28 , V_27 ) ;
V_2 += V_28 ;
break;
case V_12 :
F_16 ( V_24 , V_46 ,
V_20 , V_2 , V_28 , V_27 ) ;
V_2 += V_28 ;
break;
case V_13 :
F_16 ( V_24 , V_47 ,
V_20 , V_2 , V_28 , V_27 ) ;
V_2 += V_28 ;
break;
case V_14 :
F_16 ( V_24 , V_48 ,
V_20 , V_2 , V_28 , V_27 ) ;
V_2 += V_28 ;
break;
case V_15 :
F_16 ( V_24 , V_49 ,
V_20 , V_2 , V_28 , V_27 ) ;
V_2 += V_28 ;
break;
case V_16 :
F_17 ( V_24 , V_50 ,
V_20 , V_2 , V_28 , V_51 ) ;
V_2 += V_28 ;
break;
case V_17 :
F_16 ( V_24 , V_52 ,
V_20 , V_2 , V_28 , V_27 ) ;
V_2 += V_28 ;
break;
case V_18 : break;
case V_19 : break;
default : break;
}
if ( V_39 )
{
V_29 = 0 ;
V_31 = F_10 ( V_20 , 0 ) - 1 ;
if ( V_31 > 0 )
{
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
V_29 ^= ( F_9 ( V_20 , V_30 ) & 0xff ) ;
F_16 ( V_24 , V_53 ,
V_20 , V_30 , 1 , V_29 ) ;
}
}
}
if ( ( V_25 == V_10 ) || ( V_25 == V_17 ) )
{
V_34 = F_18 ( V_20 , V_2 ) ;
F_19 ( V_54 , V_34 , V_21 , V_22 ) ;
}
}
void
F_20 ( void )
{
T_8 * V_55 ;
static T_9 V_56 [] = {
{ & V_43 ,
{ L_6 , L_7 ,
V_57 , V_58 , F_21 ( V_40 ) , V_9 ,
NULL , V_59 }
} ,
{ & V_44 ,
{ L_8 , L_9 ,
V_57 , V_58 , NULL , V_38 ,
NULL , V_59 }
} ,
{ & V_45 ,
{ L_10 , L_11 ,
V_57 , V_58 , NULL , 0x0 ,
NULL , V_59 }
} ,
{ & V_46 ,
{ L_12 , L_13 ,
V_57 , V_58 , NULL , 0x0 ,
NULL , V_59 }
} ,
{ & V_47 ,
{ L_14 , L_15 ,
V_57 , V_58 , NULL , 0x0 ,
NULL , V_59 }
} ,
{ & V_48 ,
{ L_16 , L_17 ,
V_57 , V_58 , NULL , 0x0 ,
NULL , V_59 }
} ,
{ & V_49 ,
{ L_18 , L_19 ,
V_57 , V_58 , NULL , 0x0 ,
NULL , V_59 }
} ,
{ & V_50 ,
{ L_20 , L_21 ,
V_60 , V_61 , NULL , 0x0 ,
NULL , V_59 }
} ,
{ & V_52 ,
{ L_22 , L_23 ,
V_62 , V_58 , NULL , 0x0 ,
NULL , V_59 }
} ,
{ & V_53 ,
{ L_24 , L_25 ,
V_62 , V_63 , NULL , 0x0 ,
NULL , V_59 }
} ,
} ;
static T_10 * V_64 [] = {
& V_42 ,
} ;
V_41 = F_22 ( L_1 , L_1 , L_26 ) ;
V_65 = F_23 ( L_26 , F_4 , V_41 ) ;
F_24 ( V_41 , V_56 , F_25 ( V_56 ) ) ;
F_26 ( V_64 , F_25 ( V_64 ) ) ;
V_55 = F_27 ( V_41 , NULL ) ;
F_28 ( V_55 , L_27 ,
L_28 ,
L_29 ,
& V_39 ) ;
}
void
F_29 ( void )
{
F_30 ( L_30 , V_66 , V_65 ) ;
V_54 = F_31 ( L_31 ) ;
}
