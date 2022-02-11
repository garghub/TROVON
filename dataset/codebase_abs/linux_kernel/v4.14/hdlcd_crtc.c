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
static void F_14 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_15 ( V_4 -> V_70 ) ;
F_12 ( V_2 ) ;
F_3 ( V_4 , V_5 , 1 ) ;
F_16 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
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
struct V_30 * V_74 = & V_13 -> V_32 ;
long V_75 , V_76 = V_74 -> clock * 1000 ;
V_75 = F_21 ( V_4 -> V_70 , V_76 ) ;
if ( V_75 != V_76 ) {
return - V_77 ;
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_72 * V_13 )
{
struct V_78 * V_79 = V_2 -> V_13 -> V_79 ;
if ( V_79 ) {
V_2 -> V_13 -> V_79 = NULL ;
F_23 ( & V_2 -> V_80 -> V_81 ) ;
if ( F_24 ( V_2 ) == 0 )
F_25 ( V_2 , V_79 ) ;
else
F_26 ( V_2 , V_79 ) ;
F_27 ( & V_2 -> V_80 -> V_81 ) ;
}
}
static int F_28 ( struct V_82 * V_83 ,
struct V_84 * V_13 )
{
struct V_85 V_86 = { 0 } ;
struct V_72 * V_87 ;
T_2 V_88 = V_13 -> V_88 >> 16 ;
if ( V_88 >= V_89 ) {
F_29 ( L_1 , V_88 ) ;
return - V_77 ;
}
if ( ! V_13 -> V_11 || ! V_13 -> V_2 )
return 0 ;
V_87 = F_30 ( V_13 -> V_13 ,
V_13 -> V_2 ) ;
if ( ! V_87 ) {
F_29 ( L_2 ) ;
return - V_77 ;
}
V_86 . V_90 = V_87 -> V_32 . V_91 ;
V_86 . V_92 = V_87 -> V_32 . V_93 ;
return F_31 ( V_13 , & V_86 ,
V_94 ,
V_94 ,
false , true ) ;
}
static void F_32 ( struct V_82 * V_83 ,
struct V_84 * V_13 )
{
struct V_10 * V_11 = V_83 -> V_13 -> V_11 ;
struct V_3 * V_4 ;
T_2 V_95 ;
T_3 V_96 ;
if ( ! V_11 )
return;
V_95 = F_33 ( & V_83 -> V_13 -> V_97 ) ;
V_96 = F_34 ( V_11 , V_83 -> V_13 , 0 ) ;
V_4 = V_83 -> V_80 -> V_98 ;
F_3 ( V_4 , V_99 , V_11 -> V_100 [ 0 ] ) ;
F_3 ( V_4 , V_101 , V_11 -> V_100 [ 0 ] ) ;
F_3 ( V_4 , V_102 , V_95 - 1 ) ;
F_3 ( V_4 , V_103 , V_96 ) ;
}
static void F_35 ( struct V_82 * V_83 )
{
F_36 ( V_83 ) ;
F_37 ( V_83 ) ;
}
static struct V_82 * F_38 ( struct V_104 * V_105 )
{
struct V_3 * V_4 = V_105 -> V_98 ;
struct V_82 * V_83 = NULL ;
T_2 V_106 [ F_9 ( V_18 ) ] , V_17 ;
int V_107 ;
V_83 = F_39 ( V_105 -> V_80 , sizeof( * V_83 ) , V_108 ) ;
if ( ! V_83 )
return F_40 ( - V_109 ) ;
for ( V_17 = 0 ; V_17 < F_9 ( V_18 ) ; V_17 ++ )
V_106 [ V_17 ] = V_18 [ V_17 ] . V_19 ;
V_107 = F_41 ( V_105 , V_83 , 0xff , & V_110 ,
V_106 , F_9 ( V_106 ) ,
NULL ,
V_111 , NULL ) ;
if ( V_107 ) {
return F_40 ( V_107 ) ;
}
F_42 ( V_83 , & V_112 ) ;
V_4 -> V_83 = V_83 ;
return V_83 ;
}
int F_43 ( struct V_104 * V_105 )
{
struct V_3 * V_4 = V_105 -> V_98 ;
struct V_82 * V_12 ;
int V_107 ;
V_12 = F_38 ( V_105 ) ;
if ( F_44 ( V_12 ) )
return F_45 ( V_12 ) ;
V_107 = F_46 ( V_105 , & V_4 -> V_2 , V_12 , NULL ,
& V_113 , NULL ) ;
if ( V_107 ) {
F_35 ( V_12 ) ;
return V_107 ;
}
F_47 ( & V_4 -> V_2 , & V_114 ) ;
return 0 ;
}
