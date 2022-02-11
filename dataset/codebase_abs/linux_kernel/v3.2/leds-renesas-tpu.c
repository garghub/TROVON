static inline unsigned short F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 = V_3 << 2 ;
if ( V_3 == V_12 )
return F_2 ( V_9 - V_5 -> V_13 ) ;
return F_2 ( V_9 + V_11 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 ,
unsigned short V_14 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
void T_1 * V_9 = V_2 -> V_10 ;
unsigned long V_11 = V_3 << 2 ;
if ( V_3 == V_12 ) {
F_4 ( V_14 , V_9 - V_5 -> V_13 ) ;
return;
}
F_4 ( V_14 , V_9 + V_11 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_15 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
unsigned long V_16 , V_14 ;
F_6 ( & V_17 , V_16 ) ;
V_14 = F_1 ( V_2 , V_12 ) ;
if ( V_15 )
V_14 |= 1 << V_5 -> V_18 ;
else
V_14 &= ~ ( 1 << V_5 -> V_18 ) ;
F_3 ( V_2 , V_12 , V_14 ) ;
F_7 ( & V_17 , V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 , enum V_19 V_20 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
int V_21 [] = { 1 , 4 , 16 , 64 } ;
int V_22 , V_23 ;
unsigned long V_24 , V_25 ;
if ( V_2 -> V_26 == V_27 )
return 0 ;
F_9 ( & V_2 -> V_6 -> V_7 ) ;
V_23 = F_10 ( V_2 -> V_28 ) ;
if ( V_23 ) {
F_11 ( & V_2 -> V_6 -> V_7 , L_1 ) ;
return V_23 ;
}
F_5 ( V_2 , 0 ) ;
V_24 = F_12 ( V_2 -> V_28 ) ;
for ( V_22 = 0 ; V_22 < F_13 ( V_21 ) ; V_22 ++ )
if ( ( V_24 / V_21 [ V_22 ] ) < V_2 -> V_29 )
break;
if ( ! V_22 ) {
F_11 ( & V_2 -> V_6 -> V_7 , L_2 ) ;
goto V_30;
}
F_14 ( & V_2 -> V_6 -> V_7 , L_3 ,
V_24 , V_21 [ V_22 - 1 ] ) ;
F_3 ( V_2 , V_31 , 0x0040 | ( V_22 - 1 ) ) ;
F_3 ( V_2 , V_32 , 0x0002 ) ;
V_24 /= V_21 [ V_22 - 1 ] * V_2 -> V_33 ;
F_3 ( V_2 , V_34 , V_24 ) ;
F_14 ( & V_2 -> V_6 -> V_7 , L_4 , V_24 ) ;
V_25 = ( V_5 -> V_35 - V_20 ) * V_24 ;
F_3 ( V_2 , V_36 , V_25 / V_5 -> V_35 ) ;
F_14 ( & V_2 -> V_6 -> V_7 , L_5 , V_25 / V_5 -> V_35 ) ;
F_3 ( V_2 , V_37 , 0x0002 ) ;
F_5 ( V_2 , 1 ) ;
V_2 -> V_26 = V_27 ;
return 0 ;
V_30:
F_15 ( V_2 -> V_28 ) ;
F_16 ( & V_2 -> V_6 -> V_7 ) ;
return - V_38 ;
}
static void F_17 ( struct V_1 * V_2 )
{
if ( V_2 -> V_26 == V_39 )
return;
F_5 ( V_2 , 0 ) ;
F_15 ( V_2 -> V_28 ) ;
F_16 ( & V_2 -> V_6 -> V_7 ) ;
V_2 -> V_26 = V_39 ;
}
static void F_18 ( struct V_1 * V_2 , enum V_40 V_41 ,
enum V_19 V_20 )
{
struct V_4 * V_5 = V_2 -> V_6 -> V_7 . V_8 ;
if ( V_2 -> V_42 == V_41 ) {
if ( V_2 -> V_42 == V_43 )
F_19 ( V_5 -> V_44 , V_20 ) ;
return;
}
if ( V_2 -> V_42 == V_43 )
F_20 ( V_5 -> V_44 ) ;
if ( V_2 -> V_42 == V_45 )
F_20 ( V_5 -> V_46 ) ;
if ( V_41 == V_43 ) {
F_21 ( V_5 -> V_44 , V_5 -> V_47 ) ;
F_22 ( V_5 -> V_44 , ! ! V_20 ) ;
}
if ( V_41 == V_45 )
F_21 ( V_5 -> V_46 , V_5 -> V_47 ) ;
V_2 -> V_42 = V_41 ;
}
static void F_23 ( struct V_48 * V_49 )
{
struct V_1 * V_2 = F_24 ( V_49 , struct V_1 , V_49 ) ;
enum V_19 V_20 = V_2 -> V_50 ;
F_17 ( V_2 ) ;
if ( ( V_20 == 0 ) || ( V_20 == V_2 -> V_51 . V_35 ) )
F_18 ( V_2 , V_43 , V_20 ) ;
else {
F_18 ( V_2 , V_45 , 0 ) ;
F_8 ( V_2 , V_20 ) ;
}
}
static void F_25 ( struct V_52 * V_51 ,
enum V_19 V_20 )
{
struct V_1 * V_2 = F_24 ( V_51 , struct V_1 , V_51 ) ;
V_2 -> V_50 = V_20 ;
F_26 ( & V_2 -> V_49 ) ;
}
static int T_2 F_27 ( struct V_53 * V_6 )
{
struct V_4 * V_5 = V_6 -> V_7 . V_8 ;
struct V_1 * V_2 ;
struct V_54 * V_55 ;
int V_23 = - V_56 ;
if ( ! V_5 ) {
F_11 ( & V_6 -> V_7 , L_6 ) ;
goto V_30;
}
V_2 = F_28 ( sizeof( * V_2 ) , V_57 ) ;
if ( V_2 == NULL ) {
F_11 ( & V_6 -> V_7 , L_7 ) ;
V_23 = - V_58 ;
goto V_30;
}
V_55 = F_29 ( V_6 , V_59 , 0 ) ;
if ( ! V_55 ) {
F_11 ( & V_6 -> V_7 , L_8 ) ;
goto V_60;
}
V_2 -> V_10 = F_30 ( V_55 -> V_15 , F_31 ( V_55 ) ) ;
if ( V_2 -> V_10 == NULL ) {
F_11 ( & V_6 -> V_7 , L_9 ) ;
goto V_60;
}
V_2 -> V_28 = F_32 ( & V_6 -> V_7 , NULL ) ;
if ( F_33 ( V_2 -> V_28 ) ) {
F_11 ( & V_6 -> V_7 , L_10 ) ;
V_23 = F_34 ( V_2 -> V_28 ) ;
goto V_61;
}
V_2 -> V_6 = V_6 ;
V_2 -> V_42 = V_62 ;
V_2 -> V_26 = V_39 ;
V_2 -> V_33 = V_5 -> V_33 ? V_5 -> V_33 : 100 ;
F_18 ( V_2 , V_43 , V_63 ) ;
F_35 ( V_6 , V_2 ) ;
F_36 ( & V_2 -> V_49 , F_23 ) ;
V_2 -> V_51 . V_47 = V_5 -> V_47 ;
V_2 -> V_51 . V_20 = V_63 ;
V_2 -> V_51 . V_35 = V_5 -> V_35 ;
V_2 -> V_51 . V_64 = F_25 ;
V_2 -> V_51 . V_16 |= V_65 ;
V_23 = F_37 ( & V_6 -> V_7 , & V_2 -> V_51 ) ;
if ( V_23 < 0 )
goto V_66;
V_2 -> V_29 = V_2 -> V_51 . V_35 * V_2 -> V_33 ;
F_38 ( & V_6 -> V_7 ) ;
return 0 ;
V_66:
F_18 ( V_2 , V_62 , V_63 ) ;
F_39 ( V_2 -> V_28 ) ;
V_61:
F_40 ( V_2 -> V_10 ) ;
V_60:
F_41 ( V_2 ) ;
V_30:
return V_23 ;
}
static int T_3 F_42 ( struct V_53 * V_6 )
{
struct V_1 * V_2 = F_43 ( V_6 ) ;
F_25 ( & V_2 -> V_51 , V_63 ) ;
F_44 ( & V_2 -> V_51 ) ;
F_45 ( & V_2 -> V_49 ) ;
F_17 ( V_2 ) ;
F_18 ( V_2 , V_62 , V_63 ) ;
F_46 ( & V_6 -> V_7 ) ;
F_39 ( V_2 -> V_28 ) ;
F_40 ( V_2 -> V_10 ) ;
F_41 ( V_2 ) ;
return 0 ;
}
static int T_4 F_47 ( void )
{
return F_48 ( & V_67 ) ;
}
static void T_5 F_49 ( void )
{
F_50 ( & V_67 ) ;
}
