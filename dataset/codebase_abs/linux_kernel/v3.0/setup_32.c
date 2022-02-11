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
return V_17 + V_2 ;
}
T_1 void T_2 F_9 ( unsigned long V_1 )
{
F_10 () ;
F_11 () ;
F_12 ( F_13 ( V_1 ) ) ;
F_14 () ;
F_15 () ;
#ifdef F_16
if ( F_17 ( V_18 ) ||
F_17 ( V_19 ) )
V_20 . V_21 = V_22 ;
#endif
#ifdef F_18
if ( F_17 ( V_18 ) ||
F_17 ( V_19 ) )
V_20 . V_21 = V_23 ;
#endif
if ( V_20 . V_24 )
V_20 . V_24 ( L_1 , 0x200 ) ;
}
T_1 int T_2 F_19 ( char * V_25 )
{
if ( V_25 && strncmp ( V_25 , L_2 , 1 ) != 0 )
V_26 = 1 ;
return 0 ;
}
int T_2 F_20 ( char * V_25 )
{
if ( V_25 )
V_27 = F_21 ( V_25 , NULL , 0 ) ;
return 0 ;
}
int T_2 F_22 ( char * V_28 )
{
if ( F_17 ( V_29 ) ) {
unsigned long V_30 = F_21 ( V_28 , NULL , 0 ) ;
F_23 ( V_31 L_3 , V_30 ) ;
F_24 ( 0 ) ;
F_24 ( V_30 ) ;
}
return 1 ;
}
int T_2 F_25 ( char * V_28 )
{
if ( F_17 ( V_32 ) ) {
unsigned long V_30 = F_21 ( V_28 , NULL , 0 ) ;
F_23 ( V_31 L_4 , V_30 ) ;
F_26 ( V_30 ) ;
}
return 1 ;
}
unsigned char F_27 ( int V_33 )
{
if ( V_20 . V_34 )
return V_20 . V_34 ( V_33 ) ;
return 0xff ;
}
void F_28 ( unsigned char V_30 , int V_33 )
{
if ( V_20 . V_35 )
V_20 . V_35 ( V_33 , V_30 ) ;
}
T_3 F_29 ( void )
{
if ( V_20 . V_36 )
return V_20 . V_36 () ;
return - 1 ;
}
void F_30 ( void )
{
if ( V_20 . F_30 )
V_20 . F_30 () ;
}
int T_2 F_31 ( void )
{
if ( V_20 . V_24 )
V_20 . V_24 ( L_5 , 0xffff ) ;
if ( V_20 . V_37 != NULL ) {
V_20 . V_37 () ;
}
return 0 ;
}
static void T_2 F_32 ( void )
{
unsigned int V_38 ;
F_33 (i) {
V_39 [ V_38 ] = (struct V_40 * )
F_13 ( F_34 ( V_41 , V_41 ) ) ;
V_42 [ V_38 ] = (struct V_40 * )
F_13 ( F_34 ( V_41 , V_41 ) ) ;
}
}
static void T_2 F_35 ( void )
{
unsigned int V_38 , V_43 ;
F_33 (i) {
V_43 = F_36 ( V_38 ) ;
V_44 [ V_43 ] = (struct V_40 * )
F_13 ( F_34 ( V_41 , V_41 ) ) ;
#ifdef F_37
V_45 [ V_43 ] = (struct V_40 * )
F_13 ( F_34 ( V_41 , V_41 ) ) ;
V_46 [ V_43 ] = (struct V_40 * )
F_13 ( F_34 ( V_41 , V_41 ) ) ;
#endif
}
}
void T_2 F_38 ( char * * V_47 )
{
* V_47 = V_48 ;
V_49 = 500000000 / V_50 ;
F_39 () ;
F_40 () ;
if ( V_20 . V_51 )
V_20 . V_51 () ;
F_41 () ;
F_42 () ;
F_43 () ;
F_44 () ;
V_52 = V_53 -> V_52 ;
V_54 = V_53 -> V_54 ;
V_55 = 0 ;
if ( F_17 ( V_56 ) )
V_55 = V_54 = V_52 ;
V_57 = 180 ;
if ( V_20 . V_58 )
F_45 () ;
V_59 . V_60 = ( unsigned long ) V_61 ;
V_59 . V_62 = ( unsigned long ) V_63 ;
V_59 . V_64 = ( unsigned long ) V_65 ;
V_59 . V_66 = V_67 ;
F_35 () ;
F_32 () ;
F_46 () ;
if ( V_20 . V_24 ) V_20 . V_24 ( L_6 , 0x3eab ) ;
#ifdef F_47
V_68 = & V_69 ;
#endif
if ( V_20 . F_38 )
V_20 . F_38 () ;
if ( V_20 . V_24 ) V_20 . V_24 ( L_7 , 0x3eab ) ;
F_48 () ;
F_49 () ;
}
