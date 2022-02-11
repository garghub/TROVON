static void
F_1 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_2 * V_6 ;
int V_7 ;
V_7 = V_3 ;
V_6 = F_2 ( V_2 , V_1 , V_3 , V_4 , V_8 , NULL ,
L_1 , V_4 ) ;
while ( V_7 < ( V_3 + V_4 ) )
{
type = F_3 ( V_1 , V_7 ++ ) ;
V_5 = F_3 ( V_1 , V_7 ++ ) ;
switch ( type )
{
case V_9 :
if ( V_5 == 4 )
{
F_4 ( V_6 , V_10 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_13 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_14 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_15 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_16 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_17 :
if ( V_5 == 2 )
{
F_4 ( V_6 , V_18 , V_1 ,
V_7 , 1 , V_11 ) ;
F_4 ( V_6 , V_19 , V_1 ,
V_7 + 1 , 1 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_20 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_21 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_22 :
F_4 ( V_6 , V_23 , V_1 ,
V_7 , V_5 , V_11 ) ;
break;
}
V_7 = V_7 + V_5 ;
}
}
static void
F_6 ( T_1 * V_1 , T_2 * V_2 , int V_3 , T_3 V_4 )
{
T_4 type , V_5 ;
T_2 * V_6 ;
int V_7 ;
V_7 = V_3 ;
V_6 = F_2 ( V_2 , V_1 , V_3 , V_4 , V_24 , NULL , L_2 , V_4 ) ;
while ( V_7 < ( V_3 + V_4 ) )
{
type = F_3 ( V_1 , V_7 ++ ) ;
V_5 = F_3 ( V_1 , V_7 ++ ) ;
switch ( type )
{
case V_25 :
if ( V_5 == 8 )
{
F_4 ( V_6 , V_26 , V_1 ,
V_7 , 4 , V_11 ) ;
F_4 ( V_6 , V_27 , V_1 ,
V_7 + 4 , 4 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_28 :
if ( V_5 == 4 )
{
F_4 ( V_6 , V_29 , V_1 ,
V_7 , 2 , V_11 ) ;
F_4 ( V_6 , V_30 , V_1 ,
V_7 + 2 , 2 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_31 :
if ( V_5 == 4 )
{
F_4 ( V_6 , V_32 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
}
V_7 = V_7 + V_5 ;
}
}
static int
F_7 ( T_1 * V_1 , T_5 * V_33 , T_2 * V_2 , void * T_6 V_34 )
{
T_3 V_7 ;
T_4 type , V_5 ;
T_2 * V_6 ;
T_7 * V_35 ;
T_3 V_4 ;
V_4 = F_8 ( V_1 ) ;
F_9 ( V_33 -> V_36 , V_37 , L_3 ) ;
if ( V_2 )
{
V_35 =
F_10 ( V_2 , V_38 , V_1 , 0 ,
- 1 , L_4 ) ;
V_6 = F_11 ( V_35 , V_39 ) ;
F_4 ( V_6 , V_40 , V_1 , 0 , 2 , V_11 ) ;
V_7 = 2 ;
while ( V_7 < V_4 )
{
type = F_3 ( V_1 , V_7 ++ ) ;
V_5 = F_3 ( V_1 , V_7 ++ ) ;
switch ( type )
{
case V_41 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_42 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_43 :
F_1 ( V_1 , V_6 , V_7 , V_5 ) ;
break;
case V_44 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_45 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_46 :
F_4 ( V_6 , V_47 , V_1 ,
V_7 , V_5 , V_48 ) ;
break;
case V_49 :
if ( V_5 == 4 )
{
F_4 ( V_6 , V_50 , V_1 ,
V_7 , 2 , V_11 ) ;
F_4 ( V_6 , V_51 , V_1 ,
V_7 + 2 , 2 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_52 :
F_6 ( V_1 , V_6 , V_7 , V_5 ) ;
break;
case V_53 :
if ( V_5 == 6 )
{
F_4 ( V_6 , V_54 , V_1 ,
V_7 , V_5 , V_48 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_55 :
if ( V_5 == 1 )
{
F_4 ( V_6 , V_56 , V_1 ,
V_7 , V_5 , V_11 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
case V_57 :
if ( V_5 == 20 )
{
F_4 ( V_6 , V_58 , V_1 ,
V_7 , V_5 , V_48 ) ;
}
else
{
F_5 ( V_12 ) ;
}
break;
}
V_7 = V_7 + V_5 ;
}
}
return F_12 ( V_1 ) ;
}
void
F_13 ( void )
{
static T_8 V_59 [] = {
{ & V_40 ,
{
L_5 ,
L_6 ,
V_60 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_42 ,
{
L_7 ,
L_8 ,
V_63 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_10 ,
{
L_9 ,
L_10 ,
V_64 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_14 ,
{
L_11 ,
L_12 ,
V_63 , V_61 , F_14 ( V_65 ) , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_16 ,
{
L_13 ,
L_14 ,
V_63 , V_61 , F_14 ( V_66 ) , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_18 ,
{
L_15 ,
L_16 ,
V_63 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_19 ,
{
L_17 ,
L_18 ,
V_63 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_21 ,
{
L_19 ,
L_20 ,
V_63 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_23 ,
{
L_21 ,
L_22 ,
V_63 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_45 ,
{
L_23 ,
L_24 ,
V_63 , V_61 , F_14 ( V_67 ) , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_47 ,
{
L_25 ,
L_26 ,
V_68 , V_69 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_50 ,
{
L_27 ,
L_28 ,
V_60 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_51 ,
{
L_29 ,
L_30 ,
V_60 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_26 ,
{
L_31 ,
L_32 ,
V_64 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_27 ,
{
L_33 ,
L_34 ,
V_64 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_29 ,
{
L_35 ,
L_36 ,
V_60 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_30 ,
{
L_37 ,
L_38 ,
V_60 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_32 ,
{
L_39 ,
L_40 ,
V_64 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_54 ,
{
L_41 ,
L_42 ,
V_70 , V_69 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_56 ,
{
L_43 ,
L_44 ,
V_63 , V_61 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
{ & V_58 ,
{
L_45 ,
L_46 ,
V_68 , V_69 , NULL , 0x0 ,
NULL ,
V_62
}
} ,
} ;
static T_9 * V_71 [] = {
& V_39 ,
& V_24 ,
& V_8 ,
} ;
V_38 =
F_15 ( L_47 ,
L_48 , L_49 ) ;
F_16 ( V_38 , V_59 , F_17 ( V_59 ) ) ;
F_18 ( V_71 , F_17 ( V_71 ) ) ;
F_19 ( L_49 , F_7 , V_38 ) ;
}
void
F_20 ( void )
{
T_10 V_72 ;
V_72 = F_21 ( L_49 ) ;
F_22 ( L_50 , 0x17 , V_72 ) ;
}
