static inline void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 , T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_3 ) ;
V_7 &= ~ F_6 ( V_6 ) ;
F_1 ( V_2 , V_3 , V_7 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_6 )
{
int V_8 ;
F_8 ( V_8 ) ;
F_5 ( V_2 , V_3 , V_6 ) ;
F_9 ( V_8 ) ;
}
static inline void F_10 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_6 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_3 ) ;
V_7 |= F_6 ( V_6 ) ;
F_1 ( V_2 , V_3 , V_7 ) ;
}
static void F_11 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_6 )
{
int V_8 ;
F_8 ( V_8 ) ;
F_10 ( V_2 , V_3 , V_6 ) ;
F_9 ( V_8 ) ;
}
static inline void F_12 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_6 ,
bool V_9 )
{
T_1 V_7 ;
V_7 = F_3 ( V_2 , V_3 ) ;
V_7 &= ~ F_6 ( V_6 ) ;
if ( V_9 )
V_7 |= F_6 ( V_6 ) ;
F_1 ( V_2 , V_3 , V_7 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_6 ,
bool V_9 )
{
int V_8 ;
F_8 ( V_8 ) ;
F_12 ( V_2 , V_3 , V_6 , V_9 ) ;
F_9 ( V_8 ) ;
}
static inline int F_14 ( struct V_1 * V_2 ,
unsigned int V_3 ,
unsigned int V_6 )
{
return F_3 ( V_2 , V_3 ) & F_6 ( V_6 ) ;
}
static int F_15 ( struct V_10 * V_11 ,
unsigned int V_6 )
{
struct V_1 * V_2 = F_16 ( V_11 ) ;
F_11 ( V_2 , V_12 , V_6 ) ;
return 0 ;
}
static int F_17 ( struct V_10 * V_11 ,
unsigned int V_6 , int V_13 )
{
struct V_1 * V_2 = F_16 ( V_11 ) ;
int V_8 ;
F_8 ( V_8 ) ;
F_12 ( V_2 , V_14 , V_6 , V_13 ) ;
F_5 ( V_2 , V_12 , V_6 ) ;
F_9 ( V_8 ) ;
return 0 ;
}
static int F_18 ( struct V_10 * V_11 , unsigned int V_6 )
{
struct V_1 * V_2 = F_16 ( V_11 ) ;
return ! ! F_14 ( V_2 , V_15 , V_6 ) ;
}
static void F_19 ( struct V_10 * V_11 , unsigned int V_6 ,
int V_13 )
{
struct V_1 * V_2 = F_16 ( V_11 ) ;
F_13 ( V_2 , V_14 , V_6 , V_13 ) ;
}
static int F_20 ( struct V_10 * V_11 , unsigned int V_6 )
{
struct V_1 * V_2 = F_16 ( V_11 ) ;
int V_16 ;
V_16 = F_21 ( V_11 -> V_17 + V_6 ) ;
if ( V_16 )
return V_16 ;
F_11 ( V_2 , V_12 , V_6 ) ;
F_11 ( V_2 , V_18 , V_6 ) ;
return 0 ;
}
static void F_22 ( struct V_10 * V_11 , unsigned int V_6 )
{
struct V_1 * V_2 = F_16 ( V_11 ) ;
F_23 ( V_11 -> V_17 + V_6 ) ;
F_7 ( V_2 , V_18 , V_6 ) ;
}
static int F_24 ( struct V_10 * V_11 , unsigned int V_6 )
{
struct V_1 * V_2 = F_16 ( V_11 ) ;
if ( ! V_2 -> V_19 )
return - V_20 ;
return F_25 ( V_2 -> V_19 , V_6 ) ;
}
static inline struct V_1 * F_26 ( struct V_21 * V_4 )
{
return (struct V_1 * ) V_4 -> V_19 -> V_22 ;
}
static void F_27 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int V_23 )
{
F_13 ( V_2 , V_24 , V_6 , V_23 ) ;
}
static void F_28 ( struct V_1 * V_2 ,
unsigned int V_6 , unsigned int type )
{
F_13 ( V_2 , V_25 , V_6 , type ) ;
}
static void F_29 ( struct V_1 * V_2 ,
unsigned int V_6 )
{
unsigned int V_26 , V_27 ;
int V_8 ;
F_8 ( V_8 ) ;
V_27 = ~ F_3 ( V_2 , V_15 ) ;
V_26 = F_3 ( V_2 , V_24 ) ;
V_26 &= ~ F_6 ( V_6 ) ;
V_26 |= V_27 & F_6 ( V_6 ) ;
F_1 ( V_2 , V_24 , V_26 ) ;
F_9 ( V_8 ) ;
}
static unsigned int F_30 ( struct V_21 * V_4 )
{
F_31 ( F_32 ( V_4 ) == V_28 ,
L_1 , V_4 -> V_29 ) ;
F_33 ( V_4 ) ;
F_34 ( V_4 ) ;
return 0 ;
}
static int F_35 ( struct V_21 * V_4 , unsigned int V_30 )
{
struct V_1 * V_2 = F_26 ( V_4 ) ;
unsigned int type ;
unsigned int V_23 ;
switch ( V_30 ) {
case V_31 :
type = V_32 ;
V_23 = V_33 ;
break;
case V_34 :
type = V_32 ;
V_23 = V_35 ;
break;
case V_36 :
type = V_32 ;
V_23 = V_33 ;
break;
case V_37 :
type = V_38 ;
V_23 = V_35 ;
break;
case V_39 :
type = V_38 ;
V_23 = V_33 ;
break;
default:
return - V_20 ;
}
F_28 ( V_2 , V_4 -> V_40 , type ) ;
F_36 ( V_4 , V_30 ) ;
if ( V_30 == V_31 )
F_29 ( V_2 , V_4 -> V_40 ) ;
else
F_27 ( V_2 , V_4 -> V_40 , V_23 ) ;
return 0 ;
}
static int F_37 ( struct V_21 * V_4 , unsigned int V_41 )
{
struct V_1 * V_2 = F_26 ( V_4 ) ;
#ifdef F_38
F_39 ( L_2 , V_4 -> V_29 , V_41 ) ;
#endif
return F_40 ( V_2 -> V_29 , V_41 ) ;
}
static void F_41 ( struct V_42 * V_43 )
{
T_2 V_44 ;
unsigned int V_45 , V_46 ;
struct V_1 * V_2 ;
struct V_42 * V_47 ;
V_2 = (struct V_1 * ) F_42 ( V_43 ) ;
V_45 = F_3 ( V_2 , V_12 ) &
F_3 ( V_2 , V_48 ) &
F_3 ( V_2 , V_49 ) &
0x3FFFFFFF ;
for ( V_44 = 0 ; V_45 ; V_45 >>= 1 , ++ V_44 ) {
if ( ! ( V_45 & 1 ) )
continue;
V_46 = F_43 ( V_2 -> V_19 , V_44 ) ;
V_47 = F_44 ( V_46 ) ;
if ( F_32 ( & V_47 -> V_21 )
== V_31 )
F_29 ( V_2 , V_44 ) ;
F_45 ( V_47 ) ;
}
}
static int F_46 ( struct V_50 * V_51 )
{
struct V_52 * V_53 = V_51 -> V_54 ;
struct V_55 * V_56 = V_51 -> V_57 -> V_56 ;
struct V_1 * V_2 ;
struct V_58 * V_59 ;
int V_60 ;
V_2 = F_47 ( V_56 , sizeof( * V_2 ) , V_61 ) ;
if ( ! V_2 ) {
F_48 ( V_56 , L_3 ) ;
return - V_62 ;
}
V_2 -> V_5 = V_51 -> V_57 -> V_5 + V_51 -> V_63 * 4 ;
snprintf ( V_2 -> V_64 , sizeof( V_2 -> V_64 ) , L_4 ,
V_51 -> V_63 ) ;
V_2 -> V_11 . V_64 = V_2 -> V_64 ;
V_2 -> V_11 . V_65 = V_56 ;
V_2 -> V_11 . V_66 = F_15 ;
V_2 -> V_11 . V_67 = F_17 ;
V_2 -> V_11 . V_68 = F_18 ;
V_2 -> V_11 . V_69 = F_19 ;
V_2 -> V_11 . free = F_22 ;
V_2 -> V_11 . V_70 = F_20 ;
V_2 -> V_11 . V_71 = F_24 ;
V_2 -> V_11 . V_72 = V_53 ;
V_2 -> V_11 . V_17 = V_51 -> V_63 * 30 ;
V_2 -> V_11 . V_73 = 30 ;
F_49 ( & V_2 -> V_11 , V_2 ) ;
V_2 -> V_29 = F_50 ( V_53 , 0 ) ;
if ( ! V_2 -> V_29 ) {
F_51 ( V_56 , L_5 ,
V_51 -> V_63 ) ;
return 0 ;
}
F_51 ( V_56 , L_6 ,
V_51 -> V_63 ) ;
F_1 ( V_2 , V_49 , 0 ) ;
V_2 -> V_19 = F_52 ( V_53 ,
V_2 -> V_11 . V_73 ,
& V_74 ,
V_2 ) ;
V_60 = F_53 ( V_2 -> V_19 , V_2 -> V_11 . V_73 , 2 ,
V_2 -> V_64 , V_75 , 0 , 0 ,
V_76 ) ;
if ( V_60 ) {
F_51 ( V_56 ,
L_7 ,
V_51 -> V_63 ) ;
F_54 ( V_2 -> V_19 ) ;
return 0 ;
}
V_59 = F_55 ( V_2 -> V_19 , 0 ) ;
V_59 -> V_77 = V_2 -> V_5 ;
V_59 -> V_78 [ 0 ] . type = V_79 ;
V_59 -> V_78 [ 0 ] . V_80 = V_81 ;
V_59 -> V_78 [ 0 ] . V_82 . V_83 = V_48 ;
V_59 -> V_78 [ 0 ] . V_82 . V_84 = V_49 ;
V_59 -> V_78 [ 0 ] . V_11 . V_85 = F_30 ;
V_59 -> V_78 [ 0 ] . V_11 . V_86 = F_33 ;
V_59 -> V_78 [ 0 ] . V_11 . V_87 = V_88 ;
V_59 -> V_78 [ 0 ] . V_11 . V_89 = F_34 ;
V_59 -> V_78 [ 0 ] . V_11 . V_90 = F_35 ;
V_59 -> V_78 [ 0 ] . V_11 . V_91 = F_37 ;
V_59 -> V_78 [ 0 ] . V_11 . V_92 = V_93 ;
V_59 -> V_78 [ 1 ] . type = V_31 ;
V_59 -> V_78 [ 1 ] . V_80 = V_94 ;
V_59 -> V_78 [ 1 ] . V_82 . V_83 = V_48 ;
V_59 -> V_78 [ 1 ] . V_82 . V_84 = V_49 ;
V_59 -> V_78 [ 1 ] . V_11 . V_85 = F_30 ;
V_59 -> V_78 [ 1 ] . V_11 . V_86 = F_33 ;
V_59 -> V_78 [ 1 ] . V_11 . V_87 = V_88 ;
V_59 -> V_78 [ 1 ] . V_11 . V_89 = F_34 ;
V_59 -> V_78 [ 1 ] . V_11 . V_90 = F_35 ;
V_59 -> V_78 [ 1 ] . V_11 . V_91 = F_37 ;
V_59 -> V_78 [ 1 ] . V_11 . V_92 = V_93 ;
F_56 ( V_2 -> V_29 , F_41 ,
V_2 ) ;
return 0 ;
}
static void F_57 ( struct V_95 * V_57 )
{
struct V_52 * V_53 = V_57 -> V_56 -> V_72 ;
struct V_52 * V_54 ;
F_58 (np, node) {
struct V_50 V_51 ;
T_1 V_96 ;
int V_16 ;
V_16 = F_59 ( V_54 , L_8 , & V_96 ) ;
if ( V_16 ) {
F_48 ( V_57 -> V_56 , L_9 ,
V_54 -> V_97 ) ;
continue;
}
if ( V_96 >= 3 ) {
F_48 ( V_57 -> V_56 , L_10 ,
V_96 , V_54 -> V_97 ) ;
continue;
}
V_51 . V_63 = V_96 ;
V_51 . V_54 = F_60 ( V_54 ) ;
V_51 . V_57 = V_57 ;
V_16 = F_46 ( & V_51 ) ;
if ( V_16 ) {
F_48 ( V_57 -> V_56 , L_11 ,
V_54 -> V_97 ) ;
F_61 ( V_54 ) ;
continue;
}
}
}
static int F_62 ( struct V_98 * V_99 )
{
struct V_52 * V_53 = V_99 -> V_56 . V_72 ;
struct V_100 * V_101 ;
struct V_95 V_57 ;
if ( ! V_53 ) {
F_48 ( & V_99 -> V_56 , L_12 ) ;
return - V_102 ;
}
V_101 = F_63 ( V_99 , V_103 , 0 ) ;
if ( ! V_101 ) {
F_48 ( & V_99 -> V_56 , L_13 ) ;
return - V_102 ;
}
V_57 . V_56 = & V_99 -> V_56 ;
V_57 . V_5 = F_64 ( & V_99 -> V_56 , V_101 -> V_104 ,
F_65 ( V_101 ) ) ;
if ( ! V_57 . V_5 ) {
F_48 ( & V_99 -> V_56 , L_14 ) ;
return - V_62 ;
}
F_57 ( & V_57 ) ;
return 0 ;
}
static int T_3 F_66 ( void )
{
return F_67 ( & V_105 ) ;
}
