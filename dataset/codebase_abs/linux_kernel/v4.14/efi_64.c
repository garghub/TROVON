static void T_1 F_1 ( int V_1 )
{
T_2 * V_2 ;
if ( ! ( V_3 & V_4 ) )
return;
F_2 (md) {
if ( V_2 -> type == V_5 ||
V_2 -> type == V_6 )
F_3 ( V_2 , V_1 ) ;
}
}
T_3 * T_1 F_4 ( void )
{
unsigned long V_7 , V_8 , V_9 , V_10 ;
T_3 * V_11 , * V_12 , * V_13 ;
T_4 * V_14 , * V_15 , * V_16 ;
T_5 * V_17 ;
int V_18 ;
int V_19 , V_20 , V_21 ;
if ( ! F_5 ( V_22 ) ) {
V_11 = ( T_3 * ) F_6 () ;
F_7 ( ( unsigned long ) V_23 . V_24 ) ;
goto V_25;
}
F_1 ( 1 ) ;
V_19 = F_8 ( ( V_26 << V_27 ) , V_28 ) ;
V_11 = F_9 ( V_19 , sizeof( * V_11 ) , V_29 ) ;
for ( V_18 = 0 ; V_18 < V_19 ; V_18 ++ ) {
V_8 = ( unsigned long ) ( V_18 * V_28 ) ;
V_7 = ( unsigned long ) F_10 ( V_18 * V_28 ) ;
V_13 = F_11 ( V_8 ) ;
V_11 [ V_18 ] = * V_13 ;
V_14 = F_12 ( & V_30 , V_13 , V_8 ) ;
if ( ! V_14 ) {
F_13 ( L_1 ) ;
goto V_25;
}
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) {
V_9 = V_8 + V_20 * V_32 ;
V_16 = V_14 + F_14 ( V_9 ) ;
V_17 = F_15 ( & V_30 , V_16 , V_9 ) ;
if ( ! V_17 ) {
F_13 ( L_2 ) ;
goto V_25;
}
for ( V_21 = 0 ; V_21 < V_33 ; V_21 ++ ) {
V_10 = V_9 + V_21 * V_34 ;
if ( V_10 > ( V_26 << V_27 ) )
break;
V_7 = ( unsigned long ) F_10 ( V_10 ) ;
V_12 = F_11 ( V_7 ) ;
V_15 = F_16 ( V_12 , V_7 ) ;
V_17 [ V_21 ] = * F_17 ( V_15 , V_7 ) ;
}
}
}
V_25:
F_18 () ;
return V_11 ;
}
void T_1 F_19 ( T_3 * V_11 )
{
int V_35 , V_20 ;
int V_36 ;
T_3 * V_18 ;
T_4 * V_14 ;
T_5 * V_17 ;
if ( ! F_5 ( V_22 ) ) {
F_7 ( ( unsigned long ) V_11 ) ;
F_18 () ;
return;
}
V_36 = F_8 ( ( V_26 << V_27 ) , V_28 ) ;
for ( V_35 = 0 ; V_35 < V_36 ; V_35 ++ ) {
V_18 = F_11 ( V_35 * V_28 ) ;
F_20 ( F_11 ( V_35 * V_28 ) , V_11 [ V_35 ] ) ;
if ( ! ( F_21 ( * V_18 ) & V_37 ) )
continue;
for ( V_20 = 0 ; V_20 < V_31 ; V_20 ++ ) {
V_14 = F_16 ( V_18 ,
V_35 * V_28 + V_20 * V_32 ) ;
if ( ! ( F_22 ( * V_14 ) & V_37 ) )
continue;
V_17 = ( T_5 * ) F_23 ( * V_14 ) ;
F_24 ( & V_30 , V_17 ) ;
}
V_14 = ( T_4 * ) F_25 ( * V_18 ) ;
F_26 ( & V_30 , V_14 ) ;
}
F_27 ( V_11 ) ;
F_18 () ;
F_1 ( 0 ) ;
}
int T_1 F_28 ( void )
{
T_3 * V_18 ;
T_4 * V_14 ;
T_5 * V_17 ;
T_6 V_38 ;
if ( F_5 ( V_22 ) )
return 0 ;
V_38 = V_29 | V_39 | V_40 ;
V_41 = ( T_3 * ) F_29 ( V_38 ) ;
if ( ! V_41 )
return - V_42 ;
V_18 = V_41 + F_30 ( V_43 ) ;
V_14 = F_12 ( & V_30 , V_18 , V_43 ) ;
if ( ! V_14 ) {
F_31 ( ( unsigned long ) V_41 ) ;
return - V_42 ;
}
V_17 = F_15 ( & V_30 , V_14 , V_43 ) ;
if ( ! V_17 ) {
if ( V_44 > 4 )
F_31 ( ( unsigned long ) F_25 ( * V_18 ) ) ;
F_31 ( ( unsigned long ) V_41 ) ;
return - V_42 ;
}
return 0 ;
}
void F_32 ( void )
{
unsigned V_45 ;
T_3 * V_12 , * V_13 ;
T_4 * V_15 , * V_16 ;
T_5 * V_46 , * V_47 ;
if ( F_5 ( V_22 ) )
return;
F_33 ( F_30 ( V_43 ) != F_30 ( V_48 ) ) ;
F_33 ( ( V_49 & V_50 ) !=
( V_43 & V_50 ) ) ;
V_13 = V_41 + F_30 ( V_51 ) ;
V_12 = F_11 ( V_51 ) ;
V_45 = F_30 ( V_43 ) - F_30 ( V_51 ) ;
memcpy ( V_13 , V_12 , sizeof( T_3 ) * V_45 ) ;
F_33 ( F_14 ( V_43 ) != F_14 ( V_48 ) ) ;
F_33 ( ( V_49 & V_52 ) != ( V_43 & V_52 ) ) ;
V_13 = V_41 + F_30 ( V_43 ) ;
V_12 = F_11 ( V_43 ) ;
V_16 = F_16 ( V_13 , 0 ) ;
V_15 = F_16 ( V_12 , 0 ) ;
V_45 = F_14 ( V_43 ) ;
memcpy ( V_16 , V_15 , sizeof( T_4 ) * V_45 ) ;
F_33 ( ( V_49 & ~ V_53 ) != 0 ) ;
F_33 ( ( V_43 & ~ V_53 ) != 0 ) ;
V_16 = F_16 ( V_13 , V_43 ) ;
V_15 = F_16 ( V_12 , V_43 ) ;
V_47 = F_17 ( V_16 , 0 ) ;
V_46 = F_17 ( V_15 , 0 ) ;
V_45 = F_34 ( V_43 ) ;
memcpy ( V_47 , V_46 , sizeof( T_5 ) * V_45 ) ;
V_47 = F_17 ( V_16 , V_49 ) ;
V_46 = F_17 ( V_15 , V_49 ) ;
V_45 = V_33 - F_34 ( V_49 ) ;
memcpy ( V_47 , V_46 , sizeof( T_5 ) * V_45 ) ;
}
static inline T_7
F_35 ( void * V_54 , unsigned long V_55 )
{
bool V_56 ;
if ( ! V_54 )
return 0 ;
if ( F_36 ( V_54 ) )
return F_37 ( V_54 ) ;
V_56 = V_55 > V_57 || ! F_38 ( V_55 ) ;
F_39 ( ! F_40 ( ( unsigned long ) V_54 , V_55 ) || V_56 ) ;
return F_41 ( V_54 ) ;
}
int T_1 F_42 ( unsigned long V_58 , unsigned V_59 )
{
unsigned long V_60 , V_61 , V_62 ;
struct V_63 * V_63 ;
unsigned V_64 ;
T_3 * V_18 ;
if ( F_5 ( V_22 ) )
return 0 ;
V_23 . V_24 = ( T_3 * ) F_43 ( V_41 ) ;
V_18 = V_41 ;
V_60 = V_58 >> V_27 ;
V_62 = V_4 | V_65 | V_66 ;
if ( F_44 ( V_18 , V_60 , V_58 , V_59 , V_62 ) ) {
F_13 ( L_3 , V_58 ) ;
return 1 ;
}
V_23 . V_67 = true ;
if ( F_44 ( V_18 , 0x0 , 0x0 , 1 , V_65 ) ) {
F_13 ( L_4 ) ;
return 1 ;
}
if ( ! F_45 ( V_68 ) || F_46 () )
return 0 ;
V_63 = F_47 ( V_29 | V_69 ) ;
if ( ! V_63 )
F_48 ( L_5 ) ;
V_23 . V_70 = F_37 ( F_49 ( V_63 ) ) ;
V_23 . V_70 += V_57 ;
V_64 = ( V_71 - V_72 ) >> V_27 ;
V_61 = F_50 ( V_72 ) ;
V_60 = V_61 >> V_27 ;
V_62 = V_65 | V_66 ;
if ( F_44 ( V_18 , V_60 , V_61 , V_64 , V_62 ) ) {
F_13 ( L_6 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_51 ( T_2 * V_2 , T_8 V_54 )
{
unsigned long V_73 = V_65 ;
unsigned long V_60 ;
T_3 * V_18 = V_41 ;
if ( ! ( V_2 -> V_74 & V_75 ) )
V_73 |= V_76 ;
V_60 = V_2 -> V_77 >> V_27 ;
if ( F_44 ( V_18 , V_60 , V_54 , V_2 -> V_59 , V_73 ) )
F_52 ( L_7 ,
V_2 -> V_77 , V_54 ) ;
}
void T_1 F_53 ( T_2 * V_2 )
{
unsigned long V_55 = V_2 -> V_59 << V_27 ;
T_8 V_78 = V_2 -> V_77 ;
if ( F_5 ( V_22 ) )
return F_54 ( V_2 ) ;
F_51 ( V_2 , V_2 -> V_77 ) ;
if ( ! F_46 () && F_45 ( V_68 ) ) {
V_2 -> V_79 = V_2 -> V_77 ;
return;
}
V_80 -= V_55 ;
if ( ! ( V_78 & ( V_81 - 1 ) ) ) {
V_80 &= V_82 ;
} else {
T_8 V_83 = V_78 & ( V_81 - 1 ) ;
T_8 V_84 = V_80 ;
V_80 = ( V_80 & V_82 ) + V_83 ;
if ( V_80 > V_84 )
V_80 -= V_81 ;
}
if ( V_80 < V_43 ) {
F_52 ( V_85 L_8 ) ;
return;
}
F_51 ( V_2 , V_80 ) ;
V_2 -> V_79 = V_80 ;
}
void T_1 F_55 ( T_2 * V_2 )
{
F_51 ( V_2 , V_2 -> V_77 ) ;
F_51 ( V_2 , V_2 -> V_79 ) ;
}
void T_9 * T_1 F_56 ( unsigned long V_77 , unsigned long V_55 ,
T_10 type , T_8 V_74 )
{
unsigned long V_86 ;
if ( type == V_87 )
return F_57 ( V_77 , V_55 ) ;
V_86 = F_58 ( V_77 , V_77 + V_55 ) ;
if ( ( V_86 << V_27 ) < V_77 + V_55 ) {
unsigned long V_88 = V_86 << V_27 ;
F_56 ( V_88 , V_55 - ( V_88 - V_77 ) , type , V_74 ) ;
}
if ( ! ( V_74 & V_75 ) )
F_59 ( ( T_8 ) ( unsigned long ) F_10 ( V_77 ) , V_55 ) ;
return ( void T_9 * ) F_10 ( V_77 ) ;
}
void T_1 F_60 ( T_8 V_77 , T_10 V_89 )
{
V_90 = V_77 + sizeof( struct V_91 ) ;
}
static int T_1 F_61 ( T_2 * V_2 , unsigned long V_62 )
{
unsigned long V_60 ;
T_3 * V_18 = V_41 ;
int V_92 , V_93 ;
V_60 = V_2 -> V_77 >> V_27 ;
V_92 = F_44 ( V_18 , V_60 , V_2 -> V_77 , V_2 -> V_59 , V_62 ) ;
if ( V_92 ) {
F_13 ( L_9 ,
V_2 -> V_77 , V_2 -> V_79 ) ;
}
V_93 = F_44 ( V_18 , V_60 , V_2 -> V_79 , V_2 -> V_59 , V_62 ) ;
if ( V_93 ) {
F_13 ( L_10 ,
V_2 -> V_77 , V_2 -> V_79 ) ;
}
return V_92 || V_93 ;
}
static int T_1 F_62 ( struct V_94 * V_95 , T_2 * V_2 )
{
unsigned long V_62 = 0 ;
if ( V_2 -> V_74 & V_96 )
V_62 |= V_4 ;
if ( ! ( V_2 -> V_74 & V_97 ) )
V_62 |= V_65 ;
return F_61 ( V_2 , V_62 ) ;
}
void T_1 F_63 ( void )
{
T_2 * V_2 ;
if ( F_5 ( V_22 ) ) {
if ( V_3 & V_4 )
F_64 () ;
return;
}
if ( F_5 ( V_98 ) ) {
F_65 ( NULL , F_62 ) ;
return;
}
if ( ! F_5 ( V_99 ) )
return;
F_2 (md) {
unsigned long V_62 = 0 ;
if ( ! ( V_2 -> V_74 & V_100 ) )
continue;
if ( ! ( V_2 -> V_74 & V_75 ) )
V_62 |= V_76 ;
if ( ( V_2 -> V_74 & V_96 ) ||
( V_2 -> type == V_101 ) )
V_62 |= V_4 ;
if ( ! ( V_2 -> V_74 & V_97 ) &&
( V_2 -> type != V_5 ) )
V_62 |= V_65 ;
F_61 ( V_2 , V_62 ) ;
}
}
void T_1 F_66 ( void )
{
#ifdef F_67
if ( F_5 ( V_22 ) )
F_68 ( NULL , V_102 ) ;
else
F_68 ( NULL , V_41 ) ;
#endif
}
T_11 F_69 (
void * V_103 ,
unsigned long V_104 ,
unsigned long V_105 ,
T_10 V_106 ,
T_2 * V_107 )
{
T_11 V_108 ;
unsigned long V_73 ;
T_10 V_109 ;
F_32 () ;
F_70 ( V_73 ) ;
V_23 . V_110 = F_6 () ;
F_7 ( ( unsigned long ) V_23 . V_24 ) ;
F_18 () ;
V_109 = ( T_10 ) ( unsigned long ) V_103 ;
V_108 = F_71 ( V_109 , V_104 , V_105 ,
V_106 , V_107 ) ;
F_7 ( V_23 . V_110 ) ;
F_18 () ;
F_72 ( V_73 ) ;
return V_108 ;
}
static T_11 F_73 ( T_12 * V_111 , T_13 * V_112 )
{
T_11 V_108 ;
T_10 V_113 , V_114 ;
F_74 ( & V_115 ) ;
V_113 = F_75 ( V_111 ) ;
V_114 = F_75 ( V_112 ) ;
V_108 = F_76 ( V_116 , V_113 , V_114 ) ;
F_77 ( & V_115 ) ;
return V_108 ;
}
static T_11 F_78 ( T_12 * V_111 )
{
T_11 V_108 ;
T_10 V_113 ;
F_74 ( & V_115 ) ;
V_113 = F_75 ( V_111 ) ;
V_108 = F_76 ( V_117 , V_113 ) ;
F_77 ( & V_115 ) ;
return V_108 ;
}
static T_11
F_79 ( T_14 * V_118 , T_14 * V_119 ,
T_12 * V_111 )
{
T_11 V_108 ;
T_10 V_120 , V_121 , V_113 ;
F_74 ( & V_115 ) ;
V_120 = F_75 ( V_118 ) ;
V_121 = F_75 ( V_119 ) ;
V_113 = F_75 ( V_111 ) ;
V_108 = F_76 ( V_122 , V_120 ,
V_121 , V_113 ) ;
F_77 ( & V_115 ) ;
return V_108 ;
}
static T_11
F_80 ( T_14 V_118 , T_12 * V_111 )
{
T_11 V_108 ;
T_10 V_113 ;
F_74 ( & V_115 ) ;
V_113 = F_75 ( V_111 ) ;
V_108 = F_76 ( V_123 , V_118 , V_113 ) ;
F_77 ( & V_115 ) ;
return V_108 ;
}
static unsigned long F_81 ( T_15 * V_124 )
{
return F_82 ( V_124 , V_125 ) + 1 ;
}
static T_11
F_83 ( T_15 * V_124 , T_16 * V_126 ,
T_10 * V_127 , unsigned long * V_128 , void * V_129 )
{
T_11 V_108 ;
T_10 V_130 , V_131 , V_132 ;
T_10 V_133 , V_134 ;
V_133 = F_75 ( V_128 ) ;
V_131 = F_75 ( V_126 ) ;
V_130 = F_35 ( V_124 , F_81 ( V_124 ) ) ;
V_132 = F_75 ( V_127 ) ;
V_134 = F_35 ( V_129 , * V_128 ) ;
V_108 = F_76 ( V_135 , V_130 , V_131 ,
V_132 , V_133 , V_134 ) ;
return V_108 ;
}
static T_11
F_84 ( T_15 * V_124 , T_16 * V_126 ,
T_10 V_127 , unsigned long V_128 , void * V_129 )
{
T_10 V_130 , V_131 , V_134 ;
T_11 V_108 ;
V_130 = F_35 ( V_124 , F_81 ( V_124 ) ) ;
V_131 = F_75 ( V_126 ) ;
V_134 = F_35 ( V_129 , V_128 ) ;
V_108 = F_76 ( V_136 , V_130 , V_131 ,
V_127 , V_128 , V_134 ) ;
return V_108 ;
}
static T_11
F_85 ( unsigned long * V_137 ,
T_15 * V_124 ,
T_16 * V_126 )
{
T_11 V_108 ;
T_10 V_138 , V_130 , V_131 ;
V_138 = F_75 ( V_137 ) ;
V_131 = F_75 ( V_126 ) ;
V_130 = F_35 ( V_124 , * V_137 ) ;
V_108 = F_76 ( V_139 , V_138 ,
V_130 , V_131 ) ;
return V_108 ;
}
static T_11
F_86 ( T_10 * V_140 )
{
T_11 V_108 ;
T_10 V_141 ;
V_141 = F_75 ( V_140 ) ;
V_108 = F_76 ( V_142 , V_141 ) ;
return V_108 ;
}
static void
F_87 ( int V_143 , T_11 V_108 ,
unsigned long V_128 , T_15 * V_129 )
{
T_10 V_134 ;
V_134 = F_35 ( V_129 , V_128 ) ;
F_76 ( V_144 , V_143 , V_108 , V_128 , V_134 ) ;
}
static T_11
F_88 ( T_17 * * V_145 ,
unsigned long V_140 , unsigned long V_146 )
{
return V_147 ;
}
static T_11
F_89 ( T_10 V_127 , T_8 * V_148 ,
T_8 * V_149 ,
T_8 * V_150 )
{
T_11 V_108 ;
T_10 V_151 , V_152 , V_153 ;
if ( V_154 . V_155 < V_156 )
return V_147 ;
V_151 = F_75 ( V_148 ) ;
V_152 = F_75 ( V_149 ) ;
V_153 = F_75 ( V_150 ) ;
V_108 = F_76 ( V_157 , V_127 , V_151 ,
V_152 , V_153 ) ;
return V_108 ;
}
static T_11
F_90 ( T_17 * * V_145 ,
unsigned long V_140 , T_8 * V_158 ,
int * V_143 )
{
return V_147 ;
}
void F_91 ( void )
{
V_154 . V_116 = F_73 ;
V_154 . V_117 = F_78 ;
V_154 . V_122 = F_79 ;
V_154 . V_123 = F_80 ;
V_154 . V_135 = F_83 ;
V_154 . V_139 = F_85 ;
V_154 . V_136 = F_84 ;
V_154 . V_142 = F_86 ;
V_154 . V_144 = F_87 ;
V_154 . V_157 = F_89 ;
V_154 . V_159 = F_88 ;
V_154 . V_160 = F_90 ;
}
