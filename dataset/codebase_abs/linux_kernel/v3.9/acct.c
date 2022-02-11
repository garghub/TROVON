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
if ( ! F_18 ( F_19 ( V_3 ) -> V_36 ) ) {
F_13 ( V_3 , NULL ) ;
return - V_37 ;
}
if ( ! V_3 -> V_38 -> V_39 ) {
F_13 ( V_3 , NULL ) ;
return - V_40 ;
}
V_24 = F_20 ( V_41 ) ;
if ( V_24 -> V_42 == NULL ) {
V_2 = F_21 ( sizeof( struct V_1 ) , V_43 ) ;
if ( V_2 == NULL ) {
F_13 ( V_3 , NULL ) ;
return - V_44 ;
}
}
F_2 ( & V_10 ) ;
if ( V_24 -> V_42 == NULL ) {
V_24 -> V_42 = V_2 ;
V_2 = NULL ;
}
V_29 = V_3 -> V_14 . V_29 ;
F_22 ( V_29 ) ;
F_8 ( V_24 -> V_42 , V_3 , V_24 ) ;
F_4 ( & V_10 ) ;
F_23 ( V_29 ) ;
F_24 ( V_2 ) ;
return 0 ;
}
void F_25 ( struct V_32 * V_45 )
{
struct V_1 * V_2 ;
F_2 ( & V_10 ) ;
V_46:
F_26 (acct, &acct_list, list)
if ( V_2 -> V_3 && V_2 -> V_3 -> V_14 . V_29 == V_45 ) {
F_8 ( V_2 , NULL , NULL ) ;
goto V_46;
}
F_4 ( & V_10 ) ;
}
void F_27 ( struct V_47 * V_48 )
{
struct V_1 * V_2 ;
F_2 ( & V_10 ) ;
V_46:
F_26 (acct, &acct_list, list)
if ( V_2 -> V_3 && V_2 -> V_3 -> V_14 . V_49 -> V_50 == V_48 ) {
F_8 ( V_2 , NULL , NULL ) ;
goto V_46;
}
F_4 ( & V_10 ) ;
}
void F_28 ( struct V_23 * V_24 )
{
struct V_1 * V_2 = V_24 -> V_42 ;
if ( V_2 == NULL )
return;
F_2 ( & V_10 ) ;
if ( V_2 -> V_3 != NULL )
F_8 ( V_2 , NULL , NULL ) ;
F_4 ( & V_10 ) ;
F_24 ( V_2 ) ;
}
static T_2 F_29 ( unsigned long V_51 )
{
int exp , V_52 ;
exp = V_52 = 0 ;
while ( V_51 > V_53 ) {
V_52 = V_51 & ( 1 << ( V_54 - 1 ) ) ;
V_51 >>= V_54 ;
exp ++ ;
}
if ( V_52 && ( ++ V_51 > V_53 ) ) {
V_51 >>= V_54 ;
exp ++ ;
}
exp <<= V_55 ;
exp += V_51 ;
return exp ;
}
static T_3 F_30 ( T_1 V_51 )
{
int exp , V_52 ;
exp = ( V_51 > ( V_56 >> 1 ) ) ;
V_52 = 0 ;
while ( V_51 > V_56 ) {
V_52 = V_51 & 1 ;
V_51 >>= 1 ;
exp ++ ;
}
if ( V_52 && ( ++ V_51 > V_56 ) ) {
V_51 >>= 1 ;
exp ++ ;
}
if ( exp > V_57 ) {
return ( 1ul << ( V_58 + V_59 - 1 ) ) - 1 ;
} else {
return ( V_51 & ( V_56 >> 1 ) ) | ( exp << ( V_58 - 1 ) ) ;
}
}
static T_4 F_31 ( T_1 V_51 )
{
unsigned exp = 190 ;
unsigned V_60 ;
if ( V_51 == 0 ) return 0 ;
while ( ( V_61 ) V_51 > 0 ) {
V_51 <<= 1 ;
exp -- ;
}
V_60 = ( T_4 ) ( V_51 >> 40 ) & 0x7fffffu ;
return V_60 | ( exp << 23 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
struct V_23 * V_24 , struct V_3 * V_3 )
{
struct V_62 * V_63 = & V_41 -> signal -> V_63 ;
T_5 V_64 ;
T_6 V_65 ;
unsigned long V_66 ;
T_1 V_67 ;
T_1 V_68 ;
struct V_69 V_70 ;
struct V_71 * V_72 ;
const struct V_73 * V_74 ;
V_74 = F_32 ( V_3 -> V_75 ) ;
if ( ! F_1 ( V_2 , V_3 ) )
goto V_13;
memset ( & V_64 , 0 , sizeof( T_5 ) ) ;
V_64 . V_76 = V_77 | V_78 ;
F_33 ( V_64 . V_79 , V_41 -> V_80 , sizeof( V_64 . V_79 ) ) ;
F_34 ( & V_70 ) ;
V_68 = ( T_1 ) V_70 . V_81 * V_82 + V_70 . V_83 ;
V_68 -= ( T_1 ) V_41 -> V_84 -> V_85 . V_81 * V_82
+ V_41 -> V_84 -> V_85 . V_83 ;
V_67 = F_35 ( V_68 ) ;
#if V_77 == 3
V_64 . V_86 = F_31 ( V_67 ) ;
#else
V_64 . V_86 = F_29 ( V_67 < ( unsigned long ) - 1l ?
( unsigned long ) V_67 : ( unsigned long ) - 1l ) ;
#endif
#if V_77 == 1 || V_77 == 2
{
T_3 V_87 = F_30 ( V_67 ) ;
V_64 . V_88 = V_87 >> 16 ;
V_64 . V_89 = ( V_90 ) V_87 ;
}
#endif
F_6 ( V_67 , V_91 ) ;
V_64 . V_92 = F_36 () - V_67 ;
V_64 . V_93 = F_37 ( V_3 -> V_75 -> V_94 , V_74 -> V_95 ) ;
V_64 . V_96 = F_38 ( V_3 -> V_75 -> V_94 , V_74 -> V_97 ) ;
#if V_77 == 2
V_64 . V_98 = V_91 ;
#endif
#if V_77 == 1 || V_77 == 2
V_64 . V_99 = V_64 . V_93 ;
V_64 . V_100 = V_64 . V_96 ;
#endif
#if V_77 == 3
V_64 . V_101 = F_39 ( V_41 , V_24 ) ;
F_40 () ;
V_64 . V_102 = F_39 ( F_41 ( V_41 -> V_103 ) , V_24 ) ;
F_42 () ;
#endif
F_43 ( & V_41 -> V_104 -> V_105 ) ;
V_72 = V_41 -> signal -> V_72 ;
V_64 . V_106 = V_72 ? F_44 ( F_45 ( V_72 ) ) : 0 ;
V_64 . V_107 = F_29 ( F_46 ( F_47 ( V_63 -> V_107 ) ) ) ;
V_64 . V_108 = F_29 ( F_46 ( F_47 ( V_63 -> V_108 ) ) ) ;
V_64 . V_109 = V_63 -> V_109 ;
V_64 . V_110 = F_29 ( V_63 -> V_110 ) ;
V_64 . V_111 = F_29 ( V_63 -> V_111 ) ;
V_64 . V_112 = F_29 ( V_63 -> V_112 ) ;
V_64 . V_113 = V_63 -> V_113 ;
F_48 ( & V_41 -> V_104 -> V_105 ) ;
V_64 . V_114 = F_29 ( 0 ) ;
V_64 . V_115 = F_29 ( V_64 . V_114 / 1024 ) ;
V_64 . V_116 = F_29 ( 0 ) ;
V_65 = F_49 () ;
F_50 ( V_117 ) ;
V_66 = V_41 -> signal -> V_118 [ V_119 ] . V_120 ;
V_41 -> signal -> V_118 [ V_119 ] . V_120 = V_121 ;
V_3 -> V_38 -> V_39 ( V_3 , ( char * ) & V_64 ,
sizeof( T_5 ) , & V_3 -> V_122 ) ;
V_41 -> signal -> V_118 [ V_119 ] . V_120 = V_66 ;
F_50 ( V_65 ) ;
V_13:
F_51 ( V_74 ) ;
}
void F_52 ( long V_123 , int V_124 )
{
struct V_62 * V_63 = & V_41 -> signal -> V_63 ;
T_7 V_125 , V_126 ;
unsigned long V_127 = 0 ;
if ( V_124 && V_41 -> V_128 ) {
struct V_129 * V_130 ;
F_53 ( & V_41 -> V_128 -> V_131 ) ;
V_130 = V_41 -> V_128 -> V_132 ;
while ( V_130 ) {
V_127 += V_130 -> V_133 - V_130 -> V_134 ;
V_130 = V_130 -> V_135 ;
}
F_54 ( & V_41 -> V_128 -> V_131 ) ;
}
F_43 ( & V_41 -> V_104 -> V_105 ) ;
if ( V_124 )
V_63 -> V_110 = V_127 / 1024 ;
if ( F_55 ( V_41 ) ) {
V_63 -> V_113 = V_123 ;
if ( V_41 -> V_136 & V_137 )
V_63 -> V_109 |= V_138 ;
}
if ( V_41 -> V_136 & V_139 )
V_63 -> V_109 |= V_140 ;
if ( V_41 -> V_136 & V_141 )
V_63 -> V_109 |= V_142 ;
if ( V_41 -> V_136 & V_143 )
V_63 -> V_109 |= V_144 ;
F_56 ( V_41 , & V_125 , & V_126 ) ;
V_63 -> V_107 += V_125 ;
V_63 -> V_108 += V_126 ;
V_63 -> V_111 += V_41 -> V_145 ;
V_63 -> V_112 += V_41 -> V_146 ;
F_48 ( & V_41 -> V_104 -> V_105 ) ;
}
static void F_57 ( struct V_23 * V_24 )
{
struct V_3 * V_3 = NULL ;
struct V_1 * V_2 ;
V_2 = V_24 -> V_42 ;
if ( ! V_2 || ! V_2 -> V_3 )
return;
F_2 ( & V_10 ) ;
V_3 = V_2 -> V_3 ;
if ( F_58 ( ! V_3 ) ) {
F_4 ( & V_10 ) ;
return;
}
F_59 ( V_3 ) ;
F_4 ( & V_10 ) ;
F_12 ( V_2 , V_24 , V_3 ) ;
F_60 ( V_3 ) ;
}
void F_61 ( void )
{
struct V_23 * V_24 ;
for ( V_24 = F_20 ( V_41 ) ; V_24 != NULL ; V_24 = V_24 -> V_147 )
F_57 ( V_24 ) ;
}
