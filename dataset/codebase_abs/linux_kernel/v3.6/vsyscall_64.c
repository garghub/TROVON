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
if ( ! V_33 )
return;
F_9 ( L_4 ,
V_29 , V_34 -> V_35 , F_10 ( V_34 ) ,
V_32 , V_31 -> V_36 , V_31 -> V_37 ,
V_31 -> V_38 , V_31 -> V_39 , V_31 -> V_40 , V_31 -> V_41 ) ;
}
static int F_11 ( unsigned long V_42 )
{
int V_43 ;
if ( ( V_42 & ~ 0xC00UL ) != V_44 )
return - V_6 ;
V_43 = ( V_42 & 0xC00UL ) >> 10 ;
if ( V_43 >= 3 )
return - V_6 ;
return V_43 ;
}
static int F_12 ( struct V_45 * V_46 , int V_47 )
{
if ( ! F_13 ( & V_46 -> V_48 ) )
return 0 ;
F_14 ( V_46 ) -> V_49 = V_47 ;
F_14 ( V_46 ) -> V_39 = V_47 ;
return F_15 ( V_47 ) ;
}
static bool F_16 ( unsigned long V_50 , T_3 V_51 )
{
if ( ! F_17 ( V_52 , ( void V_53 * ) V_50 , V_51 ) ) {
T_4 V_54 ;
struct V_55 * V_56 = & V_34 -> V_56 ;
V_56 -> V_57 = 6 ;
V_56 -> V_58 = V_50 ;
V_56 -> V_59 = V_60 ;
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
V_54 . V_61 = V_62 ;
V_54 . V_63 = 0 ;
V_54 . V_64 = V_65 ;
V_54 . V_66 = ( void V_53 * ) V_50 ;
F_18 ( V_62 , & V_54 , V_34 ) ;
return false ;
} else {
return true ;
}
}
bool F_19 ( struct V_30 * V_31 , unsigned long V_67 )
{
struct V_45 * V_46 ;
unsigned long V_68 ;
int V_69 ;
int V_70 ;
long V_71 ;
int V_72 ;
F_20 ( V_67 != V_31 -> V_36 ) ;
if ( V_2 == V_5 ) {
F_8 ( V_73 , V_31 ,
L_5 ) ;
return false ;
}
V_69 = F_11 ( V_67 ) ;
F_21 ( V_69 ) ;
if ( V_69 < 0 ) {
F_8 ( V_74 , V_31 ,
L_6 ) ;
goto V_75;
}
if ( F_22 ( V_68 , ( unsigned long V_53 * ) V_31 -> V_38 ) != 0 ) {
F_8 ( V_74 , V_31 ,
L_7 ) ;
goto V_75;
}
V_46 = V_34 ;
V_70 = F_23 () -> V_76 ;
F_23 () -> V_76 = 1 ;
V_71 = - V_77 ;
V_72 = 0 ;
switch ( V_69 ) {
case 0 :
V_72 = F_12 ( V_46 , V_78 ) ;
if ( V_72 )
break;
if ( ! F_16 ( V_31 -> V_41 , sizeof( struct V_79 ) ) ||
! F_16 ( V_31 -> V_40 , sizeof( struct V_80 ) ) )
break;
V_71 = F_24 (
(struct V_79 V_53 * ) V_31 -> V_41 ,
(struct V_80 V_53 * ) V_31 -> V_40 ) ;
break;
case 1 :
V_72 = F_12 ( V_46 , V_81 ) ;
if ( V_72 )
break;
if ( ! F_16 ( V_31 -> V_41 , sizeof( V_82 ) ) )
break;
V_71 = F_25 ( ( V_82 V_53 * ) V_31 -> V_41 ) ;
break;
case 2 :
V_72 = F_12 ( V_46 , V_83 ) ;
if ( V_72 )
break;
if ( ! F_16 ( V_31 -> V_41 , sizeof( unsigned ) ) ||
! F_16 ( V_31 -> V_40 , sizeof( unsigned ) ) )
break;
V_71 = F_26 ( ( unsigned V_53 * ) V_31 -> V_41 ,
( unsigned V_53 * ) V_31 -> V_40 ,
NULL ) ;
break;
}
F_23 () -> V_76 = V_70 ;
if ( V_72 ) {
if ( ( long ) V_31 -> V_39 <= 0L )
goto V_84;
goto V_85;
}
if ( V_71 == - V_77 ) {
F_8 ( V_73 , V_31 ,
L_8 ) ;
if ( F_20 ( ! F_27 ( & V_46 -> V_86 . signal , V_87 ) &&
! F_27 ( & V_46 -> V_86 . signal , V_62 ) ) )
goto V_75;
return true ;
}
V_31 -> V_39 = V_71 ;
V_84:
V_31 -> V_36 = V_68 ;
V_31 -> V_38 += 8 ;
V_85:
return true ;
V_75:
F_28 ( V_62 , V_34 ) ;
return true ;
}
static void T_5 F_29 ( int V_88 )
{
unsigned long V_89 ;
unsigned long V_90 = 0 ;
#ifdef F_30
V_90 = F_31 ( V_88 ) ;
#endif
if ( F_32 ( & F_33 ( V_88 ) , V_91 ) )
F_34 ( ( V_90 << 12 ) | V_88 ) ;
V_89 = 0x0f40000000000ULL ;
V_89 |= V_88 ;
V_89 |= ( V_90 & 0xf ) << 12 ;
V_89 |= ( V_90 >> 4 ) << 48 ;
F_35 ( F_36 ( V_88 ) , V_92 , & V_89 , V_93 ) ;
}
static void T_5 F_37 ( void * V_94 )
{
F_29 ( F_38 () ) ;
}
static int T_5
F_39 ( struct V_95 * V_96 , unsigned long V_97 , void * V_94 )
{
long V_88 = ( long ) V_94 ;
if ( V_97 == V_98 || V_97 == V_99 )
F_40 ( V_88 , F_37 , NULL , 1 ) ;
return V_100 ;
}
void T_1 F_41 ( void )
{
extern char V_101 ;
unsigned long V_102 = F_42 ( & V_101 ) ;
extern char V_103 ;
unsigned long V_104 = F_42 ( & V_103 ) ;
F_43 ( V_105 , V_102 ,
V_2 == V_4
? V_106
: V_107 ) ;
F_44 ( ( unsigned long ) F_45 ( V_105 ) !=
( unsigned long ) V_44 ) ;
F_43 ( V_108 , V_104 , V_107 ) ;
F_44 ( ( unsigned long ) F_45 ( V_108 ) !=
( unsigned long ) V_109 ) ;
}
static int T_1 F_46 ( void )
{
F_47 ( F_48 ( 0 ) != F_45 ( V_105 ) ) ;
F_49 ( F_37 , NULL , 1 ) ;
F_50 ( F_39 , 30 ) ;
return 0 ;
}
