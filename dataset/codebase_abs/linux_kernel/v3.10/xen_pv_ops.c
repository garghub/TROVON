static void T_1
F_1 ( void )
{
unsigned long V_1 = F_2 ( V_2 ) ;
unsigned int V_3 = ( V_1 & V_4 ) >> V_5 ;
V_6 . V_7 = V_3 ;
}
static void
F_3 ( struct V_8 * V_9 , void * V_10 )
{
V_11 -> V_12 . V_13 = ( V_14 ) V_9 -> V_15 - 16 ;
F_4 ( V_16 ) ;
}
static int
F_5 ( struct V_17 * V_18 , unsigned long V_19 , void * V_20 )
{
F_6 ( F_3 , NULL ) ;
return V_21 ;
}
static void F_7 ( void )
{
F_8 () ;
F_4 ( V_22 ) ;
}
static void T_1
F_9 ( void )
{
F_10 ( V_23
L_1
L_2 ,
V_6 . V_7 ,
V_24 -> V_25 . V_26 ,
V_27 -> V_28 , V_27 -> V_29 ) ;
}
static int T_1
F_11 ( struct V_30 * V_31 )
{
V_31 -> V_32 = ( unsigned long ) F_12 (
( V_24 -> V_25 . V_26 << V_33 ) ) ;
V_31 -> V_34 = V_31 -> V_32 + V_35 ;
return 1 ;
}
static void T_1
F_13 ( void )
{
struct V_36 * V_37 ;
F_14 ( ! F_15 () ) ;
V_37 = V_24 ;
V_27 = F_12 ( V_37 -> V_25 . V_26 << V_33 ) ;
F_16 () ;
F_17 () ;
F_18 ( & V_38 ,
& V_39 ) ;
V_40 = F_7 ;
F_19 () ;
}
static void T_1
F_20 ( char * * V_41 )
{
F_21 ( L_3 , 0 , NULL ) ;
F_21 ( L_4 , 0 , NULL ) ;
F_21 ( L_5 , 0 , NULL ) ;
#if ! F_22 ( V_42 ) || ! F_22 ( V_43 )
V_44 = NULL ;
#endif
}
static int T_1
F_23 ( void )
{
return 1 ;
}
static void T_1
F_24 ( void )
{
F_25 () ;
}
static void
F_26 ( unsigned long V_45 )
{
F_27 ( V_45 - V_46 -> V_47 ) ;
}
static unsigned long
F_28 ( void )
{
F_10 ( V_48 L_6 , V_49 ) ;
F_29 ( ! F_30 () ) ;
return F_31 ( V_50 ) +
V_46 -> V_47 ;
}
static void
F_32 ( unsigned long V_45 )
{
unsigned long V_51 ;
F_29 ( ! F_30 () ) ;
V_51 = F_31 ( V_52 ) ;
V_46 -> V_47 = V_45 - V_51 ;
V_46 -> V_53 = V_45 ;
}
static unsigned long
F_33 ( void )
{
unsigned long V_54 ;
unsigned long V_47 ;
unsigned long V_53 ;
unsigned long V_55 ;
V_47 = V_46 -> V_47 ;
do {
V_53 = V_46 -> V_53 ;
V_54 = F_31 ( V_52 ) ;
V_54 += V_47 ;
if ( V_53 >= V_54 )
V_54 = V_53 + 1 ;
V_55 = F_34 ( & V_46 -> V_53 ,
V_53 , V_54 ) ;
} while ( F_35 ( V_55 != V_53 ) );
return V_54 ;
#if 0
WARN_ON(!irqs_disabled());
itc_offset = XEN_MAPPEDREGS->itc_offset;
itc_last = XEN_MAPPEDREGS->itc_last;
res = ia64_native_getreg(_IA64_REG_AR_ITC);
res += itc_offset;
if (itc_last >= res)
res = itc_last + 1;
XEN_MAPPEDREGS->itc_last = res;
return res;
#endif
}
static void F_36 ( int V_56 , unsigned long V_45 )
{
switch ( V_56 ) {
case V_57 ... V_58 :
F_37 ( V_56 - V_57 , V_45 ) ;
break;
case V_52 :
F_32 ( V_45 ) ;
break;
case V_59 :
F_38 ( V_45 ) ;
break;
case V_50 :
F_26 ( V_45 ) ;
break;
case V_60 :
F_39 ( V_45 ) ;
break;
default:
F_40 ( V_56 , V_45 ) ;
break;
}
}
static unsigned long F_41 ( int V_56 )
{
unsigned long V_54 ;
switch ( V_56 ) {
case V_61 :
V_54 = F_42 () ;
break;
case V_52 :
V_54 = F_33 () ;
break;
case V_50 :
V_54 = F_28 () ;
break;
case V_62 :
V_54 = F_43 () ;
break;
case V_59 :
V_54 = F_44 () ;
break;
default:
V_54 = F_45 ( V_56 ) ;
break;
}
return V_54 ;
}
static void
F_46 ( void )
{
int V_63 = F_47 () ;
F_48 ( 1 ) ;
F_49 () ;
if ( ! V_63 && F_50 () )
F_51 () ;
}
static void
F_52 ( void )
{
F_48 ( 0 ) ;
F_49 () ;
}
static unsigned long
F_53 ( void )
{
return F_47 () ? V_64 : 0 ;
}
static void
F_54 ( unsigned long V_65 )
{
if ( V_65 & V_64 )
F_46 () ;
else
F_52 () ;
}
static void
F_55 ( void )
{
}
static struct V_66 *
F_56 ( unsigned long V_67 )
{
return NULL ;
}
static unsigned int
F_57 ( char T_2 * V_68 , unsigned int V_69 )
{
struct V_70 V_71 ;
int V_72 ;
V_71 . V_73 = ( unsigned long ) V_68 -
V_74 ;
V_71 . V_69 = V_69 ;
V_72 = F_58 ( V_75 , & V_71 ) ;
if ( V_72 )
return V_72 ;
return V_71 . V_76 ;
}
static void
F_59 ( char T_2 * V_68 , unsigned int V_69 , T_3 V_45 )
{
struct V_70 V_71 ;
V_71 . V_73 = ( unsigned long ) V_68 -
V_74 ;
V_71 . V_69 = V_69 ;
V_71 . V_76 = V_45 ;
F_58 ( V_77 , & V_71 ) ;
}
void T_1
F_60 ( void )
{
F_1 () ;
V_78 = V_6 ;
V_79 = V_80 ;
V_81 = V_82 ;
V_83 = V_84 ;
V_85 = V_86 ;
V_87 = V_88 ;
V_89 = V_90 ;
V_91 = V_92 ;
F_61 ( & V_93 ) ;
}
static unsigned long T_4
F_62 ( void * V_94 , void * V_95 , unsigned long type )
{
const unsigned long V_96 = sizeof( V_97 ) /
sizeof( V_97 [ 0 ] ) ;
unsigned long V_98 ;
const struct V_99 * V_100 ;
V_98 = F_63 ( V_94 , V_95 , type ,
V_97 , V_96 ,
& V_100 ) ;
if ( V_100 == NULL )
return F_64 ( V_94 , V_95 , type ) ;
if ( V_98 == 0 )
return V_98 ;
switch ( type ) {
case V_101 : {
unsigned long V_102 =
V_103 ;
unsigned long V_104 = V_102 - ( unsigned long )
V_105 ;
unsigned long V_106 = ( unsigned long ) V_94 + V_104 ;
F_65 ( V_106 , V_107 ) ;
break;
}
default:
break;
}
return V_98 ;
}
static void T_1
F_66 ( unsigned long V_106 , unsigned long type )
{
F_67 ( V_106 , type , V_108 ,
F_68 ( V_108 ) ) ;
}
