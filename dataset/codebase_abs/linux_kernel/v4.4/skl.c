static void F_1 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned char V_4 , unsigned char V_5 )
{
unsigned char V_6 ;
F_2 ( V_2 , V_3 , & V_6 ) ;
V_6 &= ~ V_4 ;
V_6 |= ( V_5 & V_4 ) ;
F_3 ( V_2 , V_3 , V_6 ) ;
}
static void F_4 ( struct V_7 * V_7 )
{
struct V_8 * V_9 = & V_7 -> V_9 ;
F_5 ( F_6 ( V_9 ) -> V_10 , L_1 ) ;
F_1 ( V_7 -> V_2 , V_11 , 0x07 , 0 ) ;
}
static void F_7 ( struct V_12 * V_13 , struct V_14 * V_15 )
{
F_8 ( V_15 -> V_16 ) ;
}
static T_1 F_9 ( int V_17 , void * V_18 )
{
struct V_8 * V_9 = V_18 ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
T_2 V_19 ;
if ( ! F_10 ( V_13 -> V_10 ) )
return V_20 ;
F_11 ( & V_13 -> V_21 ) ;
V_19 = F_12 ( V_13 , V_22 ) ;
if ( V_19 == 0 || V_19 == 0xffffffff ) {
F_13 ( & V_13 -> V_21 ) ;
return V_20 ;
}
V_19 = F_14 ( V_13 , V_23 ) ;
if ( V_19 & V_24 ) {
if ( V_19 & V_25 )
F_15 ( V_13 ) ;
F_16 ( V_13 , V_23 , V_24 ) ;
}
F_13 ( & V_13 -> V_21 ) ;
return F_12 ( V_13 , V_22 ) ? V_26 : V_27 ;
}
static T_1 F_17 ( int V_17 , void * V_18 )
{
struct V_8 * V_9 = V_18 ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
T_2 V_19 ;
V_19 = F_12 ( V_13 , V_22 ) ;
F_18 ( V_13 , V_19 , F_7 ) ;
return V_27 ;
}
static int F_19 ( struct V_8 * V_9 , int V_28 )
{
struct V_7 * V_7 = F_20 ( V_9 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
int V_29 ;
V_29 = F_21 ( V_7 -> V_2 -> V_17 , F_9 ,
F_17 ,
V_30 ,
V_31 , V_9 ) ;
if ( V_29 ) {
F_22 ( V_13 -> V_10 ,
L_2 ,
V_7 -> V_2 -> V_17 ) ;
return V_29 ;
}
V_13 -> V_17 = V_7 -> V_2 -> V_17 ;
F_23 ( V_7 -> V_2 , 1 ) ;
return 0 ;
}
static int F_24 ( struct V_32 * V_10 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
struct V_8 * V_9 = F_26 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
F_27 ( V_13 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
static int F_29 ( struct V_32 * V_10 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
struct V_8 * V_9 = F_26 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
struct V_7 * V_33 = F_20 ( V_9 ) ;
F_4 ( V_33 ) ;
F_30 ( V_13 , 1 ) ;
return 0 ;
}
static int F_31 ( struct V_32 * V_10 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
struct V_8 * V_9 = F_26 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
struct V_7 * V_7 = F_20 ( V_9 ) ;
int V_29 ;
F_5 ( V_13 -> V_10 , L_3 , V_34 ) ;
F_32 ( V_13 , V_35 , 0 , V_36 ) ;
F_33 ( V_9 ) ;
V_29 = F_34 ( V_7 ) ;
if ( V_29 < 0 )
return V_29 ;
F_27 ( V_13 ) ;
F_28 ( V_13 ) ;
return 0 ;
}
static int F_35 ( struct V_32 * V_10 )
{
struct V_1 * V_2 = F_25 ( V_10 ) ;
struct V_8 * V_9 = F_26 ( V_2 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
struct V_7 * V_7 = F_20 ( V_9 ) ;
int V_19 ;
F_5 ( V_13 -> V_10 , L_3 , V_34 ) ;
V_19 = F_36 ( V_13 , V_37 ) ;
F_4 ( V_7 ) ;
F_30 ( V_13 , true ) ;
F_32 ( V_13 , V_35 , V_36 , 0 ) ;
return F_37 ( V_7 ) ;
}
static int F_38 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_20 ( V_9 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
V_7 -> V_38 = 1 ;
F_39 ( V_9 ) ;
if ( V_13 -> V_17 >= 0 )
F_40 ( V_13 -> V_17 , ( void * ) V_13 ) ;
if ( V_13 -> V_39 )
F_41 ( V_13 -> V_39 ) ;
F_42 ( V_13 ) ;
F_43 ( V_9 ) ;
F_44 ( V_9 ) ;
F_45 ( V_7 -> V_2 ) ;
F_46 ( V_7 -> V_2 ) ;
F_47 ( V_9 ) ;
return 0 ;
}
static int F_48 ( struct V_7 * V_7 )
{
struct V_12 * V_13 = F_6 ( & V_7 -> V_9 ) ;
struct V_40 * V_41 ;
int V_29 ;
V_41 = F_49 ( L_4 , - 1 ) ;
if ( ! V_41 ) {
F_22 ( V_13 -> V_10 , L_5 ) ;
return - V_42 ;
}
V_29 = F_50 ( V_41 ) ;
if ( V_29 ) {
F_22 ( V_13 -> V_10 , L_6 , V_29 ) ;
F_51 ( V_41 ) ;
return V_29 ;
}
V_7 -> V_43 = V_41 ;
return 0 ;
}
static void F_52 ( struct V_7 * V_7 )
{
if ( V_7 -> V_43 )
F_53 ( V_7 -> V_43 ) ;
}
static int F_54 ( struct V_8 * V_9 , int V_44 )
{
struct V_12 * V_13 = F_6 ( V_9 ) ;
unsigned int V_45 = ( V_44 << 28 ) | ( V_46 << 20 ) |
( V_47 << 8 ) | V_48 ;
unsigned int V_49 ;
F_55 ( & V_13 -> V_50 ) ;
F_56 ( V_13 , V_45 ) ;
F_57 ( V_13 , V_44 , & V_49 ) ;
F_58 ( & V_13 -> V_50 ) ;
if ( V_49 == - 1 )
return - V_51 ;
F_5 ( V_13 -> V_10 , L_7 , V_44 ) ;
return F_59 ( V_9 , V_44 ) ;
}
static int F_60 ( struct V_8 * V_9 )
{
struct V_12 * V_13 = F_6 ( V_9 ) ;
int V_52 , V_53 ;
V_53 = V_54 ;
for ( V_52 = 0 ; V_52 < V_53 ; V_52 ++ ) {
if ( ( V_13 -> V_55 & ( 1 << V_52 ) ) ) {
if ( F_54 ( V_9 , V_52 ) < 0 ) {
F_61 ( V_13 -> V_10 ,
L_8 , V_52 ) ;
V_13 -> V_55 &= ~ ( 1 << V_52 ) ;
F_27 ( V_13 ) ;
F_30 ( V_13 , true ) ;
}
}
}
return 0 ;
}
static int F_62 ( struct V_1 * V_2 ,
const struct V_56 * V_57 ,
struct V_7 * * V_58 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 ;
int V_59 ;
* V_58 = NULL ;
V_59 = F_63 ( V_2 ) ;
if ( V_59 < 0 )
return V_59 ;
V_7 = F_64 ( & V_2 -> V_10 , sizeof( * V_7 ) , V_60 ) ;
if ( ! V_7 ) {
F_46 ( V_2 ) ;
return - V_42 ;
}
V_9 = & V_7 -> V_9 ;
F_65 ( V_9 , & V_2 -> V_10 , & V_61 , V_57 ) ;
V_9 -> V_13 . V_62 = 1 ;
V_7 -> V_2 = V_2 ;
V_9 -> V_13 . V_63 = 0 ;
* V_58 = V_7 ;
return 0 ;
}
static int F_66 ( struct V_8 * V_9 )
{
struct V_7 * V_7 = F_20 ( V_9 ) ;
struct V_12 * V_13 = F_6 ( V_9 ) ;
struct V_1 * V_2 = V_7 -> V_2 ;
int V_59 ;
unsigned short V_64 ;
int V_65 , V_66 , V_67 ;
V_59 = F_67 ( V_2 , L_9 ) ;
if ( V_59 < 0 )
return V_59 ;
V_13 -> V_44 = F_68 ( V_2 , 0 ) ;
V_13 -> V_39 = F_69 ( V_2 , 0 ) ;
if ( V_13 -> V_39 == NULL ) {
F_22 ( V_13 -> V_10 , L_10 ) ;
return - V_68 ;
}
F_70 ( V_9 ) ;
if ( F_19 ( V_9 , 0 ) < 0 )
return - V_69 ;
F_71 ( V_2 ) ;
F_72 ( V_13 -> V_17 ) ;
V_64 = F_36 ( V_13 , V_70 ) ;
F_5 ( V_13 -> V_10 , L_11 , V_64 ) ;
if ( ! F_73 ( V_13 -> V_10 , F_74 ( 64 ) ) ) {
F_75 ( V_13 -> V_10 , F_74 ( 64 ) ) ;
} else {
F_73 ( V_13 -> V_10 , F_74 ( 32 ) ) ;
F_75 ( V_13 -> V_10 , F_74 ( 32 ) ) ;
}
V_65 = ( V_64 >> 8 ) & 0x0f ;
V_66 = ( V_64 >> 12 ) & 0x0f ;
if ( ! V_66 && ! V_65 )
return - V_51 ;
V_9 -> V_71 = V_65 + V_66 ;
F_76
( V_9 , 0 , V_65 , V_72 ) ;
V_67 = V_65 ;
F_76
( V_9 , V_67 , V_66 , V_73 ) ;
V_59 = F_77 ( V_13 ) ;
if ( V_59 < 0 )
return V_59 ;
F_4 ( V_7 ) ;
F_30 ( V_13 , true ) ;
if ( ! V_13 -> V_55 ) {
F_22 ( V_13 -> V_10 , L_12 ) ;
return - V_74 ;
}
return 0 ;
}
static int F_78 ( struct V_1 * V_2 ,
const struct V_75 * V_76 )
{
struct V_7 * V_7 ;
struct V_8 * V_9 = NULL ;
struct V_12 * V_13 = NULL ;
int V_59 ;
V_59 = F_62 ( V_2 , NULL , & V_7 ) ;
if ( V_59 < 0 )
return V_59 ;
V_9 = & V_7 -> V_9 ;
V_13 = F_6 ( V_9 ) ;
V_59 = F_66 ( V_9 ) ;
if ( V_59 < 0 )
goto V_77;
V_7 -> V_78 = F_79 ( V_13 -> V_10 ) ;
if ( V_7 -> V_78 == NULL )
goto V_77;
F_80 ( V_7 -> V_2 , V_9 ) ;
if ( V_9 -> V_79 ) {
V_59 = F_81 ( V_7 ) ;
if ( V_59 < 0 ) {
F_5 ( V_13 -> V_10 , L_13 ) ;
goto V_77;
}
}
if ( V_9 -> V_80 )
F_82 ( V_9 ) ;
V_59 = F_48 ( V_7 ) ;
if ( V_59 < 0 )
goto V_81;
V_59 = F_83 ( V_13 -> V_10 ) ;
if ( V_59 < 0 )
goto V_82;
V_59 = F_60 ( V_9 ) ;
if ( V_59 < 0 )
goto V_83;
F_84 ( V_13 -> V_10 , V_84 ) ;
F_85 ( V_13 -> V_10 ) ;
F_86 ( V_13 -> V_10 ) ;
F_87 ( V_13 -> V_10 ) ;
return 0 ;
V_83:
F_88 ( V_13 -> V_10 ) ;
V_82:
F_52 ( V_7 ) ;
V_81:
F_89 ( V_7 ) ;
V_77:
V_7 -> V_38 = 1 ;
F_38 ( V_9 ) ;
return V_59 ;
}
static void F_90 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_26 ( V_2 ) ;
struct V_7 * V_7 = F_20 ( V_9 ) ;
if ( V_7 -> V_85 )
F_91 ( V_7 -> V_85 ) ;
if ( F_92 ( V_2 ) )
F_93 ( & V_2 -> V_10 ) ;
F_94 ( V_2 ) ;
F_88 ( & V_2 -> V_10 ) ;
F_89 ( V_7 ) ;
F_52 ( V_7 ) ;
F_38 ( V_9 ) ;
F_95 ( & V_2 -> V_10 , NULL ) ;
}
