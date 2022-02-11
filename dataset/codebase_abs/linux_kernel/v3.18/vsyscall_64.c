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
static void F_2 ( const char * V_7 , struct V_8 * V_9 ,
const char * V_10 )
{
if ( ! V_11 )
return;
F_3 ( L_4 ,
V_7 , V_12 -> V_13 , F_4 ( V_12 ) ,
V_10 , V_9 -> V_14 , V_9 -> V_15 ,
V_9 -> V_16 , V_9 -> V_17 , V_9 -> V_18 , V_9 -> V_19 ) ;
}
static int F_5 ( unsigned long V_20 )
{
int V_21 ;
if ( ( V_20 & ~ 0xC00UL ) != V_22 )
return - V_6 ;
V_21 = ( V_20 & 0xC00UL ) >> 10 ;
if ( V_21 >= 3 )
return - V_6 ;
return V_21 ;
}
static bool F_6 ( unsigned long V_23 , T_2 V_24 )
{
if ( ! F_7 ( V_25 , ( void V_26 * ) V_23 , V_24 ) ) {
T_3 V_27 ;
struct V_28 * V_29 = & V_12 -> V_29 ;
V_29 -> V_30 = 6 ;
V_29 -> V_31 = V_23 ;
V_29 -> V_32 = V_33 ;
memset ( & V_27 , 0 , sizeof( V_27 ) ) ;
V_27 . V_34 = V_35 ;
V_27 . V_36 = 0 ;
V_27 . V_37 = V_38 ;
V_27 . V_39 = ( void V_26 * ) V_23 ;
F_8 ( V_35 , & V_27 , V_12 ) ;
return false ;
} else {
return true ;
}
}
bool F_9 ( struct V_8 * V_9 , unsigned long V_40 )
{
struct V_41 * V_42 ;
unsigned long V_43 ;
int V_44 , V_45 , V_46 ;
int V_47 ;
long V_48 ;
F_10 ( V_40 != V_9 -> V_14 ) ;
if ( V_2 == V_5 ) {
F_2 ( V_49 , V_9 ,
L_5 ) ;
return false ;
}
V_44 = F_5 ( V_40 ) ;
F_11 ( V_44 ) ;
if ( V_44 < 0 ) {
F_2 ( V_50 , V_9 ,
L_6 ) ;
goto V_51;
}
if ( F_12 ( V_43 , ( unsigned long V_26 * ) V_9 -> V_16 ) != 0 ) {
F_2 ( V_50 , V_9 ,
L_7 ) ;
goto V_51;
}
V_42 = V_12 ;
switch ( V_44 ) {
case 0 :
if ( ! F_6 ( V_9 -> V_19 , sizeof( struct V_52 ) ) ||
! F_6 ( V_9 -> V_18 , sizeof( struct V_53 ) ) ) {
V_48 = - V_54 ;
goto V_55;
}
V_45 = V_56 ;
break;
case 1 :
if ( ! F_6 ( V_9 -> V_19 , sizeof( V_57 ) ) ) {
V_48 = - V_54 ;
goto V_55;
}
V_45 = V_58 ;
break;
case 2 :
if ( ! F_6 ( V_9 -> V_19 , sizeof( unsigned ) ) ||
! F_6 ( V_9 -> V_18 , sizeof( unsigned ) ) ) {
V_48 = - V_54 ;
goto V_55;
}
V_45 = V_59 ;
break;
}
V_9 -> V_60 = V_45 ;
V_9 -> V_17 = - V_61 ;
V_46 = F_13 () ;
if ( ( ! V_46 && V_9 -> V_60 != V_45 ) || V_9 -> V_14 != V_40 ) {
F_2 ( V_62 , V_9 ,
L_8 ) ;
F_14 ( V_63 ) ;
}
if ( V_46 )
goto V_64;
V_47 = F_15 () -> V_65 ;
F_15 () -> V_65 = 1 ;
V_48 = - V_54 ;
switch ( V_44 ) {
case 0 :
V_48 = F_16 (
(struct V_52 V_26 * ) V_9 -> V_19 ,
(struct V_53 V_26 * ) V_9 -> V_18 ) ;
break;
case 1 :
V_48 = F_17 ( ( V_57 V_26 * ) V_9 -> V_19 ) ;
break;
case 2 :
V_48 = F_18 ( ( unsigned V_26 * ) V_9 -> V_19 ,
( unsigned V_26 * ) V_9 -> V_18 ,
NULL ) ;
break;
}
F_15 () -> V_65 = V_47 ;
V_55:
if ( V_48 == - V_54 ) {
F_2 ( V_49 , V_9 ,
L_9 ) ;
if ( F_10 ( ! F_19 ( & V_42 -> V_66 . signal , V_67 ) &&
! F_19 ( & V_42 -> V_66 . signal , V_35 ) ) )
goto V_51;
return true ;
}
V_9 -> V_17 = V_48 ;
V_64:
V_9 -> V_14 = V_43 ;
V_9 -> V_16 += 8 ;
return true ;
V_51:
F_20 ( V_35 , V_12 ) ;
return true ;
}
static void F_21 ( int V_68 )
{
unsigned long V_69 ;
unsigned long V_70 = 0 ;
#ifdef F_22
V_70 = F_23 ( V_68 ) ;
#endif
if ( F_24 ( & F_25 ( V_68 ) , V_71 ) )
F_26 ( ( V_70 << 12 ) | V_68 ) ;
V_69 = 0x0f40000000000ULL ;
V_69 |= V_68 ;
V_69 |= ( V_70 & 0xf ) << 12 ;
V_69 |= ( V_70 >> 4 ) << 48 ;
F_27 ( F_28 ( V_68 ) , V_72 , & V_69 , V_73 ) ;
}
static void F_29 ( void * V_74 )
{
F_21 ( F_30 () ) ;
}
static int
F_31 ( struct V_75 * V_76 , unsigned long V_77 , void * V_74 )
{
long V_68 = ( long ) V_74 ;
if ( V_77 == V_78 || V_77 == V_79 )
F_32 ( V_68 , F_29 , NULL , 1 ) ;
return V_80 ;
}
void T_1 F_33 ( void )
{
extern char V_81 ;
unsigned long V_82 = F_34 ( & V_81 ) ;
F_35 ( V_83 , V_82 ,
V_2 == V_4
? V_84
: V_85 ) ;
F_36 ( ( unsigned long ) F_37 ( V_83 ) !=
( unsigned long ) V_22 ) ;
}
static int T_1 F_38 ( void )
{
F_39 () ;
F_40 ( F_29 , NULL , 1 ) ;
F_41 ( F_31 , 30 ) ;
F_42 () ;
return 0 ;
}
