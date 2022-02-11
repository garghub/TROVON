static int F_1 ( struct V_1 * V_2 ,
struct F_1 * V_3 , bool V_4 )
{
T_1 V_5 ;
int V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
V_5 = sizeof( struct F_1 ) ;
V_6 = F_2 ( V_8 -> V_10 , F_3 ( V_8 -> V_10 , 0 ) ,
V_11 , V_12 , 0x0000 , 0x0000 ,
V_3 , V_5 , V_13 ) ;
if ( V_6 != V_5 )
V_4 = true ;
if ( V_4 ) {
F_4 ( & V_2 -> V_14 , L_1 ) ;
return - V_15 ;
}
F_5 ( & V_2 -> V_14 , L_2 , V_3 -> V_3 ) ;
if ( V_3 -> V_3 != 0x00 ) {
F_4 ( & V_2 -> V_14 , L_3 ) ;
return - V_16 ;
}
return 0 ;
}
static int F_6 ( struct V_17 * V_10 ,
struct V_18 * V_19 , int V_5 )
{
int V_6 , V_20 ;
int error = 0 ;
V_6 = F_7 ( V_10 ,
F_8 ( V_10 , V_21 ) , V_19 ,
sizeof( struct V_22 ) , & V_20 ,
V_13 ) ;
if ( ( V_6 < 0 )
|| ( V_20 != sizeof( struct V_22 ) ) ) {
F_4 ( & V_10 -> V_14 , L_4 ) ;
error = - V_15 ;
}
V_6 = F_7 ( V_10 ,
F_9 ( V_10 , V_23 ) , V_19 ,
V_5 , & V_20 , V_13 ) ;
if ( ( V_6 < 0 ) || ( V_5 != V_20 ) ) {
F_4 ( & V_10 -> V_14 , L_5 ) ;
error = - V_15 ;
}
return error ;
}
static int F_10 ( struct V_17 * V_10 ,
struct V_24 * V_25 )
{
int V_6 , V_20 ;
V_6 = F_7 ( V_10 ,
F_8 ( V_10 , V_21 ) , V_25 ,
sizeof( struct V_24 ) , & V_20 ,
V_13 ) ;
if ( ( V_6 < 0 ) ||
( sizeof( struct V_24 ) != V_20 ) ) {
F_4 ( & V_10 -> V_14 , L_4 ) ;
return - V_15 ;
}
return 0 ;
}
static int F_11 ( struct V_7 * V_8 , struct V_26 * V_27 )
{
int V_6 ;
T_1 V_28 , V_29 , V_30 , V_31 = 0x0000 ;
struct V_18 * V_19 =
(struct V_18 * ) V_8 -> V_32 ;
V_28 = V_27 -> V_33 ;
V_19 -> V_34 . V_35 = V_36 ;
while ( V_28 > 0 ) {
V_19 -> V_34 . V_37 = F_12 ( V_31 + 0x4000 ) ;
if ( V_28 <= 255 ) {
V_29 = V_28 ;
V_30 = 0x00 ;
V_19 -> V_34 . V_38 = V_28 ;
V_19 -> V_34 . V_29 = 0x00 ;
V_19 -> V_34 . V_30 = 0x00 ;
V_19 -> V_34 . V_39 = 0x00 ;
V_19 -> V_34 . V_40 = 0x00 ;
V_19 -> V_34 . V_41 = 0x00 ;
V_28 = 0 ;
} else if ( V_28 <= 510 ) {
V_29 = V_28 ;
V_30 = 0x00 ;
V_19 -> V_34 . V_38 = V_28 - 255 ;
V_19 -> V_34 . V_29 = 0xff ;
V_19 -> V_34 . V_30 = 0x00 ;
V_19 -> V_34 . V_39 = 0x00 ;
V_19 -> V_34 . V_40 = 0x00 ;
V_19 -> V_34 . V_41 = 0x00 ;
V_28 = 0 ;
} else if ( V_28 <= 512 ) {
V_29 = V_28 ;
V_30 = 0x00 ;
V_19 -> V_34 . V_38 = V_28 - 510 ;
V_19 -> V_34 . V_29 = 0xff ;
V_19 -> V_34 . V_30 = 0xff ;
V_19 -> V_34 . V_39 = 0x00 ;
V_19 -> V_34 . V_40 = 0x00 ;
V_19 -> V_34 . V_41 = 0x00 ;
V_28 = 0 ;
} else if ( V_28 <= 767 ) {
V_29 = 512 ;
V_30 = V_28 - 512 ;
V_19 -> V_34 . V_38 = 0x02 ;
V_19 -> V_34 . V_29 = 0xff ;
V_19 -> V_34 . V_30 = 0xff ;
V_19 -> V_34 . V_39 = V_28 - 512 ;
V_19 -> V_34 . V_40 = 0x00 ;
V_19 -> V_34 . V_41 = 0x00 ;
V_28 = 0 ;
} else if ( V_28 <= 1022 ) {
V_29 = 512 ;
V_30 = V_28 - 512 ;
V_19 -> V_34 . V_38 = 0x02 ;
V_19 -> V_34 . V_29 = 0xff ;
V_19 -> V_34 . V_30 = 0xff ;
V_19 -> V_34 . V_39 = V_28 - 767 ;
V_19 -> V_34 . V_40 = 0xff ;
V_19 -> V_34 . V_41 = 0x00 ;
V_28 = 0 ;
} else if ( V_28 <= 1024 ) {
V_29 = 512 ;
V_30 = V_28 - 512 ;
V_19 -> V_34 . V_38 = 0x02 ;
V_19 -> V_34 . V_29 = 0xff ;
V_19 -> V_34 . V_30 = 0xff ;
V_19 -> V_34 . V_39 = V_28 - 1022 ;
V_19 -> V_34 . V_40 = 0xff ;
V_19 -> V_34 . V_41 = 0xff ;
V_28 = 0 ;
} else {
V_29 = 512 ;
V_30 = 512 ;
V_19 -> V_34 . V_38 = 0x02 ;
V_19 -> V_34 . V_29 = 0xff ;
V_19 -> V_34 . V_30 = 0xff ;
V_19 -> V_34 . V_39 = 0x02 ;
V_19 -> V_34 . V_40 = 0xff ;
V_19 -> V_34 . V_41 = 0xff ;
V_28 -= 1024 ;
V_31 += 1024 ;
}
V_19 -> V_34 . V_42 = F_12 ( V_29 ) ;
V_19 -> V_34 . V_43 = F_12 ( V_30 ) ;
V_6 = F_6 ( V_8 -> V_10 , V_19 , V_29 ) ;
if ( V_6 < 0 )
return V_6 ;
memcpy ( V_27 -> V_32 + V_31 , V_19 , V_29 ) ;
if ( V_30 > 0 ) {
V_6 = F_6 ( V_8 -> V_10 , V_19 , V_30 ) ;
if ( V_6 < 0 )
return V_6 ;
memcpy ( V_27 -> V_32 + V_31 + 512 , V_19 , V_30 ) ;
}
}
return 0 ;
}
static int F_13 ( struct V_7 * V_8 , struct V_26 * V_27 )
{
int V_6 , V_20 ;
T_1 V_28 , V_5 ,
V_31 = 0x0000 ;
struct V_44 * V_45 =
(struct V_44 * ) V_8 -> V_32 ;
V_28 = V_27 -> V_33 ;
V_45 -> V_34 . V_35 = V_46 ;
V_45 -> V_34 . V_47 = 0x00 ;
V_45 -> V_34 . V_48 = 0x00 ;
V_45 -> V_34 . V_49 = 0x0000 ;
while ( V_28 > 0 ) {
V_45 -> V_34 . V_37 = F_12 ( V_31 + 0x4000 ) ;
if ( V_28 > 503 ) {
V_45 -> V_34 . V_29 = 0xff ;
V_45 -> V_34 . V_30 = 0xf8 ;
V_28 -= 503 ;
V_5 = 503 + sizeof( struct V_50 ) ;
V_31 += 503 ;
} else if ( V_28 > 255 ) {
V_45 -> V_34 . V_29 = 0xff ;
V_45 -> V_34 . V_30 = ( V_28 - 255 ) ;
V_5 = V_28 +
sizeof( struct V_50 ) ;
V_28 = 0 ;
} else {
V_45 -> V_34 . V_29 = V_28 ;
V_45 -> V_34 . V_30 = 0x00 ;
V_5 = V_28 +
sizeof( struct V_50 ) ;
V_28 = 0 ;
}
memcpy ( V_45 -> V_51 , V_27 -> V_32 + V_31 ,
V_5 - sizeof( struct V_50 ) ) ;
V_6 = F_7 ( V_8 -> V_10 ,
F_8 ( V_8 -> V_10 ,
V_21 ) , V_45 ,
V_5 , & V_20 , V_13 ) ;
if ( ( V_6 < 0 ) || ( V_5 != V_20 ) )
return - V_15 ;
}
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_26 * V_52 ,
int V_53 )
{
struct V_26 * V_54 ;
int V_55 , V_6 ,
error = 0 ;
struct V_7 * V_8 = (struct V_7 * ) V_2 -> V_9 ;
struct V_24 * V_25 =
(struct V_24 * ) V_8 -> V_32 ;
struct F_1 * V_56 = (struct F_1 * ) V_8 -> V_32 ;
F_5 ( & V_2 -> V_14 , L_6 , V_53 ) ;
for ( V_55 = 0 ; V_55 < V_53 ; V_55 ++ ) {
V_54 = & V_52 [ V_55 ] ;
F_5 ( & V_2 -> V_14 ,
L_7 ,
V_55 , V_54 -> V_57 & V_58 ? L_8 : L_9 ,
V_54 -> V_57 , V_54 -> V_33 , V_54 -> V_37 ) ;
if ( V_54 -> V_33 > 2048 )
return - V_59 ;
F_15 ( & V_8 -> V_60 ) ;
if ( V_54 -> V_57 & V_58 ) {
V_25 -> V_35 = V_61 ;
V_25 -> V_62 = 0x00 ;
V_25 -> V_63 = 0x00 ;
V_25 -> V_37 = V_54 -> V_37 ;
V_25 -> V_64 = 0x01 ;
V_25 -> V_33 = F_12 ( V_54 -> V_33 ) ;
V_6 = F_10 ( V_8 -> V_10 , V_25 ) ;
if ( V_6 < 0 )
error = V_6 ;
V_6 = F_11 ( V_8 , V_54 ) ;
if ( V_6 < 0 )
error = V_6 ;
V_6 = F_1 ( V_2 , V_56 , error ) ;
if ( V_6 < 0 )
error = V_6 ;
if ( error < 0 )
goto error;
} else {
V_6 = F_13 ( V_8 , V_54 ) ;
V_25 -> V_35 = V_61 ;
V_25 -> V_62 = 0x00 ;
V_25 -> V_63 = 0x00 ;
V_25 -> V_37 = V_54 -> V_37 ;
V_25 -> V_64 = 0x00 ;
V_25 -> V_33 = F_12 ( V_54 -> V_33 ) ;
V_6 = F_10 ( V_8 -> V_10 , V_25 ) ;
if ( V_6 < 0 )
error = V_6 ;
V_6 = F_1 ( V_2 , V_56 , error ) ;
if ( V_6 < 0 )
error = V_6 ;
if ( error < 0 )
goto error;
}
F_16 ( & V_8 -> V_60 ) ;
}
return 0 ;
error:
F_16 ( & V_8 -> V_60 ) ;
return error ;
}
static T_2 F_17 ( struct V_1 * V_2 )
{
return V_65 | V_66 ;
}
static int F_18 ( struct V_67 * V_68 )
{
struct V_7 * V_8 = F_19 ( V_68 -> V_14 . V_69 ) ;
struct V_70 * V_71 ;
int V_6 ;
int V_72 ;
V_71 = F_20 ( & V_68 -> V_14 , sizeof( * V_71 ) , V_73 ) ;
if ( V_71 == NULL )
return - V_74 ;
V_71 -> V_2 . V_75 = V_76 ;
V_71 -> V_2 . V_77 = V_78 ;
V_71 -> V_2 . V_79 = & V_80 ;
V_71 -> V_2 . V_9 = V_8 ;
V_71 -> V_81 = V_82 ;
snprintf ( V_71 -> V_2 . V_83 , sizeof( V_71 -> V_2 . V_83 ) ,
L_10 ,
V_8 -> V_10 -> V_84 -> V_85 , V_8 -> V_10 -> V_86 ) ;
if ( ( V_82 <= V_87 )
&& ( V_82 >= V_88 ) ) {
V_72 = F_21 ( V_8 -> V_10 , 0 ) ;
V_6 = F_2 ( V_8 -> V_10 , V_72 ,
V_89 , V_90 ,
0x0000 , 0x0000 , & V_71 -> V_81 , 1 ,
V_13 ) ;
if ( V_6 != 1 ) {
F_4 ( & V_68 -> V_14 ,
L_11 , V_91 ) ;
return - V_92 ;
}
} else {
F_4 ( & V_68 -> V_14 ,
L_12 , V_91 ) ;
return - V_92 ;
}
V_71 -> V_2 . V_14 . V_69 = & V_68 -> V_14 ;
F_22 ( & V_71 -> V_2 ) ;
F_23 ( V_68 , V_71 ) ;
return 0 ;
}
static int F_24 ( struct V_67 * V_68 )
{
struct V_70 * V_71 = F_25 ( V_68 ) ;
F_26 ( & V_71 -> V_2 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
switch ( V_91 ) {
case 6000 :
V_82 = V_88 ;
break;
case 3000 :
V_82 = V_93 ;
break;
case 1000 :
V_82 = V_94 ;
break;
case 400 :
V_82 = V_95 ;
break;
case 200 :
V_82 = V_96 ;
break;
case 100 :
V_82 = V_97 ;
break;
case 10 :
V_82 = V_87 ;
break;
default:
F_28 ( L_13 , V_91 ) ;
V_82 = V_97 ;
}
return F_29 ( & V_98 ) ;
}
static void T_4 F_30 ( void )
{
F_31 ( & V_98 ) ;
}
