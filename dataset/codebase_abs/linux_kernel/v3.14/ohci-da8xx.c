static void F_1 ( int V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_3 ) ;
if ( V_1 ) {
F_3 ( V_4 ) ;
if ( ! ( V_2 & V_5 ) ) {
F_3 ( V_6 ) ;
V_2 &= ~ ( V_7 | V_8 ) ;
V_2 |= V_9 ;
F_4 ( V_2 , V_3 ) ;
F_5 ( L_1 ) ;
while ( ! ( F_2 ( V_3 ) & V_10 ) )
F_6 () ;
}
V_2 |= V_11 ;
} else {
F_7 ( V_4 ) ;
if ( ! ( V_2 & V_5 ) )
F_7 ( V_6 ) ;
V_2 &= ~ V_11 ;
}
F_4 ( V_2 , V_3 ) ;
}
static void F_8 ( struct V_12 * V_13 ,
unsigned V_14 )
{
V_15 |= 1 << V_14 ;
if ( V_13 -> V_16 ( V_14 ) > 0 )
V_13 -> V_17 ( V_14 , 0 ) ;
}
static int F_9 ( struct V_18 * V_19 )
{
struct V_20 * V_21 = V_19 -> V_22 . V_23 ;
struct V_12 * V_13 = F_10 ( V_21 ) ;
struct V_24 * V_25 = F_11 ( V_19 ) ;
int V_26 ;
T_1 V_27 ;
F_12 ( V_21 , L_2 ) ;
F_1 ( 1 ) ;
V_25 -> V_28 = 1 ;
V_26 = F_13 ( V_25 ) ;
if ( V_26 < 0 )
return V_26 ;
V_27 = F_14 ( V_25 , & V_25 -> V_29 -> V_30 . V_31 ) ;
if ( V_13 -> V_17 ) {
V_27 &= ~ V_32 ;
V_27 |= V_33 ;
}
if ( V_13 -> V_16 ) {
V_27 &= ~ V_34 ;
V_27 |= V_35 ;
}
V_27 &= ~ V_36 ;
V_27 |= V_13 -> V_37 << 24 ;
F_15 ( V_25 , V_27 , & V_25 -> V_29 -> V_30 . V_31 ) ;
return V_26 ;
}
static void F_16 ( struct V_18 * V_19 )
{
F_17 ( V_19 ) ;
F_1 ( 0 ) ;
}
static int F_18 ( struct V_18 * V_19 )
{
struct V_24 * V_25 = F_11 ( V_19 ) ;
int V_26 ;
V_26 = F_19 ( V_25 ) ;
if ( V_26 < 0 )
F_16 ( V_19 ) ;
return V_26 ;
}
static int F_20 ( struct V_18 * V_19 , char * V_38 )
{
int V_39 = F_21 ( V_19 , V_38 ) ;
if ( V_15 & ( 1 << 1 ) ) {
F_12 ( V_19 -> V_22 . V_23 , L_3
L_4 ) ;
if ( ! V_39 )
V_39 = 1 ;
V_38 [ 0 ] |= 1 << 1 ;
}
return V_39 ;
}
static int F_22 ( struct V_18 * V_19 , T_2 V_40 , T_2 V_41 ,
T_2 V_42 , char * V_38 , T_2 V_43 )
{
struct V_20 * V_21 = V_19 -> V_22 . V_23 ;
struct V_12 * V_13 = F_10 ( V_21 ) ;
int V_44 ;
switch ( V_40 ) {
case V_45 :
if ( V_42 != 1 )
break;
F_12 ( V_21 , L_5 , V_42 ) ;
V_44 = F_23 ( F_11 ( V_19 ) , V_42 - 1 ) ;
if ( V_13 -> V_46 && V_13 -> V_46 ( V_42 ) == 0 )
V_44 &= ~ V_47 ;
if ( V_13 -> V_16 && V_13 -> V_16 ( V_42 ) > 0 )
V_44 |= V_48 ;
if ( V_15 & ( 1 << V_42 ) )
V_44 |= V_49 ;
F_24 ( F_25 ( V_44 ) , ( V_50 * ) V_38 ) ;
return 0 ;
case V_51 :
V_44 = 1 ;
goto V_52;
case V_53 :
V_44 = 0 ;
V_52:
if ( V_42 != 1 )
break;
switch ( V_41 ) {
case V_54 :
F_12 ( V_21 , L_6 ,
V_44 ? L_7 : L_8 , V_42 , L_9 ) ;
if ( ! V_13 -> V_17 )
return - V_55 ;
return V_13 -> V_17 ( V_42 , V_44 ) ? - V_55 : 0 ;
case V_56 :
F_12 ( V_21 , L_6 ,
V_44 ? L_7 : L_8 , V_42 ,
L_10 ) ;
if ( V_44 )
V_15 |= 1 << V_42 ;
else
V_15 &= ~ ( 1 << V_42 ) ;
return 0 ;
}
}
return F_26 ( V_19 , V_40 , V_41 , V_42 , V_38 , V_43 ) ;
}
static int F_27 ( const struct V_57 * V_58 ,
struct V_59 * V_60 )
{
struct V_12 * V_13 = F_10 ( & V_60 -> V_21 ) ;
struct V_18 * V_19 ;
struct V_61 * V_62 ;
int error , V_63 ;
if ( V_13 == NULL )
return - V_64 ;
V_4 = F_28 ( & V_60 -> V_21 , L_11 ) ;
if ( F_29 ( V_4 ) )
return F_30 ( V_4 ) ;
V_6 = F_28 ( & V_60 -> V_21 , L_12 ) ;
if ( F_29 ( V_6 ) )
return F_30 ( V_6 ) ;
V_19 = F_31 ( V_58 , & V_60 -> V_21 , F_32 ( & V_60 -> V_21 ) ) ;
if ( ! V_19 )
return - V_65 ;
V_62 = F_33 ( V_60 , V_66 , 0 ) ;
if ( ! V_62 )
return - V_64 ;
V_19 -> V_67 = V_62 -> V_68 ;
V_19 -> V_69 = F_34 ( V_62 ) ;
V_19 -> V_29 = F_35 ( & V_60 -> V_21 , V_62 ) ;
if ( F_29 ( V_19 -> V_29 ) ) {
error = F_30 ( V_19 -> V_29 ) ;
goto V_70;
}
F_36 ( F_11 ( V_19 ) ) ;
V_63 = F_37 ( V_60 , 0 ) ;
if ( V_63 < 0 ) {
error = - V_64 ;
goto V_70;
}
error = F_38 ( V_19 , V_63 , 0 ) ;
if ( error )
goto V_70;
F_39 ( V_19 -> V_22 . V_23 ) ;
if ( V_13 -> V_71 ) {
error = V_13 -> V_71 ( F_8 ) ;
if ( ! error )
return 0 ;
}
F_40 ( V_19 ) ;
V_70:
F_41 ( V_19 ) ;
return error ;
}
static inline void
F_42 ( struct V_18 * V_19 , struct V_59 * V_60 )
{
struct V_12 * V_13 = F_10 ( & V_60 -> V_21 ) ;
V_13 -> V_71 ( NULL ) ;
F_40 ( V_19 ) ;
F_41 ( V_19 ) ;
}
static int F_43 ( struct V_59 * V_21 )
{
return F_27 ( & V_72 , V_21 ) ;
}
static int F_44 ( struct V_59 * V_21 )
{
struct V_18 * V_19 = F_45 ( V_21 ) ;
F_42 ( V_19 , V_21 ) ;
return 0 ;
}
static int F_46 ( struct V_59 * V_60 ,
T_3 V_73 )
{
struct V_18 * V_19 = F_45 ( V_60 ) ;
struct V_24 * V_25 = F_11 ( V_19 ) ;
bool V_74 = F_47 ( & V_60 -> V_21 ) ;
int V_75 ;
if ( F_48 ( V_76 , V_25 -> V_77 ) )
F_49 ( 5 ) ;
V_25 -> V_77 = V_76 ;
V_75 = F_50 ( V_19 , V_74 ) ;
if ( V_75 )
return V_75 ;
F_1 ( 0 ) ;
V_19 -> V_78 = V_79 ;
return V_75 ;
}
static int F_51 ( struct V_59 * V_21 )
{
struct V_18 * V_19 = F_45 ( V_21 ) ;
struct V_24 * V_25 = F_11 ( V_19 ) ;
if ( F_48 ( V_76 , V_25 -> V_77 ) )
F_49 ( 5 ) ;
V_25 -> V_77 = V_76 ;
F_1 ( 1 ) ;
V_21 -> V_21 . V_80 . V_81 = V_82 ;
F_52 ( V_19 ) ;
return 0 ;
}
