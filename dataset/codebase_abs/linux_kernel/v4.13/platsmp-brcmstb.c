static int F_1 ( T_1 V_1 )
{
F_2 ( F_3 ( & V_2 , F_4 ( V_1 ) ) ) ;
return F_5 ( V_2 , V_1 ) ;
}
static void F_6 ( T_1 V_1 , int V_3 )
{
F_7 () ;
F_5 ( V_2 , V_1 ) = V_3 ;
F_8 ( F_3 ( & V_2 , F_4 ( V_1 ) ) ) ;
}
static inline void F_6 ( T_1 V_1 , int V_3 ) { }
static void T_2 * F_9 ( T_1 V_1 )
{
void T_2 * V_4 = V_5 + V_6 ;
V_4 += ( F_10 ( V_1 ) * 4 ) ;
return V_4 ;
}
static T_1 F_11 ( T_1 V_1 )
{
void T_2 * V_4 = F_9 ( V_1 ) ;
return F_12 ( V_4 ) ;
}
static void F_13 ( unsigned int V_1 , T_1 V_3 , T_1 V_7 )
{
void T_2 * V_4 = F_9 ( V_1 ) ;
F_14 ( ( F_15 ( V_4 ) & V_7 ) | V_3 , V_4 ) ;
}
static void F_16 ( unsigned int V_1 , T_1 V_3 , T_1 V_7 )
{
void T_2 * V_4 = F_9 ( V_1 ) ;
F_14 ( ( F_15 ( V_4 ) & V_7 ) & ~ V_3 , V_4 ) ;
}
static int F_17 ( unsigned int V_1 , T_1 V_8 , T_1 V_7 )
{
const unsigned long V_9 = V_10 + F_18 ( V_11 ) ;
T_1 V_12 ;
do {
V_12 = F_11 ( V_1 ) & V_7 ;
if ( ! V_8 == ! V_12 )
return 0 ;
} while ( F_19 ( V_10 , V_9 ) );
V_12 = F_11 ( V_1 ) & V_7 ;
if ( ! V_8 == ! V_12 )
return 0 ;
return - V_13 ;
}
static void F_20 ( T_1 V_1 , int V_8 )
{
T_1 V_3 ;
V_3 = F_12 ( V_5 + V_14 ) ;
if ( V_8 )
V_3 |= F_21 ( F_10 ( V_1 ) ) ;
else
V_3 &= ~ F_21 ( F_10 ( V_1 ) ) ;
F_22 ( V_3 , V_5 + V_14 ) ;
}
static void F_23 ( T_1 V_1 , unsigned long V_15 )
{
const int V_16 = F_10 ( V_1 ) * 8 ;
F_22 ( 0 , V_17 + V_18 + V_16 ) ;
F_22 ( V_15 , V_17 + V_18 + 4 + V_16 ) ;
}
static void F_24 ( T_1 V_1 )
{
F_6 ( V_1 , 1 ) ;
F_23 ( V_1 , F_25 ( V_19 ) ) ;
F_20 ( V_1 , 0 ) ;
}
static void F_26 ( T_1 V_1 )
{
F_13 ( V_1 , V_20 , 0xffffff00 ) ;
F_13 ( V_1 , V_21 , - 1 ) ;
F_13 ( V_1 , V_22 , - 1 ) ;
F_13 ( V_1 , V_23 , - 1 ) ;
if ( F_17 ( V_1 , 1 , V_24 ) )
F_27 ( L_1 ) ;
F_13 ( V_1 , V_25 , - 1 ) ;
if ( F_17 ( V_1 , 1 , V_26 ) )
F_27 ( L_2 ) ;
F_16 ( V_1 , V_20 , - 1 ) ;
F_13 ( V_1 , V_27 , - 1 ) ;
}
static int F_28 ( T_1 V_1 )
{
int V_12 = F_11 ( V_1 ) ;
return ( V_12 & V_28 ) ? 0 : 1 ;
}
static void F_29 ( T_1 V_1 )
{
F_30 ( V_29 ) ;
F_6 ( V_1 , 0 ) ;
F_31 () ;
while ( 1 )
;
}
static int F_32 ( T_1 V_1 )
{
if ( V_1 == 0 ) {
F_33 ( L_3 ) ;
return 1 ;
}
while ( F_1 ( V_1 ) )
;
F_13 ( V_1 , V_21 , - 1 ) ;
F_16 ( V_1 , V_27 , - 1 ) ;
F_16 ( V_1 , V_25 , - 1 ) ;
F_13 ( V_1 , V_20 , - 1 ) ;
F_16 ( V_1 , V_23 , - 1 ) ;
if ( F_17 ( V_1 , 0 , V_24 ) )
F_27 ( L_4 ) ;
F_16 ( V_1 , V_22 , - 1 ) ;
if ( F_17 ( V_1 , 0 , V_26 ) )
F_27 ( L_5 ) ;
F_34 () ;
F_20 ( V_1 , 1 ) ;
return 1 ;
}
static int T_3 F_35 ( struct V_30 * V_31 )
{
int V_32 = 0 ;
char * V_33 ;
struct V_30 * V_34 = NULL ;
V_33 = L_6 ;
V_34 = F_36 ( V_31 , V_33 , 0 ) ;
if ( ! V_34 ) {
F_37 ( L_7 , V_33 ) ;
V_32 = - V_35 ;
goto V_36;
}
V_5 = F_38 ( V_34 , 0 ) ;
if ( ! V_5 ) {
F_37 ( L_8 ) ;
V_32 = - V_35 ;
goto V_36;
}
V_32 = F_39 ( V_31 , V_33 , V_37 ,
& V_6 ) ;
if ( V_32 ) {
F_37 ( L_9 , V_33 ,
V_32 ) ;
V_32 = - V_35 ;
goto V_36;
}
V_32 = F_39 ( V_31 , V_33 , V_38 ,
& V_14 ) ;
if ( V_32 ) {
F_37 ( L_10 , V_33 ,
V_32 ) ;
V_32 = - V_35 ;
goto V_36;
}
V_36:
F_40 ( V_34 ) ;
return V_32 ;
}
static int T_3 F_41 ( struct V_30 * V_31 )
{
int V_32 = 0 ;
char * V_33 ;
struct V_30 * V_34 = NULL ;
V_33 = L_11 ;
V_34 = F_36 ( V_31 , V_33 , 0 ) ;
if ( ! V_34 ) {
F_37 ( L_7 , V_33 ) ;
V_32 = - V_35 ;
goto V_36;
}
V_17 = F_38 ( V_34 , 0 ) ;
if ( ! V_17 ) {
F_37 ( L_12 ) ;
V_32 = - V_35 ;
goto V_36;
}
V_18 = 0 ;
V_36:
F_40 ( V_34 ) ;
return V_32 ;
}
static void T_3 F_42 ( unsigned int V_39 )
{
int V_32 ;
struct V_30 * V_31 ;
char * V_33 ;
V_33 = L_13 ;
V_31 = F_43 ( NULL , NULL , V_33 ) ;
if ( ! V_31 ) {
F_37 ( L_14 , V_33 ) ;
return;
}
V_32 = F_35 ( V_31 ) ;
if ( V_32 )
return;
V_32 = F_41 ( V_31 ) ;
if ( V_32 )
return;
}
static int F_44 ( unsigned int V_1 , struct V_40 * V_41 )
{
if ( ! V_5 || ! V_17 )
return - V_42 ;
if ( F_28 ( V_1 ) == 0 )
F_26 ( V_1 ) ;
F_24 ( V_1 ) ;
return 0 ;
}
