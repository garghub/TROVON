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
int F_10 ( struct V_1 * V_2 ,
struct V_10 * V_7 , T_1 V_14 )
{
int V_15 = 0 ;
struct V_35 V_33 = {
. V_36 = V_37 ,
. V_14 = V_14 ,
. V_38 = { V_7 , } ,
. V_39 = { sizeof( * V_7 ) , } ,
} ;
T_1 V_3 V_40 = V_7 -> V_7 . V_3 ;
F_5 ( V_2 , L_18 ,
V_3 , V_7 -> V_7 . V_8 , V_14 & V_41 ? L_19 : L_20 ) ;
if ( ! ( V_14 & V_41 ) ) {
V_33 . V_14 |= V_42 ;
F_11 () ;
}
V_15 = F_12 ( F_13 ( V_2 ) , & V_33 ) ;
if ( V_15 || ( V_14 & V_41 ) )
return V_15 ;
F_14 ( V_2 -> V_19 , V_33 . V_43 ) ;
if ( V_33 . V_44 )
F_2 ( V_2 , L_21 , V_45 ,
V_33 . V_44 ) ;
return V_33 . V_44 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_46 ,
struct V_47 * V_7 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = & V_7 -> V_52 ;
T_2 V_53 ;
T_1 V_54 ;
if ( ! V_7 || ! V_51 -> V_55 )
goto V_56;
V_54 = ( V_51 -> V_57 & V_58 ) >> 2 ;
F_3 ( V_2 , L_22 ,
( V_54 == V_59 ) ?
L_23 :
( V_54 == V_60 ) ?
L_24 : L_25 ) ;
V_53 = V_2 -> V_4 [ V_46 ] . V_7 . V_61 ;
V_53 &= ~ ( V_62 | V_63 ) ;
switch ( V_54 ) {
case V_59 :
V_53 |= V_63 ;
break;
case V_60 :
V_53 |= V_62 ;
break;
case V_64 :
break;
default:
F_16 ( V_2 , L_26 , V_54 ) ;
break;
}
V_53 |= F_17 (
( V_65 ) V_51 -> V_66 << V_67 ) ;
V_53 |= F_17 (
( V_65 ) V_51 -> V_68 << V_69 ) ;
if ( F_18 ( V_2 , V_49 , & V_7 -> V_52 ) )
V_53 |= V_70 ;
else
V_53 &= ~ V_70 ;
V_2 -> V_4 [ V_46 ] . V_7 . V_61 = V_53 ;
V_56:
return;
}
T_1 F_19 ( struct V_1 * V_2 , struct V_48 * V_49 ,
const T_1 * V_8 , bool V_71 , struct V_47 * V_7 )
{
struct V_72 * V_73 ;
int V_74 ;
T_1 V_3 = V_75 ;
if ( V_71 )
V_3 = V_49 -> V_76 ;
else if ( F_20 ( V_8 ) )
V_3 = V_49 -> V_77 ;
else
for ( V_74 = V_78 ; V_74 < V_79 ; V_74 ++ ) {
if ( ! F_21 ( V_2 -> V_4 [ V_74 ] . V_7 . V_7 . V_8 ,
V_8 ) ) {
V_3 = V_74 ;
break;
}
if ( ! V_2 -> V_4 [ V_74 ] . V_5 &&
V_3 == V_75 )
V_3 = V_74 ;
}
if ( F_22 ( V_3 == V_75 ) )
return V_3 ;
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_80 ) {
F_5 ( V_2 , L_27
L_28 , V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) &&
! F_21 ( V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_8 ) ) {
F_3 ( V_2 , L_29
L_30 , V_3 , V_8 ) ;
return V_3 ;
}
V_73 = & V_2 -> V_4 [ V_3 ] ;
V_73 -> V_5 = V_6 ;
F_3 ( V_2 , L_31 ,
V_3 , V_8 ) ;
V_2 -> V_81 ++ ;
memset ( & V_73 -> V_7 , 0 , sizeof( struct V_10 ) ) ;
memcpy ( V_73 -> V_7 . V_7 . V_8 , V_8 , V_82 ) ;
V_73 -> V_7 . V_28 = 0 ;
V_73 -> V_7 . V_7 . V_3 = V_3 ;
V_73 -> V_7 . V_61 = V_49 -> V_61 ;
V_73 -> V_83 = V_49 -> V_83 ;
if ( V_7 ) {
struct V_84 * V_85 ;
V_85 = ( void * ) V_7 -> V_86 ;
V_85 -> V_49 = V_49 ;
}
F_15 ( V_2 , V_3 , V_7 , V_49 ) ;
return V_3 ;
}
int F_23 ( struct V_1 * V_2 , struct V_48 * V_49 ,
const T_1 * V_8 , bool V_71 ,
struct V_47 * V_7 , T_1 * V_87 )
{
unsigned long V_88 ;
int V_15 = 0 ;
T_1 V_3 ;
struct V_10 V_89 ;
* V_87 = 0 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
V_3 = F_19 ( V_2 , V_49 , V_8 , V_71 , V_7 ) ;
if ( V_3 == V_75 ) {
F_2 ( V_2 , L_32 ,
V_8 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
return - V_90 ;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_80 ) {
F_5 ( V_2 , L_27
L_28 , V_3 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
return - V_91 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_29
L_30 , V_3 , V_8 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
return - V_91 ;
}
V_2 -> V_4 [ V_3 ] . V_5 |= V_80 ;
memcpy ( & V_89 , & V_2 -> V_4 [ V_3 ] . V_7 ,
sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
V_15 = F_10 ( V_2 , & V_89 , V_92 ) ;
if ( V_15 ) {
F_6 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
F_2 ( V_2 , L_33 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_80 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
}
* V_87 = V_3 ;
return V_15 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( V_2 -> V_4 [ V_3 ] . V_5 &
( V_9 | V_6 ) ) !=
V_9 )
F_2 ( V_2 , L_34 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_9 ;
memset ( & V_2 -> V_4 [ V_3 ] , 0 , sizeof( struct V_72 ) ) ;
F_3 ( V_2 , L_35 , V_3 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
const T_1 * V_8 , int V_3 ,
bool V_93 )
{
struct V_12 * V_13 ;
int V_15 ;
unsigned long V_88 ;
struct V_94 V_95 ;
struct V_35 V_33 = {
. V_36 = V_96 ,
. V_39 = { sizeof( struct V_94 ) , } ,
. V_14 = V_92 ,
. V_38 = { & V_95 , } ,
} ;
memset ( & V_95 , 0 , sizeof( V_95 ) ) ;
V_95 . V_97 = 1 ;
memcpy ( & V_95 . V_8 , V_8 , V_82 ) ;
V_33 . V_14 |= V_42 ;
V_15 = F_12 ( F_13 ( V_2 ) , & V_33 ) ;
if ( V_15 )
return V_15 ;
V_13 = (struct V_12 * ) V_33 . V_43 ;
if ( V_13 -> V_17 . V_14 & V_18 ) {
F_2 ( V_2 , L_36 ,
V_13 -> V_17 . V_14 ) ;
V_15 = - V_16 ;
}
if ( ! V_15 ) {
switch ( V_13 -> V_21 . V_98 . V_23 ) {
case V_99 :
if ( ! V_93 ) {
F_6 ( & V_2 -> V_19 -> V_20 ,
V_88 ) ;
F_24 ( V_2 , V_3 ) ;
F_7 ( & V_2 -> V_19 -> V_20 ,
V_88 ) ;
}
F_3 ( V_2 , L_37 ) ;
break;
default:
V_15 = - V_16 ;
F_2 ( V_2 , L_38 ) ;
break;
}
}
F_14 ( V_2 -> V_19 , V_33 . V_43 ) ;
return V_15 ;
}
int F_26 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_8 )
{
unsigned long V_14 ;
T_1 V_100 ;
if ( ! F_27 ( V_2 -> V_19 ) ) {
F_5 ( V_2 ,
L_39 ,
V_8 ) ;
return 0 ;
}
F_3 ( V_2 , L_40 ,
V_3 , V_8 ) ;
if ( F_28 ( V_3 == V_75 ) )
return - V_90 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_5 ( V_2 , L_41 ,
V_8 ) ;
goto V_101;
}
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_5 ( V_2 , L_42 ,
V_8 ) ;
goto V_101;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_102 ) {
F_29 ( V_2 -> V_4 [ V_3 ] . V_103 ) ;
V_2 -> V_4 [ V_3 ] . V_103 = NULL ;
}
for ( V_100 = 0 ; V_100 < V_104 ; V_100 ++ )
memset ( & V_2 -> V_105 [ V_3 ] [ V_100 ] , 0 ,
sizeof( V_2 -> V_105 [ V_3 ] [ V_100 ] ) ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_81 -- ;
if ( F_28 ( V_2 -> V_81 < 0 ) )
V_2 -> V_81 = 0 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_25 ( V_2 , V_8 , V_3 , false ) ;
V_101:
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return - V_90 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_74 ;
unsigned long V_88 ;
bool V_106 = false ;
F_5 ( V_2 , L_43 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
if ( V_49 && V_49 -> V_83 != V_2 -> V_4 [ V_74 ] . V_83 )
continue;
if ( V_2 -> V_4 [ V_74 ] . V_5 & V_9 ) {
F_5 ( V_2 ,
L_44 , V_74 ) ;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_9 ;
V_106 = true ;
}
}
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
if ( ! V_106 )
F_5 ( V_2 ,
L_45 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_10 V_89 ;
struct V_107 V_103 ;
unsigned long V_88 ;
int V_74 ;
bool V_108 = false ;
int V_15 ;
bool V_109 ;
if ( ! F_27 ( V_2 -> V_19 ) ) {
F_5 ( V_2 ,
L_46 ) ;
return;
}
F_3 ( V_2 , L_47 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
if ( V_49 -> V_83 != V_2 -> V_4 [ V_74 ] . V_83 )
continue;
if ( ( V_2 -> V_4 [ V_74 ] . V_5 & V_6 ) &&
! ( V_2 -> V_4 [ V_74 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_48 ,
V_2 -> V_4 [ V_74 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_74 ] . V_7 . V_28 = 0 ;
V_2 -> V_4 [ V_74 ] . V_5 |= V_80 ;
V_108 = true ;
}
}
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
if ( ( V_2 -> V_4 [ V_74 ] . V_5 & V_80 ) ) {
memcpy ( & V_89 , & V_2 -> V_4 [ V_74 ] . V_7 ,
sizeof( struct V_10 ) ) ;
V_109 = false ;
if ( V_2 -> V_4 [ V_74 ] . V_103 ) {
if ( V_2 -> V_19 -> V_110 )
F_32 ( V_2 , V_49 , V_74 , & V_103 ) ;
else
memcpy ( & V_103 , V_2 -> V_4 [ V_74 ] . V_103 ,
sizeof( struct V_107 ) ) ;
V_109 = true ;
}
F_7 ( & V_2 -> V_19 -> V_20 ,
V_88 ) ;
V_15 = F_10 ( V_2 , & V_89 , V_92 ) ;
if ( V_15 ) {
F_6 ( & V_2 -> V_19 -> V_20 ,
V_88 ) ;
F_2 ( V_2 , L_33 ,
V_2 -> V_4 [ V_74 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_74 ] . V_5 &=
~ V_6 ;
V_2 -> V_4 [ V_74 ] . V_5 &=
~ V_80 ;
F_7 ( & V_2 -> V_19 -> V_20 ,
V_88 ) ;
}
if ( V_109 )
F_33 ( V_2 , V_49 , & V_103 ,
V_92 , true ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_80 ;
}
}
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
if ( ! V_108 )
F_5 ( V_2 , L_49
L_50 ) ;
else
F_5 ( V_2 , L_49
L_51 ) ;
}
void F_34 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
unsigned long V_14 ;
int V_3 = V_49 -> V_76 ;
int V_15 ;
struct V_10 V_89 ;
struct V_107 V_103 ;
bool V_111 , V_112 = false ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return;
}
memcpy ( & V_89 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_89 ) ) ;
V_89 . V_28 = 0 ;
if ( V_2 -> V_4 [ V_3 ] . V_103 ) {
memcpy ( & V_103 , V_2 -> V_4 [ V_3 ] . V_103 , sizeof( V_103 ) ) ;
V_112 = true ;
}
V_111 = V_2 -> V_4 [ V_3 ] . V_5 & V_9 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( V_111 ) {
V_15 = F_25 (
V_2 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ,
V_3 , true ) ;
if ( V_15 )
F_2 ( V_2 , L_52 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_15 ) ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_6 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_15 = F_10 ( V_2 , & V_89 , V_92 ) ;
if ( V_15 )
F_2 ( V_2 , L_53 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_15 ) ;
if ( V_112 )
F_33 ( V_2 , V_49 , & V_103 , V_92 , true ) ;
}
int F_35 ( struct V_1 * V_2 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_113 ; V_74 ++ )
if ( ! F_36 ( V_74 , & V_2 -> V_114 ) )
return V_74 ;
return V_115 ;
}
void F_37 ( struct V_1 * V_2 )
{
unsigned long V_14 ;
int V_74 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
for ( V_74 = 0 ; V_74 < V_79 ; V_74 ++ ) {
if ( ! ( V_2 -> V_4 [ V_74 ] . V_5 & V_116 ) )
continue;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_9 ;
V_2 -> V_81 -- ;
if ( F_28 ( V_2 -> V_81 < 0 ) )
V_2 -> V_81 = 0 ;
F_29 ( V_2 -> V_4 [ V_74 ] . V_103 ) ;
V_2 -> V_4 [ V_74 ] . V_103 = NULL ;
}
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
}
static void F_38 ( struct V_1 * V_2 ,
struct V_107 * V_103 )
{
int V_74 ;
F_39 ( V_2 , L_54 , V_103 -> V_3 ) ;
F_39 ( V_2 , L_55 ,
V_103 -> V_117 . V_118 ,
V_103 -> V_117 . V_119 ) ;
for ( V_74 = 0 ; V_74 < V_120 ; V_74 ++ )
F_39 ( V_2 , L_56 ,
V_74 , V_103 -> V_121 [ V_74 ] . V_122 ) ;
}
static inline void F_38 ( struct V_1 * V_2 ,
struct V_107 * V_103 )
{
}
static bool F_40 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_107 * V_103 )
{
int V_74 ;
if ( V_49 -> V_123 . V_124 )
return true ;
F_5 ( V_2 , L_57 ,
V_49 -> V_111 . V_125 ) ;
for ( V_74 = 0 ; V_74 < V_120 ; V_74 ++ ) {
if ( F_41 ( V_103 -> V_121 [ V_74 ] . V_122 ) &
V_126 ) {
F_5 ( V_2 ,
L_58 ,
V_74 ) ;
return false ;
}
}
return true ;
}
int F_33 ( struct V_1 * V_2 , struct V_48 * V_49 ,
struct V_107 * V_103 , T_1 V_14 , bool V_127 )
{
int V_15 = 0 ;
unsigned long V_88 ;
struct V_35 V_33 = {
. V_36 = V_128 ,
. V_39 = { sizeof( struct V_107 ) , } ,
. V_14 = V_14 ,
. V_38 = { V_103 , } ,
} ;
if ( F_28 ( V_103 -> V_3 == V_75 ) )
return - V_90 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
if ( ! ( V_2 -> V_4 [ V_103 -> V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
return - V_90 ;
}
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
F_38 ( V_2 , V_103 ) ;
if ( F_28 ( V_127 && ( V_33 . V_14 & V_41 ) ) )
return - V_90 ;
if ( F_40 ( V_2 , V_49 , V_103 ) )
V_15 = F_12 ( F_13 ( V_2 ) , & V_33 ) ;
else
V_15 = - V_90 ;
if ( V_33 . V_14 & V_41 )
return V_15 ;
if ( V_127 ) {
F_5 ( V_2 , L_59
L_60 ,
V_103 -> V_3 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
V_2 -> V_4 [ V_103 -> V_3 ] . V_5 &= ~ V_80 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_88 ) ;
}
return V_15 ;
}
void F_32 ( struct V_1 * V_2 , struct V_48 * V_49 ,
T_1 V_3 , struct V_107 * V_129 )
{
int V_74 , V_130 ;
V_65 V_131 = 0 ;
T_2 V_122 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
memset ( V_129 , 0 , sizeof( * V_129 ) ) ;
if ( V_2 -> V_133 == V_134 )
V_130 = V_135 ;
else if ( V_49 && V_49 -> V_136 && V_49 -> V_136 -> V_137 )
V_130 = V_135 ;
else
V_130 = V_138 ;
if ( V_130 >= V_139 && V_130 <= V_140 )
V_131 |= V_141 ;
V_131 |= F_43 ( F_44 ( V_2 ) . V_142 ) <<
V_143 ;
V_122 = F_45 ( V_144 [ V_130 ] . V_145 , V_131 ) ;
for ( V_74 = 0 ; V_74 < V_120 ; V_74 ++ )
V_129 -> V_121 [ V_74 ] . V_122 = V_122 ;
V_129 -> V_117 . V_118 =
F_43 ( F_44 ( V_2 ) . V_142 ) ;
V_129 -> V_117 . V_119 =
F_44 ( V_2 ) . V_142 &
~ F_43 ( F_44 ( V_2 ) . V_142 ) ;
if ( ! V_129 -> V_117 . V_119 ) {
V_129 -> V_117 . V_119 = V_146 ;
} else if ( F_46 ( F_44 ( V_2 ) . V_142 ) == 2 ) {
V_129 -> V_117 . V_119 =
F_44 ( V_2 ) . V_142 ;
}
V_129 -> V_147 . V_148 =
V_149 ;
V_129 -> V_147 . V_150 =
F_47 ( V_151 ) ;
V_129 -> V_3 = V_3 ;
}
static struct V_107 *
F_48 ( struct V_1 * V_2 , struct V_48 * V_49 ,
T_1 V_3 )
{
struct V_107 * V_129 ;
V_129 = F_49 ( sizeof( struct V_107 ) , V_152 ) ;
if ( ! V_129 ) {
F_2 ( V_2 , L_61 ) ;
return NULL ;
}
F_32 ( V_2 , V_49 , V_3 , V_129 ) ;
return V_129 ;
}
int F_50 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
const T_1 * V_8 , T_1 * V_87 )
{
int V_15 ;
T_1 V_3 ;
struct V_107 * V_129 ;
unsigned long V_14 ;
if ( V_87 )
* V_87 = V_75 ;
V_15 = F_23 ( V_2 , V_49 , V_8 , 0 , NULL , & V_3 ) ;
if ( V_15 ) {
F_2 ( V_2 , L_62 , V_8 ) ;
return V_15 ;
}
if ( V_87 )
* V_87 = V_3 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_102 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_129 = F_48 ( V_2 , V_49 , V_3 ) ;
if ( ! V_129 ) {
F_2 ( V_2 ,
L_63 ,
V_8 ) ;
return - V_153 ;
}
V_15 = F_33 ( V_2 , V_49 , V_129 , V_92 , true ) ;
if ( V_15 )
F_2 ( V_2 , L_64 , V_15 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_103 = V_129 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return 0 ;
}
static int F_51 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
bool V_154 )
{
int V_74 , V_155 = 0 ;
T_1 V_156 [ sizeof( struct V_157 ) +
sizeof( struct V_158 ) * V_159 ] ;
struct V_157 * V_160 = (struct V_157 * ) V_156 ;
T_3 V_161 = sizeof( struct V_157 ) ;
struct V_35 V_33 = {
. V_36 = V_49 -> V_162 ,
. V_38 = { V_160 , } ,
. V_14 = V_92 ,
} ;
F_11 () ;
memset ( V_160 , 0 , V_161 +
( sizeof( struct V_158 ) * V_159 ) ) ;
for ( V_74 = 0 ; V_74 < V_159 ; V_74 ++ ) {
V_160 -> V_163 [ V_74 ] . V_164 = V_74 ;
if ( V_49 -> V_165 [ V_74 ] . V_166 ) {
V_160 -> V_163 [ V_74 ] . V_167 = V_74 ;
V_155 = 1 ;
} else {
V_160 -> V_163 [ V_74 ] . V_167 = V_115 ;
}
V_160 -> V_163 [ V_74 ] . V_166 = V_49 -> V_165 [ V_74 ] . V_166 ;
memcpy ( & V_160 -> V_163 [ V_74 ] . V_163 [ 3 ] , V_49 -> V_165 [ V_74 ] . V_163 ,
V_49 -> V_165 [ V_74 ] . V_166 ) ;
}
V_160 -> V_168 = V_169 ;
V_160 -> V_170 = V_159 ;
V_161 += sizeof( struct V_158 ) * V_159 ;
V_33 . V_39 [ 0 ] = V_161 ;
if ( V_155 || V_154 )
return F_12 ( F_13 ( V_2 ) , & V_33 ) ;
else
return 0 ;
}
int F_52 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
F_42 ( & V_2 -> V_19 -> V_132 ) ;
return F_51 ( V_2 , V_49 , false ) ;
}
int F_53 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_171 * V_172 )
{
int V_15 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
F_54 ( V_2 , L_65 ,
V_172 -> V_173 ) ;
memset ( & V_49 -> V_165 [ V_172 -> V_173 ] , 0 , sizeof( V_49 -> V_165 [ 0 ] ) ) ;
if ( F_55 ( V_2 -> V_19 ) ) {
F_54 ( V_2 ,
L_66 ) ;
return 0 ;
}
V_15 = F_51 ( V_2 , V_49 , 1 ) ;
F_54 ( V_2 , L_67 ,
V_172 -> V_173 , V_15 ) ;
return V_15 ;
}
int F_56 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_171 * V_172 )
{
int V_15 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
if ( V_172 -> V_174 != V_175 &&
V_172 -> V_174 != V_176 ) {
F_54 ( V_2 ,
L_68 , V_172 -> V_174 ) ;
return - V_90 ;
}
V_172 -> V_177 = V_178 ;
V_49 -> V_165 [ V_172 -> V_173 ] . V_166 = V_172 -> V_174 ;
memcpy ( & V_49 -> V_165 [ V_172 -> V_173 ] . V_163 , & V_172 -> V_163 ,
V_172 -> V_174 ) ;
V_15 = F_51 ( V_2 , V_49 , false ) ;
F_54 ( V_2 , L_69 ,
V_172 -> V_174 , V_172 -> V_173 , V_15 ) ;
return V_15 ;
}
static T_1 F_57 ( struct V_1 * V_2 ,
struct V_179 * V_136 ,
struct V_47 * V_7 )
{
struct V_180 * V_181 = ( void * ) V_136 -> V_86 ;
T_1 V_3 = V_75 ;
if ( V_7 )
V_3 = F_58 ( V_7 ) ;
if ( ! V_7 && V_136 && V_181 -> V_49 ) {
switch ( V_136 -> type ) {
case V_182 :
V_3 = V_181 -> V_49 -> V_76 ;
break;
default:
break;
}
}
return V_3 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_171 * V_172 ,
T_1 V_3 , V_65 V_183 , T_4 * V_184 ,
V_65 V_185 )
{
unsigned long V_14 ;
T_5 V_186 ;
struct V_10 V_89 ;
int V_74 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
memcpy ( & V_89 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_89 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_186 = F_47 ( V_172 -> V_173 << V_187 ) ;
V_186 |= V_188 ;
switch ( V_172 -> V_189 ) {
case V_190 :
V_186 |= V_191 ;
memcpy ( V_89 . V_163 . V_163 , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
case V_192 :
V_186 |= V_193 ;
V_89 . V_163 . V_194 = V_183 ;
for ( V_74 = 0 ; V_74 < 5 ; V_74 ++ )
V_89 . V_163 . V_195 [ V_74 ] = F_47 ( V_184 [ V_74 ] ) ;
memcpy ( V_89 . V_163 . V_163 , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
case V_196 :
V_186 |= V_197 ;
case V_198 :
V_186 |= V_199 ;
memcpy ( & V_89 . V_163 . V_163 [ 3 ] , V_172 -> V_163 , V_172 -> V_174 ) ;
break;
default:
F_28 ( 1 ) ;
return - V_90 ;
}
if ( ! ( V_172 -> V_14 & V_200 ) )
V_186 |= V_201 ;
V_89 . V_163 . V_167 = V_172 -> V_177 ;
V_89 . V_163 . V_186 = V_186 ;
V_89 . V_28 = V_29 ;
V_89 . V_7 . V_202 = V_203 ;
return F_10 ( V_2 , & V_89 , V_185 ) ;
}
void F_60 ( struct V_1 * V_2 ,
struct V_179 * V_136 ,
struct V_171 * V_172 ,
struct V_47 * V_7 , V_65 V_204 , T_4 * V_205 )
{
T_1 V_3 = F_57 ( V_2 , V_136 , V_7 ) ;
if ( V_3 == V_75 )
return;
if ( F_61 ( V_2 ) ) {
return;
}
F_59 ( V_2 , V_172 , V_3 ,
V_204 , V_205 , V_41 ) ;
}
int F_62 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_171 * V_172 ,
struct V_47 * V_7 )
{
unsigned long V_14 ;
struct V_10 V_89 ;
T_1 V_3 = F_57 ( V_2 , V_49 -> V_136 , V_7 ) ;
T_5 V_186 ;
if ( V_3 == V_75 )
return - V_206 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
memcpy ( & V_89 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_89 ) ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) )
V_3 = V_75 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( V_3 == V_75 )
return 0 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
V_49 -> V_207 -- ;
F_54 ( V_2 , L_70 ,
V_172 -> V_173 , V_3 ) ;
if ( ! F_63 ( V_172 -> V_177 , & V_2 -> V_114 ) )
F_2 ( V_2 , L_71 ,
V_172 -> V_177 ) ;
V_186 = F_47 ( V_172 -> V_173 << V_187 ) ;
V_186 |= V_188 | V_208 |
V_209 ;
if ( ! ( V_172 -> V_14 & V_200 ) )
V_186 |= V_201 ;
V_89 . V_163 . V_186 = V_186 ;
V_89 . V_163 . V_167 = V_115 ;
V_89 . V_7 . V_202 = V_203 ;
V_89 . V_28 = V_29 ;
return F_10 ( V_2 , & V_89 , V_92 ) ;
}
int F_64 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_171 * V_172 ,
struct V_47 * V_7 )
{
struct V_210 V_211 ;
T_4 V_212 [ 5 ] ;
int V_15 ;
T_1 V_3 = F_57 ( V_2 , V_49 -> V_136 , V_7 ) ;
const T_1 * V_8 ;
if ( V_3 == V_75 )
return - V_90 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
V_172 -> V_177 = F_35 ( V_2 ) ;
if ( V_172 -> V_177 == V_115 )
return - V_213 ;
V_49 -> V_207 ++ ;
switch ( V_172 -> V_189 ) {
case V_192 :
if ( V_7 )
V_8 = V_7 -> V_8 ;
else
V_8 = V_49 -> V_111 . V_214 ;
F_65 ( V_172 , 0 , & V_211 ) ;
F_66 ( V_172 , V_8 , V_211 . V_215 . V_204 , V_212 ) ;
V_15 = F_59 ( V_2 , V_172 , V_3 ,
V_211 . V_215 . V_204 , V_212 , V_92 ) ;
break;
case V_190 :
case V_198 :
case V_196 :
V_15 = F_59 ( V_2 , V_172 , V_3 ,
0 , NULL , V_92 ) ;
break;
default:
F_2 ( V_2 , L_72 , V_172 -> V_189 ) ;
V_15 = - V_90 ;
}
if ( V_15 ) {
V_49 -> V_207 -- ;
F_67 ( V_172 -> V_177 , & V_2 -> V_114 ) ;
}
F_54 ( V_2 , L_73 ,
V_172 -> V_189 , V_172 -> V_174 , V_172 -> V_173 ,
V_7 ? V_7 -> V_8 : NULL , V_15 ) ;
return V_15 ;
}
int F_68 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
struct V_107 * V_129 ;
unsigned long V_14 ;
T_1 V_3 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_3 = F_19 ( V_2 , V_49 , V_216 , false , NULL ) ;
if ( V_3 == V_75 ) {
F_2 ( V_2 , L_74 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return - V_90 ;
}
V_2 -> V_4 [ V_3 ] . V_5 |= V_6 ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_116 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_129 = F_48 ( V_2 , V_49 , V_3 ) ;
if ( ! V_129 ) {
F_2 ( V_2 ,
L_75 ) ;
return - V_153 ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_103 = V_129 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return 0 ;
}
int F_69 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
unsigned long V_14 ;
struct V_107 * V_129 ;
T_1 V_3 = V_49 -> V_77 ;
V_129 = F_48 ( V_2 , V_49 , V_3 ) ;
if ( ! V_129 ) {
F_2 ( V_2 , L_75 ) ;
return - V_153 ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
if ( V_2 -> V_4 [ V_3 ] . V_103 )
F_29 ( V_2 -> V_4 [ V_3 ] . V_103 ) ;
else
F_5 ( V_2 , L_76 ) ;
V_2 -> V_4 [ V_3 ] . V_103 = V_129 ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return 0 ;
}
int F_70 ( struct V_1 * V_2 )
{
struct V_48 * V_49 ;
int V_15 = 0 ;
F_71 (priv, ctx) {
V_15 = F_69 ( V_2 , V_49 ) ;
if ( V_15 )
break;
}
return V_15 ;
}
int F_72 ( struct V_1 * V_2 , int V_3 , int V_100 )
{
unsigned long V_14 ;
struct V_10 V_89 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_202 = V_217 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_218 &= F_47 ( ~ ( 1 << V_100 ) ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
memcpy ( & V_89 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_10 ( V_2 , & V_89 , V_92 ) ;
}
int F_73 ( struct V_1 * V_2 , struct V_47 * V_7 ,
int V_100 , T_4 V_219 )
{
unsigned long V_14 ;
int V_3 ;
struct V_10 V_89 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
V_3 = F_58 ( V_7 ) ;
if ( V_3 == V_75 )
return - V_220 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_221 = 0 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_202 = V_222 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_223 = ( T_1 ) V_100 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_224 = F_47 ( V_219 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
memcpy ( & V_89 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_10 ( V_2 , & V_89 , V_92 ) ;
}
int F_74 ( struct V_1 * V_2 , struct V_47 * V_7 ,
int V_100 )
{
unsigned long V_14 ;
int V_3 ;
struct V_10 V_89 ;
F_42 ( & V_2 -> V_19 -> V_132 ) ;
V_3 = F_58 ( V_7 ) ;
if ( V_3 == V_75 ) {
F_2 ( V_2 , L_77 , V_100 ) ;
return - V_220 ;
}
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_221 = 0 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_202 = V_225 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_226 = ( T_1 ) V_100 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
memcpy ( & V_89 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
return F_10 ( V_2 , & V_89 , V_92 ) ;
}
void F_75 ( struct V_1 * V_2 , int V_3 , int V_227 )
{
unsigned long V_14 ;
F_6 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_61 |= V_228 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_221 = V_228 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_202 =
V_229 ;
V_2 -> V_4 [ V_3 ] . V_7 . V_230 = F_47 ( V_227 ) ;
V_2 -> V_4 [ V_3 ] . V_7 . V_28 = V_29 ;
F_10 ( V_2 , & V_2 -> V_4 [ V_3 ] . V_7 , V_41 ) ;
F_7 ( & V_2 -> V_19 -> V_20 , V_14 ) ;
}
