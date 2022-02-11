static int F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int * V_4 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_5 ) {
F_4 ( L_1 , V_3 , V_5 ) ;
goto V_9;
}
V_5 = F_5 ( V_2 -> V_7 , V_10 , V_4 ) ;
if ( V_5 )
F_4 ( L_2 , V_5 ) ;
V_9:
F_6 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int
F_7 ( struct V_1 * V_2 , unsigned int V_3 , unsigned int V_11 )
{
int V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , V_3 ) ;
if ( V_5 ) {
F_4 ( L_1 , V_3 , V_5 ) ;
goto V_9;
}
V_11 |= V_12 ;
V_5 = F_3 ( V_2 -> V_7 , V_13 , V_11 ) ;
if ( V_5 )
F_4 ( L_3 , V_5 ) ;
V_9:
F_6 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_8 ( struct V_1 * V_2 , int V_14 )
{
int V_15 , V_16 , V_17 , V_18 = 0 ;
unsigned int V_19 ;
V_18 = F_1 ( V_2 , V_14 , & V_19 ) ;
if ( V_18 ) {
F_4 ( L_4 , V_14 , V_18 ) ;
return V_18 ;
}
if ( ! V_19 ) {
F_4 ( L_5 , V_14 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_19 & ( 1 << V_17 ) ) {
V_15 = V_14 * 8 + V_17 ;
V_16 = F_9 ( V_2 -> V_20 , V_15 ) ;
F_10 ( V_16 ) ;
}
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 , int V_21 )
{
unsigned int V_22 ;
int V_23 , V_17 , V_18 = 0 ;
V_18 = F_5 ( V_2 -> V_7 , V_24 + V_21 ,
& V_22 ) ;
if ( V_18 ) {
F_4 ( L_6 , V_21 , V_18 ) ;
return V_18 ;
}
if ( ! V_22 ) {
F_4 ( L_7 , V_21 ) ;
return 0 ;
}
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ )
if ( V_22 & ( 1 << V_17 ) ) {
V_23 = V_21 * 8 + V_17 ;
V_18 |= F_8 ( V_2 , V_23 ) ;
}
return V_18 ;
}
static void F_12 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_26 ) ;
struct V_27 * V_27 = F_14 ( V_26 ) ;
unsigned int V_28 ;
int V_17 , V_18 , V_29 = 0 ;
F_15 ( V_27 , V_26 ) ;
V_18 = F_5 ( V_2 -> V_7 , V_30 , & V_28 ) ;
if ( V_18 ) {
F_4 ( L_8 , V_18 ) ;
return;
}
V_29 = V_28 >> 1 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_31 ; V_17 ++ )
if ( V_29 & ( 1 << V_17 ) )
F_11 ( V_2 , V_17 ) ;
F_16 ( V_27 , V_26 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
int V_21 , int V_14 )
{
int V_15 , V_16 , V_17 , V_18 ;
unsigned int V_19 ;
V_18 = F_5 ( V_2 -> V_7 ,
F_18 ( V_21 , V_14 ) , & V_19 ) ;
if ( V_18 ) {
F_4 ( L_9 , V_14 , V_18 ) ;
return;
}
V_14 += ( V_21 * V_32 ) - 1 ;
for ( V_17 = 0 ; V_17 < 8 ; V_17 ++ ) {
if ( V_19 & F_19 ( V_17 ) ) {
V_15 = V_14 * 8 + V_17 ;
V_16 = F_9 ( V_2 -> V_20 , V_15 ) ;
F_10 ( V_16 ) ;
}
}
}
static inline void F_20 ( struct V_1 * V_2 ,
int V_21 , T_1 V_33 )
{
int V_14 ;
for ( V_14 = 1 ; V_14 < 8 ; V_14 ++ )
if ( V_33 & F_19 ( V_14 ) )
F_17 ( V_2 , V_21 , V_14 ) ;
}
static void F_21 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_13 ( V_26 ) ;
struct V_27 * V_27 = F_14 ( V_26 ) ;
unsigned int V_21 ;
int V_18 ;
F_15 ( V_27 , V_26 ) ;
V_18 = F_5 ( V_2 -> V_7 ,
V_34 , & V_21 ) ;
if ( V_18 ) {
F_4 ( L_10 , V_18 ) ;
goto V_35;
}
if ( V_21 & F_22 ( 7 , 1 ) )
F_20 ( V_2 , 0 , V_21 ) ;
if ( ! ( V_21 & F_19 ( 0 ) ) )
goto V_35;
V_18 = F_5 ( V_2 -> V_7 ,
V_36 , & V_21 ) ;
if ( V_18 ) {
F_4 ( L_11 , V_18 ) ;
goto V_35;
}
F_20 ( V_2 , 1 , V_21 ) ;
V_35:
F_16 ( V_27 , V_26 ) ;
}
static void F_23 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_24 ( V_38 ) ;
unsigned int V_15 = F_25 ( V_38 ) ;
T_1 V_14 , V_39 ;
V_14 = V_15 / 8 ;
V_39 = V_2 -> V_39 [ V_15 ] | V_40 | V_41 ;
F_7 ( V_2 , V_14 , V_39 ) ;
}
static void F_26 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_24 ( V_38 ) ;
unsigned int V_15 = F_25 ( V_38 ) ;
T_1 V_14 , V_39 ;
V_14 = V_15 / 8 ;
V_39 = V_2 -> V_39 [ V_15 ] ;
F_7 ( V_2 , V_14 , V_39 ) ;
}
static int F_27 ( struct V_37 * V_38 , unsigned int V_42 )
{
struct V_1 * V_2 = F_24 ( V_38 ) ;
unsigned int V_15 = F_25 ( V_38 ) ;
int V_43 ;
T_1 V_14 , V_39 ;
V_14 = V_15 / 8 ;
V_43 = V_15 % 8 ;
V_2 -> V_39 [ V_15 ] = ( V_43 << V_44 )
| V_40 ;
if ( V_42 & ( V_45 | V_46 ) ) {
if ( V_42 & V_45 )
V_2 -> V_39 [ V_15 ] &= ~ V_47 ;
if ( V_42 & V_46 )
V_2 -> V_39 [ V_15 ] &= ~ V_48 ;
} else {
V_2 -> V_39 [ V_15 ] |= V_49 ;
if ( V_42 & V_50 )
V_2 -> V_39 [ V_15 ] &= ~ V_47 ;
else
V_2 -> V_39 [ V_15 ] &= ~ V_48 ;
}
V_39 = V_2 -> V_39 [ V_15 ] | V_41 ;
return F_7 ( V_2 , V_14 , V_39 ) ;
}
static int F_28 ( struct V_37 * V_38 ,
enum V_51 V_52 ,
bool * V_53 )
{
struct V_1 * V_2 = F_24 ( V_38 ) ;
unsigned int V_15 = F_25 ( V_38 ) ;
unsigned int V_19 ;
int V_43 ;
T_1 V_14 ;
int V_5 ;
if ( V_52 != V_54 )
return - V_55 ;
V_14 = V_15 / 8 ;
V_43 = V_15 % 8 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 , V_8 , V_14 ) ;
if ( V_5 ) {
F_4 ( L_1 , V_14 , V_5 ) ;
goto V_9;
}
V_5 = F_5 ( V_2 -> V_7 , V_56 , & V_19 ) ;
if ( V_5 ) {
F_4 ( L_2 , V_5 ) ;
goto V_9;
}
* V_53 = ! ! ( V_19 & F_19 ( V_43 ) ) ;
V_9:
F_6 ( & V_2 -> V_6 ) ;
return V_5 ;
}
static int F_29 ( struct V_57 * V_38 , unsigned int V_16 ,
T_2 V_58 )
{
struct V_1 * V_2 = V_38 -> V_59 ;
F_30 ( V_16 , & V_60 , V_61 ) ;
F_31 ( V_16 , V_2 ) ;
F_32 ( V_16 ) ;
return 0 ;
}
static void F_33 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_24 ( V_38 ) ;
unsigned int V_15 = F_25 ( V_38 ) ;
T_1 V_14 , V_21 ;
int V_43 , V_5 ;
V_14 = V_15 / 8 ;
V_21 = V_14 / V_32 ;
V_43 = V_15 % 8 ;
V_14 %= V_32 ;
V_5 = F_34 ( V_2 -> V_7 ,
F_35 ( V_21 , V_14 ) ,
F_19 ( V_43 ) , F_19 ( V_43 ) ) ;
if ( V_5 ) {
F_4 ( L_12 , V_15 , V_5 ) ;
return;
}
V_5 = F_34 ( V_2 -> V_7 ,
F_36 ( V_21 , V_14 ) ,
F_19 ( V_43 ) , F_19 ( V_43 ) ) ;
if ( V_5 )
F_4 ( L_13 , V_15 , V_5 ) ;
}
static void F_37 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_24 ( V_38 ) ;
unsigned int V_15 = F_25 ( V_38 ) ;
int V_43 , V_5 ;
T_1 V_14 , V_21 ;
V_14 = V_15 / 8 ;
V_21 = V_14 / V_32 ;
V_43 = V_15 % 8 ;
V_14 %= V_32 ;
V_5 = F_34 ( V_2 -> V_7 ,
F_35 ( V_21 , V_14 ) ,
F_19 ( V_43 ) , ~ F_19 ( V_43 ) ) ;
if ( V_5 )
F_4 ( L_14 , V_15 , V_5 ) ;
}
static int F_38 ( struct V_37 * V_38 ,
enum V_51 V_52 ,
bool * V_53 )
{
struct V_1 * V_2 = F_24 ( V_38 ) ;
int V_5 , V_15 = F_25 ( V_38 ) ;
T_1 V_14 , V_43 , V_21 ;
unsigned int V_19 ;
V_14 = V_15 / 8 ;
V_21 = V_14 / V_32 ;
V_43 = V_15 % 8 ;
V_14 %= V_32 ;
V_5 = F_5 ( V_2 -> V_7 ,
F_39 ( V_21 , V_14 ) , & V_19 ) ;
if ( V_5 ) {
F_4 ( L_15 , V_15 , V_5 ) ;
return V_5 ;
}
* V_53 = ! ! ( V_19 & F_19 ( V_43 ) ) ;
return V_5 ;
}
static int F_40 ( struct V_57 * V_38 , unsigned int V_16 ,
T_2 V_58 )
{
struct V_1 * V_2 = V_38 -> V_59 ;
F_30 ( V_16 , & V_62 , V_61 ) ;
F_31 ( V_16 , V_2 ) ;
F_32 ( V_16 ) ;
return 0 ;
}
static int F_41 ( struct V_63 * V_64 )
{
const struct V_65 * V_66 ;
struct V_7 * V_7 ;
int V_16 , V_5 ;
unsigned int V_67 ;
T_3 V_68 ;
struct V_1 * V_2 ;
V_66 = F_42 ( & V_64 -> V_69 ) ;
if ( ! V_66 ) {
F_43 ( & V_64 -> V_69 , L_16 ) ;
return - V_55 ;
}
V_16 = F_44 ( V_64 , 0 ) ;
if ( V_16 < 0 )
return V_16 ;
V_7 = F_45 ( & V_64 -> V_69 , NULL , V_64 -> V_69 . V_70 ,
& V_71 ) ;
if ( F_46 ( V_7 ) )
return F_47 ( V_7 ) ;
V_5 = F_5 ( V_7 , V_72 , & V_67 ) ;
if ( V_5 ) {
F_4 ( L_17 , V_72 , V_5 ) ;
return V_5 ;
}
F_48 ( L_18 , V_67 ) ;
V_68 = V_67 ;
V_5 = F_5 ( V_7 , V_73 , & V_67 ) ;
if ( V_5 ) {
F_4 ( L_19 ,
V_73 , V_5 ) ;
return V_5 ;
}
F_48 ( L_20 , V_67 ) ;
V_68 |= V_67 << V_74 ;
V_2 = F_49 ( & V_64 -> V_69 , sizeof( * V_2 ) +
sizeof( V_2 -> V_39 [ 0 ] ) * V_66 -> V_75 ,
V_76 ) ;
if ( ! V_2 )
return - V_77 ;
F_50 ( V_64 , V_2 ) ;
V_2 -> V_7 = V_7 ;
V_2 -> V_75 = V_66 -> V_75 ;
V_2 -> V_78 = F_51 ( V_2 -> V_75 , 8 ) ;
V_2 -> V_31 = F_51 ( V_2 -> V_78 , 8 ) ;
F_52 ( & V_2 -> V_6 ) ;
V_2 -> V_20 = F_53 ( V_64 -> V_69 . V_79 ,
V_66 -> V_75 ,
V_66 -> V_80 ,
V_2 ) ;
if ( ! V_2 -> V_20 )
return - V_81 ;
F_54 ( V_16 , V_66 -> V_82 , V_2 ) ;
F_55 ( V_16 , 1 ) ;
V_5 = F_56 ( V_64 -> V_69 . V_79 , NULL , NULL , & V_64 -> V_69 ) ;
if ( V_5 ) {
F_54 ( V_16 , NULL , NULL ) ;
F_57 ( V_2 -> V_20 ) ;
}
return V_5 ;
}
static int F_58 ( struct V_83 * V_69 , void * V_84 )
{
F_59 ( F_60 ( V_69 ) ) ;
return 0 ;
}
static int F_61 ( struct V_63 * V_64 )
{
int V_16 = F_44 ( V_64 , 0 ) ;
struct V_1 * V_2 = F_62 ( V_64 ) ;
F_63 ( & V_64 -> V_69 , NULL , F_58 ) ;
F_54 ( V_16 , NULL , NULL ) ;
F_57 ( V_2 -> V_20 ) ;
return 0 ;
}
static int T_4 F_64 ( void )
{
return F_65 ( & V_85 ) ;
}
static void T_5 F_66 ( void )
{
F_67 ( & V_85 ) ;
}
