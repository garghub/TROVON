int F_1 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_5 ;
if ( 1 != F_2 ( V_2 -> V_6 , & V_5 , 1 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
F_3 ( L_2 , V_5 ) ;
if ( V_5 == 0xff )
return 0 ;
if ( V_5 == 0xfe )
return 1 ;
* V_3 = V_5 ;
* V_4 = V_5 ;
return 1 ;
}
int F_4 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_8 [ 2 ] ;
T_2 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 -> V_6 , V_8 , sizeof( V_8 ) ) ;
if ( V_10 != 2 )
return - V_7 ;
if ( V_8 [ 1 ] == 0xff )
return 0 ;
V_2 -> V_11 = V_8 [ 1 ] ;
V_9 =
( ( V_8 [ 0 ] & 0x01 ) ? 0x0020 : 0 ) |
( ( V_8 [ 0 ] & 0x02 ) ? 0x0010 : 0 ) |
( ( V_8 [ 0 ] & 0x04 ) ? 0x0008 : 0 ) |
( ( V_8 [ 0 ] & 0x08 ) ? 0x0004 : 0 ) |
( ( V_8 [ 0 ] & 0x10 ) ? 0x0002 : 0 ) |
( ( V_8 [ 0 ] & 0x20 ) ? 0x0001 : 0 ) |
( ( V_8 [ 1 ] & 0x08 ) ? 0x1000 : 0 ) |
( ( V_8 [ 1 ] & 0x10 ) ? 0x0800 : 0 ) |
( ( V_8 [ 1 ] & 0x20 ) ? 0x0400 : 0 ) |
( ( V_8 [ 1 ] & 0x40 ) ? 0x0200 : 0 ) |
( ( V_8 [ 1 ] & 0x80 ) ? 0x0100 : 0 ) ;
F_3 ( L_3 ,
V_9 , V_8 [ 1 ] , V_8 [ 0 ] ) ;
* V_3 = V_9 ;
* V_4 = V_9 ;
return 1 ;
}
int F_5 ( struct V_1 * V_2 , T_1 * V_3 ,
T_1 * V_4 )
{
unsigned char V_8 [ 3 ] ;
if ( 3 != F_2 ( V_2 -> V_6 , V_8 , 3 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
F_3 ( L_2 , V_8 [ 2 ] & 0x3f ) ;
if ( V_8 [ 0 ] != 0x00 )
return 0 ;
* V_3 = V_8 [ 2 ] & 0x3f ;
* V_4 = V_8 [ 2 ] & 0x3f ;
return 1 ;
}
int F_6 ( struct V_1 * V_2 , T_1 * V_3 , T_1 * V_4 )
{
unsigned char V_12 , V_13 , V_14 ;
struct V_15 V_16 [] = { { . V_17 = V_2 -> V_6 -> V_17 , . V_18 = 0 , . V_8 = & V_12 , . V_19 = 1 } ,
{ . V_17 = V_2 -> V_6 -> V_17 , . V_18 = V_20 , . V_8 = & V_13 , . V_19 = 1 } } ;
V_12 = 0x10 ;
if ( 2 != F_7 ( V_2 -> V_6 -> V_21 , V_16 , 2 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
if ( V_13 == 0x00 )
return 0 ;
V_12 = 0x00 ;
V_16 [ 1 ] . V_8 = & V_14 ;
if ( 2 != F_7 ( V_2 -> V_6 -> V_21 , V_16 , 2 ) ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
if ( V_14 == 0x00 )
return 0 ;
* V_3 = V_14 ;
* V_4 = V_14 ;
return 1 ;
}
static int F_8 ( struct V_22 * V_2 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_27 ;
T_3 V_16 [ 3 ] = { 0 , 0 , 0 } ;
V_27 = V_26 -> V_28 ( V_26 , 0 , V_29 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_27 < 0 )
return V_27 ;
V_24 -> V_30 = ( V_16 [ 0 ] >> 7 ) ;
V_24 -> V_31 = ( V_16 [ 0 ] & 0x7f ) ;
V_24 -> V_32 = V_16 [ 1 ] ;
V_24 -> V_33 [ 0 ] = V_16 [ 2 ] ;
return 0 ;
}
static int F_9 ( struct V_22 * V_2 ,
struct V_23 * V_24 )
{
struct V_25 * V_26 = V_2 -> V_26 ;
int V_27 ;
T_3 V_16 [ 5 ] = { 0 , 0 , 0 , 0 , 0 } ;
V_27 = V_26 -> V_28 ( V_26 , 0 , V_34 ,
V_16 , sizeof( V_16 ) ) ;
if ( V_27 < 0 )
return V_27 ;
V_24 -> V_30 = ( V_16 [ 0 ] >> 7 ) ;
V_24 -> V_31 = ( V_16 [ 0 ] & 0x7f ) ;
V_24 -> V_32 = V_16 [ 1 ] ;
V_24 -> V_33 [ 0 ] = V_16 [ 2 ] ;
V_24 -> V_33 [ 1 ] = V_16 [ 3 ] ;
V_24 -> V_33 [ 2 ] = V_16 [ 4 ] ;
return 0 ;
}
static void F_10 ( struct V_22 * V_2 )
{
int V_35 ;
struct V_23 V_24 ;
V_35 = V_2 -> V_36 ( V_2 , & V_24 ) ;
if ( F_11 ( V_35 < 0 ) ) {
F_12 ( L_4 , V_35 ) ;
return;
}
if ( F_11 ( V_24 . V_31 != V_2 -> V_37 ) ) {
F_12 ( L_5 , V_38 ,
V_24 . V_30 , V_24 . V_31 ,
V_24 . V_32 , V_24 . V_33 [ 0 ] ) ;
if ( V_2 -> V_39 )
F_13 ( V_2 -> V_27 ,
V_24 . V_32 << 8 |
V_24 . V_33 [ 0 ] ,
V_24 . V_30 ) ;
else
F_13 ( V_2 -> V_27 ,
V_24 . V_33 [ 0 ] ,
V_24 . V_30 ) ;
if ( V_2 -> V_26 -> V_40 == V_41 )
V_2 -> V_37 = 0 ;
else
V_2 -> V_37 = V_24 . V_31 ;
}
}
static void F_14 ( struct V_42 * V_43 )
{
struct V_22 * V_2 = F_15 ( V_43 , struct V_22 , V_43 . V_43 ) ;
F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_43 , F_17 ( V_2 -> V_44 ) ) ;
}
static int F_18 ( struct V_45 * V_27 )
{
struct V_22 * V_2 = V_27 -> V_46 ;
F_19 ( & V_2 -> V_43 , F_14 ) ;
F_16 ( & V_2 -> V_43 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_45 * V_27 )
{
struct V_22 * V_2 = V_27 -> V_46 ;
F_21 ( & V_2 -> V_43 ) ;
}
int F_22 ( struct V_45 * V_45 , T_4 V_47 )
{
int V_27 = 0 ;
struct V_22 * V_2 = V_45 -> V_46 ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_3 V_48 = V_49 ;
if ( V_47 == V_50 ) {
V_26 -> V_51 . V_52 |= V_53 ;
V_2 -> V_39 = 1 ;
} else if ( V_47 == V_54 ) {
V_26 -> V_51 . V_52 &= ~ V_53 ;
V_48 = V_55 ;
V_2 -> V_39 = 1 ;
} else if ( V_47 != V_56 )
V_27 = - V_57 ;
F_23 ( V_26 , V_58 , V_26 -> V_51 . V_52 ,
V_53 ) ;
switch ( V_26 -> V_40 ) {
case V_59 :
case V_60 :
V_2 -> V_36 = F_8 ;
break;
case V_41 :
V_2 -> V_36 = F_9 ;
F_24 ( V_26 , V_61 , & V_48 , 1 ) ;
break;
default:
F_25 ( L_6 ) ;
V_27 = - V_57 ;
}
return V_27 ;
}
int F_26 ( struct V_25 * V_26 )
{
struct V_22 * V_2 ;
struct V_45 * V_27 ;
int V_62 = - V_63 ;
if ( V_26 -> V_51 . V_64 == NULL ) {
return 0 ;
}
V_2 = F_27 ( sizeof( * V_2 ) , V_65 ) ;
V_27 = F_28 () ;
if ( ! V_2 || ! V_27 )
goto V_66;
V_2 -> V_26 = V_26 ;
V_26 -> V_2 = V_2 ;
V_2 -> V_27 = V_27 ;
V_27 -> V_67 = V_50 | V_54 ;
V_27 -> V_46 = V_2 ;
V_27 -> V_68 = F_22 ;
V_27 -> V_69 = F_18 ;
V_27 -> V_70 = F_20 ;
V_62 = F_22 ( V_27 , V_56 ) ;
if ( V_62 )
goto V_66;
V_2 -> V_44 = 100 ;
snprintf ( V_2 -> V_71 , sizeof( V_2 -> V_71 ) , L_7 ,
V_26 -> V_71 ) ;
F_29 ( V_26 -> V_72 , V_2 -> V_73 , sizeof( V_2 -> V_73 ) ) ;
F_30 ( V_2 -> V_73 , L_8 , sizeof( V_2 -> V_73 ) ) ;
V_27 -> V_74 = V_2 -> V_71 ;
V_27 -> V_75 = V_2 -> V_73 ;
V_27 -> V_76 . V_77 = V_78 ;
V_27 -> V_76 . V_79 = 1 ;
V_27 -> V_76 . V_80 = F_31 ( V_26 -> V_72 -> V_81 . V_82 ) ;
V_27 -> V_76 . V_83 = F_31 ( V_26 -> V_72 -> V_81 . V_84 ) ;
V_27 -> V_26 . V_85 = & V_26 -> V_72 -> V_26 ;
V_27 -> V_86 = V_26 -> V_51 . V_64 ;
V_27 -> V_87 = V_88 ;
V_62 = F_32 ( V_27 ) ;
if ( V_62 )
goto V_89;
return 0 ;
V_89:
V_26 -> V_2 = NULL ;
V_66:
F_33 ( V_27 ) ;
F_34 ( V_2 ) ;
return V_62 ;
}
int F_35 ( struct V_25 * V_26 )
{
struct V_22 * V_2 = V_26 -> V_2 ;
if ( ! V_2 )
return 0 ;
F_20 ( V_2 -> V_27 ) ;
F_36 ( V_2 -> V_27 ) ;
F_34 ( V_2 ) ;
V_26 -> V_2 = NULL ;
return 0 ;
}
static void F_37 ( struct V_42 * V_43 )
{
struct V_25 * V_26 =
F_15 ( V_43 , struct V_25 , V_90 . V_43 ) ;
int V_91 ;
V_91 = F_38 ( V_26 , V_92 ) ;
if ( V_91 & V_93 ) {
T_3 V_94 ;
V_94 = ( ( T_3 ) V_91 ) & ~ V_93 ;
F_24 ( V_26 , V_92 , & V_94 , 1 ) ;
F_39 ( V_26 -> V_95 , V_96 ,
1 ) ;
F_39 ( V_26 -> V_95 , V_96 ,
0 ) ;
}
F_16 ( & V_26 -> V_90 ,
F_17 ( V_97 ) ) ;
}
void F_40 ( struct V_25 * V_26 )
{
struct V_98 * V_98 ;
int V_62 ;
F_41 ( L_9 ) ;
V_98 = F_42 () ;
if ( ! V_98 ) {
F_43 ( L_10 ) ;
return;
}
F_29 ( V_26 -> V_72 , V_26 -> V_99 ,
sizeof( V_26 -> V_99 ) ) ;
F_30 ( V_26 -> V_99 , L_11 ,
sizeof( V_26 -> V_99 ) ) ;
F_19 ( & V_26 -> V_90 , F_37 ) ;
V_98 -> V_71 = L_12 ;
V_98 -> V_73 = V_26 -> V_99 ;
V_98 -> V_100 [ 0 ] = F_44 ( V_101 ) | F_44 ( V_102 ) ;
F_45 ( V_96 , V_98 -> V_103 ) ;
V_98 -> V_104 = 0 ;
V_98 -> V_105 = 0 ;
V_98 -> V_106 . V_77 = V_78 ;
V_98 -> V_106 . V_80 = F_31 ( V_26 -> V_72 -> V_81 . V_82 ) ;
V_98 -> V_106 . V_83 = F_31 ( V_26 -> V_72 -> V_81 . V_84 ) ;
V_98 -> V_106 . V_79 = 1 ;
V_98 -> V_26 . V_85 = & V_26 -> V_72 -> V_26 ;
V_62 = F_46 ( V_98 ) ;
if ( V_62 ) {
F_43 ( L_13 ) ;
F_47 ( V_98 ) ;
return;
}
V_26 -> V_95 = V_98 ;
F_16 ( & V_26 -> V_90 ,
F_17 ( V_97 ) ) ;
return;
}
void F_48 ( struct V_25 * V_26 )
{
if ( V_26 -> V_95 != NULL ) {
F_41 ( L_14 ) ;
F_21 ( & V_26 -> V_90 ) ;
F_49 ( V_26 -> V_95 ) ;
V_26 -> V_95 = NULL ;
}
return;
}
