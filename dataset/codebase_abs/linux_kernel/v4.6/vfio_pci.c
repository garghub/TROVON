static inline bool F_1 ( void )
{
#ifdef F_2
return V_1 ;
#else
return true ;
#endif
}
static unsigned int F_3 ( void * V_2 , bool V_3 )
{
struct V_4 * V_5 = V_2 ;
struct V_6 * V_7 = NULL , * V_8 = V_5 -> V_8 ;
unsigned char V_9 ;
unsigned int V_10 ;
if ( V_3 || ! F_1 () || F_4 ( V_8 -> V_11 ) )
return V_12 | V_13 |
V_14 | V_15 ;
V_9 = F_5 ( V_8 -> V_11 ) ;
V_10 = V_12 | V_13 ;
while ( ( V_7 = F_6 ( V_16 << 8 , V_7 ) ) != NULL ) {
if ( V_7 == V_8 ||
F_7 ( V_7 -> V_11 ) != F_7 ( V_8 -> V_11 ) ||
F_4 ( V_7 -> V_11 ) )
continue;
if ( V_7 -> V_11 -> V_17 >= V_8 -> V_11 -> V_17 &&
V_7 -> V_11 -> V_17 <= V_9 ) {
F_8 ( V_7 ) ;
V_10 |= V_14 | V_15 ;
break;
}
}
return V_10 ;
}
static inline bool F_9 ( struct V_6 * V_8 )
{
return ( V_8 -> V_18 >> 8 ) == V_16 ;
}
static int F_10 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_19 ;
T_1 V_20 ;
T_2 V_21 ;
F_11 ( V_8 , V_22 ) ;
F_12 ( V_8 ) ;
V_19 = F_13 ( V_8 ) ;
if ( V_19 )
return V_19 ;
V_5 -> V_23 = ( F_14 ( V_8 ) == 0 ) ;
F_15 ( V_8 ) ;
V_5 -> V_24 = F_16 ( V_8 ) ;
if ( ! V_5 -> V_24 )
F_17 ( L_1 ,
V_25 , F_18 ( & V_8 -> V_26 ) ) ;
V_19 = F_19 ( V_5 ) ;
if ( V_19 ) {
F_20 ( V_5 -> V_24 ) ;
V_5 -> V_24 = NULL ;
F_21 ( V_8 ) ;
return V_19 ;
}
if ( F_22 ( ! V_27 ) )
V_5 -> V_28 = F_23 ( V_8 ) ;
F_24 ( V_8 , V_29 , & V_20 ) ;
if ( V_5 -> V_28 && ( V_20 & V_30 ) ) {
V_20 &= ~ V_30 ;
F_25 ( V_8 , V_29 , V_20 ) ;
}
V_21 = V_8 -> V_31 ;
if ( V_21 ) {
T_1 V_32 ;
T_3 V_33 ;
F_24 ( V_8 , V_21 + V_34 , & V_32 ) ;
F_26 ( V_8 , V_21 + V_35 , & V_33 ) ;
V_5 -> V_36 = V_33 & V_37 ;
V_5 -> V_38 = V_33 & V_39 ;
V_5 -> V_40 = ( ( V_32 & V_41 ) + 1 ) * 16 ;
} else
V_5 -> V_36 = 0xFF ;
if ( ! F_1 () && F_9 ( V_8 ) )
V_5 -> V_42 = true ;
if ( F_9 ( V_8 ) &&
V_8 -> V_43 == V_44 &&
F_27 ( V_45 ) ) {
V_19 = F_28 ( V_5 ) ;
if ( V_19 ) {
F_29 ( & V_5 -> V_8 -> V_26 ,
L_2 ) ;
F_30 ( V_5 ) ;
return V_19 ;
}
}
return 0 ;
}
static void F_30 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_46 , V_47 ;
F_12 ( V_8 ) ;
F_31 ( V_5 , V_48 |
V_49 ,
V_5 -> V_50 , 0 , 0 , NULL ) ;
V_5 -> V_51 = false ;
for ( V_46 = 0 ; V_46 < V_5 -> V_52 ; V_46 ++ )
V_5 -> V_53 [ V_46 ] . V_54 -> V_55 ( V_5 , & V_5 -> V_53 [ V_46 ] ) ;
V_5 -> V_52 = 0 ;
F_20 ( V_5 -> V_53 ) ;
V_5 -> V_53 = NULL ;
F_32 ( V_5 ) ;
for ( V_47 = V_56 ; V_47 <= V_57 ; V_47 ++ ) {
if ( ! V_5 -> V_58 [ V_47 ] )
continue;
F_33 ( V_8 , V_5 -> V_58 [ V_47 ] ) ;
F_34 ( V_8 , 1 << V_47 ) ;
V_5 -> V_58 [ V_47 ] = NULL ;
}
V_5 -> V_59 = true ;
if ( F_35 ( V_8 , & V_5 -> V_24 ) ) {
F_36 ( L_3 ,
V_25 , F_18 ( & V_8 -> V_26 ) ) ;
if ( ! V_5 -> V_23 )
goto V_60;
F_15 ( V_8 ) ;
}
F_25 ( V_8 , V_29 , V_30 ) ;
if ( V_5 -> V_23 && ! F_37 ( V_8 ) )
V_5 -> V_59 = false ;
F_38 ( V_8 ) ;
V_60:
F_21 ( V_8 ) ;
F_39 ( V_5 ) ;
if ( ! V_61 )
F_11 ( V_8 , V_62 ) ;
}
static void F_40 ( void * V_63 )
{
struct V_4 * V_5 = V_63 ;
F_41 ( & V_64 ) ;
if ( ! ( -- V_5 -> V_65 ) ) {
F_42 ( V_5 -> V_8 ) ;
F_30 ( V_5 ) ;
}
F_43 ( & V_64 ) ;
F_44 ( V_66 ) ;
}
static int F_45 ( void * V_63 )
{
struct V_4 * V_5 = V_63 ;
int V_19 = 0 ;
if ( ! F_46 ( V_66 ) )
return - V_67 ;
F_41 ( & V_64 ) ;
if ( ! V_5 -> V_65 ) {
V_19 = F_10 ( V_5 ) ;
if ( V_19 )
goto error;
F_47 ( V_5 -> V_8 ) ;
}
V_5 -> V_65 ++ ;
error:
F_43 ( & V_64 ) ;
if ( V_19 )
F_44 ( V_66 ) ;
return V_19 ;
}
static int F_48 ( struct V_4 * V_5 , int V_50 )
{
if ( V_50 == V_68 ) {
T_2 V_69 ;
F_49 ( V_5 -> V_8 , V_70 , & V_69 ) ;
if ( F_27 ( V_71 ) && V_69 )
return 1 ;
} else if ( V_50 == V_72 ) {
T_2 V_73 ;
T_1 V_32 ;
V_73 = V_5 -> V_8 -> V_74 ;
if ( V_73 ) {
F_24 ( V_5 -> V_8 ,
V_73 + V_75 , & V_32 ) ;
return 1 << ( ( V_32 & V_76 ) >> 1 ) ;
}
} else if ( V_50 == V_77 ) {
T_2 V_73 ;
T_1 V_32 ;
V_73 = V_5 -> V_8 -> V_31 ;
if ( V_73 ) {
F_24 ( V_5 -> V_8 ,
V_73 + V_34 , & V_32 ) ;
return ( V_32 & V_41 ) + 1 ;
}
} else if ( V_50 == V_78 ) {
if ( F_50 ( V_5 -> V_8 ) )
return 1 ;
} else if ( V_50 == V_79 ) {
return 1 ;
}
return 0 ;
}
static int F_51 ( struct V_6 * V_8 , void * V_80 )
{
( * ( int * ) V_80 ) ++ ;
return 0 ;
}
static int F_52 ( struct V_6 * V_8 , void * V_80 )
{
struct V_81 * V_82 = V_80 ;
struct V_83 * V_83 ;
if ( V_82 -> V_84 == V_82 -> V_85 )
return - V_86 ;
V_83 = F_53 ( & V_8 -> V_26 ) ;
if ( ! V_83 )
return - V_87 ;
V_82 -> V_88 [ V_82 -> V_84 ] . V_89 = F_54 ( V_83 ) ;
V_82 -> V_88 [ V_82 -> V_84 ] . V_90 = F_7 ( V_8 -> V_11 ) ;
V_82 -> V_88 [ V_82 -> V_84 ] . V_11 = V_8 -> V_11 -> V_17 ;
V_82 -> V_88 [ V_82 -> V_84 ] . V_91 = V_8 -> V_91 ;
V_82 -> V_84 ++ ;
F_55 ( V_83 ) ;
return 0 ;
}
static int F_56 ( struct V_6 * V_8 , void * V_80 )
{
struct V_92 * V_93 = V_80 ;
struct V_83 * V_94 ;
int V_95 , V_46 ;
V_94 = F_53 ( & V_8 -> V_26 ) ;
if ( ! V_94 )
return - V_87 ;
V_95 = F_54 ( V_94 ) ;
for ( V_46 = 0 ; V_46 < V_93 -> V_96 ; V_46 ++ )
if ( V_93 -> V_97 [ V_46 ] . V_95 == V_95 )
break;
F_55 ( V_94 ) ;
return ( V_46 == V_93 -> V_96 ) ? - V_98 : 0 ;
}
static bool F_57 ( struct V_6 * V_8 , struct V_99 * V_100 )
{
for (; V_8 ; V_8 = V_8 -> V_11 -> V_101 )
if ( V_8 -> V_11 == V_100 -> V_11 )
return ( V_8 -> V_100 == V_100 ) ;
return false ;
}
static int F_58 ( struct V_6 * V_8 , void * V_80 )
{
struct V_102 * V_103 = V_80 ;
if ( ! V_103 -> V_100 || F_57 ( V_8 , V_103 -> V_8 -> V_100 ) )
V_103 -> V_19 = V_103 -> V_104 ( V_8 , V_103 -> V_80 ) ;
return V_103 -> V_19 ;
}
static int F_59 ( struct V_6 * V_8 ,
int (* V_104)( struct V_6 * ,
void * V_80 ) , void * V_80 ,
bool V_100 )
{
struct V_102 V_103 = {
. V_104 = V_104 , . V_80 = V_80 , . V_8 = V_8 , . V_100 = V_100 , . V_19 = 0 ,
} ;
F_60 ( V_8 -> V_11 , F_58 , & V_103 ) ;
return V_103 . V_19 ;
}
static int F_61 ( struct V_4 * V_5 ,
struct V_105 * V_106 )
{
struct V_107 * V_108 ;
struct V_109 * V_110 ;
T_4 V_111 , V_112 ;
int V_113 = 2 , V_46 = 0 ;
V_111 = F_62 ( V_5 -> V_8 , V_5 -> V_36 ) ;
if ( ( ( V_5 -> V_38 & V_114 ) == 0 ) ||
( F_63 ( V_5 -> V_38 + V_5 -> V_40 ) >= V_111 ) )
V_113 = 1 ;
V_112 = sizeof( * V_110 ) + ( V_113 * sizeof( * V_110 -> V_115 ) ) ;
V_108 = F_64 ( V_106 , V_112 ,
V_116 , 1 ) ;
if ( F_65 ( V_108 ) )
return F_66 ( V_108 ) ;
V_110 = F_67 ( V_108 ,
struct V_109 , V_108 ) ;
V_110 -> V_113 = V_113 ;
if ( V_5 -> V_38 & V_114 ) {
V_110 -> V_115 [ V_46 ] . V_117 = 0 ;
V_110 -> V_115 [ V_46 ] . V_112 = V_5 -> V_38 & V_114 ;
V_46 ++ ;
}
if ( F_63 ( V_5 -> V_38 + V_5 -> V_40 ) < V_111 ) {
V_110 -> V_115 [ V_46 ] . V_117 = F_63 ( V_5 -> V_38 +
V_5 -> V_40 ) ;
V_110 -> V_115 [ V_46 ] . V_112 = V_111 - V_110 -> V_115 [ V_46 ] . V_117 ;
V_46 ++ ;
}
return 0 ;
}
static int F_68 ( struct V_4 * V_5 ,
struct V_105 * V_106 ,
unsigned int type , unsigned int V_118 )
{
struct V_107 * V_108 ;
struct V_119 * V_120 ;
V_108 = F_64 ( V_106 , sizeof( * V_120 ) ,
V_121 , 1 ) ;
if ( F_65 ( V_108 ) )
return F_66 ( V_108 ) ;
V_120 = F_67 ( V_108 , struct V_119 , V_108 ) ;
V_120 -> type = type ;
V_120 -> V_118 = V_118 ;
return 0 ;
}
int F_69 ( struct V_4 * V_5 ,
unsigned int type , unsigned int V_118 ,
const struct V_122 * V_54 ,
T_4 V_112 , T_3 V_32 , void * V_80 )
{
struct V_123 * V_53 ;
V_53 = F_70 ( V_5 -> V_53 ,
( V_5 -> V_52 + 1 ) * sizeof( * V_53 ) ,
V_124 ) ;
if ( ! V_53 )
return - V_125 ;
V_5 -> V_53 = V_53 ;
V_5 -> V_53 [ V_5 -> V_52 ] . type = type ;
V_5 -> V_53 [ V_5 -> V_52 ] . V_118 = V_118 ;
V_5 -> V_53 [ V_5 -> V_52 ] . V_54 = V_54 ;
V_5 -> V_53 [ V_5 -> V_52 ] . V_112 = V_112 ;
V_5 -> V_53 [ V_5 -> V_52 ] . V_32 = V_32 ;
V_5 -> V_53 [ V_5 -> V_52 ] . V_80 = V_80 ;
V_5 -> V_52 ++ ;
return 0 ;
}
static long F_71 ( void * V_63 ,
unsigned int V_20 , unsigned long V_126 )
{
struct V_4 * V_5 = V_63 ;
unsigned long V_127 ;
if ( V_20 == V_128 ) {
struct V_129 V_93 ;
V_127 = F_72 ( struct V_129 , V_130 ) ;
if ( F_73 ( & V_93 , ( void V_131 * ) V_126 , V_127 ) )
return - V_132 ;
if ( V_93 . V_133 < V_127 )
return - V_98 ;
V_93 . V_32 = V_134 ;
if ( V_5 -> V_23 )
V_93 . V_32 |= V_135 ;
V_93 . V_52 = V_136 + V_5 -> V_52 ;
V_93 . V_130 = V_137 ;
return F_74 ( ( void V_131 * ) V_126 , & V_93 , V_127 ) ?
- V_132 : 0 ;
} else if ( V_20 == V_138 ) {
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_139 V_93 ;
struct V_105 V_106 = { . V_140 = NULL , . V_112 = 0 } ;
int V_46 , V_19 ;
V_127 = F_72 ( struct V_139 , V_117 ) ;
if ( F_73 ( & V_93 , ( void V_131 * ) V_126 , V_127 ) )
return - V_132 ;
if ( V_93 . V_133 < V_127 )
return - V_98 ;
switch ( V_93 . V_141 ) {
case V_142 :
V_93 . V_117 = F_75 ( V_93 . V_141 ) ;
V_93 . V_112 = V_8 -> V_143 ;
V_93 . V_32 = V_144 |
V_145 ;
break;
case V_146 ... V_147 :
V_93 . V_117 = F_75 ( V_93 . V_141 ) ;
V_93 . V_112 = F_62 ( V_8 , V_93 . V_141 ) ;
if ( ! V_93 . V_112 ) {
V_93 . V_32 = 0 ;
break;
}
V_93 . V_32 = V_144 |
V_145 ;
if ( F_27 ( V_148 ) &&
F_76 ( V_8 , V_93 . V_141 ) &
V_149 && V_93 . V_112 >= V_150 ) {
V_93 . V_32 |= V_151 ;
if ( V_93 . V_141 == V_5 -> V_36 ) {
V_19 = F_61 ( V_5 , & V_106 ) ;
if ( V_19 )
return V_19 ;
}
}
break;
case V_152 :
{
void T_5 * V_153 ;
T_4 V_112 ;
V_93 . V_117 = F_75 ( V_93 . V_141 ) ;
V_93 . V_32 = 0 ;
V_93 . V_112 = F_62 ( V_8 , V_93 . V_141 ) ;
if ( ! V_93 . V_112 ) {
if ( V_8 -> V_154 [ V_155 ] . V_32 &
V_156 )
V_93 . V_112 = 0x20000 ;
else
break;
}
V_153 = F_77 ( V_8 , & V_112 ) ;
if ( ! V_153 || ! V_112 ) {
V_93 . V_112 = 0 ;
break;
}
F_78 ( V_8 , V_153 ) ;
V_93 . V_32 = V_144 ;
break;
}
case V_157 :
if ( ! V_5 -> V_42 )
return - V_98 ;
V_93 . V_117 = F_75 ( V_93 . V_141 ) ;
V_93 . V_112 = 0xc0000 ;
V_93 . V_32 = V_144 |
V_145 ;
break;
default:
if ( V_93 . V_141 >=
V_136 + V_5 -> V_52 )
return - V_98 ;
V_46 = V_93 . V_141 - V_136 ;
V_93 . V_117 = F_75 ( V_93 . V_141 ) ;
V_93 . V_112 = V_5 -> V_53 [ V_46 ] . V_112 ;
V_93 . V_32 = V_5 -> V_53 [ V_46 ] . V_32 ;
V_19 = F_68 ( V_5 , & V_106 ,
V_5 -> V_53 [ V_46 ] . type ,
V_5 -> V_53 [ V_46 ] . V_118 ) ;
if ( V_19 )
return V_19 ;
}
if ( V_106 . V_112 ) {
V_93 . V_32 |= V_158 ;
if ( V_93 . V_133 < sizeof( V_93 ) + V_106 . V_112 ) {
V_93 . V_133 = sizeof( V_93 ) + V_106 . V_112 ;
V_93 . V_159 = 0 ;
} else {
F_79 ( & V_106 , sizeof( V_93 ) ) ;
if ( F_74 ( ( void V_131 * ) V_126 +
sizeof( V_93 ) , V_106 . V_140 ,
V_106 . V_112 ) ) {
F_20 ( V_106 . V_140 ) ;
return - V_132 ;
}
V_93 . V_159 = sizeof( V_93 ) ;
}
F_20 ( V_106 . V_140 ) ;
}
return F_74 ( ( void V_131 * ) V_126 , & V_93 , V_127 ) ?
- V_132 : 0 ;
} else if ( V_20 == V_160 ) {
struct V_161 V_93 ;
V_127 = F_72 ( struct V_161 , V_96 ) ;
if ( F_73 ( & V_93 , ( void V_131 * ) V_126 , V_127 ) )
return - V_132 ;
if ( V_93 . V_133 < V_127 || V_93 . V_141 >= V_137 )
return - V_98 ;
switch ( V_93 . V_141 ) {
case V_68 ... V_77 :
case V_79 :
break;
case V_78 :
if ( F_50 ( V_5 -> V_8 ) )
break;
default:
return - V_98 ;
}
V_93 . V_32 = V_162 ;
V_93 . V_96 = F_48 ( V_5 , V_93 . V_141 ) ;
if ( V_93 . V_141 == V_68 )
V_93 . V_32 |= ( V_163 |
V_164 ) ;
else
V_93 . V_32 |= V_165 ;
return F_74 ( ( void V_131 * ) V_126 , & V_93 , V_127 ) ?
- V_132 : 0 ;
} else if ( V_20 == V_166 ) {
struct V_167 V_168 ;
T_2 * V_80 = NULL ;
int V_19 = 0 ;
V_127 = F_72 ( struct V_167 , V_96 ) ;
if ( F_73 ( & V_168 , ( void V_131 * ) V_126 , V_127 ) )
return - V_132 ;
if ( V_168 . V_133 < V_127 || V_168 . V_141 >= V_137 ||
V_168 . V_32 & ~ ( V_169 |
V_170 ) )
return - V_98 ;
if ( ! ( V_168 . V_32 & V_48 ) ) {
T_4 V_112 ;
int V_85 = F_48 ( V_5 , V_168 . V_141 ) ;
if ( V_168 . V_32 & V_171 )
V_112 = sizeof( V_172 ) ;
else if ( V_168 . V_32 & V_173 )
V_112 = sizeof( V_174 ) ;
else
return - V_98 ;
if ( V_168 . V_133 - V_127 < V_168 . V_96 * V_112 ||
V_168 . V_175 >= V_85 || V_168 . V_175 + V_168 . V_96 > V_85 )
return - V_98 ;
V_80 = F_80 ( ( void V_131 * ) ( V_126 + V_127 ) ,
V_168 . V_96 * V_112 ) ;
if ( F_65 ( V_80 ) )
return F_66 ( V_80 ) ;
}
F_41 ( & V_5 -> V_176 ) ;
V_19 = F_31 ( V_5 , V_168 . V_32 , V_168 . V_141 ,
V_168 . V_175 , V_168 . V_96 , V_80 ) ;
F_43 ( & V_5 -> V_176 ) ;
F_20 ( V_80 ) ;
return V_19 ;
} else if ( V_20 == V_177 ) {
return V_5 -> V_23 ?
F_37 ( V_5 -> V_8 ) : - V_98 ;
} else if ( V_20 == V_178 ) {
struct V_179 V_168 ;
struct V_81 V_82 = { 0 } ;
struct V_180 * V_88 = NULL ;
bool V_100 = false ;
int V_19 = 0 ;
V_127 = F_72 ( struct V_179 , V_96 ) ;
if ( F_73 ( & V_168 , ( void V_131 * ) V_126 , V_127 ) )
return - V_132 ;
if ( V_168 . V_133 < V_127 )
return - V_98 ;
V_168 . V_32 = 0 ;
if ( ! F_81 ( V_5 -> V_8 -> V_100 ) )
V_100 = true ;
else if ( F_82 ( V_5 -> V_8 -> V_11 ) )
return - V_67 ;
V_19 = F_59 ( V_5 -> V_8 ,
F_51 ,
& V_82 . V_85 , V_100 ) ;
if ( V_19 )
return V_19 ;
F_83 ( ! V_82 . V_85 ) ;
if ( V_168 . V_133 < sizeof( V_168 ) + ( V_82 . V_85 * sizeof( * V_88 ) ) ) {
V_19 = - V_181 ;
V_168 . V_96 = V_82 . V_85 ;
goto V_182;
}
V_88 = F_84 ( V_82 . V_85 , sizeof( * V_88 ) , V_124 ) ;
if ( ! V_88 )
return - V_125 ;
V_82 . V_88 = V_88 ;
V_19 = F_59 ( V_5 -> V_8 ,
F_52 ,
& V_82 , V_100 ) ;
if ( ! V_19 )
V_168 . V_96 = V_82 . V_84 ;
V_182:
if ( F_74 ( ( void V_131 * ) V_126 , & V_168 , V_127 ) )
V_19 = - V_132 ;
if ( ! V_19 ) {
if ( F_74 ( ( void V_131 * ) ( V_126 + V_127 ) , V_88 ,
V_168 . V_96 * sizeof( * V_88 ) ) )
V_19 = - V_132 ;
}
F_20 ( V_88 ) ;
return V_19 ;
} else if ( V_20 == V_183 ) {
struct V_184 V_168 ;
V_174 * V_185 ;
struct V_186 * V_97 ;
struct V_92 V_93 ;
bool V_100 = false ;
int V_46 , V_96 = 0 , V_19 = 0 ;
V_127 = F_72 ( struct V_184 , V_96 ) ;
if ( F_73 ( & V_168 , ( void V_131 * ) V_126 , V_127 ) )
return - V_132 ;
if ( V_168 . V_133 < V_127 || V_168 . V_32 )
return - V_98 ;
if ( ! F_81 ( V_5 -> V_8 -> V_100 ) )
V_100 = true ;
else if ( F_82 ( V_5 -> V_8 -> V_11 ) )
return - V_67 ;
V_19 = F_59 ( V_5 -> V_8 ,
F_51 ,
& V_96 , V_100 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_168 . V_96 || V_168 . V_96 > V_96 )
return - V_98 ;
V_185 = F_84 ( V_168 . V_96 , sizeof( * V_185 ) , V_124 ) ;
V_97 = F_84 ( V_168 . V_96 , sizeof( * V_97 ) , V_124 ) ;
if ( ! V_185 || ! V_97 ) {
F_20 ( V_185 ) ;
F_20 ( V_97 ) ;
return - V_125 ;
}
if ( F_73 ( V_185 , ( void V_131 * ) ( V_126 + V_127 ) ,
V_168 . V_96 * sizeof( * V_185 ) ) ) {
F_20 ( V_185 ) ;
F_20 ( V_97 ) ;
return - V_132 ;
}
for ( V_46 = 0 ; V_46 < V_168 . V_96 ; V_46 ++ ) {
struct V_187 * V_94 ;
struct V_188 V_189 = F_85 ( V_185 [ V_46 ] ) ;
if ( ! V_189 . V_190 ) {
V_19 = - V_191 ;
break;
}
V_94 = F_86 ( V_189 . V_190 ) ;
F_87 ( V_189 ) ;
if ( F_65 ( V_94 ) ) {
V_19 = F_66 ( V_94 ) ;
break;
}
V_97 [ V_46 ] . V_94 = V_94 ;
V_97 [ V_46 ] . V_95 = F_88 ( V_94 ) ;
}
F_20 ( V_185 ) ;
if ( V_19 )
goto V_192;
V_93 . V_96 = V_168 . V_96 ;
V_93 . V_97 = V_97 ;
V_19 = F_59 ( V_5 -> V_8 ,
F_56 ,
& V_93 , V_100 ) ;
if ( ! V_19 )
V_19 = V_100 ? F_89 ( V_5 -> V_8 -> V_100 ) :
F_90 ( V_5 -> V_8 -> V_11 ) ;
V_192:
for ( V_46 -- ; V_46 >= 0 ; V_46 -- )
F_91 ( V_97 [ V_46 ] . V_94 ) ;
F_20 ( V_97 ) ;
return V_19 ;
}
return - V_193 ;
}
static T_6 F_92 ( void * V_63 , char V_131 * V_140 ,
T_4 V_96 , T_7 * V_194 , bool V_195 )
{
unsigned int V_141 = F_93 ( * V_194 ) ;
struct V_4 * V_5 = V_63 ;
if ( V_141 >= V_136 + V_5 -> V_52 )
return - V_98 ;
switch ( V_141 ) {
case V_142 :
return F_94 ( V_5 , V_140 , V_96 , V_194 , V_195 ) ;
case V_152 :
if ( V_195 )
return - V_98 ;
return F_95 ( V_5 , V_140 , V_96 , V_194 , false ) ;
case V_146 ... V_147 :
return F_95 ( V_5 , V_140 , V_96 , V_194 , V_195 ) ;
case V_157 :
return F_96 ( V_5 , V_140 , V_96 , V_194 , V_195 ) ;
default:
V_141 -= V_136 ;
return V_5 -> V_53 [ V_141 ] . V_54 -> V_196 ( V_5 , V_140 ,
V_96 , V_194 , V_195 ) ;
}
return - V_98 ;
}
static T_6 F_97 ( void * V_63 , char V_131 * V_140 ,
T_4 V_96 , T_7 * V_194 )
{
if ( ! V_96 )
return 0 ;
return F_92 ( V_63 , V_140 , V_96 , V_194 , false ) ;
}
static T_6 F_98 ( void * V_63 , const char V_131 * V_140 ,
T_4 V_96 , T_7 * V_194 )
{
if ( ! V_96 )
return 0 ;
return F_92 ( V_63 , ( char V_131 * ) V_140 , V_96 , V_194 , true ) ;
}
static int F_99 ( void * V_63 , struct V_197 * V_198 )
{
struct V_4 * V_5 = V_63 ;
struct V_6 * V_8 = V_5 -> V_8 ;
unsigned int V_141 ;
T_8 V_199 , V_200 , V_201 , V_202 ;
int V_19 ;
V_141 = V_198 -> V_203 >> ( V_204 - V_205 ) ;
if ( V_198 -> V_206 < V_198 -> V_207 )
return - V_98 ;
if ( ( V_198 -> V_208 & V_209 ) == 0 )
return - V_98 ;
if ( V_141 >= V_152 )
return - V_98 ;
if ( ! ( F_76 ( V_8 , V_141 ) & V_149 ) )
return - V_98 ;
V_199 = F_62 ( V_8 , V_141 ) ;
V_200 = V_198 -> V_206 - V_198 -> V_207 ;
V_201 = V_198 -> V_203 &
( ( 1U << ( V_204 - V_205 ) ) - 1 ) ;
V_202 = V_201 << V_205 ;
if ( V_199 < V_150 || V_202 + V_200 > V_199 )
return - V_98 ;
if ( V_141 == V_5 -> V_36 ) {
if ( ! ( V_202 >= V_5 -> V_38 + V_5 -> V_40 ||
V_202 + V_200 <= V_5 -> V_38 ) )
return - V_98 ;
}
if ( ! V_5 -> V_58 [ V_141 ] ) {
V_19 = F_100 ( V_8 ,
1 << V_141 , L_4 ) ;
if ( V_19 )
return V_19 ;
V_5 -> V_58 [ V_141 ] = F_101 ( V_8 , V_141 , 0 ) ;
}
V_198 -> V_210 = V_5 ;
V_198 -> V_211 = F_102 ( V_198 -> V_211 ) ;
V_198 -> V_203 = ( F_103 ( V_8 , V_141 ) >> V_205 ) + V_201 ;
return F_104 ( V_198 , V_198 -> V_207 , V_198 -> V_203 ,
V_200 , V_198 -> V_211 ) ;
}
static void F_105 ( void * V_63 , unsigned int V_96 )
{
struct V_4 * V_5 = V_63 ;
F_41 ( & V_5 -> V_176 ) ;
if ( V_5 -> V_212 ) {
if ( ! ( V_96 % 10 ) )
F_106 ( & V_5 -> V_8 -> V_26 ,
L_5 ,
V_96 ) ;
F_107 ( V_5 -> V_212 , 1 ) ;
} else if ( V_96 == 0 ) {
F_29 ( & V_5 -> V_8 -> V_26 ,
L_6 ) ;
}
F_43 ( & V_5 -> V_176 ) ;
}
static int F_108 ( struct V_6 * V_8 , const struct V_213 * V_95 )
{
struct V_4 * V_5 ;
struct V_83 * V_94 ;
int V_19 ;
if ( V_8 -> V_214 != V_215 )
return - V_98 ;
V_94 = F_109 ( & V_8 -> V_26 ) ;
if ( ! V_94 )
return - V_98 ;
V_5 = F_110 ( sizeof( * V_5 ) , V_124 ) ;
if ( ! V_5 ) {
F_111 ( V_94 , & V_8 -> V_26 ) ;
return - V_125 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_50 = V_137 ;
F_112 ( & V_5 -> V_176 ) ;
F_113 ( & V_5 -> V_216 ) ;
V_19 = F_114 ( & V_8 -> V_26 , & V_217 , V_5 ) ;
if ( V_19 ) {
F_111 ( V_94 , & V_8 -> V_26 ) ;
F_20 ( V_5 ) ;
return V_19 ;
}
if ( F_9 ( V_8 ) ) {
F_115 ( V_8 , V_5 , NULL , F_3 ) ;
F_116 ( V_8 ,
F_3 ( V_5 , false ) ) ;
}
if ( ! V_61 ) {
F_11 ( V_8 , V_22 ) ;
F_11 ( V_8 , V_62 ) ;
}
return V_19 ;
}
static void F_117 ( struct V_6 * V_8 )
{
struct V_4 * V_5 ;
V_5 = F_118 ( & V_8 -> V_26 ) ;
if ( ! V_5 )
return;
F_111 ( V_8 -> V_26 . V_83 , & V_8 -> V_26 ) ;
F_20 ( V_5 -> V_53 ) ;
F_20 ( V_5 ) ;
if ( F_9 ( V_8 ) ) {
F_115 ( V_8 , NULL , NULL , NULL ) ;
F_116 ( V_8 ,
V_12 | V_13 |
V_14 | V_15 ) ;
}
if ( ! V_61 )
F_11 ( V_8 , V_22 ) ;
}
static T_9 F_119 ( struct V_6 * V_8 ,
T_10 V_218 )
{
struct V_4 * V_5 ;
struct V_219 * V_220 ;
V_220 = F_120 ( & V_8 -> V_26 ) ;
if ( V_220 == NULL )
return V_221 ;
V_5 = F_121 ( V_220 ) ;
if ( V_5 == NULL ) {
F_122 ( V_220 ) ;
return V_221 ;
}
F_41 ( & V_5 -> V_176 ) ;
if ( V_5 -> V_222 )
F_107 ( V_5 -> V_222 , 1 ) ;
F_43 ( & V_5 -> V_176 ) ;
F_122 ( V_220 ) ;
return V_223 ;
}
static int F_123 ( struct V_6 * V_8 , void * V_80 )
{
struct V_224 * V_225 = V_80 ;
struct V_219 * V_220 ;
if ( V_225 -> V_226 == V_225 -> V_227 )
return - V_181 ;
V_220 = F_120 ( & V_8 -> V_26 ) ;
if ( ! V_220 )
return - V_98 ;
if ( F_124 ( V_8 ) != & V_228 ) {
F_122 ( V_220 ) ;
return - V_229 ;
}
V_225 -> V_88 [ V_225 -> V_226 ++ ] = V_220 ;
return 0 ;
}
static void F_39 ( struct V_4 * V_5 )
{
struct V_224 V_225 = { . V_226 = 0 } ;
int V_46 = 0 , V_19 = - V_98 ;
bool V_59 = false , V_100 = false ;
struct V_4 * V_7 ;
if ( ! F_81 ( V_5 -> V_8 -> V_100 ) )
V_100 = true ;
else if ( F_82 ( V_5 -> V_8 -> V_11 ) )
return;
if ( F_59 ( V_5 -> V_8 , F_51 ,
& V_46 , V_100 ) || ! V_46 )
return;
V_225 . V_227 = V_46 ;
V_225 . V_88 = F_84 ( V_46 , sizeof( struct V_219 * ) , V_124 ) ;
if ( ! V_225 . V_88 )
return;
if ( F_59 ( V_5 -> V_8 ,
F_123 , & V_225 , V_100 ) )
goto V_230;
for ( V_46 = 0 ; V_46 < V_225 . V_226 ; V_46 ++ ) {
V_7 = F_121 ( V_225 . V_88 [ V_46 ] ) ;
if ( V_7 -> V_59 )
V_59 = true ;
if ( V_7 -> V_65 )
goto V_230;
}
if ( V_59 )
V_19 = V_100 ? F_89 ( V_5 -> V_8 -> V_100 ) :
F_90 ( V_5 -> V_8 -> V_11 ) ;
V_230:
for ( V_46 = 0 ; V_46 < V_225 . V_226 ; V_46 ++ ) {
V_7 = F_121 ( V_225 . V_88 [ V_46 ] ) ;
if ( ! V_19 )
V_7 -> V_59 = false ;
if ( ! V_7 -> V_65 && ! V_61 )
F_11 ( V_7 -> V_8 , V_62 ) ;
F_122 ( V_225 . V_88 [ V_46 ] ) ;
}
F_20 ( V_225 . V_88 ) ;
}
static void T_11 F_125 ( void )
{
F_126 ( & V_228 ) ;
F_127 () ;
}
static void T_12 F_128 ( void )
{
char * V_231 , * V_95 ;
int V_232 ;
if ( V_233 [ 0 ] == '\0' )
return;
V_231 = V_233 ;
while ( ( V_95 = F_129 ( & V_231 , L_7 ) ) ) {
unsigned int V_43 , V_220 , V_234 = V_235 ,
V_236 = V_235 , V_18 = 0 , V_237 = 0 ;
int V_238 ;
if ( ! strlen ( V_95 ) )
continue;
V_238 = sscanf ( V_95 , L_8 ,
& V_43 , & V_220 , & V_234 , & V_236 ,
& V_18 , & V_237 ) ;
if ( V_238 < 2 ) {
F_130 ( L_9 , V_95 ) ;
continue;
}
V_232 = F_131 ( & V_228 , V_43 , V_220 ,
V_234 , V_236 , V_18 , V_237 , 0 ) ;
if ( V_232 )
F_130 ( L_10 ,
V_43 , V_220 , V_234 , V_236 ,
V_18 , V_237 , V_232 ) ;
else
F_36 ( L_11 ,
V_43 , V_220 , V_234 , V_236 ,
V_18 , V_237 ) ;
}
}
static int T_12 F_132 ( void )
{
int V_19 ;
V_19 = F_133 () ;
if ( V_19 )
return V_19 ;
V_19 = F_134 ( & V_228 ) ;
if ( V_19 )
goto V_239;
F_128 () ;
return 0 ;
V_239:
F_127 () ;
return V_19 ;
}
