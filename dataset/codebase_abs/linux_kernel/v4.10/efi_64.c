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
void T_1 F_52 ( void )
{
unsigned long V_45 ;
T_3 * V_9 = V_25 ;
T_2 * V_2 ;
if ( F_5 ( V_11 ) ) {
if ( V_3 & V_4 )
F_53 () ;
return;
}
if ( ! F_5 ( V_75 ) )
return;
F_2 (md) {
unsigned long V_76 = 0 ;
if ( ! ( V_2 -> V_57 & V_77 ) )
continue;
if ( ! ( V_2 -> V_57 & V_58 ) )
V_76 |= V_59 ;
if ( ( V_2 -> V_57 & V_78 ) ||
( V_2 -> type == V_79 ) )
V_76 |= V_4 ;
if ( ! ( V_2 -> V_57 & V_80 ) &&
( V_2 -> type != V_5 ) )
V_76 |= V_49 ;
V_45 = V_2 -> V_60 >> V_16 ;
if ( F_35 ( V_9 , V_45 , V_2 -> V_60 , V_2 -> V_44 , V_76 ) )
F_43 ( L_5 ,
V_2 -> V_60 , V_2 -> V_62 ) ;
if ( F_35 ( V_9 , V_45 , V_2 -> V_62 , V_2 -> V_44 , V_76 ) )
F_43 ( L_5 ,
V_2 -> V_60 , V_2 -> V_62 ) ;
}
}
void T_1 F_54 ( void )
{
#ifdef F_55
F_56 ( NULL , V_25 ) ;
#endif
}
T_10 F_57 (
void * V_81 ,
unsigned long V_82 ,
unsigned long V_83 ,
T_9 V_84 ,
T_2 * V_85 )
{
T_10 V_86 ;
unsigned long V_56 ;
T_9 V_87 ;
F_22 () ;
F_58 ( V_56 ) ;
V_12 . V_88 = F_6 () ;
F_7 ( ( unsigned long ) V_12 . V_13 ) ;
F_13 () ;
V_87 = ( T_9 ) ( unsigned long ) V_81 ;
V_86 = F_59 ( V_87 , V_82 , V_83 ,
V_84 , V_85 ) ;
F_7 ( V_12 . V_88 ) ;
F_13 () ;
F_60 ( V_56 ) ;
return V_86 ;
}
static T_10 F_61 ( T_11 * V_89 , T_12 * V_90 )
{
T_10 V_86 ;
T_9 V_91 , V_92 ;
F_62 ( & V_93 ) ;
V_91 = F_63 ( V_89 ) ;
V_92 = F_63 ( V_90 ) ;
V_86 = F_64 ( V_94 , V_91 , V_92 ) ;
F_65 ( & V_93 ) ;
return V_86 ;
}
static T_10 F_66 ( T_11 * V_89 )
{
T_10 V_86 ;
T_9 V_91 ;
F_62 ( & V_93 ) ;
V_91 = F_63 ( V_89 ) ;
V_86 = F_64 ( V_95 , V_91 ) ;
F_65 ( & V_93 ) ;
return V_86 ;
}
static T_10
F_67 ( T_13 * V_96 , T_13 * V_97 ,
T_11 * V_89 )
{
T_10 V_86 ;
T_9 V_98 , V_99 , V_91 ;
F_62 ( & V_93 ) ;
V_98 = F_63 ( V_96 ) ;
V_99 = F_63 ( V_97 ) ;
V_91 = F_63 ( V_89 ) ;
V_86 = F_64 ( V_100 , V_98 ,
V_99 , V_91 ) ;
F_65 ( & V_93 ) ;
return V_86 ;
}
static T_10
F_68 ( T_13 V_96 , T_11 * V_89 )
{
T_10 V_86 ;
T_9 V_91 ;
F_62 ( & V_93 ) ;
V_91 = F_63 ( V_89 ) ;
V_86 = F_64 ( V_101 , V_96 , V_91 ) ;
F_65 ( & V_93 ) ;
return V_86 ;
}
static unsigned long F_69 ( T_14 * V_102 )
{
return F_70 ( V_102 , V_103 ) + 1 ;
}
static T_10
F_71 ( T_14 * V_102 , T_15 * V_104 ,
T_9 * V_105 , unsigned long * V_106 , void * V_107 )
{
T_10 V_86 ;
T_9 V_108 , V_109 , V_110 ;
T_9 V_111 , V_112 ;
V_111 = F_63 ( V_106 ) ;
V_109 = F_63 ( V_104 ) ;
V_108 = F_26 ( V_102 , F_69 ( V_102 ) ) ;
V_110 = F_63 ( V_105 ) ;
V_112 = F_26 ( V_107 , * V_106 ) ;
V_86 = F_64 ( V_113 , V_108 , V_109 ,
V_110 , V_111 , V_112 ) ;
return V_86 ;
}
static T_10
F_72 ( T_14 * V_102 , T_15 * V_104 ,
T_9 V_105 , unsigned long V_106 , void * V_107 )
{
T_9 V_108 , V_109 , V_112 ;
T_10 V_86 ;
V_108 = F_26 ( V_102 , F_69 ( V_102 ) ) ;
V_109 = F_63 ( V_104 ) ;
V_112 = F_26 ( V_107 , V_106 ) ;
V_86 = F_64 ( V_114 , V_108 , V_109 ,
V_105 , V_106 , V_112 ) ;
return V_86 ;
}
static T_10
F_73 ( unsigned long * V_115 ,
T_14 * V_102 ,
T_15 * V_104 )
{
T_10 V_86 ;
T_9 V_116 , V_108 , V_109 ;
V_116 = F_63 ( V_115 ) ;
V_109 = F_63 ( V_104 ) ;
V_108 = F_26 ( V_102 , * V_115 ) ;
V_86 = F_64 ( V_117 , V_116 ,
V_108 , V_109 ) ;
return V_86 ;
}
static T_10
F_74 ( T_9 * V_118 )
{
T_10 V_86 ;
T_9 V_119 ;
V_119 = F_63 ( V_118 ) ;
V_86 = F_64 ( V_120 , V_119 ) ;
return V_86 ;
}
static void
F_75 ( int V_121 , T_10 V_86 ,
unsigned long V_106 , T_14 * V_107 )
{
T_9 V_112 ;
V_112 = F_26 ( V_107 , V_106 ) ;
F_64 ( V_122 , V_121 , V_86 , V_106 , V_112 ) ;
}
static T_10
F_76 ( T_16 * * V_123 ,
unsigned long V_118 , unsigned long V_124 )
{
return V_125 ;
}
static T_10
F_77 ( T_9 V_105 , T_7 * V_126 ,
T_7 * V_127 ,
T_7 * V_128 )
{
T_10 V_86 ;
T_9 V_129 , V_130 , V_131 ;
if ( V_132 . V_133 < V_134 )
return V_125 ;
V_129 = F_63 ( V_126 ) ;
V_130 = F_63 ( V_127 ) ;
V_131 = F_63 ( V_128 ) ;
V_86 = F_64 ( V_135 , V_105 , V_129 ,
V_130 , V_131 ) ;
return V_86 ;
}
static T_10
F_78 ( T_16 * * V_123 ,
unsigned long V_118 , T_7 * V_136 ,
int * V_121 )
{
return V_125 ;
}
void F_79 ( void )
{
V_132 . V_94 = F_61 ;
V_132 . V_95 = F_66 ;
V_132 . V_100 = F_67 ;
V_132 . V_101 = F_68 ;
V_132 . V_113 = F_71 ;
V_132 . V_117 = F_73 ;
V_132 . V_114 = F_72 ;
V_132 . V_120 = F_74 ;
V_132 . V_122 = F_75 ;
V_132 . V_135 = F_77 ;
V_132 . V_137 = F_76 ;
V_132 . V_138 = F_78 ;
}
