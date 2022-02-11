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
} else
F_16 ( V_19 , 1 ) ;
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
int V_71 ;
struct V_10 * V_40 ;
V_40 = (struct V_10 * ) V_110 -> V_116 ;
if ( ! F_22 ( V_68 ) || V_40 -> V_117 )
return - V_69 ;
F_36 ( & V_114 ) ;
V_71 = F_23 ( V_110 -> V_116 , V_4 , ( void T_3 * ) V_67 ) ;
F_37 ( & V_114 ) ;
return V_71 ;
}
static long F_39 ( struct V_10 * V_11 , unsigned V_4 , unsigned long V_67 )
{
long V_71 ;
F_36 ( & V_114 ) ;
switch ( V_4 ) {
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
case V_128 :
V_71 = F_23 ( V_11 , V_4 , ( void T_3 * ) V_67 ) ;
break;
case V_129 : {
struct V_130 T_3 * V_131 ;
V_131 = F_40 ( sizeof( * V_131 ) ) ;
V_71 = 0 ;
if ( F_41 ( V_131 , sizeof( * V_131 ) ) )
V_71 = - V_132 ;
if ( F_42 ( V_131 , ( void T_3 * ) V_67 , sizeof( struct V_130 ) - sizeof( V_133 ) ) )
V_71 = - V_132 ;
if ( ! V_71 )
V_71 = F_23 ( V_11 , V_4 , V_131 ) ;
break;
}
default:
V_71 = - V_134 ;
break;
}
F_37 ( & V_114 ) ;
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
int V_135 ;
if ( V_11 -> V_103 . V_136 [ 0 ] ) {
char * V_137 = V_11 -> V_103 . V_136 ;
while ( * V_137 && * V_137 != ' ' )
++ V_137 ;
while ( * V_137 == ' ' )
++ V_137 ;
V_135 = snprintf ( V_26 , V_66 , L_8 , V_137 ) ;
} else
V_135 = snprintf ( V_26 , V_66 , L_8 ,
V_13 [ V_11 -> V_14 ] . V_138 ) ;
return V_135 ;
}
static T_2 F_47 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_135 ;
if ( V_11 -> V_103 . V_136 [ 0 ] ) {
char * V_137 = V_11 -> V_103 . V_136 ;
while ( * V_137 && * V_137 != ' ' )
++ V_137 ;
V_135 = snprintf ( V_26 , V_66 , L_12 ,
( int ) ( V_137 - ( char * ) V_11 -> V_103 . V_136 ) ,
V_11 -> V_103 . V_136 ) ;
} else
V_135 = snprintf ( V_26 , V_66 , L_8 ,
V_13 [ V_11 -> V_14 ] . V_139 ) ;
return V_135 ;
}
static T_2 F_48 ( struct V_63 * V_140 ,
struct V_64 * V_65 , char * V_26 )
{
int V_135 = 0 ;
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_140 ) -> V_12 ;
if ( F_49 ( F_6 ( V_141 ) ) )
V_135 = snprintf ( V_26 , V_66 , L_13 ) ;
#ifdef F_50
V_135 += snprintf ( V_26 + V_135 , V_66 - V_135 ,
L_14 ) ;
#endif
if ( V_11 -> V_78 && V_11 -> V_79 )
V_135 += snprintf ( V_26 + V_135 , V_66 - V_135 ,
L_15 ) ;
if ( V_11 -> V_42 )
V_135 += snprintf ( V_26 + V_135 , V_66 - V_135 , L_16 ) ;
if ( V_11 -> V_103 . V_104 &
V_142 )
V_135 += snprintf ( V_26 + V_135 , V_66 - V_135 ,
L_17 ) ;
if ( V_11 -> V_143 )
V_135 += snprintf ( V_26 + V_135 , V_66 - V_135 , L_18 ) ;
return V_135 ;
}
static T_2 F_51 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_135 , V_144 ;
V_144 = F_52 ( V_11 -> V_145 . V_146 ) ;
V_135 = snprintf ( V_26 , V_66 , L_19 ,
V_144 >> 24 , ( V_144 >> 16 ) & 0xff , V_144 & 0xff ,
F_52 ( V_11 -> V_145 . V_147 ) ) ;
return V_135 ;
}
static T_2 F_53 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_135 , V_144 ;
V_144 = F_52 ( V_11 -> V_145 . V_148 ) ;
V_135 = snprintf ( V_26 , V_66 , L_19 ,
V_144 >> 24 , ( V_144 >> 16 ) & 0xff , V_144 & 0xff ,
F_52 ( V_11 -> V_145 . V_149 ) ) ;
return V_135 ;
}
static T_2 F_54 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_135 , V_144 ;
V_144 = F_52 ( V_11 -> V_145 . V_150 ) ;
V_135 = snprintf ( V_26 , V_66 , L_19 ,
V_144 >> 24 , ( V_144 >> 16 ) & 0xff , V_144 & 0xff ,
F_52 ( V_11 -> V_145 . V_151 ) ) ;
return V_135 ;
}
static T_2 F_55 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_135 = 0 ;
if ( F_52 ( V_11 -> V_145 . V_152 [ 0 ] ) != 0xBAD0 )
V_135 = snprintf ( V_26 , 16 , L_20 ,
F_52 ( V_11 -> V_145 . V_152 [ 0 ] ) ) ;
if ( V_135 &&
! memcmp ( & V_11 -> V_103 . V_153 [
sizeof( V_11 -> V_103 . V_153 ) - V_135 ] ,
V_26 , V_135 - 1 ) )
V_135 = snprintf ( V_26 , 16 , L_12 ,
( int ) sizeof( V_11 -> V_103 . V_153 ) ,
V_11 -> V_103 . V_153 ) ;
return F_56 ( V_135 , 16 ) ;
}
static T_2 F_57 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
return snprintf ( V_26 , V_66 , L_21 ,
F_46 ( V_63 ) -> V_154 ) ;
}
static T_2 F_58 ( struct V_63 * V_63 ,
struct V_64 * V_65 , char * V_26 )
{
return snprintf ( V_26 , V_66 , L_21 ,
F_46 ( V_63 ) -> V_155 ) ;
}
static T_2 F_59 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
const char * V_26 , T_4 V_70 )
{
int V_156 = - V_157 ;
if ( ! F_22 ( V_158 ) )
return V_156 ;
V_156 = F_33 ( (struct V_10 * ) F_46 ( V_63 ) -> V_12 , V_26 [ 0 ] == '!' ) ;
if ( V_156 >= 0 )
V_156 = V_70 ;
return V_156 ;
}
static T_2 F_60 ( struct V_63 * V_63 ,
struct V_64 * V_65 ,
char * V_26 )
{
struct V_10 * V_11 = (struct V_10 * ) F_46 ( V_63 ) -> V_12 ;
int V_135 , V_144 ;
V_144 = F_61 ( V_11 ) ;
if ( ( V_144 == 0 ) && V_11 -> V_100 )
V_144 = - V_159 ;
V_135 = snprintf ( V_26 , V_66 , L_22 , V_144 ) ;
return V_135 ;
}
T_2 F_62 ( struct V_63 * V_63 , char * V_26 )
{
return F_55 ( V_63 , & V_160 , V_26 ) ;
}
static void F_63 ( struct V_10 * V_40 )
{
int V_161 ;
int V_162 ;
if ( V_40 -> V_163 ) {
int V_161 ;
for ( V_161 = 0 ; V_161 < ( V_40 -> V_164 -> V_62 + V_83 ) ; V_161 ++ ) {
struct V_84 * V_84 = & V_40 -> V_85 [ V_161 ] ;
if ( ! ( V_84 -> V_86 -> V_87 . V_88 & F_26 ( V_98 | V_97 ) ) &&
( V_84 -> V_86 -> V_87 . V_88 & F_26 ( V_165 ) ) )
F_64 ( & V_84 -> V_166 ) ;
}
F_65 ( V_40 -> V_167 ) ;
}
F_66 ( V_40 ) ;
F_67 ( V_40 ) ;
V_162 = F_68 ( V_168 ) ;
if ( V_40 -> V_169 -> V_63 == V_170 ||
V_40 -> V_169 -> V_63 == V_171 ||
V_40 -> V_169 -> V_63 == V_172 ||
V_40 -> V_169 -> V_63 == V_173 ) {
if ( V_40 -> V_174 > 1 ) {
for ( V_161 = 0 ; V_161 < V_40 -> V_174 ; V_161 ++ ) {
if ( F_69 (
V_40 -> V_175 [ V_161 ] . V_176 ,
NULL ) ) {
F_25 ( V_72 L_23 ,
V_40 -> V_15 ,
V_40 -> V_115 ,
V_162 ) ;
}
V_162 = F_70 ( V_162 ,
V_168 ) ;
F_71 ( V_40 -> V_175 [ V_161 ] . V_176 ,
& ( V_40 -> V_177 [ V_161 ] ) ) ;
}
} else {
F_71 ( V_40 -> V_169 -> V_178 ,
& ( V_40 -> V_177 [ 0 ] ) ) ;
}
} else {
F_71 ( V_40 -> V_169 -> V_178 , V_40 ) ;
}
if ( V_40 -> V_143 )
F_72 ( V_40 -> V_169 ) ;
else if ( V_40 -> V_174 > 1 )
F_73 ( V_40 -> V_169 ) ;
}
static int F_74 ( struct V_179 * V_169 , const struct V_180 * V_115 )
{
unsigned V_181 = V_115 -> V_182 ;
struct V_1 * V_2 ;
struct V_10 * V_40 ;
struct V_183 * V_184 = & V_185 ;
int error = - V_113 ;
int V_186 = 0 ;
T_5 V_187 ;
extern int V_188 ;
F_30 (aac, &aac_devices, entry) {
if ( V_40 -> V_115 > V_186 )
break;
V_184 = & V_40 -> V_34 ;
V_186 ++ ;
}
F_75 ( V_169 , V_189 | V_190 |
V_191 ) ;
error = F_76 ( V_169 ) ;
if ( error )
goto V_192;
error = - V_113 ;
if ( V_13 [ V_181 ] . V_193 & V_194 )
V_187 = F_77 ( 31 ) ;
else
V_187 = F_77 ( 32 ) ;
if ( F_78 ( V_169 , V_187 ) ||
F_79 ( V_169 , V_187 ) )
goto V_195;
F_80 ( V_169 ) ;
V_2 = F_81 ( & V_196 , sizeof( struct V_10 ) ) ;
if ( ! V_2 )
goto V_195;
V_2 -> V_178 = V_169 -> V_178 ;
V_2 -> V_186 = V_186 ;
V_2 -> V_197 = 16 ;
V_2 -> V_198 = 1 ;
V_40 = (struct V_10 * ) V_2 -> V_12 ;
V_40 -> V_199 = F_82 ( V_169 , 0 ) ;
V_40 -> V_164 = V_2 ;
V_40 -> V_169 = V_169 ;
V_40 -> V_15 = V_196 . V_15 ;
V_40 -> V_115 = V_2 -> V_186 ;
V_40 -> V_14 = V_181 ;
F_83 ( & V_40 -> V_34 ) ;
V_40 -> V_85 = F_84 ( sizeof( struct V_84 ) * ( V_2 -> V_62 + V_83 ) , V_200 ) ;
if ( ! V_40 -> V_85 )
goto V_201;
F_85 ( & V_40 -> V_202 ) ;
V_40 -> V_203 = V_204 ;
if ( ( * V_13 [ V_181 ] . V_205 ) ( V_40 ) )
goto V_206;
if ( V_40 -> V_207 ) {
if ( V_188 )
F_25 ( V_208 L_24
L_25
L_26 ,
V_40 -> V_15 ,
V_40 -> V_115 ) ;
else
F_25 ( V_208 L_27
L_28
L_29 ,
V_40 -> V_15 ,
V_40 -> V_115 ) ;
}
V_40 -> V_167 = F_86 ( V_209 , V_40 , V_73 ) ;
if ( F_87 ( V_40 -> V_167 ) ) {
F_25 ( V_72 L_30 ) ;
error = F_88 ( V_40 -> V_167 ) ;
V_40 -> V_167 = NULL ;
goto V_210;
}
if ( V_13 [ V_181 ] . V_193 & V_194 )
if ( F_78 ( V_169 , F_77 ( 32 ) ) )
goto V_210;
V_40 -> V_211 = V_13 [ V_181 ] . V_212 ;
error = F_89 ( V_40 ) ;
if ( error < 0 )
goto V_210;
if ( ( V_13 [ V_181 ] . V_193 & V_213 ) &&
( V_2 -> V_214 > 34 ) ) {
V_2 -> V_214 = 34 ;
V_2 -> V_215 = ( V_2 -> V_214 * 8 ) + 112 ;
}
if ( ( V_13 [ V_181 ] . V_193 & V_216 ) &&
( V_2 -> V_214 > 17 ) ) {
V_2 -> V_214 = 17 ;
V_2 -> V_215 = ( V_2 -> V_214 * 8 ) + 112 ;
}
error = F_90 ( V_169 ,
( V_40 -> V_145 . V_217 & V_218 ) ?
( V_2 -> V_215 << 9 ) : 65536 ) ;
if ( error )
goto V_210;
if ( V_13 [ V_181 ] . V_193 & V_213 )
V_40 -> V_219 = 1 ;
else
V_40 -> V_219 = 0 ;
if ( V_40 -> V_220 || V_48 || V_40 -> V_42 )
V_2 -> V_154 = V_40 -> V_211 ;
else
V_2 -> V_154 = 0 ;
F_91 ( V_40 , 0 ) ;
F_92 ( V_40 ) ;
F_93 ( & V_40 -> V_34 , V_184 ) ;
V_2 -> V_155 = V_40 -> V_59 ;
if ( V_2 -> V_155 < V_40 -> V_221 )
V_2 -> V_155 = V_40 -> V_221 ;
if ( V_2 -> V_155 < V_222 )
V_2 -> V_155 = V_222 ;
else
V_2 -> V_223 = V_2 -> V_155 ;
V_2 -> V_224 = V_225 ;
F_94 ( V_169 , V_2 ) ;
error = F_95 ( V_2 , & V_169 -> V_11 ) ;
if ( error )
goto V_210;
F_96 ( V_2 ) ;
return 0 ;
V_210:
F_63 ( V_40 ) ;
V_206:
F_97 ( V_40 ) ;
if ( V_40 -> V_226 )
F_98 ( V_40 -> V_169 , V_40 -> V_227 , V_40 -> V_226 ,
V_40 -> V_228 ) ;
F_10 ( V_40 -> V_229 ) ;
F_99 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_85 ) ;
F_10 ( V_40 -> V_60 ) ;
V_201:
F_100 ( V_2 ) ;
V_195:
F_101 ( V_169 ) ;
V_192:
return error ;
}
static void F_102 ( struct V_179 * V_11 )
{
struct V_1 * V_2 = F_103 ( V_11 ) ;
F_104 ( V_2 ) ;
F_63 ( (struct V_10 * ) V_2 -> V_12 ) ;
}
static void F_105 ( struct V_179 * V_169 )
{
struct V_1 * V_2 = F_103 ( V_169 ) ;
struct V_10 * V_40 = (struct V_10 * ) V_2 -> V_12 ;
F_106 ( V_2 ) ;
F_63 ( V_40 ) ;
F_97 ( V_40 ) ;
F_98 ( V_40 -> V_169 , V_40 -> V_227 , V_40 -> V_226 ,
V_40 -> V_228 ) ;
F_10 ( V_40 -> V_229 ) ;
F_99 ( V_40 , 0 ) ;
F_10 ( V_40 -> V_85 ) ;
F_10 ( V_40 -> V_60 ) ;
F_107 ( & V_40 -> V_34 ) ;
F_100 ( V_2 ) ;
F_101 ( V_169 ) ;
if ( F_108 ( & V_185 ) ) {
F_109 ( V_230 , L_31 ) ;
V_230 = - 1 ;
}
}
static int T_6 F_110 ( void )
{
int error ;
F_25 ( V_208 L_32 ,
V_73 , V_231 ) ;
error = F_111 ( & V_232 ) ;
if ( error < 0 )
return error ;
V_230 = F_112 ( 0 , L_31 , & V_233 ) ;
if ( V_230 < 0 ) {
F_25 ( V_234
L_33 ) ;
}
return 0 ;
}
static void T_7 F_113 ( void )
{
if ( V_230 > - 1 )
F_109 ( V_230 , L_31 ) ;
F_114 ( & V_232 ) ;
}
