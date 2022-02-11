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
static void F_8 ( struct V_9 * V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_14 * V_15 = & V_13 -> V_15 . V_13 ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
F_10 ( & V_6 -> V_18 -> V_20 ,
L_1 ,
V_6 , V_15 -> V_21 , V_15 -> V_22 , V_15 -> V_23 ) ;
V_6 -> V_24 = V_15 -> V_22 ;
F_2 ( V_6 , F_11 ( V_10 -> V_3 , V_15 -> V_7 ) ) ;
switch ( V_15 -> V_21 ) {
case V_25 :
F_12 ( V_6 , V_26 ) ;
break;
case V_27 :
F_12 ( V_6 , V_28 ) ;
break;
case V_29 :
F_12 ( V_6 , V_30 ) ;
break;
case V_31 :
F_12 ( V_6 , V_32 ) ;
break;
case V_33 :
F_12 ( V_6 , V_34 ) ;
break;
case V_35 :
F_12 ( V_6 , V_36 ) ;
break;
case V_37 :
F_12 ( V_6 , V_38 ) ;
break;
case V_39 :
F_12 ( V_6 , V_40 ) ;
break;
case V_41 :
F_12 ( V_6 , V_42 ) ;
break;
default:
F_13 ( V_43 , V_6 , L_2 ,
V_15 -> V_21 ) ;
case V_44 :
F_12 ( V_6 , V_28 ) ;
break;
}
F_14 ( F_11 ( V_10 -> V_3 , V_15 -> V_23 ) >
V_45 ) ;
if ( V_6 -> V_46 ) {
memcpy ( V_6 -> V_46 , V_15 -> V_47 ,
F_15 ( T_1 ,
F_11 ( V_10 -> V_3 , V_15 -> V_23 ) ,
V_45 ) ) ;
if ( V_15 -> V_23 )
F_16 ( V_6 , V_48 ) ;
}
V_6 -> V_49 ( V_6 ) ;
F_17 ( & V_17 -> V_50 ) ;
}
static void F_18 ( struct V_9 * V_10 ,
struct V_51 * V_52 ,
void (* F_19)( struct V_9 * V_10 , void * V_11 ) )
{
void * V_11 ;
unsigned int V_53 ;
unsigned long V_54 ;
struct V_55 * V_56 = V_52 -> V_56 ;
F_20 ( & V_52 -> V_57 , V_54 ) ;
do {
F_21 ( V_56 ) ;
while ( ( V_11 = F_22 ( V_56 , & V_53 ) ) != NULL )
F_19 ( V_10 , V_11 ) ;
if ( F_23 ( F_24 ( V_56 ) ) )
break;
} while ( ! F_25 ( V_56 ) );
F_26 ( & V_52 -> V_57 , V_54 ) ;
}
static void F_27 ( struct V_55 * V_56 )
{
struct V_1 * V_58 = F_1 ( V_56 -> V_3 ) ;
struct V_9 * V_10 = F_28 ( V_58 ) ;
int V_59 = V_56 -> V_59 - V_60 ;
struct V_51 * V_61 = & V_10 -> V_62 [ V_59 ] ;
F_18 ( V_10 , V_61 , F_8 ) ;
}
static void F_29 ( struct V_9 * V_10 )
{
int V_63 , V_64 ;
V_64 = V_10 -> V_65 ;
for ( V_63 = 0 ; V_63 < V_64 ; V_63 ++ )
F_18 ( V_10 , & V_10 -> V_62 [ V_63 ] ,
F_8 ) ;
}
static void F_30 ( struct V_9 * V_10 , void * V_11 )
{
struct V_12 * V_13 = V_11 ;
if ( V_13 -> V_66 )
F_31 ( V_13 -> V_66 ) ;
}
static void F_32 ( struct V_55 * V_56 )
{
struct V_1 * V_58 = F_1 ( V_56 -> V_3 ) ;
struct V_9 * V_10 = F_28 ( V_58 ) ;
F_18 ( V_10 , & V_10 -> V_67 , F_30 ) ;
}
static int F_33 ( struct V_9 * V_10 ,
struct V_68 * V_69 )
{
int V_70 ;
struct V_71 V_72 ;
unsigned long V_54 ;
F_34 ( & V_69 -> V_73 , V_74 ) ;
F_35 ( & V_72 , & V_69 -> V_75 , sizeof( struct V_76 ) ) ;
F_20 ( & V_10 -> V_77 . V_57 , V_54 ) ;
V_70 = F_36 ( V_10 -> V_77 . V_56 , & V_72 , 1 , V_69 ,
V_78 ) ;
if ( ! V_70 )
F_37 ( V_10 -> V_77 . V_56 ) ;
F_26 ( & V_10 -> V_77 . V_57 , V_54 ) ;
return V_70 ;
}
static int F_38 ( struct V_9 * V_10 )
{
int V_63 ;
for ( V_63 = 0 ; V_63 < V_79 ; V_63 ++ ) {
V_10 -> V_80 [ V_63 ] . V_10 = V_10 ;
F_33 ( V_10 , & V_10 -> V_80 [ V_63 ] ) ;
}
return 0 ;
}
static void F_39 ( struct V_9 * V_10 )
{
int V_63 ;
F_40 ( & V_10 -> V_77 . V_57 ) ;
V_10 -> V_81 = true ;
F_41 ( & V_10 -> V_77 . V_57 ) ;
for ( V_63 = 0 ; V_63 < V_79 ; V_63 ++ )
F_42 ( & V_10 -> V_80 [ V_63 ] . V_73 ) ;
}
static void F_43 ( struct V_9 * V_10 ,
struct V_76 * V_75 )
{
struct V_82 * V_83 ;
struct V_1 * V_84 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_85 = V_75 -> V_86 [ 1 ] ;
unsigned int V_86 = ( V_75 -> V_86 [ 2 ] << 8 ) | V_75 -> V_86 [ 3 ] ;
switch ( F_11 ( V_10 -> V_3 , V_75 -> V_87 ) ) {
case V_88 :
F_44 ( V_84 , 0 , V_85 , V_86 ) ;
break;
case V_89 :
V_83 = F_45 ( V_84 , 0 , V_85 , V_86 ) ;
if ( V_83 ) {
F_46 ( V_83 ) ;
F_47 ( V_83 ) ;
} else {
F_48 ( L_3 ,
V_84 -> V_90 , V_85 , V_86 ) ;
}
break;
default:
F_49 ( L_4 , V_75 -> V_87 ) ;
}
}
static void F_50 ( struct V_9 * V_10 ,
struct V_76 * V_75 )
{
struct V_82 * V_83 ;
struct V_1 * V_84 = F_1 ( V_10 -> V_3 ) ;
unsigned int V_85 = V_75 -> V_86 [ 1 ] ;
unsigned int V_86 = ( V_75 -> V_86 [ 2 ] << 8 ) | V_75 -> V_86 [ 3 ] ;
T_2 V_91 = F_11 ( V_10 -> V_3 , V_75 -> V_87 ) & 255 ;
T_2 V_92 = F_11 ( V_10 -> V_3 , V_75 -> V_87 ) >> 8 ;
V_83 = F_45 ( V_84 , 0 , V_85 , V_86 ) ;
if ( ! V_83 ) {
F_48 ( L_3 ,
V_84 -> V_90 , V_85 , V_86 ) ;
return;
}
if ( V_91 == 0x2a && ( V_92 == 0x00 || V_92 == 0x01 || V_92 == 0x09 ) )
F_51 ( & V_83 -> V_20 ) ;
F_47 ( V_83 ) ;
}
static void V_74 ( struct V_93 * V_73 )
{
struct V_68 * V_69 =
F_52 ( V_73 , struct V_68 , V_73 ) ;
struct V_9 * V_10 = V_69 -> V_10 ;
struct V_76 * V_75 = & V_69 -> V_75 ;
if ( V_75 -> V_75 &
F_53 ( V_10 -> V_3 , V_94 ) ) {
V_75 -> V_75 &= ~ F_53 ( V_10 -> V_3 ,
V_94 ) ;
F_54 ( F_1 ( V_10 -> V_3 ) ) ;
}
switch ( F_11 ( V_10 -> V_3 , V_75 -> V_75 ) ) {
case V_95 :
break;
case V_96 :
F_43 ( V_10 , V_75 ) ;
break;
case V_97 :
F_50 ( V_10 , V_75 ) ;
break;
default:
F_48 ( L_5 , V_75 -> V_75 ) ;
}
F_33 ( V_10 , V_69 ) ;
}
static void F_55 ( struct V_9 * V_10 , void * V_11 )
{
struct V_68 * V_69 = V_11 ;
if ( ! V_10 -> V_81 )
F_56 ( V_98 , & V_69 -> V_73 ) ;
}
static void F_57 ( struct V_55 * V_56 )
{
struct V_1 * V_58 = F_1 ( V_56 -> V_3 ) ;
struct V_9 * V_10 = F_28 ( V_58 ) ;
F_18 ( V_10 , & V_10 -> V_77 , F_55 ) ;
}
static int F_58 ( struct V_55 * V_56 ,
struct V_12 * V_13 ,
T_3 V_99 , T_3 V_100 )
{
struct V_5 * V_6 = V_13 -> V_6 ;
struct V_71 * V_101 [ 6 ] , V_102 , V_15 ;
struct V_103 * V_104 , * V_105 ;
unsigned V_106 = 0 , V_107 = 0 ;
V_104 = V_105 = NULL ;
if ( V_6 && V_6 -> V_108 != V_109 ) {
if ( V_6 -> V_108 != V_110 )
V_104 = & F_7 ( V_6 ) -> V_111 ;
if ( V_6 -> V_108 != V_112 )
V_105 = & F_5 ( V_6 ) -> V_111 ;
}
F_35 ( & V_102 , & V_13 -> V_102 , V_99 ) ;
V_101 [ V_106 ++ ] = & V_102 ;
if ( V_104 ) {
if ( F_59 ( V_6 ) )
V_101 [ V_106 ++ ] = F_60 ( V_6 ) ;
V_101 [ V_106 ++ ] = V_104 -> V_113 ;
}
F_35 ( & V_15 , & V_13 -> V_15 , V_100 ) ;
V_101 [ V_106 + V_107 ++ ] = & V_15 ;
if ( V_105 ) {
if ( F_59 ( V_6 ) )
V_101 [ V_106 + V_107 ++ ] = F_60 ( V_6 ) ;
V_101 [ V_106 + V_107 ++ ] = V_105 -> V_113 ;
}
return F_61 ( V_56 , V_101 , V_106 , V_107 , V_13 , V_78 ) ;
}
static int F_62 ( struct V_51 * V_56 ,
struct V_12 * V_13 ,
T_3 V_99 , T_3 V_100 )
{
unsigned long V_54 ;
int V_70 ;
bool V_114 = false ;
F_20 ( & V_56 -> V_57 , V_54 ) ;
V_70 = F_58 ( V_56 -> V_56 , V_13 , V_99 , V_100 ) ;
if ( ! V_70 )
V_114 = F_63 ( V_56 -> V_56 ) ;
F_26 ( & V_56 -> V_57 , V_54 ) ;
if ( V_114 )
F_64 ( V_56 -> V_56 ) ;
return V_70 ;
}
static void F_65 ( struct V_2 * V_3 ,
struct V_115 * V_13 ,
struct V_5 * V_6 )
{
V_13 -> V_86 [ 0 ] = 1 ;
V_13 -> V_86 [ 1 ] = V_6 -> V_18 -> V_116 ;
V_13 -> V_86 [ 2 ] = ( V_6 -> V_18 -> V_86 >> 8 ) | 0x40 ;
V_13 -> V_86 [ 3 ] = V_6 -> V_18 -> V_86 & 0xff ;
V_13 -> V_117 = F_66 ( V_3 , ( unsigned long ) V_6 ) ;
V_13 -> V_118 = V_119 ;
V_13 -> V_120 = 0 ;
V_13 -> V_121 = 0 ;
}
static void F_67 ( struct V_2 * V_3 ,
struct V_122 * V_123 ,
struct V_5 * V_6 )
{
struct V_124 * V_125 = V_6 -> V_124 ;
struct V_126 * V_127 ;
F_65 ( V_3 , (struct V_115 * ) V_123 , V_6 ) ;
if ( ! V_125 || ! F_59 ( V_6 ) )
return;
V_127 = F_68 ( V_125 -> V_128 ) ;
if ( V_6 -> V_108 == V_112 )
V_123 -> V_129 = F_53 ( V_3 ,
F_69 ( V_125 ) *
V_127 -> V_130 ) ;
else if ( V_6 -> V_108 == V_110 )
V_123 -> V_131 = F_53 ( V_3 ,
F_69 ( V_125 ) *
V_127 -> V_130 ) ;
}
static int F_70 ( struct V_9 * V_10 ,
struct V_51 * V_61 ,
struct V_5 * V_6 )
{
struct V_1 * V_84 = F_1 ( V_10 -> V_3 ) ;
struct V_12 * V_13 = F_71 ( V_6 ) ;
unsigned long V_54 ;
int V_99 ;
int V_132 ;
F_72 ( F_73 ( V_6 ) > V_84 -> V_133 ) ;
F_72 ( V_6 -> V_108 == V_134 ) ;
F_10 ( & V_6 -> V_18 -> V_20 ,
L_6 , V_6 , V_6 -> V_135 [ 0 ] ) ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
F_72 ( V_6 -> V_136 > V_137 ) ;
#ifdef F_74
if ( F_75 ( V_10 -> V_3 , V_138 ) ) {
F_67 ( V_10 -> V_3 , & V_13 -> V_102 . V_123 , V_6 ) ;
memcpy ( V_13 -> V_102 . V_123 . V_139 , V_6 -> V_135 , V_6 -> V_136 ) ;
V_99 = sizeof( V_13 -> V_102 . V_123 ) ;
} else
#endif
{
F_65 ( V_10 -> V_3 , & V_13 -> V_102 . V_13 , V_6 ) ;
memcpy ( V_13 -> V_102 . V_13 . V_139 , V_6 -> V_135 , V_6 -> V_136 ) ;
V_99 = sizeof( V_13 -> V_102 . V_13 ) ;
}
V_132 = F_62 ( V_61 , V_13 , V_99 , sizeof( V_13 -> V_15 . V_13 ) ) ;
if ( V_132 == - V_140 ) {
V_13 -> V_15 . V_13 . V_21 = V_31 ;
F_20 ( & V_61 -> V_57 , V_54 ) ;
F_8 ( V_10 , V_13 ) ;
F_26 ( & V_61 -> V_57 , V_54 ) ;
} else if ( V_132 != 0 ) {
return V_141 ;
}
return 0 ;
}
static int F_76 ( struct V_1 * V_58 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_28 ( V_58 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
F_77 ( & V_17 -> V_50 ) ;
return F_70 ( V_10 , & V_10 -> V_62 [ 0 ] , V_6 ) ;
}
static struct V_51 * F_78 ( struct V_9 * V_10 ,
struct V_5 * V_6 )
{
T_1 V_117 = F_79 ( V_6 -> V_124 ) ;
T_4 V_142 = F_80 ( V_117 ) ;
return & V_10 -> V_62 [ V_142 ] ;
}
static struct V_51 * F_81 ( struct V_9 * V_10 ,
struct V_16 * V_17 )
{
struct V_51 * V_56 ;
unsigned long V_54 ;
T_1 V_143 ;
F_82 ( V_54 ) ;
if ( F_83 ( & V_17 -> V_50 ) > 1 ) {
unsigned long V_144 ;
do {
V_144 = F_84 ( & V_17 -> V_145 ) ;
V_56 = V_17 -> V_61 ;
} while ( F_85 ( & V_17 -> V_145 , V_144 ) );
} else {
F_86 ( & V_17 -> V_145 ) ;
if ( F_23 ( F_87 ( & V_17 -> V_50 ) > 1 ) ) {
V_56 = V_17 -> V_61 ;
goto V_146;
}
V_143 = F_88 () ;
while ( F_23 ( V_143 >= V_10 -> V_65 ) )
V_143 -= V_10 -> V_65 ;
V_17 -> V_61 = V_56 = & V_10 -> V_62 [ V_143 ] ;
V_146:
F_89 ( & V_17 -> V_145 ) ;
}
F_90 ( V_54 ) ;
return V_56 ;
}
static int F_91 ( struct V_1 * V_58 ,
struct V_5 * V_6 )
{
struct V_9 * V_10 = F_28 ( V_58 ) ;
struct V_16 * V_17 =
F_9 ( V_6 -> V_18 ) -> V_19 ;
struct V_51 * V_61 ;
if ( F_92 ( V_58 ) )
V_61 = F_78 ( V_10 , V_6 ) ;
else
V_61 = F_81 ( V_10 , V_17 ) ;
return F_70 ( V_10 , V_61 , V_6 ) ;
}
static int F_93 ( struct V_9 * V_10 , struct V_12 * V_13 )
{
F_94 ( V_66 ) ;
int V_132 = V_147 ;
V_13 -> V_66 = & V_66 ;
if ( F_62 ( & V_10 -> V_67 , V_13 ,
sizeof V_13 -> V_102 . V_148 , sizeof V_13 -> V_15 . V_148 ) < 0 )
goto V_104;
F_95 ( & V_66 ) ;
if ( V_13 -> V_15 . V_148 . V_21 == V_25 ||
V_13 -> V_15 . V_148 . V_21 == V_149 )
V_132 = V_150 ;
F_29 ( V_10 ) ;
V_104:
F_96 ( V_13 , V_151 ) ;
return V_132 ;
}
static int F_97 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_28 ( V_6 -> V_18 -> V_152 ) ;
struct V_12 * V_13 ;
F_98 ( V_153 , V_6 -> V_18 , L_7 ) ;
V_13 = F_99 ( V_151 , V_154 ) ;
if ( ! V_13 )
return V_147 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_102 . V_148 = (struct V_155 ) {
. type = V_156 ,
. V_157 = F_53 ( V_10 -> V_3 ,
V_158 ) ,
. V_86 [ 0 ] = 1 ,
. V_86 [ 1 ] = V_6 -> V_18 -> V_116 ,
. V_86 [ 2 ] = ( V_6 -> V_18 -> V_86 >> 8 ) | 0x40 ,
. V_86 [ 3 ] = V_6 -> V_18 -> V_86 & 0xff ,
} ;
return F_93 ( V_10 , V_13 ) ;
}
static int F_100 ( struct V_82 * V_83 , int V_159 )
{
struct V_1 * V_84 = V_83 -> V_152 ;
int V_160 = V_84 -> V_161 ;
return F_101 ( V_83 , F_6 ( V_160 , V_159 ) ) ;
}
static int F_102 ( struct V_5 * V_6 )
{
struct V_9 * V_10 = F_28 ( V_6 -> V_18 -> V_152 ) ;
struct V_12 * V_13 ;
F_13 ( V_153 , V_6 , L_8 ) ;
V_13 = F_99 ( V_151 , V_154 ) ;
if ( ! V_13 )
return V_147 ;
memset ( V_13 , 0 , sizeof( * V_13 ) ) ;
V_13 -> V_6 = V_6 ;
V_13 -> V_102 . V_148 = (struct V_155 ) {
. type = V_156 ,
. V_157 = V_162 ,
. V_86 [ 0 ] = 1 ,
. V_86 [ 1 ] = V_6 -> V_18 -> V_116 ,
. V_86 [ 2 ] = ( V_6 -> V_18 -> V_86 >> 8 ) | 0x40 ,
. V_86 [ 3 ] = V_6 -> V_18 -> V_86 & 0xff ,
. V_117 = F_66 ( V_10 -> V_3 , ( unsigned long ) V_6 ) ,
} ;
return F_93 ( V_10 , V_13 ) ;
}
static int F_103 ( struct F_9 * V_163 )
{
struct V_1 * V_58 = F_104 ( V_163 -> V_164 . V_165 ) ;
struct V_9 * V_10 = F_28 ( V_58 ) ;
struct V_16 * V_17 =
F_105 ( sizeof( * V_17 ) , V_166 ) ;
if ( ! V_17 )
return - V_167 ;
F_106 ( & V_17 -> V_145 ) ;
F_107 ( & V_17 -> V_50 , 0 ) ;
V_17 -> V_61 = & V_10 -> V_62 [ 0 ] ;
V_163 -> V_19 = V_17 ;
return 0 ;
}
static void F_108 ( struct F_9 * V_163 )
{
struct V_16 * V_17 = V_163 -> V_19 ;
F_109 ( V_17 ) ;
}
static void F_110 ( struct V_9 * V_10 , bool V_168 )
{
int V_63 ;
int V_169 ;
if ( ( V_10 -> V_65 == 1 ||
V_10 -> V_65 != F_111 () ) && V_168 ) {
if ( V_10 -> V_170 )
V_168 = false ;
else
return;
}
if ( V_168 ) {
V_63 = 0 ;
F_112 (cpu) {
F_113 ( V_10 -> V_62 [ V_63 ] . V_56 , V_169 ) ;
V_63 ++ ;
}
V_10 -> V_170 = true ;
} else {
for ( V_63 = 0 ; V_63 < V_10 -> V_65 ; V_63 ++ ) {
if ( ! V_10 -> V_62 [ V_63 ] . V_56 )
continue;
F_113 ( V_10 -> V_62 [ V_63 ] . V_56 , - 1 ) ;
}
V_10 -> V_170 = false ;
}
}
static void F_114 ( struct V_9 * V_10 , bool V_168 )
{
F_115 () ;
F_110 ( V_10 , V_168 ) ;
F_116 () ;
}
static int F_117 ( unsigned int V_169 , struct V_171 * V_172 )
{
struct V_9 * V_10 = F_118 ( V_172 , struct V_9 ,
V_172 ) ;
F_110 ( V_10 , true ) ;
return 0 ;
}
static int F_119 ( struct V_9 * V_173 )
{
int V_132 ;
V_132 = F_120 ( V_174 , & V_173 -> V_172 ) ;
if ( V_132 )
return V_132 ;
V_132 = F_120 ( V_175 , & V_173 -> V_176 ) ;
if ( V_132 )
F_121 ( V_174 , & V_173 -> V_172 ) ;
return V_132 ;
}
static void F_122 ( struct V_9 * V_173 )
{
F_123 ( V_174 , & V_173 -> V_172 ) ;
F_123 ( V_175 ,
& V_173 -> V_176 ) ;
}
static void F_124 ( struct V_51 * V_52 ,
struct V_55 * V_56 )
{
F_125 ( & V_52 -> V_57 ) ;
V_52 -> V_56 = V_56 ;
}
static void F_126 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_28 ( V_58 ) ;
F_114 ( V_10 , false ) ;
V_3 -> V_177 -> V_178 ( V_3 ) ;
V_3 -> V_177 -> V_179 ( V_3 ) ;
}
static int F_127 ( struct V_2 * V_3 ,
struct V_9 * V_10 )
{
int V_70 ;
T_1 V_63 ;
T_1 V_64 ;
T_5 * * V_180 ;
const char * * V_181 ;
struct V_55 * * V_182 ;
V_64 = V_10 -> V_65 + V_60 ;
V_182 = F_105 ( V_64 * sizeof( struct V_55 * ) , V_166 ) ;
V_180 = F_105 ( V_64 * sizeof( T_5 * ) , V_166 ) ;
V_181 = F_105 ( V_64 * sizeof( char * ) , V_166 ) ;
if ( ! V_180 || ! V_182 || ! V_181 ) {
V_70 = - V_167 ;
goto V_104;
}
V_180 [ 0 ] = F_32 ;
V_180 [ 1 ] = F_57 ;
V_181 [ 0 ] = L_9 ;
V_181 [ 1 ] = L_10 ;
for ( V_63 = V_60 ; V_63 < V_64 ; V_63 ++ ) {
V_180 [ V_63 ] = F_27 ;
V_181 [ V_63 ] = L_11 ;
}
V_70 = V_3 -> V_177 -> V_183 ( V_3 , V_64 , V_182 , V_180 , V_181 ) ;
if ( V_70 )
goto V_104;
F_124 ( & V_10 -> V_67 , V_182 [ 0 ] ) ;
F_124 ( & V_10 -> V_77 , V_182 [ 1 ] ) ;
for ( V_63 = V_60 ; V_63 < V_64 ; V_63 ++ )
F_124 ( & V_10 -> V_62 [ V_63 - V_60 ] ,
V_182 [ V_63 ] ) ;
F_128 ( V_3 , V_184 , V_137 ) ;
F_128 ( V_3 , V_185 , V_45 ) ;
V_70 = 0 ;
V_104:
F_109 ( V_181 ) ;
F_109 ( V_180 ) ;
F_109 ( V_182 ) ;
if ( V_70 )
F_126 ( V_3 ) ;
return V_70 ;
}
static int F_129 ( struct V_2 * V_3 )
{
struct V_1 * V_84 ;
struct V_9 * V_10 ;
int V_70 ;
T_1 V_186 , V_187 ;
T_1 V_161 ;
T_1 V_65 ;
struct V_188 * V_189 ;
if ( ! V_3 -> V_177 -> V_190 ) {
F_130 ( & V_3 -> V_164 , L_12 ,
V_191 ) ;
return - V_192 ;
}
V_65 = F_131 ( V_3 , V_65 ) ? : 1 ;
V_187 = F_131 ( V_3 , V_193 ) + 1 ;
if ( V_65 == 1 )
V_189 = & V_194 ;
else
V_189 = & V_195 ;
V_84 = F_132 ( V_189 ,
sizeof( * V_10 ) + sizeof( V_10 -> V_62 [ 0 ] ) * V_65 ) ;
if ( ! V_84 )
return - V_167 ;
V_186 = F_131 ( V_3 , V_196 ) ? : 1 ;
V_84 -> V_133 = V_186 ;
V_10 = F_28 ( V_84 ) ;
V_10 -> V_3 = V_3 ;
V_10 -> V_65 = V_65 ;
V_3 -> V_4 = V_84 ;
V_70 = F_127 ( V_3 , V_10 ) ;
if ( V_70 )
goto V_197;
V_70 = F_119 ( V_10 ) ;
if ( V_70 )
goto V_198;
V_161 = F_131 ( V_3 , V_161 ) ? : 1 ;
V_84 -> V_161 = F_15 ( T_1 , V_161 , V_84 -> V_199 ) ;
V_84 -> V_200 = F_131 ( V_3 , V_200 ) ? : 0xFFFF ;
V_84 -> V_201 = F_131 ( V_3 , V_201 ) + 1 + 0x4000 ;
V_84 -> V_202 = V_187 ;
V_84 -> V_203 = 0 ;
V_84 -> V_204 = V_137 ;
V_84 -> V_205 = V_65 ;
#ifdef F_74
if ( F_75 ( V_3 , V_138 ) ) {
int V_206 ;
V_206 = V_207 | V_208 |
V_209 | V_210 |
V_211 | V_212 ;
F_133 ( V_84 , V_206 ) ;
F_134 ( V_84 , V_213 ) ;
}
#endif
V_70 = F_135 ( V_84 , & V_3 -> V_164 ) ;
if ( V_70 )
goto V_198;
F_136 ( V_3 ) ;
if ( F_75 ( V_3 , V_214 ) )
F_38 ( V_10 ) ;
F_54 ( V_84 ) ;
return 0 ;
V_198:
V_3 -> V_177 -> V_179 ( V_3 ) ;
V_197:
F_137 ( V_84 ) ;
return V_70 ;
}
static void F_138 ( struct V_2 * V_3 )
{
struct V_1 * V_84 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_28 ( V_84 ) ;
if ( F_75 ( V_3 , V_214 ) )
F_39 ( V_10 ) ;
F_139 ( V_84 ) ;
F_122 ( V_10 ) ;
F_126 ( V_3 ) ;
F_137 ( V_84 ) ;
}
static int F_140 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_28 ( V_58 ) ;
F_122 ( V_10 ) ;
F_126 ( V_3 ) ;
return 0 ;
}
static int F_141 ( struct V_2 * V_3 )
{
struct V_1 * V_58 = F_1 ( V_3 ) ;
struct V_9 * V_10 = F_28 ( V_58 ) ;
int V_70 ;
V_70 = F_127 ( V_3 , V_10 ) ;
if ( V_70 )
return V_70 ;
V_70 = F_119 ( V_10 ) ;
if ( V_70 ) {
V_3 -> V_177 -> V_179 ( V_3 ) ;
return V_70 ;
}
F_136 ( V_3 ) ;
if ( F_75 ( V_3 , V_214 ) )
F_38 ( V_10 ) ;
return V_70 ;
}
static int T_6 F_142 ( void )
{
int V_132 = - V_167 ;
V_215 = F_143 ( V_12 , 0 ) ;
if ( ! V_215 ) {
F_48 ( L_13 ) ;
goto error;
}
V_151 =
F_144 ( V_216 ,
V_215 ) ;
if ( ! V_151 ) {
F_48 ( L_14 ) ;
goto error;
}
V_132 = F_145 ( V_217 ,
L_15 ,
F_117 , NULL ) ;
if ( V_132 < 0 )
goto error;
V_174 = V_132 ;
V_132 = F_145 ( V_175 , L_16 ,
NULL , F_117 ) ;
if ( V_132 )
goto error;
V_132 = F_146 ( & V_218 ) ;
if ( V_132 < 0 )
goto error;
return 0 ;
error:
if ( V_151 ) {
F_147 ( V_151 ) ;
V_151 = NULL ;
}
if ( V_215 ) {
F_148 ( V_215 ) ;
V_215 = NULL ;
}
if ( V_174 )
F_149 ( V_174 ) ;
F_149 ( V_175 ) ;
return V_132 ;
}
static void T_7 F_150 ( void )
{
F_151 ( & V_218 ) ;
F_149 ( V_174 ) ;
F_149 ( V_175 ) ;
F_147 ( V_151 ) ;
F_148 ( V_215 ) ;
}
