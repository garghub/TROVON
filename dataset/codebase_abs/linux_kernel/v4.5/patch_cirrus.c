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
static void F_31 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
static const struct V_60 V_61 [] = {
{ 0x18 , 0x00ab9150 } ,
{ 0x21 , 0x004be140 } ,
{ }
} ;
if ( V_42 == V_43 ) {
V_2 -> V_62 = 1 ;
F_32 ( V_2 , V_61 ) ;
}
}
static int F_33 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_67 = V_5 -> V_11 . V_39 . V_68 [ 0 ] ;
int V_69 = V_66 -> V_70 . integer . V_70 [ 0 ] ? V_71 : 0 ;
F_35 ( V_2 , V_67 , V_69 ) ;
return V_5 -> V_72 ( V_64 , V_66 ) ;
}
static void F_36 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
if ( V_42 == V_38 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_63 * V_73 ;
if ( ! V_5 -> V_11 . V_39 . V_68 [ 0 ] )
return;
V_73 = F_37 ( V_2 , L_1 ) ;
if ( ! V_73 )
return;
V_5 -> V_72 = V_73 -> V_74 ;
V_73 -> V_74 = F_33 ;
}
}
static void F_38 ( struct V_1 * V_2 , T_1 V_75 )
{
unsigned int V_76 ;
V_76 = F_39 ( V_2 , V_75 , V_77 ) ;
V_76 &= ~ ( V_78 ) ;
V_76 |= 0x02 ;
F_40 ( V_2 , V_75 , V_77 , V_76 ) ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_23 ( V_2 , V_31 ) ;
if ( ! V_5 )
return - V_46 ;
V_2 -> V_47 = V_48 ;
V_5 -> V_11 . V_49 = F_5 ;
V_5 -> V_11 . V_79 = 1ULL << 0x10 ;
F_27 ( V_2 , V_80 , V_81 ,
V_58 ) ;
F_17 ( V_2 , V_43 ) ;
F_42 ( V_2 , 0x18 ,
F_43 ( V_2 , 0x18 ) | V_82 ) ;
F_38 ( V_2 , 0x18 ) ;
F_38 ( V_2 , 0x1b ) ;
F_38 ( V_2 , 0x1c ) ;
V_37 = F_18 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
F_17 ( V_2 , V_54 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_37 ;
}
static void F_44 ( struct V_1 * V_2 ,
const struct V_40 * V_41 , int V_42 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_42 == V_43 )
V_5 -> V_14 = 1 ;
}
static int F_45 ( struct V_63 * V_64 ,
struct V_83 * V_84 )
{
V_84 -> type = V_85 ;
V_84 -> V_86 = 1 ;
V_84 -> V_70 . integer . V_87 = 0 ;
V_84 -> V_70 . integer . V_88 = 3 ;
return 0 ;
}
static int F_46 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
V_66 -> V_70 . integer . V_70 [ 0 ] =
F_1 ( V_2 , V_89 ) & 0x0003 ;
return 0 ;
}
static int F_47 ( struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_1 * V_2 = F_34 ( V_64 ) ;
unsigned int V_90 = V_66 -> V_70 . integer . V_70 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_89 ) ;
unsigned int V_91 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_90 & 0x0003 ) ;
if ( V_91 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_89 , V_9 ) ;
return 1 ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_92 , V_9 ;
V_9 = F_1 ( V_2 , V_93 ) ;
if ( V_5 -> V_33 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_14 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_93 , V_9 ) ;
if ( ( V_5 -> V_33 || V_5 -> V_14 ) &&
F_7 ( V_2 , V_94 ) ) {
V_92 = F_8 ( V_2 , V_94 ) ;
V_92 &= ~ V_95 ;
V_92 |= ( V_22 << V_96 ) ;
F_49 ( V_2 , V_94 , V_92 ) ;
}
}
static void F_50 ( struct V_1 * V_2 ,
struct V_97 * V_98 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
bool V_13 = false ;
T_1 V_99 = V_5 -> V_11 . V_39 . V_68 [ 0 ] ;
if ( ! V_5 -> V_100 ||
V_5 -> V_6 != V_101 )
return;
V_13 = F_51 ( V_2 , V_99 ) ;
if ( V_13 == V_5 -> V_13 )
return;
V_5 -> V_13 = V_13 ;
F_52 ( V_2 , V_99 , V_13 ? V_71 : 0 ) ;
F_5 ( V_2 ) ;
}
static void F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_102 * V_103 = & V_5 -> V_11 . V_39 ;
int V_104 ;
for ( V_104 = 0 ; V_104 < V_103 -> V_105 ; V_104 ++ ) {
T_1 V_20 = V_103 -> V_68 [ V_104 ] ;
if ( F_43 ( V_2 , V_20 ) & V_106 ) {
V_5 -> V_100 = 1 ;
F_54 ( V_2 , V_20 ,
F_50 ) ;
}
}
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_101 ) {
F_13 ( V_2 , V_107 ) ;
F_13 ( V_2 , V_108 ) ;
F_48 ( V_2 ) ;
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
F_50 ( V_2 , NULL ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_37 ;
V_37 = F_16 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_5 -> V_11 . V_39 . V_109 &&
V_5 -> V_6 == V_101 ) {
V_37 = F_57 ( V_2 , 0 ,
F_58 ( & V_110 , V_2 ) ) ;
if ( V_37 < 0 )
return V_37 ;
}
return 0 ;
}
static void F_59 ( struct V_1 * V_2 , T_1 V_111 )
{
unsigned int V_76 ;
V_76 = F_39 ( V_2 , V_111 , V_112 ) ;
V_76 &= ~ ( 0x7f << V_113 ) ;
V_76 |= ( ( V_76 >> V_114 ) & 0x7f )
<< V_113 ;
F_40 ( V_2 , V_111 , V_112 , V_76 ) ;
}
static int F_60 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_111 = V_115 ;
int V_37 ;
F_59 ( V_2 , V_111 ) ;
V_37 = F_19 ( V_2 , & V_5 -> V_11 . V_39 , NULL , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_20 ( V_2 , & V_5 -> V_11 . V_39 ) ;
if ( V_37 < 0 )
return V_37 ;
F_53 ( V_2 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
F_62 ( V_2 ) ;
F_2 ( V_2 , V_115 , 0 ,
V_116 , V_117 ) ;
F_2 ( V_2 , V_118 , 0 ,
V_116 , V_117 ) ;
if ( V_5 -> V_6 == V_101 ) {
V_9 = F_1 ( V_2 , V_93 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_93 , V_9 ) ;
}
return 0 ;
}
static int F_63 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_23 ( V_2 , V_101 ) ;
if ( ! V_5 )
return - V_46 ;
V_2 -> V_47 = V_119 ;
V_5 -> V_11 . V_49 = F_5 ;
F_27 ( V_2 , V_120 , V_121 ,
V_122 ) ;
F_17 ( V_2 , V_43 ) ;
F_48 ( V_2 ) ;
V_37 = F_60 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
F_17 ( V_2 , V_54 ) ;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_37 ;
}
static int F_64 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_23 ( V_2 , V_123 ) ;
if ( ! V_5 )
return - V_46 ;
V_2 -> V_47 = V_119 ;
V_37 = F_60 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
return 0 ;
error:
F_28 ( V_2 ) ;
return V_37 ;
}
