static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 , V_2 , V_1 ) ;
V_3 = F_3 ( V_1 , & V_1 ) ;
return 0 ;
}
static unsigned long T_1 T_2 F_4 ( void )
{
struct V_4 * V_5 ;
unsigned long V_6 = 0 ;
F_5 (memory, reg)
V_6 += F_6 ( V_5 ) -
F_7 ( V_5 ) ;
return ( V_6 * V_7 / 100 ) << V_8 ;
}
static inline T_2 unsigned long F_4 ( void )
{
return 0 ;
}
void T_1 F_8 ( T_3 V_9 )
{
unsigned long V_10 = 0 ;
F_2 ( L_2 , V_2 , ( unsigned long ) V_9 ) ;
if ( V_3 != - 1 ) {
V_10 = V_3 ;
} else {
#ifdef F_9
V_10 = V_11 ;
#elif F_10 ( V_12 )
V_10 = F_4 () ;
#elif F_10 ( V_13 )
V_10 = F_11 ( V_11 , F_4 () ) ;
#elif F_10 ( V_14 )
V_10 = F_12 ( V_11 , F_4 () ) ;
#endif
}
if ( V_10 ) {
F_2 ( L_3 , V_2 ,
V_10 / V_15 ) ;
F_13 ( NULL , V_10 , 0 , V_9 ) ;
}
}
static T_1 int F_14 ( unsigned long V_16 , unsigned long V_17 )
{
unsigned long V_18 = V_16 ;
unsigned V_19 = V_17 >> V_20 ;
struct V_21 * V_21 ;
F_15 ( ! F_16 ( V_18 ) ) ;
V_21 = F_17 ( F_18 ( V_18 ) ) ;
do {
unsigned V_22 ;
V_16 = V_18 ;
for ( V_22 = V_23 ; V_22 ; -- V_22 , V_18 ++ ) {
F_15 ( ! F_16 ( V_18 ) ) ;
if ( F_17 ( F_18 ( V_18 ) ) != V_21 )
return - V_24 ;
}
F_19 ( F_18 ( V_16 ) ) ;
} while ( -- V_19 );
return 0 ;
}
static int T_1 F_20 ( void )
{
struct V_25 * V_26 = V_25 ;
unsigned V_19 = V_27 ;
F_2 ( L_4 , V_2 ) ;
for (; V_19 ; -- V_19 , ++ V_26 ) {
struct V_28 * V_28 ;
V_28 = F_21 ( F_22 ( V_26 -> V_29 ) ,
V_26 -> V_30 >> V_8 ) ;
if ( ! F_23 ( V_28 ) )
F_24 ( V_26 -> V_31 , V_28 ) ;
}
return 0 ;
}
int T_1 F_13 ( struct V_32 * V_31 , unsigned long V_30 ,
T_3 V_33 , T_3 V_9 )
{
struct V_25 * V_26 = & V_25 [ V_27 ] ;
unsigned long V_34 ;
F_2 ( L_5 , V_2 ,
( unsigned long ) V_30 , ( unsigned long ) V_33 ,
( unsigned long ) V_9 ) ;
if ( V_27 == F_25 ( V_25 ) ) {
F_26 ( L_6 ) ;
return - V_35 ;
}
if ( ! V_30 )
return - V_24 ;
V_34 = V_36 << F_12 ( V_37 - 1 , V_20 ) ;
V_33 = F_27 ( V_33 , V_34 ) ;
V_30 = F_27 ( V_30 , V_34 ) ;
V_9 &= ~ ( V_34 - 1 ) ;
if ( V_33 ) {
if ( F_28 ( V_33 , V_30 ) ||
F_29 ( V_33 , V_30 ) < 0 ) {
V_33 = - V_38 ;
goto V_39;
}
} else {
T_3 V_40 = F_30 ( V_30 , V_34 , V_9 ) ;
if ( ! V_40 ) {
V_33 = - V_41 ;
goto V_39;
} else if ( V_40 + V_30 > ~ ( unsigned long ) 0 ) {
F_31 ( V_40 , V_30 ) ;
V_33 = - V_24 ;
goto V_39;
} else {
V_33 = V_40 ;
}
}
V_26 -> V_29 = V_33 ;
V_26 -> V_30 = V_30 ;
V_26 -> V_31 = V_31 ;
V_27 ++ ;
F_32 ( L_7 , V_30 / V_15 ,
( unsigned long ) V_33 ) ;
F_33 ( V_33 , V_30 ) ;
return 0 ;
V_39:
F_26 ( L_8 , V_30 / V_15 ) ;
return V_33 ;
}
struct V_42 * F_34 ( struct V_32 * V_31 , int V_17 ,
unsigned int V_43 )
{
unsigned long V_44 , V_18 , V_45 , V_29 = 0 ;
struct V_28 * V_28 = F_35 ( V_31 ) ;
int V_46 ;
if ( ! V_28 || ! V_28 -> V_17 )
return NULL ;
if ( V_43 > V_47 )
V_43 = V_47 ;
F_2 ( L_9 , V_2 , ( void * ) V_28 ,
V_17 , V_43 ) ;
if ( ! V_17 )
return NULL ;
V_44 = ( 1 << V_43 ) - 1 ;
F_36 ( & V_48 ) ;
for (; ; ) {
V_45 = F_37 ( V_28 -> V_49 , V_28 -> V_17 ,
V_29 , V_17 , V_44 ) ;
if ( V_45 >= V_28 -> V_17 ) {
V_46 = - V_41 ;
goto error;
}
V_18 = V_28 -> V_16 + V_45 ;
V_46 = F_38 ( V_18 , V_18 + V_17 , V_50 ) ;
if ( V_46 == 0 ) {
F_39 ( V_28 -> V_49 , V_45 , V_17 ) ;
break;
} else if ( V_46 != - V_38 ) {
goto error;
}
F_2 ( L_10 ,
V_2 , F_18 ( V_18 ) ) ;
V_29 = V_45 + V_44 + 1 ;
}
F_40 ( & V_48 ) ;
F_2 ( L_11 , V_2 , F_18 ( V_18 ) ) ;
return F_18 ( V_18 ) ;
error:
F_40 ( & V_48 ) ;
return NULL ;
}
bool F_41 ( struct V_32 * V_31 , struct V_42 * V_51 ,
int V_17 )
{
struct V_28 * V_28 = F_35 ( V_31 ) ;
unsigned long V_18 ;
if ( ! V_28 || ! V_51 )
return false ;
F_2 ( L_12 , V_2 , ( void * ) V_51 ) ;
V_18 = F_42 ( V_51 ) ;
if ( V_18 < V_28 -> V_16 || V_18 >= V_28 -> V_16 + V_28 -> V_17 )
return false ;
F_43 ( V_18 + V_17 > V_28 -> V_16 + V_28 -> V_17 ) ;
F_36 ( & V_48 ) ;
F_44 ( V_28 -> V_49 , V_18 - V_28 -> V_16 , V_17 ) ;
F_45 ( V_18 , V_17 ) ;
F_40 ( & V_48 ) ;
return true ;
}
