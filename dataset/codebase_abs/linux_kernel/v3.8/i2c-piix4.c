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
const struct V_3 * V_4 )
{
unsigned short V_6 ;
unsigned short V_27 = 0xcd6 ;
T_1 V_28 , V_29 , V_30 , V_31 = 0x10 , V_32 = 0x2c ;
if ( V_18 || V_17 ) {
F_3 ( & V_2 -> V_13 , L_18
L_19 ) ;
return - V_33 ;
}
if ( ! F_6 ( V_27 , 2 , L_20 ) ) {
F_3 ( & V_2 -> V_13 , L_21
L_22 , V_27 ) ;
return - V_24 ;
}
F_15 ( V_32 , V_27 ) ;
V_28 = F_16 ( V_27 + 1 ) ;
F_15 ( V_32 + 1 , V_27 ) ;
V_29 = F_16 ( V_27 + 1 ) ;
F_12 ( V_27 , 2 ) ;
if ( ( V_28 & 1 ) == 0 ) {
F_3 ( & V_2 -> V_13 ,
L_12 ) ;
return - V_20 ;
}
V_6 = ( ( V_29 << 8 ) | V_28 ) & 0xffe0 ;
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_8 ,
V_6 ) ;
return - V_24 ;
}
if ( ! F_6 ( V_6 + V_31 , 1 , L_23 ) ) {
F_3 ( & V_2 -> V_13 , L_24
L_22 , V_6 + V_31 ) ;
F_12 ( V_6 , V_21 ) ;
return - V_24 ;
}
V_30 = F_16 ( V_6 + V_31 ) ;
F_12 ( V_6 + V_31 , 1 ) ;
if ( V_30 & 1 )
F_13 ( & V_2 -> V_13 , L_25 ) ;
else
F_13 ( & V_2 -> V_13 , L_26 ) ;
F_10 ( & V_2 -> V_13 ,
L_17 ,
V_6 , V_30 >> 4 ) ;
return V_6 ;
}
static int F_17 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned short V_34 )
{
unsigned short V_6 ;
F_4 ( V_2 , V_34 , & V_6 ) ;
if ( ( V_6 & 1 ) == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_27 ) ;
return - V_20 ;
}
V_6 &= 0xfff0 ;
if ( V_6 == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_28 ) ;
return - V_20 ;
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_29
L_30 , V_6 ) ;
return - V_24 ;
}
F_10 ( & V_2 -> V_13 ,
L_31 ,
V_6 ) ;
return V_6 ;
}
static int F_18 ( struct V_35 * V_36 )
{
struct V_37 * V_38 = F_19 ( V_36 ) ;
unsigned short V_6 = V_38 -> V_39 ;
int V_5 ;
int V_40 = 0 ;
int V_41 = 0 ;
F_13 ( & V_36 -> V_13 , L_32
L_33 , F_16 ( V_42 ) ,
F_16 ( V_43 ) , F_16 ( V_44 ) , F_16 ( V_45 ) ,
F_16 ( V_46 ) ) ;
if ( ( V_5 = F_16 ( V_47 ) ) != 0x00 ) {
F_13 ( & V_36 -> V_13 , L_34
L_35 , V_5 ) ;
F_15 ( V_5 , V_47 ) ;
if ( ( V_5 = F_16 ( V_47 ) ) != 0x00 ) {
F_3 ( & V_36 -> V_13 , L_36 , V_5 ) ;
return - V_24 ;
} else {
F_13 ( & V_36 -> V_13 , L_37 ) ;
}
}
F_15 ( F_20 ( V_42 ) | 0x040 , V_42 ) ;
if ( V_11 )
F_21 ( 2 ) ;
else
F_21 ( 1 ) ;
while ( ( ++ V_41 < V_48 ) &&
( ( V_5 = F_16 ( V_47 ) ) & 0x01 ) )
F_21 ( 1 ) ;
if ( V_41 == V_48 ) {
F_3 ( & V_36 -> V_13 , L_38 ) ;
V_40 = - V_49 ;
}
if ( V_5 & 0x10 ) {
V_40 = - V_50 ;
F_3 ( & V_36 -> V_13 , L_39 ) ;
}
if ( V_5 & 0x08 ) {
V_40 = - V_50 ;
F_13 ( & V_36 -> V_13 , L_40
L_41 ) ;
}
if ( V_5 & 0x04 ) {
V_40 = - V_51 ;
F_13 ( & V_36 -> V_13 , L_42 ) ;
}
if ( F_16 ( V_47 ) != 0x00 )
F_15 ( F_20 ( V_47 ) , V_47 ) ;
if ( ( V_5 = F_16 ( V_47 ) ) != 0x00 ) {
F_3 ( & V_36 -> V_13 , L_43
L_44 , V_5 ) ;
}
F_13 ( & V_36 -> V_13 , L_45
L_33 , F_16 ( V_42 ) ,
F_16 ( V_43 ) , F_16 ( V_44 ) , F_16 ( V_45 ) ,
F_16 ( V_46 ) ) ;
return V_40 ;
}
static T_2 F_22 ( struct V_35 * V_52 , T_3 V_53 ,
unsigned short V_54 , char V_55 ,
T_1 V_56 , int V_57 , union V_58 * V_59 )
{
struct V_37 * V_38 = F_19 ( V_52 ) ;
unsigned short V_6 = V_38 -> V_39 ;
int V_60 , V_61 ;
int V_62 ;
switch ( V_57 ) {
case V_63 :
F_15 ( ( V_53 << 1 ) | V_55 ,
V_44 ) ;
V_57 = V_64 ;
break;
case V_65 :
F_15 ( ( V_53 << 1 ) | V_55 ,
V_44 ) ;
if ( V_55 == V_66 )
F_15 ( V_56 , V_43 ) ;
V_57 = V_67 ;
break;
case V_68 :
F_15 ( ( V_53 << 1 ) | V_55 ,
V_44 ) ;
F_15 ( V_56 , V_43 ) ;
if ( V_55 == V_66 )
F_15 ( V_59 -> V_69 , V_45 ) ;
V_57 = V_70 ;
break;
case V_71 :
F_15 ( ( V_53 << 1 ) | V_55 ,
V_44 ) ;
F_15 ( V_56 , V_43 ) ;
if ( V_55 == V_66 ) {
F_15 ( V_59 -> V_72 & 0xff , V_45 ) ;
F_15 ( ( V_59 -> V_72 & 0xff00 ) >> 8 , V_46 ) ;
}
V_57 = V_73 ;
break;
case V_74 :
F_15 ( ( V_53 << 1 ) | V_55 ,
V_44 ) ;
F_15 ( V_56 , V_43 ) ;
if ( V_55 == V_66 ) {
V_61 = V_59 -> V_75 [ 0 ] ;
if ( V_61 == 0 || V_61 > V_76 )
return - V_33 ;
F_15 ( V_61 , V_45 ) ;
V_60 = F_16 ( V_42 ) ;
for ( V_60 = 1 ; V_60 <= V_61 ; V_60 ++ )
F_15 ( V_59 -> V_75 [ V_60 ] , V_77 ) ;
}
V_57 = V_78 ;
break;
default:
F_23 ( & V_52 -> V_13 , L_46 , V_57 ) ;
return - V_79 ;
}
F_15 ( ( V_57 & 0x1C ) + ( V_80 & 1 ) , V_42 ) ;
V_62 = F_18 ( V_52 ) ;
if ( V_62 )
return V_62 ;
if ( ( V_55 == V_66 ) || ( V_57 == V_64 ) )
return 0 ;
switch ( V_57 ) {
case V_67 :
case V_70 :
V_59 -> V_69 = F_16 ( V_45 ) ;
break;
case V_73 :
V_59 -> V_72 = F_16 ( V_45 ) + ( F_16 ( V_46 ) << 8 ) ;
break;
case V_78 :
V_59 -> V_75 [ 0 ] = F_16 ( V_45 ) ;
if ( V_59 -> V_75 [ 0 ] == 0 || V_59 -> V_75 [ 0 ] > V_76 )
return - V_81 ;
V_60 = F_16 ( V_42 ) ;
for ( V_60 = 1 ; V_60 <= V_59 -> V_75 [ 0 ] ; V_60 ++ )
V_59 -> V_75 [ V_60 ] = F_16 ( V_77 ) ;
break;
}
return 0 ;
}
static T_4 F_24 ( struct V_35 * V_82 )
{
return V_83 | V_84 |
V_85 | V_86 |
V_87 ;
}
static int F_25 ( struct V_1 * V_13 , unsigned short V_39 ,
struct V_35 * * V_88 )
{
struct V_35 * V_52 ;
struct V_37 * V_38 ;
int V_89 ;
V_52 = F_26 ( sizeof( * V_52 ) , V_90 ) ;
if ( V_52 == NULL ) {
F_12 ( V_39 , V_21 ) ;
return - V_91 ;
}
V_52 -> V_92 = V_93 ;
V_52 -> V_94 = V_95 | V_96 ;
V_52 -> V_97 = & V_98 ;
V_38 = F_26 ( sizeof( * V_38 ) , V_90 ) ;
if ( V_38 == NULL ) {
F_27 ( V_52 ) ;
F_12 ( V_39 , V_21 ) ;
return - V_91 ;
}
V_38 -> V_39 = V_39 ;
V_52 -> V_13 . V_99 = & V_13 -> V_13 ;
snprintf ( V_52 -> V_23 , sizeof( V_52 -> V_23 ) ,
L_47 , V_39 ) ;
F_28 ( V_52 , V_38 ) ;
V_89 = F_29 ( V_52 ) ;
if ( V_89 ) {
F_3 ( & V_13 -> V_13 , L_48 ) ;
F_27 ( V_38 ) ;
F_27 ( V_52 ) ;
F_12 ( V_39 , V_21 ) ;
return V_89 ;
}
* V_88 = V_52 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_13 , const struct V_3 * V_4 )
{
int V_89 ;
if ( ( V_13 -> V_7 == V_100 &&
V_13 -> V_9 == V_101 &&
V_13 -> V_102 >= 0x40 ) ||
V_13 -> V_7 == V_103 )
V_89 = F_14 ( V_13 , V_4 ) ;
else
V_89 = F_1 ( V_13 , V_4 ) ;
if ( V_89 < 0 )
return V_89 ;
V_89 = F_25 ( V_13 , V_89 , & V_104 ) ;
if ( V_89 < 0 )
return V_89 ;
if ( V_13 -> V_7 == V_100 &&
V_13 -> V_9 == V_101 &&
V_13 -> V_102 < 0x40 ) {
V_89 = F_17 ( V_13 , V_4 , 0x58 ) ;
if ( V_89 > 0 ) {
F_25 ( V_13 , V_89 , & V_105 ) ;
}
}
return 0 ;
}
static void F_31 ( struct V_35 * V_52 )
{
struct V_37 * V_38 = F_19 ( V_52 ) ;
if ( V_38 -> V_39 ) {
F_32 ( V_52 ) ;
F_12 ( V_38 -> V_39 , V_21 ) ;
F_27 ( V_38 ) ;
F_27 ( V_52 ) ;
}
}
static void F_33 ( struct V_1 * V_13 )
{
if ( V_104 ) {
F_31 ( V_104 ) ;
V_104 = NULL ;
}
if ( V_105 ) {
F_31 ( V_105 ) ;
V_105 = NULL ;
}
}
