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
if ( V_1 -> V_24 == V_25 || V_1 -> V_24 == V_26 )
F_15 ( V_2 ) ;
if ( V_1 -> V_24 == V_27 )
F_16 ( V_2 , ( unsigned long ) V_1 -> V_20 ) ;
}
static void F_17 ( T_1 * V_1 , void * V_2 , T_3 V_28 )
{
if ( V_1 -> V_24 == V_25 || V_1 -> V_24 == V_26 )
F_18 ( V_2 ) ;
if ( V_1 -> V_24 == V_27 )
F_19 ( V_2 , ( unsigned long ) V_1 -> V_20 ) ;
}
static void F_20 ( T_1 * V_1 , void * V_2 )
{
F_21 ( V_1 -> V_6 >= V_1 -> V_29 ) ;
F_13 ( V_1 , V_2 ) ;
F_14 ( V_1 , V_2 ) ;
V_1 -> V_30 [ V_1 -> V_6 ++ ] = V_2 ;
}
static void * F_22 ( T_1 * V_1 , T_3 V_28 )
{
void * V_2 = V_1 -> V_30 [ -- V_1 -> V_6 ] ;
F_21 ( V_1 -> V_6 < 0 ) ;
F_17 ( V_1 , V_2 , V_28 ) ;
F_8 ( V_1 , V_2 ) ;
return V_2 ;
}
void F_23 ( T_1 * V_1 )
{
if ( F_24 ( ! V_1 ) )
return;
while ( V_1 -> V_6 ) {
void * V_2 = F_22 ( V_1 , V_31 ) ;
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
}
F_25 ( V_1 -> V_30 ) ;
F_25 ( V_1 ) ;
}
T_1 * F_26 ( int V_29 , T_4 * V_32 ,
T_5 * V_33 , void * V_20 )
{
return F_27 ( V_29 , V_32 , V_33 , V_20 ,
V_31 , V_34 ) ;
}
T_1 * F_27 ( int V_29 , T_4 * V_32 ,
T_5 * V_33 , void * V_20 ,
T_3 V_35 , int V_36 )
{
T_1 * V_1 ;
V_1 = F_28 ( sizeof( * V_1 ) , V_35 , V_36 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_30 = F_29 ( V_29 * sizeof( void * ) ,
V_35 , V_36 ) ;
if ( ! V_1 -> V_30 ) {
F_25 ( V_1 ) ;
return NULL ;
}
F_30 ( & V_1 -> V_37 ) ;
V_1 -> V_29 = V_29 ;
V_1 -> V_20 = V_20 ;
F_31 ( & V_1 -> V_38 ) ;
V_1 -> V_24 = V_32 ;
V_1 -> free = V_33 ;
while ( V_1 -> V_6 < V_1 -> V_29 ) {
void * V_2 ;
V_2 = V_1 -> V_24 ( V_35 , V_1 -> V_20 ) ;
if ( F_24 ( ! V_2 ) ) {
F_23 ( V_1 ) ;
return NULL ;
}
F_20 ( V_1 , V_2 ) ;
}
return V_1 ;
}
int F_32 ( T_1 * V_1 , int V_39 )
{
void * V_2 ;
void * * V_40 ;
unsigned long V_28 ;
F_21 ( V_39 <= 0 ) ;
F_33 () ;
F_34 ( & V_1 -> V_37 , V_28 ) ;
if ( V_39 <= V_1 -> V_29 ) {
while ( V_39 < V_1 -> V_6 ) {
V_2 = F_22 ( V_1 , V_31 ) ;
F_35 ( & V_1 -> V_37 , V_28 ) ;
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
F_34 ( & V_1 -> V_37 , V_28 ) ;
}
V_1 -> V_29 = V_39 ;
goto V_41;
}
F_35 ( & V_1 -> V_37 , V_28 ) ;
V_40 = F_36 ( V_39 , sizeof( * V_40 ) ,
V_31 ) ;
if ( ! V_40 )
return - V_42 ;
F_34 ( & V_1 -> V_37 , V_28 ) ;
if ( F_24 ( V_39 <= V_1 -> V_29 ) ) {
F_35 ( & V_1 -> V_37 , V_28 ) ;
F_25 ( V_40 ) ;
goto V_43;
}
memcpy ( V_40 , V_1 -> V_30 ,
V_1 -> V_6 * sizeof( * V_40 ) ) ;
F_25 ( V_1 -> V_30 ) ;
V_1 -> V_30 = V_40 ;
V_1 -> V_29 = V_39 ;
while ( V_1 -> V_6 < V_1 -> V_29 ) {
F_35 ( & V_1 -> V_37 , V_28 ) ;
V_2 = V_1 -> V_24 ( V_31 , V_1 -> V_20 ) ;
if ( ! V_2 )
goto V_43;
F_34 ( & V_1 -> V_37 , V_28 ) ;
if ( V_1 -> V_6 < V_1 -> V_29 ) {
F_20 ( V_1 , V_2 ) ;
} else {
F_35 ( & V_1 -> V_37 , V_28 ) ;
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
goto V_43;
}
}
V_41:
F_35 ( & V_1 -> V_37 , V_28 ) ;
V_43:
return 0 ;
}
void * F_37 ( T_1 * V_1 , T_3 V_35 )
{
void * V_2 ;
unsigned long V_28 ;
T_6 V_38 ;
T_3 V_44 ;
F_38 ( V_35 & V_45 ) ;
F_39 ( V_35 & V_46 ) ;
V_35 |= V_47 ;
V_35 |= V_48 ;
V_35 |= V_49 ;
V_44 = V_35 & ~ ( V_46 | V_50 ) ;
V_51:
V_2 = V_1 -> V_24 ( V_44 , V_1 -> V_20 ) ;
if ( F_40 ( V_2 != NULL ) )
return V_2 ;
F_34 ( & V_1 -> V_37 , V_28 ) ;
if ( F_40 ( V_1 -> V_6 ) ) {
V_2 = F_22 ( V_1 , V_44 ) ;
F_35 ( & V_1 -> V_37 , V_28 ) ;
F_41 () ;
F_42 ( V_2 ) ;
return V_2 ;
}
if ( V_44 != V_35 ) {
F_35 ( & V_1 -> V_37 , V_28 ) ;
V_44 = V_35 ;
goto V_51;
}
if ( ! ( V_35 & V_46 ) ) {
F_35 ( & V_1 -> V_37 , V_28 ) ;
return NULL ;
}
F_43 ( & V_38 ) ;
F_44 ( & V_1 -> V_38 , & V_38 , V_52 ) ;
F_35 ( & V_1 -> V_37 , V_28 ) ;
F_45 ( 5 * V_53 ) ;
F_46 ( & V_1 -> V_38 , & V_38 ) ;
goto V_51;
}
void F_47 ( void * V_2 , T_1 * V_1 )
{
unsigned long V_28 ;
if ( F_24 ( V_2 == NULL ) )
return;
F_48 () ;
if ( F_24 ( V_1 -> V_6 < V_1 -> V_29 ) ) {
F_34 ( & V_1 -> V_37 , V_28 ) ;
if ( F_40 ( V_1 -> V_6 < V_1 -> V_29 ) ) {
F_20 ( V_1 , V_2 ) ;
F_35 ( & V_1 -> V_37 , V_28 ) ;
F_49 ( & V_1 -> V_38 ) ;
return;
}
F_35 ( & V_1 -> V_37 , V_28 ) ;
}
V_1 -> free ( V_2 , V_1 -> V_20 ) ;
}
void * V_25 ( T_3 V_35 , void * V_20 )
{
struct V_54 * V_55 = V_20 ;
F_50 ( V_55 -> V_56 ) ;
return F_51 ( V_55 , V_35 ) ;
}
void V_16 ( void * V_2 , void * V_20 )
{
struct V_54 * V_55 = V_20 ;
F_52 ( V_55 , V_2 ) ;
}
void * V_26 ( T_3 V_35 , void * V_20 )
{
T_2 V_3 = ( T_2 ) V_20 ;
return F_53 ( V_3 , V_35 ) ;
}
void V_17 ( void * V_2 , void * V_20 )
{
F_25 ( V_2 ) ;
}
void * V_27 ( T_3 V_35 , void * V_20 )
{
int V_19 = ( int ) ( long ) V_20 ;
return F_54 ( V_35 , V_19 ) ;
}
void V_18 ( void * V_2 , void * V_20 )
{
int V_19 = ( int ) ( long ) V_20 ;
F_55 ( V_2 , V_19 ) ;
}
