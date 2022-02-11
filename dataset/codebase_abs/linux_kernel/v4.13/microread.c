static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_6 ( V_4 -> V_7 ) ;
}
static void F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 -> V_8 ( V_4 -> V_7 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
int V_9 ;
T_1 V_10 [ 4 ] ;
V_10 [ 0 ] = 0x03 ;
V_9 = F_5 ( V_2 , V_11 ,
V_12 , V_10 , 1 , NULL ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_2 , V_13 ,
V_12 , NULL , 0 , NULL ) ;
if ( V_9 )
return V_9 ;
V_10 [ 0 ] = 0x00 ;
V_10 [ 1 ] = 0x03 ;
V_10 [ 2 ] = 0x00 ;
V_9 = F_5 ( V_2 , V_14 ,
V_12 , V_10 , 3 , NULL ) ;
if ( V_9 )
return V_9 ;
V_9 = F_5 ( V_2 , V_15 ,
V_12 , NULL , 0 , NULL ) ;
if ( V_9 )
return V_9 ;
V_10 [ 0 ] = 0xFF ;
V_10 [ 1 ] = 0xFF ;
V_10 [ 2 ] = 0x00 ;
V_10 [ 3 ] = 0x00 ;
V_9 = F_5 ( V_2 , V_16 ,
V_12 , V_10 , 4 , NULL ) ;
return V_9 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return V_4 -> V_5 -> V_19 ( V_4 -> V_7 , V_18 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
T_2 V_20 , T_2 V_21 )
{
int V_9 ;
T_1 V_10 [ 2 ] ;
T_1 V_22 ;
V_10 [ 0 ] = 0x00 ;
V_10 [ 1 ] = 0x00 ;
if ( V_20 & V_23 )
V_10 [ 0 ] |= ( 1 << 2 ) ;
if ( V_20 & V_24 )
V_10 [ 0 ] |= 1 ;
if ( V_20 & V_25 )
V_10 [ 1 ] |= 1 ;
if ( V_20 & V_26 )
V_10 [ 0 ] |= ( 1 << 1 ) ;
if ( V_20 & V_27 )
V_10 [ 0 ] |= ( 1 << 5 ) ;
if ( V_20 & V_28 )
V_10 [ 1 ] |= ( 1 << 1 ) ;
if ( ( V_20 | V_21 ) & V_28 ) {
V_2 -> V_29 = F_8 ( V_2 -> V_30 ,
& V_2 -> V_31 ) ;
if ( V_2 -> V_29 == NULL || V_2 -> V_31 == 0 ) {
V_20 &= ~ V_28 ;
V_21 &= ~ V_28 ;
}
}
V_9 = F_9 ( V_2 , V_11 ,
V_32 , NULL , 0 ) ;
if ( V_9 )
return V_9 ;
V_22 = 0xff ;
V_9 = F_10 ( V_2 , V_33 ,
V_34 , & V_22 , 1 ) ;
if ( V_9 )
return V_9 ;
if ( V_20 & V_28 ) {
V_9 = F_10 ( V_2 , V_35 ,
V_36 ,
V_2 -> V_29 , V_2 -> V_31 ) ;
if ( V_9 )
return V_9 ;
}
if ( V_21 & V_28 ) {
V_9 = F_10 ( V_2 , V_33 ,
V_37 ,
V_2 -> V_29 , V_2 -> V_31 ) ;
if ( V_9 )
return V_9 ;
V_22 = 0x02 ;
V_9 = F_10 ( V_2 , V_33 ,
V_34 , & V_22 , 1 ) ;
if ( V_9 )
return V_9 ;
}
return F_9 ( V_2 , V_11 ,
V_38 ,
V_10 , 2 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_39 * V_40 , T_1 V_41 ,
T_1 * V_29 , T_3 V_31 )
{
struct V_17 * V_42 = NULL ;
int V_9 ;
V_9 = F_12 ( V_2 , V_40 -> V_43 ,
V_44 , & V_42 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_42 -> V_45 == 0 || V_42 -> V_45 > V_46 ) {
V_9 = - V_47 ;
goto exit;
}
V_9 = F_13 ( V_2 -> V_30 , V_42 -> V_48 ,
V_42 -> V_45 ) ;
if ( V_9 == 0 )
V_9 = F_14 ( V_2 -> V_30 , V_40 -> V_49 , V_41 ,
V_50 ) ;
exit:
F_15 ( V_42 ) ;
return V_9 ;
}
static int F_16 ( struct V_1 * V_2 )
{
return F_9 ( V_2 , V_35 ,
V_32 , NULL , 0 ) ;
}
static int F_17 ( struct V_1 * V_2 , T_1 V_51 ,
struct V_39 * V_40 )
{
switch ( V_51 ) {
case V_35 :
V_40 -> V_52 = V_28 ;
break;
default:
return - V_47 ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_2 ,
T_1 V_51 ,
struct V_39 * V_40 )
{
return 0 ;
}
static void F_19 ( void * V_53 , struct V_17 * V_18 ,
int V_54 )
{
struct V_3 * V_4 = V_53 ;
switch ( V_4 -> V_55 ) {
case V_56 :
if ( V_54 == 0 ) {
if ( V_18 -> V_45 == 0 ) {
V_54 = - V_47 ;
F_15 ( V_18 ) ;
V_4 -> V_57 ( V_4 -> V_58 , NULL ,
- V_47 ) ;
return;
}
if ( V_18 -> V_48 [ V_18 -> V_45 - 1 ] != 0 ) {
V_54 = F_20 (
V_18 -> V_48 [ V_18 -> V_45 - 1 ] ) ;
F_15 ( V_18 ) ;
V_4 -> V_57 ( V_4 -> V_58 , NULL ,
V_54 ) ;
return;
}
F_21 ( V_18 , V_18 -> V_45 - 1 ) ;
}
V_4 -> V_57 ( V_4 -> V_58 , V_18 , V_54 ) ;
break;
default:
if ( V_54 == 0 )
F_15 ( V_18 ) ;
break;
}
}
static int F_22 ( struct V_1 * V_2 ,
struct V_39 * V_40 ,
struct V_17 * V_18 , T_4 V_59 ,
void * V_60 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_61 ;
T_5 V_62 ;
F_23 ( L_1 , V_40 -> V_43 ) ;
if ( V_40 -> V_43 == V_35 ) {
* ( T_1 * ) F_24 ( V_18 , 1 ) = 0 ;
return F_9 ( V_2 , V_40 -> V_43 ,
V_63 ,
V_18 -> V_48 , V_18 -> V_45 ) ;
}
switch ( V_40 -> V_43 ) {
case V_11 :
V_61 = 0xCB ;
break;
case V_13 :
V_61 = 0xCB ;
break;
case V_14 :
V_61 = 0xCB ;
break;
case V_15 :
V_61 = 0x1B ;
V_62 = F_25 ( 0xffff , V_18 -> V_48 , V_18 -> V_45 ) ;
V_62 = ~ V_62 ;
F_26 ( V_18 , V_62 & 0xff ) ;
F_26 ( V_18 , V_62 >> 8 ) ;
break;
case V_16 :
V_61 = 0xDB ;
break;
default:
F_23 ( L_2 ,
V_40 -> V_43 ) ;
return 1 ;
}
* ( T_1 * ) F_24 ( V_18 , 1 ) = V_61 ;
V_4 -> V_55 = V_56 ;
V_4 -> V_57 = V_59 ;
V_4 -> V_58 = V_60 ;
return F_27 ( V_2 , V_40 -> V_43 ,
V_64 ,
V_18 -> V_48 , V_18 -> V_45 ,
F_19 , V_4 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_17 * V_18 )
{
int V_9 ;
V_9 = F_9 ( V_2 , V_33 ,
V_65 ,
V_18 -> V_48 , V_18 -> V_45 ) ;
F_15 ( V_18 ) ;
return V_9 ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_51 ,
struct V_17 * V_18 )
{
struct V_39 * V_66 ;
int V_9 = 0 ;
F_23 ( L_3 , V_51 ) ;
V_66 = F_30 ( sizeof( struct V_39 ) , V_67 ) ;
if ( V_66 == NULL ) {
V_9 = - V_68 ;
goto exit;
}
V_66 -> V_43 = V_51 ;
switch ( V_51 ) {
case V_11 :
V_66 -> V_52 =
F_31 ( V_18 -> V_48 [ V_69 ] ) ;
V_66 -> V_70 =
F_32 ( * ( T_5 * ) & V_18 -> V_48 [ V_71 ] ) ;
V_66 -> V_72 = V_18 -> V_48 [ V_69 ] ;
V_66 -> V_73 = V_18 -> V_48 [ V_74 ] ;
if ( V_66 -> V_73 > sizeof( V_66 -> V_75 ) ) {
V_9 = - V_76 ;
goto V_77;
}
memcpy ( V_66 -> V_75 , & V_18 -> V_48 [ V_78 ] ,
V_66 -> V_73 ) ;
break;
case V_13 :
V_66 -> V_52 =
F_31 ( V_18 -> V_48 [ V_79 ] ) ;
V_66 -> V_70 =
F_32 ( * ( T_5 * ) & V_18 -> V_48 [ V_80 ] ) ;
V_66 -> V_72 = V_18 -> V_48 [ V_79 ] ;
V_66 -> V_73 = V_18 -> V_48 [ V_81 ] ;
if ( V_66 -> V_73 > sizeof( V_66 -> V_75 ) ) {
V_9 = - V_76 ;
goto V_77;
}
memcpy ( V_66 -> V_75 , & V_18 -> V_48 [ V_82 ] ,
V_66 -> V_73 ) ;
break;
case V_14 :
V_66 -> V_52 = V_24 ;
memcpy ( V_66 -> V_75 , & V_18 -> V_48 [ V_83 ] , 4 ) ;
V_66 -> V_73 = 4 ;
break;
case V_15 :
V_66 -> V_52 = V_26 ;
V_66 -> V_70 =
F_33 ( * ( T_5 * ) & V_18 -> V_48 [ V_84 ] ) ;
memcpy ( V_66 -> V_75 , & V_18 -> V_48 [ V_85 ] , 4 ) ;
V_66 -> V_73 = 4 ;
break;
case V_16 :
V_66 -> V_52 = V_27 ;
memcpy ( V_66 -> V_75 , & V_18 -> V_48 [ V_86 ] , 8 ) ;
V_66 -> V_73 = 8 ;
break;
default:
F_23 ( L_4 , V_51 ) ;
goto V_77;
}
V_9 = F_34 ( V_2 -> V_30 , V_66 , 1 ) ;
V_77:
F_35 ( V_66 ) ;
exit:
F_15 ( V_18 ) ;
if ( V_9 )
F_36 ( L_5 , V_9 ) ;
}
static int F_37 ( struct V_1 * V_2 , T_1 V_87 ,
T_1 V_88 , struct V_17 * V_18 )
{
int V_9 ;
T_1 V_51 = V_2 -> V_89 [ V_87 ] . V_51 ;
T_1 V_22 ;
F_23 ( L_6 , V_88 , V_51 ) ;
switch ( V_88 ) {
case V_90 :
F_29 ( V_2 , V_51 , V_18 ) ;
return 0 ;
case V_91 :
if ( V_18 -> V_45 < 1 ) {
F_15 ( V_18 ) ;
return - V_47 ;
}
if ( V_18 -> V_48 [ V_18 -> V_45 - 1 ] ) {
F_15 ( V_18 ) ;
return - V_92 ;
}
F_21 ( V_18 , V_18 -> V_45 - 1 ) ;
V_9 = F_38 ( V_2 -> V_30 , V_18 ) ;
break;
case V_93 :
case V_94 :
F_15 ( V_18 ) ;
return 0 ;
case V_95 :
V_9 = F_39 ( V_2 -> V_30 , V_28 ,
V_96 , V_18 -> V_48 ,
V_18 -> V_45 ) ;
F_15 ( V_18 ) ;
break;
case V_65 :
if ( V_18 -> V_45 < 1 ) {
F_15 ( V_18 ) ;
return - V_47 ;
}
if ( V_18 -> V_48 [ V_18 -> V_45 - 1 ] ) {
F_15 ( V_18 ) ;
return - V_92 ;
}
F_21 ( V_18 , V_18 -> V_45 - 1 ) ;
V_9 = F_38 ( V_2 -> V_30 , V_18 ) ;
break;
case V_97 :
F_15 ( V_18 ) ;
V_22 = 0xff ;
V_9 = F_10 ( V_2 , V_33 ,
V_34 , & V_22 , 1 ) ;
if ( V_9 )
break;
V_9 = F_9 ( V_2 , V_51 ,
V_32 , NULL ,
0 ) ;
break;
default:
return 1 ;
}
return V_9 ;
}
int F_40 ( void * V_7 , struct V_98 * V_5 , char * V_99 ,
int V_100 , int V_101 , int V_102 ,
struct V_1 * * V_2 )
{
struct V_3 * V_4 ;
unsigned long V_103 = 0 ;
T_2 V_104 ;
struct V_105 V_106 ;
int V_9 ;
V_4 = F_30 ( sizeof( struct V_3 ) , V_67 ) ;
if ( ! V_4 ) {
V_9 = - V_68 ;
goto V_107;
}
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_106 . V_108 = F_41 ( V_109 ) ;
memcpy ( V_106 . V_110 , V_109 , sizeof( V_109 ) ) ;
strcpy ( V_106 . V_111 , L_7 ) ;
F_42 ( V_112 , & V_103 ) ;
V_104 = V_26 |
V_25 |
V_27 |
V_23 |
V_24 |
V_28 ;
V_4 -> V_2 = F_43 ( & V_113 , & V_106 ,
V_103 , V_104 , V_99 ,
V_100 +
V_114 ,
V_101 +
V_115 ,
V_102 ) ;
if ( ! V_4 -> V_2 ) {
F_36 ( L_8 ) ;
V_9 = - V_68 ;
goto V_116;
}
F_44 ( V_4 -> V_2 , V_4 ) ;
V_9 = F_45 ( V_4 -> V_2 ) ;
if ( V_9 )
goto V_117;
* V_2 = V_4 -> V_2 ;
return 0 ;
V_117:
F_46 ( V_4 -> V_2 ) ;
V_116:
F_35 ( V_4 ) ;
V_107:
return V_9 ;
}
void F_47 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_48 ( V_2 ) ;
F_46 ( V_2 ) ;
F_35 ( V_4 ) ;
}
