unsigned long F_1 ( T_1 V_1 , unsigned int V_2 ,
unsigned int V_3 )
{
return ( V_1 >> ( V_2 * 8 ) ) & F_2 ( V_3 * 8 - 1 , 0 ) ;
}
T_1 F_3 ( T_1 V_4 , unsigned int V_2 , unsigned int V_5 ,
unsigned long V_6 )
{
int V_7 = ( V_2 & 4 ) * 8 ;
int V_8 = V_7 + 8 * V_5 - 1 ;
V_4 &= ~ F_2 ( V_8 , V_7 ) ;
V_6 &= F_2 ( V_5 * 8 - 1 , 0 ) ;
return V_4 | ( ( T_1 ) V_6 << V_7 ) ;
}
bool F_4 ( struct V_9 * V_9 )
{
struct V_10 * V_11 = & V_9 -> V_12 . V_13 ;
if ( V_11 -> V_14 != V_15 )
return false ;
return V_11 -> V_16 ;
}
static unsigned long F_5 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
T_3 V_20 = 0 ;
switch ( V_19 & 0x0c ) {
case V_21 :
if ( V_18 -> V_9 -> V_12 . V_13 . V_22 )
V_20 |= V_23 ;
V_20 |= V_24 | V_25 ;
break;
case V_26 :
V_20 = V_18 -> V_9 -> V_12 . V_13 . V_27 + V_28 ;
V_20 = ( V_20 >> 5 ) - 1 ;
if ( F_4 ( V_18 -> V_9 ) ) {
V_20 |= ( V_29 - 1 ) << 19 ;
V_20 |= V_30 ;
} else {
V_20 |= ( V_31 - 1 ) << 19 ;
}
break;
case V_32 :
V_20 = ( V_33 << 24 ) | ( V_34 << 0 ) ;
break;
default:
return 0 ;
}
return V_20 ;
}
static void F_6 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_10 * V_11 = & V_18 -> V_9 -> V_12 . V_13 ;
bool V_35 = V_11 -> V_22 ;
switch ( V_19 & 0x0c ) {
case V_21 :
V_11 -> V_22 = V_6 & V_23 ;
if ( ! V_35 && V_11 -> V_22 )
F_7 ( V_18 -> V_9 ) ;
break;
case V_26 :
case V_32 :
return;
}
}
static unsigned long F_8 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
int V_36 = F_9 ( V_19 , 64 ) ;
struct V_37 * V_38 = F_10 ( V_18 -> V_9 , NULL , V_36 ) ;
unsigned long V_39 = 0 ;
if ( ! V_38 )
return 0 ;
if ( ! ( V_19 & 4 ) )
V_39 = F_1 ( F_11 ( V_38 -> V_40 ) , V_19 & 7 , V_5 ) ;
F_12 ( V_18 -> V_9 , V_38 ) ;
return V_39 ;
}
static void F_13 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
int V_36 = F_9 ( V_19 , 64 ) ;
struct V_37 * V_38 ;
if ( V_19 & 4 )
return;
V_38 = F_10 ( V_18 -> V_9 , NULL , V_36 ) ;
if ( ! V_38 )
return;
F_14 ( & V_38 -> V_41 ) ;
V_38 -> V_40 = V_6 & F_15 ( 23 , 0 ) ;
V_38 -> V_42 = F_16 ( V_18 -> V_9 , V_38 -> V_40 ) ;
F_17 ( & V_38 -> V_41 ) ;
F_12 ( V_18 -> V_9 , V_38 ) ;
}
static unsigned long F_18 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
return V_43 -> V_44 ? V_45 : 0 ;
}
static void F_19 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
bool V_35 = V_43 -> V_44 ;
if ( ! F_4 ( V_18 -> V_9 ) )
return;
V_43 -> V_44 = V_6 & V_45 ;
if ( ! V_35 && V_43 -> V_44 )
F_20 ( V_18 ) ;
}
static unsigned long F_21 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
unsigned long V_40 = F_22 ( V_18 ) ;
int V_46 = V_18 -> V_47 ;
T_1 V_20 ;
V_20 = ( T_1 ) ( V_40 & F_15 ( 23 , 0 ) ) << 32 ;
V_20 |= ( ( V_46 & 0xffff ) << 8 ) ;
if ( V_46 == F_23 ( & V_18 -> V_9 -> V_48 ) - 1 )
V_20 |= V_49 ;
if ( F_4 ( V_18 -> V_9 ) )
V_20 |= V_50 ;
return F_1 ( V_20 , V_19 & 7 , V_5 ) ;
}
static unsigned long F_24 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
return ( V_33 << 24 ) | ( V_34 << 0 ) ;
}
static unsigned long F_25 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
switch ( V_19 & 0xffff ) {
case V_51 :
return 0x3b ;
}
return 0 ;
}
T_1 F_26 ( T_1 V_52 )
{
switch ( V_52 ) {
case V_53 :
return V_54 ;
default:
return V_52 ;
}
}
T_1 F_27 ( T_1 V_52 )
{
switch ( V_52 ) {
case V_55 :
case V_56 :
return V_57 ;
default:
return V_52 ;
}
}
T_1 F_28 ( T_1 V_52 )
{
switch ( V_52 ) {
case V_58 :
case V_56 :
return V_52 ;
default:
return V_56 ;
}
}
T_1 F_29 ( T_1 V_4 , T_1 V_59 , int V_60 ,
T_1 (* F_30)( T_1 ) )
{
T_1 V_52 = ( V_4 & V_59 ) >> V_60 ;
V_52 = F_30 ( V_52 ) << V_60 ;
return ( V_4 & ~ V_59 ) | V_52 ;
}
static T_1 F_31 ( T_1 V_4 )
{
V_4 = F_29 ( V_4 , V_61 ,
V_62 ,
F_26 ) ;
V_4 = F_29 ( V_4 , V_63 ,
V_64 ,
F_27 ) ;
V_4 = F_29 ( V_4 , V_65 ,
V_66 ,
F_28 ) ;
V_4 &= ~ V_67 ;
V_4 &= ~ F_2 ( 51 , 48 ) ;
return V_4 ;
}
static T_1 F_32 ( T_1 V_4 )
{
V_4 = F_29 ( V_4 , V_68 ,
V_69 ,
F_26 ) ;
V_4 = F_29 ( V_4 , V_70 ,
V_71 ,
F_27 ) ;
V_4 = F_29 ( V_4 , V_72 ,
V_73 ,
F_28 ) ;
V_4 &= ~ V_74 ;
V_4 &= ~ F_2 ( 51 , 48 ) ;
return V_4 ;
}
static unsigned long F_33 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
struct V_10 * V_11 = & V_18 -> V_9 -> V_12 . V_13 ;
return F_1 ( V_11 -> V_75 , V_19 & 7 , V_5 ) ;
}
static void F_34 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_10 * V_11 = & V_18 -> V_9 -> V_12 . V_13 ;
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
T_1 V_76 , V_75 ;
if ( V_43 -> V_44 )
return;
do {
V_76 = V_11 -> V_75 ;
V_75 = V_76 ;
V_75 = F_3 ( V_75 , V_19 & 4 , V_5 , V_6 ) ;
V_75 = F_32 ( V_75 ) ;
} while ( F_35 ( & V_11 -> V_75 , V_76 ,
V_75 ) != V_76 );
}
static unsigned long F_36 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
return F_1 ( V_43 -> V_77 , V_19 & 7 , V_5 ) ;
}
static void F_37 ( struct V_17 * V_18 ,
T_2 V_19 , unsigned int V_5 ,
unsigned long V_6 )
{
struct V_43 * V_43 = & V_18 -> V_12 . V_43 ;
T_1 V_78 , V_77 ;
if ( V_43 -> V_44 )
return;
do {
V_78 = V_43 -> V_77 ;
V_77 = V_78 ;
V_77 = F_3 ( V_77 , V_19 & 4 , V_5 , V_6 ) ;
V_77 = F_31 ( V_77 ) ;
} while ( F_35 ( & V_43 -> V_77 , V_78 ,
V_77 ) != V_78 );
}
unsigned int F_38 ( struct V_79 * V_80 )
{
V_80 -> V_81 = V_82 ;
V_80 -> V_83 = F_39 ( V_82 ) ;
F_40 ( & V_80 -> V_80 , & V_84 ) ;
return V_85 ;
}
int F_41 ( struct V_9 * V_9 , T_2 V_86 )
{
struct V_17 * V_18 ;
int V_87 , V_39 = 0 ;
F_42 (c, vcpu, kvm) {
T_2 V_88 = V_86 + V_87 * V_85 * 2 ;
T_2 V_89 = V_88 + V_85 ;
struct V_79 * V_90 = & V_18 -> V_12 . V_43 . V_91 ;
struct V_79 * V_92 = & V_18 -> V_12 . V_43 . V_93 ;
F_40 ( & V_90 -> V_80 , & V_84 ) ;
V_90 -> V_94 = V_88 ;
V_90 -> V_95 = V_96 ;
V_90 -> V_81 = V_97 ;
V_90 -> V_83 = F_39 ( V_97 ) ;
V_90 -> V_98 = V_18 ;
F_43 ( & V_9 -> V_99 ) ;
V_39 = F_44 ( V_9 , V_100 , V_88 ,
V_85 , & V_90 -> V_80 ) ;
F_45 ( & V_9 -> V_99 ) ;
if ( V_39 )
break;
F_40 ( & V_92 -> V_80 , & V_84 ) ;
V_92 -> V_94 = V_89 ;
V_92 -> V_95 = V_96 ;
V_92 -> V_81 = V_101 ;
V_92 -> V_83 = F_39 ( V_101 ) ;
V_92 -> V_98 = V_18 ;
F_43 ( & V_9 -> V_99 ) ;
V_39 = F_44 ( V_9 , V_100 , V_89 ,
V_85 , & V_92 -> V_80 ) ;
F_45 ( & V_9 -> V_99 ) ;
if ( V_39 ) {
F_46 ( V_9 , V_100 ,
& V_90 -> V_80 ) ;
break;
}
}
if ( V_39 ) {
for ( V_87 -- ; V_87 >= 0 ; V_87 -- ) {
struct V_43 * V_43 ;
V_18 = F_47 ( V_9 , V_87 ) ;
V_43 = & V_18 -> V_12 . V_43 ;
F_46 ( V_9 , V_100 ,
& V_43 -> V_91 . V_80 ) ;
F_46 ( V_9 , V_100 ,
& V_43 -> V_93 . V_80 ) ;
}
}
return V_39 ;
}
static int F_48 ( T_1 V_102 , T_4 V_103 , struct V_17 * V_18 )
{
unsigned long V_104 ;
int V_105 ;
V_104 = F_22 ( V_18 ) ;
V_105 = F_49 ( V_104 , 0 ) ;
V_104 &= ~ V_106 ;
if ( V_102 != V_104 )
return - 1 ;
if ( ! ( V_103 & F_50 ( V_105 ) ) )
return - 1 ;
return V_105 ;
}
void F_51 ( struct V_17 * V_18 , T_1 V_4 )
{
struct V_9 * V_9 = V_18 -> V_9 ;
struct V_17 * V_107 ;
T_4 V_108 ;
T_1 V_40 ;
int V_109 , V_87 ;
int V_47 = V_18 -> V_47 ;
bool V_110 ;
V_109 = ( V_4 & V_111 ) >> V_112 ;
V_110 = V_4 & F_52 ( V_113 ) ;
V_108 = ( V_4 & V_114 ) >> V_115 ;
V_40 = F_53 ( V_4 , 3 ) ;
V_40 |= F_53 ( V_4 , 2 ) ;
V_40 |= F_53 ( V_4 , 1 ) ;
F_42 (c, c_vcpu, kvm) {
struct V_37 * V_38 ;
if ( ! V_110 && V_108 == 0 )
break;
if ( V_110 && V_87 == V_47 )
continue;
if ( ! V_110 ) {
int V_105 ;
V_105 = F_48 ( V_40 , V_108 , V_107 ) ;
if ( V_105 == - 1 )
continue;
V_108 &= ~ F_50 ( V_105 ) ;
}
V_38 = F_10 ( V_18 -> V_9 , V_107 , V_109 ) ;
F_14 ( & V_38 -> V_41 ) ;
V_38 -> V_116 = true ;
F_54 ( V_18 -> V_9 , V_38 ) ;
F_12 ( V_18 -> V_9 , V_38 ) ;
}
}
