static int F_1 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_5 , V_2 ) ;
return F_3 ( V_1 -> V_6 [ V_7 ] , V_4 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_8 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_5 , V_2 ) ;
return F_5 ( V_1 -> V_6 [ V_7 ] , V_4 , V_8 ) ;
}
static int F_6 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int * V_3 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_9 , V_2 ) ;
return F_3 ( V_1 -> V_6 [ V_7 ] , V_4 , V_3 ) ;
}
static int F_7 ( struct V_1 * V_1 , unsigned int V_2 ,
unsigned int V_8 )
{
unsigned int V_4 ;
V_4 = F_2 ( V_9 , V_2 ) ;
return F_5 ( V_1 -> V_6 [ V_7 ] , V_4 , V_8 ) ;
}
static int F_8 ( struct V_10 * V_11 , unsigned int V_12 )
{
int V_13 = F_9 ( V_11 ) ;
struct V_14 * V_15 = F_10 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_1 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_19 [ V_13 ] ;
unsigned int V_2 ;
bool V_21 = true ;
F_1 ( V_15 -> V_1 , V_20 -> V_22 , & V_2 ) ;
V_2 &= ~ V_23 ;
if ( V_2 == V_24 )
V_21 = false ;
switch ( V_12 ) {
case V_25 :
V_2 |= V_26 ;
break;
case V_27 :
V_2 |= V_28 ;
break;
case V_29 :
V_2 |= V_30 ;
break;
default:
return - V_31 ;
}
V_15 -> V_32 [ V_13 ] = V_2 & V_23 ;
if ( V_21 )
F_4 ( V_15 -> V_1 , V_20 -> V_22 , V_2 ) ;
V_15 -> V_33 [ V_13 ] . V_34 = V_15 -> V_32 [ V_13 ] ;
return 0 ;
}
static unsigned int F_11 ( struct V_10 * V_11 )
{
struct V_14 * V_15 = F_10 ( V_11 ) ;
int V_13 = F_9 ( V_11 ) ;
unsigned int V_2 ;
V_2 = V_15 -> V_32 [ V_13 ] & V_23 ;
switch ( V_2 ) {
case V_26 :
return V_25 ;
case V_28 :
return V_27 ;
case V_30 :
return V_29 ;
}
return 0 ;
}
static int F_12 ( struct V_10 * V_35 ,
int V_36 )
{
int V_13 = F_9 ( V_35 ) ;
struct V_14 * V_15 = F_10 ( V_35 ) ;
struct V_16 * V_17 = V_15 -> V_1 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_19 [ V_13 ] ;
unsigned int V_2 = 0 ;
int V_37 ;
switch ( V_13 ) {
case V_38 :
case V_39 :
return 0 ;
}
if ( V_36 <= 0 )
V_2 = 0 ;
else if ( V_36 <= 2500 )
V_2 = 3 ;
else if ( V_36 <= 5000 )
V_2 = 2 ;
else
V_2 = 1 ;
V_37 = F_4 ( V_15 -> V_1 , V_20 -> V_40 , V_2 ) ;
if ( V_37 < 0 ) {
F_13 ( V_15 -> V_1 -> V_11 , L_1 , V_37 ) ;
return V_37 ;
}
V_15 -> V_36 [ V_13 ] = V_41 [ V_2 ] ;
return V_37 ;
}
static int F_14 ( struct V_10 * V_11 )
{
int V_13 = F_9 ( V_11 ) ;
struct V_14 * V_15 = F_10 ( V_11 ) ;
struct V_16 * V_17 = V_15 -> V_1 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_19 [ V_13 ] ;
unsigned int V_2 ;
F_6 ( V_15 -> V_1 , V_20 -> V_22 , & V_2 ) ;
V_2 &= V_42 ;
return ! ! ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_1 , int V_13 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = V_1 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_19 [ V_13 ] ;
int V_37 ;
V_37 = F_16 ( V_1 , V_20 -> V_45 ,
V_44 -> V_46 , true ) ;
if ( V_37 < 0 )
F_13 ( V_1 -> V_11 ,
L_2 ,
V_13 , V_37 ) ;
return V_37 ;
}
static int F_17 ( struct V_1 * V_1 , int V_13 ,
struct V_43 * V_44 )
{
unsigned int V_2 ;
int V_37 ;
struct V_16 * V_17 = V_1 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_19 [ V_13 ] ;
unsigned int V_4 = V_20 -> V_22 ;
V_37 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
switch ( V_13 ) {
case V_47 :
case V_48 :
V_2 &= ~ V_49 ;
if ( V_44 -> V_50 )
V_2 |= V_44 -> V_50 <<
V_51 ;
break;
default:
if ( V_44 -> V_52 )
V_2 |= V_53 ;
else
V_2 &= ~ V_53 ;
if ( V_44 -> V_46 )
V_2 |= V_54 ;
else
V_2 &= ~ V_54 ;
V_2 &= ~ V_55 ;
if ( V_44 -> V_50 )
V_2 |= V_44 -> V_50 <<
V_56 ;
}
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_20 -> V_57 && V_44 -> V_58 ) {
V_2 = V_44 -> V_58 ;
V_37 = F_4 ( V_1 , V_20 -> V_57 , V_2 ) ;
if ( V_37 )
return V_37 ;
}
if ( V_44 -> V_46 && ( V_13 != V_47 ) &&
( V_13 != V_48 ) ) {
V_37 = F_1 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( ! ( V_2 & V_23 ) ) {
V_2 |= V_26 ;
V_37 = F_4 ( V_1 , V_4 , V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
}
return F_15 ( V_1 , V_13 , V_44 ) ;
}
return 0 ;
}
static int F_18 ( struct V_1 * V_1 , int V_13 ,
struct V_43 * V_44 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
struct V_16 * V_17 = V_1 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_19 [ V_13 ] ;
V_4 = V_20 -> V_22 ;
V_37 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_44 -> V_52 )
V_2 |= V_59 ;
else
V_2 &= ~ V_59 ;
if ( V_44 -> V_50 )
V_2 |= V_60 ;
else
V_2 &= ~ V_60 ;
V_37 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_44 -> V_46 ) {
V_37 = F_19 ( V_1 , V_9 ,
V_4 , V_61 ,
V_61 ) ;
if ( V_37 < 0 ) {
F_13 ( V_1 -> V_11 ,
L_3 ,
V_4 , V_37 ) ;
return V_37 ;
}
return F_15 ( V_1 , V_13 , V_44 ) ;
}
return 0 ;
}
static int F_20 ( struct V_1 * V_1 , int V_13 ,
struct V_43 * V_44 )
{
unsigned int V_4 ;
int V_37 ;
unsigned int V_62 = 0 ;
struct V_16 * V_17 = V_1 -> V_18 ;
struct V_19 * V_20 = & V_17 -> V_19 [ V_13 ] ;
V_4 = V_20 -> V_22 ;
if ( V_44 -> V_50 )
V_62 = V_63 ;
V_37 = F_19 ( V_1 , V_64 ,
V_4 , V_63 , V_62 ) ;
if ( V_37 < 0 ) {
F_13 ( V_1 -> V_11 , L_4 ,
V_4 , V_37 ) ;
return V_37 ;
}
if ( V_44 -> V_46 ) {
V_37 = F_19 ( V_1 , V_64 ,
V_4 , V_65 ,
V_65 ) ;
if ( V_37 < 0 ) {
F_13 ( V_1 -> V_11 ,
L_5 ,
V_4 , V_37 ) ;
return V_37 ;
}
return F_15 ( V_1 , V_13 , V_44 ) ;
}
return 0 ;
}
static void F_21 ( struct V_1 * V_1 )
{
unsigned int V_2 ;
unsigned int V_4 ;
int V_37 ;
struct V_16 * V_17 = V_1 -> V_18 ;
struct V_19 * V_20 ;
V_20 = & V_17 -> V_19 [ V_66 ] ;
V_4 = V_20 -> V_22 ;
V_37 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 ) {
F_13 ( V_1 -> V_11 , L_6 ) ;
return;
}
V_2 |= V_67 ;
V_37 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_37 < 0 ) {
F_13 ( V_1 -> V_11 , L_7 ) ;
return;
}
V_4 = V_20 -> V_57 ;
V_37 = F_6 ( V_1 , V_4 , & V_2 ) ;
if ( V_37 ) {
F_13 ( V_1 -> V_11 , L_8 ) ;
return;
}
V_2 = ( V_2 << 1 ) & V_68 ;
V_37 = F_7 ( V_1 , V_4 , V_2 ) ;
if ( V_37 < 0 )
F_13 ( V_1 -> V_11 , L_9 ) ;
return;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_69 * V_70 ,
const char * V_71 ,
struct V_72 V_73 )
{
int V_13 , V_37 ;
struct V_10 * V_35 ;
struct V_43 * V_44 ;
struct V_19 * V_20 ;
struct V_74 * V_33 ;
for ( V_13 = V_17 -> V_75 ; V_13 < V_17 -> V_76 ; V_13 ++ ) {
if ( V_70 && V_70 -> V_44 [ V_13 ] )
V_44 = V_70 -> V_44 [ V_13 ] ;
else
V_44 = NULL ;
V_20 = & V_17 -> V_19 [ V_13 ] ;
V_33 = & V_15 -> V_33 [ V_13 ] ;
V_33 -> V_77 = V_20 -> V_77 ;
V_33 -> V_13 = V_13 ;
V_33 -> type = V_78 ;
V_33 -> V_79 = V_80 ;
if ( V_13 < V_81 ) {
V_33 -> V_82 = V_83 ;
if ( V_44 && V_44 -> V_46 )
V_33 -> V_84 = & V_85 ;
else
V_33 -> V_84 = & V_86 ;
V_33 -> V_87 = 900000 ;
V_33 -> V_88 = 50000 ;
V_33 -> V_89 = 1 ;
V_33 -> V_90 = 500 ;
V_33 -> V_91 = F_2 ( V_9 ,
V_20 -> V_57 ) ;
V_33 -> V_92 = V_93 ;
V_33 -> V_94 = F_2 ( V_9 ,
V_20 -> V_22 ) ;
V_33 -> V_95 = V_61 ;
if ( V_70 && ( V_13 == V_66 ) &&
V_70 -> V_96 ) {
F_21 ( V_15 -> V_1 ) ;
V_33 -> V_87 = 450000 ;
V_33 -> V_88 = 25000 ;
}
if ( V_70 && V_70 -> V_97 &&
( V_13 == V_98 ) )
V_33 -> V_90 = 2000 ;
} else {
if ( ! V_17 -> V_99 && V_13 == V_100 )
continue;
V_33 -> V_82 = 1 ;
if ( V_44 && V_44 -> V_46 )
V_33 -> V_84 = & V_101 ;
else
V_33 -> V_84 = & V_102 ;
V_33 -> V_94 =
F_2 ( V_64 ,
V_20 -> V_22 ) ;
V_33 -> V_95 = V_65 ;
}
if ( V_70 )
V_73 . V_103 = V_70 -> V_104 [ V_13 ] ;
else
V_73 . V_103 = NULL ;
V_33 -> V_105 = V_20 -> V_106 ;
V_73 . V_107 = V_17 -> V_108 [ V_13 ] . V_107 ;
V_35 = F_23 ( V_15 -> V_11 , V_33 , & V_73 ) ;
if ( F_24 ( V_35 ) ) {
F_13 ( V_15 -> V_11 ,
L_10 ,
V_71 ) ;
return F_25 ( V_35 ) ;
}
V_15 -> V_35 [ V_13 ] = V_35 ;
if ( V_70 ) {
V_44 = V_70 -> V_44 [ V_13 ] ;
if ( V_44 ) {
if ( V_13 <= V_17 -> V_109 )
V_37 = F_18 ( V_15 -> V_1 , V_13 ,
V_44 ) ;
else
V_37 = F_20 ( V_15 -> V_1 ,
V_13 , V_44 ) ;
if ( V_37 )
return V_37 ;
}
}
}
return 0 ;
}
static int F_26 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_69 * V_70 ,
const char * V_71 ,
struct V_72 V_73 )
{
int V_13 , V_37 ;
struct V_10 * V_35 ;
struct V_43 * V_44 ;
struct V_19 * V_20 ;
struct V_74 * V_33 ;
for ( V_13 = V_17 -> V_75 ; V_13 < V_17 -> V_76 ; V_13 ++ ) {
if ( V_70 && V_70 -> V_44 [ V_13 ] )
V_44 = V_70 -> V_44 [ V_13 ] ;
else
V_44 = NULL ;
V_20 = & V_17 -> V_19 [ V_13 ] ;
V_33 = & V_15 -> V_33 [ V_13 ] ;
V_33 -> V_77 = V_20 -> V_77 ;
V_33 -> V_13 = V_13 ;
V_33 -> type = V_78 ;
V_33 -> V_79 = V_80 ;
if ( V_13 < V_110 ) {
V_33 -> V_82 = V_83 ;
if ( V_44 && V_44 -> V_46 )
V_33 -> V_84 = & V_85 ;
else
V_33 -> V_84 = & V_111 ;
V_33 -> V_87 = 900000 ;
V_33 -> V_88 = 50000 ;
V_33 -> V_89 = 1 ;
V_33 -> V_90 = 500 ;
V_33 -> V_91 = F_2 ( V_9 ,
V_20 -> V_57 ) ;
V_33 -> V_92 = V_93 ;
V_33 -> V_94 = F_2 ( V_9 ,
V_20 -> V_22 ) ;
V_33 -> V_95 = V_61 ;
V_33 -> V_36 = 2500 ;
} else {
V_33 -> V_82 = 1 ;
if ( V_44 && V_44 -> V_46 )
V_33 -> V_84 = & V_101 ;
else
V_33 -> V_84 = & V_102 ;
V_33 -> V_94 =
F_2 ( V_64 ,
V_20 -> V_22 ) ;
V_33 -> V_95 = V_65 ;
}
if ( V_70 )
V_73 . V_103 = V_70 -> V_104 [ V_13 ] ;
else
V_73 . V_103 = NULL ;
V_33 -> V_105 = V_20 -> V_106 ;
V_73 . V_107 = V_17 -> V_108 [ V_13 ] . V_107 ;
V_35 = F_23 ( V_15 -> V_11 , V_33 , & V_73 ) ;
if ( F_24 ( V_35 ) ) {
F_13 ( V_15 -> V_11 ,
L_10 ,
V_71 ) ;
return F_25 ( V_35 ) ;
}
V_15 -> V_35 [ V_13 ] = V_35 ;
if ( V_70 ) {
V_44 = V_70 -> V_44 [ V_13 ] ;
if ( V_44 ) {
if ( V_13 < V_110 )
V_37 = F_18 ( V_15 -> V_1 ,
V_13 , V_44 ) ;
else
V_37 = F_20 ( V_15 -> V_1 ,
V_13 , V_44 ) ;
if ( V_37 )
return V_37 ;
}
}
}
return 0 ;
}
static int F_27 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_69 * V_70 ,
const char * V_71 ,
struct V_72 V_73 )
{
int V_13 , V_37 ;
unsigned int V_4 , V_2 ;
struct V_10 * V_35 ;
struct V_43 * V_44 ;
struct V_19 * V_20 ;
struct V_74 * V_33 ;
for ( V_13 = V_17 -> V_112 ; V_13 <= V_17 -> V_113 ; V_13 ++ ) {
bool V_114 = false ;
switch ( V_13 ) {
case V_115 :
case V_38 :
if ( V_15 -> V_116 )
continue;
if ( V_13 == V_115 )
V_114 = true ;
break;
case V_117 :
if ( ! V_15 -> V_116 )
continue;
V_114 = true ;
break;
case V_118 :
case V_39 :
if ( V_15 -> V_119 )
continue;
if ( V_13 == V_118 )
V_114 = true ;
break;
case V_120 :
if ( ! V_15 -> V_119 )
continue;
V_114 = true ;
break;
case V_47 :
case V_48 :
if ( ! F_28 ( V_15 -> V_1 , V_121 ) )
continue;
}
V_20 = & V_17 -> V_19 [ V_13 ] ;
V_33 = & V_15 -> V_33 [ V_13 ] ;
if ( ( V_13 == V_122 ) || ( V_13 == V_123 ) )
V_114 = true ;
if ( V_114 ) {
V_4 = V_20 -> V_40 ;
V_37 = F_1 ( V_15 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 < 0 ) {
F_13 ( V_15 -> V_11 ,
L_11 , V_37 ) ;
return V_37 ;
}
V_33 -> V_36 = V_41 [ V_2 & 0x3 ] ;
V_15 -> V_36 [ V_13 ] = V_33 -> V_36 ;
}
if ( V_70 && V_70 -> V_44 [ V_13 ] ) {
V_44 = V_70 -> V_44 [ V_13 ] ;
V_37 = F_17 ( V_15 -> V_1 , V_13 , V_44 ) ;
if ( V_37 )
return V_37 ;
} else {
V_44 = NULL ;
}
V_33 -> V_77 = V_20 -> V_77 ;
V_33 -> V_13 = V_13 ;
switch ( V_13 ) {
case V_47 :
case V_48 :
V_33 -> V_82 = V_124 ;
V_33 -> V_84 = & V_125 ;
V_33 -> V_91 = F_2 ( V_5 ,
V_126 ) ;
V_33 -> V_92 = V_127 ;
V_33 -> V_94 = F_2 ( V_5 ,
V_126 ) ;
if ( V_13 == V_47 )
V_33 -> V_95 = V_128 ;
else
V_33 -> V_95 = V_129 ;
V_33 -> V_130 = F_2 ( V_5 ,
V_126 ) ;
V_33 -> V_131 = V_132 ;
V_33 -> V_87 = 3750000 ;
V_33 -> V_88 = 1250000 ;
break;
default:
V_4 = V_20 -> V_57 ;
V_33 -> V_133 = 3 ;
V_37 = F_1 ( V_15 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_2 & V_134 )
V_15 -> V_135 [ V_13 ] = 1 ;
if ( V_15 -> V_135 [ V_13 ] )
V_33 -> V_136 = V_137 ;
else
V_33 -> V_136 = V_138 ;
if ( V_44 && V_44 -> V_46 )
V_33 -> V_84 = & V_139 ;
else
V_33 -> V_84 = & V_140 ;
V_33 -> V_82 = V_141 ;
V_33 -> V_91 = F_2 ( V_5 ,
V_20 -> V_57 ) ;
V_33 -> V_92 = V_142 ;
V_4 = V_20 -> V_22 ;
V_37 = F_1 ( V_15 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
V_15 -> V_32 [ V_13 ] = V_2 &
V_23 ;
V_33 -> V_94 = F_2 ( V_5 ,
V_20 -> V_22 ) ;
V_33 -> V_95 = V_23 ;
V_33 -> V_34 = V_26 ;
}
V_33 -> type = V_78 ;
V_33 -> V_79 = V_80 ;
if ( V_70 )
V_73 . V_103 = V_70 -> V_104 [ V_13 ] ;
else
V_73 . V_103 = NULL ;
V_33 -> V_105 = V_20 -> V_106 ;
V_73 . V_107 = V_17 -> V_108 [ V_13 ] . V_107 ;
V_35 = F_23 ( V_15 -> V_11 , V_33 , & V_73 ) ;
if ( F_24 ( V_35 ) ) {
F_13 ( V_15 -> V_11 ,
L_10 ,
V_71 ) ;
return F_25 ( V_35 ) ;
}
V_15 -> V_35 [ V_13 ] = V_35 ;
}
return 0 ;
}
static int F_29 ( struct V_14 * V_15 ,
struct V_16 * V_17 ,
struct V_69 * V_70 ,
const char * V_71 ,
struct V_72 V_73 )
{
int V_13 , V_37 ;
unsigned int V_4 , V_2 ;
struct V_10 * V_35 ;
struct V_43 * V_44 ;
struct V_19 * V_20 ;
struct V_74 * V_33 ;
for ( V_13 = V_17 -> V_112 ; V_13 <= V_17 -> V_113 ; V_13 ++ ) {
V_33 = & V_15 -> V_33 [ V_13 ] ;
V_33 -> V_133 = 3 ;
if ( ( V_13 == V_143 ) && V_15 -> V_144 )
continue;
if ( V_70 && V_70 -> V_44 [ V_13 ] ) {
V_44 = V_70 -> V_44 [ V_13 ] ;
V_37 = F_17 ( V_15 -> V_1 , V_13 , V_44 ) ;
if ( V_37 )
return V_37 ;
} else {
V_44 = NULL ;
}
V_20 = & V_17 -> V_19 [ V_13 ] ;
V_33 -> V_77 = V_20 -> V_77 ;
V_33 -> V_13 = V_13 ;
V_4 = V_20 -> V_57 ;
V_37 = F_1 ( V_15 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_2 & V_145 )
V_15 -> V_135 [ V_13 ] = 1 ;
if ( V_15 -> V_135 [ V_13 ] )
V_33 -> V_136 = V_137 ;
else
V_33 -> V_136 = V_138 ;
if ( V_44 && V_44 -> V_46 )
V_33 -> V_84 = & V_146 ;
else
V_33 -> V_84 = & V_147 ;
V_33 -> V_82 = V_141 ;
V_33 -> V_91 = F_2 ( V_5 ,
V_20 -> V_57 ) ;
V_33 -> V_92 = V_142 ;
V_33 -> V_36 = 2500 ;
V_4 = V_20 -> V_22 ;
V_37 = F_1 ( V_15 -> V_1 , V_4 , & V_2 ) ;
if ( V_37 )
return V_37 ;
V_15 -> V_32 [ V_13 ] = V_2 &
V_23 ;
V_33 -> V_94 = F_2 ( V_5 ,
V_20 -> V_22 ) ;
V_33 -> V_95 = V_23 ;
V_33 -> V_34 = V_26 ;
V_33 -> type = V_78 ;
V_33 -> V_79 = V_80 ;
if ( V_70 )
V_73 . V_103 = V_70 -> V_104 [ V_13 ] ;
else
V_73 . V_103 = NULL ;
V_33 -> V_105 = V_20 -> V_106 ;
V_73 . V_107 = V_17 -> V_108 [ V_13 ] . V_107 ;
V_35 = F_23 ( V_15 -> V_11 , V_33 , & V_73 ) ;
if ( F_24 ( V_35 ) ) {
F_13 ( V_15 -> V_11 ,
L_10 ,
V_71 ) ;
return F_25 ( V_35 ) ;
}
V_15 -> V_35 [ V_13 ] = V_35 ;
}
return 0 ;
}
static void F_30 ( struct V_148 * V_11 ,
struct V_149 * V_150 ,
struct V_69 * V_70 ,
struct V_16 * V_17 )
{
struct V_149 * V_151 ;
T_1 V_152 ;
int V_153 , V_37 ;
V_151 = F_31 ( V_150 , L_12 ) ;
if ( ! V_151 ) {
F_32 ( V_11 , L_13 ) ;
return;
}
V_37 = F_33 ( V_11 , V_151 , V_17 -> V_108 ,
V_17 -> V_76 ) ;
F_34 ( V_151 ) ;
if ( V_37 < 0 ) {
F_13 ( V_11 , L_14 , V_37 ) ;
return;
}
for ( V_153 = 0 ; V_153 < V_17 -> V_76 ; V_153 ++ ) {
if ( ! V_17 -> V_108 [ V_153 ] . V_103 ||
! V_17 -> V_108 [ V_153 ] . V_107 )
continue;
V_70 -> V_104 [ V_153 ] = V_17 -> V_108 [ V_153 ] . V_103 ;
V_70 -> V_44 [ V_153 ] = F_35 ( V_11 ,
sizeof( struct V_43 ) , V_154 ) ;
V_70 -> V_44 [ V_153 ] -> V_52 =
F_36 ( V_17 -> V_108 [ V_153 ] . V_107 ,
L_15 ) ;
V_37 = F_37 ( V_17 -> V_108 [ V_153 ] . V_107 ,
L_16 , & V_152 ) ;
if ( V_37 != - V_31 ) {
int V_155 ;
V_155 = V_156 ;
if ( ! V_37 ) {
switch ( V_152 ) {
case 1 :
V_155 = V_157 ;
break;
case 2 :
V_155 = V_158 ;
break;
case 3 :
V_155 = V_156 ;
break;
default:
F_38 ( 1 ) ;
F_39 ( V_11 ,
L_17 ,
V_108 [ V_153 ] . V_77 , V_152 ) ;
break;
}
}
V_70 -> V_44 [ V_153 ] -> V_46 = V_155 ;
}
V_37 = F_37 ( V_17 -> V_108 [ V_153 ] . V_107 ,
L_18 , & V_152 ) ;
if ( ! V_37 )
V_70 -> V_44 [ V_153 ] -> V_50 = V_152 ;
V_37 = F_36 ( V_17 -> V_108 [ V_153 ] . V_107 ,
L_19 ) ;
if ( V_37 )
V_70 -> V_44 [ V_153 ] -> V_58 =
V_134 ;
if ( V_153 == V_66 )
V_70 -> V_96 = F_36 (
V_17 -> V_108 [ V_153 ] . V_107 ,
L_20 ) ;
}
V_70 -> V_97 = F_36 ( V_150 , L_21 ) ;
}
static int F_40 ( struct V_159 * V_160 )
{
struct V_1 * V_1 = F_41 ( V_160 -> V_11 . V_161 ) ;
struct V_69 * V_70 = F_42 ( & V_160 -> V_11 ) ;
struct V_149 * V_150 = V_160 -> V_11 . V_107 ;
struct V_16 * V_162 ;
struct V_72 V_73 = { } ;
struct V_14 * V_15 ;
const char * V_71 ;
const struct V_163 * V_164 ;
int V_37 = 0 ;
unsigned int V_2 ;
V_164 = F_43 ( F_44 ( V_165 ) , & V_160 -> V_11 ) ;
if ( ! V_164 )
return - V_166 ;
V_162 = (struct V_16 * ) V_164 -> V_167 ;
V_70 = F_35 ( & V_160 -> V_11 , sizeof( * V_70 ) , V_154 ) ;
if ( ! V_70 )
return - V_168 ;
V_15 = F_35 ( & V_160 -> V_11 , sizeof( * V_15 ) , V_154 ) ;
if ( ! V_15 )
return - V_168 ;
if ( F_45 ( V_150 , L_22 ) ) {
V_169 [ V_170 ] . V_22 =
V_171 ;
V_172 . V_99 = false ;
}
V_15 -> V_11 = & V_160 -> V_11 ;
V_15 -> V_1 = V_1 ;
V_1 -> V_15 = V_15 ;
F_46 ( V_160 , V_15 ) ;
V_15 -> V_1 -> V_18 = V_162 ;
F_30 ( & V_160 -> V_11 , V_150 , V_70 , V_162 ) ;
V_37 = F_1 ( V_1 , V_173 , & V_2 ) ;
if ( V_37 )
return V_37 ;
if ( V_2 & V_174 )
V_15 -> V_116 = 1 ;
if ( V_2 & V_175 )
V_15 -> V_119 = 1 ;
V_73 . V_6 = V_1 -> V_6 [ V_7 ] ;
V_73 . V_11 = & V_160 -> V_11 ;
V_73 . V_162 = V_15 ;
V_71 = V_160 -> V_77 ;
V_37 = V_162 -> V_176 ( V_15 , V_162 , V_70 , V_71 ,
V_73 ) ;
if ( V_37 )
return V_37 ;
V_37 = V_162 -> V_177 ( V_15 , V_162 , V_70 , V_71 ,
V_73 ) ;
return V_37 ;
}
static int T_2 F_47 ( void )
{
return F_48 ( & V_178 ) ;
}
static void T_3 F_49 ( void )
{
F_50 ( & V_178 ) ;
}
