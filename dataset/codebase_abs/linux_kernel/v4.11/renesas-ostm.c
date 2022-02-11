static struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_1 * V_4 )
{
if ( F_4 ( V_4 -> V_5 + V_6 ) & V_7 ) {
F_5 ( V_8 , V_4 -> V_5 + V_9 ) ;
while ( F_4 ( V_4 -> V_5 + V_6 ) & V_7 )
;
}
}
static int T_1 F_6 ( struct V_1 * V_4 , unsigned long V_10 )
{
F_3 ( V_4 ) ;
F_7 ( 0 , V_4 -> V_5 + V_11 ) ;
F_5 ( V_12 , V_4 -> V_5 + V_13 ) ;
F_5 ( V_14 , V_4 -> V_5 + V_15 ) ;
return F_8 ( V_4 -> V_5 + V_16 ,
L_1 , V_10 ,
300 , 32 , V_17 ) ;
}
static T_2 T_3 F_9 ( void )
{
return F_10 ( V_18 ) ;
}
static void T_1 F_11 ( struct V_1 * V_4 ,
unsigned long V_10 )
{
V_18 = V_4 -> V_5 + V_16 ;
F_12 ( F_9 , 32 , V_10 ) ;
}
static int F_13 ( unsigned long V_19 ,
struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 ) ;
F_7 ( V_19 , V_4 -> V_5 + V_11 ) ;
F_5 ( V_20 , V_4 -> V_5 + V_13 ) ;
F_5 ( V_14 , V_4 -> V_5 + V_15 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
if ( F_16 ( V_3 ) || F_17 ( V_3 ) )
F_3 ( V_4 ) ;
F_7 ( V_4 -> V_21 - 1 , V_4 -> V_5 + V_11 ) ;
F_5 ( V_22 , V_4 -> V_5 + V_13 ) ;
F_5 ( V_14 , V_4 -> V_5 + V_15 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_4 = F_1 ( V_3 ) ;
F_3 ( V_4 ) ;
return 0 ;
}
static T_4 F_19 ( int V_23 , void * V_24 )
{
struct V_1 * V_4 = V_24 ;
if ( F_16 ( & V_4 -> V_3 ) )
F_3 ( V_4 ) ;
if ( V_4 -> V_3 . V_25 )
V_4 -> V_3 . V_25 ( & V_4 -> V_3 ) ;
return V_26 ;
}
static int T_1 F_20 ( struct V_1 * V_4 , int V_23 ,
unsigned long V_10 )
{
struct V_2 * V_3 = & V_4 -> V_3 ;
int V_27 = - V_28 ;
V_27 = F_21 ( V_23 , F_19 ,
V_29 | V_30 ,
L_1 , V_4 ) ;
if ( V_27 ) {
F_22 ( L_2 ) ;
return V_27 ;
}
V_3 -> V_31 = L_1 ;
V_3 -> V_32 = V_33 | V_34 ;
V_3 -> V_35 = F_14 ;
V_3 -> V_36 = F_15 ;
V_3 -> V_37 = F_18 ;
V_3 -> V_38 = F_13 ;
V_3 -> V_39 = 32 ;
V_3 -> V_40 = 300 ;
V_3 -> V_41 = F_23 ( 0 ) ;
F_24 ( V_3 , V_10 , 0xf , 0xffffffff ) ;
return 0 ;
}
static int T_1 F_25 ( struct V_42 * V_43 )
{
struct V_1 * V_4 ;
int V_27 = - V_44 ;
struct V_45 * V_46 = NULL ;
int V_23 ;
unsigned long V_10 ;
V_4 = F_26 ( sizeof( * V_4 ) , V_47 ) ;
if ( ! V_4 )
return - V_48 ;
V_4 -> V_5 = F_27 ( V_43 , 0 ) ;
if ( ! V_4 -> V_5 ) {
F_22 ( L_3 ) ;
goto V_49;
}
V_23 = F_28 ( V_43 , 0 ) ;
if ( V_23 < 0 ) {
F_22 ( L_4 ) ;
goto V_49;
}
V_46 = F_29 ( V_43 , 0 ) ;
if ( F_30 ( V_46 ) ) {
F_22 ( L_5 ) ;
V_46 = NULL ;
goto V_49;
}
V_27 = F_31 ( V_46 ) ;
if ( V_27 ) {
F_22 ( L_6 ) ;
goto V_49;
}
V_10 = F_32 ( V_46 ) ;
V_4 -> V_21 = ( V_10 + V_50 / 2 ) / V_50 ;
if ( ! V_18 ) {
V_27 = F_6 ( V_4 , V_10 ) ;
if ( ! V_27 ) {
F_11 ( V_4 , V_10 ) ;
F_33 ( L_7 ) ;
}
} else {
V_27 = F_20 ( V_4 , V_23 , V_10 ) ;
if ( ! V_27 )
F_33 ( L_8 ) ;
}
V_49:
if ( V_27 ) {
F_34 ( V_46 ) ;
F_35 ( V_4 -> V_5 ) ;
F_36 ( V_4 ) ;
return V_27 ;
}
return 0 ;
}
