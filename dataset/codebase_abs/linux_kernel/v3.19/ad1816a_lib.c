static inline int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
for ( V_3 = 1000 ; V_3 -- > 0 ; F_2 ( 10 ) )
if ( F_3 ( F_4 ( V_4 ) ) & V_5 )
return 0 ;
F_5 ( V_6 L_1 ) ;
return - V_7 ;
}
static inline unsigned char F_6 ( struct V_1 * V_2 , unsigned char V_8 )
{
F_1 ( V_2 ) ;
return F_3 ( F_4 ( V_8 ) ) ;
}
static inline void F_7 ( struct V_1 * V_2 , unsigned char V_8 ,
unsigned char V_9 )
{
F_1 ( V_2 ) ;
F_8 ( V_9 , F_4 ( V_8 ) ) ;
}
static inline void F_9 ( struct V_1 * V_2 , unsigned char V_8 ,
unsigned char V_10 , unsigned char V_9 )
{
F_7 ( V_2 , V_8 ,
( V_9 & V_10 ) | ( F_6 ( V_2 , V_8 ) & ~ V_10 ) ) ;
}
static unsigned short F_10 ( struct V_1 * V_2 , unsigned char V_8 )
{
F_7 ( V_2 , V_11 , V_8 & 0x3f ) ;
return F_6 ( V_2 , V_12 ) |
( F_6 ( V_2 , V_13 ) << 8 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned char V_8 ,
unsigned short V_9 )
{
F_7 ( V_2 , V_11 , V_8 & 0x3f ) ;
F_7 ( V_2 , V_12 , V_9 & 0xff ) ;
F_7 ( V_2 , V_13 , ( V_9 >> 8 ) & 0xff ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned char V_8 ,
unsigned short V_10 , unsigned short V_9 )
{
F_11 ( V_2 , V_8 ,
( V_9 & V_10 ) | ( F_10 ( V_2 , V_8 ) & ~ V_10 ) ) ;
}
static unsigned char F_13 ( struct V_1 * V_2 ,
unsigned int V_14 , int V_15 )
{
unsigned char V_16 = V_17 ;
switch ( V_14 ) {
case V_18 :
V_16 = V_19 ;
break;
case V_20 :
V_16 = V_21 ;
break;
case V_22 :
V_16 = V_23 ;
break;
case V_24 :
V_16 = V_25 ;
}
return ( V_15 > 1 ) ? ( V_16 | V_26 ) : V_16 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned int V_27 )
{
unsigned long V_28 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
if ( V_2 -> V_27 & V_27 ) {
F_16 ( & V_2 -> V_29 , V_28 ) ;
return - V_30 ;
}
switch ( ( V_27 &= V_31 ) ) {
case V_32 :
F_9 ( V_2 , V_33 ,
V_34 , 0x00 ) ;
F_12 ( V_2 , V_35 ,
V_36 , 0xffff ) ;
break;
case V_37 :
F_9 ( V_2 , V_33 ,
V_38 , 0x00 ) ;
F_12 ( V_2 , V_35 ,
V_39 , 0xffff ) ;
break;
case V_40 :
F_9 ( V_2 , V_33 ,
V_41 , 0x00 ) ;
F_12 ( V_2 , V_35 ,
V_42 , 0xffff ) ;
}
V_2 -> V_27 |= V_27 ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned int V_27 )
{
unsigned long V_28 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
switch ( ( V_27 &= V_31 ) ) {
case V_32 :
F_9 ( V_2 , V_33 ,
V_34 , 0x00 ) ;
F_12 ( V_2 , V_35 ,
V_36 , 0x0000 ) ;
break;
case V_37 :
F_9 ( V_2 , V_33 ,
V_38 , 0x00 ) ;
F_12 ( V_2 , V_35 ,
V_39 , 0x0000 ) ;
break;
case V_40 :
F_9 ( V_2 , V_33 ,
V_41 , 0x00 ) ;
F_12 ( V_2 , V_35 ,
V_42 , 0x0000 ) ;
}
if ( ! ( ( V_2 -> V_27 &= ~ V_27 ) & V_31 ) )
V_2 -> V_27 = 0 ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
}
static int F_18 ( struct V_1 * V_2 , unsigned char V_43 ,
int V_44 , int V_45 , int V_46 )
{
int error = 0 ;
switch ( V_45 ) {
case V_47 :
case V_48 :
F_19 ( & V_2 -> V_29 ) ;
V_45 = ( V_45 == V_47 ) ? 0xff : 0x00 ;
if ( ! V_46 )
F_9 ( V_2 , V_49 ,
V_50 , V_45 ) ;
else
F_9 ( V_2 , V_51 ,
V_52 , V_45 ) ;
F_20 ( & V_2 -> V_29 ) ;
break;
default:
F_5 ( V_6 L_2 , V_43 ) ;
error = - V_53 ;
}
return error ;
}
static int F_21 ( struct V_54 * V_55 , int V_45 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
return F_18 ( V_2 , V_50 ,
V_56 , V_45 , 0 ) ;
}
static int F_23 ( struct V_54 * V_55 , int V_45 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
return F_18 ( V_2 , V_52 ,
V_57 , V_45 , 1 ) ;
}
static int F_24 ( struct V_54 * V_55 ,
struct V_58 * V_59 )
{
return F_25 ( V_55 , F_26 ( V_59 ) ) ;
}
static int F_27 ( struct V_54 * V_55 )
{
return F_28 ( V_55 ) ;
}
static int F_29 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
unsigned long V_28 ;
struct V_60 * V_61 = V_55 -> V_61 ;
unsigned int V_62 , V_63 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_2 -> V_64 = V_62 = F_30 ( V_55 ) ;
F_9 ( V_2 , V_49 ,
V_50 | V_65 , 0x00 ) ;
F_31 ( V_2 -> V_66 , V_61 -> V_67 , V_62 ,
V_68 | V_69 ) ;
V_63 = V_61 -> V_63 ;
if ( V_2 -> V_70 )
V_63 = ( V_63 * 33000 ) / V_2 -> V_70 ;
F_11 ( V_2 , V_71 , V_63 ) ;
F_9 ( V_2 , V_49 ,
V_72 | V_26 ,
F_13 ( V_2 , V_61 -> V_14 ,
V_61 -> V_15 ) ) ;
F_11 ( V_2 , V_73 ,
F_32 ( V_55 ) / 4 - 1 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
return 0 ;
}
static int F_33 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
unsigned long V_28 ;
struct V_60 * V_61 = V_55 -> V_61 ;
unsigned int V_62 , V_63 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_2 -> V_74 = V_62 = F_30 ( V_55 ) ;
F_9 ( V_2 , V_51 ,
V_52 | V_75 , 0x00 ) ;
F_31 ( V_2 -> V_76 , V_61 -> V_67 , V_62 ,
V_77 | V_69 ) ;
V_63 = V_61 -> V_63 ;
if ( V_2 -> V_70 )
V_63 = ( V_63 * 33000 ) / V_2 -> V_70 ;
F_11 ( V_2 , V_78 , V_63 ) ;
F_9 ( V_2 , V_51 ,
V_72 | V_26 ,
F_13 ( V_2 , V_61 -> V_14 ,
V_61 -> V_15 ) ) ;
F_11 ( V_2 , V_79 ,
F_32 ( V_55 ) / 4 - 1 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
return 0 ;
}
static T_1 F_34 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
T_2 V_80 ;
if ( ! ( V_2 -> V_27 & V_32 ) )
return 0 ;
V_80 = F_35 ( V_2 -> V_66 , V_2 -> V_64 ) ;
return F_36 ( V_55 -> V_61 , V_80 ) ;
}
static T_1 F_37 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
T_2 V_80 ;
if ( ! ( V_2 -> V_27 & V_37 ) )
return 0 ;
V_80 = F_35 ( V_2 -> V_76 , V_2 -> V_74 ) ;
return F_36 ( V_55 -> V_61 , V_80 ) ;
}
static T_3 F_38 ( int V_81 , void * V_82 )
{
struct V_1 * V_2 = V_82 ;
unsigned char V_83 ;
F_19 ( & V_2 -> V_29 ) ;
V_83 = F_6 ( V_2 , V_33 ) ;
F_20 ( & V_2 -> V_29 ) ;
if ( ( V_83 & V_34 ) && V_2 -> V_84 )
F_39 ( V_2 -> V_84 ) ;
if ( ( V_83 & V_38 ) && V_2 -> V_85 )
F_39 ( V_2 -> V_85 ) ;
if ( ( V_83 & V_41 ) && V_2 -> V_86 )
F_40 ( V_2 -> V_86 , V_2 -> V_86 -> V_87 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_7 ( V_2 , V_33 , 0x00 ) ;
F_20 ( & V_2 -> V_29 ) ;
return V_88 ;
}
static int F_41 ( struct V_89 * V_86 )
{
struct V_1 * V_2 = F_42 ( V_86 ) ;
F_17 ( V_2 , V_40 ) ;
return 0 ;
}
static int F_43 ( struct V_89 * V_86 )
{
struct V_1 * V_2 = F_42 ( V_86 ) ;
F_14 ( V_2 , V_40 ) ;
return 0 ;
}
static unsigned long F_44 ( struct V_89 * V_86 )
{
if ( F_45 ( ! V_86 ) )
return 0 ;
return 10000 ;
}
static int F_46 ( struct V_89 * V_86 )
{
unsigned short V_90 ;
unsigned long V_28 ;
struct V_1 * V_2 = F_42 ( V_86 ) ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_90 = F_10 ( V_2 , V_35 ) ;
if ( ! ( V_90 & V_91 ) ) {
F_11 ( V_2 , V_92 ,
V_86 -> V_87 & 0xffff ) ;
F_12 ( V_2 , V_35 ,
V_91 , 0xffff ) ;
}
F_16 ( & V_2 -> V_29 , V_28 ) ;
return 0 ;
}
static int F_47 ( struct V_89 * V_86 )
{
unsigned long V_28 ;
struct V_1 * V_2 = F_42 ( V_86 ) ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
F_12 ( V_2 , V_35 ,
V_91 , 0x0000 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
return 0 ;
}
static int F_48 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
struct V_60 * V_61 = V_55 -> V_61 ;
int error ;
if ( ( error = F_14 ( V_2 , V_32 ) ) < 0 )
return error ;
V_61 -> V_93 = V_94 ;
F_49 ( V_2 -> V_66 , & V_61 -> V_93 . V_95 ) ;
F_49 ( V_2 -> V_66 , & V_61 -> V_93 . V_96 ) ;
V_2 -> V_84 = V_55 ;
return 0 ;
}
static int F_50 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
struct V_60 * V_61 = V_55 -> V_61 ;
int error ;
if ( ( error = F_14 ( V_2 , V_37 ) ) < 0 )
return error ;
V_61 -> V_93 = V_97 ;
F_49 ( V_2 -> V_76 , & V_61 -> V_93 . V_95 ) ;
F_49 ( V_2 -> V_76 , & V_61 -> V_93 . V_96 ) ;
V_2 -> V_85 = V_55 ;
return 0 ;
}
static int F_51 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
V_2 -> V_84 = NULL ;
F_17 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_52 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_22 ( V_55 ) ;
V_2 -> V_85 = NULL ;
F_17 ( V_2 , V_37 ) ;
return 0 ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
F_7 ( V_2 , V_33 , 0x00 ) ;
F_9 ( V_2 , V_49 ,
V_50 | V_65 , 0x00 ) ;
F_9 ( V_2 , V_51 ,
V_52 | V_75 , 0x00 ) ;
F_11 ( V_2 , V_35 , 0x0000 ) ;
F_12 ( V_2 , V_98 ,
V_99 | V_100 , 0xffff ) ;
F_11 ( V_2 , V_101 , 0x0000 ) ;
F_11 ( V_2 , V_102 , 0x0000 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
}
void F_54 ( struct V_1 * V_2 )
{
int V_8 ;
unsigned long V_28 ;
F_55 ( V_2 -> V_103 ) ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
for ( V_8 = 0 ; V_8 < 48 ; V_8 ++ )
V_2 -> V_104 [ V_8 ] = F_10 ( V_2 , V_8 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
}
void F_56 ( struct V_1 * V_2 )
{
int V_8 ;
unsigned long V_28 ;
F_53 ( V_2 ) ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
for ( V_8 = 0 ; V_8 < 48 ; V_8 ++ )
F_11 ( V_2 , V_8 , V_2 -> V_104 [ V_8 ] ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
}
static int F_57 ( struct V_1 * V_2 )
{
unsigned long V_28 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
switch ( V_2 -> V_105 = F_10 ( V_2 , V_106 ) ) {
case 0 :
V_2 -> V_107 = V_108 ;
break;
case 1 :
V_2 -> V_107 = V_109 ;
break;
case 3 :
V_2 -> V_107 = V_110 ;
break;
default:
V_2 -> V_107 = V_111 ;
}
F_16 ( & V_2 -> V_29 , V_28 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
F_59 ( V_2 -> V_112 ) ;
if ( V_2 -> V_81 >= 0 )
F_60 ( V_2 -> V_81 , ( void * ) V_2 ) ;
if ( V_2 -> V_66 >= 0 ) {
F_61 ( V_2 -> V_66 ) ;
F_62 ( V_2 -> V_66 ) ;
}
if ( V_2 -> V_76 >= 0 ) {
F_61 ( V_2 -> V_76 ) ;
F_62 ( V_2 -> V_76 ) ;
}
return 0 ;
}
static int F_63 ( struct V_113 * V_114 )
{
struct V_1 * V_2 = V_114 -> V_115 ;
return F_58 ( V_2 ) ;
}
static const char * F_64 ( struct V_1 * V_2 )
{
switch ( V_2 -> V_107 ) {
case V_110 : return L_3 ;
case V_108 : return L_4 ;
case V_109 : return L_5 ;
default:
F_5 ( V_6 L_6 ,
V_2 -> V_105 , V_2 -> V_107 ) ;
return L_7 ;
}
}
int F_65 ( struct V_116 * V_117 ,
unsigned long V_118 , int V_81 , int V_66 , int V_76 ,
struct V_1 * V_2 )
{
static struct V_119 V_120 = {
. V_121 = F_63 ,
} ;
int error ;
V_2 -> V_81 = - 1 ;
V_2 -> V_66 = - 1 ;
V_2 -> V_76 = - 1 ;
if ( ( V_2 -> V_112 = F_66 ( V_118 , 16 , L_3 ) ) == NULL ) {
F_5 ( V_122 L_8 , V_118 ) ;
F_58 ( V_2 ) ;
return - V_7 ;
}
if ( F_67 ( V_81 , F_38 , 0 , L_3 , ( void * ) V_2 ) ) {
F_5 ( V_122 L_9 , V_81 ) ;
F_58 ( V_2 ) ;
return - V_7 ;
}
V_2 -> V_81 = V_81 ;
if ( F_68 ( V_66 , L_10 ) ) {
F_5 ( V_122 L_11 , V_66 ) ;
F_58 ( V_2 ) ;
return - V_7 ;
}
V_2 -> V_66 = V_66 ;
if ( F_68 ( V_76 , L_12 ) ) {
F_5 ( V_122 L_13 , V_76 ) ;
F_58 ( V_2 ) ;
return - V_7 ;
}
V_2 -> V_76 = V_76 ;
V_2 -> V_117 = V_117 ;
V_2 -> V_118 = V_118 ;
F_69 ( & V_2 -> V_29 ) ;
if ( ( error = F_57 ( V_2 ) ) ) {
F_58 ( V_2 ) ;
return error ;
}
F_53 ( V_2 ) ;
if ( ( error = F_70 ( V_117 , V_123 , V_2 , & V_120 ) ) < 0 ) {
F_58 ( V_2 ) ;
return error ;
}
return 0 ;
}
int F_71 ( struct V_1 * V_2 , int V_114 , struct V_124 * * V_125 )
{
int error ;
struct V_124 * V_103 ;
if ( ( error = F_72 ( V_2 -> V_117 , L_3 , V_114 , 1 , 1 , & V_103 ) ) )
return error ;
F_73 ( V_103 , V_56 , & V_126 ) ;
F_73 ( V_103 , V_57 , & V_127 ) ;
V_103 -> V_128 = V_2 ;
V_103 -> V_129 = ( V_2 -> V_66 == V_2 -> V_76 ) ? V_130 : 0 ;
strcpy ( V_103 -> V_131 , F_64 ( V_2 ) ) ;
F_53 ( V_2 ) ;
F_74 ( V_103 , V_132 ,
F_75 () ,
64 * 1024 , V_2 -> V_66 > 3 || V_2 -> V_76 > 3 ? 128 * 1024 : 64 * 1024 ) ;
V_2 -> V_103 = V_103 ;
if ( V_125 )
* V_125 = V_103 ;
return 0 ;
}
int F_76 ( struct V_1 * V_2 , int V_114 ,
struct V_89 * * V_133 )
{
struct V_89 * V_86 ;
struct V_134 V_135 ;
int error ;
V_135 . V_136 = V_137 ;
V_135 . V_138 = V_139 ;
V_135 . V_117 = V_2 -> V_117 -> V_140 ;
V_135 . V_114 = V_114 ;
V_135 . V_141 = 0 ;
if ( ( error = F_77 ( V_2 -> V_117 , L_3 , & V_135 , & V_86 ) ) < 0 )
return error ;
strcpy ( V_86 -> V_131 , F_64 ( V_2 ) ) ;
V_86 -> V_128 = V_2 ;
V_2 -> V_86 = V_86 ;
V_86 -> V_93 = V_142 ;
if ( V_133 )
* V_133 = V_86 ;
return 0 ;
}
static int F_78 ( struct V_143 * V_144 , struct V_145 * V_146 )
{
static const char * const V_147 [ 8 ] = {
L_14 , L_15 , L_16 , L_17 , L_18 ,
L_19 , L_20 ,
} ;
return F_79 ( V_146 , 2 , 7 , V_147 ) ;
}
static int F_80 ( struct V_143 * V_144 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_81 ( V_144 ) ;
unsigned long V_28 ;
unsigned short V_150 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_150 = F_10 ( V_2 , V_151 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
V_149 -> V_9 . V_152 . V_153 [ 0 ] = ( V_150 >> 12 ) & 7 ;
V_149 -> V_9 . V_152 . V_153 [ 1 ] = ( V_150 >> 4 ) & 7 ;
return 0 ;
}
static int F_82 ( struct V_143 * V_144 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_81 ( V_144 ) ;
unsigned long V_28 ;
unsigned short V_150 ;
int V_154 ;
if ( V_149 -> V_9 . V_152 . V_153 [ 0 ] > 6 ||
V_149 -> V_9 . V_152 . V_153 [ 1 ] > 6 )
return - V_53 ;
V_150 = ( V_149 -> V_9 . V_152 . V_153 [ 0 ] << 12 ) |
( V_149 -> V_9 . V_152 . V_153 [ 1 ] << 4 ) ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_154 = F_10 ( V_2 , V_151 ) != V_150 ;
F_11 ( V_2 , V_151 , V_150 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
return V_154 ;
}
static int F_83 ( struct V_143 * V_144 , struct V_145 * V_146 )
{
int V_10 = ( V_144 -> V_155 >> 16 ) & 0xff ;
V_146 -> type = V_10 == 1 ? V_156 : V_157 ;
V_146 -> V_158 = 1 ;
V_146 -> V_9 . integer . V_159 = 0 ;
V_146 -> V_9 . integer . V_160 = V_10 ;
return 0 ;
}
static int F_84 ( struct V_143 * V_144 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_81 ( V_144 ) ;
unsigned long V_28 ;
int V_8 = V_144 -> V_155 & 0xff ;
int V_161 = ( V_144 -> V_155 >> 8 ) & 0xff ;
int V_10 = ( V_144 -> V_155 >> 16 ) & 0xff ;
int V_162 = ( V_144 -> V_155 >> 24 ) & 0xff ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_149 -> V_9 . integer . V_9 [ 0 ] = ( F_10 ( V_2 , V_8 ) >> V_161 ) & V_10 ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
if ( V_162 )
V_149 -> V_9 . integer . V_9 [ 0 ] = V_10 - V_149 -> V_9 . integer . V_9 [ 0 ] ;
return 0 ;
}
static int F_85 ( struct V_143 * V_144 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_81 ( V_144 ) ;
unsigned long V_28 ;
int V_8 = V_144 -> V_155 & 0xff ;
int V_161 = ( V_144 -> V_155 >> 8 ) & 0xff ;
int V_10 = ( V_144 -> V_155 >> 16 ) & 0xff ;
int V_162 = ( V_144 -> V_155 >> 24 ) & 0xff ;
int V_154 ;
unsigned short V_163 , V_150 ;
V_150 = ( V_149 -> V_9 . integer . V_9 [ 0 ] & V_10 ) ;
if ( V_162 )
V_150 = V_10 - V_150 ;
V_150 <<= V_161 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_163 = F_10 ( V_2 , V_8 ) ;
V_150 = ( V_163 & ~ ( V_10 << V_161 ) ) | V_150 ;
V_154 = V_150 != V_163 ;
F_11 ( V_2 , V_8 , V_150 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
return V_154 ;
}
static int F_86 ( struct V_143 * V_144 , struct V_145 * V_146 )
{
int V_10 = ( V_144 -> V_155 >> 16 ) & 0xff ;
V_146 -> type = V_10 == 1 ? V_156 : V_157 ;
V_146 -> V_158 = 2 ;
V_146 -> V_9 . integer . V_159 = 0 ;
V_146 -> V_9 . integer . V_160 = V_10 ;
return 0 ;
}
static int F_87 ( struct V_143 * V_144 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_81 ( V_144 ) ;
unsigned long V_28 ;
int V_8 = V_144 -> V_155 & 0xff ;
int V_164 = ( V_144 -> V_155 >> 8 ) & 0x0f ;
int V_165 = ( V_144 -> V_155 >> 12 ) & 0x0f ;
int V_10 = ( V_144 -> V_155 >> 16 ) & 0xff ;
int V_162 = ( V_144 -> V_155 >> 24 ) & 0xff ;
unsigned short V_150 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_150 = F_10 ( V_2 , V_8 ) ;
V_149 -> V_9 . integer . V_9 [ 0 ] = ( V_150 >> V_164 ) & V_10 ;
V_149 -> V_9 . integer . V_9 [ 1 ] = ( V_150 >> V_165 ) & V_10 ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
if ( V_162 ) {
V_149 -> V_9 . integer . V_9 [ 0 ] = V_10 - V_149 -> V_9 . integer . V_9 [ 0 ] ;
V_149 -> V_9 . integer . V_9 [ 1 ] = V_10 - V_149 -> V_9 . integer . V_9 [ 1 ] ;
}
return 0 ;
}
static int F_88 ( struct V_143 * V_144 , struct V_148 * V_149 )
{
struct V_1 * V_2 = F_81 ( V_144 ) ;
unsigned long V_28 ;
int V_8 = V_144 -> V_155 & 0xff ;
int V_164 = ( V_144 -> V_155 >> 8 ) & 0x0f ;
int V_165 = ( V_144 -> V_155 >> 12 ) & 0x0f ;
int V_10 = ( V_144 -> V_155 >> 16 ) & 0xff ;
int V_162 = ( V_144 -> V_155 >> 24 ) & 0xff ;
int V_154 ;
unsigned short V_163 , V_166 , V_167 ;
V_166 = V_149 -> V_9 . integer . V_9 [ 0 ] & V_10 ;
V_167 = V_149 -> V_9 . integer . V_9 [ 1 ] & V_10 ;
if ( V_162 ) {
V_166 = V_10 - V_166 ;
V_167 = V_10 - V_167 ;
}
V_166 <<= V_164 ;
V_167 <<= V_165 ;
F_15 ( & V_2 -> V_29 , V_28 ) ;
V_163 = F_10 ( V_2 , V_8 ) ;
V_166 = ( V_163 & ~ ( ( V_10 << V_164 ) | ( V_10 << V_165 ) ) ) | V_166 | V_167 ;
V_154 = V_166 != V_163 ;
F_11 ( V_2 , V_8 , V_166 ) ;
F_16 ( & V_2 -> V_29 , V_28 ) ;
return V_154 ;
}
int F_89 ( struct V_1 * V_2 )
{
struct V_116 * V_117 ;
unsigned int V_168 ;
int V_169 ;
if ( F_45 ( ! V_2 || ! V_2 -> V_117 ) )
return - V_53 ;
V_117 = V_2 -> V_117 ;
strcpy ( V_117 -> V_170 , F_64 ( V_2 ) ) ;
for ( V_168 = 0 ; V_168 < F_90 ( V_171 ) ; V_168 ++ ) {
if ( ( V_169 = F_91 ( V_117 , F_92 ( & V_171 [ V_168 ] , V_2 ) ) ) < 0 )
return V_169 ;
}
return 0 ;
}
