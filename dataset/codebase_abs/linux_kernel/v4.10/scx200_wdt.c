static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 , V_3 + V_4 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
F_6 ( L_1 , V_5 ) ;
V_2 = V_5 * V_6 ;
}
static void F_7 ( void )
{
F_8 ( L_2 , V_2 ) ;
F_2 ( & V_1 ) ;
F_3 ( 0 , V_3 + V_4 ) ;
F_9 ( V_7 , V_3 + V_8 ) ;
F_3 ( V_9 , V_3 + V_10 ) ;
F_4 ( & V_1 ) ;
F_1 () ;
}
static void F_10 ( void )
{
F_8 ( L_3 ) ;
F_2 ( & V_1 ) ;
F_3 ( 0 , V_3 + V_4 ) ;
F_9 ( V_7 , V_3 + V_8 ) ;
F_3 ( V_11 , V_3 + V_10 ) ;
F_4 ( & V_1 ) ;
}
static int F_11 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_12 ( 0 , & V_14 ) )
return - V_15 ;
F_7 () ;
return F_13 ( V_12 , V_13 ) ;
}
static int F_14 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( V_16 != 42 )
F_15 ( L_4 ) ;
else if ( ! V_17 )
F_10 () ;
V_16 = 0 ;
F_16 ( 0 , & V_14 ) ;
return 0 ;
}
static int F_17 ( struct V_18 * V_19 ,
unsigned long V_20 , void * V_21 )
{
if ( V_20 == V_22 || V_20 == V_23 )
if ( ! V_17 )
F_10 () ;
return V_24 ;
}
static T_1 F_18 ( struct V_13 * V_13 , const char T_2 * V_25 ,
T_3 V_26 , T_4 * V_27 )
{
if ( V_26 ) {
T_3 V_28 ;
F_1 () ;
V_16 = 0 ;
for ( V_28 = 0 ; V_28 < V_26 ; ++ V_28 ) {
char V_29 ;
if ( F_19 ( V_29 , V_25 + V_28 ) )
return - V_30 ;
if ( V_29 == 'V' )
V_16 = 42 ;
}
return V_26 ;
}
return 0 ;
}
static long F_20 ( struct V_13 * V_13 , unsigned int V_31 ,
unsigned long V_32 )
{
void T_2 * V_33 = ( void T_2 * ) V_32 ;
int T_2 * V_34 = V_33 ;
static const struct V_35 V_36 = {
. V_37 = L_5 ,
. V_38 = 1 ,
. V_39 = V_40 | V_41 |
V_42 ,
} ;
int V_43 ;
switch ( V_31 ) {
case V_44 :
if ( F_21 ( V_33 , & V_36 , sizeof( V_36 ) ) )
return - V_30 ;
return 0 ;
case V_45 :
case V_46 :
if ( F_22 ( 0 , V_34 ) )
return - V_30 ;
return 0 ;
case V_47 :
F_1 () ;
return 0 ;
case V_48 :
if ( F_19 ( V_43 , V_34 ) )
return - V_30 ;
if ( V_43 < 1 )
return - V_49 ;
V_5 = V_43 ;
F_5 () ;
F_1 () ;
case V_50 :
if ( F_22 ( V_5 , V_34 ) )
return - V_30 ;
return 0 ;
default:
return - V_51 ;
}
}
static int T_5 F_23 ( void )
{
int V_52 ;
F_8 ( L_6 ) ;
if ( ! F_24 () )
return - V_53 ;
if ( ! F_25 ( V_3 + V_54 ,
V_55 ,
L_5 ) ) {
F_15 ( L_7 ) ;
return - V_15 ;
}
F_5 () ;
F_10 () ;
V_52 = F_26 ( & V_56 ) ;
if ( V_52 ) {
F_27 ( L_8 ) ;
F_28 ( V_3 + V_54 ,
V_55 ) ;
return V_52 ;
}
V_52 = F_29 ( & V_57 ) ;
if ( V_52 ) {
F_30 ( & V_56 ) ;
F_28 ( V_3 + V_54 ,
V_55 ) ;
return V_52 ;
}
return 0 ;
}
static void T_6 F_31 ( void )
{
F_32 ( & V_57 ) ;
F_30 ( & V_56 ) ;
F_28 ( V_3 + V_54 ,
V_55 ) ;
}
