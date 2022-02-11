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
static void F_13 ( T_1 V_1 , T_1 V_3 )
{
void T_2 * V_4 = F_9 ( V_1 ) ;
F_14 ( V_3 , V_4 ) ;
}
static void F_15 ( T_1 V_1 , int V_7 )
{
T_1 V_3 ;
V_3 = F_12 ( V_5 + V_8 ) ;
if ( V_7 )
V_3 |= F_16 ( F_10 ( V_1 ) ) ;
else
V_3 &= ~ F_16 ( F_10 ( V_1 ) ) ;
F_17 ( V_3 , V_5 + V_8 ) ;
}
static void F_18 ( T_1 V_1 , unsigned long V_9 )
{
const int V_10 = F_10 ( V_1 ) * 8 ;
F_17 ( 0 , V_11 + V_12 + V_10 ) ;
F_17 ( V_9 , V_11 + V_12 + 4 + V_10 ) ;
}
static void F_19 ( T_1 V_1 )
{
F_6 ( V_1 , 1 ) ;
F_18 ( V_1 , F_20 ( V_13 ) ) ;
F_15 ( V_1 , 0 ) ;
}
static void F_21 ( T_1 V_1 )
{
T_1 V_14 ;
F_13 ( V_1 , V_15 ) ;
do {
V_14 = F_11 ( V_1 ) ;
} while ( ! ( V_14 & V_16 ) );
}
static int F_22 ( T_1 V_1 )
{
int V_14 = F_11 ( V_1 ) ;
return ( V_14 & V_17 ) ? 0 : 1 ;
}
static void F_23 ( T_1 V_1 )
{
F_24 ( V_18 ) ;
F_6 ( V_1 , 0 ) ;
F_25 () ;
while ( 1 )
;
}
static int F_26 ( T_1 V_1 )
{
T_1 V_14 ;
while ( F_1 ( V_1 ) )
;
F_13 ( V_1 , V_17 | V_19 |
V_20 ) ;
V_14 = F_11 ( V_1 ) ;
if ( ! ( V_14 & V_17 ) )
F_27 ( L_1 ,
V_21 , V_1 ) ;
do {
V_14 = F_11 ( V_1 ) ;
} while ( ! ( V_14 & V_22 ) );
F_28 () ;
F_15 ( V_1 , 1 ) ;
return 1 ;
}
static int T_3 F_29 ( struct V_23 * V_24 )
{
int V_25 = 0 ;
char * V_26 ;
struct V_23 * V_27 = NULL ;
V_26 = L_2 ;
V_27 = F_30 ( V_24 , V_26 , 0 ) ;
if ( ! V_27 ) {
F_27 ( L_3 , V_26 ) ;
V_25 = - V_28 ;
goto V_29;
}
V_5 = F_31 ( V_27 , 0 ) ;
if ( ! V_5 ) {
F_27 ( L_4 ) ;
V_25 = - V_28 ;
goto V_29;
}
V_25 = F_32 ( V_24 , V_26 , V_30 ,
& V_6 ) ;
if ( V_25 ) {
F_27 ( L_5 , V_26 ,
V_25 ) ;
V_25 = - V_28 ;
goto V_29;
}
V_25 = F_32 ( V_24 , V_26 , V_31 ,
& V_8 ) ;
if ( V_25 ) {
F_27 ( L_6 , V_26 ,
V_25 ) ;
V_25 = - V_28 ;
goto V_29;
}
V_29:
F_33 ( V_27 ) ;
return V_25 ;
}
static int T_3 F_34 ( struct V_23 * V_24 )
{
int V_25 = 0 ;
char * V_26 ;
struct V_23 * V_27 = NULL ;
V_26 = L_7 ;
V_27 = F_30 ( V_24 , V_26 , 0 ) ;
if ( ! V_27 ) {
F_27 ( L_3 , V_26 ) ;
V_25 = - V_28 ;
goto V_29;
}
V_11 = F_31 ( V_27 , 0 ) ;
if ( ! V_11 ) {
F_27 ( L_8 ) ;
V_25 = - V_28 ;
goto V_29;
}
V_12 = 0 ;
V_29:
F_33 ( V_27 ) ;
return V_25 ;
}
static void T_3 F_35 ( unsigned int V_32 )
{
int V_25 ;
struct V_23 * V_24 ;
char * V_26 ;
V_26 = L_9 ;
V_24 = F_36 ( NULL , NULL , V_26 ) ;
if ( ! V_24 ) {
F_27 ( L_10 , V_26 ) ;
return;
}
V_25 = F_29 ( V_24 ) ;
if ( V_25 )
return;
V_25 = F_34 ( V_24 ) ;
if ( V_25 )
return;
}
static int F_37 ( unsigned int V_1 , struct V_33 * V_34 )
{
if ( ! V_5 || ! V_11 )
return - V_35 ;
if ( F_22 ( V_1 ) == 0 )
F_21 ( V_1 ) ;
F_19 ( V_1 ) ;
return 0 ;
}
