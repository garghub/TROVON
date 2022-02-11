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
struct V_1 * V_29 = F_30 ( V_25 -> V_29 ,
F_31 ( & V_25 -> V_37 ) ) ;
if ( V_29 != V_2 )
return - V_43 ;
F_28 ( V_25 -> V_29 , NULL ) ;
F_32 () ;
F_33 ( & V_25 -> V_24 ) ;
return 0 ;
}
static void F_34 ( struct V_25 * V_25 ,
struct V_1 * V_2 )
{
F_3 ( & V_25 -> V_44 ) ;
F_35 ( & V_2 -> V_45 , & V_25 -> V_46 ) ;
F_6 ( & V_25 -> V_44 ) ;
}
static void F_36 ( struct V_25 * V_25 ,
struct V_1 * V_2 )
{
F_3 ( & V_25 -> V_44 ) ;
F_37 ( & V_2 -> V_45 ) ;
F_6 ( & V_25 -> V_44 ) ;
F_32 () ;
}
static int F_38 ( struct V_25 * V_25 )
{
int V_36 ;
V_36 = F_19 ( & V_25 -> V_37 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_25 -> V_38 )
V_36 = - V_39 ;
else if ( ! V_25 -> V_47 ++ ) {
V_36 = F_39 ( & V_25 -> V_24 ) ;
if ( V_36 )
V_25 -> V_47 -- ;
}
F_21 ( & V_25 -> V_37 ) ;
return V_36 ;
}
static void F_40 ( struct V_25 * V_25 )
{
F_41 ( & V_25 -> V_37 ) ;
if ( V_25 -> V_38 && ! -- V_25 -> V_47 )
F_42 ( & V_25 -> V_24 ) ;
F_21 ( & V_25 -> V_37 ) ;
}
static void F_43 ( struct V_25 * V_25 )
{
struct V_1 * V_2 ;
F_3 ( & V_25 -> V_44 ) ;
F_44 (client, &evdev->client_list, node)
F_5 ( & V_2 -> V_20 , V_21 , V_48 ) ;
F_6 ( & V_25 -> V_44 ) ;
F_15 ( & V_25 -> V_30 ) ;
}
static int F_45 ( struct V_49 * V_49 , struct V_32 * V_32 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
F_41 ( & V_25 -> V_37 ) ;
F_29 ( V_25 , V_2 ) ;
F_21 ( & V_25 -> V_37 ) ;
F_36 ( V_25 , V_2 ) ;
F_25 ( V_2 ) ;
F_40 ( V_25 ) ;
F_46 ( & V_25 -> V_41 ) ;
return 0 ;
}
static unsigned int F_47 ( struct V_50 * V_41 )
{
unsigned int V_51 =
F_48 ( V_41 -> V_52 * V_53 ,
V_54 ) ;
return F_49 ( V_51 ) ;
}
static int F_50 ( struct V_49 * V_49 , struct V_32 * V_32 )
{
struct V_25 * V_25 ;
struct V_1 * V_2 ;
int V_55 = F_51 ( V_49 ) - V_56 ;
unsigned int V_12 ;
int error ;
if ( V_55 >= V_57 )
return - V_39 ;
error = F_19 ( & V_58 ) ;
if ( error )
return error ;
V_25 = V_59 [ V_55 ] ;
if ( V_25 )
F_52 ( & V_25 -> V_41 ) ;
F_21 ( & V_58 ) ;
if ( ! V_25 )
return - V_39 ;
V_12 = F_47 ( V_25 -> V_24 . V_41 ) ;
V_2 = F_53 ( sizeof( struct V_1 ) +
V_12 * sizeof( struct V_3 ) ,
V_60 ) ;
if ( ! V_2 ) {
error = - V_61 ;
goto V_62;
}
V_2 -> V_12 = V_12 ;
F_54 ( & V_2 -> V_9 ) ;
V_2 -> V_25 = V_25 ;
F_34 ( V_25 , V_2 ) ;
error = F_38 ( V_25 ) ;
if ( error )
goto V_63;
V_32 -> V_34 = V_2 ;
F_55 ( V_49 , V_32 ) ;
return 0 ;
V_63:
F_36 ( V_25 , V_2 ) ;
F_25 ( V_2 ) ;
V_62:
F_46 ( & V_25 -> V_41 ) ;
return error ;
}
static T_3 F_56 ( struct V_32 * V_32 , const char T_4 * V_10 ,
T_5 V_64 , T_6 * V_65 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
struct V_3 V_4 ;
int V_36 = 0 ;
if ( V_64 != 0 && V_64 < F_57 () )
return - V_43 ;
V_36 = F_19 ( & V_25 -> V_37 ) ;
if ( V_36 )
return V_36 ;
if ( ! V_25 -> V_38 ) {
V_36 = - V_39 ;
goto V_66;
}
while ( V_36 + F_57 () <= V_64 ) {
if ( F_58 ( V_10 + V_36 , & V_4 ) ) {
V_36 = - V_67 ;
goto V_66;
}
V_36 += F_57 () ;
F_59 ( & V_25 -> V_24 ,
V_4 . type , V_4 . V_15 , V_4 . V_17 ) ;
}
V_66:
F_21 ( & V_25 -> V_37 ) ;
return V_36 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_68 ;
F_61 ( & V_2 -> V_9 ) ;
V_68 = V_2 -> V_18 != V_2 -> V_13 ;
if ( V_68 ) {
* V_4 = V_2 -> V_10 [ V_2 -> V_13 ++ ] ;
V_2 -> V_13 &= V_2 -> V_12 - 1 ;
}
F_62 ( & V_2 -> V_9 ) ;
return V_68 ;
}
static T_3 F_63 ( struct V_32 * V_32 , char T_4 * V_10 ,
T_5 V_64 , T_6 * V_65 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
struct V_3 V_4 ;
T_5 V_69 = 0 ;
int error ;
if ( V_64 != 0 && V_64 < F_57 () )
return - V_43 ;
for (; ; ) {
if ( ! V_25 -> V_38 )
return - V_39 ;
if ( V_2 -> V_18 == V_2 -> V_13 &&
( V_32 -> V_70 & V_71 ) )
return - V_72 ;
if ( V_64 == 0 )
break;
while ( V_69 + F_57 () <= V_64 &&
F_60 ( V_2 , & V_4 ) ) {
if ( F_64 ( V_10 + V_69 , & V_4 ) )
return - V_67 ;
V_69 += F_57 () ;
}
if ( V_69 )
break;
if ( ! ( V_32 -> V_70 & V_71 ) ) {
error = F_65 ( V_25 -> V_30 ,
V_2 -> V_18 != V_2 -> V_13 ||
! V_25 -> V_38 ) ;
if ( error )
return error ;
}
}
return V_69 ;
}
static unsigned int F_66 ( struct V_32 * V_32 , T_7 * V_30 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
unsigned int V_73 ;
F_67 ( V_32 , & V_25 -> V_30 , V_30 ) ;
V_73 = V_25 -> V_38 ? V_74 | V_75 : V_76 | V_77 ;
if ( V_2 -> V_18 != V_2 -> V_13 )
V_73 |= V_78 | V_79 ;
return V_73 ;
}
static int F_68 ( unsigned long * V_80 , unsigned int V_81 ,
unsigned int V_82 , void T_4 * V_83 , int V_84 )
{
int V_85 , V_55 ;
if ( V_84 ) {
V_85 = F_69 ( V_81 ) * sizeof( V_86 ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
for ( V_55 = 0 ; V_55 < V_85 / sizeof( V_86 ) ; V_55 ++ )
if ( F_70 ( ( V_86 T_4 * ) V_83 + V_55 ,
( V_86 * ) V_80 +
V_55 + 1 - ( ( V_55 % 2 ) << 1 ) ,
sizeof( V_86 ) ) )
return - V_67 ;
} else {
V_85 = F_71 ( V_81 ) * sizeof( long ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
if ( F_70 ( V_83 , V_80 , V_85 ) )
return - V_67 ;
}
return V_85 ;
}
static int F_68 ( unsigned long * V_80 , unsigned int V_81 ,
unsigned int V_82 , void T_4 * V_83 , int V_84 )
{
int V_85 = V_84 ?
F_69 ( V_81 ) * sizeof( V_86 ) :
F_71 ( V_81 ) * sizeof( long ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
return F_70 ( V_83 , V_80 , V_85 ) ? - V_67 : V_85 ;
}
static int F_68 ( unsigned long * V_80 , unsigned int V_81 ,
unsigned int V_82 , void T_4 * V_83 , int V_84 )
{
int V_85 = F_71 ( V_81 ) * sizeof( long ) ;
if ( V_85 > V_82 )
V_85 = V_82 ;
return F_70 ( V_83 , V_80 , V_85 ) ? - V_67 : V_85 ;
}
static int F_72 ( const char * V_87 , unsigned int V_82 , void T_4 * V_83 )
{
int V_85 ;
if ( ! V_87 )
return - V_88 ;
V_85 = strlen ( V_87 ) + 1 ;
if ( V_85 > V_82 )
V_85 = V_82 ;
return F_70 ( V_83 , V_87 , V_85 ) ? - V_67 : V_85 ;
}
static int F_73 ( struct V_50 * V_41 ,
unsigned int type , unsigned int V_89 ,
void T_4 * V_83 , int V_90 )
{
static unsigned long V_91 ;
unsigned long * V_80 ;
int V_85 ;
switch ( type ) {
case 0 : V_80 = V_41 -> V_92 ; V_85 = V_93 ; break;
case V_94 : V_80 = V_41 -> V_95 ; V_85 = V_96 ; break;
case V_97 : V_80 = V_41 -> V_98 ; V_85 = V_99 ; break;
case V_100 : V_80 = V_41 -> V_101 ; V_85 = V_102 ; break;
case V_103 : V_80 = V_41 -> V_104 ; V_85 = V_105 ; break;
case V_106 : V_80 = V_41 -> V_107 ; V_85 = V_108 ; break;
case V_109 : V_80 = V_41 -> V_110 ; V_85 = V_111 ; break;
case V_112 : V_80 = V_41 -> V_113 ; V_85 = V_114 ; break;
case V_115 : V_80 = V_41 -> V_116 ; V_85 = V_117 ; break;
default: return - V_43 ;
}
if ( type == V_94 && V_89 == V_118 ) {
V_85 = V_118 ;
if ( F_74 ( & V_91 , 10 * 1000 ) )
F_75 ( L_1
L_2
L_3 ,
V_118 ,
F_71 ( V_118 ) * sizeof( long ) ) ;
}
return F_68 ( V_80 , V_85 , V_89 , V_83 , V_90 ) ;
}
static int F_76 ( struct V_50 * V_41 , void T_4 * V_83 )
{
struct V_119 V_120 = {
. V_85 = sizeof( unsigned int ) ,
. V_121 = 0 ,
} ;
int T_4 * V_122 = ( int T_4 * ) V_83 ;
int error ;
if ( F_77 ( V_120 . V_123 , V_83 , sizeof( unsigned int ) ) )
return - V_67 ;
error = F_78 ( V_41 , & V_120 ) ;
if ( error )
return error ;
if ( F_79 ( V_120 . V_124 , V_122 + 1 ) )
return - V_67 ;
return 0 ;
}
static int F_80 ( struct V_50 * V_41 , void T_4 * V_83 )
{
struct V_119 V_120 ;
int error ;
if ( F_77 ( & V_120 , V_83 , sizeof( V_120 ) ) )
return - V_67 ;
error = F_78 ( V_41 , & V_120 ) ;
if ( error )
return error ;
if ( F_70 ( V_83 , & V_120 , sizeof( V_120 ) ) )
return - V_67 ;
return 0 ;
}
static int F_81 ( struct V_50 * V_41 , void T_4 * V_83 )
{
struct V_119 V_120 = {
. V_85 = sizeof( unsigned int ) ,
. V_121 = 0 ,
} ;
int T_4 * V_122 = ( int T_4 * ) V_83 ;
if ( F_77 ( V_120 . V_123 , V_83 , sizeof( unsigned int ) ) )
return - V_67 ;
if ( F_82 ( V_120 . V_124 , V_122 + 1 ) )
return - V_67 ;
return F_83 ( V_41 , & V_120 ) ;
}
static int F_84 ( struct V_50 * V_41 , void T_4 * V_83 )
{
struct V_119 V_120 ;
if ( F_77 ( & V_120 , V_83 , sizeof( V_120 ) ) )
return - V_67 ;
if ( V_120 . V_85 > sizeof( V_120 . V_123 ) )
return - V_43 ;
return F_83 ( V_41 , & V_120 ) ;
}
static int F_85 ( struct V_50 * V_41 ,
unsigned int V_89 ,
int T_4 * V_122 )
{
const struct V_125 * V_126 = V_41 -> V_126 ;
unsigned int V_15 ;
int V_127 ;
int V_55 ;
if ( F_82 ( V_15 , & V_122 [ 0 ] ) )
return - V_67 ;
if ( ! F_86 ( V_15 ) )
return - V_43 ;
V_127 = ( V_89 - sizeof( V_128 ) ) / sizeof( V_129 ) ;
for ( V_55 = 0 ; V_55 < V_41 -> V_130 && V_55 < V_127 ; V_55 ++ )
if ( F_79 ( F_87 ( & V_126 [ V_55 ] , V_15 ) , & V_122 [ 1 + V_55 ] ) )
return - V_67 ;
return 0 ;
}
static long F_88 ( struct V_32 * V_32 , unsigned int V_131 ,
void T_4 * V_83 , int V_90 )
{
struct V_1 * V_2 = V_32 -> V_34 ;
struct V_25 * V_25 = V_2 -> V_25 ;
struct V_50 * V_41 = V_25 -> V_24 . V_41 ;
struct V_132 abs ;
struct V_133 V_134 ;
int T_4 * V_122 = ( int T_4 * ) V_83 ;
unsigned int V_55 , V_135 , V_136 , V_137 ;
unsigned int V_89 ;
int error ;
switch ( V_131 ) {
case V_138 :
return F_79 ( V_139 , V_122 ) ;
case V_140 :
if ( F_70 ( V_83 , & V_41 -> V_35 , sizeof( struct V_141 ) ) )
return - V_67 ;
return 0 ;
case V_142 :
if ( ! F_89 ( V_143 , V_41 -> V_92 ) )
return - V_144 ;
if ( F_79 ( V_41 -> V_145 [ V_146 ] , V_122 ) )
return - V_67 ;
if ( F_79 ( V_41 -> V_145 [ V_147 ] , V_122 + 1 ) )
return - V_67 ;
return 0 ;
case V_148 :
if ( ! F_89 ( V_143 , V_41 -> V_92 ) )
return - V_144 ;
if ( F_82 ( V_136 , V_122 ) )
return - V_67 ;
if ( F_82 ( V_137 , V_122 + 1 ) )
return - V_67 ;
F_59 ( & V_25 -> V_24 , V_143 , V_146 , V_136 ) ;
F_59 ( & V_25 -> V_24 , V_143 , V_147 , V_137 ) ;
return 0 ;
case V_149 :
return F_90 ( V_41 , ( int ) ( unsigned long ) V_83 , V_32 ) ;
case V_150 :
V_55 = F_89 ( V_112 , V_41 -> V_92 ) ?
V_41 -> V_151 -> V_152 : 0 ;
if ( F_79 ( V_55 , V_122 ) )
return - V_67 ;
return 0 ;
case V_153 :
if ( V_83 )
return F_26 ( V_25 , V_2 ) ;
else
return F_29 ( V_25 , V_2 ) ;
case V_154 :
if ( F_77 ( & V_55 , V_83 , sizeof( unsigned int ) ) )
return - V_67 ;
if ( V_55 != V_8 && V_55 != V_155 )
return - V_43 ;
V_2 -> V_7 = V_55 ;
return 0 ;
case V_156 :
return F_76 ( V_41 , V_83 ) ;
case V_157 :
return F_81 ( V_41 , V_83 ) ;
case V_158 :
return F_80 ( V_41 , V_83 ) ;
case V_159 :
return F_84 ( V_41 , V_83 ) ;
}
V_89 = F_91 ( V_131 ) ;
#define F_92 ( T_8 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_92 ( V_131 ) ) {
case F_93 ( 0 ) :
return F_68 ( V_41 -> V_160 , V_161 ,
V_89 , V_83 , V_90 ) ;
case F_94 ( 0 ) :
return F_85 ( V_41 , V_89 , V_122 ) ;
case F_95 ( 0 ) :
return F_68 ( V_41 -> V_162 , V_96 , V_89 , V_83 , V_90 ) ;
case F_96 ( 0 ) :
return F_68 ( V_41 -> V_163 , V_108 , V_89 , V_83 , V_90 ) ;
case F_97 ( 0 ) :
return F_68 ( V_41 -> V_164 , V_111 , V_89 , V_83 , V_90 ) ;
case F_98 ( 0 ) :
return F_68 ( V_41 -> V_165 , V_117 , V_89 , V_83 , V_90 ) ;
case F_99 ( 0 ) :
return F_72 ( V_41 -> V_166 , V_89 , V_83 ) ;
case F_100 ( 0 ) :
return F_72 ( V_41 -> V_167 , V_89 , V_83 ) ;
case F_101 ( 0 ) :
return F_72 ( V_41 -> V_168 , V_89 , V_83 ) ;
case F_92 ( V_169 ) :
if ( F_102 ( V_83 , V_89 , & V_134 ) )
return - V_67 ;
error = F_103 ( V_41 , & V_134 , V_32 ) ;
if ( F_79 ( V_134 . V_35 , & ( ( (struct V_133 T_4 * ) V_83 ) -> V_35 ) ) )
return - V_67 ;
return error ;
}
if ( F_104 ( V_131 ) != 'E' )
return - V_43 ;
if ( F_105 ( V_131 ) == V_170 ) {
if ( ( F_106 ( V_131 ) & ~ V_93 ) == F_106 ( F_107 ( 0 , 0 ) ) )
return F_73 ( V_41 ,
F_106 ( V_131 ) & V_93 , V_89 ,
V_83 , V_90 ) ;
if ( ( F_106 ( V_131 ) & ~ V_102 ) == F_106 ( F_108 ( 0 ) ) ) {
if ( ! V_41 -> V_171 )
return - V_43 ;
V_135 = F_106 ( V_131 ) & V_102 ;
abs = V_41 -> V_171 [ V_135 ] ;
if ( F_70 ( V_83 , & abs , F_109 ( T_5 ,
V_89 , sizeof( struct V_132 ) ) ) )
return - V_67 ;
return 0 ;
}
}
if ( F_105 ( V_131 ) == V_172 ) {
if ( ( F_106 ( V_131 ) & ~ V_102 ) == F_106 ( F_110 ( 0 ) ) ) {
if ( ! V_41 -> V_171 )
return - V_43 ;
V_135 = F_106 ( V_131 ) & V_102 ;
if ( F_77 ( & abs , V_83 , F_109 ( T_5 ,
V_89 , sizeof( struct V_132 ) ) ) )
return - V_67 ;
if ( V_89 < sizeof( struct V_132 ) )
abs . V_173 = 0 ;
if ( V_135 == V_174 )
return - V_43 ;
F_61 ( & V_41 -> V_175 ) ;
V_41 -> V_171 [ V_135 ] = abs ;
F_62 ( & V_41 -> V_175 ) ;
return 0 ;
}
}
return - V_43 ;
}
static long F_111 ( struct V_32 * V_32 , unsigned int V_131 ,
void T_4 * V_83 , int V_90 )
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
V_36 = F_88 ( V_32 , V_131 , V_83 , V_90 ) ;
V_66:
F_21 ( & V_25 -> V_37 ) ;
return V_36 ;
}
static long F_112 ( struct V_32 * V_32 , unsigned int V_131 , unsigned long V_176 )
{
return F_111 ( V_32 , V_131 , ( void T_4 * ) V_176 , 0 ) ;
}
static long F_113 ( struct V_32 * V_32 ,
unsigned int V_131 , unsigned long V_176 )
{
return F_111 ( V_32 , V_131 , F_114 ( V_176 ) , 1 ) ;
}
static int F_115 ( struct V_25 * V_25 )
{
V_59 [ V_25 -> V_177 ] = V_25 ;
return 0 ;
}
static void F_116 ( struct V_25 * V_25 )
{
F_41 ( & V_58 ) ;
V_59 [ V_25 -> V_177 ] = NULL ;
F_21 ( & V_58 ) ;
}
static void F_117 ( struct V_25 * V_25 )
{
F_41 ( & V_25 -> V_37 ) ;
V_25 -> V_38 = false ;
F_21 ( & V_25 -> V_37 ) ;
}
static void F_118 ( struct V_25 * V_25 )
{
struct V_23 * V_24 = & V_25 -> V_24 ;
F_117 ( V_25 ) ;
F_43 ( V_25 ) ;
F_116 ( V_25 ) ;
if ( V_25 -> V_47 ) {
F_20 ( V_24 , NULL ) ;
F_42 ( V_24 ) ;
}
}
static int F_119 ( struct V_178 * V_179 , struct V_50 * V_41 ,
const struct V_180 * V_35 )
{
struct V_25 * V_25 ;
int V_177 ;
int error ;
for ( V_177 = 0 ; V_177 < V_57 ; V_177 ++ )
if ( ! V_59 [ V_177 ] )
break;
if ( V_177 == V_57 ) {
F_120 ( L_4 ) ;
return - V_181 ;
}
V_25 = F_53 ( sizeof( struct V_25 ) , V_60 ) ;
if ( ! V_25 )
return - V_61 ;
F_121 ( & V_25 -> V_46 ) ;
F_54 ( & V_25 -> V_44 ) ;
F_122 ( & V_25 -> V_37 ) ;
F_123 ( & V_25 -> V_30 ) ;
F_124 ( & V_25 -> V_41 , L_5 , V_177 ) ;
V_25 -> V_38 = true ;
V_25 -> V_177 = V_177 ;
V_25 -> V_24 . V_41 = F_125 ( V_41 ) ;
V_25 -> V_24 . V_166 = F_126 ( & V_25 -> V_41 ) ;
V_25 -> V_24 . V_179 = V_179 ;
V_25 -> V_24 . V_26 = V_25 ;
V_25 -> V_41 . V_182 = F_127 ( V_183 , V_56 + V_177 ) ;
V_25 -> V_41 . V_184 = & V_185 ;
V_25 -> V_41 . V_186 = & V_41 -> V_41 ;
V_25 -> V_41 . V_187 = F_22 ;
F_128 ( & V_25 -> V_41 ) ;
error = F_129 ( & V_25 -> V_24 ) ;
if ( error )
goto V_188;
error = F_115 ( V_25 ) ;
if ( error )
goto V_189;
error = F_130 ( & V_25 -> V_41 ) ;
if ( error )
goto V_190;
return 0 ;
V_190:
F_118 ( V_25 ) ;
V_189:
F_131 ( & V_25 -> V_24 ) ;
V_188:
F_46 ( & V_25 -> V_41 ) ;
return error ;
}
static void F_132 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = V_24 -> V_26 ;
F_133 ( & V_25 -> V_41 ) ;
F_118 ( V_25 ) ;
F_131 ( V_24 ) ;
F_46 ( & V_25 -> V_41 ) ;
}
static int T_9 F_134 ( void )
{
return F_135 ( & V_191 ) ;
}
static void T_10 F_136 ( void )
{
F_137 ( & V_191 ) ;
}
