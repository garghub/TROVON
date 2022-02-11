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
V_5 -> V_17 = V_5 -> V_11 . V_18 ?
V_5 -> V_15 : V_5 -> V_16 ;
F_2 ( V_2 , 0x01 , 0 ,
V_19 , V_5 -> V_17 ) ;
}
}
static bool F_7 ( struct V_1 * V_2 , T_1 V_20 )
{
unsigned int V_21 ;
V_21 = F_8 ( V_2 , V_20 ) ;
return ( F_9 ( V_21 ) != V_22 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
if ( V_5 -> V_6 == V_23 ) {
V_9 = F_1 ( V_2 , V_24 ) ;
if ( F_7 ( V_2 , V_25 ) )
V_9 |= 1 << 4 ;
if ( F_7 ( V_2 , V_26 ) )
V_9 |= 1 << 3 ;
F_4 ( V_2 , V_24 , V_9 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
unsigned int V_9 ;
V_9 = 0x0002 ;
V_9 |= 0x0008 ;
if ( F_7 ( V_2 , V_27 ) )
V_9 |= 0x4000 ;
F_4 ( V_2 , V_28 , V_9 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_23 ) {
F_13 ( V_2 , V_29 ) ;
F_13 ( V_2 , V_30 ) ;
} else if ( V_5 -> V_6 == V_31 ) {
F_13 ( V_2 , V_32 ) ;
}
F_14 ( V_2 ) ;
if ( V_5 -> V_33 ) {
F_2 ( V_2 , 0x01 , 0 , V_34 ,
V_5 -> V_33 ) ;
F_2 ( V_2 , 0x01 , 0 , V_35 ,
V_5 -> V_36 ) ;
F_2 ( V_2 , 0x01 , 0 , V_19 ,
V_5 -> V_17 ) ;
}
if ( V_5 -> V_6 == V_23 ) {
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
}
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_37 ;
V_37 = F_16 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
F_17 ( V_2 , V_38 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_37 ;
V_37 = F_19 ( V_2 , & V_5 -> V_11 . V_39 , NULL , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_20 ( V_2 , & V_5 -> V_11 . V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static void F_21 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
if ( V_42 == V_43 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 2 ;
V_5 -> V_16 = 8 ;
V_5 -> V_33 = V_5 -> V_36 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static void F_22 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
if ( V_42 == V_43 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 4 ;
V_5 -> V_16 = 8 ;
V_5 -> V_33 = V_5 -> V_36 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static struct V_4 * F_23 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 ;
V_5 = F_24 ( sizeof( * V_5 ) , V_44 ) ;
if ( ! V_5 )
return NULL ;
V_2 -> V_5 = V_5 ;
V_5 -> V_6 = V_6 ;
V_2 -> V_45 = 1 ;
F_25 ( & V_5 -> V_11 ) ;
return V_5 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_23 ( V_2 , V_23 ) ;
if ( ! V_5 )
return - V_46 ;
V_2 -> V_47 = V_48 ;
V_5 -> V_11 . V_49 = F_5 ;
V_2 -> V_50 = 1 ;
F_27 ( V_2 , V_51 , V_52 ,
V_53 ) ;
F_17 ( V_2 , V_43 ) ;
V_37 = F_18 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
F_17 ( V_2 , V_54 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_37 ;
}
static void F_29 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
if ( V_42 == V_43 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 0 ;
V_5 -> V_16 = 1 ;
V_5 -> V_33 = V_5 -> V_36 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static void F_30 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
if ( V_42 != V_43 )
return;
V_2 -> V_55 = V_56 ;
F_27 ( V_2 , NULL , V_57 , V_58 ) ;
if ( V_2 -> V_55 == V_56 )
V_2 -> V_55 = V_59 ;
F_17 ( V_2 , V_42 ) ;
}
static int F_31 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_32 ( V_61 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_64 = V_5 -> V_11 . V_39 . V_65 [ 0 ] ;
int V_66 = V_63 -> V_67 . integer . V_67 [ 0 ] ? V_68 : 0 ;
F_33 ( V_2 , V_64 , V_66 ) ;
return V_5 -> V_69 ( V_61 , V_63 ) ;
}
static void F_34 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
if ( V_42 == V_38 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_60 * V_70 ;
if ( ! V_5 -> V_11 . V_39 . V_65 [ 0 ] )
return;
V_70 = F_35 ( V_2 , L_1 ) ;
if ( ! V_70 )
return;
V_5 -> V_69 = V_70 -> V_71 ;
V_70 -> V_71 = F_31 ;
}
}
static void F_36 ( struct V_1 * V_2 , T_1 V_72 )
{
unsigned int V_73 ;
V_73 = F_37 ( V_2 , V_72 , V_74 ) ;
V_73 &= ~ ( V_75 ) ;
V_73 |= 0x02 ;
F_38 ( V_2 , V_72 , V_74 , V_73 ) ;
}
static int F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_23 ( V_2 , V_31 ) ;
if ( ! V_5 )
return - V_46 ;
V_2 -> V_47 = V_48 ;
V_5 -> V_11 . V_49 = F_5 ;
V_5 -> V_11 . V_76 = 1ULL << 0x10 ;
F_27 ( V_2 , V_77 , V_78 ,
V_58 ) ;
F_17 ( V_2 , V_43 ) ;
F_40 ( V_2 , 0x18 ,
F_41 ( V_2 , 0x18 ) | V_79 ) ;
F_36 ( V_2 , 0x18 ) ;
F_36 ( V_2 , 0x1b ) ;
F_36 ( V_2 , 0x1c ) ;
V_37 = F_18 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
F_17 ( V_2 , V_54 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_37 ;
}
static void F_42 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_42 == V_43 )
V_5 -> V_14 = 1 ;
}
static int F_43 ( struct V_60 * V_61 ,
struct V_80 * V_81 )
{
V_81 -> type = V_82 ;
V_81 -> V_83 = 1 ;
V_81 -> V_67 . integer . V_84 = 0 ;
V_81 -> V_67 . integer . V_85 = 3 ;
return 0 ;
}
static int F_44 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_32 ( V_61 ) ;
V_63 -> V_67 . integer . V_67 [ 0 ] =
F_1 ( V_2 , V_86 ) & 0x0003 ;
return 0 ;
}
static int F_45 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_1 * V_2 = F_32 ( V_61 ) ;
unsigned int V_87 = V_63 -> V_67 . integer . V_67 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_86 ) ;
unsigned int V_88 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_87 & 0x0003 ) ;
if ( V_88 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_86 , V_9 ) ;
return 1 ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_89 , V_9 ;
V_9 = F_1 ( V_2 , V_90 ) ;
if ( V_5 -> V_33 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_14 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_90 , V_9 ) ;
if ( ( V_5 -> V_33 || V_5 -> V_14 ) &&
F_7 ( V_2 , V_91 ) ) {
V_89 = F_8 ( V_2 , V_91 ) ;
V_89 &= ~ V_92 ;
V_89 |= ( V_22 << V_93 ) ;
F_47 ( V_2 , V_91 , V_89 ) ;
}
}
static void F_48 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
bool V_13 = false ;
T_1 V_96 = V_5 -> V_11 . V_39 . V_65 [ 0 ] ;
if ( ! V_5 -> V_97 ||
V_5 -> V_6 != V_98 )
return;
V_13 = F_49 ( V_2 , V_96 ) ;
if ( V_13 == V_5 -> V_13 )
return;
V_5 -> V_13 = V_13 ;
F_50 ( V_2 , V_96 , V_13 ? V_68 : 0 ) ;
F_5 ( V_2 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_99 * V_100 = & V_5 -> V_11 . V_39 ;
int V_101 ;
for ( V_101 = 0 ; V_101 < V_100 -> V_102 ; V_101 ++ ) {
T_1 V_20 = V_100 -> V_65 [ V_101 ] ;
if ( F_41 ( V_2 , V_20 ) & V_103 ) {
V_5 -> V_97 = 1 ;
F_52 ( V_2 , V_20 ,
F_48 ) ;
}
}
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_98 ) {
F_13 ( V_2 , V_104 ) ;
F_13 ( V_2 , V_105 ) ;
F_46 ( V_2 ) ;
}
F_14 ( V_2 ) ;
if ( V_5 -> V_33 ) {
F_2 ( V_2 , 0x01 , 0 , V_34 ,
V_5 -> V_33 ) ;
F_2 ( V_2 , 0x01 , 0 , V_35 ,
V_5 -> V_36 ) ;
F_2 ( V_2 , 0x01 , 0 , V_19 ,
V_5 -> V_17 ) ;
}
F_10 ( V_2 ) ;
F_48 ( V_2 , NULL ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_37 ;
V_37 = F_16 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_5 -> V_11 . V_39 . V_106 &&
V_5 -> V_6 == V_98 ) {
V_37 = F_55 ( V_2 , 0 ,
F_56 ( & V_107 , V_2 ) ) ;
if ( V_37 < 0 )
return V_37 ;
}
return 0 ;
}
static void F_57 ( struct V_1 * V_2 , T_1 V_108 )
{
unsigned int V_73 ;
V_73 = F_37 ( V_2 , V_108 , V_109 ) ;
V_73 &= ~ ( 0x7f << V_110 ) ;
V_73 |= ( ( V_73 >> V_111 ) & 0x7f )
<< V_110 ;
F_38 ( V_2 , V_108 , V_109 , V_73 ) ;
}
static int F_58 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_108 = V_112 ;
int V_37 ;
F_57 ( V_2 , V_108 ) ;
V_37 = F_19 ( V_2 , & V_5 -> V_11 . V_39 , NULL , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_20 ( V_2 , & V_5 -> V_11 . V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
F_51 ( V_2 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
F_60 ( V_2 ) ;
F_2 ( V_2 , V_112 , 0 ,
V_113 , V_114 ) ;
F_2 ( V_2 , V_115 , 0 ,
V_113 , V_114 ) ;
if ( V_5 -> V_6 == V_98 ) {
V_9 = F_1 ( V_2 , V_90 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_90 , V_9 ) ;
}
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_23 ( V_2 , V_98 ) ;
if ( ! V_5 )
return - V_46 ;
V_2 -> V_47 = V_116 ;
V_5 -> V_11 . V_49 = F_5 ;
F_27 ( V_2 , V_117 , V_118 ,
V_119 ) ;
F_17 ( V_2 , V_43 ) ;
F_46 ( V_2 ) ;
V_37 = F_58 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
F_17 ( V_2 , V_54 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_37 ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_23 ( V_2 , V_120 ) ;
if ( ! V_5 )
return - V_46 ;
V_2 -> V_47 = V_116 ;
V_37 = F_58 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_37 ;
}
