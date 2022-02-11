static unsigned long F_1 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_5 ;
switch ( V_3 & 0x0c ) {
case V_6 :
V_5 = V_2 -> V_7 -> V_8 . V_9 . V_10 ? V_11 : 0 ;
break;
case V_12 :
V_5 = V_2 -> V_7 -> V_8 . V_9 . V_13 + V_14 ;
V_5 = ( V_5 >> 5 ) - 1 ;
V_5 |= ( F_2 ( & V_2 -> V_7 -> V_15 ) - 1 ) << 5 ;
break;
case V_16 :
V_5 = ( V_17 << 24 ) | ( V_18 << 0 ) ;
break;
default:
return 0 ;
}
return V_5 ;
}
static void F_3 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
struct V_20 * V_21 = & V_2 -> V_7 -> V_8 . V_9 ;
bool V_22 = V_21 -> V_10 ;
switch ( V_3 & 0x0c ) {
case V_6 :
V_21 -> V_10 = V_19 & V_11 ;
if ( ! V_22 && V_21 -> V_10 )
F_4 ( V_2 -> V_7 ) ;
break;
case V_12 :
case V_16 :
return;
}
}
static void F_5 ( struct V_1 * V_23 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
int V_24 = F_2 ( & V_23 -> V_7 -> V_15 ) ;
int V_25 = V_19 & 0xf ;
int V_26 = ( V_19 >> 16 ) & 0xff ;
int V_27 = ( V_19 >> 24 ) & 0x03 ;
int V_28 ;
struct V_1 * V_2 ;
switch ( V_27 ) {
case 0x0 :
break;
case 0x1 :
V_26 = ( 1U << V_24 ) - 1 ;
V_26 &= ~ ( 1U << V_23 -> V_29 ) ;
break;
case 0x2 :
V_26 = ( 1U << V_23 -> V_29 ) ;
break;
case 0x3 :
return;
}
F_6 (c, vcpu, source_vcpu->kvm) {
struct V_30 * V_31 ;
if ( ! ( V_26 & ( 1U << V_28 ) ) )
continue;
V_31 = F_7 ( V_23 -> V_7 , V_2 , V_25 ) ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_33 = true ;
V_31 -> V_34 |= 1U << V_23 -> V_29 ;
F_9 ( V_23 -> V_7 , V_31 ) ;
F_10 ( V_23 -> V_7 , V_31 ) ;
}
}
static unsigned long F_11 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_25 = F_12 ( V_3 , 8 ) ;
int V_35 ;
T_3 V_19 = 0 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
V_19 |= ( T_3 ) V_31 -> V_26 << ( V_35 * 8 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
return V_19 ;
}
static void F_13 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
T_2 V_25 = F_12 ( V_3 , 8 ) ;
T_4 V_36 = F_14 ( F_2 ( & V_2 -> V_7 -> V_15 ) - 1 , 0 ) ;
int V_35 ;
if ( V_25 < V_14 )
return;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , NULL , V_25 + V_35 ) ;
int V_37 ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_26 = ( V_19 >> ( V_35 * 8 ) ) & V_36 ;
V_37 = V_31 -> V_26 ? F_15 ( V_31 -> V_26 ) : 0 ;
V_31 -> V_38 = F_16 ( V_2 -> V_7 , V_37 ) ;
F_17 ( & V_31 -> V_32 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
}
static unsigned long F_18 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
T_2 V_25 = V_3 & 0x0f ;
int V_35 ;
T_3 V_19 = 0 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
V_19 |= ( T_3 ) V_31 -> V_34 << ( V_35 * 8 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
return V_19 ;
}
static void F_19 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
T_2 V_25 = V_3 & 0x0f ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_34 &= ~ ( ( V_19 >> ( V_35 * 8 ) ) & 0xff ) ;
if ( ! V_31 -> V_34 )
V_31 -> V_33 = false ;
F_17 ( & V_31 -> V_32 ) ;
F_10 ( V_2 -> V_7 , V_31 ) ;
}
}
static void F_20 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
T_2 V_25 = V_3 & 0x0f ;
int V_35 ;
for ( V_35 = 0 ; V_35 < V_4 ; V_35 ++ ) {
struct V_30 * V_31 = F_7 ( V_2 -> V_7 , V_2 , V_25 + V_35 ) ;
F_8 ( & V_31 -> V_32 ) ;
V_31 -> V_34 |= ( V_19 >> ( V_35 * 8 ) ) & 0xff ;
if ( V_31 -> V_34 ) {
V_31 -> V_33 = true ;
F_9 ( V_2 -> V_7 , V_31 ) ;
} else {
F_17 ( & V_31 -> V_32 ) ;
}
F_10 ( V_2 -> V_7 , V_31 ) ;
}
}
static unsigned long F_21 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
struct V_39 V_40 ;
T_2 V_19 ;
F_22 ( V_2 , & V_40 ) ;
switch ( V_3 & 0xff ) {
case V_41 :
V_19 = V_40 . V_42 << V_43 ;
V_19 |= V_40 . V_44 << V_45 ;
V_19 |= V_40 . V_46 << V_47 ;
V_19 |= V_40 . V_48 << V_49 ;
V_19 |= V_40 . V_50 << V_51 ;
V_19 |= V_40 . V_52 << V_53 ;
break;
case V_54 :
V_19 = ( V_40 . V_55 & V_56 ) >>
V_57 ;
break;
case V_58 :
V_19 = V_40 . V_59 ;
break;
case V_60 :
V_19 = V_40 . V_61 ;
break;
case V_62 :
V_19 = ( ( V_17 << 20 ) |
( V_63 << 16 ) |
V_18 ) ;
break;
default:
return 0 ;
}
return V_19 ;
}
static void F_23 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
struct V_39 V_40 ;
F_22 ( V_2 , & V_40 ) ;
switch ( V_3 & 0xff ) {
case V_41 :
V_40 . V_42 = ! ! ( V_19 & V_64 ) ;
V_40 . V_44 = ! ! ( V_19 & V_65 ) ;
V_40 . V_46 = ! ! ( V_19 & V_66 ) ;
V_40 . V_48 = ! ! ( V_19 & V_67 ) ;
V_40 . V_50 = ! ! ( V_19 & V_68 ) ;
V_40 . V_52 = ! ! ( V_19 & V_69 ) ;
break;
case V_54 :
V_40 . V_55 = ( V_19 << V_57 ) &
V_56 ;
break;
case V_58 :
V_40 . V_59 = V_19 ;
break;
case V_60 :
V_40 . V_61 = V_19 ;
break;
}
F_24 ( V_2 , & V_40 ) ;
}
static unsigned long F_25 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 )
{
int V_70 ;
V_70 = ( V_3 >> 2 ) & 0x3 ;
if ( V_71 . type == V_72 ) {
if ( V_70 != 0 )
return 0 ;
return V_2 -> V_8 . V_73 . V_74 . V_75 ;
} else {
struct V_76 * V_77 = & V_2 -> V_8 . V_73 . V_78 ;
if ( V_70 > F_26 ( V_2 ) )
return 0 ;
return V_77 -> V_79 [ V_70 ] ;
}
}
static void F_27 ( struct V_1 * V_2 ,
T_1 V_3 , unsigned int V_4 ,
unsigned long V_19 )
{
int V_70 ;
V_70 = ( V_3 >> 2 ) & 0x3 ;
if ( V_71 . type == V_72 ) {
if ( V_70 != 0 )
return;
V_2 -> V_8 . V_73 . V_74 . V_75 = V_19 ;
} else {
struct V_76 * V_77 = & V_2 -> V_8 . V_73 . V_78 ;
if ( V_70 > F_26 ( V_2 ) )
return;
V_77 -> V_79 [ V_70 ] = V_19 ;
}
}
unsigned int F_28 ( struct V_80 * V_81 )
{
V_81 -> V_82 = V_83 ;
V_81 -> V_84 = F_29 ( V_83 ) ;
F_30 ( & V_81 -> V_81 , & V_85 ) ;
return V_86 ;
}
int F_31 ( struct V_87 * V_81 , struct V_88 * V_89 )
{
const struct V_90 * V_91 ;
struct V_80 V_92 ;
struct V_93 V_94 ;
struct V_1 * V_2 ;
T_1 V_3 ;
int V_95 ;
V_95 = F_32 ( V_81 , V_89 , & V_94 ) ;
if ( V_95 )
return V_95 ;
V_2 = V_94 . V_2 ;
V_3 = V_94 . V_3 ;
switch ( V_89 -> V_96 ) {
case V_97 :
V_92 . V_82 = V_83 ;
V_92 . V_84 = F_29 ( V_83 ) ;
V_92 . V_98 = 0 ;
break;
case V_99 :
V_92 . V_82 = V_100 ;
V_92 . V_84 = F_29 ( V_100 ) ;
V_92 . V_98 = 0 ;
break;
default:
return - V_101 ;
}
if ( V_3 & 3 )
return - V_101 ;
V_91 = F_33 ( V_2 , & V_92 , V_3 , sizeof( T_2 ) ) ;
if ( ! V_91 )
return - V_101 ;
return 0 ;
}
int F_34 ( struct V_1 * V_2 , bool V_102 ,
int V_103 , T_2 * V_19 )
{
struct V_80 V_81 = {
. V_82 = V_100 ,
. V_84 = F_29 ( V_100 ) ,
. V_104 = V_105 ,
} ;
return F_35 ( V_2 , & V_81 , V_102 , V_103 , V_19 ) ;
}
int F_36 ( struct V_1 * V_2 , bool V_102 ,
int V_103 , T_2 * V_19 )
{
struct V_80 V_81 = {
. V_82 = V_83 ,
. V_84 = F_29 ( V_83 ) ,
. V_104 = V_106 ,
} ;
return F_35 ( V_2 , & V_81 , V_102 , V_103 , V_19 ) ;
}
