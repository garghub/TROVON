static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( T_2 * V_4 )
{
return 0xffffff & ( T_1 ) F_4 ( V_4 - 1 ) ;
}
static struct V_5 *
F_5 ( struct V_6 * V_7 , struct V_5 * V_8 ,
struct V_5 * V_9 )
{
if ( F_6 ( V_7 ) && V_7 -> V_10 == V_11 )
return V_9 ;
return V_8 ;
}
static int F_7 ( struct V_1 * V_12 , const char * V_13 )
{
int V_14 ;
struct V_15 * V_16 = NULL ;
int V_17 = - V_18 ;
struct V_19 * V_19 = NULL ;
T_3 V_20 ;
T_3 V_21 ;
T_3 V_22 ;
V_14 = V_12 -> V_23 ;
if ( ! V_14 ) {
V_16 = F_8 ( V_13 , V_24 | V_25 , 0 ) ;
if ( F_9 ( V_16 ) == - V_26 || F_9 ( V_16 ) == - V_27 )
V_14 = 1 ;
}
if ( V_14 )
V_16 = F_8 ( V_13 , V_28 | V_25 , 0 ) ;
if ( F_10 ( V_16 ) ) {
F_11 ( V_12 , L_1 , V_13 ) ;
return F_9 ( V_16 ) ;
}
if ( ! ( V_16 -> V_29 & V_30 ) )
V_14 = 1 ;
if ( V_16 -> V_31 . V_32 )
V_19 = V_16 -> V_31 . V_32 -> V_33 ;
if ( ! V_19 || ( ! F_12 ( V_19 -> V_34 ) && ! F_13 ( V_19 -> V_34 ) ) ) {
F_11 ( V_12 , L_2 , V_13 ) ;
goto V_35;
}
if ( ! V_16 -> V_36 || ! ( V_16 -> V_36 -> V_37 || V_16 -> V_36 -> V_38 ) ) {
F_11 ( V_12 , L_3 , V_13 ) ;
goto V_35;
}
if ( ! ( V_16 -> V_36 -> V_39 || V_16 -> V_36 -> V_40 ) )
V_14 = 1 ;
V_20 = F_14 ( V_19 -> V_41 -> V_42 ) ;
if ( V_20 < 0 ) {
F_11 ( V_12 , L_4 , V_13 ) ;
V_17 = ( int ) V_20 ;
goto V_35;
}
V_21 = V_20 >> 9 ;
V_22 = 1 ;
if ( V_12 -> V_43 ) {
V_21 &= ~ 3 ;
V_22 = 300 * 4 ;
if ( V_21 >= 256 * 60 * 75 * 4 ) {
V_21 = ( 256 * 60 * 75 - 1 ) * 4 ;
F_11 ( V_12 , L_5 , V_13 ) ;
F_11 ( V_12 , L_6 ,
( int ) V_21 ) ;
}
}
if ( V_21 < V_22 ) {
F_11 ( V_12 , L_7 , V_13 ) ;
V_17 = - V_44 ;
goto V_35;
}
F_15 ( V_16 ) ;
V_12 -> V_14 = V_14 ;
V_12 -> V_16 = V_16 ;
V_12 -> V_45 = V_20 ;
V_12 -> V_21 = V_21 ;
F_16 ( V_12 , L_8 , V_13 ) ;
V_17 = 0 ;
V_35:
F_17 ( V_16 , V_46 -> V_47 ) ;
return V_17 ;
}
static void F_18 ( struct V_1 * V_12 )
{
if ( V_12 -> V_16 ) {
F_16 ( V_12 , L_9 ) ;
F_19 ( V_12 -> V_16 ) ;
V_12 -> V_16 = NULL ;
}
}
static int F_20 ( struct V_1 * V_12 )
{
struct V_15 * V_16 = V_12 -> V_16 ;
if ( V_12 -> V_14 || ! V_16 )
return 0 ;
return F_21 ( V_16 , 1 ) ;
}
static void F_22 ( T_2 * V_48 , int V_49 , T_1 V_50 )
{
if ( V_49 ) {
V_50 >>= 2 ;
V_50 += 2 * 75 ;
V_48 [ 3 ] = V_50 % 75 ;
V_50 /= 75 ;
V_48 [ 2 ] = V_50 % 60 ;
V_50 /= 60 ;
V_48 [ 1 ] = V_50 ;
V_48 [ 0 ] = 0 ;
} else {
F_23 ( V_50 , V_48 ) ;
}
}
static T_4 F_24 ( struct V_2 * V_3 , struct V_51 * V_52 ,
char * V_4 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return sprintf ( V_4 , L_10 , F_25 ( V_12 )
? V_12 -> V_14
: V_12 -> V_23 ) ;
}
static T_4 F_26 ( struct V_2 * V_3 , struct V_51 * V_52 ,
char * V_4 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return sprintf ( V_4 , L_11 , V_12 -> V_53 ) ;
}
static T_4 F_27 ( struct V_2 * V_3 , struct V_51 * V_52 ,
char * V_4 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_54 * V_55 = F_28 ( V_3 ) ;
char * V_56 ;
T_4 V_17 ;
F_29 ( V_55 ) ;
if ( F_25 ( V_12 ) ) {
V_56 = F_30 ( & V_12 -> V_16 -> V_31 , V_4 , V_57 - 1 ) ;
if ( F_10 ( V_56 ) )
V_17 = F_9 ( V_56 ) ;
else {
V_17 = strlen ( V_56 ) ;
memmove ( V_4 , V_56 , V_17 ) ;
V_4 [ V_17 ] = '\n' ;
V_4 [ ++ V_17 ] = 0 ;
}
} else {
* V_4 = 0 ;
V_17 = 0 ;
}
F_31 ( V_55 ) ;
return V_17 ;
}
static T_4 F_32 ( struct V_2 * V_3 , struct V_51 * V_52 ,
const char * V_4 , T_5 V_58 )
{
T_4 V_17 ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_54 * V_55 = F_28 ( V_3 ) ;
unsigned V_14 ;
V_17 = F_33 ( V_4 , 2 , & V_14 ) ;
if ( V_17 )
return V_17 ;
F_29 ( V_55 ) ;
if ( F_25 ( V_12 ) ) {
F_16 ( V_12 , L_12 ) ;
V_17 = - V_59 ;
} else {
V_12 -> V_14 = V_14 ;
V_12 -> V_23 = V_14 ;
F_16 ( V_12 , L_13 , V_12 -> V_14 ) ;
V_17 = V_58 ;
}
F_31 ( V_55 ) ;
return V_17 ;
}
static T_4 F_34 ( struct V_2 * V_3 ,
struct V_51 * V_52 ,
const char * V_4 , T_5 V_58 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
unsigned V_53 ;
int V_60 ;
V_60 = F_33 ( V_4 , 2 , & V_53 ) ;
if ( V_60 )
return V_60 ;
if ( ! V_53 && V_12 -> V_53 )
F_20 ( V_12 ) ;
V_12 -> V_53 = V_53 ;
return V_58 ;
}
static T_4 F_35 ( struct V_2 * V_3 , struct V_51 * V_52 ,
const char * V_4 , T_5 V_58 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
struct V_54 * V_55 = F_28 ( V_3 ) ;
int V_17 = 0 ;
if ( V_12 -> V_61 && F_25 ( V_12 ) ) {
F_16 ( V_12 , L_14 ) ;
return - V_59 ;
}
if ( V_58 > 0 && V_4 [ V_58 - 1 ] == '\n' )
( ( char * ) V_4 ) [ V_58 - 1 ] = 0 ;
F_36 ( V_55 ) ;
if ( F_25 ( V_12 ) ) {
F_18 ( V_12 ) ;
V_12 -> V_62 = V_63 ;
}
if ( V_58 > 0 && V_4 [ 0 ] ) {
V_17 = F_7 ( V_12 , V_4 ) ;
if ( V_17 == 0 )
V_12 -> V_62 =
V_64 ;
}
F_37 ( V_55 ) ;
return ( V_17 < 0 ? V_17 : V_58 ) ;
}
