static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( V_2 != NULL && V_2 -> V_4 -> V_5 && V_2 -> V_6 > 0 ) {
V_3 = ( 1000000000 + V_2 -> V_6 - 1 ) / V_2 -> V_6 ;
F_2 ( 8 * V_3 ) ;
}
}
static void F_3 ( struct V_7 * V_4 , unsigned int V_8 )
{
unsigned long V_9 ;
F_4 ( & V_4 -> V_10 , V_9 ) ;
if ( V_4 -> V_5 != V_8 ) {
V_4 -> V_5 = V_8 ;
if ( V_8 )
F_5 ( V_4 -> V_11 ) ;
else
F_6 ( V_4 -> V_11 ) ;
}
F_7 ( & V_4 -> V_10 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 , int V_12 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned long V_9 ;
if ( V_12 )
goto V_13;
F_4 ( & V_4 -> V_14 , V_9 ) ;
while ( V_4 -> V_15 != NULL ) {
F_7 ( & V_4 -> V_14 , V_9 ) ;
F_9 ( V_4 -> V_16 , V_4 -> V_15 == NULL ) ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
}
V_4 -> V_15 = V_2 -> V_15 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
V_13:
F_10 ( & V_4 -> V_17 ) ;
if ( V_4 -> V_18 != V_2 || ! V_12 )
F_1 ( V_4 -> V_18 ) ;
if ( V_4 -> V_18 != V_2 ) {
F_11 ( V_4 , V_19 , V_2 -> V_20 & 0xFC00 ) ;
if ( V_4 -> V_21 -> V_22 != NULL )
V_4 -> V_21 -> V_22 ( F_12 ( V_2 -> V_15 ) , V_2 -> V_23 ) ;
V_4 -> V_18 = V_2 ;
}
if ( V_12 ) {
F_3 ( V_4 , 1 ) ;
F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_2 -> V_20 ) ;
} else
F_3 ( V_4 , 0 ) ;
}
static void F_14 ( struct V_24 * V_25 )
{
struct V_7 * V_4 = F_15 ( V_25 , struct V_7 ,
V_26 ) ;
struct V_1 * V_27 = V_4 -> V_27 ;
struct V_28 * V_29 ;
V_4 -> V_27 = NULL ;
F_8 ( V_27 , 1 ) ;
V_29 = V_27 -> V_30 ;
V_27 -> V_30 = NULL ;
F_16 ( V_4 , V_29 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_31 )
{
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned long V_9 ;
int V_32 ;
F_18 ( V_2 == NULL || V_4 -> V_15 == NULL ) ;
if ( V_31 )
F_19 ( & V_4 -> V_17 , V_33 + V_34 / 10 ) ;
else {
F_10 ( & V_4 -> V_17 ) ;
F_1 ( V_2 ) ;
F_3 ( V_4 , 0 ) ;
}
F_4 ( & V_4 -> V_14 , V_9 ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
struct V_1 * V_36 ;
if ( V_4 -> V_37 [ V_32 ] == NULL || V_4 -> V_37 [ V_32 ] -> V_30 == NULL )
continue;
F_18 ( V_4 -> V_27 != NULL ) ;
V_36 = V_4 -> V_37 [ V_32 ] ;
F_18 ( V_36 == V_4 -> V_18 ) ;
V_4 -> V_27 = V_36 ;
V_4 -> V_15 = V_36 -> V_15 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
F_20 ( V_4 -> V_38 , & V_4 -> V_26 ) ;
return;
}
V_4 -> V_15 = NULL ;
F_21 ( & V_4 -> V_16 ) ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
}
static inline
int F_22 ( struct V_1 * V_2 )
{
if ( V_2 -> V_21 -> V_39 )
return V_2 -> V_21 -> V_39 ( F_12 ( V_2 -> V_15 ) ,
V_2 -> V_23 ) ;
return 0 ;
}
static T_1
F_23 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_45 * V_15 = F_15 ( V_41 , struct V_45 , V_46 ) ;
struct V_1 * V_2 = F_24 ( V_15 ) ;
return sprintf ( V_44 , L_1 , F_22 ( V_2 ) ? L_2 :
L_3 ) ;
}
static T_1
F_25 ( struct V_40 * V_41 , struct V_42 * V_43 ,
char * V_44 )
{
struct V_45 * V_15 = F_15 ( V_41 , struct V_45 , V_46 ) ;
struct V_1 * V_2 = F_24 ( V_15 ) ;
return sprintf ( V_44 , L_1 , V_2 -> V_21 -> V_47 ) ;
}
static void
F_26 ( struct V_7 * V_4 , struct V_48 * V_49 )
{
T_2 V_50 ;
T_2 V_51 ;
T_2 V_52 ;
V_4 -> V_49 = V_49 ;
V_51 = 0 ;
V_52 = 0 ;
switch ( F_27 ( V_49 ) ) {
case V_53 :
break;
case V_54 :
case V_55 :
V_51 = 1 ;
break;
case V_56 :
V_51 = 2 ;
break;
case V_57 :
V_51 = 3 ;
break;
default:
F_28 ( F_12 ( V_4 -> V_15 ) , L_4 , F_27 ( V_49 ) ) ;
break;
}
if ( F_29 ( V_49 ) == V_58 ) {
V_52 = V_59 ;
} else if ( F_29 ( V_49 ) == V_60 ) {
V_52 = V_61 ;
} else if ( F_29 ( V_49 ) == V_62 ) {
V_52 = V_63 ;
} else {
V_52 = V_64 ;
}
V_50 = V_49 -> V_65 | ( V_51 << 8 ) | ( V_52 << 12 ) ;
if ( V_4 -> V_18 -> V_66 == V_67 )
V_50 |= 1 << 6 ;
if ( V_49 -> V_9 & V_68 )
V_50 |= 1 << 11 ;
if ( V_4 -> V_69 && ! ( V_4 -> V_69 -> V_9 & V_70 ) )
V_50 |= 1 << 15 ;
F_19 ( & V_4 -> V_71 , V_33 + V_34 / 2 ) ;
F_11 ( V_4 , V_72 , 200 ) ;
F_11 ( V_4 , V_73 , V_49 -> V_74 & 0xffff ) ;
F_11 ( V_4 , V_75 , V_49 -> V_74 >> 16 ) ;
F_11 ( V_4 , V_76 ,
V_77 | V_78 |
V_79 | V_80 |
V_81 | V_82 |
V_83 | V_84 |
V_85 ) ;
F_11 ( V_4 , V_86 , V_50 ) ;
}
static void
F_30 ( struct V_7 * V_4 , struct V_87 * V_69 ,
int abort )
{
enum V_88 V_89 ;
struct V_40 * V_41 = F_12 ( V_4 -> V_15 ) ;
struct V_90 * V_91 ;
if ( V_69 -> V_9 & V_70 ) {
V_89 = V_92 ;
V_91 = V_4 -> V_93 ;
} else {
V_89 = V_94 ;
V_91 = V_4 -> V_95 ;
}
if ( V_91 ) {
if ( V_69 -> error ) {
F_31 ( V_91 ) ;
V_69 -> V_96 = 0 ;
}
V_41 = V_91 -> V_40 -> V_41 ;
}
F_32 ( V_41 , V_69 -> V_97 , V_4 -> V_98 , V_89 ) ;
}
static void F_33 ( struct V_24 * V_25 )
{
struct V_7 * V_4 = F_15 ( V_25 , struct V_7 ,
V_99 ) ;
struct V_1 * V_2 = V_4 -> V_18 ;
struct V_87 * V_69 = V_4 -> V_100 ;
unsigned long V_3 ;
V_3 = ( 1000000000 + V_2 -> V_6 - 1 ) / V_2 -> V_6 ;
F_2 ( 8 * V_3 ) ;
F_26 ( V_4 , V_69 -> V_101 ) ;
}
static void
F_34 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
if ( V_4 -> V_102 )
F_30 ( V_4 , V_69 , V_69 -> error ) ;
V_4 -> V_69 = NULL ;
V_4 -> V_98 = 0 ;
if ( ! V_69 -> V_101 ) {
struct V_45 * V_15 ;
V_4 -> V_30 = NULL ;
V_15 = V_4 -> V_15 ;
F_17 ( V_4 -> V_18 , 1 ) ;
F_35 ( V_15 , V_69 -> V_30 ) ;
return;
}
V_4 -> V_100 = V_69 ;
F_20 ( V_4 -> V_38 , & V_4 -> V_99 ) ;
}
static void
F_36 ( struct V_7 * V_4 , int V_103 )
{
struct V_1 * V_2 = V_4 -> V_18 ;
unsigned int V_104 , V_105 , V_106 ;
T_3 V_107 = 0 ;
V_106 = ( 120 * 1000000 + V_2 -> V_6 - 1 ) / V_2 -> V_6 ;
V_104 = 0 ;
while ( V_104 < V_103 ) {
F_11 ( V_4 , V_108 , 0xFFFF ) ;
F_11 ( V_4 , V_86 , ( 3 << 12 ) | ( 1 << 7 ) ) ;
V_105 = 0 ;
while ( V_105 < V_106 ) {
V_107 = F_13 ( V_4 , V_108 ) ;
if ( V_107 & V_83 )
goto V_109;
F_37 ( 1 ) ;
V_105 ++ ;
}
V_104 ++ ;
}
V_109:
F_11 ( V_4 , V_108 , V_107 ) ;
}
static void
F_38 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
if ( V_4 -> V_102 )
F_30 ( V_4 , V_69 , 1 ) ;
V_4 -> V_69 = NULL ;
V_4 -> V_98 = 0 ;
F_36 ( V_4 , 10000 ) ;
}
static void
F_39 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
unsigned long V_9 ;
int V_110 ;
if ( ! V_4 -> V_102 ) {
F_34 ( V_4 , V_69 ) ;
return;
}
V_110 = 0 ;
F_4 ( & V_4 -> V_111 , V_9 ) ;
if ( V_4 -> V_112 )
V_110 = 1 ;
else
V_4 -> V_113 = 1 ;
F_7 ( & V_4 -> V_111 , V_9 ) ;
if ( V_110 )
F_34 ( V_4 , V_69 ) ;
}
static void
F_40 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
unsigned long V_9 ;
int V_110 ;
V_110 = 0 ;
F_4 ( & V_4 -> V_111 , V_9 ) ;
if ( V_4 -> V_113 )
V_110 = 1 ;
else
V_4 -> V_112 = 1 ;
F_7 ( & V_4 -> V_111 , V_9 ) ;
if ( V_110 )
F_34 ( V_4 , V_69 ) ;
}
static void
F_41 ( struct V_7 * V_4 , struct V_48 * V_49 )
{
V_4 -> V_49 = NULL ;
F_10 ( & V_4 -> V_71 ) ;
if ( V_49 -> V_9 & V_114 ) {
if ( V_49 -> V_9 & V_115 ) {
V_49 -> V_116 [ 3 ] =
F_13 ( V_4 , V_117 ) |
( F_13 ( V_4 , V_118 ) << 16 ) ;
V_49 -> V_116 [ 2 ] =
F_13 ( V_4 , V_119 ) |
( F_13 ( V_4 , V_120 ) << 16 ) ;
V_49 -> V_116 [ 1 ] =
F_13 ( V_4 , V_121 ) |
( F_13 ( V_4 , V_122 ) << 16 ) ;
V_49 -> V_116 [ 0 ] =
F_13 ( V_4 , V_123 ) |
( F_13 ( V_4 , V_124 ) << 16 ) ;
} else {
V_49 -> V_116 [ 0 ] =
F_13 ( V_4 , V_123 ) |
( F_13 ( V_4 , V_124 ) << 16 ) ;
}
}
if ( V_4 -> V_69 == NULL || V_49 -> error ) {
struct V_45 * V_15 ;
if ( V_4 -> V_69 != NULL )
F_38 ( V_4 , V_4 -> V_69 ) ;
V_4 -> V_30 = NULL ;
V_15 = V_4 -> V_15 ;
F_17 ( V_4 -> V_18 , 1 ) ;
F_35 ( V_15 , V_49 -> V_30 ) ;
}
}
static void F_42 ( struct V_24 * V_25 )
{
struct V_7 * V_4 = F_15 ( V_25 , struct V_7 ,
V_125 ) ;
F_18 ( ! V_4 -> V_49 ) ;
F_43 ( F_12 ( V_4 -> V_15 ) , L_5 ,
V_4 -> V_49 -> V_65 ) ;
if ( V_4 -> V_49 -> error == 0 )
V_4 -> V_49 -> error = - V_126 ;
if ( V_4 -> V_69 == NULL ) {
struct V_48 * V_49 ;
struct V_45 * V_15 ;
V_49 = V_4 -> V_49 ;
V_4 -> V_49 = NULL ;
F_36 ( V_4 , 10000 ) ;
V_4 -> V_30 = NULL ;
V_15 = V_4 -> V_15 ;
F_17 ( V_4 -> V_18 , 1 ) ;
F_35 ( V_15 , V_49 -> V_30 ) ;
} else
F_41 ( V_4 , V_4 -> V_49 ) ;
V_4 -> abort = 0 ;
F_44 ( V_4 -> V_127 ) ;
}
static void
F_45 ( unsigned long V_69 )
{
struct V_7 * V_4 = (struct V_7 * ) V_69 ;
unsigned long V_9 ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
if ( V_4 -> V_49 != NULL && ! V_4 -> abort ) {
F_11 ( V_4 , V_76 , 0 ) ;
F_46 ( V_4 -> V_127 ) ;
V_4 -> abort = 1 ;
F_20 ( V_4 -> V_38 , & V_4 -> V_125 ) ;
}
F_7 ( & V_4 -> V_14 , V_9 ) ;
}
static void
F_47 ( struct V_7 * V_4 )
{
struct V_128 * V_97 ;
V_97 = V_4 -> V_69 -> V_97 + V_4 -> V_129 ;
V_4 -> V_130 = V_97 -> V_131 ;
V_4 -> V_132 = F_48 ( V_97 ) ;
if ( V_4 -> V_130 > V_4 -> V_133 )
V_4 -> V_130 = V_4 -> V_133 ;
}
static void
F_49 ( unsigned long V_69 )
{
struct V_7 * V_4 = (struct V_7 * ) V_69 ;
F_3 ( V_4 , 0 ) ;
}
static void
F_50 ( struct V_7 * V_4 , int V_134 )
{
int V_135 , V_136 ;
if ( V_4 -> V_130 == 0 ) {
V_4 -> V_129 ++ ;
F_18 ( V_4 -> V_129 == V_4 -> V_98 ) ;
F_47 ( V_4 ) ;
}
V_135 = 64 ;
if ( V_135 > V_4 -> V_130 )
V_135 = V_4 -> V_130 ;
V_136 = V_135 / 2 ;
V_136 += V_135 & 1 ;
V_4 -> V_130 -= V_135 ;
V_4 -> V_133 -= V_135 ;
V_4 -> V_69 -> V_96 += V_135 ;
if ( V_134 ) {
F_51 ( V_4 -> V_137 + F_52 ( V_4 , V_138 ) ,
V_4 -> V_132 , V_136 ) ;
} else {
F_53 ( V_4 -> V_137 + F_52 ( V_4 , V_138 ) ,
V_4 -> V_132 , V_136 ) ;
}
V_4 -> V_132 += V_136 ;
}
static inline void F_54 ( T_3 V_139 )
{
static const char * V_140 [] = {
L_6 , L_7 , L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
int V_32 , V_91 = 0 ;
for ( V_32 = 0 ; V_32 < F_55 ( V_140 ) ; V_32 ++ )
if ( V_139 & ( 1 << V_32 ) ) {
if ( V_91 )
F_56 ( L_21 ) ;
F_56 ( L_22 , V_140 [ V_32 ] ) ;
V_91 ++ ;
}
}
static T_4 F_57 ( int V_127 , void * V_141 )
{
struct V_7 * V_4 = (struct V_7 * ) V_141 ;
T_3 V_139 ;
int V_142 ;
int V_143 ;
int V_144 , V_145 ;
if ( V_4 -> V_49 == NULL && V_4 -> V_69 == NULL ) {
V_139 = F_13 ( V_4 , V_108 ) ;
F_58 ( F_12 ( V_4 -> V_37 [ 0 ] -> V_15 ) ,
L_23 , V_139 ) ;
if ( V_139 != 0 ) {
F_11 ( V_4 , V_108 , V_139 ) ;
F_11 ( V_4 , V_76 , 0 ) ;
}
return V_146 ;
}
V_142 = 0 ;
V_143 = 0 ;
V_144 = 0 ;
V_145 = 0 ;
while ( ( V_139 = F_13 ( V_4 , V_108 ) ) != 0 ) {
int V_49 ;
F_11 ( V_4 , V_108 , V_139 ) ;
if ( V_4 -> V_49 != NULL )
V_49 = V_4 -> V_49 -> V_65 ;
else
V_49 = - 1 ;
#ifdef F_59
F_43 ( F_12 ( V_4 -> V_15 ) , L_24 ,
V_139 , V_49 ) ;
F_54 ( V_139 ) ;
F_56 ( L_25 ) ;
#endif
if ( V_4 -> V_133 ) {
if ( ( V_139 & V_78 ) ||
( V_139 & V_85 ) )
F_50 ( V_4 , 0 ) ;
if ( V_139 & V_77 )
F_50 ( V_4 , 1 ) ;
}
if ( V_139 & V_85 )
V_143 = 1 ;
if ( V_139 & V_82 ) {
F_43 ( F_12 ( V_4 -> V_15 ) , L_26 ,
V_49 ) ;
if ( V_4 -> V_69 ) {
V_4 -> V_69 -> error = - V_126 ;
V_144 = 1 ;
}
}
if ( V_139 & V_81 ) {
if ( V_4 -> V_69 ) {
V_4 -> V_69 -> error = - V_147 ;
F_43 ( F_12 ( V_4 -> V_15 ) ,
L_27 ,
V_4 -> V_133 ) ;
V_144 = 1 ;
} else {
F_43 ( F_12 ( V_4 -> V_15 ) , L_28 ) ;
}
}
if ( V_139 & V_80 ) {
if ( V_4 -> V_49 ) {
struct V_1 * V_2 =
V_4 -> V_18 ;
if ( V_2 == NULL ||
! F_22 ( V_2 ) )
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_29 ,
V_49 ) ;
V_4 -> V_49 -> error = - V_126 ;
V_142 = 1 ;
V_145 = 1 ;
}
}
if ( V_139 & V_79 ) {
if ( V_4 -> V_49 ) {
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_30 ,
V_49 , V_4 -> V_49 -> V_74 ) ;
V_4 -> V_49 -> error = - V_147 ;
V_142 = 1 ;
V_145 = 1 ;
} else
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_31 ) ;
}
if ( V_139 & V_84 ) {
F_43 ( F_12 ( V_4 -> V_15 ) ,
L_32 ,
V_49 ) ;
V_142 = 1 ;
}
if ( ( V_139 & V_83 ) &&
( ! ( V_139 & V_77 ) ) ) {
V_142 = 1 ;
}
}
if ( V_145 && V_4 -> V_69 ) {
F_10 ( & V_4 -> V_71 ) ;
V_4 -> abort = 1 ;
F_11 ( V_4 , V_76 , 0 ) ;
F_60 ( V_4 -> V_127 ) ;
F_20 ( V_4 -> V_38 , & V_4 -> V_125 ) ;
return V_146 ;
}
if ( V_142 && V_4 -> V_49 )
F_41 ( V_4 , V_4 -> V_49 ) ;
if ( V_4 -> V_69 != NULL ) {
if ( V_144 )
F_34 ( V_4 , V_4 -> V_69 ) ;
else if ( V_143 )
F_39 ( V_4 , V_4 -> V_69 ) ;
}
return V_146 ;
}
void F_61 ( struct V_40 * V_41 , int V_148 , int V_149 )
{
int V_150 ;
struct V_7 * V_4 = F_62 ( V_41 ) ;
struct V_1 * V_2 = V_4 -> V_37 [ V_148 ] ;
F_18 ( V_148 >= V_4 -> V_35 ) ;
if ( V_4 -> V_35 == 0 || ! V_4 -> V_37 [ V_148 ] )
return;
V_150 = F_22 ( V_2 ) ;
if ( V_150 != V_2 -> V_150 ) {
V_2 -> V_150 = V_150 ;
F_63 ( & V_2 -> V_15 -> V_46 . V_151 , NULL , L_33 ) ;
}
F_64 ( & V_2 -> V_152 ) ;
}
static void F_65 ( unsigned long V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_66 ( & V_2 -> V_152 ) ;
}
static void F_67 ( unsigned long V_153 )
{
struct V_1 * V_2 = (struct V_1 * ) V_153 ;
int V_150 = F_22 ( V_2 ) ;
F_68 ( V_2 -> V_15 , 0 ) ;
if ( ! V_150 )
return;
if ( V_2 -> V_15 -> V_154 == NULL || ! F_69 ( V_2 -> V_15 -> V_154 ) )
return;
F_19 ( & V_2 -> V_155 ,
V_33 + F_70 ( V_156 ) ) ;
}
static void F_71 ( void * V_157 )
{
struct V_7 * V_4 = V_157 ;
struct V_87 * V_69 = V_4 -> V_69 ;
V_69 -> V_96 += V_69 -> V_158 * V_69 -> V_159 ;
F_40 ( V_4 , V_69 ) ;
}
static inline void F_72 ( struct V_7 * V_4 , struct V_28 * V_160 )
{
T_3 V_161 ;
V_161 = F_13 ( V_4 , V_162 ) ;
V_161 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_162 , V_161 ) ;
F_11 ( V_4 , V_72 , 0xff ) ;
}
static inline void F_73 ( struct V_7 * V_4 , struct V_28 * V_160 )
{
unsigned int V_106 , V_163 ;
T_3 V_161 ;
V_163 = 1000000000 / V_4 -> V_18 -> V_6 ;
V_106 = V_160 -> V_69 -> V_164 / V_163 ;
V_106 += V_160 -> V_69 -> V_165 ;
V_161 = F_13 ( V_4 , V_162 ) ;
if ( V_106 > 0xffff ) {
V_161 |= ( 1 << 5 ) ;
V_106 /= 1024 ;
} else
V_161 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_162 , V_161 ) ;
F_11 ( V_4 , V_166 , V_106 ) ;
}
static void
F_74 ( struct V_7 * V_4 , struct V_28 * V_160 )
{
struct V_87 * V_69 = V_160 -> V_69 ;
int V_32 , V_167 , V_168 ;
unsigned V_98 ;
V_4 -> V_69 = V_69 ;
if ( V_69 == NULL ) {
F_11 ( V_4 , V_169 , 0 ) ;
F_11 ( V_4 , V_170 , 0 ) ;
F_11 ( V_4 , V_171 , 0 ) ;
V_4 -> V_102 = 0 ;
F_72 ( V_4 , V_160 ) ;
return;
}
V_168 = V_69 -> V_159 ;
F_11 ( V_4 , V_170 , V_69 -> V_158 - 1 ) ;
F_11 ( V_4 , V_169 , V_168 - 1 ) ;
F_73 ( V_4 , V_160 ) ;
V_98 = ( V_69 -> V_158 == 1 ) ? 1 : V_69 -> V_98 ;
V_167 = V_4 -> V_167 ;
if ( V_167 ) {
for ( V_32 = 0 ; V_32 < V_98 ; V_32 ++ ) {
if ( ( V_69 -> V_97 [ V_32 ] . V_131 % V_168 ) != 0 ) {
V_167 = 0 ;
break;
}
}
}
V_4 -> V_129 = 0 ;
if ( V_167 ) {
enum V_88 V_89 ;
struct V_172 * V_173 ;
struct V_90 * V_91 ;
T_2 V_174 , * V_175 ;
T_3 V_44 ;
V_174 = F_75 () ? 32 : 64 ;
if ( V_174 > V_69 -> V_159 )
V_174 = V_69 -> V_159 ;
V_174 >>= 1 ;
if ( V_69 -> V_9 & V_70 ) {
V_91 = V_4 -> V_93 ;
V_175 = & V_4 -> V_176 ;
V_44 = 0x0f80 | ( V_174 - 1 ) << 0 ;
V_89 = V_92 ;
} else {
V_91 = V_4 -> V_95 ;
V_175 = & V_4 -> V_177 ;
V_44 = 0x800f | ( V_174 - 1 ) << 8 ;
V_89 = V_94 ;
}
if ( ! V_91 )
goto V_178;
if ( * V_175 != V_174 ) {
struct V_179 V_180 ;
V_180 . V_181 = V_4 -> V_182 + F_52 ( V_4 , V_138 ) ;
V_180 . V_183 = V_4 -> V_182 + F_52 ( V_4 , V_138 ) ;
V_180 . V_184 = V_185 ;
V_180 . V_186 = V_185 ;
V_180 . V_187 = V_174 ;
V_180 . V_188 = V_174 ;
if ( F_76 ( V_91 , & V_180 ) )
goto V_178;
* V_175 = V_174 ;
}
V_4 -> V_98 = F_77 ( V_91 -> V_40 -> V_41 , V_69 -> V_97 , V_98 ,
V_89 ) ;
if ( V_4 -> V_98 == 0 )
goto V_178;
V_173 = F_78 ( V_91 , V_69 -> V_97 , V_4 -> V_98 ,
V_69 -> V_9 & V_70 ? V_189 : V_190 ,
V_191 | V_192 ) ;
if ( ! V_173 )
goto V_178;
F_11 ( V_4 , V_171 , V_44 ) ;
V_173 -> V_193 = F_71 ;
V_173 -> V_194 = V_4 ;
F_79 ( V_173 ) ;
V_4 -> V_113 = 0 ;
V_4 -> V_112 = 0 ;
V_4 -> V_102 = 1 ;
return;
}
V_178:
F_11 ( V_4 , V_171 , 0x1f1f ) ;
V_4 -> V_133 = V_69 -> V_158 * V_168 ;
V_4 -> V_98 = V_98 ;
F_47 ( V_4 ) ;
V_4 -> V_102 = 0 ;
}
static void F_16 ( struct V_7 * V_4 ,
struct V_28 * V_160 )
{
F_18 ( V_4 -> V_30 != NULL ) ;
V_4 -> V_30 = V_160 ;
F_74 ( V_4 , V_160 ) ;
F_26 ( V_4 , V_160 -> V_49 ) ;
if ( V_4 -> V_102 ) {
struct V_90 * V_91 = V_4 -> V_69 -> V_9 & V_70 ?
V_4 -> V_93 : V_4 -> V_95 ;
F_80 ( V_91 ) ;
}
}
static void F_81 ( struct V_45 * V_15 , struct V_28 * V_160 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned long V_9 ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
if ( V_4 -> V_15 != NULL ) {
F_18 ( V_2 -> V_30 != NULL ) ;
V_2 -> V_30 = V_160 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
return;
} else
V_4 -> V_15 = V_15 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
F_8 ( V_2 , 1 ) ;
F_16 ( V_4 , V_160 ) ;
}
static void F_82 ( struct V_1 * V_2 , int V_195 ,
int V_196 )
{
struct V_7 * V_4 ;
V_4 = V_2 -> V_4 ;
if ( V_2 -> V_21 -> V_197 != NULL )
V_2 -> V_21 -> V_197 ( F_12 ( V_2 -> V_15 ) , V_2 -> V_23 , V_195 ,
V_196 ) ;
if ( F_83 () ) {
T_3 V_198 ;
if ( V_195 ) {
V_198 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_198 | ( 1 << 11 ) ) ;
} else {
V_198 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_198 & ~ ( 1 << 11 ) ) ;
}
}
}
static int F_84 ( struct V_45 * V_15 , struct V_199 * V_200 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_201 = F_85 ( V_4 -> V_11 ) ;
int V_202 ;
if ( V_200 -> clock == 0 )
return 0 ;
V_202 = V_201 / V_200 -> clock ;
if ( V_202 < 1 )
V_202 = 1 ;
if ( V_201 / V_202 > V_200 -> clock )
V_202 ++ ;
if ( V_202 > 250 )
V_202 = 250 ;
V_2 -> V_6 = V_201 / V_202 ;
if ( V_200 -> V_203 == V_204 )
V_202 |= 1 << 15 ;
return V_202 ;
}
static void F_86 ( struct V_45 * V_15 , struct V_199 * V_200 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_32 , V_202 ;
int V_31 ;
F_8 ( V_2 , 0 ) ;
V_202 = F_84 ( V_15 , V_200 ) ;
if ( V_200 -> V_196 != V_2 -> V_196 )
V_2 -> V_196 = V_200 -> V_196 ;
V_31 = 0 ;
switch ( V_200 -> V_205 ) {
case V_206 :
F_82 ( V_2 , 0 , V_200 -> V_196 ) ;
break;
case V_207 :
F_82 ( V_2 , 1 , V_200 -> V_196 ) ;
goto exit;
case V_208 :
F_3 ( V_4 , 1 ) ;
V_31 = 1 ;
V_202 |= 1 << 11 ;
break;
}
if ( V_2 -> V_66 != V_200 -> V_66 ) {
if ( V_2 -> V_21 -> V_209 != NULL )
V_2 -> V_21 -> V_209 ( F_12 ( V_15 ) , V_2 -> V_23 ,
V_200 -> V_66 ) ;
V_2 -> V_66 = V_200 -> V_66 ;
}
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ )
F_11 ( V_4 , V_19 , V_202 ) ;
V_2 -> V_20 = V_202 ;
if ( V_200 -> V_205 == V_208 ) {
int V_210 = 250 ;
F_11 ( V_4 , V_76 , 0 ) ;
F_11 ( V_4 , V_108 , 0xffff ) ;
F_11 ( V_4 , V_86 , 1 << 7 ) ;
while ( V_210 > 0 && ( F_13 ( V_4 , V_108 ) & 1 ) == 0 ) {
F_37 ( 1 ) ;
V_210 -- ;
}
F_11 ( V_4 , V_108 , 1 ) ;
}
exit:
F_17 ( V_2 , V_31 ) ;
}
static int T_5 F_87 ( struct V_7 * V_4 , int V_23 )
{
struct V_1 * V_2 = NULL ;
struct V_45 * V_15 ;
int V_211 ;
V_15 = F_88 ( sizeof( struct V_1 ) , V_4 -> V_41 ) ;
if ( V_15 == NULL )
return - V_212 ;
V_2 = F_24 ( V_15 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_21 = & V_4 -> V_21 -> V_37 [ V_23 ] ;
V_4 -> V_37 [ V_23 ] = V_2 ;
V_15 -> V_213 = 0 ;
if ( V_4 -> V_21 -> V_37 [ V_23 ] . V_214 >= 4 )
V_15 -> V_213 |= V_215 ;
V_15 -> V_216 = & V_217 ;
V_15 -> V_218 = 400000 ;
if ( F_89 () )
V_15 -> V_219 = 48000000 ;
else
V_15 -> V_219 = 24000000 ;
if ( V_4 -> V_21 -> V_220 )
V_15 -> V_219 = F_90 ( V_4 -> V_21 -> V_220 , V_15 -> V_219 ) ;
V_15 -> V_221 = V_2 -> V_21 -> V_222 ;
V_15 -> V_223 = 32 ;
V_15 -> V_224 = 2048 ;
V_15 -> V_225 = 2048 ;
V_15 -> V_226 = V_15 -> V_224 * V_15 -> V_225 ;
V_15 -> V_227 = V_15 -> V_226 ;
V_211 = F_91 ( V_15 ) ;
if ( V_211 < 0 )
goto V_228;
if ( V_2 -> V_21 -> V_47 != NULL ) {
V_211 = F_92 ( & V_15 -> V_46 ,
& V_229 ) ;
if ( V_211 < 0 )
goto V_228;
}
if ( V_2 -> V_21 -> V_39 != NULL ) {
V_211 = F_92 ( & V_15 -> V_46 ,
& V_230 ) ;
if ( V_211 < 0 )
goto V_231;
F_93 ( & V_2 -> V_155 , F_65 ,
( unsigned long ) V_2 ) ;
F_94 ( & V_2 -> V_152 , F_67 ,
( unsigned long ) V_2 ) ;
F_66 ( & V_2 -> V_152 ) ;
}
return 0 ;
V_231:
if ( V_2 -> V_21 -> V_47 != NULL )
F_95 ( & V_15 -> V_46 , & V_229 ) ;
V_228:
F_96 ( V_15 ) ;
F_97 ( V_15 ) ;
return V_211 ;
}
static void F_98 ( struct V_1 * V_2 )
{
struct V_45 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_21 -> V_47 != NULL )
F_95 ( & V_15 -> V_46 , & V_229 ) ;
if ( V_2 -> V_21 -> V_39 != NULL )
F_95 ( & V_15 -> V_46 , & V_230 ) ;
F_99 ( & V_2 -> V_152 ) ;
F_100 ( & V_2 -> V_155 ) ;
F_101 ( V_2 -> V_4 -> V_38 ) ;
F_96 ( V_15 ) ;
F_97 ( V_15 ) ;
}
static int T_5 F_102 ( struct V_232 * V_233 )
{
struct V_234 * V_21 = V_233 -> V_41 . V_235 ;
struct V_7 * V_4 = NULL ;
struct V_236 * V_237 ;
T_6 V_238 ;
unsigned V_239 ;
int V_32 , V_240 = 0 ;
int V_127 ;
if ( V_21 == NULL ) {
F_28 ( & V_233 -> V_41 , L_34 ) ;
return - V_241 ;
}
if ( V_21 -> V_35 == 0 ) {
F_28 ( & V_233 -> V_41 , L_35 ) ;
return - V_241 ;
}
V_237 = F_103 ( V_233 , V_242 , 0 ) ;
V_127 = F_104 ( V_233 , 0 ) ;
if ( V_237 == NULL || V_127 < 0 )
return - V_241 ;
V_237 = F_105 ( V_237 -> V_243 , F_106 ( V_237 ) ,
V_233 -> V_47 ) ;
if ( V_237 == NULL )
return - V_244 ;
V_4 = F_107 ( sizeof( struct V_7 ) , V_245 ) ;
if ( V_4 == NULL ) {
V_240 = - V_212 ;
goto V_246;
}
F_108 ( & V_4 -> V_26 , F_14 ) ;
F_108 ( & V_4 -> V_99 , F_33 ) ;
F_108 ( & V_4 -> V_125 , F_42 ) ;
F_93 ( & V_4 -> V_71 , F_45 ,
( unsigned long ) V_4 ) ;
F_109 ( & V_4 -> V_10 ) ;
F_93 ( & V_4 -> V_17 , F_49 , ( unsigned long ) V_4 ) ;
F_109 ( & V_4 -> V_111 ) ;
F_109 ( & V_4 -> V_14 ) ;
F_110 ( & V_4 -> V_16 ) ;
V_4 -> V_21 = V_21 ;
V_4 -> V_41 = & V_233 -> V_41 ;
F_111 ( V_233 , V_4 ) ;
V_4 -> V_23 = V_233 -> V_23 ;
V_4 -> V_247 = V_237 ;
V_4 -> V_127 = V_127 ;
V_4 -> V_167 = 1 ;
V_4 -> V_127 = V_127 ;
V_4 -> V_182 = V_4 -> V_247 -> V_243 ;
V_4 -> V_137 = F_112 ( V_237 -> V_243 , F_106 ( V_237 ) ) ;
if ( ! V_4 -> V_137 )
goto V_248;
V_4 -> V_249 = F_113 ( & V_233 -> V_41 , L_36 ) ;
if ( F_114 ( V_4 -> V_249 ) ) {
V_240 = F_115 ( V_4 -> V_249 ) ;
goto V_250;
}
F_5 ( V_4 -> V_249 ) ;
V_4 -> V_11 = F_113 ( & V_233 -> V_41 , L_37 ) ;
if ( F_114 ( V_4 -> V_11 ) ) {
V_240 = F_115 ( V_4 -> V_11 ) ;
goto V_251;
}
F_116 ( V_238 ) ;
F_117 ( V_252 , V_238 ) ;
V_4 -> V_176 = - 1 ;
V_4 -> V_177 = - 1 ;
if ( F_83 () )
V_239 = V_4 -> V_23 == 0 ? V_253 : V_254 ;
else
V_239 = V_4 -> V_23 == 0 ? V_255 : V_256 ;
V_4 -> V_93 = F_118 ( V_238 , V_257 , & V_239 ) ;
#if 0
if (!host->dma_tx) {
dev_err(host->dev, "unable to obtain TX DMA engine channel %u\n",
sig);
goto err_dma;
}
#else
if ( ! V_4 -> V_93 )
F_119 ( V_4 -> V_41 , L_38 ,
V_239 ) ;
#endif
if ( F_83 () )
V_239 = V_4 -> V_23 == 0 ? V_258 : V_259 ;
else
V_239 = V_4 -> V_23 == 0 ? V_260 : V_261 ;
V_4 -> V_95 = F_118 ( V_238 , V_257 , & V_239 ) ;
#if 0
if (!host->dma_rx) {
dev_err(host->dev, "unable to obtain RX DMA engine channel %u\n",
sig);
goto err_dma;
}
#else
if ( ! V_4 -> V_95 )
F_119 ( V_4 -> V_41 , L_39 ,
V_239 ) ;
#endif
V_240 = F_120 ( V_4 -> V_127 , F_57 , 0 , V_262 , V_4 ) ;
if ( V_240 )
goto V_263;
if ( V_21 -> V_264 != NULL ) {
V_240 = V_21 -> V_264 ( & V_233 -> V_41 ) ;
if ( V_240 < 0 )
goto V_265;
}
V_4 -> V_35 = V_21 -> V_35 ;
V_4 -> V_266 = ( F_121 () ? 1 : 2 ) ;
V_4 -> V_38 = F_122 ( L_40 , 0 , 0 ) ;
if ( ! V_4 -> V_38 )
goto V_267;
for ( V_32 = 0 ; V_32 < V_21 -> V_35 ; V_32 ++ ) {
V_240 = F_87 ( V_4 , V_32 ) ;
if ( V_240 < 0 ) {
while ( -- V_32 >= 0 )
F_98 ( V_4 -> V_37 [ V_32 ] ) ;
goto V_268;
}
}
return 0 ;
V_268:
F_123 ( V_4 -> V_38 ) ;
V_267:
if ( V_21 -> V_269 )
V_21 -> V_269 ( & V_233 -> V_41 ) ;
V_265:
F_124 ( V_4 -> V_127 , V_4 ) ;
V_263:
if ( V_4 -> V_93 )
F_125 ( V_4 -> V_93 ) ;
if ( V_4 -> V_95 )
F_125 ( V_4 -> V_95 ) ;
F_126 ( V_4 -> V_11 ) ;
V_251:
F_6 ( V_4 -> V_249 ) ;
F_126 ( V_4 -> V_249 ) ;
V_250:
F_127 ( V_4 -> V_137 ) ;
V_248:
F_128 ( V_4 ) ;
V_246:
F_129 ( V_237 -> V_243 , F_106 ( V_237 ) ) ;
return V_240 ;
}
static int T_7 F_130 ( struct V_232 * V_233 )
{
struct V_7 * V_4 = F_131 ( V_233 ) ;
int V_32 ;
F_111 ( V_233 , NULL ) ;
F_18 ( V_4 == NULL ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ )
F_98 ( V_4 -> V_37 [ V_32 ] ) ;
if ( V_4 -> V_21 -> V_269 )
V_4 -> V_21 -> V_269 ( & V_233 -> V_41 ) ;
F_3 ( V_4 , 0 ) ;
F_124 ( V_4 -> V_127 , V_4 ) ;
F_126 ( V_4 -> V_11 ) ;
F_6 ( V_4 -> V_249 ) ;
F_126 ( V_4 -> V_249 ) ;
if ( V_4 -> V_93 )
F_125 ( V_4 -> V_93 ) ;
if ( V_4 -> V_95 )
F_125 ( V_4 -> V_95 ) ;
F_127 ( V_4 -> V_137 ) ;
F_129 ( V_233 -> V_236 [ 0 ] . V_243 ,
V_233 -> V_236 [ 0 ] . V_270 - V_233 -> V_236 [ 0 ] . V_243 + 1 ) ;
F_123 ( V_4 -> V_38 ) ;
F_128 ( V_4 ) ;
return 0 ;
}
static int F_132 ( struct V_232 * V_233 , T_8 V_271 )
{
int V_32 , V_240 = 0 ;
struct V_7 * V_4 = F_131 ( V_233 ) ;
if ( V_4 == NULL || V_4 -> V_272 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
struct V_1 * V_2 ;
V_2 = V_4 -> V_37 [ V_32 ] ;
V_240 = F_133 ( V_2 -> V_15 ) ;
if ( V_240 < 0 ) {
while ( -- V_32 >= 0 ) {
V_2 = V_4 -> V_37 [ V_32 ] ;
F_134 ( V_2 -> V_15 ) ;
}
return V_240 ;
}
}
V_4 -> V_272 = 1 ;
return 0 ;
}
static int F_135 ( struct V_232 * V_233 )
{
int V_32 , V_240 = 0 ;
struct V_7 * V_4 = F_131 ( V_233 ) ;
if ( V_4 == NULL || ! V_4 -> V_272 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
struct V_1 * V_2 ;
V_2 = V_4 -> V_37 [ V_32 ] ;
V_240 = F_134 ( V_2 -> V_15 ) ;
if ( V_240 < 0 )
return V_240 ;
V_4 -> V_272 = 0 ;
}
return 0 ;
}
