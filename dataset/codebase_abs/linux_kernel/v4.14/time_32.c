unsigned long F_1 ( struct V_1 * V_2 )
{
extern char V_3 [] , V_4 [] ;
extern char V_5 [] , V_6 [] ;
unsigned long V_7 = V_2 -> V_7 ;
if ( F_2 ( V_7 ) ||
( V_7 >= ( unsigned long ) V_3 &&
V_7 < ( unsigned long ) V_4 ) ||
( V_7 >= ( unsigned long ) V_5 &&
V_7 < ( unsigned long ) V_6 ) )
V_7 = V_2 -> V_8 [ V_9 ] ;
return V_7 ;
}
T_1 T_2 F_3 ( int V_10 , void * V_11 )
{
if ( V_12 ) {
F_4 ( & V_13 ) ;
V_14 ++ ;
V_15 . V_16 () ;
F_5 ( & V_13 ) ;
} else {
V_15 . V_16 () ;
}
if ( V_17 )
V_18 . V_19 ( & V_18 ) ;
return V_20 ;
}
static int F_6 ( struct V_21 * V_22 )
{
V_17 = 0 ;
F_7 () ;
return 0 ;
}
static int F_8 ( struct V_21 * V_22 )
{
V_17 = 1 ;
F_7 () ;
return 0 ;
}
static T_3 void F_9 ( void )
{
struct V_21 * V_23 = & V_18 ;
F_10 ( F_11 () != V_24 ) ;
V_23 -> V_25 = L_1 ;
V_23 -> V_26 = 100 ;
V_23 -> V_27 = V_28 ;
V_23 -> V_29 = F_6 ;
V_23 -> V_30 = F_8 ;
V_23 -> V_31 = F_8 ;
V_23 -> V_32 = V_33 ;
V_23 -> V_34 = 32 ;
V_23 -> V_35 = F_12 ( V_15 . V_36 , V_37 ,
V_23 -> V_34 ) ;
F_13 ( V_23 ) ;
}
static unsigned int F_14 ( void )
{
T_4 V_38 , V_39 ;
V_38 = F_15 ( V_40 ) ;
V_39 = ( V_38 >> V_41 ) & V_42 ;
if ( V_38 & V_43 )
V_39 += V_15 . V_44 ;
return V_39 ;
}
static T_5 F_16 ( struct V_45 * V_46 )
{
unsigned int V_47 , V_39 ;
T_5 V_48 ;
do {
V_47 = F_17 ( & V_13 ) ;
V_48 = V_14 ;
V_39 = V_15 . V_49 () ;
} while ( F_18 ( & V_13 , V_47 ) );
V_48 *= V_15 . V_44 ;
V_48 += V_39 ;
return V_48 ;
}
static T_3 int F_19 ( void )
{
V_12 = 1 ;
return F_20 ( & V_50 , V_15 . V_36 ) ;
}
static int F_21 ( struct V_21 * V_22 )
{
int V_51 = F_22 ( V_22 -> V_32 ) ;
V_15 . V_52 ( V_51 , 0 ) ;
return 0 ;
}
static int F_23 ( struct V_21 * V_22 )
{
int V_51 = F_22 ( V_22 -> V_32 ) ;
V_15 . V_52 ( V_51 , V_53 / V_54 ) ;
return 0 ;
}
static int F_24 ( unsigned long V_55 ,
struct V_21 * V_22 )
{
int V_51 = F_22 ( V_22 -> V_32 ) ;
unsigned int V_56 = ( unsigned int ) V_55 ;
V_15 . V_52 ( V_51 , V_56 ) ;
return 0 ;
}
void F_25 ( int V_51 )
{
struct V_21 * V_23 = & F_26 ( V_57 , V_51 ) ;
unsigned int V_27 = V_28 ;
if ( V_15 . V_27 & V_58 )
V_27 |= V_59 ;
V_23 -> V_25 = L_2 ;
V_23 -> V_26 = 200 ;
V_23 -> V_27 = V_27 ;
V_23 -> V_29 = F_21 ;
V_23 -> V_30 = F_23 ;
V_23 -> V_60 = F_21 ;
V_23 -> V_61 = F_24 ;
V_23 -> V_32 = F_27 ( V_51 ) ;
V_23 -> V_34 = 32 ;
V_23 -> V_35 = F_12 ( V_15 . V_36 , V_37 ,
V_23 -> V_34 ) ;
V_23 -> V_62 = F_28 ( V_15 . V_36 , V_23 ) ;
V_23 -> V_63 = ( unsigned long ) V_15 . V_36 ;
V_23 -> V_64 = F_28 ( 100 , V_23 ) ;
V_23 -> V_65 = 100 ;
F_13 ( V_23 ) ;
}
static unsigned char F_29 ( struct V_66 * V_67 , T_4 V_68 )
{
struct V_69 * V_70 = F_30 ( V_67 ) ;
struct V_71 * V_72 = V_70 -> V_67 . V_73 ;
return F_31 ( V_72 -> V_74 + V_68 ) ;
}
static void F_32 ( struct V_66 * V_67 , T_4 V_68 , T_6 V_38 )
{
struct V_69 * V_70 = F_30 ( V_67 ) ;
struct V_71 * V_72 = V_70 -> V_67 . V_73 ;
F_33 ( V_38 , V_72 -> V_74 + V_68 ) ;
}
static int F_34 ( struct V_69 * V_75 )
{
struct V_76 * V_77 = V_75 -> V_67 . V_78 ;
const char * V_79 = F_35 ( V_77 , L_3 , NULL ) ;
if ( ! V_79 )
return - V_80 ;
if ( ! F_36 ( V_77 , L_4 , NULL ) )
return - V_80 ;
V_81 . V_82 = & V_75 -> V_82 [ 0 ] ;
if ( ! strcmp ( V_79 , L_5 ) ) {
V_83 . V_74 = F_37 ( & V_75 -> V_82 [ 0 ] , 0 ,
2048 , L_6 ) ;
V_83 . type = V_84 ;
} else if ( ! strcmp ( V_79 , L_7 ) ) {
V_83 . V_74 = F_37 ( & V_75 -> V_82 [ 0 ] , 0 ,
8192 , L_6 ) ;
V_83 . type = V_85 ;
} else
return - V_80 ;
if ( F_38 ( & V_81 ) < 0 )
F_39 ( V_86 L_8 ) ;
return 0 ;
}
static int T_3 F_40 ( void )
{
return F_41 ( & V_87 ) ;
}
static void T_3 F_42 ( void )
{
if ( V_15 . V_27 & V_88 )
F_9 () ;
if ( V_15 . V_27 & V_89 )
F_19 () ;
#ifdef F_43
F_25 ( F_11 () ) ;
#endif
}
static void T_3 F_44 ( void )
{
V_15 . V_49 = F_14 ;
V_15 . V_90 () ;
}
void T_3 F_45 ( void )
{
V_15 . V_27 = 0 ;
V_91 = F_42 ;
if ( F_46 () )
F_47 () ;
else
F_44 () ;
}
