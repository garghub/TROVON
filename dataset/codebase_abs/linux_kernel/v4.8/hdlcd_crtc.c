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
T_1 V_7 ;
struct V_8 * V_9 = NULL ;
int V_10 ;
V_7 = V_2 -> V_11 -> V_12 -> V_13 -> V_7 ;
for ( V_10 = 0 ; V_10 < F_6 ( V_14 ) ; V_10 ++ ) {
if ( V_14 [ V_10 ] . V_15 == V_7 )
V_9 = & V_14 [ V_10 ] ;
}
if ( F_7 ( ! V_9 ) )
return 0 ;
V_6 = ( V_9 -> V_16 + 7 ) / 8 ;
F_3 ( V_4 , V_17 , ( V_6 - 1 ) << 3 ) ;
F_3 ( V_4 , V_18 , V_9 -> V_19 . V_20 |
#ifdef F_8
0x00ff0000 |
#endif
( ( V_9 -> V_19 . V_21 & 0xf ) << 8 ) ) ;
F_3 ( V_4 , V_22 , V_9 -> V_23 . V_20 |
( ( V_9 -> V_23 . V_21 & 0xf ) << 8 ) ) ;
F_3 ( V_4 , V_24 , V_9 -> V_25 . V_20 |
( ( V_9 -> V_25 . V_21 & 0xf ) << 8 ) ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_27 = & V_2 -> V_12 -> V_28 ;
struct V_29 V_30 ;
unsigned int V_31 , V_32 ;
V_30 . V_33 = V_27 -> V_34 - V_27 -> V_35 ;
V_30 . V_36 = V_27 -> V_37 - V_27 -> V_38 ;
V_30 . V_39 = V_27 -> V_38 - V_27 -> V_34 ;
V_30 . V_40 = V_27 -> V_41 - V_27 -> V_42 ;
V_30 . V_43 = V_27 -> V_44 - V_27 -> V_45 ;
V_30 . V_46 = V_27 -> V_45 - V_27 -> V_41 ;
V_31 = V_47 | V_48 ;
if ( V_27 -> V_49 & V_50 )
V_31 |= V_51 ;
if ( V_27 -> V_49 & V_52 )
V_31 |= V_53 ;
F_3 ( V_4 , V_54 ,
V_55 | V_56 ) ;
F_3 ( V_4 , V_57 , V_27 -> V_35 - 1 ) ;
F_3 ( V_4 , V_58 , V_30 . V_36 - 1 ) ;
F_3 ( V_4 , V_59 , V_30 . V_33 - 1 ) ;
F_3 ( V_4 , V_60 , V_30 . V_39 - 1 ) ;
F_3 ( V_4 , V_61 , V_27 -> V_42 - 1 ) ;
F_3 ( V_4 , V_62 , V_30 . V_43 - 1 ) ;
F_3 ( V_4 , V_63 , V_30 . V_40 - 1 ) ;
F_3 ( V_4 , V_64 , V_30 . V_46 - 1 ) ;
F_3 ( V_4 , V_65 , V_31 ) ;
V_32 = F_5 ( V_2 ) ;
if ( V_32 )
return;
F_10 ( V_4 -> V_66 , V_27 -> V_67 * 1000 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_12 ( V_4 -> V_66 ) ;
F_9 ( V_2 ) ;
F_3 ( V_4 , V_5 , 1 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_12 -> V_68 )
return;
F_3 ( V_4 , V_5 , 0 ) ;
F_14 ( V_4 -> V_66 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_69 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_70 = & V_12 -> V_28 ;
long V_71 , V_72 = V_70 -> clock * 1000 ;
V_71 = F_16 ( V_4 -> V_66 , V_72 ) ;
if ( V_71 != V_72 ) {
return - V_73 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_69 * V_12 )
{
struct V_74 * V_75 = V_2 -> V_12 -> V_75 ;
if ( V_75 ) {
V_2 -> V_12 -> V_75 = NULL ;
F_18 ( & V_2 -> V_76 -> V_77 ) ;
if ( F_19 ( V_2 ) == 0 )
F_20 ( V_2 , V_75 ) ;
else
F_21 ( V_2 , V_75 ) ;
F_22 ( & V_2 -> V_76 -> V_77 ) ;
}
}
static int F_23 ( struct V_78 * V_79 ,
struct V_80 * V_12 )
{
T_2 V_81 , V_82 ;
V_81 = V_12 -> V_81 >> 16 ;
V_82 = V_12 -> V_82 >> 16 ;
if ( ( V_81 != V_12 -> V_83 ) || ( V_82 != V_12 -> V_84 ) )
return - V_73 ;
return 0 ;
}
static void F_24 ( struct V_78 * V_79 ,
struct V_80 * V_12 )
{
struct V_3 * V_4 ;
struct V_85 * V_86 ;
unsigned int V_87 , V_88 ;
T_2 V_81 , V_82 , V_89 , V_90 ;
T_3 V_91 ;
if ( ! V_79 -> V_12 -> V_13 )
return;
F_25 ( V_79 -> V_12 -> V_13 -> V_7 , & V_87 , & V_88 ) ;
V_81 = V_79 -> V_12 -> V_81 >> 16 ;
V_82 = V_79 -> V_12 -> V_82 >> 16 ;
V_89 = V_79 -> V_12 -> V_83 ;
V_90 = V_79 -> V_12 -> V_84 ;
V_86 = F_26 ( V_79 -> V_12 -> V_13 , 0 ) ;
V_91 = V_86 -> V_92 + V_79 -> V_12 -> V_13 -> V_93 [ 0 ] +
V_79 -> V_12 -> V_94 * V_79 -> V_12 -> V_13 -> V_95 [ 0 ] +
V_79 -> V_12 -> V_96 * V_88 / 8 ;
V_4 = V_79 -> V_76 -> V_97 ;
F_3 ( V_4 , V_98 , V_79 -> V_12 -> V_13 -> V_95 [ 0 ] ) ;
F_3 ( V_4 , V_99 , V_79 -> V_12 -> V_13 -> V_95 [ 0 ] ) ;
F_3 ( V_4 , V_100 , V_90 - 1 ) ;
F_3 ( V_4 , V_101 , V_91 ) ;
}
static void F_27 ( struct V_78 * V_79 )
{
F_28 ( V_79 ) ;
F_29 ( V_79 ) ;
}
static struct V_78 * F_30 ( struct V_102 * V_103 )
{
struct V_3 * V_4 = V_103 -> V_97 ;
struct V_78 * V_79 = NULL ;
T_2 V_104 [ F_6 ( V_14 ) ] , V_10 ;
int V_105 ;
V_79 = F_31 ( V_103 -> V_76 , sizeof( * V_79 ) , V_106 ) ;
if ( ! V_79 )
return F_32 ( - V_107 ) ;
for ( V_10 = 0 ; V_10 < F_6 ( V_14 ) ; V_10 ++ )
V_104 [ V_10 ] = V_14 [ V_10 ] . V_15 ;
V_105 = F_33 ( V_103 , V_79 , 0xff , & V_108 ,
V_104 , F_6 ( V_104 ) ,
V_109 , NULL ) ;
if ( V_105 ) {
F_34 ( V_103 -> V_76 , V_79 ) ;
return F_32 ( V_105 ) ;
}
F_35 ( V_79 , & V_110 ) ;
V_4 -> V_79 = V_79 ;
return V_79 ;
}
int F_36 ( struct V_102 * V_103 )
{
struct V_3 * V_4 = V_103 -> V_97 ;
struct V_78 * V_11 ;
int V_105 ;
V_11 = F_30 ( V_103 ) ;
if ( F_37 ( V_11 ) )
return F_38 ( V_11 ) ;
V_105 = F_39 ( V_103 , & V_4 -> V_2 , V_11 , NULL ,
& V_111 , NULL ) ;
if ( V_105 ) {
F_27 ( V_11 ) ;
F_34 ( V_103 -> V_76 , V_11 ) ;
return V_105 ;
}
F_40 ( & V_4 -> V_2 , & V_112 ) ;
return 0 ;
}
