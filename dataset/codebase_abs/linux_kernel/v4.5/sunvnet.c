static inline T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_4 * V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
F_4 ( L_1 ,
V_8 -> type , V_8 -> V_9 , V_8 -> V_10 , V_8 -> V_11 ) ;
F_4 ( L_2 ) ;
F_5 ( V_5 -> V_12 . V_13 ) ;
return - V_14 ;
}
static int F_6 ( struct V_15 * V_12 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
struct V_19 V_8 ;
int V_20 = V_21 ;
int V_22 , V_23 ;
V_23 = F_8 ( F_7 ( V_12 ) ) ;
if ( V_23 )
return V_23 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_24 . type = V_25 ;
V_8 . V_24 . V_9 = V_26 ;
V_8 . V_24 . V_10 = V_27 ;
V_8 . V_24 . V_11 = F_9 ( V_12 ) ;
if ( F_10 ( V_12 , 1 , 2 ) )
V_8 . V_28 = V_29 ;
else
V_8 . V_28 = V_30 ;
V_8 . V_31 = V_32 ;
V_8 . V_33 = 0 ;
for ( V_22 = 0 ; V_22 < 6 ; V_22 ++ )
V_8 . V_34 |= ( V_35 ) V_17 -> V_36 [ V_22 ] << ( ( 5 - V_22 ) * 8 ) ;
if ( F_11 ( V_12 , 1 , 3 ) ) {
if ( V_5 -> V_37 ) {
V_5 -> V_37 = F_12 ( V_38 , V_5 -> V_37 ) ;
V_8 . V_39 = V_5 -> V_37 ;
} else {
V_5 -> V_37 = V_38 ;
V_8 . V_39 = V_5 -> V_37 ;
}
if ( F_13 ( V_12 , 1 , 6 ) )
V_8 . V_40 = V_41 ;
} else if ( F_10 ( V_12 , 1 , 3 ) ) {
V_8 . V_39 = V_20 ;
} else {
V_8 . V_39 = V_20 + V_42 ;
}
V_8 . V_43 = 0 ;
if ( F_13 ( V_12 , 1 , 7 ) && V_5 -> V_44 ) {
V_8 . V_43 |= V_45 ;
if ( ! V_5 -> V_46 )
V_5 -> V_46 = V_47 ;
V_8 . V_48 = V_5 -> V_46 ;
}
V_8 . V_49 = V_50 ;
F_14 ( V_51 , L_3
L_4
L_5 ,
V_8 . V_28 , V_8 . V_31 ,
( unsigned long long ) V_8 . V_34 ,
V_8 . V_33 , V_8 . V_49 , V_8 . V_40 ,
( unsigned long long ) V_8 . V_39 , V_8 . V_43 , V_8 . V_48 ) ;
return F_15 ( V_12 , & V_8 , sizeof( V_8 ) ) ;
}
static int F_16 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
V_35 V_52 ;
T_2 V_28 ;
F_14 ( V_51 , L_6
L_4
L_7 ,
V_8 -> V_28 , V_8 -> V_31 ,
( unsigned long long ) V_8 -> V_34 ,
V_8 -> V_33 , V_8 -> V_49 , V_8 -> V_40 ,
( unsigned long long ) V_8 -> V_39 , V_5 -> V_37 , V_8 -> V_43 ,
V_8 -> V_48 ) ;
V_8 -> V_24 . V_11 = F_9 ( V_12 ) ;
V_28 = V_8 -> V_28 ;
if ( F_10 ( V_12 , 1 , 2 ) && V_28 == V_29 )
V_28 = V_30 ;
if ( F_10 ( V_12 , 1 , 3 ) ) {
V_52 = V_21 ;
} else if ( F_11 ( V_12 , 1 , 3 ) ) {
V_52 = V_5 -> V_37 ? V_5 -> V_37 : V_38 ;
V_52 = F_12 ( V_8 -> V_39 , V_52 ) ;
V_8 -> V_39 = V_52 ;
} else {
V_52 = V_21 + V_42 ;
}
V_5 -> V_37 = V_52 ;
if ( F_13 ( V_12 , 1 , 7 ) )
V_5 -> V_44 &= ! ! ( V_8 -> V_43 & V_45 ) ;
else
V_5 -> V_44 = false ;
if ( V_5 -> V_44 ) {
if ( ! V_5 -> V_46 )
V_5 -> V_46 = V_47 ;
V_5 -> V_46 = F_12 ( V_5 -> V_46 , V_8 -> V_48 ) ;
if ( V_5 -> V_46 < V_53 ) {
V_5 -> V_44 = false ;
V_5 -> V_46 = 0 ;
V_8 -> V_43 &= ~ V_45 ;
}
V_8 -> V_48 = V_5 -> V_46 ;
} else {
V_8 -> V_43 &= ~ V_45 ;
V_8 -> V_48 = 0 ;
}
if ( F_13 ( V_12 , 1 , 6 ) ) {
V_8 -> V_28 = V_30 ;
V_8 -> V_40 = V_41 ;
}
if ( ! ( V_28 | V_30 ) ||
V_8 -> V_31 != V_32 ||
V_8 -> V_39 != V_52 ) {
F_14 ( V_51 , L_8 ) ;
V_8 -> V_24 . V_9 = V_54 ;
( void ) F_15 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
return - V_14 ;
} else {
F_14 ( V_51 , L_9
L_10
L_11 ,
V_8 -> V_28 , V_8 -> V_31 ,
( unsigned long long ) V_8 -> V_34 ,
V_8 -> V_33 , V_8 -> V_49 , V_8 -> V_40 ,
( unsigned long long ) V_8 -> V_39 , V_5 -> V_37 , V_8 -> V_43 ,
V_8 -> V_48 ) ;
V_8 -> V_24 . V_9 = V_55 ;
return F_15 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
}
}
static int F_17 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
F_14 ( V_51 , L_12 ) ;
return 0 ;
}
static int F_18 ( struct V_15 * V_12 ,
struct V_19 * V_8 )
{
F_14 ( V_51 , L_13 ) ;
return - V_14 ;
}
static int F_19 ( struct V_15 * V_12 , void * V_6 )
{
struct V_19 * V_8 = V_6 ;
switch ( V_8 -> V_24 . V_9 ) {
case V_26 :
return F_16 ( V_12 , V_8 ) ;
case V_55 :
return F_17 ( V_12 , V_8 ) ;
case V_54 :
return F_18 ( V_12 , V_8 ) ;
default:
return - V_14 ;
}
}
static void F_20 ( struct V_15 * V_12 )
{
struct V_1 * V_2 ;
V_2 = & V_12 -> V_56 [ V_57 ] ;
V_2 -> V_58 = V_2 -> V_59 = 1 ;
V_2 = & V_12 -> V_56 [ V_60 ] ;
V_2 -> V_58 = V_2 -> V_59 = 1 ;
}
static struct V_61 * F_21 ( struct V_16 * V_17 ,
unsigned int V_62 )
{
struct V_61 * V_63 = F_22 ( V_17 , V_62 + V_64 + 8 + 8 ) ;
unsigned long V_34 , V_65 ;
if ( F_23 ( ! V_63 ) )
return NULL ;
V_34 = ( unsigned long ) V_63 -> V_66 ;
V_65 = ( ( V_34 + 7UL ) & ~ 7UL ) - V_34 ;
if ( V_65 )
F_24 ( V_63 , V_65 ) ;
return V_63 ;
}
static inline void F_25 ( struct V_61 * V_63 )
{
struct V_67 * V_68 = F_26 ( V_63 ) ;
int V_69 = F_27 ( V_63 ) ;
if ( V_63 -> V_70 != F_28 ( V_71 ) )
return;
if ( V_68 -> V_70 != V_72 &&
V_68 -> V_70 != V_73 )
return;
V_63 -> V_74 = V_75 ;
V_63 -> V_76 = 1 ;
V_63 -> V_77 = 0 ;
if ( V_68 -> V_70 == V_72 ) {
struct V_78 * V_79 = F_29 ( V_63 ) ;
V_79 -> V_80 = 0 ;
V_63 -> V_77 = F_30 ( V_63 , V_69 , V_63 -> V_62 - V_69 , 0 ) ;
V_79 -> V_80 = F_31 ( V_68 -> V_81 , V_68 -> V_82 ,
V_63 -> V_62 - V_69 , V_72 ,
V_63 -> V_77 ) ;
} else if ( V_68 -> V_70 == V_73 ) {
struct V_83 * V_84 = F_32 ( V_63 ) ;
V_84 -> V_80 = 0 ;
V_63 -> V_77 = F_30 ( V_63 , V_69 , V_63 -> V_62 - V_69 , 0 ) ;
V_84 -> V_80 = F_31 ( V_68 -> V_81 , V_68 -> V_82 ,
V_63 -> V_62 - V_69 , V_73 ,
V_63 -> V_77 ) ;
}
}
static int F_33 ( struct V_4 * V_5 , struct V_85 * V_86 )
{
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
unsigned int V_62 = V_86 -> V_87 ;
unsigned int V_88 ;
struct V_61 * V_63 ;
int V_89 ;
int V_23 ;
V_23 = - V_90 ;
if ( V_5 -> V_44 && V_5 -> V_46 > V_5 -> V_37 )
V_89 = V_5 -> V_46 ;
else
V_89 = V_5 -> V_37 ;
if ( F_23 ( V_62 < V_91 || V_62 > V_89 ) ) {
V_17 -> V_92 . V_93 ++ ;
goto V_94;
}
V_63 = F_21 ( V_17 , V_62 ) ;
V_23 = - V_95 ;
if ( F_23 ( ! V_63 ) ) {
V_17 -> V_92 . V_96 ++ ;
goto V_94;
}
V_88 = ( V_62 + V_64 + 7U ) & ~ 7U ;
F_34 ( V_63 , V_88 ) ;
V_23 = F_35 ( V_5 -> V_12 . V_13 , V_97 ,
V_63 -> V_66 , V_88 , 0 ,
V_86 -> V_98 , V_86 -> V_99 ) ;
if ( F_23 ( V_23 < 0 ) ) {
V_17 -> V_92 . V_100 ++ ;
goto V_101;
}
F_36 ( V_63 , V_64 ) ;
F_37 ( V_63 , V_62 ) ;
V_63 -> V_70 = F_38 ( V_63 , V_17 ) ;
if ( F_13 ( & V_5 -> V_12 , 1 , 8 ) ) {
struct V_102 * V_103 = F_39 ( V_86 ) ;
F_40 ( V_63 ) ;
if ( V_103 -> V_104 & V_105 ) {
if ( V_63 -> V_70 == V_71 ) {
struct V_67 * V_68 = F_26 ( V_63 ) ;
V_68 -> V_80 = 0 ;
F_41 ( V_68 ) ;
}
}
if ( ( V_103 -> V_104 & V_106 ) &&
V_63 -> V_74 == V_75 ) {
if ( V_63 -> V_70 == F_28 ( V_71 ) ) {
struct V_67 * V_68 = F_26 ( V_63 ) ;
int V_107 = V_68 -> V_107 * 4 ;
F_42 ( V_63 ) ;
F_43 ( V_63 , V_107 ) ;
F_25 ( V_63 ) ;
}
}
if ( V_103 -> V_104 & V_108 ) {
V_63 -> V_74 = V_109 ;
V_63 -> V_76 = 0 ;
if ( V_103 -> V_104 & V_110 )
V_63 -> V_76 = 1 ;
}
}
V_63 -> V_74 = V_5 -> V_111 ? V_75 : V_109 ;
V_17 -> V_92 . V_112 ++ ;
V_17 -> V_92 . V_113 += V_62 ;
F_44 ( & V_5 -> V_114 , V_63 ) ;
return 0 ;
V_101:
F_45 ( V_63 ) ;
V_94:
V_17 -> V_92 . V_115 ++ ;
return V_23 ;
}
static int F_46 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_116 , T_1 V_117 , T_2 V_1 )
{
struct V_118 V_119 = {
. V_24 = {
. type = V_120 ,
. V_9 = V_55 ,
. V_10 = V_121 ,
. V_11 = F_9 ( & V_5 -> V_12 ) ,
} ,
. V_122 = V_2 -> V_123 ,
. V_124 = V_116 ,
. V_125 = V_117 ,
. V_126 = V_1 ,
} ;
int V_23 , V_127 ;
int V_128 = 0 ;
V_119 . V_129 = V_2 -> V_58 ;
V_127 = 1 ;
do {
V_23 = F_15 ( & V_5 -> V_12 , & V_119 , sizeof( V_119 ) ) ;
if ( V_23 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_47 ( V_127 ) ;
if ( ( V_127 <<= 1 ) > 128 )
V_127 = 128 ;
if ( V_128 ++ > V_130 ) {
F_48 ( L_14 ,
V_5 -> V_131 [ 0 ] , V_5 -> V_131 [ 1 ] ,
V_5 -> V_131 [ 2 ] , V_5 -> V_131 [ 3 ] ,
V_5 -> V_131 [ 4 ] , V_5 -> V_131 [ 5 ] ) ;
break;
}
} while ( V_23 == - V_132 );
if ( V_23 <= 0 && V_1 == V_133 ) {
V_5 -> V_134 = V_117 ;
V_5 -> V_135 = true ;
} else {
V_5 -> V_134 = 0 ;
V_5 -> V_135 = false ;
}
return V_23 ;
}
static struct V_85 * F_49 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_136 )
{
struct V_85 * V_86 = V_5 -> V_12 . V_137 ;
int V_23 ;
V_23 = F_50 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_138 ,
( V_136 * V_2 -> V_138 ) ,
V_2 -> V_98 , V_2 -> V_99 ) ;
if ( V_23 < 0 )
return F_51 ( V_23 ) ;
return V_86 ;
}
static int F_52 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_1 V_136 )
{
int V_23 ;
V_23 = F_53 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_138 ,
( V_136 * V_2 -> V_138 ) ,
V_2 -> V_98 , V_2 -> V_99 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static int F_54 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_136 , int * V_139 )
{
struct V_85 * V_86 = F_49 ( V_5 , V_2 , V_136 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_23 ;
F_55 ( V_86 == NULL ) ;
if ( F_56 ( V_86 ) )
return F_57 ( V_86 ) ;
if ( V_86 -> V_119 . V_126 != V_140 )
return 1 ;
F_58 () ;
F_14 ( V_141 , L_15 ,
V_86 -> V_119 . V_126 , V_86 -> V_119 . V_142 ,
V_86 -> V_87 , V_86 -> V_99 ,
V_86 -> V_98 [ 0 ] . V_143 ,
V_86 -> V_98 [ 0 ] . V_144 ) ;
V_23 = F_33 ( V_5 , V_86 ) ;
if ( V_23 == - V_14 )
return V_23 ;
V_86 -> V_119 . V_126 = V_145 ;
V_23 = F_52 ( V_5 , V_2 , V_86 , V_136 ) ;
if ( V_23 < 0 )
return V_23 ;
* V_139 = V_86 -> V_119 . V_142 ;
return 0 ;
}
static int F_59 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_116 , T_1 V_117 , int * V_146 , int V_147 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_148 = - 1 , V_149 = - 1 ;
bool V_150 = true ;
V_117 = ( V_117 == ( T_1 ) - 1 ) ? F_60 ( V_2 , V_116 )
: F_61 ( V_2 , V_117 ) ;
F_14 ( V_141 , L_16 , V_116 , V_117 ) ;
while ( V_116 != V_117 ) {
int V_142 = 0 , V_23 = F_54 ( V_5 , V_2 , V_116 , & V_142 ) ;
if ( V_23 == - V_14 )
return V_23 ;
if ( V_23 != 0 )
break;
( * V_146 ) ++ ;
if ( V_148 == - 1 )
V_148 = V_116 ;
V_149 = V_116 ;
V_116 = F_61 ( V_2 , V_116 ) ;
if ( V_142 && V_116 != V_117 ) {
V_23 = F_46 ( V_5 , V_2 , V_148 , V_149 ,
V_151 ) ;
if ( V_23 == - V_14 )
return V_23 ;
V_148 = - 1 ;
}
if ( ( * V_146 ) >= V_147 ) {
V_150 = false ;
break;
}
}
if ( F_23 ( V_148 == - 1 ) )
V_148 = V_149 = F_60 ( V_2 , V_116 ) ;
if ( V_150 ) {
V_5 -> V_152 = false ;
return F_46 ( V_5 , V_2 , V_148 , V_149 ,
V_133 ) ;
} else {
V_5 -> V_152 = true ;
V_5 -> V_153 = V_149 ;
return 1 ;
}
}
static int F_62 ( struct V_4 * V_5 , void * V_154 , int * V_146 ,
int V_147 )
{
struct V_118 * V_8 = V_154 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_57 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_14 ( V_141 , L_17 ,
V_8 -> V_24 . V_10 , V_8 -> V_129 , V_2 -> V_59 ) ;
if ( F_23 ( V_8 -> V_24 . V_10 != V_121 ) )
return 0 ;
if ( F_23 ( V_8 -> V_129 != V_2 -> V_59 ) ) {
F_4 ( L_18 ,
V_8 -> V_129 , V_2 -> V_59 ) ;
return 0 ;
}
if ( ! V_5 -> V_152 )
V_2 -> V_59 ++ ;
return F_59 ( V_5 , V_2 , V_8 -> V_124 , V_8 -> V_125 ,
V_146 , V_147 ) ;
}
static int F_63 ( struct V_1 * V_2 , T_1 V_117 )
{
T_1 V_155 = V_2 -> V_156 ;
int V_157 = 0 ;
while ( V_155 != V_2 -> V_158 ) {
if ( V_155 == V_117 ) {
V_157 = 1 ;
break;
}
V_155 = F_61 ( V_2 , V_155 ) ;
}
return V_157 ;
}
static int F_64 ( struct V_4 * V_5 , void * V_154 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_118 * V_8 = V_154 ;
struct V_16 * V_17 ;
struct V_159 * V_18 ;
T_1 V_117 ;
struct V_85 * V_86 ;
struct V_160 * V_161 ;
if ( F_23 ( V_8 -> V_24 . V_10 != V_121 ) )
return 0 ;
V_117 = V_8 -> V_125 ;
V_18 = V_5 -> V_18 ;
V_17 = V_18 -> V_17 ;
F_65 ( V_17 ) ;
if ( F_23 ( ! F_63 ( V_2 , V_117 ) ) ) {
F_66 ( V_17 ) ;
return 0 ;
}
V_2 -> V_156 = F_61 ( V_2 , V_117 ) ;
V_86 = F_67 ( V_2 , V_2 -> V_156 ) ;
if ( V_86 -> V_119 . V_126 == V_140 && ! V_5 -> V_162 ) {
if ( F_68 ( V_5 , V_2 -> V_156 ) > 0 )
V_5 -> V_162 = false ;
else
V_5 -> V_162 = true ;
} else {
V_5 -> V_162 = true ;
}
F_66 ( V_17 ) ;
V_161 = F_69 ( V_17 , V_5 -> V_163 ) ;
if ( F_23 ( F_70 ( V_161 ) &&
F_1 ( V_2 ) >= F_71 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_72 ( struct V_4 * V_5 , void * V_154 )
{
return 0 ;
}
static int F_73 ( struct V_4 * V_5 , void * V_154 )
{
struct V_164 * V_8 = V_154 ;
if ( V_8 -> V_24 . V_9 != V_55 )
F_4 ( L_19 ,
V_5 -> V_18 -> V_17 -> V_165 ,
V_8 -> V_24 . type ,
V_8 -> V_24 . V_9 ,
V_8 -> V_24 . V_10 ,
V_8 -> V_24 . V_11 ) ;
return 0 ;
}
static void F_74 ( struct V_4 * V_5 )
{
struct V_160 * V_161 ;
V_161 = F_69 ( V_5 -> V_18 -> V_17 , V_5 -> V_163 ) ;
F_75 ( V_161 , F_76 () ) ;
if ( F_77 ( F_70 ( V_161 ) ) ) {
struct V_1 * V_2 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
F_78 ( V_161 ) ;
}
F_79 ( V_161 ) ;
}
static inline bool F_80 ( struct V_4 * V_159 )
{
struct V_15 * V_12 = & V_159 -> V_12 ;
return ! ! ( V_12 -> V_166 & V_167 ) ;
}
static int F_81 ( struct V_4 * V_5 , int V_147 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_168 , V_23 ;
int V_146 = 0 ;
int V_169 = ( V_5 -> V_170 & V_171 ) ;
V_172:
if ( F_23 ( V_169 == V_171 ||
V_169 == V_173 ) ) {
F_82 ( V_12 , V_169 ) ;
if ( V_169 == V_171 ) {
F_83 ( V_5 ) ;
F_84 ( V_12 ) ;
}
V_5 -> V_170 = 0 ;
return 0 ;
}
V_169 = ( V_5 -> V_170 & V_173 ) ;
V_5 -> V_170 &= ~ ( V_171 | V_173 ) ;
if ( V_169 == V_173 )
goto V_172;
V_169 = V_5 -> V_170 ;
if ( ! ( V_169 & V_174 ) )
return 0 ;
F_55 ( V_169 != V_174 ) ;
V_168 = V_23 = 0 ;
while ( 1 ) {
union {
struct V_7 V_24 ;
V_35 V_175 [ 8 ] ;
} V_154 ;
if ( V_5 -> V_152 ) {
struct V_118 * V_8 =
(struct V_118 * ) & V_154 ;
struct V_1 * V_2 =
& V_5 -> V_12 . V_56 [ V_57 ] ;
V_8 -> V_24 . type = V_120 ;
V_8 -> V_24 . V_9 = V_26 ;
V_8 -> V_24 . V_10 = V_121 ;
V_8 -> V_129 = V_2 -> V_59 ;
V_8 -> V_124 = F_61 ( V_2 , V_5 -> V_153 ) ;
V_8 -> V_125 = - 1 ;
goto V_152;
}
V_23 = F_85 ( V_12 -> V_13 , & V_154 , sizeof( V_154 ) ) ;
if ( F_23 ( V_23 < 0 ) ) {
if ( V_23 == - V_14 )
F_86 ( V_12 ) ;
break;
}
if ( V_23 == 0 )
break;
F_14 ( V_141 , L_20 ,
V_154 . V_24 . type ,
V_154 . V_24 . V_9 ,
V_154 . V_24 . V_10 ,
V_154 . V_24 . V_11 ) ;
V_23 = F_87 ( V_12 , & V_154 . V_24 ) ;
if ( V_23 < 0 )
break;
V_152:
if ( F_77 ( V_154 . V_24 . type == V_120 ) ) {
if ( V_154 . V_24 . V_9 == V_26 ) {
if ( ! F_80 ( V_5 ) ) {
V_23 = - V_14 ;
break;
}
V_23 = F_62 ( V_5 , & V_154 , & V_146 , V_147 ) ;
if ( V_146 >= V_147 )
break;
if ( V_146 == 0 )
break;
} else if ( V_154 . V_24 . V_9 == V_55 ) {
V_23 = F_64 ( V_5 , & V_154 ) ;
if ( V_23 > 0 )
V_168 |= V_23 ;
} else if ( V_154 . V_24 . V_9 == V_54 ) {
V_23 = F_72 ( V_5 , & V_154 ) ;
}
} else if ( V_154 . V_24 . type == V_25 ) {
if ( V_154 . V_24 . V_10 == V_176 )
V_23 = F_73 ( V_5 , & V_154 ) ;
else
V_23 = F_88 ( V_12 , & V_154 ) ;
if ( V_23 )
break;
} else {
V_23 = F_3 ( V_5 , & V_154 ) ;
}
if ( V_23 == - V_14 )
break;
}
if ( F_23 ( V_168 && V_23 != - V_14 ) )
F_74 ( V_5 ) ;
return V_146 ;
}
static int F_89 ( struct V_177 * V_114 , int V_147 )
{
struct V_4 * V_5 = F_90 ( V_114 , struct V_4 , V_114 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_178 = F_81 ( V_5 , V_147 ) ;
if ( V_178 < V_147 ) {
F_91 ( V_114 ) ;
V_5 -> V_170 &= ~ V_174 ;
F_92 ( V_12 -> V_179 -> V_180 , V_181 ) ;
}
return V_178 ;
}
static void F_93 ( void * V_6 , int V_169 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
V_5 -> V_170 |= V_169 ;
F_92 ( V_12 -> V_179 -> V_180 , V_182 ) ;
F_94 ( & V_5 -> V_114 ) ;
}
static int F_68 ( struct V_4 * V_5 , T_1 V_116 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_118 V_119 = {
. V_24 = {
. type = V_120 ,
. V_9 = V_26 ,
. V_10 = V_121 ,
. V_11 = F_9 ( & V_5 -> V_12 ) ,
} ,
. V_122 = V_2 -> V_123 ,
. V_124 = V_116 ,
. V_125 = ( T_1 ) - 1 ,
} ;
int V_23 , V_127 ;
int V_128 = 0 ;
if ( V_5 -> V_135 ) {
V_23 = F_46 ( V_5 ,
& V_5 -> V_12 . V_56 [ V_57 ] ,
V_5 -> V_134 , - 1 ,
V_133 ) ;
if ( V_23 <= 0 )
return V_23 ;
}
V_119 . V_129 = V_2 -> V_58 ;
V_127 = 1 ;
do {
V_23 = F_15 ( & V_5 -> V_12 , & V_119 , sizeof( V_119 ) ) ;
if ( V_23 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_47 ( V_127 ) ;
if ( ( V_127 <<= 1 ) > 128 )
V_127 = 128 ;
if ( V_128 ++ > V_130 )
break;
} while ( V_23 == - V_132 );
return V_23 ;
}
struct V_4 * F_95 ( struct V_159 * V_18 , struct V_61 * V_63 )
{
unsigned int V_183 = F_96 ( V_63 -> V_66 ) ;
struct V_184 * V_185 = & V_18 -> V_186 [ V_183 ] ;
struct V_4 * V_5 ;
F_97 (port, hp, hash) {
if ( ! F_80 ( V_5 ) )
continue;
if ( F_98 ( V_5 -> V_131 , V_63 -> V_66 ) )
return V_5 ;
}
F_99 (port, &vp->port_list, list) {
if ( ! V_5 -> V_111 )
continue;
if ( ! F_80 ( V_5 ) )
continue;
return V_5 ;
}
return NULL ;
}
static struct V_61 * F_100 ( struct V_4 * V_5 ,
unsigned * V_187 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_61 * V_63 = NULL ;
int V_22 , V_188 ;
* V_187 = 0 ;
V_188 = V_2 -> V_158 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_85 * V_189 ;
-- V_188 ;
if ( V_188 < 0 )
V_188 = V_3 - 1 ;
V_189 = F_67 ( V_2 , V_188 ) ;
if ( V_189 -> V_119 . V_126 == V_140 ) {
( * V_187 ) ++ ;
continue;
}
if ( V_5 -> V_190 [ V_188 ] . V_63 ) {
if ( V_189 -> V_119 . V_126 != V_145 )
F_101 ( L_21 ,
V_189 -> V_119 . V_126 ) ;
F_55 ( V_5 -> V_190 [ V_188 ] . V_63 -> V_191 ) ;
V_5 -> V_190 [ V_188 ] . V_63 -> V_191 = V_63 ;
V_63 = V_5 -> V_190 [ V_188 ] . V_63 ;
V_5 -> V_190 [ V_188 ] . V_63 = NULL ;
F_102 ( V_5 -> V_12 . V_13 ,
V_5 -> V_190 [ V_188 ] . V_98 ,
V_5 -> V_190 [ V_188 ] . V_99 ) ;
} else if ( V_189 -> V_119 . V_126 == V_192 )
break;
V_189 -> V_119 . V_126 = V_192 ;
}
return V_63 ;
}
static inline void F_103 ( struct V_61 * V_63 )
{
struct V_61 * V_191 ;
while ( V_63 ) {
V_191 = V_63 -> V_191 ;
V_63 -> V_191 = NULL ;
F_104 ( V_63 ) ;
V_63 = V_191 ;
}
}
static void F_105 ( unsigned long V_193 )
{
struct V_4 * V_5 = (struct V_4 * ) V_193 ;
struct V_61 * V_194 ;
unsigned V_187 ;
F_65 ( V_5 -> V_18 -> V_17 ) ;
V_194 = F_100 ( V_5 , & V_187 ) ;
F_66 ( V_5 -> V_18 -> V_17 ) ;
F_103 ( V_194 ) ;
if ( V_187 )
( void ) F_106 ( & V_5 -> V_195 ,
V_196 + V_197 ) ;
else
F_107 ( & V_5 -> V_195 ) ;
}
static inline int F_108 ( struct V_198 * V_13 , struct V_61 * V_63 ,
struct V_199 * V_98 , int V_99 ,
unsigned int V_200 )
{
int V_22 , V_201 , V_23 , V_202 ;
V_202 = F_109 ( V_63 ) ;
if ( V_202 < V_91 )
V_202 = V_91 ;
V_202 += V_64 ;
V_202 += 8 - ( V_202 & 7 ) ;
V_23 = F_110 ( V_13 , V_63 -> V_66 - V_64 , V_202 , V_98 ,
V_99 , V_200 ) ;
if ( V_23 < 0 )
return V_23 ;
V_201 = V_23 ;
for ( V_22 = 0 ; V_22 < F_111 ( V_63 ) -> V_203 ; V_22 ++ ) {
T_3 * V_204 = & F_111 ( V_63 ) -> V_205 [ V_22 ] ;
T_2 * V_206 ;
if ( V_201 < V_99 ) {
V_206 = F_112 ( F_113 ( V_204 ) ) ;
V_202 = F_114 ( V_204 ) ;
V_202 += 8 - ( V_202 & 7 ) ;
V_23 = F_110 ( V_13 , V_206 + V_204 -> V_207 ,
V_202 , V_98 + V_201 , V_99 - V_201 ,
V_200 ) ;
F_115 ( V_206 ) ;
} else {
V_23 = - V_90 ;
}
if ( V_23 < 0 ) {
F_102 ( V_13 , V_98 , V_201 ) ;
return V_23 ;
}
V_201 += V_23 ;
}
return V_201 ;
}
static inline struct V_61 * F_116 ( struct V_61 * V_63 , int V_99 )
{
struct V_61 * V_208 ;
int V_22 , V_62 , V_209 , V_210 ;
V_62 = V_63 -> V_62 ;
V_209 = 0 ;
if ( V_62 < V_91 ) {
V_209 += V_91 - V_63 -> V_62 ;
V_62 += V_209 ;
}
V_62 += V_64 ;
V_209 += 8 - ( V_62 & 7 ) ;
V_210 = F_111 ( V_63 ) -> V_203 >= V_99 ;
for ( V_22 = 0 ; V_22 < F_111 ( V_63 ) -> V_203 ; V_22 ++ ) {
T_3 * V_204 = & F_111 ( V_63 ) -> V_205 [ V_22 ] ;
V_210 |= V_204 -> V_207 & 7 ;
}
if ( ( ( unsigned long ) V_63 -> V_66 & 7 ) != V_64 ||
F_117 ( V_63 ) < V_209 ||
F_118 ( V_63 ) < V_64 || V_210 ) {
int V_116 = 0 , V_69 ;
T_4 V_77 ;
V_62 = V_63 -> V_62 > V_91 ? V_63 -> V_62 : V_91 ;
V_208 = F_21 ( V_63 -> V_17 , V_62 ) ;
if ( V_208 == NULL ) {
F_104 ( V_63 ) ;
return NULL ;
}
F_24 ( V_208 , V_64 ) ;
V_208 -> V_70 = V_63 -> V_70 ;
V_69 = F_119 ( V_63 ) - V_63 -> V_66 ;
F_120 ( V_208 , V_69 ) ;
V_69 = F_121 ( V_63 ) - V_63 -> V_66 ;
F_122 ( V_208 , V_69 ) ;
V_69 = F_123 ( V_63 ) - V_63 -> V_66 ;
F_43 ( V_208 , V_69 ) ;
V_69 = 0 ;
V_208 -> V_211 = V_63 -> V_211 ;
V_208 -> V_74 = V_63 -> V_74 ;
if ( V_63 -> V_74 == V_109 )
V_116 = F_124 ( V_63 ) ;
if ( V_116 ) {
struct V_67 * V_68 = F_26 ( V_208 ) ;
int V_69 = V_116 + V_208 -> V_211 ;
if ( F_125 ( V_63 , 0 , V_208 -> V_66 , V_116 ) ) {
F_104 ( V_208 ) ;
F_104 ( V_63 ) ;
return NULL ;
}
* ( V_212 * ) ( V_63 -> V_66 + V_69 ) = 0 ;
V_77 = F_126 ( V_63 , V_116 ,
V_208 -> V_66 + V_116 ,
V_63 -> V_62 - V_116 , 0 ) ;
if ( V_68 -> V_70 == V_72 ||
V_68 -> V_70 == V_73 ) {
V_77 = F_31 ( V_68 -> V_81 , V_68 -> V_82 ,
V_63 -> V_62 - V_116 ,
V_68 -> V_70 , V_77 ) ;
}
* ( V_212 * ) ( V_208 -> V_66 + V_69 ) = V_77 ;
V_208 -> V_74 = V_75 ;
} else if ( F_125 ( V_63 , 0 , V_208 -> V_66 , V_63 -> V_62 ) ) {
F_104 ( V_208 ) ;
F_104 ( V_63 ) ;
return NULL ;
}
( void ) F_34 ( V_208 , V_63 -> V_62 ) ;
if ( F_127 ( V_63 ) ) {
F_111 ( V_208 ) -> V_213 = F_111 ( V_63 ) -> V_213 ;
F_111 ( V_208 ) -> V_214 = F_111 ( V_63 ) -> V_214 ;
}
V_208 -> V_215 = V_63 -> V_215 ;
F_104 ( V_63 ) ;
V_63 = V_208 ;
}
return V_63 ;
}
static T_5
F_128 ( struct V_16 * V_17 , struct V_61 * V_63 ,
void * V_216 , T_6 V_217 )
{
struct V_159 * V_18 = F_129 ( V_17 ) ;
struct V_4 * V_5 = F_95 ( V_18 , V_63 ) ;
if ( V_5 == NULL )
return 0 ;
return V_5 -> V_163 ;
}
static int F_130 ( struct V_4 * V_5 , struct V_61 * V_63 )
{
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_61 * V_218 ;
int V_219 , V_220 ;
int V_221 ;
int V_213 , V_214 , V_222 ;
int V_223 = F_123 ( V_63 ) - F_119 ( V_63 ) ;
int V_224 = V_225 ;
if ( V_63 -> V_70 == F_28 ( V_71 ) )
V_224 = F_26 ( V_63 ) -> V_70 ;
else if ( V_63 -> V_70 == F_28 ( V_226 ) )
V_224 = F_131 ( V_63 ) -> V_227 ;
if ( V_224 == V_72 )
V_223 += F_29 ( V_63 ) -> V_228 * 4 ;
else if ( V_224 == V_73 )
V_223 += sizeof( struct V_83 ) ;
else {
F_4 ( L_22
L_23 , V_63 -> V_70 , V_224 ) ;
V_223 = 128 ;
}
V_220 = V_5 -> V_46 - V_223 ;
V_213 = F_111 ( V_63 ) -> V_213 ;
V_214 = F_111 ( V_63 ) -> V_214 ;
V_222 = F_111 ( V_63 ) -> V_222 ;
if ( V_5 -> V_44 && V_213 < V_220 )
V_222 = F_132 ( V_63 -> V_62 - V_223 , V_220 ) ;
if ( F_23 ( F_1 ( V_2 ) < V_222 ) ) {
struct V_160 * V_161 ;
V_161 = F_69 ( V_17 , V_5 -> V_163 ) ;
F_133 ( V_161 ) ;
if ( F_1 ( V_2 ) < F_111 ( V_63 ) -> V_222 )
return V_229 ;
F_78 ( V_161 ) ;
}
V_219 = F_121 ( V_63 ) - F_119 ( V_63 ) ;
F_36 ( V_63 , V_219 ) ;
if ( V_5 -> V_44 && V_213 < V_220 ) {
if ( F_134 ( V_63 , V_230 ) )
goto V_94;
F_111 ( V_63 ) -> V_213 = V_220 ;
F_111 ( V_63 ) -> V_222 = V_222 ;
}
V_218 = F_135 ( V_63 , V_17 -> V_231 & ~ V_232 ) ;
if ( F_56 ( V_218 ) )
goto V_94;
F_136 ( V_63 , V_219 ) ;
F_137 ( V_63 ) ;
V_221 = 0 ;
while ( V_218 ) {
struct V_61 * V_233 = V_218 ;
V_218 = V_218 -> V_191 ;
V_233 -> V_191 = NULL ;
if ( V_5 -> V_44 && V_233 -> V_62 > V_17 -> V_39 ) {
F_111 ( V_233 ) -> V_213 = V_213 ;
F_111 ( V_233 ) -> V_214 = V_214 ;
F_111 ( V_233 ) -> V_222 =
F_132 ( V_233 -> V_62 - V_223 , V_213 ) ;
} else
F_111 ( V_233 ) -> V_213 = 0 ;
F_136 ( V_233 , V_219 ) ;
F_137 ( V_233 ) ;
memcpy ( F_119 ( V_233 ) , F_119 ( V_63 ) ,
V_219 ) ;
V_233 -> V_234 = F_123 ( V_233 ) - V_233 -> V_235 ;
if ( F_26 ( V_233 ) -> V_70 == V_72 )
V_233 -> V_211 = F_138 ( struct V_78 , V_80 ) ;
else if ( F_26 ( V_233 ) -> V_70 == V_73 )
V_233 -> V_211 = F_138 ( struct V_83 , V_80 ) ;
if ( ! ( V_221 & V_236 ) )
V_221 = F_139 ( V_233 , V_17 ) ;
if ( V_221 & V_236 )
F_140 ( V_233 ) ;
}
if ( ! ( V_221 & V_236 ) )
F_140 ( V_63 ) ;
return V_221 ;
V_94:
V_17 -> V_92 . V_237 ++ ;
F_140 ( V_63 ) ;
return V_238 ;
}
static int F_139 ( struct V_61 * V_63 , struct V_16 * V_17 )
{
struct V_159 * V_18 = F_129 ( V_17 ) ;
struct V_4 * V_5 = NULL ;
struct V_1 * V_2 ;
struct V_85 * V_189 ;
unsigned int V_62 ;
struct V_61 * V_194 = NULL ;
int V_22 , V_23 , V_188 ;
unsigned V_187 = 0 ;
struct V_160 * V_161 ;
F_141 () ;
V_5 = F_95 ( V_18 , V_63 ) ;
if ( F_23 ( ! V_5 ) ) {
F_142 () ;
goto V_94;
}
if ( F_127 ( V_63 ) && V_63 -> V_62 > V_5 -> V_46 ) {
V_23 = F_130 ( V_5 , V_63 ) ;
F_142 () ;
return V_23 ;
}
if ( ! F_127 ( V_63 ) && V_63 -> V_62 > V_5 -> V_37 ) {
unsigned long V_52 = V_5 -> V_37 - V_239 ;
if ( F_13 ( & V_5 -> V_12 , 1 , 3 ) )
V_52 -= V_42 ;
if ( V_63 -> V_70 == F_28 ( V_71 ) ) {
struct V_240 V_241 ;
struct V_242 * V_243 = NULL ;
memset ( & V_241 , 0 , sizeof( V_241 ) ) ;
V_241 . V_244 = V_17 -> V_245 ;
V_241 . V_246 = F_143 ( F_26 ( V_63 ) -> V_247 ) ;
V_241 . V_82 = F_26 ( V_63 ) -> V_82 ;
V_241 . V_81 = F_26 ( V_63 ) -> V_81 ;
V_243 = F_144 ( F_145 ( V_17 ) , & V_241 ) ;
F_142 () ;
if ( ! F_56 ( V_243 ) ) {
F_146 ( V_63 , & V_243 -> V_248 ) ;
F_147 ( V_63 , V_249 ,
V_250 ,
F_148 ( V_52 ) ) ;
}
}
#if F_149 ( V_251 )
else if ( V_63 -> V_70 == F_28 ( V_226 ) )
F_150 ( V_63 , V_252 , 0 , V_52 ) ;
#endif
goto V_94;
}
V_63 = F_116 ( V_63 , 2 ) ;
if ( F_23 ( ! V_63 ) )
goto V_94;
if ( V_63 -> V_74 == V_109 )
F_25 ( V_63 ) ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
V_22 = F_151 ( V_63 ) ;
V_161 = F_69 ( V_17 , V_22 ) ;
if ( F_23 ( F_1 ( V_2 ) < 1 ) ) {
if ( ! F_70 ( V_161 ) ) {
F_133 ( V_161 ) ;
F_152 ( V_17 , L_24 ) ;
V_17 -> V_92 . V_253 ++ ;
}
F_142 () ;
return V_229 ;
}
V_189 = F_153 ( V_2 ) ;
V_188 = V_2 -> V_158 ;
V_194 = F_100 ( V_5 , & V_187 ) ;
F_55 ( V_5 -> V_190 [ V_188 ] . V_63 ) ;
V_62 = V_63 -> V_62 ;
if ( V_62 < V_91 )
V_62 = V_91 ;
V_23 = F_108 ( V_5 -> V_12 . V_13 , V_63 , V_5 -> V_190 [ V_188 ] . V_98 , 2 ,
( V_254 | V_255 | V_256 ) ) ;
if ( V_23 < 0 ) {
F_154 ( V_17 , L_25 , V_23 ) ;
goto V_94;
}
V_5 -> V_190 [ V_188 ] . V_63 = V_63 ;
V_63 = NULL ;
V_5 -> V_190 [ V_188 ] . V_99 = V_23 ;
V_189 -> V_119 . V_142 = V_257 ;
V_189 -> V_87 = V_62 ;
V_189 -> V_99 = V_5 -> V_190 [ V_188 ] . V_99 ;
for ( V_22 = 0 ; V_22 < V_189 -> V_99 ; V_22 ++ )
V_189 -> V_98 [ V_22 ] = V_5 -> V_190 [ V_188 ] . V_98 [ V_22 ] ;
if ( F_13 ( & V_5 -> V_12 , 1 , 7 ) ) {
struct V_102 * V_103 = F_39 ( V_189 ) ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
if ( F_127 ( V_5 -> V_190 [ V_188 ] . V_63 ) ) {
V_103 -> V_258 = F_111 ( V_5 -> V_190 [ V_188 ] . V_63 )
-> V_213 ;
V_103 -> V_104 |= V_259 ;
}
if ( F_13 ( & V_5 -> V_12 , 1 , 8 ) &&
! V_5 -> V_111 ) {
V_103 -> V_104 |= V_108 ;
V_103 -> V_104 |= V_110 ;
}
}
F_155 () ;
V_189 -> V_119 . V_126 = V_140 ;
if ( ! V_5 -> V_162 )
goto V_260;
V_23 = F_68 ( V_5 , V_2 -> V_156 ) ;
if ( F_23 ( V_23 < 0 ) ) {
F_154 ( V_17 , L_26 , V_23 ) ;
V_189 -> V_119 . V_126 = V_192 ;
V_63 = V_5 -> V_190 [ V_188 ] . V_63 ;
V_5 -> V_190 [ V_188 ] . V_63 = NULL ;
V_17 -> V_92 . V_261 ++ ;
goto V_94;
}
V_260:
V_5 -> V_162 = false ;
V_17 -> V_92 . V_262 ++ ;
V_17 -> V_92 . V_263 += V_5 -> V_190 [ V_188 ] . V_63 -> V_62 ;
V_2 -> V_158 = ( V_2 -> V_158 + 1 ) & ( V_3 - 1 ) ;
if ( F_23 ( F_1 ( V_2 ) < 1 ) ) {
F_133 ( V_161 ) ;
if ( F_1 ( V_2 ) > F_71 ( V_2 ) )
F_78 ( V_161 ) ;
}
( void ) F_106 ( & V_5 -> V_195 , V_196 + V_197 ) ;
F_142 () ;
F_103 ( V_194 ) ;
return V_238 ;
V_94:
if ( V_187 )
( void ) F_106 ( & V_5 -> V_195 ,
V_196 + V_197 ) ;
else if ( V_5 )
F_107 ( & V_5 -> V_195 ) ;
if ( V_5 )
F_142 () ;
if ( V_63 )
F_104 ( V_63 ) ;
F_103 ( V_194 ) ;
V_17 -> V_92 . V_237 ++ ;
return V_238 ;
}
static void F_156 ( struct V_16 * V_17 )
{
}
static int F_157 ( struct V_16 * V_17 )
{
F_158 ( V_17 ) ;
F_159 ( V_17 ) ;
return 0 ;
}
static int F_160 ( struct V_16 * V_17 )
{
F_161 ( V_17 ) ;
F_162 ( V_17 ) ;
return 0 ;
}
static struct V_264 * F_163 ( struct V_159 * V_18 , T_2 * V_34 )
{
struct V_264 * V_265 ;
for ( V_265 = V_18 -> V_266 ; V_265 ; V_265 = V_265 -> V_191 ) {
if ( F_98 ( V_265 -> V_34 , V_34 ) )
return V_265 ;
}
return NULL ;
}
static void F_164 ( struct V_159 * V_18 , struct V_16 * V_17 )
{
struct V_267 * V_268 ;
F_165 (ha, dev) {
struct V_264 * V_265 ;
V_265 = F_163 ( V_18 , V_268 -> V_34 ) ;
if ( V_265 ) {
V_265 -> V_269 = 1 ;
continue;
}
if ( ! V_265 ) {
V_265 = F_166 ( sizeof( * V_265 ) , V_230 ) ;
if ( ! V_265 )
continue;
memcpy ( V_265 -> V_34 , V_268 -> V_34 , V_270 ) ;
V_265 -> V_269 = 1 ;
V_265 -> V_191 = V_18 -> V_266 ;
V_18 -> V_266 = V_265 ;
}
}
}
static void F_167 ( struct V_159 * V_18 , struct V_4 * V_5 )
{
struct V_164 V_271 ;
struct V_264 * V_265 , * * V_272 ;
int V_273 ;
memset ( & V_271 , 0 , sizeof( V_271 ) ) ;
V_271 . V_24 . type = V_25 ;
V_271 . V_24 . V_9 = V_26 ;
V_271 . V_24 . V_10 = V_176 ;
V_271 . V_24 . V_11 = F_9 ( & V_5 -> V_12 ) ;
V_271 . V_274 = 1 ;
V_273 = 0 ;
for ( V_265 = V_18 -> V_266 ; V_265 ; V_265 = V_265 -> V_191 ) {
if ( V_265 -> V_275 )
continue;
V_265 -> V_275 = 1 ;
memcpy ( & V_271 . V_276 [ V_273 * V_270 ] ,
V_265 -> V_34 , V_270 ) ;
if ( ++ V_273 == V_277 ) {
V_271 . V_278 = V_273 ;
( void ) F_15 ( & V_5 -> V_12 , & V_271 ,
sizeof( V_271 ) ) ;
V_273 = 0 ;
}
}
if ( V_273 ) {
V_271 . V_278 = V_273 ;
( void ) F_15 ( & V_5 -> V_12 , & V_271 , sizeof( V_271 ) ) ;
}
V_271 . V_274 = 0 ;
V_273 = 0 ;
V_272 = & V_18 -> V_266 ;
while ( ( V_265 = * V_272 ) != NULL ) {
if ( V_265 -> V_269 ) {
V_265 -> V_269 = 0 ;
V_272 = & V_265 -> V_191 ;
continue;
}
memcpy ( & V_271 . V_276 [ V_273 * V_270 ] ,
V_265 -> V_34 , V_270 ) ;
if ( ++ V_273 == V_277 ) {
V_271 . V_278 = V_273 ;
( void ) F_15 ( & V_5 -> V_12 , & V_271 ,
sizeof( V_271 ) ) ;
V_273 = 0 ;
}
* V_272 = V_265 -> V_191 ;
F_168 ( V_265 ) ;
}
if ( V_273 ) {
V_271 . V_278 = V_273 ;
( void ) F_15 ( & V_5 -> V_12 , & V_271 , sizeof( V_271 ) ) ;
}
}
static void F_169 ( struct V_16 * V_17 )
{
struct V_159 * V_18 = F_129 ( V_17 ) ;
struct V_4 * V_5 ;
F_141 () ;
F_99 (port, &vp->port_list, list) {
if ( V_5 -> V_111 ) {
F_164 ( V_18 , V_17 ) ;
F_167 ( V_18 , V_5 ) ;
break;
}
}
F_142 () ;
}
static int F_170 ( struct V_16 * V_17 , int V_279 )
{
if ( V_279 < 68 || V_279 > 65535 )
return - V_280 ;
V_17 -> V_39 = V_279 ;
return 0 ;
}
static int F_171 ( struct V_16 * V_17 , void * V_281 )
{
return - V_280 ;
}
static void F_172 ( struct V_16 * V_17 ,
struct V_282 * V_271 )
{
F_173 ( V_271 -> V_283 , V_284 , sizeof( V_271 -> V_283 ) ) ;
F_173 ( V_271 -> V_285 , V_286 , sizeof( V_271 -> V_285 ) ) ;
}
static T_1 F_174 ( struct V_16 * V_17 )
{
struct V_159 * V_18 = F_129 ( V_17 ) ;
return V_18 -> V_287 ;
}
static void F_175 ( struct V_16 * V_17 , T_1 V_288 )
{
struct V_159 * V_18 = F_129 ( V_17 ) ;
V_18 -> V_287 = V_288 ;
}
static void F_176 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
if ( V_2 -> V_289 == NULL )
return;
for ( V_22 = 0 ; V_22 < V_3 ; V_22 ++ ) {
struct V_85 * V_189 ;
void * V_63 = V_5 -> V_190 [ V_22 ] . V_63 ;
if ( ! V_63 )
continue;
V_189 = F_67 ( V_2 , V_22 ) ;
F_102 ( V_5 -> V_12 . V_13 ,
V_5 -> V_190 [ V_22 ] . V_98 ,
V_5 -> V_190 [ V_22 ] . V_99 ) ;
F_104 ( V_63 ) ;
V_5 -> V_190 [ V_22 ] . V_63 = NULL ;
V_189 -> V_119 . V_126 = V_192 ;
}
F_177 ( V_5 -> V_12 . V_13 , V_2 -> V_289 ,
( V_2 -> V_138 * V_2 -> V_290 ) ,
V_2 -> V_98 , V_2 -> V_99 ) ;
V_2 -> V_289 = NULL ;
V_2 -> V_138 = 0 ;
V_2 -> V_290 = 0 ;
V_2 -> V_187 = 0 ;
V_2 -> V_99 = 0 ;
}
static void F_83 ( struct V_4 * V_5 )
{
F_107 ( & V_5 -> V_195 ) ;
F_176 ( V_5 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_44 = true ;
V_5 -> V_46 = 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_62 , V_291 ;
int V_22 , V_23 , V_99 ;
void * V_292 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
V_291 = sizeof( struct V_85 ) +
sizeof( struct V_199 ) * 2 ;
if ( F_13 ( & V_5 -> V_12 , 1 , 7 ) )
V_291 += sizeof( struct V_102 ) ;
V_62 = V_3 * V_291 ;
V_99 = V_293 ;
V_292 = F_178 ( V_5 -> V_12 . V_13 , V_62 ,
V_2 -> V_98 , & V_99 ,
( V_254 |
V_255 |
V_256 ) ) ;
if ( F_56 ( V_292 ) ) {
V_23 = F_57 ( V_292 ) ;
goto V_294;
}
V_2 -> V_289 = V_292 ;
V_2 -> V_138 = V_291 ;
V_2 -> V_290 = V_3 ;
V_2 -> V_158 = V_2 -> V_156 = 0 ;
V_5 -> V_162 = true ;
V_2 -> V_187 = V_3 ;
V_2 -> V_99 = V_99 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_85 * V_189 ;
V_189 = F_67 ( V_2 , V_22 ) ;
V_189 -> V_119 . V_126 = V_192 ;
}
return 0 ;
V_294:
F_176 ( V_5 ) ;
return V_23 ;
}
static void F_179 ( struct V_16 * V_17 )
{
struct V_159 * V_18 = F_129 ( V_17 ) ;
struct V_4 * V_5 ;
unsigned long V_104 ;
F_180 ( & V_18 -> V_295 , V_104 ) ;
if ( ! F_181 ( & V_18 -> V_296 ) ) {
V_5 = F_182 ( V_18 -> V_296 . V_191 , struct V_4 , V_297 ) ;
F_94 ( & V_5 -> V_114 ) ;
}
F_183 ( & V_18 -> V_295 , V_104 ) ;
}
static struct V_159 * F_184 ( const V_35 * V_298 ,
struct V_299 * V_179 )
{
struct V_16 * V_17 ;
struct V_159 * V_18 ;
int V_23 , V_22 ;
V_17 = F_185 ( sizeof( * V_18 ) , V_300 , 1 ) ;
if ( ! V_17 )
return F_51 ( - V_95 ) ;
V_17 -> V_301 = V_64 + 8 ;
V_17 -> V_302 = 8 ;
for ( V_22 = 0 ; V_22 < V_270 ; V_22 ++ )
V_17 -> V_36 [ V_22 ] = ( * V_298 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_18 = F_129 ( V_17 ) ;
F_186 ( & V_18 -> V_295 ) ;
V_18 -> V_17 = V_17 ;
F_187 ( & V_18 -> V_296 ) ;
for ( V_22 = 0 ; V_22 < V_303 ; V_22 ++ )
F_188 ( & V_18 -> V_186 [ V_22 ] ) ;
F_187 ( & V_18 -> V_297 ) ;
V_18 -> V_298 = * V_298 ;
V_17 -> V_304 = & V_305 ;
V_17 -> V_306 = & V_307 ;
V_17 -> V_308 = V_309 ;
V_17 -> V_310 = V_232 | V_311 | V_312 |
V_313 | V_314 ;
V_17 -> V_231 = V_17 -> V_310 ;
F_189 ( V_17 , & V_179 -> V_17 ) ;
V_23 = F_190 ( V_17 ) ;
if ( V_23 ) {
F_4 ( L_27 ) ;
goto V_315;
}
F_154 ( V_17 , L_28 , V_17 -> V_36 ) ;
F_191 ( & V_18 -> V_297 , & V_316 ) ;
return V_18 ;
V_315:
F_192 ( V_17 ) ;
return F_51 ( V_23 ) ;
}
static struct V_159 * F_193 ( const V_35 * V_298 ,
struct V_299 * V_179 )
{
struct V_159 * V_317 , * V_18 ;
F_194 ( & V_318 ) ;
V_18 = NULL ;
F_195 (iter, &vnet_list, list) {
if ( V_317 -> V_298 == * V_298 ) {
V_18 = V_317 ;
break;
}
}
if ( ! V_18 )
V_18 = F_184 ( V_298 , V_179 ) ;
F_196 ( & V_318 ) ;
return V_18 ;
}
static void F_197 ( void )
{
struct V_159 * V_18 ;
struct V_16 * V_17 ;
F_194 ( & V_318 ) ;
while ( ! F_181 ( & V_316 ) ) {
V_18 = F_198 ( & V_316 , struct V_159 , V_297 ) ;
F_199 ( & V_18 -> V_297 ) ;
V_17 = V_18 -> V_17 ;
F_55 ( ! F_181 ( & V_18 -> V_296 ) ) ;
F_200 ( V_17 ) ;
F_192 ( V_17 ) ;
}
F_196 ( & V_318 ) ;
}
static struct V_159 * F_201 ( struct V_319 * V_185 ,
V_35 V_320 ,
struct V_299 * V_179 )
{
const V_35 * V_298 = NULL ;
V_35 V_321 ;
F_202 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
V_35 V_322 = F_203 ( V_185 , V_321 ) ;
const char * V_165 ;
V_165 = F_204 ( V_185 , V_322 , L_29 , NULL ) ;
if ( ! V_165 || strcmp ( V_165 , L_30 ) )
continue;
V_298 = F_204 ( V_185 , V_322 ,
V_323 , NULL ) ;
if ( V_298 )
break;
}
if ( ! V_298 )
return F_51 ( - V_324 ) ;
return F_193 ( V_298 , V_179 ) ;
}
static void F_205 ( void )
{
F_206 ( V_325 L_31 , V_285 ) ;
}
static void
F_207 ( struct V_4 * V_5 )
{
struct V_159 * V_18 = V_5 -> V_18 ;
int V_326 ;
V_326 = V_18 -> V_327 ++ ;
V_326 = V_326 & ( V_300 - 1 ) ;
V_5 -> V_163 = V_326 ;
F_78 ( F_69 ( V_18 -> V_17 , V_5 -> V_163 ) ) ;
}
static void
F_208 ( struct V_4 * V_5 )
{
V_5 -> V_18 -> V_327 -- ;
F_133 ( F_69 ( V_5 -> V_18 -> V_17 , V_5 -> V_163 ) ) ;
}
static int F_209 ( struct V_299 * V_179 , const struct V_328 * V_329 )
{
struct V_319 * V_185 ;
struct V_4 * V_5 ;
unsigned long V_104 ;
struct V_159 * V_18 ;
const V_35 * V_330 ;
int V_62 , V_22 , V_23 , V_111 ;
F_205 () ;
V_185 = F_210 () ;
V_18 = F_201 ( V_185 , V_179 -> V_331 , V_179 ) ;
if ( F_56 ( V_18 ) ) {
F_4 ( L_32 ) ;
V_23 = F_57 ( V_18 ) ;
goto V_332;
}
V_330 = F_204 ( V_185 , V_179 -> V_331 , V_333 , & V_62 ) ;
V_23 = - V_324 ;
if ( ! V_330 ) {
F_4 ( L_33 , V_333 ) ;
goto V_332;
}
V_5 = F_166 ( sizeof( * V_5 ) , V_334 ) ;
V_23 = - V_95 ;
if ( ! V_5 )
goto V_332;
for ( V_22 = 0 ; V_22 < V_270 ; V_22 ++ )
V_5 -> V_131 [ V_22 ] = ( * V_330 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_5 -> V_18 = V_18 ;
V_23 = F_211 ( & V_5 -> V_12 , V_179 , V_335 ,
V_336 , F_212 ( V_336 ) ,
& V_337 , V_18 -> V_17 -> V_165 ) ;
if ( V_23 )
goto V_338;
V_23 = F_213 ( & V_5 -> V_12 , & V_339 , V_5 ) ;
if ( V_23 )
goto V_338;
F_214 ( V_5 -> V_18 -> V_17 , & V_5 -> V_114 , F_89 , V_340 ) ;
F_215 ( & V_5 -> V_183 ) ;
F_187 ( & V_5 -> V_297 ) ;
V_111 = 0 ;
if ( F_204 ( V_185 , V_179 -> V_331 , L_34 , NULL ) != NULL )
V_111 = 1 ;
V_5 -> V_111 = V_111 ;
V_5 -> V_44 = true ;
V_5 -> V_46 = 0 ;
F_180 ( & V_18 -> V_295 , V_104 ) ;
if ( V_111 )
F_216 ( & V_5 -> V_297 , & V_18 -> V_296 ) ;
else
F_217 ( & V_5 -> V_297 , & V_18 -> V_296 ) ;
F_218 ( & V_5 -> V_183 ,
& V_18 -> V_186 [ F_96 ( V_5 -> V_131 ) ] ) ;
F_207 ( V_5 ) ;
F_183 ( & V_18 -> V_295 , V_104 ) ;
F_219 ( & V_179 -> V_17 , V_5 ) ;
F_48 ( L_35 ,
V_18 -> V_17 -> V_165 , V_5 -> V_131 , V_111 ? L_36 : L_37 ) ;
F_220 ( & V_5 -> V_195 , F_105 ,
( unsigned long ) V_5 ) ;
F_221 ( & V_5 -> V_114 ) ;
F_84 ( & V_5 -> V_12 ) ;
F_222 ( V_185 ) ;
return 0 ;
V_338:
F_168 ( V_5 ) ;
V_332:
F_222 ( V_185 ) ;
return V_23 ;
}
static int F_223 ( struct V_299 * V_179 )
{
struct V_4 * V_5 = F_224 ( & V_179 -> V_17 ) ;
if ( V_5 ) {
F_225 ( & V_5 -> V_12 . V_341 ) ;
F_226 ( & V_5 -> V_114 ) ;
F_227 ( & V_5 -> V_297 ) ;
F_228 ( & V_5 -> V_183 ) ;
F_229 () ;
F_225 ( & V_5 -> V_195 ) ;
F_208 ( V_5 ) ;
F_230 ( & V_5 -> V_114 ) ;
F_176 ( V_5 ) ;
F_231 ( & V_5 -> V_12 ) ;
F_219 ( & V_179 -> V_17 , NULL ) ;
F_168 ( V_5 ) ;
}
return 0 ;
}
static int T_7 F_232 ( void )
{
return F_233 ( & V_342 ) ;
}
static void T_8 F_234 ( void )
{
F_235 ( & V_342 ) ;
F_197 () ;
}
