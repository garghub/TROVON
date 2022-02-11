static inline void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_4 , V_2 -> V_5 + V_3 ) ;
}
static inline T_1 F_3 ( const struct V_1 * V_2 ,
T_1 V_3 )
{
return F_4 ( V_2 -> V_5 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_7 ,
V_6 | V_8 | V_9 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_1 V_6 ;
V_6 = F_3 ( V_2 , V_7 ) ;
F_1 ( V_2 , V_7 ,
V_6
& ~ ( V_10 | V_9 ) ) ;
}
static T_2 F_7 ( int V_11 , void * V_12 )
{
struct V_1 * V_2 = V_12 ;
F_5 ( V_2 ) ;
F_8 ( & V_2 -> V_13 ) ;
return V_14 ;
}
static int F_9 ( struct V_15 * V_16 ,
struct V_17 * V_18 ,
const char * V_19 , T_3 V_20 )
{
struct V_1 * V_2 ;
T_1 V_21 , V_22 ;
int V_23 ;
V_2 = V_16 -> V_2 ;
V_23 = F_10 ( V_2 -> V_24 ) ;
if ( V_23 )
return V_23 ;
if ( ! ( V_18 -> V_25 & V_26 ) ) {
F_11 ( V_2 -> V_27 , V_28 ,
V_29 ) ;
F_11 ( V_2 -> V_27 , V_30 ,
V_31 ) ;
F_11 ( V_2 -> V_27 , V_30 ,
V_32 ) ;
V_21 = F_3 ( V_2 , V_33 ) ;
V_21 |= V_34 ;
F_1 ( V_2 , V_33 , V_21 ) ;
V_23 = F_12 ( V_2 , V_35 , V_22 ,
V_22 & V_36 ,
V_37 ,
V_38 ) ;
if ( V_23 ) {
F_13 ( & V_16 -> V_39 , L_1 ) ;
goto V_40;
}
V_21 = F_3 ( V_2 , V_33 ) ;
V_21 &= ~ V_34 ;
F_1 ( V_2 , V_33 , V_21 ) ;
V_23 = F_12 ( V_2 , V_35 , V_22 ,
! ( V_22 & V_36 ) ,
V_37 ,
V_38 ) ;
if ( V_23 ) {
F_13 ( & V_16 -> V_39 , L_2 ) ;
goto V_40;
}
V_21 = F_3 ( V_2 , V_33 ) ;
V_21 |= V_34 ;
F_1 ( V_2 , V_33 , V_21 ) ;
V_23 = F_12 ( V_2 , V_35 , V_22 ,
V_22 & V_36 ,
V_37 ,
V_38 ) ;
if ( V_23 ) {
F_13 ( & V_16 -> V_39 , L_1 ) ;
goto V_40;
}
}
V_21 = F_3 ( V_2 , V_33 ) ;
F_1 ( V_2 , V_33 ,
( V_41 | V_42 | V_21 ) ) ;
V_22 = F_3 ( V_2 , V_35 ) ;
if ( V_22 & V_43 ) {
F_13 ( & V_16 -> V_39 , L_3 ) ;
V_23 = - V_44 ;
goto V_40;
}
V_21 = F_3 ( V_2 , V_45 ) ;
F_1 ( V_2 , V_45 , ( ~ V_46 & V_21 ) ) ;
F_14 ( V_2 -> V_24 ) ;
return 0 ;
V_40:
F_14 ( V_2 -> V_24 ) ;
return V_23 ;
}
static int F_15 ( struct V_15 * V_16 ,
const char * V_19 , T_3 V_20 )
{
struct V_1 * V_2 ;
int V_23 ;
char * V_47 ;
T_3 V_48 ;
T_4 V_49 ;
T_1 V_50 ;
T_1 V_51 ;
V_48 = V_20 ;
V_2 = V_16 -> V_2 ;
V_47 =
F_16 ( V_16 -> V_39 . V_52 , V_20 , & V_49 , V_53 ) ;
if ( ! V_47 )
return - V_54 ;
memcpy ( V_47 , V_19 , V_20 ) ;
V_23 = F_10 ( V_2 -> V_24 ) ;
if ( V_23 )
goto V_55;
F_1 ( V_2 , V_56 , V_57 ) ;
F_17 ( & V_2 -> V_13 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 , V_58 , ( T_1 ) ( V_49 ) + 1 ) ;
F_1 ( V_2 , V_59 , ( T_1 ) V_60 ) ;
V_50 = ( V_20 + 3 ) / 4 ;
F_1 ( V_2 , V_61 , V_50 ) ;
F_1 ( V_2 , V_62 , 0 ) ;
F_18 ( & V_2 -> V_13 ) ;
V_51 = F_3 ( V_2 , V_56 ) ;
F_1 ( V_2 , V_56 , V_51 ) ;
if ( ! ( ( V_51 & V_10 ) == V_10 ) ) {
F_13 ( & V_16 -> V_39 , L_4 ) ;
V_23 = - V_63 ;
}
F_14 ( V_2 -> V_24 ) ;
V_55:
F_19 ( V_16 -> V_39 . V_52 , V_20 , V_47 , V_49 ) ;
return V_23 ;
}
static int F_20 ( struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
int V_23 ;
T_1 V_51 ;
V_23 = F_10 ( V_2 -> V_24 ) ;
if ( V_23 )
return V_23 ;
V_23 = F_12 ( V_2 , V_56 , V_51 ,
V_51 & V_64 ,
V_37 ,
V_38 ) ;
F_14 ( V_2 -> V_24 ) ;
if ( V_23 )
return V_23 ;
if ( ! ( V_18 -> V_25 & V_26 ) ) {
F_11 ( V_2 -> V_27 , V_30 ,
V_65 ) ;
F_11 ( V_2 -> V_27 , V_28 ,
V_66 ) ;
}
return 0 ;
}
static enum V_67 F_21 ( struct V_15 * V_16 )
{
int V_23 ;
T_1 V_51 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_2 ;
V_23 = F_10 ( V_2 -> V_24 ) ;
if ( V_23 )
return V_68 ;
V_51 = F_3 ( V_2 , V_56 ) ;
F_14 ( V_2 -> V_24 ) ;
if ( V_51 & V_64 )
return V_69 ;
return V_68 ;
}
static int F_22 ( struct V_70 * V_71 )
{
struct V_72 * V_39 = & V_71 -> V_39 ;
struct V_1 * V_2 ;
struct V_73 * V_74 ;
int V_23 ;
V_2 = F_23 ( V_39 , sizeof( * V_2 ) , V_53 ) ;
if ( ! V_2 )
return - V_54 ;
V_74 = F_24 ( V_71 , V_75 , 0 ) ;
V_2 -> V_5 = F_25 ( V_39 , V_74 ) ;
if ( F_26 ( V_2 -> V_5 ) )
return F_27 ( V_2 -> V_5 ) ;
V_2 -> V_27 = F_28 ( V_39 -> V_76 ,
L_5 ) ;
if ( F_26 ( V_2 -> V_27 ) ) {
F_13 ( V_39 , L_6 ) ;
return F_27 ( V_2 -> V_27 ) ;
}
F_29 ( & V_2 -> V_13 ) ;
V_2 -> V_11 = F_30 ( V_71 , 0 ) ;
if ( V_2 -> V_11 < 0 ) {
F_13 ( V_39 , L_7 ) ;
return V_2 -> V_11 ;
}
V_2 -> V_24 = F_31 ( V_39 , L_8 ) ;
if ( F_26 ( V_2 -> V_24 ) ) {
F_13 ( V_39 , L_9 ) ;
return F_27 ( V_2 -> V_24 ) ;
}
V_23 = F_32 ( V_2 -> V_24 ) ;
if ( V_23 ) {
F_13 ( V_39 , L_10 ) ;
return V_23 ;
}
F_1 ( V_2 , V_77 , V_78 ) ;
F_1 ( V_2 , V_7 , 0xFFFFFFFF ) ;
F_1 ( V_2 , V_56 , V_57 ) ;
V_23 = F_33 ( V_39 , V_2 -> V_11 , F_7 , 0 , F_34 ( V_39 ) ,
V_2 ) ;
if ( V_23 ) {
F_13 ( V_39 , L_11 ) ;
F_35 ( V_2 -> V_24 ) ;
return V_23 ;
}
F_14 ( V_2 -> V_24 ) ;
V_23 = F_36 ( V_39 , L_12 ,
& V_79 , V_2 ) ;
if ( V_23 ) {
F_13 ( V_39 , L_13 ) ;
F_37 ( V_2 -> V_24 ) ;
return V_23 ;
}
return 0 ;
}
static int F_38 ( struct V_70 * V_71 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
V_16 = F_39 ( V_71 ) ;
V_2 = V_16 -> V_2 ;
F_40 ( & V_71 -> V_39 ) ;
F_37 ( V_2 -> V_24 ) ;
return 0 ;
}
