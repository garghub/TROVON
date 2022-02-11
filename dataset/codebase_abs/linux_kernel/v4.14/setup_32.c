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
unsigned int * V_8 = & V_9 ;
unsigned long V_10 ;
F_9 () ;
F_10 () ;
F_11 ( ( unsigned int * ) & memcpy , V_11 ) ;
V_10 = F_12 ( V_8 , F_13 ( V_8 ) , 0x820000 ) ;
F_11 ( V_8 , V_10 ) ;
F_14 ( F_15 ( V_1 ) ) ;
F_16 () ;
F_17 () ;
}
int T_2 F_18 ( char * V_12 )
{
if ( F_19 ( V_13 ) ) {
unsigned long V_14 = F_20 ( V_12 , NULL , 0 ) ;
F_21 ( V_15 L_1 , V_14 ) ;
F_22 ( 0 ) ;
F_22 ( V_14 ) ;
}
return 1 ;
}
int T_2 F_23 ( char * V_12 )
{
if ( F_19 ( V_16 ) ) {
unsigned long V_14 = F_20 ( V_12 , NULL , 0 ) ;
F_21 ( V_15 L_2 , V_14 ) ;
F_24 ( V_14 ) ;
}
return 1 ;
}
unsigned char F_25 ( int V_8 )
{
if ( V_17 . V_18 )
return V_17 . V_18 ( V_8 ) ;
return 0xff ;
}
void F_26 ( unsigned char V_14 , int V_8 )
{
if ( V_17 . V_19 )
V_17 . V_19 ( V_8 , V_14 ) ;
}
T_4 F_27 ( void )
{
if ( V_17 . V_20 )
return V_17 . V_20 () ;
return - 1 ;
}
void F_28 ( void )
{
if ( V_17 . F_28 )
V_17 . F_28 () ;
}
int T_2 F_29 ( void )
{
if ( V_17 . V_21 )
V_17 . V_21 ( L_3 , 0xffff ) ;
if ( V_17 . V_22 != NULL ) {
V_17 . V_22 () ;
}
return 0 ;
}
void T_2 F_30 ( void )
{
unsigned int V_23 ;
F_31 (i) {
V_24 [ V_23 ] = (struct V_25 * )
F_15 ( F_32 ( V_26 , V_26 ) ) ;
V_27 [ V_23 ] = (struct V_25 * )
F_15 ( F_32 ( V_26 , V_26 ) ) ;
}
}
void T_2 F_33 ( void )
{
unsigned int V_23 , V_28 ;
F_31 (i) {
#ifdef F_34
V_28 = F_35 ( V_23 ) ;
#else
V_28 = 0 ;
#endif
V_29 [ V_28 ] = (struct V_25 * )
F_15 ( F_32 ( V_26 , V_26 ) ) ;
#ifdef F_36
V_30 [ V_28 ] = (struct V_25 * )
F_15 ( F_32 ( V_26 , V_26 ) ) ;
V_31 [ V_28 ] = (struct V_25 * )
F_15 ( F_32 ( V_26 , V_26 ) ) ;
#endif
}
}
void T_2 F_37 ( void )
{
#ifdef F_38
if ( F_19 ( V_32 ) ||
F_19 ( V_33 ) )
V_17 . V_34 = V_35 ;
#endif
#ifdef F_39
if ( F_19 ( V_32 ) ||
F_19 ( V_33 ) )
V_17 . V_34 = V_36 ;
#endif
}
T_2 void F_40 ( void )
{
V_37 = V_38 -> V_37 ;
V_39 = V_38 -> V_39 ;
V_40 = 0 ;
if ( F_19 ( V_41 ) )
V_40 = V_39 = V_37 ;
}
