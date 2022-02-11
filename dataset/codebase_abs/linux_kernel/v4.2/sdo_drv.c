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
struct V_34 * V_35 ,
struct V_36 * V_37 )
{
struct V_38 * V_32 = & V_37 -> V_37 ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( ! V_4 -> V_32 )
return - V_39 ;
if ( V_37 -> V_40 )
return - V_33 ;
V_32 -> V_41 = 720 ;
V_32 -> V_42 = V_4 -> V_32 -> V_42 ;
V_32 -> V_43 = V_44 ;
V_32 -> V_45 = V_46 ;
V_32 -> V_47 = V_48 ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , int V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
struct V_50 * V_51 = V_4 -> V_51 ;
int V_52 ;
F_18 ( V_51 , L_1 , V_49 ) ;
if ( V_49 )
V_52 = F_19 ( V_51 ) ;
else
V_52 = F_20 ( V_51 ) ;
return V_52 < 0 ? V_52 : 0 ;
}
static int F_21 ( struct V_1 * V_4 )
{
int V_52 ;
V_4 -> V_53 = F_22 ( V_4 -> V_54 ) ;
V_52 = F_23 ( V_4 -> V_54 , 54000000 ) ;
if ( V_52 < 0 ) {
F_24 ( V_4 -> V_51 , L_2 ) ;
return V_52 ;
}
F_18 ( V_4 -> V_51 , L_3 ,
F_22 ( V_4 -> V_54 ) ) ;
F_3 ( V_4 , V_15 , ~ 0 , V_55 ) ;
V_52 = F_25 ( V_4 -> V_56 ) ;
if ( V_52 < 0 ) {
F_24 ( V_4 -> V_51 , L_4 ) ;
goto V_57;
}
F_3 ( V_4 , V_18 , ~ 0 , V_58 ) ;
F_9 ( V_4 ) ;
return 0 ;
V_57:
F_3 ( V_4 , V_15 , 0 , V_55 ) ;
F_23 ( V_4 -> V_54 , V_4 -> V_53 ) ;
return V_52 ;
}
static int F_26 ( struct V_1 * V_4 )
{
int V_59 ;
F_3 ( V_4 , V_18 , 0 , V_58 ) ;
F_27 ( V_4 -> V_56 ) ;
F_3 ( V_4 , V_15 , 0 , V_55 ) ;
for ( V_59 = 100 ; V_59 ; -- V_59 ) {
if ( F_7 ( V_4 , V_15 ) & V_60 )
break;
F_28 ( 1 ) ;
}
if ( V_59 == 0 )
F_24 ( V_4 -> V_51 , L_5 ) ;
F_23 ( V_4 -> V_54 , V_4 -> V_53 ) ;
return V_59 ? 0 : - V_61 ;
}
static int F_29 ( struct V_2 * V_3 , int V_49 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
return V_49 ? F_21 ( V_4 ) : F_26 ( V_4 ) ;
}
static int F_30 ( struct V_50 * V_51 )
{
struct V_2 * V_3 = F_31 ( V_51 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_18 ( V_51 , L_6 ) ;
F_32 ( V_4 -> V_62 ) ;
F_32 ( V_4 -> V_63 ) ;
F_27 ( V_4 -> V_64 ) ;
return 0 ;
}
static int F_33 ( struct V_50 * V_51 )
{
struct V_2 * V_3 = F_31 ( V_51 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
int V_52 ;
F_18 ( V_51 , L_7 ) ;
V_52 = F_25 ( V_4 -> V_64 ) ;
if ( V_52 < 0 )
return V_52 ;
V_52 = F_34 ( V_4 -> V_63 ) ;
if ( V_52 < 0 )
goto V_65;
V_52 = F_34 ( V_4 -> V_62 ) ;
if ( V_52 < 0 )
goto V_66;
F_3 ( V_4 , V_15 , ~ 0 , V_67 ) ;
F_28 ( 10 ) ;
F_3 ( V_4 , V_15 , 0 , V_67 ) ;
F_3 ( V_4 , V_16 , V_4 -> V_32 -> V_68 , V_69 ) ;
F_3 ( V_4 , V_16 , 0 , V_70 ) ;
F_3 ( V_4 , V_17 , 0 , V_71 |
V_72 ) ;
F_3 ( V_4 , V_73 , ~ 0 , V_74 |
V_75 ) ;
F_9 ( V_4 ) ;
return 0 ;
V_66:
F_32 ( V_4 -> V_63 ) ;
V_65:
F_27 ( V_4 -> V_64 ) ;
return V_52 ;
}
static int F_35 ( struct V_76 * V_77 )
{
struct V_50 * V_51 = & V_77 -> V_51 ;
struct V_1 * V_4 ;
struct V_78 * V_79 ;
int V_52 = 0 ;
struct V_80 * V_81 ;
F_18 ( V_51 , L_8 ) ;
V_4 = F_36 ( & V_77 -> V_51 , sizeof( * V_4 ) , V_82 ) ;
if ( ! V_4 ) {
F_24 ( V_51 , L_9 ) ;
V_52 = - V_83 ;
goto V_57;
}
V_4 -> V_51 = V_51 ;
V_79 = F_37 ( V_77 , V_84 , 0 ) ;
if ( V_79 == NULL ) {
F_24 ( V_51 , L_10 ) ;
V_52 = - V_39 ;
goto V_57;
}
V_4 -> V_9 = F_38 ( & V_77 -> V_51 , V_79 -> V_85 , F_39 ( V_79 ) ) ;
if ( V_4 -> V_9 == NULL ) {
F_24 ( V_51 , L_11 ) ;
V_52 = - V_39 ;
goto V_57;
}
V_79 = F_37 ( V_77 , V_86 , 0 ) ;
if ( V_79 == NULL ) {
F_24 ( V_51 , L_12 ) ;
V_52 = - V_39 ;
goto V_57;
}
V_52 = F_40 ( & V_77 -> V_51 , V_79 -> V_85 , F_8 , 0 ,
L_13 , V_4 ) ;
if ( V_52 ) {
F_24 ( V_51 , L_14 ) ;
goto V_57;
}
V_4 -> V_10 = V_79 -> V_85 ;
V_4 -> V_64 = F_41 ( V_51 , L_15 ) ;
if ( F_42 ( V_4 -> V_64 ) ) {
F_24 ( V_51 , L_16 ) ;
V_52 = F_43 ( V_4 -> V_64 ) ;
goto V_57;
}
V_4 -> V_87 = F_41 ( V_51 , L_17 ) ;
if ( F_42 ( V_4 -> V_87 ) ) {
F_24 ( V_51 , L_18 ) ;
V_52 = F_43 ( V_4 -> V_87 ) ;
goto V_88;
}
V_4 -> V_56 = F_41 ( V_51 , L_19 ) ;
if ( F_42 ( V_4 -> V_56 ) ) {
F_24 ( V_51 , L_20 ) ;
V_52 = F_43 ( V_4 -> V_56 ) ;
goto V_89;
}
V_81 = F_41 ( V_51 , L_21 ) ;
if ( F_42 ( V_81 ) ) {
F_24 ( V_51 , L_22 ) ;
V_52 = F_43 ( V_81 ) ;
goto V_90;
}
F_44 ( V_4 -> V_64 , V_81 ) ;
F_45 ( V_81 ) ;
V_4 -> V_54 = F_41 ( V_51 , L_23 ) ;
if ( F_42 ( V_4 -> V_54 ) ) {
F_24 ( V_51 , L_24 ) ;
V_52 = F_43 ( V_4 -> V_54 ) ;
goto V_90;
}
F_18 ( V_51 , L_3 , F_22 ( V_81 ) ) ;
V_4 -> V_63 = F_46 ( V_51 , L_25 ) ;
if ( F_42 ( V_4 -> V_63 ) ) {
F_24 ( V_51 , L_26 ) ;
V_52 = F_43 ( V_4 -> V_63 ) ;
goto V_91;
}
V_4 -> V_62 = F_46 ( V_51 , L_27 ) ;
if ( F_42 ( V_4 -> V_62 ) ) {
F_24 ( V_51 , L_28 ) ;
V_52 = F_43 ( V_4 -> V_62 ) ;
goto V_91;
}
V_52 = F_25 ( V_4 -> V_87 ) ;
if ( V_52 < 0 ) {
F_24 ( V_51 , L_29 ) ;
goto V_91;
}
F_47 ( V_51 ) ;
F_48 ( & V_4 -> V_3 , & V_92 ) ;
V_4 -> V_3 . V_93 = V_94 ;
F_49 ( V_4 -> V_3 . V_95 , L_13 , sizeof( V_4 -> V_3 . V_95 ) ) ;
V_4 -> V_32 = F_11 ( V_96 ) ;
F_50 ( V_4 -> V_32 == NULL ) ;
F_51 ( V_51 , & V_4 -> V_3 ) ;
F_18 ( V_51 , L_30 ) ;
return 0 ;
V_91:
F_45 ( V_4 -> V_54 ) ;
V_90:
F_45 ( V_4 -> V_56 ) ;
V_89:
F_45 ( V_4 -> V_87 ) ;
V_88:
F_45 ( V_4 -> V_64 ) ;
V_57:
F_18 ( V_51 , L_31 ) ;
return V_52 ;
}
static int F_52 ( struct V_76 * V_77 )
{
struct V_2 * V_3 = F_31 ( & V_77 -> V_51 ) ;
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_53 ( & V_77 -> V_51 ) ;
F_27 ( V_4 -> V_87 ) ;
F_45 ( V_4 -> V_54 ) ;
F_45 ( V_4 -> V_56 ) ;
F_45 ( V_4 -> V_87 ) ;
F_45 ( V_4 -> V_64 ) ;
F_18 ( & V_77 -> V_51 , L_32 ) ;
return 0 ;
}
