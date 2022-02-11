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
void F_3 ( struct V_9 * V_10 )
{
struct V_7 * V_11 = & V_7 ;
F_4 ( & V_11 -> V_12 ) ;
V_11 -> clock . V_13 = V_10 -> clock -> V_14 . V_13 ;
V_11 -> clock . V_15 = V_10 -> clock -> V_15 ;
V_11 -> clock . V_16 = V_10 -> clock -> V_16 ;
V_11 -> clock . V_17 = V_10 -> V_17 ;
V_11 -> clock . V_18 = V_10 -> V_18 ;
V_11 -> V_19 = V_10 -> V_20 ;
V_11 -> V_21 = V_10 -> V_22 ;
V_11 -> V_23 = V_10 -> V_20
+ V_10 -> V_24 . V_25 ;
V_11 -> V_26 = V_10 -> V_22
+ ( V_10 -> V_24 . V_27
<< V_10 -> V_18 ) ;
while ( V_11 -> V_26 >=
( ( ( V_28 ) V_29 ) << V_10 -> V_18 ) ) {
V_11 -> V_26 -=
( ( V_28 ) V_29 ) << V_10 -> V_18 ;
V_11 -> V_23 ++ ;
}
V_11 -> V_30 . V_25 = V_10 -> V_20 ;
V_11 -> V_30 . V_27 = ( long ) ( V_10 -> V_22 >> V_10 -> V_18 ) ;
V_11 -> V_31 = F_5 ( V_11 -> V_30 ,
V_10 -> V_24 ) ;
F_6 ( & V_11 -> V_12 ) ;
}
static void F_7 ( const char * V_32 , struct V_33 * V_34 ,
const char * V_35 )
{
if ( ! V_36 )
return;
F_8 ( L_4 ,
V_32 , V_37 -> V_38 , F_9 ( V_37 ) ,
V_35 , V_34 -> V_39 , V_34 -> V_40 ,
V_34 -> V_41 , V_34 -> V_42 , V_34 -> V_43 , V_34 -> V_44 ) ;
}
static int F_10 ( unsigned long V_45 )
{
int V_46 ;
if ( ( V_45 & ~ 0xC00UL ) != V_47 )
return - V_6 ;
V_46 = ( V_45 & 0xC00UL ) >> 10 ;
if ( V_46 >= 3 )
return - V_6 ;
return V_46 ;
}
static int F_11 ( struct V_48 * V_49 , int V_50 )
{
if ( ! F_12 ( & V_49 -> V_51 ) )
return 0 ;
F_13 ( V_49 ) -> V_52 = V_50 ;
F_13 ( V_49 ) -> V_42 = V_50 ;
return F_14 ( V_50 ) ;
}
static bool F_15 ( unsigned long V_53 , T_2 V_54 )
{
if ( ! F_16 ( V_55 , ( void V_56 * ) V_53 , V_54 ) ) {
T_3 V_57 ;
struct V_58 * V_59 = & V_37 -> V_59 ;
V_59 -> V_60 = 6 ;
V_59 -> V_61 = V_53 ;
V_59 -> V_62 = V_63 ;
memset ( & V_57 , 0 , sizeof( V_57 ) ) ;
V_57 . V_64 = V_65 ;
V_57 . V_66 = 0 ;
V_57 . V_67 = V_68 ;
V_57 . V_69 = ( void V_56 * ) V_53 ;
F_17 ( V_65 , & V_57 , V_37 ) ;
return false ;
} else {
return true ;
}
}
bool F_18 ( struct V_33 * V_34 , unsigned long V_70 )
{
struct V_48 * V_49 ;
unsigned long V_71 ;
int V_72 ;
int V_73 ;
long V_74 ;
int V_75 ;
F_19 ( V_70 != V_34 -> V_39 ) ;
if ( V_2 == V_5 ) {
F_7 ( V_76 , V_34 ,
L_5 ) ;
return false ;
}
V_72 = F_10 ( V_70 ) ;
F_20 ( V_72 ) ;
if ( V_72 < 0 ) {
F_7 ( V_77 , V_34 ,
L_6 ) ;
goto V_78;
}
if ( F_21 ( V_71 , ( unsigned long V_56 * ) V_34 -> V_41 ) != 0 ) {
F_7 ( V_77 , V_34 ,
L_7 ) ;
goto V_78;
}
V_49 = V_37 ;
V_73 = F_22 () -> V_79 ;
F_22 () -> V_79 = 1 ;
V_74 = - V_80 ;
V_75 = 0 ;
switch ( V_72 ) {
case 0 :
V_75 = F_11 ( V_49 , V_81 ) ;
if ( V_75 )
break;
if ( ! F_15 ( V_34 -> V_44 , sizeof( struct V_82 ) ) ||
! F_15 ( V_34 -> V_43 , sizeof( struct V_83 ) ) )
break;
V_74 = F_23 (
(struct V_82 V_56 * ) V_34 -> V_44 ,
(struct V_83 V_56 * ) V_34 -> V_43 ) ;
break;
case 1 :
V_75 = F_11 ( V_49 , V_84 ) ;
if ( V_75 )
break;
if ( ! F_15 ( V_34 -> V_44 , sizeof( V_85 ) ) )
break;
V_74 = F_24 ( ( V_85 V_56 * ) V_34 -> V_44 ) ;
break;
case 2 :
V_75 = F_11 ( V_49 , V_86 ) ;
if ( V_75 )
break;
if ( ! F_15 ( V_34 -> V_44 , sizeof( unsigned ) ) ||
! F_15 ( V_34 -> V_43 , sizeof( unsigned ) ) )
break;
V_74 = F_25 ( ( unsigned V_56 * ) V_34 -> V_44 ,
( unsigned V_56 * ) V_34 -> V_43 ,
NULL ) ;
break;
}
F_22 () -> V_79 = V_73 ;
if ( V_75 ) {
if ( ( long ) V_34 -> V_42 <= 0L )
goto V_87;
goto V_88;
}
if ( V_74 == - V_80 ) {
F_7 ( V_76 , V_34 ,
L_8 ) ;
if ( F_19 ( ! F_26 ( & V_49 -> V_89 . signal , V_90 ) &&
! F_26 ( & V_49 -> V_89 . signal , V_65 ) ) )
goto V_78;
return true ;
}
V_34 -> V_42 = V_74 ;
V_87:
V_34 -> V_39 = V_71 ;
V_34 -> V_41 += 8 ;
V_88:
return true ;
V_78:
F_27 ( V_65 , V_37 ) ;
return true ;
}
static void T_4 F_28 ( int V_91 )
{
unsigned long V_92 ;
unsigned long V_93 = 0 ;
#ifdef F_29
V_93 = F_30 ( V_91 ) ;
#endif
if ( F_31 ( & F_32 ( V_91 ) , V_94 ) )
F_33 ( ( V_93 << 12 ) | V_91 ) ;
V_92 = 0x0f40000000000ULL ;
V_92 |= V_91 ;
V_92 |= ( V_93 & 0xf ) << 12 ;
V_92 |= ( V_93 >> 4 ) << 48 ;
F_34 ( F_35 ( V_91 ) , V_95 , & V_92 , V_96 ) ;
}
static void T_4 F_36 ( void * V_97 )
{
F_28 ( F_37 () ) ;
}
static int T_4
F_38 ( struct V_98 * V_99 , unsigned long V_100 , void * V_97 )
{
long V_91 = ( long ) V_97 ;
if ( V_100 == V_101 || V_100 == V_102 )
F_39 ( V_91 , F_36 , NULL , 1 ) ;
return V_103 ;
}
void T_1 F_40 ( void )
{
extern char V_104 ;
unsigned long V_105 = F_41 ( & V_104 ) ;
extern char V_106 ;
unsigned long V_107 = F_41 ( & V_106 ) ;
F_42 ( V_108 , V_105 ,
V_2 == V_4
? V_109
: V_110 ) ;
F_43 ( ( unsigned long ) F_44 ( V_108 ) !=
( unsigned long ) V_47 ) ;
F_42 ( V_111 , V_107 , V_110 ) ;
F_43 ( ( unsigned long ) F_44 ( V_111 ) !=
( unsigned long ) V_112 ) ;
}
static int T_1 F_45 ( void )
{
F_46 ( F_47 ( 0 ) != F_44 ( V_108 ) ) ;
F_48 ( F_36 , NULL , 1 ) ;
F_49 ( F_38 , 30 ) ;
return 0 ;
}
