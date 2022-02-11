static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_5 * V_6 = V_2 -> V_6 ;
const struct V_7 * V_8 = & V_9 [ V_10 ] ;
F_2 ( V_11 , 0x11 ) ;
F_3 ( V_2 -> V_6 , V_8 , V_4 -> V_12 , V_4 -> V_13 . V_14 ) ;
F_4 ( V_15 , V_4 -> V_12 ) ;
F_4 ( V_16 , V_17 ) ;
F_5 ( & V_2 -> V_18 , 0 ) ;
F_6 ( 1 ,
L_1 ,
V_4 -> V_12 , F_7 ( V_8 -> V_19 + 8 ) >> 1 ,
V_2 -> V_20 , V_4 -> V_12 * V_2 -> V_20 ) ;
F_4 ( V_21 , V_22 | V_23 |
V_24 | V_25 ) ;
F_4 ( V_26 , ~ 0 ) ;
F_8 ( V_27 , V_2 -> V_6 -> V_28 | V_29 ) ;
F_8 ( V_30 , ( 1 << 5 ) ) ;
F_8 ( V_11 , 0x11 ) ;
if ( V_31 )
F_9 ( V_2 -> V_6 , V_8 ) ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
F_6 ( 1 , L_2 ) ;
F_2 ( V_11 , 0x11 ) ;
F_2 ( V_27 , V_29 ) ;
F_2 ( V_21 , V_22 | V_23 |
V_24 | V_25 ) ;
if ( V_31 )
F_9 ( V_2 -> V_6 ,
& V_9 [ V_10 ] ) ;
return 0 ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_32 , V_33 ;
V_32 = F_7 ( V_26 ) ;
V_33 = F_7 ( V_21 ) ;
if ( 0 == ( V_32 & V_33 ) )
return;
F_4 ( V_26 , V_32 ) ;
if ( V_31 > 1 || ( V_32 & V_33 & ~ 0xff ) )
F_12 ( L_3 ,
V_34 , F_13 ( V_34 ) ,
V_32 , V_33 ) ;
if ( V_32 & V_22 ) {
F_14 ( L_4 ) ;
F_2 ( V_11 , 0x11 ) ;
F_9 ( V_6 , & V_9 [ V_10 ] ) ;
}
if ( V_32 & V_23 ) {
F_6 ( 1 , L_5 ) ;
F_4 ( V_16 , V_17 ) ;
return;
}
if ( V_32 & V_25 ) {
F_5 ( & V_2 -> V_18 , F_7 ( V_35 ) ) ;
F_15 ( V_2 -> V_36 ) ;
}
}
static T_2 F_16 ( int V_37 , void * V_38 )
{
struct V_1 * V_2 = V_38 ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_32 ;
int V_39 , V_40 = 0 ;
for ( V_39 = 0 ; V_39 < V_41 ; V_39 ++ ) {
V_32 = F_7 ( V_42 ) &
( V_6 -> V_28 | V_29 ) ;
if ( V_32 == 0 )
goto V_43;
F_6 ( 3 , L_6 ,
V_39 , V_41 , V_32 ) ;
V_40 = 1 ;
F_4 ( V_42 , V_32 ) ;
if ( V_32 & V_6 -> V_28 )
F_17 ( V_6 , V_32 ) ;
if ( V_32 & V_29 )
F_11 ( V_2 ) ;
}
if ( V_39 == V_41 ) {
F_18 ( L_7 ) ;
F_2 ( V_27 , V_29 ) ;
}
V_43:
return F_19 ( V_40 ) ;
}
static int F_20 ( struct V_1 * V_2 , int V_44 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_45 * V_46 ;
int V_47 ;
V_4 -> V_48 = F_21 ( V_44 << V_49 ) ;
if ( ! V_4 -> V_48 ) {
F_6 ( 1 , L_8 , V_44 ) ;
return - V_50 ;
}
F_6 ( 1 , L_9 ,
( unsigned long ) V_4 -> V_48 , V_44 << V_49 ) ;
memset ( V_4 -> V_48 , 0 , V_44 << V_49 ) ;
V_4 -> V_44 = V_44 ;
V_4 -> V_51 = F_22 ( V_4 -> V_44 * sizeof( * V_4 -> V_51 ) ) ;
if ( ! V_4 -> V_51 )
goto V_52;
F_23 ( V_4 -> V_51 , V_4 -> V_44 ) ;
for ( V_47 = 0 ; V_47 < V_4 -> V_44 ; V_47 ++ ) {
V_46 = F_24 ( V_4 -> V_48 + V_47 * V_53 ) ;
if ( ! V_46 )
goto V_54;
F_25 ( & V_4 -> V_51 [ V_47 ] , V_46 , V_53 , 0 ) ;
}
return 0 ;
V_54:
F_26 ( V_4 -> V_51 ) ;
V_4 -> V_51 = NULL ;
V_52:
F_26 ( V_4 -> V_48 ) ;
V_4 -> V_48 = NULL ;
return - V_50 ;
}
static int F_27 ( struct V_1 * V_55 )
{
struct V_3 * V_4 = V_55 -> V_4 ;
V_4 -> V_56 = F_28 ( & V_55 -> V_57 -> V_55 , V_4 -> V_51 ,
V_4 -> V_44 , V_58 ) ;
if ( V_4 -> V_56 == 0 ) {
F_14 ( L_10 , V_59 ) ;
return - V_50 ;
}
return 0 ;
}
static int F_29 ( struct V_1 * V_55 )
{
struct V_3 * V_4 = V_55 -> V_4 ;
if ( ! V_4 -> V_56 )
return 0 ;
F_30 ( & V_55 -> V_57 -> V_55 , V_4 -> V_51 , V_4 -> V_56 ,
V_58 ) ;
V_4 -> V_56 = 0 ;
return 0 ;
}
static int F_31 ( struct V_3 * V_4 )
{
F_26 ( V_4 -> V_51 ) ;
V_4 -> V_51 = NULL ;
F_26 ( V_4 -> V_48 ) ;
V_4 -> V_48 = NULL ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 )
{
struct V_60 * V_13 = & V_2 -> V_4 -> V_13 ;
F_33 ( ! V_2 -> V_61 ) ;
F_6 ( 2 , L_11 ) ;
F_29 ( V_2 ) ;
F_31 ( V_2 -> V_4 ) ;
if ( V_13 -> V_62 )
F_34 ( V_2 -> V_57 , V_13 -> V_63 ,
V_13 -> V_62 , V_13 -> V_14 ) ;
F_35 ( V_2 -> V_4 ) ;
V_2 -> V_4 = NULL ;
return 0 ;
}
static int F_36 ( struct V_64 * V_36 )
{
struct V_1 * V_2 = F_37 ( V_36 ) ;
struct V_65 * V_66 = V_36 -> V_66 ;
int V_67 ;
if ( ! V_2 ) {
F_18 ( L_12 ) ;
return - V_68 ;
}
V_67 = F_38 ( V_66 , 0 ,
V_69 ) ;
if ( V_67 < 0 )
goto V_70;
V_2 -> V_36 = V_36 ;
V_66 -> V_71 = V_72 ;
if ( V_9 [ V_10 ] . V_73 != V_74 ) {
unsigned int V_12 = V_9 [ V_10 ] . V_73 / 4 ;
V_12 &= ~ 7 ;
V_66 -> V_71 . V_75 = V_12 ;
V_66 -> V_71 . V_76 = V_12 ;
}
return 0 ;
V_70:
F_6 ( 1 , L_13 ) ;
return V_67 ;
}
static int F_39 ( struct V_64 * V_36 )
{
return 0 ;
}
static int F_40 ( struct V_64 * V_36 ,
struct V_77 * V_78 )
{
struct V_1 * V_2 = F_37 ( V_36 ) ;
struct V_3 * V_4 ;
int V_79 ;
if ( V_36 -> V_66 -> V_80 ) {
F_32 ( V_2 ) ;
V_36 -> V_66 -> V_80 = NULL ;
}
V_2 -> V_81 = F_41 ( V_78 ) ;
V_2 -> V_20 = F_42 ( V_78 ) ;
V_2 -> V_61 = V_2 -> V_81 * F_42 ( V_78 ) ;
F_33 ( ! V_2 -> V_61 ) ;
F_33 ( V_2 -> V_20 & ( V_2 -> V_20 - 1 ) ) ;
V_4 = F_43 ( sizeof( * V_4 ) , V_82 ) ;
if ( ! V_4 )
return - V_50 ;
V_2 -> V_4 = V_4 ;
V_4 -> V_12 = V_2 -> V_81 ;
V_79 = F_20 ( V_2 ,
( F_44 ( V_2 -> V_61 ) >> V_49 ) ) ;
if ( V_79 < 0 )
goto error;
V_79 = F_27 ( V_2 ) ;
if ( V_79 < 0 )
goto error;
V_79 = F_45 ( V_2 -> V_57 , & V_4 -> V_13 , V_4 -> V_51 ,
V_2 -> V_81 , V_2 -> V_20 , 1 ) ;
if ( V_79 < 0 )
goto error;
V_4 -> V_13 . V_83 [ 0 ] = F_46 ( V_84 | V_85 | V_86 ) ;
V_4 -> V_13 . V_83 [ 1 ] = F_46 ( V_4 -> V_13 . V_14 ) ;
V_36 -> V_66 -> V_80 = V_2 -> V_4 -> V_48 ;
V_36 -> V_66 -> V_87 = V_2 -> V_61 ;
V_36 -> V_66 -> V_88 = 0 ;
return 0 ;
error:
F_35 ( V_4 ) ;
return V_79 ;
}
static int F_47 ( struct V_64 * V_36 )
{
struct V_1 * V_2 = F_37 ( V_36 ) ;
if ( V_36 -> V_66 -> V_80 ) {
F_32 ( V_2 ) ;
V_36 -> V_66 -> V_80 = NULL ;
}
return 0 ;
}
static int F_48 ( struct V_64 * V_36 )
{
return 0 ;
}
static int F_49 ( struct V_64 * V_36 , int V_89 )
{
struct V_1 * V_2 = F_37 ( V_36 ) ;
int V_67 ;
F_50 ( & V_2 -> V_90 ) ;
switch ( V_89 ) {
case V_91 :
V_67 = F_1 ( V_2 ) ;
break;
case V_92 :
V_67 = F_10 ( V_2 ) ;
break;
default:
V_67 = - V_93 ;
break;
}
F_51 ( & V_2 -> V_90 ) ;
return V_67 ;
}
static T_3 F_52 ( struct V_64 * V_36 )
{
struct V_1 * V_2 = F_37 ( V_36 ) ;
struct V_65 * V_66 = V_36 -> V_66 ;
T_4 V_18 ;
V_18 = F_53 ( & V_2 -> V_18 ) ;
return V_66 -> V_81 * ( V_18 & ( V_66 -> V_94 - 1 ) ) ;
}
static struct V_45 * F_54 ( struct V_64 * V_36 ,
unsigned long V_95 )
{
void * V_96 = V_36 -> V_66 -> V_80 + V_95 ;
return F_24 ( V_96 ) ;
}
static int F_55 ( struct V_1 * V_2 , int V_97 ,
const char * V_98 )
{
int V_67 ;
struct V_99 * V_100 ;
V_67 = F_56 ( V_2 -> V_101 , V_98 , V_97 , 0 , 1 , & V_100 ) ;
if ( V_67 < 0 )
return V_67 ;
V_100 -> V_102 = V_2 ;
strcpy ( V_100 -> V_98 , V_98 ) ;
F_57 ( V_100 , V_103 , & V_104 ) ;
return 0 ;
}
static int F_58 ( struct V_105 * V_106 ,
struct V_107 * V_108 )
{
V_108 -> type = V_109 ;
V_108 -> V_18 = 2 ;
V_108 -> V_110 . integer . V_111 = 0 ;
V_108 -> V_110 . integer . V_112 = 0x3f ;
return 0 ;
}
static int F_59 ( struct V_105 * V_106 ,
struct V_113 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_114 = 0x3f - ( F_7 ( V_115 ) & 0x3f ) ,
V_116 = F_7 ( V_117 ) ;
V_110 -> V_110 . integer . V_110 [ ( V_116 & 0x40 ) ? 0 : 1 ] = V_114 ;
V_114 -= ( V_116 & 0x3f ) ;
V_110 -> V_110 . integer . V_110 [ ( V_116 & 0x40 ) ? 1 : 0 ] = V_114 < 0 ? 0 : V_114 ;
return 0 ;
}
static void F_61 ( struct V_105 * V_106 ,
struct V_113 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_118 = V_110 -> V_110 . integer . V_110 [ 0 ] ;
int V_119 = V_110 -> V_110 . integer . V_110 [ 1 ] ;
int V_120 , V_121 ;
if ( V_118 >= V_119 ) {
V_120 = V_118 << 10 ;
V_121 = V_118 ? ( 0x8000 * V_119 ) / V_118 : 0x8000 ;
} else {
V_120 = V_119 << 10 ;
V_121 = V_119 ? 0xffff - ( 0x8000 * V_118 ) / V_119 : 0x8000 ;
}
F_62 ( V_6 , V_122 , V_120 ) ;
F_62 ( V_6 , V_123 , V_121 ) ;
}
static int F_63 ( struct V_105 * V_106 ,
struct V_113 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
int V_118 , V_119 , V_120 , V_121 ;
int V_124 = 0 ;
T_1 V_125 ;
if ( V_6 -> V_126 )
F_61 ( V_106 , V_110 ) ;
V_118 = V_110 -> V_110 . integer . V_110 [ 0 ] & 0x3f ;
V_119 = V_110 -> V_110 . integer . V_110 [ 1 ] & 0x3f ;
V_121 = V_119 - V_118 ;
if ( V_121 < 0 ) {
V_120 = 0x3f - V_118 ;
V_121 = ( - V_121 ) | 0x40 ;
} else {
V_120 = 0x3f - V_119 ;
}
F_64 ( & V_2 -> V_90 ) ;
V_125 = F_7 ( V_115 ) ;
if ( V_120 != ( V_125 & 0x3f ) ) {
F_65 ( V_127 , V_115 , ( V_125 & ~ 0x3f ) | V_120 ) ;
V_124 = 1 ;
}
if ( ( F_7 ( V_117 ) & 0x7f ) != V_121 ) {
F_4 ( V_117 , V_121 ) ;
V_124 = 1 ;
}
F_66 ( & V_2 -> V_90 ) ;
return V_124 ;
}
static int F_67 ( struct V_105 * V_106 ,
struct V_113 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_128 = V_106 -> V_129 ;
V_110 -> V_110 . integer . V_110 [ 0 ] = ! ( F_7 ( V_115 ) & V_128 ) ;
return 0 ;
}
static int F_68 ( struct V_105 * V_106 ,
struct V_113 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_1 V_128 = V_106 -> V_129 ;
int V_79 = 0 ;
T_1 V_114 ;
F_64 ( & V_2 -> V_90 ) ;
V_114 = F_7 ( V_115 ) ;
if ( V_110 -> V_110 . integer . V_110 [ 0 ] != ! ( V_114 & V_128 ) ) {
V_114 ^= V_128 ;
F_65 ( V_127 , V_115 , V_114 ) ;
if ( V_6 -> V_126 && ( ( 1 << 6 ) == V_128 ) )
F_62 ( V_6 ,
V_130 , 0 != ( V_114 & V_128 ) ) ;
V_79 = 1 ;
}
F_66 ( & V_2 -> V_90 ) ;
return V_79 ;
}
static int F_69 ( struct V_105 * V_106 ,
struct V_113 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
T_5 V_131 ;
V_131 = F_70 ( V_6 , V_132 ) ;
V_110 -> V_110 . integer . V_110 [ 0 ] = V_131 ? 1 : 0 ;
return 0 ;
}
static int F_71 ( struct V_105 * V_106 ,
struct V_113 * V_110 )
{
struct V_1 * V_2 = F_60 ( V_106 ) ;
struct V_5 * V_6 = V_2 -> V_6 ;
F_62 ( V_6 , V_132 ,
V_110 -> V_110 . integer . V_110 [ 0 ] != 0 ) ;
return 0 ;
}
static int F_72 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 >= 0 )
F_73 ( V_2 -> V_37 , V_2 ) ;
F_74 ( V_2 -> V_6 , V_2 -> V_57 ) ;
F_75 ( V_2 -> V_57 ) ;
return 0 ;
}
static void F_76 ( struct V_133 * V_101 )
{
struct V_1 * V_2 = V_101 -> V_102 ;
F_72 ( V_2 ) ;
}
static int F_77 ( struct V_133 * V_101 , struct V_134 * V_57 ,
struct V_1 * * V_135 ,
struct V_5 * * V_136 )
{
struct V_1 * V_2 ;
struct V_5 * V_6 ;
int V_67 ;
unsigned char V_137 ;
* V_135 = NULL ;
V_67 = F_78 ( V_57 ) ;
if ( V_67 < 0 )
return V_67 ;
F_79 ( V_57 ) ;
V_2 = V_101 -> V_102 ;
V_6 = F_80 ( V_57 ) ;
if ( ! V_6 ) {
V_67 = - V_93 ;
return V_67 ;
}
V_67 = F_81 ( V_57 , F_82 ( 32 ) ) ;
if ( V_67 ) {
F_6 ( 0 , L_14 , V_6 -> V_98 ) ;
F_74 ( V_6 , V_57 ) ;
return V_67 ;
}
V_2 -> V_101 = V_101 ;
V_2 -> V_57 = V_57 ;
V_2 -> V_37 = - 1 ;
F_83 ( & V_2 -> V_90 ) ;
V_2 -> V_6 = V_6 ;
V_67 = F_84 ( V_2 -> V_57 -> V_37 , F_16 ,
V_138 , V_2 -> V_6 -> V_98 , V_2 ) ;
if ( V_67 < 0 ) {
F_6 ( 0 , L_15 ,
V_2 -> V_6 -> V_98 , V_2 -> V_57 -> V_37 ) ;
return V_67 ;
}
F_85 ( V_57 , V_139 , & V_137 ) ;
F_6 ( 1 ,
L_16 ,
V_6 -> V_98 , V_140 ,
F_86 ( V_57 ) , V_57 -> V_141 , V_57 -> V_37 ,
V_137 , ( unsigned long long ) F_87 ( V_57 , 0 ) ) ;
V_2 -> V_37 = V_57 -> V_37 ;
F_88 ( V_2 -> V_37 ) ;
* V_135 = V_2 ;
* V_136 = V_6 ;
return 0 ;
}
static int F_89 ( struct V_134 * V_57 ,
const struct V_142 * V_143 )
{
struct V_133 * V_101 ;
struct V_1 * V_2 ;
struct V_5 * V_6 = NULL ;
int V_67 ;
if ( V_140 >= V_144 )
return ( - V_68 ) ;
if ( ! V_145 [ V_140 ] ) {
++ V_140 ;
return ( - V_146 ) ;
}
V_67 = F_90 ( & V_57 -> V_55 , V_147 [ V_140 ] , V_148 [ V_140 ] , V_149 ,
sizeof( struct V_1 ) , & V_101 ) ;
if ( V_67 < 0 )
return V_67 ;
V_101 -> V_150 = F_76 ;
V_67 = F_77 ( V_101 , V_57 , & V_2 , & V_6 ) ;
if ( V_67 < 0 )
goto error;
V_67 = F_55 ( V_2 , 0 , L_17 ) ;
if ( V_67 < 0 )
goto error;
V_67 = F_91 ( V_101 , F_92 ( & V_151 , V_2 ) ) ;
if ( V_67 < 0 )
goto error;
V_67 = F_91 ( V_101 , F_92 ( & V_152 , V_2 ) ) ;
if ( V_67 < 0 )
goto error;
V_67 = F_91 ( V_101 , F_92 ( & V_153 , V_2 ) ) ;
if ( V_67 < 0 )
goto error;
if ( V_6 -> V_126 )
F_91 ( V_101 , F_92 ( & V_154 , V_2 ) ) ;
strcpy ( V_101 -> V_155 , L_18 ) ;
sprintf ( V_101 -> V_156 , L_19 , V_57 -> V_97 ) ;
sprintf ( V_101 -> V_157 , L_20 ,
V_101 -> V_156 ,
( unsigned long long ) F_87 ( V_57 , 0 ) ) ;
strcpy ( V_101 -> V_158 , L_21 ) ;
F_6 ( 0 , L_22 ,
V_101 -> V_155 , V_140 ) ;
V_67 = F_93 ( V_101 ) ;
if ( V_67 < 0 )
goto error;
F_94 ( V_57 , V_101 ) ;
V_140 ++ ;
return 0 ;
error:
F_95 ( V_101 ) ;
return V_67 ;
}
static void F_96 ( struct V_134 * V_57 )
{
struct V_133 * V_101 = F_97 ( V_57 ) ;
F_95 ( V_101 ) ;
V_140 -- ;
}
