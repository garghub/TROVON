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
if ( F_8 ( V_17 ) ) {
F_9 ( V_20 , V_3 ,
L_1 , V_21 ) ;
return NULL ;
}
F_10 ( V_17 ) ;
if ( V_15 && F_11 ( V_19 , V_17 , V_14 , V_15 , V_10 ) ) {
F_12 ( V_17 ) ;
F_9 ( V_20 , V_3 ,
L_2 , V_21 ) ;
return NULL ;
}
V_17 -> V_22 |= V_23 | V_24 |
V_25 ;
V_17 -> V_26 = V_27 ;
V_17 -> V_28 = V_29 * V_30 ;
return V_17 ;
}
static int F_13 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_31 = V_32 ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_6 -> V_11 , V_33 ) ;
if ( ! V_17 )
goto V_34;
V_17 -> V_35 [ 0 ] = V_36 ;
V_17 -> V_35 [ 1 ] = 1 ;
V_17 -> V_35 [ 2 ] = 0x83 ;
V_17 -> V_35 [ 4 ] = V_6 -> V_11 ;
V_17 -> V_37 = F_14 ( V_36 ) ;
V_17 -> V_38 = V_6 -> V_38 ;
memset ( V_17 -> V_38 , 0 , V_39 ) ;
V_17 -> V_40 = V_6 -> V_41 = 0 ;
V_31 = F_15 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_31 == - V_42 ) {
F_9 ( V_20 , V_3 ,
L_3 ,
V_43 , V_17 -> V_44 ) ;
V_6 -> V_41 = V_17 -> V_40 ;
V_31 = V_45 ;
}
F_12 ( V_17 ) ;
V_34:
return V_31 ;
}
static unsigned F_16 ( struct V_2 * V_3 , struct V_1 * V_6 ,
bool V_46 )
{
struct V_13 * V_17 ;
int V_31 = V_32 ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_6 -> V_11 , V_33 ) ;
if ( ! V_17 )
goto V_34;
V_17 -> V_35 [ 0 ] = V_47 ;
if ( V_46 )
V_17 -> V_35 [ 1 ] = V_48 | V_49 ;
else
V_17 -> V_35 [ 1 ] = V_48 ;
V_17 -> V_35 [ 6 ] = ( V_6 -> V_11 >> 24 ) & 0xff ;
V_17 -> V_35 [ 7 ] = ( V_6 -> V_11 >> 16 ) & 0xff ;
V_17 -> V_35 [ 8 ] = ( V_6 -> V_11 >> 8 ) & 0xff ;
V_17 -> V_35 [ 9 ] = V_6 -> V_11 & 0xff ;
V_17 -> V_37 = F_14 ( V_47 ) ;
V_17 -> V_38 = V_6 -> V_38 ;
memset ( V_17 -> V_38 , 0 , V_39 ) ;
V_17 -> V_40 = V_6 -> V_41 = 0 ;
V_31 = F_15 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_31 == - V_42 ) {
F_9 ( V_20 , V_3 ,
L_4 ,
V_43 , V_17 -> V_44 ) ;
V_6 -> V_41 = V_17 -> V_40 ;
V_31 = V_45 ;
}
F_12 ( V_17 ) ;
V_34:
return V_31 ;
}
static void F_17 ( struct V_13 * V_50 , int error )
{
struct V_1 * V_6 = V_50 -> V_51 ;
struct V_52 V_53 ;
unsigned V_31 = V_54 ;
if ( F_18 ( V_50 -> V_44 ) != V_55 ||
F_19 ( V_50 -> V_44 ) != V_56 ) {
V_31 = V_45 ;
goto V_34;
}
if ( V_50 -> V_40 > 0 ) {
V_31 = F_20 ( V_6 -> V_38 , V_39 ,
& V_53 ) ;
if ( ! V_31 ) {
V_31 = V_45 ;
goto V_34;
}
V_31 = F_21 ( V_6 -> V_3 , & V_53 ) ;
if ( V_31 == V_57 ) {
V_31 = V_58 ;
goto V_34;
}
F_9 ( V_20 , V_6 -> V_3 ,
L_5 ,
V_43 , V_53 . V_59 ,
V_53 . V_60 , V_53 . V_61 ) ;
V_31 = V_45 ;
} else if ( error )
V_31 = V_45 ;
if ( V_31 == V_54 ) {
V_6 -> V_62 = V_63 ;
F_9 ( V_20 , V_6 -> V_3 ,
L_6 ,
V_43 , V_6 -> V_64 ,
F_22 ( V_6 -> V_62 ) ) ;
}
V_34:
V_50 -> V_51 = NULL ;
F_23 ( V_50 -> V_19 , V_50 ) ;
if ( V_6 -> V_65 ) {
V_6 -> V_65 ( V_6 -> V_66 , V_31 ) ;
V_6 -> V_65 = V_6 -> V_66 = NULL ;
}
return;
}
static unsigned F_24 ( struct V_1 * V_6 )
{
struct V_13 * V_17 ;
int V_67 = 8 ;
struct V_2 * V_3 = V_6 -> V_3 ;
memset ( V_6 -> V_8 , 0 , V_67 ) ;
V_6 -> V_8 [ 4 ] = V_63 & 0x0f ;
V_6 -> V_8 [ 6 ] = ( V_6 -> V_64 >> 8 ) & 0xff ;
V_6 -> V_8 [ 7 ] = V_6 -> V_64 & 0xff ;
V_17 = F_6 ( V_3 , V_6 -> V_8 , V_67 , V_68 ) ;
if ( ! V_17 )
return V_32 ;
V_17 -> V_35 [ 0 ] = V_69 ;
V_17 -> V_35 [ 1 ] = V_70 ;
V_17 -> V_35 [ 6 ] = ( V_67 >> 24 ) & 0xff ;
V_17 -> V_35 [ 7 ] = ( V_67 >> 16 ) & 0xff ;
V_17 -> V_35 [ 8 ] = ( V_67 >> 8 ) & 0xff ;
V_17 -> V_35 [ 9 ] = V_67 & 0xff ;
V_17 -> V_37 = F_14 ( V_69 ) ;
V_17 -> V_38 = V_6 -> V_38 ;
memset ( V_17 -> V_38 , 0 , V_39 ) ;
V_17 -> V_40 = V_6 -> V_41 = 0 ;
V_17 -> V_51 = V_6 ;
F_25 ( V_17 -> V_19 , NULL , V_17 , 1 , F_17 ) ;
return V_54 ;
}
static int F_26 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_31 = V_54 ;
V_6 -> V_71 = F_27 ( V_3 ) ;
switch ( V_6 -> V_71 ) {
case V_72 | V_73 :
F_9 ( V_20 , V_3 ,
L_7 ,
V_43 ) ;
break;
case V_72 :
F_9 ( V_20 , V_3 , L_8 ,
V_43 ) ;
break;
case V_73 :
F_9 ( V_20 , V_3 , L_9 ,
V_43 ) ;
break;
default:
V_6 -> V_71 = V_74 ;
F_9 ( V_20 , V_3 , L_10 ,
V_43 ) ;
V_31 = V_75 ;
break;
}
return V_31 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_7 ;
unsigned V_31 ;
unsigned char * V_76 ;
V_77:
V_31 = F_13 ( V_3 , V_6 ) ;
if ( V_31 != V_54 )
return V_31 ;
V_7 = ( V_6 -> V_8 [ 2 ] << 8 ) + V_6 -> V_8 [ 3 ] + 4 ;
if ( V_7 > V_6 -> V_11 ) {
if ( F_3 ( V_6 , V_7 ) ) {
F_9 ( V_78 , V_3 ,
L_11 ,
V_43 ) ;
return V_79 ;
}
goto V_77;
}
V_76 = V_6 -> V_8 + 4 ;
while ( V_76 < V_6 -> V_8 + V_7 ) {
switch ( V_76 [ 1 ] & 0xf ) {
case 0x4 :
V_6 -> V_80 = ( V_76 [ 6 ] << 8 ) + V_76 [ 7 ] ;
break;
case 0x5 :
V_6 -> V_64 = ( V_76 [ 6 ] << 8 ) + V_76 [ 7 ] ;
break;
default:
break;
}
V_76 += V_76 [ 3 ] + 4 ;
}
if ( V_6 -> V_64 == - 1 ) {
F_9 ( V_20 , V_3 ,
L_12 ,
V_43 ) ;
V_6 -> V_62 = V_63 ;
V_6 -> V_71 = V_74 ;
V_31 = V_75 ;
} else {
F_9 ( V_20 , V_3 ,
L_13 ,
V_43 , V_6 -> V_64 , V_6 -> V_80 ) ;
}
return V_31 ;
}
static char F_22 ( int V_62 )
{
switch ( V_62 ) {
case V_63 :
return 'A' ;
case V_81 :
return 'N' ;
case V_82 :
return 'S' ;
case V_83 :
return 'U' ;
case V_84 :
return 'L' ;
case V_85 :
return 'O' ;
case V_86 :
return 'T' ;
default:
return 'X' ;
}
}
static int F_21 ( struct V_2 * V_3 ,
struct V_52 * V_53 )
{
switch ( V_53 -> V_59 ) {
case V_87 :
if ( V_53 -> V_60 == 0x04 && V_53 -> V_61 == 0x0a )
return V_57 ;
if ( V_53 -> V_60 == 0x04 && V_53 -> V_61 == 0x0b )
return V_88 ;
if ( V_53 -> V_60 == 0x04 && V_53 -> V_61 == 0x0c )
return V_88 ;
if ( V_53 -> V_60 == 0x04 && V_53 -> V_61 == 0x12 )
return V_88 ;
if ( V_3 -> V_89 &&
V_53 -> V_60 == 0x04 && V_53 -> V_61 == 0x02 )
return V_90 ;
break;
case V_91 :
if ( V_53 -> V_60 == 0x29 && V_53 -> V_61 == 0x00 )
return V_57 ;
if ( V_53 -> V_60 == 0x29 && V_53 -> V_61 == 0x04 )
return V_57 ;
if ( V_53 -> V_60 == 0x2a && V_53 -> V_61 == 0x01 )
return V_57 ;
if ( V_53 -> V_60 == 0x2a && V_53 -> V_61 == 0x06 )
return V_57 ;
if ( V_53 -> V_60 == 0x2a && V_53 -> V_61 == 0x07 )
return V_57 ;
if ( V_53 -> V_60 == 0x3f && V_53 -> V_61 == 0x03 )
return V_57 ;
if ( V_53 -> V_60 == 0x3f && V_53 -> V_61 == 0x0e )
return V_57 ;
break;
}
return V_92 ;
}
static int F_29 ( struct V_2 * V_3 , struct V_1 * V_6 , int V_93 )
{
struct V_52 V_53 ;
int V_7 , V_94 , V_95 , V_96 = 0 ;
unsigned char * V_97 ;
unsigned V_31 ;
bool V_46 = 1 ;
unsigned long V_98 , V_99 = 0 ;
unsigned int V_100 ;
unsigned char V_101 ;
if ( ! V_6 -> V_102 )
V_98 = F_30 ( V_103 + V_29 * V_30 ) ;
else
V_98 = F_30 ( V_103 + V_6 -> V_102 * V_30 ) ;
V_77:
V_31 = F_16 ( V_3 , V_6 , V_46 ) ;
if ( V_31 == V_45 && V_6 -> V_41 > 0 ) {
V_31 = F_20 ( V_6 -> V_38 , V_39 ,
& V_53 ) ;
if ( ! V_31 )
return V_45 ;
if ( V_46 == 1 &&
V_53 . V_59 == V_104 &&
V_53 . V_60 == 0x24 && V_53 . V_61 == 0 ) {
V_46 = 0 ;
goto V_77;
}
V_31 = F_21 ( V_3 , & V_53 ) ;
if ( V_31 == V_57 && F_31 ( V_103 , V_98 ) )
goto V_77;
F_9 ( V_20 , V_3 ,
L_14 ,
V_43 , V_53 . V_59 ,
V_53 . V_60 , V_53 . V_61 ) ;
V_31 = V_45 ;
}
if ( V_31 != V_54 )
return V_31 ;
V_7 = ( V_6 -> V_8 [ 0 ] << 24 ) + ( V_6 -> V_8 [ 1 ] << 16 ) +
( V_6 -> V_8 [ 2 ] << 8 ) + V_6 -> V_8 [ 3 ] + 4 ;
if ( V_7 > V_6 -> V_11 ) {
if ( F_3 ( V_6 , V_7 ) ) {
F_9 ( V_78 , V_3 ,
L_11 , V_21 ) ;
return V_79 ;
}
goto V_77;
}
V_101 = V_6 -> V_102 ;
if ( ( V_6 -> V_8 [ 4 ] & V_105 ) == V_106 && V_6 -> V_8 [ 5 ] != 0 )
V_6 -> V_102 = V_6 -> V_8 [ 5 ] ;
else
V_6 -> V_102 = V_29 ;
if ( V_93 && ( V_101 != V_6 -> V_102 ) ) {
F_9 ( V_20 , V_3 ,
L_15 ,
V_43 , V_6 -> V_102 ) ;
V_98 = V_103 + V_6 -> V_102 * V_30 ;
}
if ( ( V_6 -> V_8 [ 4 ] & V_105 ) == V_106 )
V_100 = 8 ;
else
V_100 = 4 ;
for ( V_94 = V_100 , V_97 = V_6 -> V_8 + V_100 ;
V_94 < V_7 ;
V_94 += V_95 , V_97 += V_95 ) {
if ( V_6 -> V_64 == ( V_97 [ 2 ] << 8 ) + V_97 [ 3 ] ) {
V_6 -> V_62 = V_97 [ 0 ] & 0x0f ;
V_6 -> V_107 = V_97 [ 0 ] >> 7 ;
V_96 = V_97 [ 1 ] ;
}
V_95 = 8 + ( V_97 [ 7 ] * 4 ) ;
}
F_9 ( V_20 , V_3 ,
L_16 ,
V_43 , V_6 -> V_64 , F_22 ( V_6 -> V_62 ) ,
V_6 -> V_107 ? L_17 : L_18 ,
V_96 & V_108 ? 'T' : 't' ,
V_96 & V_109 ? 'O' : 'o' ,
V_96 & V_110 ? 'L' : 'l' ,
V_96 & V_111 ? 'U' : 'u' ,
V_96 & V_112 ? 'S' : 's' ,
V_96 & V_113 ? 'N' : 'n' ,
V_96 & V_114 ? 'A' : 'a' ) ;
switch ( V_6 -> V_62 ) {
case V_86 :
if ( V_93 ) {
if ( F_31 ( V_103 , V_98 ) ) {
V_99 += 2000 ;
F_32 ( V_99 ) ;
goto V_77;
}
V_31 = V_58 ;
} else {
V_31 = V_54 ;
}
V_6 -> V_62 = V_82 ;
break;
case V_85 :
V_31 = V_115 ;
break;
default:
V_31 = V_54 ;
break;
}
return V_31 ;
}
static int F_33 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_31 ;
V_31 = F_26 ( V_3 , V_6 ) ;
if ( V_31 != V_54 )
goto V_116;
V_31 = F_28 ( V_3 , V_6 ) ;
if ( V_31 != V_54 )
goto V_116;
V_31 = F_29 ( V_3 , V_6 , 0 ) ;
if ( V_31 != V_54 )
goto V_116;
V_116:
return V_31 ;
}
static int F_34 ( struct V_2 * V_3 , const char * V_117 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned int V_118 = 0 , V_119 ;
const char * V_120 = V_117 ;
int V_121 = V_54 ;
if ( ( sscanf ( V_117 , L_19 , & V_119 ) != 1 ) || ( V_119 != 1 ) )
return - V_122 ;
while ( * V_120 ++ )
;
if ( ( sscanf ( V_120 , L_19 , & V_118 ) != 1 ) || ( V_118 > 1 ) )
return - V_122 ;
if ( V_118 )
V_6 -> V_123 |= V_124 ;
else
V_6 -> V_123 &= ~ V_124 ;
return V_121 ;
}
static int F_35 ( struct V_2 * V_3 ,
T_1 V_125 , void * V_126 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_31 = V_54 ;
int V_127 = 0 ;
V_31 = F_29 ( V_3 , V_6 , 1 ) ;
if ( V_31 != V_54 )
goto V_116;
if ( V_128 )
V_6 -> V_123 |= V_124 ;
if ( V_6 -> V_71 & V_72 ) {
switch ( V_6 -> V_62 ) {
case V_81 :
V_127 = 1 ;
if ( ( V_6 -> V_123 & V_124 ) &&
( ! V_6 -> V_107 ) &&
( V_6 -> V_71 & V_73 ) )
V_127 = 0 ;
break;
case V_82 :
case V_83 :
V_127 = 1 ;
break;
case V_85 :
V_31 = V_45 ;
break;
case V_86 :
V_31 = V_58 ;
break;
default:
break;
}
}
if ( V_127 ) {
V_6 -> V_65 = V_125 ;
V_6 -> V_66 = V_126 ;
V_31 = F_24 ( V_6 ) ;
if ( V_31 == V_54 )
return 0 ;
V_6 -> V_65 = V_6 -> V_66 = NULL ;
}
V_116:
if ( V_125 )
V_125 ( V_126 , V_31 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 , struct V_13 * V_50 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_129 = V_130 ;
if ( V_6 -> V_62 == V_86 )
V_129 = V_131 ;
else if ( V_6 -> V_62 != V_63 &&
V_6 -> V_62 != V_81 &&
V_6 -> V_62 != V_84 ) {
V_129 = V_132 ;
V_50 -> V_22 |= V_133 ;
}
return V_129 ;
}
static bool F_37 ( struct V_2 * V_3 )
{
return ( F_27 ( V_3 ) != 0 ) ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_123 ;
int V_31 = V_54 ;
V_4 = F_39 ( sizeof( * V_4 )
+ sizeof( * V_6 ) , V_134 ) ;
if ( ! V_4 ) {
F_9 ( V_135 , V_3 , L_20 ,
V_43 ) ;
return - V_136 ;
}
V_4 -> V_137 = & V_138 ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
V_6 -> V_71 = V_139 ;
V_6 -> V_62 = V_63 ;
V_6 -> V_64 = - 1 ;
V_6 -> V_80 = - 1 ;
V_6 -> V_8 = V_6 -> V_9 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_3 = V_3 ;
V_31 = F_33 ( V_3 , V_6 ) ;
if ( ( V_31 != V_54 ) && ( V_31 != V_115 ) )
goto V_140;
if ( ! F_40 ( V_141 ) )
goto V_140;
F_41 ( V_3 -> V_18 -> V_142 , V_123 ) ;
V_3 -> V_4 = V_4 ;
F_42 ( V_3 -> V_18 -> V_142 , V_123 ) ;
F_9 ( V_143 , V_3 , L_21 , V_43 ) ;
return 0 ;
V_140:
F_4 ( V_4 ) ;
F_9 ( V_135 , V_3 , L_22 , V_43 ) ;
return - V_122 ;
}
static void F_43 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_123 ;
F_41 ( V_3 -> V_18 -> V_142 , V_123 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_42 ( V_3 -> V_18 -> V_142 , V_123 ) ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
if ( V_6 -> V_8 && V_6 -> V_9 != V_6 -> V_8 )
F_4 ( V_6 -> V_8 ) ;
F_4 ( V_4 ) ;
F_44 ( V_141 ) ;
F_9 ( V_143 , V_3 , L_23 , V_43 ) ;
}
static int T_2 F_45 ( void )
{
int V_144 ;
V_144 = F_46 ( & V_138 ) ;
if ( V_144 != 0 )
F_47 ( V_135 L_24 ,
V_43 ) ;
return V_144 ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_138 ) ;
}
