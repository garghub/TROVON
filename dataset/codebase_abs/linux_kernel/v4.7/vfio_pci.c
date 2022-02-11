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
static bool F_10 ( struct V_6 * V_8 )
{
switch ( V_8 -> V_19 ) {
case V_20 :
switch ( V_8 -> V_21 ) {
case 0x1572 :
case 0x1574 :
case 0x1580 ... 0x1581 :
case 0x1583 ... 0x1589 :
case 0x37d0 ... 0x37d2 :
return true ;
default:
return false ;
}
}
return false ;
}
static int F_11 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_22 ;
T_1 V_23 ;
T_2 V_24 ;
F_12 ( V_8 , V_25 ) ;
F_13 ( V_8 ) ;
V_22 = F_14 ( V_8 ) ;
if ( V_22 )
return V_22 ;
V_5 -> V_26 = ( F_15 ( V_8 ) == 0 ) ;
F_16 ( V_8 ) ;
V_5 -> V_27 = F_17 ( V_8 ) ;
if ( ! V_5 -> V_27 )
F_18 ( L_1 ,
V_28 , F_19 ( & V_8 -> V_29 ) ) ;
if ( F_20 ( ! V_30 ) ) {
if ( F_10 ( V_8 ) ) {
F_21 ( & V_8 -> V_29 , L_2 ) ;
V_5 -> V_31 = true ;
F_22 ( V_8 , 0 ) ;
} else
V_5 -> V_32 = F_23 ( V_8 ) ;
}
F_24 ( V_8 , V_33 , & V_23 ) ;
if ( V_5 -> V_32 && ( V_23 & V_34 ) ) {
V_23 &= ~ V_34 ;
F_25 ( V_8 , V_33 , V_23 ) ;
}
V_22 = F_26 ( V_5 ) ;
if ( V_22 ) {
F_27 ( V_5 -> V_27 ) ;
V_5 -> V_27 = NULL ;
F_28 ( V_8 ) ;
return V_22 ;
}
V_24 = V_8 -> V_35 ;
if ( V_24 ) {
T_1 V_36 ;
T_3 V_37 ;
F_24 ( V_8 , V_24 + V_38 , & V_36 ) ;
F_29 ( V_8 , V_24 + V_39 , & V_37 ) ;
V_5 -> V_40 = V_37 & V_41 ;
V_5 -> V_42 = V_37 & V_43 ;
V_5 -> V_44 = ( ( V_36 & V_45 ) + 1 ) * 16 ;
} else
V_5 -> V_40 = 0xFF ;
if ( ! F_1 () && F_9 ( V_8 ) )
V_5 -> V_46 = true ;
if ( F_9 ( V_8 ) &&
V_8 -> V_19 == V_20 &&
F_30 ( V_47 ) ) {
V_22 = F_31 ( V_5 ) ;
if ( V_22 ) {
F_32 ( & V_5 -> V_8 -> V_29 ,
L_3 ) ;
F_33 ( V_5 ) ;
return V_22 ;
}
}
return 0 ;
}
static void F_33 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_48 , V_49 ;
F_13 ( V_8 ) ;
F_34 ( V_5 , V_50 |
V_51 ,
V_5 -> V_52 , 0 , 0 , NULL ) ;
V_5 -> V_53 = false ;
for ( V_48 = 0 ; V_48 < V_5 -> V_54 ; V_48 ++ )
V_5 -> V_55 [ V_48 ] . V_56 -> V_57 ( V_5 , & V_5 -> V_55 [ V_48 ] ) ;
V_5 -> V_54 = 0 ;
F_27 ( V_5 -> V_55 ) ;
V_5 -> V_55 = NULL ;
F_35 ( V_5 ) ;
for ( V_49 = V_58 ; V_49 <= V_59 ; V_49 ++ ) {
if ( ! V_5 -> V_60 [ V_49 ] )
continue;
F_36 ( V_8 , V_5 -> V_60 [ V_49 ] ) ;
F_37 ( V_8 , 1 << V_49 ) ;
V_5 -> V_60 [ V_49 ] = NULL ;
}
V_5 -> V_61 = true ;
if ( F_38 ( V_8 , & V_5 -> V_27 ) ) {
F_39 ( L_4 ,
V_28 , F_19 ( & V_8 -> V_29 ) ) ;
if ( ! V_5 -> V_26 )
goto V_62;
F_16 ( V_8 ) ;
}
F_25 ( V_8 , V_33 , V_34 ) ;
if ( V_5 -> V_26 && ! F_40 ( V_8 ) )
V_5 -> V_61 = false ;
F_41 ( V_8 ) ;
V_62:
F_28 ( V_8 ) ;
F_42 ( V_5 ) ;
if ( ! V_63 )
F_12 ( V_8 , V_64 ) ;
}
static void F_43 ( void * V_65 )
{
struct V_4 * V_5 = V_65 ;
F_44 ( & V_66 ) ;
if ( ! ( -- V_5 -> V_67 ) ) {
F_45 ( V_5 -> V_8 ) ;
F_33 ( V_5 ) ;
}
F_46 ( & V_66 ) ;
F_47 ( V_68 ) ;
}
static int F_48 ( void * V_65 )
{
struct V_4 * V_5 = V_65 ;
int V_22 = 0 ;
if ( ! F_49 ( V_68 ) )
return - V_69 ;
F_44 ( & V_66 ) ;
if ( ! V_5 -> V_67 ) {
V_22 = F_11 ( V_5 ) ;
if ( V_22 )
goto error;
F_50 ( V_5 -> V_8 ) ;
}
V_5 -> V_67 ++ ;
error:
F_46 ( & V_66 ) ;
if ( V_22 )
F_47 ( V_68 ) ;
return V_22 ;
}
static int F_51 ( struct V_4 * V_5 , int V_52 )
{
if ( V_52 == V_70 ) {
T_2 V_71 ;
F_52 ( V_5 -> V_8 , V_72 , & V_71 ) ;
if ( F_30 ( V_73 ) && ! V_5 -> V_31 && V_71 )
return 1 ;
} else if ( V_52 == V_74 ) {
T_2 V_75 ;
T_1 V_36 ;
V_75 = V_5 -> V_8 -> V_76 ;
if ( V_75 ) {
F_24 ( V_5 -> V_8 ,
V_75 + V_77 , & V_36 ) ;
return 1 << ( ( V_36 & V_78 ) >> 1 ) ;
}
} else if ( V_52 == V_79 ) {
T_2 V_75 ;
T_1 V_36 ;
V_75 = V_5 -> V_8 -> V_35 ;
if ( V_75 ) {
F_24 ( V_5 -> V_8 ,
V_75 + V_38 , & V_36 ) ;
return ( V_36 & V_45 ) + 1 ;
}
} else if ( V_52 == V_80 ) {
if ( F_53 ( V_5 -> V_8 ) )
return 1 ;
} else if ( V_52 == V_81 ) {
return 1 ;
}
return 0 ;
}
static int F_54 ( struct V_6 * V_8 , void * V_82 )
{
( * ( int * ) V_82 ) ++ ;
return 0 ;
}
static int F_55 ( struct V_6 * V_8 , void * V_82 )
{
struct V_83 * V_84 = V_82 ;
struct V_85 * V_85 ;
if ( V_84 -> V_86 == V_84 -> V_87 )
return - V_88 ;
V_85 = F_56 ( & V_8 -> V_29 ) ;
if ( ! V_85 )
return - V_89 ;
V_84 -> V_90 [ V_84 -> V_86 ] . V_91 = F_57 ( V_85 ) ;
V_84 -> V_90 [ V_84 -> V_86 ] . V_92 = F_7 ( V_8 -> V_11 ) ;
V_84 -> V_90 [ V_84 -> V_86 ] . V_11 = V_8 -> V_11 -> V_17 ;
V_84 -> V_90 [ V_84 -> V_86 ] . V_93 = V_8 -> V_93 ;
V_84 -> V_86 ++ ;
F_58 ( V_85 ) ;
return 0 ;
}
static int F_59 ( struct V_6 * V_8 , void * V_82 )
{
struct V_94 * V_95 = V_82 ;
struct V_85 * V_96 ;
int V_97 , V_48 ;
V_96 = F_56 ( & V_8 -> V_29 ) ;
if ( ! V_96 )
return - V_89 ;
V_97 = F_57 ( V_96 ) ;
for ( V_48 = 0 ; V_48 < V_95 -> V_98 ; V_48 ++ )
if ( V_95 -> V_99 [ V_48 ] . V_97 == V_97 )
break;
F_58 ( V_96 ) ;
return ( V_48 == V_95 -> V_98 ) ? - V_100 : 0 ;
}
static bool F_60 ( struct V_6 * V_8 , struct V_101 * V_102 )
{
for (; V_8 ; V_8 = V_8 -> V_11 -> V_103 )
if ( V_8 -> V_11 == V_102 -> V_11 )
return ( V_8 -> V_102 == V_102 ) ;
return false ;
}
static int F_61 ( struct V_6 * V_8 , void * V_82 )
{
struct V_104 * V_105 = V_82 ;
if ( ! V_105 -> V_102 || F_60 ( V_8 , V_105 -> V_8 -> V_102 ) )
V_105 -> V_22 = V_105 -> V_106 ( V_8 , V_105 -> V_82 ) ;
return V_105 -> V_22 ;
}
static int F_62 ( struct V_6 * V_8 ,
int (* V_106)( struct V_6 * ,
void * V_82 ) , void * V_82 ,
bool V_102 )
{
struct V_104 V_105 = {
. V_106 = V_106 , . V_82 = V_82 , . V_8 = V_8 , . V_102 = V_102 , . V_22 = 0 ,
} ;
F_63 ( V_8 -> V_11 , F_61 , & V_105 ) ;
return V_105 . V_22 ;
}
static int F_64 ( struct V_4 * V_5 ,
struct V_107 * V_108 )
{
struct V_109 * V_110 ;
struct V_111 * V_112 ;
T_4 V_113 , V_114 ;
int V_115 = 2 , V_48 = 0 ;
V_113 = F_65 ( V_5 -> V_8 , V_5 -> V_40 ) ;
if ( ( ( V_5 -> V_42 & V_116 ) == 0 ) ||
( F_66 ( V_5 -> V_42 + V_5 -> V_44 ) >= V_113 ) )
V_115 = 1 ;
V_114 = sizeof( * V_112 ) + ( V_115 * sizeof( * V_112 -> V_117 ) ) ;
V_110 = F_67 ( V_108 , V_114 ,
V_118 , 1 ) ;
if ( F_68 ( V_110 ) )
return F_69 ( V_110 ) ;
V_112 = F_70 ( V_110 ,
struct V_111 , V_110 ) ;
V_112 -> V_115 = V_115 ;
if ( V_5 -> V_42 & V_116 ) {
V_112 -> V_117 [ V_48 ] . V_119 = 0 ;
V_112 -> V_117 [ V_48 ] . V_114 = V_5 -> V_42 & V_116 ;
V_48 ++ ;
}
if ( F_66 ( V_5 -> V_42 + V_5 -> V_44 ) < V_113 ) {
V_112 -> V_117 [ V_48 ] . V_119 = F_66 ( V_5 -> V_42 +
V_5 -> V_44 ) ;
V_112 -> V_117 [ V_48 ] . V_114 = V_113 - V_112 -> V_117 [ V_48 ] . V_119 ;
V_48 ++ ;
}
return 0 ;
}
static int F_71 ( struct V_4 * V_5 ,
struct V_107 * V_108 ,
unsigned int type , unsigned int V_120 )
{
struct V_109 * V_110 ;
struct V_121 * V_122 ;
V_110 = F_67 ( V_108 , sizeof( * V_122 ) ,
V_123 , 1 ) ;
if ( F_68 ( V_110 ) )
return F_69 ( V_110 ) ;
V_122 = F_70 ( V_110 , struct V_121 , V_110 ) ;
V_122 -> type = type ;
V_122 -> V_120 = V_120 ;
return 0 ;
}
int F_72 ( struct V_4 * V_5 ,
unsigned int type , unsigned int V_120 ,
const struct V_124 * V_56 ,
T_4 V_114 , T_3 V_36 , void * V_82 )
{
struct V_125 * V_55 ;
V_55 = F_73 ( V_5 -> V_55 ,
( V_5 -> V_54 + 1 ) * sizeof( * V_55 ) ,
V_126 ) ;
if ( ! V_55 )
return - V_127 ;
V_5 -> V_55 = V_55 ;
V_5 -> V_55 [ V_5 -> V_54 ] . type = type ;
V_5 -> V_55 [ V_5 -> V_54 ] . V_120 = V_120 ;
V_5 -> V_55 [ V_5 -> V_54 ] . V_56 = V_56 ;
V_5 -> V_55 [ V_5 -> V_54 ] . V_114 = V_114 ;
V_5 -> V_55 [ V_5 -> V_54 ] . V_36 = V_36 ;
V_5 -> V_55 [ V_5 -> V_54 ] . V_82 = V_82 ;
V_5 -> V_54 ++ ;
return 0 ;
}
static long F_74 ( void * V_65 ,
unsigned int V_23 , unsigned long V_128 )
{
struct V_4 * V_5 = V_65 ;
unsigned long V_129 ;
if ( V_23 == V_130 ) {
struct V_131 V_95 ;
V_129 = F_75 ( struct V_131 , V_132 ) ;
if ( F_76 ( & V_95 , ( void V_133 * ) V_128 , V_129 ) )
return - V_134 ;
if ( V_95 . V_135 < V_129 )
return - V_100 ;
V_95 . V_36 = V_136 ;
if ( V_5 -> V_26 )
V_95 . V_36 |= V_137 ;
V_95 . V_54 = V_138 + V_5 -> V_54 ;
V_95 . V_132 = V_139 ;
return F_77 ( ( void V_133 * ) V_128 , & V_95 , V_129 ) ?
- V_134 : 0 ;
} else if ( V_23 == V_140 ) {
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_141 V_95 ;
struct V_107 V_108 = { . V_142 = NULL , . V_114 = 0 } ;
int V_48 , V_22 ;
V_129 = F_75 ( struct V_141 , V_119 ) ;
if ( F_76 ( & V_95 , ( void V_133 * ) V_128 , V_129 ) )
return - V_134 ;
if ( V_95 . V_135 < V_129 )
return - V_100 ;
switch ( V_95 . V_143 ) {
case V_144 :
V_95 . V_119 = F_78 ( V_95 . V_143 ) ;
V_95 . V_114 = V_8 -> V_145 ;
V_95 . V_36 = V_146 |
V_147 ;
break;
case V_148 ... V_149 :
V_95 . V_119 = F_78 ( V_95 . V_143 ) ;
V_95 . V_114 = F_65 ( V_8 , V_95 . V_143 ) ;
if ( ! V_95 . V_114 ) {
V_95 . V_36 = 0 ;
break;
}
V_95 . V_36 = V_146 |
V_147 ;
if ( F_30 ( V_150 ) &&
F_79 ( V_8 , V_95 . V_143 ) &
V_151 && V_95 . V_114 >= V_152 ) {
V_95 . V_36 |= V_153 ;
if ( V_95 . V_143 == V_5 -> V_40 ) {
V_22 = F_64 ( V_5 , & V_108 ) ;
if ( V_22 )
return V_22 ;
}
}
break;
case V_154 :
{
void T_5 * V_155 ;
T_4 V_114 ;
V_95 . V_119 = F_78 ( V_95 . V_143 ) ;
V_95 . V_36 = 0 ;
V_95 . V_114 = F_65 ( V_8 , V_95 . V_143 ) ;
if ( ! V_95 . V_114 ) {
if ( V_8 -> V_156 [ V_157 ] . V_36 &
V_158 )
V_95 . V_114 = 0x20000 ;
else
break;
}
V_155 = F_80 ( V_8 , & V_114 ) ;
if ( ! V_155 || ! V_114 ) {
V_95 . V_114 = 0 ;
break;
}
F_81 ( V_8 , V_155 ) ;
V_95 . V_36 = V_146 ;
break;
}
case V_159 :
if ( ! V_5 -> V_46 )
return - V_100 ;
V_95 . V_119 = F_78 ( V_95 . V_143 ) ;
V_95 . V_114 = 0xc0000 ;
V_95 . V_36 = V_146 |
V_147 ;
break;
default:
if ( V_95 . V_143 >=
V_138 + V_5 -> V_54 )
return - V_100 ;
V_48 = V_95 . V_143 - V_138 ;
V_95 . V_119 = F_78 ( V_95 . V_143 ) ;
V_95 . V_114 = V_5 -> V_55 [ V_48 ] . V_114 ;
V_95 . V_36 = V_5 -> V_55 [ V_48 ] . V_36 ;
V_22 = F_71 ( V_5 , & V_108 ,
V_5 -> V_55 [ V_48 ] . type ,
V_5 -> V_55 [ V_48 ] . V_120 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_108 . V_114 ) {
V_95 . V_36 |= V_160 ;
if ( V_95 . V_135 < sizeof( V_95 ) + V_108 . V_114 ) {
V_95 . V_135 = sizeof( V_95 ) + V_108 . V_114 ;
V_95 . V_161 = 0 ;
} else {
F_82 ( & V_108 , sizeof( V_95 ) ) ;
if ( F_77 ( ( void V_133 * ) V_128 +
sizeof( V_95 ) , V_108 . V_142 ,
V_108 . V_114 ) ) {
F_27 ( V_108 . V_142 ) ;
return - V_134 ;
}
V_95 . V_161 = sizeof( V_95 ) ;
}
F_27 ( V_108 . V_142 ) ;
}
return F_77 ( ( void V_133 * ) V_128 , & V_95 , V_129 ) ?
- V_134 : 0 ;
} else if ( V_23 == V_162 ) {
struct V_163 V_95 ;
V_129 = F_75 ( struct V_163 , V_98 ) ;
if ( F_76 ( & V_95 , ( void V_133 * ) V_128 , V_129 ) )
return - V_134 ;
if ( V_95 . V_135 < V_129 || V_95 . V_143 >= V_139 )
return - V_100 ;
switch ( V_95 . V_143 ) {
case V_70 ... V_79 :
case V_81 :
break;
case V_80 :
if ( F_53 ( V_5 -> V_8 ) )
break;
default:
return - V_100 ;
}
V_95 . V_36 = V_164 ;
V_95 . V_98 = F_51 ( V_5 , V_95 . V_143 ) ;
if ( V_95 . V_143 == V_70 )
V_95 . V_36 |= ( V_165 |
V_166 ) ;
else
V_95 . V_36 |= V_167 ;
return F_77 ( ( void V_133 * ) V_128 , & V_95 , V_129 ) ?
- V_134 : 0 ;
} else if ( V_23 == V_168 ) {
struct V_169 V_170 ;
T_2 * V_82 = NULL ;
int V_22 = 0 ;
V_129 = F_75 ( struct V_169 , V_98 ) ;
if ( F_76 ( & V_170 , ( void V_133 * ) V_128 , V_129 ) )
return - V_134 ;
if ( V_170 . V_135 < V_129 || V_170 . V_143 >= V_139 ||
V_170 . V_36 & ~ ( V_171 |
V_172 ) )
return - V_100 ;
if ( ! ( V_170 . V_36 & V_50 ) ) {
T_4 V_114 ;
int V_87 = F_51 ( V_5 , V_170 . V_143 ) ;
if ( V_170 . V_36 & V_173 )
V_114 = sizeof( V_174 ) ;
else if ( V_170 . V_36 & V_175 )
V_114 = sizeof( V_176 ) ;
else
return - V_100 ;
if ( V_170 . V_135 - V_129 < V_170 . V_98 * V_114 ||
V_170 . V_177 >= V_87 || V_170 . V_177 + V_170 . V_98 > V_87 )
return - V_100 ;
V_82 = F_83 ( ( void V_133 * ) ( V_128 + V_129 ) ,
V_170 . V_98 * V_114 ) ;
if ( F_68 ( V_82 ) )
return F_69 ( V_82 ) ;
}
F_44 ( & V_5 -> V_178 ) ;
V_22 = F_34 ( V_5 , V_170 . V_36 , V_170 . V_143 ,
V_170 . V_177 , V_170 . V_98 , V_82 ) ;
F_46 ( & V_5 -> V_178 ) ;
F_27 ( V_82 ) ;
return V_22 ;
} else if ( V_23 == V_179 ) {
return V_5 -> V_26 ?
F_40 ( V_5 -> V_8 ) : - V_100 ;
} else if ( V_23 == V_180 ) {
struct V_181 V_170 ;
struct V_83 V_84 = { 0 } ;
struct V_182 * V_90 = NULL ;
bool V_102 = false ;
int V_22 = 0 ;
V_129 = F_75 ( struct V_181 , V_98 ) ;
if ( F_76 ( & V_170 , ( void V_133 * ) V_128 , V_129 ) )
return - V_134 ;
if ( V_170 . V_135 < V_129 )
return - V_100 ;
V_170 . V_36 = 0 ;
if ( ! F_84 ( V_5 -> V_8 -> V_102 ) )
V_102 = true ;
else if ( F_85 ( V_5 -> V_8 -> V_11 ) )
return - V_69 ;
V_22 = F_62 ( V_5 -> V_8 ,
F_54 ,
& V_84 . V_87 , V_102 ) ;
if ( V_22 )
return V_22 ;
F_86 ( ! V_84 . V_87 ) ;
if ( V_170 . V_135 < sizeof( V_170 ) + ( V_84 . V_87 * sizeof( * V_90 ) ) ) {
V_22 = - V_183 ;
V_170 . V_98 = V_84 . V_87 ;
goto V_184;
}
V_90 = F_87 ( V_84 . V_87 , sizeof( * V_90 ) , V_126 ) ;
if ( ! V_90 )
return - V_127 ;
V_84 . V_90 = V_90 ;
V_22 = F_62 ( V_5 -> V_8 ,
F_55 ,
& V_84 , V_102 ) ;
if ( ! V_22 )
V_170 . V_98 = V_84 . V_86 ;
V_184:
if ( F_77 ( ( void V_133 * ) V_128 , & V_170 , V_129 ) )
V_22 = - V_134 ;
if ( ! V_22 ) {
if ( F_77 ( ( void V_133 * ) ( V_128 + V_129 ) , V_90 ,
V_170 . V_98 * sizeof( * V_90 ) ) )
V_22 = - V_134 ;
}
F_27 ( V_90 ) ;
return V_22 ;
} else if ( V_23 == V_185 ) {
struct V_186 V_170 ;
V_176 * V_187 ;
struct V_188 * V_99 ;
struct V_94 V_95 ;
bool V_102 = false ;
int V_48 , V_98 = 0 , V_22 = 0 ;
V_129 = F_75 ( struct V_186 , V_98 ) ;
if ( F_76 ( & V_170 , ( void V_133 * ) V_128 , V_129 ) )
return - V_134 ;
if ( V_170 . V_135 < V_129 || V_170 . V_36 )
return - V_100 ;
if ( ! F_84 ( V_5 -> V_8 -> V_102 ) )
V_102 = true ;
else if ( F_85 ( V_5 -> V_8 -> V_11 ) )
return - V_69 ;
V_22 = F_62 ( V_5 -> V_8 ,
F_54 ,
& V_98 , V_102 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_170 . V_98 || V_170 . V_98 > V_98 )
return - V_100 ;
V_187 = F_87 ( V_170 . V_98 , sizeof( * V_187 ) , V_126 ) ;
V_99 = F_87 ( V_170 . V_98 , sizeof( * V_99 ) , V_126 ) ;
if ( ! V_187 || ! V_99 ) {
F_27 ( V_187 ) ;
F_27 ( V_99 ) ;
return - V_127 ;
}
if ( F_76 ( V_187 , ( void V_133 * ) ( V_128 + V_129 ) ,
V_170 . V_98 * sizeof( * V_187 ) ) ) {
F_27 ( V_187 ) ;
F_27 ( V_99 ) ;
return - V_134 ;
}
for ( V_48 = 0 ; V_48 < V_170 . V_98 ; V_48 ++ ) {
struct V_189 * V_96 ;
struct V_190 V_191 = F_88 ( V_187 [ V_48 ] ) ;
if ( ! V_191 . V_192 ) {
V_22 = - V_193 ;
break;
}
V_96 = F_89 ( V_191 . V_192 ) ;
F_90 ( V_191 ) ;
if ( F_68 ( V_96 ) ) {
V_22 = F_69 ( V_96 ) ;
break;
}
V_99 [ V_48 ] . V_96 = V_96 ;
V_99 [ V_48 ] . V_97 = F_91 ( V_96 ) ;
}
F_27 ( V_187 ) ;
if ( V_22 )
goto V_194;
V_95 . V_98 = V_170 . V_98 ;
V_95 . V_99 = V_99 ;
V_22 = F_62 ( V_5 -> V_8 ,
F_59 ,
& V_95 , V_102 ) ;
if ( ! V_22 )
V_22 = V_102 ? F_92 ( V_5 -> V_8 -> V_102 ) :
F_93 ( V_5 -> V_8 -> V_11 ) ;
V_194:
for ( V_48 -- ; V_48 >= 0 ; V_48 -- )
F_94 ( V_99 [ V_48 ] . V_96 ) ;
F_27 ( V_99 ) ;
return V_22 ;
}
return - V_195 ;
}
static T_6 F_95 ( void * V_65 , char V_133 * V_142 ,
T_4 V_98 , T_7 * V_196 , bool V_197 )
{
unsigned int V_143 = F_96 ( * V_196 ) ;
struct V_4 * V_5 = V_65 ;
if ( V_143 >= V_138 + V_5 -> V_54 )
return - V_100 ;
switch ( V_143 ) {
case V_144 :
return F_97 ( V_5 , V_142 , V_98 , V_196 , V_197 ) ;
case V_154 :
if ( V_197 )
return - V_100 ;
return F_98 ( V_5 , V_142 , V_98 , V_196 , false ) ;
case V_148 ... V_149 :
return F_98 ( V_5 , V_142 , V_98 , V_196 , V_197 ) ;
case V_159 :
return F_99 ( V_5 , V_142 , V_98 , V_196 , V_197 ) ;
default:
V_143 -= V_138 ;
return V_5 -> V_55 [ V_143 ] . V_56 -> V_198 ( V_5 , V_142 ,
V_98 , V_196 , V_197 ) ;
}
return - V_100 ;
}
static T_6 F_100 ( void * V_65 , char V_133 * V_142 ,
T_4 V_98 , T_7 * V_196 )
{
if ( ! V_98 )
return 0 ;
return F_95 ( V_65 , V_142 , V_98 , V_196 , false ) ;
}
static T_6 F_101 ( void * V_65 , const char V_133 * V_142 ,
T_4 V_98 , T_7 * V_196 )
{
if ( ! V_98 )
return 0 ;
return F_95 ( V_65 , ( char V_133 * ) V_142 , V_98 , V_196 , true ) ;
}
static int F_102 ( void * V_65 , struct V_199 * V_200 )
{
struct V_4 * V_5 = V_65 ;
struct V_6 * V_8 = V_5 -> V_8 ;
unsigned int V_143 ;
T_8 V_201 , V_202 , V_203 , V_204 ;
int V_22 ;
V_143 = V_200 -> V_205 >> ( V_206 - V_207 ) ;
if ( V_200 -> V_208 < V_200 -> V_209 )
return - V_100 ;
if ( ( V_200 -> V_210 & V_211 ) == 0 )
return - V_100 ;
if ( V_143 >= V_154 )
return - V_100 ;
if ( ! ( F_79 ( V_8 , V_143 ) & V_151 ) )
return - V_100 ;
V_201 = F_65 ( V_8 , V_143 ) ;
V_202 = V_200 -> V_208 - V_200 -> V_209 ;
V_203 = V_200 -> V_205 &
( ( 1U << ( V_206 - V_207 ) ) - 1 ) ;
V_204 = V_203 << V_207 ;
if ( V_201 < V_152 || V_204 + V_202 > V_201 )
return - V_100 ;
if ( V_143 == V_5 -> V_40 ) {
if ( ! ( V_204 >= V_5 -> V_42 + V_5 -> V_44 ||
V_204 + V_202 <= V_5 -> V_42 ) )
return - V_100 ;
}
if ( ! V_5 -> V_60 [ V_143 ] ) {
V_22 = F_103 ( V_8 ,
1 << V_143 , L_5 ) ;
if ( V_22 )
return V_22 ;
V_5 -> V_60 [ V_143 ] = F_104 ( V_8 , V_143 , 0 ) ;
}
V_200 -> V_212 = V_5 ;
V_200 -> V_213 = F_105 ( V_200 -> V_213 ) ;
V_200 -> V_205 = ( F_106 ( V_8 , V_143 ) >> V_207 ) + V_203 ;
return F_107 ( V_200 , V_200 -> V_209 , V_200 -> V_205 ,
V_202 , V_200 -> V_213 ) ;
}
static void F_108 ( void * V_65 , unsigned int V_98 )
{
struct V_4 * V_5 = V_65 ;
F_44 ( & V_5 -> V_178 ) ;
if ( V_5 -> V_214 ) {
if ( ! ( V_98 % 10 ) )
F_109 ( & V_5 -> V_8 -> V_29 ,
L_6 ,
V_98 ) ;
F_110 ( V_5 -> V_214 , 1 ) ;
} else if ( V_98 == 0 ) {
F_32 ( & V_5 -> V_8 -> V_29 ,
L_7 ) ;
}
F_46 ( & V_5 -> V_178 ) ;
}
static int F_111 ( struct V_6 * V_8 , const struct V_215 * V_97 )
{
struct V_4 * V_5 ;
struct V_85 * V_96 ;
int V_22 ;
if ( V_8 -> V_216 != V_217 )
return - V_100 ;
V_96 = F_112 ( & V_8 -> V_29 ) ;
if ( ! V_96 )
return - V_100 ;
V_5 = F_113 ( sizeof( * V_5 ) , V_126 ) ;
if ( ! V_5 ) {
F_114 ( V_96 , & V_8 -> V_29 ) ;
return - V_127 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_52 = V_139 ;
F_115 ( & V_5 -> V_178 ) ;
F_116 ( & V_5 -> V_218 ) ;
V_22 = F_117 ( & V_8 -> V_29 , & V_219 , V_5 ) ;
if ( V_22 ) {
F_114 ( V_96 , & V_8 -> V_29 ) ;
F_27 ( V_5 ) ;
return V_22 ;
}
if ( F_9 ( V_8 ) ) {
F_118 ( V_8 , V_5 , NULL , F_3 ) ;
F_119 ( V_8 ,
F_3 ( V_5 , false ) ) ;
}
if ( ! V_63 ) {
F_12 ( V_8 , V_25 ) ;
F_12 ( V_8 , V_64 ) ;
}
return V_22 ;
}
static void F_120 ( struct V_6 * V_8 )
{
struct V_4 * V_5 ;
V_5 = F_121 ( & V_8 -> V_29 ) ;
if ( ! V_5 )
return;
F_114 ( V_8 -> V_29 . V_85 , & V_8 -> V_29 ) ;
F_27 ( V_5 -> V_55 ) ;
F_27 ( V_5 ) ;
if ( F_9 ( V_8 ) ) {
F_118 ( V_8 , NULL , NULL , NULL ) ;
F_119 ( V_8 ,
V_12 | V_13 |
V_14 | V_15 ) ;
}
if ( ! V_63 )
F_12 ( V_8 , V_25 ) ;
}
static T_9 F_122 ( struct V_6 * V_8 ,
T_10 V_220 )
{
struct V_4 * V_5 ;
struct V_221 * V_21 ;
V_21 = F_123 ( & V_8 -> V_29 ) ;
if ( V_21 == NULL )
return V_222 ;
V_5 = F_124 ( V_21 ) ;
if ( V_5 == NULL ) {
F_125 ( V_21 ) ;
return V_222 ;
}
F_44 ( & V_5 -> V_178 ) ;
if ( V_5 -> V_223 )
F_110 ( V_5 -> V_223 , 1 ) ;
F_46 ( & V_5 -> V_178 ) ;
F_125 ( V_21 ) ;
return V_224 ;
}
static int F_126 ( struct V_6 * V_8 , void * V_82 )
{
struct V_225 * V_226 = V_82 ;
struct V_221 * V_21 ;
if ( V_226 -> V_227 == V_226 -> V_228 )
return - V_183 ;
V_21 = F_123 ( & V_8 -> V_29 ) ;
if ( ! V_21 )
return - V_100 ;
if ( F_127 ( V_8 ) != & V_229 ) {
F_125 ( V_21 ) ;
return - V_230 ;
}
V_226 -> V_90 [ V_226 -> V_227 ++ ] = V_21 ;
return 0 ;
}
static void F_42 ( struct V_4 * V_5 )
{
struct V_225 V_226 = { . V_227 = 0 } ;
int V_48 = 0 , V_22 = - V_100 ;
bool V_61 = false , V_102 = false ;
struct V_4 * V_7 ;
if ( ! F_84 ( V_5 -> V_8 -> V_102 ) )
V_102 = true ;
else if ( F_85 ( V_5 -> V_8 -> V_11 ) )
return;
if ( F_62 ( V_5 -> V_8 , F_54 ,
& V_48 , V_102 ) || ! V_48 )
return;
V_226 . V_228 = V_48 ;
V_226 . V_90 = F_87 ( V_48 , sizeof( struct V_221 * ) , V_126 ) ;
if ( ! V_226 . V_90 )
return;
if ( F_62 ( V_5 -> V_8 ,
F_126 , & V_226 , V_102 ) )
goto V_231;
for ( V_48 = 0 ; V_48 < V_226 . V_227 ; V_48 ++ ) {
V_7 = F_124 ( V_226 . V_90 [ V_48 ] ) ;
if ( V_7 -> V_61 )
V_61 = true ;
if ( V_7 -> V_67 )
goto V_231;
}
if ( V_61 )
V_22 = V_102 ? F_92 ( V_5 -> V_8 -> V_102 ) :
F_93 ( V_5 -> V_8 -> V_11 ) ;
V_231:
for ( V_48 = 0 ; V_48 < V_226 . V_227 ; V_48 ++ ) {
V_7 = F_124 ( V_226 . V_90 [ V_48 ] ) ;
if ( ! V_22 )
V_7 -> V_61 = false ;
if ( ! V_7 -> V_67 && ! V_63 )
F_12 ( V_7 -> V_8 , V_64 ) ;
F_125 ( V_226 . V_90 [ V_48 ] ) ;
}
F_27 ( V_226 . V_90 ) ;
}
static void T_11 F_128 ( void )
{
F_129 ( & V_229 ) ;
F_130 () ;
}
static void T_12 F_131 ( void )
{
char * V_232 , * V_97 ;
int V_233 ;
if ( V_234 [ 0 ] == '\0' )
return;
V_232 = V_234 ;
while ( ( V_97 = F_132 ( & V_232 , L_8 ) ) ) {
unsigned int V_19 , V_21 , V_235 = V_236 ,
V_237 = V_236 , V_18 = 0 , V_238 = 0 ;
int V_239 ;
if ( ! strlen ( V_97 ) )
continue;
V_239 = sscanf ( V_97 , L_9 ,
& V_19 , & V_21 , & V_235 , & V_237 ,
& V_18 , & V_238 ) ;
if ( V_239 < 2 ) {
F_133 ( L_10 , V_97 ) ;
continue;
}
V_233 = F_134 ( & V_229 , V_19 , V_21 ,
V_235 , V_237 , V_18 , V_238 , 0 ) ;
if ( V_233 )
F_133 ( L_11 ,
V_19 , V_21 , V_235 , V_237 ,
V_18 , V_238 , V_233 ) ;
else
F_39 ( L_12 ,
V_19 , V_21 , V_235 , V_237 ,
V_18 , V_238 ) ;
}
}
static int T_12 F_135 ( void )
{
int V_22 ;
V_22 = F_136 () ;
if ( V_22 )
return V_22 ;
V_22 = F_137 ( & V_229 ) ;
if ( V_22 )
goto V_240;
F_131 () ;
return 0 ;
V_240:
F_130 () ;
return V_22 ;
}
