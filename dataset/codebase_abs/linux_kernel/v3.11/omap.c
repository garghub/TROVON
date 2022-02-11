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
static void F_54 ( struct V_7 * V_4 , T_3 V_139 )
{
static const char * V_140 [] = {
L_6 , L_7 , L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
int V_32 ;
char V_141 [ 64 ] , * V_44 = V_141 ;
V_44 += sprintf ( V_44 , L_21 , V_139 ) ;
for ( V_32 = 0 ; V_32 < F_55 ( V_140 ) ; V_32 ++ )
if ( V_139 & ( 1 << V_32 ) )
V_44 += sprintf ( V_44 , L_22 , V_140 [ V_32 ] ) ;
F_56 ( F_12 ( V_4 -> V_15 ) , L_1 , V_141 ) ;
}
static void F_54 ( struct V_7 * V_4 , T_3 V_139 )
{
}
static T_4 F_57 ( int V_127 , void * V_142 )
{
struct V_7 * V_4 = (struct V_7 * ) V_142 ;
T_3 V_139 ;
int V_143 ;
int V_144 ;
int V_145 , V_146 ;
if ( V_4 -> V_49 == NULL && V_4 -> V_69 == NULL ) {
V_139 = F_13 ( V_4 , V_108 ) ;
F_58 ( F_12 ( V_4 -> V_37 [ 0 ] -> V_15 ) ,
L_23 , V_139 ) ;
if ( V_139 != 0 ) {
F_11 ( V_4 , V_108 , V_139 ) ;
F_11 ( V_4 , V_76 , 0 ) ;
}
return V_147 ;
}
V_143 = 0 ;
V_144 = 0 ;
V_145 = 0 ;
V_146 = 0 ;
while ( ( V_139 = F_13 ( V_4 , V_108 ) ) != 0 ) {
int V_49 ;
F_11 ( V_4 , V_108 , V_139 ) ;
if ( V_4 -> V_49 != NULL )
V_49 = V_4 -> V_49 -> V_65 ;
else
V_49 = - 1 ;
F_43 ( F_12 ( V_4 -> V_15 ) , L_24 ,
V_139 , V_49 ) ;
F_54 ( V_4 , V_139 ) ;
if ( V_4 -> V_133 ) {
if ( ( V_139 & V_78 ) ||
( V_139 & V_85 ) )
F_50 ( V_4 , 0 ) ;
if ( V_139 & V_77 )
F_50 ( V_4 , 1 ) ;
}
if ( V_139 & V_85 )
V_144 = 1 ;
if ( V_139 & V_82 ) {
F_43 ( F_12 ( V_4 -> V_15 ) , L_25 ,
V_49 ) ;
if ( V_4 -> V_69 ) {
V_4 -> V_69 -> error = - V_126 ;
V_145 = 1 ;
}
}
if ( V_139 & V_81 ) {
if ( V_4 -> V_69 ) {
V_4 -> V_69 -> error = - V_148 ;
F_43 ( F_12 ( V_4 -> V_15 ) ,
L_26 ,
V_4 -> V_133 ) ;
V_145 = 1 ;
} else {
F_43 ( F_12 ( V_4 -> V_15 ) , L_27 ) ;
}
}
if ( V_139 & V_80 ) {
if ( V_4 -> V_49 ) {
struct V_1 * V_2 =
V_4 -> V_18 ;
if ( V_2 == NULL ||
! F_22 ( V_2 ) )
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_28 ,
V_49 ) ;
V_4 -> V_49 -> error = - V_126 ;
V_143 = 1 ;
V_146 = 1 ;
}
}
if ( V_139 & V_79 ) {
if ( V_4 -> V_49 ) {
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_29 ,
V_49 , V_4 -> V_49 -> V_74 ) ;
V_4 -> V_49 -> error = - V_148 ;
V_143 = 1 ;
V_146 = 1 ;
} else
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_30 ) ;
}
if ( V_139 & V_84 ) {
F_43 ( F_12 ( V_4 -> V_15 ) ,
L_31 ,
V_49 ) ;
V_143 = 1 ;
}
if ( ( V_139 & V_83 ) &&
( ! ( V_139 & V_77 ) ) ) {
V_143 = 1 ;
}
}
if ( V_146 && V_4 -> V_69 ) {
F_10 ( & V_4 -> V_71 ) ;
V_4 -> abort = 1 ;
F_11 ( V_4 , V_76 , 0 ) ;
F_59 ( V_4 -> V_127 ) ;
F_20 ( V_4 -> V_38 , & V_4 -> V_125 ) ;
return V_147 ;
}
if ( V_143 && V_4 -> V_49 )
F_41 ( V_4 , V_4 -> V_49 ) ;
if ( V_4 -> V_69 != NULL ) {
if ( V_145 )
F_34 ( V_4 , V_4 -> V_69 ) ;
else if ( V_144 )
F_39 ( V_4 , V_4 -> V_69 ) ;
}
return V_147 ;
}
void F_60 ( struct V_40 * V_41 , int V_149 , int V_150 )
{
int V_151 ;
struct V_7 * V_4 = F_61 ( V_41 ) ;
struct V_1 * V_2 = V_4 -> V_37 [ V_149 ] ;
F_18 ( V_149 >= V_4 -> V_35 ) ;
if ( V_4 -> V_35 == 0 || ! V_4 -> V_37 [ V_149 ] )
return;
V_151 = F_22 ( V_2 ) ;
if ( V_151 != V_2 -> V_151 ) {
V_2 -> V_151 = V_151 ;
F_62 ( & V_2 -> V_15 -> V_46 . V_152 , NULL , L_32 ) ;
}
F_63 ( & V_2 -> V_153 ) ;
}
static void F_64 ( unsigned long V_74 )
{
struct V_1 * V_2 = (struct V_1 * ) V_74 ;
F_65 ( & V_2 -> V_153 ) ;
}
static void F_66 ( unsigned long V_154 )
{
struct V_1 * V_2 = (struct V_1 * ) V_154 ;
int V_151 = F_22 ( V_2 ) ;
F_67 ( V_2 -> V_15 , 0 ) ;
if ( ! V_151 )
return;
if ( V_2 -> V_15 -> V_155 == NULL || ! F_68 ( V_2 -> V_15 -> V_155 ) )
return;
F_19 ( & V_2 -> V_156 ,
V_33 + F_69 ( V_157 ) ) ;
}
static void F_70 ( void * V_158 )
{
struct V_7 * V_4 = V_158 ;
struct V_87 * V_69 = V_4 -> V_69 ;
V_69 -> V_96 += V_69 -> V_159 * V_69 -> V_160 ;
F_40 ( V_4 , V_69 ) ;
}
static inline void F_71 ( struct V_7 * V_4 , struct V_28 * V_161 )
{
T_3 V_162 ;
V_162 = F_13 ( V_4 , V_163 ) ;
V_162 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_163 , V_162 ) ;
F_11 ( V_4 , V_72 , 0xff ) ;
}
static inline void F_72 ( struct V_7 * V_4 , struct V_28 * V_161 )
{
unsigned int V_106 , V_164 ;
T_3 V_162 ;
V_164 = 1000000000 / V_4 -> V_18 -> V_6 ;
V_106 = V_161 -> V_69 -> V_165 / V_164 ;
V_106 += V_161 -> V_69 -> V_166 ;
V_162 = F_13 ( V_4 , V_163 ) ;
if ( V_106 > 0xffff ) {
V_162 |= ( 1 << 5 ) ;
V_106 /= 1024 ;
} else
V_162 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_163 , V_162 ) ;
F_11 ( V_4 , V_167 , V_106 ) ;
}
static void
F_73 ( struct V_7 * V_4 , struct V_28 * V_161 )
{
struct V_87 * V_69 = V_161 -> V_69 ;
int V_32 , V_168 , V_169 ;
unsigned V_98 ;
V_4 -> V_69 = V_69 ;
if ( V_69 == NULL ) {
F_11 ( V_4 , V_170 , 0 ) ;
F_11 ( V_4 , V_171 , 0 ) ;
F_11 ( V_4 , V_172 , 0 ) ;
V_4 -> V_102 = 0 ;
F_71 ( V_4 , V_161 ) ;
return;
}
V_169 = V_69 -> V_160 ;
F_11 ( V_4 , V_171 , V_69 -> V_159 - 1 ) ;
F_11 ( V_4 , V_170 , V_169 - 1 ) ;
F_72 ( V_4 , V_161 ) ;
V_98 = ( V_69 -> V_159 == 1 ) ? 1 : V_69 -> V_98 ;
V_168 = V_4 -> V_168 ;
if ( V_168 ) {
for ( V_32 = 0 ; V_32 < V_98 ; V_32 ++ ) {
if ( ( V_69 -> V_97 [ V_32 ] . V_131 % V_169 ) != 0 ) {
V_168 = 0 ;
break;
}
}
}
V_4 -> V_129 = 0 ;
if ( V_168 ) {
enum V_88 V_89 ;
struct V_173 * V_174 ;
struct V_90 * V_91 ;
T_2 V_175 , * V_176 ;
T_3 V_44 ;
V_175 = F_74 () ? 32 : 64 ;
if ( V_175 > V_69 -> V_160 )
V_175 = V_69 -> V_160 ;
V_175 >>= 1 ;
if ( V_69 -> V_9 & V_70 ) {
V_91 = V_4 -> V_93 ;
V_176 = & V_4 -> V_177 ;
V_44 = 0x0f80 | ( V_175 - 1 ) << 0 ;
V_89 = V_92 ;
} else {
V_91 = V_4 -> V_95 ;
V_176 = & V_4 -> V_178 ;
V_44 = 0x800f | ( V_175 - 1 ) << 8 ;
V_89 = V_94 ;
}
if ( ! V_91 )
goto V_179;
if ( * V_176 != V_175 ) {
struct V_180 V_181 ;
V_181 . V_182 = V_4 -> V_183 + F_52 ( V_4 , V_138 ) ;
V_181 . V_184 = V_4 -> V_183 + F_52 ( V_4 , V_138 ) ;
V_181 . V_185 = V_186 ;
V_181 . V_187 = V_186 ;
V_181 . V_188 = V_175 ;
V_181 . V_189 = V_175 ;
if ( F_75 ( V_91 , & V_181 ) )
goto V_179;
* V_176 = V_175 ;
}
V_4 -> V_98 = F_76 ( V_91 -> V_40 -> V_41 , V_69 -> V_97 , V_98 ,
V_89 ) ;
if ( V_4 -> V_98 == 0 )
goto V_179;
V_174 = F_77 ( V_91 , V_69 -> V_97 , V_4 -> V_98 ,
V_69 -> V_9 & V_70 ? V_190 : V_191 ,
V_192 | V_193 ) ;
if ( ! V_174 )
goto V_179;
F_11 ( V_4 , V_172 , V_44 ) ;
V_174 -> V_194 = F_70 ;
V_174 -> V_195 = V_4 ;
F_78 ( V_174 ) ;
V_4 -> V_113 = 0 ;
V_4 -> V_112 = 0 ;
V_4 -> V_102 = 1 ;
return;
}
V_179:
F_11 ( V_4 , V_172 , 0x1f1f ) ;
V_4 -> V_133 = V_69 -> V_159 * V_169 ;
V_4 -> V_98 = V_98 ;
F_47 ( V_4 ) ;
V_4 -> V_102 = 0 ;
}
static void F_16 ( struct V_7 * V_4 ,
struct V_28 * V_161 )
{
F_18 ( V_4 -> V_30 != NULL ) ;
V_4 -> V_30 = V_161 ;
F_73 ( V_4 , V_161 ) ;
F_26 ( V_4 , V_161 -> V_49 ) ;
if ( V_4 -> V_102 ) {
struct V_90 * V_91 = V_4 -> V_69 -> V_9 & V_70 ?
V_4 -> V_93 : V_4 -> V_95 ;
F_79 ( V_91 ) ;
}
}
static void F_80 ( struct V_45 * V_15 , struct V_28 * V_161 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned long V_9 ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
if ( V_4 -> V_15 != NULL ) {
F_18 ( V_2 -> V_30 != NULL ) ;
V_2 -> V_30 = V_161 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
return;
} else
V_4 -> V_15 = V_15 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
F_8 ( V_2 , 1 ) ;
F_16 ( V_4 , V_161 ) ;
}
static void F_81 ( struct V_1 * V_2 , int V_196 ,
int V_197 )
{
struct V_7 * V_4 ;
V_4 = V_2 -> V_4 ;
if ( V_2 -> V_21 -> V_198 != NULL )
V_2 -> V_21 -> V_198 ( F_12 ( V_2 -> V_15 ) , V_2 -> V_23 , V_196 ,
V_197 ) ;
if ( F_82 () ) {
T_3 V_199 ;
if ( V_196 ) {
V_199 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_199 | ( 1 << 11 ) ) ;
} else {
V_199 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_199 & ~ ( 1 << 11 ) ) ;
}
}
}
static int F_83 ( struct V_45 * V_15 , struct V_200 * V_201 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_202 = F_84 ( V_4 -> V_11 ) ;
int V_203 ;
if ( V_201 -> clock == 0 )
return 0 ;
V_203 = V_202 / V_201 -> clock ;
if ( V_203 < 1 )
V_203 = 1 ;
if ( V_202 / V_203 > V_201 -> clock )
V_203 ++ ;
if ( V_203 > 250 )
V_203 = 250 ;
V_2 -> V_6 = V_202 / V_203 ;
if ( V_201 -> V_204 == V_205 )
V_203 |= 1 << 15 ;
return V_203 ;
}
static void F_85 ( struct V_45 * V_15 , struct V_200 * V_201 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_32 , V_203 ;
int V_31 ;
F_8 ( V_2 , 0 ) ;
V_203 = F_83 ( V_15 , V_201 ) ;
if ( V_201 -> V_197 != V_2 -> V_197 )
V_2 -> V_197 = V_201 -> V_197 ;
V_31 = 0 ;
switch ( V_201 -> V_206 ) {
case V_207 :
F_81 ( V_2 , 0 , V_201 -> V_197 ) ;
break;
case V_208 :
F_81 ( V_2 , 1 , V_201 -> V_197 ) ;
goto exit;
case V_209 :
F_3 ( V_4 , 1 ) ;
V_31 = 1 ;
V_203 |= 1 << 11 ;
break;
}
if ( V_2 -> V_66 != V_201 -> V_66 ) {
if ( V_2 -> V_21 -> V_210 != NULL )
V_2 -> V_21 -> V_210 ( F_12 ( V_15 ) , V_2 -> V_23 ,
V_201 -> V_66 ) ;
V_2 -> V_66 = V_201 -> V_66 ;
}
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ )
F_11 ( V_4 , V_19 , V_203 ) ;
V_2 -> V_20 = V_203 ;
if ( V_201 -> V_206 == V_209 ) {
int V_211 = 250 ;
F_11 ( V_4 , V_76 , 0 ) ;
F_11 ( V_4 , V_108 , 0xffff ) ;
F_11 ( V_4 , V_86 , 1 << 7 ) ;
while ( V_211 > 0 && ( F_13 ( V_4 , V_108 ) & 1 ) == 0 ) {
F_37 ( 1 ) ;
V_211 -- ;
}
F_11 ( V_4 , V_108 , 1 ) ;
}
exit:
F_17 ( V_2 , V_31 ) ;
}
static int F_86 ( struct V_7 * V_4 , int V_23 )
{
struct V_1 * V_2 = NULL ;
struct V_45 * V_15 ;
int V_212 ;
V_15 = F_87 ( sizeof( struct V_1 ) , V_4 -> V_41 ) ;
if ( V_15 == NULL )
return - V_213 ;
V_2 = F_24 ( V_15 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_21 = & V_4 -> V_21 -> V_37 [ V_23 ] ;
V_4 -> V_37 [ V_23 ] = V_2 ;
V_15 -> V_214 = 0 ;
if ( V_4 -> V_21 -> V_37 [ V_23 ] . V_215 >= 4 )
V_15 -> V_214 |= V_216 ;
V_15 -> V_217 = & V_218 ;
V_15 -> V_219 = 400000 ;
if ( F_82 () )
V_15 -> V_220 = 48000000 ;
else
V_15 -> V_220 = 24000000 ;
if ( V_4 -> V_21 -> V_221 )
V_15 -> V_220 = F_88 ( V_4 -> V_21 -> V_221 , V_15 -> V_220 ) ;
V_15 -> V_222 = V_2 -> V_21 -> V_223 ;
V_15 -> V_224 = 32 ;
V_15 -> V_225 = 2048 ;
V_15 -> V_226 = 2048 ;
V_15 -> V_227 = V_15 -> V_225 * V_15 -> V_226 ;
V_15 -> V_228 = V_15 -> V_227 ;
V_212 = F_89 ( V_15 ) ;
if ( V_212 < 0 )
goto V_229;
if ( V_2 -> V_21 -> V_47 != NULL ) {
V_212 = F_90 ( & V_15 -> V_46 ,
& V_230 ) ;
if ( V_212 < 0 )
goto V_229;
}
if ( V_2 -> V_21 -> V_39 != NULL ) {
V_212 = F_90 ( & V_15 -> V_46 ,
& V_231 ) ;
if ( V_212 < 0 )
goto V_232;
F_91 ( & V_2 -> V_156 , F_64 ,
( unsigned long ) V_2 ) ;
F_92 ( & V_2 -> V_153 , F_66 ,
( unsigned long ) V_2 ) ;
F_65 ( & V_2 -> V_153 ) ;
}
return 0 ;
V_232:
if ( V_2 -> V_21 -> V_47 != NULL )
F_93 ( & V_15 -> V_46 , & V_230 ) ;
V_229:
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
return V_212 ;
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_45 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_21 -> V_47 != NULL )
F_93 ( & V_15 -> V_46 , & V_230 ) ;
if ( V_2 -> V_21 -> V_39 != NULL )
F_93 ( & V_15 -> V_46 , & V_231 ) ;
F_97 ( & V_2 -> V_153 ) ;
F_98 ( & V_2 -> V_156 ) ;
F_99 ( V_2 -> V_4 -> V_38 ) ;
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
}
static int F_100 ( struct V_233 * V_234 )
{
struct V_235 * V_21 = V_234 -> V_41 . V_236 ;
struct V_7 * V_4 = NULL ;
struct V_237 * V_141 ;
T_5 V_238 ;
unsigned V_239 ;
int V_32 , V_240 = 0 ;
int V_127 ;
if ( V_21 == NULL ) {
F_28 ( & V_234 -> V_41 , L_33 ) ;
return - V_241 ;
}
if ( V_21 -> V_35 == 0 ) {
F_28 ( & V_234 -> V_41 , L_34 ) ;
return - V_241 ;
}
V_141 = F_101 ( V_234 , V_242 , 0 ) ;
V_127 = F_102 ( V_234 , 0 ) ;
if ( V_141 == NULL || V_127 < 0 )
return - V_241 ;
V_141 = F_103 ( V_141 -> V_243 , F_104 ( V_141 ) ,
V_234 -> V_47 ) ;
if ( V_141 == NULL )
return - V_244 ;
V_4 = F_105 ( sizeof( struct V_7 ) , V_245 ) ;
if ( V_4 == NULL ) {
V_240 = - V_213 ;
goto V_246;
}
F_106 ( & V_4 -> V_26 , F_14 ) ;
F_106 ( & V_4 -> V_99 , F_33 ) ;
F_106 ( & V_4 -> V_125 , F_42 ) ;
F_91 ( & V_4 -> V_71 , F_45 ,
( unsigned long ) V_4 ) ;
F_107 ( & V_4 -> V_10 ) ;
F_91 ( & V_4 -> V_17 , F_49 , ( unsigned long ) V_4 ) ;
F_107 ( & V_4 -> V_111 ) ;
F_107 ( & V_4 -> V_14 ) ;
F_108 ( & V_4 -> V_16 ) ;
V_4 -> V_21 = V_21 ;
V_4 -> V_247 = V_4 -> V_21 -> V_37 [ 0 ] . V_247 ;
V_4 -> V_41 = & V_234 -> V_41 ;
F_109 ( V_234 , V_4 ) ;
V_4 -> V_23 = V_234 -> V_23 ;
V_4 -> V_248 = V_141 ;
V_4 -> V_127 = V_127 ;
V_4 -> V_168 = 1 ;
V_4 -> V_127 = V_127 ;
V_4 -> V_183 = V_4 -> V_248 -> V_243 ;
V_4 -> V_137 = F_110 ( V_141 -> V_243 , F_104 ( V_141 ) ) ;
if ( ! V_4 -> V_137 )
goto V_249;
V_4 -> V_250 = F_111 ( & V_234 -> V_41 , L_35 ) ;
if ( F_112 ( V_4 -> V_250 ) ) {
V_240 = F_113 ( V_4 -> V_250 ) ;
goto V_251;
}
F_5 ( V_4 -> V_250 ) ;
V_4 -> V_11 = F_111 ( & V_234 -> V_41 , L_36 ) ;
if ( F_112 ( V_4 -> V_11 ) ) {
V_240 = F_113 ( V_4 -> V_11 ) ;
goto V_252;
}
F_114 ( V_238 ) ;
F_115 ( V_253 , V_238 ) ;
V_4 -> V_177 = - 1 ;
V_4 -> V_178 = - 1 ;
if ( F_82 () )
V_239 = V_4 -> V_23 == 0 ? V_254 : V_255 ;
else
V_239 = V_4 -> V_23 == 0 ? V_256 : V_257 ;
V_4 -> V_93 = F_116 ( V_238 , V_258 , & V_239 ) ;
if ( ! V_4 -> V_93 )
F_117 ( V_4 -> V_41 , L_37 ,
V_239 ) ;
if ( F_82 () )
V_239 = V_4 -> V_23 == 0 ? V_259 : V_260 ;
else
V_239 = V_4 -> V_23 == 0 ? V_261 : V_262 ;
V_4 -> V_95 = F_116 ( V_238 , V_258 , & V_239 ) ;
if ( ! V_4 -> V_95 )
F_117 ( V_4 -> V_41 , L_38 ,
V_239 ) ;
V_240 = F_118 ( V_4 -> V_127 , F_57 , 0 , V_263 , V_4 ) ;
if ( V_240 )
goto V_264;
if ( V_21 -> V_265 != NULL ) {
V_240 = V_21 -> V_265 ( & V_234 -> V_41 ) ;
if ( V_240 < 0 )
goto V_266;
}
V_4 -> V_35 = V_21 -> V_35 ;
V_4 -> V_267 = ( F_119 () ? 1 : 2 ) ;
V_4 -> V_38 = F_120 ( L_39 , 0 , 0 ) ;
if ( ! V_4 -> V_38 )
goto V_268;
for ( V_32 = 0 ; V_32 < V_21 -> V_35 ; V_32 ++ ) {
V_240 = F_86 ( V_4 , V_32 ) ;
if ( V_240 < 0 ) {
while ( -- V_32 >= 0 )
F_96 ( V_4 -> V_37 [ V_32 ] ) ;
goto V_269;
}
}
return 0 ;
V_269:
F_121 ( V_4 -> V_38 ) ;
V_268:
if ( V_21 -> V_270 )
V_21 -> V_270 ( & V_234 -> V_41 ) ;
V_266:
F_122 ( V_4 -> V_127 , V_4 ) ;
V_264:
if ( V_4 -> V_93 )
F_123 ( V_4 -> V_93 ) ;
if ( V_4 -> V_95 )
F_123 ( V_4 -> V_95 ) ;
F_124 ( V_4 -> V_11 ) ;
V_252:
F_6 ( V_4 -> V_250 ) ;
F_124 ( V_4 -> V_250 ) ;
V_251:
F_125 ( V_4 -> V_137 ) ;
V_249:
F_126 ( V_4 ) ;
V_246:
F_127 ( V_141 -> V_243 , F_104 ( V_141 ) ) ;
return V_240 ;
}
static int F_128 ( struct V_233 * V_234 )
{
struct V_7 * V_4 = F_129 ( V_234 ) ;
int V_32 ;
F_18 ( V_4 == NULL ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ )
F_96 ( V_4 -> V_37 [ V_32 ] ) ;
if ( V_4 -> V_21 -> V_270 )
V_4 -> V_21 -> V_270 ( & V_234 -> V_41 ) ;
F_3 ( V_4 , 0 ) ;
F_122 ( V_4 -> V_127 , V_4 ) ;
F_124 ( V_4 -> V_11 ) ;
F_6 ( V_4 -> V_250 ) ;
F_124 ( V_4 -> V_250 ) ;
if ( V_4 -> V_93 )
F_123 ( V_4 -> V_93 ) ;
if ( V_4 -> V_95 )
F_123 ( V_4 -> V_95 ) ;
F_125 ( V_4 -> V_137 ) ;
F_127 ( V_234 -> V_237 [ 0 ] . V_243 ,
V_234 -> V_237 [ 0 ] . V_271 - V_234 -> V_237 [ 0 ] . V_243 + 1 ) ;
F_121 ( V_4 -> V_38 ) ;
F_126 ( V_4 ) ;
return 0 ;
}
static int F_130 ( struct V_233 * V_234 , T_6 V_272 )
{
int V_32 , V_240 = 0 ;
struct V_7 * V_4 = F_129 ( V_234 ) ;
if ( V_4 == NULL || V_4 -> V_273 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
struct V_1 * V_2 ;
V_2 = V_4 -> V_37 [ V_32 ] ;
V_240 = F_131 ( V_2 -> V_15 ) ;
if ( V_240 < 0 ) {
while ( -- V_32 >= 0 ) {
V_2 = V_4 -> V_37 [ V_32 ] ;
F_132 ( V_2 -> V_15 ) ;
}
return V_240 ;
}
}
V_4 -> V_273 = 1 ;
return 0 ;
}
static int F_133 ( struct V_233 * V_234 )
{
int V_32 , V_240 = 0 ;
struct V_7 * V_4 = F_129 ( V_234 ) ;
if ( V_4 == NULL || ! V_4 -> V_273 )
return 0 ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ ) {
struct V_1 * V_2 ;
V_2 = V_4 -> V_37 [ V_32 ] ;
V_240 = F_132 ( V_2 -> V_15 ) ;
if ( V_240 < 0 )
return V_240 ;
V_4 -> V_273 = 0 ;
}
return 0 ;
}
