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
T_3 * V_12 = F_14 ( & V_8 -> V_14 -> V_15 . V_16 . V_28 ,
V_8 -> V_3 , V_11 ) ;
F_3 ( V_10 , V_12 , V_11 ,
V_18 | V_19 ) ;
return false ;
}
static T_3 F_15 ( struct V_14 * V_14 , int V_29 )
{
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
int V_30 ;
T_3 V_31 = 0 ;
V_29 -= V_32 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ )
V_31 |= 1 << ( V_2 -> V_34 [ V_29 + V_30 ] + V_30 * 8 ) ;
return V_31 ;
}
static void F_16 ( struct V_14 * V_14 , T_3 V_31 , int V_29 )
{
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
struct V_7 * V_8 ;
int V_30 , V_35 ;
unsigned long * V_36 ;
T_3 V_37 ;
V_29 -= V_32 ;
for ( V_30 = 0 ; V_30 < V_33 ; V_30 ++ ) {
int V_38 = V_30 * V_39 ;
V_37 = F_17 ( ( V_31 >> V_38 ) & 0xffU ) ;
V_37 = V_37 ? ( V_37 - 1 ) : 0 ;
V_2 -> V_34 [ V_29 + V_30 ] = V_37 ;
F_18 (c, vcpu, kvm) {
V_36 = F_19 ( & V_2 -> V_40 [ V_35 ] ) ;
if ( V_35 == V_37 )
F_20 ( V_29 + V_30 , V_36 ) ;
else
F_21 ( V_29 + V_30 , V_36 ) ;
}
}
}
static bool F_22 ( struct V_7 * V_8 ,
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
V_12 = F_15 ( V_8 -> V_14 , V_11 & ~ 3U ) ;
F_3 ( V_10 , & V_12 , V_11 ,
V_18 | V_19 ) ;
if ( V_10 -> V_20 ) {
F_16 ( V_8 -> V_14 , V_12 , V_11 & ~ 3U ) ;
F_4 ( V_8 -> V_14 ) ;
return true ;
}
return false ;
}
static bool F_23 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
T_3 * V_12 ;
V_12 = F_24 ( & V_8 -> V_14 -> V_15 . V_16 . V_42 ,
V_8 -> V_3 , V_11 >> 1 ) ;
return F_25 ( V_12 , V_10 , V_11 ) ;
}
static bool F_26 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
T_3 V_12 ;
F_3 ( V_10 , & V_12 , V_11 ,
V_43 | V_19 ) ;
if ( V_10 -> V_20 ) {
F_27 ( V_8 , V_12 ) ;
F_4 ( V_8 -> V_14 ) ;
return true ;
}
return false ;
}
static bool F_28 ( struct V_7 * V_8 ,
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
F_29 ( V_10 , ~ 0 , V_12 ) ;
return false ;
}
static bool F_30 ( struct V_7 * V_8 ,
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
V_12 = F_31 ( V_10 , ~ 0 ) ;
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
static bool F_32 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
if ( ! V_10 -> V_20 )
return F_28 ( V_8 , V_10 , V_11 ) ;
else
return F_30 ( V_8 , V_10 , V_11 , true ) ;
}
static bool F_33 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
if ( ! V_10 -> V_20 )
return F_28 ( V_8 , V_10 , V_11 ) ;
else
return F_30 ( V_8 , V_10 , V_11 , false ) ;
}
static bool F_34 ( struct V_7 * V_8 , struct V_51 * V_52 ,
struct V_9 * V_10 )
{
unsigned long V_53 = V_8 -> V_14 -> V_15 . V_16 . V_54 ;
if ( ! F_35 ( V_10 -> V_55 , V_10 -> V_56 , V_53 ,
V_57 ) )
return false ;
if ( V_10 -> V_56 > 4 ) {
F_36 ( V_8 , V_10 -> V_55 ) ;
return true ;
}
return F_37 ( V_8 , V_52 , V_10 , V_58 , V_53 ) ;
}
static void F_27 ( struct V_7 * V_8 , T_3 V_12 )
{
struct V_14 * V_14 = V_8 -> V_14 ;
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
int V_59 = F_5 ( & V_14 -> V_21 ) ;
T_1 V_60 ;
int V_4 , V_61 , V_35 , V_3 ;
V_3 = V_8 -> V_3 ;
V_4 = V_12 & 0xf ;
V_60 = ( V_12 >> 16 ) & 0xff ;
V_61 = ( V_12 >> 24 ) & 3 ;
switch ( V_61 ) {
case 0 :
if ( ! V_60 )
return;
break;
case 1 :
V_60 = ( ( 1 << V_59 ) - 1 ) & ~ ( 1 << V_3 ) & 0xff ;
break;
case 2 :
V_60 = 1 << V_3 ;
break;
}
F_18 (c, vcpu, kvm) {
if ( V_60 & 1 ) {
F_38 ( V_8 , V_4 ) ;
* F_1 ( V_2 , V_35 , V_4 ) |= 1 << V_3 ;
F_39 ( L_1 ,
V_4 , V_3 , V_35 ) ;
}
V_60 >>= 1 ;
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
F_21 ( V_35 , & V_46 ) ;
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
const struct V_62 * V_63 )
{
int V_64 = 0 ;
if ( ! F_46 ( V_14 ) )
return 0 ;
F_47 ( & V_14 -> V_65 ) ;
if ( F_48 ( V_14 ) )
goto V_66;
if ( F_49 ( V_14 -> V_15 . V_16 . V_54 ) ||
F_49 ( V_14 -> V_15 . V_16 . V_67 ) ) {
F_50 ( L_2 ) ;
V_64 = - V_68 ;
goto V_66;
}
V_64 = F_51 ( V_14 ) ;
if ( V_64 ) {
F_50 ( L_3 ) ;
goto V_66;
}
V_64 = F_52 ( V_14 , V_14 -> V_15 . V_16 . V_67 ,
V_63 -> V_69 , V_70 ,
true ) ;
if ( V_64 ) {
F_50 ( L_4 ) ;
goto V_66;
}
V_14 -> V_15 . V_16 . V_71 = true ;
V_66:
if ( V_64 )
F_53 ( V_14 ) ;
F_54 ( & V_14 -> V_65 ) ;
return V_64 ;
}
static void F_55 ( struct V_7 * V_8 , int V_29 , int V_72 )
{
struct V_1 * V_2 = & V_8 -> V_14 -> V_15 . V_16 ;
* F_1 ( V_2 , V_8 -> V_3 , V_29 ) |= 1 << V_72 ;
}
static int F_56 ( struct V_14 * V_14 )
{
int V_30 ;
for ( V_30 = V_32 ; V_30 < V_14 -> V_15 . V_16 . V_22 ; V_30 += 4 )
F_16 ( V_14 , 0 , V_30 ) ;
return 0 ;
}
void F_57 ( struct V_14 * V_14 )
{
struct V_1 * V_2 = & V_14 -> V_15 . V_16 ;
V_2 -> V_73 . V_74 = F_34 ;
V_2 -> V_73 . V_75 = F_40 ;
V_2 -> V_73 . V_76 = F_55 ;
V_2 -> V_73 . V_77 = F_56 ;
V_2 -> V_73 . V_78 = F_45 ;
V_14 -> V_15 . V_79 = V_80 ;
}
static bool F_58 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
bool V_48 = false ;
struct V_81 V_82 ;
T_3 * V_83 ;
T_3 V_12 ;
F_59 ( V_8 , & V_82 ) ;
switch ( V_11 & ~ 0x3 ) {
case V_84 :
V_83 = & V_82 . V_85 ;
break;
case V_86 :
V_83 = & V_82 . V_87 ;
break;
case V_88 :
V_83 = & V_82 . V_89 ;
break;
case V_90 :
V_83 = & V_82 . V_91 ;
break;
default:
F_60 () ;
}
if ( ! V_10 -> V_20 ) {
V_12 = * V_83 ;
F_29 ( V_10 , ~ 0 , V_12 ) ;
} else {
V_12 = F_31 ( V_10 , ~ 0 ) ;
if ( V_12 != * V_83 ) {
* V_83 = V_12 ;
F_61 ( V_8 , & V_82 ) ;
V_48 = true ;
}
}
return V_48 ;
}
static bool F_62 ( struct V_7 * V_8 ,
struct V_9 * V_10 , T_2 V_11 )
{
return F_58 ( V_8 , V_10 , V_90 ) ;
}
static bool F_63 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_2 V_11 )
{
T_3 V_12 ;
if ( V_10 -> V_20 )
return false ;
V_12 = ( V_24 << 20 ) |
( V_92 << 16 ) |
( V_25 << 0 ) ;
F_29 ( V_10 , ~ 0 , V_12 ) ;
return false ;
}
static int F_64 ( struct V_93 * V_94 ,
struct V_95 * V_96 ,
T_3 * V_12 , bool V_20 )
{
const struct V_97 * V_98 = NULL , * V_99 ;
T_2 V_11 ;
int V_64 , V_100 , V_35 ;
struct V_7 * V_8 , * V_101 ;
struct V_1 * V_16 ;
struct V_9 V_10 ;
V_11 = V_96 -> V_96 & V_102 ;
V_100 = ( V_96 -> V_96 & V_103 ) >>
V_104 ;
F_47 ( & V_94 -> V_14 -> V_65 ) ;
V_64 = F_51 ( V_94 -> V_14 ) ;
if ( V_64 )
goto V_66;
if ( V_100 >= F_5 ( & V_94 -> V_14 -> V_21 ) ) {
V_64 = - V_105 ;
goto V_66;
}
V_8 = F_65 ( V_94 -> V_14 , V_100 ) ;
V_16 = & V_94 -> V_14 -> V_15 . V_16 ;
V_10 . V_56 = 4 ;
V_10 . V_20 = V_20 ;
if ( V_20 )
F_29 ( & V_10 , ~ 0 , * V_12 ) ;
switch ( V_96 -> V_106 ) {
case V_107 :
V_10 . V_55 = V_16 -> V_54 + V_11 ;
V_99 = V_58 ;
break;
case V_108 :
V_10 . V_55 = V_16 -> V_67 + V_11 ;
V_99 = V_109 ;
break;
default:
F_60 () ;
}
V_98 = F_66 ( V_99 , & V_10 , V_11 ) ;
if ( F_67 ( ! V_98 || ! V_98 -> V_74 ) ) {
V_64 = - V_68 ;
goto V_66;
}
F_68 ( & V_16 -> V_65 ) ;
F_18 (c, tmp_vcpu, dev->kvm) {
if ( F_67 ( V_101 -> V_110 != - 1 ) ) {
V_64 = - V_111 ;
goto V_112;
}
}
F_18 (c, tmp_vcpu, dev->kvm)
F_69 ( V_101 ) ;
V_11 -= V_98 -> V_53 ;
V_98 -> V_74 ( V_8 , & V_10 , V_11 ) ;
if ( ! V_20 )
* V_12 = F_31 ( & V_10 , ~ 0 ) ;
V_64 = 0 ;
V_112:
F_70 ( & V_16 -> V_65 ) ;
V_66:
F_54 ( & V_94 -> V_14 -> V_65 ) ;
return V_64 ;
}
static int F_71 ( struct V_93 * V_94 , T_3 type )
{
return F_72 ( V_94 -> V_14 , type ) ;
}
static void F_73 ( struct V_93 * V_94 )
{
F_74 ( V_94 ) ;
}
static int F_75 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
int V_64 ;
V_64 = F_76 ( V_94 , V_96 ) ;
if ( V_64 != - V_68 )
return V_64 ;
switch ( V_96 -> V_106 ) {
case V_107 :
case V_108 : {
T_3 T_4 * V_113 = ( T_3 T_4 * ) ( long ) V_96 -> V_114 ;
T_3 V_12 ;
if ( F_77 ( V_12 , V_113 ) )
return - V_115 ;
return F_64 ( V_94 , V_96 , & V_12 , true ) ;
}
}
return - V_68 ;
}
static int F_78 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
int V_64 ;
V_64 = F_79 ( V_94 , V_96 ) ;
if ( V_64 != - V_68 )
return V_64 ;
switch ( V_96 -> V_106 ) {
case V_107 :
case V_108 : {
T_3 T_4 * V_113 = ( T_3 T_4 * ) ( long ) V_96 -> V_114 ;
T_3 V_12 = 0 ;
V_64 = F_64 ( V_94 , V_96 , & V_12 , false ) ;
if ( V_64 )
return V_64 ;
return F_80 ( V_12 , V_113 ) ;
}
}
return - V_68 ;
}
static int F_81 ( struct V_93 * V_94 ,
struct V_95 * V_96 )
{
T_2 V_11 ;
switch ( V_96 -> V_106 ) {
case V_116 :
switch ( V_96 -> V_96 ) {
case V_117 :
case V_118 :
return 0 ;
}
break;
case V_107 :
V_11 = V_96 -> V_96 & V_102 ;
return F_82 ( V_58 , V_11 ) ;
case V_108 :
V_11 = V_96 -> V_96 & V_102 ;
return F_82 ( V_109 , V_11 ) ;
case V_119 :
return 0 ;
case V_120 :
switch ( V_96 -> V_96 ) {
case V_121 :
return 0 ;
}
}
return - V_68 ;
}
