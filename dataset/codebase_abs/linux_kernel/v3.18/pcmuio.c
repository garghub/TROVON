static inline unsigned long F_1 ( struct V_1 * V_2 ,
int V_3 )
{
return V_2 -> V_4 + ( V_3 * V_5 ) ;
}
static inline int F_2 ( struct V_6 * V_7 )
{
return V_7 -> V_8 / 2 ;
}
static inline int F_3 ( struct V_6 * V_7 )
{
return ( V_7 -> V_8 % 2 ) ? 3 : 0 ;
}
static void F_4 ( struct V_1 * V_2 , unsigned int V_9 ,
int V_3 , int V_10 , int V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
unsigned long V_4 = F_1 ( V_2 , V_3 ) ;
unsigned long V_18 ;
F_5 ( & V_16 -> V_19 , V_18 ) ;
if ( V_10 == 0 ) {
F_6 ( V_9 & 0xff , V_4 + F_7 ( V_11 + 0 ) ) ;
F_6 ( ( V_9 >> 8 ) & 0xff , V_4 + F_7 ( V_11 + 1 ) ) ;
F_6 ( ( V_9 >> 16 ) & 0xff , V_4 + F_7 ( V_11 + 2 ) ) ;
} else {
F_6 ( F_8 ( V_10 ) , V_4 + V_20 ) ;
F_6 ( V_9 & 0xff , V_4 + F_9 ( 0 ) ) ;
F_6 ( ( V_9 >> 8 ) & 0xff , V_4 + F_9 ( 1 ) ) ;
F_6 ( ( V_9 >> 16 ) & 0xff , V_4 + F_9 ( 2 ) ) ;
}
F_10 ( & V_16 -> V_19 , V_18 ) ;
}
static unsigned int F_11 ( struct V_1 * V_2 ,
int V_3 , int V_10 , int V_11 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
unsigned long V_4 = F_1 ( V_2 , V_3 ) ;
unsigned long V_18 ;
unsigned int V_9 ;
F_5 ( & V_16 -> V_19 , V_18 ) ;
if ( V_10 == 0 ) {
V_9 = F_12 ( V_4 + F_7 ( V_11 + 0 ) ) ;
V_9 |= ( F_12 ( V_4 + F_7 ( V_11 + 1 ) ) << 8 ) ;
V_9 |= ( F_12 ( V_4 + F_7 ( V_11 + 2 ) ) << 16 ) ;
} else {
F_6 ( F_8 ( V_10 ) , V_4 + V_20 ) ;
V_9 = F_12 ( V_4 + F_9 ( 0 ) ) ;
V_9 |= ( F_12 ( V_4 + F_9 ( 1 ) ) << 8 ) ;
V_9 |= ( F_12 ( V_4 + F_9 ( 2 ) ) << 16 ) ;
}
F_10 ( & V_16 -> V_19 , V_18 ) ;
return V_9 ;
}
static int F_13 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_21 * V_22 ,
unsigned int * V_23 )
{
int V_3 = F_2 ( V_7 ) ;
int V_11 = F_3 ( V_7 ) ;
unsigned int V_24 = ( 1 << V_7 -> V_25 ) - 1 ;
unsigned int V_26 ;
unsigned int V_9 ;
V_26 = F_14 ( V_7 , V_23 ) ;
if ( V_26 ) {
V_9 = ~ V_7 -> V_27 & V_24 ;
V_9 &= V_7 -> V_28 ;
F_4 ( V_2 , V_9 , V_3 , 0 , V_11 ) ;
}
V_9 = F_11 ( V_2 , V_3 , 0 , V_11 ) ;
V_23 [ 1 ] = ~ V_9 & V_24 ;
return V_22 -> V_29 ;
}
static int F_15 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_21 * V_22 ,
unsigned int * V_23 )
{
int V_3 = F_2 ( V_7 ) ;
int V_11 = F_3 ( V_7 ) ;
int V_30 ;
V_30 = F_16 ( V_2 , V_7 , V_22 , V_23 , 0 ) ;
if ( V_30 )
return V_30 ;
if ( V_23 [ 0 ] == V_31 )
F_4 ( V_2 , V_7 -> V_28 , V_3 , 0 , V_11 ) ;
return V_22 -> V_29 ;
}
static void F_17 ( struct V_1 * V_2 )
{
const struct V_32 * V_33 = V_2 -> V_34 ;
int V_3 ;
for ( V_3 = 0 ; V_3 < V_33 -> V_35 ; ++ V_3 ) {
F_4 ( V_2 , 0 , V_3 , 0 , 0 ) ;
F_4 ( V_2 , 0 , V_3 , 0 , 3 ) ;
F_4 ( V_2 , 0 , V_3 , V_36 , 0 ) ;
F_4 ( V_2 , 0 , V_3 , V_37 , 0 ) ;
F_4 ( V_2 , 0 , V_3 , V_38 , 0 ) ;
}
}
static void F_18 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_3 = F_2 ( V_7 ) ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
V_16 -> V_39 = 0 ;
V_16 -> V_40 = 0 ;
V_7 -> V_41 -> V_42 = NULL ;
F_4 ( V_2 , 0 , V_3 , V_37 , 0 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
unsigned V_43 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_3 = F_2 ( V_7 ) ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
struct V_44 * V_45 = & V_7 -> V_41 -> V_45 ;
unsigned V_46 = V_7 -> V_41 -> V_47 ;
unsigned int V_9 = 0 ;
unsigned long V_18 ;
unsigned int V_48 ;
F_5 ( & V_16 -> V_49 , V_18 ) ;
if ( ! V_16 -> V_40 )
goto V_50;
if ( ! ( V_43 & V_16 -> V_39 ) )
goto V_50;
for ( V_48 = 0 ; V_48 < V_45 -> V_51 ; V_48 ++ ) {
unsigned int V_52 = F_20 ( V_45 -> V_53 [ V_48 ] ) ;
if ( V_43 & ( 1 << V_52 ) )
V_9 |= ( 1 << V_48 ) ;
}
if ( F_21 ( V_7 , V_9 ) &&
F_21 ( V_7 , V_9 >> 16 ) ) {
V_7 -> V_41 -> V_47 |= ( V_54 | V_55 ) ;
} else {
F_18 ( V_2 , V_7 ) ;
}
if ( V_45 -> V_56 == V_57 ) {
if ( V_16 -> V_58 > 0 ) {
V_16 -> V_58 -- ;
if ( V_16 -> V_58 == 0 ) {
V_7 -> V_41 -> V_47 |= V_59 ;
F_18 ( V_2 , V_7 ) ;
}
}
}
V_50:
F_10 ( & V_16 -> V_49 , V_18 ) ;
if ( V_46 != V_7 -> V_41 -> V_47 )
F_22 ( V_2 , V_7 ) ;
}
static int F_23 ( struct V_1 * V_2 , int V_3 )
{
struct V_6 * V_7 = & V_2 -> V_60 [ V_3 * 2 ] ;
unsigned long V_4 = F_1 ( V_2 , V_3 ) ;
unsigned int V_9 ;
V_9 = F_12 ( V_4 + V_61 ) & 0x07 ;
if ( ! V_9 )
return 0 ;
V_9 = F_11 ( V_2 , V_3 , V_38 , 0 ) ;
F_4 ( V_2 , 0 , V_3 , V_38 , 0 ) ;
F_19 ( V_2 , V_7 , V_9 ) ;
return 1 ;
}
static T_1 F_24 ( int V_62 , void * V_63 )
{
struct V_1 * V_2 = V_63 ;
struct V_12 * V_13 = V_2 -> V_14 ;
int V_64 = 0 ;
if ( V_62 == V_2 -> V_62 )
V_64 += F_23 ( V_2 , 0 ) ;
if ( V_62 == V_13 -> V_65 )
V_64 += F_23 ( V_2 , 1 ) ;
return V_64 ? V_66 : V_67 ;
}
static void F_25 ( struct V_1 * V_2 ,
struct V_6 * V_7 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_3 = F_2 ( V_7 ) ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
struct V_44 * V_45 = & V_7 -> V_41 -> V_45 ;
unsigned int V_68 = 0 ;
unsigned int V_69 = 0 ;
int V_48 ;
V_16 -> V_39 = 0 ;
V_16 -> V_40 = 1 ;
if ( V_45 -> V_53 ) {
for ( V_48 = 0 ; V_48 < V_45 -> V_51 ; V_48 ++ ) {
unsigned int V_70 = V_45 -> V_53 [ V_48 ] ;
unsigned int V_52 = F_20 ( V_70 ) ;
unsigned int V_71 = F_26 ( V_70 ) ;
unsigned int V_72 = F_27 ( V_70 ) ;
V_68 |= ( 1 << V_52 ) ;
V_69 |= ( ( V_72 || V_71 ) ? 1 : 0 ) << V_52 ;
}
}
V_68 &= ( ( 1 << V_7 -> V_25 ) - 1 ) ;
V_16 -> V_39 = V_68 ;
F_4 ( V_2 , V_69 , V_3 , V_36 , 0 ) ;
F_4 ( V_2 , V_68 , V_3 , V_37 , 0 ) ;
}
static int F_28 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
int V_3 = F_2 ( V_7 ) ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
unsigned long V_18 ;
F_5 ( & V_16 -> V_49 , V_18 ) ;
if ( V_16 -> V_40 )
F_18 ( V_2 , V_7 ) ;
F_10 ( & V_16 -> V_49 , V_18 ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
unsigned int V_73 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_44 * V_45 = & V_7 -> V_41 -> V_45 ;
int V_3 = F_2 ( V_7 ) ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
unsigned long V_18 ;
if ( V_73 != V_45 -> V_74 )
return - V_75 ;
F_5 ( & V_16 -> V_49 , V_18 ) ;
V_7 -> V_41 -> V_42 = NULL ;
if ( V_16 -> V_40 )
F_25 ( V_2 , V_7 ) ;
F_10 ( & V_16 -> V_49 , V_18 ) ;
return 1 ;
}
static int F_30 ( struct V_1 * V_2 , struct V_6 * V_7 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
struct V_44 * V_45 = & V_7 -> V_41 -> V_45 ;
int V_3 = F_2 ( V_7 ) ;
struct V_15 * V_16 = & V_13 -> V_17 [ V_3 ] ;
unsigned long V_18 ;
F_5 ( & V_16 -> V_49 , V_18 ) ;
V_16 -> V_40 = 1 ;
V_16 -> V_58 = V_45 -> V_76 ;
if ( V_45 -> V_77 == V_78 )
V_7 -> V_41 -> V_42 = F_29 ;
else
F_25 ( V_2 , V_7 ) ;
F_10 ( & V_16 -> V_49 , V_18 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_2 ,
struct V_6 * V_7 ,
struct V_44 * V_45 )
{
int V_79 = 0 ;
V_79 |= F_32 ( & V_45 -> V_77 , V_80 | V_78 ) ;
V_79 |= F_32 ( & V_45 -> V_81 , V_82 ) ;
V_79 |= F_32 ( & V_45 -> V_83 , V_80 ) ;
V_79 |= F_32 ( & V_45 -> V_84 , V_57 ) ;
V_79 |= F_32 ( & V_45 -> V_56 , V_57 | V_85 ) ;
if ( V_79 )
return 1 ;
V_79 |= F_33 ( V_45 -> V_77 ) ;
V_79 |= F_33 ( V_45 -> V_56 ) ;
if ( V_79 )
return 2 ;
V_79 |= F_34 ( & V_45 -> V_74 , 0 ) ;
V_79 |= F_34 ( & V_45 -> V_86 , 0 ) ;
V_79 |= F_34 ( & V_45 -> V_87 , 0 ) ;
V_79 |= F_34 ( & V_45 -> V_88 , V_45 -> V_51 ) ;
if ( V_45 -> V_56 == V_57 )
V_79 |= F_35 ( & V_45 -> V_76 , 1 ) ;
else
V_79 |= F_34 ( & V_45 -> V_76 , 0 ) ;
if ( V_79 )
return 3 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 , struct V_89 * V_90 )
{
const struct V_32 * V_33 = V_2 -> V_34 ;
struct V_6 * V_7 ;
struct V_12 * V_13 ;
int V_30 ;
int V_48 ;
V_30 = F_37 ( V_2 , V_90 -> V_91 [ 0 ] ,
V_33 -> V_35 * V_5 ) ;
if ( V_30 )
return V_30 ;
V_13 = F_38 ( V_2 , sizeof( * V_13 ) ) ;
if ( ! V_13 )
return - V_92 ;
for ( V_48 = 0 ; V_48 < V_93 ; ++ V_48 ) {
struct V_15 * V_16 = & V_13 -> V_17 [ V_48 ] ;
F_39 ( & V_16 -> V_19 ) ;
F_39 ( & V_16 -> V_49 ) ;
}
F_17 ( V_2 ) ;
if ( V_90 -> V_91 [ 1 ] ) {
V_30 = F_40 ( V_90 -> V_91 [ 1 ] , F_24 , 0 ,
V_2 -> V_94 , V_2 ) ;
if ( V_30 == 0 )
V_2 -> V_62 = V_90 -> V_91 [ 1 ] ;
}
if ( V_33 -> V_35 == 2 ) {
if ( V_90 -> V_91 [ 2 ] == V_2 -> V_62 ) {
V_13 -> V_65 = V_90 -> V_91 [ 2 ] ;
} else if ( V_90 -> V_91 [ 2 ] ) {
V_30 = F_40 ( V_90 -> V_91 [ 2 ] , F_24 , 0 ,
V_2 -> V_94 , V_2 ) ;
if ( V_30 == 0 )
V_13 -> V_65 = V_90 -> V_91 [ 2 ] ;
}
}
V_30 = F_41 ( V_2 , V_33 -> V_35 * 2 ) ;
if ( V_30 )
return V_30 ;
for ( V_48 = 0 ; V_48 < V_2 -> V_95 ; ++ V_48 ) {
V_7 = & V_2 -> V_60 [ V_48 ] ;
V_7 -> type = V_96 ;
V_7 -> V_97 = V_98 | V_99 ;
V_7 -> V_25 = 24 ;
V_7 -> V_100 = 1 ;
V_7 -> V_101 = & V_102 ;
V_7 -> V_103 = F_13 ;
V_7 -> V_104 = F_15 ;
if ( ( V_48 == 0 && V_2 -> V_62 ) || ( V_48 == 2 && V_13 -> V_65 ) ) {
V_2 -> V_105 = V_7 ;
V_7 -> V_97 |= V_106 ;
V_7 -> V_107 = V_7 -> V_25 ;
V_7 -> V_108 = F_28 ;
V_7 -> V_109 = F_30 ;
V_7 -> V_110 = F_31 ;
}
}
return 0 ;
}
static void F_42 ( struct V_1 * V_2 )
{
struct V_12 * V_13 = V_2 -> V_14 ;
if ( V_13 ) {
F_17 ( V_2 ) ;
if ( V_13 -> V_65 && V_13 -> V_65 != V_2 -> V_62 )
F_43 ( V_13 -> V_65 , V_2 ) ;
}
F_44 ( V_2 ) ;
}
