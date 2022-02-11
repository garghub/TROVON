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
F_20 ( V_38 , & V_4 -> V_26 ) ;
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
F_18 ( V_4 -> V_90 < 0 ) ;
if ( V_69 -> error )
F_31 ( V_4 -> V_90 ) ;
F_19 ( & V_4 -> V_91 , V_33 + V_34 ) ;
if ( V_69 -> V_9 & V_70 )
V_89 = V_92 ;
else
V_89 = V_93 ;
F_32 ( F_12 ( V_4 -> V_15 ) , V_69 -> V_94 , V_4 -> V_95 ,
V_89 ) ;
}
static void F_33 ( struct V_24 * V_25 )
{
struct V_7 * V_4 = F_15 ( V_25 , struct V_7 ,
V_96 ) ;
struct V_1 * V_2 = V_4 -> V_18 ;
struct V_87 * V_69 = V_4 -> V_97 ;
unsigned long V_3 ;
V_3 = ( 1000000000 + V_2 -> V_6 - 1 ) / V_2 -> V_6 ;
F_2 ( 8 * V_3 ) ;
F_26 ( V_4 , V_69 -> V_98 ) ;
}
static void
F_34 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
if ( V_4 -> V_99 )
F_30 ( V_4 , V_69 , V_69 -> error ) ;
V_4 -> V_69 = NULL ;
V_4 -> V_95 = 0 ;
if ( ! V_69 -> V_98 ) {
struct V_45 * V_15 ;
V_4 -> V_30 = NULL ;
V_15 = V_4 -> V_15 ;
F_17 ( V_4 -> V_18 , 1 ) ;
F_35 ( V_15 , V_69 -> V_30 ) ;
return;
}
V_4 -> V_97 = V_69 ;
F_20 ( V_38 , & V_4 -> V_96 ) ;
}
static void
F_36 ( struct V_7 * V_4 , int V_100 )
{
struct V_1 * V_2 = V_4 -> V_18 ;
unsigned int V_101 , V_102 , V_103 ;
T_3 V_104 = 0 ;
V_103 = ( 120 * 1000000 + V_2 -> V_6 - 1 ) / V_2 -> V_6 ;
V_101 = 0 ;
while ( V_101 < V_100 ) {
F_11 ( V_4 , V_105 , 0xFFFF ) ;
F_11 ( V_4 , V_86 , ( 3 << 12 ) | ( 1 << 7 ) ) ;
V_102 = 0 ;
while ( V_102 < V_103 ) {
V_104 = F_13 ( V_4 , V_105 ) ;
if ( V_104 & V_83 )
goto V_106;
F_37 ( 1 ) ;
V_102 ++ ;
}
V_101 ++ ;
}
V_106:
F_11 ( V_4 , V_105 , V_104 ) ;
}
static void
F_38 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
if ( V_4 -> V_99 )
F_30 ( V_4 , V_69 , 1 ) ;
V_4 -> V_69 = NULL ;
V_4 -> V_95 = 0 ;
F_36 ( V_4 , 10000 ) ;
}
static void
F_39 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
unsigned long V_9 ;
int V_107 ;
if ( ! V_4 -> V_99 ) {
F_34 ( V_4 , V_69 ) ;
return;
}
V_107 = 0 ;
F_4 ( & V_4 -> V_108 , V_9 ) ;
if ( V_4 -> V_109 )
V_107 = 1 ;
else
V_4 -> V_110 = 1 ;
F_7 ( & V_4 -> V_108 , V_9 ) ;
if ( V_107 )
F_34 ( V_4 , V_69 ) ;
}
static void
F_40 ( unsigned long V_69 )
{
struct V_7 * V_4 = (struct V_7 * ) V_69 ;
F_18 ( V_4 -> V_90 < 0 ) ;
F_41 ( V_4 -> V_90 ) ;
V_4 -> V_90 = - 1 ;
}
static void
F_42 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
unsigned long V_9 ;
int V_107 ;
V_107 = 0 ;
F_4 ( & V_4 -> V_108 , V_9 ) ;
if ( V_4 -> V_110 )
V_107 = 1 ;
else
V_4 -> V_109 = 1 ;
F_7 ( & V_4 -> V_108 , V_9 ) ;
if ( V_107 )
F_34 ( V_4 , V_69 ) ;
}
static void
F_43 ( struct V_7 * V_4 , struct V_48 * V_49 )
{
V_4 -> V_49 = NULL ;
F_10 ( & V_4 -> V_71 ) ;
if ( V_49 -> V_9 & V_111 ) {
if ( V_49 -> V_9 & V_112 ) {
V_49 -> V_113 [ 3 ] =
F_13 ( V_4 , V_114 ) |
( F_13 ( V_4 , V_115 ) << 16 ) ;
V_49 -> V_113 [ 2 ] =
F_13 ( V_4 , V_116 ) |
( F_13 ( V_4 , V_117 ) << 16 ) ;
V_49 -> V_113 [ 1 ] =
F_13 ( V_4 , V_118 ) |
( F_13 ( V_4 , V_119 ) << 16 ) ;
V_49 -> V_113 [ 0 ] =
F_13 ( V_4 , V_120 ) |
( F_13 ( V_4 , V_121 ) << 16 ) ;
} else {
V_49 -> V_113 [ 0 ] =
F_13 ( V_4 , V_120 ) |
( F_13 ( V_4 , V_121 ) << 16 ) ;
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
static void F_44 ( struct V_24 * V_25 )
{
struct V_7 * V_4 = F_15 ( V_25 , struct V_7 ,
V_122 ) ;
F_18 ( ! V_4 -> V_49 ) ;
F_45 ( F_12 ( V_4 -> V_15 ) , L_5 ,
V_4 -> V_49 -> V_65 ) ;
if ( V_4 -> V_49 -> error == 0 )
V_4 -> V_49 -> error = - V_123 ;
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
F_43 ( V_4 , V_4 -> V_49 ) ;
V_4 -> abort = 0 ;
F_46 ( V_4 -> V_124 ) ;
}
static void
F_47 ( unsigned long V_69 )
{
struct V_7 * V_4 = (struct V_7 * ) V_69 ;
unsigned long V_9 ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
if ( V_4 -> V_49 != NULL && ! V_4 -> abort ) {
F_11 ( V_4 , V_76 , 0 ) ;
F_48 ( V_4 -> V_124 ) ;
V_4 -> abort = 1 ;
F_20 ( V_38 , & V_4 -> V_122 ) ;
}
F_7 ( & V_4 -> V_14 , V_9 ) ;
}
static void
F_49 ( struct V_7 * V_4 )
{
struct V_125 * V_94 ;
V_94 = V_4 -> V_69 -> V_94 + V_4 -> V_126 ;
V_4 -> V_127 = V_94 -> V_128 ;
V_4 -> V_129 = F_50 ( V_94 ) ;
if ( V_4 -> V_127 > V_4 -> V_130 )
V_4 -> V_127 = V_4 -> V_130 ;
}
static void
F_51 ( unsigned long V_69 )
{
struct V_7 * V_4 = (struct V_7 * ) V_69 ;
F_3 ( V_4 , 0 ) ;
}
static void
F_52 ( struct V_7 * V_4 , int V_131 )
{
int V_132 ;
if ( V_4 -> V_127 == 0 ) {
V_4 -> V_126 ++ ;
F_18 ( V_4 -> V_126 == V_4 -> V_95 ) ;
F_49 ( V_4 ) ;
}
V_132 = 64 ;
if ( V_132 > V_4 -> V_127 )
V_132 = V_4 -> V_127 ;
V_4 -> V_127 -= V_132 ;
V_4 -> V_130 -= V_132 ;
V_4 -> V_69 -> V_133 += V_132 ;
if ( V_131 ) {
F_53 ( V_4 -> V_134 + F_54 ( V_4 , V_135 ) , V_4 -> V_129 , V_132 ) ;
} else {
F_55 ( V_4 -> V_134 + F_54 ( V_4 , V_135 ) , V_4 -> V_129 , V_132 ) ;
}
}
static inline void F_56 ( T_3 V_136 )
{
static const char * V_137 [] = {
L_6 , L_7 , L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
int V_32 , V_138 = 0 ;
for ( V_32 = 0 ; V_32 < F_57 ( V_137 ) ; V_32 ++ )
if ( V_136 & ( 1 << V_32 ) ) {
if ( V_138 )
F_58 ( L_21 ) ;
F_58 ( L_22 , V_137 [ V_32 ] ) ;
V_138 ++ ;
}
}
static T_4 F_59 ( int V_124 , void * V_139 )
{
struct V_7 * V_4 = (struct V_7 * ) V_139 ;
T_3 V_136 ;
int V_140 ;
int V_141 ;
int V_142 , V_143 ;
if ( V_4 -> V_49 == NULL && V_4 -> V_69 == NULL ) {
V_136 = F_13 ( V_4 , V_105 ) ;
F_60 ( F_12 ( V_4 -> V_37 [ 0 ] -> V_15 ) ,
L_23 , V_136 ) ;
if ( V_136 != 0 ) {
F_11 ( V_4 , V_105 , V_136 ) ;
F_11 ( V_4 , V_76 , 0 ) ;
}
return V_144 ;
}
V_140 = 0 ;
V_141 = 0 ;
V_142 = 0 ;
V_143 = 0 ;
while ( ( V_136 = F_13 ( V_4 , V_105 ) ) != 0 ) {
int V_49 ;
F_11 ( V_4 , V_105 , V_136 ) ;
if ( V_4 -> V_49 != NULL )
V_49 = V_4 -> V_49 -> V_65 ;
else
V_49 = - 1 ;
#ifdef F_61
F_45 ( F_12 ( V_4 -> V_15 ) , L_24 ,
V_136 , V_49 ) ;
F_56 ( V_136 ) ;
F_58 ( L_25 ) ;
#endif
if ( V_4 -> V_130 ) {
if ( ( V_136 & V_78 ) ||
( V_136 & V_85 ) )
F_52 ( V_4 , 0 ) ;
if ( V_136 & V_77 )
F_52 ( V_4 , 1 ) ;
}
if ( V_136 & V_85 )
V_141 = 1 ;
if ( V_136 & V_82 ) {
F_45 ( F_12 ( V_4 -> V_15 ) , L_26 ,
V_49 ) ;
if ( V_4 -> V_69 ) {
V_4 -> V_69 -> error = - V_123 ;
V_142 = 1 ;
}
}
if ( V_136 & V_81 ) {
if ( V_4 -> V_69 ) {
V_4 -> V_69 -> error = - V_145 ;
F_45 ( F_12 ( V_4 -> V_15 ) ,
L_27 ,
V_4 -> V_130 ) ;
V_142 = 1 ;
} else {
F_45 ( F_12 ( V_4 -> V_15 ) , L_28 ) ;
}
}
if ( V_136 & V_80 ) {
if ( V_4 -> V_49 ) {
struct V_1 * V_2 =
V_4 -> V_18 ;
if ( V_2 == NULL ||
! F_22 ( V_2 ) )
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_29 ,
V_49 ) ;
V_4 -> V_49 -> error = - V_123 ;
V_140 = 1 ;
V_143 = 1 ;
}
}
if ( V_136 & V_79 ) {
if ( V_4 -> V_49 ) {
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_30 ,
V_49 , V_4 -> V_49 -> V_74 ) ;
V_4 -> V_49 -> error = - V_145 ;
V_140 = 1 ;
V_143 = 1 ;
} else
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_31 ) ;
}
if ( V_136 & V_84 ) {
F_45 ( F_12 ( V_4 -> V_15 ) ,
L_32 ,
V_49 ) ;
V_140 = 1 ;
}
if ( ( V_136 & V_83 ) &&
( ! ( V_136 & V_77 ) ) ) {
V_140 = 1 ;
}
}
if ( V_143 && V_4 -> V_69 ) {
F_10 ( & V_4 -> V_71 ) ;
V_4 -> abort = 1 ;
F_11 ( V_4 , V_76 , 0 ) ;
F_62 ( V_4 -> V_124 ) ;
F_20 ( V_38 , & V_4 -> V_122 ) ;
return V_144 ;
}
if ( V_140 && V_4 -> V_49 )
F_43 ( V_4 , V_4 -> V_49 ) ;
if ( V_4 -> V_69 != NULL ) {
if ( V_142 )
F_34 ( V_4 , V_4 -> V_69 ) ;
else if ( V_141 )
F_39 ( V_4 , V_4 -> V_69 ) ;
}
return V_144 ;
}
void F_63 ( struct V_40 * V_41 , int V_146 , int V_147 )
{
int V_148 ;
struct V_7 * V_4 = F_64 ( V_41 ) ;
struct V_1 * V_2 = V_4 -> V_37 [ V_146 ] ;
F_18 ( V_146 >= V_4 -> V_35 ) ;
if ( V_4 -> V_35 == 0 || ! V_4 -> V_37 [ V_146 ] )
return;
V_148 = F_22 ( V_2 ) ;
if ( V_148 != V_2 -> V_148 ) {
V_2 -> V_148 = V_148 ;
F_65 ( & V_2 -> V_15 -> V_46 . V_149 , NULL , L_33 ) ;
}
F_66 ( & V_2 -> V_150 ) ;
}
static void F_67 ( unsigned long V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_68 ( & V_2 -> V_150 ) ;
}
static void F_69 ( unsigned long V_151 )
{
struct V_1 * V_2 = (struct V_1 * ) V_151 ;
int V_148 = F_22 ( V_2 ) ;
F_70 ( V_2 -> V_15 , 0 ) ;
if ( ! V_148 )
return;
if ( V_2 -> V_15 -> V_152 == NULL || ! F_71 ( V_2 -> V_15 -> V_152 ) )
return;
F_19 ( & V_2 -> V_153 ,
V_33 + F_72 ( V_154 ) ) ;
}
static void
F_73 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
int V_90 = V_4 -> V_90 ;
unsigned long V_155 ;
T_3 V_44 , V_156 ;
T_2 V_157 ;
struct V_125 * V_94 = & V_69 -> V_94 [ V_4 -> V_126 ] ;
int V_158 = 0 ;
int V_159 = 0 ;
int V_160 = 0 ;
V_155 = V_4 -> V_161 + F_54 ( V_4 , V_135 ) ;
V_156 = V_69 -> V_162 ;
V_157 = F_74 ( V_94 ) ;
if ( ( V_69 -> V_163 == 1 ) && ( V_157 > V_69 -> V_162 ) )
V_157 = V_156 ;
V_4 -> V_164 = V_157 ;
if ( F_75 () && V_156 > 32 )
V_156 = 32 ;
else if ( V_156 > 64 )
V_156 = 64 ;
V_157 /= V_156 ;
V_156 >>= 1 ;
if ( ! ( V_69 -> V_9 & V_70 ) ) {
V_44 = 0x800f | ( ( V_156 - 1 ) << 8 ) ;
if ( F_76 () ) {
V_158 = V_165 ;
V_159 = V_166 ;
}
if ( F_77 () )
V_160 = V_167 ;
F_78 ( V_90 , V_158 ,
V_168 ,
V_155 , 0 , 0 ) ;
F_79 ( V_90 , V_159 ,
V_169 ,
F_80 ( V_94 ) , 0 , 0 ) ;
F_81 ( V_90 , 1 ) ;
F_82 ( V_90 , V_170 ) ;
} else {
V_44 = 0x0f80 | ( ( V_156 - 1 ) << 0 ) ;
if ( F_76 () ) {
V_158 = V_166 ;
V_159 = V_165 ;
}
if ( F_77 () )
V_160 = V_171 ;
F_79 ( V_90 , V_159 ,
V_168 ,
V_155 , 0 , 0 ) ;
F_78 ( V_90 , V_158 ,
V_169 ,
F_80 ( V_94 ) , 0 , 0 ) ;
F_83 ( V_90 , 1 ) ;
F_84 ( V_90 , V_170 ) ;
}
F_18 ( V_157 > 0xffff ) ;
F_11 ( V_4 , V_172 , V_44 ) ;
F_85 ( V_90 , V_173 ,
V_156 , V_157 , V_174 ,
V_160 , 0 ) ;
}
static void F_86 ( int V_175 , T_3 V_176 , void * V_69 )
{
struct V_7 * V_4 = (struct V_7 * ) V_69 ;
struct V_87 * V_177 = V_4 -> V_69 ;
if ( F_87 ( V_4 -> V_90 < 0 ) ) {
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_34 ) ;
return;
}
if ( V_176 & V_178 ) {
F_28 ( F_12 ( V_4 -> V_15 ) , L_35 ) ;
return;
}
if ( V_176 & V_179 ) {
F_28 ( F_12 ( V_4 -> V_15 ) , L_36 ) ;
return;
}
if ( ! ( V_176 & V_180 ) ) {
return;
}
V_177 -> V_133 += V_4 -> V_164 ;
V_4 -> V_126 ++ ;
if ( V_4 -> V_126 < V_4 -> V_95 ) {
F_73 ( V_4 , V_4 -> V_69 ) ;
F_88 ( V_4 -> V_90 ) ;
} else
F_42 ( V_4 , V_4 -> V_69 ) ;
}
static int F_89 ( struct V_7 * V_4 , struct V_87 * V_69 )
{
const char * V_181 ;
int V_160 , V_90 , V_182 , V_183 ;
V_182 = ! ( V_69 -> V_9 & V_70 ) ;
F_90 ( & V_4 -> V_91 ) ;
if ( V_4 -> V_90 >= 0 ) {
if ( V_182 == V_4 -> V_184 )
return 0 ;
F_41 ( V_4 -> V_90 ) ;
V_4 -> V_90 = - 1 ;
}
if ( V_182 ) {
if ( V_4 -> V_23 == 0 ) {
V_160 = V_185 ;
V_181 = L_37 ;
} else {
V_160 = V_186 ;
V_181 = L_38 ;
}
} else {
if ( V_4 -> V_23 == 0 ) {
V_160 = V_187 ;
V_181 = L_39 ;
} else {
V_160 = V_188 ;
V_181 = L_40 ;
}
}
V_183 = F_91 ( V_160 , V_181 , F_86 ,
V_4 , & V_90 ) ;
if ( V_183 != 0 ) {
F_45 ( F_12 ( V_4 -> V_15 ) , L_41 , V_183 ) ;
return V_183 ;
}
V_4 -> V_90 = V_90 ;
V_4 -> V_184 = V_182 ;
return 0 ;
}
static inline void F_92 ( struct V_7 * V_4 , struct V_28 * V_189 )
{
T_3 V_190 ;
V_190 = F_13 ( V_4 , V_191 ) ;
V_190 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_191 , V_190 ) ;
F_11 ( V_4 , V_72 , 0xff ) ;
}
static inline void F_93 ( struct V_7 * V_4 , struct V_28 * V_189 )
{
unsigned int V_103 , V_192 ;
T_3 V_190 ;
V_192 = 1000000000 / V_4 -> V_18 -> V_6 ;
V_103 = V_189 -> V_69 -> V_193 / V_192 ;
V_103 += V_189 -> V_69 -> V_194 ;
V_190 = F_13 ( V_4 , V_191 ) ;
if ( V_103 > 0xffff ) {
V_190 |= ( 1 << 5 ) ;
V_103 /= 1024 ;
} else
V_190 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_191 , V_190 ) ;
F_11 ( V_4 , V_195 , V_103 ) ;
}
static void
F_94 ( struct V_7 * V_4 , struct V_28 * V_189 )
{
struct V_87 * V_69 = V_189 -> V_69 ;
int V_32 , V_196 , V_197 ;
unsigned V_95 ;
V_4 -> V_69 = V_69 ;
if ( V_69 == NULL ) {
F_11 ( V_4 , V_198 , 0 ) ;
F_11 ( V_4 , V_199 , 0 ) ;
F_11 ( V_4 , V_172 , 0 ) ;
V_4 -> V_99 = 0 ;
F_92 ( V_4 , V_189 ) ;
return;
}
V_197 = V_69 -> V_162 ;
F_11 ( V_4 , V_199 , V_69 -> V_163 - 1 ) ;
F_11 ( V_4 , V_198 , V_197 - 1 ) ;
F_93 ( V_4 , V_189 ) ;
V_95 = ( V_69 -> V_163 == 1 ) ? 1 : V_69 -> V_95 ;
V_196 = V_4 -> V_196 ;
if ( V_196 ) {
for ( V_32 = 0 ; V_32 < V_95 ; V_32 ++ ) {
if ( ( V_69 -> V_94 [ V_32 ] . V_128 % V_197 ) != 0 ) {
V_196 = 0 ;
break;
}
}
}
V_4 -> V_126 = 0 ;
if ( V_196 ) {
if ( F_89 ( V_4 , V_69 ) == 0 ) {
enum V_88 V_89 ;
if ( V_69 -> V_9 & V_70 )
V_89 = V_92 ;
else
V_89 = V_93 ;
V_4 -> V_95 = F_95 ( F_12 ( V_4 -> V_15 ) , V_69 -> V_94 ,
V_95 , V_89 ) ;
V_4 -> V_130 = 0 ;
F_73 ( V_4 , V_189 -> V_69 ) ;
V_4 -> V_110 = 0 ;
V_4 -> V_109 = 0 ;
V_4 -> V_99 = 1 ;
} else
V_196 = 0 ;
}
if ( ! V_196 ) {
F_11 ( V_4 , V_172 , 0x1f1f ) ;
V_4 -> V_130 = V_69 -> V_163 * V_197 ;
V_4 -> V_95 = V_95 ;
F_49 ( V_4 ) ;
V_4 -> V_99 = 0 ;
}
}
static void F_16 ( struct V_7 * V_4 ,
struct V_28 * V_189 )
{
F_18 ( V_4 -> V_30 != NULL ) ;
V_4 -> V_30 = V_189 ;
F_94 ( V_4 , V_189 ) ;
F_26 ( V_4 , V_189 -> V_49 ) ;
if ( V_4 -> V_99 )
F_88 ( V_4 -> V_90 ) ;
}
static void F_96 ( struct V_45 * V_15 , struct V_28 * V_189 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned long V_9 ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
if ( V_4 -> V_15 != NULL ) {
F_18 ( V_2 -> V_30 != NULL ) ;
V_2 -> V_30 = V_189 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
return;
} else
V_4 -> V_15 = V_15 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
F_8 ( V_2 , 1 ) ;
F_16 ( V_4 , V_189 ) ;
}
static void F_97 ( struct V_1 * V_2 , int V_200 ,
int V_201 )
{
struct V_7 * V_4 ;
V_4 = V_2 -> V_4 ;
if ( V_2 -> V_21 -> V_202 != NULL )
V_2 -> V_21 -> V_202 ( F_12 ( V_2 -> V_15 ) , V_2 -> V_23 , V_200 ,
V_201 ) ;
if ( F_77 () ) {
T_3 V_203 ;
if ( V_200 ) {
V_203 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_203 | ( 1 << 11 ) ) ;
} else {
V_203 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_203 & ~ ( 1 << 11 ) ) ;
}
}
}
static int F_98 ( struct V_45 * V_15 , struct V_204 * V_205 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_206 = F_99 ( V_4 -> V_11 ) ;
int V_207 ;
if ( V_205 -> clock == 0 )
return 0 ;
V_207 = V_206 / V_205 -> clock ;
if ( V_207 < 1 )
V_207 = 1 ;
if ( V_206 / V_207 > V_205 -> clock )
V_207 ++ ;
if ( V_207 > 250 )
V_207 = 250 ;
V_2 -> V_6 = V_206 / V_207 ;
if ( V_205 -> V_208 == V_209 )
V_207 |= 1 << 15 ;
return V_207 ;
}
static void F_100 ( struct V_45 * V_15 , struct V_204 * V_205 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_32 , V_207 ;
int V_31 ;
F_8 ( V_2 , 0 ) ;
V_207 = F_98 ( V_15 , V_205 ) ;
if ( V_205 -> V_201 != V_2 -> V_201 )
V_2 -> V_201 = V_205 -> V_201 ;
V_31 = 0 ;
switch ( V_205 -> V_210 ) {
case V_211 :
F_97 ( V_2 , 0 , V_205 -> V_201 ) ;
break;
case V_212 :
F_97 ( V_2 , 1 , V_205 -> V_201 ) ;
goto exit;
case V_213 :
F_3 ( V_4 , 1 ) ;
V_31 = 1 ;
V_207 |= 1 << 11 ;
break;
}
if ( V_2 -> V_66 != V_205 -> V_66 ) {
if ( V_2 -> V_21 -> V_214 != NULL )
V_2 -> V_21 -> V_214 ( F_12 ( V_15 ) , V_2 -> V_23 ,
V_205 -> V_66 ) ;
V_2 -> V_66 = V_205 -> V_66 ;
}
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ )
F_11 ( V_4 , V_19 , V_207 ) ;
V_2 -> V_20 = V_207 ;
if ( V_205 -> V_210 == V_213 ) {
int V_215 = 250 ;
F_11 ( V_4 , V_76 , 0 ) ;
F_11 ( V_4 , V_105 , 0xffff ) ;
F_11 ( V_4 , V_86 , 1 << 7 ) ;
while ( V_215 > 0 && ( F_13 ( V_4 , V_105 ) & 1 ) == 0 ) {
F_37 ( 1 ) ;
V_215 -- ;
}
F_11 ( V_4 , V_105 , 1 ) ;
}
exit:
F_17 ( V_2 , V_31 ) ;
}
static int T_5 F_101 ( struct V_7 * V_4 , int V_23 )
{
struct V_1 * V_2 = NULL ;
struct V_45 * V_15 ;
int V_183 ;
V_15 = F_102 ( sizeof( struct V_1 ) , V_4 -> V_41 ) ;
if ( V_15 == NULL )
return - V_216 ;
V_2 = F_24 ( V_15 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_21 = & V_4 -> V_21 -> V_37 [ V_23 ] ;
V_4 -> V_37 [ V_23 ] = V_2 ;
V_15 -> V_217 = 0 ;
if ( V_4 -> V_21 -> V_37 [ V_23 ] . V_218 >= 4 )
V_15 -> V_217 |= V_219 ;
V_15 -> V_220 = & V_221 ;
V_15 -> V_222 = 400000 ;
if ( F_103 () )
V_15 -> V_223 = 48000000 ;
else
V_15 -> V_223 = 24000000 ;
if ( V_4 -> V_21 -> V_224 )
V_15 -> V_223 = F_104 ( V_4 -> V_21 -> V_224 , V_15 -> V_223 ) ;
V_15 -> V_225 = V_2 -> V_21 -> V_226 ;
V_15 -> V_227 = 32 ;
V_15 -> V_228 = 2048 ;
V_15 -> V_229 = 2048 ;
V_15 -> V_230 = V_15 -> V_228 * V_15 -> V_229 ;
V_15 -> V_231 = V_15 -> V_230 ;
V_183 = F_105 ( V_15 ) ;
if ( V_183 < 0 )
goto V_232;
if ( V_2 -> V_21 -> V_47 != NULL ) {
V_183 = F_106 ( & V_15 -> V_46 ,
& V_233 ) ;
if ( V_183 < 0 )
goto V_232;
}
if ( V_2 -> V_21 -> V_39 != NULL ) {
V_183 = F_106 ( & V_15 -> V_46 ,
& V_234 ) ;
if ( V_183 < 0 )
goto V_235;
F_107 ( & V_2 -> V_153 , F_67 ,
( unsigned long ) V_2 ) ;
F_108 ( & V_2 -> V_150 , F_69 ,
( unsigned long ) V_2 ) ;
F_68 ( & V_2 -> V_150 ) ;
}
return 0 ;
V_235:
if ( V_2 -> V_21 -> V_47 != NULL )
F_109 ( & V_15 -> V_46 , & V_233 ) ;
V_232:
F_110 ( V_15 ) ;
F_111 ( V_15 ) ;
return V_183 ;
}
static void F_112 ( struct V_1 * V_2 )
{
struct V_45 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_21 -> V_47 != NULL )
F_109 ( & V_15 -> V_46 , & V_233 ) ;
if ( V_2 -> V_21 -> V_39 != NULL )
F_109 ( & V_15 -> V_46 , & V_234 ) ;
F_113 ( & V_2 -> V_150 ) ;
F_90 ( & V_2 -> V_153 ) ;
F_114 ( V_38 ) ;
F_110 ( V_15 ) ;
F_111 ( V_15 ) ;
}
static int T_5 F_115 ( struct V_236 * V_237 )
{
struct V_238 * V_21 = V_237 -> V_41 . V_239 ;
struct V_7 * V_4 = NULL ;
struct V_240 * V_241 ;
int V_32 , V_242 = 0 ;
int V_124 ;
if ( V_21 == NULL ) {
F_28 ( & V_237 -> V_41 , L_42 ) ;
return - V_243 ;
}
if ( V_21 -> V_35 == 0 ) {
F_28 ( & V_237 -> V_41 , L_43 ) ;
return - V_243 ;
}
V_241 = F_116 ( V_237 , V_244 , 0 ) ;
V_124 = F_117 ( V_237 , 0 ) ;
if ( V_241 == NULL || V_124 < 0 )
return - V_243 ;
V_241 = F_118 ( V_241 -> V_245 , F_119 ( V_241 ) ,
V_237 -> V_47 ) ;
if ( V_241 == NULL )
return - V_246 ;
V_4 = F_120 ( sizeof( struct V_7 ) , V_247 ) ;
if ( V_4 == NULL ) {
V_242 = - V_216 ;
goto V_248;
}
F_121 ( & V_4 -> V_26 , F_14 ) ;
F_121 ( & V_4 -> V_96 , F_33 ) ;
F_121 ( & V_4 -> V_122 , F_44 ) ;
F_107 ( & V_4 -> V_71 , F_47 ,
( unsigned long ) V_4 ) ;
F_122 ( & V_4 -> V_10 ) ;
F_107 ( & V_4 -> V_17 , F_51 , ( unsigned long ) V_4 ) ;
F_122 ( & V_4 -> V_108 ) ;
F_107 ( & V_4 -> V_91 , F_40 , ( unsigned long ) V_4 ) ;
F_122 ( & V_4 -> V_14 ) ;
F_123 ( & V_4 -> V_16 ) ;
V_4 -> V_21 = V_21 ;
V_4 -> V_41 = & V_237 -> V_41 ;
F_124 ( V_237 , V_4 ) ;
V_4 -> V_23 = V_237 -> V_23 ;
V_4 -> V_249 = V_241 ;
V_4 -> V_124 = V_124 ;
V_4 -> V_196 = 1 ;
V_4 -> V_41 -> V_250 = & V_21 -> V_250 ;
V_4 -> V_90 = - 1 ;
V_4 -> V_124 = V_124 ;
V_4 -> V_161 = V_4 -> V_249 -> V_245 ;
V_4 -> V_134 = F_125 ( V_241 -> V_245 , F_119 ( V_241 ) ) ;
if ( ! V_4 -> V_134 )
goto V_251;
V_4 -> V_252 = F_126 ( & V_237 -> V_41 , L_44 ) ;
if ( F_127 ( V_4 -> V_252 ) ) {
V_242 = F_128 ( V_4 -> V_252 ) ;
goto V_253;
}
F_5 ( V_4 -> V_252 ) ;
V_4 -> V_11 = F_126 ( & V_237 -> V_41 , L_45 ) ;
if ( F_127 ( V_4 -> V_11 ) ) {
V_242 = F_128 ( V_4 -> V_11 ) ;
goto V_254;
}
V_242 = F_129 ( V_4 -> V_124 , F_59 , 0 , V_255 , V_4 ) ;
if ( V_242 )
goto V_256;
if ( V_21 -> V_257 != NULL ) {
V_242 = V_21 -> V_257 ( & V_237 -> V_41 ) ;
if ( V_242 < 0 )
goto V_258;
}
V_4 -> V_35 = V_21 -> V_35 ;
for ( V_32 = 0 ; V_32 < V_21 -> V_35 ; V_32 ++ ) {
V_242 = F_101 ( V_4 , V_32 ) ;
if ( V_242 < 0 ) {
while ( -- V_32 >= 0 )
F_112 ( V_4 -> V_37 [ V_32 ] ) ;
goto V_259;
}
}
V_4 -> V_260 = ( F_130 () ? 1 : 2 ) ;
return 0 ;
V_259:
if ( V_21 -> V_261 )
V_21 -> V_261 ( & V_237 -> V_41 ) ;
V_258:
F_131 ( V_4 -> V_124 , V_4 ) ;
V_256:
F_132 ( V_4 -> V_11 ) ;
V_254:
F_6 ( V_4 -> V_252 ) ;
F_132 ( V_4 -> V_252 ) ;
V_253:
F_133 ( V_4 -> V_134 ) ;
V_251:
F_134 ( V_4 ) ;
V_248:
F_135 ( V_241 -> V_245 , F_119 ( V_241 ) ) ;
return V_242 ;
}
static int F_136 ( struct V_236 * V_237 )
{
struct V_7 * V_4 = F_137 ( V_237 ) ;
int V_32 ;
F_124 ( V_237 , NULL ) ;
F_18 ( V_4 == NULL ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ )
F_112 ( V_4 -> V_37 [ V_32 ] ) ;
if ( V_4 -> V_21 -> V_261 )
V_4 -> V_21 -> V_261 ( & V_237 -> V_41 ) ;
F_3 ( V_4 , 0 ) ;
F_131 ( V_4 -> V_124 , V_4 ) ;
F_132 ( V_4 -> V_11 ) ;
F_6 ( V_4 -> V_252 ) ;
F_132 ( V_4 -> V_252 ) ;
F_133 ( V_4 -> V_134 ) ;
F_135 ( V_237 -> V_240 [ 0 ] . V_245 ,
V_237 -> V_240 [ 0 ] . V_262 - V_237 -> V_240 [ 0 ] . V_245 + 1 ) ;
F_134 ( V_4 ) ;
return 0 ;
}
static int F_138 ( struct V_236 * V_237 , T_6 V_263 )
{
int V_32 , V_242 = 0 ;
struct V_7 * V_4 = F_137 ( V_237 ) ;
if ( V_4 == NULL || V_4 -> V_264 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
struct V_1 * V_2 ;
V_2 = V_4 -> V_37 [ V_32 ] ;
V_242 = F_139 ( V_2 -> V_15 ) ;
if ( V_242 < 0 ) {
while ( -- V_32 >= 0 ) {
V_2 = V_4 -> V_37 [ V_32 ] ;
F_140 ( V_2 -> V_15 ) ;
}
return V_242 ;
}
}
V_4 -> V_264 = 1 ;
return 0 ;
}
static int F_141 ( struct V_236 * V_237 )
{
int V_32 , V_242 = 0 ;
struct V_7 * V_4 = F_137 ( V_237 ) ;
if ( V_4 == NULL || ! V_4 -> V_264 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
struct V_1 * V_2 ;
V_2 = V_4 -> V_37 [ V_32 ] ;
V_242 = F_140 ( V_2 -> V_15 ) ;
if ( V_242 < 0 )
return V_242 ;
V_4 -> V_264 = 0 ;
}
return 0 ;
}
static int T_5 F_142 ( void )
{
int V_242 ;
V_38 = F_143 ( L_46 , 0 , 0 ) ;
if ( ! V_38 )
return - V_216 ;
V_242 = F_144 ( & V_265 , F_115 ) ;
if ( V_242 )
F_145 ( V_38 ) ;
return V_242 ;
}
static void T_7 F_146 ( void )
{
F_147 ( & V_265 ) ;
F_145 ( V_38 ) ;
}
