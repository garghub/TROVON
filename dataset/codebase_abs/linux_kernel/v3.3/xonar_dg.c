static void F_1 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_2 ( V_2 , V_8 |
V_9 |
V_10 |
( 0 << V_11 ) |
V_12 ,
V_13 |
V_14 |
( V_3 << 8 ) | V_4 ) ;
V_6 -> V_15 [ V_3 ] = V_4 ;
}
static void F_3 ( struct V_1 * V_2 , unsigned int V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
if ( V_4 != V_6 -> V_15 [ V_3 ] )
F_1 ( V_2 , V_3 , V_4 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_1 ( V_2 , V_16 , V_17 ) ;
F_1 ( V_2 , V_18 ,
V_6 -> V_15 [ V_18 ] ) ;
F_1 ( V_2 , V_19 ,
V_6 -> V_15 [ V_19 ] ) ;
F_1 ( V_2 , V_20 ,
V_6 -> V_15 [ V_20 ] ) ;
F_1 ( V_2 , V_21 ,
V_6 -> V_15 [ V_21 ] ) ;
F_1 ( V_2 , V_22 ,
V_6 -> V_15 [ V_22 ] ) ;
F_1 ( V_2 , V_23 ,
V_6 -> V_15 [ V_23 ] ) ;
F_1 ( V_2 , V_24 ,
V_6 -> V_15 [ V_24 ] ) ;
F_1 ( V_2 , V_25 ,
V_6 -> V_15 [ V_25 ] ) ;
F_1 ( V_2 , V_26 ,
V_27 | V_28 | V_29 ) ;
F_1 ( V_2 , V_30 , 0 ) ;
F_1 ( V_2 , V_16 , 0 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_15 [ V_18 ] =
V_31 | V_32 ;
V_6 -> V_15 [ V_19 ] =
V_33 | V_34 ;
V_6 -> V_15 [ V_20 ] =
V_35 | V_36 ;
V_6 -> V_15 [ V_21 ] = 0 ;
V_6 -> V_15 [ V_22 ] = 0 ;
V_6 -> V_15 [ V_23 ] =
V_37 | V_38 | V_39 ;
V_6 -> V_15 [ V_24 ] = 0 ;
V_6 -> V_15 [ V_25 ] = 0 ;
F_4 ( V_2 ) ;
F_6 ( V_2 -> V_40 , L_1 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_8 ( 2500 ) ;
F_9 ( V_2 , V_41 , V_42 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
V_6 -> V_43 = 0 ;
V_6 -> V_44 = 3 ;
V_6 -> V_45 = 2 * 16 ;
F_5 ( V_2 ) ;
F_11 ( V_2 , V_46 ,
V_47 | V_48 ) ;
F_9 ( V_2 , V_46 ,
V_49 | V_50 | V_42 ) ;
F_11 ( V_2 , V_41 ,
V_49 | V_50 ) ;
F_7 ( V_2 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_11 ( V_2 , V_41 , V_42 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_7 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 ;
V_4 = V_6 -> V_15 [ V_18 ] & ~ V_53 ;
if ( F_16 ( V_52 ) <= 50000 )
V_4 |= V_31 ;
else if ( F_16 ( V_52 ) <= 100000 )
V_4 |= V_54 ;
else
V_4 |= V_55 ;
F_3 ( V_2 , V_18 , V_4 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_4 ;
V_4 = V_6 -> V_15 [ V_19 ] & ~ V_56 ;
if ( F_16 ( V_52 ) <= 50000 )
V_4 |= V_33 ;
else if ( F_16 ( V_52 ) <= 100000 )
V_4 |= V_57 ;
else
V_4 |= V_58 ;
F_3 ( V_2 , V_19 , V_4 ) ;
}
static inline unsigned int F_18 ( unsigned int V_4 ,
unsigned int V_59 ,
unsigned int V_60 ,
unsigned int V_61 )
{
if ( V_59 < V_60 )
return ( V_4 << ( V_60 - V_59 ) ) & V_61 ;
else
return ( V_4 >> ( V_59 - V_60 ) ) & V_61 ;
}
static unsigned int F_19 ( struct V_1 * V_2 ,
unsigned int V_62 )
{
return ( V_62 & V_63 ) |
F_18 ( V_62 ,
V_64 ,
V_65 ,
V_66 ) |
F_18 ( V_62 ,
V_65 ,
V_64 ,
V_67 ) |
F_18 ( V_62 ,
V_68 ,
V_69 ,
V_70 ) ;
}
static int F_20 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
static const char * const V_75 [ 3 ] = {
L_2 , L_3 , L_4
} ;
return F_21 ( V_74 , 1 , 3 , V_75 ) ;
}
static int F_22 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_23 ( & V_2 -> V_78 ) ;
V_4 -> V_4 . V_79 . V_80 [ 0 ] = V_6 -> V_43 ;
F_24 ( & V_2 -> V_78 ) ;
return 0 ;
}
static int F_25 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_3 ;
int V_81 ;
if ( V_4 -> V_4 . V_79 . V_80 [ 0 ] > 2 )
return - V_82 ;
F_23 ( & V_2 -> V_78 ) ;
V_81 = V_4 -> V_4 . V_79 . V_80 [ 0 ] != V_6 -> V_43 ;
if ( V_81 ) {
V_6 -> V_43 = V_4 -> V_4 . V_79 . V_80 [ 0 ] ;
V_3 = V_6 -> V_15 [ V_20 ] &
~ V_83 ;
V_3 |= V_6 -> V_43 == 2 ?
V_84 : V_35 ;
F_3 ( V_2 , V_20 , V_3 ) ;
F_3 ( V_2 , V_24 ,
V_6 -> V_43 ? V_6 -> V_45 : 0 ) ;
F_3 ( V_2 , V_25 ,
V_6 -> V_43 ? V_6 -> V_45 : 0 ) ;
F_26 ( V_2 , V_41 ,
V_6 -> V_43 == 1 ? V_50 : 0 ,
V_50 ) ;
}
F_24 ( & V_2 -> V_78 ) ;
return V_81 ;
}
static int F_27 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
static const char * const V_75 [ 3 ] = {
L_5 , L_6 , L_7
} ;
return F_21 ( V_74 , 1 , 3 , V_75 ) ;
}
static int F_28 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_23 ( & V_2 -> V_78 ) ;
if ( V_6 -> V_45 > 2 * 7 )
V_4 -> V_4 . V_79 . V_80 [ 0 ] = 0 ;
else if ( V_6 -> V_45 > 0 )
V_4 -> V_4 . V_79 . V_80 [ 0 ] = 1 ;
else
V_4 -> V_4 . V_79 . V_80 [ 0 ] = 2 ;
F_24 ( & V_2 -> V_78 ) ;
return 0 ;
}
static int F_29 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
static const T_2 V_85 [ 3 ] = { 2 * 16 , 2 * 7 , 0 } ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_2 V_86 ;
int V_81 ;
if ( V_4 -> V_4 . V_79 . V_80 [ 0 ] > 2 )
return - V_82 ;
V_86 = V_85 [ V_4 -> V_4 . V_79 . V_80 [ 0 ] ] ;
F_23 ( & V_2 -> V_78 ) ;
V_81 = V_86 != V_6 -> V_45 ;
if ( V_81 ) {
V_6 -> V_45 = V_86 ;
if ( V_6 -> V_43 ) {
F_3 ( V_2 , V_24 , V_86 ) ;
F_3 ( V_2 , V_25 , V_86 ) ;
}
}
F_24 ( & V_2 -> V_78 ) ;
return V_81 ;
}
static int F_30 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
V_74 -> type = V_87 ;
V_74 -> V_88 = 2 ;
V_74 -> V_4 . integer . V_89 = 2 * - 12 ;
V_74 -> V_4 . integer . V_90 = 2 * 12 ;
return 0 ;
}
static int F_31 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_91 = V_72 -> V_92 ;
F_23 ( & V_2 -> V_78 ) ;
V_4 -> V_4 . integer . V_4 [ 0 ] = V_6 -> V_93 [ V_91 ] [ 0 ] ;
V_4 -> V_4 . integer . V_4 [ 1 ] = V_6 -> V_93 [ V_91 ] [ 1 ] ;
F_24 ( & V_2 -> V_78 ) ;
return 0 ;
}
static int F_32 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_91 = V_72 -> V_92 ;
int V_81 = 0 ;
if ( V_4 -> V_4 . integer . V_4 [ 0 ] < 2 * - 12 ||
V_4 -> V_4 . integer . V_4 [ 0 ] > 2 * 12 ||
V_4 -> V_4 . integer . V_4 [ 1 ] < 2 * - 12 ||
V_4 -> V_4 . integer . V_4 [ 1 ] > 2 * 12 )
return - V_82 ;
F_23 ( & V_2 -> V_78 ) ;
V_81 = V_6 -> V_93 [ V_91 ] [ 0 ] != V_4 -> V_4 . integer . V_4 [ 0 ] ||
V_6 -> V_93 [ V_91 ] [ 1 ] != V_4 -> V_4 . integer . V_4 [ 1 ] ;
if ( V_81 ) {
V_6 -> V_93 [ V_91 ] [ 0 ] = V_4 -> V_4 . integer . V_4 [ 0 ] ;
V_6 -> V_93 [ V_91 ] [ 1 ] = V_4 -> V_4 . integer . V_4 [ 1 ] ;
if ( V_91 == V_6 -> V_44 ) {
F_3 ( V_2 , V_22 ,
V_6 -> V_93 [ V_91 ] [ 0 ] ) ;
F_3 ( V_2 , V_21 ,
V_6 -> V_93 [ V_91 ] [ 1 ] ) ;
}
}
F_24 ( & V_2 -> V_78 ) ;
return V_81 ;
}
static int F_33 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
static const char * const V_75 [ 4 ] = {
L_8 , L_9 , L_10 , L_11
} ;
return F_21 ( V_74 , 1 , 4 , V_75 ) ;
}
static int F_34 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
F_23 ( & V_2 -> V_78 ) ;
V_4 -> V_4 . V_79 . V_80 [ 0 ] = V_6 -> V_44 ;
F_24 ( & V_2 -> V_78 ) ;
return 0 ;
}
static int F_35 ( struct V_71 * V_72 ,
struct V_76 * V_4 )
{
static const T_1 V_94 [ 4 ] = {
V_95 ,
V_96 ,
V_97 ,
V_39
} ;
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
int V_81 ;
if ( V_4 -> V_4 . V_79 . V_80 [ 0 ] > 3 )
return - V_82 ;
F_23 ( & V_2 -> V_78 ) ;
V_81 = V_4 -> V_4 . V_79 . V_80 [ 0 ] != V_6 -> V_44 ;
if ( V_81 ) {
V_6 -> V_44 = V_4 -> V_4 . V_79 . V_80 [ 0 ] ;
F_1 ( V_2 , V_23 ,
( V_6 -> V_15 [ V_23 ] &
~ V_98 ) |
V_94 [ V_6 -> V_44 ] ) ;
F_3 ( V_2 , V_22 ,
V_6 -> V_93 [ V_6 -> V_44 ] [ 0 ] ) ;
F_3 ( V_2 , V_21 ,
V_6 -> V_93 [ V_6 -> V_44 ] [ 1 ] ) ;
F_26 ( V_2 , V_41 ,
V_6 -> V_44 ? 0 : V_49 ,
V_49 ) ;
}
F_24 ( & V_2 -> V_78 ) ;
return V_81 ;
}
static int F_36 ( struct V_71 * V_72 , struct V_73 * V_74 )
{
static const char * const V_75 [ 2 ] = { L_12 , L_13 } ;
return F_21 ( V_74 , 1 , 2 , V_75 ) ;
}
static int F_37 ( struct V_71 * V_72 , struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
V_4 -> V_4 . V_79 . V_80 [ 0 ] =
! ! ( V_6 -> V_15 [ V_19 ] & V_99 ) ;
return 0 ;
}
static int F_38 ( struct V_71 * V_72 , struct V_76 * V_4 )
{
struct V_1 * V_2 = V_72 -> V_77 ;
struct V_5 * V_6 = V_2 -> V_7 ;
T_1 V_3 ;
int V_81 ;
F_23 ( & V_2 -> V_78 ) ;
V_3 = V_6 -> V_15 [ V_19 ] & ~ V_99 ;
if ( V_4 -> V_4 . V_79 . V_80 [ 0 ] )
V_3 |= V_99 ;
V_81 = V_3 != V_6 -> V_15 [ V_19 ] ;
if ( V_81 )
F_1 ( V_2 , V_19 , V_3 ) ;
F_24 ( & V_2 -> V_78 ) ;
return V_81 ;
}
static int F_39 ( struct V_100 * V_101 )
{
if ( ! strncmp ( V_101 -> V_102 , L_14 , 16 ) )
return 1 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_2 )
{
unsigned int V_103 ;
int V_104 ;
for ( V_103 = 0 ; V_103 < F_41 ( V_105 ) ; ++ V_103 ) {
V_104 = F_42 ( V_2 -> V_40 ,
F_43 ( & V_105 [ V_103 ] , V_2 ) ) ;
if ( V_104 < 0 )
return V_104 ;
}
return 0 ;
}
static void F_44 ( struct V_1 * V_2 ,
struct V_106 * V_107 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
unsigned int V_103 ;
F_45 ( V_107 , L_15 ) ;
for ( V_103 = 1 ; V_103 <= 0x10 ; ++ V_103 )
F_45 ( V_107 , L_16 , V_6 -> V_15 [ V_103 ] ) ;
F_45 ( V_107 , L_17 ) ;
}
