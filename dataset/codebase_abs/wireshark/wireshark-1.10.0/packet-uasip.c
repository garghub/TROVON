static void F_1 ( T_1 * V_1 , int * V_2 , T_2 * V_3 , T_3 V_4 , T_4 V_5 )
{
switch ( V_5 )
{
case 1 :
F_2 ( V_1 , * V_2 , V_3 , V_4 , V_5 + 2 , F_3 ( V_3 , V_4 + 2 ) ) ;
break;
case 2 :
F_2 ( V_1 , * V_2 , V_3 , V_4 , V_5 + 2 , F_4 ( V_3 , V_4 + 2 ) ) ;
break;
case 3 :
F_2 ( V_1 , * V_2 , V_3 , V_4 , V_5 + 2 , F_5 ( V_3 , V_4 + 2 ) ) ;
break;
case 4 :
F_2 ( V_1 , * V_2 , V_3 , V_4 , V_5 + 2 , F_6 ( V_3 , V_4 + 2 ) ) ;
break;
default:
break;
}
}
static void F_7 ( T_2 * V_3 , T_5 * V_6 , T_1 * V_1 , T_6 V_7 )
{
T_7 * V_8 ;
T_1 * V_9 ;
T_8 V_10 ;
T_3 V_4 = 0 ;
if ( V_11 )
{
F_8 ( V_6 -> V_12 , V_13 , L_1 ) ;
}
else
{
F_8 ( V_6 -> V_12 , V_13 , L_2 ) ;
}
V_10 = F_3 ( V_3 , V_4 ) ;
V_4 ++ ;
V_14 . V_10 = V_10 ;
V_14 . V_15 = 0 ;
V_14 . V_16 = 0 ;
if ( F_9 ( V_6 -> V_12 , V_17 ) )
{
F_10 ( V_6 -> V_12 , V_17 , L_3 , F_11 ( V_10 , & V_18 , L_4 ) ) ;
}
V_8 = F_12 ( V_1 , V_19 , V_3 , 0 , 5 ,
L_5 ,
F_11 ( V_10 , & V_18 , L_4 ) ) ;
V_9 = F_13 ( V_8 , V_20 ) ;
F_2 ( V_9 , V_21 , V_3 , 0 , 1 , V_10 ) ;
switch( V_10 )
{
case V_22 :
{
if ( ! V_1 )
break;
while( F_14 ( V_3 , V_4 ) )
{
T_8 V_23 = F_3 ( V_3 , V_4 + 0 ) ;
T_8 V_5 = F_3 ( V_3 , V_4 + 1 ) ;
switch( V_23 )
{
case V_24 :
F_1 ( V_9 , & V_25 , V_3 , V_4 , V_5 ) ;
break;
case V_26 :
F_1 ( V_9 , & V_27 , V_3 , V_4 , V_5 ) ;
break;
case V_28 :
F_1 ( V_9 , & V_29 , V_3 , V_4 , V_5 ) ;
break;
case V_30 :
F_1 ( V_9 , & V_31 , V_3 , V_4 , V_5 ) ;
break;
case V_32 :
F_1 ( V_9 , & V_33 , V_3 , V_4 , V_5 ) ;
break;
case V_34 :
F_1 ( V_9 , & V_35 , V_3 , V_4 , V_5 ) ;
break;
case V_36 :
F_1 ( V_9 , & V_37 , V_3 , V_4 , V_5 ) ;
break;
case V_38 :
F_1 ( V_9 , & V_39 , V_3 , V_4 , V_5 ) ;
break;
case V_40 :
F_1 ( V_9 , & V_41 , V_3 , V_4 , V_5 ) ;
break;
default:
break;
}
V_4 += ( 2 + V_5 ) ;
}
}
break;
case V_42 :
{
F_2 ( V_9 , V_43 , V_3 , V_4 , 2 , F_4 ( V_3 , V_4 ) ) ;
V_14 . V_15 = F_4 ( V_3 , V_4 + 0 ) ;
if ( V_11 )
{
F_10 ( V_6 -> V_12 , V_17 , L_6 ) ;
}
else
{
F_10 ( V_6 -> V_12 , V_17 , L_7 , V_14 . V_15 ) ;
}
}
break;
case V_44 :
{
int V_45 ;
F_2 ( V_9 , V_43 , V_3 , V_4 + 0 , 2 , F_4 ( V_3 , V_4 + 0 ) ) ;
F_2 ( V_9 , V_46 , V_3 , V_4 + 2 , 2 , F_4 ( V_3 , V_4 + 2 ) ) ;
V_14 . V_15 = F_4 ( V_3 , V_4 + 0 ) ;
V_14 . V_16 = F_4 ( V_3 , V_4 + 2 ) ;
V_4 += 4 ;
V_45 = ( F_15 ( V_3 ) - V_4 ) ;
if ( V_11 )
{
if ( V_45 > 0 )
{
if ( V_7 == V_47 )
{
F_16 ( V_48 , F_17 ( V_3 , V_4 , V_45 , V_45 ) , V_6 , V_1 ) ;
}
else if ( V_7 == V_49 )
{
F_16 ( V_50 , F_17 ( V_3 , V_4 , V_45 , V_45 ) , V_6 , V_1 ) ;
}
else
{
F_18 ( V_6 -> V_12 , V_17 , L_8 ) ;
}
}
else
{
F_18 ( V_6 -> V_12 , V_17 , L_9 ) ;
}
}
else
{
if ( V_45 > 0 )
{
if ( F_9 ( V_6 -> V_12 , V_17 ) )
{
F_10 ( V_6 -> V_12 , V_17 , L_10 , V_14 . V_15 ) ;
F_19 ( V_6 -> V_12 , V_17 , L_11 , V_14 . V_16 ) ;
}
}
else
{
if ( F_9 ( V_6 -> V_12 , V_17 ) )
{
F_10 ( V_6 -> V_12 , V_17 , L_12 , V_14 . V_15 ) ;
F_19 ( V_6 -> V_12 , V_17 , L_11 , V_14 . V_16 ) ;
}
}
}
}
break;
default:
break;
}
#if 0
tap_queue_packet(uasip_tap, pinfo, &ua_tap_info);
#endif
}
static void F_20 ( T_2 * V_3 , T_5 * V_6 , T_1 * V_1 )
{
if ( V_51 )
{
if ( memcmp ( ( V_6 -> V_52 ) . V_53 , V_54 , sizeof( V_54 ) ) == 0 )
{
F_7 ( V_3 , V_6 , V_1 , V_47 ) ;
return;
}
else if ( memcmp ( ( V_6 -> V_55 ) . V_53 , V_54 , sizeof( V_54 ) ) == 0 )
{
F_7 ( V_3 , V_6 , V_1 , V_49 ) ;
return;
}
}
F_7 ( V_3 , V_6 , V_1 , V_56 ) ;
}
void F_21 ( void )
{
T_9 * V_57 ;
static T_10 V_58 [] = {
{
& V_21 ,
{
L_13 ,
L_14 ,
V_59 ,
V_60 | V_61 ,
& V_18 ,
0x0 ,
L_15 ,
V_62
}
} ,
{
& V_25 ,
{
L_16 ,
L_17 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_18 ,
V_62
}
} ,
{
& V_27 ,
{
L_19 ,
L_20 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_21 ,
V_62
}
} ,
{
& V_29 ,
{
L_22 ,
L_23 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_24 ,
V_62
}
} ,
{
& V_31 ,
{
L_25 ,
L_26 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_27 ,
V_62
}
} ,
{
& V_33 ,
{
L_28 ,
L_29 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_30 ,
V_62
}
} ,
{
& V_35 ,
{
L_31 ,
L_32 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_33 ,
V_62
}
} ,
{
& V_37 ,
{
L_34 ,
L_35 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_36 ,
V_62
}
} ,
{
& V_39 ,
{
L_37 ,
L_38 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_39 ,
V_62
}
} ,
{
& V_41 ,
{
L_40 ,
L_41 ,
V_59 ,
V_60 ,
NULL ,
0x0 ,
L_42 ,
V_62
}
} ,
{
& V_43 ,
{
L_43 ,
L_44 ,
V_63 ,
V_60 ,
NULL ,
0x0 ,
L_45 ,
V_62
}
} ,
{
& V_46 ,
{
L_46 ,
L_47 ,
V_63 ,
V_60 ,
NULL ,
0x0 ,
L_48 ,
V_62
}
} ,
} ;
static T_3 * V_64 [] =
{
& V_20 ,
} ;
V_19 = F_22 ( L_49 , L_50 , L_51 ) ;
F_23 ( L_51 , F_20 , V_19 ) ;
F_24 ( V_19 , V_58 , F_25 ( V_58 ) ) ;
F_26 ( V_64 , F_25 ( V_64 ) ) ;
V_57 = F_27 ( V_19 , V_65 ) ;
F_28 ( V_57 , L_52 , L_53 , L_54 , & V_66 ) ;
F_28 ( V_57 , L_55 , L_56 , L_57 , & V_11 ) ;
F_29 ( V_57 , L_58 , L_59 ,
L_60 ,
& V_67 ) ;
#if 0
uasip_tap = register_tap("uasip");
#endif
}
void V_65 ( void )
{
static T_11 V_68 ;
static T_12 V_69 = FALSE ;
if ( ! V_69 )
{
V_68 = F_30 ( F_20 , V_19 ) ;
V_48 = F_31 ( L_61 ) ;
V_50 = F_31 ( L_62 ) ;
V_69 = TRUE ;
}
V_51 = FALSE ;
memset ( V_54 , 0 , sizeof( V_54 ) ) ;
if( V_66 ) {
F_32 ( L_63 , L_64 , V_68 ) ;
} else{
F_33 ( L_63 , L_64 , V_68 ) ;
}
if ( strcmp ( V_67 , L_65 ) != 0 ) {
if ( F_34 ( V_70 , V_67 , V_54 ) == 1 )
{
V_51 = TRUE ;
}
else
{
F_35 ( L_66 , V_67 ) ;
}
}
}
