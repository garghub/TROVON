static int F_1 ( struct V_1 * V_2 , struct V_3 * V_3 )
{
struct V_4 V_5 ;
int V_6 ;
int V_7 ;
T_1 V_8 ;
T_1 V_9 ;
F_2 ( & V_10 ) ;
V_6 = V_2 -> V_11 ;
if ( ! V_3 || F_3 ( V_2 -> V_12 ) )
goto V_13;
F_4 ( & V_10 ) ;
if ( F_5 ( & V_3 -> V_14 , & V_5 ) )
return V_6 ;
V_9 = V_5 . V_15 * V_16 ;
V_8 = V_5 . V_15 * V_17 ;
F_6 ( V_9 , 100 ) ;
F_6 ( V_8 , 100 ) ;
if ( V_5 . V_18 <= V_9 )
V_7 = - 1 ;
else if ( V_5 . V_18 >= V_8 )
V_7 = 1 ;
else
V_7 = 0 ;
F_2 ( & V_10 ) ;
if ( V_3 != V_2 -> V_3 ) {
if ( V_7 )
V_6 = V_7 > 0 ;
goto V_13;
}
if ( V_2 -> V_11 ) {
if ( V_7 < 0 ) {
V_2 -> V_11 = 0 ;
F_7 ( V_19 L_1 ) ;
}
} else {
if ( V_7 > 0 ) {
V_2 -> V_11 = 1 ;
F_7 ( V_19 L_2 ) ;
}
}
V_2 -> V_12 = V_20 + V_21 * V_22 ;
V_6 = V_2 -> V_11 ;
V_13:
F_4 ( & V_10 ) ;
return V_6 ;
}
static void F_8 ( struct V_1 * V_2 , struct V_3 * V_3 ,
struct V_23 * V_24 )
{
struct V_3 * V_25 = NULL ;
struct V_23 * V_26 = NULL ;
if ( V_2 -> V_3 ) {
V_25 = V_2 -> V_3 ;
V_26 = V_2 -> V_24 ;
V_2 -> V_11 = 0 ;
V_2 -> V_3 = NULL ;
V_2 -> V_24 = NULL ;
F_9 ( & V_2 -> V_27 ) ;
}
if ( V_3 ) {
V_2 -> V_3 = V_3 ;
V_2 -> V_24 = V_24 ;
V_2 -> V_12 = V_20 + V_21 * V_22 ;
V_2 -> V_11 = 1 ;
F_10 ( & V_2 -> V_27 , & V_28 ) ;
}
if ( V_25 ) {
F_11 ( V_25 -> V_14 . V_29 ) ;
F_4 ( & V_10 ) ;
F_12 ( V_2 , V_26 , V_25 ) ;
F_13 ( V_25 , NULL ) ;
F_2 ( & V_10 ) ;
}
}
static int F_14 ( struct V_30 * V_31 )
{
struct V_3 * V_3 ;
struct V_32 * V_29 ;
struct V_23 * V_24 ;
struct V_1 * V_2 = NULL ;
V_3 = F_15 ( V_31 , V_33 | V_34 | V_35 , 0 ) ;
if ( F_16 ( V_3 ) )
return F_17 ( V_3 ) ;
if ( ! F_18 ( V_3 -> V_14 . V_36 -> V_37 -> V_38 ) ) {
F_13 ( V_3 , NULL ) ;
return - V_39 ;
}
if ( ! V_3 -> V_40 -> V_41 ) {
F_13 ( V_3 , NULL ) ;
return - V_42 ;
}
V_24 = F_19 ( V_43 ) ;
if ( V_24 -> V_44 == NULL ) {
V_2 = F_20 ( sizeof( struct V_1 ) , V_45 ) ;
if ( V_2 == NULL ) {
F_13 ( V_3 , NULL ) ;
return - V_46 ;
}
}
F_2 ( & V_10 ) ;
if ( V_24 -> V_44 == NULL ) {
V_24 -> V_44 = V_2 ;
V_2 = NULL ;
}
V_29 = V_3 -> V_14 . V_29 ;
F_21 ( V_29 ) ;
F_8 ( V_24 -> V_44 , V_3 , V_24 ) ;
F_4 ( & V_10 ) ;
F_22 ( V_29 ) ;
F_23 ( V_2 ) ;
return 0 ;
}
void F_24 ( struct V_32 * V_47 )
{
struct V_1 * V_2 ;
F_2 ( & V_10 ) ;
V_48:
F_25 (acct, &acct_list, list)
if ( V_2 -> V_3 && V_2 -> V_3 -> V_14 . V_29 == V_47 ) {
F_8 ( V_2 , NULL , NULL ) ;
goto V_48;
}
F_4 ( & V_10 ) ;
}
void F_26 ( struct V_49 * V_50 )
{
struct V_1 * V_2 ;
F_2 ( & V_10 ) ;
V_48:
F_25 (acct, &acct_list, list)
if ( V_2 -> V_3 && V_2 -> V_3 -> V_14 . V_36 -> V_51 == V_50 ) {
F_8 ( V_2 , NULL , NULL ) ;
goto V_48;
}
F_4 ( & V_10 ) ;
}
void F_27 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_44 ;
if ( V_2 == NULL )
return;
F_2 ( & V_10 ) ;
if ( V_2 -> V_3 != NULL )
F_8 ( V_2 , NULL , NULL ) ;
F_4 ( & V_10 ) ;
F_23 ( V_2 ) ;
}
static T_2 F_28 ( unsigned long V_52 )
{
int exp , V_53 ;
exp = V_53 = 0 ;
while ( V_52 > V_54 ) {
V_53 = V_52 & ( 1 << ( V_55 - 1 ) ) ;
V_52 >>= V_55 ;
exp ++ ;
}
if ( V_53 && ( ++ V_52 > V_54 ) ) {
V_52 >>= V_55 ;
exp ++ ;
}
exp <<= V_56 ;
exp += V_52 ;
return exp ;
}
static T_3 F_29 ( T_1 V_52 )
{
int exp , V_53 ;
exp = ( V_52 > ( V_57 >> 1 ) ) ;
V_53 = 0 ;
while ( V_52 > V_57 ) {
V_53 = V_52 & 1 ;
V_52 >>= 1 ;
exp ++ ;
}
if ( V_53 && ( ++ V_52 > V_57 ) ) {
V_52 >>= 1 ;
exp ++ ;
}
if ( exp > V_58 ) {
return ( 1ul << ( V_59 + V_60 - 1 ) ) - 1 ;
} else {
return ( V_52 & ( V_57 >> 1 ) ) | ( exp << ( V_59 - 1 ) ) ;
}
}
static T_4 F_30 ( T_1 V_52 )
{
unsigned exp = 190 ;
unsigned V_61 ;
if ( V_52 == 0 ) return 0 ;
while ( ( V_62 ) V_52 > 0 ) {
V_52 <<= 1 ;
exp -- ;
}
V_61 = ( T_4 ) ( V_52 >> 40 ) & 0x7fffffu ;
return V_61 | ( exp << 23 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_23 * V_24 , struct V_3 * V_3 )
{
struct V_63 * V_64 = & V_43 -> signal -> V_64 ;
T_5 V_65 ;
T_6 V_66 ;
unsigned long V_67 ;
T_1 V_68 ;
T_1 V_69 ;
struct V_70 V_71 ;
struct V_72 * V_73 ;
const struct V_74 * V_75 ;
V_75 = F_31 ( V_3 -> V_76 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
goto V_13;
memset ( & V_65 , 0 , sizeof( T_5 ) ) ;
V_65 . V_77 = V_78 | V_79 ;
F_32 ( V_65 . V_80 , V_43 -> V_81 , sizeof( V_65 . V_80 ) ) ;
F_33 ( & V_71 ) ;
V_69 = ( T_1 ) V_71 . V_82 * V_83 + V_71 . V_84 ;
V_69 -= ( T_1 ) V_43 -> V_85 -> V_86 . V_82 * V_83
+ V_43 -> V_85 -> V_86 . V_84 ;
V_68 = F_34 ( V_69 ) ;
#if V_78 == 3
V_65 . V_87 = F_30 ( V_68 ) ;
#else
V_65 . V_87 = F_28 ( V_68 < ( unsigned long ) - 1l ?
( unsigned long ) V_68 : ( unsigned long ) - 1l ) ;
#endif
#if V_78 == 1 || V_78 == 2
{
T_3 V_88 = F_29 ( V_68 ) ;
V_65 . V_89 = V_88 >> 16 ;
V_65 . V_90 = ( V_91 ) V_88 ;
}
#endif
F_6 ( V_68 , V_92 ) ;
V_65 . V_93 = F_35 () - V_68 ;
V_65 . V_94 = F_36 ( V_3 -> V_76 -> V_95 , V_75 -> V_96 ) ;
V_65 . V_97 = F_37 ( V_3 -> V_76 -> V_95 , V_75 -> V_98 ) ;
#if V_78 == 2
V_65 . V_99 = V_92 ;
#endif
#if V_78 == 1 || V_78 == 2
V_65 . V_100 = V_65 . V_94 ;
V_65 . V_101 = V_65 . V_97 ;
#endif
#if V_78 == 3
V_65 . V_102 = F_38 ( V_43 , V_24 ) ;
F_39 () ;
V_65 . V_103 = F_38 ( F_40 ( V_43 -> V_104 ) , V_24 ) ;
F_41 () ;
#endif
F_42 ( & V_43 -> V_105 -> V_106 ) ;
V_73 = V_43 -> signal -> V_73 ;
V_65 . V_107 = V_73 ? F_43 ( F_44 ( V_73 ) ) : 0 ;
V_65 . V_108 = F_28 ( F_45 ( F_46 ( V_64 -> V_108 ) ) ) ;
V_65 . V_109 = F_28 ( F_45 ( F_46 ( V_64 -> V_109 ) ) ) ;
V_65 . V_110 = V_64 -> V_110 ;
V_65 . V_111 = F_28 ( V_64 -> V_111 ) ;
V_65 . V_112 = F_28 ( V_64 -> V_112 ) ;
V_65 . V_113 = F_28 ( V_64 -> V_113 ) ;
V_65 . V_114 = V_64 -> V_114 ;
F_47 ( & V_43 -> V_105 -> V_106 ) ;
V_65 . V_115 = F_28 ( 0 ) ;
V_65 . V_116 = F_28 ( V_65 . V_115 / 1024 ) ;
V_65 . V_117 = F_28 ( 0 ) ;
V_66 = F_48 () ;
F_49 ( V_118 ) ;
V_67 = V_43 -> signal -> V_119 [ V_120 ] . V_121 ;
V_43 -> signal -> V_119 [ V_120 ] . V_121 = V_122 ;
V_3 -> V_40 -> V_41 ( V_3 , ( char * ) & V_65 ,
sizeof( T_5 ) , & V_3 -> V_123 ) ;
V_43 -> signal -> V_119 [ V_120 ] . V_121 = V_67 ;
F_49 ( V_66 ) ;
V_13:
F_50 ( V_75 ) ;
}
void F_51 ( long V_124 , int V_125 )
{
struct V_63 * V_64 = & V_43 -> signal -> V_64 ;
unsigned long V_126 = 0 ;
if ( V_125 && V_43 -> V_127 ) {
struct V_128 * V_129 ;
F_52 ( & V_43 -> V_127 -> V_130 ) ;
V_129 = V_43 -> V_127 -> V_131 ;
while ( V_129 ) {
V_126 += V_129 -> V_132 - V_129 -> V_133 ;
V_129 = V_129 -> V_134 ;
}
F_53 ( & V_43 -> V_127 -> V_130 ) ;
}
F_42 ( & V_43 -> V_105 -> V_106 ) ;
if ( V_125 )
V_64 -> V_111 = V_126 / 1024 ;
if ( F_54 ( V_43 ) ) {
V_64 -> V_114 = V_124 ;
if ( V_43 -> V_135 & V_136 )
V_64 -> V_110 |= V_137 ;
}
if ( V_43 -> V_135 & V_138 )
V_64 -> V_110 |= V_139 ;
if ( V_43 -> V_135 & V_140 )
V_64 -> V_110 |= V_141 ;
if ( V_43 -> V_135 & V_142 )
V_64 -> V_110 |= V_143 ;
V_64 -> V_108 += V_43 -> V_144 ;
V_64 -> V_109 += V_43 -> V_145 ;
V_64 -> V_112 += V_43 -> V_146 ;
V_64 -> V_113 += V_43 -> V_147 ;
F_47 ( & V_43 -> V_105 -> V_106 ) ;
}
static void F_55 ( struct V_23 * V_24 )
{
struct V_3 * V_3 = NULL ;
struct V_1 * V_2 ;
V_2 = V_24 -> V_44 ;
if ( ! V_2 || ! V_2 -> V_3 )
return;
F_2 ( & V_10 ) ;
V_3 = V_2 -> V_3 ;
if ( F_56 ( ! V_3 ) ) {
F_4 ( & V_10 ) ;
return;
}
F_57 ( V_3 ) ;
F_4 ( & V_10 ) ;
F_12 ( V_2 , V_24 , V_3 ) ;
F_58 ( V_3 ) ;
}
void F_59 ( void )
{
struct V_23 * V_24 ;
for ( V_24 = F_19 ( V_43 ) ; V_24 != NULL ; V_24 = V_24 -> V_148 )
F_55 ( V_24 ) ;
}
