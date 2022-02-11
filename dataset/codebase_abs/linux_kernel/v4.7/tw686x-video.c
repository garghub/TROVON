static unsigned int F_1 ( T_1 V_1 , unsigned int V_2 )
{
static const unsigned int V_3 [ 15 ] = {
0x00000000 , 0x00000001 , 0x00004001 , 0x00104001 , 0x00404041 ,
0x01041041 , 0x01104411 , 0x01111111 , 0x04444445 , 0x04511445 ,
0x05145145 , 0x05151515 , 0x05515455 , 0x05551555 , 0x05555555
} ;
static const unsigned int V_4 [ 26 ] = {
0 , 1 , 1 , 2 , 3 , 3 , 4 , 4 , 5 , 5 , 6 , 7 , 7 ,
8 , 8 , 9 , 10 , 10 , 11 , 11 , 12 , 13 , 13 , 14 , 14 , 0
} ;
static const unsigned int V_5 [ 31 ] = {
0 , 1 , 1 , 1 , 2 , 2 , 3 , 3 , 4 , 4 , 5 , 5 , 6 , 6 , 7 , 7 ,
8 , 8 , 9 , 9 , 10 , 10 , 11 , 11 , 12 , 12 , 13 , 13 , 14 , 0 , 0
} ;
unsigned int V_6 ;
if ( V_1 & V_7 ) {
if ( V_2 >= F_2 ( V_5 ) )
V_2 = 30 ;
V_6 = V_5 [ V_2 ] ;
} else {
if ( V_2 >= F_2 ( V_4 ) )
V_2 = 25 ;
V_6 = V_4 [ V_2 ] ;
}
return V_3 [ V_6 ] ;
}
static void F_3 ( struct V_8 * V_9 ,
unsigned int V_2 )
{
unsigned int V_3 ;
if ( V_9 -> V_2 == V_2 )
return;
V_3 = F_1 ( V_9 -> V_10 , V_2 ) << 1 ;
V_3 |= V_3 << 1 ;
if ( V_3 > 0 )
V_3 |= F_4 ( 31 ) ;
F_5 ( V_9 -> V_11 , V_12 [ V_9 -> V_13 ] , V_3 ) ;
V_9 -> V_2 = V_2 ;
}
static const struct V_14 * F_6 ( unsigned int V_15 )
{
unsigned int V_16 ;
for ( V_16 = 0 ; V_16 < F_2 ( V_17 ) ; V_16 ++ )
if ( V_17 [ V_16 ] . V_15 == V_15 )
return & V_17 [ V_16 ] ;
return NULL ;
}
static int F_7 ( struct V_18 * V_19 ,
unsigned int * V_20 , unsigned int * V_21 ,
unsigned int V_22 [] , void * V_23 [] )
{
struct V_8 * V_9 = F_8 ( V_19 ) ;
unsigned int V_24 =
( V_9 -> V_25 * V_9 -> V_26 * V_9 -> V_27 -> V_28 ) >> 3 ;
if ( V_19 -> V_29 + * V_20 < 3 )
* V_20 = 3 - V_19 -> V_29 ;
if ( * V_21 ) {
if ( * V_21 != 1 || V_22 [ 0 ] < V_24 )
return - V_30 ;
return 0 ;
}
V_22 [ 0 ] = V_24 ;
* V_21 = 1 ;
return 0 ;
}
static void F_9 ( struct V_31 * V_32 )
{
struct V_8 * V_9 = F_8 ( V_32 -> V_18 ) ;
struct V_33 * V_11 = V_9 -> V_11 ;
struct V_34 * V_34 ;
unsigned long V_35 ;
struct V_36 * V_37 = F_10 ( V_32 ) ;
struct V_38 * V_39 =
F_11 ( V_37 , struct V_38 , V_32 ) ;
F_12 ( & V_11 -> V_40 , V_35 ) ;
V_34 = V_11 -> V_34 ;
F_13 ( & V_11 -> V_40 , V_35 ) ;
if ( ! V_34 ) {
F_14 ( & V_39 -> V_32 . V_41 , V_42 ) ;
return;
}
F_12 ( & V_9 -> V_43 , V_35 ) ;
F_15 ( & V_39 -> V_44 , & V_9 -> V_45 ) ;
F_13 ( & V_9 -> V_43 , V_35 ) ;
}
static void F_16 ( struct V_8 * V_9 , unsigned int V_46 )
{
struct V_47 * V_48 = & V_9 -> V_49 [ V_46 ] ;
struct V_33 * V_11 = V_9 -> V_11 ;
struct V_34 * V_34 ;
unsigned long V_35 ;
F_12 ( & V_11 -> V_40 , V_35 ) ;
V_34 = V_11 -> V_34 ;
F_13 ( & V_11 -> V_40 , V_35 ) ;
if ( ! V_34 ) {
F_17 ( 1 , L_1 ) ;
return;
}
if ( V_48 -> V_50 ) {
F_18 ( V_11 -> V_34 , V_48 -> V_51 ,
V_48 -> V_50 , V_48 -> V_52 ) ;
V_48 -> V_50 = NULL ;
}
}
static int F_19 ( struct V_8 * V_9 , unsigned int V_46 )
{
struct V_33 * V_11 = V_9 -> V_11 ;
T_2 V_53 = V_46 ? V_54 [ V_9 -> V_13 ] : V_55 [ V_9 -> V_13 ] ;
unsigned int V_56 ;
void * V_50 ;
F_17 ( V_9 -> V_49 [ V_46 ] . V_50 ,
L_2 ) ;
V_56 = ( V_9 -> V_25 * V_9 -> V_26 * V_9 -> V_27 -> V_28 ) >> 3 ;
V_50 = F_20 ( V_11 -> V_34 , V_56 ,
& V_9 -> V_49 [ V_46 ] . V_52 ) ;
if ( ! V_50 ) {
F_21 ( & V_11 -> V_57 ,
L_3 ,
V_9 -> V_13 , V_46 ? L_4 : L_5 ) ;
return - V_58 ;
}
V_9 -> V_49 [ V_46 ] . V_51 = V_56 ;
V_9 -> V_49 [ V_46 ] . V_50 = V_50 ;
F_5 ( V_11 , V_53 , V_9 -> V_49 [ V_46 ] . V_52 ) ;
return 0 ;
}
static void F_22 ( struct V_8 * V_9 ,
unsigned int V_46 )
{
struct V_38 * V_39 ;
while ( ! F_23 ( & V_9 -> V_45 ) ) {
V_39 = F_24 ( & V_9 -> V_45 ,
struct V_38 , V_44 ) ;
F_25 ( & V_39 -> V_44 ) ;
V_9 -> V_59 [ V_46 ] = V_39 ;
return;
}
V_9 -> V_59 [ V_46 ] = NULL ;
}
static void F_26 ( struct V_8 * V_9 ,
enum V_60 V_61 )
{
unsigned int V_46 ;
while ( ! F_23 ( & V_9 -> V_45 ) ) {
struct V_38 * V_39 ;
V_39 = F_24 ( & V_9 -> V_45 ,
struct V_38 , V_44 ) ;
F_25 ( & V_39 -> V_44 ) ;
F_14 ( & V_39 -> V_32 . V_41 , V_61 ) ;
}
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ ) {
if ( V_9 -> V_59 [ V_46 ] )
F_14 ( & V_9 -> V_59 [ V_46 ] -> V_32 . V_41 , V_61 ) ;
V_9 -> V_59 [ V_46 ] = NULL ;
}
}
static int F_27 ( struct V_18 * V_19 , unsigned int V_62 )
{
struct V_8 * V_9 = F_8 ( V_19 ) ;
struct V_33 * V_11 = V_9 -> V_11 ;
struct V_34 * V_34 ;
unsigned long V_35 ;
int V_46 , V_63 ;
F_12 ( & V_11 -> V_40 , V_35 ) ;
V_34 = V_11 -> V_34 ;
F_13 ( & V_11 -> V_40 , V_35 ) ;
if ( ! V_34 ) {
V_63 = - V_64 ;
goto V_65;
}
F_12 ( & V_9 -> V_43 , V_35 ) ;
if ( ! V_9 -> V_49 [ 0 ] . V_50 || ! V_9 -> V_49 [ 1 ] . V_50 ) {
F_13 ( & V_9 -> V_43 , V_35 ) ;
F_21 ( & V_11 -> V_57 ,
L_6 ,
V_9 -> V_66 ) ;
V_63 = - V_58 ;
goto V_65;
}
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ )
F_22 ( V_9 , V_46 ) ;
F_13 ( & V_9 -> V_43 , V_35 ) ;
V_9 -> V_67 = 0 ;
V_9 -> V_46 = 0 ;
F_12 ( & V_11 -> V_40 , V_35 ) ;
F_28 ( V_11 , V_9 -> V_13 ) ;
F_13 ( & V_11 -> V_40 , V_35 ) ;
F_29 ( & V_11 -> V_68 , V_69 + F_30 ( 100 ) ) ;
return 0 ;
V_65:
F_12 ( & V_9 -> V_43 , V_35 ) ;
F_26 ( V_9 , V_70 ) ;
F_13 ( & V_9 -> V_43 , V_35 ) ;
return V_63 ;
}
static void F_31 ( struct V_18 * V_19 )
{
struct V_8 * V_9 = F_8 ( V_19 ) ;
struct V_33 * V_11 = V_9 -> V_11 ;
struct V_34 * V_34 ;
unsigned long V_35 ;
F_12 ( & V_11 -> V_40 , V_35 ) ;
V_34 = V_11 -> V_34 ;
F_13 ( & V_11 -> V_40 , V_35 ) ;
if ( V_34 )
F_32 ( V_11 , V_9 -> V_13 ) ;
F_12 ( & V_9 -> V_43 , V_35 ) ;
F_26 ( V_9 , V_42 ) ;
F_13 ( & V_9 -> V_43 , V_35 ) ;
}
static int F_33 ( struct V_31 * V_32 )
{
struct V_8 * V_9 = F_8 ( V_32 -> V_18 ) ;
unsigned int V_51 =
( V_9 -> V_25 * V_9 -> V_26 * V_9 -> V_27 -> V_28 ) >> 3 ;
if ( F_34 ( V_32 , 0 ) < V_51 )
return - V_30 ;
F_35 ( V_32 , 0 , V_51 ) ;
return 0 ;
}
static int F_36 ( struct V_71 * V_72 )
{
struct V_8 * V_9 ;
struct V_33 * V_11 ;
unsigned int V_13 ;
V_9 = F_11 ( V_72 -> V_73 , struct V_8 ,
V_74 ) ;
V_11 = V_9 -> V_11 ;
V_13 = V_9 -> V_13 ;
switch ( V_72 -> V_75 ) {
case V_76 :
F_5 ( V_11 , V_77 [ V_13 ] , V_72 -> V_78 & 0xff ) ;
return 0 ;
case V_79 :
F_5 ( V_11 , V_80 [ V_13 ] , V_72 -> V_78 ) ;
return 0 ;
case V_81 :
F_5 ( V_11 , V_82 [ V_13 ] , V_72 -> V_78 ) ;
F_5 ( V_11 , V_83 [ V_13 ] , V_72 -> V_78 ) ;
return 0 ;
case V_84 :
F_5 ( V_11 , V_85 [ V_13 ] , V_72 -> V_78 & 0xff ) ;
return 0 ;
}
return - V_30 ;
}
static int F_37 ( struct V_86 * V_86 , void * V_87 ,
struct V_88 * V_89 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
V_89 -> V_90 . V_91 . V_25 = V_9 -> V_25 ;
V_89 -> V_90 . V_91 . V_26 = V_9 -> V_26 ;
V_89 -> V_90 . V_91 . V_92 = V_93 ;
V_89 -> V_90 . V_91 . V_94 = V_9 -> V_27 -> V_15 ;
V_89 -> V_90 . V_91 . V_95 = V_96 ;
V_89 -> V_90 . V_91 . V_97 = ( V_89 -> V_90 . V_91 . V_25 * V_9 -> V_27 -> V_28 ) / 8 ;
V_89 -> V_90 . V_91 . V_98 = V_89 -> V_90 . V_91 . V_26 * V_89 -> V_90 . V_91 . V_97 ;
return 0 ;
}
static int F_39 ( struct V_86 * V_86 , void * V_87 ,
struct V_88 * V_89 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
unsigned int V_99 = F_40 ( V_9 -> V_10 ) ;
const struct V_14 * V_27 ;
V_27 = F_6 ( V_89 -> V_90 . V_91 . V_94 ) ;
if ( ! V_27 ) {
V_27 = & V_17 [ 0 ] ;
V_89 -> V_90 . V_91 . V_94 = V_27 -> V_15 ;
}
if ( V_89 -> V_90 . V_91 . V_25 <= V_100 / 2 )
V_89 -> V_90 . V_91 . V_25 = V_100 / 2 ;
else
V_89 -> V_90 . V_91 . V_25 = V_100 ;
if ( V_89 -> V_90 . V_91 . V_26 <= V_99 / 2 )
V_89 -> V_90 . V_91 . V_26 = V_99 / 2 ;
else
V_89 -> V_90 . V_91 . V_26 = V_99 ;
V_89 -> V_90 . V_91 . V_97 = ( V_89 -> V_90 . V_91 . V_25 * V_27 -> V_28 ) / 8 ;
V_89 -> V_90 . V_91 . V_98 = V_89 -> V_90 . V_91 . V_26 * V_89 -> V_90 . V_91 . V_97 ;
V_89 -> V_90 . V_91 . V_95 = V_96 ;
V_89 -> V_90 . V_91 . V_92 = V_93 ;
return 0 ;
}
static int F_41 ( struct V_86 * V_86 , void * V_87 ,
struct V_88 * V_89 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
T_2 V_78 , V_25 , V_101 , V_26 ;
unsigned long V_102 ;
int V_63 , V_46 ;
if ( F_42 ( & V_9 -> V_103 ) )
return - V_104 ;
V_102 = V_9 -> V_25 * V_9 -> V_26 * V_9 -> V_27 -> V_28 ;
V_63 = F_39 ( V_86 , V_87 , V_89 ) ;
if ( V_63 )
return V_63 ;
V_9 -> V_27 = F_6 ( V_89 -> V_90 . V_91 . V_94 ) ;
V_9 -> V_25 = V_89 -> V_90 . V_91 . V_25 ;
V_9 -> V_26 = V_89 -> V_90 . V_91 . V_26 ;
if ( V_102 != V_9 -> V_25 * V_9 -> V_26 * V_9 -> V_27 -> V_28 ) {
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ )
F_16 ( V_9 , V_46 ) ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ ) {
V_63 = F_19 ( V_9 , V_46 ) ;
if ( V_63 ) {
if ( V_46 > 0 )
F_16 ( V_9 , 0 ) ;
return V_63 ;
}
}
}
V_78 = F_43 ( V_9 -> V_11 , V_105 [ V_9 -> V_13 ] ) ;
if ( V_9 -> V_25 <= V_100 / 2 )
V_78 |= F_4 ( 23 ) ;
else
V_78 &= ~ F_4 ( 23 ) ;
if ( V_9 -> V_26 <= F_40 ( V_9 -> V_10 ) / 2 )
V_78 |= F_4 ( 24 ) ;
else
V_78 &= ~ F_4 ( 24 ) ;
V_78 &= ~ ( 0x7 << 20 ) ;
V_78 |= V_9 -> V_27 -> V_106 << 20 ;
F_5 ( V_9 -> V_11 , V_105 [ V_9 -> V_13 ] , V_78 ) ;
V_25 = ( V_9 -> V_25 * 2 ) & 0x7ff ;
V_26 = V_9 -> V_26 / 2 ;
V_101 = ( V_9 -> V_25 * 2 ) & 0x7ff ;
V_78 = ( V_26 << 22 ) | ( V_101 << 11 ) | V_25 ;
F_5 ( V_9 -> V_11 , V_107 [ V_9 -> V_13 ] , V_78 ) ;
return 0 ;
}
static int F_44 ( struct V_86 * V_86 , void * V_87 ,
struct V_108 * V_109 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
struct V_33 * V_11 = V_9 -> V_11 ;
F_45 ( V_109 -> V_110 , L_7 , sizeof( V_109 -> V_110 ) ) ;
F_45 ( V_109 -> V_111 , V_11 -> V_112 , sizeof( V_109 -> V_111 ) ) ;
snprintf ( V_109 -> V_113 , sizeof( V_109 -> V_113 ) ,
L_8 , F_46 ( V_11 -> V_34 ) ) ;
V_109 -> V_114 = V_115 | V_116 |
V_117 ;
V_109 -> V_118 = V_109 -> V_114 | V_119 ;
return 0 ;
}
static int F_47 ( struct V_86 * V_86 , void * V_87 , T_1 V_75 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
struct V_88 V_89 ;
T_2 V_78 , V_120 ;
if ( V_9 -> V_10 == V_75 )
return 0 ;
if ( F_42 ( & V_9 -> V_103 ) )
return - V_104 ;
if ( V_75 & V_121 )
V_78 = 0 ;
else if ( V_75 & V_122 )
V_78 = 1 ;
else if ( V_75 & V_123 )
V_78 = 2 ;
else if ( V_75 & V_124 )
V_78 = 3 ;
else if ( V_75 & V_125 )
V_78 = 4 ;
else if ( V_75 & V_126 )
V_78 = 5 ;
else if ( V_75 & V_127 )
V_78 = 6 ;
else
return - V_30 ;
V_9 -> V_10 = V_75 ;
F_5 ( V_9 -> V_11 , V_128 [ V_9 -> V_13 ] , V_78 ) ;
V_78 = F_43 ( V_9 -> V_11 , V_129 ) ;
if ( V_75 & V_7 )
V_78 &= ~ ( 1 << ( V_130 + V_9 -> V_13 ) ) ;
else
V_78 |= ( 1 << ( V_130 + V_9 -> V_13 ) ) ;
F_5 ( V_9 -> V_11 , V_129 , V_78 ) ;
V_120 = F_37 ( V_86 , V_87 , & V_89 ) ;
if ( ! V_120 )
F_41 ( V_86 , V_87 , & V_89 ) ;
return 0 ;
}
static int F_48 ( struct V_86 * V_86 , void * V_87 , T_1 * V_1 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
struct V_33 * V_11 = V_9 -> V_11 ;
unsigned int V_131 , V_132 = 0 ;
unsigned long V_133 ;
if ( F_49 ( & V_9 -> V_103 ) )
return - V_104 ;
V_131 = F_43 ( V_11 , V_128 [ V_9 -> V_13 ] ) ;
F_5 ( V_11 , V_128 [ V_9 -> V_13 ] , 0x7 ) ;
F_5 ( V_11 , V_134 [ V_9 -> V_13 ] , 0xff ) ;
V_133 = V_69 + F_30 ( 500 ) ;
while ( F_50 ( V_133 ) ) {
V_132 = F_43 ( V_11 , V_128 [ V_9 -> V_13 ] ) ;
if ( ! ( V_132 & F_4 ( 7 ) ) )
break;
F_51 ( 100 ) ;
}
F_5 ( V_11 , V_128 [ V_9 -> V_13 ] , V_131 ) ;
if ( V_132 & F_4 ( 7 ) )
return 0 ;
V_132 = ( V_132 >> 4 ) & 0x7 ;
switch ( V_132 ) {
case V_135 :
* V_1 &= V_121 ;
break;
case V_136 :
* V_1 &= V_124 ;
break;
case V_137 :
* V_1 &= V_125 ;
break;
case V_138 :
* V_1 &= V_127 ;
break;
case V_139 :
* V_1 &= V_122 ;
break;
case V_140 :
* V_1 &= V_126 ;
break;
case V_141 :
* V_1 &= V_123 ;
break;
default:
* V_1 = 0 ;
}
return 0 ;
}
static int F_52 ( struct V_86 * V_86 , void * V_87 , T_1 * V_75 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
* V_75 = V_9 -> V_10 ;
return 0 ;
}
static int F_53 ( struct V_86 * V_86 , void * V_87 ,
struct V_142 * V_89 )
{
if ( V_89 -> V_143 >= F_2 ( V_17 ) )
return - V_30 ;
V_89 -> V_94 = V_17 [ V_89 -> V_143 ] . V_15 ;
return 0 ;
}
static int F_54 ( struct V_86 * V_86 , void * V_87 , unsigned int V_6 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
T_2 V_78 ;
if ( V_6 >= V_144 )
return - V_30 ;
if ( V_6 == V_9 -> V_145 )
return 0 ;
if ( F_42 ( & V_9 -> V_103 ) )
return - V_104 ;
V_9 -> V_145 = V_6 ;
V_78 = F_43 ( V_9 -> V_11 , V_105 [ V_9 -> V_13 ] ) ;
V_78 &= ~ ( 0x3 << 30 ) ;
V_78 |= V_6 << 30 ;
F_5 ( V_9 -> V_11 , V_105 [ V_9 -> V_13 ] , V_78 ) ;
return 0 ;
}
static int F_55 ( struct V_86 * V_86 , void * V_87 , unsigned int * V_6 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
* V_6 = V_9 -> V_145 ;
return 0 ;
}
static int F_56 ( struct V_86 * V_86 , void * V_87 ,
struct V_146 * V_6 )
{
struct V_8 * V_9 = F_38 ( V_86 ) ;
unsigned int V_147 ;
if ( V_6 -> V_143 >= V_144 )
return - V_30 ;
snprintf ( V_6 -> V_112 , sizeof( V_6 -> V_112 ) , L_9 , V_6 -> V_143 ) ;
V_6 -> type = V_148 ;
V_6 -> V_1 = V_9 -> V_149 -> V_150 ;
V_6 -> V_118 = V_151 ;
V_147 = F_43 ( V_9 -> V_11 , V_152 [ V_9 -> V_13 ] ) ;
V_6 -> V_153 = 0 ;
if ( V_147 & V_154 )
V_6 -> V_153 |= V_155 ;
if ( ! ( V_147 & V_156 ) )
V_6 -> V_153 |= V_157 ;
return 0 ;
}
static void F_57 ( struct V_8 * V_9 ,
unsigned int V_46 , struct V_36 * V_32 )
{
struct V_47 * V_48 = & V_9 -> V_49 [ V_46 ] ;
struct V_31 * V_41 = & V_32 -> V_41 ;
V_32 -> V_92 = V_93 ;
V_32 -> V_67 = V_9 -> V_67 ++ ;
memcpy ( F_58 ( V_41 , 0 ) , V_48 -> V_50 , V_48 -> V_51 ) ;
V_41 -> V_158 = F_59 () ;
F_14 ( V_41 , V_159 ) ;
}
void F_60 ( struct V_33 * V_11 , unsigned long V_160 ,
unsigned int V_161 , unsigned int V_162 ,
unsigned int * V_163 )
{
struct V_8 * V_9 ;
struct V_36 * V_32 ;
unsigned long V_35 ;
unsigned int V_13 , V_46 ;
F_61 (ch, &requests, max_channels(dev)) {
V_9 = & V_11 -> V_164 [ V_13 ] ;
if ( V_9 -> V_165 && ! ( V_162 & F_4 ( V_13 ) ) ) {
F_62 ( V_166 , & V_11 -> V_57 ,
L_10 , V_9 -> V_66 ) ;
V_9 -> V_165 = false ;
* V_163 |= F_4 ( V_13 ) ;
V_9 -> V_46 = 0 ;
continue;
}
V_9 -> V_165 = ! ! ( V_162 & F_4 ( V_13 ) ) ;
if ( ! V_9 -> V_165 ) {
T_2 V_167 , V_168 ;
V_167 = ( V_162 >> 24 ) & F_4 ( V_13 ) ;
V_168 = ( V_162 >> 16 ) & F_4 ( V_13 ) ;
if ( V_167 || V_168 ) {
F_62 ( V_166 , & V_11 -> V_57 ,
L_11 , V_9 -> V_66 ) ;
* V_163 |= F_4 ( V_13 ) ;
V_9 -> V_46 = 0 ;
continue;
}
}
V_46 = ! ! ( V_161 & F_4 ( V_13 ) ) ;
if ( V_9 -> V_46 != V_46 ) {
F_62 ( V_166 , & V_11 -> V_57 ,
L_12 ,
V_9 -> V_66 ) ;
* V_163 |= F_4 ( V_13 ) ;
V_9 -> V_46 = 0 ;
continue;
}
F_12 ( & V_9 -> V_43 , V_35 ) ;
if ( V_9 -> V_59 [ V_46 ] ) {
V_32 = & V_9 -> V_59 [ V_46 ] -> V_32 ;
F_57 ( V_9 , V_46 , V_32 ) ;
}
V_9 -> V_46 = ! V_46 ;
F_22 ( V_9 , V_46 ) ;
F_13 ( & V_9 -> V_43 , V_35 ) ;
}
}
void F_63 ( struct V_33 * V_11 )
{
unsigned int V_13 , V_46 ;
for ( V_13 = 0 ; V_13 < F_64 ( V_11 ) ; V_13 ++ ) {
struct V_8 * V_9 = & V_11 -> V_164 [ V_13 ] ;
if ( V_9 -> V_149 )
F_65 ( V_9 -> V_149 ) ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ )
F_16 ( V_9 , V_46 ) ;
}
}
int F_66 ( struct V_33 * V_11 )
{
unsigned int V_13 , V_78 , V_46 ;
int V_63 ;
V_63 = F_67 ( & V_11 -> V_34 -> V_11 , & V_11 -> V_57 ) ;
if ( V_63 )
return V_63 ;
for ( V_13 = 0 ; V_13 < F_64 ( V_11 ) ; V_13 ++ ) {
struct V_8 * V_9 = & V_11 -> V_164 [ V_13 ] ;
struct V_169 * V_170 ;
F_68 ( & V_9 -> V_171 ) ;
F_69 ( & V_9 -> V_43 ) ;
F_70 ( & V_9 -> V_45 ) ;
V_9 -> V_11 = V_11 ;
V_9 -> V_13 = V_13 ;
V_9 -> V_27 = & V_17 [ 0 ] ;
V_9 -> V_10 = V_121 ;
V_9 -> V_25 = V_100 ;
V_9 -> V_26 = F_40 ( V_9 -> V_10 ) ;
V_9 -> V_145 = 0 ;
F_5 ( V_9 -> V_11 , V_128 [ V_13 ] , 0 ) ;
F_3 ( V_9 , 30 ) ;
F_5 ( V_11 , V_172 [ V_13 ] , 0x14 ) ;
F_5 ( V_11 , V_173 [ V_13 ] , 0xd0 ) ;
F_5 ( V_11 , V_174 [ V_13 ] , 0 ) ;
for ( V_46 = 0 ; V_46 < 2 ; V_46 ++ ) {
V_63 = F_19 ( V_9 , V_46 ) ;
if ( V_63 )
goto error;
}
V_9 -> V_103 . V_175 = V_176 | V_177 | V_178 ;
V_9 -> V_103 . type = V_179 ;
V_9 -> V_103 . V_180 = V_9 ;
V_9 -> V_103 . V_181 = sizeof( struct V_38 ) ;
V_9 -> V_103 . V_182 = & V_183 ;
V_9 -> V_103 . V_184 = & V_185 ;
V_9 -> V_103 . V_186 = V_187 ;
V_9 -> V_103 . V_188 = 2 ;
V_9 -> V_103 . V_40 = & V_9 -> V_171 ;
V_9 -> V_103 . V_189 = V_190 ;
V_63 = F_71 ( & V_9 -> V_103 ) ;
if ( V_63 ) {
F_21 ( & V_11 -> V_57 ,
L_13 , V_13 ) ;
goto error;
}
V_63 = F_72 ( & V_9 -> V_74 , 4 ) ;
if ( V_63 ) {
F_21 ( & V_11 -> V_57 ,
L_14 , V_13 ) ;
goto error;
}
F_73 ( & V_9 -> V_74 , & V_191 ,
V_76 , - 128 , 127 , 1 , 0 ) ;
F_73 ( & V_9 -> V_74 , & V_191 ,
V_79 , 0 , 255 , 1 , 100 ) ;
F_73 ( & V_9 -> V_74 , & V_191 ,
V_81 , 0 , 255 , 1 , 128 ) ;
F_73 ( & V_9 -> V_74 , & V_191 ,
V_84 , - 128 , 127 , 1 , 0 ) ;
V_63 = V_9 -> V_74 . error ;
if ( V_63 )
goto error;
V_63 = F_74 ( & V_9 -> V_74 ) ;
if ( V_63 )
goto error;
V_170 = F_75 () ;
if ( ! V_170 ) {
F_21 ( & V_11 -> V_57 ,
L_15 , V_13 ) ;
V_63 = - V_58 ;
goto error;
}
snprintf ( V_170 -> V_112 , sizeof( V_170 -> V_112 ) , L_16 , V_11 -> V_112 ) ;
V_170 -> V_192 = & V_193 ;
V_170 -> V_194 = & V_195 ;
V_170 -> V_196 = V_197 ;
V_170 -> V_57 = & V_11 -> V_57 ;
V_170 -> V_198 = & V_9 -> V_103 ;
V_170 -> V_150 = V_7 | V_199 ;
V_170 -> V_200 = - 1 ;
V_170 -> V_40 = & V_9 -> V_171 ;
V_170 -> V_74 = & V_9 -> V_74 ;
V_9 -> V_149 = V_170 ;
F_76 ( V_170 , V_9 ) ;
V_63 = F_77 ( V_170 , V_201 , - 1 ) ;
if ( V_63 < 0 )
goto error;
V_9 -> V_66 = V_170 -> V_66 ;
}
V_78 = V_202 ;
for ( V_13 = 0 ; V_13 < F_64 ( V_11 ) ; V_13 ++ )
V_78 |= V_203 << ( 16 + V_13 * 2 ) ;
F_5 ( V_11 , V_204 , V_78 ) ;
F_5 ( V_11 , V_205 [ 0 ] , 0xe7 ) ;
F_5 ( V_11 , V_206 [ 0 ] , 0xcc ) ;
F_5 ( V_11 , V_207 [ 0 ] , 0xa5 ) ;
if ( F_64 ( V_11 ) > 4 ) {
F_5 ( V_11 , V_206 [ 1 ] , 0xcc ) ;
F_5 ( V_11 , V_207 [ 1 ] , 0xa5 ) ;
F_5 ( V_11 , V_205 [ 1 ] , 0xe7 ) ;
}
return 0 ;
error:
F_63 ( V_11 ) ;
return V_63 ;
}
