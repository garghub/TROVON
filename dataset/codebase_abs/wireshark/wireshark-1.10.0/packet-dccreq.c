static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_5 * V_6 ;
T_2 * V_7 ;
int V_8 ;
V_8 = V_3 ;
V_6 = F_2 ( V_2 , V_1 , V_3 , V_4 , L_1 , V_4 ) ;
V_7 = F_3 ( V_6 , V_9 ) ;
while ( V_8 < ( V_3 + V_4 ) )
{
type = F_4 ( V_1 , V_8 ++ ) ;
V_5 = F_4 ( V_1 , V_8 ++ ) ;
switch ( type )
{
case V_10 :
if ( V_5 == 4 )
{
F_5 ( V_7 , V_11 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_14 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_15 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_16 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_17 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_18 :
if ( V_5 == 2 )
{
F_5 ( V_7 , V_19 , V_1 ,
V_8 , 1 , V_12 ) ;
F_5 ( V_7 , V_20 , V_1 ,
V_8 + 1 , 1 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_21 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_22 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_23 :
F_5 ( V_7 , V_24 , V_1 ,
V_8 , V_5 , V_12 ) ;
break;
}
V_8 = V_8 + V_5 ;
}
}
static void
F_7 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_5 * V_6 ;
T_2 * V_7 ;
int V_8 ;
V_8 = V_3 ;
V_6 = F_2 ( V_2 , V_1 , V_3 , V_4 , L_2 , V_4 ) ;
V_7 = F_3 ( V_6 , V_25 ) ;
while ( V_8 < ( V_3 + V_4 ) )
{
type = F_4 ( V_1 , V_8 ++ ) ;
V_5 = F_4 ( V_1 , V_8 ++ ) ;
switch ( type )
{
case V_26 :
if ( V_5 == 8 )
{
F_5 ( V_7 , V_27 , V_1 ,
V_8 , 4 , V_12 ) ;
F_5 ( V_7 , V_28 , V_1 ,
V_8 + 4 , 4 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_29 :
if ( V_5 == 4 )
{
F_5 ( V_7 , V_30 , V_1 ,
V_8 , 2 , V_12 ) ;
F_5 ( V_7 , V_31 , V_1 ,
V_8 + 2 , 2 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_32 :
if ( V_5 == 4 )
{
F_5 ( V_7 , V_33 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
}
V_8 = V_8 + V_5 ;
}
}
static void
F_8 ( T_1 * V_1 , T_6 * V_34 , T_2 * V_2 )
{
T_3 V_8 ;
T_4 type , V_5 ;
T_2 * V_7 ;
T_5 * V_6 ;
T_3 V_4 ;
V_4 = F_9 ( V_1 , 0 ) ;
F_10 ( V_34 -> V_35 , V_36 , L_3 ) ;
if ( V_2 )
{
V_6 =
F_11 ( V_2 , V_37 , V_1 , 0 ,
F_9 ( V_1 , 0 ) ,
L_4 ) ;
V_7 = F_3 ( V_6 , V_38 ) ;
F_5 ( V_7 , V_39 , V_1 , 0 , 2 , V_12 ) ;
V_8 = 2 ;
while ( V_8 < V_4 )
{
type = F_4 ( V_1 , V_8 ++ ) ;
V_5 = F_4 ( V_1 , V_8 ++ ) ;
switch ( type )
{
case V_40 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_41 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_42 :
F_1 ( V_1 , V_7 , V_8 , V_5 ) ;
break;
case V_43 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_44 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_45 :
F_5 ( V_7 , V_46 , V_1 ,
V_8 , V_5 , V_47 ) ;
break;
case V_48 :
if ( V_5 == 4 )
{
F_5 ( V_7 , V_49 , V_1 ,
V_8 , 2 , V_12 ) ;
F_5 ( V_7 , V_50 , V_1 ,
V_8 + 2 , 2 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_51 :
F_7 ( V_1 , V_7 , V_8 , V_5 ) ;
break;
case V_52 :
if ( V_5 == 6 )
{
F_5 ( V_7 , V_53 , V_1 ,
V_8 , V_5 , V_47 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_54 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_55 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_56 :
if ( V_5 == 20 )
{
F_5 ( V_7 , V_57 , V_1 ,
V_8 , V_5 , V_47 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
}
V_8 = V_8 + V_5 ;
}
}
}
void
F_12 ( void )
{
static T_7 V_58 [] = {
{ & V_39 ,
{
L_5 ,
L_6 ,
V_59 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_41 ,
{
L_7 ,
L_8 ,
V_62 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_11 ,
{
L_9 ,
L_10 ,
V_63 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_15 ,
{
L_11 ,
L_12 ,
V_62 , V_60 , F_13 ( V_64 ) , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_17 ,
{
L_13 ,
L_14 ,
V_62 , V_60 , F_13 ( V_65 ) , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_19 ,
{
L_15 ,
L_16 ,
V_62 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_20 ,
{
L_17 ,
L_18 ,
V_62 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_22 ,
{
L_19 ,
L_20 ,
V_62 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_24 ,
{
L_21 ,
L_22 ,
V_62 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_44 ,
{
L_23 ,
L_24 ,
V_62 , V_60 , F_13 ( V_66 ) , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_46 ,
{
L_25 ,
L_26 ,
V_67 , V_68 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_49 ,
{
L_27 ,
L_28 ,
V_59 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_50 ,
{
L_29 ,
L_30 ,
V_59 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_27 ,
{
L_31 ,
L_32 ,
V_63 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_28 ,
{
L_33 ,
L_34 ,
V_63 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_30 ,
{
L_35 ,
L_36 ,
V_59 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_31 ,
{
L_37 ,
L_38 ,
V_59 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_33 ,
{
L_39 ,
L_40 ,
V_63 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_53 ,
{
L_41 ,
L_42 ,
V_69 , V_68 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_55 ,
{
L_43 ,
L_44 ,
V_62 , V_60 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
{ & V_57 ,
{
L_45 ,
L_46 ,
V_67 , V_68 , NULL , 0x0 ,
NULL ,
V_61
}
} ,
} ;
static T_8 * V_70 [] = {
& V_38 ,
& V_25 ,
& V_9 ,
} ;
V_37 =
F_14 ( L_47 ,
L_48 , L_49 ) ;
F_15 ( V_37 , V_58 , F_16 ( V_58 ) ) ;
F_17 ( V_70 , F_16 ( V_70 ) ) ;
F_18 ( L_49 , F_8 , V_37 ) ;
}
void
F_19 ( void )
{
T_9 V_71 ;
V_71 = F_20 ( L_49 ) ;
F_21 ( L_50 , 0x17 , V_71 ) ;
}
