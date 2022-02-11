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
F_19 ( V_12 -> V_19 ) ;
else {
unsigned long V_20 = V_12 -> V_17 ;
T_1 V_21 = V_12 -> V_22 ;
void * V_23 = V_12 -> V_23 ;
F_20 ( V_12 , V_12 -> V_2 -> V_5 ) ;
V_21 ( V_20 , V_23 ) ;
}
}
}
static void F_21 ( struct V_11 * V_11 , int error )
{
struct V_12 * V_12 ;
unsigned V_13 ;
if ( error && F_22 ( V_11 ) == V_24 )
F_23 ( V_11 ) ;
F_15 ( V_11 , & V_12 , & V_13 ) ;
F_24 ( V_11 ) ;
F_16 ( V_12 , V_13 , error ) ;
}
static void F_25 ( struct V_25 * V_26 ,
struct V_27 * * V_28 , unsigned long * V_29 , unsigned * V_30 )
{
unsigned V_31 = V_26 -> V_32 ;
struct V_33 * V_34 = (struct V_33 * ) V_26 -> V_35 ;
* V_28 = V_34 -> V_27 ;
* V_29 = V_36 - V_31 ;
* V_30 = V_31 ;
}
static void F_26 ( struct V_25 * V_26 )
{
struct V_33 * V_34 = (struct V_33 * ) V_26 -> V_35 ;
V_26 -> V_35 = V_34 -> V_37 ;
V_26 -> V_32 = 0 ;
}
static void F_27 ( struct V_25 * V_26 , struct V_33 * V_34 , unsigned V_30 )
{
V_26 -> V_38 = F_25 ;
V_26 -> V_39 = F_26 ;
V_26 -> V_32 = V_30 ;
V_26 -> V_35 = V_34 ;
}
static void F_28 ( struct V_25 * V_26 ,
struct V_27 * * V_28 , unsigned long * V_29 , unsigned * V_30 )
{
struct V_40 * V_41 = (struct V_40 * ) V_26 -> V_35 ;
* V_28 = V_41 -> V_42 ;
* V_29 = V_41 -> V_43 ;
* V_30 = V_41 -> V_44 ;
}
static void F_29 ( struct V_25 * V_26 )
{
struct V_40 * V_41 = (struct V_40 * ) V_26 -> V_35 ;
V_26 -> V_35 = V_41 + 1 ;
}
static void F_30 ( struct V_25 * V_26 , struct V_40 * V_41 )
{
V_26 -> V_38 = F_28 ;
V_26 -> V_39 = F_29 ;
V_26 -> V_35 = V_41 ;
}
static void F_31 ( struct V_25 * V_26 ,
struct V_27 * * V_28 , unsigned long * V_29 , unsigned * V_30 )
{
* V_28 = F_32 ( V_26 -> V_35 ) ;
* V_30 = V_26 -> V_32 ;
* V_29 = V_36 - V_26 -> V_32 ;
}
static void F_33 ( struct V_25 * V_26 )
{
V_26 -> V_35 += V_36 - V_26 -> V_32 ;
V_26 -> V_32 = 0 ;
}
static void F_34 ( struct V_25 * V_26 , void * V_45 )
{
V_26 -> V_38 = F_31 ;
V_26 -> V_39 = F_33 ;
V_26 -> V_32 = ( ( unsigned long ) V_45 ) & ( V_36 - 1 ) ;
V_26 -> V_35 = V_45 ;
}
static void F_35 ( struct V_11 * V_11 )
{
unsigned V_13 ;
struct V_12 * V_12 ;
F_15 ( V_11 , & V_12 , & V_13 ) ;
F_36 ( V_11 , V_12 -> V_2 -> V_9 ) ;
}
static void F_37 ( struct V_25 * V_26 , struct V_27 * * V_28 , unsigned long * V_29 ,
unsigned * V_30 )
{
* V_28 = F_38 ( V_26 -> V_35 ) ;
* V_30 = V_26 -> V_32 ;
* V_29 = V_36 - V_26 -> V_32 ;
}
static void F_39 ( struct V_25 * V_26 )
{
V_26 -> V_35 += V_36 - V_26 -> V_32 ;
V_26 -> V_32 = 0 ;
}
static void F_40 ( struct V_25 * V_26 , void * V_45 )
{
V_26 -> V_38 = F_37 ;
V_26 -> V_39 = F_39 ;
V_26 -> V_32 = ( ( unsigned long ) V_45 ) & ( V_36 - 1 ) ;
V_26 -> V_35 = V_45 ;
}
static void F_41 ( int V_46 , unsigned V_13 , struct V_47 * V_48 ,
struct V_25 * V_26 , struct V_12 * V_12 )
{
struct V_11 * V_11 ;
struct V_27 * V_27 ;
unsigned long V_29 ;
unsigned V_30 ;
unsigned V_49 ;
T_2 V_50 = V_48 -> V_18 ;
do {
V_49 = F_42 ( V_50 ,
( V_36 >> V_51 ) ) ;
V_49 = F_43 ( int , F_44 ( V_48 -> V_52 ) , V_49 ) ;
V_11 = F_45 ( V_53 , V_49 , V_12 -> V_2 -> V_9 ) ;
V_11 -> V_54 = V_48 -> V_55 + ( V_48 -> V_18 - V_50 ) ;
V_11 -> V_56 = V_48 -> V_52 ;
V_11 -> V_57 = F_21 ;
V_11 -> V_58 = F_35 ;
F_10 ( V_11 , V_12 , V_13 ) ;
while ( V_50 ) {
V_26 -> V_38 ( V_26 , & V_27 , & V_29 , & V_30 ) ;
V_29 = F_46 ( V_29 , F_47 ( V_50 ) ) ;
if ( ! F_48 ( V_11 , V_27 , V_29 , V_30 ) )
break;
V_30 = 0 ;
V_50 -= F_49 ( V_29 ) ;
V_26 -> V_39 ( V_26 ) ;
}
F_50 ( & V_12 -> V_18 ) ;
F_51 ( V_46 , V_11 ) ;
} while ( V_50 );
}
static void F_52 ( int V_46 , unsigned int V_59 ,
struct V_47 * V_48 , struct V_25 * V_26 ,
struct V_12 * V_12 , int V_60 )
{
int V_61 ;
struct V_25 V_62 = * V_26 ;
F_53 ( V_59 > V_14 ) ;
if ( V_60 )
V_46 |= V_63 ;
for ( V_61 = 0 ; V_61 < V_59 ; V_61 ++ ) {
* V_26 = V_62 ;
if ( V_48 [ V_61 ] . V_18 || ( V_46 & V_64 ) )
F_41 ( V_46 , V_61 , V_48 + V_61 , V_26 , V_12 ) ;
}
F_16 ( V_12 , 0 , 0 ) ;
}
static int F_54 ( struct V_1 * V_2 , unsigned int V_59 ,
struct V_47 * V_48 , int V_46 , struct V_25 * V_26 ,
unsigned long * V_17 )
{
volatile char V_65 [ sizeof( struct V_12 ) + F_55 ( struct V_12 ) - 1 ] ;
struct V_12 * V_12 = (struct V_12 * ) F_56 ( & V_65 , F_55 ( struct V_12 ) ) ;
if ( V_59 > 1 && ( V_46 & V_66 ) != V_67 ) {
F_57 ( 1 ) ;
return - V_68 ;
}
V_12 -> V_17 = 0 ;
F_58 ( & V_12 -> V_18 , 1 ) ;
V_12 -> V_19 = V_69 ;
V_12 -> V_2 = V_2 ;
F_52 ( V_46 , V_59 , V_48 , V_26 , V_12 , 1 ) ;
while ( 1 ) {
F_59 ( V_70 ) ;
if ( ! F_60 ( & V_12 -> V_18 ) )
break;
F_61 () ;
}
F_59 ( V_71 ) ;
if ( V_17 )
* V_17 = V_12 -> V_17 ;
return V_12 -> V_17 ? - V_68 : 0 ;
}
static int F_62 ( struct V_1 * V_2 , unsigned int V_59 ,
struct V_47 * V_48 , int V_46 , struct V_25 * V_26 ,
T_1 V_21 , void * V_23 )
{
struct V_12 * V_12 ;
if ( V_59 > 1 && ( V_46 & V_66 ) != V_67 ) {
F_57 ( 1 ) ;
V_21 ( 1 , V_23 ) ;
return - V_68 ;
}
V_12 = F_63 ( V_2 -> V_5 , V_53 ) ;
V_12 -> V_17 = 0 ;
F_58 ( & V_12 -> V_18 , 1 ) ;
V_12 -> V_19 = NULL ;
V_12 -> V_2 = V_2 ;
V_12 -> V_22 = V_21 ;
V_12 -> V_23 = V_23 ;
F_52 ( V_46 , V_59 , V_48 , V_26 , V_12 , 0 ) ;
return 0 ;
}
static int F_64 ( struct V_72 * V_73 , struct V_25 * V_26 )
{
switch ( V_73 -> V_74 . type ) {
case V_75 :
F_27 ( V_26 , V_73 -> V_74 . V_76 . V_34 , V_73 -> V_74 . V_30 ) ;
break;
case V_77 :
F_30 ( V_26 , V_73 -> V_74 . V_76 . V_41 ) ;
break;
case V_78 :
F_34 ( V_26 , V_73 -> V_74 . V_76 . V_79 ) ;
break;
case V_80 :
F_40 ( V_26 , V_73 -> V_74 . V_76 . V_81 ) ;
break;
default:
return - V_82 ;
}
return 0 ;
}
int F_65 ( struct V_72 * V_73 , unsigned V_59 ,
struct V_47 * V_48 , unsigned long * V_83 )
{
int V_20 ;
struct V_25 V_26 ;
V_20 = F_64 ( V_73 , & V_26 ) ;
if ( V_20 )
return V_20 ;
if ( ! V_73 -> V_84 . V_21 )
return F_54 ( V_73 -> V_2 , V_59 , V_48 ,
V_73 -> V_85 , & V_26 , V_83 ) ;
return F_62 ( V_73 -> V_2 , V_59 , V_48 , V_73 -> V_85 ,
& V_26 , V_73 -> V_84 . V_21 , V_73 -> V_84 . V_23 ) ;
}
int T_3 F_66 ( void )
{
V_7 = F_67 ( V_12 , 0 ) ;
if ( ! V_7 )
return - V_4 ;
return 0 ;
}
void F_68 ( void )
{
F_69 ( V_7 ) ;
V_7 = NULL ;
}
