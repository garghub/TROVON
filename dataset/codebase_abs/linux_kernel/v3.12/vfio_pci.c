static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_1 V_6 ;
T_2 V_7 ;
V_5 = F_2 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_8 = ( F_3 ( V_4 ) == 0 ) ;
F_4 ( V_4 ) ;
V_2 -> V_9 = F_5 ( V_4 ) ;
if ( ! V_2 -> V_9 )
F_6 ( L_1 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
V_5 = F_8 ( V_2 ) ;
if ( V_5 ) {
F_9 ( V_4 , & V_2 -> V_9 ) ;
F_10 ( V_4 ) ;
return V_5 ;
}
if ( F_11 ( ! V_12 ) )
V_2 -> V_13 = F_12 ( V_4 ) ;
F_13 ( V_4 , V_14 , & V_6 ) ;
if ( V_2 -> V_13 && ( V_6 & V_15 ) ) {
V_6 &= ~ V_15 ;
F_14 ( V_4 , V_14 , V_6 ) ;
}
V_7 = V_4 -> V_16 ;
if ( V_7 ) {
T_1 V_17 ;
T_3 V_18 ;
F_13 ( V_4 , V_7 + V_19 , & V_17 ) ;
F_15 ( V_4 , V_7 + V_20 , & V_18 ) ;
V_2 -> V_21 = V_18 & V_22 ;
V_2 -> V_23 = V_18 & V_24 ;
V_2 -> V_25 = ( ( V_17 & V_26 ) + 1 ) * 16 ;
} else
V_2 -> V_21 = 0xFF ;
#ifdef F_16
if ( ( V_4 -> V_27 >> 8 ) == V_28 )
V_2 -> V_29 = true ;
#endif
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_30 ;
F_10 ( V_4 ) ;
F_18 ( V_2 , V_31 |
V_32 ,
V_2 -> V_33 , 0 , 0 , NULL ) ;
V_2 -> V_34 = false ;
F_19 ( V_2 ) ;
for ( V_30 = V_35 ; V_30 <= V_36 ; V_30 ++ ) {
if ( ! V_2 -> V_37 [ V_30 ] )
continue;
F_20 ( V_4 , V_2 -> V_37 [ V_30 ] ) ;
F_21 ( V_4 , 1 << V_30 ) ;
V_2 -> V_37 [ V_30 ] = NULL ;
}
if ( F_9 ( V_4 , & V_2 -> V_9 ) ) {
F_22 ( L_2 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
if ( ! V_2 -> V_8 )
return;
F_4 ( V_4 ) ;
}
F_14 ( V_4 , V_14 , V_15 ) ;
if ( V_2 -> V_8 ) {
bool V_38 = false ;
if ( F_23 ( V_4 ) ) {
if ( F_24 ( & V_4 -> V_11 ) ) {
F_25 ( V_4 ) ;
V_38 = true ;
F_26 ( & V_4 -> V_11 ) ;
}
F_27 ( V_4 ) ;
}
if ( ! V_38 )
F_28 ( L_3 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
}
F_29 ( V_4 ) ;
}
static void F_30 ( void * V_39 )
{
struct V_1 * V_2 = V_39 ;
if ( F_31 ( & V_2 -> V_40 ) )
F_17 ( V_2 ) ;
F_32 ( V_41 ) ;
}
static int F_33 ( void * V_39 )
{
struct V_1 * V_2 = V_39 ;
if ( ! F_34 ( V_41 ) )
return - V_42 ;
if ( F_35 ( & V_2 -> V_40 ) == 1 ) {
int V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_32 ( V_41 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , int V_33 )
{
if ( V_33 == V_43 ) {
T_2 V_44 ;
F_37 ( V_2 -> V_4 , V_45 , & V_44 ) ;
if ( V_44 )
return 1 ;
} else if ( V_33 == V_46 ) {
T_2 V_47 ;
T_1 V_17 ;
V_47 = V_2 -> V_4 -> V_48 ;
if ( V_47 ) {
F_13 ( V_2 -> V_4 ,
V_47 + V_49 , & V_17 ) ;
return 1 << ( V_17 & V_50 ) ;
}
} else if ( V_33 == V_51 ) {
T_2 V_47 ;
T_1 V_17 ;
V_47 = V_2 -> V_4 -> V_16 ;
if ( V_47 ) {
F_13 ( V_2 -> V_4 ,
V_47 + V_19 , & V_17 ) ;
return ( V_17 & V_26 ) + 1 ;
}
} else if ( V_33 == V_52 )
if ( F_38 ( V_2 -> V_4 ) )
return 1 ;
return 0 ;
}
static int F_39 ( struct V_3 * V_4 , void * V_53 )
{
( * ( int * ) V_53 ) ++ ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 , void * V_53 )
{
struct V_54 * V_55 = V_53 ;
struct V_56 * V_56 ;
if ( V_55 -> V_57 == V_55 -> V_58 )
return - V_59 ;
V_56 = F_41 ( & V_4 -> V_11 ) ;
if ( ! V_56 )
return - V_60 ;
V_55 -> V_61 [ V_55 -> V_57 ] . V_62 = F_42 ( V_56 ) ;
V_55 -> V_61 [ V_55 -> V_57 ] . V_63 = F_43 ( V_4 -> V_64 ) ;
V_55 -> V_61 [ V_55 -> V_57 ] . V_64 = V_4 -> V_64 -> V_65 ;
V_55 -> V_61 [ V_55 -> V_57 ] . V_66 = V_4 -> V_66 ;
V_55 -> V_57 ++ ;
F_44 ( V_56 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 , void * V_53 )
{
struct V_67 * V_68 = V_53 ;
struct V_56 * V_69 ;
int V_70 , V_71 ;
V_69 = F_41 ( & V_4 -> V_11 ) ;
if ( ! V_69 )
return - V_60 ;
V_70 = F_42 ( V_69 ) ;
for ( V_71 = 0 ; V_71 < V_68 -> V_72 ; V_71 ++ )
if ( V_68 -> V_73 [ V_71 ] . V_70 == V_70 )
break;
F_44 ( V_69 ) ;
return ( V_71 == V_68 -> V_72 ) ? - V_74 : 0 ;
}
static bool F_46 ( struct V_3 * V_4 , struct V_75 * V_76 )
{
for (; V_4 ; V_4 = V_4 -> V_64 -> V_77 )
if ( V_4 -> V_64 == V_76 -> V_64 )
return ( V_4 -> V_76 == V_76 ) ;
return false ;
}
static int F_47 ( struct V_3 * V_4 , void * V_53 )
{
struct V_78 * V_79 = V_53 ;
if ( ! V_79 -> V_76 || F_46 ( V_4 , V_79 -> V_4 -> V_76 ) )
V_79 -> V_5 = V_79 -> V_80 ( V_4 , V_79 -> V_53 ) ;
return V_79 -> V_5 ;
}
static int F_48 ( struct V_3 * V_4 ,
int (* V_80)( struct V_3 * ,
void * V_53 ) , void * V_53 ,
bool V_76 )
{
struct V_78 V_79 = {
. V_80 = V_80 , . V_53 = V_53 , . V_4 = V_4 , . V_76 = V_76 , . V_5 = 0 ,
} ;
F_49 ( V_4 -> V_64 , F_47 , & V_79 ) ;
return V_79 . V_5 ;
}
static long F_50 ( void * V_39 ,
unsigned int V_6 , unsigned long V_81 )
{
struct V_1 * V_2 = V_39 ;
unsigned long V_82 ;
if ( V_6 == V_83 ) {
struct V_84 V_68 ;
V_82 = F_51 ( struct V_84 , V_85 ) ;
if ( F_52 ( & V_68 , ( void V_86 * ) V_81 , V_82 ) )
return - V_87 ;
if ( V_68 . V_88 < V_82 )
return - V_74 ;
V_68 . V_17 = V_89 ;
if ( V_2 -> V_8 )
V_68 . V_17 |= V_90 ;
V_68 . V_91 = V_92 ;
V_68 . V_85 = V_93 ;
return F_53 ( ( void V_86 * ) V_81 , & V_68 , V_82 ) ;
} else if ( V_6 == V_94 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_95 V_68 ;
V_82 = F_51 ( struct V_95 , V_96 ) ;
if ( F_52 ( & V_68 , ( void V_86 * ) V_81 , V_82 ) )
return - V_87 ;
if ( V_68 . V_88 < V_82 )
return - V_74 ;
switch ( V_68 . V_97 ) {
case V_98 :
V_68 . V_96 = F_54 ( V_68 . V_97 ) ;
V_68 . V_99 = V_4 -> V_100 ;
V_68 . V_17 = V_101 |
V_102 ;
break;
case V_103 ... V_104 :
V_68 . V_96 = F_54 ( V_68 . V_97 ) ;
V_68 . V_99 = F_55 ( V_4 , V_68 . V_97 ) ;
if ( ! V_68 . V_99 ) {
V_68 . V_17 = 0 ;
break;
}
V_68 . V_17 = V_101 |
V_102 ;
if ( F_56 ( V_4 , V_68 . V_97 ) &
V_105 && V_68 . V_99 >= V_106 )
V_68 . V_17 |= V_107 ;
break;
case V_108 :
{
void T_4 * V_109 ;
T_5 V_99 ;
V_68 . V_96 = F_54 ( V_68 . V_97 ) ;
V_68 . V_17 = 0 ;
V_68 . V_99 = F_55 ( V_4 , V_68 . V_97 ) ;
if ( ! V_68 . V_99 )
break;
V_109 = F_57 ( V_4 , & V_99 ) ;
if ( ! V_109 || ! V_99 ) {
V_68 . V_99 = 0 ;
break;
}
F_58 ( V_4 , V_109 ) ;
V_68 . V_17 = V_101 ;
break;
}
case V_110 :
if ( ! V_2 -> V_29 )
return - V_74 ;
V_68 . V_96 = F_54 ( V_68 . V_97 ) ;
V_68 . V_99 = 0xc0000 ;
V_68 . V_17 = V_101 |
V_102 ;
break;
default:
return - V_74 ;
}
return F_53 ( ( void V_86 * ) V_81 , & V_68 , V_82 ) ;
} else if ( V_6 == V_111 ) {
struct V_112 V_68 ;
V_82 = F_51 ( struct V_112 , V_72 ) ;
if ( F_52 ( & V_68 , ( void V_86 * ) V_81 , V_82 ) )
return - V_87 ;
if ( V_68 . V_88 < V_82 || V_68 . V_97 >= V_93 )
return - V_74 ;
switch ( V_68 . V_97 ) {
case V_43 ... V_51 :
break;
case V_52 :
if ( F_38 ( V_2 -> V_4 ) )
break;
default:
return - V_74 ;
}
V_68 . V_17 = V_113 ;
V_68 . V_72 = F_36 ( V_2 , V_68 . V_97 ) ;
if ( V_68 . V_97 == V_43 )
V_68 . V_17 |= ( V_114 |
V_115 ) ;
else
V_68 . V_17 |= V_116 ;
return F_53 ( ( void V_86 * ) V_81 , & V_68 , V_82 ) ;
} else if ( V_6 == V_117 ) {
struct V_118 V_119 ;
T_2 * V_53 = NULL ;
int V_5 = 0 ;
V_82 = F_51 ( struct V_118 , V_72 ) ;
if ( F_52 ( & V_119 , ( void V_86 * ) V_81 , V_82 ) )
return - V_87 ;
if ( V_119 . V_88 < V_82 || V_119 . V_97 >= V_93 ||
V_119 . V_17 & ~ ( V_120 |
V_121 ) )
return - V_74 ;
if ( ! ( V_119 . V_17 & V_31 ) ) {
T_5 V_99 ;
int V_58 = F_36 ( V_2 , V_119 . V_97 ) ;
if ( V_119 . V_17 & V_122 )
V_99 = sizeof( V_123 ) ;
else if ( V_119 . V_17 & V_124 )
V_99 = sizeof( V_125 ) ;
else
return - V_74 ;
if ( V_119 . V_88 - V_82 < V_119 . V_72 * V_99 ||
V_119 . V_126 >= V_58 || V_119 . V_126 + V_119 . V_72 > V_58 )
return - V_74 ;
V_53 = F_59 ( ( void V_86 * ) ( V_81 + V_82 ) ,
V_119 . V_72 * V_99 ) ;
if ( F_60 ( V_53 ) )
return F_61 ( V_53 ) ;
}
F_62 ( & V_2 -> V_127 ) ;
V_5 = F_18 ( V_2 , V_119 . V_17 , V_119 . V_97 ,
V_119 . V_126 , V_119 . V_72 , V_53 ) ;
F_63 ( & V_2 -> V_127 ) ;
F_64 ( V_53 ) ;
return V_5 ;
} else if ( V_6 == V_128 ) {
return V_2 -> V_8 ?
F_3 ( V_2 -> V_4 ) : - V_74 ;
} else if ( V_6 == V_129 ) {
struct V_130 V_119 ;
struct V_54 V_55 = { 0 } ;
struct V_131 * V_61 = NULL ;
bool V_76 = false ;
int V_5 = 0 ;
V_82 = F_51 ( struct V_130 , V_72 ) ;
if ( F_52 ( & V_119 , ( void V_86 * ) V_81 , V_82 ) )
return - V_87 ;
if ( V_119 . V_88 < V_82 )
return - V_74 ;
V_119 . V_17 = 0 ;
if ( ! F_65 ( V_2 -> V_4 -> V_76 ) )
V_76 = true ;
else if ( F_66 ( V_2 -> V_4 -> V_64 ) )
return - V_42 ;
V_5 = F_48 ( V_2 -> V_4 ,
F_39 ,
& V_55 . V_58 , V_76 ) ;
if ( V_5 )
return V_5 ;
F_67 ( ! V_55 . V_58 ) ;
if ( V_119 . V_88 < sizeof( V_119 ) + ( V_55 . V_58 * sizeof( * V_61 ) ) ) {
V_5 = - V_132 ;
V_119 . V_72 = V_55 . V_58 ;
goto V_133;
}
V_61 = F_68 ( V_55 . V_58 , sizeof( * V_61 ) , V_134 ) ;
if ( ! V_61 )
return - V_135 ;
V_55 . V_61 = V_61 ;
V_5 = F_48 ( V_2 -> V_4 ,
F_40 ,
& V_55 , V_76 ) ;
if ( ! V_5 )
V_119 . V_72 = V_55 . V_57 ;
V_133:
if ( F_53 ( ( void V_86 * ) V_81 , & V_119 , V_82 ) )
V_5 = - V_87 ;
if ( ! V_5 ) {
if ( F_53 ( ( void V_86 * ) ( V_81 + V_82 ) , V_61 ,
V_119 . V_72 * sizeof( * V_61 ) ) )
V_5 = - V_87 ;
}
F_64 ( V_61 ) ;
return V_5 ;
} else if ( V_6 == V_136 ) {
struct V_137 V_119 ;
V_125 * V_138 ;
struct V_139 * V_73 ;
struct V_67 V_68 ;
bool V_76 = false ;
int V_71 , V_72 = 0 , V_5 = 0 ;
V_82 = F_51 ( struct V_137 , V_72 ) ;
if ( F_52 ( & V_119 , ( void V_86 * ) V_81 , V_82 ) )
return - V_87 ;
if ( V_119 . V_88 < V_82 || V_119 . V_17 )
return - V_74 ;
if ( ! F_65 ( V_2 -> V_4 -> V_76 ) )
V_76 = true ;
else if ( F_66 ( V_2 -> V_4 -> V_64 ) )
return - V_42 ;
V_5 = F_48 ( V_2 -> V_4 ,
F_39 ,
& V_72 , V_76 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_119 . V_72 || V_119 . V_72 > V_72 )
return - V_74 ;
V_138 = F_68 ( V_119 . V_72 , sizeof( * V_138 ) , V_134 ) ;
V_73 = F_68 ( V_119 . V_72 , sizeof( * V_73 ) , V_134 ) ;
if ( ! V_138 || ! V_73 ) {
F_64 ( V_138 ) ;
F_64 ( V_73 ) ;
return - V_135 ;
}
if ( F_52 ( V_138 , ( void V_86 * ) ( V_81 + V_82 ) ,
V_119 . V_72 * sizeof( * V_138 ) ) ) {
F_64 ( V_138 ) ;
F_64 ( V_73 ) ;
return - V_87 ;
}
for ( V_71 = 0 ; V_71 < V_119 . V_72 ; V_71 ++ ) {
struct V_140 * V_69 ;
struct V_141 V_142 = F_69 ( V_138 [ V_71 ] ) ;
if ( ! V_142 . V_143 ) {
V_5 = - V_144 ;
break;
}
V_69 = F_70 ( V_142 . V_143 ) ;
F_71 ( V_142 ) ;
if ( F_60 ( V_69 ) ) {
V_5 = F_61 ( V_69 ) ;
break;
}
V_73 [ V_71 ] . V_69 = V_69 ;
V_73 [ V_71 ] . V_70 = F_72 ( V_69 ) ;
}
F_64 ( V_138 ) ;
if ( V_5 )
goto V_145;
V_68 . V_72 = V_119 . V_72 ;
V_68 . V_73 = V_73 ;
V_5 = F_48 ( V_2 -> V_4 ,
F_45 ,
& V_68 , V_76 ) ;
if ( ! V_5 )
V_5 = V_76 ? F_73 ( V_2 -> V_4 -> V_76 ) :
F_74 ( V_2 -> V_4 -> V_64 ) ;
V_145:
for ( V_71 -- ; V_71 >= 0 ; V_71 -- )
F_75 ( V_73 [ V_71 ] . V_69 ) ;
F_64 ( V_73 ) ;
return V_5 ;
}
return - V_146 ;
}
static T_6 F_76 ( void * V_39 , char V_86 * V_147 ,
T_5 V_72 , T_7 * V_148 , bool V_149 )
{
unsigned int V_97 = F_77 ( * V_148 ) ;
struct V_1 * V_2 = V_39 ;
if ( V_97 >= V_92 )
return - V_74 ;
switch ( V_97 ) {
case V_98 :
return F_78 ( V_2 , V_147 , V_72 , V_148 , V_149 ) ;
case V_108 :
if ( V_149 )
return - V_74 ;
return F_79 ( V_2 , V_147 , V_72 , V_148 , false ) ;
case V_103 ... V_104 :
return F_79 ( V_2 , V_147 , V_72 , V_148 , V_149 ) ;
case V_110 :
return F_80 ( V_2 , V_147 , V_72 , V_148 , V_149 ) ;
}
return - V_74 ;
}
static T_6 F_81 ( void * V_39 , char V_86 * V_147 ,
T_5 V_72 , T_7 * V_148 )
{
if ( ! V_72 )
return 0 ;
return F_76 ( V_39 , V_147 , V_72 , V_148 , false ) ;
}
static T_6 F_82 ( void * V_39 , const char V_86 * V_147 ,
T_5 V_72 , T_7 * V_148 )
{
if ( ! V_72 )
return 0 ;
return F_76 ( V_39 , ( char V_86 * ) V_147 , V_72 , V_148 , true ) ;
}
static int F_83 ( void * V_39 , struct V_150 * V_151 )
{
struct V_1 * V_2 = V_39 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_97 ;
T_8 V_152 , V_153 , V_154 , V_155 ;
int V_5 ;
V_97 = V_151 -> V_156 >> ( V_157 - V_158 ) ;
if ( V_151 -> V_159 < V_151 -> V_160 )
return - V_74 ;
if ( ( V_151 -> V_161 & V_162 ) == 0 )
return - V_74 ;
if ( V_97 >= V_108 )
return - V_74 ;
if ( ! ( F_56 ( V_4 , V_97 ) & V_105 ) )
return - V_74 ;
V_152 = F_55 ( V_4 , V_97 ) ;
V_153 = V_151 -> V_159 - V_151 -> V_160 ;
V_154 = V_151 -> V_156 &
( ( 1U << ( V_157 - V_158 ) ) - 1 ) ;
V_155 = V_154 << V_158 ;
if ( V_152 < V_106 || V_155 + V_153 > V_152 )
return - V_74 ;
if ( V_97 == V_2 -> V_21 ) {
if ( ! ( V_155 >= V_2 -> V_23 + V_2 -> V_25 ||
V_155 + V_153 <= V_2 -> V_23 ) )
return - V_74 ;
}
if ( ! V_2 -> V_37 [ V_97 ] ) {
V_5 = F_84 ( V_4 ,
1 << V_97 , L_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_37 [ V_97 ] = F_85 ( V_4 , V_97 , 0 ) ;
}
V_151 -> V_163 = V_2 ;
V_151 -> V_164 = F_86 ( V_151 -> V_164 ) ;
V_151 -> V_156 = ( F_87 ( V_4 , V_97 ) >> V_158 ) + V_154 ;
return F_88 ( V_151 , V_151 -> V_160 , V_151 -> V_156 ,
V_153 , V_151 -> V_164 ) ;
}
static int F_89 ( struct V_3 * V_4 , const struct V_165 * V_70 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_56 * V_69 ;
int V_5 ;
F_37 ( V_4 , V_166 , & type ) ;
if ( ( type & V_166 ) != V_167 )
return - V_74 ;
V_69 = F_41 ( & V_4 -> V_11 ) ;
if ( ! V_69 )
return - V_74 ;
V_2 = F_90 ( sizeof( * V_2 ) , V_134 ) ;
if ( ! V_2 ) {
F_44 ( V_69 ) ;
return - V_135 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_93 ;
F_91 ( & V_2 -> V_127 ) ;
F_92 ( & V_2 -> V_168 ) ;
F_93 ( & V_2 -> V_40 , 0 ) ;
V_5 = F_94 ( & V_4 -> V_11 , & V_169 , V_2 ) ;
if ( V_5 ) {
F_44 ( V_69 ) ;
F_64 ( V_2 ) ;
}
return V_5 ;
}
static void F_95 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_96 ( & V_4 -> V_11 ) ;
if ( ! V_2 )
return;
F_44 ( V_4 -> V_11 . V_56 ) ;
F_64 ( V_2 ) ;
}
static T_9 F_97 ( struct V_3 * V_4 ,
T_10 V_170 )
{
struct V_1 * V_2 ;
struct V_171 * V_172 ;
V_172 = F_98 ( & V_4 -> V_11 ) ;
if ( V_172 == NULL )
return V_173 ;
V_2 = F_99 ( V_172 ) ;
if ( V_2 == NULL ) {
F_100 ( V_172 ) ;
return V_173 ;
}
if ( V_2 -> V_174 )
F_101 ( V_2 -> V_174 , 1 ) ;
F_100 ( V_172 ) ;
return V_175 ;
}
static void T_11 F_102 ( void )
{
F_103 ( & V_176 ) ;
F_104 () ;
F_105 () ;
}
static int T_12 F_106 ( void )
{
int V_5 ;
V_5 = F_107 () ;
if ( V_5 )
return V_5 ;
V_5 = F_108 () ;
if ( V_5 )
goto V_177;
V_5 = F_109 ( & V_176 ) ;
if ( V_5 )
goto V_178;
return 0 ;
V_178:
F_104 () ;
V_177:
F_105 () ;
return V_5 ;
}
