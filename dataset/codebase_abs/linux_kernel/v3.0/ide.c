int F_1 ( T_1 * V_1 )
{
struct V_2 * V_3 ;
struct V_4 * V_4 ;
if ( ! F_2 ( & V_1 -> V_5 ) )
return - V_6 ;
V_3 = V_1 -> V_7 -> V_8 -> V_9 [ 0 ] ;
V_4 = V_3 ? V_3 -> V_10 -> V_11 : NULL ;
if ( V_4 && ! F_3 ( V_4 ) ) {
F_4 ( & V_1 -> V_5 ) ;
return - V_6 ;
}
return 0 ;
}
void F_5 ( T_1 * V_1 )
{
#ifdef F_6
struct V_2 * V_3 = V_1 -> V_7 -> V_8 -> V_9 [ 0 ] ;
struct V_4 * V_4 = V_3 ? V_3 -> V_10 -> V_11 : NULL ;
if ( V_4 )
F_7 ( V_4 ) ;
#endif
F_4 ( & V_1 -> V_5 ) ;
}
static int F_8 ( struct V_2 * V_9 , struct V_12 * V_13 )
{
return 1 ;
}
static int F_9 ( struct V_2 * V_9 , struct V_14 * V_15 )
{
T_1 * V_1 = F_10 ( V_9 ) ;
F_11 ( V_15 , L_1 , F_12 ( V_1 ) ) ;
F_11 ( V_15 , L_2 , V_1 -> V_16 ) ;
F_11 ( V_15 , L_3 , F_12 ( V_1 ) ) ;
return 0 ;
}
static int F_13 ( struct V_2 * V_9 )
{
T_1 * V_1 = F_10 ( V_9 ) ;
struct V_17 * V_13 = F_14 ( V_9 -> V_10 ) ;
return V_13 -> V_18 ? V_13 -> V_18 ( V_1 ) : - V_19 ;
}
static int F_15 ( struct V_2 * V_9 )
{
T_1 * V_1 = F_10 ( V_9 ) ;
struct V_17 * V_13 = F_14 ( V_9 -> V_10 ) ;
if ( V_13 -> remove )
V_13 -> remove ( V_1 ) ;
return 0 ;
}
static void F_16 ( struct V_2 * V_9 )
{
T_1 * V_1 = F_10 ( V_9 ) ;
struct V_17 * V_13 = F_14 ( V_9 -> V_10 ) ;
if ( V_9 -> V_10 && V_13 -> V_20 )
V_13 -> V_20 ( V_1 ) ;
}
static int F_17 ( const char * V_21 , const struct V_22 * V_23 )
{
int V_24 , V_25 , V_26 , V_27 = 1 ;
unsigned int * V_28 = ( unsigned int * ) V_23 -> V_29 ;
if ( sscanf ( V_21 , L_4 , & V_24 , & V_25 , & V_27 ) != 3 &&
sscanf ( V_21 , L_5 , & V_24 , & V_25 ) != 2 )
return - V_30 ;
V_26 = V_24 * V_31 + V_25 ;
if ( V_26 >= V_32 * V_31 || V_27 < 0 || V_27 > 1 )
return - V_30 ;
if ( V_27 )
* V_28 |= ( 1 << V_26 ) ;
else
* V_28 &= ~ ( 1 << V_26 ) ;
return 0 ;
}
static int F_18 ( const char * V_33 , struct V_22 * V_23 )
{
int V_24 , V_25 , V_34 = 0 , V_35 = 0 , V_21 = 0 , V_26 , V_27 = 1 ;
if ( sscanf ( V_33 , L_6 , & V_24 , & V_25 , & V_34 , & V_35 , & V_21 ) != 5 &&
sscanf ( V_33 , L_4 , & V_24 , & V_25 , & V_27 ) != 3 )
return - V_30 ;
V_26 = V_24 * V_31 + V_25 ;
if ( V_26 >= V_32 * V_31 || V_27 < 0 || V_27 > 1 )
return - V_30 ;
if ( V_34 > V_36 || V_35 > 255 || V_21 > 255 )
return - V_30 ;
if ( V_27 )
V_37 |= ( 1 << V_26 ) ;
else
V_37 &= ~ ( 1 << V_26 ) ;
V_38 [ V_26 ] . V_39 = V_34 ;
V_38 [ V_26 ] . V_40 = V_35 ;
V_38 [ V_26 ] . V_41 = V_21 ;
return 0 ;
}
static void F_19 ( T_1 * V_1 , T_2 V_42 )
{
int V_26 = V_1 -> V_7 -> V_43 * V_31 + V_42 ;
if ( V_44 & ( 1 << V_26 ) ) {
F_20 ( V_45 L_7 , V_1 -> V_16 ) ;
V_1 -> V_46 |= V_47 ;
}
if ( V_48 & ( 1 << V_26 ) ) {
F_20 ( V_45 L_8 ,
V_1 -> V_16 ) ;
V_1 -> V_46 |= V_49 ;
}
if ( V_50 & ( 1 << V_26 ) ) {
F_20 ( V_45 L_9 ,
V_1 -> V_16 ) ;
V_1 -> V_46 |= V_51 ;
}
if ( V_52 & ( 1 << V_26 ) ) {
F_20 ( V_45 L_10 , V_1 -> V_16 ) ;
V_1 -> V_46 |= V_53 ;
}
if ( V_54 & ( 1 << V_26 ) ) {
F_20 ( V_45 L_11 ,
V_1 -> V_16 ) ;
V_1 -> V_55 = V_56 ;
}
if ( V_57 & ( 1 << V_26 ) ) {
F_20 ( V_45 L_12 , V_1 -> V_16 ) ;
V_1 -> V_46 |= V_58 ;
V_1 -> V_59 = V_60 ;
V_1 -> V_61 = 0 ;
}
if ( V_37 & ( 1 << V_26 ) ) {
V_1 -> V_39 = V_1 -> V_62 = V_38 [ V_26 ] . V_39 ;
V_1 -> V_40 = V_1 -> V_63 = V_38 [ V_26 ] . V_40 ;
V_1 -> V_41 = V_1 -> V_64 = V_38 [ V_26 ] . V_41 ;
F_20 ( V_45 L_13 ,
V_1 -> V_16 ,
V_1 -> V_39 , V_1 -> V_40 , V_1 -> V_41 ) ;
V_1 -> V_46 |= V_65 | V_58 ;
V_1 -> V_59 = V_66 ;
V_1 -> V_61 = V_67 ;
}
}
static int F_21 ( const char * V_21 , struct V_22 * V_23 )
{
int V_26 , V_27 = 1 ;
if ( sscanf ( V_21 , L_14 , & V_26 , & V_27 ) != 2 && sscanf ( V_21 , L_15 , & V_26 ) != 1 )
return - V_30 ;
if ( V_26 >= V_32 || V_27 < 0 || V_27 > 1 )
return - V_30 ;
if ( V_27 )
V_68 |= ( 1 << V_26 ) ;
else
V_68 &= ~ ( 1 << V_26 ) ;
return 0 ;
}
void F_22 ( T_3 * V_7 )
{
T_1 * V_1 ;
int V_26 ;
if ( V_68 & ( 1 << V_7 -> V_43 ) ) {
F_20 ( V_45 L_16 ,
V_7 -> V_16 ) ;
V_7 -> V_69 = V_70 ;
}
F_23 (i, drive, hwif)
F_19 ( V_1 , V_26 ) ;
}
static int T_4 F_24 ( void )
{
int V_71 ;
F_20 ( V_45 L_17 ) ;
V_71 = F_25 ( & V_72 ) ;
if ( V_71 < 0 ) {
F_20 ( V_73 L_18 , V_71 ) ;
return V_71 ;
}
V_74 = F_26 ( V_75 , L_19 ) ;
if ( F_27 ( V_74 ) ) {
V_71 = F_28 ( V_74 ) ;
goto V_76;
}
F_29 () ;
F_30 () ;
return 0 ;
V_76:
F_31 ( & V_72 ) ;
return V_71 ;
}
static void T_5 F_32 ( void )
{
F_33 () ;
F_34 ( V_74 ) ;
F_31 ( & V_72 ) ;
}
