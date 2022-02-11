static inline unsigned int F_1 ( int V_1 )
{
return F_2 ( V_2 + V_1 ) ;
}
static inline void F_3 ( int V_1 , int V_3 )
{
F_4 ( V_3 , V_2 + V_1 ) ;
}
static int F_5 ( struct V_4 * V_5 , unsigned int * V_6 ,
unsigned int V_7 )
{
unsigned long V_8 ;
int V_9 ;
F_6 ( V_8 ) ;
for ( V_9 = 0 ; V_9 < V_7 ; ) {
if ( V_6 [ V_9 ] )
F_7 ( V_6 [ V_9 ] ) ;
V_9 ++ ;
if ( V_9 >= V_7 )
break;
if ( V_6 [ V_9 ] )
F_8 ( V_6 [ V_9 ] ) ;
V_9 ++ ;
}
F_9 ( V_8 ) ;
return V_7 ;
}
static void F_10 ( int V_10 , unsigned long V_11 )
{
F_11 ( V_12 ) ;
F_12 ( L_1 , V_10 , V_11 ) ;
if ( V_10 ) {
if ( V_11 > V_13 / 2 )
V_11 -= V_13 / 2 ;
else
V_11 = 1 ;
V_12 . V_14 = true ;
} else {
V_11 += V_13 / 2 ;
}
V_12 . V_15 = F_13 ( V_11 ) ;
F_14 ( V_16 , & V_12 ) ;
}
static int F_15 ( void )
{
V_16 = F_16 ( & V_17 -> V_5 , V_18 ) ;
if ( ! V_16 )
return - V_19 ;
V_16 -> V_20 = L_2 ;
V_16 -> V_21 = V_22 L_3 ;
V_16 -> V_23 . V_24 = V_25 ;
V_16 -> V_23 . V_26 = 0x0001 ;
V_16 -> V_23 . V_27 = 0x0001 ;
V_16 -> V_23 . V_28 = 0x0100 ;
V_16 -> V_29 = F_5 ;
V_16 -> V_30 = V_31 ;
V_16 -> V_32 = V_22 ;
V_16 -> V_33 = V_34 ;
V_16 -> V_35 = V_36 ;
V_16 -> V_5 . V_37 = & V_17 -> V_5 ;
return F_17 ( & V_17 -> V_5 , V_16 ) ;
}
static void F_18 ( unsigned long V_38 )
{
unsigned long V_8 ;
unsigned long V_39 ;
F_19 ( & V_40 , V_8 ) ;
if ( V_41 ) {
F_4 ( V_42 , V_2 + V_43 ) ;
V_39 = F_20 (unsigned long,
ktime_us_delta(last, last_intr_time),
IR_MAX_DURATION) ;
F_21 ( & V_17 -> V_5 , L_4 ,
V_41 , V_39 ) ;
F_10 ( V_41 , V_39 ) ;
V_41 = 0 ;
V_44 = V_45 ;
}
F_22 ( & V_40 , V_8 ) ;
F_23 ( V_16 ) ;
}
static T_1 F_24 ( int V_46 , void * V_47 )
{
unsigned char V_38 ;
T_2 V_48 ;
static unsigned long V_49 ;
unsigned long V_50 ;
unsigned long V_8 ;
int V_51 = 0 ;
int V_52 , V_53 ;
while ( ( V_52 = F_2 ( V_2 + V_54 ) & V_55 ) ) {
if ( ++ V_51 > 256 ) {
F_25 ( & V_17 -> V_5 , L_5 ) ;
break;
}
switch ( V_52 & V_55 ) {
case V_56 :
( void ) F_2 ( V_2 + V_57 ) ;
break;
case V_58 :
case V_59 :
( void ) F_2 ( V_2 + V_60 ) ;
break;
case V_61 :
F_19 ( & V_40 , V_8 ) ;
do {
F_26 ( & V_62 ) ;
V_38 = F_2 ( V_2 + V_63 ) ;
V_48 = F_27 () ;
V_49 = F_20 (unsigned long,
ktime_us_delta(last, curr_time),
IR_MAX_DURATION) ;
V_50 = F_20 (unsigned long,
ktime_us_delta(last_intr_time,
curr_time),
IR_MAX_DURATION) ;
F_21 ( & V_17 -> V_5 , L_6 ,
V_50 , ( int ) V_38 ) ;
if ( V_50 > V_13 * V_64 ) {
if ( V_41 ) {
F_21 ( & V_17 -> V_5 , L_7 ) ;
F_10 ( V_41 ,
V_49 -
V_50 ) ;
V_41 = 0 ;
V_44 = V_45 ;
V_49 = V_50 ;
}
}
V_38 = 1 ;
if ( V_38 ^ V_41 ) {
F_10 ( V_41 ,
V_49 - V_13 ) ;
V_41 = V_38 ;
V_44 = V_48 ;
V_44 = F_28 ( V_44 ,
V_13 ) ;
}
V_45 = V_48 ;
if ( V_38 ) {
V_62 . V_65 = V_66 +
V_67 ;
F_29 ( & V_62 ) ;
}
V_53 = F_2 ( V_2 + V_60 ) ;
} while ( V_53 & V_68 );
F_22 ( & V_40 , V_8 ) ;
break;
default:
break;
}
}
F_23 ( V_16 ) ;
return F_30 ( V_69 ) ;
}
static void F_8 ( unsigned long V_70 )
{
F_31 ( V_70 , V_70 + 25 ) ;
}
static void F_7 ( unsigned long V_70 )
{
long V_71 = V_70 / V_13 ;
if ( V_71 == 0 )
V_71 ++ ;
while ( V_71 -- ) {
F_4 ( V_72 , V_2 + V_73 ) ;
while ( ! ( F_2 ( V_2 + V_60 ) & V_74 ) )
;
}
}
static int F_32 ( void )
{
unsigned long V_8 ;
F_19 ( & V_75 , V_8 ) ;
F_4 ( 0 , V_2 + V_76 ) ;
F_4 ( 0 , V_2 + V_77 ) ;
F_4 ( V_78 | V_79 , V_2 + V_80 ) ;
F_4 ( 1 , V_2 + V_81 ) ; F_4 ( 0 , V_2 + V_82 ) ;
F_4 ( V_79 , V_2 + V_80 ) ;
F_4 ( V_83 , V_2 + V_43 ) ;
F_4 ( V_84 , V_2 + V_77 ) ;
F_4 ( V_85 | V_86 | V_87 , V_2 + V_76 ) ;
F_22 ( & V_75 , V_8 ) ;
return 0 ;
}
static void F_33 ( void )
{
unsigned long V_8 ;
F_19 ( & V_75 , V_8 ) ;
F_4 ( 0 , V_2 + V_77 ) ;
F_22 ( & V_75 , V_8 ) ;
}
static int F_34 ( void )
{
int V_88 ;
F_35 ( & V_62 , F_18 , 0 ) ;
if ( ! F_36 ( V_2 , 8 , V_22 ) ) {
F_37 ( L_8 , V_2 ) ;
return - V_89 ;
}
V_88 = F_38 ( V_46 , F_24 , 0 ,
V_22 , NULL ) ;
if ( V_88 < 0 ) {
F_39 ( V_2 , 8 ) ;
F_37 ( L_9 , V_46 ) ;
return V_88 ;
}
F_40 ( L_10 , V_2 , V_46 ) ;
return 0 ;
}
static void F_41 ( void )
{
F_42 ( V_46 , NULL ) ;
F_43 ( & V_62 ) ;
F_39 ( V_2 , 8 ) ;
}
static int F_44 ( void )
{
int V_88 ;
V_88 = F_34 () ;
if ( V_88 < 0 )
return V_88 ;
F_32 () ;
return 0 ;
}
static int F_45 ( struct V_90 * V_5 )
{
int V_88 ;
V_88 = F_15 () ;
if ( V_88 < 0 )
return V_88 ;
return F_44 () ;
}
static int F_46 ( struct V_90 * V_5 )
{
return 0 ;
}
static int T_3 F_47 ( void )
{
int V_88 ;
V_88 = F_48 ( & V_91 ) ;
if ( V_88 )
return V_88 ;
V_17 = F_49 ( L_11 , 0 ) ;
if ( ! V_17 ) {
V_88 = - V_19 ;
goto V_92;
}
V_88 = F_50 ( V_17 ) ;
if ( V_88 )
goto V_93;
return 0 ;
V_93:
F_51 ( V_17 ) ;
V_92:
F_52 ( & V_91 ) ;
return V_88 ;
}
static void T_4 F_53 ( void )
{
F_33 () ;
F_41 () ;
F_54 ( V_17 ) ;
F_52 ( & V_91 ) ;
}
