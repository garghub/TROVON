static void T_1 * F_1 ( struct V_1 * V_2 , unsigned V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
unsigned V_8 = V_2 -> V_9 / 32 ;
T_2 V_10 = V_3 / 32 ;
void T_1 * V_11 ;
V_11 = ( void T_1 * ) ( V_7 -> V_12 + V_5 * V_8 * 4 + V_10 * 4 ) ;
return V_11 ;
}
static int F_3 ( struct V_1 * V_2 , unsigned V_3 )
{
void T_1 * V_13 = F_1 ( V_2 , V_3 , V_14 ) ;
return F_4 ( V_13 ) & F_5 ( V_3 % 32 ) ;
}
static void F_6 ( struct V_1 * V_2 , unsigned V_3 , int V_15 )
{
void T_1 * V_16 , * V_17 ;
if ( V_15 ) {
V_16 = F_1 ( V_2 , V_3 , V_18 ) ;
F_7 ( F_5 ( V_3 % 32 ) , V_16 ) ;
} else {
V_17 = F_1 ( V_2 , V_3 , V_19 ) ;
F_7 ( F_5 ( V_3 % 32 ) , V_17 ) ;
}
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
void T_1 * V_20 = F_1 ( V_2 , V_3 , V_21 ) ;
T_3 V_15 ;
unsigned long V_22 ;
if ( V_7 -> V_23 )
F_9 ( & V_7 -> V_23 -> V_24 ) ;
F_10 ( & V_7 -> V_25 , V_22 ) ;
V_15 = F_4 ( V_20 ) ;
V_15 &= ~ F_5 ( V_3 % 32 ) ;
F_7 ( V_15 , V_20 ) ;
F_11 ( & V_7 -> V_25 , V_22 ) ;
if ( V_7 -> V_23 )
F_12 ( & V_7 -> V_23 -> V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_3 , int V_15 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
void T_1 * V_20 = F_1 ( V_2 , V_3 , V_21 ) ;
unsigned long V_22 ;
F_6 ( V_2 , V_3 , V_15 ) ;
if ( V_7 -> V_23 )
F_9 ( & V_7 -> V_23 -> V_24 ) ;
F_10 ( & V_7 -> V_25 , V_22 ) ;
V_15 = F_4 ( V_20 ) ;
V_15 |= F_5 ( V_3 % 32 ) ;
F_7 ( V_15 , V_20 ) ;
F_11 ( & V_7 -> V_25 , V_22 ) ;
if ( V_7 -> V_23 )
F_12 ( & V_7 -> V_23 -> V_24 ) ;
return 0 ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return V_7 -> V_26 + V_3 ;
}
static int F_15 ( struct V_27 * V_28 , unsigned type )
{
struct V_6 * V_7 = F_16 ( V_28 ) ;
T_3 V_29 = V_28 -> V_30 - V_7 -> V_26 ;
unsigned long V_22 ;
T_3 V_15 ;
void T_1 * V_31 = F_1 ( & V_7 -> V_2 , V_29 , V_32 ) ;
void T_1 * V_33 = F_1 ( & V_7 -> V_2 , V_29 , V_34 ) ;
if ( V_29 >= V_7 -> V_2 . V_9 )
return - V_35 ;
if ( V_7 -> V_23 )
F_9 ( & V_7 -> V_23 -> V_24 ) ;
F_10 ( & V_7 -> V_25 , V_22 ) ;
if ( type & V_36 )
V_15 = F_4 ( V_31 ) | F_5 ( V_29 % 32 ) ;
else
V_15 = F_4 ( V_31 ) & ( ~ F_5 ( V_29 % 32 ) ) ;
F_7 ( V_15 , V_31 ) ;
if ( type & V_37 )
V_15 = F_4 ( V_33 ) | F_5 ( V_29 % 32 ) ;
else
V_15 = F_4 ( V_33 ) & ( ~ F_5 ( V_29 % 32 ) ) ;
F_7 ( V_15 , V_33 ) ;
F_11 ( & V_7 -> V_25 , V_22 ) ;
if ( V_7 -> V_23 )
F_12 ( & V_7 -> V_23 -> V_24 ) ;
return 0 ;
}
static void F_17 ( struct V_27 * V_28 )
{
}
static void F_18 ( struct V_27 * V_28 )
{
}
static void F_19 ( unsigned V_30 , struct V_38 * V_39 )
{
struct V_27 * V_40 = F_20 ( V_39 ) ;
struct V_6 * V_7 = F_21 ( V_40 ) ;
struct V_41 * V_2 = F_22 ( V_40 ) ;
T_3 V_42 , V_29 , V_43 ;
unsigned long V_44 ;
void T_1 * V_45 ;
for ( V_42 = 0 ; V_42 < V_7 -> V_2 . V_9 ; V_42 += 32 ) {
V_45 = F_1 ( & V_7 -> V_2 , V_42 , V_46 ) ;
V_44 = F_4 ( V_45 ) ;
while ( V_44 ) {
V_29 = F_23 ( V_44 ) ;
V_43 = F_5 ( V_29 ) ;
V_44 &= ~ V_43 ;
F_7 ( V_43 , V_45 ) ;
F_24 ( V_7 -> V_26 + V_42 + V_29 ) ;
}
}
V_2 -> V_47 ( V_40 ) ;
}
static int F_25 ( struct V_48 * V_24 )
{
return 0 ;
}
static int F_26 ( struct V_48 * V_24 )
{
return 0 ;
}
static int F_27 ( struct V_48 * V_24 )
{
int V_49 = F_28 ( V_24 , 500 ) ;
if ( ! V_49 )
return 0 ;
return - V_50 ;
}
static int T_4 F_29 ( struct V_51 * V_23 ,
const struct V_52 * V_53 )
{
void * V_42 ;
int V_54 ;
T_5 V_55 , V_56 ;
struct V_6 * V_7 ;
T_3 V_26 ;
T_3 V_57 ;
int V_58 = 0 ;
V_58 = F_30 ( V_23 ) ;
if ( V_58 )
goto V_59;
V_58 = F_31 ( V_23 , L_1 ) ;
if ( V_58 ) {
F_32 ( & V_23 -> V_24 , L_2 ) ;
goto V_60;
}
V_55 = F_33 ( V_23 , 1 ) ;
V_56 = F_34 ( V_23 , 1 ) ;
V_42 = F_35 ( V_55 , V_56 ) ;
if ( ! V_42 ) {
F_32 ( & V_23 -> V_24 , L_3 ) ;
goto V_61;
}
V_26 = * ( T_3 * ) V_42 ;
V_57 = * ( ( T_3 * ) V_42 + 1 ) ;
F_36 ( V_42 ) ;
V_55 = F_33 ( V_23 , 0 ) ;
V_56 = F_34 ( V_23 , 0 ) ;
V_42 = F_35 ( V_55 , V_56 ) ;
if ( ! V_42 ) {
F_32 ( & V_23 -> V_24 , L_4 ) ;
V_58 = - V_62 ;
goto V_61;
}
V_7 = F_37 ( sizeof( struct V_6 ) , V_63 ) ;
if ( ! V_7 ) {
F_32 ( & V_23 -> V_24 , L_5 ) ;
V_58 = - V_64 ;
goto V_65;
}
V_7 -> V_12 = V_42 ;
V_7 -> V_26 = V_26 ;
V_7 -> V_2 . V_66 = F_38 ( & V_23 -> V_24 ) ;
V_7 -> V_2 . V_67 = F_8 ;
V_7 -> V_2 . V_68 = F_13 ;
V_7 -> V_2 . V_69 = F_3 ;
V_7 -> V_2 . V_70 = F_6 ;
V_7 -> V_2 . V_71 = F_14 ;
V_7 -> V_2 . V_42 = V_57 ;
V_7 -> V_2 . V_9 = V_53 -> V_72 ;
V_7 -> V_2 . V_73 = 0 ;
V_7 -> V_23 = V_23 ;
F_39 ( V_23 , V_7 ) ;
V_58 = F_40 ( & V_7 -> V_2 ) ;
if ( V_58 ) {
F_32 ( & V_23 -> V_24 , L_6 , V_58 ) ;
goto V_74;
}
F_41 ( V_23 -> V_30 , V_7 ) ;
F_42 ( V_23 -> V_30 , F_19 ) ;
for ( V_54 = 0 ; V_54 < V_7 -> V_2 . V_9 ; V_54 ++ ) {
F_43 ( V_54 + V_7 -> V_26 , & V_75 ,
V_76 , L_7 ) ;
F_44 ( V_54 + V_7 -> V_26 , V_7 ) ;
}
F_45 ( & V_7 -> V_25 ) ;
F_46 ( & V_23 -> V_24 ) ;
F_47 ( & V_23 -> V_24 ) ;
goto V_59;
V_74:
F_48 ( V_7 ) ;
V_65:
F_36 ( V_42 ) ;
V_61:
F_49 ( V_23 ) ;
V_60:
F_50 ( V_23 ) ;
V_59:
return V_58 ;
}
static int T_4 F_51 ( struct V_77 * V_23 )
{
struct V_6 * V_7 ;
struct V_1 * V_78 ;
struct V_79 * V_80 ;
int V_58 = 0 ;
V_80 = F_52 ( V_23 , V_81 , 0 ) ;
if ( ! V_80 )
return - V_35 ;
V_7 = F_37 ( sizeof( struct V_6 ) , V_63 ) ;
if ( ! V_7 ) {
F_32 ( & V_23 -> V_24 ,
L_8 ) ;
return - V_64 ;
}
V_7 -> V_12 = F_35 ( V_80 -> V_55 , F_53 ( V_80 ) ) ;
if ( V_7 -> V_12 == NULL ) {
V_58 = - V_35 ;
goto V_82;
}
F_45 ( & V_7 -> V_25 ) ;
V_78 = & V_7 -> V_2 ;
V_78 -> V_66 = F_38 ( & V_23 -> V_24 ) ;
V_78 -> V_83 = V_84 ;
V_78 -> V_67 = F_8 ;
V_78 -> V_68 = F_13 ;
V_78 -> V_69 = F_3 ;
V_78 -> V_70 = F_6 ;
V_78 -> V_71 = NULL ;
V_78 -> V_42 = 0 ;
V_78 -> V_9 = 64 ;
V_78 -> V_73 = 0 ;
V_58 = F_40 ( V_78 ) ;
if ( V_58 ) {
F_32 ( & V_23 -> V_24 , L_9 ,
V_58 ) ;
goto V_85;
}
F_54 ( V_23 , V_7 ) ;
return 0 ;
V_85:
F_36 ( V_7 -> V_12 ) ;
V_82:
F_48 ( V_7 ) ;
return V_58 ;
}
static int T_6 F_55 ( struct V_77 * V_23 )
{
struct V_6 * V_7 = F_56 ( V_23 ) ;
int V_49 ;
V_49 = F_57 ( & V_7 -> V_2 ) ;
if ( V_49 )
F_32 ( & V_23 -> V_24 , L_10 ) ;
F_36 ( V_7 -> V_12 ) ;
F_48 ( V_7 ) ;
F_54 ( V_23 , NULL ) ;
return 0 ;
}
static int T_7 F_58 ( void )
{
int V_86 ;
V_86 = F_59 ( & V_87 ) ;
if ( V_86 < 0 )
return V_86 ;
V_86 = F_60 ( & V_88 ) ;
if ( V_86 < 0 )
F_61 ( & V_87 ) ;
return V_86 ;
}
