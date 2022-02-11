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
V_11 -> V_75 . V_76 = & V_77 ;
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
goto V_88;
if ( V_11 -> V_75 . V_89 ) {
V_20 = F_36 ( V_11 , V_11 -> V_75 . V_89 ) ;
if ( V_20 )
goto V_90;
}
return 0 ;
V_90:
V_51 -> V_91 ( V_11 ) ;
V_88:
F_37 ( V_11 ) ;
F_38 ( V_11 ) ;
return V_20 ;
}
void
F_39 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_50 * V_51 = & V_17 -> V_52 . V_53 ;
F_40 ( V_11 ) ;
V_51 -> V_91 ( V_11 ) ;
F_37 ( V_11 ) ;
F_38 ( V_11 ) ;
}
int
F_41 ( struct V_10 * V_11 , int V_92 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_42 ( V_11 , V_93 , 0 ,
F_43 ( V_92 ) ) ;
else
F_44 ( V_11 , V_92 , V_94 ,
V_95 ) ;
return 0 ;
}
void
F_45 ( struct V_10 * V_11 , int V_92 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_42 ( V_11 , V_93 ,
F_43 ( V_92 ) , 0 ) ;
else
F_44 ( V_11 , V_92 , V_94 , 0 ) ;
}
static int
F_46 ( struct V_15 * V_96 ,
struct V_15 * V_97 )
{
int V_20 ;
V_20 = F_47 ( V_97 , V_98 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_48 ( & V_97 -> V_99 , false , false , false , 0 ) ;
if ( V_20 )
goto V_100;
V_20 = F_48 ( & V_96 -> V_99 , false , false , false , 0 ) ;
if ( V_20 )
goto V_101;
return 0 ;
V_101:
F_49 ( & V_97 -> V_99 ) ;
V_100:
F_50 ( V_97 ) ;
return V_20 ;
}
static void
F_51 ( struct V_15 * V_96 ,
struct V_15 * V_97 ,
struct V_102 * V_103 )
{
F_52 ( V_97 , V_103 ) ;
F_49 ( & V_97 -> V_99 ) ;
F_52 ( V_96 , V_103 ) ;
F_49 ( & V_96 -> V_99 ) ;
F_50 ( V_96 ) ;
}
static int
F_53 ( struct V_104 * V_105 ,
struct V_15 * V_96 ,
struct V_15 * V_97 ,
struct V_106 * V_107 ,
struct V_102 * * V_108 )
{
struct V_109 * V_110 = V_105 -> V_111 [ V_112 ] ;
struct V_16 * V_17 = V_105 -> V_11 -> V_18 ;
struct V_10 * V_11 = V_105 -> V_11 ;
unsigned long V_113 ;
int V_20 ;
F_54 ( & V_11 -> V_114 , V_113 ) ;
F_55 ( & V_107 -> V_115 , & V_110 -> V_116 ) ;
F_56 ( & V_11 -> V_114 , V_113 ) ;
V_20 = F_57 ( V_96 -> V_99 . V_117 , V_105 ) ;
if ( V_20 )
goto V_100;
V_20 = F_58 ( V_105 , 3 ) ;
if ( V_20 )
goto V_100;
if ( V_17 -> V_22 < V_43 ) {
F_59 ( V_105 , V_118 , V_119 , 1 ) ;
F_60 ( V_105 , 0x00000000 ) ;
F_60 ( V_105 , 0x00000000 ) ;
} else {
F_61 ( V_105 , 0 , V_120 , 1 ) ;
F_60 ( V_105 , 0 ) ;
F_62 ( V_105 , 0 , V_121 , 0x0000 ) ;
}
F_63 ( V_105 ) ;
V_20 = F_64 ( V_105 , V_108 ) ;
if ( V_20 )
goto V_100;
return 0 ;
V_100:
F_54 ( & V_11 -> V_114 , V_113 ) ;
F_65 ( & V_107 -> V_115 ) ;
F_56 ( & V_11 -> V_114 , V_113 ) ;
return V_20 ;
}
int
F_66 ( struct V_122 * V_92 , struct V_1 * V_4 ,
struct V_123 * V_124 )
{
struct V_10 * V_11 = V_92 -> V_11 ;
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_15 * V_96 = V_3 ( V_92 -> V_4 ) -> V_5 ;
struct V_15 * V_97 = V_3 ( V_4 ) -> V_5 ;
struct V_106 * V_107 ;
struct V_104 * V_105 = NULL ;
struct V_102 * V_103 ;
int V_20 ;
if ( ! V_17 -> V_125 )
return - V_126 ;
V_107 = F_15 ( sizeof( * V_107 ) , V_48 ) ;
if ( ! V_107 )
return - V_49 ;
V_20 = F_46 ( V_96 , V_97 ) ;
if ( V_20 )
goto V_127;
* V_107 = (struct V_106 )
{ { } , V_124 , F_67 ( V_92 ) -> V_128 ,
V_4 -> V_129 , V_4 -> V_40 [ 0 ] , V_92 -> V_130 , V_92 -> V_131 ,
V_97 -> V_99 . V_132 } ;
V_103 = V_97 -> V_99 . V_117 ;
if ( V_103 )
V_105 = F_68 ( V_103 -> V_125 ) ;
if ( ! V_105 )
V_105 = F_68 ( V_17 -> V_125 ) ;
F_69 ( & V_105 -> V_133 ) ;
if ( V_17 -> V_22 >= V_23 ) {
if ( V_17 -> V_22 >= V_38 )
V_20 = F_70 ( V_92 , V_4 , V_105 , 0 ) ;
else
V_20 = F_71 ( V_92 , V_4 , V_105 ) ;
if ( V_20 ) {
F_72 ( & V_105 ) ;
goto V_101;
}
}
V_20 = F_53 ( V_105 , V_96 , V_97 , V_107 , & V_103 ) ;
F_72 ( & V_105 ) ;
if ( V_20 )
goto V_101;
V_92 -> V_4 = V_4 ;
F_51 ( V_96 , V_97 , V_103 ) ;
F_73 ( & V_103 ) ;
return 0 ;
V_101:
F_51 ( V_96 , V_97 , NULL ) ;
V_127:
F_4 ( V_107 ) ;
return V_20 ;
}
int
F_74 ( struct V_104 * V_105 ,
struct V_106 * V_134 )
{
struct V_109 * V_110 = V_105 -> V_111 [ V_112 ] ;
struct V_10 * V_11 = V_105 -> V_11 ;
struct V_106 * V_107 ;
unsigned long V_113 ;
F_54 ( & V_11 -> V_114 , V_113 ) ;
if ( F_75 ( & V_110 -> V_116 ) ) {
F_11 ( V_11 , L_9 , V_105 -> V_135 ) ;
F_56 ( & V_11 -> V_114 , V_113 ) ;
return - V_36 ;
}
V_107 = F_76 ( & V_110 -> V_116 , struct V_106 , V_115 ) ;
if ( V_107 -> V_124 ) {
struct V_123 * V_136 = V_107 -> V_124 ;
struct V_137 V_138 ;
F_77 ( & V_138 ) ;
V_136 -> V_124 . V_139 = 0 ;
V_136 -> V_124 . V_140 = V_138 . V_140 ;
V_136 -> V_124 . V_141 = V_138 . V_141 ;
F_55 ( & V_136 -> V_19 . V_142 , & V_136 -> V_19 . V_8 -> V_143 ) ;
F_78 ( & V_136 -> V_19 . V_8 -> V_144 ) ;
}
F_65 ( & V_107 -> V_115 ) ;
if ( V_134 )
* V_134 = * V_107 ;
F_4 ( V_107 ) ;
F_56 ( & V_11 -> V_114 , V_113 ) ;
return 0 ;
}
int
F_79 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_145 * args )
{
struct V_15 * V_99 ;
int V_20 ;
args -> V_146 = F_80 ( args -> V_147 * ( args -> V_148 / 8 ) , 256 ) ;
args -> V_149 = args -> V_146 * args -> V_150 ;
args -> V_149 = F_80 ( args -> V_149 , V_151 ) ;
V_20 = F_81 ( V_11 , args -> V_149 , 0 , V_98 , 0 , 0 , & V_99 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_8 , V_99 -> V_6 , & args -> V_9 ) ;
F_2 ( V_99 -> V_6 ) ;
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
T_2 V_9 , T_3 * V_152 )
{
struct V_45 * V_6 ;
V_6 = F_13 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_99 = V_6 -> V_153 ;
* V_152 = V_99 -> V_99 . V_154 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_47 ;
}
