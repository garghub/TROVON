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
#elif F_2 ( V_18 )
F_20 () ;
#elif F_2 ( V_19 )
F_21 () ;
#endif
#ifdef F_22
V_20 = 10 ;
F_23 () ;
#endif
}
void F_24 ( const char * V_21 )
{
if ( V_22 ) {
char V_23 ;
if ( V_21 && * V_21 != '\0' ) {
while ( ( V_23 = * V_21 ++ ) != '\0' )
V_22 ( V_23 ) ;
}
if ( V_24 )
V_24 () ;
}
#if 0
else {
printk("%s", s);
}
#endif
}
int F_25 ( const char * V_21 , int V_25 )
{
int V_26 = V_25 ;
char V_23 ;
if ( ! V_22 )
return 0 ;
if ( V_21 && * V_21 != '\0' ) {
while ( ( ( V_23 = * V_21 ++ ) != '\0' ) && ( V_26 -- > 0 ) ) {
V_22 ( V_23 ) ;
}
}
if ( V_24 )
V_24 () ;
return V_25 - V_26 ;
}
void F_26 ( const char * V_27 , ... )
{
char V_28 [ V_29 ] ;
T_2 args ;
va_start ( args , V_27 ) ;
vsnprintf ( V_28 , V_29 , V_27 , args ) ;
F_24 ( V_28 ) ;
va_end ( args ) ;
}
void T_1 F_27 ( char * V_21 , unsigned short V_30 )
{
F_24 ( V_21 ) ;
F_24 ( L_1 ) ;
}
static void F_28 ( struct V_31 * V_32 , const char * V_21 ,
unsigned int V_25 )
{
F_25 ( V_21 , V_25 ) ;
}
void T_1 F_23 ( void )
{
if ( V_33 )
return;
if ( ! V_22 )
return;
if ( strstr ( V_34 , L_2 ) ) {
F_29 ( V_35 L_3 ) ;
V_36 . V_37 &= ~ V_38 ;
}
V_33 = & V_36 ;
F_30 ( & V_36 ) ;
}
