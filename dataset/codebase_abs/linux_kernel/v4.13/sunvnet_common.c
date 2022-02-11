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
if ( F_24 ( F_45 ( F_46 ( V_62 ) -> V_111 ) ) )
V_17 -> V_91 . V_112 ++ ;
V_17 -> V_91 . V_113 ++ ;
V_17 -> V_91 . V_114 += V_61 ;
V_5 -> V_91 . V_113 ++ ;
V_5 -> V_91 . V_114 += V_61 ;
F_47 ( & V_5 -> V_115 , V_62 ) ;
return 0 ;
V_100:
F_48 ( V_62 ) ;
V_93:
V_17 -> V_91 . V_116 ++ ;
return V_22 ;
}
static int F_49 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_117 , T_1 V_118 , T_2 V_1 )
{
struct V_119 V_120 = {
. V_23 = {
. type = V_121 ,
. V_9 = V_54 ,
. V_10 = V_122 ,
. V_11 = F_10 ( & V_5 -> V_12 ) ,
} ,
. V_123 = V_2 -> V_124 ,
. V_125 = V_117 ,
. V_126 = V_118 ,
. V_127 = V_1 ,
} ;
int V_22 , V_128 ;
int V_129 = 0 ;
V_120 . V_130 = V_2 -> V_58 ;
V_128 = 1 ;
do {
V_22 = F_16 ( & V_5 -> V_12 , & V_120 , sizeof( V_120 ) ) ;
if ( V_22 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_50 ( V_128 ) ;
if ( ( V_128 <<= 1 ) > 128 )
V_128 = 128 ;
if ( V_129 ++ > V_131 ) {
F_51 ( L_14 ,
V_5 -> V_132 [ 0 ] , V_5 -> V_132 [ 1 ] ,
V_5 -> V_132 [ 2 ] , V_5 -> V_132 [ 3 ] ,
V_5 -> V_132 [ 4 ] , V_5 -> V_132 [ 5 ] ) ;
break;
}
} while ( V_22 == - V_133 );
if ( V_22 <= 0 && V_1 == V_134 ) {
V_5 -> V_135 = V_118 ;
V_5 -> V_136 = true ;
} else {
V_5 -> V_135 = 0 ;
V_5 -> V_136 = false ;
}
return V_22 ;
}
static struct V_84 * F_52 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_137 )
{
struct V_84 * V_85 = V_5 -> V_12 . V_138 ;
int V_22 ;
V_22 = F_53 ( V_5 -> V_12 . V_13 , V_85 , V_2 -> V_139 ,
( V_137 * V_2 -> V_139 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
if ( V_22 < 0 )
return F_54 ( V_22 ) ;
return V_85 ;
}
static int F_55 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_84 * V_85 ,
T_1 V_137 )
{
int V_22 ;
V_22 = F_56 ( V_5 -> V_12 . V_13 , V_85 , V_2 -> V_139 ,
( V_137 * V_2 -> V_139 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
if ( V_22 < 0 )
return V_22 ;
return 0 ;
}
static int F_57 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_137 , int * V_140 )
{
struct V_84 * V_85 = F_52 ( V_5 , V_2 , V_137 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_22 ;
F_58 ( ! V_85 ) ;
if ( F_59 ( V_85 ) )
return F_60 ( V_85 ) ;
if ( V_85 -> V_120 . V_127 != V_141 )
return 1 ;
F_61 () ;
F_15 ( V_142 , L_15 ,
V_85 -> V_120 . V_127 , V_85 -> V_120 . V_143 ,
V_85 -> V_86 , V_85 -> V_98 ,
V_85 -> V_97 [ 0 ] . V_144 ,
V_85 -> V_97 [ 0 ] . V_145 ) ;
V_22 = F_34 ( V_5 , V_85 ) ;
if ( V_22 == - V_14 )
return V_22 ;
F_62 ( V_5 -> V_12 . V_146 , V_5 -> V_12 . V_147 ,
V_137 , V_85 -> V_120 . V_143 ) ;
V_85 -> V_120 . V_127 = V_148 ;
V_22 = F_55 ( V_5 , V_2 , V_85 , V_137 ) ;
if ( V_22 < 0 )
return V_22 ;
* V_140 = V_85 -> V_120 . V_143 ;
return 0 ;
}
static int F_63 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_117 , T_1 V_118 , int * V_149 , int V_150 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_151 = - 1 , V_152 = - 1 ;
bool V_153 = true ;
V_118 = ( V_118 == ( T_1 ) - 1 ) ? F_64 ( V_2 , V_117 )
: F_65 ( V_2 , V_118 ) ;
F_15 ( V_142 , L_16 , V_117 , V_118 ) ;
while ( V_117 != V_118 ) {
int V_143 = 0 , V_22 = F_57 ( V_5 , V_2 , V_117 , & V_143 ) ;
if ( V_22 == - V_14 )
return V_22 ;
if ( V_22 != 0 )
break;
( * V_149 ) ++ ;
if ( V_151 == - 1 )
V_151 = V_117 ;
V_152 = V_117 ;
V_117 = F_65 ( V_2 , V_117 ) ;
if ( V_143 && V_117 != V_118 ) {
V_22 = F_49 ( V_5 , V_2 , V_151 , V_152 ,
V_154 ) ;
if ( V_22 == - V_14 )
return V_22 ;
V_151 = - 1 ;
}
if ( ( * V_149 ) >= V_150 ) {
V_153 = false ;
break;
}
}
if ( F_24 ( V_151 == - 1 ) ) {
V_152 = F_64 ( V_2 , V_117 ) ;
V_151 = V_152 ;
}
if ( V_153 ) {
V_5 -> V_155 = false ;
F_66 ( V_5 -> V_12 . V_146 ,
V_5 -> V_12 . V_147 ,
V_152 , * V_149 ) ;
return F_49 ( V_5 , V_2 , V_151 , V_152 ,
V_134 ) ;
} else {
F_67 ( V_5 -> V_12 . V_146 ,
V_5 -> V_12 . V_147 ,
V_152 , * V_149 ) ;
V_5 -> V_155 = true ;
V_5 -> V_156 = V_152 ;
return 1 ;
}
}
static int F_68 ( struct V_4 * V_5 , void * V_157 , int * V_149 ,
int V_150 )
{
struct V_119 * V_8 = V_157 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_56 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_15 ( V_142 , L_17 ,
V_8 -> V_23 . V_10 , V_8 -> V_130 , V_2 -> V_57 ) ;
if ( F_24 ( V_8 -> V_23 . V_10 != V_122 ) )
return 0 ;
if ( F_24 ( V_8 -> V_130 != V_2 -> V_57 ) ) {
F_4 ( L_18 ,
V_8 -> V_130 , V_2 -> V_57 ) ;
return 0 ;
}
if ( ! V_5 -> V_155 )
V_2 -> V_57 ++ ;
return F_63 ( V_5 , V_2 , V_8 -> V_125 , V_8 -> V_126 ,
V_149 , V_150 ) ;
}
static int F_69 ( struct V_1 * V_2 , T_1 V_118 )
{
T_1 V_158 = V_2 -> V_159 ;
int V_160 = 0 ;
while ( V_158 != V_2 -> V_161 ) {
if ( V_158 == V_118 ) {
V_160 = 1 ;
break;
}
V_158 = F_65 ( V_2 , V_158 ) ;
}
return V_160 ;
}
static int F_70 ( struct V_4 * V_5 , void * V_157 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
struct V_119 * V_8 = V_157 ;
struct V_16 * V_17 ;
T_1 V_118 ;
struct V_84 * V_85 ;
struct V_162 * V_163 ;
if ( F_24 ( V_8 -> V_23 . V_10 != V_122 ) )
return 0 ;
V_118 = V_8 -> V_126 ;
V_17 = F_8 ( V_5 ) ;
F_71 ( V_17 ) ;
if ( F_24 ( ! F_69 ( V_2 , V_118 ) ) ) {
F_72 ( V_17 ) ;
return 0 ;
}
F_73 ( V_5 -> V_12 . V_146 ,
V_5 -> V_12 . V_147 , V_118 ) ;
V_2 -> V_159 = F_65 ( V_2 , V_118 ) ;
V_85 = F_74 ( V_2 , V_2 -> V_159 ) ;
if ( V_85 -> V_120 . V_127 == V_141 && ! V_5 -> V_164 ) {
if ( F_75 ( V_5 , V_2 -> V_159 ) > 0 )
V_5 -> V_164 = false ;
else
V_5 -> V_164 = true ;
} else {
V_5 -> V_164 = true ;
}
F_72 ( V_17 ) ;
V_163 = F_76 ( V_17 , V_5 -> V_165 ) ;
if ( F_24 ( F_77 ( V_163 ) &&
F_1 ( V_2 ) >= F_78 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_79 ( struct V_4 * V_5 , void * V_157 )
{
return 0 ;
}
static int F_80 ( struct V_4 * V_5 , void * V_157 )
{
struct V_166 * V_8 = V_157 ;
struct V_16 * V_17 = F_8 ( V_5 ) ;
if ( V_8 -> V_23 . V_9 != V_54 )
F_4 ( L_19 ,
V_17 -> V_167 ,
V_8 -> V_23 . type ,
V_8 -> V_23 . V_9 ,
V_8 -> V_23 . V_10 ,
V_8 -> V_23 . V_11 ) ;
return 0 ;
}
static void F_81 ( struct V_4 * V_5 )
{
struct V_162 * V_163 ;
V_163 = F_76 ( F_8 ( V_5 ) ,
V_5 -> V_165 ) ;
F_82 ( V_163 , F_83 () ) ;
if ( F_84 ( F_77 ( V_163 ) ) )
F_85 ( V_163 ) ;
F_86 ( V_163 ) ;
}
bool F_87 ( struct V_4 * V_168 )
{
struct V_15 * V_12 = & V_168 -> V_12 ;
return ! ! ( V_12 -> V_169 & V_170 ) ;
}
static int F_88 ( struct V_4 * V_5 , int V_150 )
{
struct V_16 * V_17 = F_8 ( V_5 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_171 , V_22 ;
int V_149 = 0 ;
F_58 ( V_5 -> V_172 & ~ ( V_173 |
V_174 |
V_175 ) ) ;
if ( V_5 -> V_172 & V_174 ) {
if ( V_5 -> V_176 == 1 ) {
F_89 ( V_17 ) ;
F_90 ( V_17 ) ;
}
F_91 ( V_12 , V_174 ) ;
F_92 ( V_5 ) ;
F_93 ( V_12 ) ;
if ( F_94 ( V_17 ) )
F_81 ( V_5 ) ;
V_5 -> V_172 = 0 ;
V_5 -> V_91 . V_177 ++ ;
return 0 ;
}
if ( V_5 -> V_172 & V_175 ) {
if ( V_5 -> V_176 == 1 ) {
F_95 ( V_5 -> V_17 ) ;
F_96 ( V_5 -> V_17 ) ;
}
F_91 ( V_12 , V_175 ) ;
V_5 -> V_172 = 0 ;
V_5 -> V_91 . V_178 ++ ;
return 0 ;
}
V_22 = 0 ;
V_171 = 0 ;
while ( 1 ) {
union {
struct V_7 V_23 ;
V_34 V_179 [ 8 ] ;
} V_157 ;
if ( V_5 -> V_155 ) {
struct V_119 * V_8 =
(struct V_119 * ) & V_157 ;
struct V_1 * V_2 =
& V_5 -> V_12 . V_55 [ V_56 ] ;
V_8 -> V_23 . type = V_121 ;
V_8 -> V_23 . V_9 = V_25 ;
V_8 -> V_23 . V_10 = V_122 ;
V_8 -> V_130 = V_2 -> V_57 ;
V_8 -> V_125 = F_65 ( V_2 ,
V_5 -> V_156 ) ;
V_8 -> V_126 = - 1 ;
} else {
V_22 = F_97 ( V_12 -> V_13 , & V_157 , sizeof( V_157 ) ) ;
if ( F_24 ( V_22 < 0 ) ) {
if ( V_22 == - V_14 )
F_98 ( V_12 ) ;
break;
}
if ( V_22 == 0 )
break;
F_15 ( V_142 , L_20 ,
V_157 . V_23 . type ,
V_157 . V_23 . V_9 ,
V_157 . V_23 . V_10 ,
V_157 . V_23 . V_11 ) ;
V_22 = F_99 ( V_12 , & V_157 . V_23 ) ;
if ( V_22 < 0 )
break;
}
if ( F_84 ( V_157 . V_23 . type == V_121 ) ) {
if ( V_157 . V_23 . V_9 == V_25 ) {
if ( ! F_87 ( V_5 ) ) {
V_22 = - V_14 ;
break;
}
V_22 = F_68 ( V_5 , & V_157 , & V_149 , V_150 ) ;
if ( V_149 >= V_150 )
break;
if ( V_149 == 0 )
break;
} else if ( V_157 . V_23 . V_9 == V_54 ) {
V_22 = F_70 ( V_5 , & V_157 ) ;
if ( V_22 > 0 )
V_171 |= V_22 ;
} else if ( V_157 . V_23 . V_9 == V_53 ) {
V_22 = F_79 ( V_5 , & V_157 ) ;
}
} else if ( V_157 . V_23 . type == V_24 ) {
if ( V_157 . V_23 . V_10 == V_180 )
V_22 = F_80 ( V_5 , & V_157 ) ;
else
V_22 = F_100 ( V_12 , & V_157 ) ;
if ( V_22 )
break;
} else {
V_22 = F_3 ( V_5 , & V_157 ) ;
}
if ( V_22 == - V_14 )
break;
}
if ( F_24 ( V_171 && V_22 != - V_14 ) )
F_81 ( V_5 ) ;
return V_149 ;
}
int F_101 ( struct V_181 * V_115 , int V_150 )
{
struct V_4 * V_5 = F_102 ( V_115 , struct V_4 , V_115 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_182 = F_88 ( V_5 , V_150 ) ;
if ( V_182 < V_150 ) {
F_103 ( V_115 , V_182 ) ;
V_5 -> V_172 &= ~ V_173 ;
F_104 ( V_12 -> V_183 -> V_184 , V_185 ) ;
}
return V_182 ;
}
void F_105 ( void * V_6 , int V_186 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
V_5 -> V_172 |= V_186 ;
F_104 ( V_12 -> V_183 -> V_184 , V_187 ) ;
F_106 ( & V_5 -> V_115 ) ;
}
static int F_75 ( struct V_4 * V_5 , T_1 V_117 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
struct V_119 V_120 = {
. V_23 = {
. type = V_121 ,
. V_9 = V_25 ,
. V_10 = V_122 ,
. V_11 = F_10 ( & V_5 -> V_12 ) ,
} ,
. V_123 = V_2 -> V_124 ,
. V_125 = V_117 ,
. V_126 = ( T_1 ) - 1 ,
} ;
int V_22 , V_128 ;
int V_129 = 0 ;
if ( V_5 -> V_136 ) {
F_107 ( V_5 -> V_12 . V_146 ,
V_5 -> V_12 . V_147 ,
V_5 -> V_135 , - 1 ) ;
V_22 = F_49 ( V_5 ,
& V_5 -> V_12 . V_55 [ V_56 ] ,
V_5 -> V_135 , - 1 ,
V_134 ) ;
if ( V_22 <= 0 )
return V_22 ;
}
V_120 . V_130 = V_2 -> V_58 ;
V_128 = 1 ;
do {
V_22 = F_16 ( & V_5 -> V_12 , & V_120 , sizeof( V_120 ) ) ;
if ( V_22 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_50 ( V_128 ) ;
if ( ( V_128 <<= 1 ) > 128 )
V_128 = 128 ;
if ( V_129 ++ > V_131 )
break;
} while ( V_22 == - V_133 );
F_108 ( V_5 -> V_12 . V_146 ,
V_5 -> V_12 . V_147 , V_117 , V_22 ) ;
return V_22 ;
}
static struct V_60 * F_109 ( struct V_4 * V_5 ,
unsigned * V_188 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
struct V_60 * V_62 = NULL ;
int V_21 , V_189 ;
* V_188 = 0 ;
V_189 = V_2 -> V_161 ;
for ( V_21 = 0 ; V_21 < V_3 ; ++ V_21 ) {
struct V_84 * V_190 ;
-- V_189 ;
if ( V_189 < 0 )
V_189 = V_3 - 1 ;
V_190 = F_74 ( V_2 , V_189 ) ;
if ( V_190 -> V_120 . V_127 == V_141 ) {
( * V_188 ) ++ ;
continue;
}
if ( V_5 -> V_191 [ V_189 ] . V_62 ) {
if ( V_190 -> V_120 . V_127 != V_148 )
F_110 ( L_21 ,
V_190 -> V_120 . V_127 ) ;
F_58 ( V_5 -> V_191 [ V_189 ] . V_62 -> V_192 ) ;
V_5 -> V_191 [ V_189 ] . V_62 -> V_192 = V_62 ;
V_62 = V_5 -> V_191 [ V_189 ] . V_62 ;
V_5 -> V_191 [ V_189 ] . V_62 = NULL ;
F_111 ( V_5 -> V_12 . V_13 ,
V_5 -> V_191 [ V_189 ] . V_97 ,
V_5 -> V_191 [ V_189 ] . V_98 ) ;
} else if ( V_190 -> V_120 . V_127 == V_193 ) {
break;
}
V_190 -> V_120 . V_127 = V_193 ;
}
return V_62 ;
}
static inline void F_112 ( struct V_60 * V_62 )
{
struct V_60 * V_192 ;
while ( V_62 ) {
V_192 = V_62 -> V_192 ;
V_62 -> V_192 = NULL ;
F_113 ( V_62 ) ;
V_62 = V_192 ;
}
}
void F_114 ( unsigned long V_194 )
{
struct V_4 * V_5 = (struct V_4 * ) V_194 ;
struct V_60 * V_195 ;
unsigned V_188 ;
F_71 ( F_8 ( V_5 ) ) ;
V_195 = F_109 ( V_5 , & V_188 ) ;
F_72 ( F_8 ( V_5 ) ) ;
F_112 ( V_195 ) ;
if ( V_188 )
( void ) F_115 ( & V_5 -> V_196 ,
V_197 + V_198 ) ;
else
F_116 ( & V_5 -> V_196 ) ;
}
static inline int F_117 ( struct V_199 * V_13 , struct V_60 * V_62 ,
struct V_200 * V_97 , int V_98 ,
unsigned int V_201 )
{
int V_21 , V_202 , V_22 , V_203 ;
V_203 = F_118 ( V_62 ) ;
if ( V_203 < V_90 )
V_203 = V_90 ;
V_203 += V_64 ;
V_203 += 8 - ( V_203 & 7 ) ;
V_22 = F_119 ( V_13 , V_62 -> V_65 - V_64 , V_203 , V_97 ,
V_98 , V_201 ) ;
if ( V_22 < 0 )
return V_22 ;
V_202 = V_22 ;
for ( V_21 = 0 ; V_21 < F_120 ( V_62 ) -> V_204 ; V_21 ++ ) {
T_3 * V_205 = & F_120 ( V_62 ) -> V_206 [ V_21 ] ;
T_2 * V_207 ;
if ( V_202 < V_98 ) {
V_207 = F_121 ( F_122 ( V_205 ) ) ;
V_203 = F_123 ( V_205 ) ;
V_203 += 8 - ( V_203 & 7 ) ;
V_22 = F_119 ( V_13 , V_207 + V_205 -> V_208 ,
V_203 , V_97 + V_202 , V_98 - V_202 ,
V_201 ) ;
F_124 ( V_207 ) ;
} else {
V_22 = - V_89 ;
}
if ( V_22 < 0 ) {
F_111 ( V_13 , V_97 , V_202 ) ;
return V_22 ;
}
V_202 += V_22 ;
}
return V_202 ;
}
static inline struct V_60 * F_125 ( struct V_60 * V_62 , int V_98 )
{
struct V_60 * V_209 ;
int V_21 , V_61 , V_210 , V_211 ;
V_61 = V_62 -> V_61 ;
V_210 = 0 ;
if ( V_61 < V_90 ) {
V_210 += V_90 - V_62 -> V_61 ;
V_61 += V_210 ;
}
V_61 += V_64 ;
V_210 += 8 - ( V_61 & 7 ) ;
V_211 = F_120 ( V_62 ) -> V_204 >= V_98 ;
for ( V_21 = 0 ; V_21 < F_120 ( V_62 ) -> V_204 ; V_21 ++ ) {
T_3 * V_205 = & F_120 ( V_62 ) -> V_206 [ V_21 ] ;
V_211 |= V_205 -> V_208 & 7 ;
}
if ( ( ( unsigned long ) V_62 -> V_65 & 7 ) != V_64 ||
F_126 ( V_62 ) < V_210 ||
F_127 ( V_62 ) < V_64 || V_211 ) {
int V_117 = 0 , V_68 ;
T_4 V_76 ;
V_61 = V_62 -> V_61 > V_90 ? V_62 -> V_61 : V_90 ;
V_209 = F_22 ( V_62 -> V_17 , V_61 ) ;
if ( ! V_209 ) {
F_113 ( V_62 ) ;
return NULL ;
}
F_25 ( V_209 , V_64 ) ;
V_209 -> V_69 = V_62 -> V_69 ;
V_68 = F_128 ( V_62 ) - V_62 -> V_65 ;
F_129 ( V_209 , V_68 ) ;
V_68 = F_130 ( V_62 ) - V_62 -> V_65 ;
F_131 ( V_209 , V_68 ) ;
V_68 = F_132 ( V_62 ) - V_62 -> V_65 ;
F_44 ( V_209 , V_68 ) ;
V_68 = 0 ;
V_209 -> V_212 = V_62 -> V_212 ;
V_209 -> V_73 = V_62 -> V_73 ;
if ( V_62 -> V_73 == V_108 )
V_117 = F_133 ( V_62 ) ;
if ( V_117 ) {
struct V_66 * V_67 = F_27 ( V_209 ) ;
int V_68 = V_117 + V_209 -> V_212 ;
if ( F_134 ( V_62 , 0 , V_209 -> V_65 , V_117 ) ) {
F_113 ( V_209 ) ;
F_113 ( V_62 ) ;
return NULL ;
}
* ( V_213 * ) ( V_62 -> V_65 + V_68 ) = 0 ;
V_76 = F_135 ( V_62 , V_117 ,
V_209 -> V_65 + V_117 ,
V_62 -> V_61 - V_117 , 0 ) ;
if ( V_67 -> V_69 == V_71 ||
V_67 -> V_69 == V_72 ) {
V_76 = F_32 ( V_67 -> V_80 , V_67 -> V_81 ,
V_62 -> V_61 - V_117 ,
V_67 -> V_69 , V_76 ) ;
}
* ( V_213 * ) ( V_209 -> V_65 + V_68 ) = V_76 ;
V_209 -> V_73 = V_74 ;
} else if ( F_134 ( V_62 , 0 , V_209 -> V_65 , V_62 -> V_61 ) ) {
F_113 ( V_209 ) ;
F_113 ( V_62 ) ;
return NULL ;
}
( void ) F_35 ( V_209 , V_62 -> V_61 ) ;
if ( F_136 ( V_62 ) ) {
F_120 ( V_209 ) -> V_214 = F_120 ( V_62 ) -> V_214 ;
F_120 ( V_209 ) -> V_215 = F_120 ( V_62 ) -> V_215 ;
}
V_209 -> V_216 = V_62 -> V_216 ;
F_113 ( V_62 ) ;
V_62 = V_209 ;
}
return V_62 ;
}
void F_137 ( struct V_16 * V_17 )
{
}
int F_138 ( struct V_16 * V_17 )
{
F_95 ( V_17 ) ;
F_96 ( V_17 ) ;
return 0 ;
}
int F_139 ( struct V_16 * V_17 )
{
F_89 ( V_17 ) ;
F_90 ( V_17 ) ;
return 0 ;
}
static struct V_217 * F_140 ( struct V_168 * V_218 , T_2 * V_33 )
{
struct V_217 * V_219 ;
for ( V_219 = V_218 -> V_220 ; V_219 ; V_219 = V_219 -> V_192 ) {
if ( F_141 ( V_219 -> V_33 , V_33 ) )
return V_219 ;
}
return NULL ;
}
static void F_142 ( struct V_168 * V_218 , struct V_16 * V_17 )
{
struct V_221 * V_222 ;
F_143 (ha, dev) {
struct V_217 * V_219 ;
V_219 = F_140 ( V_218 , V_222 -> V_33 ) ;
if ( V_219 ) {
V_219 -> V_223 = 1 ;
continue;
}
if ( ! V_219 ) {
V_219 = F_144 ( sizeof( * V_219 ) , V_224 ) ;
if ( ! V_219 )
continue;
memcpy ( V_219 -> V_33 , V_222 -> V_33 , V_225 ) ;
V_219 -> V_223 = 1 ;
V_219 -> V_192 = V_218 -> V_220 ;
V_218 -> V_220 = V_219 ;
}
}
}
static void F_145 ( struct V_168 * V_218 , struct V_4 * V_5 )
{
struct V_166 V_226 ;
struct V_217 * V_219 , * * V_227 ;
int V_228 ;
memset ( & V_226 , 0 , sizeof( V_226 ) ) ;
V_226 . V_23 . type = V_24 ;
V_226 . V_23 . V_9 = V_25 ;
V_226 . V_23 . V_10 = V_180 ;
V_226 . V_23 . V_11 = F_10 ( & V_5 -> V_12 ) ;
V_226 . V_229 = 1 ;
V_228 = 0 ;
for ( V_219 = V_218 -> V_220 ; V_219 ; V_219 = V_219 -> V_192 ) {
if ( V_219 -> V_230 )
continue;
V_219 -> V_230 = 1 ;
memcpy ( & V_226 . V_231 [ V_228 * V_225 ] ,
V_219 -> V_33 , V_225 ) ;
if ( ++ V_228 == V_232 ) {
V_226 . V_233 = V_228 ;
( void ) F_16 ( & V_5 -> V_12 , & V_226 ,
sizeof( V_226 ) ) ;
V_228 = 0 ;
}
}
if ( V_228 ) {
V_226 . V_233 = V_228 ;
( void ) F_16 ( & V_5 -> V_12 , & V_226 , sizeof( V_226 ) ) ;
}
V_226 . V_229 = 0 ;
V_228 = 0 ;
V_227 = & V_218 -> V_220 ;
while ( ( V_219 = * V_227 ) != NULL ) {
if ( V_219 -> V_223 ) {
V_219 -> V_223 = 0 ;
V_227 = & V_219 -> V_192 ;
continue;
}
memcpy ( & V_226 . V_231 [ V_228 * V_225 ] ,
V_219 -> V_33 , V_225 ) ;
if ( ++ V_228 == V_232 ) {
V_226 . V_233 = V_228 ;
( void ) F_16 ( & V_5 -> V_12 , & V_226 ,
sizeof( V_226 ) ) ;
V_228 = 0 ;
}
* V_227 = V_219 -> V_192 ;
F_146 ( V_219 ) ;
}
if ( V_228 ) {
V_226 . V_233 = V_228 ;
( void ) F_16 ( & V_5 -> V_12 , & V_226 , sizeof( V_226 ) ) ;
}
}
void F_147 ( struct V_16 * V_17 , struct V_168 * V_218 )
{
struct V_4 * V_5 ;
F_148 () ;
F_149 (port, &vp->port_list, list) {
if ( V_5 -> V_110 ) {
F_142 ( V_218 , V_17 ) ;
F_145 ( V_218 , V_5 ) ;
break;
}
}
F_150 () ;
}
int F_151 ( struct V_16 * V_17 , void * V_234 )
{
return - V_235 ;
}
void F_152 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_21 ;
V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
if ( ! V_2 -> V_236 )
return;
for ( V_21 = 0 ; V_21 < V_3 ; V_21 ++ ) {
struct V_84 * V_190 ;
void * V_62 = V_5 -> V_191 [ V_21 ] . V_62 ;
if ( ! V_62 )
continue;
V_190 = F_74 ( V_2 , V_21 ) ;
F_111 ( V_5 -> V_12 . V_13 ,
V_5 -> V_191 [ V_21 ] . V_97 ,
V_5 -> V_191 [ V_21 ] . V_98 ) ;
F_113 ( V_62 ) ;
V_5 -> V_191 [ V_21 ] . V_62 = NULL ;
V_190 -> V_120 . V_127 = V_193 ;
}
F_153 ( V_5 -> V_12 . V_13 , V_2 -> V_236 ,
( V_2 -> V_139 * V_2 -> V_237 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
V_2 -> V_236 = NULL ;
V_2 -> V_139 = 0 ;
V_2 -> V_237 = 0 ;
V_2 -> V_188 = 0 ;
V_2 -> V_98 = 0 ;
}
void F_92 ( struct V_4 * V_5 )
{
F_116 ( & V_5 -> V_196 ) ;
F_152 ( V_5 ) ;
V_5 -> V_36 = 0 ;
V_5 -> V_43 = ( V_5 -> V_176 == 0 ) ;
V_5 -> V_45 = 0 ;
}
static int F_9 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_61 , V_238 ;
int V_21 , V_22 , V_98 ;
void * V_239 ;
V_2 = & V_5 -> V_12 . V_55 [ V_59 ] ;
V_238 = sizeof( struct V_84 ) +
sizeof( struct V_200 ) * 2 ;
if ( F_14 ( & V_5 -> V_12 , 1 , 7 ) )
V_238 += sizeof( struct V_101 ) ;
V_61 = V_3 * V_238 ;
V_98 = V_240 ;
V_239 = F_154 ( V_5 -> V_12 . V_13 , V_61 ,
V_2 -> V_97 , & V_98 ,
( V_241 |
V_242 |
V_243 ) ) ;
if ( F_59 ( V_239 ) ) {
V_22 = F_60 ( V_239 ) ;
goto V_244;
}
V_2 -> V_236 = V_239 ;
V_2 -> V_139 = V_238 ;
V_2 -> V_237 = V_3 ;
V_2 -> V_161 = 0 ;
V_2 -> V_159 = 0 ;
V_5 -> V_164 = true ;
V_2 -> V_188 = V_3 ;
V_2 -> V_98 = V_98 ;
for ( V_21 = 0 ; V_21 < V_3 ; ++ V_21 ) {
struct V_84 * V_190 ;
V_190 = F_74 ( V_2 , V_21 ) ;
V_190 -> V_120 . V_127 = V_193 ;
}
return 0 ;
V_244:
F_152 ( V_5 ) ;
return V_22 ;
}
void F_155 ( struct V_16 * V_17 , struct V_168 * V_218 )
{
struct V_4 * V_5 ;
unsigned long V_103 ;
F_156 ( & V_218 -> V_245 , V_103 ) ;
if ( ! F_157 ( & V_218 -> V_246 ) ) {
V_5 = F_158 ( V_218 -> V_246 . V_192 , struct V_4 , V_247 ) ;
F_106 ( & V_5 -> V_115 ) ;
}
F_159 ( & V_218 -> V_245 , V_103 ) ;
}
void F_160 ( struct V_4 * V_5 )
{
struct V_168 * V_218 = V_5 -> V_218 ;
int V_248 = 0 ;
int V_21 ;
for ( V_21 = 0 ; V_21 < V_249 ; V_21 ++ ) {
if ( V_218 -> V_250 [ V_21 ] == 0 ) {
V_248 = V_21 ;
break;
}
if ( V_218 -> V_250 [ V_21 ] < V_218 -> V_250 [ V_248 ] )
V_248 = V_21 ;
}
V_218 -> V_251 ++ ;
V_218 -> V_250 [ V_248 ] ++ ;
V_5 -> V_165 = V_248 ;
}
void F_161 ( struct V_4 * V_5 )
{
V_5 -> V_218 -> V_251 -- ;
V_5 -> V_218 -> V_250 [ V_5 -> V_165 ] -- ;
V_5 -> V_165 = 0 ;
}
