static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
if ( V_2 -> V_4 && V_2 -> V_4 != V_2 -> V_5 )
F_2 ( V_2 -> V_4 ) ;
V_2 -> V_4 = F_3 ( V_3 , V_6 ) ;
if ( ! V_2 -> V_4 ) {
V_2 -> V_4 = V_2 -> V_5 ;
V_2 -> V_7 = V_8 ;
return 1 ;
}
V_2 -> V_7 = V_3 ;
return 0 ;
}
static struct V_9 * F_4 ( struct V_10 * V_11 ,
void * V_12 , unsigned V_13 , int V_14 )
{
struct V_9 * V_15 ;
struct V_16 * V_17 = V_11 -> V_16 ;
V_15 = F_5 ( V_17 , V_14 , V_6 ) ;
if ( F_6 ( V_15 ) ) {
F_7 ( V_18 , V_11 ,
L_1 , V_19 ) ;
return NULL ;
}
F_8 ( V_15 ) ;
if ( V_13 && F_9 ( V_17 , V_15 , V_12 , V_13 , V_6 ) ) {
F_10 ( V_15 ) ;
F_7 ( V_18 , V_11 ,
L_2 , V_19 ) ;
return NULL ;
}
V_15 -> V_20 |= V_21 | V_22 |
V_23 ;
V_15 -> V_24 = V_25 ;
V_15 -> V_26 = V_27 * V_28 ;
return V_15 ;
}
static int F_11 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
struct V_9 * V_15 ;
int V_29 = V_30 ;
V_15 = F_4 ( V_11 , V_2 -> V_4 , V_2 -> V_7 , V_31 ) ;
if ( ! V_15 )
goto V_32;
V_15 -> V_33 [ 0 ] = V_34 ;
V_15 -> V_33 [ 1 ] = 1 ;
V_15 -> V_33 [ 2 ] = 0x83 ;
V_15 -> V_33 [ 4 ] = V_2 -> V_7 ;
V_15 -> V_35 = F_12 ( V_34 ) ;
V_15 -> V_36 = V_2 -> V_36 ;
memset ( V_15 -> V_36 , 0 , V_37 ) ;
V_15 -> V_38 = V_2 -> V_39 = 0 ;
V_29 = F_13 ( V_15 -> V_17 , NULL , V_15 , 1 ) ;
if ( V_29 == - V_40 ) {
F_7 ( V_18 , V_11 ,
L_3 ,
V_41 , V_15 -> V_42 ) ;
V_2 -> V_39 = V_15 -> V_38 ;
V_29 = V_43 ;
}
F_10 ( V_15 ) ;
V_32:
return V_29 ;
}
static unsigned F_14 ( struct V_10 * V_11 , struct V_1 * V_2 ,
bool V_44 )
{
struct V_9 * V_15 ;
int V_29 = V_30 ;
V_15 = F_4 ( V_11 , V_2 -> V_4 , V_2 -> V_7 , V_31 ) ;
if ( ! V_15 )
goto V_32;
V_15 -> V_33 [ 0 ] = V_45 ;
if ( V_44 )
V_15 -> V_33 [ 1 ] = V_46 | V_47 ;
else
V_15 -> V_33 [ 1 ] = V_46 ;
V_15 -> V_33 [ 6 ] = ( V_2 -> V_7 >> 24 ) & 0xff ;
V_15 -> V_33 [ 7 ] = ( V_2 -> V_7 >> 16 ) & 0xff ;
V_15 -> V_33 [ 8 ] = ( V_2 -> V_7 >> 8 ) & 0xff ;
V_15 -> V_33 [ 9 ] = V_2 -> V_7 & 0xff ;
V_15 -> V_35 = F_12 ( V_45 ) ;
V_15 -> V_36 = V_2 -> V_36 ;
memset ( V_15 -> V_36 , 0 , V_37 ) ;
V_15 -> V_38 = V_2 -> V_39 = 0 ;
V_29 = F_13 ( V_15 -> V_17 , NULL , V_15 , 1 ) ;
if ( V_29 == - V_40 ) {
F_7 ( V_18 , V_11 ,
L_4 ,
V_41 , V_15 -> V_42 ) ;
V_2 -> V_39 = V_15 -> V_38 ;
V_29 = V_43 ;
}
F_10 ( V_15 ) ;
V_32:
return V_29 ;
}
static void F_15 ( struct V_9 * V_48 , int error )
{
struct V_1 * V_2 = V_48 -> V_49 ;
struct V_50 V_51 ;
unsigned V_29 = V_52 ;
if ( F_16 ( V_48 -> V_42 ) != V_53 ||
F_17 ( V_48 -> V_42 ) != V_54 ) {
V_29 = V_43 ;
goto V_32;
}
if ( V_48 -> V_38 > 0 ) {
V_29 = F_18 ( V_2 -> V_36 , V_37 ,
& V_51 ) ;
if ( ! V_29 ) {
V_29 = V_43 ;
goto V_32;
}
V_29 = F_19 ( V_2 -> V_11 , & V_51 ) ;
if ( V_29 == V_55 ) {
V_29 = V_56 ;
goto V_32;
}
F_7 ( V_18 , V_2 -> V_11 ,
L_5 ,
V_41 , V_51 . V_57 ,
V_51 . V_58 , V_51 . V_59 ) ;
V_29 = V_43 ;
} else if ( error )
V_29 = V_43 ;
if ( V_29 == V_52 ) {
V_2 -> V_60 = V_61 ;
F_7 ( V_18 , V_2 -> V_11 ,
L_6 ,
V_41 , V_2 -> V_62 ,
F_20 ( V_2 -> V_60 ) ) ;
}
V_32:
V_48 -> V_49 = NULL ;
F_21 ( V_48 -> V_17 , V_48 ) ;
if ( V_2 -> V_63 ) {
V_2 -> V_63 ( V_2 -> V_64 , V_29 ) ;
V_2 -> V_63 = V_2 -> V_64 = NULL ;
}
return;
}
static unsigned F_22 ( struct V_1 * V_2 )
{
struct V_9 * V_15 ;
int V_65 = 8 ;
struct V_10 * V_11 = V_2 -> V_11 ;
memset ( V_2 -> V_4 , 0 , V_65 ) ;
V_2 -> V_4 [ 4 ] = V_61 & 0x0f ;
V_2 -> V_4 [ 6 ] = ( V_2 -> V_62 >> 8 ) & 0xff ;
V_2 -> V_4 [ 7 ] = V_2 -> V_62 & 0xff ;
V_15 = F_4 ( V_11 , V_2 -> V_4 , V_65 , V_66 ) ;
if ( ! V_15 )
return V_30 ;
V_15 -> V_33 [ 0 ] = V_67 ;
V_15 -> V_33 [ 1 ] = V_68 ;
V_15 -> V_33 [ 6 ] = ( V_65 >> 24 ) & 0xff ;
V_15 -> V_33 [ 7 ] = ( V_65 >> 16 ) & 0xff ;
V_15 -> V_33 [ 8 ] = ( V_65 >> 8 ) & 0xff ;
V_15 -> V_33 [ 9 ] = V_65 & 0xff ;
V_15 -> V_35 = F_12 ( V_67 ) ;
V_15 -> V_36 = V_2 -> V_36 ;
memset ( V_15 -> V_36 , 0 , V_37 ) ;
V_15 -> V_38 = V_2 -> V_39 = 0 ;
V_15 -> V_49 = V_2 ;
F_23 ( V_15 -> V_17 , NULL , V_15 , 1 , F_15 ) ;
return V_52 ;
}
static int F_24 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_29 = V_52 ;
V_2 -> V_69 = F_25 ( V_11 ) ;
switch ( V_2 -> V_69 ) {
case V_70 | V_71 :
F_7 ( V_18 , V_11 ,
L_7 ,
V_41 ) ;
break;
case V_70 :
F_7 ( V_18 , V_11 , L_8 ,
V_41 ) ;
break;
case V_71 :
F_7 ( V_18 , V_11 , L_9 ,
V_41 ) ;
break;
default:
V_2 -> V_69 = V_72 ;
F_7 ( V_18 , V_11 , L_10 ,
V_41 ) ;
V_29 = V_73 ;
break;
}
return V_29 ;
}
static int F_26 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_3 ;
unsigned V_29 ;
unsigned char * V_74 ;
V_75:
V_29 = F_11 ( V_11 , V_2 ) ;
if ( V_29 != V_52 )
return V_29 ;
V_3 = ( V_2 -> V_4 [ 2 ] << 8 ) + V_2 -> V_4 [ 3 ] + 4 ;
if ( V_3 > V_2 -> V_7 ) {
if ( F_1 ( V_2 , V_3 ) ) {
F_7 ( V_76 , V_11 ,
L_11 ,
V_41 ) ;
return V_77 ;
}
goto V_75;
}
V_74 = V_2 -> V_4 + 4 ;
while ( V_74 < V_2 -> V_4 + V_3 ) {
switch ( V_74 [ 1 ] & 0xf ) {
case 0x4 :
V_2 -> V_78 = ( V_74 [ 6 ] << 8 ) + V_74 [ 7 ] ;
break;
case 0x5 :
V_2 -> V_62 = ( V_74 [ 6 ] << 8 ) + V_74 [ 7 ] ;
break;
default:
break;
}
V_74 += V_74 [ 3 ] + 4 ;
}
if ( V_2 -> V_62 == - 1 ) {
F_7 ( V_18 , V_11 ,
L_12 ,
V_41 ) ;
V_2 -> V_60 = V_61 ;
V_2 -> V_69 = V_72 ;
V_29 = V_73 ;
} else {
F_7 ( V_18 , V_11 ,
L_13 ,
V_41 , V_2 -> V_62 , V_2 -> V_78 ) ;
}
return V_29 ;
}
static char F_20 ( int V_60 )
{
switch ( V_60 ) {
case V_61 :
return 'A' ;
case V_79 :
return 'N' ;
case V_80 :
return 'S' ;
case V_81 :
return 'U' ;
case V_82 :
return 'L' ;
case V_83 :
return 'O' ;
case V_84 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_19 ( struct V_10 * V_11 ,
struct V_50 * V_51 )
{
switch ( V_51 -> V_57 ) {
case V_85 :
if ( V_51 -> V_58 == 0x04 && V_51 -> V_59 == 0x0a )
return V_55 ;
if ( V_51 -> V_58 == 0x04 && V_51 -> V_59 == 0x0b )
return V_86 ;
if ( V_51 -> V_58 == 0x04 && V_51 -> V_59 == 0x0c )
return V_86 ;
if ( V_51 -> V_58 == 0x04 && V_51 -> V_59 == 0x12 )
return V_86 ;
if ( V_11 -> V_87 &&
V_51 -> V_58 == 0x04 && V_51 -> V_59 == 0x02 )
return V_88 ;
break;
case V_89 :
if ( V_51 -> V_58 == 0x29 && V_51 -> V_59 == 0x00 )
return V_55 ;
if ( V_51 -> V_58 == 0x29 && V_51 -> V_59 == 0x04 )
return V_55 ;
if ( V_51 -> V_58 == 0x2a && V_51 -> V_59 == 0x01 )
return V_55 ;
if ( V_51 -> V_58 == 0x2a && V_51 -> V_59 == 0x06 )
return V_55 ;
if ( V_51 -> V_58 == 0x2a && V_51 -> V_59 == 0x07 )
return V_55 ;
if ( V_51 -> V_58 == 0x3f && V_51 -> V_59 == 0x03 )
return V_55 ;
if ( V_51 -> V_58 == 0x3f && V_51 -> V_59 == 0x0e )
return V_55 ;
break;
}
return V_90 ;
}
static int F_27 ( struct V_10 * V_11 , struct V_1 * V_2 , int V_91 )
{
struct V_50 V_51 ;
int V_3 , V_92 , V_93 , V_94 = 0 ;
unsigned char * V_95 ;
unsigned V_29 ;
bool V_44 = 1 ;
unsigned long V_96 , V_97 = 0 ;
unsigned int V_98 ;
unsigned char V_99 ;
if ( ! V_2 -> V_100 )
V_96 = F_28 ( V_101 + V_27 * V_28 ) ;
else
V_96 = F_28 ( V_101 + V_2 -> V_100 * V_28 ) ;
V_75:
V_29 = F_14 ( V_11 , V_2 , V_44 ) ;
if ( V_29 == V_43 && V_2 -> V_39 > 0 ) {
V_29 = F_18 ( V_2 -> V_36 , V_37 ,
& V_51 ) ;
if ( ! V_29 )
return V_43 ;
if ( V_44 == 1 &&
V_51 . V_57 == V_102 &&
V_51 . V_58 == 0x24 && V_51 . V_59 == 0 ) {
V_44 = 0 ;
goto V_75;
}
V_29 = F_19 ( V_11 , & V_51 ) ;
if ( V_29 == V_55 && F_29 ( V_101 , V_96 ) )
goto V_75;
F_7 ( V_18 , V_11 ,
L_14 ,
V_41 , V_51 . V_57 ,
V_51 . V_58 , V_51 . V_59 ) ;
V_29 = V_43 ;
}
if ( V_29 != V_52 )
return V_29 ;
V_3 = ( V_2 -> V_4 [ 0 ] << 24 ) + ( V_2 -> V_4 [ 1 ] << 16 ) +
( V_2 -> V_4 [ 2 ] << 8 ) + V_2 -> V_4 [ 3 ] + 4 ;
if ( V_3 > V_2 -> V_7 ) {
if ( F_1 ( V_2 , V_3 ) ) {
F_7 ( V_76 , V_11 ,
L_11 , V_19 ) ;
return V_77 ;
}
goto V_75;
}
V_99 = V_2 -> V_100 ;
if ( ( V_2 -> V_4 [ 4 ] & V_103 ) == V_104 && V_2 -> V_4 [ 5 ] != 0 )
V_2 -> V_100 = V_2 -> V_4 [ 5 ] ;
else
V_2 -> V_100 = V_27 ;
if ( V_91 && ( V_99 != V_2 -> V_100 ) ) {
F_7 ( V_18 , V_11 ,
L_15 ,
V_41 , V_2 -> V_100 ) ;
V_96 = V_101 + V_2 -> V_100 * V_28 ;
}
if ( ( V_2 -> V_4 [ 4 ] & V_103 ) == V_104 )
V_98 = 8 ;
else
V_98 = 4 ;
for ( V_92 = V_98 , V_95 = V_2 -> V_4 + V_98 ;
V_92 < V_3 ;
V_92 += V_93 , V_95 += V_93 ) {
if ( V_2 -> V_62 == ( V_95 [ 2 ] << 8 ) + V_95 [ 3 ] ) {
V_2 -> V_60 = V_95 [ 0 ] & 0x0f ;
V_2 -> V_105 = V_95 [ 0 ] >> 7 ;
V_94 = V_95 [ 1 ] ;
}
V_93 = 8 + ( V_95 [ 7 ] * 4 ) ;
}
F_7 ( V_18 , V_11 ,
L_16 ,
V_41 , V_2 -> V_62 , F_20 ( V_2 -> V_60 ) ,
V_2 -> V_105 ? L_17 : L_18 ,
V_94 & V_106 ? 'T' : 't' ,
V_94 & V_107 ? 'O' : 'o' ,
V_94 & V_108 ? 'L' : 'l' ,
V_94 & V_109 ? 'U' : 'u' ,
V_94 & V_110 ? 'S' : 's' ,
V_94 & V_111 ? 'N' : 'n' ,
V_94 & V_112 ? 'A' : 'a' ) ;
switch ( V_2 -> V_60 ) {
case V_84 :
if ( V_91 ) {
if ( F_29 ( V_101 , V_96 ) ) {
V_97 += 2000 ;
F_30 ( V_97 ) ;
goto V_75;
}
V_29 = V_56 ;
} else {
V_29 = V_52 ;
}
V_2 -> V_60 = V_80 ;
break;
case V_83 :
V_29 = V_113 ;
break;
default:
V_29 = V_52 ;
break;
}
return V_29 ;
}
static int F_31 ( struct V_10 * V_11 , struct V_1 * V_2 )
{
int V_29 ;
V_29 = F_24 ( V_11 , V_2 ) ;
if ( V_29 != V_52 )
goto V_114;
V_29 = F_26 ( V_11 , V_2 ) ;
if ( V_29 != V_52 )
goto V_114;
V_29 = F_27 ( V_11 , V_2 , 0 ) ;
if ( V_29 != V_52 )
goto V_114;
V_114:
return V_29 ;
}
static int F_32 ( struct V_10 * V_11 , const char * V_115 )
{
struct V_1 * V_2 = V_11 -> V_116 ;
unsigned int V_117 = 0 , V_118 ;
const char * V_119 = V_115 ;
int V_120 = V_52 ;
if ( ( sscanf ( V_115 , L_19 , & V_118 ) != 1 ) || ( V_118 != 1 ) )
return - V_121 ;
while ( * V_119 ++ )
;
if ( ( sscanf ( V_119 , L_19 , & V_117 ) != 1 ) || ( V_117 > 1 ) )
return - V_121 ;
if ( V_117 )
V_2 -> V_122 |= V_123 ;
else
V_2 -> V_122 &= ~ V_123 ;
return V_120 ;
}
static int F_33 ( struct V_10 * V_11 ,
T_1 V_124 , void * V_125 )
{
struct V_1 * V_2 = V_11 -> V_116 ;
int V_29 = V_52 ;
int V_126 = 0 ;
V_29 = F_27 ( V_11 , V_2 , 1 ) ;
if ( V_29 != V_52 )
goto V_114;
if ( V_127 )
V_2 -> V_122 |= V_123 ;
if ( V_2 -> V_69 & V_70 ) {
switch ( V_2 -> V_60 ) {
case V_79 :
V_126 = 1 ;
if ( ( V_2 -> V_122 & V_123 ) &&
( ! V_2 -> V_105 ) &&
( V_2 -> V_69 & V_71 ) )
V_126 = 0 ;
break;
case V_80 :
case V_81 :
V_126 = 1 ;
break;
case V_83 :
V_29 = V_43 ;
break;
case V_84 :
V_29 = V_56 ;
break;
default:
break;
}
}
if ( V_126 ) {
V_2 -> V_63 = V_124 ;
V_2 -> V_64 = V_125 ;
V_29 = F_22 ( V_2 ) ;
if ( V_29 == V_52 )
return 0 ;
V_2 -> V_63 = V_2 -> V_64 = NULL ;
}
V_114:
if ( V_124 )
V_124 ( V_125 , V_29 ) ;
return 0 ;
}
static int F_34 ( struct V_10 * V_11 , struct V_9 * V_48 )
{
struct V_1 * V_2 = V_11 -> V_116 ;
int V_128 = V_129 ;
if ( V_2 -> V_60 == V_84 )
V_128 = V_130 ;
else if ( V_2 -> V_60 != V_61 &&
V_2 -> V_60 != V_79 &&
V_2 -> V_60 != V_82 ) {
V_128 = V_131 ;
V_48 -> V_20 |= V_132 ;
}
return V_128 ;
}
static int F_35 ( struct V_10 * V_11 )
{
struct V_1 * V_2 ;
int V_29 ;
V_2 = F_36 ( sizeof( * V_2 ) , V_133 ) ;
if ( ! V_2 )
return - V_134 ;
V_2 -> V_69 = V_135 ;
V_2 -> V_60 = V_61 ;
V_2 -> V_62 = - 1 ;
V_2 -> V_78 = - 1 ;
V_2 -> V_4 = V_2 -> V_5 ;
V_2 -> V_7 = V_8 ;
V_2 -> V_11 = V_11 ;
V_29 = F_31 ( V_11 , V_2 ) ;
if ( V_29 != V_52 && V_29 != V_113 )
goto V_136;
V_11 -> V_116 = V_2 ;
return 0 ;
V_136:
F_2 ( V_2 ) ;
return - V_121 ;
}
static void F_37 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_116 ;
if ( V_2 -> V_4 && V_2 -> V_5 != V_2 -> V_4 )
F_2 ( V_2 -> V_4 ) ;
V_11 -> V_116 = NULL ;
F_2 ( V_2 ) ;
}
static int T_2 F_38 ( void )
{
int V_137 ;
V_137 = F_39 ( & V_138 ) ;
if ( V_137 != 0 )
F_40 ( V_139 L_20 ,
V_41 ) ;
return V_137 ;
}
static void T_3 F_41 ( void )
{
F_42 ( & V_138 ) ;
}
