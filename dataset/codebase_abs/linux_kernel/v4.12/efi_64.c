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
unsigned long V_60 , V_61 ;
struct V_62 * V_62 ;
unsigned V_63 ;
T_3 * V_18 ;
if ( F_5 ( V_22 ) )
return 0 ;
V_23 . V_24 = ( T_3 * ) F_43 ( V_41 ) ;
V_18 = V_41 ;
V_60 = V_58 >> V_27 ;
if ( F_44 ( V_18 , V_60 , V_58 , V_59 , V_4 | V_64 ) ) {
F_13 ( L_3 , V_58 ) ;
return 1 ;
}
V_23 . V_65 = true ;
if ( F_44 ( V_18 , 0x0 , 0x0 , 1 , V_64 ) ) {
F_13 ( L_4 ) ;
return 1 ;
}
if ( ! F_45 ( V_66 ) || F_46 () )
return 0 ;
V_62 = F_47 ( V_29 | V_67 ) ;
if ( ! V_62 )
F_48 ( L_5 ) ;
V_23 . V_68 = F_37 ( F_49 ( V_62 ) ) ;
V_23 . V_68 += V_57 ;
V_63 = ( V_69 - V_70 ) >> V_27 ;
V_61 = F_43 ( V_70 ) ;
V_60 = V_61 >> V_27 ;
if ( F_44 ( V_18 , V_60 , V_61 , V_63 , V_64 ) ) {
F_13 ( L_6 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_50 ( T_2 * V_2 , T_8 V_54 )
{
unsigned long V_71 = V_64 ;
unsigned long V_60 ;
T_3 * V_18 = V_41 ;
if ( ! ( V_2 -> V_72 & V_73 ) )
V_71 |= V_74 ;
V_60 = V_2 -> V_75 >> V_27 ;
if ( F_44 ( V_18 , V_60 , V_54 , V_2 -> V_59 , V_71 ) )
F_51 ( L_7 ,
V_2 -> V_75 , V_54 ) ;
}
void T_1 F_52 ( T_2 * V_2 )
{
unsigned long V_55 = V_2 -> V_59 << V_27 ;
T_8 V_76 = V_2 -> V_75 ;
if ( F_5 ( V_22 ) )
return F_53 ( V_2 ) ;
F_50 ( V_2 , V_2 -> V_75 ) ;
if ( ! F_46 () && F_45 ( V_66 ) ) {
V_2 -> V_77 = V_2 -> V_75 ;
return;
}
V_78 -= V_55 ;
if ( ! ( V_76 & ( V_79 - 1 ) ) ) {
V_78 &= V_80 ;
} else {
T_8 V_81 = V_76 & ( V_79 - 1 ) ;
T_8 V_82 = V_78 ;
V_78 = ( V_78 & V_80 ) + V_81 ;
if ( V_78 > V_82 )
V_78 -= V_79 ;
}
if ( V_78 < V_43 ) {
F_51 ( V_83 L_8 ) ;
return;
}
F_50 ( V_2 , V_78 ) ;
V_2 -> V_77 = V_78 ;
}
void T_1 F_54 ( T_2 * V_2 )
{
F_50 ( V_2 , V_2 -> V_75 ) ;
F_50 ( V_2 , V_2 -> V_77 ) ;
}
void T_9 * T_1 F_55 ( unsigned long V_75 , unsigned long V_55 ,
T_10 type , T_8 V_72 )
{
unsigned long V_84 ;
if ( type == V_85 )
return F_56 ( V_75 , V_55 ) ;
V_84 = F_57 ( V_75 , V_75 + V_55 ) ;
if ( ( V_84 << V_27 ) < V_75 + V_55 ) {
unsigned long V_86 = V_84 << V_27 ;
F_55 ( V_86 , V_55 - ( V_86 - V_75 ) , type , V_72 ) ;
}
if ( ! ( V_72 & V_73 ) )
F_58 ( ( T_8 ) ( unsigned long ) F_10 ( V_75 ) , V_55 ) ;
return ( void T_9 * ) F_10 ( V_75 ) ;
}
void T_1 F_59 ( T_8 V_75 , T_10 V_87 )
{
V_88 = V_75 + sizeof( struct V_89 ) ;
}
static int T_1 F_60 ( T_2 * V_2 , unsigned long V_90 )
{
unsigned long V_60 ;
T_3 * V_18 = V_41 ;
int V_91 , V_92 ;
V_60 = V_2 -> V_75 >> V_27 ;
V_91 = F_44 ( V_18 , V_60 , V_2 -> V_75 , V_2 -> V_59 , V_90 ) ;
if ( V_91 ) {
F_13 ( L_9 ,
V_2 -> V_75 , V_2 -> V_77 ) ;
}
V_92 = F_44 ( V_18 , V_60 , V_2 -> V_77 , V_2 -> V_59 , V_90 ) ;
if ( V_92 ) {
F_13 ( L_10 ,
V_2 -> V_75 , V_2 -> V_77 ) ;
}
return V_91 || V_92 ;
}
static int T_1 F_61 ( struct V_93 * V_94 , T_2 * V_2 )
{
unsigned long V_90 = 0 ;
if ( V_2 -> V_72 & V_95 )
V_90 |= V_4 ;
if ( ! ( V_2 -> V_72 & V_96 ) )
V_90 |= V_64 ;
return F_60 ( V_2 , V_90 ) ;
}
void T_1 F_62 ( void )
{
T_2 * V_2 ;
if ( F_5 ( V_22 ) ) {
if ( V_3 & V_4 )
F_63 () ;
return;
}
if ( F_5 ( V_97 ) ) {
F_64 ( NULL , F_61 ) ;
return;
}
if ( ! F_5 ( V_98 ) )
return;
F_2 (md) {
unsigned long V_90 = 0 ;
if ( ! ( V_2 -> V_72 & V_99 ) )
continue;
if ( ! ( V_2 -> V_72 & V_73 ) )
V_90 |= V_74 ;
if ( ( V_2 -> V_72 & V_95 ) ||
( V_2 -> type == V_100 ) )
V_90 |= V_4 ;
if ( ! ( V_2 -> V_72 & V_96 ) &&
( V_2 -> type != V_5 ) )
V_90 |= V_64 ;
F_60 ( V_2 , V_90 ) ;
}
}
void T_1 F_65 ( void )
{
#ifdef F_66
F_67 ( NULL , V_41 ) ;
#endif
}
T_11 F_68 (
void * V_101 ,
unsigned long V_102 ,
unsigned long V_103 ,
T_10 V_104 ,
T_2 * V_105 )
{
T_11 V_106 ;
unsigned long V_71 ;
T_10 V_107 ;
F_32 () ;
F_69 ( V_71 ) ;
V_23 . V_108 = F_6 () ;
F_7 ( ( unsigned long ) V_23 . V_24 ) ;
F_18 () ;
V_107 = ( T_10 ) ( unsigned long ) V_101 ;
V_106 = F_70 ( V_107 , V_102 , V_103 ,
V_104 , V_105 ) ;
F_7 ( V_23 . V_108 ) ;
F_18 () ;
F_71 ( V_71 ) ;
return V_106 ;
}
static T_11 F_72 ( T_12 * V_109 , T_13 * V_110 )
{
T_11 V_106 ;
T_10 V_111 , V_112 ;
F_73 ( & V_113 ) ;
V_111 = F_74 ( V_109 ) ;
V_112 = F_74 ( V_110 ) ;
V_106 = F_75 ( V_114 , V_111 , V_112 ) ;
F_76 ( & V_113 ) ;
return V_106 ;
}
static T_11 F_77 ( T_12 * V_109 )
{
T_11 V_106 ;
T_10 V_111 ;
F_73 ( & V_113 ) ;
V_111 = F_74 ( V_109 ) ;
V_106 = F_75 ( V_115 , V_111 ) ;
F_76 ( & V_113 ) ;
return V_106 ;
}
static T_11
F_78 ( T_14 * V_116 , T_14 * V_117 ,
T_12 * V_109 )
{
T_11 V_106 ;
T_10 V_118 , V_119 , V_111 ;
F_73 ( & V_113 ) ;
V_118 = F_74 ( V_116 ) ;
V_119 = F_74 ( V_117 ) ;
V_111 = F_74 ( V_109 ) ;
V_106 = F_75 ( V_120 , V_118 ,
V_119 , V_111 ) ;
F_76 ( & V_113 ) ;
return V_106 ;
}
static T_11
F_79 ( T_14 V_116 , T_12 * V_109 )
{
T_11 V_106 ;
T_10 V_111 ;
F_73 ( & V_113 ) ;
V_111 = F_74 ( V_109 ) ;
V_106 = F_75 ( V_121 , V_116 , V_111 ) ;
F_76 ( & V_113 ) ;
return V_106 ;
}
static unsigned long F_80 ( T_15 * V_122 )
{
return F_81 ( V_122 , V_123 ) + 1 ;
}
static T_11
F_82 ( T_15 * V_122 , T_16 * V_124 ,
T_10 * V_125 , unsigned long * V_126 , void * V_127 )
{
T_11 V_106 ;
T_10 V_128 , V_129 , V_130 ;
T_10 V_131 , V_132 ;
V_131 = F_74 ( V_126 ) ;
V_129 = F_74 ( V_124 ) ;
V_128 = F_35 ( V_122 , F_80 ( V_122 ) ) ;
V_130 = F_74 ( V_125 ) ;
V_132 = F_35 ( V_127 , * V_126 ) ;
V_106 = F_75 ( V_133 , V_128 , V_129 ,
V_130 , V_131 , V_132 ) ;
return V_106 ;
}
static T_11
F_83 ( T_15 * V_122 , T_16 * V_124 ,
T_10 V_125 , unsigned long V_126 , void * V_127 )
{
T_10 V_128 , V_129 , V_132 ;
T_11 V_106 ;
V_128 = F_35 ( V_122 , F_80 ( V_122 ) ) ;
V_129 = F_74 ( V_124 ) ;
V_132 = F_35 ( V_127 , V_126 ) ;
V_106 = F_75 ( V_134 , V_128 , V_129 ,
V_125 , V_126 , V_132 ) ;
return V_106 ;
}
static T_11
F_84 ( unsigned long * V_135 ,
T_15 * V_122 ,
T_16 * V_124 )
{
T_11 V_106 ;
T_10 V_136 , V_128 , V_129 ;
V_136 = F_74 ( V_135 ) ;
V_129 = F_74 ( V_124 ) ;
V_128 = F_35 ( V_122 , * V_135 ) ;
V_106 = F_75 ( V_137 , V_136 ,
V_128 , V_129 ) ;
return V_106 ;
}
static T_11
F_85 ( T_10 * V_138 )
{
T_11 V_106 ;
T_10 V_139 ;
V_139 = F_74 ( V_138 ) ;
V_106 = F_75 ( V_140 , V_139 ) ;
return V_106 ;
}
static void
F_86 ( int V_141 , T_11 V_106 ,
unsigned long V_126 , T_15 * V_127 )
{
T_10 V_132 ;
V_132 = F_35 ( V_127 , V_126 ) ;
F_75 ( V_142 , V_141 , V_106 , V_126 , V_132 ) ;
}
static T_11
F_87 ( T_17 * * V_143 ,
unsigned long V_138 , unsigned long V_144 )
{
return V_145 ;
}
static T_11
F_88 ( T_10 V_125 , T_8 * V_146 ,
T_8 * V_147 ,
T_8 * V_148 )
{
T_11 V_106 ;
T_10 V_149 , V_150 , V_151 ;
if ( V_152 . V_153 < V_154 )
return V_145 ;
V_149 = F_74 ( V_146 ) ;
V_150 = F_74 ( V_147 ) ;
V_151 = F_74 ( V_148 ) ;
V_106 = F_75 ( V_155 , V_125 , V_149 ,
V_150 , V_151 ) ;
return V_106 ;
}
static T_11
F_89 ( T_17 * * V_143 ,
unsigned long V_138 , T_8 * V_156 ,
int * V_141 )
{
return V_145 ;
}
void F_90 ( void )
{
V_152 . V_114 = F_72 ;
V_152 . V_115 = F_77 ;
V_152 . V_120 = F_78 ;
V_152 . V_121 = F_79 ;
V_152 . V_133 = F_82 ;
V_152 . V_137 = F_84 ;
V_152 . V_134 = F_83 ;
V_152 . V_140 = F_85 ;
V_152 . V_142 = F_86 ;
V_152 . V_155 = F_88 ;
V_152 . V_157 = F_87 ;
V_152 . V_158 = F_89 ;
}
