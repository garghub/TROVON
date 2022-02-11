static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( F_2 ( V_2 -> V_5 ) )
goto V_6;
if ( F_3 ( & V_2 -> V_7 -> V_8 , & V_4 ) )
goto V_6;
if ( V_2 -> V_9 ) {
T_1 V_10 = V_4 . V_11 * V_12 ;
F_4 ( V_10 , 100 ) ;
if ( V_4 . V_13 <= V_10 ) {
V_2 -> V_9 = 0 ;
F_5 ( L_1 ) ;
}
} else {
T_1 V_14 = V_4 . V_11 * V_15 ;
F_4 ( V_14 , 100 ) ;
if ( V_4 . V_13 >= V_14 ) {
V_2 -> V_9 = 1 ;
F_5 ( L_2 ) ;
}
}
V_2 -> V_5 = V_16 + V_17 * V_18 ;
V_6:
return V_2 -> V_9 ;
}
static void F_6 ( struct V_1 * V_19 )
{
if ( F_7 ( & V_19 -> V_20 ) )
F_8 ( V_19 , V_21 ) ;
}
static inline struct V_1 * F_9 ( struct V_22 * V_19 )
{
return V_19 ? F_10 ( V_19 , struct V_1 , V_23 ) : NULL ;
}
static struct V_1 * F_11 ( struct V_24 * V_25 )
{
struct V_1 * V_26 ;
V_27:
F_12 () ;
F_13 () ;
V_26 = F_9 ( F_14 ( V_25 -> V_28 ) ) ;
if ( ! V_26 ) {
F_15 () ;
return NULL ;
}
if ( ! F_16 ( & V_26 -> V_20 ) ) {
F_15 () ;
F_17 () ;
goto V_27;
}
F_15 () ;
F_18 ( & V_26 -> V_29 ) ;
if ( V_26 != F_9 ( F_14 ( V_25 -> V_28 ) ) ) {
F_19 ( & V_26 -> V_29 ) ;
F_6 ( V_26 ) ;
goto V_27;
}
return V_26 ;
}
static void F_20 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_9 ( V_23 ) ;
F_18 ( & V_2 -> V_29 ) ;
F_21 ( V_2 ) ;
F_22 ( & V_2 -> V_30 ) ;
F_23 ( & V_2 -> V_31 ) ;
F_24 ( & V_2 -> V_25 -> V_28 , V_23 , NULL ) ;
F_19 ( & V_2 -> V_29 ) ;
F_25 ( V_23 ) ;
F_6 ( V_2 ) ;
}
static void F_26 ( struct V_32 * V_30 )
{
struct V_1 * V_2 = F_10 ( V_30 , struct V_1 , V_30 ) ;
struct V_7 * V_7 = V_2 -> V_7 ;
if ( V_7 -> V_33 -> V_34 )
V_7 -> V_33 -> V_34 ( V_7 , NULL ) ;
F_27 ( V_7 ) ;
F_28 ( & V_2 -> V_31 ) ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_7 * V_7 ;
struct V_37 * V_38 , * V_39 ;
struct V_24 * V_25 = F_30 ( V_40 ) ;
struct V_1 * V_2 ;
struct V_22 * V_41 ;
int V_42 ;
V_2 = F_31 ( sizeof( struct V_1 ) , V_43 ) ;
if ( ! V_2 )
return - V_44 ;
V_7 = F_32 ( V_36 , V_45 | V_46 | V_47 , 0 ) ;
if ( F_33 ( V_7 ) ) {
F_34 ( V_2 ) ;
return F_35 ( V_7 ) ;
}
if ( ! F_36 ( F_37 ( V_7 ) -> V_48 ) ) {
F_34 ( V_2 ) ;
F_38 ( V_7 , NULL ) ;
return - V_49 ;
}
if ( ! ( V_7 -> V_50 & V_51 ) ) {
F_34 ( V_2 ) ;
F_38 ( V_7 , NULL ) ;
return - V_52 ;
}
V_39 = F_39 ( & V_7 -> V_8 ) ;
if ( F_33 ( V_39 ) ) {
F_34 ( V_2 ) ;
F_38 ( V_7 , NULL ) ;
return F_35 ( V_39 ) ;
}
V_42 = F_40 ( V_39 ) ;
if ( V_42 ) {
F_41 ( V_39 ) ;
F_34 ( V_2 ) ;
F_38 ( V_7 , NULL ) ;
return V_42 ;
}
V_38 = V_7 -> V_8 . V_38 ;
V_7 -> V_8 . V_38 = V_39 ;
F_42 ( & V_2 -> V_20 , 1 ) ;
F_43 ( & V_2 -> V_23 , F_20 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_5 = V_16 ;
V_2 -> V_25 = V_25 ;
F_44 ( & V_2 -> V_29 ) ;
F_45 ( & V_2 -> V_30 , F_26 ) ;
F_46 ( & V_2 -> V_31 ) ;
F_47 ( & V_2 -> V_29 , 1 ) ;
F_48 ( & V_2 -> V_23 , V_38 ) ;
F_13 () ;
V_41 = F_49 ( & V_25 -> V_28 , & V_2 -> V_23 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_50 ( V_41 ) ;
F_51 ( V_38 ) ;
F_41 ( V_38 ) ;
return 0 ;
}
void F_52 ( struct V_24 * V_25 )
{
F_13 () ;
F_50 ( V_25 -> V_28 ) ;
}
static T_2 F_53 ( unsigned long V_53 )
{
int exp , V_54 ;
exp = V_54 = 0 ;
while ( V_53 > V_55 ) {
V_54 = V_53 & ( 1 << ( V_56 - 1 ) ) ;
V_53 >>= V_56 ;
exp ++ ;
}
if ( V_54 && ( ++ V_53 > V_55 ) ) {
V_53 >>= V_56 ;
exp ++ ;
}
exp <<= V_57 ;
exp += V_53 ;
return exp ;
}
static T_3 F_54 ( T_1 V_53 )
{
int exp , V_54 ;
exp = ( V_53 > ( V_58 >> 1 ) ) ;
V_54 = 0 ;
while ( V_53 > V_58 ) {
V_54 = V_53 & 1 ;
V_53 >>= 1 ;
exp ++ ;
}
if ( V_54 && ( ++ V_53 > V_58 ) ) {
V_53 >>= 1 ;
exp ++ ;
}
if ( exp > V_59 ) {
return ( 1ul << ( V_60 + V_61 - 1 ) ) - 1 ;
} else {
return ( V_53 & ( V_58 >> 1 ) ) | ( exp << ( V_60 - 1 ) ) ;
}
}
static T_4 F_55 ( T_1 V_53 )
{
unsigned exp = 190 ;
unsigned V_62 ;
if ( V_53 == 0 )
return 0 ;
while ( ( V_63 ) V_53 > 0 ) {
V_53 <<= 1 ;
exp -- ;
}
V_62 = ( T_4 ) ( V_53 >> 40 ) & 0x7fffffu ;
return V_62 | ( exp << 23 ) ;
}
static void F_56 ( T_5 * V_64 )
{
struct V_65 * V_66 = & V_40 -> signal -> V_66 ;
T_1 V_67 , V_68 ;
struct V_69 * V_70 ;
memset ( V_64 , 0 , sizeof( T_5 ) ) ;
V_64 -> V_71 = V_72 | V_73 ;
F_57 ( V_64 -> V_74 , V_40 -> V_75 , sizeof( V_64 -> V_74 ) ) ;
V_68 = F_58 () ;
V_68 -= V_40 -> V_76 -> V_77 ;
V_67 = F_59 ( V_68 ) ;
#if V_72 == 3
V_64 -> V_78 = F_55 ( V_67 ) ;
#else
V_64 -> V_78 = F_53 ( V_67 < ( unsigned long ) - 1l ?
( unsigned long ) V_67 : ( unsigned long ) - 1l ) ;
#endif
#if V_72 == 1 || V_72 == 2
{
T_3 V_79 = F_54 ( V_67 ) ;
V_64 -> V_80 = V_79 >> 16 ;
V_64 -> V_81 = ( V_82 ) V_79 ;
}
#endif
F_4 ( V_67 , V_83 ) ;
V_64 -> V_84 = F_60 () - V_67 ;
#if V_72 == 2
V_64 -> V_85 = V_83 ;
#endif
F_61 ( & V_40 -> V_86 -> V_87 ) ;
V_70 = V_40 -> signal -> V_70 ;
V_64 -> V_88 = V_70 ? F_62 ( F_63 ( V_70 ) ) : 0 ;
V_64 -> V_89 = F_53 ( F_59 ( V_66 -> V_89 ) ) ;
V_64 -> V_90 = F_53 ( F_59 ( V_66 -> V_90 ) ) ;
V_64 -> V_91 = V_66 -> V_91 ;
V_64 -> V_92 = F_53 ( V_66 -> V_92 ) ;
V_64 -> V_93 = F_53 ( V_66 -> V_93 ) ;
V_64 -> V_94 = F_53 ( V_66 -> V_94 ) ;
V_64 -> V_95 = V_66 -> V_95 ;
F_64 ( & V_40 -> V_86 -> V_87 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_5 V_64 ;
unsigned long V_96 ;
const struct V_97 * V_98 ;
struct V_7 * V_7 = V_2 -> V_7 ;
V_96 = V_40 -> signal -> V_99 [ V_100 ] . V_101 ;
V_40 -> signal -> V_99 [ V_100 ] . V_101 = V_102 ;
V_98 = F_65 ( V_7 -> V_103 ) ;
if ( ! F_1 ( V_2 ) )
goto V_6;
F_56 ( & V_64 ) ;
V_64 . V_104 = F_66 ( V_7 -> V_103 -> V_105 , V_98 -> V_106 ) ;
V_64 . V_107 = F_67 ( V_7 -> V_103 -> V_105 , V_98 -> V_108 ) ;
#if V_72 == 1 || V_72 == 2
V_64 . V_109 = V_64 . V_104 ;
V_64 . V_110 = V_64 . V_107 ;
#endif
#if V_72 == 3
{
struct V_24 * V_25 = V_2 -> V_25 ;
V_64 . V_111 = F_68 ( V_40 , V_25 ) ;
F_13 () ;
V_64 . V_112 = F_68 ( F_69 ( V_40 -> V_113 ) ,
V_25 ) ;
F_15 () ;
}
#endif
if ( F_70 ( V_7 ) ) {
T_6 V_114 = 0 ;
F_71 ( V_7 , ( char * ) & V_64 , sizeof( T_5 ) , & V_114 ) ;
F_72 ( V_7 ) ;
}
V_6:
V_40 -> signal -> V_99 [ V_100 ] . V_101 = V_96 ;
F_73 ( V_98 ) ;
}
void F_74 ( long V_115 , int V_116 )
{
struct V_65 * V_66 = & V_40 -> signal -> V_66 ;
T_1 V_117 , V_118 ;
unsigned long V_119 = 0 ;
if ( V_116 && V_40 -> V_120 ) {
struct V_121 * V_122 ;
F_75 ( & V_40 -> V_120 -> V_123 ) ;
V_122 = V_40 -> V_120 -> V_124 ;
while ( V_122 ) {
V_119 += V_122 -> V_125 - V_122 -> V_126 ;
V_122 = V_122 -> V_127 ;
}
F_76 ( & V_40 -> V_120 -> V_123 ) ;
}
F_61 ( & V_40 -> V_86 -> V_87 ) ;
if ( V_116 )
V_66 -> V_92 = V_119 / 1024 ;
if ( F_77 ( V_40 ) ) {
V_66 -> V_95 = V_115 ;
if ( V_40 -> V_128 & V_129 )
V_66 -> V_91 |= V_130 ;
}
if ( V_40 -> V_128 & V_131 )
V_66 -> V_91 |= V_132 ;
if ( V_40 -> V_128 & V_133 )
V_66 -> V_91 |= V_134 ;
if ( V_40 -> V_128 & V_135 )
V_66 -> V_91 |= V_136 ;
F_78 ( V_40 , & V_117 , & V_118 ) ;
V_66 -> V_89 += V_117 ;
V_66 -> V_90 += V_118 ;
V_66 -> V_93 += V_40 -> V_137 ;
V_66 -> V_94 += V_40 -> V_138 ;
F_64 ( & V_40 -> V_86 -> V_87 ) ;
}
static void F_79 ( struct V_24 * V_25 )
{
for ( ; V_25 ; V_25 = V_25 -> V_139 ) {
struct V_1 * V_2 = F_11 ( V_25 ) ;
if ( V_2 ) {
F_21 ( V_2 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_6 ( V_2 ) ;
}
}
}
void F_80 ( void )
{
struct V_24 * V_25 ;
for ( V_25 = F_30 ( V_40 ) ; V_25 != NULL ; V_25 = V_25 -> V_139 ) {
if ( V_25 -> V_28 )
break;
}
if ( F_81 ( V_25 ) )
F_79 ( V_25 ) ;
}
