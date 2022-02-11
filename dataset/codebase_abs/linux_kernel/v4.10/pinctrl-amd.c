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
default:
return;
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
if ( V_5 & F_5 ( V_10 ) ) {
V_35 = L_11 ;
V_40 = L_26 ;
if ( V_5 & F_5 ( V_12 ) )
V_39 = L_27 ;
else
V_39 = L_28 ;
} else {
V_40 = L_29 ;
V_39 = L_11 ;
if ( V_5 & F_5 ( V_13 ) )
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
int V_15 = 0 ;
T_1 V_5 ;
unsigned long V_4 , V_59 ;
struct V_1 * V_2 = F_15 ( V_54 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
V_59 = F_21 ( V_54 -> V_60 ) ;
if ( V_59 != V_61 )
type = V_59 ;
switch ( type & V_62 ) {
case V_63 :
V_5 &= ~ F_5 ( V_47 ) ;
V_5 &= ~ ( V_64 << V_46 ) ;
V_5 |= V_65 << V_46 ;
V_5 |= V_16 << V_17 ;
F_22 ( V_54 , V_66 ) ;
break;
case V_67 :
V_5 &= ~ F_5 ( V_47 ) ;
V_5 &= ~ ( V_64 << V_46 ) ;
V_5 |= V_68 << V_46 ;
V_5 |= V_16 << V_17 ;
F_22 ( V_54 , V_66 ) ;
break;
case V_69 :
V_5 &= ~ F_5 ( V_47 ) ;
V_5 &= ~ ( V_64 << V_46 ) ;
V_5 |= V_70 << V_46 ;
V_5 |= V_16 << V_17 ;
F_22 ( V_54 , V_66 ) ;
break;
case V_71 :
V_5 |= V_72 << V_47 ;
V_5 &= ~ ( V_64 << V_46 ) ;
V_5 |= V_65 << V_46 ;
V_5 &= ~ ( V_21 << V_17 ) ;
V_5 |= V_73 << V_17 ;
F_22 ( V_54 , V_74 ) ;
break;
case V_75 :
V_5 |= V_72 << V_47 ;
V_5 &= ~ ( V_64 << V_46 ) ;
V_5 |= V_68 << V_46 ;
V_5 &= ~ ( V_21 << V_17 ) ;
V_5 |= V_76 << V_17 ;
F_22 ( V_54 , V_74 ) ;
break;
case V_61 :
break;
default:
F_23 ( & V_7 -> V_77 -> V_78 , L_34 ) ;
V_15 = - V_22 ;
}
V_5 |= V_79 << V_80 ;
F_6 ( V_5 , V_7 -> V_9 + ( V_54 -> V_55 ) * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_15 ;
}
static void F_24 ( struct V_53 * V_54 )
{
}
static void F_25 ( struct V_81 * V_82 )
{
T_1 V_26 ;
T_1 V_83 ;
T_1 V_56 ;
T_1 V_5 ;
T_2 V_84 ;
int V_85 = 0 ;
unsigned int V_60 ;
unsigned long V_4 ;
struct V_86 * V_87 = F_26 ( V_82 ) ;
struct V_1 * V_2 = F_27 ( V_82 ) ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
F_28 ( V_87 , V_82 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_56 = F_4 ( V_7 -> V_9 + V_88 ) ;
V_84 = V_56 ;
V_84 = V_84 << 32 ;
V_56 = F_4 ( V_7 -> V_9 + V_89 ) ;
V_84 |= V_56 ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
for ( V_83 = 0 ; V_83 < 46 ; V_83 ++ ) {
if ( V_84 & F_5 ( V_83 ) ) {
for ( V_26 = 0 ; V_26 < 4 ; V_26 ++ ) {
V_5 = F_4 ( V_7 -> V_9 +
( V_83 * 4 + V_26 ) * 4 ) ;
if ( ( V_5 & F_5 ( V_80 ) ) ||
( V_5 & F_5 ( V_90 ) ) ) {
V_60 = F_29 ( V_2 -> V_91 ,
V_83 * 4 + V_26 ) ;
F_30 ( V_60 ) ;
F_6 ( V_5 ,
V_7 -> V_9
+ ( V_83 * 4 + V_26 ) * 4 ) ;
V_85 ++ ;
}
}
}
}
if ( V_85 == 0 )
F_31 ( V_82 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_56 = F_4 ( V_7 -> V_9 + V_57 ) ;
V_56 |= V_58 ;
F_6 ( V_56 , V_7 -> V_9 + V_57 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
F_32 ( V_87 , V_82 ) ;
}
static int F_33 ( struct V_92 * V_93 )
{
struct V_6 * V_7 = F_34 ( V_93 ) ;
return V_7 -> V_94 ;
}
static const char * F_35 ( struct V_92 * V_93 ,
unsigned V_95 )
{
struct V_6 * V_7 = F_34 ( V_93 ) ;
return V_7 -> V_96 [ V_95 ] . V_97 ;
}
static int F_36 ( struct V_92 * V_93 ,
unsigned V_95 ,
const unsigned * * V_98 ,
unsigned * V_99 )
{
struct V_6 * V_7 = F_34 ( V_93 ) ;
* V_98 = V_7 -> V_96 [ V_95 ] . V_98 ;
* V_99 = V_7 -> V_96 [ V_95 ] . V_100 ;
return 0 ;
}
static int F_37 ( struct V_92 * V_93 ,
unsigned int V_101 ,
unsigned long * V_102 )
{
T_1 V_5 ;
unsigned V_103 ;
unsigned long V_4 ;
struct V_6 * V_7 = F_34 ( V_93 ) ;
enum V_104 V_105 = F_38 ( * V_102 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
V_5 = F_4 ( V_7 -> V_9 + V_101 * 4 ) ;
F_7 ( & V_7 -> V_8 , V_4 ) ;
switch ( V_105 ) {
case V_106 :
V_103 = V_5 & V_18 ;
break;
case V_107 :
V_103 = ( V_5 >> V_52 ) & F_5 ( 0 ) ;
break;
case V_108 :
V_103 = ( V_5 >> V_51 ) & ( F_5 ( 0 ) | F_5 ( 1 ) ) ;
break;
case V_109 :
V_103 = ( V_5 >> V_110 ) & V_111 ;
break;
default:
F_23 ( & V_7 -> V_77 -> V_78 , L_35 ,
V_105 ) ;
return - V_112 ;
}
* V_102 = F_39 ( V_105 , V_103 ) ;
return 0 ;
}
static int F_40 ( struct V_92 * V_93 , unsigned int V_101 ,
unsigned long * V_113 , unsigned V_114 )
{
int V_26 ;
T_1 V_103 ;
int V_15 = 0 ;
T_1 V_5 ;
unsigned long V_4 ;
enum V_104 V_105 ;
struct V_6 * V_7 = F_34 ( V_93 ) ;
F_3 ( & V_7 -> V_8 , V_4 ) ;
for ( V_26 = 0 ; V_26 < V_114 ; V_26 ++ ) {
V_105 = F_38 ( V_113 [ V_26 ] ) ;
V_103 = F_41 ( V_113 [ V_26 ] ) ;
V_5 = F_4 ( V_7 -> V_9 + V_101 * 4 ) ;
switch ( V_105 ) {
case V_106 :
V_5 &= ~ V_18 ;
V_5 |= V_103 & V_18 ;
break;
case V_107 :
V_5 &= ~ F_5 ( V_52 ) ;
V_5 |= ( V_103 & F_5 ( 0 ) ) << V_52 ;
break;
case V_108 :
V_5 &= ~ F_5 ( V_51 ) ;
V_5 |= ( V_103 & F_5 ( 0 ) ) << V_51 ;
V_5 &= ~ F_5 ( V_50 ) ;
V_5 |= ( ( V_103 >> 1 ) & F_5 ( 0 ) ) << V_50 ;
break;
case V_109 :
V_5 &= ~ ( V_111
<< V_110 ) ;
V_5 |= ( V_103 & V_111 )
<< V_110 ;
break;
default:
F_23 ( & V_7 -> V_77 -> V_78 ,
L_35 , V_105 ) ;
V_15 = - V_112 ;
}
F_6 ( V_5 , V_7 -> V_9 + V_101 * 4 ) ;
}
F_7 ( & V_7 -> V_8 , V_4 ) ;
return V_15 ;
}
static int F_42 ( struct V_92 * V_93 ,
unsigned int V_95 ,
unsigned long * V_102 )
{
const unsigned * V_98 ;
unsigned V_100 ;
int V_15 ;
V_15 = F_36 ( V_93 , V_95 , & V_98 , & V_100 ) ;
if ( V_15 )
return V_15 ;
if ( F_37 ( V_93 , V_98 [ 0 ] , V_102 ) )
return - V_112 ;
return 0 ;
}
static int F_43 ( struct V_92 * V_93 ,
unsigned V_95 , unsigned long * V_113 ,
unsigned V_114 )
{
const unsigned * V_98 ;
unsigned V_100 ;
int V_26 , V_15 ;
V_15 = F_36 ( V_93 , V_95 , & V_98 , & V_100 ) ;
if ( V_15 )
return V_15 ;
for ( V_26 = 0 ; V_26 < V_100 ; V_26 ++ ) {
if ( F_40 ( V_93 , V_98 [ V_26 ] , V_113 , V_114 ) )
return - V_112 ;
}
return 0 ;
}
static int F_44 ( struct V_115 * V_77 )
{
int V_15 = 0 ;
int V_116 ;
struct V_117 * V_118 ;
struct V_6 * V_7 ;
V_7 = F_45 ( & V_77 -> V_78 ,
sizeof( struct V_6 ) , V_119 ) ;
if ( ! V_7 )
return - V_120 ;
F_46 ( & V_7 -> V_8 ) ;
V_118 = F_47 ( V_77 , V_121 , 0 ) ;
if ( ! V_118 ) {
F_23 ( & V_77 -> V_78 , L_36 ) ;
return - V_22 ;
}
V_7 -> V_9 = F_48 ( & V_77 -> V_78 , V_118 -> V_122 ,
F_49 ( V_118 ) ) ;
if ( ! V_7 -> V_9 )
return - V_120 ;
V_116 = F_50 ( V_77 , 0 ) ;
if ( V_116 < 0 ) {
F_23 ( & V_77 -> V_78 , L_37 ) ;
return - V_22 ;
}
V_7 -> V_77 = V_77 ;
V_7 -> V_2 . V_123 = F_1 ;
V_7 -> V_2 . V_124 = F_8 ;
V_7 -> V_2 . V_125 = F_9 ;
V_7 -> V_2 . V_126 = F_10 ;
V_7 -> V_2 . V_127 = F_11 ;
V_7 -> V_2 . V_128 = F_12 ;
V_7 -> V_2 . V_9 = 0 ;
V_7 -> V_2 . V_129 = V_77 -> V_97 ;
V_7 -> V_2 . V_130 = V_131 ;
V_7 -> V_2 . V_132 = & V_77 -> V_78 ;
V_7 -> V_2 . V_133 = V_134 ;
#if F_51 ( V_135 )
V_7 -> V_2 . V_136 = V_77 -> V_78 . V_136 ;
#endif
V_7 -> V_96 = V_137 ;
V_7 -> V_94 = F_52 ( V_137 ) ;
V_138 . V_97 = F_53 ( & V_77 -> V_78 ) ;
V_7 -> V_139 = F_54 ( & V_77 -> V_78 , & V_138 ,
V_7 ) ;
if ( F_55 ( V_7 -> V_139 ) ) {
F_23 ( & V_77 -> V_78 , L_38 ) ;
return F_56 ( V_7 -> V_139 ) ;
}
V_15 = F_57 ( & V_7 -> V_2 , V_7 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_58 ( & V_7 -> V_2 , F_53 ( & V_77 -> V_78 ) ,
0 , 0 , V_134 ) ;
if ( V_15 ) {
F_23 ( & V_77 -> V_78 , L_39 ) ;
goto V_140;
}
V_15 = F_59 ( & V_7 -> V_2 ,
& V_141 ,
0 ,
V_142 ,
V_61 ) ;
if ( V_15 ) {
F_23 ( & V_77 -> V_78 , L_40 ) ;
V_15 = - V_143 ;
goto V_140;
}
F_60 ( & V_7 -> V_2 ,
& V_141 ,
V_116 ,
F_25 ) ;
F_61 ( V_77 , V_7 ) ;
F_62 ( & V_77 -> V_78 , L_41 ) ;
return V_15 ;
V_140:
F_63 ( & V_7 -> V_2 ) ;
return V_15 ;
}
static int F_64 ( struct V_115 * V_77 )
{
struct V_6 * V_7 ;
V_7 = F_65 ( V_77 ) ;
F_63 ( & V_7 -> V_2 ) ;
return 0 ;
}
