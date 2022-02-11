T_1 unsigned long T_2 F_1 ( unsigned long V_1 )
{
unsigned long V_2 = F_2 () ;
F_3 ( ( void V_3 * ) F_4 ( & V_4 ) , 0 ,
V_5 - V_4 ) ;
F_5 ( V_2 , F_6 ( V_6 ) ) ;
F_7 () ;
return V_7 + V_2 ;
}
T_1 void T_2 F_8 ( T_3 V_1 )
{
F_9 () ;
F_10 () ;
F_11 ( ( unsigned int * ) & memcpy , V_8 ) ;
F_11 ( & V_9 , V_8 ) ;
F_12 ( F_13 ( V_1 ) ) ;
F_14 () ;
F_15 () ;
}
int T_2 F_16 ( char * V_10 )
{
if ( F_17 ( V_11 ) ) {
unsigned long V_12 = F_18 ( V_10 , NULL , 0 ) ;
F_19 ( V_13 L_1 , V_12 ) ;
F_20 ( 0 ) ;
F_20 ( V_12 ) ;
}
return 1 ;
}
int T_2 F_21 ( char * V_10 )
{
if ( F_17 ( V_14 ) ) {
unsigned long V_12 = F_18 ( V_10 , NULL , 0 ) ;
F_19 ( V_13 L_2 , V_12 ) ;
F_22 ( V_12 ) ;
}
return 1 ;
}
unsigned char F_23 ( int V_15 )
{
if ( V_16 . V_17 )
return V_16 . V_17 ( V_15 ) ;
return 0xff ;
}
void F_24 ( unsigned char V_12 , int V_15 )
{
if ( V_16 . V_18 )
V_16 . V_18 ( V_15 , V_12 ) ;
}
T_4 F_25 ( void )
{
if ( V_16 . V_19 )
return V_16 . V_19 () ;
return - 1 ;
}
void F_26 ( void )
{
if ( V_16 . F_26 )
V_16 . F_26 () ;
}
int T_2 F_27 ( void )
{
if ( V_16 . V_20 )
V_16 . V_20 ( L_3 , 0xffff ) ;
if ( V_16 . V_21 != NULL ) {
V_16 . V_21 () ;
}
return 0 ;
}
void T_2 F_28 ( void )
{
unsigned int V_22 ;
F_29 (i) {
V_23 [ V_22 ] = (struct V_24 * )
F_13 ( F_30 ( V_25 , V_25 ) ) ;
V_26 [ V_22 ] = (struct V_24 * )
F_13 ( F_30 ( V_25 , V_25 ) ) ;
}
}
void T_2 F_31 ( void )
{
unsigned int V_22 , V_27 ;
F_29 (i) {
#ifdef F_32
V_27 = F_33 ( V_22 ) ;
#else
V_27 = 0 ;
#endif
V_28 [ V_27 ] = (struct V_24 * )
F_13 ( F_30 ( V_25 , V_25 ) ) ;
#ifdef F_34
V_29 [ V_27 ] = (struct V_24 * )
F_13 ( F_30 ( V_25 , V_25 ) ) ;
V_30 [ V_27 ] = (struct V_24 * )
F_13 ( F_30 ( V_25 , V_25 ) ) ;
#endif
}
}
void T_2 F_35 ( void )
{
#ifdef F_36
if ( F_17 ( V_31 ) ||
F_17 ( V_32 ) )
V_16 . V_33 = V_34 ;
#endif
#ifdef F_37
if ( F_17 ( V_31 ) ||
F_17 ( V_32 ) )
V_16 . V_33 = V_35 ;
#endif
}
T_2 void F_38 ( void )
{
V_36 = V_37 -> V_36 ;
V_38 = V_37 -> V_38 ;
V_39 = 0 ;
if ( F_17 ( V_40 ) )
V_39 = V_38 = V_36 ;
}
