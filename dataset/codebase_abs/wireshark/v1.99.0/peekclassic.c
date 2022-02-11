int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
{
T_3 V_4 ;
struct V_5 V_6 ;
int V_7 ;
T_4 * V_8 ;
F_2 ( sizeof( V_4 . V_9 ) == V_10 ) ;
if ( ! F_3 ( V_1 -> V_11 , & V_4 . V_9 ,
( int ) sizeof( V_4 . V_9 ) , V_2 , V_3 ) ) {
if ( * V_2 != V_12 )
return - 1 ;
return 0 ;
}
V_4 . V_9 . V_13 &= ~ 0x80 ;
switch ( V_4 . V_9 . V_13 ) {
case 5 :
case 6 :
case 7 :
F_2 ( sizeof( V_4 . V_14 . V_15 ) ==
V_16 ) ;
if ( ! F_3 ( V_1 -> V_11 , & V_4 . V_14 . V_15 ,
( int ) sizeof( V_4 . V_14 . V_15 ) , V_2 , V_3 ) ) {
if ( * V_2 == V_12 ) {
return 0 ;
}
return - 1 ;
}
if ( ( 0 != V_4 . V_14 . V_15 . V_17 [ 0 ] ) ||
( 0 != V_4 . V_14 . V_15 . V_17 [ 1 ] ) ||
( 0 != V_4 . V_14 . V_15 . V_17 [ 2 ] ) ) {
return 0 ;
}
V_4 . V_14 . V_15 . V_18 =
F_4 ( V_4 . V_14 . V_15 . V_18 ) ;
V_4 . V_14 . V_15 . V_19 =
F_4 ( V_4 . V_14 . V_15 . V_19 ) ;
switch ( V_4 . V_14 . V_15 . V_19 ) {
case 0 :
switch ( V_4 . V_14 . V_15 . V_18 ) {
case 0 :
V_7 = V_20 ;
break;
case 1 :
V_7 = V_21 ;
break;
default:
return 0 ;
}
break;
case 1 :
switch ( V_4 . V_14 . V_15 . V_18 ) {
case 0 :
V_7 = V_22 ;
break;
default:
return 0 ;
}
break;
default:
return 0 ;
}
V_4 . V_14 . V_15 . V_23 =
F_4 ( V_4 . V_14 . V_15 . V_23 ) ;
V_4 . V_14 . V_15 . V_24 =
F_4 ( V_4 . V_14 . V_15 . V_24 ) ;
V_4 . V_14 . V_15 . V_25 =
F_4 ( V_4 . V_14 . V_15 . V_25 ) ;
V_4 . V_14 . V_15 . V_26 =
F_4 ( V_4 . V_14 . V_15 . V_26 ) ;
V_4 . V_14 . V_15 . V_27 =
F_4 ( V_4 . V_14 . V_15 . V_27 ) ;
V_4 . V_14 . V_15 . V_28 =
F_4 ( V_4 . V_14 . V_15 . V_28 ) ;
V_4 . V_14 . V_15 . V_29 =
F_4 ( V_4 . V_14 . V_15 . V_29 ) ;
V_6 . V_30 =
V_4 . V_14 . V_15 . V_25 - V_31 ;
V_6 . V_32 = 0 ;
break;
default:
return 0 ;
}
V_8 = ( T_4 * ) F_5 ( sizeof( T_4 ) ) ;
V_1 -> V_33 = ( void * ) V_8 ;
V_8 -> V_6 = V_6 ;
switch ( V_4 . V_9 . V_13 ) {
case 5 :
case 6 :
V_1 -> V_34 = V_35 ;
V_1 -> V_7 = V_36 ;
V_1 -> V_37 = V_38 ;
V_1 -> V_39 = V_40 ;
break;
case 7 :
V_1 -> V_34 = V_41 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_37 = V_42 ;
V_1 -> V_39 = V_43 ;
break;
default:
F_6 () ;
}
V_1 -> V_44 = 0 ;
V_1 -> V_45 = V_46 ;
return 1 ;
}
static T_5 V_42 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_47 )
{
int V_48 ;
* V_47 = F_7 ( V_1 -> V_11 ) ;
V_48 = F_8 ( V_1 , V_1 -> V_11 , & V_1 -> V_49 ,
V_1 -> V_50 , V_2 , V_3 ) ;
if ( V_48 < 0 )
return FALSE ;
if ( ( V_51 ) V_48 > V_1 -> V_49 . V_52 ) {
if ( ! F_9 ( V_1 -> V_11 , V_48 - V_1 -> V_49 . V_52 , V_2 ) )
return FALSE ;
}
if ( V_48 & 0x01 ) {
if ( ! F_9 ( V_1 -> V_11 , 1 , V_2 ) )
return FALSE ;
}
return TRUE ;
}
static T_5 V_43 ( T_1 * V_1 , T_6 V_53 ,
struct V_54 * V_49 , T_7 * V_55 , int * V_2 , T_2 * * V_3 )
{
if ( F_10 ( V_1 -> V_56 , V_53 , V_57 , V_2 ) == - 1 )
return FALSE ;
if ( F_8 ( V_1 , V_1 -> V_56 , V_49 , V_55 ,
V_2 , V_3 ) == - 1 ) {
if ( * V_2 == 0 )
* V_2 = V_12 ;
return FALSE ;
}
return TRUE ;
}
static int F_8 ( T_1 * V_1 , T_8 V_11 ,
struct V_54 * V_49 , T_7 * V_55 , int * V_2 , T_2 * * V_3 )
{
T_9 V_58 [ V_59 ] ;
#if 0
guint16 protoNum;
#endif
T_10 V_60 ;
T_10 V_48 ;
#if 0
guint8 flags;
#endif
T_9 V_61 ;
T_11 V_62 ;
T_12 V_63 ;
V_51 V_64 ;
if ( ! F_11 ( V_11 , V_58 , sizeof( V_58 ) , V_2 , V_3 ) )
return - 1 ;
#if 0
protoNum = pntoh16(&ep_pkt[PEEKCLASSIC_V7_PROTONUM_OFFSET]);
#endif
V_60 = F_12 ( & V_58 [ V_65 ] ) ;
V_48 = F_12 ( & V_58 [ V_66 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V7_FLAGS_OFFSET];
#endif
V_61 = V_58 [ V_67 ] ;
V_62 = F_13 ( & V_58 [ V_68 ] ) ;
if ( 0 == V_48 ) {
V_48 = V_60 ;
}
V_49 -> V_69 = V_70 ;
V_49 -> V_71 = V_72 | V_73 ;
V_63 = ( T_12 ) ( V_62 / 1000000 ) ;
V_64 = ( V_51 ) ( V_62 - V_63 * 1000000 ) ;
V_49 -> V_74 . V_75 = V_63 - V_31 ;
V_49 -> V_74 . V_76 = V_64 * 1000 ;
V_49 -> V_77 = V_60 ;
V_49 -> V_52 = V_48 ;
switch ( V_1 -> V_7 ) {
case V_22 :
V_49 -> V_78 . V_79 . V_80 = 0 ;
V_49 -> V_78 . V_79 . V_81 = FALSE ;
if ( V_49 -> V_77 < 4 || V_49 -> V_52 < 4 ) {
* V_2 = V_82 ;
* V_3 = F_14 ( L_1 ) ;
return - 1 ;
}
V_49 -> V_77 -= 4 ;
V_49 -> V_52 -= 4 ;
break;
case V_20 :
V_49 -> V_78 . V_83 . V_80 = ( V_61 & 0x01 ) ? 0 : 4 ;
break;
}
if ( ! F_15 ( V_11 , V_55 , V_49 -> V_52 , V_2 , V_3 ) )
return - 1 ;
return V_48 ;
}
static T_5 V_38 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_47 )
{
* V_47 = F_7 ( V_1 -> V_11 ) ;
if ( ! F_16 ( V_1 , V_1 -> V_11 , & V_1 -> V_49 ,
V_1 -> V_50 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
static T_5 V_40 ( T_1 * V_1 , T_6 V_53 ,
struct V_54 * V_49 , T_7 * V_55 , int * V_2 , T_2 * * V_3 )
{
if ( F_10 ( V_1 -> V_56 , V_53 , V_57 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_16 ( V_1 , V_1 -> V_56 , V_49 , V_55 ,
V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_12 ;
return FALSE ;
}
return TRUE ;
}
static T_5 F_16 ( T_1 * V_1 , T_8 V_11 ,
struct V_54 * V_49 , T_7 * V_55 , int * V_2 , T_2 * * V_3 )
{
T_4 * V_8 = ( T_4 * ) V_1 -> V_33 ;
T_9 V_58 [ V_84 ] ;
T_10 V_60 ;
T_10 V_48 ;
#if 0
guint8 flags;
guint8 status;
#endif
V_51 V_62 ;
#if 0
guint16 destNum;
guint16 srcNum;
#endif
T_10 V_85 ;
#if 0
char protoStr[8];
#endif
unsigned int V_86 ;
if ( ! F_11 ( V_11 , V_58 , sizeof( V_58 ) , V_2 , V_3 ) )
return FALSE ;
V_60 = F_12 ( & V_58 [ V_87 ] ) ;
V_48 = F_12 ( & V_58 [ V_88 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V56_FLAGS_OFFSET];
status = ep_pkt[PEEKCLASSIC_V56_STATUS_OFFSET];
#endif
V_62 = F_17 ( & V_58 [ V_89 ] ) ;
#if 0
destNum = pntoh16(&ep_pkt[PEEKCLASSIC_V56_DESTNUM_OFFSET]);
srcNum = pntoh16(&ep_pkt[PEEKCLASSIC_V56_SRCNUM_OFFSET]);
#endif
V_85 = F_12 ( & V_58 [ V_90 ] ) ;
#if 0
memcpy(protoStr, &ep_pkt[PEEKCLASSIC_V56_PROTOSTR_OFFSET],
sizeof protoStr);
#endif
if ( 0 == V_48 ) {
V_48 = V_60 ;
}
V_49 -> V_69 = V_70 ;
V_49 -> V_71 = V_72 | V_73 ;
V_49 -> V_74 . V_75 = V_8 -> V_6 . V_30
+ ( V_62 / 1000 ) ;
V_49 -> V_74 . V_76 = 1000 * ( V_62 % 1000 ) * 1000 ;
V_49 -> V_77 = V_60 ;
V_49 -> V_52 = V_48 ;
V_49 -> V_91 = V_92 ;
for ( V_86 = 0 ; V_86 < V_93 ; V_86 ++ ) {
if ( V_94 [ V_86 ] . V_85 == V_85 ) {
V_49 -> V_91 = V_94 [ V_86 ] . V_95 ;
}
}
switch ( V_49 -> V_91 ) {
case V_20 :
V_49 -> V_78 . V_83 . V_80 = 0 ;
break;
}
return F_15 ( V_11 , V_55 , V_48 , V_2 , V_3 ) ;
}
