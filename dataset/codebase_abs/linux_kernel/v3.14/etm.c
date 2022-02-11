static inline bool F_1 ( struct V_1 * V_2 )
{
return ! ! ( V_2 -> V_3 & V_4 ) ;
}
static int F_2 ( struct V_1 * V_2 , int V_5 ,
unsigned long V_6 , unsigned long V_7 , int V_8 , int V_9 )
{
T_1 V_3 = V_10 | V_11 | V_12 | \
V_13 ;
if ( V_5 < 1 || V_5 > V_2 -> V_14 )
return - V_15 ;
V_5 -- ;
if ( V_9 )
V_3 |= V_16 ;
else
V_3 |= V_17 ;
F_3 ( V_2 , V_3 , F_4 ( V_5 * 2 ) ) ;
F_3 ( V_2 , V_6 , F_5 ( V_5 * 2 ) ) ;
F_3 ( V_2 , V_3 , F_4 ( V_5 * 2 + 1 ) ) ;
F_3 ( V_2 , V_7 , F_5 ( V_5 * 2 + 1 ) ) ;
V_3 = V_8 ? V_18 : 0 ;
F_3 ( V_2 , V_3 | ( 1 << V_5 ) , V_19 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
T_1 V_20 ;
unsigned long V_21 = V_22 ;
F_7 ( V_2 ) ;
F_8 ( V_2 , 0 , V_23 ) ;
F_8 ( V_2 , 1 , V_24 ) ;
F_9 ( V_2 ) ;
V_20 = V_25 | V_26 | F_10 ( V_2 -> V_27 ) ;
if ( V_2 -> V_3 & V_28 )
V_20 |= V_29 ;
F_11 ( V_2 ) ;
F_3 ( V_2 , V_20 , V_30 ) ;
while ( ! ( F_12 ( V_2 , V_30 ) & V_26 ) && -- V_21 )
;
if ( ! V_21 ) {
F_13 ( V_2 -> V_31 , L_1 ) ;
F_14 ( V_2 ) ;
return - V_32 ;
}
F_2 ( V_2 , 1 , ( unsigned long ) V_33 ,
( unsigned long ) V_34 , 0 , 0 ) ;
F_3 ( V_2 , 0 , V_35 ) ;
F_3 ( V_2 , 0 , V_36 ) ;
F_3 ( V_2 , 0x6f , V_37 ) ;
V_20 &= ~ V_26 ;
V_20 |= V_38 ;
F_3 ( V_2 , V_20 , V_30 ) ;
V_21 = V_22 ;
while ( F_12 ( V_2 , V_30 ) & V_26 && -- V_21 )
;
if ( ! V_21 ) {
F_13 ( V_2 -> V_31 , L_2 ) ;
F_14 ( V_2 ) ;
return - V_32 ;
}
F_14 ( V_2 ) ;
V_2 -> V_3 |= V_4 ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 )
{
unsigned long V_21 = V_22 ;
F_11 ( V_2 ) ;
F_3 ( V_2 , 0x440 , V_30 ) ;
while ( ! ( F_12 ( V_2 , V_30 ) & V_26 ) && -- V_21 )
;
if ( ! V_21 ) {
F_13 ( V_2 -> V_31 , L_1 ) ;
F_14 ( V_2 ) ;
return - V_32 ;
}
F_14 ( V_2 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 , V_39 , V_23 ) ;
V_21 = V_22 ;
while ( F_16 ( V_2 , V_23 ) &
V_39 && -- V_21 )
;
if ( ! V_21 ) {
F_13 ( V_2 -> V_31 , L_3
L_4 ) ;
F_9 ( V_2 ) ;
return - V_32 ;
}
F_8 ( V_2 , 0 , V_24 ) ;
F_9 ( V_2 ) ;
V_2 -> V_3 &= ~ V_4 ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 )
{
T_1 V_20 ;
int V_40 , V_41 ;
V_20 = F_16 ( V_2 , V_42 ) ;
if ( V_20 & 1 )
return V_2 -> V_43 ;
V_40 = F_16 ( V_2 , V_44 ) ;
V_41 = F_16 ( V_2 , V_45 ) ;
if ( V_40 > V_41 ) {
F_8 ( V_2 , 0 , V_44 ) ;
F_8 ( V_2 , 0 , V_45 ) ;
return 0 ;
}
return V_41 - V_40 ;
}
static void F_18 ( void )
{
struct V_1 * V_2 = & V_46 ;
T_1 V_47 = 0 ;
int V_48 ;
if ( ! V_2 -> V_49 ) {
F_19 ( V_50 L_5 ) ;
return;
}
if ( F_1 ( V_2 ) )
F_15 ( V_2 ) ;
F_7 ( V_2 ) ;
V_48 = F_17 ( V_2 ) ;
if ( V_48 == V_2 -> V_43 )
V_47 = F_16 ( V_2 , V_45 ) ;
F_8 ( V_2 , V_47 , V_44 ) ;
F_19 ( V_50 L_6 , V_48 ) ;
F_19 ( V_50 L_7 ) ;
for (; V_48 ; V_48 -- )
F_19 ( L_8 , F_20 ( F_16 ( V_2 , V_51 ) ) ) ;
F_19 ( V_50 L_9 ) ;
F_8 ( V_2 , 1 , V_24 ) ;
F_8 ( V_2 , 0 , V_24 ) ;
F_8 ( V_2 , 0 , V_52 ) ;
F_8 ( V_2 , 0 , V_44 ) ;
F_8 ( V_2 , 0 , V_45 ) ;
F_9 ( V_2 ) ;
}
static void F_21 ( int V_53 )
{
F_13 ( V_46 . V_31 , L_10 ) ;
F_18 () ;
}
static int F_22 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
if ( ! V_46 . V_49 )
return - V_56 ;
V_55 -> V_57 = & V_46 ;
return F_23 ( V_54 , V_55 ) ;
}
static T_2 F_24 ( struct V_55 * V_55 , char T_3 * V_9 ,
T_4 V_58 , T_5 * V_59 )
{
int V_60 , V_61 ;
long V_48 ;
struct V_1 * V_2 = V_55 -> V_57 ;
T_1 V_47 = 0 ;
T_1 * V_62 ;
F_25 ( & V_2 -> V_63 ) ;
if ( F_1 ( V_2 ) ) {
V_48 = 0 ;
goto V_64;
}
F_7 ( V_2 ) ;
V_60 = F_17 ( V_2 ) ;
if ( V_60 == V_2 -> V_43 )
V_47 = F_16 ( V_2 , V_45 ) ;
F_8 ( V_2 , V_47 , V_44 ) ;
V_48 = F_26 ( V_60 * 4 , ( int ) V_58 ) ;
V_62 = F_27 ( V_48 ) ;
F_13 ( V_2 -> V_31 , L_11 , V_60 ) ;
F_13 ( V_2 -> V_31 , L_12 , F_16 ( V_2 , V_42 ) ) ;
for ( V_61 = 0 ; V_61 < V_48 / 4 ; V_61 ++ )
V_62 [ V_61 ] = F_16 ( V_2 , V_51 ) ;
F_8 ( V_2 , 1 , V_24 ) ;
F_8 ( V_2 , 0 , V_24 ) ;
F_8 ( V_2 , 0 , V_45 ) ;
F_8 ( V_2 , 0 , V_44 ) ;
F_8 ( V_2 , 0 , V_52 ) ;
F_9 ( V_2 ) ;
V_48 -= F_28 ( V_9 , V_62 , V_48 ) ;
F_29 ( V_62 ) ;
V_64:
F_30 ( & V_2 -> V_63 ) ;
return V_48 ;
}
static int F_31 ( struct V_54 * V_54 , struct V_55 * V_55 )
{
return 0 ;
}
static int F_32 ( struct V_65 * V_31 , const struct V_66 * V_67 )
{
struct V_1 * V_2 = & V_46 ;
int V_68 = 0 ;
V_68 = F_33 ( V_31 , NULL ) ;
if ( V_68 )
goto V_64;
V_2 -> V_49 = F_34 ( V_31 -> V_69 . V_6 , F_35 ( & V_31 -> V_69 ) ) ;
if ( ! V_2 -> V_49 ) {
V_68 = - V_70 ;
goto V_71;
}
F_36 ( V_31 , V_2 ) ;
V_72 . V_73 = & V_31 -> V_31 ;
V_68 = F_37 ( & V_72 ) ;
if ( V_68 )
goto V_74;
V_2 -> V_75 = F_38 ( & V_31 -> V_31 , L_13 ) ;
if ( F_39 ( V_2 -> V_75 ) ) {
F_13 ( & V_31 -> V_31 , L_14 ) ;
return - V_32 ;
}
F_40 ( V_2 -> V_75 ) ;
F_7 ( V_2 ) ;
V_2 -> V_43 = F_16 ( V_2 , V_76 ) ;
F_13 ( & V_31 -> V_31 , L_15 , V_2 -> V_43 ) ;
F_8 ( V_2 , 0 , V_24 ) ;
F_8 ( V_2 , 0x1000 , V_23 ) ;
F_9 ( V_2 ) ;
F_13 ( & V_31 -> V_31 , L_16 ) ;
V_64:
return V_68 ;
V_74:
F_41 ( V_2 -> V_49 ) ;
V_71:
F_42 ( V_31 ) ;
return V_68 ;
}
static int F_43 ( struct V_65 * V_31 )
{
struct V_1 * V_2 = F_44 ( V_31 ) ;
F_41 ( V_2 -> V_49 ) ;
V_2 -> V_49 = NULL ;
F_45 ( V_2 -> V_75 ) ;
F_46 ( V_2 -> V_75 ) ;
F_42 ( V_31 ) ;
return 0 ;
}
static T_2 F_47 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
char * V_62 )
{
return sprintf ( V_62 , L_17 , F_1 ( & V_46 ) ) ;
}
static T_2 F_48 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
const char * V_62 , T_4 V_5 )
{
unsigned int V_81 ;
int V_68 ;
if ( sscanf ( V_62 , L_18 , & V_81 ) != 1 )
return - V_15 ;
F_25 ( & V_46 . V_63 ) ;
V_68 = V_81 ? F_6 ( & V_46 ) : F_15 ( & V_46 ) ;
F_30 ( & V_46 . V_63 ) ;
return V_68 ? : V_5 ;
}
static T_2 F_49 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
char * V_62 )
{
T_1 V_82 , V_83 , V_84 , V_85 , V_86 , V_87 ;
int V_88 ;
F_7 ( & V_46 ) ;
V_88 = F_17 ( & V_46 ) ;
V_82 = F_16 ( & V_46 , V_45 ) ;
V_83 = F_16 ( & V_46 , V_44 ) ;
V_84 = F_16 ( & V_46 , V_42 ) ;
V_85 = F_16 ( & V_46 , V_23 ) ;
F_9 ( & V_46 ) ;
F_11 ( & V_46 ) ;
V_86 = F_12 ( & V_46 , V_30 ) ;
V_87 = F_12 ( & V_46 , V_89 ) ;
F_14 ( & V_46 ) ;
return sprintf ( V_62 , L_19
L_20
L_21
L_22
L_23
L_24
L_25 ,
V_88 ,
V_46 . V_14 ,
V_82 ,
V_83 ,
V_84 ,
V_85 ,
V_86 ,
V_87
) ;
}
static T_2 F_50 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
char * V_62 )
{
return sprintf ( V_62 , L_26 ,
! ! ( V_46 . V_3 & V_28 ) ,
V_46 . V_27 ) ;
}
static T_2 F_51 ( struct V_77 * V_78 ,
struct V_79 * V_80 ,
const char * V_62 , T_4 V_5 )
{
unsigned int V_90 , V_91 ;
if ( sscanf ( V_62 , L_27 , & V_90 , & V_91 ) != 2 )
return - V_15 ;
F_25 ( & V_46 . V_63 ) ;
if ( V_90 )
V_46 . V_3 |= V_28 ;
else
V_46 . V_3 &= ~ V_28 ;
V_46 . V_27 = V_91 & 0x0f ;
F_30 ( & V_46 . V_63 ) ;
return V_5 ;
}
static int F_52 ( struct V_65 * V_31 , const struct V_66 * V_67 )
{
struct V_1 * V_2 = & V_46 ;
int V_68 = 0 ;
if ( V_2 -> V_92 ) {
F_13 ( & V_31 -> V_31 , L_28 ) ;
V_68 = - V_93 ;
goto V_64;
}
V_68 = F_33 ( V_31 , NULL ) ;
if ( V_68 )
goto V_64;
V_2 -> V_92 = F_34 ( V_31 -> V_69 . V_6 , F_35 ( & V_31 -> V_69 ) ) ;
if ( ! V_2 -> V_92 ) {
V_68 = - V_70 ;
goto V_71;
}
F_36 ( V_31 , V_2 ) ;
F_53 ( & V_2 -> V_63 ) ;
V_2 -> V_31 = & V_31 -> V_31 ;
V_2 -> V_3 = V_28 ;
V_2 -> V_27 = 1 ;
F_11 ( V_2 ) ;
( void ) F_12 ( V_2 , V_94 ) ;
( void ) F_12 ( & V_46 , V_95 ) ;
V_2 -> V_14 = F_12 ( V_2 , V_96 ) & 0xf ;
F_3 ( V_2 , 0x440 , V_30 ) ;
F_14 ( V_2 ) ;
V_68 = F_54 ( & V_31 -> V_31 . V_78 ,
& V_97 . V_80 ) ;
if ( V_68 )
goto V_74;
V_68 = F_54 ( & V_31 -> V_31 . V_78 , & V_98 . V_80 ) ;
if ( V_68 )
F_13 ( & V_31 -> V_31 , L_29 ) ;
V_68 = F_54 ( & V_31 -> V_31 . V_78 , & V_99 . V_80 ) ;
if ( V_68 )
F_13 ( & V_31 -> V_31 , L_30 ) ;
F_13 ( V_2 -> V_31 , L_31 ) ;
V_64:
return V_68 ;
V_74:
F_41 ( V_2 -> V_92 ) ;
V_71:
F_42 ( V_31 ) ;
return V_68 ;
}
static int F_55 ( struct V_65 * V_31 )
{
struct V_1 * V_2 = F_44 ( V_31 ) ;
F_41 ( V_2 -> V_92 ) ;
V_2 -> V_92 = NULL ;
F_42 ( V_31 ) ;
F_56 ( & V_31 -> V_31 . V_78 , & V_97 . V_80 ) ;
F_56 ( & V_31 -> V_31 . V_78 , & V_98 . V_80 ) ;
F_56 ( & V_31 -> V_31 . V_78 , & V_99 . V_80 ) ;
return 0 ;
}
static int T_6 F_57 ( void )
{
int V_100 ;
V_100 = F_58 ( & V_101 ) ;
if ( V_100 ) {
F_19 ( V_102 L_32 ) ;
return V_100 ;
}
V_100 = F_58 ( & V_103 ) ;
if ( V_100 ) {
F_59 ( & V_101 ) ;
F_19 ( V_102 L_33 ) ;
return V_100 ;
}
( void ) F_60 ( 'v' , & V_104 ) ;
return 0 ;
}
