static int F_1 ( unsigned long V_1 , unsigned long V_2 )
{
V_1 = F_2 ( V_1 ) ;
V_2 = F_2 ( V_2 ) ;
if ( V_2 > V_1 ) {
unsigned long V_3 ;
F_3 ( & V_4 -> V_5 -> V_6 ) ;
V_3 = F_4 ( V_1 , V_2 - V_1 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
if ( F_6 ( V_3 ) )
return V_3 ;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_9 * V_9 = V_8 -> V_9 ;
T_1 V_10 ;
int V_11 = 0 ;
void T_2 * V_12 ;
int V_13 ;
struct V_14 V_15 ;
#ifdef F_8
# define F_9 ( T_3 ) ((void __user *)u.start_data)
#else
# define F_9 ( T_3 ) ((void __user *)((u.u_tsize << PAGE_SHIFT) + \
u.start_code))
#endif
# define F_10 ( T_3 ) ((void __user *)u.start_stack)
V_10 = F_11 () ;
F_12 ( V_16 ) ;
V_11 = 1 ;
V_4 -> V_17 |= V_18 ;
strncpy ( V_15 . V_19 , V_4 -> V_20 , sizeof( V_15 . V_19 ) ) ;
V_15 . V_21 = F_13 ( struct V_14 , V_22 ) ;
V_15 . signal = V_8 -> V_23 ;
F_14 ( V_8 -> V_22 , & V_15 ) ;
if ( ( V_15 . V_24 + V_15 . V_25 + 1 ) * V_26 > V_8 -> V_27 )
V_15 . V_24 = 0 ;
if ( ( V_15 . V_25 + 1 ) * V_26 > V_8 -> V_27 )
V_15 . V_25 = 0 ;
F_12 ( V_28 ) ;
if ( ! F_15 ( V_29 , F_9 ( V_15 ) , V_15 . V_24 << V_30 ) )
V_15 . V_24 = 0 ;
if ( ! F_15 ( V_29 , F_10 ( V_15 ) , V_15 . V_25 << V_30 ) )
V_15 . V_25 = 0 ;
F_12 ( V_16 ) ;
if ( ! F_16 ( V_9 , & V_15 , sizeof( V_15 ) ) )
goto V_31;
if ( ! F_17 ( V_8 -> V_9 , V_26 - sizeof( V_15 ) ) )
goto V_31;
F_12 ( V_28 ) ;
if ( V_15 . V_24 != 0 ) {
V_12 = F_9 ( V_15 ) ;
V_13 = V_15 . V_24 << V_30 ;
if ( ! F_16 ( V_9 , V_12 , V_13 ) )
goto V_31;
}
if ( V_15 . V_25 != 0 ) {
V_12 = F_10 ( V_15 ) ;
V_13 = V_15 . V_25 << V_30 ;
if ( ! F_16 ( V_9 , V_12 , V_13 ) )
goto V_31;
}
V_31:
F_12 ( V_10 ) ;
return V_11 ;
}
static unsigned long T_2 * F_18 ( char T_2 * V_32 , struct V_33 * V_34 )
{
char T_2 * T_2 * V_35 ;
char T_2 * T_2 * V_36 ;
unsigned long T_2 * V_37 ;
int V_38 = V_34 -> V_38 ;
int V_39 = V_34 -> V_39 ;
V_37 = ( void T_2 * ) ( ( - ( unsigned long ) sizeof( char * ) ) & ( unsigned long ) V_32 ) ;
#ifdef F_8
F_19 ( 0 , -- V_37 ) ;
F_19 ( 0 , -- V_37 ) ;
if ( V_34 -> V_40 ) {
F_19 ( 0 , -- V_37 ) ;
F_19 ( 1003 , -- V_37 ) ;
F_19 ( V_34 -> V_40 , -- V_37 ) ;
F_19 ( 1002 , -- V_37 ) ;
}
F_19 ( V_34 -> V_41 , -- V_37 ) ;
F_19 ( 1001 , -- V_37 ) ;
#endif
V_37 -= V_39 + 1 ;
V_36 = ( char T_2 * T_2 * ) V_37 ;
V_37 -= V_38 + 1 ;
V_35 = ( char T_2 * T_2 * ) V_37 ;
#ifndef F_8
F_19 ( ( unsigned long ) V_36 , -- V_37 ) ;
F_19 ( ( unsigned long ) V_35 , -- V_37 ) ;
#endif
F_19 ( V_38 , -- V_37 ) ;
V_4 -> V_5 -> V_42 = ( unsigned long ) V_32 ;
while ( V_38 -- > 0 ) {
char V_43 ;
F_19 ( V_32 , V_35 ++ ) ;
do {
F_20 ( V_43 , V_32 ++ ) ;
} while ( V_43 );
}
F_19 ( NULL , V_35 ) ;
V_4 -> V_5 -> V_44 = V_4 -> V_5 -> V_45 = ( unsigned long ) V_32 ;
while ( V_39 -- > 0 ) {
char V_43 ;
F_19 ( V_32 , V_36 ++ ) ;
do {
F_20 ( V_43 , V_32 ++ ) ;
} while ( V_43 );
}
F_19 ( NULL , V_36 ) ;
V_4 -> V_5 -> V_46 = ( unsigned long ) V_32 ;
return V_37 ;
}
static int F_21 ( struct V_33 * V_34 , struct V_47 * V_22 )
{
struct V_41 V_48 ;
unsigned long error ;
unsigned long V_49 ;
unsigned long V_50 ;
int V_51 ;
V_48 = * ( (struct V_41 * ) V_34 -> V_52 ) ;
if ( ( F_22 ( V_48 ) != V_53 && F_22 ( V_48 ) != V_54 &&
F_22 ( V_48 ) != V_55 && F_22 ( V_48 ) != V_56 ) ||
F_23 ( V_48 ) || F_24 ( V_48 ) ||
F_25 ( V_34 -> V_9 -> V_57 . V_58 -> V_59 ) < V_48 . V_60 + V_48 . V_61 + F_26 ( V_48 ) + F_27 ( V_48 ) ) {
return - V_62 ;
}
if ( ! V_34 -> V_9 -> V_63 || ! V_34 -> V_9 -> V_63 -> V_64 )
return - V_62 ;
V_49 = F_27 ( V_48 ) ;
V_50 = F_28 ( V_65 ) ;
if ( V_50 >= V_66 )
V_50 = ~ 0 ;
if ( V_48 . V_61 + V_48 . V_67 > V_50 )
return - V_68 ;
V_51 = F_29 ( V_34 ) ;
if ( V_51 )
return V_51 ;
#ifdef F_8
F_30 ( V_34 , V_48 ) ;
#else
F_31 ( V_69 ) ;
#endif
F_32 ( V_34 ) ;
V_4 -> V_5 -> V_70 = V_48 . V_60 +
( V_4 -> V_5 -> V_71 = F_33 ( V_48 ) ) ;
V_4 -> V_5 -> V_72 = V_48 . V_61 +
( V_4 -> V_5 -> V_73 = F_34 ( V_48 ) ) ;
V_4 -> V_5 -> V_74 = V_48 . V_67 +
( V_4 -> V_5 -> V_75 = F_35 ( V_48 ) ) ;
V_4 -> V_5 -> V_76 = V_4 -> V_5 -> V_77 ;
V_4 -> V_5 -> V_78 = 0 ;
V_51 = F_36 ( V_34 , V_79 , V_80 ) ;
if ( V_51 < 0 ) {
F_37 ( V_81 , V_4 , 0 ) ;
return V_51 ;
}
F_38 ( V_34 ) ;
V_4 -> V_17 &= ~ V_82 ;
if ( F_22 ( V_48 ) == V_54 ) {
unsigned long V_83 , V_84 ;
T_4 V_85 ;
V_83 = F_33 ( V_48 ) ;
#ifdef F_8
V_85 = V_49 ;
V_84 = V_48 . V_60 + V_48 . V_61 + V_26 - 1 ;
#else
V_85 = 32 ;
V_84 = V_48 . V_60 + V_48 . V_61 ;
#endif
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_4 ( V_83 & V_86 , V_84 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
if ( error != ( V_83 & V_86 ) ) {
F_37 ( V_81 , V_4 , 0 ) ;
return error ;
}
error = V_34 -> V_9 -> V_63 -> V_87 ( V_34 -> V_9 ,
( char T_2 * ) V_83 ,
V_48 . V_60 + V_48 . V_61 , & V_85 ) ;
if ( ( signed long ) error < 0 ) {
F_37 ( V_81 , V_4 , 0 ) ;
return error ;
}
F_39 ( V_83 , V_83 + V_48 . V_60 + V_48 . V_61 ) ;
} else {
if ( ( V_48 . V_60 & 0xfff || V_48 . V_61 & 0xfff ) &&
( F_22 ( V_48 ) != V_56 ) && F_40 () )
{
F_41 ( V_88 L_1 ) ;
}
if ( ( V_49 & ~ V_86 ) != 0 && F_40 () )
{
F_41 ( V_89
L_2 ,
V_34 -> V_9 -> V_57 . V_58 -> V_90 . V_91 ) ;
}
if ( ! V_34 -> V_9 -> V_63 -> V_64 || ( ( V_49 & ~ V_86 ) != 0 ) ) {
T_4 V_85 = V_49 ;
F_3 ( & V_4 -> V_5 -> V_6 ) ;
F_4 ( F_33 ( V_48 ) , V_48 . V_60 + V_48 . V_61 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
V_34 -> V_9 -> V_63 -> V_87 ( V_34 -> V_9 ,
( char T_2 * ) F_33 ( V_48 ) ,
V_48 . V_60 + V_48 . V_61 , & V_85 ) ;
F_39 ( ( unsigned long ) F_33 ( V_48 ) ,
( unsigned long ) F_33 ( V_48 ) +
V_48 . V_60 + V_48 . V_61 ) ;
goto V_92;
}
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_42 ( V_34 -> V_9 , F_33 ( V_48 ) , V_48 . V_60 ,
V_93 | V_94 ,
V_95 | V_96 | V_97 | V_98 ,
V_49 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
if ( error != F_33 ( V_48 ) ) {
F_37 ( V_81 , V_4 , 0 ) ;
return error ;
}
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_42 ( V_34 -> V_9 , F_34 ( V_48 ) , V_48 . V_61 ,
V_93 | V_99 | V_94 ,
V_95 | V_96 | V_97 | V_98 ,
V_49 + V_48 . V_60 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
if ( error != F_34 ( V_48 ) ) {
F_37 ( V_81 , V_4 , 0 ) ;
return error ;
}
}
V_92:
F_43 ( & V_100 ) ;
V_51 = F_1 ( V_4 -> V_5 -> V_75 , V_4 -> V_5 -> V_74 ) ;
if ( V_51 < 0 ) {
F_37 ( V_81 , V_4 , 0 ) ;
return V_51 ;
}
V_4 -> V_5 -> V_101 =
( unsigned long ) F_18 ( ( char T_2 * ) V_34 -> V_32 , V_34 ) ;
#ifdef F_8
V_22 -> V_102 = V_48 . V_103 ;
#endif
F_44 ( V_22 , V_48 . V_104 , V_4 -> V_5 -> V_101 ) ;
return 0 ;
}
static int F_45 ( struct V_9 * V_9 )
{
struct V_105 * V_105 ;
unsigned long V_106 , V_107 , V_108 ;
unsigned long error ;
int V_51 ;
struct V_41 V_48 ;
V_105 = V_9 -> V_57 . V_58 -> V_59 ;
V_51 = - V_62 ;
error = F_46 ( V_9 , 0 , ( char * ) & V_48 , sizeof( V_48 ) ) ;
if ( error != sizeof( V_48 ) )
goto V_109;
if ( ( F_22 ( V_48 ) != V_53 && F_22 ( V_48 ) != V_55 ) || F_23 ( V_48 ) ||
F_24 ( V_48 ) || ( ( V_48 . V_104 & 0xfff ) && F_22 ( V_48 ) == V_53 ) ||
F_25 ( V_105 ) < V_48 . V_60 + V_48 . V_61 + F_26 ( V_48 ) + F_27 ( V_48 ) ) {
goto V_109;
}
if ( ! V_9 -> V_63 || ! V_9 -> V_63 -> V_64 )
goto V_109;
if ( F_47 ( V_48 ) )
goto V_109;
V_107 = V_48 . V_104 & 0xfffff000 ;
if ( ( F_27 ( V_48 ) & ~ V_86 ) != 0 ) {
T_4 V_85 = F_27 ( V_48 ) ;
if ( F_40 () )
{
F_41 ( V_89
L_3 ,
V_9 -> V_57 . V_58 -> V_90 . V_91 ) ;
}
F_3 ( & V_4 -> V_5 -> V_6 ) ;
F_4 ( V_107 , V_48 . V_60 + V_48 . V_61 + V_48 . V_67 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
V_9 -> V_63 -> V_87 ( V_9 , ( char T_2 * ) V_107 ,
V_48 . V_60 + V_48 . V_61 , & V_85 ) ;
F_39 ( ( unsigned long ) V_107 ,
( unsigned long ) V_107 + V_48 . V_60 + V_48 . V_61 ) ;
V_51 = 0 ;
goto V_109;
}
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_42 ( V_9 , V_107 , V_48 . V_60 + V_48 . V_61 ,
V_93 | V_99 | V_94 ,
V_95 | V_96 | V_97 ,
F_27 ( V_48 ) ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
V_51 = error ;
if ( error != V_107 )
goto V_109;
V_108 = F_2 ( V_48 . V_60 + V_48 . V_61 ) ;
V_106 = V_48 . V_60 + V_48 . V_61 + V_48 . V_67 ;
if ( V_106 > V_108 ) {
F_3 ( & V_4 -> V_5 -> V_6 ) ;
error = F_4 ( V_107 + V_108 , V_106 - V_108 ) ;
F_5 ( & V_4 -> V_5 -> V_6 ) ;
V_51 = error ;
if ( error != V_107 + V_108 )
goto V_109;
}
V_51 = 0 ;
V_109:
return V_51 ;
}
static int T_5 F_48 ( void )
{
return F_49 ( & V_100 ) ;
}
static void T_6 F_50 ( void )
{
F_51 ( & V_100 ) ;
}
