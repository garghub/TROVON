struct V_1 * F_1 ( void )
{
struct V_1 * V_2 ;
V_2 = F_2 ( sizeof( * V_2 ) , V_3 ) ;
if ( ! V_2 )
return F_3 ( - V_4 ) ;
V_2 -> V_5 = F_4 ( V_6 , V_7 ) ;
if ( ! V_2 -> V_5 )
goto V_8;
V_2 -> V_9 = F_5 ( V_10 , 0 ) ;
if ( ! V_2 -> V_9 )
goto V_8;
return V_2 ;
V_8:
if ( V_2 -> V_5 )
F_6 ( V_2 -> V_5 ) ;
F_7 ( V_2 ) ;
return F_3 ( - V_4 ) ;
}
void F_8 ( struct V_1 * V_2 )
{
F_6 ( V_2 -> V_5 ) ;
F_9 ( V_2 -> V_9 ) ;
F_7 ( V_2 ) ;
}
static void F_10 ( struct V_11 * V_11 , struct V_12 * V_12 ,
unsigned V_13 )
{
if ( F_11 ( ! F_12 ( ( unsigned long ) V_12 , V_14 ) ) ) {
F_13 ( L_1 , V_12 ) ;
F_14 () ;
}
V_11 -> V_15 = ( void * ) ( ( unsigned long ) V_12 | V_13 ) ;
}
static void F_15 ( struct V_11 * V_11 , struct V_12 * * V_12 ,
unsigned * V_13 )
{
unsigned long V_16 = ( unsigned long ) V_11 -> V_15 ;
* V_12 = ( void * ) ( V_16 & - ( unsigned long ) V_14 ) ;
* V_13 = V_16 & ( V_14 - 1 ) ;
}
static void F_16 ( struct V_12 * V_12 , unsigned int V_13 , int error )
{
if ( error )
F_17 ( V_13 , & V_12 -> V_17 ) ;
if ( F_18 ( & V_12 -> V_18 ) ) {
if ( V_12 -> V_19 )
F_19 ( V_12 -> V_20 ,
V_12 -> V_19 ) ;
if ( V_12 -> V_21 )
F_20 ( V_12 -> V_21 ) ;
else {
unsigned long V_22 = V_12 -> V_17 ;
T_1 V_23 = V_12 -> V_24 ;
void * V_25 = V_12 -> V_25 ;
F_21 ( V_12 , V_12 -> V_2 -> V_5 ) ;
V_23 ( V_22 , V_25 ) ;
}
}
}
static void F_22 ( struct V_11 * V_11 , int error )
{
struct V_12 * V_12 ;
unsigned V_13 ;
if ( error && F_23 ( V_11 ) == V_26 )
F_24 ( V_11 ) ;
F_15 ( V_11 , & V_12 , & V_13 ) ;
F_25 ( V_11 ) ;
F_16 ( V_12 , V_13 , error ) ;
}
static void F_26 ( struct V_27 * V_28 ,
struct V_29 * * V_30 , unsigned long * V_31 , unsigned * V_32 )
{
unsigned V_33 = V_28 -> V_34 ;
struct V_35 * V_36 = (struct V_35 * ) V_28 -> V_37 ;
* V_30 = V_36 -> V_29 ;
* V_31 = V_38 - V_33 ;
* V_32 = V_33 ;
}
static void F_27 ( struct V_27 * V_28 )
{
struct V_35 * V_36 = (struct V_35 * ) V_28 -> V_37 ;
V_28 -> V_37 = V_36 -> V_39 ;
V_28 -> V_34 = 0 ;
}
static void F_28 ( struct V_27 * V_28 , struct V_35 * V_36 , unsigned V_32 )
{
V_28 -> V_40 = F_26 ;
V_28 -> V_41 = F_27 ;
V_28 -> V_34 = V_32 ;
V_28 -> V_37 = V_36 ;
}
static void F_29 ( struct V_27 * V_28 ,
struct V_29 * * V_30 , unsigned long * V_31 , unsigned * V_32 )
{
struct V_42 * V_43 = (struct V_42 * ) V_28 -> V_37 ;
* V_30 = V_43 -> V_44 ;
* V_31 = V_43 -> V_45 ;
* V_32 = V_43 -> V_46 ;
}
static void F_30 ( struct V_27 * V_28 )
{
struct V_42 * V_43 = (struct V_42 * ) V_28 -> V_37 ;
V_28 -> V_37 = V_43 + 1 ;
}
static void F_31 ( struct V_27 * V_28 , struct V_42 * V_43 )
{
V_28 -> V_40 = F_29 ;
V_28 -> V_41 = F_30 ;
V_28 -> V_37 = V_43 ;
}
static void F_32 ( struct V_27 * V_28 ,
struct V_29 * * V_30 , unsigned long * V_31 , unsigned * V_32 )
{
* V_30 = F_33 ( V_28 -> V_37 ) ;
* V_32 = V_28 -> V_34 ;
* V_31 = V_38 - V_28 -> V_34 ;
}
static void F_34 ( struct V_27 * V_28 )
{
V_28 -> V_37 += V_38 - V_28 -> V_34 ;
V_28 -> V_34 = 0 ;
}
static void F_35 ( struct V_27 * V_28 , void * V_47 )
{
V_28 -> V_40 = F_32 ;
V_28 -> V_41 = F_34 ;
V_28 -> V_34 = ( ( unsigned long ) V_47 ) & ( V_38 - 1 ) ;
V_28 -> V_37 = V_47 ;
}
static void F_36 ( struct V_27 * V_28 , struct V_29 * * V_30 , unsigned long * V_31 ,
unsigned * V_32 )
{
* V_30 = F_37 ( V_28 -> V_37 ) ;
* V_32 = V_28 -> V_34 ;
* V_31 = V_38 - V_28 -> V_34 ;
}
static void F_38 ( struct V_27 * V_28 )
{
V_28 -> V_37 += V_38 - V_28 -> V_34 ;
V_28 -> V_34 = 0 ;
}
static void F_39 ( struct V_27 * V_28 , void * V_47 )
{
V_28 -> V_40 = F_36 ;
V_28 -> V_41 = F_38 ;
V_28 -> V_34 = ( ( unsigned long ) V_47 ) & ( V_38 - 1 ) ;
V_28 -> V_37 = V_47 ;
}
static void F_40 ( int V_48 , unsigned V_13 , struct V_49 * V_50 ,
struct V_27 * V_28 , struct V_12 * V_12 )
{
struct V_11 * V_11 ;
struct V_29 * V_29 ;
unsigned long V_31 ;
unsigned V_32 ;
unsigned V_51 ;
T_2 V_52 = V_50 -> V_18 ;
struct V_53 * V_54 = F_41 ( V_50 -> V_55 ) ;
T_2 V_56 ;
do {
if ( V_48 & V_57 )
V_51 = 1 ;
else
V_51 = F_42 ( int , F_43 ( V_50 -> V_55 ) ,
F_44 ( V_52 , ( V_38 >> V_58 ) ) ) ;
V_11 = F_45 ( V_59 , V_51 , V_12 -> V_2 -> V_9 ) ;
V_11 -> V_60 = V_50 -> V_61 + ( V_50 -> V_18 - V_52 ) ;
V_11 -> V_62 = V_50 -> V_55 ;
V_11 -> V_63 = F_22 ;
F_10 ( V_11 , V_12 , V_13 ) ;
if ( V_48 & V_57 ) {
V_56 = F_42 ( T_2 , V_54 -> V_64 . V_65 , V_52 ) ;
V_11 -> V_66 = V_56 << V_58 ;
V_52 -= V_56 ;
} else while ( V_52 ) {
V_28 -> V_40 ( V_28 , & V_29 , & V_31 , & V_32 ) ;
V_31 = F_46 ( V_31 , F_47 ( V_52 ) ) ;
if ( ! F_48 ( V_11 , V_29 , V_31 , V_32 ) )
break;
V_32 = 0 ;
V_52 -= F_49 ( V_31 ) ;
V_28 -> V_41 ( V_28 ) ;
}
F_50 ( & V_12 -> V_18 ) ;
F_51 ( V_48 , V_11 ) ;
} while ( V_52 );
}
static void F_52 ( int V_48 , unsigned int V_67 ,
struct V_49 * V_50 , struct V_27 * V_28 ,
struct V_12 * V_12 , int V_68 )
{
int V_69 ;
struct V_27 V_70 = * V_28 ;
F_53 ( V_67 > V_14 ) ;
if ( V_68 )
V_48 |= V_71 ;
for ( V_69 = 0 ; V_69 < V_67 ; V_69 ++ ) {
* V_28 = V_70 ;
if ( V_50 [ V_69 ] . V_18 || ( V_48 & V_72 ) )
F_40 ( V_48 , V_69 , V_50 + V_69 , V_28 , V_12 ) ;
}
F_16 ( V_12 , 0 , 0 ) ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_67 ,
struct V_49 * V_50 , int V_48 , struct V_27 * V_28 ,
unsigned long * V_17 )
{
volatile char V_73 [ sizeof( struct V_12 ) + F_55 ( struct V_12 ) - 1 ] ;
struct V_12 * V_12 = (struct V_12 * ) F_56 ( & V_73 , F_55 ( struct V_12 ) ) ;
if ( V_67 > 1 && ( V_48 & V_74 ) != V_75 ) {
F_57 ( 1 ) ;
return - V_76 ;
}
V_12 -> V_17 = 0 ;
F_58 ( & V_12 -> V_18 , 1 ) ;
V_12 -> V_21 = V_77 ;
V_12 -> V_2 = V_2 ;
V_12 -> V_20 = V_28 -> V_20 ;
V_12 -> V_19 = V_28 -> V_19 ;
F_52 ( V_48 , V_67 , V_50 , V_28 , V_12 , 1 ) ;
while ( 1 ) {
F_59 ( V_78 ) ;
if ( ! F_60 ( & V_12 -> V_18 ) )
break;
F_61 () ;
}
F_59 ( V_79 ) ;
if ( V_17 )
* V_17 = V_12 -> V_17 ;
return V_12 -> V_17 ? - V_76 : 0 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_67 ,
struct V_49 * V_50 , int V_48 , struct V_27 * V_28 ,
T_1 V_23 , void * V_25 )
{
struct V_12 * V_12 ;
if ( V_67 > 1 && ( V_48 & V_74 ) != V_75 ) {
F_57 ( 1 ) ;
V_23 ( 1 , V_25 ) ;
return - V_76 ;
}
V_12 = F_63 ( V_2 -> V_5 , V_59 ) ;
V_12 -> V_17 = 0 ;
F_58 ( & V_12 -> V_18 , 1 ) ;
V_12 -> V_21 = NULL ;
V_12 -> V_2 = V_2 ;
V_12 -> V_24 = V_23 ;
V_12 -> V_25 = V_25 ;
V_12 -> V_20 = V_28 -> V_20 ;
V_12 -> V_19 = V_28 -> V_19 ;
F_52 ( V_48 , V_67 , V_50 , V_28 , V_12 , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_80 * V_81 , struct V_27 * V_28 ,
unsigned long V_82 )
{
V_28 -> V_20 = NULL ;
V_28 -> V_19 = 0 ;
switch ( V_81 -> V_83 . type ) {
case V_84 :
F_28 ( V_28 , V_81 -> V_83 . V_85 . V_36 , V_81 -> V_83 . V_32 ) ;
break;
case V_86 :
F_31 ( V_28 , V_81 -> V_83 . V_85 . V_43 ) ;
break;
case V_87 :
F_65 ( V_81 -> V_83 . V_85 . V_88 , V_82 ) ;
if ( ( V_81 -> V_89 & V_74 ) == V_26 ) {
V_28 -> V_20 = V_81 -> V_83 . V_85 . V_88 ;
V_28 -> V_19 = V_82 ;
}
F_35 ( V_28 , V_81 -> V_83 . V_85 . V_88 ) ;
break;
case V_90 :
F_39 ( V_28 , V_81 -> V_83 . V_85 . V_91 ) ;
break;
default:
return - V_92 ;
}
return 0 ;
}
int F_66 ( struct V_80 * V_81 , unsigned V_67 ,
struct V_49 * V_50 , unsigned long * V_93 )
{
int V_22 ;
struct V_27 V_28 ;
V_22 = F_64 ( V_81 , & V_28 , ( unsigned long ) V_50 -> V_18 << V_58 ) ;
if ( V_22 )
return V_22 ;
if ( ! V_81 -> V_94 . V_23 )
return F_54 ( V_81 -> V_2 , V_67 , V_50 ,
V_81 -> V_89 , & V_28 , V_93 ) ;
return F_62 ( V_81 -> V_2 , V_67 , V_50 , V_81 -> V_89 ,
& V_28 , V_81 -> V_94 . V_23 , V_81 -> V_94 . V_25 ) ;
}
int T_3 F_67 ( void )
{
V_7 = F_68 ( V_12 , 0 ) ;
if ( ! V_7 )
return - V_4 ;
return 0 ;
}
void F_69 ( void )
{
F_70 ( V_7 ) ;
V_7 = NULL ;
}
