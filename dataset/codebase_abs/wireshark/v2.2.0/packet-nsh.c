static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 )
{
F_2 ( V_2 , V_4 , V_1 , V_3 , 4 , V_5 ) ;
F_2 ( V_2 , V_4 , V_1 , V_3 + 4 , 4 , V_5 ) ;
F_2 ( V_2 , V_4 , V_1 , V_3 + 8 , 4 , V_5 ) ;
F_2 ( V_2 , V_4 , V_1 , V_3 + 12 , 4 , V_5 ) ;
}
static void
F_3 ( T_1 * V_1 , T_2 * V_2 , int V_3 , int V_6 )
{
int V_7 = 0 ;
while ( V_3 < V_6 ) {
F_2 ( V_2 , V_8 , V_1 , V_3 , 2 , V_9 ) ;
F_2 ( V_2 , V_10 , V_1 , V_3 + 2 , 1 , V_9 ) ;
F_2 ( V_2 , V_11 , V_1 , V_3 + 3 , 1 , V_9 ) ;
F_2 ( V_2 , V_12 , V_1 , V_3 + 3 , 1 , V_9 ) ;
V_7 = 4 * F_4 ( V_1 , ( ( V_3 + 3 ) * 8 ) + 3 , 5 ) ;
if ( V_7 >= 4 )
F_2 ( V_2 , V_13 , V_1 , V_3 + 4 , V_7 , V_5 ) ;
V_3 = V_3 + 4 + V_7 ;
}
}
static int
F_5 ( T_1 * V_1 , T_3 * V_14 , T_2 * V_15 , void * T_4 V_16 )
{
int V_3 = 0 ;
int V_17 = - 1 ;
int V_6 = 0 ;
int V_18 = - 1 ;
int V_19 ;
T_1 * V_20 ;
F_6 ( V_14 -> V_21 , V_22 , L_1 ) ;
F_6 ( V_14 -> V_21 , V_23 , L_2 ) ;
V_19 = F_7 ( V_1 ) ;
if ( V_15 ) {
T_5 * V_24 ;
T_2 * V_2 ;
V_6 = 4 * F_4 ( V_1 , 10 , 6 ) ;
V_24 = F_2 ( V_15 , V_25 , V_1 , V_3 , V_6 , V_5 ) ;
V_2 = F_8 ( V_24 , V_26 ) ;
F_2 ( V_2 , V_27 , V_1 , V_3 , 2 , V_9 ) ;
F_2 ( V_2 , V_28 , V_1 , V_3 , 2 , V_9 ) ;
F_2 ( V_2 , V_29 , V_1 , V_3 , 2 , V_9 ) ;
F_2 ( V_2 , V_30 , V_1 , V_3 , 2 , V_9 ) ;
F_2 ( V_2 , V_31 , V_1 , V_3 , 2 , V_9 ) ;
V_17 = F_9 ( V_1 , V_3 + 2 ) ;
F_2 ( V_2 , V_32 , V_1 , V_3 + 2 , 1 , V_9 ) ;
V_18 = F_9 ( V_1 , V_3 + 3 ) ;
F_2 ( V_2 , V_33 , V_1 , V_3 + 3 , 1 , V_9 ) ;
V_3 = V_3 + 4 ;
F_2 ( V_2 , V_34 , V_1 , V_3 , 3 , V_9 ) ;
F_2 ( V_2 , V_35 , V_1 , V_3 + 3 , 1 , V_9 ) ;
V_3 = V_3 + 4 ;
switch ( V_17 ) {
case V_36 :
F_1 ( V_1 , V_2 , V_3 ) ;
break;
case V_37 :
if ( V_6 > 8 )
F_3 ( V_1 , V_2 , V_3 , V_6 ) ;
break;
}
if ( V_19 > ( V_6 ) ) {
V_20 = F_10 ( V_1 , V_6 ) ;
switch ( V_18 ) {
case V_38 :
F_11 ( V_39 , V_20 , V_14 , V_15 ) ;
break;
case V_40 :
F_11 ( V_41 , V_20 , V_14 , V_15 ) ;
break;
case V_42 :
F_11 ( V_43 , V_20 , V_14 , V_15 ) ;
break;
}
}
}
return F_7 ( V_1 ) ;
}
void
F_12 ( void )
{
static T_6 V_44 [] = {
{ & V_27 ,
{ L_3 , L_4 ,
V_45 , V_46 , NULL , 0xC000 ,
NULL , V_47 }
} ,
{ & V_28 ,
{ L_5 , L_6 ,
V_45 , V_48 , NULL , 0x2000 ,
L_7 , V_47 }
} ,
{ & V_29 ,
{ L_8 , L_9 ,
V_45 , V_48 , NULL , 0x1000 ,
L_10 , V_47 }
} ,
{ & V_30 ,
{ L_11 , L_12 ,
V_45 , V_49 , NULL , 0x0FC0 ,
L_13 , V_47 }
} ,
{ & V_31 ,
{ L_14 , L_15 ,
V_45 , V_46 , NULL , 0x003F ,
L_16 , V_47 }
} ,
{ & V_32 ,
{ L_17 , L_18 ,
V_50 , V_46 , NULL , 0x00 ,
L_19 , V_47 }
} ,
{ & V_33 ,
{ L_20 , L_21 ,
V_50 , V_46 , F_13 ( V_51 ) , 0x00 ,
L_22 , V_47 }
} ,
{ & V_34 ,
{ L_23 , L_24 ,
V_52 , V_46 , NULL , 0x00 ,
L_25 , V_47 }
} ,
{ & V_35 ,
{ L_26 , L_27 ,
V_50 , V_46 , NULL , 0x00 ,
L_28 , V_47 }
} ,
{ & V_4 ,
{ L_29 , L_30 ,
V_53 , V_54 , NULL , 0x00 ,
L_31 , V_47 }
} ,
{ & V_8 ,
{ L_32 , L_33 ,
V_45 , V_46 , NULL , 0x00 ,
L_34 , V_47 }
} ,
{ & V_10 ,
{ L_35 , L_36 ,
V_50 , V_46 , NULL , 0x00 ,
L_37 , V_47 }
} ,
{ & V_11 ,
{ L_11 , L_38 ,
V_50 , V_49 , NULL , 0xE0 ,
L_39 , V_47 }
} ,
{ & V_12 ,
{ L_14 , L_40 ,
V_50 , V_49 , NULL , 0x1F ,
L_41 , V_47 }
} ,
{ & V_13 ,
{ L_42 , L_43 ,
V_53 , V_54 , NULL , 0x00 ,
L_44 , V_47 }
} ,
} ;
static T_7 * V_55 [] = {
& V_26 ,
} ;
V_25 = F_14 ( L_2 ,
L_1 , L_45 ) ;
F_15 ( V_25 , V_44 , F_16 ( V_44 ) ) ;
F_17 ( V_55 , F_16 ( V_55 ) ) ;
}
void
F_18 ( void )
{
T_8 V_56 ;
V_56 = F_19 ( F_5 , V_25 ) ;
F_20 ( L_46 , V_57 , V_56 ) ;
F_20 ( L_47 , V_58 , V_56 ) ;
V_39 = F_21 ( L_48 , V_25 ) ;
V_41 = F_21 ( L_49 , V_25 ) ;
V_43 = F_21 ( L_50 , V_25 ) ;
}
