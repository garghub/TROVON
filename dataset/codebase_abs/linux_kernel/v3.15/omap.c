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
T_3 V_53 ;
V_4 -> V_49 = V_49 ;
V_51 = 0 ;
V_52 = 0 ;
switch ( F_27 ( V_49 ) ) {
case V_54 :
break;
case V_55 :
case V_56 :
V_51 = 1 ;
break;
case V_57 :
V_51 = 2 ;
break;
case V_58 :
V_51 = 3 ;
break;
default:
F_28 ( F_12 ( V_4 -> V_15 ) , L_4 , F_27 ( V_49 ) ) ;
break;
}
if ( F_29 ( V_49 ) == V_59 ) {
V_52 = V_60 ;
} else if ( F_29 ( V_49 ) == V_61 ) {
V_52 = V_62 ;
} else if ( F_29 ( V_49 ) == V_63 ) {
V_52 = V_64 ;
} else {
V_52 = V_65 ;
}
V_50 = V_49 -> V_66 | ( V_51 << 8 ) | ( V_52 << 12 ) ;
if ( V_4 -> V_18 -> V_67 == V_68 )
V_50 |= 1 << 6 ;
if ( V_49 -> V_9 & V_69 )
V_50 |= 1 << 11 ;
if ( V_4 -> V_70 && ! ( V_4 -> V_70 -> V_9 & V_71 ) )
V_50 |= 1 << 15 ;
F_19 ( & V_4 -> V_72 , V_33 + V_34 / 2 ) ;
F_11 ( V_4 , V_73 , 200 ) ;
F_11 ( V_4 , V_74 , V_49 -> V_75 & 0xffff ) ;
F_11 ( V_4 , V_76 , V_49 -> V_75 >> 16 ) ;
V_53 = V_77 | V_78 |
V_79 | V_80 |
V_81 | V_82 |
V_83 | V_84 |
V_85 ;
if ( V_49 -> V_66 == V_86 )
V_53 &= ~ V_82 ;
F_11 ( V_4 , V_87 , V_53 ) ;
F_11 ( V_4 , V_88 , V_50 ) ;
}
static void
F_30 ( struct V_7 * V_4 , struct V_89 * V_70 ,
int abort )
{
enum V_90 V_91 ;
struct V_40 * V_41 = F_12 ( V_4 -> V_15 ) ;
struct V_92 * V_93 ;
if ( V_70 -> V_9 & V_71 ) {
V_91 = V_94 ;
V_93 = V_4 -> V_95 ;
} else {
V_91 = V_96 ;
V_93 = V_4 -> V_97 ;
}
if ( V_93 ) {
if ( V_70 -> error ) {
F_31 ( V_93 ) ;
V_70 -> V_98 = 0 ;
}
V_41 = V_93 -> V_40 -> V_41 ;
}
F_32 ( V_41 , V_70 -> V_99 , V_4 -> V_100 , V_91 ) ;
}
static void F_33 ( struct V_24 * V_25 )
{
struct V_7 * V_4 = F_15 ( V_25 , struct V_7 ,
V_101 ) ;
struct V_1 * V_2 = V_4 -> V_18 ;
struct V_89 * V_70 = V_4 -> V_102 ;
unsigned long V_3 ;
V_3 = ( 1000000000 + V_2 -> V_6 - 1 ) / V_2 -> V_6 ;
F_2 ( 8 * V_3 ) ;
F_26 ( V_4 , V_70 -> V_103 ) ;
}
static void
F_34 ( struct V_7 * V_4 , struct V_89 * V_70 )
{
if ( V_4 -> V_104 )
F_30 ( V_4 , V_70 , V_70 -> error ) ;
V_4 -> V_70 = NULL ;
V_4 -> V_100 = 0 ;
if ( ! V_70 -> V_103 ) {
struct V_45 * V_15 ;
V_4 -> V_30 = NULL ;
V_15 = V_4 -> V_15 ;
F_17 ( V_4 -> V_18 , 1 ) ;
F_35 ( V_15 , V_70 -> V_30 ) ;
return;
}
V_4 -> V_102 = V_70 ;
F_20 ( V_4 -> V_38 , & V_4 -> V_101 ) ;
}
static void
F_36 ( struct V_7 * V_4 , int V_105 )
{
struct V_1 * V_2 = V_4 -> V_18 ;
unsigned int V_106 , V_107 , V_108 ;
T_3 V_109 = 0 ;
V_108 = ( 120 * 1000000 + V_2 -> V_6 - 1 ) / V_2 -> V_6 ;
V_106 = 0 ;
while ( V_106 < V_105 ) {
F_11 ( V_4 , V_110 , 0xFFFF ) ;
F_11 ( V_4 , V_88 , ( 3 << 12 ) | ( 1 << 7 ) ) ;
V_107 = 0 ;
while ( V_107 < V_108 ) {
V_109 = F_13 ( V_4 , V_110 ) ;
if ( V_109 & V_83 )
goto V_111;
F_37 ( 1 ) ;
V_107 ++ ;
}
V_106 ++ ;
}
V_111:
F_11 ( V_4 , V_110 , V_109 ) ;
}
static void
F_38 ( struct V_7 * V_4 , struct V_89 * V_70 )
{
if ( V_4 -> V_104 )
F_30 ( V_4 , V_70 , 1 ) ;
V_4 -> V_70 = NULL ;
V_4 -> V_100 = 0 ;
F_36 ( V_4 , 10000 ) ;
}
static void
F_39 ( struct V_7 * V_4 , struct V_89 * V_70 )
{
unsigned long V_9 ;
int V_112 ;
if ( ! V_4 -> V_104 ) {
F_34 ( V_4 , V_70 ) ;
return;
}
V_112 = 0 ;
F_4 ( & V_4 -> V_113 , V_9 ) ;
if ( V_4 -> V_114 )
V_112 = 1 ;
else
V_4 -> V_115 = 1 ;
F_7 ( & V_4 -> V_113 , V_9 ) ;
if ( V_112 )
F_34 ( V_4 , V_70 ) ;
}
static void
F_40 ( struct V_7 * V_4 , struct V_89 * V_70 )
{
unsigned long V_9 ;
int V_112 ;
V_112 = 0 ;
F_4 ( & V_4 -> V_113 , V_9 ) ;
if ( V_4 -> V_115 )
V_112 = 1 ;
else
V_4 -> V_114 = 1 ;
F_7 ( & V_4 -> V_113 , V_9 ) ;
if ( V_112 )
F_34 ( V_4 , V_70 ) ;
}
static void
F_41 ( struct V_7 * V_4 , struct V_48 * V_49 )
{
V_4 -> V_49 = NULL ;
F_10 ( & V_4 -> V_72 ) ;
if ( V_49 -> V_9 & V_116 ) {
if ( V_49 -> V_9 & V_117 ) {
V_49 -> V_118 [ 3 ] =
F_13 ( V_4 , V_119 ) |
( F_13 ( V_4 , V_120 ) << 16 ) ;
V_49 -> V_118 [ 2 ] =
F_13 ( V_4 , V_121 ) |
( F_13 ( V_4 , V_122 ) << 16 ) ;
V_49 -> V_118 [ 1 ] =
F_13 ( V_4 , V_123 ) |
( F_13 ( V_4 , V_124 ) << 16 ) ;
V_49 -> V_118 [ 0 ] =
F_13 ( V_4 , V_125 ) |
( F_13 ( V_4 , V_126 ) << 16 ) ;
} else {
V_49 -> V_118 [ 0 ] =
F_13 ( V_4 , V_125 ) |
( F_13 ( V_4 , V_126 ) << 16 ) ;
}
}
if ( V_4 -> V_70 == NULL || V_49 -> error ) {
struct V_45 * V_15 ;
if ( V_4 -> V_70 != NULL )
F_38 ( V_4 , V_4 -> V_70 ) ;
V_4 -> V_30 = NULL ;
V_15 = V_4 -> V_15 ;
F_17 ( V_4 -> V_18 , 1 ) ;
F_35 ( V_15 , V_49 -> V_30 ) ;
}
}
static void F_42 ( struct V_24 * V_25 )
{
struct V_7 * V_4 = F_15 ( V_25 , struct V_7 ,
V_127 ) ;
F_18 ( ! V_4 -> V_49 ) ;
F_43 ( F_12 ( V_4 -> V_15 ) , L_5 ,
V_4 -> V_49 -> V_66 ) ;
if ( V_4 -> V_49 -> error == 0 )
V_4 -> V_49 -> error = - V_128 ;
if ( V_4 -> V_70 == NULL ) {
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
F_44 ( V_4 -> V_129 ) ;
}
static void
F_45 ( unsigned long V_70 )
{
struct V_7 * V_4 = (struct V_7 * ) V_70 ;
unsigned long V_9 ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
if ( V_4 -> V_49 != NULL && ! V_4 -> abort ) {
F_11 ( V_4 , V_87 , 0 ) ;
F_46 ( V_4 -> V_129 ) ;
V_4 -> abort = 1 ;
F_20 ( V_4 -> V_38 , & V_4 -> V_127 ) ;
}
F_7 ( & V_4 -> V_14 , V_9 ) ;
}
static void
F_47 ( struct V_7 * V_4 )
{
struct V_130 * V_99 ;
V_99 = V_4 -> V_70 -> V_99 + V_4 -> V_131 ;
V_4 -> V_132 = V_99 -> V_133 ;
V_4 -> V_134 = F_48 ( V_99 ) ;
if ( V_4 -> V_132 > V_4 -> V_135 )
V_4 -> V_132 = V_4 -> V_135 ;
}
static void
F_49 ( unsigned long V_70 )
{
struct V_7 * V_4 = (struct V_7 * ) V_70 ;
F_3 ( V_4 , 0 ) ;
}
static void
F_50 ( struct V_7 * V_4 , int V_136 )
{
int V_137 , V_138 ;
if ( V_4 -> V_132 == 0 ) {
V_4 -> V_131 ++ ;
F_18 ( V_4 -> V_131 == V_4 -> V_100 ) ;
F_47 ( V_4 ) ;
}
V_137 = 64 ;
if ( V_137 > V_4 -> V_132 )
V_137 = V_4 -> V_132 ;
V_138 = V_137 / 2 ;
V_138 += V_137 & 1 ;
V_4 -> V_132 -= V_137 ;
V_4 -> V_135 -= V_137 ;
V_4 -> V_70 -> V_98 += V_137 ;
if ( V_136 ) {
F_51 ( V_4 -> V_139 + F_52 ( V_4 , V_140 ) ,
V_4 -> V_134 , V_138 ) ;
} else {
F_53 ( V_4 -> V_139 + F_52 ( V_4 , V_140 ) ,
V_4 -> V_134 , V_138 ) ;
}
V_4 -> V_134 += V_138 ;
}
static void F_54 ( struct V_7 * V_4 , T_3 V_141 )
{
static const char * V_142 [] = {
L_6 , L_7 , L_8 , L_9 , L_10 , L_11 , L_12 , L_13 ,
L_14 , L_15 , L_16 , L_17 , L_18 , L_19 , L_20
} ;
int V_32 ;
char V_143 [ 64 ] , * V_44 = V_143 ;
V_44 += sprintf ( V_44 , L_21 , V_141 ) ;
for ( V_32 = 0 ; V_32 < F_55 ( V_142 ) ; V_32 ++ )
if ( V_141 & ( 1 << V_32 ) )
V_44 += sprintf ( V_44 , L_22 , V_142 [ V_32 ] ) ;
F_56 ( F_12 ( V_4 -> V_15 ) , L_1 , V_143 ) ;
}
static void F_54 ( struct V_7 * V_4 , T_3 V_141 )
{
}
static T_4 F_57 ( int V_129 , void * V_144 )
{
struct V_7 * V_4 = (struct V_7 * ) V_144 ;
T_3 V_141 ;
int V_145 ;
int V_146 ;
int V_147 , V_148 ;
if ( V_4 -> V_49 == NULL && V_4 -> V_70 == NULL ) {
V_141 = F_13 ( V_4 , V_110 ) ;
F_58 ( F_12 ( V_4 -> V_37 [ 0 ] -> V_15 ) ,
L_23 , V_141 ) ;
if ( V_141 != 0 ) {
F_11 ( V_4 , V_110 , V_141 ) ;
F_11 ( V_4 , V_87 , 0 ) ;
}
return V_149 ;
}
V_145 = 0 ;
V_146 = 0 ;
V_147 = 0 ;
V_148 = 0 ;
while ( ( V_141 = F_13 ( V_4 , V_110 ) ) != 0 ) {
int V_49 ;
F_11 ( V_4 , V_110 , V_141 ) ;
if ( V_4 -> V_49 != NULL )
V_49 = V_4 -> V_49 -> V_66 ;
else
V_49 = - 1 ;
F_43 ( F_12 ( V_4 -> V_15 ) , L_24 ,
V_141 , V_49 ) ;
F_54 ( V_4 , V_141 ) ;
if ( V_4 -> V_135 ) {
if ( ( V_141 & V_78 ) ||
( V_141 & V_85 ) )
F_50 ( V_4 , 0 ) ;
if ( V_141 & V_77 )
F_50 ( V_4 , 1 ) ;
}
if ( V_141 & V_85 )
V_146 = 1 ;
if ( V_141 & V_82 ) {
F_43 ( F_12 ( V_4 -> V_15 ) , L_25 ,
V_49 ) ;
if ( V_4 -> V_70 ) {
V_4 -> V_70 -> error = - V_128 ;
V_147 = 1 ;
}
}
if ( V_141 & V_81 ) {
if ( V_4 -> V_70 ) {
V_4 -> V_70 -> error = - V_150 ;
F_43 ( F_12 ( V_4 -> V_15 ) ,
L_26 ,
V_4 -> V_135 ) ;
V_147 = 1 ;
} else {
F_43 ( F_12 ( V_4 -> V_15 ) , L_27 ) ;
}
}
if ( V_141 & V_80 ) {
if ( V_4 -> V_49 ) {
struct V_1 * V_2 =
V_4 -> V_18 ;
if ( V_2 == NULL ||
! F_22 ( V_2 ) )
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_28 ,
V_49 ) ;
V_4 -> V_49 -> error = - V_128 ;
V_145 = 1 ;
V_148 = 1 ;
}
}
if ( V_141 & V_79 ) {
if ( V_4 -> V_49 ) {
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_29 ,
V_49 , V_4 -> V_49 -> V_75 ) ;
V_4 -> V_49 -> error = - V_150 ;
V_145 = 1 ;
V_148 = 1 ;
} else
F_28 ( F_12 ( V_4 -> V_15 ) ,
L_30 ) ;
}
if ( V_141 & V_84 ) {
F_43 ( F_12 ( V_4 -> V_15 ) ,
L_31 ,
V_49 ) ;
V_145 = 1 ;
}
if ( ( V_141 & V_83 ) &&
( ! ( V_141 & V_77 ) ) ) {
V_145 = 1 ;
}
}
if ( V_148 && V_4 -> V_70 ) {
F_10 ( & V_4 -> V_72 ) ;
V_4 -> abort = 1 ;
F_11 ( V_4 , V_87 , 0 ) ;
F_59 ( V_4 -> V_129 ) ;
F_20 ( V_4 -> V_38 , & V_4 -> V_127 ) ;
return V_149 ;
}
if ( V_145 && V_4 -> V_49 )
F_41 ( V_4 , V_4 -> V_49 ) ;
if ( V_4 -> V_70 != NULL ) {
if ( V_147 )
F_34 ( V_4 , V_4 -> V_70 ) ;
else if ( V_146 )
F_39 ( V_4 , V_4 -> V_70 ) ;
}
return V_149 ;
}
void F_60 ( struct V_40 * V_41 , int V_151 , int V_152 )
{
int V_153 ;
struct V_7 * V_4 = F_61 ( V_41 ) ;
struct V_1 * V_2 = V_4 -> V_37 [ V_151 ] ;
F_18 ( V_151 >= V_4 -> V_35 ) ;
if ( V_4 -> V_35 == 0 || ! V_4 -> V_37 [ V_151 ] )
return;
V_153 = F_22 ( V_2 ) ;
if ( V_153 != V_2 -> V_153 ) {
V_2 -> V_153 = V_153 ;
F_62 ( & V_2 -> V_15 -> V_46 . V_154 , NULL , L_32 ) ;
}
F_63 ( & V_2 -> V_155 ) ;
}
static void F_64 ( unsigned long V_75 )
{
struct V_1 * V_2 = (struct V_1 * ) V_75 ;
F_65 ( & V_2 -> V_155 ) ;
}
static void F_66 ( unsigned long V_156 )
{
struct V_1 * V_2 = (struct V_1 * ) V_156 ;
int V_153 = F_22 ( V_2 ) ;
F_67 ( V_2 -> V_15 , 0 ) ;
if ( ! V_153 )
return;
if ( V_2 -> V_15 -> V_157 == NULL || ! F_68 ( V_2 -> V_15 -> V_157 ) )
return;
F_19 ( & V_2 -> V_158 ,
V_33 + F_69 ( V_159 ) ) ;
}
static void F_70 ( void * V_160 )
{
struct V_7 * V_4 = V_160 ;
struct V_89 * V_70 = V_4 -> V_70 ;
V_70 -> V_98 += V_70 -> V_161 * V_70 -> V_162 ;
F_40 ( V_4 , V_70 ) ;
}
static inline void F_71 ( struct V_7 * V_4 , struct V_28 * V_163 )
{
T_3 V_164 ;
V_164 = F_13 ( V_4 , V_165 ) ;
V_164 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_165 , V_164 ) ;
F_11 ( V_4 , V_73 , 0xff ) ;
}
static inline void F_72 ( struct V_7 * V_4 , struct V_28 * V_163 )
{
unsigned int V_108 , V_166 ;
T_3 V_164 ;
V_166 = 1000000000 / V_4 -> V_18 -> V_6 ;
V_108 = V_163 -> V_70 -> V_167 / V_166 ;
V_108 += V_163 -> V_70 -> V_168 ;
V_164 = F_13 ( V_4 , V_165 ) ;
if ( V_108 > 0xffff ) {
V_164 |= ( 1 << 5 ) ;
V_108 /= 1024 ;
} else
V_164 &= ~ ( 1 << 5 ) ;
F_11 ( V_4 , V_165 , V_164 ) ;
F_11 ( V_4 , V_169 , V_108 ) ;
}
static void
F_73 ( struct V_7 * V_4 , struct V_28 * V_163 )
{
struct V_89 * V_70 = V_163 -> V_70 ;
int V_32 , V_170 = 1 , V_171 ;
unsigned V_100 ;
V_4 -> V_70 = V_70 ;
if ( V_70 == NULL ) {
F_11 ( V_4 , V_172 , 0 ) ;
F_11 ( V_4 , V_173 , 0 ) ;
F_11 ( V_4 , V_174 , 0 ) ;
V_4 -> V_104 = 0 ;
F_71 ( V_4 , V_163 ) ;
return;
}
V_171 = V_70 -> V_162 ;
F_11 ( V_4 , V_173 , V_70 -> V_161 - 1 ) ;
F_11 ( V_4 , V_172 , V_171 - 1 ) ;
F_72 ( V_4 , V_163 ) ;
V_100 = ( V_70 -> V_161 == 1 ) ? 1 : V_70 -> V_100 ;
for ( V_32 = 0 ; V_32 < V_100 ; V_32 ++ ) {
if ( ( V_70 -> V_99 [ V_32 ] . V_133 % V_171 ) != 0 ) {
V_170 = 0 ;
break;
}
}
V_4 -> V_131 = 0 ;
if ( V_170 ) {
enum V_90 V_91 ;
struct V_175 * V_176 ;
struct V_92 * V_93 ;
T_2 V_177 , * V_178 ;
T_3 V_44 ;
V_177 = F_74 () ? 32 : 64 ;
if ( V_177 > V_70 -> V_162 )
V_177 = V_70 -> V_162 ;
V_177 >>= 1 ;
if ( V_70 -> V_9 & V_71 ) {
V_93 = V_4 -> V_95 ;
V_178 = & V_4 -> V_179 ;
V_44 = 0x0f80 | ( V_177 - 1 ) << 0 ;
V_91 = V_94 ;
} else {
V_93 = V_4 -> V_97 ;
V_178 = & V_4 -> V_180 ;
V_44 = 0x800f | ( V_177 - 1 ) << 8 ;
V_91 = V_96 ;
}
if ( ! V_93 )
goto V_181;
if ( * V_178 != V_177 ) {
struct V_182 V_183 ;
V_183 . V_184 = V_4 -> V_185 + F_52 ( V_4 , V_140 ) ;
V_183 . V_186 = V_4 -> V_185 + F_52 ( V_4 , V_140 ) ;
V_183 . V_187 = V_188 ;
V_183 . V_189 = V_188 ;
V_183 . V_190 = V_177 ;
V_183 . V_191 = V_177 ;
if ( F_75 ( V_93 , & V_183 ) )
goto V_181;
* V_178 = V_177 ;
}
V_4 -> V_100 = F_76 ( V_93 -> V_40 -> V_41 , V_70 -> V_99 , V_100 ,
V_91 ) ;
if ( V_4 -> V_100 == 0 )
goto V_181;
V_176 = F_77 ( V_93 , V_70 -> V_99 , V_4 -> V_100 ,
V_70 -> V_9 & V_71 ? V_192 : V_193 ,
V_194 | V_195 ) ;
if ( ! V_176 )
goto V_181;
F_11 ( V_4 , V_174 , V_44 ) ;
V_176 -> V_196 = F_70 ;
V_176 -> V_197 = V_4 ;
F_78 ( V_176 ) ;
V_4 -> V_115 = 0 ;
V_4 -> V_114 = 0 ;
V_4 -> V_104 = 1 ;
return;
}
V_181:
F_11 ( V_4 , V_174 , 0x1f1f ) ;
V_4 -> V_135 = V_70 -> V_161 * V_171 ;
V_4 -> V_100 = V_100 ;
F_47 ( V_4 ) ;
V_4 -> V_104 = 0 ;
}
static void F_16 ( struct V_7 * V_4 ,
struct V_28 * V_163 )
{
F_18 ( V_4 -> V_30 != NULL ) ;
V_4 -> V_30 = V_163 ;
F_73 ( V_4 , V_163 ) ;
F_26 ( V_4 , V_163 -> V_49 ) ;
if ( V_4 -> V_104 ) {
struct V_92 * V_93 = V_4 -> V_70 -> V_9 & V_71 ?
V_4 -> V_95 : V_4 -> V_97 ;
F_79 ( V_93 ) ;
}
}
static void F_80 ( struct V_45 * V_15 , struct V_28 * V_163 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
unsigned long V_9 ;
F_4 ( & V_4 -> V_14 , V_9 ) ;
if ( V_4 -> V_15 != NULL ) {
F_18 ( V_2 -> V_30 != NULL ) ;
V_2 -> V_30 = V_163 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
return;
} else
V_4 -> V_15 = V_15 ;
F_7 ( & V_4 -> V_14 , V_9 ) ;
F_8 ( V_2 , 1 ) ;
F_16 ( V_4 , V_163 ) ;
}
static void F_81 ( struct V_1 * V_2 , int V_198 ,
int V_199 )
{
struct V_7 * V_4 ;
V_4 = V_2 -> V_4 ;
if ( V_2 -> V_21 -> V_200 != NULL )
V_2 -> V_21 -> V_200 ( F_12 ( V_2 -> V_15 ) , V_2 -> V_23 , V_198 ,
V_199 ) ;
if ( F_82 () ) {
T_3 V_201 ;
if ( V_198 ) {
V_201 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_201 | ( 1 << 11 ) ) ;
} else {
V_201 = F_13 ( V_4 , V_19 ) ;
F_11 ( V_4 , V_19 , V_201 & ~ ( 1 << 11 ) ) ;
}
}
}
static int F_83 ( struct V_45 * V_15 , struct V_202 * V_203 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_204 = F_84 ( V_4 -> V_11 ) ;
int V_205 ;
if ( V_203 -> clock == 0 )
return 0 ;
V_205 = V_204 / V_203 -> clock ;
if ( V_205 < 1 )
V_205 = 1 ;
if ( V_204 / V_205 > V_203 -> clock )
V_205 ++ ;
if ( V_205 > 250 )
V_205 = 250 ;
V_2 -> V_6 = V_204 / V_205 ;
if ( V_203 -> V_206 == V_207 )
V_205 |= 1 << 15 ;
return V_205 ;
}
static void F_85 ( struct V_45 * V_15 , struct V_202 * V_203 )
{
struct V_1 * V_2 = F_24 ( V_15 ) ;
struct V_7 * V_4 = V_2 -> V_4 ;
int V_32 , V_205 ;
int V_31 ;
F_8 ( V_2 , 0 ) ;
V_205 = F_83 ( V_15 , V_203 ) ;
if ( V_203 -> V_199 != V_2 -> V_199 )
V_2 -> V_199 = V_203 -> V_199 ;
V_31 = 0 ;
switch ( V_203 -> V_208 ) {
case V_209 :
F_81 ( V_2 , 0 , V_203 -> V_199 ) ;
break;
case V_210 :
F_81 ( V_2 , 1 , V_203 -> V_199 ) ;
goto exit;
case V_211 :
F_3 ( V_4 , 1 ) ;
V_31 = 1 ;
V_205 |= 1 << 11 ;
break;
}
if ( V_2 -> V_67 != V_203 -> V_67 ) {
if ( V_2 -> V_21 -> V_212 != NULL )
V_2 -> V_21 -> V_212 ( F_12 ( V_15 ) , V_2 -> V_23 ,
V_203 -> V_67 ) ;
V_2 -> V_67 = V_203 -> V_67 ;
}
for ( V_32 = 0 ; V_32 < 2 ; V_32 ++ )
F_11 ( V_4 , V_19 , V_205 ) ;
V_2 -> V_20 = V_205 ;
if ( V_203 -> V_208 == V_211 ) {
int V_213 = 250 ;
F_11 ( V_4 , V_87 , 0 ) ;
F_11 ( V_4 , V_110 , 0xffff ) ;
F_11 ( V_4 , V_88 , 1 << 7 ) ;
while ( V_213 > 0 && ( F_13 ( V_4 , V_110 ) & 1 ) == 0 ) {
F_37 ( 1 ) ;
V_213 -- ;
}
F_11 ( V_4 , V_110 , 1 ) ;
}
exit:
F_17 ( V_2 , V_31 ) ;
}
static int F_86 ( struct V_7 * V_4 , int V_23 )
{
struct V_1 * V_2 = NULL ;
struct V_45 * V_15 ;
int V_214 ;
V_15 = F_87 ( sizeof( struct V_1 ) , V_4 -> V_41 ) ;
if ( V_15 == NULL )
return - V_215 ;
V_2 = F_24 ( V_15 ) ;
V_2 -> V_4 = V_4 ;
V_2 -> V_15 = V_15 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_21 = & V_4 -> V_21 -> V_37 [ V_23 ] ;
V_4 -> V_37 [ V_23 ] = V_2 ;
V_15 -> V_216 = 0 ;
if ( V_4 -> V_21 -> V_37 [ V_23 ] . V_217 >= 4 )
V_15 -> V_216 |= V_218 | V_219 ;
V_15 -> V_220 = & V_221 ;
V_15 -> V_222 = 400000 ;
if ( F_82 () )
V_15 -> V_223 = 48000000 ;
else
V_15 -> V_223 = 24000000 ;
if ( V_4 -> V_21 -> V_224 )
V_15 -> V_223 = F_88 ( V_4 -> V_21 -> V_224 , V_15 -> V_223 ) ;
V_15 -> V_225 = V_2 -> V_21 -> V_226 ;
V_15 -> V_227 = 32 ;
V_15 -> V_228 = 2048 ;
V_15 -> V_229 = 2048 ;
V_15 -> V_230 = V_15 -> V_228 * V_15 -> V_229 ;
V_15 -> V_231 = V_15 -> V_230 ;
if ( V_2 -> V_21 -> V_39 != NULL ) {
F_89 ( & V_2 -> V_158 , F_64 ,
( unsigned long ) V_2 ) ;
F_90 ( & V_2 -> V_155 , F_66 ,
( unsigned long ) V_2 ) ;
}
V_214 = F_91 ( V_15 ) ;
if ( V_214 < 0 )
goto V_232;
if ( V_2 -> V_21 -> V_47 != NULL ) {
V_214 = F_92 ( & V_15 -> V_46 ,
& V_233 ) ;
if ( V_214 < 0 )
goto V_232;
}
if ( V_2 -> V_21 -> V_39 != NULL ) {
V_214 = F_92 ( & V_15 -> V_46 ,
& V_234 ) ;
if ( V_214 < 0 )
goto V_235;
F_65 ( & V_2 -> V_155 ) ;
}
return 0 ;
V_235:
if ( V_2 -> V_21 -> V_47 != NULL )
F_93 ( & V_15 -> V_46 , & V_233 ) ;
V_232:
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
return V_214 ;
}
static void F_96 ( struct V_1 * V_2 )
{
struct V_45 * V_15 = V_2 -> V_15 ;
if ( V_2 -> V_21 -> V_47 != NULL )
F_93 ( & V_15 -> V_46 , & V_233 ) ;
if ( V_2 -> V_21 -> V_39 != NULL )
F_93 ( & V_15 -> V_46 , & V_234 ) ;
F_97 ( & V_2 -> V_155 ) ;
F_98 ( & V_2 -> V_158 ) ;
F_99 ( V_2 -> V_4 -> V_38 ) ;
F_94 ( V_15 ) ;
F_95 ( V_15 ) ;
}
static int F_100 ( struct V_236 * V_237 )
{
struct V_238 * V_21 = V_237 -> V_41 . V_239 ;
struct V_7 * V_4 = NULL ;
struct V_240 * V_143 ;
T_5 V_241 ;
unsigned V_242 = 0 ;
int V_32 , V_243 = 0 ;
int V_129 ;
if ( V_21 == NULL ) {
F_28 ( & V_237 -> V_41 , L_33 ) ;
return - V_244 ;
}
if ( V_21 -> V_35 == 0 ) {
F_28 ( & V_237 -> V_41 , L_34 ) ;
return - V_245 ;
}
V_4 = F_101 ( & V_237 -> V_41 , sizeof( struct V_7 ) ,
V_246 ) ;
if ( V_4 == NULL )
return - V_215 ;
V_129 = F_102 ( V_237 , 0 ) ;
if ( V_129 < 0 )
return - V_244 ;
V_143 = F_103 ( V_237 , V_247 , 0 ) ;
V_4 -> V_139 = F_104 ( & V_237 -> V_41 , V_143 ) ;
if ( F_105 ( V_4 -> V_139 ) )
return F_106 ( V_4 -> V_139 ) ;
F_107 ( & V_4 -> V_26 , F_14 ) ;
F_107 ( & V_4 -> V_101 , F_33 ) ;
F_107 ( & V_4 -> V_127 , F_42 ) ;
F_89 ( & V_4 -> V_72 , F_45 ,
( unsigned long ) V_4 ) ;
F_108 ( & V_4 -> V_10 ) ;
F_89 ( & V_4 -> V_17 , F_49 , ( unsigned long ) V_4 ) ;
F_108 ( & V_4 -> V_113 ) ;
F_108 ( & V_4 -> V_14 ) ;
F_109 ( & V_4 -> V_16 ) ;
V_4 -> V_21 = V_21 ;
V_4 -> V_248 = V_4 -> V_21 -> V_37 [ 0 ] . V_248 ;
V_4 -> V_41 = & V_237 -> V_41 ;
F_110 ( V_237 , V_4 ) ;
V_4 -> V_23 = V_237 -> V_23 ;
V_4 -> V_129 = V_129 ;
V_4 -> V_185 = V_143 -> V_249 ;
V_4 -> V_250 = F_111 ( & V_237 -> V_41 , L_35 ) ;
if ( F_105 ( V_4 -> V_250 ) )
return F_106 ( V_4 -> V_250 ) ;
F_5 ( V_4 -> V_250 ) ;
V_4 -> V_11 = F_111 ( & V_237 -> V_41 , L_36 ) ;
if ( F_105 ( V_4 -> V_11 ) ) {
V_243 = F_106 ( V_4 -> V_11 ) ;
goto V_251;
}
F_112 ( V_241 ) ;
F_113 ( V_252 , V_241 ) ;
V_4 -> V_179 = - 1 ;
V_4 -> V_180 = - 1 ;
V_143 = F_114 ( V_237 , V_253 , L_37 ) ;
if ( V_143 )
V_242 = V_143 -> V_249 ;
V_4 -> V_95 = F_115 ( V_241 ,
V_254 , & V_242 , & V_237 -> V_41 , L_37 ) ;
if ( ! V_4 -> V_95 )
F_116 ( V_4 -> V_41 , L_38 ,
V_242 ) ;
V_143 = F_114 ( V_237 , V_253 , L_39 ) ;
if ( V_143 )
V_242 = V_143 -> V_249 ;
V_4 -> V_97 = F_115 ( V_241 ,
V_254 , & V_242 , & V_237 -> V_41 , L_39 ) ;
if ( ! V_4 -> V_97 )
F_116 ( V_4 -> V_41 , L_40 ,
V_242 ) ;
V_243 = F_117 ( V_4 -> V_129 , F_57 , 0 , V_255 , V_4 ) ;
if ( V_243 )
goto V_256;
if ( V_21 -> V_257 != NULL ) {
V_243 = V_21 -> V_257 ( & V_237 -> V_41 ) ;
if ( V_243 < 0 )
goto V_258;
}
V_4 -> V_35 = V_21 -> V_35 ;
V_4 -> V_259 = ( F_118 () ? 1 : 2 ) ;
V_4 -> V_38 = F_119 ( L_41 , 0 , 0 ) ;
if ( ! V_4 -> V_38 )
goto V_260;
for ( V_32 = 0 ; V_32 < V_21 -> V_35 ; V_32 ++ ) {
V_243 = F_86 ( V_4 , V_32 ) ;
if ( V_243 < 0 ) {
while ( -- V_32 >= 0 )
F_96 ( V_4 -> V_37 [ V_32 ] ) ;
goto V_261;
}
}
return 0 ;
V_261:
F_120 ( V_4 -> V_38 ) ;
V_260:
if ( V_21 -> V_262 )
V_21 -> V_262 ( & V_237 -> V_41 ) ;
V_258:
F_121 ( V_4 -> V_129 , V_4 ) ;
V_256:
if ( V_4 -> V_95 )
F_122 ( V_4 -> V_95 ) ;
if ( V_4 -> V_97 )
F_122 ( V_4 -> V_97 ) ;
F_123 ( V_4 -> V_11 ) ;
V_251:
F_6 ( V_4 -> V_250 ) ;
F_123 ( V_4 -> V_250 ) ;
return V_243 ;
}
static int F_124 ( struct V_236 * V_237 )
{
struct V_7 * V_4 = F_125 ( V_237 ) ;
int V_32 ;
F_18 ( V_4 == NULL ) ;
for ( V_32 = 0 ; V_32 < V_4 -> V_35 ; V_32 ++ )
F_96 ( V_4 -> V_37 [ V_32 ] ) ;
if ( V_4 -> V_21 -> V_262 )
V_4 -> V_21 -> V_262 ( & V_237 -> V_41 ) ;
F_3 ( V_4 , 0 ) ;
F_121 ( V_4 -> V_129 , V_4 ) ;
F_123 ( V_4 -> V_11 ) ;
F_6 ( V_4 -> V_250 ) ;
F_123 ( V_4 -> V_250 ) ;
if ( V_4 -> V_95 )
F_122 ( V_4 -> V_95 ) ;
if ( V_4 -> V_97 )
F_122 ( V_4 -> V_97 ) ;
F_120 ( V_4 -> V_38 ) ;
return 0 ;
}
