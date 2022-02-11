static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return V_3 -> V_4 ;
}
static void F_2 ( struct V_5 * V_6 , T_1 V_7 )
{
if ( ! V_7 )
return;
if ( ! F_3 ( V_6 ) ) {
F_4 ( V_6 , V_7 ) ;
return;
}
F_5 ( V_6 ) -> V_7 = F_6 ( V_7 , F_5 ( V_6 ) -> V_8 ) ;
F_7 ( V_6 ) -> V_7 = V_7 - F_5 ( V_6 ) -> V_7 ;
}
static void F_8 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_12 * V_13 = & V_11 -> V_13 . V_11 ;
F_9 ( & V_6 -> V_14 -> V_15 ,
L_1 ,
V_6 , V_13 -> V_16 , V_13 -> V_17 , V_13 -> V_18 ) ;
V_6 -> V_19 = V_13 -> V_17 ;
F_2 ( V_6 , V_13 -> V_7 ) ;
switch ( V_13 -> V_16 ) {
case V_20 :
F_10 ( V_6 , V_21 ) ;
break;
case V_22 :
F_10 ( V_6 , V_23 ) ;
break;
case V_24 :
F_10 ( V_6 , V_25 ) ;
break;
case V_26 :
F_10 ( V_6 , V_27 ) ;
break;
case V_28 :
F_10 ( V_6 , V_29 ) ;
break;
case V_30 :
F_10 ( V_6 , V_31 ) ;
break;
case V_32 :
F_10 ( V_6 , V_33 ) ;
break;
case V_34 :
F_10 ( V_6 , V_35 ) ;
break;
case V_36 :
F_10 ( V_6 , V_37 ) ;
break;
default:
F_11 ( V_38 , V_6 , L_2 ,
V_13 -> V_16 ) ;
case V_39 :
F_10 ( V_6 , V_23 ) ;
break;
}
F_12 ( V_13 -> V_18 > V_40 ) ;
if ( V_6 -> V_41 ) {
memcpy ( V_6 -> V_41 , V_13 -> V_42 ,
F_13 ( T_1 , V_13 -> V_18 , V_40 ) ) ;
if ( V_13 -> V_18 )
F_14 ( V_6 , V_43 ) ;
}
F_15 ( V_11 , V_44 ) ;
V_6 -> V_45 ( V_6 ) ;
}
static void F_16 ( struct V_46 * V_47 , void (* F_17)( void * V_9 ) )
{
void * V_9 ;
unsigned int V_48 ;
do {
F_18 ( V_47 ) ;
while ( ( V_9 = F_19 ( V_47 , & V_48 ) ) != NULL )
F_17 ( V_9 ) ;
} while ( ! F_20 ( V_47 ) );
}
static void F_21 ( struct V_46 * V_47 )
{
struct V_1 * V_49 = F_1 ( V_47 -> V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
unsigned long V_52 ;
F_23 ( & V_51 -> V_53 . V_54 , V_52 ) ;
F_16 ( V_47 , F_8 ) ;
F_24 ( & V_51 -> V_53 . V_54 , V_52 ) ;
}
static void F_25 ( void * V_9 )
{
struct V_10 * V_11 = V_9 ;
if ( V_11 -> V_55 )
F_26 ( V_11 -> V_55 ) ;
else
F_15 ( V_11 , V_44 ) ;
}
static void F_27 ( struct V_46 * V_47 )
{
struct V_1 * V_49 = F_1 ( V_47 -> V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
unsigned long V_52 ;
F_23 ( & V_51 -> V_56 . V_54 , V_52 ) ;
F_16 ( V_47 , F_25 ) ;
F_24 ( & V_51 -> V_56 . V_54 , V_52 ) ;
}
static int F_28 ( struct V_50 * V_51 ,
struct V_57 * V_58 )
{
int V_59 ;
struct V_60 V_61 ;
unsigned long V_52 ;
F_29 ( & V_61 , & V_58 -> V_62 , sizeof( struct V_63 ) ) ;
F_23 ( & V_51 -> V_64 . V_54 , V_52 ) ;
V_59 = F_30 ( V_51 -> V_64 . V_47 , & V_61 , 0 , 1 , V_58 , V_65 ) ;
if ( V_59 >= 0 )
F_31 ( V_51 -> V_64 . V_47 ) ;
F_24 ( & V_51 -> V_64 . V_54 , V_52 ) ;
return V_59 ;
}
static int F_32 ( struct V_50 * V_51 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ ) {
V_51 -> V_68 [ V_66 ] . V_51 = V_51 ;
F_28 ( V_51 , & V_51 -> V_68 [ V_66 ] ) ;
}
return 0 ;
}
static void F_33 ( struct V_50 * V_51 )
{
int V_66 ;
for ( V_66 = 0 ; V_66 < V_67 ; V_66 ++ )
F_34 ( & V_51 -> V_68 [ V_66 ] . V_69 ) ;
}
static void F_35 ( struct V_50 * V_51 ,
struct V_63 * V_62 )
{
struct V_70 * V_71 ;
struct V_1 * V_72 = F_1 ( V_51 -> V_3 ) ;
unsigned int V_73 = V_62 -> V_74 [ 1 ] ;
unsigned int V_74 = ( V_62 -> V_74 [ 2 ] << 8 ) | V_62 -> V_74 [ 3 ] ;
switch ( V_62 -> V_75 ) {
case V_76 :
F_36 ( V_72 , 0 , V_73 , V_74 ) ;
break;
case V_77 :
V_71 = F_37 ( V_72 , 0 , V_73 , V_74 ) ;
if ( V_71 ) {
F_38 ( V_71 ) ;
F_39 ( V_71 ) ;
} else {
F_40 ( L_3 ,
V_72 -> V_78 , V_73 , V_74 ) ;
}
break;
default:
F_41 ( L_4 , V_62 -> V_75 ) ;
}
}
static void F_42 ( struct V_50 * V_51 ,
struct V_63 * V_62 )
{
struct V_70 * V_71 ;
struct V_1 * V_72 = F_1 ( V_51 -> V_3 ) ;
unsigned int V_73 = V_62 -> V_74 [ 1 ] ;
unsigned int V_74 = ( V_62 -> V_74 [ 2 ] << 8 ) | V_62 -> V_74 [ 3 ] ;
T_2 V_79 = V_62 -> V_75 & 255 ;
T_2 V_80 = V_62 -> V_75 >> 8 ;
V_71 = F_37 ( V_72 , 0 , V_73 , V_74 ) ;
if ( ! V_71 ) {
F_40 ( L_3 ,
V_72 -> V_78 , V_73 , V_74 ) ;
return;
}
if ( V_79 == 0x2a && ( V_80 == 0x00 || V_80 == 0x01 || V_80 == 0x09 ) )
F_43 ( & V_71 -> V_15 ) ;
F_39 ( V_71 ) ;
}
static void F_44 ( struct V_81 * V_69 )
{
struct V_57 * V_58 =
F_45 ( V_69 , struct V_57 , V_69 ) ;
struct V_50 * V_51 = V_58 -> V_51 ;
struct V_63 * V_62 = & V_58 -> V_62 ;
if ( V_62 -> V_62 & V_82 ) {
V_62 -> V_62 &= ~ V_82 ;
F_46 ( F_1 ( V_51 -> V_3 ) ) ;
}
switch ( V_62 -> V_62 ) {
case V_83 :
break;
case V_84 :
F_35 ( V_51 , V_62 ) ;
break;
case V_85 :
F_42 ( V_51 , V_62 ) ;
break;
default:
F_40 ( L_5 , V_62 -> V_62 ) ;
}
F_28 ( V_51 , V_58 ) ;
}
static void F_47 ( void * V_9 )
{
struct V_57 * V_58 = V_9 ;
F_48 ( & V_58 -> V_69 , F_44 ) ;
F_49 ( & V_58 -> V_69 ) ;
}
static void F_50 ( struct V_46 * V_47 )
{
struct V_1 * V_49 = F_1 ( V_47 -> V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
unsigned long V_52 ;
F_23 ( & V_51 -> V_64 . V_54 , V_52 ) ;
F_16 ( V_47 , F_47 ) ;
F_24 ( & V_51 -> V_64 . V_54 , V_52 ) ;
}
static void F_51 ( struct V_60 * V_61 , unsigned int * V_86 ,
struct V_87 * V_88 )
{
struct V_89 * V_90 = & V_88 -> V_90 ;
struct V_60 * V_91 ;
unsigned int V_92 = * V_86 ;
int V_66 ;
F_52 (table->sgl, sg_elem, table->nents, i)
V_61 [ V_92 ++ ] = * V_91 ;
* V_86 = V_92 ;
}
static void F_53 ( struct V_93 * V_94 ,
struct V_10 * V_11 ,
unsigned * V_95 , unsigned * V_96 ,
T_3 V_97 , T_3 V_98 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_60 * V_61 = V_94 -> V_61 ;
unsigned int V_92 = 0 ;
F_54 ( & V_61 [ V_92 ++ ] , & V_11 -> V_99 , V_97 ) ;
if ( V_6 && V_6 -> V_100 != V_101 )
F_51 ( V_61 , & V_92 , F_7 ( V_6 ) ) ;
* V_95 = V_92 ;
F_54 ( & V_61 [ V_92 ++ ] , & V_11 -> V_13 , V_98 ) ;
if ( V_6 && V_6 -> V_100 != V_102 )
F_51 ( V_61 , & V_92 , F_5 ( V_6 ) ) ;
* V_96 = V_92 - * V_95 ;
}
static int F_55 ( struct V_93 * V_94 ,
struct V_103 * V_47 ,
struct V_10 * V_11 ,
T_3 V_97 , T_3 V_98 , T_4 V_104 )
{
unsigned int V_95 , V_96 ;
unsigned long V_52 ;
int V_59 ;
F_23 ( & V_94 -> V_105 , V_52 ) ;
F_53 ( V_94 , V_11 , & V_95 , & V_96 , V_97 , V_98 ) ;
F_56 ( & V_47 -> V_54 ) ;
V_59 = F_30 ( V_47 -> V_47 , V_94 -> V_61 , V_95 , V_96 , V_11 , V_104 ) ;
F_57 ( & V_94 -> V_105 ) ;
if ( V_59 >= 0 )
V_59 = F_58 ( V_47 -> V_47 ) ;
F_24 ( & V_47 -> V_54 , V_52 ) ;
if ( V_59 > 0 )
F_59 ( V_47 -> V_47 ) ;
return V_59 ;
}
static int F_60 ( struct V_1 * V_49 , struct V_5 * V_6 )
{
struct V_50 * V_51 = F_22 ( V_49 ) ;
struct V_93 * V_94 = V_51 -> V_94 [ V_6 -> V_14 -> V_106 ] ;
struct V_10 * V_11 ;
int V_59 ;
struct V_1 * V_72 = F_1 ( V_51 -> V_3 ) ;
F_61 ( F_62 ( V_6 ) > V_72 -> V_107 ) ;
F_61 ( V_6 -> V_100 == V_108 ) ;
F_9 ( & V_6 -> V_14 -> V_15 ,
L_6 , V_6 , V_6 -> V_109 [ 0 ] ) ;
V_59 = V_110 ;
V_11 = F_63 ( V_44 , V_65 ) ;
if ( ! V_11 )
goto V_111;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_99 . V_11 = (struct V_112 ) {
. V_74 [ 0 ] = 1 ,
. V_74 [ 1 ] = V_6 -> V_14 -> V_106 ,
. V_74 [ 2 ] = ( V_6 -> V_14 -> V_74 >> 8 ) | 0x40 ,
. V_74 [ 3 ] = V_6 -> V_14 -> V_74 & 0xff ,
. V_113 = ( unsigned long ) V_6 ,
. V_114 = V_115 ,
. V_116 = 0 ,
. V_117 = 0 ,
} ;
F_61 ( V_6 -> V_118 > V_119 ) ;
memcpy ( V_11 -> V_99 . V_11 . V_120 , V_6 -> V_109 , V_6 -> V_118 ) ;
if ( F_55 ( V_94 , & V_51 -> V_53 , V_11 ,
sizeof V_11 -> V_99 . V_11 , sizeof V_11 -> V_13 . V_11 ,
V_65 ) >= 0 )
V_59 = 0 ;
V_111:
return V_59 ;
}
static int F_64 ( struct V_50 * V_51 , struct V_10 * V_11 )
{
F_65 ( V_55 ) ;
struct V_93 * V_94 = V_51 -> V_94 [ V_11 -> V_6 -> V_14 -> V_106 ] ;
int V_59 = V_121 ;
V_11 -> V_55 = & V_55 ;
if ( F_55 ( V_94 , & V_51 -> V_56 , V_11 ,
sizeof V_11 -> V_99 . V_122 , sizeof V_11 -> V_13 . V_122 ,
V_123 ) < 0 )
goto V_111;
F_66 ( & V_55 ) ;
if ( V_11 -> V_13 . V_122 . V_16 == V_20 ||
V_11 -> V_13 . V_122 . V_16 == V_124 )
V_59 = V_125 ;
V_111:
F_15 ( V_11 , V_44 ) ;
return V_59 ;
}
static int F_67 ( struct V_5 * V_6 )
{
struct V_50 * V_51 = F_22 ( V_6 -> V_14 -> V_126 ) ;
struct V_10 * V_11 ;
F_68 ( V_127 , V_6 -> V_14 , L_7 ) ;
V_11 = F_63 ( V_44 , V_123 ) ;
if ( ! V_11 )
return V_121 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_99 . V_122 = (struct V_128 ) {
. type = V_129 ,
. V_130 = V_131 ,
. V_74 [ 0 ] = 1 ,
. V_74 [ 1 ] = V_6 -> V_14 -> V_106 ,
. V_74 [ 2 ] = ( V_6 -> V_14 -> V_74 >> 8 ) | 0x40 ,
. V_74 [ 3 ] = V_6 -> V_14 -> V_74 & 0xff ,
} ;
return F_64 ( V_51 , V_11 ) ;
}
static int F_69 ( struct V_5 * V_6 )
{
struct V_50 * V_51 = F_22 ( V_6 -> V_14 -> V_126 ) ;
struct V_10 * V_11 ;
F_11 ( V_127 , V_6 , L_8 ) ;
V_11 = F_63 ( V_44 , V_123 ) ;
if ( ! V_11 )
return V_121 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_99 . V_122 = (struct V_128 ) {
. type = V_129 ,
. V_130 = V_132 ,
. V_74 [ 0 ] = 1 ,
. V_74 [ 1 ] = V_6 -> V_14 -> V_106 ,
. V_74 [ 2 ] = ( V_6 -> V_14 -> V_74 >> 8 ) | 0x40 ,
. V_74 [ 3 ] = V_6 -> V_14 -> V_74 & 0xff ,
. V_113 = ( unsigned long ) V_6 ,
} ;
return F_64 ( V_51 , V_11 ) ;
}
static void F_70 ( struct V_103 * V_133 ,
struct V_46 * V_47 )
{
F_71 ( & V_133 -> V_54 ) ;
V_133 -> V_47 = V_47 ;
}
static struct V_93 * F_72 (
struct V_2 * V_3 , int V_134 )
{
struct V_93 * V_94 ;
T_4 V_135 = V_136 ;
V_94 = F_73 ( sizeof( * V_94 ) + sizeof( V_94 -> V_61 [ 0 ] ) * ( V_134 + 2 ) ,
V_135 ) ;
if ( ! V_94 )
return NULL ;
F_71 ( & V_94 -> V_105 ) ;
F_74 ( V_94 -> V_61 , V_134 + 2 ) ;
return V_94 ;
}
static void F_75 ( struct V_2 * V_3 )
{
struct V_1 * V_72 = (struct V_1 * ) V_3 -> V_4 ;
F_46 ( V_72 ) ;
}
static void F_76 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
T_1 V_66 , V_137 ;
V_3 -> V_138 -> V_139 ( V_3 ) ;
V_137 = V_49 -> V_140 ;
for ( V_66 = 0 ; V_66 < V_137 ; V_66 ++ ) {
F_77 ( V_51 -> V_94 [ V_66 ] ) ;
V_51 -> V_94 [ V_66 ] = NULL ;
}
V_3 -> V_138 -> V_141 ( V_3 ) ;
}
static int F_78 ( struct V_2 * V_3 ,
struct V_50 * V_51 , int V_137 )
{
int V_142 ;
struct V_46 * V_143 [ 3 ] ;
T_1 V_66 , V_134 ;
T_5 * V_144 [] = {
F_27 ,
F_50 ,
F_21
} ;
const char * V_145 [] = {
L_9 ,
L_10 ,
L_11
} ;
V_142 = V_3 -> V_138 -> V_146 ( V_3 , 3 , V_143 , V_144 , V_145 ) ;
if ( V_142 )
return V_142 ;
F_70 ( & V_51 -> V_56 , V_143 [ 0 ] ) ;
F_70 ( & V_51 -> V_64 , V_143 [ 1 ] ) ;
F_70 ( & V_51 -> V_53 , V_143 [ 2 ] ) ;
F_79 ( V_3 , V_147 , V_119 ) ;
F_79 ( V_3 , V_148 , V_40 ) ;
if ( F_80 ( V_3 , V_149 ) )
F_32 ( V_51 ) ;
V_134 = F_81 ( V_3 , V_150 ) ? : 1 ;
for ( V_66 = 0 ; V_66 < V_137 ; V_66 ++ ) {
V_51 -> V_94 [ V_66 ] = F_72 ( V_3 , V_134 ) ;
if ( ! V_51 -> V_94 [ V_66 ] ) {
V_142 = - V_151 ;
goto V_111;
}
}
V_142 = 0 ;
V_111:
if ( V_142 )
F_76 ( V_3 ) ;
return V_142 ;
}
static int T_6 F_82 ( struct V_2 * V_3 )
{
struct V_1 * V_72 ;
struct V_50 * V_51 ;
int V_142 ;
T_1 V_134 , V_137 ;
T_1 V_152 ;
V_137 = F_81 ( V_3 , V_153 ) + 1 ;
V_72 = F_83 ( & V_154 ,
sizeof( * V_51 )
+ V_137 * sizeof( struct V_93 ) ) ;
if ( ! V_72 )
return - V_151 ;
V_134 = F_81 ( V_3 , V_150 ) ? : 1 ;
V_72 -> V_107 = V_134 ;
V_51 = F_22 ( V_72 ) ;
V_51 -> V_3 = V_3 ;
V_3 -> V_4 = V_72 ;
V_142 = F_78 ( V_3 , V_51 , V_137 ) ;
if ( V_142 )
goto V_155;
V_152 = F_81 ( V_3 , V_152 ) ? : 1 ;
V_72 -> V_152 = F_13 ( T_1 , V_152 , V_72 -> V_156 ) ;
V_72 -> V_157 = F_81 ( V_3 , V_157 ) ? : 0xFFFF ;
V_72 -> V_158 = F_81 ( V_3 , V_158 ) + 1 + 0x4000 ;
V_72 -> V_140 = V_137 ;
V_72 -> V_159 = 0 ;
V_72 -> V_160 = V_119 ;
V_142 = F_84 ( V_72 , & V_3 -> V_161 ) ;
if ( V_142 )
goto V_162;
return 0 ;
V_162:
V_3 -> V_138 -> V_141 ( V_3 ) ;
V_155:
F_85 ( V_72 ) ;
return V_142 ;
}
static void T_7 F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_72 = F_1 ( V_3 ) ;
struct V_50 * V_51 = F_22 ( V_72 ) ;
if ( F_80 ( V_3 , V_149 ) )
F_33 ( V_51 ) ;
F_87 ( V_72 ) ;
F_76 ( V_3 ) ;
F_85 ( V_72 ) ;
}
static int F_88 ( struct V_2 * V_3 )
{
F_76 ( V_3 ) ;
return 0 ;
}
static int F_89 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
return F_78 ( V_3 , V_51 , V_49 -> V_140 ) ;
}
static int T_8 F_90 ( void )
{
int V_59 = - V_151 ;
V_163 = F_91 ( V_10 , 0 ) ;
if ( ! V_163 ) {
F_92 ( V_164 L_12
L_13 ) ;
goto error;
}
V_44 =
F_93 ( V_165 ,
V_163 ) ;
if ( ! V_44 ) {
F_92 ( V_164 L_14
L_15 ) ;
goto error;
}
V_59 = F_94 ( & V_166 ) ;
if ( V_59 < 0 )
goto error;
return 0 ;
error:
if ( V_44 ) {
F_95 ( V_44 ) ;
V_44 = NULL ;
}
if ( V_163 ) {
F_96 ( V_163 ) ;
V_163 = NULL ;
}
return V_59 ;
}
static void T_9 F_97 ( void )
{
F_98 ( & V_166 ) ;
F_95 ( V_44 ) ;
F_96 ( V_163 ) ;
}
