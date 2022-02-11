static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) )
F_2 ( V_2 ,
L_1 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) {
F_3 ( V_2 ,
L_2
L_3 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
} else {
V_2 -> V_4 [ V_3 ] . V_5 |= V_9 ;
F_3 ( V_2 , L_4 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
}
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 ,
bool V_14 )
{
T_1 V_3 = V_11 -> V_7 . V_3 ;
unsigned long V_15 ;
int V_16 = - V_17 ;
if ( V_13 -> V_18 . V_15 & V_19 ) {
F_2 ( V_2 , L_5 ,
V_13 -> V_18 . V_15 ) ;
return V_16 ;
}
F_5 ( V_2 , L_6 ,
V_3 ) ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
switch ( V_13 -> V_21 . V_22 . V_23 ) {
case V_24 :
F_5 ( V_2 , L_7 ) ;
F_1 ( V_2 , V_3 ) ;
V_16 = 0 ;
break;
case V_25 :
F_2 ( V_2 , L_8 ,
V_3 ) ;
break;
case V_26 :
F_2 ( V_2 ,
L_9 ,
V_3 ) ;
break;
case V_27 :
F_2 ( V_2 , L_10 ,
V_3 ) ;
break;
default:
F_3 ( V_2 , L_11 ,
V_13 -> V_21 . V_22 . V_23 ) ;
break;
}
F_5 ( V_2 , L_12 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_28 ==
V_29 ? L_13 : L_14 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
F_5 ( V_2 , L_15 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_28 ==
V_29 ? L_13 : L_14 ,
V_11 -> V_7 . V_8 ) ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
return V_16 ;
}
static void F_8 ( struct V_1 * V_2 ,
struct V_30 * V_31 ,
struct V_12 * V_13 )
{
struct V_10 * V_11 =
(struct V_10 * ) V_31 -> V_31 . V_32 ;
F_4 ( V_2 , V_11 , V_13 , false ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_10 * V_7 , T_1 V_15 )
{
struct V_12 * V_13 = NULL ;
int V_16 = 0 ;
T_1 V_33 [ sizeof( * V_7 ) ] ;
struct V_34 V_31 = {
. V_35 = V_36 ,
. V_15 = V_15 ,
. V_33 = V_33 ,
} ;
T_1 V_3 V_37 = V_7 -> V_7 . V_3 ;
F_5 ( V_2 , L_16 ,
V_3 , V_7 -> V_7 . V_8 , V_15 & V_38 ? L_17 : L_18 ) ;
if ( V_15 & V_38 )
V_31 . V_39 = F_8 ;
else {
V_31 . V_15 |= V_40 ;
F_10 () ;
}
V_31 . V_41 = V_2 -> V_42 -> V_43 -> V_44 -> V_45 ( V_7 , V_33 ) ;
V_16 = F_11 ( V_2 , & V_31 ) ;
if ( V_16 || ( V_15 & V_38 ) )
return V_16 ;
if ( V_16 == 0 ) {
V_13 = (struct V_12 * ) V_31 . V_46 ;
V_16 = F_4 ( V_2 , V_7 , V_13 , true ) ;
}
F_12 ( V_2 , V_31 . V_46 ) ;
return V_16 ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_47 ,
struct V_48 * V_7 ,
struct V_49 * V_50 )
{
struct V_51 * V_52 = & V_7 -> V_53 ;
T_2 V_54 ;
T_1 V_55 ;
if ( ! V_7 || ! V_52 -> V_56 )
goto V_57;
V_55 = ( V_52 -> V_58 & V_59 ) >> 2 ;
F_3 ( V_2 , L_19 ,
( V_55 == V_60 ) ?
L_20 :
( V_55 == V_61 ) ?
L_21 : L_22 ) ;
V_54 = V_2 -> V_4 [ V_47 ] . V_7 . V_62 ;
V_54 &= ~ ( V_63 | V_64 ) ;
switch ( V_55 ) {
case V_60 :
V_54 |= V_64 ;
break;
case V_61 :
V_54 |= V_63 ;
break;
case V_65 :
break;
default:
F_14 ( V_2 , L_23 , V_55 ) ;
break;
}
V_54 |= F_15 (
( V_66 ) V_52 -> V_67 << V_68 ) ;
V_54 |= F_15 (
( V_66 ) V_52 -> V_69 << V_70 ) ;
if ( F_16 ( V_2 , V_50 , & V_7 -> V_53 ) )
V_54 |= V_71 ;
else
V_54 &= ~ V_71 ;
V_2 -> V_4 [ V_47 ] . V_7 . V_62 = V_54 ;
V_57:
return;
}
T_1 F_17 ( struct V_1 * V_2 , struct V_49 * V_50 ,
const T_1 * V_8 , bool V_72 , struct V_48 * V_7 )
{
struct V_73 * V_74 ;
int V_75 ;
T_1 V_3 = V_76 ;
T_3 V_77 ;
if ( V_72 )
V_3 = V_50 -> V_78 ;
else if ( F_18 ( V_8 ) )
V_3 = V_50 -> V_79 ;
else
for ( V_75 = V_80 ; V_75 < V_2 -> V_81 . V_82 ; V_75 ++ ) {
if ( ! F_19 ( V_2 -> V_4 [ V_75 ] . V_7 . V_7 . V_8 ,
V_8 ) ) {
V_3 = V_75 ;
break;
}
if ( ! V_2 -> V_4 [ V_75 ] . V_5 &&
V_3 == V_76 )
V_3 = V_75 ;
}
if ( F_20 ( V_3 == V_76 ) )
return V_3 ;
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_83 ) {
F_5 ( V_2 ,
L_24 ,
V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) &&
! F_19 ( V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_8 ) ) {
F_3 ( V_2 ,
L_25 ,
V_3 , V_8 ) ;
return V_3 ;
}
V_74 = & V_2 -> V_4 [ V_3 ] ;
V_74 -> V_5 = V_6 ;
F_3 ( V_2 , L_26 ,
V_3 , V_8 ) ;
V_2 -> V_84 ++ ;
memset ( & V_74 -> V_7 , 0 , sizeof( struct V_10 ) ) ;
memcpy ( V_74 -> V_7 . V_7 . V_8 , V_8 , V_85 ) ;
V_74 -> V_7 . V_28 = 0 ;
V_74 -> V_7 . V_7 . V_3 = V_3 ;
V_74 -> V_7 . V_62 = V_50 -> V_62 ;
V_74 -> V_86 = V_50 -> V_86 ;
if ( V_7 ) {
struct V_87 * V_88 ;
V_88 = ( void * ) V_7 -> V_89 ;
V_88 -> V_50 = V_50 ;
}
F_13 ( V_2 , V_3 , V_7 , V_50 ) ;
V_77 = ( V_2 -> V_90 == V_91 ) ?
V_92 : V_93 ;
V_74 -> V_7 . V_94 = F_21 ( V_77 | V_95 ) ;
return V_3 ;
}
int
F_22 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
const T_1 * V_8 , bool V_72 ,
struct V_48 * V_7 , T_1 * V_96 )
{
unsigned long V_97 ;
int V_16 = 0 ;
T_1 V_3 ;
struct V_10 V_98 ;
* V_96 = 0 ;
F_6 ( & V_2 -> V_20 , V_97 ) ;
V_3 = F_17 ( V_2 , V_50 , V_8 , V_72 , V_7 ) ;
if ( V_3 == V_76 ) {
F_2 ( V_2 , L_27 ,
V_8 ) ;
F_7 ( & V_2 -> V_20 , V_97 ) ;
return - V_99 ;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_83 ) {
F_5 ( V_2 ,
L_24 ,
V_3 ) ;
F_7 ( & V_2 -> V_20 , V_97 ) ;
return - V_100 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_3 ( V_2 ,
L_25 ,
V_3 , V_8 ) ;
F_7 ( & V_2 -> V_20 , V_97 ) ;
return - V_100 ;
}
V_2 -> V_4 [ V_3 ] . V_5 |= V_83 ;
memcpy ( & V_98 , & V_2 -> V_4 [ V_3 ] . V_7 ,
sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_20 , V_97 ) ;
V_16 = F_9 ( V_2 , & V_98 , V_101 ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_20 , V_97 ) ;
F_2 ( V_2 , L_28 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_83 ;
F_7 ( & V_2 -> V_20 , V_97 ) ;
}
* V_96 = V_3 ;
return V_16 ;
}
static void F_23 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( V_2 -> V_4 [ V_3 ] . V_5 &
( V_9 | V_6 ) ) !=
V_9 )
F_2 ( V_2 , L_29 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_9 ;
memset ( & V_2 -> V_4 [ V_3 ] , 0 , sizeof( struct V_73 ) ) ;
F_3 ( V_2 , L_30 , V_3 ) ;
}
static int F_24 ( struct V_1 * V_2 ,
const T_1 * V_8 , int V_3 ,
bool V_102 )
{
struct V_12 * V_13 ;
int V_16 ;
unsigned long V_97 ;
struct V_103 V_104 ;
struct V_34 V_31 = {
. V_35 = V_105 ,
. V_41 = sizeof( struct V_103 ) ,
. V_15 = V_101 ,
. V_33 = & V_104 ,
} ;
memset ( & V_104 , 0 , sizeof( V_104 ) ) ;
V_104 . V_106 = 1 ;
memcpy ( & V_104 . V_8 , V_8 , V_85 ) ;
V_31 . V_15 |= V_40 ;
V_16 = F_11 ( V_2 , & V_31 ) ;
if ( V_16 )
return V_16 ;
V_13 = (struct V_12 * ) V_31 . V_46 ;
if ( V_13 -> V_18 . V_15 & V_19 ) {
F_2 ( V_2 , L_31 ,
V_13 -> V_18 . V_15 ) ;
V_16 = - V_17 ;
}
if ( ! V_16 ) {
switch ( V_13 -> V_21 . V_107 . V_23 ) {
case V_108 :
if ( ! V_102 ) {
F_6 ( & V_2 -> V_20 , V_97 ) ;
F_23 ( V_2 , V_3 ) ;
F_7 ( & V_2 -> V_20 ,
V_97 ) ;
}
F_3 ( V_2 , L_32 ) ;
break;
default:
V_16 = - V_17 ;
F_2 ( V_2 , L_33 ) ;
break;
}
}
F_12 ( V_2 , V_31 . V_46 ) ;
return V_16 ;
}
int F_25 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_8 )
{
unsigned long V_15 ;
if ( ! F_26 ( V_2 ) ) {
F_5 ( V_2 ,
L_34 ,
V_8 ) ;
return 0 ;
}
F_3 ( V_2 , L_35 ,
V_3 , V_8 ) ;
if ( F_27 ( V_3 == V_76 ) )
return - V_99 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_5 ( V_2 , L_36 ,
V_8 ) ;
goto V_109;
}
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_5 ( V_2 , L_37 ,
V_8 ) ;
goto V_109;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_110 ) {
F_28 ( V_2 -> V_4 [ V_3 ] . V_111 ) ;
V_2 -> V_4 [ V_3 ] . V_111 = NULL ;
}
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_84 -- ;
F_29 ( V_2 -> V_84 < 0 ) ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
return F_24 ( V_2 , V_8 , V_3 , false ) ;
V_109:
F_7 ( & V_2 -> V_20 , V_15 ) ;
return - V_99 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
int V_75 ;
unsigned long V_97 ;
bool V_112 = false ;
F_5 ( V_2 , L_38 ) ;
F_6 ( & V_2 -> V_20 , V_97 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_81 . V_82 ; V_75 ++ ) {
if ( V_50 && V_50 -> V_86 != V_2 -> V_4 [ V_75 ] . V_86 )
continue;
if ( V_2 -> V_4 [ V_75 ] . V_5 & V_9 ) {
F_5 ( V_2 ,
L_39 , V_75 ) ;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_9 ;
V_112 = true ;
}
}
F_7 ( & V_2 -> V_20 , V_97 ) ;
if ( ! V_112 )
F_5 ( V_2 ,
L_40 ) ;
}
void
F_31 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_10 V_98 ;
struct V_113 V_111 ;
unsigned long V_97 ;
int V_75 ;
bool V_114 = false ;
int V_16 ;
bool V_115 ;
if ( ! F_26 ( V_2 ) ) {
F_5 ( V_2 ,
L_41 ) ;
return;
}
F_3 ( V_2 , L_42 ) ;
F_6 ( & V_2 -> V_20 , V_97 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_81 . V_82 ; V_75 ++ ) {
if ( V_50 -> V_86 != V_2 -> V_4 [ V_75 ] . V_86 )
continue;
if ( ( V_2 -> V_4 [ V_75 ] . V_5 & V_6 ) &&
! ( V_2 -> V_4 [ V_75 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_43 ,
V_2 -> V_4 [ V_75 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_75 ] . V_7 . V_28 = 0 ;
V_2 -> V_4 [ V_75 ] . V_5 |= V_83 ;
V_114 = true ;
}
}
for ( V_75 = 0 ; V_75 < V_2 -> V_81 . V_82 ; V_75 ++ ) {
if ( ( V_2 -> V_4 [ V_75 ] . V_5 & V_83 ) ) {
memcpy ( & V_98 , & V_2 -> V_4 [ V_75 ] . V_7 ,
sizeof( struct V_10 ) ) ;
V_115 = false ;
if ( V_2 -> V_4 [ V_75 ] . V_111 ) {
memcpy ( & V_111 , V_2 -> V_4 [ V_75 ] . V_111 ,
sizeof( struct V_113 ) ) ;
V_115 = true ;
}
F_7 ( & V_2 -> V_20 , V_97 ) ;
V_16 = F_9 ( V_2 , & V_98 , V_101 ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_20 , V_97 ) ;
F_2 ( V_2 , L_28 ,
V_2 -> V_4 [ V_75 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_75 ] . V_5 &=
~ V_6 ;
V_2 -> V_4 [ V_75 ] . V_5 &=
~ V_83 ;
F_7 ( & V_2 -> V_20 ,
V_97 ) ;
}
if ( V_115 )
F_32 ( V_2 , V_50 , & V_111 ,
V_101 , true ) ;
F_6 ( & V_2 -> V_20 , V_97 ) ;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_83 ;
}
}
F_7 ( & V_2 -> V_20 , V_97 ) ;
if ( ! V_114 )
F_5 ( V_2 , L_44
L_45 ) ;
else
F_5 ( V_2 , L_44
L_46 ) ;
}
int F_33 ( struct V_1 * V_2 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_116 ; V_75 ++ )
if ( ! F_34 ( V_75 , & V_2 -> V_117 ) )
return V_75 ;
return V_118 ;
}
void F_35 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
int V_75 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_81 . V_82 ; V_75 ++ ) {
if ( ! ( V_2 -> V_4 [ V_75 ] . V_5 & V_119 ) )
continue;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_9 ;
V_2 -> V_84 -- ;
F_29 ( V_2 -> V_84 < 0 ) ;
F_28 ( V_2 -> V_4 [ V_75 ] . V_111 ) ;
V_2 -> V_4 [ V_75 ] . V_111 = NULL ;
}
F_7 ( & V_2 -> V_20 , V_15 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
struct V_113 * V_111 )
{
int V_75 ;
F_37 ( V_2 , L_47 , V_111 -> V_3 ) ;
F_37 ( V_2 , L_48 ,
V_111 -> V_120 . V_121 ,
V_111 -> V_120 . V_122 ) ;
for ( V_75 = 0 ; V_75 < V_123 ; V_75 ++ )
F_37 ( V_2 , L_49 ,
V_75 , V_111 -> V_124 [ V_75 ] . V_94 ) ;
}
static inline void F_36 ( struct V_1 * V_2 ,
struct V_113 * V_111 )
{
}
static bool F_38 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_113 * V_111 )
{
int V_75 ;
if ( V_50 -> V_125 . V_126 )
return true ;
F_5 ( V_2 , L_50 ,
V_50 -> V_127 . V_128 ) ;
for ( V_75 = 0 ; V_75 < V_123 ; V_75 ++ ) {
if ( F_39 ( V_111 -> V_124 [ V_75 ] . V_94 ) &
V_129 ) {
F_5 ( V_2 ,
L_51 ,
V_75 ) ;
return false ;
}
}
return true ;
}
int F_32 ( struct V_1 * V_2 , struct V_49 * V_50 ,
struct V_113 * V_111 , T_1 V_15 , bool V_130 )
{
int V_16 = 0 ;
unsigned long V_97 ;
struct V_34 V_31 = {
. V_35 = V_131 ,
. V_41 = sizeof( struct V_113 ) ,
. V_15 = V_15 ,
. V_33 = V_111 ,
} ;
if ( F_27 ( V_111 -> V_3 == V_76 ) )
return - V_99 ;
F_6 ( & V_2 -> V_20 , V_97 ) ;
if ( ! ( V_2 -> V_4 [ V_111 -> V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_20 , V_97 ) ;
return - V_99 ;
}
F_7 ( & V_2 -> V_20 , V_97 ) ;
F_36 ( V_2 , V_111 ) ;
F_29 ( V_130 && ( V_31 . V_15 & V_38 ) ) ;
if ( F_38 ( V_2 , V_50 , V_111 ) )
V_16 = F_11 ( V_2 , & V_31 ) ;
else
V_16 = - V_99 ;
if ( V_31 . V_15 & V_38 )
return V_16 ;
if ( V_130 ) {
F_5 ( V_2 , L_52
L_53 ,
V_111 -> V_3 ) ;
F_6 ( & V_2 -> V_20 , V_97 ) ;
V_2 -> V_4 [ V_111 -> V_3 ] . V_5 &= ~ V_83 ;
F_7 ( & V_2 -> V_20 , V_97 ) ;
}
return V_16 ;
}
int F_40 ( struct V_132 * V_133 ,
struct V_134 * V_135 ,
struct V_48 * V_7 )
{
struct V_1 * V_2 = V_133 -> V_2 ;
struct V_87 * V_136 = ( void * ) V_7 -> V_89 ;
int V_16 ;
F_5 ( V_2 , L_54 ,
V_7 -> V_8 ) ;
F_41 ( & V_2 -> V_137 ) ;
F_5 ( V_2 , L_55 ,
V_7 -> V_8 ) ;
V_16 = F_25 ( V_2 , V_136 -> V_3 , V_7 -> V_8 ) ;
if ( V_16 )
F_2 ( V_2 , L_56 ,
V_7 -> V_8 ) ;
F_42 ( & V_2 -> V_137 ) ;
return V_16 ;
}
