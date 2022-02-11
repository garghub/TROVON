static int F_1 ( void * * V_1 )
{
struct V_2 * V_3 ;
* V_1 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
* V_1 = V_3 ;
return 0 ;
}
static int F_3 ( void * V_3 )
{
F_4 ( (struct V_2 * ) V_3 ) ;
return 0 ;
}
static int F_5 ( void * V_3 , unsigned int V_6 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_8 , V_6 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_7 ( void * V_3 , unsigned int V_11 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_12 , V_11 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_8 ( void * V_3 , unsigned int V_13 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_14 , V_13 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_9 ( void * V_3 , unsigned int V_15 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_16 , V_15 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_10 ( void * V_3 , unsigned int V_17 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_18 , V_17 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_11 ( void * V_3 , unsigned int V_19 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_20 , V_19 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_12 ( void * V_3 , unsigned int V_21 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_22 , V_21 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_13 ( void * V_3 , unsigned int V_23 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_24 , V_23 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_14 ( void * V_3 , unsigned int V_25 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_26 , V_25 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_15 ( void * V_3 , unsigned int V_27 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_28 , V_27 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_16 ( void * V_3 , unsigned int V_29 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_30 , V_29 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_17 ( void * V_3 , unsigned int V_31 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_7 , V_32 , V_31 ) ;
V_7 -> V_9 . V_10 . V_7 = 1 ;
return 0 ;
}
static int F_18 ( void * V_3 , unsigned int V_33 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_34 , V_35 , V_33 ) ;
V_7 -> V_9 . V_10 . V_34 = 1 ;
return 0 ;
}
static int F_19 ( void * V_3 , unsigned int V_36 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_36 , V_37 , V_36 ) ;
V_7 -> V_9 . V_10 . V_36 = 1 ;
return 0 ;
}
static int F_20 ( void * V_3 , unsigned int V_38 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_38 , V_39 , V_38 ) ;
V_7 -> V_9 . V_10 . V_38 = 1 ;
return 0 ;
}
static int F_21 ( void * V_3 , unsigned int V_40 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_40 , V_41 , V_40 ) ;
V_7 -> V_9 . V_10 . V_40 = 1 ;
return 0 ;
}
static int F_22 ( void * V_3 , unsigned int V_42 )
{
struct V_2 * V_7 = V_3 ;
F_6 ( & V_7 -> V_43 , V_44 , V_42 ) ;
V_7 -> V_9 . V_10 . V_43 = 1 ;
return 0 ;
}
static int F_23 ( void * V_3 , unsigned int V_45 )
{
( (struct V_2 * ) V_3 ) -> V_9 . V_10 . V_46 = ( V_45 ? 1 : 0 ) ;
return 0 ;
}
static int F_24 ( void * V_3 , unsigned int V_47 )
{
( (struct V_2 * ) V_3 ) -> V_9 . V_48 = ( V_47 & 0xffff ) ;
return 0 ;
}
static int F_25 ( void * V_3 )
{
( (struct V_2 * ) V_3 ) -> V_9 . V_48 = ~ ( 0x0 ) ;
return 0 ;
}
static unsigned int F_26 ( unsigned int V_49 )
{
return ( ( V_49 << 4 ) + V_50 + V_51
- V_52 ) % V_51 ;
}
static int F_27 ( struct V_53 * V_53 , unsigned int V_54 , void * V_3 )
{
struct V_2 * V_7 = V_3 ;
int V_55 ;
if ( V_7 -> V_9 . V_10 . V_46 ) {
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ )
F_28 ( V_53 , V_56 + V_54 * 0x100 + V_55 * 0x4 , 0 ) ;
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ )
F_28 ( V_53 , V_57 + V_54 * 0x100 + V_55 * 0x4 , 0 ) ;
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ )
F_28 ( V_53 , V_58 + V_54 * 0x100 + V_55 * 0x4 , 0 ) ;
V_7 -> V_9 . V_10 . V_46 = 0 ;
}
if ( V_7 -> V_9 . V_10 . V_43 ) {
unsigned int V_59 = F_26 ( V_54 ) ;
F_28 ( V_53 , V_60 + 4 * V_59 , V_7 -> V_43 ) ;
F_28 ( V_53 , V_61 + 8 * V_59 , 0x3 ) ;
F_28 ( V_53 , V_62 + 8 * V_59 , 0x0 ) ;
V_7 -> V_9 . V_10 . V_43 = 0 ;
}
if ( V_7 -> V_9 . V_10 . V_38 ) {
F_28 ( V_53 , V_63 + V_54 * 0x100 , V_7 -> V_38 ) ;
V_7 -> V_9 . V_10 . V_38 = 0 ;
}
if ( V_7 -> V_9 . V_10 . V_40 ) {
F_28 ( V_53 , V_64 + V_54 * 0x100 , V_7 -> V_40 ) ;
V_7 -> V_9 . V_10 . V_40 = 0 ;
}
if ( V_7 -> V_9 . V_10 . V_36 ) {
F_28 ( V_53 , V_65 + V_54 * 0x100 , V_7 -> V_36 ) ;
V_7 -> V_9 . V_10 . V_36 = 0 ;
}
F_28 ( V_53 , V_66 + V_54 * 0x100 , 0x0 ) ;
if ( V_7 -> V_9 . V_10 . V_34 ) {
F_28 ( V_53 , V_67 + V_54 * 0x100 , V_7 -> V_34 ) ;
V_7 -> V_9 . V_10 . V_34 = 0 ;
}
if ( V_7 -> V_9 . V_10 . V_7 ) {
F_28 ( V_53 , V_68 + V_54 * 0x100 , V_7 -> V_7 ) ;
V_7 -> V_9 . V_10 . V_7 = 0 ;
}
return 0 ;
}
static int F_29 ( struct V_53 * V_53 , unsigned int V_54 , void * V_3 )
{
struct V_2 * V_7 = V_3 ;
V_7 -> V_36 = F_30 ( V_53 , V_65 + V_54 * 0x100 ) ;
V_7 -> V_9 . V_10 . V_36 = 0 ;
return F_31 ( V_7 -> V_36 , V_37 ) ;
}
static unsigned int F_32 ( void * V_3 )
{
return ( (struct V_2 * ) V_3 ) -> V_9 . V_48 ;
}
static unsigned int F_33 ( void )
{
return 0x20 ;
}
static int F_34 ( void * V_3 , unsigned int V_54 )
{
( (struct V_69 * ) V_3 ) -> V_70 = ~ ( 0x0 ) ;
( (struct V_69 * ) V_3 ) -> V_9 . V_10 . V_70 = 1 ;
( (struct V_69 * ) V_3 ) -> V_71 [ V_54 / 32 ] |= ( 0x1 << ( V_54 % 32 ) ) ;
return 0 ;
}
static int F_35 ( void * V_3 , unsigned int V_54 )
{
( (struct V_69 * ) V_3 ) -> V_71 [ V_54 / 32 ] |= ( 0x1 << ( V_54 % 32 ) ) ;
( (struct V_69 * ) V_3 ) -> V_9 . V_48 |= ( 0x1 << ( V_54 / 32 ) ) ;
return 0 ;
}
static int F_36 ( void * V_3 , unsigned int V_54 )
{
( (struct V_69 * ) V_3 ) -> V_71 [ V_54 / 32 ] &= ~ ( 0x1 << ( V_54 % 32 ) ) ;
( (struct V_69 * ) V_3 ) -> V_9 . V_48 |= ( 0x1 << ( V_54 / 32 ) ) ;
return 0 ;
}
static int F_37 ( struct V_53 * V_53 , void * V_3 )
{
struct V_69 * V_7 = V_3 ;
int V_55 ;
unsigned int V_72 ;
if ( V_7 -> V_9 . V_10 . V_70 ) {
do {
V_72 = F_30 ( V_53 , V_73 ) ;
} while ( V_72 & 0x1 );
F_28 ( V_53 , V_74 , V_7 -> V_70 ) ;
V_7 -> V_9 . V_10 . V_70 = 0 ;
}
for ( V_55 = 0 ; V_55 < 8 ; V_55 ++ ) {
if ( ( V_7 -> V_9 . V_48 & ( 0x1 << V_55 ) ) ) {
F_28 ( V_53 , V_75 + ( V_55 * 0x100 ) , V_7 -> V_71 [ V_55 ] ) ;
V_7 -> V_9 . V_48 &= ~ ( 0x1 << V_55 ) ;
}
}
return 0 ;
}
static int F_38 ( void * * V_1 )
{
struct V_69 * V_3 ;
* V_1 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
* V_1 = V_3 ;
return 0 ;
}
static int F_39 ( void * V_3 )
{
F_4 ( (struct V_69 * ) V_3 ) ;
return 0 ;
}
static int F_40 ( void * * V_1 )
{
struct V_76 * V_3 ;
* V_1 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
* V_1 = V_3 ;
return 0 ;
}
static int F_41 ( void * V_3 )
{
F_4 ( (struct V_76 * ) V_3 ) ;
return 0 ;
}
static int F_42 ( void * V_3 , unsigned int V_77 )
{
struct V_76 * V_7 = V_3 ;
F_6 ( & V_7 -> V_78 . V_79 , V_80 , V_77 ) ;
V_7 -> V_9 . V_10 . V_78 = 1 ;
return 0 ;
}
static int F_43 ( void * V_3 , unsigned int V_81 )
{
struct V_76 * V_7 = V_3 ;
F_6 ( & V_7 -> V_78 . V_79 , V_82 , V_81 ) ;
V_7 -> V_9 . V_10 . V_78 = 1 ;
return 0 ;
}
static int F_44 ( void * V_3 , unsigned int V_83 )
{
struct V_76 * V_7 = V_3 ;
F_6 ( & V_7 -> V_78 . V_79 , V_84 , V_83 ) ;
V_7 -> V_9 . V_10 . V_78 = 1 ;
return 0 ;
}
static int F_45 ( void * V_3 , unsigned int V_85 )
{
struct V_76 * V_7 = V_3 ;
V_7 -> V_78 . V_54 = V_85 ;
V_7 -> V_9 . V_10 . V_78 = 1 ;
return 0 ;
}
static int F_46 ( struct V_53 * V_53 , void * V_3 )
{
struct V_76 * V_7 = V_3 ;
if ( V_7 -> V_9 . V_10 . V_78 ) {
F_28 ( V_53 , V_86 + V_7 -> V_78 . V_54 * 0x100 ,
V_7 -> V_78 . V_79 ) ;
V_7 -> V_9 . V_10 . V_78 = 0 ;
}
return 0 ;
}
static int F_47 ( void * V_3 , unsigned int V_87 )
{
struct V_88 * V_7 = V_3 ;
F_6 ( & V_7 -> V_89 , V_90 , V_87 ) ;
V_7 -> V_9 . V_10 . V_89 = 1 ;
return 0 ;
}
static int F_48 ( void * V_3 , unsigned int V_91 )
{
return 0 ;
}
static int F_49 ( void * V_3 , unsigned int V_92 )
{
struct V_88 * V_7 = V_3 ;
F_6 ( & V_7 -> V_89 , V_93 , V_92 ) ;
V_7 -> V_9 . V_10 . V_89 = 1 ;
return 0 ;
}
static int F_50 ( void * V_3 , unsigned int V_94 )
{
struct V_88 * V_7 = V_3 ;
F_6 ( & V_7 -> V_89 , V_95 , V_94 ) ;
V_7 -> V_9 . V_10 . V_89 = 1 ;
return 0 ;
}
static int F_51 ( void * V_3 , unsigned int V_96 )
{
struct V_88 * V_7 = V_3 ;
F_6 ( & V_7 -> V_97 , V_98 , V_96 ) ;
V_7 -> V_9 . V_10 . V_97 = 1 ;
return 0 ;
}
static int F_52 ( void * V_3 , unsigned int V_99 )
{
struct V_88 * V_7 = V_3 ;
F_6 ( & V_7 -> V_97 , V_100 , V_99 ) ;
V_7 -> V_9 . V_10 . V_97 = 1 ;
return 0 ;
}
static int F_53 ( void * V_3 , unsigned int V_47 )
{
( (struct V_88 * ) V_3 ) -> V_9 . V_48 = ( V_47 & 0xffff ) ;
return 0 ;
}
static int F_54 ( void * V_3 )
{
( (struct V_88 * ) V_3 ) -> V_9 . V_48 = ~ ( 0x0 ) ;
return 0 ;
}
static int F_55 ( struct V_53 * V_53 , unsigned int V_54 , void * V_3 )
{
struct V_88 * V_7 = V_3 ;
if ( V_7 -> V_9 . V_10 . V_89 || V_7 -> V_9 . V_10 . V_97 ) {
F_28 ( V_53 , V_101 + V_54 * 8 , V_7 -> V_89 ) ;
V_7 -> V_9 . V_10 . V_89 = 0 ;
F_28 ( V_53 , V_102 + V_54 * 8 , V_7 -> V_97 ) ;
V_7 -> V_9 . V_10 . V_97 = 0 ;
}
return 0 ;
}
static int F_56 ( void * V_3 )
{
struct V_88 * V_7 = V_3 ;
return F_31 ( V_7 -> V_89 , V_95 ) ;
}
static unsigned int F_57 ( void * V_3 )
{
return ( (struct V_88 * ) V_3 ) -> V_9 . V_48 ;
}
static int F_58 ( void * * V_1 )
{
struct V_88 * V_3 ;
* V_1 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
* V_1 = V_3 ;
return 0 ;
}
static int F_59 ( void * V_3 )
{
F_4 ( (struct V_88 * ) V_3 ) ;
return 0 ;
}
static int F_60 ( void * * V_1 )
{
* V_1 = NULL ;
return 0 ;
}
static int F_61 ( void * V_3 )
{
return 0 ;
}
static int F_62 ( void * V_3 , unsigned int V_103 )
{
struct V_104 * V_7 = V_3 ;
F_6 ( & V_7 -> V_105 , V_106 , V_103 ) ;
V_7 -> V_9 . V_10 . V_105 = 1 ;
return 0 ;
}
static int F_63 ( void * V_3 , unsigned int V_103 )
{
struct V_104 * V_7 = V_3 ;
F_6 ( & V_7 -> V_105 , V_107 , V_103 ) ;
V_7 -> V_9 . V_10 . V_105 = 1 ;
return 0 ;
}
static int F_64 ( void * V_3 , unsigned int V_13 )
{
struct V_104 * V_7 = V_3 ;
F_6 ( & V_7 -> V_105 , V_108 , V_13 ) ;
V_7 -> V_9 . V_10 . V_105 = 1 ;
return 0 ;
}
static int F_65 ( void * V_3 , unsigned int V_109 )
{
struct V_104 * V_7 = V_3 ;
F_6 ( & V_7 -> V_105 , V_110 , V_109 ) ;
V_7 -> V_9 . V_10 . V_105 = 1 ;
return 0 ;
}
static int F_66 ( void * V_3 , unsigned int V_111 )
{
struct V_104 * V_7 = V_3 ;
F_6 ( & V_7 -> V_105 , V_112 , V_111 ? 1 : 0 ) ;
V_7 -> V_9 . V_10 . V_105 = 1 ;
return 0 ;
}
static int F_67 ( void * V_3 , unsigned int V_113 )
{
struct V_104 * V_7 = V_3 ;
F_6 ( & V_7 -> V_105 , V_114 , V_113 ? 1 : 0 ) ;
V_7 -> V_9 . V_10 . V_105 = 1 ;
return 0 ;
}
static int F_68 ( struct V_53 * V_53 , unsigned int V_54 , void * V_3 )
{
struct V_104 * V_7 = V_3 ;
if ( V_7 -> V_9 . V_10 . V_105 ) {
if ( V_54 < 4 ) {
F_28 ( V_53 , V_115 + 0x4 * V_54 , V_7 -> V_105 ) ;
} else {
F_28 ( V_53 , V_116 , V_7 -> V_105 ) ;
}
V_7 -> V_9 . V_10 . V_105 = 0 ;
}
return 0 ;
}
static int F_69 ( void * * V_1 )
{
struct V_104 * V_3 ;
* V_1 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
* V_1 = V_3 ;
return 0 ;
}
static int F_70 ( void * V_3 )
{
F_4 ( (struct V_104 * ) V_3 ) ;
return 0 ;
}
static int F_71 ( void * V_3 , unsigned int V_117 )
{
( (struct V_118 * ) V_3 ) -> V_117 = V_117 ;
( (struct V_118 * ) V_3 ) -> V_9 . V_10 . V_117 = 1 ;
return 0 ;
}
static int F_72 ( struct V_53 * V_53 , unsigned int V_54 , void * V_3 )
{
struct V_118 * V_7 = V_3 ;
if ( V_7 -> V_9 . V_10 . V_117 ) {
if ( V_54 < 4 ) {
F_28 ( V_53 , V_119 + 0x4 * V_54 , V_7 -> V_117 ) ;
}
V_7 -> V_9 . V_10 . V_117 = 0 ;
}
return 0 ;
}
static int F_73 ( void * V_3 , unsigned int * V_117 )
{
* V_117 = ( (struct V_118 * ) V_3 ) -> V_117 ;
return 0 ;
}
static int F_74 ( void * * V_1 )
{
struct V_118 * V_3 ;
* V_1 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
* V_1 = V_3 ;
return 0 ;
}
static int F_75 ( void * V_3 )
{
F_4 ( (struct V_118 * ) V_3 ) ;
return 0 ;
}
static int F_76 ( void * V_3 , unsigned int V_54 )
{
struct V_120 * V_7 = V_3 ;
if ( V_54 < 4 ) {
F_6 ( & V_7 -> V_121 , V_122 << ( V_54 * 8 ) , 1 ) ;
V_7 -> V_9 . V_10 . V_121 |= ( 0x1 << V_54 ) ;
} else {
V_54 %= 4 ;
F_6 ( & V_7 -> V_123 , V_124 << ( V_54 * 8 ) , 1 ) ;
V_7 -> V_9 . V_10 . V_125 |= ( 0x1 << V_54 ) ;
}
return 0 ;
}
static int F_77 ( void * V_3 , unsigned int V_54 )
{
struct V_120 * V_7 = V_3 ;
if ( V_54 < 4 ) {
F_6 ( & V_7 -> V_121 , V_122 << ( V_54 * 8 ) , 0 ) ;
V_7 -> V_9 . V_10 . V_121 |= ( 0x1 << V_54 ) ;
} else {
V_54 %= 4 ;
F_6 ( & V_7 -> V_123 , V_124 << ( V_54 * 8 ) , 0 ) ;
V_7 -> V_9 . V_10 . V_125 |= ( 0x1 << V_54 ) ;
}
return 0 ;
}
static int F_78 ( void * V_3 , unsigned int V_54 )
{
struct V_120 * V_7 = V_3 ;
if ( V_54 < 4 ) {
F_6 ( & V_7 -> V_126 , V_127 << ( V_54 * 8 ) , 1 ) ;
V_7 -> V_9 . V_10 . V_126 |= ( 0x1 << V_54 ) ;
} else {
V_54 %= 4 ;
F_6 ( & V_7 -> V_123 , V_128 << ( V_54 * 8 ) , 1 ) ;
V_7 -> V_9 . V_10 . V_129 |= ( 0x1 << V_54 ) ;
}
return 0 ;
}
static int F_79 ( void * V_3 , unsigned int V_54 )
{
struct V_120 * V_7 = V_3 ;
if ( V_54 < 4 ) {
F_6 ( & V_7 -> V_126 , V_127 << ( V_54 * 8 ) , 0 ) ;
V_7 -> V_9 . V_10 . V_126 |= ( 0x1 << V_54 ) ;
} else {
V_54 %= 4 ;
F_6 ( & V_7 -> V_123 , V_128 << ( V_54 * 8 ) , 0 ) ;
V_7 -> V_9 . V_10 . V_129 |= ( 0x1 << V_54 ) ;
}
return 0 ;
}
static int F_80 ( void * V_3 , unsigned int V_54 , unsigned int V_130 )
{
struct V_120 * V_7 = V_3 ;
if ( V_54 < 4 ) {
switch ( ( V_130 & 0x7 ) ) {
case 0 :
F_6 ( & V_7 -> V_126 , V_131 << ( V_54 * 8 ) , 3 ) ;
break;
case 1 :
F_6 ( & V_7 -> V_126 , V_131 << ( V_54 * 8 ) , 0 ) ;
break;
case 2 :
F_6 ( & V_7 -> V_126 , V_131 << ( V_54 * 8 ) , 1 ) ;
break;
case 4 :
F_6 ( & V_7 -> V_126 , V_131 << ( V_54 * 8 ) , 2 ) ;
break;
default:
break;
}
F_6 ( & V_7 -> V_126 , V_132 << ( V_54 * 8 ) ,
( V_130 >> 4 ) & 0x1 ) ;
F_6 ( & V_7 -> V_126 , V_133 << ( V_54 * 8 ) ,
( V_130 >> 4 ) & 0x1 ) ;
F_6 ( & V_7 -> V_126 , V_134 << ( V_54 * 8 ) ,
( ( V_130 >> 3 ) & 0x1 ) ? 2 : 2 ) ;
V_7 -> V_9 . V_10 . V_126 |= ( 0x1 << V_54 ) ;
} else {
}
return 0 ;
}
static int F_81 ( void * V_3 , unsigned int V_77 )
{
struct V_120 * V_7 = V_3 ;
F_6 ( & V_7 -> V_135 . V_136 , V_137 , V_77 ) ;
V_7 -> V_9 . V_10 . V_135 = 1 ;
return 0 ;
}
static int F_82 ( void * V_3 , unsigned int V_83 )
{
struct V_120 * V_7 = V_3 ;
F_6 ( & V_7 -> V_135 . V_136 , V_138 , V_83 ) ;
V_7 -> V_9 . V_10 . V_135 = 1 ;
return 0 ;
}
static int F_83 ( void * V_3 , unsigned int V_85 )
{
struct V_120 * V_7 = V_3 ;
V_7 -> V_135 . V_54 = V_85 ;
V_7 -> V_9 . V_10 . V_135 = 1 ;
return 0 ;
}
static int F_84 ( struct V_53 * V_53 , void * V_3 )
{
struct V_120 * V_7 = V_3 ;
int V_55 ;
if ( V_7 -> V_9 . V_10 . V_125 || V_7 -> V_9 . V_10 . V_129 ) {
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
if ( ( V_7 -> V_9 . V_10 . V_125 & ( 0x1 << V_55 ) ) )
V_7 -> V_9 . V_10 . V_125 &= ~ ( 0x1 << V_55 ) ;
if ( ( V_7 -> V_9 . V_10 . V_129 & ( 0x1 << V_55 ) ) )
V_7 -> V_9 . V_10 . V_129 &= ~ ( 0x1 << V_55 ) ;
}
F_28 ( V_53 , V_139 , V_7 -> V_123 ) ;
F_85 ( 1 ) ;
}
if ( V_7 -> V_9 . V_10 . V_126 ) {
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
if ( ( V_7 -> V_9 . V_10 . V_126 & ( 0x1 << V_55 ) ) )
V_7 -> V_9 . V_10 . V_126 &= ~ ( 0x1 << V_55 ) ;
}
F_28 ( V_53 , V_140 , V_7 -> V_126 ) ;
F_85 ( 1 ) ;
}
if ( V_7 -> V_9 . V_10 . V_121 ) {
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ ) {
if ( ( V_7 -> V_9 . V_10 . V_121 & ( 0x1 << V_55 ) ) )
V_7 -> V_9 . V_10 . V_121 &= ~ ( 0x1 << V_55 ) ;
}
F_28 ( V_53 , V_141 , V_7 -> V_121 ) ;
F_85 ( 1 ) ;
}
if ( V_7 -> V_9 . V_10 . V_135 ) {
F_28 ( V_53 , V_142 + V_7 -> V_135 . V_54 * 4 ,
V_7 -> V_135 . V_136 ) ;
V_7 -> V_9 . V_10 . V_135 = 0 ;
}
return 0 ;
}
static int F_86 ( struct V_53 * V_53 , void * * V_1 )
{
struct V_120 * V_3 ;
* V_1 = NULL ;
V_3 = F_2 ( sizeof( * V_3 ) , V_4 ) ;
if ( ! V_3 )
return - V_5 ;
V_3 -> V_123 = F_30 ( V_53 , V_139 ) ;
V_3 -> V_126 = F_30 ( V_53 , V_140 ) ;
V_3 -> V_121 = F_30 ( V_53 , V_141 ) ;
* V_1 = V_3 ;
return 0 ;
}
static int F_87 ( void * V_3 )
{
F_4 ( (struct V_120 * ) V_3 ) ;
return 0 ;
}
static int F_88 ( struct V_53 * V_53 , int V_143 )
{
F_28 ( V_53 , V_144 , V_143 ? V_145 : 0 ) ;
return 0 ;
}
static int F_89 ( struct V_53 * V_53 , unsigned int V_146 )
{
if ( V_146 )
V_146 |= V_147 | V_148 ;
F_28 ( V_53 , V_149 , V_146 ) ;
return 0 ;
}
static unsigned int F_90 ( struct V_53 * V_53 )
{
return F_30 ( V_53 , V_150 ) ;
}
static int F_91 ( struct V_53 * V_53 , const struct V_151 * V_152 )
{
T_1 V_153 ;
T_1 V_154 ;
V_153 = 0x94040404 ;
V_153 &= 0xfffffffc ;
F_28 ( V_53 , V_140 , 0x0 ) ;
V_154 = 0x05 ;
switch ( V_152 -> V_155 ) {
case 1 :
V_153 |= 1 ;
V_154 |= ( 0x0 << 6 ) ;
break;
case 2 :
V_153 |= 2 ;
V_154 |= ( 0x1 << 6 ) ;
break;
case 4 :
V_153 |= 3 ;
V_154 |= ( 0x2 << 6 ) ;
break;
default:
V_153 |= 1 ;
break;
}
F_28 ( V_53 , V_139 , V_153 ) ;
F_28 ( V_53 , V_140 , V_154 ) ;
F_28 ( V_53 , V_141 , 0x0 ) ;
F_85 ( 1 ) ;
V_154 = 0x0a0a0a0a ;
F_28 ( V_53 , V_141 , V_154 ) ;
F_85 ( 1 ) ;
return 0 ;
}
static int F_92 ( struct V_53 * V_53 , const struct V_156 * V_152 )
{
T_1 V_157 ;
T_1 V_158 , V_159 ;
if ( ( ~ 0UL ) == V_152 -> V_160 ) {
F_93 ( V_161 L_1 ) ;
return - 1 ;
}
V_157 = 0x13 ;
V_158 = ( T_1 ) V_152 -> V_160 ;
V_159 = F_94 ( V_152 -> V_160 ) ;
if ( sizeof( void * ) == 8 )
V_157 |= ( 1 << 2 ) ;
#if 0
#if V_162 == 8192
trnctl |= (1<<5);
#endif
#endif
F_28 ( V_53 , V_163 , V_158 ) ;
F_28 ( V_53 , V_164 , V_159 ) ;
F_28 ( V_53 , V_165 , V_157 ) ;
F_28 ( V_53 , V_166 , 0x200c01 ) ;
return 0 ;
}
static int F_95 ( struct V_53 * V_53 , unsigned int V_13 )
{
unsigned int V_167 ;
int V_55 ;
V_167 = ( 48000 == V_13 ) ? 0x1480a001 : 0x1480a731 ;
for ( V_55 = 0 ; V_55 < 3 ; V_55 ++ ) {
if ( F_30 ( V_53 , V_168 ) == V_167 )
break;
F_28 ( V_53 , V_168 , V_167 ) ;
F_85 ( 40 ) ;
}
if ( V_55 >= 3 ) {
F_93 ( V_169 L_2 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_96 ( struct V_53 * V_53 )
{
unsigned int V_171 ;
int V_55 ;
V_171 = F_30 ( V_53 , V_172 ) ;
F_6 ( & V_171 , V_173 , 0 ) ;
F_28 ( V_53 , V_172 , V_171 ) ;
F_6 ( & V_171 , V_173 , 1 ) ;
F_28 ( V_53 , V_172 , V_171 ) ;
F_85 ( 10 ) ;
for ( V_55 = 0 ; V_55 < 400000 ; V_55 ++ ) {
V_171 = F_30 ( V_53 , V_172 ) ;
if ( F_31 ( V_171 , V_174 ) )
break;
}
if ( ! F_31 ( V_171 , V_174 ) ) {
F_93 ( V_169 L_3 ) ;
return - V_170 ;
}
return 0 ;
}
static int F_97 ( struct V_53 * V_53 )
{
if ( ( F_98 ( V_53 , 0xcc ) & 0xff ) == 0xaa )
return 0 ;
F_99 ( V_53 , 0xcc , 0x8c ) ;
F_99 ( V_53 , 0xcc , 0x0e ) ;
if ( ( F_98 ( V_53 , 0xcc ) & 0xff ) == 0xaa )
return 0 ;
F_99 ( V_53 , 0xcc , 0xee ) ;
F_99 ( V_53 , 0xcc , 0xaa ) ;
if ( ( F_98 ( V_53 , 0xcc ) & 0xff ) == 0xaa )
return 0 ;
return - 1 ;
}
static void F_100 ( struct V_53 * V_53 )
{
if ( ( F_98 ( V_53 , 0xcc ) & 0xff ) == 0xaa )
F_99 ( V_53 , 0xcc , 0x00 ) ;
}
static void F_101 ( struct V_53 * V_53 , T_1 V_175 , T_1 V_85 , T_1 V_48 )
{
unsigned int V_72 ;
do {
V_72 = F_98 ( V_53 , 0xEC ) ;
} while ( ! ( V_72 & 0x800000 ) );
F_99 ( V_53 , 0xE0 , V_175 ) ;
F_99 ( V_53 , 0xE4 , ( V_48 << 8 ) | ( V_85 & 0xff ) ) ;
}
static int F_102 ( struct V_53 * V_53 )
{
T_1 V_55 ;
T_2 V_176 ;
unsigned int V_72 ;
if ( F_97 ( V_53 ) )
return - 1 ;
do {
V_72 = F_98 ( V_53 , 0xEC ) ;
} while ( ! ( V_72 & 0x800000 ) );
F_99 ( V_53 , 0xEC , 0x05 ) ;
for ( V_55 = 0 ; V_55 < 2 ; V_55 ++ ) {
F_85 ( 100 ) ;
V_176 = ( T_2 ) F_30 ( V_53 , V_177 ) ;
V_176 &= 0xfffd ;
F_28 ( V_53 , V_177 , V_176 ) ;
F_85 ( 1 ) ;
F_28 ( V_53 , V_177 , V_176 | 0x2 ) ;
}
F_101 ( V_53 , 0x00180080 , 0x01 , 0x80 ) ;
F_101 ( V_53 , 0x00180080 , 0x02 , 0x10 ) ;
F_100 ( V_53 ) ;
return 0 ;
}
static int F_103 ( struct V_53 * V_53 , const struct V_178 * V_152 )
{
T_1 V_48 ;
T_2 V_176 ;
unsigned int V_72 ;
if ( V_53 -> V_179 == V_180 ) {
V_176 = ( T_2 ) F_30 ( V_53 , V_177 ) ;
V_176 &= 0xffbf ;
V_176 |= 2 ;
F_28 ( V_53 , V_177 , V_176 ) ;
return 0 ;
}
V_176 = ( T_2 ) F_30 ( V_53 , V_177 ) ;
V_176 &= 0xffbf ;
F_28 ( V_53 , V_177 , V_176 ) ;
F_102 ( V_53 ) ;
if ( F_97 ( V_53 ) )
return - 1 ;
F_99 ( V_53 , 0xEC , 0x05 ) ;
do {
V_72 = F_98 ( V_53 , 0xEC ) ;
} while ( ! ( V_72 & 0x800000 ) );
switch ( V_152 -> V_155 ) {
case 1 :
V_48 = 0x24 ;
break;
case 2 :
V_48 = 0x25 ;
break;
case 4 :
V_48 = 0x26 ;
break;
default:
V_48 = 0x24 ;
break;
}
F_101 ( V_53 , 0x00180080 , 0x06 , V_48 ) ;
F_101 ( V_53 , 0x00180080 , 0x09 , V_48 ) ;
F_101 ( V_53 , 0x00180080 , 0x0c , V_48 ) ;
F_101 ( V_53 , 0x00180080 , 0x0f , V_48 ) ;
F_100 ( V_53 ) ;
V_176 = ( T_2 ) F_30 ( V_53 , V_177 ) ;
V_176 = V_176 | 0x40 ;
F_28 ( V_53 , V_177 , V_176 ) ;
return 0 ;
}
static int F_104 ( struct V_53 * V_53 , enum V_181 type )
{
return 0 ;
}
static int F_105 ( struct V_53 * V_53 , enum V_181 type )
{
T_1 V_48 ;
V_48 = F_30 ( V_53 , V_177 ) ;
switch ( type ) {
case V_182 :
V_48 = ( ( V_48 & ( 0x1 << 7 ) ) && ( V_48 & ( 0x1 << 8 ) ) ) ;
break;
case V_183 :
V_48 = ( ! ( V_48 & ( 0x1 << 7 ) ) && ( V_48 & ( 0x1 << 8 ) ) ) ;
break;
case V_184 :
V_48 = ( ! ( V_48 & ( 0x1 << 8 ) ) ) ;
break;
default:
V_48 = 0 ;
}
return V_48 ;
}
static int F_106 ( struct V_53 * V_53 , enum V_181 type )
{
T_1 V_48 ;
V_48 = F_30 ( V_53 , V_177 ) ;
switch ( type ) {
case V_182 :
V_48 = ( V_48 & ( 0x1 << 7 ) ) ? 1 : 0 ;
break;
case V_183 :
V_48 = ( V_48 & ( 0x1 << 7 ) ) ? 0 : 1 ;
break;
default:
V_48 = 0 ;
}
return V_48 ;
}
static int F_107 ( struct V_53 * V_53 , enum V_181 type )
{
switch ( V_53 -> V_179 ) {
case V_180 :
return F_104 ( V_53 , type ) ;
case V_185 :
return F_106 ( V_53 , type ) ;
case V_186 :
return F_106 ( V_53 , type ) ;
default:
return F_105 ( V_53 , type ) ;
}
}
static int
F_108 ( struct V_53 * V_53 , enum V_181 type , unsigned char V_187 )
{
T_1 V_48 ;
V_48 = F_30 ( V_53 , V_177 ) ;
V_48 &= 0xec73 ;
switch ( type ) {
case V_182 :
V_48 |= ( 0x1 << 7 ) | ( 0x1 << 8 ) | ( 0x1 << 9 ) ;
V_48 |= V_187 ? ( 0x1 << 2 ) : 0 ;
break;
case V_183 :
V_48 |= ( 0x1 << 8 ) ;
break;
case V_188 :
V_48 |= ( 0x1 << 8 ) | ( 0x1 << 12 ) ;
break;
case V_184 :
V_48 |= ( 0x1 << 12 ) ;
break;
default:
return - 1 ;
}
F_28 ( V_53 , V_177 , V_48 ) ;
return 0 ;
}
static int
F_109 ( struct V_53 * V_53 , enum V_181 type , unsigned char V_187 )
{
T_1 V_48 ;
T_1 V_189 ;
unsigned int V_72 ;
if ( F_97 ( V_53 ) )
return - 1 ;
do {
V_72 = F_98 ( V_53 , 0xEC ) ;
} while ( ! ( V_72 & 0x800000 ) );
F_99 ( V_53 , 0xEC , 0x05 ) ;
V_48 = F_30 ( V_53 , V_177 ) ;
switch ( type ) {
case V_182 :
V_48 |= ( ( 0x1 << 7 ) | ( 0x1 << 8 ) ) ;
V_189 = 0x1 ;
break;
case V_183 :
V_48 &= ~ ( 0x1 << 7 ) ;
V_48 |= ( 0x1 << 8 ) ;
V_189 = 0x2 ;
break;
case V_184 :
V_48 &= ~ ( 0x1 << 8 ) ;
V_189 = 0x0 ;
break;
default:
F_100 ( V_53 ) ;
return - 1 ;
}
F_28 ( V_53 , V_177 , V_48 ) ;
F_101 ( V_53 , 0x001a0080 , 0x2a , V_189 ) ;
if ( V_187 ) {
F_101 ( V_53 , 0x001a0080 , 0x1c , 0xe7 ) ;
F_101 ( V_53 , 0x001a0080 , 0x1e , 0xe7 ) ;
} else {
F_101 ( V_53 , 0x001a0080 , 0x1c , 0xcf ) ;
F_101 ( V_53 , 0x001a0080 , 0x1e , 0xcf ) ;
}
F_100 ( V_53 ) ;
return 0 ;
}
static int
F_110 ( struct V_53 * V_53 , enum V_181 type , unsigned char V_187 )
{
T_1 V_48 ;
T_1 V_189 ;
unsigned int V_72 ;
if ( F_97 ( V_53 ) )
return - 1 ;
do {
V_72 = F_98 ( V_53 , 0xEC ) ;
} while ( ! ( V_72 & 0x800000 ) );
F_99 ( V_53 , 0xEC , 0x05 ) ;
V_48 = F_30 ( V_53 , V_177 ) ;
switch ( type ) {
case V_182 :
V_48 |= ( 0x1 << 7 ) ;
V_189 = 0x1 ;
break;
case V_183 :
V_48 &= ~ ( 0x1 << 7 ) ;
V_189 = 0x2 ;
break;
default:
F_100 ( V_53 ) ;
return - 1 ;
}
F_28 ( V_53 , V_177 , V_48 ) ;
F_101 ( V_53 , 0x001a0080 , 0x2a , V_189 ) ;
if ( V_187 ) {
F_101 ( V_53 , 0x001a0080 , 0x1c , 0xe7 ) ;
F_101 ( V_53 , 0x001a0080 , 0x1e , 0xe7 ) ;
} else {
F_101 ( V_53 , 0x001a0080 , 0x1c , 0xcf ) ;
F_101 ( V_53 , 0x001a0080 , 0x1e , 0xcf ) ;
}
F_100 ( V_53 ) ;
return 0 ;
}
static int F_111 ( struct V_53 * V_53 , enum V_181 type )
{
int V_6 = type == V_182 ;
switch ( V_53 -> V_179 ) {
case V_180 :
return F_108 ( V_53 , type , V_6 ) ;
case V_185 :
return F_110 ( V_53 , type , V_6 ) ;
case V_186 :
return F_110 ( V_53 , type , V_6 ) ;
default:
return F_109 ( V_53 , type , V_6 ) ;
}
}
static int F_112 ( struct V_53 * V_53 , int V_190 , int V_191 )
{
return F_108 ( V_53 , V_190 , V_191 ) ;
}
static int F_113 ( struct V_53 * V_53 , int V_190 , int V_191 )
{
T_2 V_176 ;
T_2 V_192 ;
T_1 V_193 ;
unsigned int V_72 ;
V_192 = 0x100 ;
switch ( V_190 ) {
case V_182 :
V_193 = 0x1 ;
V_192 = 0x180 ;
break;
case V_183 :
V_193 = 0x2 ;
break;
case V_194 :
V_193 = 0x4 ;
break;
case V_188 :
V_193 = 0x8 ;
break;
case V_184 :
V_193 = 0x0 ;
V_192 = 0x0 ;
break;
default:
V_193 = 0x0 ;
break;
}
if ( F_97 ( V_53 ) )
return - 1 ;
do {
V_72 = F_98 ( V_53 , 0xEC ) ;
} while ( ! ( V_72 & 0x800000 ) );
F_99 ( V_53 , 0xEC , 0x05 ) ;
F_101 ( V_53 , 0x001a0080 , 0x0e , 0x08 ) ;
F_101 ( V_53 , 0x001a0080 , 0x18 , 0x0a ) ;
F_101 ( V_53 , 0x001a0080 , 0x28 , 0x86 ) ;
F_101 ( V_53 , 0x001a0080 , 0x2a , V_193 ) ;
if ( V_191 ) {
F_101 ( V_53 , 0x001a0080 , 0x1c , 0xf7 ) ;
F_101 ( V_53 , 0x001a0080 , 0x1e , 0xf7 ) ;
} else {
F_101 ( V_53 , 0x001a0080 , 0x1c , 0xcf ) ;
F_101 ( V_53 , 0x001a0080 , 0x1e , 0xcf ) ;
}
if ( ! ( F_30 ( V_53 , V_195 ) & 0x100 ) )
F_101 ( V_53 , 0x001a0080 , 0x16 , 0x26 ) ;
F_100 ( V_53 ) ;
V_176 = ( T_2 ) F_30 ( V_53 , V_177 ) ;
V_176 &= 0xfe7f ;
V_176 |= V_192 ;
F_28 ( V_53 , V_177 , V_176 ) ;
return 0 ;
}
static int F_114 ( struct V_53 * V_53 , const struct V_196 * V_152 )
{
if ( V_53 -> V_179 == V_180 )
return F_112 ( V_53 , V_152 -> V_190 , V_152 -> V_191 ) ;
else
return F_113 ( V_53 , V_152 -> V_190 , V_152 -> V_191 ) ;
}
static struct V_197 F_115 ( struct V_53 * V_53 )
{
struct V_197 V_198 ;
V_198 . V_199 = ! ( V_53 -> V_179 == V_185 || V_53 -> V_179 == V_186 ) ;
V_198 . V_200 = 0 ;
V_198 . V_201 = 0 ;
V_198 . V_202 = 0 ;
return V_198 ;
}
static int F_116 ( struct V_203 * V_204 )
{
unsigned int V_205 , V_206 , V_207 , V_208 , V_209 , V_210 ;
unsigned int V_211 , V_212 , V_213 , V_214 , V_215 ;
unsigned int V_216 ;
unsigned int V_48 [ 4 ] = { 0 } ;
unsigned int V_217 ;
void * V_218 ;
int V_55 ;
const T_1 V_219 = F_117 ( 'C' , 'T' , 'L' , 'X' ) ;
const T_1 V_220 = F_117 ( 'C' , 'T' , 'L' , '-' ) ;
const T_1 V_221 = F_117 ( 'C' , 'T' , 'L' , 'F' ) ;
const T_1 V_222 = F_117 ( 'C' , 'T' , 'L' , 'i' ) ;
const T_1 V_223 = F_117 ( 'C' , 'T' , 'L' , 'A' ) ;
const T_1 V_224 = F_117 ( 'C' , 'T' , 'L' , 'Z' ) ;
const T_1 V_225 = F_117 ( 'C' , 'T' , 'L' , 'L' ) ;
V_217 = F_118 ( V_204 , 0 ) ;
V_218 = F_119 ( V_217 , F_120 ( V_204 , 0 ) ) ;
if ( ! V_218 )
return - V_226 ;
for ( V_55 = 0 ; V_55 < 4 ; V_55 ++ )
V_48 [ V_55 ] = F_121 ( V_218 + V_227 ) ;
if ( V_48 [ 0 ] == V_223 ) {
V_216 = ( ( V_48 [ 1 ] == V_224 && V_48 [ 2 ] == V_225
&& V_48 [ 3 ] == V_223 ) || ( V_48 [ 1 ] == V_223
&& V_48 [ 2 ] == V_224 && V_48 [ 3 ] == V_225 ) ) ;
} else if ( V_48 [ 0 ] == V_224 ) {
V_216 = ( V_48 [ 1 ] == V_225
&& V_48 [ 2 ] == V_223 && V_48 [ 3 ] == V_223 ) ;
} else if ( V_48 [ 0 ] == V_225 ) {
V_216 = ( V_48 [ 1 ] == V_223
&& V_48 [ 2 ] == V_223 && V_48 [ 3 ] == V_224 ) ;
} else {
V_216 = 0 ;
}
if ( ! V_216 ) {
F_122 ( V_218 ) ;
return 0 ;
}
F_123 ( V_204 , V_228 , & V_205 ) ;
F_123 ( V_204 , V_229 , & V_206 ) ;
F_123 ( V_204 , V_230 , & V_207 ) ;
F_123 ( V_204 , V_231 , & V_208 ) ;
F_123 ( V_204 , V_232 , & V_209 ) ;
F_123 ( V_204 , V_233 , & V_210 ) ;
F_123 ( V_204 , V_234 , & V_212 ) ;
F_123 ( V_204 , V_235 , & V_213 ) ;
F_123 ( V_204 , V_236 , & V_214 ) ;
F_123 ( V_204 , V_237 , & V_215 ) ;
F_123 ( V_204 , V_238 , & V_211 ) ;
F_124 ( V_204 , V_239 , 0x87654321 ) ;
F_124 ( V_204 , V_228 , V_210 ) ;
F_124 ( V_204 , V_239 , 0x12345678 ) ;
F_124 ( V_204 , V_229 , V_206 ) ;
F_124 ( V_204 , V_230 , V_207 ) ;
F_124 ( V_204 , V_231 , V_208 ) ;
F_124 ( V_204 , V_232 , V_209 ) ;
F_124 ( V_204 , V_234 , V_212 ) ;
F_124 ( V_204 , V_235 , V_213 ) ;
F_124 ( V_204 , V_236 , V_214 ) ;
F_124 ( V_204 , V_237 , V_215 ) ;
F_124 ( V_204 , V_238 , V_211 ) ;
F_125 ( V_219 , ( V_218 + V_227 ) ) ;
F_125 ( V_220 , ( V_218 + V_227 ) ) ;
F_125 ( V_221 , ( V_218 + V_227 ) ) ;
F_125 ( V_222 , ( V_218 + V_227 ) ) ;
F_122 ( V_218 ) ;
return 0 ;
}
static T_3 F_126 ( int V_212 , void * V_240 )
{
struct V_53 * V_53 = V_240 ;
unsigned int V_241 ;
V_241 = F_30 ( V_53 , V_242 ) ;
if ( ! V_241 )
return V_243 ;
if ( V_53 -> V_244 )
V_53 -> V_244 ( V_53 -> V_245 , V_241 ) ;
F_28 ( V_53 , V_242 , V_241 ) ;
return V_246 ;
}
static int F_127 ( struct V_53 * V_53 )
{
int V_247 ;
struct V_203 * V_204 = V_53 -> V_204 ;
V_247 = F_128 ( V_204 ) ;
if ( V_247 < 0 )
return V_247 ;
if ( F_129 ( V_204 , V_248 ) < 0 ||
F_130 ( V_204 , V_248 ) < 0 ) {
F_93 ( V_161 L_4
L_5 ,
V_248 ) ;
V_247 = - V_249 ;
goto V_250;
}
if ( ! V_53 -> V_217 ) {
V_247 = F_131 ( V_204 , L_6 ) ;
if ( V_247 < 0 )
goto V_250;
if ( V_53 -> V_179 == V_186 )
V_53 -> V_217 = F_118 ( V_204 , 5 ) ;
else
V_53 -> V_217 = F_118 ( V_204 , 0 ) ;
}
if ( V_53 -> V_179 == V_186 ) {
V_247 = F_116 ( V_204 ) ;
if ( V_247 )
goto V_251;
}
if ( V_53 -> V_212 < 0 ) {
V_247 = F_132 ( V_204 -> V_212 , F_126 , V_252 ,
V_253 , V_53 ) ;
if ( V_247 < 0 ) {
F_93 ( V_161 L_7 , V_204 -> V_212 ) ;
goto V_251;
}
V_53 -> V_212 = V_204 -> V_212 ;
}
F_133 ( V_204 ) ;
return 0 ;
V_251:
F_134 ( V_204 ) ;
V_53 -> V_217 = 0 ;
V_250:
F_135 ( V_204 ) ;
return V_247 ;
}
static int F_136 ( struct V_53 * V_53 )
{
unsigned int V_48 ;
F_28 ( V_53 , V_165 , 0x00 ) ;
V_48 = F_30 ( V_53 , V_168 ) ;
F_28 ( V_53 , V_168 , ( V_48 & ( ~ ( 0x0F << 12 ) ) ) ) ;
if ( V_53 -> V_212 >= 0 )
F_137 ( V_53 -> V_212 ) ;
return 0 ;
}
static int F_138 ( struct V_53 * V_53 )
{
if ( V_53 -> V_212 >= 0 )
F_139 ( V_53 -> V_212 , V_53 ) ;
V_53 -> V_212 = - 1 ;
if ( V_53 -> V_218 )
F_122 ( ( void * ) V_53 -> V_218 ) ;
V_53 -> V_218 = ( unsigned long ) NULL ;
if ( V_53 -> V_217 )
F_134 ( V_53 -> V_204 ) ;
V_53 -> V_217 = 0 ;
F_135 ( V_53 -> V_204 ) ;
return 0 ;
}
static int F_140 ( struct V_53 * V_53 , struct V_254 * V_152 )
{
int V_247 ;
unsigned int V_171 ;
T_1 V_48 ;
struct V_178 V_255 = { 0 } ;
struct V_196 V_256 = { 0 } ;
struct V_151 V_257 = { 0 } ;
struct V_156 V_258 = { 0 } ;
V_247 = F_127 ( V_53 ) ;
if ( V_247 )
return V_247 ;
V_247 = F_95 ( V_53 , V_152 -> V_13 ) ;
if ( V_247 < 0 )
return V_247 ;
V_247 = F_96 ( V_53 ) ;
if ( V_247 < 0 )
return V_247 ;
V_171 = F_30 ( V_53 , V_172 ) ;
F_6 ( & V_171 , V_259 , 1 ) ;
F_6 ( & V_171 , V_260 , 1 ) ;
F_6 ( & V_171 , V_261 , 1 ) ;
F_6 ( & V_171 , V_262 , 1 ) ;
F_6 ( & V_171 , V_263 , 1 ) ;
F_28 ( V_53 , V_172 , V_171 ) ;
F_85 ( 10 ) ;
F_28 ( V_53 , V_144 , 0 ) ;
F_28 ( V_53 , V_264 , 0 ) ;
F_85 ( 30 ) ;
switch ( V_53 -> V_179 ) {
case V_180 :
F_28 ( V_53 , V_265 , 0x13fe ) ;
break;
case V_185 :
F_28 ( V_53 , V_265 , 0x00e6 ) ;
break;
case V_186 :
F_28 ( V_53 , V_265 , 0x00c2 ) ;
break;
default:
F_28 ( V_53 , V_265 , 0x01e6 ) ;
break;
}
V_258 . V_160 = V_152 -> V_160 ;
V_247 = F_92 ( V_53 , & V_258 ) ;
if ( V_247 < 0 )
return V_247 ;
V_257 . V_155 = V_152 -> V_155 ;
V_247 = F_91 ( V_53 , & V_257 ) ;
if ( V_247 < 0 )
return V_247 ;
V_255 . V_155 = V_152 -> V_155 ;
V_247 = F_103 ( V_53 , & V_255 ) ;
if ( V_247 < 0 )
return V_247 ;
V_256 . V_155 = V_152 -> V_155 ;
V_256 . V_190 = V_183 ;
V_256 . V_191 = 0 ;
V_247 = F_114 ( V_53 , & V_256 ) ;
if ( V_247 < 0 )
return V_247 ;
V_48 = F_30 ( V_53 , V_266 ) ;
V_48 |= 0x1 ;
F_28 ( V_53 , V_266 , V_48 ) ;
return 0 ;
}
static int F_141 ( struct V_53 * V_53 )
{
struct V_203 * V_204 = V_53 -> V_204 ;
F_136 ( V_53 ) ;
if ( V_53 -> V_179 == V_186 ) {
F_124 ( V_204 , V_239 , 0x0 ) ;
}
F_135 ( V_204 ) ;
F_142 ( V_204 ) ;
F_143 ( V_204 , V_267 ) ;
return 0 ;
}
static int F_144 ( struct V_53 * V_53 , struct V_254 * V_152 )
{
struct V_203 * V_204 = V_53 -> V_204 ;
F_143 ( V_204 , V_268 ) ;
F_145 ( V_204 ) ;
return F_140 ( V_53 , V_152 ) ;
}
static T_1 F_30 ( struct V_53 * V_53 , T_1 V_269 )
{
T_1 V_270 ;
unsigned long V_47 ;
F_146 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_272 , V_47 ) ;
F_148 ( V_269 , V_53 -> V_217 + 0x0 ) ;
V_270 = F_149 ( V_53 -> V_217 + 0x4 ) ;
F_150 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_272 , V_47 ) ;
return V_270 ;
}
static void F_28 ( struct V_53 * V_53 , T_1 V_269 , T_1 V_48 )
{
unsigned long V_47 ;
F_146 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_272 , V_47 ) ;
F_148 ( V_269 , V_53 -> V_217 + 0x0 ) ;
F_148 ( V_48 , V_53 -> V_217 + 0x4 ) ;
F_150 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_272 , V_47 ) ;
}
static T_1 F_98 ( struct V_53 * V_53 , T_1 V_269 )
{
T_1 V_270 ;
unsigned long V_47 ;
F_146 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_273 , V_47 ) ;
F_148 ( V_269 , V_53 -> V_217 + 0x10 ) ;
V_270 = F_149 ( V_53 -> V_217 + 0x14 ) ;
F_150 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_273 , V_47 ) ;
return V_270 ;
}
static void F_99 ( struct V_53 * V_53 , T_1 V_269 , T_1 V_48 )
{
unsigned long V_47 ;
F_146 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_273 , V_47 ) ;
F_148 ( V_269 , V_53 -> V_217 + 0x10 ) ;
F_148 ( V_48 , V_53 -> V_217 + 0x14 ) ;
F_150 (
& F_147 ( V_53 , struct V_271 , V_53 ) -> V_273 , V_47 ) ;
}
int T_4 F_151 ( struct V_53 * * V_274 )
{
struct V_271 * V_271 ;
* V_274 = NULL ;
V_271 = F_2 ( sizeof( * V_271 ) , V_4 ) ;
if ( ! V_271 )
return - V_5 ;
F_152 ( & V_271 -> V_272 ) ;
F_152 ( & V_271 -> V_273 ) ;
V_271 -> V_53 = V_275 ;
* V_274 = & V_271 -> V_53 ;
return 0 ;
}
int F_153 ( struct V_53 * V_53 )
{
if ( V_53 -> V_217 )
F_138 ( V_53 ) ;
F_4 ( F_147 ( V_53 , struct V_271 , V_53 ) ) ;
return 0 ;
}
