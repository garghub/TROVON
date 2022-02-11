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
V_2 -> V_24 . V_25 = 1 + V_26 ;
F_25 ( & V_2 -> V_24 ) ;
F_19 ( & V_2 -> V_23 , V_9 ) ;
if ( V_2 -> V_27 )
F_20 ( V_2 ) ;
}
static void F_26 ( struct V_1 * V_2 , int V_28 )
{
unsigned long V_9 ;
F_17 ( & V_2 -> V_23 , V_9 ) ;
if ( V_2 -> V_29 == 0 ) {
F_27 ( & V_2 -> V_24 ) ;
V_2 -> V_24 . V_3 = ( unsigned long ) V_2 ;
V_2 -> V_24 . V_30 = F_24 ;
V_2 -> V_24 . V_25 = 1 + V_26 ;
F_25 ( & V_2 -> V_24 ) ;
}
V_2 -> V_29 |= V_28 ? V_31 :
V_32 ;
F_19 ( & V_2 -> V_23 , V_9 ) ;
}
static void F_28 ( struct V_1 * V_2 , int V_28 )
{
unsigned long V_9 ;
F_17 ( & V_2 -> V_23 , V_9 ) ;
if ( V_2 -> V_29 ) {
V_2 -> V_29 &= V_28 ? ~ V_31 :
~ V_32 ;
if ( ! V_2 -> V_29 )
F_29 ( & V_2 -> V_24 ) ;
}
F_19 ( & V_2 -> V_23 , V_9 ) ;
}
static int F_30 ( struct V_1 * V_2 , unsigned char V_33 ,
int V_34 )
{
unsigned long V_9 ;
int V_6 , V_35 ;
F_17 ( & V_2 -> V_16 , V_9 ) ;
if ( V_2 -> V_36 != V_37 ) {
V_2 -> V_38 ( V_2 , 0x00 , F_11 ( V_2 ) ) ;
}
if ( V_2 -> V_36 != V_39 ) {
for ( V_6 = 1000 ; V_6 > 0 &&
! F_31 ( V_2 ) ; V_6 -- )
F_32 ( 10 ) ;
#ifdef F_12
if ( ! V_6 )
F_13 ( V_8 L_2 ,
V_2 -> V_7 ( V_2 , F_14 ( V_2 ) ) ) ;
#endif
}
V_2 -> V_38 ( V_2 , V_33 , F_14 ( V_2 ) ) ;
if ( V_34 && ! ( V_2 -> V_14 & V_40 ) ) {
V_35 = 0 ;
V_6 = 10000 ;
while ( ! V_35 && V_6 -- > 0 ) {
if ( F_10 ( V_2 ) ) {
if ( V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) == V_41 )
V_35 = 1 ;
}
}
if ( ! V_35 && V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) == V_41 )
V_35 = 1 ;
} else
V_35 = 1 ;
F_19 ( & V_2 -> V_16 , V_9 ) ;
if ( ! V_35 ) {
F_13 ( V_8 L_3
L_4 , V_33 , V_2 -> V_42 ,
V_2 -> V_7 ( V_2 , F_14 ( V_2 ) ) ,
V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) ) ;
return 1 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_2 )
{
if ( F_30 ( V_2 , V_43 , 1 ) )
return - V_44 ;
if ( F_30 ( V_2 , V_45 , 0 ) )
return - V_44 ;
return 0 ;
}
static int F_34 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
int V_48 ;
V_2 = V_47 -> V_27 -> V_49 ;
if ( V_2 -> V_50 && ( V_48 = V_2 -> V_50 ( V_2 ) ) < 0 )
return V_48 ;
if ( ! F_16 ( V_10 , & V_2 -> V_11 ) ) {
if ( F_33 ( V_2 ) < 0 )
goto V_51;
}
V_2 -> V_52 = V_47 ;
F_35 ( V_17 , & V_2 -> V_11 ) ;
return 0 ;
V_51:
if ( V_2 -> V_50 && V_2 -> V_53 )
V_2 -> V_53 ( V_2 ) ;
return - V_44 ;
}
static int F_36 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
int V_48 ;
V_2 = V_47 -> V_27 -> V_49 ;
if ( V_2 -> V_54 && ( V_48 = V_2 -> V_54 ( V_2 ) ) < 0 )
return V_48 ;
if ( ! F_16 ( V_17 , & V_2 -> V_11 ) ) {
if ( F_33 ( V_2 ) < 0 )
goto V_51;
}
V_2 -> V_55 = V_47 ;
F_35 ( V_10 , & V_2 -> V_11 ) ;
return 0 ;
V_51:
if ( V_2 -> V_54 && V_2 -> V_56 )
V_2 -> V_56 ( V_2 ) ;
return - V_44 ;
}
static int F_37 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
int V_48 = 0 ;
V_2 = V_47 -> V_27 -> V_49 ;
F_38 ( V_17 , & V_2 -> V_11 ) ;
V_2 -> V_52 = NULL ;
if ( ! F_16 ( V_10 , & V_2 -> V_11 ) )
V_48 = F_30 ( V_2 , V_43 , 0 ) ;
if ( V_2 -> V_53 )
V_2 -> V_53 ( V_2 ) ;
if ( V_48 )
return - V_44 ;
return 0 ;
}
static int F_39 ( struct V_46 * V_47 )
{
struct V_1 * V_2 ;
int V_48 = 0 ;
V_2 = V_47 -> V_27 -> V_49 ;
F_38 ( V_10 , & V_2 -> V_11 ) ;
V_2 -> V_55 = NULL ;
if ( ! F_16 ( V_17 , & V_2 -> V_11 ) )
V_48 = F_30 ( V_2 , V_43 , 0 ) ;
if ( V_2 -> V_56 )
V_2 -> V_56 ( V_2 ) ;
if ( V_48 )
return - V_44 ;
return 0 ;
}
static void
F_40 ( struct V_46 * V_47 , int V_57 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
int V_58 = 64 ;
V_2 = V_47 -> V_27 -> V_49 ;
if ( V_57 ) {
if ( ! F_41 ( V_59 ,
& V_2 -> V_11 ) ) {
while ( V_58 -- > 0 )
V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) ;
if ( V_2 -> V_14 & V_60 )
F_26 ( V_2 , 1 ) ;
}
F_17 ( & V_2 -> V_16 , V_9 ) ;
F_21 ( V_2 ) ;
F_19 ( & V_2 -> V_16 , V_9 ) ;
} else {
if ( V_2 -> V_14 & V_60 )
F_28 ( V_2 , 1 ) ;
F_38 ( V_59 , & V_2 -> V_11 ) ;
}
}
static void F_21 ( struct V_1 * V_2 )
{
int V_58 = 128 ;
unsigned char V_61 ;
while ( V_58 -- > 0 ) {
if ( ! F_10 ( V_2 ) )
break;
V_61 = V_2 -> V_7 ( V_2 , F_11 ( V_2 ) ) ;
if ( F_16 ( V_59 , & V_2 -> V_11 ) )
F_42 ( V_2 -> V_52 , & V_61 , 1 ) ;
}
}
static void F_18 ( struct V_1 * V_2 )
{
unsigned char V_61 ;
int V_58 = 256 ;
do {
if ( F_43 ( V_2 -> V_55 ,
& V_61 , 1 ) == 1 ) {
if ( ! F_31 ( V_2 ) &&
! F_31 ( V_2 ) )
break;
V_2 -> V_38 ( V_2 , V_61 , F_11 ( V_2 ) ) ;
F_44 ( V_2 -> V_55 , 1 ) ;
} else {
F_28 ( V_2 , 0 ) ;
break;
}
} while ( -- V_58 > 0 );
}
static void
F_45 ( struct V_46 * V_47 , int V_57 )
{
unsigned long V_9 ;
struct V_1 * V_2 ;
V_2 = V_47 -> V_27 -> V_49 ;
if ( V_57 ) {
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
static void F_46 ( struct V_62 * V_27 )
{
struct V_1 * V_2 = V_27 -> V_49 ;
if ( V_2 -> V_19 >= 0 )
F_47 ( V_2 -> V_19 , ( void * ) V_2 ) ;
F_48 ( V_2 -> V_63 ) ;
F_49 ( V_2 ) ;
}
int F_50 ( struct V_64 * V_65 , int V_66 ,
unsigned short V_36 ,
unsigned long V_42 ,
unsigned int V_14 ,
int V_19 ,
struct V_62 * * V_67 )
{
struct V_1 * V_2 ;
struct V_62 * V_27 ;
int V_68 , V_69 ;
int V_48 ;
if ( V_67 )
* V_67 = NULL ;
if ( ! ( V_14 & ( V_15 | V_70 ) ) )
V_14 |= V_15 | V_70 ;
V_68 = ( V_14 & V_15 ) ? 1 : 0 ;
V_69 = ( V_14 & V_70 ) ? 1 : 0 ;
if ( ( V_48 = F_51 ( V_65 , L_5 , V_66 ,
V_69 , V_68 , & V_27 ) ) < 0 )
return V_48 ;
V_2 = F_52 ( sizeof( * V_2 ) , V_71 ) ;
if ( V_2 == NULL ) {
F_13 ( V_8 L_6 ) ;
F_53 ( V_65 , V_27 ) ;
return - V_72 ;
}
V_27 -> V_49 = V_2 ;
V_27 -> V_73 = F_46 ;
F_54 ( & V_2 -> V_16 ) ;
F_54 ( & V_2 -> V_13 ) ;
F_54 ( & V_2 -> V_23 ) ;
V_2 -> V_36 = V_36 ;
V_2 -> V_19 = - 1 ;
if ( ! ( V_14 & V_74 ) ) {
int V_75 = V_36 == V_76 ? 4 : 2 ;
V_2 -> V_63 = F_55 ( V_42 , V_75 , L_7 ) ;
if ( V_2 -> V_63 == NULL ) {
F_13 ( V_8 L_8
L_9 ,
V_42 , V_75 ) ;
F_53 ( V_65 , V_27 ) ;
return - V_77 ;
}
}
if ( V_14 & V_78 ) {
V_2 -> V_38 = F_5 ;
V_2 -> V_7 = F_7 ;
} else {
V_2 -> V_38 = F_1 ;
V_2 -> V_7 = F_3 ;
}
V_2 -> V_42 = V_42 ;
if ( V_36 == V_76 )
V_2 -> V_79 = V_42 + 2 ;
else
V_2 -> V_79 = V_42 + 1 ;
if ( V_19 >= 0 ) {
if ( F_56 ( V_19 , F_22 , 0 ,
L_7 , ( void * ) V_2 ) ) {
F_13 ( V_8 L_8
L_10 , V_19 ) ;
F_53 ( V_65 , V_27 ) ;
return - V_77 ;
}
}
if ( V_19 < 0 && ! ( V_14 & V_80 ) )
V_14 |= V_60 ;
V_2 -> V_14 = V_14 ;
V_2 -> V_19 = V_19 ;
if ( V_65 -> V_81 [ 0 ] )
snprintf ( V_27 -> V_82 , sizeof( V_27 -> V_82 ) , L_11 ,
V_65 -> V_81 ) ;
else
sprintf ( V_27 -> V_82 , L_12 , V_65 -> V_83 , V_66 ) ;
if ( V_69 ) {
F_57 ( V_27 , V_84 ,
& V_85 ) ;
V_27 -> V_14 |= V_86 ;
}
if ( V_68 ) {
F_57 ( V_27 , V_87 ,
& V_88 ) ;
V_27 -> V_14 |= V_89 ;
if ( V_69 )
V_27 -> V_14 |= V_90 ;
}
V_2 -> V_27 = V_27 ;
if ( V_67 )
* V_67 = V_27 ;
return 0 ;
}
static int T_2 F_58 ( void )
{
return 0 ;
}
static void T_3 F_59 ( void )
{
}
