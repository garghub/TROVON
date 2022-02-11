static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline
void F_3 ( struct V_1 * V_4 , T_1 V_5 , T_1 V_6 , T_1 V_7 )
{
T_1 V_8 = F_4 ( V_4 -> V_9 + V_5 ) ;
V_6 = ( V_6 & V_7 ) | ( V_8 & ~ V_7 ) ;
F_5 ( V_6 , V_4 -> V_9 + V_5 ) ;
}
static inline
void F_6 ( struct V_1 * V_4 , T_1 V_5 , T_1 V_6 )
{
F_5 ( V_6 , V_4 -> V_9 + V_5 ) ;
}
static inline
T_1 F_7 ( struct V_1 * V_4 , T_1 V_5 )
{
return F_4 ( V_4 -> V_9 + V_5 ) ;
}
static T_2 F_8 ( int V_10 , void * V_11 )
{
struct V_1 * V_4 = V_11 ;
F_3 ( V_4 , V_12 , ~ 0 , V_13 ) ;
return V_14 ;
}
static void F_9 ( struct V_1 * V_4 )
{
#define F_10 ( V_5 ) \
dev_info(sdev->dev, #reg_id " = %08x\n", \
sdo_read(sdev, reg_id))
F_10 ( V_15 ) ;
F_10 ( V_16 ) ;
F_10 ( V_17 ) ;
F_10 ( V_18 ) ;
F_10 ( V_12 ) ;
F_10 ( V_19 ) ;
F_10 ( V_20 ) ;
}
static const struct V_21 * F_11 ( T_3 V_22 )
{
int V_23 ;
for ( V_23 = 0 ; V_23 < F_12 ( V_21 ) ; ++ V_23 )
if ( V_21 [ V_23 ] . V_22 & V_22 )
return & V_21 [ V_23 ] ;
return NULL ;
}
static int F_13 ( struct V_2 * V_3 , T_3 * V_24 )
{
* V_24 = V_25 | V_26 | V_27 |
V_28 | V_29 |
V_30 | V_31 ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 , T_3 V_24 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
const struct V_21 * V_32 ;
V_32 = F_11 ( V_24 ) ;
if ( V_32 == NULL )
return - V_33 ;
V_4 -> V_32 = V_32 ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 , T_3 * V_24 )
{
* V_24 = F_1 ( V_3 ) -> V_32 -> V_22 ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_34 * V_32 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_32 )
return - V_35 ;
V_32 -> V_36 = 720 ;
V_32 -> V_37 = V_4 -> V_32 -> V_37 ;
V_32 -> V_38 = V_39 ;
V_32 -> V_40 = V_41 ;
V_32 -> V_42 = V_43 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , int V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_45 * V_46 = V_4 -> V_46 ;
int V_47 ;
F_18 ( V_46 , L_1 , V_44 ) ;
if ( V_44 )
V_47 = F_19 ( V_46 ) ;
else
V_47 = F_20 ( V_46 ) ;
return F_21 ( V_47 ) ? V_47 : 0 ;
}
static int F_22 ( struct V_1 * V_4 )
{
F_23 ( V_4 -> V_48 , 54000000 ) ;
F_18 ( V_4 -> V_46 , L_2 ,
F_24 ( V_4 -> V_48 ) ) ;
F_3 ( V_4 , V_15 , ~ 0 , V_49 ) ;
F_25 ( V_4 -> V_50 ) ;
F_3 ( V_4 , V_18 , ~ 0 , V_51 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_4 )
{
int V_52 ;
F_3 ( V_4 , V_18 , 0 , V_51 ) ;
F_27 ( V_4 -> V_50 ) ;
F_3 ( V_4 , V_15 , 0 , V_49 ) ;
for ( V_52 = 100 ; V_52 ; -- V_52 ) {
if ( F_7 ( V_4 , V_15 ) & V_53 )
break;
F_28 ( 1 ) ;
}
if ( V_52 == 0 )
F_29 ( V_4 -> V_46 , L_3 ) ;
return V_52 ? 0 : - V_54 ;
}
static int F_30 ( struct V_2 * V_3 , int V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return V_44 ? F_22 ( V_4 ) : F_26 ( V_4 ) ;
}
static int F_31 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_32 ( V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( V_46 , L_4 ) ;
F_33 ( V_4 -> V_55 ) ;
F_33 ( V_4 -> V_56 ) ;
F_27 ( V_4 -> V_57 ) ;
return 0 ;
}
static int F_34 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_32 ( V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( V_46 , L_5 ) ;
F_25 ( V_4 -> V_57 ) ;
F_35 ( V_4 -> V_56 ) ;
F_35 ( V_4 -> V_55 ) ;
F_3 ( V_4 , V_15 , ~ 0 , V_58 ) ;
F_28 ( 10 ) ;
F_3 ( V_4 , V_15 , 0 , V_58 ) ;
F_3 ( V_4 , V_16 , V_4 -> V_32 -> V_59 , V_60 ) ;
F_3 ( V_4 , V_16 , 0 , V_61 ) ;
F_3 ( V_4 , V_17 , 0 , V_62 |
V_63 ) ;
F_3 ( V_4 , V_64 , ~ 0 , V_65 |
V_66 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int T_4 F_36 ( struct V_67 * V_68 )
{
struct V_45 * V_46 = & V_68 -> V_46 ;
struct V_1 * V_4 ;
struct V_69 * V_70 ;
int V_47 = 0 ;
struct V_71 * V_72 ;
F_18 ( V_46 , L_6 ) ;
V_4 = F_37 ( & V_68 -> V_46 , sizeof *V_4 , V_73 ) ;
if ( ! V_4 ) {
F_29 ( V_46 , L_7 ) ;
V_47 = - V_74 ;
goto V_75;
}
V_4 -> V_46 = V_46 ;
V_70 = F_38 ( V_68 , V_76 , 0 ) ;
if ( V_70 == NULL ) {
F_29 ( V_46 , L_8 ) ;
V_47 = - V_35 ;
goto V_75;
}
V_4 -> V_9 = F_39 ( & V_68 -> V_46 , V_70 -> V_77 , F_40 ( V_70 ) ) ;
if ( V_4 -> V_9 == NULL ) {
F_29 ( V_46 , L_9 ) ;
V_47 = - V_35 ;
goto V_75;
}
V_70 = F_38 ( V_68 , V_78 , 0 ) ;
if ( V_70 == NULL ) {
F_29 ( V_46 , L_10 ) ;
V_47 = - V_35 ;
goto V_75;
}
V_47 = F_41 ( & V_68 -> V_46 , V_70 -> V_77 , F_8 , 0 ,
L_11 , V_4 ) ;
if ( V_47 ) {
F_29 ( V_46 , L_12 ) ;
goto V_75;
}
V_4 -> V_10 = V_70 -> V_77 ;
V_4 -> V_57 = F_42 ( V_46 , L_13 ) ;
if ( F_43 ( V_4 -> V_57 ) ) {
F_29 ( V_46 , L_14 ) ;
V_47 = - V_35 ;
goto V_75;
}
V_4 -> V_79 = F_42 ( V_46 , L_15 ) ;
if ( F_43 ( V_4 -> V_79 ) ) {
F_29 ( V_46 , L_16 ) ;
V_47 = - V_35 ;
goto V_80;
}
V_4 -> V_50 = F_42 ( V_46 , L_17 ) ;
if ( F_43 ( V_4 -> V_50 ) ) {
F_29 ( V_46 , L_18 ) ;
V_47 = - V_35 ;
goto V_81;
}
V_72 = F_42 ( V_46 , L_19 ) ;
if ( F_43 ( V_72 ) ) {
F_29 ( V_46 , L_20 ) ;
V_47 = - V_35 ;
goto V_82;
}
F_44 ( V_4 -> V_57 , V_72 ) ;
F_45 ( V_72 ) ;
V_4 -> V_48 = F_42 ( V_46 , L_21 ) ;
if ( F_43 ( V_4 -> V_48 ) ) {
F_29 ( V_46 , L_22 ) ;
goto V_82;
}
F_18 ( V_46 , L_2 , F_24 ( V_72 ) ) ;
V_4 -> V_56 = F_46 ( V_46 , L_23 ) ;
if ( F_43 ( V_4 -> V_56 ) ) {
F_29 ( V_46 , L_24 ) ;
goto V_83;
}
V_4 -> V_55 = F_46 ( V_46 , L_25 ) ;
if ( F_43 ( V_4 -> V_55 ) ) {
F_29 ( V_46 , L_26 ) ;
goto V_84;
}
F_25 ( V_4 -> V_79 ) ;
F_47 ( V_46 ) ;
F_48 ( & V_4 -> V_3 , & V_85 ) ;
V_4 -> V_3 . V_86 = V_87 ;
F_49 ( V_4 -> V_3 . V_88 , L_11 , sizeof V_4 -> V_3 . V_88 ) ;
V_4 -> V_32 = F_11 ( V_89 ) ;
F_50 ( V_4 -> V_32 == NULL ) ;
F_51 ( V_46 , & V_4 -> V_3 ) ;
F_18 ( V_46 , L_27 ) ;
return 0 ;
V_84:
F_52 ( V_4 -> V_56 ) ;
V_83:
F_45 ( V_4 -> V_48 ) ;
V_82:
F_45 ( V_4 -> V_50 ) ;
V_81:
F_45 ( V_4 -> V_79 ) ;
V_80:
F_45 ( V_4 -> V_57 ) ;
V_75:
F_18 ( V_46 , L_28 ) ;
return V_47 ;
}
static int T_5 F_53 ( struct V_67 * V_68 )
{
struct V_2 * V_3 = F_32 ( & V_68 -> V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_54 ( & V_68 -> V_46 ) ;
F_27 ( V_4 -> V_79 ) ;
F_52 ( V_4 -> V_55 ) ;
F_52 ( V_4 -> V_56 ) ;
F_45 ( V_4 -> V_48 ) ;
F_45 ( V_4 -> V_50 ) ;
F_45 ( V_4 -> V_79 ) ;
F_45 ( V_4 -> V_57 ) ;
F_18 ( & V_68 -> V_46 , L_29 ) ;
return 0 ;
}
