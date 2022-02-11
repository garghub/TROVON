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
static void F_42 ( struct V_79 * V_69 )
{
struct V_57 * V_58 =
F_43 ( V_69 , struct V_57 , V_69 ) ;
struct V_50 * V_51 = V_58 -> V_51 ;
struct V_63 * V_62 = & V_58 -> V_62 ;
if ( V_62 -> V_62 & V_80 ) {
V_62 -> V_62 &= ~ V_80 ;
F_44 ( F_1 ( V_51 -> V_3 ) ) ;
}
switch ( V_62 -> V_62 ) {
case V_81 :
break;
case V_82 :
F_35 ( V_51 , V_62 ) ;
break;
default:
F_40 ( L_5 , V_62 -> V_62 ) ;
}
F_28 ( V_51 , V_58 ) ;
}
static void F_45 ( void * V_9 )
{
struct V_57 * V_58 = V_9 ;
F_46 ( & V_58 -> V_69 , F_42 ) ;
F_47 ( & V_58 -> V_69 ) ;
}
static void F_48 ( struct V_46 * V_47 )
{
struct V_1 * V_49 = F_1 ( V_47 -> V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
unsigned long V_52 ;
F_23 ( & V_51 -> V_64 . V_54 , V_52 ) ;
F_16 ( V_47 , F_45 ) ;
F_24 ( & V_51 -> V_64 . V_54 , V_52 ) ;
}
static void F_49 ( struct V_60 * V_61 , unsigned int * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_87 = & V_85 -> V_87 ;
struct V_60 * V_88 ;
unsigned int V_89 = * V_83 ;
int V_66 ;
F_50 (table->sgl, sg_elem, table->nents, i)
V_61 [ V_89 ++ ] = * V_88 ;
* V_83 = V_89 ;
}
static void F_51 ( struct V_90 * V_91 ,
struct V_10 * V_11 ,
unsigned * V_92 , unsigned * V_93 ,
T_2 V_94 , T_2 V_95 )
{
struct V_5 * V_6 = V_11 -> V_6 ;
struct V_60 * V_61 = V_91 -> V_61 ;
unsigned int V_89 = 0 ;
F_29 ( & V_61 [ V_89 ++ ] , & V_11 -> V_96 , V_94 ) ;
if ( V_6 && V_6 -> V_97 != V_98 )
F_49 ( V_61 , & V_89 , F_7 ( V_6 ) ) ;
* V_92 = V_89 ;
F_29 ( & V_61 [ V_89 ++ ] , & V_11 -> V_13 , V_95 ) ;
if ( V_6 && V_6 -> V_97 != V_99 )
F_49 ( V_61 , & V_89 , F_5 ( V_6 ) ) ;
* V_93 = V_89 - * V_92 ;
}
static int F_52 ( struct V_90 * V_91 ,
struct V_100 * V_47 ,
struct V_10 * V_11 ,
T_2 V_94 , T_2 V_95 , T_3 V_101 )
{
unsigned int V_92 , V_93 ;
unsigned long V_52 ;
int V_59 ;
F_23 ( & V_91 -> V_102 , V_52 ) ;
F_51 ( V_91 , V_11 , & V_92 , & V_93 , V_94 , V_95 ) ;
F_53 ( & V_47 -> V_54 ) ;
V_59 = F_30 ( V_47 -> V_47 , V_91 -> V_61 , V_92 , V_93 , V_11 , V_101 ) ;
F_54 ( & V_91 -> V_102 ) ;
if ( V_59 >= 0 )
V_59 = F_55 ( V_47 -> V_47 ) ;
F_24 ( & V_47 -> V_54 , V_52 ) ;
if ( V_59 > 0 )
F_56 ( V_47 -> V_47 ) ;
return V_59 ;
}
static int F_57 ( struct V_1 * V_49 , struct V_5 * V_6 )
{
struct V_50 * V_51 = F_22 ( V_49 ) ;
struct V_90 * V_91 = V_51 -> V_91 [ V_6 -> V_14 -> V_103 ] ;
struct V_10 * V_11 ;
int V_59 ;
struct V_1 * V_72 = F_1 ( V_51 -> V_3 ) ;
F_58 ( F_59 ( V_6 ) > V_72 -> V_104 ) ;
F_58 ( V_6 -> V_97 == V_105 ) ;
F_9 ( & V_6 -> V_14 -> V_15 ,
L_6 , V_6 , V_6 -> V_106 [ 0 ] ) ;
V_59 = V_107 ;
V_11 = F_60 ( V_44 , V_65 ) ;
if ( ! V_11 )
goto V_108;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_96 . V_11 = (struct V_109 ) {
. V_74 [ 0 ] = 1 ,
. V_74 [ 1 ] = V_6 -> V_14 -> V_103 ,
. V_74 [ 2 ] = ( V_6 -> V_14 -> V_74 >> 8 ) | 0x40 ,
. V_74 [ 3 ] = V_6 -> V_14 -> V_74 & 0xff ,
. V_110 = ( unsigned long ) V_6 ,
. V_111 = V_112 ,
. V_113 = 0 ,
. V_114 = 0 ,
} ;
F_58 ( V_6 -> V_115 > V_116 ) ;
memcpy ( V_11 -> V_96 . V_11 . V_117 , V_6 -> V_106 , V_6 -> V_115 ) ;
if ( F_52 ( V_91 , & V_51 -> V_53 , V_11 ,
sizeof V_11 -> V_96 . V_11 , sizeof V_11 -> V_13 . V_11 ,
V_65 ) >= 0 )
V_59 = 0 ;
V_108:
return V_59 ;
}
static int F_61 ( struct V_50 * V_51 , struct V_10 * V_11 )
{
F_62 ( V_55 ) ;
struct V_90 * V_91 = V_51 -> V_91 [ V_11 -> V_6 -> V_14 -> V_103 ] ;
int V_59 = V_118 ;
V_11 -> V_55 = & V_55 ;
if ( F_52 ( V_91 , & V_51 -> V_56 , V_11 ,
sizeof V_11 -> V_96 . V_119 , sizeof V_11 -> V_13 . V_119 ,
V_120 ) < 0 )
goto V_108;
F_63 ( & V_55 ) ;
if ( V_11 -> V_13 . V_119 . V_16 == V_20 ||
V_11 -> V_13 . V_119 . V_16 == V_121 )
V_59 = V_122 ;
V_108:
F_15 ( V_11 , V_44 ) ;
return V_59 ;
}
static int F_64 ( struct V_5 * V_6 )
{
struct V_50 * V_51 = F_22 ( V_6 -> V_14 -> V_123 ) ;
struct V_10 * V_11 ;
F_65 ( V_124 , V_6 -> V_14 , L_7 ) ;
V_11 = F_60 ( V_44 , V_120 ) ;
if ( ! V_11 )
return V_118 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_96 . V_119 = (struct V_125 ) {
. type = V_126 ,
. V_127 = V_128 ,
. V_74 [ 0 ] = 1 ,
. V_74 [ 1 ] = V_6 -> V_14 -> V_103 ,
. V_74 [ 2 ] = ( V_6 -> V_14 -> V_74 >> 8 ) | 0x40 ,
. V_74 [ 3 ] = V_6 -> V_14 -> V_74 & 0xff ,
} ;
return F_61 ( V_51 , V_11 ) ;
}
static int F_66 ( struct V_5 * V_6 )
{
struct V_50 * V_51 = F_22 ( V_6 -> V_14 -> V_123 ) ;
struct V_10 * V_11 ;
F_11 ( V_124 , V_6 , L_8 ) ;
V_11 = F_60 ( V_44 , V_120 ) ;
if ( ! V_11 )
return V_118 ;
memset ( V_11 , 0 , sizeof( * V_11 ) ) ;
V_11 -> V_6 = V_6 ;
V_11 -> V_96 . V_119 = (struct V_125 ) {
. type = V_126 ,
. V_127 = V_129 ,
. V_74 [ 0 ] = 1 ,
. V_74 [ 1 ] = V_6 -> V_14 -> V_103 ,
. V_74 [ 2 ] = ( V_6 -> V_14 -> V_74 >> 8 ) | 0x40 ,
. V_74 [ 3 ] = V_6 -> V_14 -> V_74 & 0xff ,
. V_110 = ( unsigned long ) V_6 ,
} ;
return F_61 ( V_51 , V_11 ) ;
}
static void F_67 ( struct V_100 * V_130 ,
struct V_46 * V_47 )
{
F_68 ( & V_130 -> V_54 ) ;
V_130 -> V_47 = V_47 ;
}
static struct V_90 * F_69 (
struct V_2 * V_3 , int V_131 )
{
struct V_90 * V_91 ;
T_3 V_132 = V_133 ;
V_91 = F_70 ( sizeof( * V_91 ) + sizeof( V_91 -> V_61 [ 0 ] ) * ( V_131 + 2 ) ,
V_132 ) ;
if ( ! V_91 )
return NULL ;
F_68 ( & V_91 -> V_102 ) ;
F_71 ( V_91 -> V_61 , V_131 + 2 ) ;
return V_91 ;
}
static void F_72 ( struct V_2 * V_3 )
{
struct V_1 * V_72 = (struct V_1 * ) V_3 -> V_4 ;
F_44 ( V_72 ) ;
}
static void F_73 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
T_1 V_66 , V_134 ;
V_3 -> V_135 -> V_136 ( V_3 ) ;
V_134 = V_49 -> V_137 ;
for ( V_66 = 0 ; V_66 < V_134 ; V_66 ++ ) {
F_74 ( V_51 -> V_91 [ V_66 ] ) ;
V_51 -> V_91 [ V_66 ] = NULL ;
}
V_3 -> V_135 -> V_138 ( V_3 ) ;
}
static int F_75 ( struct V_2 * V_3 ,
struct V_50 * V_51 , int V_134 )
{
int V_139 ;
struct V_46 * V_140 [ 3 ] ;
T_1 V_66 , V_131 ;
T_4 * V_141 [] = {
F_27 ,
F_48 ,
F_21
} ;
const char * V_142 [] = {
L_9 ,
L_10 ,
L_11
} ;
V_139 = V_3 -> V_135 -> V_143 ( V_3 , 3 , V_140 , V_141 , V_142 ) ;
if ( V_139 )
return V_139 ;
F_67 ( & V_51 -> V_56 , V_140 [ 0 ] ) ;
F_67 ( & V_51 -> V_64 , V_140 [ 1 ] ) ;
F_67 ( & V_51 -> V_53 , V_140 [ 2 ] ) ;
F_76 ( V_3 , V_144 , V_116 ) ;
F_76 ( V_3 , V_145 , V_40 ) ;
if ( F_77 ( V_3 , V_146 ) )
F_32 ( V_51 ) ;
V_131 = F_78 ( V_3 , V_147 ) ? : 1 ;
for ( V_66 = 0 ; V_66 < V_134 ; V_66 ++ ) {
V_51 -> V_91 [ V_66 ] = F_69 ( V_3 , V_131 ) ;
if ( ! V_51 -> V_91 [ V_66 ] ) {
V_139 = - V_148 ;
goto V_108;
}
}
V_139 = 0 ;
V_108:
if ( V_139 )
F_73 ( V_3 ) ;
return V_139 ;
}
static int T_5 F_79 ( struct V_2 * V_3 )
{
struct V_1 * V_72 ;
struct V_50 * V_51 ;
int V_139 ;
T_1 V_131 , V_134 ;
T_1 V_149 ;
V_134 = F_78 ( V_3 , V_150 ) + 1 ;
V_72 = F_80 ( & V_151 ,
sizeof( * V_51 )
+ V_134 * sizeof( struct V_90 ) ) ;
if ( ! V_72 )
return - V_148 ;
V_131 = F_78 ( V_3 , V_147 ) ? : 1 ;
V_72 -> V_104 = V_131 ;
V_51 = F_22 ( V_72 ) ;
V_51 -> V_3 = V_3 ;
V_3 -> V_4 = V_72 ;
V_139 = F_75 ( V_3 , V_51 , V_134 ) ;
if ( V_139 )
goto V_152;
V_149 = F_78 ( V_3 , V_149 ) ? : 1 ;
V_72 -> V_149 = F_13 ( T_1 , V_149 , V_72 -> V_153 ) ;
V_72 -> V_154 = F_78 ( V_3 , V_154 ) ? : 0xFFFF ;
V_72 -> V_155 = F_78 ( V_3 , V_155 ) + 1 ;
V_72 -> V_137 = V_134 ;
V_72 -> V_156 = 0 ;
V_72 -> V_157 = V_116 ;
V_139 = F_81 ( V_72 , & V_3 -> V_158 ) ;
if ( V_139 )
goto V_159;
return 0 ;
V_159:
V_3 -> V_135 -> V_138 ( V_3 ) ;
V_152:
F_82 ( V_72 ) ;
return V_139 ;
}
static void T_6 F_83 ( struct V_2 * V_3 )
{
struct V_1 * V_72 = F_1 ( V_3 ) ;
struct V_50 * V_51 = F_22 ( V_72 ) ;
if ( F_77 ( V_3 , V_146 ) )
F_33 ( V_51 ) ;
F_84 ( V_72 ) ;
F_73 ( V_3 ) ;
F_82 ( V_72 ) ;
}
static int F_85 ( struct V_2 * V_3 )
{
F_73 ( V_3 ) ;
return 0 ;
}
static int F_86 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_50 * V_51 = F_22 ( V_49 ) ;
return F_75 ( V_3 , V_51 , V_49 -> V_137 ) ;
}
static int T_7 F_87 ( void )
{
int V_59 = - V_148 ;
V_160 = F_88 ( V_10 , 0 ) ;
if ( ! V_160 ) {
F_89 ( V_161 L_12
L_13 ) ;
goto error;
}
V_44 =
F_90 ( V_162 ,
V_160 ) ;
if ( ! V_44 ) {
F_89 ( V_161 L_14
L_15 ) ;
goto error;
}
V_59 = F_91 ( & V_163 ) ;
if ( V_59 < 0 )
goto error;
return 0 ;
error:
if ( V_44 ) {
F_92 ( V_44 ) ;
V_44 = NULL ;
}
if ( V_160 ) {
F_93 ( V_160 ) ;
V_160 = NULL ;
}
return V_59 ;
}
static void T_8 F_94 ( void )
{
F_95 ( & V_163 ) ;
F_92 ( V_44 ) ;
F_93 ( V_160 ) ;
}
