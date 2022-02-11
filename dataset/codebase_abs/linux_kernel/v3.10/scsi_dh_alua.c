static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_4 = V_3 -> V_4 ;
F_2 ( V_4 == NULL ) ;
return ( (struct V_1 * ) V_4 -> V_5 ) ;
}
static int F_3 ( struct V_1 * V_6 , unsigned V_7 )
{
if ( V_6 -> V_8 && V_6 -> V_8 != V_6 -> V_9 )
F_4 ( V_6 -> V_8 ) ;
V_6 -> V_8 = F_5 ( V_7 , V_10 ) ;
if ( ! V_6 -> V_8 ) {
V_6 -> V_8 = V_6 -> V_9 ;
V_6 -> V_11 = V_12 ;
return 1 ;
}
V_6 -> V_11 = V_7 ;
return 0 ;
}
static struct V_13 * F_6 ( struct V_2 * V_3 ,
void * V_14 , unsigned V_15 , int V_16 )
{
struct V_13 * V_17 ;
struct V_18 * V_19 = V_3 -> V_18 ;
V_17 = F_7 ( V_19 , V_16 , V_10 ) ;
if ( ! V_17 ) {
F_8 ( V_20 , V_3 ,
L_1 , V_21 ) ;
return NULL ;
}
if ( V_15 && F_9 ( V_19 , V_17 , V_14 , V_15 , V_10 ) ) {
F_10 ( V_17 ) ;
F_8 ( V_20 , V_3 ,
L_2 , V_21 ) ;
return NULL ;
}
V_17 -> V_22 = V_23 ;
V_17 -> V_24 |= V_25 | V_26 |
V_27 ;
V_17 -> V_28 = V_29 ;
V_17 -> V_30 = V_31 * V_32 ;
return V_17 ;
}
static int F_11 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_33 = V_34 ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_6 -> V_11 , V_35 ) ;
if ( ! V_17 )
goto V_36;
V_17 -> V_37 [ 0 ] = V_38 ;
V_17 -> V_37 [ 1 ] = 1 ;
V_17 -> V_37 [ 2 ] = 0x83 ;
V_17 -> V_37 [ 4 ] = V_6 -> V_11 ;
V_17 -> V_39 = F_12 ( V_38 ) ;
V_17 -> V_40 = V_6 -> V_40 ;
memset ( V_17 -> V_40 , 0 , V_41 ) ;
V_17 -> V_42 = V_6 -> V_43 = 0 ;
V_33 = F_13 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_33 == - V_44 ) {
F_8 ( V_20 , V_3 ,
L_3 ,
V_45 , V_17 -> V_46 ) ;
V_6 -> V_43 = V_17 -> V_42 ;
V_33 = V_47 ;
}
F_10 ( V_17 ) ;
V_36:
return V_33 ;
}
static unsigned F_14 ( struct V_2 * V_3 , struct V_1 * V_6 ,
bool V_48 )
{
struct V_13 * V_17 ;
int V_33 = V_34 ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_6 -> V_11 , V_35 ) ;
if ( ! V_17 )
goto V_36;
V_17 -> V_37 [ 0 ] = V_49 ;
if ( V_48 )
V_17 -> V_37 [ 1 ] = V_50 | V_51 ;
else
V_17 -> V_37 [ 1 ] = V_50 ;
V_17 -> V_37 [ 6 ] = ( V_6 -> V_11 >> 24 ) & 0xff ;
V_17 -> V_37 [ 7 ] = ( V_6 -> V_11 >> 16 ) & 0xff ;
V_17 -> V_37 [ 8 ] = ( V_6 -> V_11 >> 8 ) & 0xff ;
V_17 -> V_37 [ 9 ] = V_6 -> V_11 & 0xff ;
V_17 -> V_39 = F_12 ( V_49 ) ;
V_17 -> V_40 = V_6 -> V_40 ;
memset ( V_17 -> V_40 , 0 , V_41 ) ;
V_17 -> V_42 = V_6 -> V_43 = 0 ;
V_33 = F_13 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_33 == - V_44 ) {
F_8 ( V_20 , V_3 ,
L_4 ,
V_45 , V_17 -> V_46 ) ;
V_6 -> V_43 = V_17 -> V_42 ;
V_33 = V_47 ;
}
F_10 ( V_17 ) ;
V_36:
return V_33 ;
}
static void F_15 ( struct V_13 * V_52 , int error )
{
struct V_1 * V_6 = V_52 -> V_53 ;
struct V_54 V_55 ;
unsigned V_33 = V_56 ;
if ( F_16 ( V_52 -> V_46 ) != V_57 ||
F_17 ( V_52 -> V_46 ) != V_58 ) {
V_33 = V_47 ;
goto V_36;
}
if ( V_52 -> V_42 > 0 ) {
V_33 = F_18 ( V_6 -> V_40 , V_41 ,
& V_55 ) ;
if ( ! V_33 ) {
V_33 = V_47 ;
goto V_36;
}
V_33 = F_19 ( V_6 -> V_3 , & V_55 ) ;
if ( V_33 == V_59 ) {
V_33 = V_60 ;
goto V_36;
}
F_8 ( V_20 , V_6 -> V_3 ,
L_5 ,
V_45 , V_55 . V_61 ,
V_55 . V_62 , V_55 . V_63 ) ;
V_33 = V_47 ;
} else if ( error )
V_33 = V_47 ;
if ( V_33 == V_56 ) {
V_6 -> V_64 = V_65 ;
F_8 ( V_20 , V_6 -> V_3 ,
L_6 ,
V_45 , V_6 -> V_66 ,
F_20 ( V_6 -> V_64 ) ) ;
}
V_36:
V_52 -> V_53 = NULL ;
F_21 ( V_52 -> V_19 , V_52 ) ;
if ( V_6 -> V_67 ) {
V_6 -> V_67 ( V_6 -> V_68 , V_33 ) ;
V_6 -> V_67 = V_6 -> V_68 = NULL ;
}
return;
}
static unsigned F_22 ( struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_69 = 8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
memset ( V_6 -> V_8 , 0 , V_69 ) ;
V_6 -> V_8 [ 4 ] = V_65 & 0x0f ;
V_6 -> V_8 [ 6 ] = ( V_6 -> V_66 >> 8 ) & 0xff ;
V_6 -> V_8 [ 7 ] = V_6 -> V_66 & 0xff ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_69 , V_70 ) ;
if ( ! V_17 )
return V_34 ;
V_17 -> V_37 [ 0 ] = V_71 ;
V_17 -> V_37 [ 1 ] = V_72 ;
V_17 -> V_37 [ 6 ] = ( V_69 >> 24 ) & 0xff ;
V_17 -> V_37 [ 7 ] = ( V_69 >> 16 ) & 0xff ;
V_17 -> V_37 [ 8 ] = ( V_69 >> 8 ) & 0xff ;
V_17 -> V_37 [ 9 ] = V_69 & 0xff ;
V_17 -> V_39 = F_12 ( V_71 ) ;
V_17 -> V_40 = V_6 -> V_40 ;
memset ( V_17 -> V_40 , 0 , V_41 ) ;
V_17 -> V_42 = V_6 -> V_43 = 0 ;
V_17 -> V_53 = V_6 ;
F_23 ( V_17 -> V_19 , NULL , V_17 , 1 , F_15 ) ;
return V_56 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_33 = V_56 ;
V_6 -> V_73 = F_25 ( V_3 ) ;
switch ( V_6 -> V_73 ) {
case V_74 | V_75 :
F_8 ( V_20 , V_3 ,
L_7 ,
V_45 ) ;
break;
case V_74 :
F_8 ( V_20 , V_3 , L_8 ,
V_45 ) ;
break;
case V_75 :
F_8 ( V_20 , V_3 , L_9 ,
V_45 ) ;
break;
default:
V_6 -> V_73 = V_76 ;
F_8 ( V_20 , V_3 , L_10 ,
V_45 ) ;
V_33 = V_77 ;
break;
}
return V_33 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_7 ;
unsigned V_33 ;
unsigned char * V_78 ;
V_79:
V_33 = F_11 ( V_3 , V_6 ) ;
if ( V_33 != V_56 )
return V_33 ;
V_7 = ( V_6 -> V_8 [ 2 ] << 8 ) + V_6 -> V_8 [ 3 ] + 4 ;
if ( V_7 > V_6 -> V_11 ) {
if ( F_3 ( V_6 , V_7 ) ) {
F_8 ( V_80 , V_3 ,
L_11 ,
V_45 ) ;
return V_81 ;
}
goto V_79;
}
V_78 = V_6 -> V_8 + 4 ;
while ( V_78 < V_6 -> V_8 + V_7 ) {
switch ( V_78 [ 1 ] & 0xf ) {
case 0x4 :
V_6 -> V_82 = ( V_78 [ 6 ] << 8 ) + V_78 [ 7 ] ;
break;
case 0x5 :
V_6 -> V_66 = ( V_78 [ 6 ] << 8 ) + V_78 [ 7 ] ;
break;
default:
break;
}
V_78 += V_78 [ 3 ] + 4 ;
}
if ( V_6 -> V_66 == - 1 ) {
F_8 ( V_20 , V_3 ,
L_12 ,
V_45 ) ;
V_6 -> V_64 = V_65 ;
V_6 -> V_73 = V_76 ;
V_33 = V_77 ;
} else {
F_8 ( V_20 , V_3 ,
L_13 ,
V_45 , V_6 -> V_66 , V_6 -> V_82 ) ;
}
return V_33 ;
}
static char F_20 ( int V_64 )
{
switch ( V_64 ) {
case V_65 :
return 'A' ;
case V_83 :
return 'N' ;
case V_84 :
return 'S' ;
case V_85 :
return 'U' ;
case V_86 :
return 'L' ;
case V_87 :
return 'O' ;
case V_88 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_19 ( struct V_2 * V_3 ,
struct V_54 * V_55 )
{
switch ( V_55 -> V_61 ) {
case V_89 :
if ( V_55 -> V_62 == 0x04 && V_55 -> V_63 == 0x0a )
return V_59 ;
if ( V_55 -> V_62 == 0x04 && V_55 -> V_63 == 0x0b )
return V_90 ;
if ( V_55 -> V_62 == 0x04 && V_55 -> V_63 == 0x0c )
return V_90 ;
if ( V_55 -> V_62 == 0x04 && V_55 -> V_63 == 0x12 )
return V_90 ;
break;
case V_91 :
if ( V_55 -> V_62 == 0x29 && V_55 -> V_63 == 0x00 )
return V_59 ;
if ( V_55 -> V_62 == 0x2a && V_55 -> V_63 == 0x01 )
return V_59 ;
if ( V_55 -> V_62 == 0x2a && V_55 -> V_63 == 0x06 )
return V_59 ;
if ( V_55 -> V_62 == 0x2a && V_55 -> V_63 == 0x07 )
return V_59 ;
if ( V_55 -> V_62 == 0x3f && V_55 -> V_63 == 0x03 )
return V_59 ;
if ( V_55 -> V_62 == 0x3f && V_55 -> V_63 == 0x0e )
return V_59 ;
break;
}
return V_92 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_54 V_55 ;
int V_7 , V_93 , V_94 , V_95 = 0 ;
unsigned char * V_96 ;
unsigned V_33 ;
bool V_48 = 1 ;
unsigned long V_97 , V_98 = 0 ;
unsigned int V_99 ;
unsigned char V_100 ;
if ( ! V_6 -> V_101 )
V_97 = F_28 ( V_102 + V_31 * V_32 ) ;
else
V_97 = F_28 ( V_102 + V_6 -> V_101 * V_32 ) ;
V_79:
V_33 = F_14 ( V_3 , V_6 , V_48 ) ;
if ( V_33 == V_47 && V_6 -> V_43 > 0 ) {
V_33 = F_18 ( V_6 -> V_40 , V_41 ,
& V_55 ) ;
if ( ! V_33 )
return V_47 ;
if ( V_48 == 1 &&
V_55 . V_61 == V_103 &&
V_55 . V_62 == 0x24 && V_55 . V_63 == 0 ) {
V_48 = 0 ;
goto V_79;
}
V_33 = F_19 ( V_3 , & V_55 ) ;
if ( V_33 == V_59 && F_29 ( V_102 , V_97 ) )
goto V_79;
F_8 ( V_20 , V_3 ,
L_14 ,
V_45 , V_55 . V_61 ,
V_55 . V_62 , V_55 . V_63 ) ;
V_33 = V_47 ;
}
if ( V_33 != V_56 )
return V_33 ;
V_7 = ( V_6 -> V_8 [ 0 ] << 24 ) + ( V_6 -> V_8 [ 1 ] << 16 ) +
( V_6 -> V_8 [ 2 ] << 8 ) + V_6 -> V_8 [ 3 ] + 4 ;
if ( V_7 > V_6 -> V_11 ) {
if ( F_3 ( V_6 , V_7 ) ) {
F_8 ( V_80 , V_3 ,
L_11 , V_21 ) ;
return V_81 ;
}
goto V_79;
}
V_100 = V_6 -> V_101 ;
if ( ( V_6 -> V_8 [ 4 ] & V_104 ) == V_105 && V_6 -> V_8 [ 5 ] != 0 )
V_6 -> V_101 = V_6 -> V_8 [ 5 ] ;
else
V_6 -> V_101 = V_31 ;
if ( V_100 != V_6 -> V_101 ) {
F_8 ( V_20 , V_3 ,
L_15 ,
V_45 , V_6 -> V_101 ) ;
V_97 = V_102 + V_6 -> V_101 * V_32 ;
}
if ( ( V_6 -> V_8 [ 4 ] & V_104 ) == V_105 )
V_99 = 8 ;
else
V_99 = 4 ;
for ( V_93 = V_99 , V_96 = V_6 -> V_8 + V_99 ;
V_93 < V_7 ;
V_93 += V_94 , V_96 += V_94 ) {
if ( V_6 -> V_66 == ( V_96 [ 2 ] << 8 ) + V_96 [ 3 ] ) {
V_6 -> V_64 = V_96 [ 0 ] & 0x0f ;
V_6 -> V_106 = V_96 [ 0 ] >> 7 ;
V_95 = V_96 [ 1 ] ;
}
V_94 = 8 + ( V_96 [ 7 ] * 4 ) ;
}
F_8 ( V_20 , V_3 ,
L_16 ,
V_45 , V_6 -> V_66 , F_20 ( V_6 -> V_64 ) ,
V_6 -> V_106 ? L_17 : L_18 ,
V_95 & V_107 ? 'T' : 't' ,
V_95 & V_108 ? 'O' : 'o' ,
V_95 & V_109 ? 'L' : 'l' ,
V_95 & V_110 ? 'U' : 'u' ,
V_95 & V_111 ? 'S' : 's' ,
V_95 & V_112 ? 'N' : 'n' ,
V_95 & V_113 ? 'A' : 'a' ) ;
switch ( V_6 -> V_64 ) {
case V_88 :
if ( F_29 ( V_102 , V_97 ) ) {
V_98 += 2000 ;
F_30 ( V_98 ) ;
goto V_79;
}
V_33 = V_60 ;
V_6 -> V_64 = V_84 ;
break;
case V_87 :
V_33 = V_114 ;
break;
default:
V_33 = V_56 ;
break;
}
return V_33 ;
}
static int F_31 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_33 ;
V_33 = F_24 ( V_3 , V_6 ) ;
if ( V_33 != V_56 )
goto V_115;
V_33 = F_26 ( V_3 , V_6 ) ;
if ( V_33 != V_56 )
goto V_115;
V_33 = F_27 ( V_3 , V_6 ) ;
if ( V_33 != V_56 )
goto V_115;
V_115:
return V_33 ;
}
static int F_32 ( struct V_2 * V_3 , const char * V_116 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned int V_117 = 0 , V_118 ;
const char * V_119 = V_116 ;
int V_120 = V_56 ;
if ( ( sscanf ( V_116 , L_19 , & V_118 ) != 1 ) || ( V_118 != 1 ) )
return - V_121 ;
while ( * V_119 ++ )
;
if ( ( sscanf ( V_119 , L_19 , & V_117 ) != 1 ) || ( V_117 > 1 ) )
return - V_121 ;
if ( V_117 )
V_6 -> V_122 |= V_123 ;
else
V_6 -> V_122 &= ~ V_123 ;
return V_120 ;
}
static int F_33 ( struct V_2 * V_3 ,
T_1 V_124 , void * V_125 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_33 = V_56 ;
int V_126 = 0 ;
V_33 = F_27 ( V_3 , V_6 ) ;
if ( V_33 != V_56 )
goto V_115;
if ( V_127 )
V_6 -> V_122 |= V_123 ;
if ( V_6 -> V_73 & V_74 ) {
switch ( V_6 -> V_64 ) {
case V_83 :
V_126 = 1 ;
if ( ( V_6 -> V_122 & V_123 ) &&
( ! V_6 -> V_106 ) &&
( V_6 -> V_73 & V_75 ) )
V_126 = 0 ;
break;
case V_84 :
case V_85 :
V_126 = 1 ;
break;
case V_87 :
V_33 = V_47 ;
break;
case V_88 :
V_33 = V_60 ;
break;
default:
break;
}
}
if ( V_126 ) {
V_6 -> V_67 = V_124 ;
V_6 -> V_68 = V_125 ;
V_33 = F_22 ( V_6 ) ;
if ( V_33 == V_56 )
return 0 ;
V_6 -> V_67 = V_6 -> V_68 = NULL ;
}
V_115:
if ( V_124 )
V_124 ( V_125 , V_33 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 , struct V_13 * V_52 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_128 = V_129 ;
if ( V_6 -> V_64 == V_88 )
V_128 = V_130 ;
else if ( V_6 -> V_64 != V_65 &&
V_6 -> V_64 != V_83 &&
V_6 -> V_64 != V_86 ) {
V_128 = V_131 ;
V_52 -> V_24 |= V_132 ;
}
return V_128 ;
}
static bool F_35 ( struct V_2 * V_3 )
{
return ( F_25 ( V_3 ) != 0 ) ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_122 ;
int V_33 = V_56 ;
V_4 = F_37 ( sizeof( * V_4 )
+ sizeof( * V_6 ) , V_133 ) ;
if ( ! V_4 ) {
F_8 ( V_134 , V_3 , L_20 ,
V_45 ) ;
return - V_135 ;
}
V_4 -> V_136 = & V_137 ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
V_6 -> V_73 = V_138 ;
V_6 -> V_64 = V_65 ;
V_6 -> V_66 = - 1 ;
V_6 -> V_82 = - 1 ;
V_6 -> V_8 = V_6 -> V_9 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_3 = V_3 ;
V_33 = F_31 ( V_3 , V_6 ) ;
if ( ( V_33 != V_56 ) && ( V_33 != V_114 ) )
goto V_139;
if ( ! F_38 ( V_140 ) )
goto V_139;
F_39 ( V_3 -> V_18 -> V_141 , V_122 ) ;
V_3 -> V_4 = V_4 ;
F_40 ( V_3 -> V_18 -> V_141 , V_122 ) ;
F_8 ( V_142 , V_3 , L_21 , V_45 ) ;
return 0 ;
V_139:
F_4 ( V_4 ) ;
F_8 ( V_134 , V_3 , L_22 , V_45 ) ;
return - V_121 ;
}
static void F_41 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_122 ;
F_39 ( V_3 -> V_18 -> V_141 , V_122 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_40 ( V_3 -> V_18 -> V_141 , V_122 ) ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
if ( V_6 -> V_8 && V_6 -> V_9 != V_6 -> V_8 )
F_4 ( V_6 -> V_8 ) ;
F_4 ( V_4 ) ;
F_42 ( V_140 ) ;
F_8 ( V_142 , V_3 , L_23 , V_45 ) ;
}
static int T_2 F_43 ( void )
{
int V_143 ;
V_143 = F_44 ( & V_137 ) ;
if ( V_143 != 0 )
F_45 ( V_134 L_24 ,
V_45 ) ;
return V_143 ;
}
static void T_3 F_46 ( void )
{
F_47 ( & V_137 ) ;
}
