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
#endif
#ifdef F_21
V_19 = 10 ;
F_22 () ;
#endif
}
void F_23 ( const char * V_20 )
{
if ( V_21 ) {
char V_22 ;
if ( V_20 && * V_20 != '\0' ) {
while ( ( V_22 = * V_20 ++ ) != '\0' )
V_21 ( V_22 ) ;
}
if ( V_23 )
V_23 () ;
}
#if 0
else {
printk("%s", s);
}
#endif
}
int F_24 ( const char * V_20 , int V_24 )
{
int V_25 = V_24 ;
char V_22 ;
if ( ! V_21 )
return 0 ;
if ( V_20 && * V_20 != '\0' ) {
while ( ( ( V_22 = * V_20 ++ ) != '\0' ) && ( V_25 -- > 0 ) ) {
V_21 ( V_22 ) ;
}
}
if ( V_23 )
V_23 () ;
return V_24 - V_25 ;
}
int F_25 ( char * V_26 , int V_27 )
{
char * V_28 = V_26 ;
int V_29 , V_22 ;
if ( ! V_30 )
return 0 ;
for ( V_29 = 0 ; V_29 < V_27 ; ++ V_29 ) {
do {
V_22 = V_30 () ;
if ( V_22 == - 1 && V_29 == 0 )
return - 1 ;
} while ( V_22 == 0x11 || V_22 == 0x13 );
if ( V_22 == 0 || V_22 == - 1 )
break;
* V_28 ++ = V_22 ;
}
return V_29 ;
}
void F_26 ( const char * V_31 , ... )
{
char V_26 [ V_32 ] ;
T_2 args ;
va_start ( args , V_31 ) ;
vsnprintf ( V_26 , V_32 , V_31 , args ) ;
F_23 ( V_26 ) ;
va_end ( args ) ;
}
void T_1 F_27 ( char * V_20 , unsigned short V_33 )
{
F_23 ( V_20 ) ;
F_23 ( L_1 ) ;
}
static void F_28 ( struct V_34 * V_35 , const char * V_20 ,
unsigned int V_24 )
{
F_24 ( V_20 , V_24 ) ;
}
void T_1 F_22 ( void )
{
if ( V_36 )
return;
if ( ! V_21 )
return;
if ( strstr ( V_37 , L_2 ) ) {
F_29 ( V_38 L_3 ) ;
V_39 . V_40 &= ~ V_41 ;
}
V_36 = 1 ;
F_30 ( & V_39 ) ;
}
