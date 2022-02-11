static T_1 F_1 ( enum V_1 V_2 )
{
struct V_3 * V_4 = & V_5 [ V_2 ] ;
T_1 V_6 = V_7 . V_8 [ V_4 -> V_9 * V_10 + V_4 -> V_11 ] ;
unsigned int V_12 = F_2 ( V_4 -> V_13 ) ;
return ( V_6 & V_4 -> V_13 ) >> V_12 ;
}
static T_2 F_3 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
char * V_18 )
{
struct V_19 * V_20 =
F_4 ( V_17 , struct V_19 , V_17 ) ;
enum V_1 V_2 = ( long ) V_20 -> V_21 ;
return snprintf ( V_18 , V_22 , L_1 , F_1 ( V_2 ) ) ;
}
static int T_3 F_5 ( void )
{
struct V_19 * V_23 ;
struct V_24 * * V_25 ;
T_4 V_26 ;
int V_27 ;
long V_28 ;
V_25 = NULL ;
V_27 = - V_29 ;
if ( ! F_6 ( & V_30 , V_31 ) )
goto V_32;
for ( V_28 = 0 ; V_28 < V_33 ; V_28 ++ ) {
F_7 ( 20 , V_28 ,
& V_7 . V_8 [ V_34 + V_28 * V_10 ] ,
& V_7 . V_8 [ V_35 + V_28 * V_10 ] ,
& V_7 . V_8 [ V_36 + V_28 * V_10 ] ,
& V_7 . V_8 [ V_37 + V_28 * V_10 ] ) ;
}
V_27 = - V_38 ;
V_26 = sizeof( struct V_24 * ) * ( F_8 ( V_5 ) + 1 ) ;
V_25 = F_9 ( V_26 , V_39 ) ;
if ( ! V_25 )
goto V_32;
V_26 = sizeof( struct V_19 ) * ( F_8 ( V_5 ) + 1 ) ;
V_23 = F_9 ( V_26 , V_39 ) ;
if ( ! V_23 )
goto V_32;
for ( V_28 = 0 ; V_28 < F_8 ( V_5 ) ; V_28 ++ ) {
struct V_19 * V_40 = V_23 + V_28 ;
V_40 -> V_17 . V_17 . V_41 = V_5 [ V_28 ] . V_41 ;
F_10 ( & V_40 -> V_17 . V_17 ) ;
V_40 -> V_17 . V_17 . V_42 = V_43 ;
V_40 -> V_17 . V_44 = F_3 ;
V_40 -> V_21 = ( void * ) V_28 ;
V_25 [ V_28 ] = & V_40 -> V_17 . V_17 ;
}
V_45 . V_25 = V_25 ;
return 0 ;
V_32:
F_11 ( V_25 ) ;
return V_27 ;
}
static bool F_12 ( struct V_46 * V_47 )
{
T_5 V_48 = V_47 -> V_17 . V_48 ;
T_5 V_49 , V_50 ;
if ( ( V_48 & V_51 ) != V_48 )
return false ;
if ( V_48 & V_52 ) {
if ( ! F_1 ( V_53 ) )
return false ;
V_49 = F_1 ( V_54 ) ;
V_50 = ( V_48 & V_55 ) >>
V_56 ;
if ( V_50 && ( ! ( V_49 & F_13 ( V_50 ) ) ) )
return false ;
V_49 = F_1 ( V_57 ) ;
V_50 = ( V_48 & V_58 ) >>
V_59 ;
if ( V_50 && ( ! ( V_49 & F_13 ( V_50 ) ) ) )
return false ;
}
if ( V_48 & V_60 ) {
if ( ! F_1 ( V_61 ) )
return false ;
V_49 = F_1 ( V_62 ) ;
if ( ! V_49 )
return false ;
V_50 = ( V_48 & V_63 ) >>
V_64 ;
if ( ! ( V_49 & F_13 ( V_50 ) ) )
return false ;
}
return true ;
}
static void F_14 ( struct V_46 * V_47 )
{
T_5 V_11 ;
if ( ! V_47 -> V_65 . V_66 ) {
V_47 -> V_65 . V_66 = 1 ;
F_15 ( V_67 , 0 ) ;
}
V_11 = V_68 | V_69 | V_70 ;
if ( ! V_47 -> V_17 . V_71 )
V_11 |= V_72 ;
if ( ! V_47 -> V_17 . V_73 )
V_11 |= V_74 ;
V_11 |= ( V_47 -> V_17 . V_48 & V_51 ) ;
F_15 ( V_75 , V_11 ) ;
}
static void F_16 ( bool V_76 )
{
T_5 V_77 ;
F_17 ( V_75 , V_77 ) ;
if ( V_76 )
V_77 |= V_70 ;
else
V_77 &= ~ V_70 ;
F_15 ( V_75 , V_77 ) ;
if ( ! V_76 )
F_18 () ;
}
static void F_19 ( void * V_18 , unsigned int V_78 ,
unsigned int V_79 )
{
T_5 V_11 ;
F_15 ( V_80 , F_20 ( V_18 ) ) ;
V_11 = 0x7f | ( ( T_5 ) V_78 << 7 ) | ( ( T_5 ) V_79 << 32 ) ;
F_15 ( V_81 , V_11 ) ;
}
static struct V_82 * F_21 ( int V_83 , T_6 V_84 )
{
int V_85 = F_22 ( V_83 ) ;
struct V_82 * V_82 ;
struct V_86 * V_87 ;
V_87 = F_23 ( V_85 , V_84 | V_88 , 0 ) ;
if ( ! V_87 )
return NULL ;
V_82 = F_24 ( V_87 ) ;
V_82 -> V_89 = 0 ;
V_82 -> V_90 = F_25 ( V_87 ) ;
if ( ! F_1 ( V_91 ) ) {
F_26 ( V_82 , 1 ) -> V_92 = V_82 -> V_90 >> V_93 ;
F_26 ( V_82 , 1 ) -> V_94 = 1 ;
}
return V_82 ;
}
static void F_27 ( struct V_82 * V_82 )
{
F_28 ( ( unsigned long ) V_82 ) ;
}
static void F_29 ( struct V_95 * V_18 , struct V_82 * V_82 )
{
struct V_82 * V_89 = V_18 -> V_89 ;
F_30 ( & V_82 -> V_96 , & V_18 -> V_97 ) ;
if ( ! V_18 -> V_98 ) {
V_18 -> V_98 = V_18 -> V_89 = V_18 -> V_99 = V_82 ;
return;
}
V_82 -> V_100 = V_89 -> V_100 + V_89 -> V_26 ;
V_18 -> V_89 = V_82 ;
if ( ! F_1 ( V_91 ) )
return;
F_31 ( V_89 -> V_89 != V_101 - 1 ) ;
F_26 ( V_89 , - 1 ) -> V_92 = V_82 -> V_90 >> V_93 ;
F_26 ( V_89 , - 1 ) -> V_94 = 1 ;
}
static bool F_32 ( struct V_82 * V_82 )
{
if ( ! F_1 ( V_91 ) )
return ! ! V_82 -> V_89 ;
return V_82 -> V_89 == V_101 - 1 ;
}
static int F_33 ( struct V_95 * V_18 , T_6 V_84 )
{
struct V_82 * V_82 = V_18 -> V_89 ;
int V_102 = 0 ;
struct V_86 * V_87 ;
V_87 = F_34 ( V_18 -> V_103 [ V_18 -> V_104 ] ) ;
if ( F_35 ( V_87 ) )
V_102 = F_36 ( V_87 ) ;
if ( F_32 ( V_82 ) ) {
V_82 = F_21 ( V_18 -> V_83 , V_84 ) ;
if ( ! V_82 )
return - V_38 ;
F_29 ( V_18 , V_82 ) ;
}
F_26 ( V_82 , - 1 ) -> V_92 = F_25 ( V_87 ) >> V_93 ;
F_26 ( V_82 , - 1 ) -> V_26 = V_102 ;
if ( ! V_18 -> V_105 && ! F_1 ( V_91 ) ) {
F_26 ( V_82 , - 1 ) -> V_106 = 1 ;
F_26 ( V_82 , - 1 ) -> V_107 = 1 ;
}
V_82 -> V_89 ++ ;
V_82 -> V_26 += F_37 ( V_102 ) ;
V_18 -> V_104 += 1ul << V_102 ;
return 0 ;
}
static void F_38 ( struct V_95 * V_18 )
{
struct V_82 * V_82 ;
F_39 (topa, &buf->tables, list) {
int V_28 ;
F_40 ( L_2 , V_82 -> V_108 ,
V_82 -> V_90 , V_82 -> V_100 , V_82 -> V_26 ) ;
for ( V_28 = 0 ; V_28 < V_101 ; V_28 ++ ) {
F_40 ( L_3 ,
& V_82 -> V_108 [ V_28 ] ,
( unsigned long ) V_82 -> V_108 [ V_28 ] . V_92 << V_93 ,
F_37 ( V_82 -> V_108 [ V_28 ] . V_26 ) ,
V_82 -> V_108 [ V_28 ] . V_94 ? 'E' : ' ' ,
V_82 -> V_108 [ V_28 ] . V_106 ? 'I' : ' ' ,
V_82 -> V_108 [ V_28 ] . V_107 ? 'S' : ' ' ,
* ( T_5 * ) & V_82 -> V_108 [ V_28 ] ) ;
if ( ( F_1 ( V_91 ) &&
V_82 -> V_108 [ V_28 ] . V_107 ) ||
V_82 -> V_108 [ V_28 ] . V_94 )
break;
}
}
}
static void F_41 ( struct V_95 * V_18 )
{
V_18 -> V_79 = 0 ;
V_18 -> V_109 ++ ;
if ( V_18 -> V_109 == V_18 -> V_99 -> V_89 ) {
if ( V_18 -> V_99 == V_18 -> V_89 )
V_18 -> V_99 = V_18 -> V_98 ;
else
V_18 -> V_99 = F_42 ( V_18 -> V_99 -> V_96 . V_110 , struct V_82 ,
V_96 ) ;
V_18 -> V_109 = 0 ;
}
}
static void F_43 ( struct V_111 * V_111 )
{
struct V_95 * V_18 = F_44 ( & V_111 -> V_112 ) ;
T_5 V_78 , V_92 , V_113 ;
V_92 = V_18 -> V_99 -> V_100 + V_18 -> V_79 ;
for ( V_78 = 0 ; V_78 < V_18 -> V_109 ; V_78 ++ )
V_92 += F_37 ( V_18 -> V_99 -> V_108 [ V_78 ] . V_26 ) ;
if ( V_18 -> V_105 ) {
F_45 ( & V_18 -> V_114 , V_92 ) ;
} else {
V_113 = ( F_46 ( & V_18 -> V_115 , V_92 ) &
( ( V_18 -> V_104 << V_116 ) - 1 ) ) ;
if ( V_92 < V_113 )
V_92 += V_18 -> V_104 << V_116 ;
F_47 ( V_92 - V_113 , & V_18 -> V_114 ) ;
}
}
static void * F_48 ( struct V_95 * V_18 )
{
return F_49 ( V_18 -> V_99 -> V_108 [ V_18 -> V_109 ] . V_92 << V_93 ) ;
}
static T_4 F_50 ( struct V_95 * V_18 )
{
return F_37 ( V_18 -> V_99 -> V_108 [ V_18 -> V_109 ] . V_26 ) ;
}
static void F_51 ( struct V_111 * V_111 )
{
struct V_95 * V_18 = F_44 ( & V_111 -> V_112 ) ;
int V_117 = 0 ;
T_5 V_118 ;
F_17 ( V_67 , V_118 ) ;
if ( V_118 & V_119 ) {
F_52 ( L_4 ) ;
F_38 ( V_18 ) ;
V_118 &= ~ V_119 ;
}
if ( V_118 & V_120 ) {
V_118 &= ~ V_120 ;
if ( ! F_1 ( V_91 ) ||
V_18 -> V_79 == F_37 ( F_26 ( V_18 -> V_99 , V_18 -> V_109 ) -> V_26 ) ) {
F_53 ( & V_18 -> V_121 ) ;
V_117 ++ ;
}
}
if ( ! F_1 ( V_91 ) && ! V_18 -> V_105 &&
F_50 ( V_18 ) - V_18 -> V_79 <= V_122 ) {
void * V_115 = F_48 ( V_18 ) ;
memset ( V_115 + V_18 -> V_79 , 0 ,
F_50 ( V_18 ) -
V_18 -> V_79 ) ;
V_117 ++ ;
}
if ( V_117 )
F_41 ( V_18 ) ;
F_15 ( V_67 , V_118 ) ;
}
static void F_54 ( struct V_95 * V_18 )
{
T_5 V_100 , V_123 ;
F_17 ( V_80 , V_123 ) ;
V_18 -> V_99 = F_49 ( V_123 ) ;
F_17 ( V_81 , V_100 ) ;
V_18 -> V_79 = V_100 >> 32 ;
V_18 -> V_109 = ( V_100 & 0xffffff80 ) >> 7 ;
}
static unsigned int F_55 ( struct V_95 * V_18 , unsigned int V_124 )
{
struct V_125 * V_126 = V_18 -> V_127 [ V_124 ] ;
if ( V_18 -> V_98 == V_18 -> V_89 && V_18 -> V_98 -> V_89 == 1 )
return V_124 ;
do {
V_124 ++ ;
V_124 &= V_18 -> V_104 - 1 ;
} while ( V_18 -> V_127 [ V_124 ] == V_126 );
return V_124 ;
}
static int F_56 ( struct V_95 * V_18 ,
struct V_128 * V_112 )
{
unsigned long V_115 = F_57 ( & V_18 -> V_115 ) ;
unsigned long V_129 , V_130 , V_131 ;
if ( V_18 -> V_79 + V_112 -> V_26 + 1 <
F_37 ( F_26 ( V_18 -> V_99 , V_18 -> V_109 ) -> V_26 ) )
return - V_132 ;
if ( ! F_1 ( V_91 ) )
return 0 ;
V_18 -> V_127 [ V_18 -> V_133 ] -> V_107 = 0 ;
V_18 -> V_127 [ V_18 -> V_134 ] -> V_106 = 0 ;
V_130 = V_112 -> V_26 >> V_116 ;
if ( ! F_58 ( V_115 + V_112 -> V_26 + 1 ) )
V_130 ++ ;
V_129 = ( V_115 >> V_116 ) + V_130 ;
V_129 &= V_18 -> V_104 - 1 ;
V_18 -> V_133 = V_129 ;
V_131 = V_112 -> V_131 >> V_116 ;
V_129 = ( V_115 >> V_116 ) + V_130 - 1 ;
if ( V_129 > V_131 )
V_129 = V_131 ;
V_129 &= V_18 -> V_104 - 1 ;
V_18 -> V_134 = V_129 ;
V_18 -> V_127 [ V_18 -> V_133 ] -> V_107 = 1 ;
V_18 -> V_127 [ V_18 -> V_134 ] -> V_106 = 1 ;
return 0 ;
}
static void F_59 ( struct V_95 * V_18 )
{
struct V_82 * V_99 = V_18 -> V_98 , * V_135 = V_18 -> V_89 ;
struct V_125 * V_136 = F_26 ( V_99 , 0 ) ,
* V_137 = F_26 ( V_135 , V_135 -> V_89 - 1 ) ;
int V_124 = 0 , V_129 = 0 ;
while ( V_124 < V_18 -> V_104 ) {
int V_138 ;
for ( V_138 = 0 ; V_138 < 1 << V_136 -> V_26 ; V_138 ++ , V_124 ++ )
V_18 -> V_127 [ V_124 ] = V_137 ;
V_137 = V_136 ;
if ( V_129 == V_99 -> V_89 - 1 ) {
V_129 = 0 ;
V_99 = F_42 ( V_99 -> V_96 . V_110 , struct V_82 , V_96 ) ;
} else {
V_129 ++ ;
}
V_136 = F_26 ( V_99 , V_129 ) ;
}
}
static void F_60 ( struct V_95 * V_18 , unsigned long V_115 )
{
int V_124 ;
if ( V_18 -> V_105 )
V_115 &= ( V_18 -> V_104 << V_116 ) - 1 ;
V_124 = ( V_115 >> V_116 ) & ( V_18 -> V_104 - 1 ) ;
V_124 = F_55 ( V_18 , V_124 ) ;
V_18 -> V_99 = (struct V_82 * ) ( ( unsigned long ) V_18 -> V_127 [ V_124 ] & V_139 ) ;
V_18 -> V_109 = ( ( unsigned long ) V_18 -> V_127 [ V_124 ] -
( unsigned long ) V_18 -> V_99 ) / sizeof( struct V_125 ) ;
V_18 -> V_79 = V_115 & ( F_37 ( V_18 -> V_99 -> V_108 [ V_18 -> V_109 ] . V_26 ) - 1 ) ;
F_61 ( & V_18 -> V_115 , V_115 ) ;
F_45 ( & V_18 -> V_114 , 0 ) ;
}
static void F_62 ( struct V_95 * V_18 )
{
struct V_82 * V_82 , * V_140 ;
F_63 (topa, iter, &buf->tables, list) {
F_27 ( V_82 ) ;
}
}
static int F_64 ( struct V_95 * V_18 , unsigned long V_104 ,
T_6 V_84 )
{
struct V_82 * V_82 ;
int V_141 ;
V_82 = F_21 ( V_18 -> V_83 , V_84 ) ;
if ( ! V_82 )
return - V_38 ;
F_29 ( V_18 , V_82 ) ;
while ( V_18 -> V_104 < V_104 ) {
V_141 = F_33 ( V_18 , V_84 ) ;
if ( V_141 ) {
F_62 ( V_18 ) ;
return - V_38 ;
}
}
F_59 ( V_18 ) ;
if ( F_1 ( V_91 ) ) {
F_26 ( V_18 -> V_89 , - 1 ) -> V_92 = V_18 -> V_98 -> V_90 >> V_93 ;
F_26 ( V_18 -> V_89 , - 1 ) -> V_94 = 1 ;
}
F_38 ( V_18 ) ;
return 0 ;
}
static void *
F_65 ( int V_83 , void * * V_142 , int V_104 , bool V_105 )
{
struct V_95 * V_18 ;
int V_85 , V_27 ;
if ( ! V_104 )
return NULL ;
if ( V_83 == - 1 )
V_83 = F_66 () ;
V_85 = F_22 ( V_83 ) ;
V_18 = F_67 ( F_68 ( struct V_95 , V_127 [ V_104 ] ) ,
V_39 , V_85 ) ;
if ( ! V_18 )
return NULL ;
V_18 -> V_83 = V_83 ;
V_18 -> V_105 = V_105 ;
V_18 -> V_103 = V_142 ;
F_69 ( & V_18 -> V_97 ) ;
V_27 = F_64 ( V_18 , V_104 , V_39 ) ;
if ( V_27 ) {
F_11 ( V_18 ) ;
return NULL ;
}
return V_18 ;
}
static void F_70 ( void * V_143 )
{
struct V_95 * V_18 = V_143 ;
F_62 ( V_18 ) ;
F_11 ( V_18 ) ;
}
static bool F_71 ( struct V_95 * V_18 , struct V_111 * V_111 )
{
if ( V_18 -> V_105 )
return false ;
if ( F_72 ( & V_18 -> V_114 ) >= V_111 -> V_112 . V_26 )
return true ;
return false ;
}
void F_73 ( void )
{
struct V_111 * V_111 = F_74 ( & V_144 ) ;
struct V_95 * V_18 ;
struct V_46 * V_47 = V_111 -> V_112 . V_47 ;
if ( ! F_75 ( V_111 -> V_145 ) )
return;
F_16 ( false ) ;
if ( ! V_47 )
return;
V_18 = F_44 ( & V_111 -> V_112 ) ;
if ( ! V_18 )
return;
F_54 ( V_18 ) ;
F_51 ( V_111 ) ;
F_43 ( V_111 ) ;
F_76 ( & V_111 -> V_112 , F_77 ( & V_18 -> V_114 , 0 ) ,
F_77 ( & V_18 -> V_121 , 0 ) ) ;
if ( ! V_47 -> V_65 . V_146 ) {
int V_27 ;
V_18 = F_78 ( & V_111 -> V_112 , V_47 ) ;
if ( ! V_18 ) {
V_47 -> V_65 . V_146 = V_147 ;
return;
}
F_60 ( V_18 , V_111 -> V_112 . V_115 ) ;
V_27 = F_56 ( V_18 , & V_111 -> V_112 ) ;
if ( V_27 ) {
F_76 ( & V_111 -> V_112 , 0 , true ) ;
return;
}
F_19 ( V_18 -> V_99 -> V_108 , V_18 -> V_109 ,
V_18 -> V_79 ) ;
F_14 ( V_47 ) ;
}
}
static void F_79 ( struct V_46 * V_47 , int V_42 )
{
struct V_111 * V_111 = F_74 ( & V_144 ) ;
struct V_95 * V_18 = F_44 ( & V_111 -> V_112 ) ;
if ( ! V_18 || F_71 ( V_18 , V_111 ) ) {
V_47 -> V_65 . V_146 = V_147 ;
return;
}
F_75 ( V_111 -> V_145 ) = 1 ;
V_47 -> V_65 . V_146 = 0 ;
F_19 ( V_18 -> V_99 -> V_108 , V_18 -> V_109 ,
V_18 -> V_79 ) ;
F_14 ( V_47 ) ;
}
static void F_80 ( struct V_46 * V_47 , int V_42 )
{
struct V_111 * V_111 = F_74 ( & V_144 ) ;
F_75 ( V_111 -> V_145 ) = 0 ;
F_16 ( false ) ;
if ( V_47 -> V_65 . V_146 == V_147 )
return;
V_47 -> V_65 . V_146 = V_147 ;
if ( V_42 & V_148 ) {
struct V_95 * V_18 = F_44 ( & V_111 -> V_112 ) ;
if ( ! V_18 )
return;
if ( F_81 ( V_111 -> V_112 . V_47 != V_47 ) )
return;
F_54 ( V_18 ) ;
F_51 ( V_111 ) ;
F_43 ( V_111 ) ;
}
}
static void F_82 ( struct V_46 * V_47 , int V_42 )
{
struct V_111 * V_111 = F_74 ( & V_144 ) ;
struct V_95 * V_18 ;
F_80 ( V_47 , V_148 ) ;
V_18 = F_44 ( & V_111 -> V_112 ) ;
if ( V_18 ) {
if ( V_18 -> V_105 )
V_111 -> V_112 . V_115 =
F_77 ( & V_18 -> V_114 ,
V_18 -> V_104 << V_116 ) ;
F_76 ( & V_111 -> V_112 , F_77 ( & V_18 -> V_114 , 0 ) ,
F_77 ( & V_18 -> V_121 , 0 ) ) ;
}
}
static int F_83 ( struct V_46 * V_47 , int V_42 )
{
struct V_95 * V_18 ;
struct V_111 * V_111 = F_74 ( & V_144 ) ;
struct V_149 * V_150 = & V_47 -> V_65 ;
int V_27 = - V_151 ;
if ( V_111 -> V_112 . V_47 )
goto V_32;
V_18 = F_78 ( & V_111 -> V_112 , V_47 ) ;
V_27 = - V_132 ;
if ( ! V_18 )
goto V_152;
F_60 ( V_18 , V_111 -> V_112 . V_115 ) ;
if ( ! V_18 -> V_105 ) {
V_27 = F_56 ( V_18 , & V_111 -> V_112 ) ;
if ( V_27 )
goto V_153;
}
if ( V_42 & V_154 ) {
F_79 ( V_47 , 0 ) ;
V_27 = - V_151 ;
if ( V_150 -> V_146 == V_147 )
goto V_153;
} else {
V_150 -> V_146 = V_147 ;
}
return 0 ;
V_153:
F_76 ( & V_111 -> V_112 , 0 , true ) ;
V_152:
V_150 -> V_146 = V_147 ;
V_32:
return V_27 ;
}
static void F_84 ( struct V_46 * V_47 )
{
}
static void F_85 ( struct V_46 * V_47 )
{
F_86 ( V_155 ) ;
}
static int F_87 ( struct V_46 * V_47 )
{
if ( V_47 -> V_17 . type != V_7 . V_156 . type )
return - V_157 ;
if ( ! F_12 ( V_47 ) )
return - V_132 ;
if ( F_88 ( V_155 ) )
return - V_151 ;
V_47 -> V_158 = F_85 ;
return 0 ;
}
static T_3 int F_89 ( void )
{
int V_27 , V_83 , V_159 = 0 ;
F_90 ( sizeof( struct V_82 ) > V_22 ) ;
F_91 () ;
F_92 (cpu) {
T_5 V_77 ;
V_27 = F_93 ( V_83 , V_75 , & V_77 ) ;
if ( ! V_27 && ( V_77 & V_70 ) )
V_159 ++ ;
}
F_94 () ;
if ( V_159 ) {
F_88 ( V_155 ) ;
F_95 ( L_5 ) ;
return - V_151 ;
}
V_27 = F_5 () ;
if ( V_27 )
return V_27 ;
if ( ! F_1 ( V_160 ) ) {
F_95 ( L_6 ) ;
return - V_29 ;
}
if ( ! F_1 ( V_91 ) )
V_7 . V_156 . V_161 =
V_162 | V_163 ;
V_7 . V_156 . V_161 |= V_164 | V_165 ;
V_7 . V_156 . V_166 = V_167 ;
V_7 . V_156 . V_168 = V_169 ;
V_7 . V_156 . V_170 = F_87 ;
V_7 . V_156 . V_171 = F_83 ;
V_7 . V_156 . V_172 = F_82 ;
V_7 . V_156 . V_76 = F_79 ;
V_7 . V_156 . V_107 = F_80 ;
V_7 . V_156 . V_173 = F_84 ;
V_7 . V_156 . V_174 = F_65 ;
V_7 . V_156 . V_175 = F_70 ;
V_27 = F_96 ( & V_7 . V_156 , L_7 , - 1 ) ;
return V_27 ;
}
