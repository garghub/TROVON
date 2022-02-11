int F_1 ( void )
{
int V_1 ;
F_2 ( & V_2 ) ;
if ( ( V_1 = F_3 () ) )
goto V_3;
if ( ( V_1 = F_4 () ) )
goto V_4;
if ( V_5 . V_6 && ( V_1 = V_5 . V_6 () ) )
goto V_7;
if ( V_5 . V_8 ) {
int V_9 = V_5 . V_8 () ;
switch ( V_9 ) {
case 0 :
goto V_10;
case 1 :
goto V_11;
case - 1 :
goto V_12;
default:
goto V_12;
}
}
V_11:
if ( ( V_1 = V_8 () ) )
goto V_12;
V_10:
V_13 = 1 ;
F_5 ( & V_2 ) ;
return 0 ;
V_12:
if ( V_5 . V_14 )
V_5 . V_14 () ;
V_7:
F_6 () ;
V_4:
F_7 () ;
V_3:
F_5 ( & V_2 ) ;
return V_1 ;
}
static void F_8 ( void )
{
if ( V_5 . V_15 )
F_9 ( & V_16 , V_17 ) ;
}
static void F_10 ( void )
{
F_11 ( & V_16 ) ;
}
static void F_12 ( struct V_18 * V_19 )
{
if ( V_5 . V_15 () )
return;
F_13 ( & V_20 . V_21 ) ;
F_8 () ;
}
int F_14 ( unsigned long V_22 )
{
int V_1 = 0 ;
unsigned long V_23 ;
F_2 ( & V_2 ) ;
if ( V_24 ) {
V_1 = - V_25 ;
goto V_3;
}
if ( ! V_5 . V_15 ) {
V_1 = - V_26 ;
goto V_3;
}
V_23 = F_15 ( V_22 ) ;
if ( V_23 == V_27 ) {
V_1 = - V_26 ;
goto V_3;
}
V_17 = V_23 ;
V_3:
F_5 ( & V_2 ) ;
return V_1 ;
}
static inline void F_8 ( void ) { }
static inline void F_10 ( void ) { }
int F_16 ( void )
{
int V_1 = - V_26 ;
F_2 ( & V_2 ) ;
if ( ! V_13 )
goto V_3;
V_1 = 0 ;
if ( V_24 )
goto V_3;
F_17 () ;
if ( ( V_1 = V_5 . V_28 () ) )
goto V_3;
F_8 () ;
V_24 = 1 ;
V_3:
F_5 ( & V_2 ) ;
return V_1 ;
}
void F_18 ( void )
{
F_2 ( & V_2 ) ;
if ( ! V_24 )
goto V_3;
V_5 . V_29 () ;
V_24 = 0 ;
F_10 () ;
F_19 () ;
V_3:
F_5 ( & V_2 ) ;
}
void F_20 ( void )
{
F_2 ( & V_2 ) ;
if ( V_5 . V_30 ) {
int V_9 = V_5 . V_30 () ;
switch ( V_9 ) {
case 0 :
goto V_10;
case 1 :
goto V_11;
default:
goto V_10;
}
}
V_11:
V_30 () ;
V_10:
if ( V_5 . V_14 )
V_5 . V_14 () ;
V_13 = 0 ;
F_6 () ;
F_7 () ;
F_5 ( & V_2 ) ;
}
int F_21 ( unsigned long * V_31 , unsigned long V_32 )
{
int V_1 = - V_25 ;
F_2 ( & V_2 ) ;
if ( ! V_24 ) {
* V_31 = V_32 ;
V_1 = 0 ;
}
F_5 ( & V_2 ) ;
return V_1 ;
}
static int T_1 F_22 ( void )
{
int V_1 ;
V_1 = F_23 ( & V_5 ) ;
V_33 = V_1 || V_34 ;
if ( V_33 ) {
if ( ! V_1 )
F_24 () ;
V_1 = F_25 ( & V_5 ) ;
if ( V_1 )
return V_1 ;
}
V_1 = F_26 () ;
if ( ! V_1 )
return 0 ;
if ( V_33 )
F_27 () ;
else
F_24 () ;
return V_1 ;
}
static void T_2 F_28 ( void )
{
F_29 () ;
if ( V_33 )
F_27 () ;
else
F_24 () ;
}
