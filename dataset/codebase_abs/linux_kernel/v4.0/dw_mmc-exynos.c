static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_6 ||
V_4 -> V_5 == V_7 ) {
F_2 ( V_2 , V_8 , 0 ) ;
F_2 ( V_2 , V_9 , V_10 ) ;
F_2 ( V_2 , V_11 , V_12 |
V_13 |
V_14 |
V_15 ) ;
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
V_2 -> V_16 /= ( V_4 -> V_17 + 1 ) ;
return 0 ;
}
static int F_4 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_5 ( V_19 ) ;
return F_6 ( V_2 ) ;
}
static int F_7 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_5 ( V_19 ) ;
F_1 ( V_2 ) ;
return F_8 ( V_2 ) ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_1 * V_2 = F_5 ( V_19 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_20 ;
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
V_20 = F_10 ( V_2 , V_22 ) ;
else
V_20 = F_10 ( V_2 , V_23 ) ;
if ( V_20 & V_24 ) {
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_22 , V_20 ) ;
else
F_2 ( V_2 , V_23 , V_20 ) ;
}
return 0 ;
}
static void F_11 ( struct V_1 * V_2 , T_1 * V_25 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 ) {
if ( F_12 ( F_10 ( V_2 , V_22 ) ) )
* V_25 |= V_26 ;
} else {
if ( F_12 ( F_10 ( V_2 , V_23 ) ) )
* V_25 |= V_26 ;
}
}
static void F_13 ( struct V_1 * V_2 , struct V_27 * V_28 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
unsigned int V_29 = V_28 -> clock ;
unsigned long V_30 ;
T_2 div = V_4 -> V_17 + 1 ;
if ( V_28 -> V_31 == V_32 ) {
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_22 , V_4 -> V_33 ) ;
else
F_2 ( V_2 , V_23 , V_4 -> V_33 ) ;
if ( V_28 -> V_34 == V_35 )
V_29 <<= 1 ;
} else {
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_22 , V_4 -> V_36 ) ;
else
F_2 ( V_2 , V_23 , V_4 -> V_36 ) ;
}
if ( ! V_29 || F_14 ( V_2 -> V_37 ) )
return;
if ( V_29 < V_38 )
V_29 = V_38 ;
if ( V_29 != V_4 -> V_39 ) {
int V_40 = F_15 ( V_2 -> V_37 , V_29 * div ) ;
if ( V_40 )
F_16 ( V_2 -> V_19 ,
L_1 ,
V_29 * div , V_40 ) ;
V_30 = F_17 ( V_2 -> V_37 ) ;
V_2 -> V_16 = V_30 / div ;
V_4 -> V_39 = V_29 ;
V_2 -> V_41 = 0 ;
}
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_42 * V_43 = V_2 -> V_19 -> V_44 ;
T_1 V_31 [ 2 ] ;
T_1 div = 0 ;
int V_45 ;
int V_40 ;
V_4 = F_19 ( V_2 -> V_19 , sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return - V_47 ;
for ( V_45 = 0 ; V_45 < F_20 ( V_48 ) ; V_45 ++ ) {
if ( F_21 ( V_43 , V_48 [ V_45 ] . V_49 ) )
V_4 -> V_5 = V_48 [ V_45 ] . V_5 ;
}
if ( V_4 -> V_5 == V_50 )
V_4 -> V_17 = V_51 - 1 ;
else if ( V_4 -> V_5 == V_52 )
V_4 -> V_17 = V_53 - 1 ;
else {
F_22 ( V_43 , L_2 , & div ) ;
V_4 -> V_17 = div ;
}
V_40 = F_23 ( V_43 ,
L_3 , V_31 , 2 ) ;
if ( V_40 )
return V_40 ;
V_4 -> V_36 = F_24 ( V_31 [ 0 ] , V_31 [ 1 ] , div ) ;
V_40 = F_23 ( V_43 ,
L_4 , V_31 , 2 ) ;
if ( V_40 )
return V_40 ;
V_4 -> V_33 = F_24 ( V_31 [ 0 ] , V_31 [ 1 ] , div ) ;
V_2 -> V_4 = V_4 ;
return 0 ;
}
static inline T_2 F_25 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
return F_26 ( F_10 ( V_2 , V_22 ) ) ;
else
return F_26 ( F_10 ( V_2 , V_23 ) ) ;
}
static inline void F_27 ( struct V_1 * V_2 , T_2 V_54 )
{
T_1 V_20 ;
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
V_20 = F_10 ( V_2 , V_22 ) ;
else
V_20 = F_10 ( V_2 , V_23 ) ;
V_20 = ( V_20 & ~ 0x7 ) | F_26 ( V_54 ) ;
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_22 , V_20 ) ;
else
F_2 ( V_2 , V_23 , V_20 ) ;
}
static inline T_2 F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
T_1 V_20 ;
T_2 V_54 ;
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
V_20 = F_10 ( V_2 , V_22 ) ;
else
V_20 = F_10 ( V_2 , V_23 ) ;
V_54 = ( V_20 + 1 ) & 0x7 ;
V_20 = ( V_20 & ~ 0x7 ) | V_54 ;
if ( V_4 -> V_5 == V_21 ||
V_4 -> V_5 == V_7 )
F_2 ( V_2 , V_22 , V_20 ) ;
else
F_2 ( V_2 , V_23 , V_20 ) ;
return V_54 ;
}
static T_3 F_29 ( T_2 V_55 )
{
const T_2 V_56 = 8 ;
T_2 V_57 ;
T_3 V_58 , V_59 = - 1 ;
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ ) {
V_57 = F_30 ( V_55 , V_58 ) ;
if ( ( V_57 & 0xc7 ) == 0xc7 ) {
V_59 = V_58 ;
goto V_60;
}
}
for ( V_58 = 0 ; V_58 < V_56 ; V_58 ++ ) {
V_57 = F_30 ( V_55 , V_58 ) ;
if ( ( V_57 & 0x83 ) == 0x83 ) {
V_59 = V_58 ;
goto V_60;
}
}
V_60:
return V_59 ;
}
static int F_31 ( struct V_61 * V_62 )
{
struct V_1 * V_2 = V_62 -> V_2 ;
struct V_63 * V_64 = V_62 -> V_64 ;
T_2 V_65 , V_66 , V_55 = 0 ;
T_3 V_67 = - 1 ;
int V_40 = 0 ;
V_65 = F_25 ( V_2 ) ;
do {
F_2 ( V_2 , V_68 , ~ 0 ) ;
V_66 = F_28 ( V_2 ) ;
if ( ! F_32 ( V_64 ) )
V_55 |= ( 1 << V_66 ) ;
} while ( V_65 != V_66 );
V_67 = F_29 ( V_55 ) ;
if ( V_67 >= 0 )
F_27 ( V_2 , V_67 ) ;
else
V_40 = - V_69 ;
return V_40 ;
}
static int F_33 ( struct V_70 * V_71 )
{
const struct V_72 * V_73 ;
const struct V_74 * V_75 ;
V_75 = F_34 ( V_76 , V_71 -> V_19 . V_44 ) ;
V_73 = V_75 -> V_77 ;
return F_35 ( V_71 , V_73 ) ;
}
