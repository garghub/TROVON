static int
F_1 ( T_1 * V_1 , T_2 * V_2 , T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 ;
T_6 type , V_6 ;
T_3 * V_7 ;
T_7 * V_8 ;
T_5 V_9 ;
V_9 = F_2 ( V_1 ) ;
F_3 ( V_2 -> V_10 , V_11 , L_1 ) ;
if ( V_3 )
{
V_8 =
F_4 ( V_3 , V_12 , V_1 , 0 ,
- 1 , L_2 ) ;
V_7 = F_5 ( V_8 , V_13 ) ;
F_6 ( V_7 , V_14 , V_1 , 0 , 2 , V_15 ) ;
V_5 = 2 ;
while ( V_5 < V_9 )
{
type = F_7 ( V_1 , V_5 ++ ) ;
V_6 = F_7 ( V_1 , V_5 ++ ) ;
switch ( type )
{
case V_16 :
if ( V_6 == 1 )
{
F_6 ( V_7 , V_17 , V_1 ,
V_5 , V_6 , V_15 ) ;
}
else
{
F_8 ( V_18 ) ;
}
break;
case V_19 :
if ( V_6 == 20 )
{
F_6 ( V_7 , V_20 , V_1 ,
V_5 , V_6 , V_21 ) ;
}
else
{
F_8 ( V_18 ) ;
}
break;
}
V_5 = V_5 + V_6 ;
}
}
return F_9 ( V_1 ) ;
}
void
F_10 ( void )
{
static T_8 V_22 [] = {
{ & V_14 ,
{
L_3 ,
L_4 ,
V_23 , V_24 , NULL , 0x0 ,
NULL ,
V_25
}
} ,
{ & V_17 ,
{
L_5 ,
L_6 ,
V_26 , V_24 , NULL , 0x0 ,
NULL ,
V_25
}
} ,
{ & V_20 ,
{
L_7 ,
L_8 ,
V_27 , V_28 , NULL , 0x0 ,
NULL ,
V_25
}
} ,
} ;
static T_9 * V_29 [] = {
& V_13 ,
} ;
V_12 =
F_11 ( L_9 ,
L_10 , L_11 ) ;
F_12 ( V_12 , V_22 , F_13 ( V_22 ) ) ;
F_14 ( V_29 , F_13 ( V_29 ) ) ;
F_15 ( L_11 , F_1 , V_12 ) ;
}
void
F_16 ( void )
{
T_10 V_30 ;
V_30 = F_17 ( L_11 ) ;
F_18 ( L_12 , 0x19 , V_30 ) ;
}
