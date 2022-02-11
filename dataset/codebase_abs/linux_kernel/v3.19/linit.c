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
F_16 ( V_29 , V_63 ) ;
} else
F_16 ( V_29 , 1 ) ;
return 0 ;
}
static int F_17 ( struct V_28 * V_29 , int V_63 )
{
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
return F_16 ( V_29 , V_63 ) ;
}
return F_16 ( V_29 , 1 ) ;
}
static T_3 F_18 ( struct V_5 * V_7 , struct V_71 * V_72 , char * V_36 )
{
struct V_28 * V_29 = F_19 ( V_7 ) ;
struct V_6 * V_50 = (struct V_6 * ) ( V_29 -> V_4 -> V_8 ) ;
if ( F_12 ( V_29 ) != V_54 )
return snprintf ( V_36 , V_73 , V_29 -> V_59
? L_5 :
( ( V_50 -> V_51 && ( V_29 -> type == V_52 ) ) ? L_6 : L_7 ) ) ;
return snprintf ( V_36 , V_73 , L_8 ,
F_20 ( V_50 -> V_69 [ F_15 ( V_29 ) ] . type ) ) ;
}
static int F_21 ( struct V_28 * V_29 , int V_2 , void T_4 * V_74 )
{
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_4 -> V_8 ;
if ( ! F_22 ( V_75 ) )
return - V_76 ;
return F_23 ( V_7 , V_2 , V_74 ) ;
}
static int F_24 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_5 ;
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_6 * V_50 = (struct V_6 * ) V_4 -> V_8 ;
int V_9 ;
int V_77 = V_24 ;
F_25 ( V_78 L_9 ,
V_79 ,
V_4 -> V_80 , F_12 ( V_7 ) , F_15 ( V_7 ) , V_7 -> V_81 ) ;
switch ( V_2 -> V_82 [ 0 ] ) {
case V_83 :
if ( ! ( V_50 -> V_84 ) ||
! ( V_50 -> V_85 ) ||
( ( V_2 -> V_82 [ 1 ] & 0x1f ) != V_86 ) )
break;
case V_87 :
case V_88 :
for ( V_9 = 0 ; V_9 < ( V_4 -> V_11 + V_12 ) ; ++ V_9 ) {
struct V_13 * V_13 = & V_50 -> V_14 [ V_9 ] ;
if ( V_13 -> V_16 -> V_17 . V_18 &&
( V_13 -> V_89 & V_90 ) &&
( V_13 -> V_19 == V_2 ) ) {
V_13 -> V_89 |= V_91 ;
V_2 -> V_20 . V_21 = V_92 ;
V_77 = V_93 ;
}
}
break;
case V_94 :
for ( V_9 = 0 ; V_9 < ( V_4 -> V_11 + V_12 ) ; ++ V_9 ) {
struct V_1 * V_15 ;
struct V_13 * V_13 = & V_50 -> V_14 [ V_9 ] ;
if ( ( V_13 -> V_16 -> V_17 . V_18 & F_26 ( V_95 | V_96 ) ) &&
( V_13 -> V_89 & V_90 ) &&
( ( V_15 = V_13 -> V_19 ) ) &&
( V_15 -> V_5 == V_2 -> V_5 ) ) {
V_13 -> V_89 |= V_91 ;
V_15 -> V_20 . V_21 = V_92 ;
if ( V_15 == V_2 )
V_77 = V_93 ;
}
}
}
return V_77 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_28 * V_7 = V_2 -> V_5 ;
struct V_3 * V_4 = V_7 -> V_4 ;
struct V_1 * V_15 ;
int V_9 ;
struct V_6 * V_50 = (struct V_6 * ) V_4 -> V_8 ;
unsigned long V_89 ;
for ( V_9 = 0 ; V_9 < ( V_4 -> V_11 + V_12 ) ; ++ V_9 ) {
struct V_13 * V_13 = & V_50 -> V_14 [ V_9 ] ;
if ( V_13 -> V_16 -> V_17 . V_18 &&
( V_13 -> V_89 & V_90 ) &&
( V_13 -> V_19 == V_2 ) ) {
V_13 -> V_89 |= V_91 ;
V_2 -> V_20 . V_21 = V_92 ;
}
}
F_25 ( V_78 L_10 ,
V_79 ) ;
if ( ( V_9 = F_28 ( V_50 ) ) )
return V_9 ;
for ( V_9 = 60 ; V_9 ; -- V_9 ) {
int V_97 = V_50 -> V_98 ;
if ( V_97 == 0 )
F_14 (dev, host) {
F_29 ( & V_7 -> V_99 , V_89 ) ;
F_30 (command, &dev->cmd_list, list) {
if ( ( V_15 != V_2 ) &&
( V_15 -> V_20 . V_21 == V_22 ) ) {
V_97 ++ ;
break;
}
}
F_31 ( & V_7 -> V_99 , V_89 ) ;
if ( V_97 )
break;
}
if ( V_97 == 0 )
return V_93 ;
F_32 ( 1 ) ;
}
F_25 ( V_78 L_11 , V_79 ) ;
if ( ( ( V_50 -> V_100 . V_101 &
V_102 ) ||
( V_50 -> V_100 . V_101 &
V_103 ) ) &&
V_104 &&
( ( V_104 != 1 ) ||
! ( V_50 -> V_100 . V_101 &
V_105 ) ) )
F_33 ( V_50 , 2 ) ;
return V_93 ;
}
static int F_34 ( struct V_106 * V_106 , struct V_107 * V_107 )
{
struct V_6 * V_50 ;
unsigned V_108 = F_35 ( V_106 ) ;
int V_109 = - V_110 ;
F_36 ( & V_111 ) ;
F_30 (aac, &aac_devices, entry) {
if ( V_50 -> V_112 == V_108 ) {
V_107 -> V_113 = V_50 ;
V_109 = 0 ;
break;
}
}
F_37 ( & V_111 ) ;
return V_109 ;
}
static long F_38 ( struct V_107 * V_107 ,
unsigned int V_2 , unsigned long V_74 )
{
int V_77 ;
if ( ! F_22 ( V_75 ) )
return - V_76 ;
F_36 ( & V_111 ) ;
V_77 = F_23 ( V_107 -> V_113 , V_2 , ( void T_4 * ) V_74 ) ;
F_37 ( & V_111 ) ;
return V_77 ;
}
static long F_39 ( struct V_6 * V_7 , unsigned V_2 , unsigned long V_74 )
{
long V_77 ;
F_36 ( & V_111 ) ;
switch ( V_2 ) {
case V_114 :
case V_115 :
case V_116 :
case V_117 :
case V_118 :
case V_119 :
case V_120 :
case V_121 :
case V_122 :
case V_123 :
case V_124 :
V_77 = F_23 ( V_7 , V_2 , ( void T_4 * ) V_74 ) ;
break;
case V_125 : {
struct V_126 T_4 * V_127 ;
V_127 = F_40 ( sizeof( * V_127 ) ) ;
V_77 = 0 ;
if ( F_41 ( V_127 , sizeof( * V_127 ) ) )
V_77 = - V_128 ;
if ( F_42 ( V_127 , ( void T_4 * ) V_74 , sizeof( struct V_126 ) - sizeof( T_1 ) ) )
V_77 = - V_128 ;
if ( ! V_77 )
V_77 = F_23 ( V_7 , V_2 , V_127 ) ;
break;
}
default:
V_77 = - V_129 ;
break;
}
F_37 ( & V_111 ) ;
return V_77 ;
}
static int F_43 ( struct V_28 * V_29 , int V_2 , void T_4 * V_74 )
{
struct V_6 * V_7 = (struct V_6 * ) V_29 -> V_4 -> V_8 ;
if ( ! F_22 ( V_75 ) )
return - V_76 ;
return F_39 ( V_7 , V_2 , ( unsigned long ) V_74 ) ;
}
static long F_44 ( struct V_107 * V_107 , unsigned V_2 , unsigned long V_74 )
{
if ( ! F_22 ( V_75 ) )
return - V_76 ;
return F_39 ( V_107 -> V_113 , V_2 , V_74 ) ;
}
static T_3 F_45 ( struct V_5 * V_5 ,
struct V_71 * V_72 , char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_130 ;
if ( V_7 -> V_100 . V_131 [ 0 ] ) {
char * V_132 = V_7 -> V_100 . V_131 ;
while ( * V_132 && * V_132 != ' ' )
++ V_132 ;
while ( * V_132 == ' ' )
++ V_132 ;
V_130 = snprintf ( V_36 , V_73 , L_8 , V_132 ) ;
} else
V_130 = snprintf ( V_36 , V_73 , L_8 ,
V_27 [ V_7 -> V_133 ] . V_134 ) ;
return V_130 ;
}
static T_3 F_47 ( struct V_5 * V_5 ,
struct V_71 * V_72 , char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_130 ;
if ( V_7 -> V_100 . V_131 [ 0 ] ) {
char * V_132 = V_7 -> V_100 . V_131 ;
while ( * V_132 && * V_132 != ' ' )
++ V_132 ;
V_130 = snprintf ( V_36 , V_73 , L_12 ,
( int ) ( V_132 - ( char * ) V_7 -> V_100 . V_131 ) ,
V_7 -> V_100 . V_131 ) ;
} else
V_130 = snprintf ( V_36 , V_73 , L_8 ,
V_27 [ V_7 -> V_133 ] . V_135 ) ;
return V_130 ;
}
static T_3 F_48 ( struct V_5 * V_136 ,
struct V_71 * V_72 , char * V_36 )
{
int V_130 = 0 ;
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_136 ) -> V_8 ;
if ( F_49 ( F_6 ( V_137 ) ) )
V_130 = snprintf ( V_36 , V_73 , L_13 ) ;
#ifdef F_50
V_130 += snprintf ( V_36 + V_130 , V_73 - V_130 ,
L_14 ) ;
#endif
if ( V_7 -> V_84 && V_7 -> V_85 )
V_130 += snprintf ( V_36 + V_130 , V_73 - V_130 ,
L_15 ) ;
if ( V_7 -> V_51 )
V_130 += snprintf ( V_36 + V_130 , V_73 - V_130 , L_16 ) ;
if ( V_7 -> V_100 . V_101 &
V_138 )
V_130 += snprintf ( V_36 + V_130 , V_73 - V_130 ,
L_17 ) ;
if ( V_7 -> V_139 )
V_130 += snprintf ( V_36 + V_130 , V_73 - V_130 , L_18 ) ;
return V_130 ;
}
static T_3 F_51 ( struct V_5 * V_5 ,
struct V_71 * V_72 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_130 , V_140 ;
V_140 = F_52 ( V_7 -> V_141 . V_142 ) ;
V_130 = snprintf ( V_36 , V_73 , L_19 ,
V_140 >> 24 , ( V_140 >> 16 ) & 0xff , V_140 & 0xff ,
F_52 ( V_7 -> V_141 . V_143 ) ) ;
return V_130 ;
}
static T_3 F_53 ( struct V_5 * V_5 ,
struct V_71 * V_72 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_130 , V_140 ;
V_140 = F_52 ( V_7 -> V_141 . V_144 ) ;
V_130 = snprintf ( V_36 , V_73 , L_19 ,
V_140 >> 24 , ( V_140 >> 16 ) & 0xff , V_140 & 0xff ,
F_52 ( V_7 -> V_141 . V_145 ) ) ;
return V_130 ;
}
static T_3 F_54 ( struct V_5 * V_5 ,
struct V_71 * V_72 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_130 , V_140 ;
V_140 = F_52 ( V_7 -> V_141 . V_146 ) ;
V_130 = snprintf ( V_36 , V_73 , L_19 ,
V_140 >> 24 , ( V_140 >> 16 ) & 0xff , V_140 & 0xff ,
F_52 ( V_7 -> V_141 . V_147 ) ) ;
return V_130 ;
}
static T_3 F_55 ( struct V_5 * V_5 ,
struct V_71 * V_72 , char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_130 = 0 ;
if ( F_52 ( V_7 -> V_141 . V_148 [ 0 ] ) != 0xBAD0 )
V_130 = snprintf ( V_36 , 16 , L_20 ,
F_52 ( V_7 -> V_141 . V_148 [ 0 ] ) ) ;
if ( V_130 &&
! memcmp ( & V_7 -> V_100 . V_149 [
sizeof( V_7 -> V_100 . V_149 ) - V_130 ] ,
V_36 , V_130 - 1 ) )
V_130 = snprintf ( V_36 , 16 , L_12 ,
( int ) sizeof( V_7 -> V_100 . V_149 ) ,
V_7 -> V_100 . V_149 ) ;
return F_56 ( V_130 , 16 ) ;
}
static T_3 F_57 ( struct V_5 * V_5 ,
struct V_71 * V_72 , char * V_36 )
{
return snprintf ( V_36 , V_73 , L_21 ,
F_46 ( V_5 ) -> V_150 ) ;
}
static T_3 F_58 ( struct V_5 * V_5 ,
struct V_71 * V_72 , char * V_36 )
{
return snprintf ( V_36 , V_73 , L_21 ,
F_46 ( V_5 ) -> V_151 ) ;
}
static T_3 F_59 ( struct V_5 * V_5 ,
struct V_71 * V_72 ,
const char * V_36 , T_5 V_9 )
{
int V_152 = - V_153 ;
if ( ! F_22 ( V_154 ) )
return V_152 ;
V_152 = F_33 ( (struct V_6 * ) F_46 ( V_5 ) -> V_8 , V_36 [ 0 ] == '!' ) ;
if ( V_152 >= 0 )
V_152 = V_9 ;
return V_152 ;
}
static T_3 F_60 ( struct V_5 * V_5 ,
struct V_71 * V_72 ,
char * V_36 )
{
struct V_6 * V_7 = (struct V_6 * ) F_46 ( V_5 ) -> V_8 ;
int V_130 , V_140 ;
V_140 = F_61 ( V_7 ) ;
if ( ( V_140 == 0 ) && V_7 -> V_98 )
V_140 = - V_155 ;
V_130 = snprintf ( V_36 , V_73 , L_22 , V_140 ) ;
return V_130 ;
}
T_3 F_62 ( struct V_5 * V_5 , char * V_36 )
{
return F_55 ( V_5 , & V_156 , V_36 ) ;
}
static void F_63 ( struct V_6 * V_50 )
{
if ( V_50 -> V_157 ) {
int V_158 ;
for ( V_158 = 0 ; V_158 < ( V_50 -> V_159 -> V_11 + V_12 ) ; V_158 ++ ) {
struct V_13 * V_13 = & V_50 -> V_14 [ V_158 ] ;
if ( ! ( V_13 -> V_16 -> V_17 . V_18 & F_26 ( V_96 | V_95 ) ) &&
( V_13 -> V_16 -> V_17 . V_18 & F_26 ( V_160 ) ) )
F_64 ( & V_13 -> V_161 ) ;
}
F_65 ( V_50 -> V_162 ) ;
}
F_66 ( V_50 ) ;
F_67 ( V_50 ) ;
F_68 ( V_50 -> V_163 -> V_164 , V_50 ) ;
if ( V_50 -> V_139 )
F_69 ( V_50 -> V_163 ) ;
}
static int F_70 ( struct V_165 * V_163 , const struct V_166 * V_112 )
{
unsigned V_167 = V_112 -> V_168 ;
struct V_3 * V_169 ;
struct V_6 * V_50 ;
struct V_170 * V_171 = & V_172 ;
int error = - V_110 ;
int V_173 = 0 ;
T_6 V_174 ;
extern int V_175 ;
F_30 (aac, &aac_devices, entry) {
if ( V_50 -> V_112 > V_173 )
break;
V_171 = & V_50 -> V_44 ;
V_173 ++ ;
}
F_71 ( V_163 , V_176 | V_177 |
V_178 ) ;
error = F_72 ( V_163 ) ;
if ( error )
goto V_179;
error = - V_110 ;
if ( V_27 [ V_167 ] . V_180 & V_181 )
V_174 = F_73 ( 31 ) ;
else
V_174 = F_73 ( 32 ) ;
if ( F_74 ( V_163 , V_174 ) ||
F_75 ( V_163 , V_174 ) )
goto V_182;
F_76 ( V_163 ) ;
V_169 = F_77 ( & V_183 , sizeof( struct V_6 ) ) ;
if ( ! V_169 )
goto V_182;
V_169 -> V_164 = V_163 -> V_164 ;
V_169 -> V_173 = V_173 ;
V_169 -> V_184 = 16 ;
V_169 -> V_185 = 1 ;
V_50 = (struct V_6 * ) V_169 -> V_8 ;
V_50 -> V_186 = F_78 ( V_163 , 0 ) ;
V_50 -> V_159 = V_169 ;
V_50 -> V_163 = V_163 ;
V_50 -> V_187 = V_183 . V_187 ;
V_50 -> V_112 = V_169 -> V_173 ;
V_50 -> V_133 = V_167 ;
F_79 ( & V_50 -> V_44 ) ;
V_50 -> V_14 = F_80 ( sizeof( struct V_13 ) * ( V_169 -> V_11 + V_12 ) , V_188 ) ;
if ( ! V_50 -> V_14 )
goto V_189;
F_81 ( & V_50 -> V_190 ) ;
V_50 -> V_191 = V_192 ;
if ( ( * V_27 [ V_167 ] . V_193 ) ( V_50 ) )
goto V_194;
if ( V_50 -> V_195 ) {
if ( V_175 )
F_25 ( V_196 L_23
L_24
L_25 ,
V_50 -> V_187 ,
V_50 -> V_112 ) ;
else
F_25 ( V_196 L_26
L_27
L_28 ,
V_50 -> V_187 ,
V_50 -> V_112 ) ;
}
V_50 -> V_162 = F_82 ( V_197 , V_50 , V_79 ) ;
if ( F_83 ( V_50 -> V_162 ) ) {
F_25 ( V_78 L_29 ) ;
error = F_84 ( V_50 -> V_162 ) ;
V_50 -> V_162 = NULL ;
goto V_198;
}
if ( V_27 [ V_167 ] . V_180 & V_181 )
if ( F_74 ( V_163 , F_73 ( 32 ) ) )
goto V_198;
V_50 -> V_199 = V_27 [ V_167 ] . V_200 ;
error = F_85 ( V_50 ) ;
if ( error < 0 )
goto V_198;
if ( ( V_27 [ V_167 ] . V_180 & V_201 ) &&
( V_169 -> V_202 > 34 ) ) {
V_169 -> V_202 = 34 ;
V_169 -> V_203 = ( V_169 -> V_202 * 8 ) + 112 ;
}
if ( ( V_27 [ V_167 ] . V_180 & V_204 ) &&
( V_169 -> V_202 > 17 ) ) {
V_169 -> V_202 = 17 ;
V_169 -> V_203 = ( V_169 -> V_202 * 8 ) + 112 ;
}
error = F_86 ( V_163 ,
( V_50 -> V_141 . V_205 & V_206 ) ?
( V_169 -> V_203 << 9 ) : 65536 ) ;
if ( error )
goto V_198;
if ( V_27 [ V_167 ] . V_180 & V_201 )
V_50 -> V_207 = 1 ;
else
V_50 -> V_207 = 0 ;
if ( V_50 -> V_208 || V_57 || V_50 -> V_51 )
V_169 -> V_150 = V_50 -> V_199 ;
else
V_169 -> V_150 = 0 ;
F_87 ( V_50 , 0 ) ;
F_88 ( V_50 ) ;
F_89 ( & V_50 -> V_44 , V_171 ) ;
V_169 -> V_151 = V_50 -> V_68 ;
if ( V_169 -> V_151 < V_50 -> V_209 )
V_169 -> V_151 = V_50 -> V_209 ;
if ( V_169 -> V_151 < V_210 )
V_169 -> V_151 = V_210 ;
else
V_169 -> V_211 = V_169 -> V_151 ;
V_169 -> V_212 = V_213 ;
F_90 ( V_163 , V_169 ) ;
error = F_91 ( V_169 , & V_163 -> V_7 ) ;
if ( error )
goto V_198;
F_92 ( V_169 ) ;
return 0 ;
V_198:
F_63 ( V_50 ) ;
V_194:
F_93 ( V_50 ) ;
if ( V_50 -> V_214 )
F_94 ( V_50 -> V_163 , V_50 -> V_215 , V_50 -> V_214 ,
V_50 -> V_216 ) ;
F_10 ( V_50 -> V_217 ) ;
F_95 ( V_50 , 0 ) ;
F_10 ( V_50 -> V_14 ) ;
F_10 ( V_50 -> V_69 ) ;
V_189:
F_96 ( V_169 ) ;
V_182:
F_97 ( V_163 ) ;
V_179:
return error ;
}
static void F_98 ( struct V_165 * V_7 )
{
struct V_3 * V_169 = F_99 ( V_7 ) ;
F_100 ( V_169 ) ;
F_63 ( (struct V_6 * ) V_169 -> V_8 ) ;
}
static void F_101 ( struct V_165 * V_163 )
{
struct V_3 * V_169 = F_99 ( V_163 ) ;
struct V_6 * V_50 = (struct V_6 * ) V_169 -> V_8 ;
F_102 ( V_169 ) ;
F_63 ( V_50 ) ;
F_93 ( V_50 ) ;
F_94 ( V_50 -> V_163 , V_50 -> V_215 , V_50 -> V_214 ,
V_50 -> V_216 ) ;
F_10 ( V_50 -> V_217 ) ;
F_95 ( V_50 , 0 ) ;
F_10 ( V_50 -> V_14 ) ;
F_10 ( V_50 -> V_69 ) ;
F_103 ( & V_50 -> V_44 ) ;
F_96 ( V_169 ) ;
F_97 ( V_163 ) ;
if ( F_104 ( & V_172 ) ) {
F_105 ( V_218 , L_30 ) ;
V_218 = - 1 ;
}
}
static int T_7 F_106 ( void )
{
int error ;
F_25 ( V_196 L_31 ,
V_79 , V_219 ) ;
error = F_107 ( & V_220 ) ;
if ( error < 0 )
return error ;
V_218 = F_108 ( 0 , L_30 , & V_221 ) ;
if ( V_218 < 0 ) {
F_25 ( V_222
L_32 ) ;
}
return 0 ;
}
static void T_8 F_109 ( void )
{
if ( V_218 > - 1 )
F_105 ( V_218 , L_30 ) ;
F_110 ( & V_220 ) ;
}
