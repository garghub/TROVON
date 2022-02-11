static int F_1 ( struct V_1 * V_2 , bool V_3 ,
bool V_4 , unsigned char V_5 ,
unsigned V_6 , unsigned V_7 )
{
T_1 * V_8 = V_2 -> V_8 ;
struct V_9 V_10 = {
. V_11 = V_8 ,
. V_12 = V_6 + 1 ,
. V_4 = V_4 ,
} ;
struct V_13 V_14 ;
V_8 [ 0 ] = V_15 | F_2 ( V_5 ) ;
switch ( V_6 ) {
case 3 :
V_8 [ 1 ] = V_7 >> 16 ;
V_8 [ 2 ] = V_7 >> 8 ;
V_8 [ 3 ] = V_7 ;
break;
case 2 :
V_8 [ 1 ] = V_7 >> 8 ;
V_8 [ 2 ] = V_7 ;
break;
case 1 :
V_8 [ 1 ] = V_7 ;
break;
default:
return - V_16 ;
}
F_3 ( & V_14 ) ;
F_4 ( & V_10 , & V_14 ) ;
if ( V_3 )
return F_5 ( V_2 -> V_17 , & V_14 ) ;
else
return F_6 ( V_2 -> V_17 , & V_14 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned V_5 , unsigned V_6 , unsigned V_7 )
{
return F_1 ( V_2 , false , false , V_5 , V_6 , V_7 ) ;
}
static int F_8 ( struct V_1 * V_2 , bool V_3 ,
bool V_4 , unsigned char V_5 ,
int * V_7 , unsigned V_6 )
{
T_1 * V_8 = V_2 -> V_8 ;
int V_18 ;
struct V_9 V_10 [] = {
{
. V_11 = V_8 ,
. V_12 = 1 ,
} , {
. V_19 = V_8 ,
. V_12 = V_6 ,
. V_4 = V_4 ,
} ,
} ;
struct V_13 V_14 ;
V_8 [ 0 ] = V_20 | F_2 ( V_5 ) ;
F_3 ( & V_14 ) ;
F_4 ( & V_10 [ 0 ] , & V_14 ) ;
F_4 ( & V_10 [ 1 ] , & V_14 ) ;
if ( V_3 )
V_18 = F_5 ( V_2 -> V_17 , & V_14 ) ;
else
V_18 = F_6 ( V_2 -> V_17 , & V_14 ) ;
if ( V_18 < 0 )
return V_18 ;
switch ( V_6 ) {
case 3 :
* V_7 = V_8 [ 0 ] << 16 | V_8 [ 1 ] << 8 | V_8 [ 2 ] ;
break;
case 2 :
* V_7 = V_8 [ 0 ] << 8 | V_8 [ 1 ] ;
break;
case 1 :
* V_7 = V_8 [ 0 ] ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned V_5 , int * V_7 , unsigned V_6 )
{
return F_8 ( V_2 , 0 , 0 , V_5 , V_7 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_2 , unsigned V_21 ,
unsigned V_12 , int * V_7 )
{
int V_18 ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) |
F_11 ( 1 << V_21 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_24 ) ;
F_7 ( V_2 , V_25 , 3 , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
V_2 -> V_27 = false ;
V_18 = F_1 ( V_2 , 1 , 1 , V_28 , 3 , V_2 -> V_23 ) ;
if ( V_18 < 0 )
goto V_29;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
V_18 = F_8 ( V_2 , 1 , 0 , V_33 , V_7 , V_12 ) ;
V_29:
F_16 ( V_2 -> V_17 -> V_26 ) ;
return V_18 ;
}
static int F_17 ( struct V_1 * V_2 , unsigned V_23 , unsigned V_21 )
{
int V_18 ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) |
F_11 ( 1 << V_21 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) | F_12 ( V_23 ) ;
F_7 ( V_2 , V_25 , 3 , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
V_2 -> V_27 = false ;
V_18 = F_1 ( V_2 , 1 , 1 , V_28 , 3 ,
( V_2 -> V_34 != V_35 ) ?
V_2 -> V_23 | V_36 :
V_2 -> V_23 ) ;
if ( V_18 < 0 )
goto V_29;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_37 ) ;
V_18 = F_1 ( V_2 , 1 , 0 , V_28 , 3 , V_2 -> V_23 ) ;
V_29:
F_16 ( V_2 -> V_17 -> V_26 ) ;
return V_18 ;
}
static int F_18 ( struct V_1 * V_2 )
{
int V_38 , V_18 ;
for ( V_38 = 0 ; V_38 < F_19 ( V_39 ) ; V_38 ++ ) {
V_18 = F_17 ( V_2 , V_39 [ V_38 ] [ 0 ] ,
V_39 [ V_38 ] [ 1 ] ) ;
if ( V_18 )
goto V_29;
}
return 0 ;
V_29:
F_20 ( & V_2 -> V_17 -> V_40 , L_1 ) ;
return V_18 ;
}
static int F_21 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_22 ( V_2 -> V_17 ) ;
struct V_43 * V_44 = V_2 -> V_44 ;
unsigned long long V_45 ;
int V_38 , V_18 , V_46 ;
T_1 V_47 [ 6 ] ;
memset ( & V_47 , 0xFF , 6 ) ;
V_18 = F_23 ( V_2 -> V_17 , & V_47 , 6 ) ;
if ( V_18 < 0 )
goto V_29;
F_24 ( 1 ) ;
V_18 = F_9 ( V_2 , V_48 , & V_46 , 1 ) ;
if ( V_18 )
goto V_29;
V_46 &= V_49 ;
if ( V_46 != V_2 -> V_34 )
F_25 ( & V_2 -> V_17 -> V_40 , L_2 , V_46 ) ;
switch ( V_44 -> V_50 ) {
case V_51 :
case V_52 :
V_2 -> V_53 = V_54 ;
break;
case V_55 :
case V_56 :
if ( V_44 -> V_57 )
V_2 -> V_53 = V_44 -> V_57 ;
else
V_2 -> V_53 = V_54 ;
break;
default:
V_18 = - V_16 ;
goto V_29;
}
V_2 -> V_23 = F_12 ( V_37 ) |
F_26 ( V_44 -> V_50 ) |
F_27 ( 480 ) ;
V_2 -> V_22 = F_28 ( 0 ) ;
if ( V_44 -> V_58 )
V_2 -> V_23 |= V_59 ;
if ( V_44 -> V_60 )
V_2 -> V_23 |= V_61 ;
if ( V_44 -> V_62 && ( V_2 -> V_34 != V_35 ) )
V_2 -> V_22 |= V_63 ;
if ( V_44 -> V_64 ) {
V_2 -> V_22 |= V_65 ;
if ( V_44 -> V_60 )
V_2 -> V_66 = 3 ;
else
V_2 -> V_66 = 4 ;
} else {
V_2 -> V_66 = 1 ;
}
if ( V_44 -> V_67 )
V_2 -> V_22 |= V_68 ;
if ( V_44 -> V_69 )
V_2 -> V_22 |= V_70 ;
if ( V_44 -> V_71 )
V_2 -> V_22 |= V_72 ;
V_18 = F_7 ( V_2 , V_28 , 3 , V_2 -> V_23 ) ;
if ( V_18 )
goto V_29;
V_18 = F_7 ( V_2 , V_25 , 3 , V_2 -> V_22 ) ;
if ( V_18 )
goto V_29;
V_18 = F_18 ( V_2 ) ;
if ( V_18 )
goto V_29;
for ( V_38 = 0 ; V_38 < F_19 ( V_2 -> V_73 ) ; V_38 ++ ) {
V_45 = ( ( V_74 ) V_2 -> V_75 * 100000000 )
>> ( V_42 -> V_76 [ 0 ] . V_77 . V_78 -
( ( V_2 -> V_22 & V_70 ) ? 0 : 1 ) ) ;
V_45 >>= V_38 ;
V_2 -> V_73 [ V_38 ] [ 1 ] = F_29 ( V_45 , 100000000 ) * 10 ;
V_2 -> V_73 [ V_38 ] [ 0 ] = V_45 ;
}
return 0 ;
V_29:
F_20 ( & V_2 -> V_17 -> V_40 , L_3 ) ;
return V_18 ;
}
static int F_30 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_31 ( V_42 ) ;
unsigned V_79 ;
int V_18 ;
if ( F_32 ( V_42 -> V_80 , V_42 -> V_81 ) )
return - V_16 ;
V_18 = F_33 ( V_42 ) ;
if ( V_18 < 0 )
return V_18 ;
V_79 = F_34 ( V_42 -> V_80 ,
V_42 -> V_81 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_82 ) ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) |
F_11 ( 1 << V_42 -> V_76 [ V_79 ] . V_83 ) ;
F_7 ( V_2 , V_25 , 3 , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
F_1 ( V_2 , 1 , 1 , V_28 , 3 , V_2 -> V_23 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return 0 ;
}
static int F_35 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_31 ( V_42 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_37 ) ;
V_2 -> V_27 = false ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
if ( ! V_2 -> V_30 )
F_36 ( V_2 -> V_17 -> V_31 ) ;
F_1 ( V_2 , 1 , 0 , V_28 , 3 , V_2 -> V_23 ) ;
return F_16 ( V_2 -> V_17 -> V_26 ) ;
}
static T_2 F_37 ( int V_31 , void * V_84 )
{
struct V_85 * V_86 = V_84 ;
struct V_41 * V_42 = V_86 -> V_42 ;
struct V_87 * V_88 = V_42 -> V_89 ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
T_3 V_90 [ 2 ] ;
T_4 * V_91 = ( T_4 * ) V_90 ;
if ( ! F_32 ( V_42 -> V_80 , V_42 -> V_81 ) )
F_8 ( V_2 , 1 , 1 , V_33 ,
V_91 ,
V_42 -> V_76 [ 0 ] . V_77 . V_78 / 8 ) ;
if ( V_42 -> V_92 )
V_90 [ 1 ] = V_86 -> V_93 ;
V_88 -> V_94 -> V_95 ( V_88 , ( T_1 * ) V_90 , V_86 -> V_93 ) ;
F_38 ( V_42 -> V_96 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return V_97 ;
}
static int F_39 ( struct V_41 * V_42 )
{
return F_40 ( V_42 , & V_98 ,
& F_37 , & V_99 ) ;
}
static void F_41 ( struct V_41 * V_42 )
{
F_42 ( V_42 ) ;
}
static T_2 F_43 ( int V_31 , void * V_100 )
{
struct V_1 * V_2 = F_31 ( V_100 ) ;
V_2 -> V_27 = true ;
F_44 ( & V_2 -> V_32 ) ;
F_36 ( V_31 ) ;
V_2 -> V_30 = true ;
F_45 ( V_2 -> V_96 , F_46 () ) ;
return V_97 ;
}
static int F_47 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_31 ( V_42 ) ;
int V_18 ;
V_2 -> V_96 = F_48 ( L_4 ,
F_49 ( V_2 -> V_17 ) -> V_101 ,
V_42 -> V_46 ) ;
if ( V_2 -> V_96 == NULL ) {
V_18 = - V_102 ;
goto V_103;
}
V_2 -> V_96 -> V_104 = & V_105 ;
V_18 = F_50 ( V_2 -> V_17 -> V_31 ,
F_43 ,
V_106 ,
F_49 ( V_2 -> V_17 ) -> V_101 ,
V_42 ) ;
if ( V_18 )
goto V_107;
F_36 ( V_2 -> V_17 -> V_31 ) ;
V_2 -> V_30 = true ;
V_2 -> V_96 -> V_40 . V_108 = & V_2 -> V_17 -> V_40 ;
V_2 -> V_96 -> V_109 = V_42 ;
V_18 = F_51 ( V_2 -> V_96 ) ;
V_42 -> V_96 = V_2 -> V_96 ;
if ( V_18 )
goto V_110;
return 0 ;
V_110:
F_52 ( V_2 -> V_17 -> V_31 , V_42 ) ;
V_107:
F_53 ( V_2 -> V_96 ) ;
V_103:
return V_18 ;
}
static void F_54 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_31 ( V_42 ) ;
F_55 ( V_2 -> V_96 ) ;
F_52 ( V_2 -> V_17 -> V_31 , V_42 ) ;
F_53 ( V_2 -> V_96 ) ;
}
static T_5 F_56 ( struct V_111 * V_40 ,
struct V_112 * V_113 ,
char * V_114 )
{
struct V_41 * V_42 = F_57 ( V_40 ) ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
return sprintf ( V_114 , L_5 , V_2 -> V_53 /
( V_2 -> V_66 * 1024 * F_27 ( V_2 -> V_23 ) ) ) ;
}
static T_5 F_58 ( struct V_111 * V_40 ,
struct V_112 * V_113 ,
const char * V_114 ,
T_6 V_12 )
{
struct V_41 * V_42 = F_57 ( V_40 ) ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
unsigned long V_115 ;
int div , V_18 ;
V_18 = F_59 ( V_114 , 10 , & V_115 ) ;
if ( V_18 )
return V_18 ;
if ( V_115 == 0 )
return - V_16 ;
F_60 ( & V_42 -> V_116 ) ;
if ( F_61 ( V_42 ) ) {
F_62 ( & V_42 -> V_116 ) ;
return - V_117 ;
}
div = V_2 -> V_53 / ( V_115 * V_2 -> V_66 * 1024 ) ;
if ( div < 1 || div > 1023 ) {
V_18 = - V_16 ;
goto V_29;
}
V_2 -> V_23 &= ~ F_27 ( - 1 ) ;
V_2 -> V_23 |= F_27 ( div ) ;
F_7 ( V_2 , V_28 , 3 , V_2 -> V_23 ) ;
V_29:
F_62 ( & V_42 -> V_116 ) ;
return V_18 ? V_18 : V_12 ;
}
static T_5 F_63 ( struct V_111 * V_40 ,
struct V_112 * V_113 , char * V_114 )
{
struct V_41 * V_42 = F_57 ( V_40 ) ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
int V_38 , V_12 = 0 ;
for ( V_38 = 0 ; V_38 < F_19 ( V_2 -> V_73 ) ; V_38 ++ )
V_12 += sprintf ( V_114 + V_12 , L_6 , V_2 -> V_73 [ V_38 ] [ 0 ] ,
V_2 -> V_73 [ V_38 ] [ 1 ] ) ;
V_12 += sprintf ( V_114 + V_12 , L_7 ) ;
return V_12 ;
}
static T_5 F_64 ( struct V_111 * V_40 ,
struct V_112 * V_113 ,
char * V_114 )
{
struct V_41 * V_42 = F_57 ( V_40 ) ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
return sprintf ( V_114 , L_5 , ! ! ( V_2 -> V_23 & V_118 ) ) ;
}
static T_5 F_65 ( struct V_111 * V_40 ,
struct V_112 * V_113 ,
char * V_114 )
{
struct V_41 * V_42 = F_57 ( V_40 ) ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
return sprintf ( V_114 , L_5 , ! ! ( V_2 -> V_119 & V_120 ) ) ;
}
static T_5 F_66 ( struct V_111 * V_40 ,
struct V_112 * V_113 ,
const char * V_114 ,
T_6 V_12 )
{
struct V_41 * V_42 = F_57 ( V_40 ) ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
struct V_121 * V_122 = F_67 ( V_113 ) ;
int V_18 ;
bool V_7 ;
V_18 = F_68 ( V_114 , & V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
F_60 ( & V_42 -> V_116 ) ;
if ( F_61 ( V_42 ) ) {
F_62 ( & V_42 -> V_116 ) ;
return - V_117 ;
}
switch ( ( V_123 ) V_122 -> V_83 ) {
case V_124 :
if ( V_7 )
V_2 -> V_119 |= V_120 ;
else
V_2 -> V_119 &= ~ V_120 ;
F_7 ( V_2 , V_124 , 1 , V_2 -> V_119 ) ;
break;
case V_28 :
if ( V_7 )
V_2 -> V_23 |= V_118 ;
else
V_2 -> V_23 &= ~ V_118 ;
F_7 ( V_2 , V_28 , 3 , V_2 -> V_23 ) ;
break;
default:
V_18 = - V_16 ;
}
F_62 ( & V_42 -> V_116 ) ;
return V_18 ? V_18 : V_12 ;
}
static unsigned int F_69 ( bool V_125 )
{
return V_125 ? 2815 * 2 : 2815 ;
}
static int F_70 ( struct V_41 * V_42 ,
struct V_126 const * V_127 ,
int * V_7 ,
int * V_128 ,
long V_14 )
{
struct V_1 * V_2 = F_31 ( V_42 ) ;
int V_18 , V_129 = 0 ;
bool V_125 = ! ! ( V_2 -> V_22 & V_70 ) ;
switch ( V_14 ) {
case V_130 :
F_60 ( & V_42 -> V_116 ) ;
if ( F_61 ( V_42 ) )
V_18 = - V_117 ;
else
V_18 = F_10 ( V_2 , V_127 -> V_83 ,
V_127 -> V_77 . V_78 / 8 , & V_129 ) ;
F_62 ( & V_42 -> V_116 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_7 = ( V_129 >> V_127 -> V_77 . V_131 ) &
( ( 1 << ( V_127 -> V_77 . V_78 ) ) - 1 ) ;
return V_132 ;
case V_133 :
switch ( V_127 -> type ) {
case V_134 :
F_60 ( & V_42 -> V_116 ) ;
* V_7 = V_2 -> V_73 [ F_28 ( V_2 -> V_22 ) ] [ 0 ] ;
* V_128 = V_2 -> V_73 [ F_28 ( V_2 -> V_22 ) ] [ 1 ] ;
F_62 ( & V_42 -> V_116 ) ;
return V_135 ;
case V_136 :
* V_7 = 0 ;
* V_128 = 1000000000 / F_69 ( V_125 ) ;
return V_135 ;
default:
return - V_16 ;
}
case V_137 :
if ( ! V_125 )
* V_7 = - ( 1 << ( V_127 -> V_77 . V_78 - 1 ) ) ;
else
* V_7 = 0 ;
if ( V_127 -> type == V_136 )
* V_7 -= 273 * F_69 ( V_125 ) ;
return V_132 ;
}
return - V_16 ;
}
static int F_71 ( struct V_41 * V_42 ,
struct V_126 const * V_127 ,
int V_7 ,
int V_128 ,
long V_138 )
{
struct V_1 * V_2 = F_31 ( V_42 ) ;
int V_18 , V_38 ;
unsigned int V_139 ;
F_60 ( & V_42 -> V_116 ) ;
if ( F_61 ( V_42 ) ) {
F_62 ( & V_42 -> V_116 ) ;
return - V_117 ;
}
switch ( V_138 ) {
case V_133 :
V_18 = - V_16 ;
for ( V_38 = 0 ; V_38 < F_19 ( V_2 -> V_73 ) ; V_38 ++ )
if ( V_128 == V_2 -> V_73 [ V_38 ] [ 1 ] ) {
V_139 = V_2 -> V_22 ;
V_2 -> V_22 &= ~ F_28 ( - 1 ) ;
V_2 -> V_22 |= F_28 ( V_38 ) ;
if ( V_139 != V_2 -> V_22 ) {
F_7 ( V_2 , V_25 ,
3 , V_2 -> V_22 ) ;
F_18 ( V_2 ) ;
}
V_18 = 0 ;
}
break;
default:
V_18 = - V_16 ;
}
F_62 ( & V_42 -> V_116 ) ;
return V_18 ;
}
static int F_72 ( struct V_41 * V_42 ,
struct V_140 * V_96 )
{
if ( V_42 -> V_96 != V_96 )
return - V_16 ;
return 0 ;
}
static int F_73 ( struct V_41 * V_42 ,
struct V_126 const * V_127 ,
long V_138 )
{
return V_135 ;
}
static int T_7 F_74 ( struct V_141 * V_17 )
{
struct V_43 * V_44 = V_17 -> V_40 . V_142 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_18 , V_143 = 0 ;
if ( ! V_44 ) {
F_20 ( & V_17 -> V_40 , L_8 ) ;
return - V_144 ;
}
if ( ! V_17 -> V_31 ) {
F_20 ( & V_17 -> V_40 , L_9 ) ;
return - V_144 ;
}
V_42 = F_75 ( sizeof( * V_2 ) ) ;
if ( V_42 == NULL )
return - V_102 ;
V_2 = F_31 ( V_42 ) ;
V_2 -> V_5 = F_76 ( & V_17 -> V_40 , L_10 ) ;
if ( ! F_77 ( V_2 -> V_5 ) ) {
V_18 = F_78 ( V_2 -> V_5 ) ;
if ( V_18 )
goto V_145;
V_143 = F_79 ( V_2 -> V_5 ) ;
}
V_2 -> V_44 = V_44 ;
if ( V_44 && V_44 -> V_146 )
V_2 -> V_75 = V_44 -> V_146 ;
else if ( V_143 )
V_2 -> V_75 = V_143 / 1000 ;
else
F_25 ( & V_17 -> V_40 , L_11 ) ;
F_80 ( V_17 , V_42 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_34 = F_49 ( V_17 ) -> V_147 ;
V_42 -> V_40 . V_108 = & V_17 -> V_40 ;
V_42 -> V_101 = F_49 ( V_17 ) -> V_101 ;
V_42 -> V_148 = V_149 ;
V_42 -> V_76 = V_150 ;
V_42 -> V_151 = F_19 ( V_150 ) ;
if ( V_2 -> V_34 == V_35 )
V_42 -> V_152 = & V_153 ;
else
V_42 -> V_152 = & V_154 ;
F_81 ( & V_2 -> V_32 ) ;
V_18 = F_39 ( V_42 ) ;
if ( V_18 )
goto V_155;
V_18 = F_47 ( V_42 ) ;
if ( V_18 )
goto V_156;
V_18 = F_21 ( V_2 ) ;
if ( V_18 )
goto V_157;
V_18 = F_82 ( V_42 ) ;
if ( V_18 < 0 )
goto V_157;
return 0 ;
V_157:
F_54 ( V_42 ) ;
V_156:
F_41 ( V_42 ) ;
V_155:
if ( ! F_77 ( V_2 -> V_5 ) )
F_83 ( V_2 -> V_5 ) ;
V_145:
if ( ! F_77 ( V_2 -> V_5 ) )
F_84 ( V_2 -> V_5 ) ;
F_85 ( V_42 ) ;
return V_18 ;
}
static int F_86 ( struct V_141 * V_17 )
{
struct V_41 * V_42 = F_22 ( V_17 ) ;
struct V_1 * V_2 = F_31 ( V_42 ) ;
F_87 ( V_42 ) ;
F_54 ( V_42 ) ;
F_41 ( V_42 ) ;
if ( ! F_77 ( V_2 -> V_5 ) ) {
F_83 ( V_2 -> V_5 ) ;
F_84 ( V_2 -> V_5 ) ;
}
return 0 ;
}
