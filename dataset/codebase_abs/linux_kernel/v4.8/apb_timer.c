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
static int F_23 ( unsigned int V_36 )
{
struct V_1 * V_2 = & F_24 ( V_23 , V_36 ) ;
F_25 ( V_2 -> V_25 ) ;
if ( V_38 == V_39 ) {
F_3 ( L_10 , V_36 ) ;
} else {
F_3 ( L_11 , V_36 ) ;
F_26 ( V_2 -> V_25 ) ;
}
return 0 ;
}
static T_2 int F_27 ( void )
{
if ( V_26 == V_27 ||
! V_40 )
return 0 ;
return F_28 ( V_41 , L_12 , NULL ,
F_23 ) ;
}
void F_21 ( void ) {}
static int F_29 ( void )
{
T_3 V_42 , V_43 ;
T_4 V_44 ;
F_30 ( V_21 ) ;
V_44 = F_31 ( V_21 ) ;
V_42 = F_32 () ;
do {
F_33 () ;
V_43 = F_32 () ;
} while ( ( V_43 - V_42 ) < 200000UL );
if ( V_44 == F_31 ( V_21 ) )
F_9 ( L_13 ) ;
F_34 ( V_21 ) ;
return 0 ;
}
void T_2 F_35 ( void )
{
#ifdef F_36
int V_45 ;
struct V_6 * V_46 ;
struct V_1 * V_2 ;
#endif
if ( V_40 )
return;
F_2 () ;
if ( ! V_3 )
goto V_47;
if ( V_18 < V_48 || V_18 > V_49 ) {
F_3 ( L_14 , V_18 ) ;
goto V_47;
}
if ( F_29 () ) {
F_3 ( L_15 ) ;
goto V_47;
}
if ( ! F_12 () )
V_40 = 1 ;
else {
F_3 ( L_16 ) ;
goto V_47;
}
#ifdef F_36
if ( V_26 == V_27 ) {
F_5 ( V_37 L_17 ) ;
return;
}
F_3 ( L_18 , V_50 , F_37 () ) ;
if ( F_38 () <= V_51 )
V_52 = F_38 () ;
else
V_52 = 1 ;
F_3 ( L_19 , V_50 , V_52 ) ;
for ( V_45 = 0 ; V_45 < V_52 ; V_45 ++ ) {
V_2 = & F_24 ( V_23 , V_45 ) ;
V_2 -> V_4 = V_45 ;
V_2 -> V_36 = V_45 ;
V_46 = F_4 ( V_45 ) ;
if ( V_46 )
V_2 -> V_34 = V_46 -> V_34 ;
else
F_5 ( V_10 L_20 , V_45 ) ;
snprintf ( V_2 -> V_33 , sizeof( V_2 -> V_33 ) - 1 , L_21 , V_45 ) ;
}
#endif
return;
V_47:
F_10 () ;
V_40 = 0 ;
F_9 ( L_22 ) ;
}
unsigned long F_39 ( void )
{
int V_45 , V_53 ;
T_3 V_54 , V_55 ;
T_4 V_44 , V_56 ;
unsigned long V_57 = 0 ;
T_5 V_58 , V_59 ;
F_2 () ;
F_30 ( V_21 ) ;
V_54 = F_31 ( V_21 ) ;
V_45 = 10000 ;
while ( -- V_45 ) {
if ( V_54 != F_31 ( V_21 ) )
break;
}
if ( ! V_45 )
goto V_60;
V_58 = ( V_18 / 1000 ) << 4 ;
F_30 ( V_21 ) ;
V_54 = F_31 ( V_21 ) ;
V_54 += V_58 ;
V_44 = F_32 () ;
do {
V_55 = F_31 ( V_21 ) ;
} while ( V_55 < V_54 );
V_56 = F_32 () ;
V_59 = 5 ;
if ( F_40 ( V_58 >> V_59 == 0 ) ) {
F_5 ( V_37
L_23 ) ;
return 0 ;
}
V_53 = ( int ) F_41 ( ( V_56 - V_44 ) , V_58 >> V_59 ) ;
V_57 = ( V_53 * ( V_18 / 1000 ) ) >> V_59 ;
F_5 ( V_37 L_24 , V_57 ) ;
return V_57 ;
V_60:
return 0 ;
}
