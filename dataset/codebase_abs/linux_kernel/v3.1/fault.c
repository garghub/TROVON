static inline int F_1 ( unsigned int V_1 )
{
return ( V_1 & V_2 ) | ( V_1 & V_3 ) >> 6 ;
}
static inline int F_2 ( struct V_4 * V_5 , unsigned int V_1 )
{
int V_6 = 0 ;
if ( ! F_3 ( V_5 ) ) {
F_4 () ;
if ( F_5 () && F_6 ( V_5 , V_1 ) )
V_6 = 1 ;
F_7 () ;
}
return V_6 ;
}
static inline int F_2 ( struct V_4 * V_5 , unsigned int V_1 )
{
return 0 ;
}
void F_8 ( struct V_7 * V_8 , unsigned long V_9 )
{
T_1 * V_10 ;
if ( ! V_8 )
V_8 = & V_11 ;
F_9 ( V_12 L_1 , V_8 -> V_10 ) ;
V_10 = F_10 ( V_8 , V_9 ) ;
F_9 ( V_12 L_2 ,
V_9 , ( long long ) F_11 ( * V_10 ) ) ;
do {
T_2 * V_13 ;
T_3 * V_14 ;
T_4 * V_15 ;
if ( F_12 ( * V_10 ) )
break;
if ( F_13 ( * V_10 ) ) {
F_9 ( L_3 ) ;
break;
}
V_13 = F_14 ( V_10 , V_9 ) ;
if ( V_16 != 1 )
F_9 ( L_4 , ( long long ) F_15 ( * V_13 ) ) ;
if ( F_16 ( * V_13 ) )
break;
if ( F_17 ( * V_13 ) ) {
F_9 ( L_3 ) ;
break;
}
V_14 = F_18 ( V_13 , V_9 ) ;
if ( V_17 != 1 )
F_9 ( L_5 , ( long long ) F_19 ( * V_14 ) ) ;
if ( F_20 ( * V_14 ) )
break;
if ( F_21 ( * V_14 ) ) {
F_9 ( L_3 ) ;
break;
}
if ( F_22 ( F_23 ( F_19 ( * V_14 ) >> V_18 ) ) )
break;
V_15 = F_24 ( V_14 , V_9 ) ;
F_9 ( L_6 , ( long long ) F_25 ( * V_15 ) ) ;
F_9 ( L_7 ,
( long long ) F_25 ( V_15 [ V_19 ] ) ) ;
F_26 ( V_15 ) ;
} while( 0 );
F_9 ( L_8 ) ;
}
void F_8 ( struct V_7 * V_8 , unsigned long V_9 )
{ }
static void
F_27 ( struct V_7 * V_8 , unsigned long V_9 , unsigned int V_1 ,
struct V_4 * V_5 )
{
if ( F_28 ( V_5 ) )
return;
F_29 ( 1 ) ;
F_9 ( V_12
L_9 ,
( V_9 < V_20 ) ? L_10 :
L_11 , V_9 ) ;
F_8 ( V_8 , V_9 ) ;
F_30 ( L_12 , V_5 , V_1 ) ;
F_29 ( 0 ) ;
F_31 ( V_21 ) ;
}
static void
F_32 ( struct V_22 * V_23 , unsigned long V_9 ,
unsigned int V_1 , unsigned int V_24 , int V_25 ,
struct V_4 * V_5 )
{
struct V_26 V_27 ;
#ifdef F_33
if ( V_28 & V_29 ) {
F_9 ( V_30 L_13 ,
V_23 -> V_31 , V_24 , V_9 , V_1 ) ;
F_8 ( V_23 -> V_8 , V_9 ) ;
F_34 ( V_5 ) ;
}
#endif
V_23 -> V_32 . V_33 = V_9 ;
V_23 -> V_32 . V_34 = V_1 ;
V_23 -> V_32 . V_35 = 14 ;
V_27 . V_36 = V_24 ;
V_27 . V_37 = 0 ;
V_27 . V_38 = V_25 ;
V_27 . V_39 = ( void V_40 * ) V_9 ;
F_35 ( V_24 , & V_27 , V_23 ) ;
}
void F_36 ( unsigned long V_9 , unsigned int V_1 , struct V_4 * V_5 )
{
struct V_22 * V_23 = V_41 ;
struct V_7 * V_8 = V_23 -> V_42 ;
if ( F_3 ( V_5 ) )
F_32 ( V_23 , V_9 , V_1 , V_43 , V_44 , V_5 ) ;
else
F_27 ( V_8 , V_9 , V_1 , V_5 ) ;
}
static inline bool F_37 ( unsigned int V_1 , struct V_45 * V_46 )
{
unsigned int V_47 = V_48 | V_49 | V_50 ;
if ( V_1 & V_51 )
V_47 = V_49 ;
if ( V_1 & V_52 )
V_47 = V_50 ;
return V_46 -> V_53 & V_47 ? false : true ;
}
static int T_5
F_38 ( struct V_7 * V_8 , unsigned long V_9 , unsigned int V_1 ,
struct V_22 * V_23 )
{
struct V_45 * V_46 ;
int V_54 ;
V_46 = F_39 ( V_8 , V_9 ) ;
V_54 = V_55 ;
if ( F_40 ( ! V_46 ) )
goto V_56;
if ( F_40 ( V_46 -> V_57 > V_9 ) )
goto V_58;
V_59:
if ( F_37 ( V_1 , V_46 ) ) {
V_54 = V_60 ;
goto V_56;
}
V_54 = F_41 ( V_8 , V_46 , V_9 & V_61 , ( V_1 & V_51 ) ? V_62 : 0 ) ;
if ( F_40 ( V_54 & V_63 ) )
return V_54 ;
if ( V_54 & V_64 )
V_23 -> V_65 ++ ;
else
V_23 -> V_66 ++ ;
return V_54 ;
V_58:
if ( V_46 -> V_53 & V_67 && ! F_42 ( V_46 , V_9 ) )
goto V_59;
V_56:
return V_54 ;
}
static int T_5
F_43 ( unsigned long V_9 , unsigned int V_1 , struct V_4 * V_5 )
{
struct V_22 * V_23 ;
struct V_7 * V_8 ;
int V_54 , V_24 , V_25 ;
if ( F_2 ( V_5 , V_1 ) )
return 0 ;
V_23 = V_41 ;
V_8 = V_23 -> V_8 ;
if ( F_44 ( V_5 ) )
F_45 () ;
if ( F_46 () || ! V_8 )
goto V_68;
if ( ! F_47 ( & V_8 -> V_69 ) ) {
if ( ! F_3 ( V_5 ) && ! F_48 ( V_5 -> V_70 ) )
goto V_68;
F_49 ( & V_8 -> V_69 ) ;
} else {
F_50 () ;
#ifdef F_51
if ( ! F_3 ( V_5 ) &&
! F_48 ( V_5 -> V_70 ) )
goto V_68;
#endif
}
V_54 = F_38 ( V_8 , V_9 , V_1 , V_23 ) ;
F_52 ( & V_8 -> V_69 ) ;
F_53 ( V_71 , 1 , V_5 , V_9 ) ;
if ( V_54 & V_64 )
F_53 ( V_72 , 1 , V_5 , V_9 ) ;
else if ( V_54 & V_73 )
F_53 ( V_74 , 1 , V_5 , V_9 ) ;
if ( F_54 ( ! ( V_54 & ( V_63 | V_55 | V_60 ) ) ) )
return 0 ;
if ( V_54 & V_75 ) {
F_55 () ;
return 0 ;
}
if ( ! F_3 ( V_5 ) )
goto V_68;
if ( V_54 & V_76 ) {
V_24 = V_77 ;
V_25 = V_78 ;
} else {
V_24 = V_43 ;
V_25 = V_54 == V_60 ?
V_79 : V_44 ;
}
F_32 ( V_23 , V_9 , V_1 , V_24 , V_25 , V_5 ) ;
return 0 ;
V_68:
F_27 ( V_8 , V_9 , V_1 , V_5 ) ;
return 0 ;
}
static int
F_43 ( unsigned long V_9 , unsigned int V_1 , struct V_4 * V_5 )
{
return 0 ;
}
static int T_5
F_56 ( unsigned long V_9 , unsigned int V_1 ,
struct V_4 * V_5 )
{
unsigned int V_80 ;
T_1 * V_10 , * V_81 ;
T_2 * V_13 , * V_82 ;
T_3 * V_14 , * V_83 ;
if ( V_9 < V_84 )
return F_43 ( V_9 , V_1 , V_5 ) ;
if ( F_3 ( V_5 ) )
goto V_85;
V_80 = F_57 ( V_9 ) ;
V_10 = F_58 () + V_80 ;
V_81 = V_11 . V_10 + V_80 ;
if ( F_12 ( * V_81 ) )
goto V_85;
if ( ! F_59 ( * V_10 ) )
F_60 ( V_10 , * V_81 ) ;
V_13 = F_14 ( V_10 , V_9 ) ;
V_82 = F_14 ( V_81 , V_9 ) ;
if ( F_16 ( * V_82 ) )
goto V_85;
if ( ! F_61 ( * V_13 ) )
F_62 ( V_13 , * V_82 ) ;
V_14 = F_18 ( V_13 , V_9 ) ;
V_83 = F_18 ( V_82 , V_9 ) ;
V_80 = ( V_9 >> V_86 ) & 1 ;
if ( F_20 ( V_83 [ V_80 ] ) )
goto V_85;
F_63 ( V_14 , V_83 ) ;
return 0 ;
V_85:
F_36 ( V_9 , V_1 , V_5 ) ;
return 0 ;
}
static int
F_56 ( unsigned long V_9 , unsigned int V_1 ,
struct V_4 * V_5 )
{
return 0 ;
}
static int
F_64 ( unsigned long V_9 , unsigned int V_1 , struct V_4 * V_5 )
{
F_36 ( V_9 , V_1 , V_5 ) ;
return 0 ;
}
static int
F_65 ( unsigned long V_9 , unsigned int V_1 , struct V_4 * V_5 )
{
return 1 ;
}
void T_6
F_66 ( int V_87 , int (* F_67)( unsigned long , unsigned int , struct V_4 * ) ,
int V_24 , int V_25 , const char * V_88 )
{
if ( V_87 < 0 || V_87 >= F_68 ( V_89 ) )
F_69 () ;
V_89 [ V_87 ] . F_67 = F_67 ;
V_89 [ V_87 ] . V_24 = V_24 ;
V_89 [ V_87 ] . V_25 = V_25 ;
V_89 [ V_87 ] . V_88 = V_88 ;
}
T_7 void T_8
F_70 ( unsigned long V_9 , unsigned int V_1 , struct V_4 * V_5 )
{
const struct V_89 * V_90 = V_89 + F_1 ( V_1 ) ;
struct V_26 V_91 ;
if ( ! V_90 -> F_67 ( V_9 , V_1 & ~ V_52 , V_5 ) )
return;
F_9 ( V_12 L_14 ,
V_90 -> V_88 , V_1 , V_9 ) ;
V_91 . V_36 = V_90 -> V_24 ;
V_91 . V_37 = 0 ;
V_91 . V_38 = V_90 -> V_25 ;
V_91 . V_39 = ( void V_40 * ) V_9 ;
F_71 ( L_15 , V_5 , & V_91 , V_1 , 0 ) ;
}
void T_6
F_72 ( int V_87 , int (* F_67)( unsigned long , unsigned int , struct V_4 * ) ,
int V_24 , int V_25 , const char * V_88 )
{
if ( V_87 < 0 || V_87 >= F_68 ( V_92 ) )
F_69 () ;
V_92 [ V_87 ] . F_67 = F_67 ;
V_92 [ V_87 ] . V_24 = V_24 ;
V_92 [ V_87 ] . V_25 = V_25 ;
V_92 [ V_87 ] . V_88 = V_88 ;
}
T_7 void T_8
F_73 ( unsigned long V_9 , unsigned int V_93 , struct V_4 * V_5 )
{
const struct V_89 * V_90 = V_92 + F_1 ( V_93 ) ;
struct V_26 V_91 ;
if ( ! V_90 -> F_67 ( V_9 , V_93 | V_52 , V_5 ) )
return;
F_9 ( V_12 L_16 ,
V_90 -> V_88 , V_93 , V_9 ) ;
V_91 . V_36 = V_90 -> V_24 ;
V_91 . V_37 = 0 ;
V_91 . V_38 = V_90 -> V_25 ;
V_91 . V_39 = ( void V_40 * ) V_9 ;
F_71 ( L_15 , V_5 , & V_91 , V_93 , 0 ) ;
}
static int T_6 F_74 ( void )
{
if ( F_75 () >= V_94 ) {
F_66 ( 4 , F_56 , V_43 , V_44 ,
L_17 ) ;
}
if ( F_75 () >= V_95 ) {
F_66 ( 3 , F_65 , V_43 , V_44 ,
L_18 ) ;
F_66 ( 6 , F_65 , V_43 , V_44 ,
L_18 ) ;
}
return 0 ;
}
