static int T_1 F_1 ( void )
{
return F_2 ( & V_1 ) ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_1 ) ;
}
static T_3 F_5 ( int V_2 , void * V_3 )
{
int V_4 , V_5 ;
int V_6 ;
struct V_7 * V_8 = V_3 ;
struct V_9 * V_10 = V_8 -> V_11 + 0 ;
if ( ! V_8 -> V_12 ) {
F_6 ( V_8 , L_1 ) ;
return V_13 ;
}
V_5 = F_7 ( V_8 -> V_14 + V_15 ) ;
V_4 = F_7 ( V_8 -> V_14 + V_16 ) ;
F_8 ( 0 , V_8 -> V_14 + V_17 ) ;
V_6 = ( V_5 << 8 ) | V_4 ;
if ( ! ( -- V_18 -> V_19 ) ) {
if ( V_20 -> V_21 )
F_8 ( 1 , V_8 -> V_14 + V_22 ) ;
else
F_8 ( 0 , V_8 -> V_14 + V_22 ) ;
V_10 -> V_23 -> V_24 |= V_25 ;
}
F_9 ( V_8 , V_10 ) ;
return V_13 ;
}
static void F_10 ( struct V_7 * V_8 , int V_26 )
{
int V_27 ;
F_8 ( F_11 ( V_26 ) , V_8 -> V_14 + V_28 ) ;
V_27 = F_12 ( V_26 ) ;
if ( V_20 -> V_21 ) {
if ( V_27 >= 8 )
V_27 = 0x20 | ( V_27 & 0x7 ) ;
else
V_27 |= 0x10 ;
} else {
F_8 ( V_27 , V_8 -> V_14 + V_29 ) ;
}
}
static int F_13 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_30 * V_31 , unsigned int * V_6 )
{
int V_32 , V_33 ;
int V_5 , V_4 ;
F_10 ( V_8 , V_31 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_33 ; V_33 ++ ) {
F_8 ( 1 , V_8 -> V_14 + V_22 ) ;
if ( ! V_20 -> V_21 )
F_8 ( 0 , V_8 -> V_14 + V_35 ) ;
V_32 = V_36 ;
while ( -- V_32 ) {
V_5 = F_7 ( V_8 -> V_14 + V_15 ) ;
if ( ! ( V_5 & V_37 ) )
goto V_38;
F_14 ( 1 ) ;
}
F_15 ( V_39 L_2 , V_8 -> V_40 ) ;
return - V_41 ;
V_38:
V_4 = F_7 ( V_8 -> V_14 + V_16 ) ;
V_6 [ V_33 ] = ( ( V_5 & 0xf ) << 8 ) | V_4 ;
}
return V_33 ;
}
static int F_16 ( struct V_7 * V_8 ,
struct V_9 * V_10 , struct V_42 * V_43 )
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
#define F_17 1000
#define F_18 100
if ( V_43 -> V_57 < F_17 ) {
V_43 -> V_57 = F_17 ;
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
F_19 ( F_18 ,
& V_18 -> V_62 ,
& V_18 -> V_63 ,
& V_43 -> V_57 ,
V_43 -> V_64 & V_65 ) ;
if ( V_44 != V_43 -> V_57 )
V_45 ++ ;
}
if ( V_45 )
return 4 ;
return 0 ;
}
static int F_20 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
int V_66 , V_67 ;
struct V_42 * V_43 = & V_10 -> V_23 -> V_43 ;
F_10 ( V_8 , V_43 -> V_68 [ 0 ] ) ;
if ( V_43 -> V_48 == V_49 ) {
V_66 = V_67 = 0 ;
F_21 ( V_69 , & V_66 , & V_67 ,
& V_43 -> V_57 ,
V_70 ) ;
F_8 ( 0x74 , V_8 -> V_14 + V_71 ) ;
F_8 ( V_66 & 0xff , V_8 -> V_14 + V_72 ) ;
F_8 ( ( V_66 >> 8 ) & 0xff , V_8 -> V_14 + V_72 ) ;
F_8 ( 0xb4 , V_8 -> V_14 + V_71 ) ;
F_8 ( V_67 & 0xff , V_8 -> V_14 + V_73 ) ;
F_8 ( ( V_67 >> 8 ) & 0xff , V_8 -> V_14 + V_73 ) ;
F_8 ( 0 , V_8 -> V_14 + V_17 ) ;
F_8 ( V_18 -> V_74 | 6 , V_8 -> V_14 + V_22 ) ;
} else {
F_8 ( V_18 -> V_74 | 3 , V_8 -> V_14 + V_22 ) ;
}
return 0 ;
}
static int F_22 ( struct V_7 * V_8 , struct V_9 * V_10 ,
struct V_30 * V_31 , unsigned int * V_6 )
{
int V_33 ;
int V_26 = F_12 ( V_31 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_33 ; V_33 ++ ) {
F_8 ( ( V_6 [ V_33 ] & 0xff ) ,
V_8 -> V_14 + ( V_26 ? V_75 : V_76 ) ) ;
F_8 ( ( V_6 [ V_33 ] >> 8 ) ,
V_8 -> V_14 + ( V_26 ? V_77 : V_78 ) ) ;
V_18 -> V_79 [ V_26 ] = V_6 [ V_33 ] ;
}
return V_33 ;
}
static int F_23 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_30 * V_31 , unsigned int * V_6 )
{
int V_33 ;
int V_26 = F_12 ( V_31 -> V_34 ) ;
for ( V_33 = 0 ; V_33 < V_31 -> V_33 ; V_33 ++ )
V_6 [ V_33 ] = V_18 -> V_79 [ V_26 ] ;
return V_33 ;
}
static int F_24 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_30 * V_31 , unsigned int * V_6 )
{
if ( V_31 -> V_33 != 2 )
return - V_80 ;
V_6 [ 1 ] = F_7 ( V_8 -> V_14 + V_81 ) |
( F_7 ( V_8 -> V_14 + V_82 ) << 8 ) ;
return 2 ;
}
static int F_25 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
struct V_30 * V_31 , unsigned int * V_6 )
{
if ( V_31 -> V_33 != 2 )
return - V_80 ;
if ( V_6 [ 0 ] ) {
V_10 -> V_83 &= ~ V_6 [ 0 ] ;
V_10 -> V_83 |= V_6 [ 0 ] & V_6 [ 1 ] ;
}
if ( V_6 [ 0 ] & 0x00ff )
F_8 ( V_10 -> V_83 & 0xff , V_8 -> V_14 + V_84 ) ;
if ( V_6 [ 0 ] & 0xff00 )
F_8 ( ( V_10 -> V_83 >> 8 ) , V_8 -> V_14 + V_85 ) ;
V_6 [ 1 ] = V_10 -> V_83 ;
return 2 ;
}
static int F_26 ( struct V_7 * V_8 )
{
F_15 ( V_86 L_3 , V_8 -> V_40 ) ;
if ( V_8 -> V_2 )
F_27 ( V_8 -> V_2 , V_8 ) ;
if ( V_8 -> V_14 )
F_28 ( V_8 -> V_14 , V_87 ) ;
return 0 ;
}
static int F_29 ( struct V_7 * V_8 , struct V_88 * V_89 )
{
int V_90 ;
unsigned long V_14 ;
unsigned int V_2 ;
struct V_9 * V_10 ;
V_14 = V_89 -> V_91 [ 0 ] ;
F_15 ( V_86 L_4 , V_8 -> V_40 , V_14 ) ;
if ( ! F_30 ( V_14 , V_87 , L_5 ) ) {
F_15 ( L_6 ) ;
return - V_92 ;
}
V_8 -> V_14 = V_14 ;
V_8 -> V_93 = V_20 -> V_94 ;
V_2 = V_89 -> V_91 [ 1 ] ;
if ( V_2 > V_20 -> V_95 ) {
F_15 ( V_39 L_7 ) ;
return - V_80 ;
}
if ( V_2 ) {
if ( F_31 ( V_2 , F_5 , 0 , L_5 , V_8 ) ) {
F_15 ( V_39 L_8 , V_2 ) ;
return - V_80 ;
} else {
F_15 ( V_86 L_9 , V_2 ) ;
}
}
V_8 -> V_2 = V_2 ;
V_90 = F_32 ( V_8 , 4 ) ;
if ( V_90 < 0 )
return V_90 ;
V_90 = F_33 ( V_8 , sizeof( struct V_96 ) ) ;
if ( V_90 < 0 )
return V_90 ;
V_10 = V_8 -> V_11 + 0 ;
V_10 -> type = V_97 ;
V_10 -> V_98 = V_99 | V_100 ;
V_10 -> V_101 = V_20 -> V_102 ;
V_10 -> V_103 = 0xfff ;
V_10 -> V_104 = 1 ;
V_10 -> V_105 = V_20 -> V_106 ;
V_10 -> V_107 = F_13 ;
if ( V_2 ) {
V_8 -> V_108 = V_10 ;
V_10 -> V_98 |= V_109 ;
V_10 -> V_110 = F_16 ;
V_10 -> V_111 = F_20 ;
}
V_10 ++ ;
V_10 -> type = V_112 ;
V_10 -> V_98 = V_113 ;
V_10 -> V_101 = V_20 -> V_114 ;
V_10 -> V_103 = 0xfff ;
V_10 -> V_104 = 1 ;
V_10 -> V_105 = & V_115 ;
V_10 -> V_116 = F_22 ;
V_10 -> V_107 = F_23 ;
V_10 ++ ;
V_10 -> type = V_117 ;
V_10 -> V_98 = V_99 ;
V_10 -> V_101 = 16 ;
V_10 -> V_103 = 1 ;
V_10 -> V_104 = 16 ;
V_10 -> V_105 = & V_118 ;
V_10 -> V_119 = F_24 ;
V_10 ++ ;
V_10 -> type = V_120 ;
V_10 -> V_98 = V_113 ;
V_10 -> V_101 = 16 ;
V_10 -> V_103 = 1 ;
V_10 -> V_104 = 16 ;
V_10 -> V_105 = & V_118 ;
V_10 -> V_83 = 0 ;
V_10 -> V_119 = F_25 ;
if ( V_20 -> V_121 )
V_18 -> V_74 = ( V_8 -> V_2 << 4 ) ;
F_8 ( 0 , V_8 -> V_14 + V_76 ) ;
F_8 ( 0 , V_8 -> V_14 + V_78 ) ;
F_8 ( 0 , V_8 -> V_14 + V_75 ) ;
F_8 ( 0 , V_8 -> V_14 + V_77 ) ;
F_15 ( V_86 L_10 ) ;
return 0 ;
}
