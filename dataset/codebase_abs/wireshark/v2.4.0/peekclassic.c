T_1 F_1 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 )
{
T_4 V_4 ;
T_5 V_5 ;
int V_6 ;
T_6 * V_7 ;
F_2 ( sizeof( V_4 . V_8 ) == V_9 ) ;
if ( ! F_3 ( V_1 -> V_10 , & V_4 . V_8 ,
( int ) sizeof( V_4 . V_8 ) , V_2 , V_3 ) ) {
if ( * V_2 != V_11 )
return V_12 ;
return V_13 ;
}
V_4 . V_8 . V_14 &= ~ 0x80 ;
switch ( V_4 . V_8 . V_14 ) {
case 5 :
case 6 :
case 7 :
F_2 ( sizeof( V_4 . V_15 . V_16 ) ==
V_17 ) ;
if ( ! F_3 ( V_1 -> V_10 , & V_4 . V_15 . V_16 ,
( int ) sizeof( V_4 . V_15 . V_16 ) , V_2 , V_3 ) ) {
if ( * V_2 != V_11 )
return V_12 ;
return V_13 ;
}
if ( ( 0 != V_4 . V_15 . V_16 . V_18 [ 0 ] ) ||
( 0 != V_4 . V_15 . V_16 . V_18 [ 1 ] ) ||
( 0 != V_4 . V_15 . V_16 . V_18 [ 2 ] ) ) {
return V_13 ;
}
V_4 . V_15 . V_16 . V_19 =
F_4 ( V_4 . V_15 . V_16 . V_19 ) ;
V_4 . V_15 . V_16 . V_20 =
F_4 ( V_4 . V_15 . V_16 . V_20 ) ;
switch ( V_4 . V_15 . V_16 . V_20 ) {
case 0 :
switch ( V_4 . V_15 . V_16 . V_19 ) {
case 0 :
V_6 = V_21 ;
break;
case 1 :
V_6 = V_22 ;
break;
default:
return V_13 ;
}
break;
case 1 :
switch ( V_4 . V_15 . V_16 . V_19 ) {
case 0 :
V_6 = V_23 ;
break;
default:
return V_13 ;
}
break;
default:
return V_13 ;
}
V_4 . V_15 . V_16 . V_24 =
F_4 ( V_4 . V_15 . V_16 . V_24 ) ;
V_4 . V_15 . V_16 . V_25 =
F_4 ( V_4 . V_15 . V_16 . V_25 ) ;
V_4 . V_15 . V_16 . V_26 =
F_4 ( V_4 . V_15 . V_16 . V_26 ) ;
V_4 . V_15 . V_16 . V_27 =
F_4 ( V_4 . V_15 . V_16 . V_27 ) ;
V_4 . V_15 . V_16 . V_28 =
F_4 ( V_4 . V_15 . V_16 . V_28 ) ;
V_4 . V_15 . V_16 . V_29 =
F_4 ( V_4 . V_15 . V_16 . V_29 ) ;
V_4 . V_15 . V_16 . V_30 =
F_4 ( V_4 . V_15 . V_16 . V_30 ) ;
V_5 = V_4 . V_15 . V_16 . V_26 - V_31 ;
break;
default:
return V_13 ;
}
V_7 = ( T_6 * ) F_5 ( sizeof( T_6 ) ) ;
V_1 -> V_32 = ( void * ) V_7 ;
V_7 -> V_5 = V_5 ;
switch ( V_4 . V_8 . V_14 ) {
case 5 :
case 6 :
V_1 -> V_33 = V_34 ;
V_1 -> V_6 = V_35 ;
V_1 -> V_36 = V_37 ;
V_1 -> V_38 = V_39 ;
break;
case 7 :
V_1 -> V_33 = V_40 ;
V_1 -> V_6 = V_6 ;
V_1 -> V_36 = V_41 ;
V_1 -> V_38 = V_42 ;
break;
default:
F_6 () ;
}
V_1 -> V_43 = 0 ;
V_1 -> V_44 = V_45 ;
return V_46 ;
}
static T_7 V_41 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_8 * V_47 )
{
int V_48 ;
* V_47 = F_7 ( V_1 -> V_10 ) ;
V_48 = F_8 ( V_1 , V_1 -> V_10 , & V_1 -> V_49 ,
V_1 -> V_50 , V_2 , V_3 ) ;
if ( V_48 < 0 )
return FALSE ;
if ( ( V_51 ) V_48 > V_1 -> V_49 . V_52 ) {
if ( ! F_3 ( V_1 -> V_10 , NULL , V_48 - V_1 -> V_49 . V_52 ,
V_2 , V_3 ) )
return FALSE ;
}
if ( V_48 & 0x01 ) {
if ( ! F_3 ( V_1 -> V_10 , NULL , 1 , V_2 , V_3 ) )
return FALSE ;
}
return TRUE ;
}
static T_7 V_42 ( T_2 * V_1 , T_8 V_53 ,
struct V_54 * V_49 , T_9 * V_55 , int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_56 , V_53 , V_57 , V_2 ) == - 1 )
return FALSE ;
if ( F_8 ( V_1 , V_1 -> V_56 , V_49 , V_55 ,
V_2 , V_3 ) == - 1 ) {
if ( * V_2 == 0 )
* V_2 = V_11 ;
return FALSE ;
}
return TRUE ;
}
static int F_8 ( T_2 * V_1 , T_10 V_10 ,
struct V_54 * V_49 , T_9 * V_55 , int * V_2 , T_3 * * V_3 )
{
T_11 V_58 [ V_59 ] ;
#if 0
guint16 protoNum;
#endif
T_12 V_60 ;
T_12 V_48 ;
#if 0
guint8 flags;
#endif
T_11 V_61 ;
T_13 V_62 ;
T_5 V_63 ;
V_51 V_64 ;
T_11 V_65 [ V_66 ] ;
if ( ! F_10 ( V_10 , V_58 , sizeof( V_58 ) , V_2 , V_3 ) )
return - 1 ;
#if 0
protoNum = pntoh16(&ep_pkt[PEEKCLASSIC_V7_PROTONUM_OFFSET]);
#endif
V_60 = F_11 ( & V_58 [ V_67 ] ) ;
V_48 = F_11 ( & V_58 [ V_68 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V7_FLAGS_OFFSET];
#endif
V_61 = V_58 [ V_69 ] ;
V_62 = F_12 ( & V_58 [ V_70 ] ) ;
if ( 0 == V_48 ) {
V_48 = V_60 ;
}
V_49 -> V_71 = V_72 ;
V_49 -> V_73 = V_74 | V_75 ;
V_63 = ( T_5 ) ( V_62 / 1000000 ) ;
V_64 = ( V_51 ) ( V_62 - V_63 * 1000000 ) ;
V_49 -> V_76 . V_77 = V_63 - V_31 ;
V_49 -> V_76 . V_78 = V_64 * 1000 ;
V_49 -> V_79 = V_60 ;
V_49 -> V_52 = V_48 ;
switch ( V_1 -> V_6 ) {
case V_23 :
memset ( & V_49 -> V_80 . V_81 , 0 , sizeof( V_49 -> V_80 . V_81 ) ) ;
V_49 -> V_80 . V_81 . V_82 = 0 ;
V_49 -> V_80 . V_81 . V_83 = FALSE ;
V_49 -> V_80 . V_81 . V_84 = FALSE ;
V_49 -> V_80 . V_81 . V_85 = V_86 ;
if ( V_49 -> V_79 < V_66 || V_49 -> V_52 < V_66 ) {
* V_2 = V_87 ;
* V_3 = F_13 ( L_1 ) ;
return - 1 ;
}
V_49 -> V_79 -= V_66 ;
V_49 -> V_52 -= V_66 ;
V_48 -= V_66 ;
if ( ! F_3 ( V_10 , V_65 , V_66 , V_2 , V_3 ) )
return - 1 ;
V_49 -> V_80 . V_81 . V_88 = TRUE ;
V_49 -> V_80 . V_81 . V_89 = V_65 [ 0 ] ;
V_49 -> V_80 . V_81 . V_90 = TRUE ;
V_49 -> V_80 . V_81 . V_91 = V_65 [ 1 ] ;
V_49 -> V_80 . V_81 . V_92 = TRUE ;
V_49 -> V_80 . V_81 . V_93 = V_65 [ 2 ] ;
if ( V_49 -> V_79 < 4 || V_49 -> V_52 < 4 ) {
* V_2 = V_87 ;
* V_3 = F_13 ( L_2 ) ;
return - 1 ;
}
V_49 -> V_79 -= 4 ;
V_49 -> V_52 -= 4 ;
break;
case V_21 :
V_49 -> V_80 . V_94 . V_82 = ( V_61 & 0x01 ) ? 0 : 4 ;
break;
}
if ( ! F_14 ( V_10 , V_55 , V_49 -> V_52 , V_2 , V_3 ) )
return - 1 ;
return V_48 ;
}
static T_7 V_37 ( T_2 * V_1 , int * V_2 , T_3 * * V_3 ,
T_8 * V_47 )
{
* V_47 = F_7 ( V_1 -> V_10 ) ;
if ( ! F_15 ( V_1 , V_1 -> V_10 , & V_1 -> V_49 ,
V_1 -> V_50 , V_2 , V_3 ) )
return FALSE ;
return TRUE ;
}
static T_7 V_39 ( T_2 * V_1 , T_8 V_53 ,
struct V_54 * V_49 , T_9 * V_55 , int * V_2 , T_3 * * V_3 )
{
if ( F_9 ( V_1 -> V_56 , V_53 , V_57 , V_2 ) == - 1 )
return FALSE ;
if ( ! F_15 ( V_1 , V_1 -> V_56 , V_49 , V_55 ,
V_2 , V_3 ) ) {
if ( * V_2 == 0 )
* V_2 = V_11 ;
return FALSE ;
}
return TRUE ;
}
static T_7 F_15 ( T_2 * V_1 , T_10 V_10 ,
struct V_54 * V_49 , T_9 * V_55 , int * V_2 , T_3 * * V_3 )
{
T_6 * V_7 = ( T_6 * ) V_1 -> V_32 ;
T_11 V_58 [ V_95 ] ;
T_12 V_60 ;
T_12 V_48 ;
#if 0
guint8 flags;
guint8 status;
#endif
V_51 V_62 ;
#if 0
guint16 destNum;
guint16 srcNum;
#endif
T_12 V_96 ;
#if 0
char protoStr[8];
#endif
unsigned int V_97 ;
if ( ! F_10 ( V_10 , V_58 , sizeof( V_58 ) , V_2 , V_3 ) )
return FALSE ;
V_60 = F_11 ( & V_58 [ V_98 ] ) ;
V_48 = F_11 ( & V_58 [ V_99 ] ) ;
#if 0
flags = ep_pkt[PEEKCLASSIC_V56_FLAGS_OFFSET];
status = ep_pkt[PEEKCLASSIC_V56_STATUS_OFFSET];
#endif
V_62 = F_16 ( & V_58 [ V_100 ] ) ;
#if 0
destNum = pntoh16(&ep_pkt[PEEKCLASSIC_V56_DESTNUM_OFFSET]);
srcNum = pntoh16(&ep_pkt[PEEKCLASSIC_V56_SRCNUM_OFFSET]);
#endif
V_96 = F_11 ( & V_58 [ V_101 ] ) ;
#if 0
memcpy(protoStr, &ep_pkt[PEEKCLASSIC_V56_PROTOSTR_OFFSET],
sizeof protoStr);
#endif
if ( 0 == V_48 ) {
V_48 = V_60 ;
}
V_49 -> V_71 = V_72 ;
V_49 -> V_73 = V_74 | V_75 ;
V_49 -> V_76 . V_77 = V_7 -> V_5 + ( V_62 / 1000 ) ;
V_49 -> V_76 . V_78 = 1000 * ( V_62 % 1000 ) * 1000 ;
V_49 -> V_79 = V_60 ;
V_49 -> V_52 = V_48 ;
V_49 -> V_102 = V_103 ;
for ( V_97 = 0 ; V_97 < V_104 ; V_97 ++ ) {
if ( V_105 [ V_97 ] . V_96 == V_96 ) {
V_49 -> V_102 = V_105 [ V_97 ] . V_106 ;
}
}
switch ( V_49 -> V_102 ) {
case V_21 :
V_49 -> V_80 . V_94 . V_82 = 0 ;
break;
}
return F_14 ( V_10 , V_55 , V_48 , V_2 , V_3 ) ;
}
