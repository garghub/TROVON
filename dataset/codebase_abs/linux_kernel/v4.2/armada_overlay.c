static void
F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_2 -> V_5 , V_4 -> V_6 + V_7 ) ;
F_2 ( V_2 -> V_8 , V_4 -> V_6 + V_9 ) ;
F_2 ( V_2 -> V_10 , V_4 -> V_6 + V_11 ) ;
F_2 ( V_2 -> V_12 << 16 | V_2 -> V_13 ,
V_4 -> V_6 + V_14 ) ;
F_2 ( V_2 -> V_15 << 16 ,
V_4 -> V_6 + V_16 ) ;
F_2 ( 0x00002000 , V_4 -> V_6 + V_17 ) ;
F_3 ( & V_4 -> V_18 ) ;
F_4 ( V_2 -> V_19 | V_20 ,
V_21 | V_22 | V_23 ,
V_4 -> V_6 + V_24 ) ;
F_4 ( V_25 , 0 , V_4 -> V_6 + V_26 ) ;
F_5 ( & V_4 -> V_18 ) ;
}
static void F_6 ( struct V_3 * V_4 , void * V_27 )
{
struct V_28 * V_29 = V_27 ;
struct V_30 * V_31 ;
F_7 ( V_4 , V_29 -> V_32 . V_33 ) ;
F_8 ( & V_29 -> V_34 ) ;
V_31 = V_29 -> V_35 ;
V_29 -> V_35 = NULL ;
F_9 ( & V_29 -> V_34 ) ;
if ( V_31 )
F_10 ( V_4 -> V_36 . V_37 , V_31 ) ;
F_11 ( & V_29 -> V_32 . V_38 ) ;
}
static int
F_12 ( struct V_39 * V_40 , struct V_41 * V_36 ,
struct V_30 * V_31 ,
int V_42 , int V_43 , unsigned V_44 , unsigned V_45 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 , T_1 V_49 )
{
struct V_28 * V_29 = F_13 ( V_40 ) ;
struct V_3 * V_4 = F_14 ( V_36 ) ;
struct V_50 V_51 = {
. V_52 = V_46 ,
. y1 = V_47 ,
. V_53 = V_46 + V_48 ,
. V_54 = V_47 + V_49 ,
} ;
struct V_50 V_55 = {
. V_52 = V_42 ,
. y1 = V_43 ,
. V_53 = V_42 + V_44 ,
. V_54 = V_43 + V_45 ,
} ;
const struct V_50 V_56 = {
. V_53 = V_36 -> V_57 . V_58 ,
. V_54 = V_36 -> V_57 . V_59 ,
} ;
T_1 V_60 , V_61 ;
unsigned V_62 = 0 ;
bool V_63 ;
int V_64 ;
V_64 = F_15 ( V_40 , V_36 , V_31 , & V_51 , & V_55 , & V_56 ,
0 , V_65 , true , false , & V_63 ) ;
if ( V_64 )
return V_64 ;
V_61 = F_16 ( F_17 ( V_31 ) -> V_66 ) |
F_18 ( F_17 ( V_31 ) -> V_67 ) |
V_68 | V_69 | V_70 ;
if ( ! V_63 )
V_61 &= ~ V_70 ;
if ( ! V_4 -> V_40 ) {
V_4 -> V_40 = V_40 ;
F_1 ( & V_29 -> V_2 , V_4 ) ;
}
if ( V_40 -> V_31 == V_31 && V_29 -> V_61 == V_61 ) {
V_60 = ( F_19 ( & V_51 ) & 0xffff0000 ) |
F_20 ( & V_51 ) >> 16 ;
V_29 -> V_71 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_72 ) ;
V_60 = F_19 ( & V_55 ) << 16 | F_20 ( & V_55 ) ;
V_29 -> V_73 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_74 ) ;
V_60 = V_55 . y1 << 16 | V_55 . V_52 ;
V_29 -> V_75 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_76 ) ;
return 0 ;
} else if ( ~ V_29 -> V_61 & V_61 & V_70 ) {
F_4 ( 0 , V_77 | V_78 ,
V_4 -> V_6 + V_79 ) ;
}
F_21 ( V_29 -> V_32 . V_38 ,
F_22 ( & V_29 -> V_32 . V_80 . V_81 ) ,
V_82 / 25 ) ;
if ( V_40 -> V_31 != V_31 ) {
struct V_83 * V_84 = F_23 ( V_31 ) ;
T_1 V_85 [ 3 ] , V_86 ;
int V_87 , V_88 , V_89 ;
F_24 ( V_31 ) ;
if ( V_40 -> V_31 ) {
struct V_30 * V_90 ;
F_3 ( & V_29 -> V_34 ) ;
V_90 = V_29 -> V_35 ;
V_29 -> V_35 = V_40 -> V_31 ;
F_5 ( & V_29 -> V_34 ) ;
if ( V_90 )
F_10 ( V_4 -> V_36 . V_37 ,
V_90 ) ;
}
V_47 = V_51 . y1 >> 16 ;
V_46 = V_51 . V_52 >> 16 ;
V_86 = V_31 -> V_86 ;
V_89 = F_25 ( V_86 ) ;
V_88 = F_26 ( V_86 ) ;
if ( V_46 & ( V_89 - 1 ) && V_88 == 1 )
V_61 ^= F_18 ( V_91 ) ;
for ( V_87 = 0 ; V_87 < V_88 ; V_87 ++ )
V_85 [ V_87 ] = V_84 -> V_92 + V_31 -> V_93 [ V_87 ] +
V_47 * V_31 -> V_94 [ V_87 ] +
V_46 * F_27 ( V_86 , V_87 ) ;
for (; V_87 < F_28 ( V_85 ) ; V_87 ++ )
V_85 [ V_87 ] = 0 ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_85 [ 0 ] ,
V_95 ) ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_85 [ 1 ] ,
V_96 ) ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_85 [ 2 ] ,
V_97 ) ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_85 [ 0 ] ,
V_98 ) ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_85 [ 1 ] ,
V_99 ) ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_85 [ 2 ] ,
V_100 ) ;
V_60 = V_31 -> V_94 [ 0 ] << 16 | V_31 -> V_94 [ 0 ] ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_60 ,
V_101 ) ;
V_60 = V_31 -> V_94 [ 1 ] << 16 | V_31 -> V_94 [ 2 ] ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_60 ,
V_102 ) ;
}
V_60 = ( F_19 ( & V_51 ) & 0xffff0000 ) | F_20 ( & V_51 ) >> 16 ;
if ( V_29 -> V_71 != V_60 ) {
V_29 -> V_71 = V_60 ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_60 ,
V_72 ) ;
}
V_60 = F_19 ( & V_55 ) << 16 | F_20 ( & V_55 ) ;
if ( V_29 -> V_73 != V_60 ) {
V_29 -> V_73 = V_60 ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_60 ,
V_74 ) ;
}
V_60 = V_55 . y1 << 16 | V_55 . V_52 ;
if ( V_29 -> V_75 != V_60 ) {
V_29 -> V_75 = V_60 ;
F_29 ( V_29 -> V_32 . V_33 , V_62 , V_60 ,
V_76 ) ;
}
if ( V_29 -> V_61 != V_61 ) {
V_29 -> V_61 = V_61 ;
F_30 ( V_29 -> V_32 . V_33 , V_62 , V_61 ,
V_68 | V_103 | V_104 |
V_69 | V_105 |
F_18 ( V_106 | V_91 | V_107 |
V_108 ) | V_70 ,
V_109 ) ;
}
if ( V_62 ) {
F_31 ( V_29 -> V_32 . V_33 , V_62 ) ;
F_32 ( V_4 , & V_29 -> V_32 . V_80 ) ;
}
return 0 ;
}
static int F_33 ( struct V_39 * V_40 )
{
struct V_28 * V_29 = F_13 ( V_40 ) ;
struct V_30 * V_31 ;
struct V_3 * V_4 ;
if ( ! V_29 -> V_6 . V_36 )
return 0 ;
V_4 = F_14 ( V_29 -> V_6 . V_36 ) ;
V_4 -> V_40 = NULL ;
F_3 ( & V_4 -> V_18 ) ;
F_34 ( V_4 , & V_29 -> V_32 . V_80 ) ;
F_4 ( 0 , V_70 , V_4 -> V_6 + V_109 ) ;
V_29 -> V_61 = 0 ;
F_5 ( & V_4 -> V_18 ) ;
F_4 ( V_77 | V_78 , 0 ,
V_4 -> V_6 + V_79 ) ;
if ( V_40 -> V_31 )
F_35 ( V_40 -> V_31 ) ;
F_3 ( & V_29 -> V_34 ) ;
V_31 = V_29 -> V_35 ;
V_29 -> V_35 = NULL ;
F_5 ( & V_29 -> V_34 ) ;
if ( V_31 )
F_35 ( V_31 ) ;
return 0 ;
}
static void F_36 ( struct V_39 * V_40 )
{
struct V_28 * V_29 = F_13 ( V_40 ) ;
F_37 ( V_40 ) ;
F_38 ( V_29 ) ;
}
static int F_39 ( struct V_39 * V_40 ,
struct V_110 * V_111 , T_2 V_60 )
{
struct V_112 * V_113 = V_40 -> V_37 -> V_114 ;
struct V_28 * V_29 = F_13 ( V_40 ) ;
bool V_115 = false ;
if ( V_111 == V_113 -> V_116 ) {
#define F_40 ( T_3 ) ((v) << 24 | (v) << 16 | (v) << 8)
V_29 -> V_2 . V_5 = F_40 ( F_41 ( V_60 ) ) ;
V_29 -> V_2 . V_8 = F_40 ( F_42 ( V_60 ) ) ;
V_29 -> V_2 . V_10 = F_40 ( F_43 ( V_60 ) ) ;
#undef F_40
V_115 = true ;
} else if ( V_111 == V_113 -> V_117 ) {
V_29 -> V_2 . V_5 &= ~ 0x00ff0000 ;
V_29 -> V_2 . V_5 |= F_41 ( V_60 ) << 16 ;
V_29 -> V_2 . V_8 &= ~ 0x00ff0000 ;
V_29 -> V_2 . V_8 |= F_42 ( V_60 ) << 16 ;
V_29 -> V_2 . V_10 &= ~ 0x00ff0000 ;
V_29 -> V_2 . V_10 |= F_43 ( V_60 ) << 16 ;
V_115 = true ;
} else if ( V_111 == V_113 -> V_118 ) {
V_29 -> V_2 . V_5 &= ~ 0xff000000 ;
V_29 -> V_2 . V_5 |= F_41 ( V_60 ) << 24 ;
V_29 -> V_2 . V_8 &= ~ 0xff000000 ;
V_29 -> V_2 . V_8 |= F_42 ( V_60 ) << 24 ;
V_29 -> V_2 . V_10 &= ~ 0xff000000 ;
V_29 -> V_2 . V_10 |= F_43 ( V_60 ) << 24 ;
V_115 = true ;
} else if ( V_111 == V_113 -> V_119 ) {
V_29 -> V_2 . V_5 &= ~ 0x0000ff00 ;
V_29 -> V_2 . V_5 |= F_41 ( V_60 ) << 8 ;
V_29 -> V_2 . V_8 &= ~ 0x0000ff00 ;
V_29 -> V_2 . V_8 |= F_42 ( V_60 ) << 8 ;
V_29 -> V_2 . V_10 &= ~ 0x0000ff00 ;
V_29 -> V_2 . V_10 |= F_43 ( V_60 ) << 8 ;
V_115 = true ;
} else if ( V_111 == V_113 -> V_120 ) {
V_29 -> V_2 . V_5 &= ~ 0x000000ff ;
V_29 -> V_2 . V_5 |= F_41 ( V_60 ) ;
V_29 -> V_2 . V_8 &= ~ 0x000000ff ;
V_29 -> V_2 . V_8 |= F_42 ( V_60 ) ;
V_29 -> V_2 . V_10 &= ~ 0x000000ff ;
V_29 -> V_2 . V_10 |= F_43 ( V_60 ) ;
V_115 = true ;
} else if ( V_111 == V_113 -> V_121 ) {
V_29 -> V_2 . V_19 &= ~ V_21 ;
V_29 -> V_2 . V_19 |= F_44 ( V_60 ) ;
V_115 = true ;
} else if ( V_111 == V_113 -> V_122 ) {
V_29 -> V_2 . V_12 = V_60 - 256 ;
V_115 = true ;
} else if ( V_111 == V_113 -> V_123 ) {
V_29 -> V_2 . V_13 = V_60 ;
V_115 = true ;
} else if ( V_111 == V_113 -> V_124 ) {
V_29 -> V_2 . V_15 = V_60 ;
V_115 = true ;
}
if ( V_115 && V_29 -> V_6 . V_36 )
F_1 ( & V_29 -> V_2 ,
F_14 ( V_29 -> V_6 . V_36 ) ) ;
return 0 ;
}
static int F_45 ( struct V_125 * V_37 )
{
struct V_112 * V_113 = V_37 -> V_114 ;
if ( V_113 -> V_116 )
return 0 ;
V_113 -> V_116 = F_46 ( V_37 , 0 ,
L_1 , 0 , 0xffffff ) ;
V_113 -> V_117 = F_46 ( V_37 , 0 ,
L_2 , 0 , 0xffffff ) ;
V_113 -> V_118 = F_46 ( V_37 , 0 ,
L_3 , 0 , 0xffffff ) ;
V_113 -> V_119 = F_46 ( V_37 , 0 ,
L_4 , 0 , 0xffffff ) ;
V_113 -> V_120 = F_46 ( V_37 , 0 ,
L_5 , 0 , 0xffffff ) ;
V_113 -> V_121 = F_47 ( V_37 , 0 ,
L_6 ,
V_126 ,
F_28 ( V_126 ) ) ;
V_113 -> V_122 = F_46 ( V_37 , 0 ,
L_7 , 0 , 256 + 255 ) ;
V_113 -> V_123 = F_46 ( V_37 , 0 ,
L_8 , 0 , 0x7fff ) ;
V_113 -> V_124 = F_46 ( V_37 , 0 ,
L_9 , 0 , 0x7fff ) ;
if ( ! V_113 -> V_116 )
return - V_127 ;
return 0 ;
}
int F_48 ( struct V_125 * V_37 , unsigned long V_128 )
{
struct V_112 * V_113 = V_37 -> V_114 ;
struct V_129 * V_130 ;
struct V_28 * V_29 ;
int V_64 ;
V_64 = F_45 ( V_37 ) ;
if ( V_64 )
return V_64 ;
V_29 = F_49 ( sizeof( * V_29 ) , V_131 ) ;
if ( ! V_29 )
return - V_127 ;
F_50 ( & V_29 -> V_34 ) ;
F_51 ( & V_29 -> V_32 . V_38 ) ;
F_52 ( & V_29 -> V_32 . V_80 , F_6 ,
V_29 ) ;
F_53 ( V_37 , & V_29 -> V_6 , V_128 , & V_132 ,
V_133 , F_28 ( V_133 ) , false ) ;
V_29 -> V_2 . V_5 = 0xfefefe00 ;
V_29 -> V_2 . V_8 = 0x01010100 ;
V_29 -> V_2 . V_10 = 0x01010100 ;
V_29 -> V_2 . V_19 = F_44 ( V_134 ) ;
V_29 -> V_2 . V_12 = 0 ;
V_29 -> V_2 . V_13 = 0x4000 ;
V_29 -> V_2 . V_15 = 0x4000 ;
V_130 = & V_29 -> V_6 . V_6 ;
F_54 ( V_130 , V_113 -> V_116 ,
0x0101fe ) ;
F_54 ( V_130 , V_113 -> V_117 ,
0x0101fe ) ;
F_54 ( V_130 , V_113 -> V_118 ,
0x0101fe ) ;
F_54 ( V_130 , V_113 -> V_119 ,
0x0101fe ) ;
F_54 ( V_130 , V_113 -> V_120 ,
0x000000 ) ;
F_54 ( V_130 , V_113 -> V_121 ,
V_134 ) ;
F_54 ( V_130 , V_113 -> V_122 , 256 ) ;
F_54 ( V_130 , V_113 -> V_123 ,
V_29 -> V_2 . V_13 ) ;
F_54 ( V_130 , V_113 -> V_124 ,
V_29 -> V_2 . V_15 ) ;
return 0 ;
}
