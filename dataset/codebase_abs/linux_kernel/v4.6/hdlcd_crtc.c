static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
T_1 V_6 ;
struct V_7 * V_8 = NULL ;
int V_9 ;
V_6 = V_2 -> V_10 -> V_11 -> V_12 -> V_6 ;
for ( V_9 = 0 ; V_9 < F_3 ( V_13 ) ; V_9 ++ ) {
if ( V_13 [ V_9 ] . V_14 == V_6 )
V_8 = & V_13 [ V_9 ] ;
}
if ( F_4 ( ! V_8 ) )
return 0 ;
V_3 = ( V_8 -> V_15 + 7 ) / 8 ;
F_5 ( V_5 , V_16 , ( V_3 - 1 ) << 3 ) ;
F_5 ( V_5 , V_17 , V_8 -> V_18 . V_19 |
#ifdef F_6
0x00ff0000 |
#endif
( ( V_8 -> V_18 . V_20 & 0xf ) << 8 ) ) ;
F_5 ( V_5 , V_21 , V_8 -> V_22 . V_19 |
( ( V_8 -> V_22 . V_20 & 0xf ) << 8 ) ) ;
F_5 ( V_5 , V_23 , V_8 -> V_24 . V_19 |
( ( V_8 -> V_24 . V_20 & 0xf ) << 8 ) ) ;
return 0 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_26 = & V_2 -> V_11 -> V_27 ;
struct V_28 V_29 ;
unsigned int V_30 , V_31 , V_32 ;
V_29 . V_33 = V_26 -> V_34 - V_26 -> V_35 ;
V_29 . V_36 = V_26 -> V_37 - V_26 -> V_38 ;
V_29 . V_39 = V_26 -> V_38 - V_26 -> V_34 ;
V_29 . V_40 = V_26 -> V_41 - V_26 -> V_42 ;
V_29 . V_43 = V_26 -> V_44 - V_26 -> V_45 ;
V_29 . V_46 = V_26 -> V_45 - V_26 -> V_41 ;
V_30 = V_47 | V_48 ;
if ( V_26 -> V_49 & V_50 )
V_30 |= V_51 ;
if ( V_26 -> V_49 & V_52 )
V_30 |= V_53 ;
V_31 = V_2 -> V_10 -> V_11 -> V_12 -> V_54 [ 0 ] ;
F_5 ( V_5 , V_55 ,
V_56 | V_57 ) ;
F_5 ( V_5 , V_58 , V_31 ) ;
F_5 ( V_5 , V_59 , V_31 ) ;
F_5 ( V_5 , V_60 , V_26 -> V_35 - 1 ) ;
F_5 ( V_5 , V_61 , V_26 -> V_35 - 1 ) ;
F_5 ( V_5 , V_62 , V_29 . V_36 - 1 ) ;
F_5 ( V_5 , V_63 , V_29 . V_33 - 1 ) ;
F_5 ( V_5 , V_64 , V_29 . V_39 - 1 ) ;
F_5 ( V_5 , V_65 , V_29 . V_43 - 1 ) ;
F_5 ( V_5 , V_66 , V_29 . V_40 - 1 ) ;
F_5 ( V_5 , V_67 , V_29 . V_46 - 1 ) ;
F_5 ( V_5 , V_68 , V_26 -> V_42 - 1 ) ;
F_5 ( V_5 , V_69 , V_30 ) ;
V_32 = F_1 ( V_2 ) ;
if ( V_32 )
return;
F_8 ( V_5 -> V_70 , V_26 -> V_71 * 1000 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_10 ( V_5 -> V_70 ) ;
F_5 ( V_5 , V_72 , 1 ) ;
F_11 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( ! V_2 -> V_10 -> V_12 )
return;
F_13 ( V_5 -> V_70 ) ;
F_5 ( V_5 , V_72 , 0 ) ;
F_14 ( V_2 ) ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_73 * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_25 * V_74 = & V_11 -> V_27 ;
long V_75 , V_76 = V_74 -> clock * 1000 ;
V_75 = F_16 ( V_5 -> V_70 , V_76 ) ;
if ( V_75 != V_76 ) {
return - V_77 ;
}
return 0 ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_73 * V_11 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long V_49 ;
if ( V_2 -> V_11 -> V_78 ) {
struct V_79 * V_78 = V_2 -> V_11 -> V_78 ;
V_2 -> V_11 -> V_78 = NULL ;
V_78 -> V_80 = F_18 ( V_2 ) ;
F_4 ( F_19 ( V_2 ) != 0 ) ;
F_20 ( & V_2 -> V_81 -> V_82 , V_49 ) ;
F_21 ( & V_78 -> V_83 . V_84 , & V_5 -> V_85 ) ;
F_22 ( & V_2 -> V_81 -> V_82 , V_49 ) ;
}
}
static void F_23 ( struct V_1 * V_2 ,
struct V_73 * V_11 )
{
}
static bool F_24 ( struct V_1 * V_2 ,
const struct V_25 * V_74 ,
struct V_25 * V_27 )
{
return true ;
}
static int F_25 ( struct V_86 * V_87 ,
struct V_88 * V_11 )
{
return 0 ;
}
static void F_26 ( struct V_86 * V_87 ,
struct V_88 * V_11 )
{
struct V_4 * V_5 ;
struct V_89 * V_90 ;
T_2 V_91 ;
if ( ! V_87 -> V_11 -> V_2 || ! V_87 -> V_11 -> V_12 )
return;
V_5 = F_2 ( V_87 -> V_11 -> V_2 ) ;
V_90 = F_27 ( V_87 -> V_11 -> V_12 , 0 ) ;
V_91 = V_90 -> V_92 ;
F_5 ( V_5 , V_93 , V_91 ) ;
}
static void F_28 ( struct V_86 * V_87 )
{
F_29 ( V_87 ) ;
F_30 ( V_87 ) ;
}
static struct V_86 * F_31 ( struct V_94 * V_95 )
{
struct V_4 * V_5 = V_95 -> V_96 ;
struct V_86 * V_87 = NULL ;
T_3 V_97 [ F_3 ( V_13 ) ] , V_9 ;
int V_98 ;
V_87 = F_32 ( V_95 -> V_81 , sizeof( * V_87 ) , V_99 ) ;
if ( ! V_87 )
return F_33 ( - V_100 ) ;
for ( V_9 = 0 ; V_9 < F_3 ( V_13 ) ; V_9 ++ )
V_97 [ V_9 ] = V_13 [ V_9 ] . V_14 ;
V_98 = F_34 ( V_95 , V_87 , 0xff , & V_101 ,
V_97 , F_3 ( V_97 ) ,
V_102 , NULL ) ;
if ( V_98 ) {
F_35 ( V_95 -> V_81 , V_87 ) ;
return F_33 ( V_98 ) ;
}
F_36 ( V_87 , & V_103 ) ;
V_5 -> V_87 = V_87 ;
return V_87 ;
}
void F_37 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_9 ( V_2 ) ;
}
int F_39 ( struct V_94 * V_95 )
{
struct V_4 * V_5 = V_95 -> V_96 ;
struct V_86 * V_10 ;
int V_98 ;
V_10 = F_31 ( V_95 ) ;
if ( F_40 ( V_10 ) )
return F_41 ( V_10 ) ;
V_98 = F_42 ( V_95 , & V_5 -> V_2 , V_10 , NULL ,
& V_104 , NULL ) ;
if ( V_98 ) {
F_28 ( V_10 ) ;
F_35 ( V_95 -> V_81 , V_10 ) ;
return V_98 ;
}
F_43 ( & V_5 -> V_2 , & V_105 ) ;
return 0 ;
}
