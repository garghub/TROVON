struct V_1 * F_1 ( int V_2 )
{
return & V_3 [ V_2 ] ;
}
static int F_2 ( struct V_4 * V_5 , struct V_6 * V_7 ,
T_1 V_8 , int * V_9 )
{
struct V_10 * V_11 = (struct V_10 * ) V_9 ;
unsigned char * V_12 ;
F_3 ( ( V_13 L_1 ) ) ;
if ( V_8 >= 2 * 1024 * 1024 ) {
if( V_8 >= 4 * 1024 * 1024 ) {
V_11 -> V_14 = 255 ;
V_11 -> V_15 = 63 ;
} else {
V_11 -> V_14 = 128 ;
V_11 -> V_15 = 32 ;
}
} else {
V_11 -> V_14 = 64 ;
V_11 -> V_15 = 32 ;
}
V_11 -> V_16 = F_4 ( V_8 , V_11 -> V_14 * V_11 -> V_15 ) ;
V_12 = F_5 ( V_7 ) ;
if ( ! V_12 )
return 0 ;
if( * ( V_17 * ) ( V_12 + 0x40 ) == F_6 ( 0xaa55 ) ) {
struct V_18 * V_19 = (struct V_18 * ) V_12 ;
struct V_18 * V_20 = V_19 ;
int V_21 = V_11 -> V_16 ;
int V_22 ;
unsigned char V_23 , V_24 ;
for( V_22 = 0 ; V_22 < 4 ; V_22 ++ ) {
V_23 = V_20 -> V_23 ;
V_24 = V_20 -> V_25 & 0x3f ;
if( V_23 == 63 ) {
V_11 -> V_14 = 64 ;
V_11 -> V_15 = 32 ;
break;
} else if( V_23 == 127 ) {
V_11 -> V_14 = 128 ;
V_11 -> V_15 = 32 ;
break;
} else if( V_23 == 254 ) {
V_11 -> V_14 = 255 ;
V_11 -> V_15 = 63 ;
break;
}
V_20 ++ ;
}
if ( V_22 == 4 ) {
V_23 = V_19 -> V_23 ;
V_24 = V_19 -> V_25 & 0x3f ;
}
V_11 -> V_16 = F_4 ( V_8 , V_11 -> V_14 * V_11 -> V_15 ) ;
if ( V_22 < 4 && V_24 == V_11 -> V_15 ) {
if ( V_11 -> V_16 != V_21 )
F_3 ( ( V_13 L_2 ,
V_11 -> V_14 , V_11 -> V_15 , V_22 ) ) ;
} else if ( V_23 > 0 || V_24 > 0 ) {
F_3 ( ( V_13 L_3 ,
V_23 + 1 , V_24 , V_22 ) ) ;
F_3 ( ( V_13 L_4 ,
V_11 -> V_14 , V_11 -> V_15 ) ) ;
}
}
F_7 ( V_12 ) ;
return 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_26 * V_27 = (struct V_26 * ) V_5 -> V_28 -> V_29 ;
if ( V_27 -> V_30 && ( V_5 -> type == V_31 ) )
V_5 -> V_32 = 1 ;
if ( ( V_5 -> type == V_31 ) &&
( F_9 ( V_5 ) != V_33 ) &&
( ! V_27 -> V_30 || V_5 -> V_34 ) &&
( ! V_27 -> V_35 || ( F_9 ( V_5 ) != 2 ) ) ) {
if ( V_36 == 0 )
return - V_37 ;
if ( V_36 < 0 )
V_5 -> V_38 = 1 ;
}
if ( V_5 -> V_39 && ( V_5 -> type == V_31 ) &&
( ! V_27 -> V_35 || ( F_9 ( V_5 ) != 2 ) ) &&
! V_5 -> V_38 ) {
struct V_4 * V_40 ;
struct V_41 * V_28 = V_5 -> V_28 ;
unsigned V_42 = 0 ;
unsigned V_43 = 0 ;
unsigned V_44 ;
unsigned V_45 ;
if ( V_5 -> V_46 -> V_47 < ( 45 * V_48 ) )
F_10 ( V_5 -> V_46 , 45 * V_48 ) ;
for ( V_45 = 0 ; V_45 < V_27 -> V_49 ; ++ V_45 )
if ( V_27 -> V_50 [ V_45 ] . V_51 )
++ V_42 ;
F_11 (dev, host) {
if ( V_40 -> V_39 && ( V_40 -> type == V_31 ) &&
( ! V_27 -> V_35 ||
( F_9 ( V_5 ) != 2 ) ) &&
! V_40 -> V_38 ) {
if ( ( F_9 ( V_40 ) != V_33 )
|| ! V_27 -> V_50 [ F_12 ( V_40 ) ] . V_51 )
++ V_42 ;
} else
++ V_43 ;
}
if ( V_42 == 0 )
++ V_42 ;
V_44 = ( V_28 -> V_52 - V_43 ) / V_42 ;
if ( V_44 > 256 )
V_44 = 256 ;
else if ( V_44 < 2 )
V_44 = 2 ;
F_13 ( V_5 , V_53 , V_44 ) ;
} else
F_13 ( V_5 , 0 , 1 ) ;
return 0 ;
}
static int F_14 ( struct V_4 * V_5 , int V_44 ,
int V_54 )
{
if ( V_54 != V_55 )
return - V_56 ;
if ( V_5 -> V_39 && ( V_5 -> type == V_31 ) &&
( F_9 ( V_5 ) == V_33 ) ) {
struct V_4 * V_40 ;
struct V_41 * V_28 = V_5 -> V_28 ;
unsigned V_22 = 0 ;
F_11 (dev, host) {
if ( V_40 -> V_39 && ( V_40 -> type == V_31 ) &&
( F_9 ( V_40 ) == V_33 ) )
++ V_22 ;
++ V_22 ;
}
if ( V_22 >= V_28 -> V_52 )
V_22 = V_28 -> V_52 - 1 ;
if ( V_44 > ( V_28 -> V_52 - V_22 ) )
V_44 = V_28 -> V_52 - V_22 ;
if ( V_44 > 256 )
V_44 = 256 ;
else if ( V_44 < 2 )
V_44 = 2 ;
F_13 ( V_5 , V_53 , V_44 ) ;
} else
F_13 ( V_5 , 0 , 1 ) ;
return V_5 -> V_57 ;
}
static T_2 F_15 ( struct V_58 * V_40 , struct V_59 * V_60 , char * V_12 )
{
struct V_4 * V_5 = F_16 ( V_40 ) ;
struct V_26 * V_27 = (struct V_26 * ) ( V_5 -> V_28 -> V_29 ) ;
if ( F_9 ( V_5 ) != V_33 )
return snprintf ( V_12 , V_61 , V_5 -> V_38
? L_5 :
( ( V_27 -> V_30 && ( V_5 -> type == V_31 ) ) ? L_6 : L_7 ) ) ;
return snprintf ( V_12 , V_61 , L_8 ,
F_17 ( V_27 -> V_50 [ F_12 ( V_5 ) ] . type ) ) ;
}
static int F_18 ( struct V_4 * V_5 , int V_62 , void T_3 * V_63 )
{
struct V_26 * V_40 = (struct V_26 * ) V_5 -> V_28 -> V_29 ;
if ( ! F_19 ( V_64 ) )
return - V_65 ;
return F_20 ( V_40 , V_62 , V_63 ) ;
}
static int F_21 ( struct V_66 * V_62 )
{
struct V_4 * V_40 = V_62 -> V_58 ;
struct V_41 * V_28 = V_40 -> V_28 ;
struct V_26 * V_27 = (struct V_26 * ) V_28 -> V_29 ;
int V_67 ;
int V_68 = V_69 ;
F_22 ( V_70 L_9 ,
V_71 ,
V_28 -> V_72 , F_9 ( V_40 ) , F_12 ( V_40 ) , V_40 -> V_73 ) ;
switch ( V_62 -> V_74 [ 0 ] ) {
case V_75 :
if ( ! ( V_27 -> V_76 ) ||
! ( V_27 -> V_77 ) ||
( ( V_62 -> V_74 [ 1 ] & 0x1f ) != V_78 ) )
break;
case V_79 :
case V_80 :
for ( V_67 = 0 ; V_67 < ( V_28 -> V_52 + V_81 ) ; ++ V_67 ) {
struct V_82 * V_82 = & V_27 -> V_83 [ V_67 ] ;
if ( V_82 -> V_84 -> V_85 . V_86 &&
( V_82 -> V_87 & V_88 ) &&
( V_82 -> V_89 == V_62 ) ) {
V_82 -> V_87 |= V_90 ;
V_62 -> V_91 . V_92 = V_93 ;
V_68 = V_94 ;
}
}
break;
case V_95 :
for ( V_67 = 0 ; V_67 < ( V_28 -> V_52 + V_81 ) ; ++ V_67 ) {
struct V_66 * V_96 ;
struct V_82 * V_82 = & V_27 -> V_83 [ V_67 ] ;
if ( ( V_82 -> V_84 -> V_85 . V_86 & F_23 ( V_97 | V_98 ) ) &&
( V_82 -> V_87 & V_88 ) &&
( ( V_96 = V_82 -> V_89 ) ) &&
( V_96 -> V_58 == V_62 -> V_58 ) ) {
V_82 -> V_87 |= V_90 ;
V_96 -> V_91 . V_92 = V_93 ;
if ( V_96 == V_62 )
V_68 = V_94 ;
}
}
}
return V_68 ;
}
static int F_24 ( struct V_66 * V_62 )
{
struct V_4 * V_40 = V_62 -> V_58 ;
struct V_41 * V_28 = V_40 -> V_28 ;
struct V_66 * V_96 ;
int V_67 ;
struct V_26 * V_27 = (struct V_26 * ) V_28 -> V_29 ;
unsigned long V_87 ;
for ( V_67 = 0 ; V_67 < ( V_28 -> V_52 + V_81 ) ; ++ V_67 ) {
struct V_82 * V_82 = & V_27 -> V_83 [ V_67 ] ;
if ( V_82 -> V_84 -> V_85 . V_86 &&
( V_82 -> V_87 & V_88 ) &&
( V_82 -> V_89 == V_62 ) ) {
V_82 -> V_87 |= V_90 ;
V_62 -> V_91 . V_92 = V_93 ;
}
}
F_22 ( V_70 L_10 ,
V_71 ) ;
if ( ( V_67 = F_25 ( V_27 ) ) )
return V_67 ;
for ( V_67 = 60 ; V_67 ; -- V_67 ) {
int V_99 = V_27 -> V_100 ;
if ( V_99 == 0 )
F_11 (dev, host) {
F_26 ( & V_40 -> V_101 , V_87 ) ;
F_27 (command, &dev->cmd_list, list) {
if ( ( V_96 != V_62 ) &&
( V_96 -> V_91 . V_92 == V_102 ) ) {
V_99 ++ ;
break;
}
}
F_28 ( & V_40 -> V_101 , V_87 ) ;
if ( V_99 )
break;
}
if ( V_99 == 0 )
return V_94 ;
F_29 ( 1 ) ;
}
F_22 ( V_70 L_11 , V_71 ) ;
if ( ( ( V_27 -> V_103 . V_104 &
V_105 ) ||
( V_27 -> V_103 . V_104 &
V_106 ) ) &&
V_107 &&
( ( V_107 != 1 ) ||
! ( V_27 -> V_103 . V_104 &
V_108 ) ) )
F_30 ( V_27 , 2 ) ;
return V_94 ;
}
static int F_31 ( struct V_109 * V_109 , struct V_110 * V_110 )
{
struct V_26 * V_27 ;
unsigned V_111 = F_32 ( V_109 ) ;
int V_112 = - V_113 ;
F_33 ( & V_114 ) ;
F_27 (aac, &aac_devices, entry) {
if ( V_27 -> V_115 == V_111 ) {
V_110 -> V_116 = V_27 ;
V_112 = 0 ;
break;
}
}
F_34 ( & V_114 ) ;
return V_112 ;
}
static long F_35 ( struct V_110 * V_110 ,
unsigned int V_62 , unsigned long V_63 )
{
int V_68 ;
if ( ! F_19 ( V_64 ) )
return - V_65 ;
F_33 ( & V_114 ) ;
V_68 = F_20 ( V_110 -> V_116 , V_62 , ( void T_3 * ) V_63 ) ;
F_34 ( & V_114 ) ;
return V_68 ;
}
static long F_36 ( struct V_26 * V_40 , unsigned V_62 , unsigned long V_63 )
{
long V_68 ;
F_33 ( & V_114 ) ;
switch ( V_62 ) {
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
V_68 = F_20 ( V_40 , V_62 , ( void T_3 * ) V_63 ) ;
break;
case V_128 : {
struct V_129 T_3 * V_130 ;
V_130 = F_37 ( sizeof( * V_130 ) ) ;
V_68 = 0 ;
if ( F_38 ( V_130 , sizeof( * V_130 ) ) )
V_68 = - V_131 ;
if ( F_39 ( V_130 , ( void T_3 * ) V_63 , sizeof( struct V_129 ) - sizeof( V_132 ) ) )
V_68 = - V_131 ;
if ( ! V_68 )
V_68 = F_20 ( V_40 , V_62 , V_130 ) ;
break;
}
default:
V_68 = - V_133 ;
break;
}
F_34 ( & V_114 ) ;
return V_68 ;
}
static int F_40 ( struct V_4 * V_5 , int V_62 , void T_3 * V_63 )
{
struct V_26 * V_40 = (struct V_26 * ) V_5 -> V_28 -> V_29 ;
return F_36 ( V_40 , V_62 , ( unsigned long ) V_63 ) ;
}
static long F_41 ( struct V_110 * V_110 , unsigned V_62 , unsigned long V_63 )
{
if ( ! F_19 ( V_64 ) )
return - V_65 ;
return F_36 ( V_110 -> V_116 , V_62 , V_63 ) ;
}
static T_2 F_42 ( struct V_58 * V_58 ,
struct V_59 * V_60 , char * V_12 )
{
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_58 ) -> V_29 ;
int V_134 ;
if ( V_40 -> V_103 . V_135 [ 0 ] ) {
char * V_136 = V_40 -> V_103 . V_135 ;
while ( * V_136 && * V_136 != ' ' )
++ V_136 ;
while ( * V_136 == ' ' )
++ V_136 ;
V_134 = snprintf ( V_12 , V_61 , L_8 , V_136 ) ;
} else
V_134 = snprintf ( V_12 , V_61 , L_8 ,
V_3 [ V_40 -> V_137 ] . V_138 ) ;
return V_134 ;
}
static T_2 F_44 ( struct V_58 * V_58 ,
struct V_59 * V_60 , char * V_12 )
{
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_58 ) -> V_29 ;
int V_134 ;
if ( V_40 -> V_103 . V_135 [ 0 ] ) {
char * V_136 = V_40 -> V_103 . V_135 ;
while ( * V_136 && * V_136 != ' ' )
++ V_136 ;
V_134 = snprintf ( V_12 , V_61 , L_12 ,
( int ) ( V_136 - ( char * ) V_40 -> V_103 . V_135 ) ,
V_40 -> V_103 . V_135 ) ;
} else
V_134 = snprintf ( V_12 , V_61 , L_8 ,
V_3 [ V_40 -> V_137 ] . V_139 ) ;
return V_134 ;
}
static T_2 F_45 ( struct V_58 * V_140 ,
struct V_59 * V_60 , char * V_12 )
{
int V_134 = 0 ;
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_140 ) -> V_29 ;
if ( F_46 ( F_3 ( V_141 ) ) )
V_134 = snprintf ( V_12 , V_61 , L_13 ) ;
#ifdef F_47
V_134 += snprintf ( V_12 + V_134 , V_61 - V_134 ,
L_14 ) ;
#endif
if ( V_40 -> V_76 && V_40 -> V_77 )
V_134 += snprintf ( V_12 + V_134 , V_61 - V_134 ,
L_15 ) ;
if ( V_40 -> V_30 )
V_134 += snprintf ( V_12 + V_134 , V_61 - V_134 , L_16 ) ;
if ( V_40 -> V_103 . V_104 &
V_142 )
V_134 += snprintf ( V_12 + V_134 , V_61 - V_134 ,
L_17 ) ;
if ( V_40 -> V_143 )
V_134 += snprintf ( V_12 + V_134 , V_61 - V_134 , L_18 ) ;
return V_134 ;
}
static T_2 F_48 ( struct V_58 * V_58 ,
struct V_59 * V_60 ,
char * V_12 )
{
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_58 ) -> V_29 ;
int V_134 , V_144 ;
V_144 = F_49 ( V_40 -> V_145 . V_146 ) ;
V_134 = snprintf ( V_12 , V_61 , L_19 ,
V_144 >> 24 , ( V_144 >> 16 ) & 0xff , V_144 & 0xff ,
F_49 ( V_40 -> V_145 . V_147 ) ) ;
return V_134 ;
}
static T_2 F_50 ( struct V_58 * V_58 ,
struct V_59 * V_60 ,
char * V_12 )
{
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_58 ) -> V_29 ;
int V_134 , V_144 ;
V_144 = F_49 ( V_40 -> V_145 . V_148 ) ;
V_134 = snprintf ( V_12 , V_61 , L_19 ,
V_144 >> 24 , ( V_144 >> 16 ) & 0xff , V_144 & 0xff ,
F_49 ( V_40 -> V_145 . V_149 ) ) ;
return V_134 ;
}
static T_2 F_51 ( struct V_58 * V_58 ,
struct V_59 * V_60 ,
char * V_12 )
{
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_58 ) -> V_29 ;
int V_134 , V_144 ;
V_144 = F_49 ( V_40 -> V_145 . V_150 ) ;
V_134 = snprintf ( V_12 , V_61 , L_19 ,
V_144 >> 24 , ( V_144 >> 16 ) & 0xff , V_144 & 0xff ,
F_49 ( V_40 -> V_145 . V_151 ) ) ;
return V_134 ;
}
static T_2 F_52 ( struct V_58 * V_58 ,
struct V_59 * V_60 , char * V_12 )
{
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_58 ) -> V_29 ;
int V_134 = 0 ;
if ( F_49 ( V_40 -> V_145 . V_152 [ 0 ] ) != 0xBAD0 )
V_134 = snprintf ( V_12 , 16 , L_20 ,
F_49 ( V_40 -> V_145 . V_152 [ 0 ] ) ) ;
if ( V_134 &&
! memcmp ( & V_40 -> V_103 . V_153 [
sizeof( V_40 -> V_103 . V_153 ) - V_134 ] ,
V_12 , V_134 - 1 ) )
V_134 = snprintf ( V_12 , 16 , L_12 ,
( int ) sizeof( V_40 -> V_103 . V_153 ) ,
V_40 -> V_103 . V_153 ) ;
return F_53 ( V_134 , 16 ) ;
}
static T_2 F_54 ( struct V_58 * V_58 ,
struct V_59 * V_60 , char * V_12 )
{
return snprintf ( V_12 , V_61 , L_21 ,
F_43 ( V_58 ) -> V_154 ) ;
}
static T_2 F_55 ( struct V_58 * V_58 ,
struct V_59 * V_60 , char * V_12 )
{
return snprintf ( V_12 , V_61 , L_21 ,
F_43 ( V_58 ) -> V_155 ) ;
}
static T_2 F_56 ( struct V_58 * V_58 ,
struct V_59 * V_60 ,
const char * V_12 , T_4 V_67 )
{
int V_156 = - V_157 ;
if ( ! F_19 ( V_158 ) )
return V_156 ;
V_156 = F_30 ( (struct V_26 * ) F_43 ( V_58 ) -> V_29 , V_12 [ 0 ] == '!' ) ;
if ( V_156 >= 0 )
V_156 = V_67 ;
return V_156 ;
}
static T_2 F_57 ( struct V_58 * V_58 ,
struct V_59 * V_60 ,
char * V_12 )
{
struct V_26 * V_40 = (struct V_26 * ) F_43 ( V_58 ) -> V_29 ;
int V_134 , V_144 ;
V_144 = F_58 ( V_40 ) ;
if ( ( V_144 == 0 ) && V_40 -> V_100 )
V_144 = - V_159 ;
V_134 = snprintf ( V_12 , V_61 , L_22 , V_144 ) ;
return V_134 ;
}
T_2 F_59 ( struct V_58 * V_58 , char * V_12 )
{
return F_52 ( V_58 , & V_160 , V_12 ) ;
}
static void F_60 ( struct V_26 * V_27 )
{
if ( V_27 -> V_161 )
F_61 ( V_27 -> V_162 ) ;
F_62 ( V_27 ) ;
F_63 ( V_27 ) ;
F_64 ( V_27 -> V_163 -> V_164 , V_27 ) ;
if ( V_27 -> V_143 )
F_65 ( V_27 -> V_163 ) ;
}
static int T_5 F_66 ( struct V_165 * V_163 ,
const struct V_166 * V_115 )
{
unsigned V_167 = V_115 -> V_168 ;
struct V_41 * V_169 ;
struct V_26 * V_27 ;
struct V_170 * V_171 = & V_172 ;
int error = - V_113 ;
int V_173 = 0 ;
T_6 V_174 ;
F_27 (aac, &aac_devices, entry) {
if ( V_27 -> V_115 > V_173 )
break;
V_171 = & V_27 -> V_20 ;
V_173 ++ ;
}
F_67 ( V_163 , V_175 | V_176 |
V_177 ) ;
error = F_68 ( V_163 ) ;
if ( error )
goto V_178;
error = - V_113 ;
if ( V_3 [ V_167 ] . V_179 & V_180 )
V_174 = F_69 ( 31 ) ;
else
V_174 = F_69 ( 32 ) ;
if ( F_70 ( V_163 , V_174 ) ||
F_71 ( V_163 , V_174 ) )
goto V_181;
F_72 ( V_163 ) ;
V_169 = F_73 ( & V_182 , sizeof( struct V_26 ) ) ;
if ( ! V_169 )
goto V_181;
V_169 -> V_164 = V_163 -> V_164 ;
V_169 -> V_183 = F_74 ( V_163 , 0 ) ;
V_169 -> V_173 = V_173 ;
V_169 -> V_184 = 16 ;
V_27 = (struct V_26 * ) V_169 -> V_29 ;
V_27 -> V_185 = V_169 ;
V_27 -> V_163 = V_163 ;
V_27 -> V_186 = V_182 . V_186 ;
V_27 -> V_115 = V_169 -> V_173 ;
V_27 -> V_137 = V_167 ;
F_75 ( & V_27 -> V_20 ) ;
V_27 -> V_83 = F_76 ( sizeof( struct V_82 ) * ( V_169 -> V_52 + V_81 ) , V_187 ) ;
if ( ! V_27 -> V_83 )
goto V_188;
F_77 ( & V_27 -> V_189 ) ;
V_27 -> V_190 = V_191 ;
if ( ( * V_3 [ V_167 ] . V_192 ) ( V_27 ) )
goto V_193;
V_27 -> V_162 = F_78 ( V_194 , V_27 , V_71 ) ;
if ( F_79 ( V_27 -> V_162 ) ) {
F_22 ( V_70 L_23 ) ;
error = F_80 ( V_27 -> V_162 ) ;
goto V_195;
}
if ( V_3 [ V_167 ] . V_179 & V_180 )
if ( F_70 ( V_163 , F_69 ( 32 ) ) )
goto V_195;
V_27 -> V_196 = V_3 [ V_167 ] . V_197 ;
error = F_81 ( V_27 ) ;
if ( error < 0 )
goto V_195;
if ( ( V_3 [ V_167 ] . V_179 & V_198 ) &&
( V_169 -> V_199 > 34 ) ) {
V_169 -> V_199 = 34 ;
V_169 -> V_200 = ( V_169 -> V_199 * 8 ) + 112 ;
}
if ( ( V_3 [ V_167 ] . V_179 & V_201 ) &&
( V_169 -> V_199 > 17 ) ) {
V_169 -> V_199 = 17 ;
V_169 -> V_200 = ( V_169 -> V_199 * 8 ) + 112 ;
}
error = F_82 ( V_163 ,
( V_27 -> V_145 . V_202 & V_203 ) ?
( V_169 -> V_200 << 9 ) : 65536 ) ;
if ( error )
goto V_195;
if ( V_3 [ V_167 ] . V_179 & V_198 )
V_27 -> V_204 = 1 ;
else
V_27 -> V_204 = 0 ;
if ( V_27 -> V_205 || V_36 || V_27 -> V_30 )
V_169 -> V_154 = V_27 -> V_196 ;
else
V_169 -> V_154 = 0 ;
F_83 ( V_27 , 0 ) ;
F_84 ( V_27 ) ;
F_85 ( & V_27 -> V_20 , V_171 ) ;
V_169 -> V_155 = V_27 -> V_49 ;
if ( V_169 -> V_155 < V_27 -> V_206 )
V_169 -> V_155 = V_27 -> V_206 ;
if ( V_169 -> V_155 < V_207 )
V_169 -> V_155 = V_207 ;
else
V_169 -> V_208 = V_169 -> V_155 ;
V_169 -> V_209 = V_210 ;
F_86 ( V_163 , V_169 ) ;
error = F_87 ( V_169 , & V_163 -> V_40 ) ;
if ( error )
goto V_195;
F_88 ( V_169 ) ;
return 0 ;
V_195:
F_60 ( V_27 ) ;
V_193:
F_89 ( V_27 ) ;
if ( V_27 -> V_211 )
F_90 ( V_27 -> V_163 , V_27 -> V_212 , V_27 -> V_211 ,
V_27 -> V_213 ) ;
F_7 ( V_27 -> V_214 ) ;
F_91 ( V_27 , 0 ) ;
F_7 ( V_27 -> V_83 ) ;
F_7 ( V_27 -> V_50 ) ;
V_188:
F_92 ( V_169 ) ;
V_181:
F_93 ( V_163 ) ;
V_178:
return error ;
}
static void F_94 ( struct V_165 * V_40 )
{
struct V_41 * V_169 = F_95 ( V_40 ) ;
F_96 ( V_169 ) ;
F_60 ( (struct V_26 * ) V_169 -> V_29 ) ;
}
static void T_7 F_97 ( struct V_165 * V_163 )
{
struct V_41 * V_169 = F_95 ( V_163 ) ;
struct V_26 * V_27 = (struct V_26 * ) V_169 -> V_29 ;
F_98 ( V_169 ) ;
F_60 ( V_27 ) ;
F_89 ( V_27 ) ;
F_90 ( V_27 -> V_163 , V_27 -> V_212 , V_27 -> V_211 ,
V_27 -> V_213 ) ;
F_7 ( V_27 -> V_214 ) ;
F_91 ( V_27 , 0 ) ;
F_7 ( V_27 -> V_83 ) ;
F_7 ( V_27 -> V_50 ) ;
F_99 ( & V_27 -> V_20 ) ;
F_92 ( V_169 ) ;
F_93 ( V_163 ) ;
if ( F_100 ( & V_172 ) ) {
F_101 ( V_215 , L_24 ) ;
V_215 = - 1 ;
}
}
static int T_8 F_102 ( void )
{
int error ;
F_22 ( V_216 L_25 ,
V_71 , V_217 ) ;
error = F_103 ( & V_218 ) ;
if ( error < 0 )
return error ;
V_215 = F_104 ( 0 , L_24 , & V_219 ) ;
if ( V_215 < 0 ) {
F_22 ( V_220
L_26 ) ;
}
return 0 ;
}
static void T_9 F_105 ( void )
{
if ( V_215 > - 1 )
F_101 ( V_215 , L_24 ) ;
F_106 ( & V_218 ) ;
}
