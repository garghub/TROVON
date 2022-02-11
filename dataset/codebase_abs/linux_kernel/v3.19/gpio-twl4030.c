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
if ( V_8 )
V_10 <<= 1 ;
if ( V_9 )
V_13 &= ~ V_10 ;
else
V_13 |= V_10 ;
F_8 ( F_4 ( V_14 , V_13 ,
V_15 ) ) ;
}
static int F_9 ( int V_16 , int V_17 )
{
T_1 V_18 = V_16 >> 3 ;
T_1 V_19 = F_10 ( V_16 & 0x7 ) ;
T_1 V_20 = 0 ;
T_1 V_21 = V_22 + V_18 ;
int V_7 = 0 ;
V_7 = F_5 ( V_21 ) ;
if ( V_7 >= 0 ) {
if ( V_17 )
V_20 = V_7 & ~ V_19 ;
else
V_20 = V_7 | V_19 ;
V_7 = F_3 ( V_21 , V_20 ) ;
}
return V_7 ;
}
static int F_11 ( int V_16 , int V_23 )
{
T_1 V_18 = V_16 >> 3 ;
T_1 V_19 = F_10 ( V_16 & 0x7 ) ;
T_1 V_21 = 0 ;
if ( V_23 )
V_21 = V_24 + V_18 ;
else
V_21 = V_25 + V_18 ;
return F_3 ( V_21 , V_19 ) ;
}
static int F_12 ( int V_16 )
{
T_1 V_18 = V_16 >> 3 ;
T_1 V_26 = V_16 & 0x7 ;
T_1 V_21 = 0 ;
int V_7 = 0 ;
V_21 = V_27 + V_18 ;
V_7 = F_5 ( V_21 ) ;
if ( V_7 > 0 )
V_7 = ( V_7 >> V_26 ) & 0x1 ;
return V_7 ;
}
static int F_13 ( struct V_2 * V_3 , unsigned V_28 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
int V_30 = 0 ;
F_14 ( & V_29 -> V_31 ) ;
if ( V_28 >= V_32 ) {
T_1 V_33 = V_11 | V_34
| V_12 | V_35 ;
T_1 V_20 = V_36 ;
V_28 -= V_32 ;
if ( V_28 ) {
V_33 <<= 1 ;
V_20 = V_37 ;
}
V_30 = F_4 ( V_14 , 0x7f , V_20 + 1 ) ;
if ( V_30 < 0 )
goto V_38;
V_30 = F_4 ( V_14 , 0x7f , V_20 ) ;
if ( V_30 < 0 )
goto V_38;
V_30 = F_6 ( V_14 , & V_13 ,
V_15 ) ;
if ( V_30 < 0 )
goto V_38;
V_13 &= ~ V_33 ;
V_30 = F_4 ( V_14 , V_13 ,
V_15 ) ;
if ( V_30 < 0 )
goto V_38;
V_30 = 0 ;
goto V_38;
}
if ( ! V_29 -> V_39 ) {
struct V_40 * V_41 ;
T_1 V_9 = V_42 ;
V_41 = F_15 ( V_3 -> V_43 ) ;
if ( V_41 )
V_9 |= V_41 -> V_44 & 0x03 ;
V_30 = F_3 ( V_45 , V_9 ) ;
}
V_38:
if ( ! V_30 )
V_29 -> V_39 |= F_10 ( V_28 ) ;
F_16 ( & V_29 -> V_31 ) ;
return V_30 ;
}
static void F_17 ( struct V_2 * V_3 , unsigned V_28 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
F_14 ( & V_29 -> V_31 ) ;
if ( V_28 >= V_32 ) {
F_7 ( V_28 - V_32 , 1 ) ;
goto V_46;
}
V_29 -> V_39 &= ~ F_10 ( V_28 ) ;
if ( ! V_29 -> V_39 )
F_3 ( V_45 , 0x0 ) ;
V_46:
F_16 ( & V_29 -> V_31 ) ;
}
static int F_18 ( struct V_2 * V_3 , unsigned V_28 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
int V_7 ;
F_14 ( & V_29 -> V_31 ) ;
if ( V_28 < V_32 )
V_7 = F_9 ( V_28 , 1 ) ;
else
V_7 = - V_47 ;
if ( ! V_7 )
V_29 -> V_48 &= ~ F_10 ( V_28 ) ;
F_16 ( & V_29 -> V_31 ) ;
return V_7 ;
}
static int F_19 ( struct V_2 * V_3 , unsigned V_28 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
int V_7 ;
int V_30 = 0 ;
F_14 ( & V_29 -> V_31 ) ;
if ( ! ( V_29 -> V_39 & F_10 ( V_28 ) ) ) {
V_7 = - V_49 ;
goto V_46;
}
if ( V_29 -> V_48 & F_10 ( V_28 ) )
V_30 = V_29 -> V_50 & F_10 ( V_28 ) ;
else
V_30 = F_12 ( V_28 ) ;
V_7 = ( V_30 <= 0 ) ? 0 : 1 ;
V_46:
F_16 ( & V_29 -> V_31 ) ;
return V_7 ;
}
static void F_20 ( struct V_2 * V_3 , unsigned V_28 , int V_9 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
F_14 ( & V_29 -> V_31 ) ;
if ( V_28 < V_32 )
F_11 ( V_28 , V_9 ) ;
else
F_7 ( V_28 - V_32 , V_9 ) ;
if ( V_9 )
V_29 -> V_50 |= F_10 ( V_28 ) ;
else
V_29 -> V_50 &= ~ F_10 ( V_28 ) ;
F_16 ( & V_29 -> V_31 ) ;
}
static int F_21 ( struct V_2 * V_3 , unsigned V_28 , int V_9 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
int V_7 = 0 ;
F_14 ( & V_29 -> V_31 ) ;
if ( V_28 < V_32 ) {
V_7 = F_9 ( V_28 , 0 ) ;
if ( V_7 ) {
F_16 ( & V_29 -> V_31 ) ;
return V_7 ;
}
}
V_29 -> V_48 |= F_10 ( V_28 ) ;
F_16 ( & V_29 -> V_31 ) ;
F_20 ( V_3 , V_28 , V_9 ) ;
return V_7 ;
}
static int F_22 ( struct V_2 * V_3 , unsigned V_28 )
{
struct V_1 * V_29 = F_1 ( V_3 ) ;
return ( V_29 -> V_51 && ( V_28 < V_32 ) )
? ( V_29 -> V_51 + V_28 )
: - V_47 ;
}
static int F_23 ( T_2 V_52 , T_2 V_53 )
{
T_1 V_54 [ 5 ] ;
unsigned V_55 , V_56 ;
for ( V_56 = 1 , V_55 = 0 ; V_55 < 5 ; V_55 ++ ) {
T_1 V_57 ;
unsigned V_58 ;
for ( V_57 = 0 , V_58 = 0 ; V_58 < 8 ; V_58 += 2 , V_56 <<= 1 ) {
if ( V_52 & V_56 )
V_57 |= 1 << ( V_58 + 1 ) ;
else if ( V_53 & V_56 )
V_57 |= 1 << ( V_58 + 0 ) ;
}
V_54 [ V_55 ] = V_57 ;
}
return F_24 ( V_6 , V_54 ,
V_59 , 5 ) ;
}
static int F_25 ( T_2 V_60 , T_1 V_44 )
{
T_1 V_54 [ 3 ] ;
V_54 [ 0 ] = ( V_60 & 0xff ) | ( V_44 & 0x03 ) ;
V_60 >>= 8 ;
V_54 [ 1 ] = ( V_60 & 0xff ) ;
V_60 >>= 8 ;
V_54 [ 2 ] = ( V_60 & 0x03 ) ;
return F_24 ( V_6 , V_54 ,
V_61 , 3 ) ;
}
static struct V_40 * F_26 ( struct V_62 * V_43 ,
struct V_40 * V_41 )
{
struct V_40 * V_63 ;
V_63 = F_27 ( V_43 , sizeof( * V_63 ) , V_64 ) ;
if ( ! V_63 )
return NULL ;
if ( V_41 )
* V_63 = * V_41 ;
V_63 -> V_65 = F_28 ( V_43 -> V_66 ,
L_1 ) ;
F_29 ( V_43 -> V_66 , L_2 ,
& V_63 -> V_60 ) ;
F_29 ( V_43 -> V_66 , L_3 ,
( T_2 * ) & V_63 -> V_44 ) ;
F_29 ( V_43 -> V_66 , L_4 ,
& V_63 -> V_67 ) ;
F_29 ( V_43 -> V_66 , L_5 ,
& V_63 -> V_68 ) ;
return V_63 ;
}
static int F_30 ( struct V_69 * V_70 )
{
struct V_40 * V_41 = F_15 ( & V_70 -> V_43 ) ;
struct V_71 * V_72 = V_70 -> V_43 . V_66 ;
struct V_1 * V_29 ;
int V_7 , V_51 ;
V_29 = F_27 ( & V_70 -> V_43 , sizeof( struct V_1 ) ,
V_64 ) ;
if ( ! V_29 )
return - V_73 ;
if ( F_31 () ) {
F_32 ( & V_70 -> V_43 , L_6 ) ;
goto V_74;
}
V_51 = F_33 ( - 1 , 0 , V_32 , 0 ) ;
if ( V_51 < 0 ) {
F_32 ( & V_70 -> V_43 , L_7 ) ;
return V_51 ;
}
F_34 ( V_72 , V_32 , V_51 , 0 ,
& V_75 , NULL ) ;
V_7 = F_35 ( & V_70 -> V_43 , V_6 , V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_29 -> V_51 = V_51 ;
V_74:
V_29 -> V_2 = V_76 ;
V_29 -> V_2 . V_21 = - 1 ;
V_29 -> V_2 . V_77 = V_32 ;
V_29 -> V_2 . V_43 = & V_70 -> V_43 ;
F_36 ( & V_29 -> V_31 ) ;
if ( V_72 )
V_41 = F_26 ( & V_70 -> V_43 , V_41 ) ;
if ( V_41 == NULL ) {
F_32 ( & V_70 -> V_43 , L_8 ) ;
return - V_78 ;
}
V_7 = F_23 ( V_41 -> V_67 , V_41 -> V_68 ) ;
if ( V_7 )
F_37 ( & V_70 -> V_43 , L_9 ,
V_41 -> V_67 , V_41 -> V_68 , V_7 ) ;
V_7 = F_25 ( V_41 -> V_60 , V_41 -> V_44 ) ;
if ( V_7 )
F_37 ( & V_70 -> V_43 , L_10 ,
V_41 -> V_60 , V_41 -> V_44 , V_7 ) ;
if ( V_41 -> V_65 )
V_29 -> V_2 . V_77 += 2 ;
V_7 = F_38 ( & V_29 -> V_2 ) ;
if ( V_7 < 0 ) {
F_32 ( & V_70 -> V_43 , L_11 , V_7 ) ;
V_29 -> V_2 . V_77 = 0 ;
F_39 ( V_70 ) ;
goto V_46;
}
F_40 ( V_70 , V_29 ) ;
if ( V_41 -> V_79 ) {
int V_30 ;
V_30 = V_41 -> V_79 ( & V_70 -> V_43 , V_29 -> V_2 . V_21 ,
V_32 ) ;
if ( V_30 )
F_37 ( & V_70 -> V_43 , L_12 , V_30 ) ;
}
V_46:
return V_7 ;
}
static int F_39 ( struct V_69 * V_70 )
{
struct V_40 * V_41 = F_15 ( & V_70 -> V_43 ) ;
struct V_1 * V_29 = F_41 ( V_70 ) ;
int V_30 ;
if ( V_41 && V_41 -> V_80 ) {
V_30 = V_41 -> V_80 ( & V_70 -> V_43 , V_29 -> V_2 . V_21 ,
V_32 ) ;
if ( V_30 ) {
F_37 ( & V_70 -> V_43 , L_13 , V_30 ) ;
return V_30 ;
}
}
F_42 ( & V_29 -> V_2 ) ;
if ( F_31 () )
return 0 ;
F_43 ( 1 ) ;
return - V_81 ;
}
static int T_3 F_44 ( void )
{
return F_45 ( & V_82 ) ;
}
static void T_4 F_46 ( void )
{
F_47 ( & V_82 ) ;
}
