static void F_1 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
if ( V_4 >= V_2 -> V_9 ) {
V_3 [ 2 ] = V_10 ;
return;
}
V_3 [ 2 ] = V_11 ;
V_6 = V_2 -> V_5 [ V_4 ] -> V_6 ;
V_3 [ 9 ] = V_4 ;
V_3 [ 13 ] = V_6 -> V_12 ;
memcpy ( V_3 + 16 , V_2 -> V_13 , V_14 ) ;
memcpy ( V_3 + 24 , V_2 -> V_5 [ V_4 ] -> V_15 ,
V_14 ) ;
V_3 [ 40 ] = ( V_6 -> V_16 << 4 ) |
V_6 -> V_17 ;
V_3 [ 41 ] = ( V_6 -> V_18 << 4 ) |
V_6 -> V_19 ;
if ( ! V_2 -> V_5 [ V_4 ] -> V_20 ||
! V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 )
return;
V_8 = V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_8 ;
V_3 [ 12 ] = V_8 -> V_22 . V_23 << 4 ;
V_3 [ 14 ] = V_8 -> V_22 . V_24 ;
V_3 [ 15 ] = V_8 -> V_22 . V_25 ;
}
static void F_2 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 V_4 )
{
struct V_7 * V_8 ;
struct V_26 * V_27 ;
int V_28 ;
if ( V_4 >= V_2 -> V_9 ) {
V_3 [ 2 ] = V_10 ;
return;
}
V_3 [ 2 ] = V_29 ;
if ( ! V_2 -> V_5 [ V_4 ] -> V_20 )
return;
V_8 = V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_8 ;
V_27 = (struct V_26 * )
V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_30 ;
if ( V_8 -> V_22 . V_25 != V_31 )
return;
V_3 [ 2 ] = V_11 ;
V_3 [ 9 ] = V_4 ;
memcpy ( V_3 + 16 , V_2 -> V_5 [ V_4 ] -> V_15 ,
V_14 ) ;
if ( V_27 -> V_32 != 0x34 )
return;
for ( V_28 = 0 ; V_28 < 20 ; V_28 += 4 ) {
T_1 * V_33 = V_3 + 24 + V_28 , * V_34 =
& V_2 -> V_5 [ V_4 ] -> V_20 -> V_21 -> V_30 [ V_28 ] ;
V_33 [ 0 ] = V_34 [ 3 ] ;
V_33 [ 1 ] = V_34 [ 2 ] ;
V_33 [ 2 ] = V_34 [ 1 ] ;
V_33 [ 3 ] = V_34 [ 0 ] ;
}
}
static void F_3 ( struct V_1 * V_2 , T_1 V_4 ,
T_1 V_35 , enum V_36 V_37 ,
enum V_36 V_38 , T_1 * V_3 )
{
struct V_39 * V_28 =
F_4 ( V_2 -> V_40 . V_41 -> V_42 ) ;
struct V_43 V_44 ;
if ( V_4 >= V_2 -> V_9 ) {
V_3 [ 2 ] = V_10 ;
return;
}
switch ( V_35 ) {
case V_45 :
case V_46 :
case V_47 :
case V_48 :
case V_49 :
case V_50 :
case V_51 :
break;
default:
V_3 [ 2 ] = V_52 ;
return;
}
V_44 . V_16 = V_37 ;
V_44 . V_18 = V_38 ;
if ( V_28 -> V_53 -> V_54 ( V_2 -> V_5 [ V_4 ] , V_35 , & V_44 ) )
V_3 [ 2 ] = V_55 ;
else
V_3 [ 2 ] = V_11 ;
}
int F_5 ( struct V_56 * V_41 , struct V_57 * V_58 ,
struct V_57 * V_59 )
{
T_1 * V_60 = NULL , * V_3 = NULL , * V_61 ;
struct V_1 * V_2 = F_6 ( V_41 ) ;
int error = - V_62 ;
if ( F_7 ( V_58 ) < 8 || F_7 ( V_59 ) < 8 )
goto V_63;
if ( F_8 ( V_58 -> V_64 ) + F_7 ( V_58 ) > V_65 ||
F_8 ( V_59 -> V_64 ) + F_7 ( V_59 ) > V_65 ) {
F_9 ( V_66 , V_41 ,
L_1 ) ;
goto V_63;
}
V_60 = F_10 ( F_7 ( V_58 ) , V_67 ) ;
V_3 = F_10 ( V_38 ( F_7 ( V_59 ) , 128U ) , V_67 ) ;
if ( ! V_60 || ! V_3 ) {
error = - V_68 ;
goto V_63;
}
F_11 () ;
V_61 = F_12 ( F_13 ( V_58 -> V_64 ) , V_69 ) + F_8 ( V_58 -> V_64 ) ;
memcpy ( V_60 , V_61 , F_7 ( V_58 ) ) ;
F_14 ( V_61 - F_8 ( V_58 -> V_64 ) , V_69 ) ;
F_15 () ;
if ( V_60 [ 0 ] != V_70 )
goto V_63;
error = 0 ;
V_3 [ 0 ] = V_71 ;
V_3 [ 1 ] = V_60 [ 1 ] ;
V_3 [ 2 ] = V_72 ;
switch ( V_60 [ 1 ] ) {
case V_73 :
V_58 -> V_74 -= 8 ;
V_59 -> V_74 -= 32 ;
V_3 [ 2 ] = V_11 ;
V_3 [ 9 ] = V_2 -> V_9 ;
break;
case V_75 :
V_58 -> V_74 -= 8 ;
V_59 -> V_74 -= 64 ;
V_3 [ 2 ] = V_11 ;
memcpy ( V_3 + 12 , V_41 -> V_76 -> V_77 ,
V_78 ) ;
memcpy ( V_3 + 20 , L_2 ,
V_79 ) ;
break;
case V_80 :
break;
case V_81 :
V_58 -> V_74 -= 16 ;
if ( ( int ) V_58 -> V_74 < 0 ) {
V_58 -> V_74 = 0 ;
error = - V_62 ;
goto V_63;
}
V_59 -> V_74 -= 56 ;
F_1 ( V_2 , V_3 , V_60 [ 9 ] ) ;
break;
case V_82 :
break;
case V_83 :
V_58 -> V_74 -= 16 ;
if ( ( int ) V_58 -> V_74 < 0 ) {
V_58 -> V_74 = 0 ;
error = - V_62 ;
goto V_63;
}
V_59 -> V_74 -= 60 ;
F_2 ( V_2 , V_3 , V_60 [ 9 ] ) ;
break;
case V_84 :
break;
case V_85 :
break;
case V_86 :
break;
case V_87 :
V_58 -> V_74 -= 44 ;
if ( ( int ) V_58 -> V_74 < 0 ) {
V_58 -> V_74 = 0 ;
error = - V_62 ;
goto V_63;
}
V_59 -> V_74 -= 8 ;
F_3 ( V_2 , V_60 [ 9 ] , V_60 [ 10 ] ,
V_60 [ 32 ] >> 4 , V_60 [ 33 ] >> 4 ,
V_3 ) ;
break;
case V_88 :
break;
default:
break;
}
F_11 () ;
V_61 = F_12 ( F_13 ( V_59 -> V_64 ) , V_69 ) + F_8 ( V_59 -> V_64 ) ;
memcpy ( V_61 , V_3 , F_7 ( V_59 ) ) ;
F_16 ( F_13 ( V_59 -> V_64 ) ) ;
F_14 ( V_61 - F_8 ( V_59 -> V_64 ) , V_69 ) ;
F_15 () ;
V_63:
F_17 ( V_60 ) ;
F_17 ( V_3 ) ;
return error ;
}
