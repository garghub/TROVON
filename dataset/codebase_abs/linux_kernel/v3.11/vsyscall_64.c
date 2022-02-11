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
static bool F_11 ( unsigned long V_48 , T_2 V_49 )
{
if ( ! F_12 ( V_50 , ( void V_51 * ) V_48 , V_49 ) ) {
T_3 V_52 ;
struct V_53 * V_54 = & V_37 -> V_54 ;
V_54 -> V_55 = 6 ;
V_54 -> V_56 = V_48 ;
V_54 -> V_57 = V_58 ;
memset ( & V_52 , 0 , sizeof( V_52 ) ) ;
V_52 . V_59 = V_60 ;
V_52 . V_61 = 0 ;
V_52 . V_62 = V_63 ;
V_52 . V_64 = ( void V_51 * ) V_48 ;
F_13 ( V_60 , & V_52 , V_37 ) ;
return false ;
} else {
return true ;
}
}
bool F_14 ( struct V_33 * V_34 , unsigned long V_65 )
{
struct V_66 * V_67 ;
unsigned long V_68 ;
int V_69 , V_70 , V_71 ;
int V_72 ;
long V_73 ;
F_15 ( V_65 != V_34 -> V_39 ) ;
if ( V_2 == V_5 ) {
F_7 ( V_74 , V_34 ,
L_5 ) ;
return false ;
}
V_69 = F_10 ( V_65 ) ;
F_16 ( V_69 ) ;
if ( V_69 < 0 ) {
F_7 ( V_75 , V_34 ,
L_6 ) ;
goto V_76;
}
if ( F_17 ( V_68 , ( unsigned long V_51 * ) V_34 -> V_41 ) != 0 ) {
F_7 ( V_75 , V_34 ,
L_7 ) ;
goto V_76;
}
V_67 = V_37 ;
switch ( V_69 ) {
case 0 :
if ( ! F_11 ( V_34 -> V_44 , sizeof( struct V_77 ) ) ||
! F_11 ( V_34 -> V_43 , sizeof( struct V_78 ) ) ) {
V_73 = - V_79 ;
goto V_80;
}
V_70 = V_81 ;
break;
case 1 :
if ( ! F_11 ( V_34 -> V_44 , sizeof( V_82 ) ) ) {
V_73 = - V_79 ;
goto V_80;
}
V_70 = V_83 ;
break;
case 2 :
if ( ! F_11 ( V_34 -> V_44 , sizeof( unsigned ) ) ||
! F_11 ( V_34 -> V_43 , sizeof( unsigned ) ) ) {
V_73 = - V_79 ;
goto V_80;
}
V_70 = V_84 ;
break;
}
V_34 -> V_85 = V_70 ;
V_34 -> V_42 = - V_86 ;
V_71 = F_18 ( V_70 ) ;
if ( ( ! V_71 && V_34 -> V_85 != V_70 ) || V_34 -> V_39 != V_65 ) {
F_7 ( V_87 , V_34 ,
L_8 ) ;
F_19 ( V_88 ) ;
}
if ( V_71 )
goto V_89;
V_72 = F_20 () -> V_90 ;
F_20 () -> V_90 = 1 ;
V_73 = - V_79 ;
switch ( V_69 ) {
case 0 :
V_73 = F_21 (
(struct V_77 V_51 * ) V_34 -> V_44 ,
(struct V_78 V_51 * ) V_34 -> V_43 ) ;
break;
case 1 :
V_73 = F_22 ( ( V_82 V_51 * ) V_34 -> V_44 ) ;
break;
case 2 :
V_73 = F_23 ( ( unsigned V_51 * ) V_34 -> V_44 ,
( unsigned V_51 * ) V_34 -> V_43 ,
NULL ) ;
break;
}
F_20 () -> V_90 = V_72 ;
V_80:
if ( V_73 == - V_79 ) {
F_7 ( V_74 , V_34 ,
L_9 ) ;
if ( F_15 ( ! F_24 ( & V_67 -> V_91 . signal , V_92 ) &&
! F_24 ( & V_67 -> V_91 . signal , V_60 ) ) )
goto V_76;
return true ;
}
V_34 -> V_42 = V_73 ;
V_89:
V_34 -> V_39 = V_68 ;
V_34 -> V_41 += 8 ;
return true ;
V_76:
F_25 ( V_60 , V_37 ) ;
return true ;
}
static void F_26 ( int V_93 )
{
unsigned long V_94 ;
unsigned long V_95 = 0 ;
#ifdef F_27
V_95 = F_28 ( V_93 ) ;
#endif
if ( F_29 ( & F_30 ( V_93 ) , V_96 ) )
F_31 ( ( V_95 << 12 ) | V_93 ) ;
V_94 = 0x0f40000000000ULL ;
V_94 |= V_93 ;
V_94 |= ( V_95 & 0xf ) << 12 ;
V_94 |= ( V_95 >> 4 ) << 48 ;
F_32 ( F_33 ( V_93 ) , V_97 , & V_94 , V_98 ) ;
}
static void F_34 ( void * V_99 )
{
F_26 ( F_35 () ) ;
}
static int
F_36 ( struct V_100 * V_101 , unsigned long V_102 , void * V_99 )
{
long V_93 = ( long ) V_99 ;
if ( V_102 == V_103 || V_102 == V_104 )
F_37 ( V_93 , F_34 , NULL , 1 ) ;
return V_105 ;
}
void T_1 F_38 ( void )
{
extern char V_106 ;
unsigned long V_107 = F_39 ( & V_106 ) ;
extern char V_108 ;
unsigned long V_109 = F_39 ( & V_108 ) ;
F_40 ( V_110 , V_107 ,
V_2 == V_4
? V_111
: V_112 ) ;
F_41 ( ( unsigned long ) F_42 ( V_110 ) !=
( unsigned long ) V_47 ) ;
F_40 ( V_113 , V_109 , V_112 ) ;
F_41 ( ( unsigned long ) F_42 ( V_113 ) !=
( unsigned long ) V_114 ) ;
}
static int T_1 F_43 ( void )
{
F_44 ( F_45 ( 0 ) != F_42 ( V_110 ) ) ;
F_46 ( F_34 , NULL , 1 ) ;
F_47 ( F_36 , 30 ) ;
return 0 ;
}
