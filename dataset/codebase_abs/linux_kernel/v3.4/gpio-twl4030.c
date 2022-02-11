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
T_1 V_36 = V_37 ;
V_32 -= V_26 ;
if ( V_32 ) {
V_33 <<= 1 ;
V_36 = V_38 ;
}
V_10 = F_2 ( V_36 , 0x7f ,
V_39 ) ;
if ( V_10 < 0 )
goto V_40;
V_10 = F_2 ( V_36 , 0x7f ,
V_41 ) ;
if ( V_10 < 0 )
goto V_40;
V_36 = V_13 ;
V_10 = F_4 ( V_36 , & V_12 ,
V_14 ) ;
if ( V_10 < 0 )
goto V_40;
V_12 &= ~ V_33 ;
V_10 = F_2 ( V_36 , V_12 ,
V_14 ) ;
if ( V_10 < 0 )
goto V_40;
V_10 = 0 ;
goto V_40;
}
if ( ! V_27 ) {
struct V_42 * V_43 ;
T_1 V_6 = V_44 ;
V_43 = V_31 -> V_45 -> V_46 ;
if ( V_43 )
V_6 |= V_43 -> V_47 & 0x03 ;
V_10 = F_1 ( V_48 , V_6 ) ;
}
if ( ! V_10 )
V_27 |= ( 0x1 << V_32 ) ;
V_40:
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
F_1 ( V_48 , 0x0 ) ;
F_7 ( & V_11 ) ;
}
static int F_15 ( struct V_30 * V_31 , unsigned V_32 )
{
return ( V_32 < V_26 )
? F_8 ( V_32 , 1 )
: - V_49 ;
}
static int F_16 ( struct V_30 * V_31 , unsigned V_32 )
{
int V_10 = 0 ;
if ( V_32 < V_26 )
V_10 = F_11 ( V_32 ) ;
else if ( V_32 == V_26 )
V_10 = V_12 & V_8 ;
else
V_10 = V_12 & V_50 ;
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
return ( V_51 && ( V_32 < V_26 ) )
? ( V_51 + V_32 )
: - V_49 ;
}
static int T_2 F_20 ( T_3 V_52 , T_3 V_53 )
{
T_1 V_54 [ 6 ] ;
unsigned V_55 , V_56 ;
for ( V_56 = 1 , V_55 = 1 ; V_55 < 6 ; V_55 ++ ) {
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
return F_21 ( V_3 , V_54 ,
V_59 , 5 ) ;
}
static int T_2 F_22 ( T_3 V_60 , T_1 V_47 )
{
T_1 V_54 [ 4 ] ;
V_54 [ 1 ] = ( V_60 & 0xff ) | ( V_47 & 0x03 ) ;
V_60 >>= 8 ;
V_54 [ 2 ] = ( V_60 & 0xff ) ;
V_60 >>= 8 ;
V_54 [ 3 ] = ( V_60 & 0x03 ) ;
return F_21 ( V_3 , V_54 ,
V_61 , 3 ) ;
}
static int T_2 F_23 ( struct V_62 * V_63 )
{
struct V_42 * V_43 = V_63 -> V_45 . V_46 ;
struct V_64 * V_65 = V_63 -> V_45 . V_66 ;
int V_4 , V_67 ;
if ( F_24 () ) {
F_25 ( & V_63 -> V_45 , L_1 ) ;
goto V_68;
}
V_67 = F_26 ( - 1 , 0 , V_26 , 0 ) ;
if ( V_67 < 0 ) {
F_25 ( & V_63 -> V_45 , L_2 ) ;
return V_67 ;
}
F_27 ( V_65 , V_26 , V_67 , 0 ,
& V_69 , NULL ) ;
V_4 = F_28 ( & V_63 -> V_45 , V_3 , V_67 ) ;
if ( V_4 < 0 )
return V_4 ;
V_51 = V_67 ;
V_68:
V_70 . V_20 = - 1 ;
V_70 . V_71 = V_26 ;
V_70 . V_45 = & V_63 -> V_45 ;
if ( V_43 ) {
V_70 . V_20 = V_43 -> V_72 ;
V_4 = F_20 ( V_43 -> V_73 , V_43 -> V_74 ) ;
if ( V_4 )
F_29 ( & V_63 -> V_45 , L_3 ,
V_43 -> V_73 , V_43 -> V_74 ,
V_4 ) ;
V_4 = F_22 ( V_43 -> V_60 , V_43 -> V_47 ) ;
if ( V_4 )
F_29 ( & V_63 -> V_45 , L_4 ,
V_43 -> V_60 , V_43 -> V_47 ,
V_4 ) ;
if ( V_43 -> V_75 )
V_70 . V_71 += 2 ;
}
V_4 = F_30 ( & V_70 ) ;
if ( V_4 < 0 ) {
F_25 ( & V_63 -> V_45 , L_5 , V_4 ) ;
V_70 . V_71 = 0 ;
F_31 ( V_63 ) ;
} else if ( V_43 && V_43 -> V_76 ) {
int V_10 ;
V_10 = V_43 -> V_76 ( & V_63 -> V_45 ,
V_43 -> V_72 , V_26 ) ;
if ( V_10 )
F_29 ( & V_63 -> V_45 , L_6 , V_10 ) ;
}
return V_4 ;
}
static int F_31 ( struct V_62 * V_63 )
{
struct V_42 * V_43 = V_63 -> V_45 . V_46 ;
int V_10 ;
if ( V_43 && V_43 -> V_77 ) {
V_10 = V_43 -> V_77 ( & V_63 -> V_45 ,
V_43 -> V_72 , V_26 ) ;
if ( V_10 ) {
F_29 ( & V_63 -> V_45 , L_7 , V_10 ) ;
return V_10 ;
}
}
V_10 = F_32 ( & V_70 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( F_24 () )
return 0 ;
F_33 ( 1 ) ;
return - V_78 ;
}
static int T_4 F_34 ( void )
{
return F_35 ( & V_79 ) ;
}
static void T_5 F_36 ( void )
{
F_37 ( & V_79 ) ;
}
