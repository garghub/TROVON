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
static T_2 F_9 ( const struct V_10 * V_31 , T_1 * V_33 )
{
T_2 V_34 = ( T_2 ) sizeof( struct V_10 ) ;
struct V_10 * V_11 = (struct V_10 * ) V_33 ;
memcpy ( V_11 , V_31 , V_34 ) ;
V_11 -> V_35 = F_10 ( 0 ) ;
return V_34 ;
}
int F_11 ( struct V_1 * V_2 ,
struct V_10 * V_7 , T_1 V_15 )
{
struct V_12 * V_13 = NULL ;
int V_16 = 0 ;
T_1 V_33 [ sizeof( * V_7 ) ] ;
struct V_36 V_31 = {
. V_37 = V_38 ,
. V_15 = V_15 ,
. V_33 = { V_33 , } ,
} ;
T_1 V_3 V_39 = V_7 -> V_7 . V_3 ;
F_5 ( V_2 , L_15 ,
V_3 , V_7 -> V_7 . V_8 , V_15 & V_40 ? L_16 : L_17 ) ;
if ( V_15 & V_40 )
V_31 . V_41 = F_8 ;
else {
V_31 . V_15 |= V_42 ;
F_12 () ;
}
V_31 . V_43 [ 0 ] = F_9 ( V_7 , V_33 ) ;
V_16 = F_13 ( & V_2 -> V_44 , & V_31 ) ;
if ( V_16 || ( V_15 & V_40 ) )
return V_16 ;
if ( V_16 == 0 ) {
V_13 = (struct V_12 * ) V_31 . V_45 ;
V_16 = F_4 ( V_2 , V_7 , V_13 , true ) ;
}
F_14 ( V_2 , V_31 . V_45 ) ;
return V_16 ;
}
static void F_15 ( struct V_1 * V_2 , T_1 V_46 ,
struct V_47 * V_7 ,
struct V_48 * V_49 )
{
struct V_50 * V_51 = & V_7 -> V_52 ;
T_3 V_53 ;
T_1 V_54 ;
if ( ! V_7 || ! V_51 -> V_55 )
goto V_56;
V_54 = ( V_51 -> V_57 & V_58 ) >> 2 ;
F_3 ( V_2 , L_18 ,
( V_54 == V_59 ) ?
L_19 :
( V_54 == V_60 ) ?
L_20 : L_21 ) ;
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
F_16 ( V_2 , L_22 , V_54 ) ;
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
for ( V_74 = V_78 ; V_74 < V_2 -> V_79 . V_80 ; V_74 ++ ) {
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
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_81 ) {
F_5 ( V_2 , L_23 ,
V_3 ) ;
return V_3 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) &&
! F_21 ( V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_8 ) ) {
F_3 ( V_2 , L_24 ,
V_3 , V_8 ) ;
return V_3 ;
}
V_73 = & V_2 -> V_4 [ V_3 ] ;
V_73 -> V_5 = V_6 ;
F_3 ( V_2 , L_25 ,
V_3 , V_8 ) ;
V_2 -> V_82 ++ ;
memset ( & V_73 -> V_7 , 0 , sizeof( struct V_10 ) ) ;
memcpy ( V_73 -> V_7 . V_7 . V_8 , V_8 , V_83 ) ;
V_73 -> V_7 . V_28 = 0 ;
V_73 -> V_7 . V_7 . V_3 = V_3 ;
V_73 -> V_7 . V_61 = V_49 -> V_61 ;
V_73 -> V_84 = V_49 -> V_84 ;
if ( V_7 ) {
struct V_85 * V_86 ;
V_86 = ( void * ) V_7 -> V_87 ;
V_86 -> V_49 = V_49 ;
}
F_15 ( V_2 , V_3 , V_7 , V_49 ) ;
return V_3 ;
}
int F_23 ( struct V_1 * V_2 , struct V_48 * V_49 ,
const T_1 * V_8 , bool V_71 ,
struct V_47 * V_7 , T_1 * V_88 )
{
unsigned long V_89 ;
int V_16 = 0 ;
T_1 V_3 ;
struct V_10 V_90 ;
* V_88 = 0 ;
F_6 ( & V_2 -> V_20 , V_89 ) ;
V_3 = F_19 ( V_2 , V_49 , V_8 , V_71 , V_7 ) ;
if ( V_3 == V_75 ) {
F_2 ( V_2 , L_26 ,
V_8 ) ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
return - V_91 ;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_81 ) {
F_5 ( V_2 , L_23 ,
V_3 ) ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
return - V_92 ;
}
if ( ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) &&
( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_24 ,
V_3 , V_8 ) ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
return - V_92 ;
}
V_2 -> V_4 [ V_3 ] . V_5 |= V_81 ;
memcpy ( & V_90 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( struct V_10 ) ) ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
V_16 = F_11 ( V_2 , & V_90 , V_93 ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_20 , V_89 ) ;
F_2 ( V_2 , L_27 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_81 ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
}
* V_88 = V_3 ;
return V_16 ;
}
static void F_24 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( ( V_2 -> V_4 [ V_3 ] . V_5 &
( V_9 | V_6 ) ) != V_9 )
F_2 ( V_2 , L_28 , V_3 ) ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_9 ;
memset ( & V_2 -> V_4 [ V_3 ] , 0 , sizeof( struct V_72 ) ) ;
F_3 ( V_2 , L_29 , V_3 ) ;
}
static int F_25 ( struct V_1 * V_2 ,
const T_1 * V_8 , int V_3 ,
bool V_94 )
{
struct V_12 * V_13 ;
int V_16 ;
unsigned long V_89 ;
struct V_95 V_96 ;
struct V_36 V_31 = {
. V_37 = V_97 ,
. V_43 = { sizeof( struct V_95 ) , } ,
. V_15 = V_93 ,
. V_33 = { & V_96 , } ,
} ;
memset ( & V_96 , 0 , sizeof( V_96 ) ) ;
V_96 . V_98 = 1 ;
memcpy ( & V_96 . V_8 , V_8 , V_83 ) ;
V_31 . V_15 |= V_42 ;
V_16 = F_13 ( & V_2 -> V_44 , & V_31 ) ;
if ( V_16 )
return V_16 ;
V_13 = (struct V_12 * ) V_31 . V_45 ;
if ( V_13 -> V_18 . V_15 & V_19 ) {
F_2 ( V_2 , L_30 ,
V_13 -> V_18 . V_15 ) ;
V_16 = - V_17 ;
}
if ( ! V_16 ) {
switch ( V_13 -> V_21 . V_99 . V_23 ) {
case V_100 :
if ( ! V_94 ) {
F_6 ( & V_2 -> V_20 , V_89 ) ;
F_24 ( V_2 , V_3 ) ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
}
F_3 ( V_2 , L_31 ) ;
break;
default:
V_16 = - V_17 ;
F_2 ( V_2 , L_32 ) ;
break;
}
}
F_14 ( V_2 , V_31 . V_45 ) ;
return V_16 ;
}
int F_26 ( struct V_1 * V_2 , const T_1 V_3 ,
const T_1 * V_8 )
{
unsigned long V_15 ;
if ( ! F_27 ( V_2 ) ) {
F_5 ( V_2 ,
L_33 ,
V_8 ) ;
return 0 ;
}
F_3 ( V_2 , L_34 ,
V_3 , V_8 ) ;
if ( F_28 ( V_3 == V_75 ) )
return - V_91 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_5 ( V_2 , L_35 ,
V_8 ) ;
goto V_101;
}
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_9 ) ) {
F_5 ( V_2 , L_36 ,
V_8 ) ;
goto V_101;
}
if ( V_2 -> V_4 [ V_3 ] . V_5 & V_102 ) {
F_29 ( V_2 -> V_4 [ V_3 ] . V_103 ) ;
V_2 -> V_4 [ V_3 ] . V_103 = NULL ;
}
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
V_2 -> V_82 -- ;
if ( F_28 ( V_2 -> V_82 < 0 ) )
V_2 -> V_82 = 0 ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
return F_25 ( V_2 , V_8 , V_3 , false ) ;
V_101:
F_7 ( & V_2 -> V_20 , V_15 ) ;
return - V_91 ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_48 * V_49 )
{
int V_74 ;
unsigned long V_89 ;
bool V_104 = false ;
F_5 ( V_2 , L_37 ) ;
F_6 ( & V_2 -> V_20 , V_89 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_79 . V_80 ; V_74 ++ ) {
if ( V_49 && V_49 -> V_84 != V_2 -> V_4 [ V_74 ] . V_84 )
continue;
if ( V_2 -> V_4 [ V_74 ] . V_5 & V_9 ) {
F_5 ( V_2 , L_38 , V_74 ) ;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_9 ;
V_104 = true ;
}
}
F_7 ( & V_2 -> V_20 , V_89 ) ;
if ( ! V_104 )
F_5 ( V_2 , L_39 ) ;
}
void F_31 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
struct V_10 V_90 ;
struct V_105 V_103 ;
unsigned long V_89 ;
int V_74 ;
bool V_106 = false ;
int V_16 ;
bool V_107 ;
if ( ! F_27 ( V_2 ) ) {
F_5 ( V_2 , L_40 ) ;
return;
}
F_3 ( V_2 , L_41 ) ;
F_6 ( & V_2 -> V_20 , V_89 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_79 . V_80 ; V_74 ++ ) {
if ( V_49 -> V_84 != V_2 -> V_4 [ V_74 ] . V_84 )
continue;
if ( ( V_2 -> V_4 [ V_74 ] . V_5 & V_6 ) &&
! ( V_2 -> V_4 [ V_74 ] . V_5 & V_9 ) ) {
F_3 ( V_2 , L_42 ,
V_2 -> V_4 [ V_74 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_74 ] . V_7 . V_28 = 0 ;
V_2 -> V_4 [ V_74 ] . V_5 |= V_81 ;
V_106 = true ;
}
}
for ( V_74 = 0 ; V_74 < V_2 -> V_79 . V_80 ; V_74 ++ ) {
if ( ( V_2 -> V_4 [ V_74 ] . V_5 & V_81 ) ) {
memcpy ( & V_90 , & V_2 -> V_4 [ V_74 ] . V_7 ,
sizeof( struct V_10 ) ) ;
V_107 = false ;
if ( V_2 -> V_4 [ V_74 ] . V_103 ) {
memcpy ( & V_103 , V_2 -> V_4 [ V_74 ] . V_103 ,
sizeof( struct V_105 ) ) ;
V_107 = true ;
}
F_7 ( & V_2 -> V_20 , V_89 ) ;
V_16 = F_11 ( V_2 , & V_90 , V_93 ) ;
if ( V_16 ) {
F_6 ( & V_2 -> V_20 , V_89 ) ;
F_2 ( V_2 , L_27 ,
V_2 -> V_4 [ V_74 ] . V_7 . V_7 . V_8 ) ;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_6 ;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_81 ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
}
if ( V_107 )
F_32 ( V_2 , V_49 , & V_103 , V_93 , true ) ;
F_6 ( & V_2 -> V_20 , V_89 ) ;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_81 ;
}
}
F_7 ( & V_2 -> V_20 , V_89 ) ;
if ( ! V_106 )
F_5 ( V_2 , L_43 ) ;
else
F_5 ( V_2 , L_44 ) ;
}
void F_33 ( struct V_1 * V_2 , struct V_48 * V_49 )
{
unsigned long V_15 ;
int V_3 = V_49 -> V_76 ;
int V_16 ;
struct V_10 V_90 ;
struct V_105 V_103 ;
bool V_108 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
if ( ! ( V_2 -> V_4 [ V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_20 , V_15 ) ;
return;
}
memcpy ( & V_90 , & V_2 -> V_4 [ V_3 ] . V_7 , sizeof( V_90 ) ) ;
V_90 . V_28 = 0 ;
memcpy ( & V_103 , V_2 -> V_4 [ V_3 ] . V_103 , sizeof( V_103 ) ) ;
V_108 = V_2 -> V_4 [ V_3 ] . V_5 & V_9 ;
V_2 -> V_4 [ V_3 ] . V_5 &= ~ V_6 ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
if ( V_108 ) {
V_16 = F_25 (
V_2 , V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 ,
V_3 , true ) ;
if ( V_16 )
F_2 ( V_2 , L_45 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_16 ) ;
}
F_6 ( & V_2 -> V_20 , V_15 ) ;
V_2 -> V_4 [ V_3 ] . V_5 |= V_6 ;
F_7 ( & V_2 -> V_20 , V_15 ) ;
V_16 = F_11 ( V_2 , & V_90 , V_93 ) ;
if ( V_16 )
F_2 ( V_2 , L_46 ,
V_2 -> V_4 [ V_3 ] . V_7 . V_7 . V_8 , V_16 ) ;
F_32 ( V_2 , V_49 , & V_103 , V_93 , true ) ;
}
int F_34 ( struct V_1 * V_2 )
{
int V_74 ;
for ( V_74 = 0 ; V_74 < V_2 -> V_109 ; V_74 ++ )
if ( ! F_35 ( V_74 , & V_2 -> V_110 ) )
return V_74 ;
return V_111 ;
}
void F_36 ( struct V_1 * V_2 )
{
unsigned long V_15 ;
int V_74 ;
F_6 ( & V_2 -> V_20 , V_15 ) ;
for ( V_74 = 0 ; V_74 < V_2 -> V_79 . V_80 ; V_74 ++ ) {
if ( ! ( V_2 -> V_4 [ V_74 ] . V_5 & V_112 ) )
continue;
V_2 -> V_4 [ V_74 ] . V_5 &= ~ V_9 ;
V_2 -> V_82 -- ;
if ( F_28 ( V_2 -> V_82 < 0 ) )
V_2 -> V_82 = 0 ;
F_29 ( V_2 -> V_4 [ V_74 ] . V_103 ) ;
V_2 -> V_4 [ V_74 ] . V_103 = NULL ;
}
F_7 ( & V_2 -> V_20 , V_15 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
struct V_105 * V_103 )
{
int V_74 ;
F_38 ( V_2 , L_47 , V_103 -> V_3 ) ;
F_38 ( V_2 , L_48 ,
V_103 -> V_113 . V_114 ,
V_103 -> V_113 . V_115 ) ;
for ( V_74 = 0 ; V_74 < V_116 ; V_74 ++ )
F_38 ( V_2 , L_49 ,
V_74 , V_103 -> V_117 [ V_74 ] . V_35 ) ;
}
static inline void F_37 ( struct V_1 * V_2 ,
struct V_105 * V_103 )
{
}
static bool F_39 ( struct V_1 * V_2 ,
struct V_48 * V_49 ,
struct V_105 * V_103 )
{
int V_74 ;
if ( V_49 -> V_118 . V_119 )
return true ;
F_5 ( V_2 , L_50 ,
V_49 -> V_108 . V_120 ) ;
for ( V_74 = 0 ; V_74 < V_116 ; V_74 ++ ) {
if ( F_40 ( V_103 -> V_117 [ V_74 ] . V_35 ) & V_121 ) {
F_5 ( V_2 ,
L_51 ,
V_74 ) ;
return false ;
}
}
return true ;
}
int F_32 ( struct V_1 * V_2 , struct V_48 * V_49 ,
struct V_105 * V_103 , T_1 V_15 , bool V_122 )
{
int V_16 = 0 ;
unsigned long V_89 ;
struct V_36 V_31 = {
. V_37 = V_123 ,
. V_43 = { sizeof( struct V_105 ) , } ,
. V_15 = V_15 ,
. V_33 = { V_103 , } ,
} ;
if ( F_28 ( V_103 -> V_3 == V_75 ) )
return - V_91 ;
F_6 ( & V_2 -> V_20 , V_89 ) ;
if ( ! ( V_2 -> V_4 [ V_103 -> V_3 ] . V_5 & V_6 ) ) {
F_7 ( & V_2 -> V_20 , V_89 ) ;
return - V_91 ;
}
F_7 ( & V_2 -> V_20 , V_89 ) ;
F_37 ( V_2 , V_103 ) ;
if ( F_28 ( V_122 && ( V_31 . V_15 & V_40 ) ) )
return - V_91 ;
if ( F_39 ( V_2 , V_49 , V_103 ) )
V_16 = F_13 ( & V_2 -> V_44 , & V_31 ) ;
else
V_16 = - V_91 ;
if ( V_31 . V_15 & V_40 )
return V_16 ;
if ( V_122 ) {
F_5 ( V_2 , L_52 ,
V_103 -> V_3 ) ;
F_6 ( & V_2 -> V_20 , V_89 ) ;
V_2 -> V_4 [ V_103 -> V_3 ] . V_5 &= ~ V_81 ;
F_7 ( & V_2 -> V_20 , V_89 ) ;
}
return V_16 ;
}
int F_41 ( struct V_124 * V_125 ,
struct V_126 * V_127 ,
struct V_47 * V_7 )
{
struct V_1 * V_2 = V_125 -> V_2 ;
struct V_85 * V_128 = ( void * ) V_7 -> V_87 ;
int V_16 ;
F_5 ( V_2 , L_53 ,
V_7 -> V_8 ) ;
F_42 ( & V_2 -> V_129 ) ;
F_5 ( V_2 , L_54 ,
V_7 -> V_8 ) ;
V_16 = F_26 ( V_2 , V_128 -> V_3 , V_7 -> V_8 ) ;
if ( V_16 )
F_2 ( V_2 , L_55 ,
V_7 -> V_8 ) ;
F_43 ( & V_2 -> V_129 ) ;
return V_16 ;
}
