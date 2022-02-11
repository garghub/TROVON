static void F_1 ( struct V_1 * V_2 )
{
unsigned long V_3 ;
if ( V_2 != NULL && V_2 -> V_4 -> V_5 && V_2 -> V_6 > 0 ) {
V_3 = F_2 ( V_7 , V_2 -> V_6 ) ;
F_3 ( 8 * V_3 ) ;
}
}
static void F_4 ( struct V_8 * V_4 , unsigned int V_9 )
{
unsigned long V_10 ;
F_5 ( & V_4 -> V_11 , V_10 ) ;
if ( V_4 -> V_5 != V_9 ) {
V_4 -> V_5 = V_9 ;
if ( V_9 )
F_6 ( V_4 -> V_12 ) ;
else
F_7 ( V_4 -> V_12 ) ;
}
F_8 ( & V_4 -> V_11 , V_10 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_13 )
{
struct V_8 * V_4 = V_2 -> V_4 ;
unsigned long V_10 ;
if ( V_13 )
goto V_14;
F_5 ( & V_4 -> V_15 , V_10 ) ;
while ( V_4 -> V_16 != NULL ) {
F_8 ( & V_4 -> V_15 , V_10 ) ;
F_10 ( V_4 -> V_17 , V_4 -> V_16 == NULL ) ;
F_5 ( & V_4 -> V_15 , V_10 ) ;
}
V_4 -> V_16 = V_2 -> V_16 ;
F_8 ( & V_4 -> V_15 , V_10 ) ;
V_14:
F_11 ( & V_4 -> V_18 ) ;
if ( V_4 -> V_19 != V_2 || ! V_13 )
F_1 ( V_4 -> V_19 ) ;
if ( V_4 -> V_19 != V_2 ) {
F_12 ( V_4 , V_20 , V_2 -> V_21 & 0xFC00 ) ;
if ( V_4 -> V_22 -> V_23 != NULL )
V_4 -> V_22 -> V_23 ( F_13 ( V_2 -> V_16 ) , V_2 -> V_24 ) ;
V_4 -> V_19 = V_2 ;
}
if ( V_13 ) {
F_4 ( V_4 , 1 ) ;
F_14 ( V_4 , V_20 ) ;
F_12 ( V_4 , V_20 , V_2 -> V_21 ) ;
} else
F_4 ( V_4 , 0 ) ;
}
static void F_15 ( struct V_25 * V_26 )
{
struct V_8 * V_4 = F_16 ( V_26 , struct V_8 ,
V_27 ) ;
struct V_1 * V_28 = V_4 -> V_28 ;
struct V_29 * V_30 ;
V_4 -> V_28 = NULL ;
F_9 ( V_28 , 1 ) ;
V_30 = V_28 -> V_31 ;
V_28 -> V_31 = NULL ;
F_17 ( V_4 , V_30 ) ;
}
static void F_18 ( struct V_1 * V_2 , int V_32 )
{
struct V_8 * V_4 = V_2 -> V_4 ;
unsigned long V_10 ;
int V_33 ;
F_19 ( V_2 == NULL || V_4 -> V_16 == NULL ) ;
if ( V_32 )
F_20 ( & V_4 -> V_18 , V_34 + V_35 / 10 ) ;
else {
F_11 ( & V_4 -> V_18 ) ;
F_1 ( V_2 ) ;
F_4 ( V_4 , 0 ) ;
}
F_5 ( & V_4 -> V_15 , V_10 ) ;
for ( V_33 = 0 ; V_33 < V_4 -> V_36 ; V_33 ++ ) {
struct V_1 * V_37 ;
if ( V_4 -> V_38 [ V_33 ] == NULL || V_4 -> V_38 [ V_33 ] -> V_31 == NULL )
continue;
F_19 ( V_4 -> V_28 != NULL ) ;
V_37 = V_4 -> V_38 [ V_33 ] ;
F_19 ( V_37 == V_4 -> V_19 ) ;
V_4 -> V_28 = V_37 ;
V_4 -> V_16 = V_37 -> V_16 ;
F_8 ( & V_4 -> V_15 , V_10 ) ;
F_21 ( V_4 -> V_39 , & V_4 -> V_27 ) ;
return;
}
V_4 -> V_16 = NULL ;
F_22 ( & V_4 -> V_17 ) ;
F_8 ( & V_4 -> V_15 , V_10 ) ;
}
static inline
int F_23 ( struct V_1 * V_2 )
{
if ( V_2 -> V_22 -> V_40 )
return V_2 -> V_22 -> V_40 ( F_13 ( V_2 -> V_16 ) ,
V_2 -> V_24 ) ;
return 0 ;
}
static T_1
F_24 ( struct V_41 * V_42 , struct V_43 * V_44 ,
char * V_45 )
{
struct V_46 * V_16 = F_16 ( V_42 , struct V_46 , V_47 ) ;
struct V_1 * V_2 = F_25 ( V_16 ) ;
return sprintf ( V_45 , L_1 , F_23 ( V_2 ) ? L_2 :
L_3 ) ;
}
static T_1
F_26 ( struct V_41 * V_42 , struct V_43 * V_44 ,
char * V_45 )
{
struct V_46 * V_16 = F_16 ( V_42 , struct V_46 , V_47 ) ;
struct V_1 * V_2 = F_25 ( V_16 ) ;
return sprintf ( V_45 , L_1 , V_2 -> V_22 -> V_48 ) ;
}
static void
F_27 ( struct V_8 * V_4 , struct V_49 * V_50 )
{
T_2 V_51 ;
T_2 V_52 ;
T_2 V_53 ;
T_3 V_54 ;
V_4 -> V_50 = V_50 ;
V_52 = 0 ;
V_53 = 0 ;
switch ( F_28 ( V_50 ) ) {
case V_55 :
break;
case V_56 :
case V_57 :
V_52 = 1 ;
break;
case V_58 :
V_52 = 2 ;
break;
case V_59 :
V_52 = 3 ;
break;
default:
F_29 ( F_13 ( V_4 -> V_16 ) , L_4 , F_28 ( V_50 ) ) ;
break;
}
if ( F_30 ( V_50 ) == V_60 ) {
V_53 = V_61 ;
} else if ( F_30 ( V_50 ) == V_62 ) {
V_53 = V_63 ;
} else if ( F_30 ( V_50 ) == V_64 ) {
V_53 = V_65 ;
} else {
V_53 = V_66 ;
}
V_51 = V_50 -> V_67 | ( V_52 << 8 ) | ( V_53 << 12 ) ;
if ( V_4 -> V_19 -> V_68 == V_69 )
V_51 |= 1 << 6 ;
if ( V_50 -> V_10 & V_70 )
V_51 |= 1 << 11 ;
if ( V_4 -> V_71 && ! ( V_4 -> V_71 -> V_10 & V_72 ) )
V_51 |= 1 << 15 ;
F_20 ( & V_4 -> V_73 , V_34 + V_35 / 2 ) ;
F_12 ( V_4 , V_74 , 200 ) ;
F_12 ( V_4 , V_75 , V_50 -> V_76 & 0xffff ) ;
F_12 ( V_4 , V_77 , V_50 -> V_76 >> 16 ) ;
V_54 = V_78 | V_79 |
V_80 | V_81 |
V_82 | V_83 |
V_84 | V_85 |
V_86 ;
if ( V_50 -> V_67 == V_87 )
V_54 &= ~ V_83 ;
F_12 ( V_4 , V_88 , V_54 ) ;
F_12 ( V_4 , V_89 , V_51 ) ;
}
static void
F_31 ( struct V_8 * V_4 , struct V_90 * V_71 ,
int abort )
{
enum V_91 V_92 ;
struct V_41 * V_42 = F_13 ( V_4 -> V_16 ) ;
struct V_93 * V_94 ;
if ( V_71 -> V_10 & V_72 ) {
V_92 = V_95 ;
V_94 = V_4 -> V_96 ;
} else {
V_92 = V_97 ;
V_94 = V_4 -> V_98 ;
}
if ( V_94 ) {
if ( V_71 -> error ) {
F_32 ( V_94 ) ;
V_71 -> V_99 = 0 ;
}
V_42 = V_94 -> V_41 -> V_42 ;
}
F_33 ( V_42 , V_71 -> V_100 , V_4 -> V_101 , V_92 ) ;
}
static void F_34 ( struct V_25 * V_26 )
{
struct V_8 * V_4 = F_16 ( V_26 , struct V_8 ,
V_102 ) ;
struct V_1 * V_2 = V_4 -> V_19 ;
struct V_90 * V_71 = V_4 -> V_103 ;
unsigned long V_3 ;
V_3 = F_2 ( V_7 , V_2 -> V_6 ) ;
F_3 ( 8 * V_3 ) ;
F_27 ( V_4 , V_71 -> V_104 ) ;
}
static void
F_35 ( struct V_8 * V_4 , struct V_90 * V_71 )
{
if ( V_4 -> V_105 )
F_31 ( V_4 , V_71 , V_71 -> error ) ;
V_4 -> V_71 = NULL ;
V_4 -> V_101 = 0 ;
if ( ! V_71 -> V_104 ) {
struct V_46 * V_16 ;
V_4 -> V_31 = NULL ;
V_16 = V_4 -> V_16 ;
F_18 ( V_4 -> V_19 , 1 ) ;
F_36 ( V_16 , V_71 -> V_31 ) ;
return;
}
V_4 -> V_103 = V_71 ;
F_21 ( V_4 -> V_39 , & V_4 -> V_102 ) ;
}
static void
F_37 ( struct V_8 * V_4 , int V_106 )
{
struct V_1 * V_2 = V_4 -> V_19 ;
unsigned int V_107 , V_108 , V_109 ;
T_3 V_110 = 0 ;
V_109 = F_2 ( 120 * V_111 , V_2 -> V_6 ) ;
V_107 = 0 ;
while ( V_107 < V_106 ) {
F_12 ( V_4 , V_112 , 0xFFFF ) ;
F_12 ( V_4 , V_89 , ( 3 << 12 ) | ( 1 << 7 ) ) ;
V_108 = 0 ;
while ( V_108 < V_109 ) {
V_110 = F_14 ( V_4 , V_112 ) ;
if ( V_110 & V_84 )
goto V_113;
F_38 ( 1 ) ;
V_108 ++ ;
}
V_107 ++ ;
}
V_113:
F_12 ( V_4 , V_112 , V_110 ) ;
}
static void
F_39 ( struct V_8 * V_4 , struct V_90 * V_71 )
{
if ( V_4 -> V_105 )
F_31 ( V_4 , V_71 , 1 ) ;
V_4 -> V_71 = NULL ;
V_4 -> V_101 = 0 ;
F_37 ( V_4 , 10000 ) ;
}
static void
F_40 ( struct V_8 * V_4 , struct V_90 * V_71 )
{
unsigned long V_10 ;
int V_114 ;
if ( ! V_4 -> V_105 ) {
F_35 ( V_4 , V_71 ) ;
return;
}
V_114 = 0 ;
F_5 ( & V_4 -> V_115 , V_10 ) ;
if ( V_4 -> V_116 )
V_114 = 1 ;
else
V_4 -> V_117 = 1 ;
F_8 ( & V_4 -> V_115 , V_10 ) ;
if ( V_114 )
F_35 ( V_4 , V_71 ) ;
}
static void
F_41 ( struct V_8 * V_4 , struct V_90 * V_71 )
{
unsigned long V_10 ;
int V_114 ;
V_114 = 0 ;
F_5 ( & V_4 -> V_115 , V_10 ) ;
if ( V_4 -> V_117 )
V_114 = 1 ;
else
V_4 -> V_116 = 1 ;
F_8 ( & V_4 -> V_115 , V_10 ) ;
if ( V_114 )
F_35 ( V_4 , V_71 ) ;
}
static void
F_42 ( struct V_8 * V_4 , struct V_49 * V_50 )
{
V_4 -> V_50 = NULL ;
F_11 ( & V_4 -> V_73 ) ;
if ( V_50 -> V_10 & V_118 ) {
if ( V_50 -> V_10 & V_119 ) {
V_50 -> V_120 [ 3 ] =
F_14 ( V_4 , V_121 ) |
( F_14 ( V_4 , V_122 ) << 16 ) ;
V_50 -> V_120 [ 2 ] =
F_14 ( V_4 , V_123 ) |
( F_14 ( V_4 , V_124 ) << 16 ) ;
V_50 -> V_120 [ 1 ] =
F_14 ( V_4 , V_125 ) |
( F_14 ( V_4 , V_126 ) << 16 ) ;
V_50 -> V_120 [ 0 ] =
F_14 ( V_4 , V_127 ) |
( F_14 ( V_4 , V_128 ) << 16 ) ;
} else {
V_50 -> V_120 [ 0 ] =
F_14 ( V_4 , V_127 ) |
( F_14 ( V_4 , V_128 ) << 16 ) ;
}
}
if ( V_4 -> V_71 == NULL || V_50 -> error ) {
struct V_46 * V_16 ;
if ( V_4 -> V_71 != NULL )
F_39 ( V_4 , V_4 -> V_71 ) ;
V_4 -> V_31 = NULL ;
V_16 = V_4 -> V_16 ;
F_18 ( V_4 -> V_19 , 1 ) ;
F_36 ( V_16 , V_50 -> V_31 ) ;
}
}
static void F_43 ( struct V_25 * V_26 )
{
struct V_8 * V_4 = F_16 ( V_26 , struct V_8 ,
V_129 ) ;
F_19 ( ! V_4 -> V_50 ) ;
F_44 ( F_13 ( V_4 -> V_16 ) , L_5 ,
V_4 -> V_50 -> V_67 ) ;
if ( V_4 -> V_50 -> error == 0 )
V_4 -> V_50 -> error = - V_130 ;
if ( V_4 -> V_71 == NULL ) {
struct V_49 * V_50 ;
struct V_46 * V_16 ;
V_50 = V_4 -> V_50 ;
V_4 -> V_50 = NULL ;
F_37 ( V_4 , 10000 ) ;
V_4 -> V_31 = NULL ;
V_16 = V_4 -> V_16 ;
F_18 ( V_4 -> V_19 , 1 ) ;
F_36 ( V_16 , V_50 -> V_31 ) ;
} else
F_42 ( V_4 , V_4 -> V_50 ) ;
V_4 -> abort = 0 ;
F_45 ( V_4 -> V_131 ) ;
}
static void
F_46 ( unsigned long V_71 )
{
struct V_8 * V_4 = (struct V_8 * ) V_71 ;
unsigned long V_10 ;
F_5 ( & V_4 -> V_15 , V_10 ) ;
if ( V_4 -> V_50 != NULL && ! V_4 -> abort ) {
F_12 ( V_4 , V_88 , 0 ) ;
F_47 ( V_4 -> V_131 ) ;
V_4 -> abort = 1 ;
F_21 ( V_4 -> V_39 , & V_4 -> V_129 ) ;
}
F_8 ( & V_4 -> V_15 , V_10 ) ;
}
static void
F_48 ( struct V_8 * V_4 )
{
struct V_132 * V_100 ;
V_100 = V_4 -> V_71 -> V_100 + V_4 -> V_133 ;
V_4 -> V_134 = V_100 -> V_135 ;
V_4 -> V_136 = F_49 ( V_100 ) ;
if ( V_4 -> V_134 > V_4 -> V_137 )
V_4 -> V_134 = V_4 -> V_137 ;
}
static void
F_50 ( unsigned long V_71 )
{
struct V_8 * V_4 = (struct V_8 * ) V_71 ;
F_4 ( V_4 , 0 ) ;
}
static void
F_51 ( struct V_8 * V_4 , int V_138 )
{
int V_139 , V_140 ;
if ( V_4 -> V_134 == 0 ) {
V_4 -> V_133 ++ ;
F_19 ( V_4 -> V_133 == V_4 -> V_101 ) ;
F_48 ( V_4 ) ;
}
V_139 = 64 ;
if ( V_139 > V_4 -> V_134 )
V_139 = V_4 -> V_134 ;
V_140 = F_2 ( V_139 , 2 ) ;
V_4 -> V_134 -= V_139 ;
V_4 -> V_137 -= V_139 ;
V_4 -> V_71 -> V_99 += V_139 ;
if ( V_138 ) {
F_52 ( V_4 -> V_141 + F_53 ( V_4 , V_142 ) ,
V_4 -> V_136 , V_140 ) ;
} else {
F_54 ( V_4 -> V_141 + F_53 ( V_4 , V_142 ) ,
V_4 -> V_136 , V_140 ) ;
}
V_4 -> V_136 += V_140 ;
}
static void F_55 ( struct V_8 * V_4 , T_3 V_143 )
{
static const char * V_144 [] = {
L_6 , L_7 , L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
int V_33 ;
char V_145 [ 64 ] , * V_45 = V_145 ;
V_45 += sprintf ( V_45 , L_21 , V_143 ) ;
for ( V_33 = 0 ; V_33 < F_56 ( V_144 ) ; V_33 ++ )
if ( V_143 & ( 1 << V_33 ) )
V_45 += sprintf ( V_45 , L_22 , V_144 [ V_33 ] ) ;
F_57 ( F_13 ( V_4 -> V_16 ) , L_1 , V_145 ) ;
}
static void F_55 ( struct V_8 * V_4 , T_3 V_143 )
{
}
static T_4 F_58 ( int V_131 , void * V_146 )
{
struct V_8 * V_4 = (struct V_8 * ) V_146 ;
T_3 V_143 ;
int V_147 ;
int V_148 ;
int V_149 , V_150 ;
if ( V_4 -> V_50 == NULL && V_4 -> V_71 == NULL ) {
V_143 = F_14 ( V_4 , V_112 ) ;
F_59 ( F_13 ( V_4 -> V_38 [ 0 ] -> V_16 ) ,
L_23 , V_143 ) ;
if ( V_143 != 0 ) {
F_12 ( V_4 , V_112 , V_143 ) ;
F_12 ( V_4 , V_88 , 0 ) ;
}
return V_151 ;
}
V_147 = 0 ;
V_148 = 0 ;
V_149 = 0 ;
V_150 = 0 ;
while ( ( V_143 = F_14 ( V_4 , V_112 ) ) != 0 ) {
int V_50 ;
F_12 ( V_4 , V_112 , V_143 ) ;
if ( V_4 -> V_50 != NULL )
V_50 = V_4 -> V_50 -> V_67 ;
else
V_50 = - 1 ;
F_44 ( F_13 ( V_4 -> V_16 ) , L_24 ,
V_143 , V_50 ) ;
F_55 ( V_4 , V_143 ) ;
if ( V_4 -> V_137 ) {
if ( ( V_143 & V_79 ) ||
( V_143 & V_86 ) )
F_51 ( V_4 , 0 ) ;
if ( V_143 & V_78 )
F_51 ( V_4 , 1 ) ;
}
if ( V_143 & V_86 )
V_148 = 1 ;
if ( V_143 & V_83 ) {
F_44 ( F_13 ( V_4 -> V_16 ) , L_25 ,
V_50 ) ;
if ( V_4 -> V_71 ) {
V_4 -> V_71 -> error = - V_130 ;
V_149 = 1 ;
}
}
if ( V_143 & V_82 ) {
if ( V_4 -> V_71 ) {
V_4 -> V_71 -> error = - V_152 ;
F_44 ( F_13 ( V_4 -> V_16 ) ,
L_26 ,
V_4 -> V_137 ) ;
V_149 = 1 ;
} else {
F_44 ( F_13 ( V_4 -> V_16 ) , L_27 ) ;
}
}
if ( V_143 & V_81 ) {
if ( V_4 -> V_50 ) {
struct V_1 * V_2 =
V_4 -> V_19 ;
if ( V_2 == NULL ||
! F_23 ( V_2 ) )
F_29 ( F_13 ( V_4 -> V_16 ) ,
L_28 ,
V_50 ) ;
V_4 -> V_50 -> error = - V_130 ;
V_147 = 1 ;
V_150 = 1 ;
}
}
if ( V_143 & V_80 ) {
if ( V_4 -> V_50 ) {
F_29 ( F_13 ( V_4 -> V_16 ) ,
L_29 ,
V_50 , V_4 -> V_50 -> V_76 ) ;
V_4 -> V_50 -> error = - V_152 ;
V_147 = 1 ;
V_150 = 1 ;
} else
F_29 ( F_13 ( V_4 -> V_16 ) ,
L_30 ) ;
}
if ( V_143 & V_85 ) {
F_44 ( F_13 ( V_4 -> V_16 ) ,
L_31 ,
V_50 ) ;
V_147 = 1 ;
}
if ( ( V_143 & V_84 ) &&
( ! ( V_143 & V_78 ) ) ) {
V_147 = 1 ;
}
}
if ( V_150 && V_4 -> V_71 ) {
F_11 ( & V_4 -> V_73 ) ;
V_4 -> abort = 1 ;
F_12 ( V_4 , V_88 , 0 ) ;
F_60 ( V_4 -> V_131 ) ;
F_21 ( V_4 -> V_39 , & V_4 -> V_129 ) ;
return V_151 ;
}
if ( V_147 && V_4 -> V_50 )
F_42 ( V_4 , V_4 -> V_50 ) ;
if ( V_4 -> V_71 != NULL ) {
if ( V_149 )
F_35 ( V_4 , V_4 -> V_71 ) ;
else if ( V_148 )
F_40 ( V_4 , V_4 -> V_71 ) ;
}
return V_151 ;
}
void F_61 ( struct V_41 * V_42 , int V_153 , int V_154 )
{
int V_155 ;
struct V_8 * V_4 = F_62 ( V_42 ) ;
struct V_1 * V_2 = V_4 -> V_38 [ V_153 ] ;
F_19 ( V_153 >= V_4 -> V_36 ) ;
if ( V_4 -> V_36 == 0 || ! V_4 -> V_38 [ V_153 ] )
return;
V_155 = F_23 ( V_2 ) ;
if ( V_155 != V_2 -> V_155 ) {
V_2 -> V_155 = V_155 ;
F_63 ( & V_2 -> V_16 -> V_47 . V_156 , NULL , L_32 ) ;
}
F_64 ( & V_2 -> V_157 ) ;
}
static void F_65 ( unsigned long V_76 )
{
struct V_1 * V_2 = (struct V_1 * ) V_76 ;
F_66 ( & V_2 -> V_157 ) ;
}
static void F_67 ( unsigned long V_158 )
{
struct V_1 * V_2 = (struct V_1 * ) V_158 ;
int V_155 = F_23 ( V_2 ) ;
F_68 ( V_2 -> V_16 , 0 ) ;
if ( ! V_155 )
return;
if ( V_2 -> V_16 -> V_159 == NULL || ! F_69 ( V_2 -> V_16 -> V_159 ) )
return;
F_20 ( & V_2 -> V_160 ,
V_34 + F_70 ( V_161 ) ) ;
}
static void F_71 ( void * V_162 )
{
struct V_8 * V_4 = V_162 ;
struct V_90 * V_71 = V_4 -> V_71 ;
V_71 -> V_99 += V_71 -> V_163 * V_71 -> V_164 ;
F_41 ( V_4 , V_71 ) ;
}
static inline void F_72 ( struct V_8 * V_4 , struct V_29 * V_165 )
{
T_3 V_166 ;
V_166 = F_14 ( V_4 , V_167 ) ;
V_166 &= ~ ( 1 << 5 ) ;
F_12 ( V_4 , V_167 , V_166 ) ;
F_12 ( V_4 , V_74 , 0xff ) ;
}
static inline void F_73 ( struct V_8 * V_4 , struct V_29 * V_165 )
{
unsigned int V_109 , V_168 ;
T_3 V_166 ;
V_168 = 1000000000 / V_4 -> V_19 -> V_6 ;
V_109 = V_165 -> V_71 -> V_169 / V_168 ;
V_109 += V_165 -> V_71 -> V_170 ;
V_166 = F_14 ( V_4 , V_167 ) ;
if ( V_109 > 0xffff ) {
V_166 |= ( 1 << 5 ) ;
V_109 /= 1024 ;
} else
V_166 &= ~ ( 1 << 5 ) ;
F_12 ( V_4 , V_167 , V_166 ) ;
F_12 ( V_4 , V_171 , V_109 ) ;
}
static void
F_74 ( struct V_8 * V_4 , struct V_29 * V_165 )
{
struct V_90 * V_71 = V_165 -> V_71 ;
int V_33 , V_172 = 1 , V_173 ;
unsigned V_101 ;
V_4 -> V_71 = V_71 ;
if ( V_71 == NULL ) {
F_12 ( V_4 , V_174 , 0 ) ;
F_12 ( V_4 , V_175 , 0 ) ;
F_12 ( V_4 , V_176 , 0 ) ;
V_4 -> V_105 = 0 ;
F_72 ( V_4 , V_165 ) ;
return;
}
V_173 = V_71 -> V_164 ;
F_12 ( V_4 , V_175 , V_71 -> V_163 - 1 ) ;
F_12 ( V_4 , V_174 , V_173 - 1 ) ;
F_73 ( V_4 , V_165 ) ;
V_101 = ( V_71 -> V_163 == 1 ) ? 1 : V_71 -> V_101 ;
for ( V_33 = 0 ; V_33 < V_101 ; V_33 ++ ) {
if ( ( V_71 -> V_100 [ V_33 ] . V_135 % V_173 ) != 0 ) {
V_172 = 0 ;
break;
}
}
V_4 -> V_133 = 0 ;
if ( V_172 ) {
enum V_91 V_92 ;
struct V_177 * V_178 ;
struct V_93 * V_94 ;
T_2 V_179 , * V_180 ;
T_3 V_45 ;
V_179 = F_75 () ? 32 : 64 ;
if ( V_179 > V_71 -> V_164 )
V_179 = V_71 -> V_164 ;
V_179 >>= 1 ;
if ( V_71 -> V_10 & V_72 ) {
V_94 = V_4 -> V_96 ;
V_180 = & V_4 -> V_181 ;
V_45 = 0x0f80 | ( V_179 - 1 ) << 0 ;
V_92 = V_95 ;
} else {
V_94 = V_4 -> V_98 ;
V_180 = & V_4 -> V_182 ;
V_45 = 0x800f | ( V_179 - 1 ) << 8 ;
V_92 = V_97 ;
}
if ( ! V_94 )
goto V_183;
if ( * V_180 != V_179 ) {
struct V_184 V_185 ;
V_185 . V_186 = V_4 -> V_187 + F_53 ( V_4 , V_142 ) ;
V_185 . V_188 = V_4 -> V_187 + F_53 ( V_4 , V_142 ) ;
V_185 . V_189 = V_190 ;
V_185 . V_191 = V_190 ;
V_185 . V_192 = V_179 ;
V_185 . V_193 = V_179 ;
if ( F_76 ( V_94 , & V_185 ) )
goto V_183;
* V_180 = V_179 ;
}
V_4 -> V_101 = F_77 ( V_94 -> V_41 -> V_42 , V_71 -> V_100 , V_101 ,
V_92 ) ;
if ( V_4 -> V_101 == 0 )
goto V_183;
V_178 = F_78 ( V_94 , V_71 -> V_100 , V_4 -> V_101 ,
V_71 -> V_10 & V_72 ? V_194 : V_195 ,
V_196 | V_197 ) ;
if ( ! V_178 )
goto V_183;
F_12 ( V_4 , V_176 , V_45 ) ;
V_178 -> V_198 = F_71 ;
V_178 -> V_199 = V_4 ;
F_79 ( V_178 ) ;
V_4 -> V_117 = 0 ;
V_4 -> V_116 = 0 ;
V_4 -> V_105 = 1 ;
return;
}
V_183:
F_12 ( V_4 , V_176 , 0x1f1f ) ;
V_4 -> V_137 = V_71 -> V_163 * V_173 ;
V_4 -> V_101 = V_101 ;
F_48 ( V_4 ) ;
V_4 -> V_105 = 0 ;
}
static void F_17 ( struct V_8 * V_4 ,
struct V_29 * V_165 )
{
F_19 ( V_4 -> V_31 != NULL ) ;
V_4 -> V_31 = V_165 ;
F_74 ( V_4 , V_165 ) ;
F_27 ( V_4 , V_165 -> V_50 ) ;
if ( V_4 -> V_105 ) {
struct V_93 * V_94 = V_4 -> V_71 -> V_10 & V_72 ?
V_4 -> V_96 : V_4 -> V_98 ;
F_80 ( V_94 ) ;
}
}
static void F_81 ( struct V_46 * V_16 , struct V_29 * V_165 )
{
struct V_1 * V_2 = F_25 ( V_16 ) ;
struct V_8 * V_4 = V_2 -> V_4 ;
unsigned long V_10 ;
F_5 ( & V_4 -> V_15 , V_10 ) ;
if ( V_4 -> V_16 != NULL ) {
F_19 ( V_2 -> V_31 != NULL ) ;
V_2 -> V_31 = V_165 ;
F_8 ( & V_4 -> V_15 , V_10 ) ;
return;
} else
V_4 -> V_16 = V_16 ;
F_8 ( & V_4 -> V_15 , V_10 ) ;
F_9 ( V_2 , 1 ) ;
F_17 ( V_4 , V_165 ) ;
}
static void F_82 ( struct V_1 * V_2 , int V_200 ,
int V_201 )
{
struct V_8 * V_4 ;
V_4 = V_2 -> V_4 ;
if ( V_2 -> V_22 -> V_202 != NULL )
V_2 -> V_22 -> V_202 ( F_13 ( V_2 -> V_16 ) , V_2 -> V_24 , V_200 ,
V_201 ) ;
if ( F_83 () ) {
T_3 V_203 ;
if ( V_200 ) {
V_203 = F_14 ( V_4 , V_20 ) ;
F_12 ( V_4 , V_20 , V_203 | ( 1 << 11 ) ) ;
} else {
V_203 = F_14 ( V_4 , V_20 ) ;
F_12 ( V_4 , V_20 , V_203 & ~ ( 1 << 11 ) ) ;
}
}
}
static int F_84 ( struct V_46 * V_16 , struct V_204 * V_205 )
{
struct V_1 * V_2 = F_25 ( V_16 ) ;
struct V_8 * V_4 = V_2 -> V_4 ;
int V_206 = F_85 ( V_4 -> V_12 ) ;
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
static void F_86 ( struct V_46 * V_16 , struct V_204 * V_205 )
{
struct V_1 * V_2 = F_25 ( V_16 ) ;
struct V_8 * V_4 = V_2 -> V_4 ;
int V_33 , V_207 ;
int V_32 ;
F_9 ( V_2 , 0 ) ;
V_207 = F_84 ( V_16 , V_205 ) ;
if ( V_205 -> V_201 != V_2 -> V_201 )
V_2 -> V_201 = V_205 -> V_201 ;
V_32 = 0 ;
switch ( V_205 -> V_210 ) {
case V_211 :
F_82 ( V_2 , 0 , V_205 -> V_201 ) ;
break;
case V_212 :
F_82 ( V_2 , 1 , V_205 -> V_201 ) ;
goto exit;
case V_213 :
F_4 ( V_4 , 1 ) ;
V_32 = 1 ;
V_207 |= 1 << 11 ;
break;
}
if ( V_2 -> V_68 != V_205 -> V_68 ) {
if ( V_2 -> V_22 -> V_214 != NULL )
V_2 -> V_22 -> V_214 ( F_13 ( V_16 ) , V_2 -> V_24 ,
V_205 -> V_68 ) ;
V_2 -> V_68 = V_205 -> V_68 ;
}
for ( V_33 = 0 ; V_33 < 2 ; V_33 ++ )
F_12 ( V_4 , V_20 , V_207 ) ;
V_2 -> V_21 = V_207 ;
if ( V_205 -> V_210 == V_213 ) {
int V_215 = 250 ;
F_12 ( V_4 , V_88 , 0 ) ;
F_12 ( V_4 , V_112 , 0xffff ) ;
F_12 ( V_4 , V_89 , 1 << 7 ) ;
while ( V_215 > 0 && ( F_14 ( V_4 , V_112 ) & 1 ) == 0 ) {
F_38 ( 1 ) ;
V_215 -- ;
}
F_12 ( V_4 , V_112 , 1 ) ;
}
exit:
F_18 ( V_2 , V_32 ) ;
}
static int F_87 ( struct V_8 * V_4 , int V_24 )
{
struct V_1 * V_2 = NULL ;
struct V_46 * V_16 ;
int V_216 ;
V_16 = F_88 ( sizeof( struct V_1 ) , V_4 -> V_42 ) ;
if ( V_16 == NULL )
return - V_217 ;
V_2 = F_25 ( V_16 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_16 = V_16 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_22 = & V_4 -> V_22 -> V_38 [ V_24 ] ;
V_4 -> V_38 [ V_24 ] = V_2 ;
V_16 -> V_218 = 0 ;
if ( V_4 -> V_22 -> V_38 [ V_24 ] . V_219 >= 4 )
V_16 -> V_218 |= V_220 | V_221 ;
V_16 -> V_222 = & V_223 ;
V_16 -> V_224 = 400000 ;
if ( F_83 () )
V_16 -> V_225 = 48000000 ;
else
V_16 -> V_225 = 24000000 ;
if ( V_4 -> V_22 -> V_226 )
V_16 -> V_225 = F_89 ( V_4 -> V_22 -> V_226 , V_16 -> V_225 ) ;
V_16 -> V_227 = V_2 -> V_22 -> V_228 ;
V_16 -> V_229 = 32 ;
V_16 -> V_230 = 2048 ;
V_16 -> V_231 = 2048 ;
V_16 -> V_232 = V_16 -> V_230 * V_16 -> V_231 ;
V_16 -> V_233 = V_16 -> V_232 ;
if ( V_2 -> V_22 -> V_40 != NULL ) {
F_90 ( & V_2 -> V_160 , F_65 ,
( unsigned long ) V_2 ) ;
F_91 ( & V_2 -> V_157 , F_67 ,
( unsigned long ) V_2 ) ;
}
V_216 = F_92 ( V_16 ) ;
if ( V_216 < 0 )
goto V_234;
if ( V_2 -> V_22 -> V_48 != NULL ) {
V_216 = F_93 ( & V_16 -> V_47 ,
& V_235 ) ;
if ( V_216 < 0 )
goto V_234;
}
if ( V_2 -> V_22 -> V_40 != NULL ) {
V_216 = F_93 ( & V_16 -> V_47 ,
& V_236 ) ;
if ( V_216 < 0 )
goto V_237;
F_66 ( & V_2 -> V_157 ) ;
}
return 0 ;
V_237:
if ( V_2 -> V_22 -> V_48 != NULL )
F_94 ( & V_16 -> V_47 , & V_235 ) ;
V_234:
F_95 ( V_16 ) ;
F_96 ( V_16 ) ;
return V_216 ;
}
static void F_97 ( struct V_1 * V_2 )
{
struct V_46 * V_16 = V_2 -> V_16 ;
if ( V_2 -> V_22 -> V_48 != NULL )
F_94 ( & V_16 -> V_47 , & V_235 ) ;
if ( V_2 -> V_22 -> V_40 != NULL )
F_94 ( & V_16 -> V_47 , & V_236 ) ;
F_98 ( & V_2 -> V_157 ) ;
F_99 ( & V_2 -> V_160 ) ;
F_100 ( V_2 -> V_4 -> V_39 ) ;
F_95 ( V_16 ) ;
F_96 ( V_16 ) ;
}
static int F_101 ( struct V_238 * V_239 )
{
struct V_240 * V_22 = V_239 -> V_42 . V_241 ;
struct V_8 * V_4 = NULL ;
struct V_242 * V_145 ;
T_5 V_243 ;
unsigned V_244 = 0 ;
int V_33 , V_245 = 0 ;
int V_131 ;
if ( V_22 == NULL ) {
F_29 ( & V_239 -> V_42 , L_33 ) ;
return - V_246 ;
}
if ( V_22 -> V_36 == 0 ) {
F_29 ( & V_239 -> V_42 , L_34 ) ;
return - V_247 ;
}
V_4 = F_102 ( & V_239 -> V_42 , sizeof( struct V_8 ) ,
V_248 ) ;
if ( V_4 == NULL )
return - V_217 ;
V_131 = F_103 ( V_239 , 0 ) ;
if ( V_131 < 0 )
return - V_246 ;
V_145 = F_104 ( V_239 , V_249 , 0 ) ;
V_4 -> V_141 = F_105 ( & V_239 -> V_42 , V_145 ) ;
if ( F_106 ( V_4 -> V_141 ) )
return F_107 ( V_4 -> V_141 ) ;
F_108 ( & V_4 -> V_27 , F_15 ) ;
F_108 ( & V_4 -> V_102 , F_34 ) ;
F_108 ( & V_4 -> V_129 , F_43 ) ;
F_90 ( & V_4 -> V_73 , F_46 ,
( unsigned long ) V_4 ) ;
F_109 ( & V_4 -> V_11 ) ;
F_90 ( & V_4 -> V_18 , F_50 , ( unsigned long ) V_4 ) ;
F_109 ( & V_4 -> V_115 ) ;
F_109 ( & V_4 -> V_15 ) ;
F_110 ( & V_4 -> V_17 ) ;
V_4 -> V_22 = V_22 ;
V_4 -> V_250 = V_4 -> V_22 -> V_38 [ 0 ] . V_250 ;
V_4 -> V_42 = & V_239 -> V_42 ;
F_111 ( V_239 , V_4 ) ;
V_4 -> V_24 = V_239 -> V_24 ;
V_4 -> V_131 = V_131 ;
V_4 -> V_187 = V_145 -> V_251 ;
V_4 -> V_252 = F_112 ( & V_239 -> V_42 , L_35 ) ;
if ( F_106 ( V_4 -> V_252 ) )
return F_107 ( V_4 -> V_252 ) ;
F_6 ( V_4 -> V_252 ) ;
V_4 -> V_12 = F_112 ( & V_239 -> V_42 , L_36 ) ;
if ( F_106 ( V_4 -> V_12 ) ) {
V_245 = F_107 ( V_4 -> V_12 ) ;
goto V_253;
}
F_113 ( V_243 ) ;
F_114 ( V_254 , V_243 ) ;
V_4 -> V_181 = - 1 ;
V_4 -> V_182 = - 1 ;
V_145 = F_115 ( V_239 , V_255 , L_37 ) ;
if ( V_145 )
V_244 = V_145 -> V_251 ;
V_4 -> V_96 = F_116 ( V_243 ,
V_256 , & V_244 , & V_239 -> V_42 , L_37 ) ;
if ( ! V_4 -> V_96 )
F_117 ( V_4 -> V_42 , L_38 ,
V_244 ) ;
V_145 = F_115 ( V_239 , V_255 , L_39 ) ;
if ( V_145 )
V_244 = V_145 -> V_251 ;
V_4 -> V_98 = F_116 ( V_243 ,
V_256 , & V_244 , & V_239 -> V_42 , L_39 ) ;
if ( ! V_4 -> V_98 )
F_117 ( V_4 -> V_42 , L_40 ,
V_244 ) ;
V_245 = F_118 ( V_4 -> V_131 , F_58 , 0 , V_257 , V_4 ) ;
if ( V_245 )
goto V_258;
if ( V_22 -> V_259 != NULL ) {
V_245 = V_22 -> V_259 ( & V_239 -> V_42 ) ;
if ( V_245 < 0 )
goto V_260;
}
V_4 -> V_36 = V_22 -> V_36 ;
V_4 -> V_261 = ( F_119 () ? 1 : 2 ) ;
V_4 -> V_39 = F_120 ( L_41 , 0 , 0 ) ;
if ( ! V_4 -> V_39 )
goto V_262;
for ( V_33 = 0 ; V_33 < V_22 -> V_36 ; V_33 ++ ) {
V_245 = F_87 ( V_4 , V_33 ) ;
if ( V_245 < 0 ) {
while ( -- V_33 >= 0 )
F_97 ( V_4 -> V_38 [ V_33 ] ) ;
goto V_263;
}
}
return 0 ;
V_263:
F_121 ( V_4 -> V_39 ) ;
V_262:
if ( V_22 -> V_264 )
V_22 -> V_264 ( & V_239 -> V_42 ) ;
V_260:
F_122 ( V_4 -> V_131 , V_4 ) ;
V_258:
if ( V_4 -> V_96 )
F_123 ( V_4 -> V_96 ) ;
if ( V_4 -> V_98 )
F_123 ( V_4 -> V_98 ) ;
F_124 ( V_4 -> V_12 ) ;
V_253:
F_7 ( V_4 -> V_252 ) ;
F_124 ( V_4 -> V_252 ) ;
return V_245 ;
}
static int F_125 ( struct V_238 * V_239 )
{
struct V_8 * V_4 = F_126 ( V_239 ) ;
int V_33 ;
F_19 ( V_4 == NULL ) ;
for ( V_33 = 0 ; V_33 < V_4 -> V_36 ; V_33 ++ )
F_97 ( V_4 -> V_38 [ V_33 ] ) ;
if ( V_4 -> V_22 -> V_264 )
V_4 -> V_22 -> V_264 ( & V_239 -> V_42 ) ;
F_4 ( V_4 , 0 ) ;
F_122 ( V_4 -> V_131 , V_4 ) ;
F_124 ( V_4 -> V_12 ) ;
F_7 ( V_4 -> V_252 ) ;
F_124 ( V_4 -> V_252 ) ;
if ( V_4 -> V_96 )
F_123 ( V_4 -> V_96 ) ;
if ( V_4 -> V_98 )
F_123 ( V_4 -> V_98 ) ;
F_121 ( V_4 -> V_39 ) ;
return 0 ;
}
