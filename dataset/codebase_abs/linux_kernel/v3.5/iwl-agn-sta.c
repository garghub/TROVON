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
struct V_13 * V_14 =
(struct V_13 * ) V_35 -> V_36 ;
return F_5 ( V_2 , V_14 , V_16 ) ;
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
static bool F_15 ( struct V_1 * V_2 ,
enum V_46 V_47 ,
T_2 V_48 , T_1 V_49 )
{
const struct V_50 * V_51 ;
V_51 = F_16 ( V_2 , V_47 , V_48 ) ;
if ( ! F_17 ( V_51 ) )
return false ;
if ( V_49 == V_52 )
return ! ( V_51 -> V_53 &
V_54 ) ;
else if ( V_49 == V_55 )
return ! ( V_51 -> V_53 &
V_56 ) ;
return false ;
}
bool F_18 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_59 * V_60 )
{
if ( ! V_58 -> V_61 . V_62 || ! V_58 -> V_61 . V_63 )
return false ;
if ( V_60 && ! V_60 -> V_64 )
return false ;
#ifdef F_19
if ( V_2 -> V_65 )
return false ;
#endif
return F_15 ( V_2 , V_2 -> V_47 ,
F_20 ( V_58 -> V_66 . V_48 ) ,
V_58 -> V_61 . V_49 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_67 * V_10 ,
struct V_57 * V_58 ,
T_3 * V_23 , T_3 * V_68 )
{
struct V_59 * V_69 = & V_10 -> V_60 ;
T_1 V_70 ;
* V_68 = V_71 |
V_72 |
V_73 |
V_74 |
V_75 ;
* V_23 = 0 ;
if ( ! V_10 || ! V_69 -> V_64 )
return;
V_70 = ( V_69 -> V_76 & V_77 ) >> 2 ;
F_6 ( V_2 , L_23 ,
( V_70 == V_78 ) ?
L_24 :
( V_70 == V_79 ) ?
L_25 : L_26 ) ;
switch ( V_70 ) {
case V_78 :
* V_23 |= V_72 ;
break;
case V_79 :
* V_23 |= V_71 ;
break;
case V_80 :
break;
default:
F_22 ( V_2 , L_27 , V_70 ) ;
break;
}
* V_23 |= F_23 (
( V_81 ) V_69 -> V_82 << V_83 ) ;
* V_23 |= F_23 (
( V_81 ) V_69 -> V_84 << V_85 ) ;
if ( F_18 ( V_2 , V_58 , & V_10 -> V_60 ) )
* V_23 |= V_73 ;
}
int F_24 ( struct V_1 * V_2 , struct V_57 * V_58 ,
struct V_67 * V_10 )
{
T_1 V_3 = F_25 ( V_10 ) ;
T_3 V_23 , V_68 ;
struct V_13 V_35 ;
if ( F_26 ( V_3 == V_86 ) )
return - V_6 ;
F_21 ( V_2 , V_10 , V_58 , & V_23 , & V_68 ) ;
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_87 &= ~ V_68 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_87 |= V_23 ;
F_28 ( & V_2 -> V_4 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_30 = V_31 ;
V_35 . V_88 = V_68 ;
V_35 . V_87 = V_23 ;
V_35 . V_10 . V_3 = V_3 ;
return F_11 ( V_2 , & V_35 , V_89 ) ;
}
static void F_29 ( struct V_1 * V_2 , T_1 V_90 ,
struct V_67 * V_10 ,
struct V_57 * V_58 )
{
T_3 V_23 , V_68 ;
F_21 ( V_2 , V_10 , V_58 , & V_23 , & V_68 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_90 ] . V_10 . V_87 &= ~ V_68 ;
V_2 -> V_7 [ V_90 ] . V_10 . V_87 |= V_23 ;
}
T_1 F_30 ( struct V_1 * V_2 , struct V_57 * V_58 ,
const T_1 * V_11 , bool V_91 , struct V_67 * V_10 )
{
struct V_92 * V_93 ;
int V_94 ;
T_1 V_3 = V_86 ;
if ( V_91 )
V_3 = V_58 -> V_95 ;
else if ( F_31 ( V_11 ) )
V_3 = V_58 -> V_96 ;
else
for ( V_94 = V_97 ; V_94 < V_5 ; V_94 ++ ) {
if ( F_32 ( V_2 -> V_7 [ V_94 ] . V_10 . V_10 . V_11 ,
V_11 ) ) {
V_3 = V_94 ;
break;
}
if ( ! V_2 -> V_7 [ V_94 ] . V_8 &&
V_3 == V_86 )
V_3 = V_94 ;
}
if ( F_33 ( V_3 == V_86 ) )
return V_3 ;
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_98 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) &&
F_32 ( V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 , V_11 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
return V_3 ;
}
V_93 = & V_2 -> V_7 [ V_3 ] ;
V_93 -> V_8 = V_9 ;
F_4 ( V_2 , L_32 ,
V_3 , V_11 ) ;
V_2 -> V_99 ++ ;
memset ( & V_93 -> V_10 , 0 , sizeof( struct V_13 ) ) ;
memcpy ( V_93 -> V_10 . V_10 . V_11 , V_11 , V_100 ) ;
V_93 -> V_10 . V_30 = 0 ;
V_93 -> V_10 . V_10 . V_3 = V_3 ;
V_93 -> V_10 . V_87 = V_58 -> V_87 ;
V_93 -> V_101 = V_58 -> V_101 ;
if ( V_10 ) {
struct V_102 * V_103 ;
V_103 = ( void * ) V_10 -> V_104 ;
V_103 -> V_58 = V_58 ;
}
F_29 ( V_2 , V_3 , V_10 , V_58 ) ;
return V_3 ;
}
int F_34 ( struct V_1 * V_2 , struct V_57 * V_58 ,
const T_1 * V_11 , bool V_91 ,
struct V_67 * V_10 , T_1 * V_105 )
{
int V_20 = 0 ;
T_1 V_3 ;
struct V_13 V_106 ;
* V_105 = 0 ;
F_27 ( & V_2 -> V_4 ) ;
V_3 = F_30 ( V_2 , V_58 , V_11 , V_91 , V_10 ) ;
if ( V_3 == V_86 ) {
F_3 ( V_2 , L_33 ,
V_11 ) ;
F_28 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_98 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
F_28 ( & V_2 -> V_4 ) ;
return - V_107 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
F_28 ( & V_2 -> V_4 ) ;
return - V_107 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_98 ;
memcpy ( & V_106 , & V_2 -> V_7 [ V_3 ] . V_10 ,
sizeof( struct V_13 ) ) ;
F_28 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_106 , V_89 ) ;
if ( V_20 ) {
F_27 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_98 ;
F_28 ( & V_2 -> V_4 ) ;
}
* V_105 = V_3 ;
return V_20 ;
}
static void F_35 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
if ( ( V_2 -> V_7 [ V_3 ] . V_8 &
( V_12 | V_9 ) ) !=
V_12 )
F_3 ( V_2 , L_35 , V_3 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_12 ;
memset ( & V_2 -> V_7 [ V_3 ] , 0 , sizeof( struct V_92 ) ) ;
F_4 ( V_2 , L_36 , V_3 ) ;
}
static int F_36 ( struct V_1 * V_2 ,
const T_1 * V_11 , int V_3 ,
bool V_108 )
{
struct V_15 * V_16 ;
int V_20 ;
struct V_109 V_110 ;
struct V_37 V_35 = {
. V_38 = V_111 ,
. V_40 = { sizeof( struct V_109 ) , } ,
. V_23 = V_89 ,
. V_19 = { & V_110 , } ,
} ;
memset ( & V_110 , 0 , sizeof( V_110 ) ) ;
V_110 . V_112 = 1 ;
memcpy ( & V_110 . V_11 , V_11 , V_100 ) ;
V_35 . V_23 |= V_43 ;
V_20 = F_13 ( V_2 , & V_35 ) ;
if ( V_20 )
return V_20 ;
V_16 = V_35 . V_113 ;
if ( V_16 -> V_22 . V_23 & V_24 ) {
F_3 ( V_2 , L_37 ,
V_16 -> V_22 . V_23 ) ;
V_20 = - V_21 ;
}
if ( ! V_20 ) {
struct V_114 * V_115 = ( void * ) V_16 -> V_19 ;
switch ( V_115 -> V_25 ) {
case V_116 :
if ( ! V_108 ) {
F_27 ( & V_2 -> V_4 ) ;
F_35 ( V_2 , V_3 ) ;
F_28 ( & V_2 -> V_4 ) ;
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
int F_37 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_117 ;
if ( ! F_38 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return 0 ;
}
F_4 ( V_2 , L_41 ,
V_3 , V_11 ) ;
if ( F_39 ( V_3 == V_86 ) )
return - V_6 ;
F_27 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) {
F_6 ( V_2 , L_42 ,
V_11 ) ;
goto V_118;
}
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_6 ( V_2 , L_43 ,
V_11 ) ;
goto V_118;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_119 ) {
F_40 ( V_2 -> V_7 [ V_3 ] . V_120 ) ;
V_2 -> V_7 [ V_3 ] . V_120 = NULL ;
}
for ( V_117 = 0 ; V_117 < V_121 ; V_117 ++ )
memset ( & V_2 -> V_122 [ V_3 ] [ V_117 ] , 0 ,
sizeof( V_2 -> V_122 [ V_3 ] [ V_117 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_99 -- ;
if ( F_39 ( V_2 -> V_99 < 0 ) )
V_2 -> V_99 = 0 ;
F_28 ( & V_2 -> V_4 ) ;
return F_36 ( V_2 , V_11 , V_3 , false ) ;
V_118:
F_28 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
void F_41 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_117 ;
if ( ! F_38 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return;
}
F_4 ( V_2 , L_44 , V_11 , V_3 ) ;
if ( F_26 ( V_3 == V_86 ) )
return;
F_27 ( & V_2 -> V_4 ) ;
F_26 ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) ;
for ( V_117 = 0 ; V_117 < V_121 ; V_117 ++ )
memset ( & V_2 -> V_122 [ V_3 ] [ V_117 ] , 0 ,
sizeof( V_2 -> V_122 [ V_3 ] [ V_117 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_99 -- ;
if ( F_26 ( V_2 -> V_99 < 0 ) )
V_2 -> V_99 = 0 ;
F_28 ( & V_2 -> V_4 ) ;
}
static void F_42 ( struct V_1 * V_2 , struct V_57 * V_58 ,
T_1 V_3 , struct V_123 * V_124 )
{
int V_94 , V_125 ;
V_81 V_126 = 0 ;
T_3 V_127 ;
F_2 ( & V_2 -> V_128 ) ;
memset ( V_124 , 0 , sizeof( * V_124 ) ) ;
if ( V_2 -> V_47 == V_129 )
V_125 = V_130 ;
else if ( V_58 && V_58 -> V_131 && V_58 -> V_131 -> V_132 )
V_125 = V_130 ;
else
V_125 = V_133 ;
if ( V_125 >= V_134 && V_125 <= V_135 )
V_126 |= V_136 ;
V_126 |= F_43 ( V_2 -> V_137 . V_138 ) <<
V_139 ;
V_127 = F_44 ( V_140 [ V_125 ] . V_141 , V_126 ) ;
for ( V_94 = 0 ; V_94 < V_142 ; V_94 ++ )
V_124 -> V_143 [ V_94 ] . V_127 = V_127 ;
V_124 -> V_144 . V_145 =
F_43 ( V_2 -> V_137 . V_138 ) ;
V_124 -> V_144 . V_146 =
V_2 -> V_137 . V_138 &
~ F_43 ( V_2 -> V_137 . V_138 ) ;
if ( ! V_124 -> V_144 . V_146 ) {
V_124 -> V_144 . V_146 = V_147 ;
} else if ( F_45 ( V_2 -> V_137 . V_138 ) == 2 ) {
V_124 -> V_144 . V_146 =
V_2 -> V_137 . V_138 ;
}
V_124 -> V_148 . V_149 =
V_150 ;
V_124 -> V_148 . V_151 =
F_46 ( V_152 ) ;
V_124 -> V_3 = V_3 ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
int V_94 ;
bool V_153 = false ;
F_6 ( V_2 , L_45 ) ;
F_27 ( & V_2 -> V_4 ) ;
for ( V_94 = 0 ; V_94 < V_5 ; V_94 ++ ) {
if ( V_58 && V_58 -> V_101 != V_2 -> V_7 [ V_94 ] . V_101 )
continue;
if ( V_2 -> V_7 [ V_94 ] . V_8 & V_12 ) {
F_6 ( V_2 ,
L_46 , V_94 ) ;
V_2 -> V_7 [ V_94 ] . V_8 &= ~ V_12 ;
V_153 = true ;
}
}
F_28 ( & V_2 -> V_4 ) ;
if ( ! V_153 )
F_6 ( V_2 ,
L_47 ) ;
}
void F_48 ( struct V_1 * V_2 , struct V_57 * V_58 )
{
struct V_13 V_106 ;
struct V_123 V_120 ;
int V_94 ;
bool V_154 = false ;
int V_20 ;
bool V_155 ;
if ( ! F_38 ( V_2 ) ) {
F_6 ( V_2 ,
L_48 ) ;
return;
}
F_4 ( V_2 , L_49 ) ;
F_27 ( & V_2 -> V_4 ) ;
for ( V_94 = 0 ; V_94 < V_5 ; V_94 ++ ) {
if ( V_58 -> V_101 != V_2 -> V_7 [ V_94 ] . V_101 )
continue;
if ( ( V_2 -> V_7 [ V_94 ] . V_8 & V_9 ) &&
! ( V_2 -> V_7 [ V_94 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_50 ,
V_2 -> V_7 [ V_94 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_94 ] . V_10 . V_30 = 0 ;
V_2 -> V_7 [ V_94 ] . V_8 |= V_98 ;
V_154 = true ;
}
}
for ( V_94 = 0 ; V_94 < V_5 ; V_94 ++ ) {
if ( ( V_2 -> V_7 [ V_94 ] . V_8 & V_98 ) ) {
memcpy ( & V_106 , & V_2 -> V_7 [ V_94 ] . V_10 ,
sizeof( struct V_13 ) ) ;
V_155 = false ;
if ( V_2 -> V_7 [ V_94 ] . V_120 ) {
if ( V_2 -> V_156 )
F_42 ( V_2 , V_58 , V_94 , & V_120 ) ;
else
memcpy ( & V_120 , V_2 -> V_7 [ V_94 ] . V_120 ,
sizeof( struct V_123 ) ) ;
V_155 = true ;
}
F_28 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_106 , V_89 ) ;
if ( V_20 ) {
F_27 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_94 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_94 ] . V_8 &=
~ V_9 ;
V_2 -> V_7 [ V_94 ] . V_8 &=
~ V_98 ;
continue;
}
if ( V_155 )
F_49 ( V_2 , V_58 , & V_120 ,
V_89 , true ) ;
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_94 ] . V_8 &= ~ V_98 ;
}
}
F_28 ( & V_2 -> V_4 ) ;
if ( ! V_154 )
F_6 ( V_2 , L_51
L_52 ) ;
else
F_6 ( V_2 , L_51
L_53 ) ;
}
int F_50 ( struct V_1 * V_2 )
{
int V_94 ;
for ( V_94 = 0 ; V_94 < V_2 -> V_157 ; V_94 ++ )
if ( ! F_51 ( V_94 , & V_2 -> V_158 ) )
return V_94 ;
return V_159 ;
}
void F_52 ( struct V_1 * V_2 )
{
int V_94 ;
F_27 ( & V_2 -> V_4 ) ;
for ( V_94 = 0 ; V_94 < V_5 ; V_94 ++ ) {
if ( ! ( V_2 -> V_7 [ V_94 ] . V_8 & V_160 ) )
continue;
V_2 -> V_7 [ V_94 ] . V_8 &= ~ V_12 ;
V_2 -> V_99 -- ;
if ( F_39 ( V_2 -> V_99 < 0 ) )
V_2 -> V_99 = 0 ;
F_40 ( V_2 -> V_7 [ V_94 ] . V_120 ) ;
V_2 -> V_7 [ V_94 ] . V_120 = NULL ;
}
F_28 ( & V_2 -> V_4 ) ;
}
static void F_53 ( struct V_1 * V_2 ,
struct V_123 * V_120 )
{
int V_94 ;
F_54 ( V_2 , L_54 , V_120 -> V_3 ) ;
F_54 ( V_2 , L_55 ,
V_120 -> V_144 . V_145 ,
V_120 -> V_144 . V_146 ) ;
for ( V_94 = 0 ; V_94 < V_142 ; V_94 ++ )
F_54 ( V_2 , L_56 ,
V_94 , V_120 -> V_143 [ V_94 ] . V_127 ) ;
}
static inline void F_53 ( struct V_1 * V_2 ,
struct V_123 * V_120 )
{
}
static bool F_55 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_123 * V_120 )
{
int V_94 ;
if ( V_58 -> V_61 . V_62 )
return true ;
F_6 ( V_2 , L_57 ,
V_58 -> V_161 . V_48 ) ;
for ( V_94 = 0 ; V_94 < V_142 ; V_94 ++ ) {
if ( F_56 ( V_120 -> V_143 [ V_94 ] . V_127 ) &
V_162 ) {
F_6 ( V_2 ,
L_58 ,
V_94 ) ;
return false ;
}
}
return true ;
}
int F_49 ( struct V_1 * V_2 , struct V_57 * V_58 ,
struct V_123 * V_120 , T_1 V_23 , bool V_163 )
{
int V_20 = 0 ;
struct V_37 V_35 = {
. V_38 = V_164 ,
. V_40 = { sizeof( struct V_123 ) , } ,
. V_23 = V_23 ,
. V_19 = { V_120 , } ,
} ;
if ( F_39 ( V_120 -> V_3 == V_86 ) )
return - V_6 ;
F_27 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_120 -> V_3 ] . V_8 & V_9 ) ) {
F_28 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
F_28 ( & V_2 -> V_4 ) ;
F_53 ( V_2 , V_120 ) ;
if ( F_39 ( V_163 && ( V_35 . V_23 & V_42 ) ) )
return - V_6 ;
if ( F_55 ( V_2 , V_58 , V_120 ) )
V_20 = F_13 ( V_2 , & V_35 ) ;
else
V_20 = - V_6 ;
if ( V_35 . V_23 & V_42 )
return V_20 ;
if ( V_163 ) {
F_6 ( V_2 , L_59
L_60 ,
V_120 -> V_3 ) ;
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_120 -> V_3 ] . V_8 &= ~ V_98 ;
F_28 ( & V_2 -> V_4 ) ;
}
return V_20 ;
}
static struct V_123 *
F_57 ( struct V_1 * V_2 , struct V_57 * V_58 ,
T_1 V_3 )
{
struct V_123 * V_124 ;
V_124 = F_58 ( sizeof( struct V_123 ) , V_165 ) ;
if ( ! V_124 ) {
F_3 ( V_2 , L_61 ) ;
return NULL ;
}
F_42 ( V_2 , V_58 , V_3 , V_124 ) ;
return V_124 ;
}
int F_59 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
const T_1 * V_11 , T_1 * V_105 )
{
int V_20 ;
T_1 V_3 ;
struct V_123 * V_124 ;
if ( V_105 )
* V_105 = V_86 ;
V_20 = F_34 ( V_2 , V_58 , V_11 , 0 , NULL , & V_3 ) ;
if ( V_20 ) {
F_3 ( V_2 , L_62 , V_11 ) ;
return V_20 ;
}
if ( V_105 )
* V_105 = V_3 ;
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_119 ;
F_28 ( & V_2 -> V_4 ) ;
V_124 = F_57 ( V_2 , V_58 , V_3 ) ;
if ( ! V_124 ) {
F_3 ( V_2 ,
L_63 ,
V_11 ) ;
return - V_166 ;
}
V_20 = F_49 ( V_2 , V_58 , V_124 , V_89 , true ) ;
if ( V_20 )
F_3 ( V_2 , L_64 , V_20 ) ;
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_120 = V_124 ;
F_28 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
bool V_167 )
{
int V_94 , V_168 = 0 ;
T_1 V_169 [ sizeof( struct V_170 ) +
sizeof( struct V_171 ) * V_172 ] ;
struct V_170 * V_173 = (struct V_170 * ) V_169 ;
T_4 V_174 = sizeof( struct V_170 ) ;
struct V_37 V_35 = {
. V_38 = V_58 -> V_175 ,
. V_19 = { V_173 , } ,
. V_23 = V_89 ,
} ;
F_12 () ;
memset ( V_173 , 0 , V_174 +
( sizeof( struct V_171 ) * V_172 ) ) ;
for ( V_94 = 0 ; V_94 < V_172 ; V_94 ++ ) {
V_173 -> V_176 [ V_94 ] . V_177 = V_94 ;
if ( V_58 -> V_178 [ V_94 ] . V_179 ) {
V_173 -> V_176 [ V_94 ] . V_180 = V_94 ;
V_168 = 1 ;
} else {
V_173 -> V_176 [ V_94 ] . V_180 = V_159 ;
}
V_173 -> V_176 [ V_94 ] . V_179 = V_58 -> V_178 [ V_94 ] . V_179 ;
memcpy ( & V_173 -> V_176 [ V_94 ] . V_176 [ 3 ] , V_58 -> V_178 [ V_94 ] . V_176 ,
V_58 -> V_178 [ V_94 ] . V_179 ) ;
}
V_173 -> V_181 = V_182 ;
V_173 -> V_183 = V_172 ;
V_174 += sizeof( struct V_171 ) * V_172 ;
V_35 . V_40 [ 0 ] = V_174 ;
if ( V_168 || V_167 )
return F_13 ( V_2 , & V_35 ) ;
else
return 0 ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
F_2 ( & V_2 -> V_128 ) ;
return F_60 ( V_2 , V_58 , false ) ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_184 * V_185 )
{
int V_20 ;
F_2 ( & V_2 -> V_128 ) ;
F_63 ( V_2 , L_65 ,
V_185 -> V_186 ) ;
memset ( & V_58 -> V_178 [ V_185 -> V_186 ] , 0 , sizeof( V_58 -> V_178 [ 0 ] ) ) ;
if ( F_64 ( V_2 ) ) {
F_63 ( V_2 ,
L_66 ) ;
return 0 ;
}
V_20 = F_60 ( V_2 , V_58 , 1 ) ;
F_63 ( V_2 , L_67 ,
V_185 -> V_186 , V_20 ) ;
return V_20 ;
}
int F_65 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_184 * V_185 )
{
int V_20 ;
F_2 ( & V_2 -> V_128 ) ;
if ( V_185 -> V_187 != V_188 &&
V_185 -> V_187 != V_189 ) {
F_63 ( V_2 ,
L_68 , V_185 -> V_187 ) ;
return - V_6 ;
}
V_185 -> V_190 = V_191 ;
V_58 -> V_178 [ V_185 -> V_186 ] . V_179 = V_185 -> V_187 ;
memcpy ( & V_58 -> V_178 [ V_185 -> V_186 ] . V_176 , & V_185 -> V_176 ,
V_185 -> V_187 ) ;
V_20 = F_60 ( V_2 , V_58 , false ) ;
F_63 ( V_2 , L_69 ,
V_185 -> V_187 , V_185 -> V_186 , V_20 ) ;
return V_20 ;
}
static T_1 F_66 ( struct V_1 * V_2 ,
struct V_192 * V_131 ,
struct V_67 * V_10 )
{
struct V_193 * V_194 = ( void * ) V_131 -> V_104 ;
if ( V_10 )
return F_25 ( V_10 ) ;
if ( V_131 -> type == V_195 && V_194 -> V_58 )
return V_194 -> V_58 -> V_95 ;
return V_86 ;
}
static int F_67 ( struct V_1 * V_2 ,
struct V_184 * V_185 ,
T_1 V_3 , V_81 V_196 , T_2 * V_197 ,
V_81 V_198 )
{
T_5 V_199 ;
struct V_13 V_106 ;
int V_94 ;
F_27 ( & V_2 -> V_4 ) ;
memcpy ( & V_106 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_106 ) ) ;
F_28 ( & V_2 -> V_4 ) ;
V_199 = F_46 ( V_185 -> V_186 << V_200 ) ;
V_199 |= V_201 ;
switch ( V_185 -> V_202 ) {
case V_203 :
V_199 |= V_204 ;
memcpy ( V_106 . V_176 . V_176 , V_185 -> V_176 , V_185 -> V_187 ) ;
break;
case V_205 :
V_199 |= V_206 ;
V_106 . V_176 . V_207 = V_196 ;
for ( V_94 = 0 ; V_94 < 5 ; V_94 ++ )
V_106 . V_176 . V_208 [ V_94 ] = F_46 ( V_197 [ V_94 ] ) ;
memcpy ( V_106 . V_176 . V_176 , V_185 -> V_176 , V_185 -> V_187 ) ;
break;
case V_209 :
V_199 |= V_210 ;
case V_211 :
V_199 |= V_212 ;
memcpy ( & V_106 . V_176 . V_176 [ 3 ] , V_185 -> V_176 , V_185 -> V_187 ) ;
break;
default:
F_39 ( 1 ) ;
return - V_6 ;
}
if ( ! ( V_185 -> V_23 & V_213 ) )
V_199 |= V_214 ;
V_106 . V_176 . V_180 = V_185 -> V_190 ;
V_106 . V_176 . V_199 = V_199 ;
V_106 . V_30 = V_31 ;
V_106 . V_10 . V_215 = V_216 ;
return F_11 ( V_2 , & V_106 , V_198 ) ;
}
void F_68 ( struct V_1 * V_2 ,
struct V_192 * V_131 ,
struct V_184 * V_185 ,
struct V_67 * V_10 , V_81 V_217 , T_2 * V_218 )
{
T_1 V_3 = F_66 ( V_2 , V_131 , V_10 ) ;
if ( V_3 == V_86 )
return;
if ( F_69 ( V_2 ) ) {
return;
}
F_67 ( V_2 , V_185 , V_3 ,
V_217 , V_218 , V_42 ) ;
}
int F_70 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_184 * V_185 ,
struct V_67 * V_10 )
{
struct V_13 V_106 ;
T_1 V_3 = F_66 ( V_2 , V_58 -> V_131 , V_10 ) ;
T_5 V_199 ;
if ( V_3 == V_86 )
return - V_219 ;
F_27 ( & V_2 -> V_4 ) ;
memcpy ( & V_106 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_106 ) ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) )
V_3 = V_86 ;
F_28 ( & V_2 -> V_4 ) ;
if ( V_3 == V_86 )
return 0 ;
F_2 ( & V_2 -> V_128 ) ;
V_58 -> V_220 -- ;
F_63 ( V_2 , L_70 ,
V_185 -> V_186 , V_3 ) ;
if ( ! F_71 ( V_185 -> V_190 , & V_2 -> V_158 ) )
F_3 ( V_2 , L_71 ,
V_185 -> V_190 ) ;
V_199 = F_46 ( V_185 -> V_186 << V_200 ) ;
V_199 |= V_201 | V_221 |
V_222 ;
if ( ! ( V_185 -> V_23 & V_213 ) )
V_199 |= V_214 ;
V_106 . V_176 . V_199 = V_199 ;
V_106 . V_176 . V_180 = V_185 -> V_190 ;
V_106 . V_10 . V_215 = V_216 ;
V_106 . V_30 = V_31 ;
return F_11 ( V_2 , & V_106 , V_89 ) ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_57 * V_58 ,
struct V_184 * V_185 ,
struct V_67 * V_10 )
{
struct V_223 V_224 ;
T_2 V_225 [ 5 ] ;
int V_20 ;
T_1 V_3 = F_66 ( V_2 , V_58 -> V_131 , V_10 ) ;
const T_1 * V_11 ;
if ( V_3 == V_86 )
return - V_6 ;
F_2 ( & V_2 -> V_128 ) ;
V_185 -> V_190 = F_50 ( V_2 ) ;
if ( V_185 -> V_190 == V_159 )
return - V_226 ;
V_58 -> V_220 ++ ;
switch ( V_185 -> V_202 ) {
case V_205 :
if ( V_10 )
V_11 = V_10 -> V_11 ;
else
V_11 = V_58 -> V_161 . V_227 ;
F_73 ( V_185 , 0 , & V_224 ) ;
F_74 ( V_185 , V_11 , V_224 . V_228 . V_217 , V_225 ) ;
V_20 = F_67 ( V_2 , V_185 , V_3 ,
V_224 . V_228 . V_217 , V_225 , V_89 ) ;
break;
case V_203 :
case V_211 :
case V_209 :
V_20 = F_67 ( V_2 , V_185 , V_3 ,
0 , NULL , V_89 ) ;
break;
default:
F_3 ( V_2 , L_72 , V_185 -> V_202 ) ;
V_20 = - V_6 ;
}
if ( V_20 ) {
V_58 -> V_220 -- ;
F_75 ( V_185 -> V_190 , & V_2 -> V_158 ) ;
}
F_63 ( V_2 , L_73 ,
V_185 -> V_202 , V_185 -> V_187 , V_185 -> V_186 ,
V_10 ? V_10 -> V_11 : NULL , V_20 ) ;
return V_20 ;
}
int F_76 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_123 * V_124 ;
T_1 V_3 ;
F_27 ( & V_2 -> V_4 ) ;
V_3 = F_30 ( V_2 , V_58 , V_229 , false , NULL ) ;
if ( V_3 == V_86 ) {
F_3 ( V_2 , L_74 ) ;
F_28 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_160 ;
F_28 ( & V_2 -> V_4 ) ;
V_124 = F_57 ( V_2 , V_58 , V_3 ) ;
if ( ! V_124 ) {
F_3 ( V_2 ,
L_75 ) ;
return - V_166 ;
}
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_120 = V_124 ;
F_28 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_77 ( struct V_1 * V_2 ,
struct V_57 * V_58 )
{
struct V_123 * V_124 ;
T_1 V_3 = V_58 -> V_96 ;
V_124 = F_57 ( V_2 , V_58 , V_3 ) ;
if ( ! V_124 ) {
F_3 ( V_2 , L_75 ) ;
return - V_166 ;
}
F_27 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_7 [ V_3 ] . V_120 )
F_40 ( V_2 -> V_7 [ V_3 ] . V_120 ) ;
else
F_6 ( V_2 , L_76 ) ;
V_2 -> V_7 [ V_3 ] . V_120 = V_124 ;
F_28 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_78 ( struct V_1 * V_2 )
{
struct V_57 * V_58 ;
int V_20 = 0 ;
F_79 (priv, ctx) {
V_20 = F_77 ( V_2 , V_58 ) ;
if ( V_20 )
break;
}
return V_20 ;
}
int F_80 ( struct V_1 * V_2 , int V_3 , int V_117 )
{
struct V_13 V_106 ;
F_2 ( & V_2 -> V_128 ) ;
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_215 = V_230 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_231 &= F_46 ( ~ ( 1 << V_117 ) ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_106 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_28 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_106 , V_89 ) ;
}
int F_81 ( struct V_1 * V_2 , struct V_67 * V_10 ,
int V_117 , T_2 V_232 )
{
int V_3 ;
struct V_13 V_106 ;
F_2 ( & V_2 -> V_128 ) ;
V_3 = F_25 ( V_10 ) ;
if ( V_3 == V_86 )
return - V_233 ;
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_88 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_215 = V_234 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_235 = ( T_1 ) V_117 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_236 = F_46 ( V_232 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_106 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_28 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_106 , V_89 ) ;
}
int F_82 ( struct V_1 * V_2 , struct V_67 * V_10 ,
int V_117 )
{
int V_3 ;
struct V_13 V_106 ;
F_2 ( & V_2 -> V_128 ) ;
V_3 = F_25 ( V_10 ) ;
if ( V_3 == V_86 ) {
F_3 ( V_2 , L_77 , V_117 ) ;
return - V_233 ;
}
F_27 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_88 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_215 = V_237 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_238 = ( T_1 ) V_117 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_106 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_28 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_106 , V_89 ) ;
}
void F_83 ( struct V_1 * V_2 , int V_3 , int V_239 )
{
struct V_13 V_35 = {
. V_30 = V_31 ,
. V_87 = V_240 ,
. V_88 = V_240 ,
. V_10 . V_3 = V_3 ,
. V_10 . V_215 = V_241 ,
. V_242 = F_46 ( V_239 ) ,
} ;
F_11 ( V_2 , & V_35 , V_42 ) ;
}
