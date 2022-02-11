static int F_1 ( void )
{
F_2 () ;
F_3 ( 0 ) ;
return 0 ;
}
static int F_4 ( void )
{
F_2 () ;
F_5 ( V_1 ) ;
return 0 ;
}
static int F_6 ( void )
{
F_2 () ;
F_5 ( V_2 | V_3 ) ;
return 0 ;
}
static int F_7 ( void )
{
F_2 () ;
return ( ( F_8 () & V_4 ) != V_1 ) ;
}
static int F_9 ( unsigned long V_5 )
{
T_1 V_6 , V_7 , V_8 ;
unsigned long V_9 ;
V_8 = F_10 () ;
V_7 = - 1 / V_8 ;
V_6 = V_5 * V_8 ;
F_11 ( L_1 , V_7 , V_5 , V_6 ) ;
if ( V_5 > V_7 ) {
F_12 ( L_2 ) ;
return - V_10 ;
}
F_13 ( & V_11 , V_9 ) ;
{
int V_12 = F_7 () ;
F_4 () ;
F_14 ( V_6 ) ;
if ( V_12 )
F_6 () ;
}
F_15 ( & V_11 , V_9 ) ;
V_13 = V_5 ;
return 0 ;
}
static int F_16 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
F_2 () ;
if ( F_17 ( 0 , & V_16 ) )
return - V_17 ;
if ( V_18 )
F_18 ( V_19 ) ;
F_1 () ;
F_6 () ;
return F_19 ( V_14 , V_15 ) ;
}
static int F_20 ( struct V_14 * V_14 , struct V_15 * V_15 )
{
F_2 () ;
if ( V_20 == 42 )
F_4 () ;
else {
F_21 ( L_3 ) ;
F_1 () ;
}
V_20 = 0 ;
F_22 ( 0 , & V_16 ) ;
return 0 ;
}
static T_2 F_23 ( struct V_15 * V_15 , const char T_3 * V_21 ,
T_4 V_22 , T_5 * V_23 )
{
F_2 () ;
if ( V_22 ) {
if ( ! V_18 ) {
T_4 V_24 ;
V_20 = 0 ;
for ( V_24 = 0 ; V_24 != V_22 ; V_24 ++ ) {
char V_25 ;
if ( F_24 ( V_25 , V_21 + V_24 ) )
return - V_26 ;
if ( V_25 == 'V' )
V_20 = 42 ;
}
}
F_1 () ;
}
return V_22 ;
}
static long F_25 ( struct V_15 * V_15 ,
unsigned int V_27 , unsigned long V_28 )
{
void T_3 * V_29 = ( void T_3 * ) V_28 ;
int T_3 * V_30 = V_29 ;
F_2 () ;
switch ( V_27 ) {
case V_31 :
if ( F_26 ( V_29 , & V_32 , sizeof( V_32 ) ) )
return - V_26 ;
else
return 0 ;
case V_33 :
case V_34 :
return F_27 ( ! ! ( V_35 & V_36 ) , V_30 ) ;
case V_37 : {
unsigned long V_9 ;
int V_38 , V_39 = - V_10 ;
if ( F_24 ( V_38 , V_30 ) )
return - V_26 ;
F_13 ( & V_11 , V_9 ) ;
if ( V_38 & V_40 ) {
F_4 () ;
V_39 = 0 ;
}
if ( V_38 & V_41 ) {
F_6 () ;
V_39 = 0 ;
}
F_15 ( & V_11 , V_9 ) ;
return V_39 ;
}
case V_42 :
F_1 () ;
return 0 ;
case V_43 : {
int V_44 ;
if ( F_24 ( V_44 , V_30 ) )
return - V_26 ;
if ( F_9 ( V_44 ) )
return - V_10 ;
}
case V_45 :
return F_27 ( V_13 , V_30 ) ;
default:
return - V_46 ;
}
}
static int F_28 ( struct V_47 * V_48 , T_6 V_49 )
{
F_2 () ;
V_50 = F_7 () ;
F_4 () ;
return 0 ;
}
static int F_29 ( struct V_47 * V_48 )
{
F_2 () ;
if ( V_50 ) {
F_9 ( V_13 ) ;
F_6 () ;
}
return 0 ;
}
static int T_7 F_30 ( struct V_47 * V_48 )
{
int V_39 ;
V_39 = F_31 ( & V_51 ) ;
if ( V_39 ) {
F_32 ( L_4 ,
V_52 , V_39 ) ;
return V_39 ;
}
F_33 ( L_5 ,
V_13 , V_18 ) ;
return 0 ;
}
static int T_8 F_34 ( struct V_47 * V_48 )
{
F_35 ( & V_51 ) ;
return 0 ;
}
static void F_36 ( struct V_47 * V_48 )
{
F_2 () ;
F_4 () ;
}
static int T_9 F_37 ( void )
{
int V_39 ;
F_2 () ;
if ( F_9 ( V_13 ) )
return - V_10 ;
V_39 = F_38 ( & V_53 ) ;
if ( V_39 ) {
F_32 ( L_6 ) ;
return V_39 ;
}
V_54 = F_39 ( V_55 ,
- 1 , NULL , 0 ) ;
if ( F_40 ( V_54 ) ) {
F_32 ( L_7 ) ;
F_41 ( & V_53 ) ;
return F_42 ( V_54 ) ;
}
return 0 ;
}
static void T_10 F_43 ( void )
{
F_44 ( V_54 ) ;
F_41 ( & V_53 ) ;
}
