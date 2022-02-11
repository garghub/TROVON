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
int V_23 ;
V_23 = - V_89 ;
if ( F_23 ( V_62 < V_90 || V_62 > V_5 -> V_37 ) ) {
V_17 -> V_91 . V_92 ++ ;
goto V_93;
}
V_63 = F_21 ( V_17 , V_62 ) ;
V_23 = - V_94 ;
if ( F_23 ( ! V_63 ) ) {
V_17 -> V_91 . V_95 ++ ;
goto V_93;
}
V_88 = ( V_62 + V_64 + 7U ) & ~ 7U ;
F_34 ( V_63 , V_88 ) ;
V_23 = F_35 ( V_5 -> V_12 . V_13 , V_96 ,
V_63 -> V_66 , V_88 , 0 ,
V_86 -> V_97 , V_86 -> V_98 ) ;
if ( F_23 ( V_23 < 0 ) ) {
V_17 -> V_91 . V_99 ++ ;
goto V_100;
}
F_36 ( V_63 , V_64 ) ;
F_37 ( V_63 , V_62 ) ;
V_63 -> V_70 = F_38 ( V_63 , V_17 ) ;
if ( F_13 ( & V_5 -> V_12 , 1 , 8 ) ) {
struct V_101 * V_102 = F_39 ( V_86 ) ;
if ( V_102 -> V_103 & V_104 ) {
if ( V_63 -> V_70 == V_71 ) {
struct V_67 * V_68 = (struct V_67 * ) V_63 -> V_66 ;
V_68 -> V_80 = 0 ;
F_40 ( V_68 ) ;
}
}
if ( ( V_102 -> V_103 & V_105 ) &&
V_63 -> V_74 == V_75 )
F_25 ( V_63 ) ;
if ( V_102 -> V_103 & V_106 ) {
V_63 -> V_74 = V_107 ;
V_63 -> V_76 = 0 ;
if ( V_102 -> V_103 & V_108 )
V_63 -> V_76 = 1 ;
}
}
V_63 -> V_74 = V_5 -> V_109 ? V_75 : V_107 ;
V_17 -> V_91 . V_110 ++ ;
V_17 -> V_91 . V_111 += V_62 ;
F_41 ( & V_5 -> V_112 , V_63 ) ;
return 0 ;
V_100:
F_42 ( V_63 ) ;
V_93:
V_17 -> V_91 . V_113 ++ ;
return V_23 ;
}
static int F_43 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_114 , T_1 V_115 , T_2 V_1 )
{
struct V_116 V_117 = {
. V_24 = {
. type = V_118 ,
. V_9 = V_55 ,
. V_10 = V_119 ,
. V_11 = F_9 ( & V_5 -> V_12 ) ,
} ,
. V_120 = V_2 -> V_121 ,
. V_122 = V_114 ,
. V_123 = V_115 ,
. V_124 = V_1 ,
} ;
int V_23 , V_125 ;
int V_126 = 0 ;
V_117 . V_127 = V_2 -> V_58 ;
V_125 = 1 ;
do {
V_23 = F_15 ( & V_5 -> V_12 , & V_117 , sizeof( V_117 ) ) ;
if ( V_23 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_44 ( V_125 ) ;
if ( ( V_125 <<= 1 ) > 128 )
V_125 = 128 ;
if ( V_126 ++ > V_128 ) {
F_45 ( L_14 ,
V_5 -> V_129 [ 0 ] , V_5 -> V_129 [ 1 ] ,
V_5 -> V_129 [ 2 ] , V_5 -> V_129 [ 3 ] ,
V_5 -> V_129 [ 4 ] , V_5 -> V_129 [ 5 ] ) ;
break;
}
} while ( V_23 == - V_130 );
if ( V_23 <= 0 && V_1 == V_131 ) {
V_5 -> V_132 = V_115 ;
V_5 -> V_133 = true ;
} else {
V_5 -> V_132 = 0 ;
V_5 -> V_133 = false ;
}
return V_23 ;
}
static struct V_85 * F_46 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_134 )
{
struct V_85 * V_86 = V_5 -> V_12 . V_135 ;
int V_23 ;
V_23 = F_47 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_136 ,
( V_134 * V_2 -> V_136 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
if ( V_23 < 0 )
return F_48 ( V_23 ) ;
return V_86 ;
}
static int F_49 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_1 V_134 )
{
int V_23 ;
V_23 = F_50 ( V_5 -> V_12 . V_13 , V_86 , V_2 -> V_136 ,
( V_134 * V_2 -> V_136 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
if ( V_23 < 0 )
return V_23 ;
return 0 ;
}
static int F_51 ( struct V_4 * V_5 ,
struct V_1 * V_2 ,
T_1 V_134 , int * V_137 )
{
struct V_85 * V_86 = F_46 ( V_5 , V_2 , V_134 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_23 ;
F_52 ( V_86 == NULL ) ;
if ( F_53 ( V_86 ) )
return F_54 ( V_86 ) ;
if ( V_86 -> V_117 . V_124 != V_138 )
return 1 ;
F_55 () ;
F_14 ( V_139 , L_15 ,
V_86 -> V_117 . V_124 , V_86 -> V_117 . V_140 ,
V_86 -> V_87 , V_86 -> V_98 ,
V_86 -> V_97 [ 0 ] . V_141 ,
V_86 -> V_97 [ 0 ] . V_142 ) ;
V_23 = F_33 ( V_5 , V_86 ) ;
if ( V_23 == - V_14 )
return V_23 ;
V_86 -> V_117 . V_124 = V_143 ;
V_23 = F_49 ( V_5 , V_2 , V_86 , V_134 ) ;
if ( V_23 < 0 )
return V_23 ;
* V_137 = V_86 -> V_117 . V_140 ;
return 0 ;
}
static int F_56 ( struct V_4 * V_5 , struct V_1 * V_2 ,
T_1 V_114 , T_1 V_115 , int * V_144 , int V_145 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_146 = - 1 , V_147 = - 1 ;
bool V_148 = true ;
V_115 = ( V_115 == ( T_1 ) - 1 ) ? F_57 ( V_2 , V_114 )
: F_58 ( V_2 , V_115 ) ;
F_14 ( V_139 , L_16 , V_114 , V_115 ) ;
while ( V_114 != V_115 ) {
int V_140 = 0 , V_23 = F_51 ( V_5 , V_2 , V_114 , & V_140 ) ;
if ( V_23 == - V_14 )
return V_23 ;
if ( V_23 != 0 )
break;
( * V_144 ) ++ ;
if ( V_146 == - 1 )
V_146 = V_114 ;
V_147 = V_114 ;
V_114 = F_58 ( V_2 , V_114 ) ;
if ( V_140 && V_114 != V_115 ) {
V_23 = F_43 ( V_5 , V_2 , V_146 , V_147 ,
V_149 ) ;
if ( V_23 == - V_14 )
return V_23 ;
V_146 = - 1 ;
}
if ( ( * V_144 ) >= V_145 ) {
V_148 = false ;
break;
}
}
if ( F_23 ( V_146 == - 1 ) )
V_146 = V_147 = F_57 ( V_2 , V_114 ) ;
if ( V_148 ) {
V_5 -> V_150 = false ;
return F_43 ( V_5 , V_2 , V_146 , V_147 ,
V_131 ) ;
} else {
V_5 -> V_150 = true ;
V_5 -> V_151 = V_147 ;
return 1 ;
}
}
static int F_59 ( struct V_4 * V_5 , void * V_152 , int * V_144 ,
int V_145 )
{
struct V_116 * V_8 = V_152 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_57 ] ;
struct V_15 * V_12 = & V_5 -> V_12 ;
F_14 ( V_139 , L_17 ,
V_8 -> V_24 . V_10 , V_8 -> V_127 , V_2 -> V_59 ) ;
if ( F_23 ( V_8 -> V_24 . V_10 != V_119 ) )
return 0 ;
if ( F_23 ( V_8 -> V_127 != V_2 -> V_59 ) ) {
F_4 ( L_18 ,
V_8 -> V_127 , V_2 -> V_59 ) ;
return 0 ;
}
if ( ! V_5 -> V_150 )
V_2 -> V_59 ++ ;
return F_56 ( V_5 , V_2 , V_8 -> V_122 , V_8 -> V_123 ,
V_144 , V_145 ) ;
}
static int F_60 ( struct V_1 * V_2 , T_1 V_115 )
{
T_1 V_153 = V_2 -> V_154 ;
int V_155 = 0 ;
while ( V_153 != V_2 -> V_156 ) {
if ( V_153 == V_115 ) {
V_155 = 1 ;
break;
}
V_153 = F_58 ( V_2 , V_153 ) ;
}
return V_155 ;
}
static int F_61 ( struct V_4 * V_5 , void * V_152 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_116 * V_8 = V_152 ;
struct V_16 * V_17 ;
struct V_157 * V_18 ;
T_1 V_115 ;
struct V_85 * V_86 ;
struct V_158 * V_159 ;
if ( F_23 ( V_8 -> V_24 . V_10 != V_119 ) )
return 0 ;
V_115 = V_8 -> V_123 ;
V_18 = V_5 -> V_18 ;
V_17 = V_18 -> V_17 ;
F_62 ( V_17 ) ;
if ( F_23 ( ! F_60 ( V_2 , V_115 ) ) ) {
F_63 ( V_17 ) ;
return 0 ;
}
V_2 -> V_154 = F_58 ( V_2 , V_115 ) ;
V_86 = F_64 ( V_2 , V_2 -> V_154 ) ;
if ( V_86 -> V_117 . V_124 == V_138 && ! V_5 -> V_160 ) {
if ( F_65 ( V_5 , V_2 -> V_154 ) > 0 )
V_5 -> V_160 = false ;
else
V_5 -> V_160 = true ;
} else {
V_5 -> V_160 = true ;
}
F_63 ( V_17 ) ;
V_159 = F_66 ( V_17 , V_5 -> V_161 ) ;
if ( F_23 ( F_67 ( V_159 ) &&
F_1 ( V_2 ) >= F_68 ( V_2 ) ) )
return 1 ;
return 0 ;
}
static int F_69 ( struct V_4 * V_5 , void * V_152 )
{
return 0 ;
}
static int F_70 ( struct V_4 * V_5 , void * V_152 )
{
struct V_162 * V_8 = V_152 ;
if ( V_8 -> V_24 . V_9 != V_55 )
F_4 ( L_19 ,
V_5 -> V_18 -> V_17 -> V_163 ,
V_8 -> V_24 . type ,
V_8 -> V_24 . V_9 ,
V_8 -> V_24 . V_10 ,
V_8 -> V_24 . V_11 ) ;
return 0 ;
}
static void F_71 ( struct V_4 * V_5 )
{
struct V_158 * V_159 ;
V_159 = F_66 ( V_5 -> V_18 -> V_17 , V_5 -> V_161 ) ;
F_72 ( V_159 , F_73 () ) ;
if ( F_74 ( F_67 ( V_159 ) ) ) {
struct V_1 * V_2 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
F_75 ( V_159 ) ;
}
F_76 ( V_159 ) ;
}
static inline bool F_77 ( struct V_4 * V_157 )
{
struct V_15 * V_12 = & V_157 -> V_12 ;
return ! ! ( V_12 -> V_164 & V_165 ) ;
}
static int F_78 ( struct V_4 * V_5 , int V_145 )
{
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_166 , V_23 ;
int V_144 = 0 ;
int V_167 = ( V_5 -> V_168 & V_169 ) ;
V_170:
if ( F_23 ( V_167 == V_169 ||
V_167 == V_171 ) ) {
F_79 ( V_12 , V_167 ) ;
if ( V_167 == V_169 ) {
V_5 -> V_37 = 0 ;
V_5 -> V_44 = true ;
V_5 -> V_46 = 0 ;
F_80 ( V_12 ) ;
}
V_5 -> V_168 = 0 ;
return 0 ;
}
V_167 = ( V_5 -> V_168 & V_171 ) ;
V_5 -> V_168 &= ~ ( V_169 | V_171 ) ;
if ( V_167 == V_171 )
goto V_170;
V_167 = V_5 -> V_168 ;
if ( ! ( V_167 & V_172 ) )
return 0 ;
F_52 ( V_167 != V_172 ) ;
V_166 = V_23 = 0 ;
while ( 1 ) {
union {
struct V_7 V_24 ;
V_35 V_173 [ 8 ] ;
} V_152 ;
if ( V_5 -> V_150 ) {
struct V_116 * V_8 =
(struct V_116 * ) & V_152 ;
struct V_1 * V_2 =
& V_5 -> V_12 . V_56 [ V_57 ] ;
V_8 -> V_24 . type = V_118 ;
V_8 -> V_24 . V_9 = V_26 ;
V_8 -> V_24 . V_10 = V_119 ;
V_8 -> V_127 = V_2 -> V_59 ;
V_8 -> V_122 = F_58 ( V_2 , V_5 -> V_151 ) ;
V_8 -> V_123 = - 1 ;
goto V_150;
}
V_23 = F_81 ( V_12 -> V_13 , & V_152 , sizeof( V_152 ) ) ;
if ( F_23 ( V_23 < 0 ) ) {
if ( V_23 == - V_14 )
F_82 ( V_12 ) ;
break;
}
if ( V_23 == 0 )
break;
F_14 ( V_139 , L_20 ,
V_152 . V_24 . type ,
V_152 . V_24 . V_9 ,
V_152 . V_24 . V_10 ,
V_152 . V_24 . V_11 ) ;
V_23 = F_83 ( V_12 , & V_152 . V_24 ) ;
if ( V_23 < 0 )
break;
V_150:
if ( F_74 ( V_152 . V_24 . type == V_118 ) ) {
if ( V_152 . V_24 . V_9 == V_26 ) {
if ( ! F_77 ( V_5 ) ) {
V_23 = - V_14 ;
break;
}
V_23 = F_59 ( V_5 , & V_152 , & V_144 , V_145 ) ;
if ( V_144 >= V_145 )
break;
if ( V_144 == 0 )
break;
} else if ( V_152 . V_24 . V_9 == V_55 ) {
V_23 = F_61 ( V_5 , & V_152 ) ;
if ( V_23 > 0 )
V_166 |= V_23 ;
} else if ( V_152 . V_24 . V_9 == V_54 ) {
V_23 = F_69 ( V_5 , & V_152 ) ;
}
} else if ( V_152 . V_24 . type == V_25 ) {
if ( V_152 . V_24 . V_10 == V_174 )
V_23 = F_70 ( V_5 , & V_152 ) ;
else
V_23 = F_84 ( V_12 , & V_152 ) ;
if ( V_23 )
break;
} else {
V_23 = F_3 ( V_5 , & V_152 ) ;
}
if ( V_23 == - V_14 )
break;
}
if ( F_23 ( V_166 && V_23 != - V_14 ) )
F_71 ( V_5 ) ;
return V_144 ;
}
static int F_85 ( struct V_175 * V_112 , int V_145 )
{
struct V_4 * V_5 = F_86 ( V_112 , struct V_4 , V_112 ) ;
struct V_15 * V_12 = & V_5 -> V_12 ;
int V_176 = F_78 ( V_5 , V_145 ) ;
if ( V_176 < V_145 ) {
F_87 ( V_112 ) ;
V_5 -> V_168 &= ~ V_172 ;
F_88 ( V_12 -> V_177 -> V_178 , V_179 ) ;
}
return V_176 ;
}
static void F_89 ( void * V_6 , int V_167 )
{
struct V_4 * V_5 = V_6 ;
struct V_15 * V_12 = & V_5 -> V_12 ;
V_5 -> V_168 |= V_167 ;
F_88 ( V_12 -> V_177 -> V_178 , V_180 ) ;
F_90 ( & V_5 -> V_112 ) ;
}
static int F_65 ( struct V_4 * V_5 , T_1 V_114 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_116 V_117 = {
. V_24 = {
. type = V_118 ,
. V_9 = V_26 ,
. V_10 = V_119 ,
. V_11 = F_9 ( & V_5 -> V_12 ) ,
} ,
. V_120 = V_2 -> V_121 ,
. V_122 = V_114 ,
. V_123 = ( T_1 ) - 1 ,
} ;
int V_23 , V_125 ;
int V_126 = 0 ;
if ( V_5 -> V_133 ) {
V_23 = F_43 ( V_5 ,
& V_5 -> V_12 . V_56 [ V_57 ] ,
V_5 -> V_132 , - 1 ,
V_131 ) ;
if ( V_23 <= 0 )
return V_23 ;
}
V_117 . V_127 = V_2 -> V_58 ;
V_125 = 1 ;
do {
V_23 = F_15 ( & V_5 -> V_12 , & V_117 , sizeof( V_117 ) ) ;
if ( V_23 > 0 ) {
V_2 -> V_58 ++ ;
break;
}
F_44 ( V_125 ) ;
if ( ( V_125 <<= 1 ) > 128 )
V_125 = 128 ;
if ( V_126 ++ > V_128 )
break;
} while ( V_23 == - V_130 );
return V_23 ;
}
struct V_4 * F_91 ( struct V_157 * V_18 , struct V_61 * V_63 )
{
unsigned int V_181 = F_92 ( V_63 -> V_66 ) ;
struct V_182 * V_183 = & V_18 -> V_184 [ V_181 ] ;
struct V_4 * V_5 ;
F_93 (port, hp, hash) {
if ( ! F_77 ( V_5 ) )
continue;
if ( F_94 ( V_5 -> V_129 , V_63 -> V_66 ) )
return V_5 ;
}
F_95 (port, &vp->port_list, list) {
if ( ! V_5 -> V_109 )
continue;
if ( ! F_77 ( V_5 ) )
continue;
return V_5 ;
}
return NULL ;
}
static struct V_61 * F_96 ( struct V_4 * V_5 ,
unsigned * V_185 )
{
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_61 * V_63 = NULL ;
int V_22 , V_186 ;
* V_185 = 0 ;
V_186 = V_2 -> V_156 - 1 ;
if ( V_186 < 0 )
V_186 = V_3 - 1 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_85 * V_187 ;
V_187 = F_64 ( V_2 , V_186 ) ;
if ( V_187 -> V_117 . V_124 == V_143 ) {
if ( V_5 -> V_188 [ V_186 ] . V_63 ) {
F_52 ( V_5 -> V_188 [ V_186 ] . V_63 -> V_189 ) ;
V_5 -> V_188 [ V_186 ] . V_63 -> V_189 = V_63 ;
V_63 = V_5 -> V_188 [ V_186 ] . V_63 ;
V_5 -> V_188 [ V_186 ] . V_63 = NULL ;
F_97 ( V_5 -> V_12 . V_13 ,
V_5 -> V_188 [ V_186 ] . V_97 ,
V_5 -> V_188 [ V_186 ] . V_98 ) ;
}
V_187 -> V_117 . V_124 = V_190 ;
} else if ( V_187 -> V_117 . V_124 == V_138 ) {
( * V_185 ) ++ ;
} else if ( V_187 -> V_117 . V_124 == V_190 ) {
break;
}
-- V_186 ;
if ( V_186 < 0 )
V_186 = V_3 - 1 ;
}
return V_63 ;
}
static inline void F_98 ( struct V_61 * V_63 )
{
struct V_61 * V_189 ;
while ( V_63 ) {
V_189 = V_63 -> V_189 ;
V_63 -> V_189 = NULL ;
F_99 ( V_63 ) ;
V_63 = V_189 ;
}
}
static void F_100 ( unsigned long V_191 )
{
struct V_4 * V_5 = (struct V_4 * ) V_191 ;
struct V_61 * V_192 ;
unsigned V_185 ;
F_62 ( V_5 -> V_18 -> V_17 ) ;
V_192 = F_96 ( V_5 , & V_185 ) ;
F_63 ( V_5 -> V_18 -> V_17 ) ;
F_98 ( V_192 ) ;
if ( V_185 )
( void ) F_101 ( & V_5 -> V_193 ,
V_194 + V_195 ) ;
else
F_102 ( & V_5 -> V_193 ) ;
}
static inline int F_103 ( struct V_196 * V_13 , struct V_61 * V_63 ,
struct V_197 * V_97 , int V_98 ,
unsigned int V_198 )
{
int V_22 , V_199 , V_23 , V_200 ;
V_200 = F_104 ( V_63 ) ;
if ( V_200 < V_90 )
V_200 = V_90 ;
V_200 += V_64 ;
V_200 += 8 - ( V_200 & 7 ) ;
V_23 = F_105 ( V_13 , V_63 -> V_66 - V_64 , V_200 , V_97 ,
V_98 , V_198 ) ;
if ( V_23 < 0 )
return V_23 ;
V_199 = V_23 ;
for ( V_22 = 0 ; V_22 < F_106 ( V_63 ) -> V_201 ; V_22 ++ ) {
T_3 * V_202 = & F_106 ( V_63 ) -> V_203 [ V_22 ] ;
T_2 * V_204 ;
if ( V_199 < V_98 ) {
V_204 = F_107 ( F_108 ( V_202 ) ) ;
V_200 = F_109 ( V_202 ) ;
V_200 += 8 - ( V_200 & 7 ) ;
V_23 = F_105 ( V_13 , V_204 + V_202 -> V_205 ,
V_200 , V_97 + V_199 , V_98 - V_199 ,
V_198 ) ;
F_110 ( V_204 ) ;
} else {
V_23 = - V_89 ;
}
if ( V_23 < 0 ) {
F_97 ( V_13 , V_97 , V_199 ) ;
return V_23 ;
}
V_199 += V_23 ;
}
return V_199 ;
}
static inline struct V_61 * F_111 ( struct V_61 * V_63 , int V_98 )
{
struct V_61 * V_206 ;
int V_22 , V_62 , V_207 , V_208 ;
V_62 = V_63 -> V_62 ;
V_207 = 0 ;
if ( V_62 < V_90 ) {
V_207 += V_90 - V_63 -> V_62 ;
V_62 += V_207 ;
}
V_62 += V_64 ;
V_207 += 8 - ( V_62 & 7 ) ;
V_208 = F_106 ( V_63 ) -> V_201 >= V_98 ;
for ( V_22 = 0 ; V_22 < F_106 ( V_63 ) -> V_201 ; V_22 ++ ) {
T_3 * V_202 = & F_106 ( V_63 ) -> V_203 [ V_22 ] ;
V_208 |= V_202 -> V_205 & 7 ;
}
if ( ( ( unsigned long ) V_63 -> V_66 & 7 ) != V_64 ||
F_112 ( V_63 ) < V_207 ||
F_113 ( V_63 ) < V_64 || V_208 ) {
int V_114 = 0 , V_69 ;
T_4 V_77 ;
V_62 = V_63 -> V_62 > V_90 ? V_63 -> V_62 : V_90 ;
V_206 = F_21 ( V_63 -> V_17 , V_62 ) ;
if ( V_206 == NULL ) {
F_99 ( V_63 ) ;
return NULL ;
}
F_24 ( V_206 , V_64 ) ;
V_206 -> V_70 = V_63 -> V_70 ;
V_69 = F_114 ( V_63 ) - V_63 -> V_66 ;
F_115 ( V_206 , V_69 ) ;
V_69 = F_116 ( V_63 ) - V_63 -> V_66 ;
F_117 ( V_206 , V_69 ) ;
V_69 = F_118 ( V_63 ) - V_63 -> V_66 ;
F_119 ( V_206 , V_69 ) ;
V_69 = 0 ;
V_206 -> V_209 = V_63 -> V_209 ;
V_206 -> V_74 = V_63 -> V_74 ;
if ( V_63 -> V_74 == V_107 )
V_114 = F_120 ( V_63 ) ;
if ( V_114 ) {
struct V_67 * V_68 = F_26 ( V_206 ) ;
int V_69 = V_114 + V_206 -> V_209 ;
if ( F_121 ( V_63 , 0 , V_206 -> V_66 , V_114 ) ) {
F_99 ( V_206 ) ;
F_99 ( V_63 ) ;
return NULL ;
}
* ( V_210 * ) ( V_63 -> V_66 + V_69 ) = 0 ;
V_77 = F_122 ( V_63 , V_114 ,
V_206 -> V_66 + V_114 ,
V_63 -> V_62 - V_114 , 0 ) ;
if ( V_68 -> V_70 == V_72 ||
V_68 -> V_70 == V_73 ) {
V_77 = F_31 ( V_68 -> V_81 , V_68 -> V_82 ,
V_63 -> V_62 - V_114 ,
V_68 -> V_70 , V_77 ) ;
}
* ( V_210 * ) ( V_206 -> V_66 + V_69 ) = V_77 ;
V_206 -> V_74 = V_75 ;
} else if ( F_121 ( V_63 , 0 , V_206 -> V_66 , V_63 -> V_62 ) ) {
F_99 ( V_206 ) ;
F_99 ( V_63 ) ;
return NULL ;
}
( void ) F_34 ( V_206 , V_63 -> V_62 ) ;
if ( F_123 ( V_63 ) ) {
F_106 ( V_206 ) -> V_211 = F_106 ( V_63 ) -> V_211 ;
F_106 ( V_206 ) -> V_212 = F_106 ( V_63 ) -> V_212 ;
}
V_206 -> V_213 = V_63 -> V_213 ;
F_99 ( V_63 ) ;
V_63 = V_206 ;
}
return V_63 ;
}
static T_5
F_124 ( struct V_16 * V_17 , struct V_61 * V_63 ,
void * V_214 , T_6 V_215 )
{
struct V_157 * V_18 = F_125 ( V_17 ) ;
struct V_4 * V_5 = F_91 ( V_18 , V_63 ) ;
if ( V_5 == NULL )
return 0 ;
return V_5 -> V_161 ;
}
static int F_126 ( struct V_4 * V_5 , struct V_61 * V_63 )
{
struct V_16 * V_17 = V_5 -> V_18 -> V_17 ;
struct V_1 * V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
struct V_61 * V_216 ;
int V_217 , V_218 ;
int V_219 ;
int V_211 , V_212 , V_220 ;
int V_221 = F_118 ( V_63 ) - F_114 ( V_63 ) ;
int V_222 = V_223 ;
if ( V_63 -> V_70 == F_28 ( V_71 ) )
V_222 = F_26 ( V_63 ) -> V_70 ;
else if ( V_63 -> V_70 == F_28 ( V_224 ) )
V_222 = F_127 ( V_63 ) -> V_225 ;
if ( V_222 == V_72 )
V_221 += F_29 ( V_63 ) -> V_226 * 4 ;
else if ( V_222 == V_73 )
V_221 += sizeof( struct V_83 ) ;
else {
F_4 ( L_21
L_22 , V_63 -> V_70 , V_222 ) ;
V_221 = 128 ;
}
V_218 = V_5 -> V_46 - V_221 ;
V_211 = F_106 ( V_63 ) -> V_211 ;
V_212 = F_106 ( V_63 ) -> V_212 ;
V_220 = F_106 ( V_63 ) -> V_220 ;
if ( V_5 -> V_44 && V_211 < V_218 )
V_220 = F_128 ( V_63 -> V_62 - V_221 , V_218 ) ;
if ( F_23 ( F_1 ( V_2 ) < V_220 ) ) {
struct V_158 * V_159 ;
V_159 = F_66 ( V_17 , V_5 -> V_161 ) ;
F_129 ( V_159 ) ;
if ( F_1 ( V_2 ) < F_106 ( V_63 ) -> V_220 )
return V_227 ;
F_75 ( V_159 ) ;
}
V_217 = F_116 ( V_63 ) - F_114 ( V_63 ) ;
F_36 ( V_63 , V_217 ) ;
if ( V_5 -> V_44 && V_211 < V_218 ) {
F_106 ( V_63 ) -> V_211 = V_218 ;
F_106 ( V_63 ) -> V_220 = V_220 ;
V_216 = F_130 ( V_63 , V_17 -> V_228 & ~ V_229 ) ;
F_106 ( V_63 ) -> V_211 = V_211 ;
F_106 ( V_63 ) -> V_220 = F_128 ( V_63 -> V_62 - V_221 ,
V_211 ) ;
} else
V_216 = F_130 ( V_63 , V_17 -> V_228 & ~ V_229 ) ;
if ( F_53 ( V_216 ) ) {
V_17 -> V_91 . V_230 ++ ;
F_131 ( V_63 ) ;
return V_231 ;
}
F_132 ( V_63 , V_217 ) ;
F_133 ( V_63 ) ;
V_219 = 0 ;
while ( V_216 ) {
struct V_61 * V_232 = V_216 ;
V_216 = V_216 -> V_189 ;
V_232 -> V_189 = NULL ;
if ( V_5 -> V_44 && V_232 -> V_62 > V_17 -> V_39 ) {
F_106 ( V_232 ) -> V_211 = V_211 ;
F_106 ( V_232 ) -> V_212 = V_212 ;
F_106 ( V_232 ) -> V_220 =
F_128 ( V_232 -> V_62 - V_221 , V_211 ) ;
} else
F_106 ( V_232 ) -> V_211 = 0 ;
F_132 ( V_232 , V_217 ) ;
F_133 ( V_232 ) ;
memcpy ( F_114 ( V_232 ) , F_114 ( V_63 ) ,
V_217 ) ;
V_232 -> V_233 = F_118 ( V_232 ) - V_232 -> V_234 ;
if ( F_26 ( V_232 ) -> V_70 == V_72 )
V_232 -> V_209 = F_134 ( struct V_78 , V_80 ) ;
else if ( F_26 ( V_232 ) -> V_70 == V_73 )
V_232 -> V_209 = F_134 ( struct V_83 , V_80 ) ;
if ( ! ( V_219 & V_235 ) )
V_219 = F_135 ( V_232 , V_17 ) ;
if ( V_219 & V_235 )
F_131 ( V_232 ) ;
}
if ( ! ( V_219 & V_235 ) )
F_131 ( V_63 ) ;
return V_219 ;
}
static int F_135 ( struct V_61 * V_63 , struct V_16 * V_17 )
{
struct V_157 * V_18 = F_125 ( V_17 ) ;
struct V_4 * V_5 = NULL ;
struct V_1 * V_2 ;
struct V_85 * V_187 ;
unsigned int V_62 ;
struct V_61 * V_192 = NULL ;
int V_22 , V_23 , V_186 ;
unsigned V_185 = 0 ;
struct V_158 * V_159 ;
F_136 () ;
V_5 = F_91 ( V_18 , V_63 ) ;
if ( F_23 ( ! V_5 ) ) {
F_137 () ;
goto V_93;
}
if ( F_123 ( V_63 ) && V_63 -> V_62 > V_5 -> V_46 ) {
V_23 = F_126 ( V_5 , V_63 ) ;
F_137 () ;
return V_23 ;
}
if ( ! F_123 ( V_63 ) && V_63 -> V_62 > V_5 -> V_37 ) {
unsigned long V_52 = V_5 -> V_37 - V_236 ;
if ( F_13 ( & V_5 -> V_12 , 1 , 3 ) )
V_52 -= V_42 ;
if ( V_63 -> V_70 == F_28 ( V_71 ) ) {
struct V_237 V_238 ;
struct V_239 * V_240 = NULL ;
memset ( & V_238 , 0 , sizeof( V_238 ) ) ;
V_238 . V_241 = V_17 -> V_242 ;
V_238 . V_243 = F_138 ( F_26 ( V_63 ) -> V_244 ) ;
V_238 . V_82 = F_26 ( V_63 ) -> V_82 ;
V_238 . V_81 = F_26 ( V_63 ) -> V_81 ;
V_240 = F_139 ( F_140 ( V_17 ) , & V_238 ) ;
F_137 () ;
if ( ! F_53 ( V_240 ) ) {
F_141 ( V_63 , & V_240 -> V_245 ) ;
F_142 ( V_63 , V_246 ,
V_247 ,
F_143 ( V_52 ) ) ;
}
}
#if F_144 ( V_248 )
else if ( V_63 -> V_70 == F_28 ( V_224 ) )
F_145 ( V_63 , V_249 , 0 , V_52 ) ;
#endif
goto V_93;
}
V_63 = F_111 ( V_63 , 2 ) ;
if ( F_23 ( ! V_63 ) )
goto V_93;
if ( V_63 -> V_74 == V_107 )
F_25 ( V_63 ) ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
V_22 = F_146 ( V_63 ) ;
V_159 = F_66 ( V_17 , V_22 ) ;
if ( F_23 ( F_1 ( V_2 ) < 1 ) ) {
if ( ! F_67 ( V_159 ) ) {
F_129 ( V_159 ) ;
F_147 ( V_17 , L_23 ) ;
V_17 -> V_91 . V_250 ++ ;
}
F_137 () ;
return V_227 ;
}
V_187 = F_148 ( V_2 ) ;
V_186 = V_2 -> V_156 ;
V_192 = F_96 ( V_5 , & V_185 ) ;
F_52 ( V_5 -> V_188 [ V_186 ] . V_63 ) ;
V_62 = V_63 -> V_62 ;
if ( V_62 < V_90 )
V_62 = V_90 ;
V_23 = F_103 ( V_5 -> V_12 . V_13 , V_63 , V_5 -> V_188 [ V_186 ] . V_97 , 2 ,
( V_251 | V_252 | V_253 ) ) ;
if ( V_23 < 0 ) {
F_149 ( V_17 , L_24 , V_23 ) ;
goto V_93;
}
V_5 -> V_188 [ V_186 ] . V_63 = V_63 ;
V_63 = NULL ;
V_5 -> V_188 [ V_186 ] . V_98 = V_23 ;
V_187 -> V_117 . V_140 = V_254 ;
V_187 -> V_87 = V_62 ;
V_187 -> V_98 = V_5 -> V_188 [ V_186 ] . V_98 ;
for ( V_22 = 0 ; V_22 < V_187 -> V_98 ; V_22 ++ )
V_187 -> V_97 [ V_22 ] = V_5 -> V_188 [ V_186 ] . V_97 [ V_22 ] ;
if ( F_13 ( & V_5 -> V_12 , 1 , 7 ) ) {
struct V_101 * V_102 = F_39 ( V_187 ) ;
memset ( V_102 , 0 , sizeof( * V_102 ) ) ;
if ( F_123 ( V_5 -> V_188 [ V_186 ] . V_63 ) ) {
V_102 -> V_255 = F_106 ( V_5 -> V_188 [ V_186 ] . V_63 )
-> V_211 ;
V_102 -> V_103 |= V_256 ;
}
if ( F_13 ( & V_5 -> V_12 , 1 , 8 ) &&
! V_5 -> V_109 ) {
V_102 -> V_103 |= V_106 ;
V_102 -> V_103 |= V_108 ;
}
}
F_150 () ;
V_187 -> V_117 . V_124 = V_138 ;
if ( ! V_5 -> V_160 )
goto V_257;
V_23 = F_65 ( V_5 , V_2 -> V_154 ) ;
if ( F_23 ( V_23 < 0 ) ) {
F_149 ( V_17 , L_25 , V_23 ) ;
V_187 -> V_117 . V_124 = V_190 ;
V_17 -> V_91 . V_258 ++ ;
goto V_93;
}
V_257:
V_5 -> V_160 = false ;
V_17 -> V_91 . V_259 ++ ;
V_17 -> V_91 . V_260 += V_5 -> V_188 [ V_186 ] . V_63 -> V_62 ;
V_2 -> V_156 = ( V_2 -> V_156 + 1 ) & ( V_3 - 1 ) ;
if ( F_23 ( F_1 ( V_2 ) < 1 ) ) {
F_129 ( V_159 ) ;
if ( F_1 ( V_2 ) > F_68 ( V_2 ) )
F_75 ( V_159 ) ;
}
( void ) F_101 ( & V_5 -> V_193 , V_194 + V_195 ) ;
F_137 () ;
F_98 ( V_192 ) ;
return V_231 ;
V_93:
if ( V_185 )
( void ) F_101 ( & V_5 -> V_193 ,
V_194 + V_195 ) ;
else if ( V_5 )
F_102 ( & V_5 -> V_193 ) ;
if ( V_5 )
F_137 () ;
if ( V_63 )
F_99 ( V_63 ) ;
F_98 ( V_192 ) ;
V_17 -> V_91 . V_230 ++ ;
return V_231 ;
}
static void F_151 ( struct V_16 * V_17 )
{
}
static int F_152 ( struct V_16 * V_17 )
{
F_153 ( V_17 ) ;
F_154 ( V_17 ) ;
return 0 ;
}
static int F_155 ( struct V_16 * V_17 )
{
F_156 ( V_17 ) ;
F_157 ( V_17 ) ;
return 0 ;
}
static struct V_261 * F_158 ( struct V_157 * V_18 , T_2 * V_34 )
{
struct V_261 * V_262 ;
for ( V_262 = V_18 -> V_263 ; V_262 ; V_262 = V_262 -> V_189 ) {
if ( F_94 ( V_262 -> V_34 , V_34 ) )
return V_262 ;
}
return NULL ;
}
static void F_159 ( struct V_157 * V_18 , struct V_16 * V_17 )
{
struct V_264 * V_265 ;
F_160 (ha, dev) {
struct V_261 * V_262 ;
V_262 = F_158 ( V_18 , V_265 -> V_34 ) ;
if ( V_262 ) {
V_262 -> V_266 = 1 ;
continue;
}
if ( ! V_262 ) {
V_262 = F_161 ( sizeof( * V_262 ) , V_267 ) ;
if ( ! V_262 )
continue;
memcpy ( V_262 -> V_34 , V_265 -> V_34 , V_268 ) ;
V_262 -> V_266 = 1 ;
V_262 -> V_189 = V_18 -> V_263 ;
V_18 -> V_263 = V_262 ;
}
}
}
static void F_162 ( struct V_157 * V_18 , struct V_4 * V_5 )
{
struct V_162 V_269 ;
struct V_261 * V_262 , * * V_270 ;
int V_271 ;
memset ( & V_269 , 0 , sizeof( V_269 ) ) ;
V_269 . V_24 . type = V_25 ;
V_269 . V_24 . V_9 = V_26 ;
V_269 . V_24 . V_10 = V_174 ;
V_269 . V_24 . V_11 = F_9 ( & V_5 -> V_12 ) ;
V_269 . V_272 = 1 ;
V_271 = 0 ;
for ( V_262 = V_18 -> V_263 ; V_262 ; V_262 = V_262 -> V_189 ) {
if ( V_262 -> V_273 )
continue;
V_262 -> V_273 = 1 ;
memcpy ( & V_269 . V_274 [ V_271 * V_268 ] ,
V_262 -> V_34 , V_268 ) ;
if ( ++ V_271 == V_275 ) {
V_269 . V_276 = V_271 ;
( void ) F_15 ( & V_5 -> V_12 , & V_269 ,
sizeof( V_269 ) ) ;
V_271 = 0 ;
}
}
if ( V_271 ) {
V_269 . V_276 = V_271 ;
( void ) F_15 ( & V_5 -> V_12 , & V_269 , sizeof( V_269 ) ) ;
}
V_269 . V_272 = 0 ;
V_271 = 0 ;
V_270 = & V_18 -> V_263 ;
while ( ( V_262 = * V_270 ) != NULL ) {
if ( V_262 -> V_266 ) {
V_262 -> V_266 = 0 ;
V_270 = & V_262 -> V_189 ;
continue;
}
memcpy ( & V_269 . V_274 [ V_271 * V_268 ] ,
V_262 -> V_34 , V_268 ) ;
if ( ++ V_271 == V_275 ) {
V_269 . V_276 = V_271 ;
( void ) F_15 ( & V_5 -> V_12 , & V_269 ,
sizeof( V_269 ) ) ;
V_271 = 0 ;
}
* V_270 = V_262 -> V_189 ;
F_163 ( V_262 ) ;
}
if ( V_271 ) {
V_269 . V_276 = V_271 ;
( void ) F_15 ( & V_5 -> V_12 , & V_269 , sizeof( V_269 ) ) ;
}
}
static void F_164 ( struct V_16 * V_17 )
{
struct V_157 * V_18 = F_125 ( V_17 ) ;
struct V_4 * V_5 ;
F_136 () ;
F_95 (port, &vp->port_list, list) {
if ( V_5 -> V_109 ) {
F_159 ( V_18 , V_17 ) ;
F_162 ( V_18 , V_5 ) ;
break;
}
}
F_137 () ;
}
static int F_165 ( struct V_16 * V_17 , int V_277 )
{
if ( V_277 < 68 || V_277 > 65535 )
return - V_278 ;
V_17 -> V_39 = V_277 ;
return 0 ;
}
static int F_166 ( struct V_16 * V_17 , void * V_279 )
{
return - V_278 ;
}
static void F_167 ( struct V_16 * V_17 ,
struct V_280 * V_269 )
{
F_168 ( V_269 -> V_281 , V_282 , sizeof( V_269 -> V_281 ) ) ;
F_168 ( V_269 -> V_283 , V_284 , sizeof( V_269 -> V_283 ) ) ;
}
static T_1 F_169 ( struct V_16 * V_17 )
{
struct V_157 * V_18 = F_125 ( V_17 ) ;
return V_18 -> V_285 ;
}
static void F_170 ( struct V_16 * V_17 , T_1 V_286 )
{
struct V_157 * V_18 = F_125 ( V_17 ) ;
V_18 -> V_285 = V_286 ;
}
static void F_171 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
int V_22 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
if ( V_2 -> V_287 ) {
F_172 ( V_5 -> V_12 . V_13 , V_2 -> V_287 ,
( V_2 -> V_136 * V_2 -> V_288 ) ,
V_2 -> V_97 , V_2 -> V_98 ) ;
V_2 -> V_287 = NULL ;
V_2 -> V_136 = 0 ;
V_2 -> V_288 = 0 ;
V_2 -> V_185 = 0 ;
V_2 -> V_98 = 0 ;
}
for ( V_22 = 0 ; V_22 < V_3 ; V_22 ++ ) {
struct V_85 * V_187 ;
void * V_63 = V_5 -> V_188 [ V_22 ] . V_63 ;
if ( ! V_63 )
continue;
V_187 = F_64 ( V_2 , V_22 ) ;
if ( V_187 -> V_117 . V_124 == V_138 )
F_173 ( L_26 ) ;
F_97 ( V_5 -> V_12 . V_13 ,
V_5 -> V_188 [ V_22 ] . V_97 ,
V_5 -> V_188 [ V_22 ] . V_98 ) ;
F_99 ( V_63 ) ;
V_5 -> V_188 [ V_22 ] . V_63 = NULL ;
V_187 -> V_117 . V_124 = V_190 ;
}
}
static int F_8 ( struct V_4 * V_5 )
{
struct V_1 * V_2 ;
unsigned long V_62 , V_289 ;
int V_22 , V_23 , V_98 ;
void * V_290 ;
V_2 = & V_5 -> V_12 . V_56 [ V_60 ] ;
V_289 = sizeof( struct V_85 ) +
sizeof( struct V_197 ) * 2 ;
if ( F_13 ( & V_5 -> V_12 , 1 , 7 ) )
V_289 += sizeof( struct V_101 ) ;
V_62 = V_3 * V_289 ;
V_98 = V_291 ;
V_290 = F_174 ( V_5 -> V_12 . V_13 , V_62 ,
V_2 -> V_97 , & V_98 ,
( V_251 |
V_252 |
V_253 ) ) ;
if ( F_53 ( V_290 ) ) {
V_23 = F_54 ( V_290 ) ;
goto V_292;
}
V_2 -> V_287 = V_290 ;
V_2 -> V_136 = V_289 ;
V_2 -> V_288 = V_3 ;
V_2 -> V_156 = V_2 -> V_154 = 0 ;
V_5 -> V_160 = true ;
V_2 -> V_185 = V_3 ;
V_2 -> V_98 = V_98 ;
for ( V_22 = 0 ; V_22 < V_3 ; ++ V_22 ) {
struct V_85 * V_187 ;
V_187 = F_64 ( V_2 , V_22 ) ;
V_187 -> V_117 . V_124 = V_190 ;
}
return 0 ;
V_292:
F_171 ( V_5 ) ;
return V_23 ;
}
static void F_175 ( struct V_16 * V_17 )
{
struct V_157 * V_18 = F_125 ( V_17 ) ;
struct V_4 * V_5 ;
unsigned long V_103 ;
F_176 ( & V_18 -> V_293 , V_103 ) ;
if ( ! F_177 ( & V_18 -> V_294 ) ) {
V_5 = F_178 ( V_18 -> V_294 . V_189 , struct V_4 , V_295 ) ;
F_90 ( & V_5 -> V_112 ) ;
}
F_179 ( & V_18 -> V_293 , V_103 ) ;
}
static struct V_157 * F_180 ( const V_35 * V_296 )
{
struct V_16 * V_17 ;
struct V_157 * V_18 ;
int V_23 , V_22 ;
V_17 = F_181 ( sizeof( * V_18 ) , V_297 , 1 ) ;
if ( ! V_17 )
return F_48 ( - V_94 ) ;
V_17 -> V_298 = V_64 + 8 ;
V_17 -> V_299 = 8 ;
for ( V_22 = 0 ; V_22 < V_268 ; V_22 ++ )
V_17 -> V_36 [ V_22 ] = ( * V_296 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_18 = F_125 ( V_17 ) ;
F_182 ( & V_18 -> V_293 ) ;
V_18 -> V_17 = V_17 ;
F_183 ( & V_18 -> V_294 ) ;
for ( V_22 = 0 ; V_22 < V_300 ; V_22 ++ )
F_184 ( & V_18 -> V_184 [ V_22 ] ) ;
F_183 ( & V_18 -> V_295 ) ;
V_18 -> V_296 = * V_296 ;
V_17 -> V_301 = & V_302 ;
V_17 -> V_303 = & V_304 ;
V_17 -> V_305 = V_306 ;
V_17 -> V_307 = V_229 | V_308 | V_309 |
V_310 | V_311 ;
V_17 -> V_228 = V_17 -> V_307 ;
V_23 = F_185 ( V_17 ) ;
if ( V_23 ) {
F_4 ( L_27 ) ;
goto V_312;
}
F_149 ( V_17 , L_28 , V_17 -> V_36 ) ;
F_186 ( & V_18 -> V_295 , & V_313 ) ;
return V_18 ;
V_312:
F_187 ( V_17 ) ;
return F_48 ( V_23 ) ;
}
static struct V_157 * F_188 ( const V_35 * V_296 )
{
struct V_157 * V_314 , * V_18 ;
F_189 ( & V_315 ) ;
V_18 = NULL ;
F_190 (iter, &vnet_list, list) {
if ( V_314 -> V_296 == * V_296 ) {
V_18 = V_314 ;
break;
}
}
if ( ! V_18 )
V_18 = F_180 ( V_296 ) ;
F_191 ( & V_315 ) ;
return V_18 ;
}
static void F_192 ( void )
{
struct V_157 * V_18 ;
struct V_16 * V_17 ;
F_189 ( & V_315 ) ;
while ( ! F_177 ( & V_313 ) ) {
V_18 = F_193 ( & V_313 , struct V_157 , V_295 ) ;
F_194 ( & V_18 -> V_295 ) ;
V_17 = V_18 -> V_17 ;
F_52 ( ! F_177 ( & V_18 -> V_294 ) ) ;
F_195 ( V_17 ) ;
F_187 ( V_17 ) ;
}
F_191 ( & V_315 ) ;
}
static struct V_157 * F_196 ( struct V_316 * V_183 ,
V_35 V_317 )
{
const V_35 * V_296 = NULL ;
V_35 V_318 ;
F_197 (a, hp, port_node, MDESC_ARC_TYPE_BACK) {
V_35 V_319 = F_198 ( V_183 , V_318 ) ;
const char * V_163 ;
V_163 = F_199 ( V_183 , V_319 , L_29 , NULL ) ;
if ( ! V_163 || strcmp ( V_163 , L_30 ) )
continue;
V_296 = F_199 ( V_183 , V_319 ,
V_320 , NULL ) ;
if ( V_296 )
break;
}
if ( ! V_296 )
return F_48 ( - V_321 ) ;
return F_188 ( V_296 ) ;
}
static void F_200 ( void )
{
F_201 ( V_322 L_31 , V_283 ) ;
}
static void
F_202 ( struct V_4 * V_5 )
{
struct V_157 * V_18 = V_5 -> V_18 ;
int V_323 ;
V_323 = V_18 -> V_324 ++ ;
V_323 = V_323 & ( V_297 - 1 ) ;
V_5 -> V_161 = V_323 ;
F_75 ( F_66 ( V_18 -> V_17 , V_5 -> V_161 ) ) ;
}
static void
F_203 ( struct V_4 * V_5 )
{
V_5 -> V_18 -> V_324 -- ;
F_129 ( F_66 ( V_5 -> V_18 -> V_17 , V_5 -> V_161 ) ) ;
}
static int F_204 ( struct V_325 * V_177 , const struct V_326 * V_327 )
{
struct V_316 * V_183 ;
struct V_4 * V_5 ;
unsigned long V_103 ;
struct V_157 * V_18 ;
const V_35 * V_328 ;
int V_62 , V_22 , V_23 , V_109 ;
F_200 () ;
V_183 = F_205 () ;
V_18 = F_196 ( V_183 , V_177 -> V_329 ) ;
if ( F_53 ( V_18 ) ) {
F_4 ( L_32 ) ;
V_23 = F_54 ( V_18 ) ;
goto V_330;
}
V_328 = F_199 ( V_183 , V_177 -> V_329 , V_331 , & V_62 ) ;
V_23 = - V_321 ;
if ( ! V_328 ) {
F_4 ( L_33 , V_331 ) ;
goto V_330;
}
V_5 = F_161 ( sizeof( * V_5 ) , V_332 ) ;
V_23 = - V_94 ;
if ( ! V_5 )
goto V_330;
for ( V_22 = 0 ; V_22 < V_268 ; V_22 ++ )
V_5 -> V_129 [ V_22 ] = ( * V_328 >> ( 5 - V_22 ) * 8 ) & 0xff ;
V_5 -> V_18 = V_18 ;
V_23 = F_206 ( & V_5 -> V_12 , V_177 , V_333 ,
V_334 , F_207 ( V_334 ) ,
& V_335 , V_18 -> V_17 -> V_163 ) ;
if ( V_23 )
goto V_336;
V_23 = F_208 ( & V_5 -> V_12 , & V_337 , V_5 ) ;
if ( V_23 )
goto V_336;
F_209 ( V_5 -> V_18 -> V_17 , & V_5 -> V_112 , F_85 , V_338 ) ;
F_210 ( & V_5 -> V_181 ) ;
F_183 ( & V_5 -> V_295 ) ;
V_109 = 0 ;
if ( F_199 ( V_183 , V_177 -> V_329 , L_34 , NULL ) != NULL )
V_109 = 1 ;
V_5 -> V_109 = V_109 ;
V_5 -> V_44 = true ;
V_5 -> V_46 = 0 ;
F_176 ( & V_18 -> V_293 , V_103 ) ;
if ( V_109 )
F_211 ( & V_5 -> V_295 , & V_18 -> V_294 ) ;
else
F_212 ( & V_5 -> V_295 , & V_18 -> V_294 ) ;
F_213 ( & V_5 -> V_181 ,
& V_18 -> V_184 [ F_92 ( V_5 -> V_129 ) ] ) ;
F_202 ( V_5 ) ;
F_179 ( & V_18 -> V_293 , V_103 ) ;
F_214 ( & V_177 -> V_17 , V_5 ) ;
F_45 ( L_35 ,
V_18 -> V_17 -> V_163 , V_5 -> V_129 , V_109 ? L_36 : L_37 ) ;
F_215 ( & V_5 -> V_193 , F_100 ,
( unsigned long ) V_5 ) ;
F_216 ( & V_5 -> V_112 ) ;
F_80 ( & V_5 -> V_12 ) ;
F_217 ( V_183 ) ;
return 0 ;
V_336:
F_163 ( V_5 ) ;
V_330:
F_217 ( V_183 ) ;
return V_23 ;
}
static int F_218 ( struct V_325 * V_177 )
{
struct V_4 * V_5 = F_219 ( & V_177 -> V_17 ) ;
if ( V_5 ) {
F_220 ( & V_5 -> V_12 . V_339 ) ;
F_221 ( & V_5 -> V_112 ) ;
F_222 ( & V_5 -> V_295 ) ;
F_223 ( & V_5 -> V_181 ) ;
F_224 () ;
F_220 ( & V_5 -> V_193 ) ;
F_203 ( V_5 ) ;
F_225 ( & V_5 -> V_112 ) ;
F_171 ( V_5 ) ;
F_226 ( & V_5 -> V_12 ) ;
F_214 ( & V_177 -> V_17 , NULL ) ;
F_163 ( V_5 ) ;
}
return 0 ;
}
static int T_7 F_227 ( void )
{
return F_228 ( & V_340 ) ;
}
static void T_8 F_229 ( void )
{
F_230 ( & V_340 ) ;
F_192 () ;
}
