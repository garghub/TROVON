static void
F_1 ( T_1 V_1 , T_1 V_2 , T_2 * V_3 , T_3 V_4 , T_4 * V_5 )
{
const char * V_6 ;
T_4 * V_7 , * V_8 = NULL ;
V_6 = F_2 ( V_1 , V_9 , L_1 ) ;
V_7 = F_3 ( V_5 , V_3 , V_4 , V_2 + 2 , L_2 , V_6 ) ;
V_8 = F_4 ( V_7 , V_10 ) ;
F_3 ( V_8 , V_3 , V_4 , 1 , L_3 , V_1 ) ;
F_3 ( V_8 , V_3 , V_4 + 1 , 1 , L_4 , V_2 ) ;
if ( ! V_2 )
return;
switch( V_1 ) {
case ( V_11 ) :
F_5 ( V_8 , V_12 , V_3 ,
V_4 + 2 , V_2 , V_13 ) ;
break;
case ( V_14 ) :
F_5 ( V_8 , V_15 , V_3 ,
V_4 + 2 , V_2 , V_13 ) ;
break;
case ( V_16 ) :
F_5 ( V_8 , V_17 , V_3 ,
V_4 + 2 , V_2 , V_13 ) ;
break;
case ( V_18 ) :
F_5 ( V_8 , V_19 , V_3 ,
V_4 + 2 , V_2 , V_20 | V_21 ) ;
break;
case ( V_22 ) :
F_5 ( V_8 , V_23 , V_3 ,
V_4 + 2 , V_2 , V_21 ) ;
break;
case ( V_24 ) :
F_5 ( V_8 , V_25 , V_3 ,
V_4 + 2 , V_2 , V_21 ) ;
break;
case ( V_26 ) :
F_5 ( V_8 , V_27 , V_3 ,
V_4 + 2 , V_2 , V_21 ) ;
break;
default:
F_5 ( V_8 , V_28 , V_3 ,
V_4 + 2 , V_2 , V_21 ) ;
break;
}
return;
}
static void
F_6 ( T_2 * V_3 , T_5 * V_29 , T_4 * V_5 )
{
T_1 V_1 , V_2 ;
T_3 V_30 , V_4 = 0 ;
T_6 V_31 ;
T_4 * V_7 , * V_32 = NULL ;
T_2 * V_33 ;
F_7 ( V_29 -> V_34 , V_35 , L_5 ) ;
if ( V_5 ) {
V_7 = F_5 ( V_5 , V_36 ,
V_3 , 0 , - 1 , V_21 ) ;
V_32 = F_4 ( V_7 , V_10 ) ;
}
V_30 = F_8 ( V_3 ) ;
V_4 = 0 ;
V_31 = FALSE ;
while( ! V_31 && ( V_30 > 2 ) ) {
V_1 = F_9 ( V_3 , V_4 + 0 ) ;
V_2 = F_9 ( V_3 , V_4 + 1 ) ;
if ( ( V_30 - 2 ) < V_2 )
break;
if ( V_5 )
F_1 ( V_1 , V_2 , V_3 , V_4 , V_32 ) ;
if ( V_1 == V_22 )
V_31 = TRUE ;
V_4 += 2 + V_2 ;
V_30 -= 2 + V_2 ;
}
V_33 = F_10 ( V_3 , V_4 ) ;
F_11 ( V_37 , V_33 , V_29 , V_5 ) ;
}
static T_6
F_12 ( T_2 * V_3 , T_5 * V_29 , T_4 * V_5 , void * T_7 V_38 )
{
T_3 V_30 , V_4 = 0 ;
T_6 V_31 = FALSE ;
T_1 V_1 , V_2 ;
T_8 V_39 = 0 ;
V_30 = F_8 ( V_3 ) ;
if ( V_30 < V_40 )
return FALSE ;
while( ( V_30 > 2 ) && ! V_31 ) {
V_1 = F_9 ( V_3 , V_4 + 0 ) ;
V_2 = F_9 ( V_3 , V_4 + 1 ) ;
switch( V_1 ) {
case ( V_11 ) :
case ( V_14 ) :
case ( V_16 ) :
if ( V_2 != 4 )
return FALSE ;
V_39 |= 1 << V_1 ;
break;
case ( V_22 ) :
if ( V_2 > 1 || V_4 == 0 )
return FALSE ;
V_31 = TRUE ;
break;
case ( V_18 ) :
case ( V_24 ) :
case ( V_26 ) :
break;
default:
return FALSE ;
}
V_4 += 2 + V_2 ;
V_30 -= 2 + V_2 ;
}
if ( ! ( V_39 & ( 1 << V_11 ) ) )
return FALSE ;
if ( ! ( V_39 & ( 1 << V_16 ) ) )
return FALSE ;
if ( ! ( V_39 & ( 1 << V_14 ) ) )
return FALSE ;
F_6 ( V_3 , V_29 , V_5 ) ;
return TRUE ;
}
void F_13 ( void ) {
static T_9 V_41 [] = {
{ & V_12 ,
{ L_6 , L_7 , V_42 , V_43 , NULL , 0x0 ,
NULL , V_44 } } ,
{ & V_15 ,
{ L_8 , L_9 , V_42 , V_43 , NULL , 0x0 ,
L_10 , V_44 } } ,
{ & V_17 ,
{ L_11 , L_12 , V_42 , V_43 , NULL , 0x0 ,
L_13 , V_44 } } ,
{ & V_25 ,
#if 0
{ "Direction", "redbackli.dir", FT_UINT8, BASE_DEC, NULL, 0x0,
#endif
{ L_14 , L_15 , V_45 , V_46 , NULL , 0x0 ,
NULL , V_44 } } ,
{ & V_19 ,
{ L_16 , L_17 , V_47 , V_46 , NULL , 0x0 ,
NULL , V_44 } } ,
{ & V_27 ,
{ L_18 , L_19 , V_45 , V_46 , NULL , 0x0 ,
NULL , V_44 } } ,
{ & V_23 ,
{ L_20 , L_21 , V_45 , V_46 , NULL , 0x0 ,
NULL , V_44 } } ,
{ & V_28 ,
{ L_22 , L_23 , V_45 , V_46 , NULL , 0x0 ,
NULL , V_44 } }
} ;
static T_3 * V_48 [] = {
& V_10
} ;
V_36 = F_14 ( L_24 ,
L_25 , L_26 ) ;
F_15 ( V_36 , V_41 , F_16 ( V_41 ) ) ;
F_17 ( V_48 , F_16 ( V_48 ) ) ;
F_18 ( L_26 , F_6 , V_36 ) ;
}
void F_19 ( void ) {
T_10 V_49 ;
V_37 = F_20 ( L_27 ) ;
V_49 = F_20 ( L_26 ) ;
F_21 ( L_28 , V_49 ) ;
F_22 ( L_29 , F_12 , V_36 ) ;
}
