static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 )
return - V_9 ;
F_2 ( V_10 , V_2 -> V_11 + V_12 ) ;
V_6 -> V_13 = V_14 ;
return 0 ;
}
static enum V_15 F_3 ( int V_16 , void * V_17 )
{
struct V_1 * V_2 = V_17 ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 = V_2 -> V_18 ;
struct V_19 * V_20 = & V_4 -> V_21 -> V_20 ;
int V_22 = 10000 ;
int V_23 ;
if ( ! V_2 -> V_24 )
return V_25 ;
switch ( V_6 -> V_13 ) {
case V_14 :
F_4 ( & V_6 -> V_26 ) ;
break;
case V_27 :
while ( ! ( ( V_23 = F_5 ( V_2 -> V_11 + V_28 ) )
& V_29 ) ) {
unsigned short V_30 ;
if ( V_23 & V_31 ) {
V_4 -> V_21 -> V_32 |=
V_33 | V_34 ;
F_6 ( V_2 -> V_35 , L_1 ) ;
break;
}
V_30 = F_5 ( V_2 -> V_11 + V_36 ) ;
V_30 |= F_5 ( V_2 -> V_11 + V_36 ) << 8 ;
V_30 ^= 0x8000 ;
F_7 ( V_4 , & V_30 , 1 ) ;
if ( V_20 -> V_37 == V_38 &&
V_4 -> V_21 -> V_39 >= V_20 -> V_40 ) {
V_4 -> V_21 -> V_32 |= V_33 ;
break;
}
if ( ( V_22 -- ) <= 0 )
break;
}
if ( V_22 <= 0 ) {
F_6 ( V_2 -> V_35 ,
L_2 ) ;
V_4 -> V_21 -> V_32 |= V_33 | V_41 ;
}
F_8 ( V_2 , V_4 ) ;
}
return V_42 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_43 ,
int V_44 )
{
unsigned int V_45 = F_10 ( V_43 ) ;
unsigned int V_46 = F_11 ( V_43 ) ;
unsigned int V_47 = F_12 ( V_43 ) ;
unsigned int V_48 ;
V_48 = F_13 ( V_45 ) | F_14 ( V_46 ) ;
if ( V_47 == V_49 )
V_48 |= V_50 ;
if ( V_44 )
V_48 |= V_51 ;
F_2 ( V_48 & 0xff , V_2 -> V_11 + V_52 ) ;
F_2 ( ( V_48 >> 8 ) & 0xff , V_2 -> V_11 + V_52 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_53 * V_54 , unsigned int * V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_55 ;
int V_56 ;
int V_57 = 10000 ;
if ( V_6 -> V_8 )
return - V_9 ;
F_1 ( V_2 , V_4 ) ;
F_2 ( 0 , V_2 -> V_11 + V_58 ) ;
F_2 ( V_59 , V_2 -> V_11 + V_12 ) ;
F_9 ( V_2 , V_54 -> V_43 , 1 ) ;
F_2 ( V_60 , V_2 -> V_11 + V_12 ) ;
V_56 = V_61 | V_62
| V_63 | V_64 ;
F_2 ( V_56 , V_2 -> V_11 + V_65 ) ;
while ( -- V_57
&& ( F_5 ( V_2 -> V_11 + V_28 ) & V_66 ) )
;
if ( ! V_57 ) {
F_16 ( V_2 -> V_35 ,
L_3 ) ;
return - 1 ;
}
F_17 ( & V_6 -> V_26 ) ;
V_6 -> V_13 = V_14 ;
for ( V_55 = 0 ; V_55 < V_54 -> V_67 ; V_55 ++ ) {
F_2 ( V_68 | V_69 ,
V_2 -> V_11 + V_12 ) ;
if ( F_18 ( & V_6 -> V_26 ) )
return - V_70 ;
V_30 [ V_55 ] = F_5 ( V_2 -> V_11 + V_36 ) ;
V_30 [ V_55 ] |= F_5 ( V_2 -> V_11 + V_36 ) << 8 ;
V_30 [ V_55 ] ^= 0x8000 ;
}
return V_54 -> V_67 ;
}
static int F_19 ( unsigned int * V_71 , unsigned int V_72 )
{
int V_73 ;
V_73 = * V_71 / 200 ;
* V_71 = V_73 * 200 ;
return V_73 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_19 * V_20 )
{
int V_74 = 0 ;
unsigned int V_75 ;
V_74 |= F_21 ( & V_20 -> V_76 , V_77 ) ;
V_74 |= F_21 ( & V_20 -> V_78 ,
V_79 | V_80 ) ;
V_74 |= F_21 ( & V_20 -> V_81 ,
V_79 | V_77 ) ;
V_74 |= F_21 ( & V_20 -> V_82 , V_38 ) ;
V_74 |= F_21 ( & V_20 -> V_37 , V_38 | V_83 ) ;
if ( V_74 )
return 1 ;
V_74 |= F_22 ( V_20 -> V_78 ) ;
V_74 |= F_22 ( V_20 -> V_81 ) ;
V_74 |= F_22 ( V_20 -> V_37 ) ;
if ( V_74 )
return 2 ;
V_74 |= F_23 ( & V_20 -> V_84 , 0 ) ;
#define F_24 10000
if ( V_20 -> V_78 == V_79 )
V_74 |= F_25 ( & V_20 -> V_85 ,
F_24 ) ;
if ( V_20 -> V_78 == V_79 && V_20 -> V_81 == V_79
&& V_20 -> V_85 != V_20 -> V_86 * V_20 -> V_87 ) {
V_74 |= - V_88 ;
}
if ( V_20 -> V_81 == V_79 )
V_74 |= F_25 ( & V_20 -> V_86 , F_24 ) ;
V_74 |= F_23 ( & V_20 -> V_87 , V_20 -> V_89 ) ;
if ( V_20 -> V_37 == V_38 )
V_74 |= F_26 ( & V_20 -> V_40 , 0x00ffffff ) ;
else
V_74 |= F_23 ( & V_20 -> V_40 , 0 ) ;
if ( V_74 )
return 3 ;
if ( V_20 -> V_78 == V_79 ) {
V_75 = V_20 -> V_85 ;
F_19 ( & V_75 , V_20 -> V_72 ) ;
V_74 |= F_23 ( & V_20 -> V_85 , V_75 ) ;
}
if ( V_20 -> V_81 == V_79 ) {
V_75 = V_20 -> V_86 ;
F_19 ( & V_75 , V_20 -> V_72 ) ;
V_74 |= F_23 ( & V_20 -> V_86 , V_75 ) ;
}
if ( V_74 )
return 4 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_19 * V_20 = & V_4 -> V_21 -> V_20 ;
int V_57 ;
int V_90 ;
int V_91 ;
int V_55 ;
int V_56 ;
if ( V_6 -> V_8 )
return - V_9 ;
F_1 ( V_2 , V_4 ) ;
F_2 ( 0 , V_2 -> V_11 + V_58 ) ;
F_2 ( V_59 , V_2 -> V_11 + V_12 ) ;
if ( V_20 -> V_81 == V_79 ) {
V_57 = F_19 ( & V_20 -> V_86 , V_20 -> V_72 ) ;
F_2 ( V_57 & 0xff , V_2 -> V_11 + V_92 ) ;
F_2 ( ( V_57 >> 8 ) & 0xff , V_2 -> V_11 + V_93 ) ;
F_2 ( ( V_57 >> 16 ) & 0xff , V_2 -> V_11 + V_94 ) ;
V_90 = 1 ;
} else {
V_57 = F_19 ( & V_20 -> V_85 , V_20 -> V_72 ) ;
F_2 ( V_57 & 0xff , V_2 -> V_11 + V_92 ) ;
F_2 ( ( V_57 >> 8 ) & 0xff , V_2 -> V_11 + V_93 ) ;
F_2 ( ( V_57 >> 16 ) & 0xff , V_2 -> V_11 + V_94 ) ;
V_90 = 0 ;
}
for ( V_55 = 0 ; V_55 < V_20 -> V_89 ; V_55 ++ ) {
int V_44 = ( V_55 == 0 || V_90 ) ;
F_9 ( V_2 , V_20 -> V_95 [ V_55 ] , V_44 ) ;
}
if ( V_20 -> V_37 == V_38 ) {
unsigned long long V_96 ;
unsigned long long V_97 ;
V_96 = ( unsigned long long ) V_20 -> V_40 *
V_20 -> V_87 ;
V_97 = V_96 * F_28 ( V_4 ) ;
while ( V_97 > V_98 * 3 / 4 )
V_97 /= 2 ;
V_91 = V_97 ;
} else {
V_91 = V_98 / 2 ;
}
F_2 ( V_60 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0x00 , V_2 -> V_11 + V_36 ) ;
F_2 ( 0x00 , V_2 -> V_11 + V_36 ) ;
F_2 ( ( V_98 - V_91 ) & 0xff , V_2 -> V_11 + V_36 ) ;
F_2 ( ( V_98 - V_91 ) >> 8 , V_2 -> V_11 + V_36 ) ;
V_56 = V_99 | V_62
| V_100 | V_101 ;
F_2 ( V_56 , V_2 -> V_11 + V_65 ) ;
V_57 = 100 ;
while ( -- V_57
&& ( F_5 ( V_2 -> V_11 + V_28 ) & V_66 ) )
;
if ( ! V_57 ) {
F_16 ( V_2 -> V_35 ,
L_3 ) ;
return - 1 ;
}
V_6 -> V_13 = V_27 ;
F_2 ( V_68 | V_69 ,
V_2 -> V_11 + V_12 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_53 * V_54 ,
unsigned int * V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_45 = F_10 ( V_54 -> V_43 ) ;
int V_55 ;
if ( V_6 -> V_8 )
return - V_9 ;
F_2 ( 0 , V_2 -> V_11 + V_58 ) ;
for ( V_55 = 0 ; V_55 > V_54 -> V_67 ; V_55 ++ ) {
unsigned V_48 = V_30 [ V_55 ] ;
V_4 -> V_102 [ V_45 ] = V_48 ;
V_48 &= 0x0fff ;
V_48 ^= 0x0800 ;
V_48 |= ( V_45 << 12 ) ;
F_30 ( V_48 , V_2 -> V_11 + V_103 ) ;
}
return V_54 -> V_67 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_53 * V_54 ,
unsigned int * V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 )
return - V_9 ;
V_30 [ 0 ] = F_5 ( V_2 -> V_11 + V_104 ) ;
return V_54 -> V_67 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_53 * V_54 ,
unsigned int * V_30 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 )
return - V_9 ;
if ( F_33 ( V_4 , V_30 ) )
F_2 ( V_4 -> V_105 , V_2 -> V_11 + V_104 ) ;
V_30 [ 1 ] = V_4 -> V_105 ;
return V_54 -> V_67 ;
}
static int F_34 ( struct V_1 * V_2 ,
unsigned long V_106 )
{
struct V_107 * V_108 = F_35 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_109 ;
V_6 = F_36 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_110 ;
V_108 -> V_111 |= V_112 | V_113 ;
V_109 = F_37 ( V_2 , NULL ) ;
if ( V_109 )
return V_109 ;
V_2 -> V_11 = V_108 -> V_114 [ 0 ] -> V_44 ;
V_108 -> V_115 = V_2 ;
V_109 = F_38 ( V_108 , F_3 ) ;
if ( V_109 )
return V_109 ;
V_109 = F_39 ( V_2 , 4 ) ;
if ( V_109 )
return V_109 ;
V_4 = & V_2 -> V_116 [ 0 ] ;
V_2 -> V_18 = V_4 ;
V_4 -> type = V_117 ;
V_4 -> V_118 = V_119 | V_120 | V_121 | V_122 ;
V_4 -> V_123 = 8 ;
V_4 -> V_124 = 2048 ;
V_4 -> V_125 = 0xffff ;
V_4 -> V_126 = & V_127 ;
V_4 -> V_128 = F_15 ;
V_4 -> V_129 = F_20 ;
V_4 -> V_130 = F_27 ;
V_4 -> V_131 = F_1 ;
V_4 = & V_2 -> V_116 [ 1 ] ;
V_4 -> type = V_132 ;
V_4 -> V_118 = V_133 ;
V_4 -> V_123 = 2 ;
V_4 -> V_125 = 0x0fff ;
V_4 -> V_126 = & V_134 ;
V_4 -> V_135 = F_29 ;
V_109 = F_40 ( V_4 ) ;
if ( V_109 )
return V_109 ;
V_4 = & V_2 -> V_116 [ 2 ] ;
V_4 -> type = V_136 ;
V_4 -> V_118 = V_119 ;
V_4 -> V_123 = 1 ;
V_4 -> V_125 = 1 ;
V_4 -> V_137 = F_31 ;
V_4 = & V_2 -> V_116 [ 3 ] ;
V_4 -> type = V_138 ;
V_4 -> V_118 = V_133 ;
V_4 -> V_123 = 1 ;
V_4 -> V_125 = 1 ;
V_4 -> V_137 = F_32 ;
return 0 ;
}
static int F_41 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = V_108 -> V_115 ;
struct V_5 * V_6 = V_2 ? V_2 -> V_7 : NULL ;
if ( V_6 )
V_6 -> V_8 = 1 ;
return 0 ;
}
static int F_42 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = V_108 -> V_115 ;
struct V_5 * V_6 = V_2 ? V_2 -> V_7 : NULL ;
if ( V_6 )
V_6 -> V_8 = 0 ;
return 0 ;
}
static int F_43 ( struct V_107 * V_108 )
{
return F_44 ( V_108 , & V_139 ) ;
}
