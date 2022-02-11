static int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
int V_4 = 0 ;
void T_2 * V_5 ;
int V_6 ;
struct V_7 V_8 ;
#ifdef F_2
# define F_3 ( T_3 ) ((void __user *)u.start_data)
#else
# define F_3 ( T_3 ) ((void __user *)((u.u_tsize << PAGE_SHIFT) + \
u.start_code))
#endif
# define F_4 ( T_3 ) ((void __user *)u.start_stack)
V_3 = F_5 () ;
F_6 ( V_9 ) ;
V_4 = 1 ;
strncpy ( V_8 . V_10 , V_11 -> V_12 , sizeof( V_8 . V_10 ) ) ;
V_8 . V_13 = F_7 ( struct V_7 , V_14 ) ;
V_8 . signal = V_2 -> V_15 -> V_16 ;
F_8 ( V_2 -> V_14 , & V_8 ) ;
if ( ( V_8 . V_17 + V_8 . V_18 + 1 ) * V_19 > V_2 -> V_20 )
V_8 . V_17 = 0 ;
if ( ( V_8 . V_18 + 1 ) * V_19 > V_2 -> V_20 )
V_8 . V_18 = 0 ;
F_6 ( V_21 ) ;
if ( ! F_9 ( V_22 , F_3 ( V_8 ) , V_8 . V_17 << V_23 ) )
V_8 . V_17 = 0 ;
if ( ! F_9 ( V_22 , F_4 ( V_8 ) , V_8 . V_18 << V_23 ) )
V_8 . V_18 = 0 ;
F_6 ( V_9 ) ;
if ( ! F_10 ( V_2 , & V_8 , sizeof( V_8 ) ) )
goto V_24;
if ( ! F_11 ( V_2 , V_19 - sizeof( V_8 ) ) )
goto V_24;
F_6 ( V_21 ) ;
if ( V_8 . V_17 != 0 ) {
V_5 = F_3 ( V_8 ) ;
V_6 = V_8 . V_17 << V_23 ;
if ( ! F_10 ( V_2 , V_5 , V_6 ) )
goto V_24;
}
if ( V_8 . V_18 != 0 ) {
V_5 = F_4 ( V_8 ) ;
V_6 = V_8 . V_18 << V_23 ;
if ( ! F_10 ( V_2 , V_5 , V_6 ) )
goto V_24;
}
V_24:
F_6 ( V_3 ) ;
return V_4 ;
}
static int F_12 ( unsigned long V_25 , unsigned long V_26 )
{
V_25 = F_13 ( V_25 ) ;
V_26 = F_13 ( V_26 ) ;
if ( V_26 > V_25 ) {
unsigned long V_27 ;
V_27 = F_14 ( V_25 , V_26 - V_25 ) ;
if ( F_15 ( V_27 ) )
return V_27 ;
}
return 0 ;
}
static unsigned long T_2 * F_16 ( char T_2 * V_28 , struct V_29 * V_30 )
{
char T_2 * T_2 * V_31 ;
char T_2 * T_2 * V_32 ;
unsigned long T_2 * V_33 ;
int V_34 = V_30 -> V_34 ;
int V_35 = V_30 -> V_35 ;
V_33 = ( void T_2 * ) ( ( - ( unsigned long ) sizeof( char * ) ) & ( unsigned long ) V_28 ) ;
#ifdef F_2
F_17 ( 0 , -- V_33 ) ;
F_17 ( 0 , -- V_33 ) ;
if ( V_30 -> V_36 ) {
F_17 ( 0 , -- V_33 ) ;
F_17 ( 1003 , -- V_33 ) ;
F_17 ( V_30 -> V_36 , -- V_33 ) ;
F_17 ( 1002 , -- V_33 ) ;
}
F_17 ( V_30 -> V_37 , -- V_33 ) ;
F_17 ( 1001 , -- V_33 ) ;
#endif
V_33 -= V_35 + 1 ;
V_32 = ( char T_2 * T_2 * ) V_33 ;
V_33 -= V_34 + 1 ;
V_31 = ( char T_2 * T_2 * ) V_33 ;
#ifndef F_2
F_17 ( ( unsigned long ) V_32 , -- V_33 ) ;
F_17 ( ( unsigned long ) V_31 , -- V_33 ) ;
#endif
F_17 ( V_34 , -- V_33 ) ;
V_11 -> V_38 -> V_39 = ( unsigned long ) V_28 ;
while ( V_34 -- > 0 ) {
char V_40 ;
F_17 ( V_28 , V_31 ++ ) ;
do {
F_18 ( V_40 , V_28 ++ ) ;
} while ( V_40 );
}
F_17 ( NULL , V_31 ) ;
V_11 -> V_38 -> V_41 = V_11 -> V_38 -> V_42 = ( unsigned long ) V_28 ;
while ( V_35 -- > 0 ) {
char V_40 ;
F_17 ( V_28 , V_32 ++ ) ;
do {
F_18 ( V_40 , V_28 ++ ) ;
} while ( V_40 );
}
F_17 ( NULL , V_32 ) ;
V_11 -> V_38 -> V_43 = ( unsigned long ) V_28 ;
return V_33 ;
}
static int F_19 ( struct V_29 * V_30 )
{
struct V_44 * V_14 = F_20 () ;
struct V_37 V_45 ;
unsigned long error ;
unsigned long V_46 ;
unsigned long V_47 ;
int V_48 ;
V_45 = * ( (struct V_37 * ) V_30 -> V_49 ) ;
if ( ( F_21 ( V_45 ) != V_50 && F_21 ( V_45 ) != V_51 &&
F_21 ( V_45 ) != V_52 && F_21 ( V_45 ) != V_53 ) ||
F_22 ( V_45 ) || F_23 ( V_45 ) ||
F_24 ( F_25 ( V_30 -> V_54 ) ) < V_45 . V_55 + V_45 . V_56 + F_26 ( V_45 ) + F_27 ( V_45 ) ) {
return - V_57 ;
}
if ( ! V_30 -> V_54 -> V_58 -> V_59 )
return - V_57 ;
V_46 = F_27 ( V_45 ) ;
V_47 = F_28 ( V_60 ) ;
if ( V_47 >= V_61 )
V_47 = ~ 0 ;
if ( V_45 . V_56 + V_45 . V_62 > V_47 )
return - V_63 ;
V_48 = F_29 ( V_30 ) ;
if ( V_48 )
return V_48 ;
#ifdef F_2
F_30 ( V_30 , V_45 ) ;
#else
F_31 ( V_64 ) ;
#endif
F_32 ( V_30 ) ;
V_11 -> V_38 -> V_65 = V_45 . V_55 +
( V_11 -> V_38 -> V_66 = F_33 ( V_45 ) ) ;
V_11 -> V_38 -> V_67 = V_45 . V_56 +
( V_11 -> V_38 -> V_68 = F_34 ( V_45 ) ) ;
V_11 -> V_38 -> V_69 = V_45 . V_62 +
( V_11 -> V_38 -> V_70 = F_35 ( V_45 ) ) ;
V_48 = F_36 ( V_30 , V_71 , V_72 ) ;
if ( V_48 < 0 )
return V_48 ;
F_37 ( V_30 ) ;
if ( F_21 ( V_45 ) == V_51 ) {
unsigned long V_73 , V_74 ;
T_4 V_75 ;
V_73 = F_33 ( V_45 ) ;
#ifdef F_2
V_75 = V_46 ;
V_74 = V_45 . V_55 + V_45 . V_56 + V_19 - 1 ;
#else
V_75 = 32 ;
V_74 = V_45 . V_55 + V_45 . V_56 ;
#endif
error = F_14 ( V_73 & V_76 , V_74 ) ;
if ( error != ( V_73 & V_76 ) )
return error ;
error = F_38 ( V_30 -> V_54 , V_73 , V_75 ,
V_45 . V_55 + V_45 . V_56 ) ;
if ( ( signed long ) error < 0 )
return error ;
} else {
if ( ( V_45 . V_55 & 0xfff || V_45 . V_56 & 0xfff ) &&
( F_21 ( V_45 ) != V_53 ) && F_39 () )
{
F_40 ( V_77 L_1 ) ;
}
if ( ( V_46 & ~ V_76 ) != 0 && F_39 () )
{
F_40 ( V_78
L_2 ,
V_30 -> V_54 -> V_79 . V_80 -> V_81 . V_82 ) ;
}
if ( ! V_30 -> V_54 -> V_58 -> V_59 || ( ( V_46 & ~ V_76 ) != 0 ) ) {
F_14 ( F_33 ( V_45 ) , V_45 . V_55 + V_45 . V_56 ) ;
F_38 ( V_30 -> V_54 , F_33 ( V_45 ) , V_46 ,
V_45 . V_55 + V_45 . V_56 ) ;
goto V_83;
}
error = F_41 ( V_30 -> V_54 , F_33 ( V_45 ) , V_45 . V_55 ,
V_84 | V_85 ,
V_86 | V_87 | V_88 | V_89 ,
V_46 ) ;
if ( error != F_33 ( V_45 ) )
return error ;
error = F_41 ( V_30 -> V_54 , F_34 ( V_45 ) , V_45 . V_56 ,
V_84 | V_90 | V_85 ,
V_86 | V_87 | V_88 | V_89 ,
V_46 + V_45 . V_55 ) ;
if ( error != F_34 ( V_45 ) )
return error ;
}
V_83:
F_42 ( & V_91 ) ;
V_48 = F_12 ( V_11 -> V_38 -> V_70 , V_11 -> V_38 -> V_69 ) ;
if ( V_48 < 0 )
return V_48 ;
V_11 -> V_38 -> V_92 =
( unsigned long ) F_16 ( ( char T_2 * ) V_30 -> V_28 , V_30 ) ;
#ifdef F_2
V_14 -> V_93 = V_45 . V_94 ;
#endif
F_43 ( V_14 , V_45 . V_95 , V_11 -> V_38 -> V_92 ) ;
return 0 ;
}
static int F_44 ( struct V_54 * V_54 )
{
struct V_96 * V_96 ;
unsigned long V_97 , V_98 , V_99 ;
unsigned long error ;
int V_48 ;
struct V_37 V_45 ;
V_96 = F_25 ( V_54 ) ;
V_48 = - V_57 ;
error = F_45 ( V_54 , 0 , ( char * ) & V_45 , sizeof( V_45 ) ) ;
if ( error != sizeof( V_45 ) )
goto V_100;
if ( ( F_21 ( V_45 ) != V_50 && F_21 ( V_45 ) != V_52 ) || F_22 ( V_45 ) ||
F_23 ( V_45 ) || ( ( V_45 . V_95 & 0xfff ) && F_21 ( V_45 ) == V_50 ) ||
F_24 ( V_96 ) < V_45 . V_55 + V_45 . V_56 + F_26 ( V_45 ) + F_27 ( V_45 ) ) {
goto V_100;
}
if ( ! V_54 -> V_58 -> V_59 )
goto V_100;
if ( F_46 ( V_45 ) )
goto V_100;
V_98 = V_45 . V_95 & 0xfffff000 ;
if ( ( F_27 ( V_45 ) & ~ V_76 ) != 0 ) {
if ( F_39 () )
{
F_40 ( V_78
L_3 ,
V_54 -> V_79 . V_80 -> V_81 . V_82 ) ;
}
F_14 ( V_98 , V_45 . V_55 + V_45 . V_56 + V_45 . V_62 ) ;
F_38 ( V_54 , V_98 , F_27 ( V_45 ) ,
V_45 . V_55 + V_45 . V_56 ) ;
V_48 = 0 ;
goto V_100;
}
error = F_41 ( V_54 , V_98 , V_45 . V_55 + V_45 . V_56 ,
V_84 | V_90 | V_85 ,
V_86 | V_87 | V_88 ,
F_27 ( V_45 ) ) ;
V_48 = error ;
if ( error != V_98 )
goto V_100;
V_99 = F_13 ( V_45 . V_55 + V_45 . V_56 ) ;
V_97 = V_45 . V_55 + V_45 . V_56 + V_45 . V_62 ;
if ( V_97 > V_99 ) {
error = F_14 ( V_98 + V_99 , V_97 - V_99 ) ;
V_48 = error ;
if ( error != V_98 + V_99 )
goto V_100;
}
V_48 = 0 ;
V_100:
return V_48 ;
}
static int T_5 F_47 ( void )
{
F_48 ( & V_91 ) ;
return 0 ;
}
static void T_6 F_49 ( void )
{
F_50 ( & V_91 ) ;
}
