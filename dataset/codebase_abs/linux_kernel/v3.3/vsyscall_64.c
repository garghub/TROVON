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
static bool F_13 ( unsigned long V_48 , T_3 V_49 )
{
if ( ! F_14 ( V_50 , ( void V_51 * ) V_48 , V_49 ) ) {
T_4 V_52 ;
struct V_53 * V_54 = & V_37 -> V_54 ;
V_54 -> V_55 = 6 ;
V_54 -> V_56 = V_48 ;
V_54 -> V_57 = 14 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_58 = V_59 ;
V_52 . V_60 = 0 ;
V_52 . V_61 = V_62 ;
V_52 . V_63 = ( void V_51 * ) V_48 ;
F_15 ( V_59 , & V_52 , V_37 ) ;
return false ;
} else {
return true ;
}
}
bool F_16 ( struct V_28 * V_29 , unsigned long V_64 )
{
struct V_34 * V_35 ;
unsigned long V_65 ;
int V_66 ;
int V_67 ;
long V_68 ;
F_17 ( V_64 != V_29 -> V_39 ) ;
if ( V_2 == V_5 ) {
F_7 ( V_69 , V_29 ,
L_5 ) ;
return false ;
}
V_66 = F_12 ( V_64 ) ;
F_18 ( V_66 ) ;
if ( V_66 < 0 ) {
F_7 ( V_70 , V_29 ,
L_6 ) ;
goto V_71;
}
if ( F_19 ( V_65 , ( unsigned long V_51 * ) V_29 -> V_41 ) != 0 ) {
F_7 ( V_70 , V_29 ,
L_7 ) ;
goto V_71;
}
V_35 = V_37 ;
if ( F_20 ( & V_35 -> V_72 ) )
F_21 ( V_73 ) ;
V_67 = F_22 () -> V_74 ;
F_22 () -> V_74 = 1 ;
V_68 = - V_75 ;
switch ( V_66 ) {
case 0 :
if ( ! F_13 ( V_29 -> V_44 , sizeof( struct V_76 ) ) ||
! F_13 ( V_29 -> V_43 , sizeof( struct V_77 ) ) )
break;
V_68 = F_23 (
(struct V_76 V_51 * ) V_29 -> V_44 ,
(struct V_77 V_51 * ) V_29 -> V_43 ) ;
break;
case 1 :
if ( ! F_13 ( V_29 -> V_44 , sizeof( V_78 ) ) )
break;
V_68 = F_24 ( ( V_78 V_51 * ) V_29 -> V_44 ) ;
break;
case 2 :
if ( ! F_13 ( V_29 -> V_44 , sizeof( unsigned ) ) ||
! F_13 ( V_29 -> V_43 , sizeof( unsigned ) ) )
break;
V_68 = F_25 ( ( unsigned V_51 * ) V_29 -> V_44 ,
( unsigned V_51 * ) V_29 -> V_43 ,
0 ) ;
break;
}
F_22 () -> V_74 = V_67 ;
if ( V_68 == - V_75 ) {
F_7 ( V_69 , V_29 ,
L_8 ) ;
if ( F_17 ( ! F_26 ( & V_35 -> V_79 . signal , V_80 ) &&
! F_26 ( & V_35 -> V_79 . signal , V_59 ) ) )
goto V_71;
return true ;
}
V_29 -> V_42 = V_68 ;
V_29 -> V_39 = V_65 ;
V_29 -> V_41 += 8 ;
return true ;
V_71:
F_27 ( V_59 , V_37 ) ;
return true ;
}
static void T_5 F_28 ( int V_81 )
{
unsigned long V_82 ;
unsigned long V_83 = 0 ;
#ifdef F_29
V_83 = F_30 ( V_81 ) ;
#endif
if ( F_31 ( & F_32 ( V_81 ) , V_84 ) )
F_33 ( ( V_83 << 12 ) | V_81 ) ;
V_82 = 0x0f40000000000ULL ;
V_82 |= V_81 ;
V_82 |= ( V_83 & 0xf ) << 12 ;
V_82 |= ( V_83 >> 4 ) << 48 ;
F_34 ( F_35 ( V_81 ) , V_85 , & V_82 , V_86 ) ;
}
static void T_5 F_36 ( void * V_87 )
{
F_28 ( F_37 () ) ;
}
static int T_5
F_38 ( struct V_88 * V_89 , unsigned long V_90 , void * V_87 )
{
long V_81 = ( long ) V_87 ;
if ( V_90 == V_91 || V_90 == V_92 )
F_39 ( V_81 , F_36 , NULL , 1 ) ;
return V_93 ;
}
void T_1 F_40 ( void )
{
extern char V_94 ;
unsigned long V_95 = F_41 ( & V_94 ) ;
extern char V_96 ;
unsigned long V_97 = F_41 ( & V_96 ) ;
F_42 ( V_98 , V_95 ,
V_2 == V_4
? V_99
: V_100 ) ;
F_43 ( ( unsigned long ) F_44 ( V_98 ) !=
( unsigned long ) V_47 ) ;
F_42 ( V_101 , V_97 , V_100 ) ;
F_43 ( ( unsigned long ) F_44 ( V_101 ) !=
( unsigned long ) V_102 ) ;
}
static int T_1 F_45 ( void )
{
F_46 ( F_47 ( 0 ) != F_44 ( V_98 ) ) ;
F_48 ( F_36 , NULL , 1 ) ;
F_49 ( F_38 , 30 ) ;
return 0 ;
}
