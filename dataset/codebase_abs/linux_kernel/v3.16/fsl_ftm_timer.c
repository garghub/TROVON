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
static T_3 F_14 ( void )
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
static void F_16 ( enum V_19 V_20 ,
struct V_15 * V_21 )
{
switch ( V_20 ) {
case V_22 :
F_15 ( V_2 -> V_23 , V_21 ) ;
break;
case V_24 :
F_9 ( V_2 -> V_17 ) ;
break;
default:
return;
}
}
static T_4 F_17 ( int V_25 , void * V_26 )
{
struct V_15 * V_21 = V_26 ;
F_10 ( V_2 -> V_17 ) ;
if ( F_18 ( V_21 -> V_20 == V_24 ) ) {
F_12 ( V_2 -> V_17 ) ;
F_9 ( V_2 -> V_17 ) ;
}
V_21 -> V_27 ( V_21 ) ;
return V_28 ;
}
static int T_5 F_19 ( unsigned long V_29 , int V_25 )
{
int V_30 ;
F_4 ( 0x00 , V_2 -> V_17 + V_31 ) ;
F_4 ( ~ 0UL , V_2 -> V_17 + V_18 ) ;
F_13 ( V_2 -> V_17 ) ;
V_30 = F_20 ( V_25 , & V_32 ) ;
if ( V_30 ) {
F_21 ( L_1 , V_30 ) ;
return V_30 ;
}
V_33 . V_34 = F_22 ( 0 ) ;
V_33 . V_25 = V_25 ;
F_23 ( & V_33 ,
V_29 / ( 1 << V_2 -> V_9 ) ,
1 , 0xffff ) ;
F_7 ( V_2 -> V_17 ) ;
return 0 ;
}
static int T_5 F_24 ( unsigned long V_29 )
{
int V_30 ;
F_4 ( 0x00 , V_2 -> V_13 + V_31 ) ;
F_4 ( ~ 0UL , V_2 -> V_13 + V_18 ) ;
F_13 ( V_2 -> V_13 ) ;
F_25 ( F_14 , 16 , V_29 / ( 1 << V_2 -> V_9 ) ) ;
V_30 = F_26 ( V_2 -> V_13 + V_12 , L_2 ,
V_29 / ( 1 << V_2 -> V_9 ) , 300 , 16 ,
V_35 ) ;
if ( V_30 ) {
F_21 ( L_3 , V_30 ) ;
return V_30 ;
}
F_7 ( V_2 -> V_13 ) ;
return 0 ;
}
static int T_5 F_27 ( struct V_36 * V_37 , char * V_38 ,
char * V_39 )
{
struct V_40 * V_40 ;
int V_30 ;
V_40 = F_28 ( V_37 , V_38 ) ;
if ( F_29 ( V_40 ) ) {
F_21 ( L_4 , V_38 , F_30 ( V_40 ) ) ;
return F_30 ( V_40 ) ;
}
V_30 = F_31 ( V_40 ) ;
if ( V_30 ) {
F_21 ( L_5 ,
V_38 , V_30 ) ;
return V_30 ;
}
V_40 = F_28 ( V_37 , V_39 ) ;
if ( F_29 ( V_40 ) ) {
F_21 ( L_4 , V_39 , F_30 ( V_40 ) ) ;
return F_30 ( V_40 ) ;
}
V_30 = F_31 ( V_40 ) ;
if ( V_30 )
F_21 ( L_5 ,
V_39 , V_30 ) ;
return F_32 ( V_40 ) ;
}
static unsigned long T_5 F_33 ( struct V_36 * V_37 )
{
unsigned long V_29 ;
V_29 = F_27 ( V_37 , L_6 , L_7 ) ;
if ( V_29 <= 0 )
return 0 ;
V_29 = F_27 ( V_37 , L_8 , L_9 ) ;
if ( V_29 <= 0 )
return 0 ;
return V_29 ;
}
static int T_5 F_34 ( unsigned long V_29 )
{
V_2 -> V_9 = 0 ;
do {
V_2 -> V_23 = F_35 ( V_29 ,
V_41 * ( 1 << V_2 -> V_9 ++ ) ) ;
} while ( V_2 -> V_23 > 0xFFFF );
if ( V_2 -> V_9 > V_42 ) {
F_21 ( L_10 ,
V_2 -> V_9 , V_42 ) ;
return - V_43 ;
}
return 0 ;
}
static void T_5 F_36 ( struct V_36 * V_37 )
{
unsigned long V_29 ;
int V_25 ;
V_2 = F_37 ( sizeof( * V_2 ) , V_44 ) ;
if ( ! V_2 )
return;
V_2 -> V_17 = F_38 ( V_37 , 0 ) ;
if ( ! V_2 -> V_17 ) {
F_21 ( L_11 ) ;
goto V_30;
}
V_2 -> V_13 = F_38 ( V_37 , 1 ) ;
if ( ! V_2 -> V_13 ) {
F_21 ( L_12 ) ;
goto V_30;
}
V_25 = F_39 ( V_37 , 0 ) ;
if ( V_25 <= 0 ) {
F_21 ( L_13 , V_25 ) ;
goto V_30;
}
V_2 -> V_3 = F_40 ( V_37 , L_14 ) ;
V_29 = F_33 ( V_37 ) ;
if ( ! V_29 )
goto V_30;
if ( F_34 ( V_29 ) )
goto V_30;
if ( F_24 ( V_29 ) )
goto V_30;
if ( F_19 ( V_29 , V_25 ) )
goto V_30;
return;
V_30:
F_41 ( V_2 ) ;
}
