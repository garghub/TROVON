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
#endif
#ifdef F_18
V_16 = 10 ;
F_19 () ;
#endif
}
void F_20 ( const char * V_17 )
{
if ( V_18 ) {
char V_19 ;
if ( V_17 && * V_17 != '\0' ) {
while ( ( V_19 = * V_17 ++ ) != '\0' )
V_18 ( V_19 ) ;
}
if ( V_20 )
V_20 () ;
}
#if 0
else {
printk("%s", s);
}
#endif
}
int F_21 ( const char * V_17 , int V_21 )
{
int V_22 = V_21 ;
char V_19 ;
if ( ! V_18 )
return 0 ;
if ( V_17 && * V_17 != '\0' ) {
while ( ( ( V_19 = * V_17 ++ ) != '\0' ) && ( V_22 -- > 0 ) ) {
V_18 ( V_19 ) ;
}
}
if ( V_20 )
V_20 () ;
return V_21 - V_22 ;
}
int F_22 ( char * V_23 , int V_24 )
{
char * V_25 = V_23 ;
int V_26 , V_19 ;
if ( ! V_27 )
return 0 ;
for ( V_26 = 0 ; V_26 < V_24 ; ++ V_26 ) {
do {
V_19 = V_27 () ;
if ( V_19 == - 1 && V_26 == 0 )
return - 1 ;
} while ( V_19 == 0x11 || V_19 == 0x13 );
if ( V_19 == 0 || V_19 == - 1 )
break;
* V_25 ++ = V_19 ;
}
return V_26 ;
}
void F_23 ( const char * V_28 , ... )
{
char V_23 [ V_29 ] ;
T_2 args ;
va_start ( args , V_28 ) ;
vsnprintf ( V_23 , V_29 , V_28 , args ) ;
F_20 ( V_23 ) ;
va_end ( args ) ;
}
void T_1 F_24 ( char * V_17 , unsigned short V_30 )
{
F_20 ( V_17 ) ;
F_20 ( L_1 ) ;
}
static void F_25 ( struct V_31 * V_32 , const char * V_17 ,
unsigned int V_21 )
{
F_21 ( V_17 , V_21 ) ;
}
void T_1 F_19 ( void )
{
if ( V_33 )
return;
if ( ! V_18 )
return;
if ( strstr ( V_34 , L_2 ) ) {
F_26 ( V_35 L_3 ) ;
V_36 . V_37 &= ~ V_38 ;
}
V_33 = 1 ;
F_27 ( & V_36 ) ;
}
