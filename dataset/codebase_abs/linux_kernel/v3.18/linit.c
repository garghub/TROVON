static int F_1 ( struct V_1 * V_2 , void (* F_2)( struct V_1 * ) )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_4 ;
struct V_6 * V_7 = (struct V_6 * ) V_4 -> V_8 ;
T_1 V_9 = 0 ;
V_2 -> V_10 = F_2 ;
for (; V_9 < ( V_4 -> V_11 + V_12 ) ; ++ V_9 ) {
struct V_13 * V_13 = & V_7 -> V_14 [ V_9 ] ;
struct V_1 * V_15 ;
if ( V_13 -> V_16 -> V_17 . V_18 &&
( ( V_15 = V_13 -> V_19 ) ) &&
( V_15 == V_2 ) &&
( V_2 -> V_20 . V_21 == V_22 ) )
return 0 ;
}
V_2 -> V_20 . V_21 = V_23 ;
return ( F_3 ( V_2 ) ? V_24 : 0 ) ;
}
struct V_25 * F_4 ( int V_26 )
{
return & V_27 [ V_26 ] ;
}
static int F_5 ( struct V_28 * V_29 , struct V_30 * V_31 ,
T_2 V_32 , int * V_33 )
{
struct V_34 * V_35 = (struct V_34 * ) V_33 ;
unsigned char * V_36 ;
F_6 ( ( V_37 L_1 ) ) ;
if ( V_32 >= 2 * 1024 * 1024 ) {
if( V_32 >= 4 * 1024 * 1024 ) {
V_35 -> V_38 = 255 ;
V_35 -> V_39 = 63 ;
} else {
V_35 -> V_38 = 128 ;
V_35 -> V_39 = 32 ;
}
} else {
V_35 -> V_38 = 64 ;
V_35 -> V_39 = 32 ;
}
V_35 -> V_40 = F_7 ( V_32 , V_35 -> V_38 * V_35 -> V_39 ) ;
V_36 = F_8 ( V_31 ) ;
if ( ! V_36 )
return 0 ;
if( * ( V_41 * ) ( V_36 + 0x40 ) == F_9 ( 0xaa55 ) ) {
struct V_42 * V_43 = (struct V_42 * ) V_36 ;
struct V_42 * V_44 = V_43 ;
int V_45 = V_35 -> V_40 ;
int V_46 ;
unsigned char V_47 , V_48 ;
for( V_46 = 0 ; V_46 < 4 ; V_46 ++ ) {
V_47 = V_44 -> V_47 ;
V_48 = V_44 -> V_49 & 0x3f ;
if( V_47 == 63 ) {
V_35 -> V_38 = 64 ;
V_35 -> V_39 = 32 ;
break;
} else if( V_47 == 127 ) {
V_35 -> V_38 = 128 ;
V_35 -> V_39 = 32 ;
break;
} else if( V_47 == 254 ) {
V_35 -> V_38 = 255 ;
V_35 -> V_39 = 63 ;
break;
}
V_44 ++ ;
}
if ( V_46 == 4 ) {
V_47 = V_43 -> V_47 ;
V_48 = V_43 -> V_49 & 0x3f ;
}
V_35 -> V_40 = F_7 ( V_32 , V_35 -> V_38 * V_35 -> V_39 ) ;
if ( V_46 < 4 && V_48 == V_35 -> V_39 ) {
if ( V_35 -> V_40 != V_45 )
F_6 ( ( V_37 L_2 ,
V_35 -> V_38 , V_35 -> V_39 , V_46 ) ) ;
} else if ( V_47 > 0 || V_48 > 0 ) {
F_6 ( ( V_37 L_3 ,
V_47 + 1 , V_48 , V_46 ) ) ;
F_6 ( ( V_37 L_4 ,
V_35 -> V_38 , V_35 -> V_39 ) ) ;
}
}
F_10 ( V_36 ) ;
return 0 ;
}
static int F_11 ( struct V_28 * V_29 )
{
struct V_6 * V_50 = (struct V_6 * ) V_29 -> V_4 -> V_8 ;
if ( V_50 -> V_51 && ( V_29 -> type == V_52 ) )
V_29 -> V_53 = 1 ;
if ( ( V_29 -> type == V_52 ) &&
( F_12 ( V_29 ) != V_54 ) &&
( ! V_50 -> V_51 || V_29 -> V_55 ) &&
( ! V_50 -> V_56 || ( F_12 ( V_29 ) != 2 ) ) ) {
if ( V_57 == 0 )
return - V_58 ;
if ( V_57 < 0 )
V_29 -> V_59 = 1 ;
}
if ( V_29 -> V_60 && ( V_29 -> type == V_52 ) &&
( ! V_50 -> V_56 || ( F_12 ( V_29 ) != 2 ) ) &&
! V_29 -> V_59 ) {
struct V_28 * V_7 ;
struct V_3 * V_4 = V_29 -> V_4 ;
unsigned V_61 = 0 ;
unsigned V_62 = 0 ;
unsigned V_63 ;
unsigned V_64 ;
if ( V_29 -> V_65 -> V_66 < ( 45 * V_67 ) )
F_13 ( V_29 -> V_65 , 45 * V_67 ) ;
for ( V_64 = 0 ; V_64 < V_50 -> V_68 ; ++ V_64 )
if ( V_50 -> V_69 [ V_64 ] . V_70 )
++ V_61 ;
F_14 (dev, host) {
if ( V_7 -> V_60 && ( V_7 -> type == V_52 ) &&
( ! V_50 -> V_56 ||
( F_12 ( V_29 ) != 2 ) ) &&
! V_7 -> V_59 ) {
if ( ( F_12 ( V_7 ) != V_54 )
|| ! V_50 -> V_69 [ F_15 ( V_7 ) ] . V_70 )
++ V_61 ;
} else
++ V_62 ;
}
if ( V_61 == 0 )
++ V_61 ;
V_63 = ( V_4 -> V_11 - V_62 ) / V_61 ;
if ( V_63 > 256 )
V_63 = 256 ;
else if ( V_63 < 2 )
V_63 = 2 ;
F_16 ( V_29 , V_71 , V_63 ) ;
} else
F_16 ( V_29 , 0 , 1 ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_29 , int V_63 ,
int V_72 )
{
if ( V_72 != V_73 )
return - V_74 ;
if ( V_29 -> V_60 && ( V_29 -> type == V_52 ) &&
( F_12 ( V_29 ) == V_54 ) ) {
struct V_28 * V_7 ;
struct V_3 * V_4 = V_29 -> V_4 ;
unsigned V_46 = 0 ;
F_14 (dev, host) {
if ( V_7 -> V_60 && ( V_7 -> type == V_52 ) &&
( F_12 ( V_7 ) == V_54 ) )
++ V_46 ;
++ V_46 ;
}
if ( V_46 >= V_4 -> V_11 )
V_46 = V_4 -> V_11 - 1 ;
if ( V_63 > ( V_4 -> V_11 - V_46 ) )
V_63 = V_4 -> V_11 - V_46 ;
if ( V_63 > 256 )
V_63 = 256 ;
else if ( V_63 < 2 )
V_63 = 2 ;
F_16 ( V_29 , V_71 , V_63 ) ;
} else
F_16 ( V_29 , 0 , 1 ) ;
return V_29 -> V_75 ;
}
static T_3 F_18 ( struct V_5 * V_7 , struct V_76 * V_77 , char * V_36 )
{
struct V_28 * V_29 = F_19 ( V_7 ) ;
struct V_6 * V_50 = (struct V_6 * ) ( V_29 -> V_4 -> V_8 ) ;
if ( F_12 ( V_29 ) != V_54 )
return snprintf ( V_36 , V_78 , V_29 -> V_59
? L_5 :
( ( V_50 -> V_51 && ( V_29 -> type == V_52 ) ) ? L_6 : L_7 ) ) ;
return snprintf ( V_36 , V_78 , L_8 ,
F_20 ( V_50 -> V_69 [ F_15 ( V_29 ) ] . type ) ) ;
}
static int F_21 ( struct V_28 * V_29 , int V_2 , void T_4 * V_79 )
{
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_4 -> V_8 ;
if ( ! F_22 ( V_80 ) )
return - V_81 ;
return F_23 ( V_7 , V_2 , V_79 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_5 ;
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_6 * V_50 = (struct V_6 * ) V_4 -> V_8 ;
int V_9 ;
int V_82 = V_24 ;
F_25 ( V_83 L_9 ,
V_84 ,
V_4 -> V_85 , F_12 ( V_7 ) , F_15 ( V_7 ) , V_7 -> V_86 ) ;
switch ( V_2 -> V_87 [ 0 ] ) {
case V_88 :
if ( ! ( V_50 -> V_89 ) ||
! ( V_50 -> V_90 ) ||
( ( V_2 -> V_87 [ 1 ] & 0x1f ) != V_91 ) )
break;
case V_92 :
case V_93 :
for ( V_9 = 0 ; V_9 < ( V_4 -> V_11 + V_12 ) ; ++ V_9 ) {
struct V_13 * V_13 = & V_50 -> V_14 [ V_9 ] ;
if ( V_13 -> V_16 -> V_17 . V_18 &&
( V_13 -> V_94 & V_95 ) &&
( V_13 -> V_19 == V_2 ) ) {
V_13 -> V_94 |= V_96 ;
V_2 -> V_20 . V_21 = V_97 ;
V_82 = V_98 ;
}
}
break;
case V_99 :
for ( V_9 = 0 ; V_9 < ( V_4 -> V_11 + V_12 ) ; ++ V_9 ) {
struct V_1 * V_15 ;
struct V_13 * V_13 = & V_50 -> V_14 [ V_9 ] ;
if ( ( V_13 -> V_16 -> V_17 . V_18 & F_26 ( V_100 | V_101 ) ) &&
( V_13 -> V_94 & V_95 ) &&
( ( V_15 = V_13 -> V_19 ) ) &&
( V_15 -> V_5 == V_2 -> V_5 ) ) {
V_13 -> V_94 |= V_96 ;
V_15 -> V_20 . V_21 = V_97 ;
if ( V_15 == V_2 )
V_82 = V_98 ;
}
}
}
return V_82 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_5 ;
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_1 * V_15 ;
int V_9 ;
struct V_6 * V_50 = (struct V_6 * ) V_4 -> V_8 ;
unsigned long V_94 ;
for ( V_9 = 0 ; V_9 < ( V_4 -> V_11 + V_12 ) ; ++ V_9 ) {
struct V_13 * V_13 = & V_50 -> V_14 [ V_9 ] ;
if ( V_13 -> V_16 -> V_17 . V_18 &&
( V_13 -> V_94 & V_95 ) &&
( V_13 -> V_19 == V_2 ) ) {
V_13 -> V_94 |= V_96 ;
V_2 -> V_20 . V_21 = V_97 ;
}
}
F_25 ( V_83 L_10 ,
V_84 ) ;
if ( ( V_9 = F_28 ( V_50 ) ) )
return V_9 ;
for ( V_9 = 60 ; V_9 ; -- V_9 ) {
int V_102 = V_50 -> V_103 ;
if ( V_102 == 0 )
F_14 (dev, host) {
F_29 ( & V_7 -> V_104 , V_94 ) ;
F_30 (command, &dev->cmd_list, list) {
if ( ( V_15 != V_2 ) &&
( V_15 -> V_20 . V_21 == V_22 ) ) {
V_102 ++ ;
break;
}
}
F_31 ( & V_7 -> V_104 , V_94 ) ;
if ( V_102 )
break;
}
if ( V_102 == 0 )
return V_98 ;
F_32 ( 1 ) ;
}
F_25 ( V_83 L_11 , V_84 ) ;
if ( ( ( V_50 -> V_105 . V_106 &
V_107 ) ||
( V_50 -> V_105 . V_106 &
V_108 ) ) &&
V_109 &&
( ( V_109 != 1 ) ||
! ( V_50 -> V_105 . V_106 &
V_110 ) ) )
F_33 ( V_50 , 2 ) ;
return V_98 ;
}
static int F_34 ( struct V_111 * V_111 , struct V_112 * V_112 )
{
struct V_6 * V_50 ;
unsigned V_113 = F_35 ( V_111 ) ;
int V_114 = - V_115 ;
F_36 ( & V_116 ) ;
F_30 (aac, &aac_devices, entry) {
if ( V_50 -> V_117 == V_113 ) {
V_112 -> V_118 = V_50 ;
V_114 = 0 ;
break;
}
}
F_37 ( & V_116 ) ;
return V_114 ;
}
static long F_38 ( struct V_112 * V_112 ,
unsigned int V_2 , unsigned long V_79 )
{
int V_82 ;
if ( ! F_22 ( V_80 ) )
return - V_81 ;
F_36 ( & V_116 ) ;
V_82 = F_23 ( V_112 -> V_118 , V_2 , ( void T_4 * ) V_79 ) ;
F_37 ( & V_116 ) ;
return V_82 ;
}
static long F_39 ( struct V_6 * V_7 , unsigned V_2 , unsigned long V_79 )
{
long V_82 ;
F_36 ( & V_116 ) ;
switch ( V_2 ) {
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
case V_129 :
V_82 = F_23 ( V_7 , V_2 , ( void T_4 * ) V_79 ) ;
break;
case V_130 : {
struct V_131 T_4 * V_132 ;
V_132 = F_40 ( sizeof( * V_132 ) ) ;
V_82 = 0 ;
if ( F_41 ( V_132 , sizeof( * V_132 ) ) )
V_82 = - V_133 ;
if ( F_42 ( V_132 , ( void T_4 * ) V_79 , sizeof( struct V_131 ) - sizeof( T_1 ) ) )
V_82 = - V_133 ;
if ( ! V_82 )
V_82 = F_23 ( V_7 , V_2 , V_132 ) ;
break;
}
default:
V_82 = - V_134 ;
break;
}
F_37 ( & V_116 ) ;
return V_82 ;
}
static int F_43 ( struct V_28 * V_29 , int V_2 , void T_4 * V_79 )
{
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_4 -> V_8 ;
if ( ! F_22 ( V_80 ) )
return - V_81 ;
return F_39 ( V_7 , V_2 , ( unsigned long ) V_79 ) ;
}
static long F_44 ( struct V_112 * V_112 , unsigned V_2 , unsigned long V_79 )
{
if ( ! F_22 ( V_80 ) )
return - V_81 ;
return F_39 ( V_112 -> V_118 , V_2 , V_79 ) ;
}
static T_3 F_45 ( struct V_5 * V_5 ,
struct V_76 * V_77 , char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_135 ;
if ( V_7 -> V_105 . V_136 [ 0 ] ) {
char * V_137 = V_7 -> V_105 . V_136 ;
while ( * V_137 && * V_137 != ' ' )
++ V_137 ;
while ( * V_137 == ' ' )
++ V_137 ;
V_135 = snprintf ( V_36 , V_78 , L_8 , V_137 ) ;
} else
V_135 = snprintf ( V_36 , V_78 , L_8 ,
V_27 [ V_7 -> V_138 ] . V_139 ) ;
return V_135 ;
}
static T_3 F_47 ( struct V_5 * V_5 ,
struct V_76 * V_77 , char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_135 ;
if ( V_7 -> V_105 . V_136 [ 0 ] ) {
char * V_137 = V_7 -> V_105 . V_136 ;
while ( * V_137 && * V_137 != ' ' )
++ V_137 ;
V_135 = snprintf ( V_36 , V_78 , L_12 ,
( int ) ( V_137 - ( char * ) V_7 -> V_105 . V_136 ) ,
V_7 -> V_105 . V_136 ) ;
} else
V_135 = snprintf ( V_36 , V_78 , L_8 ,
V_27 [ V_7 -> V_138 ] . V_140 ) ;
return V_135 ;
}
static T_3 F_48 ( struct V_5 * V_141 ,
struct V_76 * V_77 , char * V_36 )
{
int V_135 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_141 ) -> V_8 ;
if ( F_49 ( F_6 ( V_142 ) ) )
V_135 = snprintf ( V_36 , V_78 , L_13 ) ;
#ifdef F_50
V_135 += snprintf ( V_36 + V_135 , V_78 - V_135 ,
L_14 ) ;
#endif
if ( V_7 -> V_89 && V_7 -> V_90 )
V_135 += snprintf ( V_36 + V_135 , V_78 - V_135 ,
L_15 ) ;
if ( V_7 -> V_51 )
V_135 += snprintf ( V_36 + V_135 , V_78 - V_135 , L_16 ) ;
if ( V_7 -> V_105 . V_106 &
V_143 )
V_135 += snprintf ( V_36 + V_135 , V_78 - V_135 ,
L_17 ) ;
if ( V_7 -> V_144 )
V_135 += snprintf ( V_36 + V_135 , V_78 - V_135 , L_18 ) ;
return V_135 ;
}
static T_3 F_51 ( struct V_5 * V_5 ,
struct V_76 * V_77 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_135 , V_145 ;
V_145 = F_52 ( V_7 -> V_146 . V_147 ) ;
V_135 = snprintf ( V_36 , V_78 , L_19 ,
V_145 >> 24 , ( V_145 >> 16 ) & 0xff , V_145 & 0xff ,
F_52 ( V_7 -> V_146 . V_148 ) ) ;
return V_135 ;
}
static T_3 F_53 ( struct V_5 * V_5 ,
struct V_76 * V_77 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_135 , V_145 ;
V_145 = F_52 ( V_7 -> V_146 . V_149 ) ;
V_135 = snprintf ( V_36 , V_78 , L_19 ,
V_145 >> 24 , ( V_145 >> 16 ) & 0xff , V_145 & 0xff ,
F_52 ( V_7 -> V_146 . V_150 ) ) ;
return V_135 ;
}
static T_3 F_54 ( struct V_5 * V_5 ,
struct V_76 * V_77 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_135 , V_145 ;
V_145 = F_52 ( V_7 -> V_146 . V_151 ) ;
V_135 = snprintf ( V_36 , V_78 , L_19 ,
V_145 >> 24 , ( V_145 >> 16 ) & 0xff , V_145 & 0xff ,
F_52 ( V_7 -> V_146 . V_152 ) ) ;
return V_135 ;
}
static T_3 F_55 ( struct V_5 * V_5 ,
struct V_76 * V_77 , char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_135 = 0 ;
if ( F_52 ( V_7 -> V_146 . V_153 [ 0 ] ) != 0xBAD0 )
V_135 = snprintf ( V_36 , 16 , L_20 ,
F_52 ( V_7 -> V_146 . V_153 [ 0 ] ) ) ;
if ( V_135 &&
! memcmp ( & V_7 -> V_105 . V_154 [
sizeof( V_7 -> V_105 . V_154 ) - V_135 ] ,
V_36 , V_135 - 1 ) )
V_135 = snprintf ( V_36 , 16 , L_12 ,
( int ) sizeof( V_7 -> V_105 . V_154 ) ,
V_7 -> V_105 . V_154 ) ;
return F_56 ( V_135 , 16 ) ;
}
static T_3 F_57 ( struct V_5 * V_5 ,
struct V_76 * V_77 , char * V_36 )
{
return snprintf ( V_36 , V_78 , L_21 ,
F_46 ( V_5 ) -> V_155 ) ;
}
static T_3 F_58 ( struct V_5 * V_5 ,
struct V_76 * V_77 , char * V_36 )
{
return snprintf ( V_36 , V_78 , L_21 ,
F_46 ( V_5 ) -> V_156 ) ;
}
static T_3 F_59 ( struct V_5 * V_5 ,
struct V_76 * V_77 ,
const char * V_36 , T_5 V_9 )
{
int V_157 = - V_158 ;
if ( ! F_22 ( V_159 ) )
return V_157 ;
V_157 = F_33 ( (struct V_6 * ) F_46 ( V_5 ) -> V_8 , V_36 [ 0 ] == '!' ) ;
if ( V_157 >= 0 )
V_157 = V_9 ;
return V_157 ;
}
static T_3 F_60 ( struct V_5 * V_5 ,
struct V_76 * V_77 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_135 , V_145 ;
V_145 = F_61 ( V_7 ) ;
if ( ( V_145 == 0 ) && V_7 -> V_103 )
V_145 = - V_160 ;
V_135 = snprintf ( V_36 , V_78 , L_22 , V_145 ) ;
return V_135 ;
}
T_3 F_62 ( struct V_5 * V_5 , char * V_36 )
{
return F_55 ( V_5 , & V_161 , V_36 ) ;
}
static void F_63 ( struct V_6 * V_50 )
{
if ( V_50 -> V_162 ) {
int V_163 ;
for ( V_163 = 0 ; V_163 < ( V_50 -> V_164 -> V_11 + V_12 ) ; V_163 ++ ) {
struct V_13 * V_13 = & V_50 -> V_14 [ V_163 ] ;
if ( ! ( V_13 -> V_16 -> V_17 . V_18 & F_26 ( V_101 | V_100 ) ) &&
( V_13 -> V_16 -> V_17 . V_18 & F_26 ( V_165 ) ) )
F_64 ( & V_13 -> V_166 ) ;
}
F_65 ( V_50 -> V_167 ) ;
}
F_66 ( V_50 ) ;
F_67 ( V_50 ) ;
F_68 ( V_50 -> V_168 -> V_169 , V_50 ) ;
if ( V_50 -> V_144 )
F_69 ( V_50 -> V_168 ) ;
}
static int F_70 ( struct V_170 * V_168 , const struct V_171 * V_117 )
{
unsigned V_172 = V_117 -> V_173 ;
struct V_3 * V_174 ;
struct V_6 * V_50 ;
struct V_175 * V_176 = & V_177 ;
int error = - V_115 ;
int V_178 = 0 ;
T_6 V_179 ;
extern int V_180 ;
F_30 (aac, &aac_devices, entry) {
if ( V_50 -> V_117 > V_178 )
break;
V_176 = & V_50 -> V_44 ;
V_178 ++ ;
}
F_71 ( V_168 , V_181 | V_182 |
V_183 ) ;
error = F_72 ( V_168 ) ;
if ( error )
goto V_184;
error = - V_115 ;
if ( V_27 [ V_172 ] . V_185 & V_186 )
V_179 = F_73 ( 31 ) ;
else
V_179 = F_73 ( 32 ) ;
if ( F_74 ( V_168 , V_179 ) ||
F_75 ( V_168 , V_179 ) )
goto V_187;
F_76 ( V_168 ) ;
V_174 = F_77 ( & V_188 , sizeof( struct V_6 ) ) ;
if ( ! V_174 )
goto V_187;
V_174 -> V_169 = V_168 -> V_169 ;
V_174 -> V_178 = V_178 ;
V_174 -> V_189 = 16 ;
V_174 -> V_190 = 1 ;
V_50 = (struct V_6 * ) V_174 -> V_8 ;
V_50 -> V_191 = F_78 ( V_168 , 0 ) ;
V_50 -> V_164 = V_174 ;
V_50 -> V_168 = V_168 ;
V_50 -> V_192 = V_188 . V_192 ;
V_50 -> V_117 = V_174 -> V_178 ;
V_50 -> V_138 = V_172 ;
F_79 ( & V_50 -> V_44 ) ;
V_50 -> V_14 = F_80 ( sizeof( struct V_13 ) * ( V_174 -> V_11 + V_12 ) , V_193 ) ;
if ( ! V_50 -> V_14 )
goto V_194;
F_81 ( & V_50 -> V_195 ) ;
V_50 -> V_196 = V_197 ;
if ( ( * V_27 [ V_172 ] . V_198 ) ( V_50 ) )
goto V_199;
if ( V_50 -> V_200 ) {
if ( V_180 )
F_25 ( V_201 L_23
L_24
L_25 ,
V_50 -> V_192 ,
V_50 -> V_117 ) ;
else
F_25 ( V_201 L_26
L_27
L_28 ,
V_50 -> V_192 ,
V_50 -> V_117 ) ;
}
V_50 -> V_167 = F_82 ( V_202 , V_50 , V_84 ) ;
if ( F_83 ( V_50 -> V_167 ) ) {
F_25 ( V_83 L_29 ) ;
error = F_84 ( V_50 -> V_167 ) ;
V_50 -> V_167 = NULL ;
goto V_203;
}
if ( V_27 [ V_172 ] . V_185 & V_186 )
if ( F_74 ( V_168 , F_73 ( 32 ) ) )
goto V_203;
V_50 -> V_204 = V_27 [ V_172 ] . V_205 ;
error = F_85 ( V_50 ) ;
if ( error < 0 )
goto V_203;
if ( ( V_27 [ V_172 ] . V_185 & V_206 ) &&
( V_174 -> V_207 > 34 ) ) {
V_174 -> V_207 = 34 ;
V_174 -> V_208 = ( V_174 -> V_207 * 8 ) + 112 ;
}
if ( ( V_27 [ V_172 ] . V_185 & V_209 ) &&
( V_174 -> V_207 > 17 ) ) {
V_174 -> V_207 = 17 ;
V_174 -> V_208 = ( V_174 -> V_207 * 8 ) + 112 ;
}
error = F_86 ( V_168 ,
( V_50 -> V_146 . V_210 & V_211 ) ?
( V_174 -> V_208 << 9 ) : 65536 ) ;
if ( error )
goto V_203;
if ( V_27 [ V_172 ] . V_185 & V_206 )
V_50 -> V_212 = 1 ;
else
V_50 -> V_212 = 0 ;
if ( V_50 -> V_213 || V_57 || V_50 -> V_51 )
V_174 -> V_155 = V_50 -> V_204 ;
else
V_174 -> V_155 = 0 ;
F_87 ( V_50 , 0 ) ;
F_88 ( V_50 ) ;
F_89 ( & V_50 -> V_44 , V_176 ) ;
V_174 -> V_156 = V_50 -> V_68 ;
if ( V_174 -> V_156 < V_50 -> V_214 )
V_174 -> V_156 = V_50 -> V_214 ;
if ( V_174 -> V_156 < V_215 )
V_174 -> V_156 = V_215 ;
else
V_174 -> V_216 = V_174 -> V_156 ;
V_174 -> V_217 = V_218 ;
F_90 ( V_168 , V_174 ) ;
error = F_91 ( V_174 , & V_168 -> V_7 ) ;
if ( error )
goto V_203;
F_92 ( V_174 ) ;
return 0 ;
V_203:
F_63 ( V_50 ) ;
V_199:
F_93 ( V_50 ) ;
if ( V_50 -> V_219 )
F_94 ( V_50 -> V_168 , V_50 -> V_220 , V_50 -> V_219 ,
V_50 -> V_221 ) ;
F_10 ( V_50 -> V_222 ) ;
F_95 ( V_50 , 0 ) ;
F_10 ( V_50 -> V_14 ) ;
F_10 ( V_50 -> V_69 ) ;
V_194:
F_96 ( V_174 ) ;
V_187:
F_97 ( V_168 ) ;
V_184:
return error ;
}
static void F_98 ( struct V_170 * V_7 )
{
struct V_3 * V_174 = F_99 ( V_7 ) ;
F_100 ( V_174 ) ;
F_63 ( (struct V_6 * ) V_174 -> V_8 ) ;
}
static void F_101 ( struct V_170 * V_168 )
{
struct V_3 * V_174 = F_99 ( V_168 ) ;
struct V_6 * V_50 = (struct V_6 * ) V_174 -> V_8 ;
F_102 ( V_174 ) ;
F_63 ( V_50 ) ;
F_93 ( V_50 ) ;
F_94 ( V_50 -> V_168 , V_50 -> V_220 , V_50 -> V_219 ,
V_50 -> V_221 ) ;
F_10 ( V_50 -> V_222 ) ;
F_95 ( V_50 , 0 ) ;
F_10 ( V_50 -> V_14 ) ;
F_10 ( V_50 -> V_69 ) ;
F_103 ( & V_50 -> V_44 ) ;
F_96 ( V_174 ) ;
F_97 ( V_168 ) ;
if ( F_104 ( & V_177 ) ) {
F_105 ( V_223 , L_30 ) ;
V_223 = - 1 ;
}
}
static int T_7 F_106 ( void )
{
int error ;
F_25 ( V_201 L_31 ,
V_84 , V_224 ) ;
error = F_107 ( & V_225 ) ;
if ( error < 0 )
return error ;
V_223 = F_108 ( 0 , L_30 , & V_226 ) ;
if ( V_223 < 0 ) {
F_25 ( V_227
L_32 ) ;
}
return 0 ;
}
static void T_8 F_109 ( void )
{
if ( V_223 > - 1 )
F_105 ( V_223 , L_30 ) ;
F_110 ( & V_225 ) ;
}
