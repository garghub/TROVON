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
F_8 ( V_10 L_1 , V_6 -> V_8 ) ;
V_8 = F_9 ( V_6 , V_7 ) ;
F_8 ( V_10 L_2 ,
V_7 , ( long long ) F_10 ( * V_8 ) ) ;
do {
T_2 * V_11 ;
T_3 * V_12 ;
T_4 * V_13 ;
if ( F_11 ( * V_8 ) )
break;
if ( F_12 ( * V_8 ) ) {
F_8 ( L_3 ) ;
break;
}
V_11 = F_13 ( V_8 , V_7 ) ;
if ( V_14 != 1 )
F_8 ( L_4 , ( long long ) F_14 ( * V_11 ) ) ;
if ( F_15 ( * V_11 ) )
break;
if ( F_16 ( * V_11 ) ) {
F_8 ( L_3 ) ;
break;
}
V_12 = F_17 ( V_11 , V_7 ) ;
if ( V_15 != 1 )
F_8 ( L_5 , ( long long ) F_18 ( * V_12 ) ) ;
if ( F_19 ( * V_12 ) )
break;
if ( F_20 ( * V_12 ) ) {
F_8 ( L_3 ) ;
break;
}
if ( F_21 ( F_22 ( F_18 ( * V_12 ) >> V_16 ) ) )
break;
V_13 = F_23 ( V_12 , V_7 ) ;
F_8 ( L_6 , ( long long ) F_24 ( * V_13 ) ) ;
#ifndef F_25
F_8 ( L_7 ,
( long long ) F_24 ( V_13 [ V_17 ] ) ) ;
#endif
F_26 ( V_13 ) ;
} while( 0 );
F_8 ( L_8 ) ;
}
void F_7 ( struct V_5 * V_6 , unsigned long V_7 )
{ }
static void
F_27 ( struct V_5 * V_6 , unsigned long V_7 , unsigned int V_3 ,
struct V_1 * V_2 )
{
if ( F_28 ( V_2 ) )
return;
F_29 ( 1 ) ;
F_8 ( V_10
L_9 ,
( V_7 < V_18 ) ? L_10 :
L_11 , V_7 ) ;
F_7 ( V_6 , V_7 ) ;
F_30 ( L_12 , V_2 , V_3 ) ;
F_29 ( 0 ) ;
F_31 ( V_19 ) ;
}
static void
F_32 ( struct V_20 * V_21 , unsigned long V_7 ,
unsigned int V_3 , unsigned int V_22 , int V_23 ,
struct V_1 * V_2 )
{
struct V_24 V_25 ;
#ifdef F_33
if ( V_26 & V_27 ) {
F_8 ( V_28 L_13 ,
V_21 -> V_29 , V_22 , V_7 , V_3 ) ;
F_7 ( V_21 -> V_6 , V_7 ) ;
F_34 ( V_2 ) ;
}
#endif
V_21 -> V_30 . V_31 = V_7 ;
V_21 -> V_30 . V_32 = V_3 ;
V_21 -> V_30 . V_33 = 14 ;
V_25 . V_34 = V_22 ;
V_25 . V_35 = 0 ;
V_25 . V_36 = V_23 ;
V_25 . V_37 = ( void V_38 * ) V_7 ;
F_35 ( V_22 , & V_25 , V_21 ) ;
}
void F_36 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
struct V_20 * V_21 = V_39 ;
struct V_5 * V_6 = V_21 -> V_40 ;
if ( F_2 ( V_2 ) )
F_32 ( V_21 , V_7 , V_3 , V_41 , V_42 , V_2 ) ;
else
F_27 ( V_6 , V_7 , V_3 , V_2 ) ;
}
static inline bool F_37 ( unsigned int V_3 , struct V_43 * V_44 )
{
unsigned int V_45 = V_46 | V_47 | V_48 ;
if ( V_3 & V_49 )
V_45 = V_47 ;
if ( V_3 & V_50 )
V_45 = V_48 ;
return V_44 -> V_51 & V_45 ? false : true ;
}
static int T_5
F_38 ( struct V_5 * V_6 , unsigned long V_7 , unsigned int V_3 ,
unsigned int V_52 , struct V_20 * V_21 )
{
struct V_43 * V_44 ;
int V_53 ;
V_44 = F_39 ( V_6 , V_7 ) ;
V_53 = V_54 ;
if ( F_40 ( ! V_44 ) )
goto V_55;
if ( F_40 ( V_44 -> V_56 > V_7 ) )
goto V_57;
V_58:
if ( F_37 ( V_3 , V_44 ) ) {
V_53 = V_59 ;
goto V_55;
}
return F_41 ( V_6 , V_44 , V_7 & V_60 , V_52 ) ;
V_57:
if ( V_44 -> V_51 & V_61 && ! F_42 ( V_44 , V_7 ) )
goto V_58;
V_55:
return V_53 ;
}
static int T_5
F_43 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
struct V_20 * V_21 ;
struct V_5 * V_6 ;
int V_53 , V_22 , V_23 ;
int V_62 = V_3 & V_49 ;
unsigned int V_52 = V_63 | V_64 |
( V_62 ? V_65 : 0 ) ;
if ( F_1 ( V_2 , V_3 ) )
return 0 ;
V_21 = V_39 ;
V_6 = V_21 -> V_6 ;
if ( F_44 ( V_2 ) )
F_45 () ;
if ( F_46 () || ! V_6 )
goto V_66;
if ( ! F_47 ( & V_6 -> V_67 ) ) {
if ( ! F_2 ( V_2 ) && ! F_48 ( V_2 -> V_68 ) )
goto V_66;
V_69:
F_49 ( & V_6 -> V_67 ) ;
} else {
F_50 () ;
#ifdef F_51
if ( ! F_2 ( V_2 ) &&
! F_48 ( V_2 -> V_68 ) )
goto V_66;
#endif
}
V_53 = F_38 ( V_6 , V_7 , V_3 , V_52 , V_21 ) ;
if ( ( V_53 & V_70 ) && F_52 ( V_39 ) )
return 0 ;
F_53 ( V_71 , 1 , V_2 , V_7 ) ;
if ( V_52 & V_63 ) {
if ( V_53 & V_72 ) {
V_21 -> V_73 ++ ;
F_53 ( V_74 , 1 ,
V_2 , V_7 ) ;
} else {
V_21 -> V_75 ++ ;
F_53 ( V_76 , 1 ,
V_2 , V_7 ) ;
}
if ( V_53 & V_70 ) {
V_52 &= ~ V_63 ;
goto V_69;
}
}
F_54 ( & V_6 -> V_67 ) ;
if ( F_55 ( ! ( V_53 & ( V_77 | V_54 | V_59 ) ) ) )
return 0 ;
if ( V_53 & V_78 ) {
F_56 () ;
return 0 ;
}
if ( ! F_2 ( V_2 ) )
goto V_66;
if ( V_53 & V_79 ) {
V_22 = V_80 ;
V_23 = V_81 ;
} else {
V_22 = V_41 ;
V_23 = V_53 == V_59 ?
V_82 : V_42 ;
}
F_32 ( V_21 , V_7 , V_3 , V_22 , V_23 , V_2 ) ;
return 0 ;
V_66:
F_27 ( V_6 , V_7 , V_3 , V_2 ) ;
return 0 ;
}
static int
F_43 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
return 0 ;
}
static int T_5
F_57 ( unsigned long V_7 , unsigned int V_3 ,
struct V_1 * V_2 )
{
unsigned int V_83 ;
T_1 * V_8 , * V_84 ;
T_2 * V_11 , * V_85 ;
T_3 * V_12 , * V_86 ;
if ( V_7 < V_87 )
return F_43 ( V_7 , V_3 , V_2 ) ;
if ( F_2 ( V_2 ) )
goto V_88;
V_83 = F_58 ( V_7 ) ;
V_8 = F_59 () + V_83 ;
V_84 = V_9 . V_8 + V_83 ;
if ( F_11 ( * V_84 ) )
goto V_88;
if ( ! F_60 ( * V_8 ) )
F_61 ( V_8 , * V_84 ) ;
V_11 = F_13 ( V_8 , V_7 ) ;
V_85 = F_13 ( V_84 , V_7 ) ;
if ( F_15 ( * V_85 ) )
goto V_88;
if ( ! F_62 ( * V_11 ) )
F_63 ( V_11 , * V_85 ) ;
V_12 = F_17 ( V_11 , V_7 ) ;
V_86 = F_17 ( V_85 , V_7 ) ;
#ifdef F_25
V_83 = 0 ;
#else
V_83 = ( V_7 >> V_89 ) & 1 ;
#endif
if ( F_19 ( V_86 [ V_83 ] ) )
goto V_88;
F_64 ( V_12 , V_86 ) ;
return 0 ;
V_88:
F_36 ( V_7 , V_3 , V_2 ) ;
return 0 ;
}
static int
F_57 ( unsigned long V_7 , unsigned int V_3 ,
struct V_1 * V_2 )
{
return 0 ;
}
static int
F_65 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
F_36 ( V_7 , V_3 , V_2 ) ;
return 0 ;
}
static int
F_66 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
return 1 ;
}
void T_6
F_67 ( int V_90 , int (* F_68)( unsigned long , unsigned int , struct V_1 * ) ,
int V_22 , int V_23 , const char * V_91 )
{
if ( V_90 < 0 || V_90 >= F_69 ( V_92 ) )
F_70 () ;
V_92 [ V_90 ] . F_68 = F_68 ;
V_92 [ V_90 ] . V_22 = V_22 ;
V_92 [ V_90 ] . V_23 = V_23 ;
V_92 [ V_90 ] . V_91 = V_91 ;
}
T_7 void T_8
F_71 ( unsigned long V_7 , unsigned int V_3 , struct V_1 * V_2 )
{
const struct V_92 * V_93 = V_92 + F_72 ( V_3 ) ;
struct V_24 V_94 ;
if ( ! V_93 -> F_68 ( V_7 , V_3 & ~ V_50 , V_2 ) )
return;
F_8 ( V_10 L_14 ,
V_93 -> V_91 , V_3 , V_7 ) ;
V_94 . V_34 = V_93 -> V_22 ;
V_94 . V_35 = 0 ;
V_94 . V_36 = V_93 -> V_23 ;
V_94 . V_37 = ( void V_38 * ) V_7 ;
F_73 ( L_15 , V_2 , & V_94 , V_3 , 0 ) ;
}
void T_6
F_74 ( int V_90 , int (* F_68)( unsigned long , unsigned int , struct V_1 * ) ,
int V_22 , int V_23 , const char * V_91 )
{
if ( V_90 < 0 || V_90 >= F_69 ( V_95 ) )
F_70 () ;
V_95 [ V_90 ] . F_68 = F_68 ;
V_95 [ V_90 ] . V_22 = V_22 ;
V_95 [ V_90 ] . V_23 = V_23 ;
V_95 [ V_90 ] . V_91 = V_91 ;
}
T_7 void T_8
F_75 ( unsigned long V_7 , unsigned int V_96 , struct V_1 * V_2 )
{
const struct V_92 * V_93 = V_95 + F_72 ( V_96 ) ;
struct V_24 V_94 ;
if ( ! V_93 -> F_68 ( V_7 , V_96 | V_50 , V_2 ) )
return;
F_8 ( V_10 L_16 ,
V_93 -> V_91 , V_96 , V_7 ) ;
V_94 . V_34 = V_93 -> V_22 ;
V_94 . V_35 = 0 ;
V_94 . V_36 = V_93 -> V_23 ;
V_94 . V_37 = ( void V_38 * ) V_7 ;
F_73 ( L_15 , V_2 , & V_94 , V_96 , 0 ) ;
}
static int T_6 F_76 ( void )
{
if ( F_77 () >= V_97 ) {
F_67 ( 4 , F_57 , V_41 , V_42 ,
L_17 ) ;
}
if ( F_77 () >= V_98 ) {
F_67 ( 3 , F_66 , V_41 , V_42 ,
L_18 ) ;
F_67 ( 6 , F_66 , V_41 , V_42 ,
L_18 ) ;
}
return 0 ;
}
