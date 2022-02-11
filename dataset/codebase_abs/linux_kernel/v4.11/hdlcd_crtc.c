static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 , V_5 , 0 ) ;
F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
unsigned int V_6 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
const struct V_7 * V_8 = V_2 -> V_9 -> V_10 -> V_8 ;
T_1 V_11 ;
struct V_12 * V_13 = NULL ;
int V_14 ;
V_11 = V_8 -> V_13 -> V_13 ;
for ( V_14 = 0 ; V_14 < F_6 ( V_15 ) ; V_14 ++ ) {
if ( V_15 [ V_14 ] . V_16 == V_11 )
V_13 = & V_15 [ V_14 ] ;
}
if ( F_7 ( ! V_13 ) )
return 0 ;
V_6 = ( V_13 -> V_17 + 7 ) / 8 ;
F_3 ( V_4 , V_18 , ( V_6 - 1 ) << 3 ) ;
F_3 ( V_4 , V_19 , V_13 -> V_20 . V_21 |
#ifdef F_8
0x00ff0000 |
#endif
( ( V_13 -> V_20 . V_22 & 0xf ) << 8 ) ) ;
F_3 ( V_4 , V_23 , V_13 -> V_24 . V_21 |
( ( V_13 -> V_24 . V_22 & 0xf ) << 8 ) ) ;
F_3 ( V_4 , V_25 , V_13 -> V_26 . V_21 |
( ( V_13 -> V_26 . V_22 & 0xf ) << 8 ) ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_28 = & V_2 -> V_10 -> V_29 ;
struct V_30 V_31 ;
unsigned int V_32 , V_33 ;
V_31 . V_34 = V_28 -> V_35 - V_28 -> V_36 ;
V_31 . V_37 = V_28 -> V_38 - V_28 -> V_39 ;
V_31 . V_40 = V_28 -> V_39 - V_28 -> V_35 ;
V_31 . V_41 = V_28 -> V_42 - V_28 -> V_43 ;
V_31 . V_44 = V_28 -> V_45 - V_28 -> V_46 ;
V_31 . V_47 = V_28 -> V_46 - V_28 -> V_42 ;
V_32 = V_48 | V_49 ;
if ( V_28 -> V_50 & V_51 )
V_32 |= V_52 ;
if ( V_28 -> V_50 & V_53 )
V_32 |= V_54 ;
F_3 ( V_4 , V_55 ,
V_56 | V_57 ) ;
F_3 ( V_4 , V_58 , V_28 -> V_36 - 1 ) ;
F_3 ( V_4 , V_59 , V_31 . V_37 - 1 ) ;
F_3 ( V_4 , V_60 , V_31 . V_34 - 1 ) ;
F_3 ( V_4 , V_61 , V_31 . V_40 - 1 ) ;
F_3 ( V_4 , V_62 , V_28 -> V_43 - 1 ) ;
F_3 ( V_4 , V_63 , V_31 . V_44 - 1 ) ;
F_3 ( V_4 , V_64 , V_31 . V_41 - 1 ) ;
F_3 ( V_4 , V_65 , V_31 . V_47 - 1 ) ;
F_3 ( V_4 , V_66 , V_32 ) ;
V_33 = F_5 ( V_2 ) ;
if ( V_33 )
return;
F_10 ( V_4 -> V_67 , V_28 -> V_68 * 1000 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_12 ( V_4 -> V_67 ) ;
F_9 ( V_2 ) ;
F_3 ( V_4 , V_5 , 1 ) ;
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_2 ) ;
F_3 ( V_4 , V_5 , 0 ) ;
F_16 ( V_4 -> V_67 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_69 * V_10 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_27 * V_70 = & V_10 -> V_29 ;
long V_71 , V_72 = V_70 -> clock * 1000 ;
V_71 = F_18 ( V_4 -> V_67 , V_72 ) ;
if ( V_71 != V_72 ) {
return - V_73 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_69 * V_10 )
{
struct V_74 * V_75 = V_2 -> V_10 -> V_75 ;
if ( V_75 ) {
V_2 -> V_10 -> V_75 = NULL ;
F_20 ( & V_2 -> V_76 -> V_77 ) ;
if ( F_21 ( V_2 ) == 0 )
F_22 ( V_2 , V_75 ) ;
else
F_23 ( V_2 , V_75 ) ;
F_24 ( & V_2 -> V_76 -> V_77 ) ;
}
}
static int F_25 ( struct V_78 * V_79 ,
struct V_80 * V_10 )
{
T_2 V_81 , V_82 ;
V_81 = V_10 -> V_81 >> 16 ;
V_82 = V_10 -> V_82 >> 16 ;
if ( ( V_81 != V_10 -> V_83 ) || ( V_82 != V_10 -> V_84 ) )
return - V_73 ;
return 0 ;
}
static void F_26 ( struct V_78 * V_79 ,
struct V_80 * V_10 )
{
struct V_7 * V_8 = V_79 -> V_10 -> V_8 ;
struct V_3 * V_4 ;
struct V_85 * V_86 ;
T_2 V_81 , V_82 , V_87 , V_88 ;
T_3 V_89 ;
if ( ! V_8 )
return;
V_81 = V_79 -> V_10 -> V_81 >> 16 ;
V_82 = V_79 -> V_10 -> V_82 >> 16 ;
V_87 = V_79 -> V_10 -> V_83 ;
V_88 = V_79 -> V_10 -> V_84 ;
V_86 = F_27 ( V_8 , 0 ) ;
V_89 = V_86 -> V_90 + V_8 -> V_91 [ 0 ] +
V_79 -> V_10 -> V_92 * V_8 -> V_93 [ 0 ] +
V_79 -> V_10 -> V_94 *
V_8 -> V_13 -> V_95 [ 0 ] ;
V_4 = V_79 -> V_76 -> V_96 ;
F_3 ( V_4 , V_97 , V_8 -> V_93 [ 0 ] ) ;
F_3 ( V_4 , V_98 , V_8 -> V_93 [ 0 ] ) ;
F_3 ( V_4 , V_99 , V_88 - 1 ) ;
F_3 ( V_4 , V_100 , V_89 ) ;
}
static void F_28 ( struct V_78 * V_79 )
{
F_29 ( V_79 ) ;
F_30 ( V_79 ) ;
}
static struct V_78 * F_31 ( struct V_101 * V_102 )
{
struct V_3 * V_4 = V_102 -> V_96 ;
struct V_78 * V_79 = NULL ;
T_2 V_103 [ F_6 ( V_15 ) ] , V_14 ;
int V_104 ;
V_79 = F_32 ( V_102 -> V_76 , sizeof( * V_79 ) , V_105 ) ;
if ( ! V_79 )
return F_33 ( - V_106 ) ;
for ( V_14 = 0 ; V_14 < F_6 ( V_15 ) ; V_14 ++ )
V_103 [ V_14 ] = V_15 [ V_14 ] . V_16 ;
V_104 = F_34 ( V_102 , V_79 , 0xff , & V_107 ,
V_103 , F_6 ( V_103 ) ,
V_108 , NULL ) ;
if ( V_104 ) {
F_35 ( V_102 -> V_76 , V_79 ) ;
return F_33 ( V_104 ) ;
}
F_36 ( V_79 , & V_109 ) ;
V_4 -> V_79 = V_79 ;
return V_79 ;
}
int F_37 ( struct V_101 * V_102 )
{
struct V_3 * V_4 = V_102 -> V_96 ;
struct V_78 * V_9 ;
int V_104 ;
V_9 = F_31 ( V_102 ) ;
if ( F_38 ( V_9 ) )
return F_39 ( V_9 ) ;
V_104 = F_40 ( V_102 , & V_4 -> V_2 , V_9 , NULL ,
& V_110 , NULL ) ;
if ( V_104 ) {
F_28 ( V_9 ) ;
F_35 ( V_102 -> V_76 , V_9 ) ;
return V_104 ;
}
F_41 ( & V_4 -> V_2 , & V_111 ) ;
return 0 ;
}
