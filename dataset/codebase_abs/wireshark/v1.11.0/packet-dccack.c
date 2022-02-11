static void
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 )
{
T_4 V_4 ;
T_5 type , V_5 ;
T_3 * V_6 ;
T_6 * V_7 ;
T_4 V_8 ;
V_8 = F_2 ( V_1 , 0 ) ;
F_3 ( V_2 -> V_9 , V_10 , L_1 ) ;
if ( V_3 )
{
V_7 =
F_4 ( V_3 , V_11 , V_1 , 0 ,
F_2 ( V_1 , 0 ) ,
L_2 ) ;
V_6 = F_5 ( V_7 , V_12 ) ;
F_6 ( V_6 , V_13 , V_1 , 0 , 2 , V_14 ) ;
V_4 = 2 ;
while ( V_4 < V_8 )
{
type = F_7 ( V_1 , V_4 ++ ) ;
V_5 = F_7 ( V_1 , V_4 ++ ) ;
switch ( type )
{
case V_15 :
if ( V_5 == 1 )
{
F_6 ( V_6 , V_16 , V_1 ,
V_4 , V_5 , V_14 ) ;
}
else
{
F_8 ( V_17 ) ;
}
break;
case V_18 :
if ( V_5 == 20 )
{
F_6 ( V_6 , V_19 , V_1 ,
V_4 , V_5 , V_20 ) ;
}
else
{
F_8 ( V_17 ) ;
}
break;
}
V_4 = V_4 + V_5 ;
}
}
}
void
F_9 ( void )
{
static T_7 V_21 [] = {
{ & V_13 ,
{
L_3 ,
L_4 ,
V_22 , V_23 , NULL , 0x0 ,
NULL ,
V_24
}
} ,
{ & V_16 ,
{
L_5 ,
L_6 ,
V_25 , V_23 , NULL , 0x0 ,
NULL ,
V_24
}
} ,
{ & V_19 ,
{
L_7 ,
L_8 ,
V_26 , V_27 , NULL , 0x0 ,
NULL ,
V_24
}
} ,
} ;
static T_8 * V_28 [] = {
& V_12 ,
} ;
V_11 =
F_10 ( L_9 ,
L_10 , L_11 ) ;
F_11 ( V_11 , V_21 , F_12 ( V_21 ) ) ;
F_13 ( V_28 , F_12 ( V_28 ) ) ;
F_14 ( L_11 , F_1 , V_11 ) ;
}
void
F_15 ( void )
{
T_9 V_29 ;
V_29 = F_16 ( L_11 ) ;
F_17 ( L_12 , 0x19 , V_29 ) ;
}
