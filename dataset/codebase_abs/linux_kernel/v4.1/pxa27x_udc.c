static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
T_1 V_7 ;
if ( ! V_5 -> V_8 )
return - V_9 ;
F_2 ( V_2 , V_10 L_1
L_2
L_3 ,
V_11 , V_12 ,
V_5 -> V_8 ? V_5 -> V_8 -> V_8 . V_13 : L_4 ) ;
V_7 = F_3 ( V_5 , V_14 ) ;
F_2 ( V_2 ,
L_5 ,
V_7 ,
( V_7 & V_15 ) ? L_6 : L_7 ,
( V_7 & V_16 ) ? L_8 : L_7 ,
( V_7 & V_17 ) ? L_9 : L_7 ,
( V_7 & V_18 ) ? L_10 : L_7 ,
( V_7 & V_19 ) ? L_11 : L_7 ,
( V_7 & V_20 ) ? L_12 : L_7 ,
( V_7 & V_21 ) ? L_13 : L_7 ,
( V_7 & V_22 ) ? L_14 : L_7 ,
( V_7 & V_23 ) ? L_15 : L_7 ,
( V_7 & V_24 ) ? L_16 : L_7 ,
( V_7 & V_25 ) >> V_26 ,
( V_7 & V_27 ) >> V_28 ,
( V_7 & V_29 ) >> V_30 ) ;
F_2 ( V_2 , L_17 ,
F_3 ( V_5 , V_31 ) , F_3 ( V_5 , V_32 ) ) ;
F_2 ( V_2 , L_18 ,
F_3 ( V_5 , V_33 ) , F_3 ( V_5 , V_34 ) ) ;
F_2 ( V_2 , L_19 , F_3 ( V_5 , V_35 ) ) ;
F_2 ( V_2 , L_20 ,
V_5 -> V_36 . V_37 , V_5 -> V_36 . V_38 ,
V_5 -> V_36 . V_39 , V_5 -> V_36 . V_40 ) ;
return 0 ;
}
static int F_4 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_45 , V_46 ;
if ( ! V_5 -> V_8 )
return - V_9 ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
V_42 = & V_5 -> V_41 [ V_45 ] ;
V_46 = V_42 -> V_48 ;
F_2 ( V_2 , L_21 ,
F_5 ( V_42 ) , V_46 , L_22 ) ;
if ( F_6 ( & V_42 -> V_49 ) ) {
F_7 ( V_2 , L_23 ) ;
continue;
}
F_8 (req, &ep->queue, queue) {
F_2 ( V_2 , L_24 ,
& V_44 -> V_44 , V_44 -> V_44 . V_50 ,
V_44 -> V_44 . V_51 , V_44 -> V_44 . V_52 ) ;
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , void * V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
struct V_41 * V_42 ;
int V_45 ;
T_1 V_7 ;
if ( ! V_5 -> V_8 )
return - V_9 ;
V_42 = & V_5 -> V_41 [ 0 ] ;
V_7 = F_10 ( V_42 , V_53 ) ;
F_2 ( V_2 , L_25 ,
V_7 ,
( V_7 & V_54 ) ? L_26 : L_7 ,
( V_7 & V_55 ) ? L_27 : L_7 ,
( V_7 & V_56 ) ? L_28 : L_7 ,
( V_7 & V_57 ) ? L_29 : L_7 ,
( V_7 & V_58 ) ? L_30 : L_7 ,
( V_7 & V_59 ) ? L_31 : L_7 ,
( V_7 & V_60 ) ? L_32 : L_7 ) ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
V_42 = & V_5 -> V_41 [ V_45 ] ;
V_7 = V_45 ? F_10 ( V_42 , V_14 ) : F_3 ( V_5 , V_14 ) ;
F_2 ( V_2 , L_33 ,
F_5 ( V_42 ) ,
V_42 -> V_36 . V_61 , V_42 -> V_36 . V_62 ,
V_42 -> V_36 . V_63 , V_42 -> V_36 . V_64 ,
V_42 -> V_36 . V_65 ,
V_7 , F_10 ( V_42 , V_53 ) ,
F_10 ( V_42 , V_66 ) ) ;
}
return 0 ;
}
static int F_11 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_12 ( V_68 , F_9 , V_67 -> V_69 ) ;
}
static int F_13 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_12 ( V_68 , F_4 , V_67 -> V_69 ) ;
}
static int F_14 ( struct V_67 * V_67 , struct V_68 * V_68 )
{
return F_12 ( V_68 , F_1 , V_67 -> V_69 ) ;
}
static void F_15 ( struct V_4 * V_5 )
{
struct V_70 * V_71 , * V_72 , * V_73 , * V_74 ;
V_71 = F_16 ( V_5 -> V_75 . V_13 , NULL ) ;
if ( F_17 ( V_71 ) || ! V_71 )
goto V_76;
V_72 = F_18 ( L_34 , 0400 , V_71 , V_5 ,
& V_77 ) ;
if ( ! V_72 )
goto V_78;
V_73 = F_18 ( L_35 , 0400 , V_71 , V_5 ,
& V_79 ) ;
if ( ! V_73 )
goto V_80;
V_74 = F_18 ( L_36 , 0400 , V_71 , V_5 ,
& V_81 ) ;
if ( ! V_74 )
goto V_82;
V_5 -> V_83 = V_71 ;
V_5 -> V_84 = V_72 ;
V_5 -> V_85 = V_73 ;
V_5 -> V_86 = V_74 ;
return;
V_82:
F_19 ( V_74 ) ;
V_80:
F_19 ( V_73 ) ;
V_78:
F_19 ( V_71 ) ;
V_76:
F_20 ( V_5 -> V_87 , L_37 ) ;
}
static void F_21 ( struct V_4 * V_5 )
{
F_19 ( V_5 -> V_86 ) ;
F_19 ( V_5 -> V_85 ) ;
F_19 ( V_5 -> V_84 ) ;
F_19 ( V_5 -> V_83 ) ;
V_5 -> V_86 = NULL ;
V_5 -> V_85 = NULL ;
V_5 -> V_84 = NULL ;
V_5 -> V_83 = NULL ;
}
static inline void F_15 ( struct V_4 * V_5 )
{
}
static inline void F_21 ( struct V_4 * V_5 )
{
}
static int F_22 ( struct V_88 * V_88 , struct V_41 * V_42 ,
int V_89 , int V_90 , int V_91 )
{
if ( F_23 ( & V_88 -> V_92 ) != V_42 -> V_93 )
return 0 ;
if ( F_24 ( & V_88 -> V_92 ) != V_42 -> V_94 )
return 0 ;
if ( F_25 ( & V_88 -> V_92 ) != V_42 -> type )
return 0 ;
if ( ( V_42 -> V_89 != V_89 ) || ( V_42 -> V_90 != V_90 )
|| ( V_42 -> V_95 != V_91 ) )
return 0 ;
return 1 ;
}
static struct V_41 * F_26 ( struct V_4 * V_5 ,
struct V_88 * V_88 )
{
int V_45 ;
struct V_41 * V_42 ;
int V_96 = V_5 -> V_89 ;
int V_97 = V_5 -> V_98 ;
int V_99 = V_5 -> V_100 ;
if ( V_88 == & V_5 -> V_88 [ 0 ] )
return & V_5 -> V_41 [ 0 ] ;
for ( V_45 = 1 ; V_45 < V_47 ; V_45 ++ ) {
V_42 = & V_5 -> V_41 [ V_45 ] ;
if ( F_22 ( V_88 , V_42 , V_96 , V_97 , V_99 ) )
return V_42 ;
}
return NULL ;
}
static void F_27 ( struct V_4 * V_5 )
{
int V_45 ;
struct V_88 * V_88 ;
for ( V_45 = 1 ; V_45 < V_101 ; V_45 ++ ) {
V_88 = & V_5 -> V_88 [ V_45 ] ;
if ( V_88 -> V_41 )
V_88 -> V_41 = F_26 ( V_5 , V_88 ) ;
}
}
static void F_28 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = V_42 -> V_87 ;
int V_102 = F_29 ( V_42 ) ;
T_1 V_103 = F_3 ( V_5 , V_31 ) ;
T_1 V_104 = F_3 ( V_5 , V_32 ) ;
if ( V_102 < 16 )
F_30 ( V_5 , V_31 , V_103 | ( 3 << ( V_102 * 2 ) ) ) ;
else
F_30 ( V_5 , V_32 , V_104 | ( 3 << ( ( V_102 - 16 ) * 2 ) ) ) ;
}
static void F_31 ( struct V_41 * V_42 )
{
struct V_4 * V_5 = V_42 -> V_87 ;
int V_102 = F_29 ( V_42 ) ;
T_1 V_103 = F_3 ( V_5 , V_31 ) ;
T_1 V_104 = F_3 ( V_5 , V_32 ) ;
if ( V_102 < 16 )
F_30 ( V_5 , V_31 , V_103 & ~ ( 3 << ( V_102 * 2 ) ) ) ;
else
F_30 ( V_5 , V_32 , V_104 & ~ ( 3 << ( ( V_102 - 16 ) * 2 ) ) ) ;
}
static inline void F_32 ( struct V_4 * V_5 , int V_105 )
{
T_1 V_106 = F_3 ( V_5 , V_14 ) ;
F_30 ( V_5 , V_14 ,
( V_106 & V_107 ) | ( V_105 & V_107 ) ) ;
}
static inline void F_33 ( struct V_4 * V_5 , int V_105 )
{
T_1 V_106 = F_3 ( V_5 , V_14 ) ;
F_30 ( V_5 , V_14 ,
( V_106 & V_107 ) & ~ ( V_105 & V_107 ) ) ;
}
static inline void F_34 ( struct V_41 * V_42 , int V_105 )
{
if ( F_35 ( V_42 ) )
V_105 |= V_108 ;
F_36 ( V_42 , V_53 , V_105 ) ;
}
static int F_37 ( struct V_41 * V_42 )
{
if ( V_42 -> V_94 )
return - V_109 ;
return F_10 ( V_42 , V_66 ) & 0x3ff ;
}
static int F_38 ( struct V_41 * V_42 )
{
int V_110 ;
if ( ! F_35 ( V_42 ) && V_42 -> V_94 )
return - V_109 ;
if ( F_35 ( V_42 ) )
V_110 = ! ( F_10 ( V_42 , V_53 ) & V_55 ) ;
else
V_110 = ! ( F_10 ( V_42 , V_53 ) & V_111 ) ;
return V_110 ;
}
static int F_39 ( struct V_41 * V_42 )
{
if ( F_35 ( V_42 ) )
return ( F_10 ( V_42 , V_53 ) & V_59 ) ;
if ( ! V_42 -> V_94 )
return - V_109 ;
return ( ! ( F_10 ( V_42 , V_53 ) & V_112 ) ) ;
}
static int F_40 ( struct V_41 * V_42 )
{
if ( ! F_35 ( V_42 ) && V_42 -> V_94 )
return - V_109 ;
if ( F_35 ( V_42 ) )
return ( F_10 ( V_42 , V_53 ) & V_60 ) ;
return ( F_10 ( V_42 , V_53 ) & V_113 ) ;
}
static void F_41 ( struct V_4 * V_5 , int V_72 )
{
struct V_41 * V_42 = & V_5 -> V_41 [ 0 ] ;
char * V_114 = F_42 ( V_5 ) ;
V_5 -> V_115 = V_72 ;
F_43 ( V_42 , L_38 , V_114 ,
F_42 ( V_5 ) , F_10 ( V_42 , V_53 ) ,
F_10 ( V_42 , V_66 ) ) ;
}
static void F_44 ( struct V_4 * V_87 )
{
F_41 ( V_87 , V_116 ) ;
}
static void F_45 ( struct V_41 * V_42 , int V_117 )
{
if ( V_117 )
V_42 -> V_36 . V_62 ++ ;
else
V_42 -> V_36 . V_64 ++ ;
}
static void F_46 ( struct V_41 * V_42 , int V_118 , int V_117 )
{
if ( V_117 )
V_42 -> V_36 . V_61 += V_118 ;
else
V_42 -> V_36 . V_63 += V_118 ;
}
static void F_47 ( struct V_41 * V_42 )
{
T_1 V_119 ;
V_119 = ( ( V_42 -> V_89 << V_120 ) & V_121 )
| ( ( V_42 -> V_90 << V_122 ) & V_123 )
| ( ( V_42 -> V_95 << V_124 ) & V_125 )
| ( ( F_48 ( V_42 ) << V_126 ) & V_127 )
| ( ( F_49 ( V_42 ) << V_128 ) & V_129 )
| ( ( V_42 -> V_94 ) ? V_130 : 0 )
| ( ( V_42 -> V_48 << V_131 ) & V_132 )
| V_133 ;
F_36 ( V_42 , V_14 , V_119 ) ;
}
static void F_50 ( struct V_4 * V_87 )
{
unsigned int V_45 ;
F_51 ( V_87 -> V_87 , L_39 , V_134 , V_87 ) ;
for ( V_45 = 1 ; V_45 < V_47 ; V_45 ++ )
F_47 ( & V_87 -> V_41 [ V_45 ] ) ;
}
static struct V_135 *
F_52 ( struct V_136 * V_137 , T_2 V_138 )
{
struct V_43 * V_44 ;
V_44 = F_53 ( sizeof *V_44 , V_138 ) ;
if ( ! V_44 )
return NULL ;
F_54 ( & V_44 -> V_49 ) ;
V_44 -> V_139 = 0 ;
V_44 -> V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
return & V_44 -> V_44 ;
}
static void F_56 ( struct V_136 * V_137 , struct V_135 * V_140 )
{
struct V_43 * V_44 ;
V_44 = F_55 ( V_140 , struct V_43 , V_44 ) ;
F_57 ( ! F_6 ( & V_44 -> V_49 ) ) ;
F_58 ( V_44 ) ;
}
static void F_59 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
if ( F_60 ( ! V_44 ) )
return;
F_61 ( V_42 , L_40 , V_44 ,
V_44 -> V_44 . V_51 , F_10 ( V_42 , V_53 ) ) ;
V_44 -> V_139 = 1 ;
F_62 ( & V_44 -> V_49 , & V_42 -> V_49 ) ;
F_28 ( V_42 ) ;
}
static void F_63 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
if ( F_60 ( ! V_44 ) )
return;
F_61 ( V_42 , L_40 , V_44 ,
V_44 -> V_44 . V_51 , F_10 ( V_42 , V_53 ) ) ;
F_64 ( & V_44 -> V_49 ) ;
V_44 -> V_139 = 0 ;
if ( ! F_35 ( V_42 ) && F_6 ( & V_42 -> V_49 ) )
F_31 ( V_42 ) ;
}
static void F_65 ( struct V_41 * V_42 , struct V_43 * V_44 , int V_141 ,
unsigned long * V_142 )
{
unsigned long V_143 ;
F_63 ( V_42 , V_44 ) ;
if ( F_66 ( V_44 -> V_44 . V_141 == - V_144 ) )
V_44 -> V_44 . V_141 = V_141 ;
else
V_141 = V_44 -> V_44 . V_141 ;
if ( V_141 && V_141 != - V_145 )
F_43 ( V_42 , L_41 ,
& V_44 -> V_44 , V_141 ,
V_44 -> V_44 . V_50 , V_44 -> V_44 . V_51 ) ;
if ( V_142 )
F_67 ( & V_42 -> V_146 , * V_142 ) ;
F_68 ( V_143 ) ;
F_69 ( & V_44 -> V_88 -> V_136 , & V_44 -> V_44 ) ;
F_70 ( V_143 ) ;
if ( V_142 )
F_71 ( & V_42 -> V_146 , * V_142 ) ;
}
static void F_72 ( struct V_41 * V_42 , struct V_43 * V_44 ,
unsigned long * V_142 )
{
F_45 ( V_42 , ! V_147 ) ;
F_65 ( V_42 , V_44 , 0 , V_142 ) ;
}
static void F_73 ( struct V_41 * V_42 , struct V_43 * V_44 ,
unsigned long * V_142 )
{
F_41 ( V_42 -> V_87 , V_148 ) ;
F_72 ( V_42 , V_44 , V_142 ) ;
F_44 ( V_42 -> V_87 ) ;
}
static void F_74 ( struct V_41 * V_42 , struct V_43 * V_44 ,
unsigned long * V_142 )
{
F_45 ( V_42 , V_147 ) ;
F_65 ( V_42 , V_44 , 0 , V_142 ) ;
}
static void F_75 ( struct V_41 * V_42 , struct V_43 * V_44 ,
unsigned long * V_142 )
{
F_41 ( V_42 -> V_87 , V_149 ) ;
F_74 ( V_42 , V_44 , V_142 ) ;
}
static void F_76 ( struct V_41 * V_42 , int V_141 )
{
struct V_43 * V_44 ;
unsigned long V_143 ;
F_71 ( & V_42 -> V_146 , V_143 ) ;
while ( ! F_6 ( & V_42 -> V_49 ) ) {
V_44 = F_77 ( V_42 -> V_49 . V_150 , struct V_43 , V_49 ) ;
F_65 ( V_42 , V_44 , V_141 , & V_143 ) ;
}
F_67 ( & V_42 -> V_146 , V_143 ) ;
}
static int F_78 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
T_1 * V_52 ;
int V_151 , V_152 , V_118 , V_45 ;
V_151 = F_37 ( V_42 ) ;
V_152 = V_44 -> V_44 . V_51 - V_44 -> V_44 . V_50 ;
V_52 = ( T_1 * ) ( V_44 -> V_44 . V_52 + V_44 -> V_44 . V_50 ) ;
F_79 ( V_52 ) ;
if ( F_66 ( ! F_38 ( V_42 ) ) )
V_118 = F_80 ( V_151 , V_152 ) ;
else
V_118 = 0 ;
for ( V_45 = V_118 ; V_45 > 0 ; V_45 -= 4 )
* V_52 ++ = F_10 ( V_42 , V_153 ) ;
V_44 -> V_44 . V_50 += V_118 ;
F_34 ( V_42 , V_113 ) ;
return V_118 ;
}
static int F_81 ( struct V_41 * V_42 , struct V_43 * V_44 ,
unsigned int V_154 )
{
int V_51 , V_118 , V_155 , V_45 ;
T_1 * V_52 ;
T_3 * V_156 ;
V_52 = ( T_1 * ) ( V_44 -> V_44 . V_52 + V_44 -> V_44 . V_50 ) ;
F_82 ( V_52 ) ;
V_51 = F_80 ( V_44 -> V_44 . V_51 - V_44 -> V_44 . V_50 , V_154 ) ;
V_44 -> V_44 . V_50 += V_51 ;
V_155 = V_51 & 0x3 ;
V_118 = V_51 & ~ ( 0x3 ) ;
for ( V_45 = V_118 ; V_45 > 0 ; V_45 -= 4 )
F_36 ( V_42 , V_153 , * V_52 ++ ) ;
V_156 = ( T_3 * ) V_52 ;
for ( V_45 = V_155 ; V_45 > 0 ; V_45 -- )
F_83 ( V_42 , V_153 , * V_156 ++ ) ;
F_61 ( V_42 , L_42 , V_118 , V_155 ,
F_10 ( V_42 , V_53 ) ) ;
return V_51 ;
}
static int F_84 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
int V_118 , V_157 , V_158 = 0 ;
while ( F_40 ( V_42 ) ) {
V_118 = F_78 ( V_42 , V_44 ) ;
F_46 ( V_42 , V_118 , ! V_147 ) ;
V_157 = ( V_118 < V_42 -> V_48 ) ;
F_43 ( V_42 , L_43 ,
F_10 ( V_42 , V_53 ) , V_118 , V_157 ? L_44 : L_7 ,
& V_44 -> V_44 , V_44 -> V_44 . V_50 , V_44 -> V_44 . V_51 ) ;
if ( V_157 || V_44 -> V_44 . V_50 == V_44 -> V_44 . V_51 ) {
V_158 = 1 ;
break;
}
}
return V_158 ;
}
static int F_85 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
unsigned V_154 ;
int V_118 , V_157 , V_159 = 0 , V_158 = 0 , V_160 = 0 ;
T_1 V_161 ;
V_154 = V_42 -> V_48 ;
do {
V_157 = 0 ;
V_161 = F_10 ( V_42 , V_53 ) ;
if ( V_161 & V_113 ) {
F_61 ( V_42 , L_45 ,
V_161 ) ;
F_34 ( V_42 , V_113 ) ;
}
if ( V_161 & V_162 ) {
F_61 ( V_42 , L_46 ,
V_161 ) ;
F_34 ( V_42 , V_162 ) ;
}
V_118 = F_81 ( V_42 , V_44 , V_154 ) ;
F_46 ( V_42 , V_118 , V_147 ) ;
V_160 += V_118 ;
if ( F_60 ( V_118 < V_154 ) ) {
V_159 = 1 ;
V_157 = 1 ;
} else {
if ( F_66 ( V_44 -> V_44 . V_51 > V_44 -> V_44 . V_50 )
|| V_44 -> V_44 . V_163 )
V_159 = 0 ;
else
V_159 = 1 ;
V_157 = F_60 ( V_154 < V_42 -> V_48 ) ;
}
if ( V_157 )
F_34 ( V_42 , V_164 ) ;
if ( V_159 ) {
V_158 = 1 ;
break;
}
} while ( ! F_39 ( V_42 ) );
F_43 ( V_42 , L_47 ,
V_160 , V_159 ? L_48 : L_7 , V_157 ? L_44 : L_7 ,
V_44 -> V_44 . V_51 - V_44 -> V_44 . V_50 , & V_44 -> V_44 ) ;
return V_158 ;
}
static int F_86 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
int V_118 , V_157 , V_158 = 0 ;
while ( F_40 ( V_42 ) ) {
V_118 = F_78 ( V_42 , V_44 ) ;
F_34 ( V_42 , V_60 ) ;
F_46 ( V_42 , V_118 , ! V_147 ) ;
V_157 = ( V_118 < V_42 -> V_48 ) ;
F_43 ( V_42 , L_43 ,
F_10 ( V_42 , V_53 ) , V_118 , V_157 ? L_44 : L_7 ,
& V_44 -> V_44 , V_44 -> V_44 . V_50 , V_44 -> V_44 . V_51 ) ;
if ( V_157 || V_44 -> V_44 . V_50 >= V_44 -> V_44 . V_51 ) {
V_158 = 1 ;
break;
}
}
return V_158 ;
}
static int F_87 ( struct V_41 * V_42 , struct V_43 * V_44 )
{
unsigned V_118 ;
int V_159 , V_157 ;
V_118 = F_81 ( V_42 , V_44 , V_165 ) ;
F_46 ( V_42 , V_118 , V_147 ) ;
V_157 = ( V_118 < V_165 ) ;
V_159 = ( ( V_118 == 0 ) || ( V_118 < V_165 ) ) ;
if ( F_60 ( V_157 ) )
F_34 ( V_42 , V_59 ) ;
F_43 ( V_42 , L_49 ,
V_118 , V_157 ? L_44 : L_7 , V_159 ? L_48 : L_7 ,
V_44 -> V_44 . V_51 - V_44 -> V_44 . V_50 ,
& V_44 -> V_44 , F_10 ( V_42 , V_53 ) ) ;
return V_159 ;
}
static int F_88 ( struct V_136 * V_137 , struct V_135 * V_140 ,
T_2 V_138 )
{
struct V_88 * V_88 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
struct V_4 * V_87 ;
unsigned long V_143 ;
int V_166 = 0 ;
int V_167 ;
unsigned V_51 ;
int V_168 ;
V_44 = F_55 ( V_140 , struct V_43 , V_44 ) ;
V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
if ( F_60 ( ! V_140 || ! V_140 -> V_169 || ! V_140 -> V_52 ) )
return - V_170 ;
if ( F_60 ( ! V_137 ) )
return - V_170 ;
V_87 = V_88 -> V_87 ;
V_42 = V_88 -> V_41 ;
if ( F_60 ( ! V_42 ) )
return - V_170 ;
V_87 = V_42 -> V_87 ;
if ( F_60 ( ! V_87 -> V_8 || V_87 -> V_75 . V_171 == V_172 ) ) {
F_43 ( V_42 , L_50 ) ;
return - V_145 ;
}
if ( F_60 ( F_89 ( V_42 )
&& V_44 -> V_44 . V_51 > V_42 -> V_48 ) )
return - V_173 ;
F_71 ( & V_42 -> V_146 , V_143 ) ;
V_168 = V_42 -> V_174 ;
V_167 = F_6 ( & V_42 -> V_49 ) ;
F_43 ( V_42 , L_51 ,
V_140 , V_167 ? L_52 : L_53 ,
V_140 -> V_51 , V_140 -> V_52 ) ;
if ( ! V_42 -> V_175 ) {
V_140 -> V_141 = - V_145 ;
V_166 = - V_145 ;
goto V_176;
}
if ( V_44 -> V_139 ) {
F_90 ( V_42 , L_54 , V_44 ) ;
goto V_176;
}
V_51 = V_140 -> V_51 ;
V_140 -> V_141 = - V_144 ;
V_140 -> V_50 = 0 ;
F_59 ( V_42 , V_44 ) ;
F_67 ( & V_42 -> V_146 , V_143 ) ;
if ( F_35 ( V_42 ) ) {
switch ( V_87 -> V_115 ) {
case V_177 :
if ( V_51 == 0 ) {
F_74 ( V_42 , V_44 , NULL ) ;
} else {
F_90 ( V_42 , L_55
L_56 ,
V_51 ) ;
F_63 ( V_42 , V_44 ) ;
V_166 = - V_178 ;
}
F_44 ( V_42 -> V_87 ) ;
break;
case V_179 :
if ( ! F_39 ( V_42 ) )
if ( F_87 ( V_42 , V_44 ) )
F_75 ( V_42 , V_44 , NULL ) ;
break;
case V_180 :
if ( ( V_51 == 0 ) || ! F_40 ( V_42 ) )
if ( F_86 ( V_42 , V_44 ) )
F_73 ( V_42 , V_44 , NULL ) ;
break;
default:
F_90 ( V_42 , L_57 ,
F_42 ( V_42 -> V_87 ) ) ;
F_63 ( V_42 , V_44 ) ;
V_166 = - V_178 ;
break;
}
} else {
if ( ! V_168 )
F_91 ( V_42 ) ;
}
V_181:
return V_166 ;
V_176:
F_67 ( & V_42 -> V_146 , V_143 ) ;
goto V_181;
}
static int F_92 ( struct V_136 * V_137 , struct V_135 * V_140 )
{
struct V_41 * V_42 ;
struct V_88 * V_88 ;
struct V_43 * V_44 ;
unsigned long V_143 ;
int V_166 = - V_170 ;
if ( ! V_137 )
return V_166 ;
V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
V_42 = V_88 -> V_41 ;
if ( ! V_42 || F_35 ( V_42 ) )
return V_166 ;
F_71 ( & V_42 -> V_146 , V_143 ) ;
F_8 (req, &ep->queue, queue) {
if ( & V_44 -> V_44 == V_140 ) {
V_166 = 0 ;
break;
}
}
F_67 ( & V_42 -> V_146 , V_143 ) ;
if ( ! V_166 )
F_65 ( V_42 , V_44 , - V_182 , NULL ) ;
return V_166 ;
}
static int F_93 ( struct V_136 * V_137 , int V_183 )
{
struct V_41 * V_42 ;
struct V_88 * V_88 ;
unsigned long V_143 ;
int V_166 ;
if ( ! V_137 )
return - V_170 ;
V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
V_42 = V_88 -> V_41 ;
if ( ! V_42 || F_35 ( V_42 ) )
return - V_170 ;
if ( V_183 == 0 ) {
F_43 ( V_42 , L_58 ) ;
return - V_184 ;
}
F_71 ( & V_42 -> V_146 , V_143 ) ;
V_166 = - V_185 ;
if ( V_42 -> V_94 && ( F_39 ( V_42 ) || ! F_6 ( & V_42 -> V_49 ) ) )
goto V_181;
V_166 = 0 ;
F_34 ( V_42 , V_186 | V_187 ) ;
if ( F_35 ( V_42 ) )
F_41 ( V_42 -> V_87 , V_188 ) ;
V_181:
F_67 ( & V_42 -> V_146 , V_143 ) ;
return V_166 ;
}
static int F_94 ( struct V_136 * V_137 )
{
struct V_41 * V_42 ;
struct V_88 * V_88 ;
if ( ! V_137 )
return - V_9 ;
V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
V_42 = V_88 -> V_41 ;
if ( ! V_42 || F_35 ( V_42 ) )
return - V_9 ;
if ( V_42 -> V_94 )
return - V_109 ;
if ( V_42 -> V_87 -> V_75 . V_171 == V_172 || F_38 ( V_42 ) )
return 0 ;
else
return F_37 ( V_42 ) + 1 ;
}
static void F_95 ( struct V_136 * V_137 )
{
struct V_41 * V_42 ;
struct V_88 * V_88 ;
unsigned long V_143 ;
if ( ! V_137 )
return;
V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
V_42 = V_88 -> V_41 ;
if ( ! V_42 || F_35 ( V_42 ) )
return;
F_71 ( & V_42 -> V_146 , V_143 ) ;
if ( F_60 ( ! F_6 ( & V_42 -> V_49 ) ) )
F_43 ( V_42 , L_59 ) ;
F_43 ( V_42 , L_60 ) ;
if ( ! V_42 -> V_94 ) {
while ( ! F_38 ( V_42 ) )
F_10 ( V_42 , V_153 ) ;
} else {
F_34 ( V_42 ,
V_113 | V_187 | V_162
| ( F_89 ( V_42 ) ? 0 : V_189 ) ) ;
}
F_67 ( & V_42 -> V_146 , V_143 ) ;
}
static int F_96 ( struct V_136 * V_137 ,
const struct V_190 * V_92 )
{
struct V_41 * V_42 ;
struct V_88 * V_88 ;
struct V_4 * V_5 ;
if ( ! V_137 || ! V_92 )
return - V_170 ;
V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
if ( V_88 -> V_41 ) {
V_42 = V_88 -> V_41 ;
F_97 ( V_42 , L_61 ,
V_137 -> V_13 ) ;
} else {
V_42 = F_26 ( V_88 -> V_87 , V_88 ) ;
}
if ( ! V_42 || F_35 ( V_42 ) ) {
F_20 ( V_88 -> V_87 -> V_87 ,
L_62 ,
V_137 -> V_13 ) ;
return - V_170 ;
}
if ( ( V_92 -> V_191 != V_192 )
|| ( V_42 -> type != F_25 ( V_92 ) ) ) {
F_90 ( V_42 , L_63 ) ;
return - V_170 ;
}
if ( V_42 -> V_48 < F_98 ( V_92 ) ) {
F_90 ( V_42 , L_64 ) ;
return - V_193 ;
}
V_88 -> V_41 = V_42 ;
V_5 = V_42 -> V_87 ;
if ( ! V_5 -> V_8 || V_5 -> V_75 . V_171 == V_172 ) {
F_90 ( V_42 , L_50 ) ;
return - V_145 ;
}
V_42 -> V_175 = 1 ;
F_95 ( V_137 ) ;
F_43 ( V_42 , L_65 ) ;
return 0 ;
}
static int F_99 ( struct V_136 * V_137 )
{
struct V_41 * V_42 ;
struct V_88 * V_88 ;
if ( ! V_137 )
return - V_170 ;
V_88 = F_55 ( V_137 , struct V_88 , V_136 ) ;
V_42 = V_88 -> V_41 ;
if ( ! V_42 || F_35 ( V_42 ) || ! F_6 ( & V_42 -> V_49 ) )
return - V_170 ;
V_42 -> V_175 = 0 ;
F_76 ( V_42 , - V_145 ) ;
F_95 ( V_137 ) ;
V_88 -> V_41 = NULL ;
F_43 ( V_42 , L_66 ) ;
return 0 ;
}
static void F_100 ( struct V_4 * V_5 , int V_194 )
{
if ( V_5 -> V_195 ) {
F_101 ( V_5 -> V_195 , V_194 ) ;
} else if ( V_5 -> V_196 ) {
if ( V_194 )
V_5 -> V_196 ( V_197 ) ;
else
V_5 -> V_196 ( V_198 ) ;
}
V_5 -> V_199 = V_194 ;
}
static int F_102 ( struct V_200 * V_201 )
{
struct V_4 * V_5 = F_103 ( V_201 ) ;
return ( F_3 ( V_5 , V_35 ) & 0x7ff ) ;
}
static int F_104 ( struct V_200 * V_201 )
{
struct V_4 * V_5 = F_103 ( V_201 ) ;
if ( ( F_3 ( V_5 , V_14 ) & V_19 ) == 0 )
return - V_202 ;
F_32 ( V_5 , V_22 ) ;
return 0 ;
}
static int F_105 ( struct V_4 * V_5 )
{
int V_203 ;
V_203 = ( ( V_5 -> V_199 ) && ( V_5 -> V_8 ) ) ;
V_203 &= ( ( V_5 -> V_204 ) || ( F_106 ( V_5 -> V_205 ) ) ) ;
return V_203 ;
}
static int F_107 ( struct V_4 * V_5 )
{
int V_206 ;
V_206 = ( ( ! V_5 -> V_199 ) || ( ! V_5 -> V_8 ) ) ;
V_206 |= ( ( ! V_5 -> V_204 ) && ( ! F_106 ( V_5 -> V_205 ) ) ) ;
return V_206 ;
}
static int F_108 ( struct V_200 * V_201 , int V_207 )
{
struct V_4 * V_5 = F_103 ( V_201 ) ;
if ( ! V_5 -> V_195 && ! V_5 -> V_196 )
return - V_109 ;
F_100 ( V_5 , V_207 ) ;
if ( F_105 ( V_5 ) )
F_109 ( V_5 ) ;
if ( F_107 ( V_5 ) )
F_110 ( V_5 ) ;
return 0 ;
}
static int F_111 ( struct V_200 * V_201 , int V_207 )
{
struct V_4 * V_5 = F_103 ( V_201 ) ;
V_5 -> V_204 = V_207 ;
if ( F_105 ( V_5 ) )
F_109 ( V_5 ) ;
if ( F_107 ( V_5 ) )
F_110 ( V_5 ) ;
return 0 ;
}
static int F_112 ( struct V_200 * V_201 , unsigned V_208 )
{
struct V_4 * V_5 ;
V_5 = F_103 ( V_201 ) ;
if ( ! F_106 ( V_5 -> V_205 ) )
return F_113 ( V_5 -> V_205 , V_208 ) ;
return - V_109 ;
}
static void F_110 ( struct V_4 * V_5 )
{
if ( ! V_5 -> V_175 )
return;
F_30 ( V_5 , V_31 , 0 ) ;
F_30 ( V_5 , V_32 , 0 ) ;
F_33 ( V_5 , V_24 ) ;
F_44 ( V_5 ) ;
V_5 -> V_75 . V_171 = V_172 ;
F_114 ( V_5 -> V_209 ) ;
V_5 -> V_175 = 0 ;
}
static void F_115 ( struct V_4 * V_87 )
{
int V_45 ;
struct V_41 * V_42 ;
F_54 ( & V_87 -> V_75 . V_210 ) ;
F_54 ( & V_87 -> V_75 . V_211 -> V_210 ) ;
V_87 -> V_88 [ 0 ] . V_41 = & V_87 -> V_41 [ 0 ] ;
F_44 ( V_87 ) ;
for ( V_45 = 0 ; V_45 < V_47 ; V_45 ++ ) {
V_42 = & V_87 -> V_41 [ V_45 ] ;
V_42 -> V_175 = F_35 ( V_42 ) ;
F_54 ( & V_42 -> V_49 ) ;
F_116 ( & V_42 -> V_146 ) ;
}
for ( V_45 = 1 ; V_45 < V_101 ; V_45 ++ ) {
F_62 ( & V_87 -> V_88 [ V_45 ] . V_136 . V_210 ,
& V_87 -> V_75 . V_210 ) ;
F_117 ( & V_87 -> V_88 [ V_45 ] . V_136 ,
V_87 -> V_88 [ V_45 ] . V_136 . V_212 ) ;
}
}
static void F_109 ( struct V_4 * V_5 )
{
if ( V_5 -> V_175 )
return;
F_118 ( V_5 -> V_209 ) ;
F_30 ( V_5 , V_31 , 0 ) ;
F_30 ( V_5 , V_32 , 0 ) ;
F_33 ( V_5 , V_24 ) ;
F_44 ( V_5 ) ;
V_5 -> V_75 . V_171 = V_213 ;
memset ( & V_5 -> V_36 , 0 , sizeof( V_5 -> V_36 ) ) ;
F_50 ( V_5 ) ;
F_32 ( V_5 , V_24 ) ;
F_34 ( & V_5 -> V_41 [ 0 ] , V_108 ) ;
F_119 ( 2 ) ;
if ( F_3 ( V_5 , V_14 ) & V_21 )
F_20 ( V_5 -> V_87 , L_67 ) ;
F_120 ( 100 ) ;
F_30 ( V_5 , V_32 ,
V_214 | V_215
| V_216 | V_217 ) ;
F_28 ( & V_5 -> V_41 [ 0 ] ) ;
V_5 -> V_175 = 1 ;
}
static int F_121 ( struct V_200 * V_218 ,
struct V_219 * V_8 )
{
struct V_4 * V_5 = F_122 ( V_218 ) ;
int V_220 ;
V_5 -> V_8 = V_8 ;
if ( ! F_106 ( V_5 -> V_205 ) ) {
V_220 = F_123 ( V_5 -> V_205 -> V_221 ,
& V_5 -> V_75 ) ;
if ( V_220 ) {
F_20 ( V_5 -> V_87 , L_68 ) ;
goto V_222;
}
}
if ( F_105 ( V_5 ) )
F_109 ( V_5 ) ;
return 0 ;
V_222:
V_5 -> V_8 = NULL ;
return V_220 ;
}
static void F_124 ( struct V_4 * V_5 , struct V_219 * V_8 )
{
int V_45 ;
if ( V_5 -> V_75 . V_171 == V_172 )
V_8 = NULL ;
V_5 -> V_75 . V_171 = V_172 ;
for ( V_45 = 0 ; V_45 < V_101 ; V_45 ++ )
F_99 ( & V_5 -> V_88 [ V_45 ] . V_136 ) ;
}
static int F_125 ( struct V_200 * V_218 )
{
struct V_4 * V_5 = F_122 ( V_218 ) ;
F_124 ( V_5 , NULL ) ;
F_110 ( V_5 ) ;
V_5 -> V_8 = NULL ;
if ( ! F_106 ( V_5 -> V_205 ) )
return F_123 ( V_5 -> V_205 -> V_221 , NULL ) ;
return 0 ;
}
static void F_126 ( struct V_4 * V_5 ,
struct V_43 * V_44 )
{
struct V_41 * V_42 = & V_5 -> V_41 [ 0 ] ;
union {
struct V_223 V_224 ;
T_1 V_225 [ 2 ] ;
} V_226 ;
int V_45 ;
int V_227 = 0 ;
unsigned long V_143 ;
F_76 ( V_42 , - V_228 ) ;
F_71 ( & V_42 -> V_146 , V_143 ) ;
if ( F_40 ( V_42 ) && ( F_37 ( V_42 ) == 0 ) )
F_34 ( V_42 , V_60 ) ;
for ( V_45 = 0 ; V_45 < 2 ; V_45 ++ ) {
if ( F_60 ( F_38 ( V_42 ) ) )
goto V_229;
V_226 . V_225 [ V_45 ] = F_10 ( V_42 , V_153 ) ;
}
V_227 = ! F_38 ( V_42 ) ;
while ( ! F_38 ( V_42 ) ) {
V_45 = F_10 ( V_42 , V_153 ) ;
F_90 ( V_42 , L_69 , V_45 ) ;
}
F_43 ( V_42 , L_70 ,
V_226 . V_224 . V_230 , V_226 . V_224 . V_231 ,
F_127 ( V_226 . V_224 . V_232 ) , F_127 ( V_226 . V_224 . V_233 ) ,
F_127 ( V_226 . V_224 . V_234 ) ) ;
if ( F_60 ( V_227 ) )
goto V_229;
if ( V_226 . V_224 . V_230 & V_147 )
F_41 ( V_5 , V_179 ) ;
else
F_41 ( V_5 , V_180 ) ;
F_34 ( V_42 , V_54 | V_60 ) ;
F_67 ( & V_42 -> V_146 , V_143 ) ;
V_45 = V_5 -> V_8 -> V_235 ( & V_5 -> V_75 , & V_226 . V_224 ) ;
F_71 ( & V_42 -> V_146 , V_143 ) ;
if ( V_45 < 0 )
goto V_229;
V_181:
F_67 ( & V_42 -> V_146 , V_143 ) ;
return;
V_229:
F_43 ( V_42 , L_71 ,
F_10 ( V_42 , V_53 ) , V_45 ) ;
F_34 ( V_42 , V_56 | V_236 ) ;
F_41 ( V_5 , V_188 ) ;
goto V_181;
}
static void F_128 ( struct V_4 * V_5 , int V_237 , int V_238 )
{
T_1 V_239 ;
struct V_41 * V_42 = & V_5 -> V_41 [ 0 ] ;
struct V_43 * V_44 = NULL ;
int V_158 = 0 ;
if ( ! F_6 ( & V_42 -> V_49 ) )
V_44 = F_77 ( V_42 -> V_49 . V_150 , struct V_43 , V_49 ) ;
V_239 = F_10 ( V_42 , V_53 ) ;
F_43 ( V_42 , L_72 ,
F_42 ( V_5 ) , V_44 , V_239 , F_10 ( V_42 , V_66 ) ,
( V_237 << 1 | V_238 ) ) ;
if ( V_239 & V_57 ) {
F_43 ( V_42 , L_73 ) ;
F_76 ( V_42 , - V_240 ) ;
F_34 ( V_42 , V_57 ) ;
F_44 ( V_5 ) ;
}
if ( V_239 & V_54 ) {
F_76 ( V_42 , 0 ) ;
F_41 ( V_5 , V_241 ) ;
}
switch ( V_5 -> V_115 ) {
case V_116 :
break;
case V_241 :
V_239 &= V_242 ;
if ( F_66 ( V_239 == V_242 ) )
F_126 ( V_5 , V_44 ) ;
break;
case V_179 :
if ( F_40 ( V_42 ) )
F_34 ( V_42 , V_60 ) ;
if ( V_44 && ! F_39 ( V_42 ) )
V_158 = F_87 ( V_42 , V_44 ) ;
if ( V_158 )
F_75 ( V_42 , V_44 , NULL ) ;
break;
case V_180 :
if ( F_40 ( V_42 ) && V_44 )
V_158 = F_86 ( V_42 , V_44 ) ;
if ( V_158 )
F_73 ( V_42 , V_44 , NULL ) ;
break;
case V_188 :
F_34 ( V_42 , V_56 ) ;
break;
case V_149 :
if ( V_238 )
F_44 ( V_5 ) ;
break;
case V_148 :
case V_177 :
F_97 ( V_42 , L_74 ,
F_42 ( V_42 -> V_87 ) ) ;
F_44 ( V_5 ) ;
break;
}
}
static void F_91 ( struct V_41 * V_42 )
{
struct V_43 * V_44 ;
int V_158 ;
T_1 V_161 ;
int V_117 = V_42 -> V_94 ;
int V_243 = 0 ;
unsigned long V_143 ;
F_71 ( & V_42 -> V_146 , V_143 ) ;
if ( V_42 -> V_174 )
goto V_168;
V_42 -> V_174 = 1 ;
do {
V_158 = 0 ;
V_161 = F_10 ( V_42 , V_53 ) ;
if ( F_66 ( ! F_6 ( & V_42 -> V_49 ) ) )
V_44 = F_77 ( V_42 -> V_49 . V_150 ,
struct V_43 , V_49 ) ;
else
V_44 = NULL ;
F_43 ( V_42 , L_75 ,
V_44 , V_161 , V_243 ++ ) ;
if ( F_60 ( V_161 & ( V_189 | V_162 ) ) )
F_36 ( V_42 , V_53 ,
V_161 & ( V_189 | V_162 ) ) ;
if ( ! V_44 )
break;
if ( F_60 ( V_117 ) ) {
if ( F_66 ( ! F_39 ( V_42 ) ) )
V_158 = F_85 ( V_42 , V_44 ) ;
} else {
if ( F_66 ( F_40 ( V_42 ) ) )
V_158 = F_84 ( V_42 , V_44 ) ;
}
if ( V_158 ) {
if ( V_117 )
F_74 ( V_42 , V_44 , & V_143 ) ;
else
F_72 ( V_42 , V_44 , & V_143 ) ;
}
} while ( V_158 );
V_42 -> V_174 = 0 ;
V_168:
F_67 ( & V_42 -> V_146 , V_143 ) ;
}
static void F_129 ( struct V_4 * V_5 , int V_89 )
{
struct V_223 V_44 ;
F_51 ( V_5 -> V_87 , L_76 , V_89 ) ;
V_5 -> V_89 = V_89 ;
V_5 -> V_98 = 0 ;
V_5 -> V_100 = 0 ;
V_44 . V_230 = 0 ;
V_44 . V_231 = V_244 ;
V_44 . V_232 = V_89 ;
V_44 . V_233 = 0 ;
V_44 . V_234 = 0 ;
F_41 ( V_5 , V_177 ) ;
V_5 -> V_8 -> V_235 ( & V_5 -> V_75 , & V_44 ) ;
F_34 ( & V_5 -> V_41 [ 0 ] , V_245 ) ;
}
static void F_130 ( struct V_4 * V_5 , int V_97 , int V_99 )
{
struct V_223 V_44 ;
F_51 ( V_5 -> V_87 , L_77 , V_97 , V_99 ) ;
V_5 -> V_98 = V_97 ;
V_5 -> V_100 = V_99 ;
V_44 . V_230 = V_246 ;
V_44 . V_231 = V_247 ;
V_44 . V_232 = V_99 ;
V_44 . V_233 = V_97 ;
V_44 . V_234 = 0 ;
F_41 ( V_5 , V_177 ) ;
V_5 -> V_8 -> V_235 ( & V_5 -> V_75 , & V_44 ) ;
F_34 ( & V_5 -> V_41 [ 0 ] , V_245 ) ;
}
static void F_131 ( int V_248 , struct V_4 * V_5 )
{
int V_45 ;
struct V_41 * V_42 ;
T_1 V_249 = F_3 ( V_5 , V_33 ) & V_250 ;
T_1 V_251 = F_3 ( V_5 , V_34 ) & V_252 ;
if ( V_249 & V_253 ) {
V_5 -> V_41 [ 0 ] . V_36 . V_65 ++ ;
F_30 ( V_5 , V_33 , F_132 ( 0 , V_253 ) ) ;
F_128 ( V_5 , ! ! ( V_249 & V_254 ) ,
! ! ( V_249 & V_255 ) ) ;
}
V_249 >>= 2 ;
for ( V_45 = 1 ; V_249 != 0 && V_45 < 16 ; V_249 >>= 2 , V_45 ++ ) {
if ( ! ( V_249 & V_253 ) )
continue;
F_30 ( V_5 , V_33 , F_132 ( V_45 , V_253 ) ) ;
F_57 ( V_45 >= F_133 ( V_5 -> V_41 ) ) ;
if ( V_45 < F_133 ( V_5 -> V_41 ) ) {
V_42 = & V_5 -> V_41 [ V_45 ] ;
V_42 -> V_36 . V_65 ++ ;
F_91 ( V_42 ) ;
}
}
for ( V_45 = 16 ; V_251 != 0 && V_45 < 24 ; V_251 >>= 2 , V_45 ++ ) {
F_30 ( V_5 , V_34 , F_132 ( V_45 - 16 , V_253 ) ) ;
if ( ! ( V_251 & V_253 ) )
continue;
F_57 ( V_45 >= F_133 ( V_5 -> V_41 ) ) ;
if ( V_45 < F_133 ( V_5 -> V_41 ) ) {
V_42 = & V_5 -> V_41 [ V_45 ] ;
V_42 -> V_36 . V_65 ++ ;
F_91 ( V_42 ) ;
}
}
}
static void F_134 ( struct V_4 * V_5 )
{
F_30 ( V_5 , V_34 , V_256 ) ;
V_5 -> V_36 . V_38 ++ ;
if ( V_5 -> V_75 . V_171 != V_172
&& V_5 -> V_8 && V_5 -> V_8 -> V_257 )
V_5 -> V_8 -> V_257 ( & V_5 -> V_75 ) ;
F_44 ( V_5 ) ;
}
static void F_135 ( struct V_4 * V_5 )
{
F_30 ( V_5 , V_34 , V_258 ) ;
V_5 -> V_36 . V_39 ++ ;
if ( V_5 -> V_75 . V_171 != V_172
&& V_5 -> V_8 && V_5 -> V_8 -> V_259 )
V_5 -> V_8 -> V_259 ( & V_5 -> V_75 ) ;
}
static void F_136 ( struct V_4 * V_5 )
{
unsigned V_89 , V_90 , V_95 , V_260 ;
T_1 V_106 = F_3 ( V_5 , V_14 ) ;
F_30 ( V_5 , V_34 , V_261 ) ;
V_5 -> V_36 . V_40 ++ ;
V_89 = ( V_106 & V_25 ) >> V_26 ;
V_260 = ( V_89 != V_5 -> V_89 ) ;
F_129 ( V_5 , V_89 ) ;
V_90 = ( V_106 & V_27 ) >> V_28 ;
V_95 = ( V_106 & V_29 ) >> V_30 ;
F_130 ( V_5 , V_90 , V_95 ) ;
if ( V_260 )
F_27 ( V_5 ) ;
F_32 ( V_5 , V_20 ) ;
}
static void F_137 ( struct V_4 * V_5 )
{
T_1 V_106 = F_3 ( V_5 , V_14 ) ;
struct V_41 * V_42 = & V_5 -> V_41 [ 0 ] ;
F_138 ( V_5 -> V_87 , L_78 ) ;
F_30 ( V_5 , V_34 , V_262 ) ;
V_5 -> V_36 . V_37 ++ ;
if ( ( V_106 & V_23 ) == 0 ) {
F_51 ( V_5 -> V_87 , L_79 ) ;
F_124 ( V_5 , V_5 -> V_8 ) ;
}
V_5 -> V_75 . V_171 = V_213 ;
memset ( & V_5 -> V_36 , 0 , sizeof V_5 -> V_36 ) ;
F_76 ( V_42 , - V_228 ) ;
F_34 ( V_42 , V_236 | V_60 ) ;
F_44 ( V_5 ) ;
}
static T_4 F_139 ( int V_248 , void * V_263 )
{
struct V_4 * V_5 = V_263 ;
T_1 V_249 = F_3 ( V_5 , V_33 ) ;
T_1 V_251 = F_3 ( V_5 , V_34 ) ;
T_1 V_106 = F_3 ( V_5 , V_14 ) ;
T_1 V_264 ;
F_140 ( V_5 -> V_87 , L_80
L_81 , V_249 , V_251 , V_106 ) ;
V_264 = V_251 & 0xf8000000 ;
if ( F_60 ( V_264 & V_256 ) )
F_134 ( V_5 ) ;
if ( F_60 ( V_264 & V_258 ) )
F_135 ( V_5 ) ;
if ( F_60 ( V_264 & V_261 ) )
F_136 ( V_5 ) ;
if ( F_60 ( V_264 & V_262 ) )
F_137 ( V_5 ) ;
if ( ( V_249 & V_250 ) | ( V_251 & V_252 ) )
F_131 ( V_248 , V_5 ) ;
return V_265 ;
}
static int F_141 ( struct V_266 * V_267 )
{
struct V_268 * V_269 ;
struct V_4 * V_5 = & V_270 ;
int V_220 = 0 , V_271 ;
struct V_272 * V_273 = F_142 ( & V_267 -> V_87 ) ;
unsigned long V_274 ;
if ( V_273 ) {
V_274 = V_273 -> V_275 ? V_276 : 0 ;
V_271 = V_273 -> V_277 ;
if ( F_143 ( V_271 ) ) {
V_220 = F_144 ( & V_267 -> V_87 , V_271 ,
V_274 ,
L_82 ) ;
if ( V_220 )
return V_220 ;
V_5 -> V_195 = F_145 ( V_273 -> V_277 ) ;
}
V_5 -> V_196 = V_273 -> V_196 ;
} else {
V_5 -> V_195 = F_146 ( & V_267 -> V_87 , NULL ) ;
}
V_269 = F_147 ( V_267 , V_278 , 0 ) ;
V_5 -> V_269 = F_148 ( & V_267 -> V_87 , V_269 ) ;
if ( F_17 ( V_5 -> V_269 ) )
return F_149 ( V_5 -> V_269 ) ;
V_5 -> V_248 = F_150 ( V_267 , 0 ) ;
if ( V_5 -> V_248 < 0 )
return V_5 -> V_248 ;
V_5 -> V_87 = & V_267 -> V_87 ;
V_5 -> V_205 = F_151 ( V_279 ) ;
if ( F_17 ( V_5 -> V_195 ) ) {
F_20 ( & V_267 -> V_87 , L_83 ,
F_149 ( V_5 -> V_195 ) ) ;
return F_149 ( V_5 -> V_195 ) ;
}
if ( V_5 -> V_195 )
F_152 ( V_5 -> V_195 , 0 ) ;
V_5 -> V_209 = F_153 ( & V_267 -> V_87 , NULL ) ;
if ( F_17 ( V_5 -> V_209 ) )
return F_149 ( V_5 -> V_209 ) ;
V_220 = F_154 ( V_5 -> V_209 ) ;
if ( V_220 )
return V_220 ;
V_5 -> V_204 = 0 ;
V_280 = V_5 ;
F_155 ( V_267 , V_5 ) ;
F_115 ( V_5 ) ;
V_220 = F_156 ( & V_267 -> V_87 , V_5 -> V_248 , F_139 ,
V_281 , V_11 , V_5 ) ;
if ( V_220 != 0 ) {
F_20 ( V_5 -> V_87 , L_84 ,
V_11 , V_5 -> V_248 , V_220 ) ;
goto V_282;
}
V_220 = F_157 ( & V_267 -> V_87 , & V_5 -> V_75 ) ;
if ( V_220 )
goto V_282;
F_15 ( V_5 ) ;
if ( F_105 ( V_5 ) )
F_109 ( V_5 ) ;
return 0 ;
V_282:
F_158 ( V_5 -> V_209 ) ;
return V_220 ;
}
static int F_159 ( struct V_266 * V_263 )
{
struct V_4 * V_5 = F_160 ( V_263 ) ;
F_161 ( & V_5 -> V_75 ) ;
F_21 ( V_5 ) ;
F_162 ( V_5 -> V_205 ) ;
V_5 -> V_205 = NULL ;
V_280 = NULL ;
F_158 ( V_5 -> V_209 ) ;
return 0 ;
}
static void F_163 ( struct V_266 * V_263 )
{
struct V_4 * V_5 = F_160 ( V_263 ) ;
if ( F_3 ( V_5 , V_14 ) & V_24 )
F_110 ( V_5 ) ;
}
static int F_164 ( struct V_266 * V_263 , T_5 V_72 )
{
struct V_4 * V_5 = F_160 ( V_263 ) ;
struct V_41 * V_42 ;
V_42 = & V_5 -> V_41 [ 0 ] ;
V_5 -> V_239 = F_10 ( V_42 , V_53 ) ;
F_110 ( V_5 ) ;
V_5 -> V_283 = V_5 -> V_199 ;
F_100 ( V_5 , 0 ) ;
return 0 ;
}
static int F_165 ( struct V_266 * V_263 )
{
struct V_4 * V_5 = F_160 ( V_263 ) ;
struct V_41 * V_42 ;
V_42 = & V_5 -> V_41 [ 0 ] ;
F_36 ( V_42 , V_53 , V_5 -> V_239 & ( V_56 | V_58 ) ) ;
F_100 ( V_5 , V_5 -> V_283 ) ;
if ( F_105 ( V_5 ) )
F_109 ( V_5 ) ;
F_166 () ;
return 0 ;
}
