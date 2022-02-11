static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) )
F_2 ( V_2 , L_1
L_2 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) {
F_3 ( V_2 ,
L_3
L_4 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
} else {
V_2 -> V_4 [ V_3 ] . V_5 |= V_9 ;
F_3 ( V_2 , L_5 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
}
}
static int F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
T_1 V_3 = V_11 -> V_7 . V_3 ;
unsigned long V_14 ;
int V_15 = - V_16 ;
if ( V_13 -> V_17 . V_14 & V_18 ) {
F_2 ( V_2 , L_6 ,
V_13 -> V_17 . V_14 ) ;
return V_15 ;
}
F_5 ( V_2 , L_7 ,
V_3 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
switch ( V_13 -> V_21 . V_22 . V_23 ) {
case V_24 :
F_5 ( V_2 , L_8 ) ;
F_1 ( V_2 , V_3 ) ;
V_15 = 0 ;
break;
case V_25 :
F_2 ( V_2 , L_9 ,
V_3 ) ;
break;
case V_26 :
F_2 ( V_2 , L_10
L_11 , V_3 ) ;
break;
case V_27 :
F_2 ( V_2 , L_12 ,
V_3 ) ;
break;
default:
F_3 ( V_2 , L_13 ,
V_13 -> V_21 . V_22 . V_23 ) ;
break;
}
F_5 ( V_2 , L_14 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_28 ==
V_29 ? L_15 : L_16 ,
V_3 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
F_5 ( V_2 , L_17 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_28 ==
V_29 ? L_15 : L_16 ,
V_11 -> V_7 . V_8 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return V_15 ;
}
int F_8 ( struct V_1 * V_2 , struct V_30 * V_31 ,
struct V_32 * V_33 )
{
struct V_12 * V_13 = F_9 ( V_31 ) ;
struct V_10 * V_11 =
(struct V_10 * ) V_33 -> V_34 ;
return F_4 ( V_2 , V_11 , V_13 ) ;
}
static T_2 F_10 ( const struct V_10 * V_33 , T_1 * V_35 )
{
T_2 V_36 = ( T_2 ) sizeof( struct V_10 ) ;
struct V_10 * V_11 = (struct V_10 * ) V_35 ;
memcpy ( V_11 , V_33 , V_36 ) ;
V_11 -> V_37 = F_11 ( 0 ) ;
return V_36 ;
}
int F_12 ( struct V_1 * V_2 ,
struct V_10 * V_7 , T_1 V_14 )
{
int V_15 = 0 ;
T_1 V_35 [ sizeof( * V_7 ) ] ;
struct V_38 V_33 = {
. V_39 = V_40 ,
. V_14 = V_14 ,
. V_35 = { V_35 , } ,
} ;
T_1 V_3 V_41 = V_7 -> V_7 . V_3 ;
F_5 ( V_2 , L_18 ,
V_3 , V_7 -> V_7 . V_8 , V_14 & V_42 ? L_19 : L_20 ) ;
if ( ! ( V_14 & V_42 ) ) {
V_33 . V_14 |= V_43 ;
F_13 () ;
}
V_33 . V_44 [ 0 ] = F_10 ( V_7 , V_35 ) ;
V_15 = F_14 ( F_15 ( V_2 ) , & V_33 ) ;
if ( V_15 || ( V_14 & V_42 ) )
return V_15 ;
F_16 ( V_2 -> V_19 , V_33 . V_45 ) ;
if ( V_33 . V_46 )
F_2 ( V_2 , L_21 , V_47 ,
V_33 . V_46 ) ;
return V_33 . V_46 ;
}
static void F_17 ( struct V_1 * V_2 , T_1 V_48 ,
struct V_49 * V_7 ,
struct V_50 * V_51 )
{
struct V_52 * V_53 = & V_7 -> V_54 ;
T_3 V_55 ;
T_1 V_56 ;
if ( ! V_7 || ! V_53 -> V_57 )
goto V_58;
V_56 = ( V_53 -> V_59 & V_60 ) >> 2 ;
F_3 ( V_2 , L_22 ,
( V_56 == V_61 ) ?
L_23 :
( V_56 == V_62 ) ?
L_24 : L_25 ) ;
V_55 = V_2 -> V_4 [ V_48 ] . V_7 . V_63 ;
V_55 &= ~ ( V_64 | V_65 ) ;
switch ( V_56 ) {
case V_61 :
V_55 |= V_65 ;
break;
case V_62 :
V_55 |= V_64 ;
break;
case V_66 :
break;
default:
F_18 ( V_2 , L_26 , V_56 ) ;
break;
}
V_55 |= F_19 (
( V_67 ) V_53 -> V_68 << V_69 ) ;
V_55 |= F_19 (
( V_67 ) V_53 -> V_70 << V_71 ) ;
if ( F_20 ( V_2 , V_51 , & V_7 -> V_54 ) )
V_55 |= V_72 ;
else
V_55 &= ~ V_72 ;
V_2 -> V_4 [ V_48 ] . V_7 . V_63 = V_55 ;
V_58:
return;
}
T_1 F_21 ( struct V_1 * V_2 , struct V_50 * V_51 ,
const T_1 * V_8 , bool V_73 , struct V_49 * V_7 )
{
struct V_74 * V_75 ;
int V_76 ;
T_1 V_3 = V_77 ;
if ( V_73 )
V_3 = V_51 -> V_78 ;
else if ( F_22 ( V_8 ) )
V_3 = V_51 -> V_79 ;
else
for ( V_76 = V_80 ; V_76 < V_81 ; V_76 ++ ) {
if ( ! F_23 ( V_2 -> V_4 [ V_76 ] . V_7 . V_7 . V_8 ,
V_8 ) ) {
V_3 = V_76 ;
break;
}
if ( ! V_2 -> V_4 [ V_76 ] . V_5 &&
V_3 == V_77 )
V_3 = V_76 ;
}
if ( F_24 ( V_3 == V_77 ) )
return V_3 ;
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_82 ) {
F_5 ( V_2 , L_27
L_28 , V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) &&
! F_23 ( V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_8 ) ) {
F_3 ( V_2 , L_29
L_30 , V_3 , V_8 ) ;
return V_3 ;
}
V_75 = & V_2 -> V_4 [ V_3 ] ;
V_75 -> V_5 = V_6 ;
F_3 ( V_2 , L_31 ,
V_3 , V_8 ) ;
V_2 -> V_83 ++ ;
memset ( & V_75 -> V_7 , 0 , sizeof( struct V_10 ) ) ;
memcpy ( V_75 -> V_7 . V_7 . V_8 , V_8 , V_84 ) ;
V_75 -> V_7 . V_28 = 0 ;
V_75 -> V_7 . V_7 . V_3 = V_3 ;
V_75 -> V_7 . V_63 = V_51 -> V_63 ;
V_75 -> V_85 = V_51 -> V_85 ;
if ( V_7 ) {
struct V_86 * V_87 ;
V_87 = ( void * ) V_7 -> V_88 ;
V_87 -> V_51 = V_51 ;
}
F_17 ( V_2 , V_3 , V_7 , V_51 ) ;
return V_3 ;
}
int F_25 ( struct V_1 * V_2 , struct V_50 * V_51 ,
const T_1 * V_8 , bool V_73 ,
struct V_49 * V_7 , T_1 * V_89 )
{
unsigned long V_90 ;
int V_15 = 0 ;
T_1 V_3 ;
struct V_10 V_91 ;
* V_89 = 0 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
V_3 = F_21 ( V_2 , V_51 , V_8 , V_73 , V_7 ) ;
if ( V_3 == V_77 ) {
F_2 ( V_2 , L_32 ,
V_8 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
return - V_92 ;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_82 ) {
F_5 ( V_2 , L_27
L_28 , V_3 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
return - V_93 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_29
L_30 , V_3 , V_8 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
return - V_93 ;
}
V_2 -> V_4 [ V_3 ] . V_5 |= V_82 ;
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 ,
sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
V_15 = F_12 ( V_2 , & V_91 , V_94 ) ;
if ( V_15 ) {
F_6 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
F_2 ( V_2 , L_33 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_82 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
}
* V_89 = V_3 ;
return V_15 ;
}
static void F_26 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( V_2 -> V_4 [ V_3 ] . V_5 &
( V_9 | V_6 ) ) !=
V_9 )
F_2 ( V_2 , L_34 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_9 ;
memset ( & V_2 -> V_4 [ V_3 ] , 0 , sizeof( struct V_74 ) ) ;
F_3 ( V_2 , L_35 , V_3 ) ;
}
static int F_27 ( struct V_1 * V_2 ,
const T_1 * V_8 , int V_3 ,
bool V_95 )
{
struct V_12 * V_13 ;
int V_15 ;
unsigned long V_90 ;
struct V_96 V_97 ;
struct V_38 V_33 = {
. V_39 = V_98 ,
. V_44 = { sizeof( struct V_96 ) , } ,
. V_14 = V_94 ,
. V_35 = { & V_97 , } ,
} ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_99 = 1 ;
memcpy ( & V_97 . V_8 , V_8 , V_84 ) ;
V_33 . V_14 |= V_43 ;
V_15 = F_14 ( F_15 ( V_2 ) , & V_33 ) ;
if ( V_15 )
return V_15 ;
V_13 = (struct V_12 * ) V_33 . V_45 ;
if ( V_13 -> V_17 . V_14 & V_18 ) {
F_2 ( V_2 , L_36 ,
V_13 -> V_17 . V_14 ) ;
V_15 = - V_16 ;
}
if ( ! V_15 ) {
switch ( V_13 -> V_21 . V_100 . V_23 ) {
case V_101 :
if ( ! V_95 ) {
F_6 ( & V_2 -> V_19 -> V_20 ,
V_90 ) ;
F_26 ( V_2 , V_3 ) ;
F_7 ( & V_2 -> V_19 -> V_20 ,
V_90 ) ;
}
F_3 ( V_2 , L_37 ) ;
break;
default:
V_15 = - V_16 ;
F_2 ( V_2 , L_38 ) ;
break;
}
}
F_16 ( V_2 -> V_19 , V_33 . V_45 ) ;
return V_15 ;
}
int F_28 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_8 )
{
unsigned long V_14 ;
if ( ! F_29 ( V_2 -> V_19 ) ) {
F_5 ( V_2 ,
L_39 ,
V_8 ) ;
return 0 ;
}
F_3 ( V_2 , L_40 ,
V_3 , V_8 ) ;
if ( F_30 ( V_3 == V_77 ) )
return - V_92 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_5 ( V_2 , L_41 ,
V_8 ) ;
goto V_102;
}
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_5 ( V_2 , L_42 ,
V_8 ) ;
goto V_102;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_103 ) {
F_31 ( V_2 -> V_4 [ V_3 ] . V_104 ) ;
V_2 -> V_4 [ V_3 ] . V_104 = NULL ;
}
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_83 -- ;
if ( F_30 ( V_2 -> V_83 < 0 ) )
V_2 -> V_83 = 0 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_27 ( V_2 , V_8 , V_3 , false ) ;
V_102:
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return - V_92 ;
}
void F_32 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
int V_76 ;
unsigned long V_90 ;
bool V_105 = false ;
F_5 ( V_2 , L_43 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
for ( V_76 = 0 ; V_76 < V_81 ; V_76 ++ ) {
if ( V_51 && V_51 -> V_85 != V_2 -> V_4 [ V_76 ] . V_85 )
continue;
if ( V_2 -> V_4 [ V_76 ] . V_5 & V_9 ) {
F_5 ( V_2 ,
L_44 , V_76 ) ;
V_2 -> V_4 [ V_76 ] . V_5 &= ~ V_9 ;
V_105 = true ;
}
}
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
if ( ! V_105 )
F_5 ( V_2 ,
L_45 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
struct V_10 V_91 ;
struct V_106 V_104 ;
unsigned long V_90 ;
int V_76 ;
bool V_107 = false ;
int V_15 ;
bool V_108 ;
if ( ! F_29 ( V_2 -> V_19 ) ) {
F_5 ( V_2 ,
L_46 ) ;
return;
}
F_3 ( V_2 , L_47 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
for ( V_76 = 0 ; V_76 < V_81 ; V_76 ++ ) {
if ( V_51 -> V_85 != V_2 -> V_4 [ V_76 ] . V_85 )
continue;
if ( ( V_2 -> V_4 [ V_76 ] . V_5 & V_6 ) &&
! ( V_2 -> V_4 [ V_76 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_48 ,
V_2 -> V_4 [ V_76 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_76 ] . V_7 . V_28 = 0 ;
V_2 -> V_4 [ V_76 ] . V_5 |= V_82 ;
V_107 = true ;
}
}
for ( V_76 = 0 ; V_76 < V_81 ; V_76 ++ ) {
if ( ( V_2 -> V_4 [ V_76 ] . V_5 & V_82 ) ) {
memcpy ( & V_91 , & V_2 -> V_4 [ V_76 ] . V_7 ,
sizeof( struct V_10 ) ) ;
V_108 = false ;
if ( V_2 -> V_4 [ V_76 ] . V_104 ) {
if ( V_2 -> V_19 -> V_109 )
F_34 ( V_2 , V_51 , V_76 , & V_104 ) ;
else
memcpy ( & V_104 , V_2 -> V_4 [ V_76 ] . V_104 ,
sizeof( struct V_106 ) ) ;
V_108 = true ;
}
F_7 ( & V_2 -> V_19 -> V_20 ,
V_90 ) ;
V_15 = F_12 ( V_2 , & V_91 , V_94 ) ;
if ( V_15 ) {
F_6 ( & V_2 -> V_19 -> V_20 ,
V_90 ) ;
F_2 ( V_2 , L_33 ,
V_2 -> V_4 [ V_76 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_76 ] . V_5 &=
~ V_6 ;
V_2 -> V_4 [ V_76 ] . V_5 &=
~ V_82 ;
F_7 ( & V_2 -> V_19 -> V_20 ,
V_90 ) ;
}
if ( V_108 )
F_35 ( V_2 , V_51 , & V_104 ,
V_94 , true ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
V_2 -> V_4 [ V_76 ] . V_5 &= ~ V_82 ;
}
}
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
if ( ! V_107 )
F_5 ( V_2 , L_49
L_50 ) ;
else
F_5 ( V_2 , L_49
L_51 ) ;
}
void F_36 ( struct V_1 * V_2 , struct V_50 * V_51 )
{
unsigned long V_14 ;
int V_3 = V_51 -> V_78 ;
int V_15 ;
struct V_10 V_91 ;
struct V_106 V_104 ;
bool V_110 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return;
}
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_91 ) ) ;
V_91 . V_28 = 0 ;
memcpy ( & V_104 , V_2 -> V_4 [ V_3 ] . V_104 , sizeof( V_104 ) ) ;
V_110 = V_2 -> V_4 [ V_3 ] . V_5 & V_9 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( V_110 ) {
V_15 = F_27 (
V_2 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ,
V_3 , true ) ;
if ( V_15 )
F_2 ( V_2 , L_52 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_15 ) ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_6 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_15 = F_12 ( V_2 , & V_91 , V_94 ) ;
if ( V_15 )
F_2 ( V_2 , L_53 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_15 ) ;
F_35 ( V_2 , V_51 , & V_104 , V_94 , true ) ;
}
int F_37 ( struct V_1 * V_2 )
{
int V_76 ;
for ( V_76 = 0 ; V_76 < V_2 -> V_111 ; V_76 ++ )
if ( ! F_38 ( V_76 , & V_2 -> V_112 ) )
return V_76 ;
return V_113 ;
}
void F_39 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
int V_76 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
for ( V_76 = 0 ; V_76 < V_81 ; V_76 ++ ) {
if ( ! ( V_2 -> V_4 [ V_76 ] . V_5 & V_114 ) )
continue;
V_2 -> V_4 [ V_76 ] . V_5 &= ~ V_9 ;
V_2 -> V_83 -- ;
if ( F_30 ( V_2 -> V_83 < 0 ) )
V_2 -> V_83 = 0 ;
F_31 ( V_2 -> V_4 [ V_76 ] . V_104 ) ;
V_2 -> V_4 [ V_76 ] . V_104 = NULL ;
}
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
}
static void F_40 ( struct V_1 * V_2 ,
struct V_106 * V_104 )
{
int V_76 ;
F_41 ( V_2 , L_54 , V_104 -> V_3 ) ;
F_41 ( V_2 , L_55 ,
V_104 -> V_115 . V_116 ,
V_104 -> V_115 . V_117 ) ;
for ( V_76 = 0 ; V_76 < V_118 ; V_76 ++ )
F_41 ( V_2 , L_56 ,
V_76 , V_104 -> V_119 [ V_76 ] . V_37 ) ;
}
static inline void F_40 ( struct V_1 * V_2 ,
struct V_106 * V_104 )
{
}
static bool F_42 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_106 * V_104 )
{
int V_76 ;
if ( V_51 -> V_120 . V_121 )
return true ;
F_5 ( V_2 , L_57 ,
V_51 -> V_110 . V_122 ) ;
for ( V_76 = 0 ; V_76 < V_118 ; V_76 ++ ) {
if ( F_43 ( V_104 -> V_119 [ V_76 ] . V_37 ) &
V_123 ) {
F_5 ( V_2 ,
L_58 ,
V_76 ) ;
return false ;
}
}
return true ;
}
int F_35 ( struct V_1 * V_2 , struct V_50 * V_51 ,
struct V_106 * V_104 , T_1 V_14 , bool V_124 )
{
int V_15 = 0 ;
unsigned long V_90 ;
struct V_38 V_33 = {
. V_39 = V_125 ,
. V_44 = { sizeof( struct V_106 ) , } ,
. V_14 = V_14 ,
. V_35 = { V_104 , } ,
} ;
if ( F_30 ( V_104 -> V_3 == V_77 ) )
return - V_92 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
if ( ! ( V_2 -> V_4 [ V_104 -> V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
return - V_92 ;
}
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
F_40 ( V_2 , V_104 ) ;
if ( F_30 ( V_124 && ( V_33 . V_14 & V_42 ) ) )
return - V_92 ;
if ( F_42 ( V_2 , V_51 , V_104 ) )
V_15 = F_14 ( F_15 ( V_2 ) , & V_33 ) ;
else
V_15 = - V_92 ;
if ( V_33 . V_14 & V_42 )
return V_15 ;
if ( V_124 ) {
F_5 ( V_2 , L_59
L_60 ,
V_104 -> V_3 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
V_2 -> V_4 [ V_104 -> V_3 ] . V_5 &= ~ V_82 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_90 ) ;
}
return V_15 ;
}
int F_44 ( struct V_126 * V_127 ,
struct V_128 * V_129 ,
struct V_49 * V_7 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_86 * V_87 = ( void * ) V_7 -> V_88 ;
int V_15 ;
F_45 ( V_2 , L_61
L_62 , V_7 -> V_8 ) ;
F_46 ( & V_2 -> V_19 -> V_130 ) ;
F_5 ( V_2 , L_63 ,
V_7 -> V_8 ) ;
V_15 = F_28 ( V_2 , V_87 -> V_3 , V_7 -> V_8 ) ;
if ( V_15 )
F_2 ( V_2 , L_64 ,
V_7 -> V_8 ) ;
F_47 ( & V_2 -> V_19 -> V_130 ) ;
F_45 ( V_2 , L_65 ) ;
return V_15 ;
}
void F_34 ( struct V_1 * V_2 , struct V_50 * V_51 ,
T_1 V_3 , struct V_106 * V_131 )
{
int V_76 , V_132 ;
V_67 V_133 = 0 ;
T_3 V_37 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
memset ( V_131 , 0 , sizeof( * V_131 ) ) ;
if ( V_2 -> V_134 == V_135 )
V_132 = V_136 ;
else if ( V_51 && V_51 -> V_129 && V_51 -> V_129 -> V_137 )
V_132 = V_136 ;
else
V_132 = V_138 ;
if ( V_132 >= V_139 && V_132 <= V_140 )
V_133 |= V_141 ;
V_133 |= F_49 ( F_50 ( V_2 ) . V_142 ) <<
V_143 ;
V_37 = F_51 ( V_144 [ V_132 ] . V_145 , V_133 ) ;
for ( V_76 = 0 ; V_76 < V_118 ; V_76 ++ )
V_131 -> V_119 [ V_76 ] . V_37 = V_37 ;
V_131 -> V_115 . V_116 =
F_49 ( F_50 ( V_2 ) . V_142 ) ;
V_131 -> V_115 . V_117 =
F_50 ( V_2 ) . V_142 &
~ F_49 ( F_50 ( V_2 ) . V_142 ) ;
if ( ! V_131 -> V_115 . V_117 ) {
V_131 -> V_115 . V_117 = V_146 ;
} else if ( F_52 ( F_50 ( V_2 ) . V_142 ) == 2 ) {
V_131 -> V_115 . V_117 =
F_50 ( V_2 ) . V_142 ;
}
V_131 -> V_147 . V_148 =
V_149 ;
V_131 -> V_147 . V_150 =
F_11 ( V_151 ) ;
V_131 -> V_3 = V_3 ;
}
static struct V_106 *
F_53 ( struct V_1 * V_2 , struct V_50 * V_51 ,
T_1 V_3 )
{
struct V_106 * V_131 ;
V_131 = F_54 ( sizeof( struct V_106 ) , V_152 ) ;
if ( ! V_131 ) {
F_2 ( V_2 , L_66 ) ;
return NULL ;
}
F_34 ( V_2 , V_51 , V_3 , V_131 ) ;
return V_131 ;
}
int F_55 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
const T_1 * V_8 , T_1 * V_89 )
{
int V_15 ;
T_1 V_3 ;
struct V_106 * V_131 ;
unsigned long V_14 ;
if ( V_89 )
* V_89 = V_77 ;
V_15 = F_25 ( V_2 , V_51 , V_8 , 0 , NULL , & V_3 ) ;
if ( V_15 ) {
F_2 ( V_2 , L_67 , V_8 ) ;
return V_15 ;
}
if ( V_89 )
* V_89 = V_3 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_103 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_131 = F_53 ( V_2 , V_51 , V_3 ) ;
if ( ! V_131 ) {
F_2 ( V_2 ,
L_68 ,
V_8 ) ;
return - V_153 ;
}
V_15 = F_35 ( V_2 , V_51 , V_131 , V_94 , true ) ;
if ( V_15 )
F_2 ( V_2 , L_69 , V_15 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_104 = V_131 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
bool V_154 )
{
int V_76 , V_155 = 0 ;
T_1 V_156 [ sizeof( struct V_157 ) +
sizeof( struct V_158 ) * V_159 ] ;
struct V_157 * V_160 = (struct V_157 * ) V_156 ;
T_4 V_161 = sizeof( struct V_157 ) ;
struct V_38 V_33 = {
. V_39 = V_51 -> V_162 ,
. V_35 = { V_160 , } ,
. V_14 = V_94 ,
} ;
F_13 () ;
memset ( V_160 , 0 , V_161 +
( sizeof( struct V_158 ) * V_159 ) ) ;
for ( V_76 = 0 ; V_76 < V_159 ; V_76 ++ ) {
V_160 -> V_163 [ V_76 ] . V_164 = V_76 ;
if ( V_51 -> V_165 [ V_76 ] . V_166 ) {
V_160 -> V_163 [ V_76 ] . V_167 = V_76 ;
V_155 = 1 ;
} else {
V_160 -> V_163 [ V_76 ] . V_167 = V_113 ;
}
V_160 -> V_163 [ V_76 ] . V_166 = V_51 -> V_165 [ V_76 ] . V_166 ;
memcpy ( & V_160 -> V_163 [ V_76 ] . V_163 [ 3 ] , V_51 -> V_165 [ V_76 ] . V_163 ,
V_51 -> V_165 [ V_76 ] . V_166 ) ;
}
V_160 -> V_168 = V_169 ;
V_160 -> V_170 = V_159 ;
V_161 += sizeof( struct V_158 ) * V_159 ;
V_33 . V_44 [ 0 ] = V_161 ;
if ( V_155 || V_154 )
return F_14 ( F_15 ( V_2 ) , & V_33 ) ;
else
return 0 ;
}
int F_57 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
F_48 ( & V_2 -> V_19 -> V_130 ) ;
return F_56 ( V_2 , V_51 , false ) ;
}
int F_58 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_171 * V_172 )
{
int V_15 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
F_59 ( V_2 , L_70 ,
V_172 -> V_173 ) ;
memset ( & V_51 -> V_165 [ V_172 -> V_173 ] , 0 , sizeof( V_51 -> V_165 [ 0 ] ) ) ;
if ( F_60 ( V_2 -> V_19 ) ) {
F_59 ( V_2 ,
L_71 ) ;
return 0 ;
}
V_15 = F_56 ( V_2 , V_51 , 1 ) ;
F_59 ( V_2 , L_72 ,
V_172 -> V_173 , V_15 ) ;
return V_15 ;
}
int F_61 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_171 * V_172 )
{
int V_15 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
if ( V_172 -> V_174 != V_175 &&
V_172 -> V_174 != V_176 ) {
F_59 ( V_2 ,
L_73 , V_172 -> V_174 ) ;
return - V_92 ;
}
V_172 -> V_177 = V_178 ;
V_51 -> V_165 [ V_172 -> V_173 ] . V_166 = V_172 -> V_174 ;
memcpy ( & V_51 -> V_165 [ V_172 -> V_173 ] . V_163 , & V_172 -> V_163 ,
V_172 -> V_174 ) ;
V_15 = F_56 ( V_2 , V_51 , false ) ;
F_59 ( V_2 , L_74 ,
V_172 -> V_174 , V_172 -> V_173 , V_15 ) ;
return V_15 ;
}
static T_1 F_62 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
struct V_49 * V_7 )
{
struct V_179 * V_180 = ( void * ) V_129 -> V_88 ;
T_1 V_3 = V_77 ;
if ( V_7 )
V_3 = F_63 ( V_7 ) ;
if ( ! V_7 && V_129 && V_180 -> V_51 ) {
switch ( V_129 -> type ) {
case V_181 :
V_3 = V_180 -> V_51 -> V_78 ;
break;
default:
break;
}
}
return V_3 ;
}
static int F_64 ( struct V_1 * V_2 ,
struct V_171 * V_172 ,
T_1 V_3 , V_67 V_182 , T_2 * V_183 ,
V_67 V_184 )
{
unsigned long V_14 ;
T_5 V_185 ;
struct V_10 V_91 ;
int V_76 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_91 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_185 = F_11 ( V_172 -> V_173 << V_186 ) ;
V_185 |= V_187 ;
switch ( V_172 -> V_188 ) {
case V_189 :
V_185 |= V_190 ;
memcpy ( V_91 . V_163 . V_163 , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
case V_191 :
V_185 |= V_192 ;
V_91 . V_163 . V_193 = V_182 ;
for ( V_76 = 0 ; V_76 < 5 ; V_76 ++ )
V_91 . V_163 . V_194 [ V_76 ] = F_11 ( V_183 [ V_76 ] ) ;
memcpy ( V_91 . V_163 . V_163 , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
case V_195 :
V_185 |= V_196 ;
case V_197 :
V_185 |= V_198 ;
memcpy ( & V_91 . V_163 . V_163 [ 3 ] , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
default:
F_30 ( 1 ) ;
return - V_92 ;
}
if ( ! ( V_172 -> V_14 & V_199 ) )
V_185 |= V_200 ;
V_91 . V_163 . V_167 = V_172 -> V_177 ;
V_91 . V_163 . V_185 = V_185 ;
V_91 . V_28 = V_29 ;
V_91 . V_7 . V_201 = V_202 ;
return F_12 ( V_2 , & V_91 , V_184 ) ;
}
void F_65 ( struct V_1 * V_2 ,
struct V_128 * V_129 ,
struct V_171 * V_172 ,
struct V_49 * V_7 , V_67 V_203 , T_2 * V_204 )
{
T_1 V_3 = F_62 ( V_2 , V_129 , V_7 ) ;
if ( V_3 == V_77 )
return;
if ( F_66 ( V_2 ) ) {
return;
}
F_64 ( V_2 , V_172 , V_3 ,
V_203 , V_204 , V_42 ) ;
}
int F_67 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_171 * V_172 ,
struct V_49 * V_7 )
{
unsigned long V_14 ;
struct V_10 V_91 ;
T_1 V_3 = F_62 ( V_2 , V_51 -> V_129 , V_7 ) ;
if ( V_3 == V_77 )
return - V_205 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_91 ) ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) )
V_3 = V_77 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( V_3 == V_77 )
return 0 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
V_51 -> V_206 -- ;
F_59 ( V_2 , L_75 ,
V_172 -> V_173 , V_3 ) ;
if ( ! F_68 ( V_172 -> V_177 , & V_2 -> V_112 ) )
F_2 ( V_2 , L_76 ,
V_172 -> V_177 ) ;
V_91 . V_163 . V_185 = V_207 | V_208 ;
V_91 . V_163 . V_167 = V_113 ;
V_91 . V_7 . V_201 = V_202 ;
V_91 . V_28 = V_29 ;
return F_12 ( V_2 , & V_91 , V_94 ) ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_50 * V_51 ,
struct V_171 * V_172 ,
struct V_49 * V_7 )
{
struct V_209 V_210 ;
T_2 V_211 [ 5 ] ;
int V_15 ;
T_1 V_3 = F_62 ( V_2 , V_51 -> V_129 , V_7 ) ;
const T_1 * V_8 ;
if ( V_3 == V_77 )
return - V_92 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
V_172 -> V_177 = F_37 ( V_2 ) ;
if ( V_172 -> V_177 == V_113 )
return - V_212 ;
V_51 -> V_206 ++ ;
switch ( V_172 -> V_188 ) {
case V_191 :
if ( V_7 )
V_8 = V_7 -> V_8 ;
else
V_8 = V_51 -> V_110 . V_213 ;
F_70 ( V_172 , 0 , & V_210 ) ;
F_71 ( V_172 , V_8 , V_210 . V_214 . V_203 , V_211 ) ;
V_15 = F_64 ( V_2 , V_172 , V_3 ,
V_210 . V_214 . V_203 , V_211 , V_94 ) ;
break;
case V_189 :
case V_197 :
case V_195 :
V_15 = F_64 ( V_2 , V_172 , V_3 ,
0 , NULL , V_94 ) ;
break;
default:
F_2 ( V_2 , L_77 , V_172 -> V_188 ) ;
V_15 = - V_92 ;
}
if ( V_15 ) {
V_51 -> V_206 -- ;
F_72 ( V_172 -> V_177 , & V_2 -> V_112 ) ;
}
F_59 ( V_2 , L_78 ,
V_172 -> V_188 , V_172 -> V_174 , V_172 -> V_173 ,
V_7 ? V_7 -> V_8 : NULL , V_15 ) ;
return V_15 ;
}
int F_73 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
struct V_106 * V_131 ;
unsigned long V_14 ;
T_1 V_3 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_3 = F_21 ( V_2 , V_51 , V_215 , false , NULL ) ;
if ( V_3 == V_77 ) {
F_2 ( V_2 , L_79 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return - V_92 ;
}
V_2 -> V_4 [ V_3 ] . V_5 |= V_6 ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_114 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_131 = F_53 ( V_2 , V_51 , V_3 ) ;
if ( ! V_131 ) {
F_2 ( V_2 ,
L_80 ) ;
return - V_153 ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_104 = V_131 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return 0 ;
}
int F_74 ( struct V_1 * V_2 ,
struct V_50 * V_51 )
{
unsigned long V_14 ;
struct V_106 * V_131 ;
T_1 V_3 = V_51 -> V_79 ;
V_131 = F_53 ( V_2 , V_51 , V_3 ) ;
if ( ! V_131 ) {
F_2 ( V_2 , L_80 ) ;
return - V_153 ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( V_2 -> V_4 [ V_3 ] . V_104 )
F_31 ( V_2 -> V_4 [ V_3 ] . V_104 ) ;
else
F_5 ( V_2 , L_81 ) ;
V_2 -> V_4 [ V_3 ] . V_104 = V_131 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return 0 ;
}
int F_75 ( struct V_1 * V_2 )
{
struct V_50 * V_51 ;
int V_15 = 0 ;
F_76 (priv, ctx) {
V_15 = F_74 ( V_2 , V_51 ) ;
if ( V_15 )
break;
}
return V_15 ;
}
int F_77 ( struct V_1 * V_2 , int V_3 , int V_216 )
{
unsigned long V_14 ;
struct V_10 V_91 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_201 = V_217 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_218 &= F_11 ( ~ ( 1 << V_216 ) ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_12 ( V_2 , & V_91 , V_94 ) ;
}
int F_78 ( struct V_1 * V_2 , struct V_49 * V_7 ,
int V_216 , T_2 V_219 )
{
unsigned long V_14 ;
int V_3 ;
struct V_10 V_91 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
V_3 = F_63 ( V_7 ) ;
if ( V_3 == V_77 )
return - V_220 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_221 = 0 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_201 = V_222 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_223 = ( T_1 ) V_216 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_224 = F_11 ( V_219 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_12 ( V_2 , & V_91 , V_94 ) ;
}
int F_79 ( struct V_1 * V_2 , struct V_49 * V_7 ,
int V_216 )
{
unsigned long V_14 ;
int V_3 ;
struct V_10 V_91 ;
F_48 ( & V_2 -> V_19 -> V_130 ) ;
V_3 = F_63 ( V_7 ) ;
if ( V_3 == V_77 ) {
F_2 ( V_2 , L_82 , V_216 ) ;
return - V_220 ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_221 = 0 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_201 = V_225 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_226 = ( T_1 ) V_216 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
memcpy ( & V_91 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_12 ( V_2 , & V_91 , V_94 ) ;
}
static void F_80 ( struct V_1 * V_2 , int V_3 )
{
unsigned long V_14 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_63 &= ~ V_227 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_221 = V_227 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_201 = 0 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_228 = 0 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
F_12 ( V_2 , & V_2 -> V_4 [ V_3 ] . V_7 , V_42 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
}
void F_81 ( struct V_1 * V_2 , int V_3 , int V_229 )
{
unsigned long V_14 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_63 |= V_227 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_221 = V_227 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_201 =
V_230 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_228 = F_11 ( V_229 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
F_12 ( V_2 , & V_2 -> V_4 [ V_3 ] . V_7 , V_42 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
}
void F_82 ( struct V_126 * V_127 ,
struct V_128 * V_129 ,
enum V_231 V_33 ,
struct V_49 * V_7 )
{
struct V_1 * V_2 = V_127 -> V_2 ;
struct V_86 * V_87 = ( void * ) V_7 -> V_88 ;
int V_3 ;
F_45 ( V_2 , L_83 ) ;
switch ( V_33 ) {
case V_232 :
F_30 ( ! V_87 -> V_233 ) ;
V_87 -> V_234 = true ;
if ( F_83 ( & V_87 -> V_235 ) > 0 )
F_84 ( V_127 , V_7 , true ) ;
break;
case V_236 :
F_30 ( ! V_87 -> V_233 ) ;
if ( ! V_87 -> V_234 )
break;
V_87 -> V_234 = false ;
V_3 = F_63 ( V_7 ) ;
if ( V_3 != V_77 )
F_80 ( V_2 , V_3 ) ;
break;
default:
break;
}
F_45 ( V_2 , L_65 ) ;
}
