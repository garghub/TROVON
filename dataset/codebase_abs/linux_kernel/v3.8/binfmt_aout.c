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
F_24 ( V_33 -> V_3 -> V_57 . V_58 -> V_59 ) < V_48 . V_60 + V_48 . V_61 + F_25 ( V_48 ) + F_26 ( V_48 ) ) {
return - V_62 ;
}
if ( ! V_33 -> V_3 -> V_63 || ! V_33 -> V_3 -> V_63 -> V_64 )
return - V_62 ;
V_49 = F_26 ( V_48 ) ;
V_50 = F_27 ( V_65 ) ;
if ( V_50 >= V_66 )
V_50 = ~ 0 ;
if ( V_48 . V_61 + V_48 . V_67 > V_50 )
return - V_68 ;
V_51 = F_28 ( V_33 ) ;
if ( V_51 )
return V_51 ;
#ifdef F_2
F_29 ( V_33 , V_48 ) ;
#else
F_30 ( V_69 ) ;
#endif
F_31 ( V_33 ) ;
V_11 -> V_41 -> V_70 = V_48 . V_60 +
( V_11 -> V_41 -> V_71 = F_32 ( V_48 ) ) ;
V_11 -> V_41 -> V_72 = V_48 . V_61 +
( V_11 -> V_41 -> V_73 = F_33 ( V_48 ) ) ;
V_11 -> V_41 -> V_74 = V_48 . V_67 +
( V_11 -> V_41 -> V_75 = F_34 ( V_48 ) ) ;
V_11 -> V_41 -> V_76 = V_11 -> V_41 -> V_77 ;
V_11 -> V_41 -> V_78 = 0 ;
V_51 = F_35 ( V_33 , V_79 , V_80 ) ;
if ( V_51 < 0 ) {
F_36 ( V_81 , V_11 , 0 ) ;
return V_51 ;
}
F_37 ( V_33 ) ;
if ( F_21 ( V_48 ) == V_54 ) {
unsigned long V_82 , V_83 ;
T_4 V_84 ;
V_82 = F_32 ( V_48 ) ;
#ifdef F_2
V_84 = V_49 ;
V_83 = V_48 . V_60 + V_48 . V_61 + V_22 - 1 ;
#else
V_84 = 32 ;
V_83 = V_48 . V_60 + V_48 . V_61 ;
#endif
error = F_14 ( V_82 & V_85 , V_83 ) ;
if ( error != ( V_82 & V_85 ) ) {
F_36 ( V_81 , V_11 , 0 ) ;
return error ;
}
error = V_33 -> V_3 -> V_63 -> V_86 ( V_33 -> V_3 ,
( char T_2 * ) V_82 ,
V_48 . V_60 + V_48 . V_61 , & V_84 ) ;
if ( ( signed long ) error < 0 ) {
F_36 ( V_81 , V_11 , 0 ) ;
return error ;
}
F_38 ( V_82 , V_82 + V_48 . V_60 + V_48 . V_61 ) ;
} else {
if ( ( V_48 . V_60 & 0xfff || V_48 . V_61 & 0xfff ) &&
( F_21 ( V_48 ) != V_56 ) && F_39 () )
{
F_40 ( V_87 L_1 ) ;
}
if ( ( V_49 & ~ V_85 ) != 0 && F_39 () )
{
F_40 ( V_88
L_2 ,
V_33 -> V_3 -> V_57 . V_58 -> V_89 . V_90 ) ;
}
if ( ! V_33 -> V_3 -> V_63 -> V_64 || ( ( V_49 & ~ V_85 ) != 0 ) ) {
T_4 V_84 = V_49 ;
F_14 ( F_32 ( V_48 ) , V_48 . V_60 + V_48 . V_61 ) ;
V_33 -> V_3 -> V_63 -> V_86 ( V_33 -> V_3 ,
( char T_2 * ) F_32 ( V_48 ) ,
V_48 . V_60 + V_48 . V_61 , & V_84 ) ;
F_38 ( ( unsigned long ) F_32 ( V_48 ) ,
( unsigned long ) F_32 ( V_48 ) +
V_48 . V_60 + V_48 . V_61 ) ;
goto V_91;
}
error = F_41 ( V_33 -> V_3 , F_32 ( V_48 ) , V_48 . V_60 ,
V_92 | V_93 ,
V_94 | V_95 | V_96 | V_97 ,
V_49 ) ;
if ( error != F_32 ( V_48 ) ) {
F_36 ( V_81 , V_11 , 0 ) ;
return error ;
}
error = F_41 ( V_33 -> V_3 , F_33 ( V_48 ) , V_48 . V_61 ,
V_92 | V_98 | V_93 ,
V_94 | V_95 | V_96 | V_97 ,
V_49 + V_48 . V_60 ) ;
if ( error != F_33 ( V_48 ) ) {
F_36 ( V_81 , V_11 , 0 ) ;
return error ;
}
}
V_91:
F_42 ( & V_99 ) ;
V_51 = F_12 ( V_11 -> V_41 -> V_75 , V_11 -> V_41 -> V_74 ) ;
if ( V_51 < 0 ) {
F_36 ( V_81 , V_11 , 0 ) ;
return V_51 ;
}
V_11 -> V_41 -> V_100 =
( unsigned long ) F_16 ( ( char T_2 * ) V_33 -> V_31 , V_33 ) ;
#ifdef F_2
V_17 -> V_101 = V_48 . V_102 ;
#endif
F_43 ( V_17 , V_48 . V_103 , V_11 -> V_41 -> V_100 ) ;
return 0 ;
}
static int F_44 ( struct V_3 * V_3 )
{
struct V_104 * V_104 ;
unsigned long V_105 , V_106 , V_107 ;
unsigned long error ;
int V_51 ;
struct V_40 V_48 ;
V_104 = V_3 -> V_57 . V_58 -> V_59 ;
V_51 = - V_62 ;
error = F_45 ( V_3 , 0 , ( char * ) & V_48 , sizeof( V_48 ) ) ;
if ( error != sizeof( V_48 ) )
goto V_108;
if ( ( F_21 ( V_48 ) != V_53 && F_21 ( V_48 ) != V_55 ) || F_22 ( V_48 ) ||
F_23 ( V_48 ) || ( ( V_48 . V_103 & 0xfff ) && F_21 ( V_48 ) == V_53 ) ||
F_24 ( V_104 ) < V_48 . V_60 + V_48 . V_61 + F_25 ( V_48 ) + F_26 ( V_48 ) ) {
goto V_108;
}
if ( ! V_3 -> V_63 || ! V_3 -> V_63 -> V_64 )
goto V_108;
if ( F_46 ( V_48 ) )
goto V_108;
V_106 = V_48 . V_103 & 0xfffff000 ;
if ( ( F_26 ( V_48 ) & ~ V_85 ) != 0 ) {
T_4 V_84 = F_26 ( V_48 ) ;
if ( F_39 () )
{
F_40 ( V_88
L_3 ,
V_3 -> V_57 . V_58 -> V_89 . V_90 ) ;
}
F_14 ( V_106 , V_48 . V_60 + V_48 . V_61 + V_48 . V_67 ) ;
V_3 -> V_63 -> V_86 ( V_3 , ( char T_2 * ) V_106 ,
V_48 . V_60 + V_48 . V_61 , & V_84 ) ;
F_38 ( ( unsigned long ) V_106 ,
( unsigned long ) V_106 + V_48 . V_60 + V_48 . V_61 ) ;
V_51 = 0 ;
goto V_108;
}
error = F_41 ( V_3 , V_106 , V_48 . V_60 + V_48 . V_61 ,
V_92 | V_98 | V_93 ,
V_94 | V_95 | V_96 ,
F_26 ( V_48 ) ) ;
V_51 = error ;
if ( error != V_106 )
goto V_108;
V_107 = F_13 ( V_48 . V_60 + V_48 . V_61 ) ;
V_105 = V_48 . V_60 + V_48 . V_61 + V_48 . V_67 ;
if ( V_105 > V_107 ) {
error = F_14 ( V_106 + V_107 , V_105 - V_107 ) ;
V_51 = error ;
if ( error != V_106 + V_107 )
goto V_108;
}
V_51 = 0 ;
V_108:
return V_51 ;
}
static int T_5 F_47 ( void )
{
F_48 ( & V_99 ) ;
return 0 ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_99 ) ;
}
