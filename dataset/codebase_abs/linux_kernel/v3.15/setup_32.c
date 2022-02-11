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
F_12 () ;
F_13 ( F_14 ( V_1 ) ) ;
F_15 () ;
F_16 () ;
F_17 () ;
F_18 () ;
#ifdef F_19
if ( F_20 ( V_18 ) ||
F_20 ( V_19 ) )
V_20 . V_21 = V_22 ;
#endif
#ifdef F_21
if ( F_20 ( V_18 ) ||
F_20 ( V_19 ) )
V_20 . V_21 = V_23 ;
#endif
if ( V_20 . V_24 )
V_20 . V_24 ( L_1 , 0x200 ) ;
}
int T_2 F_22 ( char * V_25 )
{
if ( F_20 ( V_26 ) ) {
unsigned long V_27 = F_23 ( V_25 , NULL , 0 ) ;
F_24 ( V_28 L_2 , V_27 ) ;
F_25 ( 0 ) ;
F_25 ( V_27 ) ;
}
return 1 ;
}
int T_2 F_26 ( char * V_25 )
{
if ( F_20 ( V_29 ) ) {
unsigned long V_27 = F_23 ( V_25 , NULL , 0 ) ;
F_24 ( V_28 L_3 , V_27 ) ;
F_27 ( V_27 ) ;
}
return 1 ;
}
unsigned char F_28 ( int V_30 )
{
if ( V_20 . V_31 )
return V_20 . V_31 ( V_30 ) ;
return 0xff ;
}
void F_29 ( unsigned char V_27 , int V_30 )
{
if ( V_20 . V_32 )
V_20 . V_32 ( V_30 , V_27 ) ;
}
T_4 F_30 ( void )
{
if ( V_20 . V_33 )
return V_20 . V_33 () ;
return - 1 ;
}
void F_31 ( void )
{
if ( V_20 . F_31 )
V_20 . F_31 () ;
}
int T_2 F_32 ( void )
{
if ( V_20 . V_24 )
V_20 . V_24 ( L_4 , 0xffff ) ;
if ( V_20 . V_34 != NULL ) {
V_20 . V_34 () ;
}
return 0 ;
}
static void T_2 F_33 ( void )
{
unsigned int V_35 ;
F_34 (i) {
V_36 [ V_35 ] = (struct V_37 * )
F_14 ( F_35 ( V_38 , V_38 ) ) ;
V_39 [ V_35 ] = (struct V_37 * )
F_14 ( F_35 ( V_38 , V_38 ) ) ;
}
}
static void T_2 F_36 ( void )
{
unsigned int V_35 , V_40 ;
F_34 (i) {
#ifdef F_37
V_40 = F_38 ( V_35 ) ;
#else
V_40 = 0 ;
#endif
V_41 [ V_40 ] = (struct V_37 * )
F_14 ( F_35 ( V_38 , V_38 ) ) ;
#ifdef F_39
V_42 [ V_40 ] = (struct V_37 * )
F_14 ( F_35 ( V_38 , V_38 ) ) ;
V_43 [ V_40 ] = (struct V_37 * )
F_14 ( F_35 ( V_38 , V_38 ) ) ;
#endif
}
}
void T_2 F_40 ( char * * V_44 )
{
* V_44 = V_45 ;
V_46 = 500000000 / V_47 ;
F_41 () ;
F_42 () ;
if ( V_20 . V_48 )
V_20 . V_48 () ;
F_43 () ;
F_44 () ;
F_45 () ;
F_46 () ;
V_49 = V_50 -> V_49 ;
V_51 = V_50 -> V_51 ;
V_52 = 0 ;
if ( F_20 ( V_53 ) )
V_52 = V_51 = V_49 ;
if ( V_20 . V_54 )
F_47 () ;
V_55 . V_56 = ( unsigned long ) V_57 ;
V_55 . V_58 = ( unsigned long ) V_59 ;
V_55 . V_60 = ( unsigned long ) V_61 ;
V_55 . V_62 = V_63 ;
F_36 () ;
F_33 () ;
F_48 () ;
if ( V_20 . V_24 ) V_20 . V_24 ( L_5 , 0x3eab ) ;
#ifdef F_49
V_64 = & V_65 ;
#endif
if ( V_20 . F_40 )
V_20 . F_40 () ;
if ( V_20 . V_24 ) V_20 . V_24 ( L_6 , 0x3eab ) ;
F_50 () ;
F_51 () ;
}
