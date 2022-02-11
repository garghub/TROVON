static void F_1 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned long V_4 )
{
F_2 ( V_3 , V_4 ) ;
}
static unsigned char F_3 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
return F_4 ( V_4 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned char V_3 ,
unsigned long V_4 )
{
F_6 ( V_3 , ( void V_5 * ) V_4 ) ;
}
static unsigned char F_7 ( struct V_1 * V_2 ,
unsigned long V_4 )
{
return F_8 ( ( void V_5 * ) V_4 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
int V_6 = 100000 ;
for (; V_6 > 0 && F_10 ( V_2 ) ; V_6 -- )
V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) ;
#ifdef F_12
if ( V_6 <= 0 )
F_13 ( V_8 L_1 ,
V_2 -> V_7 ( V_2 , F_14 ( V_2 ) ) ) ;
#endif
}
static void F_15 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
if ( F_16 ( V_10 , & V_2 -> V_11 ) &&
F_16 ( V_12 , & V_2 -> V_11 ) ) {
F_17 ( & V_2 -> V_13 , V_9 ) ;
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_13 , V_9 ) ;
}
}
static void F_20 ( struct V_1 * V_2 )
{
unsigned long V_9 ;
if ( V_2 -> V_14 & V_15 ) {
F_17 ( & V_2 -> V_16 , V_9 ) ;
if ( F_16 ( V_17 , & V_2 -> V_11 ) )
F_21 ( V_2 ) ;
else
F_9 ( V_2 ) ;
F_19 ( & V_2 -> V_16 , V_9 ) ;
}
if ( ! ( V_2 -> V_14 & V_18 ) )
F_15 ( V_2 ) ;
}
T_1 F_22 ( int V_19 , void * V_20 )
{
struct V_1 * V_2 = V_20 ;
if ( V_2 == NULL )
return V_21 ;
F_20 ( V_2 ) ;
return V_22 ;
}
T_1 F_23 ( int V_19 , void * V_20 )
{
struct V_1 * V_2 = V_20 ;
if ( V_2 == NULL )
return V_21 ;
F_15 ( V_2 ) ;
return V_22 ;
}
static void F_24 ( unsigned long V_3 )
{
struct V_1 * V_2 = (struct V_1 * ) V_3 ;
unsigned long V_9 ;
F_17 ( & V_2 -> V_23 , V_9 ) ;
F_25 ( & V_2 -> V_24 , 1 + V_25 ) ;
F_19 ( & V_2 -> V_23 , V_9 ) ;
if ( V_2 -> V_26 )
F_20 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_27 )
{
unsigned long V_9 ;
F_17 ( & V_2 -> V_23 , V_9 ) ;
if ( V_2 -> V_28 == 0 ) {
F_27 ( & V_2 -> V_24 , F_24 ,
( unsigned long ) V_2 ) ;
F_25 ( & V_2 -> V_24 , 1 + V_25 ) ;
}
V_2 -> V_28 |= V_27 ? V_29 :
V_30 ;
F_19 ( & V_2 -> V_23 , V_9 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_27 )
{
unsigned long V_9 ;
F_17 ( & V_2 -> V_23 , V_9 ) ;
if ( V_2 -> V_28 ) {
V_2 -> V_28 &= V_27 ? ~ V_29 :
~ V_30 ;
if ( ! V_2 -> V_28 )
F_29 ( & V_2 -> V_24 ) ;
}
F_19 ( & V_2 -> V_23 , V_9 ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned char V_31 ,
int V_32 )
{
unsigned long V_9 ;
int V_6 , V_33 ;
F_17 ( & V_2 -> V_16 , V_9 ) ;
if ( V_2 -> V_34 != V_35 ) {
V_2 -> V_36 ( V_2 , 0x00 , F_11 ( V_2 ) ) ;
}
if ( V_2 -> V_34 != V_37 ) {
for ( V_6 = 1000 ; V_6 > 0 &&
! F_31 ( V_2 ) ; V_6 -- )
F_32 ( 10 ) ;
#ifdef F_12
if ( ! V_6 )
F_13 ( V_8 L_2 ,
V_2 -> V_7 ( V_2 , F_14 ( V_2 ) ) ) ;
#endif
}
V_2 -> V_36 ( V_2 , V_31 , F_14 ( V_2 ) ) ;
if ( V_32 && ! ( V_2 -> V_14 & V_38 ) ) {
V_33 = 0 ;
V_6 = 10000 ;
while ( ! V_33 && V_6 -- > 0 ) {
if ( F_10 ( V_2 ) ) {
if ( V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) == V_39 )
V_33 = 1 ;
}
}
if ( ! V_33 && V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) == V_39 )
V_33 = 1 ;
} else
V_33 = 1 ;
F_19 ( & V_2 -> V_16 , V_9 ) ;
if ( ! V_33 ) {
F_13 ( V_8 L_3
L_4 , V_31 , V_2 -> V_40 ,
V_2 -> V_7 ( V_2 , F_14 ( V_2 ) ) ,
V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) ) ;
return 1 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
if ( F_30 ( V_2 , V_41 , 1 ) )
return - V_42 ;
if ( F_30 ( V_2 , V_43 , 0 ) )
return - V_42 ;
return 0 ;
}
static int F_34 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_46 ;
V_2 = V_45 -> V_26 -> V_47 ;
if ( V_2 -> V_48 && ( V_46 = V_2 -> V_48 ( V_2 ) ) < 0 )
return V_46 ;
if ( ! F_16 ( V_10 , & V_2 -> V_11 ) ) {
if ( F_33 ( V_2 ) < 0 )
goto V_49;
}
V_2 -> V_50 = V_45 ;
F_35 ( V_17 , & V_2 -> V_11 ) ;
return 0 ;
V_49:
if ( V_2 -> V_48 && V_2 -> V_51 )
V_2 -> V_51 ( V_2 ) ;
return - V_42 ;
}
static int F_36 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_46 ;
V_2 = V_45 -> V_26 -> V_47 ;
if ( V_2 -> V_52 && ( V_46 = V_2 -> V_52 ( V_2 ) ) < 0 )
return V_46 ;
if ( ! F_16 ( V_17 , & V_2 -> V_11 ) ) {
if ( F_33 ( V_2 ) < 0 )
goto V_49;
}
V_2 -> V_53 = V_45 ;
F_35 ( V_10 , & V_2 -> V_11 ) ;
return 0 ;
V_49:
if ( V_2 -> V_52 && V_2 -> V_54 )
V_2 -> V_54 ( V_2 ) ;
return - V_42 ;
}
static int F_37 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_46 = 0 ;
V_2 = V_45 -> V_26 -> V_47 ;
F_38 ( V_17 , & V_2 -> V_11 ) ;
V_2 -> V_50 = NULL ;
if ( ! F_16 ( V_10 , & V_2 -> V_11 ) )
V_46 = F_30 ( V_2 , V_41 , 0 ) ;
if ( V_2 -> V_51 )
V_2 -> V_51 ( V_2 ) ;
if ( V_46 )
return - V_42 ;
return 0 ;
}
static int F_39 ( struct V_44 * V_45 )
{
struct V_1 * V_2 ;
int V_46 = 0 ;
V_2 = V_45 -> V_26 -> V_47 ;
F_38 ( V_10 , & V_2 -> V_11 ) ;
V_2 -> V_53 = NULL ;
if ( ! F_16 ( V_17 , & V_2 -> V_11 ) )
V_46 = F_30 ( V_2 , V_41 , 0 ) ;
if ( V_2 -> V_54 )
V_2 -> V_54 ( V_2 ) ;
if ( V_46 )
return - V_42 ;
return 0 ;
}
static void
F_40 ( struct V_44 * V_45 , int V_55 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
int V_56 = 64 ;
V_2 = V_45 -> V_26 -> V_47 ;
if ( V_55 ) {
if ( ! F_41 ( V_57 ,
& V_2 -> V_11 ) ) {
while ( V_56 -- > 0 )
V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) ;
if ( V_2 -> V_14 & V_58 )
F_26 ( V_2 , 1 ) ;
}
F_17 ( & V_2 -> V_16 , V_9 ) ;
F_21 ( V_2 ) ;
F_19 ( & V_2 -> V_16 , V_9 ) ;
} else {
if ( V_2 -> V_14 & V_58 )
F_28 ( V_2 , 1 ) ;
F_38 ( V_57 , & V_2 -> V_11 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
int V_56 = 128 ;
unsigned char V_59 ;
while ( V_56 -- > 0 ) {
if ( ! F_10 ( V_2 ) )
break;
V_59 = V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) ;
if ( F_16 ( V_57 , & V_2 -> V_11 ) )
F_42 ( V_2 -> V_50 , & V_59 , 1 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned char V_59 ;
int V_56 = 256 ;
do {
if ( F_43 ( V_2 -> V_53 ,
& V_59 , 1 ) == 1 ) {
if ( ! F_31 ( V_2 ) &&
! F_31 ( V_2 ) )
break;
V_2 -> V_36 ( V_2 , V_59 , F_11 ( V_2 ) ) ;
F_44 ( V_2 -> V_53 , 1 ) ;
} else {
F_28 ( V_2 , 0 ) ;
break;
}
} while ( -- V_56 > 0 );
}
static void
F_45 ( struct V_44 * V_45 , int V_55 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = V_45 -> V_26 -> V_47 ;
if ( V_55 ) {
F_35 ( V_12 , & V_2 -> V_11 ) ;
if ( ! ( V_2 -> V_14 & V_18 ) )
F_26 ( V_2 , 0 ) ;
F_17 ( & V_2 -> V_13 , V_9 ) ;
F_18 ( V_2 ) ;
F_19 ( & V_2 -> V_13 , V_9 ) ;
} else {
if ( ! ( V_2 -> V_14 & V_18 ) )
F_28 ( V_2 , 0 ) ;
F_38 ( V_12 , & V_2 -> V_11 ) ;
}
}
static void F_46 ( struct V_60 * V_26 )
{
struct V_1 * V_2 = V_26 -> V_47 ;
if ( V_2 -> V_19 >= 0 )
F_47 ( V_2 -> V_19 , ( void * ) V_2 ) ;
F_48 ( V_2 -> V_61 ) ;
F_49 ( V_2 ) ;
}
int F_50 ( struct V_62 * V_63 , int V_64 ,
unsigned short V_34 ,
unsigned long V_40 ,
unsigned int V_14 ,
int V_19 ,
struct V_60 * * V_65 )
{
struct V_1 * V_2 ;
struct V_60 * V_26 ;
int V_66 , V_67 ;
int V_46 ;
if ( V_65 )
* V_65 = NULL ;
if ( ! ( V_14 & ( V_15 | V_68 ) ) )
V_14 |= V_15 | V_68 ;
V_66 = ( V_14 & V_15 ) ? 1 : 0 ;
V_67 = ( V_14 & V_68 ) ? 1 : 0 ;
if ( ( V_46 = F_51 ( V_63 , L_5 , V_64 ,
V_67 , V_66 , & V_26 ) ) < 0 )
return V_46 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_69 ) ;
if ( V_2 == NULL ) {
F_13 ( V_8 L_6 ) ;
F_53 ( V_63 , V_26 ) ;
return - V_70 ;
}
V_26 -> V_47 = V_2 ;
V_26 -> V_71 = F_46 ;
F_54 ( & V_2 -> V_16 ) ;
F_54 ( & V_2 -> V_13 ) ;
F_54 ( & V_2 -> V_23 ) ;
V_2 -> V_34 = V_34 ;
V_2 -> V_19 = - 1 ;
if ( ! ( V_14 & V_72 ) ) {
int V_73 = V_34 == V_74 ? 4 : 2 ;
V_2 -> V_61 = F_55 ( V_40 , V_73 , L_7 ) ;
if ( V_2 -> V_61 == NULL ) {
F_13 ( V_8 L_8
L_9 ,
V_40 , V_73 ) ;
F_53 ( V_63 , V_26 ) ;
return - V_75 ;
}
}
if ( V_14 & V_76 ) {
V_2 -> V_36 = F_5 ;
V_2 -> V_7 = F_7 ;
} else {
V_2 -> V_36 = F_1 ;
V_2 -> V_7 = F_3 ;
}
V_2 -> V_40 = V_40 ;
if ( V_34 == V_74 )
V_2 -> V_77 = V_40 + 2 ;
else
V_2 -> V_77 = V_40 + 1 ;
if ( V_19 >= 0 ) {
if ( F_56 ( V_19 , F_22 , 0 ,
L_7 , ( void * ) V_2 ) ) {
F_13 ( V_8 L_8
L_10 , V_19 ) ;
F_53 ( V_63 , V_26 ) ;
return - V_75 ;
}
}
if ( V_19 < 0 && ! ( V_14 & V_78 ) )
V_14 |= V_58 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_19 = V_19 ;
if ( V_63 -> V_79 [ 0 ] )
snprintf ( V_26 -> V_80 , sizeof( V_26 -> V_80 ) , L_11 ,
V_63 -> V_79 ) ;
else
sprintf ( V_26 -> V_80 , L_12 , V_63 -> V_81 , V_64 ) ;
if ( V_67 ) {
F_57 ( V_26 , V_82 ,
& V_83 ) ;
V_26 -> V_14 |= V_84 ;
}
if ( V_66 ) {
F_57 ( V_26 , V_85 ,
& V_86 ) ;
V_26 -> V_14 |= V_87 ;
if ( V_67 )
V_26 -> V_14 |= V_88 ;
}
V_2 -> V_26 = V_26 ;
if ( V_65 )
* V_65 = V_26 ;
return 0 ;
}
static int T_2 F_58 ( void )
{
return 0 ;
}
static void T_3 F_59 ( void )
{
}
