static inline void T_1 * F_1 ( struct V_1 * V_2 )
{
return V_3 + V_2 -> V_4 * V_5 ;
}
static inline void F_2 ( void )
{
struct V_6 * V_7 ;
int V_8 = 0 ;
if ( V_3 ) {
F_3 ( L_1 ) ;
return;
}
V_7 = F_4 ( V_9 ) ;
if ( V_7 == NULL ) {
F_5 ( V_10 L_2 ,
V_9 ) ;
return;
}
V_11 = ( V_12 ) V_7 -> V_13 ;
if ( ! V_11 ) {
F_5 ( V_14 L_3 ) ;
V_11 = V_15 ;
}
V_3 = F_6 ( V_11 , V_16 ) ;
if ( ! V_3 ) {
F_3 ( L_4 ,\
( unsigned long ) V_11 ) ;
goto V_17;
}
V_18 = V_7 -> V_19 ;
F_7 ( V_7 ) ;
V_7 = F_4 ( V_20 ) ;
if ( V_7 == NULL )
goto V_17;
F_3 ( L_5 ,
( int ) ( V_7 -> V_13 & 0xff ) / V_5 ) ;
V_8 = ( unsigned int ) ( V_7 -> V_13 & 0xff ) /
V_5 ;
V_21 = F_8 ( V_22 ,
L_6 , V_3 + V_8 *
V_5 , V_18 ) ;
return;
V_17:
F_9 ( L_7 ) ;
}
static inline void F_10 ( void )
{
F_11 ( V_3 ) ;
V_3 = NULL ;
}
static int T_2 F_12 ( void )
{
struct V_6 * V_7 ;
struct V_1 * V_2 = F_13 ( & V_23 ) ;
V_7 = F_4 ( V_9 ) ;
if ( V_7 == NULL ) {
F_5 ( V_10 L_2 ,
V_9 ) ;
return - V_24 ;
}
V_2 -> V_4 = F_14 () ;
V_2 -> V_25 = F_15 ( F_14 () , L_6 ,
V_26 == V_27 ?
V_28 - 100 : V_28 ,
F_1 ( V_2 ) , 0 , V_18 ) ;
V_2 -> V_25 -> V_29 = NULL ;
if ( V_26 == V_27 ) {
V_30 = & V_2 -> V_25 -> V_31 ;
F_5 ( V_32 L_8 ,
V_30 -> V_33 ) ;
}
F_16 ( V_2 -> V_25 ) ;
F_7 ( V_7 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_18 ( V_2 -> V_34 , 0 , V_35 ) ;
F_19 ( V_2 -> V_34 , F_20 ( V_2 -> V_36 ) ) ;
}
void F_21 ( void )
{
struct V_1 * V_2 ;
int V_36 ;
V_36 = F_14 () ;
if ( ! V_36 )
return;
V_2 = F_13 ( & V_23 ) ;
if ( ! V_2 -> V_25 ) {
V_2 -> V_25 = F_15 ( V_36 , V_2 -> V_33 ,
V_28 , F_1 ( V_2 ) ,
V_2 -> V_34 , V_18 ) ;
V_2 -> V_25 -> V_29 = NULL ;
} else {
F_22 ( V_2 -> V_25 ) ;
}
F_5 ( V_37 L_9 ,
V_36 , V_2 -> V_33 , V_2 -> V_36 ) ;
F_17 ( V_2 ) ;
F_16 ( V_2 -> V_25 ) ;
return;
}
static int F_23 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
unsigned long V_36 = ( unsigned long ) V_41 ;
struct V_1 * V_2 = & F_24 ( V_23 , V_36 ) ;
switch ( V_40 & ~ V_42 ) {
case V_43 :
F_25 ( V_2 -> V_25 ) ;
if ( V_44 == V_45 ) {
F_3 ( L_10 , V_36 ) ;
} else {
F_3 ( L_11 , V_36 ) ;
F_26 ( V_2 -> V_25 ) ;
}
break;
default:
F_3 ( L_12 , V_40 ) ;
}
return V_46 ;
}
static T_2 int F_27 ( void )
{
if ( V_26 == V_27 ||
! V_47 )
return 0 ;
F_28 ( F_23 , - 20 ) ;
return 0 ;
}
void F_21 ( void ) {}
static int F_29 ( void )
{
T_3 V_48 , V_49 ;
T_4 V_50 ;
F_30 ( V_21 ) ;
V_50 = F_31 ( V_21 ) ;
V_48 = F_32 () ;
do {
F_33 () ;
V_49 = F_32 () ;
} while ( ( V_49 - V_48 ) < 200000UL );
if ( V_50 == F_31 ( V_21 ) )
F_9 ( L_13 ) ;
F_34 ( V_21 ) ;
return 0 ;
}
void T_2 F_35 ( void )
{
#ifdef F_36
int V_51 ;
struct V_6 * V_52 ;
struct V_1 * V_2 ;
#endif
if ( V_47 )
return;
F_2 () ;
if ( ! V_3 )
goto V_53;
if ( V_18 < V_54 || V_18 > V_55 ) {
F_3 ( L_14 , V_18 ) ;
goto V_53;
}
if ( F_29 () ) {
F_3 ( L_15 ) ;
goto V_53;
}
if ( ! F_12 () )
V_47 = 1 ;
else {
F_3 ( L_16 ) ;
goto V_53;
}
#ifdef F_36
if ( V_26 == V_27 ) {
F_5 ( V_37 L_17 ) ;
return;
}
F_3 ( L_18 , V_56 , F_37 () ) ;
if ( F_38 () <= V_57 )
V_58 = F_38 () ;
else
V_58 = 1 ;
F_3 ( L_19 , V_56 , V_58 ) ;
for ( V_51 = 0 ; V_51 < V_58 ; V_51 ++ ) {
V_2 = & F_24 ( V_23 , V_51 ) ;
V_2 -> V_4 = V_51 ;
V_2 -> V_36 = V_51 ;
V_52 = F_4 ( V_51 ) ;
if ( V_52 )
V_2 -> V_34 = V_52 -> V_34 ;
else
F_5 ( V_10 L_20 , V_51 ) ;
snprintf ( V_2 -> V_33 , sizeof( V_2 -> V_33 ) - 1 , L_21 , V_51 ) ;
}
#endif
return;
V_53:
F_10 () ;
V_47 = 0 ;
F_9 ( L_22 ) ;
}
unsigned long F_39 ( void )
{
int V_51 , V_59 ;
T_3 V_60 , V_61 ;
T_4 V_50 , V_62 ;
unsigned long V_63 = 0 ;
T_5 V_64 , V_65 ;
F_2 () ;
F_30 ( V_21 ) ;
V_60 = F_31 ( V_21 ) ;
V_51 = 10000 ;
while ( -- V_51 ) {
if ( V_60 != F_31 ( V_21 ) )
break;
}
if ( ! V_51 )
goto V_66;
V_64 = ( V_18 / 1000 ) << 4 ;
F_30 ( V_21 ) ;
V_60 = F_31 ( V_21 ) ;
V_60 += V_64 ;
V_50 = F_32 () ;
do {
V_61 = F_31 ( V_21 ) ;
} while ( V_61 < V_60 );
V_62 = F_32 () ;
V_65 = 5 ;
if ( F_40 ( V_64 >> V_65 == 0 ) ) {
F_5 ( V_37
L_23 ) ;
return 0 ;
}
V_59 = ( int ) F_41 ( ( V_62 - V_50 ) , V_64 >> V_65 ) ;
V_63 = ( V_59 * ( V_18 / 1000 ) ) >> V_65 ;
F_5 ( V_37 L_24 , V_63 ) ;
return V_63 ;
V_66:
return 0 ;
}
