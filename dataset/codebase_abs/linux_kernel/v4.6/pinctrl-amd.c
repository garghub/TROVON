static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
unsigned long V_4 ;
T_1 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
if ( ( V_5 & V_10 ) == 0 ) {
V_5 |= 0xf ;
V_5 |= F_5 ( V_11 ) ;
V_5 |= V_12 << V_13 ;
V_5 &= ~ F_5 ( V_14 ) ;
}
V_5 &= ~ F_5 ( V_15 ) ;
F_6 ( V_5 , V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 ,
int V_16 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
V_5 |= F_5 ( V_15 ) ;
if ( V_16 )
V_5 |= F_5 ( V_17 ) ;
else
V_5 &= ~ F_5 ( V_17 ) ;
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
return ! ! ( V_5 & F_5 ( V_18 ) ) ;
}
static void F_10 ( struct V_1 * V_2 , unsigned V_3 , int V_16 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
if ( V_16 )
V_5 |= F_5 ( V_17 ) ;
else
V_5 &= ~ F_5 ( V_17 ) ;
F_6 ( V_5 , V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_11 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned V_19 )
{
T_1 time ;
T_1 V_5 ;
int V_20 = 0 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_3 * 4 ) ;
if ( V_19 ) {
V_5 |= V_12 << V_13 ;
V_5 &= ~ V_10 ;
if ( V_19 < 61 ) {
V_5 |= 1 ;
V_5 &= ~ F_5 ( V_11 ) ;
V_5 &= ~ F_5 ( V_14 ) ;
} else if ( V_19 < 976 ) {
time = V_19 / 61 ;
V_5 |= time & V_10 ;
V_5 &= ~ F_5 ( V_11 ) ;
V_5 &= ~ F_5 ( V_14 ) ;
} else if ( V_19 < 3900 ) {
time = V_19 / 244 ;
V_5 |= time & V_10 ;
V_5 |= F_5 ( V_11 ) ;
V_5 &= ~ F_5 ( V_14 ) ;
} else if ( V_19 < 250000 ) {
time = V_19 / 15600 ;
V_5 |= time & V_10 ;
V_5 &= ~ F_5 ( V_11 ) ;
V_5 |= F_5 ( V_14 ) ;
} else if ( V_19 < 1000000 ) {
time = V_19 / 62500 ;
V_5 |= time & V_10 ;
V_5 |= F_5 ( V_11 ) ;
V_5 |= F_5 ( V_14 ) ;
} else {
V_5 &= ~ V_21 ;
V_20 = - V_22 ;
}
} else {
V_5 &= ~ F_5 ( V_11 ) ;
V_5 &= ~ F_5 ( V_14 ) ;
V_5 &= ~ V_10 ;
V_5 &= ~ V_21 ;
}
F_6 ( V_5 , V_7 -> V_9 + V_3 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_20 ;
}
static void F_12 ( struct V_23 * V_24 , struct V_1 * V_2 )
{
T_1 V_5 ;
unsigned long V_4 ;
unsigned int V_25 , V_26 , V_27 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
char * V_28 ;
char * V_29 ;
char * V_30 ;
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
for ( V_25 = 0 ; V_25 < V_41 ; V_25 ++ ) {
F_13 ( V_24 , L_1 , V_25 ) ;
switch ( V_25 ) {
case 0 :
V_26 = 0 ;
V_27 = V_42 ;
break;
case 1 :
V_26 = 64 ;
V_27 = V_43 + V_26 ;
break;
case 2 :
V_26 = 128 ;
V_27 = V_44 + V_26 ;
break;
}
for (; V_26 < V_27 ; V_26 ++ ) {
F_13 ( V_24 , L_2 , V_26 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_26 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
if ( V_5 & F_5 ( V_45 ) ) {
V_30 = L_3 ;
if ( ! ( V_5 & F_5 ( V_46 ) )
&& ! ( V_5 & F_5 ( V_46 + 1 ) ) )
V_29 = L_4 ;
else if ( V_5 & F_5 ( V_46 )
&& ! ( V_5 & F_5 ( V_46 + 1 ) ) )
V_29 = L_5 ;
else if ( ! ( V_5 & F_5 ( V_46 ) )
&& V_5 & F_5 ( V_46 + 1 ) )
V_29 = L_6 ;
else
V_29 = L_7 ;
if ( V_5 & F_5 ( V_47 ) )
V_28 = L_8 ;
else
V_28 = L_9 ;
} else {
V_30 =
L_10 ;
V_29 = L_11 ;
V_28 = L_11 ;
}
if ( V_5 & F_5 ( V_48 ) )
V_31 =
L_12 ;
else
V_31 =
L_13 ;
if ( V_5 & F_5 ( V_49 ) )
V_32 = L_14 ;
else
V_32 = L_15 ;
if ( V_5 & F_5 ( V_49 ) )
V_33 = L_16 ;
else
V_33 = L_17 ;
if ( V_5 & F_5 ( V_49 ) )
V_34 = L_18 ;
else
V_34 = L_19 ;
if ( V_5 & F_5 ( V_50 ) ) {
V_37 = L_20 ;
if ( V_5 & F_5 ( V_51 ) )
V_36 = L_21 ;
else
V_36 = L_22 ;
} else {
V_37 = L_23 ;
V_36 = L_11 ;
}
if ( V_5 & F_5 ( V_52 ) )
V_38 = L_24 ;
else
V_38 = L_25 ;
if ( V_5 & F_5 ( V_15 ) ) {
V_35 = L_11 ;
V_40 = L_26 ;
if ( V_5 & F_5 ( V_17 ) )
V_39 = L_27 ;
else
V_39 = L_28 ;
} else {
V_40 = L_29 ;
V_39 = L_11 ;
if ( V_5 & F_5 ( V_18 ) )
V_35 = L_30 ;
else
V_35 = L_31 ;
}
F_13 ( V_24 , L_32
L_33 ,
V_28 , V_29 , V_30 ,
V_31 , V_32 , V_33 ,
V_34 , V_35 , V_36 ,
V_37 , V_38 ,
V_39 , V_40 , V_5 ) ;
}
}
}
static void F_14 ( struct V_53 * V_54 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
if ( ( V_5 & V_10 ) == 0 ) {
V_5 |= 0xf ;
V_5 |= F_5 ( V_11 ) ;
V_5 &= ~ F_5 ( V_14 ) ;
}
V_5 |= F_5 ( V_45 ) ;
V_5 |= F_5 ( V_48 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_16 ( struct V_53 * V_54 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
V_5 &= ~ F_5 ( V_45 ) ;
V_5 &= ~ F_5 ( V_48 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_17 ( struct V_53 * V_54 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
V_5 &= ~ F_5 ( V_48 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_18 ( struct V_53 * V_54 )
{
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
V_5 |= F_5 ( V_48 ) ;
F_6 ( V_5 , V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static void F_19 ( struct V_53 * V_54 )
{
T_1 V_56 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_56 = F_4 ( V_7 -> V_9 + V_57 ) ;
V_56 |= V_58 ;
F_6 ( V_56 , V_7 -> V_9 + V_57 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
}
static int F_20 ( struct V_53 * V_54 , unsigned int type )
{
int V_20 = 0 ;
T_1 V_5 ;
unsigned long V_4 ;
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
switch ( type & V_59 ) {
case V_60 :
V_5 &= ~ F_5 ( V_47 ) ;
V_5 &= ~ ( V_61 << V_46 ) ;
V_5 |= V_62 << V_46 ;
V_5 |= V_12 << V_13 ;
F_21 ( V_54 , V_63 ) ;
break;
case V_64 :
V_5 &= ~ F_5 ( V_47 ) ;
V_5 &= ~ ( V_61 << V_46 ) ;
V_5 |= V_65 << V_46 ;
V_5 |= V_12 << V_13 ;
F_21 ( V_54 , V_63 ) ;
break;
case V_66 :
V_5 &= ~ F_5 ( V_47 ) ;
V_5 &= ~ ( V_61 << V_46 ) ;
V_5 |= V_67 << V_46 ;
V_5 |= V_12 << V_13 ;
F_21 ( V_54 , V_63 ) ;
break;
case V_68 :
V_5 |= V_69 << V_47 ;
V_5 &= ~ ( V_61 << V_46 ) ;
V_5 |= V_62 << V_46 ;
V_5 &= ~ ( V_21 << V_13 ) ;
V_5 |= V_70 << V_13 ;
F_21 ( V_54 , V_71 ) ;
break;
case V_72 :
V_5 |= V_69 << V_47 ;
V_5 &= ~ ( V_61 << V_46 ) ;
V_5 |= V_65 << V_46 ;
V_5 &= ~ ( V_21 << V_13 ) ;
V_5 |= V_73 << V_13 ;
F_21 ( V_54 , V_71 ) ;
break;
case V_74 :
break;
default:
F_22 ( & V_7 -> V_75 -> V_76 , L_34 ) ;
V_20 = - V_22 ;
}
V_5 |= V_77 << V_78 ;
F_6 ( V_5 , V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_20 ;
}
static void F_23 ( struct V_53 * V_54 )
{
}
static void F_24 ( struct V_79 * V_80 )
{
T_1 V_26 ;
T_1 V_81 ;
T_1 V_56 ;
T_1 V_5 ;
T_2 V_82 ;
int V_83 = 0 ;
unsigned int V_84 ;
unsigned long V_4 ;
struct V_85 * V_86 = F_25 ( V_80 ) ;
struct V_1 * V_2 = F_26 ( V_80 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_27 ( V_86 , V_80 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_56 = F_4 ( V_7 -> V_9 + V_87 ) ;
V_82 = V_56 ;
V_82 = V_82 << 32 ;
V_56 = F_4 ( V_7 -> V_9 + V_88 ) ;
V_82 |= V_56 ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
for ( V_81 = 0 ; V_81 < 46 ; V_81 ++ ) {
if ( V_82 & F_5 ( V_81 ) ) {
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_5 = F_4 ( V_7 -> V_9 +
( V_81 * 4 + V_26 ) * 4 ) ;
if ( ( V_5 & F_5 ( V_78 ) ) ||
( V_5 & F_5 ( V_89 ) ) ) {
V_84 = F_28 ( V_2 -> V_90 ,
V_81 * 4 + V_26 ) ;
F_29 ( V_84 ) ;
F_6 ( V_5 ,
V_7 -> V_9
+ ( V_81 * 4 + V_26 ) * 4 ) ;
V_83 ++ ;
}
}
}
}
if ( V_83 == 0 )
F_30 ( V_80 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_56 = F_4 ( V_7 -> V_9 + V_57 ) ;
V_56 |= V_58 ;
F_6 ( V_56 , V_7 -> V_9 + V_57 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
F_31 ( V_86 , V_80 ) ;
}
static int F_32 ( struct V_91 * V_92 )
{
struct V_6 * V_7 = F_33 ( V_92 ) ;
return V_7 -> V_93 ;
}
static const char * F_34 ( struct V_91 * V_92 ,
unsigned V_94 )
{
struct V_6 * V_7 = F_33 ( V_92 ) ;
return V_7 -> V_95 [ V_94 ] . V_96 ;
}
static int F_35 ( struct V_91 * V_92 ,
unsigned V_94 ,
const unsigned * * V_97 ,
unsigned * V_98 )
{
struct V_6 * V_7 = F_33 ( V_92 ) ;
* V_97 = V_7 -> V_95 [ V_94 ] . V_97 ;
* V_98 = V_7 -> V_95 [ V_94 ] . V_99 ;
return 0 ;
}
static int F_36 ( struct V_91 * V_92 ,
unsigned int V_100 ,
unsigned long * V_101 )
{
T_1 V_5 ;
unsigned V_102 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_33 ( V_92 ) ;
enum V_103 V_104 = F_37 ( * V_101 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_100 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
switch ( V_104 ) {
case V_105 :
V_102 = V_5 & V_10 ;
break;
case V_106 :
V_102 = ( V_5 >> V_52 ) & F_5 ( 0 ) ;
break;
case V_107 :
V_102 = ( V_5 >> V_51 ) & ( F_5 ( 0 ) | F_5 ( 1 ) ) ;
break;
case V_108 :
V_102 = ( V_5 >> V_109 ) & V_110 ;
break;
default:
F_22 ( & V_7 -> V_75 -> V_76 , L_35 ,
V_104 ) ;
return - V_111 ;
}
* V_101 = F_38 ( V_104 , V_102 ) ;
return 0 ;
}
static int F_39 ( struct V_91 * V_92 , unsigned int V_100 ,
unsigned long * V_112 , unsigned V_113 )
{
int V_26 ;
T_1 V_102 ;
int V_20 = 0 ;
T_1 V_5 ;
unsigned long V_4 ;
enum V_103 V_104 ;
struct V_6 * V_7 = F_33 ( V_92 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
for ( V_26 = 0 ; V_26 < V_113 ; V_26 ++ ) {
V_104 = F_37 ( V_112 [ V_26 ] ) ;
V_102 = F_40 ( V_112 [ V_26 ] ) ;
V_5 = F_4 ( V_7 -> V_9 + V_100 * 4 ) ;
switch ( V_104 ) {
case V_105 :
V_5 &= ~ V_10 ;
V_5 |= V_102 & V_10 ;
break;
case V_106 :
V_5 &= ~ F_5 ( V_52 ) ;
V_5 |= ( V_102 & F_5 ( 0 ) ) << V_52 ;
break;
case V_107 :
V_5 &= ~ F_5 ( V_51 ) ;
V_5 |= ( V_102 & F_5 ( 0 ) ) << V_51 ;
V_5 &= ~ F_5 ( V_50 ) ;
V_5 |= ( ( V_102 >> 1 ) & F_5 ( 0 ) ) << V_50 ;
break;
case V_108 :
V_5 &= ~ ( V_110
<< V_109 ) ;
V_5 |= ( V_102 & V_110 )
<< V_109 ;
break;
default:
F_22 ( & V_7 -> V_75 -> V_76 ,
L_35 , V_104 ) ;
V_20 = - V_111 ;
}
F_6 ( V_5 , V_7 -> V_9 + V_100 * 4 ) ;
}
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_20 ;
}
static int F_41 ( struct V_91 * V_92 ,
unsigned int V_94 ,
unsigned long * V_101 )
{
const unsigned * V_97 ;
unsigned V_99 ;
int V_20 ;
V_20 = F_35 ( V_92 , V_94 , & V_97 , & V_99 ) ;
if ( V_20 )
return V_20 ;
if ( F_36 ( V_92 , V_97 [ 0 ] , V_101 ) )
return - V_111 ;
return 0 ;
}
static int F_42 ( struct V_91 * V_92 ,
unsigned V_94 , unsigned long * V_112 ,
unsigned V_113 )
{
const unsigned * V_97 ;
unsigned V_99 ;
int V_26 , V_20 ;
V_20 = F_35 ( V_92 , V_94 , & V_97 , & V_99 ) ;
if ( V_20 )
return V_20 ;
for ( V_26 = 0 ; V_26 < V_99 ; V_26 ++ ) {
if ( F_39 ( V_92 , V_97 [ V_26 ] , V_112 , V_113 ) )
return - V_111 ;
}
return 0 ;
}
static int F_43 ( struct V_114 * V_75 )
{
int V_20 = 0 ;
int V_115 ;
struct V_116 * V_117 ;
struct V_6 * V_7 ;
V_7 = F_44 ( & V_75 -> V_76 ,
sizeof( struct V_6 ) , V_118 ) ;
if ( ! V_7 )
return - V_119 ;
F_45 ( & V_7 -> V_8 ) ;
V_117 = F_46 ( V_75 , V_120 , 0 ) ;
if ( ! V_117 ) {
F_22 ( & V_75 -> V_76 , L_36 ) ;
return - V_22 ;
}
V_7 -> V_9 = F_47 ( & V_75 -> V_76 , V_117 -> V_121 ,
F_48 ( V_117 ) ) ;
if ( ! V_7 -> V_9 )
return - V_119 ;
V_115 = F_49 ( V_75 , 0 ) ;
if ( V_115 < 0 ) {
F_22 ( & V_75 -> V_76 , L_37 ) ;
return - V_22 ;
}
V_7 -> V_75 = V_75 ;
V_7 -> V_2 . V_122 = F_1 ;
V_7 -> V_2 . V_123 = F_8 ;
V_7 -> V_2 . V_124 = F_9 ;
V_7 -> V_2 . V_125 = F_10 ;
V_7 -> V_2 . V_126 = F_11 ;
V_7 -> V_2 . V_127 = F_12 ;
V_7 -> V_2 . V_9 = 0 ;
V_7 -> V_2 . V_128 = V_75 -> V_96 ;
V_7 -> V_2 . V_129 = V_130 ;
V_7 -> V_2 . V_131 = & V_75 -> V_76 ;
V_7 -> V_2 . V_132 = V_133 ;
#if F_50 ( V_134 )
V_7 -> V_2 . V_135 = V_75 -> V_76 . V_135 ;
#endif
V_7 -> V_95 = V_136 ;
V_7 -> V_93 = F_51 ( V_136 ) ;
V_137 . V_96 = F_52 ( & V_75 -> V_76 ) ;
V_7 -> V_138 = F_53 ( & V_137 ,
& V_75 -> V_76 , V_7 ) ;
if ( F_54 ( V_7 -> V_138 ) ) {
F_22 ( & V_75 -> V_76 , L_38 ) ;
return F_55 ( V_7 -> V_138 ) ;
}
V_20 = F_56 ( & V_7 -> V_2 , V_7 ) ;
if ( V_20 )
goto V_139;
V_20 = F_57 ( & V_7 -> V_2 , F_52 ( & V_75 -> V_76 ) ,
0 , 0 , V_133 ) ;
if ( V_20 ) {
F_22 ( & V_75 -> V_76 , L_39 ) ;
goto V_140;
}
V_20 = F_58 ( & V_7 -> V_2 ,
& V_141 ,
0 ,
V_142 ,
V_74 ) ;
if ( V_20 ) {
F_22 ( & V_75 -> V_76 , L_40 ) ;
V_20 = - V_143 ;
goto V_140;
}
F_59 ( & V_7 -> V_2 ,
& V_141 ,
V_115 ,
F_24 ) ;
F_60 ( V_75 , V_7 ) ;
F_61 ( & V_75 -> V_76 , L_41 ) ;
return V_20 ;
V_140:
F_62 ( & V_7 -> V_2 ) ;
V_139:
F_63 ( V_7 -> V_138 ) ;
return V_20 ;
}
static int F_64 ( struct V_114 * V_75 )
{
struct V_6 * V_7 ;
V_7 = F_65 ( V_75 ) ;
F_62 ( & V_7 -> V_2 ) ;
F_63 ( V_7 -> V_138 ) ;
return 0 ;
}
