static void T_1 * F_1 ( struct V_1 * V_2 , unsigned V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned V_8 = V_2 -> V_9 / 32 ;
T_2 V_10 = V_3 / 32 ;
void T_1 * V_11 ;
V_11 = ( void T_1 * ) ( V_7 -> V_12 + V_5 * V_8 * 4 + V_10 * 4 ) ;
return V_11 ;
}
static void T_1 * F_3 ( struct V_1 * V_2 , unsigned V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
unsigned V_8 = V_2 -> V_9 / 32 ;
T_2 V_10 = V_3 / 16 ;
void T_1 * V_11 ;
V_11 = ( void T_1 * ) ( V_7 -> V_12 + V_5 * V_8 * 4 + V_10 * 4 ) ;
return V_11 ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_13 = F_3 ( V_2 , V_3 , V_14 ) ;
T_3 V_15 = F_5 ( V_13 ) ;
int V_16 = ( V_3 % 16 ) << 1 , V_17 = ( V_15 >> V_16 ) & 3 ;
if ( V_17 ) {
V_15 &= ~ ( 3 << V_16 ) ;
F_6 ( V_15 , V_13 ) ;
}
return 0 ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_18 = F_1 ( V_2 , V_3 , V_19 ) ;
return F_5 ( V_18 ) & F_8 ( V_3 % 32 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 , int V_15 )
{
void T_1 * V_20 , * V_21 ;
if ( V_15 ) {
V_20 = F_1 ( V_2 , V_3 , V_22 ) ;
F_6 ( F_8 ( V_3 % 32 ) , V_20 ) ;
} else {
V_21 = F_1 ( V_2 , V_3 , V_23 ) ;
F_6 ( F_8 ( V_3 % 32 ) , V_21 ) ;
}
}
static int F_10 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
void T_1 * V_24 = F_1 ( V_2 , V_3 , V_25 ) ;
T_3 V_15 ;
unsigned long V_26 ;
if ( V_7 -> V_27 )
F_11 ( & V_7 -> V_27 -> V_28 ) ;
F_12 ( & V_7 -> V_29 , V_26 ) ;
V_15 = F_5 ( V_24 ) ;
V_15 &= ~ F_8 ( V_3 % 32 ) ;
F_6 ( V_15 , V_24 ) ;
F_13 ( & V_7 -> V_29 , V_26 ) ;
if ( V_7 -> V_27 )
F_14 ( & V_7 -> V_27 -> V_28 ) ;
return 0 ;
}
static int F_15 ( struct V_1 * V_2 ,
unsigned V_3 , int V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
void T_1 * V_24 = F_1 ( V_2 , V_3 , V_25 ) ;
unsigned long V_26 ;
F_9 ( V_2 , V_3 , V_15 ) ;
if ( V_7 -> V_27 )
F_11 ( & V_7 -> V_27 -> V_28 ) ;
F_12 ( & V_7 -> V_29 , V_26 ) ;
V_15 = F_5 ( V_24 ) ;
V_15 |= F_8 ( V_3 % 32 ) ;
F_6 ( V_15 , V_24 ) ;
F_13 ( & V_7 -> V_29 , V_26 ) ;
if ( V_7 -> V_27 )
F_14 ( & V_7 -> V_27 -> V_28 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return F_17 ( V_7 -> V_30 , V_3 ) ;
}
static int F_18 ( struct V_31 * V_32 , unsigned type )
{
struct V_6 * V_7 = F_19 ( V_32 ) ;
T_3 V_33 = F_20 ( V_32 ) ;
unsigned long V_26 ;
T_3 V_15 ;
void T_1 * V_34 = F_1 ( & V_7 -> V_2 , V_33 , V_35 ) ;
void T_1 * V_36 = F_1 ( & V_7 -> V_2 , V_33 , V_37 ) ;
if ( V_33 >= V_7 -> V_2 . V_9 )
return - V_38 ;
if ( V_7 -> V_27 )
F_11 ( & V_7 -> V_27 -> V_28 ) ;
F_12 ( & V_7 -> V_29 , V_26 ) ;
if ( type & V_39 )
V_15 = F_5 ( V_34 ) | F_8 ( V_33 % 32 ) ;
else
V_15 = F_5 ( V_34 ) & ( ~ F_8 ( V_33 % 32 ) ) ;
F_6 ( V_15 , V_34 ) ;
if ( type & V_40 )
V_15 = F_5 ( V_36 ) | F_8 ( V_33 % 32 ) ;
else
V_15 = F_5 ( V_36 ) & ( ~ F_8 ( V_33 % 32 ) ) ;
F_6 ( V_15 , V_36 ) ;
F_13 ( & V_7 -> V_29 , V_26 ) ;
if ( V_7 -> V_27 )
F_14 ( & V_7 -> V_27 -> V_28 ) ;
return 0 ;
}
static void F_21 ( struct V_31 * V_32 )
{
}
static void F_22 ( struct V_31 * V_32 )
{
}
static void F_23 ( unsigned V_41 , struct V_42 * V_43 )
{
struct V_31 * V_44 = F_24 ( V_43 ) ;
struct V_6 * V_7 = F_25 ( V_44 ) ;
struct V_45 * V_2 = F_26 ( V_44 ) ;
T_3 V_46 , V_33 , V_47 ;
unsigned long V_48 ;
void T_1 * V_49 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_2 . V_9 ; V_46 += 32 ) {
V_49 = F_1 ( & V_7 -> V_2 , V_46 , V_50 ) ;
while ( ( V_48 = F_5 ( V_49 ) ) ) {
V_33 = F_27 ( V_48 ) ;
V_47 = F_8 ( V_33 ) ;
F_6 ( V_47 , V_49 ) ;
F_28 ( F_29 ( V_7 -> V_30 ,
V_46 + V_33 ) ) ;
}
}
V_2 -> V_51 ( V_44 ) ;
}
static void F_30 ( struct V_6 * V_7 )
{
void T_1 * V_10 ;
unsigned V_46 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_2 . V_9 ; V_46 += 32 ) {
V_10 = F_1 ( & V_7 -> V_2 , V_46 , V_35 ) ;
F_6 ( 0 , V_10 ) ;
V_10 = F_1 ( & V_7 -> V_2 , V_46 , V_37 ) ;
F_6 ( 0 , V_10 ) ;
V_10 = F_1 ( & V_7 -> V_2 , V_46 , V_50 ) ;
F_6 ( ~ 0 , V_10 ) ;
}
}
static int F_31 ( struct V_52 * V_32 , unsigned int V_53 ,
T_4 V_54 )
{
struct V_6 * V_7 = V_32 -> V_55 ;
F_32 ( V_53 , & V_56 , V_57 ,
L_1 ) ;
F_33 ( V_53 , V_7 ) ;
F_34 ( V_53 , V_58 ) ;
return 0 ;
}
static int F_35 ( struct V_59 * V_28 )
{
int V_60 = F_36 ( V_28 , 500 ) ;
if ( ! V_60 )
return 0 ;
return - V_61 ;
}
static int F_37 ( struct V_62 * V_27 ,
const struct V_63 * V_64 )
{
void * V_46 ;
T_5 V_65 , V_66 ;
struct V_6 * V_7 ;
T_3 V_67 ;
T_3 V_68 ;
int V_69 ;
int V_9 = V_64 -> V_70 ;
V_69 = F_38 ( V_27 ) ;
if ( V_69 )
return V_69 ;
V_69 = F_39 ( V_27 , L_2 ) ;
if ( V_69 ) {
F_40 ( & V_27 -> V_28 , L_3 ) ;
goto V_71;
}
V_65 = F_41 ( V_27 , 1 ) ;
V_66 = F_42 ( V_27 , 1 ) ;
V_46 = F_43 ( V_65 , V_66 ) ;
if ( ! V_46 ) {
F_40 ( & V_27 -> V_28 , L_4 ) ;
V_69 = - V_72 ;
goto V_73;
}
V_68 = * ( T_3 * ) V_46 ;
V_67 = * ( ( T_3 * ) V_46 + 1 ) ;
F_44 ( V_46 ) ;
V_65 = F_41 ( V_27 , 0 ) ;
V_66 = F_42 ( V_27 , 0 ) ;
V_46 = F_45 ( & V_27 -> V_28 , V_65 , V_66 ) ;
if ( ! V_46 ) {
F_40 ( & V_27 -> V_28 , L_5 ) ;
V_69 = - V_72 ;
goto V_73;
}
V_7 = F_46 ( & V_27 -> V_28 , sizeof( * V_7 ) , V_74 ) ;
if ( ! V_7 ) {
F_40 ( & V_27 -> V_28 , L_6 ) ;
V_69 = - V_75 ;
goto V_73;
}
V_7 -> V_12 = V_46 ;
V_7 -> V_2 . V_76 = F_47 ( & V_27 -> V_28 ) ;
V_7 -> V_2 . V_77 = F_4 ;
V_7 -> V_2 . V_78 = F_10 ;
V_7 -> V_2 . V_79 = F_15 ;
V_7 -> V_2 . V_80 = F_7 ;
V_7 -> V_2 . V_81 = F_9 ;
V_7 -> V_2 . V_82 = F_16 ;
V_7 -> V_2 . V_46 = V_67 ;
V_7 -> V_2 . V_9 = V_9 ;
V_7 -> V_2 . V_83 = 0 ;
V_7 -> V_27 = V_27 ;
V_7 -> V_30 = F_48 ( V_27 -> V_28 . V_84 , V_9 , V_68 ,
& V_85 , V_7 ) ;
if ( ! V_7 -> V_30 ) {
V_69 = - V_75 ;
goto V_73;
}
F_49 ( V_27 , V_7 ) ;
V_69 = F_50 ( & V_7 -> V_2 ) ;
if ( V_69 ) {
F_40 ( & V_27 -> V_28 , L_7 , V_69 ) ;
goto V_73;
}
F_30 ( V_7 ) ;
F_51 ( V_27 -> V_41 , V_7 ) ;
F_52 ( V_27 -> V_41 , F_23 ) ;
F_53 ( & V_7 -> V_29 ) ;
F_54 ( & V_27 -> V_28 ) ;
F_55 ( & V_27 -> V_28 ) ;
return 0 ;
V_73:
F_56 ( V_27 ) ;
V_71:
F_57 ( V_27 ) ;
return V_69 ;
}
static int F_58 ( struct V_86 * V_27 )
{
struct V_6 * V_7 ;
struct V_1 * V_87 ;
struct V_88 * V_89 ;
int V_69 = 0 ;
V_89 = F_59 ( V_27 , V_90 , 0 ) ;
if ( ! V_89 )
return - V_38 ;
V_7 = F_60 ( sizeof( struct V_6 ) , V_74 ) ;
if ( ! V_7 ) {
F_40 ( & V_27 -> V_28 ,
L_8 ) ;
return - V_75 ;
}
V_7 -> V_12 = F_43 ( V_89 -> V_65 , F_61 ( V_89 ) ) ;
if ( V_7 -> V_12 == NULL ) {
V_69 = - V_38 ;
goto V_91;
}
F_53 ( & V_7 -> V_29 ) ;
V_87 = & V_7 -> V_2 ;
V_87 -> V_76 = F_47 ( & V_27 -> V_28 ) ;
V_87 -> V_92 = V_93 ;
V_87 -> V_78 = F_10 ;
V_87 -> V_79 = F_15 ;
V_87 -> V_80 = F_7 ;
V_87 -> V_81 = F_9 ;
V_87 -> V_82 = NULL ;
V_87 -> V_46 = 0 ;
V_87 -> V_9 = 64 ;
V_87 -> V_83 = 0 ;
V_69 = F_50 ( V_87 ) ;
if ( V_69 ) {
F_40 ( & V_27 -> V_28 , L_9 ,
V_69 ) ;
goto V_73;
}
F_62 ( V_27 , V_7 ) ;
return 0 ;
V_73:
F_44 ( V_7 -> V_12 ) ;
V_91:
F_63 ( V_7 ) ;
return V_69 ;
}
static int F_64 ( struct V_86 * V_27 )
{
struct V_6 * V_7 = F_65 ( V_27 ) ;
int V_60 ;
V_60 = F_66 ( & V_7 -> V_2 ) ;
if ( V_60 )
F_40 ( & V_27 -> V_28 , L_10 ) ;
F_44 ( V_7 -> V_12 ) ;
F_63 ( V_7 ) ;
F_62 ( V_27 , NULL ) ;
return 0 ;
}
static int T_6 F_67 ( void )
{
int V_94 ;
V_94 = F_68 ( & V_95 ) ;
if ( V_94 < 0 )
return V_94 ;
V_94 = F_69 ( & V_96 ) ;
if ( V_94 < 0 )
F_70 ( & V_95 ) ;
return V_94 ;
}
