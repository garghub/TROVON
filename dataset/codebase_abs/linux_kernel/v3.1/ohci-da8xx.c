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
struct V_12 * V_13 = V_21 -> V_24 ;
struct V_25 * V_26 = F_10 ( V_19 ) ;
int V_27 ;
T_1 V_28 ;
F_11 ( V_21 , L_2 ) ;
F_1 ( 1 ) ;
V_26 -> V_29 = 1 ;
V_27 = F_12 ( V_26 ) ;
if ( V_27 < 0 )
return V_27 ;
V_28 = F_13 ( V_26 , & V_26 -> V_30 -> V_31 . V_32 ) ;
if ( V_13 -> V_17 ) {
V_28 &= ~ V_33 ;
V_28 |= V_34 ;
}
if ( V_13 -> V_16 ) {
V_28 &= ~ V_35 ;
V_28 |= V_36 ;
}
V_28 &= ~ V_37 ;
V_28 |= V_13 -> V_38 << 24 ;
F_14 ( V_26 , V_28 , & V_26 -> V_30 -> V_31 . V_32 ) ;
return V_27 ;
}
static void F_15 ( struct V_18 * V_19 )
{
F_16 ( V_19 ) ;
F_1 ( 0 ) ;
}
static int F_17 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = F_10 ( V_19 ) ;
int V_27 ;
V_27 = F_18 ( V_26 ) ;
if ( V_27 < 0 )
F_15 ( V_19 ) ;
return V_27 ;
}
static int F_19 ( struct V_18 * V_19 , char * V_39 )
{
int V_40 = F_20 ( V_19 , V_39 ) ;
if ( V_15 & ( 1 << 1 ) ) {
F_11 ( V_19 -> V_22 . V_23 , L_3
L_4 ) ;
if ( ! V_40 )
V_40 = 1 ;
V_39 [ 0 ] |= 1 << 1 ;
}
return V_40 ;
}
static int F_21 ( struct V_18 * V_19 , T_2 V_41 , T_2 V_42 ,
T_2 V_43 , char * V_39 , T_2 V_44 )
{
struct V_20 * V_21 = V_19 -> V_22 . V_23 ;
struct V_12 * V_13 = V_21 -> V_24 ;
int V_45 ;
switch ( V_41 ) {
case V_46 :
if ( V_43 != 1 )
break;
F_11 ( V_21 , L_5 , V_43 ) ;
V_45 = F_22 ( F_10 ( V_19 ) , V_43 - 1 ) ;
if ( V_13 -> V_47 && V_13 -> V_47 ( V_43 ) == 0 )
V_45 &= ~ V_48 ;
if ( V_13 -> V_16 && V_13 -> V_16 ( V_43 ) > 0 )
V_45 |= V_49 ;
if ( V_15 & ( 1 << V_43 ) )
V_45 |= V_50 ;
F_23 ( F_24 ( V_45 ) , ( V_51 * ) V_39 ) ;
return 0 ;
case V_52 :
V_45 = 1 ;
goto V_53;
case V_54 :
V_45 = 0 ;
V_53:
if ( V_43 != 1 )
break;
switch ( V_42 ) {
case V_55 :
F_11 ( V_21 , L_6 ,
V_45 ? L_7 : L_8 , V_43 , L_9 ) ;
if ( ! V_13 -> V_17 )
return - V_56 ;
return V_13 -> V_17 ( V_43 , V_45 ) ? - V_56 : 0 ;
case V_57 :
F_11 ( V_21 , L_6 ,
V_45 ? L_7 : L_8 , V_43 ,
L_10 ) ;
if ( V_45 )
V_15 |= 1 << V_43 ;
else
V_15 &= ~ ( 1 << V_43 ) ;
return 0 ;
}
}
return F_25 ( V_19 , V_41 , V_42 , V_43 , V_39 , V_44 ) ;
}
static int F_26 ( const struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_12 * V_13 = V_61 -> V_21 . V_24 ;
struct V_18 * V_19 ;
struct V_62 * V_63 ;
int error , V_64 ;
if ( V_13 == NULL )
return - V_65 ;
V_4 = F_27 ( & V_61 -> V_21 , L_11 ) ;
if ( F_28 ( V_4 ) )
return F_29 ( V_4 ) ;
V_6 = F_27 ( & V_61 -> V_21 , L_12 ) ;
if ( F_28 ( V_6 ) ) {
error = F_29 ( V_6 ) ;
goto V_66;
}
V_19 = F_30 ( V_59 , & V_61 -> V_21 , F_31 ( & V_61 -> V_21 ) ) ;
if ( ! V_19 ) {
error = - V_67 ;
goto V_68;
}
V_63 = F_32 ( V_61 , V_69 , 0 ) ;
if ( ! V_63 ) {
error = - V_65 ;
goto V_70;
}
V_19 -> V_71 = V_63 -> V_72 ;
V_19 -> V_73 = F_33 ( V_63 ) ;
if ( ! F_34 ( V_19 -> V_71 , V_19 -> V_73 , V_74 ) ) {
F_11 ( & V_61 -> V_21 , L_13 ) ;
error = - V_75 ;
goto V_70;
}
V_19 -> V_30 = F_35 ( V_19 -> V_71 , V_19 -> V_73 ) ;
if ( ! V_19 -> V_30 ) {
F_36 ( & V_61 -> V_21 , L_14 ) ;
error = - V_67 ;
goto V_76;
}
F_37 ( F_10 ( V_19 ) ) ;
V_64 = F_38 ( V_61 , 0 ) ;
if ( V_64 < 0 ) {
error = - V_65 ;
goto V_77;
}
error = F_39 ( V_19 , V_64 , V_78 ) ;
if ( error )
goto V_77;
if ( V_13 -> V_79 ) {
error = V_13 -> V_79 ( F_8 ) ;
if ( ! error )
return 0 ;
}
F_40 ( V_19 ) ;
V_77:
F_41 ( V_19 -> V_30 ) ;
V_76:
F_42 ( V_19 -> V_71 , V_19 -> V_73 ) ;
V_70:
F_43 ( V_19 ) ;
V_68:
F_44 ( V_6 ) ;
V_66:
F_44 ( V_4 ) ;
return error ;
}
static inline void
F_45 ( struct V_18 * V_19 , struct V_60 * V_61 )
{
struct V_12 * V_13 = V_61 -> V_21 . V_24 ;
V_13 -> V_79 ( NULL ) ;
F_40 ( V_19 ) ;
F_41 ( V_19 -> V_30 ) ;
F_42 ( V_19 -> V_71 , V_19 -> V_73 ) ;
F_43 ( V_19 ) ;
F_44 ( V_6 ) ;
F_44 ( V_4 ) ;
}
static int F_46 ( struct V_60 * V_21 )
{
return F_26 ( & V_80 , V_21 ) ;
}
static int F_47 ( struct V_60 * V_21 )
{
struct V_18 * V_19 = F_48 ( V_21 ) ;
F_45 ( V_19 , V_21 ) ;
F_49 ( V_21 , NULL ) ;
return 0 ;
}
static int F_50 ( struct V_60 * V_21 , T_3 V_81 )
{
struct V_18 * V_19 = F_48 ( V_21 ) ;
struct V_25 * V_26 = F_10 ( V_19 ) ;
if ( F_51 ( V_82 , V_26 -> V_83 ) )
F_52 ( 5 ) ;
V_26 -> V_83 = V_82 ;
F_1 ( 0 ) ;
V_19 -> V_84 = V_85 ;
V_21 -> V_21 . V_86 . V_87 = V_88 ;
return 0 ;
}
static int F_53 ( struct V_60 * V_21 )
{
struct V_18 * V_19 = F_48 ( V_21 ) ;
struct V_25 * V_26 = F_10 ( V_19 ) ;
if ( F_51 ( V_82 , V_26 -> V_83 ) )
F_52 ( 5 ) ;
V_26 -> V_83 = V_82 ;
F_1 ( 1 ) ;
V_21 -> V_21 . V_86 . V_87 = V_89 ;
F_54 ( V_19 ) ;
return 0 ;
}
