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
static void F_15 ( struct V_1 * V_2 ,
struct V_46 * V_10 ,
struct V_47 * V_48 ,
T_2 * V_23 , T_2 * V_49 )
{
struct V_50 * V_51 = & V_10 -> V_52 ;
T_1 V_53 ;
* V_49 = V_54 |
V_55 |
V_56 |
V_57 |
V_58 ;
* V_23 = 0 ;
if ( ! V_10 || ! V_51 -> V_59 )
return;
V_53 = ( V_51 -> V_60 & V_61 ) >> 2 ;
F_6 ( V_2 , L_23 ,
( V_53 == V_62 ) ?
L_24 :
( V_53 == V_63 ) ?
L_25 : L_26 ) ;
switch ( V_53 ) {
case V_62 :
* V_23 |= V_55 ;
break;
case V_63 :
* V_23 |= V_54 ;
break;
case V_64 :
break;
default:
F_16 ( V_2 , L_27 , V_53 ) ;
break;
}
* V_23 |= F_17 (
( V_65 ) V_51 -> V_66 << V_67 ) ;
* V_23 |= F_17 (
( V_65 ) V_51 -> V_68 << V_69 ) ;
if ( F_18 ( V_2 , V_48 , & V_10 -> V_52 ) )
* V_23 |= V_56 ;
}
int F_19 ( struct V_1 * V_2 , struct V_47 * V_48 ,
struct V_46 * V_10 )
{
T_1 V_3 = F_20 ( V_10 ) ;
T_2 V_23 , V_49 ;
struct V_13 V_35 ;
if ( F_21 ( V_3 == V_70 ) )
return - V_6 ;
F_15 ( V_2 , V_10 , V_48 , & V_23 , & V_49 ) ;
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_71 &= ~ V_49 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_71 |= V_23 ;
F_23 ( & V_2 -> V_4 ) ;
memset ( & V_35 , 0 , sizeof( V_35 ) ) ;
V_35 . V_30 = V_31 ;
V_35 . V_72 = V_49 ;
V_35 . V_71 = V_23 ;
V_35 . V_10 . V_3 = V_3 ;
return F_11 ( V_2 , & V_35 , V_73 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_74 ,
struct V_46 * V_10 ,
struct V_47 * V_48 )
{
T_2 V_23 , V_49 ;
F_15 ( V_2 , V_10 , V_48 , & V_23 , & V_49 ) ;
F_2 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_74 ] . V_10 . V_71 &= ~ V_49 ;
V_2 -> V_7 [ V_74 ] . V_10 . V_71 |= V_23 ;
}
T_1 F_25 ( struct V_1 * V_2 , struct V_47 * V_48 ,
const T_1 * V_11 , bool V_75 , struct V_46 * V_10 )
{
struct V_76 * V_77 ;
int V_78 ;
T_1 V_3 = V_70 ;
if ( V_75 )
V_3 = V_48 -> V_79 ;
else if ( F_26 ( V_11 ) )
V_3 = V_48 -> V_80 ;
else
for ( V_78 = V_81 ; V_78 < V_5 ; V_78 ++ ) {
if ( ! F_27 ( V_2 -> V_7 [ V_78 ] . V_10 . V_10 . V_11 ,
V_11 ) ) {
V_3 = V_78 ;
break;
}
if ( ! V_2 -> V_7 [ V_78 ] . V_8 &&
V_3 == V_70 )
V_3 = V_78 ;
}
if ( F_28 ( V_3 == V_70 ) )
return V_3 ;
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_82 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) &&
! F_27 ( V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 , V_11 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
return V_3 ;
}
V_77 = & V_2 -> V_7 [ V_3 ] ;
V_77 -> V_8 = V_9 ;
F_4 ( V_2 , L_32 ,
V_3 , V_11 ) ;
V_2 -> V_83 ++ ;
memset ( & V_77 -> V_10 , 0 , sizeof( struct V_13 ) ) ;
memcpy ( V_77 -> V_10 . V_10 . V_11 , V_11 , V_84 ) ;
V_77 -> V_10 . V_30 = 0 ;
V_77 -> V_10 . V_10 . V_3 = V_3 ;
V_77 -> V_10 . V_71 = V_48 -> V_71 ;
V_77 -> V_85 = V_48 -> V_85 ;
if ( V_10 ) {
struct V_86 * V_87 ;
V_87 = ( void * ) V_10 -> V_88 ;
V_87 -> V_48 = V_48 ;
}
F_24 ( V_2 , V_3 , V_10 , V_48 ) ;
return V_3 ;
}
int F_29 ( struct V_1 * V_2 , struct V_47 * V_48 ,
const T_1 * V_11 , bool V_75 ,
struct V_46 * V_10 , T_1 * V_89 )
{
int V_20 = 0 ;
T_1 V_3 ;
struct V_13 V_90 ;
* V_89 = 0 ;
F_22 ( & V_2 -> V_4 ) ;
V_3 = F_25 ( V_2 , V_48 , V_11 , V_75 , V_10 ) ;
if ( V_3 == V_70 ) {
F_3 ( V_2 , L_33 ,
V_11 ) ;
F_23 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_82 ) {
F_6 ( V_2 , L_28
L_29 , V_3 ) ;
F_23 ( & V_2 -> V_4 ) ;
return - V_91 ;
}
if ( ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) &&
( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_30
L_31 , V_3 , V_11 ) ;
F_23 ( & V_2 -> V_4 ) ;
return - V_91 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_82 ;
memcpy ( & V_90 , & V_2 -> V_7 [ V_3 ] . V_10 ,
sizeof( struct V_13 ) ) ;
F_23 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_90 , V_73 ) ;
if ( V_20 ) {
F_22 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_82 ;
F_23 ( & V_2 -> V_4 ) ;
}
* V_89 = V_3 ;
return V_20 ;
}
static void F_30 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( & V_2 -> V_4 ) ;
if ( ( V_2 -> V_7 [ V_3 ] . V_8 &
( V_12 | V_9 ) ) !=
V_12 )
F_3 ( V_2 , L_35 , V_3 ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_12 ;
memset ( & V_2 -> V_7 [ V_3 ] , 0 , sizeof( struct V_76 ) ) ;
F_4 ( V_2 , L_36 , V_3 ) ;
}
static int F_31 ( struct V_1 * V_2 ,
const T_1 * V_11 , int V_3 ,
bool V_92 )
{
struct V_15 * V_16 ;
int V_20 ;
struct V_93 V_94 ;
struct V_37 V_35 = {
. V_38 = V_95 ,
. V_40 = { sizeof( struct V_93 ) , } ,
. V_23 = V_73 ,
. V_19 = { & V_94 , } ,
} ;
memset ( & V_94 , 0 , sizeof( V_94 ) ) ;
V_94 . V_96 = 1 ;
memcpy ( & V_94 . V_11 , V_11 , V_84 ) ;
V_35 . V_23 |= V_43 ;
V_20 = F_13 ( V_2 , & V_35 ) ;
if ( V_20 )
return V_20 ;
V_16 = V_35 . V_97 ;
if ( V_16 -> V_22 . V_23 & V_24 ) {
F_3 ( V_2 , L_37 ,
V_16 -> V_22 . V_23 ) ;
V_20 = - V_21 ;
}
if ( ! V_20 ) {
struct V_98 * V_99 = ( void * ) V_16 -> V_19 ;
switch ( V_99 -> V_25 ) {
case V_100 :
if ( ! V_92 ) {
F_22 ( & V_2 -> V_4 ) ;
F_30 ( V_2 , V_3 ) ;
F_23 ( & V_2 -> V_4 ) ;
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
int F_32 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_101 ;
if ( ! F_33 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return 0 ;
}
F_4 ( V_2 , L_41 ,
V_3 , V_11 ) ;
if ( F_34 ( V_3 == V_70 ) )
return - V_6 ;
F_22 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) {
F_6 ( V_2 , L_42 ,
V_11 ) ;
goto V_102;
}
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) ) {
F_6 ( V_2 , L_43 ,
V_11 ) ;
goto V_102;
}
if ( V_2 -> V_7 [ V_3 ] . V_8 & V_103 ) {
F_35 ( V_2 -> V_7 [ V_3 ] . V_104 ) ;
V_2 -> V_7 [ V_3 ] . V_104 = NULL ;
}
for ( V_101 = 0 ; V_101 < V_105 ; V_101 ++ )
memset ( & V_2 -> V_106 [ V_3 ] [ V_101 ] , 0 ,
sizeof( V_2 -> V_106 [ V_3 ] [ V_101 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_83 -- ;
if ( F_34 ( V_2 -> V_83 < 0 ) )
V_2 -> V_83 = 0 ;
F_23 ( & V_2 -> V_4 ) ;
return F_31 ( V_2 , V_11 , V_3 , false ) ;
V_102:
F_23 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
void F_36 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_11 )
{
T_1 V_101 ;
if ( ! F_33 ( V_2 ) ) {
F_6 ( V_2 ,
L_40 ,
V_11 ) ;
return;
}
F_4 ( V_2 , L_44 , V_11 , V_3 ) ;
if ( F_21 ( V_3 == V_70 ) )
return;
F_22 ( & V_2 -> V_4 ) ;
F_21 ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_9 ) ) ;
for ( V_101 = 0 ; V_101 < V_105 ; V_101 ++ )
memset ( & V_2 -> V_106 [ V_3 ] [ V_101 ] , 0 ,
sizeof( V_2 -> V_106 [ V_3 ] [ V_101 ] ) ) ;
V_2 -> V_7 [ V_3 ] . V_8 &= ~ V_9 ;
V_2 -> V_83 -- ;
if ( F_21 ( V_2 -> V_83 < 0 ) )
V_2 -> V_83 = 0 ;
F_23 ( & V_2 -> V_4 ) ;
}
void F_37 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
int V_78 ;
bool V_107 = false ;
F_6 ( V_2 , L_45 ) ;
F_22 ( & V_2 -> V_4 ) ;
for ( V_78 = 0 ; V_78 < V_5 ; V_78 ++ ) {
if ( V_48 && V_48 -> V_85 != V_2 -> V_7 [ V_78 ] . V_85 )
continue;
if ( V_2 -> V_7 [ V_78 ] . V_8 & V_12 ) {
F_6 ( V_2 ,
L_46 , V_78 ) ;
V_2 -> V_7 [ V_78 ] . V_8 &= ~ V_12 ;
V_107 = true ;
}
}
F_23 ( & V_2 -> V_4 ) ;
if ( ! V_107 )
F_6 ( V_2 ,
L_47 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_47 * V_48 )
{
struct V_13 V_90 ;
struct V_108 V_104 ;
int V_78 ;
bool V_109 = false ;
int V_20 ;
bool V_110 ;
if ( ! F_33 ( V_2 ) ) {
F_6 ( V_2 ,
L_48 ) ;
return;
}
F_4 ( V_2 , L_49 ) ;
F_22 ( & V_2 -> V_4 ) ;
for ( V_78 = 0 ; V_78 < V_5 ; V_78 ++ ) {
if ( V_48 -> V_85 != V_2 -> V_7 [ V_78 ] . V_85 )
continue;
if ( ( V_2 -> V_7 [ V_78 ] . V_8 & V_9 ) &&
! ( V_2 -> V_7 [ V_78 ] . V_8 & V_12 ) ) {
F_4 ( V_2 , L_50 ,
V_2 -> V_7 [ V_78 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_78 ] . V_10 . V_30 = 0 ;
V_2 -> V_7 [ V_78 ] . V_8 |= V_82 ;
V_109 = true ;
}
}
for ( V_78 = 0 ; V_78 < V_5 ; V_78 ++ ) {
if ( ( V_2 -> V_7 [ V_78 ] . V_8 & V_82 ) ) {
memcpy ( & V_90 , & V_2 -> V_7 [ V_78 ] . V_10 ,
sizeof( struct V_13 ) ) ;
V_110 = false ;
if ( V_2 -> V_7 [ V_78 ] . V_104 ) {
if ( V_2 -> V_111 )
F_39 ( V_2 , V_48 , V_78 , & V_104 ) ;
else
memcpy ( & V_104 , V_2 -> V_7 [ V_78 ] . V_104 ,
sizeof( struct V_108 ) ) ;
V_110 = true ;
}
F_23 ( & V_2 -> V_4 ) ;
V_20 = F_11 ( V_2 , & V_90 , V_73 ) ;
if ( V_20 ) {
F_22 ( & V_2 -> V_4 ) ;
F_3 ( V_2 , L_34 ,
V_2 -> V_7 [ V_78 ] . V_10 . V_10 . V_11 ) ;
V_2 -> V_7 [ V_78 ] . V_8 &=
~ V_9 ;
V_2 -> V_7 [ V_78 ] . V_8 &=
~ V_82 ;
F_23 ( & V_2 -> V_4 ) ;
}
if ( V_110 )
F_40 ( V_2 , V_48 , & V_104 ,
V_73 , true ) ;
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_78 ] . V_8 &= ~ V_82 ;
}
}
F_23 ( & V_2 -> V_4 ) ;
if ( ! V_109 )
F_6 ( V_2 , L_51
L_52 ) ;
else
F_6 ( V_2 , L_51
L_53 ) ;
}
int F_41 ( struct V_1 * V_2 )
{
int V_78 ;
for ( V_78 = 0 ; V_78 < V_2 -> V_112 ; V_78 ++ )
if ( ! F_42 ( V_78 , & V_2 -> V_113 ) )
return V_78 ;
return V_114 ;
}
void F_43 ( struct V_1 * V_2 )
{
int V_78 ;
F_22 ( & V_2 -> V_4 ) ;
for ( V_78 = 0 ; V_78 < V_5 ; V_78 ++ ) {
if ( ! ( V_2 -> V_7 [ V_78 ] . V_8 & V_115 ) )
continue;
V_2 -> V_7 [ V_78 ] . V_8 &= ~ V_12 ;
V_2 -> V_83 -- ;
if ( F_34 ( V_2 -> V_83 < 0 ) )
V_2 -> V_83 = 0 ;
F_35 ( V_2 -> V_7 [ V_78 ] . V_104 ) ;
V_2 -> V_7 [ V_78 ] . V_104 = NULL ;
}
F_23 ( & V_2 -> V_4 ) ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_108 * V_104 )
{
int V_78 ;
F_45 ( V_2 , L_54 , V_104 -> V_3 ) ;
F_45 ( V_2 , L_55 ,
V_104 -> V_116 . V_117 ,
V_104 -> V_116 . V_118 ) ;
for ( V_78 = 0 ; V_78 < V_119 ; V_78 ++ )
F_45 ( V_2 , L_56 ,
V_78 , V_104 -> V_120 [ V_78 ] . V_121 ) ;
}
static inline void F_44 ( struct V_1 * V_2 ,
struct V_108 * V_104 )
{
}
static bool F_46 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_108 * V_104 )
{
int V_78 ;
if ( V_48 -> V_122 . V_123 )
return true ;
F_6 ( V_2 , L_57 ,
V_48 -> V_124 . V_125 ) ;
for ( V_78 = 0 ; V_78 < V_119 ; V_78 ++ ) {
if ( F_47 ( V_104 -> V_120 [ V_78 ] . V_121 ) &
V_126 ) {
F_6 ( V_2 ,
L_58 ,
V_78 ) ;
return false ;
}
}
return true ;
}
int F_40 ( struct V_1 * V_2 , struct V_47 * V_48 ,
struct V_108 * V_104 , T_1 V_23 , bool V_127 )
{
int V_20 = 0 ;
struct V_37 V_35 = {
. V_38 = V_128 ,
. V_40 = { sizeof( struct V_108 ) , } ,
. V_23 = V_23 ,
. V_19 = { V_104 , } ,
} ;
if ( F_34 ( V_104 -> V_3 == V_70 ) )
return - V_6 ;
F_22 ( & V_2 -> V_4 ) ;
if ( ! ( V_2 -> V_7 [ V_104 -> V_3 ] . V_8 & V_9 ) ) {
F_23 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
F_23 ( & V_2 -> V_4 ) ;
F_44 ( V_2 , V_104 ) ;
if ( F_34 ( V_127 && ( V_35 . V_23 & V_42 ) ) )
return - V_6 ;
if ( F_46 ( V_2 , V_48 , V_104 ) )
V_20 = F_13 ( V_2 , & V_35 ) ;
else
V_20 = - V_6 ;
if ( V_35 . V_23 & V_42 )
return V_20 ;
if ( V_127 ) {
F_6 ( V_2 , L_59
L_60 ,
V_104 -> V_3 ) ;
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_104 -> V_3 ] . V_8 &= ~ V_82 ;
F_23 ( & V_2 -> V_4 ) ;
}
return V_20 ;
}
void F_39 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 , struct V_108 * V_129 )
{
int V_78 , V_130 ;
V_65 V_131 = 0 ;
T_2 V_121 ;
F_2 ( & V_2 -> V_132 ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
if ( V_2 -> V_133 == V_134 )
V_130 = V_135 ;
else if ( V_48 && V_48 -> V_136 && V_48 -> V_136 -> V_137 )
V_130 = V_135 ;
else
V_130 = V_138 ;
if ( V_130 >= V_139 && V_130 <= V_140 )
V_131 |= V_141 ;
V_131 |= F_48 ( F_49 ( V_2 ) . V_142 ) <<
V_143 ;
V_121 = F_50 ( V_144 [ V_130 ] . V_145 , V_131 ) ;
for ( V_78 = 0 ; V_78 < V_119 ; V_78 ++ )
V_129 -> V_120 [ V_78 ] . V_121 = V_121 ;
V_129 -> V_116 . V_117 =
F_48 ( F_49 ( V_2 ) . V_142 ) ;
V_129 -> V_116 . V_118 =
F_49 ( V_2 ) . V_142 &
~ F_48 ( F_49 ( V_2 ) . V_142 ) ;
if ( ! V_129 -> V_116 . V_118 ) {
V_129 -> V_116 . V_118 = V_146 ;
} else if ( F_51 ( F_49 ( V_2 ) . V_142 ) == 2 ) {
V_129 -> V_116 . V_118 =
F_49 ( V_2 ) . V_142 ;
}
V_129 -> V_147 . V_148 =
V_149 ;
V_129 -> V_147 . V_150 =
F_52 ( V_151 ) ;
V_129 -> V_3 = V_3 ;
}
static struct V_108 *
F_53 ( struct V_1 * V_2 , struct V_47 * V_48 ,
T_1 V_3 )
{
struct V_108 * V_129 ;
V_129 = F_54 ( sizeof( struct V_108 ) , V_152 ) ;
if ( ! V_129 ) {
F_3 ( V_2 , L_61 ) ;
return NULL ;
}
F_39 ( V_2 , V_48 , V_3 , V_129 ) ;
return V_129 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
const T_1 * V_11 , T_1 * V_89 )
{
int V_20 ;
T_1 V_3 ;
struct V_108 * V_129 ;
if ( V_89 )
* V_89 = V_70 ;
V_20 = F_29 ( V_2 , V_48 , V_11 , 0 , NULL , & V_3 ) ;
if ( V_20 ) {
F_3 ( V_2 , L_62 , V_11 ) ;
return V_20 ;
}
if ( V_89 )
* V_89 = V_3 ;
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_103 ;
F_23 ( & V_2 -> V_4 ) ;
V_129 = F_53 ( V_2 , V_48 , V_3 ) ;
if ( ! V_129 ) {
F_3 ( V_2 ,
L_63 ,
V_11 ) ;
return - V_153 ;
}
V_20 = F_40 ( V_2 , V_48 , V_129 , V_73 , true ) ;
if ( V_20 )
F_3 ( V_2 , L_64 , V_20 ) ;
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_104 = V_129 ;
F_23 ( & V_2 -> V_4 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
bool V_154 )
{
int V_78 , V_155 = 0 ;
T_1 V_156 [ sizeof( struct V_157 ) +
sizeof( struct V_158 ) * V_159 ] ;
struct V_157 * V_160 = (struct V_157 * ) V_156 ;
T_3 V_161 = sizeof( struct V_157 ) ;
struct V_37 V_35 = {
. V_38 = V_48 -> V_162 ,
. V_19 = { V_160 , } ,
. V_23 = V_73 ,
} ;
F_12 () ;
memset ( V_160 , 0 , V_161 +
( sizeof( struct V_158 ) * V_159 ) ) ;
for ( V_78 = 0 ; V_78 < V_159 ; V_78 ++ ) {
V_160 -> V_163 [ V_78 ] . V_164 = V_78 ;
if ( V_48 -> V_165 [ V_78 ] . V_166 ) {
V_160 -> V_163 [ V_78 ] . V_167 = V_78 ;
V_155 = 1 ;
} else {
V_160 -> V_163 [ V_78 ] . V_167 = V_114 ;
}
V_160 -> V_163 [ V_78 ] . V_166 = V_48 -> V_165 [ V_78 ] . V_166 ;
memcpy ( & V_160 -> V_163 [ V_78 ] . V_163 [ 3 ] , V_48 -> V_165 [ V_78 ] . V_163 ,
V_48 -> V_165 [ V_78 ] . V_166 ) ;
}
V_160 -> V_168 = V_169 ;
V_160 -> V_170 = V_159 ;
V_161 += sizeof( struct V_158 ) * V_159 ;
V_35 . V_40 [ 0 ] = V_161 ;
if ( V_155 || V_154 )
return F_13 ( V_2 , & V_35 ) ;
else
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
F_2 ( & V_2 -> V_132 ) ;
return F_56 ( V_2 , V_48 , false ) ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_171 * V_172 )
{
int V_20 ;
F_2 ( & V_2 -> V_132 ) ;
F_59 ( V_2 , L_65 ,
V_172 -> V_173 ) ;
memset ( & V_48 -> V_165 [ V_172 -> V_173 ] , 0 , sizeof( V_48 -> V_165 [ 0 ] ) ) ;
if ( F_60 ( V_2 ) ) {
F_59 ( V_2 ,
L_66 ) ;
return 0 ;
}
V_20 = F_56 ( V_2 , V_48 , 1 ) ;
F_59 ( V_2 , L_67 ,
V_172 -> V_173 , V_20 ) ;
return V_20 ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_171 * V_172 )
{
int V_20 ;
F_2 ( & V_2 -> V_132 ) ;
if ( V_172 -> V_174 != V_175 &&
V_172 -> V_174 != V_176 ) {
F_59 ( V_2 ,
L_68 , V_172 -> V_174 ) ;
return - V_6 ;
}
V_172 -> V_177 = V_178 ;
V_48 -> V_165 [ V_172 -> V_173 ] . V_166 = V_172 -> V_174 ;
memcpy ( & V_48 -> V_165 [ V_172 -> V_173 ] . V_163 , & V_172 -> V_163 ,
V_172 -> V_174 ) ;
V_20 = F_56 ( V_2 , V_48 , false ) ;
F_59 ( V_2 , L_69 ,
V_172 -> V_174 , V_172 -> V_173 , V_20 ) ;
return V_20 ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_179 * V_136 ,
struct V_46 * V_10 )
{
struct V_180 * V_181 = ( void * ) V_136 -> V_88 ;
if ( V_10 )
return F_20 ( V_10 ) ;
if ( V_136 -> type == V_182 && V_181 -> V_48 )
return V_181 -> V_48 -> V_79 ;
return V_70 ;
}
static int F_63 ( struct V_1 * V_2 ,
struct V_171 * V_172 ,
T_1 V_3 , V_65 V_183 , T_4 * V_184 ,
V_65 V_185 )
{
T_5 V_186 ;
struct V_13 V_90 ;
int V_78 ;
F_22 ( & V_2 -> V_4 ) ;
memcpy ( & V_90 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_90 ) ) ;
F_23 ( & V_2 -> V_4 ) ;
V_186 = F_52 ( V_172 -> V_173 << V_187 ) ;
V_186 |= V_188 ;
switch ( V_172 -> V_189 ) {
case V_190 :
V_186 |= V_191 ;
memcpy ( V_90 . V_163 . V_163 , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
case V_192 :
V_186 |= V_193 ;
V_90 . V_163 . V_194 = V_183 ;
for ( V_78 = 0 ; V_78 < 5 ; V_78 ++ )
V_90 . V_163 . V_195 [ V_78 ] = F_52 ( V_184 [ V_78 ] ) ;
memcpy ( V_90 . V_163 . V_163 , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
case V_196 :
V_186 |= V_197 ;
case V_198 :
V_186 |= V_199 ;
memcpy ( & V_90 . V_163 . V_163 [ 3 ] , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
default:
F_34 ( 1 ) ;
return - V_6 ;
}
if ( ! ( V_172 -> V_23 & V_200 ) )
V_186 |= V_201 ;
V_90 . V_163 . V_167 = V_172 -> V_177 ;
V_90 . V_163 . V_186 = V_186 ;
V_90 . V_30 = V_31 ;
V_90 . V_10 . V_202 = V_203 ;
return F_11 ( V_2 , & V_90 , V_185 ) ;
}
void F_64 ( struct V_1 * V_2 ,
struct V_179 * V_136 ,
struct V_171 * V_172 ,
struct V_46 * V_10 , V_65 V_204 , T_4 * V_205 )
{
T_1 V_3 = F_62 ( V_2 , V_136 , V_10 ) ;
if ( V_3 == V_70 )
return;
if ( F_65 ( V_2 ) ) {
return;
}
F_63 ( V_2 , V_172 , V_3 ,
V_204 , V_205 , V_42 ) ;
}
int F_66 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_171 * V_172 ,
struct V_46 * V_10 )
{
struct V_13 V_90 ;
T_1 V_3 = F_62 ( V_2 , V_48 -> V_136 , V_10 ) ;
T_5 V_186 ;
if ( V_3 == V_70 )
return - V_206 ;
F_22 ( & V_2 -> V_4 ) ;
memcpy ( & V_90 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( V_90 ) ) ;
if ( ! ( V_2 -> V_7 [ V_3 ] . V_8 & V_12 ) )
V_3 = V_70 ;
F_23 ( & V_2 -> V_4 ) ;
if ( V_3 == V_70 )
return 0 ;
F_2 ( & V_2 -> V_132 ) ;
V_48 -> V_207 -- ;
F_59 ( V_2 , L_70 ,
V_172 -> V_173 , V_3 ) ;
if ( ! F_67 ( V_172 -> V_177 , & V_2 -> V_113 ) )
F_3 ( V_2 , L_71 ,
V_172 -> V_177 ) ;
V_186 = F_52 ( V_172 -> V_173 << V_187 ) ;
V_186 |= V_188 | V_208 |
V_209 ;
if ( ! ( V_172 -> V_23 & V_200 ) )
V_186 |= V_201 ;
V_90 . V_163 . V_186 = V_186 ;
V_90 . V_163 . V_167 = V_114 ;
V_90 . V_10 . V_202 = V_203 ;
V_90 . V_30 = V_31 ;
return F_11 ( V_2 , & V_90 , V_73 ) ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_47 * V_48 ,
struct V_171 * V_172 ,
struct V_46 * V_10 )
{
struct V_210 V_211 ;
T_4 V_212 [ 5 ] ;
int V_20 ;
T_1 V_3 = F_62 ( V_2 , V_48 -> V_136 , V_10 ) ;
const T_1 * V_11 ;
if ( V_3 == V_70 )
return - V_6 ;
F_2 ( & V_2 -> V_132 ) ;
V_172 -> V_177 = F_41 ( V_2 ) ;
if ( V_172 -> V_177 == V_114 )
return - V_213 ;
V_48 -> V_207 ++ ;
switch ( V_172 -> V_189 ) {
case V_192 :
if ( V_10 )
V_11 = V_10 -> V_11 ;
else
V_11 = V_48 -> V_124 . V_214 ;
F_69 ( V_172 , 0 , & V_211 ) ;
F_70 ( V_172 , V_11 , V_211 . V_215 . V_204 , V_212 ) ;
V_20 = F_63 ( V_2 , V_172 , V_3 ,
V_211 . V_215 . V_204 , V_212 , V_73 ) ;
break;
case V_190 :
case V_198 :
case V_196 :
V_20 = F_63 ( V_2 , V_172 , V_3 ,
0 , NULL , V_73 ) ;
break;
default:
F_3 ( V_2 , L_72 , V_172 -> V_189 ) ;
V_20 = - V_6 ;
}
if ( V_20 ) {
V_48 -> V_207 -- ;
F_71 ( V_172 -> V_177 , & V_2 -> V_113 ) ;
}
F_59 ( V_2 , L_73 ,
V_172 -> V_189 , V_172 -> V_174 , V_172 -> V_173 ,
V_10 ? V_10 -> V_11 : NULL , V_20 ) ;
return V_20 ;
}
int F_72 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_108 * V_129 ;
T_1 V_3 ;
F_22 ( & V_2 -> V_4 ) ;
V_3 = F_25 ( V_2 , V_48 , V_216 , false , NULL ) ;
if ( V_3 == V_70 ) {
F_3 ( V_2 , L_74 ) ;
F_23 ( & V_2 -> V_4 ) ;
return - V_6 ;
}
V_2 -> V_7 [ V_3 ] . V_8 |= V_9 ;
V_2 -> V_7 [ V_3 ] . V_8 |= V_115 ;
F_23 ( & V_2 -> V_4 ) ;
V_129 = F_53 ( V_2 , V_48 , V_3 ) ;
if ( ! V_129 ) {
F_3 ( V_2 ,
L_75 ) ;
return - V_153 ;
}
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_104 = V_129 ;
F_23 ( & V_2 -> V_4 ) ;
return 0 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_108 * V_129 ;
T_1 V_3 = V_48 -> V_80 ;
V_129 = F_53 ( V_2 , V_48 , V_3 ) ;
if ( ! V_129 ) {
F_3 ( V_2 , L_75 ) ;
return - V_153 ;
}
F_22 ( & V_2 -> V_4 ) ;
if ( V_2 -> V_7 [ V_3 ] . V_104 )
F_35 ( V_2 -> V_7 [ V_3 ] . V_104 ) ;
else
F_6 ( V_2 , L_76 ) ;
V_2 -> V_7 [ V_3 ] . V_104 = V_129 ;
F_23 ( & V_2 -> V_4 ) ;
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
int F_76 ( struct V_1 * V_2 , int V_3 , int V_101 )
{
struct V_13 V_90 ;
F_2 ( & V_2 -> V_132 ) ;
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_202 = V_217 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_218 &= F_52 ( ~ ( 1 << V_101 ) ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_90 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_23 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_90 , V_73 ) ;
}
int F_77 ( struct V_1 * V_2 , struct V_46 * V_10 ,
int V_101 , T_4 V_219 )
{
int V_3 ;
struct V_13 V_90 ;
F_2 ( & V_2 -> V_132 ) ;
V_3 = F_20 ( V_10 ) ;
if ( V_3 == V_70 )
return - V_220 ;
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_72 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_202 = V_221 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_222 = ( T_1 ) V_101 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_223 = F_52 ( V_219 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_90 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_23 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_90 , V_73 ) ;
}
int F_78 ( struct V_1 * V_2 , struct V_46 * V_10 ,
int V_101 )
{
int V_3 ;
struct V_13 V_90 ;
F_2 ( & V_2 -> V_132 ) ;
V_3 = F_20 ( V_10 ) ;
if ( V_3 == V_70 ) {
F_3 ( V_2 , L_77 , V_101 ) ;
return - V_220 ;
}
F_22 ( & V_2 -> V_4 ) ;
V_2 -> V_7 [ V_3 ] . V_10 . V_72 = 0 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_10 . V_202 = V_224 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_225 = ( T_1 ) V_101 ;
V_2 -> V_7 [ V_3 ] . V_10 . V_30 = V_31 ;
memcpy ( & V_90 , & V_2 -> V_7 [ V_3 ] . V_10 , sizeof( struct V_13 ) ) ;
F_23 ( & V_2 -> V_4 ) ;
return F_11 ( V_2 , & V_90 , V_73 ) ;
}
void F_79 ( struct V_1 * V_2 , int V_3 , int V_226 )
{
struct V_13 V_35 = {
. V_30 = V_31 ,
. V_71 = V_227 ,
. V_72 = V_227 ,
. V_10 . V_3 = V_3 ,
. V_10 . V_202 = V_228 ,
. V_229 = F_52 ( V_226 ) ,
} ;
F_11 ( V_2 , & V_35 , V_42 ) ;
}
