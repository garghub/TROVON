static void F_1 ( T_1 * V_1 , void * V_2 , T_2 V_3 ,
T_2 V_4 )
{
const int V_5 = V_1 -> V_6 ;
const int V_7 = F_2 ( int , V_4 - ( V_8 / 8 ) , 0 ) ;
const int V_9 = F_3 ( int , V_4 + ( V_8 / 8 ) , V_3 ) ;
int V_10 ;
F_4 ( L_1 ) ;
F_4 ( L_2 , V_1 , V_3 ) ;
F_4 ( L_3 , V_5 , V_2 , V_7 > 0 ? L_4 : L_5 ) ;
for ( V_10 = V_7 ; V_10 < V_9 ; V_10 ++ )
F_5 ( L_6 , * ( V_11 * ) ( V_2 + V_10 ) ) ;
F_5 ( L_7 , V_9 < V_3 ? L_8 : L_5 ) ;
F_6 () ;
}
static void F_7 ( T_1 * V_1 , void * V_2 , T_2 V_3 )
{
V_11 * V_12 = V_2 ;
T_2 V_10 ;
for ( V_10 = 0 ; V_10 < V_3 ; V_10 ++ ) {
V_11 exp = ( V_10 < V_3 - 1 ) ? V_13 : V_14 ;
if ( V_12 [ V_10 ] != exp ) {
F_1 ( V_1 , V_2 , V_3 , V_10 ) ;
return;
}
}
memset ( V_12 , V_15 , V_3 ) ;
}
static void F_8 ( T_1 * V_1 , void * V_2 )
{
if ( V_1 -> free == V_16 || V_1 -> free == V_17 )
F_7 ( V_1 , V_2 , F_9 ( V_2 ) ) ;
if ( V_1 -> free == V_18 ) {
int V_19 = ( int ) ( long ) V_1 -> V_20 ;
void * V_21 = F_10 ( (struct V_22 * ) V_2 ) ;
F_7 ( V_1 , V_21 , 1UL << ( V_23 + V_19 ) ) ;
F_11 ( V_21 ) ;
}
}
static void F_12 ( void * V_2 , T_2 V_3 )
{
V_11 * V_12 = V_2 ;
memset ( V_12 , V_13 , V_3 - 1 ) ;
V_12 [ V_3 - 1 ] = V_14 ;
}
static void F_13 ( T_1 * V_1 , void * V_2 )
{
if ( V_1 -> V_24 == V_25 || V_1 -> V_24 == V_26 )
F_12 ( V_2 , F_9 ( V_2 ) ) ;
if ( V_1 -> V_24 == V_27 ) {
int V_19 = ( int ) ( long ) V_1 -> V_20 ;
void * V_21 = F_10 ( (struct V_22 * ) V_2 ) ;
F_12 ( V_21 , 1UL << ( V_23 + V_19 ) ) ;
F_11 ( V_21 ) ;
}
}
static inline void F_8 ( T_1 * V_1 , void * V_2 )
{
}
static inline void F_13 ( T_1 * V_1 , void * V_2 )
{
}
static void F_14 ( T_1 * V_1 , void * V_2 )
{
if ( V_1 -> V_24 == V_25 )
F_15 ( V_1 -> V_20 , V_2 ) ;
if ( V_1 -> V_24 == V_26 )
F_16 ( V_2 ) ;
if ( V_1 -> V_24 == V_27 )
F_17 ( V_2 , ( unsigned long ) V_1 -> V_20 ) ;
}
static void F_18 ( T_1 * V_1 , void * V_2 )
{
if ( V_1 -> V_24 == V_25 )
F_19 ( V_1 -> V_20 , V_2 ) ;
if ( V_1 -> V_24 == V_26 )
F_20 ( V_2 , ( T_2 ) V_1 -> V_20 ) ;
if ( V_1 -> V_24 == V_27 )
F_21 ( V_2 , ( unsigned long ) V_1 -> V_20 ) ;
}
static void F_22 ( T_1 * V_1 , void * V_2 )
{
F_23 ( V_1 -> V_6 >= V_1 -> V_28 ) ;
F_13 ( V_1 , V_2 ) ;
F_14 ( V_1 , V_2 ) ;
V_1 -> V_29 [ V_1 -> V_6 ++ ] = V_2 ;
}
static void * F_24 ( T_1 * V_1 )
{
void * V_2 = V_1 -> V_29 [ -- V_1 -> V_6 ] ;
F_23 ( V_1 -> V_6 < 0 ) ;
F_8 ( V_1 , V_2 ) ;
F_18 ( V_1 , V_2 ) ;
return V_2 ;
}
void F_25 ( T_1 * V_1 )
{
while ( V_1 -> V_6 ) {
void * V_2 = F_24 ( V_1 ) ;
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
}
F_26 ( V_1 -> V_29 ) ;
F_26 ( V_1 ) ;
}
T_1 * F_27 ( int V_28 , T_3 * V_30 ,
T_4 * V_31 , void * V_20 )
{
return F_28 ( V_28 , V_30 , V_31 , V_20 ,
V_32 , V_33 ) ;
}
T_1 * F_28 ( int V_28 , T_3 * V_30 ,
T_4 * V_31 , void * V_20 ,
T_5 V_34 , int V_35 )
{
T_1 * V_1 ;
V_1 = F_29 ( sizeof( * V_1 ) , V_34 , V_35 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_29 = F_30 ( V_28 * sizeof( void * ) ,
V_34 , V_35 ) ;
if ( ! V_1 -> V_29 ) {
F_26 ( V_1 ) ;
return NULL ;
}
F_31 ( & V_1 -> V_36 ) ;
V_1 -> V_28 = V_28 ;
V_1 -> V_20 = V_20 ;
F_32 ( & V_1 -> V_37 ) ;
V_1 -> V_24 = V_30 ;
V_1 -> free = V_31 ;
while ( V_1 -> V_6 < V_1 -> V_28 ) {
void * V_2 ;
V_2 = V_1 -> V_24 ( V_34 , V_1 -> V_20 ) ;
if ( F_33 ( ! V_2 ) ) {
F_25 ( V_1 ) ;
return NULL ;
}
F_22 ( V_1 , V_2 ) ;
}
return V_1 ;
}
int F_34 ( T_1 * V_1 , int V_38 )
{
void * V_2 ;
void * * V_39 ;
unsigned long V_40 ;
F_23 ( V_38 <= 0 ) ;
F_35 () ;
F_36 ( & V_1 -> V_36 , V_40 ) ;
if ( V_38 <= V_1 -> V_28 ) {
while ( V_38 < V_1 -> V_6 ) {
V_2 = F_24 ( V_1 ) ;
F_37 ( & V_1 -> V_36 , V_40 ) ;
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
F_36 ( & V_1 -> V_36 , V_40 ) ;
}
V_1 -> V_28 = V_38 ;
goto V_41;
}
F_37 ( & V_1 -> V_36 , V_40 ) ;
V_39 = F_38 ( V_38 , sizeof( * V_39 ) ,
V_32 ) ;
if ( ! V_39 )
return - V_42 ;
F_36 ( & V_1 -> V_36 , V_40 ) ;
if ( F_33 ( V_38 <= V_1 -> V_28 ) ) {
F_37 ( & V_1 -> V_36 , V_40 ) ;
F_26 ( V_39 ) ;
goto V_43;
}
memcpy ( V_39 , V_1 -> V_29 ,
V_1 -> V_6 * sizeof( * V_39 ) ) ;
F_26 ( V_1 -> V_29 ) ;
V_1 -> V_29 = V_39 ;
V_1 -> V_28 = V_38 ;
while ( V_1 -> V_6 < V_1 -> V_28 ) {
F_37 ( & V_1 -> V_36 , V_40 ) ;
V_2 = V_1 -> V_24 ( V_32 , V_1 -> V_20 ) ;
if ( ! V_2 )
goto V_43;
F_36 ( & V_1 -> V_36 , V_40 ) ;
if ( V_1 -> V_6 < V_1 -> V_28 ) {
F_22 ( V_1 , V_2 ) ;
} else {
F_37 ( & V_1 -> V_36 , V_40 ) ;
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
goto V_43;
}
}
V_41:
F_37 ( & V_1 -> V_36 , V_40 ) ;
V_43:
return 0 ;
}
void * F_39 ( T_1 * V_1 , T_5 V_34 )
{
void * V_2 ;
unsigned long V_40 ;
T_6 V_37 ;
T_5 V_44 ;
F_40 ( V_34 & V_45 ) ;
F_41 ( V_34 & V_46 ) ;
V_34 |= V_47 ;
V_34 |= V_48 ;
V_34 |= V_49 ;
V_44 = V_34 & ~ ( V_46 | V_50 ) ;
V_51:
V_2 = V_1 -> V_24 ( V_44 , V_1 -> V_20 ) ;
if ( F_42 ( V_2 != NULL ) )
return V_2 ;
F_36 ( & V_1 -> V_36 , V_40 ) ;
if ( F_42 ( V_1 -> V_6 ) ) {
V_2 = F_24 ( V_1 ) ;
F_37 ( & V_1 -> V_36 , V_40 ) ;
F_43 () ;
F_44 ( V_2 ) ;
return V_2 ;
}
if ( V_44 != V_34 ) {
F_37 ( & V_1 -> V_36 , V_40 ) ;
V_44 = V_34 ;
goto V_51;
}
if ( ! ( V_34 & V_46 ) ) {
F_37 ( & V_1 -> V_36 , V_40 ) ;
return NULL ;
}
F_45 ( & V_37 ) ;
F_46 ( & V_1 -> V_37 , & V_37 , V_52 ) ;
F_37 ( & V_1 -> V_36 , V_40 ) ;
F_47 ( 5 * V_53 ) ;
F_48 ( & V_1 -> V_37 , & V_37 ) ;
goto V_51;
}
void F_49 ( void * V_2 , T_1 * V_1 )
{
unsigned long V_40 ;
if ( F_33 ( V_2 == NULL ) )
return;
F_50 () ;
if ( F_33 ( V_1 -> V_6 < V_1 -> V_28 ) ) {
F_36 ( & V_1 -> V_36 , V_40 ) ;
if ( F_42 ( V_1 -> V_6 < V_1 -> V_28 ) ) {
F_22 ( V_1 , V_2 ) ;
F_37 ( & V_1 -> V_36 , V_40 ) ;
F_51 ( & V_1 -> V_37 ) ;
return;
}
F_37 ( & V_1 -> V_36 , V_40 ) ;
}
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
}
void * V_25 ( T_5 V_34 , void * V_20 )
{
struct V_54 * V_55 = V_20 ;
F_52 ( V_55 -> V_56 ) ;
return F_53 ( V_55 , V_34 ) ;
}
void V_16 ( void * V_2 , void * V_20 )
{
struct V_54 * V_55 = V_20 ;
F_54 ( V_55 , V_2 ) ;
}
void * V_26 ( T_5 V_34 , void * V_20 )
{
T_2 V_3 = ( T_2 ) V_20 ;
return F_55 ( V_3 , V_34 ) ;
}
void V_17 ( void * V_2 , void * V_20 )
{
F_26 ( V_2 ) ;
}
void * V_27 ( T_5 V_34 , void * V_20 )
{
int V_19 = ( int ) ( long ) V_20 ;
return F_56 ( V_34 , V_19 ) ;
}
void V_18 ( void * V_2 , void * V_20 )
{
int V_19 = ( int ) ( long ) V_20 ;
F_57 ( V_2 , V_19 ) ;
}
