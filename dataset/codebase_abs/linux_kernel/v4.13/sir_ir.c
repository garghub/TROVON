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
static void F_15 ( unsigned long V_17 )
{
unsigned long V_8 ;
unsigned long V_18 ;
F_16 ( & V_19 , V_8 ) ;
if ( V_20 ) {
F_4 ( V_21 , V_2 + V_22 ) ;
V_18 = F_17 (unsigned long,
ktime_us_delta(last, last_intr_time),
IR_MAX_DURATION) ;
F_18 ( & V_23 -> V_5 , L_2 ,
V_20 , V_18 ) ;
F_10 ( V_20 , V_18 ) ;
V_20 = 0 ;
V_24 = V_25 ;
}
F_19 ( & V_19 , V_8 ) ;
F_20 ( V_16 ) ;
}
static T_1 F_21 ( int V_26 , void * V_27 )
{
unsigned char V_17 ;
T_2 V_28 ;
static unsigned long V_29 ;
unsigned long V_30 ;
unsigned long V_8 ;
int V_31 = 0 ;
int V_32 , V_33 ;
while ( ( V_32 = F_2 ( V_2 + V_34 ) & V_35 ) ) {
if ( ++ V_31 > 256 ) {
F_22 ( & V_23 -> V_5 , L_3 ) ;
break;
}
switch ( V_32 & V_35 ) {
case V_36 :
( void ) F_2 ( V_2 + V_37 ) ;
break;
case V_38 :
case V_39 :
( void ) F_2 ( V_2 + V_40 ) ;
break;
case V_41 :
F_16 ( & V_19 , V_8 ) ;
do {
F_23 ( & V_42 ) ;
V_17 = F_2 ( V_2 + V_43 ) ;
V_28 = F_24 () ;
V_29 = F_17 (unsigned long,
ktime_us_delta(last, curr_time),
IR_MAX_DURATION) ;
V_30 = F_17 (unsigned long,
ktime_us_delta(last_intr_time,
curr_time),
IR_MAX_DURATION) ;
F_18 ( & V_23 -> V_5 , L_4 ,
V_30 , ( int ) V_17 ) ;
if ( V_30 > V_13 * V_44 ) {
if ( V_20 ) {
F_18 ( & V_23 -> V_5 , L_5 ) ;
F_10 ( V_20 ,
V_29 -
V_30 ) ;
V_20 = 0 ;
V_24 = V_25 ;
V_29 = V_30 ;
}
}
V_17 = 1 ;
if ( V_17 ^ V_20 ) {
F_10 ( V_20 ,
V_29 - V_13 ) ;
V_20 = V_17 ;
V_24 = V_28 ;
V_24 = F_25 ( V_24 ,
V_13 ) ;
}
V_25 = V_28 ;
if ( V_17 ) {
V_42 . V_45 = V_46 +
V_47 ;
F_26 ( & V_42 ) ;
}
V_33 = F_2 ( V_2 + V_40 ) ;
} while ( V_33 & V_48 );
F_19 ( & V_19 , V_8 ) ;
break;
default:
break;
}
}
F_20 ( V_16 ) ;
return F_27 ( V_49 ) ;
}
static void F_8 ( unsigned long V_50 )
{
F_28 ( V_50 , V_50 + 25 ) ;
}
static void F_7 ( unsigned long V_50 )
{
long V_51 = V_50 / V_13 ;
if ( V_51 == 0 )
V_51 ++ ;
while ( V_51 -- ) {
F_4 ( V_52 , V_2 + V_53 ) ;
while ( ! ( F_2 ( V_2 + V_40 ) & V_54 ) )
;
}
}
static void F_29 ( void )
{
unsigned long V_8 ;
F_16 ( & V_55 , V_8 ) ;
F_4 ( 0 , V_2 + V_56 ) ;
F_4 ( 0 , V_2 + V_57 ) ;
F_4 ( V_58 | V_59 , V_2 + V_60 ) ;
F_4 ( 1 , V_2 + V_61 ) ; F_4 ( 0 , V_2 + V_62 ) ;
F_4 ( V_59 , V_2 + V_60 ) ;
F_4 ( V_63 , V_2 + V_22 ) ;
F_4 ( V_64 , V_2 + V_57 ) ;
F_4 ( V_65 | V_66 | V_67 , V_2 + V_56 ) ;
F_19 ( & V_55 , V_8 ) ;
}
static void F_30 ( void )
{
unsigned long V_8 ;
F_16 ( & V_55 , V_8 ) ;
F_4 ( 0 , V_2 + V_57 ) ;
F_19 ( & V_55 , V_8 ) ;
}
static int F_31 ( struct V_68 * V_5 )
{
int V_69 ;
V_16 = F_32 ( & V_23 -> V_5 , V_70 ) ;
if ( ! V_16 )
return - V_71 ;
V_16 -> V_72 = L_6 ;
V_16 -> V_73 = V_74 L_7 ;
V_16 -> V_75 . V_76 = V_77 ;
V_16 -> V_75 . V_78 = 0x0001 ;
V_16 -> V_75 . V_79 = 0x0001 ;
V_16 -> V_75 . V_80 = 0x0100 ;
V_16 -> V_81 = F_5 ;
V_16 -> V_82 = V_83 ;
V_16 -> V_84 = V_74 ;
V_16 -> V_85 = V_86 ;
V_16 -> V_87 = V_88 ;
V_16 -> V_5 . V_89 = & V_23 -> V_5 ;
F_33 ( & V_42 , F_15 , 0 ) ;
if ( ! F_34 ( & V_23 -> V_5 , V_2 , 8 , V_74 ) ) {
F_35 ( L_8 , V_2 ) ;
return - V_90 ;
}
V_69 = F_36 ( & V_23 -> V_5 , V_26 , F_21 , 0 ,
V_74 , NULL ) ;
if ( V_69 < 0 ) {
F_35 ( L_9 , V_26 ) ;
return V_69 ;
}
F_37 ( L_10 , V_2 , V_26 ) ;
V_69 = F_38 ( & V_23 -> V_5 , V_16 ) ;
if ( V_69 < 0 )
return V_69 ;
F_29 () ;
return 0 ;
}
static int F_39 ( struct V_68 * V_5 )
{
F_30 () ;
F_40 ( & V_42 ) ;
return 0 ;
}
static int T_3 F_41 ( void )
{
int V_69 ;
V_69 = F_42 ( & V_91 ) ;
if ( V_69 )
return V_69 ;
V_23 = F_43 ( L_11 , 0 ) ;
if ( ! V_23 ) {
V_69 = - V_71 ;
goto V_92;
}
V_69 = F_44 ( V_23 ) ;
if ( V_69 )
goto V_93;
return 0 ;
V_93:
F_45 ( V_23 ) ;
V_92:
F_46 ( & V_91 ) ;
return V_69 ;
}
static void T_4 F_47 ( void )
{
F_48 ( V_23 ) ;
F_46 ( & V_91 ) ;
}
