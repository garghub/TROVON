int F_1 ( struct V_1 * V_2 , int V_3 , struct V_4 * * V_5 )
{
struct V_6 * V_7 ;
int V_8 ( V_9 ) ;
int V_10 ;
struct V_4 * V_11 ;
if ( V_5 )
* V_5 = NULL ;
if ( F_2 ( V_2 , & V_9 ) )
return - V_12 ;
if ( ( V_10 = F_3 ( V_2 -> V_13 , L_1 , V_3 , & V_11 ) ) < 0 )
return V_10 ;
if ( ( V_7 = F_4 ( sizeof( * V_7 ) , V_14 ) ) == NULL ) {
F_5 ( V_2 -> V_13 , V_11 ) ;
return - V_15 ;
}
V_7 -> V_2 = V_2 ;
V_7 -> V_9 = V_9 ;
V_7 -> V_16 . V_17 = V_18 ;
V_7 -> V_16 . V_19 = V_20 ;
V_7 -> V_16 . V_21 = V_22 ;
V_7 -> V_16 . V_23 = V_24 ;
V_7 -> V_16 . V_25 = V_26 ;
V_7 -> V_16 . V_27 = V_28 ;
F_6 ( & V_7 -> V_29 ) ;
sprintf ( V_11 -> V_30 , L_2 , ( V_9 >> 4 ) , ( V_9 & 0x0f ) ) ;
V_11 -> V_31 = V_32 ;
V_11 -> V_33 = V_7 ;
V_11 -> V_34 = V_35 ;
V_11 -> V_16 . V_36 = V_37 ;
V_11 -> V_16 . V_38 = V_39 ;
V_11 -> V_16 . V_40 = V_41 ;
F_7 ( V_7 , V_3 ) ;
if ( V_5 )
* V_5 = V_11 ;
return 0 ;
}
static void V_35 ( struct V_4 * V_42 )
{
int V_43 ;
struct V_6 * V_7 = V_42 -> V_33 ;
if ( V_7 ) {
if ( V_7 -> V_44 & V_45 )
V_26 ( V_7 ) ;
for ( V_43 = 0 ; V_43 < F_8 ( V_7 -> V_46 ) ; ++ V_43 )
F_9 ( V_7 -> V_46 [ V_43 ] ) ;
F_10 ( V_7 ) ;
}
}
static int V_37 ( struct V_4 * V_11 , struct V_47 * V_47 )
{
struct V_6 * V_7 = V_11 -> V_33 ;
return ( V_18 ( V_7 ) ) ;
}
static int V_39 ( struct V_4 * V_11 , struct V_47 * V_47 , unsigned int V_48 , unsigned long V_49 )
{
struct V_6 * V_7 = V_11 -> V_33 ;
struct V_50 V_51 ;
struct V_24 V_52 ;
int V_10 ;
if ( F_11 ( ! V_7 ) )
return - V_53 ;
if ( F_12 ( V_7 ) )
return - V_12 ;
switch ( V_48 ) {
case V_54 :
* V_51 . V_55 = * V_7 -> V_55 ;
V_51 . V_56 = V_7 -> V_56 ;
V_51 . V_57 = V_7 -> V_57 ;
V_51 . V_58 = V_7 -> V_58 ;
V_51 . V_59 = V_7 -> V_59 ;
V_51 . V_60 = V_7 -> V_60 ;
V_51 . V_61 = V_7 -> V_62 ;
V_51 . V_63 = V_7 -> V_63 ;
V_51 . V_64 = V_7 -> V_64 ;
V_51 . V_9 = V_7 -> V_9 ;
V_51 . V_65 = V_7 -> V_44 ;
if ( F_13 ( ( void V_66 * ) V_49 , & V_51 , sizeof( V_51 ) ) )
V_10 = - V_67 ;
else
V_10 = 0 ;
break;
case V_68 :
V_10 = ( V_7 -> V_44 & V_45 ?
- V_69 : F_14 ( V_7 , (struct V_70 V_66 * ) V_49 ) ) ;
break;
case V_71 :
V_10 = ( V_7 -> V_44 & V_45 ?
- V_69 : F_15 ( V_7 ) ) ;
break;
case V_72 :
if ( F_16 ( & V_52 , ( void V_66 * ) V_49 , sizeof( V_52 ) ) )
V_10 = - V_67 ;
else
V_10 = V_24 ( V_7 , V_52 . V_73 , V_52 . V_74 ) ;
break;
case V_75 :
V_10 = V_26 ( V_7 ) ;
break;
case V_76 :
V_10 = F_17 ( V_7 ) ;
break;
case V_77 :
V_10 = F_18 ( V_7 ) ;
break;
default:
V_10 = - V_78 ;
break;
}
return V_10 ;
}
static int V_41 ( struct V_4 * V_11 , struct V_47 * V_47 )
{
struct V_6 * V_7 = V_11 -> V_33 ;
return ( V_20 ( V_7 ) ) ;
}
static int V_18 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_29 ) ;
if ( V_7 -> V_79 ) {
F_20 ( & V_7 -> V_29 ) ;
return - V_80 ;
}
V_7 -> V_79 ++ ;
F_20 ( & V_7 -> V_29 ) ;
return 0 ;
}
static int V_20 ( struct V_6 * V_7 )
{
F_19 ( & V_7 -> V_29 ) ;
V_7 -> V_79 -- ;
F_20 ( & V_7 -> V_29 ) ;
return 0 ;
}
static int F_14 ( struct V_6 * V_7 ,
struct V_70 V_66 * V_81 )
{
struct V_82 V_51 ;
unsigned char V_66 * V_83 ;
unsigned char V_66 * V_84 ;
unsigned short V_56 = 0 ;
struct V_85 V_86 , V_87 , V_88 ;
T_1 V_89 ;
struct V_90 V_91 ;
unsigned long V_92 ;
int V_10 ;
if ( F_16 ( & V_51 , V_81 , sizeof( V_51 ) ) )
return - V_67 ;
V_83 = V_81 -> V_93 ;
if ( F_16 ( & V_86 , V_83 , sizeof( V_86 ) ) )
return - V_67 ;
if ( ( V_86 . V_30 != V_94 ) ||
( F_21 ( V_86 . V_95 ) >= V_96 - sizeof( V_86 ) ) ) {
F_22 ( L_3 , V_97 ) ;
return - V_53 ;
}
V_83 += sizeof( V_86 ) ;
V_84 = V_83 + F_21 ( V_86 . V_95 ) ;
if ( F_16 ( & V_89 , V_83 , sizeof( V_89 ) ) )
return - V_67 ;
if ( V_89 != V_98 ) {
F_22 ( L_4 , V_97 ) ;
return - V_53 ;
}
V_83 += sizeof ( V_89 ) ;
for (; V_83 < V_84 ; V_83 += F_21 ( V_87 . V_95 ) ) {
if ( F_16 ( & V_87 , V_83 , sizeof( V_87 ) ) )
return - V_67 ;
V_83 += sizeof( V_87 ) ;
if ( V_87 . V_30 != V_99 )
continue;
if ( F_16 ( & V_89 , V_83 , sizeof( V_89 ) ) )
return - V_67 ;
switch ( V_89 ) {
case V_100 :
if ( F_16 ( & V_91 , V_83 + sizeof( V_89 ) , sizeof( V_91 ) ) )
return - V_67 ;
V_56 = F_23 ( V_91 . V_56 ) ;
break;
case V_101 :
if ( V_56 != V_51 . V_102 )
break;
V_83 += sizeof( V_89 ) ;
if ( V_7 -> V_62 == V_103 ) {
F_24 ( V_7 ) ;
}
V_7 -> V_44 = 0 ;
V_7 -> V_62 = 0 ;
for (; ; ) {
if ( V_83 >= V_84 )
return - V_53 ;
if ( F_16 ( & V_88 , V_83 , sizeof( V_88 ) ) )
return - V_67 ;
if ( V_88 . V_30 != V_104 )
break;
V_83 += sizeof( V_88 ) ;
V_10 = F_25 ( V_7 , V_83 , F_21 ( V_88 . V_95 ) ,
V_105 ) ;
if ( V_10 )
return V_10 ;
V_83 += F_21 ( V_88 . V_95 ) ;
}
if ( F_16 ( & V_88 , V_83 , sizeof( V_88 ) ) )
return - V_67 ;
if ( V_88 . V_30 != V_106 ) {
F_22 ( L_5 , V_97 ) ;
return - V_53 ;
}
V_83 += sizeof( V_88 ) ;
V_10 = F_25 ( V_7 , V_83 ,
F_21 ( V_88 . V_95 ) , 0 ) ;
if ( V_10 )
return V_10 ;
F_26 ( V_7 -> V_55 , V_51 . V_55 , sizeof( V_7 -> V_55 ) ) ;
V_7 -> V_56 = V_56 ;
V_7 -> V_62 = F_23 ( V_91 . V_107 ) ;
switch ( F_23 ( V_91 . V_108 ) ) {
case 0x0001 :
if ( F_23 ( V_91 . V_107 ) == V_109 ) {
if ( F_27 ( V_7 ) == 0 )
V_7 -> V_62 = V_103 ;
}
V_7 -> V_57 = 0 ;
break;
case 0x0006 :
V_7 -> V_57 = V_110 ;
break;
case 0x0007 :
V_7 -> V_57 = V_111 ;
break;
case 0x0011 :
case 0x0200 :
V_7 -> V_57 = V_112 ;
break;
case 201 :
V_7 -> V_57 = 0 ;
break;
case 0x0202 :
case 0x0203 :
V_7 -> V_57 = V_113 ;
break;
default:
V_7 -> V_57 = V_7 -> V_59 = V_7 -> V_60 = 0 ;
V_7 -> V_62 = 0 ;
F_22 ( L_6 ,
V_97 ,
F_23 ( V_91 . V_108 ) ) ;
return - V_53 ;
}
V_7 -> V_58 = F_23 ( V_91 . V_114 ) ;
V_7 -> V_59 = F_23 ( V_91 . V_115 ) ;
V_7 -> V_60 = F_23 ( V_91 . V_116 ) ;
F_28 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
F_29 ( V_7 -> V_2 , 0xfc ) ;
F_29 ( V_7 -> V_2 , 0x00 ) ;
F_30 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
V_7 -> V_44 = V_118 ;
return 0 ;
}
}
F_22 ( L_7 , V_97 , V_51 . V_102 ) ;
return - V_53 ;
}
static int F_15 ( struct V_6 * V_7 )
{
if ( V_7 -> V_44 & V_45 )
return - V_69 ;
if ( ! ( V_7 -> V_44 & V_118 ) )
return - V_119 ;
V_7 -> V_57 = 0 ;
V_7 -> V_58 = V_7 -> V_59 = V_7 -> V_60 = 0 ;
if ( V_7 -> V_62 == V_103 ) {
F_24 ( V_7 ) ;
}
V_7 -> V_44 = 0 ;
V_7 -> V_62 = 0 ;
return 0 ;
}
static inline int F_31 ( struct V_1 * V_2 , const unsigned char * V_120 , int V_121 )
{
int V_43 ;
for ( V_43 = 0 ; V_43 < V_121 ; V_43 ++ ) {
if ( ! F_32 ( V_2 , V_120 [ V_43 ] ) )
return - V_122 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned char V_123 , unsigned char V_124 )
{
unsigned char V_125 [ 3 ] ;
V_125 [ 0 ] = 0x05 ;
V_125 [ 1 ] = V_124 ;
V_125 [ 2 ] = V_123 ;
F_31 ( V_2 , V_125 , 3 ) ;
F_32 ( V_2 , 0x03 ) ;
if ( F_34 ( V_2 ) != V_123 )
return - V_122 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_2 , unsigned char V_126 , unsigned char V_124 )
{
unsigned char V_125 [ 3 ] ;
V_125 [ 0 ] = 0x0e ;
V_125 [ 1 ] = V_126 ;
V_125 [ 2 ] = V_124 ;
return F_31 ( V_2 , V_125 , 3 ) ;
}
static int F_36 ( struct V_1 * V_2 , unsigned char V_126 )
{
unsigned char V_125 [ 2 ] ;
V_125 [ 0 ] = 0x0f ;
V_125 [ 1 ] = V_126 ;
F_31 ( V_2 , V_125 , 2 ) ;
return F_34 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 , unsigned char V_62 )
{
unsigned char V_125 [ 2 ] ;
V_125 [ 0 ] = 0x04 ;
V_125 [ 1 ] = V_62 ;
return F_31 ( V_2 , V_125 , 2 ) ;
}
static int F_2 ( struct V_1 * V_2 , int * V_9 )
{
unsigned char V_127 , V_128 ;
unsigned long V_92 ;
int V_129 = - V_12 ;
F_28 ( & V_2 -> V_117 , V_92 ) ;
F_33 ( V_2 , 0x00 , 0x00 ) ;
F_29 ( V_2 , 0xfc ) ;
V_127 = F_36 ( V_2 , 0x83 ) ;
F_35 ( V_2 , 0x83 , ~ V_127 ) ;
V_128 = F_36 ( V_2 , 0x83 ) ;
if ( V_128 != ( V_127 ^ 0xff ) )
goto V_130;
F_35 ( V_2 , 0x83 , V_127 ) ;
V_128 = F_36 ( V_2 , 0x83 ) ;
if ( V_128 != V_127 )
goto V_130;
F_29 ( V_2 , 0x00 ) ;
* V_9 = F_37 ( V_2 ) ;
F_38 ( V_2 ) ;
if ( * V_9 >= 0x10 && * V_9 <= 0x1f )
V_129 = 0 ;
V_130:
F_30 ( & V_2 -> V_117 , V_92 ) ;
return V_129 ;
}
static int F_37 ( struct V_1 * V_2 )
{
unsigned char V_125 [ 2 ] ;
V_125 [ 0 ] = 0x08 ;
V_125 [ 1 ] = 0x03 ;
F_31 ( V_2 , V_125 , 2 ) ;
return ( F_34 ( V_2 ) ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
if ( V_7 -> V_9 < 0x10 || V_7 -> V_9 > 0x1f ) {
F_22 ( L_8 , V_97 , V_7 -> V_9 ) ;
return 1 ;
}
return 0 ;
}
static int F_39 ( struct V_6 * V_7 , const unsigned char * V_131 , int V_121 , int V_132 )
{
int V_133 , V_43 ;
int V_10 ;
int V_129 = - V_122 ;
unsigned long V_92 ;
F_28 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
F_32 ( V_7 -> V_2 , 0x01 ) ;
if ( F_34 ( V_7 -> V_2 ) ) {
F_22 ( L_9 , V_97 ) ;
goto V_130;
}
F_32 ( V_7 -> V_2 , ( unsigned char ) ( V_121 - 1 ) ) ;
F_32 ( V_7 -> V_2 , ( unsigned char ) ( ( V_121 - 1 ) >> 8 ) ) ;
while ( V_121 -- ) {
if ( ! F_32 ( V_7 -> V_2 , * V_131 ++ ) )
goto V_130;
}
if ( F_34 ( V_7 -> V_2 ) )
goto V_130;
if ( V_132 & V_105 ) {
V_43 = 0 ;
while ( 1 ) {
F_32 ( V_7 -> V_2 , 0x03 ) ;
V_133 = F_34 ( V_7 -> V_2 ) ;
if ( V_133 == 0x55 || ++ V_43 >= 10 )
break;
F_40 ( 10 ) ;
}
if ( V_133 != 0x55 ) {
F_22 ( L_10 , V_97 ) ;
goto V_130;
}
} else {
F_41 ( & V_7 -> V_2 -> V_134 ) ;
V_133 = F_42 ( V_7 -> V_2 , V_135 ) ;
F_43 ( & V_7 -> V_2 -> V_134 ) ;
if ( ! ( V_133 & ( V_136 | V_137 | V_138 ) ) ) {
V_10 = ( F_33 ( V_7 -> V_2 , 0xaa , 0x00 ) ||
F_33 ( V_7 -> V_2 , 0xff , 0x00 ) ) ;
F_38 ( V_7 -> V_2 ) ;
if ( V_10 )
goto V_130;
F_29 ( V_7 -> V_2 , 0xc0 ) ;
F_29 ( V_7 -> V_2 , 0x70 ) ;
}
}
V_129 = 0 ;
V_130:
F_30 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
return V_129 ;
}
static int F_25 ( struct V_6 * V_7 , const unsigned char V_66 * V_131 , int V_121 , int V_132 )
{
int V_10 ;
unsigned char * V_139 ;
V_139 = F_44 ( V_131 , V_121 ) ;
if ( F_45 ( V_139 ) )
return F_46 ( V_139 ) ;
V_10 = F_39 ( V_7 , V_139 , V_121 , V_132 ) ;
F_10 ( V_139 ) ;
return V_10 ;
}
static int F_47 ( struct V_6 * V_7 , int V_140 , int V_92 )
{
static const char * const V_141 [] = {
L_11 ,
L_12 ,
L_13 ,
L_14 ,
L_15 ,
} ;
const struct V_142 * V_143 ;
F_48 ( F_8 ( V_141 ) != V_144 ) ;
V_143 = V_7 -> V_46 [ V_140 ] ;
if ( ! V_143 ) {
int V_10 = F_49 ( & V_143 , V_141 [ V_140 ] ,
V_7 -> V_2 -> V_13 -> V_145 ) ;
if ( V_10 < 0 )
return V_10 ;
V_7 -> V_46 [ V_140 ] = V_143 ;
}
return F_39 ( V_7 , V_143 -> V_93 , V_143 -> V_121 , V_92 ) ;
}
static int V_22 ( struct V_6 * V_7 , int V_146 , int V_147 )
{
unsigned long V_92 ;
int V_10 = 0 ;
if ( V_7 -> V_44 & ( V_45 | V_118 ) )
return - V_69 ;
if ( ( ( 1 << V_146 ) & V_7 -> V_57 ) && ( V_147 & V_7 -> V_62 ) ) {
V_7 -> V_44 = V_148 ;
} else {
switch ( V_146 ) {
case V_149 :
V_10 = F_47 ( V_7 , V_150 , 0 ) ;
V_7 -> V_57 = V_111 ;
V_7 -> V_62 = V_151 | V_109 ;
break;
case V_152 :
V_10 = F_47 ( V_7 , V_153 , 0 ) ;
V_7 -> V_57 = V_110 ;
V_7 -> V_62 = V_151 | V_109 ;
break;
case V_154 :
V_10 = F_47 ( V_7 , V_155 ,
V_105 ) ;
if ( V_10 )
break;
if ( V_147 == V_109 ) {
V_10 = F_47
( V_7 , V_156 , 0 ) ;
V_7 -> V_62 = V_109 ;
} else {
V_10 = F_47
( V_7 , V_157 , 0 ) ;
V_7 -> V_62 = V_151 ;
}
V_7 -> V_57 = V_112 ;
break;
default:
if ( V_7 -> V_44 & V_148 ) {
F_28 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
F_29 ( V_7 -> V_2 , 0xfc ) ;
F_29 ( V_7 -> V_2 , 0x00 ) ;
F_30 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
V_7 -> V_44 = 0 ;
}
return - V_53 ;
}
if ( V_10 ) {
V_7 -> V_57 = 0 ;
V_7 -> V_58 = V_7 -> V_59 = V_7 -> V_60 = 0 ;
V_7 -> V_44 = 0 ;
V_7 -> V_62 = 0 ;
return ( V_10 ) ;
} else {
V_7 -> V_44 = V_148 ;
V_7 -> V_59 = V_158 ;
V_7 -> V_58 = V_159 | V_160 ;
V_7 -> V_60 = V_161 ;
}
}
return ( V_7 -> V_44 & V_148 ) ? 0 : - V_119 ;
}
static int V_24 ( struct V_6 * V_7 , int V_73 , int V_74 )
{
unsigned char V_162 ;
unsigned char V_163 , V_164 ;
int V_129 = - V_122 ;
unsigned long V_92 ;
if ( ! ( V_7 -> V_44 & ( V_118 | V_148 ) ) ) {
F_22 ( L_16 , V_97 ) ;
return - V_119 ;
}
if ( V_7 -> V_44 & V_45 ) {
F_22 ( L_17 , V_97 ) ;
return - V_69 ;
}
if ( ! ( V_73 & V_7 -> V_59 ) ) {
F_22 ( L_18 , V_97 ) ;
return - V_53 ;
}
if ( ! ( V_74 & V_7 -> V_58 ) ) {
F_22 ( L_19 , V_97 ) ;
return - V_53 ;
}
F_28 ( & V_7 -> V_2 -> V_134 , V_92 ) ;
V_163 = F_42 ( V_7 -> V_2 , V_165 ) ;
V_164 = F_42 ( V_7 -> V_2 , V_165 + 1 ) ;
F_50 ( V_7 -> V_2 , V_165 , V_163 & 0x7 ) ;
F_50 ( V_7 -> V_2 , V_165 + 1 , V_164 & 0x7 ) ;
F_41 ( & V_7 -> V_2 -> V_117 ) ;
F_29 ( V_7 -> V_2 , 0xc0 ) ;
F_29 ( V_7 -> V_2 , 0x70 ) ;
V_162 = 0x00 ;
if ( V_74 == V_159 )
V_162 = 0x11 ;
if ( V_73 == V_166 )
V_162 |= 0x22 ;
if ( F_33 ( V_7 -> V_2 , 0x81 , V_162 ) ) {
F_22 ( L_20 , V_97 ) ;
goto V_130;
}
if ( F_33 ( V_7 -> V_2 , 0x80 , 0x00 ) ) {
F_22 ( L_21 , V_97 ) ;
goto V_130;
}
V_7 -> V_64 = V_73 ;
V_7 -> V_63 = V_74 ;
V_7 -> V_44 |= V_45 ;
if ( V_7 -> V_62 & V_103 ) {
F_33 ( V_7 -> V_2 , 0xe0 , 0x01 ) ;
F_33 ( V_7 -> V_2 , 0x00 , 0xff ) ;
F_33 ( V_7 -> V_2 , 0x01 , 0xff ) ;
V_7 -> V_44 |= V_167 ;
V_28 ( V_7 ) ;
}
V_129 = 0 ;
V_130:
F_43 ( & V_7 -> V_2 -> V_117 ) ;
F_50 ( V_7 -> V_2 , V_165 , V_163 ) ;
F_50 ( V_7 -> V_2 , V_165 + 1 , V_164 ) ;
F_30 ( & V_7 -> V_2 -> V_134 , V_92 ) ;
return V_129 ;
}
static int V_26 ( struct V_6 * V_7 )
{
int V_129 ;
unsigned char V_163 , V_164 ;
unsigned long V_92 ;
if ( ! ( V_7 -> V_44 & V_45 ) )
return 0 ;
F_28 ( & V_7 -> V_2 -> V_134 , V_92 ) ;
V_163 = F_42 ( V_7 -> V_2 , V_165 ) ;
V_164 = F_42 ( V_7 -> V_2 , V_165 + 1 ) ;
F_50 ( V_7 -> V_2 , V_165 , V_163 & 0x7 ) ;
F_50 ( V_7 -> V_2 , V_165 + 1 , V_164 & 0x7 ) ;
F_41 ( & V_7 -> V_2 -> V_117 ) ;
if ( V_7 -> V_44 & V_167 ) {
F_33 ( V_7 -> V_2 , 0xe0 , 0x01 ) ;
F_33 ( V_7 -> V_2 , 0x00 , 0x00 ) ;
F_33 ( V_7 -> V_2 , 0x01 , 0x00 ) ;
V_7 -> V_44 &= ~ V_167 ;
}
V_129 = F_29 ( V_7 -> V_2 , 0xc0 ) ;
F_43 ( & V_7 -> V_2 -> V_117 ) ;
F_50 ( V_7 -> V_2 , V_165 , V_163 ) ;
F_50 ( V_7 -> V_2 , V_165 + 1 , V_164 ) ;
F_30 ( & V_7 -> V_2 -> V_134 , V_92 ) ;
if ( ! ( V_129 ) )
V_7 -> V_44 &= ~ ( V_168 | V_45 ) ;
return V_129 ;
}
static int F_17 ( struct V_6 * V_7 )
{
int V_129 ;
unsigned long V_92 ;
if ( ! ( V_7 -> V_44 & V_45 ) )
return - V_69 ;
F_28 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
V_129 = F_33 ( V_7 -> V_2 , 0x80 , 0xff ) ;
F_30 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
if ( ! ( V_129 ) )
V_7 -> V_44 |= V_168 ;
return V_129 ;
}
static int F_18 ( struct V_6 * V_7 )
{
int V_129 ;
unsigned long V_92 ;
if ( ! ( V_7 -> V_44 & V_168 ) )
return - V_69 ;
F_28 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
V_129 = F_33 ( V_7 -> V_2 , 0x80 , 0x00 ) ;
F_30 ( & V_7 -> V_2 -> V_117 , V_92 ) ;
if ( ! ( V_129 ) )
V_7 -> V_44 &= ~ V_168 ;
return V_129 ;
}
static int F_51 ( struct V_169 * V_170 , struct V_171 * V_172 )
{
struct V_6 * V_7 = F_52 ( V_170 ) ;
V_172 -> V_173 . integer . V_173 [ 0 ] = V_7 -> V_174 ? 1 : 0 ;
return 0 ;
}
static int F_53 ( struct V_169 * V_170 , struct V_171 * V_172 )
{
struct V_6 * V_7 = F_52 ( V_170 ) ;
unsigned long V_92 ;
int V_175 ;
unsigned char V_176 ;
V_176 = V_172 -> V_173 . integer . V_173 [ 0 ] & 0x01 ;
F_28 ( & V_7 -> V_177 , V_92 ) ;
V_175 = V_7 -> V_174 != V_176 ;
V_7 -> V_174 = V_176 ;
F_30 ( & V_7 -> V_177 , V_92 ) ;
return V_175 ;
}
static int F_54 ( struct V_169 * V_170 , struct V_178 * V_179 )
{
V_179 -> type = V_180 ;
V_179 -> V_181 = 2 ;
V_179 -> V_173 . integer . V_182 = 0 ;
V_179 -> V_173 . integer . V_183 = V_184 ;
return 0 ;
}
static int F_55 ( struct V_169 * V_170 , struct V_171 * V_172 )
{
struct V_6 * V_7 = F_52 ( V_170 ) ;
unsigned long V_92 ;
F_28 ( & V_7 -> V_177 , V_92 ) ;
V_172 -> V_173 . integer . V_173 [ 0 ] = V_7 -> V_185 ;
V_172 -> V_173 . integer . V_173 [ 1 ] = V_7 -> V_186 ;
F_30 ( & V_7 -> V_177 , V_92 ) ;
return 0 ;
}
static int F_56 ( struct V_169 * V_170 , struct V_171 * V_172 )
{
struct V_6 * V_7 = F_52 ( V_170 ) ;
unsigned long V_92 ;
int V_175 ;
unsigned char V_187 , V_188 ;
V_187 = V_172 -> V_173 . integer . V_173 [ 0 ] ;
if ( V_187 > V_184 )
V_187 = V_184 ;
V_188 = V_172 -> V_173 . integer . V_173 [ 1 ] ;
if ( V_188 > V_184 )
V_188 = V_184 ;
F_28 ( & V_7 -> V_177 , V_92 ) ;
V_175 = V_7 -> V_185 != V_187 || V_7 -> V_186 != V_188 ;
V_7 -> V_185 = V_187 ;
V_7 -> V_186 = V_188 ;
V_7 -> V_189 = V_175 ;
F_30 ( & V_7 -> V_177 , V_92 ) ;
return V_175 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_190 * V_13 ;
int V_10 ;
if ( F_11 ( ! V_7 ) )
return - V_53 ;
V_13 = V_7 -> V_2 -> V_13 ;
V_7 -> V_185 = V_7 -> V_186 = V_184 / 2 ;
V_7 -> V_189 = 0 ;
F_57 ( & V_7 -> V_177 ) ;
if ( ( V_10 = F_58 ( V_13 , V_7 -> V_191 = F_59 ( & V_192 , V_7 ) ) ) < 0 )
goto V_193;
if ( ( V_10 = F_58 ( V_13 , V_7 -> V_194 = F_59 ( & V_195 , V_7 ) ) ) < 0 )
goto V_193;
return 0 ;
V_193:
F_24 ( V_7 ) ;
return V_10 ;
}
static void F_24 ( struct V_6 * V_7 )
{
struct V_190 * V_13 ;
unsigned long V_92 ;
if ( F_11 ( ! V_7 ) )
return;
V_13 = V_7 -> V_2 -> V_13 ;
F_60 ( & V_13 -> V_196 ) ;
if ( V_7 -> V_191 )
F_61 ( V_13 , V_7 -> V_191 ) ;
if ( V_7 -> V_194 )
F_61 ( V_13 , V_7 -> V_194 ) ;
F_62 ( & V_13 -> V_196 ) ;
F_28 ( & V_7 -> V_177 , V_92 ) ;
V_7 -> V_189 = 0 ;
F_30 ( & V_7 -> V_177 , V_92 ) ;
}
static int V_28 ( struct V_6 * V_7 )
{
int V_10 = - V_119 ;
F_41 ( & V_7 -> V_177 ) ;
if ( V_7 -> V_44 & V_167 ) {
F_33 ( V_7 -> V_2 , 0xe0 , 0x01 ) ;
F_33 ( V_7 -> V_2 , 0x00 , V_7 -> V_185 ) ;
F_33 ( V_7 -> V_2 , 0x02 , 0x00 ) ;
F_33 ( V_7 -> V_2 , 0x00 , V_7 -> V_186 ) ;
F_33 ( V_7 -> V_2 , 0x03 , 0x00 ) ;
V_10 = 0 ;
}
V_7 -> V_189 = 0 ;
F_43 ( & V_7 -> V_177 ) ;
return V_10 ;
}
static int F_7 ( struct V_6 * V_7 , int V_3 )
{
char V_30 [ 16 ] ;
struct V_197 * V_198 ;
sprintf ( V_30 , L_22 , V_3 ) ;
if ( ! F_63 ( V_7 -> V_2 -> V_13 , V_30 , & V_198 ) )
F_64 ( V_198 , V_7 , V_199 ) ;
return 0 ;
}
static void V_199 ( struct V_197 * V_198 , struct V_200 * V_201 )
{
struct V_6 * V_7 = V_198 -> V_33 ;
F_65 ( V_201 , L_23 , ( V_7 -> V_9 >> 4 ) , ( V_7 -> V_9 & 0x0f ) ) ;
F_65 ( V_201 , L_24 , ( ( V_7 -> V_44 & V_167 ) ? 'Q' : '-' ) ,
( ( V_7 -> V_44 & V_168 ) ? 'P' : '-' ) ,
( ( V_7 -> V_44 & V_45 ) ? 'R' : '-' ) ,
( ( V_7 -> V_44 & V_118 ) ? 'L' : '-' ) ) ;
if ( V_7 -> V_44 & V_118 ) {
F_65 ( V_201 , L_25 , V_7 -> V_55 , V_7 -> V_56 ) ;
F_65 ( V_201 , L_26 ) ;
if ( V_7 -> V_60 == V_161 ) {
F_65 ( V_201 , L_27 ) ;
} else {
F_65 ( V_201 , L_28 ,
( ( V_7 -> V_60 & V_202 ) ? L_29 : L_30 ) ,
( ( V_7 -> V_60 & V_203 ) ? L_31 : L_30 ) ,
( ( V_7 -> V_60 & V_204 ) ? L_32 : L_30 ) ,
( ( V_7 -> V_60 & V_205 ) ? L_33 : L_30 ) ) ;
}
if ( V_7 -> V_62 == V_103 ) {
F_65 ( V_201 , L_34 ,
V_7 -> V_174 ? L_35 : L_36 ) ;
} else {
F_65 ( V_201 , L_37 ,
V_7 -> V_57 ,
( ( V_7 -> V_59 & V_158 ) ? L_38 : L_39 ) ,
( ( V_7 -> V_59 & V_166 ) ? L_40 : L_39 ) ,
( ( V_7 -> V_58 & V_159 ) ? L_41 : L_39 ) ,
( ( V_7 -> V_58 & V_160 ) ? L_42 : L_39 ) ,
( ( V_7 -> V_62 & V_109 ) ? L_43 : L_39 ) ,
( ( V_7 -> V_62 & V_151 ) ? L_44 : L_39 ) ) ;
}
}
if ( V_7 -> V_44 & V_148 ) {
F_65 ( V_201 , L_45 ) ;
}
if ( V_7 -> V_44 & V_45 ) {
F_65 ( V_201 , L_46 ,
( ( V_7 -> V_64 & V_158 ) ? 16 : 8 ) ,
( ( V_7 -> V_63 & V_159 ) ? L_41 : L_42 ) ) ;
}
if ( V_7 -> V_44 & V_167 ) {
F_65 ( V_201 , L_47 ,
V_7 -> V_185 , V_7 -> V_186 ) ;
}
}
static int T_2 F_66 ( void )
{
return 0 ;
}
static void T_3 F_67 ( void )
{
}
