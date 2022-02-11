void T_1 F_1 ( void )
{
#if F_2 ( V_1 )
F_3 () ;
#elif F_2 ( V_2 )
F_4 () ;
#elif F_2 ( V_3 )
F_5 () ;
#elif F_2 ( V_4 )
F_6 () ;
#elif F_2 ( V_5 )
F_7 () ;
#elif F_2 ( V_6 )
F_8 () ;
#elif F_2 ( V_7 )
F_9 () ;
#elif F_2 ( V_8 )
F_10 () ;
#elif F_2 ( V_9 )
F_11 () ;
#elif F_2 ( V_10 )
F_12 () ;
#elif F_2 ( V_11 )
F_13 () ;
#elif F_2 ( V_12 )
F_14 () ;
#elif F_2 ( V_13 )
F_15 () ;
#elif F_2 ( V_14 )
F_16 () ;
#elif F_2 ( V_15 )
F_17 () ;
#elif F_2 ( V_16 )
F_18 () ;
#elif F_2 ( V_17 )
F_19 () ;
#endif
#ifdef F_20
V_18 = 10 ;
F_21 () ;
#endif
}
void F_22 ( const char * V_19 )
{
if ( V_20 ) {
char V_21 ;
if ( V_19 && * V_19 != '\0' ) {
while ( ( V_21 = * V_19 ++ ) != '\0' )
V_20 ( V_21 ) ;
}
if ( V_22 )
V_22 () ;
}
#if 0
else {
printk("%s", s);
}
#endif
}
int F_23 ( const char * V_19 , int V_23 )
{
int V_24 = V_23 ;
char V_21 ;
if ( ! V_20 )
return 0 ;
if ( V_19 && * V_19 != '\0' ) {
while ( ( ( V_21 = * V_19 ++ ) != '\0' ) && ( V_24 -- > 0 ) ) {
V_20 ( V_21 ) ;
}
}
if ( V_22 )
V_22 () ;
return V_23 - V_24 ;
}
void F_24 ( const char * V_25 , ... )
{
char V_26 [ V_27 ] ;
T_2 args ;
va_start ( args , V_25 ) ;
vsnprintf ( V_26 , V_27 , V_25 , args ) ;
F_22 ( V_26 ) ;
va_end ( args ) ;
}
void T_1 F_25 ( char * V_19 , unsigned short V_28 )
{
F_22 ( V_19 ) ;
F_22 ( L_1 ) ;
}
static void F_26 ( struct V_29 * V_30 , const char * V_19 ,
unsigned int V_23 )
{
F_23 ( V_19 , V_23 ) ;
}
void T_1 F_21 ( void )
{
if ( V_31 )
return;
if ( ! V_20 )
return;
if ( strstr ( V_32 , L_2 ) ) {
F_27 ( V_33 L_3 ) ;
V_34 . V_35 &= ~ V_36 ;
}
V_31 = & V_34 ;
F_28 ( & V_34 ) ;
}
