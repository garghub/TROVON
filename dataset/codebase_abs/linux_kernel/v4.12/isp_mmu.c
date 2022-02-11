static unsigned int F_1 ( T_1 V_1 , unsigned int V_2 )
{
unsigned int * V_3 = F_2 ( V_1 ) ;
return * ( V_3 + V_2 ) ;
}
static void F_3 ( T_1 V_1 ,
unsigned int V_2 , unsigned int V_4 )
{
unsigned int * V_3 = F_2 ( V_1 ) ;
* ( V_3 + V_2 ) = V_4 ;
}
static void * F_4 ( T_1 V_5 )
{
return F_2 ( V_5 ) ;
}
static T_1 F_5 ( struct V_6 * V_7 ,
unsigned int V_4 )
{
return V_7 -> V_8 -> V_9 ( V_7 , V_4 ) ;
}
static unsigned int F_6 ( struct V_6 * V_7 ,
T_1 V_5 )
{
unsigned int V_4 = V_7 -> V_8 -> V_10 ( V_7 , V_5 ) ;
return ( unsigned int ) ( V_4 | F_7 ( V_7 ) ) ;
}
static T_1 F_8 ( struct V_6 * V_7 )
{
int V_11 ;
T_1 V_12 ;
void * V_13 ;
if ( V_14 > ( unsigned long ) V_15 )
V_13 = ( void * ) F_9 ( V_16 | V_17 ) ;
else
V_13 = F_10 ( V_7 -> V_18 , V_16 ) ;
if ( ! V_13 )
return ( T_1 ) V_19 ;
#ifdef F_11
F_12 ( ( unsigned long ) V_13 , 1 ) ;
#endif
V_12 = F_13 ( V_13 ) ;
for ( V_11 = 0 ; V_11 < 1024 ; V_11 ++ ) {
F_3 ( V_12 , V_11 , V_7 -> V_8 -> V_20 ) ;
}
return V_12 ;
}
static void F_14 ( struct V_6 * V_7 , T_1 V_12 )
{
void * V_13 ;
V_12 &= V_21 ;
V_13 = F_2 ( V_12 ) ;
#ifdef F_11
F_15 ( ( unsigned long ) V_13 , 1 ) ;
#endif
F_16 ( V_7 -> V_18 , V_13 ) ;
}
static void F_17 ( struct V_6 * V_7 ,
T_1 V_22 , unsigned int V_23 ,
T_1 V_24 , unsigned int V_25 ,
unsigned int V_26 , T_1 V_27 ,
T_1 V_28 )
{
F_18 ( V_29 , L_1
L_2
L_3
L_4
L_3
L_5
L_6 ,
F_4 ( V_22 ) ,
( V_30 ) V_22 , V_23 ,
F_4 ( V_24 ) ,
( V_30 ) V_24 , V_25 , V_26 ,
( V_30 ) V_27 , V_26 ,
( V_30 ) V_28 ) ;
}
static void F_19 ( struct V_6 * V_7 ,
T_1 V_22 , unsigned int V_23 ,
T_1 V_24 , unsigned int V_25 ,
unsigned int V_26 , unsigned int V_4 )
{
F_18 ( V_29 , L_7
L_2
L_3
L_4
L_3
L_8 ,
F_4 ( V_22 ) ,
( V_30 ) V_22 , V_23 ,
F_4 ( V_24 ) ,
( V_30 ) V_24 , V_25 , V_26 ,
V_4 ) ;
}
static void F_20 ( struct V_6 * V_7 ,
T_1 V_22 , unsigned int V_23 ,
unsigned int V_26 , unsigned int V_4 )
{
F_18 ( V_29 , L_9
L_2
L_3
L_10 ,
F_4 ( V_22 ) ,
( V_30 ) V_22 , V_23 , ( unsigned int ) V_26 ,
V_4 ) ;
}
static void F_21 ( struct V_6 * V_7 , unsigned int V_4 )
{
F_18 ( V_29 , L_11
L_12 , ( unsigned int ) V_4 ) ;
}
static int F_22 ( struct V_6 * V_7 , T_1 V_22 ,
unsigned int V_23 , T_1 V_24 ,
unsigned int V_31 , unsigned int V_32 , T_1 V_5 )
{
unsigned int V_33 ;
unsigned int V_2 ;
unsigned int V_4 ;
V_24 &= V_21 ;
V_31 = V_31 & V_21 ;
V_32 = F_23 ( V_32 ) ;
V_5 &= V_21 ;
V_33 = V_31 ;
do {
V_2 = F_24 ( V_33 ) ;
V_4 = F_1 ( V_24 , V_2 ) ;
if ( F_25 ( V_7 , V_4 ) ) {
F_17 ( V_7 , V_22 , V_23 ,
V_24 , V_2 , V_33 , V_4 , V_5 ) ;
F_26 ( V_7 , V_31 , V_33 ) ;
return - V_34 ;
}
V_4 = F_6 ( V_7 , V_5 ) ;
F_3 ( V_24 , V_2 , V_4 ) ;
V_7 -> V_35 [ V_23 ] ++ ;
V_33 += ( 1U << V_36 ) ;
V_5 += ( 1U << V_36 ) ;
} while ( V_33 < V_32 && V_2 < V_37 - 1 );
return 0 ;
}
static int F_27 ( struct V_6 * V_7 , T_1 V_22 ,
unsigned int V_31 , unsigned int V_32 ,
T_1 V_5 )
{
T_1 V_24 ;
unsigned int V_33 , V_38 ;
unsigned int V_2 ;
unsigned int V_39 ;
int V_40 ;
V_22 &= V_21 ;
V_31 = V_31 & V_21 ;
V_32 = F_23 ( V_32 ) ;
V_5 &= V_21 ;
V_33 = V_31 ;
do {
V_2 = F_28 ( V_33 ) ;
V_39 = F_1 ( V_22 , V_2 ) ;
if ( ! F_25 ( V_7 , V_39 ) ) {
V_24 = F_8 ( V_7 ) ;
if ( V_24 == V_19 ) {
F_18 ( V_29 ,
L_13 ) ;
F_26 ( V_7 , V_31 , V_33 ) ;
return - V_41 ;
}
V_39 = F_6 ( V_7 , V_24 ) ;
F_3 ( V_22 , V_2 , V_39 ) ;
V_7 -> V_35 [ V_2 ] = 0 ;
}
V_24 = F_5 ( V_7 , V_39 ) ;
V_38 = ( V_33 & V_21 ) + ( 1U << V_42 ) ;
if ( V_38 < V_32 ) {
V_40 = F_22 ( V_7 , V_22 , V_2 ,
V_24 , V_33 , V_38 , V_5 ) ;
V_5 += ( V_38 - V_33 ) ;
V_33 = V_38 ;
} else {
V_40 = F_22 ( V_7 , V_22 , V_2 ,
V_24 , V_33 , V_32 , V_5 ) ;
V_5 += ( V_32 - V_33 ) ;
V_33 = V_32 ;
}
if ( V_40 ) {
F_18 ( V_29 , L_14 ) ;
F_26 ( V_7 , V_31 , V_33 ) ;
return - V_34 ;
}
} while ( V_33 < V_32 && V_2 < V_43 );
return 0 ;
}
static int F_29 ( struct V_6 * V_7 , unsigned int V_26 ,
T_1 V_5 , unsigned int V_44 )
{
unsigned int V_31 , V_32 ;
T_1 V_22 ;
int V_40 ;
F_30 ( & V_7 -> V_45 ) ;
if ( ! F_25 ( V_7 , V_7 -> V_46 ) ) {
V_22 = F_8 ( V_7 ) ;
if ( V_22 == V_19 ) {
F_18 ( V_29 , L_13 ) ;
F_31 ( & V_7 -> V_45 ) ;
return - V_41 ;
}
V_40 = V_7 -> V_8 -> V_47 ( V_7 , V_22 ) ;
if ( V_40 ) {
F_18 ( V_29 ,
L_15 ) ;
F_31 ( & V_7 -> V_45 ) ;
return V_40 ;
}
V_7 -> V_48 = V_22 ;
V_7 -> V_46 = F_6 ( V_7 , V_22 ) ;
memset ( V_7 -> V_35 , 0 , sizeof( int ) * V_43 ) ;
}
V_22 = F_5 ( V_7 , V_7 -> V_46 ) ;
V_31 = ( V_26 ) & V_21 ;
V_32 = V_31 + ( V_44 << V_49 ) ;
V_5 &= V_21 ;
V_40 = F_27 ( V_7 , V_22 , V_31 , V_32 , V_5 ) ;
if ( V_40 )
F_18 ( V_29 , L_16 ) ;
F_31 ( & V_7 -> V_45 ) ;
return V_40 ;
}
static void F_32 ( struct V_6 * V_7 , T_1 V_22 ,
unsigned int V_23 , T_1 V_24 ,
unsigned int V_31 , unsigned int V_32 )
{
unsigned int V_33 ;
unsigned int V_2 ;
unsigned int V_4 ;
V_24 &= V_21 ;
V_31 = V_31 & V_21 ;
V_32 = F_23 ( V_32 ) ;
V_33 = V_31 ;
do {
V_2 = F_24 ( V_33 ) ;
V_4 = F_1 ( V_24 , V_2 ) ;
if ( ! F_25 ( V_7 , V_4 ) )
F_19 ( V_7 , V_22 , V_23 ,
V_24 , V_2 , V_33 , V_4 ) ;
F_3 ( V_24 , V_2 , V_7 -> V_8 -> V_20 ) ;
V_7 -> V_35 [ V_23 ] -- ;
V_33 += ( 1U << V_36 ) ;
} while ( V_33 < V_32 && V_2 < V_37 - 1 );
if ( V_7 -> V_35 [ V_23 ] == 0 ) {
F_14 ( V_7 , V_24 ) ;
F_3 ( V_22 , V_23 , V_7 -> V_8 -> V_20 ) ;
}
}
static void F_33 ( struct V_6 * V_7 , T_1 V_22 ,
unsigned int V_31 , unsigned int V_32 )
{
T_1 V_24 ;
unsigned int V_33 , V_38 ;
unsigned int V_2 ;
unsigned int V_39 ;
V_22 &= V_21 ;
V_31 = V_31 & V_21 ;
V_32 = F_23 ( V_32 ) ;
V_33 = V_31 ;
do {
V_2 = F_28 ( V_33 ) ;
V_39 = F_1 ( V_22 , V_2 ) ;
if ( ! F_25 ( V_7 , V_39 ) ) {
F_20 ( V_7 , V_22 , V_2 , V_33 , V_39 ) ;
continue;
}
V_24 = F_5 ( V_7 , V_39 ) ;
V_38 = ( V_33 & V_21 ) + ( 1U << V_42 ) ;
if ( V_38 < V_32 ) {
F_32 ( V_7 , V_22 , V_2 , V_24 , V_33 , V_38 ) ;
V_33 = V_38 ;
} else {
F_32 ( V_7 , V_22 , V_2 , V_24 , V_33 , V_32 ) ;
V_33 = V_32 ;
}
} while ( V_33 < V_32 && V_2 < V_43 );
}
static void F_34 ( struct V_6 * V_7 , unsigned int V_26 ,
unsigned int V_44 )
{
unsigned int V_31 , V_32 ;
T_1 V_22 ;
F_30 ( & V_7 -> V_45 ) ;
if ( ! F_25 ( V_7 , V_7 -> V_46 ) ) {
F_21 ( V_7 , V_7 -> V_46 ) ;
F_31 ( & V_7 -> V_45 ) ;
return;
}
V_22 = F_5 ( V_7 , V_7 -> V_46 ) ;
V_31 = ( V_26 ) & V_21 ;
V_32 = V_31 + ( V_44 << V_49 ) ;
F_33 ( V_7 , V_22 , V_31 , V_32 ) ;
F_31 ( & V_7 -> V_45 ) ;
}
static void F_26 ( struct V_6 * V_7 , unsigned int V_50 ,
unsigned int V_51 )
{
unsigned int V_44 ;
unsigned int V_31 , V_32 ;
V_31 = ( V_50 ) & V_21 ;
V_32 = ( V_51 ) & V_21 ;
V_44 = ( V_32 - V_31 ) >> V_49 ;
F_34 ( V_7 , V_31 , V_44 ) ;
}
int F_35 ( struct V_6 * V_7 , unsigned int V_26 ,
T_1 V_5 , unsigned int V_44 )
{
return F_29 ( V_7 , V_26 , V_5 , V_44 ) ;
}
void F_36 ( struct V_6 * V_7 , unsigned int V_26 ,
unsigned int V_44 )
{
F_34 ( V_7 , V_26 , V_44 ) ;
}
static void F_37 ( struct V_6 * V_7 ,
unsigned int V_31 ,
unsigned int V_52 )
{
F_38 ( V_7 ) ;
}
int F_39 ( struct V_6 * V_7 , struct V_53 * V_8 )
{
if ( ! V_7 )
return - V_34 ;
if ( ! V_8 )
return - V_34 ;
if ( ! V_8 -> V_54 )
F_40 ( V_29 , L_17 ) ;
V_7 -> V_8 = V_8 ;
if ( ! V_8 -> V_47 || ! V_8 -> V_55 ) {
F_18 ( V_29 ,
L_18
L_19 ) ;
return - V_34 ;
}
if ( ! V_8 -> V_56 )
V_8 -> V_56 = F_37 ;
if ( ! V_8 -> V_57 ) {
F_18 ( V_29 , L_20 ) ;
return - V_34 ;
}
V_7 -> V_46 = V_8 -> V_20 ;
F_41 ( & V_7 -> V_45 ) ;
V_7 -> V_18 = F_42 ( L_21 , V_58 ,
V_58 , V_59 ,
NULL ) ;
if ( ! V_7 -> V_18 )
return - V_41 ;
return 0 ;
}
void F_43 ( struct V_6 * V_7 )
{
unsigned int V_2 ;
unsigned int V_4 ;
T_1 V_22 , V_24 ;
if ( ! V_7 )
return;
if ( ! F_25 ( V_7 , V_7 -> V_46 ) ) {
F_40 ( V_29 , L_22 ,
( unsigned int ) V_7 -> V_46 ) ;
return;
}
V_22 = F_5 ( V_7 , V_7 -> V_46 ) ;
for ( V_2 = 0 ; V_2 < V_43 ; V_2 ++ ) {
V_4 = F_1 ( V_22 , V_2 ) ;
if ( F_25 ( V_7 , V_4 ) ) {
V_24 = F_5 ( V_7 , V_4 ) ;
F_14 ( V_7 , V_24 ) ;
}
}
F_14 ( V_7 , V_22 ) ;
F_44 ( V_7 -> V_18 ) ;
}
