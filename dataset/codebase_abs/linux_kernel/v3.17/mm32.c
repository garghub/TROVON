static int F_1 ( int V_1 )
{
struct V_2 * V_2 ;
unsigned long V_3 ;
T_1 * V_4 ;
T_2 * V_5 ;
if ( F_2 ( V_6 , V_1 ) != NULL )
return 0 ;
V_2 = F_3 ( V_7 ) ;
if ( V_2 == NULL ) {
F_4 ( L_1 , V_1 ) ;
return - V_8 ;
}
V_3 = ( unsigned long ) F_5 ( F_6 ( V_2 ) ) ;
V_4 = F_7 ( F_8 ( F_9 ( V_3 ) , V_3 ) , V_3 ) ;
V_5 = F_10 ( V_4 , V_3 ) ;
F_2 ( V_9 , V_1 ) = V_3 ;
F_2 ( V_6 , V_1 ) = V_5 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_11 ,
unsigned long V_12 , void * V_13 )
{
int V_1 = ( long ) V_13 ;
switch ( V_12 ) {
case V_14 :
if ( F_1 ( V_1 ) )
return V_15 ;
break;
default:
break;
}
return V_16 ;
}
static void * F_12 ( T_3 V_17 )
{
unsigned long V_3 = F_13 ( V_9 ) ;
T_2 * V_5 = F_14 ( V_6 ) ;
* V_5 = F_15 ( V_17 >> V_18 , V_19 ) ;
F_16 ( V_3 ) ;
return ( void * ) V_3 ;
}
static void F_17 ( void * V_20 )
{
F_18 ( V_9 ) ;
}
static void F_19 ( T_3 V_17 , unsigned long V_21 ,
T_4 V_22 , enum V_23 V_24 ,
void (* F_20)( const void * , T_4 , int ) )
{
unsigned long V_25 ;
T_4 V_26 = V_22 ;
V_25 = ( V_17 >> V_18 ) + V_21 / V_27 ;
V_21 %= V_27 ;
do {
T_4 V_28 = V_26 ;
void * V_20 ;
if ( ! F_21 ( V_25 ) )
{
if ( ! F_22 ( V_29 ) )
return;
V_20 = F_12 ( V_17 ) + V_21 ;
F_20 ( V_20 , V_28 , V_24 ) ;
F_17 ( V_20 - V_21 ) ;
} else {
struct V_2 * V_2 = F_23 ( V_25 ) ;
if ( F_24 ( V_2 ) ) {
if ( V_28 + V_21 > V_27 )
V_28 = V_27 - V_21 ;
if ( F_25 () ) {
V_20 = F_26 ( V_2 ) ;
F_20 ( V_20 + V_21 , V_28 , V_24 ) ;
F_27 ( V_20 ) ;
} else {
V_20 = F_28 ( V_2 ) ;
if ( V_20 ) {
F_20 ( V_20 + V_21 , V_28 , V_24 ) ;
F_29 ( V_2 ) ;
}
}
} else {
V_20 = F_30 ( V_2 ) + V_21 ;
F_20 ( V_20 , V_28 , V_24 ) ;
}
}
V_21 = 0 ;
V_25 ++ ;
V_26 -= V_28 ;
} while ( V_26 );
}
static void F_31 ( struct V_30 * V_31 , T_3 V_17 ,
T_4 V_22 , enum V_23 V_24 )
{
if ( V_24 != V_32 )
F_32 ( V_17 , V_17 + V_22 ) ;
F_19 ( V_17 & V_33 , V_17 & ~ V_33 , V_22 , V_24 , V_34 ) ;
}
static void F_33 ( struct V_30 * V_31 , T_3 V_17 ,
T_4 V_22 , enum V_23 V_24 )
{
F_19 ( V_17 & V_33 , V_17 & ~ V_33 , V_22 , V_24 , V_35 ) ;
if ( V_24 == V_36 ) {
F_32 ( V_17 , V_17 + V_22 ) ;
} else {
F_34 ( V_17 , V_17 + V_22 ) ;
}
}
void F_35 ( struct V_30 * V_31 , T_3 V_17 ,
T_4 V_22 , enum V_23 V_24 ,
struct V_37 * V_38 )
{
if ( ! F_36 ( V_31 ) -> V_39 )
return;
if ( F_37 ( V_40 , V_38 ) )
return;
F_31 ( V_31 , V_17 , V_22 , V_24 ) ;
}
void F_38 ( struct V_30 * V_31 ,
T_3 V_17 , T_4 V_22 , enum V_23 V_24 )
{
if ( ! F_36 ( V_31 ) -> V_41 )
return;
F_31 ( V_31 , V_17 , V_22 , V_24 ) ;
}
void F_39 ( struct V_30 * V_31 ,
T_3 V_17 , T_4 V_22 , enum V_23 V_24 )
{
if ( ! F_36 ( V_31 ) -> V_42 )
return;
F_33 ( V_31 , V_17 , V_22 , V_24 ) ;
}
int T_5 F_40 ( void )
{
int V_1 ;
if ( ! F_41 () )
return 0 ;
F_42 ( & V_43 ) ;
F_43 () ;
F_44 (cpu) {
if ( F_1 ( V_1 ) ) {
F_45 () ;
F_46 ( & V_43 ) ;
return - V_8 ;
}
}
F_45 () ;
return 0 ;
}
