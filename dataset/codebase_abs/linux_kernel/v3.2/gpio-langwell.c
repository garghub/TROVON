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
static void T_1 * F_3 ( struct V_1 * V_2 , unsigned V_3 ,
enum V_4 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
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
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
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
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
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
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_2 ) ;
return V_7 -> V_30 + V_3 ;
}
static int F_17 ( struct V_31 * V_32 , unsigned type )
{
struct V_6 * V_7 = F_18 ( V_32 ) ;
T_3 V_33 = V_32 -> V_34 - V_7 -> V_30 ;
unsigned long V_26 ;
T_3 V_15 ;
void T_1 * V_35 = F_1 ( & V_7 -> V_2 , V_33 , V_36 ) ;
void T_1 * V_37 = F_1 ( & V_7 -> V_2 , V_33 , V_38 ) ;
if ( V_33 >= V_7 -> V_2 . V_9 )
return - V_39 ;
if ( V_7 -> V_27 )
F_11 ( & V_7 -> V_27 -> V_28 ) ;
F_12 ( & V_7 -> V_29 , V_26 ) ;
if ( type & V_40 )
V_15 = F_5 ( V_35 ) | F_8 ( V_33 % 32 ) ;
else
V_15 = F_5 ( V_35 ) & ( ~ F_8 ( V_33 % 32 ) ) ;
F_6 ( V_15 , V_35 ) ;
if ( type & V_41 )
V_15 = F_5 ( V_37 ) | F_8 ( V_33 % 32 ) ;
else
V_15 = F_5 ( V_37 ) & ( ~ F_8 ( V_33 % 32 ) ) ;
F_6 ( V_15 , V_37 ) ;
F_13 ( & V_7 -> V_29 , V_26 ) ;
if ( V_7 -> V_27 )
F_14 ( & V_7 -> V_27 -> V_28 ) ;
return 0 ;
}
static void F_19 ( struct V_31 * V_32 )
{
}
static void F_20 ( struct V_31 * V_32 )
{
}
static void F_21 ( unsigned V_34 , struct V_42 * V_43 )
{
struct V_31 * V_44 = F_22 ( V_43 ) ;
struct V_6 * V_7 = F_23 ( V_44 ) ;
struct V_45 * V_2 = F_24 ( V_44 ) ;
T_3 V_46 , V_33 , V_47 ;
unsigned long V_48 ;
void T_1 * V_49 ;
for ( V_46 = 0 ; V_46 < V_7 -> V_2 . V_9 ; V_46 += 32 ) {
V_49 = F_1 ( & V_7 -> V_2 , V_46 , V_50 ) ;
V_48 = F_5 ( V_49 ) ;
while ( V_48 ) {
V_33 = F_25 ( V_48 ) ;
V_47 = F_8 ( V_33 ) ;
V_48 &= ~ V_47 ;
F_6 ( V_47 , V_49 ) ;
F_26 ( V_7 -> V_30 + V_46 + V_33 ) ;
}
}
V_2 -> V_51 ( V_44 ) ;
}
static int F_27 ( struct V_52 * V_28 )
{
return 0 ;
}
static int F_28 ( struct V_52 * V_28 )
{
return 0 ;
}
static int F_29 ( struct V_52 * V_28 )
{
int V_53 = F_30 ( V_28 , 500 ) ;
if ( ! V_53 )
return 0 ;
return - V_54 ;
}
static int T_4 F_31 ( struct V_55 * V_27 ,
const struct V_56 * V_57 )
{
void * V_46 ;
int V_58 ;
T_5 V_59 , V_60 ;
struct V_6 * V_7 ;
T_3 V_30 ;
T_3 V_61 ;
int V_62 = 0 ;
V_62 = F_32 ( V_27 ) ;
if ( V_62 )
goto V_63;
V_62 = F_33 ( V_27 , L_1 ) ;
if ( V_62 ) {
F_34 ( & V_27 -> V_28 , L_2 ) ;
goto V_64;
}
V_59 = F_35 ( V_27 , 1 ) ;
V_60 = F_36 ( V_27 , 1 ) ;
V_46 = F_37 ( V_59 , V_60 ) ;
if ( ! V_46 ) {
F_34 ( & V_27 -> V_28 , L_3 ) ;
goto V_65;
}
V_30 = * ( T_3 * ) V_46 ;
V_61 = * ( ( T_3 * ) V_46 + 1 ) ;
F_38 ( V_46 ) ;
V_59 = F_35 ( V_27 , 0 ) ;
V_60 = F_36 ( V_27 , 0 ) ;
V_46 = F_37 ( V_59 , V_60 ) ;
if ( ! V_46 ) {
F_34 ( & V_27 -> V_28 , L_4 ) ;
V_62 = - V_66 ;
goto V_65;
}
V_7 = F_39 ( sizeof( struct V_6 ) , V_67 ) ;
if ( ! V_7 ) {
F_34 ( & V_27 -> V_28 , L_5 ) ;
V_62 = - V_68 ;
goto V_69;
}
V_7 -> V_12 = V_46 ;
V_7 -> V_30 = V_30 ;
V_7 -> V_2 . V_70 = F_40 ( & V_27 -> V_28 ) ;
V_7 -> V_2 . V_71 = F_4 ;
V_7 -> V_2 . V_72 = F_10 ;
V_7 -> V_2 . V_73 = F_15 ;
V_7 -> V_2 . V_74 = F_7 ;
V_7 -> V_2 . V_75 = F_9 ;
V_7 -> V_2 . V_76 = F_16 ;
V_7 -> V_2 . V_46 = V_61 ;
V_7 -> V_2 . V_9 = V_57 -> V_77 ;
V_7 -> V_2 . V_78 = 0 ;
V_7 -> V_27 = V_27 ;
F_41 ( V_27 , V_7 ) ;
V_62 = F_42 ( & V_7 -> V_2 ) ;
if ( V_62 ) {
F_34 ( & V_27 -> V_28 , L_6 , V_62 ) ;
goto V_79;
}
F_43 ( V_27 -> V_34 , V_7 ) ;
F_44 ( V_27 -> V_34 , F_21 ) ;
for ( V_58 = 0 ; V_58 < V_7 -> V_2 . V_9 ; V_58 ++ ) {
F_45 ( V_58 + V_7 -> V_30 , & V_80 ,
V_81 , L_7 ) ;
F_46 ( V_58 + V_7 -> V_30 , V_7 ) ;
}
F_47 ( & V_7 -> V_29 ) ;
F_48 ( & V_27 -> V_28 ) ;
F_49 ( & V_27 -> V_28 ) ;
goto V_63;
V_79:
F_50 ( V_7 ) ;
V_69:
F_38 ( V_46 ) ;
V_65:
F_51 ( V_27 ) ;
V_64:
F_52 ( V_27 ) ;
V_63:
return V_62 ;
}
static int T_4 F_53 ( struct V_82 * V_27 )
{
struct V_6 * V_7 ;
struct V_1 * V_83 ;
struct V_84 * V_85 ;
int V_62 = 0 ;
V_85 = F_54 ( V_27 , V_86 , 0 ) ;
if ( ! V_85 )
return - V_39 ;
V_7 = F_39 ( sizeof( struct V_6 ) , V_67 ) ;
if ( ! V_7 ) {
F_34 ( & V_27 -> V_28 ,
L_8 ) ;
return - V_68 ;
}
V_7 -> V_12 = F_37 ( V_85 -> V_59 , F_55 ( V_85 ) ) ;
if ( V_7 -> V_12 == NULL ) {
V_62 = - V_39 ;
goto V_87;
}
F_47 ( & V_7 -> V_29 ) ;
V_83 = & V_7 -> V_2 ;
V_83 -> V_70 = F_40 ( & V_27 -> V_28 ) ;
V_83 -> V_88 = V_89 ;
V_83 -> V_72 = F_10 ;
V_83 -> V_73 = F_15 ;
V_83 -> V_74 = F_7 ;
V_83 -> V_75 = F_9 ;
V_83 -> V_76 = NULL ;
V_83 -> V_46 = 0 ;
V_83 -> V_9 = 64 ;
V_83 -> V_78 = 0 ;
V_62 = F_42 ( V_83 ) ;
if ( V_62 ) {
F_34 ( & V_27 -> V_28 , L_9 ,
V_62 ) ;
goto V_90;
}
F_56 ( V_27 , V_7 ) ;
return 0 ;
V_90:
F_38 ( V_7 -> V_12 ) ;
V_87:
F_50 ( V_7 ) ;
return V_62 ;
}
static int T_6 F_57 ( struct V_82 * V_27 )
{
struct V_6 * V_7 = F_58 ( V_27 ) ;
int V_53 ;
V_53 = F_59 ( & V_7 -> V_2 ) ;
if ( V_53 )
F_34 ( & V_27 -> V_28 , L_10 ) ;
F_38 ( V_7 -> V_12 ) ;
F_50 ( V_7 ) ;
F_56 ( V_27 , NULL ) ;
return 0 ;
}
static int T_7 F_60 ( void )
{
int V_91 ;
V_91 = F_61 ( & V_92 ) ;
if ( V_91 < 0 )
return V_91 ;
V_91 = F_62 ( & V_93 ) ;
if ( V_91 < 0 )
F_63 ( & V_92 ) ;
return V_91 ;
}
