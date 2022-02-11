static T_1 F_1 ( unsigned int type )
{
static const T_1 V_1 [ V_2 ] = {
[ V_3 ] = V_2 ,
[ V_4 ] = V_5 ,
[ V_6 ] = V_7 ,
[ V_8 ] = V_9 ,
[ V_10 ] = V_11 ,
[ V_12 ] = V_13 ,
[ V_14 ] = V_15 ,
[ V_16 ] = V_17 ,
[ V_18 ] = V_19 ,
} ;
return ( type < V_2 ) ? V_1 [ type ] : 0 ;
}
static bool F_2 ( struct V_20 * V_21 ,
unsigned int type ,
unsigned int V_22 )
{
unsigned long * V_23 ;
T_1 V_24 ;
if ( type == V_3 || type >= V_2 )
return false ;
V_23 = V_21 -> V_25 [ 0 ] ;
if ( V_23 && ! F_3 ( type , V_23 ) )
return true ;
V_24 = F_1 ( type ) ;
if ( ! V_24 || V_22 >= V_24 )
return false ;
V_23 = V_21 -> V_25 [ type ] ;
return V_23 && ! F_3 ( V_22 , V_23 ) ;
}
static void F_4 ( struct V_20 * V_21 , unsigned int type )
{
unsigned int V_26 , V_27 , V_28 ;
unsigned int V_23 = V_21 -> V_29 - 1 ;
bool V_30 ;
struct V_31 * V_32 ;
F_5 ( type == V_3 ) ;
V_27 = V_21 -> V_33 ;
V_21 -> V_34 = V_21 -> V_33 ;
V_28 = 1 ;
for ( V_26 = V_21 -> V_33 ; V_26 != V_21 -> V_27 ; V_26 = ( V_26 + 1 ) & V_23 ) {
V_32 = & V_21 -> V_35 [ V_26 ] ;
V_30 = V_32 -> type == V_3 && V_32 -> V_22 == V_36 ;
if ( V_32 -> type == type ) {
continue;
} else if ( V_30 && ! V_28 ) {
continue;
} else if ( V_27 != V_26 ) {
V_21 -> V_35 [ V_27 ] . time = V_32 -> time ;
V_21 -> V_35 [ V_27 ] . type = V_32 -> type ;
V_21 -> V_35 [ V_27 ] . V_22 = V_32 -> V_22 ;
V_21 -> V_35 [ V_27 ] . V_37 = V_32 -> V_37 ;
}
V_28 ++ ;
V_27 = ( V_27 + 1 ) & V_23 ;
if ( V_30 ) {
V_28 = 0 ;
V_21 -> V_34 = V_27 ;
}
}
V_21 -> V_27 = V_27 ;
}
static void F_6 ( struct V_20 * V_21 )
{
struct V_31 V_32 ;
T_2 time ;
time = V_21 -> V_38 == V_39 ?
F_7 () :
V_21 -> V_38 == V_40 ?
F_8 () :
F_9 () ;
V_32 . time = F_10 ( time ) ;
V_32 . type = V_3 ;
V_32 . V_22 = V_41 ;
V_32 . V_37 = 0 ;
V_21 -> V_35 [ V_21 -> V_27 ++ ] = V_32 ;
V_21 -> V_27 &= V_21 -> V_29 - 1 ;
if ( F_11 ( V_21 -> V_27 == V_21 -> V_33 ) ) {
V_21 -> V_33 = ( V_21 -> V_27 - 1 ) & ( V_21 -> V_29 - 1 ) ;
V_21 -> V_34 = V_21 -> V_33 ;
}
}
static void F_12 ( struct V_20 * V_21 )
{
unsigned long V_42 ;
F_13 ( & V_21 -> V_43 , V_42 ) ;
F_6 ( V_21 ) ;
F_14 ( & V_21 -> V_43 , V_42 ) ;
}
static int F_15 ( struct V_20 * V_21 , unsigned int V_44 )
{
unsigned long V_42 ;
unsigned int V_38 ;
switch ( V_44 ) {
case V_45 :
V_38 = V_39 ;
break;
case V_46 :
V_38 = V_40 ;
break;
case V_47 :
V_38 = V_48 ;
break;
default:
return - V_49 ;
}
if ( V_21 -> V_38 != V_38 ) {
V_21 -> V_38 = V_38 ;
F_13 ( & V_21 -> V_43 , V_42 ) ;
if ( V_21 -> V_27 != V_21 -> V_33 ) {
V_21 -> V_34 = V_21 -> V_27 = V_21 -> V_33 ;
F_6 ( V_21 ) ;
}
F_14 ( & V_21 -> V_43 , V_42 ) ;
}
return 0 ;
}
static void F_16 ( struct V_20 * V_21 ,
const struct V_31 * V_50 )
{
V_21 -> V_35 [ V_21 -> V_27 ++ ] = * V_50 ;
V_21 -> V_27 &= V_21 -> V_29 - 1 ;
if ( F_11 ( V_21 -> V_27 == V_21 -> V_33 ) ) {
V_21 -> V_33 = ( V_21 -> V_27 - 2 ) & ( V_21 -> V_29 - 1 ) ;
V_21 -> V_35 [ V_21 -> V_33 ] . time = V_50 -> time ;
V_21 -> V_35 [ V_21 -> V_33 ] . type = V_3 ;
V_21 -> V_35 [ V_21 -> V_33 ] . V_22 = V_41 ;
V_21 -> V_35 [ V_21 -> V_33 ] . V_37 = 0 ;
V_21 -> V_34 = V_21 -> V_33 ;
}
if ( V_50 -> type == V_3 && V_50 -> V_22 == V_36 ) {
V_21 -> V_34 = V_21 -> V_27 ;
F_17 ( & V_21 -> V_51 , V_52 , V_53 ) ;
}
}
static void F_18 ( struct V_20 * V_21 ,
const struct V_54 * V_55 , unsigned int V_56 ,
T_2 * V_57 )
{
struct V_58 * V_58 = V_21 -> V_58 ;
const struct V_54 * V_59 ;
struct V_31 V_50 ;
bool V_60 = false ;
if ( V_21 -> V_61 )
return;
V_50 . time = F_10 ( V_57 [ V_21 -> V_38 ] ) ;
F_19 ( & V_21 -> V_43 ) ;
for ( V_59 = V_55 ; V_59 != V_55 + V_56 ; V_59 ++ ) {
if ( F_2 ( V_21 , V_59 -> type , V_59 -> V_22 ) )
continue;
if ( V_59 -> type == V_3 && V_59 -> V_22 == V_36 ) {
if ( V_21 -> V_34 == V_21 -> V_27 )
continue;
V_60 = true ;
}
V_50 . type = V_59 -> type ;
V_50 . V_22 = V_59 -> V_22 ;
V_50 . V_37 = V_59 -> V_37 ;
F_16 ( V_21 , & V_50 ) ;
}
F_20 ( & V_21 -> V_43 ) ;
if ( V_60 )
F_21 ( & V_58 -> V_62 ) ;
}
static void F_22 ( struct V_63 * V_64 ,
const struct V_54 * V_55 , unsigned int V_56 )
{
struct V_58 * V_58 = V_64 -> V_65 ;
struct V_20 * V_21 ;
T_2 V_57 [ V_66 ] ;
V_57 [ V_40 ] = F_8 () ;
V_57 [ V_39 ] = F_23 ( V_57 [ V_40 ] ) ;
V_57 [ V_48 ] = F_24 ( V_57 [ V_40 ] ,
V_67 ) ;
F_25 () ;
V_21 = F_26 ( V_58 -> V_68 ) ;
if ( V_21 )
F_18 ( V_21 , V_55 , V_56 , V_57 ) ;
else
F_27 (client, &evdev->client_list, node)
F_18 ( V_21 , V_55 , V_56 , V_57 ) ;
F_28 () ;
}
static void F_29 ( struct V_63 * V_64 ,
unsigned int type , unsigned int V_22 , int V_37 )
{
struct V_54 V_55 [] = { { type , V_22 , V_37 } } ;
F_22 ( V_64 , V_55 , 1 ) ;
}
static int F_30 ( int V_69 , struct V_70 * V_70 , int V_71 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
return F_31 ( V_69 , V_70 , V_71 , & V_21 -> V_51 ) ;
}
static int F_32 ( struct V_70 * V_70 , T_3 V_73 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
struct V_58 * V_58 = V_21 -> V_58 ;
F_33 ( & V_58 -> V_74 ) ;
if ( V_58 -> V_75 && ! V_21 -> V_61 )
F_34 ( & V_58 -> V_64 , V_70 ) ;
F_35 ( & V_58 -> V_74 ) ;
return 0 ;
}
static void F_36 ( struct V_76 * V_77 )
{
struct V_58 * V_58 = F_37 ( V_77 , struct V_58 , V_77 ) ;
F_38 ( V_58 -> V_64 . V_77 ) ;
F_39 ( V_58 ) ;
}
static int F_40 ( struct V_58 * V_58 , struct V_20 * V_21 )
{
int error ;
if ( V_58 -> V_68 )
return - V_78 ;
error = F_41 ( & V_58 -> V_64 ) ;
if ( error )
return error ;
F_42 ( V_58 -> V_68 , V_21 ) ;
return 0 ;
}
static int F_43 ( struct V_58 * V_58 , struct V_20 * V_21 )
{
struct V_20 * V_68 = F_44 ( V_58 -> V_68 ,
F_45 ( & V_58 -> V_74 ) ) ;
if ( V_68 != V_21 )
return - V_49 ;
F_42 ( V_58 -> V_68 , NULL ) ;
F_46 () ;
F_47 ( & V_58 -> V_64 ) ;
return 0 ;
}
static void F_48 ( struct V_58 * V_58 ,
struct V_20 * V_21 )
{
F_19 ( & V_58 -> V_79 ) ;
F_49 ( & V_21 -> V_80 , & V_58 -> V_81 ) ;
F_20 ( & V_58 -> V_79 ) ;
}
static void F_50 ( struct V_58 * V_58 ,
struct V_20 * V_21 )
{
F_19 ( & V_58 -> V_79 ) ;
F_51 ( & V_21 -> V_80 ) ;
F_20 ( & V_58 -> V_79 ) ;
F_46 () ;
}
static int F_52 ( struct V_58 * V_58 )
{
int V_82 ;
V_82 = F_53 ( & V_58 -> V_74 ) ;
if ( V_82 )
return V_82 ;
if ( ! V_58 -> V_75 )
V_82 = - V_83 ;
else if ( ! V_58 -> V_84 ++ ) {
V_82 = F_54 ( & V_58 -> V_64 ) ;
if ( V_82 )
V_58 -> V_84 -- ;
}
F_35 ( & V_58 -> V_74 ) ;
return V_82 ;
}
static void F_55 ( struct V_58 * V_58 )
{
F_33 ( & V_58 -> V_74 ) ;
if ( V_58 -> V_75 && ! -- V_58 -> V_84 )
F_56 ( & V_58 -> V_64 ) ;
F_35 ( & V_58 -> V_74 ) ;
}
static void F_57 ( struct V_58 * V_58 )
{
struct V_20 * V_21 ;
F_19 ( & V_58 -> V_79 ) ;
F_58 (client, &evdev->client_list, node)
F_17 ( & V_21 -> V_51 , V_52 , V_85 ) ;
F_20 ( & V_58 -> V_79 ) ;
F_21 ( & V_58 -> V_62 ) ;
}
static int F_59 ( struct V_86 * V_86 , struct V_70 * V_70 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
struct V_58 * V_58 = V_21 -> V_58 ;
unsigned int V_26 ;
F_33 ( & V_58 -> V_74 ) ;
F_43 ( V_58 , V_21 ) ;
F_35 ( & V_58 -> V_74 ) ;
F_50 ( V_58 , V_21 ) ;
for ( V_26 = 0 ; V_26 < V_2 ; ++ V_26 )
F_39 ( V_21 -> V_25 [ V_26 ] ) ;
F_60 ( V_21 ) ;
F_55 ( V_58 ) ;
return 0 ;
}
static unsigned int F_61 ( struct V_87 * V_77 )
{
unsigned int V_88 =
F_62 ( V_77 -> V_89 * V_90 ,
V_91 ) ;
return F_63 ( V_88 ) ;
}
static int F_64 ( struct V_86 * V_86 , struct V_70 * V_70 )
{
struct V_58 * V_58 = F_37 ( V_86 -> V_92 , struct V_58 , V_93 ) ;
unsigned int V_29 = F_61 ( V_58 -> V_64 . V_77 ) ;
unsigned int V_94 = sizeof( struct V_20 ) +
V_29 * sizeof( struct V_31 ) ;
struct V_20 * V_21 ;
int error ;
V_21 = F_65 ( V_94 , V_95 | V_96 ) ;
if ( ! V_21 )
V_21 = F_66 ( V_94 ) ;
if ( ! V_21 )
return - V_97 ;
V_21 -> V_29 = V_29 ;
F_67 ( & V_21 -> V_43 ) ;
V_21 -> V_58 = V_58 ;
F_48 ( V_58 , V_21 ) ;
error = F_52 ( V_58 ) ;
if ( error )
goto V_98;
V_70 -> V_72 = V_21 ;
F_68 ( V_86 , V_70 ) ;
return 0 ;
V_98:
F_50 ( V_58 , V_21 ) ;
F_60 ( V_21 ) ;
return error ;
}
static T_4 F_69 ( struct V_70 * V_70 , const char T_5 * V_35 ,
T_1 V_56 , T_6 * V_99 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
struct V_58 * V_58 = V_21 -> V_58 ;
struct V_31 V_50 ;
int V_82 = 0 ;
if ( V_56 != 0 && V_56 < F_70 () )
return - V_49 ;
V_82 = F_53 ( & V_58 -> V_74 ) ;
if ( V_82 )
return V_82 ;
if ( ! V_58 -> V_75 || V_21 -> V_61 ) {
V_82 = - V_83 ;
goto V_100;
}
while ( V_82 + F_70 () <= V_56 ) {
if ( F_71 ( V_35 + V_82 , & V_50 ) ) {
V_82 = - V_101 ;
goto V_100;
}
V_82 += F_70 () ;
F_72 ( & V_58 -> V_64 ,
V_50 . type , V_50 . V_22 , V_50 . V_37 ) ;
}
V_100:
F_35 ( & V_58 -> V_74 ) ;
return V_82 ;
}
static int F_73 ( struct V_20 * V_21 ,
struct V_31 * V_50 )
{
int V_102 ;
F_74 ( & V_21 -> V_43 ) ;
V_102 = V_21 -> V_34 != V_21 -> V_33 ;
if ( V_102 ) {
* V_50 = V_21 -> V_35 [ V_21 -> V_33 ++ ] ;
V_21 -> V_33 &= V_21 -> V_29 - 1 ;
}
F_75 ( & V_21 -> V_43 ) ;
return V_102 ;
}
static T_4 F_76 ( struct V_70 * V_70 , char T_5 * V_35 ,
T_1 V_56 , T_6 * V_99 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
struct V_58 * V_58 = V_21 -> V_58 ;
struct V_31 V_50 ;
T_1 V_103 = 0 ;
int error ;
if ( V_56 != 0 && V_56 < F_70 () )
return - V_49 ;
for (; ; ) {
if ( ! V_58 -> V_75 || V_21 -> V_61 )
return - V_83 ;
if ( V_21 -> V_34 == V_21 -> V_33 &&
( V_70 -> V_104 & V_105 ) )
return - V_106 ;
if ( V_56 == 0 )
break;
while ( V_103 + F_70 () <= V_56 &&
F_73 ( V_21 , & V_50 ) ) {
if ( F_77 ( V_35 + V_103 , & V_50 ) )
return - V_101 ;
V_103 += F_70 () ;
}
if ( V_103 )
break;
if ( ! ( V_70 -> V_104 & V_105 ) ) {
error = F_78 ( V_58 -> V_62 ,
V_21 -> V_34 != V_21 -> V_33 ||
! V_58 -> V_75 || V_21 -> V_61 ) ;
if ( error )
return error ;
}
}
return V_103 ;
}
static unsigned int F_79 ( struct V_70 * V_70 , T_7 * V_62 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
struct V_58 * V_58 = V_21 -> V_58 ;
unsigned int V_23 ;
F_80 ( V_70 , & V_58 -> V_62 , V_62 ) ;
if ( V_58 -> V_75 && ! V_21 -> V_61 )
V_23 = V_107 | V_108 ;
else
V_23 = V_109 | V_110 ;
if ( V_21 -> V_34 != V_21 -> V_33 )
V_23 |= V_111 | V_112 ;
return V_23 ;
}
static int F_81 ( unsigned long * V_113 , unsigned int V_114 ,
unsigned int V_115 , void T_5 * V_116 , int V_117 )
{
int V_118 , V_26 ;
if ( V_117 ) {
V_118 = F_82 ( V_114 ) * sizeof( V_119 ) ;
if ( V_118 > V_115 )
V_118 = V_115 ;
for ( V_26 = 0 ; V_26 < V_118 / sizeof( V_119 ) ; V_26 ++ )
if ( F_83 ( ( V_119 T_5 * ) V_116 + V_26 ,
( V_119 * ) V_113 +
V_26 + 1 - ( ( V_26 % 2 ) << 1 ) ,
sizeof( V_119 ) ) )
return - V_101 ;
} else {
V_118 = F_84 ( V_114 ) * sizeof( long ) ;
if ( V_118 > V_115 )
V_118 = V_115 ;
if ( F_83 ( V_116 , V_113 , V_118 ) )
return - V_101 ;
}
return V_118 ;
}
static int F_85 ( unsigned long * V_113 , unsigned int V_114 ,
unsigned int V_115 , const void T_5 * V_116 , int V_117 )
{
int V_118 , V_26 ;
if ( V_117 ) {
if ( V_115 % sizeof( V_119 ) )
return - V_49 ;
V_118 = F_82 ( V_114 ) * sizeof( V_119 ) ;
if ( V_118 > V_115 )
V_118 = V_115 ;
for ( V_26 = 0 ; V_26 < V_118 / sizeof( V_119 ) ; V_26 ++ )
if ( F_86 ( ( V_119 * ) V_113 +
V_26 + 1 - ( ( V_26 % 2 ) << 1 ) ,
( V_119 T_5 * ) V_116 + V_26 ,
sizeof( V_119 ) ) )
return - V_101 ;
if ( V_26 % 2 )
* ( ( V_119 * ) V_113 + V_26 - 1 ) = 0 ;
} else {
if ( V_115 % sizeof( long ) )
return - V_49 ;
V_118 = F_84 ( V_114 ) * sizeof( long ) ;
if ( V_118 > V_115 )
V_118 = V_115 ;
if ( F_86 ( V_113 , V_116 , V_118 ) )
return - V_101 ;
}
return V_118 ;
}
static int F_81 ( unsigned long * V_113 , unsigned int V_114 ,
unsigned int V_115 , void T_5 * V_116 , int V_117 )
{
int V_118 = V_117 ?
F_82 ( V_114 ) * sizeof( V_119 ) :
F_84 ( V_114 ) * sizeof( long ) ;
if ( V_118 > V_115 )
V_118 = V_115 ;
return F_83 ( V_116 , V_113 , V_118 ) ? - V_101 : V_118 ;
}
static int F_85 ( unsigned long * V_113 , unsigned int V_114 ,
unsigned int V_115 , const void T_5 * V_116 , int V_117 )
{
T_1 V_120 = V_117 ? sizeof( V_119 ) : sizeof( long ) ;
int V_118 ;
if ( V_115 % V_120 )
return - V_49 ;
V_118 = V_117 ? F_82 ( V_114 ) : F_84 ( V_114 ) ;
V_118 *= V_120 ;
if ( V_118 > V_115 )
V_118 = V_115 ;
return F_86 ( V_113 , V_116 , V_118 ) ? - V_101 : V_118 ;
}
static int F_81 ( unsigned long * V_113 , unsigned int V_114 ,
unsigned int V_115 , void T_5 * V_116 , int V_117 )
{
int V_118 = F_84 ( V_114 ) * sizeof( long ) ;
if ( V_118 > V_115 )
V_118 = V_115 ;
return F_83 ( V_116 , V_113 , V_118 ) ? - V_101 : V_118 ;
}
static int F_85 ( unsigned long * V_113 , unsigned int V_114 ,
unsigned int V_115 , const void T_5 * V_116 , int V_117 )
{
int V_118 ;
if ( V_115 % sizeof( long ) )
return - V_49 ;
V_118 = F_84 ( V_114 ) * sizeof( long ) ;
if ( V_118 > V_115 )
V_118 = V_115 ;
return F_86 ( V_113 , V_116 , V_118 ) ? - V_101 : V_118 ;
}
static int F_87 ( const char * V_121 , unsigned int V_115 , void T_5 * V_116 )
{
int V_118 ;
if ( ! V_121 )
return - V_122 ;
V_118 = strlen ( V_121 ) + 1 ;
if ( V_118 > V_115 )
V_118 = V_115 ;
return F_83 ( V_116 , V_121 , V_118 ) ? - V_101 : V_118 ;
}
static int F_88 ( struct V_87 * V_77 ,
unsigned int type , unsigned int V_94 ,
void T_5 * V_116 , int V_123 )
{
unsigned long * V_113 ;
int V_118 ;
switch ( type ) {
case 0 : V_113 = V_77 -> V_124 ; V_118 = V_125 ; break;
case V_4 : V_113 = V_77 -> V_126 ; V_118 = V_127 ; break;
case V_6 : V_113 = V_77 -> V_128 ; V_118 = V_129 ; break;
case V_8 : V_113 = V_77 -> V_130 ; V_118 = V_131 ; break;
case V_10 : V_113 = V_77 -> V_132 ; V_118 = V_133 ; break;
case V_14 : V_113 = V_77 -> V_134 ; V_118 = V_135 ; break;
case V_16 : V_113 = V_77 -> V_136 ; V_118 = V_137 ; break;
case V_18 : V_113 = V_77 -> V_138 ; V_118 = V_139 ; break;
case V_12 : V_113 = V_77 -> V_140 ; V_118 = V_141 ; break;
default: return - V_49 ;
}
return F_81 ( V_113 , V_118 , V_94 , V_116 , V_123 ) ;
}
static int F_89 ( struct V_87 * V_77 , void T_5 * V_116 )
{
struct V_142 V_143 = {
. V_118 = sizeof( unsigned int ) ,
. V_42 = 0 ,
} ;
int T_5 * V_144 = ( int T_5 * ) V_116 ;
int error ;
if ( F_86 ( V_143 . V_145 , V_116 , sizeof( unsigned int ) ) )
return - V_101 ;
error = F_90 ( V_77 , & V_143 ) ;
if ( error )
return error ;
if ( F_91 ( V_143 . V_146 , V_144 + 1 ) )
return - V_101 ;
return 0 ;
}
static int F_92 ( struct V_87 * V_77 , void T_5 * V_116 )
{
struct V_142 V_143 ;
int error ;
if ( F_86 ( & V_143 , V_116 , sizeof( V_143 ) ) )
return - V_101 ;
error = F_90 ( V_77 , & V_143 ) ;
if ( error )
return error ;
if ( F_83 ( V_116 , & V_143 , sizeof( V_143 ) ) )
return - V_101 ;
return 0 ;
}
static int F_93 ( struct V_87 * V_77 , void T_5 * V_116 )
{
struct V_142 V_143 = {
. V_118 = sizeof( unsigned int ) ,
. V_42 = 0 ,
} ;
int T_5 * V_144 = ( int T_5 * ) V_116 ;
if ( F_86 ( V_143 . V_145 , V_116 , sizeof( unsigned int ) ) )
return - V_101 ;
if ( F_94 ( V_143 . V_146 , V_144 + 1 ) )
return - V_101 ;
return F_95 ( V_77 , & V_143 ) ;
}
static int F_96 ( struct V_87 * V_77 , void T_5 * V_116 )
{
struct V_142 V_143 ;
if ( F_86 ( & V_143 , V_116 , sizeof( V_143 ) ) )
return - V_101 ;
if ( V_143 . V_118 > sizeof( V_143 . V_145 ) )
return - V_49 ;
return F_95 ( V_77 , & V_143 ) ;
}
static int F_97 ( struct V_20 * V_21 ,
struct V_87 * V_77 , unsigned int type ,
unsigned long * V_113 , unsigned int V_114 ,
unsigned int V_115 , void T_5 * V_116 ,
int V_117 )
{
int V_147 ;
unsigned long * V_148 ;
T_1 V_118 ;
V_118 = F_84 ( V_114 ) * sizeof( unsigned long ) ;
V_148 = F_98 ( V_118 , V_95 ) ;
if ( ! V_148 )
return - V_97 ;
F_74 ( & V_77 -> V_149 ) ;
F_19 ( & V_21 -> V_43 ) ;
memcpy ( V_148 , V_113 , V_118 ) ;
F_20 ( & V_77 -> V_149 ) ;
F_4 ( V_21 , type ) ;
F_75 ( & V_21 -> V_43 ) ;
V_147 = F_81 ( V_148 , V_114 , V_115 , V_116 , V_117 ) ;
if ( V_147 < 0 )
F_12 ( V_21 ) ;
F_39 ( V_148 ) ;
return V_147 ;
}
static int F_99 ( struct V_87 * V_77 ,
unsigned int V_94 ,
int T_5 * V_144 )
{
const struct V_150 * V_151 = V_77 -> V_151 ;
unsigned int V_22 ;
int V_152 ;
int V_26 ;
if ( F_94 ( V_22 , & V_144 [ 0 ] ) )
return - V_101 ;
if ( ! V_151 || ! F_100 ( V_22 ) )
return - V_49 ;
V_152 = ( V_94 - sizeof( V_153 ) ) / sizeof( V_154 ) ;
for ( V_26 = 0 ; V_26 < V_151 -> V_155 && V_26 < V_152 ; V_26 ++ ) {
int V_37 = F_101 ( & V_151 -> V_156 [ V_26 ] , V_22 ) ;
if ( F_91 ( V_37 , & V_144 [ 1 + V_26 ] ) )
return - V_101 ;
}
return 0 ;
}
static int F_102 ( struct V_58 * V_58 , struct V_20 * V_21 ,
struct V_70 * V_70 )
{
V_21 -> V_61 = true ;
F_43 ( V_58 , V_21 ) ;
F_34 ( & V_58 -> V_64 , V_70 ) ;
F_21 ( & V_58 -> V_62 ) ;
return 0 ;
}
static int F_103 ( struct V_20 * V_21 ,
unsigned int type ,
const void T_5 * V_157 ,
T_8 V_158 ,
int V_117 )
{
unsigned long V_42 , * V_23 , * V_159 ;
T_1 V_24 ;
int error ;
V_24 = F_1 ( type ) ;
if ( ! V_24 )
return 0 ;
V_23 = F_104 ( sizeof( unsigned long ) , F_84 ( V_24 ) , V_95 ) ;
if ( ! V_23 )
return - V_97 ;
error = F_85 ( V_23 , V_24 - 1 , V_158 , V_157 , V_117 ) ;
if ( error < 0 ) {
F_39 ( V_23 ) ;
return error ;
}
F_13 ( & V_21 -> V_43 , V_42 ) ;
V_159 = V_21 -> V_25 [ type ] ;
V_21 -> V_25 [ type ] = V_23 ;
F_14 ( & V_21 -> V_43 , V_42 ) ;
F_39 ( V_159 ) ;
return 0 ;
}
static int F_105 ( struct V_20 * V_21 ,
unsigned int type ,
void T_5 * V_157 ,
T_8 V_158 ,
int V_117 )
{
unsigned long * V_23 ;
T_1 V_24 , V_94 , V_160 ;
int V_26 ;
int error ;
V_24 = F_1 ( type ) ;
V_94 = sizeof( unsigned long ) * F_84 ( V_24 ) ;
V_160 = F_106 ( T_1 , V_158 , V_94 ) ;
if ( V_24 > 0 ) {
V_23 = V_21 -> V_25 [ type ] ;
if ( V_23 ) {
error = F_81 ( V_23 , V_24 - 1 ,
V_160 , V_157 , V_117 ) ;
if ( error < 0 )
return error ;
} else {
for ( V_26 = 0 ; V_26 < V_160 ; V_26 ++ )
if ( F_91 ( 0xffU , ( V_161 T_5 * ) V_157 + V_26 ) )
return - V_101 ;
}
}
if ( V_160 < V_158 )
if ( F_107 ( V_157 + V_160 , V_158 - V_160 ) )
return - V_101 ;
return 0 ;
}
static long F_108 ( struct V_70 * V_70 , unsigned int V_162 ,
void T_5 * V_116 , int V_123 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
struct V_58 * V_58 = V_21 -> V_58 ;
struct V_87 * V_77 = V_58 -> V_64 . V_77 ;
struct V_163 abs ;
struct V_164 V_23 ;
struct V_165 V_166 ;
int T_5 * V_144 = ( int T_5 * ) V_116 ;
unsigned int V_26 , V_167 , V_168 , V_59 ;
unsigned int V_94 ;
int error ;
switch ( V_162 ) {
case V_169 :
return F_91 ( V_170 , V_144 ) ;
case V_171 :
if ( F_83 ( V_116 , & V_77 -> V_73 , sizeof( struct V_172 ) ) )
return - V_101 ;
return 0 ;
case V_173 :
if ( ! F_3 ( V_174 , V_77 -> V_124 ) )
return - V_175 ;
if ( F_91 ( V_77 -> V_176 [ V_177 ] , V_144 ) )
return - V_101 ;
if ( F_91 ( V_77 -> V_176 [ V_178 ] , V_144 + 1 ) )
return - V_101 ;
return 0 ;
case V_179 :
if ( ! F_3 ( V_174 , V_77 -> V_124 ) )
return - V_175 ;
if ( F_94 ( V_168 , V_144 ) )
return - V_101 ;
if ( F_94 ( V_59 , V_144 + 1 ) )
return - V_101 ;
F_72 ( & V_58 -> V_64 , V_174 , V_177 , V_168 ) ;
F_72 ( & V_58 -> V_64 , V_174 , V_178 , V_59 ) ;
return 0 ;
case V_180 :
return F_109 ( V_77 , ( int ) ( unsigned long ) V_116 , V_70 ) ;
case V_181 :
V_26 = F_3 ( V_18 , V_77 -> V_124 ) ?
V_77 -> V_182 -> V_183 : 0 ;
if ( F_91 ( V_26 , V_144 ) )
return - V_101 ;
return 0 ;
case V_184 :
if ( V_116 )
return F_40 ( V_58 , V_21 ) ;
else
return F_43 ( V_58 , V_21 ) ;
case V_185 :
if ( V_116 )
return - V_49 ;
else
return F_102 ( V_58 , V_21 , V_70 ) ;
case V_186 : {
void T_5 * V_187 ;
if ( F_86 ( & V_23 , V_116 , sizeof( V_23 ) ) )
return - V_101 ;
V_187 = ( void T_5 * ) ( unsigned long ) V_23 . V_187 ;
return F_105 ( V_21 ,
V_23 . type , V_187 , V_23 . V_158 ,
V_123 ) ;
}
case V_188 : {
const void T_5 * V_187 ;
if ( F_86 ( & V_23 , V_116 , sizeof( V_23 ) ) )
return - V_101 ;
V_187 = ( const void T_5 * ) ( unsigned long ) V_23 . V_187 ;
return F_103 ( V_21 ,
V_23 . type , V_187 , V_23 . V_158 ,
V_123 ) ;
}
case V_189 :
if ( F_86 ( & V_26 , V_116 , sizeof( unsigned int ) ) )
return - V_101 ;
return F_15 ( V_21 , V_26 ) ;
case V_190 :
return F_89 ( V_77 , V_116 ) ;
case V_191 :
return F_93 ( V_77 , V_116 ) ;
case V_192 :
return F_92 ( V_77 , V_116 ) ;
case V_193 :
return F_96 ( V_77 , V_116 ) ;
}
V_94 = F_110 ( V_162 ) ;
#define F_111 ( T_9 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_111 ( V_162 ) ) {
case F_112 ( 0 ) :
return F_81 ( V_77 -> V_194 , V_195 ,
V_94 , V_116 , V_123 ) ;
case F_113 ( 0 ) :
return F_99 ( V_77 , V_94 , V_144 ) ;
case F_114 ( 0 ) :
return F_97 ( V_21 , V_77 , V_4 , V_77 -> V_196 ,
V_127 , V_94 , V_116 , V_123 ) ;
case F_115 ( 0 ) :
return F_97 ( V_21 , V_77 , V_14 , V_77 -> V_197 ,
V_135 , V_94 , V_116 , V_123 ) ;
case F_116 ( 0 ) :
return F_97 ( V_21 , V_77 , V_16 , V_77 -> V_198 ,
V_137 , V_94 , V_116 , V_123 ) ;
case F_117 ( 0 ) :
return F_97 ( V_21 , V_77 , V_12 , V_77 -> V_199 ,
V_141 , V_94 , V_116 , V_123 ) ;
case F_118 ( 0 ) :
return F_87 ( V_77 -> V_200 , V_94 , V_116 ) ;
case F_119 ( 0 ) :
return F_87 ( V_77 -> V_201 , V_94 , V_116 ) ;
case F_120 ( 0 ) :
return F_87 ( V_77 -> V_202 , V_94 , V_116 ) ;
case F_111 ( V_203 ) :
if ( F_121 ( V_116 , V_94 , & V_166 ) )
return - V_101 ;
error = F_122 ( V_77 , & V_166 , V_70 ) ;
if ( error )
return error ;
if ( F_91 ( V_166 . V_73 , & ( ( (struct V_165 T_5 * ) V_116 ) -> V_73 ) ) )
return - V_101 ;
return 0 ;
}
if ( F_123 ( V_162 ) != 'E' )
return - V_49 ;
if ( F_124 ( V_162 ) == V_204 ) {
if ( ( F_125 ( V_162 ) & ~ V_125 ) == F_125 ( F_126 ( 0 , 0 ) ) )
return F_88 ( V_77 ,
F_125 ( V_162 ) & V_125 , V_94 ,
V_116 , V_123 ) ;
if ( ( F_125 ( V_162 ) & ~ V_131 ) == F_125 ( F_127 ( 0 ) ) ) {
if ( ! V_77 -> V_205 )
return - V_49 ;
V_167 = F_125 ( V_162 ) & V_131 ;
abs = V_77 -> V_205 [ V_167 ] ;
if ( F_83 ( V_116 , & abs , F_106 ( T_1 ,
V_94 , sizeof( struct V_163 ) ) ) )
return - V_101 ;
return 0 ;
}
}
if ( F_124 ( V_162 ) == V_206 ) {
if ( ( F_125 ( V_162 ) & ~ V_131 ) == F_125 ( F_128 ( 0 ) ) ) {
if ( ! V_77 -> V_205 )
return - V_49 ;
V_167 = F_125 ( V_162 ) & V_131 ;
if ( F_86 ( & abs , V_116 , F_106 ( T_1 ,
V_94 , sizeof( struct V_163 ) ) ) )
return - V_101 ;
if ( V_94 < sizeof( struct V_163 ) )
abs . V_207 = 0 ;
if ( V_167 == V_208 )
return - V_49 ;
F_74 ( & V_77 -> V_149 ) ;
V_77 -> V_205 [ V_167 ] = abs ;
F_75 ( & V_77 -> V_149 ) ;
return 0 ;
}
}
return - V_49 ;
}
static long F_129 ( struct V_70 * V_70 , unsigned int V_162 ,
void T_5 * V_116 , int V_123 )
{
struct V_20 * V_21 = V_70 -> V_72 ;
struct V_58 * V_58 = V_21 -> V_58 ;
int V_82 ;
V_82 = F_53 ( & V_58 -> V_74 ) ;
if ( V_82 )
return V_82 ;
if ( ! V_58 -> V_75 || V_21 -> V_61 ) {
V_82 = - V_83 ;
goto V_100;
}
V_82 = F_108 ( V_70 , V_162 , V_116 , V_123 ) ;
V_100:
F_35 ( & V_58 -> V_74 ) ;
return V_82 ;
}
static long F_130 ( struct V_70 * V_70 , unsigned int V_162 , unsigned long V_209 )
{
return F_129 ( V_70 , V_162 , ( void T_5 * ) V_209 , 0 ) ;
}
static long F_131 ( struct V_70 * V_70 ,
unsigned int V_162 , unsigned long V_209 )
{
return F_129 ( V_70 , V_162 , F_132 ( V_209 ) , 1 ) ;
}
static void F_133 ( struct V_58 * V_58 )
{
F_33 ( & V_58 -> V_74 ) ;
V_58 -> V_75 = false ;
F_35 ( & V_58 -> V_74 ) ;
}
static void F_134 ( struct V_58 * V_58 )
{
struct V_63 * V_64 = & V_58 -> V_64 ;
F_133 ( V_58 ) ;
F_57 ( V_58 ) ;
if ( V_58 -> V_84 ) {
F_34 ( V_64 , NULL ) ;
F_56 ( V_64 ) ;
}
}
static int F_135 ( struct V_210 * V_211 , struct V_87 * V_77 ,
const struct V_212 * V_73 )
{
struct V_58 * V_58 ;
int V_213 ;
int V_214 ;
int error ;
V_213 = F_136 ( V_215 , V_216 , true ) ;
if ( V_213 < 0 ) {
error = V_213 ;
F_137 ( L_1 , error ) ;
return error ;
}
V_58 = F_65 ( sizeof( struct V_58 ) , V_95 ) ;
if ( ! V_58 ) {
error = - V_97 ;
goto V_217;
}
F_138 ( & V_58 -> V_81 ) ;
F_67 ( & V_58 -> V_79 ) ;
F_139 ( & V_58 -> V_74 ) ;
F_140 ( & V_58 -> V_62 ) ;
V_58 -> V_75 = true ;
V_214 = V_213 ;
if ( V_214 < V_215 + V_216 )
V_214 -= V_215 ;
F_141 ( & V_58 -> V_77 , L_2 , V_214 ) ;
V_58 -> V_64 . V_77 = F_142 ( V_77 ) ;
V_58 -> V_64 . V_200 = F_143 ( & V_58 -> V_77 ) ;
V_58 -> V_64 . V_211 = V_211 ;
V_58 -> V_64 . V_65 = V_58 ;
V_58 -> V_77 . V_218 = F_144 ( V_219 , V_213 ) ;
V_58 -> V_77 . V_220 = & V_221 ;
V_58 -> V_77 . V_222 = & V_77 -> V_77 ;
V_58 -> V_77 . V_223 = F_36 ;
F_145 ( & V_58 -> V_77 ) ;
error = F_146 ( & V_58 -> V_64 ) ;
if ( error )
goto V_224;
F_147 ( & V_58 -> V_93 , & V_225 ) ;
error = F_148 ( & V_58 -> V_93 , & V_58 -> V_77 ) ;
if ( error )
goto V_226;
return 0 ;
V_226:
F_134 ( V_58 ) ;
F_149 ( & V_58 -> V_64 ) ;
V_224:
F_150 ( & V_58 -> V_77 ) ;
V_217:
F_151 ( V_213 ) ;
return error ;
}
static void F_152 ( struct V_63 * V_64 )
{
struct V_58 * V_58 = V_64 -> V_65 ;
F_153 ( & V_58 -> V_93 , & V_58 -> V_77 ) ;
F_134 ( V_58 ) ;
F_151 ( F_154 ( V_58 -> V_77 . V_218 ) ) ;
F_149 ( V_64 ) ;
F_150 ( & V_58 -> V_77 ) ;
}
static int T_10 F_155 ( void )
{
return F_156 ( & V_227 ) ;
}
static void T_11 F_157 ( void )
{
F_158 ( & V_227 ) ;
}
