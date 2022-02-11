static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static inline int F_3 ( T_1 V_4 , T_1 V_5 )
{
return F_4 ( V_6 , V_5 , V_4 ) ;
}
static inline int F_5 ( T_1 V_4 )
{
T_1 V_5 ;
int V_7 = 0 ;
V_7 = F_6 ( V_6 , & V_5 , V_4 ) ;
return ( V_7 < 0 ) ? V_7 : V_5 ;
}
static void F_7 ( int V_8 , int V_9 )
{
T_1 V_10 = V_11 | V_12 ;
int V_13 ;
if ( V_8 )
V_10 <<= 1 ;
if ( V_9 )
V_14 &= ~ V_10 ;
else
V_14 |= V_10 ;
V_13 = F_4 ( V_15 , V_14 ,
V_16 ) ;
}
static int F_8 ( int V_17 , int V_18 )
{
T_1 V_19 = V_17 >> 3 ;
T_1 V_20 = F_9 ( V_17 & 0x7 ) ;
T_1 V_21 = 0 ;
T_1 V_22 = V_23 + V_19 ;
int V_7 = 0 ;
V_7 = F_5 ( V_22 ) ;
if ( V_7 >= 0 ) {
if ( V_18 )
V_21 = V_7 & ~ V_20 ;
else
V_21 = V_7 | V_20 ;
V_7 = F_3 ( V_22 , V_21 ) ;
}
return V_7 ;
}
static int F_10 ( int V_17 , int V_24 )
{
T_1 V_19 = V_17 >> 3 ;
T_1 V_20 = F_9 ( V_17 & 0x7 ) ;
T_1 V_22 = 0 ;
if ( V_24 )
V_22 = V_25 + V_19 ;
else
V_22 = V_26 + V_19 ;
return F_3 ( V_22 , V_20 ) ;
}
static int F_11 ( int V_17 )
{
T_1 V_19 = V_17 >> 3 ;
T_1 V_27 = V_17 & 0x7 ;
T_1 V_22 = 0 ;
int V_7 = 0 ;
V_22 = V_28 + V_19 ;
V_7 = F_5 ( V_22 ) ;
if ( V_7 > 0 )
V_7 = ( V_7 >> V_27 ) & 0x1 ;
return V_7 ;
}
static int F_12 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int V_13 = 0 ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 >= V_32 ) {
T_1 V_33 = V_11 | V_34
| V_12 | V_35 ;
T_1 V_21 = V_36 ;
V_29 -= V_32 ;
if ( V_29 ) {
V_33 <<= 1 ;
V_21 = V_37 ;
}
V_13 = F_4 ( V_15 , 0x7f , V_21 + 1 ) ;
if ( V_13 < 0 )
goto V_38;
V_13 = F_4 ( V_15 , 0x7f , V_21 ) ;
if ( V_13 < 0 )
goto V_38;
V_13 = F_6 ( V_15 , & V_14 ,
V_16 ) ;
if ( V_13 < 0 )
goto V_38;
V_14 &= ~ V_33 ;
V_13 = F_4 ( V_15 , V_14 ,
V_16 ) ;
if ( V_13 < 0 )
goto V_38;
V_13 = 0 ;
goto V_38;
}
if ( ! V_30 -> V_39 ) {
struct V_40 * V_41 ;
T_1 V_9 = V_42 ;
V_41 = V_3 -> V_43 -> V_44 ;
if ( V_41 )
V_9 |= V_41 -> V_45 & 0x03 ;
V_13 = F_3 ( V_46 , V_9 ) ;
}
V_38:
if ( ! V_13 )
V_30 -> V_39 |= F_9 ( V_29 ) ;
F_14 ( & V_30 -> V_31 ) ;
return V_13 ;
}
static void F_15 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 >= V_32 ) {
F_7 ( V_29 - V_32 , 1 ) ;
goto V_47;
}
V_30 -> V_39 &= ~ F_9 ( V_29 ) ;
if ( ! V_30 -> V_39 )
F_3 ( V_46 , 0x0 ) ;
V_47:
F_14 ( & V_30 -> V_31 ) ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int V_7 ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 < V_32 )
V_7 = F_8 ( V_29 , 1 ) ;
else
V_7 = - V_48 ;
if ( ! V_7 )
V_30 -> V_49 &= ~ F_9 ( V_29 ) ;
F_14 ( & V_30 -> V_31 ) ;
return V_7 ;
}
static int F_17 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int V_7 ;
int V_13 = 0 ;
F_13 ( & V_30 -> V_31 ) ;
if ( ! ( V_30 -> V_39 & F_9 ( V_29 ) ) ) {
V_7 = - V_50 ;
goto V_47;
}
if ( V_30 -> V_49 & F_9 ( V_29 ) )
V_13 = V_30 -> V_51 & F_9 ( V_29 ) ;
else
V_13 = F_11 ( V_29 ) ;
V_7 = ( V_13 <= 0 ) ? 0 : 1 ;
V_47:
F_14 ( & V_30 -> V_31 ) ;
return V_7 ;
}
static void F_18 ( struct V_2 * V_3 , unsigned V_29 , int V_9 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 < V_32 )
F_10 ( V_29 , V_9 ) ;
else
F_7 ( V_29 - V_32 , V_9 ) ;
if ( V_9 )
V_30 -> V_51 |= F_9 ( V_29 ) ;
else
V_30 -> V_51 &= ~ F_9 ( V_29 ) ;
F_14 ( & V_30 -> V_31 ) ;
}
static int F_19 ( struct V_2 * V_3 , unsigned V_29 , int V_9 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 < V_32 )
F_10 ( V_29 , V_9 ) ;
V_30 -> V_49 |= F_9 ( V_29 ) ;
F_14 ( & V_30 -> V_31 ) ;
F_18 ( V_3 , V_29 , V_9 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
return ( V_30 -> V_52 && ( V_29 < V_32 ) )
? ( V_30 -> V_52 + V_29 )
: - V_48 ;
}
static int F_21 ( T_2 V_53 , T_2 V_54 )
{
T_1 V_55 [ 5 ] ;
unsigned V_56 , V_57 ;
for ( V_57 = 1 , V_56 = 0 ; V_56 < 5 ; V_56 ++ ) {
T_1 V_58 ;
unsigned V_59 ;
for ( V_58 = 0 , V_59 = 0 ; V_59 < 8 ; V_59 += 2 , V_57 <<= 1 ) {
if ( V_53 & V_57 )
V_58 |= 1 << ( V_59 + 1 ) ;
else if ( V_54 & V_57 )
V_58 |= 1 << ( V_59 + 0 ) ;
}
V_55 [ V_56 ] = V_58 ;
}
return F_22 ( V_6 , V_55 ,
V_60 , 5 ) ;
}
static int F_23 ( T_2 V_61 , T_1 V_45 )
{
T_1 V_55 [ 3 ] ;
V_55 [ 0 ] = ( V_61 & 0xff ) | ( V_45 & 0x03 ) ;
V_61 >>= 8 ;
V_55 [ 1 ] = ( V_61 & 0xff ) ;
V_61 >>= 8 ;
V_55 [ 2 ] = ( V_61 & 0x03 ) ;
return F_22 ( V_6 , V_55 ,
V_62 , 3 ) ;
}
static struct V_40 * F_24 ( struct V_63 * V_43 )
{
struct V_40 * V_64 ;
V_64 = F_25 ( V_43 , sizeof( * V_64 ) , V_65 ) ;
if ( ! V_64 )
return NULL ;
V_64 -> V_66 = F_26 ( V_43 -> V_67 ,
L_1 ) ;
F_27 ( V_43 -> V_67 , L_2 ,
& V_64 -> V_61 ) ;
F_27 ( V_43 -> V_67 , L_3 ,
( T_2 * ) & V_64 -> V_45 ) ;
F_27 ( V_43 -> V_67 , L_4 ,
& V_64 -> V_68 ) ;
F_27 ( V_43 -> V_67 , L_5 ,
& V_64 -> V_69 ) ;
return V_64 ;
}
static int F_28 ( struct V_70 * V_71 )
{
struct V_40 * V_41 = V_71 -> V_43 . V_44 ;
struct V_72 * V_73 = V_71 -> V_43 . V_67 ;
struct V_1 * V_30 ;
int V_7 , V_52 ;
V_30 = F_25 ( & V_71 -> V_43 , sizeof( struct V_1 ) ,
V_65 ) ;
if ( ! V_30 )
return - V_74 ;
if ( F_29 () ) {
F_30 ( & V_71 -> V_43 , L_6 ) ;
goto V_75;
}
V_52 = F_31 ( - 1 , 0 , V_32 , 0 ) ;
if ( V_52 < 0 ) {
F_30 ( & V_71 -> V_43 , L_7 ) ;
return V_52 ;
}
F_32 ( V_73 , V_32 , V_52 , 0 ,
& V_76 , NULL ) ;
V_7 = F_33 ( & V_71 -> V_43 , V_6 , V_52 ) ;
if ( V_7 < 0 )
return V_7 ;
V_30 -> V_52 = V_52 ;
V_75:
V_30 -> V_2 = V_77 ;
V_30 -> V_2 . V_22 = - 1 ;
V_30 -> V_2 . V_78 = V_32 ;
V_30 -> V_2 . V_43 = & V_71 -> V_43 ;
F_34 ( & V_30 -> V_31 ) ;
if ( V_73 )
V_41 = F_24 ( & V_71 -> V_43 ) ;
if ( V_41 == NULL ) {
F_30 ( & V_71 -> V_43 , L_8 ) ;
return - V_79 ;
}
V_7 = F_21 ( V_41 -> V_68 , V_41 -> V_69 ) ;
if ( V_7 )
F_35 ( & V_71 -> V_43 , L_9 ,
V_41 -> V_68 , V_41 -> V_69 , V_7 ) ;
V_7 = F_23 ( V_41 -> V_61 , V_41 -> V_45 ) ;
if ( V_7 )
F_35 ( & V_71 -> V_43 , L_10 ,
V_41 -> V_61 , V_41 -> V_45 , V_7 ) ;
if ( V_41 -> V_66 )
V_30 -> V_2 . V_78 += 2 ;
V_7 = F_36 ( & V_30 -> V_2 ) ;
if ( V_7 < 0 ) {
F_30 ( & V_71 -> V_43 , L_11 , V_7 ) ;
V_30 -> V_2 . V_78 = 0 ;
F_37 ( V_71 ) ;
goto V_47;
}
F_38 ( V_71 , V_30 ) ;
if ( V_41 && V_41 -> V_80 ) {
int V_13 ;
V_13 = V_41 -> V_80 ( & V_71 -> V_43 , V_30 -> V_2 . V_22 ,
V_32 ) ;
if ( V_13 )
F_35 ( & V_71 -> V_43 , L_12 , V_13 ) ;
}
V_47:
return V_7 ;
}
static int F_37 ( struct V_70 * V_71 )
{
struct V_40 * V_41 = V_71 -> V_43 . V_44 ;
struct V_1 * V_30 = F_39 ( V_71 ) ;
int V_13 ;
if ( V_41 && V_41 -> V_81 ) {
V_13 = V_41 -> V_81 ( & V_71 -> V_43 , V_30 -> V_2 . V_22 ,
V_32 ) ;
if ( V_13 ) {
F_35 ( & V_71 -> V_43 , L_13 , V_13 ) ;
return V_13 ;
}
}
V_13 = F_40 ( & V_30 -> V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( F_29 () )
return 0 ;
F_41 ( 1 ) ;
return - V_82 ;
}
static int T_3 F_42 ( void )
{
return F_43 ( & V_83 ) ;
}
static void T_4 F_44 ( void )
{
F_45 ( & V_83 ) ;
}
