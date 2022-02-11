void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_4 )
{
if ( V_3 == 0 )
return;
if ( V_3 >= V_5 ) {
F_2 ( 0 , V_2 -> V_6 + V_7 ) ;
F_2 ( 0 , V_2 -> V_6 + V_8 ) ;
F_2 ( F_3 ( V_9 - V_3 ) |
F_4 ( V_9 - V_3 ) |
V_10 ,
V_2 -> V_6 + V_11 ) ;
F_2 ( F_5 ( V_9 - V_3 ) |
F_6 ( V_9 - V_3 ) |
F_7 ( V_9 - V_3 ) |
F_8 ( V_9 - V_3 ) ,
V_2 -> V_6 + V_12 ) ;
F_2 ( V_13 , V_2 -> V_6 + V_4 ) ;
}
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_3 )
{
F_2 ( V_14 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_15 , V_2 -> V_6 + V_18 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( V_19 | V_20 ,
V_2 -> V_6 + V_21 ) ;
F_2 ( 0x1 , V_2 -> V_6 + V_22 ) ;
}
static void F_11 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_3 )
{
F_2 ( V_14 << 16 | V_15 , V_2 -> V_6 + V_23 ) ;
F_2 ( V_24 , V_2 -> V_6 + V_25 ) ;
F_1 ( V_2 , V_3 , V_25 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_2 -> V_6 + V_26 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_27 , V_2 -> V_6 + V_28 ) ;
}
static void F_14 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_3 )
{
F_2 ( V_15 << 16 | V_14 , V_2 -> V_6 + V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
F_2 ( V_30 , V_2 -> V_6 + V_31 ) ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_17 ( 0x0 , V_2 -> V_6 + V_31 ) ;
}
static void F_18 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_3 )
{
F_2 ( V_15 << 16 | V_14 , V_2 -> V_6 + V_32 ) ;
F_1 ( V_2 , V_3 , V_33 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
F_2 ( V_34 , V_2 -> V_6 + V_35 ) ;
}
static void F_20 ( struct V_1 * V_2 )
{
F_17 ( 0x0 , V_2 -> V_6 + V_35 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_36 * V_37 )
{
unsigned int V_38 , V_39 ;
struct V_40 * V_41 ;
void T_1 * V_42 ;
T_2 V_43 ;
if ( V_37 -> V_44 ) {
V_39 = F_22 ( V_2 -> V_6 + V_33 ) ;
V_39 = V_39 | V_45 ;
F_2 ( V_39 , V_2 -> V_6 + V_33 ) ;
V_42 = V_2 -> V_6 + V_46 ;
V_41 = (struct V_40 * ) V_37 -> V_44 -> V_47 ;
for ( V_38 = 0 ; V_38 < V_48 ; V_38 ++ ) {
V_43 = ( ( ( V_41 [ V_38 ] . V_49 >> 6 ) & V_50 ) << 20 ) +
( ( ( V_41 [ V_38 ] . V_51 >> 6 ) & V_50 ) << 10 ) +
( ( V_41 [ V_38 ] . V_52 >> 6 ) & V_50 ) ;
F_2 ( V_43 , ( V_42 + V_38 * 4 ) ) ;
}
}
}
int F_23 ( struct V_53 * V_54 ,
enum V_55 V_56 )
{
int V_57 = F_24 ( V_54 , V_58 [ V_56 ] ) ;
int V_38 ;
for ( V_38 = 0 ; V_38 < F_25 ( V_59 ) ; V_38 ++ ) {
if ( V_56 == V_59 [ V_38 ] . type &&
( V_57 < 0 || V_57 == V_59 [ V_38 ] . V_60 ) )
return V_38 ;
}
return - V_61 ;
}
int F_26 ( struct V_62 * V_63 , struct V_53 * V_54 ,
struct V_1 * V_2 , enum V_64 V_65 ,
const struct V_66 * V_67 )
{
enum V_55 type ;
struct V_53 * V_68 ;
struct V_69 * V_70 ;
if ( V_65 < 0 || V_65 >= V_71 )
return - V_61 ;
V_2 -> V_57 = V_65 ;
V_2 -> V_67 = V_67 ? : V_59 [ V_65 ] . V_67 ;
if ( V_65 == V_72 ||
V_65 == V_73 ||
V_65 == V_74 ) {
V_2 -> V_6 = NULL ;
V_2 -> V_75 = NULL ;
V_2 -> V_76 = 0 ;
return 0 ;
}
V_2 -> V_6 = F_27 ( V_54 , 0 ) ;
V_2 -> V_76 = F_28 ( V_54 , 0 ) ;
V_2 -> V_75 = F_29 ( V_54 , 0 ) ;
if ( F_30 ( V_2 -> V_75 ) )
V_2 -> V_75 = NULL ;
type = V_59 [ V_65 ] . type ;
V_2 -> V_77 = NULL ;
if ( type != V_78 &&
type != V_79 &&
type != V_80 )
return 0 ;
V_68 = F_31 ( V_54 , L_1 , 0 ) ;
if ( ! V_68 ) {
F_32 ( V_63 ,
L_2 ,
V_54 -> V_81 ) ;
return - V_61 ;
}
V_70 = F_33 ( V_68 ) ;
if ( ! V_70 ) {
F_34 ( V_63 , L_3 ,
V_68 -> V_81 ) ;
F_35 ( V_68 ) ;
return - V_82 ;
}
F_35 ( V_68 ) ;
V_2 -> V_77 = & V_70 -> V_63 ;
return 0 ;
}
int F_36 ( struct V_83 * V_84 , struct V_1 * V_2 )
{
struct V_85 * V_86 = V_84 -> V_87 ;
if ( V_86 -> V_88 [ V_2 -> V_57 ] )
return - V_89 ;
V_86 -> V_88 [ V_2 -> V_57 ] = V_2 ;
return 0 ;
}
void F_37 ( struct V_83 * V_84 , struct V_1 * V_2 )
{
struct V_85 * V_86 = V_84 -> V_87 ;
V_86 -> V_88 [ V_2 -> V_57 ] = NULL ;
}
