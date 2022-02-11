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
} else
V_4 = V_15 ;
} else {
V_4 = V_18 ;
}
return V_4 ;
}
T_1 F_3 ( struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
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
return V_4 ;
}
T_1 F_5 ( struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
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
return V_4 ;
}
T_1 F_7 ( struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
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
return V_4 ;
}
T_1 F_9 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
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
return V_4 ;
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
} else
V_38 . V_55 = V_41 ;
F_13 ( & V_32 -> V_56 , V_42 ) ;
if ( F_14 ( V_32 , V_57 ) == true )
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
if ( F_14 ( V_32 , V_57 ) == false )
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
if ( F_14 ( V_32 , V_57 ) == false )
return V_67 ;
if ( F_14 ( V_32 , V_70 ) == false )
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
T_1 V_4 = V_3 ;
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
return V_4 ;
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
T_1 V_4 = V_3 ;
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
return V_4 ;
}
T_1 F_39 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
T_3 V_86 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 != sizeof( T_3 ) )
return V_15 ;
V_86 = * ( ( T_3 * ) V_2 -> V_14 ) ;
V_6 -> V_30 . V_87 = ( T_2 ) ( ( V_86 & 0xFFFF0000 ) >> 16 ) ;
V_6 -> V_30 . V_88 = ( T_2 ) ( V_86 & 0x0000FFFF ) ;
F_40 ( V_6 ) ;
return V_4 ;
}
T_1 F_41 (
struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
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
return V_4 ;
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
} else
V_4 = V_15 ;
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
} else
V_4 = V_15 ;
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
} else
V_4 = V_15 ;
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
} else
V_4 = V_15 ;
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
T_1 F_63 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_72 * V_73 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
* V_2 -> V_97 = ( T_3 ) sizeof( struct V_72 ) ;
* V_2 -> V_17 = 0 ;
if ( V_2 -> V_10 < * V_2 -> V_97 )
return V_15 ;
V_73 = (struct V_72 * ) V_2 -> V_14 ;
if ( F_25 ( V_6 , V_73 ) == V_67 )
V_4 = V_18 ;
* V_2 -> V_17 = sizeof( struct V_72 ) ;
return V_4 ;
}
T_1 F_64 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_98 * V_99 ;
T_2 V_21 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
V_99 = (struct V_98 * ) V_2 -> V_14 ;
if ( ( V_99 -> V_21 >= 0x10250800 ) &&
( V_99 -> V_21 <= 0x10250FFF ) ) {
V_21 = ( T_2 ) ( V_99 -> V_21 ) & 0xFFF ;
V_99 -> V_22 = F_6 ( V_6 , V_21 ) ;
} else {
switch ( V_99 -> V_100 ) {
case 1 :
V_99 -> V_22 = F_32 ( V_6 ,
V_99 -> V_21 ) ;
break;
case 2 :
V_99 -> V_22 = F_65 ( V_6 ,
V_99 -> V_21 ) ;
break;
case 4 :
V_99 -> V_22 = F_66 ( V_6 ,
V_99 -> V_21 ) ;
break;
default:
V_4 = V_18 ;
break;
}
}
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_67 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_98 * V_99 ;
T_2 V_21 ;
T_3 V_22 ;
T_3 V_101 = 0 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_99 = (struct V_98 * ) V_2 -> V_14 ;
if ( ( V_99 -> V_21 >= 0x10250800 ) &&
( V_99 -> V_21 <= 0x10250FFF ) ) {
V_21 = ( T_2 ) ( V_99 -> V_21 ) & 0xFFF ;
V_22 = V_99 -> V_22 ;
switch ( V_99 -> V_100 ) {
case 1 :
V_101 = F_6 ( V_6 , V_21 ) ;
V_101 &= 0xFFFFFF00 ;
V_22 &= 0x000000FF ;
V_22 |= V_101 ;
break;
case 2 :
V_101 = F_6 ( V_6 , V_21 ) ;
V_101 &= 0xFFFF0000 ;
V_22 &= 0x0000FFFF ;
V_22 |= V_101 ;
break;
}
F_4 ( V_6 , V_21 , V_22 ) ;
} else {
switch ( V_99 -> V_100 ) {
case 1 :
F_30 ( V_6 , V_99 -> V_21 ,
( unsigned char ) V_99 -> V_22 ) ;
break;
case 2 :
F_31 ( V_6 , V_99 -> V_21 ,
( unsigned short ) V_99 -> V_22 ) ;
break;
case 4 :
F_68 ( V_6 , V_99 -> V_21 ,
( unsigned int ) V_99 -> V_22 ) ;
break;
default:
V_4 = V_18 ;
break;
}
if ( ( V_4 == V_3 ) &&
( V_99 -> V_21 == V_102 ) &&
( V_99 -> V_100 == 4 ) )
V_6 -> V_103 = V_99 -> V_22 ;
}
return V_4 ;
}
T_1 F_69 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_104 * V_105 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
V_105 = (struct V_104 * ) V_2 -> V_14 ;
F_70 ( V_6 , V_105 -> V_21 , ( T_3 ) V_105 -> V_106 ,
V_105 -> V_107 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_71 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_104 * V_105 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_105 = (struct V_104 * ) V_2 -> V_14 ;
F_72 ( V_6 , V_105 -> V_21 , ( T_3 ) V_105 -> V_106 ,
V_105 -> V_107 ) ;
return V_3 ;
}
T_1 F_73 ( struct V_1 * V_2 )
{
return V_3 ;
}
T_1 F_74 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_108 * V_109 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
V_109 = (struct V_108 * ) V_2 -> V_14 ;
V_109 -> V_22 = F_75 ( V_6 ,
( T_2 ) ( V_109 -> V_21 >> 1 ) ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_76 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_108 * V_109 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_109 = (struct V_108 * ) V_2 -> V_14 ;
F_77 ( V_6 , ( T_2 ) ( V_109 -> V_21 >> 1 ) ,
V_109 -> V_22 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_78 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_110 * V_111 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( struct V_110 ) )
return V_15 ;
if ( V_6 -> V_30 . V_112 . V_113 == false )
return V_18 ;
V_111 = (struct V_110 * ) V_2 -> V_14 ;
memcpy ( V_111 , & V_6 -> V_30 . V_112 ,
sizeof( struct V_110 ) ) ;
V_6 -> V_30 . V_114 = false ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_79 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_1 ) * 2 )
return V_15 ;
if ( * ( T_1 * ) V_2 -> V_14 == 1 )
V_6 -> V_30 . V_115 = 0 ;
* ( ( T_1 * ) V_2 -> V_14 + 1 ) =
V_6 -> V_30 . V_115 ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_80 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_16 )
return V_18 ;
return V_3 ;
}
T_1 F_81 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 != V_9 )
return V_18 ;
return V_3 ;
}
T_1 F_82 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( F_83 ( V_6 , * ( unsigned char * )
V_2 -> V_14 ) == V_67 )
V_4 = V_18 ;
return V_4 ;
}
T_1 F_84 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
memcpy ( V_2 -> V_14 ,
( unsigned char * ) & V_6 -> V_30 . V_116 ,
sizeof( struct V_117 ) ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_85 ( struct V_1
* V_2 )
{
return V_3 ;
}
T_1 F_86 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( F_87 ( V_6 ,
V_2 -> V_14 ) != V_44 )
V_4 = V_18 ;
return V_4 ;
}
T_1 F_88 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_6 -> V_30 . V_114 == true )
return V_18 ;
if ( V_2 -> V_10 < sizeof( V_11 ) )
return V_15 ;
V_6 -> V_30 . V_114 = true ;
V_6 -> V_30 . V_112 . V_113 = false ;
V_6 -> V_30 . V_112 . V_118 = V_119 ;
V_6 -> V_30 . V_112 . V_120 = 0 ;
V_6 -> V_30 . V_112 . V_121 = 0xFFFFFFFF ;
F_89 ( V_6 , & V_6 -> V_30 . V_112 . V_121 ) ;
V_6 -> V_30 . V_112 . V_113 = true ;
V_6 -> V_30 . V_114 = false ;
* ( T_3 * ) V_2 -> V_14 =
V_6 -> V_30 . V_112 . V_121 ;
* V_2 -> V_17 = sizeof( T_3 ) ;
return V_4 ;
}
T_1 F_90 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( V_11 ) )
return V_15 ;
if ( ! F_91 ( V_6 , * ( ( V_11 * ) V_2 -> V_14 ) ) )
V_4 = V_18 ;
return V_4 ;
}
T_1 F_92 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
V_11 V_122 [ V_123 ] = { 11 , 10 , 9 , 8 , 7 , 6 , 5 , 4 , 3 , 2 , 1 , 0 , 0xff } ;
T_1 V_4 = V_3 ;
T_3 V_74 ;
V_11 V_124 [ V_123 ] ;
int V_125 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_74 = * ( ( T_3 * ) V_2 -> V_14 ) ;
for ( V_125 = 0 ; V_125 < V_123 ; V_125 ++ ) {
if ( V_74 == V_122 [ V_125 ] )
V_124 [ V_125 ] = V_122 [ V_125 ] ;
else
V_124 [ V_125 ] = 0xff ;
}
if ( F_93 ( V_6 , V_124 ) != V_44 )
V_4 = V_18 ;
return V_4 ;
}
T_1 F_94 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < 8 )
return V_15 ;
* V_2 -> V_17 = 8 ;
memcpy ( V_2 -> V_14 ,
& ( V_6 -> V_126 . V_127 ) , 8 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
T_1 F_95 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_127 , V_128 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
* V_2 -> V_17 = 0 ;
* V_2 -> V_97 = 8 ;
if ( V_2 -> V_10 < 8 )
return V_15 ;
V_127 = * ( T_1 * ) ( V_2 -> V_14 ) ;
V_128 = * ( T_1 * ) ( ( V_129 ) V_2 -> V_14 + 4 ) ;
if ( V_127 != V_6 -> V_126 . V_127 || V_128 !=
V_6 -> V_126 . V_128 )
F_96 ( V_6 , V_127 , V_128 ) ;
* V_2 -> V_17 = 8 ;
return V_3 ;
}
T_1 F_97 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_130 * V_131 ;
V_11 V_43 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
* V_2 -> V_97 = sizeof( struct V_130 ) ;
if ( V_2 -> V_10 <
sizeof( struct V_130 ) )
return V_15 ;
V_131 = (struct V_130 * ) V_2 -> V_14 ;
V_43 = F_98 ( V_6 , V_131 ) ;
if ( V_43 == V_67 )
V_4 = V_132 ;
return V_4 ;
}
T_1 F_99 ( struct V_1
* V_2 )
{
if ( V_2 -> V_8 != V_16 )
return V_18 ;
return V_3 ;
}
T_1 F_100 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
struct V_133 * V_134 = & V_6 -> V_135 ;
enum V_136 V_137 = 0 ;
* V_2 -> V_97 = sizeof( V_11 ) ;
if ( V_2 -> V_10 < * V_2 -> V_97 )
return V_15 ;
if ( V_2 -> V_8 == V_9 ) {
V_137 = * ( ( V_11 * ) V_2 -> V_14 ) ;
switch ( V_137 ) {
case V_138 :
V_134 -> V_139 = false ;
V_134 -> V_140 = false ;
break;
case V_141 :
V_134 -> V_139 = true ;
V_134 -> V_140 = true ;
break;
case V_142 :
V_134 -> V_139 = true ;
V_134 -> V_140 = false ;
break;
case V_143 :
V_134 -> V_139 = false ;
V_134 -> V_140 = true ;
break;
}
} else {
if ( ( V_134 -> V_140 == false ) &&
( V_134 -> V_139 == false ) )
V_137 = V_138 ;
else if ( ( V_134 -> V_140 == false ) &&
( V_134 -> V_139 == true ) )
V_137 = V_142 ;
else if ( ( V_134 -> V_140 == true ) &&
( V_134 -> V_139 == false ) )
V_137 = V_143 ;
else if ( ( V_134 -> V_140 == true ) &&
( V_134 -> V_139 == true ) )
V_137 = V_141 ;
* ( V_11 * ) V_2 -> V_14 = V_137 ;
* V_2 -> V_17 = V_2 -> V_10 ;
}
return V_3 ;
}
T_1 F_101 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_39 * V_40 = NULL ;
V_11 * V_144 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
* V_2 -> V_97 = V_47 ;
if ( V_2 -> V_10 < * V_2 -> V_97 )
return V_15 ;
V_144 = ( V_11 * ) V_2 -> V_14 ;
V_40 = F_17 ( & V_6 -> V_65 , V_144 ) ;
if ( V_40 == NULL ) {
V_40 = F_19 ( & V_6 -> V_65 , V_144 ) ;
if ( V_40 == NULL )
V_4 = V_132 ;
}
return V_4 ;
}
T_1 F_102 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
unsigned long V_42 ;
T_1 V_4 = V_3 ;
struct V_39 * V_40 = NULL ;
V_11 * V_144 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
* V_2 -> V_97 = V_47 ;
if ( V_2 -> V_10 < * V_2 -> V_97 )
return V_15 ;
V_144 = ( V_11 * ) V_2 -> V_14 ;
V_40 = F_17 ( & V_6 -> V_65 , V_144 ) ;
if ( V_40 != NULL ) {
F_13 ( & ( V_6 -> V_65 . V_145 ) , V_42 ) ;
F_18 ( V_6 , V_40 ) ;
F_22 ( & ( V_6 -> V_65 . V_145 ) , V_42 ) ;
}
return V_4 ;
}
static T_3 F_103 ( struct V_5 * V_27 , V_11 V_21 , T_3 V_146 )
{
return V_146 ;
}
T_1 F_104 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_147 * V_148 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
* V_2 -> V_97 = sizeof( struct V_147 ) ;
if ( V_2 -> V_10 < * V_2 -> V_97 )
return V_15 ;
V_148 = (struct V_147 * ) V_2 -> V_14 ;
V_148 -> V_149 = F_103 ( V_6 , V_148 -> V_21 ,
V_148 -> V_149 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_105 ( struct V_1 * V_2 )
{
return V_3 ;
}
T_1 F_106 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_150 * V_151 ;
V_11 * V_152 ;
T_2 V_153 = 0 , V_154 = 0 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 <
sizeof( struct V_150 ) )
return V_15 ;
V_151 = (struct V_150 * ) V_2 -> V_14 ;
V_153 = V_151 -> V_155 ;
V_154 = V_151 -> V_154 ;
V_152 = V_151 -> V_152 ;
memset ( V_152 , 0xFF , V_154 ) ;
if ( ( V_153 > 511 ) || ( V_154 < 1 ) || ( V_154 > 512 ) || ( V_153 + V_154 ) >
V_156 )
return V_18 ;
if ( F_107 ( V_6 , true , V_153 , V_154 , V_152 ) == false )
V_4 = V_132 ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_108 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_150 * V_151 ;
V_11 * V_152 ;
T_2 V_153 = 0 , V_154 = 0 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_151 = (struct V_150 * ) V_2 -> V_14 ;
V_153 = V_151 -> V_155 ;
V_154 = V_151 -> V_154 ;
V_152 = V_151 -> V_152 ;
if ( ( V_153 > 511 ) || ( V_154 < 1 ) || ( V_154 > 512 ) ||
( V_153 + V_154 ) > F_109 ( V_6 ) )
return V_18 ;
if ( F_107 ( V_6 , false , V_153 , V_154 , V_152 ) == false )
V_4 = V_132 ;
return V_4 ;
}
T_1 F_110 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_157 * V_158 ;
* V_2 -> V_17 = 0 ;
if ( V_2 -> V_10 < sizeof( struct V_157 ) )
return V_15 ;
V_158 = (struct V_157 * ) V_2 -> V_14 ;
if ( V_2 -> V_8 == V_16 ) {
if ( F_111 ( V_6 , V_158 -> V_21 ,
V_158 -> V_152 ) == true )
* V_2 -> V_17 =
V_2 -> V_10 ;
else
V_4 = V_132 ;
} else {
if ( F_33 ( V_6 ) == true ) {
if ( F_112 ( V_6 , V_158 -> V_21 ,
V_158 -> V_159 , V_158 -> V_152 ) == true )
* V_2 -> V_17 =
V_2 -> V_10 ;
else
V_4 = V_132 ;
F_35 ( V_6 ) ;
} else
V_4 = V_132 ;
}
return V_4 ;
}
T_1 F_113 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( int ) )
return V_15 ;
F_33 ( V_6 ) ;
* ( int * ) V_2 -> V_14 =
F_114 ( V_6 ) ;
F_35 ( V_6 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_115 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
* ( int * ) V_2 -> V_14 =
F_109 ( V_6 ) ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_4 ;
}
T_1 F_116 ( struct V_1 * V_2 )
{
T_1 V_4 = V_3 ;
if ( V_2 -> V_8 == V_16 )
V_4 = F_106 ( V_2 ) ;
else
V_4 = F_108 ( V_2 ) ;
return V_4 ;
}
T_1 F_117 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
V_11 * V_152 ;
* V_2 -> V_17 = 0 ;
if ( V_2 -> V_10 < V_160 )
return V_15 ;
V_152 = ( V_11 * ) V_2 -> V_14 ;
if ( V_2 -> V_8 == V_16 ) {
if ( F_118 ( V_6 , 0 , V_160 , V_152 ) )
* V_2 -> V_17 = V_160 ;
else
V_4 = V_132 ;
} else {
if ( F_33 ( V_6 ) == true ) {
if ( F_119 ( V_6 , 0 ,
V_160 , V_152 ) )
* V_2 -> V_17 = V_160 ;
else
V_4 = V_132 ;
F_35 ( V_6 ) ;
} else {
V_4 = V_132 ;
}
}
return V_4 ;
}
T_1 F_120 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
T_3 V_161 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
V_161 = * ( ( T_3 * ) V_2 -> V_14 ) ;
if ( V_161 != V_162 )
V_161 = V_163 ;
V_6 -> V_30 . V_164 = ( V_11 ) V_161 ;
F_121 ( V_6 ) ;
return V_4 ;
}
T_1 F_122 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
T_3 V_165 = 0 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
V_165 = * ( ( T_3 * ) V_2 -> V_14 ) ;
if ( V_165 > 0xf )
return V_18 ;
V_6 -> V_30 . V_166 = V_165 ;
F_123 ( V_6 ) ;
return V_4 ;
}
T_1 F_124 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
V_11 V_167 ;
T_3 V_168 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( V_11 ) )
return V_15 ;
V_167 = * ( ( V_11 * ) V_2 -> V_14 ) ;
V_168 = F_66 ( V_6 , V_80 ) ;
V_168 &= ~ ( V_169 | V_170 | V_171 | V_172 | V_173 ) ;
switch ( V_167 ) {
case V_174 :
V_168 |= ( V_170 | V_171 | V_172 | V_173 | V_175 ) ;
break;
case V_176 :
V_168 |= ( V_170 | V_171 | V_172 | V_173 | V_175 ) ;
break;
case V_177 :
V_168 |= ( V_172 | V_175 ) ;
break;
default:
V_168 &= ~ ( V_173 |
V_172 |
V_171 |
V_170 |
V_175 ) ;
break;
}
if ( V_167 == V_176 )
V_6 -> V_30 . V_178 = 1 ;
else
V_6 -> V_30 . V_178 = 0 ;
F_68 ( V_6 , V_80 , V_168 ) ;
return V_3 ;
}
T_1 F_125 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_3 V_179 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
V_179 = * ( T_3 * ) V_2 -> V_14 ;
F_126 ( V_6 , V_179 ) ;
return V_3 ;
}
T_1 F_127 ( struct V_1
* V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
T_1 V_4 = V_3 ;
struct V_31 * V_32 = & V_6 -> V_33 ;
struct V_28 * V_29 = & V_6 -> V_30 ;
T_3 type ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
type = * ( T_3 * ) V_2 -> V_14 ;
if ( V_62 == type ) {
V_29 -> V_61 = type ;
F_16 ( V_32 , V_63 ) ;
} else if ( V_180 == type ) {
V_29 -> V_61 = type ;
F_20 ( V_32 , V_63 ) ;
} else
V_4 = V_18 ;
return V_4 ;
}
unsigned int F_128 ( struct V_1 * V_2 )
{
return V_44 ;
}
T_1 F_129 ( struct V_1 * V_2 )
{
V_11 V_181 ;
if ( V_2 -> V_8 != V_9 )
return V_18 ;
V_181 = * ( V_11 * ) V_2 -> V_14 ;
return V_3 ;
}
T_1 F_130 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = (struct V_5 * )
( V_2 -> V_7 ) ;
if ( V_2 -> V_8 != V_16 )
return V_18 ;
if ( V_2 -> V_10 < sizeof( T_3 ) )
return V_15 ;
* ( int * ) V_2 -> V_14 =
V_6 -> V_12 . V_182 ? V_183 : V_184 ;
* V_2 -> V_17 = V_2 -> V_10 ;
return V_3 ;
}
