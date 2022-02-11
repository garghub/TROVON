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
static int F_14 ( struct V_36 * V_37 , int V_50 )
{
if ( ! F_15 ( & V_37 -> V_51 ) )
return 0 ;
F_16 ( V_37 ) -> V_52 = V_50 ;
F_16 ( V_37 ) -> V_44 = V_50 ;
return F_17 ( V_50 ) ;
}
static bool F_18 ( unsigned long V_53 , T_3 V_54 )
{
if ( ! F_19 ( V_55 , ( void V_56 * ) V_53 , V_54 ) ) {
T_4 V_57 ;
struct V_58 * V_59 = & V_39 -> V_59 ;
V_59 -> V_60 = 6 ;
V_59 -> V_61 = V_53 ;
V_59 -> V_62 = V_63 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_64 = V_65 ;
V_57 . V_66 = 0 ;
V_57 . V_67 = V_68 ;
V_57 . V_69 = ( void V_56 * ) V_53 ;
F_20 ( V_65 , & V_57 , V_39 ) ;
return false ;
} else {
return true ;
}
}
bool F_21 ( struct V_30 * V_31 , unsigned long V_70 )
{
struct V_36 * V_37 ;
unsigned long V_71 ;
int V_72 ;
int V_73 ;
long V_74 ;
int V_75 ;
F_22 ( V_70 != V_31 -> V_41 ) ;
if ( V_2 == V_5 ) {
F_8 ( V_76 , V_31 ,
L_5 ) ;
return false ;
}
V_72 = F_13 ( V_70 ) ;
F_23 ( V_72 ) ;
if ( V_72 < 0 ) {
F_8 ( V_77 , V_31 ,
L_6 ) ;
goto V_78;
}
if ( F_24 ( V_71 , ( unsigned long V_56 * ) V_31 -> V_43 ) != 0 ) {
F_8 ( V_77 , V_31 ,
L_7 ) ;
goto V_78;
}
V_37 = V_39 ;
V_73 = F_25 () -> V_79 ;
F_25 () -> V_79 = 1 ;
V_74 = - V_80 ;
V_75 = 0 ;
switch ( V_72 ) {
case 0 :
V_75 = F_14 ( V_37 , V_81 ) ;
if ( V_75 )
break;
if ( ! F_18 ( V_31 -> V_46 , sizeof( struct V_82 ) ) ||
! F_18 ( V_31 -> V_45 , sizeof( struct V_83 ) ) )
break;
V_74 = F_26 (
(struct V_82 V_56 * ) V_31 -> V_46 ,
(struct V_83 V_56 * ) V_31 -> V_45 ) ;
break;
case 1 :
V_75 = F_14 ( V_37 , V_84 ) ;
if ( V_75 )
break;
if ( ! F_18 ( V_31 -> V_46 , sizeof( V_85 ) ) )
break;
V_74 = F_27 ( ( V_85 V_56 * ) V_31 -> V_46 ) ;
break;
case 2 :
V_75 = F_14 ( V_37 , V_86 ) ;
if ( V_75 )
break;
if ( ! F_18 ( V_31 -> V_46 , sizeof( unsigned ) ) ||
! F_18 ( V_31 -> V_45 , sizeof( unsigned ) ) )
break;
V_74 = F_28 ( ( unsigned V_56 * ) V_31 -> V_46 ,
( unsigned V_56 * ) V_31 -> V_45 ,
NULL ) ;
break;
}
F_25 () -> V_79 = V_73 ;
if ( V_75 ) {
if ( ( long ) V_31 -> V_44 <= 0L )
goto V_87;
goto V_88;
}
if ( V_74 == - V_80 ) {
F_8 ( V_76 , V_31 ,
L_8 ) ;
if ( F_22 ( ! F_29 ( & V_37 -> V_89 . signal , V_90 ) &&
! F_29 ( & V_37 -> V_89 . signal , V_65 ) ) )
goto V_78;
return true ;
}
V_31 -> V_44 = V_74 ;
V_87:
V_31 -> V_41 = V_71 ;
V_31 -> V_43 += 8 ;
V_88:
return true ;
V_78:
F_30 ( V_65 , V_39 ) ;
return true ;
}
static void T_5 F_31 ( int V_91 )
{
unsigned long V_92 ;
unsigned long V_93 = 0 ;
#ifdef F_32
V_93 = F_33 ( V_91 ) ;
#endif
if ( F_34 ( & F_35 ( V_91 ) , V_94 ) )
F_36 ( ( V_93 << 12 ) | V_91 ) ;
V_92 = 0x0f40000000000ULL ;
V_92 |= V_91 ;
V_92 |= ( V_93 & 0xf ) << 12 ;
V_92 |= ( V_93 >> 4 ) << 48 ;
F_37 ( F_38 ( V_91 ) , V_95 , & V_92 , V_96 ) ;
}
static void T_5 F_39 ( void * V_97 )
{
F_31 ( F_40 () ) ;
}
static int T_5
F_41 ( struct V_98 * V_99 , unsigned long V_100 , void * V_97 )
{
long V_91 = ( long ) V_97 ;
if ( V_100 == V_101 || V_100 == V_102 )
F_42 ( V_91 , F_39 , NULL , 1 ) ;
return V_103 ;
}
void T_1 F_43 ( void )
{
extern char V_104 ;
unsigned long V_105 = F_44 ( & V_104 ) ;
extern char V_106 ;
unsigned long V_107 = F_44 ( & V_106 ) ;
F_45 ( V_108 , V_105 ,
V_2 == V_4
? V_109
: V_110 ) ;
F_46 ( ( unsigned long ) F_47 ( V_108 ) !=
( unsigned long ) V_49 ) ;
F_45 ( V_111 , V_107 , V_110 ) ;
F_46 ( ( unsigned long ) F_47 ( V_111 ) !=
( unsigned long ) V_112 ) ;
}
static int T_1 F_48 ( void )
{
F_49 ( F_50 ( 0 ) != F_47 ( V_108 ) ) ;
F_51 ( F_39 , NULL , 1 ) ;
F_52 ( F_41 , 30 ) ;
return 0 ;
}
