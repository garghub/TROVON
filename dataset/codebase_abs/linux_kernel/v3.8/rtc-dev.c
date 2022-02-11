static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( V_1 -> V_6 ,
struct V_4 , V_7 ) ;
const struct V_8 * V_9 = V_5 -> V_9 ;
if ( F_3 ( V_10 , & V_5 -> V_11 ) )
return - V_12 ;
V_2 -> V_13 = V_5 ;
V_3 = V_9 -> V_14 ? V_9 -> V_14 ( V_5 -> V_15 . V_16 ) : 0 ;
if ( V_3 == 0 ) {
F_4 ( & V_5 -> V_17 ) ;
V_5 -> V_18 = 0 ;
F_5 ( & V_5 -> V_17 ) ;
return 0 ;
}
F_6 ( V_10 , & V_5 -> V_11 ) ;
return V_3 ;
}
static void F_7 ( struct V_19 * V_20 )
{
struct V_4 * V_5 =
F_2 ( V_20 , struct V_4 , V_21 ) ;
struct V_22 V_23 ;
int V_24 = 0 ;
int V_3 ;
V_3 = F_8 ( V_5 , & V_23 ) ;
F_4 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_25 || V_3 ) {
V_5 -> V_26 = 0 ;
} else if ( V_5 -> V_27 != V_23 . V_28 ) {
V_24 = ( V_23 . V_28 + 60 - V_5 -> V_27 ) % 60 ;
V_5 -> V_27 = V_23 . V_28 ;
V_5 -> V_29 . V_30 = V_31 + V_32 - ( V_32 / 10 ) ;
V_5 -> V_33 = 1 ;
V_5 -> V_26 = 0 ;
F_9 ( & V_5 -> V_29 ) ;
} else if ( F_10 ( & V_5 -> V_21 ) == 0 ) {
V_5 -> V_26 = 0 ;
}
F_5 ( & V_5 -> V_17 ) ;
if ( V_24 )
F_11 ( V_5 , V_24 , V_34 ) ;
}
static void F_12 ( unsigned long V_35 )
{
struct V_4 * V_5 = (struct V_4 * ) V_35 ;
unsigned long V_11 ;
F_13 ( & V_5 -> V_17 , V_11 ) ;
V_5 -> V_33 = 0 ;
V_5 -> V_26 = 1 ;
if ( ( F_10 ( & V_5 -> V_21 ) == 0 ) )
V_5 -> V_26 = 0 ;
F_14 ( & V_5 -> V_17 , V_11 ) ;
}
static int F_15 ( struct V_4 * V_5 )
{
F_4 ( & V_5 -> V_17 ) ;
if ( V_5 -> V_36 ) {
V_5 -> V_25 = 1 ;
if ( V_5 -> V_33 ) {
F_5 ( & V_5 -> V_17 ) ;
F_16 ( & V_5 -> V_29 ) ;
F_4 ( & V_5 -> V_17 ) ;
V_5 -> V_33 = 0 ;
}
if ( V_5 -> V_26 ) {
F_5 ( & V_5 -> V_17 ) ;
F_17 () ;
F_4 ( & V_5 -> V_17 ) ;
}
V_5 -> V_36 = 0 ;
}
F_5 ( & V_5 -> V_17 ) ;
return 0 ;
}
static int F_18 ( struct V_4 * V_5 )
{
struct V_22 V_23 ;
int V_3 ;
V_3 = F_8 ( V_5 , & V_23 ) ;
if ( V_3 )
return V_3 ;
F_4 ( & V_5 -> V_17 ) ;
if ( ! V_5 -> V_36 ) {
V_5 -> V_36 = 1 ;
V_5 -> V_25 = 0 ;
V_5 -> V_27 = V_23 . V_28 ;
V_5 -> V_26 = 1 ;
if ( F_10 ( & V_5 -> V_21 ) == 0 )
V_5 -> V_26 = 0 ;
}
V_5 -> V_18 = 0 ;
F_5 ( & V_5 -> V_17 ) ;
return 0 ;
}
int F_19 ( struct V_4 * V_5 , unsigned int V_37 )
{
if ( V_37 )
return F_18 ( V_5 ) ;
else
return F_15 ( V_5 ) ;
}
static T_1
F_20 ( struct V_2 * V_2 , char T_2 * V_38 , T_3 V_39 , T_4 * V_40 )
{
struct V_4 * V_5 = V_2 -> V_13 ;
F_21 ( V_41 , V_42 ) ;
unsigned long V_35 ;
T_1 V_43 ;
if ( V_39 != sizeof( unsigned int ) && V_39 < sizeof( unsigned long ) )
return - V_44 ;
F_22 ( & V_5 -> V_45 , & V_41 ) ;
do {
F_23 ( V_46 ) ;
F_4 ( & V_5 -> V_17 ) ;
V_35 = V_5 -> V_18 ;
V_5 -> V_18 = 0 ;
F_5 ( & V_5 -> V_17 ) ;
if ( V_35 != 0 ) {
V_43 = 0 ;
break;
}
if ( V_2 -> V_47 & V_48 ) {
V_43 = - V_49 ;
break;
}
if ( F_24 ( V_42 ) ) {
V_43 = - V_50 ;
break;
}
F_25 () ;
} while ( 1 );
F_26 ( V_51 ) ;
F_27 ( & V_5 -> V_45 , & V_41 ) ;
if ( V_43 == 0 ) {
if ( V_5 -> V_9 -> V_52 )
V_35 = V_5 -> V_9 -> V_52 ( V_5 -> V_15 . V_16 ,
V_35 ) ;
if ( sizeof( int ) != sizeof( long ) &&
V_39 == sizeof( unsigned int ) )
V_43 = F_28 ( V_35 , ( unsigned int T_2 * ) V_38 ) ? :
sizeof( unsigned int ) ;
else
V_43 = F_28 ( V_35 , ( unsigned long T_2 * ) V_38 ) ? :
sizeof( unsigned long ) ;
}
return V_43 ;
}
static unsigned int F_29 ( struct V_2 * V_2 , T_5 * V_41 )
{
struct V_4 * V_5 = V_2 -> V_13 ;
unsigned long V_35 ;
F_30 ( V_2 , & V_5 -> V_45 , V_41 ) ;
V_35 = V_5 -> V_18 ;
return ( V_35 != 0 ) ? ( V_53 | V_54 ) : 0 ;
}
static long F_31 ( struct V_2 * V_2 ,
unsigned int V_55 , unsigned long V_56 )
{
int V_3 = 0 ;
struct V_4 * V_5 = V_2 -> V_13 ;
const struct V_8 * V_9 = V_5 -> V_9 ;
struct V_22 V_23 ;
struct V_57 V_58 ;
void T_2 * V_59 = ( void T_2 * ) V_56 ;
V_3 = F_32 ( & V_5 -> V_60 ) ;
if ( V_3 )
return V_3 ;
switch ( V_55 ) {
case V_61 :
case V_62 :
if ( ! F_33 ( V_63 ) )
V_3 = - V_64 ;
break;
case V_65 :
if ( V_56 > V_5 -> V_66 && ! F_33 ( V_67 ) )
V_3 = - V_64 ;
break;
case V_68 :
if ( V_5 -> V_69 > V_5 -> V_66 &&
! F_33 ( V_67 ) )
V_3 = - V_64 ;
break;
}
if ( V_3 )
goto V_70;
switch ( V_55 ) {
case V_71 :
F_34 ( & V_5 -> V_60 ) ;
V_3 = F_35 ( V_5 , & V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_36 ( V_59 , & V_58 . time , sizeof( V_23 ) ) )
V_3 = - V_72 ;
return V_3 ;
case V_73 :
F_34 ( & V_5 -> V_60 ) ;
if ( F_37 ( & V_58 . time , V_59 , sizeof( V_23 ) ) )
return - V_72 ;
V_58 . V_37 = 0 ;
V_58 . V_74 = 0 ;
V_58 . time . V_75 = - 1 ;
V_58 . time . V_76 = - 1 ;
V_58 . time . V_77 = - 1 ;
{
unsigned long V_78 , V_79 ;
V_3 = F_8 ( V_5 , & V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
F_38 ( & V_23 , & V_78 ) ;
V_58 . time . V_80 = V_23 . V_80 ;
V_58 . time . V_81 = V_23 . V_81 ;
V_58 . time . V_82 = V_23 . V_82 ;
V_3 = F_39 ( & V_58 . time ) ;
if ( V_3 < 0 )
return V_3 ;
F_38 ( & V_58 . time , & V_79 ) ;
if ( V_79 < V_78 ) {
F_40 ( V_78 + 24 * 60 * 60 , & V_23 ) ;
V_58 . time . V_80 = V_23 . V_80 ;
V_58 . time . V_81 = V_23 . V_81 ;
V_58 . time . V_82 = V_23 . V_82 ;
}
}
return F_41 ( V_5 , & V_58 ) ;
case V_83 :
F_34 ( & V_5 -> V_60 ) ;
V_3 = F_8 ( V_5 , & V_23 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_36 ( V_59 , & V_23 , sizeof( V_23 ) ) )
V_3 = - V_72 ;
return V_3 ;
case V_62 :
F_34 ( & V_5 -> V_60 ) ;
if ( F_37 ( & V_23 , V_59 , sizeof( V_23 ) ) )
return - V_72 ;
return F_42 ( V_5 , & V_23 ) ;
case V_68 :
V_3 = F_43 ( V_5 , NULL , 1 ) ;
break;
case V_84 :
V_3 = F_43 ( V_5 , NULL , 0 ) ;
break;
case V_85 :
F_34 ( & V_5 -> V_60 ) ;
return F_44 ( V_5 , 1 ) ;
case V_86 :
F_34 ( & V_5 -> V_60 ) ;
return F_44 ( V_5 , 0 ) ;
case V_87 :
F_34 ( & V_5 -> V_60 ) ;
return F_45 ( V_5 , 1 ) ;
case V_88 :
F_34 ( & V_5 -> V_60 ) ;
return F_45 ( V_5 , 0 ) ;
case V_65 :
V_3 = F_46 ( V_5 , NULL , V_56 ) ;
break;
case V_89 :
V_3 = F_28 ( V_5 -> V_69 , ( unsigned long T_2 * ) V_59 ) ;
break;
case V_90 :
F_34 ( & V_5 -> V_60 ) ;
if ( F_37 ( & V_58 , V_59 , sizeof( V_58 ) ) )
return - V_72 ;
return F_41 ( V_5 , & V_58 ) ;
case V_91 :
F_34 ( & V_5 -> V_60 ) ;
V_3 = F_35 ( V_5 , & V_58 ) ;
if ( V_3 < 0 )
return V_3 ;
if ( F_36 ( V_59 , & V_58 , sizeof( V_58 ) ) )
V_3 = - V_72 ;
return V_3 ;
default:
if ( V_9 -> V_92 ) {
V_3 = V_9 -> V_92 ( V_5 -> V_15 . V_16 , V_55 , V_56 ) ;
if ( V_3 == - V_93 )
V_3 = - V_94 ;
} else
V_3 = - V_94 ;
break;
}
V_70:
F_34 ( & V_5 -> V_60 ) ;
return V_3 ;
}
static int F_47 ( int V_95 , struct V_2 * V_2 , int V_96 )
{
struct V_4 * V_5 = V_2 -> V_13 ;
return F_48 ( V_95 , V_2 , V_96 , & V_5 -> V_97 ) ;
}
static int F_49 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_13 ;
F_31 ( V_2 , V_88 , 0 ) ;
F_45 ( V_5 , 0 ) ;
F_43 ( V_5 , NULL , 0 ) ;
if ( V_5 -> V_9 -> V_98 )
V_5 -> V_9 -> V_98 ( V_5 -> V_15 . V_16 ) ;
F_6 ( V_10 , & V_5 -> V_11 ) ;
return 0 ;
}
void F_50 ( struct V_4 * V_5 )
{
if ( ! V_99 )
return;
if ( V_5 -> V_100 >= V_101 ) {
F_51 ( L_1 , V_5 -> V_102 ) ;
return;
}
V_5 -> V_15 . V_103 = F_52 ( F_53 ( V_99 ) , V_5 -> V_100 ) ;
#ifdef F_54
F_55 ( & V_5 -> V_21 , F_7 ) ;
F_56 ( & V_5 -> V_29 , F_12 , ( unsigned long ) V_5 ) ;
#endif
F_57 ( & V_5 -> V_7 , & V_104 ) ;
V_5 -> V_7 . V_105 = V_5 -> V_105 ;
}
void F_58 ( struct V_4 * V_5 )
{
if ( F_59 ( & V_5 -> V_7 , V_5 -> V_15 . V_103 , 1 ) )
F_60 ( V_106 L_2 ,
V_5 -> V_102 , F_53 ( V_99 ) , V_5 -> V_100 ) ;
else
F_51 ( L_3 , V_5 -> V_102 ,
F_53 ( V_99 ) , V_5 -> V_100 ) ;
}
void F_61 ( struct V_4 * V_5 )
{
if ( V_5 -> V_15 . V_103 )
F_62 ( & V_5 -> V_7 ) ;
}
void T_6 F_63 ( void )
{
int V_3 ;
V_3 = F_64 ( & V_99 , 0 , V_101 , L_4 ) ;
if ( V_3 < 0 )
F_60 ( V_107 L_5 ,
__FILE__ ) ;
}
void T_7 F_65 ( void )
{
if ( V_99 )
F_66 ( V_99 , V_101 ) ;
}
