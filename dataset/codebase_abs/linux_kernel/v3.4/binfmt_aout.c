static int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
V_1 = F_2 ( V_1 ) ;
V_2 = F_2 ( V_2 ) ;
if ( V_2 > V_1 ) {
unsigned long V_3 ;
V_3 = F_3 ( V_1 , V_2 - V_1 ) ;
if ( F_4 ( V_3 ) )
return V_3 ;
}
return 0 ;
}
static int F_5 ( struct V_4 * V_5 )
{
struct V_6 * V_6 = V_5 -> V_6 ;
T_1 V_7 ;
int V_8 = 0 ;
void T_2 * V_9 ;
int V_10 ;
struct V_11 V_12 ;
#ifdef F_6
# define F_7 ( T_3 ) ((void __user *)u.start_data)
#else
# define F_7 ( T_3 ) ((void __user *)((u.u_tsize << PAGE_SHIFT) + \
u.start_code))
#endif
# define F_8 ( T_3 ) ((void __user *)u.start_stack)
V_7 = F_9 () ;
F_10 ( V_13 ) ;
V_8 = 1 ;
V_14 -> V_15 |= V_16 ;
strncpy ( V_12 . V_17 , V_14 -> V_18 , sizeof( V_12 . V_17 ) ) ;
V_12 . V_19 = F_11 ( struct V_11 , V_20 ) ;
V_12 . signal = V_5 -> V_21 ;
F_12 ( V_5 -> V_20 , & V_12 ) ;
if ( ( V_12 . V_22 + V_12 . V_23 + 1 ) * V_24 > V_5 -> V_25 )
V_12 . V_22 = 0 ;
if ( ( V_12 . V_23 + 1 ) * V_24 > V_5 -> V_25 )
V_12 . V_23 = 0 ;
F_10 ( V_26 ) ;
if ( ! F_13 ( V_27 , F_7 ( V_12 ) , V_12 . V_22 << V_28 ) )
V_12 . V_22 = 0 ;
if ( ! F_13 ( V_27 , F_8 ( V_12 ) , V_12 . V_23 << V_28 ) )
V_12 . V_23 = 0 ;
F_10 ( V_13 ) ;
if ( ! F_14 ( V_6 , & V_12 , sizeof( V_12 ) ) )
goto V_29;
if ( ! F_15 ( V_5 -> V_6 , V_24 - sizeof( V_12 ) ) )
goto V_29;
F_10 ( V_26 ) ;
if ( V_12 . V_22 != 0 ) {
V_9 = F_7 ( V_12 ) ;
V_10 = V_12 . V_22 << V_28 ;
if ( ! F_14 ( V_6 , V_9 , V_10 ) )
goto V_29;
}
if ( V_12 . V_23 != 0 ) {
V_9 = F_8 ( V_12 ) ;
V_10 = V_12 . V_23 << V_28 ;
if ( ! F_14 ( V_6 , V_9 , V_10 ) )
goto V_29;
}
V_29:
F_10 ( V_7 ) ;
return V_8 ;
}
static unsigned long T_2 * F_16 ( char T_2 * V_30 , struct V_31 * V_32 )
{
char T_2 * T_2 * V_33 ;
char T_2 * T_2 * V_34 ;
unsigned long T_2 * V_35 ;
int V_36 = V_32 -> V_36 ;
int V_37 = V_32 -> V_37 ;
V_35 = ( void T_2 * ) ( ( - ( unsigned long ) sizeof( char * ) ) & ( unsigned long ) V_30 ) ;
#ifdef F_6
F_17 ( 0 , -- V_35 ) ;
F_17 ( 0 , -- V_35 ) ;
if ( V_32 -> V_38 ) {
F_17 ( 0 , -- V_35 ) ;
F_17 ( 1003 , -- V_35 ) ;
F_17 ( V_32 -> V_38 , -- V_35 ) ;
F_17 ( 1002 , -- V_35 ) ;
}
F_17 ( V_32 -> V_39 , -- V_35 ) ;
F_17 ( 1001 , -- V_35 ) ;
#endif
V_35 -= V_37 + 1 ;
V_34 = ( char T_2 * T_2 * ) V_35 ;
V_35 -= V_36 + 1 ;
V_33 = ( char T_2 * T_2 * ) V_35 ;
#ifndef F_6
F_17 ( ( unsigned long ) V_34 , -- V_35 ) ;
F_17 ( ( unsigned long ) V_33 , -- V_35 ) ;
#endif
F_17 ( V_36 , -- V_35 ) ;
V_14 -> V_40 -> V_41 = ( unsigned long ) V_30 ;
while ( V_36 -- > 0 ) {
char V_42 ;
F_17 ( V_30 , V_33 ++ ) ;
do {
F_18 ( V_42 , V_30 ++ ) ;
} while ( V_42 );
}
F_17 ( NULL , V_33 ) ;
V_14 -> V_40 -> V_43 = V_14 -> V_40 -> V_44 = ( unsigned long ) V_30 ;
while ( V_37 -- > 0 ) {
char V_42 ;
F_17 ( V_30 , V_34 ++ ) ;
do {
F_18 ( V_42 , V_30 ++ ) ;
} while ( V_42 );
}
F_17 ( NULL , V_34 ) ;
V_14 -> V_40 -> V_45 = ( unsigned long ) V_30 ;
return V_35 ;
}
static int F_19 ( struct V_31 * V_32 , struct V_46 * V_20 )
{
struct V_39 V_47 ;
unsigned long error ;
unsigned long V_48 ;
unsigned long V_49 ;
int V_50 ;
V_47 = * ( (struct V_39 * ) V_32 -> V_51 ) ;
if ( ( F_20 ( V_47 ) != V_52 && F_20 ( V_47 ) != V_53 &&
F_20 ( V_47 ) != V_54 && F_20 ( V_47 ) != V_55 ) ||
F_21 ( V_47 ) || F_22 ( V_47 ) ||
F_23 ( V_32 -> V_6 -> V_56 . V_57 -> V_58 ) < V_47 . V_59 + V_47 . V_60 + F_24 ( V_47 ) + F_25 ( V_47 ) ) {
return - V_61 ;
}
if ( ! V_32 -> V_6 -> V_62 || ! V_32 -> V_6 -> V_62 -> V_63 )
return - V_61 ;
V_48 = F_25 ( V_47 ) ;
V_49 = F_26 ( V_64 ) ;
if ( V_49 >= V_65 )
V_49 = ~ 0 ;
if ( V_47 . V_60 + V_47 . V_66 > V_49 )
return - V_67 ;
V_50 = F_27 ( V_32 ) ;
if ( V_50 )
return V_50 ;
#ifdef F_6
F_28 ( V_32 , V_47 ) ;
#else
F_29 ( V_68 ) ;
#endif
F_30 ( V_32 ) ;
V_14 -> V_40 -> V_69 = V_47 . V_59 +
( V_14 -> V_40 -> V_70 = F_31 ( V_47 ) ) ;
V_14 -> V_40 -> V_71 = V_47 . V_60 +
( V_14 -> V_40 -> V_72 = F_32 ( V_47 ) ) ;
V_14 -> V_40 -> V_73 = V_47 . V_66 +
( V_14 -> V_40 -> V_74 = F_33 ( V_47 ) ) ;
V_14 -> V_40 -> V_75 = V_14 -> V_40 -> V_76 ;
V_14 -> V_40 -> V_77 = 0 ;
V_50 = F_34 ( V_32 , V_78 , V_79 ) ;
if ( V_50 < 0 ) {
F_35 ( V_80 , V_14 , 0 ) ;
return V_50 ;
}
F_36 ( V_32 ) ;
if ( F_20 ( V_47 ) == V_53 ) {
unsigned long V_81 , V_82 ;
T_4 V_83 ;
V_81 = F_31 ( V_47 ) ;
#ifdef F_6
V_83 = V_48 ;
V_82 = V_47 . V_59 + V_47 . V_60 + V_24 - 1 ;
#else
V_83 = 32 ;
V_82 = V_47 . V_59 + V_47 . V_60 ;
#endif
error = F_3 ( V_81 & V_84 , V_82 ) ;
if ( error != ( V_81 & V_84 ) ) {
F_35 ( V_80 , V_14 , 0 ) ;
return error ;
}
error = V_32 -> V_6 -> V_62 -> V_85 ( V_32 -> V_6 ,
( char T_2 * ) V_81 ,
V_47 . V_59 + V_47 . V_60 , & V_83 ) ;
if ( ( signed long ) error < 0 ) {
F_35 ( V_80 , V_14 , 0 ) ;
return error ;
}
F_37 ( V_81 , V_81 + V_47 . V_59 + V_47 . V_60 ) ;
} else {
if ( ( V_47 . V_59 & 0xfff || V_47 . V_60 & 0xfff ) &&
( F_20 ( V_47 ) != V_55 ) && F_38 () )
{
F_39 ( V_86 L_1 ) ;
}
if ( ( V_48 & ~ V_84 ) != 0 && F_38 () )
{
F_39 ( V_87
L_2 ,
V_32 -> V_6 -> V_56 . V_57 -> V_88 . V_89 ) ;
}
if ( ! V_32 -> V_6 -> V_62 -> V_63 || ( ( V_48 & ~ V_84 ) != 0 ) ) {
T_4 V_83 = V_48 ;
F_3 ( F_31 ( V_47 ) , V_47 . V_59 + V_47 . V_60 ) ;
V_32 -> V_6 -> V_62 -> V_85 ( V_32 -> V_6 ,
( char T_2 * ) F_31 ( V_47 ) ,
V_47 . V_59 + V_47 . V_60 , & V_83 ) ;
F_37 ( ( unsigned long ) F_31 ( V_47 ) ,
( unsigned long ) F_31 ( V_47 ) +
V_47 . V_59 + V_47 . V_60 ) ;
goto V_90;
}
error = F_40 ( V_32 -> V_6 , F_31 ( V_47 ) , V_47 . V_59 ,
V_91 | V_92 ,
V_93 | V_94 | V_95 | V_96 ,
V_48 ) ;
if ( error != F_31 ( V_47 ) ) {
F_35 ( V_80 , V_14 , 0 ) ;
return error ;
}
error = F_40 ( V_32 -> V_6 , F_32 ( V_47 ) , V_47 . V_60 ,
V_91 | V_97 | V_92 ,
V_93 | V_94 | V_95 | V_96 ,
V_48 + V_47 . V_59 ) ;
if ( error != F_32 ( V_47 ) ) {
F_35 ( V_80 , V_14 , 0 ) ;
return error ;
}
}
V_90:
F_41 ( & V_98 ) ;
V_50 = F_1 ( V_14 -> V_40 -> V_74 , V_14 -> V_40 -> V_73 ) ;
if ( V_50 < 0 ) {
F_35 ( V_80 , V_14 , 0 ) ;
return V_50 ;
}
V_14 -> V_40 -> V_99 =
( unsigned long ) F_16 ( ( char T_2 * ) V_32 -> V_30 , V_32 ) ;
#ifdef F_6
V_20 -> V_100 = V_47 . V_101 ;
#endif
F_42 ( V_20 , V_47 . V_102 , V_14 -> V_40 -> V_99 ) ;
return 0 ;
}
static int F_43 ( struct V_6 * V_6 )
{
struct V_103 * V_103 ;
unsigned long V_104 , V_105 , V_106 ;
unsigned long error ;
int V_50 ;
struct V_39 V_47 ;
V_103 = V_6 -> V_56 . V_57 -> V_58 ;
V_50 = - V_61 ;
error = F_44 ( V_6 , 0 , ( char * ) & V_47 , sizeof( V_47 ) ) ;
if ( error != sizeof( V_47 ) )
goto V_107;
if ( ( F_20 ( V_47 ) != V_52 && F_20 ( V_47 ) != V_54 ) || F_21 ( V_47 ) ||
F_22 ( V_47 ) || ( ( V_47 . V_102 & 0xfff ) && F_20 ( V_47 ) == V_52 ) ||
F_23 ( V_103 ) < V_47 . V_59 + V_47 . V_60 + F_24 ( V_47 ) + F_25 ( V_47 ) ) {
goto V_107;
}
if ( ! V_6 -> V_62 || ! V_6 -> V_62 -> V_63 )
goto V_107;
if ( F_45 ( V_47 ) )
goto V_107;
V_105 = V_47 . V_102 & 0xfffff000 ;
if ( ( F_25 ( V_47 ) & ~ V_84 ) != 0 ) {
T_4 V_83 = F_25 ( V_47 ) ;
if ( F_38 () )
{
F_39 ( V_87
L_3 ,
V_6 -> V_56 . V_57 -> V_88 . V_89 ) ;
}
F_3 ( V_105 , V_47 . V_59 + V_47 . V_60 + V_47 . V_66 ) ;
V_6 -> V_62 -> V_85 ( V_6 , ( char T_2 * ) V_105 ,
V_47 . V_59 + V_47 . V_60 , & V_83 ) ;
F_37 ( ( unsigned long ) V_105 ,
( unsigned long ) V_105 + V_47 . V_59 + V_47 . V_60 ) ;
V_50 = 0 ;
goto V_107;
}
error = F_40 ( V_6 , V_105 , V_47 . V_59 + V_47 . V_60 ,
V_91 | V_97 | V_92 ,
V_93 | V_94 | V_95 ,
F_25 ( V_47 ) ) ;
V_50 = error ;
if ( error != V_105 )
goto V_107;
V_106 = F_2 ( V_47 . V_59 + V_47 . V_60 ) ;
V_104 = V_47 . V_59 + V_47 . V_60 + V_47 . V_66 ;
if ( V_104 > V_106 ) {
error = F_3 ( V_105 + V_106 , V_104 - V_106 ) ;
V_50 = error ;
if ( error != V_105 + V_106 )
goto V_107;
}
V_50 = 0 ;
V_107:
return V_50 ;
}
static int T_5 F_46 ( void )
{
F_47 ( & V_98 ) ;
return 0 ;
}
static void T_6 F_48 ( void )
{
F_49 ( & V_98 ) ;
}
