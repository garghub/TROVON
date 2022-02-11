static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
F_2 ( V_3 , V_4 ) ;
V_5 = V_3 ;
}
static inline void F_3 ( struct V_1 * V_2 , unsigned long V_6 )
{
T_1 V_3 = V_2 -> V_7 | ( V_6 >> V_8 ) ;
if ( V_5 != V_3 )
F_1 ( V_2 , V_3 ) ;
}
static T_2 F_4 ( struct V_1 * V_2 , unsigned long V_6 )
{
T_2 V_9 ;
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_6 ) ;
V_9 . V_11 [ 0 ] = F_6 ( V_12 + ( V_6 & V_13 ) ) ;
F_7 ( & V_10 ) ;
return V_9 ;
}
static void F_8 ( struct V_1 * V_2 , void * V_14 , unsigned long V_15 , T_3 V_16 )
{
while( V_16 ) {
unsigned long V_17 = V_16 ;
if ( V_16 > ( V_18 - ( V_15 & V_13 ) ) )
V_17 = V_18 - ( V_15 & V_13 ) ;
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_15 ) ;
F_9 ( V_14 , V_12 + V_15 , V_17 ) ;
F_7 ( & V_10 ) ;
V_14 += V_17 ;
V_15 += V_17 ;
V_16 -= V_17 ;
}
}
static void F_10 ( struct V_1 * V_2 , T_2 V_19 , unsigned long V_20 )
{
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_20 ) ;
F_11 ( V_19 . V_11 [ 0 ] , V_12 + ( V_20 & V_13 ) ) ;
F_7 ( & V_10 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned long V_14 , const void * V_15 , T_3 V_16 )
{
while( V_16 ) {
unsigned long V_17 = V_16 ;
if ( V_16 > ( V_18 - ( V_14 & V_13 ) ) )
V_17 = V_18 - ( V_14 & V_13 ) ;
F_5 ( & V_10 ) ;
F_3 ( V_2 , V_14 ) ;
F_13 ( V_12 + V_14 , V_15 , V_17 ) ;
F_7 ( & V_10 ) ;
V_14 += V_17 ;
V_15 += V_17 ;
V_16 -= V_17 ;
}
}
static int T_4 F_14 ( void )
{
unsigned int V_21 = ( 1 << 6 ) ;
unsigned long V_22 ;
unsigned long V_23 [ 10 ] ;
for ( V_22 = 0 ; V_22 != 20 ; V_22 ++ )
{
F_2 ( V_21 + ( V_22 % 10 ) , V_4 ) ;
if ( V_22 < 10 )
{
V_23 [ V_22 % 10 ] = F_15 ( V_12 ) ;
if ( V_22 > 0 && V_23 [ V_22 % 10 ] == V_23 [ 0 ] )
return - V_24 ;
}
else
{
if ( V_23 [ V_22 % 10 ] != F_15 ( V_12 ) )
return - V_24 ;
}
}
return 0 ;
}
void F_16 ( void )
{
int V_25 ;
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ ) {
if ( V_26 [ V_25 ] ) {
F_17 ( V_26 [ V_25 ] ) ;
F_18 ( V_26 [ V_25 ] ) ;
}
}
F_19 ( ( void * ) V_12 ) ;
F_20 ( V_4 , 1 ) ;
}
static int T_4 F_21 ( void )
{
int V_25 ;
int V_9 = 0 ;
if ( ! F_22 ( V_4 , 1 , L_1 ) ) {
F_23 ( V_27 L_2 ) ;
return - V_24 ;
}
V_12 = ( unsigned long ) F_24 ( V_28 , V_18 ) ;
if ( ! V_12 ) {
F_23 ( V_27 L_3 ) ;
V_9 = - V_29 ;
goto V_30;
}
if ( F_14 () != 0 ) {
F_23 ( V_27 L_4 ) ;
F_19 ( ( void * ) V_12 ) ;
V_9 = - V_24 ;
goto V_31;
}
F_23 ( L_5 , V_4 , V_28 ,
V_28 + V_18 ) ;
for ( V_25 = 0 ; V_25 < 2 ; V_25 ++ ) {
V_26 [ V_25 ] = F_25 ( L_6 , & V_32 [ V_25 ] ) ;
if ( ! V_26 [ V_25 ] )
V_26 [ V_25 ] = F_25 ( L_7 , & V_32 [ V_25 ] ) ;
if ( ! V_26 [ V_25 ] )
V_26 [ V_25 ] = F_25 ( L_8 , & V_32 [ V_25 ] ) ;
if ( ! V_26 [ V_25 ] )
V_26 [ V_25 ] = F_25 ( L_9 , & V_32 [ V_25 ] ) ;
if ( V_26 [ V_25 ] ) {
V_26 [ V_25 ] -> V_33 = V_34 ;
F_26 ( V_26 [ V_25 ] , NULL , 0 ) ;
}
}
if ( ! V_26 [ 0 ] && ! V_26 [ 1 ] ) {
F_16 () ;
return - V_35 ;
}
return 0 ;
V_31:
F_19 ( ( void * ) V_12 ) ;
V_30:
F_20 ( V_4 , 1 ) ;
return V_9 ;
}
