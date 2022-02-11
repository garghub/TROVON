static void F_1 ( struct V_1 * V_2 , int V_3 , unsigned int V_4 )
{
if ( F_2 ( ! V_2 -> V_5 -> V_6 ) )
return;
if ( V_2 -> V_7 & V_8 )
return;
F_3 ( & V_2 -> V_9 ) ;
V_2 -> V_5 -> V_6 ( V_2 , V_3 , V_4 ) ;
F_4 ( & V_2 -> V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 , int V_10 , int V_11 )
{
union V_12 V_4 ;
F_6 ( V_4 ) ;
F_7 ( V_4 , V_10 ) ;
F_8 ( V_4 , V_11 ) ;
F_1 ( V_2 , V_3 , V_4 . V_13 ) ;
}
static void F_9 ( struct V_1 * V_2 , int V_3 , int V_14 , int V_15 )
{
V_14 = V_2 -> V_16 -> V_17 - V_14 ;
V_15 = V_2 -> V_16 -> V_17 - V_15 ;
if ( V_2 -> V_5 -> V_18 ) {
V_2 -> V_5 -> V_18 ( V_2 , V_19 , V_14 ) ;
V_2 -> V_5 -> V_18 ( V_2 , V_20 , V_15 ) ;
} else {
F_5 ( V_2 , V_3 , V_19 , V_14 ) ;
F_5 ( V_2 , V_3 , V_20 , V_15 ) ;
}
}
void F_10 ( struct V_1 * V_2 , int V_21 )
{
unsigned int V_22 ;
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_23 ; V_22 ++ ) {
if ( V_2 -> V_5 -> V_18 )
V_2 -> V_5 -> V_18 ( V_2 , V_24 , V_21 ) ;
else
F_5 ( V_2 , V_22 , V_24 ,
V_21 ? V_25 : V_26 ) ;
}
}
void F_11 ( struct V_1 * V_2 , int V_27 )
{
unsigned int V_22 ;
int V_28 = V_2 -> type >= V_29 ? 0x75 : 0x65 ;
V_2 -> V_5 -> V_30 ( V_2 ) ;
if ( ! V_2 -> V_5 -> V_18 ) {
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_23 ; V_22 ++ ) {
F_5 ( V_2 , V_22 , V_24 , V_25 ) ;
F_5 ( V_2 , V_22 , V_31 , 0x00 ) ;
F_5 ( V_2 , V_22 , V_32 , V_28 ) ;
F_5 ( V_2 , V_22 , V_33 , 0x00 ) ;
}
}
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_23 ; V_22 ++ ) {
V_2 -> V_34 [ V_22 ] [ 0 ] = 0 ;
V_2 -> V_34 [ V_22 ] [ 1 ] = 0 ;
F_9 ( V_2 , V_22 , 0 , 0 ) ;
}
}
static void F_12 ( struct V_1 * V_2 , int V_35 )
{
if ( V_2 -> V_7 & V_8 )
return;
F_3 ( & V_2 -> V_9 ) ;
V_2 -> V_5 -> V_36 ( V_2 , V_35 ) ;
F_4 ( & V_2 -> V_9 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_37 == V_2 -> V_38 ||
V_2 -> V_39 )
return 0 ;
F_12 ( V_2 , V_2 -> V_37 ) ;
V_2 -> V_38 = V_2 -> V_37 ;
return 1 ;
}
static int F_14 ( struct V_1 * V_2 , int V_40 , int V_41 ,
struct V_42 * V_43 )
{
struct V_44 V_45 ;
if ( V_2 -> V_7 & V_8 )
return - V_46 ;
F_15 ( & V_45 , V_47 ) ;
if ( V_41 )
V_45 . V_48 [ 0 ] |= V_49 ;
V_45 . V_48 [ 1 ] = 1 << V_40 ;
V_45 . V_48 [ 2 ] = 0 ;
if ( V_43 -> V_50 ) {
V_45 . V_48 [ 0 ] |= V_51 ;
V_45 . V_48 [ 2 ] |= V_43 -> V_52 ;
}
if ( V_43 -> V_53 ) {
V_45 . V_48 [ 0 ] |= V_54 ;
V_45 . V_48 [ 2 ] |= ( ( unsigned int ) V_43 -> V_55 << 10 ) ;
}
if ( V_43 -> V_56 ) {
V_45 . V_48 [ 0 ] |= V_57 ;
if ( V_43 -> V_21 )
V_45 . V_48 [ 2 ] |= V_58 ;
}
if ( V_43 -> V_59 ) {
V_45 . V_48 [ 0 ] |= V_60 | V_61 ;
if ( V_43 -> V_62 )
V_45 . V_48 [ 2 ] |= V_63 ;
}
return F_16 ( V_2 , & V_45 ) ;
}
int F_17 ( struct V_1 * V_2 , int V_40 , int V_52 , int V_64 )
{
struct V_42 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_53 = 1 ;
V_43 . V_55 = V_52 ;
V_43 . V_59 = 1 ;
V_43 . V_62 = ! V_64 ;
V_2 -> V_65 [ V_40 ] = V_52 ;
V_2 -> V_66 [ V_40 ] = V_64 ;
return F_14 ( V_2 , V_40 , 0 , & V_43 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_40 , int V_64 )
{
struct V_42 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_56 = 1 ;
V_43 . V_21 = ! V_64 ;
V_2 -> V_67 [ V_40 ] = V_64 ;
return F_14 ( V_2 , V_40 , 0 , & V_43 ) ;
}
static int F_19 ( struct V_1 * V_2 , int V_40 , int V_41 , int V_52 )
{
struct V_42 V_43 ;
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
V_43 . V_50 = 1 ;
V_43 . V_52 = V_52 ;
V_2 -> V_68 [ V_41 ] [ V_40 ] = V_52 ;
return F_14 ( V_2 , V_40 , V_41 , & V_43 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned int V_22 , V_69 ;
struct V_42 V_43 ;
memset ( V_2 -> V_68 , 0 , sizeof( V_2 -> V_68 ) ) ;
memset ( V_2 -> V_67 , 0 , sizeof( V_2 -> V_67 ) ) ;
memset ( V_2 -> V_65 , 0 , sizeof( V_2 -> V_65 ) ) ;
memset ( V_2 -> V_66 , 0 , sizeof( V_2 -> V_66 ) ) ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_70 * 2 ; V_22 ++ ) {
memset ( & V_43 , 0 , sizeof( V_43 ) ) ;
if ( V_69 == 0 ) {
V_43 . V_53 = 1 ;
V_43 . V_56 = 1 ;
V_43 . V_59 = 1 ;
}
V_43 . V_50 = 1 ;
V_43 . V_52 = V_71 ;
F_14 ( V_2 , V_22 , V_69 , & V_43 ) ;
V_2 -> V_68 [ V_69 ] [ V_22 ] = V_71 ;
V_2 -> V_65 [ V_22 ] = V_71 ;
}
}
}
static int F_21 ( struct V_1 * V_2 , int V_40 , int V_41 , struct V_72 * V_43 )
{
struct V_44 V_45 ;
int V_22 , V_73 ;
if ( V_2 -> V_7 & V_8 )
return - V_46 ;
F_15 ( & V_45 , V_74 ) ;
V_45 . V_75 += 2 * V_76 ;
if ( V_41 )
V_45 . V_48 [ 0 ] |= V_49 ;
V_45 . V_48 [ 1 ] = 0 ;
for ( V_22 = 0 ; V_22 < V_76 ; V_22 ++ )
V_45 . V_48 [ 1 ] |= 1 << ( V_40 + V_22 ) ;
V_73 = F_16 ( V_2 , & V_45 ) ;
if ( V_73 < 0 )
return V_73 ;
for ( V_22 = 0 ; V_22 < 2 * V_76 ; V_22 += 2 ) {
V_43 -> V_77 = ( V_45 . V_78 [ 0 ] & ( 1 << ( V_40 + V_22 ) ) ) ? 1 : 0 ;
V_43 -> V_79 = V_45 . V_78 [ V_22 + 1 ] ;
V_43 -> V_80 = V_45 . V_78 [ V_22 + 2 ] ;
V_43 ++ ;
}
return 0 ;
}
static int F_22 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
V_84 -> type = V_85 ;
V_84 -> V_86 = 2 ;
V_84 -> V_87 . integer . V_88 = 0 ;
V_84 -> V_87 . integer . V_89 = V_2 -> V_16 -> V_17 ;
return 0 ;
}
static int F_24 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_3 = V_82 -> V_92 . V_93 ;
F_3 ( & V_2 -> V_94 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_2 -> V_34 [ V_3 ] [ 0 ] ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_2 -> V_34 [ V_3 ] [ 1 ] ;
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_25 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_3 = V_82 -> V_92 . V_93 ;
unsigned int V_11 [ 2 ] , V_95 ;
V_95 = V_2 -> V_16 -> V_17 ;
V_11 [ 0 ] = V_91 -> V_87 . integer . V_87 [ 0 ] ;
V_11 [ 1 ] = V_91 -> V_87 . integer . V_87 [ 1 ] ;
if ( V_11 [ 0 ] > V_95 || V_11 [ 1 ] > V_95 )
return - V_96 ;
F_3 ( & V_2 -> V_94 ) ;
if ( V_11 [ 0 ] != V_2 -> V_34 [ V_3 ] [ 0 ] ||
V_11 [ 1 ] != V_2 -> V_34 [ V_3 ] [ 1 ] ) {
F_9 ( V_2 , V_3 , V_11 [ 0 ] , V_11 [ 1 ] ) ;
V_2 -> V_34 [ V_3 ] [ 0 ] = V_11 [ 0 ] ;
V_2 -> V_34 [ V_3 ] [ 1 ] = V_11 [ 1 ] ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_26 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
static const char * const V_97 [ 3 ] = {
L_1 , L_2 , L_3
} ;
static const char * const V_98 [ 2 ] = {
L_1 , L_4
} ;
struct V_1 * V_2 = F_23 ( V_82 ) ;
if ( V_2 -> type >= V_29 )
return F_27 ( V_84 , 1 , 3 , V_97 ) ;
else
return F_27 ( V_84 , 1 , 2 , V_98 ) ;
}
static int F_28 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
V_91 -> V_87 . V_99 . V_100 [ 0 ] = V_2 -> V_37 ;
return 0 ;
}
static int F_29 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
if ( V_2 -> type >= V_29 ) {
if ( V_91 -> V_87 . V_99 . V_100 [ 0 ] > 2 )
return - V_96 ;
} else {
if ( V_91 -> V_87 . V_99 . V_100 [ 0 ] > 1 )
return - V_96 ;
}
F_3 ( & V_2 -> V_94 ) ;
if ( V_2 -> V_37 != V_91 -> V_87 . V_99 . V_100 [ 0 ] ) {
V_2 -> V_37 = V_91 -> V_87 . V_99 . V_100 [ 0 ] ;
F_13 ( V_2 ) ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_30 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
static const char * const V_101 [ 3 ] = {
L_5 , L_6 , L_7
} ;
return F_27 ( V_84 , 1 , 3 , V_101 ) ;
}
static int F_31 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
V_91 -> V_87 . V_99 . V_100 [ 0 ] = V_2 -> V_102 ;
return 0 ;
}
static int F_32 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
if ( V_91 -> V_87 . V_99 . V_100 [ 0 ] > 2 )
return - V_96 ;
F_3 ( & V_2 -> V_94 ) ;
if ( V_2 -> V_102 != V_91 -> V_87 . V_99 . V_100 [ 0 ] ) {
V_2 -> V_102 = V_91 -> V_87 . V_99 . V_100 [ 0 ] ;
F_33 ( V_2 , V_2 -> V_103 ) ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_34 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
V_84 -> type = V_85 ;
V_84 -> V_86 = 2 ;
V_84 -> V_87 . integer . V_88 = 0 ;
V_84 -> V_87 . integer . V_89 = V_104 ;
return 0 ;
}
static int F_35 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
int V_41 = ( V_82 -> V_105 >> 8 ) & 1 ;
F_3 ( & V_2 -> V_94 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_2 -> V_68 [ V_41 ] [ V_40 ] ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_2 -> V_68 [ V_41 ] [ V_40 + 1 ] ;
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_36 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
int V_41 = ( V_82 -> V_105 >> 8 ) & 1 ;
unsigned int V_11 [ 2 ] ;
V_11 [ 0 ] = V_91 -> V_87 . integer . V_87 [ 0 ] ;
V_11 [ 1 ] = V_91 -> V_87 . integer . V_87 [ 1 ] ;
if ( V_11 [ 0 ] > V_104 || V_11 [ 1 ] > V_104 )
return - V_96 ;
F_3 ( & V_2 -> V_94 ) ;
if ( V_11 [ 0 ] != V_2 -> V_68 [ V_41 ] [ V_40 ] ||
V_11 [ 1 ] != V_2 -> V_68 [ V_41 ] [ V_40 + 1 ] ) {
F_19 ( V_2 , V_40 , V_41 , V_11 [ 0 ] ) ;
F_19 ( V_2 , V_40 + 1 , V_41 , V_11 [ 1 ] ) ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_37 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
F_3 ( & V_2 -> V_94 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_2 -> V_65 [ V_40 ] ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_2 -> V_65 [ V_40 + 1 ] ;
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_38 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
unsigned int V_11 [ 2 ] ;
V_11 [ 0 ] = V_91 -> V_87 . integer . V_87 [ 0 ] ;
V_11 [ 1 ] = V_91 -> V_87 . integer . V_87 [ 1 ] ;
if ( V_11 [ 0 ] > V_104 || V_11 [ 1 ] > V_104 )
return - V_96 ;
F_3 ( & V_2 -> V_94 ) ;
if ( V_11 [ 0 ] != V_2 -> V_65 [ V_40 ] ||
V_11 [ 1 ] != V_2 -> V_65 [ V_40 + 1 ] ) {
F_17 ( V_2 , V_40 , V_11 [ 0 ] ,
V_2 -> V_66 [ V_40 ] ) ;
F_17 ( V_2 , V_40 + 1 , V_11 [ 1 ] ,
V_2 -> V_66 [ V_40 + 1 ] ) ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_39 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
F_3 ( & V_2 -> V_94 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_2 -> V_67 [ V_40 ] ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_2 -> V_67 [ V_40 + 1 ] ;
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_40 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
F_3 ( & V_2 -> V_94 ) ;
if ( V_91 -> V_87 . integer . V_87 [ 0 ] != V_2 -> V_67 [ V_40 ] ||
V_91 -> V_87 . integer . V_87 [ 1 ] != V_2 -> V_67 [ V_40 + 1 ] ) {
F_18 ( V_2 , V_40 ,
! ! V_91 -> V_87 . integer . V_87 [ 0 ] ) ;
F_18 ( V_2 , V_40 + 1 ,
! ! V_91 -> V_87 . integer . V_87 [ 1 ] ) ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_41 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
F_3 ( & V_2 -> V_94 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_2 -> V_66 [ V_40 ] ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_2 -> V_66 [ V_40 + 1 ] ;
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_42 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
int V_40 = V_82 -> V_105 & 0xff ;
F_3 ( & V_2 -> V_94 ) ;
if ( V_91 -> V_87 . integer . V_87 [ 0 ] != V_2 -> V_66 [ V_40 ] ||
V_91 -> V_87 . integer . V_87 [ 1 ] != V_2 -> V_66 [ V_40 + 1 ] ) {
F_17 ( V_2 , V_40 , V_2 -> V_65 [ V_40 ] ,
! ! V_91 -> V_87 . integer . V_87 [ 0 ] ) ;
F_17 ( V_2 , V_40 + 1 , V_2 -> V_65 [ V_40 + 1 ] ,
! ! V_91 -> V_87 . integer . V_87 [ 1 ] ) ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_43 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
V_84 -> type = V_106 ;
V_84 -> V_86 = 1 ;
return 0 ;
}
static int F_44 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
F_3 ( & V_2 -> V_94 ) ;
V_91 -> V_87 . V_107 . V_108 [ 0 ] = ( V_2 -> V_109 >> 0 ) & 0xff ;
V_91 -> V_87 . V_107 . V_108 [ 1 ] = ( V_2 -> V_109 >> 8 ) & 0xff ;
V_91 -> V_87 . V_107 . V_108 [ 2 ] = ( V_2 -> V_109 >> 16 ) & 0xff ;
V_91 -> V_87 . V_107 . V_108 [ 3 ] = ( V_2 -> V_109 >> 24 ) & 0xff ;
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_45 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
V_91 -> V_87 . V_107 . V_108 [ 0 ] = 0xff ;
V_91 -> V_87 . V_107 . V_108 [ 1 ] = 0xff ;
V_91 -> V_87 . V_107 . V_108 [ 2 ] = 0xff ;
V_91 -> V_87 . V_107 . V_108 [ 3 ] = 0xff ;
return 0 ;
}
static int F_46 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
unsigned int V_11 ;
V_11 = ( V_91 -> V_87 . V_107 . V_108 [ 0 ] << 0 ) |
( V_91 -> V_87 . V_107 . V_108 [ 1 ] << 8 ) |
( V_91 -> V_87 . V_107 . V_108 [ 2 ] << 16 ) |
( V_91 -> V_87 . V_107 . V_108 [ 3 ] << 24 ) ;
F_3 ( & V_2 -> V_94 ) ;
if ( V_2 -> V_109 != V_11 ) {
V_2 -> V_109 = V_11 ;
F_47 ( V_2 , V_11 ) ;
F_4 ( & V_2 -> V_94 ) ;
return 1 ;
}
F_4 ( & V_2 -> V_94 ) ;
return 0 ;
}
static int F_48 ( struct V_81 * V_82 , struct V_83 * V_84 )
{
V_84 -> type = V_85 ;
V_84 -> V_86 = 2 ;
V_84 -> V_87 . integer . V_88 = 0 ;
V_84 -> V_87 . integer . V_89 = V_110 ;
return 0 ;
}
static int F_49 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
struct V_72 V_111 [ 2 ] ;
int V_40 = V_82 -> V_105 & 0xff ;
int V_41 = ( V_82 -> V_105 >> 8 ) & 1 ;
F_21 ( V_2 , V_40 , V_41 , V_111 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_111 [ 0 ] . V_79 >> V_112 ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_111 [ 1 ] . V_79 >> V_112 ;
return 0 ;
}
static int F_50 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
struct V_72 V_111 [ 2 ] ;
int V_40 = V_82 -> V_105 & 0xff ;
int V_41 = ( V_82 -> V_105 >> 8 ) & 1 ;
F_21 ( V_2 , V_40 , V_41 , V_111 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_111 [ 0 ] . V_80 >> V_112 ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_111 [ 1 ] . V_80 >> V_112 ;
return 0 ;
}
static int F_51 ( struct V_81 * V_82 , struct V_90 * V_91 )
{
struct V_1 * V_2 = F_23 ( V_82 ) ;
struct V_72 V_111 [ 2 ] ;
int V_40 = V_82 -> V_105 & 0xff ;
F_21 ( V_2 , V_40 , 1 , V_111 ) ;
V_91 -> V_87 . integer . V_87 [ 0 ] = V_111 [ 0 ] . V_77 ;
V_91 -> V_87 . integer . V_87 [ 1 ] = V_111 [ 1 ] . V_77 ;
return 0 ;
}
int F_52 ( struct V_1 * V_2 )
{
unsigned int V_22 , V_69 ;
int V_73 ;
struct V_113 V_114 ;
struct V_115 * V_116 = V_2 -> V_116 ;
char V_117 [ 32 ] ;
strcpy ( V_116 -> V_118 , V_116 -> V_119 ) ;
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_120 ; V_22 ++ ) {
V_114 = V_121 ;
V_114 . V_93 = V_22 ;
V_114 . V_122 . V_123 = V_2 -> V_16 -> V_124 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_120 ; V_22 ++ ) {
int V_11 = V_22 * 2 ;
V_114 = V_125 ;
V_114 . V_93 = V_22 ;
V_114 . V_117 = L_8 ;
V_114 . V_105 = V_11 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
V_114 = V_126 ;
V_114 . V_93 = V_22 ;
V_114 . V_105 = V_11 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
V_114 = V_127 ;
V_114 . V_93 = V_22 ;
V_114 . V_105 = V_11 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
V_114 = V_128 ;
V_114 . V_93 = V_22 ;
V_114 . V_105 = V_11 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
}
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_120 ; V_22 ++ ) {
V_114 = V_125 ;
V_114 . V_93 = V_22 ;
V_114 . V_117 = L_9 ;
V_114 . V_105 = ( V_22 * 2 ) | ( 1 << 8 ) ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
}
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_129 , V_2 ) ) ) < 0 )
return V_73 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_130 , V_2 ) ) ) < 0 )
return V_73 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_131 , V_2 ) ) ) < 0 )
return V_73 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_132 , V_2 ) ) ) < 0 )
return V_73 ;
for ( V_69 = 0 ; V_69 < 2 ; V_69 ++ ) {
static char * V_133 [ 2 ] = { L_10 , L_11 } ;
for ( V_22 = 0 ; V_22 < V_2 -> V_16 -> V_70 ; V_22 ++ ) {
int V_11 = ( V_22 * 2 ) | ( V_69 << 8 ) ;
if ( V_69 == 1 ) {
V_114 = V_134 ;
V_114 . V_93 = V_22 ;
V_114 . V_105 = V_11 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
}
sprintf ( V_117 , L_12 , V_133 [ V_69 ] ) ;
V_114 = V_135 ;
V_114 . V_93 = V_22 ;
V_114 . V_117 = V_117 ;
V_114 . V_105 = V_11 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
sprintf ( V_117 , L_13 , V_133 [ V_69 ] ) ;
V_114 = V_136 ;
V_114 . V_93 = V_22 ;
V_114 . V_117 = V_117 ;
V_114 . V_105 = V_11 ;
if ( ( V_73 = F_53 ( V_116 , F_54 ( & V_114 , V_2 ) ) ) < 0 )
return V_73 ;
}
}
F_20 ( V_2 ) ;
return 0 ;
}
