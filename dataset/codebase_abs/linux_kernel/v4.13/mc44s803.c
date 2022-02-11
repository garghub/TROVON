static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
T_2 V_4 [ 3 ] ;
struct V_5 V_6 = {
. V_7 = V_2 -> V_8 -> V_9 , . V_10 = 0 , . V_4 = V_4 , . V_11 = 3
} ;
V_4 [ 0 ] = ( V_3 & 0xff0000 ) >> 16 ;
V_4 [ 1 ] = ( V_3 & 0xff00 ) >> 8 ;
V_4 [ 2 ] = ( V_3 & 0xff ) ;
if ( F_2 ( V_2 -> V_12 , & V_6 , 1 ) != 1 ) {
F_3 ( V_13 , L_1 ) ;
return - V_14 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , T_2 V_15 , T_1 * V_3 )
{
T_1 V_16 ;
T_2 V_4 [ 3 ] ;
int V_17 ;
struct V_5 V_6 [] = {
{ . V_7 = V_2 -> V_8 -> V_9 , . V_10 = V_18 ,
. V_4 = V_4 , . V_11 = 3 } ,
} ;
V_16 = F_5 ( V_19 , V_20 ) |
F_5 ( V_15 , V_21 ) ;
V_17 = F_1 ( V_2 , V_16 ) ;
if ( V_17 )
return V_17 ;
if ( F_2 ( V_2 -> V_12 , V_6 , 1 ) != 1 ) {
F_3 ( V_13 , L_2 ) ;
return - V_14 ;
}
* V_3 = ( V_4 [ 0 ] << 16 ) | ( V_4 [ 1 ] << 8 ) | V_4 [ 2 ] ;
return 0 ;
}
static void F_6 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
V_23 -> V_24 = NULL ;
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
T_1 V_3 ;
int V_25 ;
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 1 ) ;
V_3 = F_5 ( V_28 , V_20 ) |
F_5 ( 1 , V_29 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_28 , V_20 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_30 , V_20 ) |
F_5 ( 0xC0 , V_31 ) |
F_5 ( 1 , V_32 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_33 , V_20 ) |
F_5 ( 0x200 , V_34 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
F_9 ( 10 ) ;
V_3 = F_5 ( V_30 , V_20 ) |
F_5 ( 0x40 , V_31 ) |
F_5 ( 1 , V_32 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
F_9 ( 20 ) ;
V_3 = F_5 ( V_35 , V_20 ) |
F_5 ( 1 , V_36 ) |
F_5 ( 0x7F , V_37 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_38 , V_20 ) |
F_5 ( 1 , V_39 ) |
F_5 ( 1 , V_40 ) |
F_5 ( 0x3 , V_41 ) |
F_5 ( 1 , V_42 ) |
F_5 ( V_2 -> V_8 -> V_43 , V_44 ) |
F_5 ( 0x3 , V_45 ) |
F_5 ( 1 , V_46 ) |
F_5 ( 1 , V_47 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_38 , V_20 ) |
F_5 ( 1 , V_39 ) |
F_5 ( 1 , V_40 ) |
F_5 ( 0x3 , V_41 ) |
F_5 ( 1 , V_42 ) |
F_5 ( V_2 -> V_8 -> V_43 , V_44 ) |
F_5 ( 0x3 , V_45 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_48 , V_20 ) |
F_5 ( 3 , V_49 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_50 , V_20 ) |
F_5 ( 1 , V_51 ) |
F_5 ( 1 , V_52 ) |
F_5 ( 1 , V_53 ) |
F_5 ( 1 , V_54 ) |
F_5 ( 1 , V_55 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 0 ) ;
return 0 ;
exit:
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 0 ) ;
F_3 ( V_13 , L_3 ) ;
return V_25 ;
}
static int F_10 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
struct V_56 * V_57 = & V_23 -> V_58 ;
T_1 V_59 , V_60 , V_61 , V_62 , V_63 , V_64 , V_65 , V_3 ;
int V_25 ;
V_2 -> V_66 = V_57 -> V_66 ;
V_59 = V_67 / 1000000 ;
V_60 = V_67 / 100000 ;
V_61 = ( V_57 -> V_66 + V_68 + 500000 ) / 1000000 ;
V_65 = V_67 / V_59 * V_61 ;
V_63 = ( ( 60 * V_61 ) + ( V_59 / 2 ) ) / V_59 ;
V_65 = V_65 - V_57 -> V_66 ;
V_62 = ( V_65 - V_69 + 50000 ) / 100000 ;
V_64 = ( ( 60 * V_62 ) + ( V_60 / 2 ) ) / V_60 ;
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 1 ) ;
V_3 = F_5 ( V_70 , V_20 ) |
F_5 ( V_59 - 1 , V_71 ) |
F_5 ( V_60 - 1 , V_72 ) |
F_5 ( 1 , V_73 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_74 , V_20 ) |
F_5 ( V_61 - 2 , V_75 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_76 , V_20 ) |
F_5 ( V_62 - 2 , V_77 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_48 , V_20 ) |
F_5 ( 1 , V_78 ) |
F_5 ( V_63 , V_79 ) |
F_5 ( 1 , V_80 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
V_3 = F_5 ( V_48 , V_20 ) |
F_5 ( 2 , V_78 ) |
F_5 ( V_64 , V_79 ) |
F_5 ( 1 , V_80 ) ;
V_25 = F_1 ( V_2 , V_3 ) ;
if ( V_25 )
goto exit;
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 0 ) ;
return 0 ;
exit:
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 0 ) ;
F_3 ( V_13 , L_3 ) ;
return V_25 ;
}
static int F_11 ( struct V_22 * V_23 , T_1 * V_66 )
{
struct V_1 * V_2 = V_23 -> V_24 ;
* V_66 = V_2 -> V_66 ;
return 0 ;
}
static int F_12 ( struct V_22 * V_23 , T_1 * V_66 )
{
* V_66 = V_69 ;
return 0 ;
}
struct V_22 * F_13 ( struct V_22 * V_23 ,
struct V_81 * V_12 , struct V_82 * V_8 )
{
struct V_1 * V_2 ;
T_1 V_15 ;
T_2 V_83 ;
int V_17 ;
V_15 = 0 ;
V_2 = F_14 ( sizeof( struct V_1 ) , V_84 ) ;
if ( V_2 == NULL )
return NULL ;
V_2 -> V_8 = V_8 ;
V_2 -> V_12 = V_12 ;
V_2 -> V_23 = V_23 ;
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 1 ) ;
V_17 = F_4 ( V_2 , V_85 , & V_15 ) ;
if ( V_17 )
goto error;
V_83 = F_15 ( V_15 , V_86 ) ;
if ( V_83 != 0x14 ) {
F_3 ( V_87 , L_4 ,
V_83 ) ;
goto error;
}
F_3 ( V_88 , L_5 , V_83 ) ;
memcpy ( & V_23 -> V_26 . V_89 , & V_90 ,
sizeof( struct V_91 ) ) ;
V_23 -> V_24 = V_2 ;
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 0 ) ;
return V_23 ;
error:
if ( V_23 -> V_26 . V_27 )
V_23 -> V_26 . V_27 ( V_23 , 0 ) ;
F_7 ( V_2 ) ;
return NULL ;
}
