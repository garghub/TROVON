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
time = F_4 () ;
if ( V_2 -> V_19 != V_20 )
time = F_5 ( time , F_6 () ) ;
V_10 . time = F_7 ( time ) ;
V_10 . type = V_11 ;
V_10 . V_15 = V_21 ;
V_10 . V_17 = 0 ;
F_8 ( & V_2 -> V_22 , V_18 ) ;
V_2 -> V_14 [ V_2 -> V_4 ++ ] = V_10 ;
V_2 -> V_4 &= V_2 -> V_7 - 1 ;
if ( F_9 ( V_2 -> V_4 == V_2 -> V_12 ) ) {
V_2 -> V_12 = ( V_2 -> V_4 - 1 ) & ( V_2 -> V_7 - 1 ) ;
V_2 -> V_13 = V_2 -> V_12 ;
}
F_10 ( & V_2 -> V_22 , V_18 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
const struct V_9 * V_23 )
{
V_2 -> V_14 [ V_2 -> V_4 ++ ] = * V_23 ;
V_2 -> V_4 &= V_2 -> V_7 - 1 ;
if ( F_9 ( V_2 -> V_4 == V_2 -> V_12 ) ) {
V_2 -> V_12 = ( V_2 -> V_4 - 2 ) & ( V_2 -> V_7 - 1 ) ;
V_2 -> V_14 [ V_2 -> V_12 ] . time = V_23 -> time ;
V_2 -> V_14 [ V_2 -> V_12 ] . type = V_11 ;
V_2 -> V_14 [ V_2 -> V_12 ] . V_15 = V_21 ;
V_2 -> V_14 [ V_2 -> V_12 ] . V_17 = 0 ;
V_2 -> V_13 = V_2 -> V_12 ;
}
if ( V_23 -> type == V_11 && V_23 -> V_15 == V_16 ) {
V_2 -> V_13 = V_2 -> V_4 ;
F_12 ( & V_2 -> V_24 , V_25 , V_26 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
const struct V_27 * V_28 , unsigned int V_29 ,
T_1 V_30 , T_1 V_31 )
{
struct V_32 * V_32 = V_2 -> V_32 ;
const struct V_27 * V_33 ;
struct V_9 V_23 ;
bool V_34 = false ;
V_23 . time = F_7 ( V_2 -> V_19 == V_20 ?
V_30 : V_31 ) ;
F_14 ( & V_2 -> V_22 ) ;
for ( V_33 = V_28 ; V_33 != V_28 + V_29 ; V_33 ++ ) {
V_23 . type = V_33 -> type ;
V_23 . V_15 = V_33 -> V_15 ;
V_23 . V_17 = V_33 -> V_17 ;
F_11 ( V_2 , & V_23 ) ;
if ( V_33 -> type == V_11 && V_33 -> V_15 == V_16 )
V_34 = true ;
}
F_15 ( & V_2 -> V_22 ) ;
if ( V_34 )
F_16 ( & V_32 -> V_35 ) ;
}
static void F_17 ( struct V_36 * V_37 ,
const struct V_27 * V_28 , unsigned int V_29 )
{
struct V_32 * V_32 = V_37 -> V_38 ;
struct V_1 * V_2 ;
T_1 V_39 , V_40 ;
V_39 = F_4 () ;
V_40 = F_5 ( V_39 , F_6 () ) ;
F_18 () ;
V_2 = F_19 ( V_32 -> V_41 ) ;
if ( V_2 )
F_13 ( V_2 , V_28 , V_29 , V_39 , V_40 ) ;
else
F_20 (client, &evdev->client_list, node)
F_13 ( V_2 , V_28 , V_29 ,
V_39 , V_40 ) ;
F_21 () ;
}
static void F_22 ( struct V_36 * V_37 ,
unsigned int type , unsigned int V_15 , int V_17 )
{
struct V_27 V_28 [] = { { type , V_15 , V_17 } } ;
F_17 ( V_37 , V_28 , 1 ) ;
}
static int F_23 ( int V_42 , struct V_43 * V_43 , int V_44 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
return F_24 ( V_42 , V_43 , V_44 , & V_2 -> V_24 ) ;
}
static int F_25 ( struct V_43 * V_43 , T_2 V_46 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
struct V_32 * V_32 = V_2 -> V_32 ;
int V_47 ;
V_47 = F_26 ( & V_32 -> V_48 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_32 -> V_49 )
V_47 = - V_50 ;
else
V_47 = F_27 ( & V_32 -> V_37 , V_43 ) ;
F_28 ( & V_32 -> V_48 ) ;
return V_47 ;
}
static void F_29 ( struct V_51 * V_52 )
{
struct V_32 * V_32 = F_30 ( V_52 , struct V_32 , V_52 ) ;
F_31 ( V_32 -> V_37 . V_52 ) ;
F_32 ( V_32 ) ;
}
static int F_33 ( struct V_32 * V_32 , struct V_1 * V_2 )
{
int error ;
if ( V_32 -> V_41 )
return - V_53 ;
error = F_34 ( & V_32 -> V_37 ) ;
if ( error )
return error ;
F_35 ( V_32 -> V_41 , V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_32 * V_32 , struct V_1 * V_2 )
{
struct V_1 * V_41 = F_37 ( V_32 -> V_41 ,
F_38 ( & V_32 -> V_48 ) ) ;
if ( V_41 != V_2 )
return - V_54 ;
F_35 ( V_32 -> V_41 , NULL ) ;
F_39 () ;
F_40 ( & V_32 -> V_37 ) ;
return 0 ;
}
static void F_41 ( struct V_32 * V_32 ,
struct V_1 * V_2 )
{
F_14 ( & V_32 -> V_55 ) ;
F_42 ( & V_2 -> V_56 , & V_32 -> V_57 ) ;
F_15 ( & V_32 -> V_55 ) ;
}
static void F_43 ( struct V_32 * V_32 ,
struct V_1 * V_2 )
{
F_14 ( & V_32 -> V_55 ) ;
F_44 ( & V_2 -> V_56 ) ;
F_15 ( & V_32 -> V_55 ) ;
F_39 () ;
}
static int F_45 ( struct V_32 * V_32 )
{
int V_47 ;
V_47 = F_26 ( & V_32 -> V_48 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_32 -> V_49 )
V_47 = - V_50 ;
else if ( ! V_32 -> V_58 ++ ) {
V_47 = F_46 ( & V_32 -> V_37 ) ;
if ( V_47 )
V_32 -> V_58 -- ;
}
F_28 ( & V_32 -> V_48 ) ;
return V_47 ;
}
static void F_47 ( struct V_32 * V_32 )
{
F_48 ( & V_32 -> V_48 ) ;
if ( V_32 -> V_49 && ! -- V_32 -> V_58 )
F_49 ( & V_32 -> V_37 ) ;
F_28 ( & V_32 -> V_48 ) ;
}
static void F_50 ( struct V_32 * V_32 )
{
struct V_1 * V_2 ;
F_14 ( & V_32 -> V_55 ) ;
F_51 (client, &evdev->client_list, node)
F_12 ( & V_2 -> V_24 , V_25 , V_59 ) ;
F_15 ( & V_32 -> V_55 ) ;
F_16 ( & V_32 -> V_35 ) ;
}
static int F_52 ( struct V_60 * V_60 , struct V_43 * V_43 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
struct V_32 * V_32 = V_2 -> V_32 ;
F_48 ( & V_32 -> V_48 ) ;
F_36 ( V_32 , V_2 ) ;
F_28 ( & V_32 -> V_48 ) ;
F_43 ( V_32 , V_2 ) ;
F_32 ( V_2 ) ;
F_47 ( V_32 ) ;
return 0 ;
}
static unsigned int F_53 ( struct V_61 * V_52 )
{
unsigned int V_62 =
F_54 ( V_52 -> V_63 * V_64 ,
V_65 ) ;
return F_55 ( V_62 ) ;
}
static int F_56 ( struct V_60 * V_60 , struct V_43 * V_43 )
{
struct V_32 * V_32 = F_30 ( V_60 -> V_66 , struct V_32 , V_67 ) ;
unsigned int V_7 = F_53 ( V_32 -> V_37 . V_52 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_57 ( sizeof( struct V_1 ) +
V_7 * sizeof( struct V_9 ) ,
V_68 ) ;
if ( ! V_2 )
return - V_69 ;
V_2 -> V_7 = V_7 ;
F_58 ( & V_2 -> V_22 ) ;
V_2 -> V_32 = V_32 ;
F_41 ( V_32 , V_2 ) ;
error = F_45 ( V_32 ) ;
if ( error )
goto V_70;
V_43 -> V_45 = V_2 ;
F_59 ( V_60 , V_43 ) ;
return 0 ;
V_70:
F_43 ( V_32 , V_2 ) ;
F_32 ( V_2 ) ;
return error ;
}
static T_3 F_60 ( struct V_43 * V_43 , const char T_4 * V_14 ,
T_5 V_29 , T_6 * V_71 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_9 V_23 ;
int V_47 = 0 ;
if ( V_29 != 0 && V_29 < F_61 () )
return - V_54 ;
V_47 = F_26 ( & V_32 -> V_48 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_32 -> V_49 ) {
V_47 = - V_50 ;
goto V_72;
}
while ( V_47 + F_61 () <= V_29 ) {
if ( F_62 ( V_14 + V_47 , & V_23 ) ) {
V_47 = - V_73 ;
goto V_72;
}
V_47 += F_61 () ;
F_63 ( & V_32 -> V_37 ,
V_23 . type , V_23 . V_15 , V_23 . V_17 ) ;
}
V_72:
F_28 ( & V_32 -> V_48 ) ;
return V_47 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_9 * V_23 )
{
int V_74 ;
F_65 ( & V_2 -> V_22 ) ;
V_74 = V_2 -> V_13 != V_2 -> V_12 ;
if ( V_74 ) {
* V_23 = V_2 -> V_14 [ V_2 -> V_12 ++ ] ;
V_2 -> V_12 &= V_2 -> V_7 - 1 ;
}
F_66 ( & V_2 -> V_22 ) ;
return V_74 ;
}
static T_3 F_67 ( struct V_43 * V_43 , char T_4 * V_14 ,
T_5 V_29 , T_6 * V_71 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_9 V_23 ;
T_5 V_75 = 0 ;
int error ;
if ( V_29 != 0 && V_29 < F_61 () )
return - V_54 ;
for (; ; ) {
if ( ! V_32 -> V_49 )
return - V_50 ;
if ( V_2 -> V_13 == V_2 -> V_12 &&
( V_43 -> V_76 & V_77 ) )
return - V_78 ;
if ( V_29 == 0 )
break;
while ( V_75 + F_61 () <= V_29 &&
F_64 ( V_2 , & V_23 ) ) {
if ( F_68 ( V_14 + V_75 , & V_23 ) )
return - V_73 ;
V_75 += F_61 () ;
}
if ( V_75 )
break;
if ( ! ( V_43 -> V_76 & V_77 ) ) {
error = F_69 ( V_32 -> V_35 ,
V_2 -> V_13 != V_2 -> V_12 ||
! V_32 -> V_49 ) ;
if ( error )
return error ;
}
}
return V_75 ;
}
static unsigned int F_70 ( struct V_43 * V_43 , T_7 * V_35 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
struct V_32 * V_32 = V_2 -> V_32 ;
unsigned int V_6 ;
F_71 ( V_43 , & V_32 -> V_35 , V_35 ) ;
V_6 = V_32 -> V_49 ? V_79 | V_80 : V_81 | V_82 ;
if ( V_2 -> V_13 != V_2 -> V_12 )
V_6 |= V_83 | V_84 ;
return V_6 ;
}
static int F_72 ( unsigned long * V_85 , unsigned int V_86 ,
unsigned int V_87 , void T_4 * V_88 , int V_89 )
{
int V_90 , V_3 ;
if ( V_89 ) {
V_90 = F_73 ( V_86 ) * sizeof( V_91 ) ;
if ( V_90 > V_87 )
V_90 = V_87 ;
for ( V_3 = 0 ; V_3 < V_90 / sizeof( V_91 ) ; V_3 ++ )
if ( F_74 ( ( V_91 T_4 * ) V_88 + V_3 ,
( V_91 * ) V_85 +
V_3 + 1 - ( ( V_3 % 2 ) << 1 ) ,
sizeof( V_91 ) ) )
return - V_73 ;
} else {
V_90 = F_75 ( V_86 ) * sizeof( long ) ;
if ( V_90 > V_87 )
V_90 = V_87 ;
if ( F_74 ( V_88 , V_85 , V_90 ) )
return - V_73 ;
}
return V_90 ;
}
static int F_72 ( unsigned long * V_85 , unsigned int V_86 ,
unsigned int V_87 , void T_4 * V_88 , int V_89 )
{
int V_90 = V_89 ?
F_73 ( V_86 ) * sizeof( V_91 ) :
F_75 ( V_86 ) * sizeof( long ) ;
if ( V_90 > V_87 )
V_90 = V_87 ;
return F_74 ( V_88 , V_85 , V_90 ) ? - V_73 : V_90 ;
}
static int F_72 ( unsigned long * V_85 , unsigned int V_86 ,
unsigned int V_87 , void T_4 * V_88 , int V_89 )
{
int V_90 = F_75 ( V_86 ) * sizeof( long ) ;
if ( V_90 > V_87 )
V_90 = V_87 ;
return F_74 ( V_88 , V_85 , V_90 ) ? - V_73 : V_90 ;
}
static int F_76 ( const char * V_92 , unsigned int V_87 , void T_4 * V_88 )
{
int V_90 ;
if ( ! V_92 )
return - V_93 ;
V_90 = strlen ( V_92 ) + 1 ;
if ( V_90 > V_87 )
V_90 = V_87 ;
return F_74 ( V_88 , V_92 , V_90 ) ? - V_73 : V_90 ;
}
static int F_77 ( struct V_61 * V_52 ,
unsigned int type , unsigned int V_94 ,
void T_4 * V_88 , int V_95 )
{
static unsigned long V_96 ;
unsigned long * V_85 ;
int V_90 ;
switch ( type ) {
case 0 : V_85 = V_52 -> V_97 ; V_90 = V_98 ; break;
case V_99 : V_85 = V_52 -> V_100 ; V_90 = V_101 ; break;
case V_102 : V_85 = V_52 -> V_103 ; V_90 = V_104 ; break;
case V_105 : V_85 = V_52 -> V_106 ; V_90 = V_107 ; break;
case V_108 : V_85 = V_52 -> V_109 ; V_90 = V_110 ; break;
case V_111 : V_85 = V_52 -> V_112 ; V_90 = V_113 ; break;
case V_114 : V_85 = V_52 -> V_115 ; V_90 = V_116 ; break;
case V_117 : V_85 = V_52 -> V_118 ; V_90 = V_119 ; break;
case V_120 : V_85 = V_52 -> V_121 ; V_90 = V_122 ; break;
default: return - V_54 ;
}
if ( type == V_99 && V_94 == V_123 ) {
V_90 = V_123 ;
if ( F_78 ( & V_96 , 10 * 1000 ) )
F_79 ( L_1
L_2
L_3 ,
V_123 ,
F_75 ( V_123 ) * sizeof( long ) ) ;
}
return F_72 ( V_85 , V_90 , V_94 , V_88 , V_95 ) ;
}
static int F_80 ( struct V_61 * V_52 , void T_4 * V_88 )
{
struct V_124 V_125 = {
. V_90 = sizeof( unsigned int ) ,
. V_18 = 0 ,
} ;
int T_4 * V_126 = ( int T_4 * ) V_88 ;
int error ;
if ( F_81 ( V_125 . V_127 , V_88 , sizeof( unsigned int ) ) )
return - V_73 ;
error = F_82 ( V_52 , & V_125 ) ;
if ( error )
return error ;
if ( F_83 ( V_125 . V_128 , V_126 + 1 ) )
return - V_73 ;
return 0 ;
}
static int F_84 ( struct V_61 * V_52 , void T_4 * V_88 )
{
struct V_124 V_125 ;
int error ;
if ( F_81 ( & V_125 , V_88 , sizeof( V_125 ) ) )
return - V_73 ;
error = F_82 ( V_52 , & V_125 ) ;
if ( error )
return error ;
if ( F_74 ( V_88 , & V_125 , sizeof( V_125 ) ) )
return - V_73 ;
return 0 ;
}
static int F_85 ( struct V_61 * V_52 , void T_4 * V_88 )
{
struct V_124 V_125 = {
. V_90 = sizeof( unsigned int ) ,
. V_18 = 0 ,
} ;
int T_4 * V_126 = ( int T_4 * ) V_88 ;
if ( F_81 ( V_125 . V_127 , V_88 , sizeof( unsigned int ) ) )
return - V_73 ;
if ( F_86 ( V_125 . V_128 , V_126 + 1 ) )
return - V_73 ;
return F_87 ( V_52 , & V_125 ) ;
}
static int F_88 ( struct V_61 * V_52 , void T_4 * V_88 )
{
struct V_124 V_125 ;
if ( F_81 ( & V_125 , V_88 , sizeof( V_125 ) ) )
return - V_73 ;
if ( V_125 . V_90 > sizeof( V_125 . V_127 ) )
return - V_54 ;
return F_87 ( V_52 , & V_125 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_61 * V_52 , unsigned int type ,
unsigned long * V_85 , unsigned int F_54 ,
unsigned int V_94 , void T_4 * V_88 , int V_89 )
{
int V_129 ;
unsigned long * V_130 ;
V_130 = F_90 ( sizeof( unsigned long ) * F_54 , V_68 ) ;
if ( ! V_130 )
return - V_69 ;
F_65 ( & V_52 -> V_131 ) ;
F_14 ( & V_2 -> V_22 ) ;
memcpy ( V_130 , V_85 , sizeof( unsigned long ) * F_54 ) ;
F_15 ( & V_52 -> V_131 ) ;
F_1 ( V_2 , type ) ;
F_66 ( & V_2 -> V_22 ) ;
V_129 = F_72 ( V_130 , F_54 , V_94 , V_88 , V_89 ) ;
if ( V_129 < 0 )
F_3 ( V_2 ) ;
F_32 ( V_130 ) ;
return V_129 ;
}
static int F_91 ( struct V_61 * V_52 ,
unsigned int V_94 ,
int T_4 * V_126 )
{
const struct V_132 * V_133 = V_52 -> V_133 ;
unsigned int V_15 ;
int V_134 ;
int V_3 ;
if ( F_86 ( V_15 , & V_126 [ 0 ] ) )
return - V_73 ;
if ( ! V_133 || ! F_92 ( V_15 ) )
return - V_54 ;
V_134 = ( V_94 - sizeof( V_135 ) ) / sizeof( V_136 ) ;
for ( V_3 = 0 ; V_3 < V_133 -> V_137 && V_3 < V_134 ; V_3 ++ ) {
int V_17 = F_93 ( & V_133 -> V_138 [ V_3 ] , V_15 ) ;
if ( F_83 ( V_17 , & V_126 [ 1 + V_3 ] ) )
return - V_73 ;
}
return 0 ;
}
static long F_94 ( struct V_43 * V_43 , unsigned int V_139 ,
void T_4 * V_88 , int V_95 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_61 * V_52 = V_32 -> V_37 . V_52 ;
struct V_140 abs ;
struct V_141 V_142 ;
int T_4 * V_126 = ( int T_4 * ) V_88 ;
unsigned int V_3 , V_143 , V_144 , V_33 ;
unsigned int V_94 ;
int error ;
switch ( V_139 ) {
case V_145 :
return F_83 ( V_146 , V_126 ) ;
case V_147 :
if ( F_74 ( V_88 , & V_52 -> V_46 , sizeof( struct V_148 ) ) )
return - V_73 ;
return 0 ;
case V_149 :
if ( ! F_95 ( V_150 , V_52 -> V_97 ) )
return - V_151 ;
if ( F_83 ( V_52 -> V_152 [ V_153 ] , V_126 ) )
return - V_73 ;
if ( F_83 ( V_52 -> V_152 [ V_154 ] , V_126 + 1 ) )
return - V_73 ;
return 0 ;
case V_155 :
if ( ! F_95 ( V_150 , V_52 -> V_97 ) )
return - V_151 ;
if ( F_86 ( V_144 , V_126 ) )
return - V_73 ;
if ( F_86 ( V_33 , V_126 + 1 ) )
return - V_73 ;
F_63 ( & V_32 -> V_37 , V_150 , V_153 , V_144 ) ;
F_63 ( & V_32 -> V_37 , V_150 , V_154 , V_33 ) ;
return 0 ;
case V_156 :
return F_96 ( V_52 , ( int ) ( unsigned long ) V_88 , V_43 ) ;
case V_157 :
V_3 = F_95 ( V_117 , V_52 -> V_97 ) ?
V_52 -> V_158 -> V_159 : 0 ;
if ( F_83 ( V_3 , V_126 ) )
return - V_73 ;
return 0 ;
case V_160 :
if ( V_88 )
return F_33 ( V_32 , V_2 ) ;
else
return F_36 ( V_32 , V_2 ) ;
case V_161 :
if ( F_81 ( & V_3 , V_88 , sizeof( unsigned int ) ) )
return - V_73 ;
if ( V_3 != V_20 && V_3 != V_162 )
return - V_54 ;
V_2 -> V_19 = V_3 ;
return 0 ;
case V_163 :
return F_80 ( V_52 , V_88 ) ;
case V_164 :
return F_85 ( V_52 , V_88 ) ;
case V_165 :
return F_84 ( V_52 , V_88 ) ;
case V_166 :
return F_88 ( V_52 , V_88 ) ;
}
V_94 = F_97 ( V_139 ) ;
#define F_98 ( T_8 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_98 ( V_139 ) ) {
case F_99 ( 0 ) :
return F_72 ( V_52 -> V_167 , V_168 ,
V_94 , V_88 , V_95 ) ;
case F_100 ( 0 ) :
return F_91 ( V_52 , V_94 , V_126 ) ;
case F_101 ( 0 ) :
return F_89 ( V_2 , V_52 , V_99 , V_52 -> V_169 ,
V_101 , V_94 , V_88 , V_95 ) ;
case F_102 ( 0 ) :
return F_89 ( V_2 , V_52 , V_111 , V_52 -> V_170 ,
V_113 , V_94 , V_88 , V_95 ) ;
case F_103 ( 0 ) :
return F_89 ( V_2 , V_52 , V_114 , V_52 -> V_171 ,
V_116 , V_94 , V_88 , V_95 ) ;
case F_104 ( 0 ) :
return F_89 ( V_2 , V_52 , V_120 , V_52 -> V_172 ,
V_122 , V_94 , V_88 , V_95 ) ;
case F_105 ( 0 ) :
return F_76 ( V_52 -> V_173 , V_94 , V_88 ) ;
case F_106 ( 0 ) :
return F_76 ( V_52 -> V_174 , V_94 , V_88 ) ;
case F_107 ( 0 ) :
return F_76 ( V_52 -> V_175 , V_94 , V_88 ) ;
case F_98 ( V_176 ) :
if ( F_108 ( V_88 , V_94 , & V_142 ) )
return - V_73 ;
error = F_109 ( V_52 , & V_142 , V_43 ) ;
if ( F_83 ( V_142 . V_46 , & ( ( (struct V_141 T_4 * ) V_88 ) -> V_46 ) ) )
return - V_73 ;
return error ;
}
if ( F_110 ( V_139 ) != 'E' )
return - V_54 ;
if ( F_111 ( V_139 ) == V_177 ) {
if ( ( F_112 ( V_139 ) & ~ V_98 ) == F_112 ( F_113 ( 0 , 0 ) ) )
return F_77 ( V_52 ,
F_112 ( V_139 ) & V_98 , V_94 ,
V_88 , V_95 ) ;
if ( ( F_112 ( V_139 ) & ~ V_107 ) == F_112 ( F_114 ( 0 ) ) ) {
if ( ! V_52 -> V_178 )
return - V_54 ;
V_143 = F_112 ( V_139 ) & V_107 ;
abs = V_52 -> V_178 [ V_143 ] ;
if ( F_74 ( V_88 , & abs , F_115 ( T_5 ,
V_94 , sizeof( struct V_140 ) ) ) )
return - V_73 ;
return 0 ;
}
}
if ( F_111 ( V_139 ) == V_179 ) {
if ( ( F_112 ( V_139 ) & ~ V_107 ) == F_112 ( F_116 ( 0 ) ) ) {
if ( ! V_52 -> V_178 )
return - V_54 ;
V_143 = F_112 ( V_139 ) & V_107 ;
if ( F_81 ( & abs , V_88 , F_115 ( T_5 ,
V_94 , sizeof( struct V_140 ) ) ) )
return - V_73 ;
if ( V_94 < sizeof( struct V_140 ) )
abs . V_180 = 0 ;
if ( V_143 == V_181 )
return - V_54 ;
F_65 ( & V_52 -> V_131 ) ;
V_52 -> V_178 [ V_143 ] = abs ;
F_66 ( & V_52 -> V_131 ) ;
return 0 ;
}
}
return - V_54 ;
}
static long F_117 ( struct V_43 * V_43 , unsigned int V_139 ,
void T_4 * V_88 , int V_95 )
{
struct V_1 * V_2 = V_43 -> V_45 ;
struct V_32 * V_32 = V_2 -> V_32 ;
int V_47 ;
V_47 = F_26 ( & V_32 -> V_48 ) ;
if ( V_47 )
return V_47 ;
if ( ! V_32 -> V_49 ) {
V_47 = - V_50 ;
goto V_72;
}
V_47 = F_94 ( V_43 , V_139 , V_88 , V_95 ) ;
V_72:
F_28 ( & V_32 -> V_48 ) ;
return V_47 ;
}
static long F_118 ( struct V_43 * V_43 , unsigned int V_139 , unsigned long V_182 )
{
return F_117 ( V_43 , V_139 , ( void T_4 * ) V_182 , 0 ) ;
}
static long F_119 ( struct V_43 * V_43 ,
unsigned int V_139 , unsigned long V_182 )
{
return F_117 ( V_43 , V_139 , F_120 ( V_182 ) , 1 ) ;
}
static void F_121 ( struct V_32 * V_32 )
{
F_48 ( & V_32 -> V_48 ) ;
V_32 -> V_49 = false ;
F_28 ( & V_32 -> V_48 ) ;
}
static void F_122 ( struct V_32 * V_32 )
{
struct V_36 * V_37 = & V_32 -> V_37 ;
F_121 ( V_32 ) ;
F_50 ( V_32 ) ;
F_123 ( & V_32 -> V_67 ) ;
if ( V_32 -> V_58 ) {
F_27 ( V_37 , NULL ) ;
F_49 ( V_37 ) ;
}
}
static int F_124 ( struct V_183 * V_184 , struct V_61 * V_52 ,
const struct V_185 * V_46 )
{
struct V_32 * V_32 ;
int V_186 ;
int V_187 ;
int error ;
V_186 = F_125 ( V_188 , V_189 , true ) ;
if ( V_186 < 0 ) {
error = V_186 ;
F_126 ( L_4 , error ) ;
return error ;
}
V_32 = F_57 ( sizeof( struct V_32 ) , V_68 ) ;
if ( ! V_32 ) {
error = - V_69 ;
goto V_190;
}
F_127 ( & V_32 -> V_57 ) ;
F_58 ( & V_32 -> V_55 ) ;
F_128 ( & V_32 -> V_48 ) ;
F_129 ( & V_32 -> V_35 ) ;
V_32 -> V_49 = true ;
V_187 = V_186 ;
if ( V_187 < V_188 + V_189 )
V_187 -= V_188 ;
F_130 ( & V_32 -> V_52 , L_5 , V_187 ) ;
V_32 -> V_37 . V_52 = F_131 ( V_52 ) ;
V_32 -> V_37 . V_173 = F_132 ( & V_32 -> V_52 ) ;
V_32 -> V_37 . V_184 = V_184 ;
V_32 -> V_37 . V_38 = V_32 ;
V_32 -> V_52 . V_191 = F_133 ( V_192 , V_186 ) ;
V_32 -> V_52 . V_193 = & V_194 ;
V_32 -> V_52 . V_195 = & V_52 -> V_52 ;
V_32 -> V_52 . V_196 = F_29 ;
F_134 ( & V_32 -> V_52 ) ;
error = F_135 ( & V_32 -> V_37 ) ;
if ( error )
goto V_197;
F_136 ( & V_32 -> V_67 , & V_198 ) ;
V_32 -> V_67 . V_199 . V_195 = & V_32 -> V_52 . V_199 ;
error = F_137 ( & V_32 -> V_67 , V_32 -> V_52 . V_191 , 1 ) ;
if ( error )
goto V_200;
error = F_138 ( & V_32 -> V_52 ) ;
if ( error )
goto V_201;
return 0 ;
V_201:
F_122 ( V_32 ) ;
V_200:
F_139 ( & V_32 -> V_37 ) ;
V_197:
F_140 ( & V_32 -> V_52 ) ;
V_190:
F_141 ( V_186 ) ;
return error ;
}
static void F_142 ( struct V_36 * V_37 )
{
struct V_32 * V_32 = V_37 -> V_38 ;
F_143 ( & V_32 -> V_52 ) ;
F_122 ( V_32 ) ;
F_141 ( F_144 ( V_32 -> V_52 . V_191 ) ) ;
F_139 ( V_37 ) ;
F_140 ( & V_32 -> V_52 ) ;
}
static int T_9 F_145 ( void )
{
return F_146 ( & V_202 ) ;
}
static void T_10 F_147 ( void )
{
F_148 ( & V_202 ) ;
}
