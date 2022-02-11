void F_1 ( T_1 * V_1 )
{
V_2 . V_3 . V_4 = 0 ;
V_2 . V_3 . V_5 = 0 ;
V_2 . V_3 . V_6 = 0 ;
V_2 . V_3 . V_7 = 0 ;
V_2 . V_3 . V_8 = 0 ;
V_2 . V_3 . V_9 = 0 ;
V_2 . V_3 . V_10 = 0 ;
V_2 . V_3 . V_11 = 0 ;
V_2 . V_3 . V_12 = 0 ;
V_2 . V_3 . V_13 = 0 ;
V_2 . V_3 . V_14 = 0 ;
V_2 . V_3 . V_15 = 0 ;
V_2 . V_3 . V_16 = 0 ;
V_2 . V_3 . V_17 = 0 ;
V_2 . V_18 = NULL ;
V_2 . V_19 . V_3 = & V_2 . V_3 ;
F_2 ( & V_2 . V_19 , V_1 ) ;
}
static const char *
F_3 ( int V_20 , T_2 * V_21 , T_3 V_22 ,
int V_23 )
{
const char * V_24 ;
static char V_25 [ 1024 + 1 ] ;
if ( V_20 < 0 ) {
switch ( V_20 ) {
case V_26 :
V_24 = L_1 ;
break;
case V_27 :
V_24 = L_2 ;
break;
case V_28 :
F_4 ( V_25 , sizeof( V_25 ) ,
L_3
L_4 , V_21 ) ;
F_5 ( V_21 ) ;
V_24 = V_25 ;
break;
case V_29 :
F_4 ( V_25 , sizeof( V_25 ) ,
L_5
L_6 , F_6 ( V_23 ) ) ;
V_24 = V_25 ;
break;
case V_30 :
V_24 = L_7 ;
break;
case V_31 :
if ( V_22 )
V_24 = L_8 ;
else {
F_4 ( V_25 , sizeof( V_25 ) ,
L_9
L_4 , V_21 ) ;
F_5 ( V_21 ) ;
V_24 = V_25 ;
}
break;
case V_32 :
if ( V_22 )
V_24 = L_8 ;
else
V_24 = L_10 ;
break;
case V_33 :
F_4 ( V_25 , sizeof( V_25 ) ,
L_11
L_4 , V_21 ) ;
F_5 ( V_21 ) ;
V_24 = V_25 ;
break;
case V_34 :
if ( V_22 )
V_24 = L_12 ;
else
V_24 = L_13 ;
break;
case V_35 :
V_24 = L_14
L_15 ;
break;
case V_36 :
V_24 = L_16 ;
break;
case V_37 :
F_4 ( V_25 , sizeof( V_25 ) ,
L_17
L_4 , V_21 ) ;
F_5 ( V_21 ) ;
V_24 = V_25 ;
break;
default:
F_4 ( V_25 , sizeof( V_25 ) ,
L_18 ,
V_22 ? L_19 : L_20 ,
F_7 ( V_20 ) ) ;
V_24 = V_25 ;
break;
}
} else
V_24 = F_8 ( V_20 , V_22 ) ;
return V_24 ;
}
T_3 F_9 ( const char * V_38 )
{
int V_20 ;
T_2 * V_21 ;
T_2 * V_39 ;
if( V_2 . V_18 != NULL ) {
F_10 ( V_2 . V_18 ) ;
}
V_2 . V_18 = F_11 ( V_38 , & V_20 , & V_21 , FALSE ) ;
if ( ! V_2 . V_18 ) {
V_39 = F_12 ( F_3 ( V_20 , V_21 , FALSE , V_40 ) ,
V_38 ) ;
F_13 ( L_21 , V_20 , V_39 ) ;
F_5 ( V_39 ) ;
return FALSE ;
} else
return TRUE ;
}
void F_14 ( int V_41 )
{
int V_20 ;
T_2 * V_21 ;
T_4 V_42 ;
struct V_43 * V_44 ;
union V_45 * V_46 ;
int V_47 ;
const T_5 * V_48 ;
V_2 . V_19 . V_49 = V_41 ;
while ( V_41 > 0 ) {
F_15 ( V_2 . V_18 ) ;
if ( F_16 ( V_2 . V_18 , & V_20 , & V_21 , & V_42 ) ) {
V_44 = F_17 ( V_2 . V_18 ) ;
V_46 = & V_44 -> V_46 ;
V_47 = V_44 -> V_50 ;
V_48 = F_18 ( V_2 . V_18 ) ;
F_19 ( & V_2 . V_3 , V_47 , V_48 , V_44 -> V_51 , V_46 ) ;
V_41 -- ;
}
}
F_20 ( & V_2 . V_19 ) ;
}
void F_21 ( void )
{
F_22 ( & V_2 . V_19 ) ;
if( V_2 . V_18 )
F_10 ( V_2 . V_18 ) ;
}
static void
F_19 ( T_6 * V_3 , T_7 V_47 , const T_5 * V_52 , T_8 V_51 , union V_45 * V_46 )
{
V_3 -> V_4 ++ ;
switch ( V_47 ) {
case V_53 :
F_23 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_54 :
case V_55 :
F_24 ( V_52 , V_51 , V_3 ) ;
break;
case V_56 :
F_25 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_57 :
F_26 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_58 :
F_27 ( V_52 , V_51 , V_3 ) ;
break;
case V_59 :
F_28 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_60 :
F_29 ( V_52 , V_51 , V_3 ) ;
break;
case V_61 :
F_30 ( V_52 , V_51 , V_3 ) ;
break;
case V_62 :
F_31 ( V_52 , V_51 , V_3 ) ;
break;
case V_63 :
case V_64 :
F_32 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_65 :
F_33 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_66 :
F_34 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_67 :
F_35 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_68 :
F_36 ( V_3 ) ;
break;
case V_69 :
F_37 ( V_46 , V_52 , V_51 , V_3 ) ;
break;
case V_70 :
F_38 ( V_52 , V_51 , V_3 ) ;
break;
case V_71 :
F_39 ( V_52 , V_51 , V_3 , FALSE , TRUE ) ;
break;
case V_72 :
F_39 ( V_52 , V_51 , V_3 , TRUE , FALSE ) ;
break;
case V_73 :
F_40 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_74 :
case V_75 :
F_41 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_76 :
F_42 ( V_52 , V_51 , V_3 ) ;
break;
case V_77 :
F_43 ( V_52 , V_51 , V_3 ) ;
break;
case V_78 :
F_44 ( V_46 , V_3 ) ;
break;
case V_79 :
F_45 ( V_52 , 0 , V_51 , V_3 ) ;
break;
case V_80 :
F_46 ( V_52 , 0 , V_51 , V_3 ) ;
break;
}
}
