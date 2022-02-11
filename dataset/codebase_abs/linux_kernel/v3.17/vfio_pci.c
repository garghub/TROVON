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
if ( V_46 )
return 1 ;
} else if ( V_33 == V_48 ) {
T_2 V_49 ;
T_1 V_17 ;
V_49 = V_2 -> V_4 -> V_50 ;
if ( V_49 ) {
F_14 ( V_2 -> V_4 ,
V_49 + V_51 , & V_17 ) ;
return 1 << ( ( V_17 & V_52 ) >> 1 ) ;
}
} else if ( V_33 == V_53 ) {
T_2 V_49 ;
T_1 V_17 ;
V_49 = V_2 -> V_4 -> V_16 ;
if ( V_49 ) {
F_14 ( V_2 -> V_4 ,
V_49 + V_19 , & V_17 ) ;
return ( V_17 & V_26 ) + 1 ;
}
} else if ( V_33 == V_54 )
if ( F_39 ( V_2 -> V_4 ) )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_3 * V_4 , void * V_55 )
{
( * ( int * ) V_55 ) ++ ;
return 0 ;
}
static int F_41 ( struct V_3 * V_4 , void * V_55 )
{
struct V_56 * V_57 = V_55 ;
struct V_58 * V_58 ;
if ( V_57 -> V_59 == V_57 -> V_60 )
return - V_61 ;
V_58 = F_42 ( & V_4 -> V_11 ) ;
if ( ! V_58 )
return - V_62 ;
V_57 -> V_63 [ V_57 -> V_59 ] . V_64 = F_43 ( V_58 ) ;
V_57 -> V_63 [ V_57 -> V_59 ] . V_65 = F_44 ( V_4 -> V_66 ) ;
V_57 -> V_63 [ V_57 -> V_59 ] . V_66 = V_4 -> V_66 -> V_67 ;
V_57 -> V_63 [ V_57 -> V_59 ] . V_68 = V_4 -> V_68 ;
V_57 -> V_59 ++ ;
F_45 ( V_58 ) ;
return 0 ;
}
static int F_46 ( struct V_3 * V_4 , void * V_55 )
{
struct V_69 * V_70 = V_55 ;
struct V_58 * V_71 ;
int V_72 , V_73 ;
V_71 = F_42 ( & V_4 -> V_11 ) ;
if ( ! V_71 )
return - V_62 ;
V_72 = F_43 ( V_71 ) ;
for ( V_73 = 0 ; V_73 < V_70 -> V_74 ; V_73 ++ )
if ( V_70 -> V_75 [ V_73 ] . V_72 == V_72 )
break;
F_45 ( V_71 ) ;
return ( V_73 == V_70 -> V_74 ) ? - V_76 : 0 ;
}
static bool F_47 ( struct V_3 * V_4 , struct V_77 * V_78 )
{
for (; V_4 ; V_4 = V_4 -> V_66 -> V_79 )
if ( V_4 -> V_66 == V_78 -> V_66 )
return ( V_4 -> V_78 == V_78 ) ;
return false ;
}
static int F_48 ( struct V_3 * V_4 , void * V_55 )
{
struct V_80 * V_81 = V_55 ;
if ( ! V_81 -> V_78 || F_47 ( V_4 , V_81 -> V_4 -> V_78 ) )
V_81 -> V_5 = V_81 -> V_82 ( V_4 , V_81 -> V_55 ) ;
return V_81 -> V_5 ;
}
static int F_49 ( struct V_3 * V_4 ,
int (* V_82)( struct V_3 * ,
void * V_55 ) , void * V_55 ,
bool V_78 )
{
struct V_80 V_81 = {
. V_82 = V_82 , . V_55 = V_55 , . V_4 = V_4 , . V_78 = V_78 , . V_5 = 0 ,
} ;
F_50 ( V_4 -> V_66 , F_48 , & V_81 ) ;
return V_81 . V_5 ;
}
static long F_51 ( void * V_40 ,
unsigned int V_6 , unsigned long V_83 )
{
struct V_1 * V_2 = V_40 ;
unsigned long V_84 ;
if ( V_6 == V_85 ) {
struct V_86 V_70 ;
V_84 = F_52 ( struct V_86 , V_87 ) ;
if ( F_53 ( & V_70 , ( void V_88 * ) V_83 , V_84 ) )
return - V_89 ;
if ( V_70 . V_90 < V_84 )
return - V_76 ;
V_70 . V_17 = V_91 ;
if ( V_2 -> V_8 )
V_70 . V_17 |= V_92 ;
V_70 . V_93 = V_94 ;
V_70 . V_87 = V_95 ;
return F_54 ( ( void V_88 * ) V_83 , & V_70 , V_84 ) ;
} else if ( V_6 == V_96 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_97 V_70 ;
V_84 = F_52 ( struct V_97 , V_98 ) ;
if ( F_53 ( & V_70 , ( void V_88 * ) V_83 , V_84 ) )
return - V_89 ;
if ( V_70 . V_90 < V_84 )
return - V_76 ;
switch ( V_70 . V_99 ) {
case V_100 :
V_70 . V_98 = F_55 ( V_70 . V_99 ) ;
V_70 . V_101 = V_4 -> V_102 ;
V_70 . V_17 = V_103 |
V_104 ;
break;
case V_105 ... V_106 :
V_70 . V_98 = F_55 ( V_70 . V_99 ) ;
V_70 . V_101 = F_56 ( V_4 , V_70 . V_99 ) ;
if ( ! V_70 . V_101 ) {
V_70 . V_17 = 0 ;
break;
}
V_70 . V_17 = V_103 |
V_104 ;
if ( F_57 ( V_4 , V_70 . V_99 ) &
V_107 && V_70 . V_101 >= V_108 )
V_70 . V_17 |= V_109 ;
break;
case V_110 :
{
void T_4 * V_111 ;
T_5 V_101 ;
V_70 . V_98 = F_55 ( V_70 . V_99 ) ;
V_70 . V_17 = 0 ;
V_70 . V_101 = F_56 ( V_4 , V_70 . V_99 ) ;
if ( ! V_70 . V_101 )
break;
V_111 = F_58 ( V_4 , & V_101 ) ;
if ( ! V_111 || ! V_101 ) {
V_70 . V_101 = 0 ;
break;
}
F_59 ( V_4 , V_111 ) ;
V_70 . V_17 = V_103 ;
break;
}
case V_112 :
if ( ! V_2 -> V_29 )
return - V_76 ;
V_70 . V_98 = F_55 ( V_70 . V_99 ) ;
V_70 . V_101 = 0xc0000 ;
V_70 . V_17 = V_103 |
V_104 ;
break;
default:
return - V_76 ;
}
return F_54 ( ( void V_88 * ) V_83 , & V_70 , V_84 ) ;
} else if ( V_6 == V_113 ) {
struct V_114 V_70 ;
V_84 = F_52 ( struct V_114 , V_74 ) ;
if ( F_53 ( & V_70 , ( void V_88 * ) V_83 , V_84 ) )
return - V_89 ;
if ( V_70 . V_90 < V_84 || V_70 . V_99 >= V_95 )
return - V_76 ;
switch ( V_70 . V_99 ) {
case V_45 ... V_53 :
break;
case V_54 :
if ( F_39 ( V_2 -> V_4 ) )
break;
default:
return - V_76 ;
}
V_70 . V_17 = V_115 ;
V_70 . V_74 = F_37 ( V_2 , V_70 . V_99 ) ;
if ( V_70 . V_99 == V_45 )
V_70 . V_17 |= ( V_116 |
V_117 ) ;
else
V_70 . V_17 |= V_118 ;
return F_54 ( ( void V_88 * ) V_83 , & V_70 , V_84 ) ;
} else if ( V_6 == V_119 ) {
struct V_120 V_121 ;
T_2 * V_55 = NULL ;
int V_5 = 0 ;
V_84 = F_52 ( struct V_120 , V_74 ) ;
if ( F_53 ( & V_121 , ( void V_88 * ) V_83 , V_84 ) )
return - V_89 ;
if ( V_121 . V_90 < V_84 || V_121 . V_99 >= V_95 ||
V_121 . V_17 & ~ ( V_122 |
V_123 ) )
return - V_76 ;
if ( ! ( V_121 . V_17 & V_31 ) ) {
T_5 V_101 ;
int V_60 = F_37 ( V_2 , V_121 . V_99 ) ;
if ( V_121 . V_17 & V_124 )
V_101 = sizeof( V_125 ) ;
else if ( V_121 . V_17 & V_126 )
V_101 = sizeof( V_127 ) ;
else
return - V_76 ;
if ( V_121 . V_90 - V_84 < V_121 . V_74 * V_101 ||
V_121 . V_128 >= V_60 || V_121 . V_128 + V_121 . V_74 > V_60 )
return - V_76 ;
V_55 = F_60 ( ( void V_88 * ) ( V_83 + V_84 ) ,
V_121 . V_74 * V_101 ) ;
if ( F_61 ( V_55 ) )
return F_62 ( V_55 ) ;
}
F_30 ( & V_2 -> V_129 ) ;
V_5 = F_19 ( V_2 , V_121 . V_17 , V_121 . V_99 ,
V_121 . V_128 , V_121 . V_74 , V_55 ) ;
F_32 ( & V_2 -> V_129 ) ;
F_10 ( V_55 ) ;
return V_5 ;
} else if ( V_6 == V_130 ) {
return V_2 -> V_8 ?
F_25 ( V_2 -> V_4 ) : - V_76 ;
} else if ( V_6 == V_131 ) {
struct V_132 V_121 ;
struct V_56 V_57 = { 0 } ;
struct V_133 * V_63 = NULL ;
bool V_78 = false ;
int V_5 = 0 ;
V_84 = F_52 ( struct V_132 , V_74 ) ;
if ( F_53 ( & V_121 , ( void V_88 * ) V_83 , V_84 ) )
return - V_89 ;
if ( V_121 . V_90 < V_84 )
return - V_76 ;
V_121 . V_17 = 0 ;
if ( ! F_63 ( V_2 -> V_4 -> V_78 ) )
V_78 = true ;
else if ( F_64 ( V_2 -> V_4 -> V_66 ) )
return - V_44 ;
V_5 = F_49 ( V_2 -> V_4 ,
F_40 ,
& V_57 . V_60 , V_78 ) ;
if ( V_5 )
return V_5 ;
F_65 ( ! V_57 . V_60 ) ;
if ( V_121 . V_90 < sizeof( V_121 ) + ( V_57 . V_60 * sizeof( * V_63 ) ) ) {
V_5 = - V_134 ;
V_121 . V_74 = V_57 . V_60 ;
goto V_135;
}
V_63 = F_66 ( V_57 . V_60 , sizeof( * V_63 ) , V_136 ) ;
if ( ! V_63 )
return - V_137 ;
V_57 . V_63 = V_63 ;
V_5 = F_49 ( V_2 -> V_4 ,
F_41 ,
& V_57 , V_78 ) ;
if ( ! V_5 )
V_121 . V_74 = V_57 . V_59 ;
V_135:
if ( F_54 ( ( void V_88 * ) V_83 , & V_121 , V_84 ) )
V_5 = - V_89 ;
if ( ! V_5 ) {
if ( F_54 ( ( void V_88 * ) ( V_83 + V_84 ) , V_63 ,
V_121 . V_74 * sizeof( * V_63 ) ) )
V_5 = - V_89 ;
}
F_10 ( V_63 ) ;
return V_5 ;
} else if ( V_6 == V_138 ) {
struct V_139 V_121 ;
V_127 * V_140 ;
struct V_141 * V_75 ;
struct V_69 V_70 ;
bool V_78 = false ;
int V_73 , V_74 = 0 , V_5 = 0 ;
V_84 = F_52 ( struct V_139 , V_74 ) ;
if ( F_53 ( & V_121 , ( void V_88 * ) V_83 , V_84 ) )
return - V_89 ;
if ( V_121 . V_90 < V_84 || V_121 . V_17 )
return - V_76 ;
if ( ! F_63 ( V_2 -> V_4 -> V_78 ) )
V_78 = true ;
else if ( F_64 ( V_2 -> V_4 -> V_66 ) )
return - V_44 ;
V_5 = F_49 ( V_2 -> V_4 ,
F_40 ,
& V_74 , V_78 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_121 . V_74 || V_121 . V_74 > V_74 )
return - V_76 ;
V_140 = F_66 ( V_121 . V_74 , sizeof( * V_140 ) , V_136 ) ;
V_75 = F_66 ( V_121 . V_74 , sizeof( * V_75 ) , V_136 ) ;
if ( ! V_140 || ! V_75 ) {
F_10 ( V_140 ) ;
F_10 ( V_75 ) ;
return - V_137 ;
}
if ( F_53 ( V_140 , ( void V_88 * ) ( V_83 + V_84 ) ,
V_121 . V_74 * sizeof( * V_140 ) ) ) {
F_10 ( V_140 ) ;
F_10 ( V_75 ) ;
return - V_89 ;
}
for ( V_73 = 0 ; V_73 < V_121 . V_74 ; V_73 ++ ) {
struct V_142 * V_71 ;
struct V_143 V_144 = F_67 ( V_140 [ V_73 ] ) ;
if ( ! V_144 . V_145 ) {
V_5 = - V_146 ;
break;
}
V_71 = F_68 ( V_144 . V_145 ) ;
F_69 ( V_144 ) ;
if ( F_61 ( V_71 ) ) {
V_5 = F_62 ( V_71 ) ;
break;
}
V_75 [ V_73 ] . V_71 = V_71 ;
V_75 [ V_73 ] . V_72 = F_70 ( V_71 ) ;
}
F_10 ( V_140 ) ;
if ( V_5 )
goto V_147;
V_70 . V_74 = V_121 . V_74 ;
V_70 . V_75 = V_75 ;
V_5 = F_49 ( V_2 -> V_4 ,
F_46 ,
& V_70 , V_78 ) ;
if ( ! V_5 )
V_5 = V_78 ? F_71 ( V_2 -> V_4 -> V_78 ) :
F_72 ( V_2 -> V_4 -> V_66 ) ;
V_147:
for ( V_73 -- ; V_73 >= 0 ; V_73 -- )
F_73 ( V_75 [ V_73 ] . V_71 ) ;
F_10 ( V_75 ) ;
return V_5 ;
}
return - V_148 ;
}
static T_6 F_74 ( void * V_40 , char V_88 * V_149 ,
T_5 V_74 , T_7 * V_150 , bool V_151 )
{
unsigned int V_99 = F_75 ( * V_150 ) ;
struct V_1 * V_2 = V_40 ;
if ( V_99 >= V_94 )
return - V_76 ;
switch ( V_99 ) {
case V_100 :
return F_76 ( V_2 , V_149 , V_74 , V_150 , V_151 ) ;
case V_110 :
if ( V_151 )
return - V_76 ;
return F_77 ( V_2 , V_149 , V_74 , V_150 , false ) ;
case V_105 ... V_106 :
return F_77 ( V_2 , V_149 , V_74 , V_150 , V_151 ) ;
case V_112 :
return F_78 ( V_2 , V_149 , V_74 , V_150 , V_151 ) ;
}
return - V_76 ;
}
static T_6 F_79 ( void * V_40 , char V_88 * V_149 ,
T_5 V_74 , T_7 * V_150 )
{
if ( ! V_74 )
return 0 ;
return F_74 ( V_40 , V_149 , V_74 , V_150 , false ) ;
}
static T_6 F_80 ( void * V_40 , const char V_88 * V_149 ,
T_5 V_74 , T_7 * V_150 )
{
if ( ! V_74 )
return 0 ;
return F_74 ( V_40 , ( char V_88 * ) V_149 , V_74 , V_150 , true ) ;
}
static int F_81 ( void * V_40 , struct V_152 * V_153 )
{
struct V_1 * V_2 = V_40 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_99 ;
T_8 V_154 , V_155 , V_156 , V_157 ;
int V_5 ;
V_99 = V_153 -> V_158 >> ( V_159 - V_160 ) ;
if ( V_153 -> V_161 < V_153 -> V_162 )
return - V_76 ;
if ( ( V_153 -> V_163 & V_164 ) == 0 )
return - V_76 ;
if ( V_99 >= V_110 )
return - V_76 ;
if ( ! ( F_57 ( V_4 , V_99 ) & V_107 ) )
return - V_76 ;
V_154 = F_56 ( V_4 , V_99 ) ;
V_155 = V_153 -> V_161 - V_153 -> V_162 ;
V_156 = V_153 -> V_158 &
( ( 1U << ( V_159 - V_160 ) ) - 1 ) ;
V_157 = V_156 << V_160 ;
if ( V_154 < V_108 || V_157 + V_155 > V_154 )
return - V_76 ;
if ( V_99 == V_2 -> V_21 ) {
if ( ! ( V_157 >= V_2 -> V_23 + V_2 -> V_25 ||
V_157 + V_155 <= V_2 -> V_23 ) )
return - V_76 ;
}
if ( ! V_2 -> V_37 [ V_99 ] ) {
V_5 = F_82 ( V_4 ,
1 << V_99 , L_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_37 [ V_99 ] = F_83 ( V_4 , V_99 , 0 ) ;
}
V_153 -> V_165 = V_2 ;
V_153 -> V_166 = F_84 ( V_153 -> V_166 ) ;
V_153 -> V_158 = ( F_85 ( V_4 , V_99 ) >> V_160 ) + V_156 ;
return F_86 ( V_153 , V_153 -> V_162 , V_153 -> V_158 ,
V_155 , V_153 -> V_166 ) ;
}
static int F_87 ( struct V_3 * V_4 , const struct V_167 * V_72 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_58 * V_71 ;
int V_5 ;
F_38 ( V_4 , V_168 , & type ) ;
if ( ( type & V_168 ) != V_169 )
return - V_76 ;
V_71 = F_42 ( & V_4 -> V_11 ) ;
if ( ! V_71 )
return - V_76 ;
V_2 = F_88 ( sizeof( * V_2 ) , V_136 ) ;
if ( ! V_2 ) {
F_45 ( V_71 ) ;
return - V_137 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_95 ;
F_89 ( & V_2 -> V_129 ) ;
F_90 ( & V_2 -> V_170 ) ;
V_5 = F_91 ( & V_4 -> V_11 , & V_171 , V_2 ) ;
if ( V_5 ) {
F_45 ( V_71 ) ;
F_10 ( V_2 ) ;
}
return V_5 ;
}
static void F_92 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
F_30 ( & V_41 ) ;
V_2 = F_93 ( & V_4 -> V_11 ) ;
if ( V_2 ) {
F_45 ( V_4 -> V_11 . V_58 ) ;
F_10 ( V_2 ) ;
}
F_32 ( & V_41 ) ;
}
static T_9 F_94 ( struct V_3 * V_4 ,
T_10 V_172 )
{
struct V_1 * V_2 ;
struct V_173 * V_174 ;
V_174 = F_95 ( & V_4 -> V_11 ) ;
if ( V_174 == NULL )
return V_175 ;
V_2 = F_96 ( V_174 ) ;
if ( V_2 == NULL ) {
F_97 ( V_174 ) ;
return V_175 ;
}
F_30 ( & V_2 -> V_129 ) ;
if ( V_2 -> V_176 )
F_98 ( V_2 -> V_176 , 1 ) ;
F_32 ( & V_2 -> V_129 ) ;
F_97 ( V_174 ) ;
return V_177 ;
}
static int F_99 ( struct V_3 * V_4 , void * V_55 )
{
bool * V_38 = V_55 ;
struct V_178 * V_179 = F_100 ( V_4 -> V_180 ) ;
int V_5 = - V_181 ;
if ( V_179 == & V_182 ) {
struct V_173 * V_174 ;
struct V_1 * V_2 ;
V_174 = F_95 ( & V_4 -> V_11 ) ;
if ( ! V_174 )
return V_5 ;
V_2 = F_96 ( V_174 ) ;
if ( V_2 ) {
if ( V_2 -> V_38 )
* V_38 = true ;
if ( ! V_2 -> V_42 )
V_5 = 0 ;
}
F_97 ( V_174 ) ;
}
return V_5 ;
}
static int F_101 ( struct V_3 * V_4 , void * V_55 )
{
struct V_178 * V_179 = F_100 ( V_4 -> V_180 ) ;
if ( V_179 == & V_182 ) {
struct V_173 * V_174 ;
struct V_1 * V_2 ;
V_174 = F_95 ( & V_4 -> V_11 ) ;
if ( ! V_174 )
return 0 ;
V_2 = F_96 ( V_174 ) ;
if ( V_2 )
V_2 -> V_38 = false ;
F_97 ( V_174 ) ;
}
return 0 ;
}
static void F_28 ( struct V_1 * V_2 )
{
bool V_38 = false , V_78 = false ;
int V_5 ;
if ( ! F_63 ( V_2 -> V_4 -> V_78 ) )
V_78 = true ;
else if ( F_64 ( V_2 -> V_4 -> V_66 ) )
return;
if ( F_49 ( V_2 -> V_4 ,
F_99 ,
& V_38 , V_78 ) || ! V_38 )
return;
if ( V_78 )
V_5 = F_71 ( V_2 -> V_4 -> V_78 ) ;
else
V_5 = F_72 ( V_2 -> V_4 -> V_66 ) ;
if ( V_5 )
return;
F_49 ( V_2 -> V_4 ,
F_101 , NULL , V_78 ) ;
}
static void T_11 F_102 ( void )
{
F_103 ( & V_182 ) ;
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
goto V_183;
V_5 = F_109 ( & V_182 ) ;
if ( V_5 )
goto V_184;
return 0 ;
V_184:
F_104 () ;
V_183:
F_105 () ;
return V_5 ;
}
