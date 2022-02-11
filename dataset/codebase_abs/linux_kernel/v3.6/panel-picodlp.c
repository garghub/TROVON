static inline struct V_1
* F_1 ( const struct V_2 * V_3 )
{
return (struct V_1 * ) V_3 -> V_4 ;
}
static T_1 F_2 ( struct V_5 * V_6 , T_2 V_7 )
{
T_2 V_8 [] = { V_9 , V_7 } , V_4 [ 4 ] ;
struct V_10 * V_10 = F_3 ( V_6 ) ;
struct V_11 V_12 [ 2 ] ;
F_4 ( & V_10 -> V_13 ) ;
V_12 [ 0 ] . V_14 = V_6 -> V_14 ;
V_12 [ 0 ] . V_15 = 0 ;
V_12 [ 0 ] . V_16 = 2 ;
V_12 [ 0 ] . V_17 = V_8 ;
V_12 [ 1 ] . V_14 = V_6 -> V_14 ;
V_12 [ 1 ] . V_15 = V_18 ;
V_12 [ 1 ] . V_16 = 4 ;
V_12 [ 1 ] . V_17 = V_4 ;
F_5 ( V_6 -> V_19 , V_12 , 2 ) ;
F_6 ( & V_10 -> V_13 ) ;
return ( V_4 [ 3 ] | ( V_4 [ 2 ] << 8 ) | ( V_4 [ 1 ] << 16 ) | ( V_4 [ 0 ] << 24 ) ) ;
}
static int F_7 ( struct V_5 * V_6 ,
T_2 * V_4 , int V_16 )
{
struct V_11 V_12 ;
int V_20 , V_21 , V_22 = 1 ;
struct V_10 * V_10 = F_3 ( V_6 ) ;
if ( V_16 < 1 || V_16 > 32 ) {
F_8 ( & V_6 -> V_23 ,
L_1 , V_16 ) ;
return - V_24 ;
}
F_4 ( & V_10 -> V_13 ) ;
V_12 . V_14 = V_6 -> V_14 ;
V_12 . V_15 = 0 ;
V_12 . V_16 = V_16 ;
V_12 . V_17 = V_4 ;
V_21 = F_5 ( V_6 -> V_19 , & V_12 , V_22 ) ;
F_6 ( & V_10 -> V_13 ) ;
if ( V_21 != V_22 )
goto V_25;
for ( V_20 = 0 ; V_20 < V_16 ; V_20 ++ )
F_9 ( & V_6 -> V_23 ,
L_2 ,
V_6 -> V_14 , V_4 [ 0 ] + V_20 , V_20 , V_4 [ V_20 ] ) ;
return 0 ;
V_25:
F_8 ( & V_6 -> V_23 , L_3 ) ;
return V_21 ;
}
static int F_10 ( struct V_5 * V_6 , T_2 V_7 , T_1 V_26 )
{
T_2 V_4 [ 5 ] ;
int V_20 ;
V_4 [ 0 ] = V_7 ;
for ( V_20 = 1 ; V_20 < 5 ; V_20 ++ )
V_4 [ V_20 ] = ( V_26 >> ( 32 - ( V_20 ) * 8 ) ) & 0xFF ;
return F_7 ( V_6 , V_4 , 5 ) ;
}
static int F_11 ( struct V_5 * V_6 ,
const struct V_27 V_28 [] ,
int V_29 )
{
int V_20 , V_21 = 0 ;
for ( V_20 = 0 ; V_20 < V_29 ; V_20 ++ ) {
V_21 = F_10 ( V_6 , V_28 [ V_20 ] . V_7 ,
V_28 [ V_20 ] . V_26 ) ;
if ( V_21 )
return V_21 ;
}
return V_21 ;
}
static int F_12 ( struct V_5 * V_6 )
{
T_2 V_30 = 100 ;
do {
F_13 ( 1 ) ;
if ( ! V_30 -- )
return - V_31 ;
} while ( F_2 ( V_6 , V_32 ) & V_33 );
return 0 ;
}
static int F_14 ( struct V_5 * V_6 )
{
int V_21 ;
static const struct V_27 V_34 [] = {
{ V_35 , 1 } ,
{ V_36 , 1 } ,
{ V_37 , 5 } ,
{ V_38 , 0 } ,
{ V_39 , 0x100 } ,
{ V_40 , 7 } ,
{ V_41 , 0x109 } ,
{ V_42 , 0xA } ,
{ V_43 , 0xB } ,
{ V_44 , 0x2ED } ,
{ V_45 , 0 } ,
{ V_46 , 0xB } ,
{ V_47 , 1 } ,
{ V_48 , 3 } ,
{ V_49 , 0 } ,
{ V_50 , V_51 } ,
{ V_52 , V_53 } ,
{ V_54 , 0 } ,
{ V_55 , V_56 } ,
{ V_49 , 1 } ,
} ;
static const struct V_27 V_57 [] = {
{ V_49 , 0 } ,
{ V_55 , 0 } ,
{ V_49 , 0 } ,
{ V_50 , V_58 } ,
{ V_52 , V_59 } ,
{ V_60 , 0 } ,
{ V_61 , V_62 } ,
{ V_49 , 1 } ,
} ;
static const struct V_27 V_63 [] = {
{ V_49 , 0 } ,
{ V_61 , 0 } ,
{ V_49 , 0 } ,
{ V_50 , V_64 } ,
{ V_52 , V_65 } ,
{ V_60 , 0 } ,
{ V_61 , V_66 } ,
{ V_49 , 1 } ,
} ;
static const struct V_27 V_67 [] = {
{ V_49 , 0 } ,
{ V_61 , 0 } ,
{ V_68 , 1 } ,
{ V_69 , 7 } ,
{ V_70 , 0x100 } ,
{ V_71 , 0x0 } ,
{ V_72 , 0x0 } ,
{ V_73 , 0x0 } ,
{ V_74 , 0x100 } ,
{ V_75 , 0x0 } ,
{ V_76 , 0x0 } ,
{ V_77 , 0x0 } ,
{ V_78 , 0x100 } ,
{ V_79 , 0x100 } ,
{ V_80 , 0x100 } ,
{ V_81 , 0x100 } ,
{ V_82 , 1 } ,
{ V_83 , 1 } ,
{ V_84 , 1 } ,
{ V_85 , 0 } ,
{ V_36 , 0 } ,
{ V_86 , 0x298 } ,
{ V_87 , 0x298 } ,
{ V_88 , 0x298 } ,
{ V_89 , 7 } ,
{ V_38 , 0 } ,
{ V_90 , 0x10 } ,
{ V_91 , V_92 } ,
{ V_93 , V_94 } ,
{ V_95 , V_96 } ,
{ V_97 , V_98 } ,
{ V_99 , 1 } ,
{ V_38 , 1 }
} ;
V_21 = F_11 ( V_6 , V_34 ,
F_15 ( V_34 ) ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_6 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_11 ( V_6 , V_57 ,
F_15 ( V_57 ) ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_6 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_11 ( V_6 , V_63 ,
F_15 ( V_63 ) ) ;
if ( V_21 )
return V_21 ;
V_21 = F_12 ( V_6 ) ;
if ( V_21 )
return V_21 ;
V_21 = F_11 ( V_6 , V_67 ,
F_15 ( V_67 ) ) ;
if ( V_21 )
return V_21 ;
return 0 ;
}
static int F_16 ( struct V_5 * V_6 ,
const struct V_100 * V_101 )
{
struct V_10 * V_10 ;
V_10 = F_17 ( sizeof( struct V_10 ) , V_102 ) ;
if ( ! V_10 )
return - V_103 ;
F_18 ( & V_10 -> V_13 ) ;
F_19 ( V_6 , V_10 ) ;
return 0 ;
}
static int F_20 ( struct V_5 * V_6 )
{
struct V_10 * V_10 =
F_3 ( V_6 ) ;
F_21 ( V_10 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
int V_21 , V_30 = 100 ;
struct V_104 * V_105 = F_23 ( & V_3 -> V_23 ) ;
struct V_1 * V_106 = F_1 ( V_3 ) ;
if ( V_3 -> V_107 ) {
V_21 = V_3 -> V_107 ( V_3 ) ;
if ( V_21 )
return V_21 ;
}
F_24 ( V_106 -> V_108 , 0 ) ;
F_13 ( 1 ) ;
F_24 ( V_106 -> V_108 , 1 ) ;
while ( ! F_25 ( V_106 -> V_109 ) ) {
if ( ! V_30 -- ) {
F_8 ( & V_3 -> V_23 , L_4
L_5 ) ;
return - V_31 ;
}
F_13 ( 5 ) ;
}
F_13 ( 1000 ) ;
V_21 = F_26 ( V_3 ) ;
if ( V_21 ) {
F_8 ( & V_3 -> V_23 , L_6 ) ;
goto V_110;
}
V_21 = F_14 ( V_105 -> V_111 ) ;
if ( V_21 )
goto V_25;
V_3 -> V_112 = V_113 ;
return V_21 ;
V_25:
F_27 ( V_3 ) ;
V_110:
if ( V_3 -> V_114 )
V_3 -> V_114 ( V_3 ) ;
return V_21 ;
}
static void F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_106 = F_1 ( V_3 ) ;
F_27 ( V_3 ) ;
F_24 ( V_106 -> V_109 , 0 ) ;
F_24 ( V_106 -> V_108 , 0 ) ;
if ( V_3 -> V_114 )
V_3 -> V_114 ( V_3 ) ;
}
static int F_29 ( struct V_2 * V_3 )
{
struct V_104 * V_105 ;
struct V_1 * V_106 = F_1 ( V_3 ) ;
struct V_115 * V_19 ;
struct V_5 * V_111 ;
int V_21 = 0 , V_116 ;
V_3 -> V_117 . V_118 = V_119 ;
V_105 = F_17 ( sizeof( struct V_104 ) , V_102 ) ;
if ( ! V_105 )
return - V_103 ;
F_18 ( & V_105 -> V_120 ) ;
V_116 = V_106 -> V_116 ;
V_19 = F_30 ( V_116 ) ;
if ( ! V_19 ) {
F_8 ( & V_3 -> V_23 , L_7 ) ;
V_21 = - V_121 ;
goto V_25;
}
V_111 = F_31 ( V_19 , & V_122 ) ;
if ( ! V_111 ) {
F_8 ( & V_3 -> V_23 , L_8
L_9 ) ;
V_21 = - V_121 ;
goto V_25;
}
V_105 -> V_111 = V_111 ;
F_32 ( & V_3 -> V_23 , V_105 ) ;
return V_21 ;
V_25:
F_21 ( V_105 ) ;
return V_21 ;
}
static void F_33 ( struct V_2 * V_3 )
{
struct V_104 * V_105 = F_23 ( & V_3 -> V_23 ) ;
F_34 ( V_105 -> V_111 ) ;
F_32 ( & V_3 -> V_23 , NULL ) ;
F_9 ( & V_3 -> V_23 , L_10 ) ;
F_21 ( V_105 ) ;
}
static int F_35 ( struct V_2 * V_3 )
{
struct V_104 * V_105 = F_23 ( & V_3 -> V_23 ) ;
int V_21 ;
F_9 ( & V_3 -> V_23 , L_11 ) ;
F_4 ( & V_105 -> V_120 ) ;
if ( V_3 -> V_112 != V_123 ) {
F_6 ( & V_105 -> V_120 ) ;
return - V_124 ;
}
V_21 = F_22 ( V_3 ) ;
F_6 ( & V_105 -> V_120 ) ;
return V_21 ;
}
static void F_36 ( struct V_2 * V_3 )
{
struct V_104 * V_105 = F_23 ( & V_3 -> V_23 ) ;
F_4 ( & V_105 -> V_120 ) ;
if ( V_3 -> V_112 == V_113 )
F_28 ( V_3 ) ;
V_3 -> V_112 = V_123 ;
F_6 ( & V_105 -> V_120 ) ;
F_9 ( & V_3 -> V_23 , L_12 ) ;
}
static int F_37 ( struct V_2 * V_3 )
{
struct V_104 * V_105 = F_23 ( & V_3 -> V_23 ) ;
F_4 ( & V_105 -> V_120 ) ;
if ( V_3 -> V_112 != V_113 ) {
F_6 ( & V_105 -> V_120 ) ;
F_8 ( & V_3 -> V_23 , L_13
L_14 ) ;
return - V_124 ;
}
F_28 ( V_3 ) ;
V_3 -> V_112 = V_125 ;
F_6 ( & V_105 -> V_120 ) ;
F_9 ( & V_3 -> V_23 , L_15 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_104 * V_105 = F_23 ( & V_3 -> V_23 ) ;
int V_21 ;
F_4 ( & V_105 -> V_120 ) ;
if ( V_3 -> V_112 != V_125 ) {
F_6 ( & V_105 -> V_120 ) ;
F_8 ( & V_3 -> V_23 , L_16
L_14 ) ;
return - V_124 ;
}
V_21 = F_22 ( V_3 ) ;
F_6 ( & V_105 -> V_120 ) ;
F_9 ( & V_3 -> V_23 , L_17 ) ;
return V_21 ;
}
static void F_39 ( struct V_2 * V_3 ,
T_3 * V_126 , T_3 * V_127 )
{
* V_126 = V_3 -> V_117 . V_118 . V_128 ;
* V_127 = V_3 -> V_117 . V_118 . V_129 ;
}
static int T_4 F_40 ( void )
{
int V_21 = 0 ;
V_21 = F_41 ( & V_130 ) ;
if ( V_21 ) {
F_42 ( V_131 L_18 \
L_19 ) ;
return V_21 ;
}
V_21 = F_43 ( & V_132 ) ;
if ( V_21 )
F_44 ( & V_130 ) ;
return V_21 ;
}
static void T_5 F_45 ( void )
{
F_44 ( & V_130 ) ;
F_46 ( & V_132 ) ;
}
