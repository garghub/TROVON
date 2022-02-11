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
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , int V_42 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_43 * V_44 = V_4 -> V_44 ;
int V_45 ;
F_18 ( V_44 , L_1 , V_42 ) ;
if ( V_42 )
V_45 = F_19 ( V_44 ) ;
else
V_45 = F_20 ( V_44 ) ;
return F_21 ( V_45 ) ? V_45 : 0 ;
}
static int F_22 ( struct V_1 * V_4 )
{
F_23 ( V_4 -> V_46 , 54000000 ) ;
F_18 ( V_4 -> V_44 , L_2 ,
F_24 ( V_4 -> V_46 ) ) ;
F_3 ( V_4 , V_15 , ~ 0 , V_47 ) ;
F_25 ( V_4 -> V_48 ) ;
F_3 ( V_4 , V_18 , ~ 0 , V_49 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_4 )
{
int V_50 ;
F_3 ( V_4 , V_18 , 0 , V_49 ) ;
F_27 ( V_4 -> V_48 ) ;
F_3 ( V_4 , V_15 , 0 , V_47 ) ;
for ( V_50 = 100 ; V_50 ; -- V_50 ) {
if ( F_7 ( V_4 , V_15 ) & V_51 )
break;
F_28 ( 1 ) ;
}
if ( V_50 == 0 )
F_29 ( V_4 -> V_44 , L_3 ) ;
return V_50 ? 0 : - V_52 ;
}
static int F_30 ( struct V_2 * V_3 , int V_42 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return V_42 ? F_22 ( V_4 ) : F_26 ( V_4 ) ;
}
static int F_31 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_32 ( V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( V_44 , L_4 ) ;
F_33 ( V_4 -> V_53 ) ;
F_33 ( V_4 -> V_54 ) ;
F_27 ( V_4 -> V_55 ) ;
return 0 ;
}
static int F_34 ( struct V_43 * V_44 )
{
struct V_2 * V_3 = F_32 ( V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( V_44 , L_5 ) ;
F_25 ( V_4 -> V_55 ) ;
F_35 ( V_4 -> V_54 ) ;
F_35 ( V_4 -> V_53 ) ;
F_3 ( V_4 , V_15 , ~ 0 , V_56 ) ;
F_28 ( 10 ) ;
F_3 ( V_4 , V_15 , 0 , V_56 ) ;
F_3 ( V_4 , V_16 , V_4 -> V_32 -> V_57 , V_58 ) ;
F_3 ( V_4 , V_16 , 0 , V_59 ) ;
F_3 ( V_4 , V_17 , 0 , V_60 |
V_61 ) ;
F_3 ( V_4 , V_62 , ~ 0 , V_63 |
V_64 ) ;
F_9 ( V_4 ) ;
return 0 ;
}
static int T_4 F_36 ( struct V_65 * V_66 )
{
struct V_43 * V_44 = & V_66 -> V_44 ;
struct V_1 * V_4 ;
struct V_67 * V_68 ;
int V_45 = 0 ;
struct V_69 * V_70 ;
F_18 ( V_44 , L_6 ) ;
V_4 = F_37 ( sizeof *V_4 , V_71 ) ;
if ( ! V_4 ) {
F_29 ( V_44 , L_7 ) ;
V_45 = - V_72 ;
goto V_73;
}
V_4 -> V_44 = V_44 ;
V_68 = F_38 ( V_66 , V_74 , 0 ) ;
if ( V_68 == NULL ) {
F_29 ( V_44 , L_8 ) ;
V_45 = - V_35 ;
goto V_75;
}
V_4 -> V_9 = F_39 ( V_68 -> V_76 , F_40 ( V_68 ) ) ;
if ( V_4 -> V_9 == NULL ) {
F_29 ( V_44 , L_9 ) ;
V_45 = - V_35 ;
goto V_75;
}
V_68 = F_38 ( V_66 , V_77 , 0 ) ;
if ( V_68 == NULL ) {
F_29 ( V_44 , L_10 ) ;
V_45 = - V_35 ;
goto V_78;
}
V_45 = F_41 ( V_68 -> V_76 , F_8 , 0 , L_11 , V_4 ) ;
if ( V_45 ) {
F_29 ( V_44 , L_12 ) ;
goto V_78;
}
V_4 -> V_10 = V_68 -> V_76 ;
V_4 -> V_55 = F_42 ( V_44 , L_13 ) ;
if ( F_43 ( V_4 -> V_55 ) ) {
F_29 ( V_44 , L_14 ) ;
V_45 = - V_35 ;
goto V_79;
}
V_4 -> V_80 = F_42 ( V_44 , L_15 ) ;
if ( F_43 ( V_4 -> V_80 ) ) {
F_29 ( V_44 , L_16 ) ;
V_45 = - V_35 ;
goto V_81;
}
V_4 -> V_48 = F_42 ( V_44 , L_17 ) ;
if ( F_43 ( V_4 -> V_48 ) ) {
F_29 ( V_44 , L_18 ) ;
V_45 = - V_35 ;
goto V_82;
}
V_70 = F_42 ( V_44 , L_19 ) ;
if ( F_43 ( V_70 ) ) {
F_29 ( V_44 , L_20 ) ;
V_45 = - V_35 ;
goto V_83;
}
F_44 ( V_4 -> V_55 , V_70 ) ;
F_45 ( V_70 ) ;
V_4 -> V_46 = F_42 ( V_44 , L_21 ) ;
if ( F_43 ( V_4 -> V_46 ) ) {
F_29 ( V_44 , L_22 ) ;
goto V_83;
}
F_18 ( V_44 , L_2 , F_24 ( V_70 ) ) ;
V_4 -> V_54 = F_46 ( V_44 , L_23 ) ;
if ( F_43 ( V_4 -> V_54 ) ) {
F_29 ( V_44 , L_24 ) ;
goto V_84;
}
V_4 -> V_53 = F_46 ( V_44 , L_25 ) ;
if ( F_43 ( V_4 -> V_53 ) ) {
F_29 ( V_44 , L_26 ) ;
goto V_85;
}
F_25 ( V_4 -> V_80 ) ;
F_47 ( V_44 ) ;
F_48 ( & V_4 -> V_3 , & V_86 ) ;
V_4 -> V_3 . V_87 = V_88 ;
F_49 ( V_4 -> V_3 . V_89 , L_11 , sizeof V_4 -> V_3 . V_89 ) ;
V_4 -> V_32 = F_11 ( V_90 ) ;
F_50 ( V_4 -> V_32 == NULL ) ;
F_51 ( V_44 , & V_4 -> V_3 ) ;
F_18 ( V_44 , L_27 ) ;
return 0 ;
V_85:
F_52 ( V_4 -> V_54 ) ;
V_84:
F_45 ( V_4 -> V_46 ) ;
V_83:
F_45 ( V_4 -> V_48 ) ;
V_82:
F_45 ( V_4 -> V_80 ) ;
V_81:
F_45 ( V_4 -> V_55 ) ;
V_79:
F_53 ( V_4 -> V_10 , V_4 ) ;
V_78:
F_54 ( V_4 -> V_9 ) ;
V_75:
F_55 ( V_4 ) ;
V_73:
F_18 ( V_44 , L_28 ) ;
return V_45 ;
}
static int T_5 F_56 ( struct V_65 * V_66 )
{
struct V_2 * V_3 = F_32 ( & V_66 -> V_44 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_57 ( & V_66 -> V_44 ) ;
F_27 ( V_4 -> V_80 ) ;
F_52 ( V_4 -> V_53 ) ;
F_52 ( V_4 -> V_54 ) ;
F_45 ( V_4 -> V_46 ) ;
F_45 ( V_4 -> V_48 ) ;
F_45 ( V_4 -> V_80 ) ;
F_45 ( V_4 -> V_55 ) ;
F_53 ( V_4 -> V_10 , V_4 ) ;
F_54 ( V_4 -> V_9 ) ;
F_55 ( V_4 ) ;
F_18 ( & V_66 -> V_44 , L_29 ) ;
return 0 ;
}
static int T_6 F_58 ( void )
{
int V_45 ;
static const char V_91 [] V_92 = V_93 \
L_30
L_31 ;
F_59 ( V_91 ) ;
V_45 = F_60 ( & V_94 ) ;
if ( V_45 )
F_59 ( V_95 L_32 ) ;
return V_45 ;
}
static void T_7 F_61 ( void )
{
F_62 ( & V_94 ) ;
}
