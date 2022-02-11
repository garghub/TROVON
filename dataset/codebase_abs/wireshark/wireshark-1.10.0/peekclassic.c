int
F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
int V_5 ;
struct V_6 V_7 ;
int V_8 ;
T_4 * V_9 ;
F_2 ( sizeof( V_4 . V_10 ) == V_11 ) ;
V_5 = F_3 ( & V_4 . V_10 , ( int ) sizeof( V_4 . V_10 ) ,
V_1 -> V_12 ) ;
if ( V_5 != sizeof( V_4 . V_10 ) ) {
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
V_4 . V_10 . V_14 &= ~ 0x80 ;
switch ( V_4 . V_10 . V_14 ) {
case 5 :
case 6 :
case 7 :
F_2 ( sizeof( V_4 . V_15 . V_16 ) ==
V_17 ) ;
V_5 = F_3 ( & V_4 . V_15 . V_16 ,
( int ) sizeof( V_4 . V_15 . V_16 ) , V_1 -> V_12 ) ;
if ( V_5 != sizeof( V_4 . V_15 . V_16 ) ) {
* V_2 = F_4 ( V_1 -> V_12 , V_3 ) ;
if ( * V_2 != 0 && * V_2 != V_13 )
return - 1 ;
return 0 ;
}
if ( ( 0 != V_4 . V_15 . V_16 . V_18 [ 0 ] ) ||
( 0 != V_4 . V_15 . V_16 . V_18 [ 1 ] ) ||
( 0 != V_4 . V_15 . V_16 . V_18 [ 2 ] ) ) {
return 0 ;
}
V_4 . V_15 . V_16 . V_19 =
F_5 ( V_4 . V_15 . V_16 . V_19 ) ;
V_4 . V_15 . V_16 . V_20 =
F_5 ( V_4 . V_15 . V_16 . V_20 ) ;
switch ( V_4 . V_15 . V_16 . V_20 ) {
case 0 :
switch ( V_4 . V_15 . V_16 . V_19 ) {
case 0 :
V_8 = V_21 ;
break;
case 1 :
V_8 = V_22 ;
break;
default:
return 0 ;
}
break;
case 1 :
switch ( V_4 . V_15 . V_16 . V_19 ) {
case 0 :
V_8 = V_23 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
V_4 . V_15 . V_16 . V_24 =
F_5 ( V_4 . V_15 . V_16 . V_24 ) ;
V_4 . V_15 . V_16 . V_25 =
F_5 ( V_4 . V_15 . V_16 . V_25 ) ;
V_4 . V_15 . V_16 . V_26 =
F_5 ( V_4 . V_15 . V_16 . V_26 ) ;
V_4 . V_15 . V_16 . V_27 =
F_5 ( V_4 . V_15 . V_16 . V_27 ) ;
V_4 . V_15 . V_16 . V_28 =
F_5 ( V_4 . V_15 . V_16 . V_28 ) ;
V_4 . V_15 . V_16 . V_29 =
F_5 ( V_4 . V_15 . V_16 . V_29 ) ;
V_4 . V_15 . V_16 . V_30 =
F_5 ( V_4 . V_15 . V_16 . V_30 ) ;
V_7 . V_31 =
V_4 . V_15 . V_16 . V_26 - V_32 ;
V_7 . V_33 = 0 ;
break;
default:
return 0 ;
}
V_9 = ( T_4 * ) F_6 ( sizeof( T_4 ) ) ;
V_1 -> V_34 = ( void * ) V_9 ;
V_9 -> V_7 = V_7 ;
switch ( V_4 . V_10 . V_14 ) {
case 5 :
case 6 :
V_1 -> V_35 = V_36 ;
V_1 -> V_8 = V_37 ;
V_1 -> V_38 = V_39 ;
V_1 -> V_40 = V_41 ;
break;
case 7 :
V_1 -> V_35 = V_42 ;
V_1 -> V_8 = V_8 ;
V_1 -> V_38 = V_43 ;
V_1 -> V_40 = V_44 ;
break;
default:
F_7 () ;
}
V_1 -> V_45 = 0 ;
V_1 -> V_46 = V_47 ;
return 1 ;
}
static T_5
V_43 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 * V_48 )
{
T_7 V_49 [ V_50 ] ;
#if 0
guint16 protoNum;
#endif
T_8 V_51 ;
T_8 V_52 ;
#if 0
guint8 flags;
#endif
T_7 V_53 ;
T_9 V_54 ;
T_10 V_55 ;
T_11 V_56 ;
* V_48 = F_8 ( V_1 -> V_12 ) ;
F_9 ( V_49 , sizeof( V_49 ) , V_1 -> V_12 , V_2 ,
V_3 ) ;
#if 0
protoNum = pntohs(&ep_pkt[PEEKCLASSIC_V7_PROTONUM_OFFSET]);
#endif
V_51 = F_10 ( & V_49 [ V_57 ] ) ;
V_52 = F_10 ( & V_49 [ V_58 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V7_FLAGS_OFFSET];
#endif
V_53 = V_49 [ V_59 ] ;
V_54 = F_11 ( & V_49 [ V_60 ] ) ;
if ( 0 == V_52 ) {
V_52 = V_51 ;
}
V_1 -> V_61 . V_62 = V_63 | V_64 ;
V_1 -> V_61 . V_65 = V_51 ;
V_1 -> V_61 . V_66 = V_52 ;
if ( V_52 % 2 )
V_52 ++ ;
switch ( V_1 -> V_8 ) {
case V_23 :
V_1 -> V_61 . V_67 . V_68 . V_69 = 0 ;
V_1 -> V_61 . V_67 . V_68 . V_70 = FALSE ;
break;
case V_21 :
V_1 -> V_61 . V_67 . V_71 . V_69 = ( V_53 & 0x01 ) ? 0 : 4 ;
break;
}
F_12 ( V_1 -> V_72 , V_52 ) ;
F_9 ( F_13 ( V_1 -> V_72 ) ,
V_52 , V_1 -> V_12 , V_2 , V_3 ) ;
V_55 = ( T_10 ) ( V_54 / 1000000 ) ;
V_56 = ( T_11 ) ( V_54 - V_55 * 1000000 ) ;
V_1 -> V_61 . V_73 . V_74 = V_55 - V_32 ;
V_1 -> V_61 . V_73 . V_75 = V_56 * 1000 ;
if ( V_1 -> V_8 == V_23 ) {
V_1 -> V_61 . V_65 -= 4 ;
V_1 -> V_61 . V_66 -= 4 ;
}
return TRUE ;
}
static T_5
V_44 ( T_1 * V_1 , T_6 V_76 ,
struct V_77 * V_61 , T_7 * V_78 , int V_51 ,
int * V_2 , T_2 * * V_3 )
{
union V_79 * V_67 = & V_61 -> V_67 ;
T_7 V_49 [ V_50 ] ;
T_7 V_53 ;
if ( F_14 ( V_1 -> V_80 , V_76 , V_81 , V_2 ) == - 1 )
return FALSE ;
F_9 ( V_49 , sizeof( V_49 ) , V_1 -> V_80 ,
V_2 , V_3 ) ;
V_53 = V_49 [ V_59 ] ;
switch ( V_1 -> V_8 ) {
case V_23 :
V_67 -> V_68 . V_69 = 0 ;
V_67 -> V_68 . V_70 = FALSE ;
break;
case V_21 :
V_67 -> V_71 . V_69 = ( V_53 & 0x01 ) ? 0 : 4 ;
break;
}
V_82 = V_83 ;
F_9 ( V_78 , V_51 , V_1 -> V_80 , V_2 ,
V_3 ) ;
return TRUE ;
}
static T_5
V_39 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 , T_6 * V_48 )
{
T_4 * V_9 = ( T_4 * ) V_1 -> V_34 ;
T_7 V_49 [ V_84 ] ;
T_8 V_51 ;
T_8 V_52 ;
#if 0
guint8 flags;
guint8 status;
#endif
T_11 V_54 ;
#if 0
guint16 destNum;
guint16 srcNum;
#endif
T_8 V_85 ;
char V_86 [ 8 ] ;
unsigned int V_87 ;
* V_48 = F_8 ( V_1 -> V_12 ) ;
F_9 ( V_49 , sizeof( V_49 ) , V_1 -> V_12 , V_2 ,
V_3 ) ;
V_51 = F_10 ( & V_49 [ V_88 ] ) ;
V_52 = F_10 ( & V_49 [ V_89 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V56_FLAGS_OFFSET];
status = ep_pkt[PEEKCLASSIC_V56_STATUS_OFFSET];
#endif
V_54 = F_15 ( & V_49 [ V_90 ] ) ;
#if 0
destNum = pntohs(&ep_pkt[PEEKCLASSIC_V56_DESTNUM_OFFSET]);
srcNum = pntohs(&ep_pkt[PEEKCLASSIC_V56_SRCNUM_OFFSET]);
#endif
V_85 = F_10 ( & V_49 [ V_91 ] ) ;
memcpy ( V_86 , & V_49 [ V_92 ] ,
sizeof V_86 ) ;
if ( 0 == V_52 ) {
V_52 = V_51 ;
}
F_12 ( V_1 -> V_72 , V_52 ) ;
F_9 ( F_13 ( V_1 -> V_72 ) ,
V_52 , V_1 -> V_12 , V_2 , V_3 ) ;
V_1 -> V_61 . V_65 = V_51 ;
V_1 -> V_61 . V_66 = V_52 ;
V_1 -> V_61 . V_73 . V_74 = V_9 -> V_7 . V_31
+ ( V_54 / 1000 ) ;
V_1 -> V_61 . V_73 . V_75 = 1000 * ( V_54 % 1000 ) * 1000 ;
V_1 -> V_61 . V_93 = V_94 ;
for ( V_87 = 0 ; V_87 < V_95 ; V_87 ++ ) {
if ( V_96 [ V_87 ] . V_85 == V_85 ) {
V_1 -> V_61 . V_93 = V_96 [ V_87 ] . V_97 ;
}
}
switch ( V_1 -> V_61 . V_93 ) {
case V_21 :
V_1 -> V_61 . V_67 . V_71 . V_69 = 0 ;
break;
}
return TRUE ;
}
static T_5
V_41 ( T_1 * V_1 , T_6 V_76 ,
struct V_77 * V_61 , T_7 * V_78 , int V_51 ,
int * V_2 , T_2 * * V_3 )
{
union V_79 * V_67 = & V_61 -> V_67 ;
T_7 V_49 [ V_84 ] ;
int V_93 ;
T_8 V_85 ;
unsigned int V_87 ;
if ( F_14 ( V_1 -> V_80 , V_76 , V_81 , V_2 ) == - 1 )
return FALSE ;
F_9 ( V_49 , sizeof( V_49 ) , V_1 -> V_80 ,
V_2 , V_3 ) ;
V_85 = F_10 ( & V_49 [ V_91 ] ) ;
V_93 = V_94 ;
for ( V_87 = 0 ; V_87 < V_95 ; V_87 ++ ) {
if ( V_96 [ V_87 ] . V_85 == V_85 ) {
V_93 = V_96 [ V_87 ] . V_97 ;
}
}
switch ( V_93 ) {
case V_21 :
V_67 -> V_71 . V_69 = 0 ;
break;
}
V_82 = V_83 ;
F_9 ( V_78 , V_51 , V_1 -> V_80 , V_2 ,
V_3 ) ;
return TRUE ;
}
