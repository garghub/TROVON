static inline T_1 F_1 ( void T_2 * V_1 )
{
if ( V_2 -> V_3 )
return F_2 ( V_1 ) ;
else
return F_3 ( V_1 ) ;
}
static inline void F_4 ( T_1 V_4 , void T_2 * V_1 )
{
if ( V_2 -> V_3 )
F_5 ( V_4 , V_1 ) ;
else
F_6 ( V_4 , V_1 ) ;
}
static inline void F_7 ( void T_2 * V_5 )
{
T_1 V_4 ;
V_4 = F_1 ( V_5 + V_6 ) ;
V_4 &= ~ ( V_7 | V_8 ) ;
V_4 |= V_2 -> V_9 | F_8 ( 1 ) ;
F_4 ( V_4 , V_5 + V_6 ) ;
}
static inline void F_9 ( void T_2 * V_5 )
{
T_1 V_4 ;
V_4 = F_1 ( V_5 + V_6 ) ;
V_4 &= ~ ( V_7 | V_8 ) ;
F_4 ( V_4 , V_5 + V_6 ) ;
}
static inline void F_10 ( void T_2 * V_5 )
{
T_1 V_4 ;
V_4 = F_1 ( V_5 + V_6 ) ;
V_4 &= ~ V_10 ;
F_4 ( V_4 , V_5 + V_6 ) ;
}
static inline void F_11 ( void T_2 * V_5 )
{
T_1 V_4 ;
V_4 = F_1 ( V_5 + V_6 ) ;
V_4 |= V_11 ;
F_4 ( V_4 , V_5 + V_6 ) ;
}
static inline void F_12 ( void T_2 * V_5 )
{
T_1 V_4 ;
V_4 = F_1 ( V_5 + V_6 ) ;
V_4 &= ~ V_11 ;
F_4 ( V_4 , V_5 + V_6 ) ;
}
static inline void F_13 ( void T_2 * V_5 )
{
F_4 ( 0x00 , V_5 + V_12 ) ;
}
static T_3 T_4 F_14 ( void )
{
return F_1 ( V_2 -> V_13 + V_12 ) ;
}
static int F_15 ( unsigned long V_14 ,
struct V_15 * V_16 )
{
F_9 ( V_2 -> V_17 ) ;
F_13 ( V_2 -> V_17 ) ;
F_4 ( V_14 - 1 , V_2 -> V_17 + V_18 ) ;
F_7 ( V_2 -> V_17 ) ;
F_11 ( V_2 -> V_17 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_19 )
{
F_9 ( V_2 -> V_17 ) ;
return 0 ;
}
static int F_17 ( struct V_15 * V_19 )
{
F_15 ( V_2 -> V_20 , V_19 ) ;
return 0 ;
}
static T_5 F_18 ( int V_21 , void * V_22 )
{
struct V_15 * V_19 = V_22 ;
F_10 ( V_2 -> V_17 ) ;
if ( F_19 ( F_20 ( V_19 ) ) ) {
F_12 ( V_2 -> V_17 ) ;
F_9 ( V_2 -> V_17 ) ;
}
V_19 -> V_23 ( V_19 ) ;
return V_24 ;
}
static int T_6 F_21 ( unsigned long V_25 , int V_21 )
{
int V_26 ;
F_4 ( 0x00 , V_2 -> V_17 + V_27 ) ;
F_4 ( ~ 0u , V_2 -> V_17 + V_18 ) ;
F_13 ( V_2 -> V_17 ) ;
V_26 = F_22 ( V_21 , & V_28 ) ;
if ( V_26 ) {
F_23 ( L_1 , V_26 ) ;
return V_26 ;
}
V_29 . V_30 = F_24 ( 0 ) ;
V_29 . V_21 = V_21 ;
F_25 ( & V_29 ,
V_25 / ( 1 << V_2 -> V_9 ) ,
1 , 0xffff ) ;
F_7 ( V_2 -> V_17 ) ;
return 0 ;
}
static int T_6 F_26 ( unsigned long V_25 )
{
int V_26 ;
F_4 ( 0x00 , V_2 -> V_13 + V_27 ) ;
F_4 ( ~ 0u , V_2 -> V_13 + V_18 ) ;
F_13 ( V_2 -> V_13 ) ;
F_27 ( F_14 , 16 , V_25 / ( 1 << V_2 -> V_9 ) ) ;
V_26 = F_28 ( V_2 -> V_13 + V_12 , L_2 ,
V_25 / ( 1 << V_2 -> V_9 ) , 300 , 16 ,
V_31 ) ;
if ( V_26 ) {
F_23 ( L_3 , V_26 ) ;
return V_26 ;
}
F_7 ( V_2 -> V_13 ) ;
return 0 ;
}
static int T_6 F_29 ( struct V_32 * V_33 , char * V_34 ,
char * V_35 )
{
struct V_36 * V_36 ;
int V_26 ;
V_36 = F_30 ( V_33 , V_34 ) ;
if ( F_31 ( V_36 ) ) {
F_23 ( L_4 , V_34 , F_32 ( V_36 ) ) ;
return F_32 ( V_36 ) ;
}
V_26 = F_33 ( V_36 ) ;
if ( V_26 ) {
F_23 ( L_5 ,
V_34 , V_26 ) ;
return V_26 ;
}
V_36 = F_30 ( V_33 , V_35 ) ;
if ( F_31 ( V_36 ) ) {
F_23 ( L_4 , V_35 , F_32 ( V_36 ) ) ;
return F_32 ( V_36 ) ;
}
V_26 = F_33 ( V_36 ) ;
if ( V_26 )
F_23 ( L_5 ,
V_35 , V_26 ) ;
return F_34 ( V_36 ) ;
}
static unsigned long T_6 F_35 ( struct V_32 * V_33 )
{
unsigned long V_25 ;
V_25 = F_29 ( V_33 , L_6 , L_7 ) ;
if ( V_25 <= 0 )
return 0 ;
V_25 = F_29 ( V_33 , L_8 , L_9 ) ;
if ( V_25 <= 0 )
return 0 ;
return V_25 ;
}
static int T_6 F_36 ( unsigned long V_25 )
{
V_2 -> V_9 = 0 ;
do {
V_2 -> V_20 = F_37 ( V_25 ,
V_37 * ( 1 << V_2 -> V_9 ++ ) ) ;
} while ( V_2 -> V_20 > 0xFFFF );
if ( V_2 -> V_9 > V_38 ) {
F_23 ( L_10 ,
V_2 -> V_9 , V_38 ) ;
return - V_39 ;
}
return 0 ;
}
static int T_6 F_38 ( struct V_32 * V_33 )
{
unsigned long V_25 ;
int V_40 , V_21 ;
V_2 = F_39 ( sizeof( * V_2 ) , V_41 ) ;
if ( ! V_2 )
return - V_42 ;
V_40 = - V_43 ;
V_2 -> V_17 = F_40 ( V_33 , 0 ) ;
if ( ! V_2 -> V_17 ) {
F_23 ( L_11 ) ;
goto V_44;
}
V_2 -> V_13 = F_40 ( V_33 , 1 ) ;
if ( ! V_2 -> V_13 ) {
F_23 ( L_12 ) ;
goto V_45;
}
V_40 = - V_39 ;
V_21 = F_41 ( V_33 , 0 ) ;
if ( V_21 <= 0 ) {
F_23 ( L_13 , V_21 ) ;
goto V_26;
}
V_2 -> V_3 = F_42 ( V_33 , L_14 ) ;
V_25 = F_35 ( V_33 ) ;
if ( ! V_25 )
goto V_26;
V_40 = F_36 ( V_25 ) ;
if ( V_40 )
goto V_26;
V_40 = F_26 ( V_25 ) ;
if ( V_40 )
goto V_26;
V_40 = F_21 ( V_25 , V_21 ) ;
if ( V_40 )
goto V_26;
return 0 ;
V_26:
F_43 ( V_2 -> V_13 ) ;
V_45:
F_43 ( V_2 -> V_17 ) ;
V_44:
F_44 ( V_2 ) ;
return V_40 ;
}
