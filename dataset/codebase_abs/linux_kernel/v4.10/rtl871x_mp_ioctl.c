T_1 F_1 ( struct V_1 * V_2 )
{
return V_3 ;
}
T_1 F_2 ( struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 == V_9 ) {
if ( V_2 -> V_10 >= sizeof( V_11 ) )
V_6 -> V_12 . V_13 =
* ( V_11 * ) V_2 -> V_14 ;
else
V_4 = V_15 ;
} else if ( V_2 -> V_8 == V_16 ) {
if ( V_2 -> V_10 >= sizeof( V_11 ) ) {
* ( V_11 * ) V_2 -> V_14 =
V_6 -> V_12 . V_13 ;
* V_2 -> V_17 =
V_2 -> V_10 ;
} else {
V_4 = V_15 ;
}
} else {
V_4 = V_18 ;
}
return V_4 ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_19 * V_20 ;
T_2 V_21 ;
T_3 V_22 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( struct V_19 ) )
return V_15 ;
V_20 = (struct V_19 * ) ( V_2 -> V_14 ) ;
V_21 = ( T_2 ) ( V_20 -> V_21 ) & 0xFFF ;
if ( V_21 < V_23 )
V_21 |= V_23 ;
V_22 = V_20 -> V_22 ;
F_4 ( V_6 , V_21 , V_22 ) ;
return V_3 ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_19 * V_20 ;
T_2 V_21 ;
T_3 V_22 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( struct V_19 ) )
return V_15 ;
V_20 = (struct V_19 * ) ( V_2 -> V_14 ) ;
V_21 = ( T_2 ) ( V_20 -> V_21 ) & 0xFFF ;
if ( V_21 < V_23 )
V_21 |= V_23 ;
V_22 = F_6 ( V_6 , V_21 ) ;
V_20 -> V_22 = V_22 ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_24 * V_20 ;
V_11 V_25 ;
V_11 V_21 ;
T_3 V_22 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( struct V_24 ) )
return V_15 ;
V_20 = (struct V_24 * ) ( V_2 -> V_14 ) ;
V_25 = ( V_11 ) V_20 -> V_25 ;
if ( V_25 > V_26 )
return V_18 ;
V_21 = ( V_11 ) V_20 -> V_21 ;
V_22 = V_20 -> V_22 ;
F_8 ( V_6 , V_25 , V_21 , V_22 ) ;
return V_3 ;
}
T_1 F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_24 * V_20 ;
V_11 V_25 ;
V_11 V_21 ;
T_3 V_22 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( struct V_24 ) )
return V_15 ;
V_20 = (struct V_24 * ) ( V_2 -> V_14 ) ;
V_25 = ( V_11 ) V_20 -> V_25 ;
if ( V_25 > V_26 )
return V_18 ;
V_21 = ( V_11 ) V_20 -> V_21 ;
V_22 = F_10 ( V_6 , V_25 , V_21 ) ;
V_20 -> V_22 = V_22 ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
static int F_11 ( struct V_5 * V_27 )
{
struct V_28 * V_29 = & V_27 -> V_30 ;
struct V_31 * V_32 = & V_27 -> V_33 ;
struct V_34 * V_35 = & V_32 -> V_36 ;
struct V_37 V_38 ;
struct V_39 * V_40 ;
unsigned long V_41 ;
unsigned long V_42 ;
int V_43 = V_44 ;
memcpy ( V_38 . V_45 , V_29 -> V_46 , V_47 ) ;
V_38 . V_48 . V_49 = 16 ;
memcpy ( V_38 . V_48 . V_48 , ( unsigned char * ) L_1 ,
V_38 . V_48 . V_49 ) ;
V_38 . V_50 = V_51 ;
V_38 . V_52 = V_53 ;
V_38 . V_54 = 0 ;
V_41 = F_12 ( & V_38 ) ;
if ( V_41 % 4 ) {
V_38 . V_55 = ( ( V_41 >> 2 ) + 1 ) << 2 ;
} else {
V_38 . V_55 = V_41 ;
}
F_13 ( & V_32 -> V_56 , V_42 ) ;
if ( F_14 ( V_32 , V_57 ) )
goto V_58;
V_29 -> V_59 = F_15 ( V_32 ) ;
V_32 -> V_60 = V_57 ;
if ( V_29 -> V_61 == V_62 )
F_16 ( V_32 , V_63 ) ;
F_16 ( V_32 , V_64 ) ;
V_40 = F_17 ( & V_27 -> V_65 ,
V_35 -> V_66 . V_45 ) ;
if ( V_40 )
F_18 ( V_27 , V_40 ) ;
V_40 = F_19 ( & V_27 -> V_65 , V_38 . V_45 ) ;
if ( V_40 == NULL ) {
V_43 = V_67 ;
goto V_58;
}
V_35 -> V_68 = 1 ;
V_35 -> V_69 = V_40 -> V_69 = 1 ;
memcpy ( & V_35 -> V_66 , & V_38 , V_41 ) ;
F_20 ( V_32 , V_64 ) ;
F_21 ( V_27 ) ;
F_16 ( V_32 , V_70 ) ;
V_58:
F_22 ( & V_32 -> V_56 , V_42 ) ;
return V_43 ;
}
static int F_23 ( struct V_5 * V_27 )
{
struct V_28 * V_29 = & V_27 -> V_30 ;
struct V_31 * V_32 = & V_27 -> V_33 ;
struct V_34 * V_35 = & V_32 -> V_36 ;
struct V_39 * V_40 ;
unsigned long V_42 ;
F_13 ( & V_32 -> V_56 , V_42 ) ;
if ( ! F_14 ( V_32 , V_57 ) )
goto V_71;
F_24 ( V_27 ) ;
V_40 = F_17 ( & V_27 -> V_65 ,
V_35 -> V_66 . V_45 ) ;
if ( V_40 )
F_18 ( V_27 , V_40 ) ;
V_32 -> V_60 = V_29 -> V_59 ;
memset ( V_35 , 0 , sizeof( struct V_34 ) ) ;
V_71:
F_22 ( & V_32 -> V_56 , V_42 ) ;
return V_44 ;
}
int F_25 ( struct V_5 * V_27 , struct V_72 * V_73 )
{
struct V_28 * V_29 = & V_27 -> V_30 ;
struct V_31 * V_32 = & V_27 -> V_33 ;
unsigned char V_43 = V_44 ;
if ( ! F_14 ( V_32 , V_57 ) )
return V_67 ;
if ( ! F_14 ( V_32 , V_70 ) )
return V_67 ;
F_20 ( V_32 , V_70 ) ;
V_43 = F_26 ( V_27 , V_29 -> V_46 ) ;
F_16 ( V_32 , V_64 ) ;
return V_43 ;
}
T_1 F_27 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_74 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 != sizeof( T_3 ) )
return V_15 ;
V_74 = * ( ( T_3 * ) V_2 -> V_14 ) ;
if ( V_74 >= V_75 )
return V_76 ;
V_6 -> V_30 . V_77 = V_74 ;
F_28 ( V_6 ) ;
return V_3 ;
}
T_1 F_29 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
T_3 V_61 ;
V_11 V_78 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_61 = * ( ( T_3 * ) V_2 -> V_14 ) ;
V_6 -> V_30 . V_61 = V_61 ;
if ( F_11 ( V_6 ) == V_67 )
V_4 = V_18 ;
F_30 ( V_6 , V_79 , 1 ) ;
F_30 ( V_6 , V_80 , 0 ) ;
F_30 ( V_6 , V_80 + 2 , 0x57 ) ;
F_31 ( V_6 , V_81 , 0x0 ) ;
V_78 = F_32 ( V_6 , V_82 ) ;
if ( ! ( V_78 & V_83 ) ) {
F_33 ( V_6 ) ;
F_34 ( V_6 ) ;
F_35 ( V_6 ) ;
}
return V_4 ;
}
T_1 F_36 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( F_23 ( V_6 ) == V_67 )
V_4 = V_18 ;
return V_4 ;
}
T_1 F_37 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_84 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 != sizeof( T_3 ) )
return V_15 ;
V_84 = * ( ( T_3 * ) V_2 -> V_14 ) ;
if ( V_84 > 14 )
return V_18 ;
V_6 -> V_30 . V_85 = V_84 ;
F_38 ( V_6 ) ;
return V_3 ;
}
T_1 F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_86 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 != sizeof( T_3 ) )
return V_15 ;
V_86 = * ( ( T_3 * ) V_2 -> V_14 ) ;
V_6 -> V_30 . V_87 = ( T_2 ) ( ( V_86 & 0xFFFF0000 ) >> 16 ) ;
V_6 -> V_30 . V_88 = ( T_2 ) ( V_86 & 0x0000FFFF ) ;
F_40 ( V_6 ) ;
return V_3 ;
}
T_1 F_41 (
struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_89 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 != sizeof( T_3 ) )
return V_15 ;
V_89 = * ( ( T_3 * ) V_2 -> V_14 ) ;
if ( V_89 > V_90 )
return V_18 ;
V_6 -> V_30 . V_91 = ( V_11 ) V_89 ;
F_42 ( V_6 ) ;
return V_3 ;
}
T_1 F_43 (
struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 ) {
V_4 = V_18 ;
return V_4 ;
}
if ( V_2 -> V_10 == sizeof( T_3 ) ) {
* ( T_3 * ) V_2 -> V_14 =
V_6 -> V_30 . V_92 ;
* V_2 -> V_17 = V_2 -> V_10 ;
} else {
V_4 = V_15 ;
}
return V_4 ;
}
T_1 F_44 (
struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 ) {
V_4 = V_18 ;
return V_4 ;
}
if ( V_2 -> V_10 == sizeof( T_3 ) ) {
* ( T_3 * ) V_2 -> V_14 =
V_6 -> V_30 . V_93 ;
* V_2 -> V_17 = V_2 -> V_10 ;
} else {
V_4 = V_15 ;
}
return V_4 ;
}
T_1 F_45 (
struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 ) {
V_4 = V_18 ;
return V_4 ;
}
if ( V_2 -> V_10 == sizeof( T_3 ) ) {
* ( T_3 * ) V_2 -> V_14 =
V_6 -> V_30 . V_94 ;
* V_2 -> V_17 = V_2 -> V_10 ;
} else {
V_4 = V_15 ;
}
return V_4 ;
}
T_1 F_46 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_6 -> V_30 . V_92 = 0 ;
return V_3 ;
}
T_1 F_47 ( struct V_1
* V_2 )
{
T_1 V_4 = V_3 ;
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 == sizeof( T_3 ) ) {
V_6 -> V_30 . V_93 = 0 ;
V_6 -> V_30 . V_94 = 0 ;
} else {
V_4 = V_15 ;
}
return V_4 ;
}
T_1 F_48 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
F_49 ( V_6 ) ;
return V_3 ;
}
T_1 F_50 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 != sizeof( T_3 ) )
return V_15 ;
* ( T_3 * ) V_2 -> V_14 =
F_51 ( V_6 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_52 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 != sizeof( T_3 ) )
return V_15 ;
* ( T_3 * ) V_2 -> V_14 =
F_53 ( V_6 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_54 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_6 -> V_30 . V_95 = * ( ( V_11 * ) V_2 -> V_14 ) ;
return V_3 ;
}
T_1 F_55 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_96 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_96 = * ( ( T_3 * ) V_2 -> V_14 ) ;
F_56 ( V_6 , ( V_11 ) V_96 ) ;
return V_3 ;
}
T_1 F_57 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_96 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_96 = * ( ( T_3 * ) V_2 -> V_14 ) ;
F_58 ( V_6 , ( V_11 ) V_96 ) ;
return V_3 ;
}
T_1 F_59 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_96 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_96 = * ( ( T_3 * ) V_2 -> V_14 ) ;
F_60 ( V_6 , ( V_11 ) V_96 ) ;
return V_3 ;
}
T_1 F_61 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_96 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_96 = * ( ( T_3 * ) V_2 -> V_14 ) ;
F_62 ( V_6 , ( V_11 ) V_96 ) ;
return V_3 ;
}
T_1 F_63 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_97 * V_98 ;
T_2 V_21 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
V_98 = (struct V_97 * ) V_2 -> V_14 ;
if ( ( V_98 -> V_21 >= 0x10250800 ) &&
( V_98 -> V_21 <= 0x10250FFF ) ) {
V_21 = ( T_2 ) ( V_98 -> V_21 ) & 0xFFF ;
V_98 -> V_22 = F_6 ( V_6 , V_21 ) ;
} else {
switch ( V_98 -> V_99 ) {
case 1 :
V_98 -> V_22 = F_32 ( V_6 ,
V_98 -> V_21 ) ;
break;
case 2 :
V_98 -> V_22 = F_64 ( V_6 ,
V_98 -> V_21 ) ;
break;
case 4 :
V_98 -> V_22 = F_65 ( V_6 ,
V_98 -> V_21 ) ;
break;
default:
V_4 = V_18 ;
break;
}
}
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_66 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_97 * V_98 ;
T_2 V_21 ;
T_3 V_22 ;
T_3 V_100 = 0 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_98 = (struct V_97 * ) V_2 -> V_14 ;
if ( ( V_98 -> V_21 >= 0x10250800 ) &&
( V_98 -> V_21 <= 0x10250FFF ) ) {
V_21 = ( T_2 ) ( V_98 -> V_21 ) & 0xFFF ;
V_22 = V_98 -> V_22 ;
switch ( V_98 -> V_99 ) {
case 1 :
V_100 = F_6 ( V_6 , V_21 ) ;
V_100 &= 0xFFFFFF00 ;
V_22 &= 0x000000FF ;
V_22 |= V_100 ;
break;
case 2 :
V_100 = F_6 ( V_6 , V_21 ) ;
V_100 &= 0xFFFF0000 ;
V_22 &= 0x0000FFFF ;
V_22 |= V_100 ;
break;
}
F_4 ( V_6 , V_21 , V_22 ) ;
} else {
switch ( V_98 -> V_99 ) {
case 1 :
F_30 ( V_6 , V_98 -> V_21 ,
( unsigned char ) V_98 -> V_22 ) ;
break;
case 2 :
F_31 ( V_6 , V_98 -> V_21 ,
( unsigned short ) V_98 -> V_22 ) ;
break;
case 4 :
F_67 ( V_6 , V_98 -> V_21 ,
( unsigned int ) V_98 -> V_22 ) ;
break;
default:
V_4 = V_18 ;
break;
}
if ( ( V_4 == V_3 ) &&
( V_98 -> V_21 == V_101 ) &&
( V_98 -> V_99 == 4 ) )
V_6 -> V_102 = V_98 -> V_22 ;
}
return V_4 ;
}
T_1 F_68 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_6 -> V_30 . V_103 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( V_11 ) )
return V_15 ;
V_6 -> V_30 . V_103 = true ;
V_6 -> V_30 . V_104 . V_105 = false ;
V_6 -> V_30 . V_104 . V_106 = V_107 ;
V_6 -> V_30 . V_104 . V_108 = 0 ;
V_6 -> V_30 . V_104 . V_109 = 0xFFFFFFFF ;
F_69 ( V_6 , & V_6 -> V_30 . V_104 . V_109 ) ;
V_6 -> V_30 . V_104 . V_105 = true ;
V_6 -> V_30 . V_103 = false ;
* ( T_3 * ) V_2 -> V_14 =
V_6 -> V_30 . V_104 . V_109 ;
* V_2 -> V_17 = sizeof( T_3 ) ;
return V_3 ;
}
T_1 F_70 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_110 * V_111 ;
V_11 * V_112 ;
T_2 V_113 = 0 , V_114 = 0 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 <
sizeof( struct V_110 ) )
return V_15 ;
V_111 = (struct V_110 * ) V_2 -> V_14 ;
V_113 = V_111 -> V_115 ;
V_114 = V_111 -> V_114 ;
V_112 = V_111 -> V_112 ;
memset ( V_112 , 0xFF , V_114 ) ;
if ( ( V_113 > 511 ) || ( V_114 < 1 ) || ( V_114 > 512 ) || ( V_113 + V_114 ) >
V_116 )
return V_18 ;
if ( ! F_71 ( V_6 , true , V_113 , V_114 , V_112 ) )
V_4 = V_117 ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_72 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_110 * V_111 ;
V_11 * V_112 ;
T_2 V_113 = 0 , V_114 = 0 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_111 = (struct V_110 * ) V_2 -> V_14 ;
V_113 = V_111 -> V_115 ;
V_114 = V_111 -> V_114 ;
V_112 = V_111 -> V_112 ;
if ( ( V_113 > 511 ) || ( V_114 < 1 ) || ( V_114 > 512 ) ||
( V_113 + V_114 ) > F_73 ( V_6 ) )
return V_18 ;
if ( ! F_71 ( V_6 , false , V_113 , V_114 , V_112 ) )
V_4 = V_117 ;
return V_4 ;
}
T_1 F_74 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( int ) )
return V_15 ;
F_33 ( V_6 ) ;
* ( int * ) V_2 -> V_14 =
F_75 ( V_6 ) ;
F_35 ( V_6 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
* ( int * ) V_2 -> V_14 =
F_73 ( V_6 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_77 ( struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 == V_16 )
V_4 = F_70 ( V_2 ) ;
else
V_4 = F_72 ( V_2 ) ;
return V_4 ;
}
T_1 F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
V_11 * V_112 ;
* V_2 -> V_17 = 0 ;
if ( V_2 -> V_10 < V_118 )
return V_15 ;
V_112 = ( V_11 * ) V_2 -> V_14 ;
if ( V_2 -> V_8 == V_16 ) {
if ( F_79 ( V_6 , 0 , V_118 , V_112 ) )
* V_2 -> V_17 = V_118 ;
else
V_4 = V_117 ;
} else {
if ( F_33 ( V_6 ) ) {
if ( F_80 ( V_6 , 0 ,
V_118 , V_112 ) )
* V_2 -> V_17 = V_118 ;
else
V_4 = V_117 ;
F_35 ( V_6 ) ;
} else {
V_4 = V_117 ;
}
}
return V_4 ;
}
T_1 F_81 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_119 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
V_119 = * ( ( T_3 * ) V_2 -> V_14 ) ;
if ( V_119 != V_120 )
V_119 = V_121 ;
V_6 -> V_30 . V_122 = ( V_11 ) V_119 ;
F_82 ( V_6 ) ;
return V_3 ;
}
T_1 F_83 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
V_11 V_123 ;
T_3 V_124 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( V_11 ) )
return V_15 ;
V_123 = * ( ( V_11 * ) V_2 -> V_14 ) ;
V_124 = F_65 ( V_6 , V_80 ) ;
V_124 &= ~ ( V_125 | V_126 | V_127 | V_128 | V_129 ) ;
switch ( V_123 ) {
case V_130 :
V_124 |= ( V_126 | V_127 | V_128 | V_129 | V_131 ) ;
break;
case V_132 :
V_124 |= ( V_126 | V_127 | V_128 | V_129 | V_131 ) ;
break;
case V_133 :
V_124 |= ( V_128 | V_131 ) ;
break;
default:
V_124 &= ~ ( V_129 |
V_128 |
V_127 |
V_126 |
V_131 ) ;
break;
}
if ( V_123 == V_132 )
V_6 -> V_30 . V_134 = 1 ;
else
V_6 -> V_30 . V_134 = 0 ;
F_67 ( V_6 , V_80 , V_124 ) ;
return V_3 ;
}
unsigned int F_84 ( struct V_1 * V_2 )
{
return V_44 ;
}
T_1 F_85 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_9 )
return V_18 ;
return V_3 ;
}
T_1 F_86 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
* ( int * ) V_2 -> V_14 =
V_6 -> V_12 . V_135 ? V_136 : V_137 ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
