static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( struct V_5 * V_6 , T_1 V_7 ,
T_2 V_8 )
{
return F_4 ( V_6 , V_7 , F_5 ( V_8 ) ) ;
}
static inline int F_6 ( struct V_5 * V_6 , T_1 V_7 )
{
T_3 V_9 = F_7 ( V_6 , V_7 ) ;
return V_9 < 0 ? V_9 : F_5 ( V_9 ) ;
}
static int F_8 ( struct V_5 * V_6 , T_1 V_7 ,
T_2 V_10 , T_2 V_8 )
{
unsigned int V_11 ;
int V_9 ;
V_9 = F_6 ( V_6 , V_7 ) ;
if ( V_9 < 0 )
return V_9 ;
V_11 = V_9 & ~ V_10 ;
V_11 |= V_8 & V_10 ;
return F_3 ( V_6 , V_7 , V_11 ) ;
}
static inline int F_9 ( struct V_1 * V_4 )
{
return F_8 ( V_4 -> V_6 , V_12 ,
V_13 ,
~ V_13 ) ;
}
static inline int F_10 ( struct V_1 * V_4 )
{
return F_8 ( V_4 -> V_6 , V_12 ,
V_13 ,
V_13 ) ;
}
static int F_11 ( struct V_1 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
int V_9 ;
T_2 V_8 ;
if ( V_15 -> V_16 ) {
V_8 = V_15 -> V_16 & V_17 ;
V_9 = F_3 ( V_4 -> V_6 ,
V_18 , V_8 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_4 -> V_6 -> V_19 ,
L_1 ,
V_9 ) ;
return V_9 ;
}
}
if ( V_15 -> V_20 ) {
V_8 = V_15 -> V_20 & V_21 ;
V_9 = F_3 ( V_4 -> V_6 ,
V_22 , V_8 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_4 -> V_6 -> V_19 ,
L_2 ,
V_9 ) ;
return V_9 ;
}
}
if ( V_15 -> V_23 ) {
V_8 = V_15 -> V_23 & V_24 ;
V_9 = F_3 ( V_4 -> V_6 ,
V_25 , V_8 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_4 -> V_6 -> V_19 ,
L_3 ,
V_9 ) ;
return V_9 ;
}
}
return 0 ;
}
static bool F_13 ( struct V_1 * V_4 )
{
struct V_14 * V_15 = V_4 -> V_15 ;
int V_9 ;
if ( V_15 -> V_26 ) {
V_9 = F_14 ( V_15 -> V_27 ) ;
return V_9 ^= V_15 -> V_28 == 0 ;
} else {
int V_29 = 0 ;
V_29 = F_6 ( V_4 -> V_6 , V_12 ) ;
if ( V_29 < 0 ) {
F_12 ( & V_4 -> V_6 -> V_19 ,
L_4 ,
V_29 ) ;
return false ;
}
return ( V_29 & V_30 ) ? true : false ;
}
return false ;
}
static T_4 F_15 ( int V_31 , void * V_32 )
{
struct V_2 * V_3 = V_32 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_13 ( V_4 ) )
F_9 ( V_4 ) ;
else
F_10 ( V_4 ) ;
F_16 ( V_3 ) ;
return V_33 ;
}
static int F_17 ( struct V_2 * V_3 ,
enum V_34 V_35 ,
union V_36 * V_37 )
{
struct V_1 * V_4 ;
V_4 = F_2 ( V_3 , struct V_1 , V_4 ) ;
switch ( V_35 ) {
case V_38 :
V_37 -> V_39 = F_13 ( V_4 ) ? 1 : 0 ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static struct V_14 * F_18 ( struct V_5 * V_6 )
{
struct V_14 * V_15 ;
struct V_41 * V_42 = V_6 -> V_19 . V_43 ;
T_5 V_37 ;
int V_9 ;
enum V_44 V_45 ;
V_15 = F_19 ( & V_6 -> V_19 , sizeof( * V_15 ) , V_46 ) ;
if ( ! V_15 ) {
F_12 ( & V_6 -> V_19 ,
L_5 ) ;
return NULL ;
}
V_15 -> V_27 = F_20 ( V_42 , L_6 ,
0 , & V_45 ) ;
if ( V_45 & V_47 )
V_15 -> V_28 = 1 ;
V_9 = F_21 ( V_42 , L_7 , & V_37 ) ;
if ( ! V_9 )
V_15 -> V_16 = V_37 ;
V_9 = F_21 ( V_42 , L_8 , & V_37 ) ;
if ( ! V_9 )
V_15 -> V_20 = V_37 ;
V_9 = F_21 ( V_42 , L_9 , & V_37 ) ;
if ( ! V_9 )
V_15 -> V_23 = V_37 ;
return V_15 ;
}
static int F_22 ( struct V_5 * V_6 ,
const struct V_48 * V_49 )
{
int V_9 ;
struct V_1 * V_4 ;
struct V_2 * V_50 ;
char * V_51 ;
V_4 = F_19 ( & V_6 -> V_19 , sizeof( * V_4 ) , V_46 ) ;
if ( ! V_4 )
return - V_52 ;
V_4 -> V_15 = V_6 -> V_19 . V_53 ;
if ( F_23 ( V_54 ) && ! V_4 -> V_15 && V_6 -> V_19 . V_43 )
V_4 -> V_15 = F_18 ( V_6 ) ;
if ( ! V_4 -> V_15 ) {
F_12 ( & V_6 -> V_19 , L_10 ) ;
return - V_40 ;
}
V_51 = ( char * ) V_4 -> V_15 -> V_51 ;
if ( ! V_51 ) {
V_51 = F_24 ( V_46 , L_11 ,
F_25 ( & V_6 -> V_19 ) ) ;
if ( ! V_51 ) {
F_12 ( & V_6 -> V_19 , L_12 ) ;
return - V_52 ;
}
}
V_4 -> V_6 = V_6 ;
V_50 = & V_4 -> V_4 ;
V_50 -> V_51 = V_51 ;
V_50 -> type = V_55 ;
V_50 -> V_56 = V_57 ;
V_50 -> V_58 = F_26 ( V_57 ) ;
V_50 -> V_59 = F_17 ;
V_50 -> V_60 = V_4 -> V_15 -> V_60 ;
V_50 -> V_61 = V_4 -> V_15 -> V_61 ;
V_50 -> V_43 = V_6 -> V_19 . V_43 ;
F_27 ( V_6 , V_4 ) ;
V_9 = F_6 ( V_6 , V_62 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_6 -> V_19 , L_13 ,
V_9 ) ;
goto V_63;
} else if ( V_9 != 0x0040 ) {
F_12 ( & V_6 -> V_19 ,
L_14 , V_9 ) ;
V_9 = - V_64 ;
goto V_63;
}
V_9 = F_6 ( V_6 , V_65 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_6 -> V_19 , L_15 , V_9 ) ;
goto V_63;
} else if ( V_9 != 0x000B ) {
F_12 ( & V_6 -> V_19 ,
L_16 , V_9 ) ;
V_9 = - V_64 ;
goto V_63;
}
if ( F_28 ( V_4 -> V_15 -> V_27 ) ) {
V_9 = F_29 ( & V_6 -> V_19 ,
V_4 -> V_15 -> V_27 ,
V_51 ) ;
if ( V_9 ) {
F_12 ( & V_6 -> V_19 ,
L_17 ,
V_4 -> V_15 -> V_27 , V_9 ) ;
}
V_4 -> V_15 -> V_26 = ! V_9 ;
}
V_9 = F_11 ( V_4 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_6 -> V_19 , L_18 ) ;
goto V_63;
}
if ( F_13 ( V_4 ) ) {
V_9 = F_9 ( V_4 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_6 -> V_19 , L_19 ) ;
goto V_63;
}
}
V_9 = F_30 ( & V_6 -> V_19 , V_50 ) ;
if ( V_9 < 0 ) {
F_12 ( & V_6 -> V_19 , L_20 ,
V_9 ) ;
goto V_63;
}
if ( V_6 -> V_31 ) {
V_9 = F_31 ( & V_6 -> V_19 , V_6 -> V_31 ,
NULL , F_15 ,
V_66 |
V_67 |
V_68 ,
V_50 -> V_51 , V_50 ) ;
if ( V_9 ) {
F_12 ( & V_6 -> V_19 ,
L_21 ,
V_6 -> V_31 , V_9 ) ;
goto V_69;
}
}
return 0 ;
V_69:
F_32 ( V_50 ) ;
V_63:
if ( V_51 != V_4 -> V_15 -> V_51 )
F_33 ( V_51 ) ;
return V_9 ;
}
static int F_34 ( struct V_5 * V_6 )
{
struct V_1 * V_4 = F_35 ( V_6 ) ;
if ( V_4 -> V_6 -> V_31 )
F_36 ( & V_4 -> V_6 -> V_19 , V_4 -> V_6 -> V_31 ,
& V_4 -> V_4 ) ;
F_32 ( & V_4 -> V_4 ) ;
if ( V_4 -> V_4 . V_51 != V_4 -> V_15 -> V_51 )
F_33 ( V_4 -> V_4 . V_51 ) ;
return 0 ;
}
