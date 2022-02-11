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
V_7 . V_8 = V_8 ;
}
void F_3 ( struct V_9 * V_10 , struct V_9 * V_11 ,
struct V_12 * clock , T_2 V_13 )
{
struct V_9 V_14 ;
F_4 ( & V_7 . V_15 ) ;
V_7 . clock . V_16 = clock -> V_17 . V_16 ;
V_7 . clock . V_18 = clock -> V_18 ;
V_7 . clock . V_19 = clock -> V_19 ;
V_7 . clock . V_13 = V_13 ;
V_7 . clock . V_20 = clock -> V_20 ;
V_7 . V_21 = V_10 -> V_22 ;
V_7 . V_23 = V_10 -> V_24 ;
V_14 = F_5 ( * V_10 , * V_11 ) ;
V_7 . V_25 = V_14 . V_22 ;
V_7 . V_26 = V_14 . V_24 ;
V_7 . V_27 = F_6 () ;
V_7 . V_28 =
F_5 ( V_7 . V_27 , * V_11 ) ;
F_7 ( & V_7 . V_15 ) ;
}
static void F_8 ( const char * V_29 , struct V_30 * V_31 ,
const char * V_32 )
{
static F_9 ( V_33 , V_34 , V_35 ) ;
struct V_36 * V_37 ;
if ( ! V_38 || ! F_10 ( & V_33 ) )
return;
V_37 = V_39 ;
F_11 ( L_4 ,
V_29 , V_37 -> V_40 , F_12 ( V_37 ) ,
V_32 , V_31 -> V_41 , V_31 -> V_42 ,
V_31 -> V_43 , V_31 -> V_44 , V_31 -> V_45 , V_31 -> V_46 ) ;
}
static int F_13 ( unsigned long V_47 )
{
int V_48 ;
if ( ( V_47 & ~ 0xC00UL ) != V_49 )
return - V_6 ;
V_48 = ( V_47 & 0xC00UL ) >> 10 ;
if ( V_48 >= 3 )
return - V_6 ;
return V_48 ;
}
static bool F_14 ( unsigned long V_50 , T_3 V_51 )
{
if ( ! F_15 ( V_52 , ( void V_53 * ) V_50 , V_51 ) ) {
T_4 V_54 ;
struct V_55 * V_56 = & V_39 -> V_56 ;
V_56 -> V_57 = 6 ;
V_56 -> V_58 = V_50 ;
V_56 -> V_59 = V_60 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_61 = V_62 ;
V_54 . V_63 = 0 ;
V_54 . V_64 = V_65 ;
V_54 . V_66 = ( void V_53 * ) V_50 ;
F_16 ( V_62 , & V_54 , V_39 ) ;
return false ;
} else {
return true ;
}
}
bool F_17 ( struct V_30 * V_31 , unsigned long V_67 )
{
struct V_36 * V_37 ;
unsigned long V_68 ;
int V_69 ;
int V_70 ;
long V_71 ;
F_18 ( V_67 != V_31 -> V_41 ) ;
if ( V_2 == V_5 ) {
F_8 ( V_72 , V_31 ,
L_5 ) ;
return false ;
}
V_69 = F_13 ( V_67 ) ;
F_19 ( V_69 ) ;
if ( V_69 < 0 ) {
F_8 ( V_73 , V_31 ,
L_6 ) ;
goto V_74;
}
if ( F_20 ( V_68 , ( unsigned long V_53 * ) V_31 -> V_43 ) != 0 ) {
F_8 ( V_73 , V_31 ,
L_7 ) ;
goto V_74;
}
V_37 = V_39 ;
if ( F_21 ( & V_37 -> V_75 ) )
F_22 ( V_76 ) ;
V_70 = F_23 () -> V_77 ;
F_23 () -> V_77 = 1 ;
V_71 = - V_78 ;
switch ( V_69 ) {
case 0 :
if ( ! F_14 ( V_31 -> V_46 , sizeof( struct V_79 ) ) ||
! F_14 ( V_31 -> V_45 , sizeof( struct V_80 ) ) )
break;
V_71 = F_24 (
(struct V_79 V_53 * ) V_31 -> V_46 ,
(struct V_80 V_53 * ) V_31 -> V_45 ) ;
break;
case 1 :
if ( ! F_14 ( V_31 -> V_46 , sizeof( V_81 ) ) )
break;
V_71 = F_25 ( ( V_81 V_53 * ) V_31 -> V_46 ) ;
break;
case 2 :
if ( ! F_14 ( V_31 -> V_46 , sizeof( unsigned ) ) ||
! F_14 ( V_31 -> V_45 , sizeof( unsigned ) ) )
break;
V_71 = F_26 ( ( unsigned V_53 * ) V_31 -> V_46 ,
( unsigned V_53 * ) V_31 -> V_45 ,
NULL ) ;
break;
}
F_23 () -> V_77 = V_70 ;
if ( V_71 == - V_78 ) {
F_8 ( V_72 , V_31 ,
L_8 ) ;
if ( F_18 ( ! F_27 ( & V_37 -> V_82 . signal , V_83 ) &&
! F_27 ( & V_37 -> V_82 . signal , V_62 ) ) )
goto V_74;
return true ;
}
V_31 -> V_44 = V_71 ;
V_31 -> V_41 = V_68 ;
V_31 -> V_43 += 8 ;
return true ;
V_74:
F_28 ( V_62 , V_39 ) ;
return true ;
}
static void T_5 F_29 ( int V_84 )
{
unsigned long V_85 ;
unsigned long V_86 = 0 ;
#ifdef F_30
V_86 = F_31 ( V_84 ) ;
#endif
if ( F_32 ( & F_33 ( V_84 ) , V_87 ) )
F_34 ( ( V_86 << 12 ) | V_84 ) ;
V_85 = 0x0f40000000000ULL ;
V_85 |= V_84 ;
V_85 |= ( V_86 & 0xf ) << 12 ;
V_85 |= ( V_86 >> 4 ) << 48 ;
F_35 ( F_36 ( V_84 ) , V_88 , & V_85 , V_89 ) ;
}
static void T_5 F_37 ( void * V_90 )
{
F_29 ( F_38 () ) ;
}
static int T_5
F_39 ( struct V_91 * V_92 , unsigned long V_93 , void * V_90 )
{
long V_84 = ( long ) V_90 ;
if ( V_93 == V_94 || V_93 == V_95 )
F_40 ( V_84 , F_37 , NULL , 1 ) ;
return V_96 ;
}
void T_1 F_41 ( void )
{
extern char V_97 ;
unsigned long V_98 = F_42 ( & V_97 ) ;
extern char V_99 ;
unsigned long V_100 = F_42 ( & V_99 ) ;
F_43 ( V_101 , V_98 ,
V_2 == V_4
? V_102
: V_103 ) ;
F_44 ( ( unsigned long ) F_45 ( V_101 ) !=
( unsigned long ) V_49 ) ;
F_43 ( V_104 , V_100 , V_103 ) ;
F_44 ( ( unsigned long ) F_45 ( V_104 ) !=
( unsigned long ) V_105 ) ;
}
static int T_1 F_46 ( void )
{
F_47 ( F_48 ( 0 ) != F_45 ( V_101 ) ) ;
F_49 ( F_37 , NULL , 1 ) ;
F_50 ( F_39 , 30 ) ;
return 0 ;
}
