static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
int V_5 , unsigned int V_6 ,
struct V_7 * V_8 )
{
const struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
if ( ! F_2 ( V_4 ) [ V_11 ] && ! F_3 ( V_4 , V_11 , 0 ) )
return - V_12 ;
V_8 -> V_8 . V_13 = V_14 ;
V_8 -> V_8 . V_15 = F_4 ( V_4 , V_11 ) + V_6 ;
V_8 -> V_8 . V_16 = F_2 ( V_4 ) [ V_11 ] + V_6 ;
V_8 -> V_8 . V_17 = V_10 -> V_18 ;
return 0 ;
}
static int
F_5 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
unsigned int V_6 = V_5 * 0x200 ;
unsigned int V_19 = 1843200 ;
T_1 T_2 * V_20 ;
int V_21 ;
V_8 -> V_8 . V_22 = V_19 * 16 ;
V_21 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
if ( V_21 )
return V_21 ;
V_20 = V_8 -> V_8 . V_16 ;
F_6 ( 0x00 , V_20 + V_23 ) ;
F_6 ( V_24 , V_20 + V_25 ) ;
F_6 ( 32 , V_20 + V_26 ) ;
F_6 ( 32 , V_20 + V_27 ) ;
if ( V_5 == 0 ) {
switch ( V_4 -> V_28 ) {
case V_29 :
case V_30 :
F_6 ( 0x78 , V_20 + V_31 ) ;
F_6 ( 0x00 , V_20 + V_32 ) ;
F_6 ( 0x00 , V_20 + V_33 ) ;
break;
case V_34 :
case V_35 :
F_6 ( 0x00 , V_20 + V_31 ) ;
F_6 ( 0xc0 , V_20 + V_32 ) ;
F_6 ( 0xc0 , V_20 + V_33 ) ;
break;
}
F_6 ( 0x00 , V_20 + V_36 ) ;
F_6 ( 0x00 , V_20 + V_37 ) ;
F_6 ( 0x00 , V_20 + V_38 ) ;
}
return 0 ;
}
static int
F_7 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
unsigned int V_6 = V_5 * 0x200 ;
unsigned int V_19 = 1843200 ;
V_8 -> V_8 . V_22 = V_19 * 16 ;
return F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
}
static int
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
unsigned int V_6 = V_5 * 0x200 ;
unsigned int V_19 = 921600 ;
V_8 -> V_8 . V_22 = V_19 * 16 ;
return F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
}
static void F_9 ( struct V_3 * V_4 , T_1 T_2 * V_20 )
{
T_1 V_39 = V_4 -> V_40 == V_41 ? 0xff : 0x00 ;
F_6 ( 0x00 , V_20 + V_36 ) ;
F_6 ( 0x00 , V_20 + V_31 ) ;
F_6 ( 0x00 , V_20 + V_37 ) ;
F_6 ( 0x00 , V_20 + V_32 ) ;
F_6 ( V_39 , V_20 + V_33 ) ;
F_6 ( 0x00 , V_20 + V_38 ) ;
F_6 ( 0x00 , V_20 + V_42 ) ;
F_6 ( 0x00 , V_20 + V_43 ) ;
F_6 ( 0x00 , V_20 + V_44 ) ;
F_6 ( 0x00 , V_20 + V_45 ) ;
F_6 ( V_39 , V_20 + V_46 ) ;
F_6 ( 0x00 , V_20 + V_47 ) ;
}
static void *
F_10 ( struct V_3 * V_4 ,
const struct V_48 * V_49 )
{
struct V_50 * V_51 ;
V_51 = F_11 ( L_1 , V_52 ) ;
if ( ! V_51 )
return NULL ;
V_51 -> V_53 . V_54 = & V_4 -> V_53 ;
F_12 ( & V_51 -> V_53 , F_13 ( & V_4 -> V_53 ) ) ;
if ( F_14 ( V_51 , V_49 ) < 0 ||
F_15 ( V_51 ) < 0 ) {
F_16 ( V_51 ) ;
return NULL ;
}
return V_51 ;
}
static int F_17 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
if ( V_4 -> V_40 == V_41 )
V_8 -> V_8 . V_55 =
F_10 ( V_4 , V_56 ) ;
return 0 ;
}
static int F_18 ( struct V_57 * V_8 ,
struct V_58 * V_59 )
{
bool V_60 = ! ! ( V_59 -> V_61 & V_62 ) ;
T_1 T_2 * V_20 = V_8 -> V_16 ;
T_1 V_63 = V_64 ;
T_1 V_65 , V_66 ;
if ( V_60 ) {
if ( V_59 -> V_61 & V_67 )
V_65 = V_68 ;
else
V_65 = V_69 ;
if ( V_59 -> V_61 & V_70 )
V_65 |= V_71 ;
} else {
V_65 = V_72 ;
}
if ( V_8 -> line == 3 ) {
V_63 <<= V_73 ;
V_65 <<= V_73 ;
}
V_66 = F_19 ( V_20 + V_31 ) ;
V_66 &= ~ V_63 ;
V_66 |= V_65 ;
F_6 ( V_66 , V_20 + V_31 ) ;
V_66 = F_19 ( V_20 + V_25 ) ;
if ( V_60 )
V_66 |= V_74 ;
else
V_66 &= ~ V_74 ;
F_6 ( V_66 , V_20 + V_25 ) ;
if ( V_60 )
F_6 ( F_20 ( 4 ) , V_20 + V_75 ) ;
V_8 -> V_59 = * V_59 ;
return 0 ;
}
static int F_21 ( struct V_3 * V_4 ,
struct V_7 * V_8 )
{
T_1 T_2 * V_20 = V_8 -> V_8 . V_16 ;
F_6 ( V_76 , V_20 + V_31 ) ;
F_6 ( V_77 , V_20 + V_33 ) ;
F_6 ( V_78 , V_20 + V_43 ) ;
F_6 ( V_79 , V_20 + V_46 ) ;
V_8 -> V_8 . V_55 =
F_10 ( V_4 , V_80 ) ;
return 0 ;
}
static int
F_22 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_7 * V_8 , int V_5 )
{
const struct V_9 * V_10 = V_2 -> V_10 ;
const struct V_81 * V_82 ;
const struct V_83 * V_84 ;
unsigned int V_6 = V_5 * 0x400 ;
unsigned int V_19 = 7812500 ;
T_1 T_2 * V_20 ;
int V_85 ;
V_84 = F_23 ( V_86 ) ;
if ( V_84 )
V_82 = V_84 -> V_87 ;
else
V_82 = & V_88 ;
V_8 -> V_8 . V_22 = V_19 * 16 ;
V_8 -> V_8 . V_89 = V_82 -> V_89 ;
if ( V_10 -> V_90 && V_5 >= 8 )
V_8 -> V_8 . V_22 /= 2 ;
V_85 = F_1 ( V_2 , V_4 , V_5 , V_6 , V_8 ) ;
if ( V_85 )
return V_85 ;
V_20 = V_8 -> V_8 . V_16 ;
F_6 ( 0x00 , V_20 + V_23 ) ;
F_6 ( V_24 , V_20 + V_25 ) ;
F_6 ( 128 , V_20 + V_26 ) ;
F_6 ( 128 , V_20 + V_27 ) ;
if ( V_5 == 0 ) {
F_9 ( V_4 , V_20 ) ;
V_85 = V_82 -> V_91 ( V_4 , V_8 ) ;
}
return V_85 ;
}
static void F_24 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_25 ( V_4 ) ;
struct V_7 * V_8 = F_26 ( V_2 -> line [ 0 ] ) ;
struct V_50 * V_51 = V_8 -> V_8 . V_55 ;
F_27 ( V_51 ) ;
V_8 -> V_8 . V_55 = NULL ;
}
static int
F_28 ( struct V_3 * V_4 , const struct V_92 * V_93 )
{
unsigned int V_94 , V_95 , V_11 = 0 , V_96 ;
struct V_9 * V_10 ;
struct V_7 V_97 ;
struct V_1 * V_2 ;
int V_98 ;
V_10 = (struct V_9 * ) V_93 -> V_87 ;
if ( ! V_10 )
return - V_99 ;
V_98 = F_29 ( V_4 ) ;
if ( V_98 )
return V_98 ;
V_96 = F_30 ( V_4 , V_11 ) >> ( V_10 -> V_18 + 3 ) ;
V_94 = V_10 -> V_100 ? V_10 -> V_100 : V_4 -> V_28 & 0x0f ;
V_2 = F_31 ( & V_4 -> V_53 , sizeof( * V_2 ) +
sizeof( unsigned int ) * V_94 ,
V_101 ) ;
if ( ! V_2 )
return - V_12 ;
V_2 -> V_10 = V_10 ;
F_32 ( V_4 ) ;
V_98 = F_33 ( V_4 , 1 , 1 , V_102 ) ;
if ( V_98 < 0 )
return V_98 ;
memset ( & V_97 , 0 , sizeof( V_97 ) ) ;
V_97 . V_8 . V_61 = V_103 | V_104 | V_105
| V_106 ;
V_97 . V_8 . V_107 = F_34 ( V_4 , 0 ) ;
V_97 . V_8 . V_53 = & V_4 -> V_53 ;
for ( V_95 = 0 ; V_95 < V_94 && V_95 < V_96 ; V_95 ++ ) {
V_98 = V_10 -> V_108 ( V_2 , V_4 , & V_97 , V_95 ) ;
if ( V_98 ) {
F_35 ( & V_4 -> V_53 , L_2 , V_95 ) ;
break;
}
F_36 ( & V_4 -> V_53 , L_3 ,
V_97 . V_8 . V_109 , V_97 . V_8 . V_107 , V_97 . V_8 . V_13 ) ;
V_2 -> line [ V_95 ] = F_37 ( & V_97 ) ;
if ( V_2 -> line [ V_95 ] < 0 ) {
F_35 ( & V_4 -> V_53 ,
L_4 ,
V_97 . V_8 . V_109 , V_97 . V_8 . V_107 ,
V_97 . V_8 . V_13 , V_2 -> line [ V_95 ] ) ;
break;
}
}
V_2 -> V_110 = V_95 ;
F_38 ( V_4 , V_2 ) ;
return 0 ;
}
static void F_39 ( struct V_3 * V_4 )
{
struct V_1 * V_2 = F_25 ( V_4 ) ;
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < V_2 -> V_110 ; V_95 ++ )
F_40 ( V_2 -> line [ V_95 ] ) ;
if ( V_2 -> V_10 -> exit )
V_2 -> V_10 -> exit ( V_4 ) ;
}
static int T_3 F_41 ( struct V_28 * V_53 )
{
struct V_3 * V_4 = F_42 ( V_53 ) ;
struct V_1 * V_2 = F_25 ( V_4 ) ;
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < V_2 -> V_110 ; V_95 ++ )
if ( V_2 -> line [ V_95 ] >= 0 )
F_43 ( V_2 -> line [ V_95 ] ) ;
if ( V_2 -> V_10 -> exit )
V_2 -> V_10 -> exit ( V_4 ) ;
return 0 ;
}
static int T_3 F_44 ( struct V_28 * V_53 )
{
struct V_3 * V_4 = F_42 ( V_53 ) ;
struct V_1 * V_2 = F_25 ( V_4 ) ;
unsigned int V_95 ;
for ( V_95 = 0 ; V_95 < V_2 -> V_110 ; V_95 ++ )
if ( V_2 -> line [ V_95 ] >= 0 )
F_45 ( V_2 -> line [ V_95 ] ) ;
return 0 ;
}
