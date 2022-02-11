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
if ( V_103 -> V_104 & V_105 ) {
if ( V_63 -> V_70 == V_71 ) {
struct V_67 * V_68 = (struct V_67 * ) V_63 -> V_66 ;
V_68 -> V_80 = 0 ;
F_40 ( V_68 ) ;
}
}
if ( ( V_103 -> V_104 & V_106 ) &&
V_63 -> V_74 == V_75 )
F_25 ( V_63 ) ;
if ( V_103 -> V_104 & V_107 ) {
V_63 -> V_74 = V_108 ;
V_63 -> V_76 = 0 ;
if ( V_103 -> V_104 & V_109 )
V_63 -> V_76 = 1 ;
}
}
V_63 -> V_74 = V_5 -> V_110 ? V_75 : V_108 ;
V_17 -> V_92 . V_111 ++ ;
V_17 -> V_92 . V_112 += V_62 ;
F_41 ( & V_5 -> V_113 , V_63 ) ;
return 0 ;
V_101:
F_42 ( V_63 ) ;
V_94:
V_17 -> V_92 . V_114 ++ ;
return V_23 ;
}
static int F_43 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_115 , T_1 V_116 , T_2 V_1 )
{
struct V_117 V_118 = {
. V_24 = {
. type = V_119 ,
. V_9 = V_55 ,
. V_10 = V_120 ,
. V_11 = F_9 ( & V_5 -> V_12 ) ,
} ,
. V_121 = V_2 -> V_122 ,
. V_123 = V_115 ,
. V_124 = V_116 ,
. V_125 = V_1 ,
} ;
int V_23 , V_126 ;
int V_127 = 0 ;
V_118 . V_128 = V_2 -> V_58 ;
V_126 = 1 ;
do {
V_23 = F_15 ( & V_5 -> V_12 , & V_118 , sizeof( V_118 ) ) ;
if ( V_23 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_44 ( V_126 ) ;
if ( ( V_126 <<= 1 ) > 128 )
V_126 = 128 ;
if ( V_127 ++ > V_129 ) {
F_45 ( L_14 ,
V_5 -> V_130 [ 0 ] , V_5 -> V_130 [ 1 ] ,
V_5 -> V_130 [ 2 ] , V_5 -> V_130 [ 3 ] ,
V_5 -> V_130 [ 4 ] , V_5 -> V_130 [ 5 ] ) ;
break;
}
} while ( V_23 == - V_131 );
if ( V_23 <= 0 && V_1 == V_132 ) {
V_5 -> V_133 = V_116 ;
V_5 -> V_134 = true ;
} else {
V_5 -> V_133 = 0 ;
V_5 -> V_134 = false ;
}
return V_23 ;
}
static struct V_85 * F_46 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_135 )
{
struct V_85 * V_86 = V_5 -> V_12 . V_136 ;
int V_23 ;
V_23 = F_47 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_137 ,
( V_135 * V_2 -> V_137 ) ,
V_2 -> V_98 , V_2 -> V_99 ) ;
if ( V_23 < 0 )
return F_48 ( V_23 ) ;
return V_86 ;
}
static int F_49 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_1 V_135 )
{
int V_23 ;
V_23 = F_50 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_137 ,
( V_135 * V_2 -> V_137 ) ,
V_2 -> V_98 , V_2 -> V_99 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_135 , int * V_138 )
{
struct V_85 * V_86 = F_46 ( V_5 , V_2 , V_135 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_23 ;
F_52 ( V_86 == NULL ) ;
if ( F_53 ( V_86 ) )
return F_54 ( V_86 ) ;
if ( V_86 -> V_118 . V_125 != V_139 )
return 1 ;
F_55 () ;
F_14 ( V_140 , L_15 ,
V_86 -> V_118 . V_125 , V_86 -> V_118 . V_141 ,
V_86 -> V_87 , V_86 -> V_99 ,
V_86 -> V_98 [ 0 ] . V_142 ,
V_86 -> V_98 [ 0 ] . V_143 ) ;
V_23 = F_33 ( V_5 , V_86 ) ;
if ( V_23 == - V_14 )
return V_23 ;
V_86 -> V_118 . V_125 = V_144 ;
V_23 = F_49 ( V_5 , V_2 , V_86 , V_135 ) ;
if ( V_23 < 0 )
return V_23 ;
* V_138 = V_86 -> V_118 . V_141 ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_115 , T_1 V_116 , int * V_145 , int V_146 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_147 = - 1 , V_148 = - 1 ;
bool V_149 = true ;
V_116 = ( V_116 == ( T_1 ) - 1 ) ? F_57 ( V_2 , V_115 )
: F_58 ( V_2 , V_116 ) ;
F_14 ( V_140 , L_16 , V_115 , V_116 ) ;
while ( V_115 != V_116 ) {
int V_141 = 0 , V_23 = F_51 ( V_5 , V_2 , V_115 , & V_141 ) ;
if ( V_23 == - V_14 )
return V_23 ;
if ( V_23 != 0 )
break;
( * V_145 ) ++ ;
if ( V_147 == - 1 )
V_147 = V_115 ;
V_148 = V_115 ;
V_115 = F_58 ( V_2 , V_115 ) ;
if ( V_141 && V_115 != V_116 ) {
V_23 = F_43 ( V_5 , V_2 , V_147 , V_148 ,
V_150 ) ;
if ( V_23 == - V_14 )
return V_23 ;
V_147 = - 1 ;
}
if ( ( * V_145 ) >= V_146 ) {
V_149 = false ;
break;
}
}
if ( F_23 ( V_147 == - 1 ) )
V_147 = V_148 = F_57 ( V_2 , V_115 ) ;
if ( V_149 ) {
V_5 -> V_151 = false ;
return F_43 ( V_5 , V_2 , V_147 , V_148 ,
V_132 ) ;
} else {
V_5 -> V_151 = true ;
V_5 -> V_152 = V_148 ;
return 1 ;
}
}
static int F_59 ( struct V_4 * V_5 , void * V_153 , int * V_145 ,
int V_146 )
{
struct V_117 * V_8 = V_153 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_57 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_14 ( V_140 , L_17 ,
V_8 -> V_24 . V_10 , V_8 -> V_128 , V_2 -> V_59 ) ;
if ( F_23 ( V_8 -> V_24 . V_10 != V_120 ) )
return 0 ;
if ( F_23 ( V_8 -> V_128 != V_2 -> V_59 ) ) {
F_4 ( L_18 ,
V_8 -> V_128 , V_2 -> V_59 ) ;
return 0 ;
}
if ( ! V_5 -> V_151 )
V_2 -> V_59 ++ ;
return F_56 ( V_5 , V_2 , V_8 -> V_123 , V_8 -> V_124 ,
V_145 , V_146 ) ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_116 )
{
T_1 V_154 = V_2 -> V_155 ;
int V_156 = 0 ;
while ( V_154 != V_2 -> V_157 ) {
if ( V_154 == V_116 ) {
V_156 = 1 ;
break;
}
V_154 = F_58 ( V_2 , V_154 ) ;
}
return V_156 ;
}
static int F_61 ( struct V_4 * V_5 , void * V_153 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_117 * V_8 = V_153 ;
struct V_16 * V_17 ;
struct V_158 * V_18 ;
T_1 V_116 ;
struct V_85 * V_86 ;
struct V_159 * V_160 ;
if ( F_23 ( V_8 -> V_24 . V_10 != V_120 ) )
return 0 ;
V_116 = V_8 -> V_124 ;
V_18 = V_5 -> V_18 ;
V_17 = V_18 -> V_17 ;
F_62 ( V_17 ) ;
if ( F_23 ( ! F_60 ( V_2 , V_116 ) ) ) {
F_63 ( V_17 ) ;
return 0 ;
}
V_2 -> V_155 = F_58 ( V_2 , V_116 ) ;
V_86 = F_64 ( V_2 , V_2 -> V_155 ) ;
if ( V_86 -> V_118 . V_125 == V_139 && ! V_5 -> V_161 ) {
if ( F_65 ( V_5 , V_2 -> V_155 ) > 0 )
V_5 -> V_161 = false ;
else
V_5 -> V_161 = true ;
} else {
V_5 -> V_161 = true ;
}
F_63 ( V_17 ) ;
V_160 = F_66 ( V_17 , V_5 -> V_162 ) ;
if ( F_23 ( F_67 ( V_160 ) &&
F_1 ( V_2 ) >= F_68 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , void * V_153 )
{
return 0 ;
}
static int F_70 ( struct V_4 * V_5 , void * V_153 )
{
struct V_163 * V_8 = V_153 ;
if ( V_8 -> V_24 . V_9 != V_55 )
F_4 ( L_19 ,
V_5 -> V_18 -> V_17 -> V_164 ,
V_8 -> V_24 . type ,
V_8 -> V_24 . V_9 ,
V_8 -> V_24 . V_10 ,
V_8 -> V_24 . V_11 ) ;
return 0 ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_159 * V_160 ;
V_160 = F_66 ( V_5 -> V_18 -> V_17 , V_5 -> V_162 ) ;
F_72 ( V_160 , F_73 () ) ;
if ( F_74 ( F_67 ( V_160 ) ) ) {
struct V_1 * V_2 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
F_75 ( V_160 ) ;
}
F_76 ( V_160 ) ;
}
static inline bool F_77 ( struct V_4 * V_158 )
{
struct V_15 * V_12 = & V_158 -> V_12 ;
return ! ! ( V_12 -> V_165 & V_166 ) ;
}
static int F_78 ( struct V_4 * V_5 , int V_146 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_167 , V_23 ;
int V_145 = 0 ;
int V_168 = ( V_5 -> V_169 & V_170 ) ;
V_171:
if ( F_23 ( V_168 == V_170 ||
V_168 == V_172 ) ) {
F_79 ( V_12 , V_168 ) ;
if ( V_168 == V_170 ) {
F_80 ( V_5 ) ;
F_81 ( V_12 ) ;
}
V_5 -> V_169 = 0 ;
return 0 ;
}
V_168 = ( V_5 -> V_169 & V_172 ) ;
V_5 -> V_169 &= ~ ( V_170 | V_172 ) ;
if ( V_168 == V_172 )
goto V_171;
V_168 = V_5 -> V_169 ;
if ( ! ( V_168 & V_173 ) )
return 0 ;
F_52 ( V_168 != V_173 ) ;
V_167 = V_23 = 0 ;
while ( 1 ) {
union {
struct V_7 V_24 ;
V_35 V_174 [ 8 ] ;
} V_153 ;
if ( V_5 -> V_151 ) {
struct V_117 * V_8 =
(struct V_117 * ) & V_153 ;
struct V_1 * V_2 =
& V_5 -> V_12 . V_56 [ V_57 ] ;
V_8 -> V_24 . type = V_119 ;
V_8 -> V_24 . V_9 = V_26 ;
V_8 -> V_24 . V_10 = V_120 ;
V_8 -> V_128 = V_2 -> V_59 ;
V_8 -> V_123 = F_58 ( V_2 , V_5 -> V_152 ) ;
V_8 -> V_124 = - 1 ;
goto V_151;
}
V_23 = F_82 ( V_12 -> V_13 , & V_153 , sizeof( V_153 ) ) ;
if ( F_23 ( V_23 < 0 ) ) {
if ( V_23 == - V_14 )
F_83 ( V_12 ) ;
break;
}
if ( V_23 == 0 )
break;
F_14 ( V_140 , L_20 ,
V_153 . V_24 . type ,
V_153 . V_24 . V_9 ,
V_153 . V_24 . V_10 ,
V_153 . V_24 . V_11 ) ;
V_23 = F_84 ( V_12 , & V_153 . V_24 ) ;
if ( V_23 < 0 )
break;
V_151:
if ( F_74 ( V_153 . V_24 . type == V_119 ) ) {
if ( V_153 . V_24 . V_9 == V_26 ) {
if ( ! F_77 ( V_5 ) ) {
V_23 = - V_14 ;
break;
}
V_23 = F_59 ( V_5 , & V_153 , & V_145 , V_146 ) ;
if ( V_145 >= V_146 )
break;
if ( V_145 == 0 )
break;
} else if ( V_153 . V_24 . V_9 == V_55 ) {
V_23 = F_61 ( V_5 , & V_153 ) ;
if ( V_23 > 0 )
V_167 |= V_23 ;
} else if ( V_153 . V_24 . V_9 == V_54 ) {
V_23 = F_69 ( V_5 , & V_153 ) ;
}
} else if ( V_153 . V_24 . type == V_25 ) {
if ( V_153 . V_24 . V_10 == V_175 )
V_23 = F_70 ( V_5 , & V_153 ) ;
else
V_23 = F_85 ( V_12 , & V_153 ) ;
if ( V_23 )
break;
} else {
V_23 = F_3 ( V_5 , & V_153 ) ;
}
if ( V_23 == - V_14 )
break;
}
if ( F_23 ( V_167 && V_23 != - V_14 ) )
F_71 ( V_5 ) ;
return V_145 ;
}
static int F_86 ( struct V_176 * V_113 , int V_146 )
{
struct V_4 * V_5 = F_87 ( V_113 , struct V_4 , V_113 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_177 = F_78 ( V_5 , V_146 ) ;
if ( V_177 < V_146 ) {
F_88 ( V_113 ) ;
V_5 -> V_169 &= ~ V_173 ;
F_89 ( V_12 -> V_178 -> V_179 , V_180 ) ;
}
return V_177 ;
}
static void F_90 ( void * V_6 , int V_168 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
V_5 -> V_169 |= V_168 ;
F_89 ( V_12 -> V_178 -> V_179 , V_181 ) ;
F_91 ( & V_5 -> V_113 ) ;
}
static int F_65 ( struct V_4 * V_5 , T_1 V_115 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_117 V_118 = {
. V_24 = {
. type = V_119 ,
. V_9 = V_26 ,
. V_10 = V_120 ,
. V_11 = F_9 ( & V_5 -> V_12 ) ,
} ,
. V_121 = V_2 -> V_122 ,
. V_123 = V_115 ,
. V_124 = ( T_1 ) - 1 ,
} ;
int V_23 , V_126 ;
int V_127 = 0 ;
if ( V_5 -> V_134 ) {
V_23 = F_43 ( V_5 ,
& V_5 -> V_12 . V_56 [ V_57 ] ,
V_5 -> V_133 , - 1 ,
V_132 ) ;
if ( V_23 <= 0 )
return V_23 ;
}
V_118 . V_128 = V_2 -> V_58 ;
V_126 = 1 ;
do {
V_23 = F_15 ( & V_5 -> V_12 , & V_118 , sizeof( V_118 ) ) ;
if ( V_23 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_44 ( V_126 ) ;
if ( ( V_126 <<= 1 ) > 128 )
V_126 = 128 ;
if ( V_127 ++ > V_129 )
break;
} while ( V_23 == - V_131 );
return V_23 ;
}
struct V_4 * F_92 ( struct V_158 * V_18 , struct V_61 * V_63 )
{
unsigned int V_182 = F_93 ( V_63 -> V_66 ) ;
struct V_183 * V_184 = & V_18 -> V_185 [ V_182 ] ;
struct V_4 * V_5 ;
F_94 (port, hp, hash) {
if ( ! F_77 ( V_5 ) )
continue;
if ( F_95 ( V_5 -> V_130 , V_63 -> V_66 ) )
return V_5 ;
}
F_96 (port, &vp->port_list, list) {
if ( ! V_5 -> V_110 )
continue;
if ( ! F_77 ( V_5 ) )
continue;
return V_5 ;
}
return NULL ;
}
static struct V_61 * F_97 ( struct V_4 * V_5 ,
unsigned * V_186 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_61 * V_63 = NULL ;
int V_22 , V_187 ;
* V_186 = 0 ;
V_187 = V_2 -> V_157 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_85 * V_188 ;
-- V_187 ;
if ( V_187 < 0 )
V_187 = V_3 - 1 ;
V_188 = F_64 ( V_2 , V_187 ) ;
if ( V_188 -> V_118 . V_125 == V_139 ) {
( * V_186 ) ++ ;
continue;
}
if ( V_5 -> V_189 [ V_187 ] . V_63 ) {
if ( V_188 -> V_118 . V_125 != V_144 )
F_98 ( L_21 ,
V_188 -> V_118 . V_125 ) ;
F_52 ( V_5 -> V_189 [ V_187 ] . V_63 -> V_190 ) ;
V_5 -> V_189 [ V_187 ] . V_63 -> V_190 = V_63 ;
V_63 = V_5 -> V_189 [ V_187 ] . V_63 ;
V_5 -> V_189 [ V_187 ] . V_63 = NULL ;
F_99 ( V_5 -> V_12 . V_13 ,
V_5 -> V_189 [ V_187 ] . V_98 ,
V_5 -> V_189 [ V_187 ] . V_99 ) ;
} else if ( V_188 -> V_118 . V_125 == V_191 )
break;
V_188 -> V_118 . V_125 = V_191 ;
}
return V_63 ;
}
static inline void F_100 ( struct V_61 * V_63 )
{
struct V_61 * V_190 ;
while ( V_63 ) {
V_190 = V_63 -> V_190 ;
V_63 -> V_190 = NULL ;
F_101 ( V_63 ) ;
V_63 = V_190 ;
}
}
static void F_102 ( unsigned long V_192 )
{
struct V_4 * V_5 = (struct V_4 * ) V_192 ;
struct V_61 * V_193 ;
unsigned V_186 ;
F_62 ( V_5 -> V_18 -> V_17 ) ;
V_193 = F_97 ( V_5 , & V_186 ) ;
F_63 ( V_5 -> V_18 -> V_17 ) ;
F_100 ( V_193 ) ;
if ( V_186 )
( void ) F_103 ( & V_5 -> V_194 ,
V_195 + V_196 ) ;
else
F_104 ( & V_5 -> V_194 ) ;
}
static inline int F_105 ( struct V_197 * V_13 , struct V_61 * V_63 ,
struct V_198 * V_98 , int V_99 ,
unsigned int V_199 )
{
int V_22 , V_200 , V_23 , V_201 ;
V_201 = F_106 ( V_63 ) ;
if ( V_201 < V_91 )
V_201 = V_91 ;
V_201 += V_64 ;
V_201 += 8 - ( V_201 & 7 ) ;
V_23 = F_107 ( V_13 , V_63 -> V_66 - V_64 , V_201 , V_98 ,
V_99 , V_199 ) ;
if ( V_23 < 0 )
return V_23 ;
V_200 = V_23 ;
for ( V_22 = 0 ; V_22 < F_108 ( V_63 ) -> V_202 ; V_22 ++ ) {
T_3 * V_203 = & F_108 ( V_63 ) -> V_204 [ V_22 ] ;
T_2 * V_205 ;
if ( V_200 < V_99 ) {
V_205 = F_109 ( F_110 ( V_203 ) ) ;
V_201 = F_111 ( V_203 ) ;
V_201 += 8 - ( V_201 & 7 ) ;
V_23 = F_107 ( V_13 , V_205 + V_203 -> V_206 ,
V_201 , V_98 + V_200 , V_99 - V_200 ,
V_199 ) ;
F_112 ( V_205 ) ;
} else {
V_23 = - V_90 ;
}
if ( V_23 < 0 ) {
F_99 ( V_13 , V_98 , V_200 ) ;
return V_23 ;
}
V_200 += V_23 ;
}
return V_200 ;
}
static inline struct V_61 * F_113 ( struct V_61 * V_63 , int V_99 )
{
struct V_61 * V_207 ;
int V_22 , V_62 , V_208 , V_209 ;
V_62 = V_63 -> V_62 ;
V_208 = 0 ;
if ( V_62 < V_91 ) {
V_208 += V_91 - V_63 -> V_62 ;
V_62 += V_208 ;
}
V_62 += V_64 ;
V_208 += 8 - ( V_62 & 7 ) ;
V_209 = F_108 ( V_63 ) -> V_202 >= V_99 ;
for ( V_22 = 0 ; V_22 < F_108 ( V_63 ) -> V_202 ; V_22 ++ ) {
T_3 * V_203 = & F_108 ( V_63 ) -> V_204 [ V_22 ] ;
V_209 |= V_203 -> V_206 & 7 ;
}
if ( ( ( unsigned long ) V_63 -> V_66 & 7 ) != V_64 ||
F_114 ( V_63 ) < V_208 ||
F_115 ( V_63 ) < V_64 || V_209 ) {
int V_115 = 0 , V_69 ;
T_4 V_77 ;
V_62 = V_63 -> V_62 > V_91 ? V_63 -> V_62 : V_91 ;
V_207 = F_21 ( V_63 -> V_17 , V_62 ) ;
if ( V_207 == NULL ) {
F_101 ( V_63 ) ;
return NULL ;
}
F_24 ( V_207 , V_64 ) ;
V_207 -> V_70 = V_63 -> V_70 ;
V_69 = F_116 ( V_63 ) - V_63 -> V_66 ;
F_117 ( V_207 , V_69 ) ;
V_69 = F_118 ( V_63 ) - V_63 -> V_66 ;
F_119 ( V_207 , V_69 ) ;
V_69 = F_120 ( V_63 ) - V_63 -> V_66 ;
F_121 ( V_207 , V_69 ) ;
V_69 = 0 ;
V_207 -> V_210 = V_63 -> V_210 ;
V_207 -> V_74 = V_63 -> V_74 ;
if ( V_63 -> V_74 == V_108 )
V_115 = F_122 ( V_63 ) ;
if ( V_115 ) {
struct V_67 * V_68 = F_26 ( V_207 ) ;
int V_69 = V_115 + V_207 -> V_210 ;
if ( F_123 ( V_63 , 0 , V_207 -> V_66 , V_115 ) ) {
F_101 ( V_207 ) ;
F_101 ( V_63 ) ;
return NULL ;
}
* ( V_211 * ) ( V_63 -> V_66 + V_69 ) = 0 ;
V_77 = F_124 ( V_63 , V_115 ,
V_207 -> V_66 + V_115 ,
V_63 -> V_62 - V_115 , 0 ) ;
if ( V_68 -> V_70 == V_72 ||
V_68 -> V_70 == V_73 ) {
V_77 = F_31 ( V_68 -> V_81 , V_68 -> V_82 ,
V_63 -> V_62 - V_115 ,
V_68 -> V_70 , V_77 ) ;
}
* ( V_211 * ) ( V_207 -> V_66 + V_69 ) = V_77 ;
V_207 -> V_74 = V_75 ;
} else if ( F_123 ( V_63 , 0 , V_207 -> V_66 , V_63 -> V_62 ) ) {
F_101 ( V_207 ) ;
F_101 ( V_63 ) ;
return NULL ;
}
( void ) F_34 ( V_207 , V_63 -> V_62 ) ;
if ( F_125 ( V_63 ) ) {
F_108 ( V_207 ) -> V_212 = F_108 ( V_63 ) -> V_212 ;
F_108 ( V_207 ) -> V_213 = F_108 ( V_63 ) -> V_213 ;
}
V_207 -> V_214 = V_63 -> V_214 ;
F_101 ( V_63 ) ;
V_63 = V_207 ;
}
return V_63 ;
}
static T_5
F_126 ( struct V_16 * V_17 , struct V_61 * V_63 ,
void * V_215 , T_6 V_216 )
{
struct V_158 * V_18 = F_127 ( V_17 ) ;
struct V_4 * V_5 = F_92 ( V_18 , V_63 ) ;
if ( V_5 == NULL )
return 0 ;
return V_5 -> V_162 ;
}
static int F_128 ( struct V_4 * V_5 , struct V_61 * V_63 )
{
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_61 * V_217 ;
int V_218 , V_219 ;
int V_220 ;
int V_212 , V_213 , V_221 ;
int V_222 = F_120 ( V_63 ) - F_116 ( V_63 ) ;
int V_223 = V_224 ;
if ( V_63 -> V_70 == F_28 ( V_71 ) )
V_223 = F_26 ( V_63 ) -> V_70 ;
else if ( V_63 -> V_70 == F_28 ( V_225 ) )
V_223 = F_129 ( V_63 ) -> V_226 ;
if ( V_223 == V_72 )
V_222 += F_29 ( V_63 ) -> V_227 * 4 ;
else if ( V_223 == V_73 )
V_222 += sizeof( struct V_83 ) ;
else {
F_4 ( L_22
L_23 , V_63 -> V_70 , V_223 ) ;
V_222 = 128 ;
}
V_219 = V_5 -> V_46 - V_222 ;
V_212 = F_108 ( V_63 ) -> V_212 ;
V_213 = F_108 ( V_63 ) -> V_213 ;
V_221 = F_108 ( V_63 ) -> V_221 ;
if ( V_5 -> V_44 && V_212 < V_219 )
V_221 = F_130 ( V_63 -> V_62 - V_222 , V_219 ) ;
if ( F_23 ( F_1 ( V_2 ) < V_221 ) ) {
struct V_159 * V_160 ;
V_160 = F_66 ( V_17 , V_5 -> V_162 ) ;
F_131 ( V_160 ) ;
if ( F_1 ( V_2 ) < F_108 ( V_63 ) -> V_221 )
return V_228 ;
F_75 ( V_160 ) ;
}
V_218 = F_118 ( V_63 ) - F_116 ( V_63 ) ;
F_36 ( V_63 , V_218 ) ;
if ( V_5 -> V_44 && V_212 < V_219 ) {
if ( F_132 ( V_63 , V_229 ) )
goto V_94;
F_108 ( V_63 ) -> V_212 = V_219 ;
F_108 ( V_63 ) -> V_221 = V_221 ;
}
V_217 = F_133 ( V_63 , V_17 -> V_230 & ~ V_231 ) ;
if ( F_53 ( V_217 ) )
goto V_94;
F_134 ( V_63 , V_218 ) ;
F_135 ( V_63 ) ;
V_220 = 0 ;
while ( V_217 ) {
struct V_61 * V_232 = V_217 ;
V_217 = V_217 -> V_190 ;
V_232 -> V_190 = NULL ;
if ( V_5 -> V_44 && V_232 -> V_62 > V_17 -> V_39 ) {
F_108 ( V_232 ) -> V_212 = V_212 ;
F_108 ( V_232 ) -> V_213 = V_213 ;
F_108 ( V_232 ) -> V_221 =
F_130 ( V_232 -> V_62 - V_222 , V_212 ) ;
} else
F_108 ( V_232 ) -> V_212 = 0 ;
F_134 ( V_232 , V_218 ) ;
F_135 ( V_232 ) ;
memcpy ( F_116 ( V_232 ) , F_116 ( V_63 ) ,
V_218 ) ;
V_232 -> V_233 = F_120 ( V_232 ) - V_232 -> V_234 ;
if ( F_26 ( V_232 ) -> V_70 == V_72 )
V_232 -> V_210 = F_136 ( struct V_78 , V_80 ) ;
else if ( F_26 ( V_232 ) -> V_70 == V_73 )
V_232 -> V_210 = F_136 ( struct V_83 , V_80 ) ;
if ( ! ( V_220 & V_235 ) )
V_220 = F_137 ( V_232 , V_17 ) ;
if ( V_220 & V_235 )
F_138 ( V_232 ) ;
}
if ( ! ( V_220 & V_235 ) )
F_138 ( V_63 ) ;
return V_220 ;
V_94:
V_17 -> V_92 . V_236 ++ ;
F_138 ( V_63 ) ;
return V_237 ;
}
static int F_137 ( struct V_61 * V_63 , struct V_16 * V_17 )
{
struct V_158 * V_18 = F_127 ( V_17 ) ;
struct V_4 * V_5 = NULL ;
struct V_1 * V_2 ;
struct V_85 * V_188 ;
unsigned int V_62 ;
struct V_61 * V_193 = NULL ;
int V_22 , V_23 , V_187 ;
unsigned V_186 = 0 ;
struct V_159 * V_160 ;
F_139 () ;
V_5 = F_92 ( V_18 , V_63 ) ;
if ( F_23 ( ! V_5 ) ) {
F_140 () ;
goto V_94;
}
if ( F_125 ( V_63 ) && V_63 -> V_62 > V_5 -> V_46 ) {
V_23 = F_128 ( V_5 , V_63 ) ;
F_140 () ;
return V_23 ;
}
if ( ! F_125 ( V_63 ) && V_63 -> V_62 > V_5 -> V_37 ) {
unsigned long V_52 = V_5 -> V_37 - V_238 ;
if ( F_13 ( & V_5 -> V_12 , 1 , 3 ) )
V_52 -= V_42 ;
if ( V_63 -> V_70 == F_28 ( V_71 ) ) {
struct V_239 V_240 ;
struct V_241 * V_242 = NULL ;
memset ( & V_240 , 0 , sizeof( V_240 ) ) ;
V_240 . V_243 = V_17 -> V_244 ;
V_240 . V_245 = F_141 ( F_26 ( V_63 ) -> V_246 ) ;
V_240 . V_82 = F_26 ( V_63 ) -> V_82 ;
V_240 . V_81 = F_26 ( V_63 ) -> V_81 ;
V_242 = F_142 ( F_143 ( V_17 ) , & V_240 ) ;
F_140 () ;
if ( ! F_53 ( V_242 ) ) {
F_144 ( V_63 , & V_242 -> V_247 ) ;
F_145 ( V_63 , V_248 ,
V_249 ,
F_146 ( V_52 ) ) ;
}
}
#if F_147 ( V_250 )
else if ( V_63 -> V_70 == F_28 ( V_225 ) )
F_148 ( V_63 , V_251 , 0 , V_52 ) ;
#endif
goto V_94;
}
V_63 = F_113 ( V_63 , 2 ) ;
if ( F_23 ( ! V_63 ) )
goto V_94;
if ( V_63 -> V_74 == V_108 )
F_25 ( V_63 ) ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
V_22 = F_149 ( V_63 ) ;
V_160 = F_66 ( V_17 , V_22 ) ;
if ( F_23 ( F_1 ( V_2 ) < 1 ) ) {
if ( ! F_67 ( V_160 ) ) {
F_131 ( V_160 ) ;
F_150 ( V_17 , L_24 ) ;
V_17 -> V_92 . V_252 ++ ;
}
F_140 () ;
return V_228 ;
}
V_188 = F_151 ( V_2 ) ;
V_187 = V_2 -> V_157 ;
V_193 = F_97 ( V_5 , & V_186 ) ;
F_52 ( V_5 -> V_189 [ V_187 ] . V_63 ) ;
V_62 = V_63 -> V_62 ;
if ( V_62 < V_91 )
V_62 = V_91 ;
V_23 = F_105 ( V_5 -> V_12 . V_13 , V_63 , V_5 -> V_189 [ V_187 ] . V_98 , 2 ,
( V_253 | V_254 | V_255 ) ) ;
if ( V_23 < 0 ) {
F_152 ( V_17 , L_25 , V_23 ) ;
goto V_94;
}
V_5 -> V_189 [ V_187 ] . V_63 = V_63 ;
V_63 = NULL ;
V_5 -> V_189 [ V_187 ] . V_99 = V_23 ;
V_188 -> V_118 . V_141 = V_256 ;
V_188 -> V_87 = V_62 ;
V_188 -> V_99 = V_5 -> V_189 [ V_187 ] . V_99 ;
for ( V_22 = 0 ; V_22 < V_188 -> V_99 ; V_22 ++ )
V_188 -> V_98 [ V_22 ] = V_5 -> V_189 [ V_187 ] . V_98 [ V_22 ] ;
if ( F_13 ( & V_5 -> V_12 , 1 , 7 ) ) {
struct V_102 * V_103 = F_39 ( V_188 ) ;
memset ( V_103 , 0 , sizeof( * V_103 ) ) ;
if ( F_125 ( V_5 -> V_189 [ V_187 ] . V_63 ) ) {
V_103 -> V_257 = F_108 ( V_5 -> V_189 [ V_187 ] . V_63 )
-> V_212 ;
V_103 -> V_104 |= V_258 ;
}
if ( F_13 ( & V_5 -> V_12 , 1 , 8 ) &&
! V_5 -> V_110 ) {
V_103 -> V_104 |= V_107 ;
V_103 -> V_104 |= V_109 ;
}
}
F_153 () ;
V_188 -> V_118 . V_125 = V_139 ;
if ( ! V_5 -> V_161 )
goto V_259;
V_23 = F_65 ( V_5 , V_2 -> V_155 ) ;
if ( F_23 ( V_23 < 0 ) ) {
F_152 ( V_17 , L_26 , V_23 ) ;
V_188 -> V_118 . V_125 = V_191 ;
V_63 = V_5 -> V_189 [ V_187 ] . V_63 ;
V_5 -> V_189 [ V_187 ] . V_63 = NULL ;
V_17 -> V_92 . V_260 ++ ;
goto V_94;
}
V_259:
V_5 -> V_161 = false ;
V_17 -> V_92 . V_261 ++ ;
V_17 -> V_92 . V_262 += V_5 -> V_189 [ V_187 ] . V_63 -> V_62 ;
V_2 -> V_157 = ( V_2 -> V_157 + 1 ) & ( V_3 - 1 ) ;
if ( F_23 ( F_1 ( V_2 ) < 1 ) ) {
F_131 ( V_160 ) ;
if ( F_1 ( V_2 ) > F_68 ( V_2 ) )
F_75 ( V_160 ) ;
}
( void ) F_103 ( & V_5 -> V_194 , V_195 + V_196 ) ;
F_140 () ;
F_100 ( V_193 ) ;
return V_237 ;
V_94:
if ( V_186 )
( void ) F_103 ( & V_5 -> V_194 ,
V_195 + V_196 ) ;
else if ( V_5 )
F_104 ( & V_5 -> V_194 ) ;
if ( V_5 )
F_140 () ;
if ( V_63 )
F_101 ( V_63 ) ;
F_100 ( V_193 ) ;
V_17 -> V_92 . V_236 ++ ;
return V_237 ;
}
static void F_154 ( struct V_16 * V_17 )
{
}
static int F_155 ( struct V_16 * V_17 )
{
F_156 ( V_17 ) ;
F_157 ( V_17 ) ;
return 0 ;
}
static int F_158 ( struct V_16 * V_17 )
{
F_159 ( V_17 ) ;
F_160 ( V_17 ) ;
return 0 ;
}
static struct V_263 * F_161 ( struct V_158 * V_18 , T_2 * V_34 )
{
struct V_263 * V_264 ;
for ( V_264 = V_18 -> V_265 ; V_264 ; V_264 = V_264 -> V_190 ) {
if ( F_95 ( V_264 -> V_34 , V_34 ) )
return V_264 ;
}
return NULL ;
}
static void F_162 ( struct V_158 * V_18 , struct V_16 * V_17 )
{
struct V_266 * V_267 ;
F_163 (ha, dev) {
struct V_263 * V_264 ;
V_264 = F_161 ( V_18 , V_267 -> V_34 ) ;
if ( V_264 ) {
V_264 -> V_268 = 1 ;
continue;
}
if ( ! V_264 ) {
V_264 = F_164 ( sizeof( * V_264 ) , V_229 ) ;
if ( ! V_264 )
continue;
memcpy ( V_264 -> V_34 , V_267 -> V_34 , V_269 ) ;
V_264 -> V_268 = 1 ;
V_264 -> V_190 = V_18 -> V_265 ;
V_18 -> V_265 = V_264 ;
}
}
}
static void F_165 ( struct V_158 * V_18 , struct V_4 * V_5 )
{
struct V_163 V_270 ;
struct V_263 * V_264 , * * V_271 ;
int V_272 ;
memset ( & V_270 , 0 , sizeof( V_270 ) ) ;
V_270 . V_24 . type = V_25 ;
V_270 . V_24 . V_9 = V_26 ;
V_270 . V_24 . V_10 = V_175 ;
V_270 . V_24 . V_11 = F_9 ( & V_5 -> V_12 ) ;
V_270 . V_273 = 1 ;
V_272 = 0 ;
for ( V_264 = V_18 -> V_265 ; V_264 ; V_264 = V_264 -> V_190 ) {
if ( V_264 -> V_274 )
continue;
V_264 -> V_274 = 1 ;
memcpy ( & V_270 . V_275 [ V_272 * V_269 ] ,
V_264 -> V_34 , V_269 ) ;
if ( ++ V_272 == V_276 ) {
V_270 . V_277 = V_272 ;
( void ) F_15 ( & V_5 -> V_12 , & V_270 ,
sizeof( V_270 ) ) ;
V_272 = 0 ;
}
}
if ( V_272 ) {
V_270 . V_277 = V_272 ;
( void ) F_15 ( & V_5 -> V_12 , & V_270 , sizeof( V_270 ) ) ;
}
V_270 . V_273 = 0 ;
V_272 = 0 ;
V_271 = & V_18 -> V_265 ;
while ( ( V_264 = * V_271 ) != NULL ) {
if ( V_264 -> V_268 ) {
V_264 -> V_268 = 0 ;
V_271 = & V_264 -> V_190 ;
continue;
}
memcpy ( & V_270 . V_275 [ V_272 * V_269 ] ,
V_264 -> V_34 , V_269 ) ;
if ( ++ V_272 == V_276 ) {
V_270 . V_277 = V_272 ;
( void ) F_15 ( & V_5 -> V_12 , & V_270 ,
sizeof( V_270 ) ) ;
V_272 = 0 ;
}
* V_271 = V_264 -> V_190 ;
F_166 ( V_264 ) ;
}
if ( V_272 ) {
V_270 . V_277 = V_272 ;
( void ) F_15 ( & V_5 -> V_12 , & V_270 , sizeof( V_270 ) ) ;
}
}
static void F_167 ( struct V_16 * V_17 )
{
struct V_158 * V_18 = F_127 ( V_17 ) ;
struct V_4 * V_5 ;
F_139 () ;
F_96 (port, &vp->port_list, list) {
if ( V_5 -> V_110 ) {
F_162 ( V_18 , V_17 ) ;
F_165 ( V_18 , V_5 ) ;
break;
}
}
F_140 () ;
}
static int F_168 ( struct V_16 * V_17 , int V_278 )
{
if ( V_278 < 68 || V_278 > 65535 )
return - V_279 ;
V_17 -> V_39 = V_278 ;
return 0 ;
}
static int F_169 ( struct V_16 * V_17 , void * V_280 )
{
return - V_279 ;
}
static void F_170 ( struct V_16 * V_17 ,
struct V_281 * V_270 )
{
F_171 ( V_270 -> V_282 , V_283 , sizeof( V_270 -> V_282 ) ) ;
F_171 ( V_270 -> V_284 , V_285 , sizeof( V_270 -> V_284 ) ) ;
}
static T_1 F_172 ( struct V_16 * V_17 )
{
struct V_158 * V_18 = F_127 ( V_17 ) ;
return V_18 -> V_286 ;
}
static void F_173 ( struct V_16 * V_17 , T_1 V_287 )
{
struct V_158 * V_18 = F_127 ( V_17 ) ;
V_18 -> V_286 = V_287 ;
}
static void F_174 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
if ( V_2 -> V_288 == NULL )
return;
for ( V_22 = 0 ; V_22 < V_3 ; V_22 ++ ) {
struct V_85 * V_188 ;
void * V_63 = V_5 -> V_189 [ V_22 ] . V_63 ;
if ( ! V_63 )
continue;
V_188 = F_64 ( V_2 , V_22 ) ;
F_99 ( V_5 -> V_12 . V_13 ,
V_5 -> V_189 [ V_22 ] . V_98 ,
V_5 -> V_189 [ V_22 ] . V_99 ) ;
F_101 ( V_63 ) ;
V_5 -> V_189 [ V_22 ] . V_63 = NULL ;
V_188 -> V_118 . V_125 = V_191 ;
}
F_175 ( V_5 -> V_12 . V_13 , V_2 -> V_288 ,
( V_2 -> V_137 * V_2 -> V_289 ) ,
V_2 -> V_98 , V_2 -> V_99 ) ;
V_2 -> V_288 = NULL ;
V_2 -> V_137 = 0 ;
V_2 -> V_289 = 0 ;
V_2 -> V_186 = 0 ;
V_2 -> V_99 = 0 ;
}
static void F_80 ( struct V_4 * V_5 )
{
F_104 ( & V_5 -> V_194 ) ;
F_174 ( V_5 ) ;
V_5 -> V_37 = 0 ;
V_5 -> V_44 = true ;
V_5 -> V_46 = 0 ;
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_62 , V_290 ;
int V_22 , V_23 , V_99 ;
void * V_291 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
V_290 = sizeof( struct V_85 ) +
sizeof( struct V_198 ) * 2 ;
if ( F_13 ( & V_5 -> V_12 , 1 , 7 ) )
V_290 += sizeof( struct V_102 ) ;
V_62 = V_3 * V_290 ;
V_99 = V_292 ;
V_291 = F_176 ( V_5 -> V_12 . V_13 , V_62 ,
V_2 -> V_98 , & V_99 ,
( V_253 |
V_254 |
V_255 ) ) ;
if ( F_53 ( V_291 ) ) {
V_23 = F_54 ( V_291 ) ;
goto V_293;
}
V_2 -> V_288 = V_291 ;
V_2 -> V_137 = V_290 ;
V_2 -> V_289 = V_3 ;
V_2 -> V_157 = V_2 -> V_155 = 0 ;
V_5 -> V_161 = true ;
V_2 -> V_186 = V_3 ;
V_2 -> V_99 = V_99 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_85 * V_188 ;
V_188 = F_64 ( V_2 , V_22 ) ;
V_188 -> V_118 . V_125 = V_191 ;
}
return 0 ;
V_293:
F_174 ( V_5 ) ;
return V_23 ;
}
static void F_177 ( struct V_16 * V_17 )
{
struct V_158 * V_18 = F_127 ( V_17 ) ;
struct V_4 * V_5 ;
unsigned long V_104 ;
F_178 ( & V_18 -> V_294 , V_104 ) ;
if ( ! F_179 ( & V_18 -> V_295 ) ) {
V_5 = F_180 ( V_18 -> V_295 . V_190 , struct V_4 , V_296 ) ;
F_91 ( & V_5 -> V_113 ) ;
}
F_181 ( & V_18 -> V_294 , V_104 ) ;
}
static struct V_158 * F_182 ( const V_35 * V_297 )
{
struct V_16 * V_17 ;
struct V_158 * V_18 ;
int V_23 , V_22 ;
V_17 = F_183 ( sizeof( * V_18 ) , V_298 , 1 ) ;
if ( ! V_17 )
return F_48 ( - V_95 ) ;
V_17 -> V_299 = V_64 + 8 ;
V_17 -> V_300 = 8 ;
for ( V_22 = 0 ; V_22 < V_269 ; V_22 ++ )
V_17 -> V_36 [ V_22 ] = ( * V_297 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_18 = F_127 ( V_17 ) ;
F_184 ( & V_18 -> V_294 ) ;
V_18 -> V_17 = V_17 ;
F_185 ( & V_18 -> V_295 ) ;
for ( V_22 = 0 ; V_22 < V_301 ; V_22 ++ )
F_186 ( & V_18 -> V_185 [ V_22 ] ) ;
F_185 ( & V_18 -> V_296 ) ;
V_18 -> V_297 = * V_297 ;
V_17 -> V_302 = & V_303 ;
V_17 -> V_304 = & V_305 ;
V_17 -> V_306 = V_307 ;
V_17 -> V_308 = V_231 | V_309 | V_310 |
V_311 | V_312 ;
V_17 -> V_230 = V_17 -> V_308 ;
V_23 = F_187 ( V_17 ) ;
if ( V_23 ) {
F_4 ( L_27 ) ;
goto V_313;
}
F_152 ( V_17 , L_28 , V_17 -> V_36 ) ;
F_188 ( & V_18 -> V_296 , & V_314 ) ;
return V_18 ;
V_313:
F_189 ( V_17 ) ;
return F_48 ( V_23 ) ;
}
static struct V_158 * F_190 ( const V_35 * V_297 )
{
struct V_158 * V_315 , * V_18 ;
F_191 ( & V_316 ) ;
V_18 = NULL ;
F_192 (iter, &vnet_list, list) {
if ( V_315 -> V_297 == * V_297 ) {
V_18 = V_315 ;
break;
}
}
if ( ! V_18 )
V_18 = F_182 ( V_297 ) ;
F_193 ( & V_316 ) ;
return V_18 ;
}
static void F_194 ( void )
{
struct V_158 * V_18 ;
struct V_16 * V_17 ;
F_191 ( & V_316 ) ;
while ( ! F_179 ( & V_314 ) ) {
V_18 = F_195 ( & V_314 , struct V_158 , V_296 ) ;
F_196 ( & V_18 -> V_296 ) ;
V_17 = V_18 -> V_17 ;
F_52 ( ! F_179 ( & V_18 -> V_295 ) ) ;
F_197 ( V_17 ) ;
F_189 ( V_17 ) ;
}
F_193 ( & V_316 ) ;
}
static struct V_158 * F_198 ( struct V_317 * V_184 ,
V_35 V_318 )
{
const V_35 * V_297 = NULL ;
V_35 V_319 ;
F_199 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
V_35 V_320 = F_200 ( V_184 , V_319 ) ;
const char * V_164 ;
V_164 = F_201 ( V_184 , V_320 , L_29 , NULL ) ;
if ( ! V_164 || strcmp ( V_164 , L_30 ) )
continue;
V_297 = F_201 ( V_184 , V_320 ,
V_321 , NULL ) ;
if ( V_297 )
break;
}
if ( ! V_297 )
return F_48 ( - V_322 ) ;
return F_190 ( V_297 ) ;
}
static void F_202 ( void )
{
F_203 ( V_323 L_31 , V_284 ) ;
}
static void
F_204 ( struct V_4 * V_5 )
{
struct V_158 * V_18 = V_5 -> V_18 ;
int V_324 ;
V_324 = V_18 -> V_325 ++ ;
V_324 = V_324 & ( V_298 - 1 ) ;
V_5 -> V_162 = V_324 ;
F_75 ( F_66 ( V_18 -> V_17 , V_5 -> V_162 ) ) ;
}
static void
F_205 ( struct V_4 * V_5 )
{
V_5 -> V_18 -> V_325 -- ;
F_131 ( F_66 ( V_5 -> V_18 -> V_17 , V_5 -> V_162 ) ) ;
}
static int F_206 ( struct V_326 * V_178 , const struct V_327 * V_328 )
{
struct V_317 * V_184 ;
struct V_4 * V_5 ;
unsigned long V_104 ;
struct V_158 * V_18 ;
const V_35 * V_329 ;
int V_62 , V_22 , V_23 , V_110 ;
F_202 () ;
V_184 = F_207 () ;
V_18 = F_198 ( V_184 , V_178 -> V_330 ) ;
if ( F_53 ( V_18 ) ) {
F_4 ( L_32 ) ;
V_23 = F_54 ( V_18 ) ;
goto V_331;
}
V_329 = F_201 ( V_184 , V_178 -> V_330 , V_332 , & V_62 ) ;
V_23 = - V_322 ;
if ( ! V_329 ) {
F_4 ( L_33 , V_332 ) ;
goto V_331;
}
V_5 = F_164 ( sizeof( * V_5 ) , V_333 ) ;
V_23 = - V_95 ;
if ( ! V_5 )
goto V_331;
for ( V_22 = 0 ; V_22 < V_269 ; V_22 ++ )
V_5 -> V_130 [ V_22 ] = ( * V_329 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_5 -> V_18 = V_18 ;
V_23 = F_208 ( & V_5 -> V_12 , V_178 , V_334 ,
V_335 , F_209 ( V_335 ) ,
& V_336 , V_18 -> V_17 -> V_164 ) ;
if ( V_23 )
goto V_337;
V_23 = F_210 ( & V_5 -> V_12 , & V_338 , V_5 ) ;
if ( V_23 )
goto V_337;
F_211 ( V_5 -> V_18 -> V_17 , & V_5 -> V_113 , F_86 , V_339 ) ;
F_212 ( & V_5 -> V_182 ) ;
F_185 ( & V_5 -> V_296 ) ;
V_110 = 0 ;
if ( F_201 ( V_184 , V_178 -> V_330 , L_34 , NULL ) != NULL )
V_110 = 1 ;
V_5 -> V_110 = V_110 ;
V_5 -> V_44 = true ;
V_5 -> V_46 = 0 ;
F_178 ( & V_18 -> V_294 , V_104 ) ;
if ( V_110 )
F_213 ( & V_5 -> V_296 , & V_18 -> V_295 ) ;
else
F_214 ( & V_5 -> V_296 , & V_18 -> V_295 ) ;
F_215 ( & V_5 -> V_182 ,
& V_18 -> V_185 [ F_93 ( V_5 -> V_130 ) ] ) ;
F_204 ( V_5 ) ;
F_181 ( & V_18 -> V_294 , V_104 ) ;
F_216 ( & V_178 -> V_17 , V_5 ) ;
F_45 ( L_35 ,
V_18 -> V_17 -> V_164 , V_5 -> V_130 , V_110 ? L_36 : L_37 ) ;
F_217 ( & V_5 -> V_194 , F_102 ,
( unsigned long ) V_5 ) ;
F_218 ( & V_5 -> V_113 ) ;
F_81 ( & V_5 -> V_12 ) ;
F_219 ( V_184 ) ;
return 0 ;
V_337:
F_166 ( V_5 ) ;
V_331:
F_219 ( V_184 ) ;
return V_23 ;
}
static int F_220 ( struct V_326 * V_178 )
{
struct V_4 * V_5 = F_221 ( & V_178 -> V_17 ) ;
if ( V_5 ) {
F_222 ( & V_5 -> V_12 . V_340 ) ;
F_223 ( & V_5 -> V_113 ) ;
F_224 ( & V_5 -> V_296 ) ;
F_225 ( & V_5 -> V_182 ) ;
F_226 () ;
F_222 ( & V_5 -> V_194 ) ;
F_205 ( V_5 ) ;
F_227 ( & V_5 -> V_113 ) ;
F_174 ( V_5 ) ;
F_228 ( & V_5 -> V_12 ) ;
F_216 ( & V_178 -> V_17 , NULL ) ;
F_166 ( V_5 ) ;
}
return 0 ;
}
static int T_7 F_229 ( void )
{
return F_230 ( & V_341 ) ;
}
static void T_8 F_231 ( void )
{
F_232 ( & V_341 ) ;
F_194 () ;
}
