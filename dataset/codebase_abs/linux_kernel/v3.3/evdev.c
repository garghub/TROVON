static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( & V_2 -> V_5 ) ;
V_2 -> V_6 [ V_2 -> V_7 ++ ] = * V_4 ;
V_2 -> V_7 &= V_2 -> V_8 - 1 ;
if ( F_3 ( V_2 -> V_7 == V_2 -> V_9 ) ) {
V_2 -> V_9 = ( V_2 -> V_7 - 2 ) & ( V_2 -> V_8 - 1 ) ;
V_2 -> V_6 [ V_2 -> V_9 ] . time = V_4 -> time ;
V_2 -> V_6 [ V_2 -> V_9 ] . type = V_10 ;
V_2 -> V_6 [ V_2 -> V_9 ] . V_11 = V_12 ;
V_2 -> V_6 [ V_2 -> V_9 ] . V_13 = 0 ;
V_2 -> V_14 = V_2 -> V_9 ;
}
if ( V_4 -> type == V_10 && V_4 -> V_11 == V_15 ) {
V_2 -> V_14 = V_2 -> V_7 ;
F_4 ( & V_2 -> V_16 , V_17 , V_18 ) ;
}
F_5 ( & V_2 -> V_5 ) ;
}
static void F_6 ( struct V_19 * V_20 ,
unsigned int type , unsigned int V_11 , int V_13 )
{
struct V_21 * V_21 = V_20 -> V_22 ;
struct V_1 * V_2 ;
struct V_3 V_4 ;
F_7 ( & V_4 . time ) ;
V_4 . type = type ;
V_4 . V_11 = V_11 ;
V_4 . V_13 = V_13 ;
F_8 () ;
V_2 = F_9 ( V_21 -> V_23 ) ;
if ( V_2 )
F_1 ( V_2 , & V_4 ) ;
else
F_10 (client, &evdev->client_list, node)
F_1 ( V_2 , & V_4 ) ;
F_11 () ;
if ( type == V_10 && V_11 == V_15 )
F_12 ( & V_21 -> V_24 ) ;
}
static int F_13 ( int V_25 , struct V_26 * V_26 , int V_27 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
return F_14 ( V_25 , V_26 , V_27 , & V_2 -> V_16 ) ;
}
static int F_15 ( struct V_26 * V_26 , T_1 V_29 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_21 * V_21 = V_2 -> V_21 ;
int V_30 ;
V_30 = F_16 ( & V_21 -> V_31 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_21 -> V_32 )
V_30 = - V_33 ;
else
V_30 = F_17 ( & V_21 -> V_20 , V_26 ) ;
F_18 ( & V_21 -> V_31 ) ;
return V_30 ;
}
static void F_19 ( struct V_34 * V_35 )
{
struct V_21 * V_21 = F_20 ( V_35 , struct V_21 , V_35 ) ;
F_21 ( V_21 -> V_20 . V_35 ) ;
F_22 ( V_21 ) ;
}
static int F_23 ( struct V_21 * V_21 , struct V_1 * V_2 )
{
int error ;
if ( V_21 -> V_23 )
return - V_36 ;
error = F_24 ( & V_21 -> V_20 ) ;
if ( error )
return error ;
F_25 ( V_21 -> V_23 , V_2 ) ;
return 0 ;
}
static int F_26 ( struct V_21 * V_21 , struct V_1 * V_2 )
{
if ( V_21 -> V_23 != V_2 )
return - V_37 ;
F_25 ( V_21 -> V_23 , NULL ) ;
F_27 () ;
F_28 ( & V_21 -> V_20 ) ;
return 0 ;
}
static void F_29 ( struct V_21 * V_21 ,
struct V_1 * V_2 )
{
F_2 ( & V_21 -> V_38 ) ;
F_30 ( & V_2 -> V_39 , & V_21 -> V_40 ) ;
F_5 ( & V_21 -> V_38 ) ;
}
static void F_31 ( struct V_21 * V_21 ,
struct V_1 * V_2 )
{
F_2 ( & V_21 -> V_38 ) ;
F_32 ( & V_2 -> V_39 ) ;
F_5 ( & V_21 -> V_38 ) ;
F_27 () ;
}
static int F_33 ( struct V_21 * V_21 )
{
int V_30 ;
V_30 = F_16 ( & V_21 -> V_31 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_21 -> V_32 )
V_30 = - V_33 ;
else if ( ! V_21 -> V_41 ++ ) {
V_30 = F_34 ( & V_21 -> V_20 ) ;
if ( V_30 )
V_21 -> V_41 -- ;
}
F_18 ( & V_21 -> V_31 ) ;
return V_30 ;
}
static void F_35 ( struct V_21 * V_21 )
{
F_36 ( & V_21 -> V_31 ) ;
if ( V_21 -> V_32 && ! -- V_21 -> V_41 )
F_37 ( & V_21 -> V_20 ) ;
F_18 ( & V_21 -> V_31 ) ;
}
static void F_38 ( struct V_21 * V_21 )
{
struct V_1 * V_2 ;
F_2 ( & V_21 -> V_38 ) ;
F_39 (client, &evdev->client_list, node)
F_4 ( & V_2 -> V_16 , V_17 , V_42 ) ;
F_5 ( & V_21 -> V_38 ) ;
F_12 ( & V_21 -> V_24 ) ;
}
static int F_40 ( struct V_43 * V_43 , struct V_26 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_21 * V_21 = V_2 -> V_21 ;
F_36 ( & V_21 -> V_31 ) ;
if ( V_21 -> V_23 == V_2 )
F_26 ( V_21 , V_2 ) ;
F_18 ( & V_21 -> V_31 ) ;
F_31 ( V_21 , V_2 ) ;
F_22 ( V_2 ) ;
F_35 ( V_21 ) ;
F_41 ( & V_21 -> V_35 ) ;
return 0 ;
}
static unsigned int F_42 ( struct V_44 * V_35 )
{
unsigned int V_45 =
F_43 ( V_35 -> V_46 * V_47 ,
V_48 ) ;
return F_44 ( V_45 ) ;
}
static int F_45 ( struct V_43 * V_43 , struct V_26 * V_26 )
{
struct V_21 * V_21 ;
struct V_1 * V_2 ;
int V_49 = F_46 ( V_43 ) - V_50 ;
unsigned int V_8 ;
int error ;
if ( V_49 >= V_51 )
return - V_33 ;
error = F_16 ( & V_52 ) ;
if ( error )
return error ;
V_21 = V_53 [ V_49 ] ;
if ( V_21 )
F_47 ( & V_21 -> V_35 ) ;
F_18 ( & V_52 ) ;
if ( ! V_21 )
return - V_33 ;
V_8 = F_42 ( V_21 -> V_20 . V_35 ) ;
V_2 = F_48 ( sizeof( struct V_1 ) +
V_8 * sizeof( struct V_3 ) ,
V_54 ) ;
if ( ! V_2 ) {
error = - V_55 ;
goto V_56;
}
V_2 -> V_8 = V_8 ;
F_49 ( & V_2 -> V_5 ) ;
V_2 -> V_21 = V_21 ;
F_29 ( V_21 , V_2 ) ;
error = F_33 ( V_21 ) ;
if ( error )
goto V_57;
V_26 -> V_28 = V_2 ;
F_50 ( V_43 , V_26 ) ;
return 0 ;
V_57:
F_31 ( V_21 , V_2 ) ;
F_22 ( V_2 ) ;
V_56:
F_41 ( & V_21 -> V_35 ) ;
return error ;
}
static T_2 F_51 ( struct V_26 * V_26 , const char T_3 * V_6 ,
T_4 V_58 , T_5 * V_59 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_21 * V_21 = V_2 -> V_21 ;
struct V_3 V_4 ;
int V_30 = 0 ;
if ( V_58 < F_52 () )
return - V_37 ;
V_30 = F_16 ( & V_21 -> V_31 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_21 -> V_32 ) {
V_30 = - V_33 ;
goto V_60;
}
do {
if ( F_53 ( V_6 + V_30 , & V_4 ) ) {
V_30 = - V_61 ;
goto V_60;
}
V_30 += F_52 () ;
F_54 ( & V_21 -> V_20 ,
V_4 . type , V_4 . V_11 , V_4 . V_13 ) ;
} while ( V_30 + F_52 () <= V_58 );
V_60:
F_18 ( & V_21 -> V_31 ) ;
return V_30 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_62 ;
F_56 ( & V_2 -> V_5 ) ;
V_62 = V_2 -> V_14 != V_2 -> V_9 ;
if ( V_62 ) {
* V_4 = V_2 -> V_6 [ V_2 -> V_9 ++ ] ;
V_2 -> V_9 &= V_2 -> V_8 - 1 ;
}
F_57 ( & V_2 -> V_5 ) ;
return V_62 ;
}
static T_2 F_58 ( struct V_26 * V_26 , char T_3 * V_6 ,
T_4 V_58 , T_5 * V_59 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_21 * V_21 = V_2 -> V_21 ;
struct V_3 V_4 ;
int V_30 = 0 ;
if ( V_58 < F_52 () )
return - V_37 ;
if ( ! ( V_26 -> V_63 & V_64 ) ) {
V_30 = F_59 ( V_21 -> V_24 ,
V_2 -> V_14 != V_2 -> V_9 ||
! V_21 -> V_32 ) ;
if ( V_30 )
return V_30 ;
}
if ( ! V_21 -> V_32 )
return - V_33 ;
while ( V_30 + F_52 () <= V_58 &&
F_55 ( V_2 , & V_4 ) ) {
if ( F_60 ( V_6 + V_30 , & V_4 ) )
return - V_61 ;
V_30 += F_52 () ;
}
if ( V_30 == 0 && ( V_26 -> V_63 & V_64 ) )
return - V_65 ;
return V_30 ;
}
static unsigned int F_61 ( struct V_26 * V_26 , T_6 * V_24 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_21 * V_21 = V_2 -> V_21 ;
unsigned int V_66 ;
F_62 ( V_26 , & V_21 -> V_24 , V_24 ) ;
V_66 = V_21 -> V_32 ? V_67 | V_68 : V_69 | V_70 ;
if ( V_2 -> V_14 != V_2 -> V_9 )
V_66 |= V_71 | V_72 ;
return V_66 ;
}
static int F_63 ( unsigned long * V_73 , unsigned int V_74 ,
unsigned int V_75 , void T_3 * V_76 , int V_77 )
{
int V_78 , V_49 ;
if ( V_77 ) {
V_78 = F_64 ( V_74 ) * sizeof( V_79 ) ;
if ( V_78 > V_75 )
V_78 = V_75 ;
for ( V_49 = 0 ; V_49 < V_78 / sizeof( V_79 ) ; V_49 ++ )
if ( F_65 ( ( V_79 T_3 * ) V_76 + V_49 ,
( V_79 * ) V_73 +
V_49 + 1 - ( ( V_49 % 2 ) << 1 ) ,
sizeof( V_79 ) ) )
return - V_61 ;
} else {
V_78 = F_66 ( V_74 ) * sizeof( long ) ;
if ( V_78 > V_75 )
V_78 = V_75 ;
if ( F_65 ( V_76 , V_73 , V_78 ) )
return - V_61 ;
}
return V_78 ;
}
static int F_63 ( unsigned long * V_73 , unsigned int V_74 ,
unsigned int V_75 , void T_3 * V_76 , int V_77 )
{
int V_78 = V_77 ?
F_64 ( V_74 ) * sizeof( V_79 ) :
F_66 ( V_74 ) * sizeof( long ) ;
if ( V_78 > V_75 )
V_78 = V_75 ;
return F_65 ( V_76 , V_73 , V_78 ) ? - V_61 : V_78 ;
}
static int F_63 ( unsigned long * V_73 , unsigned int V_74 ,
unsigned int V_75 , void T_3 * V_76 , int V_77 )
{
int V_78 = F_66 ( V_74 ) * sizeof( long ) ;
if ( V_78 > V_75 )
V_78 = V_75 ;
return F_65 ( V_76 , V_73 , V_78 ) ? - V_61 : V_78 ;
}
static int F_67 ( const char * V_80 , unsigned int V_75 , void T_3 * V_76 )
{
int V_78 ;
if ( ! V_80 )
return - V_81 ;
V_78 = strlen ( V_80 ) + 1 ;
if ( V_78 > V_75 )
V_78 = V_75 ;
return F_65 ( V_76 , V_80 , V_78 ) ? - V_61 : V_78 ;
}
static int F_68 ( struct V_44 * V_35 ,
unsigned int type , unsigned int V_82 ,
void T_3 * V_76 , int V_83 )
{
static unsigned long V_84 ;
unsigned long * V_73 ;
int V_78 ;
switch ( type ) {
case 0 : V_73 = V_35 -> V_85 ; V_78 = V_86 ; break;
case V_87 : V_73 = V_35 -> V_88 ; V_78 = V_89 ; break;
case V_90 : V_73 = V_35 -> V_91 ; V_78 = V_92 ; break;
case V_93 : V_73 = V_35 -> V_94 ; V_78 = V_95 ; break;
case V_96 : V_73 = V_35 -> V_97 ; V_78 = V_98 ; break;
case V_99 : V_73 = V_35 -> V_100 ; V_78 = V_101 ; break;
case V_102 : V_73 = V_35 -> V_103 ; V_78 = V_104 ; break;
case V_105 : V_73 = V_35 -> V_106 ; V_78 = V_107 ; break;
case V_108 : V_73 = V_35 -> V_109 ; V_78 = V_110 ; break;
default: return - V_37 ;
}
if ( type == V_87 && V_82 == V_111 ) {
V_78 = V_111 ;
if ( F_69 ( & V_84 , 10 * 1000 ) )
F_70 ( L_1
L_2
L_3 ,
V_111 ,
F_66 ( V_111 ) * sizeof( long ) ) ;
}
return F_63 ( V_73 , V_78 , V_82 , V_76 , V_83 ) ;
}
static int F_71 ( struct V_44 * V_35 , void T_3 * V_76 )
{
struct V_112 V_113 = {
. V_78 = sizeof( unsigned int ) ,
. V_114 = 0 ,
} ;
int T_3 * V_115 = ( int T_3 * ) V_76 ;
int error ;
if ( F_72 ( V_113 . V_116 , V_76 , sizeof( unsigned int ) ) )
return - V_61 ;
error = F_73 ( V_35 , & V_113 ) ;
if ( error )
return error ;
if ( F_74 ( V_113 . V_117 , V_115 + 1 ) )
return - V_61 ;
return 0 ;
}
static int F_75 ( struct V_44 * V_35 , void T_3 * V_76 )
{
struct V_112 V_113 ;
int error ;
if ( F_72 ( & V_113 , V_76 , sizeof( V_113 ) ) )
return - V_61 ;
error = F_73 ( V_35 , & V_113 ) ;
if ( error )
return error ;
if ( F_65 ( V_76 , & V_113 , sizeof( V_113 ) ) )
return - V_61 ;
return 0 ;
}
static int F_76 ( struct V_44 * V_35 , void T_3 * V_76 )
{
struct V_112 V_113 = {
. V_78 = sizeof( unsigned int ) ,
. V_114 = 0 ,
} ;
int T_3 * V_115 = ( int T_3 * ) V_76 ;
if ( F_72 ( V_113 . V_116 , V_76 , sizeof( unsigned int ) ) )
return - V_61 ;
if ( F_77 ( V_113 . V_117 , V_115 + 1 ) )
return - V_61 ;
return F_78 ( V_35 , & V_113 ) ;
}
static int F_79 ( struct V_44 * V_35 , void T_3 * V_76 )
{
struct V_112 V_113 ;
if ( F_72 ( & V_113 , V_76 , sizeof( V_113 ) ) )
return - V_61 ;
if ( V_113 . V_78 > sizeof( V_113 . V_116 ) )
return - V_37 ;
return F_78 ( V_35 , & V_113 ) ;
}
static long F_80 ( struct V_26 * V_26 , unsigned int V_118 ,
void T_3 * V_76 , int V_83 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_21 * V_21 = V_2 -> V_21 ;
struct V_44 * V_35 = V_21 -> V_20 . V_35 ;
struct V_119 abs ;
struct V_120 V_121 ;
int T_3 * V_115 = ( int T_3 * ) V_76 ;
unsigned int V_49 , V_122 , V_123 , V_124 ;
unsigned int V_82 ;
int error ;
switch ( V_118 ) {
case V_125 :
return F_74 ( V_126 , V_115 ) ;
case V_127 :
if ( F_65 ( V_76 , & V_35 -> V_29 , sizeof( struct V_128 ) ) )
return - V_61 ;
return 0 ;
case V_129 :
if ( ! F_81 ( V_130 , V_35 -> V_85 ) )
return - V_131 ;
if ( F_74 ( V_35 -> V_132 [ V_133 ] , V_115 ) )
return - V_61 ;
if ( F_74 ( V_35 -> V_132 [ V_134 ] , V_115 + 1 ) )
return - V_61 ;
return 0 ;
case V_135 :
if ( ! F_81 ( V_130 , V_35 -> V_85 ) )
return - V_131 ;
if ( F_77 ( V_123 , V_115 ) )
return - V_61 ;
if ( F_77 ( V_124 , V_115 + 1 ) )
return - V_61 ;
F_54 ( & V_21 -> V_20 , V_130 , V_133 , V_123 ) ;
F_54 ( & V_21 -> V_20 , V_130 , V_134 , V_124 ) ;
return 0 ;
case V_136 :
return F_82 ( V_35 , ( int ) ( unsigned long ) V_76 , V_26 ) ;
case V_137 :
V_49 = F_81 ( V_105 , V_35 -> V_85 ) ?
V_35 -> V_138 -> V_139 : 0 ;
if ( F_74 ( V_49 , V_115 ) )
return - V_61 ;
return 0 ;
case V_140 :
if ( V_76 )
return F_23 ( V_21 , V_2 ) ;
else
return F_26 ( V_21 , V_2 ) ;
case V_141 :
return F_71 ( V_35 , V_76 ) ;
case V_142 :
return F_76 ( V_35 , V_76 ) ;
case V_143 :
return F_75 ( V_35 , V_76 ) ;
case V_144 :
return F_79 ( V_35 , V_76 ) ;
}
V_82 = F_83 ( V_118 ) ;
#define F_84 ( T_7 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_84 ( V_118 ) ) {
case F_85 ( 0 ) :
return F_63 ( V_35 -> V_145 , V_146 ,
V_82 , V_76 , V_83 ) ;
case F_86 ( 0 ) :
return F_63 ( V_35 -> V_147 , V_89 , V_82 , V_76 , V_83 ) ;
case F_87 ( 0 ) :
return F_63 ( V_35 -> V_148 , V_101 , V_82 , V_76 , V_83 ) ;
case F_88 ( 0 ) :
return F_63 ( V_35 -> V_149 , V_104 , V_82 , V_76 , V_83 ) ;
case F_89 ( 0 ) :
return F_63 ( V_35 -> V_150 , V_110 , V_82 , V_76 , V_83 ) ;
case F_90 ( 0 ) :
return F_67 ( V_35 -> V_151 , V_82 , V_76 ) ;
case F_91 ( 0 ) :
return F_67 ( V_35 -> V_152 , V_82 , V_76 ) ;
case F_92 ( 0 ) :
return F_67 ( V_35 -> V_153 , V_82 , V_76 ) ;
case F_84 ( V_154 ) :
if ( F_93 ( V_76 , V_82 , & V_121 ) )
return - V_61 ;
error = F_94 ( V_35 , & V_121 , V_26 ) ;
if ( F_74 ( V_121 . V_29 , & ( ( (struct V_120 T_3 * ) V_76 ) -> V_29 ) ) )
return - V_61 ;
return error ;
}
if ( F_95 ( V_118 ) != 'E' )
return - V_37 ;
if ( F_96 ( V_118 ) == V_155 ) {
if ( ( F_97 ( V_118 ) & ~ V_86 ) == F_97 ( F_98 ( 0 , 0 ) ) )
return F_68 ( V_35 ,
F_97 ( V_118 ) & V_86 , V_82 ,
V_76 , V_83 ) ;
if ( ( F_97 ( V_118 ) & ~ V_95 ) == F_97 ( F_99 ( 0 ) ) ) {
if ( ! V_35 -> V_156 )
return - V_37 ;
V_122 = F_97 ( V_118 ) & V_95 ;
abs = V_35 -> V_156 [ V_122 ] ;
if ( F_65 ( V_76 , & abs , F_100 ( T_4 ,
V_82 , sizeof( struct V_119 ) ) ) )
return - V_61 ;
return 0 ;
}
}
if ( F_96 ( V_118 ) == V_157 ) {
if ( ( F_97 ( V_118 ) & ~ V_95 ) == F_97 ( F_101 ( 0 ) ) ) {
if ( ! V_35 -> V_156 )
return - V_37 ;
V_122 = F_97 ( V_118 ) & V_95 ;
if ( F_72 ( & abs , V_76 , F_100 ( T_4 ,
V_82 , sizeof( struct V_119 ) ) ) )
return - V_61 ;
if ( V_82 < sizeof( struct V_119 ) )
abs . V_158 = 0 ;
if ( V_122 == V_159 )
return - V_37 ;
F_56 ( & V_35 -> V_160 ) ;
V_35 -> V_156 [ V_122 ] = abs ;
F_57 ( & V_35 -> V_160 ) ;
return 0 ;
}
}
return - V_37 ;
}
static long F_102 ( struct V_26 * V_26 , unsigned int V_118 ,
void T_3 * V_76 , int V_83 )
{
struct V_1 * V_2 = V_26 -> V_28 ;
struct V_21 * V_21 = V_2 -> V_21 ;
int V_30 ;
V_30 = F_16 ( & V_21 -> V_31 ) ;
if ( V_30 )
return V_30 ;
if ( ! V_21 -> V_32 ) {
V_30 = - V_33 ;
goto V_60;
}
V_30 = F_80 ( V_26 , V_118 , V_76 , V_83 ) ;
V_60:
F_18 ( & V_21 -> V_31 ) ;
return V_30 ;
}
static long F_103 ( struct V_26 * V_26 , unsigned int V_118 , unsigned long V_161 )
{
return F_102 ( V_26 , V_118 , ( void T_3 * ) V_161 , 0 ) ;
}
static long F_104 ( struct V_26 * V_26 ,
unsigned int V_118 , unsigned long V_161 )
{
return F_102 ( V_26 , V_118 , F_105 ( V_161 ) , 1 ) ;
}
static int F_106 ( struct V_21 * V_21 )
{
V_53 [ V_21 -> V_162 ] = V_21 ;
return 0 ;
}
static void F_107 ( struct V_21 * V_21 )
{
F_36 ( & V_52 ) ;
V_53 [ V_21 -> V_162 ] = NULL ;
F_18 ( & V_52 ) ;
}
static void F_108 ( struct V_21 * V_21 )
{
F_36 ( & V_21 -> V_31 ) ;
V_21 -> V_32 = false ;
F_18 ( & V_21 -> V_31 ) ;
}
static void F_109 ( struct V_21 * V_21 )
{
struct V_19 * V_20 = & V_21 -> V_20 ;
F_108 ( V_21 ) ;
F_38 ( V_21 ) ;
F_107 ( V_21 ) ;
if ( V_21 -> V_41 ) {
F_17 ( V_20 , NULL ) ;
F_37 ( V_20 ) ;
}
}
static int F_110 ( struct V_163 * V_164 , struct V_44 * V_35 ,
const struct V_165 * V_29 )
{
struct V_21 * V_21 ;
int V_162 ;
int error ;
for ( V_162 = 0 ; V_162 < V_51 ; V_162 ++ )
if ( ! V_53 [ V_162 ] )
break;
if ( V_162 == V_51 ) {
F_111 ( L_4 ) ;
return - V_166 ;
}
V_21 = F_48 ( sizeof( struct V_21 ) , V_54 ) ;
if ( ! V_21 )
return - V_55 ;
F_112 ( & V_21 -> V_40 ) ;
F_49 ( & V_21 -> V_38 ) ;
F_113 ( & V_21 -> V_31 ) ;
F_114 ( & V_21 -> V_24 ) ;
F_115 ( & V_21 -> V_35 , L_5 , V_162 ) ;
V_21 -> V_32 = true ;
V_21 -> V_162 = V_162 ;
V_21 -> V_20 . V_35 = F_116 ( V_35 ) ;
V_21 -> V_20 . V_151 = F_117 ( & V_21 -> V_35 ) ;
V_21 -> V_20 . V_164 = V_164 ;
V_21 -> V_20 . V_22 = V_21 ;
V_21 -> V_35 . V_167 = F_118 ( V_168 , V_50 + V_162 ) ;
V_21 -> V_35 . V_169 = & V_170 ;
V_21 -> V_35 . V_171 = & V_35 -> V_35 ;
V_21 -> V_35 . V_172 = F_19 ;
F_119 ( & V_21 -> V_35 ) ;
error = F_120 ( & V_21 -> V_20 ) ;
if ( error )
goto V_173;
error = F_106 ( V_21 ) ;
if ( error )
goto V_174;
error = F_121 ( & V_21 -> V_35 ) ;
if ( error )
goto V_175;
return 0 ;
V_175:
F_109 ( V_21 ) ;
V_174:
F_122 ( & V_21 -> V_20 ) ;
V_173:
F_41 ( & V_21 -> V_35 ) ;
return error ;
}
static void F_123 ( struct V_19 * V_20 )
{
struct V_21 * V_21 = V_20 -> V_22 ;
F_124 ( & V_21 -> V_35 ) ;
F_109 ( V_21 ) ;
F_122 ( V_20 ) ;
F_41 ( & V_21 -> V_35 ) ;
}
static int T_8 F_125 ( void )
{
return F_126 ( & V_176 ) ;
}
static void T_9 F_127 ( void )
{
F_128 ( & V_176 ) ;
}
