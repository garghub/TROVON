static inline int F_1 ( T_1 V_1 , T_1 V_2 )
{
return F_2 ( V_3 , V_2 , V_1 ) ;
}
static inline int F_3 ( T_1 V_1 )
{
T_1 V_2 ;
int V_4 = 0 ;
V_4 = F_4 ( V_3 , & V_2 , V_1 ) ;
return ( V_4 < 0 ) ? V_4 : V_2 ;
}
static void F_5 ( int V_5 , int V_6 )
{
T_1 V_7 = V_8 | V_9 ;
if ( V_5 )
V_7 <<= 1 ;
if ( V_6 )
V_10 &= ~ V_7 ;
else
V_10 |= V_7 ;
F_6 ( F_2 ( V_11 , V_10 ,
V_12 ) ) ;
}
static int F_7 ( int V_13 , int V_14 )
{
T_1 V_15 = V_13 >> 3 ;
T_1 V_16 = F_8 ( V_13 & 0x7 ) ;
T_1 V_17 = 0 ;
T_1 V_18 = V_19 + V_15 ;
int V_4 = 0 ;
V_4 = F_3 ( V_18 ) ;
if ( V_4 >= 0 ) {
if ( V_14 )
V_17 = V_4 & ~ V_16 ;
else
V_17 = V_4 | V_16 ;
V_4 = F_1 ( V_18 , V_17 ) ;
}
return V_4 ;
}
static int F_9 ( int V_13 , int V_20 )
{
T_1 V_15 = V_13 >> 3 ;
T_1 V_16 = F_8 ( V_13 & 0x7 ) ;
T_1 V_18 = 0 ;
if ( V_20 )
V_18 = V_21 + V_15 ;
else
V_18 = V_22 + V_15 ;
return F_1 ( V_18 , V_16 ) ;
}
static int F_10 ( int V_13 )
{
T_1 V_15 = V_13 >> 3 ;
T_1 V_23 = V_13 & 0x7 ;
T_1 V_18 = 0 ;
int V_4 = 0 ;
V_18 = V_24 + V_15 ;
V_4 = F_3 ( V_18 ) ;
if ( V_4 > 0 )
V_4 = ( V_4 >> V_23 ) & 0x1 ;
return V_4 ;
}
static int F_11 ( struct V_25 * V_26 , unsigned V_27 )
{
struct V_28 * V_29 = F_12 ( V_26 ) ;
int V_30 = 0 ;
F_13 ( & V_29 -> V_31 ) ;
if ( V_27 >= V_32 ) {
T_1 V_33 = V_8 | V_34
| V_9 | V_35 ;
T_1 V_17 = V_36 ;
V_27 -= V_32 ;
if ( V_27 ) {
V_33 <<= 1 ;
V_17 = V_37 ;
}
V_30 = F_2 ( V_11 , 0x7f , V_17 + 1 ) ;
if ( V_30 < 0 )
goto V_38;
V_30 = F_2 ( V_11 , 0x7f , V_17 ) ;
if ( V_30 < 0 )
goto V_38;
V_30 = F_4 ( V_11 , & V_10 ,
V_12 ) ;
if ( V_30 < 0 )
goto V_38;
V_10 &= ~ V_33 ;
V_30 = F_2 ( V_11 , V_10 ,
V_12 ) ;
if ( V_30 < 0 )
goto V_38;
V_30 = 0 ;
goto V_38;
}
if ( ! V_29 -> V_39 ) {
struct V_40 * V_41 ;
T_1 V_6 = V_42 ;
V_41 = F_14 ( V_26 -> V_43 ) ;
if ( V_41 )
V_6 |= V_41 -> V_44 & 0x03 ;
V_30 = F_1 ( V_45 , V_6 ) ;
}
V_38:
if ( ! V_30 )
V_29 -> V_39 |= F_8 ( V_27 ) ;
F_15 ( & V_29 -> V_31 ) ;
return V_30 ;
}
static void F_16 ( struct V_25 * V_26 , unsigned V_27 )
{
struct V_28 * V_29 = F_12 ( V_26 ) ;
F_13 ( & V_29 -> V_31 ) ;
if ( V_27 >= V_32 ) {
F_5 ( V_27 - V_32 , 1 ) ;
goto V_46;
}
V_29 -> V_39 &= ~ F_8 ( V_27 ) ;
if ( ! V_29 -> V_39 )
F_1 ( V_45 , 0x0 ) ;
V_46:
F_15 ( & V_29 -> V_31 ) ;
}
static int F_17 ( struct V_25 * V_26 , unsigned V_27 )
{
struct V_28 * V_29 = F_12 ( V_26 ) ;
int V_4 ;
F_13 ( & V_29 -> V_31 ) ;
if ( V_27 < V_32 )
V_4 = F_7 ( V_27 , 1 ) ;
else
V_4 = - V_47 ;
if ( ! V_4 )
V_29 -> V_48 &= ~ F_8 ( V_27 ) ;
F_15 ( & V_29 -> V_31 ) ;
return V_4 ;
}
static int F_18 ( struct V_25 * V_26 , unsigned V_27 )
{
struct V_28 * V_29 = F_12 ( V_26 ) ;
int V_4 ;
int V_30 = 0 ;
F_13 ( & V_29 -> V_31 ) ;
if ( ! ( V_29 -> V_39 & F_8 ( V_27 ) ) ) {
V_4 = - V_49 ;
goto V_46;
}
if ( V_29 -> V_48 & F_8 ( V_27 ) )
V_30 = V_29 -> V_50 & F_8 ( V_27 ) ;
else
V_30 = F_10 ( V_27 ) ;
V_4 = ( V_30 < 0 ) ? V_30 : ! ! V_30 ;
V_46:
F_15 ( & V_29 -> V_31 ) ;
return V_4 ;
}
static void F_19 ( struct V_25 * V_26 , unsigned V_27 , int V_6 )
{
struct V_28 * V_29 = F_12 ( V_26 ) ;
F_13 ( & V_29 -> V_31 ) ;
if ( V_27 < V_32 )
F_9 ( V_27 , V_6 ) ;
else
F_5 ( V_27 - V_32 , V_6 ) ;
if ( V_6 )
V_29 -> V_50 |= F_8 ( V_27 ) ;
else
V_29 -> V_50 &= ~ F_8 ( V_27 ) ;
F_15 ( & V_29 -> V_31 ) ;
}
static int F_20 ( struct V_25 * V_26 , unsigned V_27 , int V_6 )
{
struct V_28 * V_29 = F_12 ( V_26 ) ;
int V_4 = 0 ;
F_13 ( & V_29 -> V_31 ) ;
if ( V_27 < V_32 ) {
V_4 = F_7 ( V_27 , 0 ) ;
if ( V_4 ) {
F_15 ( & V_29 -> V_31 ) ;
return V_4 ;
}
}
V_29 -> V_48 |= F_8 ( V_27 ) ;
F_15 ( & V_29 -> V_31 ) ;
F_19 ( V_26 , V_27 , V_6 ) ;
return V_4 ;
}
static int F_21 ( struct V_25 * V_26 , unsigned V_27 )
{
struct V_28 * V_29 = F_12 ( V_26 ) ;
return ( V_29 -> V_51 && ( V_27 < V_32 ) )
? ( V_29 -> V_51 + V_27 )
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
return F_23 ( V_3 , V_54 ,
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
return F_23 ( V_3 , V_54 ,
V_61 , 3 ) ;
}
static struct V_40 * F_25 ( struct V_62 * V_63 ,
struct V_40 * V_41 )
{
struct V_40 * V_64 ;
V_64 = F_26 ( V_63 , sizeof( * V_64 ) , V_65 ) ;
if ( ! V_64 )
return NULL ;
if ( V_41 )
* V_64 = * V_41 ;
V_64 -> V_66 = F_27 ( V_63 -> V_67 ,
L_1 ) ;
F_28 ( V_63 -> V_67 , L_2 ,
& V_64 -> V_60 ) ;
F_28 ( V_63 -> V_67 , L_3 ,
( T_2 * ) & V_64 -> V_44 ) ;
F_28 ( V_63 -> V_67 , L_4 ,
& V_64 -> V_68 ) ;
F_28 ( V_63 -> V_67 , L_5 ,
& V_64 -> V_69 ) ;
return V_64 ;
}
static int F_29 ( struct V_70 * V_71 )
{
struct V_40 * V_41 = F_14 ( & V_71 -> V_63 ) ;
struct V_72 * V_73 = V_71 -> V_63 . V_67 ;
struct V_28 * V_29 ;
int V_4 , V_51 ;
V_29 = F_26 ( & V_71 -> V_63 , sizeof( struct V_28 ) ,
V_65 ) ;
if ( ! V_29 )
return - V_74 ;
if ( F_30 () ) {
F_31 ( & V_71 -> V_63 , L_6 ) ;
goto V_75;
}
V_51 = F_32 ( - 1 , 0 , V_32 , 0 ) ;
if ( V_51 < 0 ) {
F_31 ( & V_71 -> V_63 , L_7 ) ;
return V_51 ;
}
F_33 ( V_73 , V_32 , V_51 , 0 ,
& V_76 , NULL ) ;
V_4 = F_34 ( & V_71 -> V_63 , V_3 , V_51 ) ;
if ( V_4 < 0 )
return V_4 ;
V_29 -> V_51 = V_51 ;
V_75:
V_29 -> V_25 = V_77 ;
V_29 -> V_25 . V_18 = - 1 ;
V_29 -> V_25 . V_78 = V_32 ;
V_29 -> V_25 . V_43 = & V_71 -> V_63 ;
F_35 ( & V_29 -> V_31 ) ;
if ( V_73 )
V_41 = F_25 ( & V_71 -> V_63 , V_41 ) ;
if ( V_41 == NULL ) {
F_31 ( & V_71 -> V_63 , L_8 ) ;
return - V_79 ;
}
V_4 = F_22 ( V_41 -> V_68 , V_41 -> V_69 ) ;
if ( V_4 )
F_36 ( & V_71 -> V_63 , L_9 ,
V_41 -> V_68 , V_41 -> V_69 , V_4 ) ;
V_4 = F_24 ( V_41 -> V_60 , V_41 -> V_44 ) ;
if ( V_4 )
F_36 ( & V_71 -> V_63 , L_10 ,
V_41 -> V_60 , V_41 -> V_44 , V_4 ) ;
if ( V_41 -> V_66 )
V_29 -> V_25 . V_78 += 2 ;
V_4 = F_37 ( & V_29 -> V_25 , V_29 ) ;
if ( V_4 < 0 ) {
F_31 ( & V_71 -> V_63 , L_11 , V_4 ) ;
V_29 -> V_25 . V_78 = 0 ;
F_38 ( V_71 ) ;
goto V_46;
}
F_39 ( V_71 , V_29 ) ;
if ( V_41 -> V_80 ) {
int V_30 ;
V_30 = V_41 -> V_80 ( & V_71 -> V_63 , V_29 -> V_25 . V_18 ,
V_32 ) ;
if ( V_30 )
F_36 ( & V_71 -> V_63 , L_12 , V_30 ) ;
}
V_46:
return V_4 ;
}
static int F_38 ( struct V_70 * V_71 )
{
struct V_40 * V_41 = F_14 ( & V_71 -> V_63 ) ;
struct V_28 * V_29 = F_40 ( V_71 ) ;
int V_30 ;
if ( V_41 && V_41 -> V_81 ) {
V_30 = V_41 -> V_81 ( & V_71 -> V_63 , V_29 -> V_25 . V_18 ,
V_32 ) ;
if ( V_30 ) {
F_36 ( & V_71 -> V_63 , L_13 , V_30 ) ;
return V_30 ;
}
}
F_41 ( & V_29 -> V_25 ) ;
if ( F_30 () )
return 0 ;
F_42 ( 1 ) ;
return - V_82 ;
}
static int T_3 F_43 ( void )
{
return F_44 ( & V_83 ) ;
}
static void T_4 F_45 ( void )
{
F_46 ( & V_83 ) ;
}
