static T_1 F_1 ( int V_1 , void * V_2 )
{
int V_3 , V_4 ;
int V_5 ;
struct V_6 * V_7 = V_2 ;
struct V_8 * V_9 = V_7 -> V_10 + 0 ;
if ( ! V_7 -> V_11 ) {
F_2 ( V_7 , L_1 ) ;
return V_12 ;
}
V_4 = F_3 ( V_7 -> V_13 + V_14 ) ;
V_3 = F_3 ( V_7 -> V_13 + V_15 ) ;
F_4 ( 0 , V_7 -> V_13 + V_16 ) ;
V_5 = ( V_4 << 8 ) | V_3 ;
if ( ! ( -- V_17 -> V_18 ) ) {
if ( V_19 -> V_20 )
F_4 ( 1 , V_7 -> V_13 + V_21 ) ;
else
F_4 ( 0 , V_7 -> V_13 + V_21 ) ;
V_9 -> V_22 -> V_23 |= V_24 ;
}
F_5 ( V_7 , V_9 ) ;
return V_12 ;
}
static void F_6 ( struct V_6 * V_7 , int V_25 )
{
int V_26 ;
F_4 ( F_7 ( V_25 ) , V_7 -> V_13 + V_27 ) ;
V_26 = F_8 ( V_25 ) ;
if ( V_19 -> V_20 ) {
if ( V_26 >= 8 )
V_26 = 0x20 | ( V_26 & 0x7 ) ;
else
V_26 |= 0x10 ;
} else {
F_4 ( V_26 , V_7 -> V_13 + V_28 ) ;
}
}
static int F_9 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_29 * V_30 , unsigned int * V_5 )
{
int V_31 , V_32 ;
int V_4 , V_3 ;
F_6 ( V_7 , V_30 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ ) {
F_4 ( 1 , V_7 -> V_13 + V_21 ) ;
if ( ! V_19 -> V_20 )
F_4 ( 0 , V_7 -> V_13 + V_34 ) ;
V_31 = V_35 ;
while ( -- V_31 ) {
V_4 = F_3 ( V_7 -> V_13 + V_14 ) ;
if ( ! ( V_4 & V_36 ) )
goto V_37;
F_10 ( 1 ) ;
}
F_11 ( V_38 L_2 , V_7 -> V_39 ) ;
return - V_40 ;
V_37:
V_3 = F_3 ( V_7 -> V_13 + V_15 ) ;
V_5 [ V_32 ] = ( ( V_4 & 0xf ) << 8 ) | V_3 ;
}
return V_32 ;
}
static int F_12 ( struct V_6 * V_7 ,
struct V_8 * V_9 , struct V_41 * V_42 )
{
int V_43 ;
int V_44 = 0 ;
V_43 = V_42 -> V_45 ;
V_42 -> V_45 &= V_46 ;
if ( ! V_42 -> V_45 || V_43 != V_42 -> V_45 )
V_44 ++ ;
V_43 = V_42 -> V_47 ;
V_42 -> V_47 &= V_48 | V_49 ;
if ( ! V_42 -> V_47 || V_43 != V_42 -> V_47 )
V_44 ++ ;
V_43 = V_42 -> V_50 ;
V_42 -> V_50 &= V_46 ;
if ( ! V_42 -> V_50 || V_43 != V_42 -> V_50 )
V_44 ++ ;
V_43 = V_42 -> V_51 ;
V_42 -> V_51 &= V_52 ;
if ( ! V_42 -> V_51 || V_43 != V_42 -> V_51 )
V_44 ++ ;
V_43 = V_42 -> V_53 ;
V_42 -> V_53 &= V_52 | V_54 ;
if ( ! V_42 -> V_53 || V_43 != V_42 -> V_53 )
V_44 ++ ;
if ( V_44 )
return 1 ;
if ( V_42 -> V_47 != V_48 &&
V_42 -> V_47 != V_49 )
V_44 ++ ;
if ( V_42 -> V_53 != V_52 && V_42 -> V_53 != V_54 )
V_44 ++ ;
if ( V_44 )
return 2 ;
if ( V_42 -> V_55 != 0 ) {
V_42 -> V_55 = 0 ;
V_44 ++ ;
}
if ( V_42 -> V_47 == V_49 ) {
if ( V_42 -> V_56 != 0 ) {
V_42 -> V_56 = 0 ;
V_44 ++ ;
}
} else {
#define F_13 1000
#define F_14 100
if ( V_42 -> V_56 < F_13 ) {
V_42 -> V_56 = F_13 ;
V_44 ++ ;
}
}
if ( V_42 -> V_57 != 0 ) {
V_42 -> V_57 = 0 ;
V_44 ++ ;
}
if ( V_42 -> V_58 != V_42 -> V_59 ) {
V_42 -> V_58 = V_42 -> V_59 ;
V_44 ++ ;
}
if ( V_42 -> V_53 == V_54 ) {
if ( V_42 -> V_60 != 0 ) {
V_42 -> V_60 = 0 ;
V_44 ++ ;
}
} else {
}
if ( V_44 )
return 3 ;
if ( V_42 -> V_47 == V_48 ) {
V_43 = V_42 -> V_56 ;
F_15 ( F_14 ,
& V_17 -> V_61 ,
& V_17 -> V_62 ,
& V_42 -> V_56 ,
V_42 -> V_63 & V_64 ) ;
if ( V_43 != V_42 -> V_56 )
V_44 ++ ;
}
if ( V_44 )
return 4 ;
return 0 ;
}
static int F_16 ( struct V_6 * V_7 , struct V_8 * V_9 )
{
int V_65 , V_66 ;
struct V_41 * V_42 = & V_9 -> V_22 -> V_42 ;
F_6 ( V_7 , V_42 -> V_67 [ 0 ] ) ;
if ( V_42 -> V_47 == V_48 ) {
V_65 = V_66 = 0 ;
F_17 ( V_68 , & V_65 , & V_66 ,
& V_42 -> V_56 ,
V_69 ) ;
F_4 ( 0x74 , V_7 -> V_13 + V_70 ) ;
F_4 ( V_65 & 0xff , V_7 -> V_13 + V_71 ) ;
F_4 ( ( V_65 >> 8 ) & 0xff , V_7 -> V_13 + V_71 ) ;
F_4 ( 0xb4 , V_7 -> V_13 + V_70 ) ;
F_4 ( V_66 & 0xff , V_7 -> V_13 + V_72 ) ;
F_4 ( ( V_66 >> 8 ) & 0xff , V_7 -> V_13 + V_72 ) ;
F_4 ( 0 , V_7 -> V_13 + V_16 ) ;
F_4 ( V_17 -> V_73 | 6 , V_7 -> V_13 + V_21 ) ;
} else {
F_4 ( V_17 -> V_73 | 3 , V_7 -> V_13 + V_21 ) ;
}
return 0 ;
}
static int F_18 ( struct V_6 * V_7 , struct V_8 * V_9 ,
struct V_29 * V_30 , unsigned int * V_5 )
{
int V_32 ;
int V_25 = F_8 ( V_30 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ ) {
F_4 ( ( V_5 [ V_32 ] & 0xff ) ,
V_7 -> V_13 + ( V_25 ? V_74 : V_75 ) ) ;
F_4 ( ( V_5 [ V_32 ] >> 8 ) ,
V_7 -> V_13 + ( V_25 ? V_76 : V_77 ) ) ;
V_17 -> V_78 [ V_25 ] = V_5 [ V_32 ] ;
}
return V_32 ;
}
static int F_19 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_29 * V_30 , unsigned int * V_5 )
{
int V_32 ;
int V_25 = F_8 ( V_30 -> V_33 ) ;
for ( V_32 = 0 ; V_32 < V_30 -> V_32 ; V_32 ++ )
V_5 [ V_32 ] = V_17 -> V_78 [ V_25 ] ;
return V_32 ;
}
static int F_20 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_29 * V_30 , unsigned int * V_5 )
{
if ( V_30 -> V_32 != 2 )
return - V_79 ;
V_5 [ 1 ] = F_3 ( V_7 -> V_13 + V_80 ) |
( F_3 ( V_7 -> V_13 + V_81 ) << 8 ) ;
return 2 ;
}
static int F_21 ( struct V_6 * V_7 ,
struct V_8 * V_9 ,
struct V_29 * V_30 , unsigned int * V_5 )
{
if ( V_30 -> V_32 != 2 )
return - V_79 ;
if ( V_5 [ 0 ] ) {
V_9 -> V_82 &= ~ V_5 [ 0 ] ;
V_9 -> V_82 |= V_5 [ 0 ] & V_5 [ 1 ] ;
}
if ( V_5 [ 0 ] & 0x00ff )
F_4 ( V_9 -> V_82 & 0xff , V_7 -> V_13 + V_83 ) ;
if ( V_5 [ 0 ] & 0xff00 )
F_4 ( ( V_9 -> V_82 >> 8 ) , V_7 -> V_13 + V_84 ) ;
V_5 [ 1 ] = V_9 -> V_82 ;
return 2 ;
}
static int F_22 ( struct V_6 * V_7 , struct V_85 * V_86 )
{
int V_87 ;
unsigned long V_13 ;
unsigned int V_1 ;
struct V_8 * V_9 ;
V_13 = V_86 -> V_88 [ 0 ] ;
F_11 ( V_89 L_3 , V_7 -> V_39 , V_13 ) ;
if ( ! F_23 ( V_13 , V_90 , L_4 ) ) {
F_11 ( L_5 ) ;
return - V_91 ;
}
V_7 -> V_13 = V_13 ;
V_7 -> V_92 = V_19 -> V_93 ;
V_1 = V_86 -> V_88 [ 1 ] ;
if ( V_1 > V_19 -> V_94 ) {
F_11 ( V_38 L_6 ) ;
return - V_79 ;
}
if ( V_1 ) {
if ( F_24 ( V_1 , F_1 , 0 , L_4 , V_7 ) ) {
F_11 ( V_38 L_7 , V_1 ) ;
return - V_79 ;
} else {
F_11 ( V_89 L_8 , V_1 ) ;
}
}
V_7 -> V_1 = V_1 ;
V_87 = F_25 ( V_7 , 4 ) ;
if ( V_87 < 0 )
return V_87 ;
V_87 = F_26 ( V_7 , sizeof( struct V_95 ) ) ;
if ( V_87 < 0 )
return V_87 ;
V_9 = V_7 -> V_10 + 0 ;
V_9 -> type = V_96 ;
V_9 -> V_97 = V_98 | V_99 ;
V_9 -> V_100 = V_19 -> V_101 ;
V_9 -> V_102 = 0xfff ;
V_9 -> V_103 = 1 ;
V_9 -> V_104 = V_19 -> V_105 ;
V_9 -> V_106 = F_9 ;
if ( V_1 ) {
V_7 -> V_107 = V_9 ;
V_9 -> V_97 |= V_108 ;
V_9 -> V_109 = F_12 ;
V_9 -> V_110 = F_16 ;
}
V_9 ++ ;
V_9 -> type = V_111 ;
V_9 -> V_97 = V_112 ;
V_9 -> V_100 = V_19 -> V_113 ;
V_9 -> V_102 = 0xfff ;
V_9 -> V_103 = 1 ;
V_9 -> V_104 = & V_114 ;
V_9 -> V_115 = F_18 ;
V_9 -> V_106 = F_19 ;
V_9 ++ ;
V_9 -> type = V_116 ;
V_9 -> V_97 = V_98 ;
V_9 -> V_100 = 16 ;
V_9 -> V_102 = 1 ;
V_9 -> V_103 = 16 ;
V_9 -> V_104 = & V_117 ;
V_9 -> V_118 = F_20 ;
V_9 ++ ;
V_9 -> type = V_119 ;
V_9 -> V_97 = V_112 ;
V_9 -> V_100 = 16 ;
V_9 -> V_102 = 1 ;
V_9 -> V_103 = 16 ;
V_9 -> V_104 = & V_117 ;
V_9 -> V_82 = 0 ;
V_9 -> V_118 = F_21 ;
if ( V_19 -> V_120 )
V_17 -> V_73 = ( V_7 -> V_1 << 4 ) ;
F_4 ( 0 , V_7 -> V_13 + V_75 ) ;
F_4 ( 0 , V_7 -> V_13 + V_77 ) ;
F_4 ( 0 , V_7 -> V_13 + V_74 ) ;
F_4 ( 0 , V_7 -> V_13 + V_76 ) ;
F_11 ( V_89 L_9 ) ;
return 0 ;
}
static void F_27 ( struct V_6 * V_7 )
{
if ( V_7 -> V_1 )
F_28 ( V_7 -> V_1 , V_7 ) ;
if ( V_7 -> V_13 )
F_29 ( V_7 -> V_13 , V_90 ) ;
}
