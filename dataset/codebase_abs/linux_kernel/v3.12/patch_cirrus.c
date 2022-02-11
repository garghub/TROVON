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
struct V_4 * V_5 = V_2 -> V_5 ;
int V_37 ;
V_37 = F_16 ( V_2 , & V_5 -> V_11 . V_38 , NULL , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_17 ( V_2 , & V_5 -> V_11 . V_38 ) ;
if ( V_37 < 0 )
return V_37 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
const struct V_39 * V_40 , int V_41 )
{
if ( V_41 == V_42 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 2 ;
V_5 -> V_16 = 8 ;
V_5 -> V_33 = V_5 -> V_36 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static void F_19 ( struct V_1 * V_2 ,
const struct V_39 * V_40 , int V_41 )
{
if ( V_41 == V_42 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 4 ;
V_5 -> V_16 = 8 ;
V_5 -> V_33 = V_5 -> V_36 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static struct V_4 * F_20 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 ;
V_5 = F_21 ( sizeof( * V_5 ) , V_43 ) ;
if ( ! V_5 )
return NULL ;
V_2 -> V_5 = V_5 ;
V_5 -> V_6 = V_6 ;
F_22 ( & V_5 -> V_11 ) ;
return V_5 ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_20 ( V_2 , V_23 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_11 . V_45 = F_5 ;
F_24 ( V_2 , V_46 , V_47 ,
V_48 ) ;
F_25 ( V_2 , V_42 ) ;
V_37 = F_15 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_49 = V_50 ;
F_25 ( V_2 , V_51 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_37 ;
}
static void F_27 ( struct V_1 * V_2 ,
const struct V_39 * V_40 , int V_41 )
{
if ( V_41 == V_42 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 0 ;
V_5 -> V_16 = 1 ;
V_5 -> V_33 = V_5 -> V_36 =
V_5 -> V_15 | V_5 -> V_16 ;
}
}
static void F_28 ( struct V_1 * V_2 , T_1 V_52 )
{
unsigned int V_53 ;
V_53 = F_29 ( V_2 , V_52 , V_54 ) ;
V_53 &= ~ ( V_55 ) ;
V_53 |= 0x02 ;
F_30 ( V_2 , V_52 , V_54 , V_53 ) ;
}
static int F_31 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_20 ( V_2 , V_31 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_11 . V_45 = F_5 ;
F_24 ( V_2 , V_56 , V_57 ,
V_58 ) ;
F_25 ( V_2 , V_42 ) ;
F_32 ( V_2 , 0x18 ,
F_33 ( V_2 , 0x18 ) | V_59 ) ;
F_28 ( V_2 , 0x18 ) ;
F_28 ( V_2 , 0x1b ) ;
F_28 ( V_2 , 0x1c ) ;
V_37 = F_15 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_49 = V_50 ;
F_25 ( V_2 , V_51 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_37 ;
}
static void F_34 ( struct V_1 * V_2 ,
const struct V_39 * V_40 , int V_41 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_41 == V_42 )
V_5 -> V_14 = 1 ;
}
static int F_35 ( struct V_60 * V_61 ,
struct V_62 * V_63 )
{
V_63 -> type = V_64 ;
V_63 -> V_65 = 1 ;
V_63 -> V_66 . integer . V_67 = 0 ;
V_63 -> V_66 . integer . V_68 = 3 ;
return 0 ;
}
static int F_36 ( struct V_60 * V_61 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_37 ( V_61 ) ;
V_70 -> V_66 . integer . V_66 [ 0 ] =
F_1 ( V_2 , V_71 ) & 0x0003 ;
return 0 ;
}
static int F_38 ( struct V_60 * V_61 ,
struct V_69 * V_70 )
{
struct V_1 * V_2 = F_37 ( V_61 ) ;
unsigned int V_72 = V_70 -> V_66 . integer . V_66 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_71 ) ;
unsigned int V_73 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_72 & 0x0003 ) ;
if ( V_73 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_71 , V_9 ) ;
return 1 ;
}
}
static void F_39 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_74 , V_9 ;
V_9 = F_1 ( V_2 , V_75 ) ;
if ( V_5 -> V_33 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_14 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_75 , V_9 ) ;
if ( ( V_5 -> V_33 || V_5 -> V_14 ) &&
F_7 ( V_2 , V_76 ) ) {
V_74 = F_8 ( V_2 , V_76 ) ;
V_74 &= ~ V_77 ;
V_74 |= ( V_22 << V_78 ) ;
F_40 ( V_2 , V_76 , V_74 ) ;
}
}
static void F_41 ( struct V_1 * V_2 ,
struct V_79 * V_80 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
bool V_13 = false ;
T_1 V_81 = V_5 -> V_11 . V_38 . V_82 [ 0 ] ;
if ( ! V_5 -> V_83 ||
V_5 -> V_6 != V_84 )
return;
V_13 = F_42 ( V_2 , V_81 ) ;
if ( V_13 == V_5 -> V_13 )
return;
V_5 -> V_13 = V_13 ;
if ( V_13 )
F_43 ( V_2 , V_81 ,
V_13 ? V_85 : 0 ) ;
F_5 ( V_2 ) ;
}
static void F_44 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_86 * V_87 = & V_5 -> V_11 . V_38 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_87 -> V_89 ; V_88 ++ ) {
T_1 V_20 = V_87 -> V_82 [ V_88 ] ;
if ( F_33 ( V_2 , V_20 ) & V_90 ) {
V_5 -> V_83 = 1 ;
F_45 ( V_2 , V_20 ,
V_91 ,
F_41 ) ;
}
}
}
static int F_46 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_84 ) {
F_13 ( V_2 , V_92 ) ;
F_13 ( V_2 , V_93 ) ;
F_39 ( V_2 ) ;
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
F_41 ( V_2 , NULL ) ;
return 0 ;
}
static int F_47 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_37 ;
V_37 = F_48 ( V_2 ) ;
if ( V_37 < 0 )
return V_37 ;
if ( V_5 -> V_11 . V_38 . V_94 &&
V_5 -> V_6 == V_84 ) {
V_37 = F_49 ( V_2 , 0 ,
F_50 ( & V_95 , V_2 ) ) ;
if ( V_37 < 0 )
return V_37 ;
}
return 0 ;
}
static void F_51 ( struct V_1 * V_2 , T_1 V_96 )
{
unsigned int V_53 ;
V_53 = F_29 ( V_2 , V_96 , V_97 ) ;
V_53 &= ~ ( 0x7f << V_98 ) ;
V_53 |= ( ( V_53 >> V_99 ) & 0x7f )
<< V_98 ;
F_30 ( V_2 , V_96 , V_97 , V_53 ) ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_96 = V_100 ;
int V_37 ;
F_51 ( V_2 , V_96 ) ;
V_37 = F_16 ( V_2 , & V_5 -> V_11 . V_38 , NULL , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_37 = F_17 ( V_2 , & V_5 -> V_11 . V_38 ) ;
if ( V_37 < 0 )
return V_37 ;
F_44 ( V_2 ) ;
return 0 ;
}
static int F_53 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
F_54 ( V_2 ) ;
F_2 ( V_2 , V_100 , 0 ,
V_101 , V_102 ) ;
F_2 ( V_2 , V_103 , 0 ,
V_101 , V_102 ) ;
if ( V_5 -> V_6 == V_84 ) {
V_9 = F_1 ( V_2 , V_75 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_75 , V_9 ) ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_20 ( V_2 , V_84 ) ;
if ( ! V_5 )
return - V_44 ;
V_5 -> V_11 . V_45 = F_5 ;
F_24 ( V_2 , V_104 , V_105 ,
V_106 ) ;
F_25 ( V_2 , V_42 ) ;
F_39 ( V_2 ) ;
V_37 = F_52 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_49 = V_107 ;
F_25 ( V_2 , V_51 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_37 ;
}
static int F_56 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_37 ;
V_5 = F_20 ( V_2 , V_108 ) ;
if ( ! V_5 )
return - V_44 ;
V_37 = F_52 ( V_2 ) ;
if ( V_37 < 0 )
goto error;
V_2 -> V_49 = V_107 ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_37 ;
}
static int T_2 F_57 ( void )
{
return F_58 ( & V_109 ) ;
}
static void T_3 F_59 ( void )
{
F_60 ( & V_109 ) ;
}
