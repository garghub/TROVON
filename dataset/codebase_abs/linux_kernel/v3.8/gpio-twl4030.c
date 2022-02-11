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
int V_10 ;
if ( V_5 )
V_7 <<= 1 ;
F_6 ( & V_11 ) ;
if ( V_6 )
V_12 &= ~ V_7 ;
else
V_12 |= V_7 ;
V_10 = F_2 ( V_13 , V_12 ,
V_14 ) ;
F_7 ( & V_11 ) ;
}
static int F_8 ( int V_15 , int V_16 )
{
T_1 V_17 = V_15 >> 3 ;
T_1 V_18 = F_9 ( V_15 & 0x7 ) ;
T_1 V_19 = 0 ;
T_1 V_20 = V_21 + V_17 ;
int V_4 = 0 ;
F_6 ( & V_11 ) ;
V_4 = F_3 ( V_20 ) ;
if ( V_4 >= 0 ) {
if ( V_16 )
V_19 = V_4 & ~ V_18 ;
else
V_19 = V_4 | V_18 ;
V_4 = F_1 ( V_20 , V_19 ) ;
}
F_7 ( & V_11 ) ;
return V_4 ;
}
static int F_10 ( int V_15 , int V_22 )
{
T_1 V_17 = V_15 >> 3 ;
T_1 V_18 = F_9 ( V_15 & 0x7 ) ;
T_1 V_20 = 0 ;
if ( V_22 )
V_20 = V_23 + V_17 ;
else
V_20 = V_24 + V_17 ;
return F_1 ( V_20 , V_18 ) ;
}
static int F_11 ( int V_15 )
{
T_1 V_17 = V_15 >> 3 ;
T_1 V_25 = V_15 & 0x7 ;
T_1 V_20 = 0 ;
int V_4 = 0 ;
if ( F_12 ( ( V_15 >= V_26 )
|| ! ( V_27 & F_9 ( V_15 ) ) ) )
return - V_28 ;
V_20 = V_29 + V_17 ;
V_4 = F_3 ( V_20 ) ;
if ( V_4 > 0 )
V_4 = ( V_4 >> V_25 ) & 0x1 ;
return V_4 ;
}
static int F_13 ( struct V_30 * V_31 , unsigned V_32 )
{
int V_10 = 0 ;
F_6 ( & V_11 ) ;
if ( V_32 >= V_26 ) {
T_1 V_33 = V_8 | V_34
| V_9 | V_35 ;
T_1 V_19 = V_36 ;
V_32 -= V_26 ;
if ( V_32 ) {
V_33 <<= 1 ;
V_19 = V_37 ;
}
V_10 = F_2 ( V_13 , 0x7f , V_19 + 1 ) ;
if ( V_10 < 0 )
goto V_38;
V_10 = F_2 ( V_13 , 0x7f , V_19 ) ;
if ( V_10 < 0 )
goto V_38;
V_10 = F_4 ( V_13 , & V_12 ,
V_14 ) ;
if ( V_10 < 0 )
goto V_38;
V_12 &= ~ V_33 ;
V_10 = F_2 ( V_13 , V_12 ,
V_14 ) ;
if ( V_10 < 0 )
goto V_38;
V_10 = 0 ;
goto V_38;
}
if ( ! V_27 ) {
struct V_39 * V_40 ;
T_1 V_6 = V_41 ;
V_40 = V_31 -> V_42 -> V_43 ;
if ( V_40 )
V_6 |= V_40 -> V_44 & 0x03 ;
V_10 = F_1 ( V_45 , V_6 ) ;
}
if ( ! V_10 )
V_27 |= ( 0x1 << V_32 ) ;
V_38:
F_7 ( & V_11 ) ;
return V_10 ;
}
static void F_14 ( struct V_30 * V_31 , unsigned V_32 )
{
if ( V_32 >= V_26 ) {
F_5 ( V_32 - V_26 , 1 ) ;
return;
}
F_6 ( & V_11 ) ;
V_27 &= ~ F_9 ( V_32 ) ;
if ( ! V_27 )
F_1 ( V_45 , 0x0 ) ;
F_7 ( & V_11 ) ;
}
static int F_15 ( struct V_30 * V_31 , unsigned V_32 )
{
return ( V_32 < V_26 )
? F_8 ( V_32 , 1 )
: - V_46 ;
}
static int F_16 ( struct V_30 * V_31 , unsigned V_32 )
{
int V_10 = 0 ;
if ( V_32 < V_26 )
V_10 = F_11 ( V_32 ) ;
else if ( V_32 == V_26 )
V_10 = V_12 & V_8 ;
else
V_10 = V_12 & V_47 ;
return ( V_10 < 0 ) ? 0 : V_10 ;
}
static int F_17 ( struct V_30 * V_31 , unsigned V_32 , int V_6 )
{
if ( V_32 < V_26 ) {
F_10 ( V_32 , V_6 ) ;
return F_8 ( V_32 , 0 ) ;
} else {
F_5 ( V_32 - V_26 , V_6 ) ;
return 0 ;
}
}
static void F_18 ( struct V_30 * V_31 , unsigned V_32 , int V_6 )
{
if ( V_32 < V_26 )
F_10 ( V_32 , V_6 ) ;
else
F_5 ( V_32 - V_26 , V_6 ) ;
}
static int F_19 ( struct V_30 * V_31 , unsigned V_32 )
{
return ( V_48 && ( V_32 < V_26 ) )
? ( V_48 + V_32 )
: - V_46 ;
}
static int F_20 ( T_2 V_49 , T_2 V_50 )
{
T_1 V_51 [ 5 ] ;
unsigned V_52 , V_53 ;
for ( V_53 = 1 , V_52 = 0 ; V_52 < 5 ; V_52 ++ ) {
T_1 V_54 ;
unsigned V_55 ;
for ( V_54 = 0 , V_55 = 0 ; V_55 < 8 ; V_55 += 2 , V_53 <<= 1 ) {
if ( V_49 & V_53 )
V_54 |= 1 << ( V_55 + 1 ) ;
else if ( V_50 & V_53 )
V_54 |= 1 << ( V_55 + 0 ) ;
}
V_51 [ V_52 ] = V_54 ;
}
return F_21 ( V_3 , V_51 ,
V_56 , 5 ) ;
}
static int F_22 ( T_2 V_57 , T_1 V_44 )
{
T_1 V_51 [ 3 ] ;
V_51 [ 0 ] = ( V_57 & 0xff ) | ( V_44 & 0x03 ) ;
V_57 >>= 8 ;
V_51 [ 1 ] = ( V_57 & 0xff ) ;
V_57 >>= 8 ;
V_51 [ 2 ] = ( V_57 & 0x03 ) ;
return F_21 ( V_3 , V_51 ,
V_58 , 3 ) ;
}
static struct V_39 * F_23 ( struct V_59 * V_42 )
{
struct V_39 * V_60 ;
V_60 = F_24 ( V_42 , sizeof( * V_60 ) , V_61 ) ;
if ( ! V_60 )
return NULL ;
V_60 -> V_62 = F_25 ( V_42 -> V_63 ,
L_1 ) ;
F_26 ( V_42 -> V_63 , L_2 ,
& V_60 -> V_57 ) ;
F_26 ( V_42 -> V_63 , L_3 ,
( T_2 * ) & V_60 -> V_44 ) ;
F_26 ( V_42 -> V_63 , L_4 ,
& V_60 -> V_64 ) ;
F_26 ( V_42 -> V_63 , L_5 ,
& V_60 -> V_65 ) ;
return V_60 ;
}
static int F_27 ( struct V_66 * V_67 )
{
struct V_39 * V_40 = V_67 -> V_42 . V_43 ;
struct V_68 * V_69 = V_67 -> V_42 . V_63 ;
int V_4 , V_70 ;
if ( F_28 () ) {
F_29 ( & V_67 -> V_42 , L_6 ) ;
goto V_71;
}
V_70 = F_30 ( - 1 , 0 , V_26 , 0 ) ;
if ( V_70 < 0 ) {
F_29 ( & V_67 -> V_42 , L_7 ) ;
return V_70 ;
}
F_31 ( V_69 , V_26 , V_70 , 0 ,
& V_72 , NULL ) ;
V_4 = F_32 ( & V_67 -> V_42 , V_3 , V_70 ) ;
if ( V_4 < 0 )
return V_4 ;
V_48 = V_70 ;
V_71:
V_73 . V_20 = - 1 ;
V_73 . V_74 = V_26 ;
V_73 . V_42 = & V_67 -> V_42 ;
if ( V_69 )
V_40 = F_23 ( & V_67 -> V_42 ) ;
if ( V_40 == NULL ) {
F_29 ( & V_67 -> V_42 , L_8 ) ;
return - V_75 ;
}
V_4 = F_20 ( V_40 -> V_64 , V_40 -> V_65 ) ;
if ( V_4 )
F_33 ( & V_67 -> V_42 , L_9 ,
V_40 -> V_64 , V_40 -> V_65 , V_4 ) ;
V_4 = F_22 ( V_40 -> V_57 , V_40 -> V_44 ) ;
if ( V_4 )
F_33 ( & V_67 -> V_42 , L_10 ,
V_40 -> V_57 , V_40 -> V_44 , V_4 ) ;
if ( V_40 -> V_62 )
V_73 . V_74 += 2 ;
V_4 = F_34 ( & V_73 ) ;
if ( V_4 < 0 ) {
F_29 ( & V_67 -> V_42 , L_11 , V_4 ) ;
V_73 . V_74 = 0 ;
F_35 ( V_67 ) ;
goto V_76;
}
V_77 = V_73 . V_20 ;
if ( V_40 && V_40 -> V_78 ) {
int V_10 ;
V_10 = V_40 -> V_78 ( & V_67 -> V_42 ,
V_77 , V_26 ) ;
if ( V_10 )
F_33 ( & V_67 -> V_42 , L_12 , V_10 ) ;
}
V_76:
return V_4 ;
}
static int F_35 ( struct V_66 * V_67 )
{
struct V_39 * V_40 = V_67 -> V_42 . V_43 ;
int V_10 ;
if ( V_40 && V_40 -> V_79 ) {
V_10 = V_40 -> V_79 ( & V_67 -> V_42 ,
V_77 , V_26 ) ;
if ( V_10 ) {
F_33 ( & V_67 -> V_42 , L_13 , V_10 ) ;
return V_10 ;
}
}
V_10 = F_36 ( & V_73 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_28 () )
return 0 ;
F_37 ( 1 ) ;
return - V_80 ;
}
static int T_3 F_38 ( void )
{
return F_39 ( & V_81 ) ;
}
static void T_4 F_40 ( void )
{
F_41 ( & V_81 ) ;
}
