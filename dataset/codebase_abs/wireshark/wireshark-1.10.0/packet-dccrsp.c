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
if ( V_5 == 8 )
{
F_5 ( V_7 , V_15 , V_1 ,
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
F_7 ( T_1 * V_1 , T_6 * V_16 , T_2 * V_2 )
{
T_3 V_8 ;
T_4 type , V_5 ;
T_2 * V_7 ;
T_5 * V_6 ;
T_3 V_4 ;
V_4 = F_8 ( V_1 , 0 ) ;
F_9 ( V_16 -> V_17 , V_18 , L_2 ) ;
if ( V_2 )
{
V_6 =
F_10 ( V_2 , V_19 , V_1 , 0 ,
F_8 ( V_1 , 0 ) ,
L_3 ) ;
V_7 = F_3 ( V_6 , V_20 ) ;
F_5 ( V_7 , V_21 , V_1 , 0 , 2 , V_12 ) ;
F_5 ( V_7 , V_22 , V_1 , 2 , 1 , V_12 ) ;
V_8 = 3 ;
while ( V_8 < V_4 )
{
type = F_4 ( V_1 , V_8 ++ ) ;
V_5 = F_4 ( V_1 , V_8 ++ ) ;
switch ( type )
{
case V_23 :
F_1 ( V_1 , V_7 , V_8 , V_5 ) ;
break;
case V_24 :
if ( V_5 == 1 )
{
F_5 ( V_7 , V_25 , V_1 ,
V_8 , V_5 , V_12 ) ;
}
else
{
F_6 ( V_13 ) ;
}
break;
case V_26 :
if ( V_5 == 20 )
{
F_5 ( V_7 , V_27 , V_1 ,
V_8 , V_5 , V_28 ) ;
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
F_11 ( void )
{
static T_7 V_29 [] = {
{ & V_21 ,
{
L_4 ,
L_5 ,
V_30 , V_31 , NULL , 0x0 ,
NULL ,
V_32
}
} ,
{ & V_22 ,
{
L_6 ,
L_7 ,
V_33 , V_31 , NULL , 0x0 ,
NULL ,
V_32
}
} ,
{ & V_11 ,
{
L_8 ,
L_9 ,
V_34 , V_31 , NULL , 0x0 ,
NULL ,
V_32
}
} ,
{ & V_15 ,
{
L_10 ,
L_11 ,
V_35 , V_31 , NULL , 0x0 ,
NULL ,
V_32
}
} ,
{ & V_25 ,
{
L_12 ,
L_13 ,
V_33 , V_31 , NULL , 0x0 ,
NULL ,
V_32
}
} ,
{ & V_27 ,
{
L_14 ,
L_15 ,
V_36 , V_37 , NULL , 0x0 ,
NULL ,
V_32
}
} ,
} ;
static T_8 * V_38 [] = {
& V_20 ,
& V_9 ,
} ;
V_19 =
F_12 ( L_16 ,
L_17 , L_18 ) ;
F_13 ( V_19 , V_29 , F_14 ( V_29 ) ) ;
F_15 ( V_38 , F_14 ( V_38 ) ) ;
F_16 ( L_18 , F_7 , V_19 ) ;
}
void
F_17 ( void )
{
T_9 V_39 ;
V_39 = F_18 ( L_18 ) ;
F_19 ( L_19 , 0x18 , V_39 ) ;
}
