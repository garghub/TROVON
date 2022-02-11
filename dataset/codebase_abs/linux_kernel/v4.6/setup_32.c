T_1 unsigned long T_2 F_1 ( unsigned long V_1 )
{
unsigned long V_2 = F_2 () ;
struct V_3 * V_4 ;
F_3 ( ( void V_5 * ) F_4 ( & V_6 ) , 0 ,
V_7 - V_6 ) ;
V_4 = F_5 ( V_2 , F_6 ( V_8 ) ) ;
F_7 ( V_4 -> V_9 ,
F_4 ( & V_10 ) ,
F_4 ( & V_11 ) ) ;
F_7 ( V_4 -> V_12 ,
F_4 ( & V_13 ) ,
F_4 ( & V_14 ) ) ;
F_8 ( V_4 -> V_9 ,
F_4 ( & V_15 ) ,
F_4 ( & V_16 ) ) ;
F_9 () ;
return V_17 + V_2 ;
}
T_1 void T_2 F_10 ( T_3 V_1 )
{
F_11 () ;
F_12 ( ( unsigned int * ) & memcpy , V_18 ) ;
F_12 ( & V_19 , V_18 ) ;
F_13 ( F_14 ( V_1 ) ) ;
F_15 () ;
F_16 () ;
F_17 () ;
F_18 () ;
#ifdef F_19
if ( F_20 ( V_20 ) ||
F_20 ( V_21 ) )
V_22 . V_23 = V_24 ;
#endif
#ifdef F_21
if ( F_20 ( V_20 ) ||
F_20 ( V_21 ) )
V_22 . V_23 = V_25 ;
#endif
if ( V_22 . V_26 )
V_22 . V_26 ( L_1 , 0x200 ) ;
}
int T_2 F_22 ( char * V_27 )
{
if ( F_20 ( V_28 ) ) {
unsigned long V_29 = F_23 ( V_27 , NULL , 0 ) ;
F_24 ( V_30 L_2 , V_29 ) ;
F_25 ( 0 ) ;
F_25 ( V_29 ) ;
}
return 1 ;
}
int T_2 F_26 ( char * V_27 )
{
if ( F_20 ( V_31 ) ) {
unsigned long V_29 = F_23 ( V_27 , NULL , 0 ) ;
F_24 ( V_30 L_3 , V_29 ) ;
F_27 ( V_29 ) ;
}
return 1 ;
}
unsigned char F_28 ( int V_32 )
{
if ( V_22 . V_33 )
return V_22 . V_33 ( V_32 ) ;
return 0xff ;
}
void F_29 ( unsigned char V_29 , int V_32 )
{
if ( V_22 . V_34 )
V_22 . V_34 ( V_32 , V_29 ) ;
}
T_4 F_30 ( void )
{
if ( V_22 . V_35 )
return V_22 . V_35 () ;
return - 1 ;
}
void F_31 ( void )
{
if ( V_22 . F_31 )
V_22 . F_31 () ;
}
int T_2 F_32 ( void )
{
if ( V_22 . V_26 )
V_22 . V_26 ( L_4 , 0xffff ) ;
if ( V_22 . V_36 != NULL ) {
V_22 . V_36 () ;
}
return 0 ;
}
static void T_2 F_33 ( void )
{
unsigned int V_37 ;
F_34 (i) {
V_38 [ V_37 ] = (struct V_39 * )
F_14 ( F_35 ( V_40 , V_40 ) ) ;
V_41 [ V_37 ] = (struct V_39 * )
F_14 ( F_35 ( V_40 , V_40 ) ) ;
}
}
static void T_2 F_36 ( void )
{
unsigned int V_37 , V_42 ;
F_34 (i) {
#ifdef F_37
V_42 = F_38 ( V_37 ) ;
#else
V_42 = 0 ;
#endif
V_43 [ V_42 ] = (struct V_39 * )
F_14 ( F_35 ( V_40 , V_40 ) ) ;
#ifdef F_39
V_44 [ V_42 ] = (struct V_39 * )
F_14 ( F_35 ( V_40 , V_40 ) ) ;
V_45 [ V_42 ] = (struct V_39 * )
F_14 ( F_35 ( V_40 , V_40 ) ) ;
#endif
}
}
void T_2 F_40 ( char * * V_46 )
{
* V_46 = V_47 ;
V_48 = 500000000 / V_49 ;
F_41 () ;
F_42 () ;
if ( V_22 . V_50 )
V_22 . V_50 () ;
F_43 () ;
F_44 () ;
F_45 () ;
F_46 () ;
V_51 = V_52 -> V_51 ;
V_53 = V_52 -> V_53 ;
V_54 = 0 ;
if ( F_20 ( V_55 ) )
V_54 = V_53 = V_51 ;
if ( V_22 . V_56 )
F_47 () ;
V_57 . V_58 = ( unsigned long ) V_59 ;
V_57 . V_60 = ( unsigned long ) V_61 ;
V_57 . V_62 = ( unsigned long ) V_63 ;
V_57 . V_64 = V_65 ;
F_36 () ;
F_33 () ;
F_48 () ;
if ( V_22 . V_26 ) V_22 . V_26 ( L_5 , 0x3eab ) ;
#ifdef F_49
V_66 = & V_67 ;
#endif
if ( V_22 . F_40 )
V_22 . F_40 () ;
if ( V_22 . V_26 ) V_22 . V_26 ( L_6 , 0x3eab ) ;
F_50 () ;
F_51 () ;
}
