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
if ( V_2 -> V_6 )
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
static void F_23 ( struct V_10 * V_10 , int error )
{
struct V_11 * V_11 ;
unsigned V_12 ;
if ( error && F_24 ( V_10 ) == V_23 )
F_25 ( V_10 ) ;
F_16 ( V_10 , & V_11 , & V_12 ) ;
F_26 ( V_10 ) ;
F_20 ( V_11 , V_12 , error ) ;
}
static void F_27 ( struct V_24 * V_25 ,
struct V_26 * * V_27 , unsigned long * V_28 , unsigned * V_29 )
{
unsigned V_30 = V_25 -> V_31 ;
struct V_32 * V_33 = (struct V_32 * ) V_25 -> V_34 ;
* V_27 = V_33 -> V_26 ;
* V_28 = V_35 - V_30 ;
* V_29 = V_30 ;
}
static void F_28 ( struct V_24 * V_25 )
{
struct V_32 * V_33 = (struct V_32 * ) V_25 -> V_34 ;
V_25 -> V_34 = V_33 -> V_36 ;
V_25 -> V_31 = 0 ;
}
static void F_29 ( struct V_24 * V_25 , struct V_32 * V_33 , unsigned V_29 )
{
V_25 -> V_37 = F_27 ;
V_25 -> V_38 = F_28 ;
V_25 -> V_31 = V_29 ;
V_25 -> V_34 = V_33 ;
}
static void F_30 ( struct V_24 * V_25 , struct V_26 * * V_27 ,
unsigned long * V_28 , unsigned * V_29 )
{
struct V_39 * V_40 = V_25 -> V_34 ;
* V_27 = V_40 -> V_41 ;
* V_28 = V_40 -> V_42 - V_25 -> V_31 ;
* V_29 = V_40 -> V_43 + V_25 -> V_31 ;
}
static void F_31 ( struct V_24 * V_25 )
{
struct V_39 * V_40 = V_25 -> V_34 ;
V_25 -> V_34 = V_40 + 1 ;
V_25 -> V_31 = 0 ;
}
static void F_32 ( struct V_24 * V_25 , struct V_10 * V_10 )
{
V_25 -> V_37 = F_30 ;
V_25 -> V_38 = F_31 ;
V_25 -> V_34 = F_33 ( V_10 -> V_44 , V_10 -> V_45 ) ;
V_25 -> V_31 = V_10 -> V_45 . V_46 ;
}
static void F_34 ( struct V_24 * V_25 ,
struct V_26 * * V_27 , unsigned long * V_28 , unsigned * V_29 )
{
* V_27 = F_35 ( V_25 -> V_34 ) ;
* V_29 = V_25 -> V_31 ;
* V_28 = V_35 - V_25 -> V_31 ;
}
static void F_36 ( struct V_24 * V_25 )
{
V_25 -> V_34 += V_35 - V_25 -> V_31 ;
V_25 -> V_31 = 0 ;
}
static void F_37 ( struct V_24 * V_25 , void * V_47 )
{
V_25 -> V_37 = F_34 ;
V_25 -> V_38 = F_36 ;
V_25 -> V_31 = ( ( unsigned long ) V_47 ) & ( V_35 - 1 ) ;
V_25 -> V_34 = V_47 ;
}
static void F_38 ( struct V_24 * V_25 , struct V_26 * * V_27 , unsigned long * V_28 ,
unsigned * V_29 )
{
* V_27 = F_39 ( V_25 -> V_34 ) ;
* V_29 = V_25 -> V_31 ;
* V_28 = V_35 - V_25 -> V_31 ;
}
static void F_40 ( struct V_24 * V_25 )
{
V_25 -> V_34 += V_35 - V_25 -> V_31 ;
V_25 -> V_31 = 0 ;
}
static void F_41 ( struct V_24 * V_25 , void * V_47 )
{
V_25 -> V_37 = F_38 ;
V_25 -> V_38 = F_40 ;
V_25 -> V_31 = ( ( unsigned long ) V_47 ) & ( V_35 - 1 ) ;
V_25 -> V_34 = V_47 ;
}
static void F_42 ( int V_48 , unsigned V_12 , struct V_49 * V_50 ,
struct V_24 * V_25 , struct V_11 * V_11 )
{
struct V_10 * V_10 ;
struct V_26 * V_26 ;
unsigned long V_28 ;
unsigned V_29 ;
unsigned V_51 ;
T_2 V_52 = V_50 -> V_22 ;
struct V_53 * V_54 = F_43 ( V_50 -> V_55 ) ;
unsigned short V_56 = F_44 ( V_54 ) ;
T_2 V_57 ;
unsigned int V_58 ( V_59 ) ;
if ( V_48 & V_60 )
V_59 = V_54 -> V_61 . V_62 ;
else if ( V_48 & V_63 )
V_59 = V_54 -> V_61 . V_64 ;
if ( ( V_48 & ( V_60 | V_63 ) ) && V_59 == 0 ) {
F_20 ( V_11 , V_12 , - V_65 ) ;
return;
}
do {
if ( ( V_48 & V_60 ) || ( V_48 & V_63 ) )
V_51 = 1 ;
else
V_51 = F_45 ( int , F_46 ( V_50 -> V_55 ) ,
F_47 ( V_52 , ( V_35 >> V_66 ) ) ) ;
V_10 = F_48 ( V_67 , V_51 , V_11 -> V_2 -> V_9 ) ;
V_10 -> V_45 . V_68 = V_50 -> V_69 + ( V_50 -> V_22 - V_52 ) ;
V_10 -> V_70 = V_50 -> V_55 ;
V_10 -> V_71 = F_23 ;
F_11 ( V_10 , V_11 , V_12 ) ;
if ( V_48 & V_60 ) {
V_57 = F_45 ( T_2 , V_59 , V_52 ) ;
V_10 -> V_45 . V_72 = V_57 << V_66 ;
V_52 -= V_57 ;
} else if ( V_48 & V_63 ) {
V_25 -> V_37 ( V_25 , & V_26 , & V_28 , & V_29 ) ;
F_49 ( V_10 , V_26 , V_56 , V_29 ) ;
V_57 = F_45 ( T_2 , V_59 , V_52 ) ;
V_10 -> V_45 . V_72 = V_57 << V_66 ;
V_29 = 0 ;
V_52 -= V_57 ;
V_25 -> V_38 ( V_25 ) ;
} else while ( V_52 ) {
V_25 -> V_37 ( V_25 , & V_26 , & V_28 , & V_29 ) ;
V_28 = F_50 ( V_28 , F_51 ( V_52 ) ) ;
if ( ! F_49 ( V_10 , V_26 , V_28 , V_29 ) )
break;
V_29 = 0 ;
V_52 -= F_52 ( V_28 ) ;
V_25 -> V_38 ( V_25 ) ;
}
F_53 ( & V_11 -> V_22 ) ;
F_54 ( V_48 , V_10 ) ;
} while ( V_52 );
}
static void F_55 ( int V_48 , unsigned int V_73 ,
struct V_49 * V_50 , struct V_24 * V_25 ,
struct V_11 * V_11 , int V_74 )
{
int V_75 ;
struct V_24 V_76 = * V_25 ;
F_56 ( V_73 > V_13 ) ;
if ( V_74 )
V_48 |= V_77 ;
for ( V_75 = 0 ; V_75 < V_73 ; V_75 ++ ) {
* V_25 = V_76 ;
if ( V_50 [ V_75 ] . V_22 || ( V_48 & V_78 ) )
F_42 ( V_48 , V_75 , V_50 + V_75 , V_25 , V_11 ) ;
}
F_20 ( V_11 , 0 , 0 ) ;
}
static void F_57 ( unsigned long error , void * V_19 )
{
struct V_79 * V_80 = V_19 ;
V_80 -> V_16 = error ;
F_58 ( & V_80 -> V_81 ) ;
}
static int V_79 ( struct V_1 * V_2 , unsigned int V_73 ,
struct V_49 * V_50 , int V_48 , struct V_24 * V_25 ,
unsigned long * V_16 )
{
struct V_11 * V_11 ;
struct V_79 V_80 ;
if ( V_73 > 1 && ( V_48 & V_82 ) != V_83 ) {
F_59 ( 1 ) ;
return - V_84 ;
}
F_60 ( & V_80 . V_81 ) ;
V_11 = F_61 ( V_2 -> V_6 , V_67 ) ;
V_11 -> V_16 = 0 ;
F_62 ( & V_11 -> V_22 , 1 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = F_57 ;
V_11 -> V_19 = & V_80 ;
V_11 -> V_21 = V_25 -> V_21 ;
V_11 -> V_20 = V_25 -> V_20 ;
F_55 ( V_48 , V_73 , V_50 , V_25 , V_11 , 1 ) ;
F_63 ( & V_80 . V_81 ) ;
if ( V_16 )
* V_16 = V_80 . V_16 ;
return V_80 . V_16 ? - V_84 : 0 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_73 ,
struct V_49 * V_50 , int V_48 , struct V_24 * V_25 ,
T_1 V_17 , void * V_19 )
{
struct V_11 * V_11 ;
if ( V_73 > 1 && ( V_48 & V_82 ) != V_83 ) {
F_59 ( 1 ) ;
V_17 ( 1 , V_19 ) ;
return - V_84 ;
}
V_11 = F_61 ( V_2 -> V_6 , V_67 ) ;
V_11 -> V_16 = 0 ;
F_62 ( & V_11 -> V_22 , 1 ) ;
V_11 -> V_2 = V_2 ;
V_11 -> V_18 = V_17 ;
V_11 -> V_19 = V_19 ;
V_11 -> V_21 = V_25 -> V_21 ;
V_11 -> V_20 = V_25 -> V_20 ;
F_55 ( V_48 , V_73 , V_50 , V_25 , V_11 , 0 ) ;
return 0 ;
}
static int F_65 ( struct V_85 * V_86 , struct V_24 * V_25 ,
unsigned long V_87 )
{
V_25 -> V_21 = NULL ;
V_25 -> V_20 = 0 ;
switch ( V_86 -> V_88 . type ) {
case V_89 :
F_29 ( V_25 , V_86 -> V_88 . V_90 . V_33 , V_86 -> V_88 . V_29 ) ;
break;
case V_91 :
F_32 ( V_25 , V_86 -> V_88 . V_90 . V_10 ) ;
break;
case V_92 :
F_66 ( V_86 -> V_88 . V_90 . V_93 , V_87 ) ;
if ( ( V_86 -> V_94 & V_82 ) == V_23 ) {
V_25 -> V_21 = V_86 -> V_88 . V_90 . V_93 ;
V_25 -> V_20 = V_87 ;
}
F_37 ( V_25 , V_86 -> V_88 . V_90 . V_93 ) ;
break;
case V_95 :
F_41 ( V_25 , V_86 -> V_88 . V_90 . V_96 ) ;
break;
default:
return - V_97 ;
}
return 0 ;
}
int F_67 ( struct V_85 * V_86 , unsigned V_73 ,
struct V_49 * V_50 , unsigned long * V_98 )
{
int V_99 ;
struct V_24 V_25 ;
V_99 = F_65 ( V_86 , & V_25 , ( unsigned long ) V_50 -> V_22 << V_66 ) ;
if ( V_99 )
return V_99 ;
if ( ! V_86 -> V_100 . V_17 )
return V_79 ( V_86 -> V_2 , V_73 , V_50 ,
V_86 -> V_94 , & V_25 , V_98 ) ;
return F_64 ( V_86 -> V_2 , V_73 , V_50 , V_86 -> V_94 ,
& V_25 , V_86 -> V_100 . V_17 , V_86 -> V_100 . V_19 ) ;
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
