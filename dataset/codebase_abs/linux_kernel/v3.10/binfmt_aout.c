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
strncpy ( V_9 . V_11 , V_12 -> V_13 , sizeof( V_9 . V_11 ) ) ;
V_9 . V_14 = F_7 ( struct V_8 , V_15 ) ;
V_9 . signal = V_2 -> V_16 -> V_17 ;
F_8 ( V_2 -> V_15 , & V_9 ) ;
if ( ( V_9 . V_18 + V_9 . V_19 + 1 ) * V_20 > V_2 -> V_21 )
V_9 . V_18 = 0 ;
if ( ( V_9 . V_19 + 1 ) * V_20 > V_2 -> V_21 )
V_9 . V_19 = 0 ;
F_6 ( V_22 ) ;
if ( ! F_9 ( V_23 , F_3 ( V_9 ) , V_9 . V_18 << V_24 ) )
V_9 . V_18 = 0 ;
if ( ! F_9 ( V_23 , F_4 ( V_9 ) , V_9 . V_19 << V_24 ) )
V_9 . V_19 = 0 ;
F_6 ( V_10 ) ;
if ( ! F_10 ( V_3 , & V_9 , sizeof( V_9 ) ) )
goto V_25;
if ( ! F_11 ( V_2 -> V_3 , V_20 - sizeof( V_9 ) ) )
goto V_25;
F_6 ( V_22 ) ;
if ( V_9 . V_18 != 0 ) {
V_6 = F_3 ( V_9 ) ;
V_7 = V_9 . V_18 << V_24 ;
if ( ! F_10 ( V_3 , V_6 , V_7 ) )
goto V_25;
}
if ( V_9 . V_19 != 0 ) {
V_6 = F_4 ( V_9 ) ;
V_7 = V_9 . V_19 << V_24 ;
if ( ! F_10 ( V_3 , V_6 , V_7 ) )
goto V_25;
}
V_25:
F_6 ( V_4 ) ;
return V_5 ;
}
static int F_12 ( unsigned long V_26 , unsigned long V_27 )
{
V_26 = F_13 ( V_26 ) ;
V_27 = F_13 ( V_27 ) ;
if ( V_27 > V_26 ) {
unsigned long V_28 ;
V_28 = F_14 ( V_26 , V_27 - V_26 ) ;
if ( F_15 ( V_28 ) )
return V_28 ;
}
return 0 ;
}
static unsigned long T_2 * F_16 ( char T_2 * V_29 , struct V_30 * V_31 )
{
char T_2 * T_2 * V_32 ;
char T_2 * T_2 * V_33 ;
unsigned long T_2 * V_34 ;
int V_35 = V_31 -> V_35 ;
int V_36 = V_31 -> V_36 ;
V_34 = ( void T_2 * ) ( ( - ( unsigned long ) sizeof( char * ) ) & ( unsigned long ) V_29 ) ;
#ifdef F_2
F_17 ( 0 , -- V_34 ) ;
F_17 ( 0 , -- V_34 ) ;
if ( V_31 -> V_37 ) {
F_17 ( 0 , -- V_34 ) ;
F_17 ( 1003 , -- V_34 ) ;
F_17 ( V_31 -> V_37 , -- V_34 ) ;
F_17 ( 1002 , -- V_34 ) ;
}
F_17 ( V_31 -> V_38 , -- V_34 ) ;
F_17 ( 1001 , -- V_34 ) ;
#endif
V_34 -= V_36 + 1 ;
V_33 = ( char T_2 * T_2 * ) V_34 ;
V_34 -= V_35 + 1 ;
V_32 = ( char T_2 * T_2 * ) V_34 ;
#ifndef F_2
F_17 ( ( unsigned long ) V_33 , -- V_34 ) ;
F_17 ( ( unsigned long ) V_32 , -- V_34 ) ;
#endif
F_17 ( V_35 , -- V_34 ) ;
V_12 -> V_39 -> V_40 = ( unsigned long ) V_29 ;
while ( V_35 -- > 0 ) {
char V_41 ;
F_17 ( V_29 , V_32 ++ ) ;
do {
F_18 ( V_41 , V_29 ++ ) ;
} while ( V_41 );
}
F_17 ( NULL , V_32 ) ;
V_12 -> V_39 -> V_42 = V_12 -> V_39 -> V_43 = ( unsigned long ) V_29 ;
while ( V_36 -- > 0 ) {
char V_41 ;
F_17 ( V_29 , V_33 ++ ) ;
do {
F_18 ( V_41 , V_29 ++ ) ;
} while ( V_41 );
}
F_17 ( NULL , V_33 ) ;
V_12 -> V_39 -> V_44 = ( unsigned long ) V_29 ;
return V_34 ;
}
static int F_19 ( struct V_30 * V_31 )
{
struct V_45 * V_15 = F_20 () ;
struct V_38 V_46 ;
unsigned long error ;
unsigned long V_47 ;
unsigned long V_48 ;
int V_49 ;
V_46 = * ( (struct V_38 * ) V_31 -> V_50 ) ;
if ( ( F_21 ( V_46 ) != V_51 && F_21 ( V_46 ) != V_52 &&
F_21 ( V_46 ) != V_53 && F_21 ( V_46 ) != V_54 ) ||
F_22 ( V_46 ) || F_23 ( V_46 ) ||
F_24 ( F_25 ( V_31 -> V_3 ) ) < V_46 . V_55 + V_46 . V_56 + F_26 ( V_46 ) + F_27 ( V_46 ) ) {
return - V_57 ;
}
if ( ! V_31 -> V_3 -> V_58 || ! V_31 -> V_3 -> V_58 -> V_59 )
return - V_57 ;
V_47 = F_27 ( V_46 ) ;
V_48 = F_28 ( V_60 ) ;
if ( V_48 >= V_61 )
V_48 = ~ 0 ;
if ( V_46 . V_56 + V_46 . V_62 > V_48 )
return - V_63 ;
V_49 = F_29 ( V_31 ) ;
if ( V_49 )
return V_49 ;
#ifdef F_2
F_30 ( V_31 , V_46 ) ;
#else
F_31 ( V_64 ) ;
#endif
F_32 ( V_31 ) ;
V_12 -> V_39 -> V_65 = V_46 . V_55 +
( V_12 -> V_39 -> V_66 = F_33 ( V_46 ) ) ;
V_12 -> V_39 -> V_67 = V_46 . V_56 +
( V_12 -> V_39 -> V_68 = F_34 ( V_46 ) ) ;
V_12 -> V_39 -> V_69 = V_46 . V_62 +
( V_12 -> V_39 -> V_70 = F_35 ( V_46 ) ) ;
V_12 -> V_39 -> V_71 = V_12 -> V_39 -> V_72 ;
V_12 -> V_39 -> V_73 = 0 ;
V_49 = F_36 ( V_31 , V_74 , V_75 ) ;
if ( V_49 < 0 ) {
F_37 ( V_76 , V_12 , 0 ) ;
return V_49 ;
}
F_38 ( V_31 ) ;
if ( F_21 ( V_46 ) == V_52 ) {
unsigned long V_77 , V_78 ;
T_4 V_79 ;
V_77 = F_33 ( V_46 ) ;
#ifdef F_2
V_79 = V_47 ;
V_78 = V_46 . V_55 + V_46 . V_56 + V_20 - 1 ;
#else
V_79 = 32 ;
V_78 = V_46 . V_55 + V_46 . V_56 ;
#endif
error = F_14 ( V_77 & V_80 , V_78 ) ;
if ( error != ( V_77 & V_80 ) ) {
F_37 ( V_76 , V_12 , 0 ) ;
return error ;
}
error = F_39 ( V_31 -> V_3 , V_77 , V_79 ,
V_46 . V_55 + V_46 . V_56 ) ;
if ( ( signed long ) error < 0 ) {
F_37 ( V_76 , V_12 , 0 ) ;
return error ;
}
} else {
if ( ( V_46 . V_55 & 0xfff || V_46 . V_56 & 0xfff ) &&
( F_21 ( V_46 ) != V_54 ) && F_40 () )
{
F_41 ( V_81 L_1 ) ;
}
if ( ( V_47 & ~ V_80 ) != 0 && F_40 () )
{
F_41 ( V_82
L_2 ,
V_31 -> V_3 -> V_83 . V_84 -> V_85 . V_86 ) ;
}
if ( ! V_31 -> V_3 -> V_58 -> V_59 || ( ( V_47 & ~ V_80 ) != 0 ) ) {
F_14 ( F_33 ( V_46 ) , V_46 . V_55 + V_46 . V_56 ) ;
F_39 ( V_31 -> V_3 , F_33 ( V_46 ) , V_47 ,
V_46 . V_55 + V_46 . V_56 ) ;
goto V_87;
}
error = F_42 ( V_31 -> V_3 , F_33 ( V_46 ) , V_46 . V_55 ,
V_88 | V_89 ,
V_90 | V_91 | V_92 | V_93 ,
V_47 ) ;
if ( error != F_33 ( V_46 ) ) {
F_37 ( V_76 , V_12 , 0 ) ;
return error ;
}
error = F_42 ( V_31 -> V_3 , F_34 ( V_46 ) , V_46 . V_56 ,
V_88 | V_94 | V_89 ,
V_90 | V_91 | V_92 | V_93 ,
V_47 + V_46 . V_55 ) ;
if ( error != F_34 ( V_46 ) ) {
F_37 ( V_76 , V_12 , 0 ) ;
return error ;
}
}
V_87:
F_43 ( & V_95 ) ;
V_49 = F_12 ( V_12 -> V_39 -> V_70 , V_12 -> V_39 -> V_69 ) ;
if ( V_49 < 0 ) {
F_37 ( V_76 , V_12 , 0 ) ;
return V_49 ;
}
V_12 -> V_39 -> V_96 =
( unsigned long ) F_16 ( ( char T_2 * ) V_31 -> V_29 , V_31 ) ;
#ifdef F_2
V_15 -> V_97 = V_46 . V_98 ;
#endif
F_44 ( V_15 , V_46 . V_99 , V_12 -> V_39 -> V_96 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_3 )
{
struct V_100 * V_100 ;
unsigned long V_101 , V_102 , V_103 ;
unsigned long error ;
int V_49 ;
struct V_38 V_46 ;
V_100 = F_25 ( V_3 ) ;
V_49 = - V_57 ;
error = F_46 ( V_3 , 0 , ( char * ) & V_46 , sizeof( V_46 ) ) ;
if ( error != sizeof( V_46 ) )
goto V_104;
if ( ( F_21 ( V_46 ) != V_51 && F_21 ( V_46 ) != V_53 ) || F_22 ( V_46 ) ||
F_23 ( V_46 ) || ( ( V_46 . V_99 & 0xfff ) && F_21 ( V_46 ) == V_51 ) ||
F_24 ( V_100 ) < V_46 . V_55 + V_46 . V_56 + F_26 ( V_46 ) + F_27 ( V_46 ) ) {
goto V_104;
}
if ( ! V_3 -> V_58 || ! V_3 -> V_58 -> V_59 )
goto V_104;
if ( F_47 ( V_46 ) )
goto V_104;
V_102 = V_46 . V_99 & 0xfffff000 ;
if ( ( F_27 ( V_46 ) & ~ V_80 ) != 0 ) {
if ( F_40 () )
{
F_41 ( V_82
L_3 ,
V_3 -> V_83 . V_84 -> V_85 . V_86 ) ;
}
F_14 ( V_102 , V_46 . V_55 + V_46 . V_56 + V_46 . V_62 ) ;
F_39 ( V_3 , V_102 , F_27 ( V_46 ) ,
V_46 . V_55 + V_46 . V_56 ) ;
V_49 = 0 ;
goto V_104;
}
error = F_42 ( V_3 , V_102 , V_46 . V_55 + V_46 . V_56 ,
V_88 | V_94 | V_89 ,
V_90 | V_91 | V_92 ,
F_27 ( V_46 ) ) ;
V_49 = error ;
if ( error != V_102 )
goto V_104;
V_103 = F_13 ( V_46 . V_55 + V_46 . V_56 ) ;
V_101 = V_46 . V_55 + V_46 . V_56 + V_46 . V_62 ;
if ( V_101 > V_103 ) {
error = F_14 ( V_102 + V_103 , V_101 - V_103 ) ;
V_49 = error ;
if ( error != V_102 + V_103 )
goto V_104;
}
V_49 = 0 ;
V_104:
return V_49 ;
}
static int T_5 F_48 ( void )
{
F_49 ( & V_95 ) ;
return 0 ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_95 ) ;
}
