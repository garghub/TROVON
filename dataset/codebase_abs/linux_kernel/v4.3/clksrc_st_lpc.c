static void T_1 F_1 ( void )
{
F_2 ( 0 , V_1 . V_2 + V_3 ) ;
F_2 ( 0 , V_1 . V_2 + V_4 ) ;
F_2 ( 0 , V_1 . V_2 + V_5 ) ;
F_2 ( 1 , V_1 . V_2 + V_3 ) ;
}
static T_2 T_3 F_3 ( void )
{
return ( T_2 ) F_4 ( V_1 . V_2 + V_5 ) ;
}
static int T_1 F_5 ( void )
{
unsigned long V_6 ;
int V_7 ;
F_1 () ;
V_6 = F_6 ( V_1 . V_8 ) ;
F_7 ( F_3 , 32 , V_6 ) ;
V_7 = F_8 ( V_1 . V_2 + V_5 ,
L_1 , V_6 , 300 , 32 ,
V_9 ) ;
if ( V_7 ) {
F_9 ( L_2 ) ;
return V_7 ;
}
return 0 ;
}
static int T_1 F_10 ( struct V_10 * V_11 )
{
struct V_8 * V_8 ;
V_8 = F_11 ( V_11 , 0 ) ;
if ( F_12 ( V_8 ) ) {
F_9 ( L_3 ) ;
return F_13 ( V_8 ) ;
}
if ( F_14 ( V_8 ) ) {
F_9 ( L_4 ) ;
return - V_12 ;
}
if ( ! F_6 ( V_8 ) ) {
F_9 ( L_5 ) ;
F_15 ( V_8 ) ;
return - V_12 ;
}
V_1 . V_8 = V_8 ;
return 0 ;
}
static void T_1 F_16 ( struct V_10 * V_11 )
{
int V_7 ;
T_4 V_13 ;
V_7 = F_17 ( V_11 , L_6 , & V_13 ) ;
if ( V_7 ) {
F_9 ( L_7 ) ;
return;
}
if ( V_13 != V_14 )
return;
V_1 . V_2 = F_18 ( V_11 , 0 ) ;
if ( ! V_1 . V_2 ) {
F_9 ( L_8 ) ;
return;
}
if ( F_10 ( V_11 ) ) {
F_19 ( V_1 . V_2 ) ;
return;
}
if ( F_5 () ) {
F_15 ( V_1 . V_8 ) ;
F_20 ( V_1 . V_8 ) ;
F_19 ( V_1 . V_2 ) ;
return;
}
F_21 ( L_9 ,
F_6 ( V_1 . V_8 ) ) ;
}
