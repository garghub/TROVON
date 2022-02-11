static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 V_6 = { 0 } ;
int V_7 = 0 , V_8 ;
T_1 * V_9 ;
F_2 ( V_2 , & V_6 , V_10 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_12 |
V_13 ) ;
V_9 = & V_6 . V_14 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
V_6 . V_16 |= F_3 (
V_17 << V_8 ) ;
V_9 [ V_8 ] = V_2 -> V_18 [ V_4 -> V_19 [ V_8 ] ] . V_20 ;
}
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
return V_7 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_22 * V_23 = V_2 -> V_24 ;
struct V_25 V_6 = { 0 } ;
int V_7 = 0 ;
F_2 ( V_2 , & V_6 , V_26 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_27 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( ! V_7 ) {
T_1 * V_9 = & V_23 -> V_14 ;
int V_8 , V_28 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
T_1 V_20 = V_9 [ V_8 ] ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ ) {
if ( V_2 -> V_18 [ V_28 ] . V_20 == V_20 ) {
V_4 -> V_19 [ V_8 ] = V_28 ;
break;
}
}
}
}
return V_7 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_29 )
{
struct V_30 V_6 = { 0 } ;
struct V_31 V_32 ;
int V_7 = 0 , V_8 ;
void * V_33 ;
F_2 ( V_2 , & V_6 , V_34 , - 1 , - 1 ) ;
V_33 = & V_6 . V_35 ;
for ( V_8 = 0 ; V_8 < V_29 ; V_8 ++ , V_33 += sizeof( V_32 ) - 4 ) {
V_6 . V_16 |= F_3 (
V_36 << V_8 ) ;
memset ( & V_32 , 0 , sizeof( V_32 ) ) ;
V_32 . V_20 = V_2 -> V_18 [ V_8 ] . V_20 ;
if ( V_4 -> V_37 [ V_8 ] == V_38 ) {
V_32 . V_39 =
V_40 ;
V_32 . V_41 = V_8 ;
} else {
V_32 . V_39 =
V_42 ;
V_32 . V_43 = V_4 -> V_44 [ V_8 ] ;
}
memcpy ( V_33 , & V_32 . V_20 , sizeof( V_32 ) - 4 ) ;
if ( V_8 == 0 ) {
V_6 . V_45 = V_32 . V_20 ;
V_6 . V_35 = 0 ;
}
}
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
return V_7 ;
}
static int F_7 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_46 * V_23 = V_2 -> V_24 ;
struct V_47 V_6 = { 0 } ;
struct V_31 V_32 ;
void * V_33 ;
int V_7 , V_8 ;
F_2 ( V_2 , & V_6 , V_48 , - 1 , - 1 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 )
return V_7 ;
V_33 = & V_23 -> V_45 + F_8 ( struct V_31 , V_20 ) ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ , V_33 += sizeof( V_32 ) - 4 ) {
int V_28 ;
memcpy ( & V_32 . V_20 , V_33 , sizeof( V_32 ) - 4 ) ;
if ( V_8 == 0 )
V_32 . V_20 = V_23 -> V_45 ;
for ( V_28 = 0 ; V_28 < V_2 -> V_29 ; V_28 ++ ) {
if ( V_2 -> V_18 [ V_28 ] . V_20 != V_32 . V_20 )
continue;
if ( V_32 . V_39 ==
V_40 ) {
V_4 -> V_37 [ V_28 ] = V_38 ;
} else {
V_4 -> V_37 [ V_28 ] = V_49 ;
V_4 -> V_44 [ V_28 ] = V_32 . V_43 ;
}
}
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned int V_50 )
{
struct V_51 V_6 = { 0 } ;
int V_8 ;
if ( F_10 ( V_2 -> V_52 ) )
F_11 ( V_2 ) ;
F_2 ( V_2 , & V_6 , V_53 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_54 ) ;
V_6 . V_16 = F_3 ( V_55 ) ;
V_6 . V_56 = V_57 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
if ( F_12 ( V_2 -> V_18 [ V_8 ] . V_58 ) ) {
V_6 . V_20 = F_3 ( V_2 -> V_18 [ V_8 ] . V_20 ) ;
F_4 ( V_2 , & V_6 , sizeof( V_6 ) ,
V_21 ) ;
V_2 -> V_18 [ V_8 ] . V_58 =
V_57 ;
}
}
V_6 . V_56 = V_59 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
if ( V_50 & ( 1 << V_8 ) ) {
V_6 . V_20 = F_3 ( V_2 -> V_18 [ V_8 ] . V_20 ) ;
F_4 ( V_2 , & V_6 , sizeof( V_6 ) ,
V_21 ) ;
V_2 -> V_18 [ V_8 ] . V_58 =
V_59 ;
}
}
if ( F_10 ( V_2 -> V_52 ) )
F_13 ( V_2 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_62 V_6 = { 0 } ;
struct V_3 * V_63 = V_2 -> V_3 ;
unsigned int V_64 = 0 , V_65 = 0 ;
T_1 V_8 , V_66 , V_67 = 0 ;
bool V_68 = false ;
int V_7 ;
if ( ! V_63 )
return - V_69 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
for ( V_66 = 0 ; V_66 < V_15 ; V_66 ++ ) {
if ( ( V_61 -> V_70 & ( 1 << V_66 ) ) &&
( V_63 -> V_19 [ V_66 ] == V_8 ) ) {
V_65 |= 1 << V_66 ;
V_64 |= 1 << V_8 ;
}
}
if ( V_64 & ( 1 << V_8 ) )
V_67 ++ ;
}
if ( V_67 > V_2 -> V_71 )
return - V_69 ;
F_2 ( V_2 , & V_6 , V_72 , - 1 , - 1 ) ;
V_6 . V_11 = F_3 ( V_65 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 )
return V_7 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_29 ; V_8 ++ ) {
if ( V_64 & ( 1 << V_8 ) ) {
if ( ! F_12 ( V_2 -> V_18 [ V_8 ] . V_58 ) )
V_68 = true ;
}
}
if ( V_68 )
V_7 = F_9 ( V_2 , V_64 ) ;
return V_7 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_73 * V_23 = V_2 -> V_24 ;
struct V_74 V_6 = { 0 } ;
T_1 V_65 ;
int V_7 ;
F_2 ( V_2 , & V_6 , V_75 , - 1 , - 1 ) ;
V_7 = F_4 ( V_2 , & V_6 , sizeof( V_6 ) , V_21 ) ;
if ( V_7 )
return V_7 ;
V_65 = F_16 ( V_23 -> V_11 ) ;
V_61 -> V_70 = V_65 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_3 * V_4 , T_1 * V_76 )
{
int V_77 = 0 ;
T_1 V_29 = 0 ;
int V_8 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ ) {
if ( V_4 -> V_19 [ V_8 ] > V_2 -> V_29 ) {
F_18 ( V_2 -> V_52 , L_1 ,
V_4 -> V_19 [ V_8 ] ) ;
return - V_69 ;
}
if ( V_4 -> V_19 [ V_8 ] > V_29 )
V_29 = V_4 -> V_19 [ V_8 ] ;
if ( ( V_4 -> V_44 [ V_8 ] || V_4 -> V_37 [ V_8 ] ) && V_8 > V_2 -> V_29 )
return - V_69 ;
switch ( V_4 -> V_37 [ V_8 ] ) {
case V_38 :
break;
case V_49 :
V_77 += V_4 -> V_44 [ V_8 ] ;
break;
default:
return - V_78 ;
}
}
if ( V_77 > 100 )
return - V_69 ;
* V_76 = V_29 + 1 ;
return 0 ;
}
static int F_19 ( struct V_79 * V_52 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
struct V_3 * V_63 = V_2 -> V_3 ;
V_4 -> V_80 = V_2 -> V_29 ;
if ( ! V_63 ) {
int V_7 ;
if ( V_2 -> V_81 & V_82 )
return 0 ;
V_63 = F_21 ( sizeof( * V_63 ) , V_83 ) ;
if ( ! V_63 )
return 0 ;
V_7 = F_7 ( V_2 , V_63 ) ;
if ( V_7 )
return 0 ;
V_7 = F_5 ( V_2 , V_63 ) ;
if ( V_7 )
return 0 ;
}
V_4 -> V_84 = V_63 -> V_84 ;
memcpy ( V_4 -> V_44 , V_63 -> V_44 , sizeof( V_4 -> V_44 ) ) ;
memcpy ( V_4 -> V_85 , V_63 -> V_85 , sizeof( V_4 -> V_85 ) ) ;
memcpy ( V_4 -> V_37 , V_63 -> V_37 , sizeof( V_4 -> V_37 ) ) ;
memcpy ( V_4 -> V_19 , V_63 -> V_19 , sizeof( V_4 -> V_19 ) ) ;
return 0 ;
}
static int F_22 ( struct V_79 * V_52 , struct V_3 * V_4 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
struct V_3 * V_63 = V_2 -> V_3 ;
T_1 V_29 = 0 ;
int V_7 , V_8 ;
if ( ! ( V_2 -> V_81 & V_86 ) ||
! ( V_2 -> V_81 & V_82 ) )
return - V_69 ;
V_7 = F_17 ( V_2 , V_4 , & V_29 ) ;
if ( ! V_7 ) {
if ( ! V_63 ) {
V_63 = F_21 ( sizeof( * V_63 ) , V_83 ) ;
if ( ! V_63 )
return - V_87 ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ )
V_63 -> V_19 [ V_8 ] = V_15 ;
V_2 -> V_3 = V_63 ;
}
V_7 = F_23 ( V_52 , V_29 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_2 , V_4 , V_29 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_1 ( V_2 , V_4 ) ;
if ( V_7 )
return V_7 ;
memcpy ( V_63 , V_4 , sizeof( * V_63 ) ) ;
}
return V_7 ;
}
static int F_24 ( struct V_79 * V_52 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
T_2 * V_88 = ( T_2 * ) V_2 -> V_89 ;
struct V_60 * V_90 = V_2 -> V_60 ;
long V_91 , V_92 ;
int V_8 , V_7 ;
V_61 -> V_93 = V_2 -> V_71 ;
if ( ! V_90 ) {
if ( V_2 -> V_81 & V_82 )
return 0 ;
V_90 = F_21 ( sizeof( * V_90 ) , V_83 ) ;
if ( ! V_90 )
return 0 ;
V_2 -> V_60 = V_90 ;
V_7 = F_15 ( V_2 , V_90 ) ;
if ( V_7 )
return 0 ;
}
V_61 -> V_70 = V_90 -> V_70 ;
V_61 -> V_94 = V_90 -> V_94 ;
V_61 -> V_95 = V_90 -> V_95 ;
if ( ! V_88 )
return 0 ;
V_91 = F_25 ( V_96 ) ;
V_92 = F_26 ( V_97 ) ;
for ( V_8 = 0 ; V_8 < V_15 ; V_8 ++ , V_91 ++ , V_92 ++ ) {
V_61 -> V_98 [ V_8 ] = F_27 ( * ( V_88 + V_92 ) ) ;
V_61 -> V_99 [ V_8 ] = F_27 ( * ( V_88 + V_91 ) ) ;
}
return 0 ;
}
static int F_28 ( struct V_79 * V_52 , struct V_60 * V_61 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
struct V_60 * V_90 = V_2 -> V_60 ;
int V_7 ;
if ( ! ( V_2 -> V_81 & V_86 ) ||
! ( V_2 -> V_81 & V_82 ) )
return - V_69 ;
if ( ! V_90 ) {
V_90 = F_21 ( sizeof( * V_90 ) , V_83 ) ;
if ( ! V_90 )
return - V_87 ;
V_2 -> V_60 = V_90 ;
}
V_7 = F_14 ( V_2 , V_61 ) ;
if ( ! V_7 )
memcpy ( V_90 , V_61 , sizeof( * V_90 ) ) ;
return V_7 ;
}
static int F_29 ( struct V_79 * V_52 , struct V_100 * V_101 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
int V_7 = - V_69 ;
if ( ! ( V_2 -> V_81 & V_86 ) ||
! ( V_2 -> V_81 & V_82 ) )
return - V_69 ;
V_7 = F_30 ( V_52 , V_101 ) ;
return V_7 ;
}
static int F_31 ( struct V_79 * V_52 , struct V_100 * V_101 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
int V_7 ;
if ( ! ( V_2 -> V_81 & V_86 ) )
return - V_69 ;
V_7 = F_32 ( V_52 , V_101 ) ;
return V_7 ;
}
static T_1 F_33 ( struct V_79 * V_52 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
return V_2 -> V_81 ;
}
static T_1 F_34 ( struct V_79 * V_52 , T_1 V_102 )
{
struct V_1 * V_2 = F_20 ( V_52 ) ;
if ( ( V_102 & V_103 ) || ! ( V_102 & V_86 ) )
return 1 ;
if ( ( V_102 & V_82 ) && F_35 ( V_2 ) )
return 1 ;
if ( V_102 == V_2 -> V_81 )
return 0 ;
V_2 -> V_81 = V_102 ;
return 0 ;
}
void F_36 ( struct V_1 * V_2 )
{
if ( V_2 -> V_104 < 0x10501 )
return;
V_2 -> V_81 = V_86 ;
if ( F_37 ( V_2 ) )
V_2 -> V_81 |= V_82 ;
else
V_2 -> V_81 |= V_105 ;
V_2 -> V_52 -> V_106 = & V_106 ;
}
void F_38 ( struct V_1 * V_2 )
{
F_39 ( V_2 -> V_60 ) ;
F_39 ( V_2 -> V_3 ) ;
V_2 -> V_60 = NULL ;
V_2 -> V_3 = NULL ;
}
void F_36 ( struct V_1 * V_2 )
{
}
void F_38 ( struct V_1 * V_2 )
{
}
