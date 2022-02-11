static void T_1 F_1 ( int V_1 )
{
T_2 * V_2 ;
void * V_3 ;
if ( ! ( V_4 & V_5 ) )
return;
for ( V_3 = V_6 . V_7 ; V_3 < V_6 . V_8 ; V_3 += V_6 . V_9 ) {
V_2 = V_3 ;
if ( V_2 -> type == V_10 ||
V_2 -> type == V_11 )
F_2 ( V_2 , V_1 ) ;
}
}
T_3 * T_1 F_3 ( void )
{
unsigned long V_12 ;
T_3 * V_13 ;
int V_14 ;
int V_15 ;
if ( ! F_4 ( V_16 ) ) {
V_13 = ( T_3 * ) F_5 () ;
F_6 ( ( unsigned long ) V_17 . V_18 ) ;
goto V_19;
}
F_1 ( 1 ) ;
V_15 = F_7 ( ( V_20 << V_21 ) , V_22 ) ;
V_13 = F_8 ( V_15 * sizeof( T_3 ) , V_23 ) ;
for ( V_14 = 0 ; V_14 < V_15 ; V_14 ++ ) {
V_13 [ V_14 ] = * F_9 ( V_14 * V_22 ) ;
V_12 = ( unsigned long ) F_10 ( V_14 * V_22 ) ;
F_11 ( F_9 ( V_14 * V_22 ) , * F_9 ( V_12 ) ) ;
}
V_19:
F_12 () ;
return V_13 ;
}
void T_1 F_13 ( T_3 * V_13 )
{
int V_24 ;
int V_25 ;
if ( ! F_4 ( V_16 ) ) {
F_6 ( ( unsigned long ) V_13 ) ;
F_12 () ;
return;
}
V_25 = F_7 ( ( V_20 << V_21 ) , V_22 ) ;
for ( V_24 = 0 ; V_24 < V_25 ; V_24 ++ )
F_11 ( F_9 ( V_24 * V_22 ) , V_13 [ V_24 ] ) ;
F_14 ( V_13 ) ;
F_12 () ;
F_1 ( 0 ) ;
}
int T_1 F_15 ( void )
{
T_3 * V_14 ;
T_4 * V_26 ;
T_5 V_27 ;
if ( F_4 ( V_16 ) )
return 0 ;
V_27 = V_23 | V_28 | V_29 | V_30 ;
V_31 = ( T_3 * ) F_16 ( V_27 ) ;
if ( ! V_31 )
return - V_32 ;
V_14 = V_31 + F_17 ( V_33 ) ;
V_26 = F_18 ( NULL , 0 ) ;
if ( ! V_26 ) {
F_19 ( ( unsigned long ) V_31 ) ;
return - V_32 ;
}
F_20 ( NULL , V_14 , V_26 ) ;
return 0 ;
}
void F_21 ( void )
{
unsigned V_34 ;
T_3 * V_35 , * V_36 ;
T_4 * V_37 , * V_38 ;
if ( F_4 ( V_16 ) )
return;
F_22 ( F_17 ( V_33 ) != F_17 ( V_39 ) ) ;
F_22 ( ( V_40 & V_41 ) !=
( V_33 & V_41 ) ) ;
V_36 = V_31 + F_17 ( V_42 ) ;
V_35 = F_9 ( V_42 ) ;
V_34 = F_17 ( V_33 ) - F_17 ( V_42 ) ;
memcpy ( V_36 , V_35 , sizeof( T_3 ) * V_34 ) ;
F_22 ( ( V_40 & ~ V_43 ) != 0 ) ;
F_22 ( ( V_33 & ~ V_43 ) != 0 ) ;
V_36 = V_31 + F_17 ( V_33 ) ;
V_38 = F_23 ( V_36 , 0 ) ;
V_35 = F_9 ( V_33 ) ;
V_37 = F_23 ( V_35 , 0 ) ;
V_34 = F_24 ( V_33 ) ;
memcpy ( V_38 , V_37 , sizeof( T_4 ) * V_34 ) ;
V_38 = F_23 ( V_36 , V_40 ) ;
V_37 = F_23 ( V_35 , V_40 ) ;
V_34 = V_44 - F_24 ( V_40 ) ;
memcpy ( V_38 , V_37 , sizeof( T_4 ) * V_34 ) ;
}
int T_1 F_25 ( unsigned long V_45 , unsigned V_46 )
{
unsigned long V_47 , V_48 ;
T_2 * V_2 ;
struct V_49 * V_49 ;
unsigned V_50 ;
T_3 * V_14 ;
if ( F_4 ( V_16 ) )
return 0 ;
V_17 . V_18 = ( T_3 * ) F_26 ( V_31 ) ;
V_14 = V_31 ;
V_47 = V_45 >> V_21 ;
if ( F_27 ( V_14 , V_47 , V_45 , V_46 , V_5 | V_51 ) ) {
F_28 ( L_1 , V_45 ) ;
return 1 ;
}
V_17 . V_52 = true ;
if ( ! F_29 ( V_53 ) )
return 0 ;
F_30 (&memmap, md) {
if ( V_2 -> type != V_54 &&
V_2 -> type != V_55 &&
V_2 -> type != V_56 )
continue;
V_47 = V_2 -> V_57 >> V_21 ;
V_50 = V_2 -> V_46 ;
if ( F_27 ( V_14 , V_47 , V_2 -> V_57 , V_50 , V_51 ) ) {
F_28 ( L_2 ) ;
return 1 ;
}
}
V_49 = F_31 ( V_23 | V_58 ) ;
if ( ! V_49 )
F_32 ( L_3 ) ;
V_17 . V_59 = F_33 ( F_34 ( V_49 ) ) ;
V_17 . V_59 += V_60 ;
V_50 = ( V_61 - V_62 ) >> V_21 ;
V_48 = F_26 ( V_62 ) ;
V_47 = V_48 >> V_21 ;
if ( F_27 ( V_14 , V_47 , V_48 , V_50 , V_51 ) ) {
F_28 ( L_4 ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_35 ( unsigned long V_45 , unsigned V_46 )
{
F_36 ( V_31 , V_45 , V_46 ) ;
}
static void T_1 F_37 ( T_2 * V_2 , T_6 V_63 )
{
unsigned long V_64 = V_51 ;
unsigned long V_47 ;
T_3 * V_14 = V_31 ;
if ( ! ( V_2 -> V_65 & V_66 ) )
V_64 |= V_67 ;
V_47 = V_2 -> V_57 >> V_21 ;
if ( F_27 ( V_14 , V_47 , V_63 , V_2 -> V_46 , V_64 ) )
F_38 ( L_5 ,
V_2 -> V_57 , V_63 ) ;
}
void T_1 F_39 ( T_2 * V_2 )
{
unsigned long V_68 = V_2 -> V_46 << V_21 ;
T_6 V_69 = V_2 -> V_57 ;
if ( F_4 ( V_16 ) )
return F_40 ( V_2 ) ;
F_37 ( V_2 , V_2 -> V_57 ) ;
if ( ! F_41 () && F_29 ( V_53 ) ) {
V_2 -> V_70 = V_2 -> V_57 ;
return;
}
V_71 -= V_68 ;
if ( ! ( V_69 & ( V_72 - 1 ) ) ) {
V_71 &= V_73 ;
} else {
T_6 V_74 = V_69 & ( V_72 - 1 ) ;
T_6 V_75 = V_71 ;
V_71 = ( V_71 & V_73 ) + V_74 ;
if ( V_71 > V_75 )
V_71 -= V_72 ;
}
if ( V_71 < V_33 ) {
F_38 ( V_76 L_6 ) ;
return;
}
F_37 ( V_2 , V_71 ) ;
V_2 -> V_70 = V_71 ;
}
void T_1 F_42 ( T_2 * V_2 )
{
F_37 ( V_2 , V_2 -> V_70 ) ;
}
void T_7 * T_1 F_43 ( unsigned long V_57 , unsigned long V_68 ,
T_8 type , T_6 V_65 )
{
unsigned long V_77 ;
if ( type == V_78 )
return F_44 ( V_57 , V_68 ) ;
V_77 = F_45 ( V_57 , V_57 + V_68 ) ;
if ( ( V_77 << V_21 ) < V_57 + V_68 ) {
unsigned long V_79 = V_77 << V_21 ;
F_43 ( V_79 , V_68 - ( V_79 - V_57 ) , type , V_65 ) ;
}
if ( ! ( V_65 & V_66 ) )
F_46 ( ( T_6 ) ( unsigned long ) F_10 ( V_57 ) , V_68 ) ;
return ( void T_7 * ) F_10 ( V_57 ) ;
}
void T_1 F_47 ( T_6 V_57 , T_8 V_80 )
{
V_81 = V_57 + sizeof( struct V_82 ) ;
}
void T_1 F_48 ( void )
{
unsigned long V_47 ;
T_3 * V_14 = V_31 ;
T_2 * V_2 ;
void * V_3 ;
if ( F_4 ( V_16 ) ) {
if ( V_4 & V_5 )
F_49 () ;
return;
}
if ( ! F_4 ( V_83 ) )
return;
for ( V_3 = V_6 . V_7 ; V_3 < V_6 . V_8 ; V_3 += V_6 . V_9 ) {
unsigned long V_84 = 0 ;
V_2 = V_3 ;
if ( ! ( V_2 -> V_65 & V_85 ) )
continue;
if ( ! ( V_2 -> V_65 & V_66 ) )
V_84 |= V_67 ;
if ( ( V_2 -> V_65 & V_86 ) ||
( V_2 -> type == V_87 ) )
V_84 |= V_5 ;
if ( ! ( V_2 -> V_65 & V_88 ) &&
( V_2 -> type != V_10 ) )
V_84 |= V_51 ;
V_47 = V_2 -> V_57 >> V_21 ;
if ( F_27 ( V_14 , V_47 , V_2 -> V_57 , V_2 -> V_46 , V_84 ) )
F_38 ( L_5 ,
V_2 -> V_57 , V_2 -> V_70 ) ;
if ( F_27 ( V_14 , V_47 , V_2 -> V_70 , V_2 -> V_46 , V_84 ) )
F_38 ( L_5 ,
V_2 -> V_57 , V_2 -> V_70 ) ;
}
}
void T_1 F_50 ( void )
{
#ifdef F_51
F_52 ( NULL , V_31 ) ;
#endif
}
T_9 F_53 (
void * V_89 ,
unsigned long V_90 ,
unsigned long V_91 ,
T_8 V_92 ,
T_2 * V_93 )
{
T_9 V_94 ;
unsigned long V_64 ;
T_8 V_95 ;
F_21 () ;
F_54 ( V_64 ) ;
V_17 . V_96 = F_5 () ;
F_6 ( ( unsigned long ) V_17 . V_18 ) ;
F_12 () ;
V_95 = ( T_8 ) ( unsigned long ) V_89 ;
V_94 = F_55 ( V_95 , V_90 , V_91 ,
V_92 , V_93 ) ;
F_6 ( V_17 . V_96 ) ;
F_12 () ;
F_56 ( V_64 ) ;
return V_94 ;
}
static T_9 F_57 ( T_10 * V_97 , T_11 * V_98 )
{
T_9 V_94 ;
T_8 V_99 , V_100 ;
F_58 ( & V_101 ) ;
V_99 = F_33 ( V_97 ) ;
V_100 = F_33 ( V_98 ) ;
V_94 = F_59 ( V_102 , V_99 , V_100 ) ;
F_60 ( & V_101 ) ;
return V_94 ;
}
static T_9 F_61 ( T_10 * V_97 )
{
T_9 V_94 ;
T_8 V_99 ;
F_58 ( & V_101 ) ;
V_99 = F_33 ( V_97 ) ;
V_94 = F_59 ( V_103 , V_99 ) ;
F_60 ( & V_101 ) ;
return V_94 ;
}
static T_9
F_62 ( T_12 * V_104 , T_12 * V_105 ,
T_10 * V_97 )
{
T_9 V_94 ;
T_8 V_106 , V_107 , V_99 ;
F_58 ( & V_101 ) ;
V_106 = F_33 ( V_104 ) ;
V_107 = F_33 ( V_105 ) ;
V_99 = F_33 ( V_97 ) ;
V_94 = F_59 ( V_108 , V_106 ,
V_107 , V_99 ) ;
F_60 ( & V_101 ) ;
return V_94 ;
}
static T_9
F_63 ( T_12 V_104 , T_10 * V_97 )
{
T_9 V_94 ;
T_8 V_99 ;
F_58 ( & V_101 ) ;
V_99 = F_33 ( V_97 ) ;
V_94 = F_59 ( V_109 , V_104 , V_99 ) ;
F_60 ( & V_101 ) ;
return V_94 ;
}
static T_9
F_64 ( T_13 * V_110 , T_14 * V_111 ,
T_8 * V_112 , unsigned long * V_113 , void * V_114 )
{
T_9 V_94 ;
T_8 V_115 , V_116 , V_117 ;
T_8 V_118 , V_119 ;
V_118 = F_33 ( V_113 ) ;
V_116 = F_33 ( V_111 ) ;
V_115 = F_33 ( V_110 ) ;
V_117 = F_33 ( V_112 ) ;
V_119 = F_33 ( V_114 ) ;
V_94 = F_59 ( V_120 , V_115 , V_116 ,
V_117 , V_118 , V_119 ) ;
return V_94 ;
}
static T_9
F_65 ( T_13 * V_110 , T_14 * V_111 ,
T_8 V_112 , unsigned long V_113 , void * V_114 )
{
T_8 V_115 , V_116 , V_119 ;
T_9 V_94 ;
V_115 = F_33 ( V_110 ) ;
V_116 = F_33 ( V_111 ) ;
V_119 = F_33 ( V_114 ) ;
V_94 = F_59 ( V_121 , V_115 , V_116 ,
V_112 , V_113 , V_119 ) ;
return V_94 ;
}
static T_9
F_66 ( unsigned long * V_122 ,
T_13 * V_110 ,
T_14 * V_111 )
{
T_9 V_94 ;
T_8 V_123 , V_115 , V_116 ;
V_123 = F_33 ( V_122 ) ;
V_116 = F_33 ( V_111 ) ;
V_115 = F_33 ( V_110 ) ;
V_94 = F_59 ( V_124 , V_123 ,
V_115 , V_116 ) ;
return V_94 ;
}
static T_9
F_67 ( T_8 * V_125 )
{
T_9 V_94 ;
T_8 V_126 ;
V_126 = F_33 ( V_125 ) ;
V_94 = F_59 ( V_127 , V_126 ) ;
return V_94 ;
}
static void
F_68 ( int V_128 , T_9 V_94 ,
unsigned long V_113 , T_13 * V_114 )
{
T_8 V_119 ;
V_119 = F_33 ( V_114 ) ;
F_59 ( V_129 , V_128 , V_94 , V_113 , V_119 ) ;
}
static T_9
F_69 ( T_15 * * V_130 ,
unsigned long V_125 , unsigned long V_131 )
{
return V_132 ;
}
static T_9
F_70 ( T_8 V_112 , T_6 * V_133 ,
T_6 * V_134 ,
T_6 * V_135 )
{
T_9 V_94 ;
T_8 V_136 , V_137 , V_138 ;
if ( V_139 . V_140 < V_141 )
return V_132 ;
V_136 = F_33 ( V_133 ) ;
V_137 = F_33 ( V_134 ) ;
V_138 = F_33 ( V_135 ) ;
V_94 = F_59 ( V_142 , V_112 , V_136 ,
V_137 , V_138 ) ;
return V_94 ;
}
static T_9
F_71 ( T_15 * * V_130 ,
unsigned long V_125 , T_6 * V_143 ,
int * V_128 )
{
return V_132 ;
}
void F_72 ( void )
{
V_139 . V_102 = F_57 ;
V_139 . V_103 = F_61 ;
V_139 . V_108 = F_62 ;
V_139 . V_109 = F_63 ;
V_139 . V_120 = F_64 ;
V_139 . V_124 = F_66 ;
V_139 . V_121 = F_65 ;
V_139 . V_127 = F_67 ;
V_139 . V_129 = F_68 ;
V_139 . V_142 = F_70 ;
V_139 . V_144 = F_69 ;
V_139 . V_145 = F_71 ;
}
