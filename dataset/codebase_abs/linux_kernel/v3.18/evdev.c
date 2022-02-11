static void F_1 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_3 , V_4 , V_5 ;
unsigned int V_6 = V_2 -> V_7 - 1 ;
bool V_8 ;
struct V_9 * V_10 ;
F_2 ( type == V_11 ) ;
V_4 = V_2 -> V_12 ;
V_2 -> V_13 = V_2 -> V_12 ;
V_5 = 1 ;
for ( V_3 = V_2 -> V_12 ; V_3 != V_2 -> V_4 ; V_3 = ( V_3 + 1 ) & V_6 ) {
V_10 = & V_2 -> V_14 [ V_3 ] ;
V_8 = V_10 -> type == V_11 && V_10 -> V_15 == V_16 ;
if ( V_10 -> type == type ) {
continue;
} else if ( V_8 && ! V_5 ) {
continue;
} else if ( V_4 != V_3 ) {
V_2 -> V_14 [ V_4 ] . time = V_10 -> time ;
V_2 -> V_14 [ V_4 ] . type = V_10 -> type ;
V_2 -> V_14 [ V_4 ] . V_15 = V_10 -> V_15 ;
V_2 -> V_14 [ V_4 ] . V_17 = V_10 -> V_17 ;
}
V_5 ++ ;
V_4 = ( V_4 + 1 ) & V_6 ;
if ( V_8 ) {
V_5 = 0 ;
V_2 -> V_13 = V_4 ;
}
}
V_2 -> V_4 = V_4 ;
}
static void F_3 ( struct V_1 * V_2 )
{
unsigned long V_18 ;
struct V_9 V_10 ;
T_1 time ;
time = ( V_2 -> V_19 == V_20 ) ?
F_4 () : F_5 () ;
V_10 . time = F_6 ( time ) ;
V_10 . type = V_11 ;
V_10 . V_15 = V_21 ;
V_10 . V_17 = 0 ;
F_7 ( & V_2 -> V_22 , V_18 ) ;
V_2 -> V_14 [ V_2 -> V_4 ++ ] = V_10 ;
V_2 -> V_4 &= V_2 -> V_7 - 1 ;
if ( F_8 ( V_2 -> V_4 == V_2 -> V_12 ) ) {
V_2 -> V_12 = ( V_2 -> V_4 - 1 ) & ( V_2 -> V_7 - 1 ) ;
V_2 -> V_13 = V_2 -> V_12 ;
}
F_9 ( & V_2 -> V_22 , V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
const struct V_9 * V_23 )
{
V_2 -> V_14 [ V_2 -> V_4 ++ ] = * V_23 ;
V_2 -> V_4 &= V_2 -> V_7 - 1 ;
if ( F_8 ( V_2 -> V_4 == V_2 -> V_12 ) ) {
V_2 -> V_12 = ( V_2 -> V_4 - 2 ) & ( V_2 -> V_7 - 1 ) ;
V_2 -> V_14 [ V_2 -> V_12 ] . time = V_23 -> time ;
V_2 -> V_14 [ V_2 -> V_12 ] . type = V_11 ;
V_2 -> V_14 [ V_2 -> V_12 ] . V_15 = V_21 ;
V_2 -> V_14 [ V_2 -> V_12 ] . V_17 = 0 ;
V_2 -> V_13 = V_2 -> V_12 ;
}
if ( V_23 -> type == V_11 && V_23 -> V_15 == V_16 ) {
V_2 -> V_13 = V_2 -> V_4 ;
F_11 ( & V_2 -> V_24 , V_25 , V_26 ) ;
}
}
static void F_12 ( struct V_1 * V_2 ,
const struct V_27 * V_28 , unsigned int V_29 ,
T_1 V_30 , T_1 V_31 )
{
struct V_32 * V_32 = V_2 -> V_32 ;
const struct V_27 * V_33 ;
struct V_9 V_23 ;
bool V_34 = false ;
if ( V_2 -> V_35 )
return;
V_23 . time = F_6 ( V_2 -> V_19 == V_20 ?
V_30 : V_31 ) ;
F_13 ( & V_2 -> V_22 ) ;
for ( V_33 = V_28 ; V_33 != V_28 + V_29 ; V_33 ++ ) {
V_23 . type = V_33 -> type ;
V_23 . V_15 = V_33 -> V_15 ;
V_23 . V_17 = V_33 -> V_17 ;
F_10 ( V_2 , & V_23 ) ;
if ( V_33 -> type == V_11 && V_33 -> V_15 == V_16 )
V_34 = true ;
}
F_14 ( & V_2 -> V_22 ) ;
if ( V_34 )
F_15 ( & V_32 -> V_36 ) ;
}
static void F_16 ( struct V_37 * V_38 ,
const struct V_27 * V_28 , unsigned int V_29 )
{
struct V_32 * V_32 = V_38 -> V_39 ;
struct V_1 * V_2 ;
T_1 V_40 , V_41 ;
V_40 = F_4 () ;
V_41 = F_17 ( V_40 ) ;
F_18 () ;
V_2 = F_19 ( V_32 -> V_42 ) ;
if ( V_2 )
F_12 ( V_2 , V_28 , V_29 , V_40 , V_41 ) ;
else
F_20 (client, &evdev->client_list, node)
F_12 ( V_2 , V_28 , V_29 ,
V_40 , V_41 ) ;
F_21 () ;
}
static void F_22 ( struct V_37 * V_38 ,
unsigned int type , unsigned int V_15 , int V_17 )
{
struct V_27 V_28 [] = { { type , V_15 , V_17 } } ;
F_16 ( V_38 , V_28 , 1 ) ;
}
static int F_23 ( int V_43 , struct V_44 * V_44 , int V_45 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
return F_24 ( V_43 , V_44 , V_45 , & V_2 -> V_24 ) ;
}
static int F_25 ( struct V_44 * V_44 , T_2 V_47 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
int V_48 ;
V_48 = F_26 ( & V_32 -> V_49 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_32 -> V_50 || V_2 -> V_35 )
V_48 = - V_51 ;
else
V_48 = F_27 ( & V_32 -> V_38 , V_44 ) ;
F_28 ( & V_32 -> V_49 ) ;
return V_48 ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_32 * V_32 = F_30 ( V_53 , struct V_32 , V_53 ) ;
F_31 ( V_32 -> V_38 . V_53 ) ;
F_32 ( V_32 ) ;
}
static int F_33 ( struct V_32 * V_32 , struct V_1 * V_2 )
{
int error ;
if ( V_32 -> V_42 )
return - V_54 ;
error = F_34 ( & V_32 -> V_38 ) ;
if ( error )
return error ;
F_35 ( V_32 -> V_42 , V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_32 * V_32 , struct V_1 * V_2 )
{
struct V_1 * V_42 = F_37 ( V_32 -> V_42 ,
F_38 ( & V_32 -> V_49 ) ) ;
if ( V_42 != V_2 )
return - V_55 ;
F_35 ( V_32 -> V_42 , NULL ) ;
F_39 () ;
F_40 ( & V_32 -> V_38 ) ;
return 0 ;
}
static void F_41 ( struct V_32 * V_32 ,
struct V_1 * V_2 )
{
F_13 ( & V_32 -> V_56 ) ;
F_42 ( & V_2 -> V_57 , & V_32 -> V_58 ) ;
F_14 ( & V_32 -> V_56 ) ;
}
static void F_43 ( struct V_32 * V_32 ,
struct V_1 * V_2 )
{
F_13 ( & V_32 -> V_56 ) ;
F_44 ( & V_2 -> V_57 ) ;
F_14 ( & V_32 -> V_56 ) ;
F_39 () ;
}
static int F_45 ( struct V_32 * V_32 )
{
int V_48 ;
V_48 = F_26 ( & V_32 -> V_49 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_32 -> V_50 )
V_48 = - V_51 ;
else if ( ! V_32 -> V_59 ++ ) {
V_48 = F_46 ( & V_32 -> V_38 ) ;
if ( V_48 )
V_32 -> V_59 -- ;
}
F_28 ( & V_32 -> V_49 ) ;
return V_48 ;
}
static void F_47 ( struct V_32 * V_32 )
{
F_48 ( & V_32 -> V_49 ) ;
if ( V_32 -> V_50 && ! -- V_32 -> V_59 )
F_49 ( & V_32 -> V_38 ) ;
F_28 ( & V_32 -> V_49 ) ;
}
static void F_50 ( struct V_32 * V_32 )
{
struct V_1 * V_2 ;
F_13 ( & V_32 -> V_56 ) ;
F_51 (client, &evdev->client_list, node)
F_11 ( & V_2 -> V_24 , V_25 , V_60 ) ;
F_14 ( & V_32 -> V_56 ) ;
F_15 ( & V_32 -> V_36 ) ;
}
static int F_52 ( struct V_61 * V_61 , struct V_44 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
F_48 ( & V_32 -> V_49 ) ;
F_36 ( V_32 , V_2 ) ;
F_28 ( & V_32 -> V_49 ) ;
F_43 ( V_32 , V_2 ) ;
if ( F_53 ( V_2 ) )
F_54 ( V_2 ) ;
else
F_32 ( V_2 ) ;
F_47 ( V_32 ) ;
return 0 ;
}
static unsigned int F_55 ( struct V_62 * V_53 )
{
unsigned int V_63 =
F_56 ( V_53 -> V_64 * V_65 ,
V_66 ) ;
return F_57 ( V_63 ) ;
}
static int F_58 ( struct V_61 * V_61 , struct V_44 * V_44 )
{
struct V_32 * V_32 = F_30 ( V_61 -> V_67 , struct V_32 , V_68 ) ;
unsigned int V_7 = F_55 ( V_32 -> V_38 . V_53 ) ;
unsigned int V_69 = sizeof( struct V_1 ) +
V_7 * sizeof( struct V_9 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_59 ( V_69 , V_70 | V_71 ) ;
if ( ! V_2 )
V_2 = F_60 ( V_69 ) ;
if ( ! V_2 )
return - V_72 ;
V_2 -> V_7 = V_7 ;
F_61 ( & V_2 -> V_22 ) ;
V_2 -> V_32 = V_32 ;
F_41 ( V_32 , V_2 ) ;
error = F_45 ( V_32 ) ;
if ( error )
goto V_73;
V_44 -> V_46 = V_2 ;
F_62 ( V_61 , V_44 ) ;
return 0 ;
V_73:
F_43 ( V_32 , V_2 ) ;
F_63 ( V_2 ) ;
return error ;
}
static T_3 F_64 ( struct V_44 * V_44 , const char T_4 * V_14 ,
T_5 V_29 , T_6 * V_74 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_9 V_23 ;
int V_48 = 0 ;
if ( V_29 != 0 && V_29 < F_65 () )
return - V_55 ;
V_48 = F_26 ( & V_32 -> V_49 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_32 -> V_50 || V_2 -> V_35 ) {
V_48 = - V_51 ;
goto V_75;
}
while ( V_48 + F_65 () <= V_29 ) {
if ( F_66 ( V_14 + V_48 , & V_23 ) ) {
V_48 = - V_76 ;
goto V_75;
}
V_48 += F_65 () ;
F_67 ( & V_32 -> V_38 ,
V_23 . type , V_23 . V_15 , V_23 . V_17 ) ;
}
V_75:
F_28 ( & V_32 -> V_49 ) ;
return V_48 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_9 * V_23 )
{
int V_77 ;
F_69 ( & V_2 -> V_22 ) ;
V_77 = V_2 -> V_13 != V_2 -> V_12 ;
if ( V_77 ) {
* V_23 = V_2 -> V_14 [ V_2 -> V_12 ++ ] ;
V_2 -> V_12 &= V_2 -> V_7 - 1 ;
}
F_70 ( & V_2 -> V_22 ) ;
return V_77 ;
}
static T_3 F_71 ( struct V_44 * V_44 , char T_4 * V_14 ,
T_5 V_29 , T_6 * V_74 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_9 V_23 ;
T_5 V_78 = 0 ;
int error ;
if ( V_29 != 0 && V_29 < F_65 () )
return - V_55 ;
for (; ; ) {
if ( ! V_32 -> V_50 || V_2 -> V_35 )
return - V_51 ;
if ( V_2 -> V_13 == V_2 -> V_12 &&
( V_44 -> V_79 & V_80 ) )
return - V_81 ;
if ( V_29 == 0 )
break;
while ( V_78 + F_65 () <= V_29 &&
F_68 ( V_2 , & V_23 ) ) {
if ( F_72 ( V_14 + V_78 , & V_23 ) )
return - V_76 ;
V_78 += F_65 () ;
}
if ( V_78 )
break;
if ( ! ( V_44 -> V_79 & V_80 ) ) {
error = F_73 ( V_32 -> V_36 ,
V_2 -> V_13 != V_2 -> V_12 ||
! V_32 -> V_50 || V_2 -> V_35 ) ;
if ( error )
return error ;
}
}
return V_78 ;
}
static unsigned int F_74 ( struct V_44 * V_44 , T_7 * V_36 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
unsigned int V_6 ;
F_75 ( V_44 , & V_32 -> V_36 , V_36 ) ;
if ( V_32 -> V_50 && ! V_2 -> V_35 )
V_6 = V_82 | V_83 ;
else
V_6 = V_84 | V_85 ;
if ( V_2 -> V_13 != V_2 -> V_12 )
V_6 |= V_86 | V_87 ;
return V_6 ;
}
static int F_76 ( unsigned long * V_88 , unsigned int V_89 ,
unsigned int V_90 , void T_4 * V_91 , int V_92 )
{
int V_93 , V_3 ;
if ( V_92 ) {
V_93 = F_77 ( V_89 ) * sizeof( V_94 ) ;
if ( V_93 > V_90 )
V_93 = V_90 ;
for ( V_3 = 0 ; V_3 < V_93 / sizeof( V_94 ) ; V_3 ++ )
if ( F_78 ( ( V_94 T_4 * ) V_91 + V_3 ,
( V_94 * ) V_88 +
V_3 + 1 - ( ( V_3 % 2 ) << 1 ) ,
sizeof( V_94 ) ) )
return - V_76 ;
} else {
V_93 = F_79 ( V_89 ) * sizeof( long ) ;
if ( V_93 > V_90 )
V_93 = V_90 ;
if ( F_78 ( V_91 , V_88 , V_93 ) )
return - V_76 ;
}
return V_93 ;
}
static int F_76 ( unsigned long * V_88 , unsigned int V_89 ,
unsigned int V_90 , void T_4 * V_91 , int V_92 )
{
int V_93 = V_92 ?
F_77 ( V_89 ) * sizeof( V_94 ) :
F_79 ( V_89 ) * sizeof( long ) ;
if ( V_93 > V_90 )
V_93 = V_90 ;
return F_78 ( V_91 , V_88 , V_93 ) ? - V_76 : V_93 ;
}
static int F_76 ( unsigned long * V_88 , unsigned int V_89 ,
unsigned int V_90 , void T_4 * V_91 , int V_92 )
{
int V_93 = F_79 ( V_89 ) * sizeof( long ) ;
if ( V_93 > V_90 )
V_93 = V_90 ;
return F_78 ( V_91 , V_88 , V_93 ) ? - V_76 : V_93 ;
}
static int F_80 ( const char * V_95 , unsigned int V_90 , void T_4 * V_91 )
{
int V_93 ;
if ( ! V_95 )
return - V_96 ;
V_93 = strlen ( V_95 ) + 1 ;
if ( V_93 > V_90 )
V_93 = V_90 ;
return F_78 ( V_91 , V_95 , V_93 ) ? - V_76 : V_93 ;
}
static int F_81 ( struct V_62 * V_53 ,
unsigned int type , unsigned int V_69 ,
void T_4 * V_91 , int V_97 )
{
unsigned long * V_88 ;
int V_93 ;
switch ( type ) {
case 0 : V_88 = V_53 -> V_98 ; V_93 = V_99 ; break;
case V_100 : V_88 = V_53 -> V_101 ; V_93 = V_102 ; break;
case V_103 : V_88 = V_53 -> V_104 ; V_93 = V_105 ; break;
case V_106 : V_88 = V_53 -> V_107 ; V_93 = V_108 ; break;
case V_109 : V_88 = V_53 -> V_110 ; V_93 = V_111 ; break;
case V_112 : V_88 = V_53 -> V_113 ; V_93 = V_114 ; break;
case V_115 : V_88 = V_53 -> V_116 ; V_93 = V_117 ; break;
case V_118 : V_88 = V_53 -> V_119 ; V_93 = V_120 ; break;
case V_121 : V_88 = V_53 -> V_122 ; V_93 = V_123 ; break;
default: return - V_55 ;
}
return F_76 ( V_88 , V_93 , V_69 , V_91 , V_97 ) ;
}
static int F_82 ( struct V_62 * V_53 , void T_4 * V_91 )
{
struct V_124 V_125 = {
. V_93 = sizeof( unsigned int ) ,
. V_18 = 0 ,
} ;
int T_4 * V_126 = ( int T_4 * ) V_91 ;
int error ;
if ( F_83 ( V_125 . V_127 , V_91 , sizeof( unsigned int ) ) )
return - V_76 ;
error = F_84 ( V_53 , & V_125 ) ;
if ( error )
return error ;
if ( F_85 ( V_125 . V_128 , V_126 + 1 ) )
return - V_76 ;
return 0 ;
}
static int F_86 ( struct V_62 * V_53 , void T_4 * V_91 )
{
struct V_124 V_125 ;
int error ;
if ( F_83 ( & V_125 , V_91 , sizeof( V_125 ) ) )
return - V_76 ;
error = F_84 ( V_53 , & V_125 ) ;
if ( error )
return error ;
if ( F_78 ( V_91 , & V_125 , sizeof( V_125 ) ) )
return - V_76 ;
return 0 ;
}
static int F_87 ( struct V_62 * V_53 , void T_4 * V_91 )
{
struct V_124 V_125 = {
. V_93 = sizeof( unsigned int ) ,
. V_18 = 0 ,
} ;
int T_4 * V_126 = ( int T_4 * ) V_91 ;
if ( F_83 ( V_125 . V_127 , V_91 , sizeof( unsigned int ) ) )
return - V_76 ;
if ( F_88 ( V_125 . V_128 , V_126 + 1 ) )
return - V_76 ;
return F_89 ( V_53 , & V_125 ) ;
}
static int F_90 ( struct V_62 * V_53 , void T_4 * V_91 )
{
struct V_124 V_125 ;
if ( F_83 ( & V_125 , V_91 , sizeof( V_125 ) ) )
return - V_76 ;
if ( V_125 . V_93 > sizeof( V_125 . V_127 ) )
return - V_55 ;
return F_89 ( V_53 , & V_125 ) ;
}
static int F_91 ( struct V_1 * V_2 ,
struct V_62 * V_53 , unsigned int type ,
unsigned long * V_88 , unsigned int V_89 ,
unsigned int V_90 , void T_4 * V_91 ,
int V_92 )
{
int V_129 ;
unsigned long * V_130 ;
T_5 V_93 ;
V_93 = F_79 ( V_89 ) * sizeof( unsigned long ) ;
V_130 = F_92 ( V_93 , V_70 ) ;
if ( ! V_130 )
return - V_72 ;
F_69 ( & V_53 -> V_131 ) ;
F_13 ( & V_2 -> V_22 ) ;
memcpy ( V_130 , V_88 , V_93 ) ;
F_14 ( & V_53 -> V_131 ) ;
F_1 ( V_2 , type ) ;
F_70 ( & V_2 -> V_22 ) ;
V_129 = F_76 ( V_130 , V_89 , V_90 , V_91 , V_92 ) ;
if ( V_129 < 0 )
F_3 ( V_2 ) ;
F_32 ( V_130 ) ;
return V_129 ;
}
static int F_93 ( struct V_62 * V_53 ,
unsigned int V_69 ,
int T_4 * V_126 )
{
const struct V_132 * V_133 = V_53 -> V_133 ;
unsigned int V_15 ;
int V_134 ;
int V_3 ;
if ( F_88 ( V_15 , & V_126 [ 0 ] ) )
return - V_76 ;
if ( ! V_133 || ! F_94 ( V_15 ) )
return - V_55 ;
V_134 = ( V_69 - sizeof( V_135 ) ) / sizeof( V_136 ) ;
for ( V_3 = 0 ; V_3 < V_133 -> V_137 && V_3 < V_134 ; V_3 ++ ) {
int V_17 = F_95 ( & V_133 -> V_138 [ V_3 ] , V_15 ) ;
if ( F_85 ( V_17 , & V_126 [ 1 + V_3 ] ) )
return - V_76 ;
}
return 0 ;
}
static int F_96 ( struct V_32 * V_32 , struct V_1 * V_2 ,
struct V_44 * V_44 )
{
V_2 -> V_35 = true ;
F_36 ( V_32 , V_2 ) ;
F_27 ( & V_32 -> V_38 , V_44 ) ;
F_15 ( & V_32 -> V_36 ) ;
return 0 ;
}
static long F_97 ( struct V_44 * V_44 , unsigned int V_139 ,
void T_4 * V_91 , int V_97 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_62 * V_53 = V_32 -> V_38 . V_53 ;
struct V_140 abs ;
struct V_141 V_142 ;
int T_4 * V_126 = ( int T_4 * ) V_91 ;
unsigned int V_3 , V_143 , V_144 , V_33 ;
unsigned int V_69 ;
int error ;
switch ( V_139 ) {
case V_145 :
return F_85 ( V_146 , V_126 ) ;
case V_147 :
if ( F_78 ( V_91 , & V_53 -> V_47 , sizeof( struct V_148 ) ) )
return - V_76 ;
return 0 ;
case V_149 :
if ( ! F_98 ( V_150 , V_53 -> V_98 ) )
return - V_151 ;
if ( F_85 ( V_53 -> V_152 [ V_153 ] , V_126 ) )
return - V_76 ;
if ( F_85 ( V_53 -> V_152 [ V_154 ] , V_126 + 1 ) )
return - V_76 ;
return 0 ;
case V_155 :
if ( ! F_98 ( V_150 , V_53 -> V_98 ) )
return - V_151 ;
if ( F_88 ( V_144 , V_126 ) )
return - V_76 ;
if ( F_88 ( V_33 , V_126 + 1 ) )
return - V_76 ;
F_67 ( & V_32 -> V_38 , V_150 , V_153 , V_144 ) ;
F_67 ( & V_32 -> V_38 , V_150 , V_154 , V_33 ) ;
return 0 ;
case V_156 :
return F_99 ( V_53 , ( int ) ( unsigned long ) V_91 , V_44 ) ;
case V_157 :
V_3 = F_98 ( V_118 , V_53 -> V_98 ) ?
V_53 -> V_158 -> V_159 : 0 ;
if ( F_85 ( V_3 , V_126 ) )
return - V_76 ;
return 0 ;
case V_160 :
if ( V_91 )
return F_33 ( V_32 , V_2 ) ;
else
return F_36 ( V_32 , V_2 ) ;
case V_161 :
if ( V_91 )
return - V_55 ;
else
return F_96 ( V_32 , V_2 , V_44 ) ;
case V_162 :
if ( F_83 ( & V_3 , V_91 , sizeof( unsigned int ) ) )
return - V_76 ;
if ( V_3 != V_20 && V_3 != V_163 )
return - V_55 ;
V_2 -> V_19 = V_3 ;
return 0 ;
case V_164 :
return F_82 ( V_53 , V_91 ) ;
case V_165 :
return F_87 ( V_53 , V_91 ) ;
case V_166 :
return F_86 ( V_53 , V_91 ) ;
case V_167 :
return F_90 ( V_53 , V_91 ) ;
}
V_69 = F_100 ( V_139 ) ;
#define F_101 ( T_8 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_101 ( V_139 ) ) {
case F_102 ( 0 ) :
return F_76 ( V_53 -> V_168 , V_169 ,
V_69 , V_91 , V_97 ) ;
case F_103 ( 0 ) :
return F_93 ( V_53 , V_69 , V_126 ) ;
case F_104 ( 0 ) :
return F_91 ( V_2 , V_53 , V_100 , V_53 -> V_170 ,
V_102 , V_69 , V_91 , V_97 ) ;
case F_105 ( 0 ) :
return F_91 ( V_2 , V_53 , V_112 , V_53 -> V_171 ,
V_114 , V_69 , V_91 , V_97 ) ;
case F_106 ( 0 ) :
return F_91 ( V_2 , V_53 , V_115 , V_53 -> V_172 ,
V_117 , V_69 , V_91 , V_97 ) ;
case F_107 ( 0 ) :
return F_91 ( V_2 , V_53 , V_121 , V_53 -> V_173 ,
V_123 , V_69 , V_91 , V_97 ) ;
case F_108 ( 0 ) :
return F_80 ( V_53 -> V_174 , V_69 , V_91 ) ;
case F_109 ( 0 ) :
return F_80 ( V_53 -> V_175 , V_69 , V_91 ) ;
case F_110 ( 0 ) :
return F_80 ( V_53 -> V_176 , V_69 , V_91 ) ;
case F_101 ( V_177 ) :
if ( F_111 ( V_91 , V_69 , & V_142 ) )
return - V_76 ;
error = F_112 ( V_53 , & V_142 , V_44 ) ;
if ( error )
return error ;
if ( F_85 ( V_142 . V_47 , & ( ( (struct V_141 T_4 * ) V_91 ) -> V_47 ) ) )
return - V_76 ;
return 0 ;
}
if ( F_113 ( V_139 ) != 'E' )
return - V_55 ;
if ( F_114 ( V_139 ) == V_178 ) {
if ( ( F_115 ( V_139 ) & ~ V_99 ) == F_115 ( F_116 ( 0 , 0 ) ) )
return F_81 ( V_53 ,
F_115 ( V_139 ) & V_99 , V_69 ,
V_91 , V_97 ) ;
if ( ( F_115 ( V_139 ) & ~ V_108 ) == F_115 ( F_117 ( 0 ) ) ) {
if ( ! V_53 -> V_179 )
return - V_55 ;
V_143 = F_115 ( V_139 ) & V_108 ;
abs = V_53 -> V_179 [ V_143 ] ;
if ( F_78 ( V_91 , & abs , F_118 ( T_5 ,
V_69 , sizeof( struct V_140 ) ) ) )
return - V_76 ;
return 0 ;
}
}
if ( F_114 ( V_139 ) == V_180 ) {
if ( ( F_115 ( V_139 ) & ~ V_108 ) == F_115 ( F_119 ( 0 ) ) ) {
if ( ! V_53 -> V_179 )
return - V_55 ;
V_143 = F_115 ( V_139 ) & V_108 ;
if ( F_83 ( & abs , V_91 , F_118 ( T_5 ,
V_69 , sizeof( struct V_140 ) ) ) )
return - V_76 ;
if ( V_69 < sizeof( struct V_140 ) )
abs . V_181 = 0 ;
if ( V_143 == V_182 )
return - V_55 ;
F_69 ( & V_53 -> V_131 ) ;
V_53 -> V_179 [ V_143 ] = abs ;
F_70 ( & V_53 -> V_131 ) ;
return 0 ;
}
}
return - V_55 ;
}
static long F_120 ( struct V_44 * V_44 , unsigned int V_139 ,
void T_4 * V_91 , int V_97 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
int V_48 ;
V_48 = F_26 ( & V_32 -> V_49 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_32 -> V_50 || V_2 -> V_35 ) {
V_48 = - V_51 ;
goto V_75;
}
V_48 = F_97 ( V_44 , V_139 , V_91 , V_97 ) ;
V_75:
F_28 ( & V_32 -> V_49 ) ;
return V_48 ;
}
static long F_121 ( struct V_44 * V_44 , unsigned int V_139 , unsigned long V_183 )
{
return F_120 ( V_44 , V_139 , ( void T_4 * ) V_183 , 0 ) ;
}
static long F_122 ( struct V_44 * V_44 ,
unsigned int V_139 , unsigned long V_183 )
{
return F_120 ( V_44 , V_139 , F_123 ( V_183 ) , 1 ) ;
}
static void F_124 ( struct V_32 * V_32 )
{
F_48 ( & V_32 -> V_49 ) ;
V_32 -> V_50 = false ;
F_28 ( & V_32 -> V_49 ) ;
}
static void F_125 ( struct V_32 * V_32 )
{
struct V_37 * V_38 = & V_32 -> V_38 ;
F_124 ( V_32 ) ;
F_50 ( V_32 ) ;
F_126 ( & V_32 -> V_68 ) ;
if ( V_32 -> V_59 ) {
F_27 ( V_38 , NULL ) ;
F_49 ( V_38 ) ;
}
}
static int F_127 ( struct V_184 * V_185 , struct V_62 * V_53 ,
const struct V_186 * V_47 )
{
struct V_32 * V_32 ;
int V_187 ;
int V_188 ;
int error ;
V_187 = F_128 ( V_189 , V_190 , true ) ;
if ( V_187 < 0 ) {
error = V_187 ;
F_129 ( L_1 , error ) ;
return error ;
}
V_32 = F_59 ( sizeof( struct V_32 ) , V_70 ) ;
if ( ! V_32 ) {
error = - V_72 ;
goto V_191;
}
F_130 ( & V_32 -> V_58 ) ;
F_61 ( & V_32 -> V_56 ) ;
F_131 ( & V_32 -> V_49 ) ;
F_132 ( & V_32 -> V_36 ) ;
V_32 -> V_50 = true ;
V_188 = V_187 ;
if ( V_188 < V_189 + V_190 )
V_188 -= V_189 ;
F_133 ( & V_32 -> V_53 , L_2 , V_188 ) ;
V_32 -> V_38 . V_53 = F_134 ( V_53 ) ;
V_32 -> V_38 . V_174 = F_135 ( & V_32 -> V_53 ) ;
V_32 -> V_38 . V_185 = V_185 ;
V_32 -> V_38 . V_39 = V_32 ;
V_32 -> V_53 . V_192 = F_136 ( V_193 , V_187 ) ;
V_32 -> V_53 . V_194 = & V_195 ;
V_32 -> V_53 . V_196 = & V_53 -> V_53 ;
V_32 -> V_53 . V_197 = F_29 ;
F_137 ( & V_32 -> V_53 ) ;
error = F_138 ( & V_32 -> V_38 ) ;
if ( error )
goto V_198;
F_139 ( & V_32 -> V_68 , & V_199 ) ;
V_32 -> V_68 . V_200 . V_196 = & V_32 -> V_53 . V_200 ;
error = F_140 ( & V_32 -> V_68 , V_32 -> V_53 . V_192 , 1 ) ;
if ( error )
goto V_201;
error = F_141 ( & V_32 -> V_53 ) ;
if ( error )
goto V_202;
return 0 ;
V_202:
F_125 ( V_32 ) ;
V_201:
F_142 ( & V_32 -> V_38 ) ;
V_198:
F_143 ( & V_32 -> V_53 ) ;
V_191:
F_144 ( V_187 ) ;
return error ;
}
static void F_145 ( struct V_37 * V_38 )
{
struct V_32 * V_32 = V_38 -> V_39 ;
F_146 ( & V_32 -> V_53 ) ;
F_125 ( V_32 ) ;
F_144 ( F_147 ( V_32 -> V_53 . V_192 ) ) ;
F_142 ( V_38 ) ;
F_143 ( & V_32 -> V_53 ) ;
}
static int T_9 F_148 ( void )
{
return F_149 ( & V_203 ) ;
}
static void T_10 F_150 ( void )
{
F_151 ( & V_203 ) ;
}
