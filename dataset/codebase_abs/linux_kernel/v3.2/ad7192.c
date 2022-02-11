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
static int F_30 ( struct V_1 * V_2 , unsigned V_21 , int * V_7 )
{
struct V_79 * V_80 = F_31 ( V_2 ) -> V_81 ;
int V_18 ;
T_2 V_82 [ 2 ] ;
T_3 * V_83 = ( T_3 * ) V_82 ;
if ( ! ( F_32 ( V_21 , V_80 -> V_84 ) ) )
return - V_85 ;
V_18 = V_80 -> V_86 -> V_87 ( V_80 , ( T_1 * ) & V_82 ) ;
if ( V_18 )
return V_18 ;
* V_7 = * V_83 ;
return 0 ;
}
static int F_33 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_34 ( V_42 ) ;
struct V_79 * V_80 = V_42 -> V_81 ;
T_4 V_88 ;
unsigned V_89 ;
if ( ! V_80 -> V_90 )
return - V_16 ;
V_89 = F_35 ( V_80 -> V_84 , V_42 -> V_91 ) ;
V_88 = V_80 -> V_90 *
V_42 -> V_76 [ 0 ] . V_77 . V_92 / 8 ;
if ( V_80 -> V_93 ) {
V_88 += sizeof( T_2 ) ;
if ( V_88 % sizeof( T_2 ) )
V_88 += sizeof( T_2 ) - ( V_88 % sizeof( T_2 ) ) ;
}
if ( V_42 -> V_81 -> V_86 -> V_94 )
V_42 -> V_81 -> V_86 ->
V_94 ( V_42 -> V_81 , V_88 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_95 ) ;
V_2 -> V_22 = ( V_2 -> V_22 & ~ F_11 ( - 1 ) ) |
F_11 ( 1 << V_42 -> V_76 [ V_89 ] . V_96 ) ;
F_7 ( V_2 , V_25 , 3 , V_2 -> V_22 ) ;
F_13 ( V_2 -> V_17 -> V_26 ) ;
F_1 ( V_2 , 1 , 1 , V_28 , 3 , V_2 -> V_23 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return 0 ;
}
static int F_36 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_34 ( V_42 ) ;
V_2 -> V_23 = ( V_2 -> V_23 & ~ F_12 ( - 1 ) ) |
F_12 ( V_37 ) ;
V_2 -> V_27 = false ;
F_15 ( V_2 -> V_32 , V_2 -> V_27 ) ;
if ( ! V_2 -> V_30 )
F_37 ( V_2 -> V_17 -> V_31 ) ;
F_1 ( V_2 , 1 , 0 , V_28 , 3 , V_2 -> V_23 ) ;
return F_16 ( V_2 -> V_17 -> V_26 ) ;
}
static T_5 F_38 ( int V_31 , void * V_97 )
{
struct V_98 * V_99 = V_97 ;
struct V_41 * V_42 = V_99 -> V_42 ;
struct V_79 * V_80 = V_42 -> V_81 ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
T_2 V_82 [ 2 ] ;
T_6 * V_83 = ( T_6 * ) V_82 ;
if ( V_80 -> V_90 )
F_8 ( V_2 , 1 , 1 , V_33 ,
V_83 ,
V_42 -> V_76 [ 0 ] . V_77 . V_78 / 8 ) ;
if ( V_80 -> V_93 )
V_82 [ 1 ] = V_99 -> V_100 ;
V_80 -> V_86 -> V_101 ( V_80 , ( T_1 * ) V_82 , V_99 -> V_100 ) ;
F_39 ( V_42 -> V_102 ) ;
V_2 -> V_30 = false ;
F_14 ( V_2 -> V_17 -> V_31 ) ;
return V_103 ;
}
static int F_40 ( struct V_41 * V_42 )
{
int V_18 ;
V_42 -> V_81 = F_41 ( V_42 ) ;
if ( ! V_42 -> V_81 ) {
V_18 = - V_104 ;
goto V_105;
}
V_42 -> V_81 -> V_86 = & V_106 ;
V_42 -> V_107 = F_42 ( & V_108 ,
& F_38 ,
V_109 ,
V_42 ,
L_4 ,
V_42 -> V_46 ) ;
if ( V_42 -> V_107 == NULL ) {
V_18 = - V_104 ;
goto V_110;
}
V_42 -> V_81 -> V_111 = & V_112 ;
V_42 -> V_113 |= V_114 ;
return 0 ;
V_110:
F_43 ( V_42 -> V_81 ) ;
V_105:
return V_18 ;
}
static void F_44 ( struct V_41 * V_42 )
{
F_45 ( V_42 -> V_107 ) ;
F_43 ( V_42 -> V_81 ) ;
}
static T_5 F_46 ( int V_31 , void * V_115 )
{
struct V_1 * V_2 = F_34 ( V_115 ) ;
V_2 -> V_27 = true ;
F_47 ( & V_2 -> V_32 ) ;
F_37 ( V_31 ) ;
V_2 -> V_30 = true ;
F_48 ( V_2 -> V_102 , F_49 () ) ;
return V_103 ;
}
static int F_50 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_34 ( V_42 ) ;
int V_18 ;
V_2 -> V_102 = F_51 ( L_5 ,
F_52 ( V_2 -> V_17 ) -> V_116 ,
V_42 -> V_46 ) ;
if ( V_2 -> V_102 == NULL ) {
V_18 = - V_104 ;
goto V_105;
}
V_18 = F_53 ( V_2 -> V_17 -> V_31 ,
F_46 ,
V_117 ,
F_52 ( V_2 -> V_17 ) -> V_116 ,
V_42 ) ;
if ( V_18 )
goto V_118;
F_37 ( V_2 -> V_17 -> V_31 ) ;
V_2 -> V_30 = true ;
V_2 -> V_102 -> V_40 . V_119 = & V_2 -> V_17 -> V_40 ;
V_2 -> V_102 -> V_120 = V_121 ;
V_2 -> V_102 -> V_122 = V_42 ;
V_18 = F_54 ( V_2 -> V_102 ) ;
V_42 -> V_102 = V_2 -> V_102 ;
if ( V_18 )
goto V_123;
return 0 ;
V_123:
F_55 ( V_2 -> V_17 -> V_31 , V_42 ) ;
V_118:
F_56 ( V_2 -> V_102 ) ;
V_105:
return V_18 ;
}
static void F_57 ( struct V_41 * V_42 )
{
struct V_1 * V_2 = F_34 ( V_42 ) ;
F_58 ( V_2 -> V_102 ) ;
F_55 ( V_2 -> V_17 -> V_31 , V_42 ) ;
F_56 ( V_2 -> V_102 ) ;
}
static T_7 F_59 ( struct V_124 * V_40 ,
struct V_125 * V_126 ,
char * V_127 )
{
struct V_41 * V_42 = F_60 ( V_40 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
return sprintf ( V_127 , L_6 , V_2 -> V_53 /
( V_2 -> V_66 * 1024 * F_27 ( V_2 -> V_23 ) ) ) ;
}
static T_7 F_61 ( struct V_124 * V_40 ,
struct V_125 * V_126 ,
const char * V_127 ,
T_4 V_12 )
{
struct V_41 * V_42 = F_60 ( V_40 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
unsigned long V_128 ;
int div , V_18 ;
V_18 = F_62 ( V_127 , 10 , & V_128 ) ;
if ( V_18 )
return V_18 ;
F_63 ( & V_42 -> V_129 ) ;
if ( F_64 ( V_42 ) ) {
F_65 ( & V_42 -> V_129 ) ;
return - V_85 ;
}
div = V_2 -> V_53 / ( V_128 * V_2 -> V_66 * 1024 ) ;
if ( div < 1 || div > 1023 ) {
V_18 = - V_16 ;
goto V_29;
}
V_2 -> V_23 &= ~ F_27 ( - 1 ) ;
V_2 -> V_23 |= F_27 ( div ) ;
F_7 ( V_2 , V_28 , 3 , V_2 -> V_23 ) ;
V_29:
F_65 ( & V_42 -> V_129 ) ;
return V_18 ? V_18 : V_12 ;
}
static T_7 F_66 ( struct V_124 * V_40 ,
struct V_125 * V_126 , char * V_127 )
{
struct V_41 * V_42 = F_60 ( V_40 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
int V_38 , V_12 = 0 ;
for ( V_38 = 0 ; V_38 < F_19 ( V_2 -> V_73 ) ; V_38 ++ )
V_12 += sprintf ( V_127 + V_12 , L_7 , V_2 -> V_73 [ V_38 ] [ 0 ] ,
V_2 -> V_73 [ V_38 ] [ 1 ] ) ;
V_12 += sprintf ( V_127 + V_12 , L_8 ) ;
return V_12 ;
}
static T_7 F_67 ( struct V_124 * V_40 ,
struct V_125 * V_126 ,
char * V_127 )
{
struct V_41 * V_42 = F_60 ( V_40 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
return sprintf ( V_127 , L_6 , ! ! ( V_2 -> V_23 & V_130 ) ) ;
}
static T_7 F_68 ( struct V_124 * V_40 ,
struct V_125 * V_126 ,
char * V_127 )
{
struct V_41 * V_42 = F_60 ( V_40 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
return sprintf ( V_127 , L_6 , ! ! ( V_2 -> V_131 & V_132 ) ) ;
}
static T_7 F_69 ( struct V_124 * V_40 ,
struct V_125 * V_126 ,
const char * V_127 ,
T_4 V_12 )
{
struct V_41 * V_42 = F_60 ( V_40 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
struct V_133 * V_134 = F_70 ( V_126 ) ;
int V_18 ;
bool V_7 ;
V_18 = F_71 ( V_127 , & V_7 ) ;
if ( V_18 < 0 )
return V_18 ;
F_63 ( & V_42 -> V_129 ) ;
if ( F_64 ( V_42 ) ) {
F_65 ( & V_42 -> V_129 ) ;
return - V_85 ;
}
switch ( V_134 -> V_96 ) {
case V_135 :
if ( V_7 )
V_2 -> V_131 |= V_132 ;
else
V_2 -> V_131 &= ~ V_132 ;
F_7 ( V_2 , V_135 , 1 , V_2 -> V_131 ) ;
break;
case V_28 :
if ( V_7 )
V_2 -> V_23 |= V_130 ;
else
V_2 -> V_23 &= ~ V_130 ;
F_7 ( V_2 , V_135 , 3 , V_2 -> V_23 ) ;
break;
default:
V_18 = - V_16 ;
}
F_65 ( & V_42 -> V_129 ) ;
return V_18 ? V_18 : V_12 ;
}
static T_8 F_72 ( struct V_136 * V_137 ,
struct V_138 * V_126 , int V_139 )
{
struct V_124 * V_40 = F_73 ( V_137 , struct V_124 , V_137 ) ;
struct V_41 * V_42 = F_60 ( V_40 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
T_8 V_23 = V_126 -> V_23 ;
if ( ( V_2 -> V_34 != V_35 ) &&
( V_126 == & V_140 . V_141 . V_126 ) )
V_23 = 0 ;
return V_23 ;
}
static int F_74 ( struct V_41 * V_42 ,
struct V_142 const * V_143 ,
int * V_7 ,
int * V_144 ,
long V_14 )
{
struct V_1 * V_2 = F_34 ( V_42 ) ;
int V_18 , V_145 = 0 ;
bool V_146 = ! ! ( V_2 -> V_22 & V_70 ) ;
switch ( V_14 ) {
case 0 :
F_63 ( & V_42 -> V_129 ) ;
if ( F_64 ( V_42 ) )
V_18 = F_30 ( V_2 ,
V_143 -> V_147 , & V_145 ) ;
else
V_18 = F_10 ( V_2 , V_143 -> V_96 ,
V_143 -> V_77 . V_78 / 8 , & V_145 ) ;
F_65 ( & V_42 -> V_129 ) ;
if ( V_18 < 0 )
return V_18 ;
* V_7 = ( V_145 >> V_143 -> V_77 . V_148 ) &
( ( 1 << ( V_143 -> V_77 . V_78 ) ) - 1 ) ;
switch ( V_143 -> type ) {
case V_149 :
if ( ! V_146 )
* V_7 -= ( 1 << ( V_143 -> V_77 . V_78 - 1 ) ) ;
break;
case V_150 :
* V_7 -= 0x800000 ;
* V_7 /= 2815 ;
* V_7 -= 273 ;
break;
default:
return - V_16 ;
}
return V_151 ;
case ( 1 << V_152 ) :
F_63 ( & V_42 -> V_129 ) ;
* V_7 = V_2 -> V_73 [ F_28 ( V_2 -> V_22 ) ] [ 0 ] ;
* V_144 = V_2 -> V_73 [ F_28 ( V_2 -> V_22 ) ] [ 1 ] ;
F_65 ( & V_42 -> V_129 ) ;
return V_153 ;
case ( 1 << V_154 ) :
* V_7 = 1000 ;
return V_151 ;
}
return - V_16 ;
}
static int F_75 ( struct V_41 * V_42 ,
struct V_142 const * V_143 ,
int V_7 ,
int V_144 ,
long V_155 )
{
struct V_1 * V_2 = F_34 ( V_42 ) ;
int V_18 , V_38 ;
unsigned int V_156 ;
F_63 ( & V_42 -> V_129 ) ;
if ( F_64 ( V_42 ) ) {
F_65 ( & V_42 -> V_129 ) ;
return - V_85 ;
}
switch ( V_155 ) {
case ( 1 << V_152 ) :
V_18 = - V_16 ;
for ( V_38 = 0 ; V_38 < F_19 ( V_2 -> V_73 ) ; V_38 ++ )
if ( V_144 == V_2 -> V_73 [ V_38 ] [ 1 ] ) {
V_156 = V_2 -> V_22 ;
V_2 -> V_22 &= ~ F_28 ( - 1 ) ;
V_2 -> V_22 |= F_28 ( V_38 ) ;
if ( V_156 != V_2 -> V_22 ) {
F_7 ( V_2 , V_25 ,
3 , V_2 -> V_22 ) ;
F_18 ( V_2 ) ;
}
V_18 = 0 ;
}
default:
V_18 = - V_16 ;
}
F_65 ( & V_42 -> V_129 ) ;
return V_18 ;
}
static int F_76 ( struct V_41 * V_42 ,
struct V_157 * V_102 )
{
if ( V_42 -> V_102 != V_102 )
return - V_16 ;
return 0 ;
}
static int F_77 ( struct V_41 * V_42 ,
struct V_142 const * V_143 ,
long V_155 )
{
return V_153 ;
}
static int T_9 F_78 ( struct V_158 * V_17 )
{
struct V_43 * V_44 = V_17 -> V_40 . V_159 ;
struct V_1 * V_2 ;
struct V_41 * V_42 ;
int V_18 , V_38 , V_160 = 0 ;
if ( ! V_44 ) {
F_20 ( & V_17 -> V_40 , L_9 ) ;
return - V_161 ;
}
if ( ! V_17 -> V_31 ) {
F_20 ( & V_17 -> V_40 , L_10 ) ;
return - V_161 ;
}
V_42 = F_79 ( sizeof( * V_2 ) ) ;
if ( V_42 == NULL )
return - V_104 ;
V_2 = F_34 ( V_42 ) ;
V_2 -> V_5 = F_80 ( & V_17 -> V_40 , L_11 ) ;
if ( ! F_81 ( V_2 -> V_5 ) ) {
V_18 = F_82 ( V_2 -> V_5 ) ;
if ( V_18 )
goto V_162;
V_160 = F_83 ( V_2 -> V_5 ) ;
}
V_2 -> V_44 = V_44 ;
if ( V_44 && V_44 -> V_163 )
V_2 -> V_75 = V_44 -> V_163 ;
else if ( V_160 )
V_2 -> V_75 = V_160 / 1000 ;
else
F_25 ( & V_17 -> V_40 , L_12 ) ;
F_84 ( V_17 , V_42 ) ;
V_2 -> V_17 = V_17 ;
V_2 -> V_34 = F_52 ( V_17 ) -> V_164 ;
V_42 -> V_40 . V_119 = & V_17 -> V_40 ;
V_42 -> V_116 = F_52 ( V_17 ) -> V_116 ;
V_42 -> V_113 = V_165 ;
V_42 -> V_76 = V_166 ;
V_42 -> V_167 = F_19 ( V_166 ) ;
V_42 -> V_168 = V_2 -> V_168 ;
V_42 -> V_169 = & V_170 ;
for ( V_38 = 0 ; V_38 < V_42 -> V_167 ; V_38 ++ )
V_2 -> V_168 [ V_38 ] = ( 1 << V_38 ) | ( 1 <<
V_42 -> V_76 [ V_42 -> V_167 - 1 ] .
V_147 ) ;
F_85 ( & V_2 -> V_32 ) ;
V_18 = F_40 ( V_42 ) ;
if ( V_18 )
goto V_171;
V_18 = F_50 ( V_42 ) ;
if ( V_18 )
goto V_172;
V_18 = F_86 ( V_42 ,
V_42 -> V_76 ,
V_42 -> V_167 ) ;
if ( V_18 )
goto V_173;
V_18 = F_21 ( V_2 ) ;
if ( V_18 )
goto V_174;
V_18 = F_87 ( V_42 ) ;
if ( V_18 < 0 )
goto V_174;
return 0 ;
V_174:
F_88 ( V_42 ) ;
V_173:
F_57 ( V_42 ) ;
V_172:
F_44 ( V_42 ) ;
V_171:
if ( ! F_81 ( V_2 -> V_5 ) )
F_89 ( V_2 -> V_5 ) ;
V_162:
if ( ! F_81 ( V_2 -> V_5 ) )
F_90 ( V_2 -> V_5 ) ;
F_91 ( V_42 ) ;
return V_18 ;
}
static int F_92 ( struct V_158 * V_17 )
{
struct V_41 * V_42 = F_22 ( V_17 ) ;
struct V_1 * V_2 = F_34 ( V_42 ) ;
F_93 ( V_42 ) ;
F_88 ( V_42 ) ;
F_57 ( V_42 ) ;
F_44 ( V_42 ) ;
if ( ! F_81 ( V_2 -> V_5 ) ) {
F_89 ( V_2 -> V_5 ) ;
F_90 ( V_2 -> V_5 ) ;
}
return 0 ;
}
static int T_10 F_94 ( void )
{
return F_95 ( & V_175 ) ;
}
static void T_11 F_96 ( void )
{
F_97 ( & V_175 ) ;
}
