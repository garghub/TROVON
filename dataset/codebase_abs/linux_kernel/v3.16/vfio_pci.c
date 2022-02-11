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
F_9 ( V_2 -> V_9 ) ;
V_2 -> V_9 = NULL ;
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
if ( F_22 ( V_4 , & V_2 -> V_9 ) ) {
F_23 ( L_2 ,
V_10 , F_7 ( & V_4 -> V_11 ) ) ;
if ( ! V_2 -> V_8 )
return;
F_4 ( V_4 ) ;
}
F_14 ( V_4 , V_14 , V_15 ) ;
if ( V_2 -> V_8 ) {
int V_5 = F_24 ( V_4 ) ;
if ( V_5 )
F_25 ( L_3 ,
V_10 , F_7 ( & V_4 -> V_11 ) , V_5 ) ;
}
F_26 ( V_4 ) ;
}
static void F_27 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
if ( F_28 ( & V_2 -> V_39 ) )
F_17 ( V_2 ) ;
F_29 ( V_40 ) ;
}
static int F_30 ( void * V_38 )
{
struct V_1 * V_2 = V_38 ;
if ( ! F_31 ( V_40 ) )
return - V_41 ;
if ( F_32 ( & V_2 -> V_39 ) == 1 ) {
int V_5 = F_1 ( V_2 ) ;
if ( V_5 ) {
F_29 ( V_40 ) ;
return V_5 ;
}
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 , int V_33 )
{
if ( V_33 == V_42 ) {
T_2 V_43 ;
F_34 ( V_2 -> V_4 , V_44 , & V_43 ) ;
if ( V_43 )
return 1 ;
} else if ( V_33 == V_45 ) {
T_2 V_46 ;
T_1 V_17 ;
V_46 = V_2 -> V_4 -> V_47 ;
if ( V_46 ) {
F_13 ( V_2 -> V_4 ,
V_46 + V_48 , & V_17 ) ;
return 1 << ( ( V_17 & V_49 ) >> 1 ) ;
}
} else if ( V_33 == V_50 ) {
T_2 V_46 ;
T_1 V_17 ;
V_46 = V_2 -> V_4 -> V_16 ;
if ( V_46 ) {
F_13 ( V_2 -> V_4 ,
V_46 + V_19 , & V_17 ) ;
return ( V_17 & V_26 ) + 1 ;
}
} else if ( V_33 == V_51 )
if ( F_35 ( V_2 -> V_4 ) )
return 1 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 , void * V_52 )
{
( * ( int * ) V_52 ) ++ ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 , void * V_52 )
{
struct V_53 * V_54 = V_52 ;
struct V_55 * V_55 ;
if ( V_54 -> V_56 == V_54 -> V_57 )
return - V_58 ;
V_55 = F_38 ( & V_4 -> V_11 ) ;
if ( ! V_55 )
return - V_59 ;
V_54 -> V_60 [ V_54 -> V_56 ] . V_61 = F_39 ( V_55 ) ;
V_54 -> V_60 [ V_54 -> V_56 ] . V_62 = F_40 ( V_4 -> V_63 ) ;
V_54 -> V_60 [ V_54 -> V_56 ] . V_63 = V_4 -> V_63 -> V_64 ;
V_54 -> V_60 [ V_54 -> V_56 ] . V_65 = V_4 -> V_65 ;
V_54 -> V_56 ++ ;
F_41 ( V_55 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 , void * V_52 )
{
struct V_66 * V_67 = V_52 ;
struct V_55 * V_68 ;
int V_69 , V_70 ;
V_68 = F_38 ( & V_4 -> V_11 ) ;
if ( ! V_68 )
return - V_59 ;
V_69 = F_39 ( V_68 ) ;
for ( V_70 = 0 ; V_70 < V_67 -> V_71 ; V_70 ++ )
if ( V_67 -> V_72 [ V_70 ] . V_69 == V_69 )
break;
F_41 ( V_68 ) ;
return ( V_70 == V_67 -> V_71 ) ? - V_73 : 0 ;
}
static bool F_43 ( struct V_3 * V_4 , struct V_74 * V_75 )
{
for (; V_4 ; V_4 = V_4 -> V_63 -> V_76 )
if ( V_4 -> V_63 == V_75 -> V_63 )
return ( V_4 -> V_75 == V_75 ) ;
return false ;
}
static int F_44 ( struct V_3 * V_4 , void * V_52 )
{
struct V_77 * V_78 = V_52 ;
if ( ! V_78 -> V_75 || F_43 ( V_4 , V_78 -> V_4 -> V_75 ) )
V_78 -> V_5 = V_78 -> V_79 ( V_4 , V_78 -> V_52 ) ;
return V_78 -> V_5 ;
}
static int F_45 ( struct V_3 * V_4 ,
int (* V_79)( struct V_3 * ,
void * V_52 ) , void * V_52 ,
bool V_75 )
{
struct V_77 V_78 = {
. V_79 = V_79 , . V_52 = V_52 , . V_4 = V_4 , . V_75 = V_75 , . V_5 = 0 ,
} ;
F_46 ( V_4 -> V_63 , F_44 , & V_78 ) ;
return V_78 . V_5 ;
}
static long F_47 ( void * V_38 ,
unsigned int V_6 , unsigned long V_80 )
{
struct V_1 * V_2 = V_38 ;
unsigned long V_81 ;
if ( V_6 == V_82 ) {
struct V_83 V_67 ;
V_81 = F_48 ( struct V_83 , V_84 ) ;
if ( F_49 ( & V_67 , ( void V_85 * ) V_80 , V_81 ) )
return - V_86 ;
if ( V_67 . V_87 < V_81 )
return - V_73 ;
V_67 . V_17 = V_88 ;
if ( V_2 -> V_8 )
V_67 . V_17 |= V_89 ;
V_67 . V_90 = V_91 ;
V_67 . V_84 = V_92 ;
return F_50 ( ( void V_85 * ) V_80 , & V_67 , V_81 ) ;
} else if ( V_6 == V_93 ) {
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_94 V_67 ;
V_81 = F_48 ( struct V_94 , V_95 ) ;
if ( F_49 ( & V_67 , ( void V_85 * ) V_80 , V_81 ) )
return - V_86 ;
if ( V_67 . V_87 < V_81 )
return - V_73 ;
switch ( V_67 . V_96 ) {
case V_97 :
V_67 . V_95 = F_51 ( V_67 . V_96 ) ;
V_67 . V_98 = V_4 -> V_99 ;
V_67 . V_17 = V_100 |
V_101 ;
break;
case V_102 ... V_103 :
V_67 . V_95 = F_51 ( V_67 . V_96 ) ;
V_67 . V_98 = F_52 ( V_4 , V_67 . V_96 ) ;
if ( ! V_67 . V_98 ) {
V_67 . V_17 = 0 ;
break;
}
V_67 . V_17 = V_100 |
V_101 ;
if ( F_53 ( V_4 , V_67 . V_96 ) &
V_104 && V_67 . V_98 >= V_105 )
V_67 . V_17 |= V_106 ;
break;
case V_107 :
{
void T_4 * V_108 ;
T_5 V_98 ;
V_67 . V_95 = F_51 ( V_67 . V_96 ) ;
V_67 . V_17 = 0 ;
V_67 . V_98 = F_52 ( V_4 , V_67 . V_96 ) ;
if ( ! V_67 . V_98 )
break;
V_108 = F_54 ( V_4 , & V_98 ) ;
if ( ! V_108 || ! V_98 ) {
V_67 . V_98 = 0 ;
break;
}
F_55 ( V_4 , V_108 ) ;
V_67 . V_17 = V_100 ;
break;
}
case V_109 :
if ( ! V_2 -> V_29 )
return - V_73 ;
V_67 . V_95 = F_51 ( V_67 . V_96 ) ;
V_67 . V_98 = 0xc0000 ;
V_67 . V_17 = V_100 |
V_101 ;
break;
default:
return - V_73 ;
}
return F_50 ( ( void V_85 * ) V_80 , & V_67 , V_81 ) ;
} else if ( V_6 == V_110 ) {
struct V_111 V_67 ;
V_81 = F_48 ( struct V_111 , V_71 ) ;
if ( F_49 ( & V_67 , ( void V_85 * ) V_80 , V_81 ) )
return - V_86 ;
if ( V_67 . V_87 < V_81 || V_67 . V_96 >= V_92 )
return - V_73 ;
switch ( V_67 . V_96 ) {
case V_42 ... V_50 :
break;
case V_51 :
if ( F_35 ( V_2 -> V_4 ) )
break;
default:
return - V_73 ;
}
V_67 . V_17 = V_112 ;
V_67 . V_71 = F_33 ( V_2 , V_67 . V_96 ) ;
if ( V_67 . V_96 == V_42 )
V_67 . V_17 |= ( V_113 |
V_114 ) ;
else
V_67 . V_17 |= V_115 ;
return F_50 ( ( void V_85 * ) V_80 , & V_67 , V_81 ) ;
} else if ( V_6 == V_116 ) {
struct V_117 V_118 ;
T_2 * V_52 = NULL ;
int V_5 = 0 ;
V_81 = F_48 ( struct V_117 , V_71 ) ;
if ( F_49 ( & V_118 , ( void V_85 * ) V_80 , V_81 ) )
return - V_86 ;
if ( V_118 . V_87 < V_81 || V_118 . V_96 >= V_92 ||
V_118 . V_17 & ~ ( V_119 |
V_120 ) )
return - V_73 ;
if ( ! ( V_118 . V_17 & V_31 ) ) {
T_5 V_98 ;
int V_57 = F_33 ( V_2 , V_118 . V_96 ) ;
if ( V_118 . V_17 & V_121 )
V_98 = sizeof( V_122 ) ;
else if ( V_118 . V_17 & V_123 )
V_98 = sizeof( V_124 ) ;
else
return - V_73 ;
if ( V_118 . V_87 - V_81 < V_118 . V_71 * V_98 ||
V_118 . V_125 >= V_57 || V_118 . V_125 + V_118 . V_71 > V_57 )
return - V_73 ;
V_52 = F_56 ( ( void V_85 * ) ( V_80 + V_81 ) ,
V_118 . V_71 * V_98 ) ;
if ( F_57 ( V_52 ) )
return F_58 ( V_52 ) ;
}
F_59 ( & V_2 -> V_126 ) ;
V_5 = F_18 ( V_2 , V_118 . V_17 , V_118 . V_96 ,
V_118 . V_125 , V_118 . V_71 , V_52 ) ;
F_60 ( & V_2 -> V_126 ) ;
F_9 ( V_52 ) ;
return V_5 ;
} else if ( V_6 == V_127 ) {
return V_2 -> V_8 ?
F_24 ( V_2 -> V_4 ) : - V_73 ;
} else if ( V_6 == V_128 ) {
struct V_129 V_118 ;
struct V_53 V_54 = { 0 } ;
struct V_130 * V_60 = NULL ;
bool V_75 = false ;
int V_5 = 0 ;
V_81 = F_48 ( struct V_129 , V_71 ) ;
if ( F_49 ( & V_118 , ( void V_85 * ) V_80 , V_81 ) )
return - V_86 ;
if ( V_118 . V_87 < V_81 )
return - V_73 ;
V_118 . V_17 = 0 ;
if ( ! F_61 ( V_2 -> V_4 -> V_75 ) )
V_75 = true ;
else if ( F_62 ( V_2 -> V_4 -> V_63 ) )
return - V_41 ;
V_5 = F_45 ( V_2 -> V_4 ,
F_36 ,
& V_54 . V_57 , V_75 ) ;
if ( V_5 )
return V_5 ;
F_63 ( ! V_54 . V_57 ) ;
if ( V_118 . V_87 < sizeof( V_118 ) + ( V_54 . V_57 * sizeof( * V_60 ) ) ) {
V_5 = - V_131 ;
V_118 . V_71 = V_54 . V_57 ;
goto V_132;
}
V_60 = F_64 ( V_54 . V_57 , sizeof( * V_60 ) , V_133 ) ;
if ( ! V_60 )
return - V_134 ;
V_54 . V_60 = V_60 ;
V_5 = F_45 ( V_2 -> V_4 ,
F_37 ,
& V_54 , V_75 ) ;
if ( ! V_5 )
V_118 . V_71 = V_54 . V_56 ;
V_132:
if ( F_50 ( ( void V_85 * ) V_80 , & V_118 , V_81 ) )
V_5 = - V_86 ;
if ( ! V_5 ) {
if ( F_50 ( ( void V_85 * ) ( V_80 + V_81 ) , V_60 ,
V_118 . V_71 * sizeof( * V_60 ) ) )
V_5 = - V_86 ;
}
F_9 ( V_60 ) ;
return V_5 ;
} else if ( V_6 == V_135 ) {
struct V_136 V_118 ;
V_124 * V_137 ;
struct V_138 * V_72 ;
struct V_66 V_67 ;
bool V_75 = false ;
int V_70 , V_71 = 0 , V_5 = 0 ;
V_81 = F_48 ( struct V_136 , V_71 ) ;
if ( F_49 ( & V_118 , ( void V_85 * ) V_80 , V_81 ) )
return - V_86 ;
if ( V_118 . V_87 < V_81 || V_118 . V_17 )
return - V_73 ;
if ( ! F_61 ( V_2 -> V_4 -> V_75 ) )
V_75 = true ;
else if ( F_62 ( V_2 -> V_4 -> V_63 ) )
return - V_41 ;
V_5 = F_45 ( V_2 -> V_4 ,
F_36 ,
& V_71 , V_75 ) ;
if ( V_5 )
return V_5 ;
if ( ! V_118 . V_71 || V_118 . V_71 > V_71 )
return - V_73 ;
V_137 = F_64 ( V_118 . V_71 , sizeof( * V_137 ) , V_133 ) ;
V_72 = F_64 ( V_118 . V_71 , sizeof( * V_72 ) , V_133 ) ;
if ( ! V_137 || ! V_72 ) {
F_9 ( V_137 ) ;
F_9 ( V_72 ) ;
return - V_134 ;
}
if ( F_49 ( V_137 , ( void V_85 * ) ( V_80 + V_81 ) ,
V_118 . V_71 * sizeof( * V_137 ) ) ) {
F_9 ( V_137 ) ;
F_9 ( V_72 ) ;
return - V_86 ;
}
for ( V_70 = 0 ; V_70 < V_118 . V_71 ; V_70 ++ ) {
struct V_139 * V_68 ;
struct V_140 V_141 = F_65 ( V_137 [ V_70 ] ) ;
if ( ! V_141 . V_142 ) {
V_5 = - V_143 ;
break;
}
V_68 = F_66 ( V_141 . V_142 ) ;
F_67 ( V_141 ) ;
if ( F_57 ( V_68 ) ) {
V_5 = F_58 ( V_68 ) ;
break;
}
V_72 [ V_70 ] . V_68 = V_68 ;
V_72 [ V_70 ] . V_69 = F_68 ( V_68 ) ;
}
F_9 ( V_137 ) ;
if ( V_5 )
goto V_144;
V_67 . V_71 = V_118 . V_71 ;
V_67 . V_72 = V_72 ;
V_5 = F_45 ( V_2 -> V_4 ,
F_42 ,
& V_67 , V_75 ) ;
if ( ! V_5 )
V_5 = V_75 ? F_69 ( V_2 -> V_4 -> V_75 ) :
F_70 ( V_2 -> V_4 -> V_63 ) ;
V_144:
for ( V_70 -- ; V_70 >= 0 ; V_70 -- )
F_71 ( V_72 [ V_70 ] . V_68 ) ;
F_9 ( V_72 ) ;
return V_5 ;
}
return - V_145 ;
}
static T_6 F_72 ( void * V_38 , char V_85 * V_146 ,
T_5 V_71 , T_7 * V_147 , bool V_148 )
{
unsigned int V_96 = F_73 ( * V_147 ) ;
struct V_1 * V_2 = V_38 ;
if ( V_96 >= V_91 )
return - V_73 ;
switch ( V_96 ) {
case V_97 :
return F_74 ( V_2 , V_146 , V_71 , V_147 , V_148 ) ;
case V_107 :
if ( V_148 )
return - V_73 ;
return F_75 ( V_2 , V_146 , V_71 , V_147 , false ) ;
case V_102 ... V_103 :
return F_75 ( V_2 , V_146 , V_71 , V_147 , V_148 ) ;
case V_109 :
return F_76 ( V_2 , V_146 , V_71 , V_147 , V_148 ) ;
}
return - V_73 ;
}
static T_6 F_77 ( void * V_38 , char V_85 * V_146 ,
T_5 V_71 , T_7 * V_147 )
{
if ( ! V_71 )
return 0 ;
return F_72 ( V_38 , V_146 , V_71 , V_147 , false ) ;
}
static T_6 F_78 ( void * V_38 , const char V_85 * V_146 ,
T_5 V_71 , T_7 * V_147 )
{
if ( ! V_71 )
return 0 ;
return F_72 ( V_38 , ( char V_85 * ) V_146 , V_71 , V_147 , true ) ;
}
static int F_79 ( void * V_38 , struct V_149 * V_150 )
{
struct V_1 * V_2 = V_38 ;
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_96 ;
T_8 V_151 , V_152 , V_153 , V_154 ;
int V_5 ;
V_96 = V_150 -> V_155 >> ( V_156 - V_157 ) ;
if ( V_150 -> V_158 < V_150 -> V_159 )
return - V_73 ;
if ( ( V_150 -> V_160 & V_161 ) == 0 )
return - V_73 ;
if ( V_96 >= V_107 )
return - V_73 ;
if ( ! ( F_53 ( V_4 , V_96 ) & V_104 ) )
return - V_73 ;
V_151 = F_52 ( V_4 , V_96 ) ;
V_152 = V_150 -> V_158 - V_150 -> V_159 ;
V_153 = V_150 -> V_155 &
( ( 1U << ( V_156 - V_157 ) ) - 1 ) ;
V_154 = V_153 << V_157 ;
if ( V_151 < V_105 || V_154 + V_152 > V_151 )
return - V_73 ;
if ( V_96 == V_2 -> V_21 ) {
if ( ! ( V_154 >= V_2 -> V_23 + V_2 -> V_25 ||
V_154 + V_152 <= V_2 -> V_23 ) )
return - V_73 ;
}
if ( ! V_2 -> V_37 [ V_96 ] ) {
V_5 = F_80 ( V_4 ,
1 << V_96 , L_4 ) ;
if ( V_5 )
return V_5 ;
V_2 -> V_37 [ V_96 ] = F_81 ( V_4 , V_96 , 0 ) ;
}
V_150 -> V_162 = V_2 ;
V_150 -> V_163 = F_82 ( V_150 -> V_163 ) ;
V_150 -> V_155 = ( F_83 ( V_4 , V_96 ) >> V_157 ) + V_153 ;
return F_84 ( V_150 , V_150 -> V_159 , V_150 -> V_155 ,
V_152 , V_150 -> V_163 ) ;
}
static int F_85 ( struct V_3 * V_4 , const struct V_164 * V_69 )
{
T_2 type ;
struct V_1 * V_2 ;
struct V_55 * V_68 ;
int V_5 ;
F_34 ( V_4 , V_165 , & type ) ;
if ( ( type & V_165 ) != V_166 )
return - V_73 ;
V_68 = F_38 ( & V_4 -> V_11 ) ;
if ( ! V_68 )
return - V_73 ;
V_2 = F_86 ( sizeof( * V_2 ) , V_133 ) ;
if ( ! V_2 ) {
F_41 ( V_68 ) ;
return - V_134 ;
}
V_2 -> V_4 = V_4 ;
V_2 -> V_33 = V_92 ;
F_87 ( & V_2 -> V_126 ) ;
F_88 ( & V_2 -> V_167 ) ;
F_89 ( & V_2 -> V_39 , 0 ) ;
V_5 = F_90 ( & V_4 -> V_11 , & V_168 , V_2 ) ;
if ( V_5 ) {
F_41 ( V_68 ) ;
F_9 ( V_2 ) ;
}
return V_5 ;
}
static void F_91 ( struct V_3 * V_4 )
{
struct V_1 * V_2 ;
V_2 = F_92 ( & V_4 -> V_11 ) ;
if ( ! V_2 )
return;
F_41 ( V_4 -> V_11 . V_55 ) ;
F_9 ( V_2 ) ;
}
static T_9 F_93 ( struct V_3 * V_4 ,
T_10 V_169 )
{
struct V_1 * V_2 ;
struct V_170 * V_171 ;
V_171 = F_94 ( & V_4 -> V_11 ) ;
if ( V_171 == NULL )
return V_172 ;
V_2 = F_95 ( V_171 ) ;
if ( V_2 == NULL ) {
F_96 ( V_171 ) ;
return V_172 ;
}
F_59 ( & V_2 -> V_126 ) ;
if ( V_2 -> V_173 )
F_97 ( V_2 -> V_173 , 1 ) ;
F_60 ( & V_2 -> V_126 ) ;
F_96 ( V_171 ) ;
return V_174 ;
}
static void T_11 F_98 ( void )
{
F_99 ( & V_175 ) ;
F_100 () ;
F_101 () ;
}
static int T_12 F_102 ( void )
{
int V_5 ;
V_5 = F_103 () ;
if ( V_5 )
return V_5 ;
V_5 = F_104 () ;
if ( V_5 )
goto V_176;
V_5 = F_105 ( & V_175 ) ;
if ( V_5 )
goto V_177;
return 0 ;
V_177:
F_100 () ;
V_176:
F_101 () ;
return V_5 ;
}
