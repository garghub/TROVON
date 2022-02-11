static inline int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
int V_4 = 0 ;
if ( ! F_2 ( V_2 ) ) {
F_3 () ;
if ( F_4 () && F_5 ( V_2 , V_3 ) )
V_4 = 1 ;
F_6 () ;
}
return V_4 ;
}
static inline int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
return 0 ;
}
void F_7 ( struct V_5 * V_6 , unsigned long V_7 )
{
T_1 * V_8 ;
if ( ! V_6 )
V_6 = & V_9 ;
F_8 ( L_1 , V_6 -> V_8 ) ;
V_8 = F_9 ( V_6 , V_7 ) ;
F_8 ( L_2 ,
V_7 , ( long long ) F_10 ( * V_8 ) ) ;
do {
T_2 * V_10 ;
T_3 * V_11 ;
T_4 * V_12 ;
if ( F_11 ( * V_8 ) )
break;
if ( F_12 ( * V_8 ) ) {
F_13 ( L_3 ) ;
break;
}
V_10 = F_14 ( V_8 , V_7 ) ;
if ( V_13 != 1 )
F_13 ( L_4 , ( long long ) F_15 ( * V_10 ) ) ;
if ( F_16 ( * V_10 ) )
break;
if ( F_17 ( * V_10 ) ) {
F_13 ( L_3 ) ;
break;
}
V_11 = F_18 ( V_10 , V_7 ) ;
if ( V_14 != 1 )
F_13 ( L_5 , ( long long ) F_19 ( * V_11 ) ) ;
if ( F_20 ( * V_11 ) )
break;
if ( F_21 ( * V_11 ) ) {
F_13 ( L_3 ) ;
break;
}
if ( F_22 ( F_23 ( F_19 ( * V_11 ) >> V_15 ) ) )
break;
V_12 = F_24 ( V_11 , V_7 ) ;
F_13 ( L_6 , ( long long ) F_25 ( * V_12 ) ) ;
#ifndef F_26
F_13 ( L_7 ,
( long long ) F_25 ( V_12 [ V_16 ] ) ) ;
#endif
F_27 ( V_12 ) ;
} while( 0 );
F_13 ( L_8 ) ;
}
void F_7 ( struct V_5 * V_6 , unsigned long V_7 )
{ }
static void
F_28 ( struct V_5 * V_6 , unsigned long V_7 , unsigned int V_3 ,
struct V_1 * V_2 )
{
if ( F_29 ( V_2 ) )
return;
F_30 ( 1 ) ;
F_8 ( L_9 ,
( V_7 < V_17 ) ? L_10 :
L_11 , V_7 ) ;
F_7 ( V_6 , V_7 ) ;
F_31 ( L_12 , V_2 , V_3 ) ;
F_30 ( 0 ) ;
F_32 ( V_18 ) ;
}
static void
F_33 ( struct V_19 * V_20 , unsigned long V_7 ,
unsigned int V_3 , unsigned int V_21 , int V_22 ,
struct V_1 * V_2 )
{
struct V_23 V_24 ;
#ifdef F_34
if ( ( ( V_25 & V_26 ) && ( V_21 == V_27 ) ) ||
( ( V_25 & V_28 ) && ( V_21 == V_29 ) ) ) {
F_35 ( V_30 L_13 ,
V_20 -> V_31 , V_21 , V_7 , V_3 ) ;
F_7 ( V_20 -> V_6 , V_7 ) ;
F_36 ( V_2 ) ;
}
#endif
V_20 -> V_32 . V_33 = V_7 ;
V_20 -> V_32 . V_34 = V_3 ;
V_20 -> V_32 . V_35 = 14 ;
V_24 . V_36 = V_21 ;
V_24 . V_37 = 0 ;
V_24 . V_38 = V_22 ;
V_24 . V_39 = ( void V_40 * ) V_7 ;
F_37 ( V_21 , & V_24 , V_20 ) ;
}
void F_38 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
struct V_19 * V_20 = V_41 ;
struct V_5 * V_6 = V_20 -> V_42 ;
if ( F_2 ( V_2 ) )
F_33 ( V_20 , V_7 , V_3 , V_27 , V_43 , V_2 ) ;
else
F_28 ( V_6 , V_7 , V_3 , V_2 ) ;
}
static inline bool F_39 ( unsigned int V_3 , struct V_44 * V_45 )
{
unsigned int V_46 = V_47 | V_48 | V_49 ;
if ( V_3 & V_50 )
V_46 = V_48 ;
if ( V_3 & V_51 )
V_46 = V_49 ;
return V_45 -> V_52 & V_46 ? false : true ;
}
static int T_5
F_40 ( struct V_5 * V_6 , unsigned long V_7 , unsigned int V_3 ,
unsigned int V_53 , struct V_19 * V_20 )
{
struct V_44 * V_45 ;
int V_54 ;
V_45 = F_41 ( V_6 , V_7 ) ;
V_54 = V_55 ;
if ( F_42 ( ! V_45 ) )
goto V_56;
if ( F_42 ( V_45 -> V_57 > V_7 ) )
goto V_58;
V_59:
if ( F_39 ( V_3 , V_45 ) ) {
V_54 = V_60 ;
goto V_56;
}
return F_43 ( V_45 , V_7 & V_61 , V_53 ) ;
V_58:
if ( V_45 -> V_52 & V_62 &&
V_7 >= V_63 && ! F_44 ( V_45 , V_7 ) )
goto V_59;
V_56:
return V_54 ;
}
static int T_5
F_45 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
struct V_19 * V_20 ;
struct V_5 * V_6 ;
int V_54 , V_21 , V_22 ;
unsigned int V_53 = V_64 | V_65 ;
if ( F_1 ( V_2 , V_3 ) )
return 0 ;
V_20 = V_41 ;
V_6 = V_20 -> V_6 ;
if ( F_46 ( V_2 ) )
F_47 () ;
if ( F_48 () || ! V_6 )
goto V_66;
if ( F_2 ( V_2 ) )
V_53 |= V_67 ;
if ( V_3 & V_50 )
V_53 |= V_68 ;
if ( ! F_49 ( & V_6 -> V_69 ) ) {
if ( ! F_2 ( V_2 ) && ! F_50 ( V_2 -> V_70 ) )
goto V_66;
V_71:
F_51 ( & V_6 -> V_69 ) ;
} else {
F_52 () ;
#ifdef F_53
if ( ! F_2 ( V_2 ) &&
! F_50 ( V_2 -> V_70 ) )
goto V_66;
#endif
}
V_54 = F_40 ( V_6 , V_7 , V_3 , V_53 , V_20 ) ;
if ( ( V_54 & V_72 ) && F_54 ( V_41 ) )
return 0 ;
F_55 ( V_73 , 1 , V_2 , V_7 ) ;
if ( ! ( V_54 & V_74 ) && V_53 & V_64 ) {
if ( V_54 & V_75 ) {
V_20 -> V_76 ++ ;
F_55 ( V_77 , 1 ,
V_2 , V_7 ) ;
} else {
V_20 -> V_78 ++ ;
F_55 ( V_79 , 1 ,
V_2 , V_7 ) ;
}
if ( V_54 & V_72 ) {
V_53 &= ~ V_64 ;
V_53 |= V_80 ;
goto V_71;
}
}
F_56 ( & V_6 -> V_69 ) ;
if ( F_57 ( ! ( V_54 & ( V_74 | V_55 | V_60 ) ) ) )
return 0 ;
if ( ! F_2 ( V_2 ) )
goto V_66;
if ( V_54 & V_81 ) {
F_58 () ;
return 0 ;
}
if ( V_54 & V_82 ) {
V_21 = V_29 ;
V_22 = V_83 ;
} else {
V_21 = V_27 ;
V_22 = V_54 == V_60 ?
V_84 : V_43 ;
}
F_33 ( V_20 , V_7 , V_3 , V_21 , V_22 , V_2 ) ;
return 0 ;
V_66:
F_28 ( V_6 , V_7 , V_3 , V_2 ) ;
return 0 ;
}
static int
F_45 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int T_5
F_59 ( unsigned long V_7 , unsigned int V_3 ,
struct V_1 * V_2 )
{
unsigned int V_85 ;
T_1 * V_8 , * V_86 ;
T_2 * V_10 , * V_87 ;
T_3 * V_11 , * V_88 ;
if ( V_7 < V_89 )
return F_45 ( V_7 , V_3 , V_2 ) ;
if ( F_2 ( V_2 ) )
goto V_90;
V_85 = F_60 ( V_7 ) ;
V_8 = F_61 () + V_85 ;
V_86 = V_9 . V_8 + V_85 ;
if ( F_11 ( * V_86 ) )
goto V_90;
if ( ! F_62 ( * V_8 ) )
F_63 ( V_8 , * V_86 ) ;
V_10 = F_14 ( V_8 , V_7 ) ;
V_87 = F_14 ( V_86 , V_7 ) ;
if ( F_16 ( * V_87 ) )
goto V_90;
if ( ! F_64 ( * V_10 ) )
F_65 ( V_10 , * V_87 ) ;
V_11 = F_18 ( V_10 , V_7 ) ;
V_88 = F_18 ( V_87 , V_7 ) ;
#ifdef F_26
V_85 = 0 ;
#else
V_85 = ( V_7 >> V_91 ) & 1 ;
#endif
if ( F_20 ( V_88 [ V_85 ] ) )
goto V_90;
F_66 ( V_11 , V_88 ) ;
return 0 ;
V_90:
F_38 ( V_7 , V_3 , V_2 ) ;
return 0 ;
}
static int
F_59 ( unsigned long V_7 , unsigned int V_3 ,
struct V_1 * V_2 )
{
return 0 ;
}
static int
F_67 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
F_38 ( V_7 , V_3 , V_2 ) ;
return 0 ;
}
static int
F_68 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
return 1 ;
}
void T_6
F_69 ( int V_92 , int (* F_70)( unsigned long , unsigned int , struct V_1 * ) ,
int V_21 , int V_22 , const char * V_93 )
{
if ( V_92 < 0 || V_92 >= F_71 ( V_94 ) )
F_72 () ;
V_94 [ V_92 ] . F_70 = F_70 ;
V_94 [ V_92 ] . V_21 = V_21 ;
V_94 [ V_92 ] . V_22 = V_22 ;
V_94 [ V_92 ] . V_93 = V_93 ;
}
T_7 void T_8
F_73 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
const struct V_94 * V_95 = V_94 + F_74 ( V_3 ) ;
struct V_23 V_96 ;
if ( ! V_95 -> F_70 ( V_7 , V_3 & ~ V_51 , V_2 ) )
return;
F_8 ( L_14 ,
V_95 -> V_93 , V_3 , V_7 ) ;
F_7 ( V_41 -> V_6 , V_7 ) ;
V_96 . V_36 = V_95 -> V_21 ;
V_96 . V_37 = 0 ;
V_96 . V_38 = V_95 -> V_22 ;
V_96 . V_39 = ( void V_40 * ) V_7 ;
F_75 ( L_15 , V_2 , & V_96 , V_3 , 0 ) ;
}
void T_6
F_76 ( int V_92 , int (* F_70)( unsigned long , unsigned int , struct V_1 * ) ,
int V_21 , int V_22 , const char * V_93 )
{
if ( V_92 < 0 || V_92 >= F_71 ( V_97 ) )
F_72 () ;
V_97 [ V_92 ] . F_70 = F_70 ;
V_97 [ V_92 ] . V_21 = V_21 ;
V_97 [ V_92 ] . V_22 = V_22 ;
V_97 [ V_92 ] . V_93 = V_93 ;
}
T_7 void T_8
F_77 ( unsigned long V_7 , unsigned int V_98 , struct V_1 * V_2 )
{
const struct V_94 * V_95 = V_97 + F_74 ( V_98 ) ;
struct V_23 V_96 ;
if ( ! V_95 -> F_70 ( V_7 , V_98 | V_51 , V_2 ) )
return;
F_8 ( L_16 ,
V_95 -> V_93 , V_98 , V_7 ) ;
V_96 . V_36 = V_95 -> V_21 ;
V_96 . V_37 = 0 ;
V_96 . V_38 = V_95 -> V_22 ;
V_96 . V_39 = ( void V_40 * ) V_7 ;
F_75 ( L_15 , V_2 , & V_96 , V_98 , 0 ) ;
}
static int T_6 F_78 ( unsigned long V_7 , unsigned int V_3 ,
struct V_1 * V_2 )
{
F_79 ( L_17
L_18
L_19 , V_3 ) ;
return 0 ;
}
void T_6 F_80 ( void )
{
V_94 [ V_99 ] . F_70 = F_78 ;
F_81 () ;
V_94 [ V_99 ] . F_70 = F_68 ;
}
static int T_6 F_82 ( void )
{
if ( F_83 () >= V_100 ) {
F_69 ( 4 , F_59 , V_27 , V_43 ,
L_20 ) ;
}
if ( F_83 () >= V_101 ) {
F_69 ( 3 , F_68 , V_27 , V_43 ,
L_21 ) ;
F_69 ( 6 , F_68 , V_27 , V_43 ,
L_21 ) ;
}
return 0 ;
}
