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
F_13 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_2 ) ;
F_3 ( V_4 , V_5 , 0 ) ;
F_16 ( V_4 -> V_66 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_68 * V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_26 * V_69 = & V_12 -> V_28 ;
long V_70 , V_71 = V_69 -> clock * 1000 ;
V_70 = F_18 ( V_4 -> V_66 , V_71 ) ;
if ( V_70 != V_71 ) {
return - V_72 ;
}
return 0 ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_68 * V_12 )
{
struct V_73 * V_74 = V_2 -> V_12 -> V_74 ;
if ( V_74 ) {
V_2 -> V_12 -> V_74 = NULL ;
F_20 ( & V_2 -> V_75 -> V_76 ) ;
if ( F_21 ( V_2 ) == 0 )
F_22 ( V_2 , V_74 ) ;
else
F_23 ( V_2 , V_74 ) ;
F_24 ( & V_2 -> V_75 -> V_76 ) ;
}
}
static int F_25 ( struct V_77 * V_78 ,
struct V_79 * V_12 )
{
T_2 V_80 , V_81 ;
V_80 = V_12 -> V_80 >> 16 ;
V_81 = V_12 -> V_81 >> 16 ;
if ( ( V_80 != V_12 -> V_82 ) || ( V_81 != V_12 -> V_83 ) )
return - V_72 ;
return 0 ;
}
static void F_26 ( struct V_77 * V_78 ,
struct V_79 * V_12 )
{
struct V_3 * V_4 ;
struct V_84 * V_85 ;
T_2 V_80 , V_81 , V_86 , V_87 ;
T_3 V_88 ;
if ( ! V_78 -> V_12 -> V_13 )
return;
V_80 = V_78 -> V_12 -> V_80 >> 16 ;
V_81 = V_78 -> V_12 -> V_81 >> 16 ;
V_86 = V_78 -> V_12 -> V_82 ;
V_87 = V_78 -> V_12 -> V_83 ;
V_85 = F_27 ( V_78 -> V_12 -> V_13 , 0 ) ;
V_88 = V_85 -> V_89 + V_78 -> V_12 -> V_13 -> V_90 [ 0 ] +
V_78 -> V_12 -> V_91 * V_78 -> V_12 -> V_13 -> V_92 [ 0 ] +
V_78 -> V_12 -> V_93 *
F_28 ( V_78 -> V_12 -> V_13 -> V_7 , 0 ) ;
V_4 = V_78 -> V_75 -> V_94 ;
F_3 ( V_4 , V_95 , V_78 -> V_12 -> V_13 -> V_92 [ 0 ] ) ;
F_3 ( V_4 , V_96 , V_78 -> V_12 -> V_13 -> V_92 [ 0 ] ) ;
F_3 ( V_4 , V_97 , V_87 - 1 ) ;
F_3 ( V_4 , V_98 , V_88 ) ;
}
static void F_29 ( struct V_77 * V_78 )
{
F_30 ( V_78 ) ;
F_31 ( V_78 ) ;
}
static struct V_77 * F_32 ( struct V_99 * V_100 )
{
struct V_3 * V_4 = V_100 -> V_94 ;
struct V_77 * V_78 = NULL ;
T_2 V_101 [ F_6 ( V_14 ) ] , V_10 ;
int V_102 ;
V_78 = F_33 ( V_100 -> V_75 , sizeof( * V_78 ) , V_103 ) ;
if ( ! V_78 )
return F_34 ( - V_104 ) ;
for ( V_10 = 0 ; V_10 < F_6 ( V_14 ) ; V_10 ++ )
V_101 [ V_10 ] = V_14 [ V_10 ] . V_15 ;
V_102 = F_35 ( V_100 , V_78 , 0xff , & V_105 ,
V_101 , F_6 ( V_101 ) ,
V_106 , NULL ) ;
if ( V_102 ) {
F_36 ( V_100 -> V_75 , V_78 ) ;
return F_34 ( V_102 ) ;
}
F_37 ( V_78 , & V_107 ) ;
V_4 -> V_78 = V_78 ;
return V_78 ;
}
int F_38 ( struct V_99 * V_100 )
{
struct V_3 * V_4 = V_100 -> V_94 ;
struct V_77 * V_11 ;
int V_102 ;
V_11 = F_32 ( V_100 ) ;
if ( F_39 ( V_11 ) )
return F_40 ( V_11 ) ;
V_102 = F_41 ( V_100 , & V_4 -> V_2 , V_11 , NULL ,
& V_108 , NULL ) ;
if ( V_102 ) {
F_29 ( V_11 ) ;
F_36 ( V_100 -> V_75 , V_11 ) ;
return V_102 ;
}
F_42 ( & V_4 -> V_2 , & V_109 ) ;
return 0 ;
}
