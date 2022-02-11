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
struct V_40 * V_41 = V_26 -> V_35 ;
* V_28 = V_41 -> V_42 ;
* V_29 = V_41 -> V_43 - V_26 -> V_32 ;
* V_30 = V_41 -> V_44 + V_26 -> V_32 ;
}
static void F_31 ( struct V_25 * V_26 )
{
struct V_40 * V_41 = V_26 -> V_35 ;
V_26 -> V_35 = V_41 + 1 ;
V_26 -> V_32 = 0 ;
}
static void F_32 ( struct V_25 * V_26 , struct V_10 * V_10 )
{
V_26 -> V_38 = F_30 ;
V_26 -> V_39 = F_31 ;
V_26 -> V_35 = F_33 ( V_10 -> V_45 , V_10 -> V_46 ) ;
V_26 -> V_32 = V_10 -> V_46 . V_47 ;
}
static void F_34 ( struct V_25 * V_26 ,
struct V_27 * * V_28 , unsigned long * V_29 , unsigned * V_30 )
{
* V_28 = F_35 ( V_26 -> V_35 ) ;
* V_30 = V_26 -> V_32 ;
* V_29 = V_36 - V_26 -> V_32 ;
}
static void F_36 ( struct V_25 * V_26 )
{
V_26 -> V_35 += V_36 - V_26 -> V_32 ;
V_26 -> V_32 = 0 ;
}
static void F_37 ( struct V_25 * V_26 , void * V_48 )
{
V_26 -> V_38 = F_34 ;
V_26 -> V_39 = F_36 ;
V_26 -> V_32 = F_38 ( V_48 ) ;
V_26 -> V_35 = V_48 ;
}
static void F_39 ( struct V_25 * V_26 , struct V_27 * * V_28 , unsigned long * V_29 ,
unsigned * V_30 )
{
* V_28 = F_40 ( V_26 -> V_35 ) ;
* V_30 = V_26 -> V_32 ;
* V_29 = V_36 - V_26 -> V_32 ;
}
static void F_41 ( struct V_25 * V_26 )
{
V_26 -> V_35 += V_36 - V_26 -> V_32 ;
V_26 -> V_32 = 0 ;
}
static void F_42 ( struct V_25 * V_26 , void * V_48 )
{
V_26 -> V_38 = F_39 ;
V_26 -> V_39 = F_41 ;
V_26 -> V_32 = F_38 ( V_48 ) ;
V_26 -> V_35 = V_48 ;
}
static void F_43 ( int V_49 , unsigned V_12 , struct V_50 * V_51 ,
struct V_25 * V_26 , struct V_11 * V_11 )
{
struct V_10 * V_10 ;
struct V_27 * V_27 ;
unsigned long V_29 ;
unsigned V_30 ;
unsigned V_52 ;
T_2 V_53 = V_51 -> V_22 ;
struct V_54 * V_55 = F_44 ( V_51 -> V_56 ) ;
unsigned short V_57 = F_45 ( V_55 ) ;
T_2 V_58 ;
unsigned int V_59 ( V_60 ) ;
if ( V_49 & V_61 )
V_60 = V_55 -> V_62 . V_63 ;
else if ( V_49 & V_64 )
V_60 = V_55 -> V_62 . V_65 ;
if ( ( V_49 & ( V_61 | V_64 ) ) && V_60 == 0 ) {
F_20 ( V_11 , V_12 , - V_66 ) ;
return;
}
do {
if ( ( V_49 & V_61 ) || ( V_49 & V_64 ) )
V_52 = 1 ;
else
V_52 = F_46 ( int , V_67 ,
F_47 ( V_53 , ( V_36 >> V_68 ) ) ) ;
V_10 = F_48 ( V_69 , V_52 , V_11 -> V_2 -> V_9 ) ;
V_10 -> V_46 . V_70 = V_51 -> V_71 + ( V_51 -> V_22 - V_53 ) ;
V_10 -> V_72 = V_51 -> V_56 ;
V_10 -> V_73 = F_23 ;
F_11 ( V_10 , V_11 , V_12 ) ;
if ( V_49 & V_61 ) {
V_58 = F_46 ( T_2 , V_60 , V_53 ) ;
V_10 -> V_46 . V_74 = V_58 << V_68 ;
V_53 -= V_58 ;
} else if ( V_49 & V_64 ) {
V_26 -> V_38 ( V_26 , & V_27 , & V_29 , & V_30 ) ;
F_49 ( V_10 , V_27 , V_57 , V_30 ) ;
V_58 = F_46 ( T_2 , V_60 , V_53 ) ;
V_10 -> V_46 . V_74 = V_58 << V_68 ;
V_30 = 0 ;
V_53 -= V_58 ;
V_26 -> V_39 ( V_26 ) ;
} else while ( V_53 ) {
V_26 -> V_38 ( V_26 , & V_27 , & V_29 , & V_30 ) ;
V_29 = F_50 ( V_29 , F_51 ( V_53 ) ) ;
if ( ! F_49 ( V_10 , V_27 , V_29 , V_30 ) )
break;
V_30 = 0 ;
V_53 -= F_52 ( V_29 ) ;
V_26 -> V_39 ( V_26 ) ;
}
F_53 ( & V_11 -> V_22 ) ;
F_54 ( V_49 , V_10 ) ;
} while ( V_53 );
}
static void F_55 ( int V_49 , unsigned int V_75 ,
struct V_50 * V_51 , struct V_25 * V_26 ,
struct V_11 * V_11 , int V_76 )
{
int V_77 ;
struct V_25 V_78 = * V_26 ;
F_56 ( V_75 > V_13 ) ;
if ( V_76 )
V_49 |= V_79 ;
for ( V_77 = 0 ; V_77 < V_75 ; V_77 ++ ) {
* V_26 = V_78 ;
if ( V_51 [ V_77 ] . V_22 || ( V_49 & V_80 ) )
F_43 ( V_49 , V_77 , V_51 + V_77 , V_26 , V_11 ) ;
}
F_20 ( V_11 , 0 , 0 ) ;
}
static void F_57 ( unsigned long error , void * V_19 )
{
struct V_81 * V_82 = V_19 ;
V_82 -> V_16 = error ;
F_58 ( & V_82 -> V_83 ) ;
}
static int V_81 ( struct V_1 * V_2 , unsigned int V_75 ,
struct V_50 * V_51 , int V_49 , struct V_25 * V_26 ,
unsigned long * V_16 )
{
struct V_11 * V_11 ;
struct V_81 V_82 ;
if ( V_75 > 1 && ( V_49 & V_84 ) != V_85 ) {
F_59 ( 1 ) ;
return - V_86 ;
}
F_60 ( & V_82 . V_83 ) ;
V_11 = F_61 ( V_2 -> V_6 , V_69 ) ;
V_11 -> V_16 = 0 ;
F_62 ( & V_11 -> V_22 , 1 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = F_57 ;
V_11 -> V_19 = & V_82 ;
V_11 -> V_21 = V_26 -> V_21 ;
V_11 -> V_20 = V_26 -> V_20 ;
F_55 ( V_49 , V_75 , V_51 , V_26 , V_11 , 1 ) ;
F_63 ( & V_82 . V_83 ) ;
if ( V_16 )
* V_16 = V_82 . V_16 ;
return V_82 . V_16 ? - V_86 : 0 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_75 ,
struct V_50 * V_51 , int V_49 , struct V_25 * V_26 ,
T_1 V_17 , void * V_19 )
{
struct V_11 * V_11 ;
if ( V_75 > 1 && ( V_49 & V_84 ) != V_85 ) {
F_59 ( 1 ) ;
V_17 ( 1 , V_19 ) ;
return - V_86 ;
}
V_11 = F_61 ( V_2 -> V_6 , V_69 ) ;
V_11 -> V_16 = 0 ;
F_62 ( & V_11 -> V_22 , 1 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = V_17 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_21 = V_26 -> V_21 ;
V_11 -> V_20 = V_26 -> V_20 ;
F_55 ( V_49 , V_75 , V_51 , V_26 , V_11 , 0 ) ;
return 0 ;
}
static int F_65 ( struct V_87 * V_88 , struct V_25 * V_26 ,
unsigned long V_89 )
{
V_26 -> V_21 = NULL ;
V_26 -> V_20 = 0 ;
switch ( V_88 -> V_90 . type ) {
case V_91 :
F_29 ( V_26 , V_88 -> V_90 . V_92 . V_34 , V_88 -> V_90 . V_30 ) ;
break;
case V_93 :
F_32 ( V_26 , V_88 -> V_90 . V_92 . V_10 ) ;
break;
case V_94 :
F_66 ( V_88 -> V_90 . V_92 . V_95 , V_89 ) ;
if ( ( V_88 -> V_96 & V_84 ) == V_24 ) {
V_26 -> V_21 = V_88 -> V_90 . V_92 . V_95 ;
V_26 -> V_20 = V_89 ;
}
F_37 ( V_26 , V_88 -> V_90 . V_92 . V_95 ) ;
break;
case V_97 :
F_42 ( V_26 , V_88 -> V_90 . V_92 . V_98 ) ;
break;
default:
return - V_99 ;
}
return 0 ;
}
int F_67 ( struct V_87 * V_88 , unsigned V_75 ,
struct V_50 * V_51 , unsigned long * V_100 )
{
int V_101 ;
struct V_25 V_26 ;
V_101 = F_65 ( V_88 , & V_26 , ( unsigned long ) V_51 -> V_22 << V_68 ) ;
if ( V_101 )
return V_101 ;
if ( ! V_88 -> V_102 . V_17 )
return V_81 ( V_88 -> V_2 , V_75 , V_51 ,
V_88 -> V_96 , & V_26 , V_100 ) ;
return F_64 ( V_88 -> V_2 , V_75 , V_51 , V_88 -> V_96 ,
& V_26 , V_88 -> V_102 . V_17 , V_88 -> V_102 . V_19 ) ;
}
int T_3 F_68 ( void )
{
V_7 = F_69 ( V_11 , 0 ) ;
if ( ! V_7 )
return - V_5 ;
return 0 ;
}
void F_70 ( void )
{
F_71 ( V_7 ) ;
V_7 = NULL ;
}
