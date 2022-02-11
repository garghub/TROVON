static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_2 , V_8 , V_3 , V_4 ) ;
if ( V_3 < F_3 ( V_6 -> V_9 ) )
V_6 -> V_9 [ V_3 ] = V_4 ;
}
static void F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 != V_6 -> V_9 [ V_3 ] )
F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_2 , V_10 , V_3 , V_4 ) ;
if ( V_3 < F_3 ( V_6 -> V_11 ) )
V_6 -> V_11 [ V_3 ] = V_4 ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 != V_6 -> V_11 [ V_3 ] )
F_5 ( V_2 , V_3 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_12 ;
F_1 ( V_2 , 8 , V_13 | V_14 ) ;
F_5 ( V_2 , 0x01 , V_15 | V_16 ) ;
F_1 ( V_2 , 2 , V_6 -> V_9 [ 2 ] ) ;
F_1 ( V_2 , 3 , V_17 | V_18 ) ;
F_1 ( V_2 , 4 , V_6 -> V_9 [ 4 ] ) ;
F_1 ( V_2 , 5 , V_6 -> V_9 [ 5 ] ) ;
F_1 ( V_2 , 6 , V_6 -> V_9 [ 6 ] ) ;
F_1 ( V_2 , 7 , V_6 -> V_9 [ 7 ] ) ;
F_5 ( V_2 , 0x02 , V_19 ) ;
F_5 ( V_2 , 0x03 , V_20 | V_21 |
V_22 | V_23 | V_24 ) ;
F_5 ( V_2 , 0x04 , V_6 -> V_11 [ 0x04 ] ) ;
F_5 ( V_2 , 0x05 , 0 ) ;
for ( V_12 = 6 ; V_12 <= 14 ; ++ V_12 )
F_5 ( V_2 , V_12 , V_6 -> V_11 [ V_12 ] ) ;
F_1 ( V_2 , 8 , V_13 ) ;
F_5 ( V_2 , 0x01 , V_16 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_25 . V_26 = 800 ;
V_6 -> V_25 . V_27 = V_28 ;
V_6 -> V_9 [ 2 ] =
V_29 | V_30 | V_31 ;
V_6 -> V_9 [ 4 ] = V_32 |
V_33 | V_34 | V_35 ;
V_6 -> V_9 [ 5 ] = 60 * 2 ;
V_6 -> V_9 [ 6 ] = 60 * 2 ;
V_6 -> V_9 [ 7 ] = V_36 | V_37 |
V_38 | V_39 ;
V_6 -> V_11 [ 4 ] = V_40 | V_41 ;
V_6 -> V_11 [ 6 ] = V_42 |
V_43 | V_44 ;
V_6 -> V_11 [ 7 ] = 60 | V_45 ;
V_6 -> V_11 [ 8 ] = 60 | V_45 ;
V_6 -> V_11 [ 9 ] = V_6 -> V_11 [ 6 ] ;
V_6 -> V_11 [ 10 ] = 60 | V_45 ;
V_6 -> V_11 [ 11 ] = 60 | V_45 ;
V_6 -> V_11 [ 12 ] = V_6 -> V_11 [ 6 ] ;
V_6 -> V_11 [ 13 ] = 60 | V_45 ;
V_6 -> V_11 [ 14 ] = 60 | V_45 ;
F_9 ( V_2 , V_46 ,
V_47 |
V_48 |
V_49 ) ;
F_7 ( V_2 ) ;
F_10 ( V_2 , V_50 ,
V_51 |
V_52 |
V_53 ) ;
F_11 ( V_2 , V_54 ,
V_51 | V_53 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 ) ;
F_14 ( V_2 -> V_55 , L_1 ) ;
F_14 ( V_2 -> V_55 , L_2 ) ;
F_14 ( V_2 -> V_55 , L_3 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_25 . V_56 = V_57 ;
V_6 -> V_25 . V_58 = V_59 ;
V_6 -> V_25 . V_60 = V_61 ;
F_16 ( V_2 ) ;
F_8 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 ) ;
F_5 ( V_2 , 0x01 , V_15 | V_16 ) ;
F_19 ( V_2 , V_62 , V_63 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_17 ( V_2 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
F_22 ( V_2 , V_62 , V_63 ) ;
F_23 ( 1 ) ;
F_7 ( V_2 ) ;
F_13 ( V_2 ) ;
}
static void F_24 ( struct V_1 * V_2 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_66 , V_67 ;
if ( F_25 ( V_65 ) <= 50000 ) {
V_66 = V_29 ;
V_67 = V_42 ;
} else if ( F_25 ( V_65 ) <= 100000 ) {
V_66 = V_68 ;
V_67 = V_69 ;
} else {
V_66 = V_70 ;
V_67 = V_71 ;
}
V_66 |= V_30 | V_31 ;
F_4 ( V_2 , 2 , V_66 ) ;
V_67 |= V_6 -> V_11 [ 6 ] & ~ V_72 ;
F_6 ( V_2 , 6 , V_67 ) ;
F_6 ( V_2 , 12 , V_67 ) ;
V_67 &= V_72 ;
V_67 |= V_6 -> V_11 [ 9 ] & ~ V_72 ;
F_6 ( V_2 , 9 , V_67 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
unsigned int V_12 ;
T_1 V_73 ;
V_73 = V_2 -> V_74 ? V_45 : 0 ;
for ( V_12 = 0 ; V_12 < 6 ; ++ V_12 )
F_6 ( V_2 , 7 + V_12 + V_12 / 2 ,
( 127 - V_2 -> V_75 [ 2 + V_12 ] ) | V_73 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
F_4 ( V_2 , 5 , ( 127 - V_2 -> V_75 [ 0 ] ) * 2 ) ;
F_4 ( V_2 , 6 , ( 127 - V_2 -> V_75 [ 1 ] ) * 2 ) ;
F_26 ( V_2 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
T_1 V_3 ;
V_3 = V_32 | V_35 ;
if ( V_2 -> V_74 )
V_3 |= V_33 | V_34 ;
F_4 ( V_2 , 4 , V_3 ) ;
F_26 ( V_2 ) ;
}
static void F_29 ( struct V_1 * V_2 , bool V_76 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_3 ;
V_3 = V_6 -> V_11 [ 9 ] & ~ V_77 ;
if ( V_76 )
V_3 |= V_78 | V_79 ;
else
V_3 |= V_43 | V_44 ;
F_6 ( V_2 , 9 , V_3 ) ;
}
static int F_30 ( struct V_80 * V_81 ,
struct V_82 * V_83 )
{
static const char * const V_84 [ 2 ] = {
L_4 , L_5
} ;
return F_31 ( V_83 , 1 , 2 , V_84 ) ;
}
static int F_32 ( struct V_80 * V_81 ,
struct V_85 * V_4 )
{
struct V_1 * V_2 = V_81 -> V_86 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 -> V_4 . V_87 . V_88 [ 0 ] =
( V_6 -> V_9 [ 7 ] & V_89 ) != 0 ;
return 0 ;
}
static int F_33 ( struct V_80 * V_81 ,
struct V_85 * V_4 )
{
struct V_1 * V_2 = V_81 -> V_86 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_90 ;
T_1 V_3 ;
F_34 ( & V_2 -> V_91 ) ;
V_3 = V_6 -> V_9 [ 7 ] ;
if ( V_4 -> V_4 . V_87 . V_88 [ 0 ] )
V_3 |= V_89 ;
else
V_3 &= ~ V_89 ;
V_90 = V_3 != V_6 -> V_9 [ 7 ] ;
if ( V_90 ) {
F_1 ( V_2 , 7 , V_3 ) ;
if ( V_3 & V_89 )
V_3 = V_6 -> V_11 [ 0x04 ] | V_92 ;
else
V_3 = V_6 -> V_11 [ 0x04 ] & ~ V_92 ;
F_5 ( V_2 , 0x04 , V_3 ) ;
}
F_35 ( & V_2 -> V_91 ) ;
return V_90 ;
}
static void F_36 ( struct V_1 * V_2 ,
unsigned int V_3 , unsigned int V_73 )
{
if ( V_3 == V_93 ) {
F_37 ( & V_2 -> V_94 ) ;
F_38 ( V_2 , V_54 ,
V_73 ? V_53 : 0 ,
V_53 ) ;
F_39 ( & V_2 -> V_94 ) ;
}
}
static int F_40 ( struct V_1 * V_2 )
{
int V_95 ;
V_95 = F_41 ( V_2 -> V_55 , F_42 ( & V_96 , V_2 ) ) ;
if ( V_95 < 0 )
return V_95 ;
V_95 = F_41 ( V_2 -> V_55 , F_42 ( & V_97 , V_2 ) ) ;
if ( V_95 < 0 )
return V_95 ;
return 0 ;
}
static void F_43 ( struct V_5 * V_6 ,
struct V_98 * V_99 )
{
unsigned int V_12 ;
F_44 ( V_99 , L_6 ) ;
for ( V_12 = 1 ; V_12 <= 14 ; ++ V_12 )
F_44 ( V_99 , L_7 , V_6 -> V_11 [ V_12 ] ) ;
F_44 ( V_99 , L_8 ) ;
}
static void F_45 ( struct V_1 * V_2 ,
struct V_98 * V_99 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_12 ;
F_44 ( V_99 , L_9 ) ;
for ( V_12 = 2 ; V_12 < 8 ; ++ V_12 )
F_44 ( V_99 , L_7 , V_6 -> V_9 [ V_12 ] ) ;
F_44 ( V_99 , L_8 ) ;
F_43 ( V_6 , V_99 ) ;
}
int T_2 F_46 ( struct V_1 * V_2 ,
const struct V_100 * V_101 )
{
switch ( V_101 -> V_102 ) {
case 0x834f :
V_2 -> V_103 = V_104 ;
V_2 -> V_103 . V_105 = L_10 ;
break;
case 0x8275 :
case 0x8327 :
V_2 -> V_103 = V_104 ;
V_2 -> V_103 . V_105 = L_11 ;
V_2 -> V_103 . V_106 = F_15 ;
break;
default:
return - V_107 ;
}
return 0 ;
}
