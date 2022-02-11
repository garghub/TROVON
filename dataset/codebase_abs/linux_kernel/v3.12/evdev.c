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
if ( V_2 -> V_35 )
return;
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
F_16 ( & V_32 -> V_36 ) ;
}
static void F_17 ( struct V_37 * V_38 ,
const struct V_27 * V_28 , unsigned int V_29 )
{
struct V_32 * V_32 = V_38 -> V_39 ;
struct V_1 * V_2 ;
T_1 V_40 , V_41 ;
V_40 = F_4 () ;
V_41 = F_5 ( V_40 , F_6 () ) ;
F_18 () ;
V_2 = F_19 ( V_32 -> V_42 ) ;
if ( V_2 )
F_13 ( V_2 , V_28 , V_29 , V_40 , V_41 ) ;
else
F_20 (client, &evdev->client_list, node)
F_13 ( V_2 , V_28 , V_29 ,
V_40 , V_41 ) ;
F_21 () ;
}
static void F_22 ( struct V_37 * V_38 ,
unsigned int type , unsigned int V_15 , int V_17 )
{
struct V_27 V_28 [] = { { type , V_15 , V_17 } } ;
F_17 ( V_38 , V_28 , 1 ) ;
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
F_14 ( & V_32 -> V_56 ) ;
F_42 ( & V_2 -> V_57 , & V_32 -> V_58 ) ;
F_15 ( & V_32 -> V_56 ) ;
}
static void F_43 ( struct V_32 * V_32 ,
struct V_1 * V_2 )
{
F_14 ( & V_32 -> V_56 ) ;
F_44 ( & V_2 -> V_57 ) ;
F_15 ( & V_32 -> V_56 ) ;
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
F_14 ( & V_32 -> V_56 ) ;
F_51 (client, &evdev->client_list, node)
F_12 ( & V_2 -> V_24 , V_25 , V_60 ) ;
F_15 ( & V_32 -> V_56 ) ;
F_16 ( & V_32 -> V_36 ) ;
}
static int F_52 ( struct V_61 * V_61 , struct V_44 * V_44 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
F_48 ( & V_32 -> V_49 ) ;
F_36 ( V_32 , V_2 ) ;
F_28 ( & V_32 -> V_49 ) ;
F_43 ( V_32 , V_2 ) ;
F_32 ( V_2 ) ;
F_47 ( V_32 ) ;
return 0 ;
}
static unsigned int F_53 ( struct V_62 * V_53 )
{
unsigned int V_63 =
F_54 ( V_53 -> V_64 * V_65 ,
V_66 ) ;
return F_55 ( V_63 ) ;
}
static int F_56 ( struct V_61 * V_61 , struct V_44 * V_44 )
{
struct V_32 * V_32 = F_30 ( V_61 -> V_67 , struct V_32 , V_68 ) ;
unsigned int V_7 = F_53 ( V_32 -> V_38 . V_53 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_57 ( sizeof( struct V_1 ) +
V_7 * sizeof( struct V_9 ) ,
V_69 ) ;
if ( ! V_2 )
return - V_70 ;
V_2 -> V_7 = V_7 ;
F_58 ( & V_2 -> V_22 ) ;
V_2 -> V_32 = V_32 ;
F_41 ( V_32 , V_2 ) ;
error = F_45 ( V_32 ) ;
if ( error )
goto V_71;
V_44 -> V_46 = V_2 ;
F_59 ( V_61 , V_44 ) ;
return 0 ;
V_71:
F_43 ( V_32 , V_2 ) ;
F_32 ( V_2 ) ;
return error ;
}
static T_3 F_60 ( struct V_44 * V_44 , const char T_4 * V_14 ,
T_5 V_29 , T_6 * V_72 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_9 V_23 ;
int V_48 = 0 ;
if ( V_29 != 0 && V_29 < F_61 () )
return - V_55 ;
V_48 = F_26 ( & V_32 -> V_49 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_32 -> V_50 || V_2 -> V_35 ) {
V_48 = - V_51 ;
goto V_73;
}
while ( V_48 + F_61 () <= V_29 ) {
if ( F_62 ( V_14 + V_48 , & V_23 ) ) {
V_48 = - V_74 ;
goto V_73;
}
V_48 += F_61 () ;
F_63 ( & V_32 -> V_38 ,
V_23 . type , V_23 . V_15 , V_23 . V_17 ) ;
}
V_73:
F_28 ( & V_32 -> V_49 ) ;
return V_48 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_9 * V_23 )
{
int V_75 ;
F_65 ( & V_2 -> V_22 ) ;
V_75 = V_2 -> V_13 != V_2 -> V_12 ;
if ( V_75 ) {
* V_23 = V_2 -> V_14 [ V_2 -> V_12 ++ ] ;
V_2 -> V_12 &= V_2 -> V_7 - 1 ;
}
F_66 ( & V_2 -> V_22 ) ;
return V_75 ;
}
static T_3 F_67 ( struct V_44 * V_44 , char T_4 * V_14 ,
T_5 V_29 , T_6 * V_72 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_9 V_23 ;
T_5 V_76 = 0 ;
int error ;
if ( V_29 != 0 && V_29 < F_61 () )
return - V_55 ;
for (; ; ) {
if ( ! V_32 -> V_50 || V_2 -> V_35 )
return - V_51 ;
if ( V_2 -> V_13 == V_2 -> V_12 &&
( V_44 -> V_77 & V_78 ) )
return - V_79 ;
if ( V_29 == 0 )
break;
while ( V_76 + F_61 () <= V_29 &&
F_64 ( V_2 , & V_23 ) ) {
if ( F_68 ( V_14 + V_76 , & V_23 ) )
return - V_74 ;
V_76 += F_61 () ;
}
if ( V_76 )
break;
if ( ! ( V_44 -> V_77 & V_78 ) ) {
error = F_69 ( V_32 -> V_36 ,
V_2 -> V_13 != V_2 -> V_12 ||
! V_32 -> V_50 || V_2 -> V_35 ) ;
if ( error )
return error ;
}
}
return V_76 ;
}
static unsigned int F_70 ( struct V_44 * V_44 , T_7 * V_36 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
unsigned int V_6 ;
F_71 ( V_44 , & V_32 -> V_36 , V_36 ) ;
if ( V_32 -> V_50 && ! V_2 -> V_35 )
V_6 = V_80 | V_81 ;
else
V_6 = V_82 | V_83 ;
if ( V_2 -> V_13 != V_2 -> V_12 )
V_6 |= V_84 | V_85 ;
return V_6 ;
}
static int F_72 ( unsigned long * V_86 , unsigned int V_87 ,
unsigned int V_88 , void T_4 * V_89 , int V_90 )
{
int V_91 , V_3 ;
if ( V_90 ) {
V_91 = F_73 ( V_87 ) * sizeof( V_92 ) ;
if ( V_91 > V_88 )
V_91 = V_88 ;
for ( V_3 = 0 ; V_3 < V_91 / sizeof( V_92 ) ; V_3 ++ )
if ( F_74 ( ( V_92 T_4 * ) V_89 + V_3 ,
( V_92 * ) V_86 +
V_3 + 1 - ( ( V_3 % 2 ) << 1 ) ,
sizeof( V_92 ) ) )
return - V_74 ;
} else {
V_91 = F_75 ( V_87 ) * sizeof( long ) ;
if ( V_91 > V_88 )
V_91 = V_88 ;
if ( F_74 ( V_89 , V_86 , V_91 ) )
return - V_74 ;
}
return V_91 ;
}
static int F_72 ( unsigned long * V_86 , unsigned int V_87 ,
unsigned int V_88 , void T_4 * V_89 , int V_90 )
{
int V_91 = V_90 ?
F_73 ( V_87 ) * sizeof( V_92 ) :
F_75 ( V_87 ) * sizeof( long ) ;
if ( V_91 > V_88 )
V_91 = V_88 ;
return F_74 ( V_89 , V_86 , V_91 ) ? - V_74 : V_91 ;
}
static int F_72 ( unsigned long * V_86 , unsigned int V_87 ,
unsigned int V_88 , void T_4 * V_89 , int V_90 )
{
int V_91 = F_75 ( V_87 ) * sizeof( long ) ;
if ( V_91 > V_88 )
V_91 = V_88 ;
return F_74 ( V_89 , V_86 , V_91 ) ? - V_74 : V_91 ;
}
static int F_76 ( const char * V_93 , unsigned int V_88 , void T_4 * V_89 )
{
int V_91 ;
if ( ! V_93 )
return - V_94 ;
V_91 = strlen ( V_93 ) + 1 ;
if ( V_91 > V_88 )
V_91 = V_88 ;
return F_74 ( V_89 , V_93 , V_91 ) ? - V_74 : V_91 ;
}
static int F_77 ( struct V_62 * V_53 ,
unsigned int type , unsigned int V_95 ,
void T_4 * V_89 , int V_96 )
{
static unsigned long V_97 ;
unsigned long * V_86 ;
int V_91 ;
switch ( type ) {
case 0 : V_86 = V_53 -> V_98 ; V_91 = V_99 ; break;
case V_100 : V_86 = V_53 -> V_101 ; V_91 = V_102 ; break;
case V_103 : V_86 = V_53 -> V_104 ; V_91 = V_105 ; break;
case V_106 : V_86 = V_53 -> V_107 ; V_91 = V_108 ; break;
case V_109 : V_86 = V_53 -> V_110 ; V_91 = V_111 ; break;
case V_112 : V_86 = V_53 -> V_113 ; V_91 = V_114 ; break;
case V_115 : V_86 = V_53 -> V_116 ; V_91 = V_117 ; break;
case V_118 : V_86 = V_53 -> V_119 ; V_91 = V_120 ; break;
case V_121 : V_86 = V_53 -> V_122 ; V_91 = V_123 ; break;
default: return - V_55 ;
}
if ( type == V_100 && V_95 == V_124 ) {
V_91 = V_124 ;
if ( F_78 ( & V_97 , 10 * 1000 ) )
F_79 ( L_1
L_2
L_3 ,
V_124 ,
F_75 ( V_124 ) * sizeof( long ) ) ;
}
return F_72 ( V_86 , V_91 , V_95 , V_89 , V_96 ) ;
}
static int F_80 ( struct V_62 * V_53 , void T_4 * V_89 )
{
struct V_125 V_126 = {
. V_91 = sizeof( unsigned int ) ,
. V_18 = 0 ,
} ;
int T_4 * V_127 = ( int T_4 * ) V_89 ;
int error ;
if ( F_81 ( V_126 . V_128 , V_89 , sizeof( unsigned int ) ) )
return - V_74 ;
error = F_82 ( V_53 , & V_126 ) ;
if ( error )
return error ;
if ( F_83 ( V_126 . V_129 , V_127 + 1 ) )
return - V_74 ;
return 0 ;
}
static int F_84 ( struct V_62 * V_53 , void T_4 * V_89 )
{
struct V_125 V_126 ;
int error ;
if ( F_81 ( & V_126 , V_89 , sizeof( V_126 ) ) )
return - V_74 ;
error = F_82 ( V_53 , & V_126 ) ;
if ( error )
return error ;
if ( F_74 ( V_89 , & V_126 , sizeof( V_126 ) ) )
return - V_74 ;
return 0 ;
}
static int F_85 ( struct V_62 * V_53 , void T_4 * V_89 )
{
struct V_125 V_126 = {
. V_91 = sizeof( unsigned int ) ,
. V_18 = 0 ,
} ;
int T_4 * V_127 = ( int T_4 * ) V_89 ;
if ( F_81 ( V_126 . V_128 , V_89 , sizeof( unsigned int ) ) )
return - V_74 ;
if ( F_86 ( V_126 . V_129 , V_127 + 1 ) )
return - V_74 ;
return F_87 ( V_53 , & V_126 ) ;
}
static int F_88 ( struct V_62 * V_53 , void T_4 * V_89 )
{
struct V_125 V_126 ;
if ( F_81 ( & V_126 , V_89 , sizeof( V_126 ) ) )
return - V_74 ;
if ( V_126 . V_91 > sizeof( V_126 . V_128 ) )
return - V_55 ;
return F_87 ( V_53 , & V_126 ) ;
}
static int F_89 ( struct V_1 * V_2 ,
struct V_62 * V_53 , unsigned int type ,
unsigned long * V_86 , unsigned int F_54 ,
unsigned int V_95 , void T_4 * V_89 , int V_90 )
{
int V_130 ;
unsigned long * V_131 ;
V_131 = F_90 ( sizeof( unsigned long ) * F_54 , V_69 ) ;
if ( ! V_131 )
return - V_70 ;
F_65 ( & V_53 -> V_132 ) ;
F_14 ( & V_2 -> V_22 ) ;
memcpy ( V_131 , V_86 , sizeof( unsigned long ) * F_54 ) ;
F_15 ( & V_53 -> V_132 ) ;
F_1 ( V_2 , type ) ;
F_66 ( & V_2 -> V_22 ) ;
V_130 = F_72 ( V_131 , F_54 , V_95 , V_89 , V_90 ) ;
if ( V_130 < 0 )
F_3 ( V_2 ) ;
F_32 ( V_131 ) ;
return V_130 ;
}
static int F_91 ( struct V_62 * V_53 ,
unsigned int V_95 ,
int T_4 * V_127 )
{
const struct V_133 * V_134 = V_53 -> V_134 ;
unsigned int V_15 ;
int V_135 ;
int V_3 ;
if ( F_86 ( V_15 , & V_127 [ 0 ] ) )
return - V_74 ;
if ( ! V_134 || ! F_92 ( V_15 ) )
return - V_55 ;
V_135 = ( V_95 - sizeof( V_136 ) ) / sizeof( V_137 ) ;
for ( V_3 = 0 ; V_3 < V_134 -> V_138 && V_3 < V_135 ; V_3 ++ ) {
int V_17 = F_93 ( & V_134 -> V_139 [ V_3 ] , V_15 ) ;
if ( F_83 ( V_17 , & V_127 [ 1 + V_3 ] ) )
return - V_74 ;
}
return 0 ;
}
static int F_94 ( struct V_32 * V_32 , struct V_1 * V_2 ,
struct V_44 * V_44 )
{
V_2 -> V_35 = true ;
F_36 ( V_32 , V_2 ) ;
F_27 ( & V_32 -> V_38 , V_44 ) ;
F_16 ( & V_32 -> V_36 ) ;
return 0 ;
}
static long F_95 ( struct V_44 * V_44 , unsigned int V_140 ,
void T_4 * V_89 , int V_96 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
struct V_62 * V_53 = V_32 -> V_38 . V_53 ;
struct V_141 abs ;
struct V_142 V_143 ;
int T_4 * V_127 = ( int T_4 * ) V_89 ;
unsigned int V_3 , V_144 , V_145 , V_33 ;
unsigned int V_95 ;
int error ;
switch ( V_140 ) {
case V_146 :
return F_83 ( V_147 , V_127 ) ;
case V_148 :
if ( F_74 ( V_89 , & V_53 -> V_47 , sizeof( struct V_149 ) ) )
return - V_74 ;
return 0 ;
case V_150 :
if ( ! F_96 ( V_151 , V_53 -> V_98 ) )
return - V_152 ;
if ( F_83 ( V_53 -> V_153 [ V_154 ] , V_127 ) )
return - V_74 ;
if ( F_83 ( V_53 -> V_153 [ V_155 ] , V_127 + 1 ) )
return - V_74 ;
return 0 ;
case V_156 :
if ( ! F_96 ( V_151 , V_53 -> V_98 ) )
return - V_152 ;
if ( F_86 ( V_145 , V_127 ) )
return - V_74 ;
if ( F_86 ( V_33 , V_127 + 1 ) )
return - V_74 ;
F_63 ( & V_32 -> V_38 , V_151 , V_154 , V_145 ) ;
F_63 ( & V_32 -> V_38 , V_151 , V_155 , V_33 ) ;
return 0 ;
case V_157 :
return F_97 ( V_53 , ( int ) ( unsigned long ) V_89 , V_44 ) ;
case V_158 :
V_3 = F_96 ( V_118 , V_53 -> V_98 ) ?
V_53 -> V_159 -> V_160 : 0 ;
if ( F_83 ( V_3 , V_127 ) )
return - V_74 ;
return 0 ;
case V_161 :
if ( V_89 )
return F_33 ( V_32 , V_2 ) ;
else
return F_36 ( V_32 , V_2 ) ;
case V_162 :
if ( V_89 )
return - V_55 ;
else
return F_94 ( V_32 , V_2 , V_44 ) ;
case V_163 :
if ( F_81 ( & V_3 , V_89 , sizeof( unsigned int ) ) )
return - V_74 ;
if ( V_3 != V_20 && V_3 != V_164 )
return - V_55 ;
V_2 -> V_19 = V_3 ;
return 0 ;
case V_165 :
return F_80 ( V_53 , V_89 ) ;
case V_166 :
return F_85 ( V_53 , V_89 ) ;
case V_167 :
return F_84 ( V_53 , V_89 ) ;
case V_168 :
return F_88 ( V_53 , V_89 ) ;
}
V_95 = F_98 ( V_140 ) ;
#define F_99 ( T_8 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_99 ( V_140 ) ) {
case F_100 ( 0 ) :
return F_72 ( V_53 -> V_169 , V_170 ,
V_95 , V_89 , V_96 ) ;
case F_101 ( 0 ) :
return F_91 ( V_53 , V_95 , V_127 ) ;
case F_102 ( 0 ) :
return F_89 ( V_2 , V_53 , V_100 , V_53 -> V_171 ,
V_102 , V_95 , V_89 , V_96 ) ;
case F_103 ( 0 ) :
return F_89 ( V_2 , V_53 , V_112 , V_53 -> V_172 ,
V_114 , V_95 , V_89 , V_96 ) ;
case F_104 ( 0 ) :
return F_89 ( V_2 , V_53 , V_115 , V_53 -> V_173 ,
V_117 , V_95 , V_89 , V_96 ) ;
case F_105 ( 0 ) :
return F_89 ( V_2 , V_53 , V_121 , V_53 -> V_174 ,
V_123 , V_95 , V_89 , V_96 ) ;
case F_106 ( 0 ) :
return F_76 ( V_53 -> V_175 , V_95 , V_89 ) ;
case F_107 ( 0 ) :
return F_76 ( V_53 -> V_176 , V_95 , V_89 ) ;
case F_108 ( 0 ) :
return F_76 ( V_53 -> V_177 , V_95 , V_89 ) ;
case F_99 ( V_178 ) :
if ( F_109 ( V_89 , V_95 , & V_143 ) )
return - V_74 ;
error = F_110 ( V_53 , & V_143 , V_44 ) ;
if ( F_83 ( V_143 . V_47 , & ( ( (struct V_142 T_4 * ) V_89 ) -> V_47 ) ) )
return - V_74 ;
return error ;
}
if ( F_111 ( V_140 ) != 'E' )
return - V_55 ;
if ( F_112 ( V_140 ) == V_179 ) {
if ( ( F_113 ( V_140 ) & ~ V_99 ) == F_113 ( F_114 ( 0 , 0 ) ) )
return F_77 ( V_53 ,
F_113 ( V_140 ) & V_99 , V_95 ,
V_89 , V_96 ) ;
if ( ( F_113 ( V_140 ) & ~ V_108 ) == F_113 ( F_115 ( 0 ) ) ) {
if ( ! V_53 -> V_180 )
return - V_55 ;
V_144 = F_113 ( V_140 ) & V_108 ;
abs = V_53 -> V_180 [ V_144 ] ;
if ( F_74 ( V_89 , & abs , F_116 ( T_5 ,
V_95 , sizeof( struct V_141 ) ) ) )
return - V_74 ;
return 0 ;
}
}
if ( F_112 ( V_140 ) == V_181 ) {
if ( ( F_113 ( V_140 ) & ~ V_108 ) == F_113 ( F_117 ( 0 ) ) ) {
if ( ! V_53 -> V_180 )
return - V_55 ;
V_144 = F_113 ( V_140 ) & V_108 ;
if ( F_81 ( & abs , V_89 , F_116 ( T_5 ,
V_95 , sizeof( struct V_141 ) ) ) )
return - V_74 ;
if ( V_95 < sizeof( struct V_141 ) )
abs . V_182 = 0 ;
if ( V_144 == V_183 )
return - V_55 ;
F_65 ( & V_53 -> V_132 ) ;
V_53 -> V_180 [ V_144 ] = abs ;
F_66 ( & V_53 -> V_132 ) ;
return 0 ;
}
}
return - V_55 ;
}
static long F_118 ( struct V_44 * V_44 , unsigned int V_140 ,
void T_4 * V_89 , int V_96 )
{
struct V_1 * V_2 = V_44 -> V_46 ;
struct V_32 * V_32 = V_2 -> V_32 ;
int V_48 ;
V_48 = F_26 ( & V_32 -> V_49 ) ;
if ( V_48 )
return V_48 ;
if ( ! V_32 -> V_50 || V_2 -> V_35 ) {
V_48 = - V_51 ;
goto V_73;
}
V_48 = F_95 ( V_44 , V_140 , V_89 , V_96 ) ;
V_73:
F_28 ( & V_32 -> V_49 ) ;
return V_48 ;
}
static long F_119 ( struct V_44 * V_44 , unsigned int V_140 , unsigned long V_184 )
{
return F_118 ( V_44 , V_140 , ( void T_4 * ) V_184 , 0 ) ;
}
static long F_120 ( struct V_44 * V_44 ,
unsigned int V_140 , unsigned long V_184 )
{
return F_118 ( V_44 , V_140 , F_121 ( V_184 ) , 1 ) ;
}
static void F_122 ( struct V_32 * V_32 )
{
F_48 ( & V_32 -> V_49 ) ;
V_32 -> V_50 = false ;
F_28 ( & V_32 -> V_49 ) ;
}
static void F_123 ( struct V_32 * V_32 )
{
struct V_37 * V_38 = & V_32 -> V_38 ;
F_122 ( V_32 ) ;
F_50 ( V_32 ) ;
F_124 ( & V_32 -> V_68 ) ;
if ( V_32 -> V_59 ) {
F_27 ( V_38 , NULL ) ;
F_49 ( V_38 ) ;
}
}
static int F_125 ( struct V_185 * V_186 , struct V_62 * V_53 ,
const struct V_187 * V_47 )
{
struct V_32 * V_32 ;
int V_188 ;
int V_189 ;
int error ;
V_188 = F_126 ( V_190 , V_191 , true ) ;
if ( V_188 < 0 ) {
error = V_188 ;
F_127 ( L_4 , error ) ;
return error ;
}
V_32 = F_57 ( sizeof( struct V_32 ) , V_69 ) ;
if ( ! V_32 ) {
error = - V_70 ;
goto V_192;
}
F_128 ( & V_32 -> V_58 ) ;
F_58 ( & V_32 -> V_56 ) ;
F_129 ( & V_32 -> V_49 ) ;
F_130 ( & V_32 -> V_36 ) ;
V_32 -> V_50 = true ;
V_189 = V_188 ;
if ( V_189 < V_190 + V_191 )
V_189 -= V_190 ;
F_131 ( & V_32 -> V_53 , L_5 , V_189 ) ;
V_32 -> V_38 . V_53 = F_132 ( V_53 ) ;
V_32 -> V_38 . V_175 = F_133 ( & V_32 -> V_53 ) ;
V_32 -> V_38 . V_186 = V_186 ;
V_32 -> V_38 . V_39 = V_32 ;
V_32 -> V_53 . V_193 = F_134 ( V_194 , V_188 ) ;
V_32 -> V_53 . V_195 = & V_196 ;
V_32 -> V_53 . V_197 = & V_53 -> V_53 ;
V_32 -> V_53 . V_198 = F_29 ;
F_135 ( & V_32 -> V_53 ) ;
error = F_136 ( & V_32 -> V_38 ) ;
if ( error )
goto V_199;
F_137 ( & V_32 -> V_68 , & V_200 ) ;
V_32 -> V_68 . V_201 . V_197 = & V_32 -> V_53 . V_201 ;
error = F_138 ( & V_32 -> V_68 , V_32 -> V_53 . V_193 , 1 ) ;
if ( error )
goto V_202;
error = F_139 ( & V_32 -> V_53 ) ;
if ( error )
goto V_203;
return 0 ;
V_203:
F_123 ( V_32 ) ;
V_202:
F_140 ( & V_32 -> V_38 ) ;
V_199:
F_141 ( & V_32 -> V_53 ) ;
V_192:
F_142 ( V_188 ) ;
return error ;
}
static void F_143 ( struct V_37 * V_38 )
{
struct V_32 * V_32 = V_38 -> V_39 ;
F_144 ( & V_32 -> V_53 ) ;
F_123 ( V_32 ) ;
F_142 ( F_145 ( V_32 -> V_53 . V_193 ) ) ;
F_140 ( V_38 ) ;
F_141 ( & V_32 -> V_53 ) ;
}
static int T_9 F_146 ( void )
{
return F_147 ( & V_204 ) ;
}
static void T_10 F_148 ( void )
{
F_149 ( & V_204 ) ;
}
