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
switch ( V_2 -> V_9 ) {
case V_39 :
V_42 = V_43 ;
V_44 = V_45 ;
V_46 = V_47 ;
break;
case V_37 :
default:
V_42 = V_48 ;
V_44 = V_49 ;
V_46 = V_50 ;
break;
}
} else {
F_15 ( & V_40 ) ;
F_16 ( V_51 , V_41 ) ;
V_32 = F_17 ( V_41 + 1 ) ;
V_42 = ( V_32 & 0x01 ) ?
V_48 :
V_52 ;
V_44 = V_49 ;
V_46 = V_50 ;
F_18 ( & V_40 ) ;
}
F_10 ( & V_2 -> V_13 ,
L_24 ,
( unsigned int ) V_42 ) ;
return V_6 ;
}
static int F_19 ( struct V_1 * V_2 ,
const struct V_3 * V_4 ,
unsigned short V_53 )
{
unsigned short V_6 ;
F_4 ( V_2 , V_53 , & V_6 ) ;
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
static int F_20 ( struct V_54 * V_55 )
{
struct V_56 * V_57 = F_21 ( V_55 ) ;
unsigned short V_6 = V_57 -> V_58 ;
int V_5 ;
int V_59 = 0 ;
int V_60 = 0 ;
F_13 ( & V_55 -> V_13 , L_29
L_30 , F_17 ( V_61 ) ,
F_17 ( V_62 ) , F_17 ( V_63 ) , F_17 ( V_64 ) ,
F_17 ( V_65 ) ) ;
if ( ( V_5 = F_17 ( V_66 ) ) != 0x00 ) {
F_13 ( & V_55 -> V_13 , L_31
L_32 , V_5 ) ;
F_16 ( V_5 , V_66 ) ;
if ( ( V_5 = F_17 ( V_66 ) ) != 0x00 ) {
F_3 ( & V_55 -> V_13 , L_33 , V_5 ) ;
return - V_24 ;
} else {
F_13 ( & V_55 -> V_13 , L_34 ) ;
}
}
F_16 ( F_22 ( V_61 ) | 0x040 , V_61 ) ;
if ( V_11 )
F_23 ( 2 ) ;
else
F_23 ( 1 ) ;
while ( ( ++ V_60 < V_67 ) &&
( ( V_5 = F_17 ( V_66 ) ) & 0x01 ) )
F_23 ( 1 ) ;
if ( V_60 == V_67 ) {
F_3 ( & V_55 -> V_13 , L_35 ) ;
V_59 = - V_68 ;
}
if ( V_5 & 0x10 ) {
V_59 = - V_69 ;
F_3 ( & V_55 -> V_13 , L_36 ) ;
}
if ( V_5 & 0x08 ) {
V_59 = - V_69 ;
F_13 ( & V_55 -> V_13 , L_37
L_38 ) ;
}
if ( V_5 & 0x04 ) {
V_59 = - V_70 ;
F_13 ( & V_55 -> V_13 , L_39 ) ;
}
if ( F_17 ( V_66 ) != 0x00 )
F_16 ( F_22 ( V_66 ) , V_66 ) ;
if ( ( V_5 = F_17 ( V_66 ) ) != 0x00 ) {
F_3 ( & V_55 -> V_13 , L_40
L_41 , V_5 ) ;
}
F_13 ( & V_55 -> V_13 , L_42
L_30 , F_17 ( V_61 ) ,
F_17 ( V_62 ) , F_17 ( V_63 ) , F_17 ( V_64 ) ,
F_17 ( V_65 ) ) ;
return V_59 ;
}
static T_2 F_24 ( struct V_54 * V_71 , T_3 V_72 ,
unsigned short V_73 , char V_74 ,
T_1 V_75 , int V_76 , union V_77 * V_78 )
{
struct V_56 * V_57 = F_21 ( V_71 ) ;
unsigned short V_6 = V_57 -> V_58 ;
int V_79 , V_80 ;
int V_81 ;
switch ( V_76 ) {
case V_82 :
F_16 ( ( V_72 << 1 ) | V_74 ,
V_63 ) ;
V_76 = V_83 ;
break;
case V_84 :
F_16 ( ( V_72 << 1 ) | V_74 ,
V_63 ) ;
if ( V_74 == V_85 )
F_16 ( V_75 , V_62 ) ;
V_76 = V_86 ;
break;
case V_87 :
F_16 ( ( V_72 << 1 ) | V_74 ,
V_63 ) ;
F_16 ( V_75 , V_62 ) ;
if ( V_74 == V_85 )
F_16 ( V_78 -> V_88 , V_64 ) ;
V_76 = V_89 ;
break;
case V_90 :
F_16 ( ( V_72 << 1 ) | V_74 ,
V_63 ) ;
F_16 ( V_75 , V_62 ) ;
if ( V_74 == V_85 ) {
F_16 ( V_78 -> V_91 & 0xff , V_64 ) ;
F_16 ( ( V_78 -> V_91 & 0xff00 ) >> 8 , V_65 ) ;
}
V_76 = V_92 ;
break;
case V_93 :
F_16 ( ( V_72 << 1 ) | V_74 ,
V_63 ) ;
F_16 ( V_75 , V_62 ) ;
if ( V_74 == V_85 ) {
V_80 = V_78 -> V_94 [ 0 ] ;
if ( V_80 == 0 || V_80 > V_95 )
return - V_35 ;
F_16 ( V_80 , V_64 ) ;
F_17 ( V_61 ) ;
for ( V_79 = 1 ; V_79 <= V_80 ; V_79 ++ )
F_16 ( V_78 -> V_94 [ V_79 ] , V_96 ) ;
}
V_76 = V_97 ;
break;
default:
F_25 ( & V_71 -> V_13 , L_43 , V_76 ) ;
return - V_98 ;
}
F_16 ( ( V_76 & 0x1C ) + ( V_99 & 1 ) , V_61 ) ;
V_81 = F_20 ( V_71 ) ;
if ( V_81 )
return V_81 ;
if ( ( V_74 == V_85 ) || ( V_76 == V_83 ) )
return 0 ;
switch ( V_76 ) {
case V_86 :
case V_89 :
V_78 -> V_88 = F_17 ( V_64 ) ;
break;
case V_92 :
V_78 -> V_91 = F_17 ( V_64 ) + ( F_17 ( V_65 ) << 8 ) ;
break;
case V_97 :
V_78 -> V_94 [ 0 ] = F_17 ( V_64 ) ;
if ( V_78 -> V_94 [ 0 ] == 0 || V_78 -> V_94 [ 0 ] > V_95 )
return - V_100 ;
F_17 ( V_61 ) ;
for ( V_79 = 1 ; V_79 <= V_78 -> V_94 [ 0 ] ; V_79 ++ )
V_78 -> V_94 [ V_79 ] = F_17 ( V_96 ) ;
break;
}
return 0 ;
}
static T_4 F_26 ( T_4 V_101 )
{
F_16 ( V_101 , V_102 ) ;
return F_17 ( V_103 ) ;
}
static void F_27 ( T_4 V_101 , T_4 V_104 )
{
F_16 ( V_101 , V_102 ) ;
F_16 ( V_104 , V_103 ) ;
}
static int F_28 ( void )
{
int V_60 = V_67 ;
if ( ! F_29 ( V_102 , 2 , L_44 ) )
return - V_24 ;
F_27 ( 0x82 , 0x00 ) ;
F_27 ( 0x83 , 0xB4 ) ;
F_27 ( 0x80 , 0x96 ) ;
while ( V_60 -- ) {
if ( F_26 ( 0x82 ) == 0xfa ) {
F_12 ( V_102 , 2 ) ;
return 0 ;
}
F_30 ( 1000 , 2000 ) ;
}
F_12 ( V_102 , 2 ) ;
return - V_68 ;
}
static void F_31 ( void )
{
int V_60 = V_67 ;
if ( ! F_29 ( V_102 , 2 , L_44 ) )
return;
F_27 ( 0x82 , 0x00 ) ;
F_27 ( 0x83 , 0xB5 ) ;
F_27 ( 0x80 , 0x96 ) ;
while ( V_60 -- ) {
if ( F_26 ( 0x82 ) == 0xfa )
break;
F_30 ( 1000 , 2000 ) ;
}
F_12 ( V_102 , 2 ) ;
}
static T_2 F_32 ( struct V_54 * V_71 , T_3 V_72 ,
unsigned short V_73 , char V_74 ,
T_1 V_75 , int V_76 , union V_77 * V_78 )
{
struct V_56 * V_57 = F_21 ( V_71 ) ;
unsigned short V_6 = V_57 -> V_58 ;
int V_105 = V_67 ;
int V_106 ;
T_1 V_28 ;
T_1 V_107 ;
int V_108 ;
F_15 ( & V_40 ) ;
V_106 = F_17 ( V_109 ) ;
do {
F_16 ( V_106 | 0x10 , V_109 ) ;
V_106 = F_17 ( V_109 ) ;
if ( V_106 & 0x10 )
break;
F_30 ( 1000 , 2000 ) ;
} while ( -- V_105 );
if ( ! V_105 ) {
F_18 ( & V_40 ) ;
return - V_24 ;
}
if ( ( V_76 == V_93 ) && V_57 -> V_110 ) {
int V_111 ;
V_111 = F_28 () ;
switch ( V_111 ) {
case - V_24 :
F_25 ( & V_71 -> V_13 ,
L_45 ,
V_102 ) ;
break;
case - V_68 :
F_25 ( & V_71 -> V_13 ,
L_46 ) ;
break;
default:
break;
}
if ( V_111 ) {
F_25 ( & V_71 -> V_13 ,
L_47 ) ;
V_57 -> V_110 = false ;
}
}
F_16 ( V_42 , V_41 ) ;
V_28 = F_17 ( V_41 + 1 ) ;
V_107 = V_57 -> V_107 ;
if ( ( V_28 & V_44 ) != V_107 )
F_16 ( ( V_28 & ~ V_44 ) | V_107 ,
V_41 + 1 ) ;
V_108 = F_24 ( V_71 , V_72 , V_73 , V_74 ,
V_75 , V_76 , V_78 ) ;
F_16 ( V_28 , V_41 + 1 ) ;
F_16 ( V_106 | 0x20 , V_109 ) ;
if ( ( V_76 == V_93 ) && V_57 -> V_110 )
F_31 () ;
F_18 ( & V_40 ) ;
return V_108 ;
}
static T_5 F_33 ( struct V_54 * V_112 )
{
return V_113 | V_114 |
V_115 | V_116 |
V_117 ;
}
static int F_34 ( struct V_1 * V_13 , unsigned short V_58 ,
bool V_118 , T_1 V_107 , bool V_110 ,
const char * V_23 , struct V_54 * * V_119 )
{
struct V_54 * V_71 ;
struct V_56 * V_57 ;
int V_108 ;
V_71 = F_35 ( sizeof( * V_71 ) , V_120 ) ;
if ( V_71 == NULL ) {
F_12 ( V_58 , V_21 ) ;
return - V_121 ;
}
V_71 -> V_122 = V_123 ;
V_71 -> V_124 = V_125 | V_126 ;
V_71 -> V_127 = V_118 ? & V_128
: & V_129 ;
V_57 = F_35 ( sizeof( * V_57 ) , V_120 ) ;
if ( V_57 == NULL ) {
F_36 ( V_71 ) ;
F_12 ( V_58 , V_21 ) ;
return - V_121 ;
}
V_57 -> V_58 = V_58 ;
V_57 -> V_118 = V_118 ;
V_57 -> V_107 = V_107 << V_46 ;
V_57 -> V_110 = V_110 ;
V_71 -> V_13 . V_130 = & V_13 -> V_13 ;
snprintf ( V_71 -> V_23 , sizeof( V_71 -> V_23 ) ,
L_48 , V_23 , V_58 ) ;
F_37 ( V_71 , V_57 ) ;
V_108 = F_38 ( V_71 ) ;
if ( V_108 ) {
F_36 ( V_57 ) ;
F_36 ( V_71 ) ;
F_12 ( V_58 , V_21 ) ;
return V_108 ;
}
* V_119 = V_71 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_13 , unsigned short V_58 ,
bool V_110 )
{
struct V_56 * V_57 ;
int V_107 ;
int V_108 ;
for ( V_107 = 0 ; V_107 < V_131 ; V_107 ++ ) {
V_108 = F_34 ( V_13 , V_58 , true , V_107 , V_110 ,
V_132 [ V_107 ] ,
& V_133 [ V_107 ] ) ;
if ( V_108 < 0 )
goto error;
}
return V_108 ;
error:
F_3 ( & V_13 -> V_13 ,
L_49 ) ;
while ( -- V_107 >= 0 ) {
V_57 = F_21 ( V_133 [ V_107 ] ) ;
if ( V_57 -> V_58 ) {
F_40 ( V_133 [ V_107 ] ) ;
F_36 ( V_57 ) ;
F_36 ( V_133 [ V_107 ] ) ;
V_133 [ V_107 ] = NULL ;
}
}
return V_108 ;
}
static int F_41 ( struct V_1 * V_13 , const struct V_3 * V_4 )
{
int V_108 ;
bool V_134 = false ;
if ( ( V_13 -> V_7 == V_135 &&
V_13 -> V_9 == V_136 &&
V_13 -> V_38 >= 0x40 ) ||
V_13 -> V_7 == V_36 ) {
bool V_110 = false ;
V_134 = true ;
if ( ! F_6 ( V_41 , 2 , L_50 ) ) {
F_3 ( & V_13 -> V_13 ,
L_51 ,
V_41 ) ;
return - V_24 ;
}
if ( V_13 -> V_7 == V_36 &&
V_13 -> V_9 == V_39 ) {
T_1 V_137 ;
F_42 ( V_13 -> V_138 , F_43 ( 0x14 , 3 ) ,
0x40 , & V_137 ) ;
if ( V_137 & 0x80 )
V_110 = true ;
}
V_108 = F_14 ( V_13 , V_4 , 0 ) ;
if ( V_108 < 0 ) {
F_12 ( V_41 , 2 ) ;
return V_108 ;
}
V_108 = F_39 ( V_13 , V_108 , V_110 ) ;
if ( V_108 < 0 ) {
F_12 ( V_41 , 2 ) ;
return V_108 ;
}
} else {
V_108 = F_1 ( V_13 , V_4 ) ;
if ( V_108 < 0 )
return V_108 ;
V_108 = F_34 ( V_13 , V_108 , false , 0 , false , L_52 ,
& V_133 [ 0 ] ) ;
if ( V_108 < 0 )
return V_108 ;
}
V_108 = - V_20 ;
if ( V_13 -> V_7 == V_135 &&
V_13 -> V_9 == V_136 ) {
if ( V_13 -> V_38 < 0x40 ) {
V_108 = F_19 ( V_13 , V_4 , 0x58 ) ;
} else {
V_108 = F_14 ( V_13 , V_4 , 1 ) ;
}
}
if ( V_13 -> V_7 == V_36 &&
V_13 -> V_9 == V_37 ) {
V_108 = F_14 ( V_13 , V_4 , 1 ) ;
}
if ( V_108 > 0 ) {
F_34 ( V_13 , V_108 , false , 0 , false ,
V_134 ? V_139 : L_52 ,
& V_140 ) ;
}
return 0 ;
}
static void F_44 ( struct V_54 * V_71 )
{
struct V_56 * V_57 = F_21 ( V_71 ) ;
if ( V_57 -> V_58 ) {
F_40 ( V_71 ) ;
if ( V_57 -> V_107 == ( 0 << 1 ) ) {
F_12 ( V_57 -> V_58 , V_21 ) ;
if ( V_57 -> V_118 )
F_12 ( V_41 , 2 ) ;
}
F_36 ( V_57 ) ;
F_36 ( V_71 ) ;
}
}
static void F_45 ( struct V_1 * V_13 )
{
int V_107 = V_131 ;
while ( -- V_107 >= 0 ) {
if ( V_133 [ V_107 ] ) {
F_44 ( V_133 [ V_107 ] ) ;
V_133 [ V_107 ] = NULL ;
}
}
if ( V_140 ) {
F_44 ( V_140 ) ;
V_140 = NULL ;
}
}
