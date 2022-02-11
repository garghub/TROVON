static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
}
static void F_2 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
unsigned long V_5 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_7 |= 1 << V_4 -> V_8 ;
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
}
static T_1 F_6 ( int V_10 , void * V_11 )
{
struct V_1 * V_2 = V_11 ;
struct V_3 * V_4 ;
unsigned int V_12 , V_13 ;
F_7 ( & V_2 -> V_6 ) ;
V_12 = F_8 ( V_2 -> V_14 + V_15 ) ;
if ( V_12 == 0 || V_12 == ( ~ 0 ) ) {
F_9 ( & V_2 -> V_6 ) ;
return V_16 ;
}
if ( V_12 & V_17 ) {
F_10 ( V_17 , V_2 -> V_14 + V_18 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_19 ; V_13 ++ ) {
V_4 = V_2 -> V_20 [ V_13 ] ;
if ( V_4 ) {
if ( ( V_12 >> V_13 ) & F_11 ( 1 ) )
V_4 -> V_21 ( V_4 ) ;
if ( ( V_12 >> V_13 ) & F_12 ( 1 ) )
V_4 -> V_22 ( V_4 ) ;
}
}
V_2 -> V_7 |= V_12
& ( ( 1 << V_2 -> V_19 ) - 1 ) ;
}
F_10 ( V_12 , V_2 -> V_14 + V_15 ) ;
if ( V_2 -> V_23 )
F_13 ( V_2 -> V_23 ) ;
else if ( ! V_2 -> V_7 )
F_10 ( V_17 , V_2 -> V_14 + V_24 ) ;
else
F_4 ( & V_2 -> V_9 ) ;
F_9 ( & V_2 -> V_6 ) ;
return V_25 ;
}
static unsigned char F_14 ( char T_2 * V_26 )
{
unsigned int V_27 ;
int V_13 ;
F_10 ( 0x0e00 , V_26 + V_28 ) ;
for ( V_13 = 16 ; V_13 <= 256 ; V_13 <<= 1 ) {
if ( ! ( V_29
& F_8 ( V_26 + V_30 ) ) )
break;
F_15 ( V_13 ) ;
}
V_27 = F_8 ( V_26 + V_30 ) ;
if ( ! ( V_31 & V_27 ) )
return 0 ;
F_10 ( F_8 ( V_26 + V_28 ) | V_32 ,
V_26 + V_28 ) ;
if ( ( ( F_8 ( V_26 + V_30 ) >> 4 ) & 7 )
== V_33 )
F_15 ( 40 ) ;
F_10 ( ( V_27 & V_34 ) | 0x0c00 ,
V_26 + V_28 ) ;
F_15 ( 20 ) ;
for ( V_13 = 16 ; V_13 <= 256 ; V_13 <<= 1 ) {
if ( ( V_29
& F_8 ( V_26 + V_30 ) ) )
break;
F_15 ( V_13 ) ;
}
F_10 ( F_8 ( V_26 + V_28 ) & ( ~ V_32 ) ,
V_26 + V_28 ) ;
return ( F_8 ( V_26 + V_30 ) >> 4 ) & 7 ;
}
inline static void F_16 ( char T_2 * V_26 )
{
F_10 ( ( ~ V_34 ) & F_8 ( V_26 + V_28 ) ,
V_26 + V_28 ) ;
}
inline static char T_2 *
F_17 ( char T_2 * V_35 , unsigned int V_36 )
{
return V_35 + ( ( V_36 + 1 ) << 10 ) ;
}
static void F_18 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_19 ( V_38 , struct V_1 ,
V_9 ) ;
struct V_3 * V_4 ;
char T_2 * V_26 ;
unsigned long V_5 ;
unsigned char V_39 ;
unsigned int V_7 , V_13 ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_7 = V_2 -> V_7 ;
V_2 -> V_7 = 0 ;
F_20 ( V_2 -> V_40 . V_41 , L_1 ,
V_7 ) ;
if ( ! V_7 ) {
F_5 ( & V_2 -> V_6 , V_5 ) ;
return;
}
for ( V_13 = 0 ; V_13 < V_2 -> V_19 ; V_13 ++ ) {
if ( ! ( V_7 & ( 1 << V_13 ) ) )
continue;
V_4 = V_2 -> V_20 [ V_13 ] ;
if ( V_4 ) {
F_21 ( V_42
L_2 ,
F_22 ( & V_2 -> V_40 ) , V_2 -> V_43 , V_13 ) ;
V_2 -> V_20 [ V_13 ] = NULL ;
V_26 = V_4 -> V_14 ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
F_23 ( & V_4 -> V_40 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
F_16 ( V_26 ) ;
F_10 ( 0x0e00 , V_26 + V_28 ) ;
}
F_5 ( & V_2 -> V_6 , V_5 ) ;
V_39 = F_14 (
F_17 ( V_2 -> V_14 , V_13 ) ) ;
V_4 = F_24 ( V_2 , V_13 , V_39 ) ;
if ( V_4 ) {
V_4 -> V_14 = F_17 ( V_2 -> V_14 , V_13 ) ;
if ( ! F_25 ( & V_4 -> V_40 ) ) {
F_3 ( & V_2 -> V_6 , V_5 ) ;
if ( ! V_2 -> V_20 [ V_13 ] ) {
V_2 -> V_20 [ V_13 ] = V_4 ;
V_4 = NULL ;
}
F_5 ( & V_2 -> V_6 , V_5 ) ;
}
if ( V_4 )
F_26 ( & V_4 -> V_40 ) ;
}
F_3 ( & V_2 -> V_6 , V_5 ) ;
}
F_10 ( F_11 ( V_7 )
| F_12 ( V_7 ) ,
V_2 -> V_14 + V_18 ) ;
F_10 ( F_11 ( V_7 )
| F_12 ( V_7 ) ,
V_2 -> V_14 + V_24 ) ;
F_10 ( V_17 , V_2 -> V_14 + V_24 ) ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
}
static int F_27 ( struct V_44 * V_40 , T_3 V_45 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_13 ;
F_20 ( & V_40 -> V_40 , L_3 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_19 ; V_13 ++ ) {
if ( V_2 -> V_20 [ V_13 ] )
F_16 ( V_2 -> V_20 [ V_13 ] -> V_14 ) ;
}
F_29 ( V_40 ) ;
F_30 ( V_40 , F_31 ( V_40 , V_45 ) , 0 ) ;
F_32 ( V_40 ) ;
F_33 ( V_40 , F_31 ( V_40 , V_45 ) ) ;
return 0 ;
}
static int F_34 ( struct V_44 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_46 ;
unsigned int V_47 = 0 , V_48 = 0 ;
unsigned long V_5 ;
unsigned char V_49 [ V_2 -> V_19 ] ;
F_35 ( V_50 ) ;
F_33 ( V_40 , V_51 ) ;
F_36 ( V_40 ) ;
V_46 = F_37 ( V_40 ) ;
if ( V_46 )
return V_46 ;
F_38 ( V_40 ) ;
F_20 ( & V_40 -> V_40 , L_4 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_19 ; V_46 ++ )
V_49 [ V_46 ] = F_14 (
F_17 ( V_2 -> V_14 , V_46 ) ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
for ( V_46 = 0 ; V_46 < V_2 -> V_19 ; V_46 ++ ) {
if ( V_2 -> V_20 [ V_46 ] ) {
if ( V_2 -> V_20 [ V_46 ] -> type == V_49 [ V_46 ] )
V_47 |= 1 << V_46 ;
else
V_48 |= 1 << V_46 ;
}
}
F_10 ( V_17 | F_39 ( ( 1 << V_2 -> V_19 ) - 1 ) ,
V_2 -> V_14 + V_24 ) ;
F_20 ( & V_40 -> V_40 , L_5 ,
V_47 , V_48 ) ;
V_2 -> V_7 = 0 ;
if ( V_47 ) {
V_2 -> V_23 = & V_50 ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
V_46 = F_40 ( & V_50 , V_52 ) ;
F_20 ( & V_40 -> V_40 , L_6 , V_46 ) ;
F_10 ( F_11 ( V_47 )
| F_12 ( V_47 ) ,
V_2 -> V_14 + V_18 ) ;
F_10 ( F_11 ( V_47 )
| F_12 ( V_47 ) ,
V_2 -> V_14 + V_24 ) ;
F_3 ( & V_2 -> V_6 , V_5 ) ;
V_2 -> V_23 = NULL ;
V_2 -> V_7 ^= V_47 & V_2 -> V_7 ;
}
V_2 -> V_7 |= V_48 ;
if ( V_2 -> V_7 )
F_4 ( & V_2 -> V_9 ) ;
F_5 ( & V_2 -> V_6 , V_5 ) ;
F_10 ( V_17 ,
V_2 -> V_14 + V_24 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return 0 ;
}
static int F_42 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
if ( ( ( V_2 -> V_19 == 4 ) && ( V_4 -> V_8 == 2 ) )
|| ( ( V_2 -> V_19 == 2 ) && ( V_4 -> V_8 == 0 ) ) )
return 1 ;
return 0 ;
}
static int F_43 ( struct V_44 * V_40 ,
const struct V_53 * V_11 )
{
struct V_1 * V_2 ;
int V_54 = 0 ;
int V_46 ;
V_46 = F_44 ( V_40 , F_45 ( 32 ) ) ;
if ( V_46 )
return V_46 ;
V_46 = F_37 ( V_40 ) ;
if ( V_46 )
return V_46 ;
F_38 ( V_40 ) ;
V_46 = F_46 ( V_40 , V_55 ) ;
if ( V_46 ) {
V_54 = 1 ;
goto V_56;
}
F_47 ( V_40 , 1 ) ;
V_2 = F_48 ( V_40 -> V_57 == V_58
? 4 : 2 , & V_40 -> V_40 ) ;
if ( ! V_2 ) {
V_46 = - V_59 ;
goto V_60;
}
F_49 ( & V_2 -> V_9 , F_18 ) ;
V_2 -> V_61 = F_2 ;
V_2 -> V_62 = F_42 ;
F_50 ( V_40 , V_2 ) ;
V_2 -> V_14 = F_51 ( V_40 , 0 ) ;
if ( ! V_2 -> V_14 ) {
V_46 = - V_63 ;
goto V_64;
}
V_46 = F_52 ( V_40 -> V_10 , F_6 , V_65 , V_55 , V_2 ) ;
if ( V_46 )
goto V_66;
V_46 = F_53 ( V_2 ) ;
if ( V_46 )
goto V_67;
F_10 ( V_17 | F_39 ( ( 1 << V_2 -> V_19 ) - 1 ) ,
V_2 -> V_14 + V_18 ) ;
F_10 ( V_17 | F_39 ( ( 1 << V_2 -> V_19 ) - 1 ) ,
V_2 -> V_14 + V_24 ) ;
return 0 ;
V_67:
F_54 ( V_40 -> V_10 , V_2 ) ;
V_66:
F_55 ( V_2 -> V_14 ) ;
V_64:
F_56 ( V_2 ) ;
V_60:
F_47 ( V_40 , 0 ) ;
F_57 ( V_40 ) ;
V_56:
if ( ! V_54 )
F_32 ( V_40 ) ;
return V_46 ;
}
static void F_58 ( struct V_44 * V_40 )
{
struct V_1 * V_2 = F_28 ( V_40 ) ;
int V_13 ;
V_2 -> V_61 = F_1 ;
V_2 -> V_62 = F_41 ;
F_10 ( V_68 , V_2 -> V_14 + V_18 ) ;
F_59 () ;
F_54 ( V_40 -> V_10 , V_2 ) ;
F_60 ( V_2 ) ;
for ( V_13 = 0 ; V_13 < V_2 -> V_19 ; V_13 ++ )
F_16 ( F_17 ( V_2 -> V_14 , V_13 ) ) ;
F_55 ( V_2 -> V_14 ) ;
F_47 ( V_40 , 0 ) ;
F_57 ( V_40 ) ;
F_32 ( V_40 ) ;
F_56 ( V_2 ) ;
}
