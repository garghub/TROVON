int F_1 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 )
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
static T_5 V_43 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_48 )
{
int V_49 ;
* V_48 = F_8 ( V_1 -> V_12 ) ;
V_49 = F_9 ( V_1 , V_1 -> V_12 , & V_1 -> V_50 ,
V_1 -> V_51 , V_2 , V_3 ) ;
if ( V_49 < 0 )
return FALSE ;
if ( ( V_52 ) V_49 > V_1 -> V_50 . V_53 ) {
if ( ! F_10 ( V_1 -> V_12 , V_49 - V_1 -> V_50 . V_53 , V_2 ) )
return FALSE ;
}
if ( V_49 & 0x01 ) {
if ( ! F_10 ( V_1 -> V_12 , 1 , V_2 ) )
return FALSE ;
}
return TRUE ;
}
static T_5 V_44 ( T_1 * V_1 , T_6 V_54 ,
struct V_55 * V_50 , T_7 * V_56 , int T_8 V_57 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_11 ( V_1 -> V_58 , V_54 , V_59 , V_2 ) == - 1 )
return FALSE ;
if ( F_9 ( V_1 , V_1 -> V_58 , V_50 , V_56 ,
V_2 , V_3 ) == - 1 ) {
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
return TRUE ;
}
static int F_9 ( T_1 * V_1 , T_9 V_12 ,
struct V_55 * V_50 , T_7 * V_56 , int * V_2 , T_2 * * V_3 )
{
T_10 V_60 [ V_61 ] ;
int V_5 ;
#if 0
guint16 protoNum;
#endif
T_11 T_8 ;
T_11 V_49 ;
#if 0
guint8 flags;
#endif
T_10 V_62 ;
T_12 V_63 ;
T_13 V_64 ;
V_52 V_65 ;
V_5 = F_3 ( V_60 , sizeof( V_60 ) , V_12 ) ;
if ( V_5 != ( int ) sizeof( V_60 ) ) {
* V_2 = F_4 ( V_12 , V_3 ) ;
if ( * V_2 == 0 && V_5 > 0 )
* V_2 = V_13 ;
return - 1 ;
}
#if 0
protoNum = pntohs(&ep_pkt[PEEKCLASSIC_V7_PROTONUM_OFFSET]);
#endif
T_8 = F_12 ( & V_60 [ V_66 ] ) ;
V_49 = F_12 ( & V_60 [ V_67 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V7_FLAGS_OFFSET];
#endif
V_62 = V_60 [ V_68 ] ;
V_63 = F_13 ( & V_60 [ V_69 ] ) ;
if ( 0 == V_49 ) {
V_49 = T_8 ;
}
V_50 -> V_70 = V_71 | V_72 ;
V_64 = ( T_13 ) ( V_63 / 1000000 ) ;
V_65 = ( V_52 ) ( V_63 - V_64 * 1000000 ) ;
V_50 -> V_73 . V_74 = V_64 - V_32 ;
V_50 -> V_73 . V_75 = V_65 * 1000 ;
V_50 -> V_76 = T_8 ;
V_50 -> V_53 = V_49 ;
switch ( V_1 -> V_8 ) {
case V_23 :
V_50 -> V_77 . V_78 . V_79 = 0 ;
V_50 -> V_77 . V_78 . V_80 = FALSE ;
if ( V_50 -> V_76 < 4 || V_50 -> V_53 < 4 ) {
* V_2 = V_81 ;
* V_3 = F_14 ( L_1 ) ;
return - 1 ;
}
V_50 -> V_76 -= 4 ;
V_50 -> V_53 -= 4 ;
break;
case V_21 :
V_50 -> V_77 . V_82 . V_79 = ( V_62 & 0x01 ) ? 0 : 4 ;
break;
}
if ( ! F_15 ( V_12 , V_56 , V_50 -> V_53 , V_2 , V_3 ) )
return - 1 ;
return V_49 ;
}
static T_5 V_39 ( T_1 * V_1 , int * V_2 , T_2 * * V_3 ,
T_6 * V_48 )
{
* V_48 = F_8 ( V_1 -> V_12 ) ;
if ( ! F_16 ( V_1 , V_1 -> V_12 , & V_1 -> V_50 ,
V_1 -> V_51 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
static T_5 V_41 ( T_1 * V_1 , T_6 V_54 ,
struct V_55 * V_50 , T_7 * V_56 , int T_8 V_57 ,
int * V_2 , T_2 * * V_3 )
{
if ( F_11 ( V_1 -> V_58 , V_54 , V_59 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_16 ( V_1 , V_1 -> V_58 , V_50 , V_56 ,
V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_13 ;
return FALSE ;
}
return TRUE ;
}
static T_5 F_16 ( T_1 * V_1 , T_9 V_12 ,
struct V_55 * V_50 , T_7 * V_56 , int * V_2 , T_2 * * V_3 )
{
T_4 * V_9 = ( T_4 * ) V_1 -> V_34 ;
T_10 V_60 [ V_83 ] ;
T_11 T_8 ;
T_11 V_49 ;
#if 0
guint8 flags;
guint8 status;
#endif
V_52 V_63 ;
#if 0
guint16 destNum;
guint16 srcNum;
#endif
T_11 V_84 ;
#if 0
char protoStr[8];
#endif
unsigned int V_85 ;
F_17 ( V_60 , sizeof( V_60 ) , V_12 , V_2 ,
V_3 ) ;
T_8 = F_12 ( & V_60 [ V_86 ] ) ;
V_49 = F_12 ( & V_60 [ V_87 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V56_FLAGS_OFFSET];
status = ep_pkt[PEEKCLASSIC_V56_STATUS_OFFSET];
#endif
V_63 = F_18 ( & V_60 [ V_88 ] ) ;
#if 0
destNum = pntohs(&ep_pkt[PEEKCLASSIC_V56_DESTNUM_OFFSET]);
srcNum = pntohs(&ep_pkt[PEEKCLASSIC_V56_SRCNUM_OFFSET]);
#endif
V_84 = F_12 ( & V_60 [ V_89 ] ) ;
#if 0
memcpy(protoStr, &ep_pkt[PEEKCLASSIC_V56_PROTOSTR_OFFSET],
sizeof protoStr);
#endif
if ( 0 == V_49 ) {
V_49 = T_8 ;
}
V_50 -> V_70 = V_71 | V_72 ;
V_50 -> V_73 . V_74 = V_9 -> V_7 . V_31
+ ( V_63 / 1000 ) ;
V_50 -> V_73 . V_75 = 1000 * ( V_63 % 1000 ) * 1000 ;
V_50 -> V_76 = T_8 ;
V_50 -> V_53 = V_49 ;
V_50 -> V_90 = V_91 ;
for ( V_85 = 0 ; V_85 < V_92 ; V_85 ++ ) {
if ( V_93 [ V_85 ] . V_84 == V_84 ) {
V_50 -> V_90 = V_93 [ V_85 ] . V_94 ;
}
}
switch ( V_50 -> V_90 ) {
case V_21 :
V_50 -> V_77 . V_82 . V_79 = 0 ;
break;
}
return F_15 ( V_12 , V_56 , V_49 , V_2 , V_3 ) ;
}
