static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 , V_2 , V_1 ) ;
V_3 = F_3 ( V_1 , & V_1 ) ;
return 0 ;
}
static T_2 T_1 T_3 F_4 ( void )
{
struct V_4 * V_5 ;
unsigned long V_6 = 0 ;
F_5 (memory, reg)
V_6 += F_6 ( V_5 ) -
F_7 ( V_5 ) ;
return ( V_6 * V_7 / 100 ) << V_8 ;
}
static inline T_3 T_2 F_4 ( void )
{
return 0 ;
}
void T_1 F_8 ( T_2 V_9 )
{
T_2 V_10 = 0 ;
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
if ( V_10 && ! V_15 ) {
F_2 ( L_3 , V_2 ,
( unsigned long ) V_10 / V_16 ) ;
F_13 ( V_10 , 0 , V_9 ,
& V_15 ) ;
}
}
static int T_1 F_14 ( struct V_17 * V_17 )
{
int V_18 = F_15 ( V_17 -> V_19 ) * sizeof( long ) ;
unsigned long V_20 = V_17 -> V_20 , V_21 = V_20 ;
unsigned V_22 = V_17 -> V_19 >> V_23 ;
struct V_24 * V_24 ;
V_17 -> V_25 = F_16 ( V_18 , V_26 ) ;
if ( ! V_17 -> V_25 )
return - V_27 ;
F_17 ( ! F_18 ( V_21 ) ) ;
V_24 = F_19 ( F_20 ( V_21 ) ) ;
do {
unsigned V_28 ;
V_20 = V_21 ;
for ( V_28 = V_29 ; V_28 ; -- V_28 , V_21 ++ ) {
F_17 ( ! F_18 ( V_21 ) ) ;
if ( F_19 ( F_20 ( V_21 ) ) != V_24 )
return - V_30 ;
}
F_21 ( F_20 ( V_20 ) ) ;
} while ( -- V_22 );
return 0 ;
}
static int T_1 F_22 ( void )
{
int V_22 ;
for ( V_22 = 0 ; V_22 < V_31 ; V_22 ++ ) {
int V_32 = F_14 ( & V_33 [ V_22 ] ) ;
if ( V_32 )
return V_32 ;
}
return 0 ;
}
int T_1 F_13 ( T_2 V_34 , T_2 V_35 ,
T_2 V_9 , struct V_17 * * V_36 )
{
struct V_17 * V_17 = & V_33 [ V_31 ] ;
T_2 V_37 ;
int V_32 = 0 ;
F_2 ( L_4 , V_2 ,
( unsigned long ) V_34 , ( unsigned long ) V_35 ,
( unsigned long ) V_9 ) ;
if ( V_31 == F_23 ( V_33 ) ) {
F_24 ( L_5 ) ;
return - V_38 ;
}
if ( ! V_34 )
return - V_30 ;
V_37 = V_39 << F_12 ( V_40 - 1 , V_23 ) ;
V_35 = F_25 ( V_35 , V_37 ) ;
V_34 = F_25 ( V_34 , V_37 ) ;
V_9 &= ~ ( V_37 - 1 ) ;
if ( V_35 ) {
if ( F_26 ( V_35 , V_34 ) ||
F_27 ( V_35 , V_34 ) < 0 ) {
V_32 = - V_41 ;
goto V_42;
}
} else {
T_2 V_43 = F_28 ( V_34 , V_37 , V_9 ) ;
if ( ! V_43 ) {
V_32 = - V_27 ;
goto V_42;
} else {
V_35 = V_43 ;
}
}
V_17 -> V_20 = F_29 ( V_35 ) ;
V_17 -> V_19 = V_34 >> V_8 ;
* V_36 = V_17 ;
V_31 ++ ;
F_30 ( L_6 , ( unsigned long ) V_34 / V_16 ,
( unsigned long ) V_35 ) ;
F_31 ( V_35 , V_34 ) ;
return 0 ;
V_42:
F_24 ( L_7 , ( unsigned long ) V_34 / V_16 ) ;
return V_32 ;
}
struct V_44 * F_32 ( struct V_45 * V_46 , int V_19 ,
unsigned int V_47 )
{
unsigned long V_48 , V_21 , V_49 , V_50 = 0 ;
struct V_17 * V_17 = F_33 ( V_46 ) ;
struct V_44 * V_44 = NULL ;
int V_32 ;
if ( ! V_17 || ! V_17 -> V_19 )
return NULL ;
if ( V_47 > V_51 )
V_47 = V_51 ;
F_2 ( L_8 , V_2 , ( void * ) V_17 ,
V_19 , V_47 ) ;
if ( ! V_19 )
return NULL ;
V_48 = ( 1 << V_47 ) - 1 ;
F_34 ( & V_52 ) ;
for (; ; ) {
V_49 = F_35 ( V_17 -> V_25 , V_17 -> V_19 ,
V_50 , V_19 , V_48 ) ;
if ( V_49 >= V_17 -> V_19 )
break;
V_21 = V_17 -> V_20 + V_49 ;
V_32 = F_36 ( V_21 , V_21 + V_19 , V_53 ) ;
if ( V_32 == 0 ) {
F_37 ( V_17 -> V_25 , V_49 , V_19 ) ;
V_44 = F_20 ( V_21 ) ;
break;
} else if ( V_32 != - V_41 ) {
break;
}
F_2 ( L_9 ,
V_2 , F_20 ( V_21 ) ) ;
V_50 = V_49 + V_48 + 1 ;
}
F_38 ( & V_52 ) ;
F_2 ( L_10 , V_2 , V_44 ) ;
return V_44 ;
}
bool F_39 ( struct V_45 * V_46 , struct V_44 * V_54 ,
int V_19 )
{
struct V_17 * V_17 = F_33 ( V_46 ) ;
unsigned long V_21 ;
if ( ! V_17 || ! V_54 )
return false ;
F_2 ( L_11 , V_2 , ( void * ) V_54 ) ;
V_21 = F_40 ( V_54 ) ;
if ( V_21 < V_17 -> V_20 || V_21 >= V_17 -> V_20 + V_17 -> V_19 )
return false ;
F_41 ( V_21 + V_19 > V_17 -> V_20 + V_17 -> V_19 ) ;
F_34 ( & V_52 ) ;
F_42 ( V_17 -> V_25 , V_21 - V_17 -> V_20 , V_19 ) ;
F_43 ( V_21 , V_19 ) ;
F_38 ( & V_52 ) ;
return true ;
}
