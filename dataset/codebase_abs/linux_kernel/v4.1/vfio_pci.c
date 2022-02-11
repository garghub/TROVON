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
return 0 ;
}
static void F_27 ( struct V_4 * V_5 )
{
struct V_6 * V_8 = V_5 -> V_8 ;
int V_43 ;
F_12 ( V_8 ) ;
F_28 ( V_5 , V_44 |
V_45 ,
V_5 -> V_46 , 0 , 0 , NULL ) ;
V_5 -> V_47 = false ;
F_29 ( V_5 ) ;
for ( V_43 = V_48 ; V_43 <= V_49 ; V_43 ++ ) {
if ( ! V_5 -> V_50 [ V_43 ] )
continue;
F_30 ( V_8 , V_5 -> V_50 [ V_43 ] ) ;
F_31 ( V_8 , 1 << V_43 ) ;
V_5 -> V_50 [ V_43 ] = NULL ;
}
V_5 -> V_51 = true ;
if ( F_32 ( V_8 , & V_5 -> V_24 ) ) {
F_33 ( L_2 ,
V_25 , F_18 ( & V_8 -> V_26 ) ) ;
if ( ! V_5 -> V_23 )
goto V_52;
F_15 ( V_8 ) ;
}
F_25 ( V_8 , V_29 , V_30 ) ;
if ( V_5 -> V_23 && ! F_34 ( V_8 ) )
V_5 -> V_51 = false ;
F_35 ( V_8 ) ;
V_52:
F_21 ( V_8 ) ;
F_36 ( V_5 ) ;
if ( ! V_53 )
F_11 ( V_8 , V_54 ) ;
}
static void F_37 ( void * V_55 )
{
struct V_4 * V_5 = V_55 ;
F_38 ( & V_56 ) ;
if ( ! ( -- V_5 -> V_57 ) ) {
F_39 ( V_5 -> V_8 ) ;
F_27 ( V_5 ) ;
}
F_40 ( & V_56 ) ;
F_41 ( V_58 ) ;
}
static int F_42 ( void * V_55 )
{
struct V_4 * V_5 = V_55 ;
int V_19 = 0 ;
if ( ! F_43 ( V_58 ) )
return - V_59 ;
F_38 ( & V_56 ) ;
if ( ! V_5 -> V_57 ) {
V_19 = F_10 ( V_5 ) ;
if ( V_19 )
goto error;
F_44 ( V_5 -> V_8 ) ;
}
V_5 -> V_57 ++ ;
error:
F_40 ( & V_56 ) ;
if ( V_19 )
F_41 ( V_58 ) ;
return V_19 ;
}
static int F_45 ( struct V_4 * V_5 , int V_46 )
{
if ( V_46 == V_60 ) {
T_2 V_61 ;
F_46 ( V_5 -> V_8 , V_62 , & V_61 ) ;
if ( F_47 ( V_63 ) && V_61 )
return 1 ;
} else if ( V_46 == V_64 ) {
T_2 V_65 ;
T_1 V_32 ;
V_65 = V_5 -> V_8 -> V_66 ;
if ( V_65 ) {
F_24 ( V_5 -> V_8 ,
V_65 + V_67 , & V_32 ) ;
return 1 << ( ( V_32 & V_68 ) >> 1 ) ;
}
} else if ( V_46 == V_69 ) {
T_2 V_65 ;
T_1 V_32 ;
V_65 = V_5 -> V_8 -> V_31 ;
if ( V_65 ) {
F_24 ( V_5 -> V_8 ,
V_65 + V_34 , & V_32 ) ;
return ( V_32 & V_41 ) + 1 ;
}
} else if ( V_46 == V_70 ) {
if ( F_48 ( V_5 -> V_8 ) )
return 1 ;
} else if ( V_46 == V_71 ) {
return 1 ;
}
return 0 ;
}
static int F_49 ( struct V_6 * V_8 , void * V_72 )
{
( * ( int * ) V_72 ) ++ ;
return 0 ;
}
static int F_50 ( struct V_6 * V_8 , void * V_72 )
{
struct V_73 * V_74 = V_72 ;
struct V_75 * V_75 ;
if ( V_74 -> V_76 == V_74 -> V_77 )
return - V_78 ;
V_75 = F_51 ( & V_8 -> V_26 ) ;
if ( ! V_75 )
return - V_79 ;
V_74 -> V_80 [ V_74 -> V_76 ] . V_81 = F_52 ( V_75 ) ;
V_74 -> V_80 [ V_74 -> V_76 ] . V_82 = F_7 ( V_8 -> V_11 ) ;
V_74 -> V_80 [ V_74 -> V_76 ] . V_11 = V_8 -> V_11 -> V_17 ;
V_74 -> V_80 [ V_74 -> V_76 ] . V_83 = V_8 -> V_83 ;
V_74 -> V_76 ++ ;
F_53 ( V_75 ) ;
return 0 ;
}
static int F_54 ( struct V_6 * V_8 , void * V_72 )
{
struct V_84 * V_85 = V_72 ;
struct V_75 * V_86 ;
int V_87 , V_88 ;
V_86 = F_51 ( & V_8 -> V_26 ) ;
if ( ! V_86 )
return - V_79 ;
V_87 = F_52 ( V_86 ) ;
for ( V_88 = 0 ; V_88 < V_85 -> V_89 ; V_88 ++ )
if ( V_85 -> V_90 [ V_88 ] . V_87 == V_87 )
break;
F_53 ( V_86 ) ;
return ( V_88 == V_85 -> V_89 ) ? - V_91 : 0 ;
}
static bool F_55 ( struct V_6 * V_8 , struct V_92 * V_93 )
{
for (; V_8 ; V_8 = V_8 -> V_11 -> V_94 )
if ( V_8 -> V_11 == V_93 -> V_11 )
return ( V_8 -> V_93 == V_93 ) ;
return false ;
}
static int F_56 ( struct V_6 * V_8 , void * V_72 )
{
struct V_95 * V_96 = V_72 ;
if ( ! V_96 -> V_93 || F_55 ( V_8 , V_96 -> V_8 -> V_93 ) )
V_96 -> V_19 = V_96 -> V_97 ( V_8 , V_96 -> V_72 ) ;
return V_96 -> V_19 ;
}
static int F_57 ( struct V_6 * V_8 ,
int (* V_97)( struct V_6 * ,
void * V_72 ) , void * V_72 ,
bool V_93 )
{
struct V_95 V_96 = {
. V_97 = V_97 , . V_72 = V_72 , . V_8 = V_8 , . V_93 = V_93 , . V_19 = 0 ,
} ;
F_58 ( V_8 -> V_11 , F_56 , & V_96 ) ;
return V_96 . V_19 ;
}
static long F_59 ( void * V_55 ,
unsigned int V_20 , unsigned long V_98 )
{
struct V_4 * V_5 = V_55 ;
unsigned long V_99 ;
if ( V_20 == V_100 ) {
struct V_101 V_85 ;
V_99 = F_60 ( struct V_101 , V_102 ) ;
if ( F_61 ( & V_85 , ( void V_103 * ) V_98 , V_99 ) )
return - V_104 ;
if ( V_85 . V_105 < V_99 )
return - V_91 ;
V_85 . V_32 = V_106 ;
if ( V_5 -> V_23 )
V_85 . V_32 |= V_107 ;
V_85 . V_108 = V_109 ;
V_85 . V_102 = V_110 ;
return F_62 ( ( void V_103 * ) V_98 , & V_85 , V_99 ) ;
} else if ( V_20 == V_111 ) {
struct V_6 * V_8 = V_5 -> V_8 ;
struct V_112 V_85 ;
V_99 = F_60 ( struct V_112 , V_113 ) ;
if ( F_61 ( & V_85 , ( void V_103 * ) V_98 , V_99 ) )
return - V_104 ;
if ( V_85 . V_105 < V_99 )
return - V_91 ;
switch ( V_85 . V_114 ) {
case V_115 :
V_85 . V_113 = F_63 ( V_85 . V_114 ) ;
V_85 . V_116 = V_8 -> V_117 ;
V_85 . V_32 = V_118 |
V_119 ;
break;
case V_120 ... V_121 :
V_85 . V_113 = F_63 ( V_85 . V_114 ) ;
V_85 . V_116 = F_64 ( V_8 , V_85 . V_114 ) ;
if ( ! V_85 . V_116 ) {
V_85 . V_32 = 0 ;
break;
}
V_85 . V_32 = V_118 |
V_119 ;
if ( F_47 ( V_122 ) &&
F_65 ( V_8 , V_85 . V_114 ) &
V_123 && V_85 . V_116 >= V_124 )
V_85 . V_32 |= V_125 ;
break;
case V_126 :
{
void T_4 * V_127 ;
T_5 V_116 ;
V_85 . V_113 = F_63 ( V_85 . V_114 ) ;
V_85 . V_32 = 0 ;
V_85 . V_116 = F_64 ( V_8 , V_85 . V_114 ) ;
if ( ! V_85 . V_116 )
break;
V_127 = F_66 ( V_8 , & V_116 ) ;
if ( ! V_127 || ! V_116 ) {
V_85 . V_116 = 0 ;
break;
}
F_67 ( V_8 , V_127 ) ;
V_85 . V_32 = V_118 ;
break;
}
case V_128 :
if ( ! V_5 -> V_42 )
return - V_91 ;
V_85 . V_113 = F_63 ( V_85 . V_114 ) ;
V_85 . V_116 = 0xc0000 ;
V_85 . V_32 = V_118 |
V_119 ;
break;
default:
return - V_91 ;
}
return F_62 ( ( void V_103 * ) V_98 , & V_85 , V_99 ) ;
} else if ( V_20 == V_129 ) {
struct V_130 V_85 ;
V_99 = F_60 ( struct V_130 , V_89 ) ;
if ( F_61 ( & V_85 , ( void V_103 * ) V_98 , V_99 ) )
return - V_104 ;
if ( V_85 . V_105 < V_99 || V_85 . V_114 >= V_110 )
return - V_91 ;
switch ( V_85 . V_114 ) {
case V_60 ... V_69 :
case V_71 :
break;
case V_70 :
if ( F_48 ( V_5 -> V_8 ) )
break;
default:
return - V_91 ;
}
V_85 . V_32 = V_131 ;
V_85 . V_89 = F_45 ( V_5 , V_85 . V_114 ) ;
if ( V_85 . V_114 == V_60 )
V_85 . V_32 |= ( V_132 |
V_133 ) ;
else
V_85 . V_32 |= V_134 ;
return F_62 ( ( void V_103 * ) V_98 , & V_85 , V_99 ) ;
} else if ( V_20 == V_135 ) {
struct V_136 V_137 ;
T_2 * V_72 = NULL ;
int V_19 = 0 ;
V_99 = F_60 ( struct V_136 , V_89 ) ;
if ( F_61 ( & V_137 , ( void V_103 * ) V_98 , V_99 ) )
return - V_104 ;
if ( V_137 . V_105 < V_99 || V_137 . V_114 >= V_110 ||
V_137 . V_32 & ~ ( V_138 |
V_139 ) )
return - V_91 ;
if ( ! ( V_137 . V_32 & V_44 ) ) {
T_5 V_116 ;
int V_77 = F_45 ( V_5 , V_137 . V_114 ) ;
if ( V_137 . V_32 & V_140 )
V_116 = sizeof( V_141 ) ;
else if ( V_137 . V_32 & V_142 )
V_116 = sizeof( V_143 ) ;
else
return - V_91 ;
if ( V_137 . V_105 - V_99 < V_137 . V_89 * V_116 ||
V_137 . V_144 >= V_77 || V_137 . V_144 + V_137 . V_89 > V_77 )
return - V_91 ;
V_72 = F_68 ( ( void V_103 * ) ( V_98 + V_99 ) ,
V_137 . V_89 * V_116 ) ;
if ( F_69 ( V_72 ) )
return F_70 ( V_72 ) ;
}
F_38 ( & V_5 -> V_145 ) ;
V_19 = F_28 ( V_5 , V_137 . V_32 , V_137 . V_114 ,
V_137 . V_144 , V_137 . V_89 , V_72 ) ;
F_40 ( & V_5 -> V_145 ) ;
F_20 ( V_72 ) ;
return V_19 ;
} else if ( V_20 == V_146 ) {
return V_5 -> V_23 ?
F_34 ( V_5 -> V_8 ) : - V_91 ;
} else if ( V_20 == V_147 ) {
struct V_148 V_137 ;
struct V_73 V_74 = { 0 } ;
struct V_149 * V_80 = NULL ;
bool V_93 = false ;
int V_19 = 0 ;
V_99 = F_60 ( struct V_148 , V_89 ) ;
if ( F_61 ( & V_137 , ( void V_103 * ) V_98 , V_99 ) )
return - V_104 ;
if ( V_137 . V_105 < V_99 )
return - V_91 ;
V_137 . V_32 = 0 ;
if ( ! F_71 ( V_5 -> V_8 -> V_93 ) )
V_93 = true ;
else if ( F_72 ( V_5 -> V_8 -> V_11 ) )
return - V_59 ;
V_19 = F_57 ( V_5 -> V_8 ,
F_49 ,
& V_74 . V_77 , V_93 ) ;
if ( V_19 )
return V_19 ;
F_73 ( ! V_74 . V_77 ) ;
if ( V_137 . V_105 < sizeof( V_137 ) + ( V_74 . V_77 * sizeof( * V_80 ) ) ) {
V_19 = - V_150 ;
V_137 . V_89 = V_74 . V_77 ;
goto V_151;
}
V_80 = F_74 ( V_74 . V_77 , sizeof( * V_80 ) , V_152 ) ;
if ( ! V_80 )
return - V_153 ;
V_74 . V_80 = V_80 ;
V_19 = F_57 ( V_5 -> V_8 ,
F_50 ,
& V_74 , V_93 ) ;
if ( ! V_19 )
V_137 . V_89 = V_74 . V_76 ;
V_151:
if ( F_62 ( ( void V_103 * ) V_98 , & V_137 , V_99 ) )
V_19 = - V_104 ;
if ( ! V_19 ) {
if ( F_62 ( ( void V_103 * ) ( V_98 + V_99 ) , V_80 ,
V_137 . V_89 * sizeof( * V_80 ) ) )
V_19 = - V_104 ;
}
F_20 ( V_80 ) ;
return V_19 ;
} else if ( V_20 == V_154 ) {
struct V_155 V_137 ;
V_143 * V_156 ;
struct V_157 * V_90 ;
struct V_84 V_85 ;
bool V_93 = false ;
int V_88 , V_89 = 0 , V_19 = 0 ;
V_99 = F_60 ( struct V_155 , V_89 ) ;
if ( F_61 ( & V_137 , ( void V_103 * ) V_98 , V_99 ) )
return - V_104 ;
if ( V_137 . V_105 < V_99 || V_137 . V_32 )
return - V_91 ;
if ( ! F_71 ( V_5 -> V_8 -> V_93 ) )
V_93 = true ;
else if ( F_72 ( V_5 -> V_8 -> V_11 ) )
return - V_59 ;
V_19 = F_57 ( V_5 -> V_8 ,
F_49 ,
& V_89 , V_93 ) ;
if ( V_19 )
return V_19 ;
if ( ! V_137 . V_89 || V_137 . V_89 > V_89 )
return - V_91 ;
V_156 = F_74 ( V_137 . V_89 , sizeof( * V_156 ) , V_152 ) ;
V_90 = F_74 ( V_137 . V_89 , sizeof( * V_90 ) , V_152 ) ;
if ( ! V_156 || ! V_90 ) {
F_20 ( V_156 ) ;
F_20 ( V_90 ) ;
return - V_153 ;
}
if ( F_61 ( V_156 , ( void V_103 * ) ( V_98 + V_99 ) ,
V_137 . V_89 * sizeof( * V_156 ) ) ) {
F_20 ( V_156 ) ;
F_20 ( V_90 ) ;
return - V_104 ;
}
for ( V_88 = 0 ; V_88 < V_137 . V_89 ; V_88 ++ ) {
struct V_158 * V_86 ;
struct V_159 V_160 = F_75 ( V_156 [ V_88 ] ) ;
if ( ! V_160 . V_161 ) {
V_19 = - V_162 ;
break;
}
V_86 = F_76 ( V_160 . V_161 ) ;
F_77 ( V_160 ) ;
if ( F_69 ( V_86 ) ) {
V_19 = F_70 ( V_86 ) ;
break;
}
V_90 [ V_88 ] . V_86 = V_86 ;
V_90 [ V_88 ] . V_87 = F_78 ( V_86 ) ;
}
F_20 ( V_156 ) ;
if ( V_19 )
goto V_163;
V_85 . V_89 = V_137 . V_89 ;
V_85 . V_90 = V_90 ;
V_19 = F_57 ( V_5 -> V_8 ,
F_54 ,
& V_85 , V_93 ) ;
if ( ! V_19 )
V_19 = V_93 ? F_79 ( V_5 -> V_8 -> V_93 ) :
F_80 ( V_5 -> V_8 -> V_11 ) ;
V_163:
for ( V_88 -- ; V_88 >= 0 ; V_88 -- )
F_81 ( V_90 [ V_88 ] . V_86 ) ;
F_20 ( V_90 ) ;
return V_19 ;
}
return - V_164 ;
}
static T_6 F_82 ( void * V_55 , char V_103 * V_165 ,
T_5 V_89 , T_7 * V_166 , bool V_167 )
{
unsigned int V_114 = F_83 ( * V_166 ) ;
struct V_4 * V_5 = V_55 ;
if ( V_114 >= V_109 )
return - V_91 ;
switch ( V_114 ) {
case V_115 :
return F_84 ( V_5 , V_165 , V_89 , V_166 , V_167 ) ;
case V_126 :
if ( V_167 )
return - V_91 ;
return F_85 ( V_5 , V_165 , V_89 , V_166 , false ) ;
case V_120 ... V_121 :
return F_85 ( V_5 , V_165 , V_89 , V_166 , V_167 ) ;
case V_128 :
return F_86 ( V_5 , V_165 , V_89 , V_166 , V_167 ) ;
}
return - V_91 ;
}
static T_6 F_87 ( void * V_55 , char V_103 * V_165 ,
T_5 V_89 , T_7 * V_166 )
{
if ( ! V_89 )
return 0 ;
return F_82 ( V_55 , V_165 , V_89 , V_166 , false ) ;
}
static T_6 F_88 ( void * V_55 , const char V_103 * V_165 ,
T_5 V_89 , T_7 * V_166 )
{
if ( ! V_89 )
return 0 ;
return F_82 ( V_55 , ( char V_103 * ) V_165 , V_89 , V_166 , true ) ;
}
static int F_89 ( void * V_55 , struct V_168 * V_169 )
{
struct V_4 * V_5 = V_55 ;
struct V_6 * V_8 = V_5 -> V_8 ;
unsigned int V_114 ;
T_8 V_170 , V_171 , V_172 , V_173 ;
int V_19 ;
V_114 = V_169 -> V_174 >> ( V_175 - V_176 ) ;
if ( V_169 -> V_177 < V_169 -> V_178 )
return - V_91 ;
if ( ( V_169 -> V_179 & V_180 ) == 0 )
return - V_91 ;
if ( V_114 >= V_126 )
return - V_91 ;
if ( ! ( F_65 ( V_8 , V_114 ) & V_123 ) )
return - V_91 ;
V_170 = F_64 ( V_8 , V_114 ) ;
V_171 = V_169 -> V_177 - V_169 -> V_178 ;
V_172 = V_169 -> V_174 &
( ( 1U << ( V_175 - V_176 ) ) - 1 ) ;
V_173 = V_172 << V_176 ;
if ( V_170 < V_124 || V_173 + V_171 > V_170 )
return - V_91 ;
if ( V_114 == V_5 -> V_36 ) {
if ( ! ( V_173 >= V_5 -> V_38 + V_5 -> V_40 ||
V_173 + V_171 <= V_5 -> V_38 ) )
return - V_91 ;
}
if ( ! V_5 -> V_50 [ V_114 ] ) {
V_19 = F_90 ( V_8 ,
1 << V_114 , L_3 ) ;
if ( V_19 )
return V_19 ;
V_5 -> V_50 [ V_114 ] = F_91 ( V_8 , V_114 , 0 ) ;
}
V_169 -> V_181 = V_5 ;
V_169 -> V_182 = F_92 ( V_169 -> V_182 ) ;
V_169 -> V_174 = ( F_93 ( V_8 , V_114 ) >> V_176 ) + V_172 ;
return F_94 ( V_169 , V_169 -> V_178 , V_169 -> V_174 ,
V_171 , V_169 -> V_182 ) ;
}
static void F_95 ( void * V_55 , unsigned int V_89 )
{
struct V_4 * V_5 = V_55 ;
F_38 ( & V_5 -> V_145 ) ;
if ( V_5 -> V_183 ) {
if ( ! ( V_89 % 10 ) )
F_96 ( & V_5 -> V_8 -> V_26 ,
L_4 ,
V_89 ) ;
F_97 ( V_5 -> V_183 , 1 ) ;
} else if ( V_89 == 0 ) {
F_98 ( & V_5 -> V_8 -> V_26 ,
L_5 ) ;
}
F_40 ( & V_5 -> V_145 ) ;
}
static int F_99 ( struct V_6 * V_8 , const struct V_184 * V_87 )
{
struct V_4 * V_5 ;
struct V_75 * V_86 ;
int V_19 ;
if ( V_8 -> V_185 != V_186 )
return - V_91 ;
V_86 = F_51 ( & V_8 -> V_26 ) ;
if ( ! V_86 )
return - V_91 ;
V_5 = F_100 ( sizeof( * V_5 ) , V_152 ) ;
if ( ! V_5 ) {
F_53 ( V_86 ) ;
return - V_153 ;
}
V_5 -> V_8 = V_8 ;
V_5 -> V_46 = V_110 ;
F_101 ( & V_5 -> V_145 ) ;
F_102 ( & V_5 -> V_187 ) ;
V_19 = F_103 ( & V_8 -> V_26 , & V_188 , V_5 ) ;
if ( V_19 ) {
F_53 ( V_86 ) ;
F_20 ( V_5 ) ;
return V_19 ;
}
if ( F_9 ( V_8 ) ) {
F_104 ( V_8 , V_5 , NULL , F_3 ) ;
F_105 ( V_8 ,
F_3 ( V_5 , false ) ) ;
}
if ( ! V_53 ) {
F_11 ( V_8 , V_22 ) ;
F_11 ( V_8 , V_54 ) ;
}
return V_19 ;
}
static void F_106 ( struct V_6 * V_8 )
{
struct V_4 * V_5 ;
V_5 = F_107 ( & V_8 -> V_26 ) ;
if ( ! V_5 )
return;
F_53 ( V_8 -> V_26 . V_75 ) ;
F_20 ( V_5 ) ;
if ( F_9 ( V_8 ) ) {
F_104 ( V_8 , NULL , NULL , NULL ) ;
F_105 ( V_8 ,
V_12 | V_13 |
V_14 | V_15 ) ;
}
if ( ! V_53 )
F_11 ( V_8 , V_22 ) ;
}
static T_9 F_108 ( struct V_6 * V_8 ,
T_10 V_189 )
{
struct V_4 * V_5 ;
struct V_190 * V_191 ;
V_191 = F_109 ( & V_8 -> V_26 ) ;
if ( V_191 == NULL )
return V_192 ;
V_5 = F_110 ( V_191 ) ;
if ( V_5 == NULL ) {
F_111 ( V_191 ) ;
return V_192 ;
}
F_38 ( & V_5 -> V_145 ) ;
if ( V_5 -> V_193 )
F_97 ( V_5 -> V_193 , 1 ) ;
F_40 ( & V_5 -> V_145 ) ;
F_111 ( V_191 ) ;
return V_194 ;
}
static int F_112 ( struct V_6 * V_8 , void * V_72 )
{
struct V_195 * V_196 = V_72 ;
struct V_197 * V_198 = F_113 ( V_8 -> V_199 ) ;
if ( V_198 != & V_200 )
return - V_201 ;
if ( V_196 -> V_202 == V_196 -> V_203 )
return - V_150 ;
V_196 -> V_80 [ V_196 -> V_202 ] = F_109 ( & V_8 -> V_26 ) ;
if ( ! V_196 -> V_80 [ V_196 -> V_202 ] )
return - V_91 ;
V_196 -> V_202 ++ ;
return 0 ;
}
static void F_36 ( struct V_4 * V_5 )
{
struct V_195 V_196 = { . V_202 = 0 } ;
int V_88 = 0 , V_19 = - V_91 ;
bool V_51 = false , V_93 = false ;
struct V_4 * V_7 ;
if ( ! F_71 ( V_5 -> V_8 -> V_93 ) )
V_93 = true ;
else if ( F_72 ( V_5 -> V_8 -> V_11 ) )
return;
if ( F_57 ( V_5 -> V_8 , F_49 ,
& V_88 , V_93 ) || ! V_88 )
return;
V_196 . V_203 = V_88 ;
V_196 . V_80 = F_74 ( V_88 , sizeof( struct V_190 * ) , V_152 ) ;
if ( ! V_196 . V_80 )
return;
if ( F_57 ( V_5 -> V_8 ,
F_112 , & V_196 , V_93 ) )
goto V_204;
for ( V_88 = 0 ; V_88 < V_196 . V_202 ; V_88 ++ ) {
V_7 = F_110 ( V_196 . V_80 [ V_88 ] ) ;
if ( V_7 -> V_51 )
V_51 = true ;
if ( V_7 -> V_57 )
goto V_204;
}
if ( V_51 )
V_19 = V_93 ? F_79 ( V_5 -> V_8 -> V_93 ) :
F_80 ( V_5 -> V_8 -> V_11 ) ;
V_204:
for ( V_88 = 0 ; V_88 < V_196 . V_202 ; V_88 ++ ) {
V_7 = F_110 ( V_196 . V_80 [ V_88 ] ) ;
if ( ! V_19 )
V_7 -> V_51 = false ;
if ( ! V_7 -> V_57 && ! V_53 )
F_11 ( V_7 -> V_8 , V_54 ) ;
F_111 ( V_196 . V_80 [ V_88 ] ) ;
}
F_20 ( V_196 . V_80 ) ;
}
static void T_11 F_114 ( void )
{
F_115 ( & V_200 ) ;
F_116 () ;
}
static void T_12 F_117 ( void )
{
char * V_205 , * V_87 ;
int V_206 ;
if ( V_207 [ 0 ] == '\0' )
return;
V_205 = V_207 ;
while ( ( V_87 = F_118 ( & V_205 , L_6 ) ) ) {
unsigned int V_208 , V_191 , V_209 = V_210 ,
V_211 = V_210 , V_18 = 0 , V_212 = 0 ;
int V_213 ;
if ( ! strlen ( V_87 ) )
continue;
V_213 = sscanf ( V_87 , L_7 ,
& V_208 , & V_191 , & V_209 , & V_211 ,
& V_18 , & V_212 ) ;
if ( V_213 < 2 ) {
F_119 ( L_8 , V_87 ) ;
continue;
}
V_206 = F_120 ( & V_200 , V_208 , V_191 ,
V_209 , V_211 , V_18 , V_212 , 0 ) ;
if ( V_206 )
F_119 ( L_9 ,
V_208 , V_191 , V_209 , V_211 ,
V_18 , V_212 , V_206 ) ;
else
F_33 ( L_10 ,
V_208 , V_191 , V_209 , V_211 ,
V_18 , V_212 ) ;
}
}
static int T_12 F_121 ( void )
{
int V_19 ;
V_19 = F_122 () ;
if ( V_19 )
return V_19 ;
V_19 = F_123 ( & V_200 ) ;
if ( V_19 )
goto V_214;
F_117 () ;
return 0 ;
V_214:
F_116 () ;
return V_19 ;
}
