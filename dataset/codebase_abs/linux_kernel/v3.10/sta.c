static int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
if ( V_3 >= V_5 ) {
F_3 ( V_2 , L_1 , V_3 ) ;
return - V_6 ;
}
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) )
F_3 ( V_2 , L_2
L_3 ,
V_3 , V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) {
F_4 ( V_2 ,
L_4
L_5 ,
V_3 , V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
} else {
V_2 -> V_7 [ V_3 ] . V_8 |= V_12 ;
F_4 ( V_2 , L_6 ,
V_3 , V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
}
return 0 ;
}
static int F_5 ( struct V_1 * V_2 ,
struct V_13 * V_14 ,
struct V_15 * V_16 )
{
struct V_17 * V_18 = ( void * ) V_16 -> V_19 ;
T_1 V_3 = V_14 -> V_10 . V_3 ;
int V_20 = - V_21 ;
if ( V_16 -> V_22 . V_23 & V_24 ) {
F_3 ( V_2 , L_7 ,
V_16 -> V_22 . V_23 ) ;
return V_20 ;
}
F_6 ( V_2 , L_8 ,
V_3 ) ;
F_7 ( & V_2 -> V_4 ) ;
switch ( V_18 -> V_25 ) {
case V_26 :
F_6 ( V_2 , L_9 ) ;
V_20 = F_1 ( V_2 , V_3 ) ;
break;
case V_27 :
F_3 ( V_2 , L_10 ,
V_3 ) ;
break;
case V_28 :
F_3 ( V_2 , L_11
L_12 , V_3 ) ;
break;
case V_29 :
F_3 ( V_2 , L_13 ,
V_3 ) ;
break;
default:
F_4 ( V_2 , L_14 ,
V_18 -> V_25 ) ;
break;
}
F_6 ( V_2 , L_15 ,
V_2 -> V_7 [ V_3 ] . V_10 . V_30 ==
V_31 ? L_16 : L_17 ,
V_3 , V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
F_6 ( V_2 , L_18 ,
V_2 -> V_7 [ V_3 ] . V_10 . V_30 ==
V_31 ? L_16 : L_17 ,
V_14 -> V_10 . V_11 ) ;
F_8 ( & V_2 -> V_4 ) ;
return V_20 ;
}
int F_9 ( struct V_1 * V_2 , struct V_32 * V_33 ,
struct V_34 * V_35 )
{
struct V_15 * V_16 = F_10 ( V_33 ) ;
if ( ! V_35 )
return 0 ;
return F_5 ( V_2 , ( void * ) V_35 -> V_36 , V_16 ) ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_13 * V_10 , T_1 V_23 )
{
int V_20 = 0 ;
struct V_37 V_35 = {
. V_38 = V_39 ,
. V_23 = V_23 ,
. V_19 = { V_10 , } ,
. V_40 = { sizeof( * V_10 ) , } ,
} ;
T_1 V_3 V_41 = V_10 -> V_10 . V_3 ;
F_6 ( V_2 , L_19 ,
V_3 , V_10 -> V_10 . V_11 , V_23 & V_42 ? L_20 : L_21 ) ;
if ( ! ( V_23 & V_42 ) ) {
V_35 . V_23 |= V_43 ;
F_12 () ;
}
V_20 = F_13 ( V_2 , & V_35 ) ;
if ( V_20 || ( V_23 & V_42 ) )
return V_20 ;
F_14 ( & V_35 ) ;
if ( V_35 . V_44 )
F_3 ( V_2 , L_22 , V_45 ,
V_35 . V_44 ) ;
return V_35 . V_44 ;
}
bool F_15 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_48 * V_10 )
{
if ( ! V_47 -> V_49 . V_50 || ! V_47 -> V_49 . V_51 )
return false ;
#ifdef F_16
if ( V_2 -> V_52 )
return false ;
#endif
if ( ! V_10 )
return true ;
return V_10 -> V_53 >= V_54 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_48 * V_10 ,
struct V_46 * V_47 ,
T_2 * V_23 , T_2 * V_55 )
{
struct V_56 * V_57 = & V_10 -> V_58 ;
* V_55 = V_59 |
V_60 |
V_61 |
V_62 |
V_63 ;
* V_23 = 0 ;
if ( ! V_10 || ! V_57 -> V_64 )
return;
F_6 ( V_2 , L_23 ,
V_10 -> V_11 ,
( V_10 -> V_65 == V_66 ) ?
L_24 :
( V_10 -> V_65 == V_67 ) ?
L_25 : L_26 ) ;
switch ( V_10 -> V_65 ) {
case V_66 :
* V_23 |= V_60 ;
break;
case V_67 :
* V_23 |= V_59 ;
break;
case V_68 :
break;
default:
F_18 ( V_2 , L_27 , V_10 -> V_65 ) ;
break;
}
* V_23 |= F_19 (
( V_69 ) V_57 -> V_70 << V_71 ) ;
* V_23 |= F_19 (
( V_69 ) V_57 -> V_72 << V_73 ) ;
if ( F_15 ( V_2 , V_47 , V_10 ) )
* V_23 |= V_61 ;
}
int F_20 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_48 * V_10 )
{
T_1 V_3 = F_21 ( V_10 ) ;
T_2 V_23 , V_55 ;
struct V_13 V_35 ;
if ( F_22 ( V_3 == V_74 ) )
return - V_6 ;
F_17 ( V_2 , V_10 , V_47 , & V_23 , & V_55 ) ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_75 &= ~ V_55 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_75 |= V_23 ;
F_8 ( & V_2 -> V_4 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_30 = V_31 ;
V_35 . V_76 = V_55 ;
V_35 . V_75 = V_23 ;
V_35 . V_10 . V_3 = V_3 ;
return F_11 ( V_2 , & V_35 , V_77 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_78 ,
struct V_48 * V_10 ,
struct V_46 * V_47 )
{
T_2 V_23 , V_55 ;
F_17 ( V_2 , V_10 , V_47 , & V_23 , & V_55 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_78 ] . V_10 . V_75 &= ~ V_55 ;
V_2 -> V_7 [ V_78 ] . V_10 . V_75 |= V_23 ;
}
T_1 F_24 ( struct V_1 * V_2 , struct V_46 * V_47 ,
const T_1 * V_11 , bool V_79 , struct V_48 * V_10 )
{
struct V_80 * V_81 ;
int V_82 ;
T_1 V_3 = V_74 ;
if ( V_79 )
V_3 = V_47 -> V_83 ;
else if ( F_25 ( V_11 ) )
V_3 = V_47 -> V_84 ;
else
for ( V_82 = V_85 ; V_82 < V_5 ; V_82 ++ ) {
if ( F_26 ( V_2 -> V_7 [ V_82 ] . V_10 . V_10 . V_11 ,
V_11 ) ) {
V_3 = V_82 ;
break;
}
if ( ! V_2 -> V_7 [ V_82 ] . V_8 &&
V_3 == V_74 )
V_3 = V_82 ;
}
if ( F_27 ( V_3 == V_74 ) )
return V_3 ;
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_86 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) &&
F_26 ( V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 , V_11 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
return V_3 ;
}
V_81 = & V_2 -> V_7 [ V_3 ] ;
V_81 -> V_8 = V_9 ;
F_4 ( V_2 , L_32 ,
V_3 , V_11 ) ;
V_2 -> V_87 ++ ;
memset ( & V_81 -> V_10 , 0 , sizeof( struct V_13 ) ) ;
memcpy ( V_81 -> V_10 . V_10 . V_11 , V_11 , V_88 ) ;
V_81 -> V_10 . V_30 = 0 ;
V_81 -> V_10 . V_10 . V_3 = V_3 ;
V_81 -> V_10 . V_75 = V_47 -> V_75 ;
V_81 -> V_89 = V_47 -> V_89 ;
if ( V_10 ) {
struct V_90 * V_91 ;
V_91 = ( void * ) V_10 -> V_92 ;
V_91 -> V_47 = V_47 ;
}
F_23 ( V_2 , V_3 , V_10 , V_47 ) ;
return V_3 ;
}
int F_28 ( struct V_1 * V_2 , struct V_46 * V_47 ,
const T_1 * V_11 , bool V_79 ,
struct V_48 * V_10 , T_1 * V_93 )
{
int V_20 = 0 ;
T_1 V_3 ;
struct V_13 V_94 ;
* V_93 = 0 ;
F_7 ( & V_2 -> V_4 ) ;
V_3 = F_24 ( V_2 , V_47 , V_11 , V_79 , V_10 ) ;
if ( V_3 == V_74 ) {
F_3 ( V_2 , L_33 ,
V_11 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_86 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_95 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_95 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_86 ;
memcpy ( & V_94 , & V_2 -> V_7 [ V_3 ] . V_10 ,
sizeof( struct V_13 ) ) ;
F_8 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_94 , V_77 ) ;
if ( V_20 ) {
F_7 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_86 ;
F_8 ( & V_2 -> V_4 ) ;
}
* V_93 = V_3 ;
return V_20 ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
if ( ( V_2 -> V_7 [ V_3 ] . V_8 &
( V_12 | V_9 ) ) !=
V_12 )
F_3 ( V_2 , L_35 , V_3 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_12 ;
memset ( & V_2 -> V_7 [ V_3 ] , 0 , sizeof( struct V_80 ) ) ;
F_4 ( V_2 , L_36 , V_3 ) ;
}
static int F_30 ( struct V_1 * V_2 ,
const T_1 * V_11 , int V_3 ,
bool V_96 )
{
struct V_15 * V_16 ;
int V_20 ;
struct V_97 V_98 ;
struct V_37 V_35 = {
. V_38 = V_99 ,
. V_40 = { sizeof( struct V_97 ) , } ,
. V_23 = V_77 ,
. V_19 = { & V_98 , } ,
} ;
memset ( & V_98 , 0 , sizeof( V_98 ) ) ;
V_98 . V_100 = 1 ;
memcpy ( & V_98 . V_11 , V_11 , V_88 ) ;
V_35 . V_23 |= V_43 ;
V_20 = F_13 ( V_2 , & V_35 ) ;
if ( V_20 )
return V_20 ;
V_16 = V_35 . V_101 ;
if ( V_16 -> V_22 . V_23 & V_24 ) {
F_3 ( V_2 , L_37 ,
V_16 -> V_22 . V_23 ) ;
V_20 = - V_21 ;
}
if ( ! V_20 ) {
struct V_102 * V_103 = ( void * ) V_16 -> V_19 ;
switch ( V_103 -> V_25 ) {
case V_104 :
if ( ! V_96 ) {
F_7 ( & V_2 -> V_4 ) ;
F_29 ( V_2 , V_3 ) ;
F_8 ( & V_2 -> V_4 ) ;
}
F_4 ( V_2 , L_38 ) ;
break;
default:
V_20 = - V_21 ;
F_3 ( V_2 , L_39 ) ;
break;
}
}
F_14 ( & V_35 ) ;
return V_20 ;
}
int F_31 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_105 ;
if ( ! F_32 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return 0 ;
}
F_4 ( V_2 , L_41 ,
V_3 , V_11 ) ;
if ( F_33 ( V_3 == V_74 ) )
return - V_6 ;
F_7 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) {
F_6 ( V_2 , L_42 ,
V_11 ) ;
goto V_106;
}
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_6 ( V_2 , L_43 ,
V_11 ) ;
goto V_106;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_107 ) {
F_34 ( V_2 -> V_7 [ V_3 ] . V_108 ) ;
V_2 -> V_7 [ V_3 ] . V_108 = NULL ;
}
for ( V_105 = 0 ; V_105 < V_109 ; V_105 ++ )
memset ( & V_2 -> V_110 [ V_3 ] [ V_105 ] , 0 ,
sizeof( V_2 -> V_110 [ V_3 ] [ V_105 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_87 -- ;
if ( F_33 ( V_2 -> V_87 < 0 ) )
V_2 -> V_87 = 0 ;
F_8 ( & V_2 -> V_4 ) ;
return F_30 ( V_2 , V_11 , V_3 , false ) ;
V_106:
F_8 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
void F_35 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_105 ;
if ( ! F_32 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return;
}
F_4 ( V_2 , L_44 , V_11 , V_3 ) ;
if ( F_22 ( V_3 == V_74 ) )
return;
F_7 ( & V_2 -> V_4 ) ;
F_22 ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) ;
for ( V_105 = 0 ; V_105 < V_109 ; V_105 ++ )
memset ( & V_2 -> V_110 [ V_3 ] [ V_105 ] , 0 ,
sizeof( V_2 -> V_110 [ V_3 ] [ V_105 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_87 -- ;
if ( F_22 ( V_2 -> V_87 < 0 ) )
V_2 -> V_87 = 0 ;
F_8 ( & V_2 -> V_4 ) ;
}
static void F_36 ( struct V_1 * V_2 , struct V_46 * V_47 ,
T_1 V_3 , struct V_111 * V_112 )
{
int V_82 , V_113 ;
V_69 V_114 = 0 ;
T_2 V_115 ;
F_2 ( & V_2 -> V_116 ) ;
memset ( V_112 , 0 , sizeof( * V_112 ) ) ;
if ( V_2 -> V_117 == V_118 )
V_113 = V_119 ;
else if ( V_47 && V_47 -> V_120 && V_47 -> V_120 -> V_121 )
V_113 = V_119 ;
else
V_113 = V_122 ;
if ( V_113 >= V_123 && V_113 <= V_124 )
V_114 |= V_125 ;
V_114 |= F_37 ( V_2 -> V_126 -> V_127 ) <<
V_128 ;
V_115 = F_38 ( V_129 [ V_113 ] . V_130 , V_114 ) ;
for ( V_82 = 0 ; V_82 < V_131 ; V_82 ++ )
V_112 -> V_132 [ V_82 ] . V_115 = V_115 ;
V_112 -> V_133 . V_134 =
F_37 ( V_2 -> V_126 -> V_127 ) ;
V_112 -> V_133 . V_135 =
V_2 -> V_126 -> V_127 &
~ F_37 ( V_2 -> V_126 -> V_127 ) ;
if ( ! V_112 -> V_133 . V_135 ) {
V_112 -> V_133 . V_135 = V_136 ;
} else if ( F_39 ( V_2 -> V_126 -> V_127 ) == 2 ) {
V_112 -> V_133 . V_135 =
V_2 -> V_126 -> V_127 ;
}
V_112 -> V_137 . V_138 =
V_139 ;
V_112 -> V_137 . V_140 =
F_40 ( V_141 ) ;
V_112 -> V_3 = V_3 ;
}
void F_41 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
int V_82 ;
bool V_142 = false ;
F_6 ( V_2 , L_45 ) ;
F_7 ( & V_2 -> V_4 ) ;
for ( V_82 = 0 ; V_82 < V_5 ; V_82 ++ ) {
if ( V_47 && V_47 -> V_89 != V_2 -> V_7 [ V_82 ] . V_89 )
continue;
if ( V_2 -> V_7 [ V_82 ] . V_8 & V_12 ) {
F_6 ( V_2 ,
L_46 , V_82 ) ;
V_2 -> V_7 [ V_82 ] . V_8 &= ~ V_12 ;
V_142 = true ;
}
}
F_8 ( & V_2 -> V_4 ) ;
if ( ! V_142 )
F_6 ( V_2 ,
L_47 ) ;
}
void F_42 ( struct V_1 * V_2 , struct V_46 * V_47 )
{
struct V_13 V_94 ;
static const struct V_111 V_143 = {} ;
struct V_111 V_108 ;
int V_82 ;
bool V_144 = false ;
int V_20 ;
bool V_145 ;
if ( ! F_32 ( V_2 ) ) {
F_6 ( V_2 ,
L_48 ) ;
return;
}
F_4 ( V_2 , L_49 ) ;
F_7 ( & V_2 -> V_4 ) ;
for ( V_82 = 0 ; V_82 < V_5 ; V_82 ++ ) {
if ( V_47 -> V_89 != V_2 -> V_7 [ V_82 ] . V_89 )
continue;
if ( ( V_2 -> V_7 [ V_82 ] . V_8 & V_9 ) &&
! ( V_2 -> V_7 [ V_82 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_50 ,
V_2 -> V_7 [ V_82 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_82 ] . V_10 . V_30 = 0 ;
V_2 -> V_7 [ V_82 ] . V_8 |= V_86 ;
V_144 = true ;
}
}
for ( V_82 = 0 ; V_82 < V_5 ; V_82 ++ ) {
if ( ( V_2 -> V_7 [ V_82 ] . V_8 & V_86 ) ) {
memcpy ( & V_94 , & V_2 -> V_7 [ V_82 ] . V_10 ,
sizeof( struct V_13 ) ) ;
V_145 = false ;
if ( V_2 -> V_7 [ V_82 ] . V_108 ) {
if ( V_2 -> V_146 )
F_36 ( V_2 , V_47 , V_82 , & V_108 ) ;
else
memcpy ( & V_108 , V_2 -> V_7 [ V_82 ] . V_108 ,
sizeof( struct V_111 ) ) ;
if ( memcmp ( & V_108 , & V_143 , sizeof( V_108 ) ) )
V_145 = true ;
}
F_8 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_94 , V_77 ) ;
if ( V_20 ) {
F_7 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_82 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_82 ] . V_8 &=
~ V_9 ;
V_2 -> V_7 [ V_82 ] . V_8 &=
~ V_86 ;
continue;
}
if ( V_145 )
F_43 ( V_2 , V_47 , & V_108 ,
V_77 , true ) ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_82 ] . V_8 &= ~ V_86 ;
}
}
F_8 ( & V_2 -> V_4 ) ;
if ( ! V_144 )
F_6 ( V_2 , L_51
L_52 ) ;
else
F_6 ( V_2 , L_51
L_53 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
int V_82 ;
for ( V_82 = 0 ; V_82 < V_2 -> V_147 ; V_82 ++ )
if ( ! F_45 ( V_82 , & V_2 -> V_148 ) )
return V_82 ;
return V_149 ;
}
void F_46 ( struct V_1 * V_2 )
{
int V_82 ;
F_7 ( & V_2 -> V_4 ) ;
for ( V_82 = 0 ; V_82 < V_5 ; V_82 ++ ) {
if ( ! ( V_2 -> V_7 [ V_82 ] . V_8 & V_150 ) )
continue;
V_2 -> V_7 [ V_82 ] . V_8 &= ~ V_12 ;
V_2 -> V_87 -- ;
if ( F_33 ( V_2 -> V_87 < 0 ) )
V_2 -> V_87 = 0 ;
F_34 ( V_2 -> V_7 [ V_82 ] . V_108 ) ;
V_2 -> V_7 [ V_82 ] . V_108 = NULL ;
}
F_8 ( & V_2 -> V_4 ) ;
}
static void F_47 ( struct V_1 * V_2 ,
struct V_111 * V_108 )
{
int V_82 ;
F_48 ( V_2 , L_54 , V_108 -> V_3 ) ;
F_48 ( V_2 , L_55 ,
V_108 -> V_133 . V_134 ,
V_108 -> V_133 . V_135 ) ;
for ( V_82 = 0 ; V_82 < V_131 ; V_82 ++ )
F_48 ( V_2 , L_56 ,
V_82 , V_108 -> V_132 [ V_82 ] . V_115 ) ;
}
static inline void F_47 ( struct V_1 * V_2 ,
struct V_111 * V_108 )
{
}
static bool F_49 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_111 * V_108 )
{
int V_82 ;
if ( V_47 -> V_49 . V_50 )
return true ;
F_6 ( V_2 , L_57 ,
V_47 -> V_151 . V_152 ) ;
for ( V_82 = 0 ; V_82 < V_131 ; V_82 ++ ) {
if ( F_50 ( V_108 -> V_132 [ V_82 ] . V_115 ) &
V_153 ) {
F_6 ( V_2 ,
L_58 ,
V_82 ) ;
return false ;
}
}
return true ;
}
int F_43 ( struct V_1 * V_2 , struct V_46 * V_47 ,
struct V_111 * V_108 , T_1 V_23 , bool V_154 )
{
int V_20 = 0 ;
struct V_37 V_35 = {
. V_38 = V_155 ,
. V_40 = { sizeof( struct V_111 ) , } ,
. V_23 = V_23 ,
. V_19 = { V_108 , } ,
} ;
if ( F_33 ( V_108 -> V_3 == V_74 ) )
return - V_6 ;
F_7 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_108 -> V_3 ] . V_8 & V_9 ) ) {
F_8 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
F_8 ( & V_2 -> V_4 ) ;
F_47 ( V_2 , V_108 ) ;
if ( F_33 ( V_154 && ( V_35 . V_23 & V_42 ) ) )
return - V_6 ;
if ( F_49 ( V_2 , V_47 , V_108 ) )
V_20 = F_13 ( V_2 , & V_35 ) ;
else
V_20 = - V_6 ;
if ( V_35 . V_23 & V_42 )
return V_20 ;
if ( V_154 ) {
F_6 ( V_2 , L_59
L_60 ,
V_108 -> V_3 ) ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_108 -> V_3 ] . V_8 &= ~ V_86 ;
F_8 ( & V_2 -> V_4 ) ;
}
return V_20 ;
}
static struct V_111 *
F_51 ( struct V_1 * V_2 , struct V_46 * V_47 ,
T_1 V_3 )
{
struct V_111 * V_112 ;
V_112 = F_52 ( sizeof( struct V_111 ) , V_156 ) ;
if ( ! V_112 ) {
F_3 ( V_2 , L_61 ) ;
return NULL ;
}
F_36 ( V_2 , V_47 , V_3 , V_112 ) ;
return V_112 ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
const T_1 * V_11 , T_1 * V_93 )
{
int V_20 ;
T_1 V_3 ;
struct V_111 * V_112 ;
if ( V_93 )
* V_93 = V_74 ;
V_20 = F_28 ( V_2 , V_47 , V_11 , 0 , NULL , & V_3 ) ;
if ( V_20 ) {
F_3 ( V_2 , L_62 , V_11 ) ;
return V_20 ;
}
if ( V_93 )
* V_93 = V_3 ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_107 ;
F_8 ( & V_2 -> V_4 ) ;
V_112 = F_51 ( V_2 , V_47 , V_3 ) ;
if ( ! V_112 ) {
F_3 ( V_2 ,
L_63 ,
V_11 ) ;
return - V_157 ;
}
V_20 = F_43 ( V_2 , V_47 , V_112 , V_77 , true ) ;
if ( V_20 )
F_3 ( V_2 , L_64 , V_20 ) ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_108 = V_112 ;
F_8 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
bool V_158 )
{
int V_82 , V_159 = 0 ;
T_1 V_160 [ sizeof( struct V_161 ) +
sizeof( struct V_162 ) * V_163 ] ;
struct V_161 * V_164 = (struct V_161 * ) V_160 ;
T_3 V_165 = sizeof( struct V_161 ) ;
struct V_37 V_35 = {
. V_38 = V_47 -> V_166 ,
. V_19 = { V_164 , } ,
. V_23 = V_77 ,
} ;
F_12 () ;
memset ( V_164 , 0 , V_165 +
( sizeof( struct V_162 ) * V_163 ) ) ;
for ( V_82 = 0 ; V_82 < V_163 ; V_82 ++ ) {
V_164 -> V_167 [ V_82 ] . V_168 = V_82 ;
if ( V_47 -> V_169 [ V_82 ] . V_170 ) {
V_164 -> V_167 [ V_82 ] . V_171 = V_82 ;
V_159 = 1 ;
} else {
V_164 -> V_167 [ V_82 ] . V_171 = V_149 ;
}
V_164 -> V_167 [ V_82 ] . V_170 = V_47 -> V_169 [ V_82 ] . V_170 ;
memcpy ( & V_164 -> V_167 [ V_82 ] . V_167 [ 3 ] , V_47 -> V_169 [ V_82 ] . V_167 ,
V_47 -> V_169 [ V_82 ] . V_170 ) ;
}
V_164 -> V_172 = V_173 ;
V_164 -> V_174 = V_163 ;
V_165 += sizeof( struct V_162 ) * V_163 ;
V_35 . V_40 [ 0 ] = V_165 ;
if ( V_159 || V_158 )
return F_13 ( V_2 , & V_35 ) ;
else
return 0 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
F_2 ( & V_2 -> V_116 ) ;
return F_54 ( V_2 , V_47 , false ) ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_175 * V_176 )
{
int V_20 ;
F_2 ( & V_2 -> V_116 ) ;
F_57 ( V_2 , L_65 ,
V_176 -> V_177 ) ;
memset ( & V_47 -> V_169 [ V_176 -> V_177 ] , 0 , sizeof( V_47 -> V_169 [ 0 ] ) ) ;
if ( F_58 ( V_2 ) ) {
F_57 ( V_2 ,
L_66 ) ;
return 0 ;
}
V_20 = F_54 ( V_2 , V_47 , 1 ) ;
F_57 ( V_2 , L_67 ,
V_176 -> V_177 , V_20 ) ;
return V_20 ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_175 * V_176 )
{
int V_20 ;
F_2 ( & V_2 -> V_116 ) ;
if ( V_176 -> V_178 != V_179 &&
V_176 -> V_178 != V_180 ) {
F_57 ( V_2 ,
L_68 , V_176 -> V_178 ) ;
return - V_6 ;
}
V_176 -> V_181 = V_182 ;
V_47 -> V_169 [ V_176 -> V_177 ] . V_170 = V_176 -> V_178 ;
memcpy ( & V_47 -> V_169 [ V_176 -> V_177 ] . V_167 , & V_176 -> V_167 ,
V_176 -> V_178 ) ;
V_20 = F_54 ( V_2 , V_47 , false ) ;
F_57 ( V_2 , L_69 ,
V_176 -> V_178 , V_176 -> V_177 , V_20 ) ;
return V_20 ;
}
static T_1 F_60 ( struct V_1 * V_2 ,
struct V_183 * V_120 ,
struct V_48 * V_10 )
{
struct V_184 * V_185 = ( void * ) V_120 -> V_92 ;
if ( V_10 )
return F_21 ( V_10 ) ;
if ( V_120 -> type == V_186 && V_185 -> V_47 )
return V_185 -> V_47 -> V_83 ;
return V_74 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_175 * V_176 ,
T_1 V_3 , V_69 V_187 , T_4 * V_188 ,
V_69 V_189 )
{
T_5 V_190 ;
struct V_13 V_94 ;
int V_82 ;
F_7 ( & V_2 -> V_4 ) ;
memcpy ( & V_94 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_94 ) ) ;
F_8 ( & V_2 -> V_4 ) ;
V_190 = F_40 ( V_176 -> V_177 << V_191 ) ;
V_190 |= V_192 ;
switch ( V_176 -> V_193 ) {
case V_194 :
V_190 |= V_195 ;
memcpy ( V_94 . V_167 . V_167 , V_176 -> V_167 , V_176 -> V_178 ) ;
break;
case V_196 :
V_190 |= V_197 ;
V_94 . V_167 . V_198 = V_187 ;
for ( V_82 = 0 ; V_82 < 5 ; V_82 ++ )
V_94 . V_167 . V_199 [ V_82 ] = F_40 ( V_188 [ V_82 ] ) ;
memcpy ( V_94 . V_167 . V_167 , V_176 -> V_167 , V_176 -> V_178 ) ;
break;
case V_200 :
V_190 |= V_201 ;
case V_202 :
V_190 |= V_203 ;
memcpy ( & V_94 . V_167 . V_167 [ 3 ] , V_176 -> V_167 , V_176 -> V_178 ) ;
break;
default:
F_33 ( 1 ) ;
return - V_6 ;
}
if ( ! ( V_176 -> V_23 & V_204 ) )
V_190 |= V_205 ;
V_94 . V_167 . V_171 = V_176 -> V_181 ;
V_94 . V_167 . V_190 = V_190 ;
V_94 . V_30 = V_31 ;
V_94 . V_10 . V_206 = V_207 ;
return F_11 ( V_2 , & V_94 , V_189 ) ;
}
void F_62 ( struct V_1 * V_2 ,
struct V_183 * V_120 ,
struct V_175 * V_176 ,
struct V_48 * V_10 , V_69 V_208 , T_4 * V_209 )
{
T_1 V_3 = F_60 ( V_2 , V_120 , V_10 ) ;
if ( V_3 == V_74 )
return;
if ( F_63 ( V_2 ) ) {
return;
}
F_61 ( V_2 , V_176 , V_3 ,
V_208 , V_209 , V_42 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_175 * V_176 ,
struct V_48 * V_10 )
{
struct V_13 V_94 ;
T_1 V_3 = F_60 ( V_2 , V_47 -> V_120 , V_10 ) ;
T_5 V_190 ;
if ( V_3 == V_74 )
return - V_210 ;
F_7 ( & V_2 -> V_4 ) ;
memcpy ( & V_94 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_94 ) ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) )
V_3 = V_74 ;
F_8 ( & V_2 -> V_4 ) ;
if ( V_3 == V_74 )
return 0 ;
F_2 ( & V_2 -> V_116 ) ;
V_47 -> V_211 -- ;
F_57 ( V_2 , L_70 ,
V_176 -> V_177 , V_3 ) ;
if ( ! F_65 ( V_176 -> V_181 , & V_2 -> V_148 ) )
F_3 ( V_2 , L_71 ,
V_176 -> V_181 ) ;
V_190 = F_40 ( V_176 -> V_177 << V_191 ) ;
V_190 |= V_192 | V_212 |
V_213 ;
if ( ! ( V_176 -> V_23 & V_204 ) )
V_190 |= V_205 ;
V_94 . V_167 . V_190 = V_190 ;
V_94 . V_167 . V_171 = V_176 -> V_181 ;
V_94 . V_10 . V_206 = V_207 ;
V_94 . V_30 = V_31 ;
return F_11 ( V_2 , & V_94 , V_77 ) ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_46 * V_47 ,
struct V_175 * V_176 ,
struct V_48 * V_10 )
{
struct V_214 V_215 ;
T_4 V_216 [ 5 ] ;
int V_20 ;
T_1 V_3 = F_60 ( V_2 , V_47 -> V_120 , V_10 ) ;
const T_1 * V_11 ;
if ( V_3 == V_74 )
return - V_6 ;
F_2 ( & V_2 -> V_116 ) ;
V_176 -> V_181 = F_44 ( V_2 ) ;
if ( V_176 -> V_181 == V_149 )
return - V_217 ;
V_47 -> V_211 ++ ;
switch ( V_176 -> V_193 ) {
case V_196 :
if ( V_10 )
V_11 = V_10 -> V_11 ;
else
V_11 = V_47 -> V_151 . V_218 ;
F_67 ( V_176 , 0 , & V_215 ) ;
F_68 ( V_176 , V_11 , V_215 . V_219 . V_208 , V_216 ) ;
V_20 = F_61 ( V_2 , V_176 , V_3 ,
V_215 . V_219 . V_208 , V_216 , V_77 ) ;
break;
case V_194 :
case V_202 :
case V_200 :
V_20 = F_61 ( V_2 , V_176 , V_3 ,
0 , NULL , V_77 ) ;
break;
default:
F_3 ( V_2 , L_72 , V_176 -> V_193 ) ;
V_20 = - V_6 ;
}
if ( V_20 ) {
V_47 -> V_211 -- ;
F_69 ( V_176 -> V_181 , & V_2 -> V_148 ) ;
}
F_57 ( V_2 , L_73 ,
V_176 -> V_193 , V_176 -> V_178 , V_176 -> V_177 ,
V_10 ? V_10 -> V_11 : NULL , V_20 ) ;
return V_20 ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_111 * V_112 ;
T_1 V_3 ;
F_7 ( & V_2 -> V_4 ) ;
V_3 = F_24 ( V_2 , V_47 , V_220 , false , NULL ) ;
if ( V_3 == V_74 ) {
F_3 ( V_2 , L_74 ) ;
F_8 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_150 ;
F_8 ( & V_2 -> V_4 ) ;
V_112 = F_51 ( V_2 , V_47 , V_3 ) ;
if ( ! V_112 ) {
F_3 ( V_2 ,
L_75 ) ;
return - V_157 ;
}
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_108 = V_112 ;
F_8 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_71 ( struct V_1 * V_2 ,
struct V_46 * V_47 )
{
struct V_111 * V_112 ;
T_1 V_3 = V_47 -> V_84 ;
V_112 = F_51 ( V_2 , V_47 , V_3 ) ;
if ( ! V_112 ) {
F_3 ( V_2 , L_75 ) ;
return - V_157 ;
}
F_7 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_7 [ V_3 ] . V_108 )
F_34 ( V_2 -> V_7 [ V_3 ] . V_108 ) ;
else
F_6 ( V_2 , L_76 ) ;
V_2 -> V_7 [ V_3 ] . V_108 = V_112 ;
F_8 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_72 ( struct V_1 * V_2 )
{
struct V_46 * V_47 ;
int V_20 = 0 ;
F_73 (priv, ctx) {
V_20 = F_71 ( V_2 , V_47 ) ;
if ( V_20 )
break;
}
return V_20 ;
}
int F_74 ( struct V_1 * V_2 , int V_3 , int V_105 )
{
struct V_13 V_94 ;
F_2 ( & V_2 -> V_116 ) ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_206 = V_221 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_222 &= F_40 ( ~ ( 1 << V_105 ) ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_94 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_8 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_94 , V_77 ) ;
}
int F_75 ( struct V_1 * V_2 , struct V_48 * V_10 ,
int V_105 , T_4 V_223 )
{
int V_3 ;
struct V_13 V_94 ;
F_2 ( & V_2 -> V_116 ) ;
V_3 = F_21 ( V_10 ) ;
if ( V_3 == V_74 )
return - V_224 ;
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_76 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_206 = V_225 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_226 = ( T_1 ) V_105 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_227 = F_40 ( V_223 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_94 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_8 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_94 , V_77 ) ;
}
int F_76 ( struct V_1 * V_2 , struct V_48 * V_10 ,
int V_105 )
{
int V_3 ;
struct V_13 V_94 ;
F_2 ( & V_2 -> V_116 ) ;
V_3 = F_21 ( V_10 ) ;
if ( V_3 == V_74 ) {
F_3 ( V_2 , L_77 , V_105 ) ;
return - V_224 ;
}
F_7 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_76 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_206 = V_228 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_229 = ( T_1 ) V_105 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_94 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_8 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_94 , V_77 ) ;
}
void F_77 ( struct V_1 * V_2 , int V_3 , int V_230 )
{
struct V_13 V_35 = {
. V_30 = V_31 ,
. V_75 = V_231 ,
. V_76 = V_231 ,
. V_10 . V_3 = V_3 ,
. V_10 . V_206 = V_232 ,
. V_233 = F_40 ( V_230 ) ,
} ;
F_11 ( V_2 , & V_35 , V_42 ) ;
}
