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
static void F_17 ( struct V_11 * V_11 , unsigned int V_12 , int error )
{
if ( error )
F_18 ( V_12 , & V_11 -> V_16 ) ;
if ( F_19 ( & V_11 -> V_17 ) ) {
if ( V_11 -> V_18 )
F_20 ( V_11 -> V_19 ,
V_11 -> V_18 ) ;
if ( V_11 -> V_20 )
F_21 ( V_11 -> V_20 ) ;
else {
unsigned long V_21 = V_11 -> V_16 ;
T_1 V_22 = V_11 -> V_23 ;
void * V_24 = V_11 -> V_24 ;
F_22 ( V_11 , V_11 -> V_2 -> V_6 ) ;
V_22 ( V_21 , V_24 ) ;
}
}
}
static void F_23 ( struct V_10 * V_10 , int error )
{
struct V_11 * V_11 ;
unsigned V_12 ;
if ( error && F_24 ( V_10 ) == V_25 )
F_25 ( V_10 ) ;
F_16 ( V_10 , & V_11 , & V_12 ) ;
F_26 ( V_10 ) ;
F_17 ( V_11 , V_12 , error ) ;
}
static void F_27 ( struct V_26 * V_27 ,
struct V_28 * * V_29 , unsigned long * V_30 , unsigned * V_31 )
{
unsigned V_32 = V_27 -> V_33 ;
struct V_34 * V_35 = (struct V_34 * ) V_27 -> V_36 ;
* V_29 = V_35 -> V_28 ;
* V_30 = V_37 - V_32 ;
* V_31 = V_32 ;
}
static void F_28 ( struct V_26 * V_27 )
{
struct V_34 * V_35 = (struct V_34 * ) V_27 -> V_36 ;
V_27 -> V_36 = V_35 -> V_38 ;
V_27 -> V_33 = 0 ;
}
static void F_29 ( struct V_26 * V_27 , struct V_34 * V_35 , unsigned V_31 )
{
V_27 -> V_39 = F_27 ;
V_27 -> V_40 = F_28 ;
V_27 -> V_33 = V_31 ;
V_27 -> V_36 = V_35 ;
}
static void F_30 ( struct V_26 * V_27 , struct V_28 * * V_29 ,
unsigned long * V_30 , unsigned * V_31 )
{
struct V_41 * V_42 = V_27 -> V_36 ;
* V_29 = V_42 -> V_43 ;
* V_30 = V_42 -> V_44 - V_27 -> V_33 ;
* V_31 = V_42 -> V_45 + V_27 -> V_33 ;
}
static void F_31 ( struct V_26 * V_27 )
{
struct V_41 * V_42 = V_27 -> V_36 ;
V_27 -> V_36 = V_42 + 1 ;
V_27 -> V_33 = 0 ;
}
static void F_32 ( struct V_26 * V_27 , struct V_10 * V_10 )
{
V_27 -> V_39 = F_30 ;
V_27 -> V_40 = F_31 ;
V_27 -> V_36 = F_33 ( V_10 -> V_46 , V_10 -> V_47 ) ;
V_27 -> V_33 = V_10 -> V_47 . V_48 ;
}
static void F_34 ( struct V_26 * V_27 ,
struct V_28 * * V_29 , unsigned long * V_30 , unsigned * V_31 )
{
* V_29 = F_35 ( V_27 -> V_36 ) ;
* V_31 = V_27 -> V_33 ;
* V_30 = V_37 - V_27 -> V_33 ;
}
static void F_36 ( struct V_26 * V_27 )
{
V_27 -> V_36 += V_37 - V_27 -> V_33 ;
V_27 -> V_33 = 0 ;
}
static void F_37 ( struct V_26 * V_27 , void * V_49 )
{
V_27 -> V_39 = F_34 ;
V_27 -> V_40 = F_36 ;
V_27 -> V_33 = ( ( unsigned long ) V_49 ) & ( V_37 - 1 ) ;
V_27 -> V_36 = V_49 ;
}
static void F_38 ( struct V_26 * V_27 , struct V_28 * * V_29 , unsigned long * V_30 ,
unsigned * V_31 )
{
* V_29 = F_39 ( V_27 -> V_36 ) ;
* V_31 = V_27 -> V_33 ;
* V_30 = V_37 - V_27 -> V_33 ;
}
static void F_40 ( struct V_26 * V_27 )
{
V_27 -> V_36 += V_37 - V_27 -> V_33 ;
V_27 -> V_33 = 0 ;
}
static void F_41 ( struct V_26 * V_27 , void * V_49 )
{
V_27 -> V_39 = F_38 ;
V_27 -> V_40 = F_40 ;
V_27 -> V_33 = ( ( unsigned long ) V_49 ) & ( V_37 - 1 ) ;
V_27 -> V_36 = V_49 ;
}
static void F_42 ( int V_50 , unsigned V_12 , struct V_51 * V_52 ,
struct V_26 * V_27 , struct V_11 * V_11 )
{
struct V_10 * V_10 ;
struct V_28 * V_28 ;
unsigned long V_30 ;
unsigned V_31 ;
unsigned V_53 ;
T_2 V_54 = V_52 -> V_17 ;
struct V_55 * V_56 = F_43 ( V_52 -> V_57 ) ;
unsigned short V_58 = F_44 ( V_56 ) ;
T_2 V_59 ;
do {
if ( ( V_50 & V_60 ) || ( V_50 & V_61 ) )
V_53 = 1 ;
else
V_53 = F_45 ( int , F_46 ( V_52 -> V_57 ) ,
F_47 ( V_54 , ( V_37 >> V_62 ) ) ) ;
V_10 = F_48 ( V_63 , V_53 , V_11 -> V_2 -> V_9 ) ;
V_10 -> V_47 . V_64 = V_52 -> V_65 + ( V_52 -> V_17 - V_54 ) ;
V_10 -> V_66 = V_52 -> V_57 ;
V_10 -> V_67 = F_23 ;
F_11 ( V_10 , V_11 , V_12 ) ;
if ( V_50 & V_60 ) {
V_59 = F_45 ( T_2 , V_56 -> V_68 . V_69 , V_54 ) ;
V_10 -> V_47 . V_70 = V_59 << V_62 ;
V_54 -= V_59 ;
} else if ( V_50 & V_61 ) {
V_27 -> V_39 ( V_27 , & V_28 , & V_30 , & V_31 ) ;
F_49 ( V_10 , V_28 , V_58 , V_31 ) ;
V_59 = F_45 ( T_2 , V_56 -> V_68 . V_71 , V_54 ) ;
V_10 -> V_47 . V_70 = V_59 << V_62 ;
V_31 = 0 ;
V_54 -= V_59 ;
V_27 -> V_40 ( V_27 ) ;
} else while ( V_54 ) {
V_27 -> V_39 ( V_27 , & V_28 , & V_30 , & V_31 ) ;
V_30 = F_50 ( V_30 , F_51 ( V_54 ) ) ;
if ( ! F_49 ( V_10 , V_28 , V_30 , V_31 ) )
break;
V_31 = 0 ;
V_54 -= F_52 ( V_30 ) ;
V_27 -> V_40 ( V_27 ) ;
}
F_53 ( & V_11 -> V_17 ) ;
F_54 ( V_50 , V_10 ) ;
} while ( V_54 );
}
static void F_55 ( int V_50 , unsigned int V_72 ,
struct V_51 * V_52 , struct V_26 * V_27 ,
struct V_11 * V_11 , int V_73 )
{
int V_74 ;
struct V_26 V_75 = * V_27 ;
F_56 ( V_72 > V_13 ) ;
if ( V_73 )
V_50 |= V_76 ;
for ( V_74 = 0 ; V_74 < V_72 ; V_74 ++ ) {
* V_27 = V_75 ;
if ( V_52 [ V_74 ] . V_17 || ( V_50 & V_77 ) )
F_42 ( V_50 , V_74 , V_52 + V_74 , V_27 , V_11 ) ;
}
F_17 ( V_11 , 0 , 0 ) ;
}
static int F_57 ( struct V_1 * V_2 , unsigned int V_72 ,
struct V_51 * V_52 , int V_50 , struct V_26 * V_27 ,
unsigned long * V_16 )
{
volatile char V_78 [ sizeof( struct V_11 ) + F_58 ( struct V_11 ) - 1 ] ;
struct V_11 * V_11 = (struct V_11 * ) F_59 ( & V_78 , F_58 ( struct V_11 ) ) ;
F_60 ( V_20 ) ;
if ( V_72 > 1 && ( V_50 & V_79 ) != V_80 ) {
F_61 ( 1 ) ;
return - V_81 ;
}
V_11 -> V_16 = 0 ;
F_62 ( & V_11 -> V_17 , 1 ) ;
V_11 -> V_20 = & V_20 ;
V_11 -> V_2 = V_2 ;
V_11 -> V_19 = V_27 -> V_19 ;
V_11 -> V_18 = V_27 -> V_18 ;
F_55 ( V_50 , V_72 , V_52 , V_27 , V_11 , 1 ) ;
F_63 ( & V_20 ) ;
if ( V_16 )
* V_16 = V_11 -> V_16 ;
return V_11 -> V_16 ? - V_81 : 0 ;
}
static int F_64 ( struct V_1 * V_2 , unsigned int V_72 ,
struct V_51 * V_52 , int V_50 , struct V_26 * V_27 ,
T_1 V_22 , void * V_24 )
{
struct V_11 * V_11 ;
if ( V_72 > 1 && ( V_50 & V_79 ) != V_80 ) {
F_61 ( 1 ) ;
V_22 ( 1 , V_24 ) ;
return - V_81 ;
}
V_11 = F_65 ( V_2 -> V_6 , V_63 ) ;
V_11 -> V_16 = 0 ;
F_62 ( & V_11 -> V_17 , 1 ) ;
V_11 -> V_20 = NULL ;
V_11 -> V_2 = V_2 ;
V_11 -> V_23 = V_22 ;
V_11 -> V_24 = V_24 ;
V_11 -> V_19 = V_27 -> V_19 ;
V_11 -> V_18 = V_27 -> V_18 ;
F_55 ( V_50 , V_72 , V_52 , V_27 , V_11 , 0 ) ;
return 0 ;
}
static int F_66 ( struct V_82 * V_83 , struct V_26 * V_27 ,
unsigned long V_84 )
{
V_27 -> V_19 = NULL ;
V_27 -> V_18 = 0 ;
switch ( V_83 -> V_85 . type ) {
case V_86 :
F_29 ( V_27 , V_83 -> V_85 . V_87 . V_35 , V_83 -> V_85 . V_31 ) ;
break;
case V_88 :
F_32 ( V_27 , V_83 -> V_85 . V_87 . V_10 ) ;
break;
case V_89 :
F_67 ( V_83 -> V_85 . V_87 . V_90 , V_84 ) ;
if ( ( V_83 -> V_91 & V_79 ) == V_25 ) {
V_27 -> V_19 = V_83 -> V_85 . V_87 . V_90 ;
V_27 -> V_18 = V_84 ;
}
F_37 ( V_27 , V_83 -> V_85 . V_87 . V_90 ) ;
break;
case V_92 :
F_41 ( V_27 , V_83 -> V_85 . V_87 . V_93 ) ;
break;
default:
return - V_94 ;
}
return 0 ;
}
int F_68 ( struct V_82 * V_83 , unsigned V_72 ,
struct V_51 * V_52 , unsigned long * V_95 )
{
int V_21 ;
struct V_26 V_27 ;
V_21 = F_66 ( V_83 , & V_27 , ( unsigned long ) V_52 -> V_17 << V_62 ) ;
if ( V_21 )
return V_21 ;
if ( ! V_83 -> V_96 . V_22 )
return F_57 ( V_83 -> V_2 , V_72 , V_52 ,
V_83 -> V_91 , & V_27 , V_95 ) ;
return F_64 ( V_83 -> V_2 , V_72 , V_52 , V_83 -> V_91 ,
& V_27 , V_83 -> V_96 . V_22 , V_83 -> V_96 . V_24 ) ;
}
int T_3 F_69 ( void )
{
V_7 = F_70 ( V_11 , 0 ) ;
if ( ! V_7 )
return - V_5 ;
return 0 ;
}
void F_71 ( void )
{
F_72 ( V_7 ) ;
V_7 = NULL ;
}
