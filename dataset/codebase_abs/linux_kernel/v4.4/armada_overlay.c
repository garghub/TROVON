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
static void F_6 ( struct V_27 * V_28 ,
struct V_29 * V_30 )
{
struct V_29 * V_31 ;
V_31 = F_7 ( & V_28 -> V_31 , V_30 ) ;
if ( V_31 )
F_8 ( V_28 -> V_6 . V_6 . V_32 , V_31 ) ;
}
static void F_9 ( struct V_3 * V_4 ,
struct V_33 * V_34 , struct V_35 * V_36 )
{
struct V_27 * V_28 = F_10 ( V_34 , struct V_27 , V_6 ) ;
F_11 ( V_4 , V_28 -> V_37 . V_38 ) ;
F_6 ( V_28 , NULL ) ;
}
static int
F_12 ( struct V_39 * V_34 , struct V_40 * V_41 ,
struct V_29 * V_30 ,
int V_42 , int V_43 , unsigned V_44 , unsigned V_45 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 , T_1 V_49 )
{
struct V_27 * V_28 = F_13 ( V_34 ) ;
struct V_3 * V_4 = F_14 ( V_41 ) ;
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
. V_53 = V_41 -> V_57 . V_58 ,
. V_54 = V_41 -> V_57 . V_59 ,
} ;
T_1 V_60 , V_61 ;
unsigned V_62 = 0 ;
bool V_63 ;
int V_64 ;
V_64 = F_15 ( V_34 , V_41 , V_30 , & V_51 , & V_55 , & V_56 ,
0 , V_65 , true , false , & V_63 ) ;
if ( V_64 )
return V_64 ;
V_61 = F_16 ( F_17 ( V_30 ) -> V_66 ) |
F_18 ( F_17 ( V_30 ) -> V_67 ) |
V_68 | V_69 | V_70 ;
if ( ! V_63 )
V_61 &= ~ V_70 ;
if ( ! V_4 -> V_34 ) {
V_4 -> V_34 = V_34 ;
F_1 ( & V_28 -> V_2 , V_4 ) ;
}
if ( V_34 -> V_30 == V_30 && V_28 -> V_61 == V_61 ) {
V_60 = ( F_19 ( & V_51 ) & 0xffff0000 ) |
F_20 ( & V_51 ) >> 16 ;
V_28 -> V_71 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_72 ) ;
V_60 = F_19 ( & V_55 ) << 16 | F_20 ( & V_55 ) ;
V_28 -> V_73 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_74 ) ;
V_60 = V_55 . y1 << 16 | V_55 . V_52 ;
V_28 -> V_75 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_76 ) ;
return 0 ;
} else if ( ~ V_28 -> V_61 & V_61 & V_70 ) {
F_4 ( 0 , V_77 | V_78 ,
V_4 -> V_6 + V_79 ) ;
}
if ( F_21 ( & V_28 -> V_6 , V_80 / 25 ) == 0 )
F_22 ( V_4 , & V_28 -> V_6 ) ;
if ( V_34 -> V_30 != V_30 ) {
struct V_81 * V_82 = F_23 ( V_30 ) ;
T_1 V_83 [ 3 ] , V_84 ;
int V_85 , V_86 , V_87 ;
F_24 ( V_30 ) ;
if ( V_34 -> V_30 )
F_6 ( V_28 , V_34 -> V_30 ) ;
V_47 = V_51 . y1 >> 16 ;
V_46 = V_51 . V_52 >> 16 ;
V_84 = V_30 -> V_84 ;
V_87 = F_25 ( V_84 ) ;
V_86 = F_26 ( V_84 ) ;
if ( V_46 & ( V_87 - 1 ) && V_86 == 1 )
V_61 ^= F_18 ( V_88 ) ;
for ( V_85 = 0 ; V_85 < V_86 ; V_85 ++ )
V_83 [ V_85 ] = V_82 -> V_89 + V_30 -> V_90 [ V_85 ] +
V_47 * V_30 -> V_91 [ V_85 ] +
V_46 * F_27 ( V_84 , V_85 ) ;
for (; V_85 < F_28 ( V_83 ) ; V_85 ++ )
V_83 [ V_85 ] = 0 ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_83 [ 0 ] ,
V_92 ) ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_83 [ 1 ] ,
V_93 ) ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_83 [ 2 ] ,
V_94 ) ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_83 [ 0 ] ,
V_95 ) ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_83 [ 1 ] ,
V_96 ) ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_83 [ 2 ] ,
V_97 ) ;
V_60 = V_30 -> V_91 [ 0 ] << 16 | V_30 -> V_91 [ 0 ] ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_60 ,
V_98 ) ;
V_60 = V_30 -> V_91 [ 1 ] << 16 | V_30 -> V_91 [ 2 ] ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_60 ,
V_99 ) ;
}
V_60 = ( F_19 ( & V_51 ) & 0xffff0000 ) | F_20 ( & V_51 ) >> 16 ;
if ( V_28 -> V_71 != V_60 ) {
V_28 -> V_71 = V_60 ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_60 ,
V_72 ) ;
}
V_60 = F_19 ( & V_55 ) << 16 | F_20 ( & V_55 ) ;
if ( V_28 -> V_73 != V_60 ) {
V_28 -> V_73 = V_60 ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_60 ,
V_74 ) ;
}
V_60 = V_55 . y1 << 16 | V_55 . V_52 ;
if ( V_28 -> V_75 != V_60 ) {
V_28 -> V_75 = V_60 ;
F_29 ( V_28 -> V_37 . V_38 , V_62 , V_60 ,
V_76 ) ;
}
if ( V_28 -> V_61 != V_61 ) {
V_28 -> V_61 = V_61 ;
F_30 ( V_28 -> V_37 . V_38 , V_62 , V_61 ,
V_68 | V_100 | V_101 |
V_69 | V_102 |
F_18 ( V_103 | V_88 | V_104 |
V_105 ) | V_70 ,
V_106 ) ;
}
if ( V_62 ) {
F_31 ( V_28 -> V_37 . V_38 , V_62 ) ;
F_32 ( V_4 , & V_28 -> V_6 ,
& V_28 -> V_37 . V_36 ) ;
}
return 0 ;
}
static int F_33 ( struct V_39 * V_34 )
{
struct V_27 * V_28 = F_13 ( V_34 ) ;
struct V_29 * V_30 ;
struct V_3 * V_4 ;
if ( ! V_28 -> V_6 . V_6 . V_41 )
return 0 ;
V_4 = F_14 ( V_28 -> V_6 . V_6 . V_41 ) ;
F_22 ( V_4 , & V_28 -> V_6 ) ;
F_34 ( V_4 , V_34 ) ;
V_4 -> V_34 = NULL ;
V_28 -> V_61 = 0 ;
V_30 = F_7 ( & V_28 -> V_31 , NULL ) ;
if ( V_30 )
F_35 ( V_30 ) ;
return 0 ;
}
static void F_36 ( struct V_39 * V_34 )
{
struct V_27 * V_28 = F_13 ( V_34 ) ;
F_37 ( V_34 ) ;
F_38 ( V_28 ) ;
}
static int F_39 ( struct V_39 * V_34 ,
struct V_107 * V_108 , T_2 V_60 )
{
struct V_109 * V_110 = V_34 -> V_32 -> V_111 ;
struct V_27 * V_28 = F_13 ( V_34 ) ;
bool V_112 = false ;
if ( V_108 == V_110 -> V_113 ) {
#define F_40 ( T_3 ) ((v) << 24 | (v) << 16 | (v) << 8)
V_28 -> V_2 . V_5 = F_40 ( F_41 ( V_60 ) ) ;
V_28 -> V_2 . V_8 = F_40 ( F_42 ( V_60 ) ) ;
V_28 -> V_2 . V_10 = F_40 ( F_43 ( V_60 ) ) ;
#undef F_40
V_112 = true ;
} else if ( V_108 == V_110 -> V_114 ) {
V_28 -> V_2 . V_5 &= ~ 0x00ff0000 ;
V_28 -> V_2 . V_5 |= F_41 ( V_60 ) << 16 ;
V_28 -> V_2 . V_8 &= ~ 0x00ff0000 ;
V_28 -> V_2 . V_8 |= F_42 ( V_60 ) << 16 ;
V_28 -> V_2 . V_10 &= ~ 0x00ff0000 ;
V_28 -> V_2 . V_10 |= F_43 ( V_60 ) << 16 ;
V_112 = true ;
} else if ( V_108 == V_110 -> V_115 ) {
V_28 -> V_2 . V_5 &= ~ 0xff000000 ;
V_28 -> V_2 . V_5 |= F_41 ( V_60 ) << 24 ;
V_28 -> V_2 . V_8 &= ~ 0xff000000 ;
V_28 -> V_2 . V_8 |= F_42 ( V_60 ) << 24 ;
V_28 -> V_2 . V_10 &= ~ 0xff000000 ;
V_28 -> V_2 . V_10 |= F_43 ( V_60 ) << 24 ;
V_112 = true ;
} else if ( V_108 == V_110 -> V_116 ) {
V_28 -> V_2 . V_5 &= ~ 0x0000ff00 ;
V_28 -> V_2 . V_5 |= F_41 ( V_60 ) << 8 ;
V_28 -> V_2 . V_8 &= ~ 0x0000ff00 ;
V_28 -> V_2 . V_8 |= F_42 ( V_60 ) << 8 ;
V_28 -> V_2 . V_10 &= ~ 0x0000ff00 ;
V_28 -> V_2 . V_10 |= F_43 ( V_60 ) << 8 ;
V_112 = true ;
} else if ( V_108 == V_110 -> V_117 ) {
V_28 -> V_2 . V_5 &= ~ 0x000000ff ;
V_28 -> V_2 . V_5 |= F_41 ( V_60 ) ;
V_28 -> V_2 . V_8 &= ~ 0x000000ff ;
V_28 -> V_2 . V_8 |= F_42 ( V_60 ) ;
V_28 -> V_2 . V_10 &= ~ 0x000000ff ;
V_28 -> V_2 . V_10 |= F_43 ( V_60 ) ;
V_112 = true ;
} else if ( V_108 == V_110 -> V_118 ) {
V_28 -> V_2 . V_19 &= ~ V_21 ;
V_28 -> V_2 . V_19 |= F_44 ( V_60 ) ;
V_112 = true ;
} else if ( V_108 == V_110 -> V_119 ) {
V_28 -> V_2 . V_12 = V_60 - 256 ;
V_112 = true ;
} else if ( V_108 == V_110 -> V_120 ) {
V_28 -> V_2 . V_13 = V_60 ;
V_112 = true ;
} else if ( V_108 == V_110 -> V_121 ) {
V_28 -> V_2 . V_15 = V_60 ;
V_112 = true ;
}
if ( V_112 && V_28 -> V_6 . V_6 . V_41 )
F_1 ( & V_28 -> V_2 ,
F_14 ( V_28 -> V_6 . V_6 . V_41 ) ) ;
return 0 ;
}
static int F_45 ( struct V_122 * V_32 )
{
struct V_109 * V_110 = V_32 -> V_111 ;
if ( V_110 -> V_113 )
return 0 ;
V_110 -> V_113 = F_46 ( V_32 , 0 ,
L_1 , 0 , 0xffffff ) ;
V_110 -> V_114 = F_46 ( V_32 , 0 ,
L_2 , 0 , 0xffffff ) ;
V_110 -> V_115 = F_46 ( V_32 , 0 ,
L_3 , 0 , 0xffffff ) ;
V_110 -> V_116 = F_46 ( V_32 , 0 ,
L_4 , 0 , 0xffffff ) ;
V_110 -> V_117 = F_46 ( V_32 , 0 ,
L_5 , 0 , 0xffffff ) ;
V_110 -> V_118 = F_47 ( V_32 , 0 ,
L_6 ,
V_123 ,
F_28 ( V_123 ) ) ;
V_110 -> V_119 = F_46 ( V_32 , 0 ,
L_7 , 0 , 256 + 255 ) ;
V_110 -> V_120 = F_46 ( V_32 , 0 ,
L_8 , 0 , 0x7fff ) ;
V_110 -> V_121 = F_46 ( V_32 , 0 ,
L_9 , 0 , 0x7fff ) ;
if ( ! V_110 -> V_113 )
return - V_124 ;
return 0 ;
}
int F_48 ( struct V_122 * V_32 , unsigned long V_125 )
{
struct V_109 * V_110 = V_32 -> V_111 ;
struct V_126 * V_127 ;
struct V_27 * V_28 ;
int V_64 ;
V_64 = F_45 ( V_32 ) ;
if ( V_64 )
return V_64 ;
V_28 = F_49 ( sizeof( * V_28 ) , V_128 ) ;
if ( ! V_28 )
return - V_124 ;
V_64 = F_50 ( & V_28 -> V_6 ) ;
if ( V_64 ) {
F_38 ( V_28 ) ;
return V_64 ;
}
V_28 -> V_37 . V_36 . V_129 = F_9 ;
V_64 = F_51 ( V_32 , & V_28 -> V_6 . V_6 , V_125 ,
& V_130 ,
V_131 ,
F_28 ( V_131 ) ,
V_132 ) ;
if ( V_64 ) {
F_38 ( V_28 ) ;
return V_64 ;
}
V_28 -> V_2 . V_5 = 0xfefefe00 ;
V_28 -> V_2 . V_8 = 0x01010100 ;
V_28 -> V_2 . V_10 = 0x01010100 ;
V_28 -> V_2 . V_19 = F_44 ( V_133 ) ;
V_28 -> V_2 . V_12 = 0 ;
V_28 -> V_2 . V_13 = 0x4000 ;
V_28 -> V_2 . V_15 = 0x4000 ;
V_127 = & V_28 -> V_6 . V_6 . V_6 ;
F_52 ( V_127 , V_110 -> V_113 ,
0x0101fe ) ;
F_52 ( V_127 , V_110 -> V_114 ,
0x0101fe ) ;
F_52 ( V_127 , V_110 -> V_115 ,
0x0101fe ) ;
F_52 ( V_127 , V_110 -> V_116 ,
0x0101fe ) ;
F_52 ( V_127 , V_110 -> V_117 ,
0x000000 ) ;
F_52 ( V_127 , V_110 -> V_118 ,
V_133 ) ;
F_52 ( V_127 , V_110 -> V_119 , 256 ) ;
F_52 ( V_127 , V_110 -> V_120 ,
V_28 -> V_2 . V_13 ) ;
F_52 ( V_127 , V_110 -> V_121 ,
V_28 -> V_2 . V_15 ) ;
return 0 ;
}
