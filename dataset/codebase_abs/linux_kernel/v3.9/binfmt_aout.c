static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_3 = V_2 -> V_3 ;
T_1 V_4 ;
int V_5 = 0 ;
void T_2 * V_6 ;
int V_7 ;
struct V_8 V_9 ;
#ifdef F_2
# define F_3 ( T_3 ) ((void __user *)u.start_data)
#else
# define F_3 ( T_3 ) ((void __user *)((u.u_tsize << PAGE_SHIFT) + \
u.start_code))
#endif
# define F_4 ( T_3 ) ((void __user *)u.start_stack)
V_4 = F_5 () ;
F_6 ( V_10 ) ;
V_5 = 1 ;
V_11 -> V_12 |= V_13 ;
strncpy ( V_9 . V_14 , V_11 -> V_15 , sizeof( V_9 . V_14 ) ) ;
V_9 . V_16 = F_7 ( struct V_8 , V_17 ) ;
V_9 . signal = V_2 -> V_18 -> V_19 ;
F_8 ( V_2 -> V_17 , & V_9 ) ;
if ( ( V_9 . V_20 + V_9 . V_21 + 1 ) * V_22 > V_2 -> V_23 )
V_9 . V_20 = 0 ;
if ( ( V_9 . V_21 + 1 ) * V_22 > V_2 -> V_23 )
V_9 . V_21 = 0 ;
F_6 ( V_24 ) ;
if ( ! F_9 ( V_25 , F_3 ( V_9 ) , V_9 . V_20 << V_26 ) )
V_9 . V_20 = 0 ;
if ( ! F_9 ( V_25 , F_4 ( V_9 ) , V_9 . V_21 << V_26 ) )
V_9 . V_21 = 0 ;
F_6 ( V_10 ) ;
if ( ! F_10 ( V_3 , & V_9 , sizeof( V_9 ) ) )
goto V_27;
if ( ! F_11 ( V_2 -> V_3 , V_22 - sizeof( V_9 ) ) )
goto V_27;
F_6 ( V_24 ) ;
if ( V_9 . V_20 != 0 ) {
V_6 = F_3 ( V_9 ) ;
V_7 = V_9 . V_20 << V_26 ;
if ( ! F_10 ( V_3 , V_6 , V_7 ) )
goto V_27;
}
if ( V_9 . V_21 != 0 ) {
V_6 = F_4 ( V_9 ) ;
V_7 = V_9 . V_21 << V_26 ;
if ( ! F_10 ( V_3 , V_6 , V_7 ) )
goto V_27;
}
V_27:
F_6 ( V_4 ) ;
return V_5 ;
}
static int F_12 ( unsigned long V_28 , unsigned long V_29 )
{
V_28 = F_13 ( V_28 ) ;
V_29 = F_13 ( V_29 ) ;
if ( V_29 > V_28 ) {
unsigned long V_30 ;
V_30 = F_14 ( V_28 , V_29 - V_28 ) ;
if ( F_15 ( V_30 ) )
return V_30 ;
}
return 0 ;
}
static unsigned long T_2 * F_16 ( char T_2 * V_31 , struct V_32 * V_33 )
{
char T_2 * T_2 * V_34 ;
char T_2 * T_2 * V_35 ;
unsigned long T_2 * V_36 ;
int V_37 = V_33 -> V_37 ;
int V_38 = V_33 -> V_38 ;
V_36 = ( void T_2 * ) ( ( - ( unsigned long ) sizeof( char * ) ) & ( unsigned long ) V_31 ) ;
#ifdef F_2
F_17 ( 0 , -- V_36 ) ;
F_17 ( 0 , -- V_36 ) ;
if ( V_33 -> V_39 ) {
F_17 ( 0 , -- V_36 ) ;
F_17 ( 1003 , -- V_36 ) ;
F_17 ( V_33 -> V_39 , -- V_36 ) ;
F_17 ( 1002 , -- V_36 ) ;
}
F_17 ( V_33 -> V_40 , -- V_36 ) ;
F_17 ( 1001 , -- V_36 ) ;
#endif
V_36 -= V_38 + 1 ;
V_35 = ( char T_2 * T_2 * ) V_36 ;
V_36 -= V_37 + 1 ;
V_34 = ( char T_2 * T_2 * ) V_36 ;
#ifndef F_2
F_17 ( ( unsigned long ) V_35 , -- V_36 ) ;
F_17 ( ( unsigned long ) V_34 , -- V_36 ) ;
#endif
F_17 ( V_37 , -- V_36 ) ;
V_11 -> V_41 -> V_42 = ( unsigned long ) V_31 ;
while ( V_37 -- > 0 ) {
char V_43 ;
F_17 ( V_31 , V_34 ++ ) ;
do {
F_18 ( V_43 , V_31 ++ ) ;
} while ( V_43 );
}
F_17 ( NULL , V_34 ) ;
V_11 -> V_41 -> V_44 = V_11 -> V_41 -> V_45 = ( unsigned long ) V_31 ;
while ( V_38 -- > 0 ) {
char V_43 ;
F_17 ( V_31 , V_35 ++ ) ;
do {
F_18 ( V_43 , V_31 ++ ) ;
} while ( V_43 );
}
F_17 ( NULL , V_35 ) ;
V_11 -> V_41 -> V_46 = ( unsigned long ) V_31 ;
return V_36 ;
}
static int F_19 ( struct V_32 * V_33 )
{
struct V_47 * V_17 = F_20 () ;
struct V_40 V_48 ;
unsigned long error ;
unsigned long V_49 ;
unsigned long V_50 ;
int V_51 ;
V_48 = * ( (struct V_40 * ) V_33 -> V_52 ) ;
if ( ( F_21 ( V_48 ) != V_53 && F_21 ( V_48 ) != V_54 &&
F_21 ( V_48 ) != V_55 && F_21 ( V_48 ) != V_56 ) ||
F_22 ( V_48 ) || F_23 ( V_48 ) ||
F_24 ( F_25 ( V_33 -> V_3 ) ) < V_48 . V_57 + V_48 . V_58 + F_26 ( V_48 ) + F_27 ( V_48 ) ) {
return - V_59 ;
}
if ( ! V_33 -> V_3 -> V_60 || ! V_33 -> V_3 -> V_60 -> V_61 )
return - V_59 ;
V_49 = F_27 ( V_48 ) ;
V_50 = F_28 ( V_62 ) ;
if ( V_50 >= V_63 )
V_50 = ~ 0 ;
if ( V_48 . V_58 + V_48 . V_64 > V_50 )
return - V_65 ;
V_51 = F_29 ( V_33 ) ;
if ( V_51 )
return V_51 ;
#ifdef F_2
F_30 ( V_33 , V_48 ) ;
#else
F_31 ( V_66 ) ;
#endif
F_32 ( V_33 ) ;
V_11 -> V_41 -> V_67 = V_48 . V_57 +
( V_11 -> V_41 -> V_68 = F_33 ( V_48 ) ) ;
V_11 -> V_41 -> V_69 = V_48 . V_58 +
( V_11 -> V_41 -> V_70 = F_34 ( V_48 ) ) ;
V_11 -> V_41 -> V_71 = V_48 . V_64 +
( V_11 -> V_41 -> V_72 = F_35 ( V_48 ) ) ;
V_11 -> V_41 -> V_73 = V_11 -> V_41 -> V_74 ;
V_11 -> V_41 -> V_75 = 0 ;
V_51 = F_36 ( V_33 , V_76 , V_77 ) ;
if ( V_51 < 0 ) {
F_37 ( V_78 , V_11 , 0 ) ;
return V_51 ;
}
F_38 ( V_33 ) ;
if ( F_21 ( V_48 ) == V_54 ) {
unsigned long V_79 , V_80 ;
T_4 V_81 ;
V_79 = F_33 ( V_48 ) ;
#ifdef F_2
V_81 = V_49 ;
V_80 = V_48 . V_57 + V_48 . V_58 + V_22 - 1 ;
#else
V_81 = 32 ;
V_80 = V_48 . V_57 + V_48 . V_58 ;
#endif
error = F_14 ( V_79 & V_82 , V_80 ) ;
if ( error != ( V_79 & V_82 ) ) {
F_37 ( V_78 , V_11 , 0 ) ;
return error ;
}
error = V_33 -> V_3 -> V_60 -> V_83 ( V_33 -> V_3 ,
( char T_2 * ) V_79 ,
V_48 . V_57 + V_48 . V_58 , & V_81 ) ;
if ( ( signed long ) error < 0 ) {
F_37 ( V_78 , V_11 , 0 ) ;
return error ;
}
F_39 ( V_79 , V_79 + V_48 . V_57 + V_48 . V_58 ) ;
} else {
if ( ( V_48 . V_57 & 0xfff || V_48 . V_58 & 0xfff ) &&
( F_21 ( V_48 ) != V_56 ) && F_40 () )
{
F_41 ( V_84 L_1 ) ;
}
if ( ( V_49 & ~ V_82 ) != 0 && F_40 () )
{
F_41 ( V_85
L_2 ,
V_33 -> V_3 -> V_86 . V_87 -> V_88 . V_89 ) ;
}
if ( ! V_33 -> V_3 -> V_60 -> V_61 || ( ( V_49 & ~ V_82 ) != 0 ) ) {
T_4 V_81 = V_49 ;
F_14 ( F_33 ( V_48 ) , V_48 . V_57 + V_48 . V_58 ) ;
V_33 -> V_3 -> V_60 -> V_83 ( V_33 -> V_3 ,
( char T_2 * ) F_33 ( V_48 ) ,
V_48 . V_57 + V_48 . V_58 , & V_81 ) ;
F_39 ( ( unsigned long ) F_33 ( V_48 ) ,
( unsigned long ) F_33 ( V_48 ) +
V_48 . V_57 + V_48 . V_58 ) ;
goto V_90;
}
error = F_42 ( V_33 -> V_3 , F_33 ( V_48 ) , V_48 . V_57 ,
V_91 | V_92 ,
V_93 | V_94 | V_95 | V_96 ,
V_49 ) ;
if ( error != F_33 ( V_48 ) ) {
F_37 ( V_78 , V_11 , 0 ) ;
return error ;
}
error = F_42 ( V_33 -> V_3 , F_34 ( V_48 ) , V_48 . V_58 ,
V_91 | V_97 | V_92 ,
V_93 | V_94 | V_95 | V_96 ,
V_49 + V_48 . V_57 ) ;
if ( error != F_34 ( V_48 ) ) {
F_37 ( V_78 , V_11 , 0 ) ;
return error ;
}
}
V_90:
F_43 ( & V_98 ) ;
V_51 = F_12 ( V_11 -> V_41 -> V_72 , V_11 -> V_41 -> V_71 ) ;
if ( V_51 < 0 ) {
F_37 ( V_78 , V_11 , 0 ) ;
return V_51 ;
}
V_11 -> V_41 -> V_99 =
( unsigned long ) F_16 ( ( char T_2 * ) V_33 -> V_31 , V_33 ) ;
#ifdef F_2
V_17 -> V_100 = V_48 . V_101 ;
#endif
F_44 ( V_17 , V_48 . V_102 , V_11 -> V_41 -> V_99 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_3 )
{
struct V_103 * V_103 ;
unsigned long V_104 , V_105 , V_106 ;
unsigned long error ;
int V_51 ;
struct V_40 V_48 ;
V_103 = F_25 ( V_3 ) ;
V_51 = - V_59 ;
error = F_46 ( V_3 , 0 , ( char * ) & V_48 , sizeof( V_48 ) ) ;
if ( error != sizeof( V_48 ) )
goto V_107;
if ( ( F_21 ( V_48 ) != V_53 && F_21 ( V_48 ) != V_55 ) || F_22 ( V_48 ) ||
F_23 ( V_48 ) || ( ( V_48 . V_102 & 0xfff ) && F_21 ( V_48 ) == V_53 ) ||
F_24 ( V_103 ) < V_48 . V_57 + V_48 . V_58 + F_26 ( V_48 ) + F_27 ( V_48 ) ) {
goto V_107;
}
if ( ! V_3 -> V_60 || ! V_3 -> V_60 -> V_61 )
goto V_107;
if ( F_47 ( V_48 ) )
goto V_107;
V_105 = V_48 . V_102 & 0xfffff000 ;
if ( ( F_27 ( V_48 ) & ~ V_82 ) != 0 ) {
T_4 V_81 = F_27 ( V_48 ) ;
if ( F_40 () )
{
F_41 ( V_85
L_3 ,
V_3 -> V_86 . V_87 -> V_88 . V_89 ) ;
}
F_14 ( V_105 , V_48 . V_57 + V_48 . V_58 + V_48 . V_64 ) ;
V_3 -> V_60 -> V_83 ( V_3 , ( char T_2 * ) V_105 ,
V_48 . V_57 + V_48 . V_58 , & V_81 ) ;
F_39 ( ( unsigned long ) V_105 ,
( unsigned long ) V_105 + V_48 . V_57 + V_48 . V_58 ) ;
V_51 = 0 ;
goto V_107;
}
error = F_42 ( V_3 , V_105 , V_48 . V_57 + V_48 . V_58 ,
V_91 | V_97 | V_92 ,
V_93 | V_94 | V_95 ,
F_27 ( V_48 ) ) ;
V_51 = error ;
if ( error != V_105 )
goto V_107;
V_106 = F_13 ( V_48 . V_57 + V_48 . V_58 ) ;
V_104 = V_48 . V_57 + V_48 . V_58 + V_48 . V_64 ;
if ( V_104 > V_106 ) {
error = F_14 ( V_105 + V_106 , V_104 - V_106 ) ;
V_51 = error ;
if ( error != V_105 + V_106 )
goto V_107;
}
V_51 = 0 ;
V_107:
return V_51 ;
}
static int T_5 F_48 ( void )
{
F_49 ( & V_98 ) ;
return 0 ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_98 ) ;
}
