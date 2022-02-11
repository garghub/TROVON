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
F_2 ( V_14 << 16 | V_15 , V_2 -> V_6 + V_17 ) ;
F_2 ( V_18 , V_2 -> V_6 + V_19 ) ;
F_1 ( V_2 , V_3 , V_19 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_2 ( 1 , V_2 -> V_6 + V_20 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_2 ( V_21 , V_2 -> V_6 + V_22 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_3 )
{
F_2 ( V_15 << 16 | V_14 , V_2 -> V_6 + V_23 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_2 ( V_24 , V_2 -> V_6 + V_25 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_15 ( 0x0 , V_2 -> V_6 + V_25 ) ;
}
static void F_16 ( struct V_1 * V_2 , unsigned int V_14 ,
unsigned int V_15 , unsigned int V_16 ,
unsigned int V_3 )
{
F_2 ( V_15 << 16 | V_14 , V_2 -> V_6 + V_26 ) ;
F_1 ( V_2 , V_3 , V_27 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_2 ( V_28 , V_2 -> V_6 + V_29 ) ;
}
static void F_18 ( struct V_1 * V_2 )
{
F_15 ( 0x0 , V_2 -> V_6 + V_29 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
struct V_30 * V_31 )
{
unsigned int V_32 , V_33 ;
struct V_34 * V_35 ;
void T_1 * V_36 ;
T_2 V_37 ;
if ( V_31 -> V_38 ) {
V_33 = F_20 ( V_2 -> V_6 + V_27 ) ;
V_33 = V_33 | V_39 ;
F_2 ( V_33 , V_2 -> V_6 + V_27 ) ;
V_36 = V_2 -> V_6 + V_40 ;
V_35 = (struct V_34 * ) V_31 -> V_38 -> V_41 ;
for ( V_32 = 0 ; V_32 < V_42 ; V_32 ++ ) {
V_37 = ( ( ( V_35 [ V_32 ] . V_43 >> 6 ) & V_44 ) << 20 ) +
( ( ( V_35 [ V_32 ] . V_45 >> 6 ) & V_44 ) << 10 ) +
( ( V_35 [ V_32 ] . V_46 >> 6 ) & V_44 ) ;
F_2 ( V_37 , ( V_36 + V_32 * 4 ) ) ;
}
}
}
int F_21 ( struct V_47 * V_48 ,
enum V_49 V_50 )
{
int V_51 = F_22 ( V_48 , V_52 [ V_50 ] ) ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_23 ( V_53 ) ; V_32 ++ ) {
if ( V_50 == V_53 [ V_32 ] . type &&
( V_51 < 0 || V_51 == V_53 [ V_32 ] . V_54 ) )
return V_32 ;
}
return - V_55 ;
}
int F_24 ( struct V_56 * V_57 , struct V_47 * V_48 ,
struct V_1 * V_2 , enum V_58 V_59 ,
const struct V_60 * V_61 )
{
enum V_49 type ;
struct V_47 * V_62 ;
struct V_63 * V_64 ;
if ( V_59 < 0 || V_59 >= V_65 )
return - V_55 ;
type = V_53 [ V_59 ] . type ;
V_2 -> V_51 = V_59 ;
V_2 -> V_61 = V_61 ? : V_53 [ V_59 ] . V_61 ;
if ( V_59 == V_66 ||
V_59 == V_67 ||
V_59 == V_68 ||
V_59 == V_69 ) {
V_2 -> V_6 = NULL ;
V_2 -> V_70 = NULL ;
V_2 -> V_71 = 0 ;
return 0 ;
}
V_2 -> V_6 = F_25 ( V_48 , 0 ) ;
V_2 -> V_71 = F_26 ( V_48 , 0 ) ;
V_2 -> V_70 = F_27 ( V_48 , 0 ) ;
if ( F_28 ( V_2 -> V_70 ) )
V_2 -> V_70 = NULL ;
V_2 -> V_72 = NULL ;
if ( type != V_73 &&
type != V_74 &&
type != V_75 )
return 0 ;
V_62 = F_29 ( V_48 , L_1 , 0 ) ;
if ( ! V_62 ) {
F_30 ( V_57 ,
L_2 , V_48 ) ;
return - V_55 ;
}
V_64 = F_31 ( V_62 ) ;
if ( ! V_64 ) {
F_32 ( V_57 , L_3 , V_62 ) ;
F_33 ( V_62 ) ;
return - V_76 ;
}
F_33 ( V_62 ) ;
V_2 -> V_72 = & V_64 -> V_57 ;
return 0 ;
}
int F_34 ( struct V_77 * V_78 , struct V_1 * V_2 )
{
struct V_79 * V_80 = V_78 -> V_81 ;
if ( V_80 -> V_82 [ V_2 -> V_51 ] )
return - V_83 ;
V_80 -> V_82 [ V_2 -> V_51 ] = V_2 ;
return 0 ;
}
void F_35 ( struct V_77 * V_78 , struct V_1 * V_2 )
{
struct V_79 * V_80 = V_78 -> V_81 ;
V_80 -> V_82 [ V_2 -> V_51 ] = NULL ;
}
