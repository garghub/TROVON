static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 = 0 , V_8 ;
T_1 V_9 ;
V_8 = - V_10 ;
if ( ! V_5 -> V_11 )
goto V_12;
V_7 += F_2 ( V_2 , V_13 L_1
L_2 ,
V_14 , V_15 ,
V_5 -> V_11 ? V_5 -> V_11 -> V_11 . V_16 : L_3 ) ;
V_9 = F_3 ( V_5 , V_17 ) ;
V_7 += F_2 ( V_2 ,
L_4
L_5 , V_9 ,
( V_9 & V_18 ) ? L_6 : L_7 ,
( V_9 & V_19 ) ? L_8 : L_7 ,
( V_9 & V_20 ) ? L_9 : L_7 ,
( V_9 & V_21 ) ? L_10 : L_7 ,
( V_9 & V_22 ) ? L_11 : L_7 ,
( V_9 & V_23 ) ? L_12 : L_7 ,
( V_9 & V_24 ) ? L_13 : L_7 ,
( V_9 & V_25 ) ? L_14 : L_7 ,
( V_9 & V_26 ) ? L_15 : L_7 ,
( V_9 & V_27 ) ? L_16 : L_7 ,
( V_9 & V_28 ) >> V_29 ,
( V_9 & V_30 ) >> V_31 ,
( V_9 & V_32 ) >> V_33 ) ;
V_7 += F_2 ( V_2 , L_17 ,
F_3 ( V_5 , V_34 ) , F_3 ( V_5 , V_35 ) ) ;
V_7 += F_2 ( V_2 , L_18 ,
F_3 ( V_5 , V_36 ) , F_3 ( V_5 , V_37 ) ) ;
V_7 += F_2 ( V_2 , L_19 , F_3 ( V_5 , V_38 ) ) ;
V_7 += F_2 ( V_2 , L_20
L_21 ,
V_5 -> V_39 . V_40 , V_5 -> V_39 . V_41 ,
V_5 -> V_39 . V_42 , V_5 -> V_39 . V_43 ) ;
V_8 = 0 ;
V_12:
return V_8 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
int V_7 = 0 , V_48 , V_49 , V_8 ;
V_8 = - V_10 ;
if ( ! V_5 -> V_11 )
goto V_12;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
V_45 = & V_5 -> V_44 [ V_48 ] ;
V_49 = V_45 -> V_51 ;
V_7 += F_2 ( V_2 , L_22 ,
F_5 ( V_45 ) , V_49 , L_23 ) ;
if ( F_6 ( & V_45 -> V_52 ) ) {
V_7 += F_2 ( V_2 , L_24 ) ;
continue;
}
F_7 (req, &ep->queue, queue) {
V_7 += F_2 ( V_2 , L_25 ,
& V_47 -> V_47 , V_47 -> V_47 . V_53 ,
V_47 -> V_47 . V_54 , V_47 -> V_47 . V_55 ) ;
}
}
V_8 = 0 ;
V_12:
return V_8 ;
}
static int F_8 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_44 * V_45 ;
int V_7 = 0 , V_48 , V_8 ;
T_1 V_9 ;
V_8 = - V_10 ;
if ( ! V_5 -> V_11 )
goto V_12;
V_45 = & V_5 -> V_44 [ 0 ] ;
V_9 = F_9 ( V_45 , V_56 ) ;
V_7 += F_2 ( V_2 , L_26 , V_9 ,
( V_9 & V_57 ) ? L_27 : L_7 ,
( V_9 & V_58 ) ? L_28 : L_7 ,
( V_9 & V_59 ) ? L_29 : L_7 ,
( V_9 & V_60 ) ? L_30 : L_7 ,
( V_9 & V_61 ) ? L_31 : L_7 ,
( V_9 & V_62 ) ? L_32 : L_7 ,
( V_9 & V_63 ) ? L_33 : L_7 ) ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
V_45 = & V_5 -> V_44 [ V_48 ] ;
V_9 = V_48 ? F_9 ( V_45 , V_17 ) : F_3 ( V_5 , V_17 ) ;
V_7 += F_2 ( V_2 , L_34
L_35
L_36
L_37 ,
F_5 ( V_45 ) ,
V_45 -> V_39 . V_64 , V_45 -> V_39 . V_65 ,
V_45 -> V_39 . V_66 , V_45 -> V_39 . V_67 ,
V_45 -> V_39 . V_68 ,
V_9 , F_9 ( V_45 , V_56 ) ,
F_9 ( V_45 , V_69 ) ) ;
}
V_8 = 0 ;
V_12:
return V_8 ;
}
static int F_10 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_11 ( V_71 , F_8 , V_70 -> V_72 ) ;
}
static int F_12 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_11 ( V_71 , F_4 , V_70 -> V_72 ) ;
}
static int F_13 ( struct V_70 * V_70 , struct V_71 * V_71 )
{
return F_11 ( V_71 , F_1 , V_70 -> V_72 ) ;
}
static void F_14 ( struct V_4 * V_5 )
{
struct V_73 * V_74 , * V_75 , * V_76 , * V_77 ;
V_74 = F_15 ( V_5 -> V_78 . V_16 , NULL ) ;
if ( F_16 ( V_74 ) || ! V_74 )
goto V_79;
V_75 = F_17 ( L_38 , 0400 , V_74 , V_5 ,
& V_80 ) ;
if ( ! V_75 )
goto V_81;
V_76 = F_17 ( L_39 , 0400 , V_74 , V_5 ,
& V_82 ) ;
if ( ! V_76 )
goto V_83;
V_77 = F_17 ( L_40 , 0400 , V_74 , V_5 ,
& V_84 ) ;
if ( ! V_77 )
goto V_85;
V_5 -> V_86 = V_74 ;
V_5 -> V_87 = V_75 ;
V_5 -> V_88 = V_76 ;
V_5 -> V_89 = V_77 ;
return;
V_85:
F_18 ( V_77 ) ;
V_83:
F_18 ( V_76 ) ;
V_81:
F_18 ( V_74 ) ;
V_79:
F_19 ( V_5 -> V_90 , L_41 ) ;
}
static void F_20 ( struct V_4 * V_5 )
{
F_18 ( V_5 -> V_89 ) ;
F_18 ( V_5 -> V_88 ) ;
F_18 ( V_5 -> V_87 ) ;
F_18 ( V_5 -> V_86 ) ;
V_5 -> V_89 = NULL ;
V_5 -> V_88 = NULL ;
V_5 -> V_87 = NULL ;
V_5 -> V_86 = NULL ;
}
static inline void F_14 ( struct V_4 * V_5 )
{
}
static inline void F_20 ( struct V_4 * V_5 )
{
}
static int F_21 ( struct V_91 * V_91 , struct V_44 * V_45 ,
int V_92 , int V_93 , int V_94 )
{
if ( F_22 ( & V_91 -> V_95 ) != V_45 -> V_96 )
return 0 ;
if ( F_23 ( & V_91 -> V_95 ) != V_45 -> V_97 )
return 0 ;
if ( F_24 ( & V_91 -> V_95 ) != V_45 -> type )
return 0 ;
if ( ( V_45 -> V_92 != V_92 ) || ( V_45 -> V_93 != V_93 )
|| ( V_45 -> V_98 != V_94 ) )
return 0 ;
return 1 ;
}
static struct V_44 * F_25 ( struct V_4 * V_5 ,
struct V_91 * V_91 )
{
int V_48 ;
struct V_44 * V_45 ;
int V_99 = V_5 -> V_92 ;
int V_100 = V_5 -> V_101 ;
int V_102 = V_5 -> V_103 ;
if ( V_91 == & V_5 -> V_91 [ 0 ] )
return & V_5 -> V_44 [ 0 ] ;
for ( V_48 = 1 ; V_48 < V_50 ; V_48 ++ ) {
V_45 = & V_5 -> V_44 [ V_48 ] ;
if ( F_21 ( V_91 , V_45 , V_99 , V_100 , V_102 ) )
return V_45 ;
}
return NULL ;
}
static void F_26 ( struct V_4 * V_5 )
{
int V_48 ;
struct V_91 * V_91 ;
for ( V_48 = 1 ; V_48 < V_104 ; V_48 ++ ) {
V_91 = & V_5 -> V_91 [ V_48 ] ;
if ( V_91 -> V_44 )
V_91 -> V_44 = F_25 ( V_5 , V_91 ) ;
}
}
static void F_27 ( struct V_44 * V_45 )
{
struct V_4 * V_5 = V_45 -> V_90 ;
int V_105 = F_28 ( V_45 ) ;
T_1 V_106 = F_3 ( V_5 , V_34 ) ;
T_1 V_107 = F_3 ( V_5 , V_35 ) ;
if ( V_105 < 16 )
F_29 ( V_5 , V_34 , V_106 | ( 3 << ( V_105 * 2 ) ) ) ;
else
F_29 ( V_5 , V_35 , V_107 | ( 3 << ( ( V_105 - 16 ) * 2 ) ) ) ;
}
static void F_30 ( struct V_44 * V_45 )
{
struct V_4 * V_5 = V_45 -> V_90 ;
int V_105 = F_28 ( V_45 ) ;
T_1 V_106 = F_3 ( V_5 , V_34 ) ;
T_1 V_107 = F_3 ( V_5 , V_35 ) ;
if ( V_105 < 16 )
F_29 ( V_5 , V_34 , V_106 & ~ ( 3 << ( V_105 * 2 ) ) ) ;
else
F_29 ( V_5 , V_35 , V_107 & ~ ( 3 << ( ( V_105 - 16 ) * 2 ) ) ) ;
}
static inline void F_31 ( struct V_4 * V_5 , int V_108 )
{
T_1 V_109 = F_3 ( V_5 , V_17 ) ;
F_29 ( V_5 , V_17 ,
( V_109 & V_110 ) | ( V_108 & V_110 ) ) ;
}
static inline void F_32 ( struct V_4 * V_5 , int V_108 )
{
T_1 V_109 = F_3 ( V_5 , V_17 ) ;
F_29 ( V_5 , V_17 ,
( V_109 & V_110 ) & ~ ( V_108 & V_110 ) ) ;
}
static inline void F_33 ( struct V_44 * V_45 , int V_108 )
{
if ( F_34 ( V_45 ) )
V_108 |= V_111 ;
F_35 ( V_45 , V_56 , V_108 ) ;
}
static int F_36 ( struct V_44 * V_45 )
{
if ( V_45 -> V_97 )
return - V_112 ;
return F_9 ( V_45 , V_69 ) & 0x3ff ;
}
static int F_37 ( struct V_44 * V_45 )
{
int V_8 ;
if ( ! F_34 ( V_45 ) && V_45 -> V_97 )
return - V_112 ;
if ( F_34 ( V_45 ) )
V_8 = ! ( F_9 ( V_45 , V_56 ) & V_58 ) ;
else
V_8 = ! ( F_9 ( V_45 , V_56 ) & V_113 ) ;
return V_8 ;
}
static int F_38 ( struct V_44 * V_45 )
{
if ( F_34 ( V_45 ) )
return ( F_9 ( V_45 , V_56 ) & V_62 ) ;
if ( ! V_45 -> V_97 )
return - V_112 ;
return ( ! ( F_9 ( V_45 , V_56 ) & V_114 ) ) ;
}
static int F_39 ( struct V_44 * V_45 )
{
if ( ! F_34 ( V_45 ) && V_45 -> V_97 )
return - V_112 ;
if ( F_34 ( V_45 ) )
return ( F_9 ( V_45 , V_56 ) & V_63 ) ;
return ( F_9 ( V_45 , V_56 ) & V_115 ) ;
}
static void F_40 ( struct V_4 * V_5 , int V_75 )
{
struct V_44 * V_45 = & V_5 -> V_44 [ 0 ] ;
char * V_116 = F_41 ( V_5 ) ;
V_5 -> V_117 = V_75 ;
F_42 ( V_45 , L_42 , V_116 ,
F_41 ( V_5 ) , F_9 ( V_45 , V_56 ) ,
F_9 ( V_45 , V_69 ) ) ;
}
static void F_43 ( struct V_4 * V_90 )
{
F_40 ( V_90 , V_118 ) ;
}
static void F_44 ( struct V_44 * V_45 , int V_119 )
{
if ( V_119 )
V_45 -> V_39 . V_65 ++ ;
else
V_45 -> V_39 . V_67 ++ ;
}
static void F_45 ( struct V_44 * V_45 , int V_120 , int V_119 )
{
if ( V_119 )
V_45 -> V_39 . V_64 += V_120 ;
else
V_45 -> V_39 . V_66 += V_120 ;
}
static T_2 void F_46 ( struct V_44 * V_45 )
{
T_1 V_121 ;
V_121 = ( ( V_45 -> V_92 << V_122 ) & V_123 )
| ( ( V_45 -> V_93 << V_124 ) & V_125 )
| ( ( V_45 -> V_98 << V_126 ) & V_127 )
| ( ( F_47 ( V_45 ) << V_128 ) & V_129 )
| ( ( F_48 ( V_45 ) << V_130 ) & V_131 )
| ( ( V_45 -> V_97 ) ? V_132 : 0 )
| ( ( V_45 -> V_51 << V_133 ) & V_134 )
| V_135 ;
F_35 ( V_45 , V_17 , V_121 ) ;
}
static T_2 void F_49 ( struct V_4 * V_90 )
{
unsigned int V_48 ;
F_50 ( V_90 -> V_90 , L_43 , V_136 , V_90 ) ;
for ( V_48 = 1 ; V_48 < V_50 ; V_48 ++ )
F_46 ( & V_90 -> V_44 [ V_48 ] ) ;
}
static struct V_137 *
F_51 ( struct V_138 * V_139 , T_3 V_140 )
{
struct V_46 * V_47 ;
V_47 = F_52 ( sizeof *V_47 , V_140 ) ;
if ( ! V_47 )
return NULL ;
F_53 ( & V_47 -> V_52 ) ;
V_47 -> V_141 = 0 ;
V_47 -> V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
return & V_47 -> V_47 ;
}
static void F_55 ( struct V_138 * V_139 , struct V_137 * V_142 )
{
struct V_46 * V_47 ;
V_47 = F_54 ( V_142 , struct V_46 , V_47 ) ;
F_56 ( ! F_6 ( & V_47 -> V_52 ) ) ;
F_57 ( V_47 ) ;
}
static void F_58 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
if ( F_59 ( ! V_47 ) )
return;
F_60 ( V_45 , L_44 , V_47 ,
V_47 -> V_47 . V_54 , F_9 ( V_45 , V_56 ) ) ;
V_47 -> V_141 = 1 ;
F_61 ( & V_47 -> V_52 , & V_45 -> V_52 ) ;
F_27 ( V_45 ) ;
}
static void F_62 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
if ( F_59 ( ! V_47 ) )
return;
F_60 ( V_45 , L_44 , V_47 ,
V_47 -> V_47 . V_54 , F_9 ( V_45 , V_56 ) ) ;
F_63 ( & V_47 -> V_52 ) ;
V_47 -> V_141 = 0 ;
if ( ! F_34 ( V_45 ) && F_6 ( & V_45 -> V_52 ) )
F_30 ( V_45 ) ;
}
static void F_64 ( struct V_44 * V_45 , struct V_46 * V_47 , int V_143 ,
unsigned long * V_144 )
{
unsigned long V_145 ;
F_62 ( V_45 , V_47 ) ;
if ( F_65 ( V_47 -> V_47 . V_143 == - V_146 ) )
V_47 -> V_47 . V_143 = V_143 ;
else
V_143 = V_47 -> V_47 . V_143 ;
if ( V_143 && V_143 != - V_147 )
F_42 ( V_45 , L_45 ,
& V_47 -> V_47 , V_143 ,
V_47 -> V_47 . V_53 , V_47 -> V_47 . V_54 ) ;
if ( V_144 )
F_66 ( & V_45 -> V_148 , * V_144 ) ;
F_67 ( V_145 ) ;
V_47 -> V_47 . V_149 ( & V_47 -> V_91 -> V_138 , & V_47 -> V_47 ) ;
F_68 ( V_145 ) ;
if ( V_144 )
F_69 ( & V_45 -> V_148 , * V_144 ) ;
}
static void F_70 ( struct V_44 * V_45 , struct V_46 * V_47 ,
unsigned long * V_144 )
{
F_44 ( V_45 , ! V_150 ) ;
F_64 ( V_45 , V_47 , 0 , V_144 ) ;
}
static void F_71 ( struct V_44 * V_45 , struct V_46 * V_47 ,
unsigned long * V_144 )
{
F_40 ( V_45 -> V_90 , V_151 ) ;
F_70 ( V_45 , V_47 , V_144 ) ;
F_43 ( V_45 -> V_90 ) ;
}
static void F_72 ( struct V_44 * V_45 , struct V_46 * V_47 ,
unsigned long * V_144 )
{
F_44 ( V_45 , V_150 ) ;
F_64 ( V_45 , V_47 , 0 , V_144 ) ;
}
static void F_73 ( struct V_44 * V_45 , struct V_46 * V_47 ,
unsigned long * V_144 )
{
F_40 ( V_45 -> V_90 , V_152 ) ;
F_72 ( V_45 , V_47 , V_144 ) ;
}
static void F_74 ( struct V_44 * V_45 , int V_143 )
{
struct V_46 * V_47 ;
unsigned long V_145 ;
F_69 ( & V_45 -> V_148 , V_145 ) ;
while ( ! F_6 ( & V_45 -> V_52 ) ) {
V_47 = F_75 ( V_45 -> V_52 . V_153 , struct V_46 , V_52 ) ;
F_64 ( V_45 , V_47 , V_143 , & V_145 ) ;
}
F_66 ( & V_45 -> V_148 , V_145 ) ;
}
static int F_76 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
T_1 * V_55 ;
int V_154 , V_155 , V_120 , V_48 ;
V_154 = F_36 ( V_45 ) ;
V_155 = V_47 -> V_47 . V_54 - V_47 -> V_47 . V_53 ;
V_55 = ( T_1 * ) ( V_47 -> V_47 . V_55 + V_47 -> V_47 . V_53 ) ;
F_77 ( V_55 ) ;
if ( F_65 ( ! F_37 ( V_45 ) ) )
V_120 = F_78 ( V_154 , V_155 ) ;
else
V_120 = 0 ;
for ( V_48 = V_120 ; V_48 > 0 ; V_48 -= 4 )
* V_55 ++ = F_9 ( V_45 , V_156 ) ;
V_47 -> V_47 . V_53 += V_120 ;
F_33 ( V_45 , V_115 ) ;
return V_120 ;
}
static int F_79 ( struct V_44 * V_45 , struct V_46 * V_47 ,
unsigned int V_157 )
{
int V_54 , V_120 , V_158 , V_48 ;
T_1 * V_55 ;
T_4 * V_159 ;
V_55 = ( T_1 * ) ( V_47 -> V_47 . V_55 + V_47 -> V_47 . V_53 ) ;
F_80 ( V_55 ) ;
V_54 = F_78 ( V_47 -> V_47 . V_54 - V_47 -> V_47 . V_53 , V_157 ) ;
V_47 -> V_47 . V_53 += V_54 ;
V_158 = V_54 & 0x3 ;
V_120 = V_54 & ~ ( 0x3 ) ;
for ( V_48 = V_120 ; V_48 > 0 ; V_48 -= 4 )
F_35 ( V_45 , V_156 , * V_55 ++ ) ;
V_159 = ( T_4 * ) V_55 ;
for ( V_48 = V_158 ; V_48 > 0 ; V_48 -- )
F_81 ( V_45 , V_156 , * V_159 ++ ) ;
F_60 ( V_45 , L_46 , V_120 , V_158 ,
F_9 ( V_45 , V_56 ) ) ;
return V_54 ;
}
static int F_82 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
int V_120 , V_160 , V_161 = 0 ;
while ( F_39 ( V_45 ) ) {
V_120 = F_76 ( V_45 , V_47 ) ;
F_45 ( V_45 , V_120 , ! V_150 ) ;
V_160 = ( V_120 < V_45 -> V_51 ) ;
F_42 ( V_45 , L_47 ,
F_9 ( V_45 , V_56 ) , V_120 , V_160 ? L_48 : L_7 ,
& V_47 -> V_47 , V_47 -> V_47 . V_53 , V_47 -> V_47 . V_54 ) ;
if ( V_160 || V_47 -> V_47 . V_53 == V_47 -> V_47 . V_54 ) {
V_161 = 1 ;
break;
}
}
return V_161 ;
}
static int F_83 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
unsigned V_157 ;
int V_120 , V_160 , V_162 = 0 , V_161 = 0 , V_163 = 0 ;
T_1 V_164 ;
V_157 = V_45 -> V_51 ;
do {
V_160 = 0 ;
V_164 = F_9 ( V_45 , V_56 ) ;
if ( V_164 & V_115 ) {
F_60 ( V_45 , L_49 ,
V_164 ) ;
F_33 ( V_45 , V_115 ) ;
}
if ( V_164 & V_165 ) {
F_60 ( V_45 , L_50 ,
V_164 ) ;
F_33 ( V_45 , V_165 ) ;
}
V_120 = F_79 ( V_45 , V_47 , V_157 ) ;
F_45 ( V_45 , V_120 , V_150 ) ;
V_163 += V_120 ;
if ( F_59 ( V_120 < V_157 ) ) {
V_162 = 1 ;
V_160 = 1 ;
} else {
if ( F_65 ( V_47 -> V_47 . V_54 > V_47 -> V_47 . V_53 )
|| V_47 -> V_47 . V_166 )
V_162 = 0 ;
else
V_162 = 1 ;
V_160 = F_59 ( V_157 < V_45 -> V_51 ) ;
}
if ( V_160 )
F_33 ( V_45 , V_167 ) ;
if ( V_162 ) {
V_161 = 1 ;
break;
}
} while ( ! F_38 ( V_45 ) );
F_42 ( V_45 , L_51 ,
V_163 , V_162 ? L_52 : L_7 , V_160 ? L_48 : L_7 ,
V_47 -> V_47 . V_54 - V_47 -> V_47 . V_53 , & V_47 -> V_47 ) ;
return V_161 ;
}
static int F_84 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
int V_120 , V_160 , V_161 = 0 ;
while ( F_39 ( V_45 ) ) {
V_120 = F_76 ( V_45 , V_47 ) ;
F_33 ( V_45 , V_63 ) ;
F_45 ( V_45 , V_120 , ! V_150 ) ;
V_160 = ( V_120 < V_45 -> V_51 ) ;
F_42 ( V_45 , L_47 ,
F_9 ( V_45 , V_56 ) , V_120 , V_160 ? L_48 : L_7 ,
& V_47 -> V_47 , V_47 -> V_47 . V_53 , V_47 -> V_47 . V_54 ) ;
if ( V_160 || V_47 -> V_47 . V_53 >= V_47 -> V_47 . V_54 ) {
V_161 = 1 ;
break;
}
}
return V_161 ;
}
static int F_85 ( struct V_44 * V_45 , struct V_46 * V_47 )
{
unsigned V_120 ;
int V_162 , V_160 ;
V_120 = F_79 ( V_45 , V_47 , V_168 ) ;
F_45 ( V_45 , V_120 , V_150 ) ;
V_160 = ( V_120 < V_168 ) ;
V_162 = ( ( V_120 == 0 ) || ( V_120 < V_168 ) ) ;
if ( F_59 ( V_160 ) )
F_33 ( V_45 , V_62 ) ;
F_42 ( V_45 , L_53 ,
V_120 , V_160 ? L_48 : L_7 , V_162 ? L_52 : L_7 ,
V_47 -> V_47 . V_54 - V_47 -> V_47 . V_53 ,
& V_47 -> V_47 , F_9 ( V_45 , V_56 ) ) ;
return V_162 ;
}
static int F_86 ( struct V_138 * V_139 , struct V_137 * V_142 ,
T_3 V_140 )
{
struct V_91 * V_91 ;
struct V_44 * V_45 ;
struct V_46 * V_47 ;
struct V_4 * V_90 ;
unsigned long V_145 ;
int V_169 = 0 ;
int V_170 ;
unsigned V_54 ;
int V_171 ;
V_47 = F_54 ( V_142 , struct V_46 , V_47 ) ;
V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
if ( F_59 ( ! V_142 || ! V_142 -> V_149 || ! V_142 -> V_55 ) )
return - V_172 ;
if ( F_59 ( ! V_139 ) )
return - V_172 ;
V_90 = V_91 -> V_90 ;
V_45 = V_91 -> V_44 ;
if ( F_59 ( ! V_45 ) )
return - V_172 ;
V_90 = V_45 -> V_90 ;
if ( F_59 ( ! V_90 -> V_11 || V_90 -> V_78 . V_173 == V_174 ) ) {
F_42 ( V_45 , L_54 ) ;
return - V_147 ;
}
if ( F_59 ( F_87 ( V_45 )
&& V_47 -> V_47 . V_54 > V_45 -> V_51 ) )
return - V_175 ;
F_69 ( & V_45 -> V_148 , V_145 ) ;
V_171 = V_45 -> V_176 ;
V_170 = F_6 ( & V_45 -> V_52 ) ;
F_42 ( V_45 , L_55 ,
V_142 , V_170 ? L_56 : L_57 ,
V_142 -> V_54 , V_142 -> V_55 ) ;
if ( ! V_45 -> V_177 ) {
V_142 -> V_143 = - V_147 ;
V_169 = - V_147 ;
goto V_178;
}
if ( V_47 -> V_141 ) {
F_88 ( V_45 , L_58 , V_47 ) ;
goto V_178;
}
V_54 = V_142 -> V_54 ;
V_142 -> V_143 = - V_146 ;
V_142 -> V_53 = 0 ;
F_58 ( V_45 , V_47 ) ;
F_66 ( & V_45 -> V_148 , V_145 ) ;
if ( F_34 ( V_45 ) ) {
switch ( V_90 -> V_117 ) {
case V_179 :
if ( V_54 == 0 ) {
F_72 ( V_45 , V_47 , NULL ) ;
} else {
F_88 ( V_45 , L_59
L_60 ,
V_54 ) ;
F_62 ( V_45 , V_47 ) ;
V_169 = - V_180 ;
}
F_43 ( V_45 -> V_90 ) ;
break;
case V_181 :
if ( ! F_38 ( V_45 ) )
if ( F_85 ( V_45 , V_47 ) )
F_73 ( V_45 , V_47 , NULL ) ;
break;
case V_182 :
if ( ( V_54 == 0 ) || ! F_39 ( V_45 ) )
if ( F_84 ( V_45 , V_47 ) )
F_71 ( V_45 , V_47 , NULL ) ;
break;
default:
F_88 ( V_45 , L_61 ,
F_41 ( V_45 -> V_90 ) ) ;
F_62 ( V_45 , V_47 ) ;
V_169 = - V_180 ;
break;
}
} else {
if ( ! V_171 )
F_89 ( V_45 ) ;
}
V_12:
return V_169 ;
V_178:
F_66 ( & V_45 -> V_148 , V_145 ) ;
goto V_12;
}
static int F_90 ( struct V_138 * V_139 , struct V_137 * V_142 )
{
struct V_44 * V_45 ;
struct V_91 * V_91 ;
struct V_46 * V_47 ;
unsigned long V_145 ;
int V_169 = - V_172 ;
if ( ! V_139 )
return V_169 ;
V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
V_45 = V_91 -> V_44 ;
if ( ! V_45 || F_34 ( V_45 ) )
return V_169 ;
F_69 ( & V_45 -> V_148 , V_145 ) ;
F_7 (req, &ep->queue, queue) {
if ( & V_47 -> V_47 == V_142 ) {
V_169 = 0 ;
break;
}
}
F_66 ( & V_45 -> V_148 , V_145 ) ;
if ( ! V_169 )
F_64 ( V_45 , V_47 , - V_183 , NULL ) ;
return V_169 ;
}
static int F_91 ( struct V_138 * V_139 , int V_184 )
{
struct V_44 * V_45 ;
struct V_91 * V_91 ;
unsigned long V_145 ;
int V_169 ;
if ( ! V_139 )
return - V_172 ;
V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
V_45 = V_91 -> V_44 ;
if ( ! V_45 || F_34 ( V_45 ) )
return - V_172 ;
if ( V_184 == 0 ) {
F_42 ( V_45 , L_62 ) ;
return - V_185 ;
}
F_69 ( & V_45 -> V_148 , V_145 ) ;
V_169 = - V_186 ;
if ( V_45 -> V_97 && ( F_38 ( V_45 ) || ! F_6 ( & V_45 -> V_52 ) ) )
goto V_12;
V_169 = 0 ;
F_33 ( V_45 , V_187 | V_188 ) ;
if ( F_34 ( V_45 ) )
F_40 ( V_45 -> V_90 , V_189 ) ;
V_12:
F_66 ( & V_45 -> V_148 , V_145 ) ;
return V_169 ;
}
static int F_92 ( struct V_138 * V_139 )
{
struct V_44 * V_45 ;
struct V_91 * V_91 ;
if ( ! V_139 )
return - V_10 ;
V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
V_45 = V_91 -> V_44 ;
if ( ! V_45 || F_34 ( V_45 ) )
return - V_10 ;
if ( V_45 -> V_97 )
return - V_112 ;
if ( V_45 -> V_90 -> V_78 . V_173 == V_174 || F_37 ( V_45 ) )
return 0 ;
else
return F_36 ( V_45 ) + 1 ;
}
static void F_93 ( struct V_138 * V_139 )
{
struct V_44 * V_45 ;
struct V_91 * V_91 ;
unsigned long V_145 ;
if ( ! V_139 )
return;
V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
V_45 = V_91 -> V_44 ;
if ( ! V_45 || F_34 ( V_45 ) )
return;
F_69 ( & V_45 -> V_148 , V_145 ) ;
if ( F_59 ( ! F_6 ( & V_45 -> V_52 ) ) )
F_42 ( V_45 , L_63 ) ;
F_42 ( V_45 , L_64 ) ;
if ( ! V_45 -> V_97 ) {
while ( ! F_37 ( V_45 ) )
F_9 ( V_45 , V_156 ) ;
} else {
F_33 ( V_45 ,
V_115 | V_188 | V_165
| ( F_87 ( V_45 ) ? 0 : V_190 ) ) ;
}
F_66 ( & V_45 -> V_148 , V_145 ) ;
}
static int F_94 ( struct V_138 * V_139 ,
const struct V_191 * V_95 )
{
struct V_44 * V_45 ;
struct V_91 * V_91 ;
struct V_4 * V_5 ;
if ( ! V_139 || ! V_95 )
return - V_172 ;
V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
if ( V_91 -> V_44 ) {
V_45 = V_91 -> V_44 ;
F_95 ( V_45 , L_65 ,
V_139 -> V_16 ) ;
} else {
V_45 = F_25 ( V_91 -> V_90 , V_91 ) ;
}
if ( ! V_45 || F_34 ( V_45 ) ) {
F_19 ( V_91 -> V_90 -> V_90 ,
L_66 ,
V_139 -> V_16 ) ;
return - V_172 ;
}
if ( ( V_95 -> V_192 != V_193 )
|| ( V_45 -> type != F_24 ( V_95 ) ) ) {
F_88 ( V_45 , L_67 ) ;
return - V_172 ;
}
if ( V_45 -> V_51 < F_96 ( V_95 ) ) {
F_88 ( V_45 , L_68 ) ;
return - V_194 ;
}
V_91 -> V_44 = V_45 ;
V_5 = V_45 -> V_90 ;
if ( ! V_5 -> V_11 || V_5 -> V_78 . V_173 == V_174 ) {
F_88 ( V_45 , L_54 ) ;
return - V_147 ;
}
V_45 -> V_177 = 1 ;
F_93 ( V_139 ) ;
F_42 ( V_45 , L_69 ) ;
return 0 ;
}
static int F_97 ( struct V_138 * V_139 )
{
struct V_44 * V_45 ;
struct V_91 * V_91 ;
if ( ! V_139 )
return - V_172 ;
V_91 = F_54 ( V_139 , struct V_91 , V_138 ) ;
V_45 = V_91 -> V_44 ;
if ( ! V_45 || F_34 ( V_45 ) || ! F_6 ( & V_45 -> V_52 ) )
return - V_172 ;
V_45 -> V_177 = 0 ;
F_74 ( V_45 , - V_147 ) ;
F_93 ( V_139 ) ;
V_91 -> V_44 = NULL ;
F_42 ( V_45 , L_70 ) ;
return 0 ;
}
static void F_98 ( struct V_4 * V_5 , int V_195 )
{
if ( V_195 ) {
if ( F_99 ( V_5 -> V_196 -> V_197 ) )
F_100 ( V_5 -> V_196 -> V_197 ,
! V_5 -> V_196 -> V_198 ) ;
if ( V_5 -> V_196 -> V_199 )
V_5 -> V_196 -> V_199 ( V_200 ) ;
} else {
if ( F_99 ( V_5 -> V_196 -> V_197 ) )
F_100 ( V_5 -> V_196 -> V_197 ,
V_5 -> V_196 -> V_198 ) ;
if ( V_5 -> V_196 -> V_199 )
V_5 -> V_196 -> V_199 ( V_201 ) ;
}
V_5 -> V_202 = V_195 ;
}
static int F_101 ( struct V_203 * V_204 )
{
struct V_4 * V_5 = F_102 ( V_204 ) ;
return ( F_3 ( V_5 , V_38 ) & 0x7ff ) ;
}
static int F_103 ( struct V_203 * V_204 )
{
struct V_4 * V_5 = F_102 ( V_204 ) ;
if ( ( F_3 ( V_5 , V_17 ) & V_22 ) == 0 )
return - V_205 ;
F_31 ( V_5 , V_25 ) ;
return 0 ;
}
static int F_104 ( struct V_4 * V_5 )
{
int V_206 ;
V_206 = ( ( V_5 -> V_202 ) && ( V_5 -> V_11 ) ) ;
V_206 &= ( ( V_5 -> V_207 ) || ( F_105 ( V_5 -> V_208 ) ) ) ;
return V_206 ;
}
static int F_106 ( struct V_4 * V_5 )
{
int V_209 ;
V_209 = ( ( ! V_5 -> V_202 ) || ( ! V_5 -> V_11 ) ) ;
V_209 |= ( ( ! V_5 -> V_207 ) && ( ! F_105 ( V_5 -> V_208 ) ) ) ;
return V_209 ;
}
static int F_107 ( struct V_203 * V_204 , int V_210 )
{
struct V_4 * V_5 = F_102 ( V_204 ) ;
if ( ! F_99 ( V_5 -> V_196 -> V_197 ) && ! V_5 -> V_196 -> V_199 )
return - V_112 ;
F_98 ( V_5 , V_210 ) ;
if ( F_104 ( V_5 ) )
F_108 ( V_5 ) ;
if ( F_106 ( V_5 ) )
F_109 ( V_5 ) ;
return 0 ;
}
static int F_110 ( struct V_203 * V_204 , int V_210 )
{
struct V_4 * V_5 = F_102 ( V_204 ) ;
V_5 -> V_207 = V_210 ;
if ( F_104 ( V_5 ) )
F_108 ( V_5 ) ;
if ( F_106 ( V_5 ) )
F_109 ( V_5 ) ;
return 0 ;
}
static int F_111 ( struct V_203 * V_204 , unsigned V_211 )
{
struct V_4 * V_5 ;
V_5 = F_102 ( V_204 ) ;
if ( ! F_105 ( V_5 -> V_208 ) )
return F_112 ( V_5 -> V_208 , V_211 ) ;
return - V_112 ;
}
static void F_109 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_177 )
return;
F_29 ( V_5 , V_34 , 0 ) ;
F_29 ( V_5 , V_35 , 0 ) ;
F_32 ( V_5 , V_27 ) ;
F_113 ( V_5 -> V_212 ) ;
F_43 ( V_5 ) ;
V_5 -> V_78 . V_173 = V_174 ;
V_5 -> V_177 = 0 ;
}
static T_2 void F_114 ( struct V_4 * V_90 )
{
int V_48 ;
struct V_44 * V_45 ;
F_53 ( & V_90 -> V_78 . V_213 ) ;
F_53 ( & V_90 -> V_78 . V_214 -> V_213 ) ;
V_90 -> V_91 [ 0 ] . V_44 = & V_90 -> V_44 [ 0 ] ;
F_43 ( V_90 ) ;
for ( V_48 = 0 ; V_48 < V_50 ; V_48 ++ ) {
V_45 = & V_90 -> V_44 [ V_48 ] ;
V_45 -> V_177 = F_34 ( V_45 ) ;
F_53 ( & V_45 -> V_52 ) ;
F_115 ( & V_45 -> V_148 ) ;
}
for ( V_48 = 1 ; V_48 < V_104 ; V_48 ++ )
F_61 ( & V_90 -> V_91 [ V_48 ] . V_138 . V_213 ,
& V_90 -> V_78 . V_213 ) ;
}
static void F_108 ( struct V_4 * V_5 )
{
if ( V_5 -> V_177 )
return;
F_29 ( V_5 , V_34 , 0 ) ;
F_29 ( V_5 , V_35 , 0 ) ;
F_32 ( V_5 , V_27 ) ;
F_116 ( V_5 -> V_212 ) ;
F_43 ( V_5 ) ;
V_5 -> V_78 . V_173 = V_215 ;
memset ( & V_5 -> V_39 , 0 , sizeof( V_5 -> V_39 ) ) ;
F_31 ( V_5 , V_27 ) ;
F_33 ( & V_5 -> V_44 [ 0 ] , V_111 ) ;
F_117 ( 2 ) ;
if ( F_3 ( V_5 , V_17 ) & V_24 )
F_19 ( V_5 -> V_90 , L_71 ) ;
F_118 ( 100 ) ;
F_29 ( V_5 , V_35 ,
V_216 | V_217
| V_218 | V_219 ) ;
F_27 ( & V_5 -> V_44 [ 0 ] ) ;
V_5 -> V_177 = 1 ;
}
static int F_119 ( struct V_203 * V_220 ,
struct V_221 * V_11 )
{
struct V_4 * V_5 = F_120 ( V_220 ) ;
int V_222 ;
V_5 -> V_11 = V_11 ;
V_5 -> V_78 . V_90 . V_11 = & V_11 -> V_11 ;
F_98 ( V_5 , 1 ) ;
if ( ! F_105 ( V_5 -> V_208 ) ) {
V_222 = F_121 ( V_5 -> V_208 -> V_223 ,
& V_5 -> V_78 ) ;
if ( V_222 ) {
F_19 ( V_5 -> V_90 , L_72 ) ;
goto V_224;
}
}
if ( F_104 ( V_5 ) )
F_108 ( V_5 ) ;
return 0 ;
V_224:
V_5 -> V_11 = NULL ;
V_5 -> V_78 . V_90 . V_11 = NULL ;
return V_222 ;
}
static void F_122 ( struct V_4 * V_5 , struct V_221 * V_11 )
{
int V_48 ;
if ( V_5 -> V_78 . V_173 == V_174 )
V_11 = NULL ;
V_5 -> V_78 . V_173 = V_174 ;
for ( V_48 = 0 ; V_48 < V_104 ; V_48 ++ )
F_97 ( & V_5 -> V_91 [ V_48 ] . V_138 ) ;
}
static int F_123 ( struct V_203 * V_220 ,
struct V_221 * V_11 )
{
struct V_4 * V_5 = F_120 ( V_220 ) ;
F_122 ( V_5 , V_11 ) ;
F_109 ( V_5 ) ;
F_98 ( V_5 , 0 ) ;
V_5 -> V_11 = NULL ;
if ( ! F_105 ( V_5 -> V_208 ) )
return F_121 ( V_5 -> V_208 -> V_223 , NULL ) ;
return 0 ;
}
static void F_124 ( struct V_4 * V_5 ,
struct V_46 * V_47 )
{
struct V_44 * V_45 = & V_5 -> V_44 [ 0 ] ;
union {
struct V_225 V_226 ;
T_1 V_227 [ 2 ] ;
} V_228 ;
int V_48 ;
int V_229 = 0 ;
unsigned long V_145 ;
F_74 ( V_45 , - V_230 ) ;
F_69 ( & V_45 -> V_148 , V_145 ) ;
if ( F_39 ( V_45 ) && ( F_36 ( V_45 ) == 0 ) )
F_33 ( V_45 , V_63 ) ;
for ( V_48 = 0 ; V_48 < 2 ; V_48 ++ ) {
if ( F_59 ( F_37 ( V_45 ) ) )
goto V_231;
V_228 . V_227 [ V_48 ] = F_9 ( V_45 , V_156 ) ;
}
V_229 = ! F_37 ( V_45 ) ;
while ( ! F_37 ( V_45 ) ) {
V_48 = F_9 ( V_45 , V_156 ) ;
F_88 ( V_45 , L_73 , V_48 ) ;
}
F_42 ( V_45 , L_74 ,
V_228 . V_226 . V_232 , V_228 . V_226 . V_233 ,
F_125 ( V_228 . V_226 . V_234 ) , F_125 ( V_228 . V_226 . V_235 ) ,
F_125 ( V_228 . V_226 . V_236 ) ) ;
if ( F_59 ( V_229 ) )
goto V_231;
if ( V_228 . V_226 . V_232 & V_150 )
F_40 ( V_5 , V_181 ) ;
else
F_40 ( V_5 , V_182 ) ;
F_33 ( V_45 , V_57 | V_63 ) ;
F_66 ( & V_45 -> V_148 , V_145 ) ;
V_48 = V_5 -> V_11 -> V_237 ( & V_5 -> V_78 , & V_228 . V_226 ) ;
F_69 ( & V_45 -> V_148 , V_145 ) ;
if ( V_48 < 0 )
goto V_231;
V_12:
F_66 ( & V_45 -> V_148 , V_145 ) ;
return;
V_231:
F_42 ( V_45 , L_75 ,
F_9 ( V_45 , V_56 ) , V_48 ) ;
F_33 ( V_45 , V_59 | V_238 ) ;
F_40 ( V_5 , V_189 ) ;
goto V_12;
}
static void F_126 ( struct V_4 * V_5 , int V_239 , int V_240 )
{
T_1 V_241 ;
struct V_44 * V_45 = & V_5 -> V_44 [ 0 ] ;
struct V_46 * V_47 = NULL ;
int V_161 = 0 ;
if ( ! F_6 ( & V_45 -> V_52 ) )
V_47 = F_75 ( V_45 -> V_52 . V_153 , struct V_46 , V_52 ) ;
V_241 = F_9 ( V_45 , V_56 ) ;
F_42 ( V_45 , L_76 ,
F_41 ( V_5 ) , V_47 , V_241 , F_9 ( V_45 , V_69 ) ,
( V_239 << 1 | V_240 ) ) ;
if ( V_241 & V_60 ) {
F_42 ( V_45 , L_77 ) ;
F_74 ( V_45 , - V_242 ) ;
F_33 ( V_45 , V_60 ) ;
F_43 ( V_5 ) ;
}
if ( V_241 & V_57 ) {
F_74 ( V_45 , 0 ) ;
F_40 ( V_5 , V_243 ) ;
}
switch ( V_5 -> V_117 ) {
case V_118 :
break;
case V_243 :
V_241 &= V_244 ;
if ( F_65 ( V_241 == V_244 ) )
F_124 ( V_5 , V_47 ) ;
break;
case V_181 :
if ( F_39 ( V_45 ) )
F_33 ( V_45 , V_63 ) ;
if ( V_47 && ! F_38 ( V_45 ) )
V_161 = F_85 ( V_45 , V_47 ) ;
if ( V_161 )
F_73 ( V_45 , V_47 , NULL ) ;
break;
case V_182 :
if ( F_39 ( V_45 ) && V_47 )
V_161 = F_84 ( V_45 , V_47 ) ;
if ( V_161 )
F_71 ( V_45 , V_47 , NULL ) ;
break;
case V_189 :
F_33 ( V_45 , V_59 ) ;
break;
case V_152 :
if ( V_240 )
F_43 ( V_5 ) ;
break;
case V_151 :
case V_179 :
F_95 ( V_45 , L_78 ,
F_41 ( V_45 -> V_90 ) ) ;
F_43 ( V_5 ) ;
break;
}
}
static void F_89 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
int V_161 ;
T_1 V_164 ;
int V_119 = V_45 -> V_97 ;
int V_245 = 0 ;
unsigned long V_145 ;
F_69 ( & V_45 -> V_148 , V_145 ) ;
if ( V_45 -> V_176 )
goto V_171;
V_45 -> V_176 = 1 ;
do {
V_161 = 0 ;
V_164 = F_9 ( V_45 , V_56 ) ;
if ( F_65 ( ! F_6 ( & V_45 -> V_52 ) ) )
V_47 = F_75 ( V_45 -> V_52 . V_153 ,
struct V_46 , V_52 ) ;
else
V_47 = NULL ;
F_42 ( V_45 , L_79 ,
V_47 , V_164 , V_245 ++ ) ;
if ( F_59 ( V_164 & ( V_190 | V_165 ) ) )
F_35 ( V_45 , V_56 ,
V_164 & ( V_190 | V_165 ) ) ;
if ( ! V_47 )
break;
if ( F_59 ( V_119 ) ) {
if ( F_65 ( ! F_38 ( V_45 ) ) )
V_161 = F_83 ( V_45 , V_47 ) ;
} else {
if ( F_65 ( F_39 ( V_45 ) ) )
V_161 = F_82 ( V_45 , V_47 ) ;
}
if ( V_161 ) {
if ( V_119 )
F_72 ( V_45 , V_47 , & V_145 ) ;
else
F_70 ( V_45 , V_47 , & V_145 ) ;
}
} while ( V_161 );
V_45 -> V_176 = 0 ;
V_171:
F_66 ( & V_45 -> V_148 , V_145 ) ;
}
static void F_127 ( struct V_4 * V_5 , int V_92 )
{
struct V_225 V_47 ;
F_50 ( V_5 -> V_90 , L_80 , V_92 ) ;
V_5 -> V_92 = V_92 ;
V_5 -> V_101 = 0 ;
V_5 -> V_103 = 0 ;
V_47 . V_232 = 0 ;
V_47 . V_233 = V_246 ;
V_47 . V_234 = V_92 ;
V_47 . V_235 = 0 ;
V_47 . V_236 = 0 ;
F_40 ( V_5 , V_179 ) ;
V_5 -> V_11 -> V_237 ( & V_5 -> V_78 , & V_47 ) ;
F_33 ( & V_5 -> V_44 [ 0 ] , V_247 ) ;
}
static void F_128 ( struct V_4 * V_5 , int V_100 , int V_102 )
{
struct V_225 V_47 ;
F_50 ( V_5 -> V_90 , L_81 , V_100 , V_102 ) ;
V_5 -> V_101 = V_100 ;
V_5 -> V_103 = V_102 ;
V_47 . V_232 = V_248 ;
V_47 . V_233 = V_249 ;
V_47 . V_234 = V_102 ;
V_47 . V_235 = V_100 ;
V_47 . V_236 = 0 ;
F_40 ( V_5 , V_179 ) ;
V_5 -> V_11 -> V_237 ( & V_5 -> V_78 , & V_47 ) ;
F_33 ( & V_5 -> V_44 [ 0 ] , V_247 ) ;
}
static void F_129 ( int V_250 , struct V_4 * V_5 )
{
int V_48 ;
struct V_44 * V_45 ;
T_1 V_251 = F_3 ( V_5 , V_36 ) & V_252 ;
T_1 V_253 = F_3 ( V_5 , V_37 ) & V_254 ;
if ( V_251 & V_255 ) {
V_5 -> V_44 [ 0 ] . V_39 . V_68 ++ ;
F_29 ( V_5 , V_36 , F_130 ( 0 , V_255 ) ) ;
F_126 ( V_5 , ! ! ( V_251 & V_256 ) ,
! ! ( V_251 & V_257 ) ) ;
}
V_251 >>= 2 ;
for ( V_48 = 1 ; V_251 != 0 && V_48 < 16 ; V_251 >>= 2 , V_48 ++ ) {
if ( ! ( V_251 & V_255 ) )
continue;
F_29 ( V_5 , V_36 , F_130 ( V_48 , V_255 ) ) ;
F_56 ( V_48 >= F_131 ( V_5 -> V_44 ) ) ;
if ( V_48 < F_131 ( V_5 -> V_44 ) ) {
V_45 = & V_5 -> V_44 [ V_48 ] ;
V_45 -> V_39 . V_68 ++ ;
F_89 ( V_45 ) ;
}
}
for ( V_48 = 16 ; V_253 != 0 && V_48 < 24 ; V_253 >>= 2 , V_48 ++ ) {
F_29 ( V_5 , V_37 , F_130 ( V_48 - 16 , V_255 ) ) ;
if ( ! ( V_253 & V_255 ) )
continue;
F_56 ( V_48 >= F_131 ( V_5 -> V_44 ) ) ;
if ( V_48 < F_131 ( V_5 -> V_44 ) ) {
V_45 = & V_5 -> V_44 [ V_48 ] ;
V_45 -> V_39 . V_68 ++ ;
F_89 ( V_45 ) ;
}
}
}
static void F_132 ( struct V_4 * V_5 )
{
F_29 ( V_5 , V_37 , V_258 ) ;
V_5 -> V_39 . V_41 ++ ;
if ( V_5 -> V_78 . V_173 != V_174
&& V_5 -> V_11 && V_5 -> V_11 -> V_259 )
V_5 -> V_11 -> V_259 ( & V_5 -> V_78 ) ;
F_43 ( V_5 ) ;
}
static void F_133 ( struct V_4 * V_5 )
{
F_29 ( V_5 , V_37 , V_260 ) ;
V_5 -> V_39 . V_42 ++ ;
if ( V_5 -> V_78 . V_173 != V_174
&& V_5 -> V_11 && V_5 -> V_11 -> V_261 )
V_5 -> V_11 -> V_261 ( & V_5 -> V_78 ) ;
}
static void F_134 ( struct V_4 * V_5 )
{
unsigned V_92 , V_93 , V_98 , V_262 ;
T_1 V_109 = F_3 ( V_5 , V_17 ) ;
F_29 ( V_5 , V_37 , V_263 ) ;
V_5 -> V_39 . V_43 ++ ;
V_92 = ( V_109 & V_28 ) >> V_29 ;
V_262 = ( V_92 != V_5 -> V_92 ) ;
F_127 ( V_5 , V_92 ) ;
V_93 = ( V_109 & V_30 ) >> V_31 ;
V_98 = ( V_109 & V_32 ) >> V_33 ;
F_128 ( V_5 , V_93 , V_98 ) ;
if ( V_262 )
F_26 ( V_5 ) ;
F_31 ( V_5 , V_23 ) ;
}
static void F_135 ( struct V_4 * V_5 )
{
T_1 V_109 = F_3 ( V_5 , V_17 ) ;
struct V_44 * V_45 = & V_5 -> V_44 [ 0 ] ;
F_136 ( V_5 -> V_90 , L_82 ) ;
F_29 ( V_5 , V_37 , V_264 ) ;
V_5 -> V_39 . V_40 ++ ;
if ( ( V_109 & V_26 ) == 0 ) {
F_50 ( V_5 -> V_90 , L_83 ) ;
F_122 ( V_5 , V_5 -> V_11 ) ;
}
V_5 -> V_78 . V_173 = V_215 ;
memset ( & V_5 -> V_39 , 0 , sizeof V_5 -> V_39 ) ;
F_74 ( V_45 , - V_230 ) ;
F_33 ( V_45 , V_238 | V_63 ) ;
F_43 ( V_5 ) ;
}
static T_5 F_137 ( int V_250 , void * V_265 )
{
struct V_4 * V_5 = V_265 ;
T_1 V_251 = F_3 ( V_5 , V_36 ) ;
T_1 V_253 = F_3 ( V_5 , V_37 ) ;
T_1 V_109 = F_3 ( V_5 , V_17 ) ;
T_1 V_266 ;
F_138 ( V_5 -> V_90 , L_84
L_85 , V_251 , V_253 , V_109 ) ;
V_266 = V_253 & 0xf8000000 ;
if ( F_59 ( V_266 & V_258 ) )
F_132 ( V_5 ) ;
if ( F_59 ( V_266 & V_260 ) )
F_133 ( V_5 ) ;
if ( F_59 ( V_266 & V_263 ) )
F_134 ( V_5 ) ;
if ( F_59 ( V_266 & V_264 ) )
F_135 ( V_5 ) ;
if ( ( V_251 & V_252 ) | ( V_253 & V_254 ) )
F_129 ( V_250 , V_5 ) ;
return V_267 ;
}
static int T_2 F_139 ( struct V_268 * V_269 )
{
struct V_270 * V_271 ;
struct V_4 * V_5 = & V_272 ;
int V_222 = 0 , V_273 ;
V_271 = F_140 ( V_269 , V_274 , 0 ) ;
if ( ! V_271 )
return - V_275 ;
V_5 -> V_250 = F_141 ( V_269 , 0 ) ;
if ( V_5 -> V_250 < 0 )
return V_5 -> V_250 ;
V_5 -> V_90 = & V_269 -> V_90 ;
V_5 -> V_196 = V_269 -> V_90 . V_276 ;
V_5 -> V_208 = F_142 ( V_277 ) ;
V_273 = V_5 -> V_196 -> V_197 ;
if ( F_99 ( V_273 ) ) {
V_222 = F_143 ( V_273 , L_86 ) ;
if ( V_222 == 0 )
F_144 ( V_273 ,
V_5 -> V_196 -> V_198 ) ;
}
if ( V_222 ) {
F_19 ( & V_269 -> V_90 , L_87 ,
V_273 , V_222 ) ;
return V_222 ;
}
V_5 -> V_212 = F_145 ( & V_269 -> V_90 , NULL ) ;
if ( F_16 ( V_5 -> V_212 ) ) {
V_222 = F_146 ( V_5 -> V_212 ) ;
goto V_278;
}
V_222 = - V_279 ;
V_5 -> V_271 = F_147 ( V_271 -> V_280 , F_148 ( V_271 ) ) ;
if ( ! V_5 -> V_271 ) {
F_19 ( & V_269 -> V_90 , L_88 ) ;
goto V_281;
}
F_149 ( & V_5 -> V_78 . V_90 ) ;
V_5 -> V_78 . V_90 . V_282 = & V_269 -> V_90 ;
V_5 -> V_78 . V_90 . V_283 = NULL ;
V_5 -> V_207 = 0 ;
V_284 = V_5 ;
F_150 ( V_269 , V_5 ) ;
F_114 ( V_5 ) ;
F_49 ( V_5 ) ;
V_222 = F_151 ( V_5 -> V_250 , F_137 ,
V_285 , V_14 , V_5 ) ;
if ( V_222 != 0 ) {
F_19 ( V_5 -> V_90 , L_89 ,
V_14 , V_5 -> V_250 , V_222 ) ;
goto V_286;
}
V_222 = F_152 ( & V_5 -> V_78 . V_90 ) ;
if ( V_222 ) {
F_19 ( V_5 -> V_90 , L_90 , V_222 ) ;
goto V_287;
}
V_222 = F_153 ( & V_269 -> V_90 , & V_5 -> V_78 ) ;
if ( V_222 )
goto V_288;
F_14 ( V_5 ) ;
return 0 ;
V_288:
F_154 ( & V_5 -> V_78 . V_90 ) ;
V_287:
F_155 ( V_5 -> V_250 , V_5 ) ;
V_286:
F_156 ( V_5 -> V_271 ) ;
V_281:
F_157 ( V_5 -> V_212 ) ;
V_5 -> V_212 = NULL ;
V_278:
return V_222 ;
}
static int T_6 F_158 ( struct V_268 * V_265 )
{
struct V_4 * V_5 = F_159 ( V_265 ) ;
int V_273 = V_5 -> V_196 -> V_197 ;
F_160 ( & V_5 -> V_78 ) ;
F_161 ( & V_5 -> V_78 . V_90 ) ;
F_162 ( V_5 -> V_11 ) ;
F_155 ( V_5 -> V_250 , V_5 ) ;
F_20 ( V_5 ) ;
if ( F_99 ( V_273 ) )
F_163 ( V_273 ) ;
F_164 ( V_5 -> V_208 ) ;
V_5 -> V_208 = NULL ;
F_150 ( V_265 , NULL ) ;
V_284 = NULL ;
F_157 ( V_5 -> V_212 ) ;
F_156 ( V_5 -> V_271 ) ;
return 0 ;
}
static void F_165 ( struct V_268 * V_265 )
{
struct V_4 * V_5 = F_159 ( V_265 ) ;
if ( F_3 ( V_5 , V_17 ) & V_27 )
F_109 ( V_5 ) ;
}
static int F_166 ( struct V_268 * V_265 , T_7 V_75 )
{
int V_48 ;
struct V_4 * V_5 = F_159 ( V_265 ) ;
struct V_44 * V_45 ;
V_45 = & V_5 -> V_44 [ 0 ] ;
V_5 -> V_241 = F_9 ( V_45 , V_56 ) ;
for ( V_48 = 1 ; V_48 < V_50 ; V_48 ++ ) {
V_45 = & V_5 -> V_44 [ V_48 ] ;
V_45 -> V_289 = F_9 ( V_45 , V_56 ) ;
V_45 -> V_290 = F_9 ( V_45 , V_17 ) ;
F_42 ( V_45 , L_91 ,
V_45 -> V_289 , V_45 -> V_290 ) ;
}
F_109 ( V_5 ) ;
V_5 -> V_291 = V_5 -> V_202 ;
F_98 ( V_5 , 0 ) ;
return 0 ;
}
static int F_167 ( struct V_268 * V_265 )
{
int V_48 ;
struct V_4 * V_5 = F_159 ( V_265 ) ;
struct V_44 * V_45 ;
V_45 = & V_5 -> V_44 [ 0 ] ;
F_35 ( V_45 , V_56 , V_5 -> V_241 & ( V_59 | V_61 ) ) ;
for ( V_48 = 1 ; V_48 < V_50 ; V_48 ++ ) {
V_45 = & V_5 -> V_44 [ V_48 ] ;
F_35 ( V_45 , V_56 , V_45 -> V_289 ) ;
F_35 ( V_45 , V_17 , V_45 -> V_290 ) ;
F_42 ( V_45 , L_91 ,
V_45 -> V_289 , V_45 -> V_290 ) ;
}
F_98 ( V_5 , V_5 -> V_291 ) ;
if ( F_104 ( V_5 ) )
F_108 ( V_5 ) ;
F_168 () ;
return 0 ;
}
static int T_2 F_169 ( void )
{
if ( ! F_170 () && ! F_171 () )
return - V_10 ;
F_172 ( V_292 L_92 , V_14 , V_15 ) ;
return F_173 ( & V_293 , F_139 ) ;
}
static void T_6 F_174 ( void )
{
F_175 ( & V_293 ) ;
}
