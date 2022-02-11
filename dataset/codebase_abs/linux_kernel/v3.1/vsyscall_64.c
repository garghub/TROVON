static int T_1 F_1 ( char * V_1 )
{
if ( V_1 ) {
if ( ! strcmp ( L_1 , V_1 ) )
V_2 = V_3 ;
else if ( ! strcmp ( L_2 , V_1 ) )
V_2 = V_4 ;
else if ( ! strcmp ( L_3 , V_1 ) )
V_2 = V_5 ;
else
return - V_6 ;
return 0 ;
}
return - V_6 ;
}
void F_2 ( void )
{
unsigned long V_7 ;
F_3 ( & V_8 . V_9 , V_7 ) ;
V_8 . V_10 = V_10 ;
F_4 ( & V_8 . V_9 , V_7 ) ;
}
void F_5 ( struct V_11 * V_12 , struct V_11 * V_13 ,
struct V_14 * clock , T_2 V_15 )
{
unsigned long V_7 ;
F_3 ( & V_8 . V_9 , V_7 ) ;
V_8 . clock . V_16 = clock -> V_17 . V_16 ;
V_8 . clock . V_18 = clock -> V_18 ;
V_8 . clock . V_19 = clock -> V_19 ;
V_8 . clock . V_15 = V_15 ;
V_8 . clock . V_20 = clock -> V_20 ;
V_8 . V_21 = V_12 -> V_22 ;
V_8 . V_23 = V_12 -> V_24 ;
V_8 . V_25 = * V_13 ;
V_8 . V_26 = F_6 () ;
F_4 ( & V_8 . V_9 , V_7 ) ;
}
static void F_7 ( const char * V_27 , struct V_28 * V_29 ,
const char * V_30 )
{
static F_8 ( V_31 , V_32 , V_33 ) ;
struct V_34 * V_35 ;
if ( ! V_36 || ! F_9 ( & V_31 ) )
return;
V_35 = V_37 ;
F_10 ( L_4 ,
V_27 , V_35 -> V_38 , F_11 ( V_35 ) ,
V_30 , V_29 -> V_39 , V_29 -> V_40 ,
V_29 -> V_41 , V_29 -> V_42 , V_29 -> V_43 , V_29 -> V_44 ) ;
}
static int F_12 ( unsigned long V_45 )
{
int V_46 ;
if ( ( V_45 & ~ 0xC00UL ) != V_47 )
return - V_6 ;
V_46 = ( V_45 & 0xC00UL ) >> 10 ;
if ( V_46 >= 3 )
return - V_6 ;
return V_46 ;
}
bool F_13 ( struct V_28 * V_29 , unsigned long V_48 )
{
struct V_34 * V_35 ;
unsigned long V_49 ;
int V_50 ;
long V_51 ;
F_14 ( V_48 != V_29 -> V_39 ) ;
if ( V_2 == V_5 ) {
F_7 ( V_52 , V_29 ,
L_5 ) ;
return false ;
}
V_50 = F_12 ( V_48 ) ;
F_15 ( V_50 ) ;
if ( V_50 < 0 ) {
F_7 ( V_53 , V_29 ,
L_6 ) ;
goto V_54;
}
if ( F_16 ( V_49 , ( unsigned long V_55 * ) V_29 -> V_41 ) != 0 ) {
F_7 ( V_53 , V_29 ,
L_7 ) ;
goto V_54;
}
V_35 = V_37 ;
if ( F_17 ( & V_35 -> V_56 ) )
F_18 ( V_57 ) ;
switch ( V_50 ) {
case 0 :
V_51 = F_19 (
(struct V_58 V_55 * ) V_29 -> V_44 ,
(struct V_59 V_55 * ) V_29 -> V_43 ) ;
break;
case 1 :
V_51 = F_20 ( ( V_60 V_55 * ) V_29 -> V_44 ) ;
break;
case 2 :
V_51 = F_21 ( ( unsigned V_55 * ) V_29 -> V_44 ,
( unsigned V_55 * ) V_29 -> V_43 ,
0 ) ;
break;
}
if ( V_51 == - V_61 ) {
F_7 ( V_52 , V_29 ,
L_8 ) ;
goto V_54;
}
V_29 -> V_42 = V_51 ;
V_29 -> V_39 = V_49 ;
V_29 -> V_41 += 8 ;
return true ;
V_54:
F_22 ( V_62 , V_37 ) ;
return true ;
}
static void T_3 F_23 ( int V_63 )
{
unsigned long V_64 ;
unsigned long V_65 = 0 ;
#ifdef F_24
V_65 = F_25 ( V_63 ) ;
#endif
if ( F_26 ( & F_27 ( V_63 ) , V_66 ) )
F_28 ( ( V_65 << 12 ) | V_63 ) ;
V_64 = 0x0f40000000000ULL ;
V_64 |= V_63 ;
V_64 |= ( V_65 & 0xf ) << 12 ;
V_64 |= ( V_65 >> 4 ) << 48 ;
F_29 ( F_30 ( V_63 ) , V_67 , & V_64 , V_68 ) ;
}
static void T_3 F_31 ( void * V_69 )
{
F_23 ( F_32 () ) ;
}
static int T_3
F_33 ( struct V_70 * V_71 , unsigned long V_72 , void * V_69 )
{
long V_63 = ( long ) V_69 ;
if ( V_72 == V_73 || V_72 == V_74 )
F_34 ( V_63 , F_31 , NULL , 1 ) ;
return V_75 ;
}
void T_1 F_35 ( void )
{
extern char V_76 ;
unsigned long V_77 = F_36 ( & V_76 ) ;
extern char V_78 ;
unsigned long V_79 = F_36 ( & V_78 ) ;
F_37 ( V_80 , V_77 ,
V_2 == V_4
? V_81
: V_82 ) ;
F_38 ( ( unsigned long ) F_39 ( V_80 ) !=
( unsigned long ) V_47 ) ;
F_37 ( V_83 , V_79 , V_82 ) ;
F_38 ( ( unsigned long ) F_39 ( V_83 ) !=
( unsigned long ) V_84 ) ;
}
static int T_1 F_40 ( void )
{
F_41 ( F_42 ( 0 ) != F_39 ( V_80 ) ) ;
F_43 ( F_31 , NULL , 1 ) ;
F_44 ( F_33 , 30 ) ;
return 0 ;
}
