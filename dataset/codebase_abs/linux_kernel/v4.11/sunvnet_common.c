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
int F_6 ( struct V_15 * V_12 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
struct V_16 * V_17 = F_8 ( V_5 ) ;
struct V_18 V_8 ;
int V_19 = V_20 ;
int V_21 , V_22 ;
V_22 = F_9 ( F_7 ( V_12 ) ) ;
if ( V_22 )
return V_22 ;
memset ( & V_8 , 0 , sizeof( V_8 ) ) ;
V_8 . V_23 . type = V_24 ;
V_8 . V_23 . V_9 = V_25 ;
V_8 . V_23 . V_10 = V_26 ;
V_8 . V_23 . V_11 = F_10 ( V_12 ) ;
if ( F_11 ( V_12 , 1 , 2 ) )
V_8 . V_27 = V_28 ;
else
V_8 . V_27 = V_29 ;
V_8 . V_30 = V_31 ;
V_8 . V_32 = 0 ;
for ( V_21 = 0 ; V_21 < 6 ; V_21 ++ )
V_8 . V_33 |= ( V_34 ) V_17 -> V_35 [ V_21 ] << ( ( 5 - V_21 ) * 8 ) ;
if ( F_12 ( V_12 , 1 , 3 ) ) {
if ( V_5 -> V_36 ) {
V_5 -> V_36 = F_13 ( V_37 , V_5 -> V_36 ) ;
V_8 . V_38 = V_5 -> V_36 ;
} else {
V_5 -> V_36 = V_37 ;
V_8 . V_38 = V_5 -> V_36 ;
}
if ( F_14 ( V_12 , 1 , 6 ) )
V_8 . V_39 = V_40 ;
} else if ( F_11 ( V_12 , 1 , 3 ) ) {
V_8 . V_38 = V_19 ;
} else {
V_8 . V_38 = V_19 + V_41 ;
}
V_8 . V_42 = 0 ;
if ( F_14 ( V_12 , 1 , 7 ) && V_5 -> V_43 ) {
V_8 . V_42 |= V_44 ;
if ( ! V_5 -> V_45 )
V_5 -> V_45 = V_46 ;
V_8 . V_47 = V_5 -> V_45 ;
}
V_8 . V_48 = V_49 ;
F_15 ( V_50 , L_3
L_4
L_5 ,
V_8 . V_27 , V_8 . V_30 ,
( unsigned long long ) V_8 . V_33 ,
V_8 . V_32 , V_8 . V_48 , V_8 . V_39 ,
( unsigned long long ) V_8 . V_38 , V_8 . V_42 , V_8 . V_47 ) ;
return F_16 ( V_12 , & V_8 , sizeof( V_8 ) ) ;
}
static int F_17 ( struct V_15 * V_12 ,
struct V_18 * V_8 )
{
struct V_4 * V_5 = F_7 ( V_12 ) ;
V_34 V_51 ;
T_2 V_27 ;
F_15 ( V_50 , L_6
L_4
L_7 ,
V_8 -> V_27 , V_8 -> V_30 ,
( unsigned long long ) V_8 -> V_33 ,
V_8 -> V_32 , V_8 -> V_48 , V_8 -> V_39 ,
( unsigned long long ) V_8 -> V_38 , V_5 -> V_36 , V_8 -> V_42 ,
V_8 -> V_47 ) ;
V_8 -> V_23 . V_11 = F_10 ( V_12 ) ;
V_27 = V_8 -> V_27 ;
if ( F_11 ( V_12 , 1 , 2 ) && V_27 == V_28 )
V_27 = V_29 ;
if ( F_11 ( V_12 , 1 , 3 ) ) {
V_51 = V_20 ;
} else if ( F_12 ( V_12 , 1 , 3 ) ) {
V_51 = V_5 -> V_36 ? V_5 -> V_36 : V_37 ;
V_51 = F_13 ( V_8 -> V_38 , V_51 ) ;
V_8 -> V_38 = V_51 ;
} else {
V_51 = V_20 + V_41 ;
}
V_5 -> V_36 = V_51 ;
if ( F_14 ( V_12 , 1 , 7 ) )
V_5 -> V_43 &= ! ! ( V_8 -> V_42 & V_44 ) ;
else
V_5 -> V_43 = false ;
if ( V_5 -> V_43 ) {
if ( ! V_5 -> V_45 )
V_5 -> V_45 = V_46 ;
V_5 -> V_45 = F_13 ( V_5 -> V_45 , V_8 -> V_47 ) ;
if ( V_5 -> V_45 < V_52 ) {
V_5 -> V_43 = false ;
V_5 -> V_45 = 0 ;
V_8 -> V_42 &= ~ V_44 ;
}
V_8 -> V_47 = V_5 -> V_45 ;
} else {
V_8 -> V_42 &= ~ V_44 ;
V_8 -> V_47 = 0 ;
V_5 -> V_45 = 0 ;
}
if ( F_14 ( V_12 , 1 , 6 ) ) {
V_8 -> V_27 = V_29 ;
V_8 -> V_39 = V_40 ;
}
if ( ! ( V_27 | V_29 ) ||
V_8 -> V_30 != V_31 ||
V_8 -> V_38 != V_51 ) {
F_15 ( V_50 , L_8 ) ;
V_8 -> V_23 . V_9 = V_53 ;
( void ) F_16 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
return - V_14 ;
}
F_15 ( V_50 , L_9
L_10
L_11 ,
V_8 -> V_27 , V_8 -> V_30 ,
( unsigned long long ) V_8 -> V_33 ,
V_8 -> V_32 , V_8 -> V_48 , V_8 -> V_39 ,
( unsigned long long ) V_8 -> V_38 , V_5 -> V_36 , V_8 -> V_42 ,
V_8 -> V_47 ) ;
V_8 -> V_23 . V_9 = V_54 ;
return F_16 ( V_12 , V_8 , sizeof( * V_8 ) ) ;
}
static int F_18 ( struct V_15 * V_12 ,
struct V_18 * V_8 )
{
F_15 ( V_50 , L_12 ) ;
return 0 ;
}
static int F_19 ( struct V_15 * V_12 ,
struct V_18 * V_8 )
{
F_15 ( V_50 , L_13 ) ;
return - V_14 ;
}
int F_20 ( struct V_15 * V_12 , void * V_6 )
{
struct V_18 * V_8 = V_6 ;
switch ( V_8 -> V_23 . V_9 ) {
case V_25 :
return F_17 ( V_12 , V_8 ) ;
case V_54 :
return F_18 ( V_12 , V_8 ) ;
case V_53 :
return F_19 ( V_12 , V_8 ) ;
default:
return - V_14 ;
}
}
void F_21 ( struct V_15 * V_12 )
{
struct V_1 * V_2 ;
V_2 = & V_12 -> V_55 [ V_56 ] ;
V_2 -> V_57 = 1 ;
V_2 -> V_58 = 1 ;
V_2 = & V_12 -> V_55 [ V_59 ] ;
V_2 -> V_57 = 1 ;
V_2 -> V_58 = 1 ;
}
static struct V_60 * F_22 ( struct V_16 * V_17 ,
unsigned int V_61 )
{
struct V_60 * V_62 ;
unsigned long V_33 , V_63 ;
V_62 = F_23 ( V_17 , V_61 + V_64 + 8 + 8 ) ;
if ( F_24 ( ! V_62 ) )
return NULL ;
V_33 = ( unsigned long ) V_62 -> V_65 ;
V_63 = ( ( V_33 + 7UL ) & ~ 7UL ) - V_33 ;
if ( V_63 )
F_25 ( V_62 , V_63 ) ;
return V_62 ;
}
static inline void F_26 ( struct V_60 * V_62 )
{
struct V_66 * V_67 = F_27 ( V_62 ) ;
int V_68 = F_28 ( V_62 ) ;
if ( V_62 -> V_69 != F_29 ( V_70 ) )
return;
if ( V_67 -> V_69 != V_71 &&
V_67 -> V_69 != V_72 )
return;
V_62 -> V_73 = V_74 ;
V_62 -> V_75 = 1 ;
V_62 -> V_76 = 0 ;
if ( V_67 -> V_69 == V_71 ) {
struct V_77 * V_78 = F_30 ( V_62 ) ;
V_78 -> V_79 = 0 ;
V_62 -> V_76 = F_31 ( V_62 , V_68 , V_62 -> V_61 - V_68 , 0 ) ;
V_78 -> V_79 = F_32 ( V_67 -> V_80 , V_67 -> V_81 ,
V_62 -> V_61 - V_68 , V_71 ,
V_62 -> V_76 ) ;
} else if ( V_67 -> V_69 == V_72 ) {
struct V_82 * V_83 = F_33 ( V_62 ) ;
V_83 -> V_79 = 0 ;
V_62 -> V_76 = F_31 ( V_62 , V_68 , V_62 -> V_61 - V_68 , 0 ) ;
V_83 -> V_79 = F_32 ( V_67 -> V_80 , V_67 -> V_81 ,
V_62 -> V_61 - V_68 , V_72 ,
V_62 -> V_76 ) ;
}
}
static int F_34 ( struct V_4 * V_5 , struct V_84 * V_85 )
{
struct V_16 * V_17 = F_8 ( V_5 ) ;
unsigned int V_61 = V_85 -> V_86 ;
unsigned int V_87 ;
struct V_60 * V_62 ;
int V_88 ;
int V_22 ;
V_22 = - V_89 ;
if ( V_5 -> V_43 && V_5 -> V_45 > V_5 -> V_36 )
V_88 = V_5 -> V_45 ;
else
V_88 = V_5 -> V_36 ;
if ( F_24 ( V_61 < V_90 || V_61 > V_88 ) ) {
V_17 -> V_91 . V_92 ++ ;
goto V_93;
}
V_62 = F_22 ( V_17 , V_61 ) ;
V_22 = - V_94 ;
if ( F_24 ( ! V_62 ) ) {
V_17 -> V_91 . V_95 ++ ;
goto V_93;
}
V_87 = ( V_61 + V_64 + 7U ) & ~ 7U ;
F_35 ( V_62 , V_87 ) ;
V_22 = F_36 ( V_5 -> V_12 . V_13 , V_96 ,
V_62 -> V_65 , V_87 , 0 ,
V_85 -> V_97 , V_85 -> V_98 ) ;
if ( F_24 ( V_22 < 0 ) ) {
V_17 -> V_91 . V_99 ++ ;
goto V_100;
}
F_37 ( V_62 , V_64 ) ;
F_38 ( V_62 , V_61 ) ;
V_62 -> V_69 = F_39 ( V_62 , V_17 ) ;
if ( F_14 ( & V_5 -> V_12 , 1 , 8 ) ) {
struct V_101 * V_102 = F_40 ( V_85 ) ;
F_41 ( V_62 ) ;
if ( V_102 -> V_103 & V_104 ) {
if ( V_62 -> V_69 == V_70 ) {
struct V_66 * V_67 = F_27 ( V_62 ) ;
V_67 -> V_79 = 0 ;
F_42 ( V_67 ) ;
}
}
if ( ( V_102 -> V_103 & V_105 ) &&
V_62 -> V_73 == V_74 ) {
if ( V_62 -> V_69 == F_29 ( V_70 ) ) {
struct V_66 * V_67 = F_27 ( V_62 ) ;
int V_106 = V_67 -> V_106 * 4 ;
F_43 ( V_62 ) ;
F_44 ( V_62 , V_106 ) ;
F_26 ( V_62 ) ;
}
}
if ( V_102 -> V_103 & V_107 ) {
V_62 -> V_73 = V_108 ;
V_62 -> V_75 = 0 ;
if ( V_102 -> V_103 & V_109 )
V_62 -> V_75 = 1 ;
}
}
V_62 -> V_73 = V_5 -> V_110 ? V_74 : V_108 ;
V_17 -> V_91 . V_111 ++ ;
V_17 -> V_91 . V_112 += V_61 ;
F_45 ( & V_5 -> V_113 , V_62 ) ;
return 0 ;
V_100:
F_46 ( V_62 ) ;
V_93:
V_17 -> V_91 . V_114 ++ ;
return V_22 ;
}
static int F_47 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_115 , T_1 V_116 , T_2 V_1 )
{
struct V_117 V_118 = {
. V_23 = {
. type = V_119 ,
. V_9 = V_54 ,
. V_10 = V_120 ,
. V_11 = F_10 ( & V_5 -> V_12 ) ,
} ,
. V_121 = V_2 -> V_122 ,
. V_123 = V_115 ,
. V_124 = V_116 ,
. V_125 = V_1 ,
} ;
int V_22 , V_126 ;
int V_127 = 0 ;
V_118 . V_128 = V_2 -> V_58 ;
V_126 = 1 ;
do {
V_22 = F_16 ( & V_5 -> V_12 , & V_118 , sizeof( V_118 ) ) ;
if ( V_22 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_48 ( V_126 ) ;
if ( ( V_126 <<= 1 ) > 128 )
V_126 = 128 ;
if ( V_127 ++ > V_129 ) {
F_49 ( L_14 ,
V_5 -> V_130 [ 0 ] , V_5 -> V_130 [ 1 ] ,
V_5 -> V_130 [ 2 ] , V_5 -> V_130 [ 3 ] ,
V_5 -> V_130 [ 4 ] , V_5 -> V_130 [ 5 ] ) ;
break;
}
} while ( V_22 == - V_131 );
if ( V_22 <= 0 && V_1 == V_132 ) {
V_5 -> V_133 = V_116 ;
V_5 -> V_134 = true ;
} else {
V_5 -> V_133 = 0 ;
V_5 -> V_134 = false ;
}
return V_22 ;
}
static struct V_84 * F_50 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_135 )
{
struct V_84 * V_85 = V_5 -> V_12 . V_136 ;
int V_22 ;
V_22 = F_51 ( V_5 -> V_12 . V_13 , V_85 , V_2 -> V_137 ,
( V_135 * V_2 -> V_137 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
if ( V_22 < 0 )
return F_52 ( V_22 ) ;
return V_85 ;
}
static int F_53 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_1 V_135 )
{
int V_22 ;
V_22 = F_54 ( V_5 -> V_12 . V_13 , V_85 , V_2 -> V_137 ,
( V_135 * V_2 -> V_137 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
}
static int F_55 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_135 , int * V_138 )
{
struct V_84 * V_85 = F_50 ( V_5 , V_2 , V_135 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_22 ;
F_56 ( ! V_85 ) ;
if ( F_57 ( V_85 ) )
return F_58 ( V_85 ) ;
if ( V_85 -> V_118 . V_125 != V_139 )
return 1 ;
F_59 () ;
F_15 ( V_140 , L_15 ,
V_85 -> V_118 . V_125 , V_85 -> V_118 . V_141 ,
V_85 -> V_86 , V_85 -> V_98 ,
V_85 -> V_97 [ 0 ] . V_142 ,
V_85 -> V_97 [ 0 ] . V_143 ) ;
V_22 = F_34 ( V_5 , V_85 ) ;
if ( V_22 == - V_14 )
return V_22 ;
F_60 ( V_5 -> V_12 . V_144 , V_5 -> V_12 . V_145 ,
V_135 , V_85 -> V_118 . V_141 ) ;
V_85 -> V_118 . V_125 = V_146 ;
V_22 = F_53 ( V_5 , V_2 , V_85 , V_135 ) ;
if ( V_22 < 0 )
return V_22 ;
* V_138 = V_85 -> V_118 . V_141 ;
return 0 ;
}
static int F_61 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_115 , T_1 V_116 , int * V_147 , int V_148 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_149 = - 1 , V_150 = - 1 ;
bool V_151 = true ;
V_116 = ( V_116 == ( T_1 ) - 1 ) ? F_62 ( V_2 , V_115 )
: F_63 ( V_2 , V_116 ) ;
F_15 ( V_140 , L_16 , V_115 , V_116 ) ;
while ( V_115 != V_116 ) {
int V_141 = 0 , V_22 = F_55 ( V_5 , V_2 , V_115 , & V_141 ) ;
if ( V_22 == - V_14 )
return V_22 ;
if ( V_22 != 0 )
break;
( * V_147 ) ++ ;
if ( V_149 == - 1 )
V_149 = V_115 ;
V_150 = V_115 ;
V_115 = F_63 ( V_2 , V_115 ) ;
if ( V_141 && V_115 != V_116 ) {
V_22 = F_47 ( V_5 , V_2 , V_149 , V_150 ,
V_152 ) ;
if ( V_22 == - V_14 )
return V_22 ;
V_149 = - 1 ;
}
if ( ( * V_147 ) >= V_148 ) {
V_151 = false ;
break;
}
}
if ( F_24 ( V_149 == - 1 ) ) {
V_150 = F_62 ( V_2 , V_115 ) ;
V_149 = V_150 ;
}
if ( V_151 ) {
V_5 -> V_153 = false ;
F_64 ( V_5 -> V_12 . V_144 ,
V_5 -> V_12 . V_145 ,
V_150 , * V_147 ) ;
return F_47 ( V_5 , V_2 , V_149 , V_150 ,
V_132 ) ;
} else {
F_65 ( V_5 -> V_12 . V_144 ,
V_5 -> V_12 . V_145 ,
V_150 , * V_147 ) ;
V_5 -> V_153 = true ;
V_5 -> V_154 = V_150 ;
return 1 ;
}
}
static int F_66 ( struct V_4 * V_5 , void * V_155 , int * V_147 ,
int V_148 )
{
struct V_117 * V_8 = V_155 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_56 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_15 ( V_140 , L_17 ,
V_8 -> V_23 . V_10 , V_8 -> V_128 , V_2 -> V_57 ) ;
if ( F_24 ( V_8 -> V_23 . V_10 != V_120 ) )
return 0 ;
if ( F_24 ( V_8 -> V_128 != V_2 -> V_57 ) ) {
F_4 ( L_18 ,
V_8 -> V_128 , V_2 -> V_57 ) ;
return 0 ;
}
if ( ! V_5 -> V_153 )
V_2 -> V_57 ++ ;
return F_61 ( V_5 , V_2 , V_8 -> V_123 , V_8 -> V_124 ,
V_147 , V_148 ) ;
}
static int F_67 ( struct V_1 * V_2 , T_1 V_116 )
{
T_1 V_156 = V_2 -> V_157 ;
int V_158 = 0 ;
while ( V_156 != V_2 -> V_159 ) {
if ( V_156 == V_116 ) {
V_158 = 1 ;
break;
}
V_156 = F_63 ( V_2 , V_156 ) ;
}
return V_158 ;
}
static int F_68 ( struct V_4 * V_5 , void * V_155 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
struct V_117 * V_8 = V_155 ;
struct V_16 * V_17 ;
T_1 V_116 ;
struct V_84 * V_85 ;
struct V_160 * V_161 ;
if ( F_24 ( V_8 -> V_23 . V_10 != V_120 ) )
return 0 ;
V_116 = V_8 -> V_124 ;
V_17 = F_8 ( V_5 ) ;
F_69 ( V_17 ) ;
if ( F_24 ( ! F_67 ( V_2 , V_116 ) ) ) {
F_70 ( V_17 ) ;
return 0 ;
}
F_71 ( V_5 -> V_12 . V_144 ,
V_5 -> V_12 . V_145 , V_116 ) ;
V_2 -> V_157 = F_63 ( V_2 , V_116 ) ;
V_85 = F_72 ( V_2 , V_2 -> V_157 ) ;
if ( V_85 -> V_118 . V_125 == V_139 && ! V_5 -> V_162 ) {
if ( F_73 ( V_5 , V_2 -> V_157 ) > 0 )
V_5 -> V_162 = false ;
else
V_5 -> V_162 = true ;
} else {
V_5 -> V_162 = true ;
}
F_70 ( V_17 ) ;
V_161 = F_74 ( V_17 , V_5 -> V_163 ) ;
if ( F_24 ( F_75 ( V_161 ) &&
F_1 ( V_2 ) >= F_76 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_77 ( struct V_4 * V_5 , void * V_155 )
{
return 0 ;
}
static int F_78 ( struct V_4 * V_5 , void * V_155 )
{
struct V_164 * V_8 = V_155 ;
struct V_16 * V_17 = F_8 ( V_5 ) ;
if ( V_8 -> V_23 . V_9 != V_54 )
F_4 ( L_19 ,
V_17 -> V_165 ,
V_8 -> V_23 . type ,
V_8 -> V_23 . V_9 ,
V_8 -> V_23 . V_10 ,
V_8 -> V_23 . V_11 ) ;
return 0 ;
}
static void F_79 ( struct V_4 * V_5 )
{
struct V_160 * V_161 ;
V_161 = F_74 ( F_8 ( V_5 ) ,
V_5 -> V_163 ) ;
F_80 ( V_161 , F_81 () ) ;
if ( F_82 ( F_75 ( V_161 ) ) )
F_83 ( V_161 ) ;
F_84 ( V_161 ) ;
}
bool F_85 ( struct V_4 * V_166 )
{
struct V_15 * V_12 = & V_166 -> V_12 ;
return ! ! ( V_12 -> V_167 & V_168 ) ;
}
static int F_86 ( struct V_4 * V_5 , int V_148 )
{
struct V_16 * V_17 = F_8 ( V_5 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_169 , V_22 ;
int V_147 = 0 ;
F_56 ( V_5 -> V_170 & ~ ( V_171 |
V_172 |
V_173 ) ) ;
if ( V_5 -> V_170 & V_172 ) {
F_87 ( V_12 , V_172 ) ;
F_88 ( V_5 ) ;
F_89 ( V_12 ) ;
if ( F_90 ( V_17 ) )
F_79 ( V_5 ) ;
V_5 -> V_170 = 0 ;
return 0 ;
}
if ( V_5 -> V_170 & V_173 ) {
F_87 ( V_12 , V_173 ) ;
V_5 -> V_170 = 0 ;
return 0 ;
}
V_22 = 0 ;
V_169 = 0 ;
while ( 1 ) {
union {
struct V_7 V_23 ;
V_34 V_174 [ 8 ] ;
} V_155 ;
if ( V_5 -> V_153 ) {
struct V_117 * V_8 =
(struct V_117 * ) & V_155 ;
struct V_1 * V_2 =
& V_5 -> V_12 . V_55 [ V_56 ] ;
V_8 -> V_23 . type = V_119 ;
V_8 -> V_23 . V_9 = V_25 ;
V_8 -> V_23 . V_10 = V_120 ;
V_8 -> V_128 = V_2 -> V_57 ;
V_8 -> V_123 = F_63 ( V_2 ,
V_5 -> V_154 ) ;
V_8 -> V_124 = - 1 ;
} else {
V_22 = F_91 ( V_12 -> V_13 , & V_155 , sizeof( V_155 ) ) ;
if ( F_24 ( V_22 < 0 ) ) {
if ( V_22 == - V_14 )
F_92 ( V_12 ) ;
break;
}
if ( V_22 == 0 )
break;
F_15 ( V_140 , L_20 ,
V_155 . V_23 . type ,
V_155 . V_23 . V_9 ,
V_155 . V_23 . V_10 ,
V_155 . V_23 . V_11 ) ;
V_22 = F_93 ( V_12 , & V_155 . V_23 ) ;
if ( V_22 < 0 )
break;
}
if ( F_82 ( V_155 . V_23 . type == V_119 ) ) {
if ( V_155 . V_23 . V_9 == V_25 ) {
if ( ! F_85 ( V_5 ) ) {
V_22 = - V_14 ;
break;
}
V_22 = F_66 ( V_5 , & V_155 , & V_147 , V_148 ) ;
if ( V_147 >= V_148 )
break;
if ( V_147 == 0 )
break;
} else if ( V_155 . V_23 . V_9 == V_54 ) {
V_22 = F_68 ( V_5 , & V_155 ) ;
if ( V_22 > 0 )
V_169 |= V_22 ;
} else if ( V_155 . V_23 . V_9 == V_53 ) {
V_22 = F_77 ( V_5 , & V_155 ) ;
}
} else if ( V_155 . V_23 . type == V_24 ) {
if ( V_155 . V_23 . V_10 == V_175 )
V_22 = F_78 ( V_5 , & V_155 ) ;
else
V_22 = F_94 ( V_12 , & V_155 ) ;
if ( V_22 )
break;
} else {
V_22 = F_3 ( V_5 , & V_155 ) ;
}
if ( V_22 == - V_14 )
break;
}
if ( F_24 ( V_169 && V_22 != - V_14 ) )
F_79 ( V_5 ) ;
return V_147 ;
}
int F_95 ( struct V_176 * V_113 , int V_148 )
{
struct V_4 * V_5 = F_96 ( V_113 , struct V_4 , V_113 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_177 = F_86 ( V_5 , V_148 ) ;
if ( V_177 < V_148 ) {
F_97 ( V_113 , V_177 ) ;
V_5 -> V_170 &= ~ V_171 ;
F_98 ( V_12 -> V_178 -> V_179 , V_180 ) ;
}
return V_177 ;
}
void F_99 ( void * V_6 , int V_181 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
V_5 -> V_170 |= V_181 ;
F_98 ( V_12 -> V_178 -> V_179 , V_182 ) ;
F_100 ( & V_5 -> V_113 ) ;
}
static int F_73 ( struct V_4 * V_5 , T_1 V_115 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
struct V_117 V_118 = {
. V_23 = {
. type = V_119 ,
. V_9 = V_25 ,
. V_10 = V_120 ,
. V_11 = F_10 ( & V_5 -> V_12 ) ,
} ,
. V_121 = V_2 -> V_122 ,
. V_123 = V_115 ,
. V_124 = ( T_1 ) - 1 ,
} ;
int V_22 , V_126 ;
int V_127 = 0 ;
if ( V_5 -> V_134 ) {
F_101 ( V_5 -> V_12 . V_144 ,
V_5 -> V_12 . V_145 ,
V_5 -> V_133 , - 1 ) ;
V_22 = F_47 ( V_5 ,
& V_5 -> V_12 . V_55 [ V_56 ] ,
V_5 -> V_133 , - 1 ,
V_132 ) ;
if ( V_22 <= 0 )
return V_22 ;
}
V_118 . V_128 = V_2 -> V_58 ;
V_126 = 1 ;
do {
V_22 = F_16 ( & V_5 -> V_12 , & V_118 , sizeof( V_118 ) ) ;
if ( V_22 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_48 ( V_126 ) ;
if ( ( V_126 <<= 1 ) > 128 )
V_126 = 128 ;
if ( V_127 ++ > V_129 )
break;
} while ( V_22 == - V_131 );
F_102 ( V_5 -> V_12 . V_144 ,
V_5 -> V_12 . V_145 , V_115 , V_22 ) ;
return V_22 ;
}
static struct V_60 * F_103 ( struct V_4 * V_5 ,
unsigned * V_183 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
struct V_60 * V_62 = NULL ;
int V_21 , V_184 ;
* V_183 = 0 ;
V_184 = V_2 -> V_159 ;
for ( V_21 = 0 ; V_21 < V_3 ; ++ V_21 ) {
struct V_84 * V_185 ;
-- V_184 ;
if ( V_184 < 0 )
V_184 = V_3 - 1 ;
V_185 = F_72 ( V_2 , V_184 ) ;
if ( V_185 -> V_118 . V_125 == V_139 ) {
( * V_183 ) ++ ;
continue;
}
if ( V_5 -> V_186 [ V_184 ] . V_62 ) {
if ( V_185 -> V_118 . V_125 != V_146 )
F_104 ( L_21 ,
V_185 -> V_118 . V_125 ) ;
F_56 ( V_5 -> V_186 [ V_184 ] . V_62 -> V_187 ) ;
V_5 -> V_186 [ V_184 ] . V_62 -> V_187 = V_62 ;
V_62 = V_5 -> V_186 [ V_184 ] . V_62 ;
V_5 -> V_186 [ V_184 ] . V_62 = NULL ;
F_105 ( V_5 -> V_12 . V_13 ,
V_5 -> V_186 [ V_184 ] . V_97 ,
V_5 -> V_186 [ V_184 ] . V_98 ) ;
} else if ( V_185 -> V_118 . V_125 == V_188 ) {
break;
}
V_185 -> V_118 . V_125 = V_188 ;
}
return V_62 ;
}
static inline void F_106 ( struct V_60 * V_62 )
{
struct V_60 * V_187 ;
while ( V_62 ) {
V_187 = V_62 -> V_187 ;
V_62 -> V_187 = NULL ;
F_107 ( V_62 ) ;
V_62 = V_187 ;
}
}
void F_108 ( unsigned long V_189 )
{
struct V_4 * V_5 = (struct V_4 * ) V_189 ;
struct V_60 * V_190 ;
unsigned V_183 ;
F_69 ( F_8 ( V_5 ) ) ;
V_190 = F_103 ( V_5 , & V_183 ) ;
F_70 ( F_8 ( V_5 ) ) ;
F_106 ( V_190 ) ;
if ( V_183 )
( void ) F_109 ( & V_5 -> V_191 ,
V_192 + V_193 ) ;
else
F_110 ( & V_5 -> V_191 ) ;
}
static inline int F_111 ( struct V_194 * V_13 , struct V_60 * V_62 ,
struct V_195 * V_97 , int V_98 ,
unsigned int V_196 )
{
int V_21 , V_197 , V_22 , V_198 ;
V_198 = F_112 ( V_62 ) ;
if ( V_198 < V_90 )
V_198 = V_90 ;
V_198 += V_64 ;
V_198 += 8 - ( V_198 & 7 ) ;
V_22 = F_113 ( V_13 , V_62 -> V_65 - V_64 , V_198 , V_97 ,
V_98 , V_196 ) ;
if ( V_22 < 0 )
return V_22 ;
V_197 = V_22 ;
for ( V_21 = 0 ; V_21 < F_114 ( V_62 ) -> V_199 ; V_21 ++ ) {
T_3 * V_200 = & F_114 ( V_62 ) -> V_201 [ V_21 ] ;
T_2 * V_202 ;
if ( V_197 < V_98 ) {
V_202 = F_115 ( F_116 ( V_200 ) ) ;
V_198 = F_117 ( V_200 ) ;
V_198 += 8 - ( V_198 & 7 ) ;
V_22 = F_113 ( V_13 , V_202 + V_200 -> V_203 ,
V_198 , V_97 + V_197 , V_98 - V_197 ,
V_196 ) ;
F_118 ( V_202 ) ;
} else {
V_22 = - V_89 ;
}
if ( V_22 < 0 ) {
F_105 ( V_13 , V_97 , V_197 ) ;
return V_22 ;
}
V_197 += V_22 ;
}
return V_197 ;
}
static inline struct V_60 * F_119 ( struct V_60 * V_62 , int V_98 )
{
struct V_60 * V_204 ;
int V_21 , V_61 , V_205 , V_206 ;
V_61 = V_62 -> V_61 ;
V_205 = 0 ;
if ( V_61 < V_90 ) {
V_205 += V_90 - V_62 -> V_61 ;
V_61 += V_205 ;
}
V_61 += V_64 ;
V_205 += 8 - ( V_61 & 7 ) ;
V_206 = F_114 ( V_62 ) -> V_199 >= V_98 ;
for ( V_21 = 0 ; V_21 < F_114 ( V_62 ) -> V_199 ; V_21 ++ ) {
T_3 * V_200 = & F_114 ( V_62 ) -> V_201 [ V_21 ] ;
V_206 |= V_200 -> V_203 & 7 ;
}
if ( ( ( unsigned long ) V_62 -> V_65 & 7 ) != V_64 ||
F_120 ( V_62 ) < V_205 ||
F_121 ( V_62 ) < V_64 || V_206 ) {
int V_115 = 0 , V_68 ;
T_4 V_76 ;
V_61 = V_62 -> V_61 > V_90 ? V_62 -> V_61 : V_90 ;
V_204 = F_22 ( V_62 -> V_17 , V_61 ) ;
if ( ! V_204 ) {
F_107 ( V_62 ) ;
return NULL ;
}
F_25 ( V_204 , V_64 ) ;
V_204 -> V_69 = V_62 -> V_69 ;
V_68 = F_122 ( V_62 ) - V_62 -> V_65 ;
F_123 ( V_204 , V_68 ) ;
V_68 = F_124 ( V_62 ) - V_62 -> V_65 ;
F_125 ( V_204 , V_68 ) ;
V_68 = F_126 ( V_62 ) - V_62 -> V_65 ;
F_44 ( V_204 , V_68 ) ;
V_68 = 0 ;
V_204 -> V_207 = V_62 -> V_207 ;
V_204 -> V_73 = V_62 -> V_73 ;
if ( V_62 -> V_73 == V_108 )
V_115 = F_127 ( V_62 ) ;
if ( V_115 ) {
struct V_66 * V_67 = F_27 ( V_204 ) ;
int V_68 = V_115 + V_204 -> V_207 ;
if ( F_128 ( V_62 , 0 , V_204 -> V_65 , V_115 ) ) {
F_107 ( V_204 ) ;
F_107 ( V_62 ) ;
return NULL ;
}
* ( V_208 * ) ( V_62 -> V_65 + V_68 ) = 0 ;
V_76 = F_129 ( V_62 , V_115 ,
V_204 -> V_65 + V_115 ,
V_62 -> V_61 - V_115 , 0 ) ;
if ( V_67 -> V_69 == V_71 ||
V_67 -> V_69 == V_72 ) {
V_76 = F_32 ( V_67 -> V_80 , V_67 -> V_81 ,
V_62 -> V_61 - V_115 ,
V_67 -> V_69 , V_76 ) ;
}
* ( V_208 * ) ( V_204 -> V_65 + V_68 ) = V_76 ;
V_204 -> V_73 = V_74 ;
} else if ( F_128 ( V_62 , 0 , V_204 -> V_65 , V_62 -> V_61 ) ) {
F_107 ( V_204 ) ;
F_107 ( V_62 ) ;
return NULL ;
}
( void ) F_35 ( V_204 , V_62 -> V_61 ) ;
if ( F_130 ( V_62 ) ) {
F_114 ( V_204 ) -> V_209 = F_114 ( V_62 ) -> V_209 ;
F_114 ( V_204 ) -> V_210 = F_114 ( V_62 ) -> V_210 ;
}
V_204 -> V_211 = V_62 -> V_211 ;
F_107 ( V_62 ) ;
V_62 = V_204 ;
}
return V_62 ;
}
void F_131 ( struct V_16 * V_17 )
{
}
int F_132 ( struct V_16 * V_17 )
{
F_133 ( V_17 ) ;
F_134 ( V_17 ) ;
return 0 ;
}
int F_135 ( struct V_16 * V_17 )
{
F_136 ( V_17 ) ;
F_137 ( V_17 ) ;
return 0 ;
}
static struct V_212 * F_138 ( struct V_166 * V_213 , T_2 * V_33 )
{
struct V_212 * V_214 ;
for ( V_214 = V_213 -> V_215 ; V_214 ; V_214 = V_214 -> V_187 ) {
if ( F_139 ( V_214 -> V_33 , V_33 ) )
return V_214 ;
}
return NULL ;
}
static void F_140 ( struct V_166 * V_213 , struct V_16 * V_17 )
{
struct V_216 * V_217 ;
F_141 (ha, dev) {
struct V_212 * V_214 ;
V_214 = F_138 ( V_213 , V_217 -> V_33 ) ;
if ( V_214 ) {
V_214 -> V_218 = 1 ;
continue;
}
if ( ! V_214 ) {
V_214 = F_142 ( sizeof( * V_214 ) , V_219 ) ;
if ( ! V_214 )
continue;
memcpy ( V_214 -> V_33 , V_217 -> V_33 , V_220 ) ;
V_214 -> V_218 = 1 ;
V_214 -> V_187 = V_213 -> V_215 ;
V_213 -> V_215 = V_214 ;
}
}
}
static void F_143 ( struct V_166 * V_213 , struct V_4 * V_5 )
{
struct V_164 V_221 ;
struct V_212 * V_214 , * * V_222 ;
int V_223 ;
memset ( & V_221 , 0 , sizeof( V_221 ) ) ;
V_221 . V_23 . type = V_24 ;
V_221 . V_23 . V_9 = V_25 ;
V_221 . V_23 . V_10 = V_175 ;
V_221 . V_23 . V_11 = F_10 ( & V_5 -> V_12 ) ;
V_221 . V_224 = 1 ;
V_223 = 0 ;
for ( V_214 = V_213 -> V_215 ; V_214 ; V_214 = V_214 -> V_187 ) {
if ( V_214 -> V_225 )
continue;
V_214 -> V_225 = 1 ;
memcpy ( & V_221 . V_226 [ V_223 * V_220 ] ,
V_214 -> V_33 , V_220 ) ;
if ( ++ V_223 == V_227 ) {
V_221 . V_228 = V_223 ;
( void ) F_16 ( & V_5 -> V_12 , & V_221 ,
sizeof( V_221 ) ) ;
V_223 = 0 ;
}
}
if ( V_223 ) {
V_221 . V_228 = V_223 ;
( void ) F_16 ( & V_5 -> V_12 , & V_221 , sizeof( V_221 ) ) ;
}
V_221 . V_224 = 0 ;
V_223 = 0 ;
V_222 = & V_213 -> V_215 ;
while ( ( V_214 = * V_222 ) != NULL ) {
if ( V_214 -> V_218 ) {
V_214 -> V_218 = 0 ;
V_222 = & V_214 -> V_187 ;
continue;
}
memcpy ( & V_221 . V_226 [ V_223 * V_220 ] ,
V_214 -> V_33 , V_220 ) ;
if ( ++ V_223 == V_227 ) {
V_221 . V_228 = V_223 ;
( void ) F_16 ( & V_5 -> V_12 , & V_221 ,
sizeof( V_221 ) ) ;
V_223 = 0 ;
}
* V_222 = V_214 -> V_187 ;
F_144 ( V_214 ) ;
}
if ( V_223 ) {
V_221 . V_228 = V_223 ;
( void ) F_16 ( & V_5 -> V_12 , & V_221 , sizeof( V_221 ) ) ;
}
}
void F_145 ( struct V_16 * V_17 , struct V_166 * V_213 )
{
struct V_4 * V_5 ;
F_146 () ;
F_147 (port, &vp->port_list, list) {
if ( V_5 -> V_110 ) {
F_140 ( V_213 , V_17 ) ;
F_143 ( V_213 , V_5 ) ;
break;
}
}
F_148 () ;
}
int F_149 ( struct V_16 * V_17 , void * V_229 )
{
return - V_230 ;
}
void F_150 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_21 ;
V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
if ( ! V_2 -> V_231 )
return;
for ( V_21 = 0 ; V_21 < V_3 ; V_21 ++ ) {
struct V_84 * V_185 ;
void * V_62 = V_5 -> V_186 [ V_21 ] . V_62 ;
if ( ! V_62 )
continue;
V_185 = F_72 ( V_2 , V_21 ) ;
F_105 ( V_5 -> V_12 . V_13 ,
V_5 -> V_186 [ V_21 ] . V_97 ,
V_5 -> V_186 [ V_21 ] . V_98 ) ;
F_107 ( V_62 ) ;
V_5 -> V_186 [ V_21 ] . V_62 = NULL ;
V_185 -> V_118 . V_125 = V_188 ;
}
F_151 ( V_5 -> V_12 . V_13 , V_2 -> V_231 ,
( V_2 -> V_137 * V_2 -> V_232 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
V_2 -> V_231 = NULL ;
V_2 -> V_137 = 0 ;
V_2 -> V_232 = 0 ;
V_2 -> V_183 = 0 ;
V_2 -> V_98 = 0 ;
}
static void F_88 ( struct V_4 * V_5 )
{
F_110 ( & V_5 -> V_191 ) ;
F_150 ( V_5 ) ;
V_5 -> V_36 = 0 ;
V_5 -> V_43 = ( V_5 -> V_233 == 0 ) ;
V_5 -> V_45 = 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_61 , V_234 ;
int V_21 , V_22 , V_98 ;
void * V_235 ;
V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
V_234 = sizeof( struct V_84 ) +
sizeof( struct V_195 ) * 2 ;
if ( F_14 ( & V_5 -> V_12 , 1 , 7 ) )
V_234 += sizeof( struct V_101 ) ;
V_61 = V_3 * V_234 ;
V_98 = V_236 ;
V_235 = F_152 ( V_5 -> V_12 . V_13 , V_61 ,
V_2 -> V_97 , & V_98 ,
( V_237 |
V_238 |
V_239 ) ) ;
if ( F_57 ( V_235 ) ) {
V_22 = F_58 ( V_235 ) ;
goto V_240;
}
V_2 -> V_231 = V_235 ;
V_2 -> V_137 = V_234 ;
V_2 -> V_232 = V_3 ;
V_2 -> V_159 = 0 ;
V_2 -> V_157 = 0 ;
V_5 -> V_162 = true ;
V_2 -> V_183 = V_3 ;
V_2 -> V_98 = V_98 ;
for ( V_21 = 0 ; V_21 < V_3 ; ++ V_21 ) {
struct V_84 * V_185 ;
V_185 = F_72 ( V_2 , V_21 ) ;
V_185 -> V_118 . V_125 = V_188 ;
}
return 0 ;
V_240:
F_150 ( V_5 ) ;
return V_22 ;
}
void F_153 ( struct V_16 * V_17 , struct V_166 * V_213 )
{
struct V_4 * V_5 ;
unsigned long V_103 ;
F_154 ( & V_213 -> V_241 , V_103 ) ;
if ( ! F_155 ( & V_213 -> V_242 ) ) {
V_5 = F_156 ( V_213 -> V_242 . V_187 , struct V_4 , V_243 ) ;
F_100 ( & V_5 -> V_113 ) ;
}
F_157 ( & V_213 -> V_241 , V_103 ) ;
}
void F_158 ( struct V_4 * V_5 )
{
struct V_166 * V_213 = V_5 -> V_213 ;
int V_244 ;
V_244 = V_213 -> V_245 ++ ;
V_244 = V_244 & ( V_246 - 1 ) ;
V_5 -> V_163 = V_244 ;
F_83 ( F_74 ( F_8 ( V_5 ) ,
V_5 -> V_163 ) ) ;
}
void F_159 ( struct V_4 * V_5 )
{
V_5 -> V_213 -> V_245 -- ;
F_160 ( F_74 ( F_8 ( V_5 ) ,
V_5 -> V_163 ) ) ;
}
