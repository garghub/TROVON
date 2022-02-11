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
T_1 V_29 , V_30 , V_31 , V_32 = 0x10 , V_33 ;
if ( V_18 || V_17 ) {
F_3 ( & V_2 -> V_13 , L_18
L_19 ) ;
return - V_34 ;
}
V_33 = ( V_27 ) ? 0x28 : 0x2c ;
if ( ! F_6 ( V_28 , 2 , L_20 ) ) {
F_3 ( & V_2 -> V_13 , L_21
L_22 , V_28 ) ;
return - V_24 ;
}
F_15 ( V_33 , V_28 ) ;
V_29 = F_16 ( V_28 + 1 ) ;
F_15 ( V_33 + 1 , V_28 ) ;
V_30 = F_16 ( V_28 + 1 ) ;
F_12 ( V_28 , 2 ) ;
if ( ( V_29 & 1 ) == 0 ) {
F_3 ( & V_2 -> V_13 ,
L_12 ) ;
return - V_20 ;
}
V_6 = ( ( V_30 << 8 ) | V_29 ) & 0xffe0 ;
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_8 ,
V_6 ) ;
return - V_24 ;
}
if ( V_27 ) {
F_10 ( & V_2 -> V_13 ,
L_23 , V_6 ) ;
return V_6 ;
}
if ( ! F_6 ( V_6 + V_32 , 1 , L_24 ) ) {
F_3 ( & V_2 -> V_13 , L_25
L_22 , V_6 + V_32 ) ;
F_12 ( V_6 , V_21 ) ;
return - V_24 ;
}
V_31 = F_16 ( V_6 + V_32 ) ;
F_12 ( V_6 + V_32 , 1 ) ;
if ( V_31 & 1 )
F_13 ( & V_2 -> V_13 , L_26 ) ;
else
F_13 ( & V_2 -> V_13 , L_27 ) ;
F_10 ( & V_2 -> V_13 ,
L_17 ,
V_6 , V_31 >> 4 ) ;
return V_6 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned short V_35 )
{
unsigned short V_6 ;
F_4 ( V_2 , V_35 , & V_6 ) ;
if ( ( V_6 & 1 ) == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_28 ) ;
return - V_20 ;
}
V_6 &= 0xfff0 ;
if ( V_6 == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_29 ) ;
return - V_20 ;
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_30
L_31 , V_6 ) ;
return - V_24 ;
}
F_10 ( & V_2 -> V_13 ,
L_32 ,
V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_36 * V_37 )
{
struct V_38 * V_39 = F_19 ( V_37 ) ;
unsigned short V_6 = V_39 -> V_40 ;
int V_5 ;
int V_41 = 0 ;
int V_42 = 0 ;
F_13 ( & V_37 -> V_13 , L_33
L_34 , F_16 ( V_43 ) ,
F_16 ( V_44 ) , F_16 ( V_45 ) , F_16 ( V_46 ) ,
F_16 ( V_47 ) ) ;
if ( ( V_5 = F_16 ( V_48 ) ) != 0x00 ) {
F_13 ( & V_37 -> V_13 , L_35
L_36 , V_5 ) ;
F_15 ( V_5 , V_48 ) ;
if ( ( V_5 = F_16 ( V_48 ) ) != 0x00 ) {
F_3 ( & V_37 -> V_13 , L_37 , V_5 ) ;
return - V_24 ;
} else {
F_13 ( & V_37 -> V_13 , L_38 ) ;
}
}
F_15 ( F_20 ( V_43 ) | 0x040 , V_43 ) ;
if ( V_11 )
F_21 ( 2 ) ;
else
F_21 ( 1 ) ;
while ( ( ++ V_42 < V_49 ) &&
( ( V_5 = F_16 ( V_48 ) ) & 0x01 ) )
F_21 ( 1 ) ;
if ( V_42 == V_49 ) {
F_3 ( & V_37 -> V_13 , L_39 ) ;
V_41 = - V_50 ;
}
if ( V_5 & 0x10 ) {
V_41 = - V_51 ;
F_3 ( & V_37 -> V_13 , L_40 ) ;
}
if ( V_5 & 0x08 ) {
V_41 = - V_51 ;
F_13 ( & V_37 -> V_13 , L_41
L_42 ) ;
}
if ( V_5 & 0x04 ) {
V_41 = - V_52 ;
F_13 ( & V_37 -> V_13 , L_43 ) ;
}
if ( F_16 ( V_48 ) != 0x00 )
F_15 ( F_20 ( V_48 ) , V_48 ) ;
if ( ( V_5 = F_16 ( V_48 ) ) != 0x00 ) {
F_3 ( & V_37 -> V_13 , L_44
L_45 , V_5 ) ;
}
F_13 ( & V_37 -> V_13 , L_46
L_34 , F_16 ( V_43 ) ,
F_16 ( V_44 ) , F_16 ( V_45 ) , F_16 ( V_46 ) ,
F_16 ( V_47 ) ) ;
return V_41 ;
}
static T_2 F_22 ( struct V_36 * V_53 , T_3 V_54 ,
unsigned short V_55 , char V_56 ,
T_1 V_57 , int V_58 , union V_59 * V_60 )
{
struct V_38 * V_39 = F_19 ( V_53 ) ;
unsigned short V_6 = V_39 -> V_40 ;
int V_61 , V_62 ;
int V_63 ;
switch ( V_58 ) {
case V_64 :
F_15 ( ( V_54 << 1 ) | V_56 ,
V_45 ) ;
V_58 = V_65 ;
break;
case V_66 :
F_15 ( ( V_54 << 1 ) | V_56 ,
V_45 ) ;
if ( V_56 == V_67 )
F_15 ( V_57 , V_44 ) ;
V_58 = V_68 ;
break;
case V_69 :
F_15 ( ( V_54 << 1 ) | V_56 ,
V_45 ) ;
F_15 ( V_57 , V_44 ) ;
if ( V_56 == V_67 )
F_15 ( V_60 -> V_70 , V_46 ) ;
V_58 = V_71 ;
break;
case V_72 :
F_15 ( ( V_54 << 1 ) | V_56 ,
V_45 ) ;
F_15 ( V_57 , V_44 ) ;
if ( V_56 == V_67 ) {
F_15 ( V_60 -> V_73 & 0xff , V_46 ) ;
F_15 ( ( V_60 -> V_73 & 0xff00 ) >> 8 , V_47 ) ;
}
V_58 = V_74 ;
break;
case V_75 :
F_15 ( ( V_54 << 1 ) | V_56 ,
V_45 ) ;
F_15 ( V_57 , V_44 ) ;
if ( V_56 == V_67 ) {
V_62 = V_60 -> V_76 [ 0 ] ;
if ( V_62 == 0 || V_62 > V_77 )
return - V_34 ;
F_15 ( V_62 , V_46 ) ;
V_61 = F_16 ( V_43 ) ;
for ( V_61 = 1 ; V_61 <= V_62 ; V_61 ++ )
F_15 ( V_60 -> V_76 [ V_61 ] , V_78 ) ;
}
V_58 = V_79 ;
break;
default:
F_23 ( & V_53 -> V_13 , L_47 , V_58 ) ;
return - V_80 ;
}
F_15 ( ( V_58 & 0x1C ) + ( V_81 & 1 ) , V_43 ) ;
V_63 = F_18 ( V_53 ) ;
if ( V_63 )
return V_63 ;
if ( ( V_56 == V_67 ) || ( V_58 == V_65 ) )
return 0 ;
switch ( V_58 ) {
case V_68 :
case V_71 :
V_60 -> V_70 = F_16 ( V_46 ) ;
break;
case V_74 :
V_60 -> V_73 = F_16 ( V_46 ) + ( F_16 ( V_47 ) << 8 ) ;
break;
case V_79 :
V_60 -> V_76 [ 0 ] = F_16 ( V_46 ) ;
if ( V_60 -> V_76 [ 0 ] == 0 || V_60 -> V_76 [ 0 ] > V_77 )
return - V_82 ;
V_61 = F_16 ( V_43 ) ;
for ( V_61 = 1 ; V_61 <= V_60 -> V_76 [ 0 ] ; V_61 ++ )
V_60 -> V_76 [ V_61 ] = F_16 ( V_78 ) ;
break;
}
return 0 ;
}
static T_4 F_24 ( struct V_36 * V_83 )
{
return V_84 | V_85 |
V_86 | V_87 |
V_88 ;
}
static int F_25 ( struct V_1 * V_13 , unsigned short V_40 ,
struct V_36 * * V_89 )
{
struct V_36 * V_53 ;
struct V_38 * V_39 ;
int V_90 ;
V_53 = F_26 ( sizeof( * V_53 ) , V_91 ) ;
if ( V_53 == NULL ) {
F_12 ( V_40 , V_21 ) ;
return - V_92 ;
}
V_53 -> V_93 = V_94 ;
V_53 -> V_95 = V_96 | V_97 ;
V_53 -> V_98 = & V_99 ;
V_39 = F_26 ( sizeof( * V_39 ) , V_91 ) ;
if ( V_39 == NULL ) {
F_27 ( V_53 ) ;
F_12 ( V_40 , V_21 ) ;
return - V_92 ;
}
V_39 -> V_40 = V_40 ;
V_53 -> V_13 . V_100 = & V_13 -> V_13 ;
snprintf ( V_53 -> V_23 , sizeof( V_53 -> V_23 ) ,
L_48 , V_40 ) ;
F_28 ( V_53 , V_39 ) ;
V_90 = F_29 ( V_53 ) ;
if ( V_90 ) {
F_3 ( & V_13 -> V_13 , L_49 ) ;
F_27 ( V_39 ) ;
F_27 ( V_53 ) ;
F_12 ( V_40 , V_21 ) ;
return V_90 ;
}
* V_89 = V_53 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_13 , const struct V_3 * V_4 )
{
int V_90 ;
if ( ( V_13 -> V_7 == V_101 &&
V_13 -> V_9 == V_102 &&
V_13 -> V_103 >= 0x40 ) ||
V_13 -> V_7 == V_104 )
V_90 = F_14 ( V_13 , V_4 , 0 ) ;
else
V_90 = F_1 ( V_13 , V_4 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_25 ( V_13 , V_90 , & V_105 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = - V_20 ;
if ( V_13 -> V_7 == V_101 &&
V_13 -> V_9 == V_102 ) {
if ( V_13 -> V_103 < 0x40 ) {
V_90 = F_17 ( V_13 , V_4 , 0x58 ) ;
} else {
V_90 = F_14 ( V_13 , V_4 , 1 ) ;
}
}
if ( V_13 -> V_7 == V_104 &&
V_13 -> V_9 == V_106 ) {
V_90 = F_14 ( V_13 , V_4 , 1 ) ;
}
if ( V_90 > 0 ) {
F_25 ( V_13 , V_90 , & V_107 ) ;
}
return 0 ;
}
static void F_31 ( struct V_36 * V_53 )
{
struct V_38 * V_39 = F_19 ( V_53 ) ;
if ( V_39 -> V_40 ) {
F_32 ( V_53 ) ;
F_12 ( V_39 -> V_40 , V_21 ) ;
F_27 ( V_39 ) ;
F_27 ( V_53 ) ;
}
}
static void F_33 ( struct V_1 * V_13 )
{
if ( V_105 ) {
F_31 ( V_105 ) ;
V_105 = NULL ;
}
if ( V_107 ) {
F_31 ( V_107 ) ;
V_107 = NULL ;
}
}
