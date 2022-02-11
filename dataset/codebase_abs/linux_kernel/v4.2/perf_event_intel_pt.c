static T_1 F_1 ( enum V_1 V_2 )
{
struct V_3 * V_4 = & V_5 [ V_2 ] ;
T_1 V_6 = V_7 . V_8 [ V_4 -> V_9 * 4 + V_4 -> V_10 ] ;
unsigned int V_11 = F_2 ( V_4 -> V_12 ) ;
return ( V_6 & V_4 -> V_12 ) >> V_11 ;
}
static T_2 F_3 ( struct V_13 * V_14 ,
struct V_15 * V_16 ,
char * V_17 )
{
struct V_18 * V_19 =
F_4 ( V_16 , struct V_18 , V_16 ) ;
enum V_1 V_2 = ( long ) V_19 -> V_20 ;
return snprintf ( V_17 , V_21 , L_1 , F_1 ( V_2 ) ) ;
}
static int T_3 F_5 ( void )
{
struct V_18 * V_22 ;
struct V_23 * * V_24 ;
T_4 V_25 ;
int V_26 ;
long V_27 ;
V_24 = NULL ;
V_26 = - V_28 ;
if ( ! F_6 ( & V_29 , V_30 ) )
goto V_31;
for ( V_27 = 0 ; V_27 < V_32 ; V_27 ++ ) {
F_7 ( 20 , V_27 ,
& V_7 . V_8 [ V_33 + V_27 * 4 ] ,
& V_7 . V_8 [ V_34 + V_27 * 4 ] ,
& V_7 . V_8 [ V_35 + V_27 * 4 ] ,
& V_7 . V_8 [ V_36 + V_27 * 4 ] ) ;
}
V_26 = - V_37 ;
V_25 = sizeof( struct V_23 * ) * ( F_8 ( V_5 ) + 1 ) ;
V_24 = F_9 ( V_25 , V_38 ) ;
if ( ! V_24 )
goto V_31;
V_25 = sizeof( struct V_18 ) * ( F_8 ( V_5 ) + 1 ) ;
V_22 = F_9 ( V_25 , V_38 ) ;
if ( ! V_22 )
goto V_31;
for ( V_27 = 0 ; V_27 < F_8 ( V_5 ) ; V_27 ++ ) {
struct V_18 * V_39 = V_22 + V_27 ;
V_39 -> V_16 . V_16 . V_40 = V_5 [ V_27 ] . V_40 ;
F_10 ( & V_39 -> V_16 . V_16 ) ;
V_39 -> V_16 . V_16 . V_41 = V_42 ;
V_39 -> V_16 . V_43 = F_3 ;
V_39 -> V_20 = ( void * ) V_27 ;
V_24 [ V_27 ] = & V_39 -> V_16 . V_16 ;
}
V_44 . V_24 = V_24 ;
return 0 ;
V_31:
F_11 ( V_24 ) ;
return V_26 ;
}
static bool F_12 ( struct V_45 * V_46 )
{
T_5 V_47 = V_46 -> V_16 . V_47 ;
if ( ( V_47 & V_48 ) != V_47 )
return false ;
return true ;
}
static void F_13 ( struct V_45 * V_46 )
{
T_5 V_10 ;
V_10 = V_49 | V_50 | V_51 ;
if ( ! V_46 -> V_16 . V_52 )
V_10 |= V_53 ;
if ( ! V_46 -> V_16 . V_54 )
V_10 |= V_55 ;
V_10 |= ( V_46 -> V_16 . V_47 & V_48 ) ;
F_14 ( V_56 , V_10 ) ;
}
static void F_15 ( bool V_57 )
{
T_5 V_58 ;
F_16 ( V_56 , V_58 ) ;
if ( V_57 )
V_58 |= V_51 ;
else
V_58 &= ~ V_51 ;
F_14 ( V_56 , V_58 ) ;
if ( ! V_57 )
F_17 () ;
}
static void F_18 ( void * V_17 , unsigned int V_59 ,
unsigned int V_60 )
{
T_5 V_10 ;
F_14 ( V_61 , F_19 ( V_17 ) ) ;
V_10 = 0x7f | ( ( T_5 ) V_59 << 7 ) | ( ( T_5 ) V_60 << 32 ) ;
F_14 ( V_62 , V_10 ) ;
}
static struct V_63 * F_20 ( int V_64 , T_6 V_65 )
{
int V_66 = F_21 ( V_64 ) ;
struct V_63 * V_63 ;
struct V_67 * V_68 ;
V_68 = F_22 ( V_66 , V_65 | V_69 , 0 ) ;
if ( ! V_68 )
return NULL ;
V_63 = F_23 ( V_68 ) ;
V_63 -> V_70 = 0 ;
V_63 -> V_71 = F_24 ( V_68 ) ;
if ( ! F_1 ( V_72 ) ) {
F_25 ( V_63 , 1 ) -> V_73 = V_63 -> V_71 >> V_74 ;
F_25 ( V_63 , 1 ) -> V_75 = 1 ;
}
return V_63 ;
}
static void F_26 ( struct V_63 * V_63 )
{
F_27 ( ( unsigned long ) V_63 ) ;
}
static void F_28 ( struct V_76 * V_17 , struct V_63 * V_63 )
{
struct V_63 * V_70 = V_17 -> V_70 ;
F_29 ( & V_63 -> V_77 , & V_17 -> V_78 ) ;
if ( ! V_17 -> V_79 ) {
V_17 -> V_79 = V_17 -> V_70 = V_17 -> V_80 = V_63 ;
return;
}
V_63 -> V_81 = V_70 -> V_81 + V_70 -> V_25 ;
V_17 -> V_70 = V_63 ;
if ( ! F_1 ( V_72 ) )
return;
F_30 ( V_70 -> V_70 != V_82 - 1 ) ;
F_25 ( V_70 , - 1 ) -> V_73 = V_63 -> V_71 >> V_74 ;
F_25 ( V_70 , - 1 ) -> V_75 = 1 ;
}
static bool F_31 ( struct V_63 * V_63 )
{
if ( ! F_1 ( V_72 ) )
return ! ! V_63 -> V_70 ;
return V_63 -> V_70 == V_82 - 1 ;
}
static int F_32 ( struct V_76 * V_17 , T_6 V_65 )
{
struct V_63 * V_63 = V_17 -> V_70 ;
int V_83 = 0 ;
struct V_67 * V_68 ;
V_68 = F_33 ( V_17 -> V_84 [ V_17 -> V_85 ] ) ;
if ( F_34 ( V_68 ) )
V_83 = F_35 ( V_68 ) ;
if ( F_31 ( V_63 ) ) {
V_63 = F_20 ( V_17 -> V_64 , V_65 ) ;
if ( ! V_63 )
return - V_37 ;
F_28 ( V_17 , V_63 ) ;
}
F_25 ( V_63 , - 1 ) -> V_73 = F_24 ( V_68 ) >> V_74 ;
F_25 ( V_63 , - 1 ) -> V_25 = V_83 ;
if ( ! V_17 -> V_86 && ! F_1 ( V_72 ) ) {
F_25 ( V_63 , - 1 ) -> V_87 = 1 ;
F_25 ( V_63 , - 1 ) -> V_88 = 1 ;
}
V_63 -> V_70 ++ ;
V_63 -> V_25 += F_36 ( V_83 ) ;
V_17 -> V_85 += 1ul << V_83 ;
return 0 ;
}
static void F_37 ( struct V_76 * V_17 )
{
struct V_63 * V_63 ;
F_38 (topa, &buf->tables, list) {
int V_27 ;
F_39 ( L_2 , V_63 -> V_89 ,
V_63 -> V_71 , V_63 -> V_81 , V_63 -> V_25 ) ;
for ( V_27 = 0 ; V_27 < V_82 ; V_27 ++ ) {
F_39 ( L_3 ,
& V_63 -> V_89 [ V_27 ] ,
( unsigned long ) V_63 -> V_89 [ V_27 ] . V_73 << V_74 ,
F_36 ( V_63 -> V_89 [ V_27 ] . V_25 ) ,
V_63 -> V_89 [ V_27 ] . V_75 ? 'E' : ' ' ,
V_63 -> V_89 [ V_27 ] . V_87 ? 'I' : ' ' ,
V_63 -> V_89 [ V_27 ] . V_88 ? 'S' : ' ' ,
* ( T_5 * ) & V_63 -> V_89 [ V_27 ] ) ;
if ( ( F_1 ( V_72 ) &&
V_63 -> V_89 [ V_27 ] . V_88 ) ||
V_63 -> V_89 [ V_27 ] . V_75 )
break;
}
}
}
static void F_40 ( struct V_76 * V_17 )
{
V_17 -> V_60 = 0 ;
V_17 -> V_90 ++ ;
if ( V_17 -> V_90 == V_17 -> V_80 -> V_70 ) {
if ( V_17 -> V_80 == V_17 -> V_70 )
V_17 -> V_80 = V_17 -> V_79 ;
else
V_17 -> V_80 = F_41 ( V_17 -> V_80 -> V_77 . V_91 , struct V_63 ,
V_77 ) ;
V_17 -> V_90 = 0 ;
}
}
static void F_42 ( struct V_92 * V_92 )
{
struct V_76 * V_17 = F_43 ( & V_92 -> V_93 ) ;
T_5 V_59 , V_73 , V_94 ;
V_73 = V_17 -> V_80 -> V_81 + V_17 -> V_60 ;
for ( V_59 = 0 ; V_59 < V_17 -> V_90 ; V_59 ++ )
V_73 += F_36 ( V_17 -> V_80 -> V_89 [ V_59 ] . V_25 ) ;
if ( V_17 -> V_86 ) {
F_44 ( & V_17 -> V_95 , V_73 ) ;
} else {
V_94 = ( F_45 ( & V_17 -> V_96 , V_73 ) &
( ( V_17 -> V_85 << V_97 ) - 1 ) ) ;
if ( V_73 < V_94 )
V_73 += V_17 -> V_85 << V_97 ;
F_46 ( V_73 - V_94 , & V_17 -> V_95 ) ;
}
}
static void * F_47 ( struct V_76 * V_17 )
{
return F_48 ( V_17 -> V_80 -> V_89 [ V_17 -> V_90 ] . V_73 << V_74 ) ;
}
static T_4 F_49 ( struct V_76 * V_17 )
{
return F_36 ( V_17 -> V_80 -> V_89 [ V_17 -> V_90 ] . V_25 ) ;
}
static void F_50 ( struct V_92 * V_92 )
{
struct V_76 * V_17 = F_43 ( & V_92 -> V_93 ) ;
int V_98 = 0 ;
T_5 V_99 ;
F_16 ( V_100 , V_99 ) ;
if ( V_99 & V_101 ) {
F_51 ( L_4 ) ;
F_37 ( V_17 ) ;
V_99 &= ~ V_101 ;
}
if ( V_99 & V_102 ) {
V_99 &= ~ V_102 ;
if ( ! F_1 ( V_72 ) ||
V_17 -> V_60 == F_36 ( F_25 ( V_17 -> V_80 , V_17 -> V_90 ) -> V_25 ) ) {
F_52 ( & V_17 -> V_103 ) ;
V_98 ++ ;
}
}
if ( ! F_1 ( V_72 ) && ! V_17 -> V_86 &&
F_49 ( V_17 ) - V_17 -> V_60 <= V_104 ) {
void * V_96 = F_47 ( V_17 ) ;
memset ( V_96 + V_17 -> V_60 , 0 ,
F_49 ( V_17 ) -
V_17 -> V_60 ) ;
V_98 ++ ;
}
if ( V_98 )
F_40 ( V_17 ) ;
F_14 ( V_100 , V_99 ) ;
}
static void F_53 ( struct V_76 * V_17 )
{
T_5 V_81 , V_105 ;
F_16 ( V_61 , V_105 ) ;
V_17 -> V_80 = F_48 ( V_105 ) ;
F_16 ( V_62 , V_81 ) ;
V_17 -> V_60 = V_81 >> 32 ;
V_17 -> V_90 = ( V_81 & 0xffffff80 ) >> 7 ;
}
static unsigned int F_54 ( struct V_76 * V_17 , unsigned int V_106 )
{
struct V_107 * V_108 = V_17 -> V_109 [ V_106 ] ;
if ( V_17 -> V_79 == V_17 -> V_70 && V_17 -> V_79 -> V_70 == 1 )
return V_106 ;
do {
V_106 ++ ;
V_106 &= V_17 -> V_85 - 1 ;
} while ( V_17 -> V_109 [ V_106 ] == V_108 );
return V_106 ;
}
static int F_55 ( struct V_76 * V_17 ,
struct V_110 * V_93 )
{
unsigned long V_96 = F_56 ( & V_17 -> V_96 ) ;
unsigned long V_111 , V_112 , V_113 ;
if ( V_17 -> V_60 + V_93 -> V_25 + 1 <
F_36 ( F_25 ( V_17 -> V_80 , V_17 -> V_90 ) -> V_25 ) )
return - V_114 ;
if ( ! F_1 ( V_72 ) )
return 0 ;
V_17 -> V_109 [ V_17 -> V_115 ] -> V_88 = 0 ;
V_17 -> V_109 [ V_17 -> V_116 ] -> V_87 = 0 ;
V_112 = V_93 -> V_25 >> V_97 ;
if ( ! F_57 ( V_96 + V_93 -> V_25 + 1 ) )
V_112 ++ ;
V_111 = ( V_96 >> V_97 ) + V_112 ;
V_111 &= V_17 -> V_85 - 1 ;
V_17 -> V_115 = V_111 ;
V_113 = V_93 -> V_113 >> V_97 ;
V_111 = ( V_96 >> V_97 ) + V_112 - 1 ;
if ( V_111 > V_113 )
V_111 = V_113 ;
V_111 &= V_17 -> V_85 - 1 ;
V_17 -> V_116 = V_111 ;
V_17 -> V_109 [ V_17 -> V_115 ] -> V_88 = 1 ;
V_17 -> V_109 [ V_17 -> V_116 ] -> V_87 = 1 ;
return 0 ;
}
static void F_58 ( struct V_76 * V_17 )
{
struct V_63 * V_80 = V_17 -> V_79 , * V_117 = V_17 -> V_70 ;
struct V_107 * V_118 = F_25 ( V_80 , 0 ) ,
* V_119 = F_25 ( V_117 , V_117 -> V_70 - 1 ) ;
int V_106 = 0 , V_111 = 0 ;
while ( V_106 < V_17 -> V_85 ) {
int V_120 ;
for ( V_120 = 0 ; V_120 < 1 << V_118 -> V_25 ; V_120 ++ , V_106 ++ )
V_17 -> V_109 [ V_106 ] = V_119 ;
V_119 = V_118 ;
if ( V_111 == V_80 -> V_70 - 1 ) {
V_111 = 0 ;
V_80 = F_41 ( V_80 -> V_77 . V_91 , struct V_63 , V_77 ) ;
} else {
V_111 ++ ;
}
V_118 = F_25 ( V_80 , V_111 ) ;
}
}
static void F_59 ( struct V_76 * V_17 , unsigned long V_96 )
{
int V_106 ;
if ( V_17 -> V_86 )
V_96 &= ( V_17 -> V_85 << V_97 ) - 1 ;
V_106 = ( V_96 >> V_97 ) & ( V_17 -> V_85 - 1 ) ;
V_106 = F_54 ( V_17 , V_106 ) ;
V_17 -> V_80 = (struct V_63 * ) ( ( unsigned long ) V_17 -> V_109 [ V_106 ] & V_121 ) ;
V_17 -> V_90 = ( ( unsigned long ) V_17 -> V_109 [ V_106 ] -
( unsigned long ) V_17 -> V_80 ) / sizeof( struct V_107 ) ;
V_17 -> V_60 = V_96 & ( F_36 ( V_17 -> V_80 -> V_89 [ V_17 -> V_90 ] . V_25 ) - 1 ) ;
F_60 ( & V_17 -> V_96 , V_96 ) ;
F_44 ( & V_17 -> V_95 , 0 ) ;
}
static void F_61 ( struct V_76 * V_17 )
{
struct V_63 * V_63 , * V_122 ;
F_62 (topa, iter, &buf->tables, list) {
F_26 ( V_63 ) ;
}
}
static int F_63 ( struct V_76 * V_17 , unsigned long V_85 ,
T_6 V_65 )
{
struct V_63 * V_63 ;
int V_123 ;
V_63 = F_20 ( V_17 -> V_64 , V_65 ) ;
if ( ! V_63 )
return - V_37 ;
F_28 ( V_17 , V_63 ) ;
while ( V_17 -> V_85 < V_85 ) {
V_123 = F_32 ( V_17 , V_65 ) ;
if ( V_123 ) {
F_61 ( V_17 ) ;
return - V_37 ;
}
}
F_58 ( V_17 ) ;
if ( F_1 ( V_72 ) ) {
F_25 ( V_17 -> V_70 , - 1 ) -> V_73 = V_17 -> V_79 -> V_71 >> V_74 ;
F_25 ( V_17 -> V_70 , - 1 ) -> V_75 = 1 ;
}
F_37 ( V_17 ) ;
return 0 ;
}
static void *
F_64 ( int V_64 , void * * V_124 , int V_85 , bool V_86 )
{
struct V_76 * V_17 ;
int V_66 , V_26 ;
if ( ! V_85 )
return NULL ;
if ( V_64 == - 1 )
V_64 = F_65 () ;
V_66 = F_21 ( V_64 ) ;
V_17 = F_66 ( F_67 ( struct V_76 , V_109 [ V_85 ] ) ,
V_38 , V_66 ) ;
if ( ! V_17 )
return NULL ;
V_17 -> V_64 = V_64 ;
V_17 -> V_86 = V_86 ;
V_17 -> V_84 = V_124 ;
F_68 ( & V_17 -> V_78 ) ;
V_26 = F_63 ( V_17 , V_85 , V_38 ) ;
if ( V_26 ) {
F_11 ( V_17 ) ;
return NULL ;
}
return V_17 ;
}
static void F_69 ( void * V_125 )
{
struct V_76 * V_17 = V_125 ;
F_61 ( V_17 ) ;
F_11 ( V_17 ) ;
}
static bool F_70 ( struct V_76 * V_17 , struct V_92 * V_92 )
{
if ( V_17 -> V_86 )
return false ;
if ( F_71 ( & V_17 -> V_95 ) >= V_92 -> V_93 . V_25 )
return true ;
return false ;
}
void F_72 ( void )
{
struct V_92 * V_92 = F_73 ( & V_126 ) ;
struct V_76 * V_17 ;
struct V_45 * V_46 = V_92 -> V_93 . V_46 ;
if ( ! F_74 ( V_92 -> V_127 ) )
return;
F_15 ( false ) ;
if ( ! V_46 )
return;
V_17 = F_43 ( & V_92 -> V_93 ) ;
if ( ! V_17 )
return;
F_53 ( V_17 ) ;
F_50 ( V_92 ) ;
F_42 ( V_92 ) ;
F_75 ( & V_92 -> V_93 , F_76 ( & V_17 -> V_95 , 0 ) ,
F_76 ( & V_17 -> V_103 , 0 ) ) ;
if ( ! V_46 -> V_128 . V_129 ) {
int V_26 ;
V_17 = F_77 ( & V_92 -> V_93 , V_46 ) ;
if ( ! V_17 ) {
V_46 -> V_128 . V_129 = V_130 ;
return;
}
F_59 ( V_17 , V_92 -> V_93 . V_96 ) ;
V_26 = F_55 ( V_17 , & V_92 -> V_93 ) ;
if ( V_26 ) {
F_75 ( & V_92 -> V_93 , 0 , true ) ;
return;
}
F_18 ( V_17 -> V_80 -> V_89 , V_17 -> V_90 ,
V_17 -> V_60 ) ;
F_14 ( V_100 , 0 ) ;
F_13 ( V_46 ) ;
}
}
static void F_78 ( struct V_45 * V_46 , int V_41 )
{
struct V_92 * V_92 = F_73 ( & V_126 ) ;
struct V_76 * V_17 = F_43 ( & V_92 -> V_93 ) ;
if ( ! V_17 || F_70 ( V_17 , V_92 ) ) {
V_46 -> V_128 . V_129 = V_130 ;
return;
}
F_74 ( V_92 -> V_127 ) = 1 ;
V_46 -> V_128 . V_129 = 0 ;
F_18 ( V_17 -> V_80 -> V_89 , V_17 -> V_90 ,
V_17 -> V_60 ) ;
F_14 ( V_100 , 0 ) ;
F_13 ( V_46 ) ;
}
static void F_79 ( struct V_45 * V_46 , int V_41 )
{
struct V_92 * V_92 = F_73 ( & V_126 ) ;
F_74 ( V_92 -> V_127 ) = 0 ;
F_15 ( false ) ;
if ( V_46 -> V_128 . V_129 == V_130 )
return;
V_46 -> V_128 . V_129 = V_130 ;
if ( V_41 & V_131 ) {
struct V_76 * V_17 = F_43 ( & V_92 -> V_93 ) ;
if ( ! V_17 )
return;
if ( F_80 ( V_92 -> V_93 . V_46 != V_46 ) )
return;
F_53 ( V_17 ) ;
F_50 ( V_92 ) ;
F_42 ( V_92 ) ;
}
}
static void F_81 ( struct V_45 * V_46 , int V_41 )
{
struct V_92 * V_92 = F_73 ( & V_126 ) ;
struct V_76 * V_17 ;
F_79 ( V_46 , V_131 ) ;
V_17 = F_43 ( & V_92 -> V_93 ) ;
if ( V_17 ) {
if ( V_17 -> V_86 )
V_92 -> V_93 . V_96 =
F_76 ( & V_17 -> V_95 ,
V_17 -> V_85 << V_97 ) ;
F_75 ( & V_92 -> V_93 , F_76 ( & V_17 -> V_95 , 0 ) ,
F_76 ( & V_17 -> V_103 , 0 ) ) ;
}
}
static int F_82 ( struct V_45 * V_46 , int V_41 )
{
struct V_76 * V_17 ;
struct V_92 * V_92 = F_73 ( & V_126 ) ;
struct V_132 * V_133 = & V_46 -> V_128 ;
int V_26 = - V_134 ;
if ( V_92 -> V_93 . V_46 )
goto V_31;
V_17 = F_77 ( & V_92 -> V_93 , V_46 ) ;
V_26 = - V_114 ;
if ( ! V_17 )
goto V_135;
F_59 ( V_17 , V_92 -> V_93 . V_96 ) ;
if ( ! V_17 -> V_86 ) {
V_26 = F_55 ( V_17 , & V_92 -> V_93 ) ;
if ( V_26 )
goto V_136;
}
if ( V_41 & V_137 ) {
F_78 ( V_46 , 0 ) ;
V_26 = - V_134 ;
if ( V_133 -> V_129 == V_130 )
goto V_136;
} else {
V_133 -> V_129 = V_130 ;
}
return 0 ;
V_136:
F_75 ( & V_92 -> V_93 , 0 , true ) ;
V_135:
V_133 -> V_129 = V_130 ;
V_31:
return V_26 ;
}
static void F_83 ( struct V_45 * V_46 )
{
}
static void F_84 ( struct V_45 * V_46 )
{
F_85 ( V_138 ) ;
}
static int F_86 ( struct V_45 * V_46 )
{
if ( V_46 -> V_16 . type != V_7 . V_139 . type )
return - V_140 ;
if ( ! F_12 ( V_46 ) )
return - V_114 ;
if ( F_87 ( V_138 ) )
return - V_134 ;
V_46 -> V_141 = F_84 ;
return 0 ;
}
static T_3 int F_88 ( void )
{
int V_26 , V_64 , V_142 = 0 ;
F_89 ( sizeof( struct V_63 ) > V_21 ) ;
F_90 () ;
F_91 (cpu) {
T_5 V_58 ;
V_26 = F_92 ( V_64 , V_56 , & V_58 ) ;
if ( ! V_26 && ( V_58 & V_51 ) )
V_142 ++ ;
}
F_93 () ;
if ( V_142 ) {
F_87 ( V_138 ) ;
F_94 ( L_5 ) ;
return - V_134 ;
}
V_26 = F_5 () ;
if ( V_26 )
return V_26 ;
if ( ! F_1 ( V_143 ) ) {
F_94 ( L_6 ) ;
return - V_28 ;
}
if ( ! F_1 ( V_72 ) )
V_7 . V_139 . V_144 =
V_145 | V_146 ;
V_7 . V_139 . V_144 |= V_147 | V_148 ;
V_7 . V_139 . V_149 = V_150 ;
V_7 . V_139 . V_151 = V_152 ;
V_7 . V_139 . V_153 = F_86 ;
V_7 . V_139 . V_154 = F_82 ;
V_7 . V_139 . V_155 = F_81 ;
V_7 . V_139 . V_57 = F_78 ;
V_7 . V_139 . V_88 = F_79 ;
V_7 . V_139 . V_156 = F_83 ;
V_7 . V_139 . V_157 = F_64 ;
V_7 . V_139 . V_158 = F_69 ;
V_26 = F_95 ( & V_7 . V_139 , L_7 , - 1 ) ;
return V_26 ;
}
