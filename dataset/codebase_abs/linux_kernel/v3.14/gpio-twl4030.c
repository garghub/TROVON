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
V_41 = F_14 ( V_3 -> V_43 ) ;
if ( V_41 )
V_9 |= V_41 -> V_44 & 0x03 ;
V_13 = F_3 ( V_45 , V_9 ) ;
}
V_38:
if ( ! V_13 )
V_30 -> V_39 |= F_9 ( V_29 ) ;
F_15 ( & V_30 -> V_31 ) ;
return V_13 ;
}
static void F_16 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 >= V_32 ) {
F_7 ( V_29 - V_32 , 1 ) ;
goto V_46;
}
V_30 -> V_39 &= ~ F_9 ( V_29 ) ;
if ( ! V_30 -> V_39 )
F_3 ( V_45 , 0x0 ) ;
V_46:
F_15 ( & V_30 -> V_31 ) ;
}
static int F_17 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int V_7 ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 < V_32 )
V_7 = F_8 ( V_29 , 1 ) ;
else
V_7 = - V_47 ;
if ( ! V_7 )
V_30 -> V_48 &= ~ F_9 ( V_29 ) ;
F_15 ( & V_30 -> V_31 ) ;
return V_7 ;
}
static int F_18 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int V_7 ;
int V_13 = 0 ;
F_13 ( & V_30 -> V_31 ) ;
if ( ! ( V_30 -> V_39 & F_9 ( V_29 ) ) ) {
V_7 = - V_49 ;
goto V_46;
}
if ( V_30 -> V_48 & F_9 ( V_29 ) )
V_13 = V_30 -> V_50 & F_9 ( V_29 ) ;
else
V_13 = F_11 ( V_29 ) ;
V_7 = ( V_13 <= 0 ) ? 0 : 1 ;
V_46:
F_15 ( & V_30 -> V_31 ) ;
return V_7 ;
}
static void F_19 ( struct V_2 * V_3 , unsigned V_29 , int V_9 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 < V_32 )
F_10 ( V_29 , V_9 ) ;
else
F_7 ( V_29 - V_32 , V_9 ) ;
if ( V_9 )
V_30 -> V_50 |= F_9 ( V_29 ) ;
else
V_30 -> V_50 &= ~ F_9 ( V_29 ) ;
F_15 ( & V_30 -> V_31 ) ;
}
static int F_20 ( struct V_2 * V_3 , unsigned V_29 , int V_9 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
int V_7 = 0 ;
F_13 ( & V_30 -> V_31 ) ;
if ( V_29 < V_32 ) {
V_7 = F_8 ( V_29 , 0 ) ;
if ( V_7 ) {
F_15 ( & V_30 -> V_31 ) ;
return V_7 ;
}
}
V_30 -> V_48 |= F_9 ( V_29 ) ;
F_15 ( & V_30 -> V_31 ) ;
F_19 ( V_3 , V_29 , V_9 ) ;
return V_7 ;
}
static int F_21 ( struct V_2 * V_3 , unsigned V_29 )
{
struct V_1 * V_30 = F_1 ( V_3 ) ;
return ( V_30 -> V_51 && ( V_29 < V_32 ) )
? ( V_30 -> V_51 + V_29 )
: - V_47 ;
}
static int F_22 ( T_2 V_52 , T_2 V_53 )
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
return F_23 ( V_6 , V_54 ,
V_59 , 5 ) ;
}
static int F_24 ( T_2 V_60 , T_1 V_44 )
{
T_1 V_54 [ 3 ] ;
V_54 [ 0 ] = ( V_60 & 0xff ) | ( V_44 & 0x03 ) ;
V_60 >>= 8 ;
V_54 [ 1 ] = ( V_60 & 0xff ) ;
V_60 >>= 8 ;
V_54 [ 2 ] = ( V_60 & 0x03 ) ;
return F_23 ( V_6 , V_54 ,
V_61 , 3 ) ;
}
static struct V_40 * F_25 ( struct V_62 * V_43 ,
struct V_40 * V_41 )
{
struct V_40 * V_63 ;
V_63 = F_26 ( V_43 , sizeof( * V_63 ) , V_64 ) ;
if ( ! V_63 )
return NULL ;
if ( V_41 )
* V_63 = * V_41 ;
V_63 -> V_65 = F_27 ( V_43 -> V_66 ,
L_1 ) ;
F_28 ( V_43 -> V_66 , L_2 ,
& V_63 -> V_60 ) ;
F_28 ( V_43 -> V_66 , L_3 ,
( T_2 * ) & V_63 -> V_44 ) ;
F_28 ( V_43 -> V_66 , L_4 ,
& V_63 -> V_67 ) ;
F_28 ( V_43 -> V_66 , L_5 ,
& V_63 -> V_68 ) ;
return V_63 ;
}
static int F_29 ( struct V_69 * V_70 )
{
struct V_40 * V_41 = F_14 ( & V_70 -> V_43 ) ;
struct V_71 * V_72 = V_70 -> V_43 . V_66 ;
struct V_1 * V_30 ;
int V_7 , V_51 ;
V_30 = F_26 ( & V_70 -> V_43 , sizeof( struct V_1 ) ,
V_64 ) ;
if ( ! V_30 )
return - V_73 ;
if ( F_30 () ) {
F_31 ( & V_70 -> V_43 , L_6 ) ;
goto V_74;
}
V_51 = F_32 ( - 1 , 0 , V_32 , 0 ) ;
if ( V_51 < 0 ) {
F_31 ( & V_70 -> V_43 , L_7 ) ;
return V_51 ;
}
F_33 ( V_72 , V_32 , V_51 , 0 ,
& V_75 , NULL ) ;
V_7 = F_34 ( & V_70 -> V_43 , V_6 , V_51 ) ;
if ( V_7 < 0 )
return V_7 ;
V_30 -> V_51 = V_51 ;
V_74:
V_30 -> V_2 = V_76 ;
V_30 -> V_2 . V_22 = - 1 ;
V_30 -> V_2 . V_77 = V_32 ;
V_30 -> V_2 . V_43 = & V_70 -> V_43 ;
F_35 ( & V_30 -> V_31 ) ;
if ( V_72 )
V_41 = F_25 ( & V_70 -> V_43 , V_41 ) ;
if ( V_41 == NULL ) {
F_31 ( & V_70 -> V_43 , L_8 ) ;
return - V_78 ;
}
V_7 = F_22 ( V_41 -> V_67 , V_41 -> V_68 ) ;
if ( V_7 )
F_36 ( & V_70 -> V_43 , L_9 ,
V_41 -> V_67 , V_41 -> V_68 , V_7 ) ;
V_7 = F_24 ( V_41 -> V_60 , V_41 -> V_44 ) ;
if ( V_7 )
F_36 ( & V_70 -> V_43 , L_10 ,
V_41 -> V_60 , V_41 -> V_44 , V_7 ) ;
if ( V_41 -> V_65 )
V_30 -> V_2 . V_77 += 2 ;
V_7 = F_37 ( & V_30 -> V_2 ) ;
if ( V_7 < 0 ) {
F_31 ( & V_70 -> V_43 , L_11 , V_7 ) ;
V_30 -> V_2 . V_77 = 0 ;
F_38 ( V_70 ) ;
goto V_46;
}
F_39 ( V_70 , V_30 ) ;
if ( V_41 && V_41 -> V_79 ) {
int V_13 ;
V_13 = V_41 -> V_79 ( & V_70 -> V_43 , V_30 -> V_2 . V_22 ,
V_32 ) ;
if ( V_13 )
F_36 ( & V_70 -> V_43 , L_12 , V_13 ) ;
}
V_46:
return V_7 ;
}
static int F_38 ( struct V_69 * V_70 )
{
struct V_40 * V_41 = F_14 ( & V_70 -> V_43 ) ;
struct V_1 * V_30 = F_40 ( V_70 ) ;
int V_13 ;
if ( V_41 && V_41 -> V_80 ) {
V_13 = V_41 -> V_80 ( & V_70 -> V_43 , V_30 -> V_2 . V_22 ,
V_32 ) ;
if ( V_13 ) {
F_36 ( & V_70 -> V_43 , L_13 , V_13 ) ;
return V_13 ;
}
}
V_13 = F_41 ( & V_30 -> V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
if ( F_30 () )
return 0 ;
F_42 ( 1 ) ;
return - V_81 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_82 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_82 ) ;
}
