static inline bool F_1 ( struct V_1 * V_2 )
{
return V_2 -> V_3 != NULL ;
}
static inline struct V_1 * F_2 ( struct V_4 * V_5 )
{
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static inline int F_4 ( void )
{
if ( V_6 >= 2 && V_6 <= 4 )
return 0 ;
F_5 ( L_1 ,
V_6 , 2 , 4 ) ;
return - V_7 ;
}
static inline T_1 F_6 ( T_2 * V_8 )
{
return 0xffffff & ( T_1 ) F_7 ( V_8 - 1 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 ) {
F_9 ( V_2 , L_2 ) ;
F_10 ( V_2 -> V_3 ) ;
V_2 -> V_3 = NULL ;
}
}
static int F_11 ( struct V_1 * V_2 , const char * V_9 )
{
int V_10 ;
struct V_11 * V_3 = NULL ;
int V_12 = - V_7 ;
struct V_13 * V_13 = NULL ;
T_3 V_14 ;
T_3 V_15 ;
T_3 V_16 ;
unsigned int V_17 ;
unsigned int V_18 ;
V_10 = V_2 -> V_19 ;
if ( ! V_10 ) {
V_3 = F_12 ( V_9 , V_20 | V_21 , 0 ) ;
if ( F_13 ( V_3 ) == - V_22 || F_13 ( V_3 ) == - V_23 )
V_10 = 1 ;
}
if ( V_10 )
V_3 = F_12 ( V_9 , V_24 | V_21 , 0 ) ;
if ( F_14 ( V_3 ) ) {
F_15 ( V_2 , L_3 , V_9 ) ;
return F_13 ( V_3 ) ;
}
if ( ! ( V_3 -> V_25 & V_26 ) )
V_10 = 1 ;
V_13 = F_16 ( V_3 ) ;
if ( ( ! F_17 ( V_13 -> V_27 ) && ! F_18 ( V_13 -> V_27 ) ) ) {
F_15 ( V_2 , L_4 , V_9 ) ;
goto V_28;
}
if ( ! ( V_3 -> V_29 -> V_30 || V_3 -> V_29 -> V_31 ) ) {
F_15 ( V_2 , L_5 , V_9 ) ;
goto V_28;
}
if ( ! ( V_3 -> V_29 -> V_32 || V_3 -> V_29 -> V_33 ) )
V_10 = 1 ;
V_14 = F_19 ( V_13 -> V_34 -> V_35 ) ;
if ( V_14 < 0 ) {
F_15 ( V_2 , L_6 , V_9 ) ;
V_12 = ( int ) V_14 ;
goto V_28;
}
if ( V_2 -> V_36 ) {
V_18 = 2048 ;
V_17 = 11 ;
} else if ( V_13 -> V_37 ) {
V_18 = F_20 ( V_13 -> V_37 ) ;
V_17 = F_21 ( V_18 ) ;
} else {
V_18 = 512 ;
V_17 = 9 ;
}
V_15 = V_14 >> V_17 ;
V_16 = 1 ;
if ( V_2 -> V_36 ) {
V_16 = 300 ;
if ( V_15 >= 256 * 60 * 75 ) {
V_15 = 256 * 60 * 75 - 1 ;
F_15 ( V_2 , L_7 , V_9 ) ;
F_15 ( V_2 , L_8 ,
( int ) V_15 ) ;
}
}
if ( V_15 < V_16 ) {
F_15 ( V_2 , L_9 , V_9 ) ;
V_12 = - V_38 ;
goto V_28;
}
if ( F_1 ( V_2 ) )
F_8 ( V_2 ) ;
V_2 -> V_18 = V_18 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_10 = V_10 ;
V_2 -> V_3 = V_3 ;
V_2 -> V_39 = V_14 ;
V_2 -> V_15 = V_15 ;
F_9 ( V_2 , L_10 , V_9 ) ;
return 0 ;
V_28:
F_10 ( V_3 ) ;
return V_12 ;
}
static int F_22 ( struct V_1 * V_2 )
{
struct V_11 * V_3 = V_2 -> V_3 ;
if ( V_2 -> V_10 || ! V_3 )
return 0 ;
return F_23 ( V_3 , 1 ) ;
}
static void F_24 ( T_2 * V_40 , int V_41 , T_1 V_42 )
{
if ( V_41 ) {
V_42 >>= 2 ;
V_42 += 2 * 75 ;
V_40 [ 3 ] = V_42 % 75 ;
V_42 /= 75 ;
V_40 [ 2 ] = V_42 % 60 ;
V_42 /= 60 ;
V_40 [ 1 ] = V_42 ;
V_40 [ 0 ] = 0 ;
} else {
F_25 ( V_42 , V_40 ) ;
}
}
static T_4 F_26 ( struct V_4 * V_5 , struct V_43 * V_44 ,
char * V_8 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
return sprintf ( V_8 , L_11 , F_1 ( V_2 )
? V_2 -> V_10
: V_2 -> V_19 ) ;
}
static T_4 F_27 ( struct V_4 * V_5 , struct V_43 * V_44 ,
char * V_8 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
return sprintf ( V_8 , L_12 , V_2 -> V_45 ) ;
}
static T_4 F_28 ( struct V_4 * V_5 , struct V_43 * V_44 ,
char * V_8 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
struct V_46 * V_47 = F_29 ( V_5 ) ;
char * V_48 ;
T_4 V_12 ;
F_30 ( V_47 ) ;
if ( F_1 ( V_2 ) ) {
V_48 = F_31 ( & V_2 -> V_3 -> V_49 , V_8 , V_50 - 1 ) ;
if ( F_14 ( V_48 ) )
V_12 = F_13 ( V_48 ) ;
else {
V_12 = strlen ( V_48 ) ;
memmove ( V_8 , V_48 , V_12 ) ;
V_8 [ V_12 ] = '\n' ;
V_8 [ ++ V_12 ] = 0 ;
}
} else {
* V_8 = 0 ;
V_12 = 0 ;
}
F_32 ( V_47 ) ;
return V_12 ;
}
static T_4 F_33 ( struct V_4 * V_5 , struct V_43 * V_44 ,
const char * V_8 , T_5 V_51 )
{
T_4 V_12 ;
struct V_1 * V_2 = F_2 ( V_5 ) ;
struct V_46 * V_47 = F_29 ( V_5 ) ;
unsigned V_10 ;
V_12 = F_34 ( V_8 , 2 , & V_10 ) ;
if ( V_12 )
return V_12 ;
F_30 ( V_47 ) ;
if ( F_1 ( V_2 ) ) {
F_9 ( V_2 , L_13 ) ;
V_12 = - V_52 ;
} else {
V_2 -> V_10 = V_10 ;
V_2 -> V_19 = V_10 ;
F_9 ( V_2 , L_14 , V_2 -> V_10 ) ;
V_12 = V_51 ;
}
F_32 ( V_47 ) ;
return V_12 ;
}
static T_4 F_35 ( struct V_4 * V_5 , struct V_43 * V_44 ,
const char * V_8 , T_5 V_51 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
unsigned V_45 ;
int V_53 ;
V_53 = F_34 ( V_8 , 2 , & V_45 ) ;
if ( V_53 )
return V_53 ;
if ( ! V_45 && V_2 -> V_45 )
F_22 ( V_2 ) ;
V_2 -> V_45 = V_45 ;
return V_51 ;
}
static T_4 F_36 ( struct V_4 * V_5 , struct V_43 * V_44 ,
const char * V_8 , T_5 V_51 )
{
struct V_1 * V_2 = F_2 ( V_5 ) ;
struct V_46 * V_47 = F_29 ( V_5 ) ;
int V_12 = 0 ;
if ( V_2 -> V_54 && F_1 ( V_2 ) ) {
F_9 ( V_2 , L_15 ) ;
return - V_52 ;
}
if ( V_51 > 0 && V_8 [ V_51 - 1 ] == '\n' )
( ( char * ) V_8 ) [ V_51 - 1 ] = 0 ;
F_37 ( V_47 ) ;
if ( V_51 > 0 && V_8 [ 0 ] ) {
V_12 = F_11 ( V_2 , V_8 ) ;
if ( V_12 == 0 )
V_2 -> V_55 =
V_56 ;
} else if ( F_1 ( V_2 ) ) {
F_8 ( V_2 ) ;
V_2 -> V_55 = V_57 ;
}
F_38 ( V_47 ) ;
return ( V_12 < 0 ? V_12 : V_51 ) ;
}
