static void F_1 ( struct V_1 * V_2 , T_1 V_3 , T_2 V_4 )
{
F_2 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static void F_3 ( struct V_1 * V_2 , T_2 V_3 , T_2 V_4 )
{
F_4 ( V_3 , V_2 -> V_5 + V_4 ) ;
}
static T_1 F_5 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_6 ( V_2 -> V_5 + V_4 ) ;
}
static T_2 F_7 ( struct V_1 * V_2 , T_2 V_4 )
{
return F_8 ( V_2 -> V_5 + V_4 ) ;
}
static unsigned char F_9 ( struct V_1 * V_2 )
{
int V_6 ;
unsigned char V_7 ;
V_6 = F_10 ( V_2 -> V_8 ) / ( 2 * V_2 -> V_9 ) - 1 ;
V_7 = F_11 ( V_6 , 0 , 255 ) ;
return V_7 ;
}
static void F_12 ( struct V_1 * V_2 , T_1 V_10 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) | V_10 , V_11 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_12 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) & ~ V_12 , V_11 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 V_13 ,
T_1 V_14 )
{
int V_15 ;
V_2 -> V_16 = F_5 ( V_2 , V_17 ) ;
F_12 ( V_2 , V_14 ) ;
V_15 = F_15 ( V_2 -> V_18 , V_2 -> V_16 & V_13 , V_19 ) ;
if ( V_15 == 0 && ! ( V_2 -> V_16 & V_13 ) )
return - V_20 ;
return 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) | V_21 , V_11 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_1 ( V_2 , F_5 ( V_2 , V_11 ) & ~ V_21 , V_11 ) ;
}
static int F_18 ( struct V_1 * V_2 , int V_22 )
{
F_1 ( V_2 , 0x00 , V_23 ) ;
F_1 ( V_2 , F_9 ( V_2 ) , V_24 ) ;
F_1 ( V_2 , 0x00 , V_25 ) ;
F_1 ( V_2 , 0x00 , V_26 ) ;
F_1 ( V_2 , 0x00 , V_27 ) ;
F_1 ( V_2 , 0x00 , V_28 ) ;
F_1 ( V_2 , 0x00 , V_29 ) ;
F_3 ( V_2 , F_19 ( V_22 ) | V_30 ,
V_31 ) ;
F_1 ( V_2 , V_32 , V_11 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_37 = V_36 -> V_38 ;
T_1 * V_3 ;
V_3 = ( T_1 * ) V_36 -> V_39 ;
while ( V_37 > 0 ) {
F_1 ( V_2 , F_5 ( V_2 , V_11 ) | V_40 ,
V_11 ) ;
if ( F_14 ( V_2 , V_41 , V_42 ) < 0 ) {
F_21 ( & V_2 -> V_43 -> V_44 ,
L_1 , V_45 ) ;
return - V_20 ;
}
F_3 ( V_2 , * V_3 , V_46 ) ;
V_3 ++ ;
V_37 -- ;
}
F_14 ( V_2 , V_41 , V_42 ) ;
return 0 ;
}
static int F_22 ( struct V_1 * V_2 , struct V_33 * V_34 ,
struct V_35 * V_36 )
{
int V_37 = V_36 -> V_38 ;
T_1 * V_3 ;
unsigned char V_16 ;
V_16 = F_5 ( V_2 , V_17 ) ;
if ( V_16 & V_47 )
F_7 ( V_2 , V_46 ) ;
if ( V_16 & V_48 )
F_1 ( V_2 , F_5 ( V_2 , V_17 ) & ~ V_48 ,
V_11 ) ;
V_3 = ( T_1 * ) V_36 -> V_49 ;
while ( V_37 > 0 ) {
F_1 ( V_2 , F_5 ( V_2 , V_11 ) & ~ V_40 ,
V_11 ) ;
if ( F_14 ( V_2 , V_41 , V_42 ) < 0 ) {
F_21 ( & V_2 -> V_43 -> V_44 ,
L_1 , V_45 ) ;
return - V_20 ;
}
F_3 ( V_2 , 0x00 , V_46 ) ;
if ( F_14 ( V_2 , V_47 , V_50 ) < 0 ) {
F_21 ( & V_2 -> V_43 -> V_44 ,
L_2 , V_45 ) ;
return - V_20 ;
}
* V_3 = ( T_1 ) F_7 ( V_2 , V_46 ) ;
V_3 ++ ;
V_37 -- ;
}
return 0 ;
}
static void F_23 ( struct V_51 * V_52 )
{
struct V_1 * V_2 = F_24 ( V_52 , struct V_1 , V_53 ) ;
struct V_33 * V_34 ;
struct V_35 * V_36 ;
unsigned long V_54 ;
int V_15 ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
while ( ! F_26 ( & V_2 -> V_56 ) ) {
V_34 = F_27 ( V_2 -> V_56 . V_57 , struct V_33 , V_56 ) ;
F_28 ( & V_34 -> V_56 ) ;
F_29 ( & V_2 -> V_55 , V_54 ) ;
F_16 ( V_2 ) ;
F_30 (t, &mesg->transfers, transfer_list) {
if ( V_36 -> V_39 ) {
V_15 = F_20 ( V_2 , V_34 , V_36 ) ;
if ( V_15 < 0 )
goto error;
}
if ( V_36 -> V_49 ) {
V_15 = F_22 ( V_2 , V_34 , V_36 ) ;
if ( V_15 < 0 )
goto error;
}
V_34 -> V_58 += V_36 -> V_38 ;
}
F_17 ( V_2 ) ;
V_34 -> V_59 = 0 ;
V_34 -> V_60 ( V_34 -> V_61 ) ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
}
return;
error:
V_34 -> V_59 = V_15 ;
V_34 -> V_60 ( V_34 -> V_61 ) ;
}
static int F_31 ( struct V_62 * V_63 )
{
struct V_1 * V_2 = F_32 ( V_63 -> V_43 ) ;
if ( ! V_63 -> V_64 )
V_63 -> V_64 = 8 ;
V_2 -> V_9 = V_63 -> V_9 ;
F_18 ( V_2 , 8 ) ;
return 0 ;
}
static int F_33 ( struct V_62 * V_63 , struct V_33 * V_34 )
{
struct V_1 * V_2 = F_32 ( V_63 -> V_43 ) ;
unsigned long V_54 ;
V_34 -> V_58 = 0 ;
V_34 -> V_59 = - V_65 ;
F_25 ( & V_2 -> V_55 , V_54 ) ;
F_34 ( & V_34 -> V_56 , & V_2 -> V_56 ) ;
F_35 ( & V_2 -> V_53 ) ;
F_29 ( & V_2 -> V_55 , V_54 ) ;
return 0 ;
}
static void F_36 ( struct V_62 * V_63 )
{
}
static T_3 F_37 ( int V_66 , void * V_67 )
{
struct V_1 * V_2 = (struct V_1 * ) V_67 ;
unsigned long V_16 ;
T_3 V_15 = V_68 ;
unsigned char V_69 = 0 ;
V_2 -> V_16 = V_16 = F_5 ( V_2 , V_17 ) ;
if ( V_16 & V_47 )
V_69 |= V_50 ;
if ( V_16 & V_41 )
V_69 |= V_42 ;
if ( V_69 ) {
V_15 = V_70 ;
F_13 ( V_2 , V_69 ) ;
F_38 ( & V_2 -> V_18 ) ;
}
return V_15 ;
}
static int T_4 F_39 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_40 ( & V_72 -> V_44 ) ;
F_41 ( V_2 -> V_43 ) ;
F_42 ( F_43 ( V_72 , 0 ) , V_2 ) ;
F_44 ( V_2 -> V_8 ) ;
F_45 ( V_2 -> V_5 ) ;
F_46 ( V_2 -> V_43 ) ;
return 0 ;
}
static int T_5 F_47 ( struct V_71 * V_72 )
{
struct V_73 * V_74 ;
struct V_75 * V_43 ;
struct V_1 * V_2 ;
int V_15 , V_66 ;
char V_76 [ 16 ] ;
V_74 = F_48 ( V_72 , V_77 , 0 ) ;
if ( F_49 ( V_74 == NULL ) ) {
F_21 ( & V_72 -> V_44 , L_3 ) ;
return - V_78 ;
}
V_66 = F_43 ( V_72 , 0 ) ;
if ( V_66 < 0 ) {
F_21 ( & V_72 -> V_44 , L_4 ) ;
return - V_79 ;
}
V_43 = F_50 ( & V_72 -> V_44 , sizeof( struct V_1 ) ) ;
if ( V_43 == NULL ) {
F_21 ( & V_72 -> V_44 , L_5 ) ;
return - V_80 ;
}
V_2 = F_32 ( V_43 ) ;
F_51 ( & V_72 -> V_44 , V_2 ) ;
V_2 -> V_43 = V_43 ;
V_2 -> V_5 = F_52 ( V_74 -> V_81 , F_53 ( V_74 ) ) ;
if ( V_2 -> V_5 == NULL ) {
F_21 ( & V_72 -> V_44 , L_6 ) ;
V_15 = - V_80 ;
goto V_82;
}
snprintf ( V_76 , sizeof( V_76 ) , L_7 , V_72 -> V_83 ) ;
V_2 -> V_8 = F_54 ( & V_72 -> V_44 , V_76 ) ;
if ( F_55 ( V_2 -> V_8 ) ) {
F_21 ( & V_72 -> V_44 , L_8 ) ;
V_15 = F_56 ( V_2 -> V_8 ) ;
goto V_84;
}
F_57 ( V_2 -> V_8 ) ;
F_58 ( & V_2 -> V_56 ) ;
F_59 ( & V_2 -> V_55 ) ;
F_60 ( & V_2 -> V_53 , F_23 ) ;
F_61 ( & V_2 -> V_18 ) ;
V_43 -> V_85 = 2 ;
V_43 -> V_86 = V_72 -> V_83 ;
V_43 -> V_87 = F_31 ;
V_43 -> V_88 = F_33 ;
V_43 -> V_89 = F_36 ;
V_15 = F_62 ( V_66 , F_37 , 0 , F_63 ( & V_72 -> V_44 ) , V_2 ) ;
if ( V_15 < 0 ) {
F_21 ( & V_72 -> V_44 , L_9 ) ;
goto V_90;
}
V_15 = F_64 ( V_43 ) ;
if ( V_15 < 0 ) {
F_21 ( & V_72 -> V_44 , L_10 ) ;
goto V_91;
}
F_65 ( & V_72 -> V_44 , L_11 ) ;
return 0 ;
V_91:
F_42 ( V_66 , V_2 ) ;
V_90:
F_44 ( V_2 -> V_8 ) ;
V_84:
F_45 ( V_2 -> V_5 ) ;
V_82:
F_46 ( V_43 ) ;
return V_15 ;
}
