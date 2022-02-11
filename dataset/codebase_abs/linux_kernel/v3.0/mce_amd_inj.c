static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
const char * V_5 , T_2 V_6 )
{
int V_7 = 0 ;
unsigned long V_8 ;
V_7 = F_2 ( V_5 , 10 , & V_8 ) ;
if ( V_7 < 0 ) {
F_3 ( V_9 L_1 ) ;
return - V_10 ;
}
if ( V_8 > 5 )
if ( V_11 . V_12 != 0x15 || V_8 > 6 ) {
F_3 ( V_9 L_2 , V_8 ) ;
return - V_10 ;
}
V_13 . V_14 = V_8 ;
F_4 ( NULL , 0 , & V_13 ) ;
return V_6 ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_15 )
{
return sprintf ( V_15 , L_3 , V_13 . V_14 ) ;
}
static int T_3 F_6 ( void )
{
struct V_16 * V_17 = NULL ;
int V_18 , V_19 = 0 ;
V_17 = F_7 () ;
if ( ! V_17 )
return - V_10 ;
V_20 = F_8 ( L_4 , & V_17 -> V_21 . V_2 ) ;
if ( ! V_20 ) {
F_3 ( V_9 L_5 ) ;
V_19 = - V_22 ;
goto V_23;
}
for ( V_18 = 0 ; V_18 < F_9 ( V_24 ) ; V_18 ++ ) {
V_19 = F_10 ( V_20 , & V_24 [ V_18 ] -> V_4 ) ;
if ( V_19 ) {
F_3 ( V_9 L_6 ,
V_24 [ V_18 ] -> V_4 . V_25 ) ;
goto V_26;
}
}
return 0 ;
V_26:
while ( -- V_18 >= 0 )
F_11 ( V_20 , & V_24 [ V_18 ] -> V_4 ) ;
F_12 ( V_20 ) ;
V_23:
F_13 () ;
return V_19 ;
}
static void T_4 F_14 ( void )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < F_9 ( V_24 ) ; V_18 ++ )
F_11 ( V_20 , & V_24 [ V_18 ] -> V_4 ) ;
F_12 ( V_20 ) ;
F_13 () ;
}
