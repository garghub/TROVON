static int T_1 F_1 ( struct V_1 * V_1 )
{
unsigned long V_2 ;
unsigned long V_3 ;
V_2 = ( unsigned long ) F_2 ( F_3 ( V_1 -> V_2 ) ) ;
V_3 = ( unsigned long ) F_2 ( F_3 ( V_1 -> V_3 ) ) ;
return F_4 ( V_2 , V_3 + 1 , V_4 ) ;
}
static void T_1 F_5 ( unsigned long V_2 ,
unsigned long V_3 )
{
for (; V_2 < V_3 ; V_2 += V_5 )
F_6 ( F_7 ( V_2 ) ) ;
}
void T_1 F_8 ( T_2 * V_6 )
{
int V_7 ;
unsigned long V_2 = V_8 ;
unsigned long V_3 = V_9 ;
for ( V_7 = F_9 ( V_2 ) ; V_2 < V_3 ; V_7 ++ ) {
V_6 [ V_7 ] = F_10 ( F_11 ( V_10 )
| V_11 ) ;
V_2 += V_5 ;
}
}
static int T_1 F_12 ( T_3 * V_12 , unsigned long V_13 ,
unsigned long V_3 )
{
T_4 * V_14 = F_13 ( V_12 , V_13 ) ;
while ( V_13 + V_15 <= V_3 ) {
F_14 ( ! F_15 ( * V_14 ) ) ;
F_16 ( V_14 , F_17 ( F_11 ( V_16 )
| V_17 ) ) ;
V_13 += V_15 ;
V_14 = F_13 ( V_12 , V_13 ) ;
}
return 0 ;
}
static int T_1 F_18 ( T_5 * V_18 , unsigned long V_13 ,
unsigned long V_3 )
{
int V_19 = 0 ;
T_3 * V_12 = F_19 ( V_18 , V_13 ) ;
while ( F_20 ( V_13 , V_20 ) && V_13 + V_20 <= V_3 ) {
F_14 ( ! F_21 ( * V_12 ) ) ;
F_22 ( V_12 , F_23 ( F_11 ( V_21 )
| V_17 ) ) ;
V_13 += V_20 ;
V_12 = F_19 ( V_18 , V_13 ) ;
}
if ( V_13 < V_3 ) {
if ( F_21 ( * V_12 ) ) {
void * V_22 = F_24 ( V_15 , V_4 ) ;
if ( ! V_22 )
return - V_23 ;
F_22 ( V_12 , F_23 ( F_11 ( V_22 ) | V_11 ) ) ;
}
V_19 = F_12 ( V_12 , V_13 , V_3 ) ;
}
return V_19 ;
}
static int T_1 F_25 ( T_2 * V_6 , unsigned long V_13 ,
unsigned long V_3 )
{
int V_19 = 0 ;
T_5 * V_18 = F_26 ( V_6 , V_13 ) ;
while ( F_20 ( V_13 , V_24 ) && V_13 + V_24 <= V_3 ) {
F_14 ( ! F_27 ( * V_18 ) ) ;
F_28 ( V_18 , F_29 ( F_11 ( V_25 )
| V_17 ) ) ;
V_13 += V_24 ;
V_18 = F_26 ( V_6 , V_13 ) ;
}
if ( V_13 < V_3 ) {
if ( F_27 ( * V_18 ) ) {
void * V_22 = F_24 ( V_15 , V_4 ) ;
if ( ! V_22 )
return - V_23 ;
F_28 ( V_18 , F_29 ( F_11 ( V_22 ) | V_11 ) ) ;
}
V_19 = F_18 ( V_18 , V_13 , V_3 ) ;
}
return V_19 ;
}
static int T_1 F_30 ( unsigned long V_13 , unsigned long V_3 )
{
int V_19 = 0 ;
T_2 * V_6 = F_7 ( V_13 ) ;
while ( F_20 ( V_13 , V_5 ) && V_13 + V_5 <= V_3 ) {
F_14 ( ! F_31 ( * V_6 ) ) ;
F_32 ( V_6 , F_10 ( F_11 ( V_10 )
| V_17 ) ) ;
V_13 += V_5 ;
V_6 = F_7 ( V_13 ) ;
}
if ( V_13 < V_3 ) {
if ( F_31 ( * V_6 ) ) {
void * V_22 = F_24 ( V_15 , V_4 ) ;
if ( ! V_22 )
return - V_23 ;
F_32 ( V_6 , F_10 ( F_11 ( V_22 ) | V_11 ) ) ;
}
V_19 = F_25 ( V_6 , V_13 , V_3 ) ;
}
return V_19 ;
}
static void T_1 F_33 ( const void * V_2 , const void * V_3 )
{
if ( F_30 ( ( unsigned long ) V_2 , ( unsigned long ) V_3 ) )
F_34 ( L_1 ) ;
}
static int F_35 ( struct V_26 * V_27 ,
unsigned long V_28 ,
void * V_29 )
{
if ( V_28 == V_30 ) {
F_36 ( L_2 ) ;
F_36 ( L_3 ) ;
}
return V_31 ;
}
void T_1 F_37 ( void )
{
int V_7 ;
#ifdef F_38
F_39 ( & V_32 ) ;
#endif
memcpy ( V_33 , V_34 , sizeof( V_33 ) ) ;
F_40 ( V_33 ) ;
F_5 ( V_8 , V_9 ) ;
F_33 ( ( void * ) V_8 ,
F_2 ( ( void * ) V_35 ) ) ;
for ( V_7 = 0 ; V_7 < V_36 ; V_7 ++ ) {
if ( V_37 [ V_7 ] . V_3 == 0 )
break;
if ( F_1 ( & V_37 [ V_7 ] ) )
F_34 ( L_4 ) ;
}
F_33 ( F_2 ( ( void * ) V_35 + V_38 ) ,
F_2 ( ( void * ) V_39 ) ) ;
F_4 ( ( unsigned long ) F_2 ( V_40 ) ,
( unsigned long ) F_2 ( V_41 ) ,
V_4 ) ;
F_33 ( F_2 ( ( void * ) V_42 ) ,
( void * ) V_9 ) ;
memset ( V_16 , 0 , V_15 ) ;
F_40 ( V_34 ) ;
V_43 . V_44 = 0 ;
}
