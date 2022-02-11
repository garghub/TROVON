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
int V_19 = 10000 ;
int V_20 ;
if ( ! V_2 -> V_21 )
return V_22 ;
switch ( V_6 -> V_13 ) {
case V_14 :
F_4 ( & V_6 -> V_23 ) ;
break;
case V_24 :
while ( ! ( ( V_20 = F_5 ( V_2 -> V_11 + V_25 ) )
& V_26 ) ) {
unsigned short V_27 ;
if ( V_20 & V_28 ) {
V_4 -> V_29 -> V_30 |=
V_31 | V_32 ;
F_6 ( V_2 -> V_33 , L_1 ) ;
break;
}
V_27 = F_5 ( V_2 -> V_11 + V_34 ) ;
V_27 |= F_5 ( V_2 -> V_11 + V_34 ) << 8 ;
V_27 ^= 0x8000 ;
F_7 ( V_4 , V_27 ) ;
if ( V_6 -> V_35 > 0 ) {
V_6 -> V_35 -- ;
if ( V_6 -> V_35 == 0 ) {
V_4 -> V_29 -> V_30 |= V_31 ;
break;
}
}
if ( ( V_19 -- ) <= 0 )
break;
}
if ( V_19 <= 0 ) {
F_6 ( V_2 -> V_33 ,
L_2 ) ;
V_4 -> V_29 -> V_30 |= V_31 | V_36 ;
}
V_4 -> V_29 -> V_30 |= V_37 ;
F_8 ( V_2 , V_4 ) ;
}
return V_38 ;
}
static void F_9 ( struct V_1 * V_2 ,
unsigned int V_39 ,
int V_40 )
{
unsigned int V_41 = F_10 ( V_39 ) ;
unsigned int V_42 = F_11 ( V_39 ) ;
unsigned int V_43 = F_12 ( V_39 ) ;
unsigned int V_44 ;
V_44 = F_13 ( V_41 ) | F_14 ( V_42 ) ;
if ( V_43 == V_45 )
V_44 |= V_46 ;
if ( V_40 )
V_44 |= V_47 ;
F_2 ( V_44 & 0xff , V_2 -> V_11 + V_48 ) ;
F_2 ( ( V_44 >> 8 ) & 0xff , V_2 -> V_11 + V_48 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 , unsigned int * V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_51 ;
int V_52 ;
int V_53 = 10000 ;
if ( V_6 -> V_8 )
return - V_9 ;
F_1 ( V_2 , V_4 ) ;
F_2 ( 0 , V_2 -> V_11 + V_54 ) ;
F_2 ( V_55 , V_2 -> V_11 + V_12 ) ;
F_9 ( V_2 , V_50 -> V_39 , 1 ) ;
F_2 ( V_56 , V_2 -> V_11 + V_12 ) ;
V_52 = V_57 | V_58
| V_59 | V_60 ;
F_2 ( V_52 , V_2 -> V_11 + V_61 ) ;
while ( -- V_53
&& ( F_5 ( V_2 -> V_11 + V_25 ) & V_62 ) )
;
if ( ! V_53 ) {
F_16 ( V_2 -> V_33 ,
L_3 ) ;
return - 1 ;
}
F_17 ( & V_6 -> V_23 ) ;
V_6 -> V_13 = V_14 ;
for ( V_51 = 0 ; V_51 < V_50 -> V_63 ; V_51 ++ ) {
F_2 ( V_64 | V_65 ,
V_2 -> V_11 + V_12 ) ;
if ( F_18 ( & V_6 -> V_23 ) )
return - V_66 ;
V_27 [ V_51 ] = F_5 ( V_2 -> V_11 + V_34 ) ;
V_27 [ V_51 ] |= F_5 ( V_2 -> V_11 + V_34 ) << 8 ;
V_27 [ V_51 ] ^= 0x8000 ;
}
return V_50 -> V_63 ;
}
static int F_19 ( unsigned int * V_67 , int V_68 )
{
int V_69 ;
V_69 = * V_67 / 200 ;
* V_67 = V_69 * 200 ;
return V_69 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_3 * V_4 , struct V_70 * V_71 )
{
int V_72 = 0 ;
unsigned int V_73 ;
V_72 |= F_21 ( & V_71 -> V_74 , V_75 ) ;
V_72 |= F_21 ( & V_71 -> V_76 ,
V_77 | V_78 ) ;
V_72 |= F_21 ( & V_71 -> V_79 ,
V_77 | V_75 ) ;
V_72 |= F_21 ( & V_71 -> V_80 , V_81 ) ;
V_72 |= F_21 ( & V_71 -> V_82 , V_81 | V_83 ) ;
if ( V_72 )
return 1 ;
V_72 |= F_22 ( V_71 -> V_76 ) ;
V_72 |= F_22 ( V_71 -> V_79 ) ;
V_72 |= F_22 ( V_71 -> V_82 ) ;
if ( V_72 )
return 2 ;
V_72 |= F_23 ( & V_71 -> V_84 , 0 ) ;
#define F_24 10000
if ( V_71 -> V_76 == V_77 )
V_72 |= F_25 ( & V_71 -> V_85 ,
F_24 ) ;
if ( V_71 -> V_76 == V_77 && V_71 -> V_79 == V_77
&& V_71 -> V_85 != V_71 -> V_86 * V_71 -> V_87 ) {
V_72 |= - V_88 ;
}
if ( V_71 -> V_79 == V_77 )
V_72 |= F_25 ( & V_71 -> V_86 , F_24 ) ;
V_72 |= F_23 ( & V_71 -> V_87 , V_71 -> V_89 ) ;
if ( V_71 -> V_82 == V_81 )
V_72 |= F_26 ( & V_71 -> V_90 , 0x00ffffff ) ;
else
V_72 |= F_23 ( & V_71 -> V_90 , 0 ) ;
if ( V_72 )
return 3 ;
if ( V_71 -> V_76 == V_77 ) {
V_73 = V_71 -> V_85 ;
F_19 ( & V_73 , V_71 -> V_91 & V_92 ) ;
V_72 |= F_23 ( & V_71 -> V_85 , V_73 ) ;
}
if ( V_71 -> V_79 == V_77 ) {
V_73 = V_71 -> V_86 ;
F_19 ( & V_73 , V_71 -> V_91 & V_92 ) ;
V_72 |= F_23 ( & V_71 -> V_86 , V_73 ) ;
}
if ( V_72 )
return 4 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_70 * V_71 = & V_4 -> V_29 -> V_71 ;
int V_53 ;
int V_93 ;
int V_94 ;
int V_51 ;
int V_52 ;
if ( V_6 -> V_8 )
return - V_9 ;
F_1 ( V_2 , V_4 ) ;
F_2 ( 0 , V_2 -> V_11 + V_54 ) ;
F_2 ( V_55 , V_2 -> V_11 + V_12 ) ;
if ( V_71 -> V_79 == V_77 ) {
V_53 = F_19 ( & V_71 -> V_86 ,
V_71 -> V_91 & V_92 ) ;
F_2 ( V_53 & 0xff , V_2 -> V_11 + V_95 ) ;
F_2 ( ( V_53 >> 8 ) & 0xff , V_2 -> V_11 + V_96 ) ;
F_2 ( ( V_53 >> 16 ) & 0xff , V_2 -> V_11 + V_97 ) ;
V_93 = 1 ;
} else {
V_53 = F_19 ( & V_71 -> V_85 ,
V_71 -> V_91 & V_92 ) ;
F_2 ( V_53 & 0xff , V_2 -> V_11 + V_95 ) ;
F_2 ( ( V_53 >> 8 ) & 0xff , V_2 -> V_11 + V_96 ) ;
F_2 ( ( V_53 >> 16 ) & 0xff , V_2 -> V_11 + V_97 ) ;
V_93 = 0 ;
}
for ( V_51 = 0 ; V_51 < V_71 -> V_89 ; V_51 ++ ) {
int V_40 = ( V_51 == 0 || V_93 ) ;
F_9 ( V_2 , V_71 -> V_98 [ V_51 ] , V_40 ) ;
}
if ( V_71 -> V_82 == V_81 ) {
V_6 -> V_35 = V_71 -> V_90 * V_71 -> V_87 ;
V_94 = 2 * V_6 -> V_35 ;
while ( V_94 > V_99 * 3 / 4 )
V_94 /= 2 ;
} else {
V_6 -> V_35 = - 1 ;
V_94 = V_99 / 2 ;
}
F_2 ( V_56 , V_2 -> V_11 + V_12 ) ;
F_2 ( 0x00 , V_2 -> V_11 + V_34 ) ;
F_2 ( 0x00 , V_2 -> V_11 + V_34 ) ;
F_2 ( ( V_99 - V_94 ) & 0xff , V_2 -> V_11 + V_34 ) ;
F_2 ( ( V_99 - V_94 ) >> 8 , V_2 -> V_11 + V_34 ) ;
V_52 = V_100 | V_58
| V_101 | V_102 ;
F_2 ( V_52 , V_2 -> V_11 + V_61 ) ;
V_53 = 100 ;
while ( -- V_53
&& ( F_5 ( V_2 -> V_11 + V_25 ) & V_62 ) )
;
if ( ! V_53 ) {
F_16 ( V_2 -> V_33 ,
L_3 ) ;
return - 1 ;
}
V_6 -> V_13 = V_24 ;
F_2 ( V_64 | V_65 ,
V_2 -> V_11 + V_12 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 ,
unsigned int * V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_41 = F_10 ( V_50 -> V_39 ) ;
unsigned int V_44 ;
int V_51 ;
if ( V_6 -> V_8 )
return - V_9 ;
F_2 ( 0 , V_2 -> V_11 + V_54 ) ;
for ( V_51 = 0 ; V_51 > V_50 -> V_63 ; V_51 ++ ) {
V_44 = V_27 [ 0 ] ;
V_44 &= 0x0fff ;
V_44 ^= 0x0800 ;
V_44 |= ( V_41 << 12 ) ;
F_29 ( V_44 , V_2 -> V_11 + V_103 ) ;
}
return V_50 -> V_63 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 ,
unsigned int * V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 )
return - V_9 ;
V_27 [ 0 ] = F_5 ( V_2 -> V_11 + V_104 ) ;
return V_50 -> V_63 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_49 * V_50 ,
unsigned int * V_27 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_6 -> V_8 )
return - V_9 ;
if ( F_32 ( V_4 , V_27 ) )
F_2 ( V_4 -> V_105 , V_2 -> V_11 + V_104 ) ;
V_27 [ 1 ] = V_4 -> V_105 ;
return V_50 -> V_63 ;
}
static int F_33 ( struct V_1 * V_2 ,
unsigned long V_106 )
{
struct V_107 * V_108 = F_34 ( V_2 ) ;
struct V_5 * V_6 ;
struct V_3 * V_4 ;
int V_109 ;
V_6 = F_35 ( V_2 , sizeof( * V_6 ) ) ;
if ( ! V_6 )
return - V_110 ;
V_108 -> V_111 |= V_112 | V_113 ;
V_109 = F_36 ( V_2 , NULL ) ;
if ( V_109 )
return V_109 ;
V_2 -> V_11 = V_108 -> V_114 [ 0 ] -> V_40 ;
V_108 -> V_115 = V_2 ;
V_109 = F_37 ( V_108 , F_3 ) ;
if ( V_109 )
return V_109 ;
V_109 = F_38 ( V_2 , 4 ) ;
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
V_4 -> V_135 = F_28 ;
V_4 = & V_2 -> V_116 [ 2 ] ;
V_4 -> type = V_136 ;
V_4 -> V_118 = V_119 ;
V_4 -> V_123 = 1 ;
V_4 -> V_125 = 1 ;
V_4 -> V_137 = F_30 ;
V_4 = & V_2 -> V_116 [ 3 ] ;
V_4 -> type = V_138 ;
V_4 -> V_118 = V_133 ;
V_4 -> V_123 = 1 ;
V_4 -> V_125 = 1 ;
V_4 -> V_137 = F_31 ;
return 0 ;
}
static int F_39 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = V_108 -> V_115 ;
struct V_5 * V_6 = V_2 ? V_2 -> V_7 : NULL ;
if ( V_6 )
V_6 -> V_8 = 1 ;
return 0 ;
}
static int F_40 ( struct V_107 * V_108 )
{
struct V_1 * V_2 = V_108 -> V_115 ;
struct V_5 * V_6 = V_2 ? V_2 -> V_7 : NULL ;
if ( V_6 )
V_6 -> V_8 = 0 ;
return 0 ;
}
static int F_41 ( struct V_107 * V_108 )
{
return F_42 ( V_108 , & V_139 ) ;
}
