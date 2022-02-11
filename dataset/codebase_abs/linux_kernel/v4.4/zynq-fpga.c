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
static int F_9 ( struct V_15 * V_16 , T_1 V_17 ,
const char * V_18 , T_3 V_19 )
{
struct V_1 * V_2 ;
T_1 V_20 , V_21 ;
int V_22 ;
V_2 = V_16 -> V_2 ;
V_22 = F_10 ( V_2 -> V_23 ) ;
if ( V_22 )
return V_22 ;
if ( ! ( V_17 & V_24 ) ) {
F_11 ( V_2 -> V_25 , V_26 ,
V_27 ) ;
F_11 ( V_2 -> V_25 , V_28 ,
V_29 ) ;
F_11 ( V_2 -> V_25 , V_28 ,
V_30 ) ;
V_20 = F_3 ( V_2 , V_31 ) ;
V_20 |= V_32 ;
F_1 ( V_2 , V_31 , V_20 ) ;
V_22 = F_12 ( V_2 , V_33 , V_21 ,
V_21 & V_34 ,
V_35 ,
V_36 ) ;
if ( V_22 ) {
F_13 ( V_2 -> V_37 , L_1 ) ;
goto V_38;
}
V_20 = F_3 ( V_2 , V_31 ) ;
V_20 &= ~ V_32 ;
F_1 ( V_2 , V_31 , V_20 ) ;
V_22 = F_12 ( V_2 , V_33 , V_21 ,
! ( V_21 & V_34 ) ,
V_35 ,
V_36 ) ;
if ( V_22 ) {
F_13 ( V_2 -> V_37 , L_2 ) ;
goto V_38;
}
V_20 = F_3 ( V_2 , V_31 ) ;
V_20 |= V_32 ;
F_1 ( V_2 , V_31 , V_20 ) ;
V_22 = F_12 ( V_2 , V_33 , V_21 ,
V_21 & V_34 ,
V_35 ,
V_36 ) ;
if ( V_22 ) {
F_13 ( V_2 -> V_37 , L_1 ) ;
goto V_38;
}
}
V_20 = F_3 ( V_2 , V_31 ) ;
F_1 ( V_2 , V_31 ,
( V_39 | V_40 | V_20 ) ) ;
V_21 = F_3 ( V_2 , V_33 ) ;
if ( V_21 & V_41 ) {
F_13 ( V_2 -> V_37 , L_3 ) ;
V_22 = - V_42 ;
goto V_38;
}
V_20 = F_3 ( V_2 , V_43 ) ;
F_1 ( V_2 , V_43 , ( ~ V_44 & V_20 ) ) ;
F_14 ( V_2 -> V_23 ) ;
return 0 ;
V_38:
F_14 ( V_2 -> V_23 ) ;
return V_22 ;
}
static int F_15 ( struct V_15 * V_16 ,
const char * V_18 , T_3 V_19 )
{
struct V_1 * V_2 ;
int V_22 ;
char * V_45 ;
T_3 V_46 ;
T_4 V_47 ;
T_1 V_48 ;
T_1 V_49 ;
V_46 = V_19 ;
V_2 = V_16 -> V_2 ;
V_45 = F_16 ( V_2 -> V_37 , V_19 , & V_47 , V_50 ) ;
if ( ! V_45 )
return - V_51 ;
memcpy ( V_45 , V_18 , V_19 ) ;
V_22 = F_10 ( V_2 -> V_23 ) ;
if ( V_22 )
goto V_52;
F_1 ( V_2 , V_53 , V_54 ) ;
F_17 ( & V_2 -> V_13 ) ;
F_6 ( V_2 ) ;
F_1 ( V_2 , V_55 , ( T_1 ) ( V_47 ) + 1 ) ;
F_1 ( V_2 , V_56 , ( T_1 ) V_57 ) ;
V_48 = ( V_19 + 3 ) / 4 ;
F_1 ( V_2 , V_58 , V_48 ) ;
F_1 ( V_2 , V_59 , 0 ) ;
F_18 ( & V_2 -> V_13 ) ;
V_49 = F_3 ( V_2 , V_53 ) ;
F_1 ( V_2 , V_53 , V_49 ) ;
if ( ! ( ( V_49 & V_10 ) == V_10 ) ) {
F_13 ( V_2 -> V_37 , L_4 ) ;
V_22 = - V_60 ;
}
F_14 ( V_2 -> V_23 ) ;
V_52:
F_19 ( V_2 -> V_37 , V_46 , V_45 , V_47 ) ;
return V_22 ;
}
static int F_20 ( struct V_15 * V_16 , T_1 V_17 )
{
struct V_1 * V_2 = V_16 -> V_2 ;
int V_22 ;
T_1 V_49 ;
V_22 = F_10 ( V_2 -> V_23 ) ;
if ( V_22 )
return V_22 ;
V_22 = F_12 ( V_2 , V_53 , V_49 ,
V_49 & V_61 ,
V_35 ,
V_36 ) ;
F_14 ( V_2 -> V_23 ) ;
if ( V_22 )
return V_22 ;
if ( ! ( V_17 & V_24 ) ) {
F_11 ( V_2 -> V_25 , V_28 ,
V_62 ) ;
F_11 ( V_2 -> V_25 , V_26 ,
V_63 ) ;
}
return 0 ;
}
static enum V_64 F_21 ( struct V_15 * V_16 )
{
int V_22 ;
T_1 V_49 ;
struct V_1 * V_2 ;
V_2 = V_16 -> V_2 ;
V_22 = F_10 ( V_2 -> V_23 ) ;
if ( V_22 )
return V_65 ;
V_49 = F_3 ( V_2 , V_53 ) ;
F_14 ( V_2 -> V_23 ) ;
if ( V_49 & V_61 )
return V_66 ;
return V_65 ;
}
static int F_22 ( struct V_67 * V_68 )
{
struct V_69 * V_37 = & V_68 -> V_37 ;
struct V_1 * V_2 ;
struct V_70 * V_71 ;
int V_22 ;
V_2 = F_23 ( V_37 , sizeof( * V_2 ) , V_50 ) ;
if ( ! V_2 )
return - V_51 ;
V_2 -> V_37 = V_37 ;
V_71 = F_24 ( V_68 , V_72 , 0 ) ;
V_2 -> V_5 = F_25 ( V_37 , V_71 ) ;
if ( F_26 ( V_2 -> V_5 ) )
return F_27 ( V_2 -> V_5 ) ;
V_2 -> V_25 = F_28 ( V_37 -> V_73 ,
L_5 ) ;
if ( F_26 ( V_2 -> V_25 ) ) {
F_13 ( V_37 , L_6 ) ;
return F_27 ( V_2 -> V_25 ) ;
}
F_29 ( & V_2 -> V_13 ) ;
V_2 -> V_11 = F_30 ( V_68 , 0 ) ;
if ( V_2 -> V_11 < 0 ) {
F_13 ( V_37 , L_7 ) ;
return V_2 -> V_11 ;
}
V_22 = F_31 ( V_37 , V_2 -> V_11 , F_7 , 0 ,
F_32 ( V_37 ) , V_2 ) ;
if ( V_22 ) {
F_13 ( V_37 , L_8 ) ;
return V_22 ;
}
V_2 -> V_23 = F_33 ( V_37 , L_9 ) ;
if ( F_26 ( V_2 -> V_23 ) ) {
F_13 ( V_37 , L_10 ) ;
return F_27 ( V_2 -> V_23 ) ;
}
V_22 = F_34 ( V_2 -> V_23 ) ;
if ( V_22 ) {
F_13 ( V_37 , L_11 ) ;
return V_22 ;
}
F_1 ( V_2 , V_74 , V_75 ) ;
F_14 ( V_2 -> V_23 ) ;
V_22 = F_35 ( V_37 , L_12 ,
& V_76 , V_2 ) ;
if ( V_22 ) {
F_13 ( V_37 , L_13 ) ;
F_36 ( V_2 -> V_23 ) ;
return V_22 ;
}
return 0 ;
}
static int F_37 ( struct V_67 * V_68 )
{
struct V_1 * V_2 ;
struct V_15 * V_16 ;
V_16 = F_38 ( V_68 ) ;
V_2 = V_16 -> V_2 ;
F_39 ( & V_68 -> V_37 ) ;
F_36 ( V_2 -> V_23 ) ;
return 0 ;
}
