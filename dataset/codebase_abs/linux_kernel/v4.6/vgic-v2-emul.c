static T_1 * F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
return V_2 -> V_5 + V_3 * V_6 + V_4 ;
}
static bool F_2 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
T_3 V_12 ;
T_3 V_13 = V_11 & 3 ;
switch ( V_11 & ~ 3 ) {
case 0 :
V_12 = V_8 -> V_14 -> V_15 . V_16 . V_17 ;
F_3 ( V_10 , & V_12 , V_13 ,
V_18 | V_19 ) ;
if ( V_10 -> V_20 ) {
V_8 -> V_14 -> V_15 . V_16 . V_17 = V_12 & 1 ;
F_4 ( V_8 -> V_14 ) ;
return true ;
}
break;
case 4 :
V_12 = ( F_5 ( & V_8 -> V_14 -> V_21 ) - 1 ) << 5 ;
V_12 |= ( V_8 -> V_14 -> V_15 . V_16 . V_22 >> 5 ) - 1 ;
F_3 ( V_10 , & V_12 , V_13 ,
V_18 | V_23 ) ;
break;
case 8 :
V_12 = ( V_24 << 24 ) | ( V_25 << 0 ) ;
F_3 ( V_10 , & V_12 , V_13 ,
V_18 | V_23 ) ;
break;
}
return false ;
}
static bool F_6 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
return F_7 ( V_8 -> V_14 , V_10 , V_11 ,
V_8 -> V_3 , V_26 ) ;
}
static bool F_8 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
return F_7 ( V_8 -> V_14 , V_10 , V_11 ,
V_8 -> V_3 , V_27 ) ;
}
static bool F_9 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
return F_10 ( V_8 -> V_14 , V_10 , V_11 ,
V_8 -> V_3 ) ;
}
static bool F_11 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
return F_12 ( V_8 -> V_14 , V_10 , V_11 ,
V_8 -> V_3 ) ;
}
static bool F_13 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
return F_14 ( V_8 -> V_14 , V_10 , V_11 ,
V_8 -> V_3 ) ;
}
static bool F_15 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
return F_16 ( V_8 -> V_14 , V_10 , V_11 ,
V_8 -> V_3 ) ;
}
static bool F_17 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
T_3 * V_12 = F_18 ( & V_8 -> V_14 -> V_15 . V_16 . V_28 ,
V_8 -> V_3 , V_11 ) ;
F_3 ( V_10 , V_12 , V_11 ,
V_18 | V_19 ) ;
return false ;
}
static T_3 F_19 ( struct V_14 * V_14 , int V_29 )
{
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
int V_30 ;
T_3 V_31 = 0 ;
V_29 -= V_32 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ )
V_31 |= 1 << ( V_2 -> V_34 [ V_29 + V_30 ] + V_30 * 8 ) ;
return V_31 ;
}
static void F_20 ( struct V_14 * V_14 , T_3 V_31 , int V_29 )
{
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_30 , V_35 ;
unsigned long * V_36 ;
T_3 V_37 ;
V_29 -= V_32 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
int V_38 = V_30 * V_39 ;
V_37 = F_21 ( ( V_31 >> V_38 ) & 0xffU ) ;
V_37 = V_37 ? ( V_37 - 1 ) : 0 ;
V_2 -> V_34 [ V_29 + V_30 ] = V_37 ;
F_22 (c, vcpu, kvm) {
V_36 = F_23 ( & V_2 -> V_40 [ V_35 ] ) ;
if ( V_35 == V_37 )
F_24 ( V_29 + V_30 , V_36 ) ;
else
F_25 ( V_29 + V_30 , V_36 ) ;
}
}
}
static bool F_26 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
T_3 V_12 ;
if ( V_11 < 32 ) {
T_3 V_41 ;
V_41 = 1 << V_8 -> V_3 ;
V_41 |= V_41 << 8 ;
V_41 |= V_41 << 16 ;
F_3 ( V_10 , & V_41 , V_11 ,
V_18 | V_23 ) ;
return false ;
}
V_12 = F_19 ( V_8 -> V_14 , V_11 & ~ 3U ) ;
F_3 ( V_10 , & V_12 , V_11 ,
V_18 | V_19 ) ;
if ( V_10 -> V_20 ) {
F_20 ( V_8 -> V_14 , V_12 , V_11 & ~ 3U ) ;
F_4 ( V_8 -> V_14 ) ;
return true ;
}
return false ;
}
static bool F_27 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
T_3 * V_12 ;
V_12 = F_28 ( & V_8 -> V_14 -> V_15 . V_16 . V_42 ,
V_8 -> V_3 , V_11 >> 1 ) ;
return F_29 ( V_12 , V_10 , V_11 ) ;
}
static bool F_30 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
T_3 V_12 ;
F_3 ( V_10 , & V_12 , V_11 ,
V_43 | V_19 ) ;
if ( V_10 -> V_20 ) {
F_31 ( V_8 , V_12 ) ;
F_4 ( V_8 -> V_14 ) ;
return true ;
}
return false ;
}
static bool F_32 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
struct V_1 * V_2 = & V_8 -> V_14 -> V_15 . V_16 ;
int V_4 ;
int V_44 = ( V_11 & ~ 0x3 ) ;
int V_45 = V_44 + 3 ;
int V_3 = V_8 -> V_3 ;
T_3 V_12 = 0 ;
for ( V_4 = V_44 ; V_4 <= V_45 ; V_4 ++ ) {
T_1 V_46 = * F_1 ( V_2 , V_3 , V_4 ) ;
V_12 |= ( ( T_3 ) V_46 ) << ( 8 * ( V_4 - V_44 ) ) ;
}
F_33 ( V_10 , ~ 0 , V_12 ) ;
return false ;
}
static bool F_34 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 , bool V_47 )
{
struct V_1 * V_2 = & V_8 -> V_14 -> V_15 . V_16 ;
int V_4 ;
int V_44 = ( V_11 & ~ 0x3 ) ;
int V_45 = V_44 + 3 ;
int V_3 = V_8 -> V_3 ;
T_3 V_12 ;
bool V_48 = false ;
V_12 = F_35 ( V_10 , ~ 0 ) ;
for ( V_4 = V_44 ; V_4 <= V_45 ; V_4 ++ ) {
T_1 V_49 = V_12 >> ( 8 * ( V_4 - V_44 ) ) ;
T_1 * V_50 = F_1 ( V_2 , V_3 , V_4 ) ;
if ( V_47 ) {
if ( ( * V_50 & V_49 ) != V_49 )
V_48 = true ;
* V_50 |= V_49 ;
} else {
if ( * V_50 & V_49 )
V_48 = true ;
* V_50 &= ~ V_49 ;
}
}
if ( V_48 )
F_4 ( V_8 -> V_14 ) ;
return V_48 ;
}
static bool F_36 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
if ( ! V_10 -> V_20 )
return F_32 ( V_8 , V_10 , V_11 ) ;
else
return F_34 ( V_8 , V_10 , V_11 , true ) ;
}
static bool F_37 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
if ( ! V_10 -> V_20 )
return F_32 ( V_8 , V_10 , V_11 ) ;
else
return F_34 ( V_8 , V_10 , V_11 , false ) ;
}
static void F_31 ( struct V_7 * V_8 , T_3 V_12 )
{
struct V_14 * V_14 = V_8 -> V_14 ;
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
int V_51 = F_5 ( & V_14 -> V_21 ) ;
T_1 V_52 ;
int V_4 , V_53 , V_35 , V_3 ;
V_3 = V_8 -> V_3 ;
V_4 = V_12 & 0xf ;
V_52 = ( V_12 >> 16 ) & 0xff ;
V_53 = ( V_12 >> 24 ) & 3 ;
switch ( V_53 ) {
case 0 :
if ( ! V_52 )
return;
break;
case 1 :
V_52 = ( ( 1 << V_51 ) - 1 ) & ~ ( 1 << V_3 ) & 0xff ;
break;
case 2 :
V_52 = 1 << V_3 ;
break;
}
F_22 (c, vcpu, kvm) {
if ( V_52 & 1 ) {
F_38 ( V_8 , V_4 ) ;
* F_1 ( V_2 , V_35 , V_4 ) |= 1 << V_3 ;
F_39 ( L_1 ,
V_4 , V_3 , V_35 ) ;
}
V_52 >>= 1 ;
}
}
static bool F_40 ( struct V_7 * V_8 , int V_29 )
{
struct V_1 * V_2 = & V_8 -> V_14 -> V_15 . V_16 ;
unsigned long V_46 ;
int V_3 = V_8 -> V_3 ;
int V_35 ;
V_46 = * F_1 ( V_2 , V_3 , V_29 ) ;
F_41 (c, &sources, dist->nr_cpus) {
if ( F_42 ( V_8 , V_35 , V_29 ) )
F_25 ( V_35 , & V_46 ) ;
}
* F_1 ( V_2 , V_3 , V_29 ) = V_46 ;
if ( ! V_46 ) {
F_43 ( V_8 , V_29 ) ;
F_44 ( V_8 , V_29 ) ;
return true ;
}
return false ;
}
static int F_45 ( struct V_14 * V_14 ,
const struct V_54 * V_55 )
{
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
int V_56 = 0 ;
if ( ! F_46 ( V_14 ) )
return 0 ;
F_47 ( & V_14 -> V_57 ) ;
if ( F_48 ( V_14 ) )
goto V_58;
if ( F_49 ( V_2 -> V_59 ) ||
F_49 ( V_2 -> V_60 ) ) {
F_50 ( L_2 ) ;
V_56 = - V_61 ;
goto V_58;
}
F_51 ( V_14 , V_2 -> V_59 ,
V_62 ,
V_63 , - 1 , & V_2 -> V_64 ) ;
V_56 = F_52 ( V_14 ) ;
if ( V_56 ) {
F_50 ( L_3 ) ;
goto V_65;
}
V_56 = F_53 ( V_14 , V_2 -> V_60 ,
V_55 -> V_66 , V_67 ,
true ) ;
if ( V_56 ) {
F_50 ( L_4 ) ;
goto V_65;
}
V_2 -> V_68 = true ;
goto V_58;
V_65:
F_54 ( V_14 , V_69 , & V_2 -> V_64 . V_70 ) ;
V_58:
if ( V_56 )
F_55 ( V_14 ) ;
F_56 ( & V_14 -> V_57 ) ;
return V_56 ;
}
static void F_57 ( struct V_7 * V_8 , int V_29 , int V_71 )
{
struct V_1 * V_2 = & V_8 -> V_14 -> V_15 . V_16 ;
* F_1 ( V_2 , V_8 -> V_3 , V_29 ) |= 1 << V_71 ;
}
static int F_58 ( struct V_14 * V_14 )
{
int V_30 ;
for ( V_30 = V_32 ; V_30 < V_14 -> V_15 . V_16 . V_22 ; V_30 += 4 )
F_20 ( V_14 , 0 , V_30 ) ;
return 0 ;
}
void F_59 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
V_2 -> V_72 . V_73 = F_40 ;
V_2 -> V_72 . V_74 = F_57 ;
V_2 -> V_72 . V_75 = F_58 ;
V_2 -> V_72 . V_76 = F_45 ;
V_14 -> V_15 . V_77 = V_78 ;
}
static bool F_60 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
bool V_48 = false ;
struct V_79 V_80 ;
T_3 * V_81 ;
T_3 V_12 ;
F_61 ( V_8 , & V_80 ) ;
switch ( V_11 & ~ 0x3 ) {
case V_82 :
V_81 = & V_80 . V_83 ;
break;
case V_84 :
V_81 = & V_80 . V_85 ;
break;
case V_86 :
V_81 = & V_80 . V_87 ;
break;
case V_88 :
V_81 = & V_80 . V_89 ;
break;
default:
F_62 () ;
}
if ( ! V_10 -> V_20 ) {
V_12 = * V_81 ;
F_33 ( V_10 , ~ 0 , V_12 ) ;
} else {
V_12 = F_35 ( V_10 , ~ 0 ) ;
if ( V_12 != * V_81 ) {
* V_81 = V_12 ;
F_63 ( V_8 , & V_80 ) ;
V_48 = true ;
}
}
return V_48 ;
}
static bool F_64 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
return F_60 ( V_8 , V_10 , V_88 ) ;
}
static bool F_65 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
T_3 V_12 ;
if ( V_10 -> V_20 )
return false ;
V_12 = ( V_24 << 20 ) |
( V_90 << 16 ) |
( V_25 << 0 ) ;
F_33 ( V_10 , ~ 0 , V_12 ) ;
return false ;
}
static int F_66 ( struct V_91 * V_70 ,
struct V_92 * V_93 ,
T_3 * V_12 , bool V_20 )
{
const struct V_94 * V_95 = NULL , * V_96 ;
T_2 V_11 ;
int V_56 , V_97 , V_35 ;
struct V_7 * V_8 , * V_98 ;
struct V_1 * V_16 ;
struct V_9 V_10 ;
T_3 V_99 ;
V_11 = V_93 -> V_93 & V_100 ;
V_97 = ( V_93 -> V_93 & V_101 ) >>
V_102 ;
F_47 ( & V_70 -> V_14 -> V_57 ) ;
V_56 = F_52 ( V_70 -> V_14 ) ;
if ( V_56 )
goto V_58;
if ( V_97 >= F_5 ( & V_70 -> V_14 -> V_21 ) ) {
V_56 = - V_103 ;
goto V_58;
}
V_8 = F_67 ( V_70 -> V_14 , V_97 ) ;
V_16 = & V_70 -> V_14 -> V_15 . V_16 ;
V_10 . V_104 = 4 ;
V_10 . V_20 = V_20 ;
V_10 . V_99 = & V_99 ;
if ( V_20 )
F_33 ( & V_10 , ~ 0 , * V_12 ) ;
switch ( V_93 -> V_105 ) {
case V_106 :
V_10 . V_107 = V_16 -> V_59 + V_11 ;
V_96 = V_63 ;
break;
case V_108 :
V_10 . V_107 = V_16 -> V_60 + V_11 ;
V_96 = V_109 ;
break;
default:
F_62 () ;
}
V_95 = F_68 ( V_96 , 4 , V_11 ) ;
if ( F_69 ( ! V_95 || ! V_95 -> V_110 ) ) {
V_56 = - V_61 ;
goto V_58;
}
F_70 ( & V_16 -> V_57 ) ;
F_22 (c, tmp_vcpu, dev->kvm) {
if ( F_69 ( V_98 -> V_111 != - 1 ) ) {
V_56 = - V_112 ;
goto V_113;
}
}
F_22 (c, tmp_vcpu, dev->kvm)
F_71 ( V_98 ) ;
V_11 -= V_95 -> V_114 ;
V_95 -> V_110 ( V_8 , & V_10 , V_11 ) ;
if ( ! V_20 )
* V_12 = F_35 ( & V_10 , ~ 0 ) ;
V_56 = 0 ;
V_113:
F_72 ( & V_16 -> V_57 ) ;
V_58:
F_56 ( & V_70 -> V_14 -> V_57 ) ;
return V_56 ;
}
static int F_73 ( struct V_91 * V_70 , T_3 type )
{
return F_74 ( V_70 -> V_14 , type ) ;
}
static void F_75 ( struct V_91 * V_70 )
{
F_76 ( V_70 ) ;
}
static int F_77 ( struct V_91 * V_70 ,
struct V_92 * V_93 )
{
int V_56 ;
V_56 = F_78 ( V_70 , V_93 ) ;
if ( V_56 != - V_61 )
return V_56 ;
switch ( V_93 -> V_105 ) {
case V_106 :
case V_108 : {
T_3 T_4 * V_115 = ( T_3 T_4 * ) ( long ) V_93 -> V_116 ;
T_3 V_12 ;
if ( F_79 ( V_12 , V_115 ) )
return - V_117 ;
return F_66 ( V_70 , V_93 , & V_12 , true ) ;
}
}
return - V_61 ;
}
static int F_80 ( struct V_91 * V_70 ,
struct V_92 * V_93 )
{
int V_56 ;
V_56 = F_81 ( V_70 , V_93 ) ;
if ( V_56 != - V_61 )
return V_56 ;
switch ( V_93 -> V_105 ) {
case V_106 :
case V_108 : {
T_3 T_4 * V_115 = ( T_3 T_4 * ) ( long ) V_93 -> V_116 ;
T_3 V_12 = 0 ;
V_56 = F_66 ( V_70 , V_93 , & V_12 , false ) ;
if ( V_56 )
return V_56 ;
return F_82 ( V_12 , V_115 ) ;
}
}
return - V_61 ;
}
static int F_83 ( struct V_91 * V_70 ,
struct V_92 * V_93 )
{
T_2 V_11 ;
switch ( V_93 -> V_105 ) {
case V_118 :
switch ( V_93 -> V_93 ) {
case V_119 :
case V_120 :
return 0 ;
}
break;
case V_106 :
V_11 = V_93 -> V_93 & V_100 ;
return F_84 ( V_63 , V_11 ) ;
case V_108 :
V_11 = V_93 -> V_93 & V_100 ;
return F_84 ( V_109 , V_11 ) ;
case V_121 :
return 0 ;
case V_122 :
switch ( V_93 -> V_93 ) {
case V_123 :
return 0 ;
}
}
return - V_61 ;
}
