static int T_1 F_1 ( char * V_1 )
{
F_2 ( L_1 , V_2 , V_1 ) ;
V_3 = F_3 ( V_1 , & V_1 ) ;
if ( * V_1 != '@' )
return 0 ;
V_4 = F_3 ( V_1 + 1 , & V_1 ) ;
if ( * V_1 != '-' ) {
V_5 = V_4 + V_3 ;
return 0 ;
}
V_5 = F_3 ( V_1 + 1 , & V_1 ) ;
return 0 ;
}
static T_2 T_1 T_3 F_4 ( void )
{
struct V_6 * V_7 ;
unsigned long V_8 = 0 ;
F_5 (memory, reg)
V_8 += F_6 ( V_7 ) -
F_7 ( V_7 ) ;
return ( V_8 * V_9 / 100 ) << V_10 ;
}
static inline T_3 T_2 F_4 ( void )
{
return 0 ;
}
void T_1 F_8 ( T_2 V_11 )
{
T_2 V_12 = 0 ;
T_2 V_13 = 0 ;
T_2 V_14 = V_11 ;
bool V_15 = false ;
F_2 ( L_2 , V_2 , ( unsigned long ) V_11 ) ;
if ( V_3 != - 1 ) {
V_12 = V_3 ;
V_13 = V_4 ;
V_14 = F_9 ( V_5 , V_11 ) ;
if ( V_4 + V_3 == V_5 )
V_15 = true ;
} else {
#ifdef F_10
V_12 = V_16 ;
#elif F_11 ( V_17 )
V_12 = F_4 () ;
#elif F_11 ( V_18 )
V_12 = F_12 ( V_16 , F_4 () ) ;
#elif F_11 ( V_19 )
V_12 = F_13 ( V_16 , F_4 () ) ;
#endif
}
if ( V_12 && ! V_20 ) {
F_2 ( L_3 , V_2 ,
( unsigned long ) V_12 / V_21 ) ;
F_14 ( V_12 , V_13 ,
V_14 ,
& V_20 ,
V_15 ) ;
}
}
static int T_1 F_15 ( struct V_22 * V_22 )
{
int V_23 = F_16 ( V_22 -> V_24 ) * sizeof( long ) ;
unsigned long V_25 = V_22 -> V_25 , V_26 = V_25 ;
unsigned V_27 = V_22 -> V_24 >> V_28 ;
struct V_29 * V_29 ;
V_22 -> V_30 = F_17 ( V_23 , V_31 ) ;
if ( ! V_22 -> V_30 )
return - V_32 ;
F_18 ( ! F_19 ( V_26 ) ) ;
V_29 = F_20 ( F_21 ( V_26 ) ) ;
do {
unsigned V_33 ;
V_25 = V_26 ;
for ( V_33 = V_34 ; V_33 ; -- V_33 , V_26 ++ ) {
F_18 ( ! F_19 ( V_26 ) ) ;
if ( F_20 ( F_21 ( V_26 ) ) != V_29 )
goto V_35;
}
F_22 ( F_21 ( V_25 ) ) ;
} while ( -- V_27 );
F_23 ( & V_22 -> V_36 ) ;
return 0 ;
V_35:
F_24 ( V_22 -> V_30 ) ;
return - V_37 ;
}
static int T_1 F_25 ( void )
{
int V_27 ;
for ( V_27 = 0 ; V_27 < V_38 ; V_27 ++ ) {
int V_39 = F_15 ( & V_40 [ V_27 ] ) ;
if ( V_39 )
return V_39 ;
}
return 0 ;
}
int T_1 F_14 ( T_2 V_41 , T_2 V_42 ,
T_2 V_11 , struct V_22 * * V_43 ,
bool V_15 )
{
struct V_22 * V_22 = & V_40 [ V_38 ] ;
T_2 V_44 ;
int V_39 = 0 ;
F_2 ( L_4 , V_2 ,
( unsigned long ) V_41 , ( unsigned long ) V_42 ,
( unsigned long ) V_11 ) ;
if ( V_38 == F_26 ( V_40 ) ) {
F_27 ( L_5 ) ;
return - V_45 ;
}
if ( ! V_41 )
return - V_37 ;
V_44 = V_46 << F_13 ( V_47 - 1 , V_28 ) ;
V_42 = F_28 ( V_42 , V_44 ) ;
V_41 = F_28 ( V_41 , V_44 ) ;
V_11 &= ~ ( V_44 - 1 ) ;
if ( V_42 && V_15 ) {
if ( F_29 ( V_42 , V_41 ) ||
F_30 ( V_42 , V_41 ) < 0 ) {
V_39 = - V_48 ;
goto V_35;
}
} else {
T_2 V_49 = F_31 ( V_41 , V_44 , V_42 ,
V_11 ) ;
if ( ! V_49 ) {
V_39 = - V_32 ;
goto V_35;
} else {
V_42 = V_49 ;
}
}
V_22 -> V_25 = F_32 ( V_42 ) ;
V_22 -> V_24 = V_41 >> V_10 ;
* V_43 = V_22 ;
V_38 ++ ;
F_33 ( L_6 , ( unsigned long ) V_41 / V_21 ,
( unsigned long ) V_42 ) ;
F_34 ( V_42 , V_41 ) ;
return 0 ;
V_35:
F_27 ( L_7 , ( unsigned long ) V_41 / V_21 ) ;
return V_39 ;
}
static void F_35 ( struct V_22 * V_22 , unsigned long V_26 , int V_24 )
{
F_36 ( & V_22 -> V_36 ) ;
F_37 ( V_22 -> V_30 , V_26 - V_22 -> V_25 , V_24 ) ;
F_38 ( & V_22 -> V_36 ) ;
}
struct V_50 * F_39 ( struct V_51 * V_52 , int V_24 ,
unsigned int V_53 )
{
unsigned long V_54 , V_26 , V_55 , V_56 = 0 ;
struct V_22 * V_22 = F_40 ( V_52 ) ;
struct V_50 * V_50 = NULL ;
int V_39 ;
if ( ! V_22 || ! V_22 -> V_24 )
return NULL ;
if ( V_53 > V_57 )
V_53 = V_57 ;
F_2 ( L_8 , V_2 , ( void * ) V_22 ,
V_24 , V_53 ) ;
if ( ! V_24 )
return NULL ;
V_54 = ( 1 << V_53 ) - 1 ;
for (; ; ) {
F_36 ( & V_22 -> V_36 ) ;
V_55 = F_41 ( V_22 -> V_30 , V_22 -> V_24 ,
V_56 , V_24 , V_54 ) ;
if ( V_55 >= V_22 -> V_24 ) {
F_38 ( & V_22 -> V_36 ) ;
break;
}
F_42 ( V_22 -> V_30 , V_55 , V_24 ) ;
F_38 ( & V_22 -> V_36 ) ;
V_26 = V_22 -> V_25 + V_55 ;
F_36 ( & V_58 ) ;
V_39 = F_43 ( V_26 , V_26 + V_24 , V_59 ) ;
F_38 ( & V_58 ) ;
if ( V_39 == 0 ) {
V_50 = F_21 ( V_26 ) ;
break;
} else if ( V_39 != - V_48 ) {
F_35 ( V_22 , V_26 , V_24 ) ;
break;
}
F_35 ( V_22 , V_26 , V_24 ) ;
F_2 ( L_9 ,
V_2 , F_21 ( V_26 ) ) ;
V_56 = V_55 + V_54 + 1 ;
}
F_2 ( L_10 , V_2 , V_50 ) ;
return V_50 ;
}
bool F_44 ( struct V_51 * V_52 , struct V_50 * V_60 ,
int V_24 )
{
struct V_22 * V_22 = F_40 ( V_52 ) ;
unsigned long V_26 ;
if ( ! V_22 || ! V_60 )
return false ;
F_2 ( L_11 , V_2 , ( void * ) V_60 ) ;
V_26 = F_45 ( V_60 ) ;
if ( V_26 < V_22 -> V_25 || V_26 >= V_22 -> V_25 + V_22 -> V_24 )
return false ;
F_46 ( V_26 + V_24 > V_22 -> V_25 + V_22 -> V_24 ) ;
F_47 ( V_26 , V_24 ) ;
F_35 ( V_22 , V_26 , V_24 ) ;
return true ;
}
