static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_1 -> V_5 ,
struct V_3 , V_6 ) ;
if ( F_3 ( V_7 , & V_4 -> V_8 ) )
return - V_9 ;
V_2 -> V_10 = V_4 ;
F_4 ( & V_4 -> V_11 ) ;
V_4 -> V_12 = 0 ;
F_5 ( & V_4 -> V_11 ) ;
return 0 ;
}
static void F_6 ( struct V_13 * V_14 )
{
struct V_3 * V_4 =
F_2 ( V_14 , struct V_3 , V_15 ) ;
struct V_16 V_17 ;
int V_18 = 0 ;
int V_19 ;
V_19 = F_7 ( V_4 , & V_17 ) ;
F_4 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_20 || V_19 ) {
V_4 -> V_21 = 0 ;
} else if ( V_4 -> V_22 != V_17 . V_23 ) {
V_18 = ( V_17 . V_23 + 60 - V_4 -> V_22 ) % 60 ;
V_4 -> V_22 = V_17 . V_23 ;
V_4 -> V_24 . V_25 = V_26 + V_27 - ( V_27 / 10 ) ;
V_4 -> V_28 = 1 ;
V_4 -> V_21 = 0 ;
F_8 ( & V_4 -> V_24 ) ;
} else if ( F_9 ( & V_4 -> V_15 ) == 0 ) {
V_4 -> V_21 = 0 ;
}
F_5 ( & V_4 -> V_11 ) ;
if ( V_18 )
F_10 ( V_4 , V_18 , V_29 ) ;
}
static void F_11 ( unsigned long V_30 )
{
struct V_3 * V_4 = (struct V_3 * ) V_30 ;
unsigned long V_8 ;
F_12 ( & V_4 -> V_11 , V_8 ) ;
V_4 -> V_28 = 0 ;
V_4 -> V_21 = 1 ;
if ( ( F_9 ( & V_4 -> V_15 ) == 0 ) )
V_4 -> V_21 = 0 ;
F_13 ( & V_4 -> V_11 , V_8 ) ;
}
static int F_14 ( struct V_3 * V_4 )
{
F_4 ( & V_4 -> V_11 ) ;
if ( V_4 -> V_31 ) {
V_4 -> V_20 = 1 ;
if ( V_4 -> V_28 ) {
F_5 ( & V_4 -> V_11 ) ;
F_15 ( & V_4 -> V_24 ) ;
F_4 ( & V_4 -> V_11 ) ;
V_4 -> V_28 = 0 ;
}
if ( V_4 -> V_21 ) {
F_5 ( & V_4 -> V_11 ) ;
F_16 () ;
F_4 ( & V_4 -> V_11 ) ;
}
V_4 -> V_31 = 0 ;
}
F_5 ( & V_4 -> V_11 ) ;
return 0 ;
}
static int F_17 ( struct V_3 * V_4 )
{
struct V_16 V_17 ;
int V_19 ;
V_19 = F_7 ( V_4 , & V_17 ) ;
if ( V_19 )
return V_19 ;
F_4 ( & V_4 -> V_11 ) ;
if ( ! V_4 -> V_31 ) {
V_4 -> V_31 = 1 ;
V_4 -> V_20 = 0 ;
V_4 -> V_22 = V_17 . V_23 ;
V_4 -> V_21 = 1 ;
if ( F_9 ( & V_4 -> V_15 ) == 0 )
V_4 -> V_21 = 0 ;
}
V_4 -> V_12 = 0 ;
F_5 ( & V_4 -> V_11 ) ;
return 0 ;
}
int F_18 ( struct V_3 * V_4 , unsigned int V_32 )
{
if ( V_32 )
return F_17 ( V_4 ) ;
else
return F_14 ( V_4 ) ;
}
static T_1
F_19 ( struct V_2 * V_2 , char T_2 * V_33 , T_3 V_34 , T_4 * V_35 )
{
struct V_3 * V_4 = V_2 -> V_10 ;
F_20 ( V_36 , V_37 ) ;
unsigned long V_30 ;
T_1 V_38 ;
if ( V_34 != sizeof( unsigned int ) && V_34 < sizeof( unsigned long ) )
return - V_39 ;
F_21 ( & V_4 -> V_40 , & V_36 ) ;
do {
F_22 ( V_41 ) ;
F_4 ( & V_4 -> V_11 ) ;
V_30 = V_4 -> V_12 ;
V_4 -> V_12 = 0 ;
F_5 ( & V_4 -> V_11 ) ;
if ( V_30 != 0 ) {
V_38 = 0 ;
break;
}
if ( V_2 -> V_42 & V_43 ) {
V_38 = - V_44 ;
break;
}
if ( F_23 ( V_37 ) ) {
V_38 = - V_45 ;
break;
}
F_24 () ;
} while ( 1 );
F_25 ( V_46 ) ;
F_26 ( & V_4 -> V_40 , & V_36 ) ;
if ( V_38 == 0 ) {
if ( V_4 -> V_47 -> V_48 )
V_30 = V_4 -> V_47 -> V_48 ( V_4 -> V_49 . V_50 ,
V_30 ) ;
if ( sizeof( int ) != sizeof( long ) &&
V_34 == sizeof( unsigned int ) )
V_38 = F_27 ( V_30 , ( unsigned int T_2 * ) V_33 ) ? :
sizeof( unsigned int ) ;
else
V_38 = F_27 ( V_30 , ( unsigned long T_2 * ) V_33 ) ? :
sizeof( unsigned long ) ;
}
return V_38 ;
}
static unsigned int F_28 ( struct V_2 * V_2 , T_5 * V_36 )
{
struct V_3 * V_4 = V_2 -> V_10 ;
unsigned long V_30 ;
F_29 ( V_2 , & V_4 -> V_40 , V_36 ) ;
V_30 = V_4 -> V_12 ;
return ( V_30 != 0 ) ? ( V_51 | V_52 ) : 0 ;
}
static long F_30 ( struct V_2 * V_2 ,
unsigned int V_53 , unsigned long V_54 )
{
int V_19 = 0 ;
struct V_3 * V_4 = V_2 -> V_10 ;
const struct V_55 * V_47 = V_4 -> V_47 ;
struct V_16 V_17 ;
struct V_56 V_57 ;
void T_2 * V_58 = ( void T_2 * ) V_54 ;
V_19 = F_31 ( & V_4 -> V_59 ) ;
if ( V_19 )
return V_19 ;
switch ( V_53 ) {
case V_60 :
case V_61 :
if ( ! F_32 ( V_62 ) )
V_19 = - V_63 ;
break;
case V_64 :
if ( V_54 > V_4 -> V_65 && ! F_32 ( V_66 ) )
V_19 = - V_63 ;
break;
case V_67 :
if ( V_4 -> V_68 > V_4 -> V_65 &&
! F_32 ( V_66 ) )
V_19 = - V_63 ;
break;
}
if ( V_19 )
goto V_69;
switch ( V_53 ) {
case V_70 :
F_33 ( & V_4 -> V_59 ) ;
V_19 = F_34 ( V_4 , & V_57 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_35 ( V_58 , & V_57 . time , sizeof( V_17 ) ) )
V_19 = - V_71 ;
return V_19 ;
case V_72 :
F_33 ( & V_4 -> V_59 ) ;
if ( F_36 ( & V_57 . time , V_58 , sizeof( V_17 ) ) )
return - V_71 ;
V_57 . V_32 = 0 ;
V_57 . V_73 = 0 ;
V_57 . time . V_74 = - 1 ;
V_57 . time . V_75 = - 1 ;
V_57 . time . V_76 = - 1 ;
{
T_6 V_77 , V_78 ;
V_19 = F_7 ( V_4 , & V_17 ) ;
if ( V_19 < 0 )
return V_19 ;
V_77 = F_37 ( & V_17 ) ;
V_57 . time . V_79 = V_17 . V_79 ;
V_57 . time . V_80 = V_17 . V_80 ;
V_57 . time . V_81 = V_17 . V_81 ;
V_19 = F_38 ( & V_57 . time ) ;
if ( V_19 < 0 )
return V_19 ;
V_78 = F_37 ( & V_57 . time ) ;
if ( V_78 < V_77 ) {
F_39 ( V_77 + 24 * 60 * 60 , & V_17 ) ;
V_57 . time . V_79 = V_17 . V_79 ;
V_57 . time . V_80 = V_17 . V_80 ;
V_57 . time . V_81 = V_17 . V_81 ;
}
}
return F_40 ( V_4 , & V_57 ) ;
case V_82 :
F_33 ( & V_4 -> V_59 ) ;
V_19 = F_7 ( V_4 , & V_17 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_35 ( V_58 , & V_17 , sizeof( V_17 ) ) )
V_19 = - V_71 ;
return V_19 ;
case V_61 :
F_33 ( & V_4 -> V_59 ) ;
if ( F_36 ( & V_17 , V_58 , sizeof( V_17 ) ) )
return - V_71 ;
return F_41 ( V_4 , & V_17 ) ;
case V_67 :
V_19 = F_42 ( V_4 , NULL , 1 ) ;
break;
case V_83 :
V_19 = F_42 ( V_4 , NULL , 0 ) ;
break;
case V_84 :
F_33 ( & V_4 -> V_59 ) ;
return F_43 ( V_4 , 1 ) ;
case V_85 :
F_33 ( & V_4 -> V_59 ) ;
return F_43 ( V_4 , 0 ) ;
case V_86 :
F_33 ( & V_4 -> V_59 ) ;
return F_44 ( V_4 , 1 ) ;
case V_87 :
F_33 ( & V_4 -> V_59 ) ;
return F_44 ( V_4 , 0 ) ;
case V_64 :
V_19 = F_45 ( V_4 , NULL , V_54 ) ;
break;
case V_88 :
V_19 = F_27 ( V_4 -> V_68 , ( unsigned long T_2 * ) V_58 ) ;
break;
case V_89 :
F_33 ( & V_4 -> V_59 ) ;
if ( F_36 ( & V_57 , V_58 , sizeof( V_57 ) ) )
return - V_71 ;
return F_40 ( V_4 , & V_57 ) ;
case V_90 :
F_33 ( & V_4 -> V_59 ) ;
V_19 = F_34 ( V_4 , & V_57 ) ;
if ( V_19 < 0 )
return V_19 ;
if ( F_35 ( V_58 , & V_57 , sizeof( V_57 ) ) )
V_19 = - V_71 ;
return V_19 ;
default:
if ( V_47 -> V_91 ) {
V_19 = V_47 -> V_91 ( V_4 -> V_49 . V_50 , V_53 , V_54 ) ;
if ( V_19 == - V_92 )
V_19 = - V_93 ;
} else
V_19 = - V_93 ;
break;
}
V_69:
F_33 ( & V_4 -> V_59 ) ;
return V_19 ;
}
static int F_46 ( int V_94 , struct V_2 * V_2 , int V_95 )
{
struct V_3 * V_4 = V_2 -> V_10 ;
return F_47 ( V_94 , V_2 , V_95 , & V_4 -> V_96 ) ;
}
static int F_48 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_10 ;
F_30 ( V_2 , V_87 , 0 ) ;
F_44 ( V_4 , 0 ) ;
F_42 ( V_4 , NULL , 0 ) ;
F_49 ( V_7 , & V_4 -> V_8 ) ;
return 0 ;
}
void F_50 ( struct V_3 * V_4 )
{
if ( ! V_97 )
return;
if ( V_4 -> V_98 >= V_99 ) {
F_51 ( & V_4 -> V_49 , L_1 ) ;
return;
}
V_4 -> V_49 . V_100 = F_52 ( F_53 ( V_97 ) , V_4 -> V_98 ) ;
#ifdef F_54
F_55 ( & V_4 -> V_15 , F_6 ) ;
F_56 ( & V_4 -> V_24 , F_11 , ( unsigned long ) V_4 ) ;
#endif
F_57 ( & V_4 -> V_6 , & V_101 ) ;
V_4 -> V_6 . V_102 = V_4 -> V_102 ;
}
void T_7 F_58 ( void )
{
int V_19 ;
V_19 = F_59 ( & V_97 , 0 , V_99 , L_2 ) ;
if ( V_19 < 0 )
F_60 ( L_3 ) ;
}
void T_8 F_61 ( void )
{
if ( V_97 )
F_62 ( V_97 , V_99 ) ;
}
