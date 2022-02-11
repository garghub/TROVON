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
V_8 = F_9 ( V_10 * sizeof( T_3 ) , V_18 ) ;
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
int T_1 F_26 ( unsigned long V_39 , unsigned V_40 )
{
unsigned long V_41 , V_42 ;
T_2 * V_2 ;
struct V_43 * V_43 ;
unsigned V_44 ;
T_3 * V_9 ;
if ( F_5 ( V_11 ) )
return 0 ;
V_12 . V_13 = ( T_3 * ) F_27 ( V_25 ) ;
V_9 = V_25 ;
V_41 = V_39 >> V_16 ;
if ( F_28 ( V_9 , V_41 , V_39 , V_40 , V_4 | V_45 ) ) {
F_29 ( L_1 , V_39 ) ;
return 1 ;
}
V_12 . V_46 = true ;
if ( ! F_30 ( V_47 ) )
return 0 ;
F_2 (md) {
if ( V_2 -> type != V_48 &&
V_2 -> type != V_49 &&
V_2 -> type != V_50 )
continue;
V_41 = V_2 -> V_51 >> V_16 ;
V_44 = V_2 -> V_40 ;
if ( F_28 ( V_9 , V_41 , V_2 -> V_51 , V_44 , V_45 ) ) {
F_29 ( L_2 ) ;
return 1 ;
}
}
V_43 = F_31 ( V_18 | V_52 ) ;
if ( ! V_43 )
F_32 ( L_3 ) ;
V_12 . V_53 = F_33 ( F_34 ( V_43 ) ) ;
V_12 . V_53 += V_54 ;
V_44 = ( V_55 - V_56 ) >> V_16 ;
V_42 = F_27 ( V_56 ) ;
V_41 = V_42 >> V_16 ;
if ( F_28 ( V_9 , V_41 , V_42 , V_44 , V_45 ) ) {
F_29 ( L_4 ) ;
return 1 ;
}
return 0 ;
}
void T_1 F_35 ( unsigned long V_39 , unsigned V_40 )
{
F_36 ( V_25 , V_39 , V_40 ) ;
}
static void T_1 F_37 ( T_2 * V_2 , T_6 V_57 )
{
unsigned long V_58 = V_45 ;
unsigned long V_41 ;
T_3 * V_9 = V_25 ;
if ( ! ( V_2 -> V_59 & V_60 ) )
V_58 |= V_61 ;
V_41 = V_2 -> V_51 >> V_16 ;
if ( F_28 ( V_9 , V_41 , V_57 , V_2 -> V_40 , V_58 ) )
F_38 ( L_5 ,
V_2 -> V_51 , V_57 ) ;
}
void T_1 F_39 ( T_2 * V_2 )
{
unsigned long V_62 = V_2 -> V_40 << V_16 ;
T_6 V_63 = V_2 -> V_51 ;
if ( F_5 ( V_11 ) )
return F_40 ( V_2 ) ;
F_37 ( V_2 , V_2 -> V_51 ) ;
if ( ! F_41 () && F_30 ( V_47 ) ) {
V_2 -> V_64 = V_2 -> V_51 ;
return;
}
V_65 -= V_62 ;
if ( ! ( V_63 & ( V_66 - 1 ) ) ) {
V_65 &= V_67 ;
} else {
T_6 V_68 = V_63 & ( V_66 - 1 ) ;
T_6 V_69 = V_65 ;
V_65 = ( V_65 & V_67 ) + V_68 ;
if ( V_65 > V_69 )
V_65 -= V_66 ;
}
if ( V_65 < V_27 ) {
F_38 ( V_70 L_6 ) ;
return;
}
F_37 ( V_2 , V_65 ) ;
V_2 -> V_64 = V_65 ;
}
void T_1 F_42 ( T_2 * V_2 )
{
F_37 ( V_2 , V_2 -> V_64 ) ;
}
void T_7 * T_1 F_43 ( unsigned long V_51 , unsigned long V_62 ,
T_8 type , T_6 V_59 )
{
unsigned long V_71 ;
if ( type == V_72 )
return F_44 ( V_51 , V_62 ) ;
V_71 = F_45 ( V_51 , V_51 + V_62 ) ;
if ( ( V_71 << V_16 ) < V_51 + V_62 ) {
unsigned long V_73 = V_71 << V_16 ;
F_43 ( V_73 , V_62 - ( V_73 - V_51 ) , type , V_59 ) ;
}
if ( ! ( V_59 & V_60 ) )
F_46 ( ( T_6 ) ( unsigned long ) F_11 ( V_51 ) , V_62 ) ;
return ( void T_7 * ) F_11 ( V_51 ) ;
}
void T_1 F_47 ( T_6 V_51 , T_8 V_74 )
{
V_75 = V_51 + sizeof( struct V_76 ) ;
}
void T_1 F_48 ( void )
{
unsigned long V_41 ;
T_3 * V_9 = V_25 ;
T_2 * V_2 ;
if ( F_5 ( V_11 ) ) {
if ( V_3 & V_4 )
F_49 () ;
return;
}
if ( ! F_5 ( V_77 ) )
return;
F_2 (md) {
unsigned long V_78 = 0 ;
if ( ! ( V_2 -> V_59 & V_79 ) )
continue;
if ( ! ( V_2 -> V_59 & V_60 ) )
V_78 |= V_61 ;
if ( ( V_2 -> V_59 & V_80 ) ||
( V_2 -> type == V_81 ) )
V_78 |= V_4 ;
if ( ! ( V_2 -> V_59 & V_82 ) &&
( V_2 -> type != V_5 ) )
V_78 |= V_45 ;
V_41 = V_2 -> V_51 >> V_16 ;
if ( F_28 ( V_9 , V_41 , V_2 -> V_51 , V_2 -> V_40 , V_78 ) )
F_38 ( L_5 ,
V_2 -> V_51 , V_2 -> V_64 ) ;
if ( F_28 ( V_9 , V_41 , V_2 -> V_64 , V_2 -> V_40 , V_78 ) )
F_38 ( L_5 ,
V_2 -> V_51 , V_2 -> V_64 ) ;
}
}
void T_1 F_50 ( void )
{
#ifdef F_51
F_52 ( NULL , V_25 ) ;
#endif
}
T_9 F_53 (
void * V_83 ,
unsigned long V_84 ,
unsigned long V_85 ,
T_8 V_86 ,
T_2 * V_87 )
{
T_9 V_88 ;
unsigned long V_58 ;
T_8 V_89 ;
F_22 () ;
F_54 ( V_58 ) ;
V_12 . V_90 = F_6 () ;
F_7 ( ( unsigned long ) V_12 . V_13 ) ;
F_13 () ;
V_89 = ( T_8 ) ( unsigned long ) V_83 ;
V_88 = F_55 ( V_89 , V_84 , V_85 ,
V_86 , V_87 ) ;
F_7 ( V_12 . V_90 ) ;
F_13 () ;
F_56 ( V_58 ) ;
return V_88 ;
}
static T_9 F_57 ( T_10 * V_91 , T_11 * V_92 )
{
T_9 V_88 ;
T_8 V_93 , V_94 ;
F_58 ( & V_95 ) ;
V_93 = F_33 ( V_91 ) ;
V_94 = F_33 ( V_92 ) ;
V_88 = F_59 ( V_96 , V_93 , V_94 ) ;
F_60 ( & V_95 ) ;
return V_88 ;
}
static T_9 F_61 ( T_10 * V_91 )
{
T_9 V_88 ;
T_8 V_93 ;
F_58 ( & V_95 ) ;
V_93 = F_33 ( V_91 ) ;
V_88 = F_59 ( V_97 , V_93 ) ;
F_60 ( & V_95 ) ;
return V_88 ;
}
static T_9
F_62 ( T_12 * V_98 , T_12 * V_99 ,
T_10 * V_91 )
{
T_9 V_88 ;
T_8 V_100 , V_101 , V_93 ;
F_58 ( & V_95 ) ;
V_100 = F_33 ( V_98 ) ;
V_101 = F_33 ( V_99 ) ;
V_93 = F_33 ( V_91 ) ;
V_88 = F_59 ( V_102 , V_100 ,
V_101 , V_93 ) ;
F_60 ( & V_95 ) ;
return V_88 ;
}
static T_9
F_63 ( T_12 V_98 , T_10 * V_91 )
{
T_9 V_88 ;
T_8 V_93 ;
F_58 ( & V_95 ) ;
V_93 = F_33 ( V_91 ) ;
V_88 = F_59 ( V_103 , V_98 , V_93 ) ;
F_60 ( & V_95 ) ;
return V_88 ;
}
static T_9
F_64 ( T_13 * V_104 , T_14 * V_105 ,
T_8 * V_106 , unsigned long * V_107 , void * V_108 )
{
T_9 V_88 ;
T_8 V_109 , V_110 , V_111 ;
T_8 V_112 , V_113 ;
V_112 = F_33 ( V_107 ) ;
V_110 = F_33 ( V_105 ) ;
V_109 = F_33 ( V_104 ) ;
V_111 = F_33 ( V_106 ) ;
V_113 = F_33 ( V_108 ) ;
V_88 = F_59 ( V_114 , V_109 , V_110 ,
V_111 , V_112 , V_113 ) ;
return V_88 ;
}
static T_9
F_65 ( T_13 * V_104 , T_14 * V_105 ,
T_8 V_106 , unsigned long V_107 , void * V_108 )
{
T_8 V_109 , V_110 , V_113 ;
T_9 V_88 ;
V_109 = F_33 ( V_104 ) ;
V_110 = F_33 ( V_105 ) ;
V_113 = F_33 ( V_108 ) ;
V_88 = F_59 ( V_115 , V_109 , V_110 ,
V_106 , V_107 , V_113 ) ;
return V_88 ;
}
static T_9
F_66 ( unsigned long * V_116 ,
T_13 * V_104 ,
T_14 * V_105 )
{
T_9 V_88 ;
T_8 V_117 , V_109 , V_110 ;
V_117 = F_33 ( V_116 ) ;
V_110 = F_33 ( V_105 ) ;
V_109 = F_33 ( V_104 ) ;
V_88 = F_59 ( V_118 , V_117 ,
V_109 , V_110 ) ;
return V_88 ;
}
static T_9
F_67 ( T_8 * V_119 )
{
T_9 V_88 ;
T_8 V_120 ;
V_120 = F_33 ( V_119 ) ;
V_88 = F_59 ( V_121 , V_120 ) ;
return V_88 ;
}
static void
F_68 ( int V_122 , T_9 V_88 ,
unsigned long V_107 , T_13 * V_108 )
{
T_8 V_113 ;
V_113 = F_33 ( V_108 ) ;
F_59 ( V_123 , V_122 , V_88 , V_107 , V_113 ) ;
}
static T_9
F_69 ( T_15 * * V_124 ,
unsigned long V_119 , unsigned long V_125 )
{
return V_126 ;
}
static T_9
F_70 ( T_8 V_106 , T_6 * V_127 ,
T_6 * V_128 ,
T_6 * V_129 )
{
T_9 V_88 ;
T_8 V_130 , V_131 , V_132 ;
if ( V_133 . V_134 < V_135 )
return V_126 ;
V_130 = F_33 ( V_127 ) ;
V_131 = F_33 ( V_128 ) ;
V_132 = F_33 ( V_129 ) ;
V_88 = F_59 ( V_136 , V_106 , V_130 ,
V_131 , V_132 ) ;
return V_88 ;
}
static T_9
F_71 ( T_15 * * V_124 ,
unsigned long V_119 , T_6 * V_137 ,
int * V_122 )
{
return V_126 ;
}
void F_72 ( void )
{
V_133 . V_96 = F_57 ;
V_133 . V_97 = F_61 ;
V_133 . V_102 = F_62 ;
V_133 . V_103 = F_63 ;
V_133 . V_114 = F_64 ;
V_133 . V_118 = F_66 ;
V_133 . V_115 = F_65 ;
V_133 . V_121 = F_67 ;
V_133 . V_123 = F_68 ;
V_133 . V_136 = F_70 ;
V_133 . V_138 = F_69 ;
V_133 . V_139 = F_71 ;
}
