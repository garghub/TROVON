void F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 ) {
F_2 ( & V_5 ) ;
F_3 ( & V_2 -> V_6 . V_7 ) ;
} else {
F_4 ( & V_8 ) ;
F_5 ( & V_2 -> V_6 . V_9 ) ;
}
}
void F_6 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 -> V_4 ) {
F_7 ( & V_2 -> V_6 . V_7 ) ;
F_8 ( & V_5 ) ;
} else {
F_9 ( & V_2 -> V_6 . V_9 ) ;
F_10 ( & V_8 ) ;
}
}
void F_11 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_3 -> V_4 )
F_12 () ;
F_1 ( V_2 ) ;
}
void F_13 ( struct V_1 * V_2 )
{
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 )
F_14 () ;
}
unsigned long F_15 ( struct V_1 * V_2 )
{
unsigned long V_10 = 0 ;
if ( ! V_2 -> V_3 -> V_4 )
F_16 ( V_10 ) ;
F_1 ( V_2 ) ;
return V_10 ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long V_10 )
{
F_6 ( V_2 ) ;
if ( ! V_2 -> V_3 -> V_4 )
F_18 ( V_10 ) ;
}
static inline T_1 F_19 ( void )
{
T_1 V_11 = F_20 () ;
F_21 ( F_22 () ) ;
return V_11 ;
}
static inline void F_23 ( T_1 V_11 )
{
F_21 ( V_11 ) ;
}
int F_24 ( struct V_1 * V_2 , struct F_24 * V_12 )
{
struct V_13 * V_14 ;
struct V_15 * V_3 = V_2 -> V_3 ;
struct V_16 * V_17 = V_2 -> V_17 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_18 = V_3 -> V_18 -> V_19 ;
V_12 -> V_20 = V_3 -> V_20 ;
V_12 -> V_21 = V_2 -> V_21 ;
V_12 -> V_22 = V_2 -> V_19 ;
F_25 ( V_12 -> V_23 , V_3 -> V_23 , sizeof( V_12 -> V_23 ) ) ;
F_25 ( V_12 -> V_24 , V_3 -> V_24 , sizeof( V_12 -> V_24 ) ) ;
V_12 -> V_25 = V_3 -> V_25 ;
V_12 -> V_26 = V_3 -> V_26 ;
V_12 -> V_27 = V_17 -> V_28 ;
V_12 -> V_29 = V_17 -> V_28 - V_17 -> V_30 ;
F_25 ( V_12 -> V_31 , V_2 -> V_24 , sizeof( V_12 -> V_31 ) ) ;
V_14 = V_2 -> V_14 ;
if ( V_14 ) {
V_12 -> V_32 = V_14 -> V_32 ;
V_2 -> V_33 -> V_34 ( V_2 , V_35 , V_12 ) ;
}
return 0 ;
}
int F_26 ( struct V_1 * V_2 ,
struct F_24 T_2 * V_36 )
{
struct F_24 * V_12 ;
int V_37 ;
V_12 = F_27 ( sizeof( * V_12 ) , V_38 ) ;
if ( ! V_12 )
return - V_39 ;
V_37 = F_24 ( V_2 , V_12 ) ;
if ( V_37 >= 0 ) {
if ( F_28 ( V_36 , V_12 , sizeof( * V_12 ) ) )
V_37 = - V_40 ;
}
F_29 ( V_12 ) ;
return V_37 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
unsigned int V_43 ;
struct V_44 * V_45 ;
struct V_46 * V_47 = NULL ;
struct V_48 * V_49 = NULL ;
struct V_50 * V_51 = & V_2 -> V_14 -> V_52 ;
unsigned int V_53 [ V_51 -> V_54 ] ;
unsigned int V_55 [ V_56 + 1 ] ;
unsigned int V_57 = 2 ;
int V_58 , V_59 ;
V_42 -> V_12 = 0 ;
V_42 -> V_60 = 0 ;
if ( V_42 -> V_61 & ( 1 << V_62 ) )
V_42 -> V_63 = 0 ;
if ( V_42 -> V_61 & ( 1 << V_64 ) ) {
V_42 -> V_65 = 0 ;
V_42 -> V_66 = 0 ;
}
for ( V_43 = V_67 ; V_43 <= V_68 ; V_43 ++ ) {
V_49 = F_31 ( V_42 , V_43 ) ;
if ( F_32 ( V_49 ) )
return - V_69 ;
if ( ! ( V_42 -> V_61 & ( 1 << V_43 ) ) )
continue;
#ifdef F_33
F_34 ( L_1 , V_70 [ V_43 ] ) ;
F_35 ( L_2 , V_49 -> V_71 [ 3 ] , V_49 -> V_71 [ 2 ] , V_49 -> V_71 [ 1 ] , V_49 -> V_71 [ 0 ] ) ;
#endif
V_58 = F_36 ( V_49 , F_37 ( V_51 , V_43 ) ) ;
#ifdef F_33
F_35 ( L_3 , V_49 -> V_71 [ 3 ] , V_49 -> V_71 [ 2 ] , V_49 -> V_71 [ 1 ] , V_49 -> V_71 [ 0 ] ) ;
#endif
if ( V_58 )
V_42 -> V_72 |= 1 << V_43 ;
if ( V_58 < 0 )
return V_58 ;
}
for ( V_43 = V_73 ; V_43 <= V_56 ; V_43 ++ ) {
V_47 = F_38 ( V_42 , V_43 ) ;
if ( F_39 ( V_47 ) )
return - V_69 ;
if ( ! ( V_42 -> V_61 & ( 1 << V_43 ) ) )
continue;
#ifdef F_33
F_34 ( L_1 , V_70 [ V_43 ] ) ;
if ( V_47 -> V_74 )
F_35 ( L_4 ) ;
else
F_35 ( L_5 ,
V_47 -> V_75 ? '(' : '[' , V_47 -> V_76 ,
V_47 -> V_77 , V_47 -> V_78 ? ')' : ']' ) ;
F_35 ( L_6 ) ;
#endif
V_58 = F_40 ( V_47 , F_41 ( V_51 , V_43 ) ) ;
#ifdef F_33
if ( V_47 -> V_74 )
F_35 ( L_7 ) ;
else
F_35 ( L_8 ,
V_47 -> V_75 ? '(' : '[' , V_47 -> V_76 ,
V_47 -> V_77 , V_47 -> V_78 ? ')' : ']' ) ;
#endif
if ( V_58 )
V_42 -> V_72 |= 1 << V_43 ;
if ( V_58 < 0 )
return V_58 ;
}
for ( V_43 = 0 ; V_43 < V_51 -> V_54 ; V_43 ++ )
V_53 [ V_43 ] = 0 ;
for ( V_43 = 0 ; V_43 <= V_56 ; V_43 ++ )
V_55 [ V_43 ] = ( V_42 -> V_61 & ( 1 << V_43 ) ) ? 1 : 0 ;
do {
V_59 = 0 ;
for ( V_43 = 0 ; V_43 < V_51 -> V_54 ; V_43 ++ ) {
struct V_79 * V_80 = & V_51 -> V_81 [ V_43 ] ;
unsigned int V_82 ;
int V_83 = 0 ;
if ( V_80 -> V_84 && ! ( V_80 -> V_84 & V_42 -> V_10 ) )
continue;
for ( V_82 = 0 ; V_80 -> V_85 [ V_82 ] >= 0 ; V_82 ++ ) {
if ( V_55 [ V_80 -> V_85 [ V_82 ] ] > V_53 [ V_43 ] ) {
V_83 = 1 ;
break;
}
}
if ( ! V_83 )
continue;
#ifdef F_33
F_34 ( L_9 , V_43 , V_80 -> V_86 ) ;
if ( V_80 -> V_87 >= 0 ) {
F_35 ( L_1 , V_70 [ V_80 -> V_87 ] ) ;
if ( F_42 ( V_80 -> V_87 ) ) {
V_49 = F_31 ( V_42 , V_80 -> V_87 ) ;
F_35 ( L_10 , * V_49 -> V_71 ) ;
} else {
V_47 = F_38 ( V_42 , V_80 -> V_87 ) ;
if ( V_47 -> V_74 )
F_35 ( L_4 ) ;
else
F_35 ( L_5 ,
V_47 -> V_75 ? '(' : '[' , V_47 -> V_76 ,
V_47 -> V_77 , V_47 -> V_78 ? ')' : ']' ) ;
}
}
#endif
V_58 = V_80 -> V_86 ( V_42 , V_80 ) ;
#ifdef F_33
if ( V_80 -> V_87 >= 0 ) {
F_35 ( L_6 ) ;
if ( F_42 ( V_80 -> V_87 ) )
F_35 ( L_10 , * V_49 -> V_71 ) ;
else {
if ( V_47 -> V_74 )
F_35 ( L_4 ) ;
else
F_35 ( L_5 ,
V_47 -> V_75 ? '(' : '[' , V_47 -> V_76 ,
V_47 -> V_77 , V_47 -> V_78 ? ')' : ']' ) ;
}
}
F_35 ( L_11 ) ;
#endif
V_53 [ V_43 ] = V_57 ;
if ( V_58 && V_80 -> V_87 >= 0 ) {
V_42 -> V_72 |= ( 1 << V_80 -> V_87 ) ;
V_55 [ V_80 -> V_87 ] = V_57 ;
V_59 = 1 ;
}
if ( V_58 < 0 )
return V_58 ;
V_57 ++ ;
}
} while ( V_59 );
if ( ! V_42 -> V_63 ) {
V_47 = F_38 ( V_42 , V_62 ) ;
if ( F_43 ( V_47 ) )
V_42 -> V_63 = F_44 ( V_47 ) ;
}
if ( ! V_42 -> V_66 ) {
V_47 = F_38 ( V_42 , V_64 ) ;
if ( F_43 ( V_47 ) ) {
V_42 -> V_65 = F_44 ( V_47 ) ;
V_42 -> V_66 = 1 ;
}
}
V_45 = & V_2 -> V_14 -> V_45 ;
if ( ! V_42 -> V_12 )
V_42 -> V_12 = V_45 -> V_12 & ~ V_88 ;
if ( ! V_42 -> V_60 ) {
V_49 = F_31 ( V_42 , V_89 ) ;
V_47 = F_38 ( V_42 , V_90 ) ;
if ( F_45 ( V_49 ) == F_46 ( V_49 ) &&
F_47 ( V_47 ) == F_48 ( V_47 ) ) {
V_58 = V_2 -> V_33 -> V_34 ( V_2 ,
V_91 , V_42 ) ;
if ( V_58 < 0 )
return V_58 ;
}
}
V_42 -> V_61 = 0 ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 ,
struct V_41 T_2 * V_92 )
{
struct V_41 * V_42 ;
int V_37 ;
V_42 = F_50 ( V_92 , sizeof( * V_42 ) ) ;
if ( F_51 ( V_42 ) )
return F_52 ( V_42 ) ;
V_37 = F_30 ( V_2 , V_42 ) ;
if ( F_28 ( V_92 , V_42 , sizeof( * V_42 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_42 ) ;
return V_37 ;
}
static int F_53 ( struct V_13 * V_14 )
{
int V_93 ;
if ( ! V_14 -> V_94 )
return - 1 ;
V_93 = ( 750000 / V_14 -> V_94 ) * V_14 -> V_95 ;
V_93 += ( ( 750000 % V_14 -> V_94 ) * V_14 -> V_95 ) /
V_14 -> V_94 ;
return V_93 ;
}
static void F_54 ( struct V_1 * V_2 , int V_96 )
{
F_11 ( V_2 ) ;
if ( V_2 -> V_14 -> V_97 -> V_96 != V_98 )
V_2 -> V_14 -> V_97 -> V_96 = V_96 ;
F_13 ( V_2 ) ;
}
static int V_41 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
struct V_13 * V_14 ;
int V_37 , V_93 ;
unsigned int V_71 ;
T_3 V_99 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_101 :
case V_102 :
case V_103 :
break;
default:
F_13 ( V_2 ) ;
return - V_104 ;
}
F_13 ( V_2 ) ;
#if F_56 ( V_105 )
if ( ! V_2 -> V_106 . V_106 )
#endif
if ( F_57 ( & V_2 -> V_107 ) )
return - V_104 ;
V_42 -> V_61 = ~ 0U ;
V_37 = F_30 ( V_2 , V_42 ) ;
if ( V_37 < 0 )
goto V_108;
V_37 = F_58 ( V_2 , V_42 ) ;
if ( V_37 < 0 )
goto V_108;
if ( V_2 -> V_33 -> V_109 != NULL ) {
V_37 = V_2 -> V_33 -> V_109 ( V_2 , V_42 ) ;
if ( V_37 < 0 )
goto V_108;
}
V_14 -> V_110 = F_59 ( V_42 ) ;
V_14 -> V_111 = F_60 ( V_42 ) ;
V_14 -> V_112 = F_61 ( V_42 ) ;
V_14 -> V_113 = F_62 ( V_42 ) ;
V_14 -> V_94 = F_63 ( V_42 ) ;
V_14 -> V_95 = F_64 ( V_42 ) ;
V_14 -> V_114 = F_65 ( V_42 ) ;
V_14 -> V_115 = F_66 ( V_42 ) ;
V_14 -> V_12 = V_42 -> V_12 ;
V_14 -> V_65 = V_42 -> V_65 ;
V_14 -> V_66 = V_42 -> V_66 ;
V_14 -> V_116 =
( V_42 -> V_12 & V_117 ) &&
( V_42 -> V_10 & V_118 ) ;
V_71 = F_67 ( V_14 -> V_111 ) ;
V_14 -> V_119 = V_71 ;
V_71 *= V_14 -> V_113 ;
V_14 -> V_120 = V_71 ;
V_99 = 1 ;
while ( V_71 % 8 != 0 ) {
V_71 *= 2 ;
V_99 *= 2 ;
}
V_14 -> V_121 = V_71 / 8 ;
V_14 -> V_122 = V_99 ;
V_14 -> V_123 = V_124 ;
V_14 -> V_125 = 1 ;
V_14 -> V_126 -> V_127 = V_14 -> V_95 ;
V_14 -> V_128 = 1 ;
V_14 -> V_129 = V_14 -> V_115 ;
V_14 -> V_130 = 0 ;
V_14 -> V_131 = 0 ;
V_14 -> V_132 = V_14 -> V_115 ;
while ( V_14 -> V_132 * 2 <= V_133 - V_14 -> V_115 )
V_14 -> V_132 *= 2 ;
F_68 ( V_2 ) ;
F_54 ( V_2 , V_102 ) ;
if ( F_69 ( & V_2 -> V_134 ) )
F_70 ( & V_2 -> V_134 ) ;
if ( ( V_93 = F_53 ( V_14 ) ) >= 0 )
F_71 ( & V_2 -> V_134 ,
V_135 , V_93 ) ;
return 0 ;
V_108:
F_54 ( V_2 , V_101 ) ;
if ( V_2 -> V_33 -> V_136 != NULL )
V_2 -> V_33 -> V_136 ( V_2 ) ;
return V_37 ;
}
static int F_72 ( struct V_1 * V_2 ,
struct V_41 T_2 * V_92 )
{
struct V_41 * V_42 ;
int V_37 ;
V_42 = F_50 ( V_92 , sizeof( * V_42 ) ) ;
if ( F_51 ( V_42 ) )
return F_52 ( V_42 ) ;
V_37 = V_41 ( V_2 , V_42 ) ;
if ( F_28 ( V_92 , V_42 , sizeof( * V_42 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_42 ) ;
return V_37 ;
}
static int F_73 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_137 = 0 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_102 :
case V_103 :
break;
default:
F_13 ( V_2 ) ;
return - V_104 ;
}
F_13 ( V_2 ) ;
if ( F_57 ( & V_2 -> V_107 ) )
return - V_104 ;
if ( V_2 -> V_33 -> V_136 )
V_137 = V_2 -> V_33 -> V_136 ( V_2 ) ;
F_54 ( V_2 , V_101 ) ;
F_70 ( & V_2 -> V_134 ) ;
return V_137 ;
}
static int F_74 ( struct V_1 * V_2 ,
struct F_74 * V_42 )
{
struct V_13 * V_14 ;
int V_37 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_97 -> V_96 == V_101 ) {
F_13 ( V_2 ) ;
return - V_104 ;
}
F_13 ( V_2 ) ;
if ( V_42 -> V_123 > V_138 )
return - V_69 ;
if ( V_42 -> V_139 >= F_75 ( 2 , 0 , 12 ) &&
V_42 -> V_140 > V_141 )
return - V_69 ;
if ( V_42 -> V_127 == 0 )
return - V_69 ;
if ( V_42 -> V_131 >= V_14 -> V_132 ) {
if ( V_42 -> V_130 != 0 )
return - V_69 ;
} else {
if ( V_42 -> V_131 > V_42 -> V_130 )
return - V_69 ;
if ( V_42 -> V_130 > V_14 -> V_115 )
return - V_69 ;
}
V_37 = 0 ;
F_11 ( V_2 ) ;
V_14 -> V_123 = V_42 -> V_123 ;
if ( V_42 -> V_139 >= F_75 ( 2 , 0 , 12 ) )
V_14 -> V_140 = V_42 -> V_140 ;
V_14 -> V_125 = V_42 -> V_125 ;
V_14 -> V_126 -> V_127 = V_42 -> V_127 ;
V_14 -> V_128 = V_42 -> V_128 ;
V_14 -> V_129 = V_42 -> V_129 ;
V_14 -> V_130 = V_42 -> V_130 ;
V_14 -> V_131 = V_42 -> V_131 ;
V_42 -> V_132 = V_14 -> V_132 ;
if ( F_76 ( V_2 ) ) {
if ( V_2 -> V_21 == V_142 &&
V_14 -> V_131 > 0 )
F_77 ( V_2 , V_143 ) ;
V_37 = F_78 ( V_2 , V_14 ) ;
}
F_13 ( V_2 ) ;
return V_37 ;
}
static int F_79 ( struct V_1 * V_2 ,
struct F_74 T_2 * V_92 )
{
struct F_74 V_42 ;
int V_37 ;
if ( F_80 ( & V_42 , V_92 , sizeof( V_42 ) ) )
return - V_40 ;
V_37 = F_74 ( V_2 , & V_42 ) ;
if ( F_28 ( V_92 , & V_42 , sizeof( V_42 ) ) )
return - V_40 ;
return V_37 ;
}
int F_81 ( struct V_1 * V_2 ,
struct F_81 * V_97 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
V_97 -> V_96 = V_14 -> V_97 -> V_96 ;
V_97 -> V_144 = V_14 -> V_97 -> V_144 ;
if ( V_97 -> V_96 == V_101 )
goto V_145;
V_97 -> V_146 = V_14 -> V_146 ;
if ( F_76 ( V_2 ) ) {
F_82 ( V_2 ) ;
if ( V_14 -> V_123 == V_147 ) {
V_97 -> V_148 = V_14 -> V_97 -> V_148 ;
V_97 -> V_149 =
V_14 -> V_97 -> V_149 ;
goto V_150;
}
}
F_83 ( V_14 , & V_97 -> V_148 ) ;
V_150:
V_97 -> V_151 = V_14 -> V_126 -> V_151 ;
V_97 -> V_152 = V_14 -> V_97 -> V_152 ;
if ( V_2 -> V_21 == V_142 ) {
V_97 -> V_153 = F_84 ( V_14 ) ;
if ( V_14 -> V_97 -> V_96 == V_154 ||
V_14 -> V_97 -> V_96 == V_155 ) {
V_97 -> V_156 = V_14 -> V_115 - V_97 -> V_153 ;
V_97 -> V_156 += V_14 -> V_156 ;
} else
V_97 -> V_156 = 0 ;
} else {
V_97 -> V_153 = F_85 ( V_14 ) ;
if ( V_14 -> V_97 -> V_96 == V_154 )
V_97 -> V_156 = V_97 -> V_153 + V_14 -> V_156 ;
else
V_97 -> V_156 = 0 ;
}
V_97 -> V_157 = V_14 -> V_157 ;
V_97 -> V_158 = V_14 -> V_158 ;
V_14 -> V_157 = 0 ;
V_14 -> V_158 = 0 ;
V_145:
F_13 ( V_2 ) ;
return 0 ;
}
static int F_86 ( struct V_1 * V_2 ,
struct F_81 T_2 * V_159 )
{
struct F_81 V_97 ;
int V_160 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_160 = F_81 ( V_2 , & V_97 ) ;
if ( V_160 < 0 )
return V_160 ;
if ( F_28 ( V_159 , & V_97 , sizeof( V_97 ) ) )
return - V_40 ;
return 0 ;
}
static int F_87 ( struct V_1 * V_2 ,
struct F_87 * V_12 )
{
struct V_13 * V_14 ;
unsigned int V_161 ;
V_161 = V_12 -> V_161 ;
V_14 = V_2 -> V_14 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_97 -> V_96 == V_101 ) {
F_13 ( V_2 ) ;
return - V_104 ;
}
F_13 ( V_2 ) ;
if ( V_161 >= V_14 -> V_113 )
return - V_69 ;
memset ( V_12 , 0 , sizeof( * V_12 ) ) ;
V_12 -> V_161 = V_161 ;
return V_2 -> V_33 -> V_34 ( V_2 , V_162 , V_12 ) ;
}
static int F_88 ( struct V_1 * V_2 ,
struct F_87 T_2 * V_36 )
{
struct F_87 V_12 ;
int V_160 ;
if ( F_80 ( & V_12 , V_36 , sizeof( V_12 ) ) )
return - V_40 ;
V_160 = F_87 ( V_2 , & V_12 ) ;
if ( V_160 < 0 )
return V_160 ;
if ( F_28 ( V_36 , & V_12 , sizeof( V_12 ) ) )
return - V_40 ;
return 0 ;
}
static void F_89 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_163 == NULL )
return;
if ( V_14 -> V_163 == V_2 ) {
F_83 ( V_14 , & V_14 -> V_146 ) ;
} else {
F_89 ( V_14 -> V_163 ) ;
V_14 -> V_146 = V_14 -> V_163 -> V_14 -> V_146 ;
}
V_14 -> V_163 = NULL ;
}
static int F_90 ( struct V_164 * V_33 ,
struct V_1 * V_2 ,
int V_96 , int V_165 )
{
struct V_1 * V_166 = NULL ;
struct V_1 * V_167 ;
int V_160 = 0 , V_168 = 1 ;
F_91 (s, substream) {
if ( V_165 && V_166 != V_2 ) {
if ( V_166 -> V_3 -> V_4 )
F_92 ( & V_166 -> V_6 . V_7 , V_168 ) ;
else
F_93 ( & V_166 -> V_6 . V_9 , V_168 ) ;
V_168 ++ ;
}
V_160 = V_33 -> V_169 ( V_166 , V_96 ) ;
if ( V_160 < 0 )
goto V_170;
}
F_91 (s, substream) {
V_160 = V_33 -> V_171 ( V_166 , V_96 ) ;
if ( V_160 < 0 ) {
if ( V_33 -> V_172 ) {
F_91 (s1, substream) {
if ( V_167 == V_166 )
break;
V_33 -> V_172 ( V_167 , V_96 ) ;
}
}
V_166 = NULL ;
goto V_170;
}
}
F_91 (s, substream) {
V_33 -> V_173 ( V_166 , V_96 ) ;
}
V_170:
if ( V_165 ) {
F_91 (s1, substream) {
if ( V_167 != V_2 ) {
if ( V_167 -> V_3 -> V_4 )
F_7 ( & V_167 -> V_6 . V_7 ) ;
else
F_9 ( & V_167 -> V_6 . V_9 ) ;
}
if ( V_167 == V_166 )
break;
}
}
return V_160 ;
}
static int F_94 ( struct V_164 * V_33 ,
struct V_1 * V_2 ,
int V_96 )
{
int V_160 ;
V_160 = V_33 -> V_169 ( V_2 , V_96 ) ;
if ( V_160 < 0 )
return V_160 ;
V_160 = V_33 -> V_171 ( V_2 , V_96 ) ;
if ( V_160 == 0 )
V_33 -> V_173 ( V_2 , V_96 ) ;
else if ( V_33 -> V_172 )
V_33 -> V_172 ( V_2 , V_96 ) ;
return V_160 ;
}
static int F_95 ( struct V_164 * V_33 ,
struct V_1 * V_2 ,
int V_96 )
{
int V_160 ;
if ( F_96 ( V_2 ) ) {
if ( ! F_97 ( & V_2 -> V_174 -> V_7 ) ) {
F_7 ( & V_2 -> V_6 . V_7 ) ;
F_3 ( & V_2 -> V_174 -> V_7 ) ;
F_3 ( & V_2 -> V_6 . V_7 ) ;
}
V_160 = F_90 ( V_33 , V_2 , V_96 , 1 ) ;
F_7 ( & V_2 -> V_174 -> V_7 ) ;
} else {
V_160 = F_94 ( V_33 , V_2 , V_96 ) ;
}
return V_160 ;
}
static int F_98 ( struct V_164 * V_33 ,
struct V_1 * V_2 ,
int V_96 )
{
int V_160 ;
if ( V_2 -> V_3 -> V_4 )
return F_95 ( V_33 , V_2 , V_96 ) ;
if ( F_96 ( V_2 ) ) {
if ( ! F_99 ( & V_2 -> V_174 -> V_9 ) ) {
F_9 ( & V_2 -> V_6 . V_9 ) ;
F_5 ( & V_2 -> V_174 -> V_9 ) ;
F_5 ( & V_2 -> V_6 . V_9 ) ;
}
V_160 = F_90 ( V_33 , V_2 , V_96 , 1 ) ;
F_9 ( & V_2 -> V_174 -> V_9 ) ;
} else {
V_160 = F_94 ( V_33 , V_2 , V_96 ) ;
}
return V_160 ;
}
static int F_100 ( struct V_164 * V_33 ,
struct V_1 * V_2 ,
int V_96 )
{
int V_160 ;
F_2 ( & V_5 ) ;
if ( F_96 ( V_2 ) ) {
F_3 ( & V_2 -> V_174 -> V_7 ) ;
F_3 ( & V_2 -> V_6 . V_7 ) ;
V_160 = F_90 ( V_33 , V_2 , V_96 , 1 ) ;
F_7 ( & V_2 -> V_6 . V_7 ) ;
F_7 ( & V_2 -> V_174 -> V_7 ) ;
} else {
F_3 ( & V_2 -> V_6 . V_7 ) ;
V_160 = F_94 ( V_33 , V_2 , V_96 ) ;
F_7 ( & V_2 -> V_6 . V_7 ) ;
}
F_8 ( & V_5 ) ;
return V_160 ;
}
static int F_101 ( struct V_164 * V_33 ,
struct V_1 * V_2 ,
int V_96 )
{
int V_160 ;
if ( V_2 -> V_3 -> V_4 )
return F_100 ( V_33 , V_2 , V_96 ) ;
F_102 ( & V_8 ) ;
if ( F_96 ( V_2 ) ) {
F_5 ( & V_2 -> V_174 -> V_9 ) ;
F_5 ( & V_2 -> V_6 . V_9 ) ;
V_160 = F_90 ( V_33 , V_2 , V_96 , 1 ) ;
F_9 ( & V_2 -> V_6 . V_9 ) ;
F_9 ( & V_2 -> V_174 -> V_9 ) ;
} else {
F_5 ( & V_2 -> V_6 . V_9 ) ;
V_160 = F_94 ( V_33 , V_2 , V_96 ) ;
F_9 ( & V_2 -> V_6 . V_9 ) ;
}
F_103 ( & V_8 ) ;
return V_160 ;
}
static int F_104 ( struct V_164 * V_33 ,
struct V_1 * V_2 ,
int V_96 )
{
int V_160 ;
F_2 ( & V_5 ) ;
if ( F_96 ( V_2 ) )
V_160 = F_90 ( V_33 , V_2 , V_96 , 0 ) ;
else
V_160 = F_94 ( V_33 , V_2 , V_96 ) ;
F_8 ( & V_5 ) ;
return V_160 ;
}
static int F_105 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 != V_103 )
return - V_104 ;
if ( V_2 -> V_21 == V_142 &&
! F_106 ( V_2 ) )
return - V_175 ;
V_14 -> V_163 = V_2 ;
return 0 ;
}
static int F_107 ( struct V_1 * V_2 , int V_96 )
{
if ( V_2 -> V_14 -> V_163 != V_2 )
return 0 ;
return V_2 -> V_33 -> V_176 ( V_2 , V_177 ) ;
}
static void F_108 ( struct V_1 * V_2 , int V_96 )
{
if ( V_2 -> V_14 -> V_163 == V_2 )
V_2 -> V_33 -> V_176 ( V_2 , V_178 ) ;
}
static void F_109 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_89 ( V_2 ) ;
V_14 -> V_179 = V_180 ;
V_14 -> V_181 = ( V_14 -> V_115 * V_182 ) /
V_14 -> V_94 ;
V_14 -> V_97 -> V_96 = V_96 ;
if ( V_2 -> V_21 == V_142 &&
V_14 -> V_131 > 0 )
F_77 ( V_2 , V_143 ) ;
if ( V_2 -> V_183 )
F_110 ( V_2 -> V_183 , V_184 ,
& V_14 -> V_146 ) ;
}
int F_111 ( struct V_1 * V_2 )
{
return F_98 ( & V_185 , V_2 ,
V_154 ) ;
}
static int F_112 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
V_14 -> V_163 = V_2 ;
return 0 ;
}
static int F_113 ( struct V_1 * V_2 , int V_96 )
{
if ( V_2 -> V_14 -> V_163 == V_2 &&
F_76 ( V_2 ) )
V_2 -> V_33 -> V_176 ( V_2 , V_178 ) ;
return 0 ;
}
static void F_114 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 != V_96 ) {
F_89 ( V_2 ) ;
if ( V_2 -> V_183 )
F_110 ( V_2 -> V_183 , V_186 ,
& V_14 -> V_146 ) ;
V_14 -> V_97 -> V_96 = V_96 ;
}
F_115 ( & V_14 -> V_187 ) ;
F_115 ( & V_14 -> V_188 ) ;
}
int F_116 ( struct V_1 * V_2 , T_4 V_96 )
{
return F_98 ( & V_189 , V_2 , V_96 ) ;
}
int F_117 ( struct V_1 * V_2 )
{
return F_94 ( & V_189 , V_2 ,
V_102 ) ;
}
static int F_118 ( struct V_1 * V_2 , int V_190 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_191 ) )
return - V_192 ;
if ( V_190 ) {
if ( V_14 -> V_97 -> V_96 != V_154 )
return - V_104 ;
} else if ( V_14 -> V_97 -> V_96 != V_193 )
return - V_104 ;
V_14 -> V_163 = V_2 ;
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , int V_190 )
{
if ( V_2 -> V_14 -> V_163 != V_2 )
return 0 ;
if ( V_190 )
F_82 ( V_2 ) ;
V_2 -> V_14 -> V_179 = V_180 - V_182 * 1000 ;
return V_2 -> V_33 -> V_176 ( V_2 ,
V_190 ? V_194 :
V_195 ) ;
}
static void F_120 ( struct V_1 * V_2 , int V_190 )
{
if ( V_2 -> V_14 -> V_163 == V_2 )
V_2 -> V_33 -> V_176 ( V_2 ,
V_190 ? V_195 :
V_194 ) ;
}
static void F_121 ( struct V_1 * V_2 , int V_190 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_89 ( V_2 ) ;
if ( V_190 ) {
V_14 -> V_97 -> V_96 = V_193 ;
if ( V_2 -> V_183 )
F_110 ( V_2 -> V_183 ,
V_196 ,
& V_14 -> V_146 ) ;
F_115 ( & V_14 -> V_187 ) ;
F_115 ( & V_14 -> V_188 ) ;
} else {
V_14 -> V_97 -> V_96 = V_154 ;
if ( V_2 -> V_183 )
F_110 ( V_2 -> V_183 ,
V_197 ,
& V_14 -> V_146 ) ;
}
}
static int F_122 ( struct V_1 * V_2 , int V_190 )
{
return F_98 ( & V_198 , V_2 , V_190 ) ;
}
static int F_123 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_199 )
return - V_200 ;
V_14 -> V_163 = V_2 ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_163 != V_2 )
return 0 ;
if ( ! F_76 ( V_2 ) )
return 0 ;
V_2 -> V_33 -> V_176 ( V_2 , V_201 ) ;
return 0 ;
}
static void F_125 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_89 ( V_2 ) ;
if ( V_2 -> V_183 )
F_110 ( V_2 -> V_183 , V_202 ,
& V_14 -> V_146 ) ;
V_14 -> V_97 -> V_144 = V_14 -> V_97 -> V_96 ;
V_14 -> V_97 -> V_96 = V_199 ;
F_115 ( & V_14 -> V_187 ) ;
F_115 ( & V_14 -> V_188 ) ;
}
int F_126 ( struct V_1 * V_2 )
{
int V_37 ;
unsigned long V_10 ;
if ( ! V_2 )
return 0 ;
F_127 ( V_2 , V_10 ) ;
V_37 = F_98 ( & V_203 , V_2 , 0 ) ;
F_17 ( V_2 , V_10 ) ;
return V_37 ;
}
int F_128 ( struct V_15 * V_3 )
{
struct V_1 * V_2 ;
int V_21 , V_37 = 0 ;
if ( ! V_3 )
return 0 ;
for ( V_21 = 0 ; V_21 < 2 ; V_21 ++ ) {
for ( V_2 = V_3 -> V_204 [ V_21 ] . V_2 ;
V_2 ; V_2 = V_2 -> V_205 ) {
if ( V_2 -> V_14 == NULL )
continue;
V_37 = F_126 ( V_2 ) ;
if ( V_37 < 0 && V_37 != - V_200 )
return V_37 ;
}
}
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( ! ( V_14 -> V_12 & V_206 ) )
return - V_192 ;
V_14 -> V_163 = V_2 ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_163 != V_2 )
return 0 ;
if ( V_14 -> V_97 -> V_144 != V_154 &&
( V_14 -> V_97 -> V_144 != V_155 ||
V_2 -> V_21 != V_142 ) )
return 0 ;
return V_2 -> V_33 -> V_176 ( V_2 , V_207 ) ;
}
static void F_131 ( struct V_1 * V_2 , int V_96 )
{
if ( V_2 -> V_14 -> V_163 == V_2 &&
F_76 ( V_2 ) )
V_2 -> V_33 -> V_176 ( V_2 , V_201 ) ;
}
static void F_132 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
F_89 ( V_2 ) ;
if ( V_2 -> V_183 )
F_110 ( V_2 -> V_183 , V_208 ,
& V_14 -> V_146 ) ;
V_14 -> V_97 -> V_96 = V_14 -> V_97 -> V_144 ;
}
static int F_133 ( struct V_1 * V_2 )
{
struct V_209 * V_18 = V_2 -> V_3 -> V_18 ;
int V_160 ;
F_134 ( V_18 ) ;
if ( ( V_160 = F_135 ( V_18 , V_210 ) ) >= 0 )
V_160 = F_101 ( & V_211 , V_2 , 0 ) ;
F_136 ( V_18 ) ;
return V_160 ;
}
static int F_133 ( struct V_1 * V_2 )
{
return - V_192 ;
}
static int F_137 ( struct V_1 * V_2 )
{
struct V_209 * V_18 = V_2 -> V_3 -> V_18 ;
struct V_13 * V_14 = V_2 -> V_14 ;
int V_137 ;
F_134 ( V_18 ) ;
if ( V_14 -> V_97 -> V_96 == V_199 ) {
V_137 = F_135 ( V_18 , V_210 ) ;
if ( V_137 < 0 )
goto V_170;
}
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_212 :
V_137 = 0 ;
break;
case V_154 :
V_137 = F_116 ( V_2 , V_212 ) ;
break;
default:
V_137 = - V_104 ;
}
F_13 ( V_2 ) ;
V_170:
F_136 ( V_18 ) ;
return V_137 ;
}
static int F_138 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_154 :
case V_103 :
case V_193 :
case V_199 :
return 0 ;
default:
return - V_104 ;
}
}
static int F_139 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 = V_2 -> V_33 -> V_34 ( V_2 , V_213 , NULL ) ;
if ( V_37 < 0 )
return V_37 ;
V_14 -> V_214 = 0 ;
V_14 -> V_215 = V_14 -> V_97 -> V_152 -
V_14 -> V_97 -> V_152 % V_14 -> V_95 ;
V_14 -> V_216 = V_14 -> V_97 -> V_152 ;
V_14 -> V_217 = 0 ;
return 0 ;
}
static void F_140 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_126 -> V_151 = V_14 -> V_97 -> V_152 ;
if ( V_2 -> V_21 == V_142 &&
V_14 -> V_131 > 0 )
F_77 ( V_2 , V_143 ) ;
}
static int F_141 ( struct V_1 * V_2 )
{
return F_104 ( & V_218 , V_2 , 0 ) ;
}
static int F_142 ( struct V_1 * V_2 ,
int V_219 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 ||
V_14 -> V_97 -> V_96 == V_98 )
return - V_104 ;
if ( F_76 ( V_2 ) )
return - V_200 ;
V_2 -> V_219 = V_219 ;
return 0 ;
}
static int F_143 ( struct V_1 * V_2 , int V_96 )
{
int V_37 ;
V_37 = V_2 -> V_33 -> V_220 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
return F_139 ( V_2 , 0 ) ;
}
static void F_144 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
V_14 -> V_126 -> V_151 = V_14 -> V_97 -> V_152 ;
F_54 ( V_2 , V_103 ) ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_221 * V_221 )
{
int V_160 ;
struct V_209 * V_18 = V_2 -> V_3 -> V_18 ;
int V_219 ;
if ( V_221 )
V_219 = V_221 -> V_219 ;
else
V_219 = V_2 -> V_219 ;
F_134 ( V_18 ) ;
if ( ( V_160 = F_135 ( V_18 , V_210 ) ) >= 0 )
V_160 = F_104 ( & V_222 ,
V_2 , V_219 ) ;
F_136 ( V_18 ) ;
return V_160 ;
}
static int F_146 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_101 :
case V_98 :
case V_199 :
return - V_104 ;
}
V_14 -> V_163 = V_2 ;
return 0 ;
}
static int F_147 ( struct V_1 * V_2 , int V_96 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
if ( V_2 -> V_21 == V_142 ) {
switch ( V_14 -> V_97 -> V_96 ) {
case V_103 :
if ( ! F_148 ( V_2 ) ) {
F_107 ( V_2 , V_155 ) ;
F_109 ( V_2 , V_155 ) ;
}
break;
case V_154 :
V_14 -> V_97 -> V_96 = V_155 ;
break;
case V_212 :
V_14 -> V_97 -> V_96 = V_102 ;
break;
default:
break;
}
} else {
if ( V_14 -> V_97 -> V_96 == V_154 ) {
int V_223 = F_85 ( V_14 ) > 0 ?
V_155 : V_102 ;
F_113 ( V_2 , V_223 ) ;
F_114 ( V_2 , V_223 ) ;
}
}
return 0 ;
}
static void F_149 ( struct V_1 * V_2 , int V_96 )
{
}
static int F_150 ( struct V_1 * V_2 ,
struct V_221 * V_221 )
{
struct V_209 * V_18 ;
struct V_13 * V_14 ;
struct V_1 * V_166 ;
T_5 V_224 ;
int V_137 = 0 ;
int V_225 = 0 ;
V_18 = V_2 -> V_3 -> V_18 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
F_134 ( V_18 ) ;
if ( V_14 -> V_97 -> V_96 == V_199 ) {
V_137 = F_135 ( V_18 , V_210 ) ;
if ( V_137 < 0 ) {
F_136 ( V_18 ) ;
return V_137 ;
}
}
if ( V_221 ) {
if ( V_221 -> V_219 & V_226 )
V_225 = 1 ;
} else if ( V_2 -> V_219 & V_226 )
V_225 = 1 ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
if ( V_14 -> V_97 -> V_96 == V_193 )
F_122 ( V_2 , 0 ) ;
V_137 = F_98 ( & V_227 , V_2 , 0 ) ;
if ( V_137 < 0 )
goto V_228;
if ( V_225 ) {
V_137 = - V_229 ;
goto V_228;
}
for (; ; ) {
long V_230 ;
struct V_13 * V_231 ;
if ( F_151 ( V_232 ) ) {
V_137 = - V_233 ;
break;
}
V_231 = NULL ;
F_91 (s, substream) {
if ( V_166 -> V_21 != V_142 )
continue;
V_14 = V_166 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_155 ) {
V_231 = V_14 ;
break;
}
}
if ( ! V_231 )
break;
F_152 ( & V_224 , V_232 ) ;
F_153 ( & V_231 -> V_187 , & V_224 ) ;
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_136 ( V_18 ) ;
if ( V_14 -> V_116 )
V_230 = V_234 ;
else {
V_230 = 10 ;
if ( V_14 -> V_94 ) {
long V_235 = V_14 -> V_95 * 2 / V_14 -> V_94 ;
V_230 = V_77 ( V_235 , V_230 ) ;
}
V_230 = F_154 ( V_230 * 1000 ) ;
}
V_230 = F_155 ( V_230 ) ;
F_134 ( V_18 ) ;
F_2 ( & V_5 ) ;
F_11 ( V_2 ) ;
F_156 ( & V_231 -> V_187 , & V_224 ) ;
if ( V_18 -> V_236 ) {
V_137 = - V_237 ;
break;
}
if ( V_230 == 0 ) {
if ( V_2 -> V_14 -> V_97 -> V_96 == V_199 )
V_137 = - V_238 ;
else {
F_157 ( V_2 -> V_3 -> V_18 -> V_239 ,
L_12 ) ;
F_116 ( V_2 , V_102 ) ;
V_137 = - V_240 ;
}
break;
}
}
V_228:
F_13 ( V_2 ) ;
F_8 ( & V_5 ) ;
F_136 ( V_18 ) ;
return V_137 ;
}
static int F_158 ( struct V_1 * V_2 )
{
struct V_13 * V_14 ;
int V_137 = 0 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 ||
V_14 -> V_97 -> V_96 == V_98 ||
V_14 -> V_97 -> V_96 == V_199 )
return - V_104 ;
F_11 ( V_2 ) ;
if ( V_14 -> V_97 -> V_96 == V_193 )
F_122 ( V_2 , 0 ) ;
F_116 ( V_2 , V_102 ) ;
F_13 ( V_2 ) ;
return V_137 ;
}
static bool F_159 ( struct V_221 * V_221 )
{
struct V_241 * V_241 = F_160 ( V_221 ) ;
unsigned int V_242 ;
if ( ! F_161 ( V_241 -> V_243 ) || F_162 ( V_241 ) != V_244 )
return false ;
V_242 = F_163 ( V_241 ) ;
return F_164 ( V_242 , V_245 ) ||
F_164 ( V_242 , V_246 ) ;
}
static int F_165 ( struct V_1 * V_2 , int V_247 )
{
int V_160 = 0 ;
struct V_248 * V_249 ;
struct V_1 * V_250 ;
struct V_251 * V_174 ;
struct V_247 V_252 = F_166 ( V_247 ) ;
if ( ! V_252 . V_221 )
return - V_104 ;
if ( ! F_159 ( V_252 . V_221 ) ) {
V_160 = - V_104 ;
goto V_253;
}
V_249 = V_252 . V_221 -> V_254 ;
V_250 = V_249 -> V_2 ;
V_174 = F_27 ( sizeof( * V_174 ) , V_38 ) ;
if ( ! V_174 ) {
V_160 = - V_39 ;
goto V_255;
}
F_167 ( & V_5 ) ;
F_168 ( & V_8 ) ;
if ( V_2 -> V_14 -> V_97 -> V_96 == V_101 ||
V_2 -> V_14 -> V_97 -> V_96 != V_250 -> V_14 -> V_97 -> V_96 ||
V_2 -> V_3 -> V_4 != V_250 -> V_3 -> V_4 ) {
V_160 = - V_104 ;
goto V_145;
}
if ( F_96 ( V_250 ) ) {
V_160 = - V_256 ;
goto V_145;
}
if ( ! F_96 ( V_2 ) ) {
V_2 -> V_174 = V_174 ;
V_174 = NULL ;
F_169 ( & V_2 -> V_174 -> V_9 ) ;
F_170 ( & V_2 -> V_174 -> V_7 ) ;
F_171 ( & V_2 -> V_174 -> V_257 ) ;
F_172 ( & V_2 -> V_258 , & V_2 -> V_174 -> V_257 ) ;
V_2 -> V_174 -> V_259 = 1 ;
}
F_172 ( & V_250 -> V_258 , & V_2 -> V_174 -> V_257 ) ;
V_2 -> V_174 -> V_259 ++ ;
V_250 -> V_174 = V_2 -> V_174 ;
V_145:
F_173 ( & V_8 ) ;
F_174 ( & V_5 ) ;
V_255:
F_175 ( V_250 -> V_3 -> V_18 ) ;
F_29 ( V_174 ) ;
V_253:
F_176 ( V_252 ) ;
return V_160 ;
}
static void F_177 ( struct V_1 * V_2 )
{
V_2 -> V_174 = & V_2 -> V_6 ;
F_171 ( & V_2 -> V_6 . V_257 ) ;
F_172 ( & V_2 -> V_258 , & V_2 -> V_6 . V_257 ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
struct V_1 * V_166 ;
int V_160 = 0 ;
F_167 ( & V_5 ) ;
F_168 ( & V_8 ) ;
if ( ! F_96 ( V_2 ) ) {
V_160 = - V_256 ;
goto V_145;
}
F_179 ( & V_2 -> V_258 ) ;
V_2 -> V_174 -> V_259 -- ;
if ( V_2 -> V_174 -> V_259 == 1 ) {
F_91 (s, substream) {
F_177 ( V_166 ) ;
break;
}
F_29 ( V_2 -> V_174 ) ;
}
F_177 ( V_2 ) ;
V_145:
F_173 ( & V_8 ) ;
F_174 ( & V_5 ) ;
return V_160 ;
}
static int F_180 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
struct V_46 V_235 ;
F_181 ( F_182 ( V_42 , V_260 -> V_85 [ 0 ] ) ,
F_182 ( V_42 , V_260 -> V_85 [ 1 ] ) , & V_235 ) ;
return F_40 ( F_38 ( V_42 , V_260 -> V_87 ) , & V_235 ) ;
}
static int F_183 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
struct V_46 V_235 ;
F_184 ( F_182 ( V_42 , V_260 -> V_85 [ 0 ] ) ,
F_182 ( V_42 , V_260 -> V_85 [ 1 ] ) , & V_235 ) ;
return F_40 ( F_38 ( V_42 , V_260 -> V_87 ) , & V_235 ) ;
}
static int F_185 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
struct V_46 V_235 ;
F_186 ( F_182 ( V_42 , V_260 -> V_85 [ 0 ] ) ,
F_182 ( V_42 , V_260 -> V_85 [ 1 ] ) ,
( unsigned long ) V_260 -> V_261 , & V_235 ) ;
return F_40 ( F_38 ( V_42 , V_260 -> V_87 ) , & V_235 ) ;
}
static int F_187 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
struct V_46 V_235 ;
F_188 ( F_182 ( V_42 , V_260 -> V_85 [ 0 ] ) ,
( unsigned long ) V_260 -> V_261 ,
F_182 ( V_42 , V_260 -> V_85 [ 1 ] ) , & V_235 ) ;
return F_40 ( F_38 ( V_42 , V_260 -> V_87 ) , & V_235 ) ;
}
static int F_189 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
unsigned int V_43 ;
struct V_46 * V_47 = F_38 ( V_42 , V_260 -> V_85 [ 0 ] ) ;
struct V_48 V_49 ;
struct V_48 * V_262 = F_31 ( V_42 , V_89 ) ;
F_190 ( & V_49 ) ;
for ( V_43 = 0 ; V_43 <= V_263 ; ++ V_43 ) {
int V_71 ;
if ( ! F_191 ( V_262 , V_43 ) )
continue;
V_71 = F_67 ( V_43 ) ;
if ( V_71 <= 0 )
continue;
if ( ( unsigned ) V_71 < V_47 -> V_76 || ( unsigned ) V_71 > V_47 -> V_77 )
F_192 ( & V_49 , V_43 ) ;
}
return F_36 ( V_262 , & V_49 ) ;
}
static int F_193 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
struct V_46 V_235 ;
unsigned int V_43 ;
V_235 . V_76 = V_264 ;
V_235 . V_77 = 0 ;
V_235 . V_75 = 0 ;
V_235 . V_78 = 0 ;
for ( V_43 = 0 ; V_43 <= V_263 ; ++ V_43 ) {
int V_71 ;
if ( ! F_191 ( F_31 ( V_42 , V_89 ) , V_43 ) )
continue;
V_71 = F_67 ( V_43 ) ;
if ( V_71 <= 0 )
continue;
if ( V_235 . V_76 > ( unsigned ) V_71 )
V_235 . V_76 = V_71 ;
if ( V_235 . V_77 < ( unsigned ) V_71 )
V_235 . V_77 = V_71 ;
}
V_235 . integer = 1 ;
return F_40 ( F_38 ( V_42 , V_260 -> V_87 ) , & V_235 ) ;
}
static int F_194 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
struct V_44 * V_45 = V_260 -> V_261 ;
return F_195 ( F_38 ( V_42 , V_260 -> V_87 ) ,
V_265 . V_259 ,
V_265 . V_266 , V_45 -> V_267 ) ;
}
static int F_196 ( struct V_41 * V_42 ,
struct V_79 * V_260 )
{
struct V_46 V_235 ;
struct V_1 * V_2 = V_260 -> V_261 ;
V_235 . V_76 = 0 ;
V_235 . V_77 = V_2 -> V_268 ;
V_235 . V_75 = 0 ;
V_235 . V_78 = 0 ;
V_235 . integer = 1 ;
return F_40 ( F_38 ( V_42 , V_260 -> V_87 ) , & V_235 ) ;
}
int F_197 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_50 * V_51 = & V_14 -> V_52 ;
int V_43 , V_37 ;
for ( V_43 = V_67 ; V_43 <= V_68 ; V_43 ++ ) {
F_190 ( F_37 ( V_51 , V_43 ) ) ;
}
for ( V_43 = V_73 ; V_43 <= V_56 ; V_43 ++ ) {
F_198 ( F_41 ( V_51 , V_43 ) ) ;
}
F_199 ( F_41 ( V_51 , V_90 ) ) ;
F_199 ( F_41 ( V_51 , V_269 ) ) ;
F_199 ( F_41 ( V_51 , V_270 ) ) ;
F_199 ( F_41 ( V_51 , V_62 ) ) ;
F_199 ( F_41 ( V_51 , V_271 ) ) ;
V_37 = F_200 ( V_14 , 0 , V_89 ,
F_189 , NULL ,
V_62 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_62 ,
F_193 , NULL ,
V_89 ,
V_62 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_62 ,
F_183 , NULL ,
V_271 , V_90 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_271 ,
F_180 , NULL ,
V_62 , V_90 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_271 ,
F_187 , ( void * ) 8 ,
V_272 , V_273 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_271 ,
F_187 , ( void * ) 8 ,
V_270 , V_269 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_90 ,
F_183 , NULL ,
V_271 , V_62 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_64 ,
F_187 , ( void * ) 1000000 ,
V_273 , V_274 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_64 ,
F_187 , ( void * ) 1000000 ,
V_269 , V_275 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_276 ,
F_183 , NULL ,
V_269 , V_273 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_273 ,
F_183 , NULL ,
V_269 , V_276 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_273 ,
F_187 , ( void * ) 8 ,
V_272 , V_271 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_273 ,
F_185 , ( void * ) 1000000 ,
V_274 , V_64 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_269 ,
F_180 , NULL ,
V_273 , V_276 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_269 ,
F_187 , ( void * ) 8 ,
V_270 , V_271 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_269 ,
F_185 , ( void * ) 1000000 ,
V_275 , V_64 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_272 ,
F_185 , ( void * ) 8 ,
V_273 , V_271 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_270 ,
F_185 , ( void * ) 8 ,
V_269 , V_271 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_274 ,
F_187 , ( void * ) 1000000 ,
V_273 , V_64 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_275 ,
F_187 , ( void * ) 1000000 ,
V_269 , V_64 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct V_44 * V_45 = & V_14 -> V_45 ;
int V_37 ;
unsigned int V_262 = 0 ;
if ( V_45 -> V_12 & V_277 )
V_262 |= 1 << V_278 ;
if ( V_45 -> V_12 & V_279 )
V_262 |= 1 << V_280 ;
if ( V_45 -> V_12 & V_281 ) {
if ( V_45 -> V_12 & V_277 )
V_262 |= 1 << V_282 ;
if ( V_45 -> V_12 & V_279 )
V_262 |= 1 << V_283 ;
if ( V_45 -> V_12 & V_284 )
V_262 |= 1 << V_285 ;
}
V_37 = F_202 ( V_14 , V_286 , V_262 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_203 ( V_14 , V_89 , V_45 -> V_287 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_202 ( V_14 , V_288 , 1 << V_289 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_204 ( V_14 , V_90 ,
V_45 -> V_290 , V_45 -> V_291 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_204 ( V_14 , V_64 ,
V_45 -> V_292 , V_45 -> V_293 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_204 ( V_14 , V_272 ,
V_45 -> V_294 , V_45 -> V_295 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_204 ( V_14 , V_276 ,
V_45 -> V_296 , V_45 -> V_297 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_204 ( V_14 , V_270 ,
V_45 -> V_294 , V_45 -> V_268 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_200 ( V_14 , 0 , V_270 ,
F_196 , V_2 ,
V_270 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_14 -> V_298 ) {
V_37 = F_204 ( V_14 , V_270 , 0 , V_14 -> V_298 ) ;
if ( V_37 < 0 )
return V_37 ;
}
if ( ! ( V_45 -> V_267 & ( V_299 | V_300 ) ) ) {
V_37 = F_200 ( V_14 , 0 , V_64 ,
F_194 , V_45 ,
V_64 , - 1 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_205 ( V_14 , V_273 ) ;
return 0 ;
}
static void F_206 ( struct V_1 * V_2 )
{
F_178 ( V_2 ) ;
}
void F_207 ( struct V_1 * V_2 )
{
V_2 -> V_301 -- ;
if ( V_2 -> V_301 > 0 )
return;
F_158 ( V_2 ) ;
if ( V_2 -> V_302 ) {
if ( V_2 -> V_33 -> V_136 != NULL )
V_2 -> V_33 -> V_136 ( V_2 ) ;
V_2 -> V_33 -> V_303 ( V_2 ) ;
V_2 -> V_302 = 0 ;
}
if ( F_69 ( & V_2 -> V_134 ) )
F_70 ( & V_2 -> V_134 ) ;
if ( V_2 -> V_304 ) {
V_2 -> V_304 ( V_2 ) ;
V_2 -> V_304 = NULL ;
}
F_208 ( V_2 ) ;
}
int F_209 ( struct V_15 * V_3 , int V_21 ,
struct V_221 * V_221 ,
struct V_1 * * V_305 )
{
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_210 ( V_3 , V_21 , V_221 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_2 -> V_301 > 1 ) {
* V_305 = V_2 ;
return 0 ;
}
V_37 = F_197 ( V_2 ) ;
if ( V_37 < 0 ) {
F_211 ( V_3 , L_13 ) ;
goto error;
}
if ( ( V_37 = V_2 -> V_33 -> V_306 ( V_2 ) ) < 0 )
goto error;
V_2 -> V_302 = 1 ;
V_37 = F_201 ( V_2 ) ;
if ( V_37 < 0 ) {
F_211 ( V_3 , L_14 ) ;
goto error;
}
* V_305 = V_2 ;
return 0 ;
error:
F_207 ( V_2 ) ;
return V_37 ;
}
static int F_212 ( struct V_221 * V_221 ,
struct V_15 * V_3 ,
int V_21 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
int V_37 ;
V_37 = F_209 ( V_3 , V_21 , V_221 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
V_249 = F_213 ( sizeof( * V_249 ) , V_38 ) ;
if ( V_249 == NULL ) {
F_207 ( V_2 ) ;
return - V_39 ;
}
V_249 -> V_2 = V_2 ;
if ( V_2 -> V_301 == 1 ) {
V_2 -> V_221 = V_249 ;
V_2 -> V_304 = F_206 ;
}
V_221 -> V_254 = V_249 ;
return 0 ;
}
static int F_214 ( struct V_241 * V_241 , struct V_221 * V_221 )
{
struct V_15 * V_3 ;
int V_37 = F_215 ( V_241 , V_221 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_164 ( F_163 ( V_241 ) ,
V_245 ) ;
V_37 = F_216 ( V_221 , V_3 , V_142 ) ;
if ( V_3 )
F_175 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_217 ( struct V_241 * V_241 , struct V_221 * V_221 )
{
struct V_15 * V_3 ;
int V_37 = F_215 ( V_241 , V_221 ) ;
if ( V_37 < 0 )
return V_37 ;
V_3 = F_164 ( F_163 ( V_241 ) ,
V_246 ) ;
V_37 = F_216 ( V_221 , V_3 , V_307 ) ;
if ( V_3 )
F_175 ( V_3 -> V_18 ) ;
return V_37 ;
}
static int F_216 ( struct V_221 * V_221 , struct V_15 * V_3 , int V_21 )
{
int V_37 ;
T_5 V_224 ;
if ( V_3 == NULL ) {
V_37 = - V_237 ;
goto V_308;
}
V_37 = F_218 ( V_3 -> V_18 , V_221 ) ;
if ( V_37 < 0 )
goto V_308;
if ( ! F_219 ( V_3 -> V_18 -> V_309 ) ) {
V_37 = - V_40 ;
goto V_310;
}
F_152 ( & V_224 , V_232 ) ;
F_153 ( & V_3 -> V_311 , & V_224 ) ;
F_3 ( & V_3 -> V_312 ) ;
while ( 1 ) {
V_37 = F_212 ( V_221 , V_3 , V_21 ) ;
if ( V_37 >= 0 )
break;
if ( V_37 == - V_229 ) {
if ( V_221 -> V_219 & V_226 ) {
V_37 = - V_200 ;
break;
}
} else
break;
F_220 ( V_313 ) ;
F_7 ( & V_3 -> V_312 ) ;
F_221 () ;
F_3 ( & V_3 -> V_312 ) ;
if ( V_3 -> V_18 -> V_236 ) {
V_37 = - V_237 ;
break;
}
if ( F_151 ( V_232 ) ) {
V_37 = - V_233 ;
break;
}
}
F_156 ( & V_3 -> V_311 , & V_224 ) ;
F_7 ( & V_3 -> V_312 ) ;
if ( V_37 < 0 )
goto V_314;
return V_37 ;
V_314:
F_222 ( V_3 -> V_18 -> V_309 ) ;
V_310:
F_223 ( V_3 -> V_18 , V_221 ) ;
V_308:
return V_37 ;
}
static int F_224 ( struct V_241 * V_241 , struct V_221 * V_221 )
{
struct V_15 * V_3 ;
struct V_1 * V_2 ;
struct V_248 * V_249 ;
V_249 = V_221 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_225 ( ! V_2 ) )
return - V_100 ;
V_3 = V_2 -> V_3 ;
F_3 ( & V_3 -> V_312 ) ;
F_207 ( V_2 ) ;
F_29 ( V_249 ) ;
F_7 ( & V_3 -> V_312 ) ;
F_115 ( & V_3 -> V_311 ) ;
F_222 ( V_3 -> V_18 -> V_309 ) ;
F_223 ( V_3 -> V_18 , V_221 ) ;
return 0 ;
}
static T_6 F_226 ( struct V_1 * V_2 ,
T_3 V_99 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_151 ;
T_6 V_315 ;
T_6 V_316 ;
if ( V_99 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_103 :
break;
case V_155 :
case V_154 :
if ( F_82 ( V_2 ) >= 0 )
break;
case V_212 :
V_315 = - V_175 ;
goto V_317;
case V_199 :
V_315 = - V_238 ;
goto V_317;
default:
V_315 = - V_104 ;
goto V_317;
}
V_316 = F_227 ( V_14 ) ;
if ( V_316 <= 0 ) {
V_315 = 0 ;
goto V_317;
}
if ( V_99 > ( T_3 ) V_316 )
V_99 = V_316 ;
V_151 = V_14 -> V_126 -> V_151 - V_99 ;
if ( V_151 < 0 )
V_151 += V_14 -> V_132 ;
V_14 -> V_126 -> V_151 = V_151 ;
V_315 = V_99 ;
V_317:
F_13 ( V_2 ) ;
return V_315 ;
}
static T_6 F_228 ( struct V_1 * V_2 ,
T_3 V_99 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_151 ;
T_6 V_315 ;
T_6 V_316 ;
if ( V_99 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_103 :
case V_155 :
break;
case V_154 :
if ( F_82 ( V_2 ) >= 0 )
break;
case V_212 :
V_315 = - V_175 ;
goto V_317;
case V_199 :
V_315 = - V_238 ;
goto V_317;
default:
V_315 = - V_104 ;
goto V_317;
}
V_316 = F_229 ( V_14 ) ;
if ( V_316 <= 0 ) {
V_315 = 0 ;
goto V_317;
}
if ( V_99 > ( T_3 ) V_316 )
V_99 = V_316 ;
V_151 = V_14 -> V_126 -> V_151 - V_99 ;
if ( V_151 < 0 )
V_151 += V_14 -> V_132 ;
V_14 -> V_126 -> V_151 = V_151 ;
V_315 = V_99 ;
V_317:
F_13 ( V_2 ) ;
return V_315 ;
}
static T_6 F_230 ( struct V_1 * V_2 ,
T_3 V_99 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_151 ;
T_6 V_315 ;
T_6 V_153 ;
if ( V_99 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_103 :
case V_193 :
break;
case V_155 :
case V_154 :
if ( F_82 ( V_2 ) >= 0 )
break;
case V_212 :
V_315 = - V_175 ;
goto V_317;
case V_199 :
V_315 = - V_238 ;
goto V_317;
default:
V_315 = - V_104 ;
goto V_317;
}
V_153 = F_84 ( V_14 ) ;
if ( V_153 <= 0 ) {
V_315 = 0 ;
goto V_317;
}
if ( V_99 > ( T_3 ) V_153 )
V_99 = V_153 ;
V_151 = V_14 -> V_126 -> V_151 + V_99 ;
if ( V_151 >= ( T_6 ) V_14 -> V_132 )
V_151 -= V_14 -> V_132 ;
V_14 -> V_126 -> V_151 = V_151 ;
V_315 = V_99 ;
V_317:
F_13 ( V_2 ) ;
return V_315 ;
}
static T_6 F_231 ( struct V_1 * V_2 ,
T_3 V_99 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_151 ;
T_6 V_315 ;
T_6 V_153 ;
if ( V_99 == 0 )
return 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_103 :
case V_155 :
case V_193 :
break;
case V_154 :
if ( F_82 ( V_2 ) >= 0 )
break;
case V_212 :
V_315 = - V_175 ;
goto V_317;
case V_199 :
V_315 = - V_238 ;
goto V_317;
default:
V_315 = - V_104 ;
goto V_317;
}
V_153 = F_85 ( V_14 ) ;
if ( V_153 <= 0 ) {
V_315 = 0 ;
goto V_317;
}
if ( V_99 > ( T_3 ) V_153 )
V_99 = V_153 ;
V_151 = V_14 -> V_126 -> V_151 + V_99 ;
if ( V_151 >= ( T_6 ) V_14 -> V_132 )
V_151 -= V_14 -> V_132 ;
V_14 -> V_126 -> V_151 = V_151 ;
V_315 = V_99 ;
V_317:
F_13 ( V_2 ) ;
return V_315 ;
}
static int F_232 ( struct V_1 * V_2 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_155 :
if ( V_2 -> V_21 == V_307 )
goto V_318;
case V_154 :
if ( ( V_37 = F_82 ( V_2 ) ) < 0 )
break;
case V_103 :
case V_199 :
V_37 = 0 ;
break;
case V_212 :
V_37 = - V_175 ;
break;
default:
V_318:
V_37 = - V_104 ;
break;
}
F_13 ( V_2 ) ;
return V_37 ;
}
static int F_233 ( struct V_1 * V_2 ,
T_6 T_2 * V_160 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_37 ;
T_6 V_319 = 0 ;
F_11 ( V_2 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_155 :
if ( V_2 -> V_21 == V_307 )
goto V_318;
case V_154 :
if ( ( V_37 = F_82 ( V_2 ) ) < 0 )
break;
case V_103 :
case V_199 :
V_37 = 0 ;
if ( V_2 -> V_21 == V_142 )
V_319 = F_227 ( V_14 ) ;
else
V_319 = F_85 ( V_14 ) ;
V_319 += V_14 -> V_156 ;
break;
case V_212 :
V_37 = - V_175 ;
break;
default:
V_318:
V_37 = - V_104 ;
break;
}
F_13 ( V_2 ) ;
if ( ! V_37 )
if ( F_234 ( V_319 , V_160 ) )
V_37 = - V_40 ;
return V_37 ;
}
static int F_235 ( struct V_1 * V_2 ,
struct F_235 T_2 * V_320 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
struct F_235 V_321 ;
volatile struct V_322 * V_97 ;
volatile struct V_323 * V_126 ;
int V_37 ;
memset ( & V_321 , 0 , sizeof( V_321 ) ) ;
if ( F_236 ( V_321 . V_10 , ( unsigned T_2 * ) & ( V_320 -> V_10 ) ) )
return - V_40 ;
if ( F_80 ( & V_321 . V_324 . V_126 , & ( V_320 -> V_324 . V_126 ) , sizeof( struct V_323 ) ) )
return - V_40 ;
V_97 = V_14 -> V_97 ;
V_126 = V_14 -> V_126 ;
if ( V_321 . V_10 & V_325 ) {
V_37 = F_232 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
}
F_11 ( V_2 ) ;
if ( ! ( V_321 . V_10 & V_326 ) )
V_126 -> V_151 = V_321 . V_324 . V_126 . V_151 ;
else
V_321 . V_324 . V_126 . V_151 = V_126 -> V_151 ;
if ( ! ( V_321 . V_10 & V_327 ) )
V_126 -> V_127 = V_321 . V_324 . V_126 . V_127 ;
else
V_321 . V_324 . V_126 . V_127 = V_126 -> V_127 ;
V_321 . V_166 . V_97 . V_96 = V_97 -> V_96 ;
V_321 . V_166 . V_97 . V_152 = V_97 -> V_152 ;
V_321 . V_166 . V_97 . V_148 = V_97 -> V_148 ;
V_321 . V_166 . V_97 . V_144 = V_97 -> V_144 ;
F_13 ( V_2 ) ;
if ( F_28 ( V_320 , & V_321 , sizeof( V_321 ) ) )
return - V_40 ;
return 0 ;
}
static int F_237 ( struct V_1 * V_2 , int T_2 * V_328 )
{
struct V_13 * V_14 = V_2 -> V_14 ;
int V_329 ;
if ( F_236 ( V_329 , V_328 ) )
return - V_40 ;
if ( V_329 < 0 || V_329 > V_141 )
return - V_69 ;
V_14 -> V_140 = V_329 ;
return 0 ;
}
static int F_238 ( struct V_221 * V_221 ,
struct V_1 * V_2 ,
unsigned int V_330 , void T_2 * V_329 )
{
switch ( V_330 ) {
case V_331 :
return F_234 ( V_332 , ( int T_2 * ) V_329 ) ? - V_40 : 0 ;
case V_333 :
return F_26 ( V_2 , V_329 ) ;
case V_334 :
return 0 ;
case V_335 :
return F_237 ( V_2 , V_329 ) ;
case V_336 :
return F_49 ( V_2 , V_329 ) ;
case V_337 :
return F_72 ( V_2 , V_329 ) ;
case V_338 :
return F_73 ( V_2 ) ;
case V_339 :
return F_79 ( V_2 , V_329 ) ;
case V_340 :
return F_86 ( V_2 , V_329 ) ;
case V_341 :
return F_88 ( V_2 , V_329 ) ;
case V_342 :
return F_145 ( V_2 , V_221 ) ;
case V_343 :
return F_141 ( V_2 ) ;
case V_344 :
return F_101 ( & V_185 , V_2 , V_154 ) ;
case V_345 :
return F_165 ( V_2 , ( int ) ( unsigned long ) V_329 ) ;
case V_346 :
return F_178 ( V_2 ) ;
case V_347 :
return F_133 ( V_2 ) ;
case V_348 :
return F_137 ( V_2 ) ;
case V_349 :
return F_232 ( V_2 ) ;
case V_350 :
return F_233 ( V_2 , V_329 ) ;
case V_351 :
return F_235 ( V_2 , V_329 ) ;
#ifdef F_239
case V_352 :
return F_240 ( V_2 , V_329 ) ;
case V_353 :
return F_241 ( V_2 , V_329 ) ;
#endif
case V_354 :
return F_150 ( V_2 , V_221 ) ;
case V_355 :
return F_158 ( V_2 ) ;
case V_356 :
{
int V_160 ;
F_11 ( V_2 ) ;
V_160 = F_122 ( V_2 , ( int ) ( unsigned long ) V_329 ) ;
F_13 ( V_2 ) ;
return V_160 ;
}
}
F_211 ( V_2 -> V_3 , L_15 , V_330 ) ;
return - V_357 ;
}
static int F_242 ( struct V_221 * V_221 ,
struct V_1 * V_2 ,
unsigned int V_330 , void T_2 * V_329 )
{
if ( F_225 ( ! V_2 ) )
return - V_100 ;
if ( F_225 ( V_2 -> V_21 != V_142 ) )
return - V_69 ;
switch ( V_330 ) {
case V_358 :
{
struct V_359 V_360 ;
struct V_359 T_2 * V_361 = V_329 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_137 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( F_234 ( 0 , & V_361 -> V_137 ) )
return - V_40 ;
if ( F_80 ( & V_360 , V_361 , sizeof( V_360 ) ) )
return - V_40 ;
V_137 = F_243 ( V_2 , V_360 . V_362 , V_360 . V_99 ) ;
F_244 ( V_137 , & V_361 -> V_137 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
case V_363 :
{
struct V_364 V_365 ;
struct V_364 T_2 * V_366 = V_329 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void T_2 * * V_367 ;
T_6 V_137 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( V_14 -> V_113 > 128 )
return - V_69 ;
if ( F_234 ( 0 , & V_366 -> V_137 ) )
return - V_40 ;
if ( F_80 ( & V_365 , V_366 , sizeof( V_365 ) ) )
return - V_40 ;
V_367 = F_50 ( V_365 . V_367 ,
sizeof( void * ) * V_14 -> V_113 ) ;
if ( F_51 ( V_367 ) )
return F_52 ( V_367 ) ;
V_137 = F_245 ( V_2 , V_367 , V_365 . V_99 ) ;
F_29 ( V_367 ) ;
F_244 ( V_137 , & V_366 -> V_137 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
case V_368 :
{
T_3 V_99 ;
T_3 T_2 * V_369 = V_329 ;
T_6 V_137 ;
if ( F_236 ( V_99 , V_369 ) )
return - V_40 ;
if ( F_234 ( 0 , V_369 ) )
return - V_40 ;
V_137 = F_226 ( V_2 , V_99 ) ;
F_244 ( V_137 , V_369 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
case V_370 :
{
T_3 V_99 ;
T_3 T_2 * V_369 = V_329 ;
T_6 V_137 ;
if ( F_236 ( V_99 , V_369 ) )
return - V_40 ;
if ( F_234 ( 0 , V_369 ) )
return - V_40 ;
V_137 = F_230 ( V_2 , V_99 ) ;
F_244 ( V_137 , V_369 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
}
return F_238 ( V_221 , V_2 , V_330 , V_329 ) ;
}
static int F_246 ( struct V_221 * V_221 ,
struct V_1 * V_2 ,
unsigned int V_330 , void T_2 * V_329 )
{
if ( F_225 ( ! V_2 ) )
return - V_100 ;
if ( F_225 ( V_2 -> V_21 != V_307 ) )
return - V_69 ;
switch ( V_330 ) {
case V_371 :
{
struct V_359 V_360 ;
struct V_359 T_2 * V_361 = V_329 ;
struct V_13 * V_14 = V_2 -> V_14 ;
T_6 V_137 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( F_234 ( 0 , & V_361 -> V_137 ) )
return - V_40 ;
if ( F_80 ( & V_360 , V_361 , sizeof( V_360 ) ) )
return - V_40 ;
V_137 = F_247 ( V_2 , V_360 . V_362 , V_360 . V_99 ) ;
F_244 ( V_137 , & V_361 -> V_137 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
case V_372 :
{
struct V_364 V_365 ;
struct V_364 T_2 * V_366 = V_329 ;
struct V_13 * V_14 = V_2 -> V_14 ;
void * V_367 ;
T_6 V_137 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( V_14 -> V_113 > 128 )
return - V_69 ;
if ( F_234 ( 0 , & V_366 -> V_137 ) )
return - V_40 ;
if ( F_80 ( & V_365 , V_366 , sizeof( V_365 ) ) )
return - V_40 ;
V_367 = F_50 ( V_365 . V_367 ,
sizeof( void * ) * V_14 -> V_113 ) ;
if ( F_51 ( V_367 ) )
return F_52 ( V_367 ) ;
V_137 = F_248 ( V_2 , V_367 , V_365 . V_99 ) ;
F_29 ( V_367 ) ;
F_244 ( V_137 , & V_366 -> V_137 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
case V_368 :
{
T_3 V_99 ;
T_3 T_2 * V_369 = V_329 ;
T_6 V_137 ;
if ( F_236 ( V_99 , V_369 ) )
return - V_40 ;
if ( F_234 ( 0 , V_369 ) )
return - V_40 ;
V_137 = F_228 ( V_2 , V_99 ) ;
F_244 ( V_137 , V_369 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
case V_370 :
{
T_3 V_99 ;
T_3 T_2 * V_369 = V_329 ;
T_6 V_137 ;
if ( F_236 ( V_99 , V_369 ) )
return - V_40 ;
if ( F_234 ( 0 , V_369 ) )
return - V_40 ;
V_137 = F_231 ( V_2 , V_99 ) ;
F_244 ( V_137 , V_369 ) ;
return V_137 < 0 ? V_137 : 0 ;
}
}
return F_238 ( V_221 , V_2 , V_330 , V_329 ) ;
}
static long F_249 ( struct V_221 * V_221 , unsigned int V_330 ,
unsigned long V_329 )
{
struct V_248 * V_249 ;
V_249 = V_221 -> V_254 ;
if ( ( ( V_330 >> 8 ) & 0xff ) != 'A' )
return - V_357 ;
return F_242 ( V_221 , V_249 -> V_2 , V_330 ,
( void T_2 * ) V_329 ) ;
}
static long F_250 ( struct V_221 * V_221 , unsigned int V_330 ,
unsigned long V_329 )
{
struct V_248 * V_249 ;
V_249 = V_221 -> V_254 ;
if ( ( ( V_330 >> 8 ) & 0xff ) != 'A' )
return - V_357 ;
return F_246 ( V_221 , V_249 -> V_2 , V_330 ,
( void T_2 * ) V_329 ) ;
}
int F_251 ( struct V_1 * V_2 ,
unsigned int V_330 , void * V_329 )
{
T_1 V_11 ;
int V_137 ;
V_11 = F_19 () ;
switch ( V_2 -> V_21 ) {
case V_142 :
V_137 = F_242 ( NULL , V_2 , V_330 ,
( void T_2 * ) V_329 ) ;
break;
case V_307 :
V_137 = F_246 ( NULL , V_2 , V_330 ,
( void T_2 * ) V_329 ) ;
break;
default:
V_137 = - V_69 ;
break;
}
F_23 ( V_11 ) ;
return V_137 ;
}
static T_7 F_252 ( struct V_221 * V_221 , char T_2 * V_362 , T_8 V_259 ,
T_9 * V_373 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_137 ;
V_249 = V_221 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( ! F_253 ( V_14 , V_259 ) )
return - V_69 ;
V_259 = F_254 ( V_14 , V_259 ) ;
V_137 = F_247 ( V_2 , V_362 , V_259 ) ;
if ( V_137 > 0 )
V_137 = F_255 ( V_14 , V_137 ) ;
return V_137 ;
}
static T_7 F_256 ( struct V_221 * V_221 , const char T_2 * V_362 ,
T_8 V_259 , T_9 * V_373 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_137 ;
V_249 = V_221 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( ! F_253 ( V_14 , V_259 ) )
return - V_69 ;
V_259 = F_254 ( V_14 , V_259 ) ;
V_137 = F_243 ( V_2 , V_362 , V_259 ) ;
if ( V_137 > 0 )
V_137 = F_255 ( V_14 , V_137 ) ;
return V_137 ;
}
static T_7 F_257 ( struct V_374 * V_375 , const struct V_376 * V_377 ,
unsigned long V_378 , T_9 V_379 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_137 ;
unsigned long V_47 ;
void T_2 * * V_367 ;
T_3 V_99 ;
V_249 = V_375 -> V_380 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( V_378 > 1024 || V_378 != V_14 -> V_113 )
return - V_69 ;
if ( ! F_253 ( V_14 , V_377 -> V_381 ) )
return - V_69 ;
V_99 = F_258 ( V_14 , V_377 -> V_381 ) ;
V_367 = F_27 ( sizeof( void * ) * V_378 , V_38 ) ;
if ( V_367 == NULL )
return - V_39 ;
for ( V_47 = 0 ; V_47 < V_378 ; ++ V_47 )
V_367 [ V_47 ] = V_377 [ V_47 ] . V_382 ;
V_137 = F_248 ( V_2 , V_367 , V_99 ) ;
if ( V_137 > 0 )
V_137 = F_255 ( V_14 , V_137 ) ;
F_29 ( V_367 ) ;
return V_137 ;
}
static T_7 F_259 ( struct V_374 * V_375 , const struct V_376 * V_377 ,
unsigned long V_378 , T_9 V_379 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
T_6 V_137 ;
unsigned long V_47 ;
void T_2 * * V_367 ;
T_3 V_99 ;
V_249 = V_375 -> V_380 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( V_378 > 128 || V_378 != V_14 -> V_113 ||
! F_253 ( V_14 , V_377 -> V_381 ) )
return - V_69 ;
V_99 = F_258 ( V_14 , V_377 -> V_381 ) ;
V_367 = F_27 ( sizeof( void * ) * V_378 , V_38 ) ;
if ( V_367 == NULL )
return - V_39 ;
for ( V_47 = 0 ; V_47 < V_378 ; ++ V_47 )
V_367 [ V_47 ] = V_377 [ V_47 ] . V_382 ;
V_137 = F_245 ( V_2 , V_367 , V_99 ) ;
if ( V_137 > 0 )
V_137 = F_255 ( V_14 , V_137 ) ;
F_29 ( V_367 ) ;
return V_137 ;
}
static unsigned int F_260 ( struct V_221 * V_221 , T_10 * V_224 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_262 ;
T_3 V_153 ;
V_249 = V_221 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
F_261 ( V_221 , & V_14 -> V_187 , V_224 ) ;
F_11 ( V_2 ) ;
V_153 = F_84 ( V_14 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_154 :
case V_103 :
case V_193 :
if ( V_153 >= V_14 -> V_126 -> V_127 ) {
V_262 = V_383 | V_384 ;
break;
}
case V_155 :
V_262 = 0 ;
break;
default:
V_262 = V_383 | V_384 | V_385 ;
break;
}
F_13 ( V_2 ) ;
return V_262 ;
}
static unsigned int F_262 ( struct V_221 * V_221 , T_10 * V_224 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
unsigned int V_262 ;
T_3 V_153 ;
V_249 = V_221 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
F_261 ( V_221 , & V_14 -> V_187 , V_224 ) ;
F_11 ( V_2 ) ;
V_153 = F_85 ( V_14 ) ;
switch ( V_14 -> V_97 -> V_96 ) {
case V_154 :
case V_103 :
case V_193 :
if ( V_153 >= V_14 -> V_126 -> V_127 ) {
V_262 = V_386 | V_387 ;
break;
}
V_262 = 0 ;
break;
case V_155 :
if ( V_153 > 0 ) {
V_262 = V_386 | V_387 ;
break;
}
default:
V_262 = V_386 | V_387 | V_385 ;
break;
}
F_13 ( V_2 ) ;
return V_262 ;
}
static int F_263 ( struct V_388 * V_389 ,
struct V_390 * V_391 )
{
struct V_1 * V_2 = V_389 -> V_392 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_393 ;
V_14 = V_2 -> V_14 ;
V_391 -> V_394 = F_264 ( V_14 -> V_97 ) ;
F_265 ( V_391 -> V_394 ) ;
return 0 ;
}
static int V_322 ( struct V_1 * V_2 , struct V_221 * V_221 ,
struct V_388 * V_389 )
{
long V_395 ;
if ( ! ( V_389 -> V_396 & V_397 ) )
return - V_69 ;
V_395 = V_389 -> V_398 - V_389 -> V_399 ;
if ( V_395 != F_266 ( sizeof( struct V_322 ) ) )
return - V_69 ;
V_389 -> V_400 = & V_401 ;
V_389 -> V_392 = V_2 ;
V_389 -> V_396 |= V_402 | V_403 ;
return 0 ;
}
static int F_267 ( struct V_388 * V_389 ,
struct V_390 * V_391 )
{
struct V_1 * V_2 = V_389 -> V_392 ;
struct V_13 * V_14 ;
if ( V_2 == NULL )
return V_393 ;
V_14 = V_2 -> V_14 ;
V_391 -> V_394 = F_264 ( V_14 -> V_126 ) ;
F_265 ( V_391 -> V_394 ) ;
return 0 ;
}
static int V_323 ( struct V_1 * V_2 , struct V_221 * V_221 ,
struct V_388 * V_389 )
{
long V_395 ;
if ( ! ( V_389 -> V_396 & V_397 ) )
return - V_69 ;
V_395 = V_389 -> V_398 - V_389 -> V_399 ;
if ( V_395 != F_266 ( sizeof( struct V_323 ) ) )
return - V_69 ;
V_389 -> V_400 = & V_404 ;
V_389 -> V_392 = V_2 ;
V_389 -> V_396 |= V_402 | V_403 ;
return 0 ;
}
static int V_322 ( struct V_1 * V_2 , struct V_221 * V_221 ,
struct V_388 * V_389 )
{
return - V_100 ;
}
static int V_323 ( struct V_1 * V_2 , struct V_221 * V_221 ,
struct V_388 * V_389 )
{
return - V_100 ;
}
static inline struct V_394 *
F_268 ( struct V_1 * V_2 , unsigned long V_405 )
{
void * V_406 = V_2 -> V_14 -> V_407 + V_405 ;
#if F_269 ( V_408 ) && F_269 ( V_409 )
if ( V_2 -> V_410 . V_239 . type == V_411 )
return F_264 ( F_270 ( V_406 ) ) ;
#endif
#if F_269 ( V_412 ) && F_269 ( V_413 )
if ( V_2 -> V_410 . V_239 . type == V_411 ) {
T_11 V_414 = V_2 -> V_14 -> V_415 + V_405 ;
V_414 -= F_271 ( V_2 -> V_410 . V_239 . V_239 ) ;
return F_272 ( V_414 >> V_416 ) ;
}
#endif
return F_264 ( V_406 ) ;
}
static int F_273 ( struct V_388 * V_389 ,
struct V_390 * V_391 )
{
struct V_1 * V_2 = V_389 -> V_392 ;
struct V_13 * V_14 ;
unsigned long V_373 ;
struct V_394 * V_394 ;
T_8 V_298 ;
if ( V_2 == NULL )
return V_393 ;
V_14 = V_2 -> V_14 ;
V_373 = V_391 -> V_417 << V_416 ;
V_298 = F_266 ( V_14 -> V_298 ) ;
if ( V_373 > V_298 - V_418 )
return V_393 ;
if ( V_2 -> V_33 -> V_394 )
V_394 = V_2 -> V_33 -> V_394 ( V_2 , V_373 ) ;
else
V_394 = F_268 ( V_2 , V_373 ) ;
if ( ! V_394 )
return V_393 ;
F_265 ( V_394 ) ;
V_391 -> V_394 = V_394 ;
return 0 ;
}
int F_274 ( struct V_1 * V_2 ,
struct V_388 * V_389 )
{
V_389 -> V_396 |= V_402 | V_403 ;
#ifdef F_275
if ( V_2 -> V_410 . V_239 . type == V_419 ) {
V_389 -> V_420 = F_276 ( V_389 -> V_420 ) ;
return F_277 ( V_389 , V_389 -> V_399 ,
V_2 -> V_410 . V_414 >> V_416 ,
V_389 -> V_398 - V_389 -> V_399 , V_389 -> V_420 ) ;
}
#endif
#ifdef F_278
if ( ! V_2 -> V_33 -> V_394 &&
V_2 -> V_410 . V_239 . type == V_411 )
return F_279 ( V_2 -> V_410 . V_239 . V_239 ,
V_389 ,
V_2 -> V_14 -> V_407 ,
V_2 -> V_14 -> V_415 ,
V_389 -> V_398 - V_389 -> V_399 ) ;
#elif F_269 ( V_408 ) && F_269 ( V_409 )
if ( V_2 -> V_410 . V_239 . type == V_411 &&
! F_280 ( V_2 -> V_410 . V_239 . V_239 ) )
V_389 -> V_420 = F_281 ( V_389 -> V_420 ) ;
#endif
V_389 -> V_400 = & V_421 ;
return 0 ;
}
int F_282 ( struct V_1 * V_2 ,
struct V_388 * V_389 )
{
struct V_13 * V_14 = V_2 -> V_14 ; ;
V_389 -> V_420 = F_281 ( V_389 -> V_420 ) ;
return F_283 ( V_389 , V_14 -> V_415 , V_14 -> V_298 ) ;
}
int F_284 ( struct V_1 * V_2 , struct V_221 * V_221 ,
struct V_388 * V_389 )
{
struct V_13 * V_14 ;
long V_395 ;
unsigned long V_373 ;
T_8 V_298 ;
int V_37 ;
if ( V_2 -> V_21 == V_142 ) {
if ( ! ( V_389 -> V_396 & ( V_422 | V_397 ) ) )
return - V_69 ;
} else {
if ( ! ( V_389 -> V_396 & V_397 ) )
return - V_69 ;
}
V_14 = V_2 -> V_14 ;
if ( V_14 -> V_97 -> V_96 == V_101 )
return - V_104 ;
if ( ! ( V_14 -> V_12 & V_281 ) )
return - V_100 ;
if ( V_14 -> V_110 == V_278 ||
V_14 -> V_110 == V_280 )
return - V_69 ;
V_395 = V_389 -> V_398 - V_389 -> V_399 ;
V_373 = V_389 -> V_423 << V_416 ;
V_298 = F_266 ( V_14 -> V_298 ) ;
if ( ( T_8 ) V_395 > V_298 )
return - V_69 ;
if ( V_373 > V_298 - V_395 )
return - V_69 ;
V_389 -> V_400 = & V_424 ;
V_389 -> V_392 = V_2 ;
if ( V_2 -> V_33 -> V_425 )
V_37 = V_2 -> V_33 -> V_425 ( V_2 , V_389 ) ;
else
V_37 = F_274 ( V_2 , V_389 ) ;
if ( ! V_37 )
F_285 ( & V_2 -> V_107 ) ;
return V_37 ;
}
static int F_286 ( struct V_221 * V_221 , struct V_388 * V_389 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
unsigned long V_373 ;
V_249 = V_221 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_373 = V_389 -> V_423 << V_416 ;
switch ( V_373 ) {
case V_426 :
if ( V_249 -> V_427 )
return - V_100 ;
return V_322 ( V_2 , V_221 , V_389 ) ;
case V_428 :
if ( V_249 -> V_427 )
return - V_100 ;
return V_323 ( V_2 , V_221 , V_389 ) ;
default:
return F_284 ( V_2 , V_221 , V_389 ) ;
}
return 0 ;
}
static int F_287 ( int V_247 , struct V_221 * V_221 , int V_429 )
{
struct V_248 * V_249 ;
struct V_1 * V_2 ;
struct V_13 * V_14 ;
V_249 = V_221 -> V_254 ;
V_2 = V_249 -> V_2 ;
if ( F_55 ( V_2 ) )
return - V_100 ;
V_14 = V_2 -> V_14 ;
return F_288 ( V_247 , V_221 , V_429 , & V_14 -> V_430 ) ;
}
static void F_289 ( struct V_41 * V_42 ,
struct V_431 * V_432 )
{
unsigned int V_47 ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
V_42 -> V_10 = V_432 -> V_10 ;
for ( V_47 = 0 ; V_47 < F_290 ( V_432 -> V_433 ) ; V_47 ++ )
V_42 -> V_433 [ V_47 ] . V_71 [ 0 ] = V_432 -> V_433 [ V_47 ] ;
memcpy ( V_42 -> V_434 , V_432 -> V_434 , sizeof( V_432 -> V_434 ) ) ;
V_42 -> V_61 = F_291 ( V_432 -> V_61 ) ;
V_42 -> V_72 = F_291 ( V_432 -> V_72 ) ;
V_42 -> V_12 = V_432 -> V_12 ;
V_42 -> V_63 = V_432 -> V_63 ;
V_42 -> V_65 = V_432 -> V_65 ;
V_42 -> V_66 = V_432 -> V_66 ;
V_42 -> V_60 = V_432 -> V_60 ;
}
static void F_292 ( struct V_431 * V_432 ,
struct V_41 * V_42 )
{
unsigned int V_47 ;
memset ( V_432 , 0 , sizeof( * V_432 ) ) ;
V_432 -> V_10 = V_42 -> V_10 ;
for ( V_47 = 0 ; V_47 < F_290 ( V_432 -> V_433 ) ; V_47 ++ )
V_432 -> V_433 [ V_47 ] = V_42 -> V_433 [ V_47 ] . V_71 [ 0 ] ;
memcpy ( V_432 -> V_434 , V_42 -> V_434 , sizeof( V_432 -> V_434 ) ) ;
V_432 -> V_61 = F_293 ( V_42 -> V_61 ) ;
V_432 -> V_72 = F_293 ( V_42 -> V_72 ) ;
V_432 -> V_12 = V_42 -> V_12 ;
V_432 -> V_63 = V_42 -> V_63 ;
V_432 -> V_65 = V_42 -> V_65 ;
V_432 -> V_66 = V_42 -> V_66 ;
V_432 -> V_60 = V_42 -> V_60 ;
}
static int F_240 ( struct V_1 * V_2 ,
struct V_431 T_2 * V_435 )
{
struct V_41 * V_42 ;
struct V_431 * V_432 = NULL ;
int V_37 ;
V_42 = F_27 ( sizeof( * V_42 ) , V_38 ) ;
if ( ! V_42 )
return - V_39 ;
V_432 = F_50 ( V_435 , sizeof( * V_432 ) ) ;
if ( F_51 ( V_432 ) ) {
V_37 = F_52 ( V_432 ) ;
goto V_436;
}
F_289 ( V_42 , V_432 ) ;
V_37 = F_30 ( V_2 , V_42 ) ;
F_292 ( V_432 , V_42 ) ;
if ( F_28 ( V_435 , V_432 , sizeof( * V_432 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_432 ) ;
V_436:
F_29 ( V_42 ) ;
return V_37 ;
}
static int F_241 ( struct V_1 * V_2 ,
struct V_431 T_2 * V_435 )
{
struct V_41 * V_42 ;
struct V_431 * V_432 = NULL ;
int V_37 ;
V_42 = F_27 ( sizeof( * V_42 ) , V_38 ) ;
if ( ! V_42 )
return - V_39 ;
V_432 = F_50 ( V_435 , sizeof( * V_432 ) ) ;
if ( F_51 ( V_432 ) ) {
V_37 = F_52 ( V_432 ) ;
goto V_436;
}
F_289 ( V_42 , V_432 ) ;
V_37 = V_41 ( V_2 , V_42 ) ;
F_292 ( V_432 , V_42 ) ;
if ( F_28 ( V_435 , V_432 , sizeof( * V_432 ) ) ) {
if ( ! V_37 )
V_37 = - V_40 ;
}
F_29 ( V_432 ) ;
V_436:
F_29 ( V_42 ) ;
return V_37 ;
}
static unsigned long F_294 ( struct V_221 * V_221 ,
unsigned long V_414 ,
unsigned long V_437 ,
unsigned long V_417 ,
unsigned long V_10 )
{
struct V_248 * V_249 = V_221 -> V_254 ;
struct V_1 * V_2 = V_249 -> V_2 ;
struct V_13 * V_14 = V_2 -> V_14 ;
unsigned long V_373 = V_417 << V_416 ;
switch ( V_373 ) {
case V_426 :
return ( unsigned long ) V_14 -> V_97 ;
case V_428 :
return ( unsigned long ) V_14 -> V_126 ;
default:
return ( unsigned long ) V_14 -> V_407 + V_373 ;
}
}
