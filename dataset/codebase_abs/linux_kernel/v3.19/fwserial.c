static inline void F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
if ( V_4 < V_3 ) {
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_1 ,
V_5 , V_3 , V_4 ) ;
}
}
static void F_6 ( struct V_1 * V_2 , unsigned * V_8 )
{
F_2 ( & V_2 -> V_6 ) ;
F_7 ( V_8 , F_3 ( & V_2 -> V_7 ) ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static void F_8 ( struct V_9 * V_10 , struct V_11 * V_11 )
{
int V_12 = 4 ;
unsigned V_13 ;
int V_14 ;
char V_15 [ 10 ] ;
snprintf ( V_15 , 10 , L_2 , 1 << V_12 ) ;
F_9 ( V_10 , L_3 , L_4 , V_15 ) ;
for ( V_14 = V_12 + 1 ; V_14 < V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , 1 << V_14 ) ;
++ V_12 ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_17 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_7 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_17 [ V_14 ] ) ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_18 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_8 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_18 [ V_14 ] ) ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_19 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_9 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_19 [ V_14 ] ) ;
for ( V_14 = 0 , V_13 = 0 ; V_14 <= V_12 ; ++ V_14 )
V_13 += V_11 -> V_20 [ V_14 ] ;
F_9 ( V_10 , L_6 , L_10 , V_13 ) ;
for ( V_14 = V_12 + 1 ; V_14 <= V_16 ; ++ V_14 )
F_9 ( V_10 , L_5 , V_11 -> V_20 [ V_14 ] ) ;
}
static inline int F_10 ( struct V_21 * V_21 )
{
return F_11 ( 2 << V_21 -> V_22 , 4096 ) ;
}
static void F_12 ( struct V_1 * V_2 , int V_23 )
{
switch ( V_23 ) {
case V_24 :
F_13 ( V_2 , L_11 ) ;
break;
case V_25 :
F_13 ( V_2 , L_12 ) ;
break;
case V_26 :
F_13 ( V_2 , L_13 ) ;
break;
case V_27 :
F_13 ( V_2 , L_14 ) ;
break;
case V_28 :
F_13 ( V_2 , L_15 ) ;
break;
default:
F_13 ( V_2 , L_16 , V_23 ) ;
}
}
static void F_14 ( void * V_29 )
{
struct V_30 * V_31 = V_29 ;
F_15 ( & V_31 -> V_32 . V_33 ) ;
}
static void F_16 ( struct V_34 * V_35 , int V_23 ,
void * V_36 , T_1 V_37 , void * V_38 )
{
struct V_30 * V_31 = V_38 ;
struct V_1 * V_2 = V_31 -> V_2 ;
if ( V_2 && V_23 != V_39 )
F_12 ( V_2 , V_23 ) ;
if ( V_31 -> V_40 )
V_31 -> V_40 ( V_35 , V_23 , V_36 , V_37 , V_31 ) ;
F_17 ( V_41 , V_31 ) ;
}
static int F_18 ( struct V_42 * V_43 , int V_44 ,
unsigned long long V_45 , void * V_36 ,
T_1 V_37 , T_2 V_40 ,
struct V_1 * V_2 )
{
struct V_30 * V_31 ;
int V_46 ;
V_31 = F_19 ( V_41 , V_47 ) ;
if ( ! V_31 )
return - V_48 ;
V_31 -> V_40 = V_40 ;
V_31 -> V_2 = V_2 ;
V_46 = V_43 -> V_46 ;
F_20 () ;
F_21 ( V_43 -> V_49 -> V_35 , & V_31 -> V_32 , V_44 ,
V_43 -> V_50 , V_46 , V_43 -> V_51 , V_45 , V_36 ,
V_37 , F_16 , V_31 ) ;
return 0 ;
}
static void F_22 ( struct V_42 * V_43 ,
struct V_30 * V_31 , int V_44 ,
unsigned long long V_45 , void * V_36 ,
T_1 V_37 , T_2 V_40 ,
struct V_1 * V_2 )
{
int V_46 ;
V_31 -> V_40 = V_40 ;
V_31 -> V_2 = V_2 ;
V_46 = V_43 -> V_46 ;
F_20 () ;
F_21 ( V_43 -> V_49 -> V_35 , & V_31 -> V_32 , V_44 ,
V_43 -> V_50 , V_46 , V_43 -> V_51 , V_45 , V_36 ,
V_37 , F_16 , V_31 ) ;
}
static void F_23 ( struct V_1 * V_2 )
{
int V_37 , V_5 ;
V_37 = F_24 ( & V_2 -> V_7 ) ;
if ( V_37 )
F_25 ( & V_2 -> V_52 , 0 ) ;
V_5 = F_3 ( & V_2 -> V_7 ) ;
F_5 ( V_2 , L_17 , V_37 , V_5 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_2 ( & V_2 -> V_6 ) ;
F_23 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static void F_27 ( struct V_1 * V_2 , unsigned V_53 )
{
unsigned V_54 ;
struct V_55 * V_56 ;
V_53 &= ~ V_57 ;
V_54 = ( V_2 -> V_58 ^ V_53 ) & ~ V_57 ;
V_54 &= ~ ( V_53 & V_59 ) ;
V_2 -> V_58 = V_53 ;
if ( V_54 & V_59 )
++ V_2 -> V_60 . V_61 ;
if ( V_54 & V_62 )
++ V_2 -> V_60 . V_63 ;
if ( V_54 & V_64 )
++ V_2 -> V_60 . V_65 ;
if ( V_54 & V_66 )
++ V_2 -> V_60 . V_67 ;
F_5 ( V_2 , L_18 , V_53 , V_54 ) ;
if ( V_54 & V_64 ) {
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 && ! F_29 ( V_56 ) ) {
if ( V_53 & V_64 )
F_30 ( & V_2 -> V_2 . V_68 ) ;
else
F_31 ( & V_2 -> V_69 ) ;
}
F_32 ( V_56 ) ;
}
if ( V_54 & V_66 ) {
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 && F_33 ( V_56 ) ) {
if ( V_56 -> V_70 ) {
if ( V_53 & V_66 ) {
V_56 -> V_70 = 0 ;
if ( V_2 -> V_71 )
F_23 ( V_2 ) ;
else
F_26 ( V_2 ) ;
}
} else {
if ( ~ V_53 & V_66 )
V_56 -> V_70 = 1 ;
}
}
F_32 ( V_56 ) ;
} else if ( V_54 & V_72 ) {
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 ) {
if ( V_56 -> V_70 ) {
if ( ~ V_53 & V_72 ) {
V_56 -> V_70 = 0 ;
if ( V_2 -> V_71 )
F_23 ( V_2 ) ;
else
F_26 ( V_2 ) ;
}
} else {
if ( V_53 & V_72 )
V_56 -> V_70 = 1 ;
}
}
F_32 ( V_56 ) ;
}
if ( V_54 & ( V_73 << 24 ) ) {
if ( V_53 & ( V_73 << 24 ) ) {
V_2 -> V_74 = V_75 ;
F_25 ( & V_2 -> V_76 , 0 ) ;
} else {
F_34 ( V_77 , & V_2 -> V_76 , 0 ) ;
}
}
if ( V_54 & ( V_62 | V_64 | V_66 | V_59 ) )
F_30 ( & V_2 -> V_2 . V_78 ) ;
}
static unsigned F_35 ( struct V_1 * V_2 )
{
unsigned V_53 = 0 ;
if ( V_2 -> V_79 & V_80 )
V_53 |= V_62 | V_64 ;
if ( V_2 -> V_79 & V_81 )
V_53 |= V_66 ;
if ( V_2 -> V_79 & V_82 )
V_53 |= V_72 ;
if ( V_2 -> V_83 )
V_53 |= V_73 << 24 ;
return V_53 ;
}
static int F_36 ( struct V_1 * V_2 )
{
struct V_42 * V_43 ;
int V_84 = - V_85 ;
unsigned V_53 = F_35 ( V_2 ) ;
F_37 () ;
V_43 = F_38 ( V_2 -> V_43 ) ;
if ( V_43 ) {
V_84 = F_18 ( V_43 , V_86 ,
V_43 -> V_87 , & V_53 ,
sizeof( V_53 ) , NULL , V_2 ) ;
}
F_39 () ;
return V_84 ;
}
static int F_40 ( struct V_1 * V_2 )
{
int V_84 ;
F_2 ( & V_2 -> V_6 ) ;
V_84 = F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_84 ;
}
static void F_41 ( struct V_1 * V_2 )
{
struct V_55 * V_56 ;
unsigned V_88 ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( ! V_56 )
return;
F_2 ( & V_2 -> V_6 ) ;
V_88 = V_2 -> V_79 ;
V_2 -> V_79 |= V_82 ;
if ( F_33 ( V_56 ) )
V_2 -> V_79 &= ~ V_81 ;
if ( ~ V_88 & V_82 )
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_32 ( V_56 ) ;
}
static void F_42 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_43 ( V_90 , V_69 ) ;
struct V_55 * V_56 ;
F_44 ( F_45 ( 50 ) ) ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 )
F_46 ( V_56 ) ;
F_32 ( V_56 ) ;
}
static void F_47 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_43 ( F_48 ( V_90 ) , V_76 ) ;
static const char V_91 [ 16 ] ;
unsigned long V_92 = V_75 ;
unsigned long V_93 = V_92 - V_2 -> V_74 ;
int V_4 , V_15 , V_3 , V_94 = 0 ;
V_4 = ( V_93 * V_2 -> V_95 ) / V_96 + 1 ;
V_2 -> V_74 = V_92 ;
F_5 ( V_2 , L_19 , V_4 ) ;
while ( V_4 ) {
V_15 = F_11 ( V_4 , 16 ) ;
V_3 = F_49 ( & V_2 -> V_2 , V_91 ,
V_97 , V_15 ) ;
V_4 -= V_3 ;
V_94 += V_3 ;
if ( V_3 < V_15 )
break;
}
F_50 ( & V_2 -> V_2 ) ;
if ( V_2 -> V_58 & ( V_73 << 24 ) )
F_25 ( & V_2 -> V_76 , V_98 ) ;
V_2 -> V_60 . V_94 += V_94 ;
}
static int F_51 ( struct V_1 * V_2 , unsigned char * V_99 , T_1 V_37 )
{
int V_3 , V_4 = V_37 ;
unsigned V_100 ;
int V_84 = 0 ;
F_5 ( V_2 , L_20 , V_4 ) ;
F_7 ( V_2 -> V_11 . V_17 , V_4 ) ;
if ( V_2 -> V_101 ) {
V_4 = 0 ;
goto V_102;
}
V_100 = ( V_2 -> V_58 >> 24 ) & ~ V_73 ;
if ( V_2 -> V_103 )
V_100 |= V_104 ;
if ( V_100 & V_104 )
++ V_2 -> V_60 . V_103 ;
V_100 &= V_2 -> V_105 ;
if ( V_100 & ~ V_2 -> V_106 & V_104 ) {
if ( ! F_52 ( & V_2 -> V_2 , 0 , V_107 ) ) {
V_84 = - V_108 ;
goto V_102;
}
}
V_2 -> V_103 = false ;
if ( V_100 & V_2 -> V_106 & ~ V_104 ) {
V_4 = 0 ;
goto V_102;
}
V_3 = F_49 ( & V_2 -> V_2 , V_99 , V_109 , V_4 ) ;
if ( V_3 > 0 )
F_50 ( & V_2 -> V_2 ) ;
V_4 -= V_3 ;
if ( V_4 ) {
V_2 -> V_103 = true ;
V_84 = - V_108 ;
F_13 ( V_2 , L_21 ) ;
} else {
if ( F_53 ( & V_2 -> V_2 ) < V_110 )
F_41 ( V_2 ) ;
}
V_102:
V_2 -> V_60 . V_111 += V_37 ;
V_2 -> V_11 . V_112 += V_4 ;
return V_84 ;
}
static void F_54 ( struct V_34 * V_35 ,
struct V_113 * V_114 ,
int V_44 , int V_115 , int V_116 ,
int V_46 ,
unsigned long long V_45 ,
void * V_99 , T_1 V_37 ,
void * V_117 )
{
struct V_1 * V_2 = V_117 ;
struct V_42 * V_43 ;
int V_84 ;
int V_23 ;
F_37 () ;
V_43 = F_55 ( V_35 , V_46 , V_116 ) ;
F_39 () ;
if ( ! V_43 || V_43 != F_56 ( V_2 -> V_43 ) ) {
V_23 = V_25 ;
F_13 ( V_2 , L_22 ) ;
goto V_118;
}
switch ( V_44 ) {
case V_86 :
if ( V_45 != V_2 -> V_119 . V_120 || V_37 != 4 ) {
V_23 = V_25 ;
} else {
F_27 ( V_2 , * ( unsigned * ) V_99 ) ;
V_23 = V_39 ;
}
break;
case V_121 :
if ( V_45 != V_2 -> V_119 . V_120 + 4 ||
V_37 > V_2 -> V_119 . V_122 - 4 ) {
V_23 = V_25 ;
} else {
V_84 = F_51 ( V_2 , V_99 , V_37 ) ;
switch ( V_84 ) {
case 0 :
V_23 = V_39 ;
break;
case - V_108 :
V_23 = V_26 ;
break;
default:
V_23 = V_123 ;
break;
}
}
break;
default:
V_23 = V_124 ;
}
V_118:
F_57 ( V_35 , V_114 , V_23 ) ;
}
static void F_58 ( struct V_34 * V_35 , int V_23 ,
void * V_99 , T_1 V_122 ,
struct V_30 * V_31 )
{
struct V_1 * V_2 = V_31 -> V_2 ;
int V_37 ;
F_5 ( V_2 , L_23 , V_23 ) ;
switch ( V_23 ) {
case V_39 :
F_2 ( & V_2 -> V_6 ) ;
F_59 ( & V_2 -> V_7 , & V_31 -> V_125 ) ;
V_37 = F_60 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
V_2 -> V_60 . V_126 += V_31 -> V_125 . V_37 ;
break;
default:
F_2 ( & V_2 -> V_6 ) ;
F_59 ( & V_2 -> V_7 , & V_31 -> V_125 ) ;
V_37 = F_60 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
V_2 -> V_11 . V_127 += V_31 -> V_125 . V_37 ;
}
if ( V_37 < V_128 )
F_61 ( & V_2 -> V_2 ) ;
}
static int F_62 ( struct V_1 * V_2 , bool V_52 )
{
struct V_42 * V_43 ;
struct V_30 * V_31 ;
struct V_55 * V_56 ;
int V_4 , V_37 ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( ! V_56 )
return - V_85 ;
F_37 () ;
V_43 = F_38 ( V_2 -> V_43 ) ;
if ( ! V_43 ) {
V_4 = - V_108 ;
goto V_102;
}
if ( F_63 ( V_129 , & V_2 -> V_130 ) ) {
V_4 = - V_131 ;
goto V_102;
}
V_4 = - V_132 ;
while ( ! V_56 -> V_133 && ! V_56 -> V_70 &&
! F_64 ( V_134 , & V_2 -> V_130 ) ) {
V_31 = F_19 ( V_41 , V_47 ) ;
if ( ! V_31 ) {
V_4 = - V_48 ;
break;
}
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_65 ( & V_2 -> V_7 , & V_31 -> V_125 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_24 , V_31 -> V_125 . V_37 , V_4 ) ;
if ( V_4 < 0 ) {
F_17 ( V_41 , V_31 ) ;
if ( V_4 == - V_132 ) {
++ V_2 -> V_11 . V_135 ;
} else if ( V_4 == - V_136 ) {
F_7 ( V_2 -> V_11 . V_19 , 0 ) ;
} else {
++ V_2 -> V_11 . V_137 ;
F_13 ( V_2 , L_25 ,
V_4 ) ;
}
break;
}
F_7 ( V_2 -> V_11 . V_19 , V_31 -> V_125 . V_37 ) ;
F_22 ( V_43 , V_31 , V_121 ,
V_43 -> V_138 , V_31 -> V_125 . V_99 ,
V_31 -> V_125 . V_37 , F_58 ,
V_2 ) ;
++ V_2 -> V_11 . V_139 ;
if ( V_4 == 0 || ( ! V_52 && V_4 < V_140 ) )
break;
}
if ( V_4 >= 0 || V_4 == - V_132 || V_4 == - V_48 || V_4 == - V_136 ) {
F_2 ( & V_2 -> V_6 ) ;
V_37 = F_24 ( & V_2 -> V_7 ) ;
if ( V_37 ) {
unsigned long V_141 = ( V_4 == - V_48 ) ? V_96 : 1 ;
F_25 ( & V_2 -> V_52 , V_141 ) ;
}
V_37 = F_60 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_52 && V_37 < V_128 )
F_66 ( V_56 ) ;
}
F_67 ( V_129 , & V_2 -> V_130 ) ;
F_30 ( & V_2 -> V_142 ) ;
V_102:
F_39 () ;
F_32 ( V_56 ) ;
return V_4 ;
}
static void F_68 ( struct V_89 * V_90 )
{
struct V_1 * V_2 = F_43 ( F_48 ( V_90 ) , V_52 ) ;
F_62 ( V_2 , true ) ;
}
static void F_69 ( struct V_1 * V_2 , char V_143 )
{
struct V_42 * V_43 ;
++ V_2 -> V_11 . V_144 ;
F_5 ( V_2 , L_26 , V_143 ) ;
F_37 () ;
V_43 = F_38 ( V_2 -> V_43 ) ;
if ( V_43 ) {
F_18 ( V_43 , V_121 ,
V_43 -> V_138 , & V_143 , sizeof( V_143 ) ,
NULL , V_2 ) ;
}
F_39 () ;
}
struct V_1 * F_70 ( unsigned V_145 )
{
struct V_1 * V_2 ;
if ( V_145 >= V_146 )
return NULL ;
F_71 ( & V_147 ) ;
V_2 = V_148 [ V_145 ] ;
if ( V_2 )
F_72 ( & V_2 -> V_49 -> V_149 ) ;
F_73 ( & V_147 ) ;
return V_2 ;
}
static int F_74 ( struct V_150 * V_49 )
{
int V_84 = - V_151 ;
int V_152 , V_14 ;
if ( V_153 )
return V_84 ;
F_71 ( & V_147 ) ;
for ( V_152 = 0 ; V_152 + V_154 <= V_146 ; V_152 += V_154 ) {
if ( ! V_148 [ V_152 ] ) {
for ( V_14 = 0 ; V_14 < V_154 ; ++ V_152 , ++ V_14 ) {
V_49 -> V_155 [ V_14 ] -> V_145 = V_152 ;
V_148 [ V_152 ] = V_49 -> V_155 [ V_14 ] ;
}
V_84 = 0 ;
break;
}
}
F_73 ( & V_147 ) ;
return V_84 ;
}
static void F_75 ( struct V_149 * V_149 )
{
struct V_150 * V_49 = F_76 ( V_149 , V_149 ) ;
struct V_1 * * V_155 = V_49 -> V_155 ;
int V_14 , V_152 = V_155 [ 0 ] -> V_145 ;
F_77 () ;
F_71 ( & V_147 ) ;
for ( V_14 = 0 ; V_14 < V_154 ; ++ V_152 , ++ V_14 ) {
V_153 |= V_148 [ V_152 ] != V_155 [ V_14 ] ;
F_78 ( V_153 , L_27 ,
V_152 , V_148 [ V_152 ] , V_14 , V_155 [ V_14 ] ) ;
V_148 [ V_152 ] = NULL ;
}
F_73 ( & V_147 ) ;
for ( V_14 = 0 ; V_14 < V_154 ; ++ V_14 ) {
F_79 ( & V_155 [ V_14 ] -> V_119 ) ;
F_80 ( & V_155 [ V_14 ] -> V_2 ) ;
F_81 ( V_155 [ V_14 ] ) ;
}
F_81 ( V_49 ) ;
}
void F_82 ( struct V_1 * V_2 )
{
F_83 ( & V_2 -> V_49 -> V_149 , F_75 ) ;
}
static void F_84 ( struct V_156 * V_156 , int V_157 )
{
struct V_1 * V_2 = F_43 ( V_156 , V_2 ) ;
F_5 ( V_2 , L_28 , V_157 ) ;
F_2 ( & V_2 -> V_6 ) ;
if ( ! V_2 -> V_2 . V_158 ) {
if ( V_157 )
V_2 -> V_79 |= V_80 | V_81 ;
else
V_2 -> V_79 &= ~ ( V_80 | V_81 ) ;
}
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static int F_85 ( struct V_156 * V_156 )
{
struct V_1 * V_2 = F_43 ( V_156 , V_2 ) ;
int V_159 ;
V_159 = ( V_2 -> V_58 & V_64 ) ;
F_5 ( V_2 , L_20 , V_159 ) ;
return V_159 ;
}
static unsigned F_86 ( struct V_1 * V_2 , struct V_55 * V_56 )
{
unsigned V_160 , V_161 ;
V_160 = F_87 ( & V_56 -> V_162 ) ;
F_88 ( & V_56 -> V_162 , V_160 , V_160 ) ;
V_161 = 12 + ( ( F_89 ( V_56 ) ) ? 4 : 2 ) + ( ( F_90 ( V_56 ) ) ? 2 : 0 ) ;
switch ( F_91 ( V_56 ) ) {
case V_163 :
V_161 -= ( F_89 ( V_56 ) ) ? 1 : 0 ;
break;
case V_164 :
V_161 += 2 ;
break;
case V_165 :
V_161 += 4 ;
break;
case V_166 :
V_161 += 6 ;
break;
}
V_2 -> V_95 = ( V_160 << 1 ) / V_161 ;
V_2 -> V_105 = V_104 ;
if ( F_92 ( V_56 , V_167 | V_168 ) )
V_2 -> V_105 |= V_73 ;
V_2 -> V_106 = 0 ;
if ( F_93 ( V_56 ) ) {
V_2 -> V_106 |= V_73 ;
if ( F_94 ( V_56 ) )
V_2 -> V_106 |= V_104 ;
}
V_2 -> V_101 = ! F_95 ( V_56 ) ;
if ( V_2 -> V_71 ) {
V_56 -> V_162 . V_169 &= ~ ( V_170 | V_171 | V_172 | V_173 |
V_174 | V_175 | V_176 ) ;
V_56 -> V_162 . V_177 &= ~ V_178 ;
}
return V_160 ;
}
static int F_96 ( struct V_156 * V_156 ,
struct V_55 * V_56 )
{
struct V_1 * V_2 = F_43 ( V_156 , V_2 ) ;
unsigned V_160 ;
int V_84 ;
F_97 ( V_179 , & V_56 -> V_130 ) ;
V_84 = F_98 ( & V_2 -> V_7 , V_180 ,
F_99 () ,
V_2 -> V_181 ,
V_182 ,
V_183 ) ;
if ( V_84 )
return V_84 ;
F_2 ( & V_2 -> V_6 ) ;
V_160 = F_86 ( V_2 , V_56 ) ;
if ( ! V_2 -> V_2 . V_158 ) {
V_2 -> V_79 = 0 ;
if ( V_160 != 0 )
V_2 -> V_79 = V_80 | V_81 ;
}
if ( F_33 ( V_56 ) && ~ V_2 -> V_58 & V_66 )
V_56 -> V_70 = 1 ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_67 ( V_179 , & V_56 -> V_130 ) ;
return 0 ;
}
static void F_100 ( struct V_156 * V_156 )
{
struct V_1 * V_2 = F_43 ( V_156 , V_2 ) ;
F_101 ( & V_2 -> V_76 ) ;
F_101 ( & V_2 -> V_52 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_130 = 0 ;
V_2 -> V_83 = 0 ;
V_2 -> V_103 = 0 ;
F_36 ( V_2 ) ;
F_102 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static int F_103 ( struct V_55 * V_56 , struct V_184 * V_185 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
return F_104 ( & V_2 -> V_2 , V_56 , V_185 ) ;
}
static void F_105 ( struct V_55 * V_56 , struct V_184 * V_185 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
F_106 ( & V_2 -> V_2 , V_56 , V_185 ) ;
}
static void F_107 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
F_108 ( & V_2 -> V_2 ) ;
}
static void F_109 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
V_56 -> V_186 = NULL ;
F_82 ( V_2 ) ;
}
static int F_110 ( struct V_187 * V_188 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_70 ( V_56 -> V_145 ) ;
int V_84 ;
V_84 = F_111 ( V_188 , V_56 ) ;
if ( ! V_84 )
V_56 -> V_186 = V_2 ;
else
F_82 ( V_2 ) ;
return V_84 ;
}
static int F_112 ( struct V_187 * V_188 , struct V_55 * V_56 )
{
struct V_1 * V_2 = F_70 ( F_113 ( V_56 -> V_145 ) ) ;
int V_84 ;
V_84 = F_111 ( V_188 , V_56 ) ;
if ( ! V_84 )
V_56 -> V_186 = V_2 ;
else
F_82 ( V_2 ) ;
return V_84 ;
}
static int F_114 ( struct V_55 * V_56 , const unsigned char * V_91 , int V_3 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
int V_4 , V_37 ;
F_5 ( V_2 , L_20 , V_3 ) ;
F_7 ( V_2 -> V_11 . V_18 , V_3 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_115 ( & V_2 -> V_7 , V_91 , V_3 ) ;
V_37 = F_24 ( & V_2 -> V_7 ) ;
if ( V_37 < V_189 )
F_25 ( & V_2 -> V_52 , 1 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_37 >= V_189 )
F_62 ( V_2 , false ) ;
F_1 ( V_2 , V_3 , V_4 ) ;
return ( V_4 < 0 ) ? 0 : V_4 ;
}
static int F_116 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
int V_4 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_3 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_20 , V_4 ) ;
return V_4 ;
}
static int F_117 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
int V_4 ;
F_2 ( & V_2 -> V_6 ) ;
V_4 = F_60 ( & V_2 -> V_7 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_20 , V_4 ) ;
return V_4 ;
}
static void F_118 ( struct V_55 * V_56 , char V_143 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
F_5 ( V_2 , L_26 , V_143 ) ;
F_69 ( V_2 , V_143 ) ;
}
static void F_119 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
++ V_2 -> V_11 . V_190 ;
}
static void F_120 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
F_5 ( V_2 , L_29 , ( F_33 ( V_56 ) != 0 ) ) ;
F_6 ( V_2 , V_2 -> V_11 . V_20 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_79 &= ~ V_82 ;
if ( F_33 ( V_56 ) )
V_2 -> V_79 |= V_81 ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
static int F_121 ( struct V_1 * V_2 , unsigned long V_191 ,
struct V_192 * V_193 )
{
struct V_192 V_92 ;
int V_54 ;
V_92 = V_2 -> V_60 ;
V_54 = ( ( V_191 & V_59 && V_193 -> V_61 != V_92 . V_61 ) ||
( V_191 & V_62 && V_193 -> V_63 != V_92 . V_63 ) ||
( V_191 & V_64 && V_193 -> V_65 != V_92 . V_65 ) ||
( V_191 & V_66 && V_193 -> V_67 != V_92 . V_67 ) ) ;
* V_193 = V_92 ;
return V_54 ;
}
static int F_122 ( struct V_1 * V_2 , unsigned long V_191 )
{
struct V_192 V_193 ;
V_193 = V_2 -> V_60 ;
return F_123 ( V_2 -> V_2 . V_78 ,
F_121 ( V_2 , V_191 , & V_193 ) ) ;
}
static int F_124 ( struct V_1 * V_2 ,
struct V_194 T_3 * V_195 )
{
struct V_194 V_196 ;
memset ( & V_196 , 0 , sizeof( V_196 ) ) ;
V_196 . type = V_197 ;
V_196 . line = V_2 -> V_2 . V_56 -> V_145 ;
V_196 . V_130 = V_2 -> V_2 . V_130 ;
V_196 . V_198 = V_180 ;
V_196 . V_199 = 400000000 ;
V_196 . V_200 = V_2 -> V_2 . V_200 ;
return ( F_125 ( V_195 , & V_196 , sizeof( * V_195 ) ) ) ? - V_201 : 0 ;
}
static int F_126 ( struct V_1 * V_2 ,
struct V_194 T_3 * V_195 )
{
struct V_194 V_196 ;
if ( F_127 ( & V_196 , V_195 , sizeof( V_196 ) ) )
return - V_201 ;
if ( V_196 . V_202 != 0 || V_196 . V_2 != 0 || V_196 . V_203 != 0 ||
V_196 . V_199 != 400000000 )
return - V_204 ;
if ( ! F_128 ( V_205 ) ) {
if ( ( ( V_196 . V_130 & ~ V_206 ) !=
( V_2 -> V_2 . V_130 & ~ V_206 ) ) )
return - V_204 ;
} else {
V_2 -> V_2 . V_200 = V_196 . V_200 * V_96 / 100 ;
}
return 0 ;
}
static int F_129 ( struct V_55 * V_56 , unsigned V_207 ,
unsigned long V_208 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
int V_84 ;
switch ( V_207 ) {
case V_209 :
F_71 ( & V_2 -> V_2 . V_210 ) ;
V_84 = F_124 ( V_2 , ( void T_3 * ) V_208 ) ;
F_73 ( & V_2 -> V_2 . V_210 ) ;
break;
case V_211 :
F_71 ( & V_2 -> V_2 . V_210 ) ;
V_84 = F_126 ( V_2 , ( void T_3 * ) V_208 ) ;
F_73 ( & V_2 -> V_2 . V_210 ) ;
break;
case V_212 :
V_84 = F_122 ( V_2 , V_208 ) ;
break;
default:
V_84 = - V_213 ;
}
return V_84 ;
}
static void F_130 ( struct V_55 * V_56 , struct V_214 * V_88 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
unsigned V_160 ;
F_2 ( & V_2 -> V_6 ) ;
V_160 = F_86 ( V_2 , V_56 ) ;
if ( ( V_160 == 0 ) && ( V_88 -> V_215 & V_216 ) ) {
V_2 -> V_79 &= ~ ( V_80 | V_81 ) ;
} else if ( ( V_160 != 0 ) && ! ( V_88 -> V_215 & V_216 ) ) {
if ( F_33 ( V_56 ) || ! F_64 ( V_217 , & V_56 -> V_130 ) )
V_2 -> V_79 |= V_80 | V_81 ;
else
V_2 -> V_79 |= V_80 ;
}
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_88 -> V_215 & V_218 ) {
if ( ! F_33 ( V_56 ) ) {
V_56 -> V_70 = 0 ;
F_26 ( V_2 ) ;
}
} else if ( F_33 ( V_56 ) && ~ V_2 -> V_58 & V_66 ) {
V_56 -> V_70 = 1 ;
}
}
static int F_131 ( struct V_55 * V_56 , int V_219 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
long V_220 ;
F_5 ( V_2 , L_20 , V_219 ) ;
if ( V_219 == - 1 ) {
F_97 ( V_134 , & V_2 -> V_130 ) ;
V_220 = F_132 ( V_2 -> V_142 ,
! F_64 ( V_129 , & V_2 -> V_130 ) ,
10 ) ;
if ( V_220 == 0 || V_220 == - V_221 ) {
F_67 ( V_134 , & V_2 -> V_130 ) ;
F_26 ( V_2 ) ;
return - V_222 ;
}
}
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_83 = ( V_219 == - 1 ) ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_219 == 0 ) {
F_2 ( & V_2 -> V_6 ) ;
F_133 ( & V_2 -> V_7 ) ;
F_67 ( V_134 , & V_2 -> V_130 ) ;
F_4 ( & V_2 -> V_6 ) ;
}
return 0 ;
}
static int F_134 ( struct V_55 * V_56 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
unsigned V_223 ;
F_2 ( & V_2 -> V_6 ) ;
V_223 = ( V_2 -> V_79 & V_57 ) | ( V_2 -> V_58 & ~ V_57 ) ;
F_4 ( & V_2 -> V_6 ) ;
F_5 ( V_2 , L_30 , V_223 ) ;
return V_223 ;
}
static int F_135 ( struct V_55 * V_56 , unsigned V_224 , unsigned V_225 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
F_5 ( V_2 , L_31 , V_224 , V_225 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_79 &= ~ ( V_225 & V_57 & 0xffff ) ;
V_2 -> V_79 |= V_224 & V_57 & 0xffff ;
F_36 ( V_2 ) ;
F_4 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_136 ( struct V_55 * V_56 ,
struct V_226 * V_60 )
{
struct V_1 * V_2 = V_56 -> V_186 ;
struct V_11 V_11 ;
memcpy ( & V_11 , & V_2 -> V_11 , sizeof( V_11 ) ) ;
if ( V_2 -> V_2 . V_158 )
(* V_2 -> V_227 -> V_11 )( & V_11 , V_2 -> V_228 ) ;
V_60 -> V_67 = V_2 -> V_60 . V_67 ;
V_60 -> V_63 = V_2 -> V_60 . V_63 ;
V_60 -> V_61 = V_2 -> V_60 . V_61 ;
V_60 -> V_65 = V_2 -> V_60 . V_65 ;
V_60 -> V_111 = V_2 -> V_60 . V_111 ;
V_60 -> V_126 = V_2 -> V_60 . V_126 + V_11 . V_144 ;
V_60 -> V_161 = V_2 -> V_60 . V_161 ;
V_60 -> V_103 = V_2 -> V_60 . V_103 ;
V_60 -> V_229 = V_2 -> V_60 . V_229 ;
V_60 -> V_94 = V_2 -> V_60 . V_94 ;
V_60 -> V_230 = V_2 -> V_60 . V_103 ;
return 0 ;
}
static void F_137 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 V_11 ;
memcpy ( & V_11 , & V_2 -> V_11 , sizeof( V_11 ) ) ;
if ( V_2 -> V_2 . V_158 )
(* V_2 -> V_227 -> V_11 )( & V_11 , V_2 -> V_228 ) ;
F_9 ( V_10 , L_32 , V_2 -> V_119 . V_120 ,
V_2 -> V_60 . V_126 + V_11 . V_144 , V_2 -> V_60 . V_111 ) ;
F_9 ( V_10 , L_33 , V_2 -> V_60 . V_67 ,
V_2 -> V_60 . V_63 , V_2 -> V_60 . V_61 , V_2 -> V_60 . V_65 ) ;
F_9 ( V_10 , L_34 , V_2 -> V_60 . V_161 ,
V_2 -> V_60 . V_103 , V_2 -> V_60 . V_229 , V_2 -> V_60 . V_94 ) ;
}
static void F_138 ( struct V_9 * V_10 , struct V_1 * V_2 )
{
struct V_11 V_11 ;
memcpy ( & V_11 , & V_2 -> V_11 , sizeof( V_11 ) ) ;
if ( V_2 -> V_2 . V_158 )
(* V_2 -> V_227 -> V_11 )( & V_11 , V_2 -> V_228 ) ;
F_9 ( V_10 , L_35 , V_11 . V_127 ,
V_11 . V_135 , V_11 . V_137 , V_11 . V_112 ) ;
F_9 ( V_10 , L_36 , V_11 . V_139 , V_11 . V_190 ) ;
if ( V_2 -> V_2 . V_158 ) {
F_139 ( V_10 , L_37 ) ;
(* V_2 -> V_227 -> V_231 )( V_10 , V_2 -> V_228 ) ;
}
F_8 ( V_10 , & V_2 -> V_11 ) ;
}
static void F_140 ( struct V_9 * V_10 , struct V_42 * V_43 )
{
int V_46 = V_43 -> V_46 ;
F_20 () ;
F_9 ( V_10 , L_38 , F_141 ( & V_43 -> V_232 -> V_233 ) ) ;
F_9 ( V_10 , L_39 , V_43 -> V_50 , V_46 ) ;
F_9 ( V_10 , L_40 , V_43 -> V_51 ,
V_43 -> V_181 , ( unsigned long long ) V_43 -> V_234 ) ;
F_9 ( V_10 , L_41 , ( unsigned long long ) V_43 -> V_235 ) ;
F_9 ( V_10 , L_42 , ( unsigned long long ) V_43 -> V_87 ) ;
F_142 ( V_10 , '\n' ) ;
}
static int F_143 ( struct V_9 * V_10 , void * V_236 )
{
struct V_1 * V_2 ;
int V_152 ;
F_139 ( V_10 , L_43 ) ;
for ( V_152 = 0 ; V_152 < V_146 && ( V_2 = F_70 ( V_152 ) ) ; ++ V_152 ) {
F_9 ( V_10 , L_44 , V_152 ) ;
if ( F_128 ( V_205 ) )
F_137 ( V_10 , V_2 ) ;
F_82 ( V_2 ) ;
F_139 ( V_10 , L_45 ) ;
}
return 0 ;
}
static int F_144 ( struct V_9 * V_10 , void * V_236 )
{
struct V_150 * V_49 = V_10 -> V_237 ;
struct V_1 * V_2 ;
int V_152 ;
for ( V_152 = 0 ; V_152 < V_154 ; ++ V_152 ) {
V_2 = F_70 ( V_49 -> V_155 [ V_152 ] -> V_145 ) ;
if ( V_2 ) {
F_9 ( V_10 , L_44 , V_2 -> V_145 ) ;
F_137 ( V_10 , V_2 ) ;
F_138 ( V_10 , V_2 ) ;
F_82 ( V_2 ) ;
F_139 ( V_10 , L_45 ) ;
}
}
return 0 ;
}
static int F_145 ( struct V_9 * V_10 , void * V_236 )
{
struct V_150 * V_49 = V_10 -> V_237 ;
struct V_42 * V_43 ;
F_37 () ;
F_9 ( V_10 , L_46 ,
F_141 ( V_49 -> V_35 -> V_233 ) ,
( unsigned long long ) V_49 -> V_35 -> V_234 ) ;
F_146 (peer, &serial->peer_list, list)
F_140 ( V_10 , V_43 ) ;
F_39 () ;
return 0 ;
}
static int F_147 ( struct V_238 * V_238 , struct V_184 * V_185 )
{
return F_148 ( V_185 , F_143 , NULL ) ;
}
static int F_149 ( struct V_238 * V_238 , struct V_184 * V_185 )
{
return F_148 ( V_185 , F_144 , V_238 -> V_239 ) ;
}
static int F_150 ( struct V_238 * V_238 , struct V_184 * V_185 )
{
return F_148 ( V_185 , F_145 , V_238 -> V_239 ) ;
}
static inline int F_151 ( T_4 V_240 )
{
static const struct V_241 V_242 ;
switch ( F_152 ( V_240 ) ) {
case V_243 :
return sizeof( V_242 . V_244 ) + sizeof( V_242 . V_245 ) ;
case V_246 :
return sizeof( V_242 . V_244 ) + sizeof( V_242 . V_247 ) ;
case V_248 :
case V_249 :
case V_246 | V_250 :
case V_249 | V_250 :
return sizeof( V_242 . V_244 ) ;
default:
return - 1 ;
}
}
static inline void F_153 ( struct V_251 * V_252 ,
struct V_1 * V_2 )
{
T_5 V_87 = V_2 -> V_119 . V_120 ;
T_5 V_138 = V_2 -> V_119 . V_120 + 4 ;
T_1 V_253 = V_2 -> V_119 . V_122 - 4 ;
V_252 -> V_254 = F_154 ( V_87 >> 32 ) ;
V_252 -> V_255 = F_154 ( V_87 ) ;
V_252 -> V_256 = F_154 ( V_138 >> 32 ) ;
V_252 -> V_257 = F_154 ( V_138 ) ;
V_252 -> V_253 = F_154 ( V_253 ) ;
}
static inline void F_155 ( struct V_241 * V_242 ,
struct V_1 * V_2 )
{
V_242 -> V_244 . V_240 = F_156 ( V_243 ) ;
V_242 -> V_244 . V_37 = F_156 ( F_151 ( V_242 -> V_244 . V_240 ) ) ;
F_153 ( & V_242 -> V_245 , V_2 ) ;
}
static inline void F_157 ( struct V_241 * V_242 ,
struct V_1 * V_2 )
{
V_242 -> V_244 . V_240 = F_156 ( V_246 ) ;
V_242 -> V_244 . V_37 = F_156 ( F_151 ( V_242 -> V_244 . V_240 ) ) ;
F_153 ( & V_242 -> V_247 , V_2 ) ;
}
static inline void F_158 ( struct V_241 * V_242 )
{
V_242 -> V_244 . V_240 = F_156 ( V_246 | V_250 ) ;
V_242 -> V_244 . V_37 = F_156 ( F_151 ( V_242 -> V_244 . V_240 ) ) ;
}
static inline void F_159 ( struct V_241 * V_242 )
{
V_242 -> V_244 . V_240 = F_156 ( V_248 ) ;
V_242 -> V_244 . V_37 = F_156 ( F_151 ( V_242 -> V_244 . V_240 ) ) ;
}
static inline void F_160 ( struct V_241 * V_242 )
{
V_242 -> V_244 . V_240 = F_156 ( V_249 | V_250 ) ;
V_242 -> V_244 . V_37 = F_156 ( F_151 ( V_242 -> V_244 . V_240 ) ) ;
}
static inline void F_161 ( struct V_241 * V_242 )
{
V_242 -> V_244 . V_240 = F_156 ( V_249 ) ;
V_242 -> V_244 . V_37 = F_156 ( F_151 ( V_242 -> V_244 . V_240 ) ) ;
}
static void F_162 ( struct V_42 * V_43 ,
struct V_251 * V_252 )
{
struct V_1 * V_2 = V_43 -> V_2 ;
V_43 -> V_87 = F_163 ( V_252 -> V_254 , V_252 -> V_255 ) ;
V_43 -> V_138 = F_163 ( V_252 -> V_256 , V_252 -> V_257 ) ;
V_43 -> V_253 = F_164 ( V_252 -> V_253 ) ;
F_165 ( V_43 , V_258 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_181 = F_11 ( V_43 -> V_181 , V_43 -> V_253 ) ;
F_166 ( & V_2 -> V_7 , V_2 -> V_181 ) ;
F_4 ( & V_43 -> V_2 -> V_6 ) ;
if ( V_2 -> V_2 . V_158 && V_2 -> V_227 -> V_259 != NULL )
(* V_2 -> V_227 -> V_259 )( V_260 , V_2 -> V_228 ) ;
F_167 ( & V_43 -> V_232 , L_47 ,
( unsigned long long ) V_43 -> V_234 , F_141 ( V_2 -> V_233 ) ) ;
}
static inline int F_168 ( struct V_42 * V_43 ,
struct V_241 * V_242 )
{
int V_46 ;
int V_23 , V_261 = 5 ;
do {
V_46 = V_43 -> V_46 ;
F_20 () ;
V_23 = F_169 ( V_43 -> V_49 -> V_35 ,
V_121 ,
V_43 -> V_50 ,
V_46 , V_43 -> V_51 ,
V_43 -> V_235 ,
V_242 , F_152 ( V_242 -> V_244 . V_37 ) ) ;
if ( V_23 == V_28 || V_23 == V_24 ||
V_23 == V_262 ) {
F_5 ( & V_43 -> V_232 , L_48 , V_23 ) ;
continue;
} else {
break;
}
} while ( -- V_261 > 0 );
return V_23 ;
}
static struct V_1 * F_170 ( struct V_42 * V_43 ,
int V_145 )
{
struct V_1 * V_2 ;
if ( V_145 < 0 || V_145 >= V_154 )
return F_171 ( - V_263 ) ;
F_77 () ;
V_2 = V_43 -> V_49 -> V_155 [ V_145 ] ;
F_2 ( & V_2 -> V_6 ) ;
if ( ! F_56 ( V_2 -> V_43 ) )
F_172 ( V_2 -> V_43 , V_43 ) ;
else
V_2 = F_171 ( - V_151 ) ;
F_4 ( & V_2 -> V_6 ) ;
return V_2 ;
}
static struct V_1 * F_173 ( struct V_42 * V_43 )
{
struct V_1 * * V_155 = V_43 -> V_49 -> V_155 ;
int V_152 ;
F_77 () ;
for ( V_152 = 0 ; V_152 < V_264 ; ++ V_152 ) {
F_2 ( & V_155 [ V_152 ] -> V_6 ) ;
if ( ! V_155 [ V_152 ] -> V_43 ) {
F_172 ( V_155 [ V_152 ] -> V_43 , V_43 ) ;
F_4 ( & V_155 [ V_152 ] -> V_6 ) ;
return V_155 [ V_152 ] ;
}
F_4 ( & V_155 [ V_152 ] -> V_6 ) ;
}
return NULL ;
}
static void F_174 ( struct V_1 * V_2 , bool V_265 )
{
if ( V_265 )
F_27 ( V_2 , 0 ) ;
F_2 ( & V_2 -> V_6 ) ;
V_2 -> V_181 = F_175 ( V_266 ) ;
F_166 ( & V_2 -> V_7 , V_2 -> V_181 ) ;
F_176 ( V_2 -> V_43 , NULL ) ;
F_4 ( & V_2 -> V_6 ) ;
if ( V_2 -> V_2 . V_158 && V_2 -> V_227 -> V_259 != NULL )
(* V_2 -> V_227 -> V_259 )( V_267 , V_2 -> V_228 ) ;
}
static void F_177 ( unsigned long V_99 )
{
struct V_42 * V_43 = (struct V_42 * ) V_99 ;
struct V_1 * V_2 ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_219 != V_268 ) {
F_4 ( & V_43 -> V_6 ) ;
return;
}
V_2 = F_178 ( V_43 ) ;
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_174 ( V_2 , false ) ;
}
static int F_179 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
struct V_241 * V_242 ;
int V_84 , V_23 ;
V_242 = F_180 ( sizeof( * V_242 ) , V_183 ) ;
if ( ! V_242 )
return - V_48 ;
V_2 = F_173 ( V_43 ) ;
if ( ! V_2 ) {
F_181 ( & V_43 -> V_232 , L_49 ) ;
V_84 = - V_151 ;
goto V_269;
}
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_219 != V_270 ) {
V_84 = - V_151 ;
goto V_271;
}
V_43 -> V_2 = V_2 ;
F_165 ( V_43 , V_268 ) ;
F_155 ( V_242 , V_43 -> V_2 ) ;
F_182 ( & V_43 -> V_272 , F_177 , ( unsigned long ) V_43 ) ;
F_183 ( & V_43 -> V_272 , V_75 + V_273 ) ;
F_4 ( & V_43 -> V_6 ) ;
V_23 = F_168 ( V_43 , V_242 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_219 == V_268 && V_23 != V_39 ) {
if ( V_23 == V_123 )
V_84 = - V_132 ;
else
V_84 = - V_108 ;
goto V_274;
}
F_4 ( & V_43 -> V_6 ) ;
F_81 ( V_242 ) ;
return 0 ;
V_274:
F_184 ( & V_43 -> V_272 ) ;
F_178 ( V_43 ) ;
V_271:
F_4 ( & V_43 -> V_6 ) ;
F_174 ( V_2 , false ) ;
V_269:
F_81 ( V_242 ) ;
return V_84 ;
}
static void F_185 ( struct V_187 * V_188 ,
struct V_1 * V_2 )
{
struct V_55 * V_56 ;
F_71 ( & V_2 -> V_2 . V_210 ) ;
V_56 = F_28 ( & V_2 -> V_2 ) ;
if ( V_56 ) {
F_46 ( V_56 ) ;
F_32 ( V_56 ) ;
}
F_73 ( & V_2 -> V_2 . V_210 ) ;
if ( V_188 == V_275 )
F_186 ( V_188 , F_187 ( V_2 ) ) ;
else
F_186 ( V_188 , V_2 -> V_145 ) ;
}
static struct V_150 * F_188 ( struct V_34 * V_35 )
{
struct V_150 * V_49 ;
F_189 (serial, &fwserial_list, list) {
if ( V_35 == V_49 -> V_35 )
return V_49 ;
}
return NULL ;
}
static struct V_150 * F_190 ( struct V_34 * V_35 )
{
struct V_150 * V_49 ;
F_146 (serial, &fwserial_list, list) {
if ( V_35 == V_49 -> V_35 )
return V_49 ;
}
return NULL ;
}
static struct V_42 * F_55 ( struct V_34 * V_35 ,
int V_46 , int V_276 )
{
struct V_150 * V_49 ;
struct V_42 * V_43 ;
V_49 = F_190 ( V_35 ) ;
if ( ! V_49 ) {
F_181 ( V_35 , L_50 ,
( unsigned long long ) V_35 -> V_234 ) ;
return NULL ;
}
F_146 (peer, &serial->peer_list, list) {
int V_277 = V_43 -> V_46 ;
F_20 () ;
if ( V_46 == V_277 && V_276 == V_43 -> V_50 )
return V_43 ;
}
return NULL ;
}
static void F_191 ( struct V_34 * V_35 )
{
struct V_150 * V_49 ;
struct V_42 * V_43 ;
V_49 = F_190 ( V_35 ) ;
if ( ! V_49 )
return;
F_146 (peer, &serial->peer_list, list) {
int V_277 = V_43 -> V_46 ;
F_20 () ;
F_5 ( V_35 , L_51 ,
V_277 , V_43 -> V_50 , ( unsigned long long ) V_43 -> V_234 ) ;
}
}
static void F_192 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_193 ( F_48 ( V_90 ) , V_278 ) ;
int V_84 ;
V_84 = F_179 ( V_43 ) ;
if ( V_84 == - V_132 && ++ V_43 -> V_279 < V_280 )
F_25 ( & V_43 -> V_278 , V_281 ) ;
}
static void F_194 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_193 ( V_90 , V_90 ) ;
V_43 -> V_282 ( V_90 ) ;
}
static int F_195 ( struct V_150 * V_49 , struct V_283 * V_232 )
{
struct V_233 * V_284 = & V_232 -> V_233 ;
struct V_21 * V_285 = F_196 ( V_232 ) ;
struct V_42 * V_43 ;
struct V_286 V_287 ;
int V_288 , V_289 ;
int V_46 ;
V_43 = F_197 ( sizeof( * V_43 ) , V_183 ) ;
if ( ! V_43 )
return - V_48 ;
F_165 ( V_43 , V_270 ) ;
F_198 ( V_284 , V_43 ) ;
V_43 -> V_232 = V_232 ;
V_43 -> V_234 = ( T_5 ) V_285 -> V_290 [ 3 ] << 32 | V_285 -> V_290 [ 4 ] ;
V_43 -> V_51 = V_285 -> V_291 ;
V_43 -> V_181 = F_11 ( F_10 ( V_285 ) ,
F_175 ( V_43 -> V_51 ) ) ;
V_46 = V_285 -> V_46 ;
F_20 () ;
V_43 -> V_50 = V_285 -> V_50 ;
F_199 () ;
V_43 -> V_46 = V_46 ;
F_200 ( & V_287 , V_232 -> V_292 ) ;
while ( F_201 ( & V_287 , & V_288 , & V_289 ) ) {
if ( V_288 == ( V_293 | V_294 ) ) {
V_43 -> V_235 = V_295 + 4 * V_289 ;
break;
}
}
if ( V_43 -> V_235 == 0ULL ) {
F_165 ( V_43 , V_296 ) ;
}
F_202 ( & V_43 -> V_6 ) ;
V_43 -> V_2 = NULL ;
F_15 ( & V_43 -> V_272 ) ;
F_203 ( & V_43 -> V_90 , F_194 ) ;
F_204 ( & V_43 -> V_278 , F_192 ) ;
V_43 -> V_49 = V_49 ;
F_205 ( & V_43 -> V_297 , & V_49 -> V_298 ) ;
F_167 ( & V_43 -> V_232 , L_52 ,
( unsigned long long ) V_43 -> V_234 ) ;
if ( V_285 -> V_299 ) {
V_49 -> V_300 = V_43 ;
if ( V_301 ) {
struct V_1 * V_2 ;
V_2 = F_170 ( V_43 , V_264 ) ;
if ( ! F_206 ( V_2 ) ) {
struct V_251 V_252 ;
F_2 ( & V_43 -> V_6 ) ;
V_43 -> V_2 = V_2 ;
F_153 ( & V_252 , V_2 ) ;
F_162 ( V_43 , & V_252 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_40 ( V_2 ) ;
}
}
} else if ( V_302 ) {
F_25 ( & V_43 -> V_278 , 1 ) ;
}
return 0 ;
}
static void F_207 ( struct V_42 * V_43 )
{
struct V_1 * V_2 ;
F_2 ( & V_43 -> V_6 ) ;
F_165 ( V_43 , V_303 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_101 ( & V_43 -> V_278 ) ;
F_208 ( & V_43 -> V_90 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 == V_43 -> V_49 -> V_300 )
V_43 -> V_49 -> V_300 = NULL ;
F_184 ( & V_43 -> V_272 ) ;
V_2 = V_43 -> V_2 ;
V_43 -> V_2 = NULL ;
F_209 ( & V_43 -> V_297 ) ;
F_167 ( & V_43 -> V_232 , L_53 ,
( unsigned long long ) V_43 -> V_234 ) ;
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_174 ( V_2 , true ) ;
F_77 () ;
F_81 ( V_43 ) ;
}
static int F_210 ( struct V_283 * V_232 )
{
struct V_21 * V_285 = F_196 ( V_232 ) ;
struct V_34 * V_35 = V_285 -> V_35 ;
struct V_150 * V_49 ;
struct V_1 * V_2 ;
struct V_233 * V_304 ;
int V_152 , V_14 ;
int V_84 ;
V_49 = F_197 ( sizeof( * V_49 ) , V_183 ) ;
if ( ! V_49 )
return - V_48 ;
F_211 ( & V_49 -> V_149 ) ;
V_49 -> V_35 = V_35 ;
F_212 ( & V_49 -> V_298 ) ;
for ( V_152 = 0 ; V_152 < V_154 ; ++ V_152 ) {
V_2 = F_197 ( sizeof( * V_2 ) , V_183 ) ;
if ( ! V_2 ) {
V_84 = - V_48 ;
goto V_305;
}
F_213 ( & V_2 -> V_2 ) ;
V_2 -> V_145 = V_306 ;
V_2 -> V_2 . V_307 = & V_308 ;
V_2 -> V_49 = V_49 ;
F_214 ( & V_2 -> V_2 , 128 * 1024 ) ;
F_202 ( & V_2 -> V_6 ) ;
F_204 ( & V_2 -> V_52 , F_68 ) ;
F_204 ( & V_2 -> V_76 , F_47 ) ;
F_203 ( & V_2 -> V_69 , F_42 ) ;
F_215 ( & V_2 -> V_142 ) ;
V_2 -> V_181 = F_175 ( V_266 ) ;
F_216 ( & V_2 -> V_7 ) ;
F_176 ( V_2 -> V_43 , NULL ) ;
V_49 -> V_155 [ V_152 ] = V_2 ;
V_2 -> V_119 . V_122 = V_309 + 4 ;
V_2 -> V_119 . V_310 = F_54 ;
V_2 -> V_119 . V_117 = V_2 ;
V_84 = F_217 ( & V_2 -> V_119 ,
& V_311 ) ;
if ( V_84 ) {
F_81 ( V_2 ) ;
goto V_305;
}
}
V_84 = F_74 ( V_49 ) ;
if ( V_84 ) {
F_181 ( & V_232 , L_54 ) ;
goto V_305;
}
for ( V_14 = 0 ; V_14 < V_264 ; ++ V_14 ) {
V_304 = F_218 ( & V_49 -> V_155 [ V_14 ] -> V_2 ,
V_312 ,
V_49 -> V_155 [ V_14 ] -> V_145 ,
V_35 -> V_233 ) ;
if ( F_206 ( V_304 ) ) {
V_84 = F_219 ( V_304 ) ;
F_181 ( & V_232 , L_55 ,
V_84 ) ;
goto V_313;
}
V_49 -> V_155 [ V_14 ] -> V_233 = V_304 ;
}
if ( V_301 ) {
struct V_233 * V_314 ;
V_314 = F_218 ( & V_49 -> V_155 [ V_14 ] -> V_2 ,
V_275 ,
F_187 ( V_49 -> V_155 [ V_14 ] ) ,
V_35 -> V_233 ) ;
if ( F_206 ( V_314 ) ) {
V_84 = F_219 ( V_314 ) ;
F_181 ( & V_232 , L_56 ,
V_84 ) ;
goto V_313;
}
V_49 -> V_155 [ V_14 ] -> V_233 = V_314 ;
V_49 -> V_155 [ V_14 ] -> V_71 = true ;
}
if ( ! F_220 ( V_315 ) ) {
V_49 -> V_316 = F_221 ( F_141 ( & V_232 -> V_233 ) ,
V_315 ) ;
if ( ! F_220 ( V_49 -> V_316 ) ) {
F_222 ( L_57 , 0444 , V_49 -> V_316 ,
V_49 , & V_317 ) ;
F_222 ( L_58 , 0444 , V_49 -> V_316 ,
V_49 , & V_318 ) ;
}
}
F_205 ( & V_49 -> V_297 , & V_319 ) ;
F_223 ( & V_232 , L_59 ,
F_141 ( V_35 -> V_233 ) , ( unsigned long long ) V_35 -> V_234 ) ;
V_84 = F_195 ( V_49 , V_232 ) ;
if ( ! V_84 )
return 0 ;
F_181 ( & V_232 , L_60 , V_84 ) ;
F_224 ( V_49 -> V_316 ) ;
F_209 ( & V_49 -> V_297 ) ;
if ( V_301 )
F_186 ( V_275 ,
F_187 ( V_49 -> V_155 [ V_14 ] ) ) ;
V_313:
for ( -- V_14 ; V_14 >= 0 ; -- V_14 )
F_186 ( V_312 , V_49 -> V_155 [ V_14 ] -> V_145 ) ;
F_83 ( & V_49 -> V_149 , F_75 ) ;
return V_84 ;
V_305:
for ( -- V_152 ; V_152 >= 0 ; -- V_152 ) {
F_80 ( & V_49 -> V_155 [ V_152 ] -> V_2 ) ;
F_81 ( V_49 -> V_155 [ V_152 ] ) ;
}
F_81 ( V_49 ) ;
return V_84 ;
}
static int F_225 ( struct V_283 * V_232 ,
const struct V_320 * V_276 )
{
struct V_150 * V_49 ;
int V_84 ;
F_71 ( & V_321 ) ;
V_49 = F_188 ( F_196 ( V_232 ) -> V_35 ) ;
if ( ! V_49 )
V_84 = F_210 ( V_232 ) ;
else
V_84 = F_195 ( V_49 , V_232 ) ;
F_73 ( & V_321 ) ;
return V_84 ;
}
static void F_226 ( struct V_283 * V_232 )
{
struct V_42 * V_43 = F_227 ( & V_232 -> V_233 ) ;
struct V_150 * V_49 = V_43 -> V_49 ;
int V_152 ;
F_71 ( & V_321 ) ;
F_207 ( V_43 ) ;
if ( F_228 ( & V_49 -> V_298 ) ) {
F_209 ( & V_49 -> V_297 ) ;
F_224 ( V_49 -> V_316 ) ;
for ( V_152 = 0 ; V_152 < V_264 ; ++ V_152 )
F_185 ( V_312 , V_49 -> V_155 [ V_152 ] ) ;
if ( V_301 )
F_185 ( V_275 , V_49 -> V_155 [ V_152 ] ) ;
F_83 ( & V_49 -> V_149 , F_75 ) ;
}
F_73 ( & V_321 ) ;
}
static void F_229 ( struct V_283 * V_232 )
{
struct V_21 * V_285 = F_196 ( V_232 ) ;
struct V_42 * V_43 = F_227 ( & V_232 -> V_233 ) ;
int V_46 ;
V_46 = V_285 -> V_46 ;
F_20 () ;
V_43 -> V_50 = V_285 -> V_50 ;
F_199 () ;
V_43 -> V_46 = V_46 ;
}
static void F_230 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_193 ( V_90 , V_90 ) ;
struct V_251 * V_245 = & V_43 -> V_322 . V_245 ;
struct V_1 * V_2 ;
struct V_241 * V_242 ;
int V_23 ;
V_242 = F_180 ( sizeof( * V_242 ) , V_183 ) ;
if ( ! V_242 )
return;
V_2 = F_173 ( V_43 ) ;
F_2 ( & V_43 -> V_6 ) ;
switch ( V_43 -> V_219 ) {
case V_270 :
if ( ! V_2 ) {
F_181 ( & V_43 -> V_232 , L_61 ) ;
F_158 ( V_242 ) ;
} else {
V_43 -> V_2 = V_2 ;
F_157 ( V_242 , V_43 -> V_2 ) ;
F_165 ( V_43 , V_323 ) ;
V_2 = NULL ;
}
break;
case V_268 :
if ( V_43 -> V_49 -> V_35 -> V_234 > V_43 -> V_234 )
goto V_324;
F_184 ( & V_43 -> V_272 ) ;
F_157 ( V_242 , V_43 -> V_2 ) ;
F_165 ( V_43 , V_323 ) ;
break;
default:
F_158 ( V_242 ) ;
}
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_174 ( V_2 , false ) ;
V_23 = F_168 ( V_43 , V_242 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_219 == V_323 ) {
if ( V_23 == V_39 ) {
struct V_1 * V_196 = V_43 -> V_2 ;
F_162 ( V_43 , V_245 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_40 ( V_196 ) ;
F_2 ( & V_43 -> V_6 ) ;
} else {
F_181 ( & V_43 -> V_232 , L_62 , V_23 ) ;
V_2 = F_178 ( V_43 ) ;
}
}
V_324:
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_174 ( V_2 , false ) ;
F_81 ( V_242 ) ;
}
static void F_231 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = F_193 ( V_90 , V_90 ) ;
struct V_1 * V_2 = NULL ;
struct V_241 * V_242 ;
int V_23 ;
V_242 = F_180 ( sizeof( * V_242 ) , V_183 ) ;
if ( ! V_242 )
return;
F_2 ( & V_43 -> V_6 ) ;
switch ( V_43 -> V_219 ) {
case V_258 :
F_161 ( V_242 ) ;
F_165 ( V_43 , V_325 ) ;
break;
case V_326 :
if ( V_43 -> V_49 -> V_35 -> V_234 > V_43 -> V_234 )
goto V_324;
F_184 ( & V_43 -> V_272 ) ;
F_161 ( V_242 ) ;
F_165 ( V_43 , V_325 ) ;
break;
default:
F_160 ( V_242 ) ;
}
F_4 ( & V_43 -> V_6 ) ;
V_23 = F_168 ( V_43 , V_242 ) ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_219 == V_325 ) {
if ( V_23 != V_39 )
F_181 ( & V_43 -> V_232 , L_63 ,
V_23 ) ;
V_2 = F_178 ( V_43 ) ;
}
V_324:
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_174 ( V_2 , true ) ;
F_81 ( V_242 ) ;
}
static int F_232 ( struct V_42 * V_43 ,
struct V_241 * V_242 ,
unsigned long long V_45 ,
T_1 V_37 )
{
struct V_1 * V_2 = NULL ;
bool V_265 = false ;
int V_23 ;
if ( V_45 != V_327 . V_120 || V_37 < sizeof( V_242 -> V_244 ) )
return V_25 ;
if ( V_37 != F_152 ( V_242 -> V_244 . V_37 ) ||
V_37 != F_151 ( V_242 -> V_244 . V_240 ) )
return V_26 ;
F_2 ( & V_43 -> V_6 ) ;
if ( V_43 -> V_219 == V_303 ) {
F_181 ( & V_43 -> V_232 , L_64 ) ;
F_4 ( & V_43 -> V_6 ) ;
return V_25 ;
}
V_23 = V_39 ;
F_5 ( & V_43 -> V_232 , L_65 , V_242 -> V_244 . V_240 ) ;
switch ( F_152 ( V_242 -> V_244 . V_240 ) & V_328 ) {
case V_243 :
if ( F_233 ( & V_43 -> V_90 ) ) {
F_181 ( & V_43 -> V_232 , L_66 ) ;
V_23 = V_123 ;
} else {
V_43 -> V_322 . V_245 = V_242 -> V_245 ;
V_43 -> V_282 = F_230 ;
F_234 ( V_329 , & V_43 -> V_90 ) ;
}
break;
case V_246 :
if ( V_43 -> V_219 != V_268 ) {
V_23 = V_123 ;
} else if ( F_152 ( V_242 -> V_244 . V_240 ) & V_250 ) {
F_223 ( & V_43 -> V_232 , L_67 ) ;
V_2 = F_178 ( V_43 ) ;
} else {
struct V_1 * V_196 = V_43 -> V_2 ;
F_162 ( V_43 , & V_242 -> V_247 ) ;
F_4 ( & V_43 -> V_6 ) ;
F_40 ( V_196 ) ;
F_2 ( & V_43 -> V_6 ) ;
}
break;
case V_248 :
if ( F_233 ( & V_43 -> V_90 ) ) {
F_181 ( & V_43 -> V_232 , L_68 ) ;
V_23 = V_123 ;
} else {
V_43 -> V_282 = F_231 ;
F_234 ( V_329 , & V_43 -> V_90 ) ;
}
break;
case V_249 :
if ( V_43 -> V_219 != V_326 ) {
V_23 = V_123 ;
} else {
if ( F_152 ( V_242 -> V_244 . V_240 ) & V_250 )
F_223 ( & V_43 -> V_232 , L_69 ) ;
V_2 = F_178 ( V_43 ) ;
V_265 = true ;
}
break;
default:
F_181 ( & V_43 -> V_232 , L_70 ,
F_152 ( V_242 -> V_244 . V_240 ) ) ;
V_23 = V_26 ;
}
F_4 ( & V_43 -> V_6 ) ;
if ( V_2 )
F_174 ( V_2 , V_265 ) ;
return V_23 ;
}
static void F_235 ( struct V_34 * V_35 ,
struct V_113 * V_114 ,
int V_44 , int V_115 , int V_116 ,
int V_46 ,
unsigned long long V_45 ,
void * V_99 , T_1 V_37 ,
void * V_117 )
{
struct V_241 * V_242 = V_99 ;
struct V_42 * V_43 ;
int V_23 ;
F_37 () ;
V_43 = F_55 ( V_35 , V_46 , V_116 ) ;
if ( ! V_43 ) {
F_5 ( V_35 , L_71 , V_46 , V_116 ) ;
F_191 ( V_35 ) ;
V_23 = V_123 ;
} else {
switch ( V_44 ) {
case V_121 :
V_23 = F_232 ( V_43 , V_242 , V_45 , V_37 ) ;
break;
default:
V_23 = V_124 ;
}
}
F_39 () ;
F_57 ( V_35 , V_114 , V_23 ) ;
}
static int T_6 F_236 ( void )
{
int V_84 , V_330 = ! ! ( V_301 ) ;
V_315 = F_221 ( V_331 , NULL ) ;
if ( V_264 + V_330 > V_332 )
V_264 = V_332 - V_330 ;
V_154 = V_264 + V_330 ;
V_312 = F_237 ( V_146 , V_333
| V_334 ) ;
if ( F_206 ( V_312 ) ) {
V_84 = F_219 ( V_312 ) ;
return V_84 ;
}
V_312 -> V_335 = V_331 ;
V_312 -> V_336 = V_337 ;
V_312 -> V_338 = 0 ;
V_312 -> V_339 = 0 ;
V_312 -> type = V_340 ;
V_312 -> V_341 = V_342 ;
V_312 -> V_343 = V_344 ;
V_312 -> V_343 . V_215 |= V_345 ;
F_238 ( V_312 , & V_346 ) ;
V_84 = F_239 ( V_312 ) ;
if ( V_84 ) {
F_240 ( L_72 , V_84 ) ;
goto V_347;
}
if ( V_301 ) {
V_275 = F_237 ( V_146 / V_154 ,
V_333
| V_334 ) ;
if ( F_206 ( V_275 ) ) {
V_84 = F_219 ( V_275 ) ;
goto V_348;
}
V_275 -> V_335 = V_331 L_73 ;
V_275 -> V_336 = V_349 ;
V_275 -> V_338 = 0 ;
V_275 -> V_339 = 0 ;
V_275 -> type = V_340 ;
V_275 -> V_341 = V_342 ;
V_275 -> V_343 = V_344 ;
V_275 -> V_343 . V_215 |= V_345 ;
F_238 ( V_275 , & V_350 ) ;
V_84 = F_239 ( V_275 ) ;
if ( V_84 ) {
F_240 ( L_74 , V_84 ) ;
goto V_351;
}
}
V_41 = F_241 ( L_75 ,
sizeof( struct V_30 ) ,
0 , 0 , F_14 ) ;
if ( ! V_41 ) {
V_84 = - V_48 ;
goto V_352;
}
V_327 . V_122 = sizeof( struct V_241 ) ;
V_327 . V_310 = F_235 ;
V_84 = F_217 ( & V_327 ,
& V_353 ) ;
if ( V_84 ) {
F_240 ( L_76 , V_84 ) ;
goto V_354;
}
V_355 . V_356 =
F_242 ( V_327 . V_120 ) ;
V_84 = F_243 ( & V_357 ) ;
if ( V_84 ) {
F_240 ( L_77 , V_84 ) ;
goto V_358;
}
V_84 = F_244 ( & V_359 . V_188 ) ;
if ( V_84 ) {
F_240 ( L_78 , V_84 ) ;
goto V_360;
}
return 0 ;
V_360:
F_245 ( & V_357 ) ;
V_358:
F_79 ( & V_327 ) ;
V_354:
F_246 ( V_41 ) ;
V_352:
if ( V_301 )
F_247 ( V_275 ) ;
V_351:
if ( V_301 )
F_248 ( V_275 ) ;
V_348:
F_247 ( V_312 ) ;
V_347:
F_248 ( V_312 ) ;
F_224 ( V_315 ) ;
return V_84 ;
}
static void T_7 F_249 ( void )
{
F_250 ( & V_359 . V_188 ) ;
F_245 ( & V_357 ) ;
F_79 ( & V_327 ) ;
F_246 ( V_41 ) ;
if ( V_301 ) {
F_247 ( V_275 ) ;
F_248 ( V_275 ) ;
}
F_247 ( V_312 ) ;
F_248 ( V_312 ) ;
F_224 ( V_315 ) ;
}
