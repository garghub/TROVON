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
#endif
#ifdef F_17
V_15 = 10 ;
#endif
}
void F_18 ( const char * V_16 )
{
if ( V_17 ) {
char V_18 ;
if ( V_16 && * V_16 != '\0' ) {
while ( ( V_18 = * V_16 ++ ) != '\0' )
V_17 ( V_18 ) ;
}
if ( V_19 )
V_19 () ;
}
#if 0
else {
printk("%s", s);
}
#endif
}
int F_19 ( const char * V_16 , int V_20 )
{
int V_21 = V_20 ;
char V_18 ;
if ( ! V_17 )
return 0 ;
if ( V_16 && * V_16 != '\0' ) {
while ( ( ( V_18 = * V_16 ++ ) != '\0' ) && ( V_21 -- > 0 ) ) {
V_17 ( V_18 ) ;
}
}
if ( V_19 )
V_19 () ;
return V_20 - V_21 ;
}
int F_20 ( char * V_22 , int V_23 )
{
char * V_24 = V_22 ;
int V_25 , V_18 ;
if ( ! V_26 )
return 0 ;
for ( V_25 = 0 ; V_25 < V_23 ; ++ V_25 ) {
do {
V_18 = V_26 () ;
if ( V_18 == - 1 && V_25 == 0 )
return - 1 ;
} while ( V_18 == 0x11 || V_18 == 0x13 );
if ( V_18 == 0 || V_18 == - 1 )
break;
* V_24 ++ = V_18 ;
}
return V_25 ;
}
void F_21 ( const char * V_27 , ... )
{
char V_22 [ V_28 ] ;
T_2 args ;
va_start ( args , V_27 ) ;
vsnprintf ( V_22 , V_28 , V_27 , args ) ;
F_18 ( V_22 ) ;
va_end ( args ) ;
}
void T_1 F_22 ( char * V_16 , unsigned short V_29 )
{
F_18 ( V_16 ) ;
F_18 ( L_1 ) ;
}
static void F_23 ( struct V_30 * V_31 , const char * V_16 ,
unsigned int V_20 )
{
F_19 ( V_16 , V_20 ) ;
}
void T_1 F_24 ( void )
{
if ( V_32 )
return;
if ( ! V_17 )
return;
if ( strstr ( V_33 , L_2 ) ) {
F_25 ( V_34 L_3 ) ;
V_35 . V_36 &= ~ V_37 ;
}
V_32 = 1 ;
F_26 ( & V_35 ) ;
}
