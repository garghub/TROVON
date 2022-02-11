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
return V_47 < 0 ? V_47 : 0 ;
}
static int F_21 ( struct V_1 * V_4 )
{
int V_47 ;
V_4 -> V_48 = F_22 ( V_4 -> V_49 ) ;
V_47 = F_23 ( V_4 -> V_49 , 54000000 ) ;
if ( V_47 < 0 ) {
F_24 ( V_4 -> V_46 , L_2 ) ;
return V_47 ;
}
F_18 ( V_4 -> V_46 , L_3 ,
F_22 ( V_4 -> V_49 ) ) ;
F_3 ( V_4 , V_15 , ~ 0 , V_50 ) ;
V_47 = F_25 ( V_4 -> V_51 ) ;
if ( V_47 < 0 ) {
F_24 ( V_4 -> V_46 , L_4 ) ;
goto V_52;
}
F_3 ( V_4 , V_18 , ~ 0 , V_53 ) ;
F_9 ( V_4 ) ;
return 0 ;
V_52:
F_3 ( V_4 , V_15 , 0 , V_50 ) ;
F_23 ( V_4 -> V_49 , V_4 -> V_48 ) ;
return V_47 ;
}
static int F_26 ( struct V_1 * V_4 )
{
int V_54 ;
F_3 ( V_4 , V_18 , 0 , V_53 ) ;
F_27 ( V_4 -> V_51 ) ;
F_3 ( V_4 , V_15 , 0 , V_50 ) ;
for ( V_54 = 100 ; V_54 ; -- V_54 ) {
if ( F_7 ( V_4 , V_15 ) & V_55 )
break;
F_28 ( 1 ) ;
}
if ( V_54 == 0 )
F_24 ( V_4 -> V_46 , L_5 ) ;
F_23 ( V_4 -> V_49 , V_4 -> V_48 ) ;
return V_54 ? 0 : - V_56 ;
}
static int F_29 ( struct V_2 * V_3 , int V_44 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return V_44 ? F_21 ( V_4 ) : F_26 ( V_4 ) ;
}
static int F_30 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_31 ( V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( V_46 , L_6 ) ;
F_32 ( V_4 -> V_57 ) ;
F_32 ( V_4 -> V_58 ) ;
F_27 ( V_4 -> V_59 ) ;
return 0 ;
}
static int F_33 ( struct V_45 * V_46 )
{
struct V_2 * V_3 = F_31 ( V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_47 ;
F_18 ( V_46 , L_7 ) ;
V_47 = F_25 ( V_4 -> V_59 ) ;
if ( V_47 < 0 )
return V_47 ;
V_47 = F_34 ( V_4 -> V_58 ) ;
if ( V_47 < 0 )
goto V_60;
V_47 = F_34 ( V_4 -> V_57 ) ;
if ( V_47 < 0 )
goto V_61;
F_3 ( V_4 , V_15 , ~ 0 , V_62 ) ;
F_28 ( 10 ) ;
F_3 ( V_4 , V_15 , 0 , V_62 ) ;
F_3 ( V_4 , V_16 , V_4 -> V_32 -> V_63 , V_64 ) ;
F_3 ( V_4 , V_16 , 0 , V_65 ) ;
F_3 ( V_4 , V_17 , 0 , V_66 |
V_67 ) ;
F_3 ( V_4 , V_68 , ~ 0 , V_69 |
V_70 ) ;
F_9 ( V_4 ) ;
return 0 ;
V_61:
F_32 ( V_4 -> V_58 ) ;
V_60:
F_27 ( V_4 -> V_59 ) ;
return V_47 ;
}
static int F_35 ( struct V_71 * V_72 )
{
struct V_45 * V_46 = & V_72 -> V_46 ;
struct V_1 * V_4 ;
struct V_73 * V_74 ;
int V_47 = 0 ;
struct V_75 * V_76 ;
F_18 ( V_46 , L_8 ) ;
V_4 = F_36 ( & V_72 -> V_46 , sizeof( * V_4 ) , V_77 ) ;
if ( ! V_4 ) {
F_24 ( V_46 , L_9 ) ;
V_47 = - V_78 ;
goto V_52;
}
V_4 -> V_46 = V_46 ;
V_74 = F_37 ( V_72 , V_79 , 0 ) ;
if ( V_74 == NULL ) {
F_24 ( V_46 , L_10 ) ;
V_47 = - V_35 ;
goto V_52;
}
V_4 -> V_9 = F_38 ( & V_72 -> V_46 , V_74 -> V_80 , F_39 ( V_74 ) ) ;
if ( V_4 -> V_9 == NULL ) {
F_24 ( V_46 , L_11 ) ;
V_47 = - V_35 ;
goto V_52;
}
V_74 = F_37 ( V_72 , V_81 , 0 ) ;
if ( V_74 == NULL ) {
F_24 ( V_46 , L_12 ) ;
V_47 = - V_35 ;
goto V_52;
}
V_47 = F_40 ( & V_72 -> V_46 , V_74 -> V_80 , F_8 , 0 ,
L_13 , V_4 ) ;
if ( V_47 ) {
F_24 ( V_46 , L_14 ) ;
goto V_52;
}
V_4 -> V_10 = V_74 -> V_80 ;
V_4 -> V_59 = F_41 ( V_46 , L_15 ) ;
if ( F_42 ( V_4 -> V_59 ) ) {
F_24 ( V_46 , L_16 ) ;
V_47 = F_43 ( V_4 -> V_59 ) ;
goto V_52;
}
V_4 -> V_82 = F_41 ( V_46 , L_17 ) ;
if ( F_42 ( V_4 -> V_82 ) ) {
F_24 ( V_46 , L_18 ) ;
V_47 = F_43 ( V_4 -> V_82 ) ;
goto V_83;
}
V_4 -> V_51 = F_41 ( V_46 , L_19 ) ;
if ( F_42 ( V_4 -> V_51 ) ) {
F_24 ( V_46 , L_20 ) ;
V_47 = F_43 ( V_4 -> V_51 ) ;
goto V_84;
}
V_76 = F_41 ( V_46 , L_21 ) ;
if ( F_42 ( V_76 ) ) {
F_24 ( V_46 , L_22 ) ;
V_47 = F_43 ( V_76 ) ;
goto V_85;
}
F_44 ( V_4 -> V_59 , V_76 ) ;
F_45 ( V_76 ) ;
V_4 -> V_49 = F_41 ( V_46 , L_23 ) ;
if ( F_42 ( V_4 -> V_49 ) ) {
F_24 ( V_46 , L_24 ) ;
V_47 = F_43 ( V_4 -> V_49 ) ;
goto V_85;
}
F_18 ( V_46 , L_3 , F_22 ( V_76 ) ) ;
V_4 -> V_58 = F_46 ( V_46 , L_25 ) ;
if ( F_42 ( V_4 -> V_58 ) ) {
F_24 ( V_46 , L_26 ) ;
V_47 = F_43 ( V_4 -> V_58 ) ;
goto V_86;
}
V_4 -> V_57 = F_46 ( V_46 , L_27 ) ;
if ( F_42 ( V_4 -> V_57 ) ) {
F_24 ( V_46 , L_28 ) ;
V_47 = F_43 ( V_4 -> V_57 ) ;
goto V_86;
}
V_47 = F_25 ( V_4 -> V_82 ) ;
if ( V_47 < 0 ) {
F_24 ( V_46 , L_29 ) ;
goto V_86;
}
F_47 ( V_46 ) ;
F_48 ( & V_4 -> V_3 , & V_87 ) ;
V_4 -> V_3 . V_88 = V_89 ;
F_49 ( V_4 -> V_3 . V_90 , L_13 , sizeof( V_4 -> V_3 . V_90 ) ) ;
V_4 -> V_32 = F_11 ( V_91 ) ;
F_50 ( V_4 -> V_32 == NULL ) ;
F_51 ( V_46 , & V_4 -> V_3 ) ;
F_18 ( V_46 , L_30 ) ;
return 0 ;
V_86:
F_45 ( V_4 -> V_49 ) ;
V_85:
F_45 ( V_4 -> V_51 ) ;
V_84:
F_45 ( V_4 -> V_82 ) ;
V_83:
F_45 ( V_4 -> V_59 ) ;
V_52:
F_18 ( V_46 , L_31 ) ;
return V_47 ;
}
static int F_52 ( struct V_71 * V_72 )
{
struct V_2 * V_3 = F_31 ( & V_72 -> V_46 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_53 ( & V_72 -> V_46 ) ;
F_27 ( V_4 -> V_82 ) ;
F_45 ( V_4 -> V_49 ) ;
F_45 ( V_4 -> V_51 ) ;
F_45 ( V_4 -> V_82 ) ;
F_45 ( V_4 -> V_59 ) ;
F_18 ( & V_72 -> V_46 , L_32 ) ;
return 0 ;
}
