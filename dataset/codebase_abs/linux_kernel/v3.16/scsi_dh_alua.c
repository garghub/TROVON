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
F_9 ( V_17 ) ;
if ( V_15 && F_10 ( V_19 , V_17 , V_14 , V_15 , V_10 ) ) {
F_11 ( V_17 ) ;
F_8 ( V_20 , V_3 ,
L_2 , V_21 ) ;
return NULL ;
}
V_17 -> V_22 |= V_23 | V_24 |
V_25 ;
V_17 -> V_26 = V_27 ;
V_17 -> V_28 = V_29 * V_30 ;
return V_17 ;
}
static int F_12 ( struct V_2 * V_3 , struct V_1 * V_6 )
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
V_17 -> V_37 = F_13 ( V_36 ) ;
V_17 -> V_38 = V_6 -> V_38 ;
memset ( V_17 -> V_38 , 0 , V_39 ) ;
V_17 -> V_40 = V_6 -> V_41 = 0 ;
V_31 = F_14 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_31 == - V_42 ) {
F_8 ( V_20 , V_3 ,
L_3 ,
V_43 , V_17 -> V_44 ) ;
V_6 -> V_41 = V_17 -> V_40 ;
V_31 = V_45 ;
}
F_11 ( V_17 ) ;
V_34:
return V_31 ;
}
static unsigned F_15 ( struct V_2 * V_3 , struct V_1 * V_6 ,
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
V_17 -> V_37 = F_13 ( V_47 ) ;
V_17 -> V_38 = V_6 -> V_38 ;
memset ( V_17 -> V_38 , 0 , V_39 ) ;
V_17 -> V_40 = V_6 -> V_41 = 0 ;
V_31 = F_14 ( V_17 -> V_19 , NULL , V_17 , 1 ) ;
if ( V_31 == - V_42 ) {
F_8 ( V_20 , V_3 ,
L_4 ,
V_43 , V_17 -> V_44 ) ;
V_6 -> V_41 = V_17 -> V_40 ;
V_31 = V_45 ;
}
F_11 ( V_17 ) ;
V_34:
return V_31 ;
}
static void F_16 ( struct V_13 * V_50 , int error )
{
struct V_1 * V_6 = V_50 -> V_51 ;
struct V_52 V_53 ;
unsigned V_31 = V_54 ;
if ( F_17 ( V_50 -> V_44 ) != V_55 ||
F_18 ( V_50 -> V_44 ) != V_56 ) {
V_31 = V_45 ;
goto V_34;
}
if ( V_50 -> V_40 > 0 ) {
V_31 = F_19 ( V_6 -> V_38 , V_39 ,
& V_53 ) ;
if ( ! V_31 ) {
V_31 = V_45 ;
goto V_34;
}
V_31 = F_20 ( V_6 -> V_3 , & V_53 ) ;
if ( V_31 == V_57 ) {
V_31 = V_58 ;
goto V_34;
}
F_8 ( V_20 , V_6 -> V_3 ,
L_5 ,
V_43 , V_53 . V_59 ,
V_53 . V_60 , V_53 . V_61 ) ;
V_31 = V_45 ;
} else if ( error )
V_31 = V_45 ;
if ( V_31 == V_54 ) {
V_6 -> V_62 = V_63 ;
F_8 ( V_20 , V_6 -> V_3 ,
L_6 ,
V_43 , V_6 -> V_64 ,
F_21 ( V_6 -> V_62 ) ) ;
}
V_34:
V_50 -> V_51 = NULL ;
F_22 ( V_50 -> V_19 , V_50 ) ;
if ( V_6 -> V_65 ) {
V_6 -> V_65 ( V_6 -> V_66 , V_31 ) ;
V_6 -> V_65 = V_6 -> V_66 = NULL ;
}
return;
}
static unsigned F_23 ( struct V_1 * V_6 )
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
V_17 -> V_37 = F_13 ( V_69 ) ;
V_17 -> V_38 = V_6 -> V_38 ;
memset ( V_17 -> V_38 , 0 , V_39 ) ;
V_17 -> V_40 = V_6 -> V_41 = 0 ;
V_17 -> V_51 = V_6 ;
F_24 ( V_17 -> V_19 , NULL , V_17 , 1 , F_16 ) ;
return V_54 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_31 = V_54 ;
V_6 -> V_71 = F_26 ( V_3 ) ;
switch ( V_6 -> V_71 ) {
case V_72 | V_73 :
F_8 ( V_20 , V_3 ,
L_7 ,
V_43 ) ;
break;
case V_72 :
F_8 ( V_20 , V_3 , L_8 ,
V_43 ) ;
break;
case V_73 :
F_8 ( V_20 , V_3 , L_9 ,
V_43 ) ;
break;
default:
V_6 -> V_71 = V_74 ;
F_8 ( V_20 , V_3 , L_10 ,
V_43 ) ;
V_31 = V_75 ;
break;
}
return V_31 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_7 ;
unsigned V_31 ;
unsigned char * V_76 ;
V_77:
V_31 = F_12 ( V_3 , V_6 ) ;
if ( V_31 != V_54 )
return V_31 ;
V_7 = ( V_6 -> V_8 [ 2 ] << 8 ) + V_6 -> V_8 [ 3 ] + 4 ;
if ( V_7 > V_6 -> V_11 ) {
if ( F_3 ( V_6 , V_7 ) ) {
F_8 ( V_78 , V_3 ,
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
F_8 ( V_20 , V_3 ,
L_12 ,
V_43 ) ;
V_6 -> V_62 = V_63 ;
V_6 -> V_71 = V_74 ;
V_31 = V_75 ;
} else {
F_8 ( V_20 , V_3 ,
L_13 ,
V_43 , V_6 -> V_64 , V_6 -> V_80 ) ;
}
return V_31 ;
}
static char F_21 ( int V_62 )
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
static int F_20 ( struct V_2 * V_3 ,
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
break;
case V_89 :
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
return V_90 ;
}
static int F_28 ( struct V_2 * V_3 , struct V_1 * V_6 , int V_91 )
{
struct V_52 V_53 ;
int V_7 , V_92 , V_93 , V_94 = 0 ;
unsigned char * V_95 ;
unsigned V_31 ;
bool V_46 = 1 ;
unsigned long V_96 , V_97 = 0 ;
unsigned int V_98 ;
unsigned char V_99 ;
if ( ! V_6 -> V_100 )
V_96 = F_29 ( V_101 + V_29 * V_30 ) ;
else
V_96 = F_29 ( V_101 + V_6 -> V_100 * V_30 ) ;
V_77:
V_31 = F_15 ( V_3 , V_6 , V_46 ) ;
if ( V_31 == V_45 && V_6 -> V_41 > 0 ) {
V_31 = F_19 ( V_6 -> V_38 , V_39 ,
& V_53 ) ;
if ( ! V_31 )
return V_45 ;
if ( V_46 == 1 &&
V_53 . V_59 == V_102 &&
V_53 . V_60 == 0x24 && V_53 . V_61 == 0 ) {
V_46 = 0 ;
goto V_77;
}
V_31 = F_20 ( V_3 , & V_53 ) ;
if ( V_31 == V_57 && F_30 ( V_101 , V_96 ) )
goto V_77;
F_8 ( V_20 , V_3 ,
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
F_8 ( V_78 , V_3 ,
L_11 , V_21 ) ;
return V_79 ;
}
goto V_77;
}
V_99 = V_6 -> V_100 ;
if ( ( V_6 -> V_8 [ 4 ] & V_103 ) == V_104 && V_6 -> V_8 [ 5 ] != 0 )
V_6 -> V_100 = V_6 -> V_8 [ 5 ] ;
else
V_6 -> V_100 = V_29 ;
if ( V_91 && ( V_99 != V_6 -> V_100 ) ) {
F_8 ( V_20 , V_3 ,
L_15 ,
V_43 , V_6 -> V_100 ) ;
V_96 = V_101 + V_6 -> V_100 * V_30 ;
}
if ( ( V_6 -> V_8 [ 4 ] & V_103 ) == V_104 )
V_98 = 8 ;
else
V_98 = 4 ;
for ( V_92 = V_98 , V_95 = V_6 -> V_8 + V_98 ;
V_92 < V_7 ;
V_92 += V_93 , V_95 += V_93 ) {
if ( V_6 -> V_64 == ( V_95 [ 2 ] << 8 ) + V_95 [ 3 ] ) {
V_6 -> V_62 = V_95 [ 0 ] & 0x0f ;
V_6 -> V_105 = V_95 [ 0 ] >> 7 ;
V_94 = V_95 [ 1 ] ;
}
V_93 = 8 + ( V_95 [ 7 ] * 4 ) ;
}
F_8 ( V_20 , V_3 ,
L_16 ,
V_43 , V_6 -> V_64 , F_21 ( V_6 -> V_62 ) ,
V_6 -> V_105 ? L_17 : L_18 ,
V_94 & V_106 ? 'T' : 't' ,
V_94 & V_107 ? 'O' : 'o' ,
V_94 & V_108 ? 'L' : 'l' ,
V_94 & V_109 ? 'U' : 'u' ,
V_94 & V_110 ? 'S' : 's' ,
V_94 & V_111 ? 'N' : 'n' ,
V_94 & V_112 ? 'A' : 'a' ) ;
switch ( V_6 -> V_62 ) {
case V_86 :
if ( V_91 ) {
if ( F_30 ( V_101 , V_96 ) ) {
V_97 += 2000 ;
F_31 ( V_97 ) ;
goto V_77;
}
V_31 = V_58 ;
} else {
V_31 = V_54 ;
}
V_6 -> V_62 = V_82 ;
break;
case V_85 :
V_31 = V_113 ;
break;
default:
V_31 = V_54 ;
break;
}
return V_31 ;
}
static int F_32 ( struct V_2 * V_3 , struct V_1 * V_6 )
{
int V_31 ;
V_31 = F_25 ( V_3 , V_6 ) ;
if ( V_31 != V_54 )
goto V_114;
V_31 = F_27 ( V_3 , V_6 ) ;
if ( V_31 != V_54 )
goto V_114;
V_31 = F_28 ( V_3 , V_6 , 0 ) ;
if ( V_31 != V_54 )
goto V_114;
V_114:
return V_31 ;
}
static int F_33 ( struct V_2 * V_3 , const char * V_115 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
unsigned int V_116 = 0 , V_117 ;
const char * V_118 = V_115 ;
int V_119 = V_54 ;
if ( ( sscanf ( V_115 , L_19 , & V_117 ) != 1 ) || ( V_117 != 1 ) )
return - V_120 ;
while ( * V_118 ++ )
;
if ( ( sscanf ( V_118 , L_19 , & V_116 ) != 1 ) || ( V_116 > 1 ) )
return - V_120 ;
if ( V_116 )
V_6 -> V_121 |= V_122 ;
else
V_6 -> V_121 &= ~ V_122 ;
return V_119 ;
}
static int F_34 ( struct V_2 * V_3 ,
T_1 V_123 , void * V_124 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_31 = V_54 ;
int V_125 = 0 ;
V_31 = F_28 ( V_3 , V_6 , 1 ) ;
if ( V_31 != V_54 )
goto V_114;
if ( V_126 )
V_6 -> V_121 |= V_122 ;
if ( V_6 -> V_71 & V_72 ) {
switch ( V_6 -> V_62 ) {
case V_81 :
V_125 = 1 ;
if ( ( V_6 -> V_121 & V_122 ) &&
( ! V_6 -> V_105 ) &&
( V_6 -> V_71 & V_73 ) )
V_125 = 0 ;
break;
case V_82 :
case V_83 :
V_125 = 1 ;
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
if ( V_125 ) {
V_6 -> V_65 = V_123 ;
V_6 -> V_66 = V_124 ;
V_31 = F_23 ( V_6 ) ;
if ( V_31 == V_54 )
return 0 ;
V_6 -> V_65 = V_6 -> V_66 = NULL ;
}
V_114:
if ( V_123 )
V_123 ( V_124 , V_31 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 , struct V_13 * V_50 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
int V_127 = V_128 ;
if ( V_6 -> V_62 == V_86 )
V_127 = V_129 ;
else if ( V_6 -> V_62 != V_63 &&
V_6 -> V_62 != V_81 &&
V_6 -> V_62 != V_84 ) {
V_127 = V_130 ;
V_50 -> V_22 |= V_131 ;
}
return V_127 ;
}
static bool F_36 ( struct V_2 * V_3 )
{
return ( F_26 ( V_3 ) != 0 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_121 ;
int V_31 = V_54 ;
V_4 = F_38 ( sizeof( * V_4 )
+ sizeof( * V_6 ) , V_132 ) ;
if ( ! V_4 ) {
F_8 ( V_133 , V_3 , L_20 ,
V_43 ) ;
return - V_134 ;
}
V_4 -> V_135 = & V_136 ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
V_6 -> V_71 = V_137 ;
V_6 -> V_62 = V_63 ;
V_6 -> V_64 = - 1 ;
V_6 -> V_80 = - 1 ;
V_6 -> V_8 = V_6 -> V_9 ;
V_6 -> V_11 = V_12 ;
V_6 -> V_3 = V_3 ;
V_31 = F_32 ( V_3 , V_6 ) ;
if ( ( V_31 != V_54 ) && ( V_31 != V_113 ) )
goto V_138;
if ( ! F_39 ( V_139 ) )
goto V_138;
F_40 ( V_3 -> V_18 -> V_140 , V_121 ) ;
V_3 -> V_4 = V_4 ;
F_41 ( V_3 -> V_18 -> V_140 , V_121 ) ;
F_8 ( V_141 , V_3 , L_21 , V_43 ) ;
return 0 ;
V_138:
F_4 ( V_4 ) ;
F_8 ( V_133 , V_3 , L_22 , V_43 ) ;
return - V_120 ;
}
static void F_42 ( struct V_2 * V_3 )
{
struct V_4 * V_4 ;
struct V_1 * V_6 ;
unsigned long V_121 ;
F_40 ( V_3 -> V_18 -> V_140 , V_121 ) ;
V_4 = V_3 -> V_4 ;
V_3 -> V_4 = NULL ;
F_41 ( V_3 -> V_18 -> V_140 , V_121 ) ;
V_6 = (struct V_1 * ) V_4 -> V_5 ;
if ( V_6 -> V_8 && V_6 -> V_9 != V_6 -> V_8 )
F_4 ( V_6 -> V_8 ) ;
F_4 ( V_4 ) ;
F_43 ( V_139 ) ;
F_8 ( V_141 , V_3 , L_23 , V_43 ) ;
}
static int T_2 F_44 ( void )
{
int V_142 ;
V_142 = F_45 ( & V_136 ) ;
if ( V_142 != 0 )
F_46 ( V_133 L_24 ,
V_43 ) ;
return V_142 ;
}
static void T_3 F_47 ( void )
{
F_48 ( & V_136 ) ;
}
