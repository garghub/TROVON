static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
struct V_6 * V_7 = V_2 ;
const struct V_8 * V_9 = F_2 ( V_7 ) ;
struct V_10 * V_11 = V_7 -> V_12 + 0 ;
if ( ! V_7 -> V_13 ) {
F_3 ( V_7 , L_1 ) ;
return V_14 ;
}
V_4 = F_4 ( V_7 -> V_15 + V_16 ) ;
V_3 = F_4 ( V_7 -> V_15 + V_17 ) ;
F_5 ( 0 , V_7 -> V_15 + V_18 ) ;
V_5 = ( V_4 << 8 ) | V_3 ;
if ( ! ( -- V_19 -> V_20 ) ) {
if ( V_9 -> V_21 )
F_5 ( 1 , V_7 -> V_15 + V_22 ) ;
else
F_5 ( 0 , V_7 -> V_15 + V_22 ) ;
V_11 -> V_23 -> V_24 |= V_25 ;
}
F_6 ( V_7 , V_11 ) ;
return V_14 ;
}
static void F_7 ( struct V_6 * V_7 , int V_26 )
{
const struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_27 ;
F_5 ( F_8 ( V_26 ) , V_7 -> V_15 + V_28 ) ;
V_27 = F_9 ( V_26 ) ;
if ( V_9 -> V_21 ) {
if ( V_27 >= 8 )
V_27 = 0x20 | ( V_27 & 0x7 ) ;
else
V_27 |= 0x10 ;
} else {
F_5 ( V_27 , V_7 -> V_15 + V_29 ) ;
}
}
static int F_10 ( struct V_6 * V_7 , struct V_10 * V_11 ,
struct V_30 * V_31 , unsigned int * V_5 )
{
const struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_32 , V_33 ;
int V_4 , V_3 ;
F_7 ( V_7 , V_31 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_33 ; V_33 ++ ) {
F_5 ( 1 , V_7 -> V_15 + V_22 ) ;
if ( ! V_9 -> V_21 )
F_5 ( 0 , V_7 -> V_15 + V_35 ) ;
V_32 = V_36 ;
while ( -- V_32 ) {
V_4 = F_4 ( V_7 -> V_15 + V_16 ) ;
if ( ! ( V_4 & V_37 ) )
goto V_38;
F_11 ( 1 ) ;
}
F_12 ( V_39 L_2 , V_7 -> V_40 ) ;
return - V_41 ;
V_38:
V_3 = F_4 ( V_7 -> V_15 + V_17 ) ;
V_5 [ V_33 ] = ( ( V_4 & 0xf ) << 8 ) | V_3 ;
}
return V_33 ;
}
static int F_13 ( struct V_6 * V_7 ,
struct V_10 * V_11 , struct V_42 * V_43 )
{
int V_44 ;
int V_45 = 0 ;
V_44 = V_43 -> V_46 ;
V_43 -> V_46 &= V_47 ;
if ( ! V_43 -> V_46 || V_44 != V_43 -> V_46 )
V_45 ++ ;
V_44 = V_43 -> V_48 ;
V_43 -> V_48 &= V_49 | V_50 ;
if ( ! V_43 -> V_48 || V_44 != V_43 -> V_48 )
V_45 ++ ;
V_44 = V_43 -> V_51 ;
V_43 -> V_51 &= V_47 ;
if ( ! V_43 -> V_51 || V_44 != V_43 -> V_51 )
V_45 ++ ;
V_44 = V_43 -> V_52 ;
V_43 -> V_52 &= V_53 ;
if ( ! V_43 -> V_52 || V_44 != V_43 -> V_52 )
V_45 ++ ;
V_44 = V_43 -> V_54 ;
V_43 -> V_54 &= V_53 | V_55 ;
if ( ! V_43 -> V_54 || V_44 != V_43 -> V_54 )
V_45 ++ ;
if ( V_45 )
return 1 ;
if ( V_43 -> V_48 != V_49 &&
V_43 -> V_48 != V_50 )
V_45 ++ ;
if ( V_43 -> V_54 != V_53 && V_43 -> V_54 != V_55 )
V_45 ++ ;
if ( V_45 )
return 2 ;
if ( V_43 -> V_56 != 0 ) {
V_43 -> V_56 = 0 ;
V_45 ++ ;
}
if ( V_43 -> V_48 == V_50 ) {
if ( V_43 -> V_57 != 0 ) {
V_43 -> V_57 = 0 ;
V_45 ++ ;
}
} else {
#define F_14 1000
#define F_15 100
if ( V_43 -> V_57 < F_14 ) {
V_43 -> V_57 = F_14 ;
V_45 ++ ;
}
}
if ( V_43 -> V_58 != 0 ) {
V_43 -> V_58 = 0 ;
V_45 ++ ;
}
if ( V_43 -> V_59 != V_43 -> V_60 ) {
V_43 -> V_59 = V_43 -> V_60 ;
V_45 ++ ;
}
if ( V_43 -> V_54 == V_55 ) {
if ( V_43 -> V_61 != 0 ) {
V_43 -> V_61 = 0 ;
V_45 ++ ;
}
} else {
}
if ( V_45 )
return 3 ;
if ( V_43 -> V_48 == V_49 ) {
V_44 = V_43 -> V_57 ;
F_16 ( F_15 ,
& V_19 -> V_62 ,
& V_19 -> V_63 ,
& V_43 -> V_57 ,
V_43 -> V_64 & V_65 ) ;
if ( V_44 != V_43 -> V_57 )
V_45 ++ ;
}
if ( V_45 )
return 4 ;
return 0 ;
}
static int F_17 ( struct V_6 * V_7 , struct V_10 * V_11 )
{
int V_66 , V_67 ;
struct V_42 * V_43 = & V_11 -> V_23 -> V_43 ;
F_7 ( V_7 , V_43 -> V_68 [ 0 ] ) ;
if ( V_43 -> V_48 == V_49 ) {
V_66 = V_67 = 0 ;
F_18 ( V_69 , & V_66 , & V_67 ,
& V_43 -> V_57 ,
V_70 ) ;
F_5 ( 0x74 , V_7 -> V_15 + V_71 ) ;
F_5 ( V_66 & 0xff , V_7 -> V_15 + V_72 ) ;
F_5 ( ( V_66 >> 8 ) & 0xff , V_7 -> V_15 + V_72 ) ;
F_5 ( 0xb4 , V_7 -> V_15 + V_71 ) ;
F_5 ( V_67 & 0xff , V_7 -> V_15 + V_73 ) ;
F_5 ( ( V_67 >> 8 ) & 0xff , V_7 -> V_15 + V_73 ) ;
F_5 ( 0 , V_7 -> V_15 + V_18 ) ;
F_5 ( V_19 -> V_74 | 6 , V_7 -> V_15 + V_22 ) ;
} else {
F_5 ( V_19 -> V_74 | 3 , V_7 -> V_15 + V_22 ) ;
}
return 0 ;
}
static int F_19 ( struct V_6 * V_7 , struct V_10 * V_11 ,
struct V_30 * V_31 , unsigned int * V_5 )
{
int V_33 ;
int V_26 = F_9 ( V_31 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_33 ; V_33 ++ ) {
F_5 ( ( V_5 [ V_33 ] & 0xff ) ,
V_7 -> V_15 + ( V_26 ? V_75 : V_76 ) ) ;
F_5 ( ( V_5 [ V_33 ] >> 8 ) ,
V_7 -> V_15 + ( V_26 ? V_77 : V_78 ) ) ;
V_19 -> V_79 [ V_26 ] = V_5 [ V_33 ] ;
}
return V_33 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_10 * V_11 ,
struct V_30 * V_31 , unsigned int * V_5 )
{
int V_33 ;
int V_26 = F_9 ( V_31 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_33 ; V_33 ++ )
V_5 [ V_33 ] = V_19 -> V_79 [ V_26 ] ;
return V_33 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_10 * V_11 ,
struct V_30 * V_31 , unsigned int * V_5 )
{
V_5 [ 1 ] = F_4 ( V_7 -> V_15 + V_80 ) |
( F_4 ( V_7 -> V_15 + V_81 ) << 8 ) ;
return V_31 -> V_33 ;
}
static int F_22 ( struct V_6 * V_7 ,
struct V_10 * V_11 ,
struct V_30 * V_31 , unsigned int * V_5 )
{
if ( V_5 [ 0 ] ) {
V_11 -> V_82 &= ~ V_5 [ 0 ] ;
V_11 -> V_82 |= V_5 [ 0 ] & V_5 [ 1 ] ;
}
if ( V_5 [ 0 ] & 0x00ff )
F_5 ( V_11 -> V_82 & 0xff , V_7 -> V_15 + V_83 ) ;
if ( V_5 [ 0 ] & 0xff00 )
F_5 ( ( V_11 -> V_82 >> 8 ) , V_7 -> V_15 + V_84 ) ;
V_5 [ 1 ] = V_11 -> V_82 ;
return V_31 -> V_33 ;
}
static int F_23 ( struct V_6 * V_7 , struct V_85 * V_86 )
{
const struct V_8 * V_9 = F_2 ( V_7 ) ;
int V_87 ;
unsigned long V_15 ;
unsigned int V_1 ;
struct V_10 * V_11 ;
V_15 = V_86 -> V_88 [ 0 ] ;
F_12 ( V_89 L_3 , V_7 -> V_40 , V_15 ) ;
if ( ! F_24 ( V_15 , V_90 , L_4 ) ) {
F_12 ( L_5 ) ;
return - V_91 ;
}
V_7 -> V_15 = V_15 ;
V_7 -> V_92 = V_9 -> V_93 ;
V_1 = V_86 -> V_88 [ 1 ] ;
if ( V_1 > V_9 -> V_94 ) {
F_12 ( V_39 L_6 ) ;
return - V_95 ;
}
if ( V_1 ) {
if ( F_25 ( V_1 , F_1 , 0 , L_4 , V_7 ) ) {
F_12 ( V_39 L_7 , V_1 ) ;
return - V_95 ;
} else {
F_12 ( V_89 L_8 , V_1 ) ;
}
}
V_7 -> V_1 = V_1 ;
V_87 = F_26 ( V_7 , 4 ) ;
if ( V_87 )
return V_87 ;
V_87 = F_27 ( V_7 , sizeof( struct V_96 ) ) ;
if ( V_87 < 0 )
return V_87 ;
V_11 = V_7 -> V_12 + 0 ;
V_11 -> type = V_97 ;
V_11 -> V_98 = V_99 | V_100 ;
V_11 -> V_101 = V_9 -> V_102 ;
V_11 -> V_103 = 0xfff ;
V_11 -> V_104 = 1 ;
V_11 -> V_105 = V_9 -> V_106 ;
V_11 -> V_107 = F_10 ;
if ( V_1 ) {
V_7 -> V_108 = V_11 ;
V_11 -> V_98 |= V_109 ;
V_11 -> V_110 = F_13 ;
V_11 -> V_111 = F_17 ;
}
V_11 ++ ;
V_11 -> type = V_112 ;
V_11 -> V_98 = V_113 ;
V_11 -> V_101 = V_9 -> V_114 ;
V_11 -> V_103 = 0xfff ;
V_11 -> V_104 = 1 ;
V_11 -> V_105 = & V_115 ;
V_11 -> V_116 = F_19 ;
V_11 -> V_107 = F_20 ;
V_11 ++ ;
V_11 -> type = V_117 ;
V_11 -> V_98 = V_99 ;
V_11 -> V_101 = 16 ;
V_11 -> V_103 = 1 ;
V_11 -> V_104 = 16 ;
V_11 -> V_105 = & V_118 ;
V_11 -> V_119 = F_21 ;
V_11 ++ ;
V_11 -> type = V_120 ;
V_11 -> V_98 = V_113 ;
V_11 -> V_101 = 16 ;
V_11 -> V_103 = 1 ;
V_11 -> V_104 = 16 ;
V_11 -> V_105 = & V_118 ;
V_11 -> V_82 = 0 ;
V_11 -> V_119 = F_22 ;
if ( V_9 -> V_121 )
V_19 -> V_74 = ( V_7 -> V_1 << 4 ) ;
F_5 ( 0 , V_7 -> V_15 + V_76 ) ;
F_5 ( 0 , V_7 -> V_15 + V_78 ) ;
F_5 ( 0 , V_7 -> V_15 + V_75 ) ;
F_5 ( 0 , V_7 -> V_15 + V_77 ) ;
F_12 ( V_89 L_9 ) ;
return 0 ;
}
static void F_28 ( struct V_6 * V_7 )
{
if ( V_7 -> V_1 )
F_29 ( V_7 -> V_1 , V_7 ) ;
if ( V_7 -> V_15 )
F_30 ( V_7 -> V_15 , V_90 ) ;
}
