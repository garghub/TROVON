static inline int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_2 , V_5 -> V_6 , 0 ,
V_7 , V_3 ) ;
return F_3 ( V_2 , V_5 -> V_6 , 0 ,
V_8 , 0 ) ;
}
static inline void F_4 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_9 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
F_2 ( V_2 , V_5 -> V_6 , 0 ,
V_7 , V_3 ) ;
F_2 ( V_2 , V_5 -> V_6 , 0 ,
V_10 , V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_11 . V_12 = ! ! ( V_5 -> V_13 && V_5 -> V_14 ) ;
F_6 ( V_2 ) ;
if ( V_5 -> V_15 || V_5 -> V_16 ) {
if ( V_5 -> V_11 . V_17 )
V_5 -> V_18 = V_5 -> V_11 . V_19 ?
V_5 -> V_15 : V_5 -> V_16 ;
else
V_5 -> V_18 =
V_5 -> V_15 | V_5 -> V_16 ;
F_2 ( V_2 , 0x01 , 0 ,
V_20 , V_5 -> V_18 ) ;
}
}
static bool F_7 ( struct V_1 * V_2 , T_1 V_21 )
{
unsigned int V_22 ;
V_22 = F_8 ( V_2 , V_21 ) ;
return ( F_9 ( V_22 ) != V_23 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
if ( V_5 -> V_6 == V_24 ) {
V_9 = F_1 ( V_2 , V_25 ) ;
if ( F_7 ( V_2 , V_26 ) )
V_9 |= 1 << 4 ;
if ( F_7 ( V_2 , V_27 ) )
V_9 |= 1 << 3 ;
F_4 ( V_2 , V_25 , V_9 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
V_9 = 0x0002 ;
V_9 |= 0x0008 ;
if ( F_7 ( V_2 , V_28 ) )
V_9 |= 0x4000 ;
F_4 ( V_2 , V_29 , V_9 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_24 ) {
F_13 ( V_2 , V_30 ) ;
F_13 ( V_2 , V_31 ) ;
} else if ( V_5 -> V_6 == V_32 ) {
F_13 ( V_2 , V_33 ) ;
}
F_14 ( V_2 ) ;
if ( V_5 -> V_34 ) {
F_2 ( V_2 , 0x01 , 0 , V_35 ,
V_5 -> V_34 ) ;
F_2 ( V_2 , 0x01 , 0 , V_36 ,
V_5 -> V_37 ) ;
F_2 ( V_2 , 0x01 , 0 , V_20 ,
V_5 -> V_18 ) ;
}
if ( V_5 -> V_6 == V_24 ) {
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_38 ;
V_38 = F_16 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
F_17 ( V_2 , V_39 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 ;
int V_40 ;
V_38 = F_19 ( V_2 , & V_5 -> V_11 . V_41 , NULL , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_20 ( V_2 , & V_5 -> V_11 . V_41 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_5 -> V_11 . V_42 ) {
unsigned int V_43 = 0 ;
for ( V_40 = 0 ; V_40 < V_5 -> V_11 . V_44 . V_45 ; V_40 ++ ) {
int V_3 = V_5 -> V_11 . V_46 [ V_40 ] ;
if ( V_43 & ( 1 << V_3 ) )
continue;
F_21 ( V_2 ,
V_5 -> V_11 . V_47 [ V_3 ] ) ;
V_43 |= 1 << V_3 ;
}
}
return 0 ;
}
static void F_22 ( struct V_1 * V_2 ,
const struct V_48 * V_49 , int V_50 )
{
if ( V_50 == V_51 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 2 ;
V_5 -> V_16 = 8 ;
V_5 -> V_34 = V_5 -> V_37 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static void F_23 ( struct V_1 * V_2 ,
const struct V_48 * V_49 , int V_50 )
{
if ( V_50 == V_51 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 4 ;
V_5 -> V_16 = 8 ;
V_5 -> V_34 = V_5 -> V_37 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static struct V_4 * F_24 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 ;
V_5 = F_25 ( sizeof( * V_5 ) , V_52 ) ;
if ( ! V_5 )
return NULL ;
V_2 -> V_5 = V_5 ;
V_5 -> V_6 = V_6 ;
V_2 -> V_53 = 1 ;
F_26 ( & V_5 -> V_11 ) ;
return V_5 ;
}
static int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 ;
V_5 = F_24 ( V_2 , V_24 ) ;
if ( ! V_5 )
return - V_54 ;
V_2 -> V_55 = V_56 ;
V_5 -> V_11 . V_57 = F_5 ;
V_2 -> V_58 = 1 ;
F_28 ( V_2 , V_59 , V_60 ,
V_61 ) ;
F_17 ( V_2 , V_51 ) ;
V_38 = F_18 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
F_17 ( V_2 , V_62 ) ;
return 0 ;
error:
F_29 ( V_2 ) ;
return V_38 ;
}
static void F_30 ( struct V_1 * V_2 ,
const struct V_48 * V_49 , int V_50 )
{
if ( V_50 == V_51 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 0 ;
V_5 -> V_16 = 1 ;
V_5 -> V_34 = V_5 -> V_37 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static void F_31 ( struct V_1 * V_2 ,
const struct V_48 * V_49 , int V_50 )
{
if ( V_50 != V_51 )
return;
V_2 -> V_63 = V_64 ;
F_28 ( V_2 , NULL , V_65 , V_66 ) ;
if ( V_2 -> V_63 == V_64 )
V_2 -> V_63 = V_67 ;
F_17 ( V_2 , V_50 ) ;
}
static void F_32 ( struct V_1 * V_2 ,
const struct V_48 * V_49 , int V_50 )
{
static const struct V_68 V_69 [] = {
{ 0x18 , 0x00ab9150 } ,
{ 0x21 , 0x004be140 } ,
{ }
} ;
if ( V_50 == V_51 ) {
V_2 -> V_70 = 1 ;
F_33 ( V_2 , V_69 ) ;
}
}
static int F_34 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_35 ( V_72 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_75 = V_5 -> V_11 . V_41 . V_76 [ 0 ] ;
int V_77 = V_74 -> V_78 . integer . V_78 [ 0 ] ? V_79 : 0 ;
F_36 ( V_2 , V_75 , V_77 ) ;
return V_5 -> V_80 ( V_72 , V_74 ) ;
}
static void F_37 ( struct V_1 * V_2 ,
const struct V_48 * V_49 , int V_50 )
{
if ( V_50 == V_39 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_71 * V_81 ;
if ( ! V_5 -> V_11 . V_41 . V_76 [ 0 ] )
return;
V_81 = F_38 ( V_2 , L_1 ) ;
if ( ! V_81 )
return;
V_5 -> V_80 = V_81 -> V_82 ;
V_81 -> V_82 = F_34 ;
}
}
static void F_39 ( struct V_1 * V_2 , T_1 V_83 )
{
unsigned int V_84 ;
V_84 = F_40 ( V_2 , V_83 , V_85 ) ;
V_84 &= ~ ( V_86 ) ;
V_84 |= 0x02 ;
F_41 ( V_2 , V_83 , V_85 , V_84 ) ;
}
static int F_42 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 ;
V_5 = F_24 ( V_2 , V_32 ) ;
if ( ! V_5 )
return - V_54 ;
V_2 -> V_55 = V_56 ;
V_5 -> V_11 . V_57 = F_5 ;
V_5 -> V_11 . V_87 = 1ULL << 0x10 ;
F_28 ( V_2 , V_88 , V_89 ,
V_66 ) ;
F_17 ( V_2 , V_51 ) ;
F_43 ( V_2 , 0x18 ,
F_44 ( V_2 , 0x18 ) | V_90 ) ;
F_39 ( V_2 , 0x18 ) ;
F_39 ( V_2 , 0x1b ) ;
F_39 ( V_2 , 0x1c ) ;
V_38 = F_18 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
F_17 ( V_2 , V_62 ) ;
return 0 ;
error:
F_29 ( V_2 ) ;
return V_38 ;
}
static void F_45 ( struct V_1 * V_2 ,
const struct V_48 * V_49 , int V_50 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_50 == V_51 )
V_5 -> V_14 = 1 ;
}
static int F_46 ( struct V_71 * V_72 ,
struct V_91 * V_92 )
{
V_92 -> type = V_93 ;
V_92 -> V_94 = 1 ;
V_92 -> V_78 . integer . V_95 = 0 ;
V_92 -> V_78 . integer . V_96 = 3 ;
return 0 ;
}
static int F_47 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_35 ( V_72 ) ;
V_74 -> V_78 . integer . V_78 [ 0 ] =
F_1 ( V_2 , V_97 ) & 0x0003 ;
return 0 ;
}
static int F_48 ( struct V_71 * V_72 ,
struct V_73 * V_74 )
{
struct V_1 * V_2 = F_35 ( V_72 ) ;
unsigned int V_98 = V_74 -> V_78 . integer . V_78 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_97 ) ;
unsigned int V_99 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_98 & 0x0003 ) ;
if ( V_99 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_97 , V_9 ) ;
return 1 ;
}
}
static void F_49 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_100 , V_9 ;
V_9 = F_1 ( V_2 , V_101 ) ;
if ( V_5 -> V_34 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_14 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_101 , V_9 ) ;
if ( ( V_5 -> V_34 || V_5 -> V_14 ) &&
F_7 ( V_2 , V_102 ) ) {
V_100 = F_8 ( V_2 , V_102 ) ;
V_100 &= ~ V_103 ;
V_100 |= ( V_23 << V_104 ) ;
F_50 ( V_2 , V_102 , V_100 ) ;
}
}
static void F_51 ( struct V_1 * V_2 ,
struct V_105 * V_106 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
bool V_13 = false ;
T_1 V_107 = V_5 -> V_11 . V_41 . V_76 [ 0 ] ;
if ( ! V_5 -> V_108 ||
V_5 -> V_6 != V_109 )
return;
V_13 = F_52 ( V_2 , V_107 ) ;
if ( V_13 == V_5 -> V_13 )
return;
V_5 -> V_13 = V_13 ;
F_53 ( V_2 , V_107 , V_13 ? V_79 : 0 ) ;
F_5 ( V_2 ) ;
}
static void F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_110 * V_111 = & V_5 -> V_11 . V_41 ;
int V_40 ;
for ( V_40 = 0 ; V_40 < V_111 -> V_112 ; V_40 ++ ) {
T_1 V_21 = V_111 -> V_76 [ V_40 ] ;
if ( F_44 ( V_2 , V_21 ) & V_113 ) {
V_5 -> V_108 = 1 ;
F_55 ( V_2 , V_21 ,
F_51 ) ;
}
}
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_109 ) {
F_13 ( V_2 , V_114 ) ;
F_13 ( V_2 , V_115 ) ;
F_49 ( V_2 ) ;
}
F_14 ( V_2 ) ;
if ( V_5 -> V_34 ) {
F_2 ( V_2 , 0x01 , 0 , V_35 ,
V_5 -> V_34 ) ;
F_2 ( V_2 , 0x01 , 0 , V_36 ,
V_5 -> V_37 ) ;
F_2 ( V_2 , 0x01 , 0 , V_20 ,
V_5 -> V_18 ) ;
}
F_10 ( V_2 ) ;
F_51 ( V_2 , NULL ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_38 ;
V_38 = F_16 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
if ( V_5 -> V_11 . V_41 . V_116 &&
V_5 -> V_6 == V_109 ) {
V_38 = F_58 ( V_2 , 0 ,
F_59 ( & V_117 , V_2 ) ) ;
if ( V_38 < 0 )
return V_38 ;
}
return 0 ;
}
static void F_60 ( struct V_1 * V_2 , T_1 V_118 )
{
unsigned int V_84 ;
V_84 = F_40 ( V_2 , V_118 , V_119 ) ;
V_84 &= ~ ( 0x7f << V_120 ) ;
V_84 |= ( ( V_84 >> V_121 ) & 0x7f )
<< V_120 ;
F_41 ( V_2 , V_118 , V_119 , V_84 ) ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_118 = V_122 ;
int V_38 ;
F_60 ( V_2 , V_118 ) ;
V_38 = F_19 ( V_2 , & V_5 -> V_11 . V_41 , NULL , 0 ) ;
if ( V_38 < 0 )
return V_38 ;
V_38 = F_20 ( V_2 , & V_5 -> V_11 . V_41 ) ;
if ( V_38 < 0 )
return V_38 ;
F_54 ( V_2 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
F_63 ( V_2 ) ;
F_2 ( V_2 , V_122 , 0 ,
V_123 , V_124 ) ;
F_2 ( V_2 , V_125 , 0 ,
V_123 , V_124 ) ;
if ( V_5 -> V_6 == V_109 ) {
V_9 = F_1 ( V_2 , V_101 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_101 , V_9 ) ;
}
return 0 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 ;
V_5 = F_24 ( V_2 , V_109 ) ;
if ( ! V_5 )
return - V_54 ;
V_2 -> V_55 = V_126 ;
V_5 -> V_11 . V_57 = F_5 ;
F_28 ( V_2 , V_127 , V_128 ,
V_129 ) ;
F_17 ( V_2 , V_51 ) ;
F_49 ( V_2 ) ;
V_38 = F_61 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
F_17 ( V_2 , V_62 ) ;
return 0 ;
error:
F_29 ( V_2 ) ;
return V_38 ;
}
static int F_65 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_38 ;
V_5 = F_24 ( V_2 , V_130 ) ;
if ( ! V_5 )
return - V_54 ;
V_2 -> V_55 = V_126 ;
V_38 = F_61 ( V_2 ) ;
if ( V_38 < 0 )
goto error;
return 0 ;
error:
F_29 ( V_2 ) ;
return V_38 ;
}
