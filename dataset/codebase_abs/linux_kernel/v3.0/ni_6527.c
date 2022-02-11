static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
int V_8 = F_2 ( V_6 -> V_9 ) ;
unsigned int V_10 ;
if ( V_6 -> V_11 != 2 )
return - V_12 ;
if ( V_7 [ 0 ] != V_13 )
return - V_12 ;
if ( V_7 [ 1 ] ) {
V_10 = ( V_7 [ 1 ] + 100 ) / 200 ;
V_7 [ 1 ] = V_10 * 200 ;
if ( V_10 != V_14 -> V_15 ) {
F_3 ( V_10 & 0xff ,
V_14 -> V_16 -> V_17 + F_4 ( 0 ) ) ;
F_3 ( ( V_10 >> 8 ) & 0xff ,
V_14 -> V_16 -> V_17 + F_4 ( 1 ) ) ;
F_3 ( ( V_10 >> 16 ) & 0x0f ,
V_14 -> V_16 -> V_17 + F_4 ( 2 ) ) ;
F_3 ( V_18 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
V_14 -> V_15 = V_10 ;
}
V_14 -> V_20 |= 1 << V_8 ;
} else {
V_14 -> V_20 &= ~ ( 1 << V_8 ) ;
}
F_3 ( V_14 -> V_20 ,
V_14 -> V_16 -> V_17 + F_5 ( 0 ) ) ;
F_3 ( V_14 -> V_20 >> 8 ,
V_14 -> V_16 -> V_17 + F_5 ( 1 ) ) ;
F_3 ( V_14 -> V_20 >> 16 ,
V_14 -> V_16 -> V_17 + F_5 ( 2 ) ) ;
return 2 ;
}
static int F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_11 != 2 )
return - V_12 ;
V_7 [ 1 ] = F_7 ( V_14 -> V_16 -> V_17 + F_8 ( 0 ) ) ;
V_7 [ 1 ] |= F_7 ( V_14 -> V_16 -> V_17 + F_8 ( 1 ) ) << 8 ;
V_7 [ 1 ] |= F_7 ( V_14 -> V_16 -> V_17 + F_8 ( 2 ) ) << 16 ;
return 2 ;
}
static int F_9 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_11 != 2 )
return - V_12 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_21 &= ~ V_7 [ 0 ] ;
V_4 -> V_21 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
if ( V_7 [ 0 ] & 0x0000ff ) {
F_3 ( ( V_4 -> V_21 ^ 0xff ) ,
V_14 -> V_16 -> V_17 + F_8 ( 3 ) ) ;
}
if ( V_7 [ 0 ] & 0x00ff00 ) {
F_3 ( ( V_4 -> V_21 >> 8 ) ^ 0xff ,
V_14 -> V_16 -> V_17 + F_8 ( 4 ) ) ;
}
if ( V_7 [ 0 ] & 0xff0000 ) {
F_3 ( ( V_4 -> V_21 >> 16 ) ^ 0xff ,
V_14 -> V_16 -> V_17 + F_8 ( 5 ) ) ;
}
}
V_7 [ 1 ] = V_4 -> V_21 ;
return 2 ;
}
static T_1 F_10 ( int V_22 , void * V_23 )
{
struct V_1 * V_2 = V_23 ;
struct V_3 * V_4 = V_2 -> V_24 + 2 ;
unsigned int V_25 ;
V_25 = F_7 ( V_14 -> V_16 -> V_17 + V_26 ) ;
if ( ( V_25 & V_27 ) == 0 )
return V_28 ;
if ( ( V_25 & V_29 ) == 0 )
return V_28 ;
F_3 ( V_30 | V_31 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
F_11 ( V_4 -> V_32 , 0 ) ;
V_4 -> V_32 -> V_33 |= V_34 ;
F_12 ( V_2 , V_4 ) ;
return V_35 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_36 * V_37 )
{
int V_38 = 0 ;
int V_39 ;
V_39 = V_37 -> V_40 ;
V_37 -> V_40 &= V_41 ;
if ( ! V_37 -> V_40 || V_39 != V_37 -> V_40 )
V_38 ++ ;
V_39 = V_37 -> V_42 ;
V_37 -> V_42 &= V_43 ;
if ( ! V_37 -> V_42 || V_39 != V_37 -> V_42 )
V_38 ++ ;
V_39 = V_37 -> V_44 ;
V_37 -> V_44 &= V_45 ;
if ( ! V_37 -> V_44 || V_39 != V_37 -> V_44 )
V_38 ++ ;
V_39 = V_37 -> V_46 ;
V_37 -> V_46 &= V_47 ;
if ( ! V_37 -> V_46 || V_39 != V_37 -> V_46 )
V_38 ++ ;
V_39 = V_37 -> V_48 ;
V_37 -> V_48 &= V_47 ;
if ( ! V_37 -> V_48 || V_39 != V_37 -> V_48 )
V_38 ++ ;
if ( V_38 )
return 1 ;
if ( V_38 )
return 2 ;
if ( V_37 -> V_49 != 0 ) {
V_37 -> V_49 = 0 ;
V_38 ++ ;
}
if ( V_37 -> V_50 != 0 ) {
V_37 -> V_50 = 0 ;
V_38 ++ ;
}
if ( V_37 -> V_51 != 0 ) {
V_37 -> V_51 = 0 ;
V_38 ++ ;
}
if ( V_37 -> V_52 != 1 ) {
V_37 -> V_52 = 1 ;
V_38 ++ ;
}
if ( V_37 -> V_53 != 0 ) {
V_37 -> V_53 = 0 ;
V_38 ++ ;
}
if ( V_38 )
return 3 ;
if ( V_38 )
return 4 ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( V_30 | V_31 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
F_3 ( V_54 | V_55 |
V_56 | V_57 ,
V_14 -> V_16 -> V_17 + V_58 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + V_58 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_11 < 1 )
return - V_12 ;
V_7 [ 1 ] = 0 ;
return 2 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_11 < 1 )
return - V_12 ;
if ( V_7 [ 0 ] != V_59 )
return - V_12 ;
F_3 ( V_7 [ 1 ] ,
V_14 -> V_16 -> V_17 + F_18 ( 0 ) ) ;
F_3 ( V_7 [ 1 ] >> 8 ,
V_14 -> V_16 -> V_17 + F_18 ( 1 ) ) ;
F_3 ( V_7 [ 1 ] >> 16 ,
V_14 -> V_16 -> V_17 + F_18 ( 2 ) ) ;
F_3 ( V_7 [ 2 ] ,
V_14 -> V_16 -> V_17 + F_19 ( 0 ) ) ;
F_3 ( V_7 [ 2 ] >> 8 ,
V_14 -> V_16 -> V_17 + F_19 ( 1 ) ) ;
F_3 ( V_7 [ 2 ] >> 16 ,
V_14 -> V_16 -> V_17 + F_19 ( 2 ) ) ;
return 2 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_60 * V_61 )
{
struct V_3 * V_4 ;
int V_62 ;
F_21 ( V_63 L_1 , V_2 -> V_64 ) ;
V_62 = F_22 ( V_2 , sizeof( struct V_65 ) ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_23 ( V_2 , V_61 -> V_66 [ 0 ] , V_61 -> V_66 [ 1 ] ) ;
if ( V_62 < 0 )
return V_62 ;
V_62 = F_24 ( V_14 -> V_16 ) ;
if ( V_62 < 0 ) {
F_21 ( V_67 L_2 ) ;
return V_62 ;
}
V_2 -> V_68 = V_69 -> V_70 ;
F_21 ( V_63 L_3 , V_2 -> V_68 ,
F_7 ( V_14 -> V_16 -> V_17 + V_71 ) ) ;
V_62 = F_25 ( V_2 , 3 ) ;
if ( V_62 < 0 )
return V_62 ;
V_4 = V_2 -> V_24 + 0 ;
V_4 -> type = V_72 ;
V_4 -> V_73 = V_74 ;
V_4 -> V_75 = 24 ;
V_4 -> V_76 = & V_77 ;
V_4 -> V_78 = 1 ;
V_4 -> V_79 = F_1 ;
V_4 -> V_80 = F_6 ;
V_4 = V_2 -> V_24 + 1 ;
V_4 -> type = V_81 ;
V_4 -> V_73 = V_74 | V_82 ;
V_4 -> V_75 = 24 ;
V_4 -> V_76 = & V_83 ;
V_4 -> V_78 = 1 ;
V_4 -> V_80 = F_9 ;
V_4 = V_2 -> V_24 + 2 ;
V_2 -> V_84 = V_4 ;
V_4 -> type = V_72 ;
V_4 -> V_73 = V_74 | V_85 ;
V_4 -> V_75 = 1 ;
V_4 -> V_76 = & V_83 ;
V_4 -> V_78 = 1 ;
V_4 -> V_86 = F_13 ;
V_4 -> V_87 = F_14 ;
V_4 -> V_88 = F_15 ;
V_4 -> V_80 = F_16 ;
V_4 -> V_79 = F_17 ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + F_5 ( 0 ) ) ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + F_5 ( 1 ) ) ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + F_5 ( 2 ) ) ;
F_3 ( V_30 | V_31 | V_89 | V_18 ,
V_14 -> V_16 -> V_17 + V_19 ) ;
F_3 ( 0x00 , V_14 -> V_16 -> V_17 + V_58 ) ;
V_62 = F_26 ( F_27 ( V_14 -> V_16 ) , F_10 ,
V_90 , L_4 , V_2 ) ;
if ( V_62 < 0 )
F_21 ( V_91 L_5 ) ;
else
V_2 -> V_22 = F_27 ( V_14 -> V_16 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_2 )
{
if ( V_14 && V_14 -> V_16 && V_14 -> V_16 -> V_17 )
F_3 ( 0x00 ,
V_14 -> V_16 -> V_17 + V_58 ) ;
if ( V_2 -> V_22 )
F_29 ( V_2 -> V_22 , V_2 ) ;
if ( V_14 && V_14 -> V_16 )
F_30 ( V_14 -> V_16 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_2 , int V_92 , int V_93 )
{
struct V_94 * V_16 ;
int V_95 ;
for ( V_16 = V_96 ; V_16 ; V_16 = V_16 -> V_97 ) {
if ( V_16 -> V_98 )
continue;
if ( V_92 || V_93 ) {
if ( V_92 != V_16 -> V_99 -> V_92 -> V_100 ||
V_93 != F_31 ( V_16 -> V_99 -> V_101 ) )
continue;
}
for ( V_95 = 0 ; V_95 < V_102 ; V_95 ++ ) {
if ( F_32 ( V_16 ) == V_103 [ V_95 ] . V_104 ) {
V_2 -> V_105 = V_103 + V_95 ;
V_14 -> V_16 = V_16 ;
return 0 ;
}
}
}
F_21 ( V_67 L_6 ) ;
F_33 () ;
return - V_106 ;
}
static int T_2 F_34 ( struct V_107 * V_2 ,
const struct V_108 * V_109 )
{
return F_35 ( V_2 , V_110 . V_111 ) ;
}
static void T_3 F_36 ( struct V_107 * V_2 )
{
F_37 ( V_2 ) ;
}
static int T_4 F_38 ( void )
{
int V_112 ;
V_112 = F_39 ( & V_110 ) ;
if ( V_112 < 0 )
return V_112 ;
V_113 . V_70 = ( char * ) V_110 . V_111 ;
return F_40 ( & V_113 ) ;
}
static void T_5 F_41 ( void )
{
F_42 ( & V_113 ) ;
F_43 ( & V_110 ) ;
}
