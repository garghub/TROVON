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
} else if ( V_33 == V_55 )
if ( F_40 ( V_2 -> V_4 ) )
return 1 ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , void * V_56 )
{
( * ( int * ) V_56 ) ++ ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , void * V_56 )
{
struct V_57 * V_58 = V_56 ;
struct V_59 * V_59 ;
if ( V_58 -> V_60 == V_58 -> V_61 )
return - V_62 ;
V_59 = F_43 ( & V_4 -> V_11 ) ;
if ( ! V_59 )
return - V_63 ;
V_58 -> V_64 [ V_58 -> V_60 ] . V_65 = F_44 ( V_59 ) ;
V_58 -> V_64 [ V_58 -> V_60 ] . V_66 = F_45 ( V_4 -> V_67 ) ;
V_58 -> V_64 [ V_58 -> V_60 ] . V_67 = V_4 -> V_67 -> V_68 ;
V_58 -> V_64 [ V_58 -> V_60 ] . V_69 = V_4 -> V_69 ;
V_58 -> V_60 ++ ;
F_46 ( V_59 ) ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 , void * V_56 )
{
struct V_70 * V_71 = V_56 ;
struct V_59 * V_72 ;
int V_73 , V_74 ;
V_72 = F_43 ( & V_4 -> V_11 ) ;
if ( ! V_72 )
return - V_63 ;
V_73 = F_44 ( V_72 ) ;
for ( V_74 = 0 ; V_74 < V_71 -> V_75 ; V_74 ++ )
if ( V_71 -> V_76 [ V_74 ] . V_73 == V_73 )
break;
F_46 ( V_72 ) ;
return ( V_74 == V_71 -> V_75 ) ? - V_77 : 0 ;
}
static bool F_48 ( struct V_3 * V_4 , struct V_78 * V_79 )
{
for (; V_4 ; V_4 = V_4 -> V_67 -> V_80 )
if ( V_4 -> V_67 == V_79 -> V_67 )
return ( V_4 -> V_79 == V_79 ) ;
return false ;
}
static int F_49 ( struct V_3 * V_4 , void * V_56 )
{
struct V_81 * V_82 = V_56 ;
if ( ! V_82 -> V_79 || F_48 ( V_4 , V_82 -> V_4 -> V_79 ) )
V_82 -> V_5 = V_82 -> V_83 ( V_4 , V_82 -> V_56 ) ;
return V_82 -> V_5 ;
}
static int F_50 ( struct V_3 * V_4 ,
int (* V_83)( struct V_3 * ,
void * V_56 ) , void * V_56 ,
bool V_79 )
{
struct V_81 V_82 = {
. V_83 = V_83 , . V_56 = V_56 , . V_4 = V_4 , . V_79 = V_79 , . V_5 = 0 ,
} ;
F_51 ( V_4 -> V_67 , F_49 , & V_82 ) ;
return V_82 . V_5 ;
}
static long F_52 ( void * V_40 ,
unsigned int V_6 , unsigned long V_84 )
{
struct V_1 * V_2 = V_40 ;
unsigned long V_85 ;
if ( V_6 == V_86 ) {
struct V_87 V_71 ;
V_85 = F_53 ( struct V_87 , V_88 ) ;
if ( F_54 ( & V_71 , ( void V_89 * ) V_84 , V_85 ) )
return - V_90 ;
if ( V_71 . V_91 < V_85 )
return - V_77 ;
V_71 . V_17 = V_92 ;
if ( V_2 -> V_8 )
V_71 . V_17 |= V_93 ;
V_71 . V_94 = V_95 ;
V_71 . V_88 = V_96 ;
return F_55 ( ( void V_89 * ) V_84 , & V_71 , V_85 ) ;
} else if ( V_6 == V_97 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_98 V_71 ;
V_85 = F_53 ( struct V_98 , V_99 ) ;
if ( F_54 ( & V_71 , ( void V_89 * ) V_84 , V_85 ) )
return - V_90 ;
if ( V_71 . V_91 < V_85 )
return - V_77 ;
switch ( V_71 . V_100 ) {
case V_101 :
V_71 . V_99 = F_56 ( V_71 . V_100 ) ;
V_71 . V_102 = V_4 -> V_103 ;
V_71 . V_17 = V_104 |
V_105 ;
break;
case V_106 ... V_107 :
V_71 . V_99 = F_56 ( V_71 . V_100 ) ;
V_71 . V_102 = F_57 ( V_4 , V_71 . V_100 ) ;
if ( ! V_71 . V_102 ) {
V_71 . V_17 = 0 ;
break;
}
V_71 . V_17 = V_104 |
V_105 ;
if ( F_39 ( V_108 ) &&
F_58 ( V_4 , V_71 . V_100 ) &
V_109 && V_71 . V_102 >= V_110 )
V_71 . V_17 |= V_111 ;
break;
case V_112 :
{
void T_4 * V_113 ;
T_5 V_102 ;
V_71 . V_99 = F_56 ( V_71 . V_100 ) ;
V_71 . V_17 = 0 ;
V_71 . V_102 = F_57 ( V_4 , V_71 . V_100 ) ;
if ( ! V_71 . V_102 )
break;
V_113 = F_59 ( V_4 , & V_102 ) ;
if ( ! V_113 || ! V_102 ) {
V_71 . V_102 = 0 ;
break;
}
F_60 ( V_4 , V_113 ) ;
V_71 . V_17 = V_104 ;
break;
}
case V_114 :
if ( ! V_2 -> V_29 )
return - V_77 ;
V_71 . V_99 = F_56 ( V_71 . V_100 ) ;
V_71 . V_102 = 0xc0000 ;
V_71 . V_17 = V_104 |
V_105 ;
break;
default:
return - V_77 ;
}
return F_55 ( ( void V_89 * ) V_84 , & V_71 , V_85 ) ;
} else if ( V_6 == V_115 ) {
struct V_116 V_71 ;
V_85 = F_53 ( struct V_116 , V_75 ) ;
if ( F_54 ( & V_71 , ( void V_89 * ) V_84 , V_85 ) )
return - V_90 ;
if ( V_71 . V_91 < V_85 || V_71 . V_100 >= V_96 )
return - V_77 ;
switch ( V_71 . V_100 ) {
case V_45 ... V_54 :
break;
case V_55 :
if ( F_40 ( V_2 -> V_4 ) )
break;
default:
return - V_77 ;
}
V_71 . V_17 = V_117 ;
V_71 . V_75 = F_37 ( V_2 , V_71 . V_100 ) ;
if ( V_71 . V_100 == V_45 )
V_71 . V_17 |= ( V_118 |
V_119 ) ;
else
V_71 . V_17 |= V_120 ;
return F_55 ( ( void V_89 * ) V_84 , & V_71 , V_85 ) ;
} else if ( V_6 == V_121 ) {
struct V_122 V_123 ;
T_2 * V_56 = NULL ;
int V_5 = 0 ;
V_85 = F_53 ( struct V_122 , V_75 ) ;
if ( F_54 ( & V_123 , ( void V_89 * ) V_84 , V_85 ) )
return - V_90 ;
if ( V_123 . V_91 < V_85 || V_123 . V_100 >= V_96 ||
V_123 . V_17 & ~ ( V_124 |
V_125 ) )
return - V_77 ;
if ( ! ( V_123 . V_17 & V_31 ) ) {
T_5 V_102 ;
int V_61 = F_37 ( V_2 , V_123 . V_100 ) ;
if ( V_123 . V_17 & V_126 )
V_102 = sizeof( V_127 ) ;
else if ( V_123 . V_17 & V_128 )
V_102 = sizeof( V_129 ) ;
else
return - V_77 ;
if ( V_123 . V_91 - V_85 < V_123 . V_75 * V_102 ||
V_123 . V_130 >= V_61 || V_123 . V_130 + V_123 . V_75 > V_61 )
return - V_77 ;
V_56 = F_61 ( ( void V_89 * ) ( V_84 + V_85 ) ,
V_123 . V_75 * V_102 ) ;
if ( F_62 ( V_56 ) )
return F_63 ( V_56 ) ;
}
F_30 ( & V_2 -> V_131 ) ;
V_5 = F_19 ( V_2 , V_123 . V_17 , V_123 . V_100 ,
V_123 . V_130 , V_123 . V_75 , V_56 ) ;
F_32 ( & V_2 -> V_131 ) ;
F_10 ( V_56 ) ;
return V_5 ;
} else if ( V_6 == V_132 ) {
return V_2 -> V_8 ?
F_25 ( V_2 -> V_4 ) : - V_77 ;
} else if ( V_6 == V_133 ) {
struct V_134 V_123 ;
struct V_57 V_58 = { 0 } ;
struct V_135 * V_64 = NULL ;
bool V_79 = false ;
int V_5 = 0 ;
V_85 = F_53 ( struct V_134 , V_75 ) ;
if ( F_54 ( & V_123 , ( void V_89 * ) V_84 , V_85 ) )
return - V_90 ;
if ( V_123 . V_91 < V_85 )
return - V_77 ;
V_123 . V_17 = 0 ;
if ( ! F_64 ( V_2 -> V_4 -> V_79 ) )
V_79 = true ;
else if ( F_65 ( V_2 -> V_4 -> V_67 ) )
return - V_44 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_41 ,
& V_58 . V_61 , V_79 ) ;
if ( V_5 )
return V_5 ;
F_66 ( ! V_58 . V_61 ) ;
if ( V_123 . V_91 < sizeof( V_123 ) + ( V_58 . V_61 * sizeof( * V_64 ) ) ) {
V_5 = - V_136 ;
V_123 . V_75 = V_58 . V_61 ;
goto V_137;
}
V_64 = F_67 ( V_58 . V_61 , sizeof( * V_64 ) , V_138 ) ;
if ( ! V_64 )
return - V_139 ;
V_58 . V_64 = V_64 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_42 ,
& V_58 , V_79 ) ;
if ( ! V_5 )
V_123 . V_75 = V_58 . V_60 ;
V_137:
if ( F_55 ( ( void V_89 * ) V_84 , & V_123 , V_85 ) )
V_5 = - V_90 ;
if ( ! V_5 ) {
if ( F_55 ( ( void V_89 * ) ( V_84 + V_85 ) , V_64 ,
V_123 . V_75 * sizeof( * V_64 ) ) )
V_5 = - V_90 ;
}
F_10 ( V_64 ) ;
return V_5 ;
} else if ( V_6 == V_140 ) {
struct V_141 V_123 ;
V_129 * V_142 ;
struct V_143 * V_76 ;
struct V_70 V_71 ;
bool V_79 = false ;
int V_74 , V_75 = 0 , V_5 = 0 ;
V_85 = F_53 ( struct V_141 , V_75 ) ;
if ( F_54 ( & V_123 , ( void V_89 * ) V_84 , V_85 ) )
return - V_90 ;
if ( V_123 . V_91 < V_85 || V_123 . V_17 )
return - V_77 ;
if ( ! F_64 ( V_2 -> V_4 -> V_79 ) )
V_79 = true ;
else if ( F_65 ( V_2 -> V_4 -> V_67 ) )
return - V_44 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_41 ,
& V_75 , V_79 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_123 . V_75 || V_123 . V_75 > V_75 )
return - V_77 ;
V_142 = F_67 ( V_123 . V_75 , sizeof( * V_142 ) , V_138 ) ;
V_76 = F_67 ( V_123 . V_75 , sizeof( * V_76 ) , V_138 ) ;
if ( ! V_142 || ! V_76 ) {
F_10 ( V_142 ) ;
F_10 ( V_76 ) ;
return - V_139 ;
}
if ( F_54 ( V_142 , ( void V_89 * ) ( V_84 + V_85 ) ,
V_123 . V_75 * sizeof( * V_142 ) ) ) {
F_10 ( V_142 ) ;
F_10 ( V_76 ) ;
return - V_90 ;
}
for ( V_74 = 0 ; V_74 < V_123 . V_75 ; V_74 ++ ) {
struct V_144 * V_72 ;
struct V_145 V_146 = F_68 ( V_142 [ V_74 ] ) ;
if ( ! V_146 . V_147 ) {
V_5 = - V_148 ;
break;
}
V_72 = F_69 ( V_146 . V_147 ) ;
F_70 ( V_146 ) ;
if ( F_62 ( V_72 ) ) {
V_5 = F_63 ( V_72 ) ;
break;
}
V_76 [ V_74 ] . V_72 = V_72 ;
V_76 [ V_74 ] . V_73 = F_71 ( V_72 ) ;
}
F_10 ( V_142 ) ;
if ( V_5 )
goto V_149;
V_71 . V_75 = V_123 . V_75 ;
V_71 . V_76 = V_76 ;
V_5 = F_50 ( V_2 -> V_4 ,
F_47 ,
& V_71 , V_79 ) ;
if ( ! V_5 )
V_5 = V_79 ? F_72 ( V_2 -> V_4 -> V_79 ) :
F_73 ( V_2 -> V_4 -> V_67 ) ;
V_149:
for ( V_74 -- ; V_74 >= 0 ; V_74 -- )
F_74 ( V_76 [ V_74 ] . V_72 ) ;
F_10 ( V_76 ) ;
return V_5 ;
}
return - V_150 ;
}
static T_6 F_75 ( void * V_40 , char V_89 * V_151 ,
T_5 V_75 , T_7 * V_152 , bool V_153 )
{
unsigned int V_100 = F_76 ( * V_152 ) ;
struct V_1 * V_2 = V_40 ;
if ( V_100 >= V_95 )
return - V_77 ;
switch ( V_100 ) {
case V_101 :
return F_77 ( V_2 , V_151 , V_75 , V_152 , V_153 ) ;
case V_112 :
if ( V_153 )
return - V_77 ;
return F_78 ( V_2 , V_151 , V_75 , V_152 , false ) ;
case V_106 ... V_107 :
return F_78 ( V_2 , V_151 , V_75 , V_152 , V_153 ) ;
case V_114 :
return F_79 ( V_2 , V_151 , V_75 , V_152 , V_153 ) ;
}
return - V_77 ;
}
static T_6 F_80 ( void * V_40 , char V_89 * V_151 ,
T_5 V_75 , T_7 * V_152 )
{
if ( ! V_75 )
return 0 ;
return F_75 ( V_40 , V_151 , V_75 , V_152 , false ) ;
}
static T_6 F_81 ( void * V_40 , const char V_89 * V_151 ,
T_5 V_75 , T_7 * V_152 )
{
if ( ! V_75 )
return 0 ;
return F_75 ( V_40 , ( char V_89 * ) V_151 , V_75 , V_152 , true ) ;
}
static int F_82 ( void * V_40 , struct V_154 * V_155 )
{
struct V_1 * V_2 = V_40 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_100 ;
T_8 V_156 , V_157 , V_158 , V_159 ;
int V_5 ;
V_100 = V_155 -> V_160 >> ( V_161 - V_162 ) ;
if ( V_155 -> V_163 < V_155 -> V_164 )
return - V_77 ;
if ( ( V_155 -> V_165 & V_166 ) == 0 )
return - V_77 ;
if ( V_100 >= V_112 )
return - V_77 ;
if ( ! ( F_58 ( V_4 , V_100 ) & V_109 ) )
return - V_77 ;
V_156 = F_57 ( V_4 , V_100 ) ;
V_157 = V_155 -> V_163 - V_155 -> V_164 ;
V_158 = V_155 -> V_160 &
( ( 1U << ( V_161 - V_162 ) ) - 1 ) ;
V_159 = V_158 << V_162 ;
if ( V_156 < V_110 || V_159 + V_157 > V_156 )
return - V_77 ;
if ( V_100 == V_2 -> V_21 ) {
if ( ! ( V_159 >= V_2 -> V_23 + V_2 -> V_25 ||
V_159 + V_157 <= V_2 -> V_23 ) )
return - V_77 ;
}
if ( ! V_2 -> V_37 [ V_100 ] ) {
V_5 = F_83 ( V_4 ,
1 << V_100 , L_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_37 [ V_100 ] = F_84 ( V_4 , V_100 , 0 ) ;
}
V_155 -> V_167 = V_2 ;
V_155 -> V_168 = F_85 ( V_155 -> V_168 ) ;
V_155 -> V_160 = ( F_86 ( V_4 , V_100 ) >> V_162 ) + V_158 ;
return F_87 ( V_155 , V_155 -> V_164 , V_155 -> V_160 ,
V_157 , V_155 -> V_168 ) ;
}
static int F_88 ( struct V_3 * V_4 , const struct V_169 * V_73 )
{
struct V_1 * V_2 ;
struct V_59 * V_72 ;
int V_5 ;
if ( V_4 -> V_170 != V_171 )
return - V_77 ;
V_72 = F_43 ( & V_4 -> V_11 ) ;
if ( ! V_72 )
return - V_77 ;
V_2 = F_89 ( sizeof( * V_2 ) , V_138 ) ;
if ( ! V_2 ) {
F_46 ( V_72 ) ;
return - V_139 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_96 ;
F_90 ( & V_2 -> V_131 ) ;
F_91 ( & V_2 -> V_172 ) ;
V_5 = F_92 ( & V_4 -> V_11 , & V_173 , V_2 ) ;
if ( V_5 ) {
F_46 ( V_72 ) ;
F_10 ( V_2 ) ;
}
return V_5 ;
}
static void F_93 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_94 ( & V_4 -> V_11 ) ;
if ( V_2 ) {
F_46 ( V_4 -> V_11 . V_59 ) ;
F_10 ( V_2 ) ;
}
}
static T_9 F_95 ( struct V_3 * V_4 ,
T_10 V_174 )
{
struct V_1 * V_2 ;
struct V_175 * V_176 ;
V_176 = F_96 ( & V_4 -> V_11 ) ;
if ( V_176 == NULL )
return V_177 ;
V_2 = F_97 ( V_176 ) ;
if ( V_2 == NULL ) {
F_98 ( V_176 ) ;
return V_177 ;
}
F_30 ( & V_2 -> V_131 ) ;
if ( V_2 -> V_178 )
F_99 ( V_2 -> V_178 , 1 ) ;
F_32 ( & V_2 -> V_131 ) ;
F_98 ( V_176 ) ;
return V_179 ;
}
static int F_100 ( struct V_3 * V_4 , void * V_56 )
{
struct V_180 * V_181 = V_56 ;
struct V_182 * V_183 = F_101 ( V_4 -> V_184 ) ;
if ( V_183 != & V_185 )
return - V_186 ;
if ( V_181 -> V_187 == V_181 -> V_188 )
return - V_136 ;
V_181 -> V_64 [ V_181 -> V_187 ] = F_96 ( & V_4 -> V_11 ) ;
if ( ! V_181 -> V_64 [ V_181 -> V_187 ] )
return - V_77 ;
V_181 -> V_187 ++ ;
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
struct V_180 V_181 = { . V_187 = 0 } ;
int V_74 = 0 , V_5 = - V_77 ;
bool V_38 = false , V_79 = false ;
struct V_1 * V_189 ;
if ( ! F_64 ( V_2 -> V_4 -> V_79 ) )
V_79 = true ;
else if ( F_65 ( V_2 -> V_4 -> V_67 ) )
return;
if ( F_50 ( V_2 -> V_4 , F_41 ,
& V_74 , V_79 ) || ! V_74 )
return;
V_181 . V_188 = V_74 ;
V_181 . V_64 = F_67 ( V_74 , sizeof( struct V_175 * ) , V_138 ) ;
if ( ! V_181 . V_64 )
return;
if ( F_50 ( V_2 -> V_4 ,
F_100 , & V_181 , V_79 ) )
goto V_190;
for ( V_74 = 0 ; V_74 < V_181 . V_187 ; V_74 ++ ) {
V_189 = F_97 ( V_181 . V_64 [ V_74 ] ) ;
if ( V_189 -> V_38 )
V_38 = true ;
if ( V_189 -> V_42 )
goto V_190;
}
if ( V_38 )
V_5 = V_79 ? F_72 ( V_2 -> V_4 -> V_79 ) :
F_73 ( V_2 -> V_4 -> V_67 ) ;
V_190:
for ( V_74 = 0 ; V_74 < V_181 . V_187 ; V_74 ++ ) {
if ( ! V_5 ) {
V_189 = F_97 ( V_181 . V_64 [ V_74 ] ) ;
V_189 -> V_38 = false ;
}
F_98 ( V_181 . V_64 [ V_74 ] ) ;
}
F_10 ( V_181 . V_64 ) ;
}
static void T_11 F_102 ( void )
{
F_103 ( & V_185 ) ;
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
goto V_191;
V_5 = F_109 ( & V_185 ) ;
if ( V_5 )
goto V_192;
return 0 ;
V_192:
F_104 () ;
V_191:
F_105 () ;
return V_5 ;
}
