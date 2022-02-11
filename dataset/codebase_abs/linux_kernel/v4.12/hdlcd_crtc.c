static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_5 , 0 ) ;
F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_6 = F_6 ( V_4 , V_7 ) ;
F_3 ( V_4 , V_7 , V_6 | V_8 ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_6 = F_6 ( V_4 , V_7 ) ;
F_3 ( V_4 , V_7 , V_6 & ~ V_8 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_10 * V_11 = V_2 -> V_12 -> V_13 -> V_11 ;
T_1 V_14 ;
struct V_15 * V_16 = NULL ;
int V_17 ;
V_14 = V_11 -> V_16 -> V_16 ;
for ( V_17 = 0 ; V_17 < F_9 ( V_18 ) ; V_17 ++ ) {
if ( V_18 [ V_17 ] . V_19 == V_14 )
V_16 = & V_18 [ V_17 ] ;
}
if ( F_10 ( ! V_16 ) )
return 0 ;
V_9 = ( V_16 -> V_20 + 7 ) / 8 ;
F_3 ( V_4 , V_21 , ( V_9 - 1 ) << 3 ) ;
F_3 ( V_4 , V_22 , V_16 -> V_23 . V_24 |
#ifdef F_11
0x00ff0000 |
#endif
( ( V_16 -> V_23 . V_25 & 0xf ) << 8 ) ) ;
F_3 ( V_4 , V_26 , V_16 -> V_27 . V_24 |
( ( V_16 -> V_27 . V_25 & 0xf ) << 8 ) ) ;
F_3 ( V_4 , V_28 , V_16 -> V_29 . V_24 |
( ( V_16 -> V_29 . V_25 & 0xf ) << 8 ) ) ;
return 0 ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_31 = & V_2 -> V_13 -> V_32 ;
struct V_33 V_34 ;
unsigned int V_35 , V_36 ;
V_34 . V_37 = V_31 -> V_38 - V_31 -> V_39 ;
V_34 . V_40 = V_31 -> V_41 - V_31 -> V_42 ;
V_34 . V_43 = V_31 -> V_42 - V_31 -> V_38 ;
V_34 . V_44 = V_31 -> V_45 - V_31 -> V_46 ;
V_34 . V_47 = V_31 -> V_48 - V_31 -> V_49 ;
V_34 . V_50 = V_31 -> V_49 - V_31 -> V_45 ;
V_35 = V_51 | V_52 ;
if ( V_31 -> V_53 & V_54 )
V_35 |= V_55 ;
if ( V_31 -> V_53 & V_56 )
V_35 |= V_57 ;
F_3 ( V_4 , V_58 ,
V_59 | V_60 ) ;
F_3 ( V_4 , V_61 , V_31 -> V_39 - 1 ) ;
F_3 ( V_4 , V_62 , V_34 . V_40 - 1 ) ;
F_3 ( V_4 , V_63 , V_34 . V_37 - 1 ) ;
F_3 ( V_4 , V_64 , V_34 . V_43 - 1 ) ;
F_3 ( V_4 , V_65 , V_31 -> V_46 - 1 ) ;
F_3 ( V_4 , V_66 , V_34 . V_47 - 1 ) ;
F_3 ( V_4 , V_67 , V_34 . V_44 - 1 ) ;
F_3 ( V_4 , V_68 , V_34 . V_50 - 1 ) ;
F_3 ( V_4 , V_69 , V_35 ) ;
V_36 = F_8 ( V_2 ) ;
if ( V_36 )
return;
F_13 ( V_4 -> V_70 , V_31 -> V_71 * 1000 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_4 -> V_70 ) ;
F_12 ( V_2 ) ;
F_3 ( V_4 , V_5 , 1 ) ;
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_18 ( V_2 ) ;
F_3 ( V_4 , V_5 , 0 ) ;
F_19 ( V_4 -> V_70 ) ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_72 * V_13 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_30 * V_73 = & V_13 -> V_32 ;
long V_74 , V_75 = V_73 -> clock * 1000 ;
V_74 = F_21 ( V_4 -> V_70 , V_75 ) ;
if ( V_74 != V_75 ) {
return - V_76 ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_72 * V_13 )
{
struct V_77 * V_78 = V_2 -> V_13 -> V_78 ;
if ( V_78 ) {
V_2 -> V_13 -> V_78 = NULL ;
F_23 ( & V_2 -> V_79 -> V_80 ) ;
if ( F_24 ( V_2 ) == 0 )
F_25 ( V_2 , V_78 ) ;
else
F_26 ( V_2 , V_78 ) ;
F_27 ( & V_2 -> V_79 -> V_80 ) ;
}
}
static int F_28 ( struct V_81 * V_82 ,
struct V_83 * V_13 )
{
struct V_84 V_85 = { 0 } ;
struct V_72 * V_86 ;
T_2 V_87 = V_13 -> V_87 >> 16 ;
if ( V_87 >= V_88 ) {
F_29 ( L_1 , V_87 ) ;
return - V_76 ;
}
if ( ! V_13 -> V_11 || ! V_13 -> V_2 )
return 0 ;
V_86 = F_30 ( V_13 -> V_13 ,
V_13 -> V_2 ) ;
if ( ! V_86 ) {
F_29 ( L_2 ) ;
return - V_76 ;
}
V_85 . V_89 = V_86 -> V_32 . V_90 ;
V_85 . V_91 = V_86 -> V_32 . V_92 ;
return F_31 ( V_13 , & V_85 ,
V_93 ,
V_93 ,
false , true ) ;
}
static void F_32 ( struct V_81 * V_82 ,
struct V_83 * V_13 )
{
struct V_10 * V_11 = V_82 -> V_13 -> V_11 ;
struct V_3 * V_4 ;
struct V_94 * V_95 ;
T_2 V_96 , V_97 , V_98 ;
T_3 V_99 ;
if ( ! V_11 )
return;
V_96 = V_82 -> V_13 -> V_100 . V_101 >> 16 ;
V_97 = V_82 -> V_13 -> V_100 . y1 >> 16 ;
V_98 = F_33 ( & V_82 -> V_13 -> V_102 ) ;
V_95 = F_34 ( V_11 , 0 ) ;
V_99 = V_95 -> V_103 + V_11 -> V_104 [ 0 ] +
V_97 * V_11 -> V_105 [ 0 ] +
V_96 * V_11 -> V_16 -> V_106 [ 0 ] ;
V_4 = V_82 -> V_79 -> V_107 ;
F_3 ( V_4 , V_108 , V_11 -> V_105 [ 0 ] ) ;
F_3 ( V_4 , V_109 , V_11 -> V_105 [ 0 ] ) ;
F_3 ( V_4 , V_110 , V_98 - 1 ) ;
F_3 ( V_4 , V_111 , V_99 ) ;
}
static void F_35 ( struct V_81 * V_82 )
{
F_36 ( V_82 ) ;
F_37 ( V_82 ) ;
}
static struct V_81 * F_38 ( struct V_112 * V_113 )
{
struct V_3 * V_4 = V_113 -> V_107 ;
struct V_81 * V_82 = NULL ;
T_2 V_114 [ F_9 ( V_18 ) ] , V_17 ;
int V_115 ;
V_82 = F_39 ( V_113 -> V_79 , sizeof( * V_82 ) , V_116 ) ;
if ( ! V_82 )
return F_40 ( - V_117 ) ;
for ( V_17 = 0 ; V_17 < F_9 ( V_18 ) ; V_17 ++ )
V_114 [ V_17 ] = V_18 [ V_17 ] . V_19 ;
V_115 = F_41 ( V_113 , V_82 , 0xff , & V_118 ,
V_114 , F_9 ( V_114 ) ,
V_119 , NULL ) ;
if ( V_115 ) {
return F_40 ( V_115 ) ;
}
F_42 ( V_82 , & V_120 ) ;
V_4 -> V_82 = V_82 ;
return V_82 ;
}
int F_43 ( struct V_112 * V_113 )
{
struct V_3 * V_4 = V_113 -> V_107 ;
struct V_81 * V_12 ;
int V_115 ;
V_12 = F_38 ( V_113 ) ;
if ( F_44 ( V_12 ) )
return F_45 ( V_12 ) ;
V_115 = F_46 ( V_113 , & V_4 -> V_2 , V_12 , NULL ,
& V_121 , NULL ) ;
if ( V_115 ) {
F_35 ( V_12 ) ;
return V_115 ;
}
F_47 ( & V_4 -> V_2 , & V_122 ) ;
return 0 ;
}
