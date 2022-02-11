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
V_2 -> V_9 = F_6 ( V_3 , 0 ) ;
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
static void F_11 ( struct V_10 * V_10 , struct V_11 * V_11 ,
unsigned V_12 )
{
if ( F_12 ( ! F_13 ( ( unsigned long ) V_11 , V_13 ) ) ) {
F_14 ( L_1 , V_11 ) ;
F_15 () ;
}
V_10 -> V_14 = ( void * ) ( ( unsigned long ) V_11 | V_12 ) ;
}
static void F_16 ( struct V_10 * V_10 , struct V_11 * * V_11 ,
unsigned * V_12 )
{
unsigned long V_15 = ( unsigned long ) V_10 -> V_14 ;
* V_11 = ( void * ) ( V_15 & - ( unsigned long ) V_13 ) ;
* V_12 = V_15 & ( V_13 - 1 ) ;
}
static void F_17 ( struct V_11 * V_11 )
{
unsigned long V_16 = V_11 -> V_16 ;
T_1 V_17 = V_11 -> V_18 ;
void * V_19 = V_11 -> V_19 ;
if ( V_11 -> V_20 )
F_18 ( V_11 -> V_21 ,
V_11 -> V_20 ) ;
F_19 ( V_11 , V_11 -> V_2 -> V_6 ) ;
V_17 ( V_16 , V_19 ) ;
}
static void F_20 ( struct V_11 * V_11 , unsigned int V_12 , int error )
{
if ( error )
F_21 ( V_12 , & V_11 -> V_16 ) ;
if ( F_22 ( & V_11 -> V_22 ) )
F_17 ( V_11 ) ;
}
static void F_23 ( struct V_10 * V_10 )
{
struct V_11 * V_11 ;
unsigned V_12 ;
int error ;
if ( V_10 -> V_23 && F_24 ( V_10 ) == V_24 )
F_25 ( V_10 ) ;
F_16 ( V_10 , & V_11 , & V_12 ) ;
error = V_10 -> V_23 ;
F_26 ( V_10 ) ;
F_20 ( V_11 , V_12 , error ) ;
}
static void F_27 ( struct V_25 * V_26 ,
struct V_27 * * V_28 , unsigned long * V_29 , unsigned * V_30 )
{
unsigned V_31 = V_26 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_26 -> V_35 ;
* V_28 = V_34 -> V_27 ;
* V_29 = V_36 - V_31 ;
* V_30 = V_31 ;
}
static void F_28 ( struct V_25 * V_26 )
{
struct V_33 * V_34 = (struct V_33 * ) V_26 -> V_35 ;
V_26 -> V_35 = V_34 -> V_37 ;
V_26 -> V_32 = 0 ;
}
static void F_29 ( struct V_25 * V_26 , struct V_33 * V_34 , unsigned V_30 )
{
V_26 -> V_38 = F_27 ;
V_26 -> V_39 = F_28 ;
V_26 -> V_32 = V_30 ;
V_26 -> V_35 = V_34 ;
}
static void F_30 ( struct V_25 * V_26 , struct V_27 * * V_28 ,
unsigned long * V_29 , unsigned * V_30 )
{
struct V_40 V_41 = F_31 ( (struct V_40 * ) V_26 -> V_35 ,
V_26 -> V_42 ) ;
* V_28 = V_41 . V_43 ;
* V_29 = V_41 . V_44 ;
* V_30 = V_41 . V_45 ;
V_26 -> V_42 . V_46 = ( V_47 ) V_41 . V_44 ;
}
static void F_32 ( struct V_25 * V_26 )
{
unsigned int V_29 = ( unsigned int ) V_26 -> V_42 . V_46 ;
F_33 ( (struct V_40 * ) V_26 -> V_35 ,
& V_26 -> V_42 , V_29 ) ;
}
static void F_34 ( struct V_25 * V_26 , struct V_10 * V_10 )
{
V_26 -> V_38 = F_30 ;
V_26 -> V_39 = F_32 ;
V_26 -> V_35 = V_10 -> V_48 ;
V_26 -> V_42 = V_10 -> V_49 ;
}
static void F_35 ( struct V_25 * V_26 ,
struct V_27 * * V_28 , unsigned long * V_29 , unsigned * V_30 )
{
* V_28 = F_36 ( V_26 -> V_35 ) ;
* V_30 = V_26 -> V_32 ;
* V_29 = V_36 - V_26 -> V_32 ;
}
static void F_37 ( struct V_25 * V_26 )
{
V_26 -> V_35 += V_36 - V_26 -> V_32 ;
V_26 -> V_32 = 0 ;
}
static void F_38 ( struct V_25 * V_26 , void * V_50 )
{
V_26 -> V_38 = F_35 ;
V_26 -> V_39 = F_37 ;
V_26 -> V_32 = F_39 ( V_50 ) ;
V_26 -> V_35 = V_50 ;
}
static void F_40 ( struct V_25 * V_26 , struct V_27 * * V_28 , unsigned long * V_29 ,
unsigned * V_30 )
{
* V_28 = F_41 ( V_26 -> V_35 ) ;
* V_30 = V_26 -> V_32 ;
* V_29 = V_36 - V_26 -> V_32 ;
}
static void F_42 ( struct V_25 * V_26 )
{
V_26 -> V_35 += V_36 - V_26 -> V_32 ;
V_26 -> V_32 = 0 ;
}
static void F_43 ( struct V_25 * V_26 , void * V_50 )
{
V_26 -> V_38 = F_40 ;
V_26 -> V_39 = F_42 ;
V_26 -> V_32 = F_39 ( V_50 ) ;
V_26 -> V_35 = V_50 ;
}
static void F_44 ( int V_51 , int V_52 , unsigned V_12 ,
struct V_53 * V_54 , struct V_25 * V_26 ,
struct V_11 * V_11 )
{
struct V_10 * V_10 ;
struct V_27 * V_27 ;
unsigned long V_29 ;
unsigned V_30 ;
unsigned V_55 ;
V_47 V_56 = V_54 -> V_22 ;
struct V_57 * V_58 = F_45 ( V_54 -> V_59 ) ;
unsigned short V_60 = F_46 ( V_58 ) ;
V_47 V_61 ;
unsigned int V_62 ( V_63 ) ;
if ( V_51 == V_64 )
V_63 = V_58 -> V_65 . V_66 ;
else if ( V_51 == V_67 )
V_63 = V_58 -> V_65 . V_68 ;
else if ( V_51 == V_69 )
V_63 = V_58 -> V_65 . V_70 ;
if ( ( V_51 == V_64 || V_51 == V_67 ||
V_51 == V_69 ) && V_63 == 0 ) {
F_47 ( & V_11 -> V_22 ) ;
F_20 ( V_11 , V_12 , - V_71 ) ;
return;
}
do {
switch ( V_51 ) {
case V_64 :
case V_67 :
V_55 = 0 ;
break;
case V_69 :
V_55 = 1 ;
break;
default:
V_55 = F_48 ( int , V_72 ,
F_49 ( V_56 , ( V_36 >> V_73 ) ) ) ;
}
V_10 = F_50 ( V_74 , V_55 , V_11 -> V_2 -> V_9 ) ;
V_10 -> V_49 . V_46 = V_54 -> V_75 + ( V_54 -> V_22 - V_56 ) ;
V_10 -> V_76 = V_54 -> V_59 ;
V_10 -> V_77 = F_23 ;
F_51 ( V_10 , V_51 , V_52 ) ;
F_11 ( V_10 , V_11 , V_12 ) ;
if ( V_51 == V_64 || V_51 == V_67 ) {
V_61 = F_48 ( V_47 , V_63 , V_56 ) ;
V_10 -> V_49 . V_78 = V_61 << V_73 ;
V_56 -= V_61 ;
} else if ( V_51 == V_69 ) {
V_26 -> V_38 ( V_26 , & V_27 , & V_29 , & V_30 ) ;
F_52 ( V_10 , V_27 , V_60 , V_30 ) ;
V_61 = F_48 ( V_47 , V_63 , V_56 ) ;
V_10 -> V_49 . V_78 = V_61 << V_73 ;
V_30 = 0 ;
V_56 -= V_61 ;
V_26 -> V_39 ( V_26 ) ;
} else while ( V_56 ) {
V_26 -> V_38 ( V_26 , & V_27 , & V_29 , & V_30 ) ;
V_29 = F_53 ( V_29 , F_54 ( V_56 ) ) ;
if ( ! F_52 ( V_10 , V_27 , V_29 , V_30 ) )
break;
V_30 = 0 ;
V_56 -= F_55 ( V_29 ) ;
V_26 -> V_39 ( V_26 ) ;
}
F_47 ( & V_11 -> V_22 ) ;
F_56 ( V_10 ) ;
} while ( V_56 );
}
static void F_57 ( int V_51 , int V_52 , unsigned int V_79 ,
struct V_53 * V_54 , struct V_25 * V_26 ,
struct V_11 * V_11 , int V_80 )
{
int V_81 ;
struct V_25 V_82 = * V_26 ;
F_58 ( V_79 > V_13 ) ;
if ( V_80 )
V_52 |= V_83 ;
for ( V_81 = 0 ; V_81 < V_79 ; V_81 ++ ) {
* V_26 = V_82 ;
if ( V_54 [ V_81 ] . V_22 || ( V_52 & V_84 ) )
F_44 ( V_51 , V_52 , V_81 , V_54 + V_81 , V_26 , V_11 ) ;
}
F_20 ( V_11 , 0 , 0 ) ;
}
static void F_59 ( unsigned long error , void * V_19 )
{
struct V_85 * V_86 = V_19 ;
V_86 -> V_16 = error ;
F_60 ( & V_86 -> V_87 ) ;
}
static int V_85 ( struct V_1 * V_2 , unsigned int V_79 ,
struct V_53 * V_54 , int V_51 , int V_52 ,
struct V_25 * V_26 , unsigned long * V_16 )
{
struct V_11 * V_11 ;
struct V_85 V_86 ;
if ( V_79 > 1 && ! F_61 ( V_51 ) ) {
F_62 ( 1 ) ;
return - V_88 ;
}
F_63 ( & V_86 . V_87 ) ;
V_11 = F_64 ( V_2 -> V_6 , V_74 ) ;
V_11 -> V_16 = 0 ;
F_65 ( & V_11 -> V_22 , 1 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = F_59 ;
V_11 -> V_19 = & V_86 ;
V_11 -> V_21 = V_26 -> V_21 ;
V_11 -> V_20 = V_26 -> V_20 ;
F_57 ( V_51 , V_52 , V_79 , V_54 , V_26 , V_11 , 1 ) ;
F_66 ( & V_86 . V_87 ) ;
if ( V_16 )
* V_16 = V_86 . V_16 ;
return V_86 . V_16 ? - V_88 : 0 ;
}
static int F_67 ( struct V_1 * V_2 , unsigned int V_79 ,
struct V_53 * V_54 , int V_51 , int V_52 ,
struct V_25 * V_26 , T_1 V_17 , void * V_19 )
{
struct V_11 * V_11 ;
if ( V_79 > 1 && ! F_61 ( V_51 ) ) {
F_62 ( 1 ) ;
V_17 ( 1 , V_19 ) ;
return - V_88 ;
}
V_11 = F_64 ( V_2 -> V_6 , V_74 ) ;
V_11 -> V_16 = 0 ;
F_65 ( & V_11 -> V_22 , 1 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = V_17 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_21 = V_26 -> V_21 ;
V_11 -> V_20 = V_26 -> V_20 ;
F_57 ( V_51 , V_52 , V_79 , V_54 , V_26 , V_11 , 0 ) ;
return 0 ;
}
static int F_68 ( struct V_89 * V_90 , struct V_25 * V_26 ,
unsigned long V_91 )
{
V_26 -> V_21 = NULL ;
V_26 -> V_20 = 0 ;
switch ( V_90 -> V_92 . type ) {
case V_93 :
F_29 ( V_26 , V_90 -> V_92 . V_94 . V_34 , V_90 -> V_92 . V_30 ) ;
break;
case V_95 :
F_34 ( V_26 , V_90 -> V_92 . V_94 . V_10 ) ;
break;
case V_96 :
F_69 ( V_90 -> V_92 . V_94 . V_97 , V_91 ) ;
if ( V_90 -> V_98 == V_99 ) {
V_26 -> V_21 = V_90 -> V_92 . V_94 . V_97 ;
V_26 -> V_20 = V_91 ;
}
F_38 ( V_26 , V_90 -> V_92 . V_94 . V_97 ) ;
break;
case V_100 :
F_43 ( V_26 , V_90 -> V_92 . V_94 . V_101 ) ;
break;
default:
return - V_102 ;
}
return 0 ;
}
int F_70 ( struct V_89 * V_90 , unsigned V_79 ,
struct V_53 * V_54 , unsigned long * V_103 )
{
int V_104 ;
struct V_25 V_26 ;
V_104 = F_68 ( V_90 , & V_26 , ( unsigned long ) V_54 -> V_22 << V_73 ) ;
if ( V_104 )
return V_104 ;
if ( ! V_90 -> V_105 . V_17 )
return V_85 ( V_90 -> V_2 , V_79 , V_54 ,
V_90 -> V_98 , V_90 -> V_106 , & V_26 ,
V_103 ) ;
return F_67 ( V_90 -> V_2 , V_79 , V_54 , V_90 -> V_98 ,
V_90 -> V_106 , & V_26 , V_90 -> V_105 . V_17 ,
V_90 -> V_105 . V_19 ) ;
}
int T_2 F_71 ( void )
{
V_7 = F_72 ( V_11 , 0 ) ;
if ( ! V_7 )
return - V_5 ;
return 0 ;
}
void F_73 ( void )
{
F_74 ( V_7 ) ;
V_7 = NULL ;
}
