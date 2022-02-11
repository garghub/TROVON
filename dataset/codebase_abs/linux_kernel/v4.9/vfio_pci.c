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
static void F_10 ( struct V_4 * V_5 )
{
struct V_19 * V_20 ;
int V_21 ;
struct V_22 * V_23 ;
F_11 ( & V_5 -> V_24 ) ;
for ( V_21 = V_25 ; V_21 <= V_26 ; V_21 ++ ) {
V_20 = V_5 -> V_8 -> V_19 + V_21 ;
if ( ! F_12 ( V_27 ) )
goto V_28;
if ( ! ( V_20 -> V_29 & V_30 ) )
goto V_28;
if ( ! F_13 ( V_20 ) )
goto V_28;
if ( F_13 ( V_20 ) >= V_31 ) {
V_5 -> V_32 [ V_21 ] = true ;
continue;
}
if ( ! ( V_20 -> V_33 & ~ V_34 ) ) {
V_23 = F_14 ( sizeof( * V_23 ) , V_35 ) ;
if ( V_23 == NULL )
goto V_28;
V_23 -> V_19 . V_36 = L_1 ;
V_23 -> V_19 . V_33 = V_20 -> V_37 + 1 ;
V_23 -> V_19 . V_37 = V_20 -> V_33 + V_31 - 1 ;
V_23 -> V_19 . V_29 = V_20 -> V_29 ;
if ( F_15 ( V_20 -> V_38 ,
& V_23 -> V_19 ) ) {
F_16 ( V_23 ) ;
goto V_28;
}
V_23 -> V_39 = V_21 ;
F_17 ( & V_23 -> V_40 ,
& V_5 -> V_24 ) ;
V_5 -> V_32 [ V_21 ] = true ;
continue;
}
V_28:
V_5 -> V_32 [ V_21 ] = false ;
}
}
static bool F_18 ( struct V_6 * V_8 )
{
switch ( V_8 -> V_41 ) {
case V_42 :
switch ( V_8 -> V_43 ) {
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
static int F_19 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_44 ;
T_1 V_45 ;
T_2 V_46 ;
F_20 ( V_8 , V_47 ) ;
F_21 ( V_8 ) ;
V_44 = F_22 ( V_8 ) ;
if ( V_44 )
return V_44 ;
V_5 -> V_48 = ( F_23 ( V_8 ) == 0 ) ;
F_24 ( V_8 ) ;
V_5 -> V_49 = F_25 ( V_8 ) ;
if ( ! V_5 -> V_49 )
F_26 ( L_2 ,
V_50 , F_27 ( & V_8 -> V_51 ) ) ;
if ( F_28 ( ! V_52 ) ) {
if ( F_18 ( V_8 ) ) {
F_29 ( & V_8 -> V_51 , L_3 ) ;
V_5 -> V_53 = true ;
F_30 ( V_8 , 0 ) ;
} else
V_5 -> V_54 = F_31 ( V_8 ) ;
}
F_32 ( V_8 , V_55 , & V_45 ) ;
if ( V_5 -> V_54 && ( V_45 & V_56 ) ) {
V_45 &= ~ V_56 ;
F_33 ( V_8 , V_55 , V_45 ) ;
}
V_44 = F_34 ( V_5 ) ;
if ( V_44 ) {
F_16 ( V_5 -> V_49 ) ;
V_5 -> V_49 = NULL ;
F_35 ( V_8 ) ;
return V_44 ;
}
V_46 = V_8 -> V_57 ;
if ( V_46 ) {
T_1 V_29 ;
T_3 V_58 ;
F_32 ( V_8 , V_46 + V_59 , & V_29 ) ;
F_36 ( V_8 , V_46 + V_60 , & V_58 ) ;
V_5 -> V_61 = V_58 & V_62 ;
V_5 -> V_63 = V_58 & V_64 ;
V_5 -> V_65 = ( ( V_29 & V_66 ) + 1 ) * 16 ;
} else
V_5 -> V_61 = 0xFF ;
if ( ! F_1 () && F_9 ( V_8 ) )
V_5 -> V_67 = true ;
if ( F_9 ( V_8 ) &&
V_8 -> V_41 == V_42 &&
F_12 ( V_68 ) ) {
V_44 = F_37 ( V_5 ) ;
if ( V_44 ) {
F_38 ( & V_5 -> V_8 -> V_51 ,
L_4 ) ;
F_39 ( V_5 ) ;
return V_44 ;
}
}
F_10 ( V_5 ) ;
return 0 ;
}
static void F_39 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_22 * V_23 , * V_7 ;
int V_69 , V_21 ;
F_21 ( V_8 ) ;
F_40 ( V_5 , V_70 |
V_71 ,
V_5 -> V_72 , 0 , 0 , NULL ) ;
V_5 -> V_73 = false ;
for ( V_69 = 0 ; V_69 < V_5 -> V_74 ; V_69 ++ )
V_5 -> V_75 [ V_69 ] . V_76 -> V_77 ( V_5 , & V_5 -> V_75 [ V_69 ] ) ;
V_5 -> V_74 = 0 ;
F_16 ( V_5 -> V_75 ) ;
V_5 -> V_75 = NULL ;
F_41 ( V_5 ) ;
for ( V_21 = V_25 ; V_21 <= V_26 ; V_21 ++ ) {
if ( ! V_5 -> V_78 [ V_21 ] )
continue;
F_42 ( V_8 , V_5 -> V_78 [ V_21 ] ) ;
F_43 ( V_8 , 1 << V_21 ) ;
V_5 -> V_78 [ V_21 ] = NULL ;
}
F_44 (dummy_res, tmp,
&vdev->dummy_resources_list, res_next) {
F_45 ( & V_23 -> V_40 ) ;
F_46 ( & V_23 -> V_19 ) ;
F_16 ( V_23 ) ;
}
V_5 -> V_79 = true ;
if ( F_47 ( V_8 , & V_5 -> V_49 ) ) {
F_48 ( L_5 ,
V_50 , F_27 ( & V_8 -> V_51 ) ) ;
if ( ! V_5 -> V_48 )
goto V_80;
F_24 ( V_8 ) ;
}
F_33 ( V_8 , V_55 , V_56 ) ;
if ( V_5 -> V_48 && ! F_49 ( V_8 ) )
V_5 -> V_79 = false ;
F_50 ( V_8 ) ;
V_80:
F_35 ( V_8 ) ;
F_51 ( V_5 ) ;
if ( ! V_81 )
F_20 ( V_8 , V_82 ) ;
}
static void F_52 ( void * V_83 )
{
struct V_4 * V_5 = V_83 ;
F_53 ( & V_84 ) ;
if ( ! ( -- V_5 -> V_85 ) ) {
F_54 ( V_5 -> V_8 ) ;
F_39 ( V_5 ) ;
}
F_55 ( & V_84 ) ;
F_56 ( V_86 ) ;
}
static int F_57 ( void * V_83 )
{
struct V_4 * V_5 = V_83 ;
int V_44 = 0 ;
if ( ! F_58 ( V_86 ) )
return - V_87 ;
F_53 ( & V_84 ) ;
if ( ! V_5 -> V_85 ) {
V_44 = F_19 ( V_5 ) ;
if ( V_44 )
goto error;
F_59 ( V_5 -> V_8 ) ;
}
V_5 -> V_85 ++ ;
error:
F_55 ( & V_84 ) ;
if ( V_44 )
F_56 ( V_86 ) ;
return V_44 ;
}
static int F_60 ( struct V_4 * V_5 , int V_72 )
{
if ( V_72 == V_88 ) {
T_2 V_89 ;
F_61 ( V_5 -> V_8 , V_90 , & V_89 ) ;
if ( F_12 ( V_91 ) && ! V_5 -> V_53 && V_89 )
return 1 ;
} else if ( V_72 == V_92 ) {
T_2 V_93 ;
T_1 V_29 ;
V_93 = V_5 -> V_8 -> V_94 ;
if ( V_93 ) {
F_32 ( V_5 -> V_8 ,
V_93 + V_95 , & V_29 ) ;
return 1 << ( ( V_29 & V_96 ) >> 1 ) ;
}
} else if ( V_72 == V_97 ) {
T_2 V_93 ;
T_1 V_29 ;
V_93 = V_5 -> V_8 -> V_57 ;
if ( V_93 ) {
F_32 ( V_5 -> V_8 ,
V_93 + V_59 , & V_29 ) ;
return ( V_29 & V_66 ) + 1 ;
}
} else if ( V_72 == V_98 ) {
if ( F_62 ( V_5 -> V_8 ) )
return 1 ;
} else if ( V_72 == V_99 ) {
return 1 ;
}
return 0 ;
}
static int F_63 ( struct V_6 * V_8 , void * V_100 )
{
( * ( int * ) V_100 ) ++ ;
return 0 ;
}
static int F_64 ( struct V_6 * V_8 , void * V_100 )
{
struct V_101 * V_102 = V_100 ;
struct V_103 * V_103 ;
if ( V_102 -> V_104 == V_102 -> V_105 )
return - V_106 ;
V_103 = F_65 ( & V_8 -> V_51 ) ;
if ( ! V_103 )
return - V_107 ;
V_102 -> V_108 [ V_102 -> V_104 ] . V_109 = F_66 ( V_103 ) ;
V_102 -> V_108 [ V_102 -> V_104 ] . V_110 = F_7 ( V_8 -> V_11 ) ;
V_102 -> V_108 [ V_102 -> V_104 ] . V_11 = V_8 -> V_11 -> V_17 ;
V_102 -> V_108 [ V_102 -> V_104 ] . V_111 = V_8 -> V_111 ;
V_102 -> V_104 ++ ;
F_67 ( V_103 ) ;
return 0 ;
}
static int F_68 ( struct V_6 * V_8 , void * V_100 )
{
struct V_112 * V_113 = V_100 ;
struct V_103 * V_114 ;
int V_115 , V_69 ;
V_114 = F_65 ( & V_8 -> V_51 ) ;
if ( ! V_114 )
return - V_107 ;
V_115 = F_66 ( V_114 ) ;
for ( V_69 = 0 ; V_69 < V_113 -> V_116 ; V_69 ++ )
if ( V_113 -> V_117 [ V_69 ] . V_115 == V_115 )
break;
F_67 ( V_114 ) ;
return ( V_69 == V_113 -> V_116 ) ? - V_118 : 0 ;
}
static bool F_69 ( struct V_6 * V_8 , struct V_119 * V_120 )
{
for (; V_8 ; V_8 = V_8 -> V_11 -> V_121 )
if ( V_8 -> V_11 == V_120 -> V_11 )
return ( V_8 -> V_120 == V_120 ) ;
return false ;
}
static int F_70 ( struct V_6 * V_8 , void * V_100 )
{
struct V_122 * V_123 = V_100 ;
if ( ! V_123 -> V_120 || F_69 ( V_8 , V_123 -> V_8 -> V_120 ) )
V_123 -> V_44 = V_123 -> V_124 ( V_8 , V_123 -> V_100 ) ;
return V_123 -> V_44 ;
}
static int F_71 ( struct V_6 * V_8 ,
int (* V_124)( struct V_6 * ,
void * V_100 ) , void * V_100 ,
bool V_120 )
{
struct V_122 V_123 = {
. V_124 = V_124 , . V_100 = V_100 , . V_8 = V_8 , . V_120 = V_120 , . V_44 = 0 ,
} ;
F_72 ( V_8 -> V_11 , F_70 , & V_123 ) ;
return V_123 . V_44 ;
}
static int F_73 ( struct V_4 * V_5 ,
struct V_125 * V_126 )
{
struct V_127 * V_128 ;
struct V_129 * V_130 ;
T_4 V_37 , V_131 ;
int V_132 = 2 , V_69 = 0 ;
V_37 = F_74 ( V_5 -> V_8 , V_5 -> V_61 ) ;
if ( ( ( V_5 -> V_63 & V_34 ) == 0 ) ||
( F_75 ( V_5 -> V_63 + V_5 -> V_65 ) >= V_37 ) )
V_132 = 1 ;
V_131 = sizeof( * V_130 ) + ( V_132 * sizeof( * V_130 -> V_133 ) ) ;
V_128 = F_76 ( V_126 , V_131 ,
V_134 , 1 ) ;
if ( F_77 ( V_128 ) )
return F_78 ( V_128 ) ;
V_130 = F_79 ( V_128 ,
struct V_129 , V_128 ) ;
V_130 -> V_132 = V_132 ;
if ( V_5 -> V_63 & V_34 ) {
V_130 -> V_133 [ V_69 ] . V_135 = 0 ;
V_130 -> V_133 [ V_69 ] . V_131 = V_5 -> V_63 & V_34 ;
V_69 ++ ;
}
if ( F_75 ( V_5 -> V_63 + V_5 -> V_65 ) < V_37 ) {
V_130 -> V_133 [ V_69 ] . V_135 = F_75 ( V_5 -> V_63 +
V_5 -> V_65 ) ;
V_130 -> V_133 [ V_69 ] . V_131 = V_37 - V_130 -> V_133 [ V_69 ] . V_135 ;
V_69 ++ ;
}
return 0 ;
}
static int F_80 ( struct V_4 * V_5 ,
struct V_125 * V_126 ,
unsigned int type , unsigned int V_136 )
{
struct V_127 * V_128 ;
struct V_137 * V_138 ;
V_128 = F_76 ( V_126 , sizeof( * V_138 ) ,
V_139 , 1 ) ;
if ( F_77 ( V_128 ) )
return F_78 ( V_128 ) ;
V_138 = F_79 ( V_128 , struct V_137 , V_128 ) ;
V_138 -> type = type ;
V_138 -> V_136 = V_136 ;
return 0 ;
}
int F_81 ( struct V_4 * V_5 ,
unsigned int type , unsigned int V_136 ,
const struct V_140 * V_76 ,
T_4 V_131 , T_3 V_29 , void * V_100 )
{
struct V_141 * V_75 ;
V_75 = F_82 ( V_5 -> V_75 ,
( V_5 -> V_74 + 1 ) * sizeof( * V_75 ) ,
V_35 ) ;
if ( ! V_75 )
return - V_142 ;
V_5 -> V_75 = V_75 ;
V_5 -> V_75 [ V_5 -> V_74 ] . type = type ;
V_5 -> V_75 [ V_5 -> V_74 ] . V_136 = V_136 ;
V_5 -> V_75 [ V_5 -> V_74 ] . V_76 = V_76 ;
V_5 -> V_75 [ V_5 -> V_74 ] . V_131 = V_131 ;
V_5 -> V_75 [ V_5 -> V_74 ] . V_29 = V_29 ;
V_5 -> V_75 [ V_5 -> V_74 ] . V_100 = V_100 ;
V_5 -> V_74 ++ ;
return 0 ;
}
static long F_83 ( void * V_83 ,
unsigned int V_45 , unsigned long V_143 )
{
struct V_4 * V_5 = V_83 ;
unsigned long V_144 ;
if ( V_45 == V_145 ) {
struct V_146 V_113 ;
V_144 = F_84 ( struct V_146 , V_147 ) ;
if ( F_85 ( & V_113 , ( void V_148 * ) V_143 , V_144 ) )
return - V_149 ;
if ( V_113 . V_150 < V_144 )
return - V_118 ;
V_113 . V_29 = V_151 ;
if ( V_5 -> V_48 )
V_113 . V_29 |= V_152 ;
V_113 . V_74 = V_153 + V_5 -> V_74 ;
V_113 . V_147 = V_154 ;
return F_86 ( ( void V_148 * ) V_143 , & V_113 , V_144 ) ?
- V_149 : 0 ;
} else if ( V_45 == V_155 ) {
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_156 V_113 ;
struct V_125 V_126 = { . V_157 = NULL , . V_131 = 0 } ;
int V_69 , V_44 ;
V_144 = F_84 ( struct V_156 , V_135 ) ;
if ( F_85 ( & V_113 , ( void V_148 * ) V_143 , V_144 ) )
return - V_149 ;
if ( V_113 . V_150 < V_144 )
return - V_118 ;
switch ( V_113 . V_39 ) {
case V_158 :
V_113 . V_135 = F_87 ( V_113 . V_39 ) ;
V_113 . V_131 = V_8 -> V_159 ;
V_113 . V_29 = V_160 |
V_161 ;
break;
case V_162 ... V_163 :
V_113 . V_135 = F_87 ( V_113 . V_39 ) ;
V_113 . V_131 = F_74 ( V_8 , V_113 . V_39 ) ;
if ( ! V_113 . V_131 ) {
V_113 . V_29 = 0 ;
break;
}
V_113 . V_29 = V_160 |
V_161 ;
if ( V_5 -> V_32 [ V_113 . V_39 ] ) {
V_113 . V_29 |= V_164 ;
if ( V_113 . V_39 == V_5 -> V_61 ) {
V_44 = F_73 ( V_5 , & V_126 ) ;
if ( V_44 )
return V_44 ;
}
}
break;
case V_165 :
{
void T_5 * V_166 ;
T_4 V_131 ;
V_113 . V_135 = F_87 ( V_113 . V_39 ) ;
V_113 . V_29 = 0 ;
V_113 . V_131 = F_74 ( V_8 , V_113 . V_39 ) ;
if ( ! V_113 . V_131 ) {
if ( V_8 -> V_19 [ V_167 ] . V_29 &
V_168 )
V_113 . V_131 = 0x20000 ;
else
break;
}
V_166 = F_88 ( V_8 , & V_131 ) ;
if ( ! V_166 || ! V_131 ) {
V_113 . V_131 = 0 ;
break;
}
F_89 ( V_8 , V_166 ) ;
V_113 . V_29 = V_160 ;
break;
}
case V_169 :
if ( ! V_5 -> V_67 )
return - V_118 ;
V_113 . V_135 = F_87 ( V_113 . V_39 ) ;
V_113 . V_131 = 0xc0000 ;
V_113 . V_29 = V_160 |
V_161 ;
break;
default:
if ( V_113 . V_39 >=
V_153 + V_5 -> V_74 )
return - V_118 ;
V_69 = V_113 . V_39 - V_153 ;
V_113 . V_135 = F_87 ( V_113 . V_39 ) ;
V_113 . V_131 = V_5 -> V_75 [ V_69 ] . V_131 ;
V_113 . V_29 = V_5 -> V_75 [ V_69 ] . V_29 ;
V_44 = F_80 ( V_5 , & V_126 ,
V_5 -> V_75 [ V_69 ] . type ,
V_5 -> V_75 [ V_69 ] . V_136 ) ;
if ( V_44 )
return V_44 ;
}
if ( V_126 . V_131 ) {
V_113 . V_29 |= V_170 ;
if ( V_113 . V_150 < sizeof( V_113 ) + V_126 . V_131 ) {
V_113 . V_150 = sizeof( V_113 ) + V_126 . V_131 ;
V_113 . V_171 = 0 ;
} else {
F_90 ( & V_126 , sizeof( V_113 ) ) ;
if ( F_86 ( ( void V_148 * ) V_143 +
sizeof( V_113 ) , V_126 . V_157 ,
V_126 . V_131 ) ) {
F_16 ( V_126 . V_157 ) ;
return - V_149 ;
}
V_113 . V_171 = sizeof( V_113 ) ;
}
F_16 ( V_126 . V_157 ) ;
}
return F_86 ( ( void V_148 * ) V_143 , & V_113 , V_144 ) ?
- V_149 : 0 ;
} else if ( V_45 == V_172 ) {
struct V_173 V_113 ;
V_144 = F_84 ( struct V_173 , V_116 ) ;
if ( F_85 ( & V_113 , ( void V_148 * ) V_143 , V_144 ) )
return - V_149 ;
if ( V_113 . V_150 < V_144 || V_113 . V_39 >= V_154 )
return - V_118 ;
switch ( V_113 . V_39 ) {
case V_88 ... V_97 :
case V_99 :
break;
case V_98 :
if ( F_62 ( V_5 -> V_8 ) )
break;
default:
return - V_118 ;
}
V_113 . V_29 = V_174 ;
V_113 . V_116 = F_60 ( V_5 , V_113 . V_39 ) ;
if ( V_113 . V_39 == V_88 )
V_113 . V_29 |= ( V_175 |
V_176 ) ;
else
V_113 . V_29 |= V_177 ;
return F_86 ( ( void V_148 * ) V_143 , & V_113 , V_144 ) ?
- V_149 : 0 ;
} else if ( V_45 == V_178 ) {
struct V_179 V_180 ;
T_4 V_131 ;
T_2 * V_100 = NULL ;
int V_105 , V_44 = 0 ;
V_144 = F_84 ( struct V_179 , V_116 ) ;
if ( F_85 ( & V_180 , ( void V_148 * ) V_143 , V_144 ) )
return - V_149 ;
if ( V_180 . V_150 < V_144 || V_180 . V_39 >= V_154 ||
V_180 . V_116 >= ( V_181 - V_180 . V_33 ) ||
V_180 . V_29 & ~ ( V_182 |
V_183 ) )
return - V_118 ;
V_105 = F_60 ( V_5 , V_180 . V_39 ) ;
if ( V_180 . V_33 >= V_105 || V_180 . V_33 + V_180 . V_116 > V_105 )
return - V_118 ;
switch ( V_180 . V_29 & V_182 ) {
case V_70 :
V_131 = 0 ;
break;
case V_184 :
V_131 = sizeof( V_185 ) ;
break;
case V_186 :
V_131 = sizeof( V_187 ) ;
break;
default:
return - V_118 ;
}
if ( V_131 ) {
if ( V_180 . V_150 - V_144 < V_180 . V_116 * V_131 )
return - V_118 ;
V_100 = F_91 ( ( void V_148 * ) ( V_143 + V_144 ) ,
V_180 . V_116 * V_131 ) ;
if ( F_77 ( V_100 ) )
return F_78 ( V_100 ) ;
}
F_53 ( & V_5 -> V_188 ) ;
V_44 = F_40 ( V_5 , V_180 . V_29 , V_180 . V_39 ,
V_180 . V_33 , V_180 . V_116 , V_100 ) ;
F_55 ( & V_5 -> V_188 ) ;
F_16 ( V_100 ) ;
return V_44 ;
} else if ( V_45 == V_189 ) {
return V_5 -> V_48 ?
F_49 ( V_5 -> V_8 ) : - V_118 ;
} else if ( V_45 == V_190 ) {
struct V_191 V_180 ;
struct V_101 V_102 = { 0 } ;
struct V_192 * V_108 = NULL ;
bool V_120 = false ;
int V_44 = 0 ;
V_144 = F_84 ( struct V_191 , V_116 ) ;
if ( F_85 ( & V_180 , ( void V_148 * ) V_143 , V_144 ) )
return - V_149 ;
if ( V_180 . V_150 < V_144 )
return - V_118 ;
V_180 . V_29 = 0 ;
if ( ! F_92 ( V_5 -> V_8 -> V_120 ) )
V_120 = true ;
else if ( F_93 ( V_5 -> V_8 -> V_11 ) )
return - V_87 ;
V_44 = F_71 ( V_5 -> V_8 ,
F_63 ,
& V_102 . V_105 , V_120 ) ;
if ( V_44 )
return V_44 ;
F_94 ( ! V_102 . V_105 ) ;
if ( V_180 . V_150 < sizeof( V_180 ) + ( V_102 . V_105 * sizeof( * V_108 ) ) ) {
V_44 = - V_193 ;
V_180 . V_116 = V_102 . V_105 ;
goto V_194;
}
V_108 = F_95 ( V_102 . V_105 , sizeof( * V_108 ) , V_35 ) ;
if ( ! V_108 )
return - V_142 ;
V_102 . V_108 = V_108 ;
V_44 = F_71 ( V_5 -> V_8 ,
F_64 ,
& V_102 , V_120 ) ;
if ( ! V_44 )
V_180 . V_116 = V_102 . V_104 ;
V_194:
if ( F_86 ( ( void V_148 * ) V_143 , & V_180 , V_144 ) )
V_44 = - V_149 ;
if ( ! V_44 ) {
if ( F_86 ( ( void V_148 * ) ( V_143 + V_144 ) , V_108 ,
V_180 . V_116 * sizeof( * V_108 ) ) )
V_44 = - V_149 ;
}
F_16 ( V_108 ) ;
return V_44 ;
} else if ( V_45 == V_195 ) {
struct V_196 V_180 ;
V_187 * V_197 ;
struct V_198 * V_117 ;
struct V_112 V_113 ;
bool V_120 = false ;
int V_69 , V_116 = 0 , V_44 = 0 ;
V_144 = F_84 ( struct V_196 , V_116 ) ;
if ( F_85 ( & V_180 , ( void V_148 * ) V_143 , V_144 ) )
return - V_149 ;
if ( V_180 . V_150 < V_144 || V_180 . V_29 )
return - V_118 ;
if ( ! F_92 ( V_5 -> V_8 -> V_120 ) )
V_120 = true ;
else if ( F_93 ( V_5 -> V_8 -> V_11 ) )
return - V_87 ;
V_44 = F_71 ( V_5 -> V_8 ,
F_63 ,
& V_116 , V_120 ) ;
if ( V_44 )
return V_44 ;
if ( ! V_180 . V_116 || V_180 . V_116 > V_116 )
return - V_118 ;
V_197 = F_95 ( V_180 . V_116 , sizeof( * V_197 ) , V_35 ) ;
V_117 = F_95 ( V_180 . V_116 , sizeof( * V_117 ) , V_35 ) ;
if ( ! V_197 || ! V_117 ) {
F_16 ( V_197 ) ;
F_16 ( V_117 ) ;
return - V_142 ;
}
if ( F_85 ( V_197 , ( void V_148 * ) ( V_143 + V_144 ) ,
V_180 . V_116 * sizeof( * V_197 ) ) ) {
F_16 ( V_197 ) ;
F_16 ( V_117 ) ;
return - V_149 ;
}
for ( V_69 = 0 ; V_69 < V_180 . V_116 ; V_69 ++ ) {
struct V_199 * V_114 ;
struct V_200 V_201 = F_96 ( V_197 [ V_69 ] ) ;
if ( ! V_201 . V_202 ) {
V_44 = - V_203 ;
break;
}
V_114 = F_97 ( V_201 . V_202 ) ;
F_98 ( V_201 ) ;
if ( F_77 ( V_114 ) ) {
V_44 = F_78 ( V_114 ) ;
break;
}
V_117 [ V_69 ] . V_114 = V_114 ;
V_117 [ V_69 ] . V_115 = F_99 ( V_114 ) ;
}
F_16 ( V_197 ) ;
if ( V_44 )
goto V_204;
V_113 . V_116 = V_180 . V_116 ;
V_113 . V_117 = V_117 ;
V_44 = F_71 ( V_5 -> V_8 ,
F_68 ,
& V_113 , V_120 ) ;
if ( ! V_44 )
V_44 = V_120 ? F_100 ( V_5 -> V_8 -> V_120 ) :
F_101 ( V_5 -> V_8 -> V_11 ) ;
V_204:
for ( V_69 -- ; V_69 >= 0 ; V_69 -- )
F_102 ( V_117 [ V_69 ] . V_114 ) ;
F_16 ( V_117 ) ;
return V_44 ;
}
return - V_205 ;
}
static T_6 F_103 ( void * V_83 , char V_148 * V_157 ,
T_4 V_116 , T_7 * V_206 , bool V_207 )
{
unsigned int V_39 = F_104 ( * V_206 ) ;
struct V_4 * V_5 = V_83 ;
if ( V_39 >= V_153 + V_5 -> V_74 )
return - V_118 ;
switch ( V_39 ) {
case V_158 :
return F_105 ( V_5 , V_157 , V_116 , V_206 , V_207 ) ;
case V_165 :
if ( V_207 )
return - V_118 ;
return F_106 ( V_5 , V_157 , V_116 , V_206 , false ) ;
case V_162 ... V_163 :
return F_106 ( V_5 , V_157 , V_116 , V_206 , V_207 ) ;
case V_169 :
return F_107 ( V_5 , V_157 , V_116 , V_206 , V_207 ) ;
default:
V_39 -= V_153 ;
return V_5 -> V_75 [ V_39 ] . V_76 -> V_208 ( V_5 , V_157 ,
V_116 , V_206 , V_207 ) ;
}
return - V_118 ;
}
static T_6 F_108 ( void * V_83 , char V_148 * V_157 ,
T_4 V_116 , T_7 * V_206 )
{
if ( ! V_116 )
return 0 ;
return F_103 ( V_83 , V_157 , V_116 , V_206 , false ) ;
}
static T_6 F_109 ( void * V_83 , const char V_148 * V_157 ,
T_4 V_116 , T_7 * V_206 )
{
if ( ! V_116 )
return 0 ;
return F_103 ( V_83 , ( char V_148 * ) V_157 , V_116 , V_206 , true ) ;
}
static int F_110 ( void * V_83 , struct V_209 * V_210 )
{
struct V_4 * V_5 = V_83 ;
struct V_6 * V_8 = V_5 -> V_8 ;
unsigned int V_39 ;
T_8 V_211 , V_212 , V_213 , V_214 ;
int V_44 ;
V_39 = V_210 -> V_215 >> ( V_216 - V_217 ) ;
if ( V_210 -> V_218 < V_210 -> V_219 )
return - V_118 ;
if ( ( V_210 -> V_220 & V_221 ) == 0 )
return - V_118 ;
if ( V_39 >= V_165 )
return - V_118 ;
if ( ! V_5 -> V_32 [ V_39 ] )
return - V_118 ;
V_211 = F_75 ( F_74 ( V_8 , V_39 ) ) ;
V_212 = V_210 -> V_218 - V_210 -> V_219 ;
V_213 = V_210 -> V_215 &
( ( 1U << ( V_216 - V_217 ) ) - 1 ) ;
V_214 = V_213 << V_217 ;
if ( V_214 + V_212 > V_211 )
return - V_118 ;
if ( V_39 == V_5 -> V_61 ) {
if ( ! ( V_214 >= V_5 -> V_63 + V_5 -> V_65 ||
V_214 + V_212 <= V_5 -> V_63 ) )
return - V_118 ;
}
if ( ! V_5 -> V_78 [ V_39 ] ) {
V_44 = F_111 ( V_8 ,
1 << V_39 , L_6 ) ;
if ( V_44 )
return V_44 ;
V_5 -> V_78 [ V_39 ] = F_112 ( V_8 , V_39 , 0 ) ;
}
V_210 -> V_222 = V_5 ;
V_210 -> V_223 = F_113 ( V_210 -> V_223 ) ;
V_210 -> V_215 = ( F_114 ( V_8 , V_39 ) >> V_217 ) + V_213 ;
return F_115 ( V_210 , V_210 -> V_219 , V_210 -> V_215 ,
V_212 , V_210 -> V_223 ) ;
}
static void F_116 ( void * V_83 , unsigned int V_116 )
{
struct V_4 * V_5 = V_83 ;
F_53 ( & V_5 -> V_188 ) ;
if ( V_5 -> V_224 ) {
if ( ! ( V_116 % 10 ) )
F_117 ( & V_5 -> V_8 -> V_51 ,
L_7 ,
V_116 ) ;
F_118 ( V_5 -> V_224 , 1 ) ;
} else if ( V_116 == 0 ) {
F_38 ( & V_5 -> V_8 -> V_51 ,
L_8 ) ;
}
F_55 ( & V_5 -> V_188 ) ;
}
static int F_119 ( struct V_6 * V_8 , const struct V_225 * V_115 )
{
struct V_4 * V_5 ;
struct V_103 * V_114 ;
int V_44 ;
if ( V_8 -> V_226 != V_227 )
return - V_118 ;
V_114 = F_120 ( & V_8 -> V_51 ) ;
if ( ! V_114 )
return - V_118 ;
V_5 = F_14 ( sizeof( * V_5 ) , V_35 ) ;
if ( ! V_5 ) {
F_121 ( V_114 , & V_8 -> V_51 ) ;
return - V_142 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_72 = V_154 ;
F_122 ( & V_5 -> V_188 ) ;
F_123 ( & V_5 -> V_228 ) ;
V_44 = F_124 ( & V_8 -> V_51 , & V_229 , V_5 ) ;
if ( V_44 ) {
F_121 ( V_114 , & V_8 -> V_51 ) ;
F_16 ( V_5 ) ;
return V_44 ;
}
if ( F_9 ( V_8 ) ) {
F_125 ( V_8 , V_5 , NULL , F_3 ) ;
F_126 ( V_8 ,
F_3 ( V_5 , false ) ) ;
}
if ( ! V_81 ) {
F_20 ( V_8 , V_47 ) ;
F_20 ( V_8 , V_82 ) ;
}
return V_44 ;
}
static void F_127 ( struct V_6 * V_8 )
{
struct V_4 * V_5 ;
V_5 = F_128 ( & V_8 -> V_51 ) ;
if ( ! V_5 )
return;
F_121 ( V_8 -> V_51 . V_103 , & V_8 -> V_51 ) ;
F_16 ( V_5 -> V_75 ) ;
F_16 ( V_5 ) ;
if ( F_9 ( V_8 ) ) {
F_125 ( V_8 , NULL , NULL , NULL ) ;
F_126 ( V_8 ,
V_12 | V_13 |
V_14 | V_15 ) ;
}
if ( ! V_81 )
F_20 ( V_8 , V_47 ) ;
}
static T_9 F_129 ( struct V_6 * V_8 ,
T_10 V_230 )
{
struct V_4 * V_5 ;
struct V_231 * V_43 ;
V_43 = F_130 ( & V_8 -> V_51 ) ;
if ( V_43 == NULL )
return V_232 ;
V_5 = F_131 ( V_43 ) ;
if ( V_5 == NULL ) {
F_132 ( V_43 ) ;
return V_232 ;
}
F_53 ( & V_5 -> V_188 ) ;
if ( V_5 -> V_233 )
F_118 ( V_5 -> V_233 , 1 ) ;
F_55 ( & V_5 -> V_188 ) ;
F_132 ( V_43 ) ;
return V_234 ;
}
static int F_133 ( struct V_6 * V_8 , void * V_100 )
{
struct V_235 * V_236 = V_100 ;
struct V_231 * V_43 ;
if ( V_236 -> V_237 == V_236 -> V_238 )
return - V_193 ;
V_43 = F_130 ( & V_8 -> V_51 ) ;
if ( ! V_43 )
return - V_118 ;
if ( F_134 ( V_8 ) != & V_239 ) {
F_132 ( V_43 ) ;
return - V_240 ;
}
V_236 -> V_108 [ V_236 -> V_237 ++ ] = V_43 ;
return 0 ;
}
static void F_51 ( struct V_4 * V_5 )
{
struct V_235 V_236 = { . V_237 = 0 } ;
int V_69 = 0 , V_44 = - V_118 ;
bool V_79 = false , V_120 = false ;
struct V_4 * V_7 ;
if ( ! F_92 ( V_5 -> V_8 -> V_120 ) )
V_120 = true ;
else if ( F_93 ( V_5 -> V_8 -> V_11 ) )
return;
if ( F_71 ( V_5 -> V_8 , F_63 ,
& V_69 , V_120 ) || ! V_69 )
return;
V_236 . V_238 = V_69 ;
V_236 . V_108 = F_95 ( V_69 , sizeof( struct V_231 * ) , V_35 ) ;
if ( ! V_236 . V_108 )
return;
if ( F_71 ( V_5 -> V_8 ,
F_133 , & V_236 , V_120 ) )
goto V_241;
for ( V_69 = 0 ; V_69 < V_236 . V_237 ; V_69 ++ ) {
V_7 = F_131 ( V_236 . V_108 [ V_69 ] ) ;
if ( V_7 -> V_79 )
V_79 = true ;
if ( V_7 -> V_85 )
goto V_241;
}
if ( V_79 )
V_44 = V_120 ? F_100 ( V_5 -> V_8 -> V_120 ) :
F_101 ( V_5 -> V_8 -> V_11 ) ;
V_241:
for ( V_69 = 0 ; V_69 < V_236 . V_237 ; V_69 ++ ) {
V_7 = F_131 ( V_236 . V_108 [ V_69 ] ) ;
if ( ! V_44 )
V_7 -> V_79 = false ;
if ( ! V_7 -> V_85 && ! V_81 )
F_20 ( V_7 -> V_8 , V_82 ) ;
F_132 ( V_236 . V_108 [ V_69 ] ) ;
}
F_16 ( V_236 . V_108 ) ;
}
static void T_11 F_135 ( void )
{
F_136 ( & V_239 ) ;
F_137 () ;
}
static void T_12 F_138 ( void )
{
char * V_242 , * V_115 ;
int V_243 ;
if ( V_244 [ 0 ] == '\0' )
return;
V_242 = V_244 ;
while ( ( V_115 = F_139 ( & V_242 , L_9 ) ) ) {
unsigned int V_41 , V_43 , V_245 = V_246 ,
V_247 = V_246 , V_18 = 0 , V_248 = 0 ;
int V_249 ;
if ( ! strlen ( V_115 ) )
continue;
V_249 = sscanf ( V_115 , L_10 ,
& V_41 , & V_43 , & V_245 , & V_247 ,
& V_18 , & V_248 ) ;
if ( V_249 < 2 ) {
F_140 ( L_11 , V_115 ) ;
continue;
}
V_243 = F_141 ( & V_239 , V_41 , V_43 ,
V_245 , V_247 , V_18 , V_248 , 0 ) ;
if ( V_243 )
F_140 ( L_12 ,
V_41 , V_43 , V_245 , V_247 ,
V_18 , V_248 , V_243 ) ;
else
F_48 ( L_13 ,
V_41 , V_43 , V_245 , V_247 ,
V_18 , V_248 ) ;
}
}
static int T_12 F_142 ( void )
{
int V_44 ;
V_44 = F_143 () ;
if ( V_44 )
return V_44 ;
V_44 = F_144 ( & V_239 ) ;
if ( V_44 )
goto V_250;
F_138 () ;
return 0 ;
V_250:
F_137 () ;
return V_44 ;
}
