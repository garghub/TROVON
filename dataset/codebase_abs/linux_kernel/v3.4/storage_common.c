static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline int F_3 ( void )
{
if ( V_4 >= 2 && V_4 <= 4 )
return 0 ;
F_4 ( L_1 ,
V_4 , 2 , 4 ) ;
return - V_5 ;
}
static inline T_1 F_5 ( T_2 * V_6 )
{
return 0xffffff & ( T_1 ) F_6 ( V_6 - 1 ) ;
}
static int F_7 ( struct V_1 * V_7 , const char * V_8 )
{
int V_9 ;
struct V_10 * V_11 = NULL ;
int V_12 = - V_5 ;
struct V_13 * V_13 = NULL ;
T_3 V_14 ;
T_3 V_15 ;
T_3 V_16 ;
V_9 = V_7 -> V_17 ;
if ( ! V_9 ) {
V_11 = F_8 ( V_8 , V_18 | V_19 , 0 ) ;
if ( F_9 ( V_11 ) == - V_20 || F_9 ( V_11 ) == - V_21 )
V_9 = 1 ;
}
if ( V_9 )
V_11 = F_8 ( V_8 , V_22 | V_19 , 0 ) ;
if ( F_10 ( V_11 ) ) {
F_11 ( V_7 , L_2 , V_8 ) ;
return F_9 ( V_11 ) ;
}
if ( ! ( V_11 -> V_23 & V_24 ) )
V_9 = 1 ;
if ( V_11 -> V_25 . V_26 )
V_13 = V_11 -> V_25 . V_26 -> V_27 ;
if ( ! V_13 || ( ! F_12 ( V_13 -> V_28 ) && ! F_13 ( V_13 -> V_28 ) ) ) {
F_11 ( V_7 , L_3 , V_8 ) ;
goto V_29;
}
if ( ! V_11 -> V_30 || ! ( V_11 -> V_30 -> V_31 || V_11 -> V_30 -> V_32 ) ) {
F_11 ( V_7 , L_4 , V_8 ) ;
goto V_29;
}
if ( ! ( V_11 -> V_30 -> V_33 || V_11 -> V_30 -> V_34 ) )
V_9 = 1 ;
V_14 = F_14 ( V_13 -> V_35 -> V_36 ) ;
if ( V_14 < 0 ) {
F_11 ( V_7 , L_5 , V_8 ) ;
V_12 = ( int ) V_14 ;
goto V_29;
}
if ( V_7 -> V_37 ) {
V_7 -> V_38 = 2048 ;
V_7 -> V_39 = 11 ;
} else if ( V_13 -> V_40 ) {
V_7 -> V_38 = F_15 ( V_13 -> V_40 ) ;
V_7 -> V_39 = F_16 ( V_7 -> V_38 ) ;
} else {
V_7 -> V_38 = 512 ;
V_7 -> V_39 = 9 ;
}
V_15 = V_14 >> V_7 -> V_39 ;
V_16 = 1 ;
if ( V_7 -> V_37 ) {
V_16 = 300 ;
if ( V_15 >= 256 * 60 * 75 ) {
V_15 = 256 * 60 * 75 - 1 ;
F_11 ( V_7 , L_6 , V_8 ) ;
F_11 ( V_7 , L_7 ,
( int ) V_15 ) ;
}
}
if ( V_15 < V_16 ) {
F_11 ( V_7 , L_8 , V_8 ) ;
V_12 = - V_41 ;
goto V_29;
}
F_17 ( V_11 ) ;
V_7 -> V_9 = V_9 ;
V_7 -> V_11 = V_11 ;
V_7 -> V_42 = V_14 ;
V_7 -> V_15 = V_15 ;
F_18 ( V_7 , L_9 , V_8 ) ;
V_12 = 0 ;
V_29:
F_19 ( V_11 , V_43 -> V_44 ) ;
return V_12 ;
}
static void F_20 ( struct V_1 * V_7 )
{
if ( V_7 -> V_11 ) {
F_18 ( V_7 , L_10 ) ;
F_21 ( V_7 -> V_11 ) ;
V_7 -> V_11 = NULL ;
}
}
static int F_22 ( struct V_1 * V_7 )
{
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_7 -> V_9 || ! V_11 )
return 0 ;
return F_23 ( V_11 , 1 ) ;
}
static void F_24 ( T_2 * V_45 , int V_46 , T_1 V_47 )
{
if ( V_46 ) {
V_47 >>= 2 ;
V_47 += 2 * 75 ;
V_45 [ 3 ] = V_47 % 75 ;
V_47 /= 75 ;
V_45 [ 2 ] = V_47 % 60 ;
V_47 /= 60 ;
V_45 [ 1 ] = V_47 ;
V_45 [ 0 ] = 0 ;
} else {
F_25 ( V_47 , V_45 ) ;
}
}
static T_4 F_26 ( struct V_2 * V_3 , struct V_48 * V_49 ,
char * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return sprintf ( V_6 , L_11 , F_27 ( V_7 )
? V_7 -> V_9
: V_7 -> V_17 ) ;
}
static T_4 F_28 ( struct V_2 * V_3 , struct V_48 * V_49 ,
char * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
return sprintf ( V_6 , L_12 , V_7 -> V_50 ) ;
}
static T_4 F_29 ( struct V_2 * V_3 , struct V_48 * V_49 ,
char * V_6 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_51 * V_52 = F_30 ( V_3 ) ;
char * V_53 ;
T_4 V_12 ;
F_31 ( V_52 ) ;
if ( F_27 ( V_7 ) ) {
V_53 = F_32 ( & V_7 -> V_11 -> V_25 , V_6 , V_54 - 1 ) ;
if ( F_10 ( V_53 ) )
V_12 = F_9 ( V_53 ) ;
else {
V_12 = strlen ( V_53 ) ;
memmove ( V_6 , V_53 , V_12 ) ;
V_6 [ V_12 ] = '\n' ;
V_6 [ ++ V_12 ] = 0 ;
}
} else {
* V_6 = 0 ;
V_12 = 0 ;
}
F_33 ( V_52 ) ;
return V_12 ;
}
static T_4 F_34 ( struct V_2 * V_3 , struct V_48 * V_49 ,
const char * V_6 , T_5 V_55 )
{
T_4 V_12 ;
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_51 * V_52 = F_30 ( V_3 ) ;
unsigned V_9 ;
V_12 = F_35 ( V_6 , 2 , & V_9 ) ;
if ( V_12 )
return V_12 ;
F_31 ( V_52 ) ;
if ( F_27 ( V_7 ) ) {
F_18 ( V_7 , L_13 ) ;
V_12 = - V_56 ;
} else {
V_7 -> V_9 = V_9 ;
V_7 -> V_17 = V_9 ;
F_18 ( V_7 , L_14 , V_7 -> V_9 ) ;
V_12 = V_55 ;
}
F_33 ( V_52 ) ;
return V_12 ;
}
static T_4 F_36 ( struct V_2 * V_3 ,
struct V_48 * V_49 ,
const char * V_6 , T_5 V_55 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
unsigned V_50 ;
int V_57 ;
V_57 = F_35 ( V_6 , 2 , & V_50 ) ;
if ( V_57 )
return V_57 ;
if ( ! V_50 && V_7 -> V_50 )
F_22 ( V_7 ) ;
V_7 -> V_50 = V_50 ;
return V_55 ;
}
static T_4 F_37 ( struct V_2 * V_3 , struct V_48 * V_49 ,
const char * V_6 , T_5 V_55 )
{
struct V_1 * V_7 = F_1 ( V_3 ) ;
struct V_51 * V_52 = F_30 ( V_3 ) ;
int V_12 = 0 ;
if ( V_7 -> V_58 && F_27 ( V_7 ) ) {
F_18 ( V_7 , L_15 ) ;
return - V_56 ;
}
if ( V_55 > 0 && V_6 [ V_55 - 1 ] == '\n' )
( ( char * ) V_6 ) [ V_55 - 1 ] = 0 ;
F_38 ( V_52 ) ;
if ( F_27 ( V_7 ) ) {
F_20 ( V_7 ) ;
V_7 -> V_59 = V_60 ;
}
if ( V_55 > 0 && V_6 [ 0 ] ) {
V_12 = F_7 ( V_7 , V_6 ) ;
if ( V_12 == 0 )
V_7 -> V_59 =
V_61 ;
}
F_39 ( V_52 ) ;
return ( V_12 < 0 ? V_12 : V_55 ) ;
}
