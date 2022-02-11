static int F_1 ( struct V_1 * V_2 , int type , T_1 V_3 ,
struct V_4 * V_5 )
{
return F_2 ( type , V_2 -> V_6 , V_3 , V_5 ) ;
}
static void F_3 ( struct V_1 * V_2 , struct V_4 * V_5 )
{
F_4 ( V_5 ) ;
}
static int F_5 ( struct V_7 * V_8 ,
struct V_9 * V_10 ,
T_1 V_3 )
{
return F_6 ( V_10 , V_3 ) ;
}
static int F_7 ( struct V_7 * V_8 ,
struct V_9 * V_10 )
{
return F_8 ( V_10 ) ;
}
static void F_9 ( T_2 V_11 , T_2 * V_12 )
{
F_10 ( V_11 , V_12 ) ;
}
static T_2 F_11 ( T_2 * V_12 )
{
return F_12 ( V_12 ) ;
}
static void F_13 ( T_3 V_11 , T_3 * V_12 )
{
unsigned int V_13 = ( ( unsigned long ) ( V_12 ) & 0x3 ) << 3 ;
void * V_14 = ( void * ) ( ( unsigned long ) ( V_12 ) & ~ 0x3 ) ;
T_2 V_15 ;
V_15 = F_12 ( V_14 ) ;
V_15 &= ~ ( 0xffff << V_13 ) ;
V_15 |= V_11 << V_13 ;
F_10 ( V_15 , V_14 ) ;
}
static T_3 F_14 ( T_3 * V_12 )
{
unsigned int V_13 = ( ( unsigned long ) ( V_12 ) & 0x3 ) << 3 ;
void * V_14 = ( void * ) ( ( unsigned long ) ( V_12 ) & ~ 0x3 ) ;
T_2 V_15 ;
V_15 = F_12 ( V_14 ) ;
return ( V_15 >> V_13 ) & 0xffff ;
}
static void F_15 ( T_4 V_11 , T_4 * V_12 )
{
unsigned int V_13 = ( ( unsigned long ) ( V_12 ) & 0x3 ) << 3 ;
void * V_14 = ( void * ) ( ( unsigned long ) ( V_12 ) & ~ 0x3 ) ;
T_2 V_15 ;
V_15 = F_12 ( V_14 ) ;
V_15 &= ~ ( 0xff << V_13 ) ;
V_15 |= V_11 << V_13 ;
F_10 ( V_15 , V_14 ) ;
}
static T_4 F_16 ( T_4 * V_12 )
{
unsigned int V_13 = ( ( unsigned long ) ( V_12 ) & 0x3 ) << 3 ;
void * V_14 = ( void * ) ( ( unsigned long ) ( V_12 ) & ~ 0x3 ) ;
T_2 V_15 ;
V_15 = F_12 ( V_14 ) ;
return ( V_15 >> V_13 ) & 0xff ;
}
static void F_17 ( struct V_16 * V_17 )
{
T_2 V_15 ;
V_15 = F_12 ( V_17 -> V_18 + V_19 ) ;
V_15 |= V_20 ;
F_10 ( V_15 , V_17 -> V_18 + V_19 ) ;
V_15 = F_12 ( V_17 -> V_18 + V_21 ) ;
V_15 &= ~ V_22 ;
V_15 |= V_23 | V_24 |
V_25 | V_26 ;
F_10 ( V_15 , V_17 -> V_18 + V_21 ) ;
F_10 ( V_27 , V_17 -> V_18 + V_28 ) ;
F_10 ( V_29 , V_17 -> V_18 + V_28 ) ;
F_10 ( V_30 , V_17 -> V_18 + V_31 ) ;
V_15 = F_12 ( V_17 -> V_18 + V_32 ) ;
V_15 |= V_33 ;
F_10 ( V_15 , V_17 -> V_18 + V_32 ) ;
}
static int F_18 ( struct V_16 * V_34 )
{
int V_35 ;
V_35 = F_19 ( V_34 -> V_36 ) ;
if ( V_35 )
return V_35 ;
V_35 = F_19 ( V_34 -> V_37 ) ;
if ( V_35 )
goto V_38;
V_35 = F_19 ( V_34 -> V_39 ) ;
if ( V_35 )
goto V_40;
return 0 ;
V_40:
F_20 ( V_34 -> V_37 ) ;
V_38:
F_20 ( V_34 -> V_36 ) ;
return V_35 ;
}
static void F_21 ( struct V_16 * V_34 )
{
F_20 ( V_34 -> V_39 ) ;
F_20 ( V_34 -> V_37 ) ;
F_20 ( V_34 -> V_36 ) ;
}
static int F_22 ( struct V_41 * V_6 )
{
struct V_42 * V_43 = F_23 ( V_6 ) ;
struct V_7 * V_8 = V_43 -> V_44 ;
struct V_16 * V_17 = F_24 ( V_8 , struct V_16 , V_8 ) ;
F_25 ( V_43 , V_45 ) ;
F_26 ( V_8 ) ;
F_27 ( V_8 ) ;
F_21 ( V_17 ) ;
return 0 ;
}
static int F_28 ( struct V_41 * V_6 )
{
struct V_42 * V_43 = F_23 ( V_6 ) ;
struct V_7 * V_8 = V_43 -> V_44 ;
struct V_16 * V_17 = F_24 ( V_8 , struct V_16 , V_8 ) ;
F_18 ( V_17 ) ;
F_17 ( V_17 ) ;
F_29 ( V_8 , 1 ) ;
F_25 ( V_43 , V_46 ) ;
return 0 ;
}
static int F_30 ( struct V_47 * V_41 )
{
struct V_7 * V_8 = V_41 -> V_48 ;
V_8 -> V_2 . V_49 = 1 ;
return 0 ;
}
static int F_31 ( struct V_47 * V_41 )
{
struct V_7 * V_8 = V_41 -> V_48 ;
struct V_16 * V_17 = F_24 ( V_8 , struct V_16 , V_8 ) ;
F_32 ( & V_17 -> V_50 ) ;
if ( F_33 ( V_8 ) -> V_51 ) {
F_34 ( V_8 ) ;
F_26 ( V_8 ) ;
}
F_35 ( V_8 ) ;
F_36 ( V_8 ) ;
F_37 ( F_33 ( V_8 ) ) ;
return 0 ;
}
static int F_38 ( struct V_7 * V_8 , struct V_52 * V_53 )
{
struct V_16 * V_17 = F_24 ( V_8 , struct V_16 , V_8 ) ;
struct V_1 * V_2 = F_33 ( V_8 ) ;
struct V_41 * V_6 = V_17 -> V_6 ;
struct V_54 * V_55 ;
int V_56 ;
V_17 -> V_36 = F_39 ( V_6 , L_1 ) ;
if ( F_40 ( V_17 -> V_36 ) ) {
F_41 ( V_6 , L_2 ) ;
return F_42 ( V_17 -> V_36 ) ;
}
V_17 -> V_37 = F_39 ( V_6 , L_3 ) ;
if ( F_40 ( V_17 -> V_37 ) ) {
F_41 ( V_6 , L_4 ) ;
return F_42 ( V_17 -> V_37 ) ;
}
V_17 -> V_39 = F_39 ( V_6 , L_5 ) ;
if ( F_40 ( V_17 -> V_39 ) ) {
F_41 ( V_6 , L_6 ) ;
return F_42 ( V_17 -> V_39 ) ;
}
V_55 = F_43 ( V_53 , V_57 , 0 ) ;
V_17 -> V_18 = F_44 ( V_6 , V_55 ) ;
if ( F_40 ( V_17 -> V_18 ) )
return F_42 ( V_17 -> V_18 ) ;
V_2 -> V_58 = V_17 -> V_18 + V_59 ;
V_2 -> V_12 = V_55 -> V_60 + V_59 ;
V_56 = F_18 ( V_17 ) ;
if ( V_56 ) {
F_41 ( V_6 , L_7 ) ;
return V_56 ;
}
F_17 ( V_17 ) ;
return 0 ;
}
static int F_45 ( struct V_7 * V_8 , struct V_52 * V_53 )
{
struct V_1 * V_2 = F_33 ( V_8 ) ;
struct V_42 * V_43 = V_8 -> V_43 ;
int V_56 ;
unsigned short V_61 ;
int V_62 = F_46 ( V_53 , 0 ) ;
V_56 = F_38 ( V_8 , V_53 ) ;
if ( V_56 )
return V_56 ;
V_56 = F_47 ( V_8 -> V_43 -> V_6 , V_62 , V_63 ,
V_64 , V_65 , V_8 ) ;
if ( V_56 ) {
F_41 ( V_8 -> V_43 -> V_6 ,
L_8 ,
V_62 ) ;
return V_56 ;
}
V_2 -> V_66 = V_62 ;
F_48 ( V_2 -> V_66 ) ;
V_61 = F_49 ( V_8 , V_67 ) ;
F_50 ( V_43 -> V_6 , L_9 , V_61 ) ;
V_8 -> V_68 = ( V_61 >> 8 ) & 0x0f ;
V_8 -> V_69 = ( V_61 >> 12 ) & 0x0f ;
if ( ! V_8 -> V_69 && ! V_8 -> V_68 ) {
V_8 -> V_69 = V_70 ;
V_8 -> V_68 = V_71 ;
}
V_8 -> V_72 = 0 ;
V_8 -> V_73 = V_8 -> V_68 ;
V_8 -> V_74 = V_8 -> V_69 + V_8 -> V_68 ;
V_56 = F_51 ( V_8 ) ;
if ( V_56 < 0 ) {
F_41 ( V_43 -> V_6 , L_10 , V_56 ) ;
return V_56 ;
}
V_56 = F_52 ( V_8 ) ;
if ( V_56 < 0 ) {
F_41 ( V_43 -> V_6 , L_11 ,
V_56 ) ;
return V_56 ;
}
F_29 ( V_8 , 1 ) ;
if ( ! V_2 -> V_75 ) {
F_41 ( V_43 -> V_6 , L_12 ) ;
return - V_76 ;
}
strcpy ( V_43 -> V_77 , L_13 ) ;
strcpy ( V_43 -> V_78 , L_13 ) ;
snprintf ( V_43 -> V_79 , sizeof( V_43 -> V_79 ) ,
L_14 ,
V_43 -> V_78 , V_2 -> V_12 , V_2 -> V_66 ) ;
return 0 ;
}
static int F_53 ( struct V_42 * V_43 ,
unsigned int V_80 ,
struct V_16 * V_17 )
{
static struct V_81 V_82 = {
. V_83 = F_30 ,
. V_84 = F_31 ,
} ;
struct V_7 * V_8 ;
int V_56 ;
V_8 = & V_17 -> V_8 ;
F_54 ( & V_8 -> V_85 ) ;
V_8 -> V_43 = V_43 ;
V_8 -> V_82 = & V_86 ;
V_8 -> V_80 = V_80 ;
V_8 -> V_87 = V_80 & 0xff ;
V_8 -> V_88 = 0 ;
F_55 ( & V_8 -> V_89 ) ;
V_8 -> V_90 = - 1 ;
V_8 -> V_91 = false ;
V_8 -> V_92 = true ;
F_56 ( & V_17 -> V_50 , V_93 ) ;
V_56 = F_57 ( V_8 , NULL , & V_94 ) ;
if ( V_56 < 0 )
return V_56 ;
V_8 -> V_2 . V_95 = 1 ;
V_56 = F_58 ( V_43 , V_96 , V_8 , & V_82 ) ;
if ( V_56 < 0 ) {
F_41 ( V_43 -> V_6 , L_15 ) ;
return V_56 ;
}
return 0 ;
}
static int F_59 ( struct V_52 * V_53 )
{
const unsigned int V_97 = V_98 ;
struct V_42 * V_43 ;
struct V_7 * V_8 ;
struct V_16 * V_17 ;
int V_56 ;
V_17 = F_60 ( & V_53 -> V_6 , sizeof( * V_17 ) , V_99 ) ;
if ( ! V_17 )
return - V_100 ;
V_17 -> V_6 = & V_53 -> V_6 ;
V_8 = & V_17 -> V_8 ;
V_56 = F_61 ( & V_53 -> V_6 , V_101 , V_102 ,
V_103 , 0 , & V_43 ) ;
if ( V_56 < 0 ) {
F_41 ( & V_53 -> V_6 , L_16 ) ;
return V_56 ;
}
V_56 = F_53 ( V_43 , V_97 , V_17 ) ;
if ( V_56 < 0 )
goto V_104;
V_43 -> V_44 = V_8 ;
F_62 ( & V_53 -> V_6 , V_43 ) ;
F_63 ( & V_17 -> V_50 ) ;
return 0 ;
V_104:
F_64 ( V_43 ) ;
return V_56 ;
}
static void V_93 ( struct V_105 * V_106 )
{
struct V_16 * V_17 = F_24 ( V_106 , struct V_16 , V_50 ) ;
struct V_7 * V_8 = & V_17 -> V_8 ;
struct V_52 * V_53 = F_65 ( V_17 -> V_6 ) ;
int V_56 ;
V_56 = F_45 ( V_8 , V_53 ) ;
if ( V_56 < 0 )
goto V_104;
V_56 = F_66 ( V_8 , 0 ) ;
if ( V_56 < 0 )
goto V_104;
V_56 = F_67 ( V_8 ) ;
if ( V_56 < 0 )
goto V_104;
V_56 = F_68 ( V_8 -> V_43 ) ;
if ( V_56 < 0 )
goto V_104;
V_8 -> V_107 = 1 ;
F_69 ( & V_8 -> V_2 , V_108 * 1000 ) ;
V_104:
return;
}
static int F_70 ( struct V_52 * V_53 )
{
return F_64 ( F_23 ( & V_53 -> V_6 ) ) ;
}
static void F_71 ( struct V_52 * V_53 )
{
struct V_42 * V_43 = F_23 ( & V_53 -> V_6 ) ;
struct V_7 * V_8 ;
if ( ! V_43 )
return;
V_8 = V_43 -> V_44 ;
if ( V_8 && V_8 -> V_107 )
F_26 ( V_8 ) ;
}
