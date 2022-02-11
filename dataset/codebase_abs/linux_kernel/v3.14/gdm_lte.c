static int F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 ) ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( V_2 -> V_5 & V_6 )
return - V_7 ;
return 0 ;
}
static void F_6 ( void * V_8 )
{
struct V_9 * V_9 = V_8 ;
if ( F_7 ( V_9 -> V_10 ) )
F_8 ( V_9 -> V_10 ) ;
}
static int F_9 ( struct V_11 * V_12 , struct V_9 * V_9 , int V_13 )
{
int V_14 ;
V_14 = F_10 ( V_12 ) ;
if ( V_14 == V_15 ) {
V_9 -> V_16 . V_17 ++ ;
} else {
V_9 -> V_16 . V_18 ++ ;
V_9 -> V_16 . V_19 += V_12 -> V_20 + V_21 ;
}
return 0 ;
}
static int F_11 ( struct V_11 * V_22 , T_1 V_13 )
{
struct V_9 * V_9 = F_12 ( V_22 -> V_2 ) ;
struct V_11 * V_23 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
struct V_28 * V_29 ;
struct V_28 * V_30 ;
struct V_31 {
T_2 V_32 [ V_33 ] ;
T_2 V_34 [ 4 ] ;
T_2 V_35 [ V_33 ] ;
T_2 V_36 [ 4 ] ;
};
struct V_31 * V_37 ;
struct V_31 * V_38 ;
T_2 V_39 [ 60 ] ;
void * V_40 ;
T_1 V_41 ;
if ( F_13 ( ( (struct V_24 * ) V_22 -> V_42 ) -> V_43 ) == V_44 ) {
memcpy ( & V_27 , V_22 -> V_42 , sizeof( struct V_26 ) ) ;
V_40 = & V_27 ;
V_41 = V_45 ;
} else {
memcpy ( & V_25 , V_22 -> V_42 , sizeof( struct V_24 ) ) ;
V_40 = & V_25 ;
V_41 = V_21 ;
}
V_29 = (struct V_28 * ) ( V_22 -> V_42 + V_41 ) ;
V_37 = (struct V_31 * ) ( V_22 -> V_42 + V_41 + sizeof( struct V_28 ) ) ;
V_30 = (struct V_28 * ) V_39 ;
V_38 = (struct V_31 * ) ( V_39 + sizeof( struct V_28 ) ) ;
memcpy ( V_30 , V_29 , sizeof( struct V_28 ) ) ;
V_30 -> V_46 = F_14 ( V_47 ) ;
V_38 -> V_32 [ 0 ] = V_37 -> V_32 [ 0 ] ;
V_38 -> V_32 [ 1 ] = V_37 -> V_32 [ 1 ] ;
memcpy ( & V_38 -> V_32 [ 2 ] , & V_37 -> V_36 [ 0 ] , 4 ) ;
memcpy ( & V_38 -> V_34 [ 0 ] , & V_37 -> V_36 [ 0 ] , 4 ) ;
memcpy ( & V_38 -> V_35 [ 0 ] , & V_37 -> V_32 [ 0 ] , 6 ) ;
memcpy ( & V_38 -> V_36 [ 0 ] , & V_37 -> V_34 [ 0 ] , 4 ) ;
memcpy ( V_40 , V_40 + V_33 , V_33 ) ;
memcpy ( V_40 + V_33 , V_9 -> V_48 , V_33 ) ;
V_23 = F_15 ( V_22 -> V_20 ) ;
if ( ! V_23 )
return - V_49 ;
F_16 ( V_23 , V_50 ) ;
memcpy ( F_17 ( V_23 , V_41 ) , V_40 , V_41 ) ;
memcpy ( F_17 ( V_23 , sizeof( struct V_28 ) ) , V_30 , sizeof( struct V_28 ) ) ;
memcpy ( F_17 ( V_23 , sizeof( struct V_31 ) ) , V_38 , sizeof( struct V_31 ) ) ;
V_23 -> V_51 = ( (struct V_24 * ) V_40 ) -> V_43 ;
V_23 -> V_2 = V_22 -> V_2 ;
F_18 ( V_23 ) ;
F_19 ( V_23 , V_21 ) ;
F_9 ( V_23 , V_9 , V_13 ) ;
return 0 ;
}
static int F_20 ( struct V_52 * V_53 , T_3 * V_54 , int V_20 )
{
unsigned short * V_55 = V_54 ;
int V_56 = 0 ;
int V_57 ;
union {
struct {
T_2 V_58 [ 16 ] ;
T_2 V_59 [ 16 ] ;
T_1 V_60 ;
T_2 V_61 [ 3 ] ;
T_2 V_62 ;
} V_63 V_64 ;
T_3 V_65 [ 20 ] ;
} V_66 ;
memset ( & V_66 , 0 , sizeof( V_66 ) ) ;
memcpy ( & V_66 . V_63 . V_58 , & V_53 -> V_67 . V_68 . V_69 , 16 ) ;
memcpy ( & V_66 . V_63 . V_59 , & V_53 -> V_70 . V_68 . V_69 , 16 ) ;
V_66 . V_63 . V_60 = V_53 -> V_71 ;
V_66 . V_63 . V_62 = V_53 -> V_72 ;
V_55 = ( T_3 * ) & V_66 ;
for ( V_57 = 0 ; V_57 < sizeof( V_66 . V_65 ) / sizeof( V_66 . V_65 [ 0 ] ) ; V_57 ++ )
V_56 += V_66 . V_65 [ V_57 ] ;
V_55 = V_54 ;
while ( V_20 > 1 ) {
V_56 += * V_55 ++ ;
V_20 -= 2 ;
}
V_56 = ( V_56 >> 16 ) + ( V_56 & 0xFFFF ) ;
V_56 += ( V_56 >> 16 ) ;
V_56 = ~ V_56 & 0xffff ;
return V_56 ;
}
static int F_21 ( struct V_11 * V_22 , T_1 V_13 )
{
struct V_9 * V_9 = F_12 ( V_22 -> V_2 ) ;
struct V_11 * V_23 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
struct V_73 {
T_2 V_74 [ 16 ] ;
T_2 type ;
T_2 V_75 ;
T_2 V_76 [ 6 ] ;
};
struct V_73 V_77 ;
struct V_78 {
T_2 V_74 [ 16 ] ;
};
struct V_78 * V_79 ;
struct V_52 * V_80 ;
struct V_52 V_81 ;
struct V_82 * V_83 ;
struct V_82 V_84 ;
void * V_40 ;
T_1 V_41 ;
if ( F_13 ( ( (struct V_24 * ) V_22 -> V_42 ) -> V_43 ) == V_44 ) {
memcpy ( & V_27 , V_22 -> V_42 , sizeof( struct V_26 ) ) ;
if ( F_13 ( V_27 . V_85 ) != V_86 )
return - 1 ;
V_40 = & V_27 ;
V_41 = V_45 ;
} else {
memcpy ( & V_25 , V_22 -> V_42 , sizeof( struct V_24 ) ) ;
if ( F_13 ( V_25 . V_43 ) != V_86 )
return - 1 ;
V_40 = & V_25 ;
V_41 = V_21 ;
}
V_80 = (struct V_52 * ) ( V_22 -> V_42 + V_41 ) ;
if ( V_80 -> V_87 != 6 || V_80 -> V_72 != V_88 )
return - 1 ;
V_83 = (struct V_82 * ) ( V_22 -> V_42 + V_41 + sizeof( struct V_52 ) ) ;
if ( V_83 -> V_89 == V_90 ) {
return - 1 ;
} else if ( V_83 -> V_89 == V_91 ) {
T_2 V_92 [ sizeof( struct V_82 ) + sizeof( struct V_73 ) ] ;
T_2 V_93 [ 16 ] = { 0 ,} ;
if ( memcmp ( V_80 -> V_67 . V_68 . V_69 , V_93 , 16 ) == 0 )
return 0 ;
V_84 . V_89 = V_94 ;
V_84 . V_95 = 0 ;
V_84 . V_96 = 0 ;
V_84 . V_97 . V_98 [ 0 ] = F_22 ( 0x60000000 ) ;
V_79 = (struct V_78 * ) ( V_22 -> V_42 + V_41 + sizeof( struct V_52 ) + sizeof( struct V_82 ) ) ;
memcpy ( & V_77 . V_74 , V_79 -> V_74 , 16 ) ;
V_77 . type = 0x02 ;
V_77 . V_75 = 1 ;
V_77 . V_76 [ 0 ] = 0x00 ;
V_77 . V_76 [ 1 ] = 0x0a ;
V_77 . V_76 [ 2 ] = 0x3b ;
V_77 . V_76 [ 3 ] = 0xaf ;
V_77 . V_76 [ 4 ] = 0x63 ;
V_77 . V_76 [ 5 ] = 0xc7 ;
memcpy ( & V_81 , V_80 , sizeof( struct V_52 ) ) ;
memcpy ( V_81 . V_67 . V_68 . V_69 , & V_77 . V_74 , 16 ) ;
memcpy ( V_81 . V_70 . V_68 . V_69 , V_80 -> V_67 . V_68 . V_69 , 16 ) ;
V_81 . V_71 = F_14 ( sizeof( struct V_82 ) + sizeof( struct V_73 ) ) ;
memcpy ( V_92 , & V_84 , sizeof( struct V_82 ) ) ;
memcpy ( V_92 + sizeof( struct V_82 ) , & V_77 , sizeof( struct V_73 ) ) ;
V_84 . V_96 = F_20 ( & V_81 , ( T_3 * ) V_92 , sizeof( V_92 ) ) ;
} else {
return - 1 ;
}
memcpy ( V_40 , V_40 + V_33 , V_33 ) ;
memcpy ( V_40 + V_33 , V_9 -> V_48 , V_33 ) ;
V_23 = F_15 ( V_22 -> V_20 ) ;
if ( ! V_23 )
return - V_49 ;
F_16 ( V_23 , V_50 ) ;
memcpy ( F_17 ( V_23 , V_41 ) , V_40 , V_41 ) ;
memcpy ( F_17 ( V_23 , sizeof( struct V_52 ) ) , & V_81 , sizeof( struct V_52 ) ) ;
memcpy ( F_17 ( V_23 , sizeof( struct V_82 ) ) , & V_84 , sizeof( struct V_82 ) ) ;
memcpy ( F_17 ( V_23 , sizeof( struct V_73 ) ) , & V_77 , sizeof( struct V_73 ) ) ;
V_23 -> V_51 = ( (struct V_24 * ) V_40 ) -> V_43 ;
V_23 -> V_2 = V_22 -> V_2 ;
F_18 ( V_23 ) ;
F_19 ( V_23 , V_21 ) ;
F_9 ( V_23 , V_9 , V_13 ) ;
return 0 ;
}
static T_4 F_23 ( struct V_1 * V_2 , struct V_11 * V_12 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_99 * V_100 ;
struct V_52 * V_53 ;
int V_101 ;
void * V_102 ;
T_1 V_13 = 0 ;
V_13 = 0x00000010 | V_9 -> V_103 ;
V_25 = (struct V_24 * ) V_12 -> V_42 ;
if ( F_13 ( V_25 -> V_43 ) == V_44 ) {
V_27 = (struct V_26 * ) V_12 -> V_42 ;
V_101 = F_13 ( V_27 -> V_85 ) ;
V_102 = V_12 -> V_42 + V_45 ;
V_13 |= V_104 ;
} else {
V_101 = F_13 ( V_25 -> V_43 ) ;
V_102 = V_12 -> V_42 + V_21 ;
}
switch ( V_101 ) {
case V_105 :
V_13 |= V_106 ;
break;
case V_107 :
V_13 |= V_108 ;
V_100 = (struct V_99 * ) V_102 ;
if ( V_100 -> V_51 == V_109 ) {
struct V_110 * V_111 = (struct V_110 * ) ( V_102 + sizeof( struct V_99 ) ) ;
if ( F_13 ( V_111 -> V_112 ) == 67 || F_13 ( V_111 -> V_112 ) == 68 )
V_13 |= V_113 ;
}
break;
case V_86 :
V_13 |= V_114 ;
V_53 = (struct V_52 * ) V_102 ;
if ( V_53 -> V_72 == V_88 ) {
struct V_82 * V_115 = (struct V_82 * ) ( V_102 + sizeof( struct V_52 ) ) ;
if (
V_115 -> V_89 == V_91 )
V_13 |= V_116 ;
} else if ( V_53 -> V_72 == V_109 ) {
struct V_110 * V_111 = (struct V_110 * ) ( V_102 + sizeof( struct V_52 ) ) ;
if ( F_13 ( V_111 -> V_112 ) == 546 || F_13 ( V_111 -> V_112 ) == 547 )
V_13 |= V_113 ;
}
break;
default:
break;
}
return V_13 ;
}
static int F_24 ( struct V_11 * V_12 , struct V_1 * V_2 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
T_1 V_13 ;
void * V_117 ;
int V_118 ;
int V_119 ;
int V_14 = 0 ;
V_13 = F_23 ( V_2 , V_12 ) ;
if ( V_13 == 0 ) {
F_25 ( V_2 , L_1 ) ;
return - 1 ;
}
if ( V_13 & V_106 ) {
if ( F_11 ( V_12 , V_13 ) == 0 ) {
F_26 ( V_12 ) ;
return 0 ;
}
}
if ( V_13 & V_116 ) {
if ( F_21 ( V_12 , V_13 ) == 0 ) {
F_26 ( V_12 ) ;
return 0 ;
}
}
if ( V_13 & V_104 ) {
struct V_26 * V_27 = (struct V_26 * ) V_12 -> V_42 ;
V_9 -> V_120 = F_13 ( V_27 -> V_121 ) & V_122 ;
V_117 = V_12 -> V_42 + ( V_45 - V_21 ) ;
V_118 = V_12 -> V_20 - ( V_45 - V_21 ) ;
} else {
V_9 -> V_120 = 0 ;
V_117 = V_12 -> V_42 ;
V_118 = V_12 -> V_20 ;
}
if ( V_13 & V_116 )
V_13 = V_116 ;
if ( ! ( V_13 & V_113 ) )
V_13 &= V_123 ;
sscanf ( V_2 -> V_124 , L_2 , & V_119 ) ;
V_14 = V_9 -> V_125 -> V_126 ( V_9 -> V_125 -> V_127 ,
V_117 , V_118 ,
V_9 -> V_128 . V_129 , 0 ,
F_6 , V_9 , V_119 ,
V_13 ) ;
if ( V_14 == V_130 || V_14 == V_131 ) {
F_4 ( V_2 ) ;
if ( V_14 == V_130 )
V_14 = 0 ;
else
V_14 = - V_132 ;
} else if ( V_14 == V_133 ) {
V_14 = - V_134 ;
}
if ( V_14 ) {
V_9 -> V_16 . V_135 ++ ;
} else {
V_9 -> V_16 . V_136 ++ ;
V_9 -> V_16 . V_137 += V_118 ;
}
F_26 ( V_12 ) ;
return 0 ;
}
static struct V_138 * F_27 ( struct V_1 * V_2 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
return & V_9 -> V_16 ;
}
static int F_28 ( struct V_1 * V_2 , char * V_139 , int V_20 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
struct V_140 * V_141 = (struct V_140 * ) V_139 ;
int V_119 ;
sscanf ( V_2 -> V_124 , L_2 , & V_119 ) ;
return F_29 ( V_142 . V_143 , V_119 , 0 , V_139 ,
F_30 (
V_9 -> V_125 -> V_144 (
V_9 -> V_125 -> V_127 ) , V_141 -> V_20 )
+ V_145 ) ;
}
static void F_31 ( struct V_1 * V_2 , T_3 type , void * V_146 , int V_20 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
V_9 -> V_125 -> V_147 ( V_9 -> V_125 -> V_127 , V_146 , V_20 , NULL ,
NULL ) ;
}
int F_32 ( void )
{
if ( V_142 . V_148 == 0 )
V_142 . V_143 = F_33 ( V_149 , F_31 ) ;
if ( V_142 . V_143 ) {
V_142 . V_148 ++ ;
return 0 ;
}
F_34 ( L_3 ) ;
return - 1 ;
}
void F_35 ( void )
{
if ( V_142 . V_143 && -- V_142 . V_148 == 0 ) {
F_36 ( V_142 . V_143 ) ;
V_142 . V_143 = NULL ;
}
}
static T_2 F_37 ( T_1 V_13 )
{
T_2 V_150 ;
V_150 = ( T_2 ) ( V_13 & 0x0000000f ) ;
if ( V_150 > V_151 )
V_150 = 0 ;
return V_150 ;
}
static void F_38 ( struct V_1 * V_2 , char * V_139 , int V_20 , int V_152 )
{
T_1 V_13 ;
struct V_9 * V_9 ;
struct V_11 * V_12 ;
struct V_24 V_25 ;
struct V_26 V_27 ;
void * V_40 ;
T_1 V_41 ;
char V_153 = 0 ;
V_13 = V_152 & V_123 ;
V_9 = F_12 ( V_2 ) ;
if ( V_152 & V_113 ) {
if ( V_152 & V_108 ) {
struct V_154 {
T_2 V_155 ;
T_2 V_156 ;
T_2 V_157 ;
T_2 V_158 ;
T_1 V_159 ;
T_3 V_160 ;
T_3 V_5 ;
#define F_39 0x8000
T_1 V_161 ;
T_1 V_162 ;
T_1 V_163 ;
T_1 V_164 ;
T_2 V_165 [ 16 ] ;
T_2 V_166 [ 64 ] ;
T_2 V_167 [ 128 ] ;
T_1 V_168 ;
} V_64 ;
void * V_169 = V_139 + sizeof( struct V_99 ) + sizeof( struct V_110 ) + F_40 ( struct V_154 , V_165 ) ;
memcpy ( V_9 -> V_170 , V_169 , V_33 ) ;
}
}
if ( V_9 -> V_120 > 0 ) {
V_40 = ( void * ) & V_27 ;
V_41 = V_45 ;
} else {
V_40 = ( void * ) & V_25 ;
V_41 = V_21 ;
}
memcpy ( V_40 , V_9 -> V_170 , V_33 ) ;
memcpy ( V_40 + V_33 , V_9 -> V_48 , V_33 ) ;
V_27 . V_121 = F_14 ( V_9 -> V_120 ) ;
V_27 . V_171 = F_14 ( V_44 ) ;
if ( V_13 == V_106 ) {
V_25 . V_43 = F_14 ( V_105 ) ;
V_27 . V_85 = F_14 ( V_105 ) ;
} else {
V_153 = V_139 [ 0 ] >> 4 ;
if ( V_153 == V_172 ) {
V_25 . V_43 = F_14 ( V_107 ) ;
V_27 . V_85 = F_14 ( V_107 ) ;
} else if ( V_153 == V_173 ) {
V_25 . V_43 = F_14 ( V_86 ) ;
V_27 . V_85 = F_14 ( V_86 ) ;
} else {
F_25 ( V_2 , L_4 , V_153 ) ;
return;
}
}
V_12 = F_15 ( V_20 + V_41 + V_50 ) ;
if ( ! V_12 )
return;
F_16 ( V_12 , V_50 ) ;
memcpy ( F_17 ( V_12 , V_41 ) , V_40 , V_41 ) ;
memcpy ( F_17 ( V_12 , V_20 ) , V_139 , V_20 ) ;
V_12 -> V_51 = ( (struct V_24 * ) V_40 ) -> V_43 ;
V_12 -> V_2 = V_2 ;
F_18 ( V_12 ) ;
F_19 ( V_12 , V_21 ) ;
F_9 ( V_12 , V_9 , V_13 ) ;
}
static void F_41 ( struct V_125 * V_125 , char * V_139 , int V_20 )
{
struct V_1 * V_2 ;
struct V_174 * V_174 = (struct V_174 * ) V_139 ;
struct V_175 * V_175 = NULL ;
T_2 * V_42 = ( T_2 * ) V_174 -> V_42 ;
T_3 V_57 = 0 ;
T_3 V_176 ;
T_3 V_177 ;
T_3 V_178 ;
T_1 V_13 ;
T_2 V_150 ;
V_177 = F_30 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_174 -> V_20 ) ;
V_176 = F_30 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_174 -> V_176 ) ;
for ( V_57 = 0 ; V_57 < V_176 ; V_57 ++ ) {
V_175 = (struct V_175 * ) V_42 ;
V_178 = F_30 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_175 -> V_178 ) ;
V_177 = F_30 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_175 -> V_20 ) ;
V_13 = F_42 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_175 -> V_13 ) ;
if ( V_178 != V_179 ) {
F_34 ( L_5 , V_178 ) ;
return;
}
if ( V_177 < 12 ) {
F_34 ( L_6 , V_177 ) ;
return;
}
V_150 = F_37 ( V_13 ) ;
if ( V_150 < V_151 ) {
V_2 = V_125 -> V_2 [ V_150 ] ;
F_38 ( V_2 , ( char * ) V_175 -> V_42 , ( int ) ( V_177 - 12 ) , V_13 ) ;
} else {
F_34 ( L_7 , V_13 ) ;
}
V_42 += ( ( V_177 + 3 ) & 0xfffc ) + V_145 ;
}
}
static void F_43 ( struct V_1 * V_2 , char * V_139 , int V_20 )
{
struct V_9 * V_9 = F_12 ( V_2 ) ;
struct V_180 * V_128 = (struct V_180 * ) V_139 ;
if ( V_128 -> V_181 ) {
V_9 -> V_128 . V_181 = V_128 -> V_181 ;
V_9 -> V_128 . V_129 = F_42 (
V_9 -> V_125 -> V_144 (
V_9 -> V_125 -> V_127 ) ,
V_128 -> V_129 ) ;
V_9 -> V_128 . V_13 = F_42 (
V_9 -> V_125 -> V_144 (
V_9 -> V_125 -> V_127 ) ,
V_128 -> V_13 ) ;
F_44 ( V_2 , L_8 ,
V_9 -> V_128 . V_13 ) ;
} else {
memset ( & V_9 -> V_128 , 0x00 , sizeof( struct V_128 ) ) ;
F_44 ( V_2 , L_9 ) ;
}
}
static int F_45 ( struct V_125 * V_125 , char * V_139 , int V_20 )
{
struct V_140 * V_141 = (struct V_140 * ) V_139 ;
struct V_180 * V_128 = (struct V_180 * ) V_139 ;
struct V_175 * V_175 ;
struct V_1 * V_2 ;
int V_14 = 0 ;
T_3 V_178 ;
T_1 V_13 ;
T_2 V_150 ;
if ( ! V_20 )
return V_14 ;
V_178 = F_30 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_141 -> V_178 ) ;
V_2 = V_125 -> V_2 [ 0 ] ;
if ( V_2 == NULL )
return 0 ;
switch ( V_178 ) {
case V_179 :
V_175 = (struct V_175 * ) V_141 -> V_42 ;
V_13 = F_42 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_175 -> V_13 ) ;
V_150 = F_37 ( V_13 ) ;
V_2 = V_125 -> V_2 [ V_150 ] ;
F_38 ( V_2 , V_141 -> V_42 , V_20 , V_13 ) ;
break;
case V_182 :
F_41 ( V_125 , V_139 , V_20 ) ;
break;
case V_183 :
F_44 ( V_2 , L_10 ,
( (struct V_184 * ) V_139 ) -> V_185
? L_11 : L_12 ) ;
break;
case V_186 :
V_128 = (struct V_180 * ) V_139 ;
V_13 = F_42 ( V_125 -> V_144 ( V_125 -> V_127 ) , V_128 -> V_13 ) ;
V_150 = F_37 ( V_13 ) ;
V_2 = V_125 -> V_2 [ V_150 ] ;
F_43 ( V_2 , V_139 , V_20 ) ;
default:
V_14 = F_28 ( V_2 , V_139 , V_20 ) ;
break;
}
return V_14 ;
}
static int F_46 ( void * V_8 , void * V_42 , int V_20 , int V_187 )
{
struct V_125 * V_125 = (struct V_125 * ) V_8 ;
return F_45 ( V_125 , ( char * ) V_42 , V_20 ) ;
}
void F_47 ( struct V_125 * V_125 )
{
int V_57 ;
for ( V_57 = 0 ; V_57 < V_188 ; V_57 ++ )
V_125 -> V_189 ( V_125 -> V_127 , F_46 , V_125 , V_190 ) ;
}
static void F_48 ( T_2 * V_191 , T_2 * V_192 , T_2 * V_193 , T_2 * V_194 , T_2 V_150 )
{
if ( ! V_194 )
memcpy ( V_191 , V_195 , V_33 ) ;
else
memcpy ( V_191 , V_194 , V_33 ) ;
V_191 [ V_33 - 1 ] += V_150 ;
F_49 ( V_192 ) ;
memcpy ( V_192 , V_191 , 3 ) ;
memcpy ( V_193 , V_191 , V_33 ) ;
}
static void F_50 ( T_2 * V_194 )
{
if ( F_51 ( V_194 ) || ( V_194 [ 0 ] & 0x01 ) ) {
F_34 ( L_13 ) ;
memcpy ( V_194 , V_195 , 6 ) ;
}
}
int F_52 ( struct V_125 * V_125 , struct V_196 * V_2 , T_2 * V_194 )
{
struct V_9 * V_9 ;
struct V_1 * V_197 ;
char V_198 [ 16 ] ;
int V_14 = 0 ;
T_2 V_150 ;
F_50 ( V_194 ) ;
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
sprintf ( V_198 , L_14 , V_150 ) ;
V_197 = F_53 ( sizeof( struct V_9 ) , V_198 , V_199 ) ;
if ( V_197 == NULL ) {
F_34 ( L_15 ) ;
V_14 = - V_49 ;
goto V_200;
}
V_197 -> V_201 = & V_202 ;
V_197 -> V_5 &= ~ V_203 ;
V_197 -> V_204 = V_205 ;
V_9 = F_12 ( V_197 ) ;
memset ( V_9 , 0 , sizeof( struct V_9 ) ) ;
V_9 -> V_10 = V_197 ;
V_9 -> V_125 = V_125 ;
V_9 -> V_103 = V_150 ;
F_48 (
V_197 -> V_191 ,
V_9 -> V_48 ,
V_9 -> V_170 ,
V_194 ,
V_150 ) ;
F_54 ( V_197 , V_2 ) ;
F_55 ( V_197 , & V_206 ) ;
V_14 = F_56 ( V_197 ) ;
if ( V_14 )
goto V_200;
F_57 ( V_197 ) ;
V_125 -> V_2 [ V_150 ] = V_197 ;
}
return 0 ;
V_200:
F_58 ( V_125 ) ;
return V_14 ;
}
void F_58 ( struct V_125 * V_125 )
{
struct V_1 * V_197 ;
int V_150 ;
for ( V_150 = 0 ; V_150 < V_151 ; V_150 ++ ) {
V_197 = V_125 -> V_2 [ V_150 ] ;
if ( V_197 == NULL )
continue;
F_59 ( V_197 ) ;
F_60 ( V_197 ) ;
}
}
