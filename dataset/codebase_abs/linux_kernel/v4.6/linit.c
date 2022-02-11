static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 = 0 ;
V_4 -> V_6 . V_7 = V_8 ;
V_5 = ( F_2 ( V_4 ) ? V_9 : 0 ) ;
return V_5 ;
}
static const char * F_3 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = (struct V_10 * ) V_2 -> V_12 ;
return V_13 [ V_11 -> V_14 ] . V_15 ;
}
struct V_16 * F_4 ( int V_17 )
{
return & V_13 [ V_17 ] ;
}
static int F_5 ( struct V_18 * V_19 , struct V_20 * V_21 ,
T_1 V_22 , int * V_23 )
{
struct V_24 * V_25 = (struct V_24 * ) V_23 ;
unsigned char * V_26 ;
F_6 ( ( V_27 L_1 ) ) ;
if ( V_22 >= 2 * 1024 * 1024 ) {
if( V_22 >= 4 * 1024 * 1024 ) {
V_25 -> V_28 = 255 ;
V_25 -> V_29 = 63 ;
} else {
V_25 -> V_28 = 128 ;
V_25 -> V_29 = 32 ;
}
} else {
V_25 -> V_28 = 64 ;
V_25 -> V_29 = 32 ;
}
V_25 -> V_30 = F_7 ( V_22 , V_25 -> V_28 * V_25 -> V_29 ) ;
V_26 = F_8 ( V_21 ) ;
if ( ! V_26 )
return 0 ;
if( * ( V_31 * ) ( V_26 + 0x40 ) == F_9 ( 0xaa55 ) ) {
struct V_32 * V_33 = (struct V_32 * ) V_26 ;
struct V_32 * V_34 = V_33 ;
int V_35 = V_25 -> V_30 ;
int V_36 ;
unsigned char V_37 , V_38 ;
for( V_36 = 0 ; V_36 < 4 ; V_36 ++ ) {
V_37 = V_34 -> V_37 ;
V_38 = V_34 -> V_39 & 0x3f ;
if( V_37 == 63 ) {
V_25 -> V_28 = 64 ;
V_25 -> V_29 = 32 ;
break;
} else if( V_37 == 127 ) {
V_25 -> V_28 = 128 ;
V_25 -> V_29 = 32 ;
break;
} else if( V_37 == 254 ) {
V_25 -> V_28 = 255 ;
V_25 -> V_29 = 63 ;
break;
}
V_34 ++ ;
}
if ( V_36 == 4 ) {
V_37 = V_33 -> V_37 ;
V_38 = V_33 -> V_39 & 0x3f ;
}
V_25 -> V_30 = F_7 ( V_22 , V_25 -> V_28 * V_25 -> V_29 ) ;
if ( V_36 < 4 && V_38 == V_25 -> V_29 ) {
if ( V_25 -> V_30 != V_35 )
F_6 ( ( V_27 L_2 ,
V_25 -> V_28 , V_25 -> V_29 , V_36 ) ) ;
} else if ( V_37 > 0 || V_38 > 0 ) {
F_6 ( ( V_27 L_3 ,
V_37 + 1 , V_38 , V_36 ) ) ;
F_6 ( ( V_27 L_4 ,
V_25 -> V_28 , V_25 -> V_29 ) ) ;
}
}
F_10 ( V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_10 * V_40 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( V_40 -> V_42 && ( V_19 -> type == V_43 ) )
V_19 -> V_44 = 1 ;
if ( ( V_19 -> type == V_43 ) &&
( F_12 ( V_19 ) != V_45 ) &&
( ! V_40 -> V_42 || V_19 -> V_46 ) &&
( ! V_40 -> V_47 || ( F_12 ( V_19 ) != 2 ) ) ) {
if ( V_48 == 0 )
return - V_49 ;
if ( V_48 < 0 )
V_19 -> V_50 = 1 ;
}
if ( V_19 -> V_51 && ( V_19 -> type == V_43 ) &&
( ! V_40 -> V_47 || ( F_12 ( V_19 ) != 2 ) ) &&
! V_19 -> V_50 ) {
struct V_18 * V_11 ;
struct V_1 * V_41 = V_19 -> V_41 ;
unsigned V_52 = 0 ;
unsigned V_53 = 0 ;
unsigned V_54 ;
unsigned V_55 ;
if ( V_19 -> V_56 -> V_57 < ( 45 * V_58 ) )
F_13 ( V_19 -> V_56 , 45 * V_58 ) ;
for ( V_55 = 0 ; V_55 < V_40 -> V_59 ; ++ V_55 )
if ( V_40 -> V_60 [ V_55 ] . V_61 )
++ V_52 ;
F_14 (dev, host) {
if ( V_11 -> V_51 && ( V_11 -> type == V_43 ) &&
( ! V_40 -> V_47 ||
( F_12 ( V_19 ) != 2 ) ) &&
! V_11 -> V_50 ) {
if ( ( F_12 ( V_11 ) != V_45 )
|| ! V_40 -> V_60 [ F_15 ( V_11 ) ] . V_61 )
++ V_52 ;
} else
++ V_53 ;
}
if ( V_52 == 0 )
++ V_52 ;
V_54 = ( V_41 -> V_62 - V_53 ) / V_52 ;
if ( V_54 > 256 )
V_54 = 256 ;
else if ( V_54 < 2 )
V_54 = 2 ;
F_16 ( V_19 , V_54 ) ;
} else {
F_16 ( V_19 , 1 ) ;
V_19 -> V_51 = 1 ;
}
return 0 ;
}
static int F_17 ( struct V_18 * V_19 , int V_54 )
{
if ( V_19 -> V_51 && ( V_19 -> type == V_43 ) &&
( F_12 ( V_19 ) == V_45 ) ) {
struct V_18 * V_11 ;
struct V_1 * V_41 = V_19 -> V_41 ;
unsigned V_36 = 0 ;
F_14 (dev, host) {
if ( V_11 -> V_51 && ( V_11 -> type == V_43 ) &&
( F_12 ( V_11 ) == V_45 ) )
++ V_36 ;
++ V_36 ;
}
if ( V_36 >= V_41 -> V_62 )
V_36 = V_41 -> V_62 - 1 ;
if ( V_54 > ( V_41 -> V_62 - V_36 ) )
V_54 = V_41 -> V_62 - V_36 ;
if ( V_54 > 256 )
V_54 = 256 ;
else if ( V_54 < 2 )
V_54 = 2 ;
return F_16 ( V_19 , V_54 ) ;
}
return F_16 ( V_19 , 1 ) ;
}
static T_2 F_18 ( struct V_63 * V_11 , struct V_64 * V_65 , char * V_26 )
{
struct V_18 * V_19 = F_19 ( V_11 ) ;
struct V_10 * V_40 = (struct V_10 * ) ( V_19 -> V_41 -> V_12 ) ;
if ( F_12 ( V_19 ) != V_45 )
return snprintf ( V_26 , V_66 , V_19 -> V_50
? L_5 :
( ( V_40 -> V_42 && ( V_19 -> type == V_43 ) ) ? L_6 : L_7 ) ) ;
return snprintf ( V_26 , V_66 , L_8 ,
F_20 ( V_40 -> V_60 [ F_15 ( V_19 ) ] . type ) ) ;
}
static int F_21 ( struct V_18 * V_19 , int V_4 , void T_3 * V_67 )
{
struct V_10 * V_11 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( ! F_22 ( V_68 ) )
return - V_69 ;
return F_23 ( V_11 , V_4 , V_67 ) ;
}
static int F_24 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_63 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
int V_70 ;
int V_71 = V_9 ;
F_25 ( V_72 L_9 ,
V_73 ,
V_41 -> V_74 , F_12 ( V_11 ) , F_15 ( V_11 ) , V_11 -> V_75 ) ;
switch ( V_4 -> V_76 [ 0 ] ) {
case V_77 :
if ( ! ( V_40 -> V_78 ) ||
! ( V_40 -> V_79 ) ||
( ( V_4 -> V_76 [ 1 ] & 0x1f ) != V_80 ) )
break;
case V_81 :
case V_82 :
for ( V_70 = 0 ; V_70 < ( V_41 -> V_62 + V_83 ) ; ++ V_70 ) {
struct V_84 * V_84 = & V_40 -> V_85 [ V_70 ] ;
if ( V_84 -> V_86 -> V_87 . V_88 &&
( V_84 -> V_89 & V_90 ) &&
( V_84 -> V_91 == V_4 ) ) {
V_84 -> V_89 |= V_92 ;
V_4 -> V_6 . V_7 = V_93 ;
V_71 = V_94 ;
}
}
break;
case V_95 :
for ( V_70 = 0 ; V_70 < ( V_41 -> V_62 + V_83 ) ; ++ V_70 ) {
struct V_3 * V_96 ;
struct V_84 * V_84 = & V_40 -> V_85 [ V_70 ] ;
if ( ( V_84 -> V_86 -> V_87 . V_88 & F_26 ( V_97 | V_98 ) ) &&
( V_84 -> V_89 & V_90 ) &&
( ( V_96 = V_84 -> V_91 ) ) &&
( V_96 -> V_63 == V_4 -> V_63 ) ) {
V_84 -> V_89 |= V_92 ;
V_96 -> V_6 . V_7 = V_93 ;
if ( V_96 == V_4 )
V_71 = V_94 ;
}
}
}
return V_71 ;
}
static int F_27 ( struct V_3 * V_4 )
{
struct V_18 * V_11 = V_4 -> V_63 ;
struct V_1 * V_41 = V_11 -> V_41 ;
struct V_3 * V_96 ;
int V_70 ;
struct V_10 * V_40 = (struct V_10 * ) V_41 -> V_12 ;
unsigned long V_89 ;
for ( V_70 = 0 ; V_70 < ( V_41 -> V_62 + V_83 ) ; ++ V_70 ) {
struct V_84 * V_84 = & V_40 -> V_85 [ V_70 ] ;
if ( V_84 -> V_86 -> V_87 . V_88 &&
( V_84 -> V_89 & V_90 ) &&
( V_84 -> V_91 == V_4 ) ) {
V_84 -> V_89 |= V_92 ;
V_4 -> V_6 . V_7 = V_93 ;
}
}
F_25 ( V_72 L_10 ,
V_73 ) ;
if ( ( V_70 = F_28 ( V_40 ) ) )
return V_70 ;
for ( V_70 = 60 ; V_70 ; -- V_70 ) {
int V_99 = V_40 -> V_100 ;
if ( V_99 == 0 )
F_14 (dev, host) {
F_29 ( & V_11 -> V_101 , V_89 ) ;
F_30 (command, &dev->cmd_list, list) {
if ( ( V_96 != V_4 ) &&
( V_96 -> V_6 . V_7 == V_102 ) ) {
V_99 ++ ;
break;
}
}
F_31 ( & V_11 -> V_101 , V_89 ) ;
if ( V_99 )
break;
}
if ( V_99 == 0 )
return V_94 ;
F_32 ( 1 ) ;
}
F_25 ( V_72 L_11 , V_73 ) ;
if ( ( ( V_40 -> V_103 . V_104 &
V_105 ) ||
( V_40 -> V_103 . V_104 &
V_106 ) ) &&
V_107 &&
( ( V_107 != 1 ) ||
! ( V_40 -> V_103 . V_104 &
V_108 ) ) )
F_33 ( V_40 , 2 ) ;
return V_94 ;
}
static int F_34 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
struct V_10 * V_40 ;
unsigned V_111 = F_35 ( V_109 ) ;
int V_112 = - V_113 ;
F_36 ( & V_114 ) ;
F_30 (aac, &aac_devices, entry) {
if ( V_40 -> V_115 == V_111 ) {
V_110 -> V_116 = V_40 ;
V_112 = 0 ;
break;
}
}
F_37 ( & V_114 ) ;
return V_112 ;
}
static long F_38 ( struct V_110 * V_110 ,
unsigned int V_4 , unsigned long V_67 )
{
struct V_10 * V_40 = (struct V_10 * ) V_110 -> V_116 ;
if ( ! F_22 ( V_68 ) )
return - V_69 ;
return F_23 ( V_40 , V_4 , ( void T_3 * ) V_67 ) ;
}
static long F_39 ( struct V_10 * V_11 , unsigned V_4 , unsigned long V_67 )
{
long V_71 ;
switch ( V_4 ) {
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
case V_125 :
case V_126 :
case V_127 :
V_71 = F_23 ( V_11 , V_4 , ( void T_3 * ) V_67 ) ;
break;
case V_128 : {
struct V_129 T_3 * V_130 ;
V_130 = F_40 ( sizeof( * V_130 ) ) ;
V_71 = 0 ;
if ( F_41 ( V_130 , sizeof( * V_130 ) ) )
V_71 = - V_131 ;
if ( F_42 ( V_130 , ( void T_3 * ) V_67 , sizeof( struct V_129 ) - sizeof( V_132 ) ) )
V_71 = - V_131 ;
if ( ! V_71 )
V_71 = F_23 ( V_11 , V_4 , V_130 ) ;
break;
}
default:
V_71 = - V_133 ;
break;
}
return V_71 ;
}
static int F_43 ( struct V_18 * V_19 , int V_4 , void T_3 * V_67 )
{
struct V_10 * V_11 = (struct V_10 * ) V_19 -> V_41 -> V_12 ;
if ( ! F_22 ( V_68 ) )
return - V_69 ;
return F_39 ( V_11 , V_4 , ( unsigned long ) V_67 ) ;
}
static long F_44 ( struct V_110 * V_110 , unsigned V_4 , unsigned long V_67 )
{
if ( ! F_22 ( V_68 ) )
return - V_69 ;
return F_39 ( V_110 -> V_116 , V_4 , V_67 ) ;
}
static T_2 F_45 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_134 ;
if ( V_11 -> V_103 . V_135 [ 0 ] ) {
char * V_136 = V_11 -> V_103 . V_135 ;
while ( * V_136 && * V_136 != ' ' )
++ V_136 ;
while ( * V_136 == ' ' )
++ V_136 ;
V_134 = snprintf ( V_26 , V_66 , L_8 , V_136 ) ;
} else
V_134 = snprintf ( V_26 , V_66 , L_8 ,
V_13 [ V_11 -> V_14 ] . V_137 ) ;
return V_134 ;
}
static T_2 F_47 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_134 ;
if ( V_11 -> V_103 . V_135 [ 0 ] ) {
char * V_136 = V_11 -> V_103 . V_135 ;
while ( * V_136 && * V_136 != ' ' )
++ V_136 ;
V_134 = snprintf ( V_26 , V_66 , L_12 ,
( int ) ( V_136 - ( char * ) V_11 -> V_103 . V_135 ) ,
V_11 -> V_103 . V_135 ) ;
} else
V_134 = snprintf ( V_26 , V_66 , L_8 ,
V_13 [ V_11 -> V_14 ] . V_138 ) ;
return V_134 ;
}
static T_2 F_48 ( struct V_63 * V_139 ,
struct V_64 * V_65 , char * V_26 )
{
int V_134 = 0 ;
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_139 ) -> V_12 ;
if ( F_49 ( F_6 ( V_140 ) ) )
V_134 = snprintf ( V_26 , V_66 , L_13 ) ;
#ifdef F_50
V_134 += snprintf ( V_26 + V_134 , V_66 - V_134 ,
L_14 ) ;
#endif
if ( V_11 -> V_78 && V_11 -> V_79 )
V_134 += snprintf ( V_26 + V_134 , V_66 - V_134 ,
L_15 ) ;
if ( V_11 -> V_42 )
V_134 += snprintf ( V_26 + V_134 , V_66 - V_134 , L_16 ) ;
if ( V_11 -> V_103 . V_104 &
V_141 )
V_134 += snprintf ( V_26 + V_134 , V_66 - V_134 ,
L_17 ) ;
if ( V_11 -> V_142 )
V_134 += snprintf ( V_26 + V_134 , V_66 - V_134 , L_18 ) ;
return V_134 ;
}
static T_2 F_51 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_134 , V_143 ;
V_143 = F_52 ( V_11 -> V_144 . V_145 ) ;
V_134 = snprintf ( V_26 , V_66 , L_19 ,
V_143 >> 24 , ( V_143 >> 16 ) & 0xff , V_143 & 0xff ,
F_52 ( V_11 -> V_144 . V_146 ) ) ;
return V_134 ;
}
static T_2 F_53 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_134 , V_143 ;
V_143 = F_52 ( V_11 -> V_144 . V_147 ) ;
V_134 = snprintf ( V_26 , V_66 , L_19 ,
V_143 >> 24 , ( V_143 >> 16 ) & 0xff , V_143 & 0xff ,
F_52 ( V_11 -> V_144 . V_148 ) ) ;
return V_134 ;
}
static T_2 F_54 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_134 , V_143 ;
V_143 = F_52 ( V_11 -> V_144 . V_149 ) ;
V_134 = snprintf ( V_26 , V_66 , L_19 ,
V_143 >> 24 , ( V_143 >> 16 ) & 0xff , V_143 & 0xff ,
F_52 ( V_11 -> V_144 . V_150 ) ) ;
return V_134 ;
}
static T_2 F_55 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_134 = 0 ;
if ( F_52 ( V_11 -> V_144 . V_151 [ 0 ] ) != 0xBAD0 )
V_134 = snprintf ( V_26 , 16 , L_20 ,
F_52 ( V_11 -> V_144 . V_151 [ 0 ] ) ) ;
if ( V_134 &&
! memcmp ( & V_11 -> V_103 . V_152 [
sizeof( V_11 -> V_103 . V_152 ) - V_134 ] ,
V_26 , V_134 - 1 ) )
V_134 = snprintf ( V_26 , 16 , L_12 ,
( int ) sizeof( V_11 -> V_103 . V_152 ) ,
V_11 -> V_103 . V_152 ) ;
return F_56 ( V_134 , 16 ) ;
}
static T_2 F_57 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
return snprintf ( V_26 , V_66 , L_21 ,
F_46 ( V_63 ) -> V_153 ) ;
}
static T_2 F_58 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
return snprintf ( V_26 , V_66 , L_21 ,
F_46 ( V_63 ) -> V_154 ) ;
}
static T_2 F_59 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
const char * V_26 , T_4 V_70 )
{
int V_155 = - V_156 ;
if ( ! F_22 ( V_157 ) )
return V_155 ;
V_155 = F_33 ( (struct V_10 * ) F_46 ( V_63 ) -> V_12 , V_26 [ 0 ] == '!' ) ;
if ( V_155 >= 0 )
V_155 = V_70 ;
return V_155 ;
}
static T_2 F_60 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_134 , V_143 ;
V_143 = F_61 ( V_11 ) ;
if ( ( V_143 == 0 ) && V_11 -> V_100 )
V_143 = - V_158 ;
V_134 = snprintf ( V_26 , V_66 , L_22 , V_143 ) ;
return V_134 ;
}
T_2 F_62 ( struct V_63 * V_63 , char * V_26 )
{
return F_55 ( V_63 , & V_159 , V_26 ) ;
}
static void F_63 ( struct V_10 * V_40 )
{
int V_160 ;
int V_161 ;
F_64 ( V_40 ) ;
if ( V_40 -> V_162 ) {
int V_160 ;
for ( V_160 = 0 ; V_160 < ( V_40 -> V_163 -> V_62 + V_83 ) ; V_160 ++ ) {
struct V_84 * V_84 = & V_40 -> V_85 [ V_160 ] ;
if ( ! ( V_84 -> V_86 -> V_87 . V_88 & F_26 ( V_98 | V_97 ) ) &&
( V_84 -> V_86 -> V_87 . V_88 & F_26 ( V_164 ) ) )
F_65 ( & V_84 -> V_165 ) ;
}
F_66 ( V_40 -> V_166 ) ;
}
F_67 ( V_40 ) ;
V_161 = F_68 ( V_167 ) ;
if ( V_40 -> V_168 -> V_63 == V_169 ||
V_40 -> V_168 -> V_63 == V_170 ||
V_40 -> V_168 -> V_63 == V_171 ||
V_40 -> V_168 -> V_63 == V_172 ) {
if ( V_40 -> V_173 > 1 ) {
for ( V_160 = 0 ; V_160 < V_40 -> V_173 ; V_160 ++ ) {
if ( F_69 (
V_40 -> V_174 [ V_160 ] . V_175 ,
NULL ) ) {
F_25 ( V_72 L_23 ,
V_40 -> V_15 ,
V_40 -> V_115 ,
V_161 ) ;
}
V_161 = F_70 ( V_161 ,
V_167 ) ;
F_71 ( V_40 -> V_174 [ V_160 ] . V_175 ,
& ( V_40 -> V_176 [ V_160 ] ) ) ;
}
} else {
F_71 ( V_40 -> V_168 -> V_177 ,
& ( V_40 -> V_176 [ 0 ] ) ) ;
}
} else {
F_71 ( V_40 -> V_168 -> V_177 , V_40 ) ;
}
if ( V_40 -> V_142 )
F_72 ( V_40 -> V_168 ) ;
else if ( V_40 -> V_173 > 1 )
F_73 ( V_40 -> V_168 ) ;
}
static void F_74 ( void )
{
V_178 = F_75 ( 0 , L_24 , & V_179 ) ;
if ( V_178 < 0 ) {
F_76 ( L_25 ) ;
}
}
static int F_77 ( struct V_180 * V_168 , const struct V_181 * V_115 )
{
unsigned V_182 = V_115 -> V_183 ;
struct V_1 * V_2 ;
struct V_10 * V_40 ;
struct V_184 * V_185 = & V_186 ;
int error = - V_113 ;
int V_187 = 0 ;
T_5 V_188 ;
extern int V_189 ;
if ( V_168 -> V_63 == V_170 )
V_168 -> V_190 = 1 ;
F_30 (aac, &aac_devices, entry) {
if ( V_40 -> V_115 > V_187 )
break;
V_185 = & V_40 -> V_34 ;
V_187 ++ ;
}
F_78 ( V_168 , V_191 | V_192 |
V_193 ) ;
error = F_79 ( V_168 ) ;
if ( error )
goto V_194;
error = - V_113 ;
if ( V_13 [ V_182 ] . V_195 & V_196 )
V_188 = F_80 ( 31 ) ;
else
V_188 = F_80 ( 32 ) ;
if ( F_81 ( V_168 , V_188 ) ||
F_82 ( V_168 , V_188 ) )
goto V_197;
F_83 ( V_168 ) ;
V_2 = F_84 ( & V_198 , sizeof( struct V_10 ) ) ;
if ( ! V_2 )
goto V_197;
V_2 -> V_177 = V_168 -> V_177 ;
V_2 -> V_187 = V_187 ;
V_2 -> V_199 = 16 ;
V_2 -> V_200 = 1 ;
if ( V_178 == V_201 )
F_74 () ;
V_40 = (struct V_10 * ) V_2 -> V_12 ;
V_40 -> V_202 = F_85 ( V_168 , 0 ) ;
V_40 -> V_163 = V_2 ;
V_40 -> V_168 = V_168 ;
V_40 -> V_15 = V_198 . V_15 ;
V_40 -> V_115 = V_2 -> V_187 ;
V_40 -> V_14 = V_182 ;
F_86 ( & V_40 -> V_34 ) ;
V_40 -> V_85 = F_87 ( sizeof( struct V_84 ) * ( V_2 -> V_62 + V_83 ) , V_203 ) ;
if ( ! V_40 -> V_85 )
goto V_204;
F_88 ( & V_40 -> V_205 ) ;
F_89 ( & V_40 -> V_206 ) ;
V_40 -> V_207 = V_208 ;
if ( ( * V_13 [ V_182 ] . V_209 ) ( V_40 ) )
goto V_210;
if ( V_40 -> V_211 ) {
if ( V_189 )
F_25 ( V_212 L_26
L_27
L_28 ,
V_40 -> V_15 ,
V_40 -> V_115 ) ;
else
F_25 ( V_212 L_29
L_30
L_31 ,
V_40 -> V_15 ,
V_40 -> V_115 ) ;
}
V_40 -> V_166 = F_90 ( V_213 , V_40 , V_73 ) ;
if ( F_91 ( V_40 -> V_166 ) ) {
F_25 ( V_72 L_32 ) ;
error = F_92 ( V_40 -> V_166 ) ;
V_40 -> V_166 = NULL ;
goto V_214;
}
if ( V_13 [ V_182 ] . V_195 & V_196 )
if ( F_81 ( V_168 , F_80 ( 32 ) ) )
goto V_214;
V_40 -> V_215 = V_13 [ V_182 ] . V_216 ;
error = F_93 ( V_40 ) ;
if ( error < 0 )
goto V_214;
if ( ( V_13 [ V_182 ] . V_195 & V_217 ) &&
( V_2 -> V_218 > 34 ) ) {
V_2 -> V_218 = 34 ;
V_2 -> V_219 = ( V_2 -> V_218 * 8 ) + 112 ;
}
if ( ( V_13 [ V_182 ] . V_195 & V_220 ) &&
( V_2 -> V_218 > 17 ) ) {
V_2 -> V_218 = 17 ;
V_2 -> V_219 = ( V_2 -> V_218 * 8 ) + 112 ;
}
error = F_94 ( V_168 ,
( V_40 -> V_144 . V_221 & V_222 ) ?
( V_2 -> V_219 << 9 ) : 65536 ) ;
if ( error )
goto V_214;
if ( V_13 [ V_182 ] . V_195 & V_217 )
V_40 -> V_223 = 1 ;
else
V_40 -> V_223 = 0 ;
if ( V_40 -> V_224 || V_48 || V_40 -> V_42 )
V_2 -> V_153 = V_40 -> V_215 ;
else
V_2 -> V_153 = 0 ;
F_95 ( V_40 , 0 ) ;
F_96 ( V_40 ) ;
F_97 ( & V_40 -> V_34 , V_185 ) ;
V_2 -> V_154 = V_40 -> V_59 ;
if ( V_2 -> V_154 < V_40 -> V_225 )
V_2 -> V_154 = V_40 -> V_225 ;
if ( V_2 -> V_154 < V_226 )
V_2 -> V_154 = V_226 ;
else
V_2 -> V_227 = V_2 -> V_154 ;
V_2 -> V_228 = V_229 ;
F_98 ( V_168 , V_2 ) ;
error = F_99 ( V_2 , & V_168 -> V_11 ) ;
if ( error )
goto V_214;
F_100 ( V_2 ) ;
F_101 ( V_168 ) ;
F_102 ( V_168 ) ;
return 0 ;
V_214:
F_63 ( V_40 ) ;
V_210:
F_103 ( V_40 ) ;
if ( V_40 -> V_230 )
F_104 ( V_40 -> V_168 , V_40 -> V_231 , V_40 -> V_230 ,
V_40 -> V_232 ) ;
F_10 ( V_40 -> V_233 ) ;
F_105 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_85 ) ;
F_10 ( V_40 -> V_60 ) ;
V_204:
F_106 ( V_2 ) ;
V_197:
F_107 ( V_168 ) ;
V_194:
return error ;
}
static void F_108 ( struct V_10 * V_40 )
{
int V_160 ;
F_67 ( V_40 ) ;
if ( V_40 -> V_168 -> V_63 == V_169 ||
V_40 -> V_168 -> V_63 == V_170 ||
V_40 -> V_168 -> V_63 == V_171 ||
V_40 -> V_168 -> V_63 == V_172 ) {
if ( V_40 -> V_173 > 1 ) {
for ( V_160 = 0 ; V_160 < V_40 -> V_173 ; V_160 ++ )
F_71 ( V_40 -> V_174 [ V_160 ] . V_175 ,
& ( V_40 -> V_176 [ V_160 ] ) ) ;
} else {
F_71 ( V_40 -> V_168 -> V_177 , & ( V_40 -> V_176 [ 0 ] ) ) ;
}
} else {
F_71 ( V_40 -> V_168 -> V_177 , V_40 ) ;
}
if ( V_40 -> V_142 )
F_72 ( V_40 -> V_168 ) ;
else if ( V_40 -> V_173 > 1 )
F_73 ( V_40 -> V_168 ) ;
}
static int F_109 ( struct V_10 * V_11 )
{
int V_160 , V_234 ;
int V_235 = V_11 -> V_115 ;
const char * V_15 = V_11 -> V_15 ;
unsigned long V_236 ;
while ( ! ( ( V_236 = F_110 ( V_11 , V_237 . V_238 ) ) & V_239 )
|| V_236 == 0xffffffff )
F_111 ( 20 ) ;
F_67 ( V_11 ) ;
F_112 ( V_11 ) ;
if ( ( V_11 -> V_168 -> V_63 == V_170 ||
V_11 -> V_168 -> V_63 == V_171 ||
V_11 -> V_168 -> V_63 == V_172 ) )
F_113 ( V_11 ) ;
if ( V_11 -> V_240 )
F_114 ( V_11 , V_241 ) ;
if ( ! V_11 -> V_211 && V_11 -> V_240 && V_11 -> V_173 > 1 ) {
for ( V_160 = 0 ; V_160 < V_11 -> V_173 ; V_160 ++ ) {
V_11 -> V_176 [ V_160 ] . V_242 = V_160 ;
V_11 -> V_176 [ V_160 ] . V_11 = V_11 ;
if ( F_115 ( V_11 -> V_174 [ V_160 ] . V_175 ,
V_11 -> V_243 . V_244 ,
0 , L_33 , & ( V_11 -> V_176 [ V_160 ] ) ) ) {
F_25 ( V_72 L_34 ,
V_15 , V_235 , V_160 ) ;
for ( V_234 = 0 ; V_234 < V_160 ; V_234 ++ )
F_71 ( V_11 -> V_174 [ V_234 ] . V_175 ,
& ( V_11 -> V_176 [ V_234 ] ) ) ;
F_73 ( V_11 -> V_168 ) ;
goto V_245;
}
}
} else {
V_11 -> V_176 [ 0 ] . V_242 = 0 ;
V_11 -> V_176 [ 0 ] . V_11 = V_11 ;
if ( F_115 ( V_11 -> V_168 -> V_177 , V_11 -> V_243 . V_244 ,
V_246 , L_33 ,
& ( V_11 -> V_176 [ 0 ] ) ) < 0 ) {
if ( V_11 -> V_142 )
F_72 ( V_11 -> V_168 ) ;
F_25 ( V_72 L_35 ,
V_15 , V_235 ) ;
goto V_245;
}
}
F_112 ( V_11 ) ;
F_116 ( V_11 ) ;
if ( ! V_11 -> V_211 ) {
F_117 ( V_11 ) ;
V_11 -> V_209 -> V_247 = F_26 ( V_11 -> V_173 ) ;
}
return 0 ;
V_245:
return - 1 ;
}
static int F_118 ( struct V_180 * V_168 , T_6 V_248 )
{
struct V_1 * V_2 = F_119 ( V_168 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_120 ( V_2 ) ;
F_64 ( V_40 ) ;
F_108 ( V_40 ) ;
F_98 ( V_168 , V_2 ) ;
F_102 ( V_168 ) ;
F_107 ( V_168 ) ;
F_121 ( V_168 , F_122 ( V_168 , V_248 ) ) ;
return 0 ;
}
static int F_123 ( struct V_180 * V_168 )
{
struct V_1 * V_2 = F_119 ( V_168 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
int V_5 ;
F_121 ( V_168 , V_249 ) ;
F_124 ( V_168 , V_249 , 0 ) ;
F_125 ( V_168 ) ;
V_5 = F_79 ( V_168 ) ;
if ( V_5 )
goto V_250;
F_83 ( V_168 ) ;
if ( F_109 ( V_40 ) )
goto V_250;
V_40 -> V_251 = 0 ;
F_126 ( V_2 ) ;
return 0 ;
V_250:
F_25 ( V_212 L_36 , V_40 -> V_15 , V_40 -> V_115 ) ;
F_106 ( V_2 ) ;
F_107 ( V_168 ) ;
return - V_113 ;
}
static void F_127 ( struct V_180 * V_11 )
{
struct V_1 * V_2 = F_119 ( V_11 ) ;
F_120 ( V_2 ) ;
F_63 ( (struct V_10 * ) V_2 -> V_12 ) ;
}
static void F_128 ( struct V_180 * V_168 )
{
struct V_1 * V_2 = F_119 ( V_168 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_129 ( V_2 ) ;
F_63 ( V_40 ) ;
F_103 ( V_40 ) ;
F_104 ( V_40 -> V_168 , V_40 -> V_231 , V_40 -> V_230 ,
V_40 -> V_232 ) ;
F_10 ( V_40 -> V_233 ) ;
F_105 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_85 ) ;
F_10 ( V_40 -> V_60 ) ;
F_130 ( & V_40 -> V_34 ) ;
F_106 ( V_2 ) ;
F_107 ( V_168 ) ;
if ( F_131 ( & V_186 ) ) {
F_132 ( V_178 , L_24 ) ;
V_178 = V_201 ;
}
}
static void F_133 ( struct V_10 * V_40 )
{
int V_160 ;
struct V_3 * V_4 ;
for ( V_160 = 0 ; V_160 < V_40 -> V_163 -> V_62 ; V_160 ++ ) {
V_4 = (struct V_3 * ) V_40 -> V_85 [ V_160 ] . V_91 ;
if ( V_4 && ( V_4 -> V_6 . V_7 == V_102 ) ) {
F_134 ( V_4 ) ;
if ( V_40 -> V_252 )
V_4 -> V_253 = V_254 << 16 ;
else
V_4 -> V_253 = V_255 << 16 ;
V_4 -> V_256 ( V_4 ) ;
}
}
}
static T_7 F_135 ( struct V_180 * V_168 ,
enum V_257 error )
{
struct V_1 * V_2 = F_119 ( V_168 ) ;
struct V_10 * V_40 = F_136 ( V_2 ) ;
F_137 ( & V_168 -> V_11 , L_37 , error ) ;
switch ( error ) {
case V_258 :
return V_259 ;
case V_260 :
V_40 -> V_252 = 1 ;
F_120 ( V_40 -> V_163 ) ;
F_133 ( V_40 ) ;
F_108 ( V_40 ) ;
F_138 ( V_168 ) ;
F_105 ( V_40 , 0 ) ;
return V_261 ;
case V_262 :
V_40 -> V_252 = 1 ;
F_133 ( V_40 ) ;
return V_263 ;
}
return V_261 ;
}
static T_7 F_139 ( struct V_180 * V_168 )
{
F_137 ( & V_168 -> V_11 , L_38 ) ;
return V_261 ;
}
static T_7 F_140 ( struct V_180 * V_168 )
{
F_137 ( & V_168 -> V_11 , L_39 ) ;
F_125 ( V_168 ) ;
if ( F_79 ( V_168 ) ) {
F_141 ( & V_168 -> V_11 ,
L_40 ) ;
goto V_250;
}
F_83 ( V_168 ) ;
if ( F_142 ( V_168 ) ) {
F_137 ( & V_168 -> V_11 , L_41 ) ;
goto V_250;
}
return V_264 ;
V_250:
F_137 ( & V_168 -> V_11 , L_42 ) ;
return V_263 ;
}
static void F_143 ( struct V_180 * V_168 )
{
struct V_1 * V_2 = F_119 ( V_168 ) ;
struct V_18 * V_19 = NULL ;
struct V_10 * V_40 = (struct V_10 * ) F_136 ( V_2 ) ;
F_144 ( V_168 ) ;
if ( F_105 ( V_40 , V_40 -> V_207 ) ) {
F_137 ( & V_168 -> V_11 , L_43 ) ;
V_40 -> V_265 = V_266 ;
if ( F_105 ( V_40 , V_208 ) ) {
F_141 ( & V_168 -> V_11 ,
L_44 ) ;
return;
}
}
F_111 ( 10000 ) ;
F_109 ( V_40 ) ;
V_40 -> V_251 = 0 ;
V_40 -> V_252 = 0 ;
F_145 (sdev, shost)
if ( V_19 -> V_267 == V_268 )
V_19 -> V_267 = V_269 ;
F_126 ( V_40 -> V_163 ) ;
F_100 ( V_40 -> V_163 ) ;
F_102 ( V_168 ) ;
F_137 ( & V_168 -> V_11 , L_45 ) ;
}
static int T_8 F_146 ( void )
{
int error ;
F_25 ( V_212 L_46 ,
V_73 , V_270 ) ;
error = F_147 ( & V_271 ) ;
if ( error < 0 )
return error ;
F_74 () ;
return 0 ;
}
static void T_9 F_148 ( void )
{
if ( V_178 > - 1 )
F_132 ( V_178 , L_24 ) ;
F_149 ( & V_271 ) ;
}
