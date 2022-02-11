static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
V_5 &= ~ F_5 ( V_10 ) ;
F_6 ( V_5 , V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_11 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
V_5 |= F_5 ( V_10 ) ;
if ( V_11 )
V_5 |= F_5 ( V_12 ) ;
else
V_5 &= ~ F_5 ( V_12 ) ;
F_6 ( V_5 , V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return ! ! ( V_5 & F_5 ( V_13 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_3 , int V_11 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
if ( V_11 )
V_5 |= F_5 ( V_12 ) ;
else
V_5 &= ~ F_5 ( V_12 ) ;
F_6 ( V_5 , V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_14 )
{
T_1 time ;
T_1 V_5 ;
int V_15 = 0 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
if ( V_14 ) {
V_5 |= V_16 << V_17 ;
V_5 &= ~ V_18 ;
if ( V_14 < 61 ) {
V_5 |= 1 ;
V_5 &= ~ F_5 ( V_19 ) ;
V_5 &= ~ F_5 ( V_20 ) ;
} else if ( V_14 < 976 ) {
time = V_14 / 61 ;
V_5 |= time & V_18 ;
V_5 &= ~ F_5 ( V_19 ) ;
V_5 &= ~ F_5 ( V_20 ) ;
} else if ( V_14 < 3900 ) {
time = V_14 / 244 ;
V_5 |= time & V_18 ;
V_5 |= F_5 ( V_19 ) ;
V_5 &= ~ F_5 ( V_20 ) ;
} else if ( V_14 < 250000 ) {
time = V_14 / 15600 ;
V_5 |= time & V_18 ;
V_5 &= ~ F_5 ( V_19 ) ;
V_5 |= F_5 ( V_20 ) ;
} else if ( V_14 < 1000000 ) {
time = V_14 / 62500 ;
V_5 |= time & V_18 ;
V_5 |= F_5 ( V_19 ) ;
V_5 |= F_5 ( V_20 ) ;
} else {
V_5 &= ~ V_21 ;
V_15 = - V_22 ;
}
} else {
V_5 &= ~ F_5 ( V_19 ) ;
V_5 &= ~ F_5 ( V_20 ) ;
V_5 &= ~ V_18 ;
V_5 &= ~ V_21 ;
}
F_6 ( V_5 , V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_15 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_23 )
{
T_1 V_14 ;
if ( F_13 ( V_23 ) != V_24 )
return - V_25 ;
V_14 = F_14 ( V_23 ) ;
return F_11 ( V_2 , V_3 , V_14 ) ;
}
static void F_15 ( struct V_26 * V_27 , struct V_1 * V_2 )
{
T_1 V_5 ;
unsigned long V_4 ;
unsigned int V_28 , V_29 , V_30 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_31 ;
char * V_32 ;
char * V_33 ;
char * V_34 ;
char * V_35 ;
char * V_36 ;
char * V_37 ;
char * V_38 ;
char * V_39 ;
char * V_40 ;
char * V_41 ;
char * V_42 ;
char * V_43 ;
for ( V_28 = 0 ; V_28 < V_7 -> V_44 ; V_28 ++ ) {
F_16 ( V_27 , L_1 , V_28 ) ;
switch ( V_28 ) {
case 0 :
V_29 = 0 ;
V_30 = V_45 ;
break;
case 1 :
V_29 = 64 ;
V_30 = V_46 + V_29 ;
break;
case 2 :
V_29 = 128 ;
V_30 = V_47 + V_29 ;
break;
case 3 :
V_29 = 192 ;
V_30 = V_48 + V_29 ;
break;
default:
continue;
}
for (; V_29 < V_30 ; V_29 ++ ) {
F_16 ( V_27 , L_2 , V_29 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_29 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
if ( V_5 & F_5 ( V_49 ) ) {
V_33 = L_3 ;
if ( ! ( V_5 & F_5 ( V_50 ) ) &&
! ( V_5 & F_5 ( V_50 + 1 ) ) )
V_32 = L_4 ;
else if ( V_5 & F_5 ( V_50 ) &&
! ( V_5 & F_5 ( V_50 + 1 ) ) )
V_32 = L_5 ;
else if ( ! ( V_5 & F_5 ( V_50 ) ) &&
V_5 & F_5 ( V_50 + 1 ) )
V_32 = L_6 ;
else
V_32 = L_7 ;
if ( V_5 & F_5 ( V_51 ) )
V_31 = L_8 ;
else
V_31 = L_9 ;
} else {
V_33 =
L_10 ;
V_32 = L_11 ;
V_31 = L_11 ;
}
if ( V_5 & F_5 ( V_52 ) )
V_34 =
L_12 ;
else
V_34 =
L_13 ;
if ( V_5 & F_5 ( V_53 ) )
V_35 = L_14 ;
else
V_35 = L_15 ;
if ( V_5 & F_5 ( V_54 ) )
V_36 = L_16 ;
else
V_36 = L_17 ;
if ( V_5 & F_5 ( V_55 ) )
V_37 = L_18 ;
else
V_37 = L_19 ;
if ( V_5 & F_5 ( V_56 ) ) {
V_40 = L_20 ;
if ( V_5 & F_5 ( V_57 ) )
V_39 = L_21 ;
else
V_39 = L_22 ;
} else {
V_40 = L_23 ;
V_39 = L_11 ;
}
if ( V_5 & F_5 ( V_58 ) )
V_41 = L_24 ;
else
V_41 = L_25 ;
if ( V_5 & F_5 ( V_10 ) ) {
V_38 = L_11 ;
V_43 = L_26 ;
if ( V_5 & F_5 ( V_12 ) )
V_42 = L_27 ;
else
V_42 = L_28 ;
} else {
V_43 = L_29 ;
V_42 = L_11 ;
if ( V_5 & F_5 ( V_13 ) )
V_38 = L_30 ;
else
V_38 = L_31 ;
}
F_16 ( V_27 , L_32
L_33 ,
V_31 , V_32 , V_33 ,
V_34 , V_35 , V_36 ,
V_37 , V_38 , V_39 ,
V_40 , V_41 ,
V_42 , V_43 , V_5 ) ;
}
}
}
static void F_17 ( struct V_59 * V_60 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_18 ( V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
V_5 |= F_5 ( V_49 ) ;
V_5 |= F_5 ( V_52 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_19 ( struct V_59 * V_60 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_18 ( V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
V_5 &= ~ F_5 ( V_49 ) ;
V_5 &= ~ F_5 ( V_52 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_20 ( struct V_59 * V_60 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_18 ( V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
V_5 &= ~ F_5 ( V_52 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_21 ( struct V_59 * V_60 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_18 ( V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
V_5 |= F_5 ( V_52 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_22 ( struct V_59 * V_60 )
{
T_1 V_62 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_18 ( V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_62 = F_4 ( V_7 -> V_9 + V_63 ) ;
V_62 |= V_64 ;
F_6 ( V_62 , V_7 -> V_9 + V_63 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_23 ( struct V_59 * V_60 , unsigned int type )
{
int V_15 = 0 ;
T_1 V_5 ;
unsigned long V_4 , V_65 ;
struct V_1 * V_2 = F_18 ( V_60 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
V_65 = F_24 ( V_60 -> V_66 ) ;
if ( V_65 != V_67 )
type = V_65 ;
switch ( type & V_68 ) {
case V_69 :
V_5 &= ~ F_5 ( V_51 ) ;
V_5 &= ~ ( V_70 << V_50 ) ;
V_5 |= V_71 << V_50 ;
V_5 |= V_16 << V_17 ;
F_25 ( V_60 , V_72 ) ;
break;
case V_73 :
V_5 &= ~ F_5 ( V_51 ) ;
V_5 &= ~ ( V_70 << V_50 ) ;
V_5 |= V_74 << V_50 ;
V_5 |= V_16 << V_17 ;
F_25 ( V_60 , V_72 ) ;
break;
case V_75 :
V_5 &= ~ F_5 ( V_51 ) ;
V_5 &= ~ ( V_70 << V_50 ) ;
V_5 |= V_76 << V_50 ;
V_5 |= V_16 << V_17 ;
F_25 ( V_60 , V_72 ) ;
break;
case V_77 :
V_5 |= V_78 << V_51 ;
V_5 &= ~ ( V_70 << V_50 ) ;
V_5 |= V_71 << V_50 ;
V_5 &= ~ ( V_21 << V_17 ) ;
V_5 |= V_79 << V_17 ;
F_25 ( V_60 , V_80 ) ;
break;
case V_81 :
V_5 |= V_78 << V_51 ;
V_5 &= ~ ( V_70 << V_50 ) ;
V_5 |= V_74 << V_50 ;
V_5 &= ~ ( V_21 << V_17 ) ;
V_5 |= V_82 << V_17 ;
F_25 ( V_60 , V_80 ) ;
break;
case V_67 :
break;
default:
F_26 ( & V_7 -> V_83 -> V_84 , L_34 ) ;
V_15 = - V_22 ;
}
V_5 |= V_85 << V_86 ;
F_6 ( V_5 , V_7 -> V_9 + ( V_60 -> V_61 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_15 ;
}
static void F_27 ( struct V_59 * V_60 )
{
}
static T_2 F_28 ( int V_66 , void * V_87 )
{
struct V_6 * V_7 = V_87 ;
struct V_1 * V_2 = & V_7 -> V_2 ;
T_2 V_15 = V_88 ;
unsigned int V_29 , V_89 ;
unsigned long V_4 ;
T_1 * V_90 , V_91 ;
T_3 V_92 , V_93 ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_92 = F_4 ( V_7 -> V_9 + V_94 ) ;
V_92 <<= 32 ;
V_92 |= F_4 ( V_7 -> V_9 + V_95 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
V_92 &= ( 1ULL << 46 ) - 1 ;
V_90 = V_7 -> V_9 ;
for ( V_93 = 1 , V_89 = 0 ; V_92 ; V_93 <<= 1 , V_90 += 4 , V_89 += 4 ) {
if ( ! ( V_92 & V_93 ) )
continue;
V_92 &= ~ V_93 ;
for ( V_29 = 0 ; V_29 < 4 ; V_29 ++ ) {
V_91 = F_4 ( V_90 + V_29 ) ;
if ( ! ( V_91 & V_96 ) )
continue;
V_66 = F_29 ( V_2 -> V_97 , V_89 + V_29 ) ;
F_30 ( V_66 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_91 = F_4 ( V_90 + V_29 ) ;
F_6 ( V_91 , V_90 + V_29 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
V_15 = V_98 ;
}
}
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_91 = F_4 ( V_7 -> V_9 + V_63 ) ;
V_91 |= V_64 ;
F_6 ( V_91 , V_7 -> V_9 + V_63 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_15 ;
}
static int F_31 ( struct V_99 * V_100 )
{
struct V_6 * V_7 = F_32 ( V_100 ) ;
return V_7 -> V_101 ;
}
static const char * F_33 ( struct V_99 * V_100 ,
unsigned V_102 )
{
struct V_6 * V_7 = F_32 ( V_100 ) ;
return V_7 -> V_103 [ V_102 ] . V_104 ;
}
static int F_34 ( struct V_99 * V_100 ,
unsigned V_102 ,
const unsigned * * V_105 ,
unsigned * V_106 )
{
struct V_6 * V_7 = F_32 ( V_100 ) ;
* V_105 = V_7 -> V_103 [ V_102 ] . V_105 ;
* V_106 = V_7 -> V_103 [ V_102 ] . V_107 ;
return 0 ;
}
static int F_35 ( struct V_99 * V_100 ,
unsigned int V_108 ,
unsigned long * V_23 )
{
T_1 V_5 ;
unsigned V_109 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_32 ( V_100 ) ;
enum V_110 V_111 = F_13 ( * V_23 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_108 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
switch ( V_111 ) {
case V_24 :
V_109 = V_5 & V_18 ;
break;
case V_112 :
V_109 = ( V_5 >> V_58 ) & F_5 ( 0 ) ;
break;
case V_113 :
V_109 = ( V_5 >> V_57 ) & ( F_5 ( 0 ) | F_5 ( 1 ) ) ;
break;
case V_114 :
V_109 = ( V_5 >> V_115 ) & V_116 ;
break;
default:
F_26 ( & V_7 -> V_83 -> V_84 , L_35 ,
V_111 ) ;
return - V_25 ;
}
* V_23 = F_36 ( V_111 , V_109 ) ;
return 0 ;
}
static int F_37 ( struct V_99 * V_100 , unsigned int V_108 ,
unsigned long * V_117 , unsigned V_118 )
{
int V_29 ;
T_1 V_109 ;
int V_15 = 0 ;
T_1 V_5 ;
unsigned long V_4 ;
enum V_110 V_111 ;
struct V_6 * V_7 = F_32 ( V_100 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
for ( V_29 = 0 ; V_29 < V_118 ; V_29 ++ ) {
V_111 = F_13 ( V_117 [ V_29 ] ) ;
V_109 = F_14 ( V_117 [ V_29 ] ) ;
V_5 = F_4 ( V_7 -> V_9 + V_108 * 4 ) ;
switch ( V_111 ) {
case V_24 :
V_5 &= ~ V_18 ;
V_5 |= V_109 & V_18 ;
break;
case V_112 :
V_5 &= ~ F_5 ( V_58 ) ;
V_5 |= ( V_109 & F_5 ( 0 ) ) << V_58 ;
break;
case V_113 :
V_5 &= ~ F_5 ( V_57 ) ;
V_5 |= ( V_109 & F_5 ( 0 ) ) << V_57 ;
V_5 &= ~ F_5 ( V_56 ) ;
V_5 |= ( ( V_109 >> 1 ) & F_5 ( 0 ) ) << V_56 ;
break;
case V_114 :
V_5 &= ~ ( V_116
<< V_115 ) ;
V_5 |= ( V_109 & V_116 )
<< V_115 ;
break;
default:
F_26 ( & V_7 -> V_83 -> V_84 ,
L_35 , V_111 ) ;
V_15 = - V_25 ;
}
F_6 ( V_5 , V_7 -> V_9 + V_108 * 4 ) ;
}
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_15 ;
}
static int F_38 ( struct V_99 * V_100 ,
unsigned int V_102 ,
unsigned long * V_23 )
{
const unsigned * V_105 ;
unsigned V_107 ;
int V_15 ;
V_15 = F_34 ( V_100 , V_102 , & V_105 , & V_107 ) ;
if ( V_15 )
return V_15 ;
if ( F_35 ( V_100 , V_105 [ 0 ] , V_23 ) )
return - V_25 ;
return 0 ;
}
static int F_39 ( struct V_99 * V_100 ,
unsigned V_102 , unsigned long * V_117 ,
unsigned V_118 )
{
const unsigned * V_105 ;
unsigned V_107 ;
int V_29 , V_15 ;
V_15 = F_34 ( V_100 , V_102 , & V_105 , & V_107 ) ;
if ( V_15 )
return V_15 ;
for ( V_29 = 0 ; V_29 < V_107 ; V_29 ++ ) {
if ( F_37 ( V_100 , V_105 [ V_29 ] , V_117 , V_118 ) )
return - V_25 ;
}
return 0 ;
}
static bool F_40 ( struct V_6 * V_7 , unsigned int V_108 )
{
const struct V_119 * V_120 = F_41 ( V_7 -> V_121 , V_108 ) ;
if ( ! V_120 )
return false ;
if ( V_120 -> V_122 || V_120 -> V_123 ||
F_42 ( & V_7 -> V_2 , V_108 ) )
return true ;
return false ;
}
int F_43 ( struct V_124 * V_84 )
{
struct V_125 * V_83 = F_44 ( V_84 ) ;
struct V_6 * V_7 = F_45 ( V_83 ) ;
struct V_126 * V_127 = V_7 -> V_121 -> V_127 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_127 -> V_107 ; V_29 ++ ) {
int V_108 = V_127 -> V_105 [ V_29 ] . V_128 ;
if ( ! F_40 ( V_7 , V_108 ) )
continue;
V_7 -> V_129 [ V_29 ] = F_4 ( V_7 -> V_9 + V_108 * 4 ) ;
}
return 0 ;
}
int F_46 ( struct V_124 * V_84 )
{
struct V_125 * V_83 = F_44 ( V_84 ) ;
struct V_6 * V_7 = F_45 ( V_83 ) ;
struct V_126 * V_127 = V_7 -> V_121 -> V_127 ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_127 -> V_107 ; V_29 ++ ) {
int V_108 = V_127 -> V_105 [ V_29 ] . V_128 ;
if ( ! F_40 ( V_7 , V_108 ) )
continue;
F_6 ( V_7 -> V_129 [ V_29 ] , V_7 -> V_9 + V_108 * 4 ) ;
}
return 0 ;
}
static int F_47 ( struct V_125 * V_83 )
{
int V_15 = 0 ;
int V_130 ;
struct V_131 * V_132 ;
struct V_6 * V_7 ;
V_7 = F_48 ( & V_83 -> V_84 ,
sizeof( struct V_6 ) , V_133 ) ;
if ( ! V_7 )
return - V_134 ;
F_49 ( & V_7 -> V_8 ) ;
V_132 = F_50 ( V_83 , V_135 , 0 ) ;
if ( ! V_132 ) {
F_26 ( & V_83 -> V_84 , L_36 ) ;
return - V_22 ;
}
V_7 -> V_9 = F_51 ( & V_83 -> V_84 , V_132 -> V_136 ,
F_52 ( V_132 ) ) ;
if ( ! V_7 -> V_9 )
return - V_134 ;
V_130 = F_53 ( V_83 , 0 ) ;
if ( V_130 < 0 ) {
F_26 ( & V_83 -> V_84 , L_37 , V_130 ) ;
return V_130 ;
}
#ifdef F_54
V_7 -> V_129 = F_55 ( & V_83 -> V_84 , V_137 . V_107 ,
sizeof( * V_7 -> V_129 ) ,
V_133 ) ;
if ( ! V_7 -> V_129 )
return - V_134 ;
#endif
V_7 -> V_83 = V_83 ;
V_7 -> V_2 . V_138 = F_1 ;
V_7 -> V_2 . V_139 = F_8 ;
V_7 -> V_2 . V_140 = F_9 ;
V_7 -> V_2 . V_141 = F_10 ;
V_7 -> V_2 . V_142 = F_12 ;
V_7 -> V_2 . V_143 = F_15 ;
V_7 -> V_2 . V_9 = - 1 ;
V_7 -> V_2 . V_144 = V_83 -> V_104 ;
V_7 -> V_2 . V_145 = V_146 ;
V_7 -> V_2 . V_147 = & V_83 -> V_84 ;
V_7 -> V_2 . V_148 = F_52 ( V_132 ) / 4 ;
#if F_56 ( V_149 )
V_7 -> V_2 . V_150 = V_83 -> V_84 . V_150 ;
#endif
V_7 -> V_44 = V_7 -> V_2 . V_148 / 64 ;
V_7 -> V_103 = V_151 ;
V_7 -> V_101 = F_57 ( V_151 ) ;
V_137 . V_104 = F_58 ( & V_83 -> V_84 ) ;
V_7 -> V_121 = F_59 ( & V_83 -> V_84 , & V_137 ,
V_7 ) ;
if ( F_60 ( V_7 -> V_121 ) ) {
F_26 ( & V_83 -> V_84 , L_38 ) ;
return F_61 ( V_7 -> V_121 ) ;
}
V_15 = F_62 ( & V_7 -> V_2 , V_7 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_63 ( & V_7 -> V_2 , F_58 ( & V_83 -> V_84 ) ,
0 , 0 , V_7 -> V_2 . V_148 ) ;
if ( V_15 ) {
F_26 ( & V_83 -> V_84 , L_39 ) ;
goto V_152;
}
V_15 = F_64 ( & V_7 -> V_2 ,
& V_153 ,
0 ,
V_154 ,
V_67 ) ;
if ( V_15 ) {
F_26 ( & V_83 -> V_84 , L_40 ) ;
V_15 = - V_155 ;
goto V_152;
}
V_15 = F_65 ( & V_83 -> V_84 , V_130 , F_28 , 0 ,
V_156 , V_7 ) ;
if ( V_15 )
goto V_152;
F_66 ( V_83 , V_7 ) ;
F_67 ( & V_83 -> V_84 , L_41 ) ;
return V_15 ;
V_152:
F_68 ( & V_7 -> V_2 ) ;
return V_15 ;
}
static int F_69 ( struct V_125 * V_83 )
{
struct V_6 * V_7 ;
V_7 = F_45 ( V_83 ) ;
F_68 ( & V_7 -> V_2 ) ;
return 0 ;
}
