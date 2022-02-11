struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
unsigned V_3 = F_2 () ;
V_2 = F_3 ( sizeof( * V_2 ) , V_4 ) ;
if ( ! V_2 )
return F_4 ( - V_5 ) ;
V_2 -> V_6 = F_5 ( V_3 , V_7 ) ;
if ( ! V_2 -> V_6 )
goto V_8;
V_2 -> V_9 = F_6 ( V_3 , 0 , ( V_10 |
V_11 ) ) ;
if ( ! V_2 -> V_9 )
goto V_8;
return V_2 ;
V_8:
F_7 ( V_2 -> V_6 ) ;
F_8 ( V_2 ) ;
return F_4 ( - V_5 ) ;
}
void F_9 ( struct V_1 * V_2 )
{
F_7 ( V_2 -> V_6 ) ;
F_10 ( V_2 -> V_9 ) ;
F_8 ( V_2 ) ;
}
static void F_11 ( struct V_12 * V_12 , struct V_13 * V_13 ,
unsigned V_14 )
{
if ( F_12 ( ! F_13 ( ( unsigned long ) V_13 , V_15 ) ) ) {
F_14 ( L_1 , V_13 ) ;
F_15 () ;
}
V_12 -> V_16 = ( void * ) ( ( unsigned long ) V_13 | V_14 ) ;
}
static void F_16 ( struct V_12 * V_12 , struct V_13 * * V_13 ,
unsigned * V_14 )
{
unsigned long V_17 = ( unsigned long ) V_12 -> V_16 ;
* V_13 = ( void * ) ( V_17 & - ( unsigned long ) V_15 ) ;
* V_14 = V_17 & ( V_15 - 1 ) ;
}
static void F_17 ( struct V_13 * V_13 )
{
unsigned long V_18 = V_13 -> V_18 ;
T_1 V_19 = V_13 -> V_20 ;
void * V_21 = V_13 -> V_21 ;
if ( V_13 -> V_22 )
F_18 ( V_13 -> V_23 ,
V_13 -> V_22 ) ;
F_19 ( V_13 , V_13 -> V_2 -> V_6 ) ;
V_19 ( V_18 , V_21 ) ;
}
static void F_20 ( struct V_13 * V_13 , unsigned int V_14 , T_2 error )
{
if ( error )
F_21 ( V_14 , & V_13 -> V_18 ) ;
if ( F_22 ( & V_13 -> V_24 ) )
F_17 ( V_13 ) ;
}
static void F_23 ( struct V_12 * V_12 )
{
struct V_13 * V_13 ;
unsigned V_14 ;
T_2 error ;
if ( V_12 -> V_25 && F_24 ( V_12 ) == V_26 )
F_25 ( V_12 ) ;
F_16 ( V_12 , & V_13 , & V_14 ) ;
error = V_12 -> V_25 ;
F_26 ( V_12 ) ;
F_20 ( V_13 , V_14 , error ) ;
}
static void F_27 ( struct V_27 * V_28 ,
struct V_29 * * V_30 , unsigned long * V_31 , unsigned * V_32 )
{
unsigned V_33 = V_28 -> V_34 ;
struct V_35 * V_36 = (struct V_35 * ) V_28 -> V_37 ;
* V_30 = V_36 -> V_29 ;
* V_31 = V_38 - V_33 ;
* V_32 = V_33 ;
}
static void F_28 ( struct V_27 * V_28 )
{
struct V_35 * V_36 = (struct V_35 * ) V_28 -> V_37 ;
V_28 -> V_37 = V_36 -> V_39 ;
V_28 -> V_34 = 0 ;
}
static void F_29 ( struct V_27 * V_28 , struct V_35 * V_36 , unsigned V_32 )
{
V_28 -> V_40 = F_27 ;
V_28 -> V_41 = F_28 ;
V_28 -> V_34 = V_32 ;
V_28 -> V_37 = V_36 ;
}
static void F_30 ( struct V_27 * V_28 , struct V_29 * * V_30 ,
unsigned long * V_31 , unsigned * V_32 )
{
struct V_42 V_43 = F_31 ( (struct V_42 * ) V_28 -> V_37 ,
V_28 -> V_44 ) ;
* V_30 = V_43 . V_45 ;
* V_31 = V_43 . V_46 ;
* V_32 = V_43 . V_47 ;
V_28 -> V_44 . V_48 = ( V_49 ) V_43 . V_46 ;
}
static void F_32 ( struct V_27 * V_28 )
{
unsigned int V_31 = ( unsigned int ) V_28 -> V_44 . V_48 ;
F_33 ( (struct V_42 * ) V_28 -> V_37 ,
& V_28 -> V_44 , V_31 ) ;
}
static void F_34 ( struct V_27 * V_28 , struct V_12 * V_12 )
{
V_28 -> V_40 = F_30 ;
V_28 -> V_41 = F_32 ;
V_28 -> V_37 = V_12 -> V_50 ;
V_28 -> V_44 = V_12 -> V_51 ;
}
static void F_35 ( struct V_27 * V_28 ,
struct V_29 * * V_30 , unsigned long * V_31 , unsigned * V_32 )
{
* V_30 = F_36 ( V_28 -> V_37 ) ;
* V_32 = V_28 -> V_34 ;
* V_31 = V_38 - V_28 -> V_34 ;
}
static void F_37 ( struct V_27 * V_28 )
{
V_28 -> V_37 += V_38 - V_28 -> V_34 ;
V_28 -> V_34 = 0 ;
}
static void F_38 ( struct V_27 * V_28 , void * V_52 )
{
V_28 -> V_40 = F_35 ;
V_28 -> V_41 = F_37 ;
V_28 -> V_34 = F_39 ( V_52 ) ;
V_28 -> V_37 = V_52 ;
}
static void F_40 ( struct V_27 * V_28 , struct V_29 * * V_30 , unsigned long * V_31 ,
unsigned * V_32 )
{
* V_30 = F_41 ( V_28 -> V_37 ) ;
* V_32 = V_28 -> V_34 ;
* V_31 = V_38 - V_28 -> V_34 ;
}
static void F_42 ( struct V_27 * V_28 )
{
V_28 -> V_37 += V_38 - V_28 -> V_34 ;
V_28 -> V_34 = 0 ;
}
static void F_43 ( struct V_27 * V_28 , void * V_52 )
{
V_28 -> V_40 = F_40 ;
V_28 -> V_41 = F_42 ;
V_28 -> V_34 = F_39 ( V_52 ) ;
V_28 -> V_37 = V_52 ;
}
static void F_44 ( int V_53 , int V_54 , unsigned V_14 ,
struct V_55 * V_56 , struct V_27 * V_28 ,
struct V_13 * V_13 )
{
struct V_12 * V_12 ;
struct V_29 * V_29 ;
unsigned long V_31 ;
unsigned V_32 ;
unsigned V_57 ;
V_49 V_58 = V_56 -> V_24 ;
struct V_59 * V_60 = F_45 ( V_56 -> V_61 ) ;
unsigned short V_62 = F_46 ( V_60 ) ;
V_49 V_63 ;
unsigned int V_64 ( V_65 ) ;
if ( V_53 == V_66 )
V_65 = V_60 -> V_67 . V_68 ;
else if ( V_53 == V_69 )
V_65 = V_60 -> V_67 . V_70 ;
else if ( V_53 == V_71 )
V_65 = V_60 -> V_67 . V_72 ;
if ( ( V_53 == V_66 || V_53 == V_69 ||
V_53 == V_71 ) && V_65 == 0 ) {
F_47 ( & V_13 -> V_24 ) ;
F_20 ( V_13 , V_14 , V_73 ) ;
return;
}
do {
switch ( V_53 ) {
case V_66 :
case V_69 :
V_57 = 0 ;
break;
case V_71 :
V_57 = 1 ;
break;
default:
V_57 = F_48 ( int , V_74 ,
F_49 ( V_58 , ( V_38 >> V_75 ) ) ) ;
}
V_12 = F_50 ( V_76 , V_57 , V_13 -> V_2 -> V_9 ) ;
V_12 -> V_51 . V_48 = V_56 -> V_77 + ( V_56 -> V_24 - V_58 ) ;
F_51 ( V_12 , V_56 -> V_61 ) ;
V_12 -> V_78 = F_23 ;
F_52 ( V_12 , V_53 , V_54 ) ;
F_11 ( V_12 , V_13 , V_14 ) ;
if ( V_53 == V_66 || V_53 == V_69 ) {
V_63 = F_48 ( V_49 , V_65 , V_58 ) ;
V_12 -> V_51 . V_79 = V_63 << V_75 ;
V_58 -= V_63 ;
} else if ( V_53 == V_71 ) {
V_28 -> V_40 ( V_28 , & V_29 , & V_31 , & V_32 ) ;
F_53 ( V_12 , V_29 , V_62 , V_32 ) ;
V_63 = F_48 ( V_49 , V_65 , V_58 ) ;
V_12 -> V_51 . V_79 = V_63 << V_75 ;
V_32 = 0 ;
V_58 -= V_63 ;
V_28 -> V_41 ( V_28 ) ;
} else while ( V_58 ) {
V_28 -> V_40 ( V_28 , & V_29 , & V_31 , & V_32 ) ;
V_31 = F_54 ( V_31 , F_55 ( V_58 ) ) ;
if ( ! F_53 ( V_12 , V_29 , V_31 , V_32 ) )
break;
V_32 = 0 ;
V_58 -= F_56 ( V_31 ) ;
V_28 -> V_41 ( V_28 ) ;
}
F_47 ( & V_13 -> V_24 ) ;
F_57 ( V_12 ) ;
} while ( V_58 );
}
static void F_58 ( int V_53 , int V_54 , unsigned int V_80 ,
struct V_55 * V_56 , struct V_27 * V_28 ,
struct V_13 * V_13 , int V_81 )
{
int V_82 ;
struct V_27 V_83 = * V_28 ;
F_59 ( V_80 > V_15 ) ;
if ( V_81 )
V_54 |= V_84 ;
for ( V_82 = 0 ; V_82 < V_80 ; V_82 ++ ) {
* V_28 = V_83 ;
if ( V_56 [ V_82 ] . V_24 || ( V_54 & V_85 ) )
F_44 ( V_53 , V_54 , V_82 , V_56 + V_82 , V_28 , V_13 ) ;
}
F_20 ( V_13 , 0 , 0 ) ;
}
static void F_60 ( unsigned long error , void * V_21 )
{
struct V_86 * V_87 = V_21 ;
V_87 -> V_18 = error ;
F_61 ( & V_87 -> V_88 ) ;
}
static int V_86 ( struct V_1 * V_2 , unsigned int V_80 ,
struct V_55 * V_56 , int V_53 , int V_54 ,
struct V_27 * V_28 , unsigned long * V_18 )
{
struct V_13 * V_13 ;
struct V_86 V_87 ;
if ( V_80 > 1 && ! F_62 ( V_53 ) ) {
F_63 ( 1 ) ;
return - V_89 ;
}
F_64 ( & V_87 . V_88 ) ;
V_13 = F_65 ( V_2 -> V_6 , V_76 ) ;
V_13 -> V_18 = 0 ;
F_66 ( & V_13 -> V_24 , 1 ) ;
V_13 -> V_2 = V_2 ;
V_13 -> V_20 = F_60 ;
V_13 -> V_21 = & V_87 ;
V_13 -> V_23 = V_28 -> V_23 ;
V_13 -> V_22 = V_28 -> V_22 ;
F_58 ( V_53 , V_54 , V_80 , V_56 , V_28 , V_13 , 1 ) ;
F_67 ( & V_87 . V_88 ) ;
if ( V_18 )
* V_18 = V_87 . V_18 ;
return V_87 . V_18 ? - V_89 : 0 ;
}
static int F_68 ( struct V_1 * V_2 , unsigned int V_80 ,
struct V_55 * V_56 , int V_53 , int V_54 ,
struct V_27 * V_28 , T_1 V_19 , void * V_21 )
{
struct V_13 * V_13 ;
if ( V_80 > 1 && ! F_62 ( V_53 ) ) {
F_63 ( 1 ) ;
V_19 ( 1 , V_21 ) ;
return - V_89 ;
}
V_13 = F_65 ( V_2 -> V_6 , V_76 ) ;
V_13 -> V_18 = 0 ;
F_66 ( & V_13 -> V_24 , 1 ) ;
V_13 -> V_2 = V_2 ;
V_13 -> V_20 = V_19 ;
V_13 -> V_21 = V_21 ;
V_13 -> V_23 = V_28 -> V_23 ;
V_13 -> V_22 = V_28 -> V_22 ;
F_58 ( V_53 , V_54 , V_80 , V_56 , V_28 , V_13 , 0 ) ;
return 0 ;
}
static int F_69 ( struct V_90 * V_91 , struct V_27 * V_28 ,
unsigned long V_92 )
{
V_28 -> V_23 = NULL ;
V_28 -> V_22 = 0 ;
switch ( V_91 -> V_93 . type ) {
case V_94 :
F_29 ( V_28 , V_91 -> V_93 . V_95 . V_36 , V_91 -> V_93 . V_32 ) ;
break;
case V_96 :
F_34 ( V_28 , V_91 -> V_93 . V_95 . V_12 ) ;
break;
case V_97 :
F_70 ( V_91 -> V_93 . V_95 . V_98 , V_92 ) ;
if ( V_91 -> V_99 == V_100 ) {
V_28 -> V_23 = V_91 -> V_93 . V_95 . V_98 ;
V_28 -> V_22 = V_92 ;
}
F_38 ( V_28 , V_91 -> V_93 . V_95 . V_98 ) ;
break;
case V_101 :
F_43 ( V_28 , V_91 -> V_93 . V_95 . V_102 ) ;
break;
default:
return - V_103 ;
}
return 0 ;
}
int F_71 ( struct V_90 * V_91 , unsigned V_80 ,
struct V_55 * V_56 , unsigned long * V_104 )
{
int V_105 ;
struct V_27 V_28 ;
V_105 = F_69 ( V_91 , & V_28 , ( unsigned long ) V_56 -> V_24 << V_75 ) ;
if ( V_105 )
return V_105 ;
if ( ! V_91 -> V_106 . V_19 )
return V_86 ( V_91 -> V_2 , V_80 , V_56 ,
V_91 -> V_99 , V_91 -> V_107 , & V_28 ,
V_104 ) ;
return F_68 ( V_91 -> V_2 , V_80 , V_56 , V_91 -> V_99 ,
V_91 -> V_107 , & V_28 , V_91 -> V_106 . V_19 ,
V_91 -> V_106 . V_21 ) ;
}
int T_3 F_72 ( void )
{
V_7 = F_73 ( V_13 , 0 ) ;
if ( ! V_7 )
return - V_5 ;
return 0 ;
}
void F_74 ( void )
{
F_75 ( V_7 ) ;
V_7 = NULL ;
}
