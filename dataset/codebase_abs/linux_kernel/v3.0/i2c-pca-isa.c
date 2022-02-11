static void F_1 ( void * V_1 , int V_2 , int V_3 )
{
#ifdef F_2
static char * V_4 [] = { L_1 , L_2 , L_3 , L_4 } ;
F_3 ( V_5 L_5 , V_4 [ V_2 ] ,
V_6 + V_2 , V_3 ) ;
#endif
F_4 ( V_3 , V_6 + V_2 ) ;
}
static int F_5 ( void * V_1 , int V_2 )
{
int V_7 = F_6 ( V_6 + V_2 ) ;
#ifdef F_2
{
static char * V_4 [] = { L_6 , L_2 , L_3 , L_4 } ;
F_3 ( V_5 L_7 , V_4 [ V_2 ] , V_7 ) ;
}
#endif
return V_7 ;
}
static int F_7 ( void * V_1 )
{
unsigned long V_8 ;
long V_9 ;
if ( V_10 > - 1 ) {
V_9 = F_8 ( V_11 ,
F_5 ( V_1 , V_12 )
& V_13 , V_14 . V_8 ) ;
} else {
V_8 = V_15 + V_14 . V_8 ;
do {
V_9 = F_9 ( V_15 , V_8 ) ;
if ( F_5 ( V_1 , V_12 )
& V_13 )
break;
F_10 ( 100 ) ;
} while ( V_9 );
}
return V_9 > 0 ;
}
static void F_11 ( void * V_1 )
{
F_3 (KERN_WARNING DRIVER L_8 ) ;
}
static T_1 F_12 ( int V_16 , void * V_17 ) {
F_13 ( & V_11 ) ;
return V_18 ;
}
static int T_2 F_14 ( struct V_19 * V_20 , unsigned int V_21 )
{
int V_22 = V_6 != 0 ;
if ( V_22 ) {
if ( V_10 <= - 1 )
F_15 ( V_20 , L_9 ) ;
} else
F_16 ( V_20 , L_10 ) ;
return V_22 ;
}
static int T_2 F_17 ( struct V_19 * V_20 , unsigned int V_21 )
{
F_18 ( & V_11 ) ;
F_19 ( V_20 , L_11 , V_6 , V_10 ) ;
#ifdef F_20
if ( F_21 ( V_6 ) ) {
F_16 ( V_20 , L_12 , V_6 ) ;
goto V_23;
}
#endif
if ( ! F_22 ( V_6 , V_24 , L_13 ) ) {
F_16 ( V_20 , L_14 , V_6 ) ;
goto V_23;
}
if ( V_10 > - 1 ) {
if ( F_23 ( V_10 , F_12 , 0 , L_13 , & V_14 ) < 0 ) {
F_16 ( V_20 , L_15 , V_10 ) ;
goto V_25;
}
}
V_26 . V_27 = clock ;
if ( F_24 ( & V_14 ) < 0 ) {
F_16 ( V_20 , L_16 ) ;
goto V_28;
}
return 0 ;
V_28:
if ( V_10 > - 1 )
F_25 ( V_10 , & V_14 ) ;
V_25:
F_26 ( V_6 , V_24 ) ;
V_23:
return - V_29 ;
}
static int T_3 F_27 ( struct V_19 * V_20 , unsigned int V_21 )
{
F_28 ( & V_14 ) ;
if ( V_10 > - 1 ) {
F_29 ( V_10 ) ;
F_25 ( V_10 , & V_14 ) ;
}
F_26 ( V_6 , V_24 ) ;
return 0 ;
}
static int T_4 F_30 ( void )
{
return F_31 ( & V_30 , 1 ) ;
}
static void T_5 F_32 ( void )
{
F_33 ( & V_30 ) ;
}
