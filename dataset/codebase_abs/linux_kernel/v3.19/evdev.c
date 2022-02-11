static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
switch ( V_3 ) {
case V_4 :
V_2 -> V_5 = V_6 ;
break;
case V_7 :
V_2 -> V_5 = V_8 ;
break;
case V_9 :
V_2 -> V_5 = V_10 ;
break;
default:
return - V_11 ;
}
return 0 ;
}
static void F_2 ( struct V_1 * V_2 , unsigned int type )
{
unsigned int V_12 , V_13 , V_14 ;
unsigned int V_15 = V_2 -> V_16 - 1 ;
bool V_17 ;
struct V_18 * V_19 ;
F_3 ( type == V_20 ) ;
V_13 = V_2 -> V_21 ;
V_2 -> V_22 = V_2 -> V_21 ;
V_14 = 1 ;
for ( V_12 = V_2 -> V_21 ; V_12 != V_2 -> V_13 ; V_12 = ( V_12 + 1 ) & V_15 ) {
V_19 = & V_2 -> V_23 [ V_12 ] ;
V_17 = V_19 -> type == V_20 && V_19 -> V_24 == V_25 ;
if ( V_19 -> type == type ) {
continue;
} else if ( V_17 && ! V_14 ) {
continue;
} else if ( V_13 != V_12 ) {
V_2 -> V_23 [ V_13 ] . time = V_19 -> time ;
V_2 -> V_23 [ V_13 ] . type = V_19 -> type ;
V_2 -> V_23 [ V_13 ] . V_24 = V_19 -> V_24 ;
V_2 -> V_23 [ V_13 ] . V_26 = V_19 -> V_26 ;
}
V_14 ++ ;
V_13 = ( V_13 + 1 ) & V_15 ;
if ( V_17 ) {
V_14 = 0 ;
V_2 -> V_22 = V_13 ;
}
}
V_2 -> V_13 = V_13 ;
}
static void F_4 ( struct V_1 * V_2 )
{
unsigned long V_27 ;
struct V_18 V_19 ;
T_1 time ;
time = V_2 -> V_5 == V_6 ?
F_5 () :
V_2 -> V_5 == V_8 ?
F_6 () :
F_7 () ;
V_19 . time = F_8 ( time ) ;
V_19 . type = V_20 ;
V_19 . V_24 = V_28 ;
V_19 . V_26 = 0 ;
F_9 ( & V_2 -> V_29 , V_27 ) ;
V_2 -> V_23 [ V_2 -> V_13 ++ ] = V_19 ;
V_2 -> V_13 &= V_2 -> V_16 - 1 ;
if ( F_10 ( V_2 -> V_13 == V_2 -> V_21 ) ) {
V_2 -> V_21 = ( V_2 -> V_13 - 1 ) & ( V_2 -> V_16 - 1 ) ;
V_2 -> V_22 = V_2 -> V_21 ;
}
F_11 ( & V_2 -> V_29 , V_27 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
const struct V_18 * V_30 )
{
V_2 -> V_23 [ V_2 -> V_13 ++ ] = * V_30 ;
V_2 -> V_13 &= V_2 -> V_16 - 1 ;
if ( F_10 ( V_2 -> V_13 == V_2 -> V_21 ) ) {
V_2 -> V_21 = ( V_2 -> V_13 - 2 ) & ( V_2 -> V_16 - 1 ) ;
V_2 -> V_23 [ V_2 -> V_21 ] . time = V_30 -> time ;
V_2 -> V_23 [ V_2 -> V_21 ] . type = V_20 ;
V_2 -> V_23 [ V_2 -> V_21 ] . V_24 = V_28 ;
V_2 -> V_23 [ V_2 -> V_21 ] . V_26 = 0 ;
V_2 -> V_22 = V_2 -> V_21 ;
}
if ( V_30 -> type == V_20 && V_30 -> V_24 == V_25 ) {
V_2 -> V_22 = V_2 -> V_13 ;
F_13 ( & V_2 -> V_31 , V_32 , V_33 ) ;
}
}
static void F_14 ( struct V_1 * V_2 ,
const struct V_34 * V_35 , unsigned int V_36 ,
T_1 * V_37 )
{
struct V_38 * V_38 = V_2 -> V_38 ;
const struct V_34 * V_39 ;
struct V_18 V_30 ;
bool V_40 = false ;
if ( V_2 -> V_41 )
return;
V_30 . time = F_8 ( V_37 [ V_2 -> V_5 ] ) ;
F_15 ( & V_2 -> V_29 ) ;
for ( V_39 = V_35 ; V_39 != V_35 + V_36 ; V_39 ++ ) {
V_30 . type = V_39 -> type ;
V_30 . V_24 = V_39 -> V_24 ;
V_30 . V_26 = V_39 -> V_26 ;
F_12 ( V_2 , & V_30 ) ;
if ( V_39 -> type == V_20 && V_39 -> V_24 == V_25 )
V_40 = true ;
}
F_16 ( & V_2 -> V_29 ) ;
if ( V_40 )
F_17 ( & V_38 -> V_42 ) ;
}
static void F_18 ( struct V_43 * V_44 ,
const struct V_34 * V_35 , unsigned int V_36 )
{
struct V_38 * V_38 = V_44 -> V_45 ;
struct V_1 * V_2 ;
T_1 V_37 [ V_46 ] ;
V_37 [ V_8 ] = F_6 () ;
V_37 [ V_6 ] = F_19 ( V_37 [ V_8 ] ) ;
V_37 [ V_10 ] = F_20 ( V_37 [ V_8 ] ,
V_47 ) ;
F_21 () ;
V_2 = F_22 ( V_38 -> V_48 ) ;
if ( V_2 )
F_14 ( V_2 , V_35 , V_36 , V_37 ) ;
else
F_23 (client, &evdev->client_list, node)
F_14 ( V_2 , V_35 , V_36 , V_37 ) ;
F_24 () ;
}
static void F_25 ( struct V_43 * V_44 ,
unsigned int type , unsigned int V_24 , int V_26 )
{
struct V_34 V_35 [] = { { type , V_24 , V_26 } } ;
F_18 ( V_44 , V_35 , 1 ) ;
}
static int F_26 ( int V_49 , struct V_50 * V_50 , int V_51 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
return F_27 ( V_49 , V_50 , V_51 , & V_2 -> V_31 ) ;
}
static int F_28 ( struct V_50 * V_50 , T_2 V_53 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
struct V_38 * V_38 = V_2 -> V_38 ;
int V_54 ;
V_54 = F_29 ( & V_38 -> V_55 ) ;
if ( V_54 )
return V_54 ;
if ( ! V_38 -> V_56 || V_2 -> V_41 )
V_54 = - V_57 ;
else
V_54 = F_30 ( & V_38 -> V_44 , V_50 ) ;
F_31 ( & V_38 -> V_55 ) ;
return V_54 ;
}
static void F_32 ( struct V_58 * V_59 )
{
struct V_38 * V_38 = F_33 ( V_59 , struct V_38 , V_59 ) ;
F_34 ( V_38 -> V_44 . V_59 ) ;
F_35 ( V_38 ) ;
}
static int F_36 ( struct V_38 * V_38 , struct V_1 * V_2 )
{
int error ;
if ( V_38 -> V_48 )
return - V_60 ;
error = F_37 ( & V_38 -> V_44 ) ;
if ( error )
return error ;
F_38 ( V_38 -> V_48 , V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_38 * V_38 , struct V_1 * V_2 )
{
struct V_1 * V_48 = F_40 ( V_38 -> V_48 ,
F_41 ( & V_38 -> V_55 ) ) ;
if ( V_48 != V_2 )
return - V_11 ;
F_38 ( V_38 -> V_48 , NULL ) ;
F_42 () ;
F_43 ( & V_38 -> V_44 ) ;
return 0 ;
}
static void F_44 ( struct V_38 * V_38 ,
struct V_1 * V_2 )
{
F_15 ( & V_38 -> V_61 ) ;
F_45 ( & V_2 -> V_62 , & V_38 -> V_63 ) ;
F_16 ( & V_38 -> V_61 ) ;
}
static void F_46 ( struct V_38 * V_38 ,
struct V_1 * V_2 )
{
F_15 ( & V_38 -> V_61 ) ;
F_47 ( & V_2 -> V_62 ) ;
F_16 ( & V_38 -> V_61 ) ;
F_42 () ;
}
static int F_48 ( struct V_38 * V_38 )
{
int V_54 ;
V_54 = F_29 ( & V_38 -> V_55 ) ;
if ( V_54 )
return V_54 ;
if ( ! V_38 -> V_56 )
V_54 = - V_57 ;
else if ( ! V_38 -> V_64 ++ ) {
V_54 = F_49 ( & V_38 -> V_44 ) ;
if ( V_54 )
V_38 -> V_64 -- ;
}
F_31 ( & V_38 -> V_55 ) ;
return V_54 ;
}
static void F_50 ( struct V_38 * V_38 )
{
F_51 ( & V_38 -> V_55 ) ;
if ( V_38 -> V_56 && ! -- V_38 -> V_64 )
F_52 ( & V_38 -> V_44 ) ;
F_31 ( & V_38 -> V_55 ) ;
}
static void F_53 ( struct V_38 * V_38 )
{
struct V_1 * V_2 ;
F_15 ( & V_38 -> V_61 ) ;
F_54 (client, &evdev->client_list, node)
F_13 ( & V_2 -> V_31 , V_32 , V_65 ) ;
F_16 ( & V_38 -> V_61 ) ;
F_17 ( & V_38 -> V_42 ) ;
}
static int F_55 ( struct V_66 * V_66 , struct V_50 * V_50 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
struct V_38 * V_38 = V_2 -> V_38 ;
F_51 ( & V_38 -> V_55 ) ;
F_39 ( V_38 , V_2 ) ;
F_31 ( & V_38 -> V_55 ) ;
F_46 ( V_38 , V_2 ) ;
if ( F_56 ( V_2 ) )
F_57 ( V_2 ) ;
else
F_35 ( V_2 ) ;
F_50 ( V_38 ) ;
return 0 ;
}
static unsigned int F_58 ( struct V_67 * V_59 )
{
unsigned int V_68 =
F_59 ( V_59 -> V_69 * V_70 ,
V_71 ) ;
return F_60 ( V_68 ) ;
}
static int F_61 ( struct V_66 * V_66 , struct V_50 * V_50 )
{
struct V_38 * V_38 = F_33 ( V_66 -> V_72 , struct V_38 , V_73 ) ;
unsigned int V_16 = F_58 ( V_38 -> V_44 . V_59 ) ;
unsigned int V_74 = sizeof( struct V_1 ) +
V_16 * sizeof( struct V_18 ) ;
struct V_1 * V_2 ;
int error ;
V_2 = F_62 ( V_74 , V_75 | V_76 ) ;
if ( ! V_2 )
V_2 = F_63 ( V_74 ) ;
if ( ! V_2 )
return - V_77 ;
V_2 -> V_16 = V_16 ;
F_64 ( & V_2 -> V_29 ) ;
V_2 -> V_38 = V_38 ;
F_44 ( V_38 , V_2 ) ;
error = F_48 ( V_38 ) ;
if ( error )
goto V_78;
V_50 -> V_52 = V_2 ;
F_65 ( V_66 , V_50 ) ;
return 0 ;
V_78:
F_46 ( V_38 , V_2 ) ;
F_66 ( V_2 ) ;
return error ;
}
static T_3 F_67 ( struct V_50 * V_50 , const char T_4 * V_23 ,
T_5 V_36 , T_6 * V_79 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
struct V_38 * V_38 = V_2 -> V_38 ;
struct V_18 V_30 ;
int V_54 = 0 ;
if ( V_36 != 0 && V_36 < F_68 () )
return - V_11 ;
V_54 = F_29 ( & V_38 -> V_55 ) ;
if ( V_54 )
return V_54 ;
if ( ! V_38 -> V_56 || V_2 -> V_41 ) {
V_54 = - V_57 ;
goto V_80;
}
while ( V_54 + F_68 () <= V_36 ) {
if ( F_69 ( V_23 + V_54 , & V_30 ) ) {
V_54 = - V_81 ;
goto V_80;
}
V_54 += F_68 () ;
F_70 ( & V_38 -> V_44 ,
V_30 . type , V_30 . V_24 , V_30 . V_26 ) ;
}
V_80:
F_31 ( & V_38 -> V_55 ) ;
return V_54 ;
}
static int F_71 ( struct V_1 * V_2 ,
struct V_18 * V_30 )
{
int V_82 ;
F_72 ( & V_2 -> V_29 ) ;
V_82 = V_2 -> V_22 != V_2 -> V_21 ;
if ( V_82 ) {
* V_30 = V_2 -> V_23 [ V_2 -> V_21 ++ ] ;
V_2 -> V_21 &= V_2 -> V_16 - 1 ;
}
F_73 ( & V_2 -> V_29 ) ;
return V_82 ;
}
static T_3 F_74 ( struct V_50 * V_50 , char T_4 * V_23 ,
T_5 V_36 , T_6 * V_79 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
struct V_38 * V_38 = V_2 -> V_38 ;
struct V_18 V_30 ;
T_5 V_83 = 0 ;
int error ;
if ( V_36 != 0 && V_36 < F_68 () )
return - V_11 ;
for (; ; ) {
if ( ! V_38 -> V_56 || V_2 -> V_41 )
return - V_57 ;
if ( V_2 -> V_22 == V_2 -> V_21 &&
( V_50 -> V_84 & V_85 ) )
return - V_86 ;
if ( V_36 == 0 )
break;
while ( V_83 + F_68 () <= V_36 &&
F_71 ( V_2 , & V_30 ) ) {
if ( F_75 ( V_23 + V_83 , & V_30 ) )
return - V_81 ;
V_83 += F_68 () ;
}
if ( V_83 )
break;
if ( ! ( V_50 -> V_84 & V_85 ) ) {
error = F_76 ( V_38 -> V_42 ,
V_2 -> V_22 != V_2 -> V_21 ||
! V_38 -> V_56 || V_2 -> V_41 ) ;
if ( error )
return error ;
}
}
return V_83 ;
}
static unsigned int F_77 ( struct V_50 * V_50 , T_7 * V_42 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
struct V_38 * V_38 = V_2 -> V_38 ;
unsigned int V_15 ;
F_78 ( V_50 , & V_38 -> V_42 , V_42 ) ;
if ( V_38 -> V_56 && ! V_2 -> V_41 )
V_15 = V_87 | V_88 ;
else
V_15 = V_89 | V_90 ;
if ( V_2 -> V_22 != V_2 -> V_21 )
V_15 |= V_91 | V_92 ;
return V_15 ;
}
static int F_79 ( unsigned long * V_93 , unsigned int V_94 ,
unsigned int V_95 , void T_4 * V_96 , int V_97 )
{
int V_98 , V_12 ;
if ( V_97 ) {
V_98 = F_80 ( V_94 ) * sizeof( V_99 ) ;
if ( V_98 > V_95 )
V_98 = V_95 ;
for ( V_12 = 0 ; V_12 < V_98 / sizeof( V_99 ) ; V_12 ++ )
if ( F_81 ( ( V_99 T_4 * ) V_96 + V_12 ,
( V_99 * ) V_93 +
V_12 + 1 - ( ( V_12 % 2 ) << 1 ) ,
sizeof( V_99 ) ) )
return - V_81 ;
} else {
V_98 = F_82 ( V_94 ) * sizeof( long ) ;
if ( V_98 > V_95 )
V_98 = V_95 ;
if ( F_81 ( V_96 , V_93 , V_98 ) )
return - V_81 ;
}
return V_98 ;
}
static int F_79 ( unsigned long * V_93 , unsigned int V_94 ,
unsigned int V_95 , void T_4 * V_96 , int V_97 )
{
int V_98 = V_97 ?
F_80 ( V_94 ) * sizeof( V_99 ) :
F_82 ( V_94 ) * sizeof( long ) ;
if ( V_98 > V_95 )
V_98 = V_95 ;
return F_81 ( V_96 , V_93 , V_98 ) ? - V_81 : V_98 ;
}
static int F_79 ( unsigned long * V_93 , unsigned int V_94 ,
unsigned int V_95 , void T_4 * V_96 , int V_97 )
{
int V_98 = F_82 ( V_94 ) * sizeof( long ) ;
if ( V_98 > V_95 )
V_98 = V_95 ;
return F_81 ( V_96 , V_93 , V_98 ) ? - V_81 : V_98 ;
}
static int F_83 ( const char * V_100 , unsigned int V_95 , void T_4 * V_96 )
{
int V_98 ;
if ( ! V_100 )
return - V_101 ;
V_98 = strlen ( V_100 ) + 1 ;
if ( V_98 > V_95 )
V_98 = V_95 ;
return F_81 ( V_96 , V_100 , V_98 ) ? - V_81 : V_98 ;
}
static int F_84 ( struct V_67 * V_59 ,
unsigned int type , unsigned int V_74 ,
void T_4 * V_96 , int V_102 )
{
unsigned long * V_93 ;
int V_98 ;
switch ( type ) {
case 0 : V_93 = V_59 -> V_103 ; V_98 = V_104 ; break;
case V_105 : V_93 = V_59 -> V_106 ; V_98 = V_107 ; break;
case V_108 : V_93 = V_59 -> V_109 ; V_98 = V_110 ; break;
case V_111 : V_93 = V_59 -> V_112 ; V_98 = V_113 ; break;
case V_114 : V_93 = V_59 -> V_115 ; V_98 = V_116 ; break;
case V_117 : V_93 = V_59 -> V_118 ; V_98 = V_119 ; break;
case V_120 : V_93 = V_59 -> V_121 ; V_98 = V_122 ; break;
case V_123 : V_93 = V_59 -> V_124 ; V_98 = V_125 ; break;
case V_126 : V_93 = V_59 -> V_127 ; V_98 = V_128 ; break;
default: return - V_11 ;
}
return F_79 ( V_93 , V_98 , V_74 , V_96 , V_102 ) ;
}
static int F_85 ( struct V_67 * V_59 , void T_4 * V_96 )
{
struct V_129 V_130 = {
. V_98 = sizeof( unsigned int ) ,
. V_27 = 0 ,
} ;
int T_4 * V_131 = ( int T_4 * ) V_96 ;
int error ;
if ( F_86 ( V_130 . V_132 , V_96 , sizeof( unsigned int ) ) )
return - V_81 ;
error = F_87 ( V_59 , & V_130 ) ;
if ( error )
return error ;
if ( F_88 ( V_130 . V_133 , V_131 + 1 ) )
return - V_81 ;
return 0 ;
}
static int F_89 ( struct V_67 * V_59 , void T_4 * V_96 )
{
struct V_129 V_130 ;
int error ;
if ( F_86 ( & V_130 , V_96 , sizeof( V_130 ) ) )
return - V_81 ;
error = F_87 ( V_59 , & V_130 ) ;
if ( error )
return error ;
if ( F_81 ( V_96 , & V_130 , sizeof( V_130 ) ) )
return - V_81 ;
return 0 ;
}
static int F_90 ( struct V_67 * V_59 , void T_4 * V_96 )
{
struct V_129 V_130 = {
. V_98 = sizeof( unsigned int ) ,
. V_27 = 0 ,
} ;
int T_4 * V_131 = ( int T_4 * ) V_96 ;
if ( F_86 ( V_130 . V_132 , V_96 , sizeof( unsigned int ) ) )
return - V_81 ;
if ( F_91 ( V_130 . V_133 , V_131 + 1 ) )
return - V_81 ;
return F_92 ( V_59 , & V_130 ) ;
}
static int F_93 ( struct V_67 * V_59 , void T_4 * V_96 )
{
struct V_129 V_130 ;
if ( F_86 ( & V_130 , V_96 , sizeof( V_130 ) ) )
return - V_81 ;
if ( V_130 . V_98 > sizeof( V_130 . V_132 ) )
return - V_11 ;
return F_92 ( V_59 , & V_130 ) ;
}
static int F_94 ( struct V_1 * V_2 ,
struct V_67 * V_59 , unsigned int type ,
unsigned long * V_93 , unsigned int V_94 ,
unsigned int V_95 , void T_4 * V_96 ,
int V_97 )
{
int V_134 ;
unsigned long * V_135 ;
T_5 V_98 ;
V_98 = F_82 ( V_94 ) * sizeof( unsigned long ) ;
V_135 = F_95 ( V_98 , V_75 ) ;
if ( ! V_135 )
return - V_77 ;
F_72 ( & V_59 -> V_136 ) ;
F_15 ( & V_2 -> V_29 ) ;
memcpy ( V_135 , V_93 , V_98 ) ;
F_16 ( & V_59 -> V_136 ) ;
F_2 ( V_2 , type ) ;
F_73 ( & V_2 -> V_29 ) ;
V_134 = F_79 ( V_135 , V_94 , V_95 , V_96 , V_97 ) ;
if ( V_134 < 0 )
F_4 ( V_2 ) ;
F_35 ( V_135 ) ;
return V_134 ;
}
static int F_96 ( struct V_67 * V_59 ,
unsigned int V_74 ,
int T_4 * V_131 )
{
const struct V_137 * V_138 = V_59 -> V_138 ;
unsigned int V_24 ;
int V_139 ;
int V_12 ;
if ( F_91 ( V_24 , & V_131 [ 0 ] ) )
return - V_81 ;
if ( ! V_138 || ! F_97 ( V_24 ) )
return - V_11 ;
V_139 = ( V_74 - sizeof( V_140 ) ) / sizeof( V_141 ) ;
for ( V_12 = 0 ; V_12 < V_138 -> V_142 && V_12 < V_139 ; V_12 ++ ) {
int V_26 = F_98 ( & V_138 -> V_143 [ V_12 ] , V_24 ) ;
if ( F_88 ( V_26 , & V_131 [ 1 + V_12 ] ) )
return - V_81 ;
}
return 0 ;
}
static int F_99 ( struct V_38 * V_38 , struct V_1 * V_2 ,
struct V_50 * V_50 )
{
V_2 -> V_41 = true ;
F_39 ( V_38 , V_2 ) ;
F_30 ( & V_38 -> V_44 , V_50 ) ;
F_17 ( & V_38 -> V_42 ) ;
return 0 ;
}
static long F_100 ( struct V_50 * V_50 , unsigned int V_144 ,
void T_4 * V_96 , int V_102 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
struct V_38 * V_38 = V_2 -> V_38 ;
struct V_67 * V_59 = V_38 -> V_44 . V_59 ;
struct V_145 abs ;
struct V_146 V_147 ;
int T_4 * V_131 = ( int T_4 * ) V_96 ;
unsigned int V_12 , V_148 , V_149 , V_39 ;
unsigned int V_74 ;
int error ;
switch ( V_144 ) {
case V_150 :
return F_88 ( V_151 , V_131 ) ;
case V_152 :
if ( F_81 ( V_96 , & V_59 -> V_53 , sizeof( struct V_153 ) ) )
return - V_81 ;
return 0 ;
case V_154 :
if ( ! F_101 ( V_155 , V_59 -> V_103 ) )
return - V_156 ;
if ( F_88 ( V_59 -> V_157 [ V_158 ] , V_131 ) )
return - V_81 ;
if ( F_88 ( V_59 -> V_157 [ V_159 ] , V_131 + 1 ) )
return - V_81 ;
return 0 ;
case V_160 :
if ( ! F_101 ( V_155 , V_59 -> V_103 ) )
return - V_156 ;
if ( F_91 ( V_149 , V_131 ) )
return - V_81 ;
if ( F_91 ( V_39 , V_131 + 1 ) )
return - V_81 ;
F_70 ( & V_38 -> V_44 , V_155 , V_158 , V_149 ) ;
F_70 ( & V_38 -> V_44 , V_155 , V_159 , V_39 ) ;
return 0 ;
case V_161 :
return F_102 ( V_59 , ( int ) ( unsigned long ) V_96 , V_50 ) ;
case V_162 :
V_12 = F_101 ( V_123 , V_59 -> V_103 ) ?
V_59 -> V_163 -> V_164 : 0 ;
if ( F_88 ( V_12 , V_131 ) )
return - V_81 ;
return 0 ;
case V_165 :
if ( V_96 )
return F_36 ( V_38 , V_2 ) ;
else
return F_39 ( V_38 , V_2 ) ;
case V_166 :
if ( V_96 )
return - V_11 ;
else
return F_99 ( V_38 , V_2 , V_50 ) ;
case V_167 :
if ( F_86 ( & V_12 , V_96 , sizeof( unsigned int ) ) )
return - V_81 ;
return F_1 ( V_2 , V_12 ) ;
case V_168 :
return F_85 ( V_59 , V_96 ) ;
case V_169 :
return F_90 ( V_59 , V_96 ) ;
case V_170 :
return F_89 ( V_59 , V_96 ) ;
case V_171 :
return F_93 ( V_59 , V_96 ) ;
}
V_74 = F_103 ( V_144 ) ;
#define F_104 ( T_8 ) ((nr) & ~(_IOC_SIZEMASK << _IOC_SIZESHIFT))
switch ( F_104 ( V_144 ) ) {
case F_105 ( 0 ) :
return F_79 ( V_59 -> V_172 , V_173 ,
V_74 , V_96 , V_102 ) ;
case F_106 ( 0 ) :
return F_96 ( V_59 , V_74 , V_131 ) ;
case F_107 ( 0 ) :
return F_94 ( V_2 , V_59 , V_105 , V_59 -> V_174 ,
V_107 , V_74 , V_96 , V_102 ) ;
case F_108 ( 0 ) :
return F_94 ( V_2 , V_59 , V_117 , V_59 -> V_175 ,
V_119 , V_74 , V_96 , V_102 ) ;
case F_109 ( 0 ) :
return F_94 ( V_2 , V_59 , V_120 , V_59 -> V_176 ,
V_122 , V_74 , V_96 , V_102 ) ;
case F_110 ( 0 ) :
return F_94 ( V_2 , V_59 , V_126 , V_59 -> V_177 ,
V_128 , V_74 , V_96 , V_102 ) ;
case F_111 ( 0 ) :
return F_83 ( V_59 -> V_178 , V_74 , V_96 ) ;
case F_112 ( 0 ) :
return F_83 ( V_59 -> V_179 , V_74 , V_96 ) ;
case F_113 ( 0 ) :
return F_83 ( V_59 -> V_180 , V_74 , V_96 ) ;
case F_104 ( V_181 ) :
if ( F_114 ( V_96 , V_74 , & V_147 ) )
return - V_81 ;
error = F_115 ( V_59 , & V_147 , V_50 ) ;
if ( error )
return error ;
if ( F_88 ( V_147 . V_53 , & ( ( (struct V_146 T_4 * ) V_96 ) -> V_53 ) ) )
return - V_81 ;
return 0 ;
}
if ( F_116 ( V_144 ) != 'E' )
return - V_11 ;
if ( F_117 ( V_144 ) == V_182 ) {
if ( ( F_118 ( V_144 ) & ~ V_104 ) == F_118 ( F_119 ( 0 , 0 ) ) )
return F_84 ( V_59 ,
F_118 ( V_144 ) & V_104 , V_74 ,
V_96 , V_102 ) ;
if ( ( F_118 ( V_144 ) & ~ V_113 ) == F_118 ( F_120 ( 0 ) ) ) {
if ( ! V_59 -> V_183 )
return - V_11 ;
V_148 = F_118 ( V_144 ) & V_113 ;
abs = V_59 -> V_183 [ V_148 ] ;
if ( F_81 ( V_96 , & abs , F_121 ( T_5 ,
V_74 , sizeof( struct V_145 ) ) ) )
return - V_81 ;
return 0 ;
}
}
if ( F_117 ( V_144 ) == V_184 ) {
if ( ( F_118 ( V_144 ) & ~ V_113 ) == F_118 ( F_122 ( 0 ) ) ) {
if ( ! V_59 -> V_183 )
return - V_11 ;
V_148 = F_118 ( V_144 ) & V_113 ;
if ( F_86 ( & abs , V_96 , F_121 ( T_5 ,
V_74 , sizeof( struct V_145 ) ) ) )
return - V_81 ;
if ( V_74 < sizeof( struct V_145 ) )
abs . V_185 = 0 ;
if ( V_148 == V_186 )
return - V_11 ;
F_72 ( & V_59 -> V_136 ) ;
V_59 -> V_183 [ V_148 ] = abs ;
F_73 ( & V_59 -> V_136 ) ;
return 0 ;
}
}
return - V_11 ;
}
static long F_123 ( struct V_50 * V_50 , unsigned int V_144 ,
void T_4 * V_96 , int V_102 )
{
struct V_1 * V_2 = V_50 -> V_52 ;
struct V_38 * V_38 = V_2 -> V_38 ;
int V_54 ;
V_54 = F_29 ( & V_38 -> V_55 ) ;
if ( V_54 )
return V_54 ;
if ( ! V_38 -> V_56 || V_2 -> V_41 ) {
V_54 = - V_57 ;
goto V_80;
}
V_54 = F_100 ( V_50 , V_144 , V_96 , V_102 ) ;
V_80:
F_31 ( & V_38 -> V_55 ) ;
return V_54 ;
}
static long F_124 ( struct V_50 * V_50 , unsigned int V_144 , unsigned long V_187 )
{
return F_123 ( V_50 , V_144 , ( void T_4 * ) V_187 , 0 ) ;
}
static long F_125 ( struct V_50 * V_50 ,
unsigned int V_144 , unsigned long V_187 )
{
return F_123 ( V_50 , V_144 , F_126 ( V_187 ) , 1 ) ;
}
static void F_127 ( struct V_38 * V_38 )
{
F_51 ( & V_38 -> V_55 ) ;
V_38 -> V_56 = false ;
F_31 ( & V_38 -> V_55 ) ;
}
static void F_128 ( struct V_38 * V_38 )
{
struct V_43 * V_44 = & V_38 -> V_44 ;
F_127 ( V_38 ) ;
F_53 ( V_38 ) ;
F_129 ( & V_38 -> V_73 ) ;
if ( V_38 -> V_64 ) {
F_30 ( V_44 , NULL ) ;
F_52 ( V_44 ) ;
}
}
static int F_130 ( struct V_188 * V_189 , struct V_67 * V_59 ,
const struct V_190 * V_53 )
{
struct V_38 * V_38 ;
int V_191 ;
int V_192 ;
int error ;
V_191 = F_131 ( V_193 , V_194 , true ) ;
if ( V_191 < 0 ) {
error = V_191 ;
F_132 ( L_1 , error ) ;
return error ;
}
V_38 = F_62 ( sizeof( struct V_38 ) , V_75 ) ;
if ( ! V_38 ) {
error = - V_77 ;
goto V_195;
}
F_133 ( & V_38 -> V_63 ) ;
F_64 ( & V_38 -> V_61 ) ;
F_134 ( & V_38 -> V_55 ) ;
F_135 ( & V_38 -> V_42 ) ;
V_38 -> V_56 = true ;
V_192 = V_191 ;
if ( V_192 < V_193 + V_194 )
V_192 -= V_193 ;
F_136 ( & V_38 -> V_59 , L_2 , V_192 ) ;
V_38 -> V_44 . V_59 = F_137 ( V_59 ) ;
V_38 -> V_44 . V_178 = F_138 ( & V_38 -> V_59 ) ;
V_38 -> V_44 . V_189 = V_189 ;
V_38 -> V_44 . V_45 = V_38 ;
V_38 -> V_59 . V_196 = F_139 ( V_197 , V_191 ) ;
V_38 -> V_59 . V_198 = & V_199 ;
V_38 -> V_59 . V_200 = & V_59 -> V_59 ;
V_38 -> V_59 . V_201 = F_32 ;
F_140 ( & V_38 -> V_59 ) ;
error = F_141 ( & V_38 -> V_44 ) ;
if ( error )
goto V_202;
F_142 ( & V_38 -> V_73 , & V_203 ) ;
V_38 -> V_73 . V_204 . V_200 = & V_38 -> V_59 . V_204 ;
error = F_143 ( & V_38 -> V_73 , V_38 -> V_59 . V_196 , 1 ) ;
if ( error )
goto V_205;
error = F_144 ( & V_38 -> V_59 ) ;
if ( error )
goto V_206;
return 0 ;
V_206:
F_128 ( V_38 ) ;
V_205:
F_145 ( & V_38 -> V_44 ) ;
V_202:
F_146 ( & V_38 -> V_59 ) ;
V_195:
F_147 ( V_191 ) ;
return error ;
}
static void F_148 ( struct V_43 * V_44 )
{
struct V_38 * V_38 = V_44 -> V_45 ;
F_149 ( & V_38 -> V_59 ) ;
F_128 ( V_38 ) ;
F_147 ( F_150 ( V_38 -> V_59 . V_196 ) ) ;
F_145 ( V_44 ) ;
F_146 ( & V_38 -> V_59 ) ;
}
static int T_9 F_151 ( void )
{
return F_152 ( & V_207 ) ;
}
static void T_10 F_153 ( void )
{
F_154 ( & V_207 ) ;
}
