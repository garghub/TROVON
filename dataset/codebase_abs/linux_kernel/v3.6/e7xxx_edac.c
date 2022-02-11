static inline int F_1 ( T_1 V_1 )
{
F_2 ( 3 , L_1 ) ;
if ( ( V_1 & 0xff00 ) == 0 )
return 0 ;
if ( ( V_1 & 0x00ff ) == 0 )
return 1 ;
if ( ( V_1 & 0xf000 ) == 0 || ( V_1 & 0x0f00 ) == 0 )
return 0 ;
return 1 ;
}
static unsigned long F_3 ( struct V_2 * V_3 ,
unsigned long V_4 )
{
T_2 V_5 ;
struct V_6 * V_7 = (struct V_6 * ) V_3 -> V_8 ;
F_2 ( 3 , L_1 ) ;
if ( ( V_4 < V_7 -> V_9 ) ||
( ( V_4 >= 0x100000 ) && ( V_4 < V_7 -> V_10 ) ) )
return V_4 ;
V_5 = ( V_4 - V_7 -> V_9 ) + V_7 -> V_10 ;
if ( V_5 < V_7 -> V_11 )
return V_5 ;
F_4 ( V_12 , L_2 , V_4 ) ;
return V_7 -> V_9 - 1 ;
}
static void F_5 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
T_2 V_15 , V_4 ;
T_1 V_1 ;
int V_16 ;
int V_17 ;
F_2 ( 3 , L_1 ) ;
V_15 = V_14 -> V_18 ;
V_4 = V_15 >> 6 ;
V_1 = V_14 -> V_19 ;
V_16 = F_6 ( V_3 , V_4 ) ;
V_17 = F_1 ( V_1 ) ;
F_7 ( V_20 , V_3 , 1 , V_4 , 0 , V_1 ,
V_16 , V_17 , - 1 , L_3 , L_4 ) ;
}
static void F_8 ( struct V_2 * V_3 )
{
F_2 ( 3 , L_1 ) ;
F_7 ( V_21 , V_3 , 1 , 0 , 0 , 0 , - 1 , - 1 , - 1 ,
L_5 , L_4 ) ;
}
static void F_9 ( struct V_2 * V_3 , struct V_13 * V_14 )
{
T_2 V_22 , V_23 ;
int V_16 ;
F_2 ( 3 , L_1 ) ;
V_22 = V_14 -> V_24 ;
V_23 = V_22 >> 6 ;
V_16 = F_6 ( V_3 , V_23 ) ;
F_7 ( V_21 , V_3 , 1 , V_23 , 0 , 0 ,
V_16 , - 1 , - 1 , L_6 , L_4 ) ;
}
static void F_10 ( struct V_2 * V_3 )
{
F_2 ( 3 , L_1 ) ;
F_7 ( V_21 , V_3 , 1 , 0 , 0 , 0 , - 1 , - 1 , - 1 ,
L_7 , L_4 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
struct V_13 * V_14 )
{
struct V_6 * V_7 ;
V_7 = (struct V_6 * ) V_3 -> V_8 ;
F_12 ( V_7 -> V_25 , V_26 , & V_14 -> V_27 ) ;
F_12 ( V_7 -> V_25 , V_28 , & V_14 -> V_29 ) ;
if ( ( V_14 -> V_27 & 1 ) || ( V_14 -> V_29 & 1 ) ) {
F_13 ( V_7 -> V_25 , V_30 ,
& V_14 -> V_18 ) ;
F_14 ( V_7 -> V_25 ,
V_31 ,
& V_14 -> V_19 ) ;
}
if ( ( V_14 -> V_27 & 2 ) || ( V_14 -> V_29 & 2 ) )
F_13 ( V_7 -> V_25 , V_32 ,
& V_14 -> V_24 ) ;
if ( V_14 -> V_27 & 3 )
F_15 ( V_7 -> V_25 , V_26 , 0x03 , 0x03 ) ;
if ( V_14 -> V_29 & 3 )
F_15 ( V_7 -> V_25 , V_28 , 0x03 , 0x03 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_13 * V_14 ,
int V_33 )
{
int V_34 ;
V_34 = 0 ;
if ( V_14 -> V_27 & 1 ) {
V_34 = 1 ;
if ( V_33 )
F_5 ( V_3 , V_14 ) ;
}
if ( V_14 -> V_27 & 2 ) {
V_34 = 1 ;
if ( V_33 )
F_9 ( V_3 , V_14 ) ;
}
if ( V_14 -> V_29 & 1 ) {
V_34 = 1 ;
if ( V_33 ) {
if ( V_14 -> V_27 & 1 )
F_8 ( V_3 ) ;
else
F_5 ( V_3 , V_14 ) ;
}
}
if ( V_14 -> V_29 & 2 ) {
V_34 = 1 ;
if ( V_33 ) {
if ( V_14 -> V_27 & 2 )
F_10 ( V_3 ) ;
else
F_9 ( V_3 , V_14 ) ;
}
}
return V_34 ;
}
static void F_17 ( struct V_2 * V_3 )
{
struct V_13 V_14 ;
F_2 ( 3 , L_1 ) ;
F_11 ( V_3 , & V_14 ) ;
F_16 ( V_3 , & V_14 , 1 ) ;
}
static inline int F_18 ( T_2 V_35 , int V_36 )
{
return ( V_36 == V_37 ) ? ( ( V_35 >> 22 ) & 0x1 ) : 1 ;
}
static inline int F_19 ( T_2 V_35 , int V_36 )
{
return ( V_36 == V_37 ) ? ( ( V_35 >> 18 ) & 0x3 ) : 1 ;
}
static void F_20 ( struct V_2 * V_3 , struct V_38 * V_39 ,
int V_36 , T_2 V_35 )
{
unsigned long V_40 ;
int V_41 , V_42 ;
T_3 V_43 ;
T_2 V_44 , V_45 , V_46 ;
int V_47 , V_48 , V_49 , V_50 ;
struct V_51 * V_52 ;
struct V_53 * V_54 ;
enum V_55 V_56 ;
F_13 ( V_39 , V_57 , & V_44 ) ;
V_47 = F_18 ( V_35 , V_36 ) ;
V_48 = F_19 ( V_35 , V_36 ) ;
V_49 = ( V_35 >> 20 ) & 0x3 ;
V_40 = 0 ;
for ( V_41 = 0 ; V_41 < V_3 -> V_58 ; V_41 ++ ) {
V_50 = ( V_44 >> ( V_41 * 4 + 3 ) ) & 0x1 ;
V_52 = V_3 -> V_59 [ V_41 ] ;
F_12 ( V_39 , V_60 + V_41 , & V_43 ) ;
V_45 = V_43 << ( 25 + V_48 - V_61 ) ;
F_2 ( 3 , L_8 , V_41 , V_45 ) ;
if ( V_45 == V_40 )
continue;
V_52 -> V_62 = V_40 ;
V_52 -> V_63 = V_45 - 1 ;
V_46 = V_45 - V_40 ;
V_40 = V_45 ;
if ( V_49 ) {
if ( V_47 && V_50 ) {
V_56 = V_64 ;
V_3 -> V_65 |= V_66 ;
} else {
V_56 = V_67 ;
V_3 -> V_65 |= V_68 ;
}
} else
V_56 = V_69 ;
for ( V_42 = 0 ; V_42 < V_47 + 1 ; V_42 ++ ) {
V_54 = V_52 -> V_70 [ V_42 ] -> V_54 ;
V_54 -> V_46 = V_46 / ( V_47 + 1 ) ;
V_54 -> V_71 = 1 << 12 ;
V_54 -> V_72 = V_73 ;
V_54 -> V_74 = V_50 ? V_75 : V_76 ;
V_54 -> V_56 = V_56 ;
}
}
}
static int F_21 ( struct V_38 * V_39 , int V_36 )
{
T_1 V_77 ;
struct V_2 * V_3 = NULL ;
struct V_78 V_79 [ 2 ] ;
struct V_6 * V_7 = NULL ;
T_2 V_35 ;
int V_47 ;
struct V_13 V_80 ;
F_2 ( 0 , L_9 ) ;
F_13 ( V_39 , V_81 , & V_35 ) ;
V_47 = F_18 ( V_35 , V_36 ) ;
V_79 [ 0 ] . type = V_82 ;
V_79 [ 0 ] . V_83 = V_84 ;
V_79 [ 0 ] . V_85 = true ;
V_79 [ 1 ] . type = V_86 ;
V_79 [ 1 ] . V_83 = V_47 + 1 ;
V_79 [ 1 ] . V_85 = false ;
V_3 = F_22 ( 0 , F_23 ( V_79 ) , V_79 , sizeof( * V_7 ) ) ;
if ( V_3 == NULL )
return - V_87 ;
F_2 ( 3 , L_10 ) ;
V_3 -> V_88 = V_89 ;
V_3 -> V_90 = V_91 | V_68 |
V_66 ;
V_3 -> V_92 = V_93 ;
V_3 -> V_94 = V_95 ;
V_3 -> V_39 = & V_39 -> V_96 ;
F_2 ( 3 , L_11 ) ;
V_7 = (struct V_6 * ) V_3 -> V_8 ;
V_7 -> V_97 = & V_98 [ V_36 ] ;
V_7 -> V_25 = F_24 ( V_99 ,
V_7 -> V_97 -> V_100 , V_7 -> V_25 ) ;
if ( ! V_7 -> V_25 ) {
F_4 ( V_12 , L_12
L_13 ,
V_99 , V_98 [ V_36 ] . V_100 ) ;
goto V_101;
}
F_2 ( 3 , L_14 ) ;
V_3 -> V_102 = V_7 -> V_97 -> V_102 ;
V_3 -> V_103 = F_25 ( V_39 ) ;
V_3 -> V_104 = F_17 ;
V_3 -> F_3 = F_3 ;
F_20 ( V_3 , V_39 , V_36 , V_35 ) ;
V_3 -> V_65 |= V_91 ;
F_2 ( 3 , L_15 ) ;
F_14 ( V_39 , V_105 , & V_77 ) ;
V_7 -> V_9 = ( ( T_2 ) V_77 ) << 4 ;
F_14 ( V_39 , V_106 , & V_77 ) ;
V_7 -> V_10 = ( ( T_2 ) V_77 ) << 14 ;
F_14 ( V_39 , V_107 , & V_77 ) ;
V_7 -> V_11 = ( ( T_2 ) V_77 ) << 14 ;
F_4 ( V_108 ,
L_16 , V_7 -> V_9 ,
V_7 -> V_10 , V_7 -> V_11 ) ;
F_11 ( V_3 , & V_80 ) ;
if ( F_26 ( V_3 ) ) {
F_2 ( 3 , L_17 ) ;
goto V_109;
}
V_110 = F_27 ( & V_39 -> V_96 , V_93 ) ;
if ( ! V_110 ) {
F_28 ( V_111
L_18 ,
V_112 ) ;
F_28 ( V_111
L_19 ,
V_112 ) ;
}
F_2 ( 3 , L_20 ) ;
return 0 ;
V_109:
F_29 ( V_7 -> V_25 ) ;
V_101:
F_30 ( V_3 ) ;
return - V_113 ;
}
static int T_4 F_31 ( struct V_38 * V_39 ,
const struct V_114 * V_115 )
{
F_2 ( 0 , L_1 ) ;
return F_32 ( V_39 ) ?
- V_116 : F_21 ( V_39 , V_115 -> V_117 ) ;
}
static void T_5 F_33 ( struct V_38 * V_39 )
{
struct V_2 * V_3 ;
struct V_6 * V_7 ;
F_2 ( 0 , L_1 ) ;
if ( V_110 )
F_34 ( V_110 ) ;
if ( ( V_3 = F_35 ( & V_39 -> V_96 ) ) == NULL )
return;
V_7 = (struct V_6 * ) V_3 -> V_8 ;
F_29 ( V_7 -> V_25 ) ;
F_30 ( V_3 ) ;
}
static int T_6 F_36 ( void )
{
F_37 () ;
return F_38 ( & V_118 ) ;
}
static void T_7 F_39 ( void )
{
F_40 ( & V_118 ) ;
}
