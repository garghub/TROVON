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
T_1 V_28 , V_29 , V_30 , V_31 , V_32 ;
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
V_30 = 0x00 ;
else
V_30 = ( V_27 ) ? 0x28 : 0x2c ;
F_15 ( & V_40 ) ;
F_16 ( V_30 , V_41 ) ;
V_28 = F_17 ( V_41 + 1 ) ;
F_16 ( V_30 + 1 , V_41 ) ;
V_29 = F_17 ( V_41 + 1 ) ;
F_18 ( & V_40 ) ;
if ( ! V_30 ) {
V_31 = V_28 & 0x10 ;
V_6 = V_29 << 8 ;
if ( V_27 )
V_6 |= 0x20 ;
} else {
V_31 = V_28 & 0x01 ;
V_6 = ( ( V_29 << 8 ) | V_28 ) & 0xffe0 ;
}
if ( ! V_31 ) {
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
L_20 ,
V_6 ) ;
return V_6 ;
}
if ( ! F_6 ( V_6 + V_34 , 1 , L_21 ) ) {
F_3 ( & V_2 -> V_13 , L_22
L_23 , V_6 + V_34 ) ;
F_12 ( V_6 , V_21 ) ;
return - V_24 ;
}
V_33 = F_17 ( V_6 + V_34 ) ;
F_12 ( V_6 + V_34 , 1 ) ;
if ( V_33 & 1 )
F_13 ( & V_2 -> V_13 , L_13 ) ;
else
F_13 ( & V_2 -> V_13 , L_14 ) ;
F_10 ( & V_2 -> V_13 ,
L_17 ,
V_6 , V_33 >> 4 ) ;
if ( V_2 -> V_7 == V_36 ) {
V_42 = V_43 ;
} else {
F_15 ( & V_40 ) ;
F_16 ( V_44 , V_41 ) ;
V_32 = F_17 ( V_41 + 1 ) ;
V_42 = ( V_32 & 0x01 ) ?
V_43 :
V_45 ;
F_18 ( & V_40 ) ;
}
F_10 ( & V_2 -> V_13 ,
L_24 ,
( unsigned int ) V_42 ) ;
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned short V_46 )
{
unsigned short V_6 ;
F_4 ( V_2 , V_46 , & V_6 ) ;
if ( ( V_6 & 1 ) == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_25 ) ;
return - V_20 ;
}
V_6 &= 0xfff0 ;
if ( V_6 == 0 ) {
F_13 ( & V_2 -> V_13 ,
L_26 ) ;
return - V_20 ;
}
if ( F_5 ( V_6 , V_21 , V_22 . V_23 ) )
return - V_20 ;
if ( ! F_6 ( V_6 , V_21 , V_22 . V_23 ) ) {
F_3 ( & V_2 -> V_13 , L_27
L_28 , V_6 ) ;
return - V_24 ;
}
F_10 ( & V_2 -> V_13 ,
L_20 ,
V_6 ) ;
return V_6 ;
}
static int F_20 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = F_21 ( V_48 ) ;
unsigned short V_6 = V_50 -> V_51 ;
int V_5 ;
int V_52 = 0 ;
int V_53 = 0 ;
F_13 ( & V_48 -> V_13 , L_29
L_30 , F_17 ( V_54 ) ,
F_17 ( V_55 ) , F_17 ( V_56 ) , F_17 ( V_57 ) ,
F_17 ( V_58 ) ) ;
if ( ( V_5 = F_17 ( V_59 ) ) != 0x00 ) {
F_13 ( & V_48 -> V_13 , L_31
L_32 , V_5 ) ;
F_16 ( V_5 , V_59 ) ;
if ( ( V_5 = F_17 ( V_59 ) ) != 0x00 ) {
F_3 ( & V_48 -> V_13 , L_33 , V_5 ) ;
return - V_24 ;
} else {
F_13 ( & V_48 -> V_13 , L_34 ) ;
}
}
F_16 ( F_22 ( V_54 ) | 0x040 , V_54 ) ;
if ( V_11 )
F_23 ( 2 ) ;
else
F_23 ( 1 ) ;
while ( ( ++ V_53 < V_60 ) &&
( ( V_5 = F_17 ( V_59 ) ) & 0x01 ) )
F_23 ( 1 ) ;
if ( V_53 == V_60 ) {
F_3 ( & V_48 -> V_13 , L_35 ) ;
V_52 = - V_61 ;
}
if ( V_5 & 0x10 ) {
V_52 = - V_62 ;
F_3 ( & V_48 -> V_13 , L_36 ) ;
}
if ( V_5 & 0x08 ) {
V_52 = - V_62 ;
F_13 ( & V_48 -> V_13 , L_37
L_38 ) ;
}
if ( V_5 & 0x04 ) {
V_52 = - V_63 ;
F_13 ( & V_48 -> V_13 , L_39 ) ;
}
if ( F_17 ( V_59 ) != 0x00 )
F_16 ( F_22 ( V_59 ) , V_59 ) ;
if ( ( V_5 = F_17 ( V_59 ) ) != 0x00 ) {
F_3 ( & V_48 -> V_13 , L_40
L_41 , V_5 ) ;
}
F_13 ( & V_48 -> V_13 , L_42
L_30 , F_17 ( V_54 ) ,
F_17 ( V_55 ) , F_17 ( V_56 ) , F_17 ( V_57 ) ,
F_17 ( V_58 ) ) ;
return V_52 ;
}
static T_2 F_24 ( struct V_47 * V_64 , T_3 V_65 ,
unsigned short V_66 , char V_67 ,
T_1 V_68 , int V_69 , union V_70 * V_71 )
{
struct V_49 * V_50 = F_21 ( V_64 ) ;
unsigned short V_6 = V_50 -> V_51 ;
int V_72 , V_73 ;
int V_74 ;
switch ( V_69 ) {
case V_75 :
F_16 ( ( V_65 << 1 ) | V_67 ,
V_56 ) ;
V_69 = V_76 ;
break;
case V_77 :
F_16 ( ( V_65 << 1 ) | V_67 ,
V_56 ) ;
if ( V_67 == V_78 )
F_16 ( V_68 , V_55 ) ;
V_69 = V_79 ;
break;
case V_80 :
F_16 ( ( V_65 << 1 ) | V_67 ,
V_56 ) ;
F_16 ( V_68 , V_55 ) ;
if ( V_67 == V_78 )
F_16 ( V_71 -> V_81 , V_57 ) ;
V_69 = V_82 ;
break;
case V_83 :
F_16 ( ( V_65 << 1 ) | V_67 ,
V_56 ) ;
F_16 ( V_68 , V_55 ) ;
if ( V_67 == V_78 ) {
F_16 ( V_71 -> V_84 & 0xff , V_57 ) ;
F_16 ( ( V_71 -> V_84 & 0xff00 ) >> 8 , V_58 ) ;
}
V_69 = V_85 ;
break;
case V_86 :
F_16 ( ( V_65 << 1 ) | V_67 ,
V_56 ) ;
F_16 ( V_68 , V_55 ) ;
if ( V_67 == V_78 ) {
V_73 = V_71 -> V_87 [ 0 ] ;
if ( V_73 == 0 || V_73 > V_88 )
return - V_35 ;
F_16 ( V_73 , V_57 ) ;
F_17 ( V_54 ) ;
for ( V_72 = 1 ; V_72 <= V_73 ; V_72 ++ )
F_16 ( V_71 -> V_87 [ V_72 ] , V_89 ) ;
}
V_69 = V_90 ;
break;
default:
F_25 ( & V_64 -> V_13 , L_43 , V_69 ) ;
return - V_91 ;
}
F_16 ( ( V_69 & 0x1C ) + ( V_92 & 1 ) , V_54 ) ;
V_74 = F_20 ( V_64 ) ;
if ( V_74 )
return V_74 ;
if ( ( V_67 == V_78 ) || ( V_69 == V_76 ) )
return 0 ;
switch ( V_69 ) {
case V_79 :
case V_82 :
V_71 -> V_81 = F_17 ( V_57 ) ;
break;
case V_85 :
V_71 -> V_84 = F_17 ( V_57 ) + ( F_17 ( V_58 ) << 8 ) ;
break;
case V_90 :
V_71 -> V_87 [ 0 ] = F_17 ( V_57 ) ;
if ( V_71 -> V_87 [ 0 ] == 0 || V_71 -> V_87 [ 0 ] > V_88 )
return - V_93 ;
F_17 ( V_54 ) ;
for ( V_72 = 1 ; V_72 <= V_71 -> V_87 [ 0 ] ; V_72 ++ )
V_71 -> V_87 [ V_72 ] = F_17 ( V_89 ) ;
break;
}
return 0 ;
}
static T_2 F_26 ( struct V_47 * V_64 , T_3 V_65 ,
unsigned short V_66 , char V_67 ,
T_1 V_68 , int V_69 , union V_70 * V_71 )
{
struct V_49 * V_50 = F_21 ( V_64 ) ;
T_1 V_28 ;
T_1 V_94 ;
int V_95 ;
F_15 ( & V_40 ) ;
F_16 ( V_42 , V_41 ) ;
V_28 = F_17 ( V_41 + 1 ) ;
V_94 = V_50 -> V_94 ;
if ( ( V_28 & V_96 ) != V_94 )
F_16 ( ( V_28 & ~ V_96 ) | V_94 ,
V_41 + 1 ) ;
V_95 = F_24 ( V_64 , V_65 , V_66 , V_67 ,
V_68 , V_69 , V_71 ) ;
F_16 ( V_28 , V_41 + 1 ) ;
F_18 ( & V_40 ) ;
return V_95 ;
}
static T_4 F_27 ( struct V_47 * V_97 )
{
return V_98 | V_99 |
V_100 | V_101 |
V_102 ;
}
static int F_28 ( struct V_1 * V_13 , unsigned short V_51 ,
bool V_103 , T_1 V_94 ,
const char * V_23 , struct V_47 * * V_104 )
{
struct V_47 * V_64 ;
struct V_49 * V_50 ;
int V_95 ;
V_64 = F_29 ( sizeof( * V_64 ) , V_105 ) ;
if ( V_64 == NULL ) {
F_12 ( V_51 , V_21 ) ;
return - V_106 ;
}
V_64 -> V_107 = V_108 ;
V_64 -> V_109 = V_110 | V_111 ;
V_64 -> V_112 = V_103 ? & V_113
: & V_114 ;
V_50 = F_29 ( sizeof( * V_50 ) , V_105 ) ;
if ( V_50 == NULL ) {
F_30 ( V_64 ) ;
F_12 ( V_51 , V_21 ) ;
return - V_106 ;
}
V_50 -> V_51 = V_51 ;
V_50 -> V_103 = V_103 ;
V_50 -> V_94 = V_94 << 1 ;
V_64 -> V_13 . V_115 = & V_13 -> V_13 ;
snprintf ( V_64 -> V_23 , sizeof( V_64 -> V_23 ) ,
L_44 , V_23 , V_51 ) ;
F_31 ( V_64 , V_50 ) ;
V_95 = F_32 ( V_64 ) ;
if ( V_95 ) {
F_3 ( & V_13 -> V_13 , L_45 ) ;
F_30 ( V_50 ) ;
F_30 ( V_64 ) ;
F_12 ( V_51 , V_21 ) ;
return V_95 ;
}
* V_104 = V_64 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_13 , unsigned short V_51 )
{
struct V_49 * V_50 ;
int V_94 ;
int V_95 ;
for ( V_94 = 0 ; V_94 < V_116 ; V_94 ++ ) {
V_95 = F_28 ( V_13 , V_51 , true , V_94 ,
V_117 [ V_94 ] ,
& V_118 [ V_94 ] ) ;
if ( V_95 < 0 )
goto error;
}
return V_95 ;
error:
F_3 ( & V_13 -> V_13 ,
L_46 ) ;
while ( -- V_94 >= 0 ) {
V_50 = F_21 ( V_118 [ V_94 ] ) ;
if ( V_50 -> V_51 ) {
F_34 ( V_118 [ V_94 ] ) ;
F_30 ( V_50 ) ;
F_30 ( V_118 [ V_94 ] ) ;
V_118 [ V_94 ] = NULL ;
}
}
return V_95 ;
}
static int F_35 ( struct V_1 * V_13 , const struct V_3 * V_4 )
{
int V_95 ;
bool V_119 = false ;
if ( ( V_13 -> V_7 == V_120 &&
V_13 -> V_9 == V_121 &&
V_13 -> V_38 >= 0x40 ) ||
V_13 -> V_7 == V_36 ) {
V_119 = true ;
if ( ! F_6 ( V_41 , 2 , L_47 ) ) {
F_3 ( & V_13 -> V_13 ,
L_48 ,
V_41 ) ;
return - V_24 ;
}
V_95 = F_14 ( V_13 , V_4 , 0 ) ;
if ( V_95 < 0 ) {
F_12 ( V_41 , 2 ) ;
return V_95 ;
}
V_95 = F_33 ( V_13 , V_95 ) ;
if ( V_95 < 0 ) {
F_12 ( V_41 , 2 ) ;
return V_95 ;
}
} else {
V_95 = F_1 ( V_13 , V_4 ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_28 ( V_13 , V_95 , false , 0 , L_49 ,
& V_118 [ 0 ] ) ;
if ( V_95 < 0 )
return V_95 ;
}
V_95 = - V_20 ;
if ( V_13 -> V_7 == V_120 &&
V_13 -> V_9 == V_121 ) {
if ( V_13 -> V_38 < 0x40 ) {
V_95 = F_19 ( V_13 , V_4 , 0x58 ) ;
} else {
V_95 = F_14 ( V_13 , V_4 , 1 ) ;
}
}
if ( V_13 -> V_7 == V_36 &&
V_13 -> V_9 == V_37 ) {
V_95 = F_14 ( V_13 , V_4 , 1 ) ;
}
if ( V_95 > 0 ) {
F_28 ( V_13 , V_95 , false , 0 ,
V_119 ? V_122 : L_49 ,
& V_123 ) ;
}
return 0 ;
}
static void F_36 ( struct V_47 * V_64 )
{
struct V_49 * V_50 = F_21 ( V_64 ) ;
if ( V_50 -> V_51 ) {
F_34 ( V_64 ) ;
if ( V_50 -> V_94 == ( 0 << 1 ) ) {
F_12 ( V_50 -> V_51 , V_21 ) ;
if ( V_50 -> V_103 )
F_12 ( V_41 , 2 ) ;
}
F_30 ( V_50 ) ;
F_30 ( V_64 ) ;
}
}
static void F_37 ( struct V_1 * V_13 )
{
int V_94 = V_116 ;
while ( -- V_94 >= 0 ) {
if ( V_118 [ V_94 ] ) {
F_36 ( V_118 [ V_94 ] ) ;
V_118 [ V_94 ] = NULL ;
}
}
if ( V_123 ) {
F_36 ( V_123 ) ;
V_123 = NULL ;
}
}
