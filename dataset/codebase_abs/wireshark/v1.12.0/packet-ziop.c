static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 ) {
T_5 V_5 = 0 ;
T_6 V_6 , V_7 , V_8 ;
T_3 * V_9 = NULL ;
T_7 * V_10 ;
F_2 ( V_2 -> V_11 , V_12 , V_13 ) ;
F_3 ( V_2 -> V_11 , V_14 ) ;
V_6 = F_4 ( V_1 , 4 ) ;
V_7 = F_4 ( V_1 , 5 ) ;
V_8 = F_4 ( V_1 , 7 ) ;
if ( ( V_6 < 1 ) ||
( V_7 < 2 ) )
{
F_5 ( V_2 -> V_11 , V_14 , L_1 ,
V_6 , V_7 ) ;
if ( V_3 )
{
V_10 = F_6 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_9 = F_7 ( V_10 , V_17 ) ;
F_8 ( V_9 , V_1 , 4 , 2 ,
L_2 ,
V_6 ,
V_7 ) ;
}
F_9 ( V_18 , V_1 , V_2 , V_3 ) ;
return F_10 ( V_1 ) ;
}
F_5 ( V_2 -> V_11 , V_14 , L_3 ,
V_6 ,
V_7 ,
F_11 ( V_8 , V_19 ,
L_4 )
) ;
if ( V_3 )
{
T_6 V_20 ;
T_5 V_21 ;
const char * V_22 = L_5 ;
V_10 = F_6 ( V_3 , V_15 , V_1 , 0 , - 1 , V_16 ) ;
V_9 = F_7 ( V_10 , V_17 ) ;
F_6 ( V_9 , V_23 , V_1 , V_5 , 4 , V_24 | V_16 ) ;
V_5 += 4 ;
F_6 ( V_9 , V_25 , V_1 , V_5 , 1 , V_26 ) ;
V_5 ++ ;
F_6 ( V_9 , V_27 , V_1 , V_5 , 1 , V_26 ) ;
V_5 ++ ;
V_20 = F_4 ( V_1 , V_5 ) ;
V_21 = ( V_20 & 0x01 ) ? V_28 : V_26 ;
if ( V_20 & 0x01 ) {
V_22 = L_6 ;
}
F_12 ( V_9 , V_29 , V_1 , V_5 , 1 ,
V_20 , L_7 , V_20 , V_22 ) ;
V_5 ++ ;
F_6 ( V_9 , V_30 , V_1 , V_5 , 1 , V_26 ) ;
V_5 ++ ;
F_6 ( V_9 , V_31 , V_1 , V_5 , 4 , V_21 ) ;
V_5 += 4 ;
F_6 ( V_9 , V_32 , V_1 , V_5 , 2 , V_21 ) ;
V_5 += 4 ;
F_6 ( V_9 , V_33 , V_1 , V_5 , 4 , V_21 ) ;
}
return F_10 ( V_1 ) ;
}
static T_5
F_13 ( T_2 * V_2 V_4 , T_1 * V_1 , int V_5 )
{
T_6 V_20 ;
T_5 V_34 ;
T_8 V_35 ;
if ( F_14 ( V_1 , 0 , V_13 , 4 ) != 0 )
return 0 ;
V_20 = F_4 ( V_1 , V_5 + 6 ) ;
V_35 = ( ( V_20 & 0x1 ) == 0 ) ;
if ( V_35 )
V_34 = F_15 ( V_1 , V_5 + 8 ) ;
else
V_34 = F_16 ( V_1 , V_5 + 8 ) ;
return V_34 + V_36 ;
}
static int
F_17 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
if ( F_14 ( V_1 , 0 , V_13 , 4 ) != 0 )
{
if ( F_15 ( V_1 , 0 ) == V_37 )
{
F_18 ( V_1 , V_2 , V_3 ) ;
return F_10 ( V_1 ) ;
}
return 0 ;
}
F_19 ( V_1 , V_2 , V_3 , V_38 , V_36 ,
F_13 , F_1 , T_4 ) ;
return F_10 ( V_1 ) ;
}
T_8
F_20 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 )
{
T_5 V_39 ;
T_9 * V_40 ;
V_39 = F_10 ( V_1 ) ;
if ( V_39 < V_36 )
{
return FALSE ;
}
if ( F_14 ( V_1 , 0 , V_13 , 4 ) != 0 )
{
return FALSE ;
}
if ( V_2 -> V_41 == V_42 )
{
if ( ! V_2 -> V_43 -> V_20 . V_44 )
{
V_40 = F_21 ( V_2 ) ;
F_22 ( V_40 , V_45 ) ;
}
F_17 ( V_1 , V_2 , V_3 , T_4 ) ;
}
else
{
F_1 ( V_1 , V_2 , V_3 , T_4 ) ;
}
return TRUE ;
}
void
F_23 ( void )
{
static T_10 V_46 [] = {
{ & V_23 ,
{ L_8 , L_9 , V_47 , V_48 , NULL , 0x0 ,
L_10 , V_49 } } ,
{ & V_25 ,
{ L_11 , L_12 , V_50 , V_51 , NULL , 0x0 ,
L_13 , V_49 } } ,
{ & V_27 ,
{ L_14 , L_15 , V_50 , V_51 , NULL , 0x0 ,
L_16 , V_49 } } ,
{ & V_29 ,
{ L_17 , L_18 , V_50 , V_51 , NULL , 0x0 ,
L_19 , V_49 } } ,
{ & V_30 ,
{ L_20 , L_21 , V_50 , V_51 , F_24 ( V_19 ) , 0x0 ,
L_22 , V_49 } } ,
{ & V_31 ,
{ L_23 , L_24 , V_52 , V_53 , NULL , 0x0 ,
L_25 , V_49 } } ,
{ & V_32 ,
{ L_26 , L_27 , V_54 , V_53 , F_24 ( V_55 ) , 0x0 ,
L_28 , V_49 } } ,
{ & V_33 ,
{ L_29 , L_30 , V_52 , V_53 , NULL , 0x0 ,
L_31 , V_49 } }
} ;
static T_11 * V_56 [] = {
& V_17
} ;
V_15 = F_25 ( L_32 , L_33 ,
L_34 ) ;
F_26 ( V_15 , V_46 , F_27 ( V_46 ) ) ;
F_28 ( V_56 , F_27 ( V_56 ) ) ;
F_29 ( L_34 , F_1 , V_15 ) ;
}
void
F_30 ( void )
{
V_45 = F_31 ( F_17 , V_15 ) ;
F_32 ( L_35 , V_45 ) ;
F_33 ( L_36 , F_20 , V_15 ) ;
V_18 = F_34 ( L_37 ) ;
}
