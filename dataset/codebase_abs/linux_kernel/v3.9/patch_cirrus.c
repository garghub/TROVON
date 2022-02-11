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
if ( V_5 -> V_15 ) {
V_5 -> V_16 = V_5 -> V_11 . V_17 ?
V_5 -> V_15 : V_5 -> V_18 ;
F_2 ( V_2 , 0x01 , 0 ,
V_19 , V_5 -> V_16 ) ;
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
F_13 ( V_2 , V_29 ) ;
F_13 ( V_2 , V_30 ) ;
F_14 ( V_2 ) ;
if ( V_5 -> V_31 ) {
F_2 ( V_2 , 0x01 , 0 , V_32 ,
V_5 -> V_31 ) ;
F_2 ( V_2 , 0x01 , 0 , V_33 ,
V_5 -> V_34 ) ;
F_2 ( V_2 , 0x01 , 0 , V_19 ,
V_5 -> V_16 ) ;
}
F_10 ( V_2 ) ;
F_11 ( V_2 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_35 ;
V_35 = F_16 ( V_2 , & V_5 -> V_11 . V_36 , NULL , 0 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_17 ( V_2 , & V_5 -> V_11 . V_36 ) ;
if ( V_35 < 0 )
return V_35 ;
return 0 ;
}
static void F_18 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
if ( V_39 == V_40 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 2 ;
V_5 -> V_18 = 8 ;
V_5 -> V_31 = V_5 -> V_34 =
V_5 -> V_15 | V_5 -> V_18 ;
}
}
static void F_19 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
if ( V_39 == V_40 ) {
struct V_4 * V_5 = V_2 -> V_5 ;
V_5 -> V_15 = 4 ;
V_5 -> V_18 = 8 ;
V_5 -> V_31 = V_5 -> V_34 =
V_5 -> V_15 | V_5 -> V_18 ;
}
}
static struct V_4 * F_20 ( struct V_1 * V_2 , int V_6 )
{
struct V_4 * V_5 ;
V_5 = F_21 ( sizeof( * V_5 ) , V_41 ) ;
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
int V_35 ;
V_5 = F_20 ( V_2 , V_23 ) ;
if ( ! V_5 )
return - V_42 ;
V_5 -> V_11 . V_43 = F_5 ;
F_24 ( V_2 , V_44 , V_45 ,
V_46 ) ;
F_25 ( V_2 , V_40 ) ;
V_35 = F_15 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_47 = V_48 ;
F_25 ( V_2 , V_49 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_35 ;
}
static void F_27 ( struct V_1 * V_2 ,
const struct V_37 * V_38 , int V_39 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_39 == V_40 )
V_5 -> V_14 = 1 ;
}
static int F_28 ( struct V_50 * V_51 ,
struct V_52 * V_53 )
{
V_53 -> type = V_54 ;
V_53 -> V_55 = 1 ;
V_53 -> V_56 . integer . V_57 = 0 ;
V_53 -> V_56 . integer . V_58 = 3 ;
return 0 ;
}
static int F_29 ( struct V_50 * V_51 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_30 ( V_51 ) ;
V_60 -> V_56 . integer . V_56 [ 0 ] =
F_1 ( V_2 , V_61 ) & 0x0003 ;
return 0 ;
}
static int F_31 ( struct V_50 * V_51 ,
struct V_59 * V_60 )
{
struct V_1 * V_2 = F_30 ( V_51 ) ;
unsigned int V_62 = V_60 -> V_56 . integer . V_56 [ 0 ] ;
unsigned int V_9 =
F_1 ( V_2 , V_61 ) ;
unsigned int V_63 = V_9 ;
V_9 &= ~ 0x0003 ;
V_9 |= ( V_62 & 0x0003 ) ;
if ( V_63 == V_9 )
return 0 ;
else {
F_4 ( V_2 , V_61 , V_9 ) ;
return 1 ;
}
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_64 , V_9 ;
V_9 = F_1 ( V_2 , V_65 ) ;
if ( V_5 -> V_31 )
V_9 |= 0x0008 ;
else
V_9 &= ~ 0x0008 ;
if ( V_5 -> V_14 )
V_9 |= 0x0010 ;
else
V_9 &= ~ 0x0010 ;
F_4 ( V_2 , V_65 , V_9 ) ;
if ( ( V_5 -> V_31 || V_5 -> V_14 ) &&
F_7 ( V_2 , V_66 ) ) {
V_64 = F_8 ( V_2 , V_66 ) ;
V_64 &= ~ V_67 ;
V_64 |= ( V_22 << V_68 ) ;
F_33 ( V_2 , V_66 , V_64 ) ;
}
}
static void F_34 ( struct V_1 * V_2 ,
struct V_69 * V_70 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
bool V_13 = false ;
T_1 V_71 = V_5 -> V_11 . V_36 . V_72 [ 0 ] ;
if ( ! V_5 -> V_73 ||
V_5 -> V_6 != V_74 )
return;
V_13 = F_35 ( V_2 , V_71 ) ;
if ( V_13 == V_5 -> V_13 )
return;
V_5 -> V_13 = V_13 ;
if ( V_13 )
F_36 ( V_2 , V_71 ,
V_13 ? V_75 : 0 ) ;
F_5 ( V_2 ) ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
struct V_76 * V_77 = & V_5 -> V_11 . V_36 ;
int V_78 ;
for ( V_78 = 0 ; V_78 < V_77 -> V_79 ; V_78 ++ ) {
T_1 V_20 = V_77 -> V_72 [ V_78 ] ;
if ( F_38 ( V_2 , V_20 ) & V_80 ) {
V_5 -> V_73 = 1 ;
F_39 ( V_2 , V_20 ,
V_81 ,
F_34 ) ;
}
}
}
static int F_40 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_5 -> V_6 == V_74 ) {
F_13 ( V_2 , V_82 ) ;
F_13 ( V_2 , V_83 ) ;
F_32 ( V_2 ) ;
}
F_14 ( V_2 ) ;
if ( V_5 -> V_31 ) {
F_2 ( V_2 , 0x01 , 0 , V_32 ,
V_5 -> V_31 ) ;
F_2 ( V_2 , 0x01 , 0 , V_33 ,
V_5 -> V_34 ) ;
F_2 ( V_2 , 0x01 , 0 , V_19 ,
V_5 -> V_16 ) ;
}
F_10 ( V_2 ) ;
F_34 ( V_2 , NULL ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
int V_35 ;
V_35 = F_42 ( V_2 ) ;
if ( V_35 < 0 )
return V_35 ;
if ( V_5 -> V_11 . V_36 . V_84 &&
V_5 -> V_6 == V_74 ) {
V_35 = F_43 ( V_2 , 0 ,
F_44 ( & V_85 , V_2 ) ) ;
if ( V_35 < 0 )
return V_35 ;
}
return 0 ;
}
static void F_45 ( struct V_1 * V_2 , T_1 V_86 )
{
unsigned int V_87 ;
V_87 = F_46 ( V_2 , V_86 , V_88 ) ;
V_87 &= ~ ( 0x7f << V_89 ) ;
V_87 |= ( ( V_87 >> V_90 ) & 0x7f )
<< V_89 ;
F_47 ( V_2 , V_86 , V_88 , V_87 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
T_1 V_86 = V_91 ;
int V_35 ;
F_45 ( V_2 , V_86 ) ;
V_35 = F_16 ( V_2 , & V_5 -> V_11 . V_36 , NULL , 0 ) ;
if ( V_35 < 0 )
return V_35 ;
V_35 = F_17 ( V_2 , & V_5 -> V_11 . V_36 ) ;
if ( V_35 < 0 )
return V_35 ;
F_37 ( V_2 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_9 ;
F_50 ( V_2 ) ;
F_2 ( V_2 , V_91 , 0 ,
V_92 , V_93 ) ;
F_2 ( V_2 , V_94 , 0 ,
V_92 , V_93 ) ;
if ( V_5 -> V_6 == V_74 ) {
V_9 = F_1 ( V_2 , V_65 ) ;
V_9 |= 0x0004 ;
F_4 ( V_2 , V_65 , V_9 ) ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_35 ;
V_5 = F_20 ( V_2 , V_74 ) ;
if ( ! V_5 )
return - V_42 ;
V_5 -> V_11 . V_43 = F_5 ;
F_24 ( V_2 , V_95 , V_96 ,
V_97 ) ;
F_25 ( V_2 , V_40 ) ;
F_32 ( V_2 ) ;
V_35 = F_48 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_47 = V_98 ;
F_25 ( V_2 , V_49 ) ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_35 ;
}
static int F_52 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
int V_35 ;
V_5 = F_20 ( V_2 , V_99 ) ;
if ( ! V_5 )
return - V_42 ;
V_35 = F_48 ( V_2 ) ;
if ( V_35 < 0 )
goto error;
V_2 -> V_47 = V_98 ;
return 0 ;
error:
F_26 ( V_2 ) ;
return V_35 ;
}
static int T_2 F_53 ( void )
{
return F_54 ( & V_100 ) ;
}
static void T_3 F_55 ( void )
{
F_56 ( & V_100 ) ;
}
