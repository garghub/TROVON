static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
if ( V_4 -> V_5 )
F_2 ( V_4 -> V_5 -> V_6 ) ;
F_3 ( V_2 ) ;
F_4 ( V_4 ) ;
}
static int
F_5 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
unsigned int * V_9 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
return F_6 ( V_8 , V_4 -> V_5 -> V_6 , V_9 ) ;
}
int
F_7 ( struct V_10 * V_11 ,
struct V_3 * V_12 ,
struct V_13 * V_14 ,
struct V_15 * V_5 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_1 * V_4 = & V_12 -> V_19 ;
int V_20 ;
V_20 = F_8 ( V_11 , V_4 , & V_21 ) ;
if ( V_20 ) {
return V_20 ;
}
F_9 ( V_4 , V_14 ) ;
V_12 -> V_5 = V_5 ;
if ( V_17 -> V_22 >= V_23 ) {
T_1 V_24 = F_10 ( V_5 ) ;
if ( V_24 == 0x7a00 ||
V_24 == 0xfe00 )
V_12 -> V_25 = V_26 ;
else
if ( V_24 == 0x7000 )
V_12 -> V_25 = V_27 ;
else
V_12 -> V_25 = V_28 ;
switch ( V_4 -> V_29 ) {
case 8 : V_12 -> V_30 = V_31 ; break;
case 15 : V_12 -> V_30 = V_32 ; break;
case 16 : V_12 -> V_30 = V_33 ; break;
case 24 :
case 32 : V_12 -> V_30 = V_34 ; break;
case 30 : V_12 -> V_30 = V_35 ; break;
default:
F_11 ( V_11 , L_1 , V_4 -> V_29 ) ;
return - V_36 ;
}
if ( V_17 -> V_37 == 0x50 )
V_12 -> V_30 |= ( V_24 << 8 ) ;
if ( ! V_24 ) {
if ( V_17 -> V_22 < V_38 )
V_12 -> V_39 = 0x00100000 | V_4 -> V_40 [ 0 ] ;
else
V_12 -> V_39 = 0x01000000 | V_4 -> V_40 [ 0 ] ;
} else {
T_1 V_41 = V_5 -> V_42 ;
if ( V_17 -> V_22 >= V_43 )
V_41 >>= 4 ;
V_12 -> V_39 = ( ( V_4 -> V_40 [ 0 ] / 4 ) << 4 ) | V_41 ;
}
}
return 0 ;
}
static struct V_1 *
F_12 ( struct V_10 * V_11 ,
struct V_7 * V_8 ,
struct V_13 * V_14 )
{
struct V_3 * V_44 ;
struct V_45 * V_6 ;
int V_20 ;
V_6 = F_13 ( V_11 , V_8 , V_14 -> V_46 [ 0 ] ) ;
if ( ! V_6 )
return F_14 ( - V_47 ) ;
V_44 = F_15 ( sizeof( struct V_3 ) , V_48 ) ;
if ( ! V_44 )
return F_14 ( - V_49 ) ;
V_20 = F_7 ( V_11 , V_44 , V_14 , F_16 ( V_6 ) ) ;
if ( V_20 ) {
F_17 ( V_6 ) ;
return F_14 ( V_20 ) ;
}
return & V_44 -> V_19 ;
}
int
F_18 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_50 * V_51 = & V_17 -> V_52 . V_53 ;
struct V_54 * V_55 ;
int V_20 ;
V_20 = V_51 -> V_56 ( V_11 ) ;
if ( V_20 )
return V_20 ;
if ( F_19 ( V_11 , V_57 ) == 0 ) {
F_20 ( V_11 , V_57 , true ) ;
F_21 ( 300 ) ;
}
F_22 ( V_11 ) ;
F_23 (connector, &dev->mode_config.connector_list, head) {
struct V_58 * V_59 = V_58 ( V_55 ) ;
F_24 ( V_11 , 0 , V_59 -> V_60 , 0xff , true ) ;
}
return V_20 ;
}
void
F_25 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_50 * V_51 = & V_17 -> V_52 . V_53 ;
struct V_54 * V_55 ;
F_23 (connector, &dev->mode_config.connector_list, head) {
struct V_58 * V_59 = V_58 ( V_55 ) ;
F_24 ( V_11 , 0 , V_59 -> V_60 , 0xff , false ) ;
}
F_26 ( V_11 ) ;
V_51 -> V_61 ( V_11 ) ;
}
int
F_27 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_50 * V_51 = & V_17 -> V_52 . V_53 ;
int V_20 , V_62 ;
F_28 ( V_11 ) ;
F_29 ( V_11 ) ;
F_30 ( V_11 ) ;
if ( V_17 -> V_22 < V_23 )
V_62 = 0 ;
else
if ( V_17 -> V_22 < V_38 )
V_62 = 1 ;
else
V_62 = 2 ;
F_31 ( V_51 -> V_63 , V_62 , L_2 , V_64 ) ;
F_31 ( V_51 -> V_65 , V_62 , L_3 , V_66 ) ;
F_31 ( V_51 -> V_67 , V_62 , L_4 , V_68 ) ;
V_51 -> V_69 =
F_32 ( V_11 , 0 , L_5 , 0 , 128 ) ;
V_51 -> V_70 =
F_32 ( V_11 , 0 , L_6 , 0 , 128 ) ;
if ( V_62 == 1 ) {
V_51 -> V_71 =
F_33 ( V_11 , V_72 ,
L_7 , 2 ) ;
V_51 -> V_71 -> V_73 [ 0 ] = 0 ;
V_51 -> V_71 -> V_73 [ 1 ] = 180 ;
V_51 -> V_74 =
F_33 ( V_11 , V_72 ,
L_8 , 2 ) ;
V_51 -> V_74 -> V_73 [ 0 ] = 0 ;
V_51 -> V_74 -> V_73 [ 1 ] = 200 ;
}
V_11 -> V_75 . V_76 = ( void * ) & V_77 ;
V_11 -> V_75 . V_78 = F_34 ( V_11 -> V_79 , 1 ) ;
V_11 -> V_75 . V_80 = 0 ;
V_11 -> V_75 . V_81 = 0 ;
if ( V_17 -> V_22 < V_82 ) {
V_11 -> V_75 . V_83 = 2048 ;
V_11 -> V_75 . V_84 = 2048 ;
} else
if ( V_17 -> V_22 < V_23 ) {
V_11 -> V_75 . V_83 = 4096 ;
V_11 -> V_75 . V_84 = 4096 ;
} else {
V_11 -> V_75 . V_83 = 8192 ;
V_11 -> V_75 . V_84 = 8192 ;
}
V_11 -> V_75 . V_85 = 24 ;
V_11 -> V_75 . V_86 = 1 ;
F_35 ( V_11 ) ;
F_26 ( V_11 ) ;
V_20 = V_51 -> V_87 ( V_11 ) ;
if ( V_20 )
return V_20 ;
if ( V_11 -> V_75 . V_88 ) {
V_20 = F_36 ( V_11 , V_11 -> V_75 . V_88 ) ;
if ( V_20 )
return V_20 ;
}
return V_20 ;
}
void
F_37 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_50 * V_51 = & V_17 -> V_52 . V_53 ;
F_38 ( V_11 ) ;
V_51 -> V_89 ( V_11 ) ;
F_39 ( V_11 ) ;
F_40 ( V_11 ) ;
}
int
F_41 ( struct V_10 * V_11 , int V_90 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_42 ( V_11 , V_91 , 0 ,
F_43 ( V_90 ) ) ;
else
F_44 ( V_11 , V_90 , V_92 ,
V_93 ) ;
return 0 ;
}
void
F_45 ( struct V_10 * V_11 , int V_90 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_42 ( V_11 , V_91 ,
F_43 ( V_90 ) , 0 ) ;
else
F_44 ( V_11 , V_90 , V_92 , 0 ) ;
}
static int
F_46 ( struct V_15 * V_94 ,
struct V_15 * V_95 )
{
int V_20 ;
V_20 = F_47 ( V_95 , V_96 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_48 ( & V_95 -> V_97 , false , false , false , 0 ) ;
if ( V_20 )
goto V_98;
V_20 = F_48 ( & V_94 -> V_97 , false , false , false , 0 ) ;
if ( V_20 )
goto V_99;
return 0 ;
V_99:
F_49 ( & V_95 -> V_97 ) ;
V_98:
F_50 ( V_95 ) ;
return V_20 ;
}
static void
F_51 ( struct V_15 * V_94 ,
struct V_15 * V_95 ,
struct V_100 * V_101 )
{
F_52 ( V_95 , V_101 ) ;
F_49 ( & V_95 -> V_97 ) ;
F_52 ( V_94 , V_101 ) ;
F_49 ( & V_94 -> V_97 ) ;
F_50 ( V_94 ) ;
}
static int
F_53 ( struct V_102 * V_103 ,
struct V_15 * V_94 ,
struct V_15 * V_95 ,
struct V_104 * V_105 ,
struct V_100 * * V_106 )
{
struct V_16 * V_17 = V_103 -> V_11 -> V_18 ;
struct V_10 * V_11 = V_103 -> V_11 ;
unsigned long V_107 ;
int V_20 ;
F_54 ( & V_11 -> V_108 , V_107 ) ;
F_55 ( & V_105 -> V_109 , & V_103 -> V_110 . V_111 ) ;
F_56 ( & V_11 -> V_108 , V_107 ) ;
V_20 = F_57 ( V_94 -> V_97 . V_112 , V_103 ) ;
if ( V_20 )
goto V_98;
V_20 = F_58 ( V_103 , 3 ) ;
if ( V_20 )
goto V_98;
if ( V_17 -> V_22 < V_43 ) {
F_59 ( V_103 , V_113 , V_114 , 1 ) ;
F_60 ( V_103 , 0x00000000 ) ;
F_60 ( V_103 , 0x00000000 ) ;
} else {
F_61 ( V_103 , 2 , 0 , V_115 , 1 ) ;
F_60 ( V_103 , ++ V_103 -> V_101 . V_116 ) ;
F_61 ( V_103 , 8 , 0 , V_117 , 0x0000 ) ;
}
F_62 ( V_103 ) ;
V_20 = F_63 ( V_103 , V_106 , true ) ;
if ( V_20 )
goto V_98;
return 0 ;
V_98:
F_54 ( & V_11 -> V_108 , V_107 ) ;
F_64 ( & V_105 -> V_109 ) ;
F_56 ( & V_11 -> V_108 , V_107 ) ;
return V_20 ;
}
int
F_65 ( struct V_118 * V_90 , struct V_1 * V_4 ,
struct V_119 * V_120 )
{
struct V_10 * V_11 = V_90 -> V_11 ;
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_15 * V_94 = V_3 ( V_90 -> V_4 ) -> V_5 ;
struct V_15 * V_95 = V_3 ( V_4 ) -> V_5 ;
struct V_104 * V_105 ;
struct V_102 * V_103 ;
struct V_100 * V_101 ;
int V_20 ;
if ( ! V_17 -> V_121 )
return - V_122 ;
V_105 = F_15 ( sizeof( * V_105 ) , V_48 ) ;
if ( ! V_105 )
return - V_49 ;
V_20 = F_46 ( V_94 , V_95 ) ;
if ( V_20 )
goto V_123;
* V_105 = (struct V_104 )
{ { } , V_120 , F_66 ( V_90 ) -> V_124 ,
V_4 -> V_125 , V_4 -> V_40 [ 0 ] , V_90 -> V_126 , V_90 -> V_127 ,
V_95 -> V_97 . V_128 } ;
V_103 = F_67 ( V_95 -> V_97 . V_112 ) ;
if ( ! V_103 )
V_103 = F_68 ( V_17 -> V_121 ) ;
F_69 ( & V_103 -> V_129 ) ;
if ( V_17 -> V_22 >= V_23 ) {
if ( V_17 -> V_22 >= V_38 )
V_20 = F_70 ( V_90 , V_4 , V_103 , 0 ) ;
else
V_20 = F_71 ( V_90 , V_4 , V_103 ) ;
if ( V_20 ) {
F_72 ( & V_103 ) ;
goto V_99;
}
}
V_20 = F_53 ( V_103 , V_94 , V_95 , V_105 , & V_101 ) ;
F_72 ( & V_103 ) ;
if ( V_20 )
goto V_99;
V_90 -> V_4 = V_4 ;
F_51 ( V_94 , V_95 , V_101 ) ;
F_73 ( & V_101 ) ;
return 0 ;
V_99:
F_51 ( V_94 , V_95 , NULL ) ;
V_123:
F_4 ( V_105 ) ;
return V_20 ;
}
int
F_74 ( struct V_102 * V_103 ,
struct V_104 * V_130 )
{
struct V_10 * V_11 = V_103 -> V_11 ;
struct V_104 * V_105 ;
unsigned long V_107 ;
F_54 ( & V_11 -> V_108 , V_107 ) ;
if ( F_75 ( & V_103 -> V_110 . V_111 ) ) {
F_11 ( V_11 , L_9 , V_103 -> V_131 ) ;
F_56 ( & V_11 -> V_108 , V_107 ) ;
return - V_36 ;
}
V_105 = F_76 ( & V_103 -> V_110 . V_111 ,
struct V_104 , V_109 ) ;
if ( V_105 -> V_120 ) {
struct V_119 * V_132 = V_105 -> V_120 ;
struct V_133 V_134 ;
F_77 ( & V_134 ) ;
V_132 -> V_120 . V_116 = 0 ;
V_132 -> V_120 . V_135 = V_134 . V_135 ;
V_132 -> V_120 . V_136 = V_134 . V_136 ;
F_55 ( & V_132 -> V_19 . V_137 , & V_132 -> V_19 . V_8 -> V_138 ) ;
F_78 ( & V_132 -> V_19 . V_8 -> V_139 ) ;
}
F_64 ( & V_105 -> V_109 ) ;
if ( V_130 )
* V_130 = * V_105 ;
F_4 ( V_105 ) ;
F_56 ( & V_11 -> V_108 , V_107 ) ;
return 0 ;
}
int
F_79 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_140 * args )
{
struct V_15 * V_97 ;
int V_20 ;
args -> V_141 = F_80 ( args -> V_142 * ( args -> V_143 / 8 ) , 256 ) ;
args -> V_144 = args -> V_141 * args -> V_145 ;
args -> V_144 = F_80 ( args -> V_144 , V_146 ) ;
V_20 = F_81 ( V_11 , args -> V_144 , 0 , V_96 , 0 , 0 , & V_97 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_8 , V_97 -> V_6 , & args -> V_9 ) ;
F_2 ( V_97 -> V_6 ) ;
return V_20 ;
}
int
F_82 ( struct V_7 * V_8 , struct V_10 * V_11 ,
T_2 V_9 )
{
return F_83 ( V_8 , V_9 ) ;
}
int
F_84 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_147 )
{
struct V_45 * V_6 ;
V_6 = F_13 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_97 = V_6 -> V_148 ;
* V_147 = V_97 -> V_97 . V_149 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_47 ;
}
