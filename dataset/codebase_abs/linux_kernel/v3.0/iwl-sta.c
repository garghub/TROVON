static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) )
F_2 ( V_2 , L_1 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) {
F_3 ( V_2 ,
L_2 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
} else {
V_2 -> V_4 [ V_3 ] . V_5 |= V_9 ;
F_3 ( V_2 , L_3 ,
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
F_2 ( V_2 , L_4 ,
V_13 -> V_18 . V_15 ) ;
return V_16 ;
}
F_5 ( V_2 , L_5 ,
V_3 ) ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
switch ( V_13 -> V_21 . V_22 . V_23 ) {
case V_24 :
F_5 ( V_2 , L_6 ) ;
F_1 ( V_2 , V_3 ) ;
V_16 = 0 ;
break;
case V_25 :
F_2 ( V_2 , L_7 ,
V_3 ) ;
break;
case V_26 :
F_2 ( V_2 , L_8 ,
V_3 ) ;
break;
case V_27 :
F_2 ( V_2 , L_9 ,
V_3 ) ;
break;
default:
F_3 ( V_2 , L_10 ,
V_13 -> V_21 . V_22 . V_23 ) ;
break;
}
F_5 ( V_2 , L_11 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_28 ==
V_29 ? L_12 : L_13 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
F_5 ( V_2 , L_14 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_28 ==
V_29 ? L_12 : L_13 ,
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
. V_33 = { V_33 , } ,
} ;
T_1 V_3 V_37 = V_7 -> V_7 . V_3 ;
F_5 ( V_2 , L_15 ,
V_3 , V_7 -> V_7 . V_8 , V_15 & V_38 ? L_16 : L_17 ) ;
if ( V_15 & V_38 )
V_31 . V_39 = F_8 ;
else {
V_31 . V_15 |= V_40 ;
F_10 () ;
}
V_31 . V_41 [ 0 ] = V_2 -> V_42 -> V_43 -> V_44 -> V_45 ( V_7 , V_33 ) ;
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
F_3 ( V_2 , L_18 ,
( V_55 == V_60 ) ?
L_19 :
( V_55 == V_61 ) ?
L_20 : L_21 ) ;
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
F_14 ( V_2 , L_22 , V_55 ) ;
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
if ( V_72 )
V_3 = V_50 -> V_77 ;
else if ( F_18 ( V_8 ) )
V_3 = V_50 -> V_78 ;
else
for ( V_75 = V_79 ; V_75 < V_2 -> V_80 . V_81 ; V_75 ++ ) {
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
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_82 ) {
F_5 ( V_2 , L_23 ,
V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) &&
! F_19 ( V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_8 ) ) {
F_3 ( V_2 , L_24 ,
V_3 , V_8 ) ;
return V_3 ;
}
V_74 = & V_2 -> V_4 [ V_3 ] ;
V_74 -> V_5 = V_6 ;
F_3 ( V_2 , L_25 ,
V_3 , V_8 ) ;
V_2 -> V_83 ++ ;
memset ( & V_74 -> V_7 , 0 , sizeof( struct V_10 ) ) ;
memcpy ( V_74 -> V_7 . V_7 . V_8 , V_8 , V_84 ) ;
V_74 -> V_7 . V_28 = 0 ;
V_74 -> V_7 . V_7 . V_3 = V_3 ;
V_74 -> V_7 . V_62 = V_50 -> V_62 ;
V_74 -> V_85 = V_50 -> V_85 ;
if ( V_7 ) {
struct V_86 * V_87 ;
V_87 = ( void * ) V_7 -> V_88 ;
V_87 -> V_50 = V_50 ;
}
F_13 ( V_2 , V_3 , V_7 , V_50 ) ;
return V_3 ;
}
int F_21 ( struct V_1 * V_2 , struct V_49 * V_50 ,
const T_1 * V_8 , bool V_72 ,
struct V_48 * V_7 , T_1 * V_89 )
{
unsigned long V_90 ;
int V_16 = 0 ;
T_1 V_3 ;
struct V_10 V_91 ;
* V_89 = 0 ;
F_6 ( & V_2 -> V_20 , V_90 ) ;
V_3 = F_17 ( V_2 , V_50 , V_8 , V_72 , V_7 ) ;
if ( V_3 == V_76 ) {
F_2 ( V_2 , L_26 ,
V_8 ) ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
return - V_92 ;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_82 ) {
F_5 ( V_2 , L_23 ,
V_3 ) ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
return - V_93 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_24 ,
V_3 , V_8 ) ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
return - V_93 ;
}
V_2 -> V_4 [ V_3 ] . V_5 |= V_82 ;
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
V_16 = F_9 ( V_2 , & V_91 , V_94 ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_20 , V_90 ) ;
F_2 ( V_2 , L_27 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_82 ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
}
* V_89 = V_3 ;
return V_16 ;
}
static void F_22 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( V_2 -> V_4 [ V_3 ] . V_5 &
( V_9 | V_6 ) ) != V_9 )
F_2 ( V_2 , L_28 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_9 ;
memset ( & V_2 -> V_4 [ V_3 ] , 0 , sizeof( struct V_73 ) ) ;
F_3 ( V_2 , L_29 , V_3 ) ;
}
static int F_23 ( struct V_1 * V_2 ,
const T_1 * V_8 , int V_3 ,
bool V_95 )
{
struct V_12 * V_13 ;
int V_16 ;
unsigned long V_90 ;
struct V_96 V_97 ;
struct V_34 V_31 = {
. V_35 = V_98 ,
. V_41 = { sizeof( struct V_96 ) , } ,
. V_15 = V_94 ,
. V_33 = { & V_97 , } ,
} ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_99 = 1 ;
memcpy ( & V_97 . V_8 , V_8 , V_84 ) ;
V_31 . V_15 |= V_40 ;
V_16 = F_11 ( V_2 , & V_31 ) ;
if ( V_16 )
return V_16 ;
V_13 = (struct V_12 * ) V_31 . V_46 ;
if ( V_13 -> V_18 . V_15 & V_19 ) {
F_2 ( V_2 , L_30 ,
V_13 -> V_18 . V_15 ) ;
V_16 = - V_17 ;
}
if ( ! V_16 ) {
switch ( V_13 -> V_21 . V_100 . V_23 ) {
case V_101 :
if ( ! V_95 ) {
F_6 ( & V_2 -> V_20 , V_90 ) ;
F_22 ( V_2 , V_3 ) ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
}
F_3 ( V_2 , L_31 ) ;
break;
default:
V_16 = - V_17 ;
F_2 ( V_2 , L_32 ) ;
break;
}
}
F_12 ( V_2 , V_31 . V_46 ) ;
return V_16 ;
}
int F_24 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_8 )
{
unsigned long V_15 ;
if ( ! F_25 ( V_2 ) ) {
F_5 ( V_2 ,
L_33 ,
V_8 ) ;
return 0 ;
}
F_3 ( V_2 , L_34 ,
V_3 , V_8 ) ;
if ( F_26 ( V_3 == V_76 ) )
return - V_92 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_5 ( V_2 , L_35 ,
V_8 ) ;
goto V_102;
}
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_5 ( V_2 , L_36 ,
V_8 ) ;
goto V_102;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_103 ) {
F_27 ( V_2 -> V_4 [ V_3 ] . V_104 ) ;
V_2 -> V_4 [ V_3 ] . V_104 = NULL ;
}
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_83 -- ;
if ( F_26 ( V_2 -> V_83 < 0 ) )
V_2 -> V_83 = 0 ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
return F_23 ( V_2 , V_8 , V_3 , false ) ;
V_102:
F_7 ( & V_2 -> V_20 , V_15 ) ;
return - V_92 ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_49 * V_50 )
{
int V_75 ;
unsigned long V_90 ;
bool V_105 = false ;
F_5 ( V_2 , L_37 ) ;
F_6 ( & V_2 -> V_20 , V_90 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_80 . V_81 ; V_75 ++ ) {
if ( V_50 && V_50 -> V_85 != V_2 -> V_4 [ V_75 ] . V_85 )
continue;
if ( V_2 -> V_4 [ V_75 ] . V_5 & V_9 ) {
F_5 ( V_2 , L_38 , V_75 ) ;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_9 ;
V_105 = true ;
}
}
F_7 ( & V_2 -> V_20 , V_90 ) ;
if ( ! V_105 )
F_5 ( V_2 , L_39 ) ;
}
void F_29 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
struct V_10 V_91 ;
struct V_106 V_104 ;
unsigned long V_90 ;
int V_75 ;
bool V_107 = false ;
int V_16 ;
bool V_108 ;
if ( ! F_25 ( V_2 ) ) {
F_5 ( V_2 , L_40 ) ;
return;
}
F_3 ( V_2 , L_41 ) ;
F_6 ( & V_2 -> V_20 , V_90 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_80 . V_81 ; V_75 ++ ) {
if ( V_50 -> V_85 != V_2 -> V_4 [ V_75 ] . V_85 )
continue;
if ( ( V_2 -> V_4 [ V_75 ] . V_5 & V_6 ) &&
! ( V_2 -> V_4 [ V_75 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_42 ,
V_2 -> V_4 [ V_75 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_75 ] . V_7 . V_28 = 0 ;
V_2 -> V_4 [ V_75 ] . V_5 |= V_82 ;
V_107 = true ;
}
}
for ( V_75 = 0 ; V_75 < V_2 -> V_80 . V_81 ; V_75 ++ ) {
if ( ( V_2 -> V_4 [ V_75 ] . V_5 & V_82 ) ) {
memcpy ( & V_91 , & V_2 -> V_4 [ V_75 ] . V_7 ,
sizeof( struct V_10 ) ) ;
V_108 = false ;
if ( V_2 -> V_4 [ V_75 ] . V_104 ) {
memcpy ( & V_104 , V_2 -> V_4 [ V_75 ] . V_104 ,
sizeof( struct V_106 ) ) ;
V_108 = true ;
}
F_7 ( & V_2 -> V_20 , V_90 ) ;
V_16 = F_9 ( V_2 , & V_91 , V_94 ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_20 , V_90 ) ;
F_2 ( V_2 , L_27 ,
V_2 -> V_4 [ V_75 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_6 ;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_82 ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
}
if ( V_108 )
F_30 ( V_2 , V_50 , & V_104 , V_94 , true ) ;
F_6 ( & V_2 -> V_20 , V_90 ) ;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_82 ;
}
}
F_7 ( & V_2 -> V_20 , V_90 ) ;
if ( ! V_107 )
F_5 ( V_2 , L_43 ) ;
else
F_5 ( V_2 , L_44 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_49 * V_50 )
{
unsigned long V_15 ;
int V_3 = V_50 -> V_77 ;
int V_16 ;
struct V_10 V_91 ;
struct V_106 V_104 ;
bool V_109 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_20 , V_15 ) ;
return;
}
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_91 ) ) ;
V_91 . V_28 = 0 ;
memcpy ( & V_104 , V_2 -> V_4 [ V_3 ] . V_104 , sizeof( V_104 ) ) ;
V_109 = V_2 -> V_4 [ V_3 ] . V_5 & V_9 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
if ( V_109 ) {
V_16 = F_23 (
V_2 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ,
V_3 , true ) ;
if ( V_16 )
F_2 ( V_2 , L_45 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_16 ) ;
}
F_6 ( & V_2 -> V_20 , V_15 ) ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_6 ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
V_16 = F_9 ( V_2 , & V_91 , V_94 ) ;
if ( V_16 )
F_2 ( V_2 , L_46 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_16 ) ;
F_30 ( V_2 , V_50 , & V_104 , V_94 , true ) ;
}
int F_32 ( struct V_1 * V_2 )
{
int V_75 ;
for ( V_75 = 0 ; V_75 < V_2 -> V_110 ; V_75 ++ )
if ( ! F_33 ( V_75 , & V_2 -> V_111 ) )
return V_75 ;
return V_112 ;
}
void F_34 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
int V_75 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
for ( V_75 = 0 ; V_75 < V_2 -> V_80 . V_81 ; V_75 ++ ) {
if ( ! ( V_2 -> V_4 [ V_75 ] . V_5 & V_113 ) )
continue;
V_2 -> V_4 [ V_75 ] . V_5 &= ~ V_9 ;
V_2 -> V_83 -- ;
if ( F_26 ( V_2 -> V_83 < 0 ) )
V_2 -> V_83 = 0 ;
F_27 ( V_2 -> V_4 [ V_75 ] . V_104 ) ;
V_2 -> V_4 [ V_75 ] . V_104 = NULL ;
}
F_7 ( & V_2 -> V_20 , V_15 ) ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_106 * V_104 )
{
int V_75 ;
F_36 ( V_2 , L_47 , V_104 -> V_3 ) ;
F_36 ( V_2 , L_48 ,
V_104 -> V_114 . V_115 ,
V_104 -> V_114 . V_116 ) ;
for ( V_75 = 0 ; V_75 < V_117 ; V_75 ++ )
F_36 ( V_2 , L_49 ,
V_75 , V_104 -> V_118 [ V_75 ] . V_119 ) ;
}
static inline void F_35 ( struct V_1 * V_2 ,
struct V_106 * V_104 )
{
}
static bool F_37 ( struct V_1 * V_2 ,
struct V_49 * V_50 ,
struct V_106 * V_104 )
{
int V_75 ;
if ( V_50 -> V_120 . V_121 )
return true ;
F_5 ( V_2 , L_50 ,
V_50 -> V_109 . V_122 ) ;
for ( V_75 = 0 ; V_75 < V_117 ; V_75 ++ ) {
if ( F_38 ( V_104 -> V_118 [ V_75 ] . V_119 ) & V_123 ) {
F_5 ( V_2 ,
L_51 ,
V_75 ) ;
return false ;
}
}
return true ;
}
int F_30 ( struct V_1 * V_2 , struct V_49 * V_50 ,
struct V_106 * V_104 , T_1 V_15 , bool V_124 )
{
int V_16 = 0 ;
unsigned long V_90 ;
struct V_34 V_31 = {
. V_35 = V_125 ,
. V_41 = { sizeof( struct V_106 ) , } ,
. V_15 = V_15 ,
. V_33 = { V_104 , } ,
} ;
if ( F_26 ( V_104 -> V_3 == V_76 ) )
return - V_92 ;
F_6 ( & V_2 -> V_20 , V_90 ) ;
if ( ! ( V_2 -> V_4 [ V_104 -> V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_20 , V_90 ) ;
return - V_92 ;
}
F_7 ( & V_2 -> V_20 , V_90 ) ;
F_35 ( V_2 , V_104 ) ;
if ( F_26 ( V_124 && ( V_31 . V_15 & V_38 ) ) )
return - V_92 ;
if ( F_37 ( V_2 , V_50 , V_104 ) )
V_16 = F_11 ( V_2 , & V_31 ) ;
else
V_16 = - V_92 ;
if ( V_31 . V_15 & V_38 )
return V_16 ;
if ( V_124 ) {
F_5 ( V_2 , L_52 ,
V_104 -> V_3 ) ;
F_6 ( & V_2 -> V_20 , V_90 ) ;
V_2 -> V_4 [ V_104 -> V_3 ] . V_5 &= ~ V_82 ;
F_7 ( & V_2 -> V_20 , V_90 ) ;
}
return V_16 ;
}
int F_39 ( struct V_126 * V_127 ,
struct V_128 * V_129 ,
struct V_48 * V_7 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_86 * V_130 = ( void * ) V_7 -> V_88 ;
int V_16 ;
F_5 ( V_2 , L_53 ,
V_7 -> V_8 ) ;
F_40 ( & V_2 -> V_131 ) ;
F_5 ( V_2 , L_54 ,
V_7 -> V_8 ) ;
V_16 = F_24 ( V_2 , V_130 -> V_3 , V_7 -> V_8 ) ;
if ( V_16 )
F_2 ( V_2 , L_55 ,
V_7 -> V_8 ) ;
F_41 ( & V_2 -> V_131 ) ;
return V_16 ;
}
