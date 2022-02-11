static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_5 ;
T_1 V_6 ;
T_2 V_7 ;
F_2 ( V_4 ) ;
V_5 = F_3 ( V_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_8 = ( F_4 ( V_4 ) == 0 ) ;
F_5 ( V_4 ) ;
V_2 -> V_9 = F_6 ( V_4 ) ;
if ( ! V_2 -> V_9 )
F_7 ( L_1 ,
V_10 , F_8 ( & V_4 -> V_11 ) ) ;
V_5 = F_9 ( V_2 ) ;
if ( V_5 ) {
F_10 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
F_11 ( V_4 ) ;
return V_5 ;
}
if ( F_12 ( ! V_12 ) )
V_2 -> V_13 = F_13 ( V_4 ) ;
F_14 ( V_4 , V_14 , & V_6 ) ;
if ( V_2 -> V_13 && ( V_6 & V_15 ) ) {
V_6 &= ~ V_15 ;
F_15 ( V_4 , V_14 , V_6 ) ;
}
V_7 = V_4 -> V_16 ;
if ( V_7 ) {
T_1 V_17 ;
T_3 V_18 ;
F_14 ( V_4 , V_7 + V_19 , & V_17 ) ;
F_16 ( V_4 , V_7 + V_20 , & V_18 ) ;
V_2 -> V_21 = V_18 & V_22 ;
V_2 -> V_23 = V_18 & V_24 ;
V_2 -> V_25 = ( ( V_17 & V_26 ) + 1 ) * 16 ;
} else
V_2 -> V_21 = 0xFF ;
#ifdef F_17
if ( ( V_4 -> V_27 >> 8 ) == V_28 )
V_2 -> V_29 = true ;
#endif
return 0 ;
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
int V_30 ;
F_2 ( V_4 ) ;
F_19 ( V_2 , V_31 |
V_32 ,
V_2 -> V_33 , 0 , 0 , NULL ) ;
V_2 -> V_34 = false ;
F_20 ( V_2 ) ;
for ( V_30 = V_35 ; V_30 <= V_36 ; V_30 ++ ) {
if ( ! V_2 -> V_37 [ V_30 ] )
continue;
F_21 ( V_4 , V_2 -> V_37 [ V_30 ] ) ;
F_22 ( V_4 , 1 << V_30 ) ;
V_2 -> V_37 [ V_30 ] = NULL ;
}
V_2 -> V_38 = true ;
if ( F_23 ( V_4 , & V_2 -> V_9 ) ) {
F_24 ( L_2 ,
V_10 , F_8 ( & V_4 -> V_11 ) ) ;
if ( ! V_2 -> V_8 )
goto V_39;
F_5 ( V_4 ) ;
}
F_15 ( V_4 , V_14 , V_15 ) ;
if ( V_2 -> V_8 ) {
int V_5 = F_25 ( V_4 ) ;
if ( V_5 )
F_26 ( L_3 ,
V_10 , F_8 ( & V_4 -> V_11 ) , V_5 ) ;
else
V_2 -> V_38 = false ;
}
F_27 ( V_4 ) ;
V_39:
F_11 ( V_4 ) ;
F_28 ( V_2 ) ;
}
static void F_29 ( void * V_40 )
{
struct V_1 * V_2 = V_40 ;
F_30 ( & V_41 ) ;
if ( ! ( -- V_2 -> V_42 ) ) {
F_31 ( V_2 -> V_4 ) ;
F_18 ( V_2 ) ;
}
F_32 ( & V_41 ) ;
F_33 ( V_43 ) ;
}
static int F_34 ( void * V_40 )
{
struct V_1 * V_2 = V_40 ;
int V_5 = 0 ;
if ( ! F_35 ( V_43 ) )
return - V_44 ;
F_30 ( & V_41 ) ;
if ( ! V_2 -> V_42 ) {
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
goto error;
F_36 ( V_2 -> V_4 ) ;
}
V_2 -> V_42 ++ ;
error:
F_32 ( & V_41 ) ;
if ( V_5 )
F_33 ( V_43 ) ;
return V_5 ;
}
static int F_37 ( struct V_1 * V_2 , int V_33 )
{
if ( V_33 == V_45 ) {
T_2 V_46 ;
F_38 ( V_2 -> V_4 , V_47 , & V_46 ) ;
if ( F_39 ( V_48 ) && V_46 )
return 1 ;
} else if ( V_33 == V_49 ) {
T_2 V_50 ;
T_1 V_17 ;
V_50 = V_2 -> V_4 -> V_51 ;
if ( V_50 ) {
F_14 ( V_2 -> V_4 ,
V_50 + V_52 , & V_17 ) ;
return 1 << ( ( V_17 & V_53 ) >> 1 ) ;
}
} else if ( V_33 == V_54 ) {
T_2 V_50 ;
T_1 V_17 ;
V_50 = V_2 -> V_4 -> V_16 ;
if ( V_50 ) {
F_14 ( V_2 -> V_4 ,
V_50 + V_19 , & V_17 ) ;
return ( V_17 & V_26 ) + 1 ;
}
} else if ( V_33 == V_55 ) {
if ( F_40 ( V_2 -> V_4 ) )
return 1 ;
} else if ( V_33 == V_56 ) {
return 1 ;
}
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , void * V_57 )
{
( * ( int * ) V_57 ) ++ ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , void * V_57 )
{
struct V_58 * V_59 = V_57 ;
struct V_60 * V_60 ;
if ( V_59 -> V_61 == V_59 -> V_62 )
return - V_63 ;
V_60 = F_43 ( & V_4 -> V_11 ) ;
if ( ! V_60 )
return - V_64 ;
V_59 -> V_65 [ V_59 -> V_61 ] . V_66 = F_44 ( V_60 ) ;
V_59 -> V_65 [ V_59 -> V_61 ] . V_67 = F_45 ( V_4 -> V_68 ) ;
V_59 -> V_65 [ V_59 -> V_61 ] . V_68 = V_4 -> V_68 -> V_69 ;
V_59 -> V_65 [ V_59 -> V_61 ] . V_70 = V_4 -> V_70 ;
V_59 -> V_61 ++ ;
F_46 ( V_60 ) ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 , void * V_57 )
{
struct V_71 * V_72 = V_57 ;
struct V_60 * V_73 ;
int V_74 , V_75 ;
V_73 = F_43 ( & V_4 -> V_11 ) ;
if ( ! V_73 )
return - V_64 ;
V_74 = F_44 ( V_73 ) ;
for ( V_75 = 0 ; V_75 < V_72 -> V_76 ; V_75 ++ )
if ( V_72 -> V_77 [ V_75 ] . V_74 == V_74 )
break;
F_46 ( V_73 ) ;
return ( V_75 == V_72 -> V_76 ) ? - V_78 : 0 ;
}
static bool F_48 ( struct V_3 * V_4 , struct V_79 * V_80 )
{
for (; V_4 ; V_4 = V_4 -> V_68 -> V_81 )
if ( V_4 -> V_68 == V_80 -> V_68 )
return ( V_4 -> V_80 == V_80 ) ;
return false ;
}
static int F_49 ( struct V_3 * V_4 , void * V_57 )
{
struct V_82 * V_83 = V_57 ;
if ( ! V_83 -> V_80 || F_48 ( V_4 , V_83 -> V_4 -> V_80 ) )
V_83 -> V_5 = V_83 -> V_84 ( V_4 , V_83 -> V_57 ) ;
return V_83 -> V_5 ;
}
static int F_50 ( struct V_3 * V_4 ,
int (* V_84)( struct V_3 * ,
void * V_57 ) , void * V_57 ,
bool V_80 )
{
struct V_82 V_83 = {
. V_84 = V_84 , . V_57 = V_57 , . V_4 = V_4 , . V_80 = V_80 , . V_5 = 0 ,
} ;
F_51 ( V_4 -> V_68 , F_49 , & V_83 ) ;
return V_83 . V_5 ;
}
static long F_52 ( void * V_40 ,
unsigned int V_6 , unsigned long V_85 )
{
struct V_1 * V_2 = V_40 ;
unsigned long V_86 ;
if ( V_6 == V_87 ) {
struct V_88 V_72 ;
V_86 = F_53 ( struct V_88 , V_89 ) ;
if ( F_54 ( & V_72 , ( void V_90 * ) V_85 , V_86 ) )
return - V_91 ;
if ( V_72 . V_92 < V_86 )
return - V_78 ;
V_72 . V_17 = V_93 ;
if ( V_2 -> V_8 )
V_72 . V_17 |= V_94 ;
V_72 . V_95 = V_96 ;
V_72 . V_89 = V_97 ;
return F_55 ( ( void V_90 * ) V_85 , & V_72 , V_86 ) ;
} else if ( V_6 == V_98 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_99 V_72 ;
V_86 = F_53 ( struct V_99 , V_100 ) ;
if ( F_54 ( & V_72 , ( void V_90 * ) V_85 , V_86 ) )
return - V_91 ;
if ( V_72 . V_92 < V_86 )
return - V_78 ;
switch ( V_72 . V_101 ) {
case V_102 :
V_72 . V_100 = F_56 ( V_72 . V_101 ) ;
V_72 . V_103 = V_4 -> V_104 ;
V_72 . V_17 = V_105 |
V_106 ;
break;
case V_107 ... V_108 :
V_72 . V_100 = F_56 ( V_72 . V_101 ) ;
V_72 . V_103 = F_57 ( V_4 , V_72 . V_101 ) ;
if ( ! V_72 . V_103 ) {
V_72 . V_17 = 0 ;
break;
}
V_72 . V_17 = V_105 |
V_106 ;
if ( F_39 ( V_109 ) &&
F_58 ( V_4 , V_72 . V_101 ) &
V_110 && V_72 . V_103 >= V_111 )
V_72 . V_17 |= V_112 ;
break;
case V_113 :
{
void T_4 * V_114 ;
T_5 V_103 ;
V_72 . V_100 = F_56 ( V_72 . V_101 ) ;
V_72 . V_17 = 0 ;
V_72 . V_103 = F_57 ( V_4 , V_72 . V_101 ) ;
if ( ! V_72 . V_103 )
break;
V_114 = F_59 ( V_4 , & V_103 ) ;
if ( ! V_114 || ! V_103 ) {
V_72 . V_103 = 0 ;
break;
}
F_60 ( V_4 , V_114 ) ;
V_72 . V_17 = V_105 ;
break;
}
case V_115 :
if ( ! V_2 -> V_29 )
return - V_78 ;
V_72 . V_100 = F_56 ( V_72 . V_101 ) ;
V_72 . V_103 = 0xc0000 ;
V_72 . V_17 = V_105 |
V_106 ;
break;
default:
return - V_78 ;
}
return F_55 ( ( void V_90 * ) V_85 , & V_72 , V_86 ) ;
} else if ( V_6 == V_116 ) {
struct V_117 V_72 ;
V_86 = F_53 ( struct V_117 , V_76 ) ;
if ( F_54 ( & V_72 , ( void V_90 * ) V_85 , V_86 ) )
return - V_91 ;
if ( V_72 . V_92 < V_86 || V_72 . V_101 >= V_97 )
return - V_78 ;
switch ( V_72 . V_101 ) {
case V_45 ... V_54 :
case V_56 :
break;
case V_55 :
if ( F_40 ( V_2 -> V_4 ) )
break;
default:
return - V_78 ;
}
V_72 . V_17 = V_118 ;
V_72 . V_76 = F_37 ( V_2 , V_72 . V_101 ) ;
if ( V_72 . V_101 == V_45 )
V_72 . V_17 |= ( V_119 |
V_120 ) ;
else
V_72 . V_17 |= V_121 ;
return F_55 ( ( void V_90 * ) V_85 , & V_72 , V_86 ) ;
} else if ( V_6 == V_122 ) {
struct V_123 V_124 ;
T_2 * V_57 = NULL ;
int V_5 = 0 ;
V_86 = F_53 ( struct V_123 , V_76 ) ;
if ( F_54 ( & V_124 , ( void V_90 * ) V_85 , V_86 ) )
return - V_91 ;
if ( V_124 . V_92 < V_86 || V_124 . V_101 >= V_97 ||
V_124 . V_17 & ~ ( V_125 |
V_126 ) )
return - V_78 ;
if ( ! ( V_124 . V_17 & V_31 ) ) {
T_5 V_103 ;
int V_62 = F_37 ( V_2 , V_124 . V_101 ) ;
if ( V_124 . V_17 & V_127 )
V_103 = sizeof( V_128 ) ;
else if ( V_124 . V_17 & V_129 )
V_103 = sizeof( V_130 ) ;
else
return - V_78 ;
if ( V_124 . V_92 - V_86 < V_124 . V_76 * V_103 ||
V_124 . V_131 >= V_62 || V_124 . V_131 + V_124 . V_76 > V_62 )
return - V_78 ;
V_57 = F_61 ( ( void V_90 * ) ( V_85 + V_86 ) ,
V_124 . V_76 * V_103 ) ;
if ( F_62 ( V_57 ) )
return F_63 ( V_57 ) ;
}
F_30 ( & V_2 -> V_132 ) ;
V_5 = F_19 ( V_2 , V_124 . V_17 , V_124 . V_101 ,
V_124 . V_131 , V_124 . V_76 , V_57 ) ;
F_32 ( & V_2 -> V_132 ) ;
F_10 ( V_57 ) ;
return V_5 ;
} else if ( V_6 == V_133 ) {
return V_2 -> V_8 ?
F_25 ( V_2 -> V_4 ) : - V_78 ;
} else if ( V_6 == V_134 ) {
struct V_135 V_124 ;
struct V_58 V_59 = { 0 } ;
struct V_136 * V_65 = NULL ;
bool V_80 = false ;
int V_5 = 0 ;
V_86 = F_53 ( struct V_135 , V_76 ) ;
if ( F_54 ( & V_124 , ( void V_90 * ) V_85 , V_86 ) )
return - V_91 ;
if ( V_124 . V_92 < V_86 )
return - V_78 ;
V_124 . V_17 = 0 ;
if ( ! F_64 ( V_2 -> V_4 -> V_80 ) )
V_80 = true ;
else if ( F_65 ( V_2 -> V_4 -> V_68 ) )
return - V_44 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_41 ,
& V_59 . V_62 , V_80 ) ;
if ( V_5 )
return V_5 ;
F_66 ( ! V_59 . V_62 ) ;
if ( V_124 . V_92 < sizeof( V_124 ) + ( V_59 . V_62 * sizeof( * V_65 ) ) ) {
V_5 = - V_137 ;
V_124 . V_76 = V_59 . V_62 ;
goto V_138;
}
V_65 = F_67 ( V_59 . V_62 , sizeof( * V_65 ) , V_139 ) ;
if ( ! V_65 )
return - V_140 ;
V_59 . V_65 = V_65 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_42 ,
& V_59 , V_80 ) ;
if ( ! V_5 )
V_124 . V_76 = V_59 . V_61 ;
V_138:
if ( F_55 ( ( void V_90 * ) V_85 , & V_124 , V_86 ) )
V_5 = - V_91 ;
if ( ! V_5 ) {
if ( F_55 ( ( void V_90 * ) ( V_85 + V_86 ) , V_65 ,
V_124 . V_76 * sizeof( * V_65 ) ) )
V_5 = - V_91 ;
}
F_10 ( V_65 ) ;
return V_5 ;
} else if ( V_6 == V_141 ) {
struct V_142 V_124 ;
V_130 * V_143 ;
struct V_144 * V_77 ;
struct V_71 V_72 ;
bool V_80 = false ;
int V_75 , V_76 = 0 , V_5 = 0 ;
V_86 = F_53 ( struct V_142 , V_76 ) ;
if ( F_54 ( & V_124 , ( void V_90 * ) V_85 , V_86 ) )
return - V_91 ;
if ( V_124 . V_92 < V_86 || V_124 . V_17 )
return - V_78 ;
if ( ! F_64 ( V_2 -> V_4 -> V_80 ) )
V_80 = true ;
else if ( F_65 ( V_2 -> V_4 -> V_68 ) )
return - V_44 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_41 ,
& V_76 , V_80 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_124 . V_76 || V_124 . V_76 > V_76 )
return - V_78 ;
V_143 = F_67 ( V_124 . V_76 , sizeof( * V_143 ) , V_139 ) ;
V_77 = F_67 ( V_124 . V_76 , sizeof( * V_77 ) , V_139 ) ;
if ( ! V_143 || ! V_77 ) {
F_10 ( V_143 ) ;
F_10 ( V_77 ) ;
return - V_140 ;
}
if ( F_54 ( V_143 , ( void V_90 * ) ( V_85 + V_86 ) ,
V_124 . V_76 * sizeof( * V_143 ) ) ) {
F_10 ( V_143 ) ;
F_10 ( V_77 ) ;
return - V_91 ;
}
for ( V_75 = 0 ; V_75 < V_124 . V_76 ; V_75 ++ ) {
struct V_145 * V_73 ;
struct V_146 V_147 = F_68 ( V_143 [ V_75 ] ) ;
if ( ! V_147 . V_148 ) {
V_5 = - V_149 ;
break;
}
V_73 = F_69 ( V_147 . V_148 ) ;
F_70 ( V_147 ) ;
if ( F_62 ( V_73 ) ) {
V_5 = F_63 ( V_73 ) ;
break;
}
V_77 [ V_75 ] . V_73 = V_73 ;
V_77 [ V_75 ] . V_74 = F_71 ( V_73 ) ;
}
F_10 ( V_143 ) ;
if ( V_5 )
goto V_150;
V_72 . V_76 = V_124 . V_76 ;
V_72 . V_77 = V_77 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_47 ,
& V_72 , V_80 ) ;
if ( ! V_5 )
V_5 = V_80 ? F_72 ( V_2 -> V_4 -> V_80 ) :
F_73 ( V_2 -> V_4 -> V_68 ) ;
V_150:
for ( V_75 -- ; V_75 >= 0 ; V_75 -- )
F_74 ( V_77 [ V_75 ] . V_73 ) ;
F_10 ( V_77 ) ;
return V_5 ;
}
return - V_151 ;
}
static T_6 F_75 ( void * V_40 , char V_90 * V_152 ,
T_5 V_76 , T_7 * V_153 , bool V_154 )
{
unsigned int V_101 = F_76 ( * V_153 ) ;
struct V_1 * V_2 = V_40 ;
if ( V_101 >= V_96 )
return - V_78 ;
switch ( V_101 ) {
case V_102 :
return F_77 ( V_2 , V_152 , V_76 , V_153 , V_154 ) ;
case V_113 :
if ( V_154 )
return - V_78 ;
return F_78 ( V_2 , V_152 , V_76 , V_153 , false ) ;
case V_107 ... V_108 :
return F_78 ( V_2 , V_152 , V_76 , V_153 , V_154 ) ;
case V_115 :
return F_79 ( V_2 , V_152 , V_76 , V_153 , V_154 ) ;
}
return - V_78 ;
}
static T_6 F_80 ( void * V_40 , char V_90 * V_152 ,
T_5 V_76 , T_7 * V_153 )
{
if ( ! V_76 )
return 0 ;
return F_75 ( V_40 , V_152 , V_76 , V_153 , false ) ;
}
static T_6 F_81 ( void * V_40 , const char V_90 * V_152 ,
T_5 V_76 , T_7 * V_153 )
{
if ( ! V_76 )
return 0 ;
return F_75 ( V_40 , ( char V_90 * ) V_152 , V_76 , V_153 , true ) ;
}
static int F_82 ( void * V_40 , struct V_155 * V_156 )
{
struct V_1 * V_2 = V_40 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_101 ;
T_8 V_157 , V_158 , V_159 , V_160 ;
int V_5 ;
V_101 = V_156 -> V_161 >> ( V_162 - V_163 ) ;
if ( V_156 -> V_164 < V_156 -> V_165 )
return - V_78 ;
if ( ( V_156 -> V_166 & V_167 ) == 0 )
return - V_78 ;
if ( V_101 >= V_113 )
return - V_78 ;
if ( ! ( F_58 ( V_4 , V_101 ) & V_110 ) )
return - V_78 ;
V_157 = F_57 ( V_4 , V_101 ) ;
V_158 = V_156 -> V_164 - V_156 -> V_165 ;
V_159 = V_156 -> V_161 &
( ( 1U << ( V_162 - V_163 ) ) - 1 ) ;
V_160 = V_159 << V_163 ;
if ( V_157 < V_111 || V_160 + V_158 > V_157 )
return - V_78 ;
if ( V_101 == V_2 -> V_21 ) {
if ( ! ( V_160 >= V_2 -> V_23 + V_2 -> V_25 ||
V_160 + V_158 <= V_2 -> V_23 ) )
return - V_78 ;
}
if ( ! V_2 -> V_37 [ V_101 ] ) {
V_5 = F_83 ( V_4 ,
1 << V_101 , L_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_37 [ V_101 ] = F_84 ( V_4 , V_101 , 0 ) ;
}
V_156 -> V_168 = V_2 ;
V_156 -> V_169 = F_85 ( V_156 -> V_169 ) ;
V_156 -> V_161 = ( F_86 ( V_4 , V_101 ) >> V_163 ) + V_159 ;
return F_87 ( V_156 , V_156 -> V_165 , V_156 -> V_161 ,
V_158 , V_156 -> V_169 ) ;
}
static void F_88 ( void * V_40 , unsigned int V_76 )
{
struct V_1 * V_2 = V_40 ;
F_30 ( & V_2 -> V_132 ) ;
if ( V_2 -> V_170 ) {
F_89 ( & V_2 -> V_4 -> V_11 , L_5 ) ;
F_90 ( V_2 -> V_170 , 1 ) ;
}
F_32 ( & V_2 -> V_132 ) ;
}
static int F_91 ( struct V_3 * V_4 , const struct V_171 * V_74 )
{
struct V_1 * V_2 ;
struct V_60 * V_73 ;
int V_5 ;
if ( V_4 -> V_172 != V_173 )
return - V_78 ;
V_73 = F_43 ( & V_4 -> V_11 ) ;
if ( ! V_73 )
return - V_78 ;
V_2 = F_92 ( sizeof( * V_2 ) , V_139 ) ;
if ( ! V_2 ) {
F_46 ( V_73 ) ;
return - V_140 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_97 ;
F_93 ( & V_2 -> V_132 ) ;
F_94 ( & V_2 -> V_174 ) ;
V_5 = F_95 ( & V_4 -> V_11 , & V_175 , V_2 ) ;
if ( V_5 ) {
F_46 ( V_73 ) ;
F_10 ( V_2 ) ;
}
return V_5 ;
}
static void F_96 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_97 ( & V_4 -> V_11 ) ;
if ( V_2 ) {
F_46 ( V_4 -> V_11 . V_60 ) ;
F_10 ( V_2 ) ;
}
}
static T_9 F_98 ( struct V_3 * V_4 ,
T_10 V_176 )
{
struct V_1 * V_2 ;
struct V_177 * V_178 ;
V_178 = F_99 ( & V_4 -> V_11 ) ;
if ( V_178 == NULL )
return V_179 ;
V_2 = F_100 ( V_178 ) ;
if ( V_2 == NULL ) {
F_101 ( V_178 ) ;
return V_179 ;
}
F_30 ( & V_2 -> V_132 ) ;
if ( V_2 -> V_180 )
F_90 ( V_2 -> V_180 , 1 ) ;
F_32 ( & V_2 -> V_132 ) ;
F_101 ( V_178 ) ;
return V_181 ;
}
static int F_102 ( struct V_3 * V_4 , void * V_57 )
{
struct V_182 * V_183 = V_57 ;
struct V_184 * V_185 = F_103 ( V_4 -> V_186 ) ;
if ( V_185 != & V_187 )
return - V_188 ;
if ( V_183 -> V_189 == V_183 -> V_190 )
return - V_137 ;
V_183 -> V_65 [ V_183 -> V_189 ] = F_99 ( & V_4 -> V_11 ) ;
if ( ! V_183 -> V_65 [ V_183 -> V_189 ] )
return - V_78 ;
V_183 -> V_189 ++ ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_182 V_183 = { . V_189 = 0 } ;
int V_75 = 0 , V_5 = - V_78 ;
bool V_38 = false , V_80 = false ;
struct V_1 * V_191 ;
if ( ! F_64 ( V_2 -> V_4 -> V_80 ) )
V_80 = true ;
else if ( F_65 ( V_2 -> V_4 -> V_68 ) )
return;
if ( F_50 ( V_2 -> V_4 , F_41 ,
& V_75 , V_80 ) || ! V_75 )
return;
V_183 . V_190 = V_75 ;
V_183 . V_65 = F_67 ( V_75 , sizeof( struct V_177 * ) , V_139 ) ;
if ( ! V_183 . V_65 )
return;
if ( F_50 ( V_2 -> V_4 ,
F_102 , & V_183 , V_80 ) )
goto V_192;
for ( V_75 = 0 ; V_75 < V_183 . V_189 ; V_75 ++ ) {
V_191 = F_100 ( V_183 . V_65 [ V_75 ] ) ;
if ( V_191 -> V_38 )
V_38 = true ;
if ( V_191 -> V_42 )
goto V_192;
}
if ( V_38 )
V_5 = V_80 ? F_72 ( V_2 -> V_4 -> V_80 ) :
F_73 ( V_2 -> V_4 -> V_68 ) ;
V_192:
for ( V_75 = 0 ; V_75 < V_183 . V_189 ; V_75 ++ ) {
if ( ! V_5 ) {
V_191 = F_100 ( V_183 . V_65 [ V_75 ] ) ;
V_191 -> V_38 = false ;
}
F_101 ( V_183 . V_65 [ V_75 ] ) ;
}
F_10 ( V_183 . V_65 ) ;
}
static void T_11 F_104 ( void )
{
F_105 ( & V_187 ) ;
F_106 () ;
F_107 () ;
}
static int T_12 F_108 ( void )
{
int V_5 ;
V_5 = F_109 () ;
if ( V_5 )
return V_5 ;
V_5 = F_110 () ;
if ( V_5 )
goto V_193;
V_5 = F_111 ( & V_187 ) ;
if ( V_5 )
goto V_194;
return 0 ;
V_194:
F_106 () ;
V_193:
F_107 () ;
return V_5 ;
}
