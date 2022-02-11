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
if ( V_2 -> V_26 -> V_40 == V_41 ||
V_2 -> V_26 -> V_40 == V_42 )
V_2 -> V_37 = 0 ;
else
V_2 -> V_37 = V_24 . V_31 ;
}
}
static void F_14 ( struct V_43 * V_44 )
{
struct V_22 * V_2 = F_15 ( V_44 , struct V_22 , V_44 . V_44 ) ;
F_10 ( V_2 ) ;
F_16 ( & V_2 -> V_44 , F_17 ( V_2 -> V_45 ) ) ;
}
static int F_18 ( struct V_46 * V_27 )
{
struct V_22 * V_2 = V_27 -> V_47 ;
F_19 ( & V_2 -> V_44 , F_14 ) ;
F_16 ( & V_2 -> V_44 , 0 ) ;
return 0 ;
}
static void F_20 ( struct V_46 * V_27 )
{
struct V_22 * V_2 = V_27 -> V_47 ;
F_21 ( & V_2 -> V_44 ) ;
}
int F_22 ( struct V_46 * V_46 , T_4 V_48 )
{
int V_27 = 0 ;
struct V_22 * V_2 = V_46 -> V_47 ;
struct V_25 * V_26 = V_2 -> V_26 ;
T_3 V_49 = V_50 ;
if ( V_48 == V_51 ) {
V_26 -> V_52 . V_53 |= V_54 ;
V_2 -> V_39 = 1 ;
} else if ( V_48 == V_55 ) {
V_26 -> V_52 . V_53 &= ~ V_54 ;
V_49 = V_56 ;
V_2 -> V_39 = 1 ;
} else if ( V_48 != V_57 )
V_27 = - V_58 ;
F_23 ( V_26 , V_59 , V_26 -> V_52 . V_53 ,
V_54 ) ;
switch ( V_26 -> V_40 ) {
case V_60 :
case V_61 :
V_2 -> V_36 = F_8 ;
break;
case V_42 :
case V_41 :
case V_62 :
V_2 -> V_36 = F_9 ;
F_24 ( V_26 , V_63 , & V_49 , 1 ) ;
break;
default:
F_25 ( L_6 ,
V_26 -> V_40 ) ;
V_27 = - V_58 ;
}
return V_27 ;
}
int F_26 ( struct V_25 * V_26 )
{
struct V_22 * V_2 ;
struct V_46 * V_27 ;
int V_64 = - V_65 ;
if ( V_26 -> V_52 . V_66 == NULL ) {
return 0 ;
}
V_2 = F_27 ( sizeof( * V_2 ) , V_67 ) ;
V_27 = F_28 () ;
if ( ! V_2 || ! V_27 )
goto V_68;
V_2 -> V_26 = V_26 ;
V_26 -> V_2 = V_2 ;
V_2 -> V_27 = V_27 ;
V_27 -> V_69 = V_51 | V_55 ;
V_27 -> V_47 = V_2 ;
V_27 -> V_70 = F_22 ;
V_27 -> V_71 = F_18 ;
V_27 -> V_72 = F_20 ;
V_64 = F_22 ( V_27 , V_57 ) ;
if ( V_64 )
goto V_68;
V_2 -> V_45 = 100 ;
snprintf ( V_2 -> V_73 , sizeof( V_2 -> V_73 ) , L_7 ,
V_26 -> V_73 ) ;
F_29 ( V_26 -> V_74 , V_2 -> V_75 , sizeof( V_2 -> V_75 ) ) ;
F_30 ( V_2 -> V_75 , L_8 , sizeof( V_2 -> V_75 ) ) ;
V_27 -> V_76 = V_2 -> V_73 ;
V_27 -> V_77 = V_2 -> V_75 ;
V_27 -> V_78 . V_79 = V_80 ;
V_27 -> V_78 . V_81 = 1 ;
V_27 -> V_78 . V_82 = F_31 ( V_26 -> V_74 -> V_83 . V_84 ) ;
V_27 -> V_78 . V_85 = F_31 ( V_26 -> V_74 -> V_83 . V_86 ) ;
V_27 -> V_26 . V_87 = & V_26 -> V_74 -> V_26 ;
V_27 -> V_88 = V_26 -> V_52 . V_66 ;
V_27 -> V_89 = V_90 ;
V_64 = F_32 ( V_27 ) ;
if ( V_64 )
goto V_91;
return 0 ;
V_91:
V_26 -> V_2 = NULL ;
V_68:
F_33 ( V_27 ) ;
F_34 ( V_2 ) ;
return V_64 ;
}
int F_35 ( struct V_25 * V_26 )
{
struct V_22 * V_2 = V_26 -> V_2 ;
if ( ! V_2 )
return 0 ;
if ( V_2 -> V_27 )
F_36 ( V_2 -> V_27 ) ;
F_34 ( V_2 ) ;
V_26 -> V_2 = NULL ;
return 0 ;
}
static void F_37 ( struct V_43 * V_44 )
{
struct V_25 * V_26 =
F_15 ( V_44 , struct V_25 , V_92 . V_44 ) ;
int V_93 ;
V_93 = F_38 ( V_26 , V_94 ) ;
if ( V_93 & V_95 ) {
T_3 V_96 ;
V_96 = ( ( T_3 ) V_93 ) & ~ V_95 ;
F_24 ( V_26 , V_94 , & V_96 , 1 ) ;
F_39 ( V_26 -> V_97 , V_98 ,
1 ) ;
F_39 ( V_26 -> V_97 , V_98 ,
0 ) ;
}
F_16 ( & V_26 -> V_92 ,
F_17 ( V_99 ) ) ;
}
void F_40 ( struct V_25 * V_26 )
{
struct V_100 * V_100 ;
int V_64 ;
F_41 ( L_9 ) ;
V_100 = F_42 () ;
if ( ! V_100 ) {
F_43 ( L_10 ) ;
return;
}
F_29 ( V_26 -> V_74 , V_26 -> V_101 ,
sizeof( V_26 -> V_101 ) ) ;
F_30 ( V_26 -> V_101 , L_11 ,
sizeof( V_26 -> V_101 ) ) ;
F_19 ( & V_26 -> V_92 , F_37 ) ;
V_100 -> V_73 = L_12 ;
V_100 -> V_75 = V_26 -> V_101 ;
V_100 -> V_102 [ 0 ] = F_44 ( V_103 ) | F_44 ( V_104 ) ;
F_45 ( V_98 , V_100 -> V_105 ) ;
V_100 -> V_106 = 0 ;
V_100 -> V_107 = 0 ;
V_100 -> V_108 . V_79 = V_80 ;
V_100 -> V_108 . V_82 = F_31 ( V_26 -> V_74 -> V_83 . V_84 ) ;
V_100 -> V_108 . V_85 = F_31 ( V_26 -> V_74 -> V_83 . V_86 ) ;
V_100 -> V_108 . V_81 = 1 ;
V_100 -> V_26 . V_87 = & V_26 -> V_74 -> V_26 ;
V_64 = F_46 ( V_100 ) ;
if ( V_64 ) {
F_43 ( L_13 ) ;
F_47 ( V_100 ) ;
return;
}
V_26 -> V_97 = V_100 ;
F_16 ( & V_26 -> V_92 ,
F_17 ( V_99 ) ) ;
return;
}
void F_48 ( struct V_25 * V_26 )
{
if ( V_26 -> V_97 != NULL ) {
F_41 ( L_14 ) ;
F_21 ( & V_26 -> V_92 ) ;
F_49 ( V_26 -> V_97 ) ;
V_26 -> V_97 = NULL ;
}
return;
}
