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
F_11 ( & V_4 -> V_37 , & V_34 -> V_6 ) ;
F_12 ( V_4 , V_28 -> V_38 . V_39 ) ;
F_6 ( V_28 , NULL ) ;
}
static int
F_13 ( struct V_40 * V_34 , struct V_41 * V_37 ,
struct V_29 * V_30 ,
int V_42 , int V_43 , unsigned V_44 , unsigned V_45 ,
T_1 V_46 , T_1 V_47 , T_1 V_48 , T_1 V_49 )
{
struct V_27 * V_28 = F_14 ( V_34 ) ;
struct V_3 * V_4 = F_15 ( V_37 ) ;
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
. V_53 = V_37 -> V_57 . V_58 ,
. V_54 = V_37 -> V_57 . V_59 ,
} ;
T_1 V_60 , V_61 ;
unsigned V_62 = 0 ;
bool V_63 ;
int V_64 ;
F_16 ( V_34 , V_37 , V_30 ,
V_42 , V_43 , V_44 , V_45 ,
V_46 , V_47 , V_48 , V_49 ) ;
V_64 = F_17 ( V_34 , V_37 , V_30 , & V_51 , & V_55 , & V_56 ,
V_65 ,
0 , V_66 , true , false , & V_63 ) ;
if ( V_64 )
return V_64 ;
V_61 = F_18 ( F_19 ( V_30 ) -> V_67 ) |
F_20 ( F_19 ( V_30 ) -> V_68 ) |
V_69 | V_70 | V_71 ;
if ( ! V_63 )
V_61 &= ~ V_71 ;
if ( ! V_4 -> V_34 ) {
V_4 -> V_34 = V_34 ;
F_1 ( & V_28 -> V_2 , V_4 ) ;
}
if ( V_34 -> V_30 == V_30 && V_28 -> V_6 . V_72 . V_61 == V_61 ) {
V_60 = ( F_21 ( & V_51 ) & 0xffff0000 ) |
F_22 ( & V_51 ) >> 16 ;
V_28 -> V_6 . V_72 . V_73 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_74 ) ;
V_60 = F_21 ( & V_55 ) << 16 | F_22 ( & V_55 ) ;
V_28 -> V_6 . V_72 . V_75 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_76 ) ;
V_60 = V_55 . y1 << 16 | V_55 . V_52 ;
V_28 -> V_6 . V_72 . V_77 = V_60 ;
F_2 ( V_60 , V_4 -> V_6 + V_78 ) ;
return 0 ;
} else if ( ~ V_28 -> V_6 . V_72 . V_61 & V_61 & V_71 ) {
F_4 ( 0 , V_79 | V_80 ,
V_4 -> V_6 + V_81 ) ;
}
if ( F_23 ( & V_28 -> V_6 , V_82 / 25 ) == 0 )
F_24 ( V_4 , & V_28 -> V_6 ) ;
if ( V_34 -> V_30 != V_30 ) {
T_2 V_83 [ 3 ] , V_84 ;
int V_85 , V_86 ;
F_25 ( V_30 ) ;
if ( V_34 -> V_30 )
F_6 ( V_28 , V_34 -> V_30 ) ;
V_47 = V_51 . y1 >> 16 ;
V_46 = V_51 . V_52 >> 16 ;
F_26 ( V_83 , V_30 , V_46 , V_47 ) ;
V_84 = V_30 -> V_87 -> V_87 ;
V_86 = F_27 ( V_84 ) ;
V_85 = V_30 -> V_87 -> V_85 ;
if ( V_46 & ( V_86 - 1 ) && V_85 == 1 )
V_61 ^= F_20 ( V_88 ) ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_83 [ 0 ] ,
V_89 ) ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_83 [ 1 ] ,
V_90 ) ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_83 [ 2 ] ,
V_91 ) ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_83 [ 0 ] ,
V_92 ) ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_83 [ 1 ] ,
V_93 ) ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_83 [ 2 ] ,
V_94 ) ;
V_60 = V_30 -> V_95 [ 0 ] << 16 | V_30 -> V_95 [ 0 ] ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_60 ,
V_96 ) ;
V_60 = V_30 -> V_95 [ 1 ] << 16 | V_30 -> V_95 [ 2 ] ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_60 ,
V_97 ) ;
}
V_60 = ( F_21 ( & V_51 ) & 0xffff0000 ) | F_22 ( & V_51 ) >> 16 ;
if ( V_28 -> V_6 . V_72 . V_73 != V_60 ) {
V_28 -> V_6 . V_72 . V_73 = V_60 ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_60 ,
V_74 ) ;
}
V_60 = F_21 ( & V_55 ) << 16 | F_22 ( & V_55 ) ;
if ( V_28 -> V_6 . V_72 . V_75 != V_60 ) {
V_28 -> V_6 . V_72 . V_75 = V_60 ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_60 ,
V_76 ) ;
}
V_60 = V_55 . y1 << 16 | V_55 . V_52 ;
if ( V_28 -> V_6 . V_72 . V_77 != V_60 ) {
V_28 -> V_6 . V_72 . V_77 = V_60 ;
F_28 ( V_28 -> V_38 . V_39 , V_62 , V_60 ,
V_78 ) ;
}
if ( V_28 -> V_6 . V_72 . V_61 != V_61 ) {
V_28 -> V_6 . V_72 . V_61 = V_61 ;
F_29 ( V_28 -> V_38 . V_39 , V_62 , V_61 ,
V_69 | V_98 | V_99 |
V_70 | V_100 |
F_20 ( V_101 | V_88 | V_102 |
V_103 ) | V_71 ,
V_104 ) ;
}
if ( V_62 ) {
F_30 ( V_28 -> V_38 . V_39 , V_62 ) ;
F_31 ( V_4 , & V_28 -> V_6 ,
& V_28 -> V_38 . V_36 ) ;
}
return 0 ;
}
static int F_32 ( struct V_40 * V_34 )
{
struct V_27 * V_28 = F_14 ( V_34 ) ;
struct V_29 * V_30 ;
struct V_3 * V_4 ;
if ( ! V_28 -> V_6 . V_6 . V_37 )
return 0 ;
V_4 = F_15 ( V_28 -> V_6 . V_6 . V_37 ) ;
F_24 ( V_4 , & V_28 -> V_6 ) ;
F_33 ( V_4 , V_34 ) ;
V_4 -> V_34 = NULL ;
V_28 -> V_6 . V_72 . V_61 = 0 ;
V_30 = F_7 ( & V_28 -> V_31 , NULL ) ;
if ( V_30 )
F_34 ( V_30 ) ;
return 0 ;
}
static void F_35 ( struct V_40 * V_34 )
{
struct V_27 * V_28 = F_14 ( V_34 ) ;
F_36 ( V_34 ) ;
F_37 ( V_28 ) ;
}
static int F_38 ( struct V_40 * V_34 ,
struct V_105 * V_106 , T_3 V_60 )
{
struct V_107 * V_108 = V_34 -> V_32 -> V_109 ;
struct V_27 * V_28 = F_14 ( V_34 ) ;
bool V_110 = false ;
if ( V_106 == V_108 -> V_111 ) {
#define F_39 ( T_4 ) ((v) << 24 | (v) << 16 | (v) << 8)
V_28 -> V_2 . V_5 = F_39 ( F_40 ( V_60 ) ) ;
V_28 -> V_2 . V_8 = F_39 ( F_41 ( V_60 ) ) ;
V_28 -> V_2 . V_10 = F_39 ( F_42 ( V_60 ) ) ;
#undef F_39
V_110 = true ;
} else if ( V_106 == V_108 -> V_112 ) {
V_28 -> V_2 . V_5 &= ~ 0x00ff0000 ;
V_28 -> V_2 . V_5 |= F_40 ( V_60 ) << 16 ;
V_28 -> V_2 . V_8 &= ~ 0x00ff0000 ;
V_28 -> V_2 . V_8 |= F_41 ( V_60 ) << 16 ;
V_28 -> V_2 . V_10 &= ~ 0x00ff0000 ;
V_28 -> V_2 . V_10 |= F_42 ( V_60 ) << 16 ;
V_110 = true ;
} else if ( V_106 == V_108 -> V_113 ) {
V_28 -> V_2 . V_5 &= ~ 0xff000000 ;
V_28 -> V_2 . V_5 |= F_40 ( V_60 ) << 24 ;
V_28 -> V_2 . V_8 &= ~ 0xff000000 ;
V_28 -> V_2 . V_8 |= F_41 ( V_60 ) << 24 ;
V_28 -> V_2 . V_10 &= ~ 0xff000000 ;
V_28 -> V_2 . V_10 |= F_42 ( V_60 ) << 24 ;
V_110 = true ;
} else if ( V_106 == V_108 -> V_114 ) {
V_28 -> V_2 . V_5 &= ~ 0x0000ff00 ;
V_28 -> V_2 . V_5 |= F_40 ( V_60 ) << 8 ;
V_28 -> V_2 . V_8 &= ~ 0x0000ff00 ;
V_28 -> V_2 . V_8 |= F_41 ( V_60 ) << 8 ;
V_28 -> V_2 . V_10 &= ~ 0x0000ff00 ;
V_28 -> V_2 . V_10 |= F_42 ( V_60 ) << 8 ;
V_110 = true ;
} else if ( V_106 == V_108 -> V_115 ) {
V_28 -> V_2 . V_5 &= ~ 0x000000ff ;
V_28 -> V_2 . V_5 |= F_40 ( V_60 ) ;
V_28 -> V_2 . V_8 &= ~ 0x000000ff ;
V_28 -> V_2 . V_8 |= F_41 ( V_60 ) ;
V_28 -> V_2 . V_10 &= ~ 0x000000ff ;
V_28 -> V_2 . V_10 |= F_42 ( V_60 ) ;
V_110 = true ;
} else if ( V_106 == V_108 -> V_116 ) {
V_28 -> V_2 . V_19 &= ~ V_21 ;
V_28 -> V_2 . V_19 |= F_43 ( V_60 ) ;
V_110 = true ;
} else if ( V_106 == V_108 -> V_117 ) {
V_28 -> V_2 . V_12 = V_60 - 256 ;
V_110 = true ;
} else if ( V_106 == V_108 -> V_118 ) {
V_28 -> V_2 . V_13 = V_60 ;
V_110 = true ;
} else if ( V_106 == V_108 -> V_119 ) {
V_28 -> V_2 . V_15 = V_60 ;
V_110 = true ;
}
if ( V_110 && V_28 -> V_6 . V_6 . V_37 )
F_1 ( & V_28 -> V_2 ,
F_15 ( V_28 -> V_6 . V_6 . V_37 ) ) ;
return 0 ;
}
static int F_44 ( struct V_120 * V_32 )
{
struct V_107 * V_108 = V_32 -> V_109 ;
if ( V_108 -> V_111 )
return 0 ;
V_108 -> V_111 = F_45 ( V_32 , 0 ,
L_1 , 0 , 0xffffff ) ;
V_108 -> V_112 = F_45 ( V_32 , 0 ,
L_2 , 0 , 0xffffff ) ;
V_108 -> V_113 = F_45 ( V_32 , 0 ,
L_3 , 0 , 0xffffff ) ;
V_108 -> V_114 = F_45 ( V_32 , 0 ,
L_4 , 0 , 0xffffff ) ;
V_108 -> V_115 = F_45 ( V_32 , 0 ,
L_5 , 0 , 0xffffff ) ;
V_108 -> V_116 = F_46 ( V_32 , 0 ,
L_6 ,
V_121 ,
F_47 ( V_121 ) ) ;
V_108 -> V_117 = F_45 ( V_32 , 0 ,
L_7 , 0 , 256 + 255 ) ;
V_108 -> V_118 = F_45 ( V_32 , 0 ,
L_8 , 0 , 0x7fff ) ;
V_108 -> V_119 = F_45 ( V_32 , 0 ,
L_9 , 0 , 0x7fff ) ;
if ( ! V_108 -> V_111 )
return - V_122 ;
return 0 ;
}
int F_48 ( struct V_120 * V_32 , unsigned long V_123 )
{
struct V_107 * V_108 = V_32 -> V_109 ;
struct V_124 * V_125 ;
struct V_27 * V_28 ;
int V_64 ;
V_64 = F_44 ( V_32 ) ;
if ( V_64 )
return V_64 ;
V_28 = F_49 ( sizeof( * V_28 ) , V_126 ) ;
if ( ! V_28 )
return - V_122 ;
V_64 = F_50 ( & V_28 -> V_6 ) ;
if ( V_64 ) {
F_37 ( V_28 ) ;
return V_64 ;
}
V_28 -> V_38 . V_36 . V_127 = F_9 ;
V_64 = F_51 ( V_32 , & V_28 -> V_6 . V_6 , V_123 ,
& V_128 ,
V_129 ,
F_47 ( V_129 ) ,
V_130 , NULL ) ;
if ( V_64 ) {
F_37 ( V_28 ) ;
return V_64 ;
}
V_28 -> V_2 . V_5 = 0xfefefe00 ;
V_28 -> V_2 . V_8 = 0x01010100 ;
V_28 -> V_2 . V_10 = 0x01010100 ;
V_28 -> V_2 . V_19 = F_43 ( V_131 ) ;
V_28 -> V_2 . V_12 = 0 ;
V_28 -> V_2 . V_13 = 0x4000 ;
V_28 -> V_2 . V_15 = 0x4000 ;
V_125 = & V_28 -> V_6 . V_6 . V_6 ;
F_52 ( V_125 , V_108 -> V_111 ,
0x0101fe ) ;
F_52 ( V_125 , V_108 -> V_112 ,
0x0101fe ) ;
F_52 ( V_125 , V_108 -> V_113 ,
0x0101fe ) ;
F_52 ( V_125 , V_108 -> V_114 ,
0x0101fe ) ;
F_52 ( V_125 , V_108 -> V_115 ,
0x000000 ) ;
F_52 ( V_125 , V_108 -> V_116 ,
V_131 ) ;
F_52 ( V_125 , V_108 -> V_117 , 256 ) ;
F_52 ( V_125 , V_108 -> V_118 ,
V_28 -> V_2 . V_13 ) ;
F_52 ( V_125 , V_108 -> V_119 ,
V_28 -> V_2 . V_15 ) ;
return 0 ;
}
