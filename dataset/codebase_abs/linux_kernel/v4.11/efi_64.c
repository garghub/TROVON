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
unsigned long V_7 ;
T_3 * V_8 ;
int V_9 ;
int V_10 ;
if ( ! F_5 ( V_11 ) ) {
V_8 = ( T_3 * ) F_6 () ;
F_7 ( ( unsigned long ) V_12 . V_13 ) ;
goto V_14;
}
F_1 ( 1 ) ;
V_10 = F_8 ( ( V_15 << V_16 ) , V_17 ) ;
V_8 = F_9 ( V_10 , sizeof( * V_8 ) , V_18 ) ;
for ( V_9 = 0 ; V_9 < V_10 ; V_9 ++ ) {
V_8 [ V_9 ] = * F_10 ( V_9 * V_17 ) ;
V_7 = ( unsigned long ) F_11 ( V_9 * V_17 ) ;
F_12 ( F_10 ( V_9 * V_17 ) , * F_10 ( V_7 ) ) ;
}
V_14:
F_13 () ;
return V_8 ;
}
void T_1 F_14 ( T_3 * V_8 )
{
int V_19 ;
int V_20 ;
if ( ! F_5 ( V_11 ) ) {
F_7 ( ( unsigned long ) V_8 ) ;
F_13 () ;
return;
}
V_20 = F_8 ( ( V_15 << V_16 ) , V_17 ) ;
for ( V_19 = 0 ; V_19 < V_20 ; V_19 ++ )
F_12 ( F_10 ( V_19 * V_17 ) , V_8 [ V_19 ] ) ;
F_15 ( V_8 ) ;
F_13 () ;
F_1 ( 0 ) ;
}
int T_1 F_16 ( void )
{
T_3 * V_9 ;
T_4 * V_21 ;
T_5 V_22 ;
if ( F_5 ( V_11 ) )
return 0 ;
V_22 = V_18 | V_23 | V_24 ;
V_25 = ( T_3 * ) F_17 ( V_22 ) ;
if ( ! V_25 )
return - V_26 ;
V_9 = V_25 + F_18 ( V_27 ) ;
V_21 = F_19 ( NULL , 0 ) ;
if ( ! V_21 ) {
F_20 ( ( unsigned long ) V_25 ) ;
return - V_26 ;
}
F_21 ( NULL , V_9 , V_21 ) ;
return 0 ;
}
void F_22 ( void )
{
unsigned V_28 ;
T_3 * V_29 , * V_30 ;
T_4 * V_31 , * V_32 ;
if ( F_5 ( V_11 ) )
return;
F_23 ( F_18 ( V_27 ) != F_18 ( V_33 ) ) ;
F_23 ( ( V_34 & V_35 ) !=
( V_27 & V_35 ) ) ;
V_30 = V_25 + F_18 ( V_36 ) ;
V_29 = F_10 ( V_36 ) ;
V_28 = F_18 ( V_27 ) - F_18 ( V_36 ) ;
memcpy ( V_30 , V_29 , sizeof( T_3 ) * V_28 ) ;
F_23 ( ( V_34 & ~ V_37 ) != 0 ) ;
F_23 ( ( V_27 & ~ V_37 ) != 0 ) ;
V_30 = V_25 + F_18 ( V_27 ) ;
V_32 = F_24 ( V_30 , 0 ) ;
V_29 = F_10 ( V_27 ) ;
V_31 = F_24 ( V_29 , 0 ) ;
V_28 = F_25 ( V_27 ) ;
memcpy ( V_32 , V_31 , sizeof( T_4 ) * V_28 ) ;
V_32 = F_24 ( V_30 , V_34 ) ;
V_31 = F_24 ( V_29 , V_34 ) ;
V_28 = V_38 - F_25 ( V_34 ) ;
memcpy ( V_32 , V_31 , sizeof( T_4 ) * V_28 ) ;
}
static inline T_6
F_26 ( void * V_39 , unsigned long V_40 )
{
bool V_41 ;
if ( ! V_39 )
return 0 ;
if ( F_27 ( V_39 ) )
return F_28 ( V_39 ) ;
V_41 = V_40 > V_42 || ! F_29 ( V_40 ) ;
F_30 ( ! F_31 ( ( unsigned long ) V_39 , V_40 ) || V_41 ) ;
return F_32 ( V_39 ) ;
}
int T_1 F_33 ( unsigned long V_43 , unsigned V_44 )
{
unsigned long V_45 , V_46 ;
struct V_47 * V_47 ;
unsigned V_48 ;
T_3 * V_9 ;
if ( F_5 ( V_11 ) )
return 0 ;
V_12 . V_13 = ( T_3 * ) F_34 ( V_25 ) ;
V_9 = V_25 ;
V_45 = V_43 >> V_16 ;
if ( F_35 ( V_9 , V_45 , V_43 , V_44 , V_4 | V_49 ) ) {
F_36 ( L_1 , V_43 ) ;
return 1 ;
}
V_12 . V_50 = true ;
if ( F_35 ( V_9 , 0x0 , 0x0 , 1 , V_49 ) ) {
F_36 ( L_2 ) ;
return 1 ;
}
if ( ! F_37 ( V_51 ) || F_38 () )
return 0 ;
V_47 = F_39 ( V_18 | V_52 ) ;
if ( ! V_47 )
F_40 ( L_3 ) ;
V_12 . V_53 = F_28 ( F_41 ( V_47 ) ) ;
V_12 . V_53 += V_42 ;
V_48 = ( V_54 - V_55 ) >> V_16 ;
V_46 = F_34 ( V_55 ) ;
V_45 = V_46 >> V_16 ;
if ( F_35 ( V_9 , V_45 , V_46 , V_48 , V_49 ) ) {
F_36 ( L_4 ) ;
return 1 ;
}
return 0 ;
}
static void T_1 F_42 ( T_2 * V_2 , T_7 V_39 )
{
unsigned long V_56 = V_49 ;
unsigned long V_45 ;
T_3 * V_9 = V_25 ;
if ( ! ( V_2 -> V_57 & V_58 ) )
V_56 |= V_59 ;
V_45 = V_2 -> V_60 >> V_16 ;
if ( F_35 ( V_9 , V_45 , V_39 , V_2 -> V_44 , V_56 ) )
F_43 ( L_5 ,
V_2 -> V_60 , V_39 ) ;
}
void T_1 F_44 ( T_2 * V_2 )
{
unsigned long V_40 = V_2 -> V_44 << V_16 ;
T_7 V_61 = V_2 -> V_60 ;
if ( F_5 ( V_11 ) )
return F_45 ( V_2 ) ;
F_42 ( V_2 , V_2 -> V_60 ) ;
if ( ! F_38 () && F_37 ( V_51 ) ) {
V_2 -> V_62 = V_2 -> V_60 ;
return;
}
V_63 -= V_40 ;
if ( ! ( V_61 & ( V_64 - 1 ) ) ) {
V_63 &= V_65 ;
} else {
T_7 V_66 = V_61 & ( V_64 - 1 ) ;
T_7 V_67 = V_63 ;
V_63 = ( V_63 & V_65 ) + V_66 ;
if ( V_63 > V_67 )
V_63 -= V_64 ;
}
if ( V_63 < V_27 ) {
F_43 ( V_68 L_6 ) ;
return;
}
F_42 ( V_2 , V_63 ) ;
V_2 -> V_62 = V_63 ;
}
void T_1 F_46 ( T_2 * V_2 )
{
F_42 ( V_2 , V_2 -> V_60 ) ;
F_42 ( V_2 , V_2 -> V_62 ) ;
}
void T_8 * T_1 F_47 ( unsigned long V_60 , unsigned long V_40 ,
T_9 type , T_7 V_57 )
{
unsigned long V_69 ;
if ( type == V_70 )
return F_48 ( V_60 , V_40 ) ;
V_69 = F_49 ( V_60 , V_60 + V_40 ) ;
if ( ( V_69 << V_16 ) < V_60 + V_40 ) {
unsigned long V_71 = V_69 << V_16 ;
F_47 ( V_71 , V_40 - ( V_71 - V_60 ) , type , V_57 ) ;
}
if ( ! ( V_57 & V_58 ) )
F_50 ( ( T_7 ) ( unsigned long ) F_11 ( V_60 ) , V_40 ) ;
return ( void T_8 * ) F_11 ( V_60 ) ;
}
void T_1 F_51 ( T_7 V_60 , T_9 V_72 )
{
V_73 = V_60 + sizeof( struct V_74 ) ;
}
static int T_1 F_52 ( T_2 * V_2 , unsigned long V_75 )
{
unsigned long V_45 ;
T_3 * V_9 = V_25 ;
int V_76 , V_77 ;
V_45 = V_2 -> V_60 >> V_16 ;
V_76 = F_35 ( V_9 , V_45 , V_2 -> V_60 , V_2 -> V_44 , V_75 ) ;
if ( V_76 ) {
F_36 ( L_7 ,
V_2 -> V_60 , V_2 -> V_62 ) ;
}
V_77 = F_35 ( V_9 , V_45 , V_2 -> V_62 , V_2 -> V_44 , V_75 ) ;
if ( V_77 ) {
F_36 ( L_8 ,
V_2 -> V_60 , V_2 -> V_62 ) ;
}
return V_76 || V_77 ;
}
static int T_1 F_53 ( struct V_78 * V_79 , T_2 * V_2 )
{
unsigned long V_75 = 0 ;
if ( V_2 -> V_57 & V_80 )
V_75 |= V_4 ;
if ( ! ( V_2 -> V_57 & V_81 ) )
V_75 |= V_49 ;
return F_52 ( V_2 , V_75 ) ;
}
void T_1 F_54 ( void )
{
T_2 * V_2 ;
if ( F_5 ( V_11 ) ) {
if ( V_3 & V_4 )
F_55 () ;
return;
}
if ( F_5 ( V_82 ) ) {
F_56 ( NULL , F_53 ) ;
return;
}
if ( ! F_5 ( V_83 ) )
return;
F_2 (md) {
unsigned long V_75 = 0 ;
if ( ! ( V_2 -> V_57 & V_84 ) )
continue;
if ( ! ( V_2 -> V_57 & V_58 ) )
V_75 |= V_59 ;
if ( ( V_2 -> V_57 & V_80 ) ||
( V_2 -> type == V_85 ) )
V_75 |= V_4 ;
if ( ! ( V_2 -> V_57 & V_81 ) &&
( V_2 -> type != V_5 ) )
V_75 |= V_49 ;
F_52 ( V_2 , V_75 ) ;
}
}
void T_1 F_57 ( void )
{
#ifdef F_58
F_59 ( NULL , V_25 ) ;
#endif
}
T_10 F_60 (
void * V_86 ,
unsigned long V_87 ,
unsigned long V_88 ,
T_9 V_89 ,
T_2 * V_90 )
{
T_10 V_91 ;
unsigned long V_56 ;
T_9 V_92 ;
F_22 () ;
F_61 ( V_56 ) ;
V_12 . V_93 = F_6 () ;
F_7 ( ( unsigned long ) V_12 . V_13 ) ;
F_13 () ;
V_92 = ( T_9 ) ( unsigned long ) V_86 ;
V_91 = F_62 ( V_92 , V_87 , V_88 ,
V_89 , V_90 ) ;
F_7 ( V_12 . V_93 ) ;
F_13 () ;
F_63 ( V_56 ) ;
return V_91 ;
}
static T_10 F_64 ( T_11 * V_94 , T_12 * V_95 )
{
T_10 V_91 ;
T_9 V_96 , V_97 ;
F_65 ( & V_98 ) ;
V_96 = F_66 ( V_94 ) ;
V_97 = F_66 ( V_95 ) ;
V_91 = F_67 ( V_99 , V_96 , V_97 ) ;
F_68 ( & V_98 ) ;
return V_91 ;
}
static T_10 F_69 ( T_11 * V_94 )
{
T_10 V_91 ;
T_9 V_96 ;
F_65 ( & V_98 ) ;
V_96 = F_66 ( V_94 ) ;
V_91 = F_67 ( V_100 , V_96 ) ;
F_68 ( & V_98 ) ;
return V_91 ;
}
static T_10
F_70 ( T_13 * V_101 , T_13 * V_102 ,
T_11 * V_94 )
{
T_10 V_91 ;
T_9 V_103 , V_104 , V_96 ;
F_65 ( & V_98 ) ;
V_103 = F_66 ( V_101 ) ;
V_104 = F_66 ( V_102 ) ;
V_96 = F_66 ( V_94 ) ;
V_91 = F_67 ( V_105 , V_103 ,
V_104 , V_96 ) ;
F_68 ( & V_98 ) ;
return V_91 ;
}
static T_10
F_71 ( T_13 V_101 , T_11 * V_94 )
{
T_10 V_91 ;
T_9 V_96 ;
F_65 ( & V_98 ) ;
V_96 = F_66 ( V_94 ) ;
V_91 = F_67 ( V_106 , V_101 , V_96 ) ;
F_68 ( & V_98 ) ;
return V_91 ;
}
static unsigned long F_72 ( T_14 * V_107 )
{
return F_73 ( V_107 , V_108 ) + 1 ;
}
static T_10
F_74 ( T_14 * V_107 , T_15 * V_109 ,
T_9 * V_110 , unsigned long * V_111 , void * V_112 )
{
T_10 V_91 ;
T_9 V_113 , V_114 , V_115 ;
T_9 V_116 , V_117 ;
V_116 = F_66 ( V_111 ) ;
V_114 = F_66 ( V_109 ) ;
V_113 = F_26 ( V_107 , F_72 ( V_107 ) ) ;
V_115 = F_66 ( V_110 ) ;
V_117 = F_26 ( V_112 , * V_111 ) ;
V_91 = F_67 ( V_118 , V_113 , V_114 ,
V_115 , V_116 , V_117 ) ;
return V_91 ;
}
static T_10
F_75 ( T_14 * V_107 , T_15 * V_109 ,
T_9 V_110 , unsigned long V_111 , void * V_112 )
{
T_9 V_113 , V_114 , V_117 ;
T_10 V_91 ;
V_113 = F_26 ( V_107 , F_72 ( V_107 ) ) ;
V_114 = F_66 ( V_109 ) ;
V_117 = F_26 ( V_112 , V_111 ) ;
V_91 = F_67 ( V_119 , V_113 , V_114 ,
V_110 , V_111 , V_117 ) ;
return V_91 ;
}
static T_10
F_76 ( unsigned long * V_120 ,
T_14 * V_107 ,
T_15 * V_109 )
{
T_10 V_91 ;
T_9 V_121 , V_113 , V_114 ;
V_121 = F_66 ( V_120 ) ;
V_114 = F_66 ( V_109 ) ;
V_113 = F_26 ( V_107 , * V_120 ) ;
V_91 = F_67 ( V_122 , V_121 ,
V_113 , V_114 ) ;
return V_91 ;
}
static T_10
F_77 ( T_9 * V_123 )
{
T_10 V_91 ;
T_9 V_124 ;
V_124 = F_66 ( V_123 ) ;
V_91 = F_67 ( V_125 , V_124 ) ;
return V_91 ;
}
static void
F_78 ( int V_126 , T_10 V_91 ,
unsigned long V_111 , T_14 * V_112 )
{
T_9 V_117 ;
V_117 = F_26 ( V_112 , V_111 ) ;
F_67 ( V_127 , V_126 , V_91 , V_111 , V_117 ) ;
}
static T_10
F_79 ( T_16 * * V_128 ,
unsigned long V_123 , unsigned long V_129 )
{
return V_130 ;
}
static T_10
F_80 ( T_9 V_110 , T_7 * V_131 ,
T_7 * V_132 ,
T_7 * V_133 )
{
T_10 V_91 ;
T_9 V_134 , V_135 , V_136 ;
if ( V_137 . V_138 < V_139 )
return V_130 ;
V_134 = F_66 ( V_131 ) ;
V_135 = F_66 ( V_132 ) ;
V_136 = F_66 ( V_133 ) ;
V_91 = F_67 ( V_140 , V_110 , V_134 ,
V_135 , V_136 ) ;
return V_91 ;
}
static T_10
F_81 ( T_16 * * V_128 ,
unsigned long V_123 , T_7 * V_141 ,
int * V_126 )
{
return V_130 ;
}
void F_82 ( void )
{
V_137 . V_99 = F_64 ;
V_137 . V_100 = F_69 ;
V_137 . V_105 = F_70 ;
V_137 . V_106 = F_71 ;
V_137 . V_118 = F_74 ;
V_137 . V_122 = F_76 ;
V_137 . V_119 = F_75 ;
V_137 . V_125 = F_77 ;
V_137 . V_127 = F_78 ;
V_137 . V_140 = F_80 ;
V_137 . V_142 = F_79 ;
V_137 . V_143 = F_81 ;
}
