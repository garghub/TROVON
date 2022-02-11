static inline int F_1 ( T_1 V_1 )
{
F_2 ( L_1 , V_2 ) ;
if ( ( V_1 & 0xff00 ) == 0 )
return 0 ;
if ( ( V_1 & 0x00ff ) == 0 )
return 1 ;
if ( ( V_1 & 0xf000 ) == 0 || ( V_1 & 0x0f00 ) == 0 )
return 0 ;
return 1 ;
}
static unsigned long F_3 ( struct V_3 * V_4 ,
unsigned long V_5 )
{
T_2 V_6 ;
struct V_7 * V_8 = (struct V_7 * ) V_4 -> V_9 ;
F_2 ( L_1 , V_2 ) ;
if ( ( V_5 < V_8 -> V_10 ) ||
( ( V_5 >= 0x100000 ) && ( V_5 < V_8 -> V_11 ) ) )
return V_5 ;
V_6 = ( V_5 - V_8 -> V_10 ) + V_8 -> V_11 ;
if ( V_6 < V_8 -> V_12 )
return V_6 ;
F_4 ( V_13 , L_2 , V_5 ) ;
return V_8 -> V_10 - 1 ;
}
static void F_5 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_2 V_16 , V_5 ;
T_1 V_1 ;
int V_17 ;
int V_18 ;
F_2 ( L_1 , V_2 ) ;
V_16 = V_15 -> V_19 ;
V_5 = V_16 >> 6 ;
V_1 = V_15 -> V_20 ;
V_17 = F_6 ( V_4 , V_5 ) ;
V_18 = F_1 ( V_1 ) ;
F_7 ( V_21 , V_4 , V_5 , 0 , V_1 ,
V_17 , V_18 , - 1 , L_3 , L_4 , NULL ) ;
}
static void F_8 ( struct V_3 * V_4 )
{
F_2 ( L_1 , V_2 ) ;
F_7 ( V_22 , V_4 , 0 , 0 , 0 , - 1 , - 1 , - 1 ,
L_5 , L_4 , NULL ) ;
}
static void F_9 ( struct V_3 * V_4 , struct V_14 * V_15 )
{
T_2 V_23 , V_24 ;
int V_17 ;
F_2 ( L_1 , V_2 ) ;
V_23 = V_15 -> V_25 ;
V_24 = V_23 >> 6 ;
V_17 = F_6 ( V_4 , V_24 ) ;
F_7 ( V_22 , V_4 , V_24 , 0 , 0 ,
V_17 , - 1 , - 1 , L_6 , L_4 , NULL ) ;
}
static void F_10 ( struct V_3 * V_4 )
{
F_2 ( L_1 , V_2 ) ;
F_7 ( V_22 , V_4 , 0 , 0 , 0 , - 1 , - 1 , - 1 ,
L_7 , L_4 , NULL ) ;
}
static void F_11 ( struct V_3 * V_4 ,
struct V_14 * V_15 )
{
struct V_7 * V_8 ;
V_8 = (struct V_7 * ) V_4 -> V_9 ;
F_12 ( V_8 -> V_26 , V_27 , & V_15 -> V_28 ) ;
F_12 ( V_8 -> V_26 , V_29 , & V_15 -> V_30 ) ;
if ( ( V_15 -> V_28 & 1 ) || ( V_15 -> V_30 & 1 ) ) {
F_13 ( V_8 -> V_26 , V_31 ,
& V_15 -> V_19 ) ;
F_14 ( V_8 -> V_26 ,
V_32 ,
& V_15 -> V_20 ) ;
}
if ( ( V_15 -> V_28 & 2 ) || ( V_15 -> V_30 & 2 ) )
F_13 ( V_8 -> V_26 , V_33 ,
& V_15 -> V_25 ) ;
if ( V_15 -> V_28 & 3 )
F_15 ( V_8 -> V_26 , V_27 , 0x03 , 0x03 ) ;
if ( V_15 -> V_30 & 3 )
F_15 ( V_8 -> V_26 , V_29 , 0x03 , 0x03 ) ;
}
static int F_16 ( struct V_3 * V_4 ,
struct V_14 * V_15 ,
int V_34 )
{
int V_35 ;
V_35 = 0 ;
if ( V_15 -> V_28 & 1 ) {
V_35 = 1 ;
if ( V_34 )
F_5 ( V_4 , V_15 ) ;
}
if ( V_15 -> V_28 & 2 ) {
V_35 = 1 ;
if ( V_34 )
F_9 ( V_4 , V_15 ) ;
}
if ( V_15 -> V_30 & 1 ) {
V_35 = 1 ;
if ( V_34 ) {
if ( V_15 -> V_28 & 1 )
F_8 ( V_4 ) ;
else
F_5 ( V_4 , V_15 ) ;
}
}
if ( V_15 -> V_30 & 2 ) {
V_35 = 1 ;
if ( V_34 ) {
if ( V_15 -> V_28 & 2 )
F_10 ( V_4 ) ;
else
F_9 ( V_4 , V_15 ) ;
}
}
return V_35 ;
}
static void F_17 ( struct V_3 * V_4 )
{
struct V_14 V_15 ;
F_2 ( L_1 , V_2 ) ;
F_11 ( V_4 , & V_15 ) ;
F_16 ( V_4 , & V_15 , 1 ) ;
}
static inline int F_18 ( T_2 V_36 , int V_37 )
{
return ( V_37 == V_38 ) ? ( ( V_36 >> 22 ) & 0x1 ) : 1 ;
}
static inline int F_19 ( T_2 V_36 , int V_37 )
{
return ( V_37 == V_38 ) ? ( ( V_36 >> 18 ) & 0x3 ) : 1 ;
}
static void F_20 ( struct V_3 * V_4 , struct V_39 * V_40 ,
int V_37 , T_2 V_36 )
{
unsigned long V_41 ;
int V_42 , V_43 ;
T_3 V_44 ;
T_2 V_45 , V_46 , V_47 ;
int V_48 , V_49 , V_50 , V_51 ;
struct V_52 * V_53 ;
struct V_54 * V_55 ;
F_13 ( V_40 , V_56 , & V_45 ) ;
V_48 = F_18 ( V_36 , V_37 ) ;
V_49 = F_19 ( V_36 , V_37 ) ;
V_50 = ( V_36 >> 20 ) & 0x3 ;
V_41 = 0 ;
for ( V_42 = 0 ; V_42 < V_4 -> V_57 ; V_42 ++ ) {
V_51 = ( V_45 >> ( V_42 * 4 + 3 ) ) & 0x1 ;
V_53 = & V_4 -> V_58 [ V_42 ] ;
F_12 ( V_40 , V_59 + V_42 , & V_44 ) ;
V_46 = V_44 << ( 25 + V_49 - V_60 ) ;
F_2 ( L_8 , V_2 , V_42 ,
V_46 ) ;
if ( V_46 == V_41 )
continue;
V_53 -> V_61 = V_41 ;
V_53 -> V_62 = V_46 - 1 ;
V_47 = V_46 - V_41 ;
V_41 = V_46 ;
for ( V_43 = 0 ; V_43 < V_48 + 1 ; V_43 ++ ) {
V_55 = V_53 -> V_63 [ V_43 ] . V_55 ;
V_55 -> V_47 = V_47 / ( V_48 + 1 ) ;
V_55 -> V_64 = 1 << 12 ;
V_55 -> V_65 = V_66 ;
V_55 -> V_67 = V_51 ? V_68 : V_69 ;
if ( V_50 ) {
if ( V_48 && V_51 ) {
V_55 -> V_70 = V_71 ;
V_4 -> V_72 |= V_73 ;
} else {
V_55 -> V_70 = V_74 ;
V_4 -> V_72 |= V_75 ;
}
} else
V_55 -> V_70 = V_76 ;
}
}
}
static int F_21 ( struct V_39 * V_40 , int V_37 )
{
T_1 V_77 ;
struct V_3 * V_4 = NULL ;
struct V_78 V_79 [ 2 ] ;
struct V_7 * V_8 = NULL ;
T_2 V_36 ;
int V_48 ;
struct V_14 V_80 ;
F_22 ( L_9 , V_2 ) ;
F_13 ( V_40 , V_81 , & V_36 ) ;
V_48 = F_18 ( V_36 , V_37 ) ;
V_79 [ 0 ] . type = V_82 ;
V_79 [ 0 ] . V_83 = V_84 ;
V_79 [ 0 ] . V_85 = true ;
V_79 [ 1 ] . type = V_86 ;
V_79 [ 1 ] . V_83 = V_48 + 1 ;
V_79 [ 1 ] . V_85 = false ;
V_4 = F_23 ( 0 , F_24 ( V_79 ) , V_79 , sizeof( * V_8 ) ) ;
if ( V_4 == NULL )
return - V_87 ;
F_2 ( L_10 , V_2 ) ;
V_4 -> V_88 = V_89 ;
V_4 -> V_90 = V_91 | V_75 |
V_73 ;
V_4 -> V_92 = V_93 ;
V_4 -> V_94 = V_95 ;
V_4 -> V_96 = & V_40 -> V_96 ;
F_2 ( L_11 , V_2 ) ;
V_8 = (struct V_7 * ) V_4 -> V_9 ;
V_8 -> V_97 = & V_98 [ V_37 ] ;
V_8 -> V_26 = F_25 ( V_99 ,
V_8 -> V_97 -> V_100 , V_8 -> V_26 ) ;
if ( ! V_8 -> V_26 ) {
F_4 ( V_13 , L_12
L_13 ,
V_99 , V_98 [ V_37 ] . V_100 ) ;
goto V_101;
}
F_2 ( L_14 , V_2 ) ;
V_4 -> V_102 = V_8 -> V_97 -> V_102 ;
V_4 -> V_103 = F_26 ( V_40 ) ;
V_4 -> V_104 = F_17 ;
V_4 -> F_3 = F_3 ;
F_20 ( V_4 , V_40 , V_37 , V_36 ) ;
V_4 -> V_72 |= V_91 ;
F_2 ( L_15 , V_2 ) ;
F_14 ( V_40 , V_105 , & V_77 ) ;
V_8 -> V_10 = ( ( T_2 ) V_77 ) << 4 ;
F_14 ( V_40 , V_106 , & V_77 ) ;
V_8 -> V_11 = ( ( T_2 ) V_77 ) << 14 ;
F_14 ( V_40 , V_107 , & V_77 ) ;
V_8 -> V_12 = ( ( T_2 ) V_77 ) << 14 ;
F_4 ( V_108 ,
L_16 , V_8 -> V_10 ,
V_8 -> V_11 , V_8 -> V_12 ) ;
F_11 ( V_4 , & V_80 ) ;
if ( F_27 ( V_4 ) ) {
F_2 ( L_17 , V_2 ) ;
goto V_109;
}
V_110 = F_28 ( & V_40 -> V_96 , V_93 ) ;
if ( ! V_110 ) {
F_29 ( V_111
L_18 ,
V_2 ) ;
F_29 ( V_111
L_19 ,
V_2 ) ;
}
F_2 ( L_20 , V_2 ) ;
return 0 ;
V_109:
F_30 ( V_8 -> V_26 ) ;
V_101:
F_31 ( V_4 ) ;
return - V_112 ;
}
static int T_4 F_32 ( struct V_39 * V_40 ,
const struct V_113 * V_114 )
{
F_22 ( L_1 , V_2 ) ;
return F_33 ( V_40 ) ?
- V_115 : F_21 ( V_40 , V_114 -> V_116 ) ;
}
static void T_5 F_34 ( struct V_39 * V_40 )
{
struct V_3 * V_4 ;
struct V_7 * V_8 ;
F_22 ( L_1 , V_2 ) ;
if ( V_110 )
F_35 ( V_110 ) ;
if ( ( V_4 = F_36 ( & V_40 -> V_96 ) ) == NULL )
return;
V_8 = (struct V_7 * ) V_4 -> V_9 ;
F_30 ( V_8 -> V_26 ) ;
F_31 ( V_4 ) ;
}
static int T_6 F_37 ( void )
{
F_38 () ;
return F_39 ( & V_117 ) ;
}
static void T_7 F_40 ( void )
{
F_41 ( & V_117 ) ;
}
