static inline T_1 F_1 ( T_1 V_1 )
{
return F_2 ( V_2 -> V_3 + V_1 ) ;
}
static inline void F_3 ( T_1 V_1 , T_1 V_4 )
{
F_4 ( V_4 , V_2 -> V_3 + V_1 ) ;
}
static inline enum V_5 F_5 ( void )
{
return ( F_1 ( V_6 ) >> 28 ) & 0xF ;
}
static int F_6 ( void )
{
int V_7 = 50000 ;
while ( V_7 -- ) {
if ( ! ( F_1 ( V_8 ) & V_9 ) )
return 0 ;
F_7 () ;
}
F_8 ( L_1 , V_10 ) ;
return - V_11 ;
}
static int F_9 ( struct V_12 * V_13 , T_1 V_1 )
{
int V_14 ;
if ( F_5 () != V_15 ) {
F_8 ( L_2 , V_10 ) ;
return - V_16 ;
}
F_3 ( V_8 , V_9 | V_17 | ( V_1 << 16 ) ) ;
F_10 ( 5 ) ;
V_14 = F_6 () ;
if ( V_14 )
return V_14 ;
return F_1 ( V_8 ) & V_18 ;
}
static int F_11 ( struct V_12 * V_13 , T_1 V_4 , T_1 V_1 )
{
if ( F_5 () != V_15 ) {
F_8 ( L_2 , V_10 ) ;
return - V_16 ;
}
F_3 ( V_8 , V_9 | ( V_1 << 16 ) | ( V_4 << 8 ) ) ;
F_10 ( 5 ) ;
return F_6 () ;
}
static void F_12 ( void )
{
T_1 V_19 ;
V_19 = F_1 ( V_20 ) ;
V_19 |= V_21 | V_22 ;
F_3 ( V_20 , V_19 ) ;
F_10 ( 10 ) ;
V_19 = F_1 ( V_20 ) ;
V_19 |= V_23 ;
V_19 &= ~ ( V_24 | V_25 ) ;
F_3 ( V_20 , V_19 ) ;
}
static int F_13 ( struct V_26 * V_27 )
{
int V_14 ;
F_12 () ;
V_14 = F_14 ( V_2 -> V_13 ) ;
if ( V_14 ) {
F_15 ( L_3 ) ;
return V_14 ;
}
V_14 = F_16 ( V_2 -> V_13 -> V_13 , 1 ) ;
if ( V_14 ) {
F_15 ( L_4 ) ;
return V_14 ;
}
V_14 = F_17 ( V_2 -> V_13 -> V_13 , V_27 ) ;
if ( V_14 )
F_15 ( L_5 ) ;
return V_14 ;
}
static int F_18 ( struct V_26 * V_27 )
{
T_1 V_19 ;
int V_14 ;
F_3 ( V_28 , F_1 ( V_28 ) & ~ V_29 ) ;
F_3 ( V_20 , F_1 ( V_20 ) | V_22 ) ;
F_3 ( V_30 , F_1 ( V_30 ) & ~ 0x37F7F ) ;
V_14 = F_13 ( V_27 ) ;
if ( V_14 )
return V_14 ;
if ( V_2 -> V_31 & V_32 )
F_3 ( V_33 , F_1 ( V_33 ) & ~ V_34 ) ;
else if ( V_2 -> V_31 & V_35 )
F_3 ( V_33 , F_1 ( V_33 ) | V_34 ) ;
V_19 = F_1 ( V_20 ) | V_24 ;
F_3 ( V_20 , V_19 & ~ ( V_23 | V_25 ) ) ;
return 0 ;
}
static void F_19 ( void )
{
F_12 () ;
F_17 ( V_2 -> V_13 -> V_13 , NULL ) ;
F_16 ( V_2 -> V_13 -> V_13 , 0 ) ;
F_20 ( V_2 -> V_13 ) ;
}
static void F_21 ( void )
{
T_1 V_19 ;
V_19 = F_1 ( V_20 ) ;
V_19 |= V_23 | V_22 ;
V_19 &= ~ ( V_24 | V_25 ) ;
F_3 ( V_20 , V_19 ) ;
F_10 ( 5 ) ;
F_3 ( V_20 , V_19 | V_36 ) ;
F_10 ( 5 ) ;
F_3 ( V_30 , F_1 ( V_30 ) & ~ 0x37F7F ) ;
}
static int F_22 ( struct V_37 * V_38 )
{
unsigned int V_31 = V_39 ;
if ( V_38 ) {
if ( V_38 -> V_31 & V_40 )
V_31 |= V_32 ;
else if ( V_38 -> V_31 & V_41 )
V_31 |= V_35 ;
}
V_2 -> V_31 = V_31 ;
V_2 -> V_13 = F_23 ( & V_42 , V_31 ) ;
if ( ! V_2 -> V_13 )
return - V_43 ;
V_2 -> V_13 -> V_44 = V_2 -> V_3 ;
return 0 ;
}
static void F_24 ( void )
{
F_25 ( V_2 -> V_13 ) ;
}
static inline void F_21 ( void ) {}
static inline int F_18 ( struct V_26 * V_27 )
{
return 0 ;
}
static inline void F_19 ( void ) {}
static inline int F_22 ( struct V_37 * V_38 )
{
return 0 ;
}
static inline void F_24 ( void ) {}
int F_26 ( struct V_26 * V_27 )
{
int V_14 = 0 ;
if ( ! V_2 )
return 0 ;
F_27 ( V_2 -> V_45 ) ;
if ( F_28 () ) {
F_21 () ;
V_14 = F_18 ( V_27 ) ;
}
return V_14 ;
}
void F_29 ( struct V_26 * V_27 )
{
if ( ! V_2 )
return;
if ( F_28 () )
F_19 () ;
F_30 ( V_2 -> V_45 ) ;
}
static int F_31 ( struct V_46 * V_47 )
{
struct V_37 * V_38 = V_47 -> V_48 . V_49 ;
struct V_50 * V_51 ;
int V_14 ;
V_2 = F_32 ( sizeof( struct V_52 ) , V_53 ) ;
if ( ! V_2 ) {
F_33 ( & V_47 -> V_48 , L_6 ) ;
return - V_43 ;
}
V_2 -> V_45 = F_34 ( & V_47 -> V_48 , NULL ) ;
if ( F_35 ( V_2 -> V_45 ) ) {
F_33 ( & V_47 -> V_48 , L_7 ) ;
V_14 = F_36 ( V_2 -> V_45 ) ;
goto V_54;
}
V_51 = F_37 ( V_47 , V_55 , 0 ) ;
if ( ! V_51 ) {
F_33 ( & V_47 -> V_48 , L_8 ) ;
V_14 = - V_56 ;
goto V_57;
}
V_51 = F_38 ( V_51 -> V_58 , F_39 ( V_51 ) , V_47 -> V_59 ) ;
if ( ! V_51 ) {
F_33 ( & V_47 -> V_48 , L_9 ) ;
V_14 = - V_16 ;
goto V_57;
}
V_2 -> V_3 = F_40 ( V_51 -> V_58 , F_39 ( V_51 ) ) ;
if ( ! V_2 -> V_3 ) {
F_33 ( & V_47 -> V_48 , L_10 ) ;
V_14 = - V_56 ;
goto V_60;
}
if ( V_38 -> V_61 ) {
V_14 = V_38 -> V_61 ( & V_47 -> V_48 ) ;
if ( V_14 )
goto V_62;
}
if ( F_28 () ) {
V_14 = F_22 ( V_38 ) ;
if ( V_14 )
goto V_63;
}
F_41 ( V_47 , & V_2 ) ;
return 0 ;
V_63:
if ( V_38 -> exit )
V_38 -> exit ( & V_47 -> V_48 ) ;
V_62:
F_42 ( V_2 -> V_3 ) ;
V_60:
F_43 ( V_51 -> V_58 , F_39 ( V_51 ) ) ;
V_57:
F_44 ( V_2 -> V_45 ) ;
V_54:
F_25 ( V_2 ) ;
return V_14 ;
}
static int F_45 ( struct V_46 * V_47 )
{
struct V_37 * V_38 = V_47 -> V_48 . V_49 ;
struct V_50 * V_51 ;
if ( F_28 () ) {
F_19 () ;
F_24 () ;
}
if ( V_38 -> exit )
V_38 -> exit ( & V_47 -> V_48 ) ;
F_41 ( V_47 , NULL ) ;
F_42 ( V_2 -> V_3 ) ;
V_51 = F_37 ( V_47 , V_55 , 0 ) ;
F_43 ( V_51 -> V_58 , F_39 ( V_51 ) ) ;
F_44 ( V_2 -> V_45 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
