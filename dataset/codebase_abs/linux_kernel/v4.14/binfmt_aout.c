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
if ( V_26 > V_25 )
return F_14 ( V_25 , V_26 - V_25 ) ;
return 0 ;
}
static unsigned long T_2 * F_15 ( char T_2 * V_27 , struct V_28 * V_29 )
{
char T_2 * T_2 * V_30 ;
char T_2 * T_2 * V_31 ;
unsigned long T_2 * V_32 ;
int V_33 = V_29 -> V_33 ;
int V_34 = V_29 -> V_34 ;
V_32 = ( void T_2 * ) ( ( - ( unsigned long ) sizeof( char * ) ) & ( unsigned long ) V_27 ) ;
#ifdef F_2
F_16 ( 0 , -- V_32 ) ;
F_16 ( 0 , -- V_32 ) ;
if ( V_29 -> V_35 ) {
F_16 ( 0 , -- V_32 ) ;
F_16 ( 1003 , -- V_32 ) ;
F_16 ( V_29 -> V_35 , -- V_32 ) ;
F_16 ( 1002 , -- V_32 ) ;
}
F_16 ( V_29 -> V_36 , -- V_32 ) ;
F_16 ( 1001 , -- V_32 ) ;
#endif
V_32 -= V_34 + 1 ;
V_31 = ( char T_2 * T_2 * ) V_32 ;
V_32 -= V_33 + 1 ;
V_30 = ( char T_2 * T_2 * ) V_32 ;
#ifndef F_2
F_16 ( ( unsigned long ) V_31 , -- V_32 ) ;
F_16 ( ( unsigned long ) V_30 , -- V_32 ) ;
#endif
F_16 ( V_33 , -- V_32 ) ;
V_11 -> V_37 -> V_38 = ( unsigned long ) V_27 ;
while ( V_33 -- > 0 ) {
char V_39 ;
F_16 ( V_27 , V_30 ++ ) ;
do {
F_17 ( V_39 , V_27 ++ ) ;
} while ( V_39 );
}
F_16 ( NULL , V_30 ) ;
V_11 -> V_37 -> V_40 = V_11 -> V_37 -> V_41 = ( unsigned long ) V_27 ;
while ( V_34 -- > 0 ) {
char V_39 ;
F_16 ( V_27 , V_31 ++ ) ;
do {
F_17 ( V_39 , V_27 ++ ) ;
} while ( V_39 );
}
F_16 ( NULL , V_31 ) ;
V_11 -> V_37 -> V_42 = ( unsigned long ) V_27 ;
return V_32 ;
}
static int F_18 ( struct V_28 * V_29 )
{
struct V_43 * V_14 = F_19 () ;
struct V_36 V_44 ;
unsigned long error ;
unsigned long V_45 ;
unsigned long V_46 ;
int V_47 ;
V_44 = * ( (struct V_36 * ) V_29 -> V_48 ) ;
if ( ( F_20 ( V_44 ) != V_49 && F_20 ( V_44 ) != V_50 &&
F_20 ( V_44 ) != V_51 && F_20 ( V_44 ) != V_52 ) ||
F_21 ( V_44 ) || F_22 ( V_44 ) ||
F_23 ( F_24 ( V_29 -> V_53 ) ) < V_44 . V_54 + V_44 . V_55 + F_25 ( V_44 ) + F_26 ( V_44 ) ) {
return - V_56 ;
}
if ( ! V_29 -> V_53 -> V_57 -> V_58 )
return - V_56 ;
V_45 = F_26 ( V_44 ) ;
V_46 = F_27 ( V_59 ) ;
if ( V_46 >= V_60 )
V_46 = ~ 0 ;
if ( V_44 . V_55 + V_44 . V_61 > V_46 )
return - V_62 ;
V_47 = F_28 ( V_29 ) ;
if ( V_47 )
return V_47 ;
#ifdef F_2
F_29 ( V_29 , V_44 ) ;
#else
F_30 ( V_63 ) ;
#endif
F_31 ( V_29 ) ;
V_11 -> V_37 -> V_64 = V_44 . V_54 +
( V_11 -> V_37 -> V_65 = F_32 ( V_44 ) ) ;
V_11 -> V_37 -> V_66 = V_44 . V_55 +
( V_11 -> V_37 -> V_67 = F_33 ( V_44 ) ) ;
V_11 -> V_37 -> V_68 = V_44 . V_61 +
( V_11 -> V_37 -> V_69 = F_34 ( V_44 ) ) ;
V_47 = F_35 ( V_29 , V_70 , V_71 ) ;
if ( V_47 < 0 )
return V_47 ;
F_36 ( V_29 ) ;
if ( F_20 ( V_44 ) == V_50 ) {
unsigned long V_72 , V_73 ;
T_4 V_74 ;
V_72 = F_32 ( V_44 ) ;
#ifdef F_2
V_74 = V_45 ;
V_73 = V_44 . V_54 + V_44 . V_55 + V_19 - 1 ;
#else
V_74 = 32 ;
V_73 = V_44 . V_54 + V_44 . V_55 ;
#endif
error = F_14 ( V_72 & V_75 , V_73 ) ;
if ( error )
return error ;
error = F_37 ( V_29 -> V_53 , V_72 , V_74 ,
V_44 . V_54 + V_44 . V_55 ) ;
if ( ( signed long ) error < 0 )
return error ;
} else {
if ( ( V_44 . V_54 & 0xfff || V_44 . V_55 & 0xfff ) &&
( F_20 ( V_44 ) != V_52 ) && F_38 () )
{
F_39 ( V_76 L_1 ) ;
}
if ( ( V_45 & ~ V_75 ) != 0 && F_38 () )
{
F_39 ( V_77
L_2 ,
V_29 -> V_53 ) ;
}
if ( ! V_29 -> V_53 -> V_57 -> V_58 || ( ( V_45 & ~ V_75 ) != 0 ) ) {
error = F_14 ( F_32 ( V_44 ) , V_44 . V_54 + V_44 . V_55 ) ;
if ( error )
return error ;
F_37 ( V_29 -> V_53 , F_32 ( V_44 ) , V_45 ,
V_44 . V_54 + V_44 . V_55 ) ;
goto V_78;
}
error = F_40 ( V_29 -> V_53 , F_32 ( V_44 ) , V_44 . V_54 ,
V_79 | V_80 ,
V_81 | V_82 | V_83 | V_84 ,
V_45 ) ;
if ( error != F_32 ( V_44 ) )
return error ;
error = F_40 ( V_29 -> V_53 , F_33 ( V_44 ) , V_44 . V_55 ,
V_79 | V_85 | V_80 ,
V_81 | V_82 | V_83 | V_84 ,
V_45 + V_44 . V_54 ) ;
if ( error != F_33 ( V_44 ) )
return error ;
}
V_78:
F_41 ( & V_86 ) ;
V_47 = F_12 ( V_11 -> V_37 -> V_69 , V_11 -> V_37 -> V_68 ) ;
if ( V_47 < 0 )
return V_47 ;
V_11 -> V_37 -> V_87 =
( unsigned long ) F_15 ( ( char T_2 * ) V_29 -> V_27 , V_29 ) ;
#ifdef F_2
V_14 -> V_88 = V_44 . V_89 ;
#endif
F_42 ( V_14 , V_44 . V_90 , V_11 -> V_37 -> V_87 ) ;
return 0 ;
}
static int F_43 ( struct V_53 * V_53 )
{
struct V_91 * V_91 ;
unsigned long V_92 , V_93 , V_94 ;
unsigned long error ;
int V_47 ;
struct V_36 V_44 ;
T_4 V_74 = 0 ;
V_91 = F_24 ( V_53 ) ;
V_47 = - V_56 ;
error = F_44 ( V_53 , & V_44 , sizeof( V_44 ) , & V_74 ) ;
if ( error != sizeof( V_44 ) )
goto V_95;
if ( ( F_20 ( V_44 ) != V_49 && F_20 ( V_44 ) != V_51 ) || F_21 ( V_44 ) ||
F_22 ( V_44 ) || ( ( V_44 . V_90 & 0xfff ) && F_20 ( V_44 ) == V_49 ) ||
F_23 ( V_91 ) < V_44 . V_54 + V_44 . V_55 + F_25 ( V_44 ) + F_26 ( V_44 ) ) {
goto V_95;
}
if ( ! V_53 -> V_57 -> V_58 )
goto V_95;
if ( F_45 ( V_44 ) )
goto V_95;
V_93 = V_44 . V_90 & 0xfffff000 ;
if ( ( F_26 ( V_44 ) & ~ V_75 ) != 0 ) {
if ( F_38 () )
{
F_39 ( V_77
L_3 ,
V_53 ) ;
}
V_47 = F_14 ( V_93 , V_44 . V_54 + V_44 . V_55 + V_44 . V_61 ) ;
if ( V_47 )
goto V_95;
F_37 ( V_53 , V_93 , F_26 ( V_44 ) ,
V_44 . V_54 + V_44 . V_55 ) ;
V_47 = 0 ;
goto V_95;
}
error = F_40 ( V_53 , V_93 , V_44 . V_54 + V_44 . V_55 ,
V_79 | V_85 | V_80 ,
V_81 | V_82 | V_83 ,
F_26 ( V_44 ) ) ;
V_47 = error ;
if ( error != V_93 )
goto V_95;
V_94 = F_13 ( V_44 . V_54 + V_44 . V_55 ) ;
V_92 = V_44 . V_54 + V_44 . V_55 + V_44 . V_61 ;
if ( V_92 > V_94 ) {
V_47 = F_14 ( V_93 + V_94 , V_92 - V_94 ) ;
if ( V_47 )
goto V_95;
}
V_47 = 0 ;
V_95:
return V_47 ;
}
static int T_5 F_46 ( void )
{
F_47 ( & V_86 ) ;
return 0 ;
}
static void T_6 F_48 ( void )
{
F_49 ( & V_86 ) ;
}
