static const struct V_1 * F_1 ( int V_2 )
{
#define F_2 (sizeof(ar9300_eep_templates) / sizeof(ar9300_eep_templates[0]))
int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ; V_3 ++ )
if ( V_4 [ V_3 ] -> V_5 == V_2 )
return V_4 [ V_3 ] ;
return NULL ;
#undef F_2
}
static int F_3 ( struct V_6 * V_7 )
{
return 0 ;
}
static int F_4 ( int V_8 , int V_9 , int V_10 , int V_11 , int V_12 )
{
int V_13 , V_14 , V_15 ;
V_13 = 2 * ( V_12 - V_11 ) * ( V_8 - V_9 ) / ( V_10 - V_9 ) ;
V_14 = V_13 / 2 ;
V_15 = V_13 % 2 ;
return V_11 + V_14 + V_15 ;
}
static T_1 F_5 ( struct V_6 * V_7 ,
enum V_16 V_17 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_21 * V_22 = & V_18 -> V_23 ;
switch ( V_17 ) {
case V_24 :
return F_6 ( V_18 -> V_25 ) ;
case V_26 :
return F_6 ( V_18 -> V_25 + 2 ) ;
case V_27 :
return F_6 ( V_18 -> V_25 + 4 ) ;
case V_28 :
return F_7 ( V_22 -> V_29 [ 0 ] ) ;
case V_30 :
return V_22 -> V_31 ;
case V_32 :
return V_22 -> V_33 . V_34 ;
case V_35 :
return V_22 -> V_36 ;
case V_37 :
return ( V_22 -> V_38 >> 4 ) & 0xf ;
case V_39 :
return V_22 -> V_38 & 0xf ;
case V_40 :
#define F_8 0x1
return V_22 -> V_41 & F_8 ;
case V_42 :
return ( V_22 -> V_43 & 0x10 ) >> 4 ;
case V_44 :
return F_9 ( V_22 -> V_45 ) ;
case V_46 :
return ! ! ( V_22 -> V_43 & F_10 ( 5 ) ) ;
case V_47 :
return ( V_22 -> V_41 >> 0x3 ) & 0x1 ;
case V_48 :
return V_18 -> V_49 . V_50 ;
case V_51 :
return V_18 -> V_52 . V_53 ;
case V_54 :
return V_18 -> V_55 . V_53 ;
case V_56 :
return V_22 -> V_41 & F_10 ( 1 ) ;
default:
return 0 ;
}
}
static bool F_11 ( struct V_57 * V_58 , int V_59 ,
T_2 * V_60 )
{
T_3 V_61 ;
if ( F_12 ( ! F_13 ( V_58 , V_59 / 2 , & V_61 ) ) )
return false ;
* V_60 = ( V_61 >> ( 8 * ( V_59 % 2 ) ) ) & 0xff ;
return true ;
}
static bool F_14 ( struct V_57 * V_58 , int V_59 ,
T_2 * V_60 )
{
T_3 V_61 ;
if ( F_12 ( ! F_13 ( V_58 , V_59 / 2 , & V_61 ) ) )
return false ;
V_60 [ 0 ] = V_61 >> 8 ;
V_60 [ 1 ] = V_61 & 0xff ;
return true ;
}
static bool F_15 ( struct V_6 * V_7 , int V_59 , T_2 * V_60 ,
int V_62 )
{
struct V_57 * V_58 = F_16 ( V_7 ) ;
int V_63 ;
if ( ( V_59 < 0 ) || ( ( V_59 + V_62 ) / 2 > V_64 - 1 ) ) {
F_17 ( V_58 , V_65 , L_1 ) ;
return false ;
}
if ( V_59 % 2 == 0 ) {
if ( ! F_11 ( V_58 , V_59 -- , V_60 ++ ) )
goto error;
V_62 -- ;
}
for ( V_63 = 0 ; V_63 < V_62 / 2 ; V_63 ++ ) {
if ( ! F_14 ( V_58 , V_59 , V_60 ) )
goto error;
V_59 -= 2 ;
V_60 += 2 ;
}
if ( V_62 % 2 )
if ( ! F_11 ( V_58 , V_59 , V_60 ) )
goto error;
return true ;
error:
F_17 ( V_58 , V_65 , L_2 ,
V_59 ) ;
return false ;
}
static bool F_18 ( struct V_6 * V_7 , int V_66 , T_1 * V_67 )
{
F_19 ( V_7 , V_68 + ( 4 * V_66 ) ) ;
if ( ! F_20 ( V_7 , V_69 , V_70 ,
V_71 , 1000 ) )
return false ;
* V_67 = F_19 ( V_7 , V_72 ) ;
return true ;
}
static bool F_21 ( struct V_6 * V_7 , int V_59 , T_2 * V_60 ,
int V_62 )
{
T_1 V_67 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_62 ; V_63 ++ ) {
int V_73 = 8 * ( ( V_59 - V_63 ) % 4 ) ;
if ( ! F_18 ( V_7 , ( V_59 - V_63 ) / 4 , & V_67 ) )
return false ;
V_60 [ V_63 ] = ( V_67 >> V_73 ) & 0xff ;
}
return true ;
}
static void F_22 ( T_2 * V_74 , int * V_75 , int * V_76 ,
int * V_77 , int * V_78 , int * V_79 )
{
unsigned long V_80 [ 4 ] ;
V_80 [ 0 ] = V_74 [ 0 ] ;
V_80 [ 1 ] = V_74 [ 1 ] ;
V_80 [ 2 ] = V_74 [ 2 ] ;
V_80 [ 3 ] = V_74 [ 3 ] ;
* V_75 = ( ( V_80 [ 0 ] >> 5 ) & 0x0007 ) ;
* V_76 = ( V_80 [ 0 ] & 0x001f ) | ( ( V_80 [ 1 ] >> 2 ) & 0x0020 ) ;
* V_77 = ( ( V_80 [ 1 ] << 4 ) & 0x07f0 ) | ( ( V_80 [ 2 ] >> 4 ) & 0x000f ) ;
* V_78 = ( V_80 [ 2 ] & 0x000f ) ;
* V_79 = ( V_80 [ 3 ] & 0x00ff ) ;
}
static T_3 F_23 ( T_2 * V_67 , int V_81 )
{
int V_3 , V_82 = 0 ;
for ( V_3 = 0 ; V_3 < V_81 ; V_3 ++ ) {
V_82 += V_67 [ V_3 ] ;
V_82 &= 0xffff ;
}
return V_82 ;
}
static bool F_24 ( struct V_6 * V_7 ,
T_2 * V_83 ,
int V_84 ,
T_2 * V_85 ,
int V_86 )
{
int V_3 ;
int V_87 ;
int V_73 ;
int V_77 ;
struct V_57 * V_58 = F_16 ( V_7 ) ;
V_87 = 0 ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 += ( V_77 + 2 ) ) {
V_73 = V_85 [ V_3 ] ;
V_73 &= 0xff ;
V_87 += V_73 ;
V_77 = V_85 [ V_3 + 1 ] ;
V_77 &= 0xff ;
if ( V_77 > 0 && V_87 >= 0 && V_87 + V_77 <= V_84 ) {
F_17 ( V_58 , V_65 ,
L_3 ,
V_3 , V_87 , V_73 , V_77 ) ;
memcpy ( & V_83 [ V_87 ] , & V_85 [ V_3 + 2 ] , V_77 ) ;
V_87 += V_77 ;
} else if ( V_77 > 0 ) {
F_17 ( V_58 , V_65 ,
L_4 ,
V_3 , V_87 , V_73 , V_77 ) ;
return false ;
}
}
return true ;
}
static int F_25 ( struct V_6 * V_7 ,
int V_3 ,
int V_75 ,
int V_76 ,
T_2 * V_83 ,
T_2 * V_88 , int V_77 , int V_89 )
{
struct V_57 * V_58 = F_16 ( V_7 ) ;
const struct V_1 * V_18 = NULL ;
switch ( V_75 ) {
case V_90 :
if ( V_77 != V_89 ) {
F_17 ( V_58 , V_65 ,
L_5 ,
V_89 , V_77 ) ;
return - 1 ;
}
memcpy ( V_83 , ( T_2 * ) ( V_88 + V_91 ) , V_77 ) ;
F_17 ( V_58 , V_65 ,
L_6 ,
V_3 , V_77 ) ;
break;
case V_92 :
if ( V_76 == 0 ) {
} else {
V_18 = F_1 ( V_76 ) ;
if ( V_18 == NULL ) {
F_17 ( V_58 , V_65 ,
L_7 ,
V_76 ) ;
return - 1 ;
}
memcpy ( V_83 , V_18 , V_89 ) ;
}
F_17 ( V_58 , V_65 ,
L_8 ,
V_3 , V_76 , V_77 ) ;
F_24 ( V_7 , V_83 , V_89 ,
( T_2 * ) ( V_88 + V_91 ) , V_77 ) ;
break;
default:
F_17 ( V_58 , V_65 , L_9 , V_75 ) ;
return - 1 ;
}
return 0 ;
}
static bool F_26 ( void * V_67 )
{
T_1 * V_88 = V_67 ;
return ! ( * V_88 == 0 || * V_88 == ~ 0 ) ;
}
static bool F_27 ( struct V_6 * V_7 , T_4 V_93 ,
int V_94 )
{
T_2 V_95 [ 4 ] ;
if ( ! V_93 ( V_7 , V_94 , V_95 , 4 ) )
return false ;
return F_26 ( V_95 ) ;
}
static int F_28 ( struct V_6 * V_7 , T_2 * V_83 ,
int V_89 )
{
struct V_57 * V_58 = F_16 ( V_7 ) ;
T_3 * V_67 = ( T_3 * ) V_83 ;
int V_63 ;
for ( V_63 = 0 ; V_63 < V_89 / 2 ; V_63 ++ , V_67 ++ )
F_13 ( V_58 , V_63 , V_67 ) ;
return 0 ;
}
static int F_29 ( struct V_6 * V_7 ,
T_2 * V_83 , int V_89 )
{
#define F_30 15
#define F_31 100
int V_96 ;
T_2 * V_88 ;
int V_75 ;
int V_76 , V_77 , V_78 , V_79 ;
int V_97 ;
int V_3 ;
T_3 V_82 , V_98 ;
struct V_57 * V_58 = F_16 ( V_7 ) ;
T_4 V_93 ;
if ( F_32 ( V_7 ) )
return F_28 ( V_7 , V_83 , V_89 ) ;
V_88 = F_33 ( 2048 , V_99 ) ;
if ( ! V_88 )
return - V_100 ;
memcpy ( V_83 , & V_101 , V_89 ) ;
V_93 = F_15 ;
if ( F_34 ( V_7 ) )
V_96 = V_102 ;
else if ( F_35 ( V_7 ) )
V_96 = V_103 ;
else
V_96 = V_104 ;
F_17 ( V_58 , V_65 , L_10 ,
V_96 ) ;
if ( F_27 ( V_7 , V_93 , V_96 ) )
goto V_105;
V_96 = V_103 ;
F_17 ( V_58 , V_65 , L_10 ,
V_96 ) ;
if ( F_27 ( V_7 , V_93 , V_96 ) )
goto V_105;
V_93 = F_21 ;
V_96 = V_104 ;
F_17 ( V_58 , V_65 , L_11 , V_96 ) ;
if ( F_27 ( V_7 , V_93 , V_96 ) )
goto V_105;
V_96 = V_103 ;
F_17 ( V_58 , V_65 , L_11 , V_96 ) ;
if ( F_27 ( V_7 , V_93 , V_96 ) )
goto V_105;
goto V_106;
V_105:
F_17 ( V_58 , V_65 , L_12 ) ;
for ( V_3 = 0 ; V_3 < F_31 ; V_3 ++ ) {
if ( ! V_93 ( V_7 , V_96 , V_88 , V_91 ) )
goto V_106;
if ( ! F_26 ( V_88 ) )
break;
F_22 ( V_88 , & V_75 , & V_76 ,
& V_77 , & V_78 , & V_79 ) ;
F_17 ( V_58 , V_65 ,
L_13 ,
V_96 , V_75 , V_76 , V_77 , V_78 , V_79 ) ;
if ( ( ! F_34 ( V_7 ) && V_77 >= 1024 ) ||
( F_34 ( V_7 ) && V_77 > V_107 ) ) {
F_17 ( V_58 , V_65 , L_14 ) ;
V_96 -= V_91 ;
continue;
}
V_97 = V_77 ;
V_93 ( V_7 , V_96 , V_88 , V_91 + V_97 + V_108 ) ;
V_82 = F_23 ( & V_88 [ V_91 ] , V_77 ) ;
V_98 = F_36 ( & V_88 [ V_91 + V_97 ] ) ;
F_17 ( V_58 , V_65 , L_15 ,
V_82 , V_98 ) ;
if ( V_82 == V_98 ) {
F_25 ( V_7 , V_3 , V_75 , V_76 , V_83 ,
V_88 , V_77 , V_89 ) ;
} else {
F_17 ( V_58 , V_65 ,
L_16 ) ;
}
V_96 -= ( V_91 + V_97 + V_108 ) ;
}
F_37 ( V_88 ) ;
return V_96 ;
V_106:
F_37 ( V_88 ) ;
return - 1 ;
}
static bool F_38 ( struct V_6 * V_7 )
{
T_2 * V_83 = ( T_2 * ) & V_7 -> V_19 . V_20 ;
if ( F_29 ( V_7 , V_83 ,
sizeof( struct V_1 ) ) < 0 )
return false ;
return true ;
}
static T_1 F_39 ( char * V_109 , T_1 V_110 , T_1 V_86 ,
struct V_111 * V_112 )
{
F_40 ( L_17 , F_7 ( V_112 -> V_113 [ 0 ] ) ) ;
F_40 ( L_18 , F_7 ( V_112 -> V_113 [ 1 ] ) ) ;
F_40 ( L_19 , F_7 ( V_112 -> V_113 [ 2 ] ) ) ;
F_40 ( L_20 , F_9 ( V_112 -> V_114 ) ) ;
F_40 ( L_21 , F_9 ( V_112 -> V_115 ) ) ;
F_40 ( L_22 , V_112 -> V_53 ) ;
F_40 ( L_23 , V_112 -> V_116 ) ;
F_40 ( L_24 , V_112 -> V_117 [ 0 ] ) ;
F_40 ( L_25 , V_112 -> V_117 [ 1 ] ) ;
F_40 ( L_26 , V_112 -> V_117 [ 2 ] ) ;
F_40 ( L_27 , V_112 -> V_118 [ 0 ] ) ;
F_40 ( L_28 , V_112 -> V_118 [ 1 ] ) ;
F_40 ( L_29 , V_112 -> V_118 [ 2 ] ) ;
F_40 ( L_30 , V_112 -> V_119 ) ;
F_40 ( L_31 , V_112 -> V_120 ) ;
F_40 ( L_32 , V_112 -> V_121 [ 0 ] ) ;
F_40 ( L_33 , V_112 -> V_121 [ 1 ] ) ;
F_40 ( L_34 , V_112 -> V_121 [ 2 ] ) ;
F_40 ( L_35 , V_112 -> V_121 [ 3 ] ) ;
F_40 ( L_36 , V_112 -> V_121 [ 4 ] ) ;
F_40 ( L_37 , V_112 -> V_122 [ 0 ] ) ;
F_40 ( L_38 , V_112 -> V_122 [ 1 ] ) ;
F_40 ( L_39 , V_112 -> V_122 [ 2 ] ) ;
F_40 ( L_40 , V_112 -> V_123 ) ;
F_40 ( L_41 , V_112 -> V_124 ) ;
F_40 ( L_42 , V_112 -> V_125 ) ;
F_40 ( L_43 , V_112 -> V_126 ) ;
F_40 ( L_44 , V_112 -> V_127 ) ;
F_40 ( L_45 , V_112 -> V_128 ) ;
F_40 ( L_46 , V_112 -> V_129 ) ;
F_40 ( L_47 , V_112 -> V_130 ) ;
return V_110 ;
}
static T_1 F_41 ( struct V_6 * V_7 , bool V_131 ,
T_2 * V_109 , T_1 V_110 , T_1 V_86 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_21 * V_22 ;
if ( ! V_131 ) {
V_110 += snprintf ( V_109 + V_110 , V_86 - V_110 ,
L_48 , L_49 ) ;
V_110 += F_39 ( V_109 , V_110 , V_86 ,
& V_18 -> V_55 ) ;
V_110 += snprintf ( V_109 + V_110 , V_86 - V_110 ,
L_48 , L_50 ) ;
V_110 += F_39 ( V_109 , V_110 , V_86 ,
& V_18 -> V_52 ) ;
goto V_132;
}
V_22 = & V_18 -> V_23 ;
F_40 ( L_51 , V_7 -> V_19 . V_20 . V_133 ) ;
F_40 ( L_52 , F_7 ( V_22 -> V_29 [ 0 ] ) ) ;
F_40 ( L_53 , F_7 ( V_22 -> V_29 [ 1 ] ) ) ;
F_40 ( L_54 , ( V_22 -> V_38 >> 4 ) ) ;
F_40 ( L_55 , ( V_22 -> V_38 & 0x0f ) ) ;
F_40 ( L_56 , ! ! ( V_22 -> V_33 . V_34 &
V_134 ) ) ;
F_40 ( L_57 , ! ! ( V_22 -> V_33 . V_34 &
V_135 ) ) ;
F_40 ( L_58 , ! ! ( V_22 -> V_33 . V_34 &
V_136 ) ) ;
F_40 ( L_59 , ! ! ( V_22 -> V_33 . V_34 &
V_137 ) ) ;
F_40 ( L_60 , ! ! ( V_22 -> V_33 . V_34 &
V_138 ) ) ;
F_40 ( L_61 , ! ! ( V_22 -> V_33 . V_34 &
V_139 ) ) ;
F_40 ( L_62 , ! ! ( V_22 -> V_33 . V_140 & 0x01 ) ) ;
F_40 ( L_63 , V_22 -> V_36 ) ;
F_40 ( L_64 , V_22 -> V_141 ) ;
F_40 ( L_65 , V_22 -> V_31 ) ;
F_40 ( L_66 , V_22 -> V_142 ) ;
F_40 ( L_67 , V_22 -> V_143 ) ;
F_40 ( L_68 , V_22 -> V_144 [ 0 ] ) ;
F_40 ( L_69 , V_22 -> V_144 [ 1 ] ) ;
F_40 ( L_70 , ! ! ( V_22 -> V_43 & F_10 ( 0 ) ) ) ;
F_40 ( L_71 , ! ! ( V_22 -> V_43 & F_10 ( 1 ) ) ) ;
F_40 ( L_72 , ! ! ( V_22 -> V_43 & F_10 ( 2 ) ) ) ;
F_40 ( L_73 , ! ! ( V_22 -> V_43 & F_10 ( 3 ) ) ) ;
F_40 ( L_74 , ! ! ( V_22 -> V_43 & F_10 ( 4 ) ) ) ;
F_40 ( L_75 , ! ! ( V_22 -> V_43 & F_10 ( 5 ) ) ) ;
F_40 ( L_76 , ! ! ( V_22 -> V_41 & F_10 ( 0 ) ) ) ;
F_40 ( L_40 , ! ! ( V_22 -> V_41 & F_10 ( 1 ) ) ) ;
F_40 ( L_77 , ( V_22 -> V_41 >> 0x3 ) & 0x1 ) ;
F_40 ( L_78 , V_22 -> V_145 ) ;
F_40 ( L_79 , V_22 -> V_146 ) ;
F_40 ( L_80 , V_22 -> V_147 ) ;
F_40 ( L_81 , V_22 -> V_148 ) ;
F_40 ( L_82 , V_22 -> V_149 >> 4 ) ;
F_40 ( L_83 , V_22 -> V_149 & 0xf ) ;
F_40 ( L_84 , F_9 ( V_22 -> V_45 ) ) ;
V_110 += snprintf ( V_109 + V_110 , V_86 - V_110 , L_85 , L_86 ,
V_7 -> V_19 . V_20 . V_25 ) ;
V_132:
if ( V_110 > V_86 )
V_110 = V_86 ;
return V_110 ;
}
static T_1 F_41 ( struct V_6 * V_7 , bool V_131 ,
T_2 * V_109 , T_1 V_110 , T_1 V_86 )
{
return 0 ;
}
static int F_42 ( struct V_6 * V_7 )
{
return V_7 -> V_19 . V_20 . V_133 ;
}
static int F_43 ( struct V_6 * V_7 )
{
return 0 ;
}
static T_5 F_44 ( struct V_6 * V_7 , bool V_150 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
if ( V_150 )
return V_18 -> V_55 . V_125 ;
else
return V_18 -> V_52 . V_125 ;
}
static void F_45 ( struct V_6 * V_7 , bool V_150 )
{
int V_151 = F_44 ( V_7 , V_150 ) ;
if ( F_34 ( V_7 ) || F_35 ( V_7 ) || F_46 ( V_7 ) )
F_47 ( V_7 , V_152 , V_153 , V_151 ) ;
else if ( F_48 ( V_7 ) )
F_47 ( V_7 , V_154 , V_155 , V_151 ) ;
else {
F_47 ( V_7 , V_154 , V_155 , V_151 ) ;
F_47 ( V_7 , V_156 ,
V_157 ,
V_151 >> 2 ) ;
F_47 ( V_7 , V_156 ,
V_158 , 1 ) ;
}
}
static T_3 F_49 ( struct V_6 * V_7 , bool V_159 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
T_6 V_61 ;
if ( V_159 )
V_61 = V_18 -> V_55 . V_160 ;
else
V_61 = V_18 -> V_52 . V_160 ;
return F_7 ( V_61 ) ;
}
static T_1 F_50 ( struct V_6 * V_7 , bool V_150 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
T_7 V_61 ;
if ( V_150 )
V_61 = V_18 -> V_55 . V_114 ;
else
V_61 = V_18 -> V_52 . V_114 ;
return F_9 ( V_61 ) ;
}
static T_1 F_51 ( struct V_6 * V_7 , bool V_150 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
T_7 V_61 ;
if ( V_150 )
V_61 = V_18 -> V_55 . V_115 ;
else
V_61 = V_18 -> V_52 . V_115 ;
return F_9 ( V_61 ) ;
}
static T_3 F_52 ( struct V_6 * V_7 ,
int V_161 ,
bool V_150 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
T_6 V_61 = 0 ;
if ( V_161 >= 0 && V_161 < V_162 ) {
if ( V_150 )
V_61 = V_18 -> V_55 . V_113 [ V_161 ] ;
else
V_61 = V_18 -> V_52 . V_113 [ V_161 ] ;
}
return F_7 ( V_61 ) ;
}
static void F_53 ( struct V_6 * V_7 , bool V_150 )
{
int V_161 ;
T_1 V_163 ;
T_1 V_164 ;
static const T_1 V_165 [ V_162 ] = {
V_166 ,
V_167 ,
V_168 ,
} ;
T_1 V_80 = F_50 ( V_7 , V_150 ) ;
if ( F_48 ( V_7 ) ) {
F_47 ( V_7 , V_169 ,
V_170 , V_80 ) ;
} else
F_47 ( V_7 , V_169 ,
V_171 , V_80 ) ;
if ( F_54 ( V_7 ) ) {
V_80 = F_49 ( V_7 , V_150 ) ;
F_47 ( V_7 , V_172 ,
V_173 , V_80 ) ;
}
V_80 = F_51 ( V_7 , V_150 ) ;
F_47 ( V_7 , V_174 , V_175 , V_80 ) ;
for ( V_161 = 0 ; V_161 < V_162 ; V_161 ++ ) {
if ( ( V_7 -> V_176 & F_10 ( V_161 ) ) ||
( V_7 -> V_177 & F_10 ( V_161 ) ) ) {
V_80 = F_52 ( V_7 , V_161 ,
V_150 ) ;
F_47 ( V_7 , V_165 [ V_161 ] ,
V_178 , V_80 ) ;
}
}
if ( F_35 ( V_7 ) || F_34 ( V_7 ) ) {
V_80 = F_5 ( V_7 , V_48 ) ;
V_163 = F_19 ( V_7 , V_179 ) ;
V_163 &= ( ~ V_180 ) ;
V_163 |= ( V_80 & 0x3f ) << V_181 ;
V_163 &= ( ~ V_182 ) ;
V_163 |= ( ( V_80 >> 6 ) & 0x1 ) <<
V_183 ;
F_55 ( V_7 , V_179 , V_163 ) ;
V_163 = F_19 ( V_7 , V_184 ) ;
V_163 &= ( ~ V_185 ) ;
V_163 |= ( ( V_80 >> 7 ) & 0x1 ) <<
V_186 ;
F_55 ( V_7 , V_184 , V_163 ) ;
V_164 =
V_7 -> V_187 -> V_188 ( V_7 , V_48 ) ;
if ( ( V_164 >> 0x6 ) == 0x3 ) {
V_163 = F_19 ( V_7 , V_179 ) ;
V_163 &= ( ~ ( V_189 |
V_190 |
V_191 |
V_192 ) ) ;
V_163 |= ( V_193 <<
V_194 ) ;
V_163 |= ( V_195 <<
V_196 ) ;
F_55 ( V_7 , V_179 , V_163 ) ;
}
}
}
static void F_56 ( struct V_6 * V_7 )
{
int V_197 ;
unsigned long V_198 ;
V_197 = F_5 ( V_7 , V_40 ) ;
if ( ! V_197 )
return;
V_198 = F_19 ( V_7 , V_199 ) ;
V_198 &= ~ 0x00ffffc0 ;
V_198 |= 0x5 << 21 ;
V_198 |= 0x5 << 18 ;
V_198 |= 0x5 << 15 ;
V_198 |= 0x5 << 12 ;
V_198 |= 0x5 << 9 ;
V_198 |= 0x5 << 6 ;
F_55 ( V_7 , V_199 , V_198 ) ;
V_198 = F_19 ( V_7 , V_200 ) ;
V_198 &= ~ 0xffffffe0 ;
V_198 |= 0x5 << 29 ;
V_198 |= 0x5 << 26 ;
V_198 |= 0x5 << 23 ;
V_198 |= 0x5 << 20 ;
V_198 |= 0x5 << 17 ;
V_198 |= 0x5 << 14 ;
V_198 |= 0x5 << 11 ;
V_198 |= 0x5 << 8 ;
V_198 |= 0x5 << 5 ;
F_55 ( V_7 , V_200 , V_198 ) ;
V_198 = F_19 ( V_7 , V_201 ) ;
V_198 &= ~ 0xff800000 ;
V_198 |= 0x5 << 29 ;
V_198 |= 0x5 << 26 ;
V_198 |= 0x5 << 23 ;
F_55 ( V_7 , V_201 , V_198 ) ;
}
static T_3 F_57 ( struct V_6 * V_7 , int V_161 ,
struct V_202 * V_203 )
{
int V_204 [ 3 ] , V_205 [ 3 ] ;
T_3 V_80 ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
if ( V_161 >= 0 && V_161 < 3 ) {
if ( F_58 ( V_203 ) )
return V_18 -> V_55 . V_117 [ V_161 ] ;
else if ( V_18 -> V_206 . V_207 [ V_161 ] != 0 ) {
V_205 [ 0 ] = V_18 -> V_206 . V_207 [ V_161 ] ;
V_204 [ 0 ] = 5180 ;
V_205 [ 1 ] = V_18 -> V_52 . V_117 [ V_161 ] ;
V_204 [ 1 ] = 5500 ;
V_205 [ 2 ] = V_18 -> V_206 . V_208 [ V_161 ] ;
V_204 [ 2 ] = 5785 ;
V_80 = F_59 ( ( T_5 ) V_203 -> V_209 ,
V_204 , V_205 , 3 ) ;
return V_80 ;
} else
return V_18 -> V_52 . V_117 [ V_161 ] ;
}
return 0 ;
}
static T_3 F_60 ( struct V_6 * V_7 , int V_161 ,
struct V_202 * V_203 )
{
int V_204 [ 3 ] , V_205 [ 3 ] ;
T_3 V_80 ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
if ( V_161 >= 0 && V_161 < 3 ) {
if ( F_58 ( V_203 ) )
return V_18 -> V_55 . V_118 [ V_161 ] ;
else if ( V_18 -> V_206 . V_210 [ V_161 ] != 0 ) {
V_205 [ 0 ] = V_18 -> V_206 . V_210 [ V_161 ] ;
V_204 [ 0 ] = 5180 ;
V_205 [ 1 ] = V_18 -> V_52 . V_118 [ V_161 ] ;
V_204 [ 1 ] = 5500 ;
V_205 [ 2 ] = V_18 -> V_206 . V_211 [ V_161 ] ;
V_204 [ 2 ] = 5785 ;
V_80 = F_59 ( ( T_5 ) V_203 -> V_209 ,
V_204 , V_205 , 3 ) ;
return V_80 ;
} else
return V_18 -> V_52 . V_118 [ V_161 ] ;
}
return 0 ;
}
static void F_61 ( struct V_6 * V_7 , struct V_202 * V_203 )
{
int V_63 ;
T_3 V_80 ;
unsigned long V_212 [ 3 ] = { V_213 ,
V_214 ,
V_215 ,
} ;
for ( V_63 = 0 ; V_63 < 3 ; V_63 ++ ) {
if ( V_7 -> V_177 & F_10 ( V_63 ) ) {
V_80 = F_57 ( V_7 , V_63 , V_203 ) ;
F_47 ( V_7 , V_212 [ V_63 ] ,
V_216 , V_80 ) ;
V_80 = F_60 ( V_7 , V_63 , V_203 ) ;
F_47 ( V_7 , V_212 [ V_63 ] ,
V_217 ,
V_80 ) ;
}
}
}
static bool F_62 ( struct V_6 * V_7 , T_1 V_218 , int V_219 )
{
int V_220 = 100 ;
while ( V_219 != F_19 ( V_7 , V_218 ) ) {
if ( V_220 -- == 0 )
return false ;
F_55 ( V_7 , V_218 , V_219 ) ;
F_63 ( 10 ) ;
}
return true ;
}
void F_64 ( struct V_6 * V_7 )
{
int V_221 =
F_5 ( V_7 , V_42 ) ;
T_1 V_222 ;
if ( V_221 ) {
if ( F_35 ( V_7 ) || F_34 ( V_7 ) ) {
int V_223 ;
V_223 = F_19 ( V_7 , V_224 ) & ~ V_225 ;
F_55 ( V_7 , V_224 , V_223 ) ;
if ( ! F_62 ( V_7 , V_224 , V_223 ) )
return;
if ( F_35 ( V_7 ) ) {
if ( V_7 -> V_226 ) {
V_223 = ( 3 << 1 ) | ( 8 << 4 ) |
( 3 << 8 ) | ( 1 << 14 ) |
( 6 << 17 ) | ( 1 << 20 ) |
( 3 << 24 ) ;
} else {
V_223 = ( 4 << 1 ) | ( 7 << 4 ) |
( 3 << 8 ) | ( 1 << 14 ) |
( 6 << 17 ) | ( 1 << 20 ) |
( 3 << 24 ) ;
}
} else {
V_223 = ( 5 << 1 ) | ( 7 << 4 ) |
( 2 << 8 ) | ( 2 << 14 ) |
( 6 << 17 ) | ( 1 << 20 ) |
( 3 << 24 ) | ( 1 << 28 ) ;
}
F_55 ( V_7 , V_227 , V_223 ) ;
if ( ! F_62 ( V_7 , V_227 , V_223 ) )
return;
V_223 = ( F_19 ( V_7 , V_224 ) & ~ 0xFFC00000 )
| ( 4 << 26 ) ;
F_55 ( V_7 , V_224 , V_223 ) ;
if ( ! F_62 ( V_7 , V_224 , V_223 ) )
return;
V_223 = ( F_19 ( V_7 , V_224 ) & ~ 0x00200000 )
| ( 1 << 21 ) ;
F_55 ( V_7 , V_224 , V_223 ) ;
if ( ! F_62 ( V_7 , V_224 , V_223 ) )
return;
} else if ( F_48 ( V_7 ) ) {
V_222 = F_5 ( V_7 , V_44 ) ;
F_55 ( V_7 , V_227 , V_222 ) ;
} else {
V_222 = F_5 ( V_7 , V_44 ) ;
F_55 ( V_7 , V_228 ,
F_19 ( V_7 , V_228 ) &
( ~ V_229 ) ) ;
F_55 ( V_7 , V_230 , V_222 ) ;
F_55 ( V_7 , V_228 ,
F_19 ( V_7 ,
V_228 ) |
V_229 ) ;
}
} else {
if ( F_35 ( V_7 ) || F_34 ( V_7 ) ) {
F_47 ( V_7 , V_224 , V_225 , 0 ) ;
while ( F_65 ( V_7 , V_224 ,
V_225 ) )
F_63 ( 10 ) ;
F_47 ( V_7 , V_227 , V_231 , 0x1 ) ;
while ( ! F_65 ( V_7 , V_227 ,
V_231 ) )
F_63 ( 10 ) ;
F_47 ( V_7 , V_224 , V_225 , 0x1 ) ;
while ( ! F_65 ( V_7 , V_224 ,
V_225 ) )
F_63 ( 10 ) ;
} else if ( F_48 ( V_7 ) )
F_47 ( V_7 , V_227 , V_231 , 0x1 ) ;
else {
V_222 = F_19 ( V_7 , V_232 ) |
V_233 ;
F_55 ( V_7 , V_232 , V_222 ) ;
}
}
}
static void F_66 ( struct V_6 * V_7 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
T_2 V_234 = V_18 -> V_23 . V_144 [ 0 ] ;
if ( V_18 -> V_23 . V_43 & 0x40 ) {
V_234 &= 0x7f ;
F_47 ( V_7 , V_235 , V_236 ,
V_234 ) ;
F_47 ( V_7 , V_235 , V_237 ,
V_234 ) ;
}
}
static void F_67 ( struct V_6 * V_7 , T_3 V_238 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
int V_123 = F_5 ( V_7 , V_56 ) ;
T_5 V_205 [ 3 ] , V_204 [ 3 ] = { 5180 , 5500 , 5785 } ;
if ( ! V_123 )
return;
if ( V_238 < 4000 )
V_123 = V_18 -> V_55 . V_123 ;
else {
V_205 [ 0 ] = V_18 -> V_49 . V_239 ;
V_205 [ 1 ] = V_18 -> V_52 . V_123 ;
V_205 [ 2 ] = V_18 -> V_49 . V_240 ;
V_123 = F_59 ( V_238 , V_204 , V_205 , 3 ) ;
}
F_47 ( V_7 , V_241 , V_242 , V_123 ) ;
}
static void F_68 ( struct V_6 * V_7 , T_3 V_238 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
T_1 V_80 ;
V_80 = ( V_238 < 4000 ) ? V_18 -> V_55 . V_124 :
V_18 -> V_52 . V_124 ;
F_47 ( V_7 , V_243 ,
V_244 , V_80 ) ;
F_47 ( V_7 , V_243 ,
V_245 , V_80 ) ;
}
static void F_69 ( struct V_6 * V_7 ,
struct V_202 * V_203 )
{
F_45 ( V_7 , F_58 ( V_203 ) ) ;
F_53 ( V_7 , F_58 ( V_203 ) ) ;
F_56 ( V_7 ) ;
F_61 ( V_7 , V_203 ) ;
F_67 ( V_7 , V_203 -> V_209 ) ;
if ( ! F_35 ( V_7 ) && ! F_46 ( V_7 ) )
F_64 ( V_7 ) ;
if ( F_34 ( V_7 ) || F_35 ( V_7 ) || F_46 ( V_7 ) )
F_66 ( V_7 ) ;
F_68 ( V_7 , V_203 -> V_209 ) ;
}
static void F_70 ( struct V_6 * V_7 ,
struct V_202 * V_203 )
{
}
static int F_59 ( T_8 V_8 ,
T_8 * V_246 , T_8 * V_247 , T_9 V_248 )
{
int V_249 = 0 ;
int V_250 = 0 , V_251 = 0 , V_252 = 0 ;
int V_253 = 0 , V_254 = 0 , V_255 = 0 ;
int V_256 = 0 ;
int V_257 = 0 ;
V_252 = 0 ;
V_255 = 0 ;
for ( V_249 = 0 ; V_249 < V_248 ; V_249 ++ ) {
V_256 = V_8 - V_246 [ V_249 ] ;
if ( V_256 <= 0 ) {
if ( ! V_255 || V_256 > ( V_8 - V_253 ) ) {
V_253 = V_246 [ V_249 ] ;
V_254 = V_247 [ V_249 ] ;
V_255 = 1 ;
}
}
if ( V_256 >= 0 ) {
if ( ! V_252 || V_256 < ( V_8 - V_250 ) ) {
V_250 = V_246 [ V_249 ] ;
V_251 = V_247 [ V_249 ] ;
V_252 = 1 ;
}
}
}
if ( V_252 ) {
if ( V_255 ) {
if ( V_253 == V_250 )
V_257 = V_251 ;
else
V_257 = F_4 ( V_8 , V_250 , V_253 , V_251 , V_254 ) ;
} else
V_257 = V_251 ;
} else if ( V_255 )
V_257 = V_254 ;
else
V_257 = - ( 1 << 30 ) ;
return V_257 ;
}
static T_2 F_71 ( struct V_6 * V_7 ,
T_3 V_258 , T_3 V_238 , bool V_259 )
{
T_3 V_260 , V_63 ;
T_5 V_261 [ V_262 ] ;
T_5 V_263 [ V_262 ] ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_264 * V_265 ;
T_2 * V_266 ;
if ( V_259 ) {
V_260 = V_267 ;
V_265 = V_18 -> V_268 ;
V_266 = V_18 -> V_269 ;
} else {
V_260 = V_262 ;
V_265 = V_18 -> V_270 ;
V_266 = V_18 -> V_271 ;
}
for ( V_63 = 0 ; V_63 < V_260 ; V_63 ++ ) {
V_263 [ V_63 ] = F_72 ( V_266 [ V_63 ] , V_259 ) ;
V_261 [ V_63 ] = V_265 [ V_63 ] . V_272 [ V_258 ] ;
}
return ( T_2 ) F_59 ( ( T_5 ) V_238 ,
V_263 ,
V_261 , V_260 ) ;
}
static T_2 F_73 ( struct V_6 * V_7 ,
T_3 V_258 ,
T_3 V_238 , bool V_259 )
{
T_3 V_260 , V_63 ;
T_5 V_261 [ V_262 ] ;
T_5 V_263 [ V_262 ] ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_273 * V_265 ;
T_2 * V_266 ;
if ( V_259 ) {
V_260 = V_267 ;
V_265 = V_18 -> V_274 ;
V_266 = V_18 -> V_275 ;
} else {
V_260 = V_262 ;
V_265 = V_18 -> V_276 ;
V_266 = V_18 -> V_277 ;
}
for ( V_63 = 0 ; V_63 < V_260 ; V_63 ++ ) {
V_263 [ V_63 ] = F_72 ( V_266 [ V_63 ] , V_259 ) ;
V_261 [ V_63 ] = V_265 [ V_63 ] . V_272 [ V_258 ] ;
}
return ( T_2 ) F_59 ( ( T_5 ) V_238 ,
V_263 ,
V_261 , V_260 ) ;
}
static T_2 F_74 ( struct V_6 * V_7 ,
T_3 V_258 ,
T_3 V_238 , bool V_259 )
{
T_3 V_260 , V_63 ;
T_5 V_261 [ V_278 ] ;
T_5 V_263 [ V_278 ] ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_273 * V_265 ;
T_2 * V_266 ;
if ( V_259 ) {
V_260 = V_279 ;
V_265 = V_18 -> V_280 ;
V_266 = V_18 -> V_281 ;
} else {
V_260 = V_278 ;
V_265 = V_18 -> V_282 ;
V_266 = V_18 -> V_283 ;
}
for ( V_63 = 0 ; V_63 < V_260 ; V_63 ++ ) {
V_263 [ V_63 ] = F_72 ( V_266 [ V_63 ] , V_259 ) ;
V_261 [ V_63 ] = V_265 [ V_63 ] . V_272 [ V_258 ] ;
}
return ( T_2 ) F_59 ( ( T_5 ) V_238 ,
V_263 ,
V_261 , V_260 ) ;
}
static T_2 F_75 ( struct V_6 * V_7 ,
T_3 V_258 , T_3 V_238 )
{
T_3 V_260 = V_284 , V_63 ;
T_5 V_261 [ V_284 ] ;
T_5 V_263 [ V_284 ] ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_264 * V_265 = V_18 -> V_285 ;
T_2 * V_266 = V_18 -> V_286 ;
for ( V_63 = 0 ; V_63 < V_260 ; V_63 ++ ) {
V_263 [ V_63 ] = F_72 ( V_266 [ V_63 ] , 1 ) ;
V_261 [ V_63 ] = V_265 [ V_63 ] . V_272 [ V_258 ] ;
}
return ( T_2 ) F_59 ( ( T_5 ) V_238 ,
V_263 ,
V_261 , V_260 ) ;
}
static int F_76 ( struct V_6 * V_7 , T_2 * V_287 )
{
#define F_77 ( T_10 , T_11 ) (((_r) & 0x3f) << (_s))
F_55 ( V_7 , V_288 , 0 ) ;
F_55 ( V_7 , F_78 ( 0 ) ,
F_77 ( V_287 [ V_289 ] , 24 ) |
F_77 ( V_287 [ V_289 ] , 16 ) |
F_77 ( V_287 [ V_289 ] , 8 ) |
F_77 ( V_287 [ V_289 ] , 0 ) ) ;
F_55 ( V_7 , F_78 ( 1 ) ,
F_77 ( V_287 [ V_290 ] , 24 ) |
F_77 ( V_287 [ V_291 ] , 16 ) |
F_77 ( V_287 [ V_292 ] , 8 ) |
F_77 ( V_287 [ V_289 ] , 0 ) ) ;
F_55 ( V_7 , F_78 ( 2 ) ,
F_77 ( V_287 [ V_293 ] , 24 ) |
F_77 ( V_287 [ V_293 ] , 16 ) |
F_77 ( V_287 [ V_293 ] , 0 ) ) ;
F_55 ( V_7 , F_78 ( 3 ) ,
F_77 ( V_287 [ V_294 ] , 24 ) |
F_77 ( V_287 [ V_295 ] , 16 ) |
F_77 ( V_287 [ V_296 ] , 8 ) |
F_77 ( V_287 [ V_293 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 8 ) ,
F_77 ( V_287 [ V_289 ] , 24 ) |
F_77 ( V_287 [ V_293 ] , 16 ) |
F_77 ( V_287 [ V_289 ] , 8 ) |
F_77 ( V_287 [ V_293 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 4 ) ,
F_77 ( V_287 [ V_297 ] , 24 ) |
F_77 ( V_287 [ V_298 ] , 16 ) |
F_77 ( V_287 [ V_299 ] , 8 ) |
F_77 ( V_287 [ V_300 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 5 ) ,
F_77 ( V_287 [ V_301 ] , 24 ) |
F_77 ( V_287 [ V_302 ] , 16 ) |
F_77 ( V_287 [ V_303 ] , 8 ) |
F_77 ( V_287 [ V_304 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 9 ) ,
F_77 ( V_287 [ V_305 ] , 24 ) |
F_77 ( V_287 [ V_306 ] , 16 ) |
F_77 ( V_287 [ V_307 ] , 8 ) |
F_77 ( V_287 [ V_308 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 10 ) ,
F_77 ( V_287 [ V_309 ] , 24 ) |
F_77 ( V_287 [ V_310 ] , 16 ) |
F_77 ( V_287 [ V_311 ] , 8 ) |
F_77 ( V_287 [ V_312 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 6 ) ,
F_77 ( V_287 [ V_313 ] , 24 ) |
F_77 ( V_287 [ V_314 ] , 16 ) |
F_77 ( V_287 [ V_315 ] , 8 ) |
F_77 ( V_287 [ V_316 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 7 ) ,
F_77 ( V_287 [ V_317 ] , 24 ) |
F_77 ( V_287 [ V_318 ] , 16 ) |
F_77 ( V_287 [ V_319 ] , 8 ) |
F_77 ( V_287 [ V_320 ] , 0 )
) ;
F_55 ( V_7 , F_78 ( 11 ) ,
F_77 ( V_287 [ V_321 ] , 24 ) |
F_77 ( V_287 [ V_322 ] , 16 ) |
F_77 ( V_287 [ V_323 ] , 8 ) |
F_77 ( V_287 [ V_324 ] , 0 )
) ;
return 0 ;
#undef F_77
}
static void F_79 ( struct V_6 * V_7 , T_3 V_238 ,
T_2 * V_325 ,
bool V_259 )
{
V_325 [ V_289 ] =
F_71 ( V_7 , V_326 , V_238 ,
V_259 ) ;
V_325 [ V_292 ] =
F_71 ( V_7 , V_327 , V_238 ,
V_259 ) ;
V_325 [ V_291 ] =
F_71 ( V_7 , V_328 , V_238 ,
V_259 ) ;
V_325 [ V_290 ] =
F_71 ( V_7 , V_329 , V_238 ,
V_259 ) ;
}
static void F_80 ( struct V_6 * V_7 , T_3 V_238 ,
T_2 * V_325 )
{
V_325 [ V_293 ] =
F_75 ( V_7 , V_330 ,
V_238 ) ;
V_325 [ V_296 ] =
F_75 ( V_7 , V_331 , V_238 ) ;
V_325 [ V_295 ] =
F_75 ( V_7 , V_332 , V_238 ) ;
V_325 [ V_294 ] =
F_75 ( V_7 , V_333 , V_238 ) ;
}
static void F_81 ( struct V_6 * V_7 , T_3 V_238 ,
T_2 * V_325 , bool V_259 )
{
V_325 [ V_300 ] =
F_73 ( V_7 , V_334 , V_238 ,
V_259 ) ;
V_325 [ V_299 ] =
F_73 ( V_7 , V_335 ,
V_238 , V_259 ) ;
V_325 [ V_298 ] =
F_73 ( V_7 , V_336 , V_238 ,
V_259 ) ;
V_325 [ V_297 ] =
F_73 ( V_7 , V_337 , V_238 ,
V_259 ) ;
V_325 [ V_304 ] =
F_73 ( V_7 , V_338 , V_238 ,
V_259 ) ;
V_325 [ V_303 ] =
F_73 ( V_7 , V_339 , V_238 ,
V_259 ) ;
V_325 [ V_302 ] =
F_73 ( V_7 , V_340 , V_238 ,
V_259 ) ;
V_325 [ V_301 ] =
F_73 ( V_7 , V_341 , V_238 ,
V_259 ) ;
V_325 [ V_308 ] =
F_73 ( V_7 , V_342 , V_238 ,
V_259 ) ;
V_325 [ V_307 ] =
F_73 ( V_7 , V_343 , V_238 ,
V_259 ) ;
V_325 [ V_306 ] =
F_73 ( V_7 , V_344 , V_238 ,
V_259 ) ;
V_325 [ V_305 ] =
F_73 ( V_7 , V_345 , V_238 ,
V_259 ) ;
V_325 [ V_312 ] =
F_73 ( V_7 , V_346 , V_238 ,
V_259 ) ;
V_325 [ V_311 ] =
F_73 ( V_7 , V_347 , V_238 ,
V_259 ) ;
}
static void F_82 ( struct V_6 * V_7 ,
T_3 V_238 ,
T_2 * V_325 ,
bool V_259 )
{
T_2 V_348 = 0 ;
V_325 [ V_316 ] =
F_74 ( V_7 , V_334 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_315 ] =
F_74 ( V_7 , V_335 ,
V_238 ,
V_259 ) + V_348 ;
V_325 [ V_314 ] =
F_74 ( V_7 , V_336 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_313 ] =
F_74 ( V_7 , V_337 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_320 ] =
F_74 ( V_7 , V_338 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_319 ] =
F_74 ( V_7 , V_339 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_318 ] =
F_74 ( V_7 , V_340 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_317 ] =
F_74 ( V_7 , V_341 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_324 ] =
F_74 ( V_7 , V_342 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_323 ] =
F_74 ( V_7 , V_343 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_322 ] =
F_74 ( V_7 , V_344 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_321 ] =
F_74 ( V_7 , V_345 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_310 ] =
F_74 ( V_7 , V_346 , V_238 ,
V_259 ) + V_348 ;
V_325 [ V_309 ] =
F_74 ( V_7 , V_347 , V_238 ,
V_259 ) + V_348 ;
}
static void F_83 ( struct V_6 * V_7 ,
struct V_202 * V_203 ,
T_2 * V_325 )
{
bool V_259 = F_58 ( V_203 ) ;
unsigned int V_63 = 0 ;
struct V_57 * V_58 = F_16 ( V_7 ) ;
T_3 V_238 = V_203 -> V_209 ;
if ( V_259 )
F_80 ( V_7 , V_238 , V_325 ) ;
F_79 ( V_7 , V_238 , V_325 , V_259 ) ;
F_81 ( V_7 , V_238 , V_325 , V_259 ) ;
if ( F_84 ( V_203 ) )
F_82 ( V_7 , V_238 , V_325 ,
V_259 ) ;
for ( V_63 = 0 ; V_63 < V_349 ; V_63 ++ ) {
F_17 ( V_58 , V_65 , L_87 ,
V_63 , V_325 [ V_63 ] ) ;
}
}
static int F_85 ( struct V_6 * V_7 ,
int V_350 ,
int V_351 ,
int V_352 ,
int * V_353 ,
int * V_354 ,
int * V_355 , int * V_356 )
{
T_2 * V_357 ;
struct V_358 * V_359 ;
int V_259 ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_57 * V_58 = F_16 ( V_7 ) ;
if ( V_352 >= V_162 ) {
F_17 ( V_58 , V_65 ,
L_88 ,
V_162 ) ;
return - 1 ;
}
if ( V_350 ) {
if ( V_351 >= V_360 ) {
F_17 ( V_58 , V_65 ,
L_89 ,
V_360 ) ;
return - 1 ;
}
V_357 = & ( V_18 -> V_361 [ V_351 ] ) ;
V_359 = & ( V_18 -> V_362 [ V_352 ] [ V_351 ] ) ;
V_259 = 0 ;
} else {
if ( V_351 >= V_363 ) {
F_17 ( V_58 , V_65 ,
L_90 ,
V_363 ) ;
return - 1 ;
}
V_357 = & ( V_18 -> V_364 [ V_351 ] ) ;
V_359 = & ( V_18 -> V_365 [ V_352 ] [ V_351 ] ) ;
V_259 = 1 ;
}
* V_353 = F_72 ( * V_357 , V_259 ) ;
* V_354 = V_359 -> V_366 ;
* V_355 = V_359 -> V_367 ;
* V_356 = V_359 -> V_368 ;
return 0 ;
}
static int F_86 ( struct V_6 * V_7 ,
int V_369 ,
int * V_370 ,
int * V_371 , int * V_372 )
{
int V_119 = 0 ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
int V_204 [ 3 ] , V_205 [ 3 ] ;
F_87 ( V_7 , V_373 ,
( V_370 [ 0 ] << V_374 ) ,
V_375 ) ;
if ( V_7 -> V_376 . V_377 & F_10 ( 1 ) )
F_87 ( V_7 , V_378 ,
( V_370 [ 1 ] << V_374 ) ,
V_375 ) ;
if ( V_7 -> V_376 . V_377 & F_10 ( 2 ) )
F_87 ( V_7 , V_379 ,
( V_370 [ 2 ] << V_374 ) ,
V_375 ) ;
F_87 ( V_7 , V_380 ,
( 3 << V_381 ) ,
V_382 ) ;
if ( V_7 -> V_376 . V_377 & F_10 ( 1 ) )
F_87 ( V_7 , V_383 ,
( 3 << V_381 ) ,
V_382 ) ;
if ( V_7 -> V_376 . V_377 & F_10 ( 2 ) )
F_87 ( V_7 , V_384 ,
( 3 << V_381 ) ,
V_382 ) ;
if ( V_369 < 4000 )
V_119 = V_18 -> V_55 . V_119 ;
else if ( V_18 -> V_206 . V_385 != 0 ) {
V_205 [ 0 ] = V_18 -> V_206 . V_385 ;
V_204 [ 0 ] = 5180 ;
V_205 [ 1 ] = V_18 -> V_52 . V_119 ;
V_204 [ 1 ] = 5500 ;
V_205 [ 2 ] = V_18 -> V_206 . V_386 ;
V_204 [ 2 ] = 5785 ;
V_119 = F_59 ( ( T_5 ) V_369 ,
V_204 , V_205 , 3 ) ;
} else
V_119 = V_18 -> V_52 . V_119 ;
F_47 ( V_7 , V_387 , V_388 , V_119 ) ;
if ( F_88 ( V_7 ) )
F_47 ( V_7 , V_389 ,
V_390 , V_119 ) ;
F_47 ( V_7 , V_391 , V_392 ,
V_372 [ 0 ] ) ;
return 0 ;
}
static int F_89 ( struct V_6 * V_7 , int V_369 )
{
int V_352 , V_351 , V_393 ;
int V_350 ;
int V_394 [ V_162 ] ,
V_395 [ V_162 ] ,
V_396 [ V_162 ] , V_397 [ V_162 ] ;
int V_398 [ V_162 ] ,
V_399 [ V_162 ] ,
V_400 [ V_162 ] , V_401 [ V_162 ] ;
int V_402 ;
int V_370 [ V_162 ] ,
V_371 [ V_162 ] , V_372 [ V_162 ] ;
int V_353 , V_354 , V_355 , V_356 ;
struct V_57 * V_58 = F_16 ( V_7 ) ;
V_350 = ( V_369 >= 4000 ) ;
if ( V_350 )
V_393 = V_360 ;
else
V_393 = V_363 ;
for ( V_352 = 0 ; V_352 < V_162 ; V_352 ++ ) {
V_394 [ V_352 ] = 0 ;
V_398 [ V_352 ] = 100000 ;
}
for ( V_352 = 0 ; V_352 < V_162 ; V_352 ++ ) {
for ( V_351 = 0 ; V_351 < V_393 ; V_351 ++ ) {
if ( ! F_85 ( V_7 , V_350 , V_351 , V_352 ,
& V_353 , & V_354 ,
& V_355 , & V_356 ) ) {
V_402 = V_369 - V_353 ;
if ( V_402 <= 0 ) {
if ( V_398 [ V_352 ] <= 0 ||
V_398 [ V_352 ] >= 100000 ||
V_402 >
( V_369 - V_398 [ V_352 ] ) ) {
V_398 [ V_352 ] = V_353 ;
V_399 [ V_352 ] =
V_354 ;
V_400 [ V_352 ] =
V_355 ;
V_401 [ V_352 ] = V_356 ;
}
}
if ( V_402 >= 0 ) {
if ( V_394 [ V_352 ] <= 0
|| V_402 <
( V_369 - V_394 [ V_352 ] ) ) {
V_394 [ V_352 ] = V_353 ;
V_395 [ V_352 ] =
V_354 ;
V_396 [ V_352 ] =
V_355 ;
V_397 [ V_352 ] = V_356 ;
}
}
}
}
}
for ( V_352 = 0 ; V_352 < V_162 ; V_352 ++ ) {
F_17 ( V_58 , V_65 , L_91 ,
V_352 , V_369 , V_394 [ V_352 ] ,
V_395 [ V_352 ] , V_398 [ V_352 ] ,
V_399 [ V_352 ] ) ;
if ( V_398 [ V_352 ] == V_394 [ V_352 ] ) {
V_370 [ V_352 ] = V_395 [ V_352 ] ;
V_371 [ V_352 ] = V_397 [ V_352 ] ;
V_372 [ V_352 ] = V_396 [ V_352 ] ;
}
else if ( V_369 - V_394 [ V_352 ] < 1000 ) {
if ( V_398 [ V_352 ] - V_369 < 1000 ) {
V_370 [ V_352 ] = F_4 ( V_369 ,
V_394 [ V_352 ] ,
V_398 [ V_352 ] ,
V_395 [ V_352 ] ,
V_399 [ V_352 ] ) ;
V_372 [ V_352 ] = F_4 ( V_369 ,
V_394 [ V_352 ] ,
V_398 [ V_352 ] ,
V_396 [ V_352 ] ,
V_400 [ V_352 ] ) ;
V_371 [ V_352 ] = F_4 ( V_369 ,
V_394 [ V_352 ] ,
V_398 [ V_352 ] ,
V_397 [ V_352 ] ,
V_401 [ V_352 ] ) ;
}
else {
V_370 [ V_352 ] = V_395 [ V_352 ] ;
V_372 [ V_352 ] = V_396 [ V_352 ] ;
V_371 [ V_352 ] = V_397 [ V_352 ] ;
}
}
else if ( V_398 [ V_352 ] - V_369 < 1000 ) {
V_370 [ V_352 ] = V_399 [ V_352 ] ;
V_372 [ V_352 ] = V_400 [ V_352 ] ;
V_371 [ V_352 ] = V_401 [ V_352 ] ;
} else {
V_370 [ V_352 ] = 0 ;
V_372 [ V_352 ] = 0 ;
V_371 [ V_352 ] = 0 ;
}
}
F_86 ( V_7 , V_369 , V_370 , V_371 ,
V_372 ) ;
F_17 ( V_58 , V_65 ,
L_92 ,
V_369 , V_370 [ 0 ] , V_370 [ 1 ] , V_370 [ 2 ] ) ;
return 0 ;
}
static T_3 F_90 ( struct V_1 * V_18 ,
int V_403 ,
int V_404 ,
bool V_259 )
{
struct V_405 * V_406 = V_18 -> V_407 ;
struct V_408 * V_409 = V_18 -> V_410 ;
if ( V_259 )
return F_91 ( V_406 [ V_403 ] . V_411 [ V_404 ] ) ;
else
return F_91 ( V_409 [ V_403 ] . V_411 [ V_404 ] ) ;
}
static T_3 F_92 ( struct V_1 * V_18 ,
int V_403 ,
unsigned int V_404 ,
T_3 V_238 ,
bool V_259 )
{
struct V_405 * V_406 = V_18 -> V_407 ;
struct V_408 * V_409 = V_18 -> V_410 ;
T_2 * V_412 = V_259 ?
& V_18 -> V_413 [ V_403 ] [ 0 ] :
& V_18 -> V_414 [ V_403 ] [ 0 ] ;
if ( V_259 ) {
if ( F_72 ( V_412 [ V_404 - 1 ] , 1 ) < V_238 &&
F_93 ( V_406 [ V_403 ] . V_411 [ V_404 - 1 ] ) )
return F_91 ( V_406 [ V_403 ] . V_411 [ V_404 - 1 ] ) ;
} else {
if ( F_72 ( V_412 [ V_404 - 1 ] , 0 ) < V_238 &&
F_93 ( V_409 [ V_403 ] . V_411 [ V_404 - 1 ] ) )
return F_91 ( V_409 [ V_403 ] . V_411 [ V_404 - 1 ] ) ;
}
return V_415 ;
}
static T_3 F_94 ( struct V_1 * V_18 ,
T_3 V_238 , int V_403 , bool V_259 )
{
T_3 V_416 = V_415 ;
T_2 * V_412 = V_259 ?
& V_18 -> V_413 [ V_403 ] [ 0 ] :
& V_18 -> V_414 [ V_403 ] [ 0 ] ;
T_3 V_417 = V_259 ?
V_418 : V_419 ;
unsigned int V_404 ;
for ( V_404 = 0 ;
( V_404 < V_417 ) && ( V_412 [ V_404 ] != V_420 ) ;
V_404 ++ ) {
if ( V_238 == F_72 ( V_412 [ V_404 ] , V_259 ) ) {
V_416 =
F_90 ( V_18 , V_403 ,
V_404 , V_259 ) ;
break;
} else if ( ( V_404 > 0 ) &&
( V_238 < F_72 ( V_412 [ V_404 ] ,
V_259 ) ) ) {
V_416 =
F_92 ( V_18 , V_403 ,
V_404 , V_238 ,
V_259 ) ;
break;
}
}
return V_416 ;
}
static void F_95 ( struct V_6 * V_7 ,
struct V_202 * V_203 ,
T_2 * V_287 , T_3 V_421 ,
T_2 V_422 ,
T_3 V_423 )
{
struct V_57 * V_58 = F_16 ( V_7 ) ;
struct V_1 * V_424 = & V_7 -> V_19 . V_20 ;
T_3 V_416 ;
int V_63 ;
T_3 V_425 = 0 , V_426 ;
static const T_3 V_427 [] = {
V_428 , V_429 , V_430 , V_431
} ;
static const T_3 V_432 [] = {
V_433 , V_434 , V_435 , V_436 ,
V_437 , V_438
} ;
T_3 V_439 ;
const T_3 * V_440 ;
T_3 V_441 , V_238 ;
struct V_442 V_443 ;
T_2 * V_444 ;
T_2 V_445 ;
T_3 V_446 ;
bool V_150 = F_58 ( V_203 ) ;
F_96 ( V_7 , V_203 , & V_443 ) ;
V_425 = F_97 ( V_7 , V_423 ,
V_422 ) ;
if ( V_150 ) {
V_439 =
F_98 ( V_432 ) -
V_447 ;
V_440 = V_432 ;
if ( F_84 ( V_203 ) )
V_439 = F_98 ( V_432 ) ;
} else {
V_439 = F_98 ( V_427 ) -
V_448 ;
V_440 = V_427 ;
if ( F_84 ( V_203 ) )
V_439 = F_98 ( V_427 ) ;
}
for ( V_441 = 0 ; V_441 < V_439 ; V_441 ++ ) {
bool V_449 = ( V_440 [ V_441 ] == V_431 ) ||
( V_440 [ V_441 ] == V_438 ) ;
if ( V_449 )
V_238 = V_443 . V_450 ;
else if ( V_440 [ V_441 ] & V_451 )
V_238 = V_443 . V_452 ;
else
V_238 = V_443 . V_453 ;
F_17 ( V_58 , V_454 ,
L_93 ,
V_441 , V_439 , V_449 ,
( V_440 [ V_441 ] & V_451 ) ) ;
if ( V_150 ) {
V_444 = V_424 -> V_455 ;
V_445 = V_456 ;
} else {
V_444 = V_424 -> V_457 ;
V_445 = V_458 ;
}
V_416 = V_415 ;
for ( V_63 = 0 ; ( V_63 < V_445 ) && V_444 [ V_63 ] ; V_63 ++ ) {
F_17 ( V_58 , V_454 ,
L_94 ,
V_63 , V_421 , V_440 [ V_441 ] , V_444 [ V_63 ] ,
V_203 -> V_209 ) ;
if ( ( ( ( V_421 & ~ V_459 ) |
( V_440 [ V_441 ] & V_459 ) ) ==
V_444 [ V_63 ] ) ||
( ( ( V_421 & ~ V_459 ) |
( V_440 [ V_441 ] & V_459 ) ) ==
( ( V_444 [ V_63 ] & V_459 ) |
V_460 ) ) ) {
V_446 =
F_94 ( V_424 ,
V_238 , V_63 ,
V_150 ) ;
if ( ( V_421 & ~ V_459 ) == V_460 )
V_416 =
F_99 ( V_416 ,
V_446 ) ;
else {
V_416 =
V_446 ;
break;
}
}
}
V_426 = ( T_2 ) F_99 ( V_416 , V_425 ) ;
F_17 ( V_58 , V_454 ,
L_95 ,
V_441 , V_440 [ V_441 ] , V_416 ,
V_425 , V_426 ) ;
switch ( V_440 [ V_441 ] ) {
case V_433 :
for ( V_63 = V_293 ;
V_63 <= V_294 ; V_63 ++ )
V_287 [ V_63 ] =
( T_2 ) F_99 ( ( T_3 ) V_287 [ V_63 ] ,
V_426 ) ;
break;
case V_428 :
case V_434 :
for ( V_63 = V_289 ;
V_63 <= V_290 ; V_63 ++ )
V_287 [ V_63 ] =
( T_2 ) F_99 ( ( T_3 ) V_287 [ V_63 ] ,
V_426 ) ;
break;
case V_429 :
case V_435 :
for ( V_63 = V_300 ;
V_63 <= V_305 ; V_63 ++ )
V_287 [ V_63 ] =
( T_2 ) F_99 ( ( T_3 ) V_287 [ V_63 ] ,
V_426 ) ;
V_287 [ V_312 ] =
( T_2 ) F_99 ( ( T_3 ) V_287 [ V_312 ] ,
V_426 ) ;
V_287 [ V_311 ] =
( T_2 ) F_99 ( ( T_3 ) V_287 [ V_311 ] ,
V_426 ) ;
break;
case V_431 :
case V_438 :
for ( V_63 = V_316 ;
V_63 <= V_309 ; V_63 ++ )
V_287 [ V_63 ] =
( T_2 ) F_99 ( ( T_3 ) V_287 [ V_63 ] ,
V_426 ) ;
break;
default:
break;
}
}
}
static inline T_2 F_100 ( unsigned int V_461 , T_2 V_462 )
{
T_2 V_463 = V_461 % 8 ;
if ( V_463 <= 3 )
return V_463 ? ( V_462 + 1 ) : V_462 ;
else
return V_462 + 4 * ( V_461 / 8 ) + V_463 - 2 ;
}
static void F_101 ( struct V_6 * V_7 ,
struct V_202 * V_203 , T_3 V_421 ,
T_2 V_464 ,
T_2 V_423 , bool V_465 )
{
struct V_466 * V_467 = F_102 ( V_7 ) ;
struct V_57 * V_58 = F_16 ( V_7 ) ;
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
struct V_111 * V_112 ;
T_2 V_325 [ V_349 ] ;
T_2 V_468 [ V_349 ] ;
unsigned int V_63 = 0 , V_469 = 0 ;
T_2 V_470 , V_471 = 0 ;
memset ( V_325 , 0 , sizeof( V_325 ) ) ;
F_83 ( V_7 , V_203 , V_325 ) ;
if ( V_7 -> V_187 -> V_188 ( V_7 , V_46 ) ) {
if ( F_58 ( V_203 ) )
V_112 = & V_18 -> V_55 ;
else
V_112 = & V_18 -> V_52 ;
V_7 -> V_472 =
F_9 ( V_112 -> V_473 ) &
V_474 ;
V_7 -> V_475 =
F_9 ( V_112 -> V_476 ) &
V_474 ;
V_469 = F_103 ( V_7 , V_203 ) ;
V_471 = F_84 ( V_203 ) ? V_316 :
V_300 ;
if ( ! V_7 -> V_477 ) {
memcpy ( V_468 , V_325 ,
sizeof( V_325 ) ) ;
for ( V_63 = 0 ; V_63 < 24 ; V_63 ++ ) {
V_470 = F_100 ( V_63 , V_471 ) ;
if ( V_7 -> V_472 & ( 1 << V_63 ) ) {
if ( V_325 [ V_470 ] &&
V_325 [ V_470 ] ==
V_468 [ V_470 ] )
V_325 [ V_470 ] -=
V_469 ;
}
}
}
memcpy ( V_468 , V_325 ,
sizeof( V_325 ) ) ;
}
F_95 ( V_7 , V_203 ,
V_325 , V_421 ,
V_464 ,
V_423 ) ;
if ( V_7 -> V_187 -> V_188 ( V_7 , V_46 ) ) {
for ( V_63 = 0 ; V_63 < V_349 ; V_63 ++ ) {
if ( ( V_7 -> V_472 & ( 1 << V_63 ) ) &&
( abs ( V_325 [ V_63 ] -
V_468 [ V_63 ] ) >
V_469 ) ) {
V_7 -> V_472 &= ~ ( 1 << V_63 ) ;
F_17 ( V_58 , V_65 ,
L_96 , V_63 ) ;
}
}
}
V_467 -> V_478 = 0 ;
for ( V_63 = 0 ; V_63 < V_349 ; V_63 ++ ) {
if ( V_325 [ V_63 ] > V_467 -> V_478 )
V_467 -> V_478 = V_325 [ V_63 ] ;
}
F_104 ( V_7 ) ;
if ( V_465 )
return;
for ( V_63 = 0 ; V_63 < V_349 ; V_63 ++ ) {
F_17 ( V_58 , V_65 , L_87 ,
V_63 , V_325 [ V_63 ] ) ;
}
F_76 ( V_7 , V_325 ) ;
F_89 ( V_7 , V_203 -> V_209 ) ;
if ( F_58 ( V_203 ) ) {
if ( F_84 ( V_203 ) )
V_63 = V_316 ;
else
V_63 = V_300 ;
} else {
if ( F_84 ( V_203 ) )
V_63 = V_319 ;
else
V_63 = V_303 ;
}
V_7 -> V_479 = V_325 [ V_63 ] ;
}
static T_3 F_105 ( struct V_6 * V_7 ,
T_3 V_63 , bool V_259 )
{
return V_480 ;
}
T_5 F_106 ( struct V_6 * V_7 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
return ( V_18 -> V_23 . V_149 >> 4 ) & 0xf ;
}
T_5 F_107 ( struct V_6 * V_7 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
return ( V_18 -> V_23 . V_149 ) & 0xf ;
}
T_2 * F_108 ( struct V_6 * V_7 , bool V_159 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
if ( V_159 )
return V_18 -> V_55 . V_121 ;
else
return V_18 -> V_52 . V_121 ;
}
unsigned int F_103 ( struct V_6 * V_7 ,
struct V_202 * V_203 )
{
struct V_1 * V_18 = & V_7 -> V_19 . V_20 ;
if ( F_58 ( V_203 ) )
return F_109 ( F_9 ( V_18 -> V_55 . V_473 ) ,
V_481 ) ;
else {
if ( V_203 -> V_209 >= 5700 )
return F_109 ( F_9 ( V_18 -> V_52 . V_473 ) ,
V_481 ) ;
else if ( V_203 -> V_209 >= 5400 )
return F_109 ( F_9 ( V_18 -> V_52 . V_476 ) ,
V_482 ) ;
else
return F_109 ( F_9 ( V_18 -> V_52 . V_476 ) ,
V_481 ) ;
}
}
