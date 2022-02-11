static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
unsigned char V_5 ;
unsigned short V_6 ;
if ( ( V_2 -> V_7 == V_8 ) &&
( V_2 -> V_9 == V_10 ) )
V_11 = 1 ;
if ( F_2 ( V_12 ) ) {
F_3 ( & V_2 -> V_13 ,
L_1 ) ;
return - V_14 ;
}
if ( F_2 ( V_15 ) &&
V_2 -> V_7 == V_16 ) {
F_3 ( & V_2 -> V_13 , L_2
L_3
L_4 ) ;
return - V_14 ;
}
if ( V_17 ) {
V_6 = V_17 & 0xfff0 ;
V_18 = 0 ;
} else {
F_4 ( V_2 , V_19 , & V_6 ) ;
V_6 &= 0xfff0 ;
if( V_6 == 0 ) {
F_3 ( & V_2 -> V_13 , L_5
L_6
L_7 ) ;
return - V_20 ;
}
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_8 ,
V_6 ) ;
return - V_24 ;
}
F_7 ( V_2 , V_25 , & V_5 ) ;
if ( V_17 ) {
F_8 ( V_2 , V_25 , V_5 & 0xfe ) ;
F_9 ( V_2 , V_19 , V_6 ) ;
F_8 ( V_2 , V_25 , V_5 | 0x01 ) ;
F_10 ( & V_2 -> V_13 , L_9
L_10 , V_6 ) ;
} else if ( ( V_5 & 1 ) == 0 ) {
if ( V_18 ) {
F_8 ( V_2 , V_25 ,
V_5 | 1 ) ;
F_11 ( & V_2 -> V_13 ,
L_11 ) ;
} else {
F_3 ( & V_2 -> V_13 ,
L_12 ) ;
F_12 ( V_6 , V_21 ) ;
return - V_20 ;
}
}
if ( ( ( V_5 & 0x0E ) == 8 ) || ( ( V_5 & 0x0E ) == 2 ) )
F_13 ( & V_2 -> V_13 , L_13 ) ;
else if ( ( V_5 & 0x0E ) == 0 )
F_13 ( & V_2 -> V_13 , L_14 ) ;
else
F_3 ( & V_2 -> V_13 , L_15
L_16 ) ;
F_7 ( V_2 , V_26 , & V_5 ) ;
F_10 ( & V_2 -> V_13 ,
L_17 ,
V_6 , V_5 ) ;
return V_6 ;
}
static int F_14 ( struct V_1 * V_2 ,
const struct V_3 * V_4 , T_1 V_27 )
{
unsigned short V_6 ;
unsigned short V_28 = 0xcd6 ;
T_1 V_29 , V_30 , V_31 , V_32 ;
T_1 V_33 , V_34 = 0x10 ;
if ( V_18 || V_17 ) {
F_3 ( & V_2 -> V_13 , L_18
L_19 ) ;
return - V_35 ;
}
if ( ( V_2 -> V_7 == V_36 &&
V_2 -> V_9 == V_37 &&
V_2 -> V_38 >= 0x41 ) ||
( V_2 -> V_7 == V_36 &&
V_2 -> V_9 == V_39 &&
V_2 -> V_38 >= 0x49 ) )
V_31 = 0x00 ;
else
V_31 = ( V_27 ) ? 0x28 : 0x2c ;
if ( ! F_6 ( V_28 , 2 , L_20 ) ) {
F_3 ( & V_2 -> V_13 , L_21
L_22 , V_28 ) ;
return - V_24 ;
}
F_15 ( V_31 , V_28 ) ;
V_29 = F_16 ( V_28 + 1 ) ;
F_15 ( V_31 + 1 , V_28 ) ;
V_30 = F_16 ( V_28 + 1 ) ;
F_12 ( V_28 , 2 ) ;
if ( ! V_31 ) {
V_32 = V_29 & 0x10 ;
V_6 = V_30 << 8 ;
if ( V_27 )
V_6 |= 0x20 ;
} else {
V_32 = V_29 & 0x01 ;
V_6 = ( ( V_30 << 8 ) | V_29 ) & 0xffe0 ;
}
if ( ! V_32 ) {
F_3 ( & V_2 -> V_13 ,
L_12 ) ;
return - V_20 ;
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_8 ,
V_6 ) ;
return - V_24 ;
}
if ( V_27 ) {
F_10 ( & V_2 -> V_13 ,
L_23 ,
V_6 ) ;
return V_6 ;
}
if ( ! F_6 ( V_6 + V_34 , 1 , L_24 ) ) {
F_3 ( & V_2 -> V_13 , L_25
L_22 , V_6 + V_34 ) ;
F_12 ( V_6 , V_21 ) ;
return - V_24 ;
}
V_33 = F_16 ( V_6 + V_34 ) ;
F_12 ( V_6 + V_34 , 1 ) ;
if ( V_33 & 1 )
F_13 ( & V_2 -> V_13 , L_13 ) ;
else
F_13 ( & V_2 -> V_13 , L_14 ) ;
F_10 ( & V_2 -> V_13 ,
L_17 ,
V_6 , V_33 >> 4 ) ;
return V_6 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned short V_40 )
{
unsigned short V_6 ;
F_4 ( V_2 , V_40 , & V_6 ) ;
if ( ( V_6 & 1 ) == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_26 ) ;
return - V_20 ;
}
V_6 &= 0xfff0 ;
if ( V_6 == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_27 ) ;
return - V_20 ;
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_28
L_29 , V_6 ) ;
return - V_24 ;
}
F_10 ( & V_2 -> V_13 ,
L_23 ,
V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_41 * V_42 )
{
struct V_43 * V_44 = F_19 ( V_42 ) ;
unsigned short V_6 = V_44 -> V_45 ;
int V_5 ;
int V_46 = 0 ;
int V_47 = 0 ;
F_13 ( & V_42 -> V_13 , L_30
L_31 , F_16 ( V_48 ) ,
F_16 ( V_49 ) , F_16 ( V_50 ) , F_16 ( V_51 ) ,
F_16 ( V_52 ) ) ;
if ( ( V_5 = F_16 ( V_53 ) ) != 0x00 ) {
F_13 ( & V_42 -> V_13 , L_32
L_33 , V_5 ) ;
F_15 ( V_5 , V_53 ) ;
if ( ( V_5 = F_16 ( V_53 ) ) != 0x00 ) {
F_3 ( & V_42 -> V_13 , L_34 , V_5 ) ;
return - V_24 ;
} else {
F_13 ( & V_42 -> V_13 , L_35 ) ;
}
}
F_15 ( F_20 ( V_48 ) | 0x040 , V_48 ) ;
if ( V_11 )
F_21 ( 2 ) ;
else
F_21 ( 1 ) ;
while ( ( ++ V_47 < V_54 ) &&
( ( V_5 = F_16 ( V_53 ) ) & 0x01 ) )
F_21 ( 1 ) ;
if ( V_47 == V_54 ) {
F_3 ( & V_42 -> V_13 , L_36 ) ;
V_46 = - V_55 ;
}
if ( V_5 & 0x10 ) {
V_46 = - V_56 ;
F_3 ( & V_42 -> V_13 , L_37 ) ;
}
if ( V_5 & 0x08 ) {
V_46 = - V_56 ;
F_13 ( & V_42 -> V_13 , L_38
L_39 ) ;
}
if ( V_5 & 0x04 ) {
V_46 = - V_57 ;
F_13 ( & V_42 -> V_13 , L_40 ) ;
}
if ( F_16 ( V_53 ) != 0x00 )
F_15 ( F_20 ( V_53 ) , V_53 ) ;
if ( ( V_5 = F_16 ( V_53 ) ) != 0x00 ) {
F_3 ( & V_42 -> V_13 , L_41
L_42 , V_5 ) ;
}
F_13 ( & V_42 -> V_13 , L_43
L_31 , F_16 ( V_48 ) ,
F_16 ( V_49 ) , F_16 ( V_50 ) , F_16 ( V_51 ) ,
F_16 ( V_52 ) ) ;
return V_46 ;
}
static T_2 F_22 ( struct V_41 * V_58 , T_3 V_59 ,
unsigned short V_60 , char V_61 ,
T_1 V_62 , int V_63 , union V_64 * V_65 )
{
struct V_43 * V_44 = F_19 ( V_58 ) ;
unsigned short V_6 = V_44 -> V_45 ;
int V_66 , V_67 ;
int V_68 ;
switch ( V_63 ) {
case V_69 :
F_15 ( ( V_59 << 1 ) | V_61 ,
V_50 ) ;
V_63 = V_70 ;
break;
case V_71 :
F_15 ( ( V_59 << 1 ) | V_61 ,
V_50 ) ;
if ( V_61 == V_72 )
F_15 ( V_62 , V_49 ) ;
V_63 = V_73 ;
break;
case V_74 :
F_15 ( ( V_59 << 1 ) | V_61 ,
V_50 ) ;
F_15 ( V_62 , V_49 ) ;
if ( V_61 == V_72 )
F_15 ( V_65 -> V_75 , V_51 ) ;
V_63 = V_76 ;
break;
case V_77 :
F_15 ( ( V_59 << 1 ) | V_61 ,
V_50 ) ;
F_15 ( V_62 , V_49 ) ;
if ( V_61 == V_72 ) {
F_15 ( V_65 -> V_78 & 0xff , V_51 ) ;
F_15 ( ( V_65 -> V_78 & 0xff00 ) >> 8 , V_52 ) ;
}
V_63 = V_79 ;
break;
case V_80 :
F_15 ( ( V_59 << 1 ) | V_61 ,
V_50 ) ;
F_15 ( V_62 , V_49 ) ;
if ( V_61 == V_72 ) {
V_67 = V_65 -> V_81 [ 0 ] ;
if ( V_67 == 0 || V_67 > V_82 )
return - V_35 ;
F_15 ( V_67 , V_51 ) ;
V_66 = F_16 ( V_48 ) ;
for ( V_66 = 1 ; V_66 <= V_67 ; V_66 ++ )
F_15 ( V_65 -> V_81 [ V_66 ] , V_83 ) ;
}
V_63 = V_84 ;
break;
default:
F_23 ( & V_58 -> V_13 , L_44 , V_63 ) ;
return - V_85 ;
}
F_15 ( ( V_63 & 0x1C ) + ( V_86 & 1 ) , V_48 ) ;
V_68 = F_18 ( V_58 ) ;
if ( V_68 )
return V_68 ;
if ( ( V_61 == V_72 ) || ( V_63 == V_70 ) )
return 0 ;
switch ( V_63 ) {
case V_73 :
case V_76 :
V_65 -> V_75 = F_16 ( V_51 ) ;
break;
case V_79 :
V_65 -> V_78 = F_16 ( V_51 ) + ( F_16 ( V_52 ) << 8 ) ;
break;
case V_84 :
V_65 -> V_81 [ 0 ] = F_16 ( V_51 ) ;
if ( V_65 -> V_81 [ 0 ] == 0 || V_65 -> V_81 [ 0 ] > V_82 )
return - V_87 ;
V_66 = F_16 ( V_48 ) ;
for ( V_66 = 1 ; V_66 <= V_65 -> V_81 [ 0 ] ; V_66 ++ )
V_65 -> V_81 [ V_66 ] = F_16 ( V_83 ) ;
break;
}
return 0 ;
}
static T_4 F_24 ( struct V_41 * V_88 )
{
return V_89 | V_90 |
V_91 | V_92 |
V_93 ;
}
static int F_25 ( struct V_1 * V_13 , unsigned short V_45 ,
struct V_41 * * V_94 )
{
struct V_41 * V_58 ;
struct V_43 * V_44 ;
int V_95 ;
V_58 = F_26 ( sizeof( * V_58 ) , V_96 ) ;
if ( V_58 == NULL ) {
F_12 ( V_45 , V_21 ) ;
return - V_97 ;
}
V_58 -> V_98 = V_99 ;
V_58 -> V_100 = V_101 | V_102 ;
V_58 -> V_103 = & V_104 ;
V_44 = F_26 ( sizeof( * V_44 ) , V_96 ) ;
if ( V_44 == NULL ) {
F_27 ( V_58 ) ;
F_12 ( V_45 , V_21 ) ;
return - V_97 ;
}
V_44 -> V_45 = V_45 ;
V_58 -> V_13 . V_105 = & V_13 -> V_13 ;
snprintf ( V_58 -> V_23 , sizeof( V_58 -> V_23 ) ,
L_45 , V_45 ) ;
F_28 ( V_58 , V_44 ) ;
V_95 = F_29 ( V_58 ) ;
if ( V_95 ) {
F_3 ( & V_13 -> V_13 , L_46 ) ;
F_27 ( V_44 ) ;
F_27 ( V_58 ) ;
F_12 ( V_45 , V_21 ) ;
return V_95 ;
}
* V_94 = V_58 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_13 , const struct V_3 * V_4 )
{
int V_95 ;
if ( ( V_13 -> V_7 == V_106 &&
V_13 -> V_9 == V_107 &&
V_13 -> V_38 >= 0x40 ) ||
V_13 -> V_7 == V_36 )
V_95 = F_14 ( V_13 , V_4 , 0 ) ;
else
V_95 = F_1 ( V_13 , V_4 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_25 ( V_13 , V_95 , & V_108 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = - V_20 ;
if ( V_13 -> V_7 == V_106 &&
V_13 -> V_9 == V_107 ) {
if ( V_13 -> V_38 < 0x40 ) {
V_95 = F_17 ( V_13 , V_4 , 0x58 ) ;
} else {
V_95 = F_14 ( V_13 , V_4 , 1 ) ;
}
}
if ( V_13 -> V_7 == V_36 &&
V_13 -> V_9 == V_37 ) {
V_95 = F_14 ( V_13 , V_4 , 1 ) ;
}
if ( V_95 > 0 ) {
F_25 ( V_13 , V_95 , & V_109 ) ;
}
return 0 ;
}
static void F_31 ( struct V_41 * V_58 )
{
struct V_43 * V_44 = F_19 ( V_58 ) ;
if ( V_44 -> V_45 ) {
F_32 ( V_58 ) ;
F_12 ( V_44 -> V_45 , V_21 ) ;
F_27 ( V_44 ) ;
F_27 ( V_58 ) ;
}
}
static void F_33 ( struct V_1 * V_13 )
{
if ( V_108 ) {
F_31 ( V_108 ) ;
V_108 = NULL ;
}
if ( V_109 ) {
F_31 ( V_109 ) ;
V_109 = NULL ;
}
}
