T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
char V_4 [ sizeof F_2 ] ;
T_4 V_5 ;
int V_6 ;
T_5 V_7 ;
T_6 * V_8 ;
if ( ! F_3 ( V_1 -> V_9 , V_4 , sizeof V_4 , V_2 , V_3 ) ) {
if ( * V_2 != V_10 )
return V_11 ;
return V_12 ;
}
if ( memcmp ( V_4 , F_2 , sizeof F_2 ) != 0 ) {
return V_12 ;
}
if ( ! F_3 ( V_1 -> V_9 , & V_5 , sizeof V_5 ,
V_2 , V_3 ) )
return V_11 ;
V_5 = F_4 ( V_5 ) ;
switch ( V_5 ) {
case 1 :
V_6 = V_13 ;
break;
case 2 :
V_6 = V_14 ;
break;
default:
* V_2 = V_15 ;
* V_3 = F_5 ( L_1 ,
V_5 ) ;
return V_11 ;
}
if ( ! F_6 ( V_1 -> V_9 , 2 , V_2 ) )
return V_11 ;
if ( ! F_6 ( V_1 -> V_9 , 4 , V_2 ) )
return V_11 ;
if ( ! F_6 ( V_1 -> V_9 , 4 , V_2 ) )
return V_11 ;
if ( ! F_6 ( V_1 -> V_9 , 4 , V_2 ) )
return V_11 ;
if ( ! F_3 ( V_1 -> V_9 , & V_7 , sizeof V_7 ,
V_2 , V_3 ) )
return V_11 ;
V_7 = F_7 ( V_7 ) ;
if ( ! F_8 ( V_1 -> V_9 , 0x44ef , V_16 , V_2 ) )
return V_11 ;
V_1 -> V_6 = V_6 ;
V_8 = ( T_6 * ) F_9 ( sizeof( T_6 ) ) ;
V_8 -> V_5 = V_5 ;
V_8 -> V_7 = V_7 ;
V_8 -> V_17 = 0 ;
V_1 -> V_18 = ( void * ) V_8 ;
V_1 -> V_19 = V_20 ;
V_1 -> V_21 = V_22 ;
V_1 -> V_23 = V_24 ;
V_1 -> V_25 = 0 ;
V_1 -> V_26 = V_27 ;
return V_28 ;
}
static T_7 V_20 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_8 * V_29 )
{
T_6 * V_8 = ( T_6 * ) V_1 -> V_18 ;
T_5 V_30 ;
int V_31 ;
if ( V_8 -> V_17 == V_8 -> V_7 ) {
* V_2 = 0 ;
return FALSE ;
}
V_30 = V_8 -> V_17 % V_32 ;
if ( V_30 == 0 ) {
V_8 -> V_33 = F_10 ( V_1 -> V_9 ) ;
if ( ! F_6 ( V_1 -> V_9 , 1 , V_2 ) )
return FALSE ;
if ( ! F_3 ( V_1 -> V_9 , & V_8 -> V_34 ,
sizeof V_8 -> V_34 , V_2 , V_3 ) )
return FALSE ;
if ( ! F_6 ( V_1 -> V_9 , 4 , V_2 ) )
return FALSE ;
}
* V_29 = V_8 -> V_33 +
F_7 ( V_8 -> V_34 [ V_30 ] ) ;
if ( ! F_8 ( V_1 -> V_9 , * V_29 , V_16 , V_2 ) )
return FALSE ;
V_31 = F_11 ( V_1 , V_1 -> V_9 , & V_1 -> V_35 ,
V_1 -> V_36 , V_2 , V_3 ) ;
if ( V_31 == - 1 )
return FALSE ;
if ( V_31 != 0 ) {
if ( ! F_6 ( V_1 -> V_9 , V_31 , V_2 ) )
return FALSE ;
}
V_8 -> V_17 ++ ;
return TRUE ;
}
static T_7
V_22 ( T_2 * V_1 , T_8 V_37 ,
struct V_38 * V_35 , T_9 * V_39 , int * V_2 , T_3 * * V_3 )
{
if ( F_8 ( V_1 -> V_40 , V_37 , V_16 , V_2 ) == - 1 )
return FALSE ;
if ( F_11 ( V_1 , V_1 -> V_40 , V_35 , V_39 , V_2 , V_3 ) == - 1 ) {
if ( * V_2 == 0 )
* V_2 = V_10 ;
return FALSE ;
}
return TRUE ;
}
static int
F_11 ( T_2 * V_1 , T_10 V_9 , struct V_38 * V_35 ,
T_9 * V_39 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_8 = ( T_6 * ) V_1 -> V_18 ;
struct V_41 V_41 ;
struct V_42 V_42 ;
T_5 V_43 ;
T_5 V_44 ;
T_5 V_45 ;
T_5 V_46 ;
T_11 V_47 ;
switch ( V_8 -> V_5 ) {
case 1 :
if ( ! F_12 ( V_9 , & V_41 ,
sizeof V_41 , V_2 , V_3 ) )
return - 1 ;
V_43 = F_4 ( V_41 . V_48 ) ;
V_45 = F_4 ( V_41 . V_49 ) ;
V_44 = F_4 ( V_41 . V_50 ) ;
V_46 = sizeof V_41 ;
V_47 = ( ( ( T_11 ) F_7 ( V_41 . V_51 ) ) << 32 ) + F_7 ( V_41 . V_52 ) ;
if ( ! F_6 ( V_9 , ( V_41 . V_53 + V_41 . V_54 ) * 4 ,
V_2 ) )
return - 1 ;
V_46 += ( V_41 . V_53 + V_41 . V_54 ) * 4 ;
break;
case 2 :
if ( ! F_12 ( V_9 , & V_42 ,
sizeof V_42 , V_2 , V_3 ) )
return - 1 ;
V_43 = F_4 ( V_42 . V_48 ) ;
V_45 = F_4 ( V_42 . V_49 ) ;
V_44 = F_4 ( V_42 . V_50 ) ;
V_46 = sizeof V_42 ;
V_47 = ( ( ( T_11 ) F_7 ( V_42 . V_51 ) ) << 32 ) + F_7 ( V_42 . V_52 ) ;
break;
default:
F_13 () ;
* V_2 = V_55 ;
return - 1 ;
}
if ( V_45 > V_56 ) {
* V_2 = V_57 ;
* V_3 = F_5 ( L_2 ,
V_45 , V_56 ) ;
return - 1 ;
}
if ( V_44 > V_56 ) {
* V_2 = V_57 ;
* V_3 = F_5 ( L_3 ,
V_44 , V_56 ) ;
return - 1 ;
}
if ( V_46 + V_44 > V_43 ) {
* V_2 = V_57 ;
* V_3 = F_5 ( L_4 ,
V_44 , V_46 , V_43 ) ;
return - 1 ;
}
if ( V_45 == V_44 + 4 )
V_45 = V_44 ;
V_35 -> V_58 . V_59 . V_60 = 0 ;
V_35 -> V_61 = V_62 ;
V_35 -> V_63 = V_44 ;
V_35 -> V_64 = V_45 ;
V_35 -> V_65 = V_66 | V_67 ;
V_35 -> V_68 . V_69 = ( V_70 ) ( V_47 / 1000000 ) ;
V_35 -> V_68 . V_71 = ( ( int ) ( V_47 % 1000000 ) ) * 1000 ;
if ( ! F_14 ( V_9 , V_39 , V_44 , V_2 , V_3 ) )
return - 1 ;
return V_43 - ( V_46 + V_44 ) ;
}
