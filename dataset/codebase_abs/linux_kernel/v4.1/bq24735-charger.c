static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) ;
}
static inline int F_3 ( struct V_4 * V_5 , T_1 V_6 ,
T_2 V_7 )
{
return F_4 ( V_5 , V_6 , F_5 ( V_7 ) ) ;
}
static inline int F_6 ( struct V_4 * V_5 , T_1 V_6 )
{
T_3 V_8 = F_7 ( V_5 , V_6 ) ;
return V_8 < 0 ? V_8 : F_5 ( V_8 ) ;
}
static int F_8 ( struct V_4 * V_5 , T_1 V_6 ,
T_2 V_9 , T_2 V_7 )
{
unsigned int V_10 ;
int V_8 ;
V_8 = F_6 ( V_5 , V_6 ) ;
if ( V_8 < 0 )
return V_8 ;
V_10 = V_8 & ~ V_9 ;
V_10 |= V_7 & V_9 ;
return F_3 ( V_5 , V_6 , V_10 ) ;
}
static inline int F_9 ( struct V_1 * V_11 )
{
return F_8 ( V_11 -> V_5 , V_12 ,
V_13 ,
~ V_13 ) ;
}
static inline int F_10 ( struct V_1 * V_11 )
{
return F_8 ( V_11 -> V_5 , V_12 ,
V_13 ,
V_13 ) ;
}
static int F_11 ( struct V_1 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
int V_8 ;
T_2 V_7 ;
if ( V_15 -> V_16 ) {
V_7 = V_15 -> V_16 & V_17 ;
V_8 = F_3 ( V_11 -> V_5 ,
V_18 , V_7 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_11 -> V_5 -> V_19 ,
L_1 ,
V_8 ) ;
return V_8 ;
}
}
if ( V_15 -> V_20 ) {
V_7 = V_15 -> V_20 & V_21 ;
V_8 = F_3 ( V_11 -> V_5 ,
V_22 , V_7 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_11 -> V_5 -> V_19 ,
L_2 ,
V_8 ) ;
return V_8 ;
}
}
if ( V_15 -> V_23 ) {
V_7 = V_15 -> V_23 & V_24 ;
V_8 = F_3 ( V_11 -> V_5 ,
V_25 , V_7 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_11 -> V_5 -> V_19 ,
L_3 ,
V_8 ) ;
return V_8 ;
}
}
return 0 ;
}
static bool F_13 ( struct V_1 * V_11 )
{
struct V_14 * V_15 = V_11 -> V_15 ;
int V_8 ;
if ( V_15 -> V_26 ) {
V_8 = F_14 ( V_15 -> V_27 ) ;
return V_8 ^= V_15 -> V_28 == 0 ;
} else {
int V_29 = 0 ;
V_29 = F_6 ( V_11 -> V_5 , V_12 ) ;
if ( V_29 < 0 ) {
F_12 ( & V_11 -> V_5 -> V_19 ,
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
struct V_1 * V_11 = F_1 ( V_3 ) ;
if ( F_13 ( V_11 ) )
F_9 ( V_11 ) ;
else
F_10 ( V_11 ) ;
F_16 ( V_3 ) ;
return V_33 ;
}
static int F_17 ( struct V_2 * V_3 ,
enum V_34 V_35 ,
union V_36 * V_37 )
{
struct V_1 * V_11 = F_1 ( V_3 ) ;
switch ( V_35 ) {
case V_38 :
V_37 -> V_39 = F_13 ( V_11 ) ? 1 : 0 ;
break;
default:
return - V_40 ;
}
return 0 ;
}
static struct V_14 * F_18 ( struct V_4 * V_5 )
{
struct V_14 * V_15 ;
struct V_41 * V_42 = V_5 -> V_19 . V_43 ;
T_5 V_37 ;
int V_8 ;
enum V_44 V_45 ;
V_15 = F_19 ( & V_5 -> V_19 , sizeof( * V_15 ) , V_46 ) ;
if ( ! V_15 ) {
F_12 ( & V_5 -> V_19 ,
L_5 ) ;
return NULL ;
}
V_15 -> V_27 = F_20 ( V_42 , L_6 ,
0 , & V_45 ) ;
if ( V_45 & V_47 )
V_15 -> V_28 = 1 ;
V_8 = F_21 ( V_42 , L_7 , & V_37 ) ;
if ( ! V_8 )
V_15 -> V_16 = V_37 ;
V_8 = F_21 ( V_42 , L_8 , & V_37 ) ;
if ( ! V_8 )
V_15 -> V_20 = V_37 ;
V_8 = F_21 ( V_42 , L_9 , & V_37 ) ;
if ( ! V_8 )
V_15 -> V_23 = V_37 ;
return V_15 ;
}
static int F_22 ( struct V_4 * V_5 ,
const struct V_48 * V_49 )
{
int V_8 ;
struct V_1 * V_11 ;
struct V_50 * V_51 ;
struct V_52 V_53 = {} ;
char * V_54 ;
V_11 = F_19 ( & V_5 -> V_19 , sizeof( * V_11 ) , V_46 ) ;
if ( ! V_11 )
return - V_55 ;
V_11 -> V_15 = V_5 -> V_19 . V_56 ;
if ( F_23 ( V_57 ) && ! V_11 -> V_15 && V_5 -> V_19 . V_43 )
V_11 -> V_15 = F_18 ( V_5 ) ;
if ( ! V_11 -> V_15 ) {
F_12 ( & V_5 -> V_19 , L_10 ) ;
return - V_40 ;
}
V_54 = ( char * ) V_11 -> V_15 -> V_54 ;
if ( ! V_54 ) {
V_54 = F_24 ( V_46 , L_11 ,
F_25 ( & V_5 -> V_19 ) ) ;
if ( ! V_54 ) {
F_12 ( & V_5 -> V_19 , L_12 ) ;
return - V_55 ;
}
}
V_11 -> V_5 = V_5 ;
V_51 = & V_11 -> V_58 ;
V_51 -> V_54 = V_54 ;
V_51 -> type = V_59 ;
V_51 -> V_60 = V_61 ;
V_51 -> V_62 = F_26 ( V_61 ) ;
V_51 -> V_63 = F_17 ;
V_53 . V_64 = V_11 -> V_15 -> V_64 ;
V_53 . V_65 = V_11 -> V_15 -> V_65 ;
V_53 . V_43 = V_5 -> V_19 . V_43 ;
V_53 . V_66 = V_11 ;
F_27 ( V_5 , V_11 ) ;
V_8 = F_6 ( V_5 , V_67 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_5 -> V_19 , L_13 ,
V_8 ) ;
goto V_68;
} else if ( V_8 != 0x0040 ) {
F_12 ( & V_5 -> V_19 ,
L_14 , V_8 ) ;
V_8 = - V_69 ;
goto V_68;
}
V_8 = F_6 ( V_5 , V_70 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_5 -> V_19 , L_15 , V_8 ) ;
goto V_68;
} else if ( V_8 != 0x000B ) {
F_12 ( & V_5 -> V_19 ,
L_16 , V_8 ) ;
V_8 = - V_69 ;
goto V_68;
}
if ( F_28 ( V_11 -> V_15 -> V_27 ) ) {
V_8 = F_29 ( & V_5 -> V_19 ,
V_11 -> V_15 -> V_27 ,
V_54 ) ;
if ( V_8 ) {
F_12 ( & V_5 -> V_19 ,
L_17 ,
V_11 -> V_15 -> V_27 , V_8 ) ;
}
V_11 -> V_15 -> V_26 = ! V_8 ;
}
V_8 = F_11 ( V_11 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_5 -> V_19 , L_18 ) ;
goto V_68;
}
if ( F_13 ( V_11 ) ) {
V_8 = F_9 ( V_11 ) ;
if ( V_8 < 0 ) {
F_12 ( & V_5 -> V_19 , L_19 ) ;
goto V_68;
}
}
V_11 -> V_11 = F_30 ( & V_5 -> V_19 , V_51 ,
& V_53 ) ;
if ( F_31 ( V_11 -> V_11 ) ) {
V_8 = F_32 ( V_11 -> V_11 ) ;
F_12 ( & V_5 -> V_19 , L_20 ,
V_8 ) ;
goto V_68;
}
if ( V_5 -> V_31 ) {
V_8 = F_33 ( & V_5 -> V_19 , V_5 -> V_31 ,
NULL , F_15 ,
V_71 |
V_72 |
V_73 ,
V_51 -> V_54 ,
V_11 -> V_11 ) ;
if ( V_8 ) {
F_12 ( & V_5 -> V_19 ,
L_21 ,
V_5 -> V_31 , V_8 ) ;
goto V_74;
}
}
return 0 ;
V_74:
F_34 ( V_11 -> V_11 ) ;
V_68:
if ( V_54 != V_11 -> V_15 -> V_54 )
F_35 ( V_54 ) ;
return V_8 ;
}
static int F_36 ( struct V_4 * V_5 )
{
struct V_1 * V_11 = F_37 ( V_5 ) ;
if ( V_11 -> V_5 -> V_31 )
F_38 ( & V_11 -> V_5 -> V_19 , V_11 -> V_5 -> V_31 ,
& V_11 -> V_11 ) ;
F_34 ( V_11 -> V_11 ) ;
if ( V_11 -> V_58 . V_54 != V_11 -> V_15 -> V_54 )
F_35 ( V_11 -> V_58 . V_54 ) ;
return 0 ;
}
