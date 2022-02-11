static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
void F_3 ( struct V_2 * V_3 , unsigned int V_5 ,
unsigned int V_6 )
{
if ( V_5 == 0 )
return;
if ( V_5 >= V_7 ) {
F_4 ( 0 , V_3 -> V_8 + V_9 ) ;
F_4 ( 0 , V_3 -> V_8 + V_10 ) ;
F_4 ( F_5 ( V_11 - V_5 ) |
F_6 ( V_11 - V_5 ) |
V_12 ,
V_3 -> V_8 + V_13 ) ;
F_4 ( F_7 ( V_11 - V_5 ) |
F_8 ( V_11 - V_5 ) |
F_9 ( V_11 - V_5 ) |
F_10 ( V_11 - V_5 ) ,
V_3 -> V_8 + V_14 ) ;
F_4 ( V_15 , V_3 -> V_8 + V_6 ) ;
}
}
static void F_11 ( struct V_2 * V_3 , unsigned int V_16 ,
unsigned int V_17 , unsigned int V_18 ,
unsigned int V_5 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_4 ( V_16 , V_3 -> V_8 + F_12 ( V_19 ) ) ;
F_4 ( V_17 , V_3 -> V_8 + F_13 ( V_19 ) ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_19 = F_1 ( V_3 ) ;
F_4 ( V_20 | V_21 ,
V_3 -> V_8 + V_22 ) ;
F_4 ( 0x1 , V_3 -> V_8 + F_15 ( V_19 ) ) ;
}
static void F_16 ( struct V_2 * V_3 , unsigned int V_16 ,
unsigned int V_17 , unsigned int V_18 ,
unsigned int V_5 )
{
F_4 ( V_16 << 16 | V_17 , V_3 -> V_8 + V_23 ) ;
F_4 ( V_24 , V_3 -> V_8 + V_25 ) ;
F_3 ( V_3 , V_5 , V_25 ) ;
}
static void F_17 ( struct V_2 * V_3 )
{
F_4 ( 1 , V_3 -> V_8 + V_26 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
F_4 ( V_27 , V_3 -> V_8 + V_28 ) ;
}
static void F_19 ( struct V_2 * V_3 , unsigned int V_16 ,
unsigned int V_17 , unsigned int V_18 ,
unsigned int V_5 )
{
F_4 ( V_17 << 16 | V_16 , V_3 -> V_8 + V_29 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
F_4 ( V_30 , V_3 -> V_8 + V_31 ) ;
}
static void F_21 ( struct V_2 * V_3 )
{
F_22 ( 0x0 , V_3 -> V_8 + V_31 ) ;
}
static void F_23 ( struct V_2 * V_3 , unsigned int V_16 ,
unsigned int V_17 , unsigned int V_18 ,
unsigned int V_5 )
{
F_4 ( V_17 << 16 | V_16 , V_3 -> V_8 + V_32 ) ;
F_3 ( V_3 , V_5 , V_33 ) ;
}
static void F_24 ( struct V_2 * V_3 )
{
F_4 ( V_34 , V_3 -> V_8 + V_35 ) ;
}
static void F_25 ( struct V_2 * V_3 )
{
F_22 ( 0x0 , V_3 -> V_8 + V_35 ) ;
}
static void F_26 ( struct V_2 * V_3 ,
struct V_36 * V_37 )
{
unsigned int V_38 , V_39 ;
struct V_40 * V_41 ;
void T_1 * V_42 ;
T_2 V_43 ;
if ( V_37 -> V_44 ) {
V_39 = F_27 ( V_3 -> V_8 + V_33 ) ;
V_39 = V_39 | V_45 ;
F_4 ( V_39 , V_3 -> V_8 + V_33 ) ;
V_42 = V_3 -> V_8 + V_46 ;
V_41 = (struct V_40 * ) V_37 -> V_44 -> V_47 ;
for ( V_38 = 0 ; V_38 < V_48 ; V_38 ++ ) {
V_43 = ( ( ( V_41 [ V_38 ] . V_49 >> 6 ) & V_50 ) << 20 ) +
( ( ( V_41 [ V_38 ] . V_51 >> 6 ) & V_50 ) << 10 ) +
( ( V_41 [ V_38 ] . V_52 >> 6 ) & V_50 ) ;
F_4 ( V_43 , ( V_42 + V_38 * 4 ) ) ;
}
}
}
int F_28 ( struct V_53 * V_54 ,
enum V_55 V_56 )
{
int V_57 = F_29 ( V_54 , V_58 [ V_56 ] ) ;
int V_38 ;
for ( V_38 = 0 ; V_38 < F_30 ( V_59 ) ; V_38 ++ ) {
if ( V_56 == V_59 [ V_38 ] . type &&
( V_57 < 0 || V_57 == V_59 [ V_38 ] . V_60 ) )
return V_38 ;
}
return - V_61 ;
}
int F_31 ( struct V_62 * V_63 , struct V_53 * V_54 ,
struct V_2 * V_3 , enum V_64 V_65 ,
const struct V_66 * V_67 )
{
enum V_55 type ;
struct V_53 * V_68 ;
struct V_69 * V_70 ;
const struct V_71 * V_72 ;
struct V_1 * V_19 ;
if ( V_65 < 0 || V_65 >= V_73 )
return - V_61 ;
type = V_59 [ V_65 ] . type ;
if ( type == V_74 ) {
F_32 ( V_63 , V_3 ) ;
V_19 = F_33 ( V_63 , sizeof( * V_19 ) , V_75 ) ;
if ( ! V_19 )
return - V_76 ;
V_72 = F_34 ( V_77 , V_54 ) ;
V_19 -> V_47 = V_72 -> V_47 ;
V_3 = & V_19 -> V_4 ;
}
V_3 -> V_57 = V_65 ;
V_3 -> V_67 = V_67 ? : V_59 [ V_65 ] . V_67 ;
if ( V_65 == V_78 ||
V_65 == V_79 ||
V_65 == V_80 ||
V_65 == V_81 ) {
V_3 -> V_8 = NULL ;
V_3 -> V_82 = NULL ;
V_3 -> V_83 = 0 ;
return 0 ;
}
V_3 -> V_8 = F_35 ( V_54 , 0 ) ;
V_3 -> V_83 = F_36 ( V_54 , 0 ) ;
V_3 -> V_82 = F_37 ( V_54 , 0 ) ;
if ( F_38 ( V_3 -> V_82 ) )
V_3 -> V_82 = NULL ;
V_3 -> V_84 = NULL ;
if ( type != V_85 &&
type != V_86 &&
type != V_87 )
return 0 ;
V_68 = F_39 ( V_54 , L_1 , 0 ) ;
if ( ! V_68 ) {
F_40 ( V_63 ,
L_2 ,
V_54 -> V_88 ) ;
return - V_61 ;
}
V_70 = F_41 ( V_68 ) ;
if ( ! V_70 ) {
F_42 ( V_63 , L_3 ,
V_68 -> V_88 ) ;
F_43 ( V_68 ) ;
return - V_89 ;
}
F_43 ( V_68 ) ;
V_3 -> V_84 = & V_70 -> V_63 ;
return 0 ;
}
int F_44 ( struct V_90 * V_91 , struct V_2 * V_3 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
if ( V_93 -> V_4 [ V_3 -> V_57 ] )
return - V_95 ;
V_93 -> V_4 [ V_3 -> V_57 ] = V_3 ;
return 0 ;
}
void F_45 ( struct V_90 * V_91 , struct V_2 * V_3 )
{
struct V_92 * V_93 = V_91 -> V_94 ;
V_93 -> V_4 [ V_3 -> V_57 ] = NULL ;
}
