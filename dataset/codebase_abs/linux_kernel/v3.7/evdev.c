static void F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
V_2 -> V_5 [ V_2 -> V_6 ++ ] = * V_4 ;
V_2 -> V_6 &= V_2 -> V_7 - 1 ;
if ( F_2 ( V_2 -> V_6 == V_2 -> V_8 ) ) {
V_2 -> V_8 = ( V_2 -> V_6 - 2 ) & ( V_2 -> V_7 - 1 ) ;
V_2 -> V_5 [ V_2 -> V_8 ] . time = V_4 -> time ;
V_2 -> V_5 [ V_2 -> V_8 ] . type = V_9 ;
V_2 -> V_5 [ V_2 -> V_8 ] . V_10 = V_11 ;
V_2 -> V_5 [ V_2 -> V_8 ] . V_12 = 0 ;
V_2 -> V_13 = V_2 -> V_8 ;
}
if ( V_4 -> type == V_9 && V_4 -> V_10 == V_14 ) {
V_2 -> V_13 = V_2 -> V_6 ;
F_3 ( & V_2 -> V_15 , V_16 , V_17 ) ;
}
}
static void F_4 ( struct V_1 * V_2 ,
const struct V_18 * V_19 , unsigned int V_20 ,
T_1 V_21 , T_1 V_22 )
{
struct V_23 * V_23 = V_2 -> V_23 ;
const struct V_18 * V_24 ;
struct V_3 V_4 ;
bool V_25 = false ;
V_4 . time = F_5 ( V_2 -> V_26 == V_27 ?
V_21 : V_22 ) ;
F_6 ( & V_2 -> V_28 ) ;
for ( V_24 = V_19 ; V_24 != V_19 + V_20 ; V_24 ++ ) {
V_4 . type = V_24 -> type ;
V_4 . V_10 = V_24 -> V_10 ;
V_4 . V_12 = V_24 -> V_12 ;
F_1 ( V_2 , & V_4 ) ;
if ( V_24 -> type == V_9 && V_24 -> V_10 == V_14 )
V_25 = true ;
}
F_7 ( & V_2 -> V_28 ) ;
if ( V_25 )
F_8 ( & V_23 -> V_29 ) ;
}
static void F_9 ( struct V_30 * V_31 ,
const struct V_18 * V_19 , unsigned int V_20 )
{
struct V_23 * V_23 = V_31 -> V_32 ;
struct V_1 * V_2 ;
T_1 V_33 , V_34 ;
V_33 = F_10 () ;
V_34 = F_11 ( V_33 , F_12 () ) ;
F_13 () ;
V_2 = F_14 ( V_23 -> V_35 ) ;
if ( V_2 )
F_4 ( V_2 , V_19 , V_20 , V_33 , V_34 ) ;
else
F_15 (client, &evdev->client_list, node)
F_4 ( V_2 , V_19 , V_20 ,
V_33 , V_34 ) ;
F_16 () ;
}
static void F_17 ( struct V_30 * V_31 ,
unsigned int type , unsigned int V_10 , int V_12 )
{
struct V_18 V_19 [] = { { type , V_10 , V_12 } } ;
F_9 ( V_31 , V_19 , 1 ) ;
}
static int F_18 ( int V_36 , struct V_37 * V_37 , int V_38 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
return F_19 ( V_36 , V_37 , V_38 , & V_2 -> V_15 ) ;
}
static int F_20 ( struct V_37 * V_37 , T_2 V_40 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_23 * V_23 = V_2 -> V_23 ;
int V_41 ;
V_41 = F_21 ( & V_23 -> V_42 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_23 -> V_43 )
V_41 = - V_44 ;
else
V_41 = F_22 ( & V_23 -> V_31 , V_37 ) ;
F_23 ( & V_23 -> V_42 ) ;
return V_41 ;
}
static void F_24 ( struct V_45 * V_46 )
{
struct V_23 * V_23 = F_25 ( V_46 , struct V_23 , V_46 ) ;
F_26 ( V_23 -> V_31 . V_46 ) ;
F_27 ( V_23 ) ;
}
static int F_28 ( struct V_23 * V_23 , struct V_1 * V_2 )
{
int error ;
if ( V_23 -> V_35 )
return - V_47 ;
error = F_29 ( & V_23 -> V_31 ) ;
if ( error )
return error ;
F_30 ( V_23 -> V_35 , V_2 ) ;
return 0 ;
}
static int F_31 ( struct V_23 * V_23 , struct V_1 * V_2 )
{
struct V_1 * V_35 = F_32 ( V_23 -> V_35 ,
F_33 ( & V_23 -> V_42 ) ) ;
if ( V_35 != V_2 )
return - V_48 ;
F_30 ( V_23 -> V_35 , NULL ) ;
F_34 () ;
F_35 ( & V_23 -> V_31 ) ;
return 0 ;
}
static void F_36 ( struct V_23 * V_23 ,
struct V_1 * V_2 )
{
F_6 ( & V_23 -> V_49 ) ;
F_37 ( & V_2 -> V_50 , & V_23 -> V_51 ) ;
F_7 ( & V_23 -> V_49 ) ;
}
static void F_38 ( struct V_23 * V_23 ,
struct V_1 * V_2 )
{
F_6 ( & V_23 -> V_49 ) ;
F_39 ( & V_2 -> V_50 ) ;
F_7 ( & V_23 -> V_49 ) ;
F_34 () ;
}
static int F_40 ( struct V_23 * V_23 )
{
int V_41 ;
V_41 = F_21 ( & V_23 -> V_42 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_23 -> V_43 )
V_41 = - V_44 ;
else if ( ! V_23 -> V_52 ++ ) {
V_41 = F_41 ( & V_23 -> V_31 ) ;
if ( V_41 )
V_23 -> V_52 -- ;
}
F_23 ( & V_23 -> V_42 ) ;
return V_41 ;
}
static void F_42 ( struct V_23 * V_23 )
{
F_43 ( & V_23 -> V_42 ) ;
if ( V_23 -> V_43 && ! -- V_23 -> V_52 )
F_44 ( & V_23 -> V_31 ) ;
F_23 ( & V_23 -> V_42 ) ;
}
static void F_45 ( struct V_23 * V_23 )
{
struct V_1 * V_2 ;
F_6 ( & V_23 -> V_49 ) ;
F_46 (client, &evdev->client_list, node)
F_3 ( & V_2 -> V_15 , V_16 , V_53 ) ;
F_7 ( & V_23 -> V_49 ) ;
F_8 ( & V_23 -> V_29 ) ;
}
static int F_47 ( struct V_54 * V_54 , struct V_37 * V_37 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_23 * V_23 = V_2 -> V_23 ;
F_43 ( & V_23 -> V_42 ) ;
F_31 ( V_23 , V_2 ) ;
F_23 ( & V_23 -> V_42 ) ;
F_38 ( V_23 , V_2 ) ;
F_27 ( V_2 ) ;
F_42 ( V_23 ) ;
return 0 ;
}
static unsigned int F_48 ( struct V_55 * V_46 )
{
unsigned int V_56 =
F_49 ( V_46 -> V_57 * V_58 ,
V_59 ) ;
return F_50 ( V_56 ) ;
}
static int F_51 ( struct V_54 * V_54 , struct V_37 * V_37 )
{
struct V_23 * V_23 = F_25 ( V_54 -> V_60 , struct V_23 , V_61 ) ;
unsigned int V_7 = F_48 ( V_23 -> V_31 . V_46 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_52 ( sizeof( struct V_1 ) +
V_7 * sizeof( struct V_3 ) ,
V_62 ) ;
if ( ! V_2 )
return - V_63 ;
V_2 -> V_7 = V_7 ;
F_53 ( & V_2 -> V_28 ) ;
V_2 -> V_23 = V_23 ;
F_36 ( V_23 , V_2 ) ;
error = F_40 ( V_23 ) ;
if ( error )
goto V_64;
V_37 -> V_39 = V_2 ;
F_54 ( V_54 , V_37 ) ;
return 0 ;
V_64:
F_38 ( V_23 , V_2 ) ;
F_27 ( V_2 ) ;
return error ;
}
static T_3 F_55 ( struct V_37 * V_37 , const char T_4 * V_5 ,
T_5 V_20 , T_6 * V_65 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_23 * V_23 = V_2 -> V_23 ;
struct V_3 V_4 ;
int V_41 = 0 ;
if ( V_20 != 0 && V_20 < F_56 () )
return - V_48 ;
V_41 = F_21 ( & V_23 -> V_42 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_23 -> V_43 ) {
V_41 = - V_44 ;
goto V_66;
}
while ( V_41 + F_56 () <= V_20 ) {
if ( F_57 ( V_5 + V_41 , & V_4 ) ) {
V_41 = - V_67 ;
goto V_66;
}
V_41 += F_56 () ;
F_58 ( & V_23 -> V_31 ,
V_4 . type , V_4 . V_10 , V_4 . V_12 ) ;
}
V_66:
F_23 ( & V_23 -> V_42 ) ;
return V_41 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_68 ;
F_60 ( & V_2 -> V_28 ) ;
V_68 = V_2 -> V_13 != V_2 -> V_8 ;
if ( V_68 ) {
* V_4 = V_2 -> V_5 [ V_2 -> V_8 ++ ] ;
V_2 -> V_8 &= V_2 -> V_7 - 1 ;
}
F_61 ( & V_2 -> V_28 ) ;
return V_68 ;
}
static T_3 F_62 ( struct V_37 * V_37 , char T_4 * V_5 ,
T_5 V_20 , T_6 * V_65 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_23 * V_23 = V_2 -> V_23 ;
struct V_3 V_4 ;
T_5 V_69 = 0 ;
int error ;
if ( V_20 != 0 && V_20 < F_56 () )
return - V_48 ;
for (; ; ) {
if ( ! V_23 -> V_43 )
return - V_44 ;
if ( V_2 -> V_13 == V_2 -> V_8 &&
( V_37 -> V_70 & V_71 ) )
return - V_72 ;
if ( V_20 == 0 )
break;
while ( V_69 + F_56 () <= V_20 &&
F_59 ( V_2 , & V_4 ) ) {
if ( F_63 ( V_5 + V_69 , & V_4 ) )
return - V_67 ;
V_69 += F_56 () ;
}
if ( V_69 )
break;
if ( ! ( V_37 -> V_70 & V_71 ) ) {
error = F_64 ( V_23 -> V_29 ,
V_2 -> V_13 != V_2 -> V_8 ||
! V_23 -> V_43 ) ;
if ( error )
return error ;
}
}
return V_69 ;
}
static unsigned int F_65 ( struct V_37 * V_37 , T_7 * V_29 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_23 * V_23 = V_2 -> V_23 ;
unsigned int V_73 ;
F_66 ( V_37 , & V_23 -> V_29 , V_29 ) ;
V_73 = V_23 -> V_43 ? V_74 | V_75 : V_76 | V_77 ;
if ( V_2 -> V_13 != V_2 -> V_8 )
V_73 |= V_78 | V_79 ;
return V_73 ;
}
static int F_67 ( unsigned long * V_80 , unsigned int V_81 ,
unsigned int V_82 , void T_4 * V_83 , int V_84 )
{
int V_85 , V_86 ;
if ( V_84 ) {
V_85 = F_68 ( V_81 ) * sizeof( V_87 ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
for ( V_86 = 0 ; V_86 < V_85 / sizeof( V_87 ) ; V_86 ++ )
if ( F_69 ( ( V_87 T_4 * ) V_83 + V_86 ,
( V_87 * ) V_80 +
V_86 + 1 - ( ( V_86 % 2 ) << 1 ) ,
sizeof( V_87 ) ) )
return - V_67 ;
} else {
V_85 = F_70 ( V_81 ) * sizeof( long ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
if ( F_69 ( V_83 , V_80 , V_85 ) )
return - V_67 ;
}
return V_85 ;
}
static int F_67 ( unsigned long * V_80 , unsigned int V_81 ,
unsigned int V_82 , void T_4 * V_83 , int V_84 )
{
int V_85 = V_84 ?
F_68 ( V_81 ) * sizeof( V_87 ) :
F_70 ( V_81 ) * sizeof( long ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
return F_69 ( V_83 , V_80 , V_85 ) ? - V_67 : V_85 ;
}
static int F_67 ( unsigned long * V_80 , unsigned int V_81 ,
unsigned int V_82 , void T_4 * V_83 , int V_84 )
{
int V_85 = F_70 ( V_81 ) * sizeof( long ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
return F_69 ( V_83 , V_80 , V_85 ) ? - V_67 : V_85 ;
}
static int F_71 ( const char * V_88 , unsigned int V_82 , void T_4 * V_83 )
{
int V_85 ;
if ( ! V_88 )
return - V_89 ;
V_85 = strlen ( V_88 ) + 1 ;
if ( V_85 > V_82 )
V_85 = V_82 ;
return F_69 ( V_83 , V_88 , V_85 ) ? - V_67 : V_85 ;
}
static int F_72 ( struct V_55 * V_46 ,
unsigned int type , unsigned int V_90 ,
void T_4 * V_83 , int V_91 )
{
static unsigned long V_92 ;
unsigned long * V_80 ;
int V_85 ;
switch ( type ) {
case 0 : V_80 = V_46 -> V_93 ; V_85 = V_94 ; break;
case V_95 : V_80 = V_46 -> V_96 ; V_85 = V_97 ; break;
case V_98 : V_80 = V_46 -> V_99 ; V_85 = V_100 ; break;
case V_101 : V_80 = V_46 -> V_102 ; V_85 = V_103 ; break;
case V_104 : V_80 = V_46 -> V_105 ; V_85 = V_106 ; break;
case V_107 : V_80 = V_46 -> V_108 ; V_85 = V_109 ; break;
case V_110 : V_80 = V_46 -> V_111 ; V_85 = V_112 ; break;
case V_113 : V_80 = V_46 -> V_114 ; V_85 = V_115 ; break;
case V_116 : V_80 = V_46 -> V_117 ; V_85 = V_118 ; break;
default: return - V_48 ;
}
if ( type == V_95 && V_90 == V_119 ) {
V_85 = V_119 ;
if ( F_73 ( & V_92 , 10 * 1000 ) )
F_74 ( L_1
L_2
L_3 ,
V_119 ,
F_70 ( V_119 ) * sizeof( long ) ) ;
}
return F_67 ( V_80 , V_85 , V_90 , V_83 , V_91 ) ;
}
static int F_75 ( struct V_55 * V_46 , void T_4 * V_83 )
{
struct V_120 V_121 = {
. V_85 = sizeof( unsigned int ) ,
. V_122 = 0 ,
} ;
int T_4 * V_123 = ( int T_4 * ) V_83 ;
int error ;
if ( F_76 ( V_121 . V_124 , V_83 , sizeof( unsigned int ) ) )
return - V_67 ;
error = F_77 ( V_46 , & V_121 ) ;
if ( error )
return error ;
if ( F_78 ( V_121 . V_125 , V_123 + 1 ) )
return - V_67 ;
return 0 ;
}
static int F_79 ( struct V_55 * V_46 , void T_4 * V_83 )
{
struct V_120 V_121 ;
int error ;
if ( F_76 ( & V_121 , V_83 , sizeof( V_121 ) ) )
return - V_67 ;
error = F_77 ( V_46 , & V_121 ) ;
if ( error )
return error ;
if ( F_69 ( V_83 , & V_121 , sizeof( V_121 ) ) )
return - V_67 ;
return 0 ;
}
static int F_80 ( struct V_55 * V_46 , void T_4 * V_83 )
{
struct V_120 V_121 = {
. V_85 = sizeof( unsigned int ) ,
. V_122 = 0 ,
} ;
int T_4 * V_123 = ( int T_4 * ) V_83 ;
if ( F_76 ( V_121 . V_124 , V_83 , sizeof( unsigned int ) ) )
return - V_67 ;
if ( F_81 ( V_121 . V_125 , V_123 + 1 ) )
return - V_67 ;
return F_82 ( V_46 , & V_121 ) ;
}
static int F_83 ( struct V_55 * V_46 , void T_4 * V_83 )
{
struct V_120 V_121 ;
if ( F_76 ( & V_121 , V_83 , sizeof( V_121 ) ) )
return - V_67 ;
if ( V_121 . V_85 > sizeof( V_121 . V_124 ) )
return - V_48 ;
return F_82 ( V_46 , & V_121 ) ;
}
static int F_84 ( struct V_55 * V_46 ,
unsigned int V_90 ,
int T_4 * V_123 )
{
const struct V_126 * V_127 = V_46 -> V_127 ;
unsigned int V_10 ;
int V_128 ;
int V_86 ;
if ( F_81 ( V_10 , & V_123 [ 0 ] ) )
return - V_67 ;
if ( ! V_127 || ! F_85 ( V_10 ) )
return - V_48 ;
V_128 = ( V_90 - sizeof( V_129 ) ) / sizeof( V_130 ) ;
for ( V_86 = 0 ; V_86 < V_127 -> V_131 && V_86 < V_128 ; V_86 ++ ) {
int V_12 = F_86 ( & V_127 -> V_132 [ V_86 ] , V_10 ) ;
if ( F_78 ( V_12 , & V_123 [ 1 + V_86 ] ) )
return - V_67 ;
}
return 0 ;
}
static long F_87 ( struct V_37 * V_37 , unsigned int V_133 ,
void T_4 * V_83 , int V_91 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_23 * V_23 = V_2 -> V_23 ;
struct V_55 * V_46 = V_23 -> V_31 . V_46 ;
struct V_134 abs ;
struct V_135 V_136 ;
int T_4 * V_123 = ( int T_4 * ) V_83 ;
unsigned int V_86 , V_137 , V_138 , V_24 ;
unsigned int V_90 ;
int error ;
switch ( V_133 ) {
case V_139 :
return F_78 ( V_140 , V_123 ) ;
case V_141 :
if ( F_69 ( V_83 , & V_46 -> V_40 , sizeof( struct V_142 ) ) )
return - V_67 ;
return 0 ;
case V_143 :
if ( ! F_88 ( V_144 , V_46 -> V_93 ) )
return - V_145 ;
if ( F_78 ( V_46 -> V_146 [ V_147 ] , V_123 ) )
return - V_67 ;
if ( F_78 ( V_46 -> V_146 [ V_148 ] , V_123 + 1 ) )
return - V_67 ;
return 0 ;
case V_149 :
if ( ! F_88 ( V_144 , V_46 -> V_93 ) )
return - V_145 ;
if ( F_81 ( V_138 , V_123 ) )
return - V_67 ;
if ( F_81 ( V_24 , V_123 + 1 ) )
return - V_67 ;
F_58 ( & V_23 -> V_31 , V_144 , V_147 , V_138 ) ;
F_58 ( & V_23 -> V_31 , V_144 , V_148 , V_24 ) ;
return 0 ;
case V_150 :
return F_89 ( V_46 , ( int ) ( unsigned long ) V_83 , V_37 ) ;
case V_151 :
V_86 = F_88 ( V_113 , V_46 -> V_93 ) ?
V_46 -> V_152 -> V_153 : 0 ;
if ( F_78 ( V_86 , V_123 ) )
return - V_67 ;
return 0 ;
case V_154 :
if ( V_83 )
return F_28 ( V_23 , V_2 ) ;
else
return F_31 ( V_23 , V_2 ) ;
case V_155 :
if ( F_76 ( & V_86 , V_83 , sizeof( unsigned int ) ) )
return - V_67 ;
if ( V_86 != V_27 && V_86 != V_156 )
return - V_48 ;
V_2 -> V_26 = V_86 ;
return 0 ;
case V_157 :
return F_75 ( V_46 , V_83 ) ;
case V_158 :
return F_80 ( V_46 , V_83 ) ;
case V_159 :
return F_79 ( V_46 , V_83 ) ;
case V_160 :
return F_83 ( V_46 , V_83 ) ;
}
V_90 = F_90 ( V_133 ) ;
#define F_91 ( T_8 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_91 ( V_133 ) ) {
case F_92 ( 0 ) :
return F_67 ( V_46 -> V_161 , V_162 ,
V_90 , V_83 , V_91 ) ;
case F_93 ( 0 ) :
return F_84 ( V_46 , V_90 , V_123 ) ;
case F_94 ( 0 ) :
return F_67 ( V_46 -> V_163 , V_97 , V_90 , V_83 , V_91 ) ;
case F_95 ( 0 ) :
return F_67 ( V_46 -> V_164 , V_109 , V_90 , V_83 , V_91 ) ;
case F_96 ( 0 ) :
return F_67 ( V_46 -> V_165 , V_112 , V_90 , V_83 , V_91 ) ;
case F_97 ( 0 ) :
return F_67 ( V_46 -> V_166 , V_118 , V_90 , V_83 , V_91 ) ;
case F_98 ( 0 ) :
return F_71 ( V_46 -> V_167 , V_90 , V_83 ) ;
case F_99 ( 0 ) :
return F_71 ( V_46 -> V_168 , V_90 , V_83 ) ;
case F_100 ( 0 ) :
return F_71 ( V_46 -> V_169 , V_90 , V_83 ) ;
case F_91 ( V_170 ) :
if ( F_101 ( V_83 , V_90 , & V_136 ) )
return - V_67 ;
error = F_102 ( V_46 , & V_136 , V_37 ) ;
if ( F_78 ( V_136 . V_40 , & ( ( (struct V_135 T_4 * ) V_83 ) -> V_40 ) ) )
return - V_67 ;
return error ;
}
if ( F_103 ( V_133 ) != 'E' )
return - V_48 ;
if ( F_104 ( V_133 ) == V_171 ) {
if ( ( F_105 ( V_133 ) & ~ V_94 ) == F_105 ( F_106 ( 0 , 0 ) ) )
return F_72 ( V_46 ,
F_105 ( V_133 ) & V_94 , V_90 ,
V_83 , V_91 ) ;
if ( ( F_105 ( V_133 ) & ~ V_103 ) == F_105 ( F_107 ( 0 ) ) ) {
if ( ! V_46 -> V_172 )
return - V_48 ;
V_137 = F_105 ( V_133 ) & V_103 ;
abs = V_46 -> V_172 [ V_137 ] ;
if ( F_69 ( V_83 , & abs , F_108 ( T_5 ,
V_90 , sizeof( struct V_134 ) ) ) )
return - V_67 ;
return 0 ;
}
}
if ( F_104 ( V_133 ) == V_173 ) {
if ( ( F_105 ( V_133 ) & ~ V_103 ) == F_105 ( F_109 ( 0 ) ) ) {
if ( ! V_46 -> V_172 )
return - V_48 ;
V_137 = F_105 ( V_133 ) & V_103 ;
if ( F_76 ( & abs , V_83 , F_108 ( T_5 ,
V_90 , sizeof( struct V_134 ) ) ) )
return - V_67 ;
if ( V_90 < sizeof( struct V_134 ) )
abs . V_174 = 0 ;
if ( V_137 == V_175 )
return - V_48 ;
F_60 ( & V_46 -> V_176 ) ;
V_46 -> V_172 [ V_137 ] = abs ;
F_61 ( & V_46 -> V_176 ) ;
return 0 ;
}
}
return - V_48 ;
}
static long F_110 ( struct V_37 * V_37 , unsigned int V_133 ,
void T_4 * V_83 , int V_91 )
{
struct V_1 * V_2 = V_37 -> V_39 ;
struct V_23 * V_23 = V_2 -> V_23 ;
int V_41 ;
V_41 = F_21 ( & V_23 -> V_42 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_23 -> V_43 ) {
V_41 = - V_44 ;
goto V_66;
}
V_41 = F_87 ( V_37 , V_133 , V_83 , V_91 ) ;
V_66:
F_23 ( & V_23 -> V_42 ) ;
return V_41 ;
}
static long F_111 ( struct V_37 * V_37 , unsigned int V_133 , unsigned long V_177 )
{
return F_110 ( V_37 , V_133 , ( void T_4 * ) V_177 , 0 ) ;
}
static long F_112 ( struct V_37 * V_37 ,
unsigned int V_133 , unsigned long V_177 )
{
return F_110 ( V_37 , V_133 , F_113 ( V_177 ) , 1 ) ;
}
static void F_114 ( struct V_23 * V_23 )
{
F_43 ( & V_23 -> V_42 ) ;
V_23 -> V_43 = false ;
F_23 ( & V_23 -> V_42 ) ;
}
static void F_115 ( struct V_23 * V_23 )
{
struct V_30 * V_31 = & V_23 -> V_31 ;
F_114 ( V_23 ) ;
F_45 ( V_23 ) ;
F_116 ( & V_23 -> V_61 ) ;
if ( V_23 -> V_52 ) {
F_22 ( V_31 , NULL ) ;
F_44 ( V_31 ) ;
}
}
static int F_117 ( struct V_178 * V_179 , struct V_55 * V_46 ,
const struct V_180 * V_40 )
{
struct V_23 * V_23 ;
int V_181 ;
int V_182 ;
int error ;
V_181 = F_118 ( V_183 , V_184 , true ) ;
if ( V_181 < 0 ) {
error = V_181 ;
F_119 ( L_4 , error ) ;
return error ;
}
V_23 = F_52 ( sizeof( struct V_23 ) , V_62 ) ;
if ( ! V_23 ) {
error = - V_63 ;
goto V_185;
}
F_120 ( & V_23 -> V_51 ) ;
F_53 ( & V_23 -> V_49 ) ;
F_121 ( & V_23 -> V_42 ) ;
F_122 ( & V_23 -> V_29 ) ;
V_23 -> V_43 = true ;
V_182 = V_181 ;
if ( V_182 < V_183 + V_184 )
V_182 -= V_183 ;
F_123 ( & V_23 -> V_46 , L_5 , V_182 ) ;
V_23 -> V_31 . V_46 = F_124 ( V_46 ) ;
V_23 -> V_31 . V_167 = F_125 ( & V_23 -> V_46 ) ;
V_23 -> V_31 . V_179 = V_179 ;
V_23 -> V_31 . V_32 = V_23 ;
V_23 -> V_46 . V_186 = F_126 ( V_187 , V_181 ) ;
V_23 -> V_46 . V_188 = & V_189 ;
V_23 -> V_46 . V_190 = & V_46 -> V_46 ;
V_23 -> V_46 . V_191 = F_24 ;
F_127 ( & V_23 -> V_46 ) ;
error = F_128 ( & V_23 -> V_31 ) ;
if ( error )
goto V_192;
F_129 ( & V_23 -> V_61 , & V_193 ) ;
V_23 -> V_61 . V_194 . V_190 = & V_23 -> V_46 . V_194 ;
error = F_130 ( & V_23 -> V_61 , V_23 -> V_46 . V_186 , 1 ) ;
if ( error )
goto V_195;
error = F_131 ( & V_23 -> V_46 ) ;
if ( error )
goto V_196;
return 0 ;
V_196:
F_115 ( V_23 ) ;
V_195:
F_132 ( & V_23 -> V_31 ) ;
V_192:
F_133 ( & V_23 -> V_46 ) ;
V_185:
F_134 ( V_181 ) ;
return error ;
}
static void F_135 ( struct V_30 * V_31 )
{
struct V_23 * V_23 = V_31 -> V_32 ;
F_136 ( & V_23 -> V_46 ) ;
F_115 ( V_23 ) ;
F_134 ( F_137 ( V_23 -> V_46 . V_186 ) ) ;
F_132 ( V_31 ) ;
F_133 ( & V_23 -> V_46 ) ;
}
static int T_9 F_138 ( void )
{
return F_139 ( & V_197 ) ;
}
static void T_10 F_140 ( void )
{
F_141 ( & V_197 ) ;
}
