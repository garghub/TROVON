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
if ( ! V_7 -> V_33 -> V_50 ) {
F_34 ( V_2 ) ;
F_38 ( V_7 , NULL ) ;
return - V_51 ;
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
static T_2 F_53 ( unsigned long V_52 )
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
static T_3 F_54 ( T_1 V_52 )
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
static T_4 F_55 ( T_1 V_52 )
{
unsigned exp = 190 ;
unsigned V_61 ;
if ( V_52 == 0 )
return 0 ;
while ( ( V_62 ) V_52 > 0 ) {
V_52 <<= 1 ;
exp -- ;
}
V_61 = ( T_4 ) ( V_52 >> 40 ) & 0x7fffffu ;
return V_61 | ( exp << 23 ) ;
}
static void F_56 ( T_5 * V_63 )
{
struct V_64 * V_65 = & V_40 -> signal -> V_65 ;
T_1 V_66 , V_67 ;
struct V_68 * V_69 ;
memset ( V_63 , 0 , sizeof( T_5 ) ) ;
V_63 -> V_70 = V_71 | V_72 ;
F_57 ( V_63 -> V_73 , V_40 -> V_74 , sizeof( V_63 -> V_73 ) ) ;
V_67 = F_58 () ;
V_67 -= V_40 -> V_75 -> V_76 ;
V_66 = F_59 ( V_67 ) ;
#if V_71 == 3
V_63 -> V_77 = F_55 ( V_66 ) ;
#else
V_63 -> V_77 = F_53 ( V_66 < ( unsigned long ) - 1l ?
( unsigned long ) V_66 : ( unsigned long ) - 1l ) ;
#endif
#if V_71 == 1 || V_71 == 2
{
T_3 V_78 = F_54 ( V_66 ) ;
V_63 -> V_79 = V_78 >> 16 ;
V_63 -> V_80 = ( V_81 ) V_78 ;
}
#endif
F_4 ( V_66 , V_82 ) ;
V_63 -> V_83 = F_60 () - V_66 ;
#if V_71 == 2
V_63 -> V_84 = V_82 ;
#endif
F_61 ( & V_40 -> V_85 -> V_86 ) ;
V_69 = V_40 -> signal -> V_69 ;
V_63 -> V_87 = V_69 ? F_62 ( F_63 ( V_69 ) ) : 0 ;
V_63 -> V_88 = F_53 ( F_64 ( F_65 ( V_65 -> V_88 ) ) ) ;
V_63 -> V_89 = F_53 ( F_64 ( F_65 ( V_65 -> V_89 ) ) ) ;
V_63 -> V_90 = V_65 -> V_90 ;
V_63 -> V_91 = F_53 ( V_65 -> V_91 ) ;
V_63 -> V_92 = F_53 ( V_65 -> V_92 ) ;
V_63 -> V_93 = F_53 ( V_65 -> V_93 ) ;
V_63 -> V_94 = V_65 -> V_94 ;
F_66 ( & V_40 -> V_85 -> V_86 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_5 V_63 ;
unsigned long V_95 ;
const struct V_96 * V_97 ;
struct V_7 * V_7 = V_2 -> V_7 ;
V_95 = V_40 -> signal -> V_98 [ V_99 ] . V_100 ;
V_40 -> signal -> V_98 [ V_99 ] . V_100 = V_101 ;
V_97 = F_67 ( V_7 -> V_102 ) ;
if ( ! F_1 ( V_2 ) )
goto V_6;
F_56 ( & V_63 ) ;
V_63 . V_103 = F_68 ( V_7 -> V_102 -> V_104 , V_97 -> V_105 ) ;
V_63 . V_106 = F_69 ( V_7 -> V_102 -> V_104 , V_97 -> V_107 ) ;
#if V_71 == 1 || V_71 == 2
V_63 . V_108 = V_63 . V_103 ;
V_63 . V_109 = V_63 . V_106 ;
#endif
#if V_71 == 3
{
struct V_24 * V_25 = V_2 -> V_25 ;
V_63 . V_110 = F_70 ( V_40 , V_25 ) ;
F_13 () ;
V_63 . V_111 = F_70 ( F_71 ( V_40 -> V_112 ) ,
V_25 ) ;
F_15 () ;
}
#endif
if ( F_72 ( V_7 ) ) {
T_6 V_113 = 0 ;
F_73 ( V_7 , ( char * ) & V_63 , sizeof( T_5 ) , & V_113 ) ;
F_74 ( V_7 ) ;
}
V_6:
V_40 -> signal -> V_98 [ V_99 ] . V_100 = V_95 ;
F_75 ( V_97 ) ;
}
void F_76 ( long V_114 , int V_115 )
{
struct V_64 * V_65 = & V_40 -> signal -> V_65 ;
T_7 V_116 , V_117 ;
unsigned long V_118 = 0 ;
if ( V_115 && V_40 -> V_119 ) {
struct V_120 * V_121 ;
F_77 ( & V_40 -> V_119 -> V_122 ) ;
V_121 = V_40 -> V_119 -> V_123 ;
while ( V_121 ) {
V_118 += V_121 -> V_124 - V_121 -> V_125 ;
V_121 = V_121 -> V_126 ;
}
F_78 ( & V_40 -> V_119 -> V_122 ) ;
}
F_61 ( & V_40 -> V_85 -> V_86 ) ;
if ( V_115 )
V_65 -> V_91 = V_118 / 1024 ;
if ( F_79 ( V_40 ) ) {
V_65 -> V_94 = V_114 ;
if ( V_40 -> V_127 & V_128 )
V_65 -> V_90 |= V_129 ;
}
if ( V_40 -> V_127 & V_130 )
V_65 -> V_90 |= V_131 ;
if ( V_40 -> V_127 & V_132 )
V_65 -> V_90 |= V_133 ;
if ( V_40 -> V_127 & V_134 )
V_65 -> V_90 |= V_135 ;
F_80 ( V_40 , & V_116 , & V_117 ) ;
V_65 -> V_88 += V_116 ;
V_65 -> V_89 += V_117 ;
V_65 -> V_92 += V_40 -> V_136 ;
V_65 -> V_93 += V_40 -> V_137 ;
F_66 ( & V_40 -> V_85 -> V_86 ) ;
}
static void F_81 ( struct V_24 * V_25 )
{
for ( ; V_25 ; V_25 = V_25 -> V_138 ) {
struct V_1 * V_2 = F_11 ( V_25 ) ;
if ( V_2 ) {
F_21 ( V_2 ) ;
F_19 ( & V_2 -> V_29 ) ;
F_6 ( V_2 ) ;
}
}
}
void F_82 ( void )
{
struct V_24 * V_25 ;
for ( V_25 = F_30 ( V_40 ) ; V_25 != NULL ; V_25 = V_25 -> V_138 ) {
if ( V_25 -> V_28 )
break;
}
if ( F_83 ( V_25 ) )
F_81 ( V_25 ) ;
}
