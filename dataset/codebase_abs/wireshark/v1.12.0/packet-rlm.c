static T_1
F_1 ( T_2 * V_1 , T_3 * T_4 V_2 , T_5 * V_3 , void * T_6 V_2 )
{
if ( T_4 -> V_4 < 3001 || T_4 -> V_4 > 3015
|| T_4 -> V_5 < 3001 || T_4 -> V_5 > 3015
|| T_4 -> V_5 != T_4 -> V_4 )
return FALSE ;
if ( ! F_2 ( V_1 , 2 , NULL , NULL , FALSE , FALSE ) )
return FALSE ;
F_3 ( V_6 , V_1 , T_4 , V_3 ) ;
return TRUE ;
}
static T_1
F_4 ( T_2 * V_1 , T_3 * T_4 , T_5 * V_3 , void * T_6 V_2 )
{
T_7 * V_7 ;
T_5 * V_8 ;
T_8 V_9 , V_10 ;
const char * V_11 = NULL ;
if ( T_4 -> V_4 < 3000 || T_4 -> V_4 > 3015
|| T_4 -> V_5 < 3000 || T_4 -> V_5 > 3015
|| T_4 -> V_5 != T_4 -> V_4 )
return FALSE ;
if ( F_5 ( V_1 ) < 2 )
return FALSE ;
V_10 = F_6 ( V_1 , 0 ) ;
V_9 = F_6 ( V_1 , 1 ) ;
if ( F_7 ( V_1 ) != 8 || V_10 != 2 ) {
return FALSE ;
}
F_8 ( T_4 -> V_12 , V_13 , L_1 ) ;
switch ( V_9 ) {
case V_14 :
V_11 = L_2 ;
break;
case V_15 :
V_11 = L_3 ;
break;
case V_16 :
V_11 = L_4 ;
break;
case V_17 :
V_11 = L_5 ;
break;
default:
V_11 = L_6 ;
break;
}
F_8 ( T_4 -> V_12 , V_18 , V_11 ) ;
if ( V_3 ) {
V_7 = F_9 ( V_3 , V_19 , V_1 , 0 , 8 , V_20 ) ;
V_8 = F_10 ( V_7 , V_21 ) ;
F_9 ( V_8 , V_22 , V_1 , 0 , 1 , V_23 ) ;
F_11 ( V_8 , V_24 , V_1 , 1 , 1 , V_9 , L_7 , V_9 , V_11 ) ;
F_9 ( V_8 , V_25 , V_1 , 2 , 2 , V_23 ) ;
F_9 ( V_8 , V_26 , V_1 , 4 , 2 , V_23 ) ;
F_9 ( V_8 , V_27 , V_1 , 6 , 2 , V_23 ) ;
}
return TRUE ;
}
void
F_12 ( void )
{
V_6 = F_13 ( L_8 ) ;
F_14 ( L_9 , F_4 , V_19 ) ;
F_14 ( L_9 , F_1 , F_15 ( L_8 ) ) ;
}
void
F_16 ( void )
{
static T_9 V_28 [] = {
{ & V_22 ,
{ L_10 , L_11 ,
V_29 , V_30 , NULL , 0x0 ,
NULL , V_31 }
} ,
{ & V_24 ,
{ L_12 , L_13 ,
V_29 , V_30 , NULL , 0x0 ,
NULL , V_31 }
} ,
{ & V_25 ,
{ L_14 , L_15 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_31 }
} ,
{ & V_26 ,
{ L_16 , L_17 ,
V_32 , V_30 , NULL , 0x0 ,
NULL , V_31 }
} ,
{ & V_27 ,
{ L_14 , L_18 ,
V_32 , V_33 , NULL , 0x0 ,
NULL , V_31 }
} ,
} ;
static T_10 * V_34 [] = {
& V_21 ,
} ;
V_19 = F_17 ( L_19 ,
L_1 , L_20 ) ;
F_18 ( V_19 , V_28 , F_19 ( V_28 ) ) ;
F_20 ( V_34 , F_19 ( V_34 ) ) ;
}
