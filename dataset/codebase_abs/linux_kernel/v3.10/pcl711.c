static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
struct V_6 * V_7 = V_2 ;
const struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_12 ;
struct V_13 * V_14 = & V_7 -> V_15 [ 0 ] ;
if ( ! V_7 -> V_16 ) {
F_3 ( V_7 , L_1 ) ;
return V_17 ;
}
V_4 = F_4 ( V_7 -> V_18 + V_19 ) ;
V_3 = F_4 ( V_7 -> V_18 + V_20 ) ;
F_5 ( 0 , V_7 -> V_18 + V_21 ) ;
V_5 = ( V_4 << 8 ) | V_3 ;
if ( ! ( -- V_11 -> V_22 ) ) {
if ( V_9 -> V_23 )
F_5 ( 1 , V_7 -> V_18 + V_24 ) ;
else
F_5 ( 0 , V_7 -> V_18 + V_24 ) ;
V_14 -> V_25 -> V_26 |= V_27 ;
}
F_6 ( V_7 , V_14 ) ;
return V_17 ;
}
static void F_7 ( struct V_6 * V_7 , int V_28 )
{
const struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_29 ;
F_5 ( F_8 ( V_28 ) , V_7 -> V_18 + V_30 ) ;
V_29 = F_9 ( V_28 ) ;
if ( V_9 -> V_23 ) {
if ( V_29 >= 8 )
V_29 = 0x20 | ( V_29 & 0x7 ) ;
else
V_29 |= 0x10 ;
} else {
F_5 ( V_29 , V_7 -> V_18 + V_31 ) ;
}
}
static int F_10 ( struct V_6 * V_7 , struct V_13 * V_14 ,
struct V_32 * V_33 , unsigned int * V_5 )
{
const struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_34 , V_35 ;
int V_4 , V_3 ;
F_7 ( V_7 , V_33 -> V_36 ) ;
for ( V_35 = 0 ; V_35 < V_33 -> V_35 ; V_35 ++ ) {
F_5 ( 1 , V_7 -> V_18 + V_24 ) ;
if ( ! V_9 -> V_23 )
F_5 ( 0 , V_7 -> V_18 + V_37 ) ;
V_34 = V_38 ;
while ( -- V_34 ) {
V_4 = F_4 ( V_7 -> V_18 + V_19 ) ;
if ( ! ( V_4 & V_39 ) )
goto V_40;
F_11 ( 1 ) ;
}
F_12 ( V_41 L_2 , V_7 -> V_42 ) ;
return - V_43 ;
V_40:
V_3 = F_4 ( V_7 -> V_18 + V_20 ) ;
V_5 [ V_35 ] = ( ( V_4 & 0xf ) << 8 ) | V_3 ;
}
return V_35 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_13 * V_14 , struct V_44 * V_45 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
int V_46 ;
int V_47 = 0 ;
V_47 |= F_14 ( & V_45 -> V_48 , V_49 ) ;
V_47 |= F_14 ( & V_45 -> V_50 ,
V_51 | V_52 ) ;
V_47 |= F_14 ( & V_45 -> V_53 , V_49 ) ;
V_47 |= F_14 ( & V_45 -> V_54 , V_55 ) ;
V_47 |= F_14 ( & V_45 -> V_56 , V_55 | V_57 ) ;
if ( V_47 )
return 1 ;
V_47 |= F_15 ( V_45 -> V_50 ) ;
V_47 |= F_15 ( V_45 -> V_56 ) ;
if ( V_47 )
return 2 ;
V_47 |= F_16 ( & V_45 -> V_58 , 0 ) ;
if ( V_45 -> V_50 == V_52 ) {
V_47 |= F_16 ( & V_45 -> V_59 , 0 ) ;
} else {
#define F_17 1000
#define F_18 100
V_47 |= F_19 ( & V_45 -> V_59 ,
F_17 ) ;
}
V_47 |= F_16 ( & V_45 -> V_60 , 0 ) ;
V_47 |= F_16 ( & V_45 -> V_61 , V_45 -> V_62 ) ;
if ( V_45 -> V_56 == V_57 ) {
V_47 |= F_16 ( & V_45 -> V_63 , 0 ) ;
} else {
}
if ( V_47 )
return 3 ;
if ( V_45 -> V_50 == V_51 ) {
V_46 = V_45 -> V_59 ;
F_20 ( F_18 ,
& V_11 -> V_64 ,
& V_11 -> V_65 ,
& V_45 -> V_59 ,
V_45 -> V_66 & V_67 ) ;
if ( V_46 != V_45 -> V_59 )
V_47 ++ ;
}
if ( V_47 )
return 4 ;
return 0 ;
}
static int F_21 ( struct V_6 * V_7 , struct V_13 * V_14 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
int V_68 , V_69 ;
struct V_44 * V_45 = & V_14 -> V_25 -> V_45 ;
F_7 ( V_7 , V_45 -> V_70 [ 0 ] ) ;
if ( V_45 -> V_50 == V_51 ) {
V_68 = V_69 = 0 ;
F_22 ( V_71 , & V_68 , & V_69 ,
& V_45 -> V_59 ,
V_72 ) ;
F_5 ( 0x74 , V_7 -> V_18 + V_73 ) ;
F_5 ( V_68 & 0xff , V_7 -> V_18 + V_74 ) ;
F_5 ( ( V_68 >> 8 ) & 0xff , V_7 -> V_18 + V_74 ) ;
F_5 ( 0xb4 , V_7 -> V_18 + V_73 ) ;
F_5 ( V_69 & 0xff , V_7 -> V_18 + V_75 ) ;
F_5 ( ( V_69 >> 8 ) & 0xff , V_7 -> V_18 + V_75 ) ;
F_5 ( 0 , V_7 -> V_18 + V_21 ) ;
F_5 ( V_11 -> V_76 | 6 , V_7 -> V_18 + V_24 ) ;
} else {
F_5 ( V_11 -> V_76 | 3 , V_7 -> V_18 + V_24 ) ;
}
return 0 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_13 * V_14 ,
struct V_32 * V_33 , unsigned int * V_5 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
int V_35 ;
int V_28 = F_9 ( V_33 -> V_36 ) ;
for ( V_35 = 0 ; V_35 < V_33 -> V_35 ; V_35 ++ ) {
F_5 ( ( V_5 [ V_35 ] & 0xff ) ,
V_7 -> V_18 + ( V_28 ? V_77 : V_78 ) ) ;
F_5 ( ( V_5 [ V_35 ] >> 8 ) ,
V_7 -> V_18 + ( V_28 ? V_79 : V_80 ) ) ;
V_11 -> V_81 [ V_28 ] = V_5 [ V_35 ] ;
}
return V_35 ;
}
static int F_24 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
struct V_32 * V_33 , unsigned int * V_5 )
{
struct V_10 * V_11 = V_7 -> V_12 ;
int V_35 ;
int V_28 = F_9 ( V_33 -> V_36 ) ;
for ( V_35 = 0 ; V_35 < V_33 -> V_35 ; V_35 ++ )
V_5 [ V_35 ] = V_11 -> V_81 [ V_28 ] ;
return V_35 ;
}
static int F_25 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
struct V_32 * V_33 , unsigned int * V_5 )
{
V_5 [ 1 ] = F_4 ( V_7 -> V_18 + V_82 ) |
( F_4 ( V_7 -> V_18 + V_83 ) << 8 ) ;
return V_33 -> V_35 ;
}
static int F_26 ( struct V_6 * V_7 ,
struct V_13 * V_14 ,
struct V_32 * V_33 , unsigned int * V_5 )
{
if ( V_5 [ 0 ] ) {
V_14 -> V_84 &= ~ V_5 [ 0 ] ;
V_14 -> V_84 |= V_5 [ 0 ] & V_5 [ 1 ] ;
}
if ( V_5 [ 0 ] & 0x00ff )
F_5 ( V_14 -> V_84 & 0xff , V_7 -> V_18 + V_85 ) ;
if ( V_5 [ 0 ] & 0xff00 )
F_5 ( ( V_14 -> V_84 >> 8 ) , V_7 -> V_18 + V_86 ) ;
V_5 [ 1 ] = V_14 -> V_84 ;
return V_33 -> V_35 ;
}
static int F_27 ( struct V_6 * V_7 , struct V_87 * V_88 )
{
const struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 ;
int V_89 ;
unsigned int V_1 ;
struct V_13 * V_14 ;
V_89 = F_28 ( V_7 , V_88 -> V_90 [ 0 ] , V_91 ) ;
if ( V_89 )
return V_89 ;
V_1 = V_88 -> V_90 [ 1 ] ;
if ( V_1 > V_9 -> V_92 ) {
F_12 ( V_41 L_3 ) ;
return - V_93 ;
}
if ( V_1 ) {
if ( F_29 ( V_1 , F_1 , 0 , V_7 -> V_94 ,
V_7 ) ) {
F_12 ( V_41 L_4 , V_1 ) ;
return - V_93 ;
} else {
F_12 ( V_95 L_5 , V_1 ) ;
}
}
V_7 -> V_1 = V_1 ;
V_89 = F_30 ( V_7 , 4 ) ;
if ( V_89 )
return V_89 ;
V_11 = F_31 ( sizeof( * V_11 ) , V_96 ) ;
if ( ! V_11 )
return - V_97 ;
V_7 -> V_12 = V_11 ;
V_14 = & V_7 -> V_15 [ 0 ] ;
V_14 -> type = V_98 ;
V_14 -> V_99 = V_100 | V_101 ;
V_14 -> V_102 = V_9 -> V_103 ;
V_14 -> V_104 = 0xfff ;
V_14 -> V_105 = 1 ;
V_14 -> V_106 = V_9 -> V_107 ;
V_14 -> V_108 = F_10 ;
if ( V_1 ) {
V_7 -> V_109 = V_14 ;
V_14 -> V_99 |= V_110 ;
V_14 -> V_111 = F_13 ;
V_14 -> V_112 = F_21 ;
}
V_14 = & V_7 -> V_15 [ 1 ] ;
V_14 -> type = V_113 ;
V_14 -> V_99 = V_114 ;
V_14 -> V_102 = V_9 -> V_115 ;
V_14 -> V_104 = 0xfff ;
V_14 -> V_105 = 1 ;
V_14 -> V_106 = & V_116 ;
V_14 -> V_117 = F_23 ;
V_14 -> V_108 = F_24 ;
V_14 = & V_7 -> V_15 [ 2 ] ;
V_14 -> type = V_118 ;
V_14 -> V_99 = V_100 ;
V_14 -> V_102 = 16 ;
V_14 -> V_104 = 1 ;
V_14 -> V_105 = 16 ;
V_14 -> V_106 = & V_119 ;
V_14 -> V_120 = F_25 ;
V_14 = & V_7 -> V_15 [ 3 ] ;
V_14 -> type = V_121 ;
V_14 -> V_99 = V_114 ;
V_14 -> V_102 = 16 ;
V_14 -> V_104 = 1 ;
V_14 -> V_105 = 16 ;
V_14 -> V_106 = & V_119 ;
V_14 -> V_84 = 0 ;
V_14 -> V_120 = F_26 ;
if ( V_9 -> V_122 )
V_11 -> V_76 = ( V_7 -> V_1 << 4 ) ;
F_5 ( 0 , V_7 -> V_18 + V_78 ) ;
F_5 ( 0 , V_7 -> V_18 + V_80 ) ;
F_5 ( 0 , V_7 -> V_18 + V_77 ) ;
F_5 ( 0 , V_7 -> V_18 + V_79 ) ;
F_12 ( V_95 L_6 ) ;
return 0 ;
}
