static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
T_1 V_5 , T_1 V_6 )
{
V_4 -> time = F_2 ( V_2 -> V_7 == V_8 ?
V_5 : V_6 ) ;
F_3 ( & V_2 -> V_9 ) ;
V_2 -> V_10 [ V_2 -> V_11 ++ ] = * V_4 ;
V_2 -> V_11 &= V_2 -> V_12 - 1 ;
if ( F_4 ( V_2 -> V_11 == V_2 -> V_13 ) ) {
V_2 -> V_13 = ( V_2 -> V_11 - 2 ) & ( V_2 -> V_12 - 1 ) ;
V_2 -> V_10 [ V_2 -> V_13 ] . time = V_4 -> time ;
V_2 -> V_10 [ V_2 -> V_13 ] . type = V_14 ;
V_2 -> V_10 [ V_2 -> V_13 ] . V_15 = V_16 ;
V_2 -> V_10 [ V_2 -> V_13 ] . V_17 = 0 ;
V_2 -> V_18 = V_2 -> V_13 ;
}
if ( V_4 -> type == V_14 && V_4 -> V_15 == V_19 ) {
V_2 -> V_18 = V_2 -> V_11 ;
F_5 ( & V_2 -> V_20 , V_21 , V_22 ) ;
}
F_6 ( & V_2 -> V_9 ) ;
}
static void F_7 ( struct V_23 * V_24 ,
unsigned int type , unsigned int V_15 , int V_17 )
{
struct V_25 * V_25 = V_24 -> V_26 ;
struct V_1 * V_2 ;
struct V_3 V_4 ;
T_1 V_27 , V_28 ;
V_27 = F_8 () ;
V_28 = F_9 ( V_27 , F_10 () ) ;
V_4 . type = type ;
V_4 . V_15 = V_15 ;
V_4 . V_17 = V_17 ;
F_11 () ;
V_2 = F_12 ( V_25 -> V_29 ) ;
if ( V_2 )
F_1 ( V_2 , & V_4 , V_27 , V_28 ) ;
else
F_13 (client, &evdev->client_list, node)
F_1 ( V_2 , & V_4 , V_27 , V_28 ) ;
F_14 () ;
if ( type == V_14 && V_15 == V_19 )
F_15 ( & V_25 -> V_30 ) ;
}
static int F_16 ( int V_31 , struct V_32 * V_32 , int V_33 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
return F_17 ( V_31 , V_32 , V_33 , & V_2 -> V_20 ) ;
}
static int F_18 ( struct V_32 * V_32 , T_2 V_35 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
int V_36 ;
V_36 = F_19 ( & V_25 -> V_37 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_25 -> V_38 )
V_36 = - V_39 ;
else
V_36 = F_20 ( & V_25 -> V_24 , V_32 ) ;
F_21 ( & V_25 -> V_37 ) ;
return V_36 ;
}
static void F_22 ( struct V_40 * V_41 )
{
struct V_25 * V_25 = F_23 ( V_41 , struct V_25 , V_41 ) ;
F_24 ( V_25 -> V_24 . V_41 ) ;
F_25 ( V_25 ) ;
}
static int F_26 ( struct V_25 * V_25 , struct V_1 * V_2 )
{
int error ;
if ( V_25 -> V_29 )
return - V_42 ;
error = F_27 ( & V_25 -> V_24 ) ;
if ( error )
return error ;
F_28 ( V_25 -> V_29 , V_2 ) ;
return 0 ;
}
static int F_29 ( struct V_25 * V_25 , struct V_1 * V_2 )
{
if ( V_25 -> V_29 != V_2 )
return - V_43 ;
F_28 ( V_25 -> V_29 , NULL ) ;
F_30 () ;
F_31 ( & V_25 -> V_24 ) ;
return 0 ;
}
static void F_32 ( struct V_25 * V_25 ,
struct V_1 * V_2 )
{
F_3 ( & V_25 -> V_44 ) ;
F_33 ( & V_2 -> V_45 , & V_25 -> V_46 ) ;
F_6 ( & V_25 -> V_44 ) ;
}
static void F_34 ( struct V_25 * V_25 ,
struct V_1 * V_2 )
{
F_3 ( & V_25 -> V_44 ) ;
F_35 ( & V_2 -> V_45 ) ;
F_6 ( & V_25 -> V_44 ) ;
F_30 () ;
}
static int F_36 ( struct V_25 * V_25 )
{
int V_36 ;
V_36 = F_19 ( & V_25 -> V_37 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_25 -> V_38 )
V_36 = - V_39 ;
else if ( ! V_25 -> V_47 ++ ) {
V_36 = F_37 ( & V_25 -> V_24 ) ;
if ( V_36 )
V_25 -> V_47 -- ;
}
F_21 ( & V_25 -> V_37 ) ;
return V_36 ;
}
static void F_38 ( struct V_25 * V_25 )
{
F_39 ( & V_25 -> V_37 ) ;
if ( V_25 -> V_38 && ! -- V_25 -> V_47 )
F_40 ( & V_25 -> V_24 ) ;
F_21 ( & V_25 -> V_37 ) ;
}
static void F_41 ( struct V_25 * V_25 )
{
struct V_1 * V_2 ;
F_3 ( & V_25 -> V_44 ) ;
F_42 (client, &evdev->client_list, node)
F_5 ( & V_2 -> V_20 , V_21 , V_48 ) ;
F_6 ( & V_25 -> V_44 ) ;
F_15 ( & V_25 -> V_30 ) ;
}
static int F_43 ( struct V_49 * V_49 , struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
F_39 ( & V_25 -> V_37 ) ;
if ( V_25 -> V_29 == V_2 )
F_29 ( V_25 , V_2 ) ;
F_21 ( & V_25 -> V_37 ) ;
F_34 ( V_25 , V_2 ) ;
F_25 ( V_2 ) ;
F_38 ( V_25 ) ;
F_44 ( & V_25 -> V_41 ) ;
return 0 ;
}
static unsigned int F_45 ( struct V_50 * V_41 )
{
unsigned int V_51 =
F_46 ( V_41 -> V_52 * V_53 ,
V_54 ) ;
return F_47 ( V_51 ) ;
}
static int F_48 ( struct V_49 * V_49 , struct V_32 * V_32 )
{
struct V_25 * V_25 ;
struct V_1 * V_2 ;
int V_55 = F_49 ( V_49 ) - V_56 ;
unsigned int V_12 ;
int error ;
if ( V_55 >= V_57 )
return - V_39 ;
error = F_19 ( & V_58 ) ;
if ( error )
return error ;
V_25 = V_59 [ V_55 ] ;
if ( V_25 )
F_50 ( & V_25 -> V_41 ) ;
F_21 ( & V_58 ) ;
if ( ! V_25 )
return - V_39 ;
V_12 = F_45 ( V_25 -> V_24 . V_41 ) ;
V_2 = F_51 ( sizeof( struct V_1 ) +
V_12 * sizeof( struct V_3 ) ,
V_60 ) ;
if ( ! V_2 ) {
error = - V_61 ;
goto V_62;
}
V_2 -> V_12 = V_12 ;
F_52 ( & V_2 -> V_9 ) ;
V_2 -> V_25 = V_25 ;
F_32 ( V_25 , V_2 ) ;
error = F_36 ( V_25 ) ;
if ( error )
goto V_63;
V_32 -> V_34 = V_2 ;
F_53 ( V_49 , V_32 ) ;
return 0 ;
V_63:
F_34 ( V_25 , V_2 ) ;
F_25 ( V_2 ) ;
V_62:
F_44 ( & V_25 -> V_41 ) ;
return error ;
}
static T_3 F_54 ( struct V_32 * V_32 , const char T_4 * V_10 ,
T_5 V_64 , T_6 * V_65 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
struct V_3 V_4 ;
int V_36 = 0 ;
if ( V_64 < F_55 () )
return - V_43 ;
V_36 = F_19 ( & V_25 -> V_37 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_25 -> V_38 ) {
V_36 = - V_39 ;
goto V_66;
}
do {
if ( F_56 ( V_10 + V_36 , & V_4 ) ) {
V_36 = - V_67 ;
goto V_66;
}
V_36 += F_55 () ;
F_57 ( & V_25 -> V_24 ,
V_4 . type , V_4 . V_15 , V_4 . V_17 ) ;
} while ( V_36 + F_55 () <= V_64 );
V_66:
F_21 ( & V_25 -> V_37 ) ;
return V_36 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_68 ;
F_59 ( & V_2 -> V_9 ) ;
V_68 = V_2 -> V_18 != V_2 -> V_13 ;
if ( V_68 ) {
* V_4 = V_2 -> V_10 [ V_2 -> V_13 ++ ] ;
V_2 -> V_13 &= V_2 -> V_12 - 1 ;
}
F_60 ( & V_2 -> V_9 ) ;
return V_68 ;
}
static T_3 F_61 ( struct V_32 * V_32 , char T_4 * V_10 ,
T_5 V_64 , T_6 * V_65 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
struct V_3 V_4 ;
int V_36 = 0 ;
if ( V_64 < F_55 () )
return - V_43 ;
if ( ! ( V_32 -> V_69 & V_70 ) ) {
V_36 = F_62 ( V_25 -> V_30 ,
V_2 -> V_18 != V_2 -> V_13 ||
! V_25 -> V_38 ) ;
if ( V_36 )
return V_36 ;
}
if ( ! V_25 -> V_38 )
return - V_39 ;
while ( V_36 + F_55 () <= V_64 &&
F_58 ( V_2 , & V_4 ) ) {
if ( F_63 ( V_10 + V_36 , & V_4 ) )
return - V_67 ;
V_36 += F_55 () ;
}
if ( V_36 == 0 && ( V_32 -> V_69 & V_70 ) )
return - V_71 ;
return V_36 ;
}
static unsigned int F_64 ( struct V_32 * V_32 , T_7 * V_30 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
unsigned int V_72 ;
F_65 ( V_32 , & V_25 -> V_30 , V_30 ) ;
V_72 = V_25 -> V_38 ? V_73 | V_74 : V_75 | V_76 ;
if ( V_2 -> V_18 != V_2 -> V_13 )
V_72 |= V_77 | V_78 ;
return V_72 ;
}
static int F_66 ( unsigned long * V_79 , unsigned int V_80 ,
unsigned int V_81 , void T_4 * V_82 , int V_83 )
{
int V_84 , V_55 ;
if ( V_83 ) {
V_84 = F_67 ( V_80 ) * sizeof( V_85 ) ;
if ( V_84 > V_81 )
V_84 = V_81 ;
for ( V_55 = 0 ; V_55 < V_84 / sizeof( V_85 ) ; V_55 ++ )
if ( F_68 ( ( V_85 T_4 * ) V_82 + V_55 ,
( V_85 * ) V_79 +
V_55 + 1 - ( ( V_55 % 2 ) << 1 ) ,
sizeof( V_85 ) ) )
return - V_67 ;
} else {
V_84 = F_69 ( V_80 ) * sizeof( long ) ;
if ( V_84 > V_81 )
V_84 = V_81 ;
if ( F_68 ( V_82 , V_79 , V_84 ) )
return - V_67 ;
}
return V_84 ;
}
static int F_66 ( unsigned long * V_79 , unsigned int V_80 ,
unsigned int V_81 , void T_4 * V_82 , int V_83 )
{
int V_84 = V_83 ?
F_67 ( V_80 ) * sizeof( V_85 ) :
F_69 ( V_80 ) * sizeof( long ) ;
if ( V_84 > V_81 )
V_84 = V_81 ;
return F_68 ( V_82 , V_79 , V_84 ) ? - V_67 : V_84 ;
}
static int F_66 ( unsigned long * V_79 , unsigned int V_80 ,
unsigned int V_81 , void T_4 * V_82 , int V_83 )
{
int V_84 = F_69 ( V_80 ) * sizeof( long ) ;
if ( V_84 > V_81 )
V_84 = V_81 ;
return F_68 ( V_82 , V_79 , V_84 ) ? - V_67 : V_84 ;
}
static int F_70 ( const char * V_86 , unsigned int V_81 , void T_4 * V_82 )
{
int V_84 ;
if ( ! V_86 )
return - V_87 ;
V_84 = strlen ( V_86 ) + 1 ;
if ( V_84 > V_81 )
V_84 = V_81 ;
return F_68 ( V_82 , V_86 , V_84 ) ? - V_67 : V_84 ;
}
static int F_71 ( struct V_50 * V_41 ,
unsigned int type , unsigned int V_88 ,
void T_4 * V_82 , int V_89 )
{
static unsigned long V_90 ;
unsigned long * V_79 ;
int V_84 ;
switch ( type ) {
case 0 : V_79 = V_41 -> V_91 ; V_84 = V_92 ; break;
case V_93 : V_79 = V_41 -> V_94 ; V_84 = V_95 ; break;
case V_96 : V_79 = V_41 -> V_97 ; V_84 = V_98 ; break;
case V_99 : V_79 = V_41 -> V_100 ; V_84 = V_101 ; break;
case V_102 : V_79 = V_41 -> V_103 ; V_84 = V_104 ; break;
case V_105 : V_79 = V_41 -> V_106 ; V_84 = V_107 ; break;
case V_108 : V_79 = V_41 -> V_109 ; V_84 = V_110 ; break;
case V_111 : V_79 = V_41 -> V_112 ; V_84 = V_113 ; break;
case V_114 : V_79 = V_41 -> V_115 ; V_84 = V_116 ; break;
default: return - V_43 ;
}
if ( type == V_93 && V_88 == V_117 ) {
V_84 = V_117 ;
if ( F_72 ( & V_90 , 10 * 1000 ) )
F_73 ( L_1
L_2
L_3 ,
V_117 ,
F_69 ( V_117 ) * sizeof( long ) ) ;
}
return F_66 ( V_79 , V_84 , V_88 , V_82 , V_89 ) ;
}
static int F_74 ( struct V_50 * V_41 , void T_4 * V_82 )
{
struct V_118 V_119 = {
. V_84 = sizeof( unsigned int ) ,
. V_120 = 0 ,
} ;
int T_4 * V_121 = ( int T_4 * ) V_82 ;
int error ;
if ( F_75 ( V_119 . V_122 , V_82 , sizeof( unsigned int ) ) )
return - V_67 ;
error = F_76 ( V_41 , & V_119 ) ;
if ( error )
return error ;
if ( F_77 ( V_119 . V_123 , V_121 + 1 ) )
return - V_67 ;
return 0 ;
}
static int F_78 ( struct V_50 * V_41 , void T_4 * V_82 )
{
struct V_118 V_119 ;
int error ;
if ( F_75 ( & V_119 , V_82 , sizeof( V_119 ) ) )
return - V_67 ;
error = F_76 ( V_41 , & V_119 ) ;
if ( error )
return error ;
if ( F_68 ( V_82 , & V_119 , sizeof( V_119 ) ) )
return - V_67 ;
return 0 ;
}
static int F_79 ( struct V_50 * V_41 , void T_4 * V_82 )
{
struct V_118 V_119 = {
. V_84 = sizeof( unsigned int ) ,
. V_120 = 0 ,
} ;
int T_4 * V_121 = ( int T_4 * ) V_82 ;
if ( F_75 ( V_119 . V_122 , V_82 , sizeof( unsigned int ) ) )
return - V_67 ;
if ( F_80 ( V_119 . V_123 , V_121 + 1 ) )
return - V_67 ;
return F_81 ( V_41 , & V_119 ) ;
}
static int F_82 ( struct V_50 * V_41 , void T_4 * V_82 )
{
struct V_118 V_119 ;
if ( F_75 ( & V_119 , V_82 , sizeof( V_119 ) ) )
return - V_67 ;
if ( V_119 . V_84 > sizeof( V_119 . V_122 ) )
return - V_43 ;
return F_81 ( V_41 , & V_119 ) ;
}
static int F_83 ( struct V_50 * V_41 ,
unsigned int V_88 ,
int T_4 * V_121 )
{
const struct V_124 * V_125 = V_41 -> V_125 ;
unsigned int V_15 ;
int V_126 ;
int V_55 ;
if ( F_80 ( V_15 , & V_121 [ 0 ] ) )
return - V_67 ;
if ( ! F_84 ( V_15 ) )
return - V_43 ;
V_126 = ( V_88 - sizeof( V_127 ) ) / sizeof( V_128 ) ;
for ( V_55 = 0 ; V_55 < V_41 -> V_129 && V_55 < V_126 ; V_55 ++ )
if ( F_77 ( F_85 ( & V_125 [ V_55 ] , V_15 ) , & V_121 [ 1 + V_55 ] ) )
return - V_67 ;
return 0 ;
}
static long F_86 ( struct V_32 * V_32 , unsigned int V_130 ,
void T_4 * V_82 , int V_89 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
struct V_50 * V_41 = V_25 -> V_24 . V_41 ;
struct V_131 abs ;
struct V_132 V_133 ;
int T_4 * V_121 = ( int T_4 * ) V_82 ;
unsigned int V_55 , V_134 , V_135 , V_136 ;
unsigned int V_88 ;
int error ;
switch ( V_130 ) {
case V_137 :
return F_77 ( V_138 , V_121 ) ;
case V_139 :
if ( F_68 ( V_82 , & V_41 -> V_35 , sizeof( struct V_140 ) ) )
return - V_67 ;
return 0 ;
case V_141 :
if ( ! F_87 ( V_142 , V_41 -> V_91 ) )
return - V_143 ;
if ( F_77 ( V_41 -> V_144 [ V_145 ] , V_121 ) )
return - V_67 ;
if ( F_77 ( V_41 -> V_144 [ V_146 ] , V_121 + 1 ) )
return - V_67 ;
return 0 ;
case V_147 :
if ( ! F_87 ( V_142 , V_41 -> V_91 ) )
return - V_143 ;
if ( F_80 ( V_135 , V_121 ) )
return - V_67 ;
if ( F_80 ( V_136 , V_121 + 1 ) )
return - V_67 ;
F_57 ( & V_25 -> V_24 , V_142 , V_145 , V_135 ) ;
F_57 ( & V_25 -> V_24 , V_142 , V_146 , V_136 ) ;
return 0 ;
case V_148 :
return F_88 ( V_41 , ( int ) ( unsigned long ) V_82 , V_32 ) ;
case V_149 :
V_55 = F_87 ( V_111 , V_41 -> V_91 ) ?
V_41 -> V_150 -> V_151 : 0 ;
if ( F_77 ( V_55 , V_121 ) )
return - V_67 ;
return 0 ;
case V_152 :
if ( V_82 )
return F_26 ( V_25 , V_2 ) ;
else
return F_29 ( V_25 , V_2 ) ;
case V_153 :
if ( F_75 ( & V_55 , V_82 , sizeof( unsigned int ) ) )
return - V_67 ;
if ( V_55 != V_8 && V_55 != V_154 )
return - V_43 ;
V_2 -> V_7 = V_55 ;
return 0 ;
case V_155 :
return F_74 ( V_41 , V_82 ) ;
case V_156 :
return F_79 ( V_41 , V_82 ) ;
case V_157 :
return F_78 ( V_41 , V_82 ) ;
case V_158 :
return F_82 ( V_41 , V_82 ) ;
}
V_88 = F_89 ( V_130 ) ;
#define F_90 ( T_8 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_90 ( V_130 ) ) {
case F_91 ( 0 ) :
return F_66 ( V_41 -> V_159 , V_160 ,
V_88 , V_82 , V_89 ) ;
case F_92 ( 0 ) :
return F_83 ( V_41 , V_88 , V_121 ) ;
case F_93 ( 0 ) :
return F_66 ( V_41 -> V_161 , V_95 , V_88 , V_82 , V_89 ) ;
case F_94 ( 0 ) :
return F_66 ( V_41 -> V_162 , V_107 , V_88 , V_82 , V_89 ) ;
case F_95 ( 0 ) :
return F_66 ( V_41 -> V_163 , V_110 , V_88 , V_82 , V_89 ) ;
case F_96 ( 0 ) :
return F_66 ( V_41 -> V_164 , V_116 , V_88 , V_82 , V_89 ) ;
case F_97 ( 0 ) :
return F_70 ( V_41 -> V_165 , V_88 , V_82 ) ;
case F_98 ( 0 ) :
return F_70 ( V_41 -> V_166 , V_88 , V_82 ) ;
case F_99 ( 0 ) :
return F_70 ( V_41 -> V_167 , V_88 , V_82 ) ;
case F_90 ( V_168 ) :
if ( F_100 ( V_82 , V_88 , & V_133 ) )
return - V_67 ;
error = F_101 ( V_41 , & V_133 , V_32 ) ;
if ( F_77 ( V_133 . V_35 , & ( ( (struct V_132 T_4 * ) V_82 ) -> V_35 ) ) )
return - V_67 ;
return error ;
}
if ( F_102 ( V_130 ) != 'E' )
return - V_43 ;
if ( F_103 ( V_130 ) == V_169 ) {
if ( ( F_104 ( V_130 ) & ~ V_92 ) == F_104 ( F_105 ( 0 , 0 ) ) )
return F_71 ( V_41 ,
F_104 ( V_130 ) & V_92 , V_88 ,
V_82 , V_89 ) ;
if ( ( F_104 ( V_130 ) & ~ V_101 ) == F_104 ( F_106 ( 0 ) ) ) {
if ( ! V_41 -> V_170 )
return - V_43 ;
V_134 = F_104 ( V_130 ) & V_101 ;
abs = V_41 -> V_170 [ V_134 ] ;
if ( F_68 ( V_82 , & abs , F_107 ( T_5 ,
V_88 , sizeof( struct V_131 ) ) ) )
return - V_67 ;
return 0 ;
}
}
if ( F_103 ( V_130 ) == V_171 ) {
if ( ( F_104 ( V_130 ) & ~ V_101 ) == F_104 ( F_108 ( 0 ) ) ) {
if ( ! V_41 -> V_170 )
return - V_43 ;
V_134 = F_104 ( V_130 ) & V_101 ;
if ( F_75 ( & abs , V_82 , F_107 ( T_5 ,
V_88 , sizeof( struct V_131 ) ) ) )
return - V_67 ;
if ( V_88 < sizeof( struct V_131 ) )
abs . V_172 = 0 ;
if ( V_134 == V_173 )
return - V_43 ;
F_59 ( & V_41 -> V_174 ) ;
V_41 -> V_170 [ V_134 ] = abs ;
F_60 ( & V_41 -> V_174 ) ;
return 0 ;
}
}
return - V_43 ;
}
static long F_109 ( struct V_32 * V_32 , unsigned int V_130 ,
void T_4 * V_82 , int V_89 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
int V_36 ;
V_36 = F_19 ( & V_25 -> V_37 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_25 -> V_38 ) {
V_36 = - V_39 ;
goto V_66;
}
V_36 = F_86 ( V_32 , V_130 , V_82 , V_89 ) ;
V_66:
F_21 ( & V_25 -> V_37 ) ;
return V_36 ;
}
static long F_110 ( struct V_32 * V_32 , unsigned int V_130 , unsigned long V_175 )
{
return F_109 ( V_32 , V_130 , ( void T_4 * ) V_175 , 0 ) ;
}
static long F_111 ( struct V_32 * V_32 ,
unsigned int V_130 , unsigned long V_175 )
{
return F_109 ( V_32 , V_130 , F_112 ( V_175 ) , 1 ) ;
}
static int F_113 ( struct V_25 * V_25 )
{
V_59 [ V_25 -> V_176 ] = V_25 ;
return 0 ;
}
static void F_114 ( struct V_25 * V_25 )
{
F_39 ( & V_58 ) ;
V_59 [ V_25 -> V_176 ] = NULL ;
F_21 ( & V_58 ) ;
}
static void F_115 ( struct V_25 * V_25 )
{
F_39 ( & V_25 -> V_37 ) ;
V_25 -> V_38 = false ;
F_21 ( & V_25 -> V_37 ) ;
}
static void F_116 ( struct V_25 * V_25 )
{
struct V_23 * V_24 = & V_25 -> V_24 ;
F_115 ( V_25 ) ;
F_41 ( V_25 ) ;
F_114 ( V_25 ) ;
if ( V_25 -> V_47 ) {
F_20 ( V_24 , NULL ) ;
F_40 ( V_24 ) ;
}
}
static int F_117 ( struct V_177 * V_178 , struct V_50 * V_41 ,
const struct V_179 * V_35 )
{
struct V_25 * V_25 ;
int V_176 ;
int error ;
for ( V_176 = 0 ; V_176 < V_57 ; V_176 ++ )
if ( ! V_59 [ V_176 ] )
break;
if ( V_176 == V_57 ) {
F_118 ( L_4 ) ;
return - V_180 ;
}
V_25 = F_51 ( sizeof( struct V_25 ) , V_60 ) ;
if ( ! V_25 )
return - V_61 ;
F_119 ( & V_25 -> V_46 ) ;
F_52 ( & V_25 -> V_44 ) ;
F_120 ( & V_25 -> V_37 ) ;
F_121 ( & V_25 -> V_30 ) ;
F_122 ( & V_25 -> V_41 , L_5 , V_176 ) ;
V_25 -> V_38 = true ;
V_25 -> V_176 = V_176 ;
V_25 -> V_24 . V_41 = F_123 ( V_41 ) ;
V_25 -> V_24 . V_165 = F_124 ( & V_25 -> V_41 ) ;
V_25 -> V_24 . V_178 = V_178 ;
V_25 -> V_24 . V_26 = V_25 ;
V_25 -> V_41 . V_181 = F_125 ( V_182 , V_56 + V_176 ) ;
V_25 -> V_41 . V_183 = & V_184 ;
V_25 -> V_41 . V_185 = & V_41 -> V_41 ;
V_25 -> V_41 . V_186 = F_22 ;
F_126 ( & V_25 -> V_41 ) ;
error = F_127 ( & V_25 -> V_24 ) ;
if ( error )
goto V_187;
error = F_113 ( V_25 ) ;
if ( error )
goto V_188;
error = F_128 ( & V_25 -> V_41 ) ;
if ( error )
goto V_189;
return 0 ;
V_189:
F_116 ( V_25 ) ;
V_188:
F_129 ( & V_25 -> V_24 ) ;
V_187:
F_44 ( & V_25 -> V_41 ) ;
return error ;
}
static void F_130 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = V_24 -> V_26 ;
F_131 ( & V_25 -> V_41 ) ;
F_116 ( V_25 ) ;
F_129 ( V_24 ) ;
F_44 ( & V_25 -> V_41 ) ;
}
static int T_9 F_132 ( void )
{
return F_133 ( & V_190 ) ;
}
static void T_10 F_134 ( void )
{
F_135 ( & V_190 ) ;
}
