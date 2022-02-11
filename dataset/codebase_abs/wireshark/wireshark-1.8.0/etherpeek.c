int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
struct V_5 V_6 ;
int V_7 ;
T_4 * V_8 ;
F_2 ( sizeof( V_4 . V_9 ) == V_10 ) ;
F_3 (
& V_4 . V_9 , sizeof( V_4 . V_9 ) , V_1 -> V_11 , V_2 , V_3 ) ;
V_4 . V_9 . V_12 &= ~ 0x80 ;
switch ( V_4 . V_9 . V_12 ) {
case 5 :
case 6 :
case 7 :
F_2 ( sizeof( V_4 . V_13 . V_14 ) ==
V_15 ) ;
F_3 (
& V_4 . V_13 . V_14 ,
sizeof( V_4 . V_13 . V_14 ) , V_1 -> V_11 , V_2 , V_3 ) ;
if ( ( 0 != V_4 . V_13 . V_14 . V_16 [ 0 ] ) ||
( 0 != V_4 . V_13 . V_14 . V_16 [ 1 ] ) ||
( 0 != V_4 . V_13 . V_14 . V_16 [ 2 ] ) ) {
return 0 ;
}
V_4 . V_13 . V_14 . V_17 =
F_4 ( V_4 . V_13 . V_14 . V_17 ) ;
V_4 . V_13 . V_14 . V_18 =
F_4 ( V_4 . V_13 . V_14 . V_18 ) ;
switch ( V_4 . V_13 . V_14 . V_18 ) {
case 0 :
switch ( V_4 . V_13 . V_14 . V_17 ) {
case 0 :
V_7 = V_19 ;
break;
case 1 :
V_7 = V_20 ;
break;
default:
return 0 ;
}
break;
case 1 :
switch ( V_4 . V_13 . V_14 . V_17 ) {
case 0 :
V_7 = V_21 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
V_4 . V_13 . V_14 . V_22 =
F_4 ( V_4 . V_13 . V_14 . V_22 ) ;
V_4 . V_13 . V_14 . V_23 =
F_4 ( V_4 . V_13 . V_14 . V_23 ) ;
V_4 . V_13 . V_14 . V_24 =
F_4 ( V_4 . V_13 . V_14 . V_24 ) ;
V_4 . V_13 . V_14 . V_25 =
F_4 ( V_4 . V_13 . V_14 . V_25 ) ;
V_4 . V_13 . V_14 . V_26 =
F_4 ( V_4 . V_13 . V_14 . V_26 ) ;
V_4 . V_13 . V_14 . V_27 =
F_4 ( V_4 . V_13 . V_14 . V_27 ) ;
V_4 . V_13 . V_14 . V_28 =
F_4 ( V_4 . V_13 . V_14 . V_28 ) ;
V_6 . V_29 =
V_4 . V_13 . V_14 . V_24 - V_30 ;
V_6 . V_31 = 0 ;
break;
default:
return 0 ;
}
V_8 = ( T_4 * ) F_5 ( sizeof( T_4 ) ) ;
V_1 -> V_32 = ( void * ) V_8 ;
V_8 -> V_6 = V_6 ;
switch ( V_4 . V_9 . V_12 ) {
case 5 :
case 6 :
V_1 -> V_33 = V_34 ;
V_1 -> V_7 = V_35 ;
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = V_39 ;
break;
case 7 :
V_1 -> V_33 = V_40 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_36 = V_41 ;
V_1 -> V_38 = V_42 ;
break;
default:
F_6 () ;
}
V_1 -> V_43 = 0 ;
V_1 -> V_44 = V_45 ;
return 1 ;
}
static T_5 V_41 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_46 )
{
T_7 V_47 [ V_48 ] ;
#if 0
guint16 protoNum;
#endif
T_8 V_49 ;
T_8 V_50 ;
#if 0
guint8 flags;
#endif
T_7 V_51 ;
T_9 V_52 ;
T_10 V_53 ;
T_11 V_54 ;
* V_46 = F_7 ( V_1 -> V_11 ) ;
F_8 ( V_47 , sizeof( V_47 ) , V_1 -> V_11 , V_2 ,
V_3 ) ;
#if 0
protoNum = pntohs(&ep_pkt[ETHERPEEK_V7_PROTONUM_OFFSET]);
#endif
V_49 = F_9 ( & V_47 [ V_55 ] ) ;
V_50 = F_9 ( & V_47 [ V_56 ] ) ;
#if 0
flags = ep_pkt[ETHERPEEK_V7_FLAGS_OFFSET];
#endif
V_51 = V_47 [ V_57 ] ;
V_52 = F_10 ( & V_47 [ V_58 ] ) ;
if ( 0 == V_50 ) {
V_50 = V_49 ;
}
V_1 -> V_59 . V_60 = V_61 | V_62 ;
V_1 -> V_59 . V_63 = V_49 ;
V_1 -> V_59 . V_64 = V_50 ;
if ( V_50 % 2 )
V_50 ++ ;
switch ( V_1 -> V_7 ) {
case V_21 :
V_1 -> V_65 . V_66 . V_67 = 0 ;
break;
case V_19 :
V_1 -> V_65 . V_68 . V_67 = ( V_51 & 0x01 ) ? 0 : 4 ;
break;
}
F_11 ( V_1 -> V_69 , V_50 ) ;
F_8 ( F_12 ( V_1 -> V_69 ) ,
V_50 , V_1 -> V_11 , V_2 , V_3 ) ;
V_53 = ( T_10 ) ( V_52 / 1000000 ) ;
V_54 = ( T_11 ) ( V_52 - V_53 * 1000000 ) ;
V_1 -> V_59 . V_70 . V_71 = V_53 - V_30 ;
V_1 -> V_59 . V_70 . V_72 = V_54 * 1000 ;
if ( V_1 -> V_7 == V_21 ) {
V_1 -> V_59 . V_63 -= 4 ;
V_1 -> V_59 . V_64 -= 4 ;
}
return TRUE ;
}
static T_5
V_42 ( T_1 * V_1 , T_6 V_73 ,
union V_74 * V_65 , T_7 * V_75 , int V_49 ,
int * V_2 , T_2 * * V_3 )
{
T_7 V_47 [ V_48 ] ;
T_7 V_51 ;
if ( F_13 ( V_1 -> V_76 , V_73 , V_77 , V_2 ) == - 1 )
return FALSE ;
F_8 ( V_47 , sizeof( V_47 ) , V_1 -> V_76 ,
V_2 , V_3 ) ;
V_51 = V_47 [ V_57 ] ;
switch ( V_1 -> V_7 ) {
case V_21 :
V_65 -> V_66 . V_67 = 0 ;
break;
case V_19 :
V_65 -> V_68 . V_67 = ( V_51 & 0x01 ) ? 0 : 4 ;
break;
}
V_78 = V_79 ;
F_8 ( V_75 , V_49 , V_1 -> V_76 , V_2 ,
V_3 ) ;
return TRUE ;
}
static T_5 V_37 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_46 )
{
T_4 * V_8 = ( T_4 * ) V_1 -> V_32 ;
T_7 V_47 [ V_80 ] ;
T_8 V_49 ;
T_8 V_50 ;
#if 0
guint8 flags;
guint8 status;
#endif
T_11 V_52 ;
#if 0
guint16 destNum;
guint16 srcNum;
#endif
T_8 V_81 ;
char V_82 [ 8 ] ;
unsigned int V_83 ;
* V_46 = F_7 ( V_1 -> V_11 ) ;
F_8 ( V_47 , sizeof( V_47 ) , V_1 -> V_11 , V_2 ,
V_3 ) ;
V_49 = F_9 ( & V_47 [ V_84 ] ) ;
V_50 = F_9 ( & V_47 [ V_85 ] ) ;
#if 0
flags = ep_pkt[ETHERPEEK_V56_FLAGS_OFFSET];
status = ep_pkt[ETHERPEEK_V56_STATUS_OFFSET];
#endif
V_52 = F_14 ( & V_47 [ V_86 ] ) ;
#if 0
destNum = pntohs(&ep_pkt[ETHERPEEK_V56_DESTNUM_OFFSET]);
srcNum = pntohs(&ep_pkt[ETHERPEEK_V56_SRCNUM_OFFSET]);
#endif
V_81 = F_9 ( & V_47 [ V_87 ] ) ;
memcpy ( V_82 , & V_47 [ V_88 ] ,
sizeof V_82 ) ;
if ( 0 == V_50 ) {
V_50 = V_49 ;
}
F_11 ( V_1 -> V_69 , V_50 ) ;
F_8 ( F_12 ( V_1 -> V_69 ) ,
V_50 , V_1 -> V_11 , V_2 , V_3 ) ;
V_1 -> V_59 . V_63 = V_49 ;
V_1 -> V_59 . V_64 = V_50 ;
V_1 -> V_59 . V_70 . V_71 = V_8 -> V_6 . V_29
+ ( V_52 / 1000 ) ;
V_1 -> V_59 . V_70 . V_72 = 1000 * ( V_52 % 1000 ) * 1000 ;
V_1 -> V_59 . V_89 = V_90 ;
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
if ( V_92 [ V_83 ] . V_81 == V_81 ) {
V_1 -> V_59 . V_89 = V_92 [ V_83 ] . V_93 ;
}
}
switch ( V_1 -> V_59 . V_89 ) {
case V_19 :
V_1 -> V_65 . V_68 . V_67 = 0 ;
break;
}
return TRUE ;
}
static T_5
V_39 ( T_1 * V_1 , T_6 V_73 ,
union V_74 * V_65 , T_7 * V_75 , int V_49 ,
int * V_2 , T_2 * * V_3 )
{
T_7 V_47 [ V_80 ] ;
int V_89 ;
T_8 V_81 ;
unsigned int V_83 ;
if ( F_13 ( V_1 -> V_76 , V_73 , V_77 , V_2 ) == - 1 )
return FALSE ;
F_8 ( V_47 , sizeof( V_47 ) , V_1 -> V_76 ,
V_2 , V_3 ) ;
V_81 = F_9 ( & V_47 [ V_87 ] ) ;
V_89 = V_90 ;
for ( V_83 = 0 ; V_83 < V_91 ; V_83 ++ ) {
if ( V_92 [ V_83 ] . V_81 == V_81 ) {
V_89 = V_92 [ V_83 ] . V_93 ;
}
}
switch ( V_89 ) {
case V_19 :
V_65 -> V_68 . V_67 = 0 ;
break;
}
V_78 = V_79 ;
F_8 ( V_75 , V_49 , V_1 -> V_76 , V_2 ,
V_3 ) ;
return TRUE ;
}
