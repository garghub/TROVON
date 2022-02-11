static int F_1 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 == 0x10CF && V_2 -> V_4 == 0x10AF )
return 1 ;
if ( V_2 -> V_3 == 0x1071 && V_2 -> V_4 == 0x8317 )
return 1 ;
if ( F_2 ( V_5 ) )
return 1 ;
return 0 ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 -> V_8 -> V_9 ) ;
T_1 V_10 ;
if ( F_1 ( V_2 ) )
return V_11 ;
F_5 ( V_2 , 0x4A , & V_10 ) ;
if ( V_10 & ( 1 << V_7 -> V_12 ) )
return V_13 ;
else
return V_14 ;
}
static unsigned long F_6 ( struct V_15 * V_16 , unsigned long V_17 )
{
char V_18 [ V_19 + 1 ] ;
if ( V_16 -> V_20 != V_21 )
V_17 &= ~ ( V_22 | V_23 ) ;
F_7 ( V_16 -> V_24 , V_18 , V_25 , sizeof( V_18 ) ) ;
if ( strstr ( V_18 , L_1 ) )
return V_17 &= ~ V_23 ;
return V_17 ;
}
static void F_8 ( struct V_6 * V_7 , struct V_15 * V_16 , int V_26 )
{
struct V_1 * V_2 = F_4 ( V_7 -> V_8 -> V_9 ) ;
int V_27 = 0x54 + V_7 -> V_12 ;
T_1 V_28 ;
int V_29 = 4 * V_16 -> V_30 ;
F_5 ( V_2 , V_27 , & V_28 ) ;
V_28 &= ~ ( 0x0F << V_29 ) ;
V_28 |= ( V_26 << V_29 ) ;
F_9 ( V_2 , V_27 , V_28 ) ;
}
static void F_10 ( struct V_6 * V_7 , struct V_15 * V_16 , struct V_31 * V_32 , T_1 V_33 )
{
struct V_1 * V_2 = F_4 ( V_7 -> V_8 -> V_9 ) ;
int V_34 = 0x58 + 4 * V_7 -> V_12 ;
int V_35 = 0x59 + 4 * V_7 -> V_12 ;
int V_36 = 0x5A + 4 * V_7 -> V_12 + V_16 -> V_30 ;
int V_37 = 0x56 + V_7 -> V_12 ;
int V_29 = 4 * V_16 -> V_30 ;
T_1 V_38 ;
if ( V_32 != NULL ) {
V_32 -> V_39 = F_11 ( V_32 -> V_39 , 1 , 8 ) & 7 ;
V_32 -> V_40 = F_11 ( V_32 -> V_40 , 1 , 8 ) & 7 ;
V_32 -> V_41 = F_11 ( V_32 -> V_41 , 1 , 16 ) & 15 ;
V_32 -> V_42 = F_11 ( V_32 -> V_42 , 1 , 8 ) & 7 ;
V_32 -> V_43 = F_11 ( V_32 -> V_43 , 1 , 16 ) & 15 ;
F_9 ( V_2 , V_34 , V_32 -> V_39 ) ;
F_9 ( V_2 , V_35 , ( V_32 -> V_40 << 4 ) | V_32 -> V_41 ) ;
F_9 ( V_2 , V_36 , ( V_32 -> V_42 << 4 ) | V_32 -> V_43 ) ;
}
F_5 ( V_2 , V_37 , & V_38 ) ;
V_38 &= ~ ( 0x0F << V_29 ) ;
V_38 |= V_33 << V_29 ;
F_9 ( V_2 , V_37 , V_38 ) ;
}
static void F_12 ( struct V_6 * V_7 , struct V_15 * V_16 )
{
struct V_15 * V_44 = F_13 ( V_16 ) ;
struct V_31 V_32 ;
unsigned long V_45 = 1000000000 / 33333 ;
F_14 ( V_16 , V_16 -> V_46 , & V_32 , V_45 , 1 ) ;
if ( V_44 ) {
struct V_31 V_47 ;
F_14 ( V_44 , V_44 -> V_46 , & V_47 , V_45 , 1 ) ;
F_15 ( & V_47 , & V_32 , & V_32 , V_48 | V_49 ) ;
if ( V_44 -> V_50 ) {
F_14 ( V_44 , V_44 -> V_50 , & V_47 , V_45 , 1 ) ;
F_15 ( & V_47 , & V_32 , & V_32 , V_48 | V_49 ) ;
}
}
if ( V_16 -> V_20 != V_21 )
F_8 ( V_7 , V_16 , 0x00 ) ;
F_10 ( V_7 , V_16 , & V_32 , 0 ) ;
if ( V_16 -> V_20 == V_21 )
F_8 ( V_7 , V_16 , 0x05 ) ;
}
static void F_16 ( struct V_6 * V_7 , struct V_15 * V_16 )
{
static T_1 V_51 [ 7 ] = { 0xC , 0xB , 0xA , 0x9 , 0x8 , 0xF , 0xD } ;
struct V_15 * V_44 = F_13 ( V_16 ) ;
struct V_31 V_32 ;
unsigned long V_45 = 1000000000 / 33333 ;
struct V_1 * V_2 = F_4 ( V_7 -> V_8 -> V_9 ) ;
if ( V_16 -> V_20 == V_21 )
F_8 ( V_7 , V_16 , 0x08 ) ;
if ( V_16 -> V_50 >= V_52 ) {
F_10 ( V_7 , V_16 , NULL , V_51 [ V_16 -> V_50 - V_52 ] ) ;
if ( V_16 -> V_50 >= V_53 ) {
T_1 V_54 ;
F_5 ( V_2 , 0x4B , & V_54 ) ;
V_54 |= 1 ;
F_9 ( V_2 , 0x4B , V_54 ) ;
}
} else {
F_14 ( V_16 , V_16 -> V_50 , & V_32 , V_45 , 1 ) ;
if ( V_44 ) {
struct V_31 V_47 ;
F_14 ( V_44 , V_44 -> V_46 , & V_47 , V_45 , 1 ) ;
F_15 ( & V_47 , & V_32 , & V_32 , V_48 | V_49 ) ;
if ( V_44 -> V_50 ) {
F_14 ( V_44 , V_44 -> V_50 , & V_47 , V_45 , 1 ) ;
F_15 ( & V_47 , & V_32 , & V_32 , V_48 | V_49 ) ;
}
}
F_10 ( V_7 , V_16 , & V_32 , 0 ) ;
}
}
static void F_17 ( struct V_15 * V_16 )
{
struct V_55 * V_56 = & V_16 -> V_57 -> V_58 ;
int V_59 = V_56 -> V_60 . V_61 & V_62 ;
if ( V_59 && V_16 -> V_20 == V_63 && ! V_64 ) {
F_18 ( V_16 ,
L_2 ) ;
F_18 ( V_16 ,
L_3 ) ;
}
}
static void F_19 ( struct V_15 * V_16 )
{
V_16 -> V_65 = 255 ;
F_17 ( V_16 ) ;
}
static int F_20 ( struct V_66 * V_67 )
{
if ( ! V_64 ) {
return - V_68 ;
}
if ( F_21 ( V_67 -> V_69 [ 0 ] ) == V_70 )
return - V_68 ;
return 0 ;
}
static void F_22 ( struct V_71 * V_57 , unsigned int * V_72 )
{
T_1 V_73 ;
int V_74 = 4 << V_57 -> V_7 -> V_12 ;
if ( V_75 ) {
F_5 ( V_75 , 0x58 , & V_73 ) ;
V_73 &= ~ V_74 ;
F_9 ( V_75 , 0x58 , V_73 ) ;
V_73 |= V_74 ;
F_9 ( V_75 , 0x58 , V_73 ) ;
}
F_23 ( V_57 , V_72 ) ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_1 V_76 ;
struct V_1 * V_77 ;
if ( V_2 -> V_78 <= 0x20 ) {
F_5 ( V_2 , 0x53 , & V_76 ) ;
V_76 |= 0x03 ;
F_9 ( V_2 , 0x53 , V_76 ) ;
} else {
F_5 ( V_2 , 0x4a , & V_76 ) ;
F_9 ( V_2 , 0x4a , V_76 | 0x20 ) ;
F_5 ( V_2 , 0x4B , & V_76 ) ;
if ( V_2 -> V_78 < 0xC2 )
V_76 &= 0x7F ;
if ( V_2 -> V_78 >= 0xc2 )
V_76 |= 0x01 ;
F_9 ( V_2 , 0x4B , V_76 | 0x08 ) ;
F_5 ( V_2 , 0x53 , & V_76 ) ;
if ( V_2 -> V_78 >= 0xc7 )
V_76 |= 0x03 ;
else
V_76 |= 0x01 ;
F_9 ( V_2 , 0x53 , V_76 ) ;
}
V_77 = F_25 ( 0 , F_26 ( 0 , 0 ) ) ;
if ( V_77 && V_77 -> V_79 == V_80 && V_75 ) {
F_5 ( V_75 , 0x79 , & V_76 ) ;
if ( V_2 -> V_78 == 0xC2 )
F_9 ( V_75 , 0x79 , V_76 | 0x04 ) ;
else if ( V_2 -> V_78 > 0xC2 && V_2 -> V_78 < 0xC5 )
F_9 ( V_75 , 0x79 , V_76 | 0x02 ) ;
}
F_27 ( V_77 ) ;
F_28 ( V_2 ) ;
}
static int F_29 ( struct V_1 * V_2 , const struct V_81 * V_24 )
{
static const struct V_82 V_83 = {
. V_61 = V_84 ,
. V_85 = V_86 ,
. V_87 = & V_88
} ;
static const struct V_82 V_89 = {
. V_61 = V_84 | V_90 |
V_91 ,
. V_85 = V_86 ,
. V_92 = V_93 ,
. V_87 = & V_94
} ;
static const struct V_82 V_95 = {
. V_61 = V_84 | V_90 |
V_91 ,
. V_85 = V_86 ,
. V_92 = V_93 ,
. V_96 = V_97 ,
. V_87 = & V_94
} ;
static const struct V_82 V_98 = {
. V_61 = V_84 | V_90 |
V_91 ,
. V_85 = V_86 ,
. V_92 = V_93 ,
. V_96 = V_99 ,
. V_87 = & V_100
} ;
static const struct V_82 V_101 = {
. V_61 = V_84 | V_90 |
V_91 ,
. V_85 = V_86 ,
. V_92 = V_93 ,
. V_96 = V_99 ,
. V_87 = & V_100
} ;
static const struct V_82 V_102 = {
. V_61 = V_84 | V_90 |
V_91 ,
. V_85 = V_86 ,
. V_92 = V_93 ,
. V_96 = V_103 ,
. V_87 = & V_104
} ;
static const struct V_82 V_105 = {
. V_61 = V_84 | V_91 ,
. V_85 = V_86 ,
. V_92 = V_93 ,
. V_96 = V_106 ,
. V_87 = & V_107
} ;
const struct V_82 * V_108 [] = { NULL , NULL } ;
T_1 V_76 ;
int V_109 ;
V_109 = F_30 ( V_2 ) ;
if ( V_109 )
return V_109 ;
if ( V_2 -> V_78 < 0x20 ) {
V_108 [ 0 ] = & V_83 ;
} else if ( V_2 -> V_78 < 0xC2 ) {
V_108 [ 0 ] = & V_89 ;
} else if ( V_2 -> V_78 == 0xC2 ) {
V_108 [ 0 ] = & V_98 ;
} else if ( V_2 -> V_78 == 0xC3 ) {
V_108 [ 0 ] = & V_101 ;
} else if ( V_2 -> V_78 == 0xC4 ) {
V_108 [ 0 ] = & V_102 ;
} else
V_108 [ 0 ] = & V_105 ;
F_24 ( V_2 ) ;
if ( V_75 && V_2 -> V_78 >= 0x20 && V_2 -> V_78 < 0xC2 ) {
F_5 ( V_75 , 0x5E , & V_76 ) ;
if ( ( V_76 & 0x1E ) == 0x12 )
V_108 [ 0 ] = & V_95 ;
}
if ( ! V_108 [ 0 ] -> V_92 && ! V_108 [ 0 ] -> V_96 )
return F_31 ( V_2 , V_108 , & V_110 , NULL , 0 ) ;
else
return F_32 ( V_2 , V_108 , & V_110 , NULL , 0 ) ;
}
static int F_33 ( struct V_1 * V_2 )
{
struct V_111 * V_8 = F_34 ( & V_2 -> V_9 ) ;
int V_109 ;
V_109 = F_35 ( V_2 ) ;
if ( V_109 )
return V_109 ;
F_24 ( V_2 ) ;
F_36 ( V_8 ) ;
return 0 ;
}
static int T_2 F_37 ( void )
{
int V_112 ;
V_75 = F_38 ( V_80 , V_113 , NULL ) ;
V_112 = F_39 ( & V_114 ) ;
if ( V_112 < 0 )
F_27 ( V_75 ) ;
return V_112 ;
}
static void T_3 F_40 ( void )
{
F_41 ( & V_114 ) ;
F_27 ( V_75 ) ;
}
