static int F_1 ( T_1 * V_1 )
{
int V_2 = 0 ;
if ( ( V_1 [ 0 ] & 0xF0 ) == 0xF0 ) {
V_2 = 255 ;
} else if ( ( V_1 [ 0 ] & 0xE0 ) == 0xE0 ) {
V_2 = 4 ;
} else if ( ( V_1 [ 0 ] & 0xE0 ) == 0xC0 ) {
V_2 = 3 ;
} else if ( ( V_1 [ 0 ] & 0xC0 ) == 0x80 ) {
V_2 = 2 ;
} else if ( ( V_1 [ 0 ] & 0x80 ) == 0x00 ) {
V_2 = 1 ;
}
return V_2 ;
}
static void
F_2 ( T_2 * V_3 , T_3 * V_4 , T_4 * V_5 )
{
T_5 * V_6 ;
T_4 * V_7 , * V_8 ;
T_2 * V_9 ;
T_6 V_10 , V_11 ;
T_7 V_12 , V_1 , V_13 ;
T_1 V_14 , V_15 , V_16 ;
F_3 ( V_4 -> V_17 , V_18 , L_1 ) ;
F_3 ( V_4 -> V_17 , V_19 , L_2 ) ;
V_6 = F_4 ( V_5 , V_20 , V_3 , 0 , - 1 , V_21 ) ;
V_7 = F_5 ( V_6 , V_22 ) ;
V_11 = 0 ;
F_4 ( V_7 ,
V_23 , V_3 , V_11 , 1 , V_24 ) ;
V_11 ++ ;
V_1 = F_6 ( V_3 , V_11 ) ;
V_12 = ( T_7 ) F_1 ( ( T_1 * ) & V_1 ) ;
if ( V_12 == 2 )
V_1 = F_7 ( V_3 , V_11 ) ;
else if ( V_12 == 3 )
{
V_1 = F_8 ( V_3 , V_11 ) ;
V_1 = V_1 & 0x00FFFF ;
}
else if ( V_12 == 4 )
V_1 = F_8 ( V_3 , V_11 ) ;
F_4 ( V_7 ,
V_25 , V_3 , V_11 , V_12 , V_24 ) ;
V_11 += V_12 ;
V_14 = F_6 ( V_3 , V_11 ) ;
while ( ( V_14 != V_26 ) && ( V_14 != V_27 ) && ( V_14 != V_28 ) )
{
V_11 ++ ;
if ( V_14 == V_29 )
{
V_15 = F_6 ( V_3 , V_11 ) ;
V_11 ++ ;
F_4 ( V_7 ,
V_30 , V_3 , V_11 , V_15 , V_24 ) ;
V_11 += V_15 ;
}
else if ( V_14 == V_31 )
{
V_15 = F_6 ( V_3 , V_11 ) ;
V_11 ++ ;
F_4 ( V_7 ,
V_32 , V_3 , V_11 , V_15 , V_24 ) ;
V_11 += V_15 ;
}
else if ( V_14 == V_33 )
{
V_15 = F_6 ( V_3 , V_11 ) ;
V_11 ++ ;
F_4 ( V_7 ,
V_34 , V_3 , V_11 , V_15 , V_24 ) ;
V_11 += V_15 ;
}
V_14 = F_6 ( V_3 , V_11 ) ;
}
F_4 ( V_7 ,
V_35 , V_3 , V_11 , 1 , V_24 ) ;
V_11 ++ ;
V_10 = F_9 ( V_3 , V_11 ) ;
F_4 ( V_7 ,
V_36 , V_3 , V_11 , 2 , V_24 ) ;
V_11 += 2 ;
if ( V_14 == V_27 )
{
V_16 = 1 ;
V_13 = 0 ;
while ( V_16 )
{
V_16 = F_6 ( V_3 , V_11 + V_13 ) ;
V_16 = V_16 & 0x80 ;
V_13 ++ ;
}
F_4 ( V_7 ,
V_37 , V_3 , V_11 , V_13 , V_24 ) ;
V_10 -= V_13 ;
V_11 += V_13 ;
}
V_8 = F_10 ( V_7 , V_3 , V_11 , V_10 ,
V_38 , NULL , L_3 ) ;
V_9 = F_11 ( V_3 , V_11 , - 1 , V_10 ) ;
if ( V_1 == 0xbff0 )
{
F_12 ( V_39 , V_9 , V_4 , V_8 ) ;
}
}
void
F_13 ( void )
{
static T_8 V_40 [] = {
{ & V_23 ,
{ L_4 , L_5 , V_41 , V_42 , NULL , 0x0 ,
NULL , V_43 } } ,
{ & V_25 ,
{ L_6 , L_7 , V_44 , V_45 , NULL , 0x0 ,
NULL , V_43 } } ,
{ & V_30 ,
{ L_8 , L_9 , V_41 , V_42 , NULL , 0x0 ,
NULL , V_43 } } ,
{ & V_32 ,
{ L_10 , L_11 , V_41 , V_42 , NULL , 0x0 ,
NULL , V_43 } } ,
{ & V_34 ,
{ L_12 , L_13 , V_41 , V_42 , NULL , 0x0 ,
NULL , V_43 } } ,
{ & V_35 ,
{ L_14 , L_15 , V_41 , V_42 , F_14 ( V_46 ) , 0x0 ,
NULL , V_43 } } ,
{ & V_36 ,
{ L_16 , L_17 , V_47 , V_42 , NULL , 0x0 ,
NULL , V_43 } } ,
{ & V_37 ,
{ L_18 , L_19 , V_41 , V_45 , NULL , 0x0 ,
NULL , V_43 } } ,
} ;
static T_9 * V_48 [] = {
& V_22 ,
& V_38 ,
} ;
V_20 = F_15 ( L_20 ,
L_1 , L_21 ) ;
F_16 ( V_20 , V_40 , F_17 ( V_40 ) ) ;
F_18 ( V_48 , F_17 ( V_48 ) ) ;
}
void
F_19 ( void )
{
T_10 V_49 ;
V_49 = F_20 ( F_2 , V_20 ) ;
F_21 ( L_22 , V_50 , V_49 ) ;
V_39 = F_22 ( L_23 ) ;
return;
}
