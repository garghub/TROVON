static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = (struct V_2 * ) V_1 ;
V_3 -> V_4 = 1 ;
}
static int F_2 ( struct V_2 * V_3 , struct V_5 * V_5 )
{
struct V_6 V_7 ;
int V_8 ;
int V_9 ;
T_1 V_10 ;
T_1 V_11 ;
F_3 ( & V_12 ) ;
V_8 = V_3 -> V_13 ;
if ( ! V_5 || ! V_3 -> V_4 )
goto V_14;
F_4 ( & V_12 ) ;
if ( F_5 ( & V_5 -> V_15 , & V_7 ) )
return V_8 ;
V_11 = V_7 . V_16 * V_17 ;
V_10 = V_7 . V_16 * V_18 ;
F_6 ( V_11 , 100 ) ;
F_6 ( V_10 , 100 ) ;
if ( V_7 . V_19 <= V_11 )
V_9 = - 1 ;
else if ( V_7 . V_19 >= V_10 )
V_9 = 1 ;
else
V_9 = 0 ;
F_3 ( & V_12 ) ;
if ( V_5 != V_3 -> V_5 ) {
if ( V_9 )
V_8 = V_9 > 0 ;
goto V_14;
}
if ( V_3 -> V_13 ) {
if ( V_9 < 0 ) {
V_3 -> V_13 = 0 ;
F_7 ( V_20 L_1 ) ;
}
} else {
if ( V_9 > 0 ) {
V_3 -> V_13 = 1 ;
F_7 ( V_20 L_2 ) ;
}
}
F_8 ( & V_3 -> V_21 ) ;
V_3 -> V_4 = 0 ;
V_3 -> V_21 . V_22 = V_23 + V_24 * V_25 ;
F_9 ( & V_3 -> V_21 ) ;
V_8 = V_3 -> V_13 ;
V_14:
F_4 ( & V_12 ) ;
return V_8 ;
}
static void F_10 ( struct V_2 * V_3 , struct V_5 * V_5 ,
struct V_26 * V_27 )
{
struct V_5 * V_28 = NULL ;
struct V_26 * V_29 = NULL ;
if ( V_3 -> V_5 ) {
V_28 = V_3 -> V_5 ;
V_29 = V_3 -> V_27 ;
F_8 ( & V_3 -> V_21 ) ;
V_3 -> V_13 = 0 ;
V_3 -> V_4 = 0 ;
V_3 -> V_5 = NULL ;
V_3 -> V_27 = NULL ;
F_11 ( & V_3 -> V_30 ) ;
}
if ( V_5 ) {
V_3 -> V_5 = V_5 ;
V_3 -> V_27 = V_27 ;
V_3 -> V_4 = 0 ;
V_3 -> V_13 = 1 ;
F_12 ( & V_3 -> V_30 , & V_31 ) ;
F_13 ( & V_3 -> V_21 , F_1 , ( unsigned long ) V_3 ) ;
V_3 -> V_21 . V_22 = V_23 + V_24 * V_25 ;
F_9 ( & V_3 -> V_21 ) ;
}
if ( V_28 ) {
F_14 ( V_28 -> V_15 . V_32 ) ;
F_4 ( & V_12 ) ;
F_15 ( V_3 , V_29 , V_28 ) ;
F_16 ( V_28 , NULL ) ;
F_3 ( & V_12 ) ;
}
}
static int F_17 ( char * V_33 )
{
struct V_5 * V_5 ;
struct V_34 * V_32 ;
struct V_26 * V_27 ;
struct V_2 * V_3 = NULL ;
V_5 = F_18 ( V_33 , V_35 | V_36 | V_37 , 0 ) ;
if ( F_19 ( V_5 ) )
return F_20 ( V_5 ) ;
if ( ! F_21 ( V_5 -> V_15 . V_38 -> V_39 -> V_40 ) ) {
F_16 ( V_5 , NULL ) ;
return - V_41 ;
}
if ( ! V_5 -> V_42 -> V_43 ) {
F_16 ( V_5 , NULL ) ;
return - V_44 ;
}
V_27 = F_22 ( V_45 ) ;
if ( V_27 -> V_46 == NULL ) {
V_3 = F_23 ( sizeof( struct V_2 ) , V_47 ) ;
if ( V_3 == NULL ) {
F_16 ( V_5 , NULL ) ;
return - V_48 ;
}
}
F_3 ( & V_12 ) ;
if ( V_27 -> V_46 == NULL ) {
V_27 -> V_46 = V_3 ;
V_3 = NULL ;
}
V_32 = V_5 -> V_15 . V_32 ;
F_24 ( V_32 ) ;
F_10 ( V_27 -> V_46 , V_5 , V_27 ) ;
F_4 ( & V_12 ) ;
F_25 ( V_32 ) ;
F_26 ( V_3 ) ;
return 0 ;
}
void F_27 ( struct V_34 * V_49 )
{
struct V_2 * V_3 ;
F_3 ( & V_12 ) ;
V_50:
F_28 (acct, &acct_list, list)
if ( V_3 -> V_5 && V_3 -> V_5 -> V_15 . V_32 == V_49 ) {
F_10 ( V_3 , NULL , NULL ) ;
goto V_50;
}
F_4 ( & V_12 ) ;
}
void F_29 ( struct V_51 * V_52 )
{
struct V_2 * V_3 ;
F_3 ( & V_12 ) ;
V_50:
F_28 (acct, &acct_list, list)
if ( V_3 -> V_5 && V_3 -> V_5 -> V_15 . V_32 -> V_53 == V_52 ) {
F_10 ( V_3 , NULL , NULL ) ;
goto V_50;
}
F_4 ( & V_12 ) ;
}
void F_30 ( struct V_26 * V_27 )
{
struct V_2 * V_3 = V_27 -> V_46 ;
if ( V_3 == NULL )
return;
F_31 ( & V_3 -> V_21 ) ;
F_3 ( & V_12 ) ;
if ( V_3 -> V_5 != NULL )
F_10 ( V_3 , NULL , NULL ) ;
F_4 ( & V_12 ) ;
F_26 ( V_3 ) ;
}
static T_2 F_32 ( unsigned long V_54 )
{
int exp , V_55 ;
exp = V_55 = 0 ;
while ( V_54 > V_56 ) {
V_55 = V_54 & ( 1 << ( V_57 - 1 ) ) ;
V_54 >>= V_57 ;
exp ++ ;
}
if ( V_55 && ( ++ V_54 > V_56 ) ) {
V_54 >>= V_57 ;
exp ++ ;
}
exp <<= V_58 ;
exp += V_54 ;
return exp ;
}
static T_3 F_33 ( T_4 V_54 )
{
int exp , V_55 ;
exp = ( V_54 > ( V_59 >> 1 ) ) ;
V_55 = 0 ;
while ( V_54 > V_59 ) {
V_55 = V_54 & 1 ;
V_54 >>= 1 ;
exp ++ ;
}
if ( V_55 && ( ++ V_54 > V_59 ) ) {
V_54 >>= 1 ;
exp ++ ;
}
if ( exp > V_60 ) {
return ( 1ul << ( V_61 + V_62 - 1 ) ) - 1 ;
} else {
return ( V_54 & ( V_59 >> 1 ) ) | ( exp << ( V_61 - 1 ) ) ;
}
}
static T_5 F_34 ( T_4 V_54 )
{
unsigned exp = 190 ;
unsigned V_63 ;
if ( V_54 == 0 ) return 0 ;
while ( ( V_64 ) V_54 > 0 ) {
V_54 <<= 1 ;
exp -- ;
}
V_63 = ( T_5 ) ( V_54 >> 40 ) & 0x7fffffu ;
return V_63 | ( exp << 23 ) ;
}
static void F_15 ( struct V_2 * V_3 ,
struct V_26 * V_27 , struct V_5 * V_5 )
{
struct V_65 * V_66 = & V_45 -> signal -> V_66 ;
T_6 V_67 ;
T_7 V_68 ;
unsigned long V_69 ;
T_4 V_70 ;
T_4 V_71 ;
struct V_72 V_73 ;
struct V_74 * V_75 ;
const struct V_76 * V_77 ;
V_77 = F_35 ( V_5 -> V_78 ) ;
if ( ! F_2 ( V_3 , V_5 ) )
goto V_14;
memset ( ( V_79 ) & V_67 , 0 , sizeof( T_6 ) ) ;
V_67 . V_80 = V_81 | V_82 ;
F_36 ( V_67 . V_83 , V_45 -> V_84 , sizeof( V_67 . V_83 ) ) ;
F_37 ( & V_73 ) ;
V_71 = ( T_4 ) V_73 . V_85 * V_86 + V_73 . V_87 ;
V_71 -= ( T_4 ) V_45 -> V_88 -> V_89 . V_85 * V_86
+ V_45 -> V_88 -> V_89 . V_87 ;
V_70 = F_38 ( V_71 ) ;
#if V_81 == 3
V_67 . V_90 = F_34 ( V_70 ) ;
#else
V_67 . V_90 = F_32 ( V_70 < ( unsigned long ) - 1l ?
( unsigned long ) V_70 : ( unsigned long ) - 1l ) ;
#endif
#if V_81 == 1 || V_81 == 2
{
T_3 V_91 = F_33 ( V_70 ) ;
V_67 . V_92 = V_91 >> 16 ;
V_67 . V_93 = ( V_94 ) V_91 ;
}
#endif
F_39 ( V_70 , V_95 ) ;
V_67 . V_96 = F_40 () - V_70 ;
V_67 . V_97 = V_77 -> V_98 ;
V_67 . V_99 = V_77 -> V_100 ;
#if V_81 == 2
V_67 . V_101 = V_95 ;
#endif
#if V_81 == 1 || V_81 == 2
V_67 . V_102 = V_67 . V_97 ;
V_67 . V_103 = V_67 . V_99 ;
#endif
#if V_81 == 3
V_67 . V_104 = F_41 ( V_45 , V_27 ) ;
F_42 () ;
V_67 . V_105 = F_41 ( F_43 ( V_45 -> V_106 ) , V_27 ) ;
F_44 () ;
#endif
F_45 ( & V_45 -> V_107 -> V_108 ) ;
V_75 = V_45 -> signal -> V_75 ;
V_67 . V_109 = V_75 ? F_46 ( F_47 ( V_75 ) ) : 0 ;
V_67 . V_110 = F_32 ( F_48 ( F_49 ( V_66 -> V_110 ) ) ) ;
V_67 . V_111 = F_32 ( F_48 ( F_49 ( V_66 -> V_111 ) ) ) ;
V_67 . V_112 = V_66 -> V_112 ;
V_67 . V_113 = F_32 ( V_66 -> V_113 ) ;
V_67 . V_114 = F_32 ( V_66 -> V_114 ) ;
V_67 . V_115 = F_32 ( V_66 -> V_115 ) ;
V_67 . V_116 = V_66 -> V_116 ;
F_50 ( & V_45 -> V_107 -> V_108 ) ;
V_67 . V_117 = F_32 ( 0 ) ;
V_67 . V_118 = F_32 ( V_67 . V_117 / 1024 ) ;
V_67 . V_119 = F_32 ( 0 ) ;
V_68 = F_51 () ;
F_52 ( V_120 ) ;
V_69 = V_45 -> signal -> V_121 [ V_122 ] . V_123 ;
V_45 -> signal -> V_121 [ V_122 ] . V_123 = V_124 ;
V_5 -> V_42 -> V_43 ( V_5 , ( char * ) & V_67 ,
sizeof( T_6 ) , & V_5 -> V_125 ) ;
V_45 -> signal -> V_121 [ V_122 ] . V_123 = V_69 ;
F_52 ( V_68 ) ;
V_14:
F_53 ( V_77 ) ;
}
void F_54 ( long V_126 , int V_127 )
{
struct V_65 * V_66 = & V_45 -> signal -> V_66 ;
unsigned long V_128 = 0 ;
if ( V_127 && V_45 -> V_129 ) {
struct V_130 * V_131 ;
F_55 ( & V_45 -> V_129 -> V_132 ) ;
V_131 = V_45 -> V_129 -> V_133 ;
while ( V_131 ) {
V_128 += V_131 -> V_134 - V_131 -> V_135 ;
V_131 = V_131 -> V_136 ;
}
F_56 ( & V_45 -> V_129 -> V_132 ) ;
}
F_45 ( & V_45 -> V_107 -> V_108 ) ;
if ( V_127 )
V_66 -> V_113 = V_128 / 1024 ;
if ( F_57 ( V_45 ) ) {
V_66 -> V_116 = V_126 ;
if ( V_45 -> V_137 & V_138 )
V_66 -> V_112 |= V_139 ;
}
if ( V_45 -> V_137 & V_140 )
V_66 -> V_112 |= V_141 ;
if ( V_45 -> V_137 & V_142 )
V_66 -> V_112 |= V_143 ;
if ( V_45 -> V_137 & V_144 )
V_66 -> V_112 |= V_145 ;
V_66 -> V_110 = F_58 ( V_66 -> V_110 , V_45 -> V_146 ) ;
V_66 -> V_111 = F_58 ( V_66 -> V_111 , V_45 -> V_147 ) ;
V_66 -> V_114 += V_45 -> V_148 ;
V_66 -> V_115 += V_45 -> V_149 ;
F_50 ( & V_45 -> V_107 -> V_108 ) ;
}
static void F_59 ( struct V_26 * V_27 )
{
struct V_5 * V_5 = NULL ;
struct V_2 * V_3 ;
V_3 = V_27 -> V_46 ;
if ( ! V_3 || ! V_3 -> V_5 )
return;
F_3 ( & V_12 ) ;
V_5 = V_3 -> V_5 ;
if ( F_60 ( ! V_5 ) ) {
F_4 ( & V_12 ) ;
return;
}
F_61 ( V_5 ) ;
F_4 ( & V_12 ) ;
F_15 ( V_3 , V_27 , V_5 ) ;
F_62 ( V_5 ) ;
}
void F_63 ( void )
{
struct V_26 * V_27 ;
for ( V_27 = F_22 ( V_45 ) ; V_27 != NULL ; V_27 = V_27 -> V_150 )
F_59 ( V_27 ) ;
}
