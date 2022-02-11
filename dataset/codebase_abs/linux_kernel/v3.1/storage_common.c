static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( T_2 * V_4 )
{
return 0xffffff & ( T_1 ) F_4 ( V_4 - 1 ) ;
}
static int F_5 ( struct V_1 * V_5 , const char * V_6 )
{
int V_7 ;
struct V_8 * V_9 = NULL ;
int V_10 = - V_11 ;
struct V_12 * V_12 = NULL ;
T_3 V_13 ;
T_3 V_14 ;
T_3 V_15 ;
V_7 = V_5 -> V_16 ;
if ( ! V_7 ) {
V_9 = F_6 ( V_6 , V_17 | V_18 , 0 ) ;
if ( F_7 ( V_9 ) == - V_19 || F_7 ( V_9 ) == - V_20 )
V_7 = 1 ;
}
if ( V_7 )
V_9 = F_6 ( V_6 , V_21 | V_18 , 0 ) ;
if ( F_8 ( V_9 ) ) {
F_9 ( V_5 , L_1 , V_6 ) ;
return F_7 ( V_9 ) ;
}
if ( ! ( V_9 -> V_22 & V_23 ) )
V_7 = 1 ;
if ( V_9 -> V_24 . V_25 )
V_12 = V_9 -> V_24 . V_25 -> V_26 ;
if ( ! V_12 || ( ! F_10 ( V_12 -> V_27 ) && ! F_11 ( V_12 -> V_27 ) ) ) {
F_9 ( V_5 , L_2 , V_6 ) ;
goto V_28;
}
if ( ! V_9 -> V_29 || ! ( V_9 -> V_29 -> V_30 || V_9 -> V_29 -> V_31 ) ) {
F_9 ( V_5 , L_3 , V_6 ) ;
goto V_28;
}
if ( ! ( V_9 -> V_29 -> V_32 || V_9 -> V_29 -> V_33 ) )
V_7 = 1 ;
V_13 = F_12 ( V_12 -> V_34 -> V_35 ) ;
if ( V_13 < 0 ) {
F_9 ( V_5 , L_4 , V_6 ) ;
V_10 = ( int ) V_13 ;
goto V_28;
}
V_14 = V_13 >> 9 ;
V_15 = 1 ;
if ( V_5 -> V_36 ) {
V_14 &= ~ 3 ;
V_15 = 300 * 4 ;
if ( V_14 >= 256 * 60 * 75 * 4 ) {
V_14 = ( 256 * 60 * 75 - 1 ) * 4 ;
F_9 ( V_5 , L_5 , V_6 ) ;
F_9 ( V_5 , L_6 ,
( int ) V_14 ) ;
}
}
if ( V_14 < V_15 ) {
F_9 ( V_5 , L_7 , V_6 ) ;
V_10 = - V_37 ;
goto V_28;
}
F_13 ( V_9 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> V_9 = V_9 ;
V_5 -> V_38 = V_13 ;
V_5 -> V_14 = V_14 ;
F_14 ( V_5 , L_8 , V_6 ) ;
V_10 = 0 ;
V_28:
F_15 ( V_9 , V_39 -> V_40 ) ;
return V_10 ;
}
static void F_16 ( struct V_1 * V_5 )
{
if ( V_5 -> V_9 ) {
F_14 ( V_5 , L_9 ) ;
F_17 ( V_5 -> V_9 ) ;
V_5 -> V_9 = NULL ;
}
}
static int F_18 ( struct V_1 * V_5 )
{
struct V_8 * V_9 = V_5 -> V_9 ;
if ( V_5 -> V_7 || ! V_9 )
return 0 ;
return F_19 ( V_9 , 1 ) ;
}
static void F_20 ( T_2 * V_41 , int V_42 , T_1 V_43 )
{
if ( V_42 ) {
V_43 >>= 2 ;
V_43 += 2 * 75 ;
V_41 [ 3 ] = V_43 % 75 ;
V_43 /= 75 ;
V_41 [ 2 ] = V_43 % 60 ;
V_43 /= 60 ;
V_41 [ 1 ] = V_43 ;
V_41 [ 0 ] = 0 ;
} else {
F_21 ( V_43 , V_41 ) ;
}
}
static T_4 F_22 ( struct V_2 * V_3 , struct V_44 * V_45 ,
char * V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return sprintf ( V_4 , L_10 , F_23 ( V_5 )
? V_5 -> V_7
: V_5 -> V_16 ) ;
}
static T_4 F_24 ( struct V_2 * V_3 , struct V_44 * V_45 ,
char * V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return sprintf ( V_4 , L_11 , V_5 -> V_46 ) ;
}
static T_4 F_25 ( struct V_2 * V_3 , struct V_44 * V_45 ,
char * V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_47 * V_48 = F_26 ( V_3 ) ;
char * V_49 ;
T_4 V_10 ;
F_27 ( V_48 ) ;
if ( F_23 ( V_5 ) ) {
V_49 = F_28 ( & V_5 -> V_9 -> V_24 , V_4 , V_50 - 1 ) ;
if ( F_8 ( V_49 ) )
V_10 = F_7 ( V_49 ) ;
else {
V_10 = strlen ( V_49 ) ;
memmove ( V_4 , V_49 , V_10 ) ;
V_4 [ V_10 ] = '\n' ;
V_4 [ ++ V_10 ] = 0 ;
}
} else {
* V_4 = 0 ;
V_10 = 0 ;
}
F_29 ( V_48 ) ;
return V_10 ;
}
static T_4 F_30 ( struct V_2 * V_3 , struct V_44 * V_45 ,
const char * V_4 , T_5 V_51 )
{
T_4 V_10 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_47 * V_48 = F_26 ( V_3 ) ;
unsigned V_7 ;
V_10 = F_31 ( V_4 , 2 , & V_7 ) ;
if ( V_10 )
return V_10 ;
F_27 ( V_48 ) ;
if ( F_23 ( V_5 ) ) {
F_14 ( V_5 , L_12 ) ;
V_10 = - V_52 ;
} else {
V_5 -> V_7 = V_7 ;
V_5 -> V_16 = V_7 ;
F_14 ( V_5 , L_13 , V_5 -> V_7 ) ;
V_10 = V_51 ;
}
F_29 ( V_48 ) ;
return V_10 ;
}
static T_4 F_32 ( struct V_2 * V_3 ,
struct V_44 * V_45 ,
const char * V_4 , T_5 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
unsigned V_46 ;
int V_53 ;
V_53 = F_31 ( V_4 , 2 , & V_46 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_46 && V_5 -> V_46 )
F_18 ( V_5 ) ;
V_5 -> V_46 = V_46 ;
return V_51 ;
}
static T_4 F_33 ( struct V_2 * V_3 , struct V_44 * V_45 ,
const char * V_4 , T_5 V_51 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_47 * V_48 = F_26 ( V_3 ) ;
int V_10 = 0 ;
if ( V_5 -> V_54 && F_23 ( V_5 ) ) {
F_14 ( V_5 , L_14 ) ;
return - V_52 ;
}
if ( V_51 > 0 && V_4 [ V_51 - 1 ] == '\n' )
( ( char * ) V_4 ) [ V_51 - 1 ] = 0 ;
F_34 ( V_48 ) ;
if ( F_23 ( V_5 ) ) {
F_16 ( V_5 ) ;
V_5 -> V_55 = V_56 ;
}
if ( V_51 > 0 && V_4 [ 0 ] ) {
V_10 = F_5 ( V_5 , V_4 ) ;
if ( V_10 == 0 )
V_5 -> V_55 =
V_57 ;
}
F_35 ( V_48 ) ;
return ( V_10 < 0 ? V_10 : V_51 ) ;
}
