int T_1 F_1 ( T_2 V_1 , T_2 V_2 ,
T_3 V_3 , int V_4 )
{
static char V_5 [] = L_1 ;
T_4 V_6 ;
T_5 V_7 ;
T_6 V_8 ;
char V_9 [ 200 ] ;
if ( V_3 [ 0 ] == '\0' )
V_10 = F_2 ( V_9 , sizeof V_9 ) ;
else
V_10 = V_3 ;
F_3 ( V_10 , - 1 ) ;
V_8 . V_11 = sizeof( V_8 ) ;
V_8 . V_12 = V_13 | V_14 ;
V_8 . V_15 = V_16 ;
V_8 . V_17 = 0 ;
V_8 . V_18 = 0 ;
V_8 . V_1 = V_1 ;
V_8 . V_19 = F_4 ( NULL , V_20 ) ;
V_8 . V_21 = F_5 ( NULL , V_22 ) ;
V_8 . V_23 = ( V_24 ) F_6 ( V_25 ) ;
V_8 . V_26 = NULL ;
V_8 . V_27 = V_5 ;
V_8 . V_28 = F_4 ( NULL , V_20 ) ;
F_7 ( & V_8 ) ;
V_6 = F_8 ( V_5 , V_29 ,
V_30 , V_31 , V_31 ,
V_31 , V_31 , NULL , NULL , V_1 , NULL ) ;
F_9 ( V_6 , V_4 ) ;
F_10 ( V_6 ) ;
while ( F_11 ( & V_7 , NULL , 0 , 0 ) )
{
F_12 ( & V_7 ) ;
F_13 ( & V_7 ) ;
}
return V_7 . V_32 ;
}
T_7 T_8 V_16 ( T_4 V_6 , T_9 V_33 , T_10 V_32 , T_11 V_34 )
{
T_12 V_35 ;
T_13 V_36 ;
T_14 V_37 ;
static int V_38 = 0 ;
switch ( V_33 )
{
case V_39 :
V_35 = F_14 ( V_6 , & V_36 ) ;
F_15 ( V_6 , & V_37 ) ;
F_16 ( V_35 , L_2 , - 1 ,
& V_37 , V_40 | V_41 | V_42 ) ;
F_17 ( V_6 , & V_36 ) ;
return 0 ;
case V_43 :
F_18 ( 0 ) ;
return 0 ;
}
if ( F_19 ( V_33 , V_32 , V_34 ) == 1 && V_38 == 0 )
{
V_38 = 1 ;
if ( F_20 ( V_10 ) <= 0 )
F_21 ( V_6 , L_3 ,
L_1 , V_44 | V_45 ) ;
F_18 ( 0 ) ;
}
return F_22 ( V_6 , V_33 , V_32 , V_34 ) ;
}
