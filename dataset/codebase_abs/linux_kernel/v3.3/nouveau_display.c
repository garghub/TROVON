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
F_32 ( V_11 , V_70 ,
L_5 , 2 ) ;
V_51 -> V_69 -> V_71 [ 0 ] = 0 ;
V_51 -> V_69 -> V_71 [ 1 ] = 128 ;
V_51 -> V_72 =
F_32 ( V_11 , V_70 ,
L_6 , 2 ) ;
V_51 -> V_72 -> V_71 [ 0 ] = 0 ;
V_51 -> V_72 -> V_71 [ 1 ] = 128 ;
V_11 -> V_73 . V_74 = ( void * ) & V_75 ;
V_11 -> V_73 . V_76 = F_33 ( V_11 -> V_77 , 1 ) ;
V_11 -> V_73 . V_78 = 0 ;
V_11 -> V_73 . V_79 = 0 ;
if ( V_17 -> V_22 < V_80 ) {
V_11 -> V_73 . V_81 = 2048 ;
V_11 -> V_73 . V_82 = 2048 ;
} else
if ( V_17 -> V_22 < V_23 ) {
V_11 -> V_73 . V_81 = 4096 ;
V_11 -> V_73 . V_82 = 4096 ;
} else {
V_11 -> V_73 . V_81 = 8192 ;
V_11 -> V_73 . V_82 = 8192 ;
}
F_34 ( V_11 ) ;
F_26 ( V_11 ) ;
V_20 = V_51 -> V_83 ( V_11 ) ;
if ( V_20 )
return V_20 ;
if ( V_11 -> V_73 . V_84 ) {
V_20 = F_35 ( V_11 , V_11 -> V_73 . V_84 ) ;
if ( V_20 )
return V_20 ;
}
return V_20 ;
}
void
F_36 ( struct V_10 * V_11 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_50 * V_51 = & V_17 -> V_52 . V_53 ;
F_37 ( V_11 ) ;
V_51 -> V_85 ( V_11 ) ;
F_38 ( V_11 ) ;
F_39 ( V_11 ) ;
}
int
F_40 ( struct V_10 * V_11 , int V_86 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_41 ( V_11 , V_87 , 0 ,
F_42 ( V_86 ) ) ;
else
F_43 ( V_11 , V_86 , V_88 ,
V_89 ) ;
return 0 ;
}
void
F_44 ( struct V_10 * V_11 , int V_86 )
{
struct V_16 * V_17 = V_11 -> V_18 ;
if ( V_17 -> V_22 >= V_23 )
F_41 ( V_11 , V_87 ,
F_42 ( V_86 ) , 0 ) ;
else
F_43 ( V_11 , V_86 , V_88 , 0 ) ;
}
static int
F_45 ( struct V_15 * V_90 ,
struct V_15 * V_91 )
{
int V_20 ;
V_20 = F_46 ( V_91 , V_92 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_47 ( & V_91 -> V_93 , false , false , false , 0 ) ;
if ( V_20 )
goto V_94;
V_20 = F_47 ( & V_90 -> V_93 , false , false , false , 0 ) ;
if ( V_20 )
goto V_95;
return 0 ;
V_95:
F_48 ( & V_91 -> V_93 ) ;
V_94:
F_49 ( V_91 ) ;
return V_20 ;
}
static void
F_50 ( struct V_15 * V_90 ,
struct V_15 * V_91 ,
struct V_96 * V_97 )
{
F_51 ( V_91 , V_97 ) ;
F_48 ( & V_91 -> V_93 ) ;
F_51 ( V_90 , V_97 ) ;
F_48 ( & V_90 -> V_93 ) ;
F_49 ( V_90 ) ;
}
static int
F_52 ( struct V_98 * V_99 ,
struct V_15 * V_90 ,
struct V_15 * V_91 ,
struct V_100 * V_101 ,
struct V_96 * * V_102 )
{
struct V_16 * V_17 = V_99 -> V_11 -> V_18 ;
struct V_10 * V_11 = V_99 -> V_11 ;
unsigned long V_103 ;
int V_20 ;
F_53 ( & V_11 -> V_104 , V_103 ) ;
F_54 ( & V_101 -> V_105 , & V_99 -> V_106 . V_107 ) ;
F_55 ( & V_11 -> V_104 , V_103 ) ;
V_20 = F_56 ( V_90 -> V_93 . V_108 , V_99 ) ;
if ( V_20 )
goto V_94;
V_20 = F_57 ( V_99 , 2 ) ;
if ( V_20 )
goto V_94;
if ( V_17 -> V_22 < V_43 )
F_58 ( V_99 , V_109 , V_110 , 1 ) ;
else
F_59 ( V_99 , 2 , V_111 , 0x0500 , 1 ) ;
F_60 ( V_99 , 0 ) ;
F_61 ( V_99 ) ;
V_20 = F_62 ( V_99 , V_102 , true ) ;
if ( V_20 )
goto V_94;
return 0 ;
V_94:
F_53 ( & V_11 -> V_104 , V_103 ) ;
F_63 ( & V_101 -> V_105 ) ;
F_55 ( & V_11 -> V_104 , V_103 ) ;
return V_20 ;
}
int
F_64 ( struct V_112 * V_86 , struct V_1 * V_4 ,
struct V_113 * V_114 )
{
struct V_10 * V_11 = V_86 -> V_11 ;
struct V_16 * V_17 = V_11 -> V_18 ;
struct V_15 * V_90 = V_3 ( V_86 -> V_4 ) -> V_5 ;
struct V_15 * V_91 = V_3 ( V_4 ) -> V_5 ;
struct V_100 * V_101 ;
struct V_98 * V_99 ;
struct V_96 * V_97 ;
int V_20 ;
if ( ! V_17 -> V_115 )
return - V_116 ;
V_101 = F_15 ( sizeof( * V_101 ) , V_48 ) ;
if ( ! V_101 )
return - V_49 ;
V_20 = F_45 ( V_90 , V_91 ) ;
if ( V_20 )
goto V_117;
* V_101 = (struct V_100 )
{ { } , V_114 , F_65 ( V_86 ) -> V_118 ,
V_4 -> V_119 , V_4 -> V_40 [ 0 ] , V_86 -> V_120 , V_86 -> V_121 ,
V_91 -> V_93 . V_122 } ;
V_99 = F_66 ( V_91 -> V_93 . V_108 ) ;
if ( ! V_99 )
V_99 = F_67 ( V_17 -> V_115 ) ;
F_68 ( & V_99 -> V_123 ) ;
if ( V_17 -> V_22 >= V_23 ) {
if ( V_17 -> V_22 >= V_38 )
V_20 = F_69 ( V_86 , V_4 , V_99 , 0 ) ;
else
V_20 = F_70 ( V_86 , V_4 , V_99 ) ;
if ( V_20 ) {
F_71 ( & V_99 ) ;
goto V_95;
}
}
V_20 = F_52 ( V_99 , V_90 , V_91 , V_101 , & V_97 ) ;
F_71 ( & V_99 ) ;
if ( V_20 )
goto V_95;
V_86 -> V_4 = V_4 ;
F_50 ( V_90 , V_91 , V_97 ) ;
F_72 ( & V_97 ) ;
return 0 ;
V_95:
F_50 ( V_90 , V_91 , NULL ) ;
V_117:
F_4 ( V_101 ) ;
return V_20 ;
}
int
F_73 ( struct V_98 * V_99 ,
struct V_100 * V_124 )
{
struct V_10 * V_11 = V_99 -> V_11 ;
struct V_100 * V_101 ;
unsigned long V_103 ;
F_53 ( & V_11 -> V_104 , V_103 ) ;
if ( F_74 ( & V_99 -> V_106 . V_107 ) ) {
F_11 ( V_11 , L_7 , V_99 -> V_125 ) ;
F_55 ( & V_11 -> V_104 , V_103 ) ;
return - V_36 ;
}
V_101 = F_75 ( & V_99 -> V_106 . V_107 ,
struct V_100 , V_105 ) ;
if ( V_101 -> V_114 ) {
struct V_113 * V_126 = V_101 -> V_114 ;
struct V_127 V_128 ;
F_76 ( & V_128 ) ;
V_126 -> V_114 . V_129 = 0 ;
V_126 -> V_114 . V_130 = V_128 . V_130 ;
V_126 -> V_114 . V_131 = V_128 . V_131 ;
F_54 ( & V_126 -> V_19 . V_132 , & V_126 -> V_19 . V_8 -> V_133 ) ;
F_77 ( & V_126 -> V_19 . V_8 -> V_134 ) ;
}
F_63 ( & V_101 -> V_105 ) ;
if ( V_124 )
* V_124 = * V_101 ;
F_4 ( V_101 ) ;
F_55 ( & V_11 -> V_104 , V_103 ) ;
return 0 ;
}
int
F_78 ( struct V_7 * V_8 , struct V_10 * V_11 ,
struct V_135 * args )
{
struct V_15 * V_93 ;
int V_20 ;
args -> V_136 = F_79 ( args -> V_137 * ( args -> V_138 / 8 ) , 256 ) ;
args -> V_139 = args -> V_136 * args -> V_140 ;
args -> V_139 = F_79 ( args -> V_139 , V_141 ) ;
V_20 = F_80 ( V_11 , args -> V_139 , 0 , V_92 , 0 , 0 , & V_93 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_6 ( V_8 , V_93 -> V_6 , & args -> V_9 ) ;
F_2 ( V_93 -> V_6 ) ;
return V_20 ;
}
int
F_81 ( struct V_7 * V_8 , struct V_10 * V_11 ,
T_2 V_9 )
{
return F_82 ( V_8 , V_9 ) ;
}
int
F_83 ( struct V_7 * V_8 ,
struct V_10 * V_11 ,
T_2 V_9 , T_3 * V_142 )
{
struct V_45 * V_6 ;
V_6 = F_13 ( V_11 , V_8 , V_9 ) ;
if ( V_6 ) {
struct V_15 * V_93 = V_6 -> V_143 ;
* V_142 = V_93 -> V_93 . V_144 ;
F_2 ( V_6 ) ;
return 0 ;
}
return - V_47 ;
}
