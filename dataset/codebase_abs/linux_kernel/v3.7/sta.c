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
V_35 . V_23 |= V_43 | V_44 ;
F_12 () ;
}
V_20 = F_13 ( V_2 , & V_35 ) ;
if ( V_20 || ( V_23 & V_42 ) )
return V_20 ;
F_14 ( & V_35 ) ;
if ( V_35 . V_45 )
F_3 ( V_2 , L_22 , V_46 ,
V_35 . V_45 ) ;
return V_35 . V_45 ;
}
bool F_15 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_49 * V_50 )
{
if ( ! V_48 -> V_51 . V_52 || ! V_48 -> V_51 . V_53 )
return false ;
#ifdef F_16
if ( V_2 -> V_54 )
return false ;
#endif
if ( ! V_50 )
return true ;
if ( ! V_50 -> V_55 )
return false ;
if ( ! ( V_50 -> V_56 & V_57 ) )
return false ;
return true ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_58 * V_10 ,
struct V_47 * V_48 ,
T_2 * V_23 , T_2 * V_59 )
{
struct V_49 * V_60 = & V_10 -> V_50 ;
T_1 V_61 ;
* V_59 = V_62 |
V_63 |
V_64 |
V_65 |
V_66 ;
* V_23 = 0 ;
if ( ! V_10 || ! V_60 -> V_55 )
return;
V_61 = ( V_60 -> V_56 & V_67 ) >> 2 ;
F_6 ( V_2 , L_23 ,
V_10 -> V_11 ,
( V_61 == V_68 ) ?
L_24 :
( V_61 == V_69 ) ?
L_25 : L_26 ) ;
switch ( V_61 ) {
case V_68 :
* V_23 |= V_63 ;
break;
case V_69 :
* V_23 |= V_62 ;
break;
case V_70 :
break;
default:
F_18 ( V_2 , L_27 , V_61 ) ;
break;
}
* V_23 |= F_19 (
( V_71 ) V_60 -> V_72 << V_73 ) ;
* V_23 |= F_19 (
( V_71 ) V_60 -> V_74 << V_75 ) ;
if ( F_15 ( V_2 , V_48 , & V_10 -> V_50 ) )
* V_23 |= V_64 ;
}
int F_20 ( struct V_1 * V_2 , struct V_47 * V_48 ,
struct V_58 * V_10 )
{
T_1 V_3 = F_21 ( V_10 ) ;
T_2 V_23 , V_59 ;
struct V_13 V_35 ;
if ( F_22 ( V_3 == V_76 ) )
return - V_6 ;
F_17 ( V_2 , V_10 , V_48 , & V_23 , & V_59 ) ;
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_77 &= ~ V_59 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_77 |= V_23 ;
F_24 ( & V_2 -> V_4 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_30 = V_31 ;
V_35 . V_78 = V_59 ;
V_35 . V_77 = V_23 ;
V_35 . V_10 . V_3 = V_3 ;
return F_11 ( V_2 , & V_35 , V_79 ) ;
}
static void F_25 ( struct V_1 * V_2 , T_1 V_80 ,
struct V_58 * V_10 ,
struct V_47 * V_48 )
{
T_2 V_23 , V_59 ;
F_17 ( V_2 , V_10 , V_48 , & V_23 , & V_59 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_80 ] . V_10 . V_77 &= ~ V_59 ;
V_2 -> V_7 [ V_80 ] . V_10 . V_77 |= V_23 ;
}
T_1 F_26 ( struct V_1 * V_2 , struct V_47 * V_48 ,
const T_1 * V_11 , bool V_81 , struct V_58 * V_10 )
{
struct V_82 * V_83 ;
int V_84 ;
T_1 V_3 = V_76 ;
if ( V_81 )
V_3 = V_48 -> V_85 ;
else if ( F_27 ( V_11 ) )
V_3 = V_48 -> V_86 ;
else
for ( V_84 = V_87 ; V_84 < V_5 ; V_84 ++ ) {
if ( F_28 ( V_2 -> V_7 [ V_84 ] . V_10 . V_10 . V_11 ,
V_11 ) ) {
V_3 = V_84 ;
break;
}
if ( ! V_2 -> V_7 [ V_84 ] . V_8 &&
V_3 == V_76 )
V_3 = V_84 ;
}
if ( F_29 ( V_3 == V_76 ) )
return V_3 ;
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_88 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) &&
F_28 ( V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 , V_11 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
return V_3 ;
}
V_83 = & V_2 -> V_7 [ V_3 ] ;
V_83 -> V_8 = V_9 ;
F_4 ( V_2 , L_32 ,
V_3 , V_11 ) ;
V_2 -> V_89 ++ ;
memset ( & V_83 -> V_10 , 0 , sizeof( struct V_13 ) ) ;
memcpy ( V_83 -> V_10 . V_10 . V_11 , V_11 , V_90 ) ;
V_83 -> V_10 . V_30 = 0 ;
V_83 -> V_10 . V_10 . V_3 = V_3 ;
V_83 -> V_10 . V_77 = V_48 -> V_77 ;
V_83 -> V_91 = V_48 -> V_91 ;
if ( V_10 ) {
struct V_92 * V_93 ;
V_93 = ( void * ) V_10 -> V_94 ;
V_93 -> V_48 = V_48 ;
}
F_25 ( V_2 , V_3 , V_10 , V_48 ) ;
return V_3 ;
}
int F_30 ( struct V_1 * V_2 , struct V_47 * V_48 ,
const T_1 * V_11 , bool V_81 ,
struct V_58 * V_10 , T_1 * V_95 )
{
int V_20 = 0 ;
T_1 V_3 ;
struct V_13 V_96 ;
* V_95 = 0 ;
F_23 ( & V_2 -> V_4 ) ;
V_3 = F_26 ( V_2 , V_48 , V_11 , V_81 , V_10 ) ;
if ( V_3 == V_76 ) {
F_3 ( V_2 , L_33 ,
V_11 ) ;
F_24 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_88 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
F_24 ( & V_2 -> V_4 ) ;
return - V_97 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
F_24 ( & V_2 -> V_4 ) ;
return - V_97 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_88 ;
memcpy ( & V_96 , & V_2 -> V_7 [ V_3 ] . V_10 ,
sizeof( struct V_13 ) ) ;
F_24 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_96 , V_79 ) ;
if ( V_20 ) {
F_23 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_88 ;
F_24 ( & V_2 -> V_4 ) ;
}
* V_95 = V_3 ;
return V_20 ;
}
static void F_31 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
if ( ( V_2 -> V_7 [ V_3 ] . V_8 &
( V_12 | V_9 ) ) !=
V_12 )
F_3 ( V_2 , L_35 , V_3 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_12 ;
memset ( & V_2 -> V_7 [ V_3 ] , 0 , sizeof( struct V_82 ) ) ;
F_4 ( V_2 , L_36 , V_3 ) ;
}
static int F_32 ( struct V_1 * V_2 ,
const T_1 * V_11 , int V_3 ,
bool V_98 )
{
struct V_15 * V_16 ;
int V_20 ;
struct V_99 V_100 ;
struct V_37 V_35 = {
. V_38 = V_101 ,
. V_40 = { sizeof( struct V_99 ) , } ,
. V_23 = V_79 ,
. V_19 = { & V_100 , } ,
} ;
memset ( & V_100 , 0 , sizeof( V_100 ) ) ;
V_100 . V_102 = 1 ;
memcpy ( & V_100 . V_11 , V_11 , V_90 ) ;
V_35 . V_23 |= V_43 ;
V_20 = F_13 ( V_2 , & V_35 ) ;
if ( V_20 )
return V_20 ;
V_16 = V_35 . V_103 ;
if ( V_16 -> V_22 . V_23 & V_24 ) {
F_3 ( V_2 , L_37 ,
V_16 -> V_22 . V_23 ) ;
V_20 = - V_21 ;
}
if ( ! V_20 ) {
struct V_104 * V_105 = ( void * ) V_16 -> V_19 ;
switch ( V_105 -> V_25 ) {
case V_106 :
if ( ! V_98 ) {
F_23 ( & V_2 -> V_4 ) ;
F_31 ( V_2 , V_3 ) ;
F_24 ( & V_2 -> V_4 ) ;
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
int F_33 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_107 ;
if ( ! F_34 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return 0 ;
}
F_4 ( V_2 , L_41 ,
V_3 , V_11 ) ;
if ( F_35 ( V_3 == V_76 ) )
return - V_6 ;
F_23 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) {
F_6 ( V_2 , L_42 ,
V_11 ) ;
goto V_108;
}
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_6 ( V_2 , L_43 ,
V_11 ) ;
goto V_108;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_109 ) {
F_36 ( V_2 -> V_7 [ V_3 ] . V_110 ) ;
V_2 -> V_7 [ V_3 ] . V_110 = NULL ;
}
for ( V_107 = 0 ; V_107 < V_111 ; V_107 ++ )
memset ( & V_2 -> V_112 [ V_3 ] [ V_107 ] , 0 ,
sizeof( V_2 -> V_112 [ V_3 ] [ V_107 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_89 -- ;
if ( F_35 ( V_2 -> V_89 < 0 ) )
V_2 -> V_89 = 0 ;
F_24 ( & V_2 -> V_4 ) ;
return F_32 ( V_2 , V_11 , V_3 , false ) ;
V_108:
F_24 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
void F_37 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_107 ;
if ( ! F_34 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return;
}
F_4 ( V_2 , L_44 , V_11 , V_3 ) ;
if ( F_22 ( V_3 == V_76 ) )
return;
F_23 ( & V_2 -> V_4 ) ;
F_22 ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) ;
for ( V_107 = 0 ; V_107 < V_111 ; V_107 ++ )
memset ( & V_2 -> V_112 [ V_3 ] [ V_107 ] , 0 ,
sizeof( V_2 -> V_112 [ V_3 ] [ V_107 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_89 -- ;
if ( F_22 ( V_2 -> V_89 < 0 ) )
V_2 -> V_89 = 0 ;
F_24 ( & V_2 -> V_4 ) ;
}
static void F_38 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 , struct V_113 * V_114 )
{
int V_84 , V_115 ;
V_71 V_116 = 0 ;
T_2 V_117 ;
F_2 ( & V_2 -> V_118 ) ;
memset ( V_114 , 0 , sizeof( * V_114 ) ) ;
if ( V_2 -> V_119 == V_120 )
V_115 = V_121 ;
else if ( V_48 && V_48 -> V_122 && V_48 -> V_122 -> V_123 )
V_115 = V_121 ;
else
V_115 = V_124 ;
if ( V_115 >= V_125 && V_115 <= V_126 )
V_116 |= V_127 ;
V_116 |= F_39 ( V_2 -> V_128 -> V_129 ) <<
V_130 ;
V_117 = F_40 ( V_131 [ V_115 ] . V_132 , V_116 ) ;
for ( V_84 = 0 ; V_84 < V_133 ; V_84 ++ )
V_114 -> V_134 [ V_84 ] . V_117 = V_117 ;
V_114 -> V_135 . V_136 =
F_39 ( V_2 -> V_128 -> V_129 ) ;
V_114 -> V_135 . V_137 =
V_2 -> V_128 -> V_129 &
~ F_39 ( V_2 -> V_128 -> V_129 ) ;
if ( ! V_114 -> V_135 . V_137 ) {
V_114 -> V_135 . V_137 = V_138 ;
} else if ( F_41 ( V_2 -> V_128 -> V_129 ) == 2 ) {
V_114 -> V_135 . V_137 =
V_2 -> V_128 -> V_129 ;
}
V_114 -> V_139 . V_140 =
V_141 ;
V_114 -> V_139 . V_142 =
F_42 ( V_143 ) ;
V_114 -> V_3 = V_3 ;
}
void F_43 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
int V_84 ;
bool V_144 = false ;
F_6 ( V_2 , L_45 ) ;
F_23 ( & V_2 -> V_4 ) ;
for ( V_84 = 0 ; V_84 < V_5 ; V_84 ++ ) {
if ( V_48 && V_48 -> V_91 != V_2 -> V_7 [ V_84 ] . V_91 )
continue;
if ( V_2 -> V_7 [ V_84 ] . V_8 & V_12 ) {
F_6 ( V_2 ,
L_46 , V_84 ) ;
V_2 -> V_7 [ V_84 ] . V_8 &= ~ V_12 ;
V_144 = true ;
}
}
F_24 ( & V_2 -> V_4 ) ;
if ( ! V_144 )
F_6 ( V_2 ,
L_47 ) ;
}
void F_44 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_13 V_96 ;
struct V_113 V_110 ;
int V_84 ;
bool V_145 = false ;
int V_20 ;
bool V_146 ;
if ( ! F_34 ( V_2 ) ) {
F_6 ( V_2 ,
L_48 ) ;
return;
}
F_4 ( V_2 , L_49 ) ;
F_23 ( & V_2 -> V_4 ) ;
for ( V_84 = 0 ; V_84 < V_5 ; V_84 ++ ) {
if ( V_48 -> V_91 != V_2 -> V_7 [ V_84 ] . V_91 )
continue;
if ( ( V_2 -> V_7 [ V_84 ] . V_8 & V_9 ) &&
! ( V_2 -> V_7 [ V_84 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_50 ,
V_2 -> V_7 [ V_84 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_84 ] . V_10 . V_30 = 0 ;
V_2 -> V_7 [ V_84 ] . V_8 |= V_88 ;
V_145 = true ;
}
}
for ( V_84 = 0 ; V_84 < V_5 ; V_84 ++ ) {
if ( ( V_2 -> V_7 [ V_84 ] . V_8 & V_88 ) ) {
memcpy ( & V_96 , & V_2 -> V_7 [ V_84 ] . V_10 ,
sizeof( struct V_13 ) ) ;
V_146 = false ;
if ( V_2 -> V_7 [ V_84 ] . V_110 ) {
if ( V_2 -> V_147 )
F_38 ( V_2 , V_48 , V_84 , & V_110 ) ;
else
memcpy ( & V_110 , V_2 -> V_7 [ V_84 ] . V_110 ,
sizeof( struct V_113 ) ) ;
V_146 = true ;
}
F_24 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_96 , V_79 ) ;
if ( V_20 ) {
F_23 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_84 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_84 ] . V_8 &=
~ V_9 ;
V_2 -> V_7 [ V_84 ] . V_8 &=
~ V_88 ;
continue;
}
if ( V_146 )
F_45 ( V_2 , V_48 , & V_110 ,
V_79 , true ) ;
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_84 ] . V_8 &= ~ V_88 ;
}
}
F_24 ( & V_2 -> V_4 ) ;
if ( ! V_145 )
F_6 ( V_2 , L_51
L_52 ) ;
else
F_6 ( V_2 , L_51
L_53 ) ;
}
int F_46 ( struct V_1 * V_2 )
{
int V_84 ;
for ( V_84 = 0 ; V_84 < V_2 -> V_148 ; V_84 ++ )
if ( ! F_47 ( V_84 , & V_2 -> V_149 ) )
return V_84 ;
return V_150 ;
}
void F_48 ( struct V_1 * V_2 )
{
int V_84 ;
F_23 ( & V_2 -> V_4 ) ;
for ( V_84 = 0 ; V_84 < V_5 ; V_84 ++ ) {
if ( ! ( V_2 -> V_7 [ V_84 ] . V_8 & V_151 ) )
continue;
V_2 -> V_7 [ V_84 ] . V_8 &= ~ V_12 ;
V_2 -> V_89 -- ;
if ( F_35 ( V_2 -> V_89 < 0 ) )
V_2 -> V_89 = 0 ;
F_36 ( V_2 -> V_7 [ V_84 ] . V_110 ) ;
V_2 -> V_7 [ V_84 ] . V_110 = NULL ;
}
F_24 ( & V_2 -> V_4 ) ;
}
static void F_49 ( struct V_1 * V_2 ,
struct V_113 * V_110 )
{
int V_84 ;
F_50 ( V_2 , L_54 , V_110 -> V_3 ) ;
F_50 ( V_2 , L_55 ,
V_110 -> V_135 . V_136 ,
V_110 -> V_135 . V_137 ) ;
for ( V_84 = 0 ; V_84 < V_133 ; V_84 ++ )
F_50 ( V_2 , L_56 ,
V_84 , V_110 -> V_134 [ V_84 ] . V_117 ) ;
}
static inline void F_49 ( struct V_1 * V_2 ,
struct V_113 * V_110 )
{
}
static bool F_51 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_113 * V_110 )
{
int V_84 ;
if ( V_48 -> V_51 . V_52 )
return true ;
F_6 ( V_2 , L_57 ,
V_48 -> V_152 . V_153 ) ;
for ( V_84 = 0 ; V_84 < V_133 ; V_84 ++ ) {
if ( F_52 ( V_110 -> V_134 [ V_84 ] . V_117 ) &
V_154 ) {
F_6 ( V_2 ,
L_58 ,
V_84 ) ;
return false ;
}
}
return true ;
}
int F_45 ( struct V_1 * V_2 , struct V_47 * V_48 ,
struct V_113 * V_110 , T_1 V_23 , bool V_155 )
{
int V_20 = 0 ;
struct V_37 V_35 = {
. V_38 = V_156 ,
. V_40 = { sizeof( struct V_113 ) , } ,
. V_23 = V_23 ,
. V_19 = { V_110 , } ,
} ;
if ( F_35 ( V_110 -> V_3 == V_76 ) )
return - V_6 ;
F_23 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_110 -> V_3 ] . V_8 & V_9 ) ) {
F_24 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
F_24 ( & V_2 -> V_4 ) ;
F_49 ( V_2 , V_110 ) ;
if ( F_35 ( V_155 && ( V_35 . V_23 & V_42 ) ) )
return - V_6 ;
if ( F_51 ( V_2 , V_48 , V_110 ) )
V_20 = F_13 ( V_2 , & V_35 ) ;
else
V_20 = - V_6 ;
if ( V_35 . V_23 & V_42 )
return V_20 ;
if ( V_155 ) {
F_6 ( V_2 , L_59
L_60 ,
V_110 -> V_3 ) ;
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_110 -> V_3 ] . V_8 &= ~ V_88 ;
F_24 ( & V_2 -> V_4 ) ;
}
return V_20 ;
}
static struct V_113 *
F_53 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 )
{
struct V_113 * V_114 ;
V_114 = F_54 ( sizeof( struct V_113 ) , V_157 ) ;
if ( ! V_114 ) {
F_3 ( V_2 , L_61 ) ;
return NULL ;
}
F_38 ( V_2 , V_48 , V_3 , V_114 ) ;
return V_114 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
const T_1 * V_11 , T_1 * V_95 )
{
int V_20 ;
T_1 V_3 ;
struct V_113 * V_114 ;
if ( V_95 )
* V_95 = V_76 ;
V_20 = F_30 ( V_2 , V_48 , V_11 , 0 , NULL , & V_3 ) ;
if ( V_20 ) {
F_3 ( V_2 , L_62 , V_11 ) ;
return V_20 ;
}
if ( V_95 )
* V_95 = V_3 ;
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_109 ;
F_24 ( & V_2 -> V_4 ) ;
V_114 = F_53 ( V_2 , V_48 , V_3 ) ;
if ( ! V_114 ) {
F_3 ( V_2 ,
L_63 ,
V_11 ) ;
return - V_158 ;
}
V_20 = F_45 ( V_2 , V_48 , V_114 , V_79 , true ) ;
if ( V_20 )
F_3 ( V_2 , L_64 , V_20 ) ;
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_110 = V_114 ;
F_24 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
bool V_159 )
{
int V_84 , V_160 = 0 ;
T_1 V_161 [ sizeof( struct V_162 ) +
sizeof( struct V_163 ) * V_164 ] ;
struct V_162 * V_165 = (struct V_162 * ) V_161 ;
T_3 V_166 = sizeof( struct V_162 ) ;
struct V_37 V_35 = {
. V_38 = V_48 -> V_167 ,
. V_19 = { V_165 , } ,
. V_23 = V_79 ,
} ;
F_12 () ;
memset ( V_165 , 0 , V_166 +
( sizeof( struct V_163 ) * V_164 ) ) ;
for ( V_84 = 0 ; V_84 < V_164 ; V_84 ++ ) {
V_165 -> V_168 [ V_84 ] . V_169 = V_84 ;
if ( V_48 -> V_170 [ V_84 ] . V_171 ) {
V_165 -> V_168 [ V_84 ] . V_172 = V_84 ;
V_160 = 1 ;
} else {
V_165 -> V_168 [ V_84 ] . V_172 = V_150 ;
}
V_165 -> V_168 [ V_84 ] . V_171 = V_48 -> V_170 [ V_84 ] . V_171 ;
memcpy ( & V_165 -> V_168 [ V_84 ] . V_168 [ 3 ] , V_48 -> V_170 [ V_84 ] . V_168 ,
V_48 -> V_170 [ V_84 ] . V_171 ) ;
}
V_165 -> V_173 = V_174 ;
V_165 -> V_175 = V_164 ;
V_166 += sizeof( struct V_163 ) * V_164 ;
V_35 . V_40 [ 0 ] = V_166 ;
if ( V_160 || V_159 )
return F_13 ( V_2 , & V_35 ) ;
else
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
F_2 ( & V_2 -> V_118 ) ;
return F_56 ( V_2 , V_48 , false ) ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_176 * V_177 )
{
int V_20 ;
F_2 ( & V_2 -> V_118 ) ;
F_59 ( V_2 , L_65 ,
V_177 -> V_178 ) ;
memset ( & V_48 -> V_170 [ V_177 -> V_178 ] , 0 , sizeof( V_48 -> V_170 [ 0 ] ) ) ;
if ( F_60 ( V_2 ) ) {
F_59 ( V_2 ,
L_66 ) ;
return 0 ;
}
V_20 = F_56 ( V_2 , V_48 , 1 ) ;
F_59 ( V_2 , L_67 ,
V_177 -> V_178 , V_20 ) ;
return V_20 ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_176 * V_177 )
{
int V_20 ;
F_2 ( & V_2 -> V_118 ) ;
if ( V_177 -> V_179 != V_180 &&
V_177 -> V_179 != V_181 ) {
F_59 ( V_2 ,
L_68 , V_177 -> V_179 ) ;
return - V_6 ;
}
V_177 -> V_182 = V_183 ;
V_48 -> V_170 [ V_177 -> V_178 ] . V_171 = V_177 -> V_179 ;
memcpy ( & V_48 -> V_170 [ V_177 -> V_178 ] . V_168 , & V_177 -> V_168 ,
V_177 -> V_179 ) ;
V_20 = F_56 ( V_2 , V_48 , false ) ;
F_59 ( V_2 , L_69 ,
V_177 -> V_179 , V_177 -> V_178 , V_20 ) ;
return V_20 ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_184 * V_122 ,
struct V_58 * V_10 )
{
struct V_185 * V_186 = ( void * ) V_122 -> V_94 ;
if ( V_10 )
return F_21 ( V_10 ) ;
if ( V_122 -> type == V_187 && V_186 -> V_48 )
return V_186 -> V_48 -> V_85 ;
return V_76 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_176 * V_177 ,
T_1 V_3 , V_71 V_188 , T_4 * V_189 ,
V_71 V_190 )
{
T_5 V_191 ;
struct V_13 V_96 ;
int V_84 ;
F_23 ( & V_2 -> V_4 ) ;
memcpy ( & V_96 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_96 ) ) ;
F_24 ( & V_2 -> V_4 ) ;
V_191 = F_42 ( V_177 -> V_178 << V_192 ) ;
V_191 |= V_193 ;
switch ( V_177 -> V_194 ) {
case V_195 :
V_191 |= V_196 ;
memcpy ( V_96 . V_168 . V_168 , V_177 -> V_168 , V_177 -> V_179 ) ;
break;
case V_197 :
V_191 |= V_198 ;
V_96 . V_168 . V_199 = V_188 ;
for ( V_84 = 0 ; V_84 < 5 ; V_84 ++ )
V_96 . V_168 . V_200 [ V_84 ] = F_42 ( V_189 [ V_84 ] ) ;
memcpy ( V_96 . V_168 . V_168 , V_177 -> V_168 , V_177 -> V_179 ) ;
break;
case V_201 :
V_191 |= V_202 ;
case V_203 :
V_191 |= V_204 ;
memcpy ( & V_96 . V_168 . V_168 [ 3 ] , V_177 -> V_168 , V_177 -> V_179 ) ;
break;
default:
F_35 ( 1 ) ;
return - V_6 ;
}
if ( ! ( V_177 -> V_23 & V_205 ) )
V_191 |= V_206 ;
V_96 . V_168 . V_172 = V_177 -> V_182 ;
V_96 . V_168 . V_191 = V_191 ;
V_96 . V_30 = V_31 ;
V_96 . V_10 . V_207 = V_208 ;
return F_11 ( V_2 , & V_96 , V_190 ) ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_184 * V_122 ,
struct V_176 * V_177 ,
struct V_58 * V_10 , V_71 V_209 , T_4 * V_210 )
{
T_1 V_3 = F_62 ( V_2 , V_122 , V_10 ) ;
if ( V_3 == V_76 )
return;
if ( F_65 ( V_2 ) ) {
return;
}
F_63 ( V_2 , V_177 , V_3 ,
V_209 , V_210 , V_42 ) ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_176 * V_177 ,
struct V_58 * V_10 )
{
struct V_13 V_96 ;
T_1 V_3 = F_62 ( V_2 , V_48 -> V_122 , V_10 ) ;
T_5 V_191 ;
if ( V_3 == V_76 )
return - V_211 ;
F_23 ( & V_2 -> V_4 ) ;
memcpy ( & V_96 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_96 ) ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) )
V_3 = V_76 ;
F_24 ( & V_2 -> V_4 ) ;
if ( V_3 == V_76 )
return 0 ;
F_2 ( & V_2 -> V_118 ) ;
V_48 -> V_212 -- ;
F_59 ( V_2 , L_70 ,
V_177 -> V_178 , V_3 ) ;
if ( ! F_67 ( V_177 -> V_182 , & V_2 -> V_149 ) )
F_3 ( V_2 , L_71 ,
V_177 -> V_182 ) ;
V_191 = F_42 ( V_177 -> V_178 << V_192 ) ;
V_191 |= V_193 | V_213 |
V_214 ;
if ( ! ( V_177 -> V_23 & V_205 ) )
V_191 |= V_206 ;
V_96 . V_168 . V_191 = V_191 ;
V_96 . V_168 . V_172 = V_177 -> V_182 ;
V_96 . V_10 . V_207 = V_208 ;
V_96 . V_30 = V_31 ;
return F_11 ( V_2 , & V_96 , V_79 ) ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_176 * V_177 ,
struct V_58 * V_10 )
{
struct V_215 V_216 ;
T_4 V_217 [ 5 ] ;
int V_20 ;
T_1 V_3 = F_62 ( V_2 , V_48 -> V_122 , V_10 ) ;
const T_1 * V_11 ;
if ( V_3 == V_76 )
return - V_6 ;
F_2 ( & V_2 -> V_118 ) ;
V_177 -> V_182 = F_46 ( V_2 ) ;
if ( V_177 -> V_182 == V_150 )
return - V_218 ;
V_48 -> V_212 ++ ;
switch ( V_177 -> V_194 ) {
case V_197 :
if ( V_10 )
V_11 = V_10 -> V_11 ;
else
V_11 = V_48 -> V_152 . V_219 ;
F_69 ( V_177 , 0 , & V_216 ) ;
F_70 ( V_177 , V_11 , V_216 . V_220 . V_209 , V_217 ) ;
V_20 = F_63 ( V_2 , V_177 , V_3 ,
V_216 . V_220 . V_209 , V_217 , V_79 ) ;
break;
case V_195 :
case V_203 :
case V_201 :
V_20 = F_63 ( V_2 , V_177 , V_3 ,
0 , NULL , V_79 ) ;
break;
default:
F_3 ( V_2 , L_72 , V_177 -> V_194 ) ;
V_20 = - V_6 ;
}
if ( V_20 ) {
V_48 -> V_212 -- ;
F_71 ( V_177 -> V_182 , & V_2 -> V_149 ) ;
}
F_59 ( V_2 , L_73 ,
V_177 -> V_194 , V_177 -> V_179 , V_177 -> V_178 ,
V_10 ? V_10 -> V_11 : NULL , V_20 ) ;
return V_20 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_113 * V_114 ;
T_1 V_3 ;
F_23 ( & V_2 -> V_4 ) ;
V_3 = F_26 ( V_2 , V_48 , V_221 , false , NULL ) ;
if ( V_3 == V_76 ) {
F_3 ( V_2 , L_74 ) ;
F_24 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_151 ;
F_24 ( & V_2 -> V_4 ) ;
V_114 = F_53 ( V_2 , V_48 , V_3 ) ;
if ( ! V_114 ) {
F_3 ( V_2 ,
L_75 ) ;
return - V_158 ;
}
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_110 = V_114 ;
F_24 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_113 * V_114 ;
T_1 V_3 = V_48 -> V_86 ;
V_114 = F_53 ( V_2 , V_48 , V_3 ) ;
if ( ! V_114 ) {
F_3 ( V_2 , L_75 ) ;
return - V_158 ;
}
F_23 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_7 [ V_3 ] . V_110 )
F_36 ( V_2 -> V_7 [ V_3 ] . V_110 ) ;
else
F_6 ( V_2 , L_76 ) ;
V_2 -> V_7 [ V_3 ] . V_110 = V_114 ;
F_24 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 )
{
struct V_47 * V_48 ;
int V_20 = 0 ;
F_75 (priv, ctx) {
V_20 = F_73 ( V_2 , V_48 ) ;
if ( V_20 )
break;
}
return V_20 ;
}
int F_76 ( struct V_1 * V_2 , int V_3 , int V_107 )
{
struct V_13 V_96 ;
F_2 ( & V_2 -> V_118 ) ;
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_207 = V_222 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_223 &= F_42 ( ~ ( 1 << V_107 ) ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_96 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_24 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_96 , V_79 ) ;
}
int F_77 ( struct V_1 * V_2 , struct V_58 * V_10 ,
int V_107 , T_4 V_224 )
{
int V_3 ;
struct V_13 V_96 ;
F_2 ( & V_2 -> V_118 ) ;
V_3 = F_21 ( V_10 ) ;
if ( V_3 == V_76 )
return - V_225 ;
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_78 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_207 = V_226 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_227 = ( T_1 ) V_107 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_228 = F_42 ( V_224 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_96 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_24 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_96 , V_79 ) ;
}
int F_78 ( struct V_1 * V_2 , struct V_58 * V_10 ,
int V_107 )
{
int V_3 ;
struct V_13 V_96 ;
F_2 ( & V_2 -> V_118 ) ;
V_3 = F_21 ( V_10 ) ;
if ( V_3 == V_76 ) {
F_3 ( V_2 , L_77 , V_107 ) ;
return - V_225 ;
}
F_23 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_78 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_207 = V_229 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_230 = ( T_1 ) V_107 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_96 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_24 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_96 , V_79 ) ;
}
void F_79 ( struct V_1 * V_2 , int V_3 , int V_231 )
{
struct V_13 V_35 = {
. V_30 = V_31 ,
. V_77 = V_232 ,
. V_78 = V_232 ,
. V_10 . V_3 = V_3 ,
. V_10 . V_207 = V_233 ,
. V_234 = F_42 ( V_231 ) ,
} ;
F_11 ( V_2 , & V_35 , V_42 ) ;
}
