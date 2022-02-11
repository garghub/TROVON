static void F_1 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 -> V_3 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 -> V_3 + V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_1 )
{
return F_5 ( V_1 -> V_3 + V_5 ) ;
}
static void F_6 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 -> V_3 + V_6 ) ;
}
static void F_7 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 -> V_3 + V_7 ) ;
}
static void F_8 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 -> V_3 + V_8 ) ;
}
static void F_9 ( struct V_1 * V_1 , T_1 V_2 )
{
F_2 ( V_2 , V_1 -> V_3 + V_9 ) ;
}
static T_1 F_10 ( struct V_1 * V_1 )
{
return F_5 ( V_1 -> V_3 + V_9 ) ;
}
static void F_11 ( struct V_1 * V_1 , T_2 V_10 ,
bool V_11 )
{
V_1 -> V_12 -> V_13 ( V_1 -> V_12 , V_10 , V_11 ) ;
}
static void F_12 ( struct V_1 * V_1 , T_2 V_10 ,
bool V_11 )
{
V_1 -> V_12 -> V_14 ( V_1 -> V_12 , V_10 , V_11 ) ;
}
static int F_13 ( struct V_1 * V_1 )
{
return ( V_1 -> V_12 -> V_15 ) ?
V_1 -> V_12 -> V_15 ( V_1 -> V_12 ) : 0 ;
}
static void F_14 ( struct V_1 * V_1 )
{
if ( V_1 -> V_12 -> V_16 )
V_1 -> V_12 -> V_16 ( V_1 -> V_12 ) ;
}
static T_2 F_15 ( T_3 V_17 )
{
return F_16 ( ( V_18 + V_17 - 1 ) / V_17 , 2u , 255u ) ;
}
static bool F_17 ( struct V_1 * V_1 )
{
return F_4 ( V_1 ) & V_19 ;
}
static T_4 F_18 ( int V_20 , void * V_21 )
{
struct V_1 * V_1 = V_21 ;
F_7 ( V_1 , V_22 | V_23 ) ;
F_19 ( & V_1 -> V_24 ) ;
return V_25 ;
}
static void F_20 ( struct V_1 * V_1 , unsigned V_26 ,
const T_2 * V_27 , T_2 * V_28 )
{
unsigned V_29 , V_30 , V_31 = 0 ;
V_30 = F_21 ( V_26 , 16u ) ;
F_8 ( V_1 , V_32 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
F_9 ( V_1 , V_33 ) ;
F_8 ( V_1 , V_34 ) ;
if ( V_27 )
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
F_9 ( V_1 , * V_27 ++ ) ;
else
for ( V_29 = 0 ; V_29 < V_26 ; ++ V_29 )
F_9 ( V_1 , 0 ) ;
V_26 -= V_30 ;
if ( V_26 ) {
T_1 V_35 = 0xf08 ;
F_6 ( V_1 , 0x700 ) ;
F_3 ( V_1 , V_19 ) ;
do {
F_22 ( V_1 -> V_24 , ! F_17 ( V_1 ) ) ;
F_6 ( V_1 , V_35 ) ;
F_3 ( V_1 , V_19 ) ;
if ( V_28 ) {
F_8 ( V_1 ,
V_36 + V_31 ) ;
for ( V_29 = 0 ; V_29 < 8 ; ++ V_29 )
* V_28 ++ = F_10 ( V_1 ) ;
}
V_30 = F_21 ( V_26 , 8u ) ;
if ( V_27 ) {
F_8 ( V_1 ,
V_34 + V_31 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
F_9 ( V_1 , * V_27 ++ ) ;
}
V_35 = ( V_31 ? 0x808 : 0 ) + ( ( V_30 - 1 ) << 8 ) ;
V_31 ^= 8 ;
V_26 -= V_30 ;
} while ( V_26 );
F_22 ( V_1 -> V_24 , ! F_17 ( V_1 ) ) ;
F_6 ( V_1 , V_35 ) ;
F_3 ( V_1 , V_19 ) ;
if ( V_28 ) {
F_8 ( V_1 , V_36 + V_31 ) ;
for ( V_29 = 0 ; V_29 < 8 ; ++ V_29 )
* V_28 ++ = F_10 ( V_1 ) ;
V_31 ^= 8 ;
}
} else {
F_6 ( V_1 , ( V_30 - 1 ) << 8 ) ;
F_3 ( V_1 , V_19 ) ;
}
F_22 ( V_1 -> V_24 , ! F_17 ( V_1 ) ) ;
if ( V_28 ) {
F_8 ( V_1 , V_36 + V_31 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
* V_28 ++ = F_10 ( V_1 ) ;
}
}
static void F_23 ( struct V_1 * V_1 , unsigned V_26 ,
const T_1 * V_27 , T_1 * V_28 )
{
unsigned V_29 , V_30 , V_31 = 0 ;
V_30 = F_21 ( V_26 , 16u ) ;
F_8 ( V_1 , V_32 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
F_9 ( V_1 , V_33 ) ;
F_8 ( V_1 , V_34 ) ;
if ( V_27 )
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
F_9 ( V_1 , * V_27 ++ ) ;
else
for ( V_29 = 0 ; V_29 < V_26 ; ++ V_29 )
F_9 ( V_1 , 0 ) ;
V_26 -= V_30 ;
if ( V_26 ) {
T_1 V_35 = 0xf08 ;
F_6 ( V_1 , 0x700 ) ;
F_3 ( V_1 , V_19 ) ;
do {
F_22 ( V_1 -> V_24 , ! F_17 ( V_1 ) ) ;
F_6 ( V_1 , V_35 ) ;
F_3 ( V_1 , V_19 ) ;
if ( V_28 ) {
F_8 ( V_1 ,
V_36 + V_31 ) ;
for ( V_29 = 0 ; V_29 < 8 ; ++ V_29 )
* V_28 ++ = F_10 ( V_1 ) ;
}
V_30 = F_21 ( V_26 , 8u ) ;
if ( V_27 ) {
F_8 ( V_1 ,
V_34 + V_31 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
F_9 ( V_1 , * V_27 ++ ) ;
}
V_35 = ( V_31 ? 0x808 : 0x000 ) + ( ( V_30 - 1 ) << 8 ) ;
V_31 ^= 8 ;
V_26 -= V_30 ;
} while ( V_26 );
F_22 ( V_1 -> V_24 , ! F_17 ( V_1 ) ) ;
F_6 ( V_1 , V_35 ) ;
F_3 ( V_1 , V_19 ) ;
if ( V_28 ) {
F_8 ( V_1 , V_36 + V_31 ) ;
for ( V_29 = 0 ; V_29 < 8 ; ++ V_29 )
* V_28 ++ = F_10 ( V_1 ) ;
V_31 ^= 8 ;
}
} else {
F_6 ( V_1 , ( V_30 - 1 ) << 8 ) ;
F_3 ( V_1 , V_19 ) ;
}
F_22 ( V_1 -> V_24 , ! F_17 ( V_1 ) ) ;
if ( V_28 ) {
F_8 ( V_1 , V_36 + V_31 ) ;
for ( V_29 = 0 ; V_29 < V_30 ; ++ V_29 )
* V_28 ++ = F_10 ( V_1 ) ;
}
}
static void F_24 ( struct V_37 * V_38 , bool V_39 )
{
struct V_1 * V_1 = F_25 ( V_38 -> V_40 ) ;
bool V_11 = V_38 -> V_41 & V_42 ;
if ( V_39 )
F_11 ( V_1 , V_38 -> V_10 , V_11 ) ;
else
F_12 ( V_1 , V_38 -> V_10 , V_11 ) ;
}
static int F_26 ( struct V_43 * V_40 ,
struct V_37 * V_38 ,
struct V_44 * V_45 )
{
struct V_1 * V_1 = F_25 ( V_40 ) ;
T_1 V_46 = V_47 ;
V_46 |= V_45 -> V_48 << 10 ;
if ( V_38 -> V_41 & V_49 )
V_46 |= V_50 ;
if ( V_38 -> V_41 & V_51 )
V_46 |= V_52 ;
V_46 |= F_15 ( V_45 -> V_17 ) ;
F_1 ( V_1 , V_46 ) ;
F_7 ( V_1 , V_22 ) ;
if ( V_45 -> V_48 == 8 )
F_20 ( V_1 , V_45 -> V_53 , V_45 -> V_54 , V_45 -> V_55 ) ;
else
F_23 ( V_1 , V_45 -> V_53 / 2 , V_45 -> V_54 ,
V_45 -> V_55 ) ;
F_7 ( V_1 , 0 ) ;
return 0 ;
}
static int F_27 ( struct V_37 * V_38 )
{
F_12 ( F_25 ( V_38 -> V_40 ) ,
V_38 -> V_10 , V_38 -> V_41 & V_42 ) ;
F_28 ( & V_38 -> V_56 ,
L_1 ,
V_38 -> V_48 , V_38 -> V_10 ,
( V_18 / F_15 ( V_38 -> V_57 ) )
/ 1000 ) ;
return 0 ;
}
static int F_29 ( struct V_58 * V_59 )
{
struct V_43 * V_40 ;
struct V_1 * V_1 ;
struct V_60 * V_61 ;
struct V_62 * V_63 ;
int V_64 ;
V_63 = F_30 ( & V_59 -> V_56 ) ;
if ( ! V_63 ) {
F_28 ( & V_59 -> V_56 , L_2 ) ;
return - V_65 ;
}
if ( ! V_63 -> V_12 ) {
F_28 ( & V_59 -> V_56 , L_3 ) ;
return - V_66 ;
}
V_40 = F_31 ( & V_59 -> V_56 , sizeof( * V_1 ) ) ;
if ( V_40 == NULL ) {
F_28 ( & V_59 -> V_56 , L_4 ) ;
return - V_67 ;
}
V_1 = F_25 ( V_40 ) ;
V_61 = F_32 ( V_59 , V_68 , 0 ) ;
V_1 -> V_3 = F_33 ( & V_59 -> V_56 , V_61 ) ;
if ( F_34 ( V_1 -> V_3 ) ) {
V_64 = F_35 ( V_1 -> V_3 ) ;
goto V_69;
}
V_1 -> V_70 = F_36 ( V_59 , 0 ) ;
if ( V_1 -> V_70 < 0 ) {
F_28 ( & V_59 -> V_56 , L_5 ) ;
V_64 = - V_71 ;
goto V_69;
}
V_64 = F_37 ( & V_59 -> V_56 , V_1 -> V_70 , F_18 ,
0 , V_59 -> V_72 , V_1 ) ;
if ( V_64 ) {
F_28 ( & V_59 -> V_56 , L_6 ) ;
goto V_69;
}
V_1 -> V_73 = F_38 ( & V_59 -> V_56 , L_7 ) ;
if ( F_34 ( V_1 -> V_73 ) ) {
F_28 ( & V_59 -> V_56 , L_8 ) ;
V_64 = F_35 ( V_1 -> V_73 ) ;
goto V_69;
}
F_39 ( V_1 -> V_73 ) ;
V_40 -> V_74 = V_63 -> V_74 ;
V_40 -> V_75 = V_63 -> V_75 ;
V_1 -> V_12 = V_63 -> V_12 ;
V_64 = F_13 ( V_1 ) ;
if ( V_64 ) {
F_28 ( & V_59 -> V_56 , L_9 ) ;
goto V_76;
}
F_40 ( & V_1 -> V_24 ) ;
V_40 -> V_77 = V_42 | V_51 | V_49 ;
V_40 -> V_78 = F_41 ( 8 , 16 ) ;
V_40 -> V_15 = F_27 ;
V_40 -> V_79 = F_24 ;
V_40 -> V_80 = F_26 ;
V_40 -> V_81 = true ;
F_42 ( V_59 , V_40 ) ;
V_64 = F_43 ( & V_59 -> V_56 , V_40 ) ;
if ( V_64 ) {
F_28 ( & V_59 -> V_56 , L_10 ) ;
goto V_82;
}
F_44 ( & V_59 -> V_56 ) ;
F_45 ( & V_59 -> V_56 , L_11 ) ;
return 0 ;
V_82:
F_14 ( V_1 ) ;
V_76:
F_46 ( V_1 -> V_73 ) ;
V_69:
F_47 ( V_40 ) ;
F_28 ( & V_59 -> V_56 , L_12 ) ;
return V_64 ;
}
static int F_48 ( struct V_58 * V_59 )
{
struct V_43 * V_40 = F_49 ( V_59 ) ;
struct V_1 * V_1 = F_25 ( V_40 ) ;
F_50 ( & V_59 -> V_56 ) ;
F_1 ( V_1 , V_47 ) ;
F_14 ( V_1 ) ;
F_46 ( V_1 -> V_73 ) ;
return 0 ;
}
static int F_51 ( struct V_83 * V_56 )
{
struct V_43 * V_40 = F_52 ( V_56 ) ;
struct V_1 * V_1 = F_25 ( V_40 ) ;
int V_84 ;
V_84 = F_53 ( V_40 ) ;
if ( V_84 )
return V_84 ;
F_46 ( V_1 -> V_73 ) ;
return 0 ;
}
static int F_54 ( struct V_83 * V_56 )
{
struct V_43 * V_40 = F_52 ( V_56 ) ;
struct V_1 * V_1 = F_25 ( V_40 ) ;
F_39 ( V_1 -> V_73 ) ;
return F_55 ( V_40 ) ;
}
static int F_56 ( struct V_83 * V_56 )
{
struct V_43 * V_40 = F_52 ( V_56 ) ;
struct V_1 * V_1 = F_25 ( V_40 ) ;
F_46 ( V_1 -> V_73 ) ;
return 0 ;
}
static int F_57 ( struct V_83 * V_56 )
{
struct V_43 * V_40 = F_52 ( V_56 ) ;
struct V_1 * V_1 = F_25 ( V_40 ) ;
F_39 ( V_1 -> V_73 ) ;
return 0 ;
}
