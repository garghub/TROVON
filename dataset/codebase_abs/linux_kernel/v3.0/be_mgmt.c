unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 = 0 ;
F_2 ( V_10 , L_1 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_14 ,
V_15 ,
sizeof( * V_8 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_11 ( struct V_1 * V_2 ,
T_1 V_16 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
unsigned int V_9 = 0 ;
struct V_19 * V_8 ;
struct V_20 * V_21 ;
struct V_22 * V_23 ;
F_2 ( V_10 , L_2 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_18 -> V_24 = sizeof( * V_21 ) ;
V_8 = V_18 -> V_25 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 = F_6 ( V_2 ) ;
V_23 = F_12 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_14 ,
V_26 ,
sizeof( * V_21 ) ) ;
V_8 -> V_27 = V_16 ;
V_23 -> V_28 = F_13 ( F_14 ( V_18 -> V_29 ) ) ;
V_23 -> V_30 = F_13 ( V_18 -> V_29 & 0xFFFFFFFF ) ;
V_23 -> V_31 = F_13 ( V_18 -> V_24 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
int F_15 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_16 ( & V_4 -> V_32 ) ;
struct V_33 * V_8 = F_7 ( V_6 ) ;
int V_34 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_35 ,
V_36 , sizeof( * V_8 ) ) ;
V_34 = F_17 ( V_4 ) ;
if ( ! V_34 ) {
struct V_33 * V_37 ;
V_37 = V_8 ;
V_2 -> V_38 . V_39 = V_37 -> V_39 ;
V_2 -> V_38 . V_40 =
V_37 -> V_41 [ 0 ] . V_42 ;
V_2 -> V_38 . V_43 =
V_37 -> V_41 [ 0 ] . V_44 ;
V_2 -> V_38 . V_45 =
V_37 -> V_41 [ 0 ] . V_46 ;
V_2 -> V_38 . V_47 =
V_37 -> V_41 [ 0 ] . V_48 ;
if ( V_2 -> V_38 . V_47 > ( V_49 / 2 ) ) {
F_2 ( V_10 ,
L_3
L_4 ,
V_2 -> V_38 . V_47 ,
V_49 ) ;
V_2 -> V_38 . V_47 = V_49 / 2 ;
}
} else {
F_18 ( V_50 , V_2 -> V_51 ,
L_5 ) ;
}
F_5 ( & V_4 -> V_11 ) ;
return V_34 ;
}
int F_19 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_17 V_18 ;
struct V_5 * V_6 = F_16 ( & V_4 -> V_32 ) ;
struct V_52 * V_8 ;
struct V_22 * V_23 = F_12 ( V_6 ) ;
int V_34 = 0 ;
V_18 . V_25 = F_20 ( V_4 -> V_53 ,
sizeof( struct V_52 ) ,
& V_18 . V_29 ) ;
if ( V_18 . V_25 == NULL ) {
F_2 ( V_54 ,
L_6
L_7 ) ;
return - V_55 ;
}
V_18 . V_24 = sizeof( struct V_52 ) ;
V_8 = V_18 . V_25 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
F_3 ( & V_4 -> V_11 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_35 ,
V_56 , sizeof( * V_8 ) ) ;
V_23 -> V_28 = F_13 ( F_14 ( V_18 . V_29 ) ) ;
V_23 -> V_30 = F_13 ( V_18 . V_29 & 0xFFFFFFFF ) ;
V_23 -> V_31 = F_13 ( V_18 . V_24 ) ;
V_34 = F_17 ( V_4 ) ;
if ( ! V_34 ) {
struct V_57 * V_21 = V_18 . V_25 ;
F_2 ( V_10 , L_8 ,
V_21 -> V_58 . V_59 . V_60 ) ;
F_2 ( V_10 , L_9 ,
V_21 -> V_58 . V_59 . V_61 ) ;
F_2 ( V_10 ,
L_10 ) ;
V_2 -> V_38 . V_62 =
V_21 -> V_58 . V_59 . V_62 ;
F_2 ( V_10 , L_11 ,
V_2 -> V_38 . V_62 ) ;
} else
F_2 ( V_54 , L_12 ) ;
F_5 ( & V_4 -> V_11 ) ;
if ( V_18 . V_25 )
F_21 ( V_4 -> V_53 , V_18 . V_24 ,
V_18 . V_25 , V_18 . V_29 ) ;
return V_34 ;
}
int F_22 ( struct V_1 * V_2 , unsigned short V_63 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 = F_6 ( V_2 ) ;
struct V_64 * V_8 = F_7 ( V_6 ) ;
int V_34 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_65 ,
V_66 , sizeof( * V_8 ) ) ;
V_8 -> V_63 = V_63 ;
V_8 -> V_67 = F_23 ( F_24 ( V_2 ) ) ;
V_8 -> V_68 = F_23 ( F_25 ( V_2 ) ) ;
V_34 = F_26 ( V_2 ) ;
if ( V_34 )
F_18 ( V_50 , V_2 -> V_51 ,
L_13 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_34 ;
}
unsigned int F_27 ( struct V_1 * V_2 ,
struct V_69 * V_70 ,
unsigned int V_71 , unsigned int V_72 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_22 * V_23 ;
struct V_73 * V_8 ;
unsigned int V_74 , V_9 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_8 = V_18 -> V_25 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 = F_6 ( V_2 ) ;
V_23 = F_12 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_65 ,
V_75 ,
sizeof( * V_8 ) ) ;
V_8 -> V_76 = 0 ;
V_8 -> V_77 = V_78 ;
for ( V_74 = 0 ; V_74 < V_71 ; V_74 ++ ) {
V_8 -> V_79 [ V_74 ] . V_80 = V_70 -> V_80 ;
V_8 -> V_79 [ V_74 ] . V_72 = V_70 -> V_72 ;
V_8 -> V_44 ++ ;
V_70 ++ ;
}
V_23 -> V_28 = F_13 ( F_14 ( V_18 -> V_29 ) ) ;
V_23 -> V_30 = F_13 ( V_18 -> V_29 & 0xFFFFFFFF ) ;
V_23 -> V_31 = F_13 ( V_18 -> V_24 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_28 ( struct V_1 * V_2 ,
struct V_81 * V_82 ,
unsigned short V_72 ,
unsigned short V_83 ,
unsigned short V_84 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_85 * V_8 ;
unsigned int V_9 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_6 -> V_12 |= V_9 ;
V_8 = F_7 ( V_6 ) ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_14 ,
V_86 ,
sizeof( * V_8 ) ) ;
V_8 -> V_27 = V_82 -> V_87 ;
V_8 -> V_72 = V_72 ;
if ( V_83 )
V_8 -> V_77 = V_88 ;
else
V_8 -> V_77 = V_89 ;
V_8 -> V_90 = V_84 ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_29 ( struct V_1 * V_2 ,
unsigned short V_72 , unsigned int V_91 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_92 * V_8 ;
unsigned int V_9 = 0 ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_93 ,
V_94 , sizeof( * V_8 ) ) ;
V_8 -> V_95 = ( unsigned short ) V_72 ;
V_8 -> V_96 = ( unsigned char ) V_91 ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
int F_30 ( struct V_1 * V_2 ,
struct V_97 * V_98 ,
struct V_81 * V_82 ,
struct V_17 * V_18 )
{
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_104 = (struct V_103 * ) V_98 ;
struct V_105 * V_106 = (struct V_105 * ) V_98 ;
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_107 * V_8 ;
unsigned short V_108 ;
unsigned short V_109 ;
struct V_110 V_111 = { 0 , 0 } ;
struct V_110 * V_112 ;
unsigned int V_9 = 0 ;
unsigned int V_74 ;
unsigned short V_72 = V_82 -> V_113 ;
struct V_22 * V_23 ;
V_100 = V_2 -> V_100 ;
V_102 = V_100 -> V_114 ;
V_108 = ( unsigned short ) F_24 ( V_2 ) ;
V_109 = ( unsigned short ) F_25 ( V_2 ) ;
V_112 = & V_111 ;
F_31 ( V_2 , V_112 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
memset ( V_6 , 0 , sizeof( * V_6 ) ) ;
V_23 = F_12 ( V_6 ) ;
V_8 = V_18 -> V_25 ;
memset ( V_8 , 0 , sizeof( * V_8 ) ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , false , 1 ) ;
F_9 ( & V_8 -> V_13 , V_65 ,
V_115 ,
sizeof( * V_8 ) ) ;
if ( V_98 -> V_116 == V_117 ) {
T_2 V_118 = V_104 -> V_119 . V_118 ;
V_8 -> V_120 . V_121 = V_122 ;
V_8 -> V_120 . V_120 [ 0 ] = V_118 & 0x000000ff ;
V_8 -> V_120 . V_120 [ 1 ] = ( V_118 & 0x0000ff00 ) >> 8 ;
V_8 -> V_120 . V_120 [ 2 ] = ( V_118 & 0x00ff0000 ) >> 16 ;
V_8 -> V_120 . V_120 [ 3 ] = ( V_118 & 0xff000000 ) >> 24 ;
V_8 -> V_123 = F_32 ( V_104 -> V_124 ) ;
V_82 -> V_98 = V_104 -> V_119 . V_118 ;
V_82 -> V_125 = F_32 ( V_104 -> V_124 ) ;
V_82 -> V_121 = V_122 ;
} else if ( V_98 -> V_116 == V_126 ) {
V_8 -> V_120 . V_121 = V_127 ;
memcpy ( & V_8 -> V_120 . V_120 ,
& V_106 -> V_128 . V_129 . V_130 , 16 ) ;
V_8 -> V_123 = F_32 ( V_106 -> V_131 ) ;
V_82 -> V_125 = F_32 ( V_106 -> V_131 ) ;
memcpy ( & V_82 -> V_132 ,
& V_106 -> V_128 . V_129 . V_130 , 16 ) ;
V_82 -> V_121 = V_127 ;
} else{
F_18 ( V_133 , V_2 -> V_51 , L_14 ,
V_98 -> V_116 ) ;
F_5 ( & V_4 -> V_11 ) ;
F_33 ( & V_2 -> V_4 , V_9 ) ;
return - V_134 ;
}
V_8 -> V_72 = V_72 ;
V_74 = V_2 -> V_135 ++ ;
if ( V_2 -> V_135 == V_2 -> V_136 )
V_2 -> V_135 = 0 ;
V_8 -> V_137 = V_102 -> V_138 [ V_74 ] . V_95 ;
F_2 ( V_10 , L_15 , V_74 , V_8 -> V_137 ) ;
V_8 -> V_139 = V_108 ;
V_8 -> V_67 = V_108 ;
V_8 -> V_68 = V_109 ;
V_8 -> V_140 = 1 ;
V_8 -> V_141 . V_142 = V_112 -> V_142 ;
V_8 -> V_141 . V_143 = V_112 -> V_143 ;
V_23 -> V_28 = F_13 ( F_14 ( V_18 -> V_29 ) ) ;
V_23 -> V_30 = F_13 ( V_18 -> V_29 & 0xFFFFFFFF ) ;
V_23 -> V_31 = F_13 ( V_18 -> V_24 ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
unsigned int F_34 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 * V_6 ;
struct V_7 * V_8 ;
unsigned int V_9 = 0 ;
F_2 ( V_10 , L_16 ) ;
F_3 ( & V_4 -> V_11 ) ;
V_9 = F_4 ( V_2 ) ;
if ( ! V_9 ) {
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
V_6 = F_6 ( V_2 ) ;
V_8 = F_7 ( V_6 ) ;
V_6 -> V_12 |= V_9 ;
F_8 ( V_6 , sizeof( * V_8 ) , true , 0 ) ;
F_9 ( & V_8 -> V_13 , V_65 ,
V_144 ,
sizeof( * V_8 ) ) ;
F_10 ( V_2 ) ;
F_5 ( & V_4 -> V_11 ) ;
return V_9 ;
}
